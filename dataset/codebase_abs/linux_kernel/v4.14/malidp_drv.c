static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 [ V_4 ] )
{
int V_5 ;
const T_1 V_6 = F_2 ( 18 , 16 ) ;
F_3 ( V_2 , V_6 ,
V_2 -> V_7 . V_8 + V_9 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; ++ V_5 )
F_3 ( V_2 , V_3 [ V_5 ] ,
V_2 -> V_7 . V_8 +
V_10 ) ;
}
static void F_4 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_5 ( V_12 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
if ( ! V_12 -> V_18 -> V_19 )
return;
if ( ! V_12 -> V_18 -> V_20 ) {
F_6 ( V_2 ,
V_21 ,
V_22 ) ;
} else {
struct V_23 * V_24 =
F_7 ( V_12 -> V_18 ) ;
if ( ! V_14 -> V_20 || ( V_12 -> V_18 -> V_20 -> V_25 . V_26 !=
V_14 -> V_20 -> V_25 . V_26 ) )
F_1 ( V_2 , V_24 -> V_27 ) ;
F_8 ( V_2 , V_21 ,
V_22 ) ;
}
}
static
void F_9 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_5 ( V_12 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_5 ;
if ( ! V_12 -> V_18 -> V_19 )
return;
if ( ! V_12 -> V_18 -> V_28 ) {
F_6 ( V_2 , V_29 ,
V_22 ) ;
} else {
struct V_23 * V_24 =
F_7 ( V_12 -> V_18 ) ;
if ( ! V_14 -> V_28 || ( V_12 -> V_18 -> V_28 -> V_25 . V_26 !=
V_14 -> V_28 -> V_25 . V_26 ) )
for ( V_5 = 0 ; V_5 < V_30 ; ++ V_5 )
F_3 ( V_2 ,
V_24 -> V_31 [ V_5 ] ,
V_2 -> V_7 . V_8 +
V_32 + 4 * V_5 ) ;
F_8 ( V_2 , V_29 ,
V_22 ) ;
}
}
static void F_10 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_23 * V_33 = F_7 ( V_12 -> V_18 ) ;
struct V_23 * V_34 = F_7 ( V_14 ) ;
struct V_15 * V_16 = F_5 ( V_12 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_35 * V_36 = & V_33 -> V_37 ;
struct V_35 * V_38 = & V_34 -> V_37 ;
T_1 V_39 = V_2 -> V_7 . V_40 +
( ( V_2 -> V_7 . V_41 & V_42 ) ?
0x10 : 0xC ) ;
T_1 V_43 = V_39 + V_44 ;
T_1 V_45 = V_39 + V_46 ;
T_1 V_47 ;
if ( ! V_36 -> V_48 ) {
V_47 = F_11 ( V_2 , V_39 ) ;
V_47 &= ~ V_49 ;
F_3 ( V_2 , V_47 , V_39 ) ;
return;
}
V_2 -> V_50 ( V_2 , V_36 , V_38 ) ;
V_47 = F_11 ( V_2 , V_39 ) ;
V_47 |= V_49 | V_51 ;
V_47 &= ~ F_12 ( V_52 ) ;
V_47 |= V_36 -> V_53 ? F_12 ( 3 ) : 0 ;
V_47 |= V_54 ;
F_3 ( V_2 , V_47 , V_39 ) ;
V_47 = F_13 ( V_36 -> V_55 ) |
F_14 ( V_36 -> V_56 ) ;
F_3 ( V_2 , V_47 , V_43 + V_57 ) ;
V_47 = F_13 ( V_36 -> V_58 ) |
F_14 ( V_36 -> V_59 ) ;
F_3 ( V_2 , V_47 , V_43 + V_60 ) ;
F_3 ( V_2 , V_36 -> V_61 , V_45 + V_62 ) ;
F_3 ( V_2 , V_36 -> V_63 , V_45 + V_64 ) ;
F_3 ( V_2 , V_36 -> V_65 , V_45 + V_66 ) ;
F_3 ( V_2 , V_36 -> V_67 , V_45 + V_68 ) ;
}
static int F_15 ( struct V_69 * V_70 )
{
struct V_15 * V_16 = V_70 -> V_71 ;
struct V_1 * V_2 = V_16 -> V_17 ;
int V_72 ;
F_16 ( & V_16 -> V_73 , 0 ) ;
V_2 -> V_74 ( V_2 ) ;
if ( V_2 -> V_75 ( V_2 ) )
return 0 ;
V_72 = F_17 ( V_16 -> V_76 ,
F_18 ( & V_16 -> V_73 ) == 1 ,
F_19 ( V_77 ) ) ;
return ( V_72 > 0 ) ? 0 : - V_78 ;
}
static void F_20 ( struct V_69 * V_70 )
{
struct V_15 * V_16 = V_70 -> V_71 ;
F_21 ( V_16 -> V_79 ) ;
}
static void F_22 ( struct V_80 * V_18 )
{
struct V_81 * V_82 ;
struct V_69 * V_70 = V_18 -> V_17 ;
struct V_15 * V_16 = V_70 -> V_71 ;
if ( V_16 -> V_12 . V_83 ) {
if ( F_15 ( V_70 ) )
F_23 ( L_1 ) ;
}
V_82 = V_16 -> V_12 . V_18 -> V_82 ;
if ( V_82 ) {
V_16 -> V_12 . V_18 -> V_82 = NULL ;
F_24 ( & V_70 -> V_84 ) ;
if ( F_25 ( & V_16 -> V_12 ) == 0 )
F_26 ( & V_16 -> V_12 , V_82 ) ;
else
F_27 ( & V_16 -> V_12 , V_82 ) ;
F_28 ( & V_70 -> V_84 ) ;
}
F_29 ( V_18 ) ;
}
static void F_30 ( struct V_80 * V_18 )
{
struct V_69 * V_70 = V_18 -> V_17 ;
struct V_11 * V_12 ;
struct V_13 * V_85 ;
int V_5 ;
F_31 ( V_70 -> V_17 ) ;
F_32 ( V_70 , V_18 ) ;
F_33 (state, crtc, old_crtc_state, i) {
F_4 ( V_12 , V_85 ) ;
F_9 ( V_12 , V_85 ) ;
F_10 ( V_12 , V_85 ) ;
}
F_34 ( V_70 , V_18 , 0 ) ;
F_35 ( V_70 , V_18 ) ;
F_22 ( V_18 ) ;
F_36 ( V_70 , V_18 ) ;
F_37 ( V_70 -> V_17 ) ;
F_38 ( V_70 , V_18 ) ;
}
static int F_39 ( struct V_69 * V_70 )
{
int V_72 ;
struct V_15 * V_16 = V_70 -> V_71 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_40 ( V_70 ) ;
V_70 -> V_86 . V_87 = V_2 -> V_88 ;
V_70 -> V_86 . V_89 = V_2 -> V_88 ;
V_70 -> V_86 . V_90 = V_2 -> V_91 ;
V_70 -> V_86 . V_92 = V_2 -> V_91 ;
V_70 -> V_86 . V_93 = & V_94 ;
V_70 -> V_86 . V_95 = & V_96 ;
V_72 = F_41 ( V_70 ) ;
if ( V_72 ) {
F_42 ( V_70 ) ;
return V_72 ;
}
return 0 ;
}
static void F_43 ( struct V_69 * V_70 )
{
F_44 ( V_70 ) ;
F_42 ( V_70 ) ;
}
static int F_45 ( struct V_97 * V_98 )
{
int V_99 , V_100 , V_72 = 0 ;
struct V_69 * V_70 = F_46 ( & V_98 -> V_17 ) ;
V_99 = F_47 ( V_98 , L_2 ) ;
if ( V_99 < 0 ) {
F_48 ( L_3 ) ;
return V_99 ;
}
V_100 = F_47 ( V_98 , L_4 ) ;
if ( V_100 < 0 ) {
F_48 ( L_5 ) ;
return V_100 ;
}
V_72 = F_49 ( V_70 , V_99 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_50 ( V_70 , V_100 ) ;
if ( V_72 ) {
F_51 ( V_70 ) ;
return V_72 ;
}
return 0 ;
}
static void F_52 ( struct V_69 * V_70 )
{
struct V_15 * V_16 = V_70 -> V_71 ;
F_53 ( V_16 -> V_79 ) ;
}
static bool F_54 ( struct V_1 * V_2 ,
const struct V_101 * V_102 )
{
T_1 V_103 ;
const char * V_104 = L_6 ;
bool V_105 ;
bool V_106 ;
V_103 = F_11 ( V_2 , V_107 + V_108 ) ;
V_105 = ( F_55 ( V_103 ) == 0x500 ) ;
V_106 = F_56 ( V_102 -> V_109 , V_104 ,
sizeof( V_102 -> V_109 ) ) != NULL ;
if ( V_105 != V_106 ) {
F_48 ( L_7 ,
V_102 -> V_109 , V_105 ? L_8 : L_9 ) ;
return false ;
} else if ( ! V_106 ) {
T_2 V_110 ;
char V_111 [ 32 ] ;
V_103 = F_11 ( V_2 ,
V_112 + V_108 ) ;
V_110 = F_55 ( V_103 ) ;
snprintf ( V_111 , sizeof( V_111 ) , L_10 , V_110 ) ;
if ( ! F_56 ( V_102 -> V_109 , V_111 ,
sizeof( V_102 -> V_109 ) ) ) {
F_48 ( L_11 ,
V_102 -> V_109 , V_110 ) ;
return false ;
}
}
return true ;
}
static bool F_57 ( const struct V_113 * V_114 ,
const struct V_101 * V_102 )
{
T_3 V_115 = F_58 ( V_114 ) ;
const char * V_104 = L_6 ;
if ( ! F_56 ( V_102 -> V_109 , V_104 ,
sizeof( V_102 -> V_109 ) ) )
return V_115 >= V_116 ;
else if ( V_115 < V_117 )
return false ;
return true ;
}
static T_4 F_59 ( struct V_118 * V_17 , struct V_119 * V_120 ,
char * V_111 )
{
struct V_69 * V_70 = F_46 ( V_17 ) ;
struct V_15 * V_16 = V_70 -> V_71 ;
return snprintf ( V_111 , V_121 , L_12 , V_16 -> V_103 ) ;
}
static int F_60 ( struct V_118 * V_17 )
{
int V_72 = F_61 ( V_17 , & V_122 ) ;
if ( V_72 )
F_48 ( L_13 ) ;
return V_72 ;
}
static void F_62 ( struct V_118 * V_17 )
{
F_63 ( V_17 , & V_122 ) ;
}
static int F_64 ( struct V_118 * V_17 )
{
struct V_69 * V_70 = F_46 ( V_17 ) ;
struct V_15 * V_16 = V_70 -> V_71 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_65 ( ! V_2 -> V_75 ( V_2 ) ) ;
V_2 -> V_123 = true ;
F_66 ( V_2 -> V_124 ) ;
F_66 ( V_2 -> V_125 ) ;
F_66 ( V_2 -> V_126 ) ;
return 0 ;
}
static int F_67 ( struct V_118 * V_17 )
{
struct V_69 * V_70 = F_46 ( V_17 ) ;
struct V_15 * V_16 = V_70 -> V_71 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_68 ( V_2 -> V_126 ) ;
F_68 ( V_2 -> V_125 ) ;
F_68 ( V_2 -> V_124 ) ;
V_2 -> V_123 = false ;
return 0 ;
}
static int F_69 ( struct V_118 * V_17 )
{
struct V_113 * V_114 ;
struct V_69 * V_70 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_97 * V_98 = F_70 ( V_17 ) ;
struct V_101 const * V_102 ;
T_5 V_127 [ V_128 ] ;
int V_72 = 0 , V_5 ;
T_1 V_129 , V_130 = 0 ;
V_16 = F_71 ( V_17 , sizeof( * V_16 ) , V_131 ) ;
if ( ! V_16 )
return - V_132 ;
V_2 = F_71 ( V_17 , sizeof( * V_2 ) , V_131 ) ;
if ( ! V_2 )
return - V_132 ;
memcpy ( V_2 , F_72 ( V_17 ) , sizeof( * V_2 ) ) ;
V_16 -> V_17 = V_2 ;
V_114 = F_73 ( V_98 , V_133 , 0 ) ;
V_2 -> V_134 = F_74 ( V_17 , V_114 ) ;
if ( F_75 ( V_2 -> V_134 ) )
return F_76 ( V_2 -> V_134 ) ;
V_2 -> V_126 = F_77 ( V_17 , L_14 ) ;
if ( F_75 ( V_2 -> V_126 ) )
return F_76 ( V_2 -> V_126 ) ;
V_2 -> V_125 = F_77 ( V_17 , L_15 ) ;
if ( F_75 ( V_2 -> V_125 ) )
return F_76 ( V_2 -> V_125 ) ;
V_2 -> V_124 = F_77 ( V_17 , L_16 ) ;
if ( F_75 ( V_2 -> V_124 ) )
return F_76 ( V_2 -> V_124 ) ;
V_2 -> V_135 = F_77 ( V_17 , L_17 ) ;
if ( F_75 ( V_2 -> V_135 ) )
return F_76 ( V_2 -> V_135 ) ;
V_72 = F_78 ( V_17 ) ;
if ( V_72 && V_72 != - V_136 )
return V_72 ;
V_70 = F_79 ( & V_137 , V_17 ) ;
if ( F_75 ( V_70 ) ) {
V_72 = F_76 ( V_70 ) ;
goto V_138;
}
V_70 -> V_71 = V_16 ;
F_80 ( V_17 , V_70 ) ;
F_81 ( V_17 ) ;
if ( F_82 ( V_17 ) )
F_31 ( V_17 ) ;
else
F_67 ( V_17 ) ;
V_102 = F_83 ( V_139 , V_17 ) ;
if ( ! V_102 ) {
V_72 = - V_140 ;
goto V_141;
}
if ( ! F_57 ( V_114 , V_102 ) ) {
F_48 ( L_18 ) ;
V_72 = - V_140 ;
goto V_141;
}
if ( ! F_54 ( V_2 , V_102 ) ) {
V_72 = - V_140 ;
goto V_141;
}
V_72 = V_2 -> V_142 ( V_2 ) ;
if ( V_72 ) {
F_48 ( L_19 ) ;
goto V_141;
}
V_129 = F_11 ( V_2 , V_2 -> V_7 . V_143 + V_108 ) ;
F_84 ( L_20 , V_129 >> 16 ,
( V_129 >> 12 ) & 0xf , ( V_129 >> 8 ) & 0xf ) ;
V_16 -> V_103 = V_129 ;
V_72 = F_85 ( V_17 -> V_144 ,
L_21 ,
V_127 , V_128 ) ;
if ( V_72 )
goto V_141;
for ( V_5 = 0 ; V_5 < V_128 ; V_5 ++ )
V_130 = ( V_130 << 8 ) | ( V_127 [ V_5 ] & 0xf ) ;
F_3 ( V_2 , V_130 , V_2 -> V_7 . V_145 ) ;
F_16 ( & V_16 -> V_73 , 0 ) ;
F_86 ( & V_16 -> V_76 ) ;
V_72 = F_39 ( V_70 ) ;
if ( V_72 < 0 )
goto V_141;
V_72 = F_60 ( V_17 ) ;
if ( V_72 )
goto V_146;
V_16 -> V_12 . V_147 = F_87 ( V_17 -> V_144 , 0 ) ;
V_72 = F_88 ( V_17 , V_70 ) ;
if ( V_72 ) {
F_48 ( L_22 ) ;
goto V_148;
}
V_72 = F_45 ( V_98 ) ;
if ( V_72 < 0 )
goto V_149;
V_70 -> V_150 = true ;
V_72 = F_89 ( V_70 , V_70 -> V_86 . V_151 ) ;
if ( V_72 < 0 ) {
F_48 ( L_23 ) ;
goto V_152;
}
F_37 ( V_17 ) ;
F_90 ( V_70 ) ;
V_16 -> V_79 = F_91 ( V_70 , 32 ,
V_70 -> V_86 . V_153 ) ;
if ( F_75 ( V_16 -> V_79 ) ) {
V_72 = F_76 ( V_16 -> V_79 ) ;
V_16 -> V_79 = NULL ;
goto V_154;
}
F_92 ( V_70 ) ;
V_72 = F_93 ( V_70 , 0 ) ;
if ( V_72 )
goto V_155;
return 0 ;
V_155:
if ( V_16 -> V_79 ) {
F_94 ( V_16 -> V_79 ) ;
V_16 -> V_79 = NULL ;
}
F_95 ( V_70 ) ;
V_154:
F_31 ( V_17 ) ;
V_152:
F_96 ( V_70 ) ;
F_51 ( V_70 ) ;
V_70 -> V_150 = false ;
V_149:
F_97 ( V_17 , V_70 ) ;
V_148:
F_98 ( V_16 -> V_12 . V_147 ) ;
V_16 -> V_12 . V_147 = NULL ;
V_146:
F_62 ( V_17 ) ;
F_43 ( V_70 ) ;
V_141:
F_37 ( V_17 ) ;
if ( F_82 ( V_17 ) )
F_99 ( V_17 ) ;
else
F_64 ( V_17 ) ;
V_70 -> V_71 = NULL ;
F_80 ( V_17 , NULL ) ;
F_100 ( V_70 ) ;
V_138:
F_101 ( V_17 ) ;
return V_72 ;
}
static void F_102 ( struct V_118 * V_17 )
{
struct V_69 * V_70 = F_46 ( V_17 ) ;
struct V_15 * V_16 = V_70 -> V_71 ;
F_103 ( V_70 ) ;
if ( V_16 -> V_79 ) {
F_94 ( V_16 -> V_79 ) ;
V_16 -> V_79 = NULL ;
}
F_95 ( V_70 ) ;
F_31 ( V_17 ) ;
F_96 ( V_70 ) ;
F_51 ( V_70 ) ;
F_97 ( V_17 , V_70 ) ;
F_98 ( V_16 -> V_12 . V_147 ) ;
V_16 -> V_12 . V_147 = NULL ;
F_62 ( V_17 ) ;
F_43 ( V_70 ) ;
F_37 ( V_17 ) ;
if ( F_82 ( V_17 ) )
F_99 ( V_17 ) ;
else
F_64 ( V_17 ) ;
V_70 -> V_71 = NULL ;
F_80 ( V_17 , NULL ) ;
F_100 ( V_70 ) ;
F_101 ( V_17 ) ;
}
static int F_104 ( struct V_118 * V_17 , void * V_3 )
{
struct V_156 * V_157 = V_3 ;
return V_17 -> V_144 == V_157 ;
}
static int F_105 ( struct V_97 * V_98 )
{
struct V_156 * V_147 ;
struct V_158 * V_159 = NULL ;
if ( ! V_98 -> V_17 . V_144 )
return - V_136 ;
V_147 = F_106 ( V_98 -> V_17 . V_144 , 0 , 0 ) ;
if ( ! V_147 )
return - V_136 ;
F_107 ( & V_98 -> V_17 , & V_159 , F_104 ,
V_147 ) ;
F_98 ( V_147 ) ;
return F_108 ( & V_98 -> V_17 , & V_160 ,
V_159 ) ;
}
static int F_109 ( struct V_97 * V_98 )
{
F_110 ( & V_98 -> V_17 , & V_160 ) ;
return 0 ;
}
static int T_6 F_111 ( struct V_118 * V_17 )
{
struct V_69 * V_70 = F_46 ( V_17 ) ;
struct V_15 * V_16 = V_70 -> V_71 ;
F_112 ( V_70 ) ;
F_113 () ;
F_114 ( V_16 -> V_79 , 1 ) ;
F_115 () ;
V_16 -> V_161 = F_116 ( V_70 ) ;
if ( F_75 ( V_16 -> V_161 ) ) {
F_113 () ;
F_114 ( V_16 -> V_79 , 0 ) ;
F_115 () ;
F_117 ( V_70 ) ;
return F_76 ( V_16 -> V_161 ) ;
}
return 0 ;
}
static int T_6 F_118 ( struct V_118 * V_17 )
{
struct V_69 * V_70 = F_46 ( V_17 ) ;
struct V_15 * V_16 = V_70 -> V_71 ;
F_119 ( V_70 , V_16 -> V_161 ) ;
F_113 () ;
F_114 ( V_16 -> V_79 , 0 ) ;
F_115 () ;
F_117 ( V_70 ) ;
return 0 ;
}
