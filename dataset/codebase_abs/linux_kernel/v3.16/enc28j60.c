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
memcpy ( V_51 -> V_64 , V_38 -> V_72 , V_51 -> V_74 ) ;
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
static T_2 F_46 ( T_2 V_75 , T_2 V_76 , T_2 V_77 )
{
T_2 V_78 ;
if ( ( V_75 - 1 < V_76 ) || ( V_75 - 1 > V_77 ) )
V_78 = V_77 ;
else
V_78 = V_75 - 1 ;
return V_78 ;
}
static T_2 F_47 ( T_2 V_79 )
{
if ( V_79 + V_80 > V_81 )
return ( V_79 + V_80 ) - ( V_81 - V_82 + 1 ) ;
else
return V_79 + V_80 ;
}
static void F_48 ( struct V_1 * V_2 , T_2 V_76 , T_2 V_77 )
{
T_2 V_78 ;
if ( V_76 > 0x1FFF || V_77 > 0x1FFF || V_76 > V_77 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_ERR DRV_NAME L_23
L_24 , __func__, start, end) ;
return;
}
V_2 -> V_83 = V_76 ;
F_28 ( V_2 , V_84 , V_76 ) ;
V_78 = F_46 ( V_2 -> V_83 , V_76 , V_77 ) ;
F_28 ( V_2 , V_85 , V_78 ) ;
F_28 ( V_2 , V_86 , V_77 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_2 V_76 , T_2 V_77 )
{
if ( V_76 > 0x1FFF || V_77 > 0x1FFF || V_76 > V_77 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_ERR DRV_NAME L_25
L_24 , __func__, start, end) ;
return;
}
F_28 ( V_2 , V_87 , V_76 ) ;
F_28 ( V_2 , V_47 , V_77 ) ;
}
static void F_50 ( struct V_1 * V_2 , bool V_88 )
{
if ( F_5 ( V_2 ) )
F_35 ( & V_2 -> V_15 -> V_51 , L_26 ,
V_88 ? L_27 : L_28 ) ;
F_18 ( & V_2 -> V_37 ) ;
if ( V_88 ) {
F_20 ( V_2 , V_30 , V_89 ) ;
F_33 ( V_2 , V_90 , V_91 , 0 ) ;
F_33 ( V_2 , V_30 , V_92 , 0 ) ;
F_16 ( V_2 , V_93 , V_94 ) ;
} else {
F_20 ( V_2 , V_93 , V_94 ) ;
F_33 ( V_2 , V_90 , V_95 , V_95 ) ;
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
V_2 -> V_96 = 0 ;
V_2 -> V_97 = 0 ;
V_2 -> V_98 = V_99 ;
F_26 ( V_2 , V_93 , V_100 | V_101 ) ;
F_48 ( V_2 , V_82 , V_81 ) ;
F_49 ( V_2 , V_46 , V_102 ) ;
F_19 ( & V_2 -> V_37 ) ;
V_44 = F_23 ( V_2 , V_103 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_INFO DRV_NAME L_32 , reg) ;
if ( V_44 == 0x00 || V_44 == 0xff ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_33 ,
__func__, reg) ;
return 0 ;
}
F_27 ( V_2 , V_104 ,
V_105 | V_106 | V_107 ) ;
F_27 ( V_2 , V_108 ,
V_109 | V_110 | V_111 ) ;
if ( V_2 -> V_112 ) {
F_27 ( V_2 , V_113 ,
V_114 | V_115 |
V_116 | V_117 ) ;
F_27 ( V_2 , V_118 , 0x12 ) ;
F_27 ( V_2 , V_119 , 0x15 ) ;
} else {
F_27 ( V_2 , V_113 ,
V_114 | V_115 |
V_116 ) ;
F_27 ( V_2 , V_120 , 1 << 6 ) ;
F_29 ( V_2 , V_118 , 0x0C12 ) ;
F_27 ( V_2 , V_119 , 0x12 ) ;
}
F_29 ( V_2 , V_121 , V_122 ) ;
if ( ! F_39 ( V_2 , V_123 , V_124 ) )
return 0 ;
if ( V_2 -> V_112 ) {
if ( ! F_39 ( V_2 , V_125 , V_126 ) )
return 0 ;
if ( ! F_39 ( V_2 , V_127 , 0x00 ) )
return 0 ;
} else {
if ( ! F_39 ( V_2 , V_125 , 0x00 ) )
return 0 ;
if ( ! F_39 ( V_2 , V_127 , V_128 ) )
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
F_39 ( V_2 , V_129 , V_130 | V_131 ) ;
F_18 ( & V_2 -> V_37 ) ;
F_20 ( V_2 , V_132 , V_133 | V_134 |
V_135 | V_136 | V_137 | V_138 ) ;
F_26 ( V_2 , V_29 , V_139 | V_140 | V_141 |
V_142 | V_143 | V_144 ) ;
F_16 ( V_2 , V_30 , V_89 ) ;
V_2 -> V_62 = true ;
F_19 ( & V_2 -> V_37 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_37 ) ;
F_26 ( V_2 , V_29 , 0x00 ) ;
F_20 ( V_2 , V_30 , V_89 ) ;
V_2 -> V_62 = false ;
F_19 ( & V_2 -> V_37 ) ;
}
static int
F_54 ( struct V_60 * V_61 , T_1 V_145 , T_2 V_146 , T_1 V_147 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
int V_13 = 0 ;
if ( ! V_2 -> V_62 ) {
if ( V_145 == V_148 && V_146 == V_149 )
V_2 -> V_112 = ( V_147 == V_150 ) ;
else {
if ( F_55 ( V_2 ) )
F_56 ( & V_61 -> V_51 ,
L_36 ) ;
V_13 = - V_151 ;
}
} else {
if ( F_55 ( V_2 ) )
F_56 ( & V_61 -> V_51 , L_37
L_38 ) ;
V_13 = - V_70 ;
}
return V_13 ;
}
static void F_57 ( struct V_1 * V_2 , T_1 V_152 [ V_153 ] )
{
int V_154 ;
V_154 = F_25 ( V_2 , V_47 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_39 ,
endptr + 1 ) ;
F_30 ( V_2 , V_154 + 1 , V_153 , V_152 ) ;
}
static void F_58 ( struct V_1 * V_2 , const char * V_12 ,
T_1 V_152 [ V_153 ] )
{
T_2 V_155 , V_156 ;
F_6 (KERN_DEBUG DRV_NAME L_40 , msg) ;
V_155 = V_152 [ 1 ] ;
V_155 <<= 8 ;
V_155 |= V_152 [ 0 ] ;
V_156 = V_152 [ 5 ] ;
V_156 <<= 8 ;
V_156 |= V_152 [ 4 ] ;
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
T_2 V_157 , int V_3 , T_2 V_158 )
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
F_61 ( V_159 , L_58 , V_160 , 16 , 1 ,
V_4 , V_3 , true ) ;
}
static void F_62 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
struct V_161 * V_162 = NULL ;
T_2 V_78 , V_163 , V_164 ;
T_1 V_165 [ V_80 ] ;
int V_3 ;
if ( F_63 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_59 ,
priv->next_pk_ptr) ;
if ( F_64 ( V_2 -> V_83 > V_81 ) ) {
if ( F_65 ( V_2 ) )
F_66 ( & V_61 -> V_51 ,
L_60 ,
V_166 , V_2 -> V_83 ) ;
F_18 ( & V_2 -> V_37 ) ;
F_20 ( V_2 , V_30 , V_89 ) ;
F_16 ( V_2 , V_30 , V_167 ) ;
F_20 ( V_2 , V_30 , V_167 ) ;
F_48 ( V_2 , V_82 , V_81 ) ;
F_20 ( V_2 , V_132 , V_137 ) ;
F_16 ( V_2 , V_30 , V_89 ) ;
F_19 ( & V_2 -> V_37 ) ;
V_61 -> V_168 . V_169 ++ ;
return;
}
F_30 ( V_2 , V_2 -> V_83 , sizeof( V_165 ) , V_165 ) ;
V_163 = V_165 [ 1 ] ;
V_163 <<= 8 ;
V_163 |= V_165 [ 0 ] ;
V_3 = V_165 [ 3 ] ;
V_3 <<= 8 ;
V_3 |= V_165 [ 2 ] ;
V_164 = V_165 [ 5 ] ;
V_164 <<= 8 ;
V_164 |= V_165 [ 4 ] ;
if ( F_63 ( V_2 ) )
F_59 ( V_2 , V_166 , V_163 , V_3 , V_164 ) ;
if ( ! F_67 ( V_164 , V_170 ) || V_3 > V_122 ) {
if ( F_65 ( V_2 ) )
F_66 ( & V_61 -> V_51 , L_61 , V_164 ) ;
V_61 -> V_168 . V_169 ++ ;
if ( F_67 ( V_164 , V_171 ) )
V_61 -> V_168 . V_172 ++ ;
if ( F_67 ( V_164 , V_173 ) )
V_61 -> V_168 . V_174 ++ ;
if ( V_3 > V_122 )
V_61 -> V_168 . V_175 ++ ;
} else {
V_162 = F_68 ( V_61 , V_3 + V_176 ) ;
if ( ! V_162 ) {
if ( F_65 ( V_2 ) )
F_66 ( & V_61 -> V_51 ,
L_62 ) ;
V_61 -> V_168 . V_177 ++ ;
} else {
F_69 ( V_162 , V_176 ) ;
F_30 ( V_2 ,
F_47 ( V_2 -> V_83 ) ,
V_3 , F_70 ( V_162 , V_3 ) ) ;
if ( F_71 ( V_2 ) )
F_60 ( V_166 , V_162 -> V_3 , V_162 -> V_4 ) ;
V_162 -> V_178 = F_72 ( V_162 , V_61 ) ;
V_61 -> V_168 . V_179 ++ ;
V_61 -> V_168 . V_180 += V_3 ;
F_73 ( V_162 ) ;
}
}
V_78 = F_46 ( V_163 , V_82 , V_81 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_63 ,
__func__, erxrdpt) ;
F_18 ( & V_2 -> V_37 ) ;
F_28 ( V_2 , V_85 , V_78 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
T_2 V_44 ;
V_44 = F_24 ( V_2 , V_85 ) ;
if ( V_44 != V_78 )
F_6 (KERN_DEBUG DRV_NAME L_64
L_65 , __func__,
reg, erxrdpt) ;
}
#endif
V_2 -> V_83 = V_163 ;
F_16 ( V_2 , V_93 , V_181 ) ;
F_19 ( & V_2 -> V_37 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_182 , V_183 , V_184 , V_185 , V_186 ;
int V_187 ;
F_18 ( & V_2 -> V_37 ) ;
V_182 = F_22 ( V_2 , V_188 ) ;
if ( V_182 >= 255 )
V_187 = - 1 ;
else {
V_183 = F_24 ( V_2 , V_84 ) ;
V_184 = F_24 ( V_2 , V_86 ) ;
V_185 = F_24 ( V_2 , V_189 ) ;
V_186 = F_24 ( V_2 , V_85 ) ;
if ( V_185 > V_186 )
V_187 = ( V_184 - V_183 ) - ( V_185 - V_186 ) ;
else if ( V_185 == V_186 )
V_187 = ( V_184 - V_183 ) ;
else
V_187 = V_186 - V_185 - 1 ;
}
F_19 ( & V_2 -> V_37 ) ;
if ( F_63 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_66 ,
__func__, free_space) ;
return V_187 ;
}
static void F_75 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
T_2 V_44 ;
int V_147 ;
V_44 = F_38 ( V_2 , V_190 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_67
L_68 , __func__,
enc28j60_phy_read(priv, PHSTAT1), reg) ;
V_147 = V_44 & V_191 ;
if ( V_44 & V_192 ) {
F_76 ( V_61 ) ;
if ( F_77 ( V_2 ) )
F_78 ( & V_61 -> V_51 , L_69 ,
V_147 ? L_70 : L_71 ) ;
} else {
if ( F_79 ( V_2 ) )
F_78 ( & V_61 -> V_51 , L_72 ) ;
F_80 ( V_61 ) ;
}
}
static void F_81 ( struct V_60 * V_61 , bool V_193 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
if ( V_193 )
V_61 -> V_168 . V_194 ++ ;
else
V_61 -> V_168 . V_195 ++ ;
if ( V_2 -> V_196 ) {
if ( ! V_193 )
V_61 -> V_168 . V_197 += V_2 -> V_196 -> V_3 ;
F_82 ( V_2 -> V_196 ) ;
V_2 -> V_196 = NULL ;
}
F_21 ( V_2 , V_30 , V_92 ) ;
F_83 ( V_61 ) ;
}
static int F_84 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
int V_198 , V_13 ;
V_198 = F_23 ( V_2 , V_188 ) ;
if ( V_198 && F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_73 , pk_counter) ;
if ( V_198 > V_2 -> V_97 ) {
V_2 -> V_97 = V_198 ;
if ( F_63 ( V_2 ) && V_2 -> V_97 > 1 )
F_6 (KERN_DEBUG DRV_NAME L_74 ,
priv->max_pk_counter) ;
}
V_13 = V_198 ;
while ( V_198 -- > 0 )
F_62 ( V_61 ) ;
return V_13 ;
}
static void F_86 ( struct V_199 * V_200 )
{
struct V_1 * V_2 =
F_87 ( V_200 , struct V_1 , V_201 ) ;
struct V_60 * V_61 = V_2 -> V_202 ;
int V_203 , V_204 ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_21 ( V_2 , V_29 , V_139 ) ;
do {
V_204 = 0 ;
V_203 = F_23 ( V_2 , V_132 ) ;
if ( ( V_203 & V_133 ) != 0 ) {
V_204 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_75 , loop) ;
F_21 ( V_2 , V_132 , V_133 ) ;
}
if ( ( V_203 & V_134 ) != 0 ) {
V_204 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_76 , loop) ;
F_75 ( V_61 ) ;
F_38 ( V_2 , V_205 ) ;
}
if ( ( V_203 & V_135 ) != 0 ) {
bool V_193 = false ;
V_204 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_77 , loop) ;
V_2 -> V_96 = 0 ;
if ( F_23 ( V_2 , V_90 ) & V_206 ) {
if ( F_88 ( V_2 ) )
F_66 ( & V_61 -> V_51 ,
L_78 ) ;
V_193 = true ;
}
if ( F_89 ( V_2 ) ) {
T_1 V_152 [ V_153 ] ;
F_57 ( V_2 , V_152 ) ;
F_58 ( V_2 , L_79 , V_152 ) ;
}
F_81 ( V_61 , V_193 ) ;
F_21 ( V_2 , V_132 , V_135 ) ;
}
if ( ( V_203 & V_136 ) != 0 ) {
T_1 V_152 [ V_153 ] ;
V_204 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_80 , loop) ;
F_21 ( V_2 , V_30 , V_92 ) ;
F_57 ( V_2 , V_152 ) ;
if ( F_88 ( V_2 ) )
F_58 ( V_2 , L_81 , V_152 ) ;
F_18 ( & V_2 -> V_37 ) ;
F_16 ( V_2 , V_30 , V_207 ) ;
F_20 ( V_2 , V_30 , V_207 ) ;
F_49 ( V_2 , V_46 , V_102 ) ;
F_19 ( & V_2 -> V_37 ) ;
if ( F_90 ( V_152 , V_208 ) ) {
if ( F_88 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_82 ,
priv->tx_retry_count) ;
if ( V_2 -> V_96 ++ < V_209 )
F_17 ( V_2 , V_30 ,
V_92 ) ;
else
F_81 ( V_61 , true ) ;
} else
F_81 ( V_61 , true ) ;
F_21 ( V_2 , V_132 , V_136 ) ;
}
if ( ( V_203 & V_137 ) != 0 ) {
V_204 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_83 , loop) ;
if ( F_74 ( V_2 ) <= 0 ) {
if ( F_65 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_84 ) ;
V_61 -> V_168 . V_177 ++ ;
}
F_21 ( V_2 , V_132 , V_137 ) ;
}
if ( F_84 ( V_61 ) )
V_204 ++ ;
} while ( V_204 );
F_17 ( V_2 , V_29 , V_139 ) ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_85 , __func__) ;
}
static void F_91 ( struct V_1 * V_2 )
{
if ( F_92 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_86 , priv->tx_skb->len) ;
if ( F_71 ( V_2 ) )
F_60 ( V_166 ,
V_2 -> V_196 -> V_3 , V_2 -> V_196 -> V_4 ) ;
F_32 ( V_2 , V_2 -> V_196 -> V_3 , V_2 -> V_196 -> V_4 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
int V_210 , V_211 ;
T_1 V_212 [ 64 ] ;
int V_213 ;
V_210 = V_2 -> V_196 -> V_3 ;
if ( V_210 > sizeof( V_212 ) )
V_210 = sizeof( V_212 ) ;
F_30 ( V_2 , V_46 + 1 , V_210 , V_212 ) ;
V_213 = 1 ;
for ( V_211 = 0 ; V_211 < V_210 ; V_211 ++ ) {
if ( V_2 -> V_196 -> V_4 [ V_211 ] != V_212 [ V_211 ] ) {
F_6 (KERN_DEBUG DRV_NAME
L_87
L_88 , k,
priv->tx_skb->data[k], test_buf[k]) ;
V_213 = 0 ;
}
}
if ( ! V_213 )
F_6 (KERN_DEBUG DRV_NAME L_89
L_90 ) ;
}
#endif
F_17 ( V_2 , V_30 , V_92 ) ;
}
static T_3 F_93 ( struct V_161 * V_162 ,
struct V_60 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
if ( F_92 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_94 ( V_51 ) ;
V_2 -> V_196 = V_162 ;
F_95 ( & V_2 -> V_214 ) ;
return V_215 ;
}
static void F_96 ( struct V_199 * V_200 )
{
struct V_1 * V_2 =
F_87 ( V_200 , struct V_1 , V_214 ) ;
F_91 ( V_2 ) ;
}
static T_4 F_97 ( int V_216 , void * V_217 )
{
struct V_1 * V_2 = V_217 ;
F_95 ( & V_2 -> V_201 ) ;
return V_218 ;
}
static void F_98 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_41 ( V_61 ) ;
if ( F_99 ( V_2 ) )
F_66 ( & V_61 -> V_51 , V_219 L_91 ) ;
V_61 -> V_168 . V_194 ++ ;
F_95 ( & V_2 -> V_220 ) ;
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
int V_221 = V_2 -> V_98 ;
if ( V_51 -> V_222 & V_223 ) {
if ( F_55 ( V_2 ) )
F_78 ( & V_51 -> V_51 , L_94 ) ;
V_2 -> V_98 = V_224 ;
} else if ( ( V_51 -> V_222 & V_225 ) || ! F_104 ( V_51 ) ) {
if ( F_55 ( V_2 ) )
F_78 ( & V_51 -> V_51 , L_95 ,
( V_51 -> V_222 & V_225 ) ? L_96 : L_97 ) ;
V_2 -> V_98 = V_226 ;
} else {
if ( F_55 ( V_2 ) )
F_78 ( & V_51 -> V_51 , L_98 ) ;
V_2 -> V_98 = V_99 ;
}
if ( V_221 != V_2 -> V_98 )
F_95 ( & V_2 -> V_227 ) ;
}
static void F_105 ( struct V_199 * V_200 )
{
struct V_1 * V_2 =
F_87 ( V_200 , struct V_1 , V_227 ) ;
if ( V_2 -> V_98 == V_224 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_99 ) ;
F_27 ( V_2 , V_104 , 0x00 ) ;
} else if ( V_2 -> V_98 == V_226 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_100 ) ;
F_27 ( V_2 , V_104 ,
V_105 | V_106 |
V_107 | V_228 ) ;
} else {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_101 ) ;
F_27 ( V_2 , V_104 ,
V_105 | V_106 |
V_107 ) ;
}
}
static void F_106 ( struct V_199 * V_200 )
{
struct V_1 * V_2 =
F_87 ( V_200 , struct V_1 , V_220 ) ;
struct V_60 * V_61 = V_2 -> V_202 ;
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
F_110 ( struct V_60 * V_51 , struct V_229 * V_230 )
{
F_111 ( V_230 -> V_231 , V_219 , sizeof( V_230 -> V_231 ) ) ;
F_111 ( V_230 -> V_232 , V_233 , sizeof( V_230 -> V_232 ) ) ;
F_111 ( V_230 -> V_234 ,
F_112 ( V_51 -> V_51 . V_235 ) , sizeof( V_230 -> V_234 ) ) ;
}
static int
F_113 ( struct V_60 * V_51 , struct V_236 * V_237 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
V_237 -> V_238 = V_239 ;
V_237 -> V_240 = V_241
| V_242
| V_243 ;
F_114 ( V_237 , V_149 ) ;
V_237 -> V_147 = V_2 -> V_112 ? V_150 : V_244 ;
V_237 -> V_245 = V_246 ;
V_237 -> V_145 = V_148 ;
return 0 ;
}
static int
F_115 ( struct V_60 * V_51 , struct V_236 * V_237 )
{
return F_54 ( V_51 , V_237 -> V_145 ,
F_116 ( V_237 ) , V_237 -> V_147 ) ;
}
static T_5 F_117 ( struct V_60 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
return V_2 -> V_247 ;
}
static void F_118 ( struct V_60 * V_51 , T_5 V_22 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
V_2 -> V_247 = V_22 ;
}
static int F_119 ( struct V_60 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
return F_51 ( V_2 ) ;
}
static int F_120 ( struct V_248 * V_15 )
{
struct V_60 * V_51 ;
struct V_1 * V_2 ;
int V_13 = 0 ;
if ( F_5 ( & V_249 ) )
F_78 ( & V_15 -> V_51 , V_219 L_103 ,
V_233 ) ;
V_51 = F_121 ( sizeof( struct V_1 ) ) ;
if ( ! V_51 ) {
V_13 = - V_250 ;
goto V_251;
}
V_2 = F_41 ( V_51 ) ;
V_2 -> V_202 = V_51 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_247 = F_122 ( V_249 . V_247 ,
V_252 ) ;
F_123 ( & V_2 -> V_37 ) ;
F_124 ( & V_2 -> V_214 , F_96 ) ;
F_124 ( & V_2 -> V_227 , F_105 ) ;
F_124 ( & V_2 -> V_201 , F_86 ) ;
F_124 ( & V_2 -> V_220 , F_106 ) ;
F_125 ( V_15 , V_2 ) ;
F_126 ( V_51 , & V_15 -> V_51 ) ;
if ( ! F_119 ( V_51 ) ) {
if ( F_127 ( V_2 ) )
F_78 ( & V_15 -> V_51 , V_219 L_104 ) ;
V_13 = - V_253 ;
goto V_254;
}
F_128 ( V_51 ) ;
F_40 ( V_51 ) ;
V_13 = F_129 ( V_15 -> V_216 , F_97 , 0 , V_219 , V_2 ) ;
if ( V_13 < 0 ) {
if ( F_127 ( V_2 ) )
F_66 ( & V_15 -> V_51 , V_219 L_105
L_106 , V_15 -> V_216 , V_13 ) ;
goto V_254;
}
V_51 -> V_255 = V_256 ;
V_51 -> V_216 = V_15 -> V_216 ;
V_51 -> V_257 = & V_258 ;
V_51 -> V_259 = V_260 ;
V_51 -> V_261 = & V_262 ;
F_50 ( V_2 , true ) ;
V_13 = F_130 ( V_51 ) ;
if ( V_13 ) {
if ( F_127 ( V_2 ) )
F_66 ( & V_15 -> V_51 , L_107 V_219
L_108 , V_13 ) ;
goto V_263;
}
F_78 ( & V_51 -> V_51 , V_219 L_109 ) ;
return 0 ;
V_263:
F_131 ( V_15 -> V_216 , V_2 ) ;
V_254:
F_132 ( V_51 ) ;
V_251:
return V_13 ;
}
static int F_133 ( struct V_248 * V_15 )
{
struct V_1 * V_2 = F_134 ( V_15 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_110 ) ;
F_135 ( V_2 -> V_202 ) ;
F_131 ( V_15 -> V_216 , V_2 ) ;
F_132 ( V_2 -> V_202 ) ;
return 0 ;
}
static int T_6 F_136 ( void )
{
V_50 = F_137 ( 20 ) ;
return F_138 ( & V_264 ) ;
}
static void T_7 F_139 ( void )
{
F_140 ( & V_264 ) ;
}
