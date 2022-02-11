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
void F_19 ( struct V_18 * V_19 , struct V_41 * V_42 ,
const struct V_49 * V_36 )
{
V_42 -> V_19 = V_19 ;
V_42 -> V_36 = V_36 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_4 ( V_19 , & V_42 -> V_7 , V_51 ) ;
F_20 ( & V_42 -> V_39 , & V_19 -> V_26 . V_52 ) ;
V_19 -> V_26 . V_53 ++ ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
void F_21 ( struct V_41 * V_42 )
{
struct V_18 * V_19 = V_42 -> V_19 ;
if ( V_42 -> V_54 ) {
F_22 ( V_42 -> V_54 ) ;
V_42 -> V_54 = NULL ;
}
F_10 ( V_19 , & V_42 -> V_7 ) ;
F_18 ( & V_42 -> V_39 ) ;
V_19 -> V_26 . V_53 -- ;
}
void F_23 ( struct V_9 * V_10 ,
struct V_55 * V_56 )
{
F_15 ( & V_56 -> V_39 , & V_10 -> V_57 ) ;
}
void F_24 ( struct V_9 * V_10 ,
struct V_55 * V_56 )
{
F_18 ( & V_56 -> V_39 ) ;
F_22 ( V_56 ) ;
}
void F_25 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
const struct V_58 * V_36 ,
int V_12 )
{
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_10 -> V_19 = V_19 ;
V_10 -> V_36 = V_36 ;
F_4 ( V_19 , & V_10 -> V_7 , V_59 ) ;
V_10 -> V_12 = V_12 ;
V_10 -> V_13 =
++ V_11 [ V_12 ] . V_60 ;
F_26 ( & V_10 -> V_61 ) ;
F_26 ( & V_10 -> V_57 ) ;
F_26 ( & V_10 -> V_62 ) ;
V_10 -> V_63 = NULL ;
F_20 ( & V_10 -> V_39 , & V_19 -> V_26 . V_64 ) ;
V_19 -> V_26 . V_65 ++ ;
if ( V_12 != V_66 )
F_27 ( V_10 ,
V_19 -> V_26 . V_67 ,
0 ) ;
F_27 ( V_10 ,
V_19 -> V_26 . V_68 , 0 ) ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
void F_28 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
struct V_55 * V_56 , * V_69 ;
F_29 (mode, t, &connector->probed_modes, head)
F_24 ( V_10 , V_56 ) ;
F_29 (mode, t, &connector->modes, head)
F_24 ( V_10 , V_56 ) ;
F_29 (mode, t, &connector->user_modes, head)
F_24 ( V_10 , V_56 ) ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_10 ( V_19 , & V_10 -> V_7 ) ;
F_18 ( & V_10 -> V_39 ) ;
V_19 -> V_26 . V_65 -- ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
void F_30 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
const struct V_70 * V_36 ,
int V_5 )
{
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_2 -> V_19 = V_19 ;
F_4 ( V_19 , & V_2 -> V_7 , V_71 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_36 = V_36 ;
F_20 ( & V_2 -> V_39 , & V_19 -> V_26 . V_72 ) ;
V_19 -> V_26 . V_73 ++ ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_10 ( V_19 , & V_2 -> V_7 ) ;
F_18 ( & V_2 -> V_39 ) ;
V_19 -> V_26 . V_73 -- ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
int F_32 ( struct V_18 * V_19 , struct V_43 * V_44 ,
unsigned long V_74 ,
const struct V_75 * V_36 ,
const T_1 * V_76 , T_1 V_77 ,
bool V_78 )
{
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_44 -> V_19 = V_19 ;
F_4 ( V_19 , & V_44 -> V_7 , V_79 ) ;
V_44 -> V_36 = V_36 ;
V_44 -> V_80 = F_33 ( sizeof( T_1 ) * V_77 ,
V_28 ) ;
if ( ! V_44 -> V_80 ) {
F_34 ( L_8 ) ;
F_10 ( V_19 , & V_44 -> V_7 ) ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
return - V_81 ;
}
memcpy ( V_44 -> V_80 , V_76 , V_77 * sizeof( T_1 ) ) ;
V_44 -> V_77 = V_77 ;
V_44 -> V_74 = V_74 ;
if ( ! V_78 ) {
F_20 ( & V_44 -> V_39 , & V_19 -> V_26 . V_82 ) ;
V_19 -> V_26 . V_83 ++ ;
} else {
F_26 ( & V_44 -> V_39 ) ;
}
F_9 ( & V_19 -> V_26 . V_50 ) ;
return 0 ;
}
void F_35 ( struct V_43 * V_44 )
{
struct V_18 * V_19 = V_44 -> V_19 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_22 ( V_44 -> V_80 ) ;
F_10 ( V_19 , & V_44 -> V_7 ) ;
if ( ! F_36 ( & V_44 -> V_39 ) ) {
F_18 ( & V_44 -> V_39 ) ;
V_19 -> V_26 . V_83 -- ;
}
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
struct V_55 * F_37 ( struct V_18 * V_19 )
{
struct V_55 * V_84 ;
V_84 = F_38 ( sizeof( struct V_55 ) , V_28 ) ;
if ( ! V_84 )
return NULL ;
F_4 ( V_19 , & V_84 -> V_7 , V_85 ) ;
return V_84 ;
}
void F_39 ( struct V_18 * V_19 , struct V_55 * V_56 )
{
F_10 ( V_19 , & V_56 -> V_7 ) ;
F_22 ( V_56 ) ;
}
static int F_40 ( struct V_18 * V_19 )
{
struct V_86 * V_87 ;
struct V_86 * V_88 ;
int V_89 ;
V_87 = F_41 ( V_19 , V_90 |
V_91 ,
L_9 , 0 ) ;
V_19 -> V_26 . V_67 = V_87 ;
V_88 = F_41 ( V_19 , V_92 ,
L_10 , F_42 ( V_93 ) ) ;
for ( V_89 = 0 ; V_89 < F_42 ( V_93 ) ; V_89 ++ )
F_43 ( V_88 , V_89 , V_93 [ V_89 ] . type ,
V_93 [ V_89 ] . V_6 ) ;
V_19 -> V_26 . V_68 = V_88 ;
return 0 ;
}
int F_44 ( struct V_18 * V_19 )
{
struct V_86 * V_94 ;
struct V_86 * V_95 ;
int V_89 ;
if ( V_19 -> V_26 . V_96 )
return 0 ;
V_94 =
F_41 ( V_19 , V_92 ,
L_11 ,
F_42 ( V_97 ) ) ;
for ( V_89 = 0 ; V_89 < F_42 ( V_97 ) ; V_89 ++ )
F_43 ( V_94 , V_89 ,
V_97 [ V_89 ] . type ,
V_97 [ V_89 ] . V_6 ) ;
V_19 -> V_26 . V_96 = V_94 ;
V_95 =
F_41 ( V_19 , V_92 |
V_91 ,
L_12 ,
F_42 ( V_98 ) ) ;
for ( V_89 = 0 ; V_89 < F_42 ( V_98 ) ; V_89 ++ )
F_43 ( V_95 , V_89 ,
V_98 [ V_89 ] . type ,
V_98 [ V_89 ] . V_6 ) ;
V_19 -> V_26 . V_99 = V_95 ;
return 0 ;
}
int F_45 ( struct V_18 * V_19 , int V_100 ,
char * V_62 [] )
{
struct V_86 * V_101 ;
struct V_86 * V_102 ;
int V_89 ;
if ( V_19 -> V_26 . V_103 )
return 0 ;
V_101 = F_41 ( V_19 , V_92 ,
L_11 ,
F_42 ( V_104 ) ) ;
for ( V_89 = 0 ; V_89 < F_42 ( V_104 ) ; V_89 ++ )
F_43 ( V_101 , V_89 ,
V_104 [ V_89 ] . type ,
V_104 [ V_89 ] . V_6 ) ;
V_19 -> V_26 . V_103 = V_101 ;
V_102 =
F_41 ( V_19 , V_92 |
V_91 , L_12 ,
F_42 ( V_105 ) ) ;
for ( V_89 = 0 ; V_89 < F_42 ( V_105 ) ; V_89 ++ )
F_43 ( V_102 , V_89 ,
V_105 [ V_89 ] . type ,
V_105 [ V_89 ] . V_6 ) ;
V_19 -> V_26 . V_106 = V_102 ;
V_19 -> V_26 . V_107 =
F_41 ( V_19 , V_108 ,
L_13 , 2 ) ;
V_19 -> V_26 . V_107 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_107 -> V_109 [ 1 ] = 100 ;
V_19 -> V_26 . V_110 =
F_41 ( V_19 , V_108 ,
L_14 , 2 ) ;
V_19 -> V_26 . V_110 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_110 -> V_109 [ 1 ] = 100 ;
V_19 -> V_26 . V_111 =
F_41 ( V_19 , V_108 ,
L_15 , 2 ) ;
V_19 -> V_26 . V_111 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_111 -> V_109 [ 1 ] = 100 ;
V_19 -> V_26 . V_112 =
F_41 ( V_19 , V_108 ,
L_16 , 2 ) ;
V_19 -> V_26 . V_112 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_112 -> V_109 [ 1 ] = 100 ;
V_19 -> V_26 . V_113 =
F_41 ( V_19 , V_92 ,
L_17 , V_100 ) ;
for ( V_89 = 0 ; V_89 < V_100 ; V_89 ++ )
F_43 ( V_19 -> V_26 . V_113 , V_89 ,
V_89 , V_62 [ V_89 ] ) ;
V_19 -> V_26 . V_114 =
F_41 ( V_19 , V_108 ,
L_18 , 2 ) ;
V_19 -> V_26 . V_114 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_114 -> V_109 [ 1 ] = 100 ;
V_19 -> V_26 . V_115 =
F_41 ( V_19 , V_108 ,
L_19 , 2 ) ;
V_19 -> V_26 . V_115 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_115 -> V_109 [ 1 ] = 100 ;
V_19 -> V_26 . V_116 =
F_41 ( V_19 , V_108 ,
L_20 , 2 ) ;
V_19 -> V_26 . V_116 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_116 -> V_109 [ 1 ] = 100 ;
V_19 -> V_26 . V_117 =
F_41 ( V_19 , V_108 ,
L_21 , 2 ) ;
V_19 -> V_26 . V_117 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_117 -> V_109 [ 1 ] = 100 ;
V_19 -> V_26 . V_118 =
F_41 ( V_19 , V_108 ,
L_22 , 2 ) ;
V_19 -> V_26 . V_118 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_118 -> V_109 [ 1 ] = 100 ;
V_19 -> V_26 . V_119 =
F_41 ( V_19 , V_108 ,
L_23 , 2 ) ;
V_19 -> V_26 . V_119 -> V_109 [ 0 ] = 0 ;
V_19 -> V_26 . V_119 -> V_109 [ 1 ] = 100 ;
return 0 ;
}
int F_46 ( struct V_18 * V_19 )
{
struct V_86 * V_120 ;
int V_89 ;
if ( V_19 -> V_26 . V_121 )
return 0 ;
V_120 =
F_41 ( V_19 , V_92 , L_24 ,
F_42 ( V_122 ) ) ;
for ( V_89 = 0 ; V_89 < F_42 ( V_122 ) ; V_89 ++ )
F_43 ( V_120 , V_89 ,
V_122 [ V_89 ] . type ,
V_122 [ V_89 ] . V_6 ) ;
V_19 -> V_26 . V_121 = V_120 ;
return 0 ;
}
int F_47 ( struct V_18 * V_19 )
{
struct V_86 * V_123 ;
int V_89 ;
if ( V_19 -> V_26 . V_124 )
return 0 ;
V_123 =
F_41 ( V_19 , V_92 , L_25 ,
F_42 ( V_125 ) ) ;
for ( V_89 = 0 ; V_89 < F_42 ( V_125 ) ; V_89 ++ )
F_43 ( V_123 , V_89 ,
V_125 [ V_89 ] . type ,
V_125 [ V_89 ] . V_6 ) ;
V_19 -> V_26 . V_124 = V_123 ;
return 0 ;
}
int F_48 ( struct V_18 * V_19 )
{
struct V_86 * V_126 ;
int V_89 ;
if ( V_19 -> V_26 . V_127 )
return 0 ;
V_126 =
F_41 ( V_19 , V_92 |
V_91 ,
L_26 ,
F_42 ( V_128 ) ) ;
for ( V_89 = 0 ; V_89 < F_42 ( V_128 ) ; V_89 ++ )
F_43 ( V_126 , V_89 ,
V_128 [ V_89 ] . type ,
V_128 [ V_89 ] . V_6 ) ;
V_19 -> V_26 . V_127 = V_126 ;
return 0 ;
}
void F_49 ( struct V_18 * V_19 )
{
F_50 ( & V_19 -> V_26 . V_50 ) ;
F_50 ( & V_19 -> V_26 . V_30 ) ;
F_26 ( & V_19 -> V_26 . V_40 ) ;
F_26 ( & V_19 -> V_26 . V_52 ) ;
F_26 ( & V_19 -> V_26 . V_64 ) ;
F_26 ( & V_19 -> V_26 . V_72 ) ;
F_26 ( & V_19 -> V_26 . V_129 ) ;
F_26 ( & V_19 -> V_26 . V_130 ) ;
F_26 ( & V_19 -> V_26 . V_82 ) ;
F_51 ( & V_19 -> V_26 . V_27 ) ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_40 ( V_19 ) ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
V_19 -> V_26 . V_38 = 0 ;
V_19 -> V_26 . V_65 = 0 ;
V_19 -> V_26 . V_53 = 0 ;
V_19 -> V_26 . V_73 = 0 ;
}
int F_52 ( struct V_18 * V_19 , struct V_131 * V_132 )
{
T_1 V_133 = 0 ;
V_133 += V_19 -> V_26 . V_53 ;
V_133 += V_19 -> V_26 . V_65 ;
V_133 += V_19 -> V_26 . V_73 ;
V_132 -> V_134 = F_38 ( V_133 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_132 -> V_134 )
return - V_81 ;
V_132 -> V_135 = 0 ;
V_132 -> V_136 = 0 ;
V_132 -> V_137 = 0 ;
return 0 ;
}
int F_53 ( struct V_18 * V_19 ,
struct V_131 * V_132 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_24 ;
if ( ( V_24 = F_52 ( V_19 , V_132 ) ) )
return V_24 ;
F_17 (crtc, &dev->mode_config.crtc_list, head)
V_132 -> V_134 [ V_132 -> V_135 ++ ] = V_42 -> V_7 . V_8 ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
V_132 -> V_134 [ V_132 -> V_135 + V_132 -> V_137 ++ ] =
V_2 -> V_7 . V_8 ;
F_17 (connector, &dev->mode_config.connector_list, head)
V_132 -> V_134 [ V_132 -> V_135 + V_132 -> V_137 +
V_132 -> V_136 ++ ] = V_10 -> V_7 . V_8 ;
return 0 ;
}
void F_54 ( struct V_18 * V_19 )
{
struct V_9 * V_10 , * V_138 ;
struct V_41 * V_42 , * V_139 ;
struct V_1 * V_2 , * V_140 ;
struct V_33 * V_34 , * V_141 ;
struct V_86 * V_142 , * V_143 ;
struct V_43 * V_44 , * V_144 ;
F_29 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_2 -> V_36 -> V_145 ( V_2 ) ;
}
F_29 (connector, ot,
&dev->mode_config.connector_list, head) {
V_10 -> V_36 -> V_145 ( V_10 ) ;
}
F_29 (property, pt, &dev->mode_config.property_list,
head) {
F_55 ( V_19 , V_142 ) ;
}
F_29 (fb, fbt, &dev->mode_config.fb_list, head) {
V_34 -> V_36 -> V_145 ( V_34 ) ;
}
F_29 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_42 -> V_36 -> V_145 ( V_42 ) ;
}
F_29 (plane, plt, &dev->mode_config.plane_list,
head) {
V_44 -> V_36 -> V_145 ( V_44 ) ;
}
}
void F_56 ( struct V_146 * V_147 ,
struct V_55 * V_148 )
{
V_147 -> clock = V_148 -> clock ;
V_147 -> V_149 = V_148 -> V_149 ;
V_147 -> V_150 = V_148 -> V_150 ;
V_147 -> V_151 = V_148 -> V_151 ;
V_147 -> V_152 = V_148 -> V_152 ;
V_147 -> V_153 = V_148 -> V_153 ;
V_147 -> V_154 = V_148 -> V_154 ;
V_147 -> V_155 = V_148 -> V_155 ;
V_147 -> V_156 = V_148 -> V_156 ;
V_147 -> V_157 = V_148 -> V_157 ;
V_147 -> V_158 = V_148 -> V_158 ;
V_147 -> V_159 = V_148 -> V_159 ;
V_147 -> V_160 = V_148 -> V_160 ;
V_147 -> type = V_148 -> type ;
strncpy ( V_147 -> V_6 , V_148 -> V_6 , V_161 ) ;
V_147 -> V_6 [ V_161 - 1 ] = 0 ;
}
void F_57 ( struct V_55 * V_147 ,
struct V_146 * V_148 )
{
V_147 -> clock = V_148 -> clock ;
V_147 -> V_149 = V_148 -> V_149 ;
V_147 -> V_150 = V_148 -> V_150 ;
V_147 -> V_151 = V_148 -> V_151 ;
V_147 -> V_152 = V_148 -> V_152 ;
V_147 -> V_153 = V_148 -> V_153 ;
V_147 -> V_154 = V_148 -> V_154 ;
V_147 -> V_155 = V_148 -> V_155 ;
V_147 -> V_156 = V_148 -> V_156 ;
V_147 -> V_157 = V_148 -> V_157 ;
V_147 -> V_158 = V_148 -> V_158 ;
V_147 -> V_159 = V_148 -> V_159 ;
V_147 -> V_160 = V_148 -> V_160 ;
V_147 -> type = V_148 -> type ;
strncpy ( V_147 -> V_6 , V_148 -> V_6 , V_161 ) ;
V_147 -> V_6 [ V_161 - 1 ] = 0 ;
}
int F_58 ( struct V_18 * V_19 , void * V_162 ,
struct V_163 * V_164 )
{
struct V_165 * V_166 = V_162 ;
struct V_167 * V_168 ;
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
int V_169 = 0 ;
int V_170 = 0 ;
int V_171 = 0 ;
int V_172 = 0 ;
int V_173 = 0 , V_89 ;
T_1 T_2 * V_174 ;
T_1 T_2 * V_175 ;
T_1 T_2 * V_176 ;
T_1 T_2 * V_177 ;
struct V_131 * V_178 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_60 (lh, &file_priv->fbs)
V_171 ++ ;
V_178 = & V_164 -> V_180 -> V_181 -> V_178 ;
if ( V_164 -> V_180 -> V_181 -> type == V_182 ) {
F_60 (lh, &dev->mode_config.crtc_list)
V_170 ++ ;
F_60 (lh, &dev->mode_config.connector_list)
V_169 ++ ;
F_60 (lh, &dev->mode_config.encoder_list)
V_172 ++ ;
} else {
V_170 = V_178 -> V_135 ;
V_169 = V_178 -> V_136 ;
V_172 = V_178 -> V_137 ;
}
V_166 -> V_183 = V_19 -> V_26 . V_183 ;
V_166 -> V_184 = V_19 -> V_26 . V_184 ;
V_166 -> V_185 = V_19 -> V_26 . V_185 ;
V_166 -> V_186 = V_19 -> V_26 . V_186 ;
if ( V_166 -> V_187 >= V_171 ) {
V_173 = 0 ;
V_174 = ( T_1 T_2 * ) ( unsigned long ) V_166 -> V_188 ;
F_17 (fb, &file_priv->fbs, filp_head) {
if ( F_61 ( V_34 -> V_7 . V_8 , V_174 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
}
V_166 -> V_187 = V_171 ;
if ( V_166 -> V_190 >= V_170 ) {
V_173 = 0 ;
V_175 = ( T_1 T_2 * ) ( unsigned long ) V_166 -> V_191 ;
if ( V_164 -> V_180 -> V_181 -> type == V_182 ) {
F_17 (crtc, &dev->mode_config.crtc_list,
head) {
F_34 ( L_27 , V_42 -> V_7 . V_8 ) ;
if ( F_61 ( V_42 -> V_7 . V_8 , V_175 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
} else {
for ( V_89 = 0 ; V_89 < V_178 -> V_135 ; V_89 ++ ) {
if ( F_61 ( V_178 -> V_134 [ V_89 ] ,
V_175 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
}
}
V_166 -> V_190 = V_170 ;
if ( V_166 -> V_192 >= V_172 ) {
V_173 = 0 ;
V_177 = ( T_1 T_2 * ) ( unsigned long ) V_166 -> V_193 ;
if ( V_164 -> V_180 -> V_181 -> type == V_182 ) {
F_17 (encoder,
&dev->mode_config.encoder_list,
head) {
F_34 ( L_28 , V_2 -> V_7 . V_8 ,
F_1 ( V_2 ) ) ;
if ( F_61 ( V_2 -> V_7 . V_8 , V_177 +
V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
} else {
for ( V_89 = V_178 -> V_135 ; V_89 < V_178 -> V_135 + V_178 -> V_137 ; V_89 ++ ) {
if ( F_61 ( V_178 -> V_134 [ V_89 ] ,
V_177 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
}
}
V_166 -> V_192 = V_172 ;
if ( V_166 -> V_194 >= V_169 ) {
V_173 = 0 ;
V_176 = ( T_1 T_2 * ) ( unsigned long ) V_166 -> V_195 ;
if ( V_164 -> V_180 -> V_181 -> type == V_182 ) {
F_17 (connector,
&dev->mode_config.connector_list,
head) {
F_34 ( L_29 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
if ( F_61 ( V_10 -> V_7 . V_8 ,
V_176 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
} else {
int V_196 = V_178 -> V_135 +
V_178 -> V_137 ;
for ( V_89 = V_196 ; V_89 < V_196 + V_178 -> V_136 ; V_89 ++ ) {
if ( F_61 ( V_178 -> V_134 [ V_89 ] ,
V_176 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
}
}
V_166 -> V_194 = V_169 ;
F_34 ( L_30 , V_166 -> V_190 ,
V_166 -> V_194 , V_166 -> V_192 ) ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_62 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_197 * V_198 = V_162 ;
struct V_41 * V_42 ;
struct V_20 * V_21 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_198 -> V_175 ,
V_51 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_147;
}
V_42 = F_63 ( V_21 ) ;
V_198 -> V_199 = V_42 -> V_199 ;
V_198 -> V_200 = V_42 -> V_200 ;
V_198 -> V_201 = V_42 -> V_201 ;
if ( V_42 -> V_34 )
V_198 -> V_174 = V_42 -> V_34 -> V_7 . V_8 ;
else
V_198 -> V_174 = 0 ;
if ( V_42 -> V_202 ) {
F_56 ( & V_198 -> V_56 , & V_42 -> V_56 ) ;
V_198 -> V_203 = 1 ;
} else {
V_198 -> V_203 = 0 ;
}
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_64 ( struct V_18 * V_19 , void * V_162 ,
struct V_163 * V_164 )
{
struct V_204 * V_205 = V_162 ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
struct V_55 * V_56 ;
int V_206 = 0 ;
int V_207 = 0 ;
int V_208 = 0 ;
int V_24 = 0 ;
int V_173 = 0 ;
int V_89 ;
struct V_146 V_209 ;
struct V_146 T_2 * V_210 ;
T_1 T_2 * V_211 ;
T_3 T_2 * V_212 ;
T_1 T_2 * V_213 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
memset ( & V_209 , 0 , sizeof( struct V_146 ) ) ;
F_34 ( L_31 , V_205 -> V_176 ) ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_205 -> V_176 ,
V_59 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_147;
}
V_10 = F_65 ( V_21 ) ;
for ( V_89 = 0 ; V_89 < V_214 ; V_89 ++ ) {
if ( V_10 -> V_215 [ V_89 ] != 0 ) {
V_207 ++ ;
}
}
for ( V_89 = 0 ; V_89 < V_216 ; V_89 ++ ) {
if ( V_10 -> V_217 [ V_89 ] != 0 ) {
V_208 ++ ;
}
}
if ( V_205 -> V_218 == 0 ) {
V_10 -> V_36 -> V_219 ( V_10 ,
V_19 -> V_26 . V_185 ,
V_19 -> V_26 . V_183 ) ;
}
F_17 (mode, &connector->modes, head)
V_206 ++ ;
V_205 -> V_176 = V_10 -> V_7 . V_8 ;
V_205 -> V_12 = V_10 -> V_12 ;
V_205 -> V_13 = V_10 -> V_13 ;
V_205 -> V_220 = V_10 -> V_221 . V_222 ;
V_205 -> V_223 = V_10 -> V_221 . V_224 ;
V_205 -> V_225 = V_10 -> V_221 . V_226 ;
V_205 -> V_227 = V_10 -> V_15 ;
if ( V_10 -> V_2 )
V_205 -> V_177 = V_10 -> V_2 -> V_7 . V_8 ;
else
V_205 -> V_177 = 0 ;
if ( ( V_205 -> V_218 >= V_206 ) && V_206 ) {
V_173 = 0 ;
V_210 = (struct V_146 T_2 * ) ( unsigned long ) V_205 -> V_228 ;
F_17 (mode, &connector->modes, head) {
F_56 ( & V_209 , V_56 ) ;
if ( F_66 ( V_210 + V_173 ,
& V_209 , sizeof( V_209 ) ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
}
V_205 -> V_218 = V_206 ;
if ( ( V_205 -> V_229 >= V_207 ) && V_207 ) {
V_173 = 0 ;
V_211 = ( T_1 T_2 * ) ( unsigned long ) ( V_205 -> V_230 ) ;
V_212 = ( T_3 T_2 * ) ( unsigned long ) ( V_205 -> V_231 ) ;
for ( V_89 = 0 ; V_89 < V_214 ; V_89 ++ ) {
if ( V_10 -> V_215 [ V_89 ] != 0 ) {
if ( F_61 ( V_10 -> V_215 [ V_89 ] ,
V_211 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
if ( F_61 ( V_10 -> V_232 [ V_89 ] ,
V_212 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
}
}
V_205 -> V_229 = V_207 ;
if ( ( V_205 -> V_192 >= V_208 ) && V_208 ) {
V_173 = 0 ;
V_213 = ( T_1 T_2 * ) ( unsigned long ) ( V_205 -> V_233 ) ;
for ( V_89 = 0 ; V_89 < V_216 ; V_89 ++ ) {
if ( V_10 -> V_217 [ V_89 ] != 0 ) {
if ( F_61 ( V_10 -> V_217 [ V_89 ] ,
V_213 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
}
}
V_205 -> V_192 = V_208 ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_67 ( struct V_18 * V_19 , void * V_162 ,
struct V_163 * V_164 )
{
struct V_234 * V_235 = V_162 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_235 -> V_177 ,
V_71 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_147;
}
V_2 = F_68 ( V_21 ) ;
if ( V_2 -> V_42 )
V_235 -> V_175 = V_2 -> V_42 -> V_7 . V_8 ;
else
V_235 -> V_175 = 0 ;
V_235 -> V_5 = V_2 -> V_5 ;
V_235 -> V_177 = V_2 -> V_7 . V_8 ;
V_235 -> V_74 = V_2 -> V_74 ;
V_235 -> V_236 = V_2 -> V_236 ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_69 ( struct V_18 * V_19 , void * V_162 ,
struct V_163 * V_164 )
{
struct V_237 * V_238 = V_162 ;
struct V_239 * V_240 ;
struct V_43 * V_44 ;
T_1 T_2 * V_241 ;
int V_173 = 0 , V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_240 = & V_19 -> V_26 ;
if ( V_240 -> V_83 &&
( V_238 -> V_242 >= V_240 -> V_83 ) ) {
V_241 = ( T_1 T_2 * ) ( unsigned long ) V_238 -> V_243 ;
F_17 (plane, &config->plane_list, head) {
if ( F_61 ( V_44 -> V_7 . V_8 , V_241 + V_173 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_173 ++ ;
}
}
V_238 -> V_242 = V_240 -> V_83 ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_70 ( struct V_18 * V_19 , void * V_162 ,
struct V_163 * V_164 )
{
struct V_244 * V_238 = V_162 ;
struct V_20 * V_21 ;
struct V_43 * V_44 ;
T_1 T_2 * V_245 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_238 -> V_246 ,
V_79 ) ;
if ( ! V_21 ) {
V_24 = - V_247 ;
goto V_147;
}
V_44 = F_71 ( V_21 ) ;
if ( V_44 -> V_42 )
V_238 -> V_175 = V_44 -> V_42 -> V_7 . V_8 ;
else
V_238 -> V_175 = 0 ;
if ( V_44 -> V_34 )
V_238 -> V_174 = V_44 -> V_34 -> V_7 . V_8 ;
else
V_238 -> V_174 = 0 ;
V_238 -> V_246 = V_44 -> V_7 . V_8 ;
V_238 -> V_74 = V_44 -> V_74 ;
V_238 -> V_201 = V_44 -> V_201 ;
if ( V_44 -> V_77 &&
( V_238 -> V_248 >= V_44 -> V_77 ) ) {
V_245 = ( T_1 T_2 * ) ( unsigned long ) V_238 -> V_249 ;
if ( F_66 ( V_245 ,
V_44 -> V_80 ,
sizeof( T_1 ) * V_44 -> V_77 ) ) {
V_24 = - V_189 ;
goto V_147;
}
}
V_238 -> V_248 = V_44 -> V_77 ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_72 ( struct V_18 * V_19 , void * V_162 ,
struct V_163 * V_164 )
{
struct V_250 * V_251 = V_162 ;
struct V_20 * V_21 ;
struct V_43 * V_44 ;
struct V_41 * V_42 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
unsigned int V_252 , V_253 ;
int V_89 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_251 -> V_246 ,
V_79 ) ;
if ( ! V_21 ) {
F_34 ( L_32 ,
V_251 -> V_246 ) ;
V_24 = - V_247 ;
goto V_147;
}
V_44 = F_71 ( V_21 ) ;
if ( ! V_251 -> V_174 ) {
V_44 -> V_36 -> V_48 ( V_44 ) ;
V_44 -> V_42 = NULL ;
V_44 -> V_34 = NULL ;
goto V_147;
}
V_21 = F_12 ( V_19 , V_251 -> V_175 ,
V_51 ) ;
if ( ! V_21 ) {
F_34 ( L_33 ,
V_251 -> V_175 ) ;
V_24 = - V_247 ;
goto V_147;
}
V_42 = F_63 ( V_21 ) ;
V_21 = F_12 ( V_19 , V_251 -> V_174 ,
V_37 ) ;
if ( ! V_21 ) {
F_34 ( L_34 ,
V_251 -> V_174 ) ;
V_24 = - V_247 ;
goto V_147;
}
V_34 = F_73 ( V_21 ) ;
for ( V_89 = 0 ; V_89 < V_44 -> V_77 ; V_89 ++ )
if ( V_34 -> V_254 == V_44 -> V_80 [ V_89 ] )
break;
if ( V_89 == V_44 -> V_77 ) {
F_34 ( L_35 , V_34 -> V_254 ) ;
V_24 = - V_29 ;
goto V_147;
}
V_252 = V_34 -> V_255 << 16 ;
V_253 = V_34 -> V_256 << 16 ;
if ( V_251 -> V_257 > V_252 ||
V_251 -> V_258 > V_252 - V_251 -> V_257 ||
V_251 -> V_259 > V_253 ||
V_251 -> V_260 > V_253 - V_251 -> V_259 ) {
F_34 ( L_36
L_37 ,
V_251 -> V_257 >> 16 ,
( ( V_251 -> V_257 & 0xffff ) * 15625 ) >> 10 ,
V_251 -> V_259 >> 16 ,
( ( V_251 -> V_259 & 0xffff ) * 15625 ) >> 10 ,
V_251 -> V_258 >> 16 ,
( ( V_251 -> V_258 & 0xffff ) * 15625 ) >> 10 ,
V_251 -> V_260 >> 16 ,
( ( V_251 -> V_260 & 0xffff ) * 15625 ) >> 10 ) ;
V_24 = - V_261 ;
goto V_147;
}
if ( V_251 -> V_262 > V_263 ||
V_251 -> V_264 > V_263 - ( V_265 ) V_251 -> V_262 ||
V_251 -> V_266 > V_263 ||
V_251 -> V_267 > V_263 - ( V_265 ) V_251 -> V_266 ) {
F_34 ( L_38 ,
V_251 -> V_262 , V_251 -> V_266 ,
V_251 -> V_264 , V_251 -> V_267 ) ;
V_24 = - V_268 ;
goto V_147;
}
V_24 = V_44 -> V_36 -> V_269 ( V_44 , V_42 , V_34 ,
V_251 -> V_264 , V_251 -> V_267 ,
V_251 -> V_262 , V_251 -> V_266 ,
V_251 -> V_258 , V_251 -> V_260 ,
V_251 -> V_257 , V_251 -> V_259 ) ;
if ( ! V_24 ) {
V_44 -> V_42 = V_42 ;
V_44 -> V_34 = V_34 ;
}
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_74 ( struct V_18 * V_19 , void * V_162 ,
struct V_163 * V_164 )
{
struct V_239 * V_240 = & V_19 -> V_26 ;
struct V_197 * V_270 = V_162 ;
struct V_20 * V_21 ;
struct V_41 * V_42 , * V_271 ;
struct V_9 * * V_272 = NULL , * V_10 ;
struct V_33 * V_34 = NULL ;
struct V_55 * V_56 = NULL ;
struct V_45 V_46 ;
T_1 T_2 * V_273 ;
int V_24 = 0 ;
int V_89 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_270 -> V_175 ,
V_51 ) ;
if ( ! V_21 ) {
F_34 ( L_39 , V_270 -> V_175 ) ;
V_24 = - V_29 ;
goto V_147;
}
V_42 = F_63 ( V_21 ) ;
F_34 ( L_27 , V_42 -> V_7 . V_8 ) ;
if ( V_270 -> V_203 ) {
if ( V_270 -> V_174 == - 1 ) {
F_17 (crtcfb,
&dev->mode_config.crtc_list, head) {
if ( V_271 == V_42 ) {
F_34 ( L_40
L_41 ) ;
V_34 = V_42 -> V_34 ;
}
}
} else {
V_21 = F_12 ( V_19 , V_270 -> V_174 ,
V_37 ) ;
if ( ! V_21 ) {
F_34 ( L_42 ,
V_270 -> V_174 ) ;
V_24 = - V_29 ;
goto V_147;
}
V_34 = F_73 ( V_21 ) ;
}
V_56 = F_37 ( V_19 ) ;
F_57 ( V_56 , & V_270 -> V_56 ) ;
F_75 ( V_56 , V_274 ) ;
}
if ( V_270 -> V_194 == 0 && V_56 ) {
F_34 ( L_43 ) ;
V_24 = - V_29 ;
goto V_147;
}
if ( V_270 -> V_194 > 0 && ( ! V_56 || ! V_34 ) ) {
F_34 ( L_44 ,
V_270 -> V_194 ) ;
V_24 = - V_29 ;
goto V_147;
}
if ( V_270 -> V_194 > 0 ) {
T_4 V_275 ;
if ( V_270 -> V_194 > V_240 -> V_65 ) {
V_24 = - V_29 ;
goto V_147;
}
V_272 = F_33 ( V_270 -> V_194 *
sizeof( struct V_9 * ) ,
V_28 ) ;
if ( ! V_272 ) {
V_24 = - V_81 ;
goto V_147;
}
for ( V_89 = 0 ; V_89 < V_270 -> V_194 ; V_89 ++ ) {
V_273 = ( T_1 T_2 * ) ( unsigned long ) V_270 -> V_273 ;
if ( F_76 ( V_275 , & V_273 [ V_89 ] ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_21 = F_12 ( V_19 , V_275 ,
V_59 ) ;
if ( ! V_21 ) {
F_34 ( L_45 ,
V_275 ) ;
V_24 = - V_29 ;
goto V_147;
}
V_10 = F_65 ( V_21 ) ;
F_34 ( L_29 ,
V_10 -> V_7 . V_8 ,
F_2 ( V_10 ) ) ;
V_272 [ V_89 ] = V_10 ;
}
}
V_46 . V_42 = V_42 ;
V_46 . V_199 = V_270 -> V_199 ;
V_46 . V_200 = V_270 -> V_200 ;
V_46 . V_56 = V_56 ;
V_46 . V_276 = V_272 ;
V_46 . V_136 = V_270 -> V_194 ;
V_46 . V_34 = V_34 ;
V_24 = V_42 -> V_36 -> V_47 ( & V_46 ) ;
V_147:
F_22 ( V_272 ) ;
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_77 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_277 * V_278 = V_162 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
if ( ! V_278 -> V_160 )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_278 -> V_175 , V_51 ) ;
if ( ! V_21 ) {
F_34 ( L_39 , V_278 -> V_175 ) ;
V_24 = - V_29 ;
goto V_147;
}
V_42 = F_63 ( V_21 ) ;
if ( V_278 -> V_160 & V_279 ) {
if ( ! V_42 -> V_36 -> V_280 ) {
V_24 = - V_281 ;
goto V_147;
}
V_24 = V_42 -> V_36 -> V_280 ( V_42 , V_164 , V_278 -> V_282 ,
V_278 -> V_255 , V_278 -> V_256 ) ;
}
if ( V_278 -> V_160 & V_283 ) {
if ( V_42 -> V_36 -> V_284 ) {
V_24 = V_42 -> V_36 -> V_284 ( V_42 , V_278 -> V_199 , V_278 -> V_200 ) ;
} else {
V_24 = - V_189 ;
goto V_147;
}
}
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
T_1 F_78 ( T_1 V_285 , T_1 V_286 )
{
T_1 V_287 ;
switch ( V_285 ) {
case 8 :
V_287 = V_288 ;
break;
case 16 :
if ( V_286 == 15 )
V_287 = V_289 ;
else
V_287 = V_290 ;
break;
case 24 :
V_287 = V_291 ;
break;
case 32 :
if ( V_286 == 24 )
V_287 = V_292 ;
else if ( V_286 == 30 )
V_287 = V_293 ;
else
V_287 = V_294 ;
break;
default:
F_6 ( L_46 ) ;
V_287 = V_292 ;
break;
}
return V_287 ;
}
int F_79 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_295 * V_296 = V_162 ;
struct V_297 V_298 = {} ;
struct V_239 * V_240 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
V_298 . V_174 = V_296 -> V_174 ;
V_298 . V_255 = V_296 -> V_255 ;
V_298 . V_256 = V_296 -> V_256 ;
V_298 . V_299 [ 0 ] = V_296 -> V_300 ;
V_298 . V_254 = F_78 ( V_296 -> V_285 , V_296 -> V_286 ) ;
V_298 . V_301 [ 0 ] = V_296 -> V_282 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
if ( ( V_240 -> V_186 > V_298 . V_255 ) || ( V_298 . V_255 > V_240 -> V_185 ) )
return - V_29 ;
if ( ( V_240 -> V_184 > V_298 . V_256 ) || ( V_298 . V_256 > V_240 -> V_183 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_302 ( V_19 , V_164 , & V_298 ) ;
if ( F_80 ( V_34 ) ) {
F_6 ( L_47 ) ;
V_24 = F_81 ( V_34 ) ;
goto V_147;
}
V_296 -> V_174 = V_34 -> V_7 . V_8 ;
F_15 ( & V_34 -> V_303 , & V_164 -> V_304 ) ;
F_34 ( L_48 , V_34 -> V_7 . V_8 ) ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
static int F_82 ( struct V_297 * V_298 )
{
T_1 V_305 = V_298 -> V_254 & ~ V_306 ;
switch ( V_305 ) {
case V_307 :
case V_288 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_289 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_290 :
case V_324 :
case V_291 :
case V_325 :
case V_292 :
case V_326 :
case V_327 :
case V_328 :
case V_294 :
case V_329 :
case V_330 :
case V_331 :
case V_293 :
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
case V_357 :
return 0 ;
default:
return - V_29 ;
}
}
int F_83 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_297 * V_298 = V_162 ;
struct V_239 * V_240 = & V_19 -> V_26 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
if ( ( V_240 -> V_186 > V_298 -> V_255 ) || ( V_298 -> V_255 > V_240 -> V_185 ) ) {
F_6 ( L_49 ,
V_298 -> V_255 , V_240 -> V_186 , V_240 -> V_185 ) ;
return - V_29 ;
}
if ( ( V_240 -> V_184 > V_298 -> V_256 ) || ( V_298 -> V_256 > V_240 -> V_183 ) ) {
F_6 ( L_50 ,
V_298 -> V_256 , V_240 -> V_184 , V_240 -> V_183 ) ;
return - V_29 ;
}
V_24 = F_82 ( V_298 ) ;
if ( V_24 ) {
F_6 ( L_51 , V_298 -> V_254 ) ;
return V_24 ;
}
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_34 = V_19 -> V_26 . V_36 -> V_302 ( V_19 , V_164 , V_298 ) ;
if ( F_80 ( V_34 ) ) {
F_6 ( L_47 ) ;
V_24 = F_81 ( V_34 ) ;
goto V_147;
}
V_298 -> V_174 = V_34 -> V_7 . V_8 ;
F_15 ( & V_34 -> V_303 , & V_164 -> V_304 ) ;
F_34 ( L_48 , V_34 -> V_7 . V_8 ) ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_84 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_20 * V_21 ;
struct V_33 * V_34 = NULL ;
struct V_33 * V_358 = NULL ;
T_1 * V_8 = V_162 ;
int V_24 = 0 ;
int V_359 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , * V_8 , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_147;
}
V_34 = F_73 ( V_21 ) ;
F_17 (fbl, &file_priv->fbs, filp_head)
if ( V_34 == V_358 )
V_359 = 1 ;
if ( ! V_359 ) {
V_24 = - V_29 ;
goto V_147;
}
F_18 ( & V_34 -> V_303 ) ;
V_34 -> V_36 -> V_145 ( V_34 ) ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_85 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_295 * V_298 = V_162 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_298 -> V_174 , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_147;
}
V_34 = F_73 ( V_21 ) ;
V_298 -> V_256 = V_34 -> V_256 ;
V_298 -> V_255 = V_34 -> V_255 ;
V_298 -> V_286 = V_34 -> V_286 ;
V_298 -> V_285 = V_34 -> V_360 ;
V_298 -> V_300 = V_34 -> V_299 [ 0 ] ;
V_34 -> V_36 -> V_361 ( V_34 , V_164 , & V_298 -> V_282 ) ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_86 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_362 T_2 * V_363 ;
struct V_362 * V_364 = NULL ;
struct V_365 * V_298 = V_162 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
unsigned V_160 ;
int V_366 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_298 -> V_174 , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_367;
}
V_34 = F_73 ( V_21 ) ;
V_366 = V_298 -> V_366 ;
V_363 = (struct V_362 T_2 * ) ( unsigned long ) V_298 -> V_363 ;
if ( ! V_366 != ! V_363 ) {
V_24 = - V_29 ;
goto V_367;
}
V_160 = V_368 & V_298 -> V_160 ;
if ( V_160 & V_369 && ( V_366 % 2 ) ) {
V_24 = - V_29 ;
goto V_367;
}
if ( V_366 && V_363 ) {
if ( V_366 < 0 || V_366 > V_370 ) {
V_24 = - V_29 ;
goto V_367;
}
V_364 = F_38 ( V_366 * sizeof( * V_364 ) , V_28 ) ;
if ( ! V_364 ) {
V_24 = - V_81 ;
goto V_367;
}
V_24 = F_87 ( V_364 , V_363 ,
V_366 * sizeof( * V_364 ) ) ;
if ( V_24 ) {
V_24 = - V_189 ;
goto V_371;
}
}
if ( V_34 -> V_36 -> V_372 ) {
V_24 = V_34 -> V_36 -> V_372 ( V_34 , V_164 , V_160 , V_298 -> V_373 ,
V_364 , V_366 ) ;
} else {
V_24 = - V_374 ;
goto V_371;
}
V_371:
F_22 ( V_364 ) ;
V_367:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_88 ( struct V_163 * V_78 )
{
struct V_18 * V_19 = V_78 -> V_181 -> V_19 ;
struct V_33 * V_34 , * V_375 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
F_29 (fb, tfb, &priv->fbs, filp_head) {
F_18 ( & V_34 -> V_303 ) ;
V_34 -> V_36 -> V_145 ( V_34 ) ;
}
F_9 ( & V_19 -> V_26 . V_50 ) ;
}
static int F_89 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_55 * V_56 )
{
int V_24 = 0 ;
F_20 ( & V_56 -> V_39 , & V_10 -> V_61 ) ;
return V_24 ;
}
int F_90 ( struct V_18 * V_19 , struct V_41 * V_42 ,
struct V_55 * V_56 )
{
struct V_9 * V_10 ;
int V_24 = 0 ;
struct V_55 * V_376 ;
int V_377 = 0 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_10 -> V_2 )
break;
if ( V_10 -> V_2 -> V_42 == V_42 ) {
if ( V_377 )
V_376 = F_91 ( V_19 , V_56 ) ;
else
V_376 = V_56 ;
V_24 = F_89 ( V_19 , V_10 , V_376 ) ;
if ( V_24 )
return V_24 ;
V_377 = 1 ;
}
}
return 0 ;
}
static int F_92 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_55 * V_56 )
{
int V_359 = 0 ;
int V_24 = 0 ;
struct V_55 * V_378 , * V_69 ;
F_29 (match_mode, t, &connector->user_modes, head) {
if ( F_93 ( V_378 , V_56 ) ) {
F_18 ( & V_378 -> V_39 ) ;
F_39 ( V_19 , V_378 ) ;
V_359 = 1 ;
break;
}
}
if ( ! V_359 )
V_24 = - V_29 ;
return V_24 ;
}
int F_94 ( struct V_18 * V_19 , struct V_55 * V_56 )
{
struct V_9 * V_10 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
F_92 ( V_19 , V_10 , V_56 ) ;
}
return 0 ;
}
int F_95 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_379 * V_380 = V_162 ;
struct V_9 * V_10 ;
struct V_55 * V_56 ;
struct V_20 * V_21 ;
struct V_146 * V_381 = & V_380 -> V_56 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_380 -> V_176 , V_59 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_147;
}
V_10 = F_65 ( V_21 ) ;
V_56 = F_37 ( V_19 ) ;
if ( ! V_56 ) {
V_24 = - V_81 ;
goto V_147;
}
F_57 ( V_56 , V_381 ) ;
V_24 = F_89 ( V_19 , V_10 , V_56 ) ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_96 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_20 * V_21 ;
struct V_379 * V_380 = V_162 ;
struct V_9 * V_10 ;
struct V_55 V_56 ;
struct V_146 * V_381 = & V_380 -> V_56 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_380 -> V_176 , V_59 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_147;
}
V_10 = F_65 ( V_21 ) ;
F_57 ( & V_56 , V_381 ) ;
V_24 = F_92 ( V_19 , V_10 , & V_56 ) ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
struct V_86 * F_41 ( struct V_18 * V_19 , int V_160 ,
const char * V_6 , int V_382 )
{
struct V_86 * V_142 = NULL ;
V_142 = F_38 ( sizeof( struct V_86 ) , V_28 ) ;
if ( ! V_142 )
return NULL ;
if ( V_382 ) {
V_142 -> V_109 = F_38 ( sizeof( T_3 ) * V_382 , V_28 ) ;
if ( ! V_142 -> V_109 )
goto V_383;
}
F_4 ( V_19 , & V_142 -> V_7 , V_384 ) ;
V_142 -> V_160 = V_160 ;
V_142 -> V_382 = V_382 ;
F_26 ( & V_142 -> V_385 ) ;
if ( V_6 ) {
strncpy ( V_142 -> V_6 , V_6 , V_386 ) ;
V_142 -> V_6 [ V_386 - 1 ] = '\0' ;
}
F_20 ( & V_142 -> V_39 , & V_19 -> V_26 . V_129 ) ;
return V_142 ;
V_383:
F_22 ( V_142 ) ;
return NULL ;
}
int F_43 ( struct V_86 * V_142 , int V_387 ,
T_3 V_388 , const char * V_6 )
{
struct V_389 * V_390 ;
if ( ! ( V_142 -> V_160 & V_92 ) )
return - V_29 ;
if ( ! F_36 ( & V_142 -> V_385 ) ) {
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( V_390 -> V_388 == V_388 ) {
strncpy ( V_390 -> V_6 , V_6 , V_386 ) ;
V_390 -> V_6 [ V_386 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_390 = F_38 ( sizeof( struct V_389 ) , V_28 ) ;
if ( ! V_390 )
return - V_81 ;
strncpy ( V_390 -> V_6 , V_6 , V_386 ) ;
V_390 -> V_6 [ V_386 - 1 ] = '\0' ;
V_390 -> V_388 = V_388 ;
V_142 -> V_109 [ V_387 ] = V_388 ;
F_20 ( & V_390 -> V_39 , & V_142 -> V_385 ) ;
return 0 ;
}
void F_55 ( struct V_18 * V_19 , struct V_86 * V_142 )
{
struct V_389 * V_390 , * V_143 ;
F_29 (prop_enum, pt, &property->enum_blob_list, head) {
F_18 ( & V_390 -> V_39 ) ;
F_22 ( V_390 ) ;
}
if ( V_142 -> V_382 )
F_22 ( V_142 -> V_109 ) ;
F_10 ( V_19 , & V_142 -> V_7 ) ;
F_18 ( & V_142 -> V_39 ) ;
F_22 ( V_142 ) ;
}
int F_27 ( struct V_9 * V_10 ,
struct V_86 * V_142 , T_3 V_391 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_214 ; V_89 ++ ) {
if ( V_10 -> V_215 [ V_89 ] == 0 ) {
V_10 -> V_215 [ V_89 ] = V_142 -> V_7 . V_8 ;
V_10 -> V_232 [ V_89 ] = V_391 ;
break;
}
}
if ( V_89 == V_214 )
return - V_29 ;
return 0 ;
}
int F_97 ( struct V_9 * V_10 ,
struct V_86 * V_142 , T_3 V_388 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_214 ; V_89 ++ ) {
if ( V_10 -> V_215 [ V_89 ] == V_142 -> V_7 . V_8 ) {
V_10 -> V_232 [ V_89 ] = V_388 ;
break;
}
}
if ( V_89 == V_214 )
return - V_29 ;
return 0 ;
}
int F_98 ( struct V_9 * V_10 ,
struct V_86 * V_142 , T_3 * V_392 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_214 ; V_89 ++ ) {
if ( V_10 -> V_215 [ V_89 ] == V_142 -> V_7 . V_8 ) {
* V_392 = V_10 -> V_232 [ V_89 ] ;
break;
}
}
if ( V_89 == V_214 )
return - V_29 ;
return 0 ;
}
int F_99 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_20 * V_21 ;
struct V_393 * V_205 = V_162 ;
struct V_86 * V_142 ;
int V_394 = 0 ;
int V_395 = 0 ;
int V_396 = 0 ;
int V_24 = 0 , V_89 ;
int V_173 ;
struct V_389 * V_390 ;
struct V_397 T_2 * V_398 ;
struct V_399 * V_400 ;
T_1 T_2 * V_401 ;
T_3 T_2 * V_402 ;
T_1 T_2 * V_403 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_205 -> V_404 , V_384 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_405;
}
V_142 = F_100 ( V_21 ) ;
if ( V_142 -> V_160 & V_92 ) {
F_17 (prop_enum, &property->enum_blob_list, head)
V_394 ++ ;
} else if ( V_142 -> V_160 & V_90 ) {
F_17 (prop_blob, &property->enum_blob_list, head)
V_395 ++ ;
}
V_396 = V_142 -> V_382 ;
strncpy ( V_205 -> V_6 , V_142 -> V_6 , V_386 ) ;
V_205 -> V_6 [ V_386 - 1 ] = 0 ;
V_205 -> V_160 = V_142 -> V_160 ;
if ( ( V_205 -> V_406 >= V_396 ) && V_396 ) {
V_402 = ( T_3 T_2 * ) ( unsigned long ) V_205 -> V_402 ;
for ( V_89 = 0 ; V_89 < V_396 ; V_89 ++ ) {
if ( F_66 ( V_402 + V_89 , & V_142 -> V_109 [ V_89 ] , sizeof( T_3 ) ) ) {
V_24 = - V_189 ;
goto V_405;
}
}
}
V_205 -> V_406 = V_396 ;
if ( V_142 -> V_160 & V_92 ) {
if ( ( V_205 -> V_407 >= V_394 ) && V_394 ) {
V_173 = 0 ;
V_398 = (struct V_397 T_2 * ) ( unsigned long ) V_205 -> V_408 ;
F_17 (prop_enum, &property->enum_blob_list, head) {
if ( F_66 ( & V_398 [ V_173 ] . V_388 , & V_390 -> V_388 , sizeof( T_3 ) ) ) {
V_24 = - V_189 ;
goto V_405;
}
if ( F_66 ( & V_398 [ V_173 ] . V_6 ,
& V_390 -> V_6 , V_386 ) ) {
V_24 = - V_189 ;
goto V_405;
}
V_173 ++ ;
}
}
V_205 -> V_407 = V_394 ;
}
if ( V_142 -> V_160 & V_90 ) {
if ( ( V_205 -> V_407 >= V_395 ) && V_395 ) {
V_173 = 0 ;
V_401 = ( T_1 T_2 * ) ( unsigned long ) V_205 -> V_408 ;
V_403 = ( T_1 T_2 * ) ( unsigned long ) V_205 -> V_402 ;
F_17 (prop_blob, &property->enum_blob_list, head) {
if ( F_61 ( V_400 -> V_7 . V_8 , V_401 + V_173 ) ) {
V_24 = - V_189 ;
goto V_405;
}
if ( F_61 ( V_400 -> V_409 , V_403 + V_173 ) ) {
V_24 = - V_189 ;
goto V_405;
}
V_173 ++ ;
}
}
V_205 -> V_407 = V_395 ;
}
V_405:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
static struct V_399 * F_101 ( struct V_18 * V_19 , int V_409 ,
void * V_162 )
{
struct V_399 * V_410 ;
if ( ! V_409 || ! V_162 )
return NULL ;
V_410 = F_38 ( sizeof( struct V_399 ) + V_409 , V_28 ) ;
if ( ! V_410 )
return NULL ;
V_410 -> V_162 = ( void * ) ( ( char * ) V_410 + sizeof( struct V_399 ) ) ;
V_410 -> V_409 = V_409 ;
memcpy ( V_410 -> V_162 , V_162 , V_409 ) ;
F_4 ( V_19 , & V_410 -> V_7 , V_411 ) ;
F_20 ( & V_410 -> V_39 , & V_19 -> V_26 . V_130 ) ;
return V_410 ;
}
static void F_102 ( struct V_18 * V_19 ,
struct V_399 * V_410 )
{
F_10 ( V_19 , & V_410 -> V_7 ) ;
F_18 ( & V_410 -> V_39 ) ;
F_22 ( V_410 ) ;
}
int F_103 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_20 * V_21 ;
struct V_412 * V_205 = V_162 ;
struct V_399 * V_410 ;
int V_24 = 0 ;
void T_2 * V_413 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_205 -> V_414 , V_411 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_405;
}
V_410 = F_104 ( V_21 ) ;
if ( V_205 -> V_409 == V_410 -> V_409 ) {
V_413 = ( void T_2 * ) ( unsigned long ) V_205 -> V_162 ;
if ( F_66 ( V_413 , V_410 -> V_162 , V_410 -> V_409 ) ) {
V_24 = - V_189 ;
goto V_405;
}
}
V_205 -> V_409 = V_410 -> V_409 ;
V_405:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_105 ( struct V_9 * V_10 ,
struct V_87 * V_87 )
{
struct V_18 * V_19 = V_10 -> V_19 ;
int V_24 = 0 , V_415 ;
if ( V_10 -> V_63 )
F_102 ( V_19 , V_10 -> V_63 ) ;
if ( ! V_87 ) {
V_10 -> V_63 = NULL ;
V_24 = F_97 ( V_10 , V_19 -> V_26 . V_67 , 0 ) ;
return V_24 ;
}
V_415 = V_416 * ( 1 + V_87 -> V_417 ) ;
V_10 -> V_63 = F_101 ( V_10 -> V_19 ,
V_415 , V_87 ) ;
V_24 = F_97 ( V_10 ,
V_19 -> V_26 . V_67 ,
V_10 -> V_63 -> V_7 . V_8 ) ;
return V_24 ;
}
int F_106 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_418 * V_205 = V_162 ;
struct V_20 * V_21 ;
struct V_86 * V_142 ;
struct V_9 * V_10 ;
int V_24 = - V_29 ;
int V_89 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_205 -> V_176 , V_59 ) ;
if ( ! V_21 ) {
goto V_147;
}
V_10 = F_65 ( V_21 ) ;
for ( V_89 = 0 ; V_89 < V_214 ; V_89 ++ ) {
if ( V_10 -> V_215 [ V_89 ] == V_205 -> V_404 )
break;
}
if ( V_89 == V_214 ) {
goto V_147;
}
V_21 = F_12 ( V_19 , V_205 -> V_404 , V_384 ) ;
if ( ! V_21 ) {
goto V_147;
}
V_142 = F_100 ( V_21 ) ;
if ( V_142 -> V_160 & V_91 )
goto V_147;
if ( V_142 -> V_160 & V_108 ) {
if ( V_205 -> V_388 < V_142 -> V_109 [ 0 ] )
goto V_147;
if ( V_205 -> V_388 > V_142 -> V_109 [ 1 ] )
goto V_147;
} else {
int V_359 = 0 ;
for ( V_89 = 0 ; V_89 < V_142 -> V_382 ; V_89 ++ ) {
if ( V_142 -> V_109 [ V_89 ] == V_205 -> V_388 ) {
V_359 = 1 ;
break;
}
}
if ( ! V_359 ) {
goto V_147;
}
}
if ( V_142 == V_10 -> V_19 -> V_26 . V_68 ) {
if ( V_10 -> V_36 -> V_88 )
(* V_10 -> V_36 -> V_88 )( V_10 , ( int ) V_205 -> V_388 ) ;
V_24 = 0 ;
} else if ( V_10 -> V_36 -> V_419 )
V_24 = V_10 -> V_36 -> V_419 ( V_10 , V_142 , V_205 -> V_388 ) ;
if ( ! V_24 )
F_97 ( V_10 , V_142 , V_205 -> V_388 ) ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_107 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_216 ; V_89 ++ ) {
if ( V_10 -> V_217 [ V_89 ] == 0 ) {
V_10 -> V_217 [ V_89 ] = V_2 -> V_7 . V_8 ;
return 0 ;
}
}
return - V_81 ;
}
void F_108 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_216 ; V_89 ++ ) {
if ( V_10 -> V_217 [ V_89 ] == V_2 -> V_7 . V_8 ) {
V_10 -> V_217 [ V_89 ] = 0 ;
if ( V_10 -> V_2 == V_2 )
V_10 -> V_2 = NULL ;
break;
}
}
}
bool F_109 ( struct V_41 * V_42 ,
int V_201 )
{
V_42 -> V_201 = V_201 ;
V_42 -> V_54 = F_38 ( V_201 * sizeof( V_420 ) * 3 , V_28 ) ;
if ( ! V_42 -> V_54 ) {
V_42 -> V_201 = 0 ;
return false ;
}
return true ;
}
int F_110 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_421 * V_422 = V_162 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_423 , * V_424 , * V_425 ;
int V_415 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_422 -> V_175 , V_51 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_147;
}
V_42 = F_63 ( V_21 ) ;
if ( V_422 -> V_201 != V_42 -> V_201 ) {
V_24 = - V_29 ;
goto V_147;
}
V_415 = V_422 -> V_201 * ( sizeof( V_420 ) ) ;
V_423 = V_42 -> V_54 ;
if ( F_87 ( V_423 , ( void T_2 * ) ( unsigned long ) V_422 -> V_426 , V_415 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_424 = V_423 + V_415 ;
if ( F_87 ( V_424 , ( void T_2 * ) ( unsigned long ) V_422 -> V_427 , V_415 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_425 = V_424 + V_415 ;
if ( F_87 ( V_425 , ( void T_2 * ) ( unsigned long ) V_422 -> V_428 , V_415 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_42 -> V_36 -> V_429 ( V_42 , V_423 , V_424 , V_425 , 0 , V_42 -> V_201 ) ;
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_111 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_421 * V_422 = V_162 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
void * V_423 , * V_424 , * V_425 ;
int V_415 ;
int V_24 = 0 ;
if ( ! F_59 ( V_19 , V_179 ) )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_422 -> V_175 , V_51 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_147;
}
V_42 = F_63 ( V_21 ) ;
if ( V_422 -> V_201 != V_42 -> V_201 ) {
V_24 = - V_29 ;
goto V_147;
}
V_415 = V_422 -> V_201 * ( sizeof( V_420 ) ) ;
V_423 = V_42 -> V_54 ;
if ( F_66 ( ( void T_2 * ) ( unsigned long ) V_422 -> V_426 , V_423 , V_415 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_424 = V_423 + V_415 ;
if ( F_66 ( ( void T_2 * ) ( unsigned long ) V_422 -> V_427 , V_424 , V_415 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_425 = V_424 + V_415 ;
if ( F_66 ( ( void T_2 * ) ( unsigned long ) V_422 -> V_428 , V_425 , V_415 ) ) {
V_24 = - V_189 ;
goto V_147;
}
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
int F_112 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_430 * V_431 = V_162 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
struct V_33 * V_34 ;
struct V_432 * V_433 = NULL ;
unsigned long V_160 ;
int V_24 = - V_29 ;
if ( V_431 -> V_160 & ~ V_434 ||
V_431 -> V_435 != 0 )
return - V_29 ;
F_7 ( & V_19 -> V_26 . V_50 ) ;
V_21 = F_12 ( V_19 , V_431 -> V_175 , V_51 ) ;
if ( ! V_21 )
goto V_147;
V_42 = F_63 ( V_21 ) ;
if ( V_42 -> V_34 == NULL ) {
V_24 = - V_436 ;
goto V_147;
}
if ( V_42 -> V_36 -> V_431 == NULL )
goto V_147;
V_21 = F_12 ( V_19 , V_431 -> V_174 , V_37 ) ;
if ( ! V_21 )
goto V_147;
V_34 = F_73 ( V_21 ) ;
if ( V_431 -> V_160 & V_437 ) {
V_24 = - V_81 ;
F_113 ( & V_19 -> V_438 , V_160 ) ;
if ( V_164 -> V_439 < sizeof V_433 -> V_440 ) {
F_114 ( & V_19 -> V_438 , V_160 ) ;
goto V_147;
}
V_164 -> V_439 -= sizeof V_433 -> V_440 ;
F_114 ( & V_19 -> V_438 , V_160 ) ;
V_433 = F_38 ( sizeof *V_433 , V_28 ) ;
if ( V_433 == NULL ) {
F_113 ( & V_19 -> V_438 , V_160 ) ;
V_164 -> V_439 += sizeof V_433 -> V_440 ;
F_114 ( & V_19 -> V_438 , V_160 ) ;
goto V_147;
}
V_433 -> V_440 . V_7 . type = V_441 ;
V_433 -> V_440 . V_7 . V_409 = sizeof V_433 -> V_440 ;
V_433 -> V_440 . V_442 = V_431 -> V_442 ;
V_433 -> V_7 . V_440 = & V_433 -> V_440 . V_7 ;
V_433 -> V_7 . V_164 = V_164 ;
V_433 -> V_7 . V_145 =
( void ( * ) ( struct V_443 * ) ) F_22 ;
}
V_24 = V_42 -> V_36 -> V_431 ( V_42 , V_34 , V_433 ) ;
if ( V_24 ) {
F_113 ( & V_19 -> V_438 , V_160 ) ;
V_164 -> V_439 += sizeof V_433 -> V_440 ;
F_114 ( & V_19 -> V_438 , V_160 ) ;
F_22 ( V_433 ) ;
}
V_147:
F_9 ( & V_19 -> V_26 . V_50 ) ;
return V_24 ;
}
void F_115 ( struct V_18 * V_19 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_17 (crtc, &dev->mode_config.crtc_list, head)
if ( V_42 -> V_36 -> V_444 )
V_42 -> V_36 -> V_444 ( V_42 ) ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
if ( V_2 -> V_36 -> V_444 )
V_2 -> V_36 -> V_444 ( V_2 ) ;
F_17 (connector, &dev->mode_config.connector_list, head)
if ( V_10 -> V_36 -> V_444 )
V_10 -> V_36 -> V_444 ( V_10 ) ;
}
int F_116 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_445 * args = V_162 ;
if ( ! V_19 -> V_446 -> V_447 )
return - V_374 ;
return V_19 -> V_446 -> V_447 ( V_164 , V_19 , args ) ;
}
int F_117 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_448 * args = V_162 ;
if ( ! V_19 -> V_446 -> V_449 )
return - V_374 ;
return V_19 -> V_446 -> V_449 ( V_164 , V_19 , args -> V_282 , & args -> V_450 ) ;
}
int F_118 ( struct V_18 * V_19 ,
void * V_162 , struct V_163 * V_164 )
{
struct V_451 * args = V_162 ;
if ( ! V_19 -> V_446 -> V_452 )
return - V_374 ;
return V_19 -> V_446 -> V_452 ( V_164 , V_19 , args -> V_282 ) ;
}
void F_119 ( T_1 V_305 , unsigned int * V_286 ,
int * V_285 )
{
switch ( V_305 ) {
case V_288 :
case V_308 :
* V_286 = 8 ;
* V_285 = 8 ;
break;
case V_289 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
* V_286 = 15 ;
* V_285 = 16 ;
break;
case V_290 :
case V_324 :
* V_286 = 16 ;
* V_285 = 16 ;
break;
case V_291 :
case V_325 :
* V_286 = 24 ;
* V_285 = 24 ;
break;
case V_292 :
case V_326 :
case V_327 :
case V_328 :
* V_286 = 24 ;
* V_285 = 32 ;
break;
case V_293 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
* V_286 = 30 ;
* V_285 = 32 ;
break;
case V_294 :
case V_329 :
case V_330 :
case V_331 :
* V_286 = 32 ;
* V_285 = 32 ;
break;
default:
F_34 ( L_52 ) ;
* V_286 = 0 ;
* V_285 = 0 ;
break;
}
}
