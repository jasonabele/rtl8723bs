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
#ifndef __SDIO_HAL_H__
#define __SDIO_HAL_H__


extern u8 sd_hal_bus_init(PADAPTER padapter);
extern u8 sd_hal_bus_deinit(PADAPTER padapter);

u8 sd_int_isr(PADAPTER padapter);
void sd_int_dpc(PADAPTER padapter);
void rtw_set_hal_ops(_adapter *padapter);

void rtl8723bs_set_hal_ops(PADAPTER padapter);

#endif /* __SDIO_HAL_H__ */
