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
static inline void F_10 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) )
F_5 ( V_2 , 1 , V_13 ) ;
}
static bool F_11 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_10 ) & V_14 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
T_1 V_9 = F_3 ( V_2 , V_10 ) ;
return ( F_8 ( V_9 ) == V_11 ) &&
( V_9 & V_14 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
bool (* F_14)( struct V_1 * ) )
{
unsigned long V_15 ;
V_15 = V_16 + F_15 ( 255 ) ;
do {
if ( F_16 ( V_16 , V_15 ) )
return F_14 ( V_2 ) ? 0 : - V_17 ;
if ( F_14 ( V_2 ) )
return 0 ;
} while ( 1 );
}
static int F_17 ( struct V_1 * V_2 , T_1 V_18 , T_1 V_19 )
{
int V_20 ;
V_20 = F_13 ( V_2 , F_7 ) ;
if ( V_20 ) {
F_10 ( V_2 ) ;
return V_20 ;
}
F_5 ( V_2 , ( 1 << 31 ) | ( ( V_18 >> 1 ) << 16 ) | V_19 ,
V_21 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_18 , T_1 * V_22 )
{
int V_20 ;
V_20 = F_13 ( V_2 , F_7 ) ;
if ( V_20 ) {
F_10 ( V_2 ) ;
return V_20 ;
}
F_5 ( V_2 , ( V_18 >> 1 ) << 16 , V_21 ) ;
V_20 = F_13 ( V_2 , F_9 ) ;
if ( V_20 )
return V_20 ;
* V_22 = F_19 ( F_3 ( V_2 , V_10 ) ) ;
F_5 ( V_2 , 1 , V_13 ) ;
return 0 ;
}
static int F_20 ( void * V_23 , T_1 V_18 , T_1 * V_22 )
{
return F_18 ( V_23 , V_18 , V_22 ) ;
}
static int F_21 ( void * V_23 , T_1 V_18 , T_1 V_19 )
{
return F_17 ( V_23 , V_18 , V_19 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_20 , V_24 ;
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
V_20 = F_13 ( V_2 , F_11 ) ;
if ( V_20 ) {
F_23 ( V_2 -> V_35 , L_1 , V_36 , V_20 ) ;
return V_20 ;
}
F_5 ( V_2 , 0 , V_28 ) ;
F_5 ( V_2 , 0 , V_27 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_1 V_22 ;
T_1 V_24 ;
T_1 V_37 = 0 ;
signed char V_38 [ 16 ] = {
- 1 , 0 , 1 , 0 , 2 , - 1 , 1 , 1 , 3 , - 1 , - 1 , - 1 , 3 , - 1 , 2 , 1
} ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
F_5 ( V_2 , V_24 , V_39 ) ;
F_18 ( V_2 , V_40 , & V_22 ) ;
if ( V_22 == V_41 ) {
F_25 ( V_2 -> V_35 , L_2 , V_24 ) ;
V_37 |= 1 << V_24 ;
}
}
if ( V_38 [ V_37 ] < 0 ) {
F_23 ( V_2 -> V_35 , L_3 ,
V_37 ) ;
return - V_42 ;
}
F_5 ( V_2 , V_38 [ V_37 ] , V_39 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
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
static bool F_27 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_48 ) & 1 ;
}
static bool F_28 ( struct V_1 * V_2 )
{
T_1 V_22 ;
int V_20 ;
V_20 = F_18 ( V_2 , V_49 , & V_22 ) ;
if ( V_20 )
return 0 ;
return V_22 == 1 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_20 ;
T_1 V_22 ;
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
F_17 ( V_2 , V_56 , 0x1 ) ;
F_17 ( V_2 , V_56 , 0x0 ) ;
F_17 ( V_2 , V_57 , 0x1 ) ;
F_17 ( V_2 , V_58 , 0x2 ) ;
F_17 ( V_2 , V_59 , 0x1 ) ;
F_17 ( V_2 , V_60 , 0x1 ) ;
V_20 = F_13 ( V_2 , F_27 ) ;
if ( V_20 ) {
F_23 ( V_2 -> V_35 , L_4 , V_20 ) ;
return V_20 ;
}
V_20 = F_13 ( V_2 , F_28 ) ;
if ( V_20 ) {
F_23 ( V_2 -> V_35 , L_5 ) ;
return V_20 ;
}
F_17 ( V_2 , V_61 , 0x1 ) ;
V_20 = F_13 ( V_2 , F_12 ) ;
if ( V_20 ) {
F_23 ( V_2 -> V_35 , L_6 , V_20 ) ;
return V_20 ;
}
F_5 ( V_2 , 1 , V_62 ) ;
if ( F_17 ( V_2 , V_63 , V_64 ) ||
F_18 ( V_2 , V_63 , & V_22 ) ||
( V_22 != V_64 ) ) {
F_23 ( V_2 -> V_35 , L_7 , V_22 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_20 ;
T_1 V_22 ;
F_31 ( V_2 -> V_66 ) ;
if ( V_2 -> V_67 )
F_31 ( V_2 -> V_67 ) ;
if ( F_2 ( V_2 ) ) {
F_5 ( V_2 , 3 , V_68 ) ;
F_5 ( V_2 , 0 , V_69 ) ;
}
V_20 = F_22 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_5 ( V_2 , 1 , V_26 ) ;
F_5 ( V_2 , V_2 -> V_70 , V_25 ) ;
F_5 ( V_2 , 1 , V_71 ) ;
V_20 = F_26 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_24 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_17 ( V_2 , V_72 , 1 ) ;
V_20 = F_13 ( V_2 , F_12 ) ;
if ( V_20 ) {
F_23 ( V_2 -> V_35 , L_1 , V_36 , V_20 ) ;
return V_20 ;
}
F_5 ( V_2 , 1 , V_29 ) ;
F_18 ( V_2 , V_40 , & V_22 ) ;
if ( V_22 != V_41 ) {
F_23 ( V_2 -> V_35 , L_8 ,
V_41 , V_22 ) ;
return - V_65 ;
}
V_20 = F_29 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( F_17 ( V_2 , V_73 , 0x1 ) )
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
if ( F_1 ( V_2 ) ) {
F_5 ( V_2 , 0x1 , V_83 ) ;
F_5 ( V_2 , 0xffff , V_84 ) ;
F_6 ( 0x7f , V_2 -> V_85 + V_86 ) ;
F_6 ( 0x1 , V_2 -> V_85 + V_87 ) ;
F_6 ( 0x1 , V_2 -> V_85 + V_88 ) ;
F_6 ( 0x1 , V_2 -> V_85 + V_89 ) ;
F_6 ( 0xffff , V_2 -> V_85 + V_90 ) ;
F_6 ( 0x1 , V_2 -> V_85 + V_91 ) ;
F_6 ( 0x7ff , V_2 -> V_85 + V_92 ) ;
if ( F_17 ( V_2 , V_93 , 0x1 ) ||
F_17 ( V_2 , V_94 , 0xffff ) ) {
F_23 ( V_2 -> V_35 , L_9 ) ;
return - V_65 ;
}
} else {
if ( F_17 ( V_2 , V_93 , 0x1 ) ||
F_17 ( V_2 , V_94 , 0xffff ) ) {
F_23 ( V_2 -> V_35 , L_9 ) ;
return - V_65 ;
}
}
F_5 ( V_2 , 1 , V_95 ) ;
F_5 ( V_2 , 1 , V_96 ) ;
F_5 ( V_2 , 1 , V_97 ) ;
if ( F_1 ( V_2 ) ) {
F_6 ( 1 , V_2 -> V_85 + V_98 ) ;
F_6 ( 1 , V_2 -> V_85 + V_99 ) ;
}
return 0 ;
}
static T_2 F_32 ( int V_100 , void * V_101 )
{
T_1 V_22 ;
struct V_1 * V_2 = V_101 ;
V_22 = F_3 ( V_2 , V_102 ) ;
F_23 ( V_2 -> V_35 , L_10 , V_22 ) ;
F_5 ( V_2 , 0xffffffff , V_103 ) ;
return V_104 ;
}
static int F_33 ( struct V_105 * V_106 )
{
int V_20 , V_107 , V_108 ;
struct V_1 * V_2 ;
struct V_109 * V_110 = V_106 -> V_35 . V_111 ;
const struct V_112 * V_113 =
F_34 ( V_114 , & V_106 -> V_35 ) ;
const struct V_115 * type ;
struct V_116 * V_117 ;
V_2 = F_35 ( & V_106 -> V_35 , sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 )
return - V_119 ;
F_36 ( V_106 , V_2 ) ;
type = V_113 -> V_120 ;
V_2 -> V_8 = type -> V_8 ;
V_2 -> type = type -> type ;
V_2 -> V_70 = type -> V_70 ;
V_2 -> V_35 = & V_106 -> V_35 ;
V_117 = F_37 ( V_106 , V_121 , L_11 ) ;
V_2 -> V_7 = F_38 ( V_2 -> V_35 , V_117 ) ;
if ( F_39 ( V_2 -> V_7 ) )
return F_40 ( V_2 -> V_7 ) ;
V_2 -> V_66 = F_41 ( V_2 -> V_35 , L_11 ) ;
if ( F_39 ( V_2 -> V_66 ) ) {
V_20 = F_40 ( V_2 -> V_66 ) ;
F_25 ( V_2 -> V_35 , L_12 , V_20 ) ;
return V_20 ;
}
if ( F_1 ( V_2 ) ) {
V_117 = F_37 ( V_106 , V_121 ,
L_13 ) ;
V_2 -> V_85 = F_38 ( V_2 -> V_35 , V_117 ) ;
if ( F_39 ( V_2 -> V_85 ) )
return F_40 ( V_2 -> V_85 ) ;
V_2 -> V_67 = F_41 ( V_2 -> V_35 , L_13 ) ;
if ( F_39 ( V_2 -> V_67 ) ) {
V_20 = F_40 ( V_2 -> V_67 ) ;
F_25 ( V_2 -> V_35 , L_14 , V_20 ) ;
return V_20 ;
}
}
V_2 -> V_122 = F_42 ( V_2 -> V_35 , L_15 ) ;
if ( F_39 ( V_2 -> V_122 ) ) {
F_25 ( V_2 -> V_35 , L_16 , F_40 ( V_2 -> V_122 ) ) ;
return F_40 ( V_2 -> V_122 ) ;
}
V_2 -> V_123 = F_42 ( V_2 -> V_35 , L_17 ) ;
if ( F_39 ( V_2 -> V_123 ) ) {
F_25 ( V_2 -> V_35 , L_16 , F_40 ( V_2 -> V_123 ) ) ;
return F_40 ( V_2 -> V_123 ) ;
}
V_20 = F_43 ( V_2 -> V_122 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_43 ( V_2 -> V_123 ) ;
if ( V_20 )
goto V_124;
F_5 ( V_2 , 1 , V_68 ) ;
F_5 ( V_2 , 0 , V_69 ) ;
if ( ! F_3 ( V_2 , V_95 ) ) {
V_20 = F_30 ( V_2 ) ;
if ( V_20 ) {
F_25 ( V_2 -> V_35 , L_18 , V_20 ) ;
goto V_125;
}
}
if ( ! ( F_3 ( V_2 , V_10 ) & V_126 ) ) {
F_25 ( V_2 -> V_35 , L_19 ) ;
return - V_127 ;
}
F_5 ( V_2 , 0xf , V_128 ) ;
V_108 = F_2 ( V_2 ) ?
V_129 : V_130 ;
F_5 ( V_2 , V_108 , V_131 ) ;
F_5 ( V_2 , 0x1 , V_132 ) ;
F_5 ( V_2 , ~ ( ( 1 << 31 ) | ( 1 << 1 ) ) , V_133 ) ;
V_107 = F_44 ( V_106 , 0 ) ;
V_20 = F_45 ( V_2 -> V_35 , V_107 , F_32 , V_134 ,
L_20 , V_2 ) ;
if ( V_20 )
goto V_125;
V_2 -> V_135 = F_46 ( V_2 -> V_35 , NULL , V_2 , & V_136 ) ;
if ( F_39 ( V_2 -> V_135 ) )
return F_40 ( V_2 -> V_135 ) ;
V_20 = F_47 ( V_110 , NULL , NULL , V_2 -> V_35 ) ;
if ( V_20 ) {
F_25 ( V_2 -> V_35 , L_21 ,
V_110 -> V_137 ) ;
goto V_125;
}
return 0 ;
V_125:
F_48 ( V_2 -> V_123 ) ;
V_124:
F_48 ( V_2 -> V_122 ) ;
return V_20 ;
}
