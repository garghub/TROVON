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
T_1 V_5 ;
int V_89 ;
F_7 () ;
F_5 ( F_16 ( & V_100 -> V_101 . V_94 ) ) ;
F_19 ( V_100 -> V_102 . V_3 . type ) ;
F_20 ( 1 ) ;
V_5 = 0 ;
if ( V_100 -> V_102 . V_3 . type == V_103 )
V_5 |= 1 << 1 ;
else
V_5 |= ( 1 << 0 ) | ( 1 << 2 ) ;
if ( V_100 -> V_102 . V_3 . V_104 == false )
V_5 |= 1 << 3 ;
F_1 ( V_105 , V_5 ) ;
F_21 ( V_100 -> V_106 , & V_100 -> V_101 . V_94 ) ;
V_89 = F_22 ( V_3 . V_107 ) ;
if ( V_89 )
goto V_108;
if ( V_100 -> V_109 )
V_100 -> V_109 ( V_100 ) ;
V_89 = F_23 ( V_100 -> V_106 ) ;
if ( V_89 )
goto V_108;
return 0 ;
V_108:
F_1 ( V_105 , 0 ) ;
F_20 ( 0 ) ;
if ( V_100 -> V_110 )
V_100 -> V_110 ( V_100 ) ;
F_24 ( V_3 . V_107 ) ;
return V_89 ;
}
static void F_25 ( struct V_99 * V_100 )
{
F_1 ( V_105 , 0 ) ;
F_20 ( 0 ) ;
F_26 ( V_100 -> V_106 ) ;
if ( V_100 -> V_110 )
V_100 -> V_110 ( V_100 ) ;
F_24 ( V_3 . V_107 ) ;
}
unsigned long F_27 ( void )
{
return 13500000 ;
}
static T_2 F_28 ( struct V_111 * V_91 ,
struct V_112 * V_113 , char * V_114 )
{
struct V_99 * V_100 = F_29 ( V_91 ) ;
const char * V_115 ;
switch ( V_100 -> V_102 . V_3 . type ) {
case V_103 :
V_115 = L_5 ;
break;
case V_116 :
V_115 = L_6 ;
break;
default:
return - V_117 ;
}
return snprintf ( V_114 , V_118 , L_7 , V_115 ) ;
}
static T_2 F_30 ( struct V_111 * V_91 ,
struct V_112 * V_113 , const char * V_114 , T_3 V_119 )
{
struct V_99 * V_100 = F_29 ( V_91 ) ;
enum V_120 V_121 ;
if ( F_31 ( L_5 , V_114 ) )
V_121 = V_103 ;
else if ( F_31 ( L_6 , V_114 ) )
V_121 = V_116 ;
else
return - V_117 ;
F_32 ( & V_3 . V_122 ) ;
if ( V_100 -> V_102 . V_3 . type != V_121 ) {
V_100 -> V_102 . V_3 . type = V_121 ;
if ( V_100 -> V_123 == V_124 ) {
F_25 ( V_100 ) ;
F_18 ( V_100 ) ;
}
}
F_33 ( & V_3 . V_122 ) ;
return V_119 ;
}
static int F_34 ( struct V_99 * V_100 )
{
V_100 -> V_101 . V_94 = V_95 ;
return F_35 ( & V_100 -> V_91 , & V_125 ) ;
}
static void F_36 ( struct V_99 * V_100 )
{
F_37 ( & V_100 -> V_91 , & V_125 ) ;
}
static int F_38 ( struct V_99 * V_100 )
{
int V_89 = 0 ;
F_6 ( L_8 ) ;
F_32 ( & V_3 . V_122 ) ;
V_89 = F_39 ( V_100 ) ;
if ( V_89 ) {
F_8 ( L_9 ) ;
goto V_126;
}
if ( V_100 -> V_123 != V_127 ) {
V_89 = - V_117 ;
goto V_128;
}
V_89 = F_11 () ;
if ( V_89 )
goto V_128;
V_89 = F_18 ( V_100 ) ;
if ( V_89 )
goto V_129;
V_3 . V_30 = 0 ;
V_100 -> V_123 = V_124 ;
F_33 ( & V_3 . V_122 ) ;
return 0 ;
V_129:
F_14 () ;
V_128:
F_40 ( V_100 ) ;
V_126:
F_33 ( & V_3 . V_122 ) ;
return V_89 ;
}
static void F_41 ( struct V_99 * V_100 )
{
F_6 ( L_10 ) ;
F_32 ( & V_3 . V_122 ) ;
if ( V_100 -> V_123 == V_127 )
goto V_130;
if ( V_100 -> V_123 == V_131 ) {
V_100 -> V_123 = V_127 ;
goto V_130;
}
F_25 ( V_100 ) ;
F_14 () ;
V_100 -> V_123 = V_127 ;
F_40 ( V_100 ) ;
V_130:
F_33 ( & V_3 . V_122 ) ;
}
static int F_42 ( struct V_99 * V_100 )
{
F_41 ( V_100 ) ;
return 0 ;
}
static int F_43 ( struct V_99 * V_100 )
{
return F_38 ( V_100 ) ;
}
static void F_44 ( struct V_99 * V_100 ,
struct V_93 * V_94 )
{
F_6 ( L_11 ) ;
if ( memcmp ( & V_100 -> V_101 . V_94 , V_94 , sizeof( * V_94 ) ) )
V_3 . V_30 = 0 ;
V_100 -> V_101 . V_94 = * V_94 ;
if ( V_100 -> V_123 == V_124 ) {
F_41 ( V_100 ) ;
F_38 ( V_100 ) ;
} else {
F_21 ( V_100 -> V_106 , V_94 ) ;
}
}
static int F_45 ( struct V_99 * V_100 ,
struct V_93 * V_94 )
{
F_6 ( L_12 ) ;
if ( memcmp ( & V_95 , V_94 , sizeof( * V_94 ) ) == 0 )
return 0 ;
if ( memcmp ( & V_97 , V_94 , sizeof( * V_94 ) ) == 0 )
return 0 ;
return - V_117 ;
}
static T_1 F_46 ( struct V_99 * V_100 )
{
return ( V_3 . V_30 >> 8 ) ^ 0xfffff ;
}
static int F_47 ( struct V_99 * V_100 , T_1 V_132 )
{
const struct V_6 * V_7 ;
int V_89 ;
F_6 ( L_13 ) ;
F_32 ( & V_3 . V_122 ) ;
V_7 = F_16 ( & V_100 -> V_101 . V_94 ) ;
V_3 . V_30 = ( V_132 ^ 0xfffff ) << 8 ;
V_89 = F_11 () ;
if ( V_89 )
goto V_108;
F_1 ( V_28 , V_7 -> V_29 |
V_3 . V_30 ) ;
F_14 () ;
V_108:
F_33 ( & V_3 . V_122 ) ;
return V_89 ;
}
static int T_4 F_48 ( struct V_99 * V_100 )
{
F_6 ( L_14 ) ;
if ( V_3 . V_107 == NULL ) {
struct V_133 * V_134 ;
V_134 = F_49 ( & V_3 . V_90 -> V_91 , L_15 ) ;
if ( F_50 ( V_134 ) ) {
F_8 ( L_16 ) ;
return F_51 ( V_134 ) ;
}
V_3 . V_107 = V_134 ;
}
return 0 ;
}
static void F_52 ( struct V_135 * V_136 )
{
#define F_53 ( V_89 ) seq_printf(s, "%-35s %08x\n", #r, venc_read_reg(r))
if ( F_54 () ) {
F_55 ( V_136 , L_17 ) ;
return;
}
if ( F_11 () )
return;
F_53 ( V_84 ) ;
F_53 ( V_66 ) ;
F_53 ( V_86 ) ;
F_53 ( V_8 ) ;
F_53 ( V_10 ) ;
F_53 ( V_68 ) ;
F_53 ( V_12 ) ;
F_53 ( V_14 ) ;
F_53 ( V_16 ) ;
F_53 ( V_18 ) ;
F_53 ( V_20 ) ;
F_53 ( V_22 ) ;
F_53 ( V_24 ) ;
F_53 ( V_70 ) ;
F_53 ( V_26 ) ;
F_53 ( V_28 ) ;
F_53 ( V_31 ) ;
F_53 ( V_72 ) ;
F_53 ( V_74 ) ;
F_53 ( V_33 ) ;
F_53 ( V_76 ) ;
F_53 ( V_35 ) ;
F_53 ( V_37 ) ;
F_53 ( V_39 ) ;
F_53 ( V_41 ) ;
F_53 ( V_43 ) ;
F_53 ( V_45 ) ;
F_53 ( V_47 ) ;
F_53 ( V_49 ) ;
F_53 ( V_51 ) ;
F_53 ( V_53 ) ;
F_53 ( V_55 ) ;
F_53 ( V_57 ) ;
F_53 ( V_59 ) ;
F_53 ( V_61 ) ;
F_53 ( V_63 ) ;
F_53 ( V_78 ) ;
F_53 ( V_80 ) ;
F_53 ( V_82 ) ;
F_53 ( V_105 ) ;
F_53 ( V_137 ) ;
F_14 () ;
#undef F_53
}
static int F_56 ( struct V_138 * V_90 )
{
struct V_139 * V_139 ;
if ( F_57 ( V_140 ) ) {
V_139 = F_58 ( & V_90 -> V_91 , L_18 ) ;
if ( F_50 ( V_139 ) ) {
F_8 ( L_19 ) ;
return F_51 ( V_139 ) ;
}
} else {
V_139 = NULL ;
}
V_3 . V_141 = V_139 ;
return 0 ;
}
static void F_59 ( void )
{
if ( V_3 . V_141 )
F_60 ( V_3 . V_141 ) ;
}
static void T_4 F_61 ( struct V_138 * V_90 )
{
struct V_142 * V_143 = V_90 -> V_91 . V_144 ;
int V_89 , V_145 ;
for ( V_145 = 0 ; V_145 < V_143 -> V_146 ; ++ V_145 ) {
struct V_99 * V_100 = V_143 -> V_147 [ V_145 ] ;
if ( V_100 -> type != V_148 )
continue;
V_89 = F_48 ( V_100 ) ;
if ( V_89 ) {
F_8 ( L_20 , V_100 -> V_149 , V_89 ) ;
continue;
}
V_89 = F_62 ( V_100 , & V_90 -> V_91 , V_145 ) ;
if ( V_89 )
F_8 ( L_21 ,
V_100 -> V_149 , V_89 ) ;
}
}
static int T_4 F_63 ( struct V_138 * V_90 )
{
T_5 V_150 ;
struct V_151 * V_152 ;
int V_89 ;
V_3 . V_90 = V_90 ;
F_64 ( & V_3 . V_122 ) ;
V_3 . V_30 = 0 ;
V_152 = F_65 ( V_3 . V_90 , V_153 , 0 ) ;
if ( ! V_152 ) {
F_8 ( L_22 ) ;
return - V_117 ;
}
V_3 . V_4 = F_66 ( & V_90 -> V_91 , V_152 -> V_154 ,
F_67 ( V_152 ) ) ;
if ( ! V_3 . V_4 ) {
F_8 ( L_23 ) ;
return - V_155 ;
}
V_89 = F_56 ( V_90 ) ;
if ( V_89 )
return V_89 ;
F_68 ( & V_90 -> V_91 ) ;
V_89 = F_11 () ;
if ( V_89 )
goto V_156;
V_150 = ( T_5 ) ( F_3 ( V_157 ) & 0xff ) ;
F_69 ( & V_90 -> V_91 , L_24 , V_150 ) ;
F_14 () ;
V_89 = F_70 ( & V_158 ) ;
if ( V_89 )
goto V_159;
F_71 ( L_25 , F_52 ) ;
F_61 ( V_90 ) ;
return 0 ;
V_159:
V_156:
F_72 ( & V_90 -> V_91 ) ;
F_59 () ;
return V_89 ;
}
static int T_6 F_73 ( struct V_138 * V_90 )
{
F_74 ( & V_90 -> V_91 ) ;
if ( V_3 . V_107 != NULL ) {
F_75 ( V_3 . V_107 ) ;
V_3 . V_107 = NULL ;
}
F_76 ( & V_158 ) ;
F_72 ( & V_90 -> V_91 ) ;
F_59 () ;
return 0 ;
}
static int F_77 ( struct V_111 * V_91 )
{
if ( V_3 . V_141 )
F_78 ( V_3 . V_141 ) ;
F_79 () ;
return 0 ;
}
static int F_80 ( struct V_111 * V_91 )
{
int V_89 ;
V_89 = F_81 () ;
if ( V_89 < 0 )
return V_89 ;
if ( V_3 . V_141 )
F_82 ( V_3 . V_141 ) ;
return 0 ;
}
int T_4 F_83 ( void )
{
if ( F_54 () )
return 0 ;
return F_84 ( & V_160 , F_63 ) ;
}
void T_6 F_85 ( void )
{
if ( F_54 () )
return;
F_86 ( & V_160 ) ;
}
