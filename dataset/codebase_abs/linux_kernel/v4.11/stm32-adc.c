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
static void F_13 ( struct V_1 * V_2 , bool V_13 )
{
F_7 ( V_2 , V_11 , V_14 ) ;
if ( V_13 )
F_7 ( V_2 , V_15 ,
V_16 | V_17 ) ;
F_7 ( V_2 , V_15 , V_18 | V_19 ) ;
F_14 ( 2 , 3 ) ;
if ( ! ( F_1 ( V_2 , V_15 ) & V_20 ) )
F_7 ( V_2 , V_15 , V_21 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_15 , V_20 ) ;
F_10 ( V_2 , V_22 , V_23 ) ;
F_10 ( V_2 , V_11 , V_14 ) ;
F_10 ( V_2 , V_15 ,
V_19 | V_16 | V_17 ) ;
}
static int F_16 ( struct V_24 * V_25 ,
const unsigned long * V_26 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
const struct V_27 * V_28 ;
T_1 V_7 , V_29 ;
int V_30 = 0 ;
F_18 (bit, scan_mask, indio_dev->masklength) {
V_28 = V_25 -> V_31 + V_29 ;
V_30 ++ ;
if ( V_30 > V_32 )
return - V_33 ;
F_19 ( & V_25 -> V_34 , L_1 ,
V_35 , V_28 -> V_36 , V_30 ) ;
V_7 = F_1 ( V_2 , V_37 [ V_30 ] . V_3 ) ;
V_7 &= ~ V_37 [ V_30 ] . V_38 ;
V_7 |= V_28 -> V_36 << V_37 [ V_30 ] . V_39 ;
F_5 ( V_2 , V_37 [ V_30 ] . V_3 , V_7 ) ;
}
if ( ! V_30 )
return - V_33 ;
V_7 = F_1 ( V_2 , V_37 [ 0 ] . V_3 ) ;
V_7 &= ~ V_37 [ 0 ] . V_38 ;
V_7 |= ( ( V_30 - 1 ) << V_37 [ 0 ] . V_39 ) ;
F_5 ( V_2 , V_37 [ 0 ] . V_3 , V_7 ) ;
return 0 ;
}
static int F_20 ( struct V_40 * V_41 )
{
int V_30 ;
for ( V_30 = 0 ; V_42 [ V_30 ] . V_43 ; V_30 ++ ) {
if ( F_21 ( V_41 ) &&
! strcmp ( V_42 [ V_30 ] . V_43 , V_41 -> V_43 ) ) {
return V_42 [ V_30 ] . V_44 ;
}
}
return - V_33 ;
}
static int F_22 ( struct V_24 * V_25 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
T_1 V_7 , V_44 = 0 , V_45 = V_46 ;
unsigned long V_9 ;
int V_47 ;
if ( V_41 ) {
V_47 = F_20 ( V_41 ) ;
if ( V_47 < 0 )
return V_47 ;
V_44 = V_47 ;
V_45 = V_2 -> V_48 + V_49 ;
}
F_8 ( & V_2 -> V_10 , V_9 ) ;
V_7 = F_1 ( V_2 , V_15 ) ;
V_7 &= ~ ( V_20 | V_50 ) ;
V_7 |= V_45 << V_51 ;
V_7 |= V_44 << V_52 ;
F_5 ( V_2 , V_15 , V_7 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
return 0 ;
}
static int F_23 ( struct V_24 * V_25 ,
const struct V_27 * V_28 ,
unsigned int type )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
V_2 -> V_48 = type ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 ,
const struct V_27 * V_28 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
return V_2 -> V_48 ;
}
static int F_25 ( struct V_24 * V_25 ,
const struct V_27 * V_28 ,
int * V_53 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
long V_54 ;
T_1 V_7 ;
int V_47 ;
F_26 ( & V_2 -> V_55 ) ;
V_2 -> V_56 = 0 ;
V_7 = F_1 ( V_2 , V_37 [ 1 ] . V_3 ) ;
V_7 &= ~ V_37 [ 1 ] . V_38 ;
V_7 |= V_28 -> V_36 << V_37 [ 1 ] . V_39 ;
F_5 ( V_2 , V_37 [ 1 ] . V_3 , V_7 ) ;
F_10 ( V_2 , V_37 [ 0 ] . V_3 , V_37 [ 0 ] . V_38 ) ;
F_10 ( V_2 , V_15 , V_20 ) ;
F_11 ( V_2 ) ;
F_13 ( V_2 , false ) ;
V_54 = F_27 (
& V_2 -> V_55 , V_57 ) ;
if ( V_54 == 0 ) {
V_47 = - V_58 ;
} else if ( V_54 < 0 ) {
V_47 = V_54 ;
} else {
* V_53 = V_2 -> V_59 [ 0 ] ;
V_47 = V_60 ;
}
F_15 ( V_2 ) ;
F_12 ( V_2 ) ;
return V_47 ;
}
static int F_28 ( struct V_24 * V_25 ,
struct V_27 const * V_28 ,
int * V_7 , int * V_61 , long V_38 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
int V_47 ;
switch ( V_38 ) {
case V_62 :
V_47 = F_29 ( V_25 ) ;
if ( V_47 )
return V_47 ;
if ( V_28 -> type == V_63 )
V_47 = F_25 ( V_25 , V_28 , V_7 ) ;
else
V_47 = - V_33 ;
F_30 ( V_25 ) ;
return V_47 ;
case V_64 :
* V_7 = V_2 -> V_4 -> V_65 ;
* V_61 = V_28 -> V_66 . V_67 ;
return V_68 ;
default:
return - V_33 ;
}
}
static T_3 F_31 ( int V_69 , void * V_70 )
{
struct V_1 * V_2 = V_70 ;
struct V_24 * V_25 = F_32 ( V_2 ) ;
T_1 V_71 = F_1 ( V_2 , V_22 ) ;
if ( V_71 & V_72 ) {
V_2 -> V_59 [ V_2 -> V_56 ] = F_3 ( V_2 , V_73 ) ;
if ( F_33 ( V_25 ) ) {
V_2 -> V_56 ++ ;
if ( V_2 -> V_56 >= V_2 -> V_74 ) {
F_12 ( V_2 ) ;
F_34 ( V_25 -> V_41 ) ;
}
} else {
F_35 ( & V_2 -> V_55 ) ;
}
return V_75 ;
}
return V_76 ;
}
static int F_36 ( struct V_24 * V_25 ,
struct V_40 * V_41 )
{
return F_20 ( V_41 ) < 0 ? - V_33 : 0 ;
}
static int F_37 ( struct V_24 * V_25 , unsigned int V_7 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned int V_77 = V_78 / 2 ;
V_77 = F_38 ( V_77 , V_7 * ( unsigned ) ( sizeof( T_2 ) ) ) ;
V_2 -> V_79 = V_77 * 2 ;
return 0 ;
}
static int F_39 ( struct V_24 * V_25 ,
const unsigned long * V_26 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
int V_47 ;
V_2 -> V_74 = F_40 ( V_26 , V_25 -> V_80 ) ;
V_47 = F_16 ( V_25 , V_26 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 ,
const struct V_81 * V_82 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_25 -> V_83 ; V_30 ++ )
if ( V_25 -> V_31 [ V_30 ] . V_36 == V_82 -> args [ 0 ] )
return V_30 ;
return - V_33 ;
}
static int F_42 ( struct V_24 * V_25 ,
unsigned V_3 , unsigned V_84 ,
unsigned * V_85 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
if ( ! V_85 )
F_5 ( V_2 , V_3 , V_84 ) ;
else
* V_85 = F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static unsigned int F_43 ( struct V_1 * V_2 )
{
struct V_86 V_87 ;
enum V_88 V_71 ;
V_71 = F_44 ( V_2 -> V_89 ,
V_2 -> V_89 -> V_90 ,
& V_87 ) ;
if ( V_71 == V_91 ) {
unsigned int V_30 = V_2 -> V_79 - V_87 . V_92 ;
unsigned int V_93 ;
if ( V_30 >= V_2 -> V_56 )
V_93 = V_30 - V_2 -> V_56 ;
else
V_93 = V_2 -> V_79 + V_30 - V_2 -> V_56 ;
return V_93 ;
}
return 0 ;
}
static void F_45 ( void * V_70 )
{
struct V_24 * V_25 = V_70 ;
F_46 ( V_25 -> V_41 ) ;
}
static int F_47 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_94 * V_95 ;
T_4 V_90 ;
int V_47 ;
if ( ! V_2 -> V_89 )
return 0 ;
F_19 ( & V_25 -> V_34 , L_2 , V_35 ,
V_2 -> V_79 , V_2 -> V_79 / 2 ) ;
V_95 = F_48 ( V_2 -> V_89 ,
V_2 -> V_96 ,
V_2 -> V_79 , V_2 -> V_79 / 2 ,
V_97 ,
V_98 ) ;
if ( ! V_95 )
return - V_99 ;
V_95 -> V_100 = F_45 ;
V_95 -> V_101 = V_25 ;
V_90 = F_49 ( V_95 ) ;
V_47 = F_50 ( V_90 ) ;
if ( V_47 ) {
F_51 ( V_2 -> V_89 ) ;
return V_47 ;
}
F_52 ( V_2 -> V_89 ) ;
return 0 ;
}
static int F_53 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
int V_47 ;
V_47 = F_22 ( V_25 , V_25 -> V_41 ) ;
if ( V_47 ) {
F_54 ( & V_25 -> V_34 , L_3 ) ;
return V_47 ;
}
V_47 = F_47 ( V_25 ) ;
if ( V_47 ) {
F_54 ( & V_25 -> V_34 , L_4 ) ;
goto V_102;
}
V_47 = F_55 ( V_25 ) ;
if ( V_47 < 0 )
goto V_103;
V_2 -> V_56 = 0 ;
if ( ! V_2 -> V_89 )
F_11 ( V_2 ) ;
F_13 ( V_2 , ! ! V_2 -> V_89 ) ;
return 0 ;
V_103:
if ( V_2 -> V_89 )
F_51 ( V_2 -> V_89 ) ;
V_102:
F_22 ( V_25 , NULL ) ;
return V_47 ;
}
static int F_56 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
int V_47 ;
F_15 ( V_2 ) ;
if ( ! V_2 -> V_89 )
F_12 ( V_2 ) ;
V_47 = F_57 ( V_25 ) ;
if ( V_47 < 0 )
F_54 ( & V_25 -> V_34 , L_5 ) ;
if ( V_2 -> V_89 )
F_51 ( V_2 -> V_89 ) ;
if ( F_22 ( V_25 , NULL ) )
F_54 ( & V_25 -> V_34 , L_6 ) ;
return V_47 ;
}
static T_3 F_58 ( int V_69 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
struct V_24 * V_25 = V_106 -> V_25 ;
struct V_1 * V_2 = F_17 ( V_25 ) ;
F_19 ( & V_25 -> V_34 , L_7 , V_35 , V_2 -> V_56 ) ;
if ( ! V_2 -> V_89 ) {
V_2 -> V_56 = 0 ;
F_59 ( V_25 , V_2 -> V_59 ,
V_106 -> V_107 ) ;
} else {
int V_92 = F_43 ( V_2 ) ;
while ( V_92 >= V_25 -> V_108 ) {
T_2 * V_59 = ( T_2 * ) & V_2 -> V_109 [ V_2 -> V_56 ] ;
F_59 ( V_25 , V_59 ,
V_106 -> V_107 ) ;
V_92 -= V_25 -> V_108 ;
V_2 -> V_56 += V_25 -> V_108 ;
if ( V_2 -> V_56 >= V_2 -> V_79 )
V_2 -> V_56 = 0 ;
}
}
F_60 ( V_25 -> V_41 ) ;
if ( ! V_2 -> V_89 )
F_11 ( V_2 ) ;
return V_75 ;
}
static void F_61 ( struct V_24 * V_25 ,
struct V_27 * V_28 ,
const struct V_110 * V_36 ,
int V_111 )
{
V_28 -> type = V_36 -> type ;
V_28 -> V_36 = V_36 -> V_36 ;
V_28 -> V_112 = V_36 -> V_43 ;
V_28 -> V_111 = V_111 ;
V_28 -> V_113 = 1 ;
V_28 -> V_114 = F_62 ( V_62 ) ;
V_28 -> V_115 = F_62 ( V_64 ) ;
V_28 -> V_66 . V_116 = 'u' ;
V_28 -> V_66 . V_67 = 12 ;
V_28 -> V_66 . V_117 = 16 ;
V_28 -> V_118 = V_119 ;
}
static int F_63 ( struct V_24 * V_25 )
{
struct V_120 * V_121 = V_25 -> V_34 . V_122 ;
struct V_123 * V_124 ;
const T_5 * V_125 ;
struct V_27 * V_31 ;
int V_111 = 0 , V_83 ;
T_1 V_7 ;
V_83 = F_64 ( V_121 , L_8 ) ;
if ( V_83 < 0 ||
V_83 >= F_65 ( V_126 ) ) {
F_54 ( & V_25 -> V_34 , L_9 ) ;
return V_83 < 0 ? V_83 : - V_33 ;
}
V_31 = F_66 ( & V_25 -> V_34 , V_83 ,
sizeof( struct V_27 ) , V_127 ) ;
if ( ! V_31 )
return - V_128 ;
F_67 (node, L_8 , prop, cur, val) {
if ( V_7 >= F_65 ( V_126 ) ) {
F_54 ( & V_25 -> V_34 , L_10 , V_7 ) ;
return - V_33 ;
}
F_61 ( V_25 , & V_31 [ V_111 ] ,
& V_126 [ V_7 ] ,
V_111 ) ;
V_111 ++ ;
}
V_25 -> V_83 = V_111 ;
V_25 -> V_31 = V_31 ;
return 0 ;
}
static int F_68 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_129 V_130 ;
int V_47 ;
V_2 -> V_89 = F_69 ( & V_25 -> V_34 , L_11 ) ;
if ( ! V_2 -> V_89 )
return 0 ;
V_2 -> V_109 = F_70 ( V_2 -> V_89 -> V_131 -> V_34 ,
V_78 ,
& V_2 -> V_96 , V_127 ) ;
if ( ! V_2 -> V_109 ) {
V_47 = - V_128 ;
goto V_132;
}
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_130 . V_133 = ( V_134 ) V_2 -> V_4 -> V_135 ;
V_130 . V_133 += V_2 -> V_6 + V_73 ;
V_130 . V_136 = V_137 ;
V_47 = F_71 ( V_2 -> V_89 , & V_130 ) ;
if ( V_47 )
goto V_138;
return 0 ;
V_138:
F_72 ( V_2 -> V_89 -> V_131 -> V_34 , V_78 ,
V_2 -> V_109 , V_2 -> V_96 ) ;
V_132:
F_73 ( V_2 -> V_89 ) ;
return V_47 ;
}
static int F_74 ( struct V_139 * V_140 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
int V_47 ;
if ( ! V_140 -> V_34 . V_122 )
return - V_141 ;
V_25 = F_75 ( & V_140 -> V_34 , sizeof( * V_2 ) ) ;
if ( ! V_25 )
return - V_128 ;
V_2 = F_17 ( V_25 ) ;
V_2 -> V_4 = F_76 ( V_140 -> V_34 . V_142 ) ;
F_77 ( & V_2 -> V_10 ) ;
F_78 ( & V_2 -> V_55 ) ;
V_25 -> V_43 = F_79 ( & V_140 -> V_34 ) ;
V_25 -> V_34 . V_142 = & V_140 -> V_34 ;
V_25 -> V_34 . V_122 = V_140 -> V_34 . V_122 ;
V_25 -> V_143 = & V_144 ;
V_25 -> V_145 = V_146 ;
F_80 ( V_140 , V_2 ) ;
V_47 = F_81 ( V_140 -> V_34 . V_122 , L_12 , & V_2 -> V_6 ) ;
if ( V_47 != 0 ) {
F_54 ( & V_140 -> V_34 , L_13 ) ;
return - V_33 ;
}
V_2 -> V_69 = F_82 ( V_140 , 0 ) ;
if ( V_2 -> V_69 < 0 ) {
F_54 ( & V_140 -> V_34 , L_14 ) ;
return V_2 -> V_69 ;
}
V_47 = F_83 ( & V_140 -> V_34 , V_2 -> V_69 , F_31 ,
0 , V_140 -> V_43 , V_2 ) ;
if ( V_47 ) {
F_54 ( & V_140 -> V_34 , L_15 ) ;
return V_47 ;
}
V_2 -> V_147 = F_84 ( & V_140 -> V_34 , NULL ) ;
if ( F_85 ( V_2 -> V_147 ) ) {
F_54 ( & V_140 -> V_34 , L_16 ) ;
return F_86 ( V_2 -> V_147 ) ;
}
V_47 = F_87 ( V_2 -> V_147 ) ;
if ( V_47 < 0 ) {
F_54 ( & V_140 -> V_34 , L_17 ) ;
return V_47 ;
}
V_47 = F_63 ( V_25 ) ;
if ( V_47 < 0 )
goto V_148;
V_47 = F_68 ( V_25 ) ;
if ( V_47 < 0 )
goto V_148;
V_47 = F_88 ( V_25 ,
& V_149 ,
& F_58 ,
& V_150 ) ;
if ( V_47 ) {
F_54 ( & V_140 -> V_34 , L_18 ) ;
goto V_151;
}
V_47 = F_89 ( V_25 ) ;
if ( V_47 ) {
F_54 ( & V_140 -> V_34 , L_19 ) ;
goto V_152;
}
return 0 ;
V_152:
F_90 ( V_25 ) ;
V_151:
if ( V_2 -> V_89 ) {
F_72 ( V_2 -> V_89 -> V_131 -> V_34 ,
V_78 ,
V_2 -> V_109 , V_2 -> V_96 ) ;
F_73 ( V_2 -> V_89 ) ;
}
V_148:
F_91 ( V_2 -> V_147 ) ;
return V_47 ;
}
static int F_92 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = F_93 ( V_140 ) ;
struct V_24 * V_25 = F_32 ( V_2 ) ;
F_94 ( V_25 ) ;
F_90 ( V_25 ) ;
if ( V_2 -> V_89 ) {
F_72 ( V_2 -> V_89 -> V_131 -> V_34 ,
V_78 ,
V_2 -> V_109 , V_2 -> V_96 ) ;
F_73 ( V_2 -> V_89 ) ;
}
F_91 ( V_2 -> V_147 ) ;
return 0 ;
}
