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

#ifndef __HAL_PHY_RF_8723B_H__
#define __HAL_PHY_RF_8723B_H__

/*--------------------------Define Parameters-------------------------------*/
#define	IQK_DELAY_TIME_8723B		20		/* ms */
#define IQK_DEFERRED_TIME_8723B		4
#define	index_mapping_NUM_8723B		15
#define AVG_THERMAL_NUM_8723B		4
#define	RF_T_METER_8723B					0x42	/*  */


void ConfigureTxpowerTrack_8723B(
	PTXPWRTRACK_CFG	pConfig
	);

void DoIQK_8723B(
	PDM_ODM_T	pDM_Odm,
	u1Byte		DeltaThermalIndex,
	u1Byte		ThermalValue,
	u1Byte		Threshold
	);

void
ODM_TxPwrTrackSetPwr_8723B(
	PDM_ODM_T			pDM_Odm,
	PWRTRACK_METHOD		Method,
	u1Byte				RFPath,
	u1Byte				ChannelMappedIndex
	);

/* 1 7.	IQK */

void
PHY_IQCalibrate_8723B(
	IN PADAPTER	Adapter,
	IN bool	bReCovery,
	IN bool	bRestore,
	IN bool	Is2ant,
	IN u1Byte	RF_Path);

void
ODM_SetIQCbyRFpath(
	IN PDM_ODM_T		pDM_Odm,
    IN u4Byte RFpath
	);

/*  */
/*  LC calibrate */
/*  */
void
PHY_LCCalibrate_8723B(
	IN PDM_ODM_T		pDM_Odm
);

/*  */
/*  AP calibrate */
/*  */
void
PHY_DigitalPredistortion_8723B(		IN	PADAPTER	pAdapter);


void
_PHY_SaveADDARegisters_8723B(
	IN	PADAPTER	pAdapter,
	IN	pu4Byte		ADDAReg,
	IN	pu4Byte		ADDABackup,
	IN	u4Byte		RegisterNum
	);

void
_PHY_PathADDAOn_8723B(
	IN	PADAPTER	pAdapter,
	IN	pu4Byte		ADDAReg,
	IN	bool		isPathAOn,
	IN	bool		is2T
	);

void
_PHY_MACSettingCalibration_8723B(
	IN	PADAPTER	pAdapter,
	IN	pu4Byte		MACReg,
	IN	pu4Byte		MACBackup
	);

#endif	/*  #ifndef __HAL_PHY_RF_8188E_H__ */
