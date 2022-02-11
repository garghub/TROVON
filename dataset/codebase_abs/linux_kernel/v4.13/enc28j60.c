static int
F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
T_1 * V_5 = V_2 -> V_6 + 4 ;
T_1 * V_7 = V_2 -> V_6 ;
struct V_8 V_9 = {
. V_7 = V_7 ,
. V_3 = V_10 ,
} ;
struct V_8 V_11 = {
. V_5 = V_5 ,
. V_3 = V_3 ,
} ;
struct V_12 V_13 ;
int V_14 ;
V_7 [ 0 ] = V_15 ;
F_2 ( & V_13 ) ;
F_3 ( & V_9 , & V_13 ) ;
F_3 ( & V_11 , & V_13 ) ;
V_14 = F_4 ( V_2 -> V_16 , & V_13 ) ;
if ( V_14 == 0 ) {
memcpy ( V_4 , V_5 , V_3 ) ;
V_14 = V_13 . V_17 ;
}
if ( V_14 && F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_1 ,
__func__, ret) ;
return V_14 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 ,
const T_1 * V_4 )
{
int V_14 ;
if ( V_3 > V_18 - 1 || V_3 <= 0 )
V_14 = - V_19 ;
else {
V_2 -> V_6 [ 0 ] = V_20 ;
memcpy ( & V_2 -> V_6 [ 1 ] , V_4 , V_3 ) ;
V_14 = F_8 ( V_2 -> V_16 , V_2 -> V_6 , V_3 + 1 ) ;
if ( V_14 && F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_1 ,
__func__, ret) ;
}
return V_14 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_21 ,
T_1 V_22 )
{
T_1 V_7 [ 2 ] ;
T_1 V_5 [ 4 ] ;
T_1 V_23 = 0 ;
int V_14 ;
int V_24 = V_10 ;
if ( V_22 & V_25 )
V_24 ++ ;
V_7 [ 0 ] = V_21 | ( V_22 & V_26 ) ;
V_14 = F_10 ( V_2 -> V_16 , V_7 , 1 , V_5 , V_24 ) ;
if ( V_14 )
F_6 (KERN_DEBUG DRV_NAME L_1 ,
__func__, ret) ;
else
V_23 = V_5 [ V_24 - 1 ] ;
return V_23 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_21 ,
T_1 V_22 , T_1 V_23 )
{
int V_14 ;
V_2 -> V_6 [ 0 ] = V_21 | ( V_22 & V_26 ) ;
V_2 -> V_6 [ 1 ] = V_23 ;
V_14 = F_8 ( V_2 -> V_16 , V_2 -> V_6 , 2 ) ;
if ( V_14 && F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_1 ,
__func__, ret) ;
return V_14 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_11 ( V_2 , V_27 , 0 , V_27 ) ;
F_14 ( 2000 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_22 )
{
T_1 V_28 = ( V_22 & V_29 ) >> 5 ;
if ( V_22 >= V_30 && V_22 <= V_31 )
return;
if ( ( V_28 & V_32 ) != ( V_2 -> V_33 & V_32 ) ) {
if ( V_28 & V_32 )
F_11 ( V_2 , V_34 , V_31 ,
V_32 ) ;
else
F_11 ( V_2 , V_35 , V_31 ,
V_32 ) ;
}
if ( ( V_28 & V_36 ) != ( V_2 -> V_33 & V_36 ) ) {
if ( V_28 & V_36 )
F_11 ( V_2 , V_34 , V_31 ,
V_36 ) ;
else
F_11 ( V_2 , V_35 , V_31 ,
V_36 ) ;
}
V_2 -> V_33 = V_28 ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 V_22 , T_1 V_37 )
{
F_15 ( V_2 , V_22 ) ;
F_11 ( V_2 , V_34 , V_22 , V_37 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
T_1 V_22 , T_1 V_37 )
{
F_18 ( & V_2 -> V_38 ) ;
F_16 ( V_2 , V_22 , V_37 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
T_1 V_22 , T_1 V_37 )
{
F_15 ( V_2 , V_22 ) ;
F_11 ( V_2 , V_35 , V_22 , V_37 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
T_1 V_22 , T_1 V_37 )
{
F_18 ( & V_2 -> V_38 ) ;
F_20 ( V_2 , V_22 , V_37 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
T_1 V_39 )
{
F_15 ( V_2 , V_39 ) ;
return F_9 ( V_2 , V_40 , V_39 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 V_39 )
{
int V_14 ;
F_18 ( & V_2 -> V_38 ) ;
V_14 = F_22 ( V_2 , V_39 ) ;
F_19 ( & V_2 -> V_38 ) ;
return V_14 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_1 V_39 )
{
int V_41 , V_42 ;
F_15 ( V_2 , V_39 ) ;
V_41 = F_9 ( V_2 , V_40 , V_39 ) ;
V_42 = F_9 ( V_2 , V_40 , V_39 + 1 ) ;
return ( V_42 << 8 ) | V_41 ;
}
static int F_25 ( struct V_1 * V_2 ,
T_1 V_39 )
{
int V_14 ;
F_18 ( & V_2 -> V_38 ) ;
V_14 = F_24 ( V_2 , V_39 ) ;
F_19 ( & V_2 -> V_38 ) ;
return V_14 ;
}
static void F_26 ( struct V_1 * V_2 ,
T_1 V_39 , T_1 V_4 )
{
F_15 ( V_2 , V_39 ) ;
F_11 ( V_2 , V_43 , V_39 , V_4 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
T_1 V_39 , T_1 V_4 )
{
F_18 ( & V_2 -> V_38 ) ;
F_26 ( V_2 , V_39 , V_4 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
T_1 V_39 , T_2 V_4 )
{
F_15 ( V_2 , V_39 ) ;
F_11 ( V_2 , V_43 , V_39 , ( T_1 ) V_4 ) ;
F_11 ( V_2 , V_43 , V_39 + 1 ,
( T_1 ) ( V_4 >> 8 ) ) ;
}
static void F_29 ( struct V_1 * V_2 ,
T_1 V_39 , T_2 V_4 )
{
F_18 ( & V_2 -> V_38 ) ;
F_28 ( V_2 , V_39 , V_4 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
T_2 V_22 , int V_3 , T_1 * V_4 )
{
F_18 ( & V_2 -> V_38 ) ;
F_28 ( V_2 , V_44 , V_22 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
T_2 V_45 ;
V_45 = F_24 ( V_2 , V_44 ) ;
if ( V_45 != V_22 )
F_6 (KERN_DEBUG DRV_NAME L_3
L_4 , __func__, reg, addr) ;
}
#endif
F_1 ( V_2 , V_3 , V_4 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static void
F_32 ( struct V_1 * V_2 , int V_3 , const T_1 * V_4 )
{
F_18 ( & V_2 -> V_38 ) ;
F_28 ( V_2 , V_46 , V_47 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
T_2 V_45 ;
V_45 = F_24 ( V_2 , V_46 ) ;
if ( V_45 != V_47 )
F_6 (KERN_DEBUG DRV_NAME
L_5 ,
__func__, reg, TXSTART_INIT) ;
}
#endif
F_28 ( V_2 , V_48 , V_47 + V_3 ) ;
F_11 ( V_2 , V_20 , 0 , 0x00 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_6 ,
__func__, nolock_regw_read(priv, EWRPTL)) ;
F_7 ( V_2 , V_3 , V_4 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_7 ,
__func__, nolock_regw_read(priv, EWRPTL), len) ;
F_19 ( & V_2 -> V_38 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_45 , T_1 V_37 , T_1 V_23 )
{
unsigned long V_49 = V_50 + V_51 ;
while ( ( F_22 ( V_2 , V_45 ) & V_37 ) != V_23 ) {
if ( F_34 ( V_50 , V_49 ) ) {
if ( F_5 ( V_2 ) )
F_35 ( & V_2 -> V_16 -> V_52 ,
L_8 , V_45 ) ;
return - V_53 ;
}
F_36 () ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , V_54 , V_55 , 0 ) ? 0 : 1 ;
}
static T_2 F_38 ( struct V_1 * V_2 , T_1 V_39 )
{
T_2 V_14 ;
F_18 ( & V_2 -> V_38 ) ;
F_26 ( V_2 , V_56 , V_39 ) ;
F_26 ( V_2 , V_57 , V_58 ) ;
F_37 ( V_2 ) ;
F_26 ( V_2 , V_57 , 0x00 ) ;
V_14 = F_24 ( V_2 , V_59 ) ;
F_19 ( & V_2 -> V_38 ) ;
return V_14 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_39 , T_2 V_4 )
{
int V_14 ;
F_18 ( & V_2 -> V_38 ) ;
F_26 ( V_2 , V_56 , V_39 ) ;
F_28 ( V_2 , V_60 , V_4 ) ;
V_14 = F_37 ( V_2 ) ;
F_19 ( & V_2 -> V_38 ) ;
return V_14 ;
}
static int F_40 ( struct V_61 * V_62 )
{
int V_14 ;
struct V_1 * V_2 = F_41 ( V_62 ) ;
F_18 ( & V_2 -> V_38 ) ;
if ( ! V_2 -> V_63 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_INFO DRV_NAME
L_9 ,
ndev->name, ndev->dev_addr) ;
F_26 ( V_2 , V_64 , V_62 -> V_65 [ 0 ] ) ;
F_26 ( V_2 , V_66 , V_62 -> V_65 [ 1 ] ) ;
F_26 ( V_2 , V_67 , V_62 -> V_65 [ 2 ] ) ;
F_26 ( V_2 , V_68 , V_62 -> V_65 [ 3 ] ) ;
F_26 ( V_2 , V_69 , V_62 -> V_65 [ 4 ] ) ;
F_26 ( V_2 , V_70 , V_62 -> V_65 [ 5 ] ) ;
V_14 = 0 ;
} else {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_10
L_11 , __func__) ;
V_14 = - V_71 ;
}
F_19 ( & V_2 -> V_38 ) ;
return V_14 ;
}
static int F_42 ( struct V_61 * V_52 , void * V_22 )
{
struct V_72 * V_39 = V_22 ;
if ( F_43 ( V_52 ) )
return - V_71 ;
if ( ! F_44 ( V_39 -> V_73 ) )
return - V_74 ;
memcpy ( V_52 -> V_65 , V_39 -> V_73 , V_52 -> V_75 ) ;
return F_40 ( V_52 ) ;
}
static void F_45 ( struct V_1 * V_2 , const char * V_13 )
{
F_18 ( & V_2 -> V_38 ) ;
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
F_19 ( & V_2 -> V_38 ) ;
}
static T_2 F_46 ( T_2 V_76 , T_2 V_77 , T_2 V_78 )
{
T_2 V_79 ;
if ( ( V_76 - 1 < V_77 ) || ( V_76 - 1 > V_78 ) )
V_79 = V_78 ;
else
V_79 = V_76 - 1 ;
return V_79 ;
}
static T_2 F_47 ( T_2 V_80 )
{
if ( V_80 + V_81 > V_82 )
return ( V_80 + V_81 ) - ( V_82 - V_83 + 1 ) ;
else
return V_80 + V_81 ;
}
static void F_48 ( struct V_1 * V_2 , T_2 V_77 , T_2 V_78 )
{
T_2 V_79 ;
if ( V_77 > 0x1FFF || V_78 > 0x1FFF || V_77 > V_78 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_ERR DRV_NAME L_23
L_24 , __func__, start, end) ;
return;
}
V_2 -> V_84 = V_77 ;
F_28 ( V_2 , V_85 , V_77 ) ;
V_79 = F_46 ( V_2 -> V_84 , V_77 , V_78 ) ;
F_28 ( V_2 , V_86 , V_79 ) ;
F_28 ( V_2 , V_87 , V_78 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_2 V_77 , T_2 V_78 )
{
if ( V_77 > 0x1FFF || V_78 > 0x1FFF || V_77 > V_78 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_ERR DRV_NAME L_25
L_24 , __func__, start, end) ;
return;
}
F_28 ( V_2 , V_88 , V_77 ) ;
F_28 ( V_2 , V_48 , V_78 ) ;
}
static void F_50 ( struct V_1 * V_2 , bool V_89 )
{
if ( F_5 ( V_2 ) )
F_35 ( & V_2 -> V_16 -> V_52 , L_26 ,
V_89 ? L_27 : L_28 ) ;
F_18 ( & V_2 -> V_38 ) ;
if ( V_89 ) {
F_20 ( V_2 , V_31 , V_90 ) ;
F_33 ( V_2 , V_91 , V_92 , 0 ) ;
F_33 ( V_2 , V_31 , V_93 , 0 ) ;
F_16 ( V_2 , V_94 , V_95 ) ;
} else {
F_20 ( V_2 , V_94 , V_95 ) ;
F_33 ( V_2 , V_91 , V_96 , V_96 ) ;
}
F_19 ( & V_2 -> V_38 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
T_1 V_45 ;
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_29 , __func__,
priv->full_duplex ? L_30 : L_31 ) ;
F_18 ( & V_2 -> V_38 ) ;
F_12 ( V_2 ) ;
F_11 ( V_2 , V_43 , V_31 , 0x00 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_63 = false ;
V_2 -> V_97 = 0 ;
V_2 -> V_98 = 0 ;
V_2 -> V_99 = V_100 ;
F_26 ( V_2 , V_94 , V_101 | V_102 ) ;
F_48 ( V_2 , V_83 , V_82 ) ;
F_49 ( V_2 , V_47 , V_103 ) ;
F_19 ( & V_2 -> V_38 ) ;
V_45 = F_23 ( V_2 , V_104 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_INFO DRV_NAME L_32 , reg) ;
if ( V_45 == 0x00 || V_45 == 0xff ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_33 ,
__func__, reg) ;
return 0 ;
}
F_27 ( V_2 , V_105 ,
V_106 | V_107 | V_108 ) ;
F_27 ( V_2 , V_109 ,
V_110 | V_111 | V_112 ) ;
if ( V_2 -> V_113 ) {
F_27 ( V_2 , V_114 ,
V_115 | V_116 |
V_117 | V_118 ) ;
F_27 ( V_2 , V_119 , 0x12 ) ;
F_27 ( V_2 , V_120 , 0x15 ) ;
} else {
F_27 ( V_2 , V_114 ,
V_115 | V_116 |
V_117 ) ;
F_27 ( V_2 , V_121 , 1 << 6 ) ;
F_29 ( V_2 , V_119 , 0x0C12 ) ;
F_27 ( V_2 , V_120 , 0x12 ) ;
}
F_29 ( V_2 , V_122 , V_123 ) ;
if ( ! F_39 ( V_2 , V_124 , V_125 ) )
return 0 ;
if ( V_2 -> V_113 ) {
if ( ! F_39 ( V_2 , V_126 , V_127 ) )
return 0 ;
if ( ! F_39 ( V_2 , V_128 , 0x00 ) )
return 0 ;
} else {
if ( ! F_39 ( V_2 , V_126 , 0x00 ) )
return 0 ;
if ( ! F_39 ( V_2 , V_128 , V_129 ) )
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
F_39 ( V_2 , V_130 , V_131 | V_132 ) ;
F_18 ( & V_2 -> V_38 ) ;
F_20 ( V_2 , V_133 , V_134 | V_135 |
V_136 | V_137 | V_138 | V_139 ) ;
F_26 ( V_2 , V_30 , V_140 | V_141 | V_142 |
V_143 | V_144 | V_145 ) ;
F_16 ( V_2 , V_31 , V_90 ) ;
V_2 -> V_63 = true ;
F_19 ( & V_2 -> V_38 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_38 ) ;
F_26 ( V_2 , V_30 , 0x00 ) ;
F_20 ( V_2 , V_31 , V_90 ) ;
V_2 -> V_63 = false ;
F_19 ( & V_2 -> V_38 ) ;
}
static int
F_54 ( struct V_61 * V_62 , T_1 V_146 , T_2 V_147 , T_1 V_148 )
{
struct V_1 * V_2 = F_41 ( V_62 ) ;
int V_14 = 0 ;
if ( ! V_2 -> V_63 ) {
if ( V_146 == V_149 && V_147 == V_150 )
V_2 -> V_113 = ( V_148 == V_151 ) ;
else {
if ( F_55 ( V_2 ) )
F_56 ( & V_62 -> V_52 ,
L_36 ) ;
V_14 = - V_152 ;
}
} else {
if ( F_55 ( V_2 ) )
F_56 ( & V_62 -> V_52 , L_37
L_38 ) ;
V_14 = - V_71 ;
}
return V_14 ;
}
static void F_57 ( struct V_1 * V_2 , T_1 V_153 [ V_154 ] )
{
int V_155 ;
V_155 = F_25 ( V_2 , V_48 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_39 ,
endptr + 1 ) ;
F_30 ( V_2 , V_155 + 1 , V_154 , V_153 ) ;
}
static void F_58 ( struct V_1 * V_2 , const char * V_13 ,
T_1 V_153 [ V_154 ] )
{
T_2 V_156 , V_157 ;
F_6 (KERN_DEBUG DRV_NAME L_40 , msg) ;
V_156 = V_153 [ 1 ] ;
V_156 <<= 8 ;
V_156 |= V_153 [ 0 ] ;
V_157 = V_153 [ 5 ] ;
V_157 <<= 8 ;
V_157 |= V_153 [ 4 ] ;
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
static void F_59 ( struct V_1 * V_2 , const char * V_13 ,
T_2 V_158 , int V_3 , T_2 V_159 )
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
static void F_60 ( const char * V_13 , int V_3 , const char * V_4 )
{
F_6 (KERN_DEBUG DRV_NAME L_57 , msg, len) ;
F_61 ( V_160 , L_58 , V_161 , 16 , 1 ,
V_4 , V_3 , true ) ;
}
static void F_62 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_41 ( V_62 ) ;
struct V_162 * V_163 = NULL ;
T_2 V_79 , V_164 , V_165 ;
T_1 V_166 [ V_81 ] ;
int V_3 ;
if ( F_63 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_59 ,
priv->next_pk_ptr) ;
if ( F_64 ( V_2 -> V_84 > V_82 ) ) {
if ( F_65 ( V_2 ) )
F_66 ( & V_62 -> V_52 ,
L_60 ,
V_167 , V_2 -> V_84 ) ;
F_18 ( & V_2 -> V_38 ) ;
F_20 ( V_2 , V_31 , V_90 ) ;
F_16 ( V_2 , V_31 , V_168 ) ;
F_20 ( V_2 , V_31 , V_168 ) ;
F_48 ( V_2 , V_83 , V_82 ) ;
F_20 ( V_2 , V_133 , V_138 ) ;
F_16 ( V_2 , V_31 , V_90 ) ;
F_19 ( & V_2 -> V_38 ) ;
V_62 -> V_169 . V_170 ++ ;
return;
}
F_30 ( V_2 , V_2 -> V_84 , sizeof( V_166 ) , V_166 ) ;
V_164 = V_166 [ 1 ] ;
V_164 <<= 8 ;
V_164 |= V_166 [ 0 ] ;
V_3 = V_166 [ 3 ] ;
V_3 <<= 8 ;
V_3 |= V_166 [ 2 ] ;
V_165 = V_166 [ 5 ] ;
V_165 <<= 8 ;
V_165 |= V_166 [ 4 ] ;
if ( F_63 ( V_2 ) )
F_59 ( V_2 , V_167 , V_164 , V_3 , V_165 ) ;
if ( ! F_67 ( V_165 , V_171 ) || V_3 > V_123 ) {
if ( F_65 ( V_2 ) )
F_66 ( & V_62 -> V_52 , L_61 , V_165 ) ;
V_62 -> V_169 . V_170 ++ ;
if ( F_67 ( V_165 , V_172 ) )
V_62 -> V_169 . V_173 ++ ;
if ( F_67 ( V_165 , V_174 ) )
V_62 -> V_169 . V_175 ++ ;
if ( V_3 > V_123 )
V_62 -> V_169 . V_176 ++ ;
} else {
V_163 = F_68 ( V_62 , V_3 + V_177 ) ;
if ( ! V_163 ) {
if ( F_65 ( V_2 ) )
F_66 ( & V_62 -> V_52 ,
L_62 ) ;
V_62 -> V_169 . V_178 ++ ;
} else {
F_69 ( V_163 , V_177 ) ;
F_30 ( V_2 ,
F_47 ( V_2 -> V_84 ) ,
V_3 , F_70 ( V_163 , V_3 ) ) ;
if ( F_71 ( V_2 ) )
F_60 ( V_167 , V_163 -> V_3 , V_163 -> V_4 ) ;
V_163 -> V_179 = F_72 ( V_163 , V_62 ) ;
V_62 -> V_169 . V_180 ++ ;
V_62 -> V_169 . V_181 += V_3 ;
F_73 ( V_163 ) ;
}
}
V_79 = F_46 ( V_164 , V_83 , V_82 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_63 ,
__func__, erxrdpt) ;
F_18 ( & V_2 -> V_38 ) ;
F_28 ( V_2 , V_86 , V_79 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
T_2 V_45 ;
V_45 = F_24 ( V_2 , V_86 ) ;
if ( V_45 != V_79 )
F_6 (KERN_DEBUG DRV_NAME L_64
L_65 , __func__,
reg, erxrdpt) ;
}
#endif
V_2 -> V_84 = V_164 ;
F_16 ( V_2 , V_94 , V_182 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_183 , V_184 , V_185 , V_186 , V_187 ;
int V_188 ;
F_18 ( & V_2 -> V_38 ) ;
V_183 = F_22 ( V_2 , V_189 ) ;
if ( V_183 >= 255 )
V_188 = - 1 ;
else {
V_184 = F_24 ( V_2 , V_85 ) ;
V_185 = F_24 ( V_2 , V_87 ) ;
V_186 = F_24 ( V_2 , V_190 ) ;
V_187 = F_24 ( V_2 , V_86 ) ;
if ( V_186 > V_187 )
V_188 = ( V_185 - V_184 ) - ( V_186 - V_187 ) ;
else if ( V_186 == V_187 )
V_188 = ( V_185 - V_184 ) ;
else
V_188 = V_187 - V_186 - 1 ;
}
F_19 ( & V_2 -> V_38 ) ;
if ( F_63 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_66 ,
__func__, free_space) ;
return V_188 ;
}
static void F_75 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_41 ( V_62 ) ;
T_2 V_45 ;
int V_148 ;
V_45 = F_38 ( V_2 , V_191 ) ;
if ( F_13 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_67
L_68 , __func__,
enc28j60_phy_read(priv, PHSTAT1), reg) ;
V_148 = V_45 & V_192 ;
if ( V_45 & V_193 ) {
F_76 ( V_62 ) ;
if ( F_77 ( V_2 ) )
F_78 ( & V_62 -> V_52 , L_69 ,
V_148 ? L_70 : L_71 ) ;
} else {
if ( F_79 ( V_2 ) )
F_78 ( & V_62 -> V_52 , L_72 ) ;
F_80 ( V_62 ) ;
}
}
static void F_81 ( struct V_61 * V_62 , bool V_194 )
{
struct V_1 * V_2 = F_41 ( V_62 ) ;
if ( V_194 )
V_62 -> V_169 . V_195 ++ ;
else
V_62 -> V_169 . V_196 ++ ;
if ( V_2 -> V_197 ) {
if ( ! V_194 )
V_62 -> V_169 . V_198 += V_2 -> V_197 -> V_3 ;
F_82 ( V_2 -> V_197 ) ;
V_2 -> V_197 = NULL ;
}
F_21 ( V_2 , V_31 , V_93 ) ;
F_83 ( V_62 ) ;
}
static int F_84 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_41 ( V_62 ) ;
int V_199 , V_14 ;
V_199 = F_23 ( V_2 , V_189 ) ;
if ( V_199 && F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_73 , pk_counter) ;
if ( V_199 > V_2 -> V_98 ) {
V_2 -> V_98 = V_199 ;
if ( F_63 ( V_2 ) && V_2 -> V_98 > 1 )
F_6 (KERN_DEBUG DRV_NAME L_74 ,
priv->max_pk_counter) ;
}
V_14 = V_199 ;
while ( V_199 -- > 0 )
F_62 ( V_62 ) ;
return V_14 ;
}
static void F_86 ( struct V_200 * V_201 )
{
struct V_1 * V_2 =
F_87 ( V_201 , struct V_1 , V_202 ) ;
struct V_61 * V_62 = V_2 -> V_203 ;
int V_204 , V_205 ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_21 ( V_2 , V_30 , V_140 ) ;
do {
V_205 = 0 ;
V_204 = F_23 ( V_2 , V_133 ) ;
if ( ( V_204 & V_134 ) != 0 ) {
V_205 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_75 , loop) ;
F_21 ( V_2 , V_133 , V_134 ) ;
}
if ( ( V_204 & V_135 ) != 0 ) {
V_205 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_76 , loop) ;
F_75 ( V_62 ) ;
F_38 ( V_2 , V_206 ) ;
}
if ( ( ( V_204 & V_136 ) != 0 ) &&
( ( V_204 & V_137 ) == 0 ) ) {
bool V_194 = false ;
V_205 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_77 , loop) ;
V_2 -> V_97 = 0 ;
if ( F_23 ( V_2 , V_91 ) & V_207 ) {
if ( F_88 ( V_2 ) )
F_66 ( & V_62 -> V_52 ,
L_78 ) ;
V_194 = true ;
}
if ( F_89 ( V_2 ) ) {
T_1 V_153 [ V_154 ] ;
F_57 ( V_2 , V_153 ) ;
F_58 ( V_2 , L_79 , V_153 ) ;
}
F_81 ( V_62 , V_194 ) ;
F_21 ( V_2 , V_133 , V_136 ) ;
}
if ( ( V_204 & V_137 ) != 0 ) {
T_1 V_153 [ V_154 ] ;
V_205 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_80 , loop) ;
F_21 ( V_2 , V_31 , V_93 ) ;
F_57 ( V_2 , V_153 ) ;
if ( F_88 ( V_2 ) )
F_58 ( V_2 , L_81 , V_153 ) ;
F_18 ( & V_2 -> V_38 ) ;
F_16 ( V_2 , V_31 , V_208 ) ;
F_20 ( V_2 , V_31 , V_208 ) ;
F_49 ( V_2 , V_47 , V_103 ) ;
F_19 ( & V_2 -> V_38 ) ;
if ( F_90 ( V_153 , V_209 ) ) {
if ( F_88 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_82 ,
priv->tx_retry_count) ;
if ( V_2 -> V_97 ++ < V_210 )
F_17 ( V_2 , V_31 ,
V_93 ) ;
else
F_81 ( V_62 , true ) ;
} else
F_81 ( V_62 , true ) ;
F_21 ( V_2 , V_133 , V_137 | V_136 ) ;
}
if ( ( V_204 & V_138 ) != 0 ) {
V_205 ++ ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_83 , loop) ;
if ( F_74 ( V_2 ) <= 0 ) {
if ( F_65 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_84 ) ;
V_62 -> V_169 . V_178 ++ ;
}
F_21 ( V_2 , V_133 , V_138 ) ;
}
if ( F_84 ( V_62 ) )
V_205 ++ ;
} while ( V_205 );
F_17 ( V_2 , V_30 , V_140 ) ;
if ( F_85 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_85 , __func__) ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_92 ( ! V_2 -> V_197 ) ;
if ( F_93 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME
L_86 , priv->tx_skb->len) ;
if ( F_71 ( V_2 ) )
F_60 ( V_167 ,
V_2 -> V_197 -> V_3 , V_2 -> V_197 -> V_4 ) ;
F_32 ( V_2 , V_2 -> V_197 -> V_3 , V_2 -> V_197 -> V_4 ) ;
#ifdef F_31
if ( F_5 ( V_2 ) ) {
int V_211 , V_212 ;
T_1 V_213 [ 64 ] ;
int V_214 ;
V_211 = V_2 -> V_197 -> V_3 ;
if ( V_211 > sizeof( V_213 ) )
V_211 = sizeof( V_213 ) ;
F_30 ( V_2 , V_47 + 1 , V_211 , V_213 ) ;
V_214 = 1 ;
for ( V_212 = 0 ; V_212 < V_211 ; V_212 ++ ) {
if ( V_2 -> V_197 -> V_4 [ V_212 ] != V_213 [ V_212 ] ) {
F_6 (KERN_DEBUG DRV_NAME
L_87
L_88 , k,
priv->tx_skb->data[k], test_buf[k]) ;
V_214 = 0 ;
}
}
if ( ! V_214 )
F_6 (KERN_DEBUG DRV_NAME L_89
L_90 ) ;
}
#endif
F_17 ( V_2 , V_31 , V_93 ) ;
}
static T_3 F_94 ( struct V_162 * V_163 ,
struct V_61 * V_52 )
{
struct V_1 * V_2 = F_41 ( V_52 ) ;
if ( F_93 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_95 ( V_52 ) ;
V_2 -> V_197 = V_163 ;
F_96 ( & V_2 -> V_215 ) ;
return V_216 ;
}
static void F_97 ( struct V_200 * V_201 )
{
struct V_1 * V_2 =
F_87 ( V_201 , struct V_1 , V_215 ) ;
F_91 ( V_2 ) ;
}
static T_4 F_98 ( int V_217 , void * V_218 )
{
struct V_1 * V_2 = V_218 ;
F_96 ( & V_2 -> V_202 ) ;
return V_219 ;
}
static void F_99 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_41 ( V_62 ) ;
if ( F_100 ( V_2 ) )
F_66 ( & V_62 -> V_52 , V_220 L_91 ) ;
V_62 -> V_169 . V_195 ++ ;
F_96 ( & V_2 -> V_221 ) ;
}
static int F_101 ( struct V_61 * V_52 )
{
struct V_1 * V_2 = F_41 ( V_52 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
if ( ! F_44 ( V_52 -> V_65 ) ) {
if ( F_77 ( V_2 ) )
F_66 ( & V_52 -> V_52 , L_92 ,
V_52 -> V_65 ) ;
return - V_74 ;
}
F_50 ( V_2 , false ) ;
F_53 ( V_2 ) ;
if ( ! F_51 ( V_2 ) ) {
if ( F_77 ( V_2 ) )
F_66 ( & V_52 -> V_52 , L_93 ) ;
return - V_19 ;
}
F_40 ( V_52 ) ;
F_52 ( V_2 ) ;
F_75 ( V_52 ) ;
F_102 ( V_52 ) ;
return 0 ;
}
static int F_103 ( struct V_61 * V_52 )
{
struct V_1 * V_2 = F_41 ( V_52 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_2 , __func__) ;
F_53 ( V_2 ) ;
F_50 ( V_2 , true ) ;
F_95 ( V_52 ) ;
return 0 ;
}
static void F_104 ( struct V_61 * V_52 )
{
struct V_1 * V_2 = F_41 ( V_52 ) ;
int V_222 = V_2 -> V_99 ;
if ( V_52 -> V_223 & V_224 ) {
if ( F_55 ( V_2 ) )
F_78 ( & V_52 -> V_52 , L_94 ) ;
V_2 -> V_99 = V_225 ;
} else if ( ( V_52 -> V_223 & V_226 ) || ! F_105 ( V_52 ) ) {
if ( F_55 ( V_2 ) )
F_78 ( & V_52 -> V_52 , L_95 ,
( V_52 -> V_223 & V_226 ) ? L_96 : L_97 ) ;
V_2 -> V_99 = V_227 ;
} else {
if ( F_55 ( V_2 ) )
F_78 ( & V_52 -> V_52 , L_98 ) ;
V_2 -> V_99 = V_100 ;
}
if ( V_222 != V_2 -> V_99 )
F_96 ( & V_2 -> V_228 ) ;
}
static void F_106 ( struct V_200 * V_201 )
{
struct V_1 * V_2 =
F_87 ( V_201 , struct V_1 , V_228 ) ;
if ( V_2 -> V_99 == V_225 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_99 ) ;
F_27 ( V_2 , V_105 , 0x00 ) ;
} else if ( V_2 -> V_99 == V_227 ) {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_100 ) ;
F_27 ( V_2 , V_105 ,
V_106 | V_107 |
V_108 | V_229 ) ;
} else {
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_101 ) ;
F_27 ( V_2 , V_105 ,
V_106 | V_107 |
V_108 ) ;
}
}
static void F_107 ( struct V_200 * V_201 )
{
struct V_1 * V_2 =
F_87 ( V_201 , struct V_1 , V_221 ) ;
struct V_61 * V_62 = V_2 -> V_203 ;
int V_14 ;
F_108 () ;
if ( F_43 ( V_62 ) ) {
F_103 ( V_62 ) ;
V_14 = F_101 ( V_62 ) ;
if ( F_64 ( V_14 ) ) {
F_78 ( & V_62 -> V_52 , L_102 , V_14 ) ;
F_109 ( V_62 ) ;
}
}
F_110 () ;
}
static void
F_111 ( struct V_61 * V_52 , struct V_230 * V_231 )
{
F_112 ( V_231 -> V_232 , V_220 , sizeof( V_231 -> V_232 ) ) ;
F_112 ( V_231 -> V_233 , V_234 , sizeof( V_231 -> V_233 ) ) ;
F_112 ( V_231 -> V_235 ,
F_113 ( V_52 -> V_52 . V_236 ) , sizeof( V_231 -> V_235 ) ) ;
}
static int
F_114 ( struct V_61 * V_52 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = F_41 ( V_52 ) ;
F_115 ( V_238 , V_239 ) ;
F_116 ( V_238 , V_239 , 10baseT_Half ) ;
F_116 ( V_238 , V_239 , 10baseT_Full ) ;
F_116 ( V_238 , V_239 , V_240 ) ;
V_238 -> V_241 . V_147 = V_150 ;
V_238 -> V_241 . V_148 = V_2 -> V_113 ? V_151 : V_242 ;
V_238 -> V_241 . V_243 = V_244 ;
V_238 -> V_241 . V_146 = V_149 ;
return 0 ;
}
static int
F_117 ( struct V_61 * V_52 ,
const struct V_237 * V_238 )
{
return F_54 ( V_52 , V_238 -> V_241 . V_146 ,
V_238 -> V_241 . V_147 , V_238 -> V_241 . V_148 ) ;
}
static T_5 F_118 ( struct V_61 * V_52 )
{
struct V_1 * V_2 = F_41 ( V_52 ) ;
return V_2 -> V_245 ;
}
static void F_119 ( struct V_61 * V_52 , T_5 V_23 )
{
struct V_1 * V_2 = F_41 ( V_52 ) ;
V_2 -> V_245 = V_23 ;
}
static int F_120 ( struct V_61 * V_52 )
{
struct V_1 * V_2 = F_41 ( V_52 ) ;
return F_51 ( V_2 ) ;
}
static int F_121 ( struct V_246 * V_16 )
{
struct V_61 * V_52 ;
struct V_1 * V_2 ;
const void * V_247 ;
int V_14 = 0 ;
if ( F_5 ( & V_248 ) )
F_78 ( & V_16 -> V_52 , V_220 L_103 ,
V_234 ) ;
V_52 = F_122 ( sizeof( struct V_1 ) ) ;
if ( ! V_52 ) {
V_14 = - V_249 ;
goto V_250;
}
V_2 = F_41 ( V_52 ) ;
V_2 -> V_203 = V_52 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_245 = F_123 ( V_248 . V_245 ,
V_251 ) ;
F_124 ( & V_2 -> V_38 ) ;
F_125 ( & V_2 -> V_215 , F_97 ) ;
F_125 ( & V_2 -> V_228 , F_106 ) ;
F_125 ( & V_2 -> V_202 , F_86 ) ;
F_125 ( & V_2 -> V_221 , F_107 ) ;
F_126 ( V_16 , V_2 ) ;
F_127 ( V_52 , & V_16 -> V_52 ) ;
if ( ! F_120 ( V_52 ) ) {
if ( F_128 ( V_2 ) )
F_78 ( & V_16 -> V_52 , V_220 L_104 ) ;
V_14 = - V_252 ;
goto V_253;
}
V_247 = F_129 ( V_16 -> V_52 . V_254 ) ;
if ( V_247 )
F_130 ( V_52 -> V_65 , V_247 ) ;
else
F_131 ( V_52 ) ;
F_40 ( V_52 ) ;
V_14 = F_132 ( V_16 -> V_217 , F_98 , 0 , V_220 , V_2 ) ;
if ( V_14 < 0 ) {
if ( F_128 ( V_2 ) )
F_66 ( & V_16 -> V_52 , V_220 L_105
L_106 , V_16 -> V_217 , V_14 ) ;
goto V_253;
}
V_52 -> V_255 = V_256 ;
V_52 -> V_217 = V_16 -> V_217 ;
V_52 -> V_257 = & V_258 ;
V_52 -> V_259 = V_260 ;
V_52 -> V_261 = & V_262 ;
F_50 ( V_2 , true ) ;
V_14 = F_133 ( V_52 ) ;
if ( V_14 ) {
if ( F_128 ( V_2 ) )
F_66 ( & V_16 -> V_52 , L_107 V_220
L_108 , V_14 ) ;
goto V_263;
}
F_78 ( & V_52 -> V_52 , V_220 L_109 ) ;
return 0 ;
V_263:
F_134 ( V_16 -> V_217 , V_2 ) ;
V_253:
F_135 ( V_52 ) ;
V_250:
return V_14 ;
}
static int F_136 ( struct V_246 * V_16 )
{
struct V_1 * V_2 = F_137 ( V_16 ) ;
if ( F_5 ( V_2 ) )
F_6 (KERN_DEBUG DRV_NAME L_110 ) ;
F_138 ( V_2 -> V_203 ) ;
F_134 ( V_16 -> V_217 , V_2 ) ;
F_135 ( V_2 -> V_203 ) ;
return 0 ;
}
static int T_6 F_139 ( void )
{
V_51 = F_140 ( 20 ) ;
return F_141 ( & V_264 ) ;
}
static void T_7 F_142 ( void )
{
F_143 ( & V_264 ) ;
}
