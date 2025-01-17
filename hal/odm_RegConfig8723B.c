/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 ******************************************************************************/

#include "odm_precomp.h"

void
odm_ConfigRFReg_8723B(
	IN	PDM_ODM_T				pDM_Odm,
	IN	u4Byte					Addr,
	IN	u4Byte					Data,
	IN  ODM_RF_RADIO_PATH_E     RF_PATH,
	IN	u4Byte				    RegAddr
	)
{
    if (Addr == 0xfe || Addr == 0xffe)
	{
		msleep(50);
	}
	else
	{
		PHY_SetRFReg(pDM_Odm->Adapter, RF_PATH, RegAddr, bRFRegOffsetMask, Data);
		/*  Add 1us delay between BB/RF register setting. */
		udelay(1);

		/* For disable/enable test in high temperature, the B6 value will fail to fill. Suggestion by BB Stanley, 2013.06.25. */
		if (Addr == 0xb6)
		{
			u4Byte getvalue =0;
			u1Byte	count =0;
			getvalue = PHY_QueryRFReg(pDM_Odm->Adapter, RF_PATH, Addr, bMaskDWord);

			udelay(1);

			while ((getvalue>>8)!=(Data>>8))
			{
				count++;
				PHY_SetRFReg(pDM_Odm->Adapter, RF_PATH, RegAddr, bRFRegOffsetMask, Data);
				udelay(1);
				getvalue = PHY_QueryRFReg(pDM_Odm->Adapter, RF_PATH, Addr, bMaskDWord);
				ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigRFWithHeaderFile: [B6] getvalue 0x%x, Data 0x%x, count %d\n", getvalue, Data, count));
				if (count>5)
					break;
			}
		}

		if (Addr == 0xb2)
		{
			u4Byte getvalue =0;
			u1Byte	count =0;
			getvalue = PHY_QueryRFReg(pDM_Odm->Adapter, RF_PATH, Addr, bMaskDWord);

			udelay(1);

			while (getvalue!=Data)
			{
				count++;
				PHY_SetRFReg(pDM_Odm->Adapter, RF_PATH, RegAddr, bRFRegOffsetMask, Data);
				udelay(1);
				/* Do LCK againg */
				PHY_SetRFReg(pDM_Odm->Adapter, RF_PATH, 0x18, bRFRegOffsetMask, 0x0fc07);
				udelay(1);
				getvalue = PHY_QueryRFReg(pDM_Odm->Adapter, RF_PATH, Addr, bMaskDWord);
				ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigRFWithHeaderFile: [B2] getvalue 0x%x, Data 0x%x, count %d\n", getvalue, Data, count));
				if (count>5)
					break;
			}
		}
	}
}


void
odm_ConfigRF_RadioA_8723B(
	IN	PDM_ODM_T				pDM_Odm,
	IN	u4Byte					Addr,
	IN	u4Byte					Data
	)
{
	u4Byte  content = 0x1000; /*  RF_Content: radioa_txt */
	u4Byte	maskforPhySet = (u4Byte)(content&0xE000);

	odm_ConfigRFReg_8723B(pDM_Odm, Addr, Data, ODM_RF_PATH_A, Addr|maskforPhySet);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigRFWithHeaderFile: [RadioA] %08X %08X\n", Addr, Data));
}

void
odm_ConfigMAC_8723B(
	IN	PDM_ODM_T	pDM_Odm,
	IN	u4Byte		Addr,
	IN	u1Byte		Data
	)
{
	rtw_write8(pDM_Odm->Adapter, Addr, Data);
    ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigMACWithHeaderFile: [MAC_REG] %08X %08X\n", Addr, Data));
}

void
odm_ConfigBB_AGC_8723B(
    IN	PDM_ODM_T	pDM_Odm,
    IN	u4Byte		Addr,
    IN	u4Byte		Bitmask,
    IN	u4Byte		Data
   )
{
	PHY_SetBBReg(pDM_Odm->Adapter, Addr, Bitmask, Data);
	/*  Add 1us delay between BB/RF register setting. */
	udelay(1);

    ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigBBWithHeaderFile: [AGC_TAB] %08X %08X\n", Addr, Data));
}

void
odm_ConfigBB_PHY_REG_PG_8723B(
	IN	PDM_ODM_T	pDM_Odm,
	IN	u4Byte		Band,
	IN	u4Byte		RfPath,
	IN	u4Byte		TxNum,
    IN	u4Byte		Addr,
    IN	u4Byte		Bitmask,
    IN	u4Byte		Data
   )
{
	if (Addr == 0xfe || Addr == 0xffe)
		msleep(50);
    else
    {
	    PHY_StoreTxPowerByRate(pDM_Odm->Adapter, Band, RfPath, TxNum, Addr, Bitmask, Data);
    }
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("===> ODM_ConfigBBWithHeaderFile: [PHY_REG] %08X %08X %08X\n", Addr, Bitmask, Data));
}

void
odm_ConfigBB_PHY_8723B(
	IN	PDM_ODM_T	pDM_Odm,
    IN	u4Byte		Addr,
    IN	u4Byte		Bitmask,
    IN	u4Byte		Data
   )
{
	if (Addr == 0xfe)
		msleep(50);
	else if (Addr == 0xfd)
		mdelay(5);
	else if (Addr == 0xfc)
		mdelay(1);
	else if (Addr == 0xfb)
		udelay(50);
	else if (Addr == 0xfa)
		udelay(5);
	else if (Addr == 0xf9)
		udelay(1);
	else
	{
		PHY_SetBBReg(pDM_Odm->Adapter, Addr, Bitmask, Data);
	}

	/*  Add 1us delay between BB/RF register setting. */
	udelay(1);
    ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigBBWithHeaderFile: [PHY_REG] %08X %08X\n", Addr, Data));
}

void
odm_ConfigBB_TXPWR_LMT_8723B(
	IN	PDM_ODM_T	pDM_Odm,
	IN	pu1Byte		Regulation,
	IN	pu1Byte		Band,
	IN	pu1Byte		Bandwidth,
	IN	pu1Byte		RateSection,
	IN	pu1Byte		RfPath,
	IN	pu1Byte		Channel,
	IN	pu1Byte		PowerLimit
	)
{
		PHY_SetTxPowerLimit(pDM_Odm->Adapter, Regulation, Band,
			Bandwidth, RateSection, RfPath, Channel, PowerLimit);
}
