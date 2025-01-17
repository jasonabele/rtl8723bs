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
#ifndef __INC_HAL8723BPHYCFG_H__
#define __INC_HAL8723BPHYCFG_H__

/*--------------------------Define Parameters-------------------------------*/
#define LOOP_LIMIT				5
#define MAX_STALL_TIME			50		/* us */
#define AntennaDiversityValue	0x80	/* Adapter->bSoftwareAntennaDiversity ? 0x00:0x80) */
#define MAX_TXPWR_IDX_NMODE_92S	63
#define Reset_Cnt_Limit			3

#define MAX_AGGR_NUM	0x07


/*--------------------------Define Parameters End-------------------------------*/


/*------------------------------Define structure----------------------------*/

/*------------------------------Define structure End----------------------------*/

/*--------------------------Exported Function prototype---------------------*/
u32
PHY_QueryBBReg_8723B(
	IN	PADAPTER	Adapter,
	IN	u32		RegAddr,
	IN	u32		BitMask
	);

void
PHY_SetBBReg_8723B(
	IN	PADAPTER	Adapter,
	IN	u32		RegAddr,
	IN	u32		BitMask,
	IN	u32		Data
	);

u32
PHY_QueryRFReg_8723B(
	IN	PADAPTER			Adapter,
	IN	u8				eRFPath,
	IN	u32				RegAddr,
	IN	u32				BitMask
	);

void
PHY_SetRFReg_8723B(
	IN	PADAPTER			Adapter,
	IN	u8				eRFPath,
	IN	u32				RegAddr,
	IN	u32				BitMask,
	IN	u32				Data
	);

/* MAC/BB/RF HAL config */
int PHY_BBConfig8723B(PADAPTER	Adapter	);

int PHY_RFConfig8723B(PADAPTER	Adapter	);

s32 PHY_MACConfig8723B(PADAPTER padapter);

void
PHY_SetTxPowerIndex_8723B(
	IN	PADAPTER			Adapter,
	IN	u32					PowerIndex,
	IN	u8					RFPath,
	IN	u8					Rate
	);

u8
PHY_GetTxPowerIndex_8723B(
	IN	PADAPTER			pAdapter,
	IN	u8					RFPath,
	IN	u8					Rate,
	IN	CHANNEL_WIDTH		BandWidth,
	IN	u8					Channel
	);

void
PHY_GetTxPowerLevel8723B(
	IN	PADAPTER		Adapter,
	OUT s32*				powerlevel
	);

void
PHY_SetTxPowerLevel8723B(
	IN	PADAPTER		Adapter,
	IN	u8			channel
	);

void
PHY_SetBWMode8723B(
	IN	PADAPTER				Adapter,
	IN	CHANNEL_WIDTH			Bandwidth,	/*  20M or 40M */
	IN	unsigned char				Offset		/*  Upper, Lower, or Don't care */
);

void
PHY_SwChnl8723B(	/*  Call after initialization */
	IN	PADAPTER	Adapter,
	IN	u8		channel
	);

void
PHY_SetSwChnlBWMode8723B(
	IN	PADAPTER			Adapter,
	IN	u8					channel,
	IN	CHANNEL_WIDTH		Bandwidth,
	IN	u8					Offset40,
	IN	u8					Offset80
);

/*--------------------------Exported Function prototype End---------------------*/

#endif
