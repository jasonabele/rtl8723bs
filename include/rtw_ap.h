/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
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
#ifndef __RTW_AP_H_
#define __RTW_AP_H_

void init_mlme_ap_info(_adapter *padapter);
void free_mlme_ap_info(_adapter *padapter);
/* void update_BCNTIM(_adapter *padapter); */
void update_beacon(_adapter *padapter, u8 ie_id, u8 *oui, u8 tx);
void add_RATid(_adapter *padapter, struct sta_info *psta, u8 rssi_level);
void expire_timeout_chk(_adapter *padapter);
void update_sta_info_apmode(_adapter *padapter, struct sta_info *psta);
void start_bss_network(_adapter *padapter, u8 *pbuf);
int rtw_check_beacon_data(_adapter *padapter, u8 *pbuf,  int len);
void rtw_ap_restore_network(_adapter *padapter);
void rtw_set_macaddr_acl(_adapter *padapter, int mode);
int rtw_acl_add_sta(_adapter *padapter, u8 *addr);
int rtw_acl_remove_sta(_adapter *padapter, u8 *addr);

u8 rtw_ap_set_pairwise_key(_adapter *padapter, struct sta_info *psta);
int rtw_ap_set_group_key(_adapter *padapter, u8 *key, u8 alg, int keyid);
int rtw_ap_set_wep_key(_adapter *padapter, u8 *key, u8 keylen, int keyid, u8 set_tx);

void associated_clients_update(_adapter *padapter, u8 updated);
void bss_cap_update_on_sta_join(_adapter *padapter, struct sta_info *psta);
u8 bss_cap_update_on_sta_leave(_adapter *padapter, struct sta_info *psta);
void sta_info_update(_adapter *padapter, struct sta_info *psta);
void ap_sta_info_defer_update(_adapter *padapter, struct sta_info *psta);
u8 ap_free_sta(_adapter *padapter, struct sta_info *psta, bool active, u16 reason);
int rtw_sta_flush(_adapter *padapter);
void start_ap_mode(_adapter *padapter);
void stop_ap_mode(_adapter *padapter);

#endif
void update_bmc_sta(_adapter *padapter);
