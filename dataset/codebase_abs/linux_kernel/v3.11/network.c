static char * F_1 ( char * V_1 , ... )
{
char * * V_2 , * V_3 ;
T_1 V_4 ;
va_start ( V_4 , V_1 ) ;
while ( ( V_2 = va_arg ( V_4 , char * * ) ) != NULL ) {
if ( * V_1 == '\0' )
return NULL ;
V_3 = strchr ( V_1 , ',' ) ;
if ( V_3 != V_1 )
* V_2 = V_1 ;
if ( V_3 == NULL )
return NULL ;
* V_3 ++ = '\0' ;
V_1 = V_3 ;
}
va_end ( V_4 ) ;
return V_1 ;
}
static void F_2 ( void * V_5 , char * V_6 , char * V_7 )
{
struct V_8 * V_9 = V_5 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_14 ;
T_2 V_15 ;
if ( ( V_11 == NULL ) || ( ( V_14 = V_11 -> V_16 ) == NULL ) ) {
F_3 ( V_17 L_1 ) ;
return;
}
V_15 = V_14 -> V_18 ;
sprintf ( V_6 , L_2 , V_15 & 0xff , ( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff , V_15 >> 24 ) ;
if ( V_7 ) {
V_7 [ 0 ] = V_15 & 0xff ;
V_7 [ 1 ] = ( V_15 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_15 >> 16 ) & 0xff ;
V_7 [ 3 ] = V_15 >> 24 ;
}
}
static void inline F_4 ( void * V_5 , unsigned char * V_15 )
{
struct V_8 * V_9 = V_5 ;
memcpy ( V_9 -> V_19 , V_15 , V_20 ) ;
}
static int F_5 ( struct V_21 * V_22 )
{
struct V_23 V_24 ;
char * V_25 = V_22 -> V_26 . V_27 . V_28 . V_25 ;
int V_29 = - V_30 ;
int V_31 ;
if ( ! V_22 -> V_26 . V_27 . V_28 . V_32 )
return - V_30 ;
if ( ( V_31 = F_6 ( L_3 , 02 , 0 ) ) < 0 ) {
F_3 ( L_4
L_5 , V_31 , V_33 ) ;
return V_31 ;
}
memset ( & V_24 , 0 , sizeof V_24 ) ;
V_24 . V_34 = V_35 | V_36 ;
F_7 ( V_24 . V_37 , V_25 , sizeof V_24 . V_37 ) ;
if ( ( V_29 = F_8 ( V_31 , V_38 , ( void * ) & V_24 ) ) < 0 ) {
F_3 ( L_6
L_5 , V_29 , V_33 ) ;
F_9 ( V_31 ) ;
return V_29 ;
}
V_22 -> V_26 . V_27 . V_28 . V_31 = V_31 ;
return V_29 ;
}
static void F_10 ( struct V_21 * V_22 )
{
#if 0
if (lp->tp.info.tuntap.fixed_config)
iter_addresses(lp->tp.info.tuntap.dev, close_addr, lp->host.dev_name);
#endif
F_9 ( V_22 -> V_26 . V_27 . V_28 . V_31 ) ;
V_22 -> V_26 . V_27 . V_28 . V_31 = - 1 ;
}
static int F_11 ( struct V_21 * V_22 , struct V_39 * * V_40 )
{
#if 0
*skb = ether_adjust_skb(*skb, ETH_HEADER_OTHER);
if (*skb == NULL)
return -ENOMEM;
#endif
return F_12 ( V_22 -> V_26 . V_27 . V_28 . V_31 ,
( * V_40 ) -> V_41 , ( * V_40 ) -> V_9 -> V_42 + V_43 ) ;
}
static int F_13 ( struct V_21 * V_22 , struct V_39 * * V_40 )
{
return F_14 ( V_22 -> V_26 . V_27 . V_28 . V_31 , ( * V_40 ) -> V_41 , ( * V_40 ) -> V_44 ) ;
}
unsigned short F_15 ( struct V_39 * V_40 )
{
return F_16 ( V_40 , V_40 -> V_9 ) ;
}
static int F_17 ( struct V_21 * V_22 )
{
return F_18 ( V_22 -> V_26 . V_27 . V_28 . V_31 ) ;
}
static int F_19 ( struct V_21 * V_22 , int V_45 , char * V_46 )
{
const int V_44 = strlen ( V_47 ) ;
char * V_25 = NULL , * V_48 = NULL , * V_49 = NULL ;
if ( strncmp ( V_46 , V_47 , V_44 ) )
return 0 ;
if ( * ( V_46 += strlen ( V_47 ) ) == ',' ) {
if ( ( V_49 = F_1 ( V_46 + 1 , & V_48 , & V_25 ) ) != NULL ) {
F_3 ( L_7 , V_49 ) ;
return 0 ;
}
} else if ( * V_46 != '\0' ) {
F_3 ( L_8 , V_46 ) ;
return 0 ;
}
if ( V_25 ) {
strncpy ( V_22 -> V_26 . V_27 . V_28 . V_25 , V_25 ,
sizeof V_22 -> V_26 . V_27 . V_28 . V_25 ) ;
V_22 -> V_26 . V_27 . V_28 . V_32 = 1 ;
} else
strcpy ( V_22 -> V_26 . V_27 . V_28 . V_25 , V_47 ) ;
#if 0
if (setup_etheraddr(mac_str, lp->mac))
lp->have_mac = 1;
#endif
V_22 -> V_42 = V_50 ;
V_22 -> V_26 . V_27 . V_28 . V_31 = - 1 ;
V_22 -> V_26 . V_51 = F_5 ;
V_22 -> V_26 . V_52 = F_10 ;
V_22 -> V_26 . V_53 = F_11 ;
V_22 -> V_26 . V_54 = F_13 ;
V_22 -> V_26 . V_55 = F_15 ;
V_22 -> V_26 . V_56 = F_17 ;
F_3 ( L_9 ) ;
#if 0
if (lp->host.gate_addr != NULL)
printk("IP = %s", lp->host.gate_addr);
#endif
F_3 ( L_10 ) ;
return 1 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_21 * V_22 = F_21 ( V_9 ) ;
int V_57 ;
struct V_39 * V_40 ;
if ( V_22 -> V_26 . V_56 ( V_22 ) == 0 )
return 0 ;
if ( ( V_40 = F_22 ( V_9 -> V_42 + 2 + V_43 ) ) == NULL ) {
V_22 -> V_58 . V_59 ++ ;
return 0 ;
}
F_23 ( V_40 , 2 ) ;
V_40 -> V_9 = V_9 ;
F_24 ( V_40 ) ;
V_57 = V_22 -> V_26 . V_53 ( V_22 , & V_40 ) ;
F_25 ( V_40 , V_57 ) ;
if ( V_57 > 0 ) {
F_26 ( V_40 , V_57 ) ;
V_40 -> V_55 = V_22 -> V_26 . V_55 ( V_40 ) ;
V_22 -> V_58 . V_60 += V_40 -> V_44 ;
V_22 -> V_58 . V_61 ++ ;
F_27 ( V_40 ) ;
return V_57 ;
}
F_28 ( V_40 ) ;
return V_57 ;
}
static int F_29 ( void )
{
struct V_62 * V_63 ;
int V_29 , V_64 = 0 ;
F_30 ( & V_65 ) ;
F_31 (ele, &opened) {
struct V_21 * V_22 ;
V_22 = F_32 ( V_63 , struct V_21 , V_66 ) ;
if ( ! F_33 ( V_22 -> V_9 ) )
break;
F_30 ( & V_22 -> V_67 ) ;
while ( ( V_29 = F_20 ( V_22 -> V_9 ) ) > 0 )
V_64 ++ ;
F_34 ( & V_22 -> V_67 ) ;
if ( V_29 < 0 ) {
F_3 ( V_68 L_11
L_12 , V_22 -> V_9 -> V_69 , V_29 ) ;
F_35 ( V_22 -> V_9 ) ;
} else {
}
}
F_34 ( & V_65 ) ;
return V_64 ;
}
static void F_36 ( unsigned long V_70 )
{
struct V_21 * V_22 = (struct V_21 * ) V_70 ;
F_30 ( & V_22 -> V_67 ) ;
F_29 () ;
F_37 ( & V_22 -> V_71 , V_72 + V_22 -> V_73 ) ;
F_34 ( & V_22 -> V_67 ) ;
}
static int F_38 ( struct V_8 * V_9 )
{
struct V_21 * V_22 = F_21 ( V_9 ) ;
char V_15 [ sizeof "255.255.255.255\0"];
int V_29 ;
F_30 ( & V_22 -> V_67 ) ;
if ( ( V_29 = V_22 -> V_26 . V_51 ( V_22 ) ) < 0 )
goto V_74;
if ( ! V_22 -> V_75 ) {
F_2 ( V_9 , V_15 , & V_22 -> V_76 [ 2 ] ) ;
F_4 ( V_9 , V_22 -> V_76 ) ;
}
F_39 ( V_9 ) ;
while ( ( V_29 = F_20 ( V_9 ) ) > 0 )
;
F_30 ( & V_65 ) ;
F_40 ( & V_22 -> V_66 , & V_77 ) ;
F_34 ( & V_65 ) ;
F_41 ( & V_22 -> V_71 ) ;
V_22 -> V_73 = V_78 ;
V_22 -> V_71 . V_41 = ( unsigned long ) V_22 ;
V_22 -> V_71 . V_79 = F_36 ;
F_37 ( & V_22 -> V_71 , V_72 + V_22 -> V_73 ) ;
V_74:
F_34 ( & V_22 -> V_67 ) ;
return V_29 ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_21 * V_22 = F_21 ( V_9 ) ;
F_3 ( L_13 ) ;
F_43 ( V_9 ) ;
F_30 ( & V_22 -> V_67 ) ;
F_30 ( & V_65 ) ;
F_44 ( & V_77 ) ;
F_34 ( & V_65 ) ;
F_45 ( & V_22 -> V_71 ) ;
V_22 -> V_26 . V_52 ( V_22 ) ;
F_34 ( & V_22 -> V_67 ) ;
return 0 ;
}
static int F_46 ( struct V_39 * V_40 , struct V_8 * V_9 )
{
struct V_21 * V_22 = F_21 ( V_9 ) ;
unsigned long V_80 ;
int V_44 ;
F_43 ( V_9 ) ;
F_47 ( & V_22 -> V_67 , V_80 ) ;
V_44 = V_22 -> V_26 . V_54 ( V_22 , & V_40 ) ;
if ( V_44 == V_40 -> V_44 ) {
V_22 -> V_58 . V_81 ++ ;
V_22 -> V_58 . V_82 += V_40 -> V_44 ;
V_9 -> V_83 = V_72 ;
F_39 ( V_9 ) ;
F_48 ( V_9 ) ;
} else if ( V_44 == 0 ) {
F_39 ( V_9 ) ;
V_22 -> V_58 . V_84 ++ ;
} else {
F_39 ( V_9 ) ;
F_3 ( V_68 L_14 , V_44 ) ;
}
F_49 ( & V_22 -> V_67 , V_80 ) ;
F_50 ( V_40 ) ;
return V_85 ;
}
static struct V_86 * F_51 ( struct V_8 * V_9 )
{
struct V_21 * V_22 = F_21 ( V_9 ) ;
return & V_22 -> V_58 ;
}
static void F_52 ( struct V_8 * V_9 )
{
#if 0
if (dev->flags & IFF_PROMISC)
return;
else if (!netdev_mc_empty(dev))
dev->flags |= IFF_ALLMULTI;
else
dev->flags &= ~IFF_ALLMULTI;
#endif
}
static void F_53 ( struct V_8 * V_9 )
{
#if 0
dev->trans_start = jiffies;
netif_wake_queue(dev);
#endif
}
static int F_54 ( struct V_8 * V_9 , void * V_15 )
{
#if 0
struct iss_net_private *lp = netdev_priv(dev);
struct sockaddr *hwaddr = addr;
spin_lock(&lp->lock);
memcpy(dev->dev_addr, hwaddr->sa_data, ETH_ALEN);
spin_unlock(&lp->lock);
#endif
return 0 ;
}
static int F_55 ( struct V_8 * V_9 , int V_87 )
{
#if 0
struct iss_net_private *lp = netdev_priv(dev);
int err = 0;
spin_lock(&lp->lock);
if (new_mtu < 0)
err = new_mtu;
else
dev->mtu = new_mtu;
spin_unlock(&lp->lock);
return err;
#endif
return - V_30 ;
}
void F_56 ( unsigned long V_88 )
{
}
static int F_57 ( int V_45 , char * V_46 )
{
struct V_8 * V_9 ;
struct V_21 * V_22 ;
int V_29 ;
if ( ( V_9 = F_58 ( sizeof *V_22 ) ) == NULL ) {
F_3 ( V_68 L_15 ) ;
return 1 ;
}
V_22 = F_21 ( V_9 ) ;
* V_22 = ( (struct V_21 ) {
. V_89 = F_59 ( V_22 -> V_89 ) ,
. V_66 = F_59 ( V_22 -> V_66 ) ,
. V_67 = F_60 ( V_22 . V_67 ) ,
. V_9 = V_9 ,
. V_45 = V_45 ,
. V_76 = { 0xfe , 0xfd , 0x0 , 0x0 , 0x0 , 0x0 } ,
. V_75 = 0 ,
} ) ;
if ( ! F_19 ( V_22 , V_45 , V_46 ) ) {
F_3 ( L_16 ) ;
goto V_90;
}
F_3 ( V_91 L_17 , V_45 ) ;
if ( V_22 -> V_75 )
F_3 ( L_18 , V_22 -> V_76 ) ;
F_3 ( L_19 ) ;
if ( ! V_92 ) {
F_61 ( & V_93 ) ;
V_92 = 1 ;
}
F_30 ( & V_94 ) ;
F_40 ( & V_22 -> V_89 , & V_95 ) ;
F_34 ( & V_94 ) ;
V_22 -> V_96 . V_97 = V_45 ;
V_22 -> V_96 . V_69 = V_98 ;
F_62 ( & V_22 -> V_96 ) ;
F_63 ( V_9 , & V_22 -> V_96 . V_9 ) ;
snprintf ( V_9 -> V_69 , sizeof V_9 -> V_69 , L_20 , V_45 ) ;
V_9 -> V_99 = & V_100 ;
V_9 -> V_42 = V_22 -> V_42 ;
V_9 -> V_101 = ( V_102 >> 1 ) ;
V_9 -> V_103 = - 1 ;
F_64 () ;
V_29 = F_65 ( V_9 ) ;
F_66 () ;
if ( V_29 ) {
F_3 ( L_21 ) ;
F_67 ( V_9 ) ;
return 1 ;
}
F_41 ( & V_22 -> V_104 ) ;
V_22 -> V_104 . V_79 = F_56 ;
#if 0
if (lp->have_mac)
set_ether_mac(dev, lp->mac);
#endif
return 0 ;
V_90:
return - V_105 ;
}
static int T_3 F_68 ( char * V_1 )
{
struct V_21 * V_106 = NULL ;
struct V_107 * V_108 ;
struct V_62 * V_63 ;
char * V_3 ;
int V_109 ;
V_109 = F_69 ( V_1 , & V_3 , 0 ) ;
if ( V_3 == V_1 ) {
F_3 ( V_110 L_22 , V_1 ) ;
return 1 ;
}
if ( V_109 < 0 ) {
F_3 ( V_110 L_23 , V_109 ) ;
return 1 ;
}
if ( * ( V_1 = V_3 ) != '=' ) {
F_3 ( V_110 L_24 ) ;
return 1 ;
}
F_30 ( & V_94 ) ;
F_31 (ele, &devices) {
V_106 = F_32 ( V_63 , struct V_21 , V_89 ) ;
if ( V_106 -> V_45 == V_109 )
break;
}
F_34 ( & V_94 ) ;
if ( V_106 && V_106 -> V_45 == V_109 ) {
F_3 ( V_110 L_25 , V_109 ) ;
return 1 ;
}
if ( ( V_108 = F_70 ( sizeof V_108 ) ) == NULL ) {
F_3 ( L_26 ) ;
return 1 ;
}
F_71 ( & V_108 -> V_111 ) ;
V_108 -> V_45 = V_109 ;
V_108 -> V_46 = V_1 + 1 ;
F_72 ( & V_108 -> V_111 , & V_112 ) ;
return 1 ;
}
static int V_107 ( void )
{
struct V_62 * V_63 , * V_113 ;
F_73 (ele, next, &eth_cmd_line) {
struct V_107 * V_114 ;
V_114 = F_32 ( V_63 , struct V_107 , V_111 ) ;
F_57 ( V_114 -> V_45 , V_114 -> V_46 ) ;
}
return 1 ;
}
