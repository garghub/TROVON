static inline void F_1 ( int V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_3 . V_4 + V_1 ) ;
}
static inline T_1 F_3 ( int V_1 )
{
T_1 V_5 = F_4 ( V_3 . V_4 + V_1 ) ;
return V_5 ;
}
static void F_5 ( const struct V_6 * V_7 )
{
F_6 ( L_1 ) ;
F_1 ( V_8 , V_7 -> V_9 ) ;
F_1 ( V_10 , V_7 -> V_11 ) ;
F_1 ( V_12 , V_7 -> V_13 ) ;
F_1 ( V_14 , V_7 -> V_15 ) ;
F_1 ( V_16 , V_7 -> V_17 ) ;
F_1 ( V_18 , V_7 -> V_19 ) ;
F_1 ( V_20 , V_7 -> V_21 ) ;
F_1 ( V_22 , V_7 -> V_23 ) ;
F_1 ( V_24 , V_7 -> V_25 ) ;
F_1 ( V_26 , V_7 -> V_27 ) ;
F_1 ( V_28 , V_7 -> V_29 |
V_3 . V_30 ) ;
F_1 ( V_31 , V_7 -> V_32 ) ;
F_1 ( V_33 , V_7 -> V_34 ) ;
F_1 ( V_35 , V_7 -> V_36 ) ;
F_1 ( V_37 , V_7 -> V_38 ) ;
F_1 ( V_39 , V_7 -> V_40 ) ;
F_1 ( V_41 , V_7 -> V_42 ) ;
F_1 ( V_43 , V_7 -> V_44 ) ;
F_1 ( V_45 , V_7 -> V_46 ) ;
F_1 ( V_47 ,
V_7 -> V_48 ) ;
F_1 ( V_49 ,
V_7 -> V_50 ) ;
F_1 ( V_51 ,
V_7 -> V_52 ) ;
F_1 ( V_53 , V_7 -> V_54 ) ;
F_1 ( V_55 , V_7 -> V_56 ) ;
F_1 ( V_57 , V_7 -> V_58 ) ;
F_1 ( V_59 ,
V_7 -> V_60 ) ;
F_1 ( V_61 ,
V_7 -> V_62 ) ;
F_1 ( V_63 ,
V_7 -> V_64 ) ;
F_1 ( V_65 , F_3 ( V_65 ) ) ;
F_1 ( V_66 , V_7 -> V_67 ) ;
F_1 ( V_68 , V_7 -> V_69 ) ;
F_1 ( V_70 , V_7 -> V_71 ) ;
F_1 ( V_72 , V_7 -> V_73 ) ;
F_1 ( V_74 , V_7 -> V_75 ) ;
F_1 ( V_76 , V_7 -> V_77 ) ;
F_1 ( V_78 ,
V_7 -> V_79 ) ;
F_1 ( V_80 ,
V_7 -> V_81 ) ;
F_1 ( V_82 , V_7 -> V_83 ) ;
F_1 ( V_84 , V_7 -> V_85 ) ;
F_1 ( V_86 , V_7 -> V_87 ) ;
}
static void F_7 ( void )
{
int V_88 = 1000 ;
F_1 ( V_84 , 1 << 8 ) ;
while ( F_3 ( V_84 ) & ( 1 << 8 ) ) {
if ( -- V_88 == 0 ) {
F_8 ( L_2 ) ;
return;
}
}
#ifdef F_9
F_10 ( 20 ) ;
#endif
}
static void F_11 ( int V_89 )
{
if ( V_89 )
F_12 ( V_90 | V_91 | V_92 |
V_93 ) ;
else
F_13 ( V_90 | V_91 | V_92 |
V_93 ) ;
}
static const struct V_6 * F_14 (
struct V_94 * V_95 )
{
if ( memcmp ( & V_96 , V_95 , sizeof( * V_95 ) ) == 0 )
return & V_97 ;
if ( memcmp ( & V_98 , V_95 , sizeof( * V_95 ) ) == 0 )
return & V_99 ;
F_15 () ;
}
static void F_16 ( struct V_100 * V_101 )
{
T_1 V_5 ;
F_11 ( 1 ) ;
F_7 () ;
F_5 ( F_14 ( & V_101 -> V_102 . V_95 ) ) ;
F_17 ( V_101 -> V_103 . V_3 . type ) ;
F_18 ( 1 ) ;
V_5 = 0 ;
if ( V_101 -> V_103 . V_3 . type == V_104 )
V_5 |= 1 << 1 ;
else
V_5 |= ( 1 << 0 ) | ( 1 << 2 ) ;
if ( V_101 -> V_103 . V_3 . V_105 == false )
V_5 |= 1 << 3 ;
F_1 ( V_106 , V_5 ) ;
F_19 ( V_101 -> V_102 . V_95 . V_107 ,
V_101 -> V_102 . V_95 . V_108 / 2 ) ;
F_20 ( V_3 . V_109 ) ;
if ( V_101 -> V_110 )
V_101 -> V_110 ( V_101 ) ;
V_101 -> V_111 -> V_89 ( V_101 -> V_111 ) ;
}
static void F_21 ( struct V_100 * V_101 )
{
F_1 ( V_106 , 0 ) ;
F_18 ( 0 ) ;
V_101 -> V_111 -> V_112 ( V_101 -> V_111 ) ;
if ( V_101 -> V_113 )
V_101 -> V_113 ( V_101 ) ;
F_22 ( V_3 . V_109 ) ;
F_11 ( 0 ) ;
}
static int F_23 ( struct V_100 * V_101 )
{
V_101 -> V_102 . V_95 = V_96 ;
return 0 ;
}
static void F_24 ( struct V_100 * V_101 )
{
}
static int F_25 ( struct V_100 * V_101 )
{
int V_114 = 0 ;
F_6 ( L_3 ) ;
F_26 ( & V_3 . V_115 ) ;
V_114 = F_27 ( V_101 ) ;
if ( V_114 ) {
F_8 ( L_4 ) ;
goto V_116;
}
if ( V_101 -> V_117 != V_118 ) {
V_114 = - V_119 ;
goto V_120;
}
F_16 ( V_101 ) ;
V_3 . V_30 = 0 ;
V_101 -> V_117 = V_121 ;
F_28 ( & V_3 . V_115 ) ;
return 0 ;
V_120:
F_29 ( V_101 ) ;
V_116:
F_28 ( & V_3 . V_115 ) ;
return V_114 ;
}
static void F_30 ( struct V_100 * V_101 )
{
F_6 ( L_5 ) ;
F_26 ( & V_3 . V_115 ) ;
if ( V_101 -> V_117 == V_118 )
goto V_122;
if ( V_101 -> V_117 == V_123 ) {
V_101 -> V_117 = V_118 ;
goto V_122;
}
F_21 ( V_101 ) ;
V_101 -> V_117 = V_118 ;
F_29 ( V_101 ) ;
V_122:
F_28 ( & V_3 . V_115 ) ;
}
static int F_31 ( struct V_100 * V_101 )
{
F_30 ( V_101 ) ;
return 0 ;
}
static int F_32 ( struct V_100 * V_101 )
{
return F_25 ( V_101 ) ;
}
static enum V_124 F_33 (
struct V_100 * V_101 )
{
return V_125 ;
}
static int F_34 ( struct V_100 * V_101 ,
enum V_124 V_126 )
{
if ( V_126 != V_125 )
return - V_119 ;
return 0 ;
}
static void F_35 ( struct V_100 * V_101 ,
struct V_94 * V_95 )
{
* V_95 = V_101 -> V_102 . V_95 ;
}
static void F_36 ( struct V_100 * V_101 ,
struct V_94 * V_95 )
{
F_6 ( L_6 ) ;
if ( memcmp ( & V_101 -> V_102 . V_95 , V_95 , sizeof( * V_95 ) ) )
V_3 . V_30 = 0 ;
V_101 -> V_102 . V_95 = * V_95 ;
if ( V_101 -> V_117 == V_121 ) {
F_30 ( V_101 ) ;
F_25 ( V_101 ) ;
}
}
static int F_37 ( struct V_100 * V_101 ,
struct V_94 * V_95 )
{
F_6 ( L_7 ) ;
if ( memcmp ( & V_96 , V_95 , sizeof( * V_95 ) ) == 0 )
return 0 ;
if ( memcmp ( & V_98 , V_95 , sizeof( * V_95 ) ) == 0 )
return 0 ;
return - V_119 ;
}
static T_1 F_38 ( struct V_100 * V_101 )
{
return ( V_3 . V_30 >> 8 ) ^ 0xfffff ;
}
static int F_39 ( struct V_100 * V_101 , T_1 V_127 )
{
const struct V_6 * V_7 ;
F_6 ( L_8 ) ;
F_26 ( & V_3 . V_115 ) ;
V_7 = F_14 ( & V_101 -> V_102 . V_95 ) ;
V_3 . V_30 = ( V_127 ^ 0xfffff ) << 8 ;
F_11 ( 1 ) ;
F_1 ( V_28 , V_7 -> V_29 |
V_3 . V_30 ) ;
F_11 ( 0 ) ;
F_28 ( & V_3 . V_115 ) ;
return 0 ;
}
int F_40 ( struct V_100 * V_101 )
{
F_6 ( L_9 ) ;
if ( V_3 . V_109 == NULL ) {
struct V_128 * V_129 ;
V_129 = F_41 ( & V_3 . V_130 -> V_131 , L_10 ) ;
if ( F_42 ( V_129 ) ) {
F_8 ( L_11 ) ;
return F_43 ( V_129 ) ;
}
V_3 . V_109 = V_129 ;
}
return 0 ;
}
void F_44 ( struct V_132 * V_133 )
{
#define F_45 ( V_114 ) seq_printf(s, "%-35s %08x\n", #r, venc_read_reg(r))
F_11 ( 1 ) ;
F_45 ( V_84 ) ;
F_45 ( V_66 ) ;
F_45 ( V_86 ) ;
F_45 ( V_8 ) ;
F_45 ( V_10 ) ;
F_45 ( V_68 ) ;
F_45 ( V_12 ) ;
F_45 ( V_14 ) ;
F_45 ( V_16 ) ;
F_45 ( V_18 ) ;
F_45 ( V_20 ) ;
F_45 ( V_22 ) ;
F_45 ( V_24 ) ;
F_45 ( V_70 ) ;
F_45 ( V_26 ) ;
F_45 ( V_28 ) ;
F_45 ( V_31 ) ;
F_45 ( V_72 ) ;
F_45 ( V_74 ) ;
F_45 ( V_33 ) ;
F_45 ( V_76 ) ;
F_45 ( V_35 ) ;
F_45 ( V_37 ) ;
F_45 ( V_39 ) ;
F_45 ( V_41 ) ;
F_45 ( V_43 ) ;
F_45 ( V_45 ) ;
F_45 ( V_47 ) ;
F_45 ( V_49 ) ;
F_45 ( V_51 ) ;
F_45 ( V_53 ) ;
F_45 ( V_55 ) ;
F_45 ( V_57 ) ;
F_45 ( V_59 ) ;
F_45 ( V_61 ) ;
F_45 ( V_63 ) ;
F_45 ( V_78 ) ;
F_45 ( V_80 ) ;
F_45 ( V_82 ) ;
F_45 ( V_106 ) ;
F_45 ( V_134 ) ;
F_11 ( 0 ) ;
#undef F_45
}
static int F_46 ( struct V_135 * V_130 )
{
T_2 V_136 ;
struct V_137 * V_138 ;
V_3 . V_130 = V_130 ;
F_47 ( & V_3 . V_115 ) ;
V_3 . V_30 = 0 ;
V_138 = F_48 ( V_3 . V_130 , V_139 , 0 ) ;
if ( ! V_138 ) {
F_8 ( L_12 ) ;
return - V_119 ;
}
V_3 . V_4 = F_49 ( V_138 -> V_140 , F_50 ( V_138 ) ) ;
if ( ! V_3 . V_4 ) {
F_8 ( L_13 ) ;
return - V_141 ;
}
F_11 ( 1 ) ;
V_136 = ( T_2 ) ( F_3 ( V_142 ) & 0xff ) ;
F_51 ( & V_130 -> V_131 , L_14 , V_136 ) ;
F_11 ( 0 ) ;
return F_52 ( & V_143 ) ;
}
static int F_53 ( struct V_135 * V_130 )
{
if ( V_3 . V_109 != NULL ) {
F_54 ( V_3 . V_109 ) ;
V_3 . V_109 = NULL ;
}
F_55 ( & V_143 ) ;
F_56 ( V_3 . V_4 ) ;
return 0 ;
}
int F_57 ( void )
{
if ( F_58 () )
return 0 ;
return F_59 ( & V_144 ) ;
}
void F_60 ( void )
{
if ( F_58 () )
return;
return F_61 ( & V_144 ) ;
}
