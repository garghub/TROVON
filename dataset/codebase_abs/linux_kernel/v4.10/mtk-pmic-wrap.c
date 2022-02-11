static T_1 F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
return F_2 ( V_2 -> V_5 + V_2 -> V_6 -> V_7 [ V_4 ] ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_8 , enum V_3 V_4 )
{
F_4 ( V_8 , V_2 -> V_5 + V_2 -> V_6 -> V_7 [ V_4 ] ) ;
}
static bool F_5 ( struct V_1 * V_2 )
{
T_1 V_8 = F_1 ( V_2 , V_9 ) ;
return F_6 ( V_8 ) == V_10 ;
}
static bool F_7 ( struct V_1 * V_2 )
{
T_1 V_8 = F_1 ( V_2 , V_9 ) ;
return F_6 ( V_8 ) == V_11 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) )
F_3 ( V_2 , 1 , V_12 ) ;
}
static bool F_9 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_9 ) & V_13 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
T_1 V_8 = F_1 ( V_2 , V_9 ) ;
return ( F_6 ( V_8 ) == V_10 ) &&
( V_8 & V_13 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
bool (* F_12)( struct V_1 * ) )
{
unsigned long V_14 ;
V_14 = V_15 + F_13 ( 10000 ) ;
do {
if ( F_14 ( V_15 , V_14 ) )
return F_12 ( V_2 ) ? 0 : - V_16 ;
if ( F_12 ( V_2 ) )
return 0 ;
} while ( 1 );
}
static int F_15 ( struct V_1 * V_2 , T_1 V_17 , T_1 V_18 )
{
int V_19 ;
V_19 = F_11 ( V_2 , F_5 ) ;
if ( V_19 ) {
F_8 ( V_2 ) ;
return V_19 ;
}
F_3 ( V_2 , ( 1 << 31 ) | ( ( V_17 >> 1 ) << 16 ) | V_18 ,
V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_17 , T_1 * V_21 )
{
int V_19 ;
V_19 = F_11 ( V_2 , F_5 ) ;
if ( V_19 ) {
F_8 ( V_2 ) ;
return V_19 ;
}
F_3 ( V_2 , ( V_17 >> 1 ) << 16 , V_20 ) ;
V_19 = F_11 ( V_2 , F_7 ) ;
if ( V_19 )
return V_19 ;
* V_21 = F_17 ( F_1 ( V_2 , V_9 ) ) ;
F_3 ( V_2 , 1 , V_12 ) ;
return 0 ;
}
static int F_18 ( void * V_22 , T_1 V_17 , T_1 * V_21 )
{
return F_16 ( V_22 , V_17 , V_21 ) ;
}
static int F_19 ( void * V_22 , T_1 V_17 , T_1 V_18 )
{
return F_15 ( V_22 , V_17 , V_18 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_19 , V_23 ;
F_3 ( V_2 , 0 , V_24 ) ;
F_3 ( V_2 , 0 , V_25 ) ;
F_3 ( V_2 , 1 , V_26 ) ;
F_3 ( V_2 , 1 , V_27 ) ;
F_3 ( V_2 , 0 , V_28 ) ;
F_3 ( V_2 , V_2 -> V_6 -> V_29 | V_30 ,
V_31 ) ;
F_3 ( V_2 , V_2 -> V_6 -> V_29 | V_32 ,
V_31 ) ;
F_3 ( V_2 , V_2 -> V_6 -> V_29 | V_33 ,
V_31 ) ;
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ )
F_3 ( V_2 , V_2 -> V_6 -> V_29 | V_32 ,
V_31 ) ;
V_19 = F_11 ( V_2 , F_9 ) ;
if ( V_19 ) {
F_21 ( V_2 -> V_34 , L_1 , V_35 , V_19 ) ;
return V_19 ;
}
F_3 ( V_2 , 0 , V_27 ) ;
F_3 ( V_2 , 0 , V_26 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_1 V_21 ;
T_1 V_23 ;
T_1 V_36 = 0 ;
signed char V_37 [ 16 ] = {
- 1 , 0 , 1 , 0 , 2 , - 1 , 1 , 1 , 3 , - 1 , - 1 , - 1 , 3 , - 1 , 2 , 1
} ;
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
F_3 ( V_2 , V_23 , V_38 ) ;
F_16 ( V_2 , V_2 -> V_39 -> V_40 [ V_41 ] ,
& V_21 ) ;
if ( V_21 == V_42 ) {
F_23 ( V_2 -> V_34 , L_2 , V_23 ) ;
V_36 |= 1 << V_23 ;
}
}
if ( V_37 [ V_36 ] < 0 ) {
F_21 ( V_2 -> V_34 , L_3 ,
V_36 ) ;
return - V_43 ;
}
F_3 ( V_2 , V_37 [ V_36 ] , V_38 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0x4 , V_44 ) ;
F_3 ( V_2 , 0x0 , V_45 ) ;
F_3 ( V_2 , 0x4 , V_46 ) ;
F_3 ( V_2 , 0x0 , V_47 ) ;
F_3 ( V_2 , 0x0 , V_48 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0x0 , V_45 ) ;
F_3 ( V_2 , 0x4 , V_46 ) ;
F_3 ( V_2 , 0x2 , V_47 ) ;
F_3 ( V_2 , 0x2 , V_48 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_39 -> type ) {
case V_49 :
F_3 ( V_2 , 0xc , V_50 ) ;
F_3 ( V_2 , 0x4 , V_45 ) ;
F_3 ( V_2 , 0x0 , V_46 ) ;
F_3 ( V_2 , 0x2 , V_47 ) ;
F_3 ( V_2 , 0x2 , V_48 ) ;
break;
case V_51 :
F_3 ( V_2 , 0x8 , V_50 ) ;
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_52 ] ,
0x8 ) ;
F_3 ( V_2 , 0x5 , V_45 ) ;
F_3 ( V_2 , 0x0 , V_46 ) ;
F_3 ( V_2 , 0x2 , V_47 ) ;
F_3 ( V_2 , 0x2 , V_48 ) ;
break;
}
return 0 ;
}
static bool F_27 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_53 ) & 1 ;
}
static bool F_28 ( struct V_1 * V_2 )
{
T_1 V_21 ;
int V_19 ;
V_19 = F_16 ( V_2 , V_2 -> V_39 -> V_40 [ V_54 ] ,
& V_21 ) ;
if ( V_19 )
return 0 ;
return V_21 == 1 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_19 ;
T_1 V_21 ;
F_3 ( V_2 , 0x1 , V_55 ) ;
F_3 ( V_2 , 0x0 , V_55 ) ;
F_3 ( V_2 , 0x1 , V_56 ) ;
F_3 ( V_2 , 0x2 , V_57 ) ;
switch ( V_2 -> V_6 -> type ) {
case V_58 :
F_3 ( V_2 , 1 , V_59 ) ;
F_3 ( V_2 , 1 , V_60 ) ;
break;
case V_61 :
case V_62 :
F_3 ( V_2 , 1 , V_63 ) ;
break;
}
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_64 ] , 0x1 ) ;
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_64 ] , 0x0 ) ;
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_65 ] , 0x1 ) ;
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_66 ] , 0x2 ) ;
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_67 ] , 0x1 ) ;
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_68 ] , 0x1 ) ;
switch ( V_2 -> V_39 -> type ) {
case V_49 :
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_67 ] ,
0x1 ) ;
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_68 ] ,
0x1 ) ;
break;
case V_51 :
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_69 ] ,
0x1 ) ;
break;
}
V_19 = F_11 ( V_2 , F_27 ) ;
if ( V_19 ) {
F_21 ( V_2 -> V_34 , L_4 , V_19 ) ;
return V_19 ;
}
V_19 = F_11 ( V_2 , F_28 ) ;
if ( V_19 ) {
F_21 ( V_2 -> V_34 , L_5 ) ;
return V_19 ;
}
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_70 ] , 0x1 ) ;
V_19 = F_11 ( V_2 , F_10 ) ;
if ( V_19 ) {
F_21 ( V_2 -> V_34 , L_6 , V_19 ) ;
return V_19 ;
}
F_3 ( V_2 , 1 , V_71 ) ;
if ( F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_72 ] ,
V_73 ) ||
F_16 ( V_2 , V_2 -> V_39 -> V_40 [ V_72 ] ,
& V_21 ) ||
( V_21 != V_73 ) ) {
F_21 ( V_2 -> V_34 , L_7 , V_21 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0x1 , V_75 ) ;
F_3 ( V_2 , 0xffff , V_76 ) ;
F_4 ( 0x7f , V_2 -> V_77 + V_78 ) ;
F_4 ( 0x1 , V_2 -> V_77 + V_79 ) ;
F_4 ( 0x1 , V_2 -> V_77 + V_80 ) ;
F_4 ( 0x1 , V_2 -> V_77 + V_81 ) ;
F_4 ( 0xffff , V_2 -> V_77 + V_82 ) ;
F_4 ( 0x1 , V_2 -> V_77 + V_83 ) ;
F_4 ( 0x7ff , V_2 -> V_77 + V_84 ) ;
if ( F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_85 ] ,
0x1 ) ||
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_86 ] ,
0xffff ) ) {
F_21 ( V_2 -> V_34 , L_8 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_85 ] ,
0x1 ) ||
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_86 ] ,
0xffff ) ) {
F_21 ( V_2 -> V_34 , L_8 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_39 -> type ) {
case V_51 :
F_3 ( V_2 , 0x076c , V_87 ) ;
F_3 ( V_2 , 0x8000 , V_88 ) ;
F_3 ( V_2 , 0x072c , V_89 ) ;
F_3 ( V_2 , 0x072e , V_90 ) ;
F_3 ( V_2 , 0x0730 , V_91 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_19 ;
T_1 V_21 ;
F_34 ( V_2 -> V_92 ) ;
if ( V_2 -> V_93 )
F_34 ( V_2 -> V_93 ) ;
if ( V_2 -> V_6 -> type == V_62 ) {
F_3 ( V_2 , 3 , V_94 ) ;
F_3 ( V_2 , 0 , V_95 ) ;
}
V_19 = F_20 ( V_2 ) ;
if ( V_19 )
return V_19 ;
F_3 ( V_2 , 1 , V_25 ) ;
F_3 ( V_2 , V_2 -> V_6 -> V_96 , V_24 ) ;
F_3 ( V_2 , 1 , V_97 ) ;
V_19 = V_2 -> V_6 -> V_98 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_22 ( V_2 ) ;
if ( V_19 )
return V_19 ;
F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_99 ] , 1 ) ;
V_19 = F_11 ( V_2 , F_10 ) ;
if ( V_19 ) {
F_21 ( V_2 -> V_34 , L_1 , V_35 , V_19 ) ;
return V_19 ;
}
F_3 ( V_2 , 1 , V_28 ) ;
F_16 ( V_2 , V_2 -> V_39 -> V_40 [ V_41 ] , & V_21 ) ;
if ( V_21 != V_42 ) {
F_21 ( V_2 -> V_34 , L_9 ,
V_42 , V_21 ) ;
return - V_74 ;
}
V_19 = F_29 ( V_2 ) ;
if ( V_19 )
return V_19 ;
if ( F_15 ( V_2 , V_2 -> V_39 -> V_40 [ V_100 ] , 0x1 ) )
return - V_74 ;
F_3 ( V_2 , 0x1 , V_101 ) ;
F_3 ( V_2 , 0x0 , V_102 ) ;
F_3 ( V_2 , V_2 -> V_39 -> V_40 [ V_103 ] ,
V_104 ) ;
F_3 ( V_2 , V_2 -> V_6 -> V_96 , V_24 ) ;
if ( V_2 -> V_6 -> type == V_58 )
F_3 ( V_2 , 0x7 , V_105 ) ;
F_3 ( V_2 , 0x1 , V_106 ) ;
F_3 ( V_2 , 0x1 , V_107 ) ;
F_3 ( V_2 , 0x1 , V_97 ) ;
F_3 ( V_2 , 0x5 , V_108 ) ;
F_3 ( V_2 , 0xff , V_109 ) ;
if ( V_2 -> V_6 -> V_110 ) {
V_19 = V_2 -> V_6 -> V_110 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
F_3 ( V_2 , 1 , V_111 ) ;
F_3 ( V_2 , 1 , V_112 ) ;
F_3 ( V_2 , 1 , V_113 ) ;
if ( V_2 -> V_6 -> V_114 ) {
F_4 ( 1 , V_2 -> V_77 + V_115 ) ;
F_4 ( 1 , V_2 -> V_77 + V_116 ) ;
}
return 0 ;
}
static T_2 F_35 ( int V_117 , void * V_118 )
{
T_1 V_21 ;
struct V_1 * V_2 = V_118 ;
V_21 = F_1 ( V_2 , V_119 ) ;
F_21 ( V_2 -> V_34 , L_10 , V_21 ) ;
F_3 ( V_2 , 0xffffffff , V_120 ) ;
return V_121 ;
}
static int F_36 ( struct V_122 * V_123 )
{
int V_19 , V_124 ;
struct V_1 * V_2 ;
struct V_125 * V_126 = V_123 -> V_34 . V_127 ;
const struct V_128 * V_129 =
F_37 ( V_130 , & V_123 -> V_34 ) ;
const struct V_128 * V_131 = NULL ;
struct V_132 * V_133 ;
if ( V_123 -> V_34 . V_127 -> V_134 )
V_131 = F_38 ( V_135 ,
V_123 -> V_34 . V_127 -> V_134 ) ;
if ( ! V_131 ) {
F_23 ( & V_123 -> V_34 , L_11 ) ;
return - V_136 ;
}
V_2 = F_39 ( & V_123 -> V_34 , sizeof( * V_2 ) , V_137 ) ;
if ( ! V_2 )
return - V_138 ;
F_40 ( V_123 , V_2 ) ;
V_2 -> V_6 = V_129 -> V_139 ;
V_2 -> V_39 = V_131 -> V_139 ;
V_2 -> V_34 = & V_123 -> V_34 ;
V_133 = F_41 ( V_123 , V_140 , L_12 ) ;
V_2 -> V_5 = F_42 ( V_2 -> V_34 , V_133 ) ;
if ( F_43 ( V_2 -> V_5 ) )
return F_44 ( V_2 -> V_5 ) ;
V_2 -> V_92 = F_45 ( V_2 -> V_34 , L_12 ) ;
if ( F_43 ( V_2 -> V_92 ) ) {
V_19 = F_44 ( V_2 -> V_92 ) ;
F_23 ( V_2 -> V_34 , L_13 , V_19 ) ;
return V_19 ;
}
if ( V_2 -> V_6 -> V_114 ) {
V_133 = F_41 ( V_123 , V_140 ,
L_14 ) ;
V_2 -> V_77 = F_42 ( V_2 -> V_34 , V_133 ) ;
if ( F_43 ( V_2 -> V_77 ) )
return F_44 ( V_2 -> V_77 ) ;
V_2 -> V_93 = F_45 ( V_2 -> V_34 , L_14 ) ;
if ( F_43 ( V_2 -> V_93 ) ) {
V_19 = F_44 ( V_2 -> V_93 ) ;
F_23 ( V_2 -> V_34 , L_15 , V_19 ) ;
return V_19 ;
}
}
V_2 -> V_141 = F_46 ( V_2 -> V_34 , L_16 ) ;
if ( F_43 ( V_2 -> V_141 ) ) {
F_23 ( V_2 -> V_34 , L_17 , F_44 ( V_2 -> V_141 ) ) ;
return F_44 ( V_2 -> V_141 ) ;
}
V_2 -> V_142 = F_46 ( V_2 -> V_34 , L_18 ) ;
if ( F_43 ( V_2 -> V_142 ) ) {
F_23 ( V_2 -> V_34 , L_17 , F_44 ( V_2 -> V_142 ) ) ;
return F_44 ( V_2 -> V_142 ) ;
}
V_19 = F_47 ( V_2 -> V_141 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_47 ( V_2 -> V_142 ) ;
if ( V_19 )
goto V_143;
F_3 ( V_2 , 1 , V_94 ) ;
F_3 ( V_2 , 0 , V_95 ) ;
if ( ! F_1 ( V_2 , V_111 ) ) {
V_19 = F_33 ( V_2 ) ;
if ( V_19 ) {
F_23 ( V_2 -> V_34 , L_19 , V_19 ) ;
goto V_144;
}
}
if ( ! ( F_1 ( V_2 , V_9 ) & V_145 ) ) {
F_23 ( V_2 -> V_34 , L_20 ) ;
return - V_146 ;
}
F_3 ( V_2 , 0xf , V_147 ) ;
F_3 ( V_2 , V_2 -> V_6 -> V_148 , V_149 ) ;
F_3 ( V_2 , 0x1 , V_150 ) ;
F_3 ( V_2 , V_2 -> V_6 -> V_151 , V_152 ) ;
V_124 = F_48 ( V_123 , 0 ) ;
V_19 = F_49 ( V_2 -> V_34 , V_124 , F_35 , V_153 ,
L_21 , V_2 ) ;
if ( V_19 )
goto V_144;
V_2 -> V_154 = F_50 ( V_2 -> V_34 , NULL , V_2 , & V_155 ) ;
if ( F_43 ( V_2 -> V_154 ) )
return F_44 ( V_2 -> V_154 ) ;
V_19 = F_51 ( V_126 , NULL , NULL , V_2 -> V_34 ) ;
if ( V_19 ) {
F_23 ( V_2 -> V_34 , L_22 ,
V_126 -> V_156 ) ;
goto V_144;
}
return 0 ;
V_144:
F_52 ( V_2 -> V_142 ) ;
V_143:
F_52 ( V_2 -> V_141 ) ;
return V_19 ;
}
