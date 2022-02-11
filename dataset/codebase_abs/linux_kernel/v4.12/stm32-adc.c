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
F_7 ( V_2 , V_11 , V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_11 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_7 = F_1 ( V_2 , V_11 ) ;
V_7 = ( V_7 & ~ V_13 ) | ( V_2 -> V_14 << V_15 ) ;
F_5 ( V_2 , V_11 , V_7 ) ;
}
static void F_14 ( struct V_1 * V_2 , bool V_16 )
{
F_7 ( V_2 , V_11 , V_17 ) ;
if ( V_16 )
F_7 ( V_2 , V_18 ,
V_19 | V_20 ) ;
F_7 ( V_2 , V_18 , V_21 | V_22 ) ;
F_15 ( 2 , 3 ) ;
if ( ! ( F_1 ( V_2 , V_18 ) & V_23 ) )
F_7 ( V_2 , V_18 , V_24 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_18 , V_23 ) ;
F_10 ( V_2 , V_25 , V_26 ) ;
F_10 ( V_2 , V_11 , V_17 ) ;
F_10 ( V_2 , V_18 ,
V_22 | V_19 | V_20 ) ;
}
static int F_17 ( struct V_27 * V_28 ,
const unsigned long * V_29 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
const struct V_30 * V_31 ;
T_1 V_7 , V_32 ;
int V_33 = 0 ;
F_19 (bit, scan_mask, indio_dev->masklength) {
V_31 = V_28 -> V_34 + V_32 ;
V_33 ++ ;
if ( V_33 > V_35 )
return - V_36 ;
F_20 ( & V_28 -> V_37 , L_1 ,
V_38 , V_31 -> V_39 , V_33 ) ;
V_7 = F_1 ( V_2 , V_40 [ V_33 ] . V_3 ) ;
V_7 &= ~ V_40 [ V_33 ] . V_41 ;
V_7 |= V_31 -> V_39 << V_40 [ V_33 ] . V_42 ;
F_5 ( V_2 , V_40 [ V_33 ] . V_3 , V_7 ) ;
}
if ( ! V_33 )
return - V_36 ;
V_7 = F_1 ( V_2 , V_40 [ 0 ] . V_3 ) ;
V_7 &= ~ V_40 [ 0 ] . V_41 ;
V_7 |= ( ( V_33 - 1 ) << V_40 [ 0 ] . V_42 ) ;
F_5 ( V_2 , V_40 [ 0 ] . V_3 , V_7 ) ;
return 0 ;
}
static int F_21 ( struct V_43 * V_44 )
{
int V_33 ;
for ( V_33 = 0 ; V_45 [ V_33 ] . V_46 ; V_33 ++ ) {
if ( F_22 ( V_44 ) &&
! strcmp ( V_45 [ V_33 ] . V_46 , V_44 -> V_46 ) ) {
return V_45 [ V_33 ] . V_47 ;
}
}
return - V_36 ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
T_1 V_7 , V_47 = 0 , V_48 = V_49 ;
unsigned long V_9 ;
int V_50 ;
if ( V_44 ) {
V_50 = F_21 ( V_44 ) ;
if ( V_50 < 0 )
return V_50 ;
V_47 = V_50 ;
V_48 = V_2 -> V_51 + V_52 ;
}
F_8 ( & V_2 -> V_10 , V_9 ) ;
V_7 = F_1 ( V_2 , V_18 ) ;
V_7 &= ~ ( V_23 | V_53 ) ;
V_7 |= V_48 << V_54 ;
V_7 |= V_47 << V_55 ;
F_5 ( V_2 , V_18 , V_7 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_27 * V_28 ,
const struct V_30 * V_31 ,
unsigned int type )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
V_2 -> V_51 = type ;
return 0 ;
}
static int F_25 ( struct V_27 * V_28 ,
const struct V_30 * V_31 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
return V_2 -> V_51 ;
}
static int F_26 ( struct V_27 * V_28 ,
const struct V_30 * V_31 ,
int * V_14 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
long V_56 ;
T_1 V_7 ;
int V_50 ;
F_27 ( & V_2 -> V_57 ) ;
V_2 -> V_58 = 0 ;
V_7 = F_1 ( V_2 , V_40 [ 1 ] . V_3 ) ;
V_7 &= ~ V_40 [ 1 ] . V_41 ;
V_7 |= V_31 -> V_39 << V_40 [ 1 ] . V_42 ;
F_5 ( V_2 , V_40 [ 1 ] . V_3 , V_7 ) ;
F_10 ( V_2 , V_40 [ 0 ] . V_3 , V_40 [ 0 ] . V_41 ) ;
F_10 ( V_2 , V_18 , V_23 ) ;
F_11 ( V_2 ) ;
F_14 ( V_2 , false ) ;
V_56 = F_28 (
& V_2 -> V_57 , V_59 ) ;
if ( V_56 == 0 ) {
V_50 = - V_60 ;
} else if ( V_56 < 0 ) {
V_50 = V_56 ;
} else {
* V_14 = V_2 -> V_61 [ 0 ] ;
V_50 = V_62 ;
}
F_16 ( V_2 ) ;
F_12 ( V_2 ) ;
return V_50 ;
}
static int F_29 ( struct V_27 * V_28 ,
struct V_30 const * V_31 ,
int * V_7 , int * V_63 , long V_41 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
int V_50 ;
switch ( V_41 ) {
case V_64 :
V_50 = F_30 ( V_28 ) ;
if ( V_50 )
return V_50 ;
if ( V_31 -> type == V_65 )
V_50 = F_26 ( V_28 , V_31 , V_7 ) ;
else
V_50 = - V_36 ;
F_31 ( V_28 ) ;
return V_50 ;
case V_66 :
* V_7 = V_2 -> V_4 -> V_67 ;
* V_63 = V_31 -> V_68 . V_69 ;
return V_70 ;
default:
return - V_36 ;
}
}
static T_3 F_32 ( int V_71 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
struct V_27 * V_28 = F_33 ( V_2 ) ;
T_1 V_73 = F_1 ( V_2 , V_25 ) ;
if ( V_73 & V_74 ) {
V_2 -> V_61 [ V_2 -> V_58 ] = F_3 ( V_2 , V_75 ) ;
if ( F_34 ( V_28 ) ) {
V_2 -> V_58 ++ ;
if ( V_2 -> V_58 >= V_2 -> V_76 ) {
F_12 ( V_2 ) ;
F_35 ( V_28 -> V_44 ) ;
}
} else {
F_36 ( & V_2 -> V_57 ) ;
}
return V_77 ;
}
return V_78 ;
}
static int F_37 ( struct V_27 * V_28 ,
struct V_43 * V_44 )
{
return F_21 ( V_44 ) < 0 ? - V_36 : 0 ;
}
static int F_38 ( struct V_27 * V_28 , unsigned int V_7 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
unsigned int V_79 = V_80 / 2 ;
V_79 = F_39 ( V_79 , V_7 * ( unsigned ) ( sizeof( T_2 ) ) ) ;
V_2 -> V_81 = V_79 * 2 ;
return 0 ;
}
static int F_40 ( struct V_27 * V_28 ,
const unsigned long * V_29 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
int V_50 ;
V_2 -> V_76 = F_41 ( V_29 , V_28 -> V_82 ) ;
V_50 = F_17 ( V_28 , V_29 ) ;
if ( V_50 )
return V_50 ;
return 0 ;
}
static int F_42 ( struct V_27 * V_28 ,
const struct V_83 * V_84 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_28 -> V_85 ; V_33 ++ )
if ( V_28 -> V_34 [ V_33 ] . V_39 == V_84 -> args [ 0 ] )
return V_33 ;
return - V_36 ;
}
static int F_43 ( struct V_27 * V_28 ,
unsigned V_3 , unsigned V_86 ,
unsigned * V_87 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
if ( ! V_87 )
F_5 ( V_2 , V_3 , V_86 ) ;
else
* V_87 = F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static unsigned int F_44 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
enum V_90 V_73 ;
V_73 = F_45 ( V_2 -> V_91 ,
V_2 -> V_91 -> V_92 ,
& V_89 ) ;
if ( V_73 == V_93 ) {
unsigned int V_33 = V_2 -> V_81 - V_89 . V_94 ;
unsigned int V_95 ;
if ( V_33 >= V_2 -> V_58 )
V_95 = V_33 - V_2 -> V_58 ;
else
V_95 = V_2 -> V_81 + V_33 - V_2 -> V_58 ;
return V_95 ;
}
return 0 ;
}
static void F_46 ( void * V_72 )
{
struct V_27 * V_28 = V_72 ;
F_47 ( V_28 -> V_44 ) ;
}
static int F_48 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_96 * V_97 ;
T_4 V_92 ;
int V_50 ;
if ( ! V_2 -> V_91 )
return 0 ;
F_20 ( & V_28 -> V_37 , L_2 , V_38 ,
V_2 -> V_81 , V_2 -> V_81 / 2 ) ;
V_97 = F_49 ( V_2 -> V_91 ,
V_2 -> V_98 ,
V_2 -> V_81 , V_2 -> V_81 / 2 ,
V_99 ,
V_100 ) ;
if ( ! V_97 )
return - V_101 ;
V_97 -> V_102 = F_46 ;
V_97 -> V_103 = V_28 ;
V_92 = F_50 ( V_97 ) ;
V_50 = F_51 ( V_92 ) ;
if ( V_50 ) {
F_52 ( V_2 -> V_91 ) ;
return V_50 ;
}
F_53 ( V_2 -> V_91 ) ;
return 0 ;
}
static int F_54 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
int V_50 ;
V_50 = F_23 ( V_28 , V_28 -> V_44 ) ;
if ( V_50 ) {
F_55 ( & V_28 -> V_37 , L_3 ) ;
return V_50 ;
}
V_50 = F_48 ( V_28 ) ;
if ( V_50 ) {
F_55 ( & V_28 -> V_37 , L_4 ) ;
goto V_104;
}
V_50 = F_56 ( V_28 ) ;
if ( V_50 < 0 )
goto V_105;
V_2 -> V_58 = 0 ;
if ( ! V_2 -> V_91 )
F_11 ( V_2 ) ;
F_14 ( V_2 , ! ! V_2 -> V_91 ) ;
return 0 ;
V_105:
if ( V_2 -> V_91 )
F_52 ( V_2 -> V_91 ) ;
V_104:
F_23 ( V_28 , NULL ) ;
return V_50 ;
}
static int F_57 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
int V_50 ;
F_16 ( V_2 ) ;
if ( ! V_2 -> V_91 )
F_12 ( V_2 ) ;
V_50 = F_58 ( V_28 ) ;
if ( V_50 < 0 )
F_55 ( & V_28 -> V_37 , L_5 ) ;
if ( V_2 -> V_91 )
F_52 ( V_2 -> V_91 ) ;
if ( F_23 ( V_28 , NULL ) )
F_55 ( & V_28 -> V_37 , L_6 ) ;
return V_50 ;
}
static T_3 F_59 ( int V_71 , void * V_106 )
{
struct V_107 * V_108 = V_106 ;
struct V_27 * V_28 = V_108 -> V_28 ;
struct V_1 * V_2 = F_18 ( V_28 ) ;
F_20 ( & V_28 -> V_37 , L_7 , V_38 , V_2 -> V_58 ) ;
if ( ! V_2 -> V_91 ) {
V_2 -> V_58 = 0 ;
F_60 ( V_28 , V_2 -> V_61 ,
V_108 -> V_109 ) ;
} else {
int V_94 = F_44 ( V_2 ) ;
while ( V_94 >= V_28 -> V_110 ) {
T_2 * V_61 = ( T_2 * ) & V_2 -> V_111 [ V_2 -> V_58 ] ;
F_60 ( V_28 , V_61 ,
V_108 -> V_109 ) ;
V_94 -= V_28 -> V_110 ;
V_2 -> V_58 += V_28 -> V_110 ;
if ( V_2 -> V_58 >= V_2 -> V_81 )
V_2 -> V_58 = 0 ;
}
}
F_61 ( V_28 -> V_44 ) ;
if ( ! V_2 -> V_91 )
F_11 ( V_2 ) ;
return V_77 ;
}
static int F_62 ( struct V_27 * V_28 )
{
struct V_112 * V_113 = V_28 -> V_37 . V_114 ;
struct V_1 * V_2 = F_18 ( V_28 ) ;
unsigned int V_33 ;
T_1 V_14 ;
if ( F_63 ( V_113 , L_8 , & V_14 ) )
V_14 = V_115 [ 0 ] ;
for ( V_33 = 0 ; V_33 < F_64 ( V_115 ) ; V_33 ++ )
if ( V_14 == V_115 [ V_33 ] )
break;
if ( V_33 >= F_64 ( V_115 ) ) {
F_55 ( & V_28 -> V_37 , L_9 , V_14 ) ;
return - V_36 ;
}
F_20 ( & V_28 -> V_37 , L_10 , V_14 ) ;
V_2 -> V_14 = V_33 ;
return 0 ;
}
static void F_65 ( struct V_27 * V_28 ,
struct V_30 * V_31 ,
const struct V_116 * V_39 ,
int V_117 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
V_31 -> type = V_39 -> type ;
V_31 -> V_39 = V_39 -> V_39 ;
V_31 -> V_118 = V_39 -> V_46 ;
V_31 -> V_117 = V_117 ;
V_31 -> V_119 = 1 ;
V_31 -> V_120 = F_66 ( V_64 ) ;
V_31 -> V_121 = F_66 ( V_66 ) ;
V_31 -> V_68 . V_122 = 'u' ;
V_31 -> V_68 . V_69 = V_115 [ V_2 -> V_14 ] ;
V_31 -> V_68 . V_123 = 16 ;
V_31 -> V_124 = V_125 ;
}
static int F_67 ( struct V_27 * V_28 )
{
struct V_112 * V_113 = V_28 -> V_37 . V_114 ;
struct V_126 * V_127 ;
const T_5 * V_128 ;
struct V_30 * V_34 ;
int V_117 = 0 , V_85 ;
T_1 V_7 ;
V_85 = F_68 ( V_113 , L_11 ) ;
if ( V_85 < 0 ||
V_85 >= F_64 ( V_129 ) ) {
F_55 ( & V_28 -> V_37 , L_12 ) ;
return V_85 < 0 ? V_85 : - V_36 ;
}
V_34 = F_69 ( & V_28 -> V_37 , V_85 ,
sizeof( struct V_30 ) , V_130 ) ;
if ( ! V_34 )
return - V_131 ;
F_70 (node, L_11 , prop, cur, val) {
if ( V_7 >= F_64 ( V_129 ) ) {
F_55 ( & V_28 -> V_37 , L_13 , V_7 ) ;
return - V_36 ;
}
F_65 ( V_28 , & V_34 [ V_117 ] ,
& V_129 [ V_7 ] ,
V_117 ) ;
V_117 ++ ;
}
V_28 -> V_85 = V_117 ;
V_28 -> V_34 = V_34 ;
return 0 ;
}
static int F_71 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_132 V_133 ;
int V_50 ;
V_2 -> V_91 = F_72 ( & V_28 -> V_37 , L_14 ) ;
if ( ! V_2 -> V_91 )
return 0 ;
V_2 -> V_111 = F_73 ( V_2 -> V_91 -> V_134 -> V_37 ,
V_80 ,
& V_2 -> V_98 , V_130 ) ;
if ( ! V_2 -> V_111 ) {
V_50 = - V_131 ;
goto V_135;
}
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_136 = ( V_137 ) V_2 -> V_4 -> V_138 ;
V_133 . V_136 += V_2 -> V_6 + V_75 ;
V_133 . V_139 = V_140 ;
V_50 = F_74 ( V_2 -> V_91 , & V_133 ) ;
if ( V_50 )
goto V_141;
return 0 ;
V_141:
F_75 ( V_2 -> V_91 -> V_134 -> V_37 , V_80 ,
V_2 -> V_111 , V_2 -> V_98 ) ;
V_135:
F_76 ( V_2 -> V_91 ) ;
return V_50 ;
}
static int F_77 ( struct V_142 * V_143 )
{
struct V_27 * V_28 ;
struct V_1 * V_2 ;
int V_50 ;
if ( ! V_143 -> V_37 . V_114 )
return - V_144 ;
V_28 = F_78 ( & V_143 -> V_37 , sizeof( * V_2 ) ) ;
if ( ! V_28 )
return - V_131 ;
V_2 = F_18 ( V_28 ) ;
V_2 -> V_4 = F_79 ( V_143 -> V_37 . V_145 ) ;
F_80 ( & V_2 -> V_10 ) ;
F_81 ( & V_2 -> V_57 ) ;
V_28 -> V_46 = F_82 ( & V_143 -> V_37 ) ;
V_28 -> V_37 . V_145 = & V_143 -> V_37 ;
V_28 -> V_37 . V_114 = V_143 -> V_37 . V_114 ;
V_28 -> V_146 = & V_147 ;
V_28 -> V_148 = V_149 ;
F_83 ( V_143 , V_2 ) ;
V_50 = F_63 ( V_143 -> V_37 . V_114 , L_15 , & V_2 -> V_6 ) ;
if ( V_50 != 0 ) {
F_55 ( & V_143 -> V_37 , L_16 ) ;
return - V_36 ;
}
V_2 -> V_71 = F_84 ( V_143 , 0 ) ;
if ( V_2 -> V_71 < 0 ) {
F_55 ( & V_143 -> V_37 , L_17 ) ;
return V_2 -> V_71 ;
}
V_50 = F_85 ( & V_143 -> V_37 , V_2 -> V_71 , F_32 ,
0 , V_143 -> V_46 , V_2 ) ;
if ( V_50 ) {
F_55 ( & V_143 -> V_37 , L_18 ) ;
return V_50 ;
}
V_2 -> V_150 = F_86 ( & V_143 -> V_37 , NULL ) ;
if ( F_87 ( V_2 -> V_150 ) ) {
F_55 ( & V_143 -> V_37 , L_19 ) ;
return F_88 ( V_2 -> V_150 ) ;
}
V_50 = F_89 ( V_2 -> V_150 ) ;
if ( V_50 < 0 ) {
F_55 ( & V_143 -> V_37 , L_20 ) ;
return V_50 ;
}
V_50 = F_62 ( V_28 ) ;
if ( V_50 < 0 )
goto V_151;
F_13 ( V_2 ) ;
V_50 = F_67 ( V_28 ) ;
if ( V_50 < 0 )
goto V_151;
V_50 = F_71 ( V_28 ) ;
if ( V_50 < 0 )
goto V_151;
V_50 = F_90 ( V_28 ,
& V_152 ,
& F_59 ,
& V_153 ) ;
if ( V_50 ) {
F_55 ( & V_143 -> V_37 , L_21 ) ;
goto V_154;
}
V_50 = F_91 ( V_28 ) ;
if ( V_50 ) {
F_55 ( & V_143 -> V_37 , L_22 ) ;
goto V_155;
}
return 0 ;
V_155:
F_92 ( V_28 ) ;
V_154:
if ( V_2 -> V_91 ) {
F_75 ( V_2 -> V_91 -> V_134 -> V_37 ,
V_80 ,
V_2 -> V_111 , V_2 -> V_98 ) ;
F_76 ( V_2 -> V_91 ) ;
}
V_151:
F_93 ( V_2 -> V_150 ) ;
return V_50 ;
}
static int F_94 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = F_95 ( V_143 ) ;
struct V_27 * V_28 = F_33 ( V_2 ) ;
F_96 ( V_28 ) ;
F_92 ( V_28 ) ;
if ( V_2 -> V_91 ) {
F_75 ( V_2 -> V_91 -> V_134 -> V_37 ,
V_80 ,
V_2 -> V_111 , V_2 -> V_98 ) ;
F_76 ( V_2 -> V_91 ) ;
}
F_93 ( V_2 -> V_150 ) ;
return 0 ;
}
