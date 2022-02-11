char * F_1 ( struct V_1 * V_2 )
{
static char V_3 [ 32 ] ;
snprintf ( V_3 , 32 , L_1 ,
V_4 [ V_2 -> V_5 ] . V_6 ,
V_2 -> V_7 . V_8 ) ;
return V_3 ;
}
char * F_2 ( struct V_9 * V_10 )
{
static char V_3 [ 32 ] ;
snprintf ( V_3 , 32 , L_1 ,
V_11 [ V_10 -> V_12 ] . V_6 ,
V_10 -> V_13 ) ;
return V_3 ;
}
char * F_3 ( enum V_14 V_15 )
{
if ( V_15 == V_16 )
return L_2 ;
else if ( V_15 == V_17 )
return L_3 ;
else
return L_4 ;
}
static int F_4 ( struct V_18 * V_19 ,
struct V_20 * V_21 , T_1 V_22 )
{
int V_23 = 0 ;
int V_24 ;
V_25:
if ( F_5 ( & V_19 -> V_26 . V_27 , V_28 ) == 0 ) {
F_6 ( L_5 ) ;
return - V_29 ;
}
F_7 ( & V_19 -> V_26 . V_30 ) ;
V_24 = F_8 ( & V_19 -> V_26 . V_27 , V_21 , 1 , & V_23 ) ;
F_9 ( & V_19 -> V_26 . V_30 ) ;
if ( V_24 == - V_31 )
goto V_25;
else if ( V_24 )
return V_24 ;
V_21 -> V_8 = V_23 ;
V_21 -> type = V_22 ;
return 0 ;
}
static void F_10 ( struct V_18 * V_19 ,
struct V_20 * V_32 )
{
F_7 ( & V_19 -> V_26 . V_30 ) ;
F_11 ( & V_19 -> V_26 . V_27 , V_32 -> V_8 ) ;
F_9 ( & V_19 -> V_26 . V_30 ) ;
}
struct V_20 * F_12 ( struct V_18 * V_19 ,
T_1 V_8 , T_1 type )
{
struct V_20 * V_21 = NULL ;
F_7 ( & V_19 -> V_26 . V_30 ) ;
V_21 = F_13 ( & V_19 -> V_26 . V_27 , V_8 ) ;
if ( ! V_21 || ( V_21 -> type != type ) || ( V_21 -> V_8 != V_8 ) )
V_21 = NULL ;
F_9 ( & V_19 -> V_26 . V_30 ) ;
return V_21 ;
}
int F_14 ( struct V_18 * V_19 , struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
int V_24 ;
V_24 = F_4 ( V_19 , & V_34 -> V_7 , V_37 ) ;
if ( V_24 )
return V_24 ;
V_34 -> V_19 = V_19 ;
V_34 -> V_36 = V_36 ;
V_19 -> V_26 . V_38 ++ ;
F_15 ( & V_34 -> V_39 , & V_19 -> V_26 . V_40 ) ;
return 0 ;
}
void F_16 ( struct V_33 * V_34 )
{
struct V_18 * V_19 = V_34 -> V_19 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
int V_24 ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_42 -> V_34 == V_34 ) {
memset ( & V_46 , 0 , sizeof( struct V_45 ) ) ;
V_46 . V_42 = V_42 ;
V_46 . V_34 = NULL ;
V_24 = V_42 -> V_36 -> V_47 ( & V_46 ) ;
if ( V_24 )
F_6 ( L_6 , V_42 ) ;
}
}
F_17 (plane, &dev->mode_config.plane_list, head) {
if ( V_44 -> V_34 == V_34 ) {
V_24 = V_44 -> V_36 -> V_48 ( V_44 ) ;
if ( V_24 )
F_6 ( L_7 ) ;
V_44 -> V_34 = NULL ;
V_44 -> V_42 = NULL ;
}
}
F_10 ( V_19 , & V_34 -> V_7 ) ;
F_18 ( & V_34 -> V_39 ) ;
V_19 -> V_26 . V_38 -- ;
}
int F_19 ( struct V_18 * V_19 , struct V_41 * V_42 ,
const struct V_49 * V_36 )
{
int V_24 ;
V_42 -> V_19 = V_19 ;
V_42 -> V_36 = V_36 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_24 = F_4 ( V_19 , & V_42 -> V_7 , V_51 ) ;
if ( V_24 )
goto V_52;
V_42 -> V_7 . V_53 = & V_42 -> V_53 ;
F_20 ( & V_42 -> V_39 , & V_19 -> V_26 . V_54 ) ;
V_19 -> V_26 . V_55 ++ ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_21 ( struct V_41 * V_42 )
{
struct V_18 * V_19 = V_42 -> V_19 ;
if ( V_42 -> V_56 ) {
F_22 ( V_42 -> V_56 ) ;
V_42 -> V_56 = NULL ;
}
F_10 ( V_19 , & V_42 -> V_7 ) ;
F_18 ( & V_42 -> V_39 ) ;
V_19 -> V_26 . V_55 -- ;
}
void F_23 ( struct V_9 * V_10 ,
struct V_57 * V_58 )
{
F_15 ( & V_58 -> V_39 , & V_10 -> V_59 ) ;
}
void F_24 ( struct V_9 * V_10 ,
struct V_57 * V_58 )
{
F_18 ( & V_58 -> V_39 ) ;
F_25 ( V_10 -> V_19 , V_58 ) ;
}
int F_26 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
const struct V_60 * V_36 ,
int V_12 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_24 = F_4 ( V_19 , & V_10 -> V_7 , V_61 ) ;
if ( V_24 )
goto V_52;
V_10 -> V_7 . V_53 = & V_10 -> V_53 ;
V_10 -> V_19 = V_19 ;
V_10 -> V_36 = V_36 ;
V_10 -> V_12 = V_12 ;
V_10 -> V_13 =
++ V_11 [ V_12 ] . V_62 ;
F_27 ( & V_10 -> V_63 ) ;
F_27 ( & V_10 -> V_59 ) ;
F_27 ( & V_10 -> V_64 ) ;
V_10 -> V_65 = NULL ;
F_20 ( & V_10 -> V_39 , & V_19 -> V_26 . V_66 ) ;
V_19 -> V_26 . V_67 ++ ;
if ( V_12 != V_68 )
F_28 ( V_10 ,
V_19 -> V_26 . V_69 ,
0 ) ;
F_28 ( V_10 ,
V_19 -> V_26 . V_70 , 0 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_29 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
struct V_57 * V_58 , * V_71 ;
F_30 (mode, t, &connector->probed_modes, head)
F_24 ( V_10 , V_58 ) ;
F_30 (mode, t, &connector->modes, head)
F_24 ( V_10 , V_58 ) ;
F_30 (mode, t, &connector->user_modes, head)
F_24 ( V_10 , V_58 ) ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_10 ( V_19 , & V_10 -> V_7 ) ;
F_18 ( & V_10 -> V_39 ) ;
V_19 -> V_26 . V_67 -- ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
void F_31 ( struct V_18 * V_19 )
{
struct V_9 * V_10 ;
F_17 (connector, &dev->mode_config.connector_list, head)
F_32 ( V_10 ) ;
}
int F_33 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
const struct V_72 * V_36 ,
int V_5 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_24 = F_4 ( V_19 , & V_2 -> V_7 , V_73 ) ;
if ( V_24 )
goto V_52;
V_2 -> V_19 = V_19 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_36 = V_36 ;
F_20 ( & V_2 -> V_39 , & V_19 -> V_26 . V_74 ) ;
V_19 -> V_26 . V_75 ++ ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_10 ( V_19 , & V_2 -> V_7 ) ;
F_18 ( & V_2 -> V_39 ) ;
V_19 -> V_26 . V_75 -- ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
int F_35 ( struct V_18 * V_19 , struct V_43 * V_44 ,
unsigned long V_76 ,
const struct V_77 * V_36 ,
const T_1 * V_78 , T_1 V_79 ,
bool V_80 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_24 = F_4 ( V_19 , & V_44 -> V_7 , V_81 ) ;
if ( V_24 )
goto V_52;
V_44 -> V_7 . V_53 = & V_44 -> V_53 ;
V_44 -> V_19 = V_19 ;
V_44 -> V_36 = V_36 ;
V_44 -> V_82 = F_36 ( sizeof( T_1 ) * V_79 ,
V_28 ) ;
if ( ! V_44 -> V_82 ) {
F_37 ( L_8 ) ;
F_10 ( V_19 , & V_44 -> V_7 ) ;
V_24 = - V_29 ;
goto V_52;
}
memcpy ( V_44 -> V_82 , V_78 , V_79 * sizeof( T_1 ) ) ;
V_44 -> V_79 = V_79 ;
V_44 -> V_76 = V_76 ;
if ( ! V_80 ) {
F_20 ( & V_44 -> V_39 , & V_19 -> V_26 . V_83 ) ;
V_19 -> V_26 . V_84 ++ ;
} else {
F_27 ( & V_44 -> V_39 ) ;
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_38 ( struct V_43 * V_44 )
{
struct V_18 * V_19 = V_44 -> V_19 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_22 ( V_44 -> V_82 ) ;
F_10 ( V_19 , & V_44 -> V_7 ) ;
if ( ! F_39 ( & V_44 -> V_39 ) ) {
F_18 ( & V_44 -> V_39 ) ;
V_19 -> V_26 . V_84 -- ;
}
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
struct V_57 * F_40 ( struct V_18 * V_19 )
{
struct V_57 * V_85 ;
V_85 = F_41 ( sizeof( struct V_57 ) , V_28 ) ;
if ( ! V_85 )
return NULL ;
if ( F_4 ( V_19 , & V_85 -> V_7 , V_86 ) ) {
F_22 ( V_85 ) ;
return NULL ;
}
return V_85 ;
}
void F_25 ( struct V_18 * V_19 , struct V_57 * V_58 )
{
if ( ! V_58 )
return;
F_10 ( V_19 , & V_58 -> V_7 ) ;
F_22 ( V_58 ) ;
}
static int F_42 ( struct V_18 * V_19 )
{
struct V_87 * V_88 ;
struct V_87 * V_89 ;
V_88 = F_43 ( V_19 , V_90 |
V_91 ,
L_9 , 0 ) ;
V_19 -> V_26 . V_69 = V_88 ;
V_89 = F_44 ( V_19 , 0 ,
L_10 , V_92 ,
F_45 ( V_92 ) ) ;
V_19 -> V_26 . V_70 = V_89 ;
return 0 ;
}
int F_46 ( struct V_18 * V_19 )
{
struct V_87 * V_93 ;
struct V_87 * V_94 ;
if ( V_19 -> V_26 . V_95 )
return 0 ;
V_93 =
F_44 ( V_19 , 0 ,
L_11 ,
V_96 ,
F_45 ( V_96 ) ) ;
V_19 -> V_26 . V_95 = V_93 ;
V_94 = F_44 ( V_19 , V_91 ,
L_12 ,
V_97 ,
F_45 ( V_97 ) ) ;
V_19 -> V_26 . V_98 = V_94 ;
return 0 ;
}
int F_47 ( struct V_18 * V_19 , int V_99 ,
char * V_64 [] )
{
struct V_87 * V_100 ;
struct V_87 * V_101 ;
int V_102 ;
if ( V_19 -> V_26 . V_103 )
return 0 ;
V_100 = F_44 ( V_19 , 0 ,
L_11 ,
V_104 ,
F_45 ( V_104 ) ) ;
V_19 -> V_26 . V_103 = V_100 ;
V_101 =
F_44 ( V_19 , V_91 ,
L_12 ,
V_105 ,
F_45 ( V_105 ) ) ;
V_19 -> V_26 . V_106 = V_101 ;
V_19 -> V_26 . V_107 =
F_48 ( V_19 , 0 , L_13 , 0 , 100 ) ;
V_19 -> V_26 . V_108 =
F_48 ( V_19 , 0 , L_14 , 0 , 100 ) ;
V_19 -> V_26 . V_109 =
F_48 ( V_19 , 0 , L_15 , 0 , 100 ) ;
V_19 -> V_26 . V_110 =
F_48 ( V_19 , 0 , L_16 , 0 , 100 ) ;
V_19 -> V_26 . V_111 =
F_43 ( V_19 , V_112 ,
L_17 , V_99 ) ;
for ( V_102 = 0 ; V_102 < V_99 ; V_102 ++ )
F_49 ( V_19 -> V_26 . V_111 , V_102 ,
V_102 , V_64 [ V_102 ] ) ;
V_19 -> V_26 . V_113 =
F_48 ( V_19 , 0 , L_18 , 0 , 100 ) ;
V_19 -> V_26 . V_114 =
F_48 ( V_19 , 0 , L_19 , 0 , 100 ) ;
V_19 -> V_26 . V_115 =
F_48 ( V_19 , 0 , L_20 , 0 , 100 ) ;
V_19 -> V_26 . V_116 =
F_48 ( V_19 , 0 , L_21 , 0 , 100 ) ;
V_19 -> V_26 . V_117 =
F_48 ( V_19 , 0 , L_22 , 0 , 100 ) ;
V_19 -> V_26 . V_118 =
F_48 ( V_19 , 0 , L_23 , 0 , 100 ) ;
return 0 ;
}
int F_50 ( struct V_18 * V_19 )
{
struct V_87 * V_119 ;
if ( V_19 -> V_26 . V_120 )
return 0 ;
V_119 =
F_44 ( V_19 , 0 , L_24 ,
V_121 ,
F_45 ( V_121 ) ) ;
V_19 -> V_26 . V_120 = V_119 ;
return 0 ;
}
int F_51 ( struct V_18 * V_19 )
{
struct V_87 * V_122 ;
if ( V_19 -> V_26 . V_123 )
return 0 ;
V_122 =
F_44 ( V_19 , 0 , L_25 ,
V_124 ,
F_45 ( V_124 ) ) ;
V_19 -> V_26 . V_123 = V_122 ;
return 0 ;
}
int F_52 ( struct V_18 * V_19 )
{
struct V_87 * V_125 ;
if ( V_19 -> V_26 . V_126 )
return 0 ;
V_125 =
F_44 ( V_19 , V_91 ,
L_26 ,
V_127 ,
F_45 ( V_127 ) ) ;
V_19 -> V_26 . V_126 = V_125 ;
return 0 ;
}
void F_53 ( struct V_18 * V_19 )
{
F_54 ( & V_19 -> V_26 . V_50 ) ;
F_54 ( & V_19 -> V_26 . V_30 ) ;
F_27 ( & V_19 -> V_26 . V_40 ) ;
F_27 ( & V_19 -> V_26 . V_54 ) ;
F_27 ( & V_19 -> V_26 . V_66 ) ;
F_27 ( & V_19 -> V_26 . V_74 ) ;
F_27 ( & V_19 -> V_26 . V_128 ) ;
F_27 ( & V_19 -> V_26 . V_129 ) ;
F_27 ( & V_19 -> V_26 . V_83 ) ;
F_55 ( & V_19 -> V_26 . V_27 ) ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_42 ( V_19 ) ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
V_19 -> V_26 . V_38 = 0 ;
V_19 -> V_26 . V_67 = 0 ;
V_19 -> V_26 . V_55 = 0 ;
V_19 -> V_26 . V_75 = 0 ;
}
int F_56 ( struct V_18 * V_19 , struct V_130 * V_131 )
{
T_1 V_132 = 0 ;
V_132 += V_19 -> V_26 . V_55 ;
V_132 += V_19 -> V_26 . V_67 ;
V_132 += V_19 -> V_26 . V_75 ;
V_131 -> V_133 = F_41 ( V_132 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_131 -> V_133 )
return - V_29 ;
V_131 -> V_134 = 0 ;
V_131 -> V_135 = 0 ;
V_131 -> V_136 = 0 ;
return 0 ;
}
int F_57 ( struct V_18 * V_19 ,
struct V_130 * V_131 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_24 ;
if ( ( V_24 = F_56 ( V_19 , V_131 ) ) )
return V_24 ;
F_17 (crtc, &dev->mode_config.crtc_list, head)
V_131 -> V_133 [ V_131 -> V_134 ++ ] = V_42 -> V_7 . V_8 ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
V_131 -> V_133 [ V_131 -> V_134 + V_131 -> V_136 ++ ] =
V_2 -> V_7 . V_8 ;
F_17 (connector, &dev->mode_config.connector_list, head)
V_131 -> V_133 [ V_131 -> V_134 + V_131 -> V_136 +
V_131 -> V_135 ++ ] = V_10 -> V_7 . V_8 ;
return 0 ;
}
void F_58 ( struct V_18 * V_19 )
{
struct V_9 * V_10 , * V_137 ;
struct V_41 * V_42 , * V_138 ;
struct V_1 * V_2 , * V_139 ;
struct V_33 * V_34 , * V_140 ;
struct V_87 * V_141 , * V_142 ;
struct V_43 * V_44 , * V_143 ;
F_30 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_2 -> V_36 -> V_144 ( V_2 ) ;
}
F_30 (connector, ot,
&dev->mode_config.connector_list, head) {
V_10 -> V_36 -> V_144 ( V_10 ) ;
}
F_30 (property, pt, &dev->mode_config.property_list,
head) {
F_59 ( V_19 , V_141 ) ;
}
F_30 (fb, fbt, &dev->mode_config.fb_list, head) {
V_34 -> V_36 -> V_144 ( V_34 ) ;
}
F_30 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_42 -> V_36 -> V_144 ( V_42 ) ;
}
F_30 (plane, plt, &dev->mode_config.plane_list,
head) {
V_44 -> V_36 -> V_144 ( V_44 ) ;
}
F_60 ( & V_19 -> V_26 . V_27 ) ;
F_61 ( & V_19 -> V_26 . V_27 ) ;
}
static void F_62 ( struct V_145 * V_52 ,
const struct V_57 * V_146 )
{
F_63 ( V_146 -> V_147 > V_148 || V_146 -> V_149 > V_148 ||
V_146 -> V_150 > V_148 || V_146 -> V_151 > V_148 ||
V_146 -> V_152 > V_148 || V_146 -> V_153 > V_148 ||
V_146 -> V_154 > V_148 || V_146 -> V_155 > V_148 ||
V_146 -> V_156 > V_148 || V_146 -> V_157 > V_148 ,
L_27 ) ;
V_52 -> clock = V_146 -> clock ;
V_52 -> V_147 = V_146 -> V_147 ;
V_52 -> V_149 = V_146 -> V_149 ;
V_52 -> V_150 = V_146 -> V_150 ;
V_52 -> V_151 = V_146 -> V_151 ;
V_52 -> V_152 = V_146 -> V_152 ;
V_52 -> V_153 = V_146 -> V_153 ;
V_52 -> V_154 = V_146 -> V_154 ;
V_52 -> V_155 = V_146 -> V_155 ;
V_52 -> V_156 = V_146 -> V_156 ;
V_52 -> V_157 = V_146 -> V_157 ;
V_52 -> V_158 = V_146 -> V_158 ;
V_52 -> V_159 = V_146 -> V_159 ;
V_52 -> type = V_146 -> type ;
strncpy ( V_52 -> V_6 , V_146 -> V_6 , V_160 ) ;
V_52 -> V_6 [ V_160 - 1 ] = 0 ;
}
static int F_64 ( struct V_57 * V_52 ,
const struct V_145 * V_146 )
{
if ( V_146 -> clock > V_161 || V_146 -> V_158 > V_161 )
return - V_162 ;
V_52 -> clock = V_146 -> clock ;
V_52 -> V_147 = V_146 -> V_147 ;
V_52 -> V_149 = V_146 -> V_149 ;
V_52 -> V_150 = V_146 -> V_150 ;
V_52 -> V_151 = V_146 -> V_151 ;
V_52 -> V_152 = V_146 -> V_152 ;
V_52 -> V_153 = V_146 -> V_153 ;
V_52 -> V_154 = V_146 -> V_154 ;
V_52 -> V_155 = V_146 -> V_155 ;
V_52 -> V_156 = V_146 -> V_156 ;
V_52 -> V_157 = V_146 -> V_157 ;
V_52 -> V_158 = V_146 -> V_158 ;
V_52 -> V_159 = V_146 -> V_159 ;
V_52 -> type = V_146 -> type ;
strncpy ( V_52 -> V_6 , V_146 -> V_6 , V_160 ) ;
V_52 -> V_6 [ V_160 - 1 ] = 0 ;
return 0 ;
}
int F_65 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_166 * V_167 = V_163 ;
struct V_168 * V_169 ;
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
int V_170 = 0 ;
int V_171 = 0 ;
int V_172 = 0 ;
int V_173 = 0 ;
int V_174 = 0 , V_102 ;
T_1 T_2 * V_175 ;
T_1 T_2 * V_176 ;
T_1 T_2 * V_177 ;
T_1 T_2 * V_178 ;
struct V_130 * V_179 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_67 (lh, &file_priv->fbs)
V_172 ++ ;
V_179 = & V_165 -> V_182 -> V_183 -> V_179 ;
if ( V_165 -> V_182 -> V_183 -> type == V_184 ) {
F_67 (lh, &dev->mode_config.crtc_list)
V_171 ++ ;
F_67 (lh, &dev->mode_config.connector_list)
V_170 ++ ;
F_67 (lh, &dev->mode_config.encoder_list)
V_173 ++ ;
} else {
V_171 = V_179 -> V_134 ;
V_170 = V_179 -> V_135 ;
V_173 = V_179 -> V_136 ;
}
V_167 -> V_185 = V_19 -> V_26 . V_185 ;
V_167 -> V_186 = V_19 -> V_26 . V_186 ;
V_167 -> V_187 = V_19 -> V_26 . V_187 ;
V_167 -> V_188 = V_19 -> V_26 . V_188 ;
if ( V_167 -> V_189 >= V_172 ) {
V_174 = 0 ;
V_175 = ( T_1 T_2 * ) ( unsigned long ) V_167 -> V_190 ;
F_17 (fb, &file_priv->fbs, filp_head) {
if ( F_68 ( V_34 -> V_7 . V_8 , V_175 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
}
V_167 -> V_189 = V_172 ;
if ( V_167 -> V_192 >= V_171 ) {
V_174 = 0 ;
V_176 = ( T_1 T_2 * ) ( unsigned long ) V_167 -> V_193 ;
if ( V_165 -> V_182 -> V_183 -> type == V_184 ) {
F_17 (crtc, &dev->mode_config.crtc_list,
head) {
F_37 ( L_28 , V_42 -> V_7 . V_8 ) ;
if ( F_68 ( V_42 -> V_7 . V_8 , V_176 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
} else {
for ( V_102 = 0 ; V_102 < V_179 -> V_134 ; V_102 ++ ) {
if ( F_68 ( V_179 -> V_133 [ V_102 ] ,
V_176 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
}
}
V_167 -> V_192 = V_171 ;
if ( V_167 -> V_194 >= V_173 ) {
V_174 = 0 ;
V_178 = ( T_1 T_2 * ) ( unsigned long ) V_167 -> V_195 ;
if ( V_165 -> V_182 -> V_183 -> type == V_184 ) {
F_17 (encoder,
&dev->mode_config.encoder_list,
head) {
F_37 ( L_29 , V_2 -> V_7 . V_8 ,
F_1 ( V_2 ) ) ;
if ( F_68 ( V_2 -> V_7 . V_8 , V_178 +
V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
} else {
for ( V_102 = V_179 -> V_134 ; V_102 < V_179 -> V_134 + V_179 -> V_136 ; V_102 ++ ) {
if ( F_68 ( V_179 -> V_133 [ V_102 ] ,
V_178 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
}
}
V_167 -> V_194 = V_173 ;
if ( V_167 -> V_196 >= V_170 ) {
V_174 = 0 ;
V_177 = ( T_1 T_2 * ) ( unsigned long ) V_167 -> V_197 ;
if ( V_165 -> V_182 -> V_183 -> type == V_184 ) {
F_17 (connector,
&dev->mode_config.connector_list,
head) {
F_37 ( L_30 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
if ( F_68 ( V_10 -> V_7 . V_8 ,
V_177 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
} else {
int V_198 = V_179 -> V_134 +
V_179 -> V_136 ;
for ( V_102 = V_198 ; V_102 < V_198 + V_179 -> V_135 ; V_102 ++ ) {
if ( F_68 ( V_179 -> V_133 [ V_102 ] ,
V_177 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
}
}
V_167 -> V_196 = V_170 ;
F_37 ( L_31 , V_167 -> V_192 ,
V_167 -> V_196 , V_167 -> V_194 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_69 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_199 * V_200 = V_163 ;
struct V_41 * V_42 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_200 -> V_176 ,
V_51 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
V_200 -> V_201 = V_42 -> V_201 ;
V_200 -> V_202 = V_42 -> V_202 ;
V_200 -> V_203 = V_42 -> V_203 ;
if ( V_42 -> V_34 )
V_200 -> V_175 = V_42 -> V_34 -> V_7 . V_8 ;
else
V_200 -> V_175 = 0 ;
if ( V_42 -> V_204 ) {
F_62 ( & V_200 -> V_58 , & V_42 -> V_58 ) ;
V_200 -> V_205 = 1 ;
} else {
V_200 -> V_205 = 0 ;
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_71 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_206 * V_207 = V_163 ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
struct V_57 * V_58 ;
int V_208 = 0 ;
int V_209 = 0 ;
int V_210 = 0 ;
int V_24 = 0 ;
int V_174 = 0 ;
int V_102 ;
struct V_145 V_211 ;
struct V_145 T_2 * V_212 ;
T_1 T_2 * V_213 ;
T_3 T_2 * V_214 ;
T_1 T_2 * V_215 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
memset ( & V_211 , 0 , sizeof( struct V_145 ) ) ;
F_37 ( L_32 , V_207 -> V_177 ) ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_207 -> V_177 ,
V_61 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
V_10 = F_72 ( V_21 ) ;
V_209 = V_10 -> V_53 . V_62 ;
for ( V_102 = 0 ; V_102 < V_216 ; V_102 ++ ) {
if ( V_10 -> V_217 [ V_102 ] != 0 ) {
V_210 ++ ;
}
}
if ( V_207 -> V_218 == 0 ) {
V_10 -> V_36 -> V_219 ( V_10 ,
V_19 -> V_26 . V_187 ,
V_19 -> V_26 . V_185 ) ;
}
F_17 (mode, &connector->modes, head)
V_208 ++ ;
V_207 -> V_177 = V_10 -> V_7 . V_8 ;
V_207 -> V_12 = V_10 -> V_12 ;
V_207 -> V_13 = V_10 -> V_13 ;
V_207 -> V_220 = V_10 -> V_221 . V_222 ;
V_207 -> V_223 = V_10 -> V_221 . V_224 ;
V_207 -> V_225 = V_10 -> V_221 . V_226 ;
V_207 -> V_227 = V_10 -> V_15 ;
if ( V_10 -> V_2 )
V_207 -> V_178 = V_10 -> V_2 -> V_7 . V_8 ;
else
V_207 -> V_178 = 0 ;
if ( ( V_207 -> V_218 >= V_208 ) && V_208 ) {
V_174 = 0 ;
V_212 = (struct V_145 T_2 * ) ( unsigned long ) V_207 -> V_228 ;
F_17 (mode, &connector->modes, head) {
F_62 ( & V_211 , V_58 ) ;
if ( F_73 ( V_212 + V_174 ,
& V_211 , sizeof( V_211 ) ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
}
V_207 -> V_218 = V_208 ;
if ( ( V_207 -> V_229 >= V_209 ) && V_209 ) {
V_174 = 0 ;
V_213 = ( T_1 T_2 * ) ( unsigned long ) ( V_207 -> V_230 ) ;
V_214 = ( T_3 T_2 * ) ( unsigned long ) ( V_207 -> V_231 ) ;
for ( V_102 = 0 ; V_102 < V_10 -> V_53 . V_62 ; V_102 ++ ) {
if ( F_68 ( V_10 -> V_53 . V_232 [ V_102 ] ,
V_213 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
if ( F_68 ( V_10 -> V_53 . V_233 [ V_102 ] ,
V_214 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
}
V_207 -> V_229 = V_209 ;
if ( ( V_207 -> V_194 >= V_210 ) && V_210 ) {
V_174 = 0 ;
V_215 = ( T_1 T_2 * ) ( unsigned long ) ( V_207 -> V_234 ) ;
for ( V_102 = 0 ; V_102 < V_216 ; V_102 ++ ) {
if ( V_10 -> V_217 [ V_102 ] != 0 ) {
if ( F_68 ( V_10 -> V_217 [ V_102 ] ,
V_215 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
}
}
V_207 -> V_194 = V_210 ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_74 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_235 * V_236 = V_163 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_236 -> V_178 ,
V_73 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
V_2 = F_75 ( V_21 ) ;
if ( V_2 -> V_42 )
V_236 -> V_176 = V_2 -> V_42 -> V_7 . V_8 ;
else
V_236 -> V_176 = 0 ;
V_236 -> V_5 = V_2 -> V_5 ;
V_236 -> V_178 = V_2 -> V_7 . V_8 ;
V_236 -> V_76 = V_2 -> V_76 ;
V_236 -> V_237 = V_2 -> V_237 ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_76 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_238 * V_239 = V_163 ;
struct V_240 * V_241 ;
struct V_43 * V_44 ;
T_1 T_2 * V_242 ;
int V_174 = 0 , V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_241 = & V_19 -> V_26 ;
if ( V_241 -> V_84 &&
( V_239 -> V_243 >= V_241 -> V_84 ) ) {
V_242 = ( T_1 T_2 * ) ( unsigned long ) V_239 -> V_244 ;
F_17 (plane, &config->plane_list, head) {
if ( F_68 ( V_44 -> V_7 . V_8 , V_242 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
}
V_239 -> V_243 = V_241 -> V_84 ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_77 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_245 * V_239 = V_163 ;
struct V_20 * V_21 ;
struct V_43 * V_44 ;
T_1 T_2 * V_246 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_239 -> V_247 ,
V_81 ) ;
if ( ! V_21 ) {
V_24 = - V_248 ;
goto V_52;
}
V_44 = F_78 ( V_21 ) ;
if ( V_44 -> V_42 )
V_239 -> V_176 = V_44 -> V_42 -> V_7 . V_8 ;
else
V_239 -> V_176 = 0 ;
if ( V_44 -> V_34 )
V_239 -> V_175 = V_44 -> V_34 -> V_7 . V_8 ;
else
V_239 -> V_175 = 0 ;
V_239 -> V_247 = V_44 -> V_7 . V_8 ;
V_239 -> V_76 = V_44 -> V_76 ;
V_239 -> V_203 = V_44 -> V_203 ;
if ( V_44 -> V_79 &&
( V_239 -> V_249 >= V_44 -> V_79 ) ) {
V_246 = ( T_1 T_2 * ) ( unsigned long ) V_239 -> V_250 ;
if ( F_73 ( V_246 ,
V_44 -> V_82 ,
sizeof( T_1 ) * V_44 -> V_79 ) ) {
V_24 = - V_191 ;
goto V_52;
}
}
V_239 -> V_249 = V_44 -> V_79 ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_79 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_251 * V_252 = V_163 ;
struct V_20 * V_21 ;
struct V_43 * V_44 ;
struct V_41 * V_42 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
unsigned int V_253 , V_254 ;
int V_102 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_252 -> V_247 ,
V_81 ) ;
if ( ! V_21 ) {
F_37 ( L_33 ,
V_252 -> V_247 ) ;
V_24 = - V_248 ;
goto V_52;
}
V_44 = F_78 ( V_21 ) ;
if ( ! V_252 -> V_175 ) {
V_44 -> V_36 -> V_48 ( V_44 ) ;
V_44 -> V_42 = NULL ;
V_44 -> V_34 = NULL ;
goto V_52;
}
V_21 = F_12 ( V_19 , V_252 -> V_176 ,
V_51 ) ;
if ( ! V_21 ) {
F_37 ( L_34 ,
V_252 -> V_176 ) ;
V_24 = - V_248 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
V_21 = F_12 ( V_19 , V_252 -> V_175 ,
V_37 ) ;
if ( ! V_21 ) {
F_37 ( L_35 ,
V_252 -> V_175 ) ;
V_24 = - V_248 ;
goto V_52;
}
V_34 = F_80 ( V_21 ) ;
for ( V_102 = 0 ; V_102 < V_44 -> V_79 ; V_102 ++ )
if ( V_34 -> V_255 == V_44 -> V_82 [ V_102 ] )
break;
if ( V_102 == V_44 -> V_79 ) {
F_37 ( L_36 , V_34 -> V_255 ) ;
V_24 = - V_181 ;
goto V_52;
}
V_253 = V_34 -> V_256 << 16 ;
V_254 = V_34 -> V_257 << 16 ;
if ( V_252 -> V_258 > V_253 ||
V_252 -> V_259 > V_253 - V_252 -> V_258 ||
V_252 -> V_260 > V_254 ||
V_252 -> V_261 > V_254 - V_252 -> V_260 ) {
F_37 ( L_37
L_38 ,
V_252 -> V_258 >> 16 ,
( ( V_252 -> V_258 & 0xffff ) * 15625 ) >> 10 ,
V_252 -> V_260 >> 16 ,
( ( V_252 -> V_260 & 0xffff ) * 15625 ) >> 10 ,
V_252 -> V_259 >> 16 ,
( ( V_252 -> V_259 & 0xffff ) * 15625 ) >> 10 ,
V_252 -> V_261 >> 16 ,
( ( V_252 -> V_261 & 0xffff ) * 15625 ) >> 10 ) ;
V_24 = - V_262 ;
goto V_52;
}
if ( V_252 -> V_263 > V_161 ||
V_252 -> V_264 > V_161 - ( V_265 ) V_252 -> V_263 ||
V_252 -> V_266 > V_161 ||
V_252 -> V_267 > V_161 - ( V_265 ) V_252 -> V_266 ) {
F_37 ( L_39 ,
V_252 -> V_263 , V_252 -> V_266 ,
V_252 -> V_264 , V_252 -> V_267 ) ;
V_24 = - V_162 ;
goto V_52;
}
V_24 = V_44 -> V_36 -> V_268 ( V_44 , V_42 , V_34 ,
V_252 -> V_264 , V_252 -> V_267 ,
V_252 -> V_263 , V_252 -> V_266 ,
V_252 -> V_259 , V_252 -> V_261 ,
V_252 -> V_258 , V_252 -> V_260 ) ;
if ( ! V_24 ) {
V_44 -> V_42 = V_42 ;
V_44 -> V_34 = V_34 ;
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_81 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_240 * V_241 = & V_19 -> V_26 ;
struct V_199 * V_269 = V_163 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
struct V_9 * * V_270 = NULL , * V_10 ;
struct V_33 * V_34 = NULL ;
struct V_57 * V_58 = NULL ;
struct V_45 V_46 ;
T_1 T_2 * V_271 ;
int V_24 ;
int V_102 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
if ( V_269 -> V_201 > V_161 || V_269 -> V_202 > V_161 )
return - V_162 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_269 -> V_176 ,
V_51 ) ;
if ( ! V_21 ) {
F_37 ( L_40 , V_269 -> V_176 ) ;
V_24 = - V_181 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
F_37 ( L_28 , V_42 -> V_7 . V_8 ) ;
if ( V_269 -> V_205 ) {
if ( V_269 -> V_175 == - 1 ) {
if ( ! V_42 -> V_34 ) {
F_37 ( L_41 ) ;
V_24 = - V_181 ;
goto V_52;
}
V_34 = V_42 -> V_34 ;
} else {
V_21 = F_12 ( V_19 , V_269 -> V_175 ,
V_37 ) ;
if ( ! V_21 ) {
F_37 ( L_42 ,
V_269 -> V_175 ) ;
V_24 = - V_181 ;
goto V_52;
}
V_34 = F_80 ( V_21 ) ;
}
V_58 = F_40 ( V_19 ) ;
if ( ! V_58 ) {
V_24 = - V_29 ;
goto V_52;
}
V_24 = F_64 ( V_58 , & V_269 -> V_58 ) ;
if ( V_24 ) {
F_37 ( L_43 ) ;
goto V_52;
}
F_82 ( V_58 , V_272 ) ;
if ( V_58 -> V_147 > V_34 -> V_256 ||
V_58 -> V_153 > V_34 -> V_257 ||
V_269 -> V_201 > V_34 -> V_256 - V_58 -> V_147 ||
V_269 -> V_202 > V_34 -> V_257 - V_58 -> V_153 ) {
F_37 ( L_44 ,
V_58 -> V_147 , V_58 -> V_153 ,
V_269 -> V_201 , V_269 -> V_202 ,
V_34 -> V_256 , V_34 -> V_257 ) ;
V_24 = - V_262 ;
goto V_52;
}
}
if ( V_269 -> V_196 == 0 && V_58 ) {
F_37 ( L_45 ) ;
V_24 = - V_181 ;
goto V_52;
}
if ( V_269 -> V_196 > 0 && ( ! V_58 || ! V_34 ) ) {
F_37 ( L_46 ,
V_269 -> V_196 ) ;
V_24 = - V_181 ;
goto V_52;
}
if ( V_269 -> V_196 > 0 ) {
T_4 V_273 ;
if ( V_269 -> V_196 > V_241 -> V_67 ) {
V_24 = - V_181 ;
goto V_52;
}
V_270 = F_36 ( V_269 -> V_196 *
sizeof( struct V_9 * ) ,
V_28 ) ;
if ( ! V_270 ) {
V_24 = - V_29 ;
goto V_52;
}
for ( V_102 = 0 ; V_102 < V_269 -> V_196 ; V_102 ++ ) {
V_271 = ( T_1 T_2 * ) ( unsigned long ) V_269 -> V_271 ;
if ( F_83 ( V_273 , & V_271 [ V_102 ] ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_21 = F_12 ( V_19 , V_273 ,
V_61 ) ;
if ( ! V_21 ) {
F_37 ( L_47 ,
V_273 ) ;
V_24 = - V_181 ;
goto V_52;
}
V_10 = F_72 ( V_21 ) ;
F_37 ( L_30 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
V_270 [ V_102 ] = V_10 ;
}
}
V_46 . V_42 = V_42 ;
V_46 . V_201 = V_269 -> V_201 ;
V_46 . V_202 = V_269 -> V_202 ;
V_46 . V_58 = V_58 ;
V_46 . V_274 = V_270 ;
V_46 . V_135 = V_269 -> V_196 ;
V_46 . V_34 = V_34 ;
V_24 = V_42 -> V_36 -> V_47 ( & V_46 ) ;
V_52:
F_22 ( V_270 ) ;
F_25 ( V_19 , V_58 ) ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_84 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_275 * V_276 = V_163 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
if ( ! V_276 -> V_159 || ( ~ V_277 & V_276 -> V_159 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_276 -> V_176 , V_51 ) ;
if ( ! V_21 ) {
F_37 ( L_40 , V_276 -> V_176 ) ;
V_24 = - V_181 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
if ( V_276 -> V_159 & V_278 ) {
if ( ! V_42 -> V_36 -> V_279 ) {
V_24 = - V_280 ;
goto V_52;
}
V_24 = V_42 -> V_36 -> V_279 ( V_42 , V_165 , V_276 -> V_281 ,
V_276 -> V_256 , V_276 -> V_257 ) ;
}
if ( V_276 -> V_159 & V_282 ) {
if ( V_42 -> V_36 -> V_283 ) {
V_24 = V_42 -> V_36 -> V_283 ( V_42 , V_276 -> V_201 , V_276 -> V_202 ) ;
} else {
V_24 = - V_191 ;
goto V_52;
}
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
T_1 F_85 ( T_1 V_284 , T_1 V_285 )
{
T_1 V_286 ;
switch ( V_284 ) {
case 8 :
V_286 = V_287 ;
break;
case 16 :
if ( V_285 == 15 )
V_286 = V_288 ;
else
V_286 = V_289 ;
break;
case 24 :
V_286 = V_290 ;
break;
case 32 :
if ( V_285 == 24 )
V_286 = V_291 ;
else if ( V_285 == 30 )
V_286 = V_292 ;
else
V_286 = V_293 ;
break;
default:
F_6 ( L_48 ) ;
V_286 = V_291 ;
break;
}
return V_286 ;
}
int F_86 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_294 * V_295 = V_163 ;
struct V_296 V_297 = {} ;
struct V_240 * V_241 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
V_297 . V_175 = V_295 -> V_175 ;
V_297 . V_256 = V_295 -> V_256 ;
V_297 . V_257 = V_295 -> V_257 ;
V_297 . V_298 [ 0 ] = V_295 -> V_299 ;
V_297 . V_255 = F_85 ( V_295 -> V_284 , V_295 -> V_285 ) ;
V_297 . V_300 [ 0 ] = V_295 -> V_281 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
if ( ( V_241 -> V_188 > V_297 . V_256 ) || ( V_297 . V_256 > V_241 -> V_187 ) )
return - V_181 ;
if ( ( V_241 -> V_186 > V_297 . V_257 ) || ( V_297 . V_257 > V_241 -> V_185 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_301 ( V_19 , V_165 , & V_297 ) ;
if ( F_87 ( V_34 ) ) {
F_37 ( L_49 ) ;
V_24 = F_88 ( V_34 ) ;
goto V_52;
}
V_295 -> V_175 = V_34 -> V_7 . V_8 ;
F_15 ( & V_34 -> V_302 , & V_165 -> V_303 ) ;
F_37 ( L_50 , V_34 -> V_7 . V_8 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
static int F_89 ( const struct V_296 * V_297 )
{
T_1 V_304 = V_297 -> V_255 & ~ V_305 ;
switch ( V_304 ) {
case V_306 :
case V_287 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_288 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_289 :
case V_323 :
case V_290 :
case V_324 :
case V_291 :
case V_325 :
case V_326 :
case V_327 :
case V_293 :
case V_328 :
case V_329 :
case V_330 :
case V_292 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
return 0 ;
default:
return - V_181 ;
}
}
static int F_90 ( const struct V_296 * V_297 )
{
int V_24 , V_357 , V_358 , V_359 , V_102 ;
V_24 = F_89 ( V_297 ) ;
if ( V_24 ) {
F_37 ( L_51 , V_297 -> V_255 ) ;
return V_24 ;
}
V_357 = F_91 ( V_297 -> V_255 ) ;
V_358 = F_92 ( V_297 -> V_255 ) ;
V_359 = F_93 ( V_297 -> V_255 ) ;
if ( V_297 -> V_256 == 0 || V_297 -> V_256 % V_357 ) {
F_37 ( L_52 , V_297 -> V_257 ) ;
return - V_181 ;
}
if ( V_297 -> V_257 == 0 || V_297 -> V_257 % V_358 ) {
F_37 ( L_53 , V_297 -> V_257 ) ;
return - V_181 ;
}
for ( V_102 = 0 ; V_102 < V_359 ; V_102 ++ ) {
unsigned int V_256 = V_297 -> V_256 / ( V_102 != 0 ? V_357 : 1 ) ;
if ( ! V_297 -> V_300 [ V_102 ] ) {
F_37 ( L_54 , V_102 ) ;
return - V_181 ;
}
if ( V_297 -> V_298 [ V_102 ] < F_94 ( V_297 -> V_255 , V_102 ) * V_256 ) {
F_37 ( L_55 , V_297 -> V_298 [ V_102 ] , V_102 ) ;
return - V_181 ;
}
}
return 0 ;
}
int F_95 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_296 * V_297 = V_163 ;
struct V_240 * V_241 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
if ( ( V_241 -> V_188 > V_297 -> V_256 ) || ( V_297 -> V_256 > V_241 -> V_187 ) ) {
F_37 ( L_56 ,
V_297 -> V_256 , V_241 -> V_188 , V_241 -> V_187 ) ;
return - V_181 ;
}
if ( ( V_241 -> V_186 > V_297 -> V_257 ) || ( V_297 -> V_257 > V_241 -> V_185 ) ) {
F_37 ( L_57 ,
V_297 -> V_257 , V_241 -> V_186 , V_241 -> V_185 ) ;
return - V_181 ;
}
V_24 = F_90 ( V_297 ) ;
if ( V_24 )
return V_24 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_301 ( V_19 , V_165 , V_297 ) ;
if ( F_87 ( V_34 ) ) {
F_37 ( L_49 ) ;
V_24 = F_88 ( V_34 ) ;
goto V_52;
}
V_297 -> V_175 = V_34 -> V_7 . V_8 ;
F_15 ( & V_34 -> V_302 , & V_165 -> V_303 ) ;
F_37 ( L_50 , V_34 -> V_7 . V_8 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_96 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_20 * V_21 ;
struct V_33 * V_34 = NULL ;
struct V_33 * V_360 = NULL ;
T_1 * V_8 = V_163 ;
int V_24 = 0 ;
int V_361 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , * V_8 , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
V_34 = F_80 ( V_21 ) ;
F_17 (fbl, &file_priv->fbs, filp_head)
if ( V_34 == V_360 )
V_361 = 1 ;
if ( ! V_361 ) {
V_24 = - V_181 ;
goto V_52;
}
F_18 ( & V_34 -> V_302 ) ;
V_34 -> V_36 -> V_144 ( V_34 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_97 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_294 * V_297 = V_163 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_297 -> V_175 , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
V_34 = F_80 ( V_21 ) ;
V_297 -> V_257 = V_34 -> V_257 ;
V_297 -> V_256 = V_34 -> V_256 ;
V_297 -> V_285 = V_34 -> V_285 ;
V_297 -> V_284 = V_34 -> V_362 ;
V_297 -> V_299 = V_34 -> V_298 [ 0 ] ;
V_34 -> V_36 -> V_363 ( V_34 , V_165 , & V_297 -> V_281 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_98 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_364 T_2 * V_365 ;
struct V_364 * V_366 = NULL ;
struct V_367 * V_297 = V_163 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
unsigned V_159 ;
int V_368 ;
int V_24 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_297 -> V_175 , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_369;
}
V_34 = F_80 ( V_21 ) ;
V_368 = V_297 -> V_368 ;
V_365 = (struct V_364 T_2 * ) ( unsigned long ) V_297 -> V_365 ;
if ( ! V_368 != ! V_365 ) {
V_24 = - V_181 ;
goto V_369;
}
V_159 = V_370 & V_297 -> V_159 ;
if ( V_159 & V_371 && ( V_368 % 2 ) ) {
V_24 = - V_181 ;
goto V_369;
}
if ( V_368 && V_365 ) {
if ( V_368 < 0 || V_368 > V_372 ) {
V_24 = - V_181 ;
goto V_369;
}
V_366 = F_41 ( V_368 * sizeof( * V_366 ) , V_28 ) ;
if ( ! V_366 ) {
V_24 = - V_29 ;
goto V_369;
}
V_24 = F_99 ( V_366 , V_365 ,
V_368 * sizeof( * V_366 ) ) ;
if ( V_24 ) {
V_24 = - V_191 ;
goto V_373;
}
}
if ( V_34 -> V_36 -> V_374 ) {
V_24 = V_34 -> V_36 -> V_374 ( V_34 , V_165 , V_159 , V_297 -> V_375 ,
V_366 , V_368 ) ;
} else {
V_24 = - V_376 ;
goto V_373;
}
V_373:
F_22 ( V_366 ) ;
V_369:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_100 ( struct V_164 * V_80 )
{
struct V_18 * V_19 = V_80 -> V_183 -> V_19 ;
struct V_33 * V_34 , * V_377 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_30 (fb, tfb, &priv->fbs, filp_head) {
F_18 ( & V_34 -> V_302 ) ;
V_34 -> V_36 -> V_144 ( V_34 ) ;
}
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
static void F_101 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_57 * V_58 )
{
F_20 ( & V_58 -> V_39 , & V_10 -> V_63 ) ;
}
int F_102 ( struct V_18 * V_19 , struct V_41 * V_42 ,
const struct V_57 * V_58 )
{
struct V_9 * V_10 ;
int V_24 = 0 ;
struct V_57 * V_378 , * V_379 ;
F_103 ( V_380 ) ;
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
continue;
if ( V_10 -> V_2 -> V_42 == V_42 ) {
V_378 = F_104 ( V_19 , V_58 ) ;
if ( ! V_378 ) {
V_24 = - V_29 ;
goto V_52;
}
F_20 ( & V_378 -> V_39 , & V_380 ) ;
}
}
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
continue;
if ( V_10 -> V_2 -> V_42 == V_42 )
F_105 ( V_380 . V_379 , & V_10 -> V_63 ) ;
}
F_106 ( ! F_39 ( & V_380 ) ) ;
V_52:
F_30 (dup_mode, next, &list, head)
F_25 ( V_19 , V_378 ) ;
return V_24 ;
}
static int F_107 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_57 * V_58 )
{
int V_361 = 0 ;
int V_24 = 0 ;
struct V_57 * V_381 , * V_71 ;
F_30 (match_mode, t, &connector->user_modes, head) {
if ( F_108 ( V_381 , V_58 ) ) {
F_18 ( & V_381 -> V_39 ) ;
F_25 ( V_19 , V_381 ) ;
V_361 = 1 ;
break;
}
}
if ( ! V_361 )
V_24 = - V_181 ;
return V_24 ;
}
int F_109 ( struct V_18 * V_19 , struct V_57 * V_58 )
{
struct V_9 * V_10 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
F_107 ( V_19 , V_10 , V_58 ) ;
}
return 0 ;
}
int F_110 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_382 * V_383 = V_163 ;
struct V_9 * V_10 ;
struct V_57 * V_58 ;
struct V_20 * V_21 ;
struct V_145 * V_384 = & V_383 -> V_58 ;
int V_24 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_383 -> V_177 , V_61 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
V_10 = F_72 ( V_21 ) ;
V_58 = F_40 ( V_19 ) ;
if ( ! V_58 ) {
V_24 = - V_29 ;
goto V_52;
}
V_24 = F_64 ( V_58 , V_384 ) ;
if ( V_24 ) {
F_37 ( L_43 ) ;
F_25 ( V_19 , V_58 ) ;
goto V_52;
}
F_101 ( V_19 , V_10 , V_58 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_111 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_20 * V_21 ;
struct V_382 * V_383 = V_163 ;
struct V_9 * V_10 ;
struct V_57 V_58 ;
struct V_145 * V_384 = & V_383 -> V_58 ;
int V_24 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_383 -> V_177 , V_61 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
V_10 = F_72 ( V_21 ) ;
V_24 = F_64 ( & V_58 , V_384 ) ;
if ( V_24 ) {
F_37 ( L_43 ) ;
goto V_52;
}
V_24 = F_107 ( V_19 , V_10 , & V_58 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
struct V_87 * F_43 ( struct V_18 * V_19 , int V_159 ,
const char * V_6 , int V_385 )
{
struct V_87 * V_141 = NULL ;
int V_24 ;
V_141 = F_41 ( sizeof( struct V_87 ) , V_28 ) ;
if ( ! V_141 )
return NULL ;
if ( V_385 ) {
V_141 -> V_233 = F_41 ( sizeof( T_3 ) * V_385 , V_28 ) ;
if ( ! V_141 -> V_233 )
goto V_386;
}
V_24 = F_4 ( V_19 , & V_141 -> V_7 , V_387 ) ;
if ( V_24 )
goto V_386;
V_141 -> V_159 = V_159 ;
V_141 -> V_385 = V_385 ;
F_27 ( & V_141 -> V_388 ) ;
if ( V_6 ) {
strncpy ( V_141 -> V_6 , V_6 , V_389 ) ;
V_141 -> V_6 [ V_389 - 1 ] = '\0' ;
}
F_20 ( & V_141 -> V_39 , & V_19 -> V_26 . V_128 ) ;
return V_141 ;
V_386:
F_22 ( V_141 -> V_233 ) ;
F_22 ( V_141 ) ;
return NULL ;
}
struct V_87 * F_44 ( struct V_18 * V_19 , int V_159 ,
const char * V_6 ,
const struct V_390 * V_391 ,
int V_385 )
{
struct V_87 * V_141 ;
int V_102 , V_24 ;
V_159 |= V_112 ;
V_141 = F_43 ( V_19 , V_159 , V_6 , V_385 ) ;
if ( ! V_141 )
return NULL ;
for ( V_102 = 0 ; V_102 < V_385 ; V_102 ++ ) {
V_24 = F_49 ( V_141 , V_102 ,
V_391 [ V_102 ] . type ,
V_391 [ V_102 ] . V_6 ) ;
if ( V_24 ) {
F_59 ( V_19 , V_141 ) ;
return NULL ;
}
}
return V_141 ;
}
struct V_87 * F_112 ( struct V_18 * V_19 ,
int V_159 , const char * V_6 ,
const struct V_390 * V_391 ,
int V_385 )
{
struct V_87 * V_141 ;
int V_102 , V_24 ;
V_159 |= V_392 ;
V_141 = F_43 ( V_19 , V_159 , V_6 , V_385 ) ;
if ( ! V_141 )
return NULL ;
for ( V_102 = 0 ; V_102 < V_385 ; V_102 ++ ) {
V_24 = F_49 ( V_141 , V_102 ,
V_391 [ V_102 ] . type ,
V_391 [ V_102 ] . V_6 ) ;
if ( V_24 ) {
F_59 ( V_19 , V_141 ) ;
return NULL ;
}
}
return V_141 ;
}
struct V_87 * F_48 ( struct V_18 * V_19 , int V_159 ,
const char * V_6 ,
T_3 V_393 , T_3 V_394 )
{
struct V_87 * V_141 ;
V_159 |= V_395 ;
V_141 = F_43 ( V_19 , V_159 , V_6 , 2 ) ;
if ( ! V_141 )
return NULL ;
V_141 -> V_233 [ 0 ] = V_393 ;
V_141 -> V_233 [ 1 ] = V_394 ;
return V_141 ;
}
int F_49 ( struct V_87 * V_141 , int V_396 ,
T_3 V_397 , const char * V_6 )
{
struct V_398 * V_399 ;
if ( ! ( V_141 -> V_159 & ( V_112 | V_392 ) ) )
return - V_181 ;
if ( ( V_141 -> V_159 & V_392 ) && ( V_397 > 63 ) )
return - V_181 ;
if ( ! F_39 ( & V_141 -> V_388 ) ) {
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( V_399 -> V_397 == V_397 ) {
strncpy ( V_399 -> V_6 , V_6 , V_389 ) ;
V_399 -> V_6 [ V_389 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_399 = F_41 ( sizeof( struct V_398 ) , V_28 ) ;
if ( ! V_399 )
return - V_29 ;
strncpy ( V_399 -> V_6 , V_6 , V_389 ) ;
V_399 -> V_6 [ V_389 - 1 ] = '\0' ;
V_399 -> V_397 = V_397 ;
V_141 -> V_233 [ V_396 ] = V_397 ;
F_20 ( & V_399 -> V_39 , & V_141 -> V_388 ) ;
return 0 ;
}
void F_59 ( struct V_18 * V_19 , struct V_87 * V_141 )
{
struct V_398 * V_399 , * V_142 ;
F_30 (prop_enum, pt, &property->enum_blob_list, head) {
F_18 ( & V_399 -> V_39 ) ;
F_22 ( V_399 ) ;
}
if ( V_141 -> V_385 )
F_22 ( V_141 -> V_233 ) ;
F_10 ( V_19 , & V_141 -> V_7 ) ;
F_18 ( & V_141 -> V_39 ) ;
F_22 ( V_141 ) ;
}
void F_28 ( struct V_9 * V_10 ,
struct V_87 * V_141 , T_3 V_400 )
{
F_113 ( & V_10 -> V_7 , V_141 , V_400 ) ;
}
int F_114 ( struct V_9 * V_10 ,
struct V_87 * V_141 , T_3 V_397 )
{
return F_115 ( & V_10 -> V_7 , V_141 , V_397 ) ;
}
int F_116 ( struct V_9 * V_10 ,
struct V_87 * V_141 , T_3 * V_401 )
{
return F_117 ( & V_10 -> V_7 , V_141 , V_401 ) ;
}
void F_113 ( struct V_20 * V_21 ,
struct V_87 * V_141 ,
T_3 V_400 )
{
int V_62 = V_21 -> V_53 -> V_62 ;
if ( V_62 == V_402 ) {
F_63 ( 1 , L_58
L_59
L_60 ,
V_21 -> type ) ;
return;
}
V_21 -> V_53 -> V_232 [ V_62 ] = V_141 -> V_7 . V_8 ;
V_21 -> V_53 -> V_233 [ V_62 ] = V_400 ;
V_21 -> V_53 -> V_62 ++ ;
}
int F_115 ( struct V_20 * V_21 ,
struct V_87 * V_141 , T_3 V_401 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_21 -> V_53 -> V_62 ; V_102 ++ ) {
if ( V_21 -> V_53 -> V_232 [ V_102 ] == V_141 -> V_7 . V_8 ) {
V_21 -> V_53 -> V_233 [ V_102 ] = V_401 ;
return 0 ;
}
}
return - V_181 ;
}
int F_117 ( struct V_20 * V_21 ,
struct V_87 * V_141 , T_3 * V_401 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_21 -> V_53 -> V_62 ; V_102 ++ ) {
if ( V_21 -> V_53 -> V_232 [ V_102 ] == V_141 -> V_7 . V_8 ) {
* V_401 = V_21 -> V_53 -> V_233 [ V_102 ] ;
return 0 ;
}
}
return - V_181 ;
}
int F_118 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_20 * V_21 ;
struct V_403 * V_207 = V_163 ;
struct V_87 * V_141 ;
int V_404 = 0 ;
int V_405 = 0 ;
int V_406 = 0 ;
int V_24 = 0 , V_102 ;
int V_174 ;
struct V_398 * V_399 ;
struct V_407 T_2 * V_408 ;
struct V_409 * V_410 ;
T_1 T_2 * V_411 ;
T_3 T_2 * V_412 ;
T_1 T_2 * V_413 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_207 -> V_414 , V_387 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_415;
}
V_141 = F_119 ( V_21 ) ;
if ( V_141 -> V_159 & ( V_112 | V_392 ) ) {
F_17 (prop_enum, &property->enum_blob_list, head)
V_404 ++ ;
} else if ( V_141 -> V_159 & V_90 ) {
F_17 (prop_blob, &property->enum_blob_list, head)
V_405 ++ ;
}
V_406 = V_141 -> V_385 ;
strncpy ( V_207 -> V_6 , V_141 -> V_6 , V_389 ) ;
V_207 -> V_6 [ V_389 - 1 ] = 0 ;
V_207 -> V_159 = V_141 -> V_159 ;
if ( ( V_207 -> V_416 >= V_406 ) && V_406 ) {
V_412 = ( T_3 T_2 * ) ( unsigned long ) V_207 -> V_412 ;
for ( V_102 = 0 ; V_102 < V_406 ; V_102 ++ ) {
if ( F_73 ( V_412 + V_102 , & V_141 -> V_233 [ V_102 ] , sizeof( T_3 ) ) ) {
V_24 = - V_191 ;
goto V_415;
}
}
}
V_207 -> V_416 = V_406 ;
if ( V_141 -> V_159 & ( V_112 | V_392 ) ) {
if ( ( V_207 -> V_417 >= V_404 ) && V_404 ) {
V_174 = 0 ;
V_408 = (struct V_407 T_2 * ) ( unsigned long ) V_207 -> V_418 ;
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( F_73 ( & V_408 [ V_174 ] . V_397 , & V_399 -> V_397 , sizeof( T_3 ) ) ) {
V_24 = - V_191 ;
goto V_415;
}
if ( F_73 ( & V_408 [ V_174 ] . V_6 ,
& V_399 -> V_6 , V_389 ) ) {
V_24 = - V_191 ;
goto V_415;
}
V_174 ++ ;
}
}
V_207 -> V_417 = V_404 ;
}
if ( V_141 -> V_159 & V_90 ) {
if ( ( V_207 -> V_417 >= V_405 ) && V_405 ) {
V_174 = 0 ;
V_411 = ( T_1 T_2 * ) ( unsigned long ) V_207 -> V_418 ;
V_413 = ( T_1 T_2 * ) ( unsigned long ) V_207 -> V_412 ;
F_17 (prop_blob, &property->enum_blob_list, head) {
if ( F_68 ( V_410 -> V_7 . V_8 , V_411 + V_174 ) ) {
V_24 = - V_191 ;
goto V_415;
}
if ( F_68 ( V_410 -> V_419 , V_413 + V_174 ) ) {
V_24 = - V_191 ;
goto V_415;
}
V_174 ++ ;
}
}
V_207 -> V_417 = V_405 ;
}
V_415:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
static struct V_409 * F_120 ( struct V_18 * V_19 , int V_419 ,
void * V_163 )
{
struct V_409 * V_420 ;
int V_24 ;
if ( ! V_419 || ! V_163 )
return NULL ;
V_420 = F_41 ( sizeof( struct V_409 ) + V_419 , V_28 ) ;
if ( ! V_420 )
return NULL ;
V_24 = F_4 ( V_19 , & V_420 -> V_7 , V_421 ) ;
if ( V_24 ) {
F_22 ( V_420 ) ;
return NULL ;
}
V_420 -> V_419 = V_419 ;
memcpy ( V_420 -> V_163 , V_163 , V_419 ) ;
F_20 ( & V_420 -> V_39 , & V_19 -> V_26 . V_129 ) ;
return V_420 ;
}
static void F_121 ( struct V_18 * V_19 ,
struct V_409 * V_420 )
{
F_10 ( V_19 , & V_420 -> V_7 ) ;
F_18 ( & V_420 -> V_39 ) ;
F_22 ( V_420 ) ;
}
int F_122 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_20 * V_21 ;
struct V_422 * V_207 = V_163 ;
struct V_409 * V_420 ;
int V_24 = 0 ;
void T_2 * V_423 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_207 -> V_424 , V_421 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_415;
}
V_420 = F_123 ( V_21 ) ;
if ( V_207 -> V_419 == V_420 -> V_419 ) {
V_423 = ( void T_2 * ) ( unsigned long ) V_207 -> V_163 ;
if ( F_73 ( V_423 , V_420 -> V_163 , V_420 -> V_419 ) ) {
V_24 = - V_191 ;
goto V_415;
}
}
V_207 -> V_419 = V_420 -> V_419 ;
V_415:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_124 ( struct V_9 * V_10 ,
struct V_88 * V_88 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
int V_24 , V_425 ;
if ( V_10 -> V_65 )
F_121 ( V_19 , V_10 -> V_65 ) ;
if ( ! V_88 ) {
V_10 -> V_65 = NULL ;
V_24 = F_114 ( V_10 , V_19 -> V_26 . V_69 , 0 ) ;
return V_24 ;
}
V_425 = V_426 * ( 1 + V_88 -> V_427 ) ;
V_10 -> V_65 = F_120 ( V_10 -> V_19 ,
V_425 , V_88 ) ;
V_24 = F_114 ( V_10 ,
V_19 -> V_26 . V_69 ,
V_10 -> V_65 -> V_7 . V_8 ) ;
return V_24 ;
}
static bool F_125 ( struct V_87 * V_141 ,
T_3 V_397 )
{
if ( V_141 -> V_159 & V_91 )
return false ;
if ( V_141 -> V_159 & V_395 ) {
if ( V_397 < V_141 -> V_233 [ 0 ] || V_397 > V_141 -> V_233 [ 1 ] )
return false ;
return true ;
} else if ( V_141 -> V_159 & V_392 ) {
int V_102 ;
T_3 V_428 = 0 ;
for ( V_102 = 0 ; V_102 < V_141 -> V_385 ; V_102 ++ )
V_428 |= ( 1ULL << V_141 -> V_233 [ V_102 ] ) ;
return ! ( V_397 & ~ V_428 ) ;
} else {
int V_102 ;
for ( V_102 = 0 ; V_102 < V_141 -> V_385 ; V_102 ++ )
if ( V_141 -> V_233 [ V_102 ] == V_397 )
return true ;
return false ;
}
}
int F_126 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_429 * V_430 = V_163 ;
struct V_431 V_432 = {
. V_397 = V_430 -> V_397 ,
. V_414 = V_430 -> V_414 ,
. V_433 = V_430 -> V_177 ,
. V_22 = V_61
} ;
return F_127 ( V_19 , & V_432 , V_165 ) ;
}
static int F_128 ( struct V_20 * V_21 ,
struct V_87 * V_141 ,
T_3 V_397 )
{
int V_24 = - V_181 ;
struct V_9 * V_10 = F_72 ( V_21 ) ;
if ( V_141 == V_10 -> V_19 -> V_26 . V_70 ) {
if ( V_10 -> V_36 -> V_89 )
(* V_10 -> V_36 -> V_89 )( V_10 , ( int ) V_397 ) ;
V_24 = 0 ;
} else if ( V_10 -> V_36 -> V_434 )
V_24 = V_10 -> V_36 -> V_434 ( V_10 , V_141 , V_397 ) ;
if ( ! V_24 )
F_114 ( V_10 , V_141 , V_397 ) ;
return V_24 ;
}
static int F_129 ( struct V_20 * V_21 ,
struct V_87 * V_141 ,
T_3 V_397 )
{
int V_24 = - V_181 ;
struct V_41 * V_42 = F_70 ( V_21 ) ;
if ( V_42 -> V_36 -> V_434 )
V_24 = V_42 -> V_36 -> V_434 ( V_42 , V_141 , V_397 ) ;
if ( ! V_24 )
F_115 ( V_21 , V_141 , V_397 ) ;
return V_24 ;
}
static int F_130 ( struct V_20 * V_21 ,
struct V_87 * V_141 ,
T_3 V_397 )
{
int V_24 = - V_181 ;
struct V_43 * V_44 = F_78 ( V_21 ) ;
if ( V_44 -> V_36 -> V_434 )
V_24 = V_44 -> V_36 -> V_434 ( V_44 , V_141 , V_397 ) ;
if ( ! V_24 )
F_115 ( V_21 , V_141 , V_397 ) ;
return V_24 ;
}
int F_131 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_435 * V_436 = V_163 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
int V_102 ;
int V_174 = 0 ;
int V_209 = 0 ;
T_1 T_2 * V_230 ;
T_3 T_2 * V_231 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_436 -> V_433 , V_436 -> V_22 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
if ( ! V_21 -> V_53 ) {
V_24 = - V_181 ;
goto V_52;
}
V_209 = V_21 -> V_53 -> V_62 ;
if ( ( V_436 -> V_229 >= V_209 ) && V_209 ) {
V_174 = 0 ;
V_230 = ( T_1 T_2 * ) ( unsigned long ) ( V_436 -> V_230 ) ;
V_231 = ( T_3 T_2 * ) ( unsigned long )
( V_436 -> V_231 ) ;
for ( V_102 = 0 ; V_102 < V_209 ; V_102 ++ ) {
if ( F_68 ( V_21 -> V_53 -> V_232 [ V_102 ] ,
V_230 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
if ( F_68 ( V_21 -> V_53 -> V_233 [ V_102 ] ,
V_231 + V_174 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_174 ++ ;
}
}
V_436 -> V_229 = V_209 ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_127 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_431 * V_436 = V_163 ;
struct V_20 * V_437 ;
struct V_20 * V_438 ;
struct V_87 * V_141 ;
int V_24 = - V_181 ;
int V_102 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_437 = F_12 ( V_19 , V_436 -> V_433 , V_436 -> V_22 ) ;
if ( ! V_437 )
goto V_52;
if ( ! V_437 -> V_53 )
goto V_52;
for ( V_102 = 0 ; V_102 < V_437 -> V_53 -> V_62 ; V_102 ++ )
if ( V_437 -> V_53 -> V_232 [ V_102 ] == V_436 -> V_414 )
break;
if ( V_102 == V_437 -> V_53 -> V_62 )
goto V_52;
V_438 = F_12 ( V_19 , V_436 -> V_414 ,
V_387 ) ;
if ( ! V_438 )
goto V_52;
V_141 = F_119 ( V_438 ) ;
if ( ! F_125 ( V_141 , V_436 -> V_397 ) )
goto V_52;
switch ( V_437 -> type ) {
case V_61 :
V_24 = F_128 ( V_437 , V_141 ,
V_436 -> V_397 ) ;
break;
case V_51 :
V_24 = F_129 ( V_437 , V_141 , V_436 -> V_397 ) ;
break;
case V_81 :
V_24 = F_130 ( V_437 , V_141 , V_436 -> V_397 ) ;
break;
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_132 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_216 ; V_102 ++ ) {
if ( V_10 -> V_217 [ V_102 ] == 0 ) {
V_10 -> V_217 [ V_102 ] = V_2 -> V_7 . V_8 ;
return 0 ;
}
}
return - V_29 ;
}
void F_133 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_216 ; V_102 ++ ) {
if ( V_10 -> V_217 [ V_102 ] == V_2 -> V_7 . V_8 ) {
V_10 -> V_217 [ V_102 ] = 0 ;
if ( V_10 -> V_2 == V_2 )
V_10 -> V_2 = NULL ;
break;
}
}
}
int F_134 ( struct V_41 * V_42 ,
int V_203 )
{
V_42 -> V_203 = V_203 ;
V_42 -> V_56 = F_41 ( V_203 * sizeof( V_439 ) * 3 , V_28 ) ;
if ( ! V_42 -> V_56 ) {
V_42 -> V_203 = 0 ;
return - V_29 ;
}
return 0 ;
}
int F_135 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_440 * V_441 = V_163 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_442 , * V_443 , * V_444 ;
int V_425 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_441 -> V_176 , V_51 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
if ( V_42 -> V_36 -> V_445 == NULL ) {
V_24 = - V_376 ;
goto V_52;
}
if ( V_441 -> V_203 != V_42 -> V_203 ) {
V_24 = - V_181 ;
goto V_52;
}
V_425 = V_441 -> V_203 * ( sizeof( V_439 ) ) ;
V_442 = V_42 -> V_56 ;
if ( F_99 ( V_442 , ( void T_2 * ) ( unsigned long ) V_441 -> V_446 , V_425 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_443 = V_442 + V_425 ;
if ( F_99 ( V_443 , ( void T_2 * ) ( unsigned long ) V_441 -> V_447 , V_425 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_444 = V_443 + V_425 ;
if ( F_99 ( V_444 , ( void T_2 * ) ( unsigned long ) V_441 -> V_448 , V_425 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_42 -> V_36 -> V_445 ( V_42 , V_442 , V_443 , V_444 , 0 , V_42 -> V_203 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_136 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_440 * V_441 = V_163 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_442 , * V_443 , * V_444 ;
int V_425 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_441 -> V_176 , V_51 ) ;
if ( ! V_21 ) {
V_24 = - V_181 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
if ( V_441 -> V_203 != V_42 -> V_203 ) {
V_24 = - V_181 ;
goto V_52;
}
V_425 = V_441 -> V_203 * ( sizeof( V_439 ) ) ;
V_442 = V_42 -> V_56 ;
if ( F_73 ( ( void T_2 * ) ( unsigned long ) V_441 -> V_446 , V_442 , V_425 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_443 = V_442 + V_425 ;
if ( F_73 ( ( void T_2 * ) ( unsigned long ) V_441 -> V_447 , V_443 , V_425 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_444 = V_443 + V_425 ;
if ( F_73 ( ( void T_2 * ) ( unsigned long ) V_441 -> V_448 , V_444 , V_425 ) ) {
V_24 = - V_191 ;
goto V_52;
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_137 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_449 * V_450 = V_163 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
struct V_33 * V_34 ;
struct V_451 * V_452 = NULL ;
unsigned long V_159 ;
int V_24 = - V_181 ;
if ( V_450 -> V_159 & ~ V_453 ||
V_450 -> V_454 != 0 )
return - V_181 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_450 -> V_176 , V_51 ) ;
if ( ! V_21 )
goto V_52;
V_42 = F_70 ( V_21 ) ;
if ( V_42 -> V_34 == NULL ) {
V_24 = - V_455 ;
goto V_52;
}
if ( V_42 -> V_36 -> V_450 == NULL )
goto V_52;
V_21 = F_12 ( V_19 , V_450 -> V_175 , V_37 ) ;
if ( ! V_21 )
goto V_52;
V_34 = F_80 ( V_21 ) ;
if ( V_42 -> V_58 . V_147 > V_34 -> V_256 ||
V_42 -> V_58 . V_153 > V_34 -> V_257 ||
V_42 -> V_201 > V_34 -> V_256 - V_42 -> V_58 . V_147 ||
V_42 -> V_202 > V_34 -> V_257 - V_42 -> V_58 . V_153 ) {
F_37 ( L_61 ,
V_34 -> V_256 , V_34 -> V_257 ,
V_42 -> V_58 . V_147 , V_42 -> V_58 . V_153 ,
V_42 -> V_201 , V_42 -> V_202 ) ;
V_24 = - V_262 ;
goto V_52;
}
if ( V_450 -> V_159 & V_456 ) {
V_24 = - V_29 ;
F_138 ( & V_19 -> V_457 , V_159 ) ;
if ( V_165 -> V_458 < sizeof V_452 -> V_459 ) {
F_139 ( & V_19 -> V_457 , V_159 ) ;
goto V_52;
}
V_165 -> V_458 -= sizeof V_452 -> V_459 ;
F_139 ( & V_19 -> V_457 , V_159 ) ;
V_452 = F_41 ( sizeof *V_452 , V_28 ) ;
if ( V_452 == NULL ) {
F_138 ( & V_19 -> V_457 , V_159 ) ;
V_165 -> V_458 += sizeof V_452 -> V_459 ;
F_139 ( & V_19 -> V_457 , V_159 ) ;
goto V_52;
}
V_452 -> V_459 . V_7 . type = V_460 ;
V_452 -> V_459 . V_7 . V_419 = sizeof V_452 -> V_459 ;
V_452 -> V_459 . V_461 = V_450 -> V_461 ;
V_452 -> V_7 . V_459 = & V_452 -> V_459 . V_7 ;
V_452 -> V_7 . V_165 = V_165 ;
V_452 -> V_7 . V_144 =
( void ( * ) ( struct V_462 * ) ) F_22 ;
}
V_24 = V_42 -> V_36 -> V_450 ( V_42 , V_34 , V_452 ) ;
if ( V_24 ) {
if ( V_450 -> V_159 & V_456 ) {
F_138 ( & V_19 -> V_457 , V_159 ) ;
V_165 -> V_458 += sizeof V_452 -> V_459 ;
F_139 ( & V_19 -> V_457 , V_159 ) ;
F_22 ( V_452 ) ;
}
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_140 ( struct V_18 * V_19 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_17 (crtc, &dev->mode_config.crtc_list, head)
if ( V_42 -> V_36 -> V_463 )
V_42 -> V_36 -> V_463 ( V_42 ) ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
if ( V_2 -> V_36 -> V_463 )
V_2 -> V_36 -> V_463 ( V_2 ) ;
F_17 (connector, &dev->mode_config.connector_list, head)
if ( V_10 -> V_36 -> V_463 )
V_10 -> V_36 -> V_463 ( V_10 ) ;
}
int F_141 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_464 * args = V_163 ;
if ( ! V_19 -> V_465 -> V_466 )
return - V_376 ;
return V_19 -> V_465 -> V_466 ( V_165 , V_19 , args ) ;
}
int F_142 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_467 * args = V_163 ;
if ( ! V_19 -> V_465 -> V_468 )
return - V_376 ;
return V_19 -> V_465 -> V_468 ( V_165 , V_19 , args -> V_281 , & args -> V_469 ) ;
}
int F_143 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_470 * args = V_163 ;
if ( ! V_19 -> V_465 -> V_471 )
return - V_376 ;
return V_19 -> V_465 -> V_471 ( V_165 , V_19 , args -> V_281 ) ;
}
void F_144 ( T_1 V_304 , unsigned int * V_285 ,
int * V_284 )
{
switch ( V_304 ) {
case V_287 :
case V_307 :
* V_285 = 8 ;
* V_284 = 8 ;
break;
case V_288 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
* V_285 = 15 ;
* V_284 = 16 ;
break;
case V_289 :
case V_323 :
* V_285 = 16 ;
* V_284 = 16 ;
break;
case V_290 :
case V_324 :
* V_285 = 24 ;
* V_284 = 24 ;
break;
case V_291 :
case V_325 :
case V_326 :
case V_327 :
* V_285 = 24 ;
* V_284 = 32 ;
break;
case V_292 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
* V_285 = 30 ;
* V_284 = 32 ;
break;
case V_293 :
case V_328 :
case V_329 :
case V_330 :
* V_285 = 32 ;
* V_284 = 32 ;
break;
default:
F_37 ( L_62 ) ;
* V_285 = 0 ;
* V_284 = 0 ;
break;
}
}
int F_93 ( T_1 V_304 )
{
switch ( V_304 ) {
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
return 3 ;
case V_343 :
case V_344 :
case V_345 :
case V_346 :
return 2 ;
default:
return 1 ;
}
}
int F_94 ( T_1 V_304 , int V_44 )
{
unsigned int V_285 ;
int V_284 ;
if ( V_44 >= F_93 ( V_304 ) )
return 0 ;
switch ( V_304 ) {
case V_338 :
case V_339 :
case V_340 :
case V_341 :
return 2 ;
case V_343 :
case V_344 :
case V_345 :
case V_346 :
return V_44 ? 2 : 1 ;
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
return 1 ;
default:
F_144 ( V_304 , & V_285 , & V_284 ) ;
return V_284 >> 3 ;
}
}
int F_91 ( T_1 V_304 )
{
switch ( V_304 ) {
case V_349 :
case V_350 :
case V_347 :
case V_348 :
return 4 ;
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_353 :
case V_354 :
case V_351 :
case V_352 :
return 2 ;
default:
return 1 ;
}
}
int F_92 ( T_1 V_304 )
{
switch ( V_304 ) {
case V_347 :
case V_348 :
return 4 ;
case V_351 :
case V_352 :
case V_343 :
case V_344 :
return 2 ;
default:
return 1 ;
}
}
