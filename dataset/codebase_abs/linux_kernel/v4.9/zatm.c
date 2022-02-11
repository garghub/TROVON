static void F_1 ( void )
{
}
static void F_2 ( const char * V_1 , unsigned long V_2 , unsigned long V_3 )
{
V_4 [ V_5 ] = V_1 ;
V_6 [ V_5 ] = V_2 ;
V_7 [ V_5 ] = V_3 ;
V_5 = ( V_5 + 1 ) % V_8 ;
}
static void F_1 ( void )
{
int V_9 , V_10 ;
F_3 ( V_11 L_1 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
V_10 = ( V_5 + V_9 ) % V_8 ;
F_3 ( V_11 ) ;
F_3 ( V_4 [ V_10 ] ? V_4 [ V_10 ] : L_2 , V_6 [ V_10 ] , V_7 [ V_10 ] ) ;
}
F_3 ( V_11 L_3 ) ;
}
static void F_4 ( struct V_12 * V_12 , T_1 V_13 , T_1 V_14 )
{
V_15 ;
F_5 ( V_13 , V_16 ) ;
F_5 ( V_17 | V_18 |
( V_19 << V_20 ) | V_14 , V_21 ) ;
}
static T_1 F_6 ( struct V_12 * V_12 , T_1 V_14 )
{
V_15 ;
F_5 ( V_17 | V_18 | V_22 |
( V_19 << V_20 ) | V_14 , V_21 ) ;
V_15 ;
return F_7 ( V_16 ) ;
}
static void F_8 ( struct V_23 * V_24 , int V_25 )
{
struct V_12 * V_12 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
unsigned long V_30 ;
int V_31 , V_32 , free , V_33 , V_34 ;
F_2 ( L_4 , 0 , 0 ) ;
V_12 = F_9 ( V_24 ) ;
V_34 = ( 64 << ( V_25 <= V_35 ? 0 :
V_25 - V_35 ) ) + sizeof( struct V_28 ) ;
if ( V_34 < V_36 ) {
V_31 = 32 ;
V_32 = sizeof( struct V_28 ) ;
}
else {
V_31 = 4096 ;
V_32 = V_12 -> V_37 [ V_25 ] . V_32 +
sizeof( struct V_28 ) ;
}
V_34 += V_31 ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
free = F_6 ( V_12 , V_12 -> V_39 + 2 * V_25 ) &
V_40 ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
if ( free >= V_12 -> V_37 [ V_25 ] . V_41 ) return;
F_2 ( L_5 ,
F_6 ( V_12 , V_12 -> V_39 + 2 * V_25 ) ,
F_6 ( V_12 , V_12 -> V_39 + 2 * V_25 + 1 ) ) ;
F_2 ( L_6 , V_42 [ 0 ] , V_42 [ 1 ] ) ;
V_33 = 0 ;
V_29 = NULL ;
while ( free < V_12 -> V_37 [ V_25 ] . V_43 ) {
struct V_28 * V_44 ;
V_27 = F_12 ( V_34 , V_45 ) ;
if ( ! V_27 ) {
F_3 (KERN_WARNING DEV_LABEL L_7
L_8 ,dev->number,size,free) ;
break;
}
F_13 ( V_27 , ( unsigned char * ) ( ( ( ( unsigned long ) V_27 -> V_46 +
V_31 + V_32 - 1 ) & ~ ( unsigned long ) ( V_31 - 1 ) ) - V_32 ) -
V_27 -> V_46 ) ;
V_44 = (struct V_28 * ) V_27 -> V_46 ;
F_13 ( V_27 , sizeof( struct V_28 ) ) ;
if ( ! V_29 ) V_29 = V_44 ;
V_33 ++ ;
V_44 -> V_47 = F_14 ( V_27 -> V_46 ) ;
V_44 -> V_48 = 0 ;
V_44 -> V_27 = V_27 ;
F_2 ( L_9 , ( unsigned long ) V_27 ,
( unsigned long ) V_44 ) ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
if ( V_12 -> V_49 [ V_25 ] )
( (struct V_28 * ) ( V_12 -> V_49 [ V_25 ] ->
V_46 ) ) [ - 1 ] . V_48 = F_14 ( V_44 ) ;
V_12 -> V_49 [ V_25 ] = V_27 ;
F_15 ( & V_12 -> V_25 [ V_25 ] , V_27 ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
free ++ ;
}
if ( V_29 ) {
F_10 ( & V_12 -> V_38 , V_30 ) ;
V_15 ;
F_5 ( F_14 ( V_29 ) , V_16 ) ;
F_5 ( V_50 | ( V_25 << V_51 ) | V_33 ,
V_21 ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
F_2 ( L_10 ,
F_6 ( V_12 , V_12 -> V_39 + 2 * V_25 ) ,
F_6 ( V_12 , V_12 -> V_39 + 2 * V_25 + 1 ) ) ;
F_2 ( L_6 , V_42 [ 0 ] , V_42 [ 1 ] ) ;
}
}
static void F_16 ( struct V_23 * V_24 , int V_25 )
{
F_17 ( & F_9 ( V_24 ) -> V_25 [ V_25 ] ) ;
}
static int F_18 ( int V_52 )
{
int V_10 ;
if ( V_52 % V_53 )
F_3 (KERN_ERR DEV_LABEL L_11
L_12 ,max_pdu) ;
if ( V_52 > 65536 ) return - 1 ;
for ( V_10 = 0 ; ( 64 << V_10 ) < V_52 ; V_10 ++ ) ;
return V_10 + V_35 ;
}
static void F_19 ( struct V_23 * V_24 , int V_25 )
{
struct V_12 * V_12 ;
unsigned long V_30 ;
int V_34 ;
V_12 = F_9 ( V_24 ) ;
if ( ! ( V_12 -> V_37 [ V_25 ] . V_54 ++ ) ) {
F_20 ( & V_12 -> V_25 [ V_25 ] ) ;
V_34 = V_25 - V_35 ;
if ( V_34 < 0 ) V_34 = 0 ;
else if ( V_34 > 10 ) V_34 = 10 ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
F_4 ( V_12 , ( ( V_12 -> V_37 [ V_25 ] . V_41 / 4 ) <<
V_55 ) |
( 1 << V_56 ) |
( V_34 << V_57 ) ,
V_12 -> V_39 + V_25 * 2 ) ;
F_4 ( V_12 , ( unsigned long ) V_42 , V_12 -> V_39 +
V_25 * 2 + 1 ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
V_12 -> V_49 [ V_25 ] = NULL ;
F_8 ( V_24 , V_25 ) ;
}
F_21 ( L_13 , V_25 , V_12 -> V_37 [ V_25 ] . V_54 ) ;
}
static void F_22 ( struct V_23 * V_24 , int V_25 )
{
if ( ! ( -- F_9 ( V_24 ) -> V_37 [ V_25 ] . V_54 ) )
F_16 ( V_24 , V_25 ) ;
}
static void F_23 ( struct V_23 * V_24 , int V_58 )
{
struct V_12 * V_12 ;
unsigned long V_59 ;
T_1 V_60 ;
int error ;
F_2 ( L_14 , 0 , 0 ) ;
V_12 = F_9 ( V_24 ) ;
V_59 = ( V_12 -> V_61 [ V_58 ] & ~ 0xffffUL ) | F_7 ( F_24 ( V_58 ) ) ;
while ( V_60 = F_7 ( F_25 ( V_58 ) ) , ( V_59 & 0xffff ) != V_60 ) {
T_1 * V_62 ;
struct V_26 * V_27 ;
struct V_63 * V_64 ;
int V_65 , V_34 , V_66 ;
F_2 ( L_15 , V_59 , V_60 ) ;
V_62 = ( T_1 * ) V_59 ;
if ( ( ( V_59 += 16 ) & 0xffff ) == V_12 -> V_67 [ V_58 ] )
V_59 = V_12 -> V_61 [ V_58 ] ;
V_65 = V_62 [ 0 ] & V_68 ;
#if 0
printk("RX IND: 0x%x, 0x%x, 0x%x, 0x%x\n",here[0],here[1],here[2],here[3]);
{
unsigned long *x;
printk("POOL: 0x%08x, 0x%08x\n",zpeekl(zatm_dev,
zatm_dev->pool_base),
zpeekl(zatm_dev,zatm_dev->pool_base+1));
x = (unsigned long *) here[2];
printk("[0..3] = 0x%08lx, 0x%08lx, 0x%08lx, 0x%08lx\n",
x[0],x[1],x[2],x[3]);
}
#endif
error = 0 ;
if ( V_62 [ 3 ] & V_69 ) {
error = ( V_62 [ 3 ] & V_70 ) >>
V_71 ;
if ( error == V_72 ||
error == V_73 ) continue;
}
F_2 ( L_16 , ( V_62 [ 3 ] & V_70 ) >>
V_71 , error ) ;
V_27 = ( (struct V_28 * ) F_26 ( V_62 [ 2 ] ) ) -> V_27 ;
F_27 ( V_27 ) ;
#if 0
printk("[-3..0] 0x%08lx 0x%08lx 0x%08lx 0x%08lx\n",((unsigned *) skb->data)[-3],
((unsigned *) skb->data)[-2],((unsigned *) skb->data)[-1],
((unsigned *) skb->data)[0]);
#endif
F_2 ( L_17 , ( unsigned long ) V_27 ,
( unsigned long ) V_62 ) ;
#if 0
printk("dummy: 0x%08lx, 0x%08lx\n",dummy[0],dummy[1]);
#endif
V_34 = error ? 0 : F_28 ( ( ( V_74 * ) V_27 -> V_46 ) [ V_65 *
V_53 / sizeof( V_75 ) - 3 ] ) ;
F_2 ( L_18 , ( unsigned long ) V_27 , V_34 ) ;
V_66 = ( V_62 [ 3 ] & V_76 ) >>
V_77 ;
if ( V_66 < V_12 -> V_78 && V_12 -> V_79 [ V_66 ] ) {
int V_59 ;
V_64 = V_12 -> V_79 [ V_66 ] ;
V_59 = F_29 ( V_64 ) -> V_25 ;
if ( V_27 == V_12 -> V_49 [ V_59 ] )
V_12 -> V_49 [ V_59 ] = NULL ;
F_30 ( V_27 , V_12 -> V_25 + V_59 ) ;
}
else {
F_3 (KERN_ERR DEV_LABEL L_19
L_20 ,dev->number) ;
V_34 = 0 ;
V_64 = NULL ;
F_1 () ;
}
if ( error ) {
static unsigned long V_80 = 0 ;
static int V_81 = 0 ;
if ( error != V_81 ||
F_31 ( V_82 , V_80 ) || V_80 == 0 ) {
F_3 (KERN_WARNING DEV_LABEL L_21
L_22 ,dev->number,chan,
err_txt[error]) ;
V_81 = error ;
V_80 = ( V_82 + 2 * V_83 ) | 1 ;
}
V_34 = 0 ;
}
if ( V_34 && ( V_34 > V_65 * V_53 - V_84 ||
V_34 <= ( V_65 - 1 ) * V_53 - V_84 ) ) {
F_3 (KERN_ERR DEV_LABEL L_23
L_24 ,dev->number,size,cells) ;
V_34 = 0 ;
F_1 () ;
}
if ( V_34 > V_85 ) {
F_3 (KERN_ERR DEV_LABEL L_25
L_26 ,dev->number,size) ;
V_34 = 0 ;
F_1 () ;
}
if ( ! V_34 ) {
F_32 ( V_27 ) ;
if ( V_64 ) F_33 ( & V_64 -> V_86 -> V_87 ) ;
continue;
}
if ( ! F_34 ( V_64 , V_27 -> V_88 ) ) {
F_32 ( V_27 ) ;
continue;
}
V_27 -> V_89 = V_34 ;
F_35 ( V_27 ) -> V_64 = V_64 ;
V_64 -> V_90 ( V_64 , V_27 ) ;
F_33 ( & V_64 -> V_86 -> V_91 ) ;
}
F_5 ( V_59 & 0xffff , F_24 ( V_58 ) ) ;
#if 0
refill_pool(dev,zatm_vcc->pool);
#endif
}
static int F_36 ( struct V_63 * V_64 )
{
struct V_12 * V_12 ;
struct V_92 * V_92 ;
unsigned long V_30 ;
unsigned short V_66 ;
int V_65 ;
F_21 ( L_27 , F_37 ( 0xc053 ) ) ;
V_12 = F_9 ( V_64 -> V_24 ) ;
V_92 = F_29 ( V_64 ) ;
V_92 -> V_93 = 0 ;
if ( V_64 -> V_94 . V_95 . V_96 == V_97 ) return 0 ;
if ( V_64 -> V_94 . V_98 == V_99 ) {
if ( V_64 -> V_94 . V_95 . V_100 > 65464 )
V_64 -> V_94 . V_95 . V_100 = 65464 ;
V_65 = F_38 ( V_64 -> V_94 . V_95 . V_100 + V_84 ,
V_53 ) ;
V_92 -> V_25 = F_18 ( V_65 * V_53 ) ;
}
else {
V_65 = 1 ;
V_92 -> V_25 = V_101 ;
}
if ( V_92 -> V_25 < 0 ) return - V_102 ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
V_15 ;
F_5 ( V_103 , V_21 ) ;
V_15 ;
F_21 ( L_28 , F_7 ( V_21 ) , F_7 ( V_16 ) ) ;
V_66 = ( F_7 ( V_21 ) & V_104 ) >> V_105 ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
F_21 ( L_29 , V_66 ) ;
if ( ! V_66 ) return - V_106 ;
F_19 ( V_64 -> V_24 , V_92 -> V_25 ) ;
F_21 ( L_30 , V_92 -> V_25 ) ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
F_4 ( V_12 , V_92 -> V_25 << V_107 ,
V_66 * V_108 / 4 ) ;
F_4 ( V_12 , V_109 | ( V_64 -> V_94 . V_98 == V_99 ?
V_110 : 0 ) | V_65 , V_66 * V_108 / 4 + 1 ) ;
F_4 ( V_12 , 0 , V_66 * V_108 / 4 + 2 ) ;
V_92 -> V_93 = V_66 ;
V_12 -> V_79 [ V_66 ] = V_64 ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
return 0 ;
}
static int F_39 ( struct V_63 * V_64 )
{
struct V_12 * V_12 ;
struct V_92 * V_92 ;
unsigned long V_30 ;
int V_59 , V_111 ;
F_21 ( L_31 , F_37 ( 0xc053 ) ) ;
V_12 = F_9 ( V_64 -> V_24 ) ;
V_92 = F_29 ( V_64 ) ;
if ( ! V_92 -> V_93 ) return 0 ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
V_59 = V_64 -> V_112 >> 1 ;
V_111 = ( 1 - ( V_64 -> V_112 & 1 ) ) << 4 ;
F_4 ( V_12 , ( F_6 ( V_12 , V_59 ) & ~ ( 0xffff << V_111 ) ) |
( ( V_92 -> V_93 | V_113 ) << V_111 ) , V_59 ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
return 0 ;
}
static void F_40 ( struct V_63 * V_64 )
{
struct V_12 * V_12 ;
struct V_92 * V_92 ;
unsigned long V_30 ;
int V_59 , V_111 ;
V_92 = F_29 ( V_64 ) ;
V_12 = F_9 ( V_64 -> V_24 ) ;
if ( ! V_92 -> V_93 ) return;
F_21 ( L_32 ) ;
if ( V_64 -> V_114 != V_115 && V_64 -> V_112 != V_116 ) {
F_10 ( & V_12 -> V_38 , V_30 ) ;
V_59 = V_64 -> V_112 >> 1 ;
V_111 = ( 1 - ( V_64 -> V_112 & 1 ) ) << 4 ;
F_4 ( V_12 , F_6 ( V_12 , V_59 ) & ~ ( 0xffff << V_111 ) , V_59 ) ;
V_15 ;
F_5 ( V_117 , V_21 ) ;
V_15 ;
F_5 ( V_117 , V_21 ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
}
F_10 ( & V_12 -> V_38 , V_30 ) ;
V_15 ;
F_5 ( V_118 | V_119 | ( V_92 -> V_93 <<
V_105 ) , V_21 ) ;
V_15 ;
F_41 ( 10 ) ;
F_5 ( V_120 | V_119 | ( V_92 -> V_93 <<
V_105 ) , V_21 ) ;
V_15 ;
if ( ! ( F_7 ( V_21 ) & V_104 ) )
F_3 (KERN_CRIT DEV_LABEL L_33
L_34 ,vcc->dev->number,zatm_vcc->rx_chan) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
V_12 -> V_79 [ V_92 -> V_93 ] = NULL ;
V_92 -> V_93 = 0 ;
F_22 ( V_64 -> V_24 , V_92 -> V_25 ) ;
}
static int F_42 ( struct V_23 * V_24 )
{
struct V_12 * V_12 ;
int V_10 ;
F_21 ( L_35 ) ;
V_12 = F_9 ( V_24 ) ;
V_12 -> V_79 = F_43 ( V_12 -> V_78 ,
sizeof( * V_12 -> V_79 ) ,
V_121 ) ;
if ( ! V_12 -> V_79 ) return - V_122 ;
F_4 ( V_12 , ( 1 << V_24 -> V_123 . V_124 ) - 1 , V_125 ) ;
for ( V_10 = 0 ; V_10 <= V_126 ; V_10 ++ ) {
V_12 -> V_37 [ V_10 ] . V_54 = 0 ;
V_12 -> V_37 [ V_10 ] . V_127 = 0 ;
V_12 -> V_37 [ V_10 ] . V_128 = 0 ;
V_12 -> V_37 [ V_10 ] . V_41 = V_129 ;
V_12 -> V_37 [ V_10 ] . V_43 = V_130 ;
V_12 -> V_37 [ V_10 ] . V_32 = 0 ;
V_12 -> V_37 [ V_10 ] . V_131 = 0 ;
V_12 -> V_37 [ V_10 ] . V_132 = 0 ;
V_12 -> V_37 [ V_10 ] . V_133 = V_134 ;
}
return 0 ;
}
static int F_44 ( struct V_26 * V_27 )
{
struct V_63 * V_64 ;
struct V_12 * V_12 ;
struct V_92 * V_92 ;
T_1 * V_135 ;
unsigned long V_30 ;
F_2 ( L_36 , 0 , 0 ) ;
F_21 ( L_37 , V_27 ) ;
V_64 = F_35 ( V_27 ) -> V_64 ;
V_12 = F_9 ( V_64 -> V_24 ) ;
V_92 = F_29 ( V_64 ) ;
F_2 ( L_38 , F_45 ( V_27 ) -> V_136 , 0 ) ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
if ( ! F_45 ( V_27 ) -> V_136 ) {
if ( V_92 -> V_137 == V_138 - 1 ) {
F_11 ( & V_12 -> V_38 , V_30 ) ;
return V_139 ;
}
V_92 -> V_137 ++ ;
V_135 = V_92 -> V_140 + V_92 -> V_141 ;
V_92 -> V_141 = ( V_92 -> V_141 + V_142 ) &
( V_138 * V_142 - 1 ) ;
V_135 [ 1 ] = 0 ;
V_135 [ 2 ] = V_27 -> V_89 ;
V_135 [ 3 ] = F_14 ( V_27 -> V_46 ) ;
F_46 () ;
V_135 [ 0 ] = V_143 | V_144 | V_145
| ( V_64 -> V_94 . V_98 == V_99 ? V_146 : 0 |
( F_35 ( V_27 ) -> V_147 & V_148 ?
V_149 : V_150 ) ) ;
F_2 ( L_39 , ( unsigned long ) V_135 , 0 ) ;
}
else {
F_3 ( L_40 ) ;
V_135 = NULL ;
#if 0
u32 *put;
int i;
dsc = kmalloc(uPD98401_TXPD_SIZE * 2 +
uPD98401_TXBD_SIZE * ATM_SKB(skb)->iovcnt, GFP_ATOMIC);
if (!dsc) {
if (vcc->pop)
vcc->pop(vcc, skb);
else
dev_kfree_skb_irq(skb);
return -EAGAIN;
}
put = dsc+8;
dsc[0] = uPD98401_TXPD_V | uPD98401_TXPD_DP |
(vcc->aal == ATM_AAL5 ? uPD98401_TXPD_AAL5 : 0 |
(ATM_SKB(skb)->atm_options & ATM_ATMOPT_CLP ?
uPD98401_CLPM_1 : uPD98401_CLPM_0));
dsc[1] = 0;
dsc[2] = ATM_SKB(skb)->iovcnt * uPD98401_TXBD_SIZE;
dsc[3] = virt_to_bus(put);
for (i = 0; i < ATM_SKB(skb)->iovcnt; i++) {
*put++ = ((struct iovec *) skb->data)[i].iov_len;
*put++ = virt_to_bus(((struct iovec *)
skb->data)[i].iov_base);
}
put[-2] |= uPD98401_TXBD_LAST;
#endif
}
F_47 ( V_27 ) = V_135 ;
F_15 ( & V_92 -> V_151 , V_27 ) ;
F_21 ( L_41 , F_6 ( V_12 , V_92 -> V_152 * V_108 / 4 +
V_153 ) ) ;
V_15 ;
F_5 ( V_154 | ( V_92 -> V_152 <<
V_105 ) , V_21 ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
F_2 ( L_42 , 0 , 0 ) ;
return 0 ;
}
static inline void F_48 ( struct V_63 * V_64 )
{
struct V_92 * V_92 ;
struct V_26 * V_27 ;
F_2 ( L_43 , 0 , 0 ) ;
V_92 = F_29 ( V_64 ) ;
V_27 = F_49 ( & V_92 -> V_151 ) ;
if ( ! V_27 ) {
F_3 (KERN_CRIT DEV_LABEL L_44
L_45 ,vcc->dev->number) ;
return;
}
#if 0
if (*ZATM_PRV_DSC(skb) != (uPD98401_TXPD_V | uPD98401_TXPD_DP |
uPD98401_TXPD_SM | uPD98401_TXPD_AAL5)) printk("@#*$!!!! (%08x)\n",
*ZATM_PRV_DSC(skb));
#endif
* F_47 ( V_27 ) = 0 ;
V_92 -> V_137 -- ;
if ( V_64 -> V_155 ) V_64 -> V_155 ( V_64 , V_27 ) ;
else F_32 ( V_27 ) ;
while ( ( V_27 = F_49 ( & V_92 -> V_156 ) ) )
if ( F_44 ( V_27 ) == V_139 ) {
F_50 ( & V_92 -> V_156 , V_27 ) ;
break;
}
F_33 ( & V_64 -> V_86 -> V_157 ) ;
F_51 ( & V_92 -> V_158 ) ;
}
static void F_52 ( struct V_23 * V_24 , int V_58 )
{
struct V_12 * V_12 ;
unsigned long V_59 ;
T_1 V_60 ;
F_2 ( L_46 , 0 , 0 ) ;
V_12 = F_9 ( V_24 ) ;
V_59 = ( V_12 -> V_61 [ V_58 ] & ~ 0xffffUL ) | F_7 ( F_24 ( V_58 ) ) ;
while ( V_60 = F_7 ( F_25 ( V_58 ) ) , ( V_59 & 0xffff ) != V_60 ) {
int V_66 ;
#if 1
T_1 V_46 , * V_14 ;
F_2 ( L_15 , V_59 , V_60 ) ;
V_14 = ( T_1 * ) V_59 ;
V_46 = * V_14 ;
V_66 = ( V_46 & V_159 ) >> V_160 ;
F_2 ( L_47 , ( unsigned long ) V_14 ,
V_46 ) ;
F_2 ( L_48 , V_66 , 0 ) ;
#else
V_161 !
V_66 = ( V_12 -> V_61 [ V_58 ] [ V_59 >> 2 ] & V_159 )
>> V_160 ;
#endif
if ( V_66 < V_12 -> V_78 && V_12 -> V_162 [ V_66 ] )
F_48 ( V_12 -> V_162 [ V_66 ] ) ;
else {
F_3 (KERN_CRIT DEV_LABEL L_49
L_50 ,dev->number,chan) ;
F_1 () ;
}
if ( ( ( V_59 += 4 ) & 0xffff ) == V_12 -> V_67 [ V_58 ] )
V_59 = V_12 -> V_61 [ V_58 ] ;
}
F_5 ( V_59 & 0xffff , F_24 ( V_58 ) ) ;
}
static int F_53 ( struct V_23 * V_24 , int * V_163 , int V_164 , int V_165 , int V_166 )
{
struct V_12 * V_12 ;
unsigned long V_30 ;
unsigned long V_10 , V_167 , V_168 ;
int V_169 ;
F_21 ( L_51 , V_164 , V_165 ) ;
V_12 = F_9 ( V_24 ) ;
if ( ! V_12 -> V_170 ) return - V_106 ;
for ( V_169 = 0 ; ! ( ( V_12 -> V_170 >> V_169 ) & 1 ) ; V_169 ++ ) ;
V_12 -> V_170 &= ~ 1 << V_169 ;
if ( V_166 ) {
V_168 = 5 ;
V_10 = V_167 = 1 ;
V_12 -> V_171 ++ ;
V_12 -> V_166 = V_169 ;
* V_163 = 0 ;
}
else {
if ( V_164 ) {
if ( V_164 <= 255 ) {
V_10 = V_164 ;
V_167 = V_172 ;
}
else {
V_10 = 255 ;
V_167 = V_172 * 255 / V_164 ;
}
}
else {
if ( V_165 > V_12 -> V_173 ) V_165 = V_12 -> V_173 ;
if ( V_165 <= 255 ) {
V_10 = V_165 ;
V_167 = V_172 ;
}
else {
V_10 = 255 ;
V_167 = F_38 ( V_172 * 255 , V_165 ) ;
}
}
if ( V_10 > V_167 ) {
F_3 (KERN_CRIT DEV_LABEL L_52
L_53 ,min,max,i,m) ;
V_167 = V_10 ;
}
* V_163 = V_10 * V_172 / V_167 ;
V_168 = 20 ;
if ( ( V_164 && * V_163 < V_164 ) || ( V_165 && * V_163 > V_165 ) ) return - V_174 ;
if ( V_12 -> V_173 < * V_163 ) return - V_106 ;
V_12 -> V_173 -= * V_163 ;
}
F_10 ( & V_12 -> V_38 , V_30 ) ;
F_21 ( L_54 , V_10 , V_167 , * V_163 ) ;
F_4 ( V_12 , ( V_10 << V_175 ) | V_167 , F_54 ( V_169 ) ) ;
F_4 ( V_12 , V_168 << V_176 , F_55 ( V_169 ) ) ;
F_4 ( V_12 , 0 , F_56 ( V_169 ) ) ;
F_4 ( V_12 , 0 , F_57 ( V_169 ) ) ;
F_4 ( V_12 , V_177 , F_58 ( V_169 ) ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
return V_169 ;
}
static void F_59 ( struct V_23 * V_24 , int V_169 )
{
struct V_12 * V_12 ;
unsigned long V_30 ;
V_12 = F_9 ( V_24 ) ;
if ( V_169 == V_12 -> V_166 ) {
if ( -- V_12 -> V_171 ) return;
V_12 -> V_166 = - 1 ;
}
F_10 ( & V_12 -> V_38 , V_30 ) ;
F_4 ( V_12 , F_6 ( V_12 , F_58 ( V_169 ) ) & ~ V_177 ,
F_58 ( V_169 ) ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
V_12 -> V_170 |= 1 << V_169 ;
}
static void F_60 ( struct V_63 * V_64 )
{
struct V_12 * V_12 ;
struct V_92 * V_92 ;
unsigned long V_30 ;
int V_66 ;
V_92 = F_29 ( V_64 ) ;
V_12 = F_9 ( V_64 -> V_24 ) ;
V_66 = V_92 -> V_152 ;
if ( ! V_66 ) return;
F_21 ( L_55 ) ;
if ( F_61 ( & V_92 -> V_156 ) ) {
F_3 ( L_56 ) ;
F_1 () ;
F_62 ( V_92 -> V_158 , ! F_61 ( & V_92 -> V_156 ) ) ;
}
if ( F_61 ( & V_92 -> V_151 ) ) {
F_3 ( L_57 ) ;
F_1 () ;
F_62 ( V_92 -> V_158 , ! F_61 ( & V_92 -> V_151 ) ) ;
}
F_10 ( & V_12 -> V_38 , V_30 ) ;
#if 0
zwait;
zout(uPD98401_DEACT_CHAN | (chan << uPD98401_CHAN_ADDR_SHIFT),CMR);
#endif
V_15 ;
F_5 ( V_120 | ( V_66 << V_105 ) , V_21 ) ;
V_15 ;
if ( ! ( F_7 ( V_21 ) & V_104 ) )
F_3 (KERN_CRIT DEV_LABEL L_58
L_34 ,vcc->dev->number,chan) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
V_92 -> V_152 = 0 ;
V_12 -> V_162 [ V_66 ] = NULL ;
if ( V_92 -> V_169 != V_12 -> V_166 ) {
V_12 -> V_173 += V_64 -> V_94 . V_178 . V_179 ;
F_59 ( V_64 -> V_24 , V_92 -> V_169 ) ;
}
F_63 ( V_92 -> V_140 ) ;
}
static int F_64 ( struct V_63 * V_64 )
{
struct V_12 * V_12 ;
struct V_92 * V_92 ;
unsigned long V_30 ;
T_1 * V_180 ;
unsigned short V_66 ;
int V_181 ;
F_21 ( L_59 ) ;
V_12 = F_9 ( V_64 -> V_24 ) ;
V_92 = F_29 ( V_64 ) ;
V_92 -> V_152 = 0 ;
if ( V_64 -> V_94 . V_178 . V_96 == V_97 ) return 0 ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
V_15 ;
F_5 ( V_103 , V_21 ) ;
V_15 ;
F_21 ( L_28 , F_7 ( V_21 ) , F_7 ( V_16 ) ) ;
V_66 = ( F_7 ( V_21 ) & V_104 ) >> V_105 ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
F_21 ( L_29 , V_66 ) ;
if ( ! V_66 ) return - V_106 ;
V_181 = V_64 -> V_94 . V_178 . V_96 == V_182 &&
( ! V_64 -> V_94 . V_178 . V_183 || V_64 -> V_94 . V_178 . V_183 == V_184 ||
V_64 -> V_94 . V_178 . V_183 >= V_172 ) ;
if ( V_181 && V_12 -> V_166 != - 1 ) V_92 -> V_169 = V_12 -> V_166 ;
else {
int V_185 ( V_163 ) ;
if ( V_181 ) V_64 -> V_94 . V_178 . V_100 = V_85 ;
if ( ( V_92 -> V_169 = F_53 ( V_64 -> V_24 , & V_163 ,
V_64 -> V_94 . V_178 . V_179 , V_64 -> V_94 . V_178 . V_183 , V_181 ) )
< 0 ) {
F_60 ( V_64 ) ;
return V_92 -> V_169 ;
}
if ( V_163 > V_172 ) V_163 = V_172 ;
V_64 -> V_94 . V_178 . V_179 = V_64 -> V_94 . V_178 . V_183 = V_163 ;
}
V_92 -> V_152 = V_66 ;
F_20 ( & V_92 -> V_151 ) ;
F_65 ( & V_92 -> V_158 ) ;
V_92 -> V_140 = F_66 ( V_186 , V_121 ) ;
if ( ! V_92 -> V_140 ) return - V_122 ;
V_180 = V_92 -> V_140 + V_138 * V_142 ;
V_180 [ 0 ] = V_143 ;
V_180 [ 1 ] = V_180 [ 2 ] = 0 ;
V_180 [ 3 ] = F_14 ( V_92 -> V_140 ) ;
V_92 -> V_141 = 0 ;
V_92 -> V_137 = 0 ;
F_20 ( & V_92 -> V_156 ) ;
F_4 ( V_12 , F_14 ( V_92 -> V_140 ) ,
V_66 * V_108 / 4 + V_153 ) ;
return 0 ;
}
static int F_67 ( struct V_63 * V_64 )
{
struct V_12 * V_12 ;
struct V_92 * V_92 ;
unsigned long V_30 ;
F_21 ( L_60 ) ;
V_12 = F_9 ( V_64 -> V_24 ) ;
V_92 = F_29 ( V_64 ) ;
if ( ! V_92 -> V_152 ) return 0 ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
F_4 ( V_12 , 0 , V_92 -> V_152 * V_108 / 4 ) ;
F_4 ( V_12 , V_187 | ( V_92 -> V_169 <<
V_188 ) | ( V_64 -> V_114 << V_189 ) |
V_64 -> V_112 , V_92 -> V_152 * V_108 / 4 + 1 ) ;
F_4 ( V_12 , 0 , V_92 -> V_152 * V_108 / 4 + 2 ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
V_12 -> V_162 [ V_92 -> V_152 ] = V_64 ;
return 0 ;
}
static int F_68 ( struct V_23 * V_24 )
{
struct V_12 * V_12 ;
int V_10 ;
F_21 ( L_61 ) ;
V_12 = F_9 ( V_24 ) ;
V_12 -> V_162 = F_69 ( V_12 -> V_78 ,
sizeof( * V_12 -> V_162 ) ,
V_121 ) ;
if ( ! V_12 -> V_162 ) return - V_122 ;
V_12 -> V_173 = V_172 ;
V_12 -> V_170 = ( 1 << V_190 ) - 1 ;
V_12 -> V_166 = - 1 ;
V_12 -> V_171 = 0 ;
for ( V_10 = 0 ; V_10 < V_190 ; V_10 ++ ) F_4 ( V_12 , 0 , F_58 ( V_10 ) ) ;
return 0 ;
}
static T_2 F_70 ( int V_191 , void * V_192 )
{
struct V_23 * V_24 ;
struct V_12 * V_12 ;
T_1 V_193 ;
int V_194 = 0 ;
V_24 = V_192 ;
V_12 = F_9 ( V_24 ) ;
while ( ( V_193 = F_7 ( V_195 ) ) ) {
V_194 = 1 ;
F_2 ( L_62 , V_193 , 0 ) ;
if ( V_193 & V_196 ) {
F_2 ( L_63 , 0 , 0 ) ;
V_24 -> V_197 -> V_198 ( V_24 ) ;
}
if ( V_193 & V_199 ) {
unsigned long V_200 ;
int V_10 ;
V_200 = F_7 ( V_201 ) ;
F_2 ( L_64 , V_200 , 0 ) ;
for ( V_10 = 0 ; V_200 ; V_10 ++ ) {
if ( V_200 & 1 ) {
F_8 ( V_24 , V_10 ) ;
V_12 -> V_37 [ V_10 ] . V_127 ++ ;
}
V_200 >>= 1 ;
}
}
if ( V_193 & V_202 ) {
unsigned long V_200 ;
int V_10 ;
V_200 = F_7 ( V_203 ) ;
F_3 (KERN_WARNING DEV_LABEL L_65 ,
dev->number,pools) ;
F_1 () ;
for ( V_10 = 0 ; V_200 ; V_10 ++ ) {
if ( V_200 & 1 ) {
F_8 ( V_24 , V_10 ) ;
V_12 -> V_37 [ V_10 ] . V_128 ++ ;
}
V_200 >>= 1 ;
}
}
if ( V_193 & V_204 )
F_3 (KERN_ALERT DEV_LABEL L_66
L_67 ,dev->number,zin(ADDR)) ;
if ( V_193 & V_205 )
F_3 (KERN_ALERT DEV_LABEL L_68
L_69 ,dev->number,zin(ADDR)) ;
if ( V_193 & V_206 ) {
F_3 (KERN_ALERT DEV_LABEL L_70
L_67 ,dev->number,zin(ADDR)) ;
F_1 () ;
}
if ( V_193 & V_207 ) {
F_3 (KERN_CRIT DEV_LABEL L_71
L_72 ,dev->number,(reason & uPD98401_INT_MF)
>> uPD98401_INT_MF_SHIFT) ;
F_1 () ;
}
if ( V_193 & V_208 ) {
if ( V_193 & 1 ) F_23 ( V_24 , 0 ) ;
if ( V_193 & 2 ) F_23 ( V_24 , 1 ) ;
if ( V_193 & 4 ) F_52 ( V_24 , 2 ) ;
if ( V_193 & 8 ) F_52 ( V_24 , 3 ) ;
}
}
return F_71 ( V_194 ) ;
}
static void F_72 ( struct V_12 * V_12 , unsigned long V_13 ,
unsigned short V_209 )
{
int error ;
if ( ( error = F_73 ( V_12 -> V_210 , V_209 , V_13 ) ) )
F_3 (KERN_ERR DEV_LABEL L_73 ,
error) ;
}
static unsigned long F_74 ( struct V_12 * V_12 , unsigned short V_209 )
{
unsigned int V_13 ;
int error ;
if ( ( error = F_75 ( V_12 -> V_210 , V_209 , & V_13 ) ) )
F_3 (KERN_ERR DEV_LABEL L_74 ,
error) ;
return V_13 ;
}
static void F_76 ( struct V_12 * V_12 , unsigned long V_46 ,
int V_211 , unsigned short V_209 )
{
unsigned long V_13 ;
int V_10 ;
for ( V_10 = V_211 - 1 ; V_10 >= 0 ; V_10 -- ) {
V_13 = V_212 | ( ( ( V_46 >> V_10 ) & 1 ) ? V_213 : 0 ) ;
F_72 ( V_12 , V_13 , V_209 ) ;
F_72 ( V_12 , V_13 | V_214 , V_209 ) ;
F_72 ( V_12 , V_13 , V_209 ) ;
}
}
static void F_77 ( struct V_12 * V_12 , unsigned char * V_215 ,
unsigned short V_209 )
{
int V_10 ;
* V_215 = 0 ;
for ( V_10 = 8 ; V_10 ; V_10 -- ) {
F_72 ( V_12 , V_212 , V_209 ) ;
F_72 ( V_12 , V_212 | V_214 , V_209 ) ;
* V_215 <<= 1 ;
if ( F_74 ( V_12 , V_209 ) & V_216 ) * V_215 |= 1 ;
F_72 ( V_12 , V_212 , V_209 ) ;
}
}
static unsigned char F_78 ( struct V_23 * V_24 , unsigned short V_209 ,
int V_32 , int V_217 )
{
unsigned char V_218 [ V_219 ] ;
struct V_12 * V_12 ;
int V_10 ;
V_12 = F_9 ( V_24 ) ;
for ( V_10 = 0 ; V_10 < V_219 ; V_10 += 2 ) {
F_72 ( V_12 , V_212 , V_209 ) ;
F_76 ( V_12 , V_220 , V_221 , V_209 ) ;
F_76 ( V_12 , V_10 >> 1 , V_222 , V_209 ) ;
F_77 ( V_12 , V_218 + V_10 + V_217 , V_209 ) ;
F_77 ( V_12 , V_218 + V_10 + 1 - V_217 , V_209 ) ;
F_72 ( V_12 , 0 , V_209 ) ;
}
memcpy ( V_24 -> V_223 , V_218 + V_32 , V_224 ) ;
return memcmp ( V_24 -> V_223 , L_75 , V_224 ) ;
}
static void F_79 ( struct V_23 * V_24 )
{
if ( F_78 ( V_24 , V_225 , V_226 , 1 ) ) return;
( void ) F_78 ( V_24 , V_227 , V_228 , 0 ) ;
}
static int F_80 ( struct V_23 * V_24 )
{
struct V_12 * V_12 ;
struct V_210 * V_210 ;
unsigned short V_229 ;
int error , V_10 , V_230 ;
unsigned long V_231 , V_232 , V_233 ;
F_21 ( L_76 ) ;
V_12 = F_9 ( V_24 ) ;
F_81 ( & V_12 -> V_38 ) ;
V_210 = V_12 -> V_210 ;
V_12 -> V_234 = F_82 ( V_210 , 0 ) ;
V_12 -> V_191 = V_210 -> V_191 ;
if ( ( error = F_83 ( V_210 , V_235 , & V_229 ) ) ) {
F_3 (KERN_ERR DEV_LABEL L_77 ,
dev->number,error) ;
return - V_174 ;
}
if ( ( error = F_84 ( V_210 , V_235 ,
V_229 | V_236 | V_237 ) ) ) {
F_3 (KERN_ERR DEV_LABEL L_78
L_79 ,dev->number,error) ;
return - V_238 ;
}
F_79 ( V_24 ) ;
F_3 (KERN_NOTICE DEV_LABEL L_80 ,
dev->number,pci_dev->revision,zatm_dev->base,zatm_dev->irq) ;
F_5 ( 0 , V_239 ) ;
while ( ! ( F_7 ( V_195 ) & V_240 ) ) ;
F_5 ( V_241 , V_242 ) ;
V_230 = V_243 ;
for ( V_10 = V_230 - V_244 ; V_10 >= 0 ; V_10 -= V_244 ) {
F_4 ( V_12 , 0x55555555 , V_10 ) ;
if ( F_6 ( V_12 , V_10 ) != 0x55555555 ) V_230 = V_10 ;
else {
F_4 ( V_12 , 0xAAAAAAAA , V_10 ) ;
if ( F_6 ( V_12 , V_10 ) != 0xAAAAAAAA ) V_230 = V_10 ;
else F_4 ( V_12 , V_10 , V_10 ) ;
}
}
for ( V_10 = 0 ; V_10 < V_230 ; V_10 += V_244 )
if ( F_6 ( V_12 , V_10 ) != V_10 ) break;
V_12 -> V_245 = V_10 << 2 ;
while ( V_10 ) F_4 ( V_12 , 0 , -- V_10 ) ;
F_5 ( 0 , V_239 ) ;
while ( ! ( F_7 ( V_195 ) & V_240 ) ) ;
F_5 ( V_241 | V_246 | V_247 |
V_248 | V_249 | V_250 , V_242 ) ;
F_3 ( L_81 , V_12 -> V_245 >> 10 , V_12 -> V_251 ? L_82 :
L_83 ) ;
for ( V_10 = 0 ; V_10 < V_224 ; V_10 ++ )
F_3 ( L_84 , V_24 -> V_223 [ V_10 ] , V_10 == V_224 - 1 ? L_85 : L_86 ) ;
do {
unsigned long V_30 ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
V_231 = F_6 ( V_12 , V_252 ) ;
F_41 ( 10 ) ;
V_232 = F_6 ( V_12 , V_252 ) ;
F_41 ( 1010 ) ;
V_233 = F_6 ( V_12 , V_252 ) ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
}
while ( V_231 > V_232 || V_232 > V_233 );
V_12 -> V_253 = V_233 - 2 * V_232 + V_231 ;
F_3 (KERN_NOTICE DEV_LABEL L_87
L_88 ,dev->number,
(zin(VER) & uPD98401_MAJOR) >> uPD98401_MAJOR_SHIFT,
zin(VER) & uPD98401_MINOR,zatm_dev->khz/1000 ,zatm_dev->khz % 1000 ) ;
return F_85 ( V_24 ) ;
}
static int F_86 ( struct V_23 * V_24 )
{
struct V_12 * V_12 = F_9 ( V_24 ) ;
struct V_210 * V_254 = V_12 -> V_210 ;
unsigned long V_255 ;
int V_200 , V_256 , V_91 ;
int error , V_10 , V_257 ;
F_21 ( L_89 ) ;
V_12 -> V_79 = V_12 -> V_162 = NULL ;
for ( V_10 = 0 ; V_10 < V_258 ; V_10 ++ )
V_12 -> V_61 [ V_10 ] = 0 ;
error = F_87 ( V_12 -> V_191 , F_70 , V_259 , V_260 , V_24 ) ;
if ( error < 0 ) {
F_3 (KERN_ERR DEV_LABEL L_90 ,
dev->number,zatm_dev->irq) ;
goto V_261;
}
V_200 = V_262 ;
if ( V_190 * V_263 > V_200 * V_264 )
V_200 = V_190 * V_263 / V_264 ;
V_256 = ( V_12 -> V_245 - V_190 * V_263 - V_200 * V_264 ) /
( 2 * V_108 + V_265 ) ;
V_257 = - 1 ;
for ( V_91 = 1 ; V_91 < V_256 ; V_91 <<= 1 ) V_257 ++ ;
V_24 -> V_123 . V_266 = 0 ;
V_24 -> V_123 . V_124 = V_257 ;
V_24 -> V_267 = V_172 ;
V_12 -> V_78 = V_256 ;
V_255 = V_91 * V_265 / 4 ;
F_21 ( L_91 , V_255 ) ;
F_4 ( V_12 , V_255 , V_268 ) ;
V_12 -> V_39 = V_255 ;
V_255 += V_200 * V_264 / 4 ;
F_21 ( L_92 , V_255 ) ;
F_4 ( V_12 , V_255 , V_269 ) ;
V_255 += V_190 * V_263 / 4 ;
F_21 ( L_93 , V_255 ) ;
F_4 ( V_12 , V_255 , V_270 ) ;
F_3 (KERN_INFO DEV_LABEL L_94
L_95 ,dev->number,NR_SHAPERS,pools,rx,
(zatm_dev->mem-curr*4)/VC_SIZE) ;
for ( V_10 = 0 ; V_10 < V_258 ; V_10 ++ ) {
void * V_58 ;
T_3 V_271 ;
if ( ! V_272 [ V_10 ] )
continue;
V_58 = F_88 ( & V_254 -> V_24 ,
2 * F_89 ( V_10 ) , & V_271 , V_121 ) ;
if ( ! V_58 ) {
error = - V_122 ;
goto V_273;
}
if ( ( ( unsigned long ) V_58 ^ V_271 ) & 0xffff ) {
F_3 (KERN_ERR DEV_LABEL L_96
L_97 , dev->number) ;
F_90 ( & V_254 -> V_24 , 2 * F_89 ( V_10 ) , V_58 , V_271 ) ;
error = - V_274 ;
goto V_273;
}
F_21 ( L_98 , V_58 , V_58 + F_89 ( V_10 ) ) ;
V_12 -> V_61 [ V_10 ] = ( unsigned long ) V_58 ;
V_12 -> V_271 [ V_10 ] = V_271 ;
V_12 -> V_67 [ V_10 ] = ( V_12 -> V_61 [ V_10 ] + F_89 ( V_10 ) ) &
0xffff ;
F_5 ( V_271 >> 16 , F_91 ( V_10 ) ) ;
F_5 ( V_271 , F_92 ( V_10 ) ) ;
F_5 ( V_12 -> V_67 [ V_10 ] , F_93 ( V_10 ) ) ;
F_5 ( ( unsigned long ) V_58 & 0xffff , F_24 ( V_10 ) ) ;
F_5 ( ( unsigned long ) V_58 & 0xffff , F_25 ( V_10 ) ) ;
}
error = F_68 ( V_24 ) ;
if ( error )
goto V_273;
error = F_42 ( V_24 ) ;
if ( error )
goto V_275;
error = V_24 -> V_197 -> V_276 ( V_24 ) ;
if ( error )
goto V_277;
F_5 ( 0xffffffff , V_278 ) ;
F_5 ( F_7 ( V_242 ) | V_279 | V_280 , V_242 ) ;
V_261:
return error ;
V_277:
F_63 ( V_12 -> V_79 ) ;
V_275:
F_63 ( V_12 -> V_162 ) ;
V_273:
while ( V_10 -- > 0 ) {
F_90 ( & V_254 -> V_24 , 2 * F_89 ( V_10 ) ,
( void * ) V_12 -> V_61 [ V_10 ] ,
V_12 -> V_271 [ V_10 ] ) ;
}
F_94 ( V_12 -> V_191 , V_24 ) ;
goto V_261;
}
static void F_95 ( struct V_63 * V_64 )
{
F_21 ( L_99 ) ;
if ( ! F_29 ( V_64 ) ) return;
F_96 ( V_281 , & V_64 -> V_30 ) ;
F_40 ( V_64 ) ;
F_2 ( L_55 , 0 , 0 ) ;
F_60 ( V_64 ) ;
F_21 ( L_100 ) ;
F_63 ( F_29 ( V_64 ) ) ;
V_64 -> V_282 = NULL ;
F_96 ( V_283 , & V_64 -> V_30 ) ;
}
static int F_97 ( struct V_63 * V_64 )
{
struct V_12 * V_12 ;
struct V_92 * V_92 ;
short V_114 = V_64 -> V_114 ;
int V_112 = V_64 -> V_112 ;
int error ;
F_21 ( L_101 ) ;
V_12 = F_9 ( V_64 -> V_24 ) ;
if ( ! F_98 ( V_284 , & V_64 -> V_30 ) )
V_64 -> V_282 = NULL ;
if ( V_112 != V_115 && V_114 != V_116 )
F_99 ( V_283 , & V_64 -> V_30 ) ;
if ( V_64 -> V_94 . V_98 != V_99 ) return - V_174 ;
F_21 ( V_260 L_102 , V_64 -> V_24 -> V_285 , V_64 -> V_114 ,
V_64 -> V_112 ) ;
if ( ! F_98 ( V_284 , & V_64 -> V_30 ) ) {
V_92 = F_100 ( sizeof( * V_92 ) , V_121 ) ;
if ( ! V_92 ) {
F_96 ( V_283 , & V_64 -> V_30 ) ;
return - V_122 ;
}
V_64 -> V_282 = V_92 ;
F_29 ( V_64 ) -> V_152 = 0 ;
if ( ( error = F_36 ( V_64 ) ) ) {
F_95 ( V_64 ) ;
return error ;
}
if ( ( error = F_64 ( V_64 ) ) ) {
F_95 ( V_64 ) ;
return error ;
}
}
if ( V_112 == V_115 || V_114 == V_116 ) return 0 ;
if ( ( error = F_39 ( V_64 ) ) ) {
F_95 ( V_64 ) ;
return error ;
}
if ( ( error = F_67 ( V_64 ) ) ) {
F_95 ( V_64 ) ;
return error ;
}
F_99 ( V_281 , & V_64 -> V_30 ) ;
return 0 ;
}
static int F_101 ( struct V_63 * V_64 , struct V_286 * V_94 , int V_30 )
{
F_3 ( L_103 ) ;
return - V_287 ;
}
static int F_102 ( struct V_23 * V_24 , unsigned int V_209 , void T_4 * V_288 )
{
struct V_12 * V_12 ;
unsigned long V_30 ;
V_12 = F_9 ( V_24 ) ;
switch ( V_209 ) {
case V_289 :
if ( ! F_103 ( V_290 ) ) return - V_291 ;
case V_292 :
{
struct V_293 V_294 ;
int V_25 ;
if ( F_104 ( V_25 ,
& ( (struct V_295 T_4 * ) V_288 ) -> V_296 ) )
return - V_297 ;
if ( V_25 < 0 || V_25 > V_126 )
return - V_174 ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
V_294 = V_12 -> V_37 [ V_25 ] ;
if ( V_209 == V_289 ) {
V_12 -> V_37 [ V_25 ] . V_127 = 0 ;
V_12 -> V_37 [ V_25 ] . V_128 = 0 ;
}
F_11 ( & V_12 -> V_38 , V_30 ) ;
return F_105 (
& ( (struct V_295 T_4 * ) V_288 ) -> V_294 ,
& V_294 , sizeof( V_294 ) ) ? - V_297 : 0 ;
}
case V_298 :
{
struct V_293 V_294 ;
int V_25 ;
if ( ! F_103 ( V_290 ) ) return - V_291 ;
if ( F_104 ( V_25 ,
& ( (struct V_295 T_4 * ) V_288 ) -> V_296 ) )
return - V_297 ;
if ( V_25 < 0 || V_25 > V_126 )
return - V_174 ;
if ( F_106 ( & V_294 ,
& ( (struct V_295 T_4 * ) V_288 ) -> V_294 ,
sizeof( V_294 ) ) ) return - V_297 ;
if ( ! V_294 . V_41 )
V_294 . V_41 = V_12 ->
V_37 [ V_25 ] . V_41 ;
if ( ! V_294 . V_43 )
V_294 . V_43 = V_12 ->
V_37 [ V_25 ] . V_43 ;
if ( ! V_294 . V_133 )
V_294 . V_133 = V_12 ->
V_37 [ V_25 ] . V_133 ;
if ( V_294 . V_41 >= V_294 . V_43 ||
V_294 . V_41 < 0 )
return - V_174 ;
F_10 ( & V_12 -> V_38 , V_30 ) ;
V_12 -> V_37 [ V_25 ] . V_41 =
V_294 . V_41 ;
V_12 -> V_37 [ V_25 ] . V_43 =
V_294 . V_43 ;
V_12 -> V_37 [ V_25 ] . V_133 =
V_294 . V_133 ;
F_11 ( & V_12 -> V_38 , V_30 ) ;
return 0 ;
}
default:
if ( ! V_24 -> V_197 -> V_299 ) return - V_300 ;
return V_24 -> V_197 -> V_299 ( V_24 , V_209 , V_288 ) ;
}
}
static int F_107 ( struct V_63 * V_64 , int V_301 , int V_302 ,
void T_4 * V_303 , int V_304 )
{
return - V_174 ;
}
static int F_108 ( struct V_63 * V_64 , int V_301 , int V_302 ,
void T_4 * V_303 , unsigned int V_304 )
{
return - V_174 ;
}
static int F_109 ( struct V_63 * V_64 , struct V_26 * V_27 )
{
int error ;
F_2 ( L_104 , ( unsigned long ) V_27 , 0 ) ;
if ( ! F_29 ( V_64 ) -> V_152 || ! F_98 ( V_281 , & V_64 -> V_30 ) ) {
if ( V_64 -> V_155 ) V_64 -> V_155 ( V_64 , V_27 ) ;
else F_110 ( V_27 ) ;
return - V_174 ;
}
if ( ! V_27 ) {
F_3 ( V_305 L_105 ) ;
if ( V_64 -> V_155 ) V_64 -> V_155 ( V_64 , V_27 ) ;
return - V_174 ;
}
F_35 ( V_27 ) -> V_64 = V_64 ;
error = F_44 ( V_27 ) ;
if ( error != V_139 ) return error ;
F_15 ( & F_29 ( V_64 ) -> V_156 , V_27 ) ;
return 0 ;
}
static void F_111 ( struct V_23 * V_24 , unsigned char V_13 ,
unsigned long V_14 )
{
struct V_12 * V_12 ;
V_12 = F_9 ( V_24 ) ;
V_15 ;
F_5 ( V_13 , V_16 ) ;
F_5 ( V_17 | V_306 |
( V_307 << V_20 ) | V_14 , V_21 ) ;
}
static unsigned char F_112 ( struct V_23 * V_24 , unsigned long V_14 )
{
struct V_12 * V_12 ;
V_12 = F_9 ( V_24 ) ;
V_15 ;
F_5 ( V_17 | V_306 | V_22 |
( V_307 << V_20 ) | V_14 , V_21 ) ;
V_15 ;
return F_7 ( V_16 ) & 0xff ;
}
static int F_113 ( struct V_210 * V_210 ,
const struct V_308 * V_309 )
{
struct V_23 * V_24 ;
struct V_12 * V_12 ;
int V_310 = - V_122 ;
V_12 = F_100 ( sizeof( * V_12 ) , V_121 ) ;
if ( ! V_12 ) {
F_3 ( V_311 L_106 , V_260 ) ;
goto V_273;
}
V_24 = F_114 ( V_260 , & V_210 -> V_24 , & V_312 , - 1 , NULL ) ;
if ( ! V_24 )
goto V_313;
V_310 = F_115 ( V_210 ) ;
if ( V_310 < 0 )
goto V_314;
V_310 = F_116 ( V_210 , V_260 ) ;
if ( V_310 < 0 )
goto V_315;
V_310 = F_117 ( & V_210 -> V_24 , F_118 ( 32 ) ) ;
if ( V_310 < 0 )
goto V_315;
V_12 -> V_210 = V_210 ;
V_24 -> V_282 = V_12 ;
V_12 -> V_251 = ( int ) V_309 -> V_316 ;
if ( ( V_310 = F_80 ( V_24 ) ) || ( V_310 = F_86 ( V_24 ) ) )
goto V_317;
F_119 ( V_210 , V_24 ) ;
V_12 -> V_318 = V_319 ;
V_319 = V_24 ;
V_310 = 0 ;
V_273:
return V_310 ;
V_317:
F_120 ( V_210 ) ;
V_315:
F_121 ( V_210 ) ;
V_314:
F_122 ( V_24 ) ;
V_313:
F_63 ( V_12 ) ;
goto V_273;
}
static int T_5 F_123 ( void )
{
return F_124 ( & V_320 ) ;
}
