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
#ifndef _RTW_BR_EXT_H_
#define _RTW_BR_EXT_H_

#define MACADDRLEN		6
#define _DEBUG_ERR		DBG_8192C
#define _DEBUG_INFO		/* DBG_8192C */
#define DEBUG_WARN		DBG_8192C
#define DEBUG_INFO		/* DBG_8192C */
#define DEBUG_ERR		DBG_8192C
/* define GET_MY_HWADDR		((GET_MIB(priv))->dot11OperationEntry.hwaddr) */
#define GET_MY_HWADDR(padapter)		((padapter)->eeprompriv.mac_addr)

#define NAT25_HASH_BITS		4
#define NAT25_HASH_SIZE		(1 << NAT25_HASH_BITS)
#define NAT25_AGEING_TIME	300

#define MAX_NETWORK_ADDR_LEN	17

struct nat25_network_db_entry
{
	struct nat25_network_db_entry	*next_hash;
	struct nat25_network_db_entry	**pprev_hash;
	atomic_t						use_count;
	unsigned char					macAddr[6];
	unsigned long					ageing_timer;
	unsigned char					networkAddr[MAX_NETWORK_ADDR_LEN];
};

enum NAT25_METHOD {
	NAT25_MIN,
	NAT25_CHECK,
	NAT25_INSERT,
	NAT25_LOOKUP,
	NAT25_PARSE,
	NAT25_MAX
};

struct br_ext_info {
	unsigned int	nat25_disable;
	unsigned int	macclone_enable;
	unsigned int	dhcp_bcst_disable;
	int		addPPPoETag;		/*  1: Add PPPoE relay-SID, 0: disable */
	unsigned char	nat25_dmzMac[MACADDRLEN];
	unsigned int	nat25sc_disable;
};

void nat25_db_cleanup(_adapter *priv);

#endif /*  _RTW_BR_EXT_H_ */
