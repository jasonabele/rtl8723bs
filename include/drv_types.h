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
/*-------------------------------------------------------------------------------

	For type defines and data structure defines

--------------------------------------------------------------------------------*/


#ifndef __DRV_TYPES_H__
#define __DRV_TYPES_H__

#include <autoconf.h>
#include <basic_types.h>
#include <osdep_service.h>
#include <rtw_byteorder.h>
#include <wlan_bssdef.h>
#include <wifi.h>
#include <ieee80211.h>

enum _NIC_VERSION {

	RTL8711_NIC,
	RTL8712_NIC,
	RTL8713_NIC,
	RTL8716_NIC

};

typedef struct _ADAPTER _adapter, ADAPTER,*PADAPTER;

#include <rtw_debug.h>
#include <rtw_rf.h>

#include <rtw_ht.h>

#ifdef CONFIG_INTEL_WIDI
#include <rtw_intel_widi.h>
#endif

#include <rtw_cmd.h>
#include <cmd_osdep.h>
#include <rtw_security.h>
#include <rtw_xmit.h>
#include <xmit_osdep.h>
#include <rtw_recv.h>

#include <recv_osdep.h>
#include <rtw_efuse.h>
#include <hal_intf.h>
#include <hal_com.h>
#include <rtw_qos.h>
#include <rtw_pwrctrl.h>
#include <rtw_mlme.h>
#include <mlme_osdep.h>
#include <rtw_io.h>
#include <rtw_ioctl.h>
#include <rtw_ioctl_set.h>
#include <osdep_intf.h>
#include <rtw_eeprom.h>
#include <sta_info.h>
#include <rtw_event.h>
#include <rtw_mlme_ext.h>
#include <rtw_ap.h>
#include <rtw_efuse.h>
#include <rtw_version.h>
#include <rtw_odm.h>

#include "ioctl_cfg80211.h"

#include <linux/ip.h>
#include <linux/if_ether.h>
#include <ethernet.h>

#define SPEC_DEV_ID_NONE BIT(0)
#define SPEC_DEV_ID_DISABLE_HT BIT(1)
#define SPEC_DEV_ID_ENABLE_PS BIT(2)
#define SPEC_DEV_ID_RF_CONFIG_1T1R BIT(3)
#define SPEC_DEV_ID_RF_CONFIG_2T2R BIT(4)
#define SPEC_DEV_ID_ASSIGN_IFNAME BIT(5)

struct specific_device_id{

	u32		flags;

	u16		idVendor;
	u16		idProduct;

};

struct registry_priv
{
	u8	chip_version;
	u8	rfintfs;
	u8	lbkmode;
	u8	hci;
	NDIS_802_11_SSID	ssid;
	u8	network_mode;	/* infra, ad-hoc, auto */
	u8	channel;/* ad-hoc support requirement */
	u8	wireless_mode;/* A, B, G, auto */
	u8	scan_mode;/* active, passive */
	u8	radio_enable;
	u8	preamble;/* long, short, auto */
	u8	vrtl_carrier_sense;/* Enable, Disable, Auto */
	u8	vcs_type;/* RTS/CTS, CTS-to-self */
	u16	rts_thresh;
	u16  frag_thresh;
	u8	adhoc_tx_pwr;
	u8	soft_ap;
	u8	power_mgnt;
	u8	ips_mode;
	u8	smart_ps;
	u8   usb_rxagg_mode;
	u8	long_retry_lmt;
	u8	short_retry_lmt;
	u16	busy_thresh;
	u8	ack_policy;
	u8	mp_mode;
	u8  mp_dm;
	u8	software_encrypt;
	u8	software_decrypt;
	u8	acm_method;
	  /* UAPSD */
	u8	wmm_enable;
	u8	uapsd_enable;
	u8	uapsd_max_sp;
	u8	uapsd_acbk_en;
	u8	uapsd_acbe_en;
	u8	uapsd_acvi_en;
	u8	uapsd_acvo_en;

	WLAN_BSSID_EX    dev_network;

	u8	ht_enable;
	/*  0: 20 MHz, 1: 40 MHz, 2: 80 MHz, 3: 160MHz */
	/*  2.4G use bit 0 ~ 3, 5G use bit 4 ~ 7 */
	/*  0x21 means enable 2.4G 40MHz & 5G 80MHz */
	u8	bw_mode;
	u8	ampdu_enable;/* for tx */
	u8	rx_stbc;
	u8	ampdu_amsdu;/* A-MPDU Supports A-MSDU is permitted */
	/*  Short GI support Bit Map */
	/*  BIT0 - 20MHz, 1: support, 0: non-support */
	/*  BIT1 - 40MHz, 1: support, 0: non-support */
	/*  BIT2 - 80MHz, 1: support, 0: non-support */
	/*  BIT3 - 160MHz, 1: support, 0: non-support */
	u8	short_gi;
	/*  BIT0: Enable VHT LDPC Rx, BIT1: Enable VHT LDPC Tx, BIT4: Enable HT LDPC Rx, BIT5: Enable HT LDPC Tx */
	u8	ldpc_cap;
	/*  BIT0: Enable VHT STBC Rx, BIT1: Enable VHT STBC Tx, BIT4: Enable HT STBC Rx, BIT5: Enable HT STBC Tx */
	u8	stbc_cap;
	/*  BIT0: Enable VHT Beamformer, BIT1: Enable VHT Beamformee, BIT4: Enable HT Beamformer, BIT5: Enable HT Beamformee */
	u8	beamform_cap;

	u8	lowrate_two_xmit;

	u8	rf_config ;
	u8	low_power ;

	u8	wifi_spec;/*  !turbo_mode */

	u8	channel_plan;

	u8	btcoex;
	u8	bt_iso;
	u8	bt_sco;
	u8	bt_ampdu;
	s8	ant_num;

	bool	bAcceptAddbaReq;

	u8	antdiv_cfg;
	u8	antdiv_type;

	u8	usbss_enable;/* 0:disable, 1:enable */
	u8	hwpdn_mode;/* 0:disable, 1:enable, 2:decide by EFUSE config */
	u8	hwpwrp_detect;/* 0:disable, 1:enable */

	u8	hw_wps_pbc;/* 0:disable, 1:enable */

	u8	max_roaming_times; /*  the max number driver will try to roaming */

	u8 enable80211d;

	u8 ifname[16];
	u8 if2name[16];

	u8 notch_filter;

	/* define for tx power adjust */
	u8	RegEnableTxPowerLimit;
	u8	RegEnableTxPowerByRate;
	u8	RegPowerBase;
	u8	RegPwrTblSel;
	s8	TxBBSwing_2G;
	s8	TxBBSwing_5G;
	u8	AmplifierType_2G;
	u8	AmplifierType_5G;
	u8	bEn_RFE;
	u8	RFE_Type;
	u8  check_fw_ps;

#ifdef CONFIG_LOAD_PHY_PARA_FROM_FILE
	u8	load_phy_file;
	u8	RegDecryptCustomFile;
#endif

#ifdef CONFIG_MULTI_VIR_IFACES
	u8 ext_iface_num;/* primary/secondary iface is excluded */
#endif
	u8 qos_opt_enable;

	u8 hiq_filter;
};


/* For registry parameters */
#define RGTRY_OFT(field) ((u32)FIELD_OFFSET(struct registry_priv, field))
#define RGTRY_SZ(field)   sizeof(((struct registry_priv*) 0)->field)
#define BSSID_OFT(field) ((u32)FIELD_OFFSET(WLAN_BSSID_EX, field))
#define BSSID_SZ(field)   sizeof(((PWLAN_BSSID_EX) 0)->field)



#include <drv_types_sdio.h>
#define INTF_DATA SDIO_DATA

#define is_primary_adapter(adapter) (1)
#define get_iface_type(adapter) (IFACE_PORT0)
#define GET_PRIMARY_ADAPTER(padapter) (((_adapter *)padapter)->dvobj->if1)
#define GET_IFACE_NUMS(padapter) (((_adapter *)padapter)->dvobj->iface_nums)
#define GET_ADAPTER(padapter, iface_id) (((_adapter *)padapter)->dvobj->padapters[iface_id])

enum _IFACE_ID {
	IFACE_ID0, /* maping to PRIMARY_ADAPTER */
	IFACE_ID1, /* maping to SECONDARY_ADAPTER */
	IFACE_ID2,
	IFACE_ID3,
	IFACE_ID_MAX,
};

#ifdef CONFIG_DBG_COUNTER

struct rx_logs {
	u32 intf_rx;
	u32 intf_rx_err_recvframe;
	u32 intf_rx_err_skb;
	u32 intf_rx_report;
	u32 core_rx;
	u32 core_rx_pre;
	u32 core_rx_pre_ver_err;
	u32 core_rx_pre_mgmt;
	u32 core_rx_pre_mgmt_err_80211w;
	u32 core_rx_pre_mgmt_err;
	u32 core_rx_pre_ctrl;
	u32 core_rx_pre_ctrl_err;
	u32 core_rx_pre_data;
	u32 core_rx_pre_data_wapi_seq_err;
	u32 core_rx_pre_data_wapi_key_err;
	u32 core_rx_pre_data_handled;
	u32 core_rx_pre_data_err;
	u32 core_rx_pre_data_unknown;
	u32 core_rx_pre_unknown;
	u32 core_rx_enqueue;
	u32 core_rx_dequeue;
	u32 core_rx_post;
	u32 core_rx_post_decrypt;
	u32 core_rx_post_decrypt_wep;
	u32 core_rx_post_decrypt_tkip;
	u32 core_rx_post_decrypt_aes;
	u32 core_rx_post_decrypt_wapi;
	u32 core_rx_post_decrypt_hw;
	u32 core_rx_post_decrypt_unknown;
	u32 core_rx_post_decrypt_err;
	u32 core_rx_post_defrag_err;
	u32 core_rx_post_portctrl_err;
	u32 core_rx_post_indicate;
	u32 core_rx_post_indicate_in_oder;
	u32 core_rx_post_indicate_reoder;
	u32 core_rx_post_indicate_err;
	u32 os_indicate;
	u32 os_indicate_ap_mcast;
	u32 os_indicate_ap_forward;
	u32 os_indicate_ap_self;
	u32 os_indicate_err;
	u32 os_netif_ok;
	u32 os_netif_err;
};

struct tx_logs {
	u32 os_tx;
	u32 os_tx_err_up;
	u32 os_tx_err_xmit;
	u32 os_tx_m2u;
	u32 os_tx_m2u_ignore_fw_linked;
	u32 os_tx_m2u_ignore_self;
	u32 os_tx_m2u_entry;
	u32 os_tx_m2u_entry_err_xmit;
	u32 os_tx_m2u_entry_err_skb;
	u32 os_tx_m2u_stop;
	u32 core_tx;
	u32 core_tx_err_pxmitframe;
	u32 core_tx_err_brtx;
	u32 core_tx_upd_attrib;
	u32 core_tx_upd_attrib_adhoc;
	u32 core_tx_upd_attrib_sta;
	u32 core_tx_upd_attrib_ap;
	u32 core_tx_upd_attrib_unknown;
	u32 core_tx_upd_attrib_dhcp;
	u32 core_tx_upd_attrib_icmp;
	u32 core_tx_upd_attrib_active;
	u32 core_tx_upd_attrib_err_ucast_sta;
	u32 core_tx_upd_attrib_err_ucast_ap_link;
	u32 core_tx_upd_attrib_err_sta;
	u32 core_tx_upd_attrib_err_link;
	u32 core_tx_upd_attrib_err_sec;
	u32 core_tx_ap_enqueue_warn_fwstate;
	u32 core_tx_ap_enqueue_warn_sta;
	u32 core_tx_ap_enqueue_warn_nosta;
	u32 core_tx_ap_enqueue_warn_link;
	u32 core_tx_ap_enqueue_warn_trigger;
	u32 core_tx_ap_enqueue_mcast;
	u32 core_tx_ap_enqueue_ucast;
	u32 core_tx_ap_enqueue;
	u32 intf_tx;
	u32 intf_tx_pending_ac;
	u32 intf_tx_pending_fw_under_survey;
	u32 intf_tx_pending_fw_under_linking;
	u32 intf_tx_pending_xmitbuf;
	u32 intf_tx_enqueue;
	u32 core_tx_enqueue;
	u32 core_tx_enqueue_class;
	u32 core_tx_enqueue_class_err_sta;
	u32 core_tx_enqueue_class_err_nosta;
	u32 core_tx_enqueue_class_err_fwlink;
	u32 intf_tx_direct;
	u32 intf_tx_direct_err_coalesce;
	u32 intf_tx_dequeue;
	u32 intf_tx_dequeue_err_coalesce;
	u32 intf_tx_dump_xframe;
	u32 intf_tx_dump_xframe_err_txdesc;
	u32 intf_tx_dump_xframe_err_port;
};

struct int_logs {
	u32 all;
	u32 err;
	u32 tbdok;
	u32 tbder;
	u32 bcnderr;
	u32 bcndma;
	u32 bcndma_e;
	u32 rx;
	u32 rx_rdu;
	u32 rx_fovw;
	u32 txfovw;
	u32 mgntok;
	u32 highdok;
	u32 bkdok;
	u32 bedok;
	u32 vidok;
	u32 vodok;
};

#endif /*  CONFIG_DBG_COUNTER */

struct debug_priv {
	u32 dbg_sdio_free_irq_error_cnt;
	u32 dbg_sdio_alloc_irq_error_cnt;
	u32 dbg_sdio_free_irq_cnt;
	u32 dbg_sdio_alloc_irq_cnt;
	u32 dbg_sdio_deinit_error_cnt;
	u32 dbg_sdio_init_error_cnt;
	u32 dbg_suspend_error_cnt;
	u32 dbg_suspend_cnt;
	u32 dbg_resume_cnt;
	u32 dbg_resume_error_cnt;
	u32 dbg_deinit_fail_cnt;
	u32 dbg_carddisable_cnt;
	u32 dbg_carddisable_error_cnt;
	u32 dbg_ps_insuspend_cnt;
	u32	dbg_dev_unload_inIPS_cnt;
	u32 dbg_wow_leave_ps_fail_cnt;
	u32 dbg_scan_pwr_state_cnt;
	u32 dbg_downloadfw_pwr_state_cnt;
	u32 dbg_fw_read_ps_state_fail_cnt;
	u32 dbg_leave_ips_fail_cnt;
	u32 dbg_leave_lps_fail_cnt;
	u32 dbg_h2c_leave32k_fail_cnt;
	u32 dbg_diswow_dload_fw_fail_cnt;
	u32 dbg_enwow_dload_fw_fail_cnt;
	u32 dbg_ips_drvopen_fail_cnt;
	u32 dbg_poll_fail_cnt;
	u32 dbg_rpwm_toogle_cnt;
	u32 dbg_rpwm_timeout_fail_cnt;
	u64 dbg_rx_fifo_last_overflow;
	u64 dbg_rx_fifo_curr_overflow;
	u64 dbg_rx_fifo_diff_overflow;
	u64 dbg_rx_ampdu_drop_count;
	u64 dbg_rx_ampdu_forced_indicate_count;
	u64 dbg_rx_ampdu_loss_count;
	u64 dbg_rx_dup_mgt_frame_drop_count;
	u64 dbg_rx_ampdu_window_shift_cnt;
};

struct rtw_traffic_statistics {
	/*  tx statistics */
	u64	tx_bytes;
	u64	tx_pkts;
	u64	tx_drop;
	u64	cur_tx_bytes;
	u64	last_tx_bytes;
	u32	cur_tx_tp; /*  Tx throughput in MBps. */

	/*  rx statistics */
	u64	rx_bytes;
	u64	rx_pkts;
	u64	rx_drop;
	u64	cur_rx_bytes;
	u64	last_rx_bytes;
	u32	cur_rx_tp; /*  Rx throughput in MBps. */
};

struct cam_ctl_t {
	_lock lock;
	u64 bitmap;
};

struct cam_entry_cache {
	u16 ctrl;
	u8 mac[ETH_ALEN];
	u8 key[16];
};

#define KEY_FMT "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x"
#define KEY_ARG(x) ((u8*)(x))[0], ((u8*)(x))[1], ((u8*)(x))[2], ((u8*)(x))[3], ((u8*)(x))[4], ((u8*)(x))[5], \
	((u8*)(x))[6], ((u8*)(x))[7], ((u8*)(x))[8], ((u8*)(x))[9], ((u8*)(x))[10], ((u8*)(x))[11], \
	((u8*)(x))[12], ((u8*)(x))[13], ((u8*)(x))[14], ((u8*)(x))[15]

struct dvobj_priv
{
	/*-------- below is common data --------*/
	_adapter *if1; /* PRIMARY_ADAPTER */
	_adapter *if2; /* SECONDARY_ADAPTER */

	s32	processing_dev_remove;

	struct debug_priv drv_dbg;

	/* for local/global synchronization */
	/*  */
	_lock	lock;
	int macid[NUM_STA];

	_mutex hw_init_mutex;
	_mutex h2c_fwcmd_mutex;
	_mutex setch_mutex;
	_mutex setbw_mutex;

	unsigned char	oper_channel; /* saved channel info when call set_channel_bw */
	unsigned char	oper_bwmode;
	unsigned char	oper_ch_offset;/* PRIME_CHNL_OFFSET */
	unsigned long on_oper_ch_time;

	/* extend to support mulitu interface */
	/* padapters[IFACE_ID0] == if1 */
	/* padapters[IFACE_ID1] == if2 */
	_adapter *padapters[IFACE_ID_MAX];
	u8 iface_nums; /*  total number of ifaces used runtime */

	struct cam_ctl_t cam_ctl;
	struct cam_entry_cache cam_cache[TOTAL_CAM_ENTRY];

	/* For 92D, DMDP have 2 interface. */
	u8	InterfaceNumber;
	u8	NumInterfaces;

	/* In /Out Pipe information */
	int	RtInPipe[2];
	int	RtOutPipe[4];
	u8	Queue2Pipe[HW_QUEUE_ENTRY];/* for out pipe mapping */

	u8	irq_alloc;
	atomic_t continual_io_error;

	atomic_t disable_func;

	struct pwrctrl_priv pwrctl_priv;

	struct rtw_traffic_statistics	traffic_stat;

/*-------- below is for SDIO INTERFACE --------*/

#ifdef INTF_DATA
	INTF_DATA intf_data;
#endif
};

#define dvobj_to_pwrctl(dvobj) (&(dvobj->pwrctl_priv))
#define pwrctl_to_dvobj(pwrctl) container_of(pwrctl, struct dvobj_priv, pwrctl_priv)

__inline static struct device *dvobj_to_dev(struct dvobj_priv *dvobj)
{
	/* todo: get interface type from dvobj and the return the dev accordingly */
#ifdef RTW_DVOBJ_CHIP_HW_TYPE
#endif

	return &dvobj->intf_data.func->dev;
}

_adapter *dvobj_get_port0_adapter(struct dvobj_priv *dvobj);

enum _IFACE_TYPE {
	IFACE_PORT0, /* mapping to port0 for C/D series chips */
	IFACE_PORT1, /* mapping to port1 for C/D series chip */
	MAX_IFACE_PORT,
};

enum _ADAPTER_TYPE {
	PRIMARY_ADAPTER,
	SECONDARY_ADAPTER,
	MAX_ADAPTER = 0xFF,
};

typedef enum _DRIVER_STATE{
	DRIVER_NORMAL = 0,
	DRIVER_DISAPPEAR = 1,
	DRIVER_REPLACE_DONGLE = 2,
}DRIVER_STATE;

struct _ADAPTER{
	int	DriverState;/*  for disable driver using module, use dongle to replace module. */
	int	pid[3];/* process id from UI, 0:wps, 1:hostapd, 2:dhcpcd */
	int	bDongle;/* build-in module or external dongle */

	struct dvobj_priv *dvobj;
	struct	mlme_priv mlmepriv;
	struct	mlme_ext_priv mlmeextpriv;
	struct	cmd_priv	cmdpriv;
	struct	evt_priv	evtpriv;
	/* struct	io_queue	*pio_queue; */
	struct	io_priv	iopriv;
	struct	xmit_priv	xmitpriv;
	struct	recv_priv	recvpriv;
	struct	sta_priv	stapriv;
	struct	security_priv	securitypriv;
	_lock   security_key_mutex; /*  add for CONFIG_IEEE80211W, none 11w also can use */
	struct	registry_priv	registrypriv;
	struct	eeprom_priv eeprompriv;

	struct	hostapd_priv	*phostapdpriv;

	u32	setband;

	void *			HalData;
	u32 hal_data_sz;
	struct hal_ops	HalFunc;

	s32	bDriverStopped;
	s32	bSurpriseRemoved;
	s32  bCardDisableWOHSM;

	u32	IsrContent;
	u32	ImrContent;

	u8	EepromAddressSize;
	u8	hw_init_completed;
	u8	bDriverIsGoingToUnload;
	u8	init_adpt_in_progress;
	u8	bHaltInProgress;

	void * cmdThread;
	void * evtThread;
	void * xmitThread;
	void * recvThread;

	u32 (*intf_init)(struct dvobj_priv *dvobj);
	void (*intf_deinit)(struct dvobj_priv *dvobj);
	int (*intf_alloc_irq)(struct dvobj_priv *dvobj);
	void (*intf_free_irq)(struct dvobj_priv *dvobj);


	void (*intf_start)(_adapter * adapter);
	void (*intf_stop)(_adapter * adapter);

	_nic_hdl pnetdev;
	char old_ifname[IFNAMSIZ];

	/*  used by rtw_rereg_nd_name related function */
	struct rereg_nd_name_data {
		_nic_hdl old_pnetdev;
		char old_ifname[IFNAMSIZ];
		u8 old_ips_mode;
		u8 old_bRegUseLed;
	} rereg_nd_name_priv;

	int bup;
	struct net_device_stats stats;
	struct iw_statistics iwstats;
	struct proc_dir_entry *dir_dev;/*  for proc directory */
	struct proc_dir_entry *dir_odm;

	struct wireless_dev *rtw_wdev;
	struct rtw_wdev_priv wdev_data;

	int net_closed;

	u8 netif_up;

	u8 bFWReady;
	u8 bBTFWReady;
	u8 bLinkInfoDump;
	u8 bRxRSSIDisplay;
	/* 	Added by Albert 2012/10/26 */
	/* 	The driver will show up the desired channel number when this flag is 1. */
	u8 bNotifyChannelChange;

	/* pbuddy_adapter is used only in  two inteface case, (iface_nums =2 in struct dvobj_priv) */
	/* PRIMARY_ADAPTER's buddy is SECONDARY_ADAPTER */
	/* SECONDARY_ADAPTER's buddy is PRIMARY_ADAPTER */
	/* for iface_id > SECONDARY_ADAPTER(IFACE_ID1), refer to padapters[iface_id]  in struct dvobj_priv */
	/* and their pbuddy_adapter is PRIMARY_ADAPTER. */
	/* for PRIMARY_ADAPTER(IFACE_ID0) can directly refer to if1 in struct dvobj_priv */
	_adapter *pbuddy_adapter;

	/* extend to support multi interface */
       /* IFACE_ID0 is equals to PRIMARY_ADAPTER */
       /* IFACE_ID1 is equals to SECONDARY_ADAPTER */
	u8 iface_id;

	/* for debug purpose */
	u8 fix_rate;
	u8 driver_vcs_en; /* Enable =1, Disable =0 driver control vrtl_carrier_sense for tx */
	u8 driver_vcs_type;/* force 0:disable VCS, 1:RTS-CTS, 2:CTS-to-self when vcs_en =1. */
	u8 driver_ampdu_spacing;/* driver control AMPDU Density for peer sta's rx */
	u8 driver_rx_ampdu_factor;/* 0xff: disable drv ctrl, 0:8k, 1:16k, 2:32k, 3:64k; */

	unsigned char     in_cta_test;

#ifdef CONFIG_DBG_COUNTER
	struct rx_logs rx_logs;
	struct tx_logs tx_logs;
	struct int_logs int_logs;
#endif
};

#define adapter_to_dvobj(adapter) (adapter->dvobj)
#define adapter_to_pwrctl(adapter) (dvobj_to_pwrctl(adapter->dvobj))
#define adapter_wdev_data(adapter) (&((adapter)->wdev_data))

/*  */
/*  Function disabled. */
/*  */
#define DF_TX_BIT		BIT0
#define DF_RX_BIT		BIT1
#define DF_IO_BIT		BIT2

/* define RTW_DISABLE_FUNC(padapter, func) (atomic_add(&adapter_to_dvobj(padapter)->disable_func, (func))) */
/* define RTW_ENABLE_FUNC(padapter, func) (atomic_sub(&adapter_to_dvobj(padapter)->disable_func, (func))) */
__inline static void RTW_DISABLE_FUNC(_adapter*padapter, int func_bit)
{
	int	df = atomic_read(&adapter_to_dvobj(padapter)->disable_func);
	df |= func_bit;
	atomic_set(&adapter_to_dvobj(padapter)->disable_func, df);
}

__inline static void RTW_ENABLE_FUNC(_adapter*padapter, int func_bit)
{
	int	df = atomic_read(&adapter_to_dvobj(padapter)->disable_func);
	df &= ~(func_bit);
	atomic_set(&adapter_to_dvobj(padapter)->disable_func, df);
}

#define RTW_IS_FUNC_DISABLED(padapter, func_bit) (atomic_read(&adapter_to_dvobj(padapter)->disable_func) & (func_bit))

#define RTW_CANNOT_IO(padapter) \
			((padapter)->bSurpriseRemoved || \
			 RTW_IS_FUNC_DISABLED((padapter), DF_IO_BIT))

#define RTW_CANNOT_RX(padapter) \
			((padapter)->bDriverStopped || \
			 (padapter)->bSurpriseRemoved || \
			 RTW_IS_FUNC_DISABLED((padapter), DF_RX_BIT))

#define RTW_CANNOT_TX(padapter) \
			((padapter)->bDriverStopped || \
			 (padapter)->bSurpriseRemoved || \
			 RTW_IS_FUNC_DISABLED((padapter), DF_TX_BIT))

#ifdef CONFIG_GPIO_API
int rtw_get_gpio(struct net_device *netdev, int gpio_num);
int rtw_set_gpio_output_value(struct net_device *netdev, int gpio_num, bool isHigh);
int rtw_config_gpio(struct net_device *netdev, int gpio_num, bool isOutput);
#endif

#ifdef CONFIG_WOWLAN
int rtw_suspend_wow(_adapter *padapter);
int rtw_resume_process_wow(_adapter *padapter);
#endif

__inline static u8 *myid(struct eeprom_priv *peepriv)
{
	return (peepriv->mac_addr);
}

/*  HCI Related header file */
#include <sdio_osintf.h>
#include <sdio_ops.h>
#include <sdio_hal.h>

#include <rtw_btcoex.h>

void rtw_indicate_wx_disassoc_event(_adapter *padapter);
void rtw_indicate_wx_assoc_event(_adapter *padapter);
void rtw_indicate_wx_disassoc_event(_adapter *padapter);
void indicate_wx_scan_complete_event(_adapter *padapter);
int rtw_change_ifname(_adapter *padapter, const char *ifname);

extern char *rtw_phy_file_path;
extern char *rtw_initmac;
extern int rtw_mc2u_disable;
extern int rtw_ht_enable;
extern u32 g_wait_hiq_empty;
extern u8 g_fwdl_wintint_rdy_fail;
extern u8 g_fwdl_chksum_fail;

#endif /* __DRV_TYPES_H__ */
