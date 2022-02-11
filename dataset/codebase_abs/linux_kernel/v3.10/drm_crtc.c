void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
F_4 ( & V_4 -> V_6 , & V_2 -> V_5 . V_6 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
F_6 ( & V_4 -> V_6 ) ;
F_6 ( & V_2 -> V_5 . V_6 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_7 )
return;
F_3 (crtc, &dev->mode_config.crtc_list, head)
F_8 ( ! F_9 ( & V_4 -> V_6 ) ) ;
F_8 ( ! F_9 ( & V_2 -> V_5 . V_6 ) ) ;
}
char * F_10 ( struct V_8 * V_9 )
{
static char V_10 [ 32 ] ;
snprintf ( V_10 , 32 , L_1 ,
V_11 [ V_9 -> V_12 ] . V_13 ,
V_9 -> V_14 . V_15 ) ;
return V_10 ;
}
char * F_11 ( struct V_16 * V_17 )
{
static char V_10 [ 32 ] ;
snprintf ( V_10 , 32 , L_1 ,
V_18 [ V_17 -> V_19 ] . V_13 ,
V_17 -> V_20 ) ;
return V_10 ;
}
char * F_12 ( enum V_21 V_22 )
{
if ( V_22 == V_23 )
return L_2 ;
else if ( V_22 == V_24 )
return L_3 ;
else
return L_4 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_25 * V_26 , T_1 V_27 )
{
int V_28 ;
F_2 ( & V_2 -> V_5 . V_29 ) ;
V_28 = F_14 ( & V_2 -> V_5 . V_30 , V_26 , 1 , 0 , V_31 ) ;
if ( V_28 >= 0 ) {
V_26 -> V_15 = V_28 ;
V_26 -> type = V_27 ;
}
F_6 ( & V_2 -> V_5 . V_29 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_25 * V_32 )
{
F_2 ( & V_2 -> V_5 . V_29 ) ;
F_16 ( & V_2 -> V_5 . V_30 , V_32 -> V_15 ) ;
F_6 ( & V_2 -> V_5 . V_29 ) ;
}
struct V_25 * F_17 ( struct V_1 * V_2 ,
T_1 V_15 , T_1 type )
{
struct V_25 * V_26 = NULL ;
F_8 ( type == V_33 ) ;
F_2 ( & V_2 -> V_5 . V_29 ) ;
V_26 = F_18 ( & V_2 -> V_5 . V_30 , V_15 ) ;
if ( ! V_26 || ( V_26 -> type != type ) || ( V_26 -> V_15 != V_15 ) )
V_26 = NULL ;
F_6 ( & V_2 -> V_5 . V_29 ) ;
return V_26 ;
}
int F_19 ( struct V_1 * V_2 , struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
int V_28 ;
F_2 ( & V_2 -> V_5 . V_38 ) ;
F_20 ( & V_35 -> V_39 ) ;
F_21 ( & V_35 -> V_40 ) ;
V_35 -> V_2 = V_2 ;
V_35 -> V_37 = V_37 ;
V_28 = F_13 ( V_2 , & V_35 -> V_14 , V_33 ) ;
if ( V_28 )
goto V_41;
F_22 ( V_35 ) ;
V_2 -> V_5 . V_42 ++ ;
F_23 ( & V_35 -> V_43 , & V_2 -> V_5 . V_44 ) ;
V_41:
F_6 ( & V_2 -> V_5 . V_38 ) ;
return 0 ;
}
static void F_24 ( struct V_45 * V_45 )
{
struct V_34 * V_35 =
F_25 ( V_45 , struct V_34 , V_39 ) ;
V_35 -> V_37 -> V_46 ( V_35 ) ;
}
static struct V_34 * F_26 ( struct V_1 * V_2 ,
T_1 V_15 )
{
struct V_25 * V_26 = NULL ;
struct V_34 * V_35 ;
F_2 ( & V_2 -> V_5 . V_29 ) ;
V_26 = F_18 ( & V_2 -> V_5 . V_30 , V_15 ) ;
if ( ! V_26 || ( V_26 -> type != V_33 ) || ( V_26 -> V_15 != V_15 ) )
V_35 = NULL ;
else
V_35 = F_27 ( V_26 ) ;
F_6 ( & V_2 -> V_5 . V_29 ) ;
return V_35 ;
}
struct V_34 * F_28 ( struct V_1 * V_2 ,
T_1 V_15 )
{
struct V_34 * V_35 ;
F_2 ( & V_2 -> V_5 . V_38 ) ;
V_35 = F_26 ( V_2 , V_15 ) ;
if ( V_35 )
F_22 ( V_35 ) ;
F_6 ( & V_2 -> V_5 . V_38 ) ;
return V_35 ;
}
void F_29 ( struct V_34 * V_35 )
{
F_30 ( L_5 , V_35 -> V_14 . V_15 ) ;
F_31 ( & V_35 -> V_39 , F_24 ) ;
}
void F_22 ( struct V_34 * V_35 )
{
F_30 ( L_5 , V_35 -> V_14 . V_15 ) ;
F_32 ( & V_35 -> V_39 ) ;
}
static void F_33 ( struct V_45 * V_45 )
{
F_34 () ;
}
static void F_35 ( struct V_34 * V_35 )
{
F_30 ( L_5 , V_35 -> V_14 . V_15 ) ;
F_31 ( & V_35 -> V_39 , F_33 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
F_2 ( & V_2 -> V_5 . V_29 ) ;
F_16 ( & V_2 -> V_5 . V_30 , V_35 -> V_14 . V_15 ) ;
F_6 ( & V_2 -> V_5 . V_29 ) ;
V_35 -> V_14 . V_15 = 0 ;
F_35 ( V_35 ) ;
}
void F_37 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_38 ) ;
F_36 ( V_2 , V_35 ) ;
F_6 ( & V_2 -> V_5 . V_38 ) ;
}
void F_38 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_38 ) ;
F_39 ( & V_35 -> V_43 ) ;
V_2 -> V_5 . V_42 -- ;
F_6 ( & V_2 -> V_5 . V_38 ) ;
}
void F_40 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 ;
struct V_47 * V_48 ;
struct V_49 V_50 ;
int V_28 ;
F_8 ( ! F_41 ( & V_35 -> V_40 ) ) ;
if ( F_42 ( & V_35 -> V_39 . V_39 ) > 1 ) {
F_1 ( V_2 ) ;
F_3 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_4 -> V_35 == V_35 ) {
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_4 = V_4 ;
V_50 . V_35 = NULL ;
V_28 = F_43 ( & V_50 ) ;
if ( V_28 )
F_44 ( L_6 , V_4 ) ;
}
}
F_3 (plane, &dev->mode_config.plane_list, head) {
if ( V_48 -> V_35 == V_35 ) {
V_28 = V_48 -> V_37 -> V_51 ( V_48 ) ;
if ( V_28 )
F_44 ( L_7 ) ;
F_35 ( V_48 -> V_35 ) ;
V_48 -> V_35 = NULL ;
V_48 -> V_4 = NULL ;
}
}
F_5 ( V_2 ) ;
}
F_29 ( V_35 ) ;
}
int F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_52 * V_37 )
{
int V_28 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_37 = V_37 ;
V_4 -> V_53 = false ;
F_1 ( V_2 ) ;
F_46 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_6 , & V_2 -> V_5 . V_6 ) ;
V_28 = F_13 ( V_2 , & V_4 -> V_14 , V_54 ) ;
if ( V_28 )
goto V_41;
V_4 -> V_14 . V_55 = & V_4 -> V_55 ;
F_47 ( & V_4 -> V_43 , & V_2 -> V_5 . V_56 ) ;
V_2 -> V_5 . V_57 ++ ;
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
void F_48 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_49 ( V_4 -> V_58 ) ;
V_4 -> V_58 = NULL ;
F_15 ( V_2 , & V_4 -> V_14 ) ;
F_39 ( & V_4 -> V_43 ) ;
V_2 -> V_5 . V_57 -- ;
}
void F_50 ( struct V_16 * V_17 ,
struct V_59 * V_60 )
{
F_23 ( & V_60 -> V_43 , & V_17 -> V_61 ) ;
}
void F_51 ( struct V_16 * V_17 ,
struct V_59 * V_60 )
{
F_39 ( & V_60 -> V_43 ) ;
F_52 ( V_17 -> V_2 , V_60 ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const struct V_62 * V_37 ,
int V_19 )
{
int V_28 ;
F_1 ( V_2 ) ;
V_28 = F_13 ( V_2 , & V_17 -> V_14 , V_63 ) ;
if ( V_28 )
goto V_41;
V_17 -> V_14 . V_55 = & V_17 -> V_55 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_37 = V_37 ;
V_17 -> V_19 = V_19 ;
V_17 -> V_20 =
++ V_18 [ V_19 ] . V_64 ;
F_21 ( & V_17 -> V_61 ) ;
F_21 ( & V_17 -> V_65 ) ;
V_17 -> V_66 = NULL ;
V_17 -> V_22 = V_67 ;
F_47 ( & V_17 -> V_43 , & V_2 -> V_5 . V_68 ) ;
V_2 -> V_5 . V_69 ++ ;
if ( V_19 != V_70 )
F_54 ( & V_17 -> V_14 ,
V_2 -> V_5 . V_71 ,
0 ) ;
F_54 ( & V_17 -> V_14 ,
V_2 -> V_5 . V_72 , 0 ) ;
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
void F_55 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_59 * V_60 , * V_73 ;
F_56 (mode, t, &connector->probed_modes, head)
F_51 ( V_17 , V_60 ) ;
F_56 (mode, t, &connector->modes, head)
F_51 ( V_17 , V_60 ) ;
F_15 ( V_2 , & V_17 -> V_14 ) ;
F_39 ( & V_17 -> V_43 ) ;
V_2 -> V_5 . V_69 -- ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
F_3 (connector, &dev->mode_config.connector_list, head)
F_58 ( V_17 ) ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_74 * V_37 ,
int V_12 )
{
int V_28 ;
F_1 ( V_2 ) ;
V_28 = F_13 ( V_2 , & V_9 -> V_14 , V_75 ) ;
if ( V_28 )
goto V_41;
V_9 -> V_2 = V_2 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_37 = V_37 ;
F_47 ( & V_9 -> V_43 , & V_2 -> V_5 . V_76 ) ;
V_2 -> V_5 . V_77 ++ ;
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
void F_60 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
F_1 ( V_2 ) ;
F_15 ( V_2 , & V_9 -> V_14 ) ;
F_39 ( & V_9 -> V_43 ) ;
V_2 -> V_5 . V_77 -- ;
F_5 ( V_2 ) ;
}
int F_61 ( struct V_1 * V_2 , struct V_47 * V_48 ,
unsigned long V_78 ,
const struct V_79 * V_37 ,
const T_1 * V_80 , T_1 V_81 ,
bool V_82 )
{
int V_28 ;
F_1 ( V_2 ) ;
V_28 = F_13 ( V_2 , & V_48 -> V_14 , V_83 ) ;
if ( V_28 )
goto V_41;
V_48 -> V_14 . V_55 = & V_48 -> V_55 ;
V_48 -> V_2 = V_2 ;
V_48 -> V_37 = V_37 ;
V_48 -> V_84 = F_62 ( sizeof( T_1 ) * V_81 ,
V_31 ) ;
if ( ! V_48 -> V_84 ) {
F_63 ( L_8 ) ;
F_15 ( V_2 , & V_48 -> V_14 ) ;
V_28 = - V_85 ;
goto V_41;
}
memcpy ( V_48 -> V_84 , V_80 , V_81 * sizeof( T_1 ) ) ;
V_48 -> V_81 = V_81 ;
V_48 -> V_78 = V_78 ;
if ( ! V_82 ) {
F_47 ( & V_48 -> V_43 , & V_2 -> V_5 . V_86 ) ;
V_2 -> V_5 . V_87 ++ ;
} else {
F_21 ( & V_48 -> V_43 ) ;
}
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
void F_64 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
F_1 ( V_2 ) ;
F_49 ( V_48 -> V_84 ) ;
F_15 ( V_2 , & V_48 -> V_14 ) ;
if ( ! F_41 ( & V_48 -> V_43 ) ) {
F_39 ( & V_48 -> V_43 ) ;
V_2 -> V_5 . V_87 -- ;
}
F_5 ( V_2 ) ;
}
struct V_59 * F_65 ( struct V_1 * V_2 )
{
struct V_59 * V_88 ;
V_88 = F_66 ( sizeof( struct V_59 ) , V_31 ) ;
if ( ! V_88 )
return NULL ;
if ( F_13 ( V_2 , & V_88 -> V_14 , V_89 ) ) {
F_49 ( V_88 ) ;
return NULL ;
}
return V_88 ;
}
void F_52 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
if ( ! V_60 )
return;
F_15 ( V_2 , & V_60 -> V_14 ) ;
F_49 ( V_60 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
struct V_90 * V_92 ;
V_91 = F_68 ( V_2 , V_93 |
V_94 ,
L_9 , 0 ) ;
V_2 -> V_5 . V_71 = V_91 ;
V_92 = F_69 ( V_2 , 0 ,
L_10 , V_95 ,
F_70 ( V_95 ) ) ;
V_2 -> V_5 . V_72 = V_92 ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_90 * V_96 ;
struct V_90 * V_97 ;
if ( V_2 -> V_5 . V_98 )
return 0 ;
V_96 =
F_69 ( V_2 , 0 ,
L_11 ,
V_99 ,
F_70 ( V_99 ) ) ;
V_2 -> V_5 . V_98 = V_96 ;
V_97 = F_69 ( V_2 , V_94 ,
L_12 ,
V_100 ,
F_70 ( V_100 ) ) ;
V_2 -> V_5 . V_101 = V_97 ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 , int V_102 ,
char * V_65 [] )
{
struct V_90 * V_103 ;
struct V_90 * V_104 ;
int V_105 ;
if ( V_2 -> V_5 . V_106 )
return 0 ;
V_103 = F_69 ( V_2 , 0 ,
L_11 ,
V_107 ,
F_70 ( V_107 ) ) ;
V_2 -> V_5 . V_106 = V_103 ;
V_104 =
F_69 ( V_2 , V_94 ,
L_12 ,
V_108 ,
F_70 ( V_108 ) ) ;
V_2 -> V_5 . V_109 = V_104 ;
V_2 -> V_5 . V_110 =
F_73 ( V_2 , 0 , L_13 , 0 , 100 ) ;
V_2 -> V_5 . V_111 =
F_73 ( V_2 , 0 , L_14 , 0 , 100 ) ;
V_2 -> V_5 . V_112 =
F_73 ( V_2 , 0 , L_15 , 0 , 100 ) ;
V_2 -> V_5 . V_113 =
F_73 ( V_2 , 0 , L_16 , 0 , 100 ) ;
V_2 -> V_5 . V_114 =
F_68 ( V_2 , V_115 ,
L_17 , V_102 ) ;
for ( V_105 = 0 ; V_105 < V_102 ; V_105 ++ )
F_74 ( V_2 -> V_5 . V_114 , V_105 ,
V_105 , V_65 [ V_105 ] ) ;
V_2 -> V_5 . V_116 =
F_73 ( V_2 , 0 , L_18 , 0 , 100 ) ;
V_2 -> V_5 . V_117 =
F_73 ( V_2 , 0 , L_19 , 0 , 100 ) ;
V_2 -> V_5 . V_118 =
F_73 ( V_2 , 0 , L_20 , 0 , 100 ) ;
V_2 -> V_5 . V_119 =
F_73 ( V_2 , 0 , L_21 , 0 , 100 ) ;
V_2 -> V_5 . V_120 =
F_73 ( V_2 , 0 , L_22 , 0 , 100 ) ;
V_2 -> V_5 . V_121 =
F_73 ( V_2 , 0 , L_23 , 0 , 100 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 )
{
struct V_90 * V_122 ;
if ( V_2 -> V_5 . V_123 )
return 0 ;
V_122 =
F_69 ( V_2 , 0 , L_24 ,
V_124 ,
F_70 ( V_124 ) ) ;
V_2 -> V_5 . V_123 = V_122 ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_90 * V_125 ;
if ( V_2 -> V_5 . V_126 )
return 0 ;
V_125 =
F_69 ( V_2 , 0 , L_25 ,
V_127 ,
F_70 ( V_127 ) ) ;
V_2 -> V_5 . V_126 = V_125 ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 )
{
struct V_90 * V_128 ;
if ( V_2 -> V_5 . V_129 )
return 0 ;
V_128 =
F_69 ( V_2 , V_94 ,
L_26 ,
V_130 ,
F_70 ( V_130 ) ) ;
V_2 -> V_5 . V_129 = V_128 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_131 * V_132 )
{
T_1 V_133 = 0 ;
V_133 += V_2 -> V_5 . V_57 ;
V_133 += V_2 -> V_5 . V_69 ;
V_133 += V_2 -> V_5 . V_77 ;
V_132 -> V_134 = F_66 ( V_133 * sizeof( T_1 ) , V_31 ) ;
if ( ! V_132 -> V_134 )
return - V_85 ;
V_132 -> V_135 = 0 ;
V_132 -> V_136 = 0 ;
V_132 -> V_137 = 0 ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
int V_28 ;
if ( ( V_28 = F_78 ( V_2 , V_132 ) ) )
return V_28 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
V_132 -> V_134 [ V_132 -> V_135 ++ ] = V_4 -> V_14 . V_15 ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
V_132 -> V_134 [ V_132 -> V_135 + V_132 -> V_137 ++ ] =
V_9 -> V_14 . V_15 ;
F_3 (connector, &dev->mode_config.connector_list, head)
V_132 -> V_134 [ V_132 -> V_135 + V_132 -> V_137 +
V_132 -> V_136 ++ ] = V_17 -> V_14 . V_15 ;
return 0 ;
}
static void F_80 ( struct V_138 * V_41 ,
const struct V_59 * V_139 )
{
F_81 ( V_139 -> V_140 > V_141 || V_139 -> V_142 > V_141 ||
V_139 -> V_143 > V_141 || V_139 -> V_144 > V_141 ||
V_139 -> V_145 > V_141 || V_139 -> V_146 > V_141 ||
V_139 -> V_147 > V_141 || V_139 -> V_148 > V_141 ||
V_139 -> V_149 > V_141 || V_139 -> V_150 > V_141 ,
L_27 ) ;
V_41 -> clock = V_139 -> clock ;
V_41 -> V_140 = V_139 -> V_140 ;
V_41 -> V_142 = V_139 -> V_142 ;
V_41 -> V_143 = V_139 -> V_143 ;
V_41 -> V_144 = V_139 -> V_144 ;
V_41 -> V_145 = V_139 -> V_145 ;
V_41 -> V_146 = V_139 -> V_146 ;
V_41 -> V_147 = V_139 -> V_147 ;
V_41 -> V_148 = V_139 -> V_148 ;
V_41 -> V_149 = V_139 -> V_149 ;
V_41 -> V_150 = V_139 -> V_150 ;
V_41 -> V_151 = V_139 -> V_151 ;
V_41 -> V_152 = V_139 -> V_152 ;
V_41 -> type = V_139 -> type ;
strncpy ( V_41 -> V_13 , V_139 -> V_13 , V_153 ) ;
V_41 -> V_13 [ V_153 - 1 ] = 0 ;
}
static int F_82 ( struct V_59 * V_41 ,
const struct V_138 * V_139 )
{
if ( V_139 -> clock > V_154 || V_139 -> V_151 > V_154 )
return - V_155 ;
V_41 -> clock = V_139 -> clock ;
V_41 -> V_140 = V_139 -> V_140 ;
V_41 -> V_142 = V_139 -> V_142 ;
V_41 -> V_143 = V_139 -> V_143 ;
V_41 -> V_144 = V_139 -> V_144 ;
V_41 -> V_145 = V_139 -> V_145 ;
V_41 -> V_146 = V_139 -> V_146 ;
V_41 -> V_147 = V_139 -> V_147 ;
V_41 -> V_148 = V_139 -> V_148 ;
V_41 -> V_149 = V_139 -> V_149 ;
V_41 -> V_150 = V_139 -> V_150 ;
V_41 -> V_151 = V_139 -> V_151 ;
V_41 -> V_152 = V_139 -> V_152 ;
V_41 -> type = V_139 -> type ;
strncpy ( V_41 -> V_13 , V_139 -> V_13 , V_153 ) ;
V_41 -> V_13 [ V_153 - 1 ] = 0 ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_159 * V_160 = V_156 ;
struct V_161 * V_162 ;
struct V_34 * V_35 ;
struct V_16 * V_17 ;
struct V_3 * V_4 ;
struct V_8 * V_9 ;
int V_28 = 0 ;
int V_163 = 0 ;
int V_164 = 0 ;
int V_165 = 0 ;
int V_166 = 0 ;
int V_167 = 0 , V_105 ;
T_1 T_2 * V_168 ;
T_1 T_2 * V_169 ;
T_1 T_2 * V_170 ;
T_1 T_2 * V_171 ;
struct V_131 * V_172 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_2 ( & V_158 -> V_175 ) ;
F_85 (lh, &file_priv->fbs)
V_165 ++ ;
if ( V_160 -> V_176 >= V_165 ) {
V_167 = 0 ;
V_168 = ( T_1 T_2 * ) ( unsigned long ) V_160 -> V_177 ;
F_3 (fb, &file_priv->fbs, filp_head) {
if ( F_86 ( V_35 -> V_14 . V_15 , V_168 + V_167 ) ) {
F_6 ( & V_158 -> V_175 ) ;
return - V_178 ;
}
V_167 ++ ;
}
}
V_160 -> V_176 = V_165 ;
F_6 ( & V_158 -> V_175 ) ;
F_1 ( V_2 ) ;
V_172 = & V_158 -> V_179 -> V_180 -> V_172 ;
if ( V_158 -> V_179 -> V_180 -> type == V_181 ) {
F_85 (lh, &dev->mode_config.crtc_list)
V_164 ++ ;
F_85 (lh, &dev->mode_config.connector_list)
V_163 ++ ;
F_85 (lh, &dev->mode_config.encoder_list)
V_166 ++ ;
} else {
V_164 = V_172 -> V_135 ;
V_163 = V_172 -> V_136 ;
V_166 = V_172 -> V_137 ;
}
V_160 -> V_182 = V_2 -> V_5 . V_182 ;
V_160 -> V_183 = V_2 -> V_5 . V_183 ;
V_160 -> V_184 = V_2 -> V_5 . V_184 ;
V_160 -> V_185 = V_2 -> V_5 . V_185 ;
if ( V_160 -> V_186 >= V_164 ) {
V_167 = 0 ;
V_169 = ( T_1 T_2 * ) ( unsigned long ) V_160 -> V_187 ;
if ( V_158 -> V_179 -> V_180 -> type == V_181 ) {
F_3 (crtc, &dev->mode_config.crtc_list,
head) {
F_63 ( L_28 , V_4 -> V_14 . V_15 ) ;
if ( F_86 ( V_4 -> V_14 . V_15 , V_169 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
} else {
for ( V_105 = 0 ; V_105 < V_172 -> V_135 ; V_105 ++ ) {
if ( F_86 ( V_172 -> V_134 [ V_105 ] ,
V_169 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
}
}
V_160 -> V_186 = V_164 ;
if ( V_160 -> V_188 >= V_166 ) {
V_167 = 0 ;
V_171 = ( T_1 T_2 * ) ( unsigned long ) V_160 -> V_189 ;
if ( V_158 -> V_179 -> V_180 -> type == V_181 ) {
F_3 (encoder,
&dev->mode_config.encoder_list,
head) {
F_63 ( L_29 , V_9 -> V_14 . V_15 ,
F_10 ( V_9 ) ) ;
if ( F_86 ( V_9 -> V_14 . V_15 , V_171 +
V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
} else {
for ( V_105 = V_172 -> V_135 ; V_105 < V_172 -> V_135 + V_172 -> V_137 ; V_105 ++ ) {
if ( F_86 ( V_172 -> V_134 [ V_105 ] ,
V_171 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
}
}
V_160 -> V_188 = V_166 ;
if ( V_160 -> V_190 >= V_163 ) {
V_167 = 0 ;
V_170 = ( T_1 T_2 * ) ( unsigned long ) V_160 -> V_191 ;
if ( V_158 -> V_179 -> V_180 -> type == V_181 ) {
F_3 (connector,
&dev->mode_config.connector_list,
head) {
F_63 ( L_30 ,
V_17 -> V_14 . V_15 ,
F_11 ( V_17 ) ) ;
if ( F_86 ( V_17 -> V_14 . V_15 ,
V_170 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
} else {
int V_192 = V_172 -> V_135 +
V_172 -> V_137 ;
for ( V_105 = V_192 ; V_105 < V_192 + V_172 -> V_136 ; V_105 ++ ) {
if ( F_86 ( V_172 -> V_134 [ V_105 ] ,
V_170 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
}
}
V_160 -> V_190 = V_163 ;
F_63 ( L_31 , V_160 -> V_186 ,
V_160 -> V_190 , V_160 -> V_188 ) ;
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_87 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_193 * V_194 = V_156 ;
struct V_3 * V_4 ;
struct V_25 * V_26 ;
int V_28 = 0 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_26 = F_17 ( V_2 , V_194 -> V_169 ,
V_54 ) ;
if ( ! V_26 ) {
V_28 = - V_174 ;
goto V_41;
}
V_4 = F_88 ( V_26 ) ;
V_194 -> V_195 = V_4 -> V_195 ;
V_194 -> V_196 = V_4 -> V_196 ;
V_194 -> V_197 = V_4 -> V_197 ;
if ( V_4 -> V_35 )
V_194 -> V_168 = V_4 -> V_35 -> V_14 . V_15 ;
else
V_194 -> V_168 = 0 ;
if ( V_4 -> V_198 ) {
F_80 ( & V_194 -> V_60 , & V_4 -> V_60 ) ;
V_194 -> V_199 = 1 ;
} else {
V_194 -> V_199 = 0 ;
}
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_89 ( struct V_1 * V_2 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_200 * V_201 = V_156 ;
struct V_25 * V_26 ;
struct V_16 * V_17 ;
struct V_59 * V_60 ;
int V_202 = 0 ;
int V_203 = 0 ;
int V_204 = 0 ;
int V_28 = 0 ;
int V_167 = 0 ;
int V_105 ;
struct V_138 V_205 ;
struct V_138 T_2 * V_206 ;
T_1 T_2 * V_207 ;
T_3 T_2 * V_208 ;
T_1 T_2 * V_209 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
memset ( & V_205 , 0 , sizeof( struct V_138 ) ) ;
F_63 ( L_32 , V_201 -> V_170 ) ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_26 = F_17 ( V_2 , V_201 -> V_170 ,
V_63 ) ;
if ( ! V_26 ) {
V_28 = - V_174 ;
goto V_41;
}
V_17 = F_90 ( V_26 ) ;
V_203 = V_17 -> V_55 . V_64 ;
for ( V_105 = 0 ; V_105 < V_210 ; V_105 ++ ) {
if ( V_17 -> V_211 [ V_105 ] != 0 ) {
V_204 ++ ;
}
}
if ( V_201 -> V_212 == 0 ) {
V_17 -> V_37 -> V_213 ( V_17 ,
V_2 -> V_5 . V_184 ,
V_2 -> V_5 . V_182 ) ;
}
F_3 (mode, &connector->modes, head)
V_202 ++ ;
V_201 -> V_170 = V_17 -> V_14 . V_15 ;
V_201 -> V_19 = V_17 -> V_19 ;
V_201 -> V_20 = V_17 -> V_20 ;
V_201 -> V_214 = V_17 -> V_215 . V_216 ;
V_201 -> V_217 = V_17 -> V_215 . V_218 ;
V_201 -> V_219 = V_17 -> V_215 . V_220 ;
V_201 -> V_221 = V_17 -> V_22 ;
if ( V_17 -> V_9 )
V_201 -> V_171 = V_17 -> V_9 -> V_14 . V_15 ;
else
V_201 -> V_171 = 0 ;
if ( ( V_201 -> V_212 >= V_202 ) && V_202 ) {
V_167 = 0 ;
V_206 = (struct V_138 T_2 * ) ( unsigned long ) V_201 -> V_222 ;
F_3 (mode, &connector->modes, head) {
F_80 ( & V_205 , V_60 ) ;
if ( F_91 ( V_206 + V_167 ,
& V_205 , sizeof( V_205 ) ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
}
V_201 -> V_212 = V_202 ;
if ( ( V_201 -> V_223 >= V_203 ) && V_203 ) {
V_167 = 0 ;
V_207 = ( T_1 T_2 * ) ( unsigned long ) ( V_201 -> V_224 ) ;
V_208 = ( T_3 T_2 * ) ( unsigned long ) ( V_201 -> V_225 ) ;
for ( V_105 = 0 ; V_105 < V_17 -> V_55 . V_64 ; V_105 ++ ) {
if ( F_86 ( V_17 -> V_55 . V_226 [ V_105 ] ,
V_207 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
if ( F_86 ( V_17 -> V_55 . V_227 [ V_105 ] ,
V_208 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
}
V_201 -> V_223 = V_203 ;
if ( ( V_201 -> V_188 >= V_204 ) && V_204 ) {
V_167 = 0 ;
V_209 = ( T_1 T_2 * ) ( unsigned long ) ( V_201 -> V_228 ) ;
for ( V_105 = 0 ; V_105 < V_210 ; V_105 ++ ) {
if ( V_17 -> V_211 [ V_105 ] != 0 ) {
if ( F_86 ( V_17 -> V_211 [ V_105 ] ,
V_209 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
}
}
V_201 -> V_188 = V_204 ;
V_41:
F_6 ( & V_2 -> V_5 . V_6 ) ;
return V_28 ;
}
int F_92 ( struct V_1 * V_2 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_229 * V_230 = V_156 ;
struct V_25 * V_26 ;
struct V_8 * V_9 ;
int V_28 = 0 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_26 = F_17 ( V_2 , V_230 -> V_171 ,
V_75 ) ;
if ( ! V_26 ) {
V_28 = - V_174 ;
goto V_41;
}
V_9 = F_93 ( V_26 ) ;
if ( V_9 -> V_4 )
V_230 -> V_169 = V_9 -> V_4 -> V_14 . V_15 ;
else
V_230 -> V_169 = 0 ;
V_230 -> V_12 = V_9 -> V_12 ;
V_230 -> V_171 = V_9 -> V_14 . V_15 ;
V_230 -> V_78 = V_9 -> V_78 ;
V_230 -> V_231 = V_9 -> V_231 ;
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_94 ( struct V_1 * V_2 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_232 * V_233 = V_156 ;
struct V_234 * V_235 ;
struct V_47 * V_48 ;
T_1 T_2 * V_236 ;
int V_167 = 0 , V_28 = 0 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_235 = & V_2 -> V_5 ;
if ( V_235 -> V_87 &&
( V_233 -> V_237 >= V_235 -> V_87 ) ) {
V_236 = ( T_1 T_2 * ) ( unsigned long ) V_233 -> V_238 ;
F_3 (plane, &config->plane_list, head) {
if ( F_86 ( V_48 -> V_14 . V_15 , V_236 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
}
V_233 -> V_237 = V_235 -> V_87 ;
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_95 ( struct V_1 * V_2 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_239 * V_233 = V_156 ;
struct V_25 * V_26 ;
struct V_47 * V_48 ;
T_1 T_2 * V_240 ;
int V_28 = 0 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_26 = F_17 ( V_2 , V_233 -> V_241 ,
V_83 ) ;
if ( ! V_26 ) {
V_28 = - V_242 ;
goto V_41;
}
V_48 = F_96 ( V_26 ) ;
if ( V_48 -> V_4 )
V_233 -> V_169 = V_48 -> V_4 -> V_14 . V_15 ;
else
V_233 -> V_169 = 0 ;
if ( V_48 -> V_35 )
V_233 -> V_168 = V_48 -> V_35 -> V_14 . V_15 ;
else
V_233 -> V_168 = 0 ;
V_233 -> V_241 = V_48 -> V_14 . V_15 ;
V_233 -> V_78 = V_48 -> V_78 ;
V_233 -> V_197 = V_48 -> V_197 ;
if ( V_48 -> V_81 &&
( V_233 -> V_243 >= V_48 -> V_81 ) ) {
V_240 = ( T_1 T_2 * ) ( unsigned long ) V_233 -> V_244 ;
if ( F_91 ( V_240 ,
V_48 -> V_84 ,
sizeof( T_1 ) * V_48 -> V_81 ) ) {
V_28 = - V_178 ;
goto V_41;
}
}
V_233 -> V_243 = V_48 -> V_81 ;
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_97 ( struct V_1 * V_2 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_245 * V_246 = V_156 ;
struct V_25 * V_26 ;
struct V_47 * V_48 ;
struct V_3 * V_4 ;
struct V_34 * V_35 = NULL , * V_247 = NULL ;
int V_28 = 0 ;
unsigned int V_248 , V_249 ;
int V_105 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
V_26 = F_17 ( V_2 , V_246 -> V_241 ,
V_83 ) ;
if ( ! V_26 ) {
F_63 ( L_33 ,
V_246 -> V_241 ) ;
return - V_242 ;
}
V_48 = F_96 ( V_26 ) ;
if ( ! V_246 -> V_168 ) {
F_1 ( V_2 ) ;
V_247 = V_48 -> V_35 ;
V_48 -> V_37 -> V_51 ( V_48 ) ;
V_48 -> V_4 = NULL ;
V_48 -> V_35 = NULL ;
F_5 ( V_2 ) ;
goto V_41;
}
V_26 = F_17 ( V_2 , V_246 -> V_169 ,
V_54 ) ;
if ( ! V_26 ) {
F_63 ( L_34 ,
V_246 -> V_169 ) ;
V_28 = - V_242 ;
goto V_41;
}
V_4 = F_88 ( V_26 ) ;
V_35 = F_28 ( V_2 , V_246 -> V_168 ) ;
if ( ! V_35 ) {
F_63 ( L_35 ,
V_246 -> V_168 ) ;
V_28 = - V_242 ;
goto V_41;
}
for ( V_105 = 0 ; V_105 < V_48 -> V_81 ; V_105 ++ )
if ( V_35 -> V_250 == V_48 -> V_84 [ V_105 ] )
break;
if ( V_105 == V_48 -> V_81 ) {
F_63 ( L_36 , V_35 -> V_250 ) ;
V_28 = - V_174 ;
goto V_41;
}
V_248 = V_35 -> V_251 << 16 ;
V_249 = V_35 -> V_252 << 16 ;
if ( V_246 -> V_253 > V_248 ||
V_246 -> V_254 > V_248 - V_246 -> V_253 ||
V_246 -> V_255 > V_249 ||
V_246 -> V_256 > V_249 - V_246 -> V_255 ) {
F_63 ( L_37
L_38 ,
V_246 -> V_253 >> 16 ,
( ( V_246 -> V_253 & 0xffff ) * 15625 ) >> 10 ,
V_246 -> V_255 >> 16 ,
( ( V_246 -> V_255 & 0xffff ) * 15625 ) >> 10 ,
V_246 -> V_254 >> 16 ,
( ( V_246 -> V_254 & 0xffff ) * 15625 ) >> 10 ,
V_246 -> V_256 >> 16 ,
( ( V_246 -> V_256 & 0xffff ) * 15625 ) >> 10 ) ;
V_28 = - V_257 ;
goto V_41;
}
if ( V_246 -> V_258 > V_154 ||
V_246 -> V_259 > V_154 - ( V_260 ) V_246 -> V_258 ||
V_246 -> V_261 > V_154 ||
V_246 -> V_262 > V_154 - ( V_260 ) V_246 -> V_261 ) {
F_63 ( L_39 ,
V_246 -> V_258 , V_246 -> V_261 ,
V_246 -> V_259 , V_246 -> V_262 ) ;
V_28 = - V_155 ;
goto V_41;
}
F_1 ( V_2 ) ;
V_28 = V_48 -> V_37 -> V_263 ( V_48 , V_4 , V_35 ,
V_246 -> V_259 , V_246 -> V_262 ,
V_246 -> V_258 , V_246 -> V_261 ,
V_246 -> V_254 , V_246 -> V_256 ,
V_246 -> V_253 , V_246 -> V_255 ) ;
if ( ! V_28 ) {
V_247 = V_48 -> V_35 ;
V_48 -> V_4 = V_4 ;
V_48 -> V_35 = V_35 ;
V_35 = NULL ;
}
F_5 ( V_2 ) ;
V_41:
if ( V_35 )
F_29 ( V_35 ) ;
if ( V_247 )
F_29 ( V_247 ) ;
return V_28 ;
}
int F_43 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = V_50 -> V_4 ;
struct V_34 * V_35 , * V_247 ;
int V_28 ;
V_247 = V_4 -> V_35 ;
V_35 = V_50 -> V_35 ;
V_28 = V_4 -> V_37 -> V_264 ( V_50 ) ;
if ( V_28 == 0 ) {
if ( V_247 )
F_29 ( V_247 ) ;
if ( V_35 )
F_22 ( V_35 ) ;
}
return V_28 ;
}
int F_98 ( struct V_1 * V_2 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_234 * V_235 = & V_2 -> V_5 ;
struct V_193 * V_265 = V_156 ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
struct V_16 * * V_266 = NULL , * V_17 ;
struct V_34 * V_35 = NULL ;
struct V_59 * V_60 = NULL ;
struct V_49 V_50 ;
T_1 T_2 * V_267 ;
int V_28 ;
int V_105 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
if ( V_265 -> V_195 > V_154 || V_265 -> V_196 > V_154 )
return - V_155 ;
F_1 ( V_2 ) ;
V_26 = F_17 ( V_2 , V_265 -> V_169 ,
V_54 ) ;
if ( ! V_26 ) {
F_63 ( L_40 , V_265 -> V_169 ) ;
V_28 = - V_174 ;
goto V_41;
}
V_4 = F_88 ( V_26 ) ;
F_63 ( L_28 , V_4 -> V_14 . V_15 ) ;
if ( V_265 -> V_199 ) {
int V_140 , V_146 ;
if ( V_265 -> V_168 == - 1 ) {
if ( ! V_4 -> V_35 ) {
F_63 ( L_41 ) ;
V_28 = - V_174 ;
goto V_41;
}
V_35 = V_4 -> V_35 ;
F_22 ( V_35 ) ;
} else {
V_35 = F_28 ( V_2 , V_265 -> V_168 ) ;
if ( ! V_35 ) {
F_63 ( L_42 ,
V_265 -> V_168 ) ;
V_28 = - V_174 ;
goto V_41;
}
}
V_60 = F_65 ( V_2 ) ;
if ( ! V_60 ) {
V_28 = - V_85 ;
goto V_41;
}
V_28 = F_82 ( V_60 , & V_265 -> V_60 ) ;
if ( V_28 ) {
F_63 ( L_43 ) ;
goto V_41;
}
F_99 ( V_60 , V_268 ) ;
V_140 = V_60 -> V_140 ;
V_146 = V_60 -> V_146 ;
if ( V_4 -> V_53 )
F_100 ( V_140 , V_146 ) ;
if ( V_140 > V_35 -> V_251 ||
V_146 > V_35 -> V_252 ||
V_265 -> V_195 > V_35 -> V_251 - V_140 ||
V_265 -> V_196 > V_35 -> V_252 - V_146 ) {
F_63 ( L_44 ,
V_35 -> V_251 , V_35 -> V_252 ,
V_140 , V_146 , V_265 -> V_195 , V_265 -> V_196 ,
V_4 -> V_53 ? L_45 : L_46 ) ;
V_28 = - V_257 ;
goto V_41;
}
}
if ( V_265 -> V_190 == 0 && V_60 ) {
F_63 ( L_47 ) ;
V_28 = - V_174 ;
goto V_41;
}
if ( V_265 -> V_190 > 0 && ( ! V_60 || ! V_35 ) ) {
F_63 ( L_48 ,
V_265 -> V_190 ) ;
V_28 = - V_174 ;
goto V_41;
}
if ( V_265 -> V_190 > 0 ) {
T_4 V_269 ;
if ( V_265 -> V_190 > V_235 -> V_69 ) {
V_28 = - V_174 ;
goto V_41;
}
V_266 = F_62 ( V_265 -> V_190 *
sizeof( struct V_16 * ) ,
V_31 ) ;
if ( ! V_266 ) {
V_28 = - V_85 ;
goto V_41;
}
for ( V_105 = 0 ; V_105 < V_265 -> V_190 ; V_105 ++ ) {
V_267 = ( T_1 T_2 * ) ( unsigned long ) V_265 -> V_267 ;
if ( F_101 ( V_269 , & V_267 [ V_105 ] ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_26 = F_17 ( V_2 , V_269 ,
V_63 ) ;
if ( ! V_26 ) {
F_63 ( L_49 ,
V_269 ) ;
V_28 = - V_174 ;
goto V_41;
}
V_17 = F_90 ( V_26 ) ;
F_63 ( L_30 ,
V_17 -> V_14 . V_15 ,
F_11 ( V_17 ) ) ;
V_266 [ V_105 ] = V_17 ;
}
}
V_50 . V_4 = V_4 ;
V_50 . V_195 = V_265 -> V_195 ;
V_50 . V_196 = V_265 -> V_196 ;
V_50 . V_60 = V_60 ;
V_50 . V_270 = V_266 ;
V_50 . V_136 = V_265 -> V_190 ;
V_50 . V_35 = V_35 ;
V_28 = F_43 ( & V_50 ) ;
V_41:
if ( V_35 )
F_29 ( V_35 ) ;
F_49 ( V_266 ) ;
F_52 ( V_2 , V_60 ) ;
F_5 ( V_2 ) ;
return V_28 ;
}
int F_102 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_271 * V_272 = V_156 ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
int V_28 = 0 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
if ( ! V_272 -> V_152 || ( ~ V_273 & V_272 -> V_152 ) )
return - V_174 ;
V_26 = F_17 ( V_2 , V_272 -> V_169 , V_54 ) ;
if ( ! V_26 ) {
F_63 ( L_40 , V_272 -> V_169 ) ;
return - V_174 ;
}
V_4 = F_88 ( V_26 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_272 -> V_152 & V_274 ) {
if ( ! V_4 -> V_37 -> V_275 ) {
V_28 = - V_276 ;
goto V_41;
}
V_28 = V_4 -> V_37 -> V_275 ( V_4 , V_158 , V_272 -> V_277 ,
V_272 -> V_251 , V_272 -> V_252 ) ;
}
if ( V_272 -> V_152 & V_278 ) {
if ( V_4 -> V_37 -> V_279 ) {
V_28 = V_4 -> V_37 -> V_279 ( V_4 , V_272 -> V_195 , V_272 -> V_196 ) ;
} else {
V_28 = - V_178 ;
goto V_41;
}
}
V_41:
F_6 ( & V_4 -> V_6 ) ;
return V_28 ;
}
T_1 F_103 ( T_1 V_280 , T_1 V_281 )
{
T_1 V_282 ;
switch ( V_280 ) {
case 8 :
V_282 = V_283 ;
break;
case 16 :
if ( V_281 == 15 )
V_282 = V_284 ;
else
V_282 = V_285 ;
break;
case 24 :
V_282 = V_286 ;
break;
case 32 :
if ( V_281 == 24 )
V_282 = V_287 ;
else if ( V_281 == 30 )
V_282 = V_288 ;
else
V_282 = V_289 ;
break;
default:
F_44 ( L_50 ) ;
V_282 = V_287 ;
break;
}
return V_282 ;
}
int F_104 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_290 * V_291 = V_156 ;
struct V_292 V_293 = {} ;
struct V_234 * V_235 = & V_2 -> V_5 ;
struct V_34 * V_35 ;
int V_28 = 0 ;
V_293 . V_168 = V_291 -> V_168 ;
V_293 . V_251 = V_291 -> V_251 ;
V_293 . V_252 = V_291 -> V_252 ;
V_293 . V_294 [ 0 ] = V_291 -> V_295 ;
V_293 . V_250 = F_103 ( V_291 -> V_280 , V_291 -> V_281 ) ;
V_293 . V_296 [ 0 ] = V_291 -> V_277 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
if ( ( V_235 -> V_185 > V_293 . V_251 ) || ( V_293 . V_251 > V_235 -> V_184 ) )
return - V_174 ;
if ( ( V_235 -> V_183 > V_293 . V_252 ) || ( V_293 . V_252 > V_235 -> V_182 ) )
return - V_174 ;
V_35 = V_2 -> V_5 . V_37 -> V_297 ( V_2 , V_158 , & V_293 ) ;
if ( F_105 ( V_35 ) ) {
F_63 ( L_51 ) ;
return F_106 ( V_35 ) ;
}
F_2 ( & V_158 -> V_175 ) ;
V_291 -> V_168 = V_35 -> V_14 . V_15 ;
F_23 ( & V_35 -> V_40 , & V_158 -> V_298 ) ;
F_63 ( L_52 , V_35 -> V_14 . V_15 ) ;
F_6 ( & V_158 -> V_175 ) ;
return V_28 ;
}
static int F_107 ( const struct V_292 * V_293 )
{
T_1 V_299 = V_293 -> V_250 & ~ V_300 ;
switch ( V_299 ) {
case V_283 :
case V_301 :
case V_302 :
case V_303 :
case V_304 :
case V_305 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_284 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_285 :
case V_318 :
case V_286 :
case V_319 :
case V_287 :
case V_320 :
case V_321 :
case V_322 :
case V_289 :
case V_323 :
case V_324 :
case V_325 :
case V_288 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
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
return 0 ;
default:
return - V_174 ;
}
}
static int F_108 ( const struct V_292 * V_293 )
{
int V_28 , V_354 , V_355 , V_356 , V_105 ;
V_28 = F_107 ( V_293 ) ;
if ( V_28 ) {
F_63 ( L_53 , V_293 -> V_250 ) ;
return V_28 ;
}
V_354 = F_109 ( V_293 -> V_250 ) ;
V_355 = F_110 ( V_293 -> V_250 ) ;
V_356 = F_111 ( V_293 -> V_250 ) ;
if ( V_293 -> V_251 == 0 || V_293 -> V_251 % V_354 ) {
F_63 ( L_54 , V_293 -> V_252 ) ;
return - V_174 ;
}
if ( V_293 -> V_252 == 0 || V_293 -> V_252 % V_355 ) {
F_63 ( L_55 , V_293 -> V_252 ) ;
return - V_174 ;
}
for ( V_105 = 0 ; V_105 < V_356 ; V_105 ++ ) {
unsigned int V_251 = V_293 -> V_251 / ( V_105 != 0 ? V_354 : 1 ) ;
unsigned int V_252 = V_293 -> V_252 / ( V_105 != 0 ? V_355 : 1 ) ;
unsigned int V_357 = F_112 ( V_293 -> V_250 , V_105 ) ;
if ( ! V_293 -> V_296 [ V_105 ] ) {
F_63 ( L_56 , V_105 ) ;
return - V_174 ;
}
if ( ( T_3 ) V_251 * V_357 > V_358 )
return - V_155 ;
if ( ( T_3 ) V_252 * V_293 -> V_294 [ V_105 ] + V_293 -> V_359 [ V_105 ] > V_358 )
return - V_155 ;
if ( V_293 -> V_294 [ V_105 ] < V_251 * V_357 ) {
F_63 ( L_57 , V_293 -> V_294 [ V_105 ] , V_105 ) ;
return - V_174 ;
}
}
return 0 ;
}
int F_113 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_292 * V_293 = V_156 ;
struct V_234 * V_235 = & V_2 -> V_5 ;
struct V_34 * V_35 ;
int V_28 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
if ( V_293 -> V_152 & ~ V_360 ) {
F_63 ( L_58 , V_293 -> V_152 ) ;
return - V_174 ;
}
if ( ( V_235 -> V_185 > V_293 -> V_251 ) || ( V_293 -> V_251 > V_235 -> V_184 ) ) {
F_63 ( L_59 ,
V_293 -> V_251 , V_235 -> V_185 , V_235 -> V_184 ) ;
return - V_174 ;
}
if ( ( V_235 -> V_183 > V_293 -> V_252 ) || ( V_293 -> V_252 > V_235 -> V_182 ) ) {
F_63 ( L_60 ,
V_293 -> V_252 , V_235 -> V_183 , V_235 -> V_182 ) ;
return - V_174 ;
}
V_28 = F_108 ( V_293 ) ;
if ( V_28 )
return V_28 ;
V_35 = V_2 -> V_5 . V_37 -> V_297 ( V_2 , V_158 , V_293 ) ;
if ( F_105 ( V_35 ) ) {
F_63 ( L_51 ) ;
return F_106 ( V_35 ) ;
}
F_2 ( & V_158 -> V_175 ) ;
V_293 -> V_168 = V_35 -> V_14 . V_15 ;
F_23 ( & V_35 -> V_40 , & V_158 -> V_298 ) ;
F_63 ( L_52 , V_35 -> V_14 . V_15 ) ;
F_6 ( & V_158 -> V_175 ) ;
return V_28 ;
}
int F_114 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_34 * V_35 = NULL ;
struct V_34 * V_361 = NULL ;
T_1 * V_15 = V_156 ;
int V_362 = 0 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_2 ( & V_158 -> V_175 ) ;
F_2 ( & V_2 -> V_5 . V_38 ) ;
V_35 = F_26 ( V_2 , * V_15 ) ;
if ( ! V_35 )
goto V_363;
F_3 (fbl, &file_priv->fbs, filp_head)
if ( V_35 == V_361 )
V_362 = 1 ;
if ( ! V_362 )
goto V_363;
F_36 ( V_2 , V_35 ) ;
F_115 ( & V_35 -> V_40 ) ;
F_6 ( & V_2 -> V_5 . V_38 ) ;
F_6 ( & V_158 -> V_175 ) ;
F_40 ( V_35 ) ;
return 0 ;
V_363:
F_6 ( & V_2 -> V_5 . V_38 ) ;
F_6 ( & V_158 -> V_175 ) ;
return - V_174 ;
}
int F_116 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_290 * V_293 = V_156 ;
struct V_34 * V_35 ;
int V_28 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
V_35 = F_28 ( V_2 , V_293 -> V_168 ) ;
if ( ! V_35 )
return - V_174 ;
V_293 -> V_252 = V_35 -> V_252 ;
V_293 -> V_251 = V_35 -> V_251 ;
V_293 -> V_281 = V_35 -> V_281 ;
V_293 -> V_280 = V_35 -> V_364 ;
V_293 -> V_295 = V_35 -> V_294 [ 0 ] ;
if ( V_35 -> V_37 -> V_365 )
V_28 = V_35 -> V_37 -> V_365 ( V_35 , V_158 , & V_293 -> V_277 ) ;
else
V_28 = - V_366 ;
F_29 ( V_35 ) ;
return V_28 ;
}
int F_117 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_367 T_2 * V_368 ;
struct V_367 * V_369 = NULL ;
struct V_370 * V_293 = V_156 ;
struct V_34 * V_35 ;
unsigned V_152 ;
int V_371 ;
int V_28 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
V_35 = F_28 ( V_2 , V_293 -> V_168 ) ;
if ( ! V_35 )
return - V_174 ;
V_371 = V_293 -> V_371 ;
V_368 = (struct V_367 T_2 * ) ( unsigned long ) V_293 -> V_368 ;
if ( ! V_371 != ! V_368 ) {
V_28 = - V_174 ;
goto V_372;
}
V_152 = V_373 & V_293 -> V_152 ;
if ( V_152 & V_374 && ( V_371 % 2 ) ) {
V_28 = - V_174 ;
goto V_372;
}
if ( V_371 && V_368 ) {
if ( V_371 < 0 || V_371 > V_375 ) {
V_28 = - V_174 ;
goto V_372;
}
V_369 = F_66 ( V_371 * sizeof( * V_369 ) , V_31 ) ;
if ( ! V_369 ) {
V_28 = - V_85 ;
goto V_372;
}
V_28 = F_118 ( V_369 , V_368 ,
V_371 * sizeof( * V_369 ) ) ;
if ( V_28 ) {
V_28 = - V_178 ;
goto V_376;
}
}
if ( V_35 -> V_37 -> V_377 ) {
F_1 ( V_2 ) ;
V_28 = V_35 -> V_37 -> V_377 ( V_35 , V_158 , V_152 , V_293 -> V_378 ,
V_369 , V_371 ) ;
F_5 ( V_2 ) ;
} else {
V_28 = - V_379 ;
}
V_376:
F_49 ( V_369 ) ;
V_372:
F_29 ( V_35 ) ;
return V_28 ;
}
void F_119 ( struct V_157 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_180 -> V_2 ;
struct V_34 * V_35 , * V_380 ;
F_2 ( & V_82 -> V_175 ) ;
F_56 (fb, tfb, &priv->fbs, filp_head) {
F_2 ( & V_2 -> V_5 . V_38 ) ;
F_36 ( V_2 , V_35 ) ;
F_6 ( & V_2 -> V_5 . V_38 ) ;
F_115 ( & V_35 -> V_40 ) ;
F_40 ( V_35 ) ;
}
F_6 ( & V_82 -> V_175 ) ;
}
struct V_90 * F_68 ( struct V_1 * V_2 , int V_152 ,
const char * V_13 , int V_381 )
{
struct V_90 * V_382 = NULL ;
int V_28 ;
V_382 = F_66 ( sizeof( struct V_90 ) , V_31 ) ;
if ( ! V_382 )
return NULL ;
if ( V_381 ) {
V_382 -> V_227 = F_66 ( sizeof( T_3 ) * V_381 , V_31 ) ;
if ( ! V_382 -> V_227 )
goto V_383;
}
V_28 = F_13 ( V_2 , & V_382 -> V_14 , V_384 ) ;
if ( V_28 )
goto V_383;
V_382 -> V_152 = V_152 ;
V_382 -> V_381 = V_381 ;
F_21 ( & V_382 -> V_385 ) ;
if ( V_13 ) {
strncpy ( V_382 -> V_13 , V_13 , V_386 ) ;
V_382 -> V_13 [ V_386 - 1 ] = '\0' ;
}
F_47 ( & V_382 -> V_43 , & V_2 -> V_5 . V_387 ) ;
return V_382 ;
V_383:
F_49 ( V_382 -> V_227 ) ;
F_49 ( V_382 ) ;
return NULL ;
}
struct V_90 * F_69 ( struct V_1 * V_2 , int V_152 ,
const char * V_13 ,
const struct V_388 * V_389 ,
int V_381 )
{
struct V_90 * V_382 ;
int V_105 , V_28 ;
V_152 |= V_115 ;
V_382 = F_68 ( V_2 , V_152 , V_13 , V_381 ) ;
if ( ! V_382 )
return NULL ;
for ( V_105 = 0 ; V_105 < V_381 ; V_105 ++ ) {
V_28 = F_74 ( V_382 , V_105 ,
V_389 [ V_105 ] . type ,
V_389 [ V_105 ] . V_13 ) ;
if ( V_28 ) {
F_120 ( V_2 , V_382 ) ;
return NULL ;
}
}
return V_382 ;
}
struct V_90 * F_121 ( struct V_1 * V_2 ,
int V_152 , const char * V_13 ,
const struct V_388 * V_389 ,
int V_381 )
{
struct V_90 * V_382 ;
int V_105 , V_28 ;
V_152 |= V_390 ;
V_382 = F_68 ( V_2 , V_152 , V_13 , V_381 ) ;
if ( ! V_382 )
return NULL ;
for ( V_105 = 0 ; V_105 < V_381 ; V_105 ++ ) {
V_28 = F_74 ( V_382 , V_105 ,
V_389 [ V_105 ] . type ,
V_389 [ V_105 ] . V_13 ) ;
if ( V_28 ) {
F_120 ( V_2 , V_382 ) ;
return NULL ;
}
}
return V_382 ;
}
struct V_90 * F_73 ( struct V_1 * V_2 , int V_152 ,
const char * V_13 ,
T_3 V_391 , T_3 V_392 )
{
struct V_90 * V_382 ;
V_152 |= V_393 ;
V_382 = F_68 ( V_2 , V_152 , V_13 , 2 ) ;
if ( ! V_382 )
return NULL ;
V_382 -> V_227 [ 0 ] = V_391 ;
V_382 -> V_227 [ 1 ] = V_392 ;
return V_382 ;
}
int F_74 ( struct V_90 * V_382 , int V_394 ,
T_3 V_395 , const char * V_13 )
{
struct V_396 * V_397 ;
if ( ! ( V_382 -> V_152 & ( V_115 | V_390 ) ) )
return - V_174 ;
if ( ( V_382 -> V_152 & V_390 ) && ( V_395 > 63 ) )
return - V_174 ;
if ( ! F_41 ( & V_382 -> V_385 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( V_397 -> V_395 == V_395 ) {
strncpy ( V_397 -> V_13 , V_13 , V_386 ) ;
V_397 -> V_13 [ V_386 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_397 = F_66 ( sizeof( struct V_396 ) , V_31 ) ;
if ( ! V_397 )
return - V_85 ;
strncpy ( V_397 -> V_13 , V_13 , V_386 ) ;
V_397 -> V_13 [ V_386 - 1 ] = '\0' ;
V_397 -> V_395 = V_395 ;
V_382 -> V_227 [ V_394 ] = V_395 ;
F_47 ( & V_397 -> V_43 , & V_382 -> V_385 ) ;
return 0 ;
}
void F_120 ( struct V_1 * V_2 , struct V_90 * V_382 )
{
struct V_396 * V_397 , * V_398 ;
F_56 (prop_enum, pt, &property->enum_blob_list, head) {
F_39 ( & V_397 -> V_43 ) ;
F_49 ( V_397 ) ;
}
if ( V_382 -> V_381 )
F_49 ( V_382 -> V_227 ) ;
F_15 ( V_2 , & V_382 -> V_14 ) ;
F_39 ( & V_382 -> V_43 ) ;
F_49 ( V_382 ) ;
}
void F_54 ( struct V_25 * V_26 ,
struct V_90 * V_382 ,
T_3 V_399 )
{
int V_64 = V_26 -> V_55 -> V_64 ;
if ( V_64 == V_400 ) {
F_81 ( 1 , L_61
L_62
L_63 ,
V_26 -> type ) ;
return;
}
V_26 -> V_55 -> V_226 [ V_64 ] = V_382 -> V_14 . V_15 ;
V_26 -> V_55 -> V_227 [ V_64 ] = V_399 ;
V_26 -> V_55 -> V_64 ++ ;
}
int F_122 ( struct V_25 * V_26 ,
struct V_90 * V_382 , T_3 V_401 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_26 -> V_55 -> V_64 ; V_105 ++ ) {
if ( V_26 -> V_55 -> V_226 [ V_105 ] == V_382 -> V_14 . V_15 ) {
V_26 -> V_55 -> V_227 [ V_105 ] = V_401 ;
return 0 ;
}
}
return - V_174 ;
}
int F_123 ( struct V_25 * V_26 ,
struct V_90 * V_382 , T_3 * V_401 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_26 -> V_55 -> V_64 ; V_105 ++ ) {
if ( V_26 -> V_55 -> V_226 [ V_105 ] == V_382 -> V_14 . V_15 ) {
* V_401 = V_26 -> V_55 -> V_227 [ V_105 ] ;
return 0 ;
}
}
return - V_174 ;
}
int F_124 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_25 * V_26 ;
struct V_402 * V_201 = V_156 ;
struct V_90 * V_382 ;
int V_403 = 0 ;
int V_404 = 0 ;
int V_405 = 0 ;
int V_28 = 0 , V_105 ;
int V_167 ;
struct V_396 * V_397 ;
struct V_406 T_2 * V_407 ;
struct V_408 * V_409 ;
T_1 T_2 * V_410 ;
T_3 T_2 * V_411 ;
T_1 T_2 * V_412 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_26 = F_17 ( V_2 , V_201 -> V_413 , V_384 ) ;
if ( ! V_26 ) {
V_28 = - V_174 ;
goto V_414;
}
V_382 = F_125 ( V_26 ) ;
if ( V_382 -> V_152 & ( V_115 | V_390 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head)
V_403 ++ ;
} else if ( V_382 -> V_152 & V_93 ) {
F_3 (prop_blob, &property->enum_blob_list, head)
V_404 ++ ;
}
V_405 = V_382 -> V_381 ;
strncpy ( V_201 -> V_13 , V_382 -> V_13 , V_386 ) ;
V_201 -> V_13 [ V_386 - 1 ] = 0 ;
V_201 -> V_152 = V_382 -> V_152 ;
if ( ( V_201 -> V_415 >= V_405 ) && V_405 ) {
V_411 = ( T_3 T_2 * ) ( unsigned long ) V_201 -> V_411 ;
for ( V_105 = 0 ; V_105 < V_405 ; V_105 ++ ) {
if ( F_91 ( V_411 + V_105 , & V_382 -> V_227 [ V_105 ] , sizeof( T_3 ) ) ) {
V_28 = - V_178 ;
goto V_414;
}
}
}
V_201 -> V_415 = V_405 ;
if ( V_382 -> V_152 & ( V_115 | V_390 ) ) {
if ( ( V_201 -> V_416 >= V_403 ) && V_403 ) {
V_167 = 0 ;
V_407 = (struct V_406 T_2 * ) ( unsigned long ) V_201 -> V_417 ;
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( F_91 ( & V_407 [ V_167 ] . V_395 , & V_397 -> V_395 , sizeof( T_3 ) ) ) {
V_28 = - V_178 ;
goto V_414;
}
if ( F_91 ( & V_407 [ V_167 ] . V_13 ,
& V_397 -> V_13 , V_386 ) ) {
V_28 = - V_178 ;
goto V_414;
}
V_167 ++ ;
}
}
V_201 -> V_416 = V_403 ;
}
if ( V_382 -> V_152 & V_93 ) {
if ( ( V_201 -> V_416 >= V_404 ) && V_404 ) {
V_167 = 0 ;
V_410 = ( T_1 T_2 * ) ( unsigned long ) V_201 -> V_417 ;
V_412 = ( T_1 T_2 * ) ( unsigned long ) V_201 -> V_411 ;
F_3 (prop_blob, &property->enum_blob_list, head) {
if ( F_86 ( V_409 -> V_14 . V_15 , V_410 + V_167 ) ) {
V_28 = - V_178 ;
goto V_414;
}
if ( F_86 ( V_409 -> V_418 , V_412 + V_167 ) ) {
V_28 = - V_178 ;
goto V_414;
}
V_167 ++ ;
}
}
V_201 -> V_416 = V_404 ;
}
V_414:
F_5 ( V_2 ) ;
return V_28 ;
}
static struct V_408 * F_126 ( struct V_1 * V_2 , int V_418 ,
void * V_156 )
{
struct V_408 * V_419 ;
int V_28 ;
if ( ! V_418 || ! V_156 )
return NULL ;
V_419 = F_66 ( sizeof( struct V_408 ) + V_418 , V_31 ) ;
if ( ! V_419 )
return NULL ;
V_28 = F_13 ( V_2 , & V_419 -> V_14 , V_420 ) ;
if ( V_28 ) {
F_49 ( V_419 ) ;
return NULL ;
}
V_419 -> V_418 = V_418 ;
memcpy ( V_419 -> V_156 , V_156 , V_418 ) ;
F_47 ( & V_419 -> V_43 , & V_2 -> V_5 . V_421 ) ;
return V_419 ;
}
static void F_127 ( struct V_1 * V_2 ,
struct V_408 * V_419 )
{
F_15 ( V_2 , & V_419 -> V_14 ) ;
F_39 ( & V_419 -> V_43 ) ;
F_49 ( V_419 ) ;
}
int F_128 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_25 * V_26 ;
struct V_422 * V_201 = V_156 ;
struct V_408 * V_419 ;
int V_28 = 0 ;
void T_2 * V_423 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_26 = F_17 ( V_2 , V_201 -> V_424 , V_420 ) ;
if ( ! V_26 ) {
V_28 = - V_174 ;
goto V_414;
}
V_419 = F_129 ( V_26 ) ;
if ( V_201 -> V_418 == V_419 -> V_418 ) {
V_423 = ( void T_2 * ) ( unsigned long ) V_201 -> V_156 ;
if ( F_91 ( V_423 , V_419 -> V_156 , V_419 -> V_418 ) ) {
V_28 = - V_178 ;
goto V_414;
}
}
V_201 -> V_418 = V_419 -> V_418 ;
V_414:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_130 ( struct V_16 * V_17 ,
struct V_91 * V_91 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
int V_28 , V_425 ;
if ( V_17 -> V_66 )
F_127 ( V_2 , V_17 -> V_66 ) ;
if ( ! V_91 ) {
V_17 -> V_66 = NULL ;
V_28 = F_122 ( & V_17 -> V_14 , V_2 -> V_5 . V_71 , 0 ) ;
return V_28 ;
}
V_425 = V_426 * ( 1 + V_91 -> V_427 ) ;
V_17 -> V_66 = F_126 ( V_17 -> V_2 ,
V_425 , V_91 ) ;
if ( ! V_17 -> V_66 )
return - V_174 ;
V_28 = F_122 ( & V_17 -> V_14 ,
V_2 -> V_5 . V_71 ,
V_17 -> V_66 -> V_14 . V_15 ) ;
return V_28 ;
}
static bool F_131 ( struct V_90 * V_382 ,
T_3 V_395 )
{
if ( V_382 -> V_152 & V_94 )
return false ;
if ( V_382 -> V_152 & V_393 ) {
if ( V_395 < V_382 -> V_227 [ 0 ] || V_395 > V_382 -> V_227 [ 1 ] )
return false ;
return true ;
} else if ( V_382 -> V_152 & V_390 ) {
int V_105 ;
T_3 V_428 = 0 ;
for ( V_105 = 0 ; V_105 < V_382 -> V_381 ; V_105 ++ )
V_428 |= ( 1ULL << V_382 -> V_227 [ V_105 ] ) ;
return ! ( V_395 & ~ V_428 ) ;
} else if ( V_382 -> V_152 & V_93 ) {
return true ;
} else {
int V_105 ;
for ( V_105 = 0 ; V_105 < V_382 -> V_381 ; V_105 ++ )
if ( V_382 -> V_227 [ V_105 ] == V_395 )
return true ;
return false ;
}
}
int F_132 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_429 * V_430 = V_156 ;
struct V_431 V_432 = {
. V_395 = V_430 -> V_395 ,
. V_413 = V_430 -> V_413 ,
. V_433 = V_430 -> V_170 ,
. V_27 = V_63
} ;
return F_133 ( V_2 , & V_432 , V_158 ) ;
}
static int F_134 ( struct V_25 * V_26 ,
struct V_90 * V_382 ,
T_3 V_395 )
{
int V_28 = - V_174 ;
struct V_16 * V_17 = F_90 ( V_26 ) ;
if ( V_382 == V_17 -> V_2 -> V_5 . V_72 ) {
if ( V_17 -> V_37 -> V_92 )
(* V_17 -> V_37 -> V_92 )( V_17 , ( int ) V_395 ) ;
V_28 = 0 ;
} else if ( V_17 -> V_37 -> V_434 )
V_28 = V_17 -> V_37 -> V_434 ( V_17 , V_382 , V_395 ) ;
if ( ! V_28 )
F_122 ( & V_17 -> V_14 , V_382 , V_395 ) ;
return V_28 ;
}
static int F_135 ( struct V_25 * V_26 ,
struct V_90 * V_382 ,
T_3 V_395 )
{
int V_28 = - V_174 ;
struct V_3 * V_4 = F_88 ( V_26 ) ;
if ( V_4 -> V_37 -> V_434 )
V_28 = V_4 -> V_37 -> V_434 ( V_4 , V_382 , V_395 ) ;
if ( ! V_28 )
F_122 ( V_26 , V_382 , V_395 ) ;
return V_28 ;
}
static int F_136 ( struct V_25 * V_26 ,
struct V_90 * V_382 ,
T_3 V_395 )
{
int V_28 = - V_174 ;
struct V_47 * V_48 = F_96 ( V_26 ) ;
if ( V_48 -> V_37 -> V_434 )
V_28 = V_48 -> V_37 -> V_434 ( V_48 , V_382 , V_395 ) ;
if ( ! V_28 )
F_122 ( V_26 , V_382 , V_395 ) ;
return V_28 ;
}
int F_137 ( struct V_1 * V_2 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_435 * V_436 = V_156 ;
struct V_25 * V_26 ;
int V_28 = 0 ;
int V_105 ;
int V_167 = 0 ;
int V_203 = 0 ;
T_1 T_2 * V_224 ;
T_3 T_2 * V_225 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_26 = F_17 ( V_2 , V_436 -> V_433 , V_436 -> V_27 ) ;
if ( ! V_26 ) {
V_28 = - V_174 ;
goto V_41;
}
if ( ! V_26 -> V_55 ) {
V_28 = - V_174 ;
goto V_41;
}
V_203 = V_26 -> V_55 -> V_64 ;
if ( ( V_436 -> V_223 >= V_203 ) && V_203 ) {
V_167 = 0 ;
V_224 = ( T_1 T_2 * ) ( unsigned long ) ( V_436 -> V_224 ) ;
V_225 = ( T_3 T_2 * ) ( unsigned long )
( V_436 -> V_225 ) ;
for ( V_105 = 0 ; V_105 < V_203 ; V_105 ++ ) {
if ( F_86 ( V_26 -> V_55 -> V_226 [ V_105 ] ,
V_224 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
if ( F_86 ( V_26 -> V_55 -> V_227 [ V_105 ] ,
V_225 + V_167 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_167 ++ ;
}
}
V_436 -> V_223 = V_203 ;
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_133 ( struct V_1 * V_2 , void * V_156 ,
struct V_157 * V_158 )
{
struct V_431 * V_436 = V_156 ;
struct V_25 * V_437 ;
struct V_25 * V_438 ;
struct V_90 * V_382 ;
int V_28 = - V_174 ;
int V_105 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_437 = F_17 ( V_2 , V_436 -> V_433 , V_436 -> V_27 ) ;
if ( ! V_437 )
goto V_41;
if ( ! V_437 -> V_55 )
goto V_41;
for ( V_105 = 0 ; V_105 < V_437 -> V_55 -> V_64 ; V_105 ++ )
if ( V_437 -> V_55 -> V_226 [ V_105 ] == V_436 -> V_413 )
break;
if ( V_105 == V_437 -> V_55 -> V_64 )
goto V_41;
V_438 = F_17 ( V_2 , V_436 -> V_413 ,
V_384 ) ;
if ( ! V_438 )
goto V_41;
V_382 = F_125 ( V_438 ) ;
if ( ! F_131 ( V_382 , V_436 -> V_395 ) )
goto V_41;
switch ( V_437 -> type ) {
case V_63 :
V_28 = F_134 ( V_437 , V_382 ,
V_436 -> V_395 ) ;
break;
case V_54 :
V_28 = F_135 ( V_437 , V_382 , V_436 -> V_395 ) ;
break;
case V_83 :
V_28 = F_136 ( V_437 , V_382 , V_436 -> V_395 ) ;
break;
}
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_138 ( struct V_16 * V_17 ,
struct V_8 * V_9 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_210 ; V_105 ++ ) {
if ( V_17 -> V_211 [ V_105 ] == 0 ) {
V_17 -> V_211 [ V_105 ] = V_9 -> V_14 . V_15 ;
return 0 ;
}
}
return - V_85 ;
}
void F_139 ( struct V_16 * V_17 ,
struct V_8 * V_9 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_210 ; V_105 ++ ) {
if ( V_17 -> V_211 [ V_105 ] == V_9 -> V_14 . V_15 ) {
V_17 -> V_211 [ V_105 ] = 0 ;
if ( V_17 -> V_9 == V_9 )
V_17 -> V_9 = NULL ;
break;
}
}
}
int F_140 ( struct V_3 * V_4 ,
int V_197 )
{
V_4 -> V_197 = V_197 ;
V_4 -> V_58 = F_66 ( V_197 * sizeof( V_439 ) * 3 , V_31 ) ;
if ( ! V_4 -> V_58 ) {
V_4 -> V_197 = 0 ;
return - V_85 ;
}
return 0 ;
}
int F_141 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_440 * V_441 = V_156 ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
void * V_442 , * V_443 , * V_444 ;
int V_425 ;
int V_28 = 0 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_26 = F_17 ( V_2 , V_441 -> V_169 , V_54 ) ;
if ( ! V_26 ) {
V_28 = - V_174 ;
goto V_41;
}
V_4 = F_88 ( V_26 ) ;
if ( V_4 -> V_37 -> V_445 == NULL ) {
V_28 = - V_379 ;
goto V_41;
}
if ( V_441 -> V_197 != V_4 -> V_197 ) {
V_28 = - V_174 ;
goto V_41;
}
V_425 = V_441 -> V_197 * ( sizeof( V_439 ) ) ;
V_442 = V_4 -> V_58 ;
if ( F_118 ( V_442 , ( void T_2 * ) ( unsigned long ) V_441 -> V_446 , V_425 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_443 = V_442 + V_425 ;
if ( F_118 ( V_443 , ( void T_2 * ) ( unsigned long ) V_441 -> V_447 , V_425 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_444 = V_443 + V_425 ;
if ( F_118 ( V_444 , ( void T_2 * ) ( unsigned long ) V_441 -> V_448 , V_425 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_4 -> V_37 -> V_445 ( V_4 , V_442 , V_443 , V_444 , 0 , V_4 -> V_197 ) ;
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_142 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_440 * V_441 = V_156 ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
void * V_442 , * V_443 , * V_444 ;
int V_425 ;
int V_28 = 0 ;
if ( ! F_84 ( V_2 , V_173 ) )
return - V_174 ;
F_1 ( V_2 ) ;
V_26 = F_17 ( V_2 , V_441 -> V_169 , V_54 ) ;
if ( ! V_26 ) {
V_28 = - V_174 ;
goto V_41;
}
V_4 = F_88 ( V_26 ) ;
if ( V_441 -> V_197 != V_4 -> V_197 ) {
V_28 = - V_174 ;
goto V_41;
}
V_425 = V_441 -> V_197 * ( sizeof( V_439 ) ) ;
V_442 = V_4 -> V_58 ;
if ( F_91 ( ( void T_2 * ) ( unsigned long ) V_441 -> V_446 , V_442 , V_425 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_443 = V_442 + V_425 ;
if ( F_91 ( ( void T_2 * ) ( unsigned long ) V_441 -> V_447 , V_443 , V_425 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_444 = V_443 + V_425 ;
if ( F_91 ( ( void T_2 * ) ( unsigned long ) V_441 -> V_448 , V_444 , V_425 ) ) {
V_28 = - V_178 ;
goto V_41;
}
V_41:
F_5 ( V_2 ) ;
return V_28 ;
}
int F_143 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_449 * V_450 = V_156 ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
struct V_34 * V_35 = NULL , * V_247 = NULL ;
struct V_451 * V_452 = NULL ;
unsigned long V_152 ;
int V_140 , V_146 ;
int V_28 = - V_174 ;
if ( V_450 -> V_152 & ~ V_453 ||
V_450 -> V_454 != 0 )
return - V_174 ;
V_26 = F_17 ( V_2 , V_450 -> V_169 , V_54 ) ;
if ( ! V_26 )
return - V_174 ;
V_4 = F_88 ( V_26 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_35 == NULL ) {
V_28 = - V_455 ;
goto V_41;
}
if ( V_4 -> V_37 -> V_450 == NULL )
goto V_41;
V_35 = F_28 ( V_2 , V_450 -> V_168 ) ;
if ( ! V_35 )
goto V_41;
V_140 = V_4 -> V_60 . V_140 ;
V_146 = V_4 -> V_60 . V_146 ;
if ( V_4 -> V_53 )
F_100 ( V_140 , V_146 ) ;
if ( V_140 > V_35 -> V_251 ||
V_146 > V_35 -> V_252 ||
V_4 -> V_195 > V_35 -> V_251 - V_140 ||
V_4 -> V_196 > V_35 -> V_252 - V_146 ) {
F_63 ( L_44 ,
V_35 -> V_251 , V_35 -> V_252 , V_140 , V_146 , V_4 -> V_195 , V_4 -> V_196 ,
V_4 -> V_53 ? L_45 : L_46 ) ;
V_28 = - V_257 ;
goto V_41;
}
if ( V_4 -> V_35 -> V_250 != V_35 -> V_250 ) {
F_63 ( L_64 ) ;
V_28 = - V_174 ;
goto V_41;
}
if ( V_450 -> V_152 & V_456 ) {
V_28 = - V_85 ;
F_144 ( & V_2 -> V_457 , V_152 ) ;
if ( V_158 -> V_458 < sizeof V_452 -> V_459 ) {
F_145 ( & V_2 -> V_457 , V_152 ) ;
goto V_41;
}
V_158 -> V_458 -= sizeof V_452 -> V_459 ;
F_145 ( & V_2 -> V_457 , V_152 ) ;
V_452 = F_66 ( sizeof *V_452 , V_31 ) ;
if ( V_452 == NULL ) {
F_144 ( & V_2 -> V_457 , V_152 ) ;
V_158 -> V_458 += sizeof V_452 -> V_459 ;
F_145 ( & V_2 -> V_457 , V_152 ) ;
goto V_41;
}
V_452 -> V_459 . V_14 . type = V_460 ;
V_452 -> V_459 . V_14 . V_418 = sizeof V_452 -> V_459 ;
V_452 -> V_459 . V_461 = V_450 -> V_461 ;
V_452 -> V_14 . V_459 = & V_452 -> V_459 . V_14 ;
V_452 -> V_14 . V_158 = V_158 ;
V_452 -> V_14 . V_46 =
( void ( * ) ( struct V_462 * ) ) F_49 ;
}
V_247 = V_4 -> V_35 ;
V_28 = V_4 -> V_37 -> V_450 ( V_4 , V_35 , V_452 ) ;
if ( V_28 ) {
if ( V_450 -> V_152 & V_456 ) {
F_144 ( & V_2 -> V_457 , V_152 ) ;
V_158 -> V_458 += sizeof V_452 -> V_459 ;
F_145 ( & V_2 -> V_457 , V_152 ) ;
F_49 ( V_452 ) ;
}
V_247 = NULL ;
} else {
F_8 ( V_4 -> V_35 != V_35 ) ;
V_35 = NULL ;
}
V_41:
if ( V_35 )
F_29 ( V_35 ) ;
if ( V_247 )
F_29 ( V_247 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_28 ;
}
void F_146 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
if ( V_4 -> V_37 -> V_463 )
V_4 -> V_37 -> V_463 ( V_4 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
if ( V_9 -> V_37 -> V_463 )
V_9 -> V_37 -> V_463 ( V_9 ) ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_17 -> V_22 = V_67 ;
if ( V_17 -> V_37 -> V_463 )
V_17 -> V_37 -> V_463 ( V_17 ) ;
}
}
int F_147 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_464 * args = V_156 ;
if ( ! V_2 -> V_465 -> V_466 )
return - V_379 ;
return V_2 -> V_465 -> V_466 ( V_158 , V_2 , args ) ;
}
int F_148 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_467 * args = V_156 ;
if ( ! V_2 -> V_465 -> V_468 )
return - V_379 ;
return V_2 -> V_465 -> V_468 ( V_158 , V_2 , args -> V_277 , & args -> V_469 ) ;
}
int F_149 ( struct V_1 * V_2 ,
void * V_156 , struct V_157 * V_158 )
{
struct V_470 * args = V_156 ;
if ( ! V_2 -> V_465 -> V_471 )
return - V_379 ;
return V_2 -> V_465 -> V_471 ( V_158 , V_2 , args -> V_277 ) ;
}
void F_150 ( T_1 V_299 , unsigned int * V_281 ,
int * V_280 )
{
switch ( V_299 ) {
case V_283 :
case V_301 :
case V_302 :
* V_281 = 8 ;
* V_280 = 8 ;
break;
case V_284 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
* V_281 = 15 ;
* V_280 = 16 ;
break;
case V_285 :
case V_318 :
* V_281 = 16 ;
* V_280 = 16 ;
break;
case V_286 :
case V_319 :
* V_281 = 24 ;
* V_280 = 24 ;
break;
case V_287 :
case V_320 :
case V_321 :
case V_322 :
* V_281 = 24 ;
* V_280 = 32 ;
break;
case V_288 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
* V_281 = 30 ;
* V_280 = 32 ;
break;
case V_289 :
case V_323 :
case V_324 :
case V_325 :
* V_281 = 32 ;
* V_280 = 32 ;
break;
default:
F_63 ( L_65 ) ;
* V_281 = 0 ;
* V_280 = 0 ;
break;
}
}
int F_111 ( T_1 V_299 )
{
switch ( V_299 ) {
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
return 3 ;
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
return 2 ;
default:
return 1 ;
}
}
int F_112 ( T_1 V_299 , int V_48 )
{
unsigned int V_281 ;
int V_280 ;
if ( V_48 >= F_111 ( V_299 ) )
return 0 ;
switch ( V_299 ) {
case V_333 :
case V_334 :
case V_335 :
case V_336 :
return 2 ;
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
return V_48 ? 2 : 1 ;
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
return 1 ;
default:
F_150 ( V_299 , & V_281 , & V_280 ) ;
return V_280 >> 3 ;
}
}
int F_109 ( T_1 V_299 )
{
switch ( V_299 ) {
case V_346 :
case V_347 :
case V_344 :
case V_345 :
return 4 ;
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_350 :
case V_351 :
case V_348 :
case V_349 :
return 2 ;
default:
return 1 ;
}
}
int F_110 ( T_1 V_299 )
{
switch ( V_299 ) {
case V_344 :
case V_345 :
return 4 ;
case V_348 :
case V_349 :
case V_338 :
case V_339 :
return 2 ;
default:
return 1 ;
}
}
void F_151 ( struct V_1 * V_2 )
{
F_46 ( & V_2 -> V_5 . V_6 ) ;
F_46 ( & V_2 -> V_5 . V_29 ) ;
F_46 ( & V_2 -> V_5 . V_38 ) ;
F_21 ( & V_2 -> V_5 . V_44 ) ;
F_21 ( & V_2 -> V_5 . V_56 ) ;
F_21 ( & V_2 -> V_5 . V_68 ) ;
F_21 ( & V_2 -> V_5 . V_76 ) ;
F_21 ( & V_2 -> V_5 . V_387 ) ;
F_21 ( & V_2 -> V_5 . V_421 ) ;
F_21 ( & V_2 -> V_5 . V_86 ) ;
F_152 ( & V_2 -> V_5 . V_30 ) ;
F_1 ( V_2 ) ;
F_67 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_5 . V_42 = 0 ;
V_2 -> V_5 . V_69 = 0 ;
V_2 -> V_5 . V_57 = 0 ;
V_2 -> V_5 . V_77 = 0 ;
}
void F_153 ( struct V_1 * V_2 )
{
struct V_16 * V_17 , * V_472 ;
struct V_3 * V_4 , * V_473 ;
struct V_8 * V_9 , * V_474 ;
struct V_34 * V_35 , * V_475 ;
struct V_90 * V_382 , * V_398 ;
struct V_408 * V_419 , * V_476 ;
struct V_47 * V_48 , * V_477 ;
F_56 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_9 -> V_37 -> V_46 ( V_9 ) ;
}
F_56 (connector, ot,
&dev->mode_config.connector_list, head) {
V_17 -> V_37 -> V_46 ( V_17 ) ;
}
F_56 (property, pt, &dev->mode_config.property_list,
head) {
F_120 ( V_2 , V_382 ) ;
}
F_56 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_127 ( V_2 , V_419 ) ;
}
F_8 ( ! F_41 ( & V_2 -> V_5 . V_44 ) ) ;
F_56 (fb, fbt, &dev->mode_config.fb_list, head) {
F_40 ( V_35 ) ;
}
F_56 (plane, plt, &dev->mode_config.plane_list,
head) {
V_48 -> V_37 -> V_46 ( V_48 ) ;
}
F_56 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_4 -> V_37 -> V_46 ( V_4 ) ;
}
F_154 ( & V_2 -> V_5 . V_30 ) ;
}
