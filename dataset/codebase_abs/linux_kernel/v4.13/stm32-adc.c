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
F_34 (bit, scan_mask, indio_dev->masklength) {
V_82 = V_40 -> V_84 + V_83 ;
V_54 ++ ;
if ( V_54 > V_85 )
return - V_86 ;
F_35 ( & V_40 -> V_44 , L_8 ,
V_87 , V_82 -> V_88 , V_54 ) ;
V_7 = F_1 ( V_2 , V_80 [ V_54 ] . V_3 ) ;
V_7 &= ~ V_80 [ V_54 ] . V_14 ;
V_7 |= V_82 -> V_88 << V_80 [ V_54 ] . V_17 ;
F_5 ( V_2 , V_80 [ V_54 ] . V_3 , V_7 ) ;
}
if ( ! V_54 )
return - V_86 ;
V_7 = F_1 ( V_2 , V_80 [ 0 ] . V_3 ) ;
V_7 &= ~ V_80 [ 0 ] . V_14 ;
V_7 |= ( ( V_54 - 1 ) << V_80 [ 0 ] . V_17 ) ;
F_5 ( V_2 , V_80 [ 0 ] . V_3 , V_7 ) ;
return 0 ;
}
static int F_36 ( struct V_39 * V_40 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_54 ;
for ( V_54 = 0 ; V_2 -> V_11 -> V_91 [ V_54 ] . V_92 ; V_54 ++ ) {
if ( F_37 ( V_90 ) &&
! strcmp ( V_2 -> V_11 -> V_91 [ V_54 ] . V_92 , V_90 -> V_92 ) ) {
return V_2 -> V_11 -> V_91 [ V_54 ] . V_93 ;
}
}
return - V_86 ;
}
static int F_38 ( struct V_39 * V_40 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
T_1 V_7 , V_93 = 0 , V_94 = V_95 ;
unsigned long V_9 ;
int V_41 ;
if ( V_90 ) {
V_41 = F_36 ( V_40 , V_90 ) ;
if ( V_41 < 0 )
return V_41 ;
V_93 = V_41 ;
V_94 = V_2 -> V_96 + V_97 ;
}
F_8 ( & V_2 -> V_10 , V_9 ) ;
V_7 = F_1 ( V_2 , V_2 -> V_11 -> V_12 -> V_94 . V_3 ) ;
V_7 &= ~ ( V_2 -> V_11 -> V_12 -> V_94 . V_14 | V_2 -> V_11 -> V_12 -> V_93 . V_14 ) ;
V_7 |= V_94 << V_2 -> V_11 -> V_12 -> V_94 . V_17 ;
V_7 |= V_93 << V_2 -> V_11 -> V_12 -> V_93 . V_17 ;
F_5 ( V_2 , V_2 -> V_11 -> V_12 -> V_94 . V_3 , V_7 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
return 0 ;
}
static int F_39 ( struct V_39 * V_40 ,
const struct V_81 * V_82 ,
unsigned int type )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
V_2 -> V_96 = type ;
return 0 ;
}
static int F_40 ( struct V_39 * V_40 ,
const struct V_81 * V_82 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
return V_2 -> V_96 ;
}
static int F_41 ( struct V_39 * V_40 ,
const struct V_81 * V_82 ,
int * V_16 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
const struct V_98 * V_12 = V_2 -> V_11 -> V_12 ;
long V_99 ;
T_1 V_7 ;
int V_41 ;
F_42 ( & V_2 -> V_100 ) ;
V_2 -> V_101 = 0 ;
if ( V_2 -> V_11 -> V_102 ) {
V_41 = V_2 -> V_11 -> V_102 ( V_2 ) ;
if ( V_41 )
return V_41 ;
}
V_7 = F_1 ( V_2 , V_12 -> V_80 [ 1 ] . V_3 ) ;
V_7 &= ~ V_12 -> V_80 [ 1 ] . V_14 ;
V_7 |= V_82 -> V_88 << V_12 -> V_80 [ 1 ] . V_17 ;
F_5 ( V_2 , V_12 -> V_80 [ 1 ] . V_3 , V_7 ) ;
F_10 ( V_2 , V_12 -> V_80 [ 0 ] . V_3 , V_12 -> V_80 [ 0 ] . V_14 ) ;
F_10 ( V_2 , V_12 -> V_94 . V_3 , V_12 -> V_94 . V_14 ) ;
F_11 ( V_2 ) ;
V_2 -> V_11 -> V_103 ( V_2 , false ) ;
V_99 = F_43 (
& V_2 -> V_100 , V_104 ) ;
if ( V_99 == 0 ) {
V_41 = - V_105 ;
} else if ( V_99 < 0 ) {
V_41 = V_99 ;
} else {
* V_16 = V_2 -> V_106 [ 0 ] ;
V_41 = V_107 ;
}
V_2 -> V_11 -> V_108 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_11 -> V_109 )
V_2 -> V_11 -> V_109 ( V_2 ) ;
return V_41 ;
}
static int F_44 ( struct V_39 * V_40 ,
struct V_81 const * V_82 ,
int * V_7 , int * V_110 , long V_14 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_41 ;
switch ( V_14 ) {
case V_111 :
V_41 = F_45 ( V_40 ) ;
if ( V_41 )
return V_41 ;
if ( V_82 -> type == V_112 )
V_41 = F_41 ( V_40 , V_82 , V_7 ) ;
else
V_41 = - V_86 ;
F_46 ( V_40 ) ;
return V_41 ;
case V_113 :
* V_7 = V_2 -> V_4 -> V_114 ;
* V_110 = V_82 -> V_115 . V_116 ;
return V_117 ;
default:
return - V_86 ;
}
}
static T_3 F_47 ( int V_118 , void * V_119 )
{
struct V_1 * V_2 = V_119 ;
struct V_39 * V_40 = F_19 ( V_2 ) ;
const struct V_98 * V_12 = V_2 -> V_11 -> V_12 ;
T_1 V_120 = F_1 ( V_2 , V_12 -> V_121 . V_3 ) ;
if ( V_120 & V_12 -> V_121 . V_14 ) {
V_2 -> V_106 [ V_2 -> V_101 ] = F_3 ( V_2 , V_12 -> V_122 ) ;
if ( F_48 ( V_40 ) ) {
V_2 -> V_101 ++ ;
if ( V_2 -> V_101 >= V_2 -> V_123 ) {
F_12 ( V_2 ) ;
F_49 ( V_40 -> V_90 ) ;
}
} else {
F_50 ( & V_2 -> V_100 ) ;
}
return V_124 ;
}
return V_125 ;
}
static int F_51 ( struct V_39 * V_40 ,
struct V_89 * V_90 )
{
return F_36 ( V_40 , V_90 ) < 0 ? - V_86 : 0 ;
}
static int F_52 ( struct V_39 * V_40 , unsigned int V_7 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
unsigned int V_126 = V_127 / 2 ;
V_126 = F_53 ( V_126 , V_7 * ( unsigned ) ( sizeof( T_2 ) ) ) ;
V_2 -> V_128 = V_126 * 2 ;
return 0 ;
}
static int F_54 ( struct V_39 * V_40 ,
const unsigned long * V_79 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_41 ;
V_2 -> V_123 = F_55 ( V_79 , V_40 -> V_129 ) ;
V_41 = F_32 ( V_40 , V_79 ) ;
if ( V_41 )
return V_41 ;
return 0 ;
}
static int F_56 ( struct V_39 * V_40 ,
const struct V_130 * V_131 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_40 -> V_132 ; V_54 ++ )
if ( V_40 -> V_84 [ V_54 ] . V_88 == V_131 -> args [ 0 ] )
return V_54 ;
return - V_86 ;
}
static int F_57 ( struct V_39 * V_40 ,
unsigned V_3 , unsigned V_133 ,
unsigned * V_134 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
if ( ! V_134 )
F_5 ( V_2 , V_3 , V_133 ) ;
else
* V_134 = F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static unsigned int F_58 ( struct V_1 * V_2 )
{
struct V_135 V_136 ;
enum V_137 V_120 ;
V_120 = F_59 ( V_2 -> V_138 ,
V_2 -> V_138 -> V_139 ,
& V_136 ) ;
if ( V_120 == V_140 ) {
unsigned int V_54 = V_2 -> V_128 - V_136 . V_141 ;
unsigned int V_142 ;
if ( V_54 >= V_2 -> V_101 )
V_142 = V_54 - V_2 -> V_101 ;
else
V_142 = V_2 -> V_128 + V_54 - V_2 -> V_101 ;
return V_142 ;
}
return 0 ;
}
static void F_60 ( void * V_119 )
{
struct V_39 * V_40 = V_119 ;
F_61 ( V_40 -> V_90 ) ;
}
static int F_62 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
struct V_143 * V_144 ;
T_4 V_139 ;
int V_41 ;
if ( ! V_2 -> V_138 )
return 0 ;
F_35 ( & V_40 -> V_44 , L_9 , V_87 ,
V_2 -> V_128 , V_2 -> V_128 / 2 ) ;
V_144 = F_63 ( V_2 -> V_138 ,
V_2 -> V_145 ,
V_2 -> V_128 , V_2 -> V_128 / 2 ,
V_146 ,
V_147 ) ;
if ( ! V_144 )
return - V_148 ;
V_144 -> V_149 = F_60 ;
V_144 -> V_150 = V_40 ;
V_139 = F_64 ( V_144 ) ;
V_41 = F_65 ( V_139 ) ;
if ( V_41 ) {
F_66 ( V_2 -> V_138 ) ;
return V_41 ;
}
F_67 ( V_2 -> V_138 ) ;
return 0 ;
}
static int F_68 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_41 ;
if ( V_2 -> V_11 -> V_102 ) {
V_41 = V_2 -> V_11 -> V_102 ( V_2 ) ;
if ( V_41 )
return V_41 ;
}
V_41 = F_38 ( V_40 , V_40 -> V_90 ) ;
if ( V_41 ) {
F_25 ( & V_40 -> V_44 , L_10 ) ;
goto V_151;
}
V_41 = F_62 ( V_40 ) ;
if ( V_41 ) {
F_25 ( & V_40 -> V_44 , L_11 ) ;
goto V_152;
}
V_41 = F_69 ( V_40 ) ;
if ( V_41 < 0 )
goto V_153;
V_2 -> V_101 = 0 ;
if ( ! V_2 -> V_138 )
F_11 ( V_2 ) ;
V_2 -> V_11 -> V_103 ( V_2 , ! ! V_2 -> V_138 ) ;
return 0 ;
V_153:
if ( V_2 -> V_138 )
F_66 ( V_2 -> V_138 ) ;
V_152:
F_38 ( V_40 , NULL ) ;
V_151:
if ( V_2 -> V_11 -> V_109 )
V_2 -> V_11 -> V_109 ( V_2 ) ;
return V_41 ;
}
static int F_70 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_41 ;
V_2 -> V_11 -> V_108 ( V_2 ) ;
if ( ! V_2 -> V_138 )
F_12 ( V_2 ) ;
V_41 = F_71 ( V_40 ) ;
if ( V_41 < 0 )
F_25 ( & V_40 -> V_44 , L_12 ) ;
if ( V_2 -> V_138 )
F_66 ( V_2 -> V_138 ) ;
if ( F_38 ( V_40 , NULL ) )
F_25 ( & V_40 -> V_44 , L_13 ) ;
if ( V_2 -> V_11 -> V_109 )
V_2 -> V_11 -> V_109 ( V_2 ) ;
return V_41 ;
}
static T_3 F_72 ( int V_118 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
struct V_39 * V_40 = V_156 -> V_40 ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
F_35 ( & V_40 -> V_44 , L_14 , V_87 , V_2 -> V_101 ) ;
if ( ! V_2 -> V_138 ) {
V_2 -> V_101 = 0 ;
F_73 ( V_40 , V_2 -> V_106 ,
V_156 -> V_157 ) ;
} else {
int V_141 = F_58 ( V_2 ) ;
while ( V_141 >= V_40 -> V_158 ) {
T_2 * V_106 = ( T_2 * ) & V_2 -> V_159 [ V_2 -> V_101 ] ;
F_73 ( V_40 , V_106 ,
V_156 -> V_157 ) ;
V_141 -= V_40 -> V_158 ;
V_2 -> V_101 += V_40 -> V_158 ;
if ( V_2 -> V_101 >= V_2 -> V_128 )
V_2 -> V_101 = 0 ;
}
}
F_74 ( V_40 -> V_90 ) ;
if ( ! V_2 -> V_138 )
F_11 ( V_2 ) ;
return V_124 ;
}
static int F_75 ( struct V_39 * V_40 )
{
struct V_160 * V_161 = V_40 -> V_44 . V_162 ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
unsigned int V_54 ;
T_1 V_16 ;
if ( F_76 ( V_161 , L_15 , & V_16 ) )
V_16 = V_2 -> V_11 -> V_163 -> V_164 [ 0 ] ;
for ( V_54 = 0 ; V_54 < V_2 -> V_11 -> V_163 -> V_165 ; V_54 ++ )
if ( V_16 == V_2 -> V_11 -> V_163 -> V_164 [ V_54 ] )
break;
if ( V_54 >= V_2 -> V_11 -> V_163 -> V_165 ) {
F_25 ( & V_40 -> V_44 , L_16 , V_16 ) ;
return - V_86 ;
}
F_35 ( & V_40 -> V_44 , L_17 , V_16 ) ;
V_2 -> V_16 = V_54 ;
return 0 ;
}
static void F_77 ( struct V_39 * V_40 ,
struct V_81 * V_82 ,
const struct V_166 * V_88 ,
int V_167 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
V_82 -> type = V_88 -> type ;
V_82 -> V_88 = V_88 -> V_88 ;
V_82 -> V_168 = V_88 -> V_92 ;
V_82 -> V_167 = V_167 ;
V_82 -> V_169 = 1 ;
V_82 -> V_170 = F_78 ( V_111 ) ;
V_82 -> V_171 = F_78 ( V_113 ) ;
V_82 -> V_115 . V_172 = 'u' ;
V_82 -> V_115 . V_116 = V_2 -> V_11 -> V_163 -> V_164 [ V_2 -> V_16 ] ;
V_82 -> V_115 . V_173 = 16 ;
V_82 -> V_174 = V_175 ;
V_2 -> V_78 |= F_78 ( V_82 -> V_88 ) ;
}
static int F_79 ( struct V_39 * V_40 )
{
struct V_160 * V_161 = V_40 -> V_44 . V_162 ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
const struct V_176 * V_163 = V_2 -> V_11 -> V_163 ;
struct V_177 * V_178 ;
const T_5 * V_179 ;
struct V_81 * V_84 ;
int V_167 = 0 , V_132 ;
T_1 V_7 ;
V_132 = F_80 ( V_161 , L_18 ) ;
if ( V_132 < 0 ||
V_132 >= V_163 -> V_180 ) {
F_25 ( & V_40 -> V_44 , L_19 ) ;
return V_132 < 0 ? V_132 : - V_86 ;
}
V_84 = F_81 ( & V_40 -> V_44 , V_132 ,
sizeof( struct V_81 ) , V_181 ) ;
if ( ! V_84 )
return - V_182 ;
F_82 (node, L_18 , prop, cur, val) {
if ( V_7 >= V_163 -> V_180 ) {
F_25 ( & V_40 -> V_44 , L_20 , V_7 ) ;
return - V_86 ;
}
F_77 ( V_40 , & V_84 [ V_167 ] ,
& V_163 -> V_84 [ V_7 ] ,
V_167 ) ;
V_167 ++ ;
}
V_40 -> V_132 = V_167 ;
V_40 -> V_84 = V_84 ;
return 0 ;
}
static int F_83 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
struct V_183 V_184 ;
int V_41 ;
V_2 -> V_138 = F_84 ( & V_40 -> V_44 , L_21 ) ;
if ( ! V_2 -> V_138 )
return 0 ;
V_2 -> V_159 = F_85 ( V_2 -> V_138 -> V_185 -> V_44 ,
V_127 ,
& V_2 -> V_145 , V_181 ) ;
if ( ! V_2 -> V_159 ) {
V_41 = - V_182 ;
goto V_186;
}
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
V_184 . V_187 = ( V_188 ) V_2 -> V_4 -> V_189 ;
V_184 . V_187 += V_2 -> V_6 + V_2 -> V_11 -> V_12 -> V_122 ;
V_184 . V_190 = V_191 ;
V_41 = F_86 ( V_2 -> V_138 , & V_184 ) ;
if ( V_41 )
goto V_192;
return 0 ;
V_192:
F_87 ( V_2 -> V_138 -> V_185 -> V_44 , V_127 ,
V_2 -> V_159 , V_2 -> V_145 ) ;
V_186:
F_88 ( V_2 -> V_138 ) ;
return V_41 ;
}
static int F_89 ( struct V_193 * V_194 )
{
struct V_39 * V_40 ;
struct V_185 * V_44 = & V_194 -> V_44 ;
struct V_1 * V_2 ;
int V_41 ;
if ( ! V_194 -> V_44 . V_162 )
return - V_195 ;
V_40 = F_90 ( & V_194 -> V_44 , sizeof( * V_2 ) ) ;
if ( ! V_40 )
return - V_182 ;
V_2 = F_33 ( V_40 ) ;
V_2 -> V_4 = F_91 ( V_194 -> V_44 . V_196 ) ;
F_92 ( & V_2 -> V_10 ) ;
F_93 ( & V_2 -> V_100 ) ;
V_2 -> V_11 = ( const struct V_197 * )
F_94 ( V_44 -> V_198 -> V_199 , V_44 ) -> V_119 ;
V_40 -> V_92 = F_95 ( & V_194 -> V_44 ) ;
V_40 -> V_44 . V_196 = & V_194 -> V_44 ;
V_40 -> V_44 . V_162 = V_194 -> V_44 . V_162 ;
V_40 -> V_200 = & V_201 ;
V_40 -> V_202 = V_203 ;
F_96 ( V_194 , V_2 ) ;
V_41 = F_76 ( V_194 -> V_44 . V_162 , L_22 , & V_2 -> V_6 ) ;
if ( V_41 != 0 ) {
F_25 ( & V_194 -> V_44 , L_23 ) ;
return - V_86 ;
}
V_2 -> V_118 = F_97 ( V_194 , 0 ) ;
if ( V_2 -> V_118 < 0 ) {
F_25 ( & V_194 -> V_44 , L_24 ) ;
return V_2 -> V_118 ;
}
V_41 = F_98 ( & V_194 -> V_44 , V_2 -> V_118 , F_47 ,
0 , V_194 -> V_92 , V_2 ) ;
if ( V_41 ) {
F_25 ( & V_194 -> V_44 , L_25 ) ;
return V_41 ;
}
V_2 -> V_204 = F_99 ( & V_194 -> V_44 , NULL ) ;
if ( F_100 ( V_2 -> V_204 ) ) {
V_41 = F_101 ( V_2 -> V_204 ) ;
if ( V_41 == - V_205 && ! V_2 -> V_11 -> V_206 ) {
V_2 -> V_204 = NULL ;
} else {
F_25 ( & V_194 -> V_44 , L_26 ) ;
return V_41 ;
}
}
if ( V_2 -> V_204 ) {
V_41 = F_102 ( V_2 -> V_204 ) ;
if ( V_41 < 0 ) {
F_25 ( & V_194 -> V_44 , L_27 ) ;
return V_41 ;
}
}
V_41 = F_75 ( V_40 ) ;
if ( V_41 < 0 )
goto V_207;
F_13 ( V_2 ) ;
if ( V_2 -> V_11 -> V_208 ) {
V_41 = V_2 -> V_11 -> V_208 ( V_2 ) ;
if ( V_41 )
goto V_207;
}
V_41 = F_79 ( V_40 ) ;
if ( V_41 < 0 )
goto V_207;
V_41 = F_83 ( V_40 ) ;
if ( V_41 < 0 )
goto V_207;
V_41 = F_103 ( V_40 ,
& V_209 ,
& F_72 ,
& V_210 ) ;
if ( V_41 ) {
F_25 ( & V_194 -> V_44 , L_28 ) ;
goto V_211;
}
V_41 = F_104 ( V_40 ) ;
if ( V_41 ) {
F_25 ( & V_194 -> V_44 , L_29 ) ;
goto V_212;
}
return 0 ;
V_212:
F_105 ( V_40 ) ;
V_211:
if ( V_2 -> V_138 ) {
F_87 ( V_2 -> V_138 -> V_185 -> V_44 ,
V_127 ,
V_2 -> V_159 , V_2 -> V_145 ) ;
F_88 ( V_2 -> V_138 ) ;
}
V_207:
if ( V_2 -> V_204 )
F_106 ( V_2 -> V_204 ) ;
return V_41 ;
}
static int F_107 ( struct V_193 * V_194 )
{
struct V_1 * V_2 = F_108 ( V_194 ) ;
struct V_39 * V_40 = F_19 ( V_2 ) ;
F_109 ( V_40 ) ;
F_105 ( V_40 ) ;
if ( V_2 -> V_138 ) {
F_87 ( V_2 -> V_138 -> V_185 -> V_44 ,
V_127 ,
V_2 -> V_159 , V_2 -> V_145 ) ;
F_88 ( V_2 -> V_138 ) ;
}
if ( V_2 -> V_204 )
F_106 ( V_2 -> V_204 ) ;
return 0 ;
}
