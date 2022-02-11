static void F_1 ( volatile T_1 * V_1 , T_1 * V_2 , int V_3 )
{
while ( V_3 >= 2 ) {
* ( V_1 ++ ) = * ( V_2 ++ ) ;
V_3 -= 2 ;
}
if ( V_3 == 1 )
* V_1 = ( * ( V_4 * ) V_2 ) << 8 ;
}
static int T_2 F_2 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
unsigned long V_9 = V_6 -> V_10 . V_11 ;
unsigned long V_12 = V_9 + V_13 ;
unsigned long V_14 = V_9 + V_15 ;
struct V_10 * V_16 , * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
V_16 = F_3 ( V_12 , sizeof( struct V_23 ) , L_1 ) ;
if ( ! V_16 )
return - V_24 ;
V_17 = F_3 ( V_14 , V_25 , L_2 ) ;
if ( ! V_17 ) {
F_4 ( V_12 , sizeof( struct V_23 ) ) ;
return - V_24 ;
}
V_19 = F_5 ( sizeof( struct V_20 ) ) ;
if ( V_19 == NULL ) {
F_4 ( V_12 , sizeof( struct V_23 ) ) ;
F_4 ( V_14 , V_25 ) ;
return - V_26 ;
}
V_21 = F_6 ( V_19 ) ;
V_16 -> V_27 = V_19 -> V_27 ;
V_17 -> V_27 = V_19 -> V_27 ;
V_19 -> V_28 [ 0 ] = 0x00 ;
V_19 -> V_28 [ 1 ] = 0x60 ;
V_19 -> V_28 [ 2 ] = 0x30 ;
V_19 -> V_28 [ 3 ] = ( V_6 -> V_29 . V_30 >> 16 ) & 0xff ;
V_19 -> V_28 [ 4 ] = ( V_6 -> V_29 . V_30 >> 8 ) & 0xff ;
V_19 -> V_28 [ 5 ] = V_6 -> V_29 . V_30 & 0xff ;
V_19 -> V_12 = F_7 ( V_12 ) ;
V_19 -> V_14 = F_7 ( V_14 ) ;
V_19 -> V_31 = V_19 -> V_14 + V_25 ;
V_19 -> V_32 = & V_33 ;
V_19 -> V_34 = 5 * V_35 ;
V_22 = F_8 ( V_19 ) ;
if ( V_22 ) {
F_4 ( V_12 , sizeof( struct V_23 ) ) ;
F_4 ( V_14 , V_25 ) ;
F_9 ( V_19 ) ;
return V_22 ;
}
F_10 ( V_6 , V_19 ) ;
F_11 ( V_36 L_3 ,
V_19 -> V_27 , V_9 , V_19 -> V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 )
{
volatile struct V_23 * V_37 = (struct V_23 * ) V_19 -> V_12 ;
T_1 V_38 ;
T_3 V_39 ;
int V_40 ;
V_38 = V_37 -> V_41 ;
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = V_45 ;
V_37 -> V_42 = V_46 ;
V_39 = F_13 ( V_37 -> V_44 ) ;
V_37 -> V_42 = V_47 ;
V_39 |= F_13 ( V_37 -> V_44 ) << 16 ;
if ( ( V_39 & 0x00000fff ) != 0x00000003 ) {
F_11 ( V_48 L_4 ) ;
return - V_49 ;
}
if ( ( V_39 & 0x0ffff000 ) != 0x00003000 ) {
F_11 ( V_48 L_5
L_6 , ( V_39 & 0x0ffff000 ) >> 12 ) ;
return - V_49 ;
}
#if 0
printk(KERN_DEBUG "ariadne_open: Am79C960 (PCnet-ISA) Revision %ld\n",
(version & 0xf0000000)>>28);
#endif
F_14 ( V_19 ) ;
V_37 -> V_42 = V_50 ;
V_37 -> V_44 = 0x0000 ;
V_37 -> V_42 = V_51 ;
V_37 -> V_44 = V_52 | V_53 | V_54 | V_55 | V_56 | V_57 ;
V_37 -> V_42 = V_58 ;
V_37 -> V_44 = 0x0000 ;
V_37 -> V_42 = V_59 ;
V_37 -> V_44 = 0x0000 ;
V_37 -> V_42 = V_60 ;
V_37 -> V_44 = 0x0000 ;
V_37 -> V_42 = V_61 ;
V_37 -> V_44 = 0x0000 ;
V_37 -> V_42 = V_62 ;
V_37 -> V_44 = ( ( T_1 * ) & V_19 -> V_28 [ 0 ] ) [ 0 ] ;
V_37 -> V_42 = V_63 ;
V_37 -> V_44 = ( ( T_1 * ) & V_19 -> V_28 [ 0 ] ) [ 1 ] ;
V_37 -> V_42 = V_64 ;
V_37 -> V_44 = ( ( T_1 * ) & V_19 -> V_28 [ 0 ] ) [ 2 ] ;
V_37 -> V_42 = V_65 ;
V_37 -> V_44 = 0x0000 ;
V_37 -> V_42 = V_66 ;
V_37 -> V_44 = F_15 ( V_15 + F_16 ( struct V_67 , V_68 ) ) ;
V_37 -> V_42 = V_69 ;
V_37 -> V_44 = F_17 ( V_15 + F_16 ( struct V_67 , V_68 ) ) ;
V_37 -> V_42 = V_70 ;
V_37 -> V_44 = F_15 ( V_15 + F_16 ( struct V_67 , V_71 ) ) ;
V_37 -> V_42 = V_72 ;
V_37 -> V_44 = F_17 ( V_15 + F_16 ( struct V_67 , V_71 ) ) ;
V_37 -> V_42 = V_73 ;
V_37 -> V_44 = F_13 ( ( ( T_1 ) - V_74 ) ) ;
V_37 -> V_42 = V_75 ;
V_37 -> V_44 = F_13 ( ( ( T_1 ) - V_76 ) ) ;
V_37 -> V_42 = V_77 ;
V_37 -> V_78 = V_79 ;
V_37 -> V_42 = V_80 ;
V_37 -> V_78 = V_81 | V_82 ;
V_37 -> V_42 = V_83 ;
V_37 -> V_78 = V_81 | V_84 ;
V_37 -> V_42 = V_85 ;
V_37 -> V_78 = V_81 | V_86 ;
F_18 ( V_19 ) ;
V_40 = F_19 ( V_87 , V_88 , V_89 ,
V_19 -> V_27 , V_19 ) ;
if ( V_40 ) return V_40 ;
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = V_90 | V_91 ;
return 0 ;
}
static void F_14 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
volatile struct V_67 * V_67 = (struct V_67 * ) V_19 -> V_14 ;
int V_40 ;
F_20 ( V_19 ) ;
V_21 -> V_92 = 0 ;
V_21 -> V_93 = V_21 -> V_94 = 0 ;
V_21 -> V_95 = 0 ;
for ( V_40 = 0 ; V_40 < V_76 ; V_40 ++ ) {
volatile struct V_96 * V_97 = & V_67 -> V_68 [ V_40 ] ;
V_97 -> V_98 = F_15 ( V_15 + F_16 ( struct V_67 , V_99 [ V_40 ] ) ) ;
V_97 -> V_100 = F_17 ( V_15 + F_16 ( struct V_67 , V_99 [ V_40 ] ) ) |
V_101 | V_102 ;
V_97 -> V_103 = F_13 ( ( T_1 ) - V_104 ) ;
V_97 -> V_105 = 0 ;
V_21 -> V_68 [ V_40 ] = & V_67 -> V_68 [ V_40 ] ;
V_21 -> V_99 [ V_40 ] = V_67 -> V_99 [ V_40 ] ;
#if 0
printk(KERN_DEBUG "TX Entry %2d at %p, Buf at %p\n", i,
&lancedata->tx_ring[i], lancedata->tx_buff[i]);
#endif
}
for ( V_40 = 0 ; V_40 < V_74 ; V_40 ++ ) {
volatile struct V_106 * V_107 = & V_67 -> V_71 [ V_40 ] ;
V_107 -> V_108 = F_15 ( V_15 + F_16 ( struct V_67 , V_109 [ V_40 ] ) ) ;
V_107 -> V_110 = F_17 ( V_15 + F_16 ( struct V_67 , V_109 [ V_40 ] ) ) |
V_111 ;
V_107 -> V_112 = F_13 ( ( T_1 ) - V_104 ) ;
V_107 -> V_113 = 0x0000 ;
V_21 -> V_71 [ V_40 ] = & V_67 -> V_71 [ V_40 ] ;
V_21 -> V_109 [ V_40 ] = V_67 -> V_109 [ V_40 ] ;
#if 0
printk(KERN_DEBUG "RX Entry %2d at %p, Buf at %p\n", i,
&lancedata->rx_ring[i], lancedata->rx_buff[i]);
#endif
}
}
static int F_21 ( struct V_18 * V_19 )
{
volatile struct V_23 * V_37 = (struct V_23 * ) V_19 -> V_12 ;
F_20 ( V_19 ) ;
V_37 -> V_42 = V_114 ;
V_19 -> V_115 . V_116 = F_13 ( V_37 -> V_44 ) ;
V_37 -> V_42 = V_43 ;
if ( V_117 > 1 ) {
F_11 ( V_118 L_7 ,
V_19 -> V_27 , V_37 -> V_44 ) ;
F_11 ( V_118 L_8 , V_19 -> V_27 ,
V_19 -> V_115 . V_116 ) ;
}
V_37 -> V_44 = V_45 ;
F_22 ( V_87 , V_19 ) ;
return 0 ;
}
static inline void F_23 ( struct V_18 * V_19 )
{
volatile struct V_23 * V_37 = (struct V_23 * ) V_19 -> V_12 ;
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = V_45 ;
F_14 ( V_19 ) ;
V_37 -> V_44 = V_90 | V_91 ;
F_18 ( V_19 ) ;
}
static T_4 V_88 ( int V_119 , void * V_120 )
{
struct V_18 * V_19 = (struct V_18 * ) V_120 ;
volatile struct V_23 * V_37 = (struct V_23 * ) V_19 -> V_12 ;
struct V_20 * V_21 ;
int V_121 , V_122 ;
int V_123 = 0 ;
V_37 -> V_42 = V_43 ;
if ( ! ( V_37 -> V_44 & V_124 ) )
return V_125 ;
V_21 = F_6 ( V_19 ) ;
V_122 = 10 ;
while ( ( V_121 = V_37 -> V_44 ) & ( V_126 | V_127 | V_128 ) && -- V_122 >= 0 ) {
V_37 -> V_44 = V_121 & ~ ( V_90 | V_129 | V_45 | V_91 | V_130 ) ;
#if 0
if (ariadne_debug > 5) {
printk(KERN_DEBUG "%s: interrupt csr0=%#2.2x new csr=%#2.2x.",
dev->name, csr0, lance->RDP);
printk("[");
if (csr0 & INTR)
printk(" INTR");
if (csr0 & INEA)
printk(" INEA");
if (csr0 & RXON)
printk(" RXON");
if (csr0 & TXON)
printk(" TXON");
if (csr0 & TDMD)
printk(" TDMD");
if (csr0 & STOP)
printk(" STOP");
if (csr0 & STRT)
printk(" STRT");
if (csr0 & INIT)
printk(" INIT");
if (csr0 & ERR)
printk(" ERR");
if (csr0 & BABL)
printk(" BABL");
if (csr0 & CERR)
printk(" CERR");
if (csr0 & MISS)
printk(" MISS");
if (csr0 & MERR)
printk(" MERR");
if (csr0 & RINT)
printk(" RINT");
if (csr0 & TINT)
printk(" TINT");
if (csr0 & IDON)
printk(" IDON");
printk(" ]\n");
}
#endif
if ( V_121 & V_127 ) {
V_123 = 1 ;
F_24 ( V_19 ) ;
}
if ( V_121 & V_128 ) {
int V_95 = V_21 -> V_95 ;
V_123 = 1 ;
while ( V_95 < V_21 -> V_94 ) {
int V_131 = V_95 % V_76 ;
int V_132 = F_25 ( V_21 -> V_68 [ V_131 ] -> V_100 ) ;
if ( V_132 & V_133 )
break;
V_21 -> V_68 [ V_131 ] -> V_100 &= 0xff00 ;
if ( V_132 & V_134 ) {
int V_135 = V_21 -> V_68 [ V_131 ] -> V_105 ;
V_19 -> V_115 . V_136 ++ ;
if ( V_135 & V_137 )
V_19 -> V_115 . V_138 ++ ;
if ( V_135 & V_139 )
V_19 -> V_115 . V_140 ++ ;
if ( V_135 & V_141 )
V_19 -> V_115 . V_142 ++ ;
if ( V_135 & V_143 ) {
V_19 -> V_115 . V_144 ++ ;
F_11 ( V_145 L_9 ,
V_19 -> V_27 , V_121 ) ;
V_37 -> V_44 = V_91 ;
}
} else {
if ( V_132 & ( V_146 | V_147 ) )
V_19 -> V_115 . V_148 ++ ;
V_19 -> V_115 . V_149 ++ ;
}
V_95 ++ ;
}
#ifndef F_26
if ( V_21 -> V_94 - V_95 >= V_76 ) {
F_11 ( V_145 L_10
L_11 , V_95 , V_21 -> V_94 , V_21 -> V_92 ) ;
V_95 += V_76 ;
}
#endif
if ( V_21 -> V_92 && F_27 ( V_19 ) &&
V_95 > V_21 -> V_94 - V_76 + 2 ) {
V_21 -> V_92 = 0 ;
F_28 ( V_19 ) ;
}
V_21 -> V_95 = V_95 ;
}
if ( V_121 & V_150 ) {
V_123 = 1 ;
V_19 -> V_115 . V_136 ++ ;
}
if ( V_121 & V_151 ) {
V_123 = 1 ;
V_19 -> V_115 . V_152 ++ ;
}
if ( V_121 & V_153 ) {
V_123 = 1 ;
F_11 ( V_145 L_12
L_13 , V_19 -> V_27 , V_121 ) ;
V_37 -> V_44 = V_91 ;
}
}
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = V_90 | V_150 | V_154 | V_151 | V_153 | V_155 ;
#if 0
if (ariadne_debug > 4)
printk(KERN_DEBUG "%s: exiting interrupt, csr%d=%#4.4x.\n", dev->name,
lance->RAP, lance->RDP);
#endif
return F_29 ( V_123 ) ;
}
static void F_30 ( struct V_18 * V_19 )
{
volatile struct V_23 * V_37 = (struct V_23 * ) V_19 -> V_12 ;
F_11 ( V_145 L_14 ,
V_19 -> V_27 , V_37 -> V_44 ) ;
F_23 ( V_19 ) ;
F_28 ( V_19 ) ;
}
static T_5 F_31 ( struct V_156 * V_157 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
volatile struct V_23 * V_37 = (struct V_23 * ) V_19 -> V_12 ;
int V_131 ;
unsigned long V_158 ;
int V_3 = V_157 -> V_3 ;
#if 0
if (ariadne_debug > 3) {
lance->RAP = CSR0;
printk(KERN_DEBUG "%s: ariadne_start_xmit() called, csr0 %4.4x.\n",
dev->name, lance->RDP);
lance->RDP = 0x0000;
}
#endif
if ( V_157 -> V_3 < V_159 )
{
if ( F_32 ( V_157 , V_159 ) )
return V_160 ;
V_3 = V_159 ;
}
#if 0
{
printk(KERN_DEBUG "TX pkt type 0x%04x from %pM to %pM "
" data 0x%08x len %d\n",
((u_short *)skb->data)[6],
skb->data + 6, skb->data,
(int)skb->data, (int)skb->len);
}
#endif
F_33 ( V_158 ) ;
V_131 = V_21 -> V_94 % V_76 ;
V_21 -> V_68 [ V_131 ] -> V_103 = F_13 ( ( T_1 ) - V_157 -> V_3 ) ;
V_21 -> V_68 [ V_131 ] -> V_105 = 0x0000 ;
F_1 ( V_21 -> V_99 [ V_131 ] , ( T_1 * ) V_157 -> V_120 , V_3 ) ;
#if 0
{
int i, len;
len = skb->len > 64 ? 64 : skb->len;
len >>= 1;
for (i = 0; i < len; i += 8) {
int j;
printk(KERN_DEBUG "%04x:", i);
for (j = 0; (j < 8) && ((i+j) < len); j++) {
if (!(j & 1))
printk(" ");
printk("%04x", priv->tx_buff[entry][i+j]);
}
printk("\n");
}
}
#endif
V_21 -> V_68 [ V_131 ] -> V_100 = ( V_21 -> V_68 [ V_131 ] -> V_100 & 0xff00 ) | V_133 | V_101 | V_102 ;
F_34 ( V_157 ) ;
V_21 -> V_94 ++ ;
if ( ( V_21 -> V_94 >= V_76 ) && ( V_21 -> V_95 >= V_76 ) ) {
#if 0
printk(KERN_DEBUG "*** Subtracting TX_RING_SIZE from cur_tx (%d) and "
"dirty_tx (%d)\n", priv->cur_tx, priv->dirty_tx);
#endif
V_21 -> V_94 -= V_76 ;
V_21 -> V_95 -= V_76 ;
}
V_19 -> V_115 . V_161 += V_3 ;
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = V_90 | V_129 ;
if ( F_25 ( V_21 -> V_68 [ ( V_131 + 1 ) % V_76 ] -> V_100 ) != 0 ) {
F_20 ( V_19 ) ;
V_21 -> V_92 = 1 ;
}
F_35 ( V_158 ) ;
return V_160 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
int V_131 = V_21 -> V_93 % V_74 ;
int V_40 ;
while ( ! ( F_25 ( V_21 -> V_71 [ V_131 ] -> V_110 ) & V_111 ) ) {
int V_132 = F_25 ( V_21 -> V_71 [ V_131 ] -> V_110 ) ;
if ( V_132 != ( V_162 | V_163 ) ) {
if ( V_132 & V_163 )
V_19 -> V_115 . V_152 ++ ;
if ( V_132 & V_164 )
V_19 -> V_115 . V_165 ++ ;
if ( V_132 & V_166 )
V_19 -> V_115 . V_167 ++ ;
if ( V_132 & V_168 )
V_19 -> V_115 . V_169 ++ ;
if ( V_132 & V_170 )
V_19 -> V_115 . V_171 ++ ;
V_21 -> V_71 [ V_131 ] -> V_110 &= 0xff00 | V_162 | V_163 ;
} else {
short V_172 = F_13 ( V_21 -> V_71 [ V_131 ] -> V_113 ) ;
struct V_156 * V_157 ;
V_157 = F_36 ( V_172 + 2 ) ;
if ( V_157 == NULL ) {
F_11 ( V_48 L_15 ,
V_19 -> V_27 ) ;
for ( V_40 = 0 ; V_40 < V_74 ; V_40 ++ )
if ( F_25 ( V_21 -> V_71 [ ( V_131 + V_40 ) % V_74 ] -> V_110 ) & V_111 )
break;
if ( V_40 > V_74 - 2 ) {
V_19 -> V_115 . V_173 ++ ;
V_21 -> V_71 [ V_131 ] -> V_110 |= V_111 ;
V_21 -> V_93 ++ ;
}
break;
}
F_37 ( V_157 , 2 ) ;
F_38 ( V_157 , V_172 ) ;
F_39 ( V_157 , ( char * ) V_21 -> V_109 [ V_131 ] , V_172 ) ;
V_157 -> V_174 = F_40 ( V_157 , V_19 ) ;
#if 0
{
printk(KERN_DEBUG "RX pkt type 0x%04x from ",
((u_short *)skb->data)[6]);
{
u_char *ptr = &((u_char *)skb->data)[6];
printk("%pM", ptr);
}
printk(" to ");
{
u_char *ptr = (u_char *)skb->data;
printk("%pM", ptr);
}
printk(" data 0x%08x len %d\n", (int)skb->data, (int)skb->len);
}
#endif
F_41 ( V_157 ) ;
V_19 -> V_115 . V_175 ++ ;
V_19 -> V_115 . V_176 += V_172 ;
}
V_21 -> V_71 [ V_131 ] -> V_110 |= V_111 ;
V_131 = ( ++ V_21 -> V_93 ) % V_74 ;
}
V_21 -> V_93 = V_21 -> V_93 % V_74 ;
return 0 ;
}
static struct V_177 * F_42 ( struct V_18 * V_19 )
{
volatile struct V_23 * V_37 = (struct V_23 * ) V_19 -> V_12 ;
short V_178 ;
unsigned long V_158 ;
F_33 ( V_158 ) ;
V_178 = V_37 -> V_42 ;
V_37 -> V_42 = V_114 ;
V_19 -> V_115 . V_116 = F_13 ( V_37 -> V_44 ) ;
V_37 -> V_42 = V_178 ;
F_35 ( V_158 ) ;
return & V_19 -> V_115 ;
}
static void F_43 ( struct V_18 * V_19 )
{
volatile struct V_23 * V_37 = (struct V_23 * ) V_19 -> V_12 ;
if ( ! F_44 ( V_19 ) )
return;
F_20 ( V_19 ) ;
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = V_45 ;
F_14 ( V_19 ) ;
if ( V_19 -> V_158 & V_179 ) {
V_37 -> V_42 = V_65 ;
V_37 -> V_44 = V_180 ;
} else {
short V_181 [ 4 ] ;
int V_182 = F_45 ( V_19 ) ;
int V_40 ;
memset ( V_181 , ( V_182 == 0 ) ? 0 : - 1 ,
sizeof( V_181 ) ) ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
V_37 -> V_42 = V_58 + ( V_40 << 8 ) ;
V_37 -> V_44 = F_13 ( V_181 [ V_40 ] ) ;
}
V_37 -> V_42 = V_65 ;
V_37 -> V_44 = 0x0000 ;
}
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = V_90 | V_91 | V_155 ;
F_28 ( V_19 ) ;
}
static void T_6 F_46 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = F_47 ( V_6 ) ;
F_48 ( V_19 ) ;
F_4 ( F_49 ( V_19 -> V_12 ) , sizeof( struct V_23 ) ) ;
F_4 ( F_49 ( V_19 -> V_14 ) , V_25 ) ;
F_9 ( V_19 ) ;
}
static int T_7 F_50 ( void )
{
return F_51 ( & V_183 ) ;
}
static void T_8 F_52 ( void )
{
F_53 ( & V_183 ) ;
}
