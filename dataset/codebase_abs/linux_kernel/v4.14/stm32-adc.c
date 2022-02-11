static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_2 -> V_6 + V_3 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_4 -> V_5 + V_2 -> V_6 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
F_6 ( V_7 , V_2 -> V_4 -> V_5 + V_2 -> V_6 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_9 ;
F_8 ( & V_2 -> V_10 , V_9 ) ;
F_5 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) | V_8 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_9 ;
F_8 ( & V_2 -> V_10 , V_9 ) ;
F_5 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) & ~ V_8 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_2 -> V_11 -> V_12 -> V_13 . V_3 ,
V_2 -> V_11 -> V_12 -> V_13 . V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_2 -> V_11 -> V_12 -> V_13 . V_3 ,
V_2 -> V_11 -> V_12 -> V_13 . V_14 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = & V_2 -> V_11 -> V_12 -> V_16 ;
T_1 V_7 ;
V_7 = F_1 ( V_2 , V_16 -> V_3 ) ;
V_7 = ( V_7 & ~ V_16 -> V_14 ) | ( V_2 -> V_16 << V_16 -> V_17 ) ;
F_5 ( V_2 , V_16 -> V_3 , V_7 ) ;
}
static void F_14 ( struct V_1 * V_2 , bool V_18 )
{
F_7 ( V_2 , V_19 , V_20 ) ;
if ( V_18 )
F_7 ( V_2 , V_21 ,
V_22 | V_23 ) ;
F_7 ( V_2 , V_21 , V_24 | V_25 ) ;
F_15 ( 2 , 3 ) ;
if ( ! ( F_1 ( V_2 , V_21 ) & V_26 ) )
F_7 ( V_2 , V_21 , V_27 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_21 , V_26 ) ;
F_10 ( V_2 , V_28 , V_29 ) ;
F_10 ( V_2 , V_19 , V_20 ) ;
F_10 ( V_2 , V_21 ,
V_25 | V_22 | V_23 ) ;
}
static void F_17 ( struct V_1 * V_2 , bool V_18 )
{
enum V_30 V_31 ;
unsigned long V_9 ;
T_1 V_7 ;
if ( V_18 )
V_31 = V_32 ;
else
V_31 = V_33 ;
F_8 ( & V_2 -> V_10 , V_9 ) ;
V_7 = F_1 ( V_2 , V_34 ) ;
V_7 = ( V_7 & ~ V_35 ) | ( V_31 << V_36 ) ;
F_5 ( V_2 , V_34 , V_7 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
F_7 ( V_2 , V_37 , V_38 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_19 ( V_2 ) ;
int V_41 ;
T_1 V_7 ;
F_7 ( V_2 , V_37 , V_42 ) ;
V_41 = F_20 ( V_37 , V_7 ,
! ( V_7 & ( V_38 ) ) ,
100 , V_43 ) ;
if ( V_41 )
F_21 ( & V_40 -> V_44 , L_1 ) ;
F_10 ( V_2 , V_34 , V_35 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_37 , V_45 ) ;
F_7 ( V_2 , V_37 , V_46 ) ;
if ( V_2 -> V_4 -> V_47 > V_48 )
F_7 ( V_2 , V_37 , V_49 ) ;
F_15 ( 10 , 20 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_37 , V_49 ) ;
F_7 ( V_2 , V_37 , V_45 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_19 ( V_2 ) ;
int V_41 ;
T_1 V_7 ;
F_7 ( V_2 , V_50 , V_51 ) ;
F_7 ( V_2 , V_37 , V_52 ) ;
V_41 = F_20 ( V_50 , V_7 ,
V_7 & V_51 ,
100 , V_43 ) ;
if ( V_41 ) {
F_10 ( V_2 , V_37 , V_52 ) ;
F_25 ( & V_40 -> V_44 , L_2 ) ;
}
return V_41 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_19 ( V_2 ) ;
int V_41 ;
T_1 V_7 ;
F_7 ( V_2 , V_37 , V_53 ) ;
V_41 = F_20 ( V_37 , V_7 ,
! ( V_7 & V_52 ) , 100 ,
V_43 ) ;
if ( V_41 )
F_21 ( & V_40 -> V_44 , L_3 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_19 ( V_2 ) ;
int V_54 , V_41 ;
T_1 V_55 , V_7 ;
V_41 = F_24 ( V_2 ) ;
if ( V_41 )
return V_41 ;
V_55 = V_56 ;
for ( V_54 = V_57 - 1 ; V_54 >= 0 ; V_54 -- ) {
F_10 ( V_2 , V_37 , V_55 ) ;
V_41 = F_20 ( V_37 , V_7 ,
! ( V_7 & V_55 ) ,
100 , V_43 ) ;
if ( V_41 ) {
F_25 ( & V_40 -> V_44 , L_4 ) ;
goto V_58;
}
V_7 = F_1 ( V_2 , V_59 ) ;
V_2 -> V_60 . V_61 [ V_54 ] = ( V_7 & V_62 ) ;
V_2 -> V_60 . V_61 [ V_54 ] >>= V_63 ;
V_55 >>= 1 ;
}
V_7 = F_1 ( V_2 , V_64 ) ;
V_2 -> V_60 . V_65 = ( V_7 & V_66 ) ;
V_2 -> V_60 . V_65 >>= V_67 ;
V_2 -> V_60 . V_68 = ( V_7 & V_69 ) ;
V_2 -> V_60 . V_68 >>= V_70 ;
V_58:
F_26 ( V_2 ) ;
return V_41 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_19 ( V_2 ) ;
int V_54 , V_41 ;
T_1 V_55 , V_7 ;
V_7 = ( V_2 -> V_60 . V_65 << V_67 ) |
( V_2 -> V_60 . V_68 << V_70 ) ;
F_5 ( V_2 , V_64 , V_7 ) ;
V_55 = V_56 ;
for ( V_54 = V_57 - 1 ; V_54 >= 0 ; V_54 -- ) {
V_7 = V_2 -> V_60 . V_61 [ V_54 ] << V_63 ;
F_5 ( V_2 , V_59 , V_7 ) ;
F_7 ( V_2 , V_37 , V_55 ) ;
V_41 = F_20 ( V_37 , V_7 ,
V_7 & V_55 ,
100 , V_43 ) ;
if ( V_41 ) {
F_25 ( & V_40 -> V_44 , L_5 ) ;
return V_41 ;
}
F_10 ( V_2 , V_37 , V_55 ) ;
V_41 = F_20 ( V_37 , V_7 ,
! ( V_7 & V_55 ) ,
100 , V_43 ) ;
if ( V_41 ) {
F_25 ( & V_40 -> V_44 , L_4 ) ;
return V_41 ;
}
V_7 = F_1 ( V_2 , V_59 ) ;
if ( V_7 != V_2 -> V_60 . V_61 [ V_54 ] << V_63 ) {
F_25 ( & V_40 -> V_44 , L_6 ) ;
return - V_71 ;
}
V_55 >>= 1 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_19 ( V_2 ) ;
int V_41 ;
T_1 V_7 ;
F_22 ( V_2 ) ;
F_10 ( V_2 , V_37 , V_72 ) ;
F_10 ( V_2 , V_37 , V_73 ) ;
F_7 ( V_2 , V_37 , V_74 ) ;
V_41 = F_20 ( V_37 , V_7 ,
! ( V_7 & V_74 ) , 100 ,
V_75 ) ;
if ( V_41 ) {
F_25 ( & V_40 -> V_44 , L_7 ) ;
goto V_76;
}
F_7 ( V_2 , V_37 ,
V_72 | V_73 ) ;
F_7 ( V_2 , V_37 , V_74 ) ;
V_41 = F_20 ( V_37 , V_7 ,
! ( V_7 & V_74 ) , 100 ,
V_75 ) ;
if ( V_41 ) {
F_25 ( & V_40 -> V_44 , L_7 ) ;
goto V_76;
}
F_10 ( V_2 , V_37 ,
V_72 | V_73 ) ;
V_41 = F_27 ( V_2 ) ;
V_76:
F_23 ( V_2 ) ;
return V_41 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_41 ;
F_22 ( V_2 ) ;
V_41 = F_24 ( V_2 ) ;
if ( V_41 )
goto V_76;
V_41 = F_28 ( V_2 ) ;
if ( V_41 )
goto V_58;
F_5 ( V_2 , V_77 , V_2 -> V_78 ) ;
return 0 ;
V_58:
F_26 ( V_2 ) ;
V_76:
F_23 ( V_2 ) ;
return V_41 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
F_23 ( V_2 ) ;
}
static int F_32 ( struct V_39 * V_40 ,
const unsigned long * V_79 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
const struct V_15 * V_80 = V_2 -> V_11 -> V_12 -> V_80 ;
const struct V_81 * V_82 ;
T_1 V_7 , V_83 ;
int V_54 = 0 ;
F_5 ( V_2 , V_2 -> V_11 -> V_12 -> V_84 [ 0 ] , V_2 -> V_85 [ 0 ] ) ;
F_5 ( V_2 , V_2 -> V_11 -> V_12 -> V_84 [ 1 ] , V_2 -> V_85 [ 1 ] ) ;
F_34 (bit, scan_mask, indio_dev->masklength) {
V_82 = V_40 -> V_86 + V_83 ;
V_54 ++ ;
if ( V_54 > V_87 )
return - V_88 ;
F_35 ( & V_40 -> V_44 , L_8 ,
V_89 , V_82 -> V_90 , V_54 ) ;
V_7 = F_1 ( V_2 , V_80 [ V_54 ] . V_3 ) ;
V_7 &= ~ V_80 [ V_54 ] . V_14 ;
V_7 |= V_82 -> V_90 << V_80 [ V_54 ] . V_17 ;
F_5 ( V_2 , V_80 [ V_54 ] . V_3 , V_7 ) ;
}
if ( ! V_54 )
return - V_88 ;
V_7 = F_1 ( V_2 , V_80 [ 0 ] . V_3 ) ;
V_7 &= ~ V_80 [ 0 ] . V_14 ;
V_7 |= ( ( V_54 - 1 ) << V_80 [ 0 ] . V_17 ) ;
F_5 ( V_2 , V_80 [ 0 ] . V_3 , V_7 ) ;
return 0 ;
}
static int F_36 ( struct V_39 * V_40 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_54 ;
for ( V_54 = 0 ; V_2 -> V_11 -> V_93 [ V_54 ] . V_94 ; V_54 ++ ) {
if ( ( F_37 ( V_92 ) ||
F_38 ( V_92 ) ) &&
! strcmp ( V_2 -> V_11 -> V_93 [ V_54 ] . V_94 , V_92 -> V_94 ) ) {
return V_2 -> V_11 -> V_93 [ V_54 ] . V_95 ;
}
}
return - V_88 ;
}
static int F_39 ( struct V_39 * V_40 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
T_1 V_7 , V_95 = 0 , V_96 = V_97 ;
unsigned long V_9 ;
int V_41 ;
if ( V_92 ) {
V_41 = F_36 ( V_40 , V_92 ) ;
if ( V_41 < 0 )
return V_41 ;
V_95 = V_41 ;
V_96 = V_2 -> V_98 + V_99 ;
}
F_8 ( & V_2 -> V_10 , V_9 ) ;
V_7 = F_1 ( V_2 , V_2 -> V_11 -> V_12 -> V_96 . V_3 ) ;
V_7 &= ~ ( V_2 -> V_11 -> V_12 -> V_96 . V_14 | V_2 -> V_11 -> V_12 -> V_95 . V_14 ) ;
V_7 |= V_96 << V_2 -> V_11 -> V_12 -> V_96 . V_17 ;
V_7 |= V_95 << V_2 -> V_11 -> V_12 -> V_95 . V_17 ;
F_5 ( V_2 , V_2 -> V_11 -> V_12 -> V_96 . V_3 , V_7 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
return 0 ;
}
static int F_40 ( struct V_39 * V_40 ,
const struct V_81 * V_82 ,
unsigned int type )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
V_2 -> V_98 = type ;
return 0 ;
}
static int F_41 ( struct V_39 * V_40 ,
const struct V_81 * V_82 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
return V_2 -> V_98 ;
}
static int F_42 ( struct V_39 * V_40 ,
const struct V_81 * V_82 ,
int * V_16 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
const struct V_100 * V_12 = V_2 -> V_11 -> V_12 ;
long V_101 ;
T_1 V_7 ;
int V_41 ;
F_43 ( & V_2 -> V_102 ) ;
V_2 -> V_103 = 0 ;
if ( V_2 -> V_11 -> V_104 ) {
V_41 = V_2 -> V_11 -> V_104 ( V_2 ) ;
if ( V_41 )
return V_41 ;
}
F_5 ( V_2 , V_12 -> V_84 [ 0 ] , V_2 -> V_85 [ 0 ] ) ;
F_5 ( V_2 , V_12 -> V_84 [ 1 ] , V_2 -> V_85 [ 1 ] ) ;
V_7 = F_1 ( V_2 , V_12 -> V_80 [ 1 ] . V_3 ) ;
V_7 &= ~ V_12 -> V_80 [ 1 ] . V_14 ;
V_7 |= V_82 -> V_90 << V_12 -> V_80 [ 1 ] . V_17 ;
F_5 ( V_2 , V_12 -> V_80 [ 1 ] . V_3 , V_7 ) ;
F_10 ( V_2 , V_12 -> V_80 [ 0 ] . V_3 , V_12 -> V_80 [ 0 ] . V_14 ) ;
F_10 ( V_2 , V_12 -> V_96 . V_3 , V_12 -> V_96 . V_14 ) ;
F_11 ( V_2 ) ;
V_2 -> V_11 -> V_105 ( V_2 , false ) ;
V_101 = F_44 (
& V_2 -> V_102 , V_106 ) ;
if ( V_101 == 0 ) {
V_41 = - V_107 ;
} else if ( V_101 < 0 ) {
V_41 = V_101 ;
} else {
* V_16 = V_2 -> V_108 [ 0 ] ;
V_41 = V_109 ;
}
V_2 -> V_11 -> V_110 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_11 -> V_111 )
V_2 -> V_11 -> V_111 ( V_2 ) ;
return V_41 ;
}
static int F_45 ( struct V_39 * V_40 ,
struct V_81 const * V_82 ,
int * V_7 , int * V_112 , long V_14 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_41 ;
switch ( V_14 ) {
case V_113 :
V_41 = F_46 ( V_40 ) ;
if ( V_41 )
return V_41 ;
if ( V_82 -> type == V_114 )
V_41 = F_42 ( V_40 , V_82 , V_7 ) ;
else
V_41 = - V_88 ;
F_47 ( V_40 ) ;
return V_41 ;
case V_115 :
* V_7 = V_2 -> V_4 -> V_116 ;
* V_112 = V_82 -> V_117 . V_118 ;
return V_119 ;
default:
return - V_88 ;
}
}
static T_3 F_48 ( int V_120 , void * V_121 )
{
struct V_1 * V_2 = V_121 ;
struct V_39 * V_40 = F_19 ( V_2 ) ;
const struct V_100 * V_12 = V_2 -> V_11 -> V_12 ;
T_1 V_122 = F_1 ( V_2 , V_12 -> V_123 . V_3 ) ;
if ( V_122 & V_12 -> V_123 . V_14 ) {
V_2 -> V_108 [ V_2 -> V_103 ] = F_3 ( V_2 , V_12 -> V_124 ) ;
if ( F_49 ( V_40 ) ) {
V_2 -> V_103 ++ ;
if ( V_2 -> V_103 >= V_2 -> V_125 ) {
F_12 ( V_2 ) ;
F_50 ( V_40 -> V_92 ) ;
}
} else {
F_51 ( & V_2 -> V_102 ) ;
}
return V_126 ;
}
return V_127 ;
}
static int F_52 ( struct V_39 * V_40 ,
struct V_91 * V_92 )
{
return F_36 ( V_40 , V_92 ) < 0 ? - V_88 : 0 ;
}
static int F_53 ( struct V_39 * V_40 , unsigned int V_7 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
unsigned int V_128 = V_129 / 2 ;
V_128 = F_54 ( V_128 , V_7 * ( unsigned ) ( sizeof( T_2 ) ) ) ;
V_2 -> V_130 = V_128 * 2 ;
return 0 ;
}
static int F_55 ( struct V_39 * V_40 ,
const unsigned long * V_79 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_41 ;
V_2 -> V_125 = F_56 ( V_79 , V_40 -> V_131 ) ;
V_41 = F_32 ( V_40 , V_79 ) ;
if ( V_41 )
return V_41 ;
return 0 ;
}
static int F_57 ( struct V_39 * V_40 ,
const struct V_132 * V_133 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_40 -> V_134 ; V_54 ++ )
if ( V_40 -> V_86 [ V_54 ] . V_90 == V_133 -> args [ 0 ] )
return V_54 ;
return - V_88 ;
}
static int F_58 ( struct V_39 * V_40 ,
unsigned V_3 , unsigned V_135 ,
unsigned * V_136 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
if ( ! V_136 )
F_5 ( V_2 , V_3 , V_135 ) ;
else
* V_136 = F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static unsigned int F_59 ( struct V_1 * V_2 )
{
struct V_137 V_138 ;
enum V_139 V_122 ;
V_122 = F_60 ( V_2 -> V_140 ,
V_2 -> V_140 -> V_141 ,
& V_138 ) ;
if ( V_122 == V_142 ) {
unsigned int V_54 = V_2 -> V_130 - V_138 . V_143 ;
unsigned int V_144 ;
if ( V_54 >= V_2 -> V_103 )
V_144 = V_54 - V_2 -> V_103 ;
else
V_144 = V_2 -> V_130 + V_54 - V_2 -> V_103 ;
return V_144 ;
}
return 0 ;
}
static void F_61 ( void * V_121 )
{
struct V_39 * V_40 = V_121 ;
F_62 ( V_40 -> V_92 ) ;
}
static int F_63 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
struct V_145 * V_146 ;
T_4 V_141 ;
int V_41 ;
if ( ! V_2 -> V_140 )
return 0 ;
F_35 ( & V_40 -> V_44 , L_9 , V_89 ,
V_2 -> V_130 , V_2 -> V_130 / 2 ) ;
V_146 = F_64 ( V_2 -> V_140 ,
V_2 -> V_147 ,
V_2 -> V_130 , V_2 -> V_130 / 2 ,
V_148 ,
V_149 ) ;
if ( ! V_146 )
return - V_150 ;
V_146 -> V_151 = F_61 ;
V_146 -> V_152 = V_40 ;
V_141 = F_65 ( V_146 ) ;
V_41 = F_66 ( V_141 ) ;
if ( V_41 ) {
F_67 ( V_2 -> V_140 ) ;
return V_41 ;
}
F_68 ( V_2 -> V_140 ) ;
return 0 ;
}
static int F_69 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_41 ;
if ( V_2 -> V_11 -> V_104 ) {
V_41 = V_2 -> V_11 -> V_104 ( V_2 ) ;
if ( V_41 )
return V_41 ;
}
V_41 = F_39 ( V_40 , V_40 -> V_92 ) ;
if ( V_41 ) {
F_25 ( & V_40 -> V_44 , L_10 ) ;
goto V_153;
}
V_41 = F_63 ( V_40 ) ;
if ( V_41 ) {
F_25 ( & V_40 -> V_44 , L_11 ) ;
goto V_154;
}
V_41 = F_70 ( V_40 ) ;
if ( V_41 < 0 )
goto V_155;
V_2 -> V_103 = 0 ;
if ( ! V_2 -> V_140 )
F_11 ( V_2 ) ;
V_2 -> V_11 -> V_105 ( V_2 , ! ! V_2 -> V_140 ) ;
return 0 ;
V_155:
if ( V_2 -> V_140 )
F_67 ( V_2 -> V_140 ) ;
V_154:
F_39 ( V_40 , NULL ) ;
V_153:
if ( V_2 -> V_11 -> V_111 )
V_2 -> V_11 -> V_111 ( V_2 ) ;
return V_41 ;
}
static int F_71 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_41 ;
V_2 -> V_11 -> V_110 ( V_2 ) ;
if ( ! V_2 -> V_140 )
F_12 ( V_2 ) ;
V_41 = F_72 ( V_40 ) ;
if ( V_41 < 0 )
F_25 ( & V_40 -> V_44 , L_12 ) ;
if ( V_2 -> V_140 )
F_67 ( V_2 -> V_140 ) ;
if ( F_39 ( V_40 , NULL ) )
F_25 ( & V_40 -> V_44 , L_13 ) ;
if ( V_2 -> V_11 -> V_111 )
V_2 -> V_11 -> V_111 ( V_2 ) ;
return V_41 ;
}
static T_3 F_73 ( int V_120 , void * V_156 )
{
struct V_157 * V_158 = V_156 ;
struct V_39 * V_40 = V_158 -> V_40 ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
F_35 ( & V_40 -> V_44 , L_14 , V_89 , V_2 -> V_103 ) ;
if ( ! V_2 -> V_140 ) {
V_2 -> V_103 = 0 ;
F_74 ( V_40 , V_2 -> V_108 ,
V_158 -> V_159 ) ;
} else {
int V_143 = F_59 ( V_2 ) ;
while ( V_143 >= V_40 -> V_160 ) {
T_2 * V_108 = ( T_2 * ) & V_2 -> V_161 [ V_2 -> V_103 ] ;
F_74 ( V_40 , V_108 ,
V_158 -> V_159 ) ;
V_143 -= V_40 -> V_160 ;
V_2 -> V_103 += V_40 -> V_160 ;
if ( V_2 -> V_103 >= V_2 -> V_130 )
V_2 -> V_103 = 0 ;
}
}
F_75 ( V_40 -> V_92 ) ;
if ( ! V_2 -> V_140 )
F_11 ( V_2 ) ;
return V_126 ;
}
static int F_76 ( struct V_39 * V_40 )
{
struct V_162 * V_163 = V_40 -> V_44 . V_164 ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
unsigned int V_54 ;
T_1 V_16 ;
if ( F_77 ( V_163 , L_15 , & V_16 ) )
V_16 = V_2 -> V_11 -> V_165 -> V_166 [ 0 ] ;
for ( V_54 = 0 ; V_54 < V_2 -> V_11 -> V_165 -> V_167 ; V_54 ++ )
if ( V_16 == V_2 -> V_11 -> V_165 -> V_166 [ V_54 ] )
break;
if ( V_54 >= V_2 -> V_11 -> V_165 -> V_167 ) {
F_25 ( & V_40 -> V_44 , L_16 , V_16 ) ;
return - V_88 ;
}
F_35 ( & V_40 -> V_44 , L_17 , V_16 ) ;
V_2 -> V_16 = V_54 ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 , int V_90 , T_1 V_168 )
{
const struct V_15 * V_84 = & V_2 -> V_11 -> V_12 -> V_169 [ V_90 ] ;
T_1 V_170 , V_17 = V_84 -> V_17 , V_14 = V_84 -> V_14 ;
unsigned int V_171 , V_172 = V_84 -> V_3 ;
V_170 = V_173 / V_2 -> V_4 -> V_47 ;
for ( V_171 = 0 ; V_171 <= V_174 ; V_171 ++ )
if ( ( V_170 * V_2 -> V_11 -> V_175 [ V_171 ] ) >= V_168 )
break;
if ( V_171 > V_174 )
V_171 = V_174 ;
V_2 -> V_85 [ V_172 ] = ( V_2 -> V_85 [ V_172 ] & ~ V_14 ) | ( V_171 << V_17 ) ;
}
static void F_79 ( struct V_39 * V_40 ,
struct V_81 * V_82 ,
const struct V_176 * V_90 ,
int V_177 , T_1 V_171 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
V_82 -> type = V_90 -> type ;
V_82 -> V_90 = V_90 -> V_90 ;
V_82 -> V_178 = V_90 -> V_94 ;
V_82 -> V_177 = V_177 ;
V_82 -> V_179 = 1 ;
V_82 -> V_180 = F_80 ( V_113 ) ;
V_82 -> V_181 = F_80 ( V_115 ) ;
V_82 -> V_117 . V_182 = 'u' ;
V_82 -> V_117 . V_118 = V_2 -> V_11 -> V_165 -> V_166 [ V_2 -> V_16 ] ;
V_82 -> V_117 . V_183 = 16 ;
V_82 -> V_184 = V_185 ;
F_78 ( V_2 , V_82 -> V_90 , V_171 ) ;
V_2 -> V_78 |= F_80 ( V_82 -> V_90 ) ;
}
static int F_81 ( struct V_39 * V_40 )
{
struct V_162 * V_163 = V_40 -> V_44 . V_164 ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
const struct V_186 * V_165 = V_2 -> V_11 -> V_165 ;
struct V_187 * V_188 ;
const T_5 * V_189 ;
struct V_81 * V_86 ;
int V_177 = 0 , V_134 , V_41 ;
T_1 V_7 , V_171 = 0 ;
V_134 = F_82 ( V_163 , L_18 ) ;
if ( V_134 < 0 ||
V_134 > V_165 -> V_190 ) {
F_25 ( & V_40 -> V_44 , L_19 ) ;
return V_134 < 0 ? V_134 : - V_88 ;
}
V_41 = F_82 ( V_163 , L_20 ) ;
if ( V_41 > 1 && V_41 != V_134 ) {
F_25 ( & V_40 -> V_44 , L_21 ) ;
return - V_88 ;
}
V_86 = F_83 ( & V_40 -> V_44 , V_134 ,
sizeof( struct V_81 ) , V_191 ) ;
if ( ! V_86 )
return - V_192 ;
F_84 (node, L_18 , prop, cur, val) {
if ( V_7 >= V_165 -> V_190 ) {
F_25 ( & V_40 -> V_44 , L_22 , V_7 ) ;
return - V_88 ;
}
F_85 ( V_163 , L_20 ,
V_177 , & V_171 ) ;
F_79 ( V_40 , & V_86 [ V_177 ] ,
& V_165 -> V_86 [ V_7 ] ,
V_177 , V_171 ) ;
V_177 ++ ;
}
V_40 -> V_134 = V_177 ;
V_40 -> V_86 = V_86 ;
return 0 ;
}
static int F_86 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
struct V_193 V_194 ;
int V_41 ;
V_2 -> V_140 = F_87 ( & V_40 -> V_44 , L_23 ) ;
if ( ! V_2 -> V_140 )
return 0 ;
V_2 -> V_161 = F_88 ( V_2 -> V_140 -> V_195 -> V_44 ,
V_129 ,
& V_2 -> V_147 , V_191 ) ;
if ( ! V_2 -> V_161 ) {
V_41 = - V_192 ;
goto V_196;
}
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
V_194 . V_197 = ( V_198 ) V_2 -> V_4 -> V_199 ;
V_194 . V_197 += V_2 -> V_6 + V_2 -> V_11 -> V_12 -> V_124 ;
V_194 . V_200 = V_201 ;
V_41 = F_89 ( V_2 -> V_140 , & V_194 ) ;
if ( V_41 )
goto V_202;
return 0 ;
V_202:
F_90 ( V_2 -> V_140 -> V_195 -> V_44 , V_129 ,
V_2 -> V_161 , V_2 -> V_147 ) ;
V_196:
F_91 ( V_2 -> V_140 ) ;
return V_41 ;
}
static int F_92 ( struct V_203 * V_204 )
{
struct V_39 * V_40 ;
struct V_195 * V_44 = & V_204 -> V_44 ;
struct V_1 * V_2 ;
int V_41 ;
if ( ! V_204 -> V_44 . V_164 )
return - V_205 ;
V_40 = F_93 ( & V_204 -> V_44 , sizeof( * V_2 ) ) ;
if ( ! V_40 )
return - V_192 ;
V_2 = F_33 ( V_40 ) ;
V_2 -> V_4 = F_94 ( V_204 -> V_44 . V_206 ) ;
F_95 ( & V_2 -> V_10 ) ;
F_96 ( & V_2 -> V_102 ) ;
V_2 -> V_11 = ( const struct V_207 * )
F_97 ( V_44 -> V_208 -> V_209 , V_44 ) -> V_121 ;
V_40 -> V_94 = F_98 ( & V_204 -> V_44 ) ;
V_40 -> V_44 . V_206 = & V_204 -> V_44 ;
V_40 -> V_44 . V_164 = V_204 -> V_44 . V_164 ;
V_40 -> V_210 = & V_211 ;
V_40 -> V_212 = V_213 | V_214 ;
F_99 ( V_204 , V_2 ) ;
V_41 = F_77 ( V_204 -> V_44 . V_164 , L_24 , & V_2 -> V_6 ) ;
if ( V_41 != 0 ) {
F_25 ( & V_204 -> V_44 , L_25 ) ;
return - V_88 ;
}
V_2 -> V_120 = F_100 ( V_204 , 0 ) ;
if ( V_2 -> V_120 < 0 ) {
F_25 ( & V_204 -> V_44 , L_26 ) ;
return V_2 -> V_120 ;
}
V_41 = F_101 ( & V_204 -> V_44 , V_2 -> V_120 , F_48 ,
0 , V_204 -> V_94 , V_2 ) ;
if ( V_41 ) {
F_25 ( & V_204 -> V_44 , L_27 ) ;
return V_41 ;
}
V_2 -> V_215 = F_102 ( & V_204 -> V_44 , NULL ) ;
if ( F_103 ( V_2 -> V_215 ) ) {
V_41 = F_104 ( V_2 -> V_215 ) ;
if ( V_41 == - V_216 && ! V_2 -> V_11 -> V_217 ) {
V_2 -> V_215 = NULL ;
} else {
F_25 ( & V_204 -> V_44 , L_28 ) ;
return V_41 ;
}
}
if ( V_2 -> V_215 ) {
V_41 = F_105 ( V_2 -> V_215 ) ;
if ( V_41 < 0 ) {
F_25 ( & V_204 -> V_44 , L_29 ) ;
return V_41 ;
}
}
V_41 = F_76 ( V_40 ) ;
if ( V_41 < 0 )
goto V_218;
F_13 ( V_2 ) ;
if ( V_2 -> V_11 -> V_219 ) {
V_41 = V_2 -> V_11 -> V_219 ( V_2 ) ;
if ( V_41 )
goto V_218;
}
V_41 = F_81 ( V_40 ) ;
if ( V_41 < 0 )
goto V_218;
V_41 = F_86 ( V_40 ) ;
if ( V_41 < 0 )
goto V_218;
V_41 = F_106 ( V_40 ,
& V_220 ,
& F_73 ,
& V_221 ) ;
if ( V_41 ) {
F_25 ( & V_204 -> V_44 , L_30 ) ;
goto V_222;
}
V_41 = F_107 ( V_40 ) ;
if ( V_41 ) {
F_25 ( & V_204 -> V_44 , L_31 ) ;
goto V_223;
}
return 0 ;
V_223:
F_108 ( V_40 ) ;
V_222:
if ( V_2 -> V_140 ) {
F_90 ( V_2 -> V_140 -> V_195 -> V_44 ,
V_129 ,
V_2 -> V_161 , V_2 -> V_147 ) ;
F_91 ( V_2 -> V_140 ) ;
}
V_218:
if ( V_2 -> V_215 )
F_109 ( V_2 -> V_215 ) ;
return V_41 ;
}
static int F_110 ( struct V_203 * V_204 )
{
struct V_1 * V_2 = F_111 ( V_204 ) ;
struct V_39 * V_40 = F_19 ( V_2 ) ;
F_112 ( V_40 ) ;
F_108 ( V_40 ) ;
if ( V_2 -> V_140 ) {
F_90 ( V_2 -> V_140 -> V_195 -> V_44 ,
V_129 ,
V_2 -> V_161 , V_2 -> V_147 ) ;
F_91 ( V_2 -> V_140 ) ;
}
if ( V_2 -> V_215 )
F_109 ( V_2 -> V_215 ) ;
return 0 ;
}
