static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> type == V_3 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> type == V_4 ;
}
static T_1 F_3 ( struct V_1 * V_2 , enum V_5 V_6 )
{
return F_4 ( V_2 -> V_7 + V_2 -> V_8 [ V_6 ] ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_9 , enum V_5 V_6 )
{
F_6 ( V_9 , V_2 -> V_7 + V_2 -> V_8 [ V_6 ] ) ;
}
static bool F_7 ( struct V_1 * V_2 )
{
T_1 V_9 = F_3 ( V_2 , V_10 ) ;
return F_8 ( V_9 ) == V_11 ;
}
static bool F_9 ( struct V_1 * V_2 )
{
T_1 V_9 = F_3 ( V_2 , V_10 ) ;
return F_8 ( V_9 ) == V_12 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_10 ) & V_13 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
T_1 V_9 = F_3 ( V_2 , V_10 ) ;
return ( F_8 ( V_9 ) == V_11 ) &&
( V_9 & V_13 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
bool (* F_13)( struct V_1 * ) )
{
unsigned long V_14 ;
V_14 = V_15 + F_14 ( 255 ) ;
do {
if ( F_15 ( V_15 , V_14 ) )
return F_13 ( V_2 ) ? 0 : - V_16 ;
if ( F_13 ( V_2 ) )
return 0 ;
} while ( 1 );
}
static int F_16 ( struct V_1 * V_2 , T_1 V_17 , T_1 V_18 )
{
int V_19 ;
V_19 = F_12 ( V_2 , F_7 ) ;
if ( V_19 )
return V_19 ;
F_5 ( V_2 , ( 1 << 31 ) | ( ( V_17 >> 1 ) << 16 ) | V_18 ,
V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_17 , T_1 * V_21 )
{
int V_19 ;
V_19 = F_12 ( V_2 , F_7 ) ;
if ( V_19 )
return V_19 ;
F_5 ( V_2 , ( V_17 >> 1 ) << 16 , V_20 ) ;
V_19 = F_12 ( V_2 , F_9 ) ;
if ( V_19 )
return V_19 ;
* V_21 = F_18 ( F_3 ( V_2 , V_10 ) ) ;
F_5 ( V_2 , 1 , V_22 ) ;
return 0 ;
}
static int F_19 ( void * V_23 , T_1 V_17 , T_1 * V_21 )
{
return F_17 ( V_23 , V_17 , V_21 ) ;
}
static int F_20 ( void * V_23 , T_1 V_17 , T_1 V_18 )
{
return F_16 ( V_23 , V_17 , V_18 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_19 , V_24 ;
F_5 ( V_2 , 0 , V_25 ) ;
F_5 ( V_2 , 0 , V_26 ) ;
F_5 ( V_2 , 1 , V_27 ) ;
F_5 ( V_2 , 1 , V_28 ) ;
F_5 ( V_2 , 0 , V_29 ) ;
F_5 ( V_2 , V_30 | V_31 ,
V_32 ) ;
F_5 ( V_2 , V_30 | V_33 ,
V_32 ) ;
F_5 ( V_2 , V_30 | V_34 ,
V_32 ) ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ )
F_5 ( V_2 , V_30 | V_33 ,
V_32 ) ;
V_19 = F_12 ( V_2 , F_10 ) ;
if ( V_19 ) {
F_22 ( V_2 -> V_35 , L_1 , V_36 , V_19 ) ;
return V_19 ;
}
F_5 ( V_2 , 0 , V_28 ) ;
F_5 ( V_2 , 0 , V_27 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_21 ;
T_1 V_24 ;
T_1 V_37 = 0 ;
signed char V_38 [ 16 ] = {
- 1 , 0 , 1 , 0 , 2 , - 1 , 1 , 1 , 3 , - 1 , - 1 , - 1 , 3 , - 1 , 2 , 1
} ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
F_5 ( V_2 , V_24 , V_39 ) ;
F_17 ( V_2 , V_40 , & V_21 ) ;
if ( V_21 == V_41 ) {
F_24 ( V_2 -> V_35 , L_2 , V_24 ) ;
V_37 |= 1 << V_24 ;
}
}
if ( V_38 [ V_37 ] < 0 ) {
F_22 ( V_2 -> V_35 , L_3 ,
V_37 ) ;
return - V_42 ;
}
F_5 ( V_2 , V_38 [ V_37 ] , V_39 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) ) {
F_5 ( V_2 , 0x4 , V_43 ) ;
F_5 ( V_2 , 0x0 , V_44 ) ;
F_5 ( V_2 , 0x4 , V_45 ) ;
F_5 ( V_2 , 0x0 , V_46 ) ;
F_5 ( V_2 , 0x0 , V_47 ) ;
} else {
F_5 ( V_2 , 0x0 , V_44 ) ;
F_5 ( V_2 , 0x4 , V_45 ) ;
F_5 ( V_2 , 0x2 , V_46 ) ;
F_5 ( V_2 , 0x2 , V_47 ) ;
}
return 0 ;
}
static bool F_26 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_48 ) & 1 ;
}
static bool F_27 ( struct V_1 * V_2 )
{
T_1 V_21 ;
int V_19 ;
V_19 = F_17 ( V_2 , V_49 , & V_21 ) ;
if ( V_19 )
return 0 ;
return V_21 == 1 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_19 ;
T_1 V_21 ;
F_5 ( V_2 , 0x1 , V_50 ) ;
F_5 ( V_2 , 0x0 , V_50 ) ;
F_5 ( V_2 , 0x1 , V_51 ) ;
F_5 ( V_2 , 0x2 , V_52 ) ;
if ( F_1 ( V_2 ) ) {
F_5 ( V_2 , 1 , V_53 ) ;
F_5 ( V_2 , 1 , V_54 ) ;
} else {
F_5 ( V_2 , 1 , V_55 ) ;
}
F_16 ( V_2 , V_56 , 0x1 ) ;
F_16 ( V_2 , V_56 , 0x0 ) ;
F_16 ( V_2 , V_57 , 0x1 ) ;
F_16 ( V_2 , V_58 , 0x2 ) ;
F_16 ( V_2 , V_59 , 0x1 ) ;
F_16 ( V_2 , V_60 , 0x1 ) ;
V_19 = F_12 ( V_2 , F_26 ) ;
if ( V_19 ) {
F_22 ( V_2 -> V_35 , L_4 , V_19 ) ;
return V_19 ;
}
V_19 = F_12 ( V_2 , F_27 ) ;
if ( V_19 ) {
F_22 ( V_2 -> V_35 , L_5 ) ;
return V_19 ;
}
F_16 ( V_2 , V_61 , 0x1 ) ;
V_19 = F_12 ( V_2 , F_11 ) ;
if ( V_19 ) {
F_22 ( V_2 -> V_35 , L_6 , V_19 ) ;
return V_19 ;
}
F_5 ( V_2 , 1 , V_62 ) ;
if ( F_16 ( V_2 , V_63 , V_64 ) ||
F_17 ( V_2 , V_63 , & V_21 ) ||
( V_21 != V_64 ) ) {
F_22 ( V_2 -> V_35 , L_7 , V_21 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_19 ;
T_1 V_21 ;
F_30 ( V_2 -> V_66 ) ;
if ( V_2 -> V_67 )
F_30 ( V_2 -> V_67 ) ;
if ( F_2 ( V_2 ) ) {
F_5 ( V_2 , 3 , V_68 ) ;
F_5 ( V_2 , 0 , V_69 ) ;
}
V_19 = F_21 ( V_2 ) ;
if ( V_19 )
return V_19 ;
F_5 ( V_2 , 1 , V_26 ) ;
F_5 ( V_2 , V_2 -> V_70 , V_25 ) ;
F_5 ( V_2 , 1 , V_71 ) ;
V_19 = F_25 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_23 ( V_2 ) ;
if ( V_19 )
return V_19 ;
F_16 ( V_2 , V_72 , 1 ) ;
V_19 = F_12 ( V_2 , F_11 ) ;
if ( V_19 ) {
F_22 ( V_2 -> V_35 , L_1 , V_36 , V_19 ) ;
return V_19 ;
}
F_5 ( V_2 , 1 , V_29 ) ;
F_17 ( V_2 , V_40 , & V_21 ) ;
if ( V_21 != V_41 ) {
F_22 ( V_2 -> V_35 , L_8 ,
V_41 , V_21 ) ;
return - V_65 ;
}
V_19 = F_28 ( V_2 ) ;
if ( V_19 )
return V_19 ;
if ( F_16 ( V_2 , V_73 , 0x1 ) )
return - V_65 ;
F_5 ( V_2 , 0x1 , V_74 ) ;
F_5 ( V_2 , 0x0 , V_75 ) ;
F_5 ( V_2 , V_76 , V_77 ) ;
F_5 ( V_2 , V_2 -> V_70 , V_25 ) ;
if ( F_1 ( V_2 ) )
F_5 ( V_2 , 0x7 , V_78 ) ;
F_5 ( V_2 , 0x1 , V_79 ) ;
F_5 ( V_2 , 0x1 , V_80 ) ;
F_5 ( V_2 , 0x1 , V_71 ) ;
F_5 ( V_2 , 0x5 , V_81 ) ;
F_5 ( V_2 , 0xff , V_82 ) ;
F_5 ( V_2 , 0xf , V_83 ) ;
F_5 ( V_2 , 0xffffffff , V_84 ) ;
F_5 ( V_2 , 0x1 , V_85 ) ;
F_5 ( V_2 , ~ ( ( 1 << 31 ) | ( 1 << 1 ) ) , V_86 ) ;
if ( F_1 ( V_2 ) ) {
F_5 ( V_2 , 0x1 , V_87 ) ;
F_5 ( V_2 , 0xffff , V_88 ) ;
F_6 ( 0x7f , V_2 -> V_89 + V_90 ) ;
F_6 ( 0x1 , V_2 -> V_89 + V_91 ) ;
F_6 ( 0x1 , V_2 -> V_89 + V_92 ) ;
F_6 ( 0x1 , V_2 -> V_89 + V_93 ) ;
F_6 ( 0xffff , V_2 -> V_89 + V_94 ) ;
F_6 ( 0x1 , V_2 -> V_89 + V_95 ) ;
F_6 ( 0x7ff , V_2 -> V_89 + V_96 ) ;
if ( F_16 ( V_2 , V_97 , 0x1 ) ||
F_16 ( V_2 , V_98 , 0xffff ) ) {
F_22 ( V_2 -> V_35 , L_9 ) ;
return - V_65 ;
}
} else {
if ( F_16 ( V_2 , V_97 , 0x1 ) ||
F_16 ( V_2 , V_98 , 0xffff ) ) {
F_22 ( V_2 -> V_35 , L_9 ) ;
return - V_65 ;
}
}
F_5 ( V_2 , 1 , V_99 ) ;
F_5 ( V_2 , 1 , V_100 ) ;
F_5 ( V_2 , 1 , V_101 ) ;
if ( F_1 ( V_2 ) ) {
F_6 ( 1 , V_2 -> V_89 + V_102 ) ;
F_6 ( 1 , V_2 -> V_89 + V_103 ) ;
}
return 0 ;
}
static T_2 F_31 ( int V_104 , void * V_105 )
{
T_1 V_21 ;
struct V_1 * V_2 = V_105 ;
V_21 = F_3 ( V_2 , V_106 ) ;
F_22 ( V_2 -> V_35 , L_10 , V_21 ) ;
F_5 ( V_2 , 0xffffffff , V_107 ) ;
return V_108 ;
}
static int F_32 ( struct V_109 * V_110 )
{
int V_19 , V_111 ;
struct V_1 * V_2 ;
struct V_112 * V_113 = V_110 -> V_35 . V_114 ;
const struct V_115 * V_116 =
F_33 ( V_117 , & V_110 -> V_35 ) ;
const struct V_118 * type ;
struct V_119 * V_120 ;
V_2 = F_34 ( & V_110 -> V_35 , sizeof( * V_2 ) , V_121 ) ;
if ( ! V_2 )
return - V_122 ;
F_35 ( V_110 , V_2 ) ;
type = V_116 -> V_123 ;
V_2 -> V_8 = type -> V_8 ;
V_2 -> type = type -> type ;
V_2 -> V_70 = type -> V_70 ;
V_2 -> V_35 = & V_110 -> V_35 ;
V_120 = F_36 ( V_110 , V_124 , L_11 ) ;
V_2 -> V_7 = F_37 ( V_2 -> V_35 , V_120 ) ;
if ( F_38 ( V_2 -> V_7 ) )
return F_39 ( V_2 -> V_7 ) ;
V_2 -> V_66 = F_40 ( V_2 -> V_35 , L_11 ) ;
if ( F_38 ( V_2 -> V_66 ) ) {
V_19 = F_39 ( V_2 -> V_66 ) ;
F_24 ( V_2 -> V_35 , L_12 , V_19 ) ;
return V_19 ;
}
if ( F_1 ( V_2 ) ) {
V_120 = F_36 ( V_110 , V_124 ,
L_13 ) ;
V_2 -> V_89 = F_37 ( V_2 -> V_35 , V_120 ) ;
if ( F_38 ( V_2 -> V_89 ) )
return F_39 ( V_2 -> V_89 ) ;
V_2 -> V_67 = F_40 ( V_2 -> V_35 , L_13 ) ;
if ( F_38 ( V_2 -> V_67 ) ) {
V_19 = F_39 ( V_2 -> V_67 ) ;
F_24 ( V_2 -> V_35 , L_14 , V_19 ) ;
return V_19 ;
}
}
V_2 -> V_125 = F_41 ( V_2 -> V_35 , L_15 ) ;
if ( F_38 ( V_2 -> V_125 ) ) {
F_24 ( V_2 -> V_35 , L_16 , F_39 ( V_2 -> V_125 ) ) ;
return F_39 ( V_2 -> V_125 ) ;
}
V_2 -> V_126 = F_41 ( V_2 -> V_35 , L_17 ) ;
if ( F_38 ( V_2 -> V_126 ) ) {
F_24 ( V_2 -> V_35 , L_16 , F_39 ( V_2 -> V_126 ) ) ;
return F_39 ( V_2 -> V_126 ) ;
}
V_19 = F_42 ( V_2 -> V_125 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_42 ( V_2 -> V_126 ) ;
if ( V_19 )
goto V_127;
F_5 ( V_2 , 1 , V_68 ) ;
F_5 ( V_2 , 0 , V_69 ) ;
if ( ! F_3 ( V_2 , V_99 ) ) {
V_19 = F_29 ( V_2 ) ;
if ( V_19 ) {
F_24 ( V_2 -> V_35 , L_18 , V_19 ) ;
goto V_128;
}
}
if ( ! ( F_3 ( V_2 , V_10 ) & V_129 ) ) {
F_24 ( V_2 -> V_35 , L_19 ) ;
return - V_130 ;
}
V_111 = F_43 ( V_110 , 0 ) ;
V_19 = F_44 ( V_2 -> V_35 , V_111 , F_31 , V_131 ,
L_20 , V_2 ) ;
if ( V_19 )
goto V_128;
V_2 -> V_132 = F_45 ( V_2 -> V_35 , NULL , V_2 , & V_133 ) ;
if ( F_38 ( V_2 -> V_132 ) )
return F_39 ( V_2 -> V_132 ) ;
V_19 = F_46 ( V_113 , NULL , NULL , V_2 -> V_35 ) ;
if ( V_19 ) {
F_24 ( V_2 -> V_35 , L_21 ,
V_113 -> V_134 ) ;
goto V_128;
}
return 0 ;
V_128:
F_47 ( V_2 -> V_126 ) ;
V_127:
F_47 ( V_2 -> V_125 ) ;
return V_19 ;
}
