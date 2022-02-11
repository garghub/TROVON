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
if ( V_12 != V_63 )
F_27 ( V_10 ,
V_19 -> V_26 . V_64 ,
0 ) ;
F_27 ( V_10 ,
V_19 -> V_26 . V_65 , 0 ) ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
void F_28 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
struct V_52 * V_53 , * V_66 ;
F_29 (mode, t, &connector->probed_modes, head)
F_24 ( V_10 , V_53 ) ;
F_29 (mode, t, &connector->modes, head)
F_24 ( V_10 , V_53 ) ;
F_29 (mode, t, &connector->user_modes, head)
F_24 ( V_10 , V_53 ) ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_10 ( V_19 , & V_10 -> V_7 ) ;
F_18 ( & V_10 -> V_39 ) ;
V_19 -> V_26 . V_62 -- ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
void F_30 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
const struct V_67 * V_36 ,
int V_5 )
{
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_2 -> V_19 = V_19 ;
F_4 ( V_19 , & V_2 -> V_7 , V_68 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_36 = V_36 ;
F_20 ( & V_2 -> V_39 , & V_19 -> V_26 . V_69 ) ;
V_19 -> V_26 . V_70 ++ ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_10 ( V_19 , & V_2 -> V_7 ) ;
F_18 ( & V_2 -> V_39 ) ;
V_19 -> V_26 . V_70 -- ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
}
struct V_52 * F_32 ( struct V_18 * V_19 )
{
struct V_52 * V_71 ;
V_71 = F_33 ( sizeof( struct V_52 ) , V_28 ) ;
if ( ! V_71 )
return NULL ;
F_4 ( V_19 , & V_71 -> V_7 , V_72 ) ;
return V_71 ;
}
void F_34 ( struct V_18 * V_19 , struct V_52 * V_53 )
{
F_10 ( V_19 , & V_53 -> V_7 ) ;
F_22 ( V_53 ) ;
}
static int F_35 ( struct V_18 * V_19 )
{
struct V_73 * V_74 ;
struct V_73 * V_75 ;
int V_76 ;
V_74 = F_36 ( V_19 , V_77 |
V_78 ,
L_7 , 0 ) ;
V_19 -> V_26 . V_64 = V_74 ;
V_75 = F_36 ( V_19 , V_79 ,
L_8 , F_37 ( V_80 ) ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_80 ) ; V_76 ++ )
F_38 ( V_75 , V_76 , V_80 [ V_76 ] . type ,
V_80 [ V_76 ] . V_6 ) ;
V_19 -> V_26 . V_65 = V_75 ;
return 0 ;
}
int F_39 ( struct V_18 * V_19 )
{
struct V_73 * V_81 ;
struct V_73 * V_82 ;
int V_76 ;
if ( V_19 -> V_26 . V_83 )
return 0 ;
V_81 =
F_36 ( V_19 , V_79 ,
L_9 ,
F_37 ( V_84 ) ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_84 ) ; V_76 ++ )
F_38 ( V_81 , V_76 ,
V_84 [ V_76 ] . type ,
V_84 [ V_76 ] . V_6 ) ;
V_19 -> V_26 . V_83 = V_81 ;
V_82 =
F_36 ( V_19 , V_79 |
V_78 ,
L_10 ,
F_37 ( V_85 ) ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_85 ) ; V_76 ++ )
F_38 ( V_82 , V_76 ,
V_85 [ V_76 ] . type ,
V_85 [ V_76 ] . V_6 ) ;
V_19 -> V_26 . V_86 = V_82 ;
return 0 ;
}
int F_40 ( struct V_18 * V_19 , int V_87 ,
char * V_59 [] )
{
struct V_73 * V_88 ;
struct V_73 * V_89 ;
int V_76 ;
if ( V_19 -> V_26 . V_90 )
return 0 ;
V_88 = F_36 ( V_19 , V_79 ,
L_9 ,
F_37 ( V_91 ) ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_91 ) ; V_76 ++ )
F_38 ( V_88 , V_76 ,
V_91 [ V_76 ] . type ,
V_91 [ V_76 ] . V_6 ) ;
V_19 -> V_26 . V_90 = V_88 ;
V_89 =
F_36 ( V_19 , V_79 |
V_78 , L_10 ,
F_37 ( V_92 ) ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_92 ) ; V_76 ++ )
F_38 ( V_89 , V_76 ,
V_92 [ V_76 ] . type ,
V_92 [ V_76 ] . V_6 ) ;
V_19 -> V_26 . V_93 = V_89 ;
V_19 -> V_26 . V_94 =
F_36 ( V_19 , V_95 ,
L_11 , 2 ) ;
V_19 -> V_26 . V_94 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_94 -> V_96 [ 1 ] = 100 ;
V_19 -> V_26 . V_97 =
F_36 ( V_19 , V_95 ,
L_12 , 2 ) ;
V_19 -> V_26 . V_97 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_97 -> V_96 [ 1 ] = 100 ;
V_19 -> V_26 . V_98 =
F_36 ( V_19 , V_95 ,
L_13 , 2 ) ;
V_19 -> V_26 . V_98 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_98 -> V_96 [ 1 ] = 100 ;
V_19 -> V_26 . V_99 =
F_36 ( V_19 , V_95 ,
L_14 , 2 ) ;
V_19 -> V_26 . V_99 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_99 -> V_96 [ 1 ] = 100 ;
V_19 -> V_26 . V_100 =
F_36 ( V_19 , V_79 ,
L_15 , V_87 ) ;
for ( V_76 = 0 ; V_76 < V_87 ; V_76 ++ )
F_38 ( V_19 -> V_26 . V_100 , V_76 ,
V_76 , V_59 [ V_76 ] ) ;
V_19 -> V_26 . V_101 =
F_36 ( V_19 , V_95 ,
L_16 , 2 ) ;
V_19 -> V_26 . V_101 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_101 -> V_96 [ 1 ] = 100 ;
V_19 -> V_26 . V_102 =
F_36 ( V_19 , V_95 ,
L_17 , 2 ) ;
V_19 -> V_26 . V_102 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_102 -> V_96 [ 1 ] = 100 ;
V_19 -> V_26 . V_103 =
F_36 ( V_19 , V_95 ,
L_18 , 2 ) ;
V_19 -> V_26 . V_103 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_103 -> V_96 [ 1 ] = 100 ;
V_19 -> V_26 . V_104 =
F_36 ( V_19 , V_95 ,
L_19 , 2 ) ;
V_19 -> V_26 . V_104 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_104 -> V_96 [ 1 ] = 100 ;
V_19 -> V_26 . V_105 =
F_36 ( V_19 , V_95 ,
L_20 , 2 ) ;
V_19 -> V_26 . V_105 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_105 -> V_96 [ 1 ] = 100 ;
V_19 -> V_26 . V_106 =
F_36 ( V_19 , V_95 ,
L_21 , 2 ) ;
V_19 -> V_26 . V_106 -> V_96 [ 0 ] = 0 ;
V_19 -> V_26 . V_106 -> V_96 [ 1 ] = 100 ;
return 0 ;
}
int F_41 ( struct V_18 * V_19 )
{
struct V_73 * V_107 ;
int V_76 ;
if ( V_19 -> V_26 . V_108 )
return 0 ;
V_107 =
F_36 ( V_19 , V_79 , L_22 ,
F_37 ( V_109 ) ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_109 ) ; V_76 ++ )
F_38 ( V_107 , V_76 ,
V_109 [ V_76 ] . type ,
V_109 [ V_76 ] . V_6 ) ;
V_19 -> V_26 . V_108 = V_107 ;
return 0 ;
}
int F_42 ( struct V_18 * V_19 )
{
struct V_73 * V_110 ;
int V_76 ;
if ( V_19 -> V_26 . V_111 )
return 0 ;
V_110 =
F_36 ( V_19 , V_79 , L_23 ,
F_37 ( V_112 ) ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_112 ) ; V_76 ++ )
F_38 ( V_110 , V_76 ,
V_112 [ V_76 ] . type ,
V_112 [ V_76 ] . V_6 ) ;
V_19 -> V_26 . V_111 = V_110 ;
return 0 ;
}
int F_43 ( struct V_18 * V_19 )
{
struct V_73 * V_113 ;
int V_76 ;
if ( V_19 -> V_26 . V_114 )
return 0 ;
V_113 =
F_36 ( V_19 , V_79 |
V_78 ,
L_24 ,
F_37 ( V_115 ) ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_115 ) ; V_76 ++ )
F_38 ( V_113 , V_76 ,
V_115 [ V_76 ] . type ,
V_115 [ V_76 ] . V_6 ) ;
V_19 -> V_26 . V_114 = V_113 ;
return 0 ;
}
void F_44 ( struct V_18 * V_19 )
{
F_45 ( & V_19 -> V_26 . V_47 ) ;
F_45 ( & V_19 -> V_26 . V_30 ) ;
F_26 ( & V_19 -> V_26 . V_40 ) ;
F_26 ( & V_19 -> V_26 . V_49 ) ;
F_26 ( & V_19 -> V_26 . V_61 ) ;
F_26 ( & V_19 -> V_26 . V_69 ) ;
F_26 ( & V_19 -> V_26 . V_116 ) ;
F_26 ( & V_19 -> V_26 . V_117 ) ;
F_46 ( & V_19 -> V_26 . V_27 ) ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_35 ( V_19 ) ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
V_19 -> V_26 . V_38 = 0 ;
V_19 -> V_26 . V_62 = 0 ;
V_19 -> V_26 . V_50 = 0 ;
V_19 -> V_26 . V_70 = 0 ;
}
int F_47 ( struct V_18 * V_19 , struct V_118 * V_119 )
{
T_1 V_120 = 0 ;
V_120 += V_19 -> V_26 . V_50 ;
V_120 += V_19 -> V_26 . V_62 ;
V_120 += V_19 -> V_26 . V_70 ;
V_119 -> V_121 = F_33 ( V_120 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_119 -> V_121 )
return - V_122 ;
V_119 -> V_123 = 0 ;
V_119 -> V_124 = 0 ;
V_119 -> V_125 = 0 ;
return 0 ;
}
int F_48 ( struct V_18 * V_19 ,
struct V_118 * V_119 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_24 ;
if ( ( V_24 = F_47 ( V_19 , V_119 ) ) )
return V_24 ;
F_17 (crtc, &dev->mode_config.crtc_list, head)
V_119 -> V_121 [ V_119 -> V_123 ++ ] = V_42 -> V_7 . V_8 ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
V_119 -> V_121 [ V_119 -> V_123 + V_119 -> V_125 ++ ] =
V_2 -> V_7 . V_8 ;
F_17 (connector, &dev->mode_config.connector_list, head)
V_119 -> V_121 [ V_119 -> V_123 + V_119 -> V_125 +
V_119 -> V_124 ++ ] = V_10 -> V_7 . V_8 ;
return 0 ;
}
void F_49 ( struct V_18 * V_19 )
{
struct V_9 * V_10 , * V_126 ;
struct V_41 * V_42 , * V_127 ;
struct V_1 * V_2 , * V_128 ;
struct V_33 * V_34 , * V_129 ;
struct V_73 * V_130 , * V_131 ;
F_29 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_2 -> V_36 -> V_132 ( V_2 ) ;
}
F_29 (connector, ot,
&dev->mode_config.connector_list, head) {
V_10 -> V_36 -> V_132 ( V_10 ) ;
}
F_29 (property, pt, &dev->mode_config.property_list,
head) {
F_50 ( V_19 , V_130 ) ;
}
F_29 (fb, fbt, &dev->mode_config.fb_list, head) {
V_34 -> V_36 -> V_132 ( V_34 ) ;
}
F_29 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_42 -> V_36 -> V_132 ( V_42 ) ;
}
}
void F_51 ( struct V_133 * V_134 ,
struct V_52 * V_135 )
{
V_134 -> clock = V_135 -> clock ;
V_134 -> V_136 = V_135 -> V_136 ;
V_134 -> V_137 = V_135 -> V_137 ;
V_134 -> V_138 = V_135 -> V_138 ;
V_134 -> V_139 = V_135 -> V_139 ;
V_134 -> V_140 = V_135 -> V_140 ;
V_134 -> V_141 = V_135 -> V_141 ;
V_134 -> V_142 = V_135 -> V_142 ;
V_134 -> V_143 = V_135 -> V_143 ;
V_134 -> V_144 = V_135 -> V_144 ;
V_134 -> V_145 = V_135 -> V_145 ;
V_134 -> V_146 = V_135 -> V_146 ;
V_134 -> V_147 = V_135 -> V_147 ;
V_134 -> type = V_135 -> type ;
strncpy ( V_134 -> V_6 , V_135 -> V_6 , V_148 ) ;
V_134 -> V_6 [ V_148 - 1 ] = 0 ;
}
void F_52 ( struct V_52 * V_134 ,
struct V_133 * V_135 )
{
V_134 -> clock = V_135 -> clock ;
V_134 -> V_136 = V_135 -> V_136 ;
V_134 -> V_137 = V_135 -> V_137 ;
V_134 -> V_138 = V_135 -> V_138 ;
V_134 -> V_139 = V_135 -> V_139 ;
V_134 -> V_140 = V_135 -> V_140 ;
V_134 -> V_141 = V_135 -> V_141 ;
V_134 -> V_142 = V_135 -> V_142 ;
V_134 -> V_143 = V_135 -> V_143 ;
V_134 -> V_144 = V_135 -> V_144 ;
V_134 -> V_145 = V_135 -> V_145 ;
V_134 -> V_146 = V_135 -> V_146 ;
V_134 -> V_147 = V_135 -> V_147 ;
V_134 -> type = V_135 -> type ;
strncpy ( V_134 -> V_6 , V_135 -> V_6 , V_148 ) ;
V_134 -> V_6 [ V_148 - 1 ] = 0 ;
}
int F_53 ( struct V_18 * V_19 , void * V_149 ,
struct V_150 * V_151 )
{
struct V_152 * V_153 = V_149 ;
struct V_154 * V_155 ;
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
int V_156 = 0 ;
int V_157 = 0 ;
int V_158 = 0 ;
int V_159 = 0 ;
int V_160 = 0 , V_76 ;
T_1 T_2 * V_161 ;
T_1 T_2 * V_162 ;
T_1 T_2 * V_163 ;
T_1 T_2 * V_164 ;
struct V_118 * V_165 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_55 (lh, &file_priv->fbs)
V_158 ++ ;
V_165 = & V_151 -> V_167 -> V_168 -> V_165 ;
if ( V_151 -> V_167 -> V_168 -> type == V_169 ) {
F_55 (lh, &dev->mode_config.crtc_list)
V_157 ++ ;
F_55 (lh, &dev->mode_config.connector_list)
V_156 ++ ;
F_55 (lh, &dev->mode_config.encoder_list)
V_159 ++ ;
} else {
V_157 = V_165 -> V_123 ;
V_156 = V_165 -> V_124 ;
V_159 = V_165 -> V_125 ;
}
V_153 -> V_170 = V_19 -> V_26 . V_170 ;
V_153 -> V_171 = V_19 -> V_26 . V_171 ;
V_153 -> V_172 = V_19 -> V_26 . V_172 ;
V_153 -> V_173 = V_19 -> V_26 . V_173 ;
if ( V_153 -> V_174 >= V_158 ) {
V_160 = 0 ;
V_161 = ( T_1 T_2 * ) ( unsigned long ) V_153 -> V_175 ;
F_17 (fb, &file_priv->fbs, filp_head) {
if ( F_56 ( V_34 -> V_7 . V_8 , V_161 + V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
}
V_153 -> V_174 = V_158 ;
if ( V_153 -> V_177 >= V_157 ) {
V_160 = 0 ;
V_162 = ( T_1 T_2 * ) ( unsigned long ) V_153 -> V_178 ;
if ( V_151 -> V_167 -> V_168 -> type == V_169 ) {
F_17 (crtc, &dev->mode_config.crtc_list,
head) {
F_57 ( L_25 , V_42 -> V_7 . V_8 ) ;
if ( F_56 ( V_42 -> V_7 . V_8 , V_162 + V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
} else {
for ( V_76 = 0 ; V_76 < V_165 -> V_123 ; V_76 ++ ) {
if ( F_56 ( V_165 -> V_121 [ V_76 ] ,
V_162 + V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
}
}
V_153 -> V_177 = V_157 ;
if ( V_153 -> V_179 >= V_159 ) {
V_160 = 0 ;
V_164 = ( T_1 T_2 * ) ( unsigned long ) V_153 -> V_180 ;
if ( V_151 -> V_167 -> V_168 -> type == V_169 ) {
F_17 (encoder,
&dev->mode_config.encoder_list,
head) {
F_57 ( L_26 , V_2 -> V_7 . V_8 ,
F_1 ( V_2 ) ) ;
if ( F_56 ( V_2 -> V_7 . V_8 , V_164 +
V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
} else {
for ( V_76 = V_165 -> V_123 ; V_76 < V_165 -> V_123 + V_165 -> V_125 ; V_76 ++ ) {
if ( F_56 ( V_165 -> V_121 [ V_76 ] ,
V_164 + V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
}
}
V_153 -> V_179 = V_159 ;
if ( V_153 -> V_181 >= V_156 ) {
V_160 = 0 ;
V_163 = ( T_1 T_2 * ) ( unsigned long ) V_153 -> V_182 ;
if ( V_151 -> V_167 -> V_168 -> type == V_169 ) {
F_17 (connector,
&dev->mode_config.connector_list,
head) {
F_57 ( L_27 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
if ( F_56 ( V_10 -> V_7 . V_8 ,
V_163 + V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
} else {
int V_183 = V_165 -> V_123 +
V_165 -> V_125 ;
for ( V_76 = V_183 ; V_76 < V_183 + V_165 -> V_124 ; V_76 ++ ) {
if ( F_56 ( V_165 -> V_121 [ V_76 ] ,
V_163 + V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
}
}
V_153 -> V_181 = V_156 ;
F_57 ( L_28 , V_153 -> V_177 ,
V_153 -> V_181 , V_153 -> V_179 ) ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_58 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_184 * V_185 = V_149 ;
struct V_41 * V_42 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_185 -> V_162 ,
V_48 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_134;
}
V_42 = F_59 ( V_21 ) ;
V_185 -> V_186 = V_42 -> V_186 ;
V_185 -> V_187 = V_42 -> V_187 ;
V_185 -> V_188 = V_42 -> V_188 ;
if ( V_42 -> V_34 )
V_185 -> V_161 = V_42 -> V_34 -> V_7 . V_8 ;
else
V_185 -> V_161 = 0 ;
if ( V_42 -> V_189 ) {
F_51 ( & V_185 -> V_53 , & V_42 -> V_53 ) ;
V_185 -> V_190 = 1 ;
} else {
V_185 -> V_190 = 0 ;
}
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_60 ( struct V_18 * V_19 , void * V_149 ,
struct V_150 * V_151 )
{
struct V_191 * V_192 = V_149 ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
struct V_52 * V_53 ;
int V_193 = 0 ;
int V_194 = 0 ;
int V_195 = 0 ;
int V_24 = 0 ;
int V_160 = 0 ;
int V_76 ;
struct V_133 V_196 ;
struct V_133 T_2 * V_197 ;
T_1 T_2 * V_198 ;
T_3 T_2 * V_199 ;
T_1 T_2 * V_200 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
memset ( & V_196 , 0 , sizeof( struct V_133 ) ) ;
F_57 ( L_29 , V_192 -> V_163 ) ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_192 -> V_163 ,
V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_134;
}
V_10 = F_61 ( V_21 ) ;
for ( V_76 = 0 ; V_76 < V_201 ; V_76 ++ ) {
if ( V_10 -> V_202 [ V_76 ] != 0 ) {
V_194 ++ ;
}
}
for ( V_76 = 0 ; V_76 < V_203 ; V_76 ++ ) {
if ( V_10 -> V_204 [ V_76 ] != 0 ) {
V_195 ++ ;
}
}
if ( V_192 -> V_205 == 0 ) {
V_10 -> V_36 -> V_206 ( V_10 ,
V_19 -> V_26 . V_172 ,
V_19 -> V_26 . V_170 ) ;
}
F_17 (mode, &connector->modes, head)
V_193 ++ ;
V_192 -> V_163 = V_10 -> V_7 . V_8 ;
V_192 -> V_12 = V_10 -> V_12 ;
V_192 -> V_13 = V_10 -> V_13 ;
V_192 -> V_207 = V_10 -> V_208 . V_209 ;
V_192 -> V_210 = V_10 -> V_208 . V_211 ;
V_192 -> V_212 = V_10 -> V_208 . V_213 ;
V_192 -> V_214 = V_10 -> V_15 ;
if ( V_10 -> V_2 )
V_192 -> V_164 = V_10 -> V_2 -> V_7 . V_8 ;
else
V_192 -> V_164 = 0 ;
if ( ( V_192 -> V_205 >= V_193 ) && V_193 ) {
V_160 = 0 ;
V_197 = (struct V_133 * ) ( unsigned long ) V_192 -> V_215 ;
F_17 (mode, &connector->modes, head) {
F_51 ( & V_196 , V_53 ) ;
if ( F_62 ( V_197 + V_160 ,
& V_196 , sizeof( V_196 ) ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
}
V_192 -> V_205 = V_193 ;
if ( ( V_192 -> V_216 >= V_194 ) && V_194 ) {
V_160 = 0 ;
V_198 = ( T_1 * ) ( unsigned long ) ( V_192 -> V_217 ) ;
V_199 = ( T_3 * ) ( unsigned long ) ( V_192 -> V_218 ) ;
for ( V_76 = 0 ; V_76 < V_201 ; V_76 ++ ) {
if ( V_10 -> V_202 [ V_76 ] != 0 ) {
if ( F_56 ( V_10 -> V_202 [ V_76 ] ,
V_198 + V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
if ( F_56 ( V_10 -> V_219 [ V_76 ] ,
V_199 + V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
}
}
V_192 -> V_216 = V_194 ;
if ( ( V_192 -> V_179 >= V_195 ) && V_195 ) {
V_160 = 0 ;
V_200 = ( T_1 * ) ( unsigned long ) ( V_192 -> V_220 ) ;
for ( V_76 = 0 ; V_76 < V_203 ; V_76 ++ ) {
if ( V_10 -> V_204 [ V_76 ] != 0 ) {
if ( F_56 ( V_10 -> V_204 [ V_76 ] ,
V_200 + V_160 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_160 ++ ;
}
}
}
V_192 -> V_179 = V_195 ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_63 ( struct V_18 * V_19 , void * V_149 ,
struct V_150 * V_151 )
{
struct V_221 * V_222 = V_149 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_222 -> V_164 ,
V_68 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_134;
}
V_2 = F_64 ( V_21 ) ;
if ( V_2 -> V_42 )
V_222 -> V_162 = V_2 -> V_42 -> V_7 . V_8 ;
else
V_222 -> V_162 = 0 ;
V_222 -> V_5 = V_2 -> V_5 ;
V_222 -> V_164 = V_2 -> V_7 . V_8 ;
V_222 -> V_223 = V_2 -> V_223 ;
V_222 -> V_224 = V_2 -> V_224 ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_65 ( struct V_18 * V_19 , void * V_149 ,
struct V_150 * V_151 )
{
struct V_225 * V_226 = & V_19 -> V_26 ;
struct V_184 * V_227 = V_149 ;
struct V_20 * V_21 ;
struct V_41 * V_42 , * V_228 ;
struct V_9 * * V_229 = NULL , * V_10 ;
struct V_33 * V_34 = NULL ;
struct V_52 * V_53 = NULL ;
struct V_43 V_44 ;
T_1 T_2 * V_230 ;
int V_24 = 0 ;
int V_76 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_227 -> V_162 ,
V_48 ) ;
if ( ! V_21 ) {
F_57 ( L_30 , V_227 -> V_162 ) ;
V_24 = - V_29 ;
goto V_134;
}
V_42 = F_59 ( V_21 ) ;
F_57 ( L_25 , V_42 -> V_7 . V_8 ) ;
if ( V_227 -> V_190 ) {
if ( V_227 -> V_161 == - 1 ) {
F_17 (crtcfb,
&dev->mode_config.crtc_list, head) {
if ( V_228 == V_42 ) {
F_57 ( L_31
L_32 ) ;
V_34 = V_42 -> V_34 ;
}
}
} else {
V_21 = F_12 ( V_19 , V_227 -> V_161 ,
V_37 ) ;
if ( ! V_21 ) {
F_57 ( L_33 ,
V_227 -> V_161 ) ;
V_24 = - V_29 ;
goto V_134;
}
V_34 = F_66 ( V_21 ) ;
}
V_53 = F_32 ( V_19 ) ;
F_52 ( V_53 , & V_227 -> V_53 ) ;
F_67 ( V_53 , V_231 ) ;
}
if ( V_227 -> V_181 == 0 && V_53 ) {
F_57 ( L_34 ) ;
V_24 = - V_29 ;
goto V_134;
}
if ( V_227 -> V_181 > 0 && ( ! V_53 || ! V_34 ) ) {
F_57 ( L_35 ,
V_227 -> V_181 ) ;
V_24 = - V_29 ;
goto V_134;
}
if ( V_227 -> V_181 > 0 ) {
T_4 V_232 ;
if ( V_227 -> V_181 > V_226 -> V_62 ) {
V_24 = - V_29 ;
goto V_134;
}
V_229 = F_68 ( V_227 -> V_181 *
sizeof( struct V_9 * ) ,
V_28 ) ;
if ( ! V_229 ) {
V_24 = - V_122 ;
goto V_134;
}
for ( V_76 = 0 ; V_76 < V_227 -> V_181 ; V_76 ++ ) {
V_230 = ( T_1 * ) ( unsigned long ) V_227 -> V_230 ;
if ( F_69 ( V_232 , & V_230 [ V_76 ] ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_21 = F_12 ( V_19 , V_232 ,
V_56 ) ;
if ( ! V_21 ) {
F_57 ( L_36 ,
V_232 ) ;
V_24 = - V_29 ;
goto V_134;
}
V_10 = F_61 ( V_21 ) ;
F_57 ( L_27 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
V_229 [ V_76 ] = V_10 ;
}
}
V_44 . V_42 = V_42 ;
V_44 . V_186 = V_227 -> V_186 ;
V_44 . V_187 = V_227 -> V_187 ;
V_44 . V_53 = V_53 ;
V_44 . V_233 = V_229 ;
V_44 . V_124 = V_227 -> V_181 ;
V_44 . V_34 = V_34 ;
V_24 = V_42 -> V_36 -> V_45 ( & V_44 ) ;
V_134:
F_22 ( V_229 ) ;
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_70 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_234 * V_235 = V_149 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
if ( ! V_235 -> V_147 ) {
F_6 ( L_37 ) ;
return - V_29 ;
}
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_235 -> V_162 , V_48 ) ;
if ( ! V_21 ) {
F_57 ( L_30 , V_235 -> V_162 ) ;
V_24 = - V_29 ;
goto V_134;
}
V_42 = F_59 ( V_21 ) ;
if ( V_235 -> V_147 & V_236 ) {
if ( ! V_42 -> V_36 -> V_237 ) {
F_6 ( L_38 ) ;
V_24 = - V_238 ;
goto V_134;
}
V_24 = V_42 -> V_36 -> V_237 ( V_42 , V_151 , V_235 -> V_239 ,
V_235 -> V_240 , V_235 -> V_241 ) ;
}
if ( V_235 -> V_147 & V_242 ) {
if ( V_42 -> V_36 -> V_243 ) {
V_24 = V_42 -> V_36 -> V_243 ( V_42 , V_235 -> V_186 , V_235 -> V_187 ) ;
} else {
F_6 ( L_38 ) ;
V_24 = - V_176 ;
goto V_134;
}
}
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_71 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_244 * V_245 = V_149 ;
struct V_225 * V_226 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
if ( ( V_226 -> V_173 > V_245 -> V_240 ) || ( V_245 -> V_240 > V_226 -> V_172 ) ) {
F_6 ( L_39 ) ;
return - V_29 ;
}
if ( ( V_226 -> V_171 > V_245 -> V_241 ) || ( V_245 -> V_241 > V_226 -> V_170 ) ) {
F_6 ( L_40 ) ;
return - V_29 ;
}
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_246 ( V_19 , V_151 , V_245 ) ;
if ( F_72 ( V_34 ) ) {
F_6 ( L_41 ) ;
V_24 = F_73 ( V_34 ) ;
goto V_134;
}
V_245 -> V_161 = V_34 -> V_7 . V_8 ;
F_15 ( & V_34 -> V_247 , & V_151 -> V_248 ) ;
F_57 ( L_42 , V_34 -> V_7 . V_8 ) ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_74 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_20 * V_21 ;
struct V_33 * V_34 = NULL ;
struct V_33 * V_249 = NULL ;
T_1 * V_8 = V_149 ;
int V_24 = 0 ;
int V_250 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , * V_8 , V_37 ) ;
if ( ! V_21 ) {
F_6 ( L_43 ) ;
V_24 = - V_29 ;
goto V_134;
}
V_34 = F_66 ( V_21 ) ;
F_17 (fbl, &file_priv->fbs, filp_head)
if ( V_34 == V_249 )
V_250 = 1 ;
if ( ! V_250 ) {
F_6 ( L_44 ) ;
V_24 = - V_29 ;
goto V_134;
}
F_18 ( & V_34 -> V_247 ) ;
V_34 -> V_36 -> V_132 ( V_34 ) ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_75 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_244 * V_245 = V_149 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_245 -> V_161 , V_37 ) ;
if ( ! V_21 ) {
F_6 ( L_45 ) ;
V_24 = - V_29 ;
goto V_134;
}
V_34 = F_66 ( V_21 ) ;
V_245 -> V_241 = V_34 -> V_241 ;
V_245 -> V_240 = V_34 -> V_240 ;
V_245 -> V_251 = V_34 -> V_251 ;
V_245 -> V_252 = V_34 -> V_253 ;
V_245 -> V_254 = V_34 -> V_254 ;
V_34 -> V_36 -> V_255 ( V_34 , V_151 , & V_245 -> V_239 ) ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_76 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_256 T_2 * V_257 ;
struct V_256 * V_258 = NULL ;
struct V_259 * V_245 = V_149 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
unsigned V_147 ;
int V_260 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_245 -> V_161 , V_37 ) ;
if ( ! V_21 ) {
F_6 ( L_45 ) ;
V_24 = - V_29 ;
goto V_261;
}
V_34 = F_66 ( V_21 ) ;
V_260 = V_245 -> V_260 ;
V_257 = (struct V_256 * ) ( unsigned long ) V_245 -> V_257 ;
if ( ! V_260 != ! V_257 ) {
V_24 = - V_29 ;
goto V_261;
}
V_147 = V_262 & V_245 -> V_147 ;
if ( V_147 & V_263 && ( V_260 % 2 ) ) {
V_24 = - V_29 ;
goto V_261;
}
if ( V_260 && V_257 ) {
if ( V_260 < 0 || V_260 > V_264 ) {
V_24 = - V_29 ;
goto V_261;
}
V_258 = F_33 ( V_260 * sizeof( * V_258 ) , V_28 ) ;
if ( ! V_258 ) {
V_24 = - V_122 ;
goto V_261;
}
V_24 = F_77 ( V_258 , V_257 ,
V_260 * sizeof( * V_258 ) ) ;
if ( V_24 ) {
V_24 = - V_176 ;
goto V_265;
}
}
if ( V_34 -> V_36 -> V_266 ) {
V_24 = V_34 -> V_36 -> V_266 ( V_34 , V_151 , V_147 , V_245 -> V_267 ,
V_258 , V_260 ) ;
} else {
V_24 = - V_268 ;
goto V_265;
}
V_265:
F_22 ( V_258 ) ;
V_261:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
void F_78 ( struct V_150 * V_269 )
{
struct V_18 * V_19 = V_269 -> V_168 -> V_19 ;
struct V_33 * V_34 , * V_270 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
F_29 (fb, tfb, &priv->fbs, filp_head) {
F_18 ( & V_34 -> V_247 ) ;
V_34 -> V_36 -> V_132 ( V_34 ) ;
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
struct V_52 * V_271 ;
int V_272 = 0 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
break;
if ( V_10 -> V_2 -> V_42 == V_42 ) {
if ( V_272 )
V_271 = F_81 ( V_19 , V_53 ) ;
else
V_271 = V_53 ;
V_24 = F_79 ( V_19 , V_10 , V_271 ) ;
if ( V_24 )
return V_24 ;
V_272 = 1 ;
}
}
return 0 ;
}
static int F_82 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_52 * V_53 )
{
int V_250 = 0 ;
int V_24 = 0 ;
struct V_52 * V_273 , * V_66 ;
F_29 (match_mode, t, &connector->user_modes, head) {
if ( F_83 ( V_273 , V_53 ) ) {
F_18 ( & V_273 -> V_39 ) ;
F_34 ( V_19 , V_273 ) ;
V_250 = 1 ;
break;
}
}
if ( ! V_250 )
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
void * V_149 , struct V_150 * V_151 )
{
struct V_274 * V_275 = V_149 ;
struct V_9 * V_10 ;
struct V_52 * V_53 ;
struct V_20 * V_21 ;
struct V_133 * V_276 = & V_275 -> V_53 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_275 -> V_163 , V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_134;
}
V_10 = F_61 ( V_21 ) ;
V_53 = F_32 ( V_19 ) ;
if ( ! V_53 ) {
V_24 = - V_122 ;
goto V_134;
}
F_52 ( V_53 , V_276 ) ;
V_24 = F_79 ( V_19 , V_10 , V_53 ) ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_86 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_20 * V_21 ;
struct V_274 * V_275 = V_149 ;
struct V_9 * V_10 ;
struct V_52 V_53 ;
struct V_133 * V_276 = & V_275 -> V_53 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_275 -> V_163 , V_56 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_134;
}
V_10 = F_61 ( V_21 ) ;
F_52 ( & V_53 , V_276 ) ;
V_24 = F_82 ( V_19 , V_10 , & V_53 ) ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
struct V_73 * F_36 ( struct V_18 * V_19 , int V_147 ,
const char * V_6 , int V_277 )
{
struct V_73 * V_130 = NULL ;
V_130 = F_33 ( sizeof( struct V_73 ) , V_28 ) ;
if ( ! V_130 )
return NULL ;
if ( V_277 ) {
V_130 -> V_96 = F_33 ( sizeof( T_3 ) * V_277 , V_28 ) ;
if ( ! V_130 -> V_96 )
goto V_278;
}
F_4 ( V_19 , & V_130 -> V_7 , V_279 ) ;
V_130 -> V_147 = V_147 ;
V_130 -> V_277 = V_277 ;
F_26 ( & V_130 -> V_280 ) ;
if ( V_6 ) {
strncpy ( V_130 -> V_6 , V_6 , V_281 ) ;
V_130 -> V_6 [ V_281 - 1 ] = '\0' ;
}
F_20 ( & V_130 -> V_39 , & V_19 -> V_26 . V_116 ) ;
return V_130 ;
V_278:
F_22 ( V_130 ) ;
return NULL ;
}
int F_38 ( struct V_73 * V_130 , int V_282 ,
T_3 V_283 , const char * V_6 )
{
struct V_284 * V_285 ;
if ( ! ( V_130 -> V_147 & V_79 ) )
return - V_29 ;
if ( ! F_87 ( & V_130 -> V_280 ) ) {
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( V_285 -> V_283 == V_283 ) {
strncpy ( V_285 -> V_6 , V_6 , V_281 ) ;
V_285 -> V_6 [ V_281 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_285 = F_33 ( sizeof( struct V_284 ) , V_28 ) ;
if ( ! V_285 )
return - V_122 ;
strncpy ( V_285 -> V_6 , V_6 , V_281 ) ;
V_285 -> V_6 [ V_281 - 1 ] = '\0' ;
V_285 -> V_283 = V_283 ;
V_130 -> V_96 [ V_282 ] = V_283 ;
F_20 ( & V_285 -> V_39 , & V_130 -> V_280 ) ;
return 0 ;
}
void F_50 ( struct V_18 * V_19 , struct V_73 * V_130 )
{
struct V_284 * V_285 , * V_131 ;
F_29 (prop_enum, pt, &property->enum_blob_list, head) {
F_18 ( & V_285 -> V_39 ) ;
F_22 ( V_285 ) ;
}
if ( V_130 -> V_277 )
F_22 ( V_130 -> V_96 ) ;
F_10 ( V_19 , & V_130 -> V_7 ) ;
F_18 ( & V_130 -> V_39 ) ;
F_22 ( V_130 ) ;
}
int F_27 ( struct V_9 * V_10 ,
struct V_73 * V_130 , T_3 V_286 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_201 ; V_76 ++ ) {
if ( V_10 -> V_202 [ V_76 ] == 0 ) {
V_10 -> V_202 [ V_76 ] = V_130 -> V_7 . V_8 ;
V_10 -> V_219 [ V_76 ] = V_286 ;
break;
}
}
if ( V_76 == V_201 )
return - V_29 ;
return 0 ;
}
int F_88 ( struct V_9 * V_10 ,
struct V_73 * V_130 , T_3 V_283 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_201 ; V_76 ++ ) {
if ( V_10 -> V_202 [ V_76 ] == V_130 -> V_7 . V_8 ) {
V_10 -> V_219 [ V_76 ] = V_283 ;
break;
}
}
if ( V_76 == V_201 )
return - V_29 ;
return 0 ;
}
int F_89 ( struct V_9 * V_10 ,
struct V_73 * V_130 , T_3 * V_287 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_201 ; V_76 ++ ) {
if ( V_10 -> V_202 [ V_76 ] == V_130 -> V_7 . V_8 ) {
* V_287 = V_10 -> V_219 [ V_76 ] ;
break;
}
}
if ( V_76 == V_201 )
return - V_29 ;
return 0 ;
}
int F_90 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_20 * V_21 ;
struct V_288 * V_192 = V_149 ;
struct V_73 * V_130 ;
int V_289 = 0 ;
int V_290 = 0 ;
int V_291 = 0 ;
int V_24 = 0 , V_76 ;
int V_160 ;
struct V_284 * V_285 ;
struct V_292 T_2 * V_293 ;
struct V_294 * V_295 ;
T_1 * V_296 ;
T_3 T_2 * V_297 ;
T_1 T_2 * V_298 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_192 -> V_299 , V_279 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_300;
}
V_130 = F_91 ( V_21 ) ;
if ( V_130 -> V_147 & V_79 ) {
F_17 (prop_enum, &property->enum_blob_list, head)
V_289 ++ ;
} else if ( V_130 -> V_147 & V_77 ) {
F_17 (prop_blob, &property->enum_blob_list, head)
V_290 ++ ;
}
V_291 = V_130 -> V_277 ;
strncpy ( V_192 -> V_6 , V_130 -> V_6 , V_281 ) ;
V_192 -> V_6 [ V_281 - 1 ] = 0 ;
V_192 -> V_147 = V_130 -> V_147 ;
if ( ( V_192 -> V_301 >= V_291 ) && V_291 ) {
V_297 = ( T_3 * ) ( unsigned long ) V_192 -> V_297 ;
for ( V_76 = 0 ; V_76 < V_291 ; V_76 ++ ) {
if ( F_62 ( V_297 + V_76 , & V_130 -> V_96 [ V_76 ] , sizeof( T_3 ) ) ) {
V_24 = - V_176 ;
goto V_300;
}
}
}
V_192 -> V_301 = V_291 ;
if ( V_130 -> V_147 & V_79 ) {
if ( ( V_192 -> V_302 >= V_289 ) && V_289 ) {
V_160 = 0 ;
V_293 = (struct V_292 * ) ( unsigned long ) V_192 -> V_303 ;
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( F_62 ( & V_293 [ V_160 ] . V_283 , & V_285 -> V_283 , sizeof( T_3 ) ) ) {
V_24 = - V_176 ;
goto V_300;
}
if ( F_62 ( & V_293 [ V_160 ] . V_6 ,
& V_285 -> V_6 , V_281 ) ) {
V_24 = - V_176 ;
goto V_300;
}
V_160 ++ ;
}
}
V_192 -> V_302 = V_289 ;
}
if ( V_130 -> V_147 & V_77 ) {
if ( ( V_192 -> V_302 >= V_290 ) && V_290 ) {
V_160 = 0 ;
V_296 = ( T_1 * ) ( unsigned long ) V_192 -> V_303 ;
V_298 = ( T_1 * ) ( unsigned long ) V_192 -> V_297 ;
F_17 (prop_blob, &property->enum_blob_list, head) {
if ( F_56 ( V_295 -> V_7 . V_8 , V_296 + V_160 ) ) {
V_24 = - V_176 ;
goto V_300;
}
if ( F_56 ( V_295 -> V_304 , V_298 + V_160 ) ) {
V_24 = - V_176 ;
goto V_300;
}
V_160 ++ ;
}
}
V_192 -> V_302 = V_290 ;
}
V_300:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
static struct V_294 * F_92 ( struct V_18 * V_19 , int V_304 ,
void * V_149 )
{
struct V_294 * V_305 ;
if ( ! V_304 || ! V_149 )
return NULL ;
V_305 = F_33 ( sizeof( struct V_294 ) + V_304 , V_28 ) ;
if ( ! V_305 )
return NULL ;
V_305 -> V_149 = ( void * ) ( ( char * ) V_305 + sizeof( struct V_294 ) ) ;
V_305 -> V_304 = V_304 ;
memcpy ( V_305 -> V_149 , V_149 , V_304 ) ;
F_4 ( V_19 , & V_305 -> V_7 , V_306 ) ;
F_20 ( & V_305 -> V_39 , & V_19 -> V_26 . V_117 ) ;
return V_305 ;
}
static void F_93 ( struct V_18 * V_19 ,
struct V_294 * V_305 )
{
F_10 ( V_19 , & V_305 -> V_7 ) ;
F_18 ( & V_305 -> V_39 ) ;
F_22 ( V_305 ) ;
}
int F_94 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_20 * V_21 ;
struct V_307 * V_192 = V_149 ;
struct V_294 * V_305 ;
int V_24 = 0 ;
void * V_308 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_192 -> V_309 , V_306 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_300;
}
V_305 = F_95 ( V_21 ) ;
if ( V_192 -> V_304 == V_305 -> V_304 ) {
V_308 = ( void * ) ( unsigned long ) V_192 -> V_149 ;
if ( F_62 ( V_308 , V_305 -> V_149 , V_305 -> V_304 ) ) {
V_24 = - V_176 ;
goto V_300;
}
}
V_192 -> V_304 = V_305 -> V_304 ;
V_300:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_96 ( struct V_9 * V_10 ,
struct V_74 * V_74 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
int V_24 = 0 , V_310 ;
if ( V_10 -> V_60 )
F_93 ( V_19 , V_10 -> V_60 ) ;
if ( ! V_74 ) {
V_10 -> V_60 = NULL ;
V_24 = F_88 ( V_10 , V_19 -> V_26 . V_64 , 0 ) ;
return V_24 ;
}
V_310 = V_311 * ( 1 + V_74 -> V_312 ) ;
V_10 -> V_60 = F_92 ( V_10 -> V_19 ,
V_310 , V_74 ) ;
V_24 = F_88 ( V_10 ,
V_19 -> V_26 . V_64 ,
V_10 -> V_60 -> V_7 . V_8 ) ;
return V_24 ;
}
int F_97 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_313 * V_192 = V_149 ;
struct V_20 * V_21 ;
struct V_73 * V_130 ;
struct V_9 * V_10 ;
int V_24 = - V_29 ;
int V_76 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_192 -> V_163 , V_56 ) ;
if ( ! V_21 ) {
goto V_134;
}
V_10 = F_61 ( V_21 ) ;
for ( V_76 = 0 ; V_76 < V_201 ; V_76 ++ ) {
if ( V_10 -> V_202 [ V_76 ] == V_192 -> V_299 )
break;
}
if ( V_76 == V_201 ) {
goto V_134;
}
V_21 = F_12 ( V_19 , V_192 -> V_299 , V_279 ) ;
if ( ! V_21 ) {
goto V_134;
}
V_130 = F_91 ( V_21 ) ;
if ( V_130 -> V_147 & V_78 )
goto V_134;
if ( V_130 -> V_147 & V_95 ) {
if ( V_192 -> V_283 < V_130 -> V_96 [ 0 ] )
goto V_134;
if ( V_192 -> V_283 > V_130 -> V_96 [ 1 ] )
goto V_134;
} else {
int V_250 = 0 ;
for ( V_76 = 0 ; V_76 < V_130 -> V_277 ; V_76 ++ ) {
if ( V_130 -> V_96 [ V_76 ] == V_192 -> V_283 ) {
V_250 = 1 ;
break;
}
}
if ( ! V_250 ) {
goto V_134;
}
}
if ( V_130 == V_10 -> V_19 -> V_26 . V_65 ) {
if ( V_10 -> V_36 -> V_75 )
(* V_10 -> V_36 -> V_75 )( V_10 , ( int ) V_192 -> V_283 ) ;
V_24 = 0 ;
} else if ( V_10 -> V_36 -> V_314 )
V_24 = V_10 -> V_36 -> V_314 ( V_10 , V_130 , V_192 -> V_283 ) ;
if ( ! V_24 )
F_88 ( V_10 , V_130 , V_192 -> V_283 ) ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_98 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_203 ; V_76 ++ ) {
if ( V_10 -> V_204 [ V_76 ] == 0 ) {
V_10 -> V_204 [ V_76 ] = V_2 -> V_7 . V_8 ;
return 0 ;
}
}
return - V_122 ;
}
void F_99 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_203 ; V_76 ++ ) {
if ( V_10 -> V_204 [ V_76 ] == V_2 -> V_7 . V_8 ) {
V_10 -> V_204 [ V_76 ] = 0 ;
if ( V_10 -> V_2 == V_2 )
V_10 -> V_2 = NULL ;
break;
}
}
}
bool F_100 ( struct V_41 * V_42 ,
int V_188 )
{
V_42 -> V_188 = V_188 ;
V_42 -> V_51 = F_33 ( V_188 * sizeof( V_315 ) * 3 , V_28 ) ;
if ( ! V_42 -> V_51 ) {
V_42 -> V_188 = 0 ;
return false ;
}
return true ;
}
int F_101 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_316 * V_317 = V_149 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_318 , * V_319 , * V_320 ;
int V_310 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_317 -> V_162 , V_48 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_134;
}
V_42 = F_59 ( V_21 ) ;
if ( V_317 -> V_188 != V_42 -> V_188 ) {
V_24 = - V_29 ;
goto V_134;
}
V_310 = V_317 -> V_188 * ( sizeof( V_315 ) ) ;
V_318 = V_42 -> V_51 ;
if ( F_77 ( V_318 , ( void T_2 * ) ( unsigned long ) V_317 -> V_321 , V_310 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_319 = V_318 + V_310 ;
if ( F_77 ( V_319 , ( void T_2 * ) ( unsigned long ) V_317 -> V_322 , V_310 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_320 = V_319 + V_310 ;
if ( F_77 ( V_320 , ( void T_2 * ) ( unsigned long ) V_317 -> V_323 , V_310 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_42 -> V_36 -> V_324 ( V_42 , V_318 , V_319 , V_320 , 0 , V_42 -> V_188 ) ;
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_102 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_316 * V_317 = V_149 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_318 , * V_319 , * V_320 ;
int V_310 ;
int V_24 = 0 ;
if ( ! F_54 ( V_19 , V_166 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_317 -> V_162 , V_48 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_134;
}
V_42 = F_59 ( V_21 ) ;
if ( V_317 -> V_188 != V_42 -> V_188 ) {
V_24 = - V_29 ;
goto V_134;
}
V_310 = V_317 -> V_188 * ( sizeof( V_315 ) ) ;
V_318 = V_42 -> V_51 ;
if ( F_62 ( ( void T_2 * ) ( unsigned long ) V_317 -> V_321 , V_318 , V_310 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_319 = V_318 + V_310 ;
if ( F_62 ( ( void T_2 * ) ( unsigned long ) V_317 -> V_322 , V_319 , V_310 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_320 = V_319 + V_310 ;
if ( F_62 ( ( void T_2 * ) ( unsigned long ) V_317 -> V_323 , V_320 , V_310 ) ) {
V_24 = - V_176 ;
goto V_134;
}
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
int F_103 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_325 * V_326 = V_149 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
struct V_33 * V_34 ;
struct V_327 * V_328 = NULL ;
unsigned long V_147 ;
int V_24 = - V_29 ;
if ( V_326 -> V_147 & ~ V_329 ||
V_326 -> V_330 != 0 )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_47 ) ;
V_21 = F_12 ( V_19 , V_326 -> V_162 , V_48 ) ;
if ( ! V_21 )
goto V_134;
V_42 = F_59 ( V_21 ) ;
if ( V_42 -> V_34 == NULL ) {
V_24 = - V_331 ;
goto V_134;
}
if ( V_42 -> V_36 -> V_326 == NULL )
goto V_134;
V_21 = F_12 ( V_19 , V_326 -> V_161 , V_37 ) ;
if ( ! V_21 )
goto V_134;
V_34 = F_66 ( V_21 ) ;
if ( V_326 -> V_147 & V_332 ) {
V_24 = - V_122 ;
F_104 ( & V_19 -> V_333 , V_147 ) ;
if ( V_151 -> V_334 < sizeof V_328 -> V_335 ) {
F_105 ( & V_19 -> V_333 , V_147 ) ;
goto V_134;
}
V_151 -> V_334 -= sizeof V_328 -> V_335 ;
F_105 ( & V_19 -> V_333 , V_147 ) ;
V_328 = F_33 ( sizeof *V_328 , V_28 ) ;
if ( V_328 == NULL ) {
F_104 ( & V_19 -> V_333 , V_147 ) ;
V_151 -> V_334 += sizeof V_328 -> V_335 ;
F_105 ( & V_19 -> V_333 , V_147 ) ;
goto V_134;
}
V_328 -> V_335 . V_7 . type = V_336 ;
V_328 -> V_335 . V_7 . V_304 = sizeof V_328 -> V_335 ;
V_328 -> V_335 . V_337 = V_326 -> V_337 ;
V_328 -> V_7 . V_335 = & V_328 -> V_335 . V_7 ;
V_328 -> V_7 . V_151 = V_151 ;
V_328 -> V_7 . V_132 =
( void ( * ) ( struct V_338 * ) ) F_22 ;
}
V_24 = V_42 -> V_36 -> V_326 ( V_42 , V_34 , V_328 ) ;
if ( V_24 ) {
F_104 ( & V_19 -> V_333 , V_147 ) ;
V_151 -> V_334 += sizeof V_328 -> V_335 ;
F_105 ( & V_19 -> V_333 , V_147 ) ;
F_22 ( V_328 ) ;
}
V_134:
F_9 ( & V_19 -> V_26 . V_47 ) ;
return V_24 ;
}
void F_106 ( struct V_18 * V_19 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_17 (crtc, &dev->mode_config.crtc_list, head)
if ( V_42 -> V_36 -> V_339 )
V_42 -> V_36 -> V_339 ( V_42 ) ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
if ( V_2 -> V_36 -> V_339 )
V_2 -> V_36 -> V_339 ( V_2 ) ;
F_17 (connector, &dev->mode_config.connector_list, head)
if ( V_10 -> V_36 -> V_339 )
V_10 -> V_36 -> V_339 ( V_10 ) ;
}
int F_107 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_340 * args = V_149 ;
if ( ! V_19 -> V_341 -> V_342 )
return - V_268 ;
return V_19 -> V_341 -> V_342 ( V_151 , V_19 , args ) ;
}
int F_108 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_343 * args = V_149 ;
if ( ! V_19 -> V_341 -> V_344 )
return - V_268 ;
return V_19 -> V_341 -> V_344 ( V_151 , V_19 , args -> V_239 , & args -> V_345 ) ;
}
int F_109 ( struct V_18 * V_19 ,
void * V_149 , struct V_150 * V_151 )
{
struct V_346 * args = V_149 ;
if ( ! V_19 -> V_341 -> V_347 )
return - V_268 ;
return V_19 -> V_341 -> V_347 ( V_151 , V_19 , args -> V_239 ) ;
}
