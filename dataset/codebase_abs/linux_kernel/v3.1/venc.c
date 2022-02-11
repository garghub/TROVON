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
static int F_11 ( void )
{
int V_89 ;
F_6 ( L_3 ) ;
V_89 = F_12 ( & V_3 . V_90 -> V_91 ) ;
F_13 ( V_89 < 0 ) ;
return V_89 < 0 ? V_89 : 0 ;
}
static void F_14 ( void )
{
int V_89 ;
F_6 ( L_4 ) ;
V_89 = F_15 ( & V_3 . V_90 -> V_91 ) ;
F_13 ( V_89 < 0 ) ;
}
static const struct V_6 * F_16 (
struct V_92 * V_93 )
{
if ( memcmp ( & V_94 , V_93 , sizeof( * V_93 ) ) == 0 )
return & V_95 ;
if ( memcmp ( & V_96 , V_93 , sizeof( * V_93 ) ) == 0 )
return & V_97 ;
F_17 () ;
}
static void F_18 ( struct V_98 * V_99 )
{
T_1 V_5 ;
F_7 () ;
F_5 ( F_16 ( & V_99 -> V_100 . V_93 ) ) ;
F_19 ( V_99 -> V_101 . V_3 . type ) ;
F_20 ( 1 ) ;
V_5 = 0 ;
if ( V_99 -> V_101 . V_3 . type == V_102 )
V_5 |= 1 << 1 ;
else
V_5 |= ( 1 << 0 ) | ( 1 << 2 ) ;
if ( V_99 -> V_101 . V_3 . V_103 == false )
V_5 |= 1 << 3 ;
F_1 ( V_104 , V_5 ) ;
F_21 ( V_99 -> V_100 . V_93 . V_105 ,
V_99 -> V_100 . V_93 . V_106 / 2 ) ;
F_22 ( V_3 . V_107 ) ;
if ( V_99 -> V_108 )
V_99 -> V_108 ( V_99 ) ;
V_99 -> V_109 -> V_110 ( V_99 -> V_109 ) ;
}
static void F_23 ( struct V_98 * V_99 )
{
F_1 ( V_104 , 0 ) ;
F_20 ( 0 ) ;
V_99 -> V_109 -> V_111 ( V_99 -> V_109 ) ;
if ( V_99 -> V_112 )
V_99 -> V_112 ( V_99 ) ;
F_24 ( V_3 . V_107 ) ;
}
static int F_25 ( struct V_98 * V_99 )
{
V_99 -> V_100 . V_93 = V_94 ;
return 0 ;
}
static void F_26 ( struct V_98 * V_99 )
{
}
static int F_27 ( struct V_98 * V_99 )
{
int V_89 = 0 ;
F_6 ( L_5 ) ;
F_28 ( & V_3 . V_113 ) ;
V_89 = F_29 ( V_99 ) ;
if ( V_89 ) {
F_8 ( L_6 ) ;
goto V_114;
}
if ( V_99 -> V_115 != V_116 ) {
V_89 = - V_117 ;
goto V_118;
}
V_89 = F_11 () ;
if ( V_89 )
goto V_118;
F_18 ( V_99 ) ;
V_3 . V_30 = 0 ;
V_99 -> V_115 = V_119 ;
F_30 ( & V_3 . V_113 ) ;
return 0 ;
V_118:
F_31 ( V_99 ) ;
V_114:
F_30 ( & V_3 . V_113 ) ;
return V_89 ;
}
static void F_32 ( struct V_98 * V_99 )
{
F_6 ( L_7 ) ;
F_28 ( & V_3 . V_113 ) ;
if ( V_99 -> V_115 == V_116 )
goto V_120;
if ( V_99 -> V_115 == V_121 ) {
V_99 -> V_115 = V_116 ;
goto V_120;
}
F_23 ( V_99 ) ;
F_14 () ;
V_99 -> V_115 = V_116 ;
F_31 ( V_99 ) ;
V_120:
F_30 ( & V_3 . V_113 ) ;
}
static int F_33 ( struct V_98 * V_99 )
{
F_32 ( V_99 ) ;
return 0 ;
}
static int F_34 ( struct V_98 * V_99 )
{
return F_27 ( V_99 ) ;
}
static void F_35 ( struct V_98 * V_99 ,
struct V_92 * V_93 )
{
* V_93 = V_99 -> V_100 . V_93 ;
}
static void F_36 ( struct V_98 * V_99 ,
struct V_92 * V_93 )
{
F_6 ( L_8 ) ;
if ( memcmp ( & V_99 -> V_100 . V_93 , V_93 , sizeof( * V_93 ) ) )
V_3 . V_30 = 0 ;
V_99 -> V_100 . V_93 = * V_93 ;
if ( V_99 -> V_115 == V_119 ) {
F_32 ( V_99 ) ;
F_27 ( V_99 ) ;
}
}
static int F_37 ( struct V_98 * V_99 ,
struct V_92 * V_93 )
{
F_6 ( L_9 ) ;
if ( memcmp ( & V_94 , V_93 , sizeof( * V_93 ) ) == 0 )
return 0 ;
if ( memcmp ( & V_96 , V_93 , sizeof( * V_93 ) ) == 0 )
return 0 ;
return - V_117 ;
}
static T_1 F_38 ( struct V_98 * V_99 )
{
return ( V_3 . V_30 >> 8 ) ^ 0xfffff ;
}
static int F_39 ( struct V_98 * V_99 , T_1 V_122 )
{
const struct V_6 * V_7 ;
int V_89 ;
F_6 ( L_10 ) ;
F_28 ( & V_3 . V_113 ) ;
V_7 = F_16 ( & V_99 -> V_100 . V_93 ) ;
V_3 . V_30 = ( V_122 ^ 0xfffff ) << 8 ;
V_89 = F_11 () ;
if ( V_89 )
goto V_123;
F_1 ( V_28 , V_7 -> V_29 |
V_3 . V_30 ) ;
F_14 () ;
V_123:
F_30 ( & V_3 . V_113 ) ;
return V_89 ;
}
int F_40 ( struct V_98 * V_99 )
{
F_6 ( L_11 ) ;
if ( V_3 . V_107 == NULL ) {
struct V_124 * V_125 ;
V_125 = F_41 ( & V_3 . V_90 -> V_91 , L_12 ) ;
if ( F_42 ( V_125 ) ) {
F_8 ( L_13 ) ;
return F_43 ( V_125 ) ;
}
V_3 . V_107 = V_125 ;
}
return 0 ;
}
void F_44 ( struct V_126 * V_127 )
{
#define F_45 ( V_89 ) seq_printf(s, "%-35s %08x\n", #r, venc_read_reg(r))
if ( F_11 () )
return;
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
F_45 ( V_104 ) ;
F_45 ( V_128 ) ;
F_14 () ;
#undef F_45
}
static int F_46 ( struct V_129 * V_90 )
{
struct V_130 * V_130 ;
V_130 = F_47 ( & V_90 -> V_91 , L_14 ) ;
if ( F_42 ( V_130 ) ) {
F_8 ( L_15 ) ;
return F_43 ( V_130 ) ;
}
V_3 . V_131 = V_130 ;
if ( F_48 ( V_132 ) ) {
if ( F_49 () || F_50 () )
V_130 = F_47 ( & V_90 -> V_91 , L_16 ) ;
else
V_130 = F_47 ( & V_90 -> V_91 , L_17 ) ;
if ( F_42 ( V_130 ) ) {
F_8 ( L_18 ) ;
F_51 ( V_3 . V_131 ) ;
return F_43 ( V_130 ) ;
}
} else {
V_130 = NULL ;
}
V_3 . V_133 = V_130 ;
return 0 ;
}
static void F_52 ( void )
{
if ( V_3 . V_131 )
F_51 ( V_3 . V_131 ) ;
if ( V_3 . V_133 )
F_51 ( V_3 . V_133 ) ;
}
static int F_53 ( struct V_129 * V_90 )
{
T_2 V_134 ;
struct V_135 * V_136 ;
int V_89 ;
V_3 . V_90 = V_90 ;
F_54 ( & V_3 . V_113 ) ;
V_3 . V_30 = 0 ;
V_136 = F_55 ( V_3 . V_90 , V_137 , 0 ) ;
if ( ! V_136 ) {
F_8 ( L_19 ) ;
V_89 = - V_117 ;
goto V_138;
}
V_3 . V_4 = F_56 ( V_136 -> V_139 , F_57 ( V_136 ) ) ;
if ( ! V_3 . V_4 ) {
F_8 ( L_20 ) ;
V_89 = - V_140 ;
goto V_138;
}
V_89 = F_46 ( V_90 ) ;
if ( V_89 )
goto V_141;
F_58 ( & V_90 -> V_91 ) ;
V_89 = F_11 () ;
if ( V_89 )
goto V_142;
V_134 = ( T_2 ) ( F_3 ( V_143 ) & 0xff ) ;
F_59 ( & V_90 -> V_91 , L_21 , V_134 ) ;
F_14 () ;
return F_60 ( & V_144 ) ;
V_142:
F_61 ( & V_90 -> V_91 ) ;
F_52 () ;
V_141:
F_62 ( V_3 . V_4 ) ;
V_138:
return V_89 ;
}
static int F_63 ( struct V_129 * V_90 )
{
if ( V_3 . V_107 != NULL ) {
F_64 ( V_3 . V_107 ) ;
V_3 . V_107 = NULL ;
}
F_65 ( & V_144 ) ;
F_61 ( & V_90 -> V_91 ) ;
F_52 () ;
F_62 ( V_3 . V_4 ) ;
return 0 ;
}
static int F_66 ( struct V_145 * V_91 )
{
if ( V_3 . V_133 )
F_67 ( V_3 . V_133 ) ;
F_67 ( V_3 . V_131 ) ;
F_68 () ;
F_69 () ;
return 0 ;
}
static int F_70 ( struct V_145 * V_91 )
{
int V_89 ;
V_89 = F_71 () ;
if ( V_89 < 0 )
goto V_146;
V_89 = F_72 () ;
if ( V_89 < 0 )
goto V_147;
F_73 ( V_3 . V_131 ) ;
if ( V_3 . V_133 )
F_73 ( V_3 . V_133 ) ;
return 0 ;
V_147:
F_69 () ;
V_146:
return V_89 ;
}
int F_74 ( void )
{
if ( F_75 () )
return 0 ;
return F_76 ( & V_148 ) ;
}
void F_77 ( void )
{
if ( F_75 () )
return;
return F_78 ( & V_148 ) ;
}
