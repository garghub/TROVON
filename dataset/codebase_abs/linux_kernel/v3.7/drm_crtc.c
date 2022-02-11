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
if ( V_46 -> V_61 ) {
F_33 ( V_46 -> V_61 ) ;
V_46 -> V_61 = NULL ;
}
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
F_31 ( & V_10 -> V_40 , & V_19 -> V_26 . V_71 ) ;
V_19 -> V_26 . V_72 ++ ;
if ( V_12 != V_73 )
F_39 ( V_10 ,
V_19 -> V_26 . V_74 ,
0 ) ;
F_39 ( V_10 ,
V_19 -> V_26 . V_75 , 0 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
void F_40 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
struct V_62 * V_63 , * V_76 ;
F_41 (mode, t, &connector->probed_modes, head)
F_35 ( V_10 , V_63 ) ;
F_41 (mode, t, &connector->modes, head)
F_35 ( V_10 , V_63 ) ;
F_41 (mode, t, &connector->user_modes, head)
F_35 ( V_10 , V_63 ) ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
F_10 ( V_19 , & V_10 -> V_7 ) ;
F_27 ( & V_10 -> V_40 ) ;
V_19 -> V_26 . V_72 -- ;
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
const struct V_77 * V_36 ,
int V_5 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_24 = F_4 ( V_19 , & V_2 -> V_7 , V_78 ) ;
if ( V_24 )
goto V_57;
V_2 -> V_19 = V_19 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_36 = V_36 ;
F_31 ( & V_2 -> V_40 , & V_19 -> V_26 . V_79 ) ;
V_19 -> V_26 . V_80 ++ ;
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
V_19 -> V_26 . V_80 -- ;
F_9 ( & V_19 -> V_26 . V_44 ) ;
}
int F_46 ( struct V_18 * V_19 , struct V_47 * V_48 ,
unsigned long V_81 ,
const struct V_82 * V_36 ,
const T_1 * V_83 , T_1 V_84 ,
bool V_85 )
{
int V_24 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_24 = F_4 ( V_19 , & V_48 -> V_7 , V_86 ) ;
if ( V_24 )
goto V_57;
V_48 -> V_7 . V_58 = & V_48 -> V_58 ;
V_48 -> V_19 = V_19 ;
V_48 -> V_36 = V_36 ;
V_48 -> V_87 = F_47 ( sizeof( T_1 ) * V_84 ,
V_28 ) ;
if ( ! V_48 -> V_87 ) {
F_48 ( L_9 ) ;
F_10 ( V_19 , & V_48 -> V_7 ) ;
V_24 = - V_29 ;
goto V_57;
}
memcpy ( V_48 -> V_87 , V_83 , V_84 * sizeof( T_1 ) ) ;
V_48 -> V_84 = V_84 ;
V_48 -> V_81 = V_81 ;
if ( ! V_85 ) {
F_31 ( & V_48 -> V_40 , & V_19 -> V_26 . V_88 ) ;
V_19 -> V_26 . V_89 ++ ;
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
F_33 ( V_48 -> V_87 ) ;
F_10 ( V_19 , & V_48 -> V_7 ) ;
if ( ! F_50 ( & V_48 -> V_40 ) ) {
F_27 ( & V_48 -> V_40 ) ;
V_19 -> V_26 . V_89 -- ;
}
F_9 ( & V_19 -> V_26 . V_44 ) ;
}
struct V_62 * F_51 ( struct V_18 * V_19 )
{
struct V_62 * V_90 ;
V_90 = F_52 ( sizeof( struct V_62 ) , V_28 ) ;
if ( ! V_90 )
return NULL ;
if ( F_4 ( V_19 , & V_90 -> V_7 , V_91 ) ) {
F_33 ( V_90 ) ;
return NULL ;
}
return V_90 ;
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
struct V_92 * V_93 ;
struct V_92 * V_94 ;
V_93 = F_54 ( V_19 , V_95 |
V_96 ,
L_10 , 0 ) ;
V_19 -> V_26 . V_74 = V_93 ;
V_94 = F_55 ( V_19 , 0 ,
L_11 , V_97 ,
F_56 ( V_97 ) ) ;
V_19 -> V_26 . V_75 = V_94 ;
return 0 ;
}
int F_57 ( struct V_18 * V_19 )
{
struct V_92 * V_98 ;
struct V_92 * V_99 ;
if ( V_19 -> V_26 . V_100 )
return 0 ;
V_98 =
F_55 ( V_19 , 0 ,
L_12 ,
V_101 ,
F_56 ( V_101 ) ) ;
V_19 -> V_26 . V_100 = V_98 ;
V_99 = F_55 ( V_19 , V_96 ,
L_13 ,
V_102 ,
F_56 ( V_102 ) ) ;
V_19 -> V_26 . V_103 = V_99 ;
return 0 ;
}
int F_58 ( struct V_18 * V_19 , int V_104 ,
char * V_69 [] )
{
struct V_92 * V_105 ;
struct V_92 * V_106 ;
int V_107 ;
if ( V_19 -> V_26 . V_108 )
return 0 ;
V_105 = F_55 ( V_19 , 0 ,
L_12 ,
V_109 ,
F_56 ( V_109 ) ) ;
V_19 -> V_26 . V_108 = V_105 ;
V_106 =
F_55 ( V_19 , V_96 ,
L_13 ,
V_110 ,
F_56 ( V_110 ) ) ;
V_19 -> V_26 . V_111 = V_106 ;
V_19 -> V_26 . V_112 =
F_59 ( V_19 , 0 , L_14 , 0 , 100 ) ;
V_19 -> V_26 . V_113 =
F_59 ( V_19 , 0 , L_15 , 0 , 100 ) ;
V_19 -> V_26 . V_114 =
F_59 ( V_19 , 0 , L_16 , 0 , 100 ) ;
V_19 -> V_26 . V_115 =
F_59 ( V_19 , 0 , L_17 , 0 , 100 ) ;
V_19 -> V_26 . V_116 =
F_54 ( V_19 , V_117 ,
L_18 , V_104 ) ;
for ( V_107 = 0 ; V_107 < V_104 ; V_107 ++ )
F_60 ( V_19 -> V_26 . V_116 , V_107 ,
V_107 , V_69 [ V_107 ] ) ;
V_19 -> V_26 . V_118 =
F_59 ( V_19 , 0 , L_19 , 0 , 100 ) ;
V_19 -> V_26 . V_119 =
F_59 ( V_19 , 0 , L_20 , 0 , 100 ) ;
V_19 -> V_26 . V_120 =
F_59 ( V_19 , 0 , L_21 , 0 , 100 ) ;
V_19 -> V_26 . V_121 =
F_59 ( V_19 , 0 , L_22 , 0 , 100 ) ;
V_19 -> V_26 . V_122 =
F_59 ( V_19 , 0 , L_23 , 0 , 100 ) ;
V_19 -> V_26 . V_123 =
F_59 ( V_19 , 0 , L_24 , 0 , 100 ) ;
return 0 ;
}
int F_61 ( struct V_18 * V_19 )
{
struct V_92 * V_124 ;
if ( V_19 -> V_26 . V_125 )
return 0 ;
V_124 =
F_55 ( V_19 , 0 , L_25 ,
V_126 ,
F_56 ( V_126 ) ) ;
V_19 -> V_26 . V_125 = V_124 ;
return 0 ;
}
int F_62 ( struct V_18 * V_19 )
{
struct V_92 * V_127 ;
if ( V_19 -> V_26 . V_128 )
return 0 ;
V_127 =
F_55 ( V_19 , 0 , L_26 ,
V_129 ,
F_56 ( V_129 ) ) ;
V_19 -> V_26 . V_128 = V_127 ;
return 0 ;
}
int F_63 ( struct V_18 * V_19 )
{
struct V_92 * V_130 ;
if ( V_19 -> V_26 . V_131 )
return 0 ;
V_130 =
F_55 ( V_19 , V_96 ,
L_27 ,
V_132 ,
F_56 ( V_132 ) ) ;
V_19 -> V_26 . V_131 = V_130 ;
return 0 ;
}
void F_64 ( struct V_18 * V_19 )
{
F_65 ( & V_19 -> V_26 . V_44 ) ;
F_65 ( & V_19 -> V_26 . V_30 ) ;
F_38 ( & V_19 -> V_26 . V_41 ) ;
F_38 ( & V_19 -> V_26 . V_59 ) ;
F_38 ( & V_19 -> V_26 . V_71 ) ;
F_38 ( & V_19 -> V_26 . V_79 ) ;
F_38 ( & V_19 -> V_26 . V_133 ) ;
F_38 ( & V_19 -> V_26 . V_134 ) ;
F_38 ( & V_19 -> V_26 . V_88 ) ;
F_66 ( & V_19 -> V_26 . V_27 ) ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
F_53 ( V_19 ) ;
F_9 ( & V_19 -> V_26 . V_44 ) ;
V_19 -> V_26 . V_39 = 0 ;
V_19 -> V_26 . V_72 = 0 ;
V_19 -> V_26 . V_60 = 0 ;
V_19 -> V_26 . V_80 = 0 ;
}
int F_67 ( struct V_18 * V_19 , struct V_135 * V_136 )
{
T_1 V_137 = 0 ;
V_137 += V_19 -> V_26 . V_60 ;
V_137 += V_19 -> V_26 . V_72 ;
V_137 += V_19 -> V_26 . V_80 ;
V_136 -> V_138 = F_52 ( V_137 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_136 -> V_138 )
return - V_29 ;
V_136 -> V_139 = 0 ;
V_136 -> V_140 = 0 ;
V_136 -> V_141 = 0 ;
return 0 ;
}
int F_68 ( struct V_18 * V_19 ,
struct V_135 * V_136 )
{
struct V_45 * V_46 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_24 ;
if ( ( V_24 = F_67 ( V_19 , V_136 ) ) )
return V_24 ;
F_29 (crtc, &dev->mode_config.crtc_list, head)
V_136 -> V_138 [ V_136 -> V_139 ++ ] = V_46 -> V_7 . V_8 ;
F_29 (encoder, &dev->mode_config.encoder_list, head)
V_136 -> V_138 [ V_136 -> V_139 + V_136 -> V_141 ++ ] =
V_2 -> V_7 . V_8 ;
F_29 (connector, &dev->mode_config.connector_list, head)
V_136 -> V_138 [ V_136 -> V_139 + V_136 -> V_141 +
V_136 -> V_140 ++ ] = V_10 -> V_7 . V_8 ;
return 0 ;
}
void F_69 ( struct V_18 * V_19 )
{
struct V_9 * V_10 , * V_142 ;
struct V_45 * V_46 , * V_143 ;
struct V_1 * V_2 , * V_144 ;
struct V_33 * V_34 , * V_145 ;
struct V_92 * V_146 , * V_147 ;
struct V_47 * V_48 , * V_148 ;
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
F_70 ( V_19 , V_146 ) ;
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
static void F_73 ( struct V_149 * V_57 ,
const struct V_62 * V_150 )
{
F_74 ( V_150 -> V_151 > V_152 || V_150 -> V_153 > V_152 ||
V_150 -> V_154 > V_152 || V_150 -> V_155 > V_152 ||
V_150 -> V_156 > V_152 || V_150 -> V_157 > V_152 ||
V_150 -> V_158 > V_152 || V_150 -> V_159 > V_152 ||
V_150 -> V_160 > V_152 || V_150 -> V_161 > V_152 ,
L_28 ) ;
V_57 -> clock = V_150 -> clock ;
V_57 -> V_151 = V_150 -> V_151 ;
V_57 -> V_153 = V_150 -> V_153 ;
V_57 -> V_154 = V_150 -> V_154 ;
V_57 -> V_155 = V_150 -> V_155 ;
V_57 -> V_156 = V_150 -> V_156 ;
V_57 -> V_157 = V_150 -> V_157 ;
V_57 -> V_158 = V_150 -> V_158 ;
V_57 -> V_159 = V_150 -> V_159 ;
V_57 -> V_160 = V_150 -> V_160 ;
V_57 -> V_161 = V_150 -> V_161 ;
V_57 -> V_162 = V_150 -> V_162 ;
V_57 -> V_163 = V_150 -> V_163 ;
V_57 -> type = V_150 -> type ;
strncpy ( V_57 -> V_6 , V_150 -> V_6 , V_164 ) ;
V_57 -> V_6 [ V_164 - 1 ] = 0 ;
}
static int F_75 ( struct V_62 * V_57 ,
const struct V_149 * V_150 )
{
if ( V_150 -> clock > V_165 || V_150 -> V_162 > V_165 )
return - V_166 ;
V_57 -> clock = V_150 -> clock ;
V_57 -> V_151 = V_150 -> V_151 ;
V_57 -> V_153 = V_150 -> V_153 ;
V_57 -> V_154 = V_150 -> V_154 ;
V_57 -> V_155 = V_150 -> V_155 ;
V_57 -> V_156 = V_150 -> V_156 ;
V_57 -> V_157 = V_150 -> V_157 ;
V_57 -> V_158 = V_150 -> V_158 ;
V_57 -> V_159 = V_150 -> V_159 ;
V_57 -> V_160 = V_150 -> V_160 ;
V_57 -> V_161 = V_150 -> V_161 ;
V_57 -> V_162 = V_150 -> V_162 ;
V_57 -> V_163 = V_150 -> V_163 ;
V_57 -> type = V_150 -> type ;
strncpy ( V_57 -> V_6 , V_150 -> V_6 , V_164 ) ;
V_57 -> V_6 [ V_164 - 1 ] = 0 ;
return 0 ;
}
int F_76 ( struct V_18 * V_19 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_170 * V_171 = V_167 ;
struct V_172 * V_173 ;
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_45 * V_46 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
int V_174 = 0 ;
int V_175 = 0 ;
int V_176 = 0 ;
int V_177 = 0 ;
int V_178 = 0 , V_107 ;
T_1 T_2 * V_179 ;
T_1 T_2 * V_180 ;
T_1 T_2 * V_181 ;
T_1 T_2 * V_182 ;
struct V_135 * V_183 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
F_78 (lh, &file_priv->fbs)
V_176 ++ ;
V_183 = & V_169 -> V_186 -> V_187 -> V_183 ;
if ( V_169 -> V_186 -> V_187 -> type == V_188 ) {
F_78 (lh, &dev->mode_config.crtc_list)
V_175 ++ ;
F_78 (lh, &dev->mode_config.connector_list)
V_174 ++ ;
F_78 (lh, &dev->mode_config.encoder_list)
V_177 ++ ;
} else {
V_175 = V_183 -> V_139 ;
V_174 = V_183 -> V_140 ;
V_177 = V_183 -> V_141 ;
}
V_171 -> V_189 = V_19 -> V_26 . V_189 ;
V_171 -> V_190 = V_19 -> V_26 . V_190 ;
V_171 -> V_191 = V_19 -> V_26 . V_191 ;
V_171 -> V_192 = V_19 -> V_26 . V_192 ;
if ( V_171 -> V_193 >= V_176 ) {
V_178 = 0 ;
V_179 = ( T_1 T_2 * ) ( unsigned long ) V_171 -> V_194 ;
F_29 (fb, &file_priv->fbs, filp_head) {
if ( F_79 ( V_34 -> V_7 . V_8 , V_179 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
}
V_171 -> V_193 = V_176 ;
if ( V_171 -> V_196 >= V_175 ) {
V_178 = 0 ;
V_180 = ( T_1 T_2 * ) ( unsigned long ) V_171 -> V_197 ;
if ( V_169 -> V_186 -> V_187 -> type == V_188 ) {
F_29 (crtc, &dev->mode_config.crtc_list,
head) {
F_48 ( L_29 , V_46 -> V_7 . V_8 ) ;
if ( F_79 ( V_46 -> V_7 . V_8 , V_180 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
} else {
for ( V_107 = 0 ; V_107 < V_183 -> V_139 ; V_107 ++ ) {
if ( F_79 ( V_183 -> V_138 [ V_107 ] ,
V_180 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
}
}
V_171 -> V_196 = V_175 ;
if ( V_171 -> V_198 >= V_177 ) {
V_178 = 0 ;
V_182 = ( T_1 T_2 * ) ( unsigned long ) V_171 -> V_199 ;
if ( V_169 -> V_186 -> V_187 -> type == V_188 ) {
F_29 (encoder,
&dev->mode_config.encoder_list,
head) {
F_48 ( L_30 , V_2 -> V_7 . V_8 ,
F_1 ( V_2 ) ) ;
if ( F_79 ( V_2 -> V_7 . V_8 , V_182 +
V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
} else {
for ( V_107 = V_183 -> V_139 ; V_107 < V_183 -> V_139 + V_183 -> V_141 ; V_107 ++ ) {
if ( F_79 ( V_183 -> V_138 [ V_107 ] ,
V_182 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
}
}
V_171 -> V_198 = V_177 ;
if ( V_171 -> V_200 >= V_174 ) {
V_178 = 0 ;
V_181 = ( T_1 T_2 * ) ( unsigned long ) V_171 -> V_201 ;
if ( V_169 -> V_186 -> V_187 -> type == V_188 ) {
F_29 (connector,
&dev->mode_config.connector_list,
head) {
F_48 ( L_31 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
if ( F_79 ( V_10 -> V_7 . V_8 ,
V_181 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
} else {
int V_202 = V_183 -> V_139 +
V_183 -> V_141 ;
for ( V_107 = V_202 ; V_107 < V_202 + V_183 -> V_140 ; V_107 ++ ) {
if ( F_79 ( V_183 -> V_138 [ V_107 ] ,
V_181 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
}
}
V_171 -> V_200 = V_174 ;
F_48 ( L_32 , V_171 -> V_196 ,
V_171 -> V_200 , V_171 -> V_198 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_80 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_203 * V_204 = V_167 ;
struct V_45 * V_46 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_204 -> V_180 ,
V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
V_204 -> V_205 = V_46 -> V_205 ;
V_204 -> V_206 = V_46 -> V_206 ;
V_204 -> V_207 = V_46 -> V_207 ;
if ( V_46 -> V_34 )
V_204 -> V_179 = V_46 -> V_34 -> V_7 . V_8 ;
else
V_204 -> V_179 = 0 ;
if ( V_46 -> V_208 ) {
F_73 ( & V_204 -> V_63 , & V_46 -> V_63 ) ;
V_204 -> V_209 = 1 ;
} else {
V_204 -> V_209 = 0 ;
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_82 ( struct V_18 * V_19 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_210 * V_211 = V_167 ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
struct V_62 * V_63 ;
int V_212 = 0 ;
int V_213 = 0 ;
int V_214 = 0 ;
int V_24 = 0 ;
int V_178 = 0 ;
int V_107 ;
struct V_149 V_215 ;
struct V_149 T_2 * V_216 ;
T_1 T_2 * V_217 ;
T_3 T_2 * V_218 ;
T_1 T_2 * V_219 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
memset ( & V_215 , 0 , sizeof( struct V_149 ) ) ;
F_48 ( L_33 , V_211 -> V_181 ) ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_211 -> V_181 ,
V_66 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
V_10 = F_83 ( V_21 ) ;
V_213 = V_10 -> V_58 . V_67 ;
for ( V_107 = 0 ; V_107 < V_220 ; V_107 ++ ) {
if ( V_10 -> V_221 [ V_107 ] != 0 ) {
V_214 ++ ;
}
}
if ( V_211 -> V_222 == 0 ) {
V_10 -> V_36 -> V_223 ( V_10 ,
V_19 -> V_26 . V_191 ,
V_19 -> V_26 . V_189 ) ;
}
F_29 (mode, &connector->modes, head)
V_212 ++ ;
V_211 -> V_181 = V_10 -> V_7 . V_8 ;
V_211 -> V_12 = V_10 -> V_12 ;
V_211 -> V_13 = V_10 -> V_13 ;
V_211 -> V_224 = V_10 -> V_225 . V_226 ;
V_211 -> V_227 = V_10 -> V_225 . V_228 ;
V_211 -> V_229 = V_10 -> V_225 . V_230 ;
V_211 -> V_231 = V_10 -> V_15 ;
if ( V_10 -> V_2 )
V_211 -> V_182 = V_10 -> V_2 -> V_7 . V_8 ;
else
V_211 -> V_182 = 0 ;
if ( ( V_211 -> V_222 >= V_212 ) && V_212 ) {
V_178 = 0 ;
V_216 = (struct V_149 T_2 * ) ( unsigned long ) V_211 -> V_232 ;
F_29 (mode, &connector->modes, head) {
F_73 ( & V_215 , V_63 ) ;
if ( F_84 ( V_216 + V_178 ,
& V_215 , sizeof( V_215 ) ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
}
V_211 -> V_222 = V_212 ;
if ( ( V_211 -> V_233 >= V_213 ) && V_213 ) {
V_178 = 0 ;
V_217 = ( T_1 T_2 * ) ( unsigned long ) ( V_211 -> V_234 ) ;
V_218 = ( T_3 T_2 * ) ( unsigned long ) ( V_211 -> V_235 ) ;
for ( V_107 = 0 ; V_107 < V_10 -> V_58 . V_67 ; V_107 ++ ) {
if ( F_79 ( V_10 -> V_58 . V_236 [ V_107 ] ,
V_217 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
if ( F_79 ( V_10 -> V_58 . V_237 [ V_107 ] ,
V_218 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
}
V_211 -> V_233 = V_213 ;
if ( ( V_211 -> V_198 >= V_214 ) && V_214 ) {
V_178 = 0 ;
V_219 = ( T_1 T_2 * ) ( unsigned long ) ( V_211 -> V_238 ) ;
for ( V_107 = 0 ; V_107 < V_220 ; V_107 ++ ) {
if ( V_10 -> V_221 [ V_107 ] != 0 ) {
if ( F_79 ( V_10 -> V_221 [ V_107 ] ,
V_219 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
}
}
V_211 -> V_198 = V_214 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_85 ( struct V_18 * V_19 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_239 * V_240 = V_167 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_240 -> V_182 ,
V_78 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
V_2 = F_86 ( V_21 ) ;
if ( V_2 -> V_46 )
V_240 -> V_180 = V_2 -> V_46 -> V_7 . V_8 ;
else
V_240 -> V_180 = 0 ;
V_240 -> V_5 = V_2 -> V_5 ;
V_240 -> V_182 = V_2 -> V_7 . V_8 ;
V_240 -> V_81 = V_2 -> V_81 ;
V_240 -> V_241 = V_2 -> V_241 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_87 ( struct V_18 * V_19 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_242 * V_243 = V_167 ;
struct V_244 * V_245 ;
struct V_47 * V_48 ;
T_1 T_2 * V_246 ;
int V_178 = 0 , V_24 = 0 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_245 = & V_19 -> V_26 ;
if ( V_245 -> V_89 &&
( V_243 -> V_247 >= V_245 -> V_89 ) ) {
V_246 = ( T_1 T_2 * ) ( unsigned long ) V_243 -> V_248 ;
F_29 (plane, &config->plane_list, head) {
if ( F_79 ( V_48 -> V_7 . V_8 , V_246 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
}
V_243 -> V_247 = V_245 -> V_89 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_88 ( struct V_18 * V_19 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_249 * V_243 = V_167 ;
struct V_20 * V_21 ;
struct V_47 * V_48 ;
T_1 T_2 * V_250 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_243 -> V_251 ,
V_86 ) ;
if ( ! V_21 ) {
V_24 = - V_252 ;
goto V_57;
}
V_48 = F_89 ( V_21 ) ;
if ( V_48 -> V_46 )
V_243 -> V_180 = V_48 -> V_46 -> V_7 . V_8 ;
else
V_243 -> V_180 = 0 ;
if ( V_48 -> V_34 )
V_243 -> V_179 = V_48 -> V_34 -> V_7 . V_8 ;
else
V_243 -> V_179 = 0 ;
V_243 -> V_251 = V_48 -> V_7 . V_8 ;
V_243 -> V_81 = V_48 -> V_81 ;
V_243 -> V_207 = V_48 -> V_207 ;
if ( V_48 -> V_84 &&
( V_243 -> V_253 >= V_48 -> V_84 ) ) {
V_250 = ( T_1 T_2 * ) ( unsigned long ) V_243 -> V_254 ;
if ( F_84 ( V_250 ,
V_48 -> V_87 ,
sizeof( T_1 ) * V_48 -> V_84 ) ) {
V_24 = - V_195 ;
goto V_57;
}
}
V_243 -> V_253 = V_48 -> V_84 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_90 ( struct V_18 * V_19 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_255 * V_256 = V_167 ;
struct V_20 * V_21 ;
struct V_47 * V_48 ;
struct V_45 * V_46 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
unsigned int V_257 , V_258 ;
int V_107 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_256 -> V_251 ,
V_86 ) ;
if ( ! V_21 ) {
F_48 ( L_34 ,
V_256 -> V_251 ) ;
V_24 = - V_252 ;
goto V_57;
}
V_48 = F_89 ( V_21 ) ;
if ( ! V_256 -> V_179 ) {
V_48 -> V_36 -> V_52 ( V_48 ) ;
V_48 -> V_46 = NULL ;
V_48 -> V_34 = NULL ;
goto V_57;
}
V_21 = F_12 ( V_19 , V_256 -> V_180 ,
V_56 ) ;
if ( ! V_21 ) {
F_48 ( L_35 ,
V_256 -> V_180 ) ;
V_24 = - V_252 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
V_21 = F_12 ( V_19 , V_256 -> V_179 ,
V_38 ) ;
if ( ! V_21 ) {
F_48 ( L_36 ,
V_256 -> V_179 ) ;
V_24 = - V_252 ;
goto V_57;
}
V_34 = F_91 ( V_21 ) ;
for ( V_107 = 0 ; V_107 < V_48 -> V_84 ; V_107 ++ )
if ( V_34 -> V_259 == V_48 -> V_87 [ V_107 ] )
break;
if ( V_107 == V_48 -> V_84 ) {
F_48 ( L_37 , V_34 -> V_259 ) ;
V_24 = - V_185 ;
goto V_57;
}
V_257 = V_34 -> V_260 << 16 ;
V_258 = V_34 -> V_261 << 16 ;
if ( V_256 -> V_262 > V_257 ||
V_256 -> V_263 > V_257 - V_256 -> V_262 ||
V_256 -> V_264 > V_258 ||
V_256 -> V_265 > V_258 - V_256 -> V_264 ) {
F_48 ( L_38
L_39 ,
V_256 -> V_262 >> 16 ,
( ( V_256 -> V_262 & 0xffff ) * 15625 ) >> 10 ,
V_256 -> V_264 >> 16 ,
( ( V_256 -> V_264 & 0xffff ) * 15625 ) >> 10 ,
V_256 -> V_263 >> 16 ,
( ( V_256 -> V_263 & 0xffff ) * 15625 ) >> 10 ,
V_256 -> V_265 >> 16 ,
( ( V_256 -> V_265 & 0xffff ) * 15625 ) >> 10 ) ;
V_24 = - V_266 ;
goto V_57;
}
if ( V_256 -> V_267 > V_165 ||
V_256 -> V_268 > V_165 - ( V_269 ) V_256 -> V_267 ||
V_256 -> V_270 > V_165 ||
V_256 -> V_271 > V_165 - ( V_269 ) V_256 -> V_270 ) {
F_48 ( L_40 ,
V_256 -> V_267 , V_256 -> V_270 ,
V_256 -> V_268 , V_256 -> V_271 ) ;
V_24 = - V_166 ;
goto V_57;
}
V_24 = V_48 -> V_36 -> V_272 ( V_48 , V_46 , V_34 ,
V_256 -> V_268 , V_256 -> V_271 ,
V_256 -> V_267 , V_256 -> V_270 ,
V_256 -> V_263 , V_256 -> V_265 ,
V_256 -> V_262 , V_256 -> V_264 ) ;
if ( ! V_24 ) {
V_48 -> V_46 = V_46 ;
V_48 -> V_34 = V_34 ;
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_92 ( struct V_18 * V_19 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_244 * V_245 = & V_19 -> V_26 ;
struct V_203 * V_273 = V_167 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
struct V_9 * * V_274 = NULL , * V_10 ;
struct V_33 * V_34 = NULL ;
struct V_62 * V_63 = NULL ;
struct V_49 V_50 ;
T_1 T_2 * V_275 ;
int V_24 ;
int V_107 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
if ( V_273 -> V_205 > V_165 || V_273 -> V_206 > V_165 )
return - V_166 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_273 -> V_180 ,
V_56 ) ;
if ( ! V_21 ) {
F_48 ( L_41 , V_273 -> V_180 ) ;
V_24 = - V_185 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
F_48 ( L_29 , V_46 -> V_7 . V_8 ) ;
if ( V_273 -> V_209 ) {
int V_151 , V_157 ;
if ( V_273 -> V_179 == - 1 ) {
if ( ! V_46 -> V_34 ) {
F_48 ( L_42 ) ;
V_24 = - V_185 ;
goto V_57;
}
V_34 = V_46 -> V_34 ;
} else {
V_21 = F_12 ( V_19 , V_273 -> V_179 ,
V_38 ) ;
if ( ! V_21 ) {
F_48 ( L_43 ,
V_273 -> V_179 ) ;
V_24 = - V_185 ;
goto V_57;
}
V_34 = F_91 ( V_21 ) ;
}
V_63 = F_51 ( V_19 ) ;
if ( ! V_63 ) {
V_24 = - V_29 ;
goto V_57;
}
V_24 = F_75 ( V_63 , & V_273 -> V_63 ) ;
if ( V_24 ) {
F_48 ( L_44 ) ;
goto V_57;
}
F_93 ( V_63 , V_276 ) ;
V_151 = V_63 -> V_151 ;
V_157 = V_63 -> V_157 ;
if ( V_46 -> V_55 )
F_94 ( V_151 , V_157 ) ;
if ( V_151 > V_34 -> V_260 ||
V_157 > V_34 -> V_261 ||
V_273 -> V_205 > V_34 -> V_260 - V_151 ||
V_273 -> V_206 > V_34 -> V_261 - V_157 ) {
F_48 ( L_45 ,
V_34 -> V_260 , V_34 -> V_261 ,
V_151 , V_157 , V_273 -> V_205 , V_273 -> V_206 ,
V_46 -> V_55 ? L_46 : L_47 ) ;
V_24 = - V_266 ;
goto V_57;
}
}
if ( V_273 -> V_200 == 0 && V_63 ) {
F_48 ( L_48 ) ;
V_24 = - V_185 ;
goto V_57;
}
if ( V_273 -> V_200 > 0 && ( ! V_63 || ! V_34 ) ) {
F_48 ( L_49 ,
V_273 -> V_200 ) ;
V_24 = - V_185 ;
goto V_57;
}
if ( V_273 -> V_200 > 0 ) {
T_4 V_277 ;
if ( V_273 -> V_200 > V_245 -> V_72 ) {
V_24 = - V_185 ;
goto V_57;
}
V_274 = F_47 ( V_273 -> V_200 *
sizeof( struct V_9 * ) ,
V_28 ) ;
if ( ! V_274 ) {
V_24 = - V_29 ;
goto V_57;
}
for ( V_107 = 0 ; V_107 < V_273 -> V_200 ; V_107 ++ ) {
V_275 = ( T_1 T_2 * ) ( unsigned long ) V_273 -> V_275 ;
if ( F_95 ( V_277 , & V_275 [ V_107 ] ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_21 = F_12 ( V_19 , V_277 ,
V_66 ) ;
if ( ! V_21 ) {
F_48 ( L_50 ,
V_277 ) ;
V_24 = - V_185 ;
goto V_57;
}
V_10 = F_83 ( V_21 ) ;
F_48 ( L_31 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
V_274 [ V_107 ] = V_10 ;
}
}
V_50 . V_46 = V_46 ;
V_50 . V_205 = V_273 -> V_205 ;
V_50 . V_206 = V_273 -> V_206 ;
V_50 . V_63 = V_63 ;
V_50 . V_278 = V_274 ;
V_50 . V_140 = V_273 -> V_200 ;
V_50 . V_34 = V_34 ;
V_24 = V_46 -> V_36 -> V_51 ( & V_50 ) ;
V_57:
F_33 ( V_274 ) ;
F_36 ( V_19 , V_63 ) ;
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_96 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_279 * V_280 = V_167 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
if ( ! V_280 -> V_163 || ( ~ V_281 & V_280 -> V_163 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_280 -> V_180 , V_56 ) ;
if ( ! V_21 ) {
F_48 ( L_41 , V_280 -> V_180 ) ;
V_24 = - V_185 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
if ( V_280 -> V_163 & V_282 ) {
if ( ! V_46 -> V_36 -> V_283 ) {
V_24 = - V_284 ;
goto V_57;
}
V_24 = V_46 -> V_36 -> V_283 ( V_46 , V_169 , V_280 -> V_285 ,
V_280 -> V_260 , V_280 -> V_261 ) ;
}
if ( V_280 -> V_163 & V_286 ) {
if ( V_46 -> V_36 -> V_287 ) {
V_24 = V_46 -> V_36 -> V_287 ( V_46 , V_280 -> V_205 , V_280 -> V_206 ) ;
} else {
V_24 = - V_195 ;
goto V_57;
}
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
T_1 F_97 ( T_1 V_288 , T_1 V_289 )
{
T_1 V_290 ;
switch ( V_288 ) {
case 8 :
V_290 = V_291 ;
break;
case 16 :
if ( V_289 == 15 )
V_290 = V_292 ;
else
V_290 = V_293 ;
break;
case 24 :
V_290 = V_294 ;
break;
case 32 :
if ( V_289 == 24 )
V_290 = V_295 ;
else if ( V_289 == 30 )
V_290 = V_296 ;
else
V_290 = V_297 ;
break;
default:
F_6 ( L_51 ) ;
V_290 = V_295 ;
break;
}
return V_290 ;
}
int F_98 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_298 * V_299 = V_167 ;
struct V_300 V_301 = {} ;
struct V_244 * V_245 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
V_301 . V_179 = V_299 -> V_179 ;
V_301 . V_260 = V_299 -> V_260 ;
V_301 . V_261 = V_299 -> V_261 ;
V_301 . V_302 [ 0 ] = V_299 -> V_303 ;
V_301 . V_259 = F_97 ( V_299 -> V_288 , V_299 -> V_289 ) ;
V_301 . V_304 [ 0 ] = V_299 -> V_285 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
if ( ( V_245 -> V_192 > V_301 . V_260 ) || ( V_301 . V_260 > V_245 -> V_191 ) )
return - V_185 ;
if ( ( V_245 -> V_190 > V_301 . V_261 ) || ( V_301 . V_261 > V_245 -> V_189 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_305 ( V_19 , V_169 , & V_301 ) ;
if ( F_99 ( V_34 ) ) {
F_48 ( L_52 ) ;
V_24 = F_100 ( V_34 ) ;
goto V_57;
}
V_299 -> V_179 = V_34 -> V_7 . V_8 ;
F_16 ( & V_34 -> V_53 , & V_169 -> V_306 ) ;
F_48 ( L_53 , V_34 -> V_7 . V_8 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
static int F_101 ( const struct V_300 * V_301 )
{
T_1 V_307 = V_301 -> V_259 & ~ V_308 ;
switch ( V_307 ) {
case V_309 :
case V_291 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_292 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_293 :
case V_326 :
case V_294 :
case V_327 :
case V_295 :
case V_328 :
case V_329 :
case V_330 :
case V_297 :
case V_331 :
case V_332 :
case V_333 :
case V_296 :
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
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
return 0 ;
default:
return - V_185 ;
}
}
static int F_102 ( const struct V_300 * V_301 )
{
int V_24 , V_362 , V_363 , V_364 , V_107 ;
V_24 = F_101 ( V_301 ) ;
if ( V_24 ) {
F_48 ( L_54 , V_301 -> V_259 ) ;
return V_24 ;
}
V_362 = F_103 ( V_301 -> V_259 ) ;
V_363 = F_104 ( V_301 -> V_259 ) ;
V_364 = F_105 ( V_301 -> V_259 ) ;
if ( V_301 -> V_260 == 0 || V_301 -> V_260 % V_362 ) {
F_48 ( L_55 , V_301 -> V_261 ) ;
return - V_185 ;
}
if ( V_301 -> V_261 == 0 || V_301 -> V_261 % V_363 ) {
F_48 ( L_56 , V_301 -> V_261 ) ;
return - V_185 ;
}
for ( V_107 = 0 ; V_107 < V_364 ; V_107 ++ ) {
unsigned int V_260 = V_301 -> V_260 / ( V_107 != 0 ? V_362 : 1 ) ;
if ( ! V_301 -> V_304 [ V_107 ] ) {
F_48 ( L_57 , V_107 ) ;
return - V_185 ;
}
if ( V_301 -> V_302 [ V_107 ] < F_106 ( V_301 -> V_259 , V_107 ) * V_260 ) {
F_48 ( L_58 , V_301 -> V_302 [ V_107 ] , V_107 ) ;
return - V_185 ;
}
}
return 0 ;
}
int F_107 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_300 * V_301 = V_167 ;
struct V_244 * V_245 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
if ( ( V_245 -> V_192 > V_301 -> V_260 ) || ( V_301 -> V_260 > V_245 -> V_191 ) ) {
F_48 ( L_59 ,
V_301 -> V_260 , V_245 -> V_192 , V_245 -> V_191 ) ;
return - V_185 ;
}
if ( ( V_245 -> V_190 > V_301 -> V_261 ) || ( V_301 -> V_261 > V_245 -> V_189 ) ) {
F_48 ( L_60 ,
V_301 -> V_261 , V_245 -> V_190 , V_245 -> V_189 ) ;
return - V_185 ;
}
V_24 = F_102 ( V_301 ) ;
if ( V_24 )
return V_24 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_305 ( V_19 , V_169 , V_301 ) ;
if ( F_99 ( V_34 ) ) {
F_48 ( L_52 ) ;
V_24 = F_100 ( V_34 ) ;
goto V_57;
}
V_301 -> V_179 = V_34 -> V_7 . V_8 ;
F_16 ( & V_34 -> V_53 , & V_169 -> V_306 ) ;
F_48 ( L_53 , V_34 -> V_7 . V_8 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_108 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_20 * V_21 ;
struct V_33 * V_34 = NULL ;
struct V_33 * V_365 = NULL ;
T_1 * V_8 = V_167 ;
int V_24 = 0 ;
int V_366 = 0 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , * V_8 , V_38 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
V_34 = F_91 ( V_21 ) ;
F_29 (fbl, &file_priv->fbs, filp_head)
if ( V_34 == V_365 )
V_366 = 1 ;
if ( ! V_366 ) {
V_24 = - V_185 ;
goto V_57;
}
F_28 ( V_34 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_109 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_298 * V_301 = V_167 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_301 -> V_179 , V_38 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
V_34 = F_91 ( V_21 ) ;
V_301 -> V_261 = V_34 -> V_261 ;
V_301 -> V_260 = V_34 -> V_260 ;
V_301 -> V_289 = V_34 -> V_289 ;
V_301 -> V_288 = V_34 -> V_367 ;
V_301 -> V_303 = V_34 -> V_302 [ 0 ] ;
V_34 -> V_36 -> V_368 ( V_34 , V_169 , & V_301 -> V_285 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_110 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_369 T_2 * V_370 ;
struct V_369 * V_371 = NULL ;
struct V_372 * V_301 = V_167 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
unsigned V_163 ;
int V_373 ;
int V_24 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_301 -> V_179 , V_38 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_374;
}
V_34 = F_91 ( V_21 ) ;
V_373 = V_301 -> V_373 ;
V_370 = (struct V_369 T_2 * ) ( unsigned long ) V_301 -> V_370 ;
if ( ! V_373 != ! V_370 ) {
V_24 = - V_185 ;
goto V_374;
}
V_163 = V_375 & V_301 -> V_163 ;
if ( V_163 & V_376 && ( V_373 % 2 ) ) {
V_24 = - V_185 ;
goto V_374;
}
if ( V_373 && V_370 ) {
if ( V_373 < 0 || V_373 > V_377 ) {
V_24 = - V_185 ;
goto V_374;
}
V_371 = F_52 ( V_373 * sizeof( * V_371 ) , V_28 ) ;
if ( ! V_371 ) {
V_24 = - V_29 ;
goto V_374;
}
V_24 = F_111 ( V_371 , V_370 ,
V_373 * sizeof( * V_371 ) ) ;
if ( V_24 ) {
V_24 = - V_195 ;
goto V_378;
}
}
if ( V_34 -> V_36 -> V_379 ) {
V_24 = V_34 -> V_36 -> V_379 ( V_34 , V_169 , V_163 , V_301 -> V_380 ,
V_371 , V_373 ) ;
} else {
V_24 = - V_381 ;
goto V_378;
}
V_378:
F_33 ( V_371 ) ;
V_374:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
void F_112 ( struct V_168 * V_85 )
{
struct V_18 * V_19 = V_85 -> V_187 -> V_19 ;
struct V_33 * V_34 , * V_382 ;
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
struct V_62 * V_383 , * V_384 ;
F_115 ( V_385 ) ;
F_29 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
continue;
if ( V_10 -> V_2 -> V_46 == V_46 ) {
V_383 = F_116 ( V_19 , V_63 ) ;
if ( ! V_383 ) {
V_24 = - V_29 ;
goto V_57;
}
F_31 ( & V_383 -> V_40 , & V_385 ) ;
}
}
F_29 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
continue;
if ( V_10 -> V_2 -> V_46 == V_46 )
F_117 ( V_385 . V_384 , & V_10 -> V_68 ) ;
}
F_21 ( ! F_50 ( & V_385 ) ) ;
V_57:
F_41 (dup_mode, next, &list, head)
F_36 ( V_19 , V_383 ) ;
return V_24 ;
}
static int F_118 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_62 * V_63 )
{
int V_366 = 0 ;
int V_24 = 0 ;
struct V_62 * V_386 , * V_76 ;
F_41 (match_mode, t, &connector->user_modes, head) {
if ( F_119 ( V_386 , V_63 ) ) {
F_27 ( & V_386 -> V_40 ) ;
F_36 ( V_19 , V_386 ) ;
V_366 = 1 ;
break;
}
}
if ( ! V_366 )
V_24 = - V_185 ;
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
void * V_167 , struct V_168 * V_169 )
{
struct V_387 * V_388 = V_167 ;
struct V_9 * V_10 ;
struct V_62 * V_63 ;
struct V_20 * V_21 ;
struct V_149 * V_389 = & V_388 -> V_63 ;
int V_24 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_388 -> V_181 , V_66 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
V_10 = F_83 ( V_21 ) ;
V_63 = F_51 ( V_19 ) ;
if ( ! V_63 ) {
V_24 = - V_29 ;
goto V_57;
}
V_24 = F_75 ( V_63 , V_389 ) ;
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
void * V_167 , struct V_168 * V_169 )
{
struct V_20 * V_21 ;
struct V_387 * V_388 = V_167 ;
struct V_9 * V_10 ;
struct V_62 V_63 ;
struct V_149 * V_389 = & V_388 -> V_63 ;
int V_24 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_388 -> V_181 , V_66 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
V_10 = F_83 ( V_21 ) ;
V_24 = F_75 ( & V_63 , V_389 ) ;
if ( V_24 ) {
F_48 ( L_44 ) ;
goto V_57;
}
V_24 = F_118 ( V_19 , V_10 , & V_63 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
struct V_92 * F_54 ( struct V_18 * V_19 , int V_163 ,
const char * V_6 , int V_390 )
{
struct V_92 * V_146 = NULL ;
int V_24 ;
V_146 = F_52 ( sizeof( struct V_92 ) , V_28 ) ;
if ( ! V_146 )
return NULL ;
if ( V_390 ) {
V_146 -> V_237 = F_52 ( sizeof( T_3 ) * V_390 , V_28 ) ;
if ( ! V_146 -> V_237 )
goto V_391;
}
V_24 = F_4 ( V_19 , & V_146 -> V_7 , V_392 ) ;
if ( V_24 )
goto V_391;
V_146 -> V_163 = V_163 ;
V_146 -> V_390 = V_390 ;
F_38 ( & V_146 -> V_393 ) ;
if ( V_6 ) {
strncpy ( V_146 -> V_6 , V_6 , V_394 ) ;
V_146 -> V_6 [ V_394 - 1 ] = '\0' ;
}
F_31 ( & V_146 -> V_40 , & V_19 -> V_26 . V_133 ) ;
return V_146 ;
V_391:
F_33 ( V_146 -> V_237 ) ;
F_33 ( V_146 ) ;
return NULL ;
}
struct V_92 * F_55 ( struct V_18 * V_19 , int V_163 ,
const char * V_6 ,
const struct V_395 * V_396 ,
int V_390 )
{
struct V_92 * V_146 ;
int V_107 , V_24 ;
V_163 |= V_117 ;
V_146 = F_54 ( V_19 , V_163 , V_6 , V_390 ) ;
if ( ! V_146 )
return NULL ;
for ( V_107 = 0 ; V_107 < V_390 ; V_107 ++ ) {
V_24 = F_60 ( V_146 , V_107 ,
V_396 [ V_107 ] . type ,
V_396 [ V_107 ] . V_6 ) ;
if ( V_24 ) {
F_70 ( V_19 , V_146 ) ;
return NULL ;
}
}
return V_146 ;
}
struct V_92 * F_123 ( struct V_18 * V_19 ,
int V_163 , const char * V_6 ,
const struct V_395 * V_396 ,
int V_390 )
{
struct V_92 * V_146 ;
int V_107 , V_24 ;
V_163 |= V_397 ;
V_146 = F_54 ( V_19 , V_163 , V_6 , V_390 ) ;
if ( ! V_146 )
return NULL ;
for ( V_107 = 0 ; V_107 < V_390 ; V_107 ++ ) {
V_24 = F_60 ( V_146 , V_107 ,
V_396 [ V_107 ] . type ,
V_396 [ V_107 ] . V_6 ) ;
if ( V_24 ) {
F_70 ( V_19 , V_146 ) ;
return NULL ;
}
}
return V_146 ;
}
struct V_92 * F_59 ( struct V_18 * V_19 , int V_163 ,
const char * V_6 ,
T_3 V_398 , T_3 V_399 )
{
struct V_92 * V_146 ;
V_163 |= V_400 ;
V_146 = F_54 ( V_19 , V_163 , V_6 , 2 ) ;
if ( ! V_146 )
return NULL ;
V_146 -> V_237 [ 0 ] = V_398 ;
V_146 -> V_237 [ 1 ] = V_399 ;
return V_146 ;
}
int F_60 ( struct V_92 * V_146 , int V_401 ,
T_3 V_402 , const char * V_6 )
{
struct V_403 * V_404 ;
if ( ! ( V_146 -> V_163 & ( V_117 | V_397 ) ) )
return - V_185 ;
if ( ( V_146 -> V_163 & V_397 ) && ( V_402 > 63 ) )
return - V_185 ;
if ( ! F_50 ( & V_146 -> V_393 ) ) {
F_29 (prop_enum, &property->enum_blob_list, head) {
if ( V_404 -> V_402 == V_402 ) {
strncpy ( V_404 -> V_6 , V_6 , V_394 ) ;
V_404 -> V_6 [ V_394 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_404 = F_52 ( sizeof( struct V_403 ) , V_28 ) ;
if ( ! V_404 )
return - V_29 ;
strncpy ( V_404 -> V_6 , V_6 , V_394 ) ;
V_404 -> V_6 [ V_394 - 1 ] = '\0' ;
V_404 -> V_402 = V_402 ;
V_146 -> V_237 [ V_401 ] = V_402 ;
F_31 ( & V_404 -> V_40 , & V_146 -> V_393 ) ;
return 0 ;
}
void F_70 ( struct V_18 * V_19 , struct V_92 * V_146 )
{
struct V_403 * V_404 , * V_147 ;
F_41 (prop_enum, pt, &property->enum_blob_list, head) {
F_27 ( & V_404 -> V_40 ) ;
F_33 ( V_404 ) ;
}
if ( V_146 -> V_390 )
F_33 ( V_146 -> V_237 ) ;
F_10 ( V_19 , & V_146 -> V_7 ) ;
F_27 ( & V_146 -> V_40 ) ;
F_33 ( V_146 ) ;
}
void F_39 ( struct V_9 * V_10 ,
struct V_92 * V_146 , T_3 V_405 )
{
F_124 ( & V_10 -> V_7 , V_146 , V_405 ) ;
}
int F_125 ( struct V_9 * V_10 ,
struct V_92 * V_146 , T_3 V_402 )
{
return F_126 ( & V_10 -> V_7 , V_146 , V_402 ) ;
}
int F_127 ( struct V_9 * V_10 ,
struct V_92 * V_146 , T_3 * V_406 )
{
return F_128 ( & V_10 -> V_7 , V_146 , V_406 ) ;
}
void F_124 ( struct V_20 * V_21 ,
struct V_92 * V_146 ,
T_3 V_405 )
{
int V_67 = V_21 -> V_58 -> V_67 ;
if ( V_67 == V_407 ) {
F_74 ( 1 , L_61
L_62
L_63 ,
V_21 -> type ) ;
return;
}
V_21 -> V_58 -> V_236 [ V_67 ] = V_146 -> V_7 . V_8 ;
V_21 -> V_58 -> V_237 [ V_67 ] = V_405 ;
V_21 -> V_58 -> V_67 ++ ;
}
int F_126 ( struct V_20 * V_21 ,
struct V_92 * V_146 , T_3 V_406 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_21 -> V_58 -> V_67 ; V_107 ++ ) {
if ( V_21 -> V_58 -> V_236 [ V_107 ] == V_146 -> V_7 . V_8 ) {
V_21 -> V_58 -> V_237 [ V_107 ] = V_406 ;
return 0 ;
}
}
return - V_185 ;
}
int F_128 ( struct V_20 * V_21 ,
struct V_92 * V_146 , T_3 * V_406 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_21 -> V_58 -> V_67 ; V_107 ++ ) {
if ( V_21 -> V_58 -> V_236 [ V_107 ] == V_146 -> V_7 . V_8 ) {
* V_406 = V_21 -> V_58 -> V_237 [ V_107 ] ;
return 0 ;
}
}
return - V_185 ;
}
int F_129 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_20 * V_21 ;
struct V_408 * V_211 = V_167 ;
struct V_92 * V_146 ;
int V_409 = 0 ;
int V_410 = 0 ;
int V_411 = 0 ;
int V_24 = 0 , V_107 ;
int V_178 ;
struct V_403 * V_404 ;
struct V_412 T_2 * V_413 ;
struct V_414 * V_415 ;
T_1 T_2 * V_416 ;
T_3 T_2 * V_417 ;
T_1 T_2 * V_418 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_211 -> V_419 , V_392 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_420;
}
V_146 = F_130 ( V_21 ) ;
if ( V_146 -> V_163 & ( V_117 | V_397 ) ) {
F_29 (prop_enum, &property->enum_blob_list, head)
V_409 ++ ;
} else if ( V_146 -> V_163 & V_95 ) {
F_29 (prop_blob, &property->enum_blob_list, head)
V_410 ++ ;
}
V_411 = V_146 -> V_390 ;
strncpy ( V_211 -> V_6 , V_146 -> V_6 , V_394 ) ;
V_211 -> V_6 [ V_394 - 1 ] = 0 ;
V_211 -> V_163 = V_146 -> V_163 ;
if ( ( V_211 -> V_421 >= V_411 ) && V_411 ) {
V_417 = ( T_3 T_2 * ) ( unsigned long ) V_211 -> V_417 ;
for ( V_107 = 0 ; V_107 < V_411 ; V_107 ++ ) {
if ( F_84 ( V_417 + V_107 , & V_146 -> V_237 [ V_107 ] , sizeof( T_3 ) ) ) {
V_24 = - V_195 ;
goto V_420;
}
}
}
V_211 -> V_421 = V_411 ;
if ( V_146 -> V_163 & ( V_117 | V_397 ) ) {
if ( ( V_211 -> V_422 >= V_409 ) && V_409 ) {
V_178 = 0 ;
V_413 = (struct V_412 T_2 * ) ( unsigned long ) V_211 -> V_423 ;
F_29 (prop_enum, &property->enum_blob_list, head) {
if ( F_84 ( & V_413 [ V_178 ] . V_402 , & V_404 -> V_402 , sizeof( T_3 ) ) ) {
V_24 = - V_195 ;
goto V_420;
}
if ( F_84 ( & V_413 [ V_178 ] . V_6 ,
& V_404 -> V_6 , V_394 ) ) {
V_24 = - V_195 ;
goto V_420;
}
V_178 ++ ;
}
}
V_211 -> V_422 = V_409 ;
}
if ( V_146 -> V_163 & V_95 ) {
if ( ( V_211 -> V_422 >= V_410 ) && V_410 ) {
V_178 = 0 ;
V_416 = ( T_1 T_2 * ) ( unsigned long ) V_211 -> V_423 ;
V_418 = ( T_1 T_2 * ) ( unsigned long ) V_211 -> V_417 ;
F_29 (prop_blob, &property->enum_blob_list, head) {
if ( F_79 ( V_415 -> V_7 . V_8 , V_416 + V_178 ) ) {
V_24 = - V_195 ;
goto V_420;
}
if ( F_79 ( V_415 -> V_424 , V_418 + V_178 ) ) {
V_24 = - V_195 ;
goto V_420;
}
V_178 ++ ;
}
}
V_211 -> V_422 = V_410 ;
}
V_420:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
static struct V_414 * F_131 ( struct V_18 * V_19 , int V_424 ,
void * V_167 )
{
struct V_414 * V_425 ;
int V_24 ;
if ( ! V_424 || ! V_167 )
return NULL ;
V_425 = F_52 ( sizeof( struct V_414 ) + V_424 , V_28 ) ;
if ( ! V_425 )
return NULL ;
V_24 = F_4 ( V_19 , & V_425 -> V_7 , V_426 ) ;
if ( V_24 ) {
F_33 ( V_425 ) ;
return NULL ;
}
V_425 -> V_424 = V_424 ;
memcpy ( V_425 -> V_167 , V_167 , V_424 ) ;
F_31 ( & V_425 -> V_40 , & V_19 -> V_26 . V_134 ) ;
return V_425 ;
}
static void F_132 ( struct V_18 * V_19 ,
struct V_414 * V_425 )
{
F_10 ( V_19 , & V_425 -> V_7 ) ;
F_27 ( & V_425 -> V_40 ) ;
F_33 ( V_425 ) ;
}
int F_133 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_20 * V_21 ;
struct V_427 * V_211 = V_167 ;
struct V_414 * V_425 ;
int V_24 = 0 ;
void T_2 * V_428 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_211 -> V_429 , V_426 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_420;
}
V_425 = F_134 ( V_21 ) ;
if ( V_211 -> V_424 == V_425 -> V_424 ) {
V_428 = ( void T_2 * ) ( unsigned long ) V_211 -> V_167 ;
if ( F_84 ( V_428 , V_425 -> V_167 , V_425 -> V_424 ) ) {
V_24 = - V_195 ;
goto V_420;
}
}
V_211 -> V_424 = V_425 -> V_424 ;
V_420:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_135 ( struct V_9 * V_10 ,
struct V_93 * V_93 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
int V_24 , V_430 ;
if ( V_10 -> V_70 )
F_132 ( V_19 , V_10 -> V_70 ) ;
if ( ! V_93 ) {
V_10 -> V_70 = NULL ;
V_24 = F_125 ( V_10 , V_19 -> V_26 . V_74 , 0 ) ;
return V_24 ;
}
V_430 = V_431 * ( 1 + V_93 -> V_432 ) ;
V_10 -> V_70 = F_131 ( V_10 -> V_19 ,
V_430 , V_93 ) ;
V_24 = F_125 ( V_10 ,
V_19 -> V_26 . V_74 ,
V_10 -> V_70 -> V_7 . V_8 ) ;
return V_24 ;
}
static bool F_136 ( struct V_92 * V_146 ,
T_3 V_402 )
{
if ( V_146 -> V_163 & V_96 )
return false ;
if ( V_146 -> V_163 & V_400 ) {
if ( V_402 < V_146 -> V_237 [ 0 ] || V_402 > V_146 -> V_237 [ 1 ] )
return false ;
return true ;
} else if ( V_146 -> V_163 & V_397 ) {
int V_107 ;
T_3 V_433 = 0 ;
for ( V_107 = 0 ; V_107 < V_146 -> V_390 ; V_107 ++ )
V_433 |= ( 1ULL << V_146 -> V_237 [ V_107 ] ) ;
return ! ( V_402 & ~ V_433 ) ;
} else {
int V_107 ;
for ( V_107 = 0 ; V_107 < V_146 -> V_390 ; V_107 ++ )
if ( V_146 -> V_237 [ V_107 ] == V_402 )
return true ;
return false ;
}
}
int F_137 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_434 * V_435 = V_167 ;
struct V_436 V_437 = {
. V_402 = V_435 -> V_402 ,
. V_419 = V_435 -> V_419 ,
. V_438 = V_435 -> V_181 ,
. V_22 = V_66
} ;
return F_138 ( V_19 , & V_437 , V_169 ) ;
}
static int F_139 ( struct V_20 * V_21 ,
struct V_92 * V_146 ,
T_3 V_402 )
{
int V_24 = - V_185 ;
struct V_9 * V_10 = F_83 ( V_21 ) ;
if ( V_146 == V_10 -> V_19 -> V_26 . V_75 ) {
if ( V_10 -> V_36 -> V_94 )
(* V_10 -> V_36 -> V_94 )( V_10 , ( int ) V_402 ) ;
V_24 = 0 ;
} else if ( V_10 -> V_36 -> V_439 )
V_24 = V_10 -> V_36 -> V_439 ( V_10 , V_146 , V_402 ) ;
if ( ! V_24 )
F_125 ( V_10 , V_146 , V_402 ) ;
return V_24 ;
}
static int F_140 ( struct V_20 * V_21 ,
struct V_92 * V_146 ,
T_3 V_402 )
{
int V_24 = - V_185 ;
struct V_45 * V_46 = F_81 ( V_21 ) ;
if ( V_46 -> V_36 -> V_439 )
V_24 = V_46 -> V_36 -> V_439 ( V_46 , V_146 , V_402 ) ;
if ( ! V_24 )
F_126 ( V_21 , V_146 , V_402 ) ;
return V_24 ;
}
static int F_141 ( struct V_20 * V_21 ,
struct V_92 * V_146 ,
T_3 V_402 )
{
int V_24 = - V_185 ;
struct V_47 * V_48 = F_89 ( V_21 ) ;
if ( V_48 -> V_36 -> V_439 )
V_24 = V_48 -> V_36 -> V_439 ( V_48 , V_146 , V_402 ) ;
if ( ! V_24 )
F_126 ( V_21 , V_146 , V_402 ) ;
return V_24 ;
}
int F_142 ( struct V_18 * V_19 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_440 * V_441 = V_167 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
int V_107 ;
int V_178 = 0 ;
int V_213 = 0 ;
T_1 T_2 * V_234 ;
T_3 T_2 * V_235 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_441 -> V_438 , V_441 -> V_22 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
if ( ! V_21 -> V_58 ) {
V_24 = - V_185 ;
goto V_57;
}
V_213 = V_21 -> V_58 -> V_67 ;
if ( ( V_441 -> V_233 >= V_213 ) && V_213 ) {
V_178 = 0 ;
V_234 = ( T_1 T_2 * ) ( unsigned long ) ( V_441 -> V_234 ) ;
V_235 = ( T_3 T_2 * ) ( unsigned long )
( V_441 -> V_235 ) ;
for ( V_107 = 0 ; V_107 < V_213 ; V_107 ++ ) {
if ( F_79 ( V_21 -> V_58 -> V_236 [ V_107 ] ,
V_234 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
if ( F_79 ( V_21 -> V_58 -> V_237 [ V_107 ] ,
V_235 + V_178 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_178 ++ ;
}
}
V_441 -> V_233 = V_213 ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_138 ( struct V_18 * V_19 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_436 * V_441 = V_167 ;
struct V_20 * V_442 ;
struct V_20 * V_443 ;
struct V_92 * V_146 ;
int V_24 = - V_185 ;
int V_107 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_442 = F_12 ( V_19 , V_441 -> V_438 , V_441 -> V_22 ) ;
if ( ! V_442 )
goto V_57;
if ( ! V_442 -> V_58 )
goto V_57;
for ( V_107 = 0 ; V_107 < V_442 -> V_58 -> V_67 ; V_107 ++ )
if ( V_442 -> V_58 -> V_236 [ V_107 ] == V_441 -> V_419 )
break;
if ( V_107 == V_442 -> V_58 -> V_67 )
goto V_57;
V_443 = F_12 ( V_19 , V_441 -> V_419 ,
V_392 ) ;
if ( ! V_443 )
goto V_57;
V_146 = F_130 ( V_443 ) ;
if ( ! F_136 ( V_146 , V_441 -> V_402 ) )
goto V_57;
switch ( V_442 -> type ) {
case V_66 :
V_24 = F_139 ( V_442 , V_146 ,
V_441 -> V_402 ) ;
break;
case V_56 :
V_24 = F_140 ( V_442 , V_146 , V_441 -> V_402 ) ;
break;
case V_86 :
V_24 = F_141 ( V_442 , V_146 , V_441 -> V_402 ) ;
break;
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_143 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_220 ; V_107 ++ ) {
if ( V_10 -> V_221 [ V_107 ] == 0 ) {
V_10 -> V_221 [ V_107 ] = V_2 -> V_7 . V_8 ;
return 0 ;
}
}
return - V_29 ;
}
void F_144 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_220 ; V_107 ++ ) {
if ( V_10 -> V_221 [ V_107 ] == V_2 -> V_7 . V_8 ) {
V_10 -> V_221 [ V_107 ] = 0 ;
if ( V_10 -> V_2 == V_2 )
V_10 -> V_2 = NULL ;
break;
}
}
}
int F_145 ( struct V_45 * V_46 ,
int V_207 )
{
V_46 -> V_207 = V_207 ;
V_46 -> V_61 = F_52 ( V_207 * sizeof( V_444 ) * 3 , V_28 ) ;
if ( ! V_46 -> V_61 ) {
V_46 -> V_207 = 0 ;
return - V_29 ;
}
return 0 ;
}
int F_146 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_445 * V_446 = V_167 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
void * V_447 , * V_448 , * V_449 ;
int V_430 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_446 -> V_180 , V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
if ( V_46 -> V_36 -> V_450 == NULL ) {
V_24 = - V_381 ;
goto V_57;
}
if ( V_446 -> V_207 != V_46 -> V_207 ) {
V_24 = - V_185 ;
goto V_57;
}
V_430 = V_446 -> V_207 * ( sizeof( V_444 ) ) ;
V_447 = V_46 -> V_61 ;
if ( F_111 ( V_447 , ( void T_2 * ) ( unsigned long ) V_446 -> V_451 , V_430 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_448 = V_447 + V_430 ;
if ( F_111 ( V_448 , ( void T_2 * ) ( unsigned long ) V_446 -> V_452 , V_430 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_449 = V_448 + V_430 ;
if ( F_111 ( V_449 , ( void T_2 * ) ( unsigned long ) V_446 -> V_453 , V_430 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_46 -> V_36 -> V_450 ( V_46 , V_447 , V_448 , V_449 , 0 , V_46 -> V_207 ) ;
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_147 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_445 * V_446 = V_167 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
void * V_447 , * V_448 , * V_449 ;
int V_430 ;
int V_24 = 0 ;
if ( ! F_77 ( V_19 , V_184 ) )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_446 -> V_180 , V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_185 ;
goto V_57;
}
V_46 = F_81 ( V_21 ) ;
if ( V_446 -> V_207 != V_46 -> V_207 ) {
V_24 = - V_185 ;
goto V_57;
}
V_430 = V_446 -> V_207 * ( sizeof( V_444 ) ) ;
V_447 = V_46 -> V_61 ;
if ( F_84 ( ( void T_2 * ) ( unsigned long ) V_446 -> V_451 , V_447 , V_430 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_448 = V_447 + V_430 ;
if ( F_84 ( ( void T_2 * ) ( unsigned long ) V_446 -> V_452 , V_448 , V_430 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_449 = V_448 + V_430 ;
if ( F_84 ( ( void T_2 * ) ( unsigned long ) V_446 -> V_453 , V_449 , V_430 ) ) {
V_24 = - V_195 ;
goto V_57;
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
int F_148 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_454 * V_455 = V_167 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
struct V_33 * V_34 ;
struct V_456 * V_457 = NULL ;
unsigned long V_163 ;
int V_151 , V_157 ;
int V_24 = - V_185 ;
if ( V_455 -> V_163 & ~ V_458 ||
V_455 -> V_459 != 0 )
return - V_185 ;
F_7 ( & V_19 -> V_26 . V_44 ) ;
V_21 = F_12 ( V_19 , V_455 -> V_180 , V_56 ) ;
if ( ! V_21 )
goto V_57;
V_46 = F_81 ( V_21 ) ;
if ( V_46 -> V_34 == NULL ) {
V_24 = - V_460 ;
goto V_57;
}
if ( V_46 -> V_36 -> V_455 == NULL )
goto V_57;
V_21 = F_12 ( V_19 , V_455 -> V_179 , V_38 ) ;
if ( ! V_21 )
goto V_57;
V_34 = F_91 ( V_21 ) ;
V_151 = V_46 -> V_63 . V_151 ;
V_157 = V_46 -> V_63 . V_157 ;
if ( V_46 -> V_55 )
F_94 ( V_151 , V_157 ) ;
if ( V_151 > V_34 -> V_260 ||
V_157 > V_34 -> V_261 ||
V_46 -> V_205 > V_34 -> V_260 - V_151 ||
V_46 -> V_206 > V_34 -> V_261 - V_157 ) {
F_48 ( L_45 ,
V_34 -> V_260 , V_34 -> V_261 , V_151 , V_157 , V_46 -> V_205 , V_46 -> V_206 ,
V_46 -> V_55 ? L_46 : L_47 ) ;
V_24 = - V_266 ;
goto V_57;
}
if ( V_455 -> V_163 & V_461 ) {
V_24 = - V_29 ;
F_149 ( & V_19 -> V_462 , V_163 ) ;
if ( V_169 -> V_463 < sizeof V_457 -> V_464 ) {
F_150 ( & V_19 -> V_462 , V_163 ) ;
goto V_57;
}
V_169 -> V_463 -= sizeof V_457 -> V_464 ;
F_150 ( & V_19 -> V_462 , V_163 ) ;
V_457 = F_52 ( sizeof *V_457 , V_28 ) ;
if ( V_457 == NULL ) {
F_149 ( & V_19 -> V_462 , V_163 ) ;
V_169 -> V_463 += sizeof V_457 -> V_464 ;
F_150 ( & V_19 -> V_462 , V_163 ) ;
goto V_57;
}
V_457 -> V_464 . V_7 . type = V_465 ;
V_457 -> V_464 . V_7 . V_424 = sizeof V_457 -> V_464 ;
V_457 -> V_464 . V_466 = V_455 -> V_466 ;
V_457 -> V_7 . V_464 = & V_457 -> V_464 . V_7 ;
V_457 -> V_7 . V_169 = V_169 ;
V_457 -> V_7 . V_43 =
( void ( * ) ( struct V_467 * ) ) F_33 ;
}
V_24 = V_46 -> V_36 -> V_455 ( V_46 , V_34 , V_457 ) ;
if ( V_24 ) {
if ( V_455 -> V_163 & V_461 ) {
F_149 ( & V_19 -> V_462 , V_163 ) ;
V_169 -> V_463 += sizeof V_457 -> V_464 ;
F_150 ( & V_19 -> V_462 , V_163 ) ;
F_33 ( V_457 ) ;
}
}
V_57:
F_9 ( & V_19 -> V_26 . V_44 ) ;
return V_24 ;
}
void F_151 ( struct V_18 * V_19 )
{
struct V_45 * V_46 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_29 (crtc, &dev->mode_config.crtc_list, head)
if ( V_46 -> V_36 -> V_468 )
V_46 -> V_36 -> V_468 ( V_46 ) ;
F_29 (encoder, &dev->mode_config.encoder_list, head)
if ( V_2 -> V_36 -> V_468 )
V_2 -> V_36 -> V_468 ( V_2 ) ;
F_29 (connector, &dev->mode_config.connector_list, head)
if ( V_10 -> V_36 -> V_468 )
V_10 -> V_36 -> V_468 ( V_10 ) ;
}
int F_152 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_469 * args = V_167 ;
if ( ! V_19 -> V_470 -> V_471 )
return - V_381 ;
return V_19 -> V_470 -> V_471 ( V_169 , V_19 , args ) ;
}
int F_153 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_472 * args = V_167 ;
if ( ! V_19 -> V_470 -> V_473 )
return - V_381 ;
return V_19 -> V_470 -> V_473 ( V_169 , V_19 , args -> V_285 , & args -> V_474 ) ;
}
int F_154 ( struct V_18 * V_19 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_475 * args = V_167 ;
if ( ! V_19 -> V_470 -> V_476 )
return - V_381 ;
return V_19 -> V_470 -> V_476 ( V_169 , V_19 , args -> V_285 ) ;
}
void F_155 ( T_1 V_307 , unsigned int * V_289 ,
int * V_288 )
{
switch ( V_307 ) {
case V_291 :
case V_310 :
* V_289 = 8 ;
* V_288 = 8 ;
break;
case V_292 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
* V_289 = 15 ;
* V_288 = 16 ;
break;
case V_293 :
case V_326 :
* V_289 = 16 ;
* V_288 = 16 ;
break;
case V_294 :
case V_327 :
* V_289 = 24 ;
* V_288 = 24 ;
break;
case V_295 :
case V_328 :
case V_329 :
case V_330 :
* V_289 = 24 ;
* V_288 = 32 ;
break;
case V_296 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
* V_289 = 30 ;
* V_288 = 32 ;
break;
case V_297 :
case V_331 :
case V_332 :
case V_333 :
* V_289 = 32 ;
* V_288 = 32 ;
break;
default:
F_48 ( L_64 ) ;
* V_289 = 0 ;
* V_288 = 0 ;
break;
}
}
int F_105 ( T_1 V_307 )
{
switch ( V_307 ) {
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
return 3 ;
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
return 2 ;
default:
return 1 ;
}
}
int F_106 ( T_1 V_307 , int V_48 )
{
unsigned int V_289 ;
int V_288 ;
if ( V_48 >= F_105 ( V_307 ) )
return 0 ;
switch ( V_307 ) {
case V_341 :
case V_342 :
case V_343 :
case V_344 :
return 2 ;
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
return V_48 ? 2 : 1 ;
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
return 1 ;
default:
F_155 ( V_307 , & V_289 , & V_288 ) ;
return V_288 >> 3 ;
}
}
int F_103 ( T_1 V_307 )
{
switch ( V_307 ) {
case V_354 :
case V_355 :
case V_352 :
case V_353 :
return 4 ;
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_358 :
case V_359 :
case V_356 :
case V_357 :
return 2 ;
default:
return 1 ;
}
}
int F_104 ( T_1 V_307 )
{
switch ( V_307 ) {
case V_352 :
case V_353 :
return 4 ;
case V_356 :
case V_357 :
case V_346 :
case V_347 :
return 2 ;
default:
return 1 ;
}
}
