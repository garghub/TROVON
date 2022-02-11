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
const char * F_10 ( const struct V_8 * V_9 )
{
static char V_10 [ 32 ] ;
snprintf ( V_10 , 32 , L_1 ,
V_11 [ V_9 -> V_12 ] . V_13 ,
V_9 -> V_14 . V_15 ) ;
return V_10 ;
}
const char * F_11 ( const struct V_16 * V_17 )
{
static char V_10 [ 32 ] ;
snprintf ( V_10 , 32 , L_1 ,
V_18 [ V_17 -> V_19 ] . V_13 ,
V_17 -> V_20 ) ;
return V_10 ;
}
const char * F_12 ( enum V_21 V_22 )
{
if ( V_22 == V_23 )
return L_2 ;
else if ( V_22 == V_24 )
return L_3 ;
else
return L_4 ;
}
static char F_13 ( int V_25 )
{
return isascii ( V_25 ) && isprint ( V_25 ) ? V_25 : '?' ;
}
const char * F_14 ( T_1 V_26 )
{
static char V_10 [ 32 ] ;
snprintf ( V_10 , sizeof( V_10 ) ,
L_5 ,
F_13 ( V_26 & 0xff ) ,
F_13 ( ( V_26 >> 8 ) & 0xff ) ,
F_13 ( ( V_26 >> 16 ) & 0xff ) ,
F_13 ( ( V_26 >> 24 ) & 0x7f ) ,
V_26 & V_27 ? L_6 : L_7 ,
V_26 ) ;
return V_10 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_28 * V_29 , T_1 V_30 )
{
int V_31 ;
F_2 ( & V_2 -> V_5 . V_32 ) ;
V_31 = F_16 ( & V_2 -> V_5 . V_33 , V_29 , 1 , 0 , V_34 ) ;
if ( V_31 >= 0 ) {
V_29 -> V_15 = V_31 ;
V_29 -> type = V_30 ;
}
F_6 ( & V_2 -> V_5 . V_32 ) ;
return V_31 < 0 ? V_31 : 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_28 * V_35 )
{
F_2 ( & V_2 -> V_5 . V_32 ) ;
F_18 ( & V_2 -> V_5 . V_33 , V_35 -> V_15 ) ;
F_6 ( & V_2 -> V_5 . V_32 ) ;
}
struct V_28 * F_19 ( struct V_1 * V_2 ,
T_1 V_15 , T_1 type )
{
struct V_28 * V_29 = NULL ;
F_8 ( type == V_36 ) ;
F_2 ( & V_2 -> V_5 . V_32 ) ;
V_29 = F_20 ( & V_2 -> V_5 . V_33 , V_15 ) ;
if ( ! V_29 || ( V_29 -> type != type ) || ( V_29 -> V_15 != V_15 ) )
V_29 = NULL ;
F_6 ( & V_2 -> V_5 . V_32 ) ;
return V_29 ;
}
int F_21 ( struct V_1 * V_2 , struct V_37 * V_38 ,
const struct V_39 * V_40 )
{
int V_31 ;
F_2 ( & V_2 -> V_5 . V_41 ) ;
F_22 ( & V_38 -> V_42 ) ;
F_23 ( & V_38 -> V_43 ) ;
V_38 -> V_2 = V_2 ;
V_38 -> V_40 = V_40 ;
V_31 = F_15 ( V_2 , & V_38 -> V_14 , V_36 ) ;
if ( V_31 )
goto V_44;
F_24 ( V_38 ) ;
V_2 -> V_5 . V_45 ++ ;
F_25 ( & V_38 -> V_46 , & V_2 -> V_5 . V_47 ) ;
V_44:
F_6 ( & V_2 -> V_5 . V_41 ) ;
return 0 ;
}
static void F_26 ( struct V_48 * V_48 )
{
struct V_37 * V_38 =
F_27 ( V_48 , struct V_37 , V_42 ) ;
V_38 -> V_40 -> V_49 ( V_38 ) ;
}
static struct V_37 * F_28 ( struct V_1 * V_2 ,
T_1 V_15 )
{
struct V_28 * V_29 = NULL ;
struct V_37 * V_38 ;
F_2 ( & V_2 -> V_5 . V_32 ) ;
V_29 = F_20 ( & V_2 -> V_5 . V_33 , V_15 ) ;
if ( ! V_29 || ( V_29 -> type != V_36 ) || ( V_29 -> V_15 != V_15 ) )
V_38 = NULL ;
else
V_38 = F_29 ( V_29 ) ;
F_6 ( & V_2 -> V_5 . V_32 ) ;
return V_38 ;
}
struct V_37 * F_30 ( struct V_1 * V_2 ,
T_1 V_15 )
{
struct V_37 * V_38 ;
F_2 ( & V_2 -> V_5 . V_41 ) ;
V_38 = F_28 ( V_2 , V_15 ) ;
if ( V_38 )
F_24 ( V_38 ) ;
F_6 ( & V_2 -> V_5 . V_41 ) ;
return V_38 ;
}
void F_31 ( struct V_37 * V_38 )
{
F_32 ( L_8 , V_38 -> V_14 . V_15 ) ;
F_33 ( & V_38 -> V_42 , F_26 ) ;
}
void F_24 ( struct V_37 * V_38 )
{
F_32 ( L_8 , V_38 -> V_14 . V_15 ) ;
F_34 ( & V_38 -> V_42 ) ;
}
static void F_35 ( struct V_48 * V_48 )
{
F_36 () ;
}
static void F_37 ( struct V_37 * V_38 )
{
F_32 ( L_8 , V_38 -> V_14 . V_15 ) ;
F_33 ( & V_38 -> V_42 , F_35 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
F_2 ( & V_2 -> V_5 . V_32 ) ;
F_18 ( & V_2 -> V_5 . V_33 , V_38 -> V_14 . V_15 ) ;
F_6 ( & V_2 -> V_5 . V_32 ) ;
V_38 -> V_14 . V_15 = 0 ;
F_37 ( V_38 ) ;
}
void F_39 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_41 ) ;
F_38 ( V_2 , V_38 ) ;
F_6 ( & V_2 -> V_5 . V_41 ) ;
}
void F_40 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_41 ) ;
F_41 ( & V_38 -> V_46 ) ;
V_2 -> V_5 . V_45 -- ;
F_6 ( & V_2 -> V_5 . V_41 ) ;
}
void F_42 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_3 * V_4 ;
struct V_50 * V_51 ;
struct V_52 V_53 ;
int V_31 ;
F_8 ( ! F_43 ( & V_38 -> V_43 ) ) ;
if ( F_44 ( & V_38 -> V_42 . V_42 ) > 1 ) {
F_1 ( V_2 ) ;
F_3 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_4 -> V_38 == V_38 ) {
memset ( & V_53 , 0 , sizeof( struct V_52 ) ) ;
V_53 . V_4 = V_4 ;
V_53 . V_38 = NULL ;
V_31 = F_45 ( & V_53 ) ;
if ( V_31 )
F_46 ( L_9 , V_4 ) ;
}
}
F_3 (plane, &dev->mode_config.plane_list, head) {
if ( V_51 -> V_38 == V_38 )
F_47 ( V_51 ) ;
}
F_5 ( V_2 ) ;
}
F_31 ( V_38 ) ;
}
int F_48 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_54 * V_40 )
{
int V_31 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_40 = V_40 ;
V_4 -> V_55 = false ;
F_1 ( V_2 ) ;
F_49 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_6 , & V_2 -> V_5 . V_6 ) ;
V_31 = F_15 ( V_2 , & V_4 -> V_14 , V_56 ) ;
if ( V_31 )
goto V_44;
V_4 -> V_14 . V_57 = & V_4 -> V_57 ;
F_50 ( & V_4 -> V_46 , & V_2 -> V_5 . V_58 ) ;
V_2 -> V_5 . V_59 ++ ;
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
void F_51 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_52 ( V_4 -> V_60 ) ;
V_4 -> V_60 = NULL ;
F_17 ( V_2 , & V_4 -> V_14 ) ;
F_41 ( & V_4 -> V_46 ) ;
V_2 -> V_5 . V_59 -- ;
}
void F_53 ( struct V_16 * V_17 ,
struct V_61 * V_62 )
{
F_50 ( & V_62 -> V_46 , & V_17 -> V_63 ) ;
}
void F_54 ( struct V_16 * V_17 ,
struct V_61 * V_62 )
{
F_41 ( & V_62 -> V_46 ) ;
F_55 ( V_17 -> V_2 , V_62 ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const struct V_64 * V_40 ,
int V_19 )
{
int V_31 ;
F_1 ( V_2 ) ;
V_31 = F_15 ( V_2 , & V_17 -> V_14 , V_65 ) ;
if ( V_31 )
goto V_44;
V_17 -> V_14 . V_57 = & V_17 -> V_57 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_40 = V_40 ;
V_17 -> V_19 = V_19 ;
V_17 -> V_20 =
++ V_18 [ V_19 ] . V_66 ;
F_23 ( & V_17 -> V_63 ) ;
F_23 ( & V_17 -> V_67 ) ;
V_17 -> V_68 = NULL ;
V_17 -> V_22 = V_69 ;
F_50 ( & V_17 -> V_46 , & V_2 -> V_5 . V_70 ) ;
V_2 -> V_5 . V_71 ++ ;
if ( V_19 != V_72 )
F_57 ( & V_17 -> V_14 ,
V_2 -> V_5 . V_73 ,
0 ) ;
F_57 ( & V_17 -> V_14 ,
V_2 -> V_5 . V_74 , 0 ) ;
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
void F_58 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_61 * V_62 , * V_75 ;
F_59 (mode, t, &connector->probed_modes, head)
F_54 ( V_17 , V_62 ) ;
F_59 (mode, t, &connector->modes, head)
F_54 ( V_17 , V_62 ) ;
F_17 ( V_2 , & V_17 -> V_14 ) ;
F_41 ( & V_17 -> V_46 ) ;
V_2 -> V_5 . V_71 -- ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
F_3 (connector, &dev->mode_config.connector_list, head)
F_61 ( V_17 ) ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
const struct V_76 * V_40 ,
int V_12 )
{
int V_31 ;
F_1 ( V_2 ) ;
V_31 = F_15 ( V_2 , & V_9 -> V_14 , V_77 ) ;
if ( V_31 )
goto V_44;
V_9 -> V_2 = V_2 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_40 = V_40 ;
F_50 ( & V_9 -> V_46 , & V_2 -> V_5 . V_78 ) ;
V_2 -> V_5 . V_79 ++ ;
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
void F_63 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
F_1 ( V_2 ) ;
F_17 ( V_2 , & V_9 -> V_14 ) ;
F_41 ( & V_9 -> V_46 ) ;
V_2 -> V_5 . V_79 -- ;
F_5 ( V_2 ) ;
}
int F_64 ( struct V_1 * V_2 , struct V_50 * V_51 ,
unsigned long V_80 ,
const struct V_81 * V_40 ,
const T_1 * V_82 , T_1 V_83 ,
bool V_84 )
{
int V_31 ;
F_1 ( V_2 ) ;
V_31 = F_15 ( V_2 , & V_51 -> V_14 , V_85 ) ;
if ( V_31 )
goto V_44;
V_51 -> V_14 . V_57 = & V_51 -> V_57 ;
V_51 -> V_2 = V_2 ;
V_51 -> V_40 = V_40 ;
V_51 -> V_86 = F_65 ( sizeof( T_1 ) * V_83 ,
V_34 ) ;
if ( ! V_51 -> V_86 ) {
F_66 ( L_10 ) ;
F_17 ( V_2 , & V_51 -> V_14 ) ;
V_31 = - V_87 ;
goto V_44;
}
memcpy ( V_51 -> V_86 , V_82 , V_83 * sizeof( T_1 ) ) ;
V_51 -> V_83 = V_83 ;
V_51 -> V_80 = V_80 ;
if ( ! V_84 ) {
F_50 ( & V_51 -> V_46 , & V_2 -> V_5 . V_88 ) ;
V_2 -> V_5 . V_89 ++ ;
} else {
F_23 ( & V_51 -> V_46 ) ;
}
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
void F_67 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
F_1 ( V_2 ) ;
F_52 ( V_51 -> V_86 ) ;
F_17 ( V_2 , & V_51 -> V_14 ) ;
if ( ! F_43 ( & V_51 -> V_46 ) ) {
F_41 ( & V_51 -> V_46 ) ;
V_2 -> V_5 . V_89 -- ;
}
F_5 ( V_2 ) ;
}
void F_47 ( struct V_50 * V_51 )
{
int V_31 ;
if ( ! V_51 -> V_38 )
return;
V_31 = V_51 -> V_40 -> V_90 ( V_51 ) ;
if ( V_31 )
F_46 ( L_11 ) ;
F_37 ( V_51 -> V_38 ) ;
V_51 -> V_38 = NULL ;
V_51 -> V_4 = NULL ;
}
struct V_61 * F_68 ( struct V_1 * V_2 )
{
struct V_61 * V_91 ;
V_91 = F_69 ( sizeof( struct V_61 ) , V_34 ) ;
if ( ! V_91 )
return NULL ;
if ( F_15 ( V_2 , & V_91 -> V_14 , V_92 ) ) {
F_52 ( V_91 ) ;
return NULL ;
}
return V_91 ;
}
void F_55 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
if ( ! V_62 )
return;
F_17 ( V_2 , & V_62 -> V_14 ) ;
F_52 ( V_62 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_93 * V_94 ;
struct V_93 * V_95 ;
V_94 = F_71 ( V_2 , V_96 |
V_97 ,
L_12 , 0 ) ;
V_2 -> V_5 . V_73 = V_94 ;
V_95 = F_72 ( V_2 , 0 ,
L_13 , V_98 ,
F_73 ( V_98 ) ) ;
V_2 -> V_5 . V_74 = V_95 ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_93 * V_99 ;
struct V_93 * V_100 ;
if ( V_2 -> V_5 . V_101 )
return 0 ;
V_99 =
F_72 ( V_2 , 0 ,
L_14 ,
V_102 ,
F_73 ( V_102 ) ) ;
V_2 -> V_5 . V_101 = V_99 ;
V_100 = F_72 ( V_2 , V_97 ,
L_15 ,
V_103 ,
F_73 ( V_103 ) ) ;
V_2 -> V_5 . V_104 = V_100 ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 , int V_105 ,
char * V_67 [] )
{
struct V_93 * V_106 ;
struct V_93 * V_107 ;
int V_108 ;
if ( V_2 -> V_5 . V_109 )
return 0 ;
V_106 = F_72 ( V_2 , 0 ,
L_14 ,
V_110 ,
F_73 ( V_110 ) ) ;
V_2 -> V_5 . V_109 = V_106 ;
V_107 =
F_72 ( V_2 , V_97 ,
L_15 ,
V_111 ,
F_73 ( V_111 ) ) ;
V_2 -> V_5 . V_112 = V_107 ;
V_2 -> V_5 . V_113 =
F_76 ( V_2 , 0 , L_16 , 0 , 100 ) ;
V_2 -> V_5 . V_114 =
F_76 ( V_2 , 0 , L_17 , 0 , 100 ) ;
V_2 -> V_5 . V_115 =
F_76 ( V_2 , 0 , L_18 , 0 , 100 ) ;
V_2 -> V_5 . V_116 =
F_76 ( V_2 , 0 , L_19 , 0 , 100 ) ;
V_2 -> V_5 . V_117 =
F_71 ( V_2 , V_118 ,
L_20 , V_105 ) ;
for ( V_108 = 0 ; V_108 < V_105 ; V_108 ++ )
F_77 ( V_2 -> V_5 . V_117 , V_108 ,
V_108 , V_67 [ V_108 ] ) ;
V_2 -> V_5 . V_119 =
F_76 ( V_2 , 0 , L_21 , 0 , 100 ) ;
V_2 -> V_5 . V_120 =
F_76 ( V_2 , 0 , L_22 , 0 , 100 ) ;
V_2 -> V_5 . V_121 =
F_76 ( V_2 , 0 , L_23 , 0 , 100 ) ;
V_2 -> V_5 . V_122 =
F_76 ( V_2 , 0 , L_24 , 0 , 100 ) ;
V_2 -> V_5 . V_123 =
F_76 ( V_2 , 0 , L_25 , 0 , 100 ) ;
V_2 -> V_5 . V_124 =
F_76 ( V_2 , 0 , L_26 , 0 , 100 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 )
{
struct V_93 * V_125 ;
if ( V_2 -> V_5 . V_126 )
return 0 ;
V_125 =
F_72 ( V_2 , 0 , L_27 ,
V_127 ,
F_73 ( V_127 ) ) ;
V_2 -> V_5 . V_126 = V_125 ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 )
{
struct V_93 * V_128 ;
if ( V_2 -> V_5 . V_129 )
return 0 ;
V_128 =
F_72 ( V_2 , 0 , L_28 ,
V_130 ,
F_73 ( V_130 ) ) ;
V_2 -> V_5 . V_129 = V_128 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
struct V_93 * V_131 ;
if ( V_2 -> V_5 . V_132 )
return 0 ;
V_131 =
F_72 ( V_2 , V_97 ,
L_29 ,
V_133 ,
F_73 ( V_133 ) ) ;
V_2 -> V_5 . V_132 = V_131 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_134 * V_135 )
{
T_1 V_136 = 0 ;
V_136 += V_2 -> V_5 . V_59 ;
V_136 += V_2 -> V_5 . V_71 ;
V_136 += V_2 -> V_5 . V_79 ;
V_135 -> V_137 = F_69 ( V_136 * sizeof( T_1 ) , V_34 ) ;
if ( ! V_135 -> V_137 )
return - V_87 ;
V_135 -> V_138 = 0 ;
V_135 -> V_139 = 0 ;
V_135 -> V_140 = 0 ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_134 * V_135 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
int V_31 ;
if ( ( V_31 = F_81 ( V_2 , V_135 ) ) )
return V_31 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
V_135 -> V_137 [ V_135 -> V_138 ++ ] = V_4 -> V_14 . V_15 ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
V_135 -> V_137 [ V_135 -> V_138 + V_135 -> V_140 ++ ] =
V_9 -> V_14 . V_15 ;
F_3 (connector, &dev->mode_config.connector_list, head)
V_135 -> V_137 [ V_135 -> V_138 + V_135 -> V_140 +
V_135 -> V_139 ++ ] = V_17 -> V_14 . V_15 ;
return 0 ;
}
static void F_83 ( struct V_141 * V_44 ,
const struct V_61 * V_142 )
{
F_84 ( V_142 -> V_143 > V_144 || V_142 -> V_145 > V_144 ||
V_142 -> V_146 > V_144 || V_142 -> V_147 > V_144 ||
V_142 -> V_148 > V_144 || V_142 -> V_149 > V_144 ||
V_142 -> V_150 > V_144 || V_142 -> V_151 > V_144 ||
V_142 -> V_152 > V_144 || V_142 -> V_153 > V_144 ,
L_30 ) ;
V_44 -> clock = V_142 -> clock ;
V_44 -> V_143 = V_142 -> V_143 ;
V_44 -> V_145 = V_142 -> V_145 ;
V_44 -> V_146 = V_142 -> V_146 ;
V_44 -> V_147 = V_142 -> V_147 ;
V_44 -> V_148 = V_142 -> V_148 ;
V_44 -> V_149 = V_142 -> V_149 ;
V_44 -> V_150 = V_142 -> V_150 ;
V_44 -> V_151 = V_142 -> V_151 ;
V_44 -> V_152 = V_142 -> V_152 ;
V_44 -> V_153 = V_142 -> V_153 ;
V_44 -> V_154 = V_142 -> V_154 ;
V_44 -> V_155 = V_142 -> V_155 ;
V_44 -> type = V_142 -> type ;
strncpy ( V_44 -> V_13 , V_142 -> V_13 , V_156 ) ;
V_44 -> V_13 [ V_156 - 1 ] = 0 ;
}
static int F_85 ( struct V_61 * V_44 ,
const struct V_141 * V_142 )
{
if ( V_142 -> clock > V_157 || V_142 -> V_154 > V_157 )
return - V_158 ;
V_44 -> clock = V_142 -> clock ;
V_44 -> V_143 = V_142 -> V_143 ;
V_44 -> V_145 = V_142 -> V_145 ;
V_44 -> V_146 = V_142 -> V_146 ;
V_44 -> V_147 = V_142 -> V_147 ;
V_44 -> V_148 = V_142 -> V_148 ;
V_44 -> V_149 = V_142 -> V_149 ;
V_44 -> V_150 = V_142 -> V_150 ;
V_44 -> V_151 = V_142 -> V_151 ;
V_44 -> V_152 = V_142 -> V_152 ;
V_44 -> V_153 = V_142 -> V_153 ;
V_44 -> V_154 = V_142 -> V_154 ;
V_44 -> V_155 = V_142 -> V_155 ;
V_44 -> type = V_142 -> type ;
strncpy ( V_44 -> V_13 , V_142 -> V_13 , V_156 ) ;
V_44 -> V_13 [ V_156 - 1 ] = 0 ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_162 * V_163 = V_159 ;
struct V_164 * V_165 ;
struct V_37 * V_38 ;
struct V_16 * V_17 ;
struct V_3 * V_4 ;
struct V_8 * V_9 ;
int V_31 = 0 ;
int V_166 = 0 ;
int V_167 = 0 ;
int V_168 = 0 ;
int V_169 = 0 ;
int V_170 = 0 , V_108 ;
T_1 T_2 * V_171 ;
T_1 T_2 * V_172 ;
T_1 T_2 * V_173 ;
T_1 T_2 * V_174 ;
struct V_134 * V_175 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_2 ( & V_161 -> V_178 ) ;
F_88 (lh, &file_priv->fbs)
V_168 ++ ;
if ( V_163 -> V_179 >= V_168 ) {
V_170 = 0 ;
V_171 = ( T_1 T_2 * ) ( unsigned long ) V_163 -> V_180 ;
F_3 (fb, &file_priv->fbs, filp_head) {
if ( F_89 ( V_38 -> V_14 . V_15 , V_171 + V_170 ) ) {
F_6 ( & V_161 -> V_178 ) ;
return - V_181 ;
}
V_170 ++ ;
}
}
V_163 -> V_179 = V_168 ;
F_6 ( & V_161 -> V_178 ) ;
F_1 ( V_2 ) ;
V_175 = & V_161 -> V_182 -> V_183 -> V_175 ;
if ( V_161 -> V_182 -> V_183 -> type == V_184 ) {
F_88 (lh, &dev->mode_config.crtc_list)
V_167 ++ ;
F_88 (lh, &dev->mode_config.connector_list)
V_166 ++ ;
F_88 (lh, &dev->mode_config.encoder_list)
V_169 ++ ;
} else {
V_167 = V_175 -> V_138 ;
V_166 = V_175 -> V_139 ;
V_169 = V_175 -> V_140 ;
}
V_163 -> V_185 = V_2 -> V_5 . V_185 ;
V_163 -> V_186 = V_2 -> V_5 . V_186 ;
V_163 -> V_187 = V_2 -> V_5 . V_187 ;
V_163 -> V_188 = V_2 -> V_5 . V_188 ;
if ( V_163 -> V_189 >= V_167 ) {
V_170 = 0 ;
V_172 = ( T_1 T_2 * ) ( unsigned long ) V_163 -> V_190 ;
if ( V_161 -> V_182 -> V_183 -> type == V_184 ) {
F_3 (crtc, &dev->mode_config.crtc_list,
head) {
F_66 ( L_31 , V_4 -> V_14 . V_15 ) ;
if ( F_89 ( V_4 -> V_14 . V_15 , V_172 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
} else {
for ( V_108 = 0 ; V_108 < V_175 -> V_138 ; V_108 ++ ) {
if ( F_89 ( V_175 -> V_137 [ V_108 ] ,
V_172 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
}
}
V_163 -> V_189 = V_167 ;
if ( V_163 -> V_191 >= V_169 ) {
V_170 = 0 ;
V_174 = ( T_1 T_2 * ) ( unsigned long ) V_163 -> V_192 ;
if ( V_161 -> V_182 -> V_183 -> type == V_184 ) {
F_3 (encoder,
&dev->mode_config.encoder_list,
head) {
F_66 ( L_32 , V_9 -> V_14 . V_15 ,
F_10 ( V_9 ) ) ;
if ( F_89 ( V_9 -> V_14 . V_15 , V_174 +
V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
} else {
for ( V_108 = V_175 -> V_138 ; V_108 < V_175 -> V_138 + V_175 -> V_140 ; V_108 ++ ) {
if ( F_89 ( V_175 -> V_137 [ V_108 ] ,
V_174 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
}
}
V_163 -> V_191 = V_169 ;
if ( V_163 -> V_193 >= V_166 ) {
V_170 = 0 ;
V_173 = ( T_1 T_2 * ) ( unsigned long ) V_163 -> V_194 ;
if ( V_161 -> V_182 -> V_183 -> type == V_184 ) {
F_3 (connector,
&dev->mode_config.connector_list,
head) {
F_66 ( L_33 ,
V_17 -> V_14 . V_15 ,
F_11 ( V_17 ) ) ;
if ( F_89 ( V_17 -> V_14 . V_15 ,
V_173 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
} else {
int V_195 = V_175 -> V_138 +
V_175 -> V_140 ;
for ( V_108 = V_195 ; V_108 < V_195 + V_175 -> V_139 ; V_108 ++ ) {
if ( F_89 ( V_175 -> V_137 [ V_108 ] ,
V_173 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
}
}
V_163 -> V_193 = V_166 ;
F_66 ( L_34 , V_163 -> V_189 ,
V_163 -> V_193 , V_163 -> V_191 ) ;
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_90 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_196 * V_197 = V_159 ;
struct V_3 * V_4 ;
struct V_28 * V_29 ;
int V_31 = 0 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_29 = F_19 ( V_2 , V_197 -> V_172 ,
V_56 ) ;
if ( ! V_29 ) {
V_31 = - V_177 ;
goto V_44;
}
V_4 = F_91 ( V_29 ) ;
V_197 -> V_198 = V_4 -> V_198 ;
V_197 -> V_199 = V_4 -> V_199 ;
V_197 -> V_200 = V_4 -> V_200 ;
if ( V_4 -> V_38 )
V_197 -> V_171 = V_4 -> V_38 -> V_14 . V_15 ;
else
V_197 -> V_171 = 0 ;
if ( V_4 -> V_201 ) {
F_83 ( & V_197 -> V_62 , & V_4 -> V_62 ) ;
V_197 -> V_202 = 1 ;
} else {
V_197 -> V_202 = 0 ;
}
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_92 ( struct V_1 * V_2 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_203 * V_204 = V_159 ;
struct V_28 * V_29 ;
struct V_16 * V_17 ;
struct V_61 * V_62 ;
int V_205 = 0 ;
int V_206 = 0 ;
int V_207 = 0 ;
int V_31 = 0 ;
int V_170 = 0 ;
int V_108 ;
struct V_141 V_208 ;
struct V_141 T_2 * V_209 ;
T_1 T_2 * V_210 ;
T_3 T_2 * V_211 ;
T_1 T_2 * V_212 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
memset ( & V_208 , 0 , sizeof( struct V_141 ) ) ;
F_66 ( L_35 , V_204 -> V_173 ) ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_29 = F_19 ( V_2 , V_204 -> V_173 ,
V_65 ) ;
if ( ! V_29 ) {
V_31 = - V_177 ;
goto V_44;
}
V_17 = F_93 ( V_29 ) ;
V_206 = V_17 -> V_57 . V_66 ;
for ( V_108 = 0 ; V_108 < V_213 ; V_108 ++ ) {
if ( V_17 -> V_214 [ V_108 ] != 0 ) {
V_207 ++ ;
}
}
if ( V_204 -> V_215 == 0 ) {
V_17 -> V_40 -> V_216 ( V_17 ,
V_2 -> V_5 . V_187 ,
V_2 -> V_5 . V_185 ) ;
}
F_3 (mode, &connector->modes, head)
V_205 ++ ;
V_204 -> V_173 = V_17 -> V_14 . V_15 ;
V_204 -> V_19 = V_17 -> V_19 ;
V_204 -> V_20 = V_17 -> V_20 ;
V_204 -> V_217 = V_17 -> V_218 . V_219 ;
V_204 -> V_220 = V_17 -> V_218 . V_221 ;
V_204 -> V_222 = V_17 -> V_218 . V_223 ;
V_204 -> V_224 = V_17 -> V_22 ;
if ( V_17 -> V_9 )
V_204 -> V_174 = V_17 -> V_9 -> V_14 . V_15 ;
else
V_204 -> V_174 = 0 ;
if ( ( V_204 -> V_215 >= V_205 ) && V_205 ) {
V_170 = 0 ;
V_209 = (struct V_141 T_2 * ) ( unsigned long ) V_204 -> V_225 ;
F_3 (mode, &connector->modes, head) {
F_83 ( & V_208 , V_62 ) ;
if ( F_94 ( V_209 + V_170 ,
& V_208 , sizeof( V_208 ) ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
}
V_204 -> V_215 = V_205 ;
if ( ( V_204 -> V_226 >= V_206 ) && V_206 ) {
V_170 = 0 ;
V_210 = ( T_1 T_2 * ) ( unsigned long ) ( V_204 -> V_227 ) ;
V_211 = ( T_3 T_2 * ) ( unsigned long ) ( V_204 -> V_228 ) ;
for ( V_108 = 0 ; V_108 < V_17 -> V_57 . V_66 ; V_108 ++ ) {
if ( F_89 ( V_17 -> V_57 . V_229 [ V_108 ] ,
V_210 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
if ( F_89 ( V_17 -> V_57 . V_230 [ V_108 ] ,
V_211 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
}
V_204 -> V_226 = V_206 ;
if ( ( V_204 -> V_191 >= V_207 ) && V_207 ) {
V_170 = 0 ;
V_212 = ( T_1 T_2 * ) ( unsigned long ) ( V_204 -> V_231 ) ;
for ( V_108 = 0 ; V_108 < V_213 ; V_108 ++ ) {
if ( V_17 -> V_214 [ V_108 ] != 0 ) {
if ( F_89 ( V_17 -> V_214 [ V_108 ] ,
V_212 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
}
}
V_204 -> V_191 = V_207 ;
V_44:
F_6 ( & V_2 -> V_5 . V_6 ) ;
return V_31 ;
}
int F_95 ( struct V_1 * V_2 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_232 * V_233 = V_159 ;
struct V_28 * V_29 ;
struct V_8 * V_9 ;
int V_31 = 0 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_29 = F_19 ( V_2 , V_233 -> V_174 ,
V_77 ) ;
if ( ! V_29 ) {
V_31 = - V_177 ;
goto V_44;
}
V_9 = F_96 ( V_29 ) ;
if ( V_9 -> V_4 )
V_233 -> V_172 = V_9 -> V_4 -> V_14 . V_15 ;
else
V_233 -> V_172 = 0 ;
V_233 -> V_12 = V_9 -> V_12 ;
V_233 -> V_174 = V_9 -> V_14 . V_15 ;
V_233 -> V_80 = V_9 -> V_80 ;
V_233 -> V_234 = V_9 -> V_234 ;
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_97 ( struct V_1 * V_2 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_235 * V_236 = V_159 ;
struct V_237 * V_238 ;
struct V_50 * V_51 ;
T_1 T_2 * V_239 ;
int V_170 = 0 , V_31 = 0 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_238 = & V_2 -> V_5 ;
if ( V_238 -> V_89 &&
( V_236 -> V_240 >= V_238 -> V_89 ) ) {
V_239 = ( T_1 T_2 * ) ( unsigned long ) V_236 -> V_241 ;
F_3 (plane, &config->plane_list, head) {
if ( F_89 ( V_51 -> V_14 . V_15 , V_239 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
}
V_236 -> V_240 = V_238 -> V_89 ;
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_98 ( struct V_1 * V_2 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_242 * V_236 = V_159 ;
struct V_28 * V_29 ;
struct V_50 * V_51 ;
T_1 T_2 * V_243 ;
int V_31 = 0 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_29 = F_19 ( V_2 , V_236 -> V_244 ,
V_85 ) ;
if ( ! V_29 ) {
V_31 = - V_245 ;
goto V_44;
}
V_51 = F_99 ( V_29 ) ;
if ( V_51 -> V_4 )
V_236 -> V_172 = V_51 -> V_4 -> V_14 . V_15 ;
else
V_236 -> V_172 = 0 ;
if ( V_51 -> V_38 )
V_236 -> V_171 = V_51 -> V_38 -> V_14 . V_15 ;
else
V_236 -> V_171 = 0 ;
V_236 -> V_244 = V_51 -> V_14 . V_15 ;
V_236 -> V_80 = V_51 -> V_80 ;
V_236 -> V_200 = 0 ;
if ( V_51 -> V_83 &&
( V_236 -> V_246 >= V_51 -> V_83 ) ) {
V_243 = ( T_1 T_2 * ) ( unsigned long ) V_236 -> V_247 ;
if ( F_94 ( V_243 ,
V_51 -> V_86 ,
sizeof( T_1 ) * V_51 -> V_83 ) ) {
V_31 = - V_181 ;
goto V_44;
}
}
V_236 -> V_246 = V_51 -> V_83 ;
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_100 ( struct V_1 * V_2 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_248 * V_249 = V_159 ;
struct V_28 * V_29 ;
struct V_50 * V_51 ;
struct V_3 * V_4 ;
struct V_37 * V_38 = NULL , * V_250 = NULL ;
int V_31 = 0 ;
unsigned int V_251 , V_252 ;
int V_108 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
V_29 = F_19 ( V_2 , V_249 -> V_244 ,
V_85 ) ;
if ( ! V_29 ) {
F_66 ( L_36 ,
V_249 -> V_244 ) ;
return - V_245 ;
}
V_51 = F_99 ( V_29 ) ;
if ( ! V_249 -> V_171 ) {
F_1 ( V_2 ) ;
V_250 = V_51 -> V_38 ;
V_51 -> V_40 -> V_90 ( V_51 ) ;
V_51 -> V_4 = NULL ;
V_51 -> V_38 = NULL ;
F_5 ( V_2 ) ;
goto V_44;
}
V_29 = F_19 ( V_2 , V_249 -> V_172 ,
V_56 ) ;
if ( ! V_29 ) {
F_66 ( L_37 ,
V_249 -> V_172 ) ;
V_31 = - V_245 ;
goto V_44;
}
V_4 = F_91 ( V_29 ) ;
V_38 = F_30 ( V_2 , V_249 -> V_171 ) ;
if ( ! V_38 ) {
F_66 ( L_38 ,
V_249 -> V_171 ) ;
V_31 = - V_245 ;
goto V_44;
}
for ( V_108 = 0 ; V_108 < V_51 -> V_83 ; V_108 ++ )
if ( V_38 -> V_253 == V_51 -> V_86 [ V_108 ] )
break;
if ( V_108 == V_51 -> V_83 ) {
F_66 ( L_39 ,
F_14 ( V_38 -> V_253 ) ) ;
V_31 = - V_177 ;
goto V_44;
}
V_251 = V_38 -> V_254 << 16 ;
V_252 = V_38 -> V_255 << 16 ;
if ( V_249 -> V_256 > V_251 ||
V_249 -> V_257 > V_251 - V_249 -> V_256 ||
V_249 -> V_258 > V_252 ||
V_249 -> V_259 > V_252 - V_249 -> V_258 ) {
F_66 ( L_40
L_41 ,
V_249 -> V_256 >> 16 ,
( ( V_249 -> V_256 & 0xffff ) * 15625 ) >> 10 ,
V_249 -> V_258 >> 16 ,
( ( V_249 -> V_258 & 0xffff ) * 15625 ) >> 10 ,
V_249 -> V_257 >> 16 ,
( ( V_249 -> V_257 & 0xffff ) * 15625 ) >> 10 ,
V_249 -> V_259 >> 16 ,
( ( V_249 -> V_259 & 0xffff ) * 15625 ) >> 10 ) ;
V_31 = - V_260 ;
goto V_44;
}
if ( V_249 -> V_261 > V_157 ||
V_249 -> V_262 > V_157 - ( V_263 ) V_249 -> V_261 ||
V_249 -> V_264 > V_157 ||
V_249 -> V_265 > V_157 - ( V_263 ) V_249 -> V_264 ) {
F_66 ( L_42 ,
V_249 -> V_261 , V_249 -> V_264 ,
V_249 -> V_262 , V_249 -> V_265 ) ;
V_31 = - V_158 ;
goto V_44;
}
F_1 ( V_2 ) ;
V_31 = V_51 -> V_40 -> V_266 ( V_51 , V_4 , V_38 ,
V_249 -> V_262 , V_249 -> V_265 ,
V_249 -> V_261 , V_249 -> V_264 ,
V_249 -> V_257 , V_249 -> V_259 ,
V_249 -> V_256 , V_249 -> V_258 ) ;
if ( ! V_31 ) {
V_250 = V_51 -> V_38 ;
V_51 -> V_4 = V_4 ;
V_51 -> V_38 = V_38 ;
V_38 = NULL ;
}
F_5 ( V_2 ) ;
V_44:
if ( V_38 )
F_31 ( V_38 ) ;
if ( V_250 )
F_31 ( V_250 ) ;
return V_31 ;
}
int F_45 ( struct V_52 * V_53 )
{
struct V_3 * V_4 = V_53 -> V_4 ;
struct V_37 * V_38 ;
struct V_3 * V_267 ;
int V_31 ;
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_267 -> V_250 = V_267 -> V_38 ;
V_38 = V_53 -> V_38 ;
V_31 = V_4 -> V_40 -> V_268 ( V_53 ) ;
if ( V_31 == 0 ) {
F_8 ( V_38 != V_4 -> V_38 ) ;
}
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_267 -> V_38 )
F_24 ( V_267 -> V_38 ) ;
if ( V_267 -> V_250 )
F_31 ( V_267 -> V_250 ) ;
}
return V_31 ;
}
int F_101 ( struct V_1 * V_2 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_237 * V_238 = & V_2 -> V_5 ;
struct V_196 * V_269 = V_159 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
struct V_16 * * V_270 = NULL , * V_17 ;
struct V_37 * V_38 = NULL ;
struct V_61 * V_62 = NULL ;
struct V_52 V_53 ;
T_1 T_2 * V_271 ;
int V_31 ;
int V_108 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
if ( V_269 -> V_198 > V_157 || V_269 -> V_199 > V_157 )
return - V_158 ;
F_1 ( V_2 ) ;
V_29 = F_19 ( V_2 , V_269 -> V_172 ,
V_56 ) ;
if ( ! V_29 ) {
F_66 ( L_43 , V_269 -> V_172 ) ;
V_31 = - V_177 ;
goto V_44;
}
V_4 = F_91 ( V_29 ) ;
F_66 ( L_31 , V_4 -> V_14 . V_15 ) ;
if ( V_269 -> V_202 ) {
int V_143 , V_149 ;
if ( V_269 -> V_171 == - 1 ) {
if ( ! V_4 -> V_38 ) {
F_66 ( L_44 ) ;
V_31 = - V_177 ;
goto V_44;
}
V_38 = V_4 -> V_38 ;
F_24 ( V_38 ) ;
} else {
V_38 = F_30 ( V_2 , V_269 -> V_171 ) ;
if ( ! V_38 ) {
F_66 ( L_45 ,
V_269 -> V_171 ) ;
V_31 = - V_177 ;
goto V_44;
}
}
V_62 = F_68 ( V_2 ) ;
if ( ! V_62 ) {
V_31 = - V_87 ;
goto V_44;
}
V_31 = F_85 ( V_62 , & V_269 -> V_62 ) ;
if ( V_31 ) {
F_66 ( L_46 ) ;
goto V_44;
}
F_102 ( V_62 , V_272 ) ;
V_143 = V_62 -> V_143 ;
V_149 = V_62 -> V_149 ;
if ( V_4 -> V_55 )
F_103 ( V_143 , V_149 ) ;
if ( V_143 > V_38 -> V_254 ||
V_149 > V_38 -> V_255 ||
V_269 -> V_198 > V_38 -> V_254 - V_143 ||
V_269 -> V_199 > V_38 -> V_255 - V_149 ) {
F_66 ( L_47 ,
V_38 -> V_254 , V_38 -> V_255 ,
V_143 , V_149 , V_269 -> V_198 , V_269 -> V_199 ,
V_4 -> V_55 ? L_48 : L_49 ) ;
V_31 = - V_260 ;
goto V_44;
}
}
if ( V_269 -> V_193 == 0 && V_62 ) {
F_66 ( L_50 ) ;
V_31 = - V_177 ;
goto V_44;
}
if ( V_269 -> V_193 > 0 && ( ! V_62 || ! V_38 ) ) {
F_66 ( L_51 ,
V_269 -> V_193 ) ;
V_31 = - V_177 ;
goto V_44;
}
if ( V_269 -> V_193 > 0 ) {
T_4 V_273 ;
if ( V_269 -> V_193 > V_238 -> V_71 ) {
V_31 = - V_177 ;
goto V_44;
}
V_270 = F_65 ( V_269 -> V_193 *
sizeof( struct V_16 * ) ,
V_34 ) ;
if ( ! V_270 ) {
V_31 = - V_87 ;
goto V_44;
}
for ( V_108 = 0 ; V_108 < V_269 -> V_193 ; V_108 ++ ) {
V_271 = ( T_1 T_2 * ) ( unsigned long ) V_269 -> V_271 ;
if ( F_104 ( V_273 , & V_271 [ V_108 ] ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_29 = F_19 ( V_2 , V_273 ,
V_65 ) ;
if ( ! V_29 ) {
F_66 ( L_52 ,
V_273 ) ;
V_31 = - V_177 ;
goto V_44;
}
V_17 = F_93 ( V_29 ) ;
F_66 ( L_33 ,
V_17 -> V_14 . V_15 ,
F_11 ( V_17 ) ) ;
V_270 [ V_108 ] = V_17 ;
}
}
V_53 . V_4 = V_4 ;
V_53 . V_198 = V_269 -> V_198 ;
V_53 . V_199 = V_269 -> V_199 ;
V_53 . V_62 = V_62 ;
V_53 . V_274 = V_270 ;
V_53 . V_139 = V_269 -> V_193 ;
V_53 . V_38 = V_38 ;
V_31 = F_45 ( & V_53 ) ;
V_44:
if ( V_38 )
F_31 ( V_38 ) ;
F_52 ( V_270 ) ;
F_55 ( V_2 , V_62 ) ;
F_5 ( V_2 ) ;
return V_31 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_275 * V_276 ,
struct V_160 * V_161 )
{
struct V_28 * V_29 ;
struct V_3 * V_4 ;
int V_31 = 0 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
if ( ! V_276 -> V_155 || ( ~ V_277 & V_276 -> V_155 ) )
return - V_177 ;
V_29 = F_19 ( V_2 , V_276 -> V_172 , V_56 ) ;
if ( ! V_29 ) {
F_66 ( L_43 , V_276 -> V_172 ) ;
return - V_177 ;
}
V_4 = F_91 ( V_29 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_276 -> V_155 & V_278 ) {
if ( ! V_4 -> V_40 -> V_279 && ! V_4 -> V_40 -> V_280 ) {
V_31 = - V_281 ;
goto V_44;
}
if ( V_4 -> V_40 -> V_280 )
V_31 = V_4 -> V_40 -> V_280 ( V_4 , V_161 , V_276 -> V_282 ,
V_276 -> V_254 , V_276 -> V_255 , V_276 -> V_283 , V_276 -> V_284 ) ;
else
V_31 = V_4 -> V_40 -> V_279 ( V_4 , V_161 , V_276 -> V_282 ,
V_276 -> V_254 , V_276 -> V_255 ) ;
}
if ( V_276 -> V_155 & V_285 ) {
if ( V_4 -> V_40 -> V_286 ) {
V_31 = V_4 -> V_40 -> V_286 ( V_4 , V_276 -> V_198 , V_276 -> V_199 ) ;
} else {
V_31 = - V_181 ;
goto V_44;
}
}
V_44:
F_6 ( & V_4 -> V_6 ) ;
return V_31 ;
}
int F_106 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_287 * V_276 = V_159 ;
struct V_275 V_288 ;
memcpy ( & V_288 , V_276 , sizeof( struct V_287 ) ) ;
V_288 . V_283 = V_288 . V_284 = 0 ;
return F_105 ( V_2 , & V_288 , V_161 ) ;
}
int F_107 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_275 * V_276 = V_159 ;
return F_105 ( V_2 , V_276 , V_161 ) ;
}
T_1 F_108 ( T_1 V_289 , T_1 V_290 )
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
F_46 ( L_53 ) ;
V_291 = V_296 ;
break;
}
return V_291 ;
}
int F_109 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_299 * V_300 = V_159 ;
struct V_301 V_302 = {} ;
struct V_237 * V_238 = & V_2 -> V_5 ;
struct V_37 * V_38 ;
int V_31 = 0 ;
V_302 . V_171 = V_300 -> V_171 ;
V_302 . V_254 = V_300 -> V_254 ;
V_302 . V_255 = V_300 -> V_255 ;
V_302 . V_303 [ 0 ] = V_300 -> V_304 ;
V_302 . V_253 = F_108 ( V_300 -> V_289 , V_300 -> V_290 ) ;
V_302 . V_305 [ 0 ] = V_300 -> V_282 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
if ( ( V_238 -> V_188 > V_302 . V_254 ) || ( V_302 . V_254 > V_238 -> V_187 ) )
return - V_177 ;
if ( ( V_238 -> V_186 > V_302 . V_255 ) || ( V_302 . V_255 > V_238 -> V_185 ) )
return - V_177 ;
V_38 = V_2 -> V_5 . V_40 -> V_306 ( V_2 , V_161 , & V_302 ) ;
if ( F_110 ( V_38 ) ) {
F_66 ( L_54 ) ;
return F_111 ( V_38 ) ;
}
F_2 ( & V_161 -> V_178 ) ;
V_300 -> V_171 = V_38 -> V_14 . V_15 ;
F_25 ( & V_38 -> V_43 , & V_161 -> V_307 ) ;
F_66 ( L_55 , V_38 -> V_14 . V_15 ) ;
F_6 ( & V_161 -> V_178 ) ;
return V_31 ;
}
static int F_112 ( const struct V_301 * V_302 )
{
T_1 V_26 = V_302 -> V_253 & ~ V_27 ;
switch ( V_26 ) {
case V_292 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_293 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_294 :
case V_325 :
case V_295 :
case V_326 :
case V_296 :
case V_327 :
case V_328 :
case V_329 :
case V_298 :
case V_330 :
case V_331 :
case V_332 :
case V_297 :
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
case V_358 :
case V_359 :
case V_360 :
return 0 ;
default:
return - V_177 ;
}
}
static int F_113 ( const struct V_301 * V_302 )
{
int V_31 , V_361 , V_362 , V_363 , V_108 ;
V_31 = F_112 ( V_302 ) ;
if ( V_31 ) {
F_66 ( L_56 ,
F_14 ( V_302 -> V_253 ) ) ;
return V_31 ;
}
V_361 = F_114 ( V_302 -> V_253 ) ;
V_362 = F_115 ( V_302 -> V_253 ) ;
V_363 = F_116 ( V_302 -> V_253 ) ;
if ( V_302 -> V_254 == 0 || V_302 -> V_254 % V_361 ) {
F_66 ( L_57 , V_302 -> V_255 ) ;
return - V_177 ;
}
if ( V_302 -> V_255 == 0 || V_302 -> V_255 % V_362 ) {
F_66 ( L_58 , V_302 -> V_255 ) ;
return - V_177 ;
}
for ( V_108 = 0 ; V_108 < V_363 ; V_108 ++ ) {
unsigned int V_254 = V_302 -> V_254 / ( V_108 != 0 ? V_361 : 1 ) ;
unsigned int V_255 = V_302 -> V_255 / ( V_108 != 0 ? V_362 : 1 ) ;
unsigned int V_364 = F_117 ( V_302 -> V_253 , V_108 ) ;
if ( ! V_302 -> V_305 [ V_108 ] ) {
F_66 ( L_59 , V_108 ) ;
return - V_177 ;
}
if ( ( T_3 ) V_254 * V_364 > V_365 )
return - V_158 ;
if ( ( T_3 ) V_255 * V_302 -> V_303 [ V_108 ] + V_302 -> V_366 [ V_108 ] > V_365 )
return - V_158 ;
if ( V_302 -> V_303 [ V_108 ] < V_254 * V_364 ) {
F_66 ( L_60 , V_302 -> V_303 [ V_108 ] , V_108 ) ;
return - V_177 ;
}
}
return 0 ;
}
int F_118 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_301 * V_302 = V_159 ;
struct V_237 * V_238 = & V_2 -> V_5 ;
struct V_37 * V_38 ;
int V_31 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
if ( V_302 -> V_155 & ~ V_367 ) {
F_66 ( L_61 , V_302 -> V_155 ) ;
return - V_177 ;
}
if ( ( V_238 -> V_188 > V_302 -> V_254 ) || ( V_302 -> V_254 > V_238 -> V_187 ) ) {
F_66 ( L_62 ,
V_302 -> V_254 , V_238 -> V_188 , V_238 -> V_187 ) ;
return - V_177 ;
}
if ( ( V_238 -> V_186 > V_302 -> V_255 ) || ( V_302 -> V_255 > V_238 -> V_185 ) ) {
F_66 ( L_63 ,
V_302 -> V_255 , V_238 -> V_186 , V_238 -> V_185 ) ;
return - V_177 ;
}
V_31 = F_113 ( V_302 ) ;
if ( V_31 )
return V_31 ;
V_38 = V_2 -> V_5 . V_40 -> V_306 ( V_2 , V_161 , V_302 ) ;
if ( F_110 ( V_38 ) ) {
F_66 ( L_54 ) ;
return F_111 ( V_38 ) ;
}
F_2 ( & V_161 -> V_178 ) ;
V_302 -> V_171 = V_38 -> V_14 . V_15 ;
F_25 ( & V_38 -> V_43 , & V_161 -> V_307 ) ;
F_66 ( L_55 , V_38 -> V_14 . V_15 ) ;
F_6 ( & V_161 -> V_178 ) ;
return V_31 ;
}
int F_119 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_37 * V_38 = NULL ;
struct V_37 * V_368 = NULL ;
T_1 * V_15 = V_159 ;
int V_369 = 0 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_2 ( & V_161 -> V_178 ) ;
F_2 ( & V_2 -> V_5 . V_41 ) ;
V_38 = F_28 ( V_2 , * V_15 ) ;
if ( ! V_38 )
goto V_370;
F_3 (fbl, &file_priv->fbs, filp_head)
if ( V_38 == V_368 )
V_369 = 1 ;
if ( ! V_369 )
goto V_370;
F_38 ( V_2 , V_38 ) ;
F_120 ( & V_38 -> V_43 ) ;
F_6 ( & V_2 -> V_5 . V_41 ) ;
F_6 ( & V_161 -> V_178 ) ;
F_42 ( V_38 ) ;
return 0 ;
V_370:
F_6 ( & V_2 -> V_5 . V_41 ) ;
F_6 ( & V_161 -> V_178 ) ;
return - V_177 ;
}
int F_121 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_299 * V_302 = V_159 ;
struct V_37 * V_38 ;
int V_31 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
V_38 = F_30 ( V_2 , V_302 -> V_171 ) ;
if ( ! V_38 )
return - V_177 ;
V_302 -> V_255 = V_38 -> V_255 ;
V_302 -> V_254 = V_38 -> V_254 ;
V_302 -> V_290 = V_38 -> V_290 ;
V_302 -> V_289 = V_38 -> V_371 ;
V_302 -> V_304 = V_38 -> V_303 [ 0 ] ;
if ( V_38 -> V_40 -> V_372 )
V_31 = V_38 -> V_40 -> V_372 ( V_38 , V_161 , & V_302 -> V_282 ) ;
else
V_31 = - V_373 ;
F_31 ( V_38 ) ;
return V_31 ;
}
int F_122 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_374 T_2 * V_375 ;
struct V_374 * V_376 = NULL ;
struct V_377 * V_302 = V_159 ;
struct V_37 * V_38 ;
unsigned V_155 ;
int V_378 ;
int V_31 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
V_38 = F_30 ( V_2 , V_302 -> V_171 ) ;
if ( ! V_38 )
return - V_177 ;
V_378 = V_302 -> V_378 ;
V_375 = (struct V_374 T_2 * ) ( unsigned long ) V_302 -> V_375 ;
if ( ! V_378 != ! V_375 ) {
V_31 = - V_177 ;
goto V_379;
}
V_155 = V_380 & V_302 -> V_155 ;
if ( V_155 & V_381 && ( V_378 % 2 ) ) {
V_31 = - V_177 ;
goto V_379;
}
if ( V_378 && V_375 ) {
if ( V_378 < 0 || V_378 > V_382 ) {
V_31 = - V_177 ;
goto V_379;
}
V_376 = F_69 ( V_378 * sizeof( * V_376 ) , V_34 ) ;
if ( ! V_376 ) {
V_31 = - V_87 ;
goto V_379;
}
V_31 = F_123 ( V_376 , V_375 ,
V_378 * sizeof( * V_376 ) ) ;
if ( V_31 ) {
V_31 = - V_181 ;
goto V_383;
}
}
if ( V_38 -> V_40 -> V_384 ) {
F_1 ( V_2 ) ;
V_31 = V_38 -> V_40 -> V_384 ( V_38 , V_161 , V_155 , V_302 -> V_385 ,
V_376 , V_378 ) ;
F_5 ( V_2 ) ;
} else {
V_31 = - V_386 ;
}
V_383:
F_52 ( V_376 ) ;
V_379:
F_31 ( V_38 ) ;
return V_31 ;
}
void F_124 ( struct V_160 * V_84 )
{
struct V_1 * V_2 = V_84 -> V_183 -> V_2 ;
struct V_37 * V_38 , * V_387 ;
F_2 ( & V_84 -> V_178 ) ;
F_59 (fb, tfb, &priv->fbs, filp_head) {
F_2 ( & V_2 -> V_5 . V_41 ) ;
F_38 ( V_2 , V_38 ) ;
F_6 ( & V_2 -> V_5 . V_41 ) ;
F_120 ( & V_38 -> V_43 ) ;
F_42 ( V_38 ) ;
}
F_6 ( & V_84 -> V_178 ) ;
}
struct V_93 * F_71 ( struct V_1 * V_2 , int V_155 ,
const char * V_13 , int V_388 )
{
struct V_93 * V_389 = NULL ;
int V_31 ;
V_389 = F_69 ( sizeof( struct V_93 ) , V_34 ) ;
if ( ! V_389 )
return NULL ;
if ( V_388 ) {
V_389 -> V_230 = F_69 ( sizeof( T_3 ) * V_388 , V_34 ) ;
if ( ! V_389 -> V_230 )
goto V_390;
}
V_31 = F_15 ( V_2 , & V_389 -> V_14 , V_391 ) ;
if ( V_31 )
goto V_390;
V_389 -> V_155 = V_155 ;
V_389 -> V_388 = V_388 ;
F_23 ( & V_389 -> V_392 ) ;
if ( V_13 ) {
strncpy ( V_389 -> V_13 , V_13 , V_393 ) ;
V_389 -> V_13 [ V_393 - 1 ] = '\0' ;
}
F_50 ( & V_389 -> V_46 , & V_2 -> V_5 . V_394 ) ;
return V_389 ;
V_390:
F_52 ( V_389 -> V_230 ) ;
F_52 ( V_389 ) ;
return NULL ;
}
struct V_93 * F_72 ( struct V_1 * V_2 , int V_155 ,
const char * V_13 ,
const struct V_395 * V_396 ,
int V_388 )
{
struct V_93 * V_389 ;
int V_108 , V_31 ;
V_155 |= V_118 ;
V_389 = F_71 ( V_2 , V_155 , V_13 , V_388 ) ;
if ( ! V_389 )
return NULL ;
for ( V_108 = 0 ; V_108 < V_388 ; V_108 ++ ) {
V_31 = F_77 ( V_389 , V_108 ,
V_396 [ V_108 ] . type ,
V_396 [ V_108 ] . V_13 ) ;
if ( V_31 ) {
F_125 ( V_2 , V_389 ) ;
return NULL ;
}
}
return V_389 ;
}
struct V_93 * F_126 ( struct V_1 * V_2 ,
int V_155 , const char * V_13 ,
const struct V_395 * V_396 ,
int V_388 )
{
struct V_93 * V_389 ;
int V_108 , V_31 ;
V_155 |= V_397 ;
V_389 = F_71 ( V_2 , V_155 , V_13 , V_388 ) ;
if ( ! V_389 )
return NULL ;
for ( V_108 = 0 ; V_108 < V_388 ; V_108 ++ ) {
V_31 = F_77 ( V_389 , V_108 ,
V_396 [ V_108 ] . type ,
V_396 [ V_108 ] . V_13 ) ;
if ( V_31 ) {
F_125 ( V_2 , V_389 ) ;
return NULL ;
}
}
return V_389 ;
}
struct V_93 * F_76 ( struct V_1 * V_2 , int V_155 ,
const char * V_13 ,
T_3 V_398 , T_3 V_399 )
{
struct V_93 * V_389 ;
V_155 |= V_400 ;
V_389 = F_71 ( V_2 , V_155 , V_13 , 2 ) ;
if ( ! V_389 )
return NULL ;
V_389 -> V_230 [ 0 ] = V_398 ;
V_389 -> V_230 [ 1 ] = V_399 ;
return V_389 ;
}
int F_77 ( struct V_93 * V_389 , int V_401 ,
T_3 V_402 , const char * V_13 )
{
struct V_403 * V_404 ;
if ( ! ( V_389 -> V_155 & ( V_118 | V_397 ) ) )
return - V_177 ;
if ( ( V_389 -> V_155 & V_397 ) && ( V_402 > 63 ) )
return - V_177 ;
if ( ! F_43 ( & V_389 -> V_392 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( V_404 -> V_402 == V_402 ) {
strncpy ( V_404 -> V_13 , V_13 , V_393 ) ;
V_404 -> V_13 [ V_393 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_404 = F_69 ( sizeof( struct V_403 ) , V_34 ) ;
if ( ! V_404 )
return - V_87 ;
strncpy ( V_404 -> V_13 , V_13 , V_393 ) ;
V_404 -> V_13 [ V_393 - 1 ] = '\0' ;
V_404 -> V_402 = V_402 ;
V_389 -> V_230 [ V_401 ] = V_402 ;
F_50 ( & V_404 -> V_46 , & V_389 -> V_392 ) ;
return 0 ;
}
void F_125 ( struct V_1 * V_2 , struct V_93 * V_389 )
{
struct V_403 * V_404 , * V_405 ;
F_59 (prop_enum, pt, &property->enum_blob_list, head) {
F_41 ( & V_404 -> V_46 ) ;
F_52 ( V_404 ) ;
}
if ( V_389 -> V_388 )
F_52 ( V_389 -> V_230 ) ;
F_17 ( V_2 , & V_389 -> V_14 ) ;
F_41 ( & V_389 -> V_46 ) ;
F_52 ( V_389 ) ;
}
void F_57 ( struct V_28 * V_29 ,
struct V_93 * V_389 ,
T_3 V_406 )
{
int V_66 = V_29 -> V_57 -> V_66 ;
if ( V_66 == V_407 ) {
F_84 ( 1 , L_64
L_65
L_66 ,
V_29 -> type ) ;
return;
}
V_29 -> V_57 -> V_229 [ V_66 ] = V_389 -> V_14 . V_15 ;
V_29 -> V_57 -> V_230 [ V_66 ] = V_406 ;
V_29 -> V_57 -> V_66 ++ ;
}
int F_127 ( struct V_28 * V_29 ,
struct V_93 * V_389 , T_3 V_408 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_29 -> V_57 -> V_66 ; V_108 ++ ) {
if ( V_29 -> V_57 -> V_229 [ V_108 ] == V_389 -> V_14 . V_15 ) {
V_29 -> V_57 -> V_230 [ V_108 ] = V_408 ;
return 0 ;
}
}
return - V_177 ;
}
int F_128 ( struct V_28 * V_29 ,
struct V_93 * V_389 , T_3 * V_408 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_29 -> V_57 -> V_66 ; V_108 ++ ) {
if ( V_29 -> V_57 -> V_229 [ V_108 ] == V_389 -> V_14 . V_15 ) {
* V_408 = V_29 -> V_57 -> V_230 [ V_108 ] ;
return 0 ;
}
}
return - V_177 ;
}
int F_129 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_28 * V_29 ;
struct V_409 * V_204 = V_159 ;
struct V_93 * V_389 ;
int V_410 = 0 ;
int V_411 = 0 ;
int V_412 = 0 ;
int V_31 = 0 , V_108 ;
int V_170 ;
struct V_403 * V_404 ;
struct V_413 T_2 * V_414 ;
struct V_415 * V_416 ;
T_1 T_2 * V_417 ;
T_3 T_2 * V_418 ;
T_1 T_2 * V_419 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_29 = F_19 ( V_2 , V_204 -> V_420 , V_391 ) ;
if ( ! V_29 ) {
V_31 = - V_177 ;
goto V_421;
}
V_389 = F_130 ( V_29 ) ;
if ( V_389 -> V_155 & ( V_118 | V_397 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head)
V_410 ++ ;
} else if ( V_389 -> V_155 & V_96 ) {
F_3 (prop_blob, &property->enum_blob_list, head)
V_411 ++ ;
}
V_412 = V_389 -> V_388 ;
strncpy ( V_204 -> V_13 , V_389 -> V_13 , V_393 ) ;
V_204 -> V_13 [ V_393 - 1 ] = 0 ;
V_204 -> V_155 = V_389 -> V_155 ;
if ( ( V_204 -> V_422 >= V_412 ) && V_412 ) {
V_418 = ( T_3 T_2 * ) ( unsigned long ) V_204 -> V_418 ;
for ( V_108 = 0 ; V_108 < V_412 ; V_108 ++ ) {
if ( F_94 ( V_418 + V_108 , & V_389 -> V_230 [ V_108 ] , sizeof( T_3 ) ) ) {
V_31 = - V_181 ;
goto V_421;
}
}
}
V_204 -> V_422 = V_412 ;
if ( V_389 -> V_155 & ( V_118 | V_397 ) ) {
if ( ( V_204 -> V_423 >= V_410 ) && V_410 ) {
V_170 = 0 ;
V_414 = (struct V_413 T_2 * ) ( unsigned long ) V_204 -> V_424 ;
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( F_94 ( & V_414 [ V_170 ] . V_402 , & V_404 -> V_402 , sizeof( T_3 ) ) ) {
V_31 = - V_181 ;
goto V_421;
}
if ( F_94 ( & V_414 [ V_170 ] . V_13 ,
& V_404 -> V_13 , V_393 ) ) {
V_31 = - V_181 ;
goto V_421;
}
V_170 ++ ;
}
}
V_204 -> V_423 = V_410 ;
}
if ( V_389 -> V_155 & V_96 ) {
if ( ( V_204 -> V_423 >= V_411 ) && V_411 ) {
V_170 = 0 ;
V_417 = ( T_1 T_2 * ) ( unsigned long ) V_204 -> V_424 ;
V_419 = ( T_1 T_2 * ) ( unsigned long ) V_204 -> V_418 ;
F_3 (prop_blob, &property->enum_blob_list, head) {
if ( F_89 ( V_416 -> V_14 . V_15 , V_417 + V_170 ) ) {
V_31 = - V_181 ;
goto V_421;
}
if ( F_89 ( V_416 -> V_425 , V_419 + V_170 ) ) {
V_31 = - V_181 ;
goto V_421;
}
V_170 ++ ;
}
}
V_204 -> V_423 = V_411 ;
}
V_421:
F_5 ( V_2 ) ;
return V_31 ;
}
static struct V_415 * F_131 ( struct V_1 * V_2 , int V_425 ,
void * V_159 )
{
struct V_415 * V_426 ;
int V_31 ;
if ( ! V_425 || ! V_159 )
return NULL ;
V_426 = F_69 ( sizeof( struct V_415 ) + V_425 , V_34 ) ;
if ( ! V_426 )
return NULL ;
V_31 = F_15 ( V_2 , & V_426 -> V_14 , V_427 ) ;
if ( V_31 ) {
F_52 ( V_426 ) ;
return NULL ;
}
V_426 -> V_425 = V_425 ;
memcpy ( V_426 -> V_159 , V_159 , V_425 ) ;
F_50 ( & V_426 -> V_46 , & V_2 -> V_5 . V_428 ) ;
return V_426 ;
}
static void F_132 ( struct V_1 * V_2 ,
struct V_415 * V_426 )
{
F_17 ( V_2 , & V_426 -> V_14 ) ;
F_41 ( & V_426 -> V_46 ) ;
F_52 ( V_426 ) ;
}
int F_133 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_28 * V_29 ;
struct V_429 * V_204 = V_159 ;
struct V_415 * V_426 ;
int V_31 = 0 ;
void T_2 * V_430 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_29 = F_19 ( V_2 , V_204 -> V_431 , V_427 ) ;
if ( ! V_29 ) {
V_31 = - V_177 ;
goto V_421;
}
V_426 = F_134 ( V_29 ) ;
if ( V_204 -> V_425 == V_426 -> V_425 ) {
V_430 = ( void T_2 * ) ( unsigned long ) V_204 -> V_159 ;
if ( F_94 ( V_430 , V_426 -> V_159 , V_426 -> V_425 ) ) {
V_31 = - V_181 ;
goto V_421;
}
}
V_204 -> V_425 = V_426 -> V_425 ;
V_421:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_135 ( struct V_16 * V_17 ,
struct V_94 * V_94 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
int V_31 , V_432 ;
if ( V_17 -> V_68 )
F_132 ( V_2 , V_17 -> V_68 ) ;
if ( ! V_94 ) {
V_17 -> V_68 = NULL ;
V_31 = F_127 ( & V_17 -> V_14 , V_2 -> V_5 . V_73 , 0 ) ;
return V_31 ;
}
V_432 = V_433 * ( 1 + V_94 -> V_434 ) ;
V_17 -> V_68 = F_131 ( V_17 -> V_2 ,
V_432 , V_94 ) ;
if ( ! V_17 -> V_68 )
return - V_177 ;
V_31 = F_127 ( & V_17 -> V_14 ,
V_2 -> V_5 . V_73 ,
V_17 -> V_68 -> V_14 . V_15 ) ;
return V_31 ;
}
static bool F_136 ( struct V_93 * V_389 ,
T_3 V_402 )
{
if ( V_389 -> V_155 & V_97 )
return false ;
if ( V_389 -> V_155 & V_400 ) {
if ( V_402 < V_389 -> V_230 [ 0 ] || V_402 > V_389 -> V_230 [ 1 ] )
return false ;
return true ;
} else if ( V_389 -> V_155 & V_397 ) {
int V_108 ;
T_3 V_435 = 0 ;
for ( V_108 = 0 ; V_108 < V_389 -> V_388 ; V_108 ++ )
V_435 |= ( 1ULL << V_389 -> V_230 [ V_108 ] ) ;
return ! ( V_402 & ~ V_435 ) ;
} else if ( V_389 -> V_155 & V_96 ) {
return true ;
} else {
int V_108 ;
for ( V_108 = 0 ; V_108 < V_389 -> V_388 ; V_108 ++ )
if ( V_389 -> V_230 [ V_108 ] == V_402 )
return true ;
return false ;
}
}
int F_137 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_436 * V_437 = V_159 ;
struct V_438 V_439 = {
. V_402 = V_437 -> V_402 ,
. V_420 = V_437 -> V_420 ,
. V_440 = V_437 -> V_173 ,
. V_30 = V_65
} ;
return F_138 ( V_2 , & V_439 , V_161 ) ;
}
static int F_139 ( struct V_28 * V_29 ,
struct V_93 * V_389 ,
T_3 V_402 )
{
int V_31 = - V_177 ;
struct V_16 * V_17 = F_93 ( V_29 ) ;
if ( V_389 == V_17 -> V_2 -> V_5 . V_74 ) {
if ( V_17 -> V_40 -> V_95 )
(* V_17 -> V_40 -> V_95 )( V_17 , ( int ) V_402 ) ;
V_31 = 0 ;
} else if ( V_17 -> V_40 -> V_441 )
V_31 = V_17 -> V_40 -> V_441 ( V_17 , V_389 , V_402 ) ;
if ( ! V_31 )
F_127 ( & V_17 -> V_14 , V_389 , V_402 ) ;
return V_31 ;
}
static int F_140 ( struct V_28 * V_29 ,
struct V_93 * V_389 ,
T_3 V_402 )
{
int V_31 = - V_177 ;
struct V_3 * V_4 = F_91 ( V_29 ) ;
if ( V_4 -> V_40 -> V_441 )
V_31 = V_4 -> V_40 -> V_441 ( V_4 , V_389 , V_402 ) ;
if ( ! V_31 )
F_127 ( V_29 , V_389 , V_402 ) ;
return V_31 ;
}
static int F_141 ( struct V_28 * V_29 ,
struct V_93 * V_389 ,
T_3 V_402 )
{
int V_31 = - V_177 ;
struct V_50 * V_51 = F_99 ( V_29 ) ;
if ( V_51 -> V_40 -> V_441 )
V_31 = V_51 -> V_40 -> V_441 ( V_51 , V_389 , V_402 ) ;
if ( ! V_31 )
F_127 ( V_29 , V_389 , V_402 ) ;
return V_31 ;
}
int F_142 ( struct V_1 * V_2 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_442 * V_443 = V_159 ;
struct V_28 * V_29 ;
int V_31 = 0 ;
int V_108 ;
int V_170 = 0 ;
int V_206 = 0 ;
T_1 T_2 * V_227 ;
T_3 T_2 * V_228 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_29 = F_19 ( V_2 , V_443 -> V_440 , V_443 -> V_30 ) ;
if ( ! V_29 ) {
V_31 = - V_177 ;
goto V_44;
}
if ( ! V_29 -> V_57 ) {
V_31 = - V_177 ;
goto V_44;
}
V_206 = V_29 -> V_57 -> V_66 ;
if ( ( V_443 -> V_226 >= V_206 ) && V_206 ) {
V_170 = 0 ;
V_227 = ( T_1 T_2 * ) ( unsigned long ) ( V_443 -> V_227 ) ;
V_228 = ( T_3 T_2 * ) ( unsigned long )
( V_443 -> V_228 ) ;
for ( V_108 = 0 ; V_108 < V_206 ; V_108 ++ ) {
if ( F_89 ( V_29 -> V_57 -> V_229 [ V_108 ] ,
V_227 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
if ( F_89 ( V_29 -> V_57 -> V_230 [ V_108 ] ,
V_228 + V_170 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_170 ++ ;
}
}
V_443 -> V_226 = V_206 ;
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_138 ( struct V_1 * V_2 , void * V_159 ,
struct V_160 * V_161 )
{
struct V_438 * V_443 = V_159 ;
struct V_28 * V_444 ;
struct V_28 * V_445 ;
struct V_93 * V_389 ;
int V_31 = - V_177 ;
int V_108 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_444 = F_19 ( V_2 , V_443 -> V_440 , V_443 -> V_30 ) ;
if ( ! V_444 )
goto V_44;
if ( ! V_444 -> V_57 )
goto V_44;
for ( V_108 = 0 ; V_108 < V_444 -> V_57 -> V_66 ; V_108 ++ )
if ( V_444 -> V_57 -> V_229 [ V_108 ] == V_443 -> V_420 )
break;
if ( V_108 == V_444 -> V_57 -> V_66 )
goto V_44;
V_445 = F_19 ( V_2 , V_443 -> V_420 ,
V_391 ) ;
if ( ! V_445 )
goto V_44;
V_389 = F_130 ( V_445 ) ;
if ( ! F_136 ( V_389 , V_443 -> V_402 ) )
goto V_44;
switch ( V_444 -> type ) {
case V_65 :
V_31 = F_139 ( V_444 , V_389 ,
V_443 -> V_402 ) ;
break;
case V_56 :
V_31 = F_140 ( V_444 , V_389 , V_443 -> V_402 ) ;
break;
case V_85 :
V_31 = F_141 ( V_444 , V_389 , V_443 -> V_402 ) ;
break;
}
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_143 ( struct V_16 * V_17 ,
struct V_8 * V_9 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_213 ; V_108 ++ ) {
if ( V_17 -> V_214 [ V_108 ] == 0 ) {
V_17 -> V_214 [ V_108 ] = V_9 -> V_14 . V_15 ;
return 0 ;
}
}
return - V_87 ;
}
void F_144 ( struct V_16 * V_17 ,
struct V_8 * V_9 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_213 ; V_108 ++ ) {
if ( V_17 -> V_214 [ V_108 ] == V_9 -> V_14 . V_15 ) {
V_17 -> V_214 [ V_108 ] = 0 ;
if ( V_17 -> V_9 == V_9 )
V_17 -> V_9 = NULL ;
break;
}
}
}
int F_145 ( struct V_3 * V_4 ,
int V_200 )
{
V_4 -> V_200 = V_200 ;
V_4 -> V_60 = F_69 ( V_200 * sizeof( V_446 ) * 3 , V_34 ) ;
if ( ! V_4 -> V_60 ) {
V_4 -> V_200 = 0 ;
return - V_87 ;
}
return 0 ;
}
int F_146 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_447 * V_448 = V_159 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
void * V_449 , * V_450 , * V_451 ;
int V_432 ;
int V_31 = 0 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_29 = F_19 ( V_2 , V_448 -> V_172 , V_56 ) ;
if ( ! V_29 ) {
V_31 = - V_177 ;
goto V_44;
}
V_4 = F_91 ( V_29 ) ;
if ( V_4 -> V_40 -> V_452 == NULL ) {
V_31 = - V_386 ;
goto V_44;
}
if ( V_448 -> V_200 != V_4 -> V_200 ) {
V_31 = - V_177 ;
goto V_44;
}
V_432 = V_448 -> V_200 * ( sizeof( V_446 ) ) ;
V_449 = V_4 -> V_60 ;
if ( F_123 ( V_449 , ( void T_2 * ) ( unsigned long ) V_448 -> V_453 , V_432 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_450 = V_449 + V_432 ;
if ( F_123 ( V_450 , ( void T_2 * ) ( unsigned long ) V_448 -> V_454 , V_432 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_451 = V_450 + V_432 ;
if ( F_123 ( V_451 , ( void T_2 * ) ( unsigned long ) V_448 -> V_455 , V_432 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_4 -> V_40 -> V_452 ( V_4 , V_449 , V_450 , V_451 , 0 , V_4 -> V_200 ) ;
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_147 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_447 * V_448 = V_159 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
void * V_449 , * V_450 , * V_451 ;
int V_432 ;
int V_31 = 0 ;
if ( ! F_87 ( V_2 , V_176 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_29 = F_19 ( V_2 , V_448 -> V_172 , V_56 ) ;
if ( ! V_29 ) {
V_31 = - V_177 ;
goto V_44;
}
V_4 = F_91 ( V_29 ) ;
if ( V_448 -> V_200 != V_4 -> V_200 ) {
V_31 = - V_177 ;
goto V_44;
}
V_432 = V_448 -> V_200 * ( sizeof( V_446 ) ) ;
V_449 = V_4 -> V_60 ;
if ( F_94 ( ( void T_2 * ) ( unsigned long ) V_448 -> V_453 , V_449 , V_432 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_450 = V_449 + V_432 ;
if ( F_94 ( ( void T_2 * ) ( unsigned long ) V_448 -> V_454 , V_450 , V_432 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_451 = V_450 + V_432 ;
if ( F_94 ( ( void T_2 * ) ( unsigned long ) V_448 -> V_455 , V_451 , V_432 ) ) {
V_31 = - V_181 ;
goto V_44;
}
V_44:
F_5 ( V_2 ) ;
return V_31 ;
}
int F_148 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_456 * V_457 = V_159 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
struct V_37 * V_38 = NULL , * V_250 = NULL ;
struct V_458 * V_459 = NULL ;
unsigned long V_155 ;
int V_143 , V_149 ;
int V_31 = - V_177 ;
if ( V_457 -> V_155 & ~ V_460 ||
V_457 -> V_461 != 0 )
return - V_177 ;
V_29 = F_19 ( V_2 , V_457 -> V_172 , V_56 ) ;
if ( ! V_29 )
return - V_177 ;
V_4 = F_91 ( V_29 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_38 == NULL ) {
V_31 = - V_462 ;
goto V_44;
}
if ( V_4 -> V_40 -> V_457 == NULL )
goto V_44;
V_38 = F_30 ( V_2 , V_457 -> V_171 ) ;
if ( ! V_38 )
goto V_44;
V_143 = V_4 -> V_62 . V_143 ;
V_149 = V_4 -> V_62 . V_149 ;
if ( V_4 -> V_55 )
F_103 ( V_143 , V_149 ) ;
if ( V_143 > V_38 -> V_254 ||
V_149 > V_38 -> V_255 ||
V_4 -> V_198 > V_38 -> V_254 - V_143 ||
V_4 -> V_199 > V_38 -> V_255 - V_149 ) {
F_66 ( L_47 ,
V_38 -> V_254 , V_38 -> V_255 , V_143 , V_149 , V_4 -> V_198 , V_4 -> V_199 ,
V_4 -> V_55 ? L_48 : L_49 ) ;
V_31 = - V_260 ;
goto V_44;
}
if ( V_4 -> V_38 -> V_253 != V_38 -> V_253 ) {
F_66 ( L_67 ) ;
V_31 = - V_177 ;
goto V_44;
}
if ( V_457 -> V_155 & V_463 ) {
V_31 = - V_87 ;
F_149 ( & V_2 -> V_464 , V_155 ) ;
if ( V_161 -> V_465 < sizeof V_459 -> V_466 ) {
F_150 ( & V_2 -> V_464 , V_155 ) ;
goto V_44;
}
V_161 -> V_465 -= sizeof V_459 -> V_466 ;
F_150 ( & V_2 -> V_464 , V_155 ) ;
V_459 = F_69 ( sizeof *V_459 , V_34 ) ;
if ( V_459 == NULL ) {
F_149 ( & V_2 -> V_464 , V_155 ) ;
V_161 -> V_465 += sizeof V_459 -> V_466 ;
F_150 ( & V_2 -> V_464 , V_155 ) ;
goto V_44;
}
V_459 -> V_466 . V_14 . type = V_467 ;
V_459 -> V_466 . V_14 . V_425 = sizeof V_459 -> V_466 ;
V_459 -> V_466 . V_468 = V_457 -> V_468 ;
V_459 -> V_14 . V_466 = & V_459 -> V_466 . V_14 ;
V_459 -> V_14 . V_161 = V_161 ;
V_459 -> V_14 . V_49 =
( void ( * ) ( struct V_469 * ) ) F_52 ;
}
V_250 = V_4 -> V_38 ;
V_31 = V_4 -> V_40 -> V_457 ( V_4 , V_38 , V_459 ) ;
if ( V_31 ) {
if ( V_457 -> V_155 & V_463 ) {
F_149 ( & V_2 -> V_464 , V_155 ) ;
V_161 -> V_465 += sizeof V_459 -> V_466 ;
F_150 ( & V_2 -> V_464 , V_155 ) ;
F_52 ( V_459 ) ;
}
V_250 = NULL ;
} else {
F_8 ( V_4 -> V_38 != V_38 ) ;
V_38 = NULL ;
}
V_44:
if ( V_38 )
F_31 ( V_38 ) ;
if ( V_250 )
F_31 ( V_250 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_31 ;
}
void F_151 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
if ( V_4 -> V_40 -> V_470 )
V_4 -> V_40 -> V_470 ( V_4 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
if ( V_9 -> V_40 -> V_470 )
V_9 -> V_40 -> V_470 ( V_9 ) ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_17 -> V_22 = V_69 ;
if ( V_17 -> V_40 -> V_470 )
V_17 -> V_40 -> V_470 ( V_17 ) ;
}
}
int F_152 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_471 * args = V_159 ;
if ( ! V_2 -> V_472 -> V_473 )
return - V_386 ;
return V_2 -> V_472 -> V_473 ( V_161 , V_2 , args ) ;
}
int F_153 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_474 * args = V_159 ;
if ( ! V_2 -> V_472 -> V_475 )
return - V_386 ;
return V_2 -> V_472 -> V_475 ( V_161 , V_2 , args -> V_282 , & args -> V_476 ) ;
}
int F_154 ( struct V_1 * V_2 ,
void * V_159 , struct V_160 * V_161 )
{
struct V_477 * args = V_159 ;
if ( ! V_2 -> V_472 -> V_478 )
return - V_386 ;
return V_2 -> V_472 -> V_478 ( V_161 , V_2 , args -> V_282 ) ;
}
void F_155 ( T_1 V_26 , unsigned int * V_290 ,
int * V_289 )
{
switch ( V_26 ) {
case V_292 :
case V_308 :
case V_309 :
* V_290 = 8 ;
* V_289 = 8 ;
break;
case V_293 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
* V_290 = 15 ;
* V_289 = 16 ;
break;
case V_294 :
case V_325 :
* V_290 = 16 ;
* V_289 = 16 ;
break;
case V_295 :
case V_326 :
* V_290 = 24 ;
* V_289 = 24 ;
break;
case V_296 :
case V_327 :
case V_328 :
case V_329 :
* V_290 = 24 ;
* V_289 = 32 ;
break;
case V_297 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
* V_290 = 30 ;
* V_289 = 32 ;
break;
case V_298 :
case V_330 :
case V_331 :
case V_332 :
* V_290 = 32 ;
* V_289 = 32 ;
break;
default:
F_66 ( L_68 ) ;
* V_290 = 0 ;
* V_289 = 0 ;
break;
}
}
int F_116 ( T_1 V_26 )
{
switch ( V_26 ) {
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
return 3 ;
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
return 2 ;
default:
return 1 ;
}
}
int F_117 ( T_1 V_26 , int V_51 )
{
unsigned int V_290 ;
int V_289 ;
if ( V_51 >= F_116 ( V_26 ) )
return 0 ;
switch ( V_26 ) {
case V_340 :
case V_341 :
case V_342 :
case V_343 :
return 2 ;
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
return V_51 ? 2 : 1 ;
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
return 1 ;
default:
F_155 ( V_26 , & V_290 , & V_289 ) ;
return V_289 >> 3 ;
}
}
int F_114 ( T_1 V_26 )
{
switch ( V_26 ) {
case V_353 :
case V_354 :
case V_351 :
case V_352 :
return 4 ;
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_357 :
case V_358 :
case V_355 :
case V_356 :
return 2 ;
default:
return 1 ;
}
}
int F_115 ( T_1 V_26 )
{
switch ( V_26 ) {
case V_351 :
case V_352 :
return 4 ;
case V_355 :
case V_356 :
case V_345 :
case V_346 :
return 2 ;
default:
return 1 ;
}
}
void F_156 ( struct V_1 * V_2 )
{
F_49 ( & V_2 -> V_5 . V_6 ) ;
F_49 ( & V_2 -> V_5 . V_32 ) ;
F_49 ( & V_2 -> V_5 . V_41 ) ;
F_23 ( & V_2 -> V_5 . V_47 ) ;
F_23 ( & V_2 -> V_5 . V_58 ) ;
F_23 ( & V_2 -> V_5 . V_70 ) ;
F_23 ( & V_2 -> V_5 . V_78 ) ;
F_23 ( & V_2 -> V_5 . V_394 ) ;
F_23 ( & V_2 -> V_5 . V_428 ) ;
F_23 ( & V_2 -> V_5 . V_88 ) ;
F_157 ( & V_2 -> V_5 . V_33 ) ;
F_1 ( V_2 ) ;
F_70 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_5 . V_45 = 0 ;
V_2 -> V_5 . V_71 = 0 ;
V_2 -> V_5 . V_59 = 0 ;
V_2 -> V_5 . V_79 = 0 ;
}
void F_158 ( struct V_1 * V_2 )
{
struct V_16 * V_17 , * V_479 ;
struct V_3 * V_4 , * V_480 ;
struct V_8 * V_9 , * V_481 ;
struct V_37 * V_38 , * V_482 ;
struct V_93 * V_389 , * V_405 ;
struct V_415 * V_426 , * V_483 ;
struct V_50 * V_51 , * V_484 ;
F_59 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_9 -> V_40 -> V_49 ( V_9 ) ;
}
F_59 (connector, ot,
&dev->mode_config.connector_list, head) {
V_17 -> V_40 -> V_49 ( V_17 ) ;
}
F_59 (property, pt, &dev->mode_config.property_list,
head) {
F_125 ( V_2 , V_389 ) ;
}
F_59 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_132 ( V_2 , V_426 ) ;
}
F_8 ( ! F_43 ( & V_2 -> V_5 . V_47 ) ) ;
F_59 (fb, fbt, &dev->mode_config.fb_list, head) {
F_42 ( V_38 ) ;
}
F_59 (plane, plt, &dev->mode_config.plane_list,
head) {
V_51 -> V_40 -> V_49 ( V_51 ) ;
}
F_59 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_4 -> V_40 -> V_49 ( V_4 ) ;
}
F_159 ( & V_2 -> V_5 . V_33 ) ;
}
