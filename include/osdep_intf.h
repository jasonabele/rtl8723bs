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

#ifndef __OSDEP_INTF_H_
#define __OSDEP_INTF_H_


struct intf_priv {

	u8 *intf_dev;
	u32	max_iosz;	/* USB2.0: 128, USB1.1: 64, SDIO:64 */
	u32	max_xmitsz; /* USB2.0: unlimited, SDIO:512 */
	u32	max_recvsz; /* USB2.0: unlimited, SDIO:512 */

	volatile u8 *io_rwmem;
	volatile u8 *allocated_io_rwmem;
	u32	io_wsz; /* unit: 4bytes */
	u32	io_rsz;/* unit: 4bytes */
	u8 intf_status;

	void (*_bus_io)(u8 *priv);

/*
Under Sync. IRP (SDIO/USB)
A protection mechanism is necessary for the io_rwmem(read/write protocol)

Under Async. IRP (SDIO/USB)
The protection mechanism is through the pending queue.
*/

	_mutex ioctl_mutex;
};


#ifdef CONFIG_R871X_TEST
int rtw_start_pseudo_adhoc(_adapter *padapter);
int rtw_stop_pseudo_adhoc(_adapter *padapter);
#endif

struct dvobj_priv *devobj_init(void);
void devobj_deinit(struct dvobj_priv *pdvobj);

u8 rtw_init_drv_sw(_adapter *padapter);
u8 rtw_free_drv_sw(_adapter *padapter);
u8 rtw_reset_drv_sw(_adapter *padapter);
void rtw_dev_unload(PADAPTER padapter);

u32 rtw_start_drv_threads(_adapter *padapter);
void rtw_stop_drv_threads (_adapter *padapter);
void rtw_cancel_all_timer(_adapter *padapter);

int rtw_ioctl(struct net_device *dev, struct ifreq *rq, int cmd);

int rtw_init_netdev_name(struct net_device *pnetdev, const char *ifname);
struct net_device *rtw_init_netdev(_adapter *padapter);
void rtw_unregister_netdevs(struct dvobj_priv *dvobj);

u16 rtw_recv_select_queue(struct sk_buff *skb);

int rtw_ndev_notifier_register(void);
void rtw_ndev_notifier_unregister(void);

#include "../os_dep/rtw_proc.h"

void rtw_ips_dev_unload(_adapter *padapter);

int rtw_ips_pwr_up(_adapter *padapter);
void rtw_ips_pwr_down(_adapter *padapter);

int rtw_drv_register_netdev(_adapter *padapter);
void rtw_ndev_destructor(_nic_hdl ndev);

int rtw_suspend_common(_adapter *padapter);
int rtw_resume_common(_adapter *padapter);

#endif	/* _OSDEP_INTF_H_ */
