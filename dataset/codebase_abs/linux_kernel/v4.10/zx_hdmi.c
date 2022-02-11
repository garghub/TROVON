static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 * 4 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 * 4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_6 , T_1 V_5 )
{
T_1 V_7 ;
V_7 = F_1 ( V_2 , V_3 ) ;
V_7 = ( V_7 & ~ V_6 ) | ( V_5 & V_6 ) ;
F_3 ( V_2 , V_3 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
union V_8 * V_9 , T_1 V_10 )
{
T_1 V_11 [ V_12 ] ;
int V_13 ;
int V_14 ;
F_3 ( V_2 , V_15 , V_10 ) ;
V_13 = F_7 ( V_9 , V_11 , V_12 ) ;
if ( V_13 < 0 ) {
F_8 ( V_2 -> V_16 , L_1 , V_13 ) ;
return V_13 ;
}
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
F_3 ( V_2 , V_17 + V_14 , V_11 [ V_14 ] ) ;
F_5 ( V_2 , V_18 , V_19 ,
V_19 ) ;
F_5 ( V_2 , V_18 , V_20 ,
V_20 ) ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
union V_8 V_9 ;
int V_23 ;
V_23 = F_10 ( & V_9 . V_24 . V_2 ,
V_22 ) ;
if ( V_23 ) {
F_8 ( V_2 -> V_16 , L_2 ,
V_23 ) ;
return V_23 ;
}
return F_6 ( V_2 , & V_9 , V_25 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
union V_8 V_9 ;
int V_23 ;
V_23 = F_12 ( & V_9 . V_26 , V_22 ) ;
if ( V_23 ) {
F_8 ( V_2 -> V_16 , L_3 ,
V_23 ) ;
return V_23 ;
}
V_9 . V_26 . V_27 = V_28 ;
return F_6 ( V_2 , & V_9 , V_29 ) ;
}
static void F_13 ( struct V_30 * V_31 ,
struct V_21 * V_22 ,
struct V_21 * V_32 )
{
struct V_1 * V_2 = F_14 ( V_31 ) ;
if ( V_2 -> V_33 ) {
F_11 ( V_2 , V_22 ) ;
F_9 ( V_2 , V_22 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0x222 , 0x0 ) ;
F_3 ( V_2 , 0x224 , 0x4 ) ;
F_3 ( V_2 , 0x909 , 0x0 ) ;
F_3 ( V_2 , 0x7b0 , 0x90 ) ;
F_3 ( V_2 , 0x7b1 , 0x00 ) ;
F_3 ( V_2 , 0x7b2 , 0xa7 ) ;
F_3 ( V_2 , 0x7b8 , 0xaa ) ;
F_3 ( V_2 , 0x7b2 , 0xa7 ) ;
F_3 ( V_2 , 0x7b3 , 0x0f ) ;
F_3 ( V_2 , 0x7b4 , 0x0f ) ;
F_3 ( V_2 , 0x7b5 , 0x55 ) ;
F_3 ( V_2 , 0x7b7 , 0x03 ) ;
F_3 ( V_2 , 0x7b9 , 0x12 ) ;
F_3 ( V_2 , 0x7ba , 0x32 ) ;
F_3 ( V_2 , 0x7bc , 0x68 ) ;
F_3 ( V_2 , 0x7be , 0x40 ) ;
F_3 ( V_2 , 0x7bf , 0x84 ) ;
F_3 ( V_2 , 0x7c1 , 0x0f ) ;
F_3 ( V_2 , 0x7c8 , 0x02 ) ;
F_3 ( V_2 , 0x7c9 , 0x03 ) ;
F_3 ( V_2 , 0x7ca , 0x40 ) ;
F_3 ( V_2 , 0x7dc , 0x31 ) ;
F_3 ( V_2 , 0x7e2 , 0x04 ) ;
F_3 ( V_2 , 0x7e0 , 0x06 ) ;
F_3 ( V_2 , 0x7cb , 0x68 ) ;
F_3 ( V_2 , 0x7f9 , 0x02 ) ;
F_3 ( V_2 , 0x7b6 , 0x02 ) ;
F_3 ( V_2 , 0x7f3 , 0x0 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_34 , V_35 , V_35 ) ;
F_5 ( V_2 , V_36 , V_37 , V_37 ) ;
F_5 ( V_2 , V_38 , V_39 , V_39 ) ;
F_5 ( V_2 , V_40 , V_41 ,
V_41 ) ;
F_3 ( V_2 , V_42 , 0x3 ) ;
F_5 ( V_2 , V_43 , V_44 ,
V_44 ) ;
F_15 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_43 , V_44 , 0 ) ;
F_5 ( V_2 , V_38 , V_39 , V_39 ) ;
F_5 ( V_2 , V_36 , V_37 , 0 ) ;
F_5 ( V_2 , V_34 , V_35 , 0 ) ;
}
static void F_18 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_14 ( V_31 ) ;
F_19 ( V_2 -> V_45 ) ;
F_19 ( V_2 -> V_46 ) ;
F_19 ( V_2 -> V_47 ) ;
F_16 ( V_2 ) ;
F_20 ( V_2 -> V_48 , V_31 -> V_49 ) ;
}
static void F_21 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_14 ( V_31 ) ;
F_22 ( V_2 -> V_48 , V_31 -> V_49 ) ;
F_17 ( V_2 ) ;
F_23 ( V_2 -> V_47 ) ;
F_23 ( V_2 -> V_46 ) ;
F_23 ( V_2 -> V_45 ) ;
}
static int F_24 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
struct V_52 * V_52 ;
int V_23 ;
V_52 = F_25 ( V_51 , & V_2 -> V_53 -> V_54 ) ;
if ( ! V_52 )
return 0 ;
V_2 -> V_33 = F_26 ( V_52 ) ;
V_2 -> V_55 = F_27 ( V_52 ) ;
F_28 ( V_51 , V_52 ) ;
V_23 = F_29 ( V_51 , V_52 ) ;
F_30 ( V_52 ) ;
return V_23 ;
}
static enum V_56
F_31 ( struct V_50 * V_51 ,
struct V_21 * V_22 )
{
return V_57 ;
}
static enum V_58
F_32 ( struct V_50 * V_51 , bool V_59 )
{
struct V_1 * V_2 = F_14 ( V_51 ) ;
return ( F_1 ( V_2 , V_60 ) & V_61 ) ?
V_62 : V_63 ;
}
static int F_33 ( struct V_64 * V_65 , struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
V_31 -> V_66 = V_67 ;
F_34 ( V_65 , V_31 , & V_68 ,
V_69 , NULL ) ;
F_35 ( V_31 , & V_70 ) ;
V_2 -> V_51 . V_71 = V_72 ;
F_36 ( V_65 , & V_2 -> V_51 , & V_73 ,
V_74 ) ;
F_37 ( & V_2 -> V_51 ,
& V_75 ) ;
F_38 ( & V_2 -> V_51 , V_31 ) ;
return 0 ;
}
static T_3 F_39 ( int V_76 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
F_40 ( V_2 -> V_51 . V_16 ) ;
return V_78 ;
}
static T_3 F_41 ( int V_76 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
T_1 V_79 ;
V_79 = F_1 ( V_2 , V_80 ) ;
if ( V_79 & V_81 ) {
T_1 V_82 ;
V_82 = F_1 ( V_2 , V_83 ) ;
F_3 ( V_2 , V_83 , V_82 ) ;
if ( V_82 & V_44 )
return V_84 ;
}
return V_85 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
int V_88 = V_87 -> V_88 ;
T_1 * V_89 = V_87 -> V_89 ;
int V_90 = 0 ;
int V_23 = 0 ;
F_3 ( V_2 , V_91 , ( V_88 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_92 , V_88 & 0xff ) ;
F_5 ( V_2 , V_93 , V_94 , V_95 ) ;
F_5 ( V_2 , V_93 , V_94 ,
V_96 ) ;
while ( V_88 > 0 ) {
int V_97 , V_14 ;
F_43 ( 500 , 1000 ) ;
V_97 = F_1 ( V_2 , V_98 ) & V_99 ;
if ( V_97 == 0 ) {
if ( ++ V_90 > 5 ) {
F_8 ( V_2 -> V_16 ,
L_4 ) ;
return - V_100 ;
}
continue;
}
for ( V_14 = 0 ; V_14 < V_97 ; V_14 ++ )
* V_89 ++ = F_1 ( V_2 , V_101 ) ;
V_88 -= V_97 ;
}
return V_23 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
if ( ( V_87 -> V_88 != 1 ) ||
( ( V_87 -> V_102 != V_103 ) && ( V_87 -> V_102 != V_104 ) ) )
return - V_105 ;
if ( V_87 -> V_102 == V_104 )
F_3 ( V_2 , V_106 , V_87 -> V_102 << 1 ) ;
else if ( V_87 -> V_102 == V_103 )
F_3 ( V_2 , V_107 , V_87 -> V_102 << 1 ) ;
F_3 ( V_2 , V_108 , V_87 -> V_89 [ 0 ] ) ;
return 0 ;
}
static int F_45 ( struct V_109 * V_54 , struct V_86 * V_110 ,
int V_13 )
{
struct V_1 * V_2 = F_46 ( V_54 ) ;
struct V_111 * V_53 = V_2 -> V_53 ;
int V_14 , V_23 = 0 ;
F_47 ( & V_53 -> V_112 ) ;
F_5 ( V_2 , V_113 , V_114 , V_114 ) ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
F_48 ( V_2 -> V_16 ,
L_5 ,
V_14 + 1 , V_13 , V_110 [ V_14 ] . V_88 , V_110 [ V_14 ] . V_115 ) ;
if ( V_110 [ V_14 ] . V_115 & V_116 )
V_23 = F_42 ( V_2 , & V_110 [ V_14 ] ) ;
else
V_23 = F_44 ( V_2 , & V_110 [ V_14 ] ) ;
if ( V_23 < 0 )
break;
}
if ( ! V_23 )
V_23 = V_13 ;
F_5 ( V_2 , V_113 , V_114 , 0 ) ;
F_49 ( & V_53 -> V_112 ) ;
return V_23 ;
}
static T_4 F_50 ( struct V_109 * V_117 )
{
return V_118 | V_119 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_109 * V_54 ;
struct V_111 * V_53 ;
int V_23 ;
V_53 = F_52 ( V_2 -> V_16 , sizeof( * V_53 ) , V_120 ) ;
if ( ! V_53 )
return - V_121 ;
V_2 -> V_53 = V_53 ;
F_53 ( & V_53 -> V_112 ) ;
V_54 = & V_53 -> V_54 ;
V_54 -> V_122 = V_123 ;
V_54 -> V_124 = V_125 ;
V_54 -> V_16 . V_126 = V_2 -> V_16 ;
V_54 -> V_127 = & V_128 ;
snprintf ( V_54 -> V_129 , sizeof( V_54 -> V_129 ) , L_6 ) ;
V_23 = F_54 ( V_54 ) ;
if ( V_23 ) {
F_8 ( V_2 -> V_16 , L_7 ,
V_23 ) ;
return V_23 ;
}
F_55 ( V_54 , V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_130 * V_16 , struct V_130 * V_131 , void * V_132 )
{
struct V_133 * V_134 = F_57 ( V_16 ) ;
struct V_64 * V_65 = V_132 ;
struct V_135 * V_136 ;
struct V_1 * V_2 ;
int V_76 ;
int V_23 ;
V_2 = F_52 ( V_16 , sizeof( * V_2 ) , V_120 ) ;
if ( ! V_2 )
return - V_121 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_48 = & V_137 ;
F_58 ( V_16 , V_2 ) ;
V_136 = F_59 ( V_134 , V_138 , 0 ) ;
V_2 -> V_4 = F_60 ( V_16 , V_136 ) ;
if ( F_61 ( V_2 -> V_4 ) ) {
V_23 = F_62 ( V_2 -> V_4 ) ;
F_8 ( V_16 , L_8 , V_23 ) ;
return V_23 ;
}
V_76 = F_63 ( V_134 , 0 ) ;
if ( V_76 < 0 )
return V_76 ;
V_2 -> V_45 = F_64 ( V_2 -> V_16 , L_9 ) ;
if ( F_61 ( V_2 -> V_45 ) ) {
V_23 = F_62 ( V_2 -> V_45 ) ;
F_8 ( V_16 , L_10 , V_23 ) ;
return V_23 ;
}
V_2 -> V_46 = F_64 ( V_2 -> V_16 , L_11 ) ;
if ( F_61 ( V_2 -> V_46 ) ) {
V_23 = F_62 ( V_2 -> V_46 ) ;
F_8 ( V_16 , L_12 , V_23 ) ;
return V_23 ;
}
V_2 -> V_47 = F_64 ( V_2 -> V_16 , L_13 ) ;
if ( F_61 ( V_2 -> V_47 ) ) {
V_23 = F_62 ( V_2 -> V_47 ) ;
F_8 ( V_16 , L_14 , V_23 ) ;
return V_23 ;
}
V_23 = F_51 ( V_2 ) ;
if ( V_23 ) {
F_8 ( V_16 , L_15 , V_23 ) ;
return V_23 ;
}
V_23 = F_33 ( V_65 , V_2 ) ;
if ( V_23 ) {
F_8 ( V_16 , L_16 , V_23 ) ;
return V_23 ;
}
V_23 = F_65 ( V_16 , V_76 , F_41 ,
F_39 , V_139 ,
F_66 ( V_16 ) , V_2 ) ;
if ( V_23 ) {
F_8 ( V_16 , L_17 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static void F_67 ( struct V_130 * V_16 , struct V_130 * V_131 ,
void * V_132 )
{
struct V_1 * V_2 = F_68 ( V_16 ) ;
V_2 -> V_51 . V_140 -> V_141 ( & V_2 -> V_51 ) ;
V_2 -> V_31 . V_140 -> V_141 ( & V_2 -> V_31 ) ;
}
static int F_69 ( struct V_133 * V_134 )
{
return F_70 ( & V_134 -> V_16 , & V_142 ) ;
}
static int F_71 ( struct V_133 * V_134 )
{
F_72 ( & V_134 -> V_16 , & V_142 ) ;
return 0 ;
}
