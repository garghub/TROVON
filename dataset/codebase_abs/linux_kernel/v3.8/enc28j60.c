static int
F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
T_1 * V_5 = V_2 -> V_6 + 4 ;
T_1 * V_7 = V_2 -> V_6 ;
struct V_8 V_9 = {
. V_7 = V_7 ,
. V_5 = V_5 ,
. V_3 = V_10 + V_3 ,
} ;
struct V_11 V_12 ;
int V_13 ;
V_7 [ 0 ] = V_14 ;
V_7 [ 1 ] = V_7 [ 2 ] = V_7 [ 3 ] = 0 ;
F_2 ( & V_12 ) ;
F_3 ( & V_9 , & V_12 ) ;
V_13 = F_4 ( V_2 -> V_15 , & V_12 ) ;
if ( V_13 == 0 ) {
memcpy ( V_4 , & V_5 [ V_10 ] , V_3 ) ;
V_13 = V_12 . V_16 ;
}
if ( V_13 && F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_1 ,
__func__, ret) ;
return V_13 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 ,
const T_1 * V_4 )
{
int V_13 ;
if ( V_3 > V_17 - 1 || V_3 <= 0 )
V_13 = - V_18 ;
else {
V_2 -> V_6 [ 0 ] = V_19 ;
memcpy ( & V_2 -> V_6 [ 1 ] , V_4 , V_3 ) ;
V_13 = F_8 ( V_2 -> V_15 , V_2 -> V_6 , V_3 + 1 ) ;
if ( V_13 && F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_1 ,
__func__, ret) ;
}
return V_13 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_20 ,
T_1 V_21 )
{
T_1 V_7 [ 2 ] ;
T_1 V_5 [ 4 ] ;
T_1 V_22 = 0 ;
int V_13 ;
int V_23 = V_10 ;
if ( V_21 & V_24 )
V_23 ++ ;
V_7 [ 0 ] = V_20 | ( V_21 & V_25 ) ;
V_13 = F_10 ( V_2 -> V_15 , V_7 , 1 , V_5 , V_23 ) ;
if ( V_13 )
F_6 (KERN_DEBUG DRV_NAME L_1 ,
__func__, ret) ;
else
V_22 = V_5 [ V_23 - 1 ] ;
return V_22 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_20 ,
T_1 V_21 , T_1 V_22 )
{
int V_13 ;
V_2 -> V_6 [ 0 ] = V_20 | ( V_21 & V_25 ) ;
V_2 -> V_6 [ 1 ] = V_22 ;
V_13 = F_8 ( V_2 -> V_15 , V_2 -> V_6 , 2 ) ;
if ( V_13 && F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_1 ,
__func__, ret) ;
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_11 ( V_2 , V_26 , 0 , V_26 ) ;
F_14 ( 2000 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_21 )
{
T_1 V_27 = ( V_21 & V_28 ) >> 5 ;
if ( V_21 >= V_29 && V_21 <= V_30 )
return;
if ( ( V_27 & V_31 ) != ( V_2 -> V_32 & V_31 ) ) {
if ( V_27 & V_31 )
F_11 ( V_2 , V_33 , V_30 ,
V_31 ) ;
else
F_11 ( V_2 , V_34 , V_30 ,
V_31 ) ;
}
if ( ( V_27 & V_35 ) != ( V_2 -> V_32 & V_35 ) ) {
if ( V_27 & V_35 )
F_11 ( V_2 , V_33 , V_30 ,
V_35 ) ;
else
F_11 ( V_2 , V_34 , V_30 ,
V_35 ) ;
}
V_2 -> V_32 = V_27 ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 V_21 , T_1 V_36 )
{
F_15 ( V_2 , V_21 ) ;
F_11 ( V_2 , V_33 , V_21 , V_36 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
T_1 V_21 , T_1 V_36 )
{
F_18 ( & V_2 -> V_37 ) ;
F_16 ( V_2 , V_21 , V_36 ) ;
F_19 ( & V_2 -> V_37 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
T_1 V_21 , T_1 V_36 )
{
F_15 ( V_2 , V_21 ) ;
F_11 ( V_2 , V_34 , V_21 , V_36 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
T_1 V_21 , T_1 V_36 )
{
F_18 ( & V_2 -> V_37 ) ;
F_20 ( V_2 , V_21 , V_36 ) ;
F_19 ( & V_2 -> V_37 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
T_1 V_38 )
{
F_15 ( V_2 , V_38 ) ;
return F_9 ( V_2 , V_39 , V_38 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 V_38 )
{
int V_13 ;
F_18 ( & V_2 -> V_37 ) ;
V_13 = F_22 ( V_2 , V_38 ) ;
F_19 ( & V_2 -> V_37 ) ;
return V_13 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_1 V_38 )
{
int V_40 , V_41 ;
F_15 ( V_2 , V_38 ) ;
V_40 = F_9 ( V_2 , V_39 , V_38 ) ;
V_41 = F_9 ( V_2 , V_39 , V_38 + 1 ) ;
return ( V_41 << 8 ) | V_40 ;
}
static int F_25 ( struct V_1 * V_2 ,
T_1 V_38 )
{
int V_13 ;
F_18 ( & V_2 -> V_37 ) ;
V_13 = F_24 ( V_2 , V_38 ) ;
F_19 ( & V_2 -> V_37 ) ;
return V_13 ;
}
static void F_26 ( struct V_1 * V_2 ,
T_1 V_38 , T_1 V_4 )
{
F_15 ( V_2 , V_38 ) ;
F_11 ( V_2 , V_42 , V_38 , V_4 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
T_1 V_38 , T_1 V_4 )
{
F_18 ( & V_2 -> V_37 ) ;
F_26 ( V_2 , V_38 , V_4 ) ;
F_19 ( & V_2 -> V_37 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
T_1 V_38 , T_2 V_4 )
{
F_15 ( V_2 , V_38 ) ;
F_11 ( V_2 , V_42 , V_38 , ( T_1 ) V_4 ) ;
F_11 ( V_2 , V_42 , V_38 + 1 ,
( T_1 ) ( V_4 >> 8 ) ) ;
}
static void F_29 ( struct V_1 * V_2 ,
T_1 V_38 , T_2 V_4 )
{
F_18 ( & V_2 -> V_37 ) ;
F_28 ( V_2 , V_38 , V_4 ) ;
F_19 ( & V_2 -> V_37 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
T_2 V_21 , int V_3 , T_1 * V_4 )
{
F_18 ( & V_2 -> V_37 ) ;
F_28 ( V_2 , V_43 , V_21 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
T_2 V_44 ;
V_44 = F_24 ( V_2 , V_43 ) ;
if ( V_44 != V_21 )
F_6 (KERN_DEBUG DRV_NAME L_3
L_4 , __func__, reg, addr) ;
}
#endif
F_1 ( V_2 , V_3 , V_4 ) ;
F_19 ( & V_2 -> V_37 ) ;
}
static void
F_32 ( struct V_1 * V_2 , int V_3 , const T_1 * V_4 )
{
F_18 ( & V_2 -> V_37 ) ;
F_28 ( V_2 , V_45 , V_46 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
T_2 V_44 ;
V_44 = F_24 ( V_2 , V_45 ) ;
if ( V_44 != V_46 )
F_6 (KERN_DEBUG DRV_NAME
L_5 ,
__func__, reg, TXSTART_INIT) ;
}
#endif
F_28 ( V_2 , V_47 , V_46 + V_3 ) ;
F_11 ( V_2 , V_19 , 0 , 0x00 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_6 ,
__func__, nolock_regw_read(priv, EWRPTL)) ;
F_7 ( V_2 , V_3 , V_4 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_7 ,
__func__, nolock_regw_read(priv, EWRPTL), len) ;
F_19 ( & V_2 -> V_37 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_44 , T_1 V_36 , T_1 V_22 )
{
unsigned long V_48 = V_49 + V_50 ;
while ( ( F_22 ( V_2 , V_44 ) & V_36 ) != V_22 ) {
if ( F_34 ( V_49 , V_48 ) ) {
if ( F_5 ( V_2 ) )
F_35 ( & V_2 -> V_15 -> V_51 ,
L_8 , V_44 ) ;
return - V_52 ;
}
F_36 () ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , V_53 , V_54 , 0 ) ? 0 : 1 ;
}
static T_2 F_38 ( struct V_1 * V_2 , T_1 V_38 )
{
T_2 V_13 ;
F_18 ( & V_2 -> V_37 ) ;
F_26 ( V_2 , V_55 , V_38 ) ;
F_26 ( V_2 , V_56 , V_57 ) ;
F_37 ( V_2 ) ;
F_26 ( V_2 , V_56 , 0x00 ) ;
V_13 = F_24 ( V_2 , V_58 ) ;
F_19 ( & V_2 -> V_37 ) ;
return V_13 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_38 , T_2 V_4 )
{
int V_13 ;
F_18 ( & V_2 -> V_37 ) ;
F_26 ( V_2 , V_55 , V_38 ) ;
F_28 ( V_2 , V_59 , V_4 ) ;
V_13 = F_37 ( V_2 ) ;
F_19 ( & V_2 -> V_37 ) ;
return V_13 ;
}
static int F_40 ( struct V_60 * V_61 )
{
int V_13 ;
struct V_1 * V_2 = F_41 ( V_61 ) ;
F_18 ( & V_2 -> V_37 ) ;
if ( ! V_2 -> V_62 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_INFO DRV_NAME
L_9 ,
ndev->name, ndev->dev_addr) ;
F_26 ( V_2 , V_63 , V_61 -> V_64 [ 0 ] ) ;
F_26 ( V_2 , V_65 , V_61 -> V_64 [ 1 ] ) ;
F_26 ( V_2 , V_66 , V_61 -> V_64 [ 2 ] ) ;
F_26 ( V_2 , V_67 , V_61 -> V_64 [ 3 ] ) ;
F_26 ( V_2 , V_68 , V_61 -> V_64 [ 4 ] ) ;
F_26 ( V_2 , V_69 , V_61 -> V_64 [ 5 ] ) ;
V_13 = 0 ;
} else {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_10
L_11 , __func__) ;
V_13 = - V_70 ;
}
F_19 ( & V_2 -> V_37 ) ;
return V_13 ;
}
static int F_42 ( struct V_60 * V_51 , void * V_21 )
{
struct V_71 * V_38 = V_21 ;
if ( F_43 ( V_51 ) )
return - V_70 ;
if ( ! F_44 ( V_38 -> V_72 ) )
return - V_73 ;
V_51 -> V_74 &= ~ V_75 ;
memcpy ( V_51 -> V_64 , V_38 -> V_72 , V_51 -> V_76 ) ;
return F_40 ( V_51 ) ;
}
static void F_45 ( struct V_1 * V_2 , const char * V_12 )
{
F_18 ( & V_2 -> V_37 ) ;
F_6 (KERN_DEBUG DRV_NAME L_12
L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22 ,
msg, nolock_regb_read(priv, EREVID),
nolock_regb_read(priv, ECON1), nolock_regb_read(priv, ECON2),
nolock_regb_read(priv, ESTAT), nolock_regb_read(priv, EIR),
nolock_regb_read(priv, EIE), nolock_regb_read(priv, MACON1),
nolock_regb_read(priv, MACON3), nolock_regb_read(priv, MACON4),
nolock_regw_read(priv, ERXSTL), nolock_regw_read(priv, ERXNDL),
nolock_regw_read(priv, ERXWRPTL),
nolock_regw_read(priv, ERXRDPTL),
nolock_regb_read(priv, ERXFCON),
nolock_regb_read(priv, EPKTCNT),
nolock_regw_read(priv, MAMXFLL), nolock_regw_read(priv, ETXSTL),
nolock_regw_read(priv, ETXNDL),
nolock_regb_read(priv, MACLCON1),
nolock_regb_read(priv, MACLCON2),
nolock_regb_read(priv, MAPHSUP)) ;
F_19 ( & V_2 -> V_37 ) ;
}
static T_2 F_46 ( T_2 V_77 , T_2 V_78 , T_2 V_79 )
{
T_2 V_80 ;
if ( ( V_77 - 1 < V_78 ) || ( V_77 - 1 > V_79 ) )
V_80 = V_79 ;
else
V_80 = V_77 - 1 ;
return V_80 ;
}
static T_2 F_47 ( T_2 V_81 )
{
if ( V_81 + V_82 > V_83 )
return ( V_81 + V_82 ) - ( V_83 - V_84 + 1 ) ;
else
return V_81 + V_82 ;
}
static void F_48 ( struct V_1 * V_2 , T_2 V_78 , T_2 V_79 )
{
T_2 V_80 ;
if ( V_78 > 0x1FFF || V_79 > 0x1FFF || V_78 > V_79 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_ERR DRV_NAME L_23
L_24 , __func__, start, end) ;
return;
}
V_2 -> V_85 = V_78 ;
F_28 ( V_2 , V_86 , V_78 ) ;
V_80 = F_46 ( V_2 -> V_85 , V_78 , V_79 ) ;
F_28 ( V_2 , V_87 , V_80 ) ;
F_28 ( V_2 , V_88 , V_79 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_2 V_78 , T_2 V_79 )
{
if ( V_78 > 0x1FFF || V_79 > 0x1FFF || V_78 > V_79 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_ERR DRV_NAME L_25
L_24 , __func__, start, end) ;
return;
}
F_28 ( V_2 , V_89 , V_78 ) ;
F_28 ( V_2 , V_47 , V_79 ) ;
}
static void F_50 ( struct V_1 * V_2 , bool V_90 )
{
if ( F_5 ( V_2 ) )
F_35 ( & V_2 -> V_15 -> V_51 , L_26 ,
V_90 ? L_27 : L_28 ) ;
F_18 ( & V_2 -> V_37 ) ;
if ( V_90 ) {
F_20 ( V_2 , V_30 , V_91 ) ;
F_33 ( V_2 , V_92 , V_93 , 0 ) ;
F_33 ( V_2 , V_30 , V_94 , 0 ) ;
F_16 ( V_2 , V_95 , V_96 ) ;
} else {
F_20 ( V_2 , V_95 , V_96 ) ;
F_33 ( V_2 , V_92 , V_97 , V_97 ) ;
}
F_19 ( & V_2 -> V_37 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
T_1 V_44 ;
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_29 , __func__,
priv->full_duplex ? L_30 : L_31 ) ;
F_18 ( & V_2 -> V_37 ) ;
F_12 ( V_2 ) ;
F_11 ( V_2 , V_42 , V_30 , 0x00 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_62 = false ;
V_2 -> V_98 = 0 ;
V_2 -> V_99 = 0 ;
V_2 -> V_100 = V_101 ;
F_26 ( V_2 , V_95 , V_102 | V_103 ) ;
F_48 ( V_2 , V_84 , V_83 ) ;
F_49 ( V_2 , V_46 , V_104 ) ;
F_19 ( & V_2 -> V_37 ) ;
V_44 = F_23 ( V_2 , V_105 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_INFO DRV_NAME L_32 , reg) ;
if ( V_44 == 0x00 || V_44 == 0xff ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_33 ,
__func__, reg) ;
return 0 ;
}
F_27 ( V_2 , V_106 ,
V_107 | V_108 | V_109 ) ;
F_27 ( V_2 , V_110 ,
V_111 | V_112 | V_113 ) ;
if ( V_2 -> V_114 ) {
F_27 ( V_2 , V_115 ,
V_116 | V_117 |
V_118 | V_119 ) ;
F_27 ( V_2 , V_120 , 0x12 ) ;
F_27 ( V_2 , V_121 , 0x15 ) ;
} else {
F_27 ( V_2 , V_115 ,
V_116 | V_117 |
V_118 ) ;
F_27 ( V_2 , V_122 , 1 << 6 ) ;
F_29 ( V_2 , V_120 , 0x0C12 ) ;
F_27 ( V_2 , V_121 , 0x12 ) ;
}
F_29 ( V_2 , V_123 , V_124 ) ;
if ( ! F_39 ( V_2 , V_125 , V_126 ) )
return 0 ;
if ( V_2 -> V_114 ) {
if ( ! F_39 ( V_2 , V_127 , V_128 ) )
return 0 ;
if ( ! F_39 ( V_2 , V_129 , 0x00 ) )
return 0 ;
} else {
if ( ! F_39 ( V_2 , V_127 , 0x00 ) )
return 0 ;
if ( ! F_39 ( V_2 , V_129 , V_130 ) )
return 0 ;
}
if ( F_13 ( V_2 ) )
F_45 ( V_2 , L_34 ) ;
return 1 ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_35 ,
__func__) ;
F_39 ( V_2 , V_131 , V_132 | V_133 ) ;
F_18 ( & V_2 -> V_37 ) ;
F_20 ( V_2 , V_134 , V_135 | V_136 |
V_137 | V_138 | V_139 | V_140 ) ;
F_26 ( V_2 , V_29 , V_141 | V_142 | V_143 |
V_144 | V_145 | V_146 ) ;
F_16 ( V_2 , V_30 , V_91 ) ;
V_2 -> V_62 = true ;
F_19 ( & V_2 -> V_37 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_37 ) ;
F_26 ( V_2 , V_29 , 0x00 ) ;
F_20 ( V_2 , V_30 , V_91 ) ;
V_2 -> V_62 = false ;
F_19 ( & V_2 -> V_37 ) ;
}
static int
F_54 ( struct V_60 * V_61 , T_1 V_147 , T_2 V_148 , T_1 V_149 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
int V_13 = 0 ;
if ( ! V_2 -> V_62 ) {
if ( V_147 == V_150 && V_148 == V_151 )
V_2 -> V_114 = ( V_149 == V_152 ) ;
else {
if ( F_55 ( V_2 ) )
F_56 ( & V_61 -> V_51 ,
L_36 ) ;
V_13 = - V_153 ;
}
} else {
if ( F_55 ( V_2 ) )
F_56 ( & V_61 -> V_51 , L_37
L_38 ) ;
V_13 = - V_70 ;
}
return V_13 ;
}
static void F_57 ( struct V_1 * V_2 , T_1 V_154 [ V_155 ] )
{
int V_156 ;
V_156 = F_25 ( V_2 , V_47 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_39 ,
endptr + 1 ) ;
F_30 ( V_2 , V_156 + 1 , V_155 , V_154 ) ;
}
static void F_58 ( struct V_1 * V_2 , const char * V_12 ,
T_1 V_154 [ V_155 ] )
{
T_2 V_157 , V_158 ;
F_6 (KERN_DEBUG DRV_NAME L_40 , msg) ;
V_157 = V_154 [ 1 ] ;
V_157 <<= 8 ;
V_157 |= V_154 [ 0 ] ;
V_158 = V_154 [ 5 ] ;
V_158 <<= 8 ;
V_158 |= V_154 [ 4 ] ;
F_6 (KERN_DEBUG DRV_NAME L_41
L_42 , tmp1, tsv[2] & 0x0f , tmp2) ;
F_6 (KERN_DEBUG DRV_NAME L_43
L_44 , TSV_GETBIT(tsv, TSV_TXDONE),
TSV_GETBIT(tsv, TSV_TXCRCERROR),
TSV_GETBIT(tsv, TSV_TXLENCHKERROR),
TSV_GETBIT(tsv, TSV_TXLENOUTOFRANGE)) ;
F_6 (KERN_DEBUG DRV_NAME L_45
L_46 ,
TSV_GETBIT(tsv, TSV_TXMULTICAST),
TSV_GETBIT(tsv, TSV_TXBROADCAST),
TSV_GETBIT(tsv, TSV_TXPACKETDEFER),
TSV_GETBIT(tsv, TSV_TXEXDEFER)) ;
F_6 (KERN_DEBUG DRV_NAME L_47
L_48 ,
TSV_GETBIT(tsv, TSV_TXEXCOLLISION),
TSV_GETBIT(tsv, TSV_TXLATECOLLISION),
TSV_GETBIT(tsv, TSV_TXGIANT), TSV_GETBIT(tsv, TSV_TXUNDERRUN)) ;
F_6 (KERN_DEBUG DRV_NAME L_49
L_50 ,
TSV_GETBIT(tsv, TSV_TXCONTROLFRAME),
TSV_GETBIT(tsv, TSV_TXPAUSEFRAME),
TSV_GETBIT(tsv, TSV_BACKPRESSUREAPP),
TSV_GETBIT(tsv, TSV_TXVLANTAGFRAME)) ;
}
static void F_59 ( struct V_1 * V_2 , const char * V_12 ,
T_2 V_159 , int V_3 , T_2 V_160 )
{
F_6 (KERN_DEBUG DRV_NAME L_51 ,
msg, pk_ptr) ;
F_6 (KERN_DEBUG DRV_NAME L_52 , len,
RSV_GETBIT(sts, RSV_DRIBBLENIBBLE)) ;
F_6 (KERN_DEBUG DRV_NAME L_53
L_44 , RSV_GETBIT(sts, RSV_RXOK),
RSV_GETBIT(sts, RSV_CRCERROR),
RSV_GETBIT(sts, RSV_LENCHECKERR),
RSV_GETBIT(sts, RSV_LENOUTOFRANGE)) ;
F_6 (KERN_DEBUG DRV_NAME L_45
L_54 ,
RSV_GETBIT(sts, RSV_RXMULTICAST),
RSV_GETBIT(sts, RSV_RXBROADCAST),
RSV_GETBIT(sts, RSV_RXLONGEVDROPEV),
RSV_GETBIT(sts, RSV_CARRIEREV)) ;
F_6 (KERN_DEBUG DRV_NAME L_55
L_56 ,
RSV_GETBIT(sts, RSV_RXCONTROLFRAME),
RSV_GETBIT(sts, RSV_RXPAUSEFRAME),
RSV_GETBIT(sts, RSV_RXUNKNOWNOPCODE),
RSV_GETBIT(sts, RSV_RXTYPEVLAN)) ;
}
static void F_60 ( const char * V_12 , int V_3 , const char * V_4 )
{
F_6 (KERN_DEBUG DRV_NAME L_57 , msg, len) ;
F_61 ( V_161 , L_58 , V_162 , 16 , 1 ,
V_4 , V_3 , true ) ;
}
static void F_62 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
struct V_163 * V_164 = NULL ;
T_2 V_80 , V_165 , V_166 ;
T_1 V_167 [ V_82 ] ;
int V_3 ;
if ( F_63 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_59 ,
priv->next_pk_ptr) ;
if ( F_64 ( V_2 -> V_85 > V_83 ) ) {
if ( F_65 ( V_2 ) )
F_66 ( & V_61 -> V_51 ,
L_60 ,
V_168 , V_2 -> V_85 ) ;
F_18 ( & V_2 -> V_37 ) ;
F_20 ( V_2 , V_30 , V_91 ) ;
F_16 ( V_2 , V_30 , V_169 ) ;
F_20 ( V_2 , V_30 , V_169 ) ;
F_48 ( V_2 , V_84 , V_83 ) ;
F_20 ( V_2 , V_134 , V_139 ) ;
F_16 ( V_2 , V_30 , V_91 ) ;
F_19 ( & V_2 -> V_37 ) ;
V_61 -> V_170 . V_171 ++ ;
return;
}
F_30 ( V_2 , V_2 -> V_85 , sizeof( V_167 ) , V_167 ) ;
V_165 = V_167 [ 1 ] ;
V_165 <<= 8 ;
V_165 |= V_167 [ 0 ] ;
V_3 = V_167 [ 3 ] ;
V_3 <<= 8 ;
V_3 |= V_167 [ 2 ] ;
V_166 = V_167 [ 5 ] ;
V_166 <<= 8 ;
V_166 |= V_167 [ 4 ] ;
if ( F_63 ( V_2 ) )
F_59 ( V_2 , V_168 , V_165 , V_3 , V_166 ) ;
if ( ! F_67 ( V_166 , V_172 ) || V_3 > V_124 ) {
if ( F_65 ( V_2 ) )
F_66 ( & V_61 -> V_51 , L_61 , V_166 ) ;
V_61 -> V_170 . V_171 ++ ;
if ( F_67 ( V_166 , V_173 ) )
V_61 -> V_170 . V_174 ++ ;
if ( F_67 ( V_166 , V_175 ) )
V_61 -> V_170 . V_176 ++ ;
if ( V_3 > V_124 )
V_61 -> V_170 . V_177 ++ ;
} else {
V_164 = F_68 ( V_61 , V_3 + V_178 ) ;
if ( ! V_164 ) {
if ( F_65 ( V_2 ) )
F_66 ( & V_61 -> V_51 ,
L_62 ) ;
V_61 -> V_170 . V_179 ++ ;
} else {
F_69 ( V_164 , V_178 ) ;
F_30 ( V_2 ,
F_47 ( V_2 -> V_85 ) ,
V_3 , F_70 ( V_164 , V_3 ) ) ;
if ( F_71 ( V_2 ) )
F_60 ( V_168 , V_164 -> V_3 , V_164 -> V_4 ) ;
V_164 -> V_180 = F_72 ( V_164 , V_61 ) ;
V_61 -> V_170 . V_181 ++ ;
V_61 -> V_170 . V_182 += V_3 ;
F_73 ( V_164 ) ;
}
}
V_80 = F_46 ( V_165 , V_84 , V_83 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_63 ,
__func__, erxrdpt) ;
F_18 ( & V_2 -> V_37 ) ;
F_28 ( V_2 , V_87 , V_80 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
T_2 V_44 ;
V_44 = F_24 ( V_2 , V_87 ) ;
if ( V_44 != V_80 )
F_6 (KERN_DEBUG DRV_NAME L_64
L_65 , __func__,
reg, erxrdpt) ;
}
#endif
V_2 -> V_85 = V_165 ;
F_16 ( V_2 , V_95 , V_183 ) ;
F_19 ( & V_2 -> V_37 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_184 , V_185 , V_186 , V_187 , V_188 ;
int V_189 ;
F_18 ( & V_2 -> V_37 ) ;
V_184 = F_22 ( V_2 , V_190 ) ;
if ( V_184 >= 255 )
V_189 = - 1 ;
else {
V_185 = F_24 ( V_2 , V_86 ) ;
V_186 = F_24 ( V_2 , V_88 ) ;
V_187 = F_24 ( V_2 , V_191 ) ;
V_188 = F_24 ( V_2 , V_87 ) ;
if ( V_187 > V_188 )
V_189 = ( V_186 - V_185 ) - ( V_187 - V_188 ) ;
else if ( V_187 == V_188 )
V_189 = ( V_186 - V_185 ) ;
else
V_189 = V_188 - V_187 - 1 ;
}
F_19 ( & V_2 -> V_37 ) ;
if ( F_63 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_66 ,
__func__, free_space) ;
return V_189 ;
}
static void F_75 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
T_2 V_44 ;
int V_149 ;
V_44 = F_38 ( V_2 , V_192 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_67
L_68 , __func__,
enc28j60_phy_read(priv, PHSTAT1), reg) ;
V_149 = V_44 & V_193 ;
if ( V_44 & V_194 ) {
F_76 ( V_61 ) ;
if ( F_77 ( V_2 ) )
F_78 ( & V_61 -> V_51 , L_69 ,
V_149 ? L_70 : L_71 ) ;
} else {
if ( F_79 ( V_2 ) )
F_78 ( & V_61 -> V_51 , L_72 ) ;
F_80 ( V_61 ) ;
}
}
static void F_81 ( struct V_60 * V_61 , bool V_195 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
if ( V_195 )
V_61 -> V_170 . V_196 ++ ;
else
V_61 -> V_170 . V_197 ++ ;
if ( V_2 -> V_198 ) {
if ( ! V_195 )
V_61 -> V_170 . V_199 += V_2 -> V_198 -> V_3 ;
F_82 ( V_2 -> V_198 ) ;
V_2 -> V_198 = NULL ;
}
F_21 ( V_2 , V_30 , V_94 ) ;
F_83 ( V_61 ) ;
}
static int F_84 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
int V_200 , V_13 ;
V_200 = F_23 ( V_2 , V_190 ) ;
if ( V_200 && F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_73 , pk_counter) ;
if ( V_200 > V_2 -> V_99 ) {
V_2 -> V_99 = V_200 ;
if ( F_63 ( V_2 ) && V_2 -> V_99 > 1 )
F_6 (KERN_DEBUG DRV_NAME L_74 ,
priv->max_pk_counter) ;
}
V_13 = V_200 ;
while ( V_200 -- > 0 )
F_62 ( V_61 ) ;
return V_13 ;
}
static void F_86 ( struct V_201 * V_202 )
{
struct V_1 * V_2 =
F_87 ( V_202 , struct V_1 , V_203 ) ;
struct V_60 * V_61 = V_2 -> V_204 ;
int V_205 , V_206 ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_21 ( V_2 , V_29 , V_141 ) ;
do {
V_206 = 0 ;
V_205 = F_23 ( V_2 , V_134 ) ;
if ( ( V_205 & V_135 ) != 0 ) {
V_206 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_75 , loop) ;
F_21 ( V_2 , V_134 , V_135 ) ;
}
if ( ( V_205 & V_136 ) != 0 ) {
V_206 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_76 , loop) ;
F_75 ( V_61 ) ;
F_38 ( V_2 , V_207 ) ;
}
if ( ( V_205 & V_137 ) != 0 ) {
bool V_195 = false ;
V_206 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_77 , loop) ;
V_2 -> V_98 = 0 ;
if ( F_23 ( V_2 , V_92 ) & V_208 ) {
if ( F_88 ( V_2 ) )
F_66 ( & V_61 -> V_51 ,
L_78 ) ;
V_195 = true ;
}
if ( F_89 ( V_2 ) ) {
T_1 V_154 [ V_155 ] ;
F_57 ( V_2 , V_154 ) ;
F_58 ( V_2 , L_79 , V_154 ) ;
}
F_81 ( V_61 , V_195 ) ;
F_21 ( V_2 , V_134 , V_137 ) ;
}
if ( ( V_205 & V_138 ) != 0 ) {
T_1 V_154 [ V_155 ] ;
V_206 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_80 , loop) ;
F_21 ( V_2 , V_30 , V_94 ) ;
F_57 ( V_2 , V_154 ) ;
if ( F_88 ( V_2 ) )
F_58 ( V_2 , L_81 , V_154 ) ;
F_18 ( & V_2 -> V_37 ) ;
F_16 ( V_2 , V_30 , V_209 ) ;
F_20 ( V_2 , V_30 , V_209 ) ;
F_49 ( V_2 , V_46 , V_104 ) ;
F_19 ( & V_2 -> V_37 ) ;
if ( F_90 ( V_154 , V_210 ) ) {
if ( F_88 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_82 ,
priv->tx_retry_count) ;
if ( V_2 -> V_98 ++ < V_211 )
F_17 ( V_2 , V_30 ,
V_94 ) ;
else
F_81 ( V_61 , true ) ;
} else
F_81 ( V_61 , true ) ;
F_21 ( V_2 , V_134 , V_138 ) ;
}
if ( ( V_205 & V_139 ) != 0 ) {
V_206 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_83 , loop) ;
if ( F_74 ( V_2 ) <= 0 ) {
if ( F_65 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_84 ) ;
V_61 -> V_170 . V_179 ++ ;
}
F_21 ( V_2 , V_134 , V_139 ) ;
}
if ( F_84 ( V_61 ) )
V_206 ++ ;
} while ( V_206 );
F_17 ( V_2 , V_29 , V_141 ) ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_85 , __func__) ;
}
static void F_91 ( struct V_1 * V_2 )
{
if ( F_92 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_86 , priv->tx_skb->len) ;
if ( F_71 ( V_2 ) )
F_60 ( V_168 ,
V_2 -> V_198 -> V_3 , V_2 -> V_198 -> V_4 ) ;
F_32 ( V_2 , V_2 -> V_198 -> V_3 , V_2 -> V_198 -> V_4 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
int V_212 , V_213 ;
T_1 V_214 [ 64 ] ;
int V_215 ;
V_212 = V_2 -> V_198 -> V_3 ;
if ( V_212 > sizeof( V_214 ) )
V_212 = sizeof( V_214 ) ;
F_30 ( V_2 , V_46 + 1 , V_212 , V_214 ) ;
V_215 = 1 ;
for ( V_213 = 0 ; V_213 < V_212 ; V_213 ++ ) {
if ( V_2 -> V_198 -> V_4 [ V_213 ] != V_214 [ V_213 ] ) {
F_6 (KERN_DEBUG DRV_NAME
L_87
L_88 , k,
priv->tx_skb->data[k], test_buf[k]) ;
V_215 = 0 ;
}
}
if ( ! V_215 )
F_6 (KERN_DEBUG DRV_NAME L_89
L_90 ) ;
}
#endif
F_17 ( V_2 , V_30 , V_94 ) ;
}
static T_3 F_93 ( struct V_163 * V_164 ,
struct V_60 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
if ( F_92 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_94 ( V_51 ) ;
V_2 -> V_198 = V_164 ;
F_95 ( & V_2 -> V_216 ) ;
return V_217 ;
}
static void F_96 ( struct V_201 * V_202 )
{
struct V_1 * V_2 =
F_87 ( V_202 , struct V_1 , V_216 ) ;
F_91 ( V_2 ) ;
}
static T_4 F_97 ( int V_218 , void * V_219 )
{
struct V_1 * V_2 = V_219 ;
F_95 ( & V_2 -> V_203 ) ;
return V_220 ;
}
static void F_98 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
if ( F_99 ( V_2 ) )
F_66 ( & V_61 -> V_51 , V_221 L_91 ) ;
V_61 -> V_170 . V_196 ++ ;
F_95 ( & V_2 -> V_222 ) ;
}
static int F_100 ( struct V_60 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
if ( ! F_44 ( V_51 -> V_64 ) ) {
if ( F_77 ( V_2 ) )
F_66 ( & V_51 -> V_51 , L_92 ,
V_51 -> V_64 ) ;
return - V_73 ;
}
F_50 ( V_2 , false ) ;
F_53 ( V_2 ) ;
if ( ! F_51 ( V_2 ) ) {
if ( F_77 ( V_2 ) )
F_66 ( & V_51 -> V_51 , L_93 ) ;
return - V_18 ;
}
F_40 ( V_51 ) ;
F_52 ( V_2 ) ;
F_75 ( V_51 ) ;
F_101 ( V_51 ) ;
return 0 ;
}
static int F_102 ( struct V_60 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_53 ( V_2 ) ;
F_50 ( V_2 , true ) ;
F_94 ( V_51 ) ;
return 0 ;
}
static void F_103 ( struct V_60 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
int V_223 = V_2 -> V_100 ;
if ( V_51 -> V_224 & V_225 ) {
if ( F_55 ( V_2 ) )
F_78 ( & V_51 -> V_51 , L_94 ) ;
V_2 -> V_100 = V_226 ;
} else if ( ( V_51 -> V_224 & V_227 ) || ! F_104 ( V_51 ) ) {
if ( F_55 ( V_2 ) )
F_78 ( & V_51 -> V_51 , L_95 ,
( V_51 -> V_224 & V_227 ) ? L_96 : L_97 ) ;
V_2 -> V_100 = V_228 ;
} else {
if ( F_55 ( V_2 ) )
F_78 ( & V_51 -> V_51 , L_98 ) ;
V_2 -> V_100 = V_101 ;
}
if ( V_223 != V_2 -> V_100 )
F_95 ( & V_2 -> V_229 ) ;
}
static void F_105 ( struct V_201 * V_202 )
{
struct V_1 * V_2 =
F_87 ( V_202 , struct V_1 , V_229 ) ;
if ( V_2 -> V_100 == V_226 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_99 ) ;
F_27 ( V_2 , V_106 , 0x00 ) ;
} else if ( V_2 -> V_100 == V_228 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_100 ) ;
F_27 ( V_2 , V_106 ,
V_107 | V_108 |
V_109 | V_230 ) ;
} else {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_101 ) ;
F_27 ( V_2 , V_106 ,
V_107 | V_108 |
V_109 ) ;
}
}
static void F_106 ( struct V_201 * V_202 )
{
struct V_1 * V_2 =
F_87 ( V_202 , struct V_1 , V_222 ) ;
struct V_60 * V_61 = V_2 -> V_204 ;
int V_13 ;
F_107 () ;
if ( F_43 ( V_61 ) ) {
F_102 ( V_61 ) ;
V_13 = F_100 ( V_61 ) ;
if ( F_64 ( V_13 ) ) {
F_78 ( & V_61 -> V_51 , L_102 , V_13 ) ;
F_108 ( V_61 ) ;
}
}
F_109 () ;
}
static void
F_110 ( struct V_60 * V_51 , struct V_231 * V_232 )
{
F_111 ( V_232 -> V_233 , V_221 , sizeof( V_232 -> V_233 ) ) ;
F_111 ( V_232 -> V_234 , V_235 , sizeof( V_232 -> V_234 ) ) ;
F_111 ( V_232 -> V_236 ,
F_112 ( V_51 -> V_51 . V_237 ) , sizeof( V_232 -> V_236 ) ) ;
}
static int
F_113 ( struct V_60 * V_51 , struct V_238 * V_239 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
V_239 -> V_240 = V_241 ;
V_239 -> V_242 = V_243
| V_244
| V_245 ;
F_114 ( V_239 , V_151 ) ;
V_239 -> V_149 = V_2 -> V_114 ? V_152 : V_246 ;
V_239 -> V_247 = V_248 ;
V_239 -> V_147 = V_150 ;
return 0 ;
}
static int
F_115 ( struct V_60 * V_51 , struct V_238 * V_239 )
{
return F_54 ( V_51 , V_239 -> V_147 ,
F_116 ( V_239 ) , V_239 -> V_149 ) ;
}
static T_5 F_117 ( struct V_60 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
return V_2 -> V_249 ;
}
static void F_118 ( struct V_60 * V_51 , T_5 V_22 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
V_2 -> V_249 = V_22 ;
}
static int F_119 ( struct V_60 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
return F_51 ( V_2 ) ;
}
static int F_120 ( struct V_250 * V_15 )
{
struct V_60 * V_51 ;
struct V_1 * V_2 ;
int V_13 = 0 ;
if ( F_5 ( & V_251 ) )
F_78 ( & V_15 -> V_51 , V_221 L_103 ,
V_235 ) ;
V_51 = F_121 ( sizeof( struct V_1 ) ) ;
if ( ! V_51 ) {
V_13 = - V_252 ;
goto V_253;
}
V_2 = F_41 ( V_51 ) ;
V_2 -> V_204 = V_51 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_249 = F_122 ( V_251 . V_249 ,
V_254 ) ;
F_123 ( & V_2 -> V_37 ) ;
F_124 ( & V_2 -> V_216 , F_96 ) ;
F_124 ( & V_2 -> V_229 , F_105 ) ;
F_124 ( & V_2 -> V_203 , F_86 ) ;
F_124 ( & V_2 -> V_222 , F_106 ) ;
F_125 ( & V_15 -> V_51 , V_2 ) ;
F_126 ( V_51 , & V_15 -> V_51 ) ;
if ( ! F_119 ( V_51 ) ) {
if ( F_127 ( V_2 ) )
F_78 ( & V_15 -> V_51 , V_221 L_104 ) ;
V_13 = - V_255 ;
goto V_256;
}
F_128 ( V_51 ) ;
F_40 ( V_51 ) ;
V_13 = F_129 ( V_15 -> V_218 , F_97 , 0 , V_221 , V_2 ) ;
if ( V_13 < 0 ) {
if ( F_127 ( V_2 ) )
F_66 ( & V_15 -> V_51 , V_221 L_105
L_106 , V_15 -> V_218 , V_13 ) ;
goto V_256;
}
V_51 -> V_257 = V_258 ;
V_51 -> V_218 = V_15 -> V_218 ;
V_51 -> V_259 = & V_260 ;
V_51 -> V_261 = V_262 ;
F_130 ( V_51 , & V_263 ) ;
F_50 ( V_2 , true ) ;
V_13 = F_131 ( V_51 ) ;
if ( V_13 ) {
if ( F_127 ( V_2 ) )
F_66 ( & V_15 -> V_51 , L_107 V_221
L_108 , V_13 ) ;
goto V_264;
}
F_78 ( & V_51 -> V_51 , V_221 L_109 ) ;
return 0 ;
V_264:
F_132 ( V_15 -> V_218 , V_2 ) ;
V_256:
F_133 ( V_51 ) ;
V_253:
return V_13 ;
}
static int F_134 ( struct V_250 * V_15 )
{
struct V_1 * V_2 = F_135 ( & V_15 -> V_51 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_110 ) ;
F_136 ( V_2 -> V_204 ) ;
F_132 ( V_15 -> V_218 , V_2 ) ;
F_133 ( V_2 -> V_204 ) ;
return 0 ;
}
static int T_6 F_137 ( void )
{
V_50 = F_138 ( 20 ) ;
return F_139 ( & V_265 ) ;
}
static void T_7 F_140 ( void )
{
F_141 ( & V_265 ) ;
}
