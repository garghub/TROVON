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
struct V_101 * V_102 = V_3 . V_103 . V_104 ;
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
struct V_101 * V_102 = V_3 . V_103 . V_104 ;
F_1 ( V_108 , 0 ) ;
F_20 ( 0 ) ;
F_26 ( V_102 ) ;
F_24 ( V_3 . V_109 ) ;
F_14 () ;
}
static int F_27 ( struct V_99 * V_100 )
{
struct V_99 * V_112 = & V_3 . V_103 ;
int V_89 ;
F_6 ( L_5 ) ;
F_28 ( & V_3 . V_113 ) ;
if ( V_112 -> V_104 == NULL ) {
F_8 ( L_6 ) ;
V_89 = - V_114 ;
goto V_105;
}
V_89 = F_18 ( V_100 ) ;
if ( V_89 )
goto V_105;
V_3 . V_30 = 0 ;
F_29 ( & V_3 . V_113 ) ;
return 0 ;
V_105:
F_29 ( & V_3 . V_113 ) ;
return V_89 ;
}
static void F_30 ( struct V_99 * V_100 )
{
F_6 ( L_7 ) ;
F_28 ( & V_3 . V_113 ) ;
F_25 ( V_100 ) ;
F_29 ( & V_3 . V_113 ) ;
}
static void F_31 ( struct V_99 * V_100 ,
struct V_93 * V_94 )
{
F_6 ( L_8 ) ;
F_28 ( & V_3 . V_113 ) ;
if ( memcmp ( & V_3 . V_94 , V_94 , sizeof( * V_94 ) ) )
V_3 . V_30 = 0 ;
V_3 . V_94 = * V_94 ;
F_32 ( 13500000 ) ;
F_29 ( & V_3 . V_113 ) ;
}
static int F_33 ( struct V_99 * V_100 ,
struct V_93 * V_94 )
{
F_6 ( L_9 ) ;
if ( memcmp ( & V_95 , V_94 , sizeof( * V_94 ) ) == 0 )
return 0 ;
if ( memcmp ( & V_97 , V_94 , sizeof( * V_94 ) ) == 0 )
return 0 ;
return - V_115 ;
}
static void F_34 ( struct V_99 * V_100 ,
struct V_93 * V_94 )
{
F_28 ( & V_3 . V_113 ) ;
* V_94 = V_3 . V_94 ;
F_29 ( & V_3 . V_113 ) ;
}
static T_1 F_35 ( struct V_99 * V_100 )
{
return ( V_3 . V_30 >> 8 ) ^ 0xfffff ;
}
static int F_36 ( struct V_99 * V_100 , T_1 V_116 )
{
const struct V_6 * V_7 ;
int V_89 ;
F_6 ( L_10 ) ;
F_28 ( & V_3 . V_113 ) ;
V_7 = F_16 ( & V_3 . V_94 ) ;
V_3 . V_30 = ( V_116 ^ 0xfffff ) << 8 ;
V_89 = F_11 () ;
if ( V_89 )
goto V_117;
F_1 ( V_28 , V_7 -> V_29 |
V_3 . V_30 ) ;
F_14 () ;
V_117:
F_29 ( & V_3 . V_113 ) ;
return V_89 ;
}
static void F_37 ( struct V_99 * V_100 ,
enum V_118 type )
{
F_28 ( & V_3 . V_113 ) ;
V_3 . type = type ;
F_29 ( & V_3 . V_113 ) ;
}
static void F_38 ( struct V_99 * V_100 ,
bool V_107 )
{
F_28 ( & V_3 . V_113 ) ;
V_3 . V_107 = V_107 ;
F_29 ( & V_3 . V_113 ) ;
}
static int F_39 ( void )
{
struct V_119 * V_120 ;
if ( V_3 . V_109 != NULL )
return 0 ;
if ( V_3 . V_90 -> V_91 . V_121 )
V_120 = F_40 ( & V_3 . V_90 -> V_91 , L_11 ) ;
else
V_120 = F_40 ( & V_3 . V_90 -> V_91 , L_12 ) ;
if ( F_41 ( V_120 ) ) {
if ( F_42 ( V_120 ) != - V_122 )
F_8 ( L_13 ) ;
return F_42 ( V_120 ) ;
}
V_3 . V_109 = V_120 ;
return 0 ;
}
static void F_43 ( struct V_123 * V_124 )
{
#define F_44 ( V_89 ) seq_printf(s, "%-35s %08x\n", #r, venc_read_reg(r))
if ( F_11 () )
return;
F_44 ( V_84 ) ;
F_44 ( V_66 ) ;
F_44 ( V_86 ) ;
F_44 ( V_8 ) ;
F_44 ( V_10 ) ;
F_44 ( V_68 ) ;
F_44 ( V_12 ) ;
F_44 ( V_14 ) ;
F_44 ( V_16 ) ;
F_44 ( V_18 ) ;
F_44 ( V_20 ) ;
F_44 ( V_22 ) ;
F_44 ( V_24 ) ;
F_44 ( V_70 ) ;
F_44 ( V_26 ) ;
F_44 ( V_28 ) ;
F_44 ( V_31 ) ;
F_44 ( V_72 ) ;
F_44 ( V_74 ) ;
F_44 ( V_33 ) ;
F_44 ( V_76 ) ;
F_44 ( V_35 ) ;
F_44 ( V_37 ) ;
F_44 ( V_39 ) ;
F_44 ( V_41 ) ;
F_44 ( V_43 ) ;
F_44 ( V_45 ) ;
F_44 ( V_47 ) ;
F_44 ( V_49 ) ;
F_44 ( V_51 ) ;
F_44 ( V_53 ) ;
F_44 ( V_55 ) ;
F_44 ( V_57 ) ;
F_44 ( V_59 ) ;
F_44 ( V_61 ) ;
F_44 ( V_63 ) ;
F_44 ( V_78 ) ;
F_44 ( V_80 ) ;
F_44 ( V_82 ) ;
F_44 ( V_108 ) ;
F_44 ( V_125 ) ;
F_14 () ;
#undef F_44
}
static int F_45 ( struct V_126 * V_90 )
{
struct V_127 * V_127 ;
if ( F_46 ( V_128 ) ) {
V_127 = F_47 ( & V_90 -> V_91 , L_14 ) ;
if ( F_41 ( V_127 ) ) {
F_8 ( L_15 ) ;
return F_42 ( V_127 ) ;
}
} else {
V_127 = NULL ;
}
V_3 . V_129 = V_127 ;
return 0 ;
}
static int F_48 ( struct V_99 * V_100 ,
struct V_99 * V_130 )
{
struct V_101 * V_102 ;
int V_89 ;
V_89 = F_39 () ;
if ( V_89 )
return V_89 ;
V_102 = F_49 ( V_100 -> V_131 ) ;
if ( ! V_102 )
return - V_114 ;
V_89 = F_50 ( V_102 , V_100 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_51 ( V_100 , V_130 ) ;
if ( V_89 ) {
F_8 ( L_16 ,
V_130 -> V_132 ) ;
F_52 ( V_102 , V_100 ) ;
return V_89 ;
}
return 0 ;
}
static void F_53 ( struct V_99 * V_100 ,
struct V_99 * V_130 )
{
F_13 ( V_130 != V_100 -> V_130 ) ;
if ( V_130 != V_100 -> V_130 )
return;
F_54 ( V_100 ) ;
if ( V_100 -> V_104 )
F_52 ( V_100 -> V_104 , V_100 ) ;
}
static void F_55 ( struct V_126 * V_90 )
{
struct V_99 * V_112 = & V_3 . V_103 ;
V_112 -> V_91 = & V_90 -> V_91 ;
V_112 -> V_133 = V_134 ;
V_112 -> V_135 = V_136 ;
V_112 -> V_132 = L_17 ;
V_112 -> V_131 = V_137 ;
V_112 -> V_138 . V_139 = & V_140 ;
V_112 -> V_141 = V_142 ;
F_56 ( V_112 ) ;
}
static void F_57 ( struct V_126 * V_90 )
{
struct V_99 * V_112 = & V_3 . V_103 ;
F_58 ( V_112 ) ;
}
static int F_59 ( struct V_126 * V_90 )
{
struct V_143 * V_144 = V_90 -> V_91 . V_121 ;
struct V_143 * V_145 ;
T_1 V_146 ;
int V_89 ;
V_145 = F_60 ( V_144 ) ;
if ( ! V_145 )
return 0 ;
V_3 . V_107 = F_61 ( V_145 , L_18 ) ;
V_89 = F_62 ( V_145 , L_19 , & V_146 ) ;
if ( V_89 ) {
F_63 ( & V_90 -> V_91 ,
L_20 , V_89 ) ;
goto V_117;
}
switch ( V_146 ) {
case 1 :
V_3 . type = V_106 ;
break;
case 2 :
V_3 . type = V_147 ;
break;
default:
F_63 ( & V_90 -> V_91 , L_21 , V_146 ) ;
V_89 = - V_115 ;
goto V_117;
}
F_64 ( V_145 ) ;
return 0 ;
V_117:
F_64 ( V_145 ) ;
return 0 ;
}
static int F_65 ( struct V_148 * V_91 , struct V_148 * V_149 , void * V_150 )
{
struct V_126 * V_90 = F_66 ( V_91 ) ;
T_2 V_151 ;
struct V_152 * V_153 ;
int V_89 ;
V_3 . V_90 = V_90 ;
F_67 ( & V_3 . V_113 ) ;
V_3 . V_30 = 0 ;
V_153 = F_68 ( V_3 . V_90 , V_154 , 0 ) ;
if ( ! V_153 ) {
F_8 ( L_22 ) ;
return - V_115 ;
}
V_3 . V_4 = F_69 ( & V_90 -> V_91 , V_153 -> V_155 ,
F_70 ( V_153 ) ) ;
if ( ! V_3 . V_4 ) {
F_8 ( L_23 ) ;
return - V_156 ;
}
V_89 = F_45 ( V_90 ) ;
if ( V_89 )
return V_89 ;
F_71 ( & V_90 -> V_91 ) ;
V_89 = F_11 () ;
if ( V_89 )
goto V_157;
V_151 = ( T_2 ) ( F_3 ( V_158 ) & 0xff ) ;
F_72 ( & V_90 -> V_91 , L_24 , V_151 ) ;
F_14 () ;
if ( V_90 -> V_91 . V_121 ) {
V_89 = F_59 ( V_90 ) ;
if ( V_89 ) {
F_8 ( L_25 ) ;
goto V_159;
}
}
F_73 ( L_26 , F_43 ) ;
F_55 ( V_90 ) ;
return 0 ;
V_159:
V_157:
F_74 ( & V_90 -> V_91 ) ;
return V_89 ;
}
static void F_75 ( struct V_148 * V_91 , struct V_148 * V_149 , void * V_150 )
{
struct V_126 * V_90 = F_66 ( V_91 ) ;
F_57 ( V_90 ) ;
F_74 ( & V_90 -> V_91 ) ;
}
static int F_76 ( struct V_126 * V_90 )
{
return F_77 ( & V_90 -> V_91 , & V_160 ) ;
}
static int F_78 ( struct V_126 * V_90 )
{
F_79 ( & V_90 -> V_91 , & V_160 ) ;
return 0 ;
}
static int F_80 ( struct V_148 * V_91 )
{
if ( V_3 . V_129 )
F_81 ( V_3 . V_129 ) ;
F_82 () ;
return 0 ;
}
static int F_83 ( struct V_148 * V_91 )
{
int V_89 ;
V_89 = F_84 () ;
if ( V_89 < 0 )
return V_89 ;
if ( V_3 . V_129 )
F_85 ( V_3 . V_129 ) ;
return 0 ;
}
int T_3 F_86 ( void )
{
return F_87 ( & V_161 ) ;
}
void F_88 ( void )
{
F_89 ( & V_161 ) ;
}
