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
F_20 ( & V_42 -> V_39 , & V_19 -> V_26 . V_53 ) ;
V_19 -> V_26 . V_54 ++ ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_21 ( struct V_41 * V_42 )
{
struct V_18 * V_19 = V_42 -> V_19 ;
if ( V_42 -> V_55 ) {
F_22 ( V_42 -> V_55 ) ;
V_42 -> V_55 = NULL ;
}
F_10 ( V_19 , & V_42 -> V_7 ) ;
F_18 ( & V_42 -> V_39 ) ;
V_19 -> V_26 . V_54 -- ;
}
void F_23 ( struct V_9 * V_10 ,
struct V_56 * V_57 )
{
F_15 ( & V_57 -> V_39 , & V_10 -> V_58 ) ;
}
void F_24 ( struct V_9 * V_10 ,
struct V_56 * V_57 )
{
F_18 ( & V_57 -> V_39 ) ;
F_25 ( V_10 -> V_19 , V_57 ) ;
}
int F_26 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
const struct V_59 * V_36 ,
int V_12 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_24 = F_4 ( V_19 , & V_10 -> V_7 , V_60 ) ;
if ( V_24 )
goto V_52;
V_10 -> V_19 = V_19 ;
V_10 -> V_36 = V_36 ;
V_10 -> V_12 = V_12 ;
V_10 -> V_13 =
++ V_11 [ V_12 ] . V_61 ;
F_27 ( & V_10 -> V_62 ) ;
F_27 ( & V_10 -> V_58 ) ;
F_27 ( & V_10 -> V_63 ) ;
V_10 -> V_64 = NULL ;
F_20 ( & V_10 -> V_39 , & V_19 -> V_26 . V_65 ) ;
V_19 -> V_26 . V_66 ++ ;
if ( V_12 != V_67 )
F_28 ( V_10 ,
V_19 -> V_26 . V_68 ,
0 ) ;
F_28 ( V_10 ,
V_19 -> V_26 . V_69 , 0 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_29 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
struct V_56 * V_57 , * V_70 ;
F_30 (mode, t, &connector->probed_modes, head)
F_24 ( V_10 , V_57 ) ;
F_30 (mode, t, &connector->modes, head)
F_24 ( V_10 , V_57 ) ;
F_30 (mode, t, &connector->user_modes, head)
F_24 ( V_10 , V_57 ) ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_10 ( V_19 , & V_10 -> V_7 ) ;
F_18 ( & V_10 -> V_39 ) ;
V_19 -> V_26 . V_66 -- ;
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
const struct V_71 * V_36 ,
int V_5 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_24 = F_4 ( V_19 , & V_2 -> V_7 , V_72 ) ;
if ( V_24 )
goto V_52;
V_2 -> V_19 = V_19 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_36 = V_36 ;
F_20 ( & V_2 -> V_39 , & V_19 -> V_26 . V_73 ) ;
V_19 -> V_26 . V_74 ++ ;
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
V_19 -> V_26 . V_74 -- ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
int F_35 ( struct V_18 * V_19 , struct V_43 * V_44 ,
unsigned long V_75 ,
const struct V_76 * V_36 ,
const T_1 * V_77 , T_1 V_78 ,
bool V_79 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_24 = F_4 ( V_19 , & V_44 -> V_7 , V_80 ) ;
if ( V_24 )
goto V_52;
V_44 -> V_19 = V_19 ;
V_44 -> V_36 = V_36 ;
V_44 -> V_81 = F_36 ( sizeof( T_1 ) * V_78 ,
V_28 ) ;
if ( ! V_44 -> V_81 ) {
F_37 ( L_8 ) ;
F_10 ( V_19 , & V_44 -> V_7 ) ;
V_24 = - V_82 ;
goto V_52;
}
memcpy ( V_44 -> V_81 , V_77 , V_78 * sizeof( T_1 ) ) ;
V_44 -> V_78 = V_78 ;
V_44 -> V_75 = V_75 ;
if ( ! V_79 ) {
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
F_22 ( V_44 -> V_81 ) ;
F_10 ( V_19 , & V_44 -> V_7 ) ;
if ( ! F_39 ( & V_44 -> V_39 ) ) {
F_18 ( & V_44 -> V_39 ) ;
V_19 -> V_26 . V_84 -- ;
}
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
struct V_56 * F_40 ( struct V_18 * V_19 )
{
struct V_56 * V_85 ;
V_85 = F_41 ( sizeof( struct V_56 ) , V_28 ) ;
if ( ! V_85 )
return NULL ;
if ( F_4 ( V_19 , & V_85 -> V_7 , V_86 ) ) {
F_22 ( V_85 ) ;
return NULL ;
}
return V_85 ;
}
void F_25 ( struct V_18 * V_19 , struct V_56 * V_57 )
{
if ( ! V_57 )
return;
F_10 ( V_19 , & V_57 -> V_7 ) ;
F_22 ( V_57 ) ;
}
static int F_42 ( struct V_18 * V_19 )
{
struct V_87 * V_88 ;
struct V_87 * V_89 ;
V_88 = F_43 ( V_19 , V_90 |
V_91 ,
L_9 , 0 ) ;
V_19 -> V_26 . V_68 = V_88 ;
V_89 = F_44 ( V_19 , 0 ,
L_10 , V_92 ,
F_45 ( V_92 ) ) ;
V_19 -> V_26 . V_69 = V_89 ;
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
char * V_63 [] )
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
V_102 , V_63 [ V_102 ] ) ;
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
F_27 ( & V_19 -> V_26 . V_53 ) ;
F_27 ( & V_19 -> V_26 . V_65 ) ;
F_27 ( & V_19 -> V_26 . V_73 ) ;
F_27 ( & V_19 -> V_26 . V_128 ) ;
F_27 ( & V_19 -> V_26 . V_129 ) ;
F_27 ( & V_19 -> V_26 . V_83 ) ;
F_55 ( & V_19 -> V_26 . V_27 ) ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_42 ( V_19 ) ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
V_19 -> V_26 . V_38 = 0 ;
V_19 -> V_26 . V_66 = 0 ;
V_19 -> V_26 . V_54 = 0 ;
V_19 -> V_26 . V_74 = 0 ;
}
int F_56 ( struct V_18 * V_19 , struct V_130 * V_131 )
{
T_1 V_132 = 0 ;
V_132 += V_19 -> V_26 . V_54 ;
V_132 += V_19 -> V_26 . V_66 ;
V_132 += V_19 -> V_26 . V_74 ;
V_131 -> V_133 = F_41 ( V_132 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_131 -> V_133 )
return - V_82 ;
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
const struct V_56 * V_146 )
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
static int F_64 ( struct V_56 * V_52 ,
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
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_67 (lh, &file_priv->fbs)
V_172 ++ ;
V_179 = & V_165 -> V_181 -> V_182 -> V_179 ;
if ( V_165 -> V_181 -> V_182 -> type == V_183 ) {
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
V_167 -> V_184 = V_19 -> V_26 . V_184 ;
V_167 -> V_185 = V_19 -> V_26 . V_185 ;
V_167 -> V_186 = V_19 -> V_26 . V_186 ;
V_167 -> V_187 = V_19 -> V_26 . V_187 ;
if ( V_167 -> V_188 >= V_172 ) {
V_174 = 0 ;
V_175 = ( T_1 T_2 * ) ( unsigned long ) V_167 -> V_189 ;
F_17 (fb, &file_priv->fbs, filp_head) {
if ( F_68 ( V_34 -> V_7 . V_8 , V_175 + V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
}
V_167 -> V_188 = V_172 ;
if ( V_167 -> V_191 >= V_171 ) {
V_174 = 0 ;
V_176 = ( T_1 T_2 * ) ( unsigned long ) V_167 -> V_192 ;
if ( V_165 -> V_181 -> V_182 -> type == V_183 ) {
F_17 (crtc, &dev->mode_config.crtc_list,
head) {
F_37 ( L_28 , V_42 -> V_7 . V_8 ) ;
if ( F_68 ( V_42 -> V_7 . V_8 , V_176 + V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
} else {
for ( V_102 = 0 ; V_102 < V_179 -> V_134 ; V_102 ++ ) {
if ( F_68 ( V_179 -> V_133 [ V_102 ] ,
V_176 + V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
}
}
V_167 -> V_191 = V_171 ;
if ( V_167 -> V_193 >= V_173 ) {
V_174 = 0 ;
V_178 = ( T_1 T_2 * ) ( unsigned long ) V_167 -> V_194 ;
if ( V_165 -> V_181 -> V_182 -> type == V_183 ) {
F_17 (encoder,
&dev->mode_config.encoder_list,
head) {
F_37 ( L_29 , V_2 -> V_7 . V_8 ,
F_1 ( V_2 ) ) ;
if ( F_68 ( V_2 -> V_7 . V_8 , V_178 +
V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
} else {
for ( V_102 = V_179 -> V_134 ; V_102 < V_179 -> V_134 + V_179 -> V_136 ; V_102 ++ ) {
if ( F_68 ( V_179 -> V_133 [ V_102 ] ,
V_178 + V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
}
}
V_167 -> V_193 = V_173 ;
if ( V_167 -> V_195 >= V_170 ) {
V_174 = 0 ;
V_177 = ( T_1 T_2 * ) ( unsigned long ) V_167 -> V_196 ;
if ( V_165 -> V_181 -> V_182 -> type == V_183 ) {
F_17 (connector,
&dev->mode_config.connector_list,
head) {
F_37 ( L_30 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
if ( F_68 ( V_10 -> V_7 . V_8 ,
V_177 + V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
} else {
int V_197 = V_179 -> V_134 +
V_179 -> V_136 ;
for ( V_102 = V_197 ; V_102 < V_197 + V_179 -> V_135 ; V_102 ++ ) {
if ( F_68 ( V_179 -> V_133 [ V_102 ] ,
V_177 + V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
}
}
V_167 -> V_195 = V_170 ;
F_37 ( L_31 , V_167 -> V_191 ,
V_167 -> V_195 , V_167 -> V_193 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_69 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_198 * V_199 = V_163 ;
struct V_41 * V_42 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_199 -> V_176 ,
V_51 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
V_199 -> V_200 = V_42 -> V_200 ;
V_199 -> V_201 = V_42 -> V_201 ;
V_199 -> V_202 = V_42 -> V_202 ;
if ( V_42 -> V_34 )
V_199 -> V_175 = V_42 -> V_34 -> V_7 . V_8 ;
else
V_199 -> V_175 = 0 ;
if ( V_42 -> V_203 ) {
F_62 ( & V_199 -> V_57 , & V_42 -> V_57 ) ;
V_199 -> V_204 = 1 ;
} else {
V_199 -> V_204 = 0 ;
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_71 ( struct V_18 * V_19 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_205 * V_206 = V_163 ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
struct V_56 * V_57 ;
int V_207 = 0 ;
int V_208 = 0 ;
int V_209 = 0 ;
int V_24 = 0 ;
int V_174 = 0 ;
int V_102 ;
struct V_145 V_210 ;
struct V_145 T_2 * V_211 ;
T_1 T_2 * V_212 ;
T_3 T_2 * V_213 ;
T_1 T_2 * V_214 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
memset ( & V_210 , 0 , sizeof( struct V_145 ) ) ;
F_37 ( L_32 , V_206 -> V_177 ) ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_206 -> V_177 ,
V_60 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_52;
}
V_10 = F_72 ( V_21 ) ;
for ( V_102 = 0 ; V_102 < V_215 ; V_102 ++ ) {
if ( V_10 -> V_216 [ V_102 ] != 0 ) {
V_208 ++ ;
}
}
for ( V_102 = 0 ; V_102 < V_217 ; V_102 ++ ) {
if ( V_10 -> V_218 [ V_102 ] != 0 ) {
V_209 ++ ;
}
}
if ( V_206 -> V_219 == 0 ) {
V_10 -> V_36 -> V_220 ( V_10 ,
V_19 -> V_26 . V_186 ,
V_19 -> V_26 . V_184 ) ;
}
F_17 (mode, &connector->modes, head)
V_207 ++ ;
V_206 -> V_177 = V_10 -> V_7 . V_8 ;
V_206 -> V_12 = V_10 -> V_12 ;
V_206 -> V_13 = V_10 -> V_13 ;
V_206 -> V_221 = V_10 -> V_222 . V_223 ;
V_206 -> V_224 = V_10 -> V_222 . V_225 ;
V_206 -> V_226 = V_10 -> V_222 . V_227 ;
V_206 -> V_228 = V_10 -> V_15 ;
if ( V_10 -> V_2 )
V_206 -> V_178 = V_10 -> V_2 -> V_7 . V_8 ;
else
V_206 -> V_178 = 0 ;
if ( ( V_206 -> V_219 >= V_207 ) && V_207 ) {
V_174 = 0 ;
V_211 = (struct V_145 T_2 * ) ( unsigned long ) V_206 -> V_229 ;
F_17 (mode, &connector->modes, head) {
F_62 ( & V_210 , V_57 ) ;
if ( F_73 ( V_211 + V_174 ,
& V_210 , sizeof( V_210 ) ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
}
V_206 -> V_219 = V_207 ;
if ( ( V_206 -> V_230 >= V_208 ) && V_208 ) {
V_174 = 0 ;
V_212 = ( T_1 T_2 * ) ( unsigned long ) ( V_206 -> V_231 ) ;
V_213 = ( T_3 T_2 * ) ( unsigned long ) ( V_206 -> V_232 ) ;
for ( V_102 = 0 ; V_102 < V_215 ; V_102 ++ ) {
if ( V_10 -> V_216 [ V_102 ] != 0 ) {
if ( F_68 ( V_10 -> V_216 [ V_102 ] ,
V_212 + V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
if ( F_68 ( V_10 -> V_233 [ V_102 ] ,
V_213 + V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
}
}
V_206 -> V_230 = V_208 ;
if ( ( V_206 -> V_193 >= V_209 ) && V_209 ) {
V_174 = 0 ;
V_214 = ( T_1 T_2 * ) ( unsigned long ) ( V_206 -> V_234 ) ;
for ( V_102 = 0 ; V_102 < V_217 ; V_102 ++ ) {
if ( V_10 -> V_218 [ V_102 ] != 0 ) {
if ( F_68 ( V_10 -> V_218 [ V_102 ] ,
V_214 + V_174 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_174 ++ ;
}
}
}
V_206 -> V_193 = V_209 ;
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
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_236 -> V_178 ,
V_72 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_52;
}
V_2 = F_75 ( V_21 ) ;
if ( V_2 -> V_42 )
V_236 -> V_176 = V_2 -> V_42 -> V_7 . V_8 ;
else
V_236 -> V_176 = 0 ;
V_236 -> V_5 = V_2 -> V_5 ;
V_236 -> V_178 = V_2 -> V_7 . V_8 ;
V_236 -> V_75 = V_2 -> V_75 ;
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
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_241 = & V_19 -> V_26 ;
if ( V_241 -> V_84 &&
( V_239 -> V_243 >= V_241 -> V_84 ) ) {
V_242 = ( T_1 T_2 * ) ( unsigned long ) V_239 -> V_244 ;
F_17 (plane, &config->plane_list, head) {
if ( F_68 ( V_44 -> V_7 . V_8 , V_242 + V_174 ) ) {
V_24 = - V_190 ;
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
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_239 -> V_247 ,
V_80 ) ;
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
V_239 -> V_75 = V_44 -> V_75 ;
V_239 -> V_202 = V_44 -> V_202 ;
if ( V_44 -> V_78 &&
( V_239 -> V_249 >= V_44 -> V_78 ) ) {
V_246 = ( T_1 T_2 * ) ( unsigned long ) V_239 -> V_250 ;
if ( F_73 ( V_246 ,
V_44 -> V_81 ,
sizeof( T_1 ) * V_44 -> V_78 ) ) {
V_24 = - V_190 ;
goto V_52;
}
}
V_239 -> V_249 = V_44 -> V_78 ;
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
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_252 -> V_247 ,
V_80 ) ;
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
for ( V_102 = 0 ; V_102 < V_44 -> V_78 ; V_102 ++ )
if ( V_34 -> V_255 == V_44 -> V_81 [ V_102 ] )
break;
if ( V_102 == V_44 -> V_78 ) {
F_37 ( L_36 , V_34 -> V_255 ) ;
V_24 = - V_29 ;
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
struct V_198 * V_269 = V_163 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
struct V_9 * * V_270 = NULL , * V_10 ;
struct V_33 * V_34 = NULL ;
struct V_56 * V_57 = NULL ;
struct V_45 V_46 ;
T_1 T_2 * V_271 ;
int V_24 = 0 ;
int V_102 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
if ( V_269 -> V_200 > V_161 || V_269 -> V_201 > V_161 )
return - V_162 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_269 -> V_176 ,
V_51 ) ;
if ( ! V_21 ) {
F_37 ( L_40 , V_269 -> V_176 ) ;
V_24 = - V_29 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
F_37 ( L_28 , V_42 -> V_7 . V_8 ) ;
if ( V_269 -> V_204 ) {
if ( V_269 -> V_175 == - 1 ) {
if ( ! V_42 -> V_34 ) {
F_37 ( L_41 ) ;
V_24 = - V_29 ;
goto V_52;
}
V_34 = V_42 -> V_34 ;
} else {
V_21 = F_12 ( V_19 , V_269 -> V_175 ,
V_37 ) ;
if ( ! V_21 ) {
F_37 ( L_42 ,
V_269 -> V_175 ) ;
V_24 = - V_29 ;
goto V_52;
}
V_34 = F_80 ( V_21 ) ;
}
V_57 = F_40 ( V_19 ) ;
if ( ! V_57 ) {
V_24 = - V_82 ;
goto V_52;
}
V_24 = F_64 ( V_57 , & V_269 -> V_57 ) ;
if ( V_24 ) {
F_37 ( L_43 ) ;
goto V_52;
}
F_82 ( V_57 , V_272 ) ;
if ( V_57 -> V_147 > V_34 -> V_256 ||
V_57 -> V_153 > V_34 -> V_257 ||
V_269 -> V_200 > V_34 -> V_256 - V_57 -> V_147 ||
V_269 -> V_201 > V_34 -> V_257 - V_57 -> V_153 ) {
F_37 ( L_44 ,
V_57 -> V_147 , V_57 -> V_153 ,
V_269 -> V_200 , V_269 -> V_201 ,
V_34 -> V_256 , V_34 -> V_257 ) ;
V_24 = - V_262 ;
goto V_52;
}
}
if ( V_269 -> V_195 == 0 && V_57 ) {
F_37 ( L_45 ) ;
V_24 = - V_29 ;
goto V_52;
}
if ( V_269 -> V_195 > 0 && ( ! V_57 || ! V_34 ) ) {
F_37 ( L_46 ,
V_269 -> V_195 ) ;
V_24 = - V_29 ;
goto V_52;
}
if ( V_269 -> V_195 > 0 ) {
T_4 V_273 ;
if ( V_269 -> V_195 > V_241 -> V_66 ) {
V_24 = - V_29 ;
goto V_52;
}
V_270 = F_36 ( V_269 -> V_195 *
sizeof( struct V_9 * ) ,
V_28 ) ;
if ( ! V_270 ) {
V_24 = - V_82 ;
goto V_52;
}
for ( V_102 = 0 ; V_102 < V_269 -> V_195 ; V_102 ++ ) {
V_271 = ( T_1 T_2 * ) ( unsigned long ) V_269 -> V_271 ;
if ( F_83 ( V_273 , & V_271 [ V_102 ] ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_21 = F_12 ( V_19 , V_273 ,
V_60 ) ;
if ( ! V_21 ) {
F_37 ( L_47 ,
V_273 ) ;
V_24 = - V_29 ;
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
V_46 . V_200 = V_269 -> V_200 ;
V_46 . V_201 = V_269 -> V_201 ;
V_46 . V_57 = V_57 ;
V_46 . V_274 = V_270 ;
V_46 . V_135 = V_269 -> V_195 ;
V_46 . V_34 = V_34 ;
V_24 = V_42 -> V_36 -> V_47 ( & V_46 ) ;
V_52:
F_22 ( V_270 ) ;
F_25 ( V_19 , V_57 ) ;
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
return - V_29 ;
if ( ! V_276 -> V_159 )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_276 -> V_176 , V_51 ) ;
if ( ! V_21 ) {
F_37 ( L_40 , V_276 -> V_176 ) ;
V_24 = - V_29 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
if ( V_276 -> V_159 & V_277 ) {
if ( ! V_42 -> V_36 -> V_278 ) {
V_24 = - V_279 ;
goto V_52;
}
V_24 = V_42 -> V_36 -> V_278 ( V_42 , V_165 , V_276 -> V_280 ,
V_276 -> V_256 , V_276 -> V_257 ) ;
}
if ( V_276 -> V_159 & V_281 ) {
if ( V_42 -> V_36 -> V_282 ) {
V_24 = V_42 -> V_36 -> V_282 ( V_42 , V_276 -> V_200 , V_276 -> V_201 ) ;
} else {
V_24 = - V_190 ;
goto V_52;
}
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
T_1 F_85 ( T_1 V_283 , T_1 V_284 )
{
T_1 V_285 ;
switch ( V_283 ) {
case 8 :
V_285 = V_286 ;
break;
case 16 :
if ( V_284 == 15 )
V_285 = V_287 ;
else
V_285 = V_288 ;
break;
case 24 :
V_285 = V_289 ;
break;
case 32 :
if ( V_284 == 24 )
V_285 = V_290 ;
else if ( V_284 == 30 )
V_285 = V_291 ;
else
V_285 = V_292 ;
break;
default:
F_6 ( L_48 ) ;
V_285 = V_290 ;
break;
}
return V_285 ;
}
int F_86 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_293 * V_294 = V_163 ;
struct V_295 V_296 = {} ;
struct V_240 * V_241 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
V_296 . V_175 = V_294 -> V_175 ;
V_296 . V_256 = V_294 -> V_256 ;
V_296 . V_257 = V_294 -> V_257 ;
V_296 . V_297 [ 0 ] = V_294 -> V_298 ;
V_296 . V_255 = F_85 ( V_294 -> V_283 , V_294 -> V_284 ) ;
V_296 . V_299 [ 0 ] = V_294 -> V_280 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
if ( ( V_241 -> V_187 > V_296 . V_256 ) || ( V_296 . V_256 > V_241 -> V_186 ) )
return - V_29 ;
if ( ( V_241 -> V_185 > V_296 . V_257 ) || ( V_296 . V_257 > V_241 -> V_184 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_300 ( V_19 , V_165 , & V_296 ) ;
if ( F_87 ( V_34 ) ) {
F_6 ( L_49 ) ;
V_24 = F_88 ( V_34 ) ;
goto V_52;
}
V_294 -> V_175 = V_34 -> V_7 . V_8 ;
F_15 ( & V_34 -> V_301 , & V_165 -> V_302 ) ;
F_37 ( L_50 , V_34 -> V_7 . V_8 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
static int F_89 ( struct V_295 * V_296 )
{
T_1 V_303 = V_296 -> V_255 & ~ V_304 ;
switch ( V_303 ) {
case V_305 :
case V_286 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_287 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_288 :
case V_322 :
case V_289 :
case V_323 :
case V_290 :
case V_324 :
case V_325 :
case V_326 :
case V_292 :
case V_327 :
case V_328 :
case V_329 :
case V_291 :
case V_330 :
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
return 0 ;
default:
return - V_29 ;
}
}
int F_90 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_295 * V_296 = V_163 ;
struct V_240 * V_241 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
if ( ( V_241 -> V_187 > V_296 -> V_256 ) || ( V_296 -> V_256 > V_241 -> V_186 ) ) {
F_6 ( L_51 ,
V_296 -> V_256 , V_241 -> V_187 , V_241 -> V_186 ) ;
return - V_29 ;
}
if ( ( V_241 -> V_185 > V_296 -> V_257 ) || ( V_296 -> V_257 > V_241 -> V_184 ) ) {
F_6 ( L_52 ,
V_296 -> V_257 , V_241 -> V_185 , V_241 -> V_184 ) ;
return - V_29 ;
}
V_24 = F_89 ( V_296 ) ;
if ( V_24 ) {
F_6 ( L_53 , V_296 -> V_255 ) ;
return V_24 ;
}
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_300 ( V_19 , V_165 , V_296 ) ;
if ( F_87 ( V_34 ) ) {
F_6 ( L_49 ) ;
V_24 = F_88 ( V_34 ) ;
goto V_52;
}
V_296 -> V_175 = V_34 -> V_7 . V_8 ;
F_15 ( & V_34 -> V_301 , & V_165 -> V_302 ) ;
F_37 ( L_50 , V_34 -> V_7 . V_8 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_91 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_20 * V_21 ;
struct V_33 * V_34 = NULL ;
struct V_33 * V_356 = NULL ;
T_1 * V_8 = V_163 ;
int V_24 = 0 ;
int V_357 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , * V_8 , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_52;
}
V_34 = F_80 ( V_21 ) ;
F_17 (fbl, &file_priv->fbs, filp_head)
if ( V_34 == V_356 )
V_357 = 1 ;
if ( ! V_357 ) {
V_24 = - V_29 ;
goto V_52;
}
F_18 ( & V_34 -> V_301 ) ;
V_34 -> V_36 -> V_144 ( V_34 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_92 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_293 * V_296 = V_163 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_296 -> V_175 , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_52;
}
V_34 = F_80 ( V_21 ) ;
V_296 -> V_257 = V_34 -> V_257 ;
V_296 -> V_256 = V_34 -> V_256 ;
V_296 -> V_284 = V_34 -> V_284 ;
V_296 -> V_283 = V_34 -> V_358 ;
V_296 -> V_298 = V_34 -> V_297 [ 0 ] ;
V_34 -> V_36 -> V_359 ( V_34 , V_165 , & V_296 -> V_280 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_93 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_360 T_2 * V_361 ;
struct V_360 * V_362 = NULL ;
struct V_363 * V_296 = V_163 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
unsigned V_159 ;
int V_364 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_296 -> V_175 , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_365;
}
V_34 = F_80 ( V_21 ) ;
V_364 = V_296 -> V_364 ;
V_361 = (struct V_360 T_2 * ) ( unsigned long ) V_296 -> V_361 ;
if ( ! V_364 != ! V_361 ) {
V_24 = - V_29 ;
goto V_365;
}
V_159 = V_366 & V_296 -> V_159 ;
if ( V_159 & V_367 && ( V_364 % 2 ) ) {
V_24 = - V_29 ;
goto V_365;
}
if ( V_364 && V_361 ) {
if ( V_364 < 0 || V_364 > V_368 ) {
V_24 = - V_29 ;
goto V_365;
}
V_362 = F_41 ( V_364 * sizeof( * V_362 ) , V_28 ) ;
if ( ! V_362 ) {
V_24 = - V_82 ;
goto V_365;
}
V_24 = F_94 ( V_362 , V_361 ,
V_364 * sizeof( * V_362 ) ) ;
if ( V_24 ) {
V_24 = - V_190 ;
goto V_369;
}
}
if ( V_34 -> V_36 -> V_370 ) {
V_24 = V_34 -> V_36 -> V_370 ( V_34 , V_165 , V_159 , V_296 -> V_371 ,
V_362 , V_364 ) ;
} else {
V_24 = - V_372 ;
goto V_369;
}
V_369:
F_22 ( V_362 ) ;
V_365:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_95 ( struct V_164 * V_79 )
{
struct V_18 * V_19 = V_79 -> V_182 -> V_19 ;
struct V_33 * V_34 , * V_373 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_30 (fb, tfb, &priv->fbs, filp_head) {
F_18 ( & V_34 -> V_301 ) ;
V_34 -> V_36 -> V_144 ( V_34 ) ;
}
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
static void F_96 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_56 * V_57 )
{
F_20 ( & V_57 -> V_39 , & V_10 -> V_62 ) ;
}
int F_97 ( struct V_18 * V_19 , struct V_41 * V_42 ,
const struct V_56 * V_57 )
{
struct V_9 * V_10 ;
int V_24 = 0 ;
struct V_56 * V_374 , * V_375 ;
F_98 ( V_376 ) ;
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
continue;
if ( V_10 -> V_2 -> V_42 == V_42 ) {
V_374 = F_99 ( V_19 , V_57 ) ;
if ( ! V_374 ) {
V_24 = - V_82 ;
goto V_52;
}
F_20 ( & V_374 -> V_39 , & V_376 ) ;
}
}
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
continue;
if ( V_10 -> V_2 -> V_42 == V_42 )
F_100 ( V_376 . V_375 , & V_10 -> V_62 ) ;
}
F_101 ( ! F_39 ( & V_376 ) ) ;
V_52:
F_30 (dup_mode, next, &list, head)
F_25 ( V_19 , V_374 ) ;
return V_24 ;
}
static int F_102 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_56 * V_57 )
{
int V_357 = 0 ;
int V_24 = 0 ;
struct V_56 * V_377 , * V_70 ;
F_30 (match_mode, t, &connector->user_modes, head) {
if ( F_103 ( V_377 , V_57 ) ) {
F_18 ( & V_377 -> V_39 ) ;
F_25 ( V_19 , V_377 ) ;
V_357 = 1 ;
break;
}
}
if ( ! V_357 )
V_24 = - V_29 ;
return V_24 ;
}
int F_104 ( struct V_18 * V_19 , struct V_56 * V_57 )
{
struct V_9 * V_10 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
F_102 ( V_19 , V_10 , V_57 ) ;
}
return 0 ;
}
int F_105 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_378 * V_379 = V_163 ;
struct V_9 * V_10 ;
struct V_56 * V_57 ;
struct V_20 * V_21 ;
struct V_145 * V_380 = & V_379 -> V_57 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_379 -> V_177 , V_60 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_52;
}
V_10 = F_72 ( V_21 ) ;
V_57 = F_40 ( V_19 ) ;
if ( ! V_57 ) {
V_24 = - V_82 ;
goto V_52;
}
V_24 = F_64 ( V_57 , V_380 ) ;
if ( V_24 ) {
F_37 ( L_43 ) ;
F_25 ( V_19 , V_57 ) ;
goto V_52;
}
F_96 ( V_19 , V_10 , V_57 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_106 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_20 * V_21 ;
struct V_378 * V_379 = V_163 ;
struct V_9 * V_10 ;
struct V_56 V_57 ;
struct V_145 * V_380 = & V_379 -> V_57 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_379 -> V_177 , V_60 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_52;
}
V_10 = F_72 ( V_21 ) ;
V_24 = F_64 ( & V_57 , V_380 ) ;
if ( V_24 ) {
F_37 ( L_43 ) ;
goto V_52;
}
V_24 = F_102 ( V_19 , V_10 , & V_57 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
struct V_87 * F_43 ( struct V_18 * V_19 , int V_159 ,
const char * V_6 , int V_381 )
{
struct V_87 * V_141 = NULL ;
int V_24 ;
V_141 = F_41 ( sizeof( struct V_87 ) , V_28 ) ;
if ( ! V_141 )
return NULL ;
if ( V_381 ) {
V_141 -> V_382 = F_41 ( sizeof( T_3 ) * V_381 , V_28 ) ;
if ( ! V_141 -> V_382 )
goto V_383;
}
V_24 = F_4 ( V_19 , & V_141 -> V_7 , V_384 ) ;
if ( V_24 )
goto V_383;
V_141 -> V_159 = V_159 ;
V_141 -> V_381 = V_381 ;
F_27 ( & V_141 -> V_385 ) ;
if ( V_6 ) {
strncpy ( V_141 -> V_6 , V_6 , V_386 ) ;
V_141 -> V_6 [ V_386 - 1 ] = '\0' ;
}
F_20 ( & V_141 -> V_39 , & V_19 -> V_26 . V_128 ) ;
return V_141 ;
V_383:
F_22 ( V_141 -> V_382 ) ;
F_22 ( V_141 ) ;
return NULL ;
}
struct V_87 * F_44 ( struct V_18 * V_19 , int V_159 ,
const char * V_6 ,
const struct V_387 * V_388 ,
int V_381 )
{
struct V_87 * V_141 ;
int V_102 , V_24 ;
V_159 |= V_112 ;
V_141 = F_43 ( V_19 , V_159 , V_6 , V_381 ) ;
if ( ! V_141 )
return NULL ;
for ( V_102 = 0 ; V_102 < V_381 ; V_102 ++ ) {
V_24 = F_49 ( V_141 , V_102 ,
V_388 [ V_102 ] . type ,
V_388 [ V_102 ] . V_6 ) ;
if ( V_24 ) {
F_59 ( V_19 , V_141 ) ;
return NULL ;
}
}
return V_141 ;
}
struct V_87 * F_48 ( struct V_18 * V_19 , int V_159 ,
const char * V_6 ,
T_3 V_389 , T_3 V_390 )
{
struct V_87 * V_141 ;
V_159 |= V_391 ;
V_141 = F_43 ( V_19 , V_159 , V_6 , 2 ) ;
if ( ! V_141 )
return NULL ;
V_141 -> V_382 [ 0 ] = V_389 ;
V_141 -> V_382 [ 1 ] = V_390 ;
return V_141 ;
}
int F_49 ( struct V_87 * V_141 , int V_392 ,
T_3 V_393 , const char * V_6 )
{
struct V_394 * V_395 ;
if ( ! ( V_141 -> V_159 & V_112 ) )
return - V_29 ;
if ( ! F_39 ( & V_141 -> V_385 ) ) {
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( V_395 -> V_393 == V_393 ) {
strncpy ( V_395 -> V_6 , V_6 , V_386 ) ;
V_395 -> V_6 [ V_386 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_395 = F_41 ( sizeof( struct V_394 ) , V_28 ) ;
if ( ! V_395 )
return - V_82 ;
strncpy ( V_395 -> V_6 , V_6 , V_386 ) ;
V_395 -> V_6 [ V_386 - 1 ] = '\0' ;
V_395 -> V_393 = V_393 ;
V_141 -> V_382 [ V_392 ] = V_393 ;
F_20 ( & V_395 -> V_39 , & V_141 -> V_385 ) ;
return 0 ;
}
void F_59 ( struct V_18 * V_19 , struct V_87 * V_141 )
{
struct V_394 * V_395 , * V_142 ;
F_30 (prop_enum, pt, &property->enum_blob_list, head) {
F_18 ( & V_395 -> V_39 ) ;
F_22 ( V_395 ) ;
}
if ( V_141 -> V_381 )
F_22 ( V_141 -> V_382 ) ;
F_10 ( V_19 , & V_141 -> V_7 ) ;
F_18 ( & V_141 -> V_39 ) ;
F_22 ( V_141 ) ;
}
int F_28 ( struct V_9 * V_10 ,
struct V_87 * V_141 , T_3 V_396 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_215 ; V_102 ++ ) {
if ( V_10 -> V_216 [ V_102 ] == 0 ) {
V_10 -> V_216 [ V_102 ] = V_141 -> V_7 . V_8 ;
V_10 -> V_233 [ V_102 ] = V_396 ;
break;
}
}
if ( V_102 == V_215 )
return - V_29 ;
return 0 ;
}
int F_107 ( struct V_9 * V_10 ,
struct V_87 * V_141 , T_3 V_393 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_215 ; V_102 ++ ) {
if ( V_10 -> V_216 [ V_102 ] == V_141 -> V_7 . V_8 ) {
V_10 -> V_233 [ V_102 ] = V_393 ;
break;
}
}
if ( V_102 == V_215 )
return - V_29 ;
return 0 ;
}
int F_108 ( struct V_9 * V_10 ,
struct V_87 * V_141 , T_3 * V_397 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_215 ; V_102 ++ ) {
if ( V_10 -> V_216 [ V_102 ] == V_141 -> V_7 . V_8 ) {
* V_397 = V_10 -> V_233 [ V_102 ] ;
break;
}
}
if ( V_102 == V_215 )
return - V_29 ;
return 0 ;
}
int F_109 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_20 * V_21 ;
struct V_398 * V_206 = V_163 ;
struct V_87 * V_141 ;
int V_399 = 0 ;
int V_400 = 0 ;
int V_401 = 0 ;
int V_24 = 0 , V_102 ;
int V_174 ;
struct V_394 * V_395 ;
struct V_402 T_2 * V_403 ;
struct V_404 * V_405 ;
T_1 T_2 * V_406 ;
T_3 T_2 * V_407 ;
T_1 T_2 * V_408 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_206 -> V_409 , V_384 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_410;
}
V_141 = F_110 ( V_21 ) ;
if ( V_141 -> V_159 & V_112 ) {
F_17 (prop_enum, &property->enum_blob_list, head)
V_399 ++ ;
} else if ( V_141 -> V_159 & V_90 ) {
F_17 (prop_blob, &property->enum_blob_list, head)
V_400 ++ ;
}
V_401 = V_141 -> V_381 ;
strncpy ( V_206 -> V_6 , V_141 -> V_6 , V_386 ) ;
V_206 -> V_6 [ V_386 - 1 ] = 0 ;
V_206 -> V_159 = V_141 -> V_159 ;
if ( ( V_206 -> V_411 >= V_401 ) && V_401 ) {
V_407 = ( T_3 T_2 * ) ( unsigned long ) V_206 -> V_407 ;
for ( V_102 = 0 ; V_102 < V_401 ; V_102 ++ ) {
if ( F_73 ( V_407 + V_102 , & V_141 -> V_382 [ V_102 ] , sizeof( T_3 ) ) ) {
V_24 = - V_190 ;
goto V_410;
}
}
}
V_206 -> V_411 = V_401 ;
if ( V_141 -> V_159 & V_112 ) {
if ( ( V_206 -> V_412 >= V_399 ) && V_399 ) {
V_174 = 0 ;
V_403 = (struct V_402 T_2 * ) ( unsigned long ) V_206 -> V_413 ;
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( F_73 ( & V_403 [ V_174 ] . V_393 , & V_395 -> V_393 , sizeof( T_3 ) ) ) {
V_24 = - V_190 ;
goto V_410;
}
if ( F_73 ( & V_403 [ V_174 ] . V_6 ,
& V_395 -> V_6 , V_386 ) ) {
V_24 = - V_190 ;
goto V_410;
}
V_174 ++ ;
}
}
V_206 -> V_412 = V_399 ;
}
if ( V_141 -> V_159 & V_90 ) {
if ( ( V_206 -> V_412 >= V_400 ) && V_400 ) {
V_174 = 0 ;
V_406 = ( T_1 T_2 * ) ( unsigned long ) V_206 -> V_413 ;
V_408 = ( T_1 T_2 * ) ( unsigned long ) V_206 -> V_407 ;
F_17 (prop_blob, &property->enum_blob_list, head) {
if ( F_68 ( V_405 -> V_7 . V_8 , V_406 + V_174 ) ) {
V_24 = - V_190 ;
goto V_410;
}
if ( F_68 ( V_405 -> V_414 , V_408 + V_174 ) ) {
V_24 = - V_190 ;
goto V_410;
}
V_174 ++ ;
}
}
V_206 -> V_412 = V_400 ;
}
V_410:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
static struct V_404 * F_111 ( struct V_18 * V_19 , int V_414 ,
void * V_163 )
{
struct V_404 * V_415 ;
int V_24 ;
if ( ! V_414 || ! V_163 )
return NULL ;
V_415 = F_41 ( sizeof( struct V_404 ) + V_414 , V_28 ) ;
if ( ! V_415 )
return NULL ;
V_24 = F_4 ( V_19 , & V_415 -> V_7 , V_416 ) ;
if ( V_24 ) {
F_22 ( V_415 ) ;
return NULL ;
}
V_415 -> V_414 = V_414 ;
memcpy ( V_415 -> V_163 , V_163 , V_414 ) ;
F_20 ( & V_415 -> V_39 , & V_19 -> V_26 . V_129 ) ;
return V_415 ;
}
static void F_112 ( struct V_18 * V_19 ,
struct V_404 * V_415 )
{
F_10 ( V_19 , & V_415 -> V_7 ) ;
F_18 ( & V_415 -> V_39 ) ;
F_22 ( V_415 ) ;
}
int F_113 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_20 * V_21 ;
struct V_417 * V_206 = V_163 ;
struct V_404 * V_415 ;
int V_24 = 0 ;
void T_2 * V_418 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_206 -> V_419 , V_416 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_410;
}
V_415 = F_114 ( V_21 ) ;
if ( V_206 -> V_414 == V_415 -> V_414 ) {
V_418 = ( void T_2 * ) ( unsigned long ) V_206 -> V_163 ;
if ( F_73 ( V_418 , V_415 -> V_163 , V_415 -> V_414 ) ) {
V_24 = - V_190 ;
goto V_410;
}
}
V_206 -> V_414 = V_415 -> V_414 ;
V_410:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_115 ( struct V_9 * V_10 ,
struct V_88 * V_88 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
int V_24 = 0 , V_420 ;
if ( V_10 -> V_64 )
F_112 ( V_19 , V_10 -> V_64 ) ;
if ( ! V_88 ) {
V_10 -> V_64 = NULL ;
V_24 = F_107 ( V_10 , V_19 -> V_26 . V_68 , 0 ) ;
return V_24 ;
}
V_420 = V_421 * ( 1 + V_88 -> V_422 ) ;
V_10 -> V_64 = F_111 ( V_10 -> V_19 ,
V_420 , V_88 ) ;
V_24 = F_107 ( V_10 ,
V_19 -> V_26 . V_68 ,
V_10 -> V_64 -> V_7 . V_8 ) ;
return V_24 ;
}
int F_116 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_423 * V_206 = V_163 ;
struct V_20 * V_21 ;
struct V_87 * V_141 ;
struct V_9 * V_10 ;
int V_24 = - V_29 ;
int V_102 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_206 -> V_177 , V_60 ) ;
if ( ! V_21 ) {
goto V_52;
}
V_10 = F_72 ( V_21 ) ;
for ( V_102 = 0 ; V_102 < V_215 ; V_102 ++ ) {
if ( V_10 -> V_216 [ V_102 ] == V_206 -> V_409 )
break;
}
if ( V_102 == V_215 ) {
goto V_52;
}
V_21 = F_12 ( V_19 , V_206 -> V_409 , V_384 ) ;
if ( ! V_21 ) {
goto V_52;
}
V_141 = F_110 ( V_21 ) ;
if ( V_141 -> V_159 & V_91 )
goto V_52;
if ( V_141 -> V_159 & V_391 ) {
if ( V_206 -> V_393 < V_141 -> V_382 [ 0 ] )
goto V_52;
if ( V_206 -> V_393 > V_141 -> V_382 [ 1 ] )
goto V_52;
} else {
int V_357 = 0 ;
for ( V_102 = 0 ; V_102 < V_141 -> V_381 ; V_102 ++ ) {
if ( V_141 -> V_382 [ V_102 ] == V_206 -> V_393 ) {
V_357 = 1 ;
break;
}
}
if ( ! V_357 ) {
goto V_52;
}
}
if ( V_141 == V_10 -> V_19 -> V_26 . V_69 ) {
if ( V_10 -> V_36 -> V_89 )
(* V_10 -> V_36 -> V_89 )( V_10 , ( int ) V_206 -> V_393 ) ;
V_24 = 0 ;
} else if ( V_10 -> V_36 -> V_424 )
V_24 = V_10 -> V_36 -> V_424 ( V_10 , V_141 , V_206 -> V_393 ) ;
if ( ! V_24 )
F_107 ( V_10 , V_141 , V_206 -> V_393 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_117 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_217 ; V_102 ++ ) {
if ( V_10 -> V_218 [ V_102 ] == 0 ) {
V_10 -> V_218 [ V_102 ] = V_2 -> V_7 . V_8 ;
return 0 ;
}
}
return - V_82 ;
}
void F_118 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_217 ; V_102 ++ ) {
if ( V_10 -> V_218 [ V_102 ] == V_2 -> V_7 . V_8 ) {
V_10 -> V_218 [ V_102 ] = 0 ;
if ( V_10 -> V_2 == V_2 )
V_10 -> V_2 = NULL ;
break;
}
}
}
int F_119 ( struct V_41 * V_42 ,
int V_202 )
{
V_42 -> V_202 = V_202 ;
V_42 -> V_55 = F_41 ( V_202 * sizeof( V_425 ) * 3 , V_28 ) ;
if ( ! V_42 -> V_55 ) {
V_42 -> V_202 = 0 ;
return - V_82 ;
}
return 0 ;
}
int F_120 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_426 * V_427 = V_163 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_428 , * V_429 , * V_430 ;
int V_420 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_427 -> V_176 , V_51 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
if ( V_427 -> V_202 != V_42 -> V_202 ) {
V_24 = - V_29 ;
goto V_52;
}
V_420 = V_427 -> V_202 * ( sizeof( V_425 ) ) ;
V_428 = V_42 -> V_55 ;
if ( F_94 ( V_428 , ( void T_2 * ) ( unsigned long ) V_427 -> V_431 , V_420 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_429 = V_428 + V_420 ;
if ( F_94 ( V_429 , ( void T_2 * ) ( unsigned long ) V_427 -> V_432 , V_420 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_430 = V_429 + V_420 ;
if ( F_94 ( V_430 , ( void T_2 * ) ( unsigned long ) V_427 -> V_433 , V_420 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_42 -> V_36 -> V_434 ( V_42 , V_428 , V_429 , V_430 , 0 , V_42 -> V_202 ) ;
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_121 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_426 * V_427 = V_163 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_428 , * V_429 , * V_430 ;
int V_420 ;
int V_24 = 0 ;
if ( ! F_66 ( V_19 , V_180 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_427 -> V_176 , V_51 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_52;
}
V_42 = F_70 ( V_21 ) ;
if ( V_427 -> V_202 != V_42 -> V_202 ) {
V_24 = - V_29 ;
goto V_52;
}
V_420 = V_427 -> V_202 * ( sizeof( V_425 ) ) ;
V_428 = V_42 -> V_55 ;
if ( F_73 ( ( void T_2 * ) ( unsigned long ) V_427 -> V_431 , V_428 , V_420 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_429 = V_428 + V_420 ;
if ( F_73 ( ( void T_2 * ) ( unsigned long ) V_427 -> V_432 , V_429 , V_420 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_430 = V_429 + V_420 ;
if ( F_73 ( ( void T_2 * ) ( unsigned long ) V_427 -> V_433 , V_430 , V_420 ) ) {
V_24 = - V_190 ;
goto V_52;
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_122 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_435 * V_436 = V_163 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
struct V_33 * V_34 ;
struct V_437 * V_438 = NULL ;
unsigned long V_159 ;
int V_24 = - V_29 ;
if ( V_436 -> V_159 & ~ V_439 ||
V_436 -> V_440 != 0 )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_436 -> V_176 , V_51 ) ;
if ( ! V_21 )
goto V_52;
V_42 = F_70 ( V_21 ) ;
if ( V_42 -> V_34 == NULL ) {
V_24 = - V_441 ;
goto V_52;
}
if ( V_42 -> V_36 -> V_436 == NULL )
goto V_52;
V_21 = F_12 ( V_19 , V_436 -> V_175 , V_37 ) ;
if ( ! V_21 )
goto V_52;
V_34 = F_80 ( V_21 ) ;
if ( V_42 -> V_57 . V_147 > V_34 -> V_256 ||
V_42 -> V_57 . V_153 > V_34 -> V_257 ||
V_42 -> V_200 > V_34 -> V_256 - V_42 -> V_57 . V_147 ||
V_42 -> V_201 > V_34 -> V_257 - V_42 -> V_57 . V_153 ) {
F_37 ( L_54 ,
V_34 -> V_256 , V_34 -> V_257 ,
V_42 -> V_57 . V_147 , V_42 -> V_57 . V_153 ,
V_42 -> V_200 , V_42 -> V_201 ) ;
V_24 = - V_262 ;
goto V_52;
}
if ( V_436 -> V_159 & V_442 ) {
V_24 = - V_82 ;
F_123 ( & V_19 -> V_443 , V_159 ) ;
if ( V_165 -> V_444 < sizeof V_438 -> V_445 ) {
F_124 ( & V_19 -> V_443 , V_159 ) ;
goto V_52;
}
V_165 -> V_444 -= sizeof V_438 -> V_445 ;
F_124 ( & V_19 -> V_443 , V_159 ) ;
V_438 = F_41 ( sizeof *V_438 , V_28 ) ;
if ( V_438 == NULL ) {
F_123 ( & V_19 -> V_443 , V_159 ) ;
V_165 -> V_444 += sizeof V_438 -> V_445 ;
F_124 ( & V_19 -> V_443 , V_159 ) ;
goto V_52;
}
V_438 -> V_445 . V_7 . type = V_446 ;
V_438 -> V_445 . V_7 . V_414 = sizeof V_438 -> V_445 ;
V_438 -> V_445 . V_447 = V_436 -> V_447 ;
V_438 -> V_7 . V_445 = & V_438 -> V_445 . V_7 ;
V_438 -> V_7 . V_165 = V_165 ;
V_438 -> V_7 . V_144 =
( void ( * ) ( struct V_448 * ) ) F_22 ;
}
V_24 = V_42 -> V_36 -> V_436 ( V_42 , V_34 , V_438 ) ;
if ( V_24 ) {
if ( V_436 -> V_159 & V_442 ) {
F_123 ( & V_19 -> V_443 , V_159 ) ;
V_165 -> V_444 += sizeof V_438 -> V_445 ;
F_124 ( & V_19 -> V_443 , V_159 ) ;
F_22 ( V_438 ) ;
}
}
V_52:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_125 ( struct V_18 * V_19 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_17 (crtc, &dev->mode_config.crtc_list, head)
if ( V_42 -> V_36 -> V_449 )
V_42 -> V_36 -> V_449 ( V_42 ) ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
if ( V_2 -> V_36 -> V_449 )
V_2 -> V_36 -> V_449 ( V_2 ) ;
F_17 (connector, &dev->mode_config.connector_list, head)
if ( V_10 -> V_36 -> V_449 )
V_10 -> V_36 -> V_449 ( V_10 ) ;
}
int F_126 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_450 * args = V_163 ;
if ( ! V_19 -> V_451 -> V_452 )
return - V_372 ;
return V_19 -> V_451 -> V_452 ( V_165 , V_19 , args ) ;
}
int F_127 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_453 * args = V_163 ;
if ( ! V_19 -> V_451 -> V_454 )
return - V_372 ;
return V_19 -> V_451 -> V_454 ( V_165 , V_19 , args -> V_280 , & args -> V_455 ) ;
}
int F_128 ( struct V_18 * V_19 ,
void * V_163 , struct V_164 * V_165 )
{
struct V_456 * args = V_163 ;
if ( ! V_19 -> V_451 -> V_457 )
return - V_372 ;
return V_19 -> V_451 -> V_457 ( V_165 , V_19 , args -> V_280 ) ;
}
void F_129 ( T_1 V_303 , unsigned int * V_284 ,
int * V_283 )
{
switch ( V_303 ) {
case V_286 :
case V_306 :
* V_284 = 8 ;
* V_283 = 8 ;
break;
case V_287 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
* V_284 = 15 ;
* V_283 = 16 ;
break;
case V_288 :
case V_322 :
* V_284 = 16 ;
* V_283 = 16 ;
break;
case V_289 :
case V_323 :
* V_284 = 24 ;
* V_283 = 24 ;
break;
case V_290 :
case V_324 :
case V_325 :
case V_326 :
* V_284 = 24 ;
* V_283 = 32 ;
break;
case V_291 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
* V_284 = 30 ;
* V_283 = 32 ;
break;
case V_292 :
case V_327 :
case V_328 :
case V_329 :
* V_284 = 32 ;
* V_283 = 32 ;
break;
default:
F_37 ( L_55 ) ;
* V_284 = 0 ;
* V_283 = 0 ;
break;
}
}
