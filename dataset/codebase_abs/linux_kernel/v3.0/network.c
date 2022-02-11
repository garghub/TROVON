static int F_1 ( int V_1 , int V_2 , int V_3 , int V_4 , int V_5 , int V_6 )
{
int V_7 ;
__asm__ __volatile__ ("simcall\n"
"mov %0, a2\n"
"mov %1, a3\n" : "=a" (ret), "=a" (errno)
: : "a2", "a3");
return V_7 ;
}
static int inline F_2 ( char * V_8 , int V_9 , int V_10 )
{
return F_1 ( V_11 , ( int ) V_8 , V_9 , V_10 , 0 , 0 ) ;
}
static int inline F_3 ( int V_12 )
{
return F_1 ( V_13 , V_12 , 0 , 0 , 0 , 0 ) ;
}
static int inline F_4 ( int V_12 , int V_14 , void * V_15 )
{
return F_1 ( V_16 , V_12 , V_14 , ( int ) V_15 , 0 , 0 ) ;
}
static int inline F_5 ( int V_12 , void * V_17 , T_1 V_18 )
{
return F_1 ( V_19 , V_12 , ( int ) V_17 , V_18 , 0 , 0 ) ;
}
static int inline F_6 ( int V_12 , void * V_17 , T_1 V_18 )
{
return F_1 ( V_20 , V_12 , ( int ) V_17 , V_18 , 0 , 0 ) ;
}
static int inline F_7 ( int V_12 )
{
struct V_21 V_22 = { . V_23 = 0 , . V_24 = 0 } ;
return F_1 ( V_25 , V_12 , V_26 , ( int ) & V_22 , 0 , 0 ) ;
}
static char * F_8 ( char * V_27 , ... )
{
char * * V_15 , * V_28 ;
T_2 V_29 ;
va_start ( V_29 , V_27 ) ;
while ( ( V_15 = va_arg ( V_29 , char * * ) ) != NULL ) {
if ( * V_27 == '\0' )
return NULL ;
V_28 = strchr ( V_27 , ',' ) ;
if ( V_28 != V_27 )
* V_15 = V_27 ;
if ( V_28 == NULL )
return NULL ;
* V_28 ++ = '\0' ;
V_27 = V_28 ;
}
va_end ( V_29 ) ;
return V_27 ;
}
static void F_9 ( void * V_4 , char * V_17 , char * V_30 )
{
struct V_31 * V_32 = V_4 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_36 * V_37 ;
T_3 V_38 ;
if ( ( V_34 == NULL ) || ( ( V_37 = V_34 -> V_39 ) == NULL ) ) {
F_10 ( V_40 L_1 ) ;
return;
}
V_38 = V_37 -> V_41 ;
sprintf ( V_17 , L_2 , V_38 & 0xff , ( V_38 >> 8 ) & 0xff ,
( V_38 >> 16 ) & 0xff , V_38 >> 24 ) ;
if ( V_30 ) {
V_30 [ 0 ] = V_38 & 0xff ;
V_30 [ 1 ] = ( V_38 >> 8 ) & 0xff ;
V_30 [ 2 ] = ( V_38 >> 16 ) & 0xff ;
V_30 [ 3 ] = V_38 >> 24 ;
}
}
static void inline F_11 ( void * V_4 , unsigned char * V_38 )
{
struct V_31 * V_32 = V_4 ;
memcpy ( V_32 -> V_42 , V_38 , V_43 ) ;
}
static int F_12 ( struct V_44 * V_45 )
{
struct V_46 V_47 ;
char * V_48 = V_45 -> V_49 . V_50 . V_51 . V_48 ;
int V_52 = - V_53 ;
int V_12 ;
if ( ! V_45 -> V_49 . V_50 . V_51 . V_54 )
return - V_53 ;
if ( ( V_12 = F_2 ( L_3 , 02 , 0 ) ) < 0 ) {
F_10 ( L_4
L_5 , V_12 , V_55 ) ;
return V_12 ;
}
memset ( & V_47 , 0 , sizeof V_47 ) ;
V_47 . V_56 = V_57 | V_58 ;
F_13 ( V_47 . V_59 , V_48 , sizeof V_47 . V_59 ) ;
if ( ( V_52 = F_4 ( V_12 , V_60 , ( void * ) & V_47 ) ) < 0 ) {
F_10 ( L_6
L_5 , V_52 , V_55 ) ;
F_3 ( V_12 ) ;
return V_52 ;
}
V_45 -> V_49 . V_50 . V_51 . V_12 = V_12 ;
return V_52 ;
}
static void F_14 ( struct V_44 * V_45 )
{
#if 0
if (lp->tp.info.tuntap.fixed_config)
iter_addresses(lp->tp.info.tuntap.dev, close_addr, lp->host.dev_name);
#endif
F_3 ( V_45 -> V_49 . V_50 . V_51 . V_12 ) ;
V_45 -> V_49 . V_50 . V_51 . V_12 = - 1 ;
}
static int F_15 ( struct V_44 * V_45 , struct V_61 * * V_62 )
{
#if 0
*skb = ether_adjust_skb(*skb, ETH_HEADER_OTHER);
if (*skb == NULL)
return -ENOMEM;
#endif
return F_5 ( V_45 -> V_49 . V_50 . V_51 . V_12 ,
( * V_62 ) -> V_63 , ( * V_62 ) -> V_32 -> V_64 + V_65 ) ;
}
static int F_16 ( struct V_44 * V_45 , struct V_61 * * V_62 )
{
return F_6 ( V_45 -> V_49 . V_50 . V_51 . V_12 , ( * V_62 ) -> V_63 , ( * V_62 ) -> V_66 ) ;
}
unsigned short F_17 ( struct V_61 * V_62 )
{
return F_18 ( V_62 , V_62 -> V_32 ) ;
}
static int F_19 ( struct V_44 * V_45 )
{
return F_7 ( V_45 -> V_49 . V_50 . V_51 . V_12 ) ;
}
static int F_20 ( struct V_44 * V_45 , int V_67 , char * V_68 )
{
const int V_66 = strlen ( V_69 ) ;
char * V_48 = NULL , * V_70 = NULL , * V_71 = NULL ;
if ( strncmp ( V_68 , V_69 , V_66 ) )
return 0 ;
if ( * ( V_68 += strlen ( V_69 ) ) == ',' ) {
if ( ( V_71 = F_8 ( V_68 + 1 , & V_70 , & V_48 ) ) != NULL ) {
F_10 ( L_7 , V_71 ) ;
return 0 ;
}
} else if ( * V_68 != '\0' ) {
F_10 ( L_8 , V_68 ) ;
return 0 ;
}
if ( V_48 ) {
strncpy ( V_45 -> V_49 . V_50 . V_51 . V_48 , V_48 ,
sizeof V_45 -> V_49 . V_50 . V_51 . V_48 ) ;
V_45 -> V_49 . V_50 . V_51 . V_54 = 1 ;
} else
strcpy ( V_45 -> V_49 . V_50 . V_51 . V_48 , V_69 ) ;
#if 0
if (setup_etheraddr(mac_str, lp->mac))
lp->have_mac = 1;
#endif
V_45 -> V_64 = V_72 ;
V_45 -> V_49 . V_50 . V_51 . V_12 = - 1 ;
V_45 -> V_49 . V_73 = F_12 ;
V_45 -> V_49 . V_74 = F_14 ;
V_45 -> V_49 . V_75 = F_15 ;
V_45 -> V_49 . V_76 = F_16 ;
V_45 -> V_49 . V_77 = F_17 ;
V_45 -> V_49 . V_78 = F_19 ;
F_10 ( L_9 ) ;
#if 0
if (lp->host.gate_addr != NULL)
printk("IP = %s", lp->host.gate_addr);
#endif
F_10 ( L_10 ) ;
return 1 ;
}
static int F_21 ( struct V_31 * V_32 )
{
struct V_44 * V_45 = F_22 ( V_32 ) ;
int V_79 ;
struct V_61 * V_62 ;
if ( V_45 -> V_49 . V_78 ( V_45 ) == 0 )
return 0 ;
if ( ( V_62 = F_23 ( V_32 -> V_64 + 2 + V_65 ) ) == NULL ) {
V_45 -> V_80 . V_81 ++ ;
return 0 ;
}
F_24 ( V_62 , 2 ) ;
V_62 -> V_32 = V_32 ;
F_25 ( V_62 ) ;
V_79 = V_45 -> V_49 . V_75 ( V_45 , & V_62 ) ;
F_26 ( V_62 , V_79 ) ;
if ( V_79 > 0 ) {
F_27 ( V_62 , V_79 ) ;
V_62 -> V_77 = V_45 -> V_49 . V_77 ( V_62 ) ;
V_45 -> V_80 . V_82 += V_62 -> V_66 ;
V_45 -> V_80 . V_83 ++ ;
F_28 ( V_62 ) ;
return V_79 ;
}
F_29 ( V_62 ) ;
return V_79 ;
}
static int F_30 ( void )
{
struct V_84 * V_85 ;
int V_52 , V_7 = 0 ;
F_31 ( & V_86 ) ;
F_32 (ele, &opened) {
struct V_44 * V_45 ;
V_45 = F_33 ( V_85 , struct V_44 , V_87 ) ;
if ( ! F_34 ( V_45 -> V_32 ) )
break;
F_31 ( & V_45 -> V_88 ) ;
while ( ( V_52 = F_21 ( V_45 -> V_32 ) ) > 0 )
V_7 ++ ;
F_35 ( & V_45 -> V_88 ) ;
if ( V_52 < 0 ) {
F_10 ( V_89 L_11
L_12 , V_45 -> V_32 -> V_90 , V_52 ) ;
F_36 ( V_45 -> V_32 ) ;
} else {
}
}
F_35 ( & V_86 ) ;
return V_7 ;
}
static void F_37 ( unsigned long V_91 )
{
struct V_44 * V_45 = (struct V_44 * ) V_91 ;
F_31 ( & V_45 -> V_88 ) ;
F_30 () ;
F_38 ( & V_45 -> V_92 , V_93 + V_45 -> V_94 ) ;
F_35 ( & V_45 -> V_88 ) ;
}
static int F_39 ( struct V_31 * V_32 )
{
struct V_44 * V_45 = F_22 ( V_32 ) ;
char V_38 [ sizeof "255.255.255.255\0"];
int V_52 ;
F_31 ( & V_45 -> V_88 ) ;
if ( ( V_52 = V_45 -> V_49 . V_73 ( V_45 ) ) < 0 )
goto V_95;
if ( ! V_45 -> V_96 ) {
F_9 ( V_32 , V_38 , & V_45 -> V_97 [ 2 ] ) ;
F_11 ( V_32 , V_45 -> V_97 ) ;
}
F_40 ( V_32 ) ;
while ( ( V_52 = F_21 ( V_32 ) ) > 0 )
;
F_31 ( & V_86 ) ;
F_41 ( & V_45 -> V_87 , & V_98 ) ;
F_35 ( & V_86 ) ;
F_42 ( & V_45 -> V_92 ) ;
V_45 -> V_94 = V_99 ;
V_45 -> V_92 . V_63 = ( unsigned long ) V_45 ;
V_45 -> V_92 . V_100 = F_37 ;
F_38 ( & V_45 -> V_92 , V_93 + V_45 -> V_94 ) ;
V_95:
F_35 ( & V_45 -> V_88 ) ;
return V_52 ;
}
static int F_43 ( struct V_31 * V_32 )
{
struct V_44 * V_45 = F_22 ( V_32 ) ;
F_10 ( L_13 ) ;
F_44 ( V_32 ) ;
F_31 ( & V_45 -> V_88 ) ;
F_31 ( & V_86 ) ;
F_45 ( & V_98 ) ;
F_35 ( & V_86 ) ;
F_46 ( & V_45 -> V_92 ) ;
V_45 -> V_49 . V_74 ( V_45 ) ;
F_35 ( & V_45 -> V_88 ) ;
return 0 ;
}
static int F_47 ( struct V_61 * V_62 , struct V_31 * V_32 )
{
struct V_44 * V_45 = F_22 ( V_32 ) ;
unsigned long V_9 ;
int V_66 ;
F_44 ( V_32 ) ;
F_48 ( & V_45 -> V_88 , V_9 ) ;
V_66 = V_45 -> V_49 . V_76 ( V_45 , & V_62 ) ;
if ( V_66 == V_62 -> V_66 ) {
V_45 -> V_80 . V_101 ++ ;
V_45 -> V_80 . V_102 += V_62 -> V_66 ;
V_32 -> V_103 = V_93 ;
F_40 ( V_32 ) ;
F_49 ( V_32 ) ;
} else if ( V_66 == 0 ) {
F_40 ( V_32 ) ;
V_45 -> V_80 . V_104 ++ ;
} else {
F_40 ( V_32 ) ;
F_10 ( V_89 L_14 , V_66 ) ;
}
F_50 ( & V_45 -> V_88 , V_9 ) ;
F_51 ( V_62 ) ;
return V_105 ;
}
static struct V_106 * F_52 ( struct V_31 * V_32 )
{
struct V_44 * V_45 = F_22 ( V_32 ) ;
return & V_45 -> V_80 ;
}
static void F_53 ( struct V_31 * V_32 )
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
static void F_54 ( struct V_31 * V_32 )
{
#if 0
dev->trans_start = jiffies;
netif_wake_queue(dev);
#endif
}
static int F_55 ( struct V_31 * V_32 , void * V_38 )
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
static int F_56 ( struct V_31 * V_32 , int V_107 )
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
return - V_53 ;
}
void F_57 ( unsigned long V_108 )
{
}
static int F_58 ( int V_67 , char * V_68 )
{
struct V_31 * V_32 ;
struct V_44 * V_45 ;
int V_52 ;
if ( ( V_32 = F_59 ( sizeof *V_45 ) ) == NULL ) {
F_10 ( V_89 L_15 ) ;
return 1 ;
}
V_45 = F_22 ( V_32 ) ;
* V_45 = ( (struct V_44 ) {
. V_109 = F_60 ( V_45 -> V_109 ) ,
. V_87 = F_60 ( V_45 -> V_87 ) ,
. V_88 = F_61 ( V_45 . V_88 ) ,
. V_32 = V_32 ,
. V_67 = V_67 ,
. V_97 = { 0xfe , 0xfd , 0x0 , 0x0 , 0x0 , 0x0 } ,
. V_96 = 0 ,
} ) ;
if ( ! F_20 ( V_45 , V_67 , V_68 ) ) {
F_10 ( L_16 ) ;
goto V_110;
}
F_10 ( V_111 L_17 , V_67 ) ;
if ( V_45 -> V_96 )
F_10 ( L_18 , V_45 -> V_97 ) ;
F_10 ( L_19 ) ;
if ( ! V_112 ) {
F_62 ( & V_113 ) ;
V_112 = 1 ;
}
F_31 ( & V_114 ) ;
F_41 ( & V_45 -> V_109 , & V_115 ) ;
F_35 ( & V_114 ) ;
V_45 -> V_116 . V_117 = V_67 ;
V_45 -> V_116 . V_90 = V_118 ;
F_63 ( & V_45 -> V_116 ) ;
F_64 ( V_32 , & V_45 -> V_116 . V_32 ) ;
snprintf ( V_32 -> V_90 , sizeof V_32 -> V_90 , L_20 , V_67 ) ;
V_32 -> V_119 = & V_120 ;
V_32 -> V_64 = V_45 -> V_64 ;
V_32 -> V_121 = ( V_122 >> 1 ) ;
V_32 -> V_123 = - 1 ;
F_65 () ;
V_52 = F_66 ( V_32 ) ;
F_67 () ;
if ( V_52 ) {
F_10 ( L_21 ) ;
F_68 ( V_32 ) ;
return 1 ;
}
F_42 ( & V_45 -> V_124 ) ;
V_45 -> V_124 . V_100 = F_57 ;
#if 0
if (lp->have_mac)
set_ether_mac(dev, lp->mac);
#endif
return 0 ;
V_110:
return - V_125 ;
}
static int F_69 ( char * V_27 )
{
struct V_44 * V_126 = NULL ;
struct V_127 * V_128 ;
struct V_84 * V_85 ;
char * V_28 ;
int V_129 ;
V_129 = F_70 ( V_27 , & V_28 , 0 ) ;
if ( V_28 == V_27 ) {
F_10 ( V_130 L_22 , V_27 ) ;
return 1 ;
}
if ( V_129 < 0 ) {
F_10 ( V_130 L_23 , V_129 ) ;
return 1 ;
}
if ( * ( V_27 = V_28 ) != '=' ) {
F_10 ( V_130 L_24 ) ;
return 1 ;
}
F_31 ( & V_114 ) ;
F_32 (ele, &devices) {
V_126 = F_33 ( V_85 , struct V_44 , V_109 ) ;
if ( V_126 -> V_67 == V_129 )
break;
}
F_35 ( & V_114 ) ;
if ( V_126 && V_126 -> V_67 == V_129 ) {
F_10 ( V_130 L_25 , V_129 ) ;
return 1 ;
}
if ( ( V_128 = F_71 ( sizeof V_128 ) ) == NULL ) {
F_10 ( L_26 ) ;
return 1 ;
}
F_72 ( & V_128 -> V_131 ) ;
V_128 -> V_67 = V_129 ;
V_128 -> V_68 = V_27 + 1 ;
F_73 ( & V_128 -> V_131 , & V_132 ) ;
return 1 ;
}
static int V_127 ( void )
{
struct V_84 * V_85 , * V_133 ;
F_74 (ele, next, &eth_cmd_line) {
struct V_127 * V_134 ;
V_134 = F_33 ( V_85 , struct V_127 , V_131 ) ;
F_58 ( V_134 -> V_67 , V_134 -> V_68 ) ;
}
return 1 ;
}
