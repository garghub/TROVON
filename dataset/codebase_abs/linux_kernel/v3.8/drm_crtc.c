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
F_15 ( & V_34 -> V_37 ) ;
V_24 = F_4 ( V_19 , & V_34 -> V_7 , V_38 ) ;
if ( V_24 )
return V_24 ;
V_34 -> V_19 = V_19 ;
V_34 -> V_36 = V_36 ;
V_19 -> V_26 . V_39 ++ ;
F_16 ( & V_34 -> V_40 , & V_19 -> V_26 . V_41 ) ;
return 0 ;
}
static void F_17 ( struct V_42 * V_42 )
{
struct V_33 * V_34 =
F_18 ( V_42 , struct V_33 , V_37 ) ;
V_34 -> V_36 -> V_43 ( V_34 ) ;
}
void F_19 ( struct V_33 * V_34 )
{
struct V_18 * V_19 = V_34 -> V_19 ;
F_20 ( L_6 , V_34 -> V_7 . V_8 ) ;
F_21 ( ! F_22 ( & V_19 -> V_26 . V_44 ) ) ;
F_23 ( & V_34 -> V_37 , F_17 ) ;
}
void F_24 ( struct V_33 * V_34 )
{
F_20 ( L_6 , V_34 -> V_7 . V_8 ) ;
F_25 ( & V_34 -> V_37 ) ;
}
void F_26 ( struct V_33 * V_34 )
{
struct V_18 * V_19 = V_34 -> V_19 ;
F_10 ( V_19 , & V_34 -> V_7 ) ;
F_27 ( & V_34 -> V_40 ) ;
V_19 -> V_26 . V_39 -- ;
}
void F_28 ( struct V_33 * V_34 )
{
struct V_18 * V_19 = V_34 -> V_19 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 V_50 ;
int V_24 ;
F_29 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_46 -> V_34 == V_34 ) {
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_46 = V_46 ;
V_50 . V_34 = NULL ;
V_24 = V_46 -> V_36 -> V_51 ( & V_50 ) ;
if ( V_24 )
F_6 ( L_7 , V_46 ) ;
}
}
F_29 (plane, &dev->mode_config.plane_list, head) {
if ( V_48 -> V_34 == V_34 ) {
V_24 = V_48 -> V_36 -> V_52 ( V_48 ) ;
if ( V_24 )
F_6 ( L_8 ) ;
V_48 -> V_34 = NULL ;
V_48 -> V_46 = NULL ;
}
}
F_27 ( & V_34 -> V_53 ) ;
F_19 ( V_34 ) ;
}
int F_30 ( struct V_18 * V_19 , struct V_45 * V_46 ,
const struct V_54 * V_36 )
{
int V_24 ;
V_46 -> V_19 = V_19 ;
V_46 -> V_36 = V_36 ;
V_46 -> V_55 = false ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_24 = F_4 ( V_19 , & V_46 -> V_7 , V_56 ) ;
if ( V_24 )
goto V_57;
V_46 -> V_7 . V_58 = & V_46 -> V_58 ;
F_31 ( & V_46 -> V_40 , & V_19 -> V_26 . V_59 ) ;
V_19 -> V_26 . V_60 ++ ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
void F_32 ( struct V_45 * V_46 )
{
struct V_18 * V_19 = V_46 -> V_19 ;
F_33 ( V_46 -> V_61 ) ;
V_46 -> V_61 = NULL ;
F_10 ( V_19 , & V_46 -> V_7 ) ;
F_27 ( & V_46 -> V_40 ) ;
V_19 -> V_26 . V_60 -- ;
}
void F_34 ( struct V_9 * V_10 ,
struct V_62 * V_63 )
{
F_16 ( & V_63 -> V_40 , & V_10 -> V_64 ) ;
}
void F_35 ( struct V_9 * V_10 ,
struct V_62 * V_63 )
{
F_27 ( & V_63 -> V_40 ) ;
F_36 ( V_10 -> V_19 , V_63 ) ;
}
int F_37 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
const struct V_65 * V_36 ,
int V_12 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_24 = F_4 ( V_19 , & V_10 -> V_7 , V_66 ) ;
if ( V_24 )
goto V_57;
V_10 -> V_7 . V_58 = & V_10 -> V_58 ;
V_10 -> V_19 = V_19 ;
V_10 -> V_36 = V_36 ;
V_10 -> V_12 = V_12 ;
V_10 -> V_13 =
++ V_11 [ V_12 ] . V_67 ;
F_38 ( & V_10 -> V_68 ) ;
F_38 ( & V_10 -> V_64 ) ;
F_38 ( & V_10 -> V_69 ) ;
V_10 -> V_70 = NULL ;
V_10 -> V_15 = V_71 ;
F_31 ( & V_10 -> V_40 , & V_19 -> V_26 . V_72 ) ;
V_19 -> V_26 . V_73 ++ ;
if ( V_12 != V_74 )
F_39 ( & V_10 -> V_7 ,
V_19 -> V_26 . V_75 ,
0 ) ;
F_39 ( & V_10 -> V_7 ,
V_19 -> V_26 . V_76 , 0 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
void F_40 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
struct V_62 * V_63 , * V_77 ;
F_41 (mode, t, &connector->probed_modes, head)
F_35 ( V_10 , V_63 ) ;
F_41 (mode, t, &connector->modes, head)
F_35 ( V_10 , V_63 ) ;
F_41 (mode, t, &connector->user_modes, head)
F_35 ( V_10 , V_63 ) ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
F_10 ( V_19 , & V_10 -> V_7 ) ;
F_27 ( & V_10 -> V_40 ) ;
V_19 -> V_26 . V_73 -- ;
F_9 ( & V_19 -> V_26 . V_44 ) ;
}
void F_42 ( struct V_18 * V_19 )
{
struct V_9 * V_10 ;
F_29 (connector, &dev->mode_config.connector_list, head)
F_43 ( V_10 ) ;
}
int F_44 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
const struct V_78 * V_36 ,
int V_5 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_24 = F_4 ( V_19 , & V_2 -> V_7 , V_79 ) ;
if ( V_24 )
goto V_57;
V_2 -> V_19 = V_19 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_36 = V_36 ;
F_31 ( & V_2 -> V_40 , & V_19 -> V_26 . V_80 ) ;
V_19 -> V_26 . V_81 ++ ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
F_10 ( V_19 , & V_2 -> V_7 ) ;
F_27 ( & V_2 -> V_40 ) ;
V_19 -> V_26 . V_81 -- ;
F_9 ( & V_19 -> V_26 . V_44 ) ;
}
int F_46 ( struct V_18 * V_19 , struct V_47 * V_48 ,
unsigned long V_82 ,
const struct V_83 * V_36 ,
const T_1 * V_84 , T_1 V_85 ,
bool V_86 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_24 = F_4 ( V_19 , & V_48 -> V_7 , V_87 ) ;
if ( V_24 )
goto V_57;
V_48 -> V_7 . V_58 = & V_48 -> V_58 ;
V_48 -> V_19 = V_19 ;
V_48 -> V_36 = V_36 ;
V_48 -> V_88 = F_47 ( sizeof( T_1 ) * V_85 ,
V_28 ) ;
if ( ! V_48 -> V_88 ) {
F_48 ( L_9 ) ;
F_10 ( V_19 , & V_48 -> V_7 ) ;
V_24 = - V_29 ;
goto V_57;
}
memcpy ( V_48 -> V_88 , V_84 , V_85 * sizeof( T_1 ) ) ;
V_48 -> V_85 = V_85 ;
V_48 -> V_82 = V_82 ;
if ( ! V_86 ) {
F_31 ( & V_48 -> V_40 , & V_19 -> V_26 . V_89 ) ;
V_19 -> V_26 . V_90 ++ ;
} else {
F_38 ( & V_48 -> V_40 ) ;
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
void F_49 ( struct V_47 * V_48 )
{
struct V_18 * V_19 = V_48 -> V_19 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
F_33 ( V_48 -> V_88 ) ;
F_10 ( V_19 , & V_48 -> V_7 ) ;
if ( ! F_50 ( & V_48 -> V_40 ) ) {
F_27 ( & V_48 -> V_40 ) ;
V_19 -> V_26 . V_90 -- ;
}
F_9 ( & V_19 -> V_26 . V_44 ) ;
}
struct V_62 * F_51 ( struct V_18 * V_19 )
{
struct V_62 * V_91 ;
V_91 = F_52 ( sizeof( struct V_62 ) , V_28 ) ;
if ( ! V_91 )
return NULL ;
if ( F_4 ( V_19 , & V_91 -> V_7 , V_92 ) ) {
F_33 ( V_91 ) ;
return NULL ;
}
return V_91 ;
}
void F_36 ( struct V_18 * V_19 , struct V_62 * V_63 )
{
if ( ! V_63 )
return;
F_10 ( V_19 , & V_63 -> V_7 ) ;
F_33 ( V_63 ) ;
}
static int F_53 ( struct V_18 * V_19 )
{
struct V_93 * V_94 ;
struct V_93 * V_95 ;
V_94 = F_54 ( V_19 , V_96 |
V_97 ,
L_10 , 0 ) ;
V_19 -> V_26 . V_75 = V_94 ;
V_95 = F_55 ( V_19 , 0 ,
L_11 , V_98 ,
F_56 ( V_98 ) ) ;
V_19 -> V_26 . V_76 = V_95 ;
return 0 ;
}
int F_57 ( struct V_18 * V_19 )
{
struct V_93 * V_99 ;
struct V_93 * V_100 ;
if ( V_19 -> V_26 . V_101 )
return 0 ;
V_99 =
F_55 ( V_19 , 0 ,
L_12 ,
V_102 ,
F_56 ( V_102 ) ) ;
V_19 -> V_26 . V_101 = V_99 ;
V_100 = F_55 ( V_19 , V_97 ,
L_13 ,
V_103 ,
F_56 ( V_103 ) ) ;
V_19 -> V_26 . V_104 = V_100 ;
return 0 ;
}
int F_58 ( struct V_18 * V_19 , int V_105 ,
char * V_69 [] )
{
struct V_93 * V_106 ;
struct V_93 * V_107 ;
int V_108 ;
if ( V_19 -> V_26 . V_109 )
return 0 ;
V_106 = F_55 ( V_19 , 0 ,
L_12 ,
V_110 ,
F_56 ( V_110 ) ) ;
V_19 -> V_26 . V_109 = V_106 ;
V_107 =
F_55 ( V_19 , V_97 ,
L_13 ,
V_111 ,
F_56 ( V_111 ) ) ;
V_19 -> V_26 . V_112 = V_107 ;
V_19 -> V_26 . V_113 =
F_59 ( V_19 , 0 , L_14 , 0 , 100 ) ;
V_19 -> V_26 . V_114 =
F_59 ( V_19 , 0 , L_15 , 0 , 100 ) ;
V_19 -> V_26 . V_115 =
F_59 ( V_19 , 0 , L_16 , 0 , 100 ) ;
V_19 -> V_26 . V_116 =
F_59 ( V_19 , 0 , L_17 , 0 , 100 ) ;
V_19 -> V_26 . V_117 =
F_54 ( V_19 , V_118 ,
L_18 , V_105 ) ;
for ( V_108 = 0 ; V_108 < V_105 ; V_108 ++ )
F_60 ( V_19 -> V_26 . V_117 , V_108 ,
V_108 , V_69 [ V_108 ] ) ;
V_19 -> V_26 . V_119 =
F_59 ( V_19 , 0 , L_19 , 0 , 100 ) ;
V_19 -> V_26 . V_120 =
F_59 ( V_19 , 0 , L_20 , 0 , 100 ) ;
V_19 -> V_26 . V_121 =
F_59 ( V_19 , 0 , L_21 , 0 , 100 ) ;
V_19 -> V_26 . V_122 =
F_59 ( V_19 , 0 , L_22 , 0 , 100 ) ;
V_19 -> V_26 . V_123 =
F_59 ( V_19 , 0 , L_23 , 0 , 100 ) ;
V_19 -> V_26 . V_124 =
F_59 ( V_19 , 0 , L_24 , 0 , 100 ) ;
return 0 ;
}
int F_61 ( struct V_18 * V_19 )
{
struct V_93 * V_125 ;
if ( V_19 -> V_26 . V_126 )
return 0 ;
V_125 =
F_55 ( V_19 , 0 , L_25 ,
V_127 ,
F_56 ( V_127 ) ) ;
V_19 -> V_26 . V_126 = V_125 ;
return 0 ;
}
int F_62 ( struct V_18 * V_19 )
{
struct V_93 * V_128 ;
if ( V_19 -> V_26 . V_129 )
return 0 ;
V_128 =
F_55 ( V_19 , 0 , L_26 ,
V_130 ,
F_56 ( V_130 ) ) ;
V_19 -> V_26 . V_129 = V_128 ;
return 0 ;
}
int F_63 ( struct V_18 * V_19 )
{
struct V_93 * V_131 ;
if ( V_19 -> V_26 . V_132 )
return 0 ;
V_131 =
F_55 ( V_19 , V_97 ,
L_27 ,
V_133 ,
F_56 ( V_133 ) ) ;
V_19 -> V_26 . V_132 = V_131 ;
return 0 ;
}
void F_64 ( struct V_18 * V_19 )
{
F_65 ( & V_19 -> V_26 . V_44 ) ;
F_65 ( & V_19 -> V_26 . V_30 ) ;
F_38 ( & V_19 -> V_26 . V_41 ) ;
F_38 ( & V_19 -> V_26 . V_59 ) ;
F_38 ( & V_19 -> V_26 . V_72 ) ;
F_38 ( & V_19 -> V_26 . V_80 ) ;
F_38 ( & V_19 -> V_26 . V_134 ) ;
F_38 ( & V_19 -> V_26 . V_135 ) ;
F_38 ( & V_19 -> V_26 . V_89 ) ;
F_66 ( & V_19 -> V_26 . V_27 ) ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
F_53 ( V_19 ) ;
F_9 ( & V_19 -> V_26 . V_44 ) ;
V_19 -> V_26 . V_39 = 0 ;
V_19 -> V_26 . V_73 = 0 ;
V_19 -> V_26 . V_60 = 0 ;
V_19 -> V_26 . V_81 = 0 ;
}
int F_67 ( struct V_18 * V_19 , struct V_136 * V_137 )
{
T_1 V_138 = 0 ;
V_138 += V_19 -> V_26 . V_60 ;
V_138 += V_19 -> V_26 . V_73 ;
V_138 += V_19 -> V_26 . V_81 ;
V_137 -> V_139 = F_52 ( V_138 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_137 -> V_139 )
return - V_29 ;
V_137 -> V_140 = 0 ;
V_137 -> V_141 = 0 ;
V_137 -> V_142 = 0 ;
return 0 ;
}
int F_68 ( struct V_18 * V_19 ,
struct V_136 * V_137 )
{
struct V_45 * V_46 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_24 ;
if ( ( V_24 = F_67 ( V_19 , V_137 ) ) )
return V_24 ;
F_29 (crtc, &dev->mode_config.crtc_list, head)
V_137 -> V_139 [ V_137 -> V_140 ++ ] = V_46 -> V_7 . V_8 ;
F_29 (encoder, &dev->mode_config.encoder_list, head)
V_137 -> V_139 [ V_137 -> V_140 + V_137 -> V_142 ++ ] =
V_2 -> V_7 . V_8 ;
F_29 (connector, &dev->mode_config.connector_list, head)
V_137 -> V_139 [ V_137 -> V_140 + V_137 -> V_142 +
V_137 -> V_141 ++ ] = V_10 -> V_7 . V_8 ;
return 0 ;
}
void F_69 ( struct V_18 * V_19 )
{
struct V_9 * V_10 , * V_143 ;
struct V_45 * V_46 , * V_144 ;
struct V_1 * V_2 , * V_145 ;
struct V_33 * V_34 , * V_146 ;
struct V_93 * V_147 , * V_148 ;
struct V_47 * V_48 , * V_149 ;
F_41 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_2 -> V_36 -> V_43 ( V_2 ) ;
}
F_41 (connector, ot,
&dev->mode_config.connector_list, head) {
V_10 -> V_36 -> V_43 ( V_10 ) ;
}
F_41 (property, pt, &dev->mode_config.property_list,
head) {
F_70 ( V_19 , V_147 ) ;
}
F_41 (fb, fbt, &dev->mode_config.fb_list, head) {
F_28 ( V_34 ) ;
}
F_41 (plane, plt, &dev->mode_config.plane_list,
head) {
V_48 -> V_36 -> V_43 ( V_48 ) ;
}
F_41 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_46 -> V_36 -> V_43 ( V_46 ) ;
}
F_71 ( & V_19 -> V_26 . V_27 ) ;
F_72 ( & V_19 -> V_26 . V_27 ) ;
}
static void F_73 ( struct V_150 * V_57 ,
const struct V_62 * V_151 )
{
F_74 ( V_151 -> V_152 > V_153 || V_151 -> V_154 > V_153 ||
V_151 -> V_155 > V_153 || V_151 -> V_156 > V_153 ||
V_151 -> V_157 > V_153 || V_151 -> V_158 > V_153 ||
V_151 -> V_159 > V_153 || V_151 -> V_160 > V_153 ||
V_151 -> V_161 > V_153 || V_151 -> V_162 > V_153 ,
L_28 ) ;
V_57 -> clock = V_151 -> clock ;
V_57 -> V_152 = V_151 -> V_152 ;
V_57 -> V_154 = V_151 -> V_154 ;
V_57 -> V_155 = V_151 -> V_155 ;
V_57 -> V_156 = V_151 -> V_156 ;
V_57 -> V_157 = V_151 -> V_157 ;
V_57 -> V_158 = V_151 -> V_158 ;
V_57 -> V_159 = V_151 -> V_159 ;
V_57 -> V_160 = V_151 -> V_160 ;
V_57 -> V_161 = V_151 -> V_161 ;
V_57 -> V_162 = V_151 -> V_162 ;
V_57 -> V_163 = V_151 -> V_163 ;
V_57 -> V_164 = V_151 -> V_164 ;
V_57 -> type = V_151 -> type ;
strncpy ( V_57 -> V_6 , V_151 -> V_6 , V_165 ) ;
V_57 -> V_6 [ V_165 - 1 ] = 0 ;
}
static int F_75 ( struct V_62 * V_57 ,
const struct V_150 * V_151 )
{
if ( V_151 -> clock > V_166 || V_151 -> V_163 > V_166 )
return - V_167 ;
V_57 -> clock = V_151 -> clock ;
V_57 -> V_152 = V_151 -> V_152 ;
V_57 -> V_154 = V_151 -> V_154 ;
V_57 -> V_155 = V_151 -> V_155 ;
V_57 -> V_156 = V_151 -> V_156 ;
V_57 -> V_157 = V_151 -> V_157 ;
V_57 -> V_158 = V_151 -> V_158 ;
V_57 -> V_159 = V_151 -> V_159 ;
V_57 -> V_160 = V_151 -> V_160 ;
V_57 -> V_161 = V_151 -> V_161 ;
V_57 -> V_162 = V_151 -> V_162 ;
V_57 -> V_163 = V_151 -> V_163 ;
V_57 -> V_164 = V_151 -> V_164 ;
V_57 -> type = V_151 -> type ;
strncpy ( V_57 -> V_6 , V_151 -> V_6 , V_165 ) ;
V_57 -> V_6 [ V_165 - 1 ] = 0 ;
return 0 ;
}
int F_76 ( struct V_18 * V_19 , void * V_168 ,
struct V_169 * V_170 )
{
struct V_171 * V_172 = V_168 ;
struct V_173 * V_174 ;
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_45 * V_46 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
int V_175 = 0 ;
int V_176 = 0 ;
int V_177 = 0 ;
int V_178 = 0 ;
int V_179 = 0 , V_108 ;
T_1 T_2 * V_180 ;
T_1 T_2 * V_181 ;
T_1 T_2 * V_182 ;
T_1 T_2 * V_183 ;
struct V_136 * V_184 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
F_78 (lh, &file_priv->fbs)
V_177 ++ ;
V_184 = & V_170 -> V_187 -> V_188 -> V_184 ;
if ( V_170 -> V_187 -> V_188 -> type == V_189 ) {
F_78 (lh, &dev->mode_config.crtc_list)
V_176 ++ ;
F_78 (lh, &dev->mode_config.connector_list)
V_175 ++ ;
F_78 (lh, &dev->mode_config.encoder_list)
V_178 ++ ;
} else {
V_176 = V_184 -> V_140 ;
V_175 = V_184 -> V_141 ;
V_178 = V_184 -> V_142 ;
}
V_172 -> V_190 = V_19 -> V_26 . V_190 ;
V_172 -> V_191 = V_19 -> V_26 . V_191 ;
V_172 -> V_192 = V_19 -> V_26 . V_192 ;
V_172 -> V_193 = V_19 -> V_26 . V_193 ;
if ( V_172 -> V_194 >= V_177 ) {
V_179 = 0 ;
V_180 = ( T_1 T_2 * ) ( unsigned long ) V_172 -> V_195 ;
F_29 (fb, &file_priv->fbs, filp_head) {
if ( F_79 ( V_34 -> V_7 . V_8 , V_180 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
}
V_172 -> V_194 = V_177 ;
if ( V_172 -> V_197 >= V_176 ) {
V_179 = 0 ;
V_181 = ( T_1 T_2 * ) ( unsigned long ) V_172 -> V_198 ;
if ( V_170 -> V_187 -> V_188 -> type == V_189 ) {
F_29 (crtc, &dev->mode_config.crtc_list,
head) {
F_48 ( L_29 , V_46 -> V_7 . V_8 ) ;
if ( F_79 ( V_46 -> V_7 . V_8 , V_181 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
} else {
for ( V_108 = 0 ; V_108 < V_184 -> V_140 ; V_108 ++ ) {
if ( F_79 ( V_184 -> V_139 [ V_108 ] ,
V_181 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
}
}
V_172 -> V_197 = V_176 ;
if ( V_172 -> V_199 >= V_178 ) {
V_179 = 0 ;
V_183 = ( T_1 T_2 * ) ( unsigned long ) V_172 -> V_200 ;
if ( V_170 -> V_187 -> V_188 -> type == V_189 ) {
F_29 (encoder,
&dev->mode_config.encoder_list,
head) {
F_48 ( L_30 , V_2 -> V_7 . V_8 ,
F_1 ( V_2 ) ) ;
if ( F_79 ( V_2 -> V_7 . V_8 , V_183 +
V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
} else {
for ( V_108 = V_184 -> V_140 ; V_108 < V_184 -> V_140 + V_184 -> V_142 ; V_108 ++ ) {
if ( F_79 ( V_184 -> V_139 [ V_108 ] ,
V_183 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
}
}
V_172 -> V_199 = V_178 ;
if ( V_172 -> V_201 >= V_175 ) {
V_179 = 0 ;
V_182 = ( T_1 T_2 * ) ( unsigned long ) V_172 -> V_202 ;
if ( V_170 -> V_187 -> V_188 -> type == V_189 ) {
F_29 (connector,
&dev->mode_config.connector_list,
head) {
F_48 ( L_31 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
if ( F_79 ( V_10 -> V_7 . V_8 ,
V_182 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
} else {
int V_203 = V_184 -> V_140 +
V_184 -> V_142 ;
for ( V_108 = V_203 ; V_108 < V_203 + V_184 -> V_141 ; V_108 ++ ) {
if ( F_79 ( V_184 -> V_139 [ V_108 ] ,
V_182 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
}
}
V_172 -> V_201 = V_175 ;
F_48 ( L_32 , V_172 -> V_197 ,
V_172 -> V_201 , V_172 -> V_199 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_80 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_204 * V_205 = V_168 ;
struct V_45 * V_46 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_205 -> V_181 ,
V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
V_205 -> V_206 = V_46 -> V_206 ;
V_205 -> V_207 = V_46 -> V_207 ;
V_205 -> V_208 = V_46 -> V_208 ;
if ( V_46 -> V_34 )
V_205 -> V_180 = V_46 -> V_34 -> V_7 . V_8 ;
else
V_205 -> V_180 = 0 ;
if ( V_46 -> V_209 ) {
F_73 ( & V_205 -> V_63 , & V_46 -> V_63 ) ;
V_205 -> V_210 = 1 ;
} else {
V_205 -> V_210 = 0 ;
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_82 ( struct V_18 * V_19 , void * V_168 ,
struct V_169 * V_170 )
{
struct V_211 * V_212 = V_168 ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
struct V_62 * V_63 ;
int V_213 = 0 ;
int V_214 = 0 ;
int V_215 = 0 ;
int V_24 = 0 ;
int V_179 = 0 ;
int V_108 ;
struct V_150 V_216 ;
struct V_150 T_2 * V_217 ;
T_1 T_2 * V_218 ;
T_3 T_2 * V_219 ;
T_1 T_2 * V_220 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
memset ( & V_216 , 0 , sizeof( struct V_150 ) ) ;
F_48 ( L_33 , V_212 -> V_182 ) ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_212 -> V_182 ,
V_66 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
V_10 = F_83 ( V_21 ) ;
V_214 = V_10 -> V_58 . V_67 ;
for ( V_108 = 0 ; V_108 < V_221 ; V_108 ++ ) {
if ( V_10 -> V_222 [ V_108 ] != 0 ) {
V_215 ++ ;
}
}
if ( V_212 -> V_223 == 0 ) {
V_10 -> V_36 -> V_224 ( V_10 ,
V_19 -> V_26 . V_192 ,
V_19 -> V_26 . V_190 ) ;
}
F_29 (mode, &connector->modes, head)
V_213 ++ ;
V_212 -> V_182 = V_10 -> V_7 . V_8 ;
V_212 -> V_12 = V_10 -> V_12 ;
V_212 -> V_13 = V_10 -> V_13 ;
V_212 -> V_225 = V_10 -> V_226 . V_227 ;
V_212 -> V_228 = V_10 -> V_226 . V_229 ;
V_212 -> V_230 = V_10 -> V_226 . V_231 ;
V_212 -> V_232 = V_10 -> V_15 ;
if ( V_10 -> V_2 )
V_212 -> V_183 = V_10 -> V_2 -> V_7 . V_8 ;
else
V_212 -> V_183 = 0 ;
if ( ( V_212 -> V_223 >= V_213 ) && V_213 ) {
V_179 = 0 ;
V_217 = (struct V_150 T_2 * ) ( unsigned long ) V_212 -> V_233 ;
F_29 (mode, &connector->modes, head) {
F_73 ( & V_216 , V_63 ) ;
if ( F_84 ( V_217 + V_179 ,
& V_216 , sizeof( V_216 ) ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
}
V_212 -> V_223 = V_213 ;
if ( ( V_212 -> V_234 >= V_214 ) && V_214 ) {
V_179 = 0 ;
V_218 = ( T_1 T_2 * ) ( unsigned long ) ( V_212 -> V_235 ) ;
V_219 = ( T_3 T_2 * ) ( unsigned long ) ( V_212 -> V_236 ) ;
for ( V_108 = 0 ; V_108 < V_10 -> V_58 . V_67 ; V_108 ++ ) {
if ( F_79 ( V_10 -> V_58 . V_237 [ V_108 ] ,
V_218 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
if ( F_79 ( V_10 -> V_58 . V_238 [ V_108 ] ,
V_219 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
}
V_212 -> V_234 = V_214 ;
if ( ( V_212 -> V_199 >= V_215 ) && V_215 ) {
V_179 = 0 ;
V_220 = ( T_1 T_2 * ) ( unsigned long ) ( V_212 -> V_239 ) ;
for ( V_108 = 0 ; V_108 < V_221 ; V_108 ++ ) {
if ( V_10 -> V_222 [ V_108 ] != 0 ) {
if ( F_79 ( V_10 -> V_222 [ V_108 ] ,
V_220 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
}
}
V_212 -> V_199 = V_215 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_85 ( struct V_18 * V_19 , void * V_168 ,
struct V_169 * V_170 )
{
struct V_240 * V_241 = V_168 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_241 -> V_183 ,
V_79 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
V_2 = F_86 ( V_21 ) ;
if ( V_2 -> V_46 )
V_241 -> V_181 = V_2 -> V_46 -> V_7 . V_8 ;
else
V_241 -> V_181 = 0 ;
V_241 -> V_5 = V_2 -> V_5 ;
V_241 -> V_183 = V_2 -> V_7 . V_8 ;
V_241 -> V_82 = V_2 -> V_82 ;
V_241 -> V_242 = V_2 -> V_242 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_87 ( struct V_18 * V_19 , void * V_168 ,
struct V_169 * V_170 )
{
struct V_243 * V_244 = V_168 ;
struct V_245 * V_246 ;
struct V_47 * V_48 ;
T_1 T_2 * V_247 ;
int V_179 = 0 , V_24 = 0 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_246 = & V_19 -> V_26 ;
if ( V_246 -> V_90 &&
( V_244 -> V_248 >= V_246 -> V_90 ) ) {
V_247 = ( T_1 T_2 * ) ( unsigned long ) V_244 -> V_249 ;
F_29 (plane, &config->plane_list, head) {
if ( F_79 ( V_48 -> V_7 . V_8 , V_247 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
}
V_244 -> V_248 = V_246 -> V_90 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_88 ( struct V_18 * V_19 , void * V_168 ,
struct V_169 * V_170 )
{
struct V_250 * V_244 = V_168 ;
struct V_20 * V_21 ;
struct V_47 * V_48 ;
T_1 T_2 * V_251 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_244 -> V_252 ,
V_87 ) ;
if ( ! V_21 ) {
V_24 = - V_253 ;
goto V_57;
}
V_48 = F_89 ( V_21 ) ;
if ( V_48 -> V_46 )
V_244 -> V_181 = V_48 -> V_46 -> V_7 . V_8 ;
else
V_244 -> V_181 = 0 ;
if ( V_48 -> V_34 )
V_244 -> V_180 = V_48 -> V_34 -> V_7 . V_8 ;
else
V_244 -> V_180 = 0 ;
V_244 -> V_252 = V_48 -> V_7 . V_8 ;
V_244 -> V_82 = V_48 -> V_82 ;
V_244 -> V_208 = V_48 -> V_208 ;
if ( V_48 -> V_85 &&
( V_244 -> V_254 >= V_48 -> V_85 ) ) {
V_251 = ( T_1 T_2 * ) ( unsigned long ) V_244 -> V_255 ;
if ( F_84 ( V_251 ,
V_48 -> V_88 ,
sizeof( T_1 ) * V_48 -> V_85 ) ) {
V_24 = - V_196 ;
goto V_57;
}
}
V_244 -> V_254 = V_48 -> V_85 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_90 ( struct V_18 * V_19 , void * V_168 ,
struct V_169 * V_170 )
{
struct V_256 * V_257 = V_168 ;
struct V_20 * V_21 ;
struct V_47 * V_48 ;
struct V_45 * V_46 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
unsigned int V_258 , V_259 ;
int V_108 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_257 -> V_252 ,
V_87 ) ;
if ( ! V_21 ) {
F_48 ( L_34 ,
V_257 -> V_252 ) ;
V_24 = - V_253 ;
goto V_57;
}
V_48 = F_89 ( V_21 ) ;
if ( ! V_257 -> V_180 ) {
V_48 -> V_36 -> V_52 ( V_48 ) ;
V_48 -> V_46 = NULL ;
V_48 -> V_34 = NULL ;
goto V_57;
}
V_21 = F_12 ( V_19 , V_257 -> V_181 ,
V_56 ) ;
if ( ! V_21 ) {
F_48 ( L_35 ,
V_257 -> V_181 ) ;
V_24 = - V_253 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
V_21 = F_12 ( V_19 , V_257 -> V_180 ,
V_38 ) ;
if ( ! V_21 ) {
F_48 ( L_36 ,
V_257 -> V_180 ) ;
V_24 = - V_253 ;
goto V_57;
}
V_34 = F_91 ( V_21 ) ;
for ( V_108 = 0 ; V_108 < V_48 -> V_85 ; V_108 ++ )
if ( V_34 -> V_260 == V_48 -> V_88 [ V_108 ] )
break;
if ( V_108 == V_48 -> V_85 ) {
F_48 ( L_37 , V_34 -> V_260 ) ;
V_24 = - V_186 ;
goto V_57;
}
V_258 = V_34 -> V_261 << 16 ;
V_259 = V_34 -> V_262 << 16 ;
if ( V_257 -> V_263 > V_258 ||
V_257 -> V_264 > V_258 - V_257 -> V_263 ||
V_257 -> V_265 > V_259 ||
V_257 -> V_266 > V_259 - V_257 -> V_265 ) {
F_48 ( L_38
L_39 ,
V_257 -> V_263 >> 16 ,
( ( V_257 -> V_263 & 0xffff ) * 15625 ) >> 10 ,
V_257 -> V_265 >> 16 ,
( ( V_257 -> V_265 & 0xffff ) * 15625 ) >> 10 ,
V_257 -> V_264 >> 16 ,
( ( V_257 -> V_264 & 0xffff ) * 15625 ) >> 10 ,
V_257 -> V_266 >> 16 ,
( ( V_257 -> V_266 & 0xffff ) * 15625 ) >> 10 ) ;
V_24 = - V_267 ;
goto V_57;
}
if ( V_257 -> V_268 > V_166 ||
V_257 -> V_269 > V_166 - ( V_270 ) V_257 -> V_268 ||
V_257 -> V_271 > V_166 ||
V_257 -> V_272 > V_166 - ( V_270 ) V_257 -> V_271 ) {
F_48 ( L_40 ,
V_257 -> V_268 , V_257 -> V_271 ,
V_257 -> V_269 , V_257 -> V_272 ) ;
V_24 = - V_167 ;
goto V_57;
}
V_24 = V_48 -> V_36 -> V_273 ( V_48 , V_46 , V_34 ,
V_257 -> V_269 , V_257 -> V_272 ,
V_257 -> V_268 , V_257 -> V_271 ,
V_257 -> V_264 , V_257 -> V_266 ,
V_257 -> V_263 , V_257 -> V_265 ) ;
if ( ! V_24 ) {
V_48 -> V_46 = V_46 ;
V_48 -> V_34 = V_34 ;
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_92 ( struct V_18 * V_19 , void * V_168 ,
struct V_169 * V_170 )
{
struct V_245 * V_246 = & V_19 -> V_26 ;
struct V_204 * V_274 = V_168 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
struct V_9 * * V_275 = NULL , * V_10 ;
struct V_33 * V_34 = NULL ;
struct V_62 * V_63 = NULL ;
struct V_49 V_50 ;
T_1 T_2 * V_276 ;
int V_24 ;
int V_108 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
if ( V_274 -> V_206 > V_166 || V_274 -> V_207 > V_166 )
return - V_167 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_274 -> V_181 ,
V_56 ) ;
if ( ! V_21 ) {
F_48 ( L_41 , V_274 -> V_181 ) ;
V_24 = - V_186 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
F_48 ( L_29 , V_46 -> V_7 . V_8 ) ;
if ( V_274 -> V_210 ) {
int V_152 , V_158 ;
if ( V_274 -> V_180 == - 1 ) {
if ( ! V_46 -> V_34 ) {
F_48 ( L_42 ) ;
V_24 = - V_186 ;
goto V_57;
}
V_34 = V_46 -> V_34 ;
} else {
V_21 = F_12 ( V_19 , V_274 -> V_180 ,
V_38 ) ;
if ( ! V_21 ) {
F_48 ( L_43 ,
V_274 -> V_180 ) ;
V_24 = - V_186 ;
goto V_57;
}
V_34 = F_91 ( V_21 ) ;
}
V_63 = F_51 ( V_19 ) ;
if ( ! V_63 ) {
V_24 = - V_29 ;
goto V_57;
}
V_24 = F_75 ( V_63 , & V_274 -> V_63 ) ;
if ( V_24 ) {
F_48 ( L_44 ) ;
goto V_57;
}
F_93 ( V_63 , V_277 ) ;
V_152 = V_63 -> V_152 ;
V_158 = V_63 -> V_158 ;
if ( V_46 -> V_55 )
F_94 ( V_152 , V_158 ) ;
if ( V_152 > V_34 -> V_261 ||
V_158 > V_34 -> V_262 ||
V_274 -> V_206 > V_34 -> V_261 - V_152 ||
V_274 -> V_207 > V_34 -> V_262 - V_158 ) {
F_48 ( L_45 ,
V_34 -> V_261 , V_34 -> V_262 ,
V_152 , V_158 , V_274 -> V_206 , V_274 -> V_207 ,
V_46 -> V_55 ? L_46 : L_47 ) ;
V_24 = - V_267 ;
goto V_57;
}
}
if ( V_274 -> V_201 == 0 && V_63 ) {
F_48 ( L_48 ) ;
V_24 = - V_186 ;
goto V_57;
}
if ( V_274 -> V_201 > 0 && ( ! V_63 || ! V_34 ) ) {
F_48 ( L_49 ,
V_274 -> V_201 ) ;
V_24 = - V_186 ;
goto V_57;
}
if ( V_274 -> V_201 > 0 ) {
T_4 V_278 ;
if ( V_274 -> V_201 > V_246 -> V_73 ) {
V_24 = - V_186 ;
goto V_57;
}
V_275 = F_47 ( V_274 -> V_201 *
sizeof( struct V_9 * ) ,
V_28 ) ;
if ( ! V_275 ) {
V_24 = - V_29 ;
goto V_57;
}
for ( V_108 = 0 ; V_108 < V_274 -> V_201 ; V_108 ++ ) {
V_276 = ( T_1 T_2 * ) ( unsigned long ) V_274 -> V_276 ;
if ( F_95 ( V_278 , & V_276 [ V_108 ] ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_21 = F_12 ( V_19 , V_278 ,
V_66 ) ;
if ( ! V_21 ) {
F_48 ( L_50 ,
V_278 ) ;
V_24 = - V_186 ;
goto V_57;
}
V_10 = F_83 ( V_21 ) ;
F_48 ( L_31 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
V_275 [ V_108 ] = V_10 ;
}
}
V_50 . V_46 = V_46 ;
V_50 . V_206 = V_274 -> V_206 ;
V_50 . V_207 = V_274 -> V_207 ;
V_50 . V_63 = V_63 ;
V_50 . V_279 = V_275 ;
V_50 . V_141 = V_274 -> V_201 ;
V_50 . V_34 = V_34 ;
V_24 = V_46 -> V_36 -> V_51 ( & V_50 ) ;
V_57:
F_33 ( V_275 ) ;
F_36 ( V_19 , V_63 ) ;
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_96 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_280 * V_281 = V_168 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
if ( ! V_281 -> V_164 || ( ~ V_282 & V_281 -> V_164 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_281 -> V_181 , V_56 ) ;
if ( ! V_21 ) {
F_48 ( L_41 , V_281 -> V_181 ) ;
V_24 = - V_186 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
if ( V_281 -> V_164 & V_283 ) {
if ( ! V_46 -> V_36 -> V_284 ) {
V_24 = - V_285 ;
goto V_57;
}
V_24 = V_46 -> V_36 -> V_284 ( V_46 , V_170 , V_281 -> V_286 ,
V_281 -> V_261 , V_281 -> V_262 ) ;
}
if ( V_281 -> V_164 & V_287 ) {
if ( V_46 -> V_36 -> V_288 ) {
V_24 = V_46 -> V_36 -> V_288 ( V_46 , V_281 -> V_206 , V_281 -> V_207 ) ;
} else {
V_24 = - V_196 ;
goto V_57;
}
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
T_1 F_97 ( T_1 V_289 , T_1 V_290 )
{
T_1 V_291 ;
switch ( V_289 ) {
case 8 :
V_291 = V_292 ;
break;
case 16 :
if ( V_290 == 15 )
V_291 = V_293 ;
else
V_291 = V_294 ;
break;
case 24 :
V_291 = V_295 ;
break;
case 32 :
if ( V_290 == 24 )
V_291 = V_296 ;
else if ( V_290 == 30 )
V_291 = V_297 ;
else
V_291 = V_298 ;
break;
default:
F_6 ( L_51 ) ;
V_291 = V_296 ;
break;
}
return V_291 ;
}
int F_98 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_299 * V_300 = V_168 ;
struct V_301 V_302 = {} ;
struct V_245 * V_246 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
V_302 . V_180 = V_300 -> V_180 ;
V_302 . V_261 = V_300 -> V_261 ;
V_302 . V_262 = V_300 -> V_262 ;
V_302 . V_303 [ 0 ] = V_300 -> V_304 ;
V_302 . V_260 = F_97 ( V_300 -> V_289 , V_300 -> V_290 ) ;
V_302 . V_305 [ 0 ] = V_300 -> V_286 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
if ( ( V_246 -> V_193 > V_302 . V_261 ) || ( V_302 . V_261 > V_246 -> V_192 ) )
return - V_186 ;
if ( ( V_246 -> V_191 > V_302 . V_262 ) || ( V_302 . V_262 > V_246 -> V_190 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_306 ( V_19 , V_170 , & V_302 ) ;
if ( F_99 ( V_34 ) ) {
F_48 ( L_52 ) ;
V_24 = F_100 ( V_34 ) ;
goto V_57;
}
V_300 -> V_180 = V_34 -> V_7 . V_8 ;
F_16 ( & V_34 -> V_53 , & V_170 -> V_307 ) ;
F_48 ( L_53 , V_34 -> V_7 . V_8 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
static int F_101 ( const struct V_301 * V_302 )
{
T_1 V_308 = V_302 -> V_260 & ~ V_309 ;
switch ( V_308 ) {
case V_310 :
case V_292 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_293 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_294 :
case V_327 :
case V_295 :
case V_328 :
case V_296 :
case V_329 :
case V_330 :
case V_331 :
case V_298 :
case V_332 :
case V_333 :
case V_334 :
case V_297 :
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
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
return 0 ;
default:
return - V_186 ;
}
}
static int F_102 ( const struct V_301 * V_302 )
{
int V_24 , V_363 , V_364 , V_365 , V_108 ;
V_24 = F_101 ( V_302 ) ;
if ( V_24 ) {
F_48 ( L_54 , V_302 -> V_260 ) ;
return V_24 ;
}
V_363 = F_103 ( V_302 -> V_260 ) ;
V_364 = F_104 ( V_302 -> V_260 ) ;
V_365 = F_105 ( V_302 -> V_260 ) ;
if ( V_302 -> V_261 == 0 || V_302 -> V_261 % V_363 ) {
F_48 ( L_55 , V_302 -> V_262 ) ;
return - V_186 ;
}
if ( V_302 -> V_262 == 0 || V_302 -> V_262 % V_364 ) {
F_48 ( L_56 , V_302 -> V_262 ) ;
return - V_186 ;
}
for ( V_108 = 0 ; V_108 < V_365 ; V_108 ++ ) {
unsigned int V_261 = V_302 -> V_261 / ( V_108 != 0 ? V_363 : 1 ) ;
unsigned int V_262 = V_302 -> V_262 / ( V_108 != 0 ? V_364 : 1 ) ;
unsigned int V_366 = F_106 ( V_302 -> V_260 , V_108 ) ;
if ( ! V_302 -> V_305 [ V_108 ] ) {
F_48 ( L_57 , V_108 ) ;
return - V_186 ;
}
if ( ( T_3 ) V_261 * V_366 > V_367 )
return - V_167 ;
if ( ( T_3 ) V_262 * V_302 -> V_303 [ V_108 ] + V_302 -> V_368 [ V_108 ] > V_367 )
return - V_167 ;
if ( V_302 -> V_303 [ V_108 ] < V_261 * V_366 ) {
F_48 ( L_58 , V_302 -> V_303 [ V_108 ] , V_108 ) ;
return - V_186 ;
}
}
return 0 ;
}
int F_107 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_301 * V_302 = V_168 ;
struct V_245 * V_246 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
if ( V_302 -> V_164 & ~ V_369 ) {
F_48 ( L_59 , V_302 -> V_164 ) ;
return - V_186 ;
}
if ( ( V_246 -> V_193 > V_302 -> V_261 ) || ( V_302 -> V_261 > V_246 -> V_192 ) ) {
F_48 ( L_60 ,
V_302 -> V_261 , V_246 -> V_193 , V_246 -> V_192 ) ;
return - V_186 ;
}
if ( ( V_246 -> V_191 > V_302 -> V_262 ) || ( V_302 -> V_262 > V_246 -> V_190 ) ) {
F_48 ( L_61 ,
V_302 -> V_262 , V_246 -> V_191 , V_246 -> V_190 ) ;
return - V_186 ;
}
V_24 = F_102 ( V_302 ) ;
if ( V_24 )
return V_24 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_306 ( V_19 , V_170 , V_302 ) ;
if ( F_99 ( V_34 ) ) {
F_48 ( L_52 ) ;
V_24 = F_100 ( V_34 ) ;
goto V_57;
}
V_302 -> V_180 = V_34 -> V_7 . V_8 ;
F_16 ( & V_34 -> V_53 , & V_170 -> V_307 ) ;
F_48 ( L_53 , V_34 -> V_7 . V_8 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_108 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_20 * V_21 ;
struct V_33 * V_34 = NULL ;
struct V_33 * V_370 = NULL ;
T_1 * V_8 = V_168 ;
int V_24 = 0 ;
int V_371 = 0 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , * V_8 , V_38 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
V_34 = F_91 ( V_21 ) ;
F_29 (fbl, &file_priv->fbs, filp_head)
if ( V_34 == V_370 )
V_371 = 1 ;
if ( ! V_371 ) {
V_24 = - V_186 ;
goto V_57;
}
F_28 ( V_34 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_109 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_299 * V_302 = V_168 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_302 -> V_180 , V_38 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
V_34 = F_91 ( V_21 ) ;
V_302 -> V_262 = V_34 -> V_262 ;
V_302 -> V_261 = V_34 -> V_261 ;
V_302 -> V_290 = V_34 -> V_290 ;
V_302 -> V_289 = V_34 -> V_372 ;
V_302 -> V_304 = V_34 -> V_303 [ 0 ] ;
V_34 -> V_36 -> V_373 ( V_34 , V_170 , & V_302 -> V_286 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_110 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_374 T_2 * V_375 ;
struct V_374 * V_376 = NULL ;
struct V_377 * V_302 = V_168 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
unsigned V_164 ;
int V_378 ;
int V_24 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_302 -> V_180 , V_38 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_379;
}
V_34 = F_91 ( V_21 ) ;
V_378 = V_302 -> V_378 ;
V_375 = (struct V_374 T_2 * ) ( unsigned long ) V_302 -> V_375 ;
if ( ! V_378 != ! V_375 ) {
V_24 = - V_186 ;
goto V_379;
}
V_164 = V_380 & V_302 -> V_164 ;
if ( V_164 & V_381 && ( V_378 % 2 ) ) {
V_24 = - V_186 ;
goto V_379;
}
if ( V_378 && V_375 ) {
if ( V_378 < 0 || V_378 > V_382 ) {
V_24 = - V_186 ;
goto V_379;
}
V_376 = F_52 ( V_378 * sizeof( * V_376 ) , V_28 ) ;
if ( ! V_376 ) {
V_24 = - V_29 ;
goto V_379;
}
V_24 = F_111 ( V_376 , V_375 ,
V_378 * sizeof( * V_376 ) ) ;
if ( V_24 ) {
V_24 = - V_196 ;
goto V_383;
}
}
if ( V_34 -> V_36 -> V_384 ) {
V_24 = V_34 -> V_36 -> V_384 ( V_34 , V_170 , V_164 , V_302 -> V_385 ,
V_376 , V_378 ) ;
} else {
V_24 = - V_386 ;
goto V_383;
}
V_383:
F_33 ( V_376 ) ;
V_379:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
void F_112 ( struct V_169 * V_86 )
{
struct V_18 * V_19 = V_86 -> V_188 -> V_19 ;
struct V_33 * V_34 , * V_387 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
F_41 (fb, tfb, &priv->fbs, filp_head) {
F_28 ( V_34 ) ;
}
F_9 ( & V_19 -> V_26 . V_44 ) ;
}
static void F_113 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_62 * V_63 )
{
F_31 ( & V_63 -> V_40 , & V_10 -> V_68 ) ;
}
int F_114 ( struct V_18 * V_19 , struct V_45 * V_46 ,
const struct V_62 * V_63 )
{
struct V_9 * V_10 ;
int V_24 = 0 ;
struct V_62 * V_388 , * V_389 ;
F_115 ( V_390 ) ;
F_29 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
continue;
if ( V_10 -> V_2 -> V_46 == V_46 ) {
V_388 = F_116 ( V_19 , V_63 ) ;
if ( ! V_388 ) {
V_24 = - V_29 ;
goto V_57;
}
F_31 ( & V_388 -> V_40 , & V_390 ) ;
}
}
F_29 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
continue;
if ( V_10 -> V_2 -> V_46 == V_46 )
F_117 ( V_390 . V_389 , & V_10 -> V_68 ) ;
}
F_21 ( ! F_50 ( & V_390 ) ) ;
V_57:
F_41 (dup_mode, next, &list, head)
F_36 ( V_19 , V_388 ) ;
return V_24 ;
}
static int F_118 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_62 * V_63 )
{
int V_371 = 0 ;
int V_24 = 0 ;
struct V_62 * V_391 , * V_77 ;
F_41 (match_mode, t, &connector->user_modes, head) {
if ( F_119 ( V_391 , V_63 ) ) {
F_27 ( & V_391 -> V_40 ) ;
F_36 ( V_19 , V_391 ) ;
V_371 = 1 ;
break;
}
}
if ( ! V_371 )
V_24 = - V_186 ;
return V_24 ;
}
int F_120 ( struct V_18 * V_19 , struct V_62 * V_63 )
{
struct V_9 * V_10 ;
F_29 (connector, &dev->mode_config.connector_list, head) {
F_118 ( V_19 , V_10 , V_63 ) ;
}
return 0 ;
}
int F_121 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_392 * V_393 = V_168 ;
struct V_9 * V_10 ;
struct V_62 * V_63 ;
struct V_20 * V_21 ;
struct V_150 * V_394 = & V_393 -> V_63 ;
int V_24 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_393 -> V_182 , V_66 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
V_10 = F_83 ( V_21 ) ;
V_63 = F_51 ( V_19 ) ;
if ( ! V_63 ) {
V_24 = - V_29 ;
goto V_57;
}
V_24 = F_75 ( V_63 , V_394 ) ;
if ( V_24 ) {
F_48 ( L_44 ) ;
F_36 ( V_19 , V_63 ) ;
goto V_57;
}
F_113 ( V_19 , V_10 , V_63 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_122 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_20 * V_21 ;
struct V_392 * V_393 = V_168 ;
struct V_9 * V_10 ;
struct V_62 V_63 ;
struct V_150 * V_394 = & V_393 -> V_63 ;
int V_24 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_393 -> V_182 , V_66 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
V_10 = F_83 ( V_21 ) ;
V_24 = F_75 ( & V_63 , V_394 ) ;
if ( V_24 ) {
F_48 ( L_44 ) ;
goto V_57;
}
V_24 = F_118 ( V_19 , V_10 , & V_63 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
struct V_93 * F_54 ( struct V_18 * V_19 , int V_164 ,
const char * V_6 , int V_395 )
{
struct V_93 * V_147 = NULL ;
int V_24 ;
V_147 = F_52 ( sizeof( struct V_93 ) , V_28 ) ;
if ( ! V_147 )
return NULL ;
if ( V_395 ) {
V_147 -> V_238 = F_52 ( sizeof( T_3 ) * V_395 , V_28 ) ;
if ( ! V_147 -> V_238 )
goto V_396;
}
V_24 = F_4 ( V_19 , & V_147 -> V_7 , V_397 ) ;
if ( V_24 )
goto V_396;
V_147 -> V_164 = V_164 ;
V_147 -> V_395 = V_395 ;
F_38 ( & V_147 -> V_398 ) ;
if ( V_6 ) {
strncpy ( V_147 -> V_6 , V_6 , V_399 ) ;
V_147 -> V_6 [ V_399 - 1 ] = '\0' ;
}
F_31 ( & V_147 -> V_40 , & V_19 -> V_26 . V_134 ) ;
return V_147 ;
V_396:
F_33 ( V_147 -> V_238 ) ;
F_33 ( V_147 ) ;
return NULL ;
}
struct V_93 * F_55 ( struct V_18 * V_19 , int V_164 ,
const char * V_6 ,
const struct V_400 * V_401 ,
int V_395 )
{
struct V_93 * V_147 ;
int V_108 , V_24 ;
V_164 |= V_118 ;
V_147 = F_54 ( V_19 , V_164 , V_6 , V_395 ) ;
if ( ! V_147 )
return NULL ;
for ( V_108 = 0 ; V_108 < V_395 ; V_108 ++ ) {
V_24 = F_60 ( V_147 , V_108 ,
V_401 [ V_108 ] . type ,
V_401 [ V_108 ] . V_6 ) ;
if ( V_24 ) {
F_70 ( V_19 , V_147 ) ;
return NULL ;
}
}
return V_147 ;
}
struct V_93 * F_123 ( struct V_18 * V_19 ,
int V_164 , const char * V_6 ,
const struct V_400 * V_401 ,
int V_395 )
{
struct V_93 * V_147 ;
int V_108 , V_24 ;
V_164 |= V_402 ;
V_147 = F_54 ( V_19 , V_164 , V_6 , V_395 ) ;
if ( ! V_147 )
return NULL ;
for ( V_108 = 0 ; V_108 < V_395 ; V_108 ++ ) {
V_24 = F_60 ( V_147 , V_108 ,
V_401 [ V_108 ] . type ,
V_401 [ V_108 ] . V_6 ) ;
if ( V_24 ) {
F_70 ( V_19 , V_147 ) ;
return NULL ;
}
}
return V_147 ;
}
struct V_93 * F_59 ( struct V_18 * V_19 , int V_164 ,
const char * V_6 ,
T_3 V_403 , T_3 V_404 )
{
struct V_93 * V_147 ;
V_164 |= V_405 ;
V_147 = F_54 ( V_19 , V_164 , V_6 , 2 ) ;
if ( ! V_147 )
return NULL ;
V_147 -> V_238 [ 0 ] = V_403 ;
V_147 -> V_238 [ 1 ] = V_404 ;
return V_147 ;
}
int F_60 ( struct V_93 * V_147 , int V_406 ,
T_3 V_407 , const char * V_6 )
{
struct V_408 * V_409 ;
if ( ! ( V_147 -> V_164 & ( V_118 | V_402 ) ) )
return - V_186 ;
if ( ( V_147 -> V_164 & V_402 ) && ( V_407 > 63 ) )
return - V_186 ;
if ( ! F_50 ( & V_147 -> V_398 ) ) {
F_29 (prop_enum, &property->enum_blob_list, head) {
if ( V_409 -> V_407 == V_407 ) {
strncpy ( V_409 -> V_6 , V_6 , V_399 ) ;
V_409 -> V_6 [ V_399 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_409 = F_52 ( sizeof( struct V_408 ) , V_28 ) ;
if ( ! V_409 )
return - V_29 ;
strncpy ( V_409 -> V_6 , V_6 , V_399 ) ;
V_409 -> V_6 [ V_399 - 1 ] = '\0' ;
V_409 -> V_407 = V_407 ;
V_147 -> V_238 [ V_406 ] = V_407 ;
F_31 ( & V_409 -> V_40 , & V_147 -> V_398 ) ;
return 0 ;
}
void F_70 ( struct V_18 * V_19 , struct V_93 * V_147 )
{
struct V_408 * V_409 , * V_148 ;
F_41 (prop_enum, pt, &property->enum_blob_list, head) {
F_27 ( & V_409 -> V_40 ) ;
F_33 ( V_409 ) ;
}
if ( V_147 -> V_395 )
F_33 ( V_147 -> V_238 ) ;
F_10 ( V_19 , & V_147 -> V_7 ) ;
F_27 ( & V_147 -> V_40 ) ;
F_33 ( V_147 ) ;
}
void F_39 ( struct V_20 * V_21 ,
struct V_93 * V_147 ,
T_3 V_410 )
{
int V_67 = V_21 -> V_58 -> V_67 ;
if ( V_67 == V_411 ) {
F_74 ( 1 , L_62
L_63
L_64 ,
V_21 -> type ) ;
return;
}
V_21 -> V_58 -> V_237 [ V_67 ] = V_147 -> V_7 . V_8 ;
V_21 -> V_58 -> V_238 [ V_67 ] = V_410 ;
V_21 -> V_58 -> V_67 ++ ;
}
int F_124 ( struct V_20 * V_21 ,
struct V_93 * V_147 , T_3 V_412 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_21 -> V_58 -> V_67 ; V_108 ++ ) {
if ( V_21 -> V_58 -> V_237 [ V_108 ] == V_147 -> V_7 . V_8 ) {
V_21 -> V_58 -> V_238 [ V_108 ] = V_412 ;
return 0 ;
}
}
return - V_186 ;
}
int F_125 ( struct V_20 * V_21 ,
struct V_93 * V_147 , T_3 * V_412 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_21 -> V_58 -> V_67 ; V_108 ++ ) {
if ( V_21 -> V_58 -> V_237 [ V_108 ] == V_147 -> V_7 . V_8 ) {
* V_412 = V_21 -> V_58 -> V_238 [ V_108 ] ;
return 0 ;
}
}
return - V_186 ;
}
int F_126 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_20 * V_21 ;
struct V_413 * V_212 = V_168 ;
struct V_93 * V_147 ;
int V_414 = 0 ;
int V_415 = 0 ;
int V_416 = 0 ;
int V_24 = 0 , V_108 ;
int V_179 ;
struct V_408 * V_409 ;
struct V_417 T_2 * V_418 ;
struct V_419 * V_420 ;
T_1 T_2 * V_421 ;
T_3 T_2 * V_422 ;
T_1 T_2 * V_423 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_212 -> V_424 , V_397 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_425;
}
V_147 = F_127 ( V_21 ) ;
if ( V_147 -> V_164 & ( V_118 | V_402 ) ) {
F_29 (prop_enum, &property->enum_blob_list, head)
V_414 ++ ;
} else if ( V_147 -> V_164 & V_96 ) {
F_29 (prop_blob, &property->enum_blob_list, head)
V_415 ++ ;
}
V_416 = V_147 -> V_395 ;
strncpy ( V_212 -> V_6 , V_147 -> V_6 , V_399 ) ;
V_212 -> V_6 [ V_399 - 1 ] = 0 ;
V_212 -> V_164 = V_147 -> V_164 ;
if ( ( V_212 -> V_426 >= V_416 ) && V_416 ) {
V_422 = ( T_3 T_2 * ) ( unsigned long ) V_212 -> V_422 ;
for ( V_108 = 0 ; V_108 < V_416 ; V_108 ++ ) {
if ( F_84 ( V_422 + V_108 , & V_147 -> V_238 [ V_108 ] , sizeof( T_3 ) ) ) {
V_24 = - V_196 ;
goto V_425;
}
}
}
V_212 -> V_426 = V_416 ;
if ( V_147 -> V_164 & ( V_118 | V_402 ) ) {
if ( ( V_212 -> V_427 >= V_414 ) && V_414 ) {
V_179 = 0 ;
V_418 = (struct V_417 T_2 * ) ( unsigned long ) V_212 -> V_428 ;
F_29 (prop_enum, &property->enum_blob_list, head) {
if ( F_84 ( & V_418 [ V_179 ] . V_407 , & V_409 -> V_407 , sizeof( T_3 ) ) ) {
V_24 = - V_196 ;
goto V_425;
}
if ( F_84 ( & V_418 [ V_179 ] . V_6 ,
& V_409 -> V_6 , V_399 ) ) {
V_24 = - V_196 ;
goto V_425;
}
V_179 ++ ;
}
}
V_212 -> V_427 = V_414 ;
}
if ( V_147 -> V_164 & V_96 ) {
if ( ( V_212 -> V_427 >= V_415 ) && V_415 ) {
V_179 = 0 ;
V_421 = ( T_1 T_2 * ) ( unsigned long ) V_212 -> V_428 ;
V_423 = ( T_1 T_2 * ) ( unsigned long ) V_212 -> V_422 ;
F_29 (prop_blob, &property->enum_blob_list, head) {
if ( F_79 ( V_420 -> V_7 . V_8 , V_421 + V_179 ) ) {
V_24 = - V_196 ;
goto V_425;
}
if ( F_79 ( V_420 -> V_429 , V_423 + V_179 ) ) {
V_24 = - V_196 ;
goto V_425;
}
V_179 ++ ;
}
}
V_212 -> V_427 = V_415 ;
}
V_425:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
static struct V_419 * F_128 ( struct V_18 * V_19 , int V_429 ,
void * V_168 )
{
struct V_419 * V_430 ;
int V_24 ;
if ( ! V_429 || ! V_168 )
return NULL ;
V_430 = F_52 ( sizeof( struct V_419 ) + V_429 , V_28 ) ;
if ( ! V_430 )
return NULL ;
V_24 = F_4 ( V_19 , & V_430 -> V_7 , V_431 ) ;
if ( V_24 ) {
F_33 ( V_430 ) ;
return NULL ;
}
V_430 -> V_429 = V_429 ;
memcpy ( V_430 -> V_168 , V_168 , V_429 ) ;
F_31 ( & V_430 -> V_40 , & V_19 -> V_26 . V_135 ) ;
return V_430 ;
}
static void F_129 ( struct V_18 * V_19 ,
struct V_419 * V_430 )
{
F_10 ( V_19 , & V_430 -> V_7 ) ;
F_27 ( & V_430 -> V_40 ) ;
F_33 ( V_430 ) ;
}
int F_130 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_20 * V_21 ;
struct V_432 * V_212 = V_168 ;
struct V_419 * V_430 ;
int V_24 = 0 ;
void T_2 * V_433 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_212 -> V_434 , V_431 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_425;
}
V_430 = F_131 ( V_21 ) ;
if ( V_212 -> V_429 == V_430 -> V_429 ) {
V_433 = ( void T_2 * ) ( unsigned long ) V_212 -> V_168 ;
if ( F_84 ( V_433 , V_430 -> V_168 , V_430 -> V_429 ) ) {
V_24 = - V_196 ;
goto V_425;
}
}
V_212 -> V_429 = V_430 -> V_429 ;
V_425:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_132 ( struct V_9 * V_10 ,
struct V_94 * V_94 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
int V_24 , V_435 ;
if ( V_10 -> V_70 )
F_129 ( V_19 , V_10 -> V_70 ) ;
if ( ! V_94 ) {
V_10 -> V_70 = NULL ;
V_24 = F_124 ( & V_10 -> V_7 , V_19 -> V_26 . V_75 , 0 ) ;
return V_24 ;
}
V_435 = V_436 * ( 1 + V_94 -> V_437 ) ;
V_10 -> V_70 = F_128 ( V_10 -> V_19 ,
V_435 , V_94 ) ;
if ( ! V_10 -> V_70 )
return - V_186 ;
V_24 = F_124 ( & V_10 -> V_7 ,
V_19 -> V_26 . V_75 ,
V_10 -> V_70 -> V_7 . V_8 ) ;
return V_24 ;
}
static bool F_133 ( struct V_93 * V_147 ,
T_3 V_407 )
{
if ( V_147 -> V_164 & V_97 )
return false ;
if ( V_147 -> V_164 & V_405 ) {
if ( V_407 < V_147 -> V_238 [ 0 ] || V_407 > V_147 -> V_238 [ 1 ] )
return false ;
return true ;
} else if ( V_147 -> V_164 & V_402 ) {
int V_108 ;
T_3 V_438 = 0 ;
for ( V_108 = 0 ; V_108 < V_147 -> V_395 ; V_108 ++ )
V_438 |= ( 1ULL << V_147 -> V_238 [ V_108 ] ) ;
return ! ( V_407 & ~ V_438 ) ;
} else if ( V_147 -> V_164 & V_96 ) {
return true ;
} else {
int V_108 ;
for ( V_108 = 0 ; V_108 < V_147 -> V_395 ; V_108 ++ )
if ( V_147 -> V_238 [ V_108 ] == V_407 )
return true ;
return false ;
}
}
int F_134 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_439 * V_440 = V_168 ;
struct V_441 V_442 = {
. V_407 = V_440 -> V_407 ,
. V_424 = V_440 -> V_424 ,
. V_443 = V_440 -> V_182 ,
. V_22 = V_66
} ;
return F_135 ( V_19 , & V_442 , V_170 ) ;
}
static int F_136 ( struct V_20 * V_21 ,
struct V_93 * V_147 ,
T_3 V_407 )
{
int V_24 = - V_186 ;
struct V_9 * V_10 = F_83 ( V_21 ) ;
if ( V_147 == V_10 -> V_19 -> V_26 . V_76 ) {
if ( V_10 -> V_36 -> V_95 )
(* V_10 -> V_36 -> V_95 )( V_10 , ( int ) V_407 ) ;
V_24 = 0 ;
} else if ( V_10 -> V_36 -> V_444 )
V_24 = V_10 -> V_36 -> V_444 ( V_10 , V_147 , V_407 ) ;
if ( ! V_24 )
F_124 ( & V_10 -> V_7 , V_147 , V_407 ) ;
return V_24 ;
}
static int F_137 ( struct V_20 * V_21 ,
struct V_93 * V_147 ,
T_3 V_407 )
{
int V_24 = - V_186 ;
struct V_45 * V_46 = F_81 ( V_21 ) ;
if ( V_46 -> V_36 -> V_444 )
V_24 = V_46 -> V_36 -> V_444 ( V_46 , V_147 , V_407 ) ;
if ( ! V_24 )
F_124 ( V_21 , V_147 , V_407 ) ;
return V_24 ;
}
static int F_138 ( struct V_20 * V_21 ,
struct V_93 * V_147 ,
T_3 V_407 )
{
int V_24 = - V_186 ;
struct V_47 * V_48 = F_89 ( V_21 ) ;
if ( V_48 -> V_36 -> V_444 )
V_24 = V_48 -> V_36 -> V_444 ( V_48 , V_147 , V_407 ) ;
if ( ! V_24 )
F_124 ( V_21 , V_147 , V_407 ) ;
return V_24 ;
}
int F_139 ( struct V_18 * V_19 , void * V_168 ,
struct V_169 * V_170 )
{
struct V_445 * V_446 = V_168 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
int V_108 ;
int V_179 = 0 ;
int V_214 = 0 ;
T_1 T_2 * V_235 ;
T_3 T_2 * V_236 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_446 -> V_443 , V_446 -> V_22 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
if ( ! V_21 -> V_58 ) {
V_24 = - V_186 ;
goto V_57;
}
V_214 = V_21 -> V_58 -> V_67 ;
if ( ( V_446 -> V_234 >= V_214 ) && V_214 ) {
V_179 = 0 ;
V_235 = ( T_1 T_2 * ) ( unsigned long ) ( V_446 -> V_235 ) ;
V_236 = ( T_3 T_2 * ) ( unsigned long )
( V_446 -> V_236 ) ;
for ( V_108 = 0 ; V_108 < V_214 ; V_108 ++ ) {
if ( F_79 ( V_21 -> V_58 -> V_237 [ V_108 ] ,
V_235 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
if ( F_79 ( V_21 -> V_58 -> V_238 [ V_108 ] ,
V_236 + V_179 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_179 ++ ;
}
}
V_446 -> V_234 = V_214 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_135 ( struct V_18 * V_19 , void * V_168 ,
struct V_169 * V_170 )
{
struct V_441 * V_446 = V_168 ;
struct V_20 * V_447 ;
struct V_20 * V_448 ;
struct V_93 * V_147 ;
int V_24 = - V_186 ;
int V_108 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_447 = F_12 ( V_19 , V_446 -> V_443 , V_446 -> V_22 ) ;
if ( ! V_447 )
goto V_57;
if ( ! V_447 -> V_58 )
goto V_57;
for ( V_108 = 0 ; V_108 < V_447 -> V_58 -> V_67 ; V_108 ++ )
if ( V_447 -> V_58 -> V_237 [ V_108 ] == V_446 -> V_424 )
break;
if ( V_108 == V_447 -> V_58 -> V_67 )
goto V_57;
V_448 = F_12 ( V_19 , V_446 -> V_424 ,
V_397 ) ;
if ( ! V_448 )
goto V_57;
V_147 = F_127 ( V_448 ) ;
if ( ! F_133 ( V_147 , V_446 -> V_407 ) )
goto V_57;
switch ( V_447 -> type ) {
case V_66 :
V_24 = F_136 ( V_447 , V_147 ,
V_446 -> V_407 ) ;
break;
case V_56 :
V_24 = F_137 ( V_447 , V_147 , V_446 -> V_407 ) ;
break;
case V_87 :
V_24 = F_138 ( V_447 , V_147 , V_446 -> V_407 ) ;
break;
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_140 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_221 ; V_108 ++ ) {
if ( V_10 -> V_222 [ V_108 ] == 0 ) {
V_10 -> V_222 [ V_108 ] = V_2 -> V_7 . V_8 ;
return 0 ;
}
}
return - V_29 ;
}
void F_141 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_221 ; V_108 ++ ) {
if ( V_10 -> V_222 [ V_108 ] == V_2 -> V_7 . V_8 ) {
V_10 -> V_222 [ V_108 ] = 0 ;
if ( V_10 -> V_2 == V_2 )
V_10 -> V_2 = NULL ;
break;
}
}
}
int F_142 ( struct V_45 * V_46 ,
int V_208 )
{
V_46 -> V_208 = V_208 ;
V_46 -> V_61 = F_52 ( V_208 * sizeof( V_449 ) * 3 , V_28 ) ;
if ( ! V_46 -> V_61 ) {
V_46 -> V_208 = 0 ;
return - V_29 ;
}
return 0 ;
}
int F_143 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_450 * V_451 = V_168 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
void * V_452 , * V_453 , * V_454 ;
int V_435 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_451 -> V_181 , V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
if ( V_46 -> V_36 -> V_455 == NULL ) {
V_24 = - V_386 ;
goto V_57;
}
if ( V_451 -> V_208 != V_46 -> V_208 ) {
V_24 = - V_186 ;
goto V_57;
}
V_435 = V_451 -> V_208 * ( sizeof( V_449 ) ) ;
V_452 = V_46 -> V_61 ;
if ( F_111 ( V_452 , ( void T_2 * ) ( unsigned long ) V_451 -> V_456 , V_435 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_453 = V_452 + V_435 ;
if ( F_111 ( V_453 , ( void T_2 * ) ( unsigned long ) V_451 -> V_457 , V_435 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_454 = V_453 + V_435 ;
if ( F_111 ( V_454 , ( void T_2 * ) ( unsigned long ) V_451 -> V_458 , V_435 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_46 -> V_36 -> V_455 ( V_46 , V_452 , V_453 , V_454 , 0 , V_46 -> V_208 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_144 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_450 * V_451 = V_168 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
void * V_452 , * V_453 , * V_454 ;
int V_435 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_185 ) )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_451 -> V_181 , V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_186 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
if ( V_451 -> V_208 != V_46 -> V_208 ) {
V_24 = - V_186 ;
goto V_57;
}
V_435 = V_451 -> V_208 * ( sizeof( V_449 ) ) ;
V_452 = V_46 -> V_61 ;
if ( F_84 ( ( void T_2 * ) ( unsigned long ) V_451 -> V_456 , V_452 , V_435 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_453 = V_452 + V_435 ;
if ( F_84 ( ( void T_2 * ) ( unsigned long ) V_451 -> V_457 , V_453 , V_435 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_454 = V_453 + V_435 ;
if ( F_84 ( ( void T_2 * ) ( unsigned long ) V_451 -> V_458 , V_454 , V_435 ) ) {
V_24 = - V_196 ;
goto V_57;
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_145 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_459 * V_460 = V_168 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
struct V_33 * V_34 ;
struct V_461 * V_462 = NULL ;
unsigned long V_164 ;
int V_152 , V_158 ;
int V_24 = - V_186 ;
if ( V_460 -> V_164 & ~ V_463 ||
V_460 -> V_464 != 0 )
return - V_186 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_460 -> V_181 , V_56 ) ;
if ( ! V_21 )
goto V_57;
V_46 = F_81 ( V_21 ) ;
if ( V_46 -> V_34 == NULL ) {
V_24 = - V_465 ;
goto V_57;
}
if ( V_46 -> V_36 -> V_460 == NULL )
goto V_57;
V_21 = F_12 ( V_19 , V_460 -> V_180 , V_38 ) ;
if ( ! V_21 )
goto V_57;
V_34 = F_91 ( V_21 ) ;
V_152 = V_46 -> V_63 . V_152 ;
V_158 = V_46 -> V_63 . V_158 ;
if ( V_46 -> V_55 )
F_94 ( V_152 , V_158 ) ;
if ( V_152 > V_34 -> V_261 ||
V_158 > V_34 -> V_262 ||
V_46 -> V_206 > V_34 -> V_261 - V_152 ||
V_46 -> V_207 > V_34 -> V_262 - V_158 ) {
F_48 ( L_45 ,
V_34 -> V_261 , V_34 -> V_262 , V_152 , V_158 , V_46 -> V_206 , V_46 -> V_207 ,
V_46 -> V_55 ? L_46 : L_47 ) ;
V_24 = - V_267 ;
goto V_57;
}
if ( V_460 -> V_164 & V_466 ) {
V_24 = - V_29 ;
F_146 ( & V_19 -> V_467 , V_164 ) ;
if ( V_170 -> V_468 < sizeof V_462 -> V_469 ) {
F_147 ( & V_19 -> V_467 , V_164 ) ;
goto V_57;
}
V_170 -> V_468 -= sizeof V_462 -> V_469 ;
F_147 ( & V_19 -> V_467 , V_164 ) ;
V_462 = F_52 ( sizeof *V_462 , V_28 ) ;
if ( V_462 == NULL ) {
F_146 ( & V_19 -> V_467 , V_164 ) ;
V_170 -> V_468 += sizeof V_462 -> V_469 ;
F_147 ( & V_19 -> V_467 , V_164 ) ;
goto V_57;
}
V_462 -> V_469 . V_7 . type = V_470 ;
V_462 -> V_469 . V_7 . V_429 = sizeof V_462 -> V_469 ;
V_462 -> V_469 . V_471 = V_460 -> V_471 ;
V_462 -> V_7 . V_469 = & V_462 -> V_469 . V_7 ;
V_462 -> V_7 . V_170 = V_170 ;
V_462 -> V_7 . V_43 =
( void ( * ) ( struct V_472 * ) ) F_33 ;
}
V_24 = V_46 -> V_36 -> V_460 ( V_46 , V_34 , V_462 ) ;
if ( V_24 ) {
if ( V_460 -> V_164 & V_466 ) {
F_146 ( & V_19 -> V_467 , V_164 ) ;
V_170 -> V_468 += sizeof V_462 -> V_469 ;
F_147 ( & V_19 -> V_467 , V_164 ) ;
F_33 ( V_462 ) ;
}
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
void F_148 ( struct V_18 * V_19 )
{
struct V_45 * V_46 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_29 (crtc, &dev->mode_config.crtc_list, head)
if ( V_46 -> V_36 -> V_473 )
V_46 -> V_36 -> V_473 ( V_46 ) ;
F_29 (encoder, &dev->mode_config.encoder_list, head)
if ( V_2 -> V_36 -> V_473 )
V_2 -> V_36 -> V_473 ( V_2 ) ;
F_29 (connector, &dev->mode_config.connector_list, head) {
V_10 -> V_15 = V_71 ;
if ( V_10 -> V_36 -> V_473 )
V_10 -> V_36 -> V_473 ( V_10 ) ;
}
}
int F_149 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_474 * args = V_168 ;
if ( ! V_19 -> V_475 -> V_476 )
return - V_386 ;
return V_19 -> V_475 -> V_476 ( V_170 , V_19 , args ) ;
}
int F_150 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_477 * args = V_168 ;
if ( ! V_19 -> V_475 -> V_478 )
return - V_386 ;
return V_19 -> V_475 -> V_478 ( V_170 , V_19 , args -> V_286 , & args -> V_479 ) ;
}
int F_151 ( struct V_18 * V_19 ,
void * V_168 , struct V_169 * V_170 )
{
struct V_480 * args = V_168 ;
if ( ! V_19 -> V_475 -> V_481 )
return - V_386 ;
return V_19 -> V_475 -> V_481 ( V_170 , V_19 , args -> V_286 ) ;
}
void F_152 ( T_1 V_308 , unsigned int * V_290 ,
int * V_289 )
{
switch ( V_308 ) {
case V_292 :
case V_311 :
* V_290 = 8 ;
* V_289 = 8 ;
break;
case V_293 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
* V_290 = 15 ;
* V_289 = 16 ;
break;
case V_294 :
case V_327 :
* V_290 = 16 ;
* V_289 = 16 ;
break;
case V_295 :
case V_328 :
* V_290 = 24 ;
* V_289 = 24 ;
break;
case V_296 :
case V_329 :
case V_330 :
case V_331 :
* V_290 = 24 ;
* V_289 = 32 ;
break;
case V_297 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
* V_290 = 30 ;
* V_289 = 32 ;
break;
case V_298 :
case V_332 :
case V_333 :
case V_334 :
* V_290 = 32 ;
* V_289 = 32 ;
break;
default:
F_48 ( L_65 ) ;
* V_290 = 0 ;
* V_289 = 0 ;
break;
}
}
int F_105 ( T_1 V_308 )
{
switch ( V_308 ) {
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
return 3 ;
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
return 2 ;
default:
return 1 ;
}
}
int F_106 ( T_1 V_308 , int V_48 )
{
unsigned int V_290 ;
int V_289 ;
if ( V_48 >= F_105 ( V_308 ) )
return 0 ;
switch ( V_308 ) {
case V_342 :
case V_343 :
case V_344 :
case V_345 :
return 2 ;
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
return V_48 ? 2 : 1 ;
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
return 1 ;
default:
F_152 ( V_308 , & V_290 , & V_289 ) ;
return V_289 >> 3 ;
}
}
int F_103 ( T_1 V_308 )
{
switch ( V_308 ) {
case V_355 :
case V_356 :
case V_353 :
case V_354 :
return 4 ;
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_359 :
case V_360 :
case V_357 :
case V_358 :
return 2 ;
default:
return 1 ;
}
}
int F_104 ( T_1 V_308 )
{
switch ( V_308 ) {
case V_353 :
case V_354 :
return 4 ;
case V_357 :
case V_358 :
case V_347 :
case V_348 :
return 2 ;
default:
return 1 ;
}
}
