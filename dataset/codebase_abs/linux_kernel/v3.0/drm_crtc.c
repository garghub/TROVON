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
if ( V_24 ) {
return V_24 ;
}
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
struct V_43 V_44 ;
int V_24 ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_42 -> V_34 == V_34 ) {
memset ( & V_44 , 0 , sizeof( struct V_43 ) ) ;
V_44 . V_42 = V_42 ;
V_44 . V_34 = NULL ;
V_24 = V_42 -> V_36 -> V_45 ( & V_44 ) ;
if ( V_24 )
F_6 ( L_6 , V_42 ) ;
}
}
F_10 ( V_19 , & V_34 -> V_7 ) ;
F_18 ( & V_34 -> V_39 ) ;
V_19 -> V_26 . V_38 -- ;
}
void F_19 ( struct V_18 * V_19 , struct V_41 * V_42 ,
const struct V_46 * V_36 )
{
V_42 -> V_19 = V_19 ;
V_42 -> V_36 = V_36 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_4 ( V_19 , & V_42 -> V_7 , V_48 ) ;
F_20 ( & V_42 -> V_39 , & V_19 -> V_26 . V_49 ) ;
V_19 -> V_26 . V_50 ++ ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
void F_21 ( struct V_41 * V_42 )
{
struct V_18 * V_19 = V_42 -> V_19 ;
if ( V_42 -> V_51 ) {
F_22 ( V_42 -> V_51 ) ;
V_42 -> V_51 = NULL ;
}
F_10 ( V_19 , & V_42 -> V_7 ) ;
F_18 ( & V_42 -> V_39 ) ;
V_19 -> V_26 . V_50 -- ;
}
void F_23 ( struct V_9 * V_10 ,
struct V_52 * V_53 )
{
F_15 ( & V_53 -> V_39 , & V_10 -> V_54 ) ;
}
void F_24 ( struct V_9 * V_10 ,
struct V_52 * V_53 )
{
F_18 ( & V_53 -> V_39 ) ;
F_22 ( V_53 ) ;
}
void F_25 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
const struct V_55 * V_36 ,
int V_12 )
{
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_10 -> V_19 = V_19 ;
V_10 -> V_36 = V_36 ;
F_4 ( V_19 , & V_10 -> V_7 , V_56 ) ;
V_10 -> V_12 = V_12 ;
V_10 -> V_13 =
++ V_11 [ V_12 ] . V_57 ;
F_26 ( & V_10 -> V_58 ) ;
F_26 ( & V_10 -> V_54 ) ;
F_26 ( & V_10 -> V_59 ) ;
V_10 -> V_60 = NULL ;
F_20 ( & V_10 -> V_39 , & V_19 -> V_26 . V_61 ) ;
V_19 -> V_26 . V_62 ++ ;
F_27 ( V_10 ,
V_19 -> V_26 . V_63 , 0 ) ;
F_27 ( V_10 ,
V_19 -> V_26 . V_64 , 0 ) ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
void F_28 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
struct V_52 * V_53 , * V_65 ;
F_29 (mode, t, &connector->probed_modes, head)
F_24 ( V_10 , V_53 ) ;
F_29 (mode, t, &connector->modes, head)
F_24 ( V_10 , V_53 ) ;
F_29 (mode, t, &connector->user_modes, head)
F_24 ( V_10 , V_53 ) ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_10 ( V_19 , & V_10 -> V_7 ) ;
F_18 ( & V_10 -> V_39 ) ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
void F_30 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
const struct V_66 * V_36 ,
int V_5 )
{
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_2 -> V_19 = V_19 ;
F_4 ( V_19 , & V_2 -> V_7 , V_67 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_36 = V_36 ;
F_20 ( & V_2 -> V_39 , & V_19 -> V_26 . V_68 ) ;
V_19 -> V_26 . V_69 ++ ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_10 ( V_19 , & V_2 -> V_7 ) ;
F_18 ( & V_2 -> V_39 ) ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
struct V_52 * F_32 ( struct V_18 * V_19 )
{
struct V_52 * V_70 ;
V_70 = F_33 ( sizeof( struct V_52 ) , V_28 ) ;
if ( ! V_70 )
return NULL ;
F_4 ( V_19 , & V_70 -> V_7 , V_71 ) ;
return V_70 ;
}
void F_34 ( struct V_18 * V_19 , struct V_52 * V_53 )
{
F_10 ( V_19 , & V_53 -> V_7 ) ;
F_22 ( V_53 ) ;
}
static int F_35 ( struct V_18 * V_19 )
{
struct V_72 * V_73 ;
struct V_72 * V_74 ;
int V_75 ;
V_73 = F_36 ( V_19 , V_76 |
V_77 ,
L_7 , 0 ) ;
V_19 -> V_26 . V_63 = V_73 ;
V_74 = F_36 ( V_19 , V_78 ,
L_8 , F_37 ( V_79 ) ) ;
for ( V_75 = 0 ; V_75 < F_37 ( V_79 ) ; V_75 ++ )
F_38 ( V_74 , V_75 , V_79 [ V_75 ] . type ,
V_79 [ V_75 ] . V_6 ) ;
V_19 -> V_26 . V_64 = V_74 ;
return 0 ;
}
int F_39 ( struct V_18 * V_19 )
{
struct V_72 * V_80 ;
struct V_72 * V_81 ;
int V_75 ;
if ( V_19 -> V_26 . V_82 )
return 0 ;
V_80 =
F_36 ( V_19 , V_78 ,
L_9 ,
F_37 ( V_83 ) ) ;
for ( V_75 = 0 ; V_75 < F_37 ( V_83 ) ; V_75 ++ )
F_38 ( V_80 , V_75 ,
V_83 [ V_75 ] . type ,
V_83 [ V_75 ] . V_6 ) ;
V_19 -> V_26 . V_82 = V_80 ;
V_81 =
F_36 ( V_19 , V_78 |
V_77 ,
L_10 ,
F_37 ( V_84 ) ) ;
for ( V_75 = 0 ; V_75 < F_37 ( V_84 ) ; V_75 ++ )
F_38 ( V_81 , V_75 ,
V_84 [ V_75 ] . type ,
V_84 [ V_75 ] . V_6 ) ;
V_19 -> V_26 . V_85 = V_81 ;
return 0 ;
}
int F_40 ( struct V_18 * V_19 , int V_86 ,
char * V_59 [] )
{
struct V_72 * V_87 ;
struct V_72 * V_88 ;
int V_75 ;
if ( V_19 -> V_26 . V_89 )
return 0 ;
V_87 = F_36 ( V_19 , V_78 ,
L_9 ,
F_37 ( V_90 ) ) ;
for ( V_75 = 0 ; V_75 < F_37 ( V_90 ) ; V_75 ++ )
F_38 ( V_87 , V_75 ,
V_90 [ V_75 ] . type ,
V_90 [ V_75 ] . V_6 ) ;
V_19 -> V_26 . V_89 = V_87 ;
V_88 =
F_36 ( V_19 , V_78 |
V_77 , L_10 ,
F_37 ( V_91 ) ) ;
for ( V_75 = 0 ; V_75 < F_37 ( V_91 ) ; V_75 ++ )
F_38 ( V_88 , V_75 ,
V_91 [ V_75 ] . type ,
V_91 [ V_75 ] . V_6 ) ;
V_19 -> V_26 . V_92 = V_88 ;
V_19 -> V_26 . V_93 =
F_36 ( V_19 , V_94 ,
L_11 , 2 ) ;
V_19 -> V_26 . V_93 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_93 -> V_95 [ 1 ] = 100 ;
V_19 -> V_26 . V_96 =
F_36 ( V_19 , V_94 ,
L_12 , 2 ) ;
V_19 -> V_26 . V_96 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_96 -> V_95 [ 1 ] = 100 ;
V_19 -> V_26 . V_97 =
F_36 ( V_19 , V_94 ,
L_13 , 2 ) ;
V_19 -> V_26 . V_97 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_97 -> V_95 [ 1 ] = 100 ;
V_19 -> V_26 . V_98 =
F_36 ( V_19 , V_94 ,
L_14 , 2 ) ;
V_19 -> V_26 . V_98 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_98 -> V_95 [ 1 ] = 100 ;
V_19 -> V_26 . V_99 =
F_36 ( V_19 , V_78 ,
L_15 , V_86 ) ;
for ( V_75 = 0 ; V_75 < V_86 ; V_75 ++ )
F_38 ( V_19 -> V_26 . V_99 , V_75 ,
V_75 , V_59 [ V_75 ] ) ;
V_19 -> V_26 . V_100 =
F_36 ( V_19 , V_94 ,
L_16 , 2 ) ;
V_19 -> V_26 . V_100 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_100 -> V_95 [ 1 ] = 100 ;
V_19 -> V_26 . V_101 =
F_36 ( V_19 , V_94 ,
L_17 , 2 ) ;
V_19 -> V_26 . V_101 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_101 -> V_95 [ 1 ] = 100 ;
V_19 -> V_26 . V_102 =
F_36 ( V_19 , V_94 ,
L_18 , 2 ) ;
V_19 -> V_26 . V_102 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_102 -> V_95 [ 1 ] = 100 ;
V_19 -> V_26 . V_103 =
F_36 ( V_19 , V_94 ,
L_19 , 2 ) ;
V_19 -> V_26 . V_103 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_103 -> V_95 [ 1 ] = 100 ;
V_19 -> V_26 . V_104 =
F_36 ( V_19 , V_94 ,
L_20 , 2 ) ;
V_19 -> V_26 . V_104 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_104 -> V_95 [ 1 ] = 100 ;
V_19 -> V_26 . V_105 =
F_36 ( V_19 , V_94 ,
L_21 , 2 ) ;
V_19 -> V_26 . V_105 -> V_95 [ 0 ] = 0 ;
V_19 -> V_26 . V_105 -> V_95 [ 1 ] = 100 ;
return 0 ;
}
int F_41 ( struct V_18 * V_19 )
{
struct V_72 * V_106 ;
int V_75 ;
if ( V_19 -> V_26 . V_107 )
return 0 ;
V_106 =
F_36 ( V_19 , V_78 , L_22 ,
F_37 ( V_108 ) ) ;
for ( V_75 = 0 ; V_75 < F_37 ( V_108 ) ; V_75 ++ )
F_38 ( V_106 , V_75 ,
V_108 [ V_75 ] . type ,
V_108 [ V_75 ] . V_6 ) ;
V_19 -> V_26 . V_107 = V_106 ;
return 0 ;
}
int F_42 ( struct V_18 * V_19 )
{
struct V_72 * V_109 ;
int V_75 ;
if ( V_19 -> V_26 . V_110 )
return 0 ;
V_109 =
F_36 ( V_19 , V_78 , L_23 ,
F_37 ( V_111 ) ) ;
for ( V_75 = 0 ; V_75 < F_37 ( V_111 ) ; V_75 ++ )
F_38 ( V_109 , V_75 ,
V_111 [ V_75 ] . type ,
V_111 [ V_75 ] . V_6 ) ;
V_19 -> V_26 . V_110 = V_109 ;
return 0 ;
}
int F_43 ( struct V_18 * V_19 )
{
struct V_72 * V_112 ;
int V_75 ;
if ( V_19 -> V_26 . V_113 )
return 0 ;
V_112 =
F_36 ( V_19 , V_78 |
V_77 ,
L_24 ,
F_37 ( V_114 ) ) ;
for ( V_75 = 0 ; V_75 < F_37 ( V_114 ) ; V_75 ++ )
F_38 ( V_112 , V_75 ,
V_114 [ V_75 ] . type ,
V_114 [ V_75 ] . V_6 ) ;
V_19 -> V_26 . V_113 = V_112 ;
return 0 ;
}
void F_44 ( struct V_18 * V_19 )
{
F_45 ( & V_19 -> V_26 . V_47 ) ;
F_45 ( & V_19 -> V_26 . V_30 ) ;
F_26 ( & V_19 -> V_26 . V_40 ) ;
F_26 ( & V_19 -> V_26 . V_49 ) ;
F_26 ( & V_19 -> V_26 . V_61 ) ;
F_26 ( & V_19 -> V_26 . V_68 ) ;
F_26 ( & V_19 -> V_26 . V_115 ) ;
F_26 ( & V_19 -> V_26 . V_116 ) ;
F_46 ( & V_19 -> V_26 . V_27 ) ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_35 ( V_19 ) ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
V_19 -> V_26 . V_38 = 0 ;
V_19 -> V_26 . V_62 = 0 ;
V_19 -> V_26 . V_50 = 0 ;
V_19 -> V_26 . V_69 = 0 ;
}
int F_47 ( struct V_18 * V_19 , struct V_117 * V_118 )
{
T_1 V_119 = 0 ;
V_119 += V_19 -> V_26 . V_50 ;
V_119 += V_19 -> V_26 . V_62 ;
V_119 += V_19 -> V_26 . V_69 ;
V_118 -> V_120 = F_33 ( V_119 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_118 -> V_120 )
return - V_121 ;
V_118 -> V_122 = 0 ;
V_118 -> V_123 = 0 ;
V_118 -> V_124 = 0 ;
return 0 ;
}
int F_48 ( struct V_18 * V_19 ,
struct V_117 * V_118 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_24 ;
if ( ( V_24 = F_47 ( V_19 , V_118 ) ) )
return V_24 ;
F_17 (crtc, &dev->mode_config.crtc_list, head)
V_118 -> V_120 [ V_118 -> V_122 ++ ] = V_42 -> V_7 . V_8 ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
V_118 -> V_120 [ V_118 -> V_122 + V_118 -> V_124 ++ ] =
V_2 -> V_7 . V_8 ;
F_17 (connector, &dev->mode_config.connector_list, head)
V_118 -> V_120 [ V_118 -> V_122 + V_118 -> V_124 +
V_118 -> V_123 ++ ] = V_10 -> V_7 . V_8 ;
return 0 ;
}
void F_49 ( struct V_18 * V_19 )
{
struct V_9 * V_10 , * V_125 ;
struct V_41 * V_42 , * V_126 ;
struct V_1 * V_2 , * V_127 ;
struct V_33 * V_34 , * V_128 ;
struct V_72 * V_129 , * V_130 ;
F_29 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_2 -> V_36 -> V_131 ( V_2 ) ;
}
F_29 (connector, ot,
&dev->mode_config.connector_list, head) {
V_10 -> V_36 -> V_131 ( V_10 ) ;
}
F_29 (property, pt, &dev->mode_config.property_list,
head) {
F_50 ( V_19 , V_129 ) ;
}
F_29 (fb, fbt, &dev->mode_config.fb_list, head) {
V_34 -> V_36 -> V_131 ( V_34 ) ;
}
F_29 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_42 -> V_36 -> V_131 ( V_42 ) ;
}
}
void F_51 ( struct V_132 * V_133 ,
struct V_52 * V_134 )
{
V_133 -> clock = V_134 -> clock ;
V_133 -> V_135 = V_134 -> V_135 ;
V_133 -> V_136 = V_134 -> V_136 ;
V_133 -> V_137 = V_134 -> V_137 ;
V_133 -> V_138 = V_134 -> V_138 ;
V_133 -> V_139 = V_134 -> V_139 ;
V_133 -> V_140 = V_134 -> V_140 ;
V_133 -> V_141 = V_134 -> V_141 ;
V_133 -> V_142 = V_134 -> V_142 ;
V_133 -> V_143 = V_134 -> V_143 ;
V_133 -> V_144 = V_134 -> V_144 ;
V_133 -> V_145 = V_134 -> V_145 ;
V_133 -> V_146 = V_134 -> V_146 ;
V_133 -> type = V_134 -> type ;
strncpy ( V_133 -> V_6 , V_134 -> V_6 , V_147 ) ;
V_133 -> V_6 [ V_147 - 1 ] = 0 ;
}
void F_52 ( struct V_52 * V_133 ,
struct V_132 * V_134 )
{
V_133 -> clock = V_134 -> clock ;
V_133 -> V_135 = V_134 -> V_135 ;
V_133 -> V_136 = V_134 -> V_136 ;
V_133 -> V_137 = V_134 -> V_137 ;
V_133 -> V_138 = V_134 -> V_138 ;
V_133 -> V_139 = V_134 -> V_139 ;
V_133 -> V_140 = V_134 -> V_140 ;
V_133 -> V_141 = V_134 -> V_141 ;
V_133 -> V_142 = V_134 -> V_142 ;
V_133 -> V_143 = V_134 -> V_143 ;
V_133 -> V_144 = V_134 -> V_144 ;
V_133 -> V_145 = V_134 -> V_145 ;
V_133 -> V_146 = V_134 -> V_146 ;
V_133 -> type = V_134 -> type ;
strncpy ( V_133 -> V_6 , V_134 -> V_6 , V_147 ) ;
V_133 -> V_6 [ V_147 - 1 ] = 0 ;
}
int F_53 ( struct V_18 * V_19 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_151 * V_152 = V_148 ;
struct V_153 * V_154 ;
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
int V_155 = 0 ;
int V_156 = 0 ;
int V_157 = 0 ;
int V_158 = 0 ;
int V_159 = 0 , V_75 ;
T_1 T_2 * V_160 ;
T_1 T_2 * V_161 ;
T_1 T_2 * V_162 ;
T_1 T_2 * V_163 ;
struct V_117 * V_164 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_55 (lh, &file_priv->fbs)
V_157 ++ ;
V_164 = & V_150 -> V_166 -> V_167 -> V_164 ;
if ( V_150 -> V_166 -> V_167 -> type == V_168 ) {
F_55 (lh, &dev->mode_config.crtc_list)
V_156 ++ ;
F_55 (lh, &dev->mode_config.connector_list)
V_155 ++ ;
F_55 (lh, &dev->mode_config.encoder_list)
V_158 ++ ;
} else {
V_156 = V_164 -> V_122 ;
V_155 = V_164 -> V_123 ;
V_158 = V_164 -> V_124 ;
}
V_152 -> V_169 = V_19 -> V_26 . V_169 ;
V_152 -> V_170 = V_19 -> V_26 . V_170 ;
V_152 -> V_171 = V_19 -> V_26 . V_171 ;
V_152 -> V_172 = V_19 -> V_26 . V_172 ;
if ( V_152 -> V_173 >= V_157 ) {
V_159 = 0 ;
V_160 = ( T_1 T_2 * ) ( unsigned long ) V_152 -> V_174 ;
F_17 (fb, &file_priv->fbs, filp_head) {
if ( F_56 ( V_34 -> V_7 . V_8 , V_160 + V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
}
V_152 -> V_173 = V_157 ;
if ( V_152 -> V_176 >= V_156 ) {
V_159 = 0 ;
V_161 = ( T_1 T_2 * ) ( unsigned long ) V_152 -> V_177 ;
if ( V_150 -> V_166 -> V_167 -> type == V_168 ) {
F_17 (crtc, &dev->mode_config.crtc_list,
head) {
F_57 ( L_25 , V_42 -> V_7 . V_8 ) ;
if ( F_56 ( V_42 -> V_7 . V_8 , V_161 + V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
} else {
for ( V_75 = 0 ; V_75 < V_164 -> V_122 ; V_75 ++ ) {
if ( F_56 ( V_164 -> V_120 [ V_75 ] ,
V_161 + V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
}
}
V_152 -> V_176 = V_156 ;
if ( V_152 -> V_178 >= V_158 ) {
V_159 = 0 ;
V_163 = ( T_1 T_2 * ) ( unsigned long ) V_152 -> V_179 ;
if ( V_150 -> V_166 -> V_167 -> type == V_168 ) {
F_17 (encoder,
&dev->mode_config.encoder_list,
head) {
F_57 ( L_26 , V_2 -> V_7 . V_8 ,
F_1 ( V_2 ) ) ;
if ( F_56 ( V_2 -> V_7 . V_8 , V_163 +
V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
} else {
for ( V_75 = V_164 -> V_122 ; V_75 < V_164 -> V_122 + V_164 -> V_124 ; V_75 ++ ) {
if ( F_56 ( V_164 -> V_120 [ V_75 ] ,
V_163 + V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
}
}
V_152 -> V_178 = V_158 ;
if ( V_152 -> V_180 >= V_155 ) {
V_159 = 0 ;
V_162 = ( T_1 T_2 * ) ( unsigned long ) V_152 -> V_181 ;
if ( V_150 -> V_166 -> V_167 -> type == V_168 ) {
F_17 (connector,
&dev->mode_config.connector_list,
head) {
F_57 ( L_27 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
if ( F_56 ( V_10 -> V_7 . V_8 ,
V_162 + V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
} else {
int V_182 = V_164 -> V_122 +
V_164 -> V_124 ;
for ( V_75 = V_182 ; V_75 < V_182 + V_164 -> V_123 ; V_75 ++ ) {
if ( F_56 ( V_164 -> V_120 [ V_75 ] ,
V_162 + V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
}
}
V_152 -> V_180 = V_155 ;
F_57 ( L_28 , V_152 -> V_176 ,
V_152 -> V_180 , V_152 -> V_178 ) ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_58 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_183 * V_184 = V_148 ;
struct V_41 * V_42 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_184 -> V_161 ,
V_48 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_133;
}
V_42 = F_59 ( V_21 ) ;
V_184 -> V_185 = V_42 -> V_185 ;
V_184 -> V_186 = V_42 -> V_186 ;
V_184 -> V_187 = V_42 -> V_187 ;
if ( V_42 -> V_34 )
V_184 -> V_160 = V_42 -> V_34 -> V_7 . V_8 ;
else
V_184 -> V_160 = 0 ;
if ( V_42 -> V_188 ) {
F_51 ( & V_184 -> V_53 , & V_42 -> V_53 ) ;
V_184 -> V_189 = 1 ;
} else {
V_184 -> V_189 = 0 ;
}
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_60 ( struct V_18 * V_19 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_190 * V_191 = V_148 ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
struct V_52 * V_53 ;
int V_192 = 0 ;
int V_193 = 0 ;
int V_194 = 0 ;
int V_24 = 0 ;
int V_159 = 0 ;
int V_75 ;
struct V_132 V_195 ;
struct V_132 T_2 * V_196 ;
T_1 T_2 * V_197 ;
T_3 T_2 * V_198 ;
T_1 T_2 * V_199 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
memset ( & V_195 , 0 , sizeof( struct V_132 ) ) ;
F_57 ( L_29 , V_191 -> V_162 ) ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_191 -> V_162 ,
V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_133;
}
V_10 = F_61 ( V_21 ) ;
for ( V_75 = 0 ; V_75 < V_200 ; V_75 ++ ) {
if ( V_10 -> V_201 [ V_75 ] != 0 ) {
V_193 ++ ;
}
}
for ( V_75 = 0 ; V_75 < V_202 ; V_75 ++ ) {
if ( V_10 -> V_203 [ V_75 ] != 0 ) {
V_194 ++ ;
}
}
if ( V_191 -> V_204 == 0 ) {
V_10 -> V_36 -> V_205 ( V_10 ,
V_19 -> V_26 . V_171 ,
V_19 -> V_26 . V_169 ) ;
}
F_17 (mode, &connector->modes, head)
V_192 ++ ;
V_191 -> V_162 = V_10 -> V_7 . V_8 ;
V_191 -> V_12 = V_10 -> V_12 ;
V_191 -> V_13 = V_10 -> V_13 ;
V_191 -> V_206 = V_10 -> V_207 . V_208 ;
V_191 -> V_209 = V_10 -> V_207 . V_210 ;
V_191 -> V_211 = V_10 -> V_207 . V_212 ;
V_191 -> V_213 = V_10 -> V_15 ;
if ( V_10 -> V_2 )
V_191 -> V_163 = V_10 -> V_2 -> V_7 . V_8 ;
else
V_191 -> V_163 = 0 ;
if ( ( V_191 -> V_204 >= V_192 ) && V_192 ) {
V_159 = 0 ;
V_196 = (struct V_132 * ) ( unsigned long ) V_191 -> V_214 ;
F_17 (mode, &connector->modes, head) {
F_51 ( & V_195 , V_53 ) ;
if ( F_62 ( V_196 + V_159 ,
& V_195 , sizeof( V_195 ) ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
}
V_191 -> V_204 = V_192 ;
if ( ( V_191 -> V_215 >= V_193 ) && V_193 ) {
V_159 = 0 ;
V_197 = ( T_1 * ) ( unsigned long ) ( V_191 -> V_216 ) ;
V_198 = ( T_3 * ) ( unsigned long ) ( V_191 -> V_217 ) ;
for ( V_75 = 0 ; V_75 < V_200 ; V_75 ++ ) {
if ( V_10 -> V_201 [ V_75 ] != 0 ) {
if ( F_56 ( V_10 -> V_201 [ V_75 ] ,
V_197 + V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
if ( F_56 ( V_10 -> V_218 [ V_75 ] ,
V_198 + V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
}
}
V_191 -> V_215 = V_193 ;
if ( ( V_191 -> V_178 >= V_194 ) && V_194 ) {
V_159 = 0 ;
V_199 = ( T_1 * ) ( unsigned long ) ( V_191 -> V_219 ) ;
for ( V_75 = 0 ; V_75 < V_202 ; V_75 ++ ) {
if ( V_10 -> V_203 [ V_75 ] != 0 ) {
if ( F_56 ( V_10 -> V_203 [ V_75 ] ,
V_199 + V_159 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_159 ++ ;
}
}
}
V_191 -> V_178 = V_194 ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_63 ( struct V_18 * V_19 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_220 * V_221 = V_148 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_221 -> V_163 ,
V_67 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_133;
}
V_2 = F_64 ( V_21 ) ;
if ( V_2 -> V_42 )
V_221 -> V_161 = V_2 -> V_42 -> V_7 . V_8 ;
else
V_221 -> V_161 = 0 ;
V_221 -> V_5 = V_2 -> V_5 ;
V_221 -> V_163 = V_2 -> V_7 . V_8 ;
V_221 -> V_222 = V_2 -> V_222 ;
V_221 -> V_223 = V_2 -> V_223 ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_65 ( struct V_18 * V_19 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_224 * V_225 = & V_19 -> V_26 ;
struct V_183 * V_226 = V_148 ;
struct V_20 * V_21 ;
struct V_41 * V_42 , * V_227 ;
struct V_9 * * V_228 = NULL , * V_10 ;
struct V_33 * V_34 = NULL ;
struct V_52 * V_53 = NULL ;
struct V_43 V_44 ;
T_1 T_2 * V_229 ;
int V_24 = 0 ;
int V_75 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_226 -> V_161 ,
V_48 ) ;
if ( ! V_21 ) {
F_57 ( L_30 , V_226 -> V_161 ) ;
V_24 = - V_29 ;
goto V_133;
}
V_42 = F_59 ( V_21 ) ;
F_57 ( L_25 , V_42 -> V_7 . V_8 ) ;
if ( V_226 -> V_189 ) {
if ( V_226 -> V_160 == - 1 ) {
F_17 (crtcfb,
&dev->mode_config.crtc_list, head) {
if ( V_227 == V_42 ) {
F_57 ( L_31
L_32 ) ;
V_34 = V_42 -> V_34 ;
}
}
} else {
V_21 = F_12 ( V_19 , V_226 -> V_160 ,
V_37 ) ;
if ( ! V_21 ) {
F_57 ( L_33 ,
V_226 -> V_160 ) ;
V_24 = - V_29 ;
goto V_133;
}
V_34 = F_66 ( V_21 ) ;
}
V_53 = F_32 ( V_19 ) ;
F_52 ( V_53 , & V_226 -> V_53 ) ;
F_67 ( V_53 , V_230 ) ;
}
if ( V_226 -> V_180 == 0 && V_53 ) {
F_57 ( L_34 ) ;
V_24 = - V_29 ;
goto V_133;
}
if ( V_226 -> V_180 > 0 && ( ! V_53 || ! V_34 ) ) {
F_57 ( L_35 ,
V_226 -> V_180 ) ;
V_24 = - V_29 ;
goto V_133;
}
if ( V_226 -> V_180 > 0 ) {
T_4 V_231 ;
if ( V_226 -> V_180 > V_225 -> V_62 ) {
V_24 = - V_29 ;
goto V_133;
}
V_228 = F_68 ( V_226 -> V_180 *
sizeof( struct V_9 * ) ,
V_28 ) ;
if ( ! V_228 ) {
V_24 = - V_121 ;
goto V_133;
}
for ( V_75 = 0 ; V_75 < V_226 -> V_180 ; V_75 ++ ) {
V_229 = ( T_1 * ) ( unsigned long ) V_226 -> V_229 ;
if ( F_69 ( V_231 , & V_229 [ V_75 ] ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_21 = F_12 ( V_19 , V_231 ,
V_56 ) ;
if ( ! V_21 ) {
F_57 ( L_36 ,
V_231 ) ;
V_24 = - V_29 ;
goto V_133;
}
V_10 = F_61 ( V_21 ) ;
F_57 ( L_27 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
V_228 [ V_75 ] = V_10 ;
}
}
V_44 . V_42 = V_42 ;
V_44 . V_185 = V_226 -> V_185 ;
V_44 . V_186 = V_226 -> V_186 ;
V_44 . V_53 = V_53 ;
V_44 . V_232 = V_228 ;
V_44 . V_123 = V_226 -> V_180 ;
V_44 . V_34 = V_34 ;
V_24 = V_42 -> V_36 -> V_45 ( & V_44 ) ;
V_133:
F_22 ( V_228 ) ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_70 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_233 * V_234 = V_148 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
if ( ! V_234 -> V_146 ) {
F_6 ( L_37 ) ;
return - V_29 ;
}
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_234 -> V_161 , V_48 ) ;
if ( ! V_21 ) {
F_57 ( L_30 , V_234 -> V_161 ) ;
V_24 = - V_29 ;
goto V_133;
}
V_42 = F_59 ( V_21 ) ;
if ( V_234 -> V_146 & V_235 ) {
if ( ! V_42 -> V_36 -> V_236 ) {
F_6 ( L_38 ) ;
V_24 = - V_237 ;
goto V_133;
}
V_24 = V_42 -> V_36 -> V_236 ( V_42 , V_150 , V_234 -> V_238 ,
V_234 -> V_239 , V_234 -> V_240 ) ;
}
if ( V_234 -> V_146 & V_241 ) {
if ( V_42 -> V_36 -> V_242 ) {
V_24 = V_42 -> V_36 -> V_242 ( V_42 , V_234 -> V_185 , V_234 -> V_186 ) ;
} else {
F_6 ( L_38 ) ;
V_24 = - V_175 ;
goto V_133;
}
}
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_71 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_243 * V_244 = V_148 ;
struct V_224 * V_225 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
if ( ( V_225 -> V_172 > V_244 -> V_239 ) || ( V_244 -> V_239 > V_225 -> V_171 ) ) {
F_6 ( L_39 ) ;
return - V_29 ;
}
if ( ( V_225 -> V_170 > V_244 -> V_240 ) || ( V_244 -> V_240 > V_225 -> V_169 ) ) {
F_6 ( L_40 ) ;
return - V_29 ;
}
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_245 ( V_19 , V_150 , V_244 ) ;
if ( F_72 ( V_34 ) ) {
F_6 ( L_41 ) ;
V_24 = F_73 ( V_34 ) ;
goto V_133;
}
V_244 -> V_160 = V_34 -> V_7 . V_8 ;
F_15 ( & V_34 -> V_246 , & V_150 -> V_247 ) ;
F_57 ( L_42 , V_34 -> V_7 . V_8 ) ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_74 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_20 * V_21 ;
struct V_33 * V_34 = NULL ;
struct V_33 * V_248 = NULL ;
T_1 * V_8 = V_148 ;
int V_24 = 0 ;
int V_249 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , * V_8 , V_37 ) ;
if ( ! V_21 ) {
F_6 ( L_43 ) ;
V_24 = - V_29 ;
goto V_133;
}
V_34 = F_66 ( V_21 ) ;
F_17 (fbl, &file_priv->fbs, filp_head)
if ( V_34 == V_248 )
V_249 = 1 ;
if ( ! V_249 ) {
F_6 ( L_44 ) ;
V_24 = - V_29 ;
goto V_133;
}
F_18 ( & V_34 -> V_246 ) ;
V_34 -> V_36 -> V_131 ( V_34 ) ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_75 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_243 * V_244 = V_148 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_244 -> V_160 , V_37 ) ;
if ( ! V_21 ) {
F_6 ( L_45 ) ;
V_24 = - V_29 ;
goto V_133;
}
V_34 = F_66 ( V_21 ) ;
V_244 -> V_240 = V_34 -> V_240 ;
V_244 -> V_239 = V_34 -> V_239 ;
V_244 -> V_250 = V_34 -> V_250 ;
V_244 -> V_251 = V_34 -> V_252 ;
V_244 -> V_253 = V_34 -> V_253 ;
V_34 -> V_36 -> V_254 ( V_34 , V_150 , & V_244 -> V_238 ) ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_76 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_255 T_2 * V_256 ;
struct V_255 * V_257 = NULL ;
struct V_258 * V_244 = V_148 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
unsigned V_146 ;
int V_259 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_244 -> V_160 , V_37 ) ;
if ( ! V_21 ) {
F_6 ( L_45 ) ;
V_24 = - V_29 ;
goto V_260;
}
V_34 = F_66 ( V_21 ) ;
V_259 = V_244 -> V_259 ;
V_256 = (struct V_255 * ) ( unsigned long ) V_244 -> V_256 ;
if ( ! V_259 != ! V_256 ) {
V_24 = - V_29 ;
goto V_260;
}
V_146 = V_261 & V_244 -> V_146 ;
if ( V_146 & V_262 && ( V_259 % 2 ) ) {
V_24 = - V_29 ;
goto V_260;
}
if ( V_259 && V_256 ) {
V_257 = F_33 ( V_259 * sizeof( * V_257 ) , V_28 ) ;
if ( ! V_257 ) {
V_24 = - V_121 ;
goto V_260;
}
V_24 = F_77 ( V_257 , V_256 ,
V_259 * sizeof( * V_257 ) ) ;
if ( V_24 ) {
V_24 = - V_175 ;
goto V_263;
}
}
if ( V_34 -> V_36 -> V_264 ) {
V_24 = V_34 -> V_36 -> V_264 ( V_34 , V_150 , V_146 , V_244 -> V_265 ,
V_257 , V_259 ) ;
} else {
V_24 = - V_266 ;
goto V_263;
}
V_263:
F_22 ( V_257 ) ;
V_260:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
void F_78 ( struct V_149 * V_267 )
{
struct V_18 * V_19 = V_267 -> V_167 -> V_19 ;
struct V_33 * V_34 , * V_268 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_29 (fb, tfb, &priv->fbs, filp_head) {
F_18 ( & V_34 -> V_246 ) ;
V_34 -> V_36 -> V_131 ( V_34 ) ;
}
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
static int F_79 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_52 * V_53 )
{
int V_24 = 0 ;
F_20 ( & V_53 -> V_39 , & V_10 -> V_58 ) ;
return V_24 ;
}
int F_80 ( struct V_18 * V_19 , struct V_41 * V_42 ,
struct V_52 * V_53 )
{
struct V_9 * V_10 ;
int V_24 = 0 ;
struct V_52 * V_269 ;
int V_270 = 0 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
break;
if ( V_10 -> V_2 -> V_42 == V_42 ) {
if ( V_270 )
V_269 = F_81 ( V_19 , V_53 ) ;
else
V_269 = V_53 ;
V_24 = F_79 ( V_19 , V_10 , V_269 ) ;
if ( V_24 )
return V_24 ;
V_270 = 1 ;
}
}
return 0 ;
}
static int F_82 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_52 * V_53 )
{
int V_249 = 0 ;
int V_24 = 0 ;
struct V_52 * V_271 , * V_65 ;
F_29 (match_mode, t, &connector->user_modes, head) {
if ( F_83 ( V_271 , V_53 ) ) {
F_18 ( & V_271 -> V_39 ) ;
F_34 ( V_19 , V_271 ) ;
V_249 = 1 ;
break;
}
}
if ( ! V_249 )
V_24 = - V_29 ;
return V_24 ;
}
int F_84 ( struct V_18 * V_19 , struct V_52 * V_53 )
{
struct V_9 * V_10 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
F_82 ( V_19 , V_10 , V_53 ) ;
}
return 0 ;
}
int F_85 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_272 * V_273 = V_148 ;
struct V_9 * V_10 ;
struct V_52 * V_53 ;
struct V_20 * V_21 ;
struct V_132 * V_274 = & V_273 -> V_53 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_273 -> V_162 , V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_133;
}
V_10 = F_61 ( V_21 ) ;
V_53 = F_32 ( V_19 ) ;
if ( ! V_53 ) {
V_24 = - V_121 ;
goto V_133;
}
F_52 ( V_53 , V_274 ) ;
V_24 = F_79 ( V_19 , V_10 , V_53 ) ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_86 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_20 * V_21 ;
struct V_272 * V_273 = V_148 ;
struct V_9 * V_10 ;
struct V_52 V_53 ;
struct V_132 * V_274 = & V_273 -> V_53 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_273 -> V_162 , V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_133;
}
V_10 = F_61 ( V_21 ) ;
F_52 ( & V_53 , V_274 ) ;
V_24 = F_82 ( V_19 , V_10 , & V_53 ) ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
struct V_72 * F_36 ( struct V_18 * V_19 , int V_146 ,
const char * V_6 , int V_275 )
{
struct V_72 * V_129 = NULL ;
V_129 = F_33 ( sizeof( struct V_72 ) , V_28 ) ;
if ( ! V_129 )
return NULL ;
if ( V_275 ) {
V_129 -> V_95 = F_33 ( sizeof( T_3 ) * V_275 , V_28 ) ;
if ( ! V_129 -> V_95 )
goto V_276;
}
F_4 ( V_19 , & V_129 -> V_7 , V_277 ) ;
V_129 -> V_146 = V_146 ;
V_129 -> V_275 = V_275 ;
F_26 ( & V_129 -> V_278 ) ;
if ( V_6 )
strncpy ( V_129 -> V_6 , V_6 , V_279 ) ;
F_20 ( & V_129 -> V_39 , & V_19 -> V_26 . V_115 ) ;
return V_129 ;
V_276:
F_22 ( V_129 ) ;
return NULL ;
}
int F_38 ( struct V_72 * V_129 , int V_280 ,
T_3 V_281 , const char * V_6 )
{
struct V_282 * V_283 ;
if ( ! ( V_129 -> V_146 & V_78 ) )
return - V_29 ;
if ( ! F_87 ( & V_129 -> V_278 ) ) {
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( V_283 -> V_281 == V_281 ) {
strncpy ( V_283 -> V_6 , V_6 , V_279 ) ;
V_283 -> V_6 [ V_279 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_283 = F_33 ( sizeof( struct V_282 ) , V_28 ) ;
if ( ! V_283 )
return - V_121 ;
strncpy ( V_283 -> V_6 , V_6 , V_279 ) ;
V_283 -> V_6 [ V_279 - 1 ] = '\0' ;
V_283 -> V_281 = V_281 ;
V_129 -> V_95 [ V_280 ] = V_281 ;
F_20 ( & V_283 -> V_39 , & V_129 -> V_278 ) ;
return 0 ;
}
void F_50 ( struct V_18 * V_19 , struct V_72 * V_129 )
{
struct V_282 * V_283 , * V_130 ;
F_29 (prop_enum, pt, &property->enum_blob_list, head) {
F_18 ( & V_283 -> V_39 ) ;
F_22 ( V_283 ) ;
}
if ( V_129 -> V_275 )
F_22 ( V_129 -> V_95 ) ;
F_10 ( V_19 , & V_129 -> V_7 ) ;
F_18 ( & V_129 -> V_39 ) ;
F_22 ( V_129 ) ;
}
int F_27 ( struct V_9 * V_10 ,
struct V_72 * V_129 , T_3 V_284 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_200 ; V_75 ++ ) {
if ( V_10 -> V_201 [ V_75 ] == 0 ) {
V_10 -> V_201 [ V_75 ] = V_129 -> V_7 . V_8 ;
V_10 -> V_218 [ V_75 ] = V_284 ;
break;
}
}
if ( V_75 == V_200 )
return - V_29 ;
return 0 ;
}
int F_88 ( struct V_9 * V_10 ,
struct V_72 * V_129 , T_3 V_281 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_200 ; V_75 ++ ) {
if ( V_10 -> V_201 [ V_75 ] == V_129 -> V_7 . V_8 ) {
V_10 -> V_218 [ V_75 ] = V_281 ;
break;
}
}
if ( V_75 == V_200 )
return - V_29 ;
return 0 ;
}
int F_89 ( struct V_9 * V_10 ,
struct V_72 * V_129 , T_3 * V_285 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_200 ; V_75 ++ ) {
if ( V_10 -> V_201 [ V_75 ] == V_129 -> V_7 . V_8 ) {
* V_285 = V_10 -> V_218 [ V_75 ] ;
break;
}
}
if ( V_75 == V_200 )
return - V_29 ;
return 0 ;
}
int F_90 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_20 * V_21 ;
struct V_286 * V_191 = V_148 ;
struct V_72 * V_129 ;
int V_287 = 0 ;
int V_288 = 0 ;
int V_289 = 0 ;
int V_24 = 0 , V_75 ;
int V_159 ;
struct V_282 * V_283 ;
struct V_290 T_2 * V_291 ;
struct V_292 * V_293 ;
T_1 * V_294 ;
T_3 T_2 * V_295 ;
T_1 T_2 * V_296 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_191 -> V_297 , V_277 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_298;
}
V_129 = F_91 ( V_21 ) ;
if ( V_129 -> V_146 & V_78 ) {
F_17 (prop_enum, &property->enum_blob_list, head)
V_287 ++ ;
} else if ( V_129 -> V_146 & V_76 ) {
F_17 (prop_blob, &property->enum_blob_list, head)
V_288 ++ ;
}
V_289 = V_129 -> V_275 ;
strncpy ( V_191 -> V_6 , V_129 -> V_6 , V_279 ) ;
V_191 -> V_6 [ V_279 - 1 ] = 0 ;
V_191 -> V_146 = V_129 -> V_146 ;
if ( ( V_191 -> V_299 >= V_289 ) && V_289 ) {
V_295 = ( T_3 * ) ( unsigned long ) V_191 -> V_295 ;
for ( V_75 = 0 ; V_75 < V_289 ; V_75 ++ ) {
if ( F_62 ( V_295 + V_75 , & V_129 -> V_95 [ V_75 ] , sizeof( T_3 ) ) ) {
V_24 = - V_175 ;
goto V_298;
}
}
}
V_191 -> V_299 = V_289 ;
if ( V_129 -> V_146 & V_78 ) {
if ( ( V_191 -> V_300 >= V_287 ) && V_287 ) {
V_159 = 0 ;
V_291 = (struct V_290 * ) ( unsigned long ) V_191 -> V_301 ;
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( F_62 ( & V_291 [ V_159 ] . V_281 , & V_283 -> V_281 , sizeof( T_3 ) ) ) {
V_24 = - V_175 ;
goto V_298;
}
if ( F_62 ( & V_291 [ V_159 ] . V_6 ,
& V_283 -> V_6 , V_279 ) ) {
V_24 = - V_175 ;
goto V_298;
}
V_159 ++ ;
}
}
V_191 -> V_300 = V_287 ;
}
if ( V_129 -> V_146 & V_76 ) {
if ( ( V_191 -> V_300 >= V_288 ) && V_288 ) {
V_159 = 0 ;
V_294 = ( T_1 * ) ( unsigned long ) V_191 -> V_301 ;
V_296 = ( T_1 * ) ( unsigned long ) V_191 -> V_295 ;
F_17 (prop_blob, &property->enum_blob_list, head) {
if ( F_56 ( V_293 -> V_7 . V_8 , V_294 + V_159 ) ) {
V_24 = - V_175 ;
goto V_298;
}
if ( F_56 ( V_293 -> V_302 , V_296 + V_159 ) ) {
V_24 = - V_175 ;
goto V_298;
}
V_159 ++ ;
}
}
V_191 -> V_300 = V_288 ;
}
V_298:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
static struct V_292 * F_92 ( struct V_18 * V_19 , int V_302 ,
void * V_148 )
{
struct V_292 * V_303 ;
if ( ! V_302 || ! V_148 )
return NULL ;
V_303 = F_33 ( sizeof( struct V_292 ) + V_302 , V_28 ) ;
if ( ! V_303 )
return NULL ;
V_303 -> V_148 = ( void * ) ( ( char * ) V_303 + sizeof( struct V_292 ) ) ;
V_303 -> V_302 = V_302 ;
memcpy ( V_303 -> V_148 , V_148 , V_302 ) ;
F_4 ( V_19 , & V_303 -> V_7 , V_304 ) ;
F_20 ( & V_303 -> V_39 , & V_19 -> V_26 . V_116 ) ;
return V_303 ;
}
static void F_93 ( struct V_18 * V_19 ,
struct V_292 * V_303 )
{
F_10 ( V_19 , & V_303 -> V_7 ) ;
F_18 ( & V_303 -> V_39 ) ;
F_22 ( V_303 ) ;
}
int F_94 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_20 * V_21 ;
struct V_305 * V_191 = V_148 ;
struct V_292 * V_303 ;
int V_24 = 0 ;
void * V_306 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_191 -> V_307 , V_304 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_298;
}
V_303 = F_95 ( V_21 ) ;
if ( V_191 -> V_302 == V_303 -> V_302 ) {
V_306 = ( void * ) ( unsigned long ) V_191 -> V_148 ;
if ( F_62 ( V_306 , V_303 -> V_148 , V_303 -> V_302 ) ) {
V_24 = - V_175 ;
goto V_298;
}
}
V_191 -> V_302 = V_303 -> V_302 ;
V_298:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_96 ( struct V_9 * V_10 ,
struct V_73 * V_73 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
int V_24 = 0 , V_308 ;
if ( V_10 -> V_60 )
F_93 ( V_19 , V_10 -> V_60 ) ;
if ( ! V_73 ) {
V_10 -> V_60 = NULL ;
V_24 = F_88 ( V_10 , V_19 -> V_26 . V_63 , 0 ) ;
return V_24 ;
}
V_308 = V_309 * ( 1 + V_73 -> V_310 ) ;
V_10 -> V_60 = F_92 ( V_10 -> V_19 ,
V_308 , V_73 ) ;
V_24 = F_88 ( V_10 ,
V_19 -> V_26 . V_63 ,
V_10 -> V_60 -> V_7 . V_8 ) ;
return V_24 ;
}
int F_97 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_311 * V_191 = V_148 ;
struct V_20 * V_21 ;
struct V_72 * V_129 ;
struct V_9 * V_10 ;
int V_24 = - V_29 ;
int V_75 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_191 -> V_162 , V_56 ) ;
if ( ! V_21 ) {
goto V_133;
}
V_10 = F_61 ( V_21 ) ;
for ( V_75 = 0 ; V_75 < V_200 ; V_75 ++ ) {
if ( V_10 -> V_201 [ V_75 ] == V_191 -> V_297 )
break;
}
if ( V_75 == V_200 ) {
goto V_133;
}
V_21 = F_12 ( V_19 , V_191 -> V_297 , V_277 ) ;
if ( ! V_21 ) {
goto V_133;
}
V_129 = F_91 ( V_21 ) ;
if ( V_129 -> V_146 & V_77 )
goto V_133;
if ( V_129 -> V_146 & V_94 ) {
if ( V_191 -> V_281 < V_129 -> V_95 [ 0 ] )
goto V_133;
if ( V_191 -> V_281 > V_129 -> V_95 [ 1 ] )
goto V_133;
} else {
int V_249 = 0 ;
for ( V_75 = 0 ; V_75 < V_129 -> V_275 ; V_75 ++ ) {
if ( V_129 -> V_95 [ V_75 ] == V_191 -> V_281 ) {
V_249 = 1 ;
break;
}
}
if ( ! V_249 ) {
goto V_133;
}
}
if ( V_129 == V_10 -> V_19 -> V_26 . V_64 ) {
if ( V_10 -> V_36 -> V_74 )
(* V_10 -> V_36 -> V_74 )( V_10 , ( int ) V_191 -> V_281 ) ;
V_24 = 0 ;
} else if ( V_10 -> V_36 -> V_312 )
V_24 = V_10 -> V_36 -> V_312 ( V_10 , V_129 , V_191 -> V_281 ) ;
if ( ! V_24 )
F_88 ( V_10 , V_129 , V_191 -> V_281 ) ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_98 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_202 ; V_75 ++ ) {
if ( V_10 -> V_203 [ V_75 ] == 0 ) {
V_10 -> V_203 [ V_75 ] = V_2 -> V_7 . V_8 ;
return 0 ;
}
}
return - V_121 ;
}
void F_99 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_202 ; V_75 ++ ) {
if ( V_10 -> V_203 [ V_75 ] == V_2 -> V_7 . V_8 ) {
V_10 -> V_203 [ V_75 ] = 0 ;
if ( V_10 -> V_2 == V_2 )
V_10 -> V_2 = NULL ;
break;
}
}
}
bool F_100 ( struct V_41 * V_42 ,
int V_187 )
{
V_42 -> V_187 = V_187 ;
V_42 -> V_51 = F_33 ( V_187 * sizeof( V_313 ) * 3 , V_28 ) ;
if ( ! V_42 -> V_51 ) {
V_42 -> V_187 = 0 ;
return false ;
}
return true ;
}
int F_101 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_314 * V_315 = V_148 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_316 , * V_317 , * V_318 ;
int V_308 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_315 -> V_161 , V_48 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_133;
}
V_42 = F_59 ( V_21 ) ;
if ( V_315 -> V_187 != V_42 -> V_187 ) {
V_24 = - V_29 ;
goto V_133;
}
V_308 = V_315 -> V_187 * ( sizeof( V_313 ) ) ;
V_316 = V_42 -> V_51 ;
if ( F_77 ( V_316 , ( void T_2 * ) ( unsigned long ) V_315 -> V_319 , V_308 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_317 = V_316 + V_308 ;
if ( F_77 ( V_317 , ( void T_2 * ) ( unsigned long ) V_315 -> V_320 , V_308 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_318 = V_317 + V_308 ;
if ( F_77 ( V_318 , ( void T_2 * ) ( unsigned long ) V_315 -> V_321 , V_308 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_42 -> V_36 -> V_322 ( V_42 , V_316 , V_317 , V_318 , 0 , V_42 -> V_187 ) ;
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_102 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_314 * V_315 = V_148 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_316 , * V_317 , * V_318 ;
int V_308 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_165 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_315 -> V_161 , V_48 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_133;
}
V_42 = F_59 ( V_21 ) ;
if ( V_315 -> V_187 != V_42 -> V_187 ) {
V_24 = - V_29 ;
goto V_133;
}
V_308 = V_315 -> V_187 * ( sizeof( V_313 ) ) ;
V_316 = V_42 -> V_51 ;
if ( F_62 ( ( void T_2 * ) ( unsigned long ) V_315 -> V_319 , V_316 , V_308 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_317 = V_316 + V_308 ;
if ( F_62 ( ( void T_2 * ) ( unsigned long ) V_315 -> V_320 , V_317 , V_308 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_318 = V_317 + V_308 ;
if ( F_62 ( ( void T_2 * ) ( unsigned long ) V_315 -> V_321 , V_318 , V_308 ) ) {
V_24 = - V_175 ;
goto V_133;
}
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_103 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_323 * V_324 = V_148 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
struct V_33 * V_34 ;
struct V_325 * V_326 = NULL ;
unsigned long V_146 ;
int V_24 = - V_29 ;
if ( V_324 -> V_146 & ~ V_327 ||
V_324 -> V_328 != 0 )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_324 -> V_161 , V_48 ) ;
if ( ! V_21 )
goto V_133;
V_42 = F_59 ( V_21 ) ;
if ( V_42 -> V_34 == NULL ) {
V_24 = - V_329 ;
goto V_133;
}
if ( V_42 -> V_36 -> V_324 == NULL )
goto V_133;
V_21 = F_12 ( V_19 , V_324 -> V_160 , V_37 ) ;
if ( ! V_21 )
goto V_133;
V_34 = F_66 ( V_21 ) ;
if ( V_324 -> V_146 & V_330 ) {
V_24 = - V_121 ;
F_104 ( & V_19 -> V_331 , V_146 ) ;
if ( V_150 -> V_332 < sizeof V_326 -> V_333 ) {
F_105 ( & V_19 -> V_331 , V_146 ) ;
goto V_133;
}
V_150 -> V_332 -= sizeof V_326 -> V_333 ;
F_105 ( & V_19 -> V_331 , V_146 ) ;
V_326 = F_33 ( sizeof *V_326 , V_28 ) ;
if ( V_326 == NULL ) {
F_104 ( & V_19 -> V_331 , V_146 ) ;
V_150 -> V_332 += sizeof V_326 -> V_333 ;
F_105 ( & V_19 -> V_331 , V_146 ) ;
goto V_133;
}
V_326 -> V_333 . V_7 . type = V_334 ;
V_326 -> V_333 . V_7 . V_302 = sizeof V_326 -> V_333 ;
V_326 -> V_333 . V_335 = V_324 -> V_335 ;
V_326 -> V_7 . V_333 = & V_326 -> V_333 . V_7 ;
V_326 -> V_7 . V_150 = V_150 ;
V_326 -> V_7 . V_131 =
( void ( * ) ( struct V_336 * ) ) F_22 ;
}
V_24 = V_42 -> V_36 -> V_324 ( V_42 , V_34 , V_326 ) ;
if ( V_24 ) {
F_104 ( & V_19 -> V_331 , V_146 ) ;
V_150 -> V_332 += sizeof V_326 -> V_333 ;
F_105 ( & V_19 -> V_331 , V_146 ) ;
F_22 ( V_326 ) ;
}
V_133:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
void F_106 ( struct V_18 * V_19 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_17 (crtc, &dev->mode_config.crtc_list, head)
if ( V_42 -> V_36 -> V_337 )
V_42 -> V_36 -> V_337 ( V_42 ) ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
if ( V_2 -> V_36 -> V_337 )
V_2 -> V_36 -> V_337 ( V_2 ) ;
F_17 (connector, &dev->mode_config.connector_list, head)
if ( V_10 -> V_36 -> V_337 )
V_10 -> V_36 -> V_337 ( V_10 ) ;
}
int F_107 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_338 * args = V_148 ;
if ( ! V_19 -> V_339 -> V_340 )
return - V_266 ;
return V_19 -> V_339 -> V_340 ( V_150 , V_19 , args ) ;
}
int F_108 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_341 * args = V_148 ;
if ( ! V_19 -> V_339 -> V_342 )
return - V_266 ;
return V_19 -> V_339 -> V_342 ( V_150 , V_19 , args -> V_238 , & args -> V_343 ) ;
}
int F_109 ( struct V_18 * V_19 ,
void * V_148 , struct V_149 * V_150 )
{
struct V_344 * args = V_148 ;
if ( ! V_19 -> V_339 -> V_345 )
return - V_266 ;
return V_19 -> V_339 -> V_345 ( V_150 , V_19 , args -> V_238 ) ;
}
