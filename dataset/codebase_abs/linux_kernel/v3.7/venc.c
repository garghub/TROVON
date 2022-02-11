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
F_13 ( V_89 < 0 && V_89 != - V_92 ) ;
}
static const struct V_6 * F_16 (
struct V_93 * V_94 )
{
if ( memcmp ( & V_95 , V_94 , sizeof( * V_94 ) ) == 0 )
return & V_96 ;
if ( memcmp ( & V_97 , V_94 , sizeof( * V_94 ) ) == 0 )
return & V_98 ;
F_17 () ;
return NULL ;
}
static int F_18 ( struct V_99 * V_100 )
{
struct V_101 * V_102 = V_100 -> V_103 -> V_104 ;
T_1 V_5 ;
int V_89 ;
V_89 = F_11 () ;
if ( V_89 )
goto V_105;
F_7 () ;
F_5 ( F_16 ( & V_3 . V_94 ) ) ;
F_19 ( V_3 . type ) ;
F_20 ( 1 ) ;
V_5 = 0 ;
if ( V_3 . type == V_106 )
V_5 |= 1 << 1 ;
else
V_5 |= ( 1 << 0 ) | ( 1 << 2 ) ;
if ( V_3 . V_107 == false )
V_5 |= 1 << 3 ;
F_1 ( V_108 , V_5 ) ;
F_21 ( V_102 , & V_3 . V_94 ) ;
V_89 = F_22 ( V_3 . V_109 ) ;
if ( V_89 )
goto V_110;
V_89 = F_23 ( V_102 ) ;
if ( V_89 )
goto V_111;
return 0 ;
V_111:
F_24 ( V_3 . V_109 ) ;
V_110:
F_1 ( V_108 , 0 ) ;
F_20 ( 0 ) ;
F_14 () ;
V_105:
return V_89 ;
}
static void F_25 ( struct V_99 * V_100 )
{
struct V_101 * V_102 = V_100 -> V_103 -> V_104 ;
F_1 ( V_108 , 0 ) ;
F_20 ( 0 ) ;
F_26 ( V_102 ) ;
F_24 ( V_3 . V_109 ) ;
F_14 () ;
}
unsigned long F_27 ( void )
{
return 13500000 ;
}
int F_28 ( struct V_99 * V_100 )
{
struct V_112 * V_113 = V_100 -> V_103 ;
int V_89 ;
F_6 ( L_5 ) ;
F_29 ( & V_3 . V_114 ) ;
if ( V_113 == NULL || V_113 -> V_104 == NULL ) {
F_8 ( L_6 ) ;
V_89 = - V_115 ;
goto V_105;
}
V_89 = F_30 ( V_100 ) ;
if ( V_89 ) {
F_8 ( L_7 ) ;
goto V_105;
}
if ( V_100 -> V_116 )
V_100 -> V_116 ( V_100 ) ;
V_89 = F_18 ( V_100 ) ;
if ( V_89 )
goto V_110;
V_3 . V_30 = 0 ;
F_31 ( & V_3 . V_114 ) ;
return 0 ;
V_110:
if ( V_100 -> V_117 )
V_100 -> V_117 ( V_100 ) ;
F_32 ( V_100 ) ;
V_105:
F_31 ( & V_3 . V_114 ) ;
return V_89 ;
}
void F_33 ( struct V_99 * V_100 )
{
F_6 ( L_8 ) ;
F_29 ( & V_3 . V_114 ) ;
F_25 ( V_100 ) ;
F_32 ( V_100 ) ;
if ( V_100 -> V_117 )
V_100 -> V_117 ( V_100 ) ;
F_31 ( & V_3 . V_114 ) ;
}
void F_34 ( struct V_99 * V_100 ,
struct V_93 * V_94 )
{
F_6 ( L_9 ) ;
F_29 ( & V_3 . V_114 ) ;
if ( memcmp ( & V_3 . V_94 , V_94 , sizeof( * V_94 ) ) )
V_3 . V_30 = 0 ;
V_3 . V_94 = * V_94 ;
F_31 ( & V_3 . V_114 ) ;
}
int F_35 ( struct V_99 * V_100 ,
struct V_93 * V_94 )
{
F_6 ( L_10 ) ;
if ( memcmp ( & V_95 , V_94 , sizeof( * V_94 ) ) == 0 )
return 0 ;
if ( memcmp ( & V_97 , V_94 , sizeof( * V_94 ) ) == 0 )
return 0 ;
return - V_118 ;
}
T_1 F_36 ( struct V_99 * V_100 )
{
return ( V_3 . V_30 >> 8 ) ^ 0xfffff ;
}
int F_37 ( struct V_99 * V_100 , T_1 V_119 )
{
const struct V_6 * V_7 ;
int V_89 ;
F_6 ( L_11 ) ;
F_29 ( & V_3 . V_114 ) ;
V_7 = F_16 ( & V_3 . V_94 ) ;
V_3 . V_30 = ( V_119 ^ 0xfffff ) << 8 ;
V_89 = F_11 () ;
if ( V_89 )
goto V_120;
F_1 ( V_28 , V_7 -> V_29 |
V_3 . V_30 ) ;
F_14 () ;
V_120:
F_31 ( & V_3 . V_114 ) ;
return V_89 ;
}
void F_38 ( struct V_99 * V_100 ,
enum V_121 type )
{
F_29 ( & V_3 . V_114 ) ;
V_3 . type = type ;
F_31 ( & V_3 . V_114 ) ;
}
void F_39 ( struct V_99 * V_100 ,
bool V_107 )
{
F_29 ( & V_3 . V_114 ) ;
V_3 . V_107 = V_107 ;
F_31 ( & V_3 . V_114 ) ;
}
static int T_2 F_40 ( struct V_99 * V_100 )
{
F_6 ( L_12 ) ;
if ( V_3 . V_109 == NULL ) {
struct V_122 * V_123 ;
V_123 = F_41 ( & V_3 . V_90 -> V_91 , L_13 ) ;
if ( F_42 ( V_123 ) ) {
F_8 ( L_14 ) ;
return F_43 ( V_123 ) ;
}
V_3 . V_109 = V_123 ;
}
return 0 ;
}
static void F_44 ( struct V_124 * V_125 )
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
F_45 ( V_108 ) ;
F_45 ( V_126 ) ;
F_14 () ;
#undef F_45
}
static int F_46 ( struct V_127 * V_90 )
{
struct V_128 * V_128 ;
if ( F_47 ( V_129 ) ) {
V_128 = F_48 ( & V_90 -> V_91 , L_15 ) ;
if ( F_42 ( V_128 ) ) {
F_8 ( L_16 ) ;
return F_43 ( V_128 ) ;
}
} else {
V_128 = NULL ;
}
V_3 . V_130 = V_128 ;
return 0 ;
}
static void F_49 ( void )
{
if ( V_3 . V_130 )
F_50 ( V_3 . V_130 ) ;
}
static struct V_99 * T_2 F_51 ( struct V_127 * V_90 )
{
struct V_131 * V_132 = V_90 -> V_91 . V_133 ;
const char * V_134 = F_52 () ;
struct V_99 * V_135 ;
int V_136 ;
V_135 = NULL ;
for ( V_136 = 0 ; V_136 < V_132 -> V_137 ; ++ V_136 ) {
struct V_99 * V_100 = V_132 -> V_138 [ V_136 ] ;
if ( V_100 -> type != V_139 )
continue;
if ( V_135 == NULL )
V_135 = V_100 ;
if ( V_134 != NULL &&
strcmp ( V_100 -> V_140 , V_134 ) == 0 ) {
V_135 = V_100 ;
break;
}
}
return V_135 ;
}
static void T_2 F_53 ( struct V_127 * V_141 )
{
struct V_99 * V_142 ;
struct V_99 * V_100 ;
int V_89 ;
V_142 = F_51 ( V_141 ) ;
if ( ! V_142 )
return;
V_100 = F_54 ( & V_141 -> V_91 ) ;
if ( ! V_100 )
return;
F_55 ( V_100 , V_142 ) ;
V_100 -> V_143 = V_144 ;
V_89 = F_40 ( V_100 ) ;
if ( V_89 ) {
F_8 ( L_17 , V_100 -> V_140 , V_89 ) ;
F_56 ( V_100 ) ;
return;
}
V_89 = F_57 ( V_100 ) ;
if ( V_89 ) {
F_8 ( L_18 , V_100 -> V_140 , V_89 ) ;
F_56 ( V_100 ) ;
return;
}
}
static void T_2 F_58 ( struct V_127 * V_90 )
{
struct V_112 * V_113 = & V_3 . V_103 ;
V_113 -> V_90 = V_90 ;
V_113 -> V_145 = V_146 ;
V_113 -> type = V_139 ;
F_59 ( V_113 ) ;
}
static void T_3 F_60 ( struct V_127 * V_90 )
{
struct V_112 * V_113 = & V_3 . V_103 ;
F_61 ( V_113 ) ;
}
static int T_2 F_62 ( struct V_127 * V_90 )
{
T_4 V_147 ;
struct V_148 * V_149 ;
int V_89 ;
V_3 . V_90 = V_90 ;
F_63 ( & V_3 . V_114 ) ;
V_3 . V_30 = 0 ;
V_149 = F_64 ( V_3 . V_90 , V_150 , 0 ) ;
if ( ! V_149 ) {
F_8 ( L_19 ) ;
return - V_118 ;
}
V_3 . V_4 = F_65 ( & V_90 -> V_91 , V_149 -> V_151 ,
F_66 ( V_149 ) ) ;
if ( ! V_3 . V_4 ) {
F_8 ( L_20 ) ;
return - V_152 ;
}
V_89 = F_46 ( V_90 ) ;
if ( V_89 )
return V_89 ;
F_67 ( & V_90 -> V_91 ) ;
V_89 = F_11 () ;
if ( V_89 )
goto V_153;
V_147 = ( T_4 ) ( F_3 ( V_154 ) & 0xff ) ;
F_68 ( & V_90 -> V_91 , L_21 , V_147 ) ;
F_14 () ;
V_89 = F_69 () ;
if ( V_89 )
goto V_155;
F_70 ( L_22 , F_44 ) ;
F_58 ( V_90 ) ;
F_53 ( V_90 ) ;
return 0 ;
V_155:
V_153:
F_71 ( & V_90 -> V_91 ) ;
F_49 () ;
return V_89 ;
}
static int T_3 F_72 ( struct V_127 * V_90 )
{
F_73 ( & V_90 -> V_91 ) ;
if ( V_3 . V_109 != NULL ) {
F_74 ( V_3 . V_109 ) ;
V_3 . V_109 = NULL ;
}
F_75 () ;
F_60 ( V_90 ) ;
F_71 ( & V_90 -> V_91 ) ;
F_49 () ;
return 0 ;
}
static int F_76 ( struct V_156 * V_91 )
{
if ( V_3 . V_130 )
F_77 ( V_3 . V_130 ) ;
F_78 () ;
return 0 ;
}
static int F_79 ( struct V_156 * V_91 )
{
int V_89 ;
V_89 = F_80 () ;
if ( V_89 < 0 )
return V_89 ;
if ( V_3 . V_130 )
F_81 ( V_3 . V_130 ) ;
return 0 ;
}
int T_2 F_82 ( void )
{
return F_83 ( & V_157 , F_62 ) ;
}
void T_3 F_84 ( void )
{
F_85 ( & V_157 ) ;
}
