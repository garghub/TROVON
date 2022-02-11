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
F_3 (crtc, &dev->mode_config.crtc_list, head)
F_8 ( ! F_9 ( & V_4 -> V_6 ) ) ;
F_8 ( ! F_9 ( & V_2 -> V_5 . V_6 ) ) ;
}
char * F_10 ( struct V_7 * V_8 )
{
static char V_9 [ 32 ] ;
snprintf ( V_9 , 32 , L_1 ,
V_10 [ V_8 -> V_11 ] . V_12 ,
V_8 -> V_13 . V_14 ) ;
return V_9 ;
}
char * F_11 ( struct V_15 * V_16 )
{
static char V_9 [ 32 ] ;
snprintf ( V_9 , 32 , L_1 ,
V_17 [ V_16 -> V_18 ] . V_12 ,
V_16 -> V_19 ) ;
return V_9 ;
}
char * F_12 ( enum V_20 V_21 )
{
if ( V_21 == V_22 )
return L_2 ;
else if ( V_21 == V_23 )
return L_3 ;
else
return L_4 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_24 * V_25 , T_1 V_26 )
{
int V_27 ;
F_2 ( & V_2 -> V_5 . V_28 ) ;
V_27 = F_14 ( & V_2 -> V_5 . V_29 , V_25 , 1 , 0 , V_30 ) ;
if ( V_27 >= 0 ) {
V_25 -> V_14 = V_27 ;
V_25 -> type = V_26 ;
}
F_6 ( & V_2 -> V_5 . V_28 ) ;
return V_27 < 0 ? V_27 : 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_24 * V_31 )
{
F_2 ( & V_2 -> V_5 . V_28 ) ;
F_16 ( & V_2 -> V_5 . V_29 , V_31 -> V_14 ) ;
F_6 ( & V_2 -> V_5 . V_28 ) ;
}
struct V_24 * F_17 ( struct V_1 * V_2 ,
T_1 V_14 , T_1 type )
{
struct V_24 * V_25 = NULL ;
F_8 ( type == V_32 ) ;
F_2 ( & V_2 -> V_5 . V_28 ) ;
V_25 = F_18 ( & V_2 -> V_5 . V_29 , V_14 ) ;
if ( ! V_25 || ( V_25 -> type != type ) || ( V_25 -> V_14 != V_14 ) )
V_25 = NULL ;
F_6 ( & V_2 -> V_5 . V_28 ) ;
return V_25 ;
}
int F_19 ( struct V_1 * V_2 , struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
int V_27 ;
F_2 ( & V_2 -> V_5 . V_37 ) ;
F_20 ( & V_34 -> V_38 ) ;
F_21 ( & V_34 -> V_39 ) ;
V_34 -> V_2 = V_2 ;
V_34 -> V_36 = V_36 ;
V_27 = F_13 ( V_2 , & V_34 -> V_13 , V_32 ) ;
if ( V_27 )
goto V_40;
F_22 ( V_34 ) ;
V_2 -> V_5 . V_41 ++ ;
F_23 ( & V_34 -> V_42 , & V_2 -> V_5 . V_43 ) ;
V_40:
F_6 ( & V_2 -> V_5 . V_37 ) ;
return 0 ;
}
static void F_24 ( struct V_44 * V_44 )
{
struct V_33 * V_34 =
F_25 ( V_44 , struct V_33 , V_38 ) ;
V_34 -> V_36 -> V_45 ( V_34 ) ;
}
static struct V_33 * F_26 ( struct V_1 * V_2 ,
T_1 V_14 )
{
struct V_24 * V_25 = NULL ;
struct V_33 * V_34 ;
F_2 ( & V_2 -> V_5 . V_28 ) ;
V_25 = F_18 ( & V_2 -> V_5 . V_29 , V_14 ) ;
if ( ! V_25 || ( V_25 -> type != V_32 ) || ( V_25 -> V_14 != V_14 ) )
V_34 = NULL ;
else
V_34 = F_27 ( V_25 ) ;
F_6 ( & V_2 -> V_5 . V_28 ) ;
return V_34 ;
}
struct V_33 * F_28 ( struct V_1 * V_2 ,
T_1 V_14 )
{
struct V_33 * V_34 ;
F_2 ( & V_2 -> V_5 . V_37 ) ;
V_34 = F_26 ( V_2 , V_14 ) ;
if ( V_34 )
F_29 ( & V_34 -> V_38 ) ;
F_6 ( & V_2 -> V_5 . V_37 ) ;
return V_34 ;
}
void F_30 ( struct V_33 * V_34 )
{
F_31 ( L_5 , V_34 -> V_13 . V_14 ) ;
F_32 ( & V_34 -> V_38 , F_24 ) ;
}
void F_22 ( struct V_33 * V_34 )
{
F_31 ( L_5 , V_34 -> V_13 . V_14 ) ;
F_29 ( & V_34 -> V_38 ) ;
}
static void F_33 ( struct V_44 * V_44 )
{
F_34 () ;
}
static void F_35 ( struct V_33 * V_34 )
{
F_31 ( L_5 , V_34 -> V_13 . V_14 ) ;
F_32 ( & V_34 -> V_38 , F_33 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
F_2 ( & V_2 -> V_5 . V_28 ) ;
F_16 ( & V_2 -> V_5 . V_29 , V_34 -> V_13 . V_14 ) ;
F_6 ( & V_2 -> V_5 . V_28 ) ;
V_34 -> V_13 . V_14 = 0 ;
F_35 ( V_34 ) ;
}
void F_37 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_37 ) ;
F_36 ( V_2 , V_34 ) ;
F_6 ( & V_2 -> V_5 . V_37 ) ;
}
void F_38 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_37 ) ;
F_39 ( & V_34 -> V_42 ) ;
V_2 -> V_5 . V_41 -- ;
F_6 ( & V_2 -> V_5 . V_37 ) ;
}
void F_40 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_3 * V_4 ;
struct V_46 * V_47 ;
struct V_48 V_49 ;
int V_27 ;
F_8 ( ! F_41 ( & V_34 -> V_39 ) ) ;
if ( F_42 ( & V_34 -> V_38 . V_38 ) > 1 ) {
F_1 ( V_2 ) ;
F_3 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_4 -> V_34 == V_34 ) {
memset ( & V_49 , 0 , sizeof( struct V_48 ) ) ;
V_49 . V_4 = V_4 ;
V_49 . V_34 = NULL ;
V_27 = F_43 ( & V_49 ) ;
if ( V_27 )
F_44 ( L_6 , V_4 ) ;
}
}
F_3 (plane, &dev->mode_config.plane_list, head) {
if ( V_47 -> V_34 == V_34 ) {
V_27 = V_47 -> V_36 -> V_50 ( V_47 ) ;
if ( V_27 )
F_44 ( L_7 ) ;
F_35 ( V_47 -> V_34 ) ;
V_47 -> V_34 = NULL ;
V_47 -> V_4 = NULL ;
}
}
F_5 ( V_2 ) ;
}
F_30 ( V_34 ) ;
}
int F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_51 * V_36 )
{
int V_27 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_36 = V_36 ;
V_4 -> V_52 = false ;
F_1 ( V_2 ) ;
F_46 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_6 , & V_2 -> V_5 . V_6 ) ;
V_27 = F_13 ( V_2 , & V_4 -> V_13 , V_53 ) ;
if ( V_27 )
goto V_40;
V_4 -> V_13 . V_54 = & V_4 -> V_54 ;
F_47 ( & V_4 -> V_42 , & V_2 -> V_5 . V_55 ) ;
V_2 -> V_5 . V_56 ++ ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
void F_48 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_49 ( V_4 -> V_57 ) ;
V_4 -> V_57 = NULL ;
F_15 ( V_2 , & V_4 -> V_13 ) ;
F_39 ( & V_4 -> V_42 ) ;
V_2 -> V_5 . V_56 -- ;
}
void F_50 ( struct V_15 * V_16 ,
struct V_58 * V_59 )
{
F_23 ( & V_59 -> V_42 , & V_16 -> V_60 ) ;
}
void F_51 ( struct V_15 * V_16 ,
struct V_58 * V_59 )
{
F_39 ( & V_59 -> V_42 ) ;
F_52 ( V_16 -> V_2 , V_59 ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const struct V_61 * V_36 ,
int V_18 )
{
int V_27 ;
F_1 ( V_2 ) ;
V_27 = F_13 ( V_2 , & V_16 -> V_13 , V_62 ) ;
if ( V_27 )
goto V_40;
V_16 -> V_13 . V_54 = & V_16 -> V_54 ;
V_16 -> V_2 = V_2 ;
V_16 -> V_36 = V_36 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 =
++ V_17 [ V_18 ] . V_63 ;
F_21 ( & V_16 -> V_64 ) ;
F_21 ( & V_16 -> V_60 ) ;
F_21 ( & V_16 -> V_65 ) ;
V_16 -> V_66 = NULL ;
V_16 -> V_21 = V_67 ;
F_47 ( & V_16 -> V_42 , & V_2 -> V_5 . V_68 ) ;
V_2 -> V_5 . V_69 ++ ;
if ( V_18 != V_70 )
F_54 ( & V_16 -> V_13 ,
V_2 -> V_5 . V_71 ,
0 ) ;
F_54 ( & V_16 -> V_13 ,
V_2 -> V_5 . V_72 , 0 ) ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
void F_55 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_58 * V_59 , * V_73 ;
F_56 (mode, t, &connector->probed_modes, head)
F_51 ( V_16 , V_59 ) ;
F_56 (mode, t, &connector->modes, head)
F_51 ( V_16 , V_59 ) ;
F_56 (mode, t, &connector->user_modes, head)
F_51 ( V_16 , V_59 ) ;
F_15 ( V_2 , & V_16 -> V_13 ) ;
F_39 ( & V_16 -> V_42 ) ;
V_2 -> V_5 . V_69 -- ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
F_3 (connector, &dev->mode_config.connector_list, head)
F_58 ( V_16 ) ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
const struct V_74 * V_36 ,
int V_11 )
{
int V_27 ;
F_1 ( V_2 ) ;
V_27 = F_13 ( V_2 , & V_8 -> V_13 , V_75 ) ;
if ( V_27 )
goto V_40;
V_8 -> V_2 = V_2 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_36 = V_36 ;
F_47 ( & V_8 -> V_42 , & V_2 -> V_5 . V_76 ) ;
V_2 -> V_5 . V_77 ++ ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
void F_60 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_1 ( V_2 ) ;
F_15 ( V_2 , & V_8 -> V_13 ) ;
F_39 ( & V_8 -> V_42 ) ;
V_2 -> V_5 . V_77 -- ;
F_5 ( V_2 ) ;
}
int F_61 ( struct V_1 * V_2 , struct V_46 * V_47 ,
unsigned long V_78 ,
const struct V_79 * V_36 ,
const T_1 * V_80 , T_1 V_81 ,
bool V_82 )
{
int V_27 ;
F_1 ( V_2 ) ;
V_27 = F_13 ( V_2 , & V_47 -> V_13 , V_83 ) ;
if ( V_27 )
goto V_40;
V_47 -> V_13 . V_54 = & V_47 -> V_54 ;
V_47 -> V_2 = V_2 ;
V_47 -> V_36 = V_36 ;
V_47 -> V_84 = F_62 ( sizeof( T_1 ) * V_81 ,
V_30 ) ;
if ( ! V_47 -> V_84 ) {
F_63 ( L_8 ) ;
F_15 ( V_2 , & V_47 -> V_13 ) ;
V_27 = - V_85 ;
goto V_40;
}
memcpy ( V_47 -> V_84 , V_80 , V_81 * sizeof( T_1 ) ) ;
V_47 -> V_81 = V_81 ;
V_47 -> V_78 = V_78 ;
if ( ! V_82 ) {
F_47 ( & V_47 -> V_42 , & V_2 -> V_5 . V_86 ) ;
V_2 -> V_5 . V_87 ++ ;
} else {
F_21 ( & V_47 -> V_42 ) ;
}
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
void F_64 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_2 ;
F_1 ( V_2 ) ;
F_49 ( V_47 -> V_84 ) ;
F_15 ( V_2 , & V_47 -> V_13 ) ;
if ( ! F_41 ( & V_47 -> V_42 ) ) {
F_39 ( & V_47 -> V_42 ) ;
V_2 -> V_5 . V_87 -- ;
}
F_5 ( V_2 ) ;
}
struct V_58 * F_65 ( struct V_1 * V_2 )
{
struct V_58 * V_88 ;
V_88 = F_66 ( sizeof( struct V_58 ) , V_30 ) ;
if ( ! V_88 )
return NULL ;
if ( F_13 ( V_2 , & V_88 -> V_13 , V_89 ) ) {
F_49 ( V_88 ) ;
return NULL ;
}
return V_88 ;
}
void F_52 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_15 ( V_2 , & V_59 -> V_13 ) ;
F_49 ( V_59 ) ;
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
void F_78 ( struct V_1 * V_2 )
{
F_46 ( & V_2 -> V_5 . V_6 ) ;
F_46 ( & V_2 -> V_5 . V_28 ) ;
F_46 ( & V_2 -> V_5 . V_37 ) ;
F_21 ( & V_2 -> V_5 . V_43 ) ;
F_21 ( & V_2 -> V_5 . V_55 ) ;
F_21 ( & V_2 -> V_5 . V_68 ) ;
F_21 ( & V_2 -> V_5 . V_76 ) ;
F_21 ( & V_2 -> V_5 . V_131 ) ;
F_21 ( & V_2 -> V_5 . V_132 ) ;
F_21 ( & V_2 -> V_5 . V_86 ) ;
F_79 ( & V_2 -> V_5 . V_29 ) ;
F_1 ( V_2 ) ;
F_67 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_5 . V_41 = 0 ;
V_2 -> V_5 . V_69 = 0 ;
V_2 -> V_5 . V_56 = 0 ;
V_2 -> V_5 . V_77 = 0 ;
}
int F_80 ( struct V_1 * V_2 , struct V_133 * V_134 )
{
T_1 V_135 = 0 ;
V_135 += V_2 -> V_5 . V_56 ;
V_135 += V_2 -> V_5 . V_69 ;
V_135 += V_2 -> V_5 . V_77 ;
V_134 -> V_136 = F_66 ( V_135 * sizeof( T_1 ) , V_30 ) ;
if ( ! V_134 -> V_136 )
return - V_85 ;
V_134 -> V_137 = 0 ;
V_134 -> V_138 = 0 ;
V_134 -> V_139 = 0 ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
struct V_15 * V_16 ;
int V_27 ;
if ( ( V_27 = F_80 ( V_2 , V_134 ) ) )
return V_27 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
V_134 -> V_136 [ V_134 -> V_137 ++ ] = V_4 -> V_13 . V_14 ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
V_134 -> V_136 [ V_134 -> V_137 + V_134 -> V_139 ++ ] =
V_8 -> V_13 . V_14 ;
F_3 (connector, &dev->mode_config.connector_list, head)
V_134 -> V_136 [ V_134 -> V_137 + V_134 -> V_139 +
V_134 -> V_138 ++ ] = V_16 -> V_13 . V_14 ;
return 0 ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_140 ;
struct V_3 * V_4 , * V_141 ;
struct V_7 * V_8 , * V_142 ;
struct V_33 * V_34 , * V_143 ;
struct V_90 * V_144 , * V_145 ;
struct V_46 * V_47 , * V_146 ;
F_56 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_8 -> V_36 -> V_45 ( V_8 ) ;
}
F_56 (connector, ot,
&dev->mode_config.connector_list, head) {
V_16 -> V_36 -> V_45 ( V_16 ) ;
}
F_56 (property, pt, &dev->mode_config.property_list,
head) {
F_83 ( V_2 , V_144 ) ;
}
F_8 ( ! F_41 ( & V_2 -> V_5 . V_43 ) ) ;
F_56 (fb, fbt, &dev->mode_config.fb_list, head) {
F_40 ( V_34 ) ;
}
F_56 (plane, plt, &dev->mode_config.plane_list,
head) {
V_47 -> V_36 -> V_45 ( V_47 ) ;
}
F_56 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_4 -> V_36 -> V_45 ( V_4 ) ;
}
F_84 ( & V_2 -> V_5 . V_29 ) ;
}
static void F_85 ( struct V_147 * V_40 ,
const struct V_58 * V_148 )
{
F_86 ( V_148 -> V_149 > V_150 || V_148 -> V_151 > V_150 ||
V_148 -> V_152 > V_150 || V_148 -> V_153 > V_150 ||
V_148 -> V_154 > V_150 || V_148 -> V_155 > V_150 ||
V_148 -> V_156 > V_150 || V_148 -> V_157 > V_150 ||
V_148 -> V_158 > V_150 || V_148 -> V_159 > V_150 ,
L_27 ) ;
V_40 -> clock = V_148 -> clock ;
V_40 -> V_149 = V_148 -> V_149 ;
V_40 -> V_151 = V_148 -> V_151 ;
V_40 -> V_152 = V_148 -> V_152 ;
V_40 -> V_153 = V_148 -> V_153 ;
V_40 -> V_154 = V_148 -> V_154 ;
V_40 -> V_155 = V_148 -> V_155 ;
V_40 -> V_156 = V_148 -> V_156 ;
V_40 -> V_157 = V_148 -> V_157 ;
V_40 -> V_158 = V_148 -> V_158 ;
V_40 -> V_159 = V_148 -> V_159 ;
V_40 -> V_160 = V_148 -> V_160 ;
V_40 -> V_161 = V_148 -> V_161 ;
V_40 -> type = V_148 -> type ;
strncpy ( V_40 -> V_12 , V_148 -> V_12 , V_162 ) ;
V_40 -> V_12 [ V_162 - 1 ] = 0 ;
}
static int F_87 ( struct V_58 * V_40 ,
const struct V_147 * V_148 )
{
if ( V_148 -> clock > V_163 || V_148 -> V_160 > V_163 )
return - V_164 ;
V_40 -> clock = V_148 -> clock ;
V_40 -> V_149 = V_148 -> V_149 ;
V_40 -> V_151 = V_148 -> V_151 ;
V_40 -> V_152 = V_148 -> V_152 ;
V_40 -> V_153 = V_148 -> V_153 ;
V_40 -> V_154 = V_148 -> V_154 ;
V_40 -> V_155 = V_148 -> V_155 ;
V_40 -> V_156 = V_148 -> V_156 ;
V_40 -> V_157 = V_148 -> V_157 ;
V_40 -> V_158 = V_148 -> V_158 ;
V_40 -> V_159 = V_148 -> V_159 ;
V_40 -> V_160 = V_148 -> V_160 ;
V_40 -> V_161 = V_148 -> V_161 ;
V_40 -> type = V_148 -> type ;
strncpy ( V_40 -> V_12 , V_148 -> V_12 , V_162 ) ;
V_40 -> V_12 [ V_162 - 1 ] = 0 ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 , void * V_165 ,
struct V_166 * V_167 )
{
struct V_168 * V_169 = V_165 ;
struct V_170 * V_171 ;
struct V_33 * V_34 ;
struct V_15 * V_16 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
int V_172 = 0 ;
int V_173 = 0 ;
int V_174 = 0 ;
int V_175 = 0 ;
int V_176 = 0 , V_105 ;
T_1 T_2 * V_177 ;
T_1 T_2 * V_178 ;
T_1 T_2 * V_179 ;
T_1 T_2 * V_180 ;
struct V_133 * V_181 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_2 ( & V_167 -> V_184 ) ;
F_90 (lh, &file_priv->fbs)
V_174 ++ ;
if ( V_169 -> V_185 >= V_174 ) {
V_176 = 0 ;
V_177 = ( T_1 T_2 * ) ( unsigned long ) V_169 -> V_186 ;
F_3 (fb, &file_priv->fbs, filp_head) {
if ( F_91 ( V_34 -> V_13 . V_14 , V_177 + V_176 ) ) {
F_6 ( & V_167 -> V_184 ) ;
return - V_187 ;
}
V_176 ++ ;
}
}
V_169 -> V_185 = V_174 ;
F_6 ( & V_167 -> V_184 ) ;
F_1 ( V_2 ) ;
V_181 = & V_167 -> V_188 -> V_189 -> V_181 ;
if ( V_167 -> V_188 -> V_189 -> type == V_190 ) {
F_90 (lh, &dev->mode_config.crtc_list)
V_173 ++ ;
F_90 (lh, &dev->mode_config.connector_list)
V_172 ++ ;
F_90 (lh, &dev->mode_config.encoder_list)
V_175 ++ ;
} else {
V_173 = V_181 -> V_137 ;
V_172 = V_181 -> V_138 ;
V_175 = V_181 -> V_139 ;
}
V_169 -> V_191 = V_2 -> V_5 . V_191 ;
V_169 -> V_192 = V_2 -> V_5 . V_192 ;
V_169 -> V_193 = V_2 -> V_5 . V_193 ;
V_169 -> V_194 = V_2 -> V_5 . V_194 ;
if ( V_169 -> V_195 >= V_173 ) {
V_176 = 0 ;
V_178 = ( T_1 T_2 * ) ( unsigned long ) V_169 -> V_196 ;
if ( V_167 -> V_188 -> V_189 -> type == V_190 ) {
F_3 (crtc, &dev->mode_config.crtc_list,
head) {
F_63 ( L_28 , V_4 -> V_13 . V_14 ) ;
if ( F_91 ( V_4 -> V_13 . V_14 , V_178 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
} else {
for ( V_105 = 0 ; V_105 < V_181 -> V_137 ; V_105 ++ ) {
if ( F_91 ( V_181 -> V_136 [ V_105 ] ,
V_178 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
}
}
V_169 -> V_195 = V_173 ;
if ( V_169 -> V_197 >= V_175 ) {
V_176 = 0 ;
V_180 = ( T_1 T_2 * ) ( unsigned long ) V_169 -> V_198 ;
if ( V_167 -> V_188 -> V_189 -> type == V_190 ) {
F_3 (encoder,
&dev->mode_config.encoder_list,
head) {
F_63 ( L_29 , V_8 -> V_13 . V_14 ,
F_10 ( V_8 ) ) ;
if ( F_91 ( V_8 -> V_13 . V_14 , V_180 +
V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
} else {
for ( V_105 = V_181 -> V_137 ; V_105 < V_181 -> V_137 + V_181 -> V_139 ; V_105 ++ ) {
if ( F_91 ( V_181 -> V_136 [ V_105 ] ,
V_180 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
}
}
V_169 -> V_197 = V_175 ;
if ( V_169 -> V_199 >= V_172 ) {
V_176 = 0 ;
V_179 = ( T_1 T_2 * ) ( unsigned long ) V_169 -> V_200 ;
if ( V_167 -> V_188 -> V_189 -> type == V_190 ) {
F_3 (connector,
&dev->mode_config.connector_list,
head) {
F_63 ( L_30 ,
V_16 -> V_13 . V_14 ,
F_11 ( V_16 ) ) ;
if ( F_91 ( V_16 -> V_13 . V_14 ,
V_179 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
} else {
int V_201 = V_181 -> V_137 +
V_181 -> V_139 ;
for ( V_105 = V_201 ; V_105 < V_201 + V_181 -> V_138 ; V_105 ++ ) {
if ( F_91 ( V_181 -> V_136 [ V_105 ] ,
V_179 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
}
}
V_169 -> V_199 = V_172 ;
F_63 ( L_31 , V_169 -> V_195 ,
V_169 -> V_199 , V_169 -> V_197 ) ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_92 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_202 * V_203 = V_165 ;
struct V_3 * V_4 ;
struct V_24 * V_25 ;
int V_27 = 0 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_203 -> V_178 ,
V_53 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_40;
}
V_4 = F_93 ( V_25 ) ;
V_203 -> V_204 = V_4 -> V_204 ;
V_203 -> V_205 = V_4 -> V_205 ;
V_203 -> V_206 = V_4 -> V_206 ;
if ( V_4 -> V_34 )
V_203 -> V_177 = V_4 -> V_34 -> V_13 . V_14 ;
else
V_203 -> V_177 = 0 ;
if ( V_4 -> V_207 ) {
F_85 ( & V_203 -> V_59 , & V_4 -> V_59 ) ;
V_203 -> V_208 = 1 ;
} else {
V_203 -> V_208 = 0 ;
}
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_94 ( struct V_1 * V_2 , void * V_165 ,
struct V_166 * V_167 )
{
struct V_209 * V_210 = V_165 ;
struct V_24 * V_25 ;
struct V_15 * V_16 ;
struct V_58 * V_59 ;
int V_211 = 0 ;
int V_212 = 0 ;
int V_213 = 0 ;
int V_27 = 0 ;
int V_176 = 0 ;
int V_105 ;
struct V_147 V_214 ;
struct V_147 T_2 * V_215 ;
T_1 T_2 * V_216 ;
T_3 T_2 * V_217 ;
T_1 T_2 * V_218 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
memset ( & V_214 , 0 , sizeof( struct V_147 ) ) ;
F_63 ( L_32 , V_210 -> V_179 ) ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_25 = F_17 ( V_2 , V_210 -> V_179 ,
V_62 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_40;
}
V_16 = F_95 ( V_25 ) ;
V_212 = V_16 -> V_54 . V_63 ;
for ( V_105 = 0 ; V_105 < V_219 ; V_105 ++ ) {
if ( V_16 -> V_220 [ V_105 ] != 0 ) {
V_213 ++ ;
}
}
if ( V_210 -> V_221 == 0 ) {
V_16 -> V_36 -> V_222 ( V_16 ,
V_2 -> V_5 . V_193 ,
V_2 -> V_5 . V_191 ) ;
}
F_3 (mode, &connector->modes, head)
V_211 ++ ;
V_210 -> V_179 = V_16 -> V_13 . V_14 ;
V_210 -> V_18 = V_16 -> V_18 ;
V_210 -> V_19 = V_16 -> V_19 ;
V_210 -> V_223 = V_16 -> V_224 . V_225 ;
V_210 -> V_226 = V_16 -> V_224 . V_227 ;
V_210 -> V_228 = V_16 -> V_224 . V_229 ;
V_210 -> V_230 = V_16 -> V_21 ;
if ( V_16 -> V_8 )
V_210 -> V_180 = V_16 -> V_8 -> V_13 . V_14 ;
else
V_210 -> V_180 = 0 ;
if ( ( V_210 -> V_221 >= V_211 ) && V_211 ) {
V_176 = 0 ;
V_215 = (struct V_147 T_2 * ) ( unsigned long ) V_210 -> V_231 ;
F_3 (mode, &connector->modes, head) {
F_85 ( & V_214 , V_59 ) ;
if ( F_96 ( V_215 + V_176 ,
& V_214 , sizeof( V_214 ) ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
}
V_210 -> V_221 = V_211 ;
if ( ( V_210 -> V_232 >= V_212 ) && V_212 ) {
V_176 = 0 ;
V_216 = ( T_1 T_2 * ) ( unsigned long ) ( V_210 -> V_233 ) ;
V_217 = ( T_3 T_2 * ) ( unsigned long ) ( V_210 -> V_234 ) ;
for ( V_105 = 0 ; V_105 < V_16 -> V_54 . V_63 ; V_105 ++ ) {
if ( F_91 ( V_16 -> V_54 . V_235 [ V_105 ] ,
V_216 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
if ( F_91 ( V_16 -> V_54 . V_236 [ V_105 ] ,
V_217 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
}
V_210 -> V_232 = V_212 ;
if ( ( V_210 -> V_197 >= V_213 ) && V_213 ) {
V_176 = 0 ;
V_218 = ( T_1 T_2 * ) ( unsigned long ) ( V_210 -> V_237 ) ;
for ( V_105 = 0 ; V_105 < V_219 ; V_105 ++ ) {
if ( V_16 -> V_220 [ V_105 ] != 0 ) {
if ( F_91 ( V_16 -> V_220 [ V_105 ] ,
V_218 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
}
}
V_210 -> V_197 = V_213 ;
V_40:
F_6 ( & V_2 -> V_5 . V_6 ) ;
return V_27 ;
}
int F_97 ( struct V_1 * V_2 , void * V_165 ,
struct V_166 * V_167 )
{
struct V_238 * V_239 = V_165 ;
struct V_24 * V_25 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_239 -> V_180 ,
V_75 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_40;
}
V_8 = F_98 ( V_25 ) ;
if ( V_8 -> V_4 )
V_239 -> V_178 = V_8 -> V_4 -> V_13 . V_14 ;
else
V_239 -> V_178 = 0 ;
V_239 -> V_11 = V_8 -> V_11 ;
V_239 -> V_180 = V_8 -> V_13 . V_14 ;
V_239 -> V_78 = V_8 -> V_78 ;
V_239 -> V_240 = V_8 -> V_240 ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_99 ( struct V_1 * V_2 , void * V_165 ,
struct V_166 * V_167 )
{
struct V_241 * V_242 = V_165 ;
struct V_243 * V_244 ;
struct V_46 * V_47 ;
T_1 T_2 * V_245 ;
int V_176 = 0 , V_27 = 0 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_244 = & V_2 -> V_5 ;
if ( V_244 -> V_87 &&
( V_242 -> V_246 >= V_244 -> V_87 ) ) {
V_245 = ( T_1 T_2 * ) ( unsigned long ) V_242 -> V_247 ;
F_3 (plane, &config->plane_list, head) {
if ( F_91 ( V_47 -> V_13 . V_14 , V_245 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
}
V_242 -> V_246 = V_244 -> V_87 ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_100 ( struct V_1 * V_2 , void * V_165 ,
struct V_166 * V_167 )
{
struct V_248 * V_242 = V_165 ;
struct V_24 * V_25 ;
struct V_46 * V_47 ;
T_1 T_2 * V_249 ;
int V_27 = 0 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_242 -> V_250 ,
V_83 ) ;
if ( ! V_25 ) {
V_27 = - V_251 ;
goto V_40;
}
V_47 = F_101 ( V_25 ) ;
if ( V_47 -> V_4 )
V_242 -> V_178 = V_47 -> V_4 -> V_13 . V_14 ;
else
V_242 -> V_178 = 0 ;
if ( V_47 -> V_34 )
V_242 -> V_177 = V_47 -> V_34 -> V_13 . V_14 ;
else
V_242 -> V_177 = 0 ;
V_242 -> V_250 = V_47 -> V_13 . V_14 ;
V_242 -> V_78 = V_47 -> V_78 ;
V_242 -> V_206 = V_47 -> V_206 ;
if ( V_47 -> V_81 &&
( V_242 -> V_252 >= V_47 -> V_81 ) ) {
V_249 = ( T_1 T_2 * ) ( unsigned long ) V_242 -> V_253 ;
if ( F_96 ( V_249 ,
V_47 -> V_84 ,
sizeof( T_1 ) * V_47 -> V_81 ) ) {
V_27 = - V_187 ;
goto V_40;
}
}
V_242 -> V_252 = V_47 -> V_81 ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_102 ( struct V_1 * V_2 , void * V_165 ,
struct V_166 * V_167 )
{
struct V_254 * V_255 = V_165 ;
struct V_24 * V_25 ;
struct V_46 * V_47 ;
struct V_3 * V_4 ;
struct V_33 * V_34 = NULL , * V_256 = NULL ;
int V_27 = 0 ;
unsigned int V_257 , V_258 ;
int V_105 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
V_25 = F_17 ( V_2 , V_255 -> V_250 ,
V_83 ) ;
if ( ! V_25 ) {
F_63 ( L_33 ,
V_255 -> V_250 ) ;
return - V_251 ;
}
V_47 = F_101 ( V_25 ) ;
if ( ! V_255 -> V_177 ) {
F_1 ( V_2 ) ;
V_256 = V_47 -> V_34 ;
V_47 -> V_36 -> V_50 ( V_47 ) ;
V_47 -> V_4 = NULL ;
V_47 -> V_34 = NULL ;
F_5 ( V_2 ) ;
goto V_40;
}
V_25 = F_17 ( V_2 , V_255 -> V_178 ,
V_53 ) ;
if ( ! V_25 ) {
F_63 ( L_34 ,
V_255 -> V_178 ) ;
V_27 = - V_251 ;
goto V_40;
}
V_4 = F_93 ( V_25 ) ;
V_34 = F_28 ( V_2 , V_255 -> V_177 ) ;
if ( ! V_34 ) {
F_63 ( L_35 ,
V_255 -> V_177 ) ;
V_27 = - V_251 ;
goto V_40;
}
for ( V_105 = 0 ; V_105 < V_47 -> V_81 ; V_105 ++ )
if ( V_34 -> V_259 == V_47 -> V_84 [ V_105 ] )
break;
if ( V_105 == V_47 -> V_81 ) {
F_63 ( L_36 , V_34 -> V_259 ) ;
V_27 = - V_183 ;
goto V_40;
}
V_257 = V_34 -> V_260 << 16 ;
V_258 = V_34 -> V_261 << 16 ;
if ( V_255 -> V_262 > V_257 ||
V_255 -> V_263 > V_257 - V_255 -> V_262 ||
V_255 -> V_264 > V_258 ||
V_255 -> V_265 > V_258 - V_255 -> V_264 ) {
F_63 ( L_37
L_38 ,
V_255 -> V_262 >> 16 ,
( ( V_255 -> V_262 & 0xffff ) * 15625 ) >> 10 ,
V_255 -> V_264 >> 16 ,
( ( V_255 -> V_264 & 0xffff ) * 15625 ) >> 10 ,
V_255 -> V_263 >> 16 ,
( ( V_255 -> V_263 & 0xffff ) * 15625 ) >> 10 ,
V_255 -> V_265 >> 16 ,
( ( V_255 -> V_265 & 0xffff ) * 15625 ) >> 10 ) ;
V_27 = - V_266 ;
goto V_40;
}
if ( V_255 -> V_267 > V_163 ||
V_255 -> V_268 > V_163 - ( V_269 ) V_255 -> V_267 ||
V_255 -> V_270 > V_163 ||
V_255 -> V_271 > V_163 - ( V_269 ) V_255 -> V_270 ) {
F_63 ( L_39 ,
V_255 -> V_267 , V_255 -> V_270 ,
V_255 -> V_268 , V_255 -> V_271 ) ;
V_27 = - V_164 ;
goto V_40;
}
F_1 ( V_2 ) ;
V_27 = V_47 -> V_36 -> V_272 ( V_47 , V_4 , V_34 ,
V_255 -> V_268 , V_255 -> V_271 ,
V_255 -> V_267 , V_255 -> V_270 ,
V_255 -> V_263 , V_255 -> V_265 ,
V_255 -> V_262 , V_255 -> V_264 ) ;
if ( ! V_27 ) {
V_256 = V_47 -> V_34 ;
V_47 -> V_4 = V_4 ;
V_47 -> V_34 = V_34 ;
V_34 = NULL ;
}
F_5 ( V_2 ) ;
V_40:
if ( V_34 )
F_30 ( V_34 ) ;
if ( V_256 )
F_30 ( V_256 ) ;
return V_27 ;
}
int F_43 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = V_49 -> V_4 ;
struct V_33 * V_34 , * V_256 ;
int V_27 ;
V_256 = V_4 -> V_34 ;
V_34 = V_49 -> V_34 ;
V_27 = V_4 -> V_36 -> V_273 ( V_49 ) ;
if ( V_27 == 0 ) {
if ( V_256 )
F_30 ( V_256 ) ;
if ( V_34 )
F_22 ( V_34 ) ;
}
return V_27 ;
}
int F_103 ( struct V_1 * V_2 , void * V_165 ,
struct V_166 * V_167 )
{
struct V_243 * V_244 = & V_2 -> V_5 ;
struct V_202 * V_274 = V_165 ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
struct V_15 * * V_275 = NULL , * V_16 ;
struct V_33 * V_34 = NULL ;
struct V_58 * V_59 = NULL ;
struct V_48 V_49 ;
T_1 T_2 * V_276 ;
int V_27 ;
int V_105 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
if ( V_274 -> V_204 > V_163 || V_274 -> V_205 > V_163 )
return - V_164 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_274 -> V_178 ,
V_53 ) ;
if ( ! V_25 ) {
F_63 ( L_40 , V_274 -> V_178 ) ;
V_27 = - V_183 ;
goto V_40;
}
V_4 = F_93 ( V_25 ) ;
F_63 ( L_28 , V_4 -> V_13 . V_14 ) ;
if ( V_274 -> V_208 ) {
int V_149 , V_155 ;
if ( V_274 -> V_177 == - 1 ) {
if ( ! V_4 -> V_34 ) {
F_63 ( L_41 ) ;
V_27 = - V_183 ;
goto V_40;
}
V_34 = V_4 -> V_34 ;
F_22 ( V_34 ) ;
} else {
V_34 = F_28 ( V_2 , V_274 -> V_177 ) ;
if ( ! V_34 ) {
F_63 ( L_42 ,
V_274 -> V_177 ) ;
V_27 = - V_183 ;
goto V_40;
}
}
V_59 = F_65 ( V_2 ) ;
if ( ! V_59 ) {
V_27 = - V_85 ;
goto V_40;
}
V_27 = F_87 ( V_59 , & V_274 -> V_59 ) ;
if ( V_27 ) {
F_63 ( L_43 ) ;
goto V_40;
}
F_104 ( V_59 , V_277 ) ;
V_149 = V_59 -> V_149 ;
V_155 = V_59 -> V_155 ;
if ( V_4 -> V_52 )
F_105 ( V_149 , V_155 ) ;
if ( V_149 > V_34 -> V_260 ||
V_155 > V_34 -> V_261 ||
V_274 -> V_204 > V_34 -> V_260 - V_149 ||
V_274 -> V_205 > V_34 -> V_261 - V_155 ) {
F_63 ( L_44 ,
V_34 -> V_260 , V_34 -> V_261 ,
V_149 , V_155 , V_274 -> V_204 , V_274 -> V_205 ,
V_4 -> V_52 ? L_45 : L_46 ) ;
V_27 = - V_266 ;
goto V_40;
}
}
if ( V_274 -> V_199 == 0 && V_59 ) {
F_63 ( L_47 ) ;
V_27 = - V_183 ;
goto V_40;
}
if ( V_274 -> V_199 > 0 && ( ! V_59 || ! V_34 ) ) {
F_63 ( L_48 ,
V_274 -> V_199 ) ;
V_27 = - V_183 ;
goto V_40;
}
if ( V_274 -> V_199 > 0 ) {
T_4 V_278 ;
if ( V_274 -> V_199 > V_244 -> V_69 ) {
V_27 = - V_183 ;
goto V_40;
}
V_275 = F_62 ( V_274 -> V_199 *
sizeof( struct V_15 * ) ,
V_30 ) ;
if ( ! V_275 ) {
V_27 = - V_85 ;
goto V_40;
}
for ( V_105 = 0 ; V_105 < V_274 -> V_199 ; V_105 ++ ) {
V_276 = ( T_1 T_2 * ) ( unsigned long ) V_274 -> V_276 ;
if ( F_106 ( V_278 , & V_276 [ V_105 ] ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_25 = F_17 ( V_2 , V_278 ,
V_62 ) ;
if ( ! V_25 ) {
F_63 ( L_49 ,
V_278 ) ;
V_27 = - V_183 ;
goto V_40;
}
V_16 = F_95 ( V_25 ) ;
F_63 ( L_30 ,
V_16 -> V_13 . V_14 ,
F_11 ( V_16 ) ) ;
V_275 [ V_105 ] = V_16 ;
}
}
V_49 . V_4 = V_4 ;
V_49 . V_204 = V_274 -> V_204 ;
V_49 . V_205 = V_274 -> V_205 ;
V_49 . V_59 = V_59 ;
V_49 . V_279 = V_275 ;
V_49 . V_138 = V_274 -> V_199 ;
V_49 . V_34 = V_34 ;
V_27 = F_43 ( & V_49 ) ;
V_40:
if ( V_34 )
F_30 ( V_34 ) ;
F_49 ( V_275 ) ;
F_52 ( V_2 , V_59 ) ;
F_5 ( V_2 ) ;
return V_27 ;
}
int F_107 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_280 * V_281 = V_165 ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
if ( ! V_281 -> V_161 || ( ~ V_282 & V_281 -> V_161 ) )
return - V_183 ;
V_25 = F_17 ( V_2 , V_281 -> V_178 , V_53 ) ;
if ( ! V_25 ) {
F_63 ( L_40 , V_281 -> V_178 ) ;
return - V_183 ;
}
V_4 = F_93 ( V_25 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_281 -> V_161 & V_283 ) {
if ( ! V_4 -> V_36 -> V_284 ) {
V_27 = - V_285 ;
goto V_40;
}
V_27 = V_4 -> V_36 -> V_284 ( V_4 , V_167 , V_281 -> V_286 ,
V_281 -> V_260 , V_281 -> V_261 ) ;
}
if ( V_281 -> V_161 & V_287 ) {
if ( V_4 -> V_36 -> V_288 ) {
V_27 = V_4 -> V_36 -> V_288 ( V_4 , V_281 -> V_204 , V_281 -> V_205 ) ;
} else {
V_27 = - V_187 ;
goto V_40;
}
}
V_40:
F_6 ( & V_4 -> V_6 ) ;
return V_27 ;
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
F_44 ( L_50 ) ;
V_291 = V_296 ;
break;
}
return V_291 ;
}
int F_109 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_299 * V_300 = V_165 ;
struct V_301 V_302 = {} ;
struct V_243 * V_244 = & V_2 -> V_5 ;
struct V_33 * V_34 ;
int V_27 = 0 ;
V_302 . V_177 = V_300 -> V_177 ;
V_302 . V_260 = V_300 -> V_260 ;
V_302 . V_261 = V_300 -> V_261 ;
V_302 . V_303 [ 0 ] = V_300 -> V_304 ;
V_302 . V_259 = F_108 ( V_300 -> V_289 , V_300 -> V_290 ) ;
V_302 . V_305 [ 0 ] = V_300 -> V_286 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
if ( ( V_244 -> V_194 > V_302 . V_260 ) || ( V_302 . V_260 > V_244 -> V_193 ) )
return - V_183 ;
if ( ( V_244 -> V_192 > V_302 . V_261 ) || ( V_302 . V_261 > V_244 -> V_191 ) )
return - V_183 ;
V_34 = V_2 -> V_5 . V_36 -> V_306 ( V_2 , V_167 , & V_302 ) ;
if ( F_110 ( V_34 ) ) {
F_63 ( L_51 ) ;
return F_111 ( V_34 ) ;
}
F_2 ( & V_167 -> V_184 ) ;
V_300 -> V_177 = V_34 -> V_13 . V_14 ;
F_23 ( & V_34 -> V_39 , & V_167 -> V_307 ) ;
F_63 ( L_52 , V_34 -> V_13 . V_14 ) ;
F_6 ( & V_167 -> V_184 ) ;
return V_27 ;
}
static int F_112 ( const struct V_301 * V_302 )
{
T_1 V_308 = V_302 -> V_259 & ~ V_309 ;
switch ( V_308 ) {
case V_292 :
case V_310 :
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
return - V_183 ;
}
}
static int F_113 ( const struct V_301 * V_302 )
{
int V_27 , V_363 , V_364 , V_365 , V_105 ;
V_27 = F_112 ( V_302 ) ;
if ( V_27 ) {
F_63 ( L_53 , V_302 -> V_259 ) ;
return V_27 ;
}
V_363 = F_114 ( V_302 -> V_259 ) ;
V_364 = F_115 ( V_302 -> V_259 ) ;
V_365 = F_116 ( V_302 -> V_259 ) ;
if ( V_302 -> V_260 == 0 || V_302 -> V_260 % V_363 ) {
F_63 ( L_54 , V_302 -> V_261 ) ;
return - V_183 ;
}
if ( V_302 -> V_261 == 0 || V_302 -> V_261 % V_364 ) {
F_63 ( L_55 , V_302 -> V_261 ) ;
return - V_183 ;
}
for ( V_105 = 0 ; V_105 < V_365 ; V_105 ++ ) {
unsigned int V_260 = V_302 -> V_260 / ( V_105 != 0 ? V_363 : 1 ) ;
unsigned int V_261 = V_302 -> V_261 / ( V_105 != 0 ? V_364 : 1 ) ;
unsigned int V_366 = F_117 ( V_302 -> V_259 , V_105 ) ;
if ( ! V_302 -> V_305 [ V_105 ] ) {
F_63 ( L_56 , V_105 ) ;
return - V_183 ;
}
if ( ( T_3 ) V_260 * V_366 > V_367 )
return - V_164 ;
if ( ( T_3 ) V_261 * V_302 -> V_303 [ V_105 ] + V_302 -> V_368 [ V_105 ] > V_367 )
return - V_164 ;
if ( V_302 -> V_303 [ V_105 ] < V_260 * V_366 ) {
F_63 ( L_57 , V_302 -> V_303 [ V_105 ] , V_105 ) ;
return - V_183 ;
}
}
return 0 ;
}
int F_118 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_301 * V_302 = V_165 ;
struct V_243 * V_244 = & V_2 -> V_5 ;
struct V_33 * V_34 ;
int V_27 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
if ( V_302 -> V_161 & ~ V_369 ) {
F_63 ( L_58 , V_302 -> V_161 ) ;
return - V_183 ;
}
if ( ( V_244 -> V_194 > V_302 -> V_260 ) || ( V_302 -> V_260 > V_244 -> V_193 ) ) {
F_63 ( L_59 ,
V_302 -> V_260 , V_244 -> V_194 , V_244 -> V_193 ) ;
return - V_183 ;
}
if ( ( V_244 -> V_192 > V_302 -> V_261 ) || ( V_302 -> V_261 > V_244 -> V_191 ) ) {
F_63 ( L_60 ,
V_302 -> V_261 , V_244 -> V_192 , V_244 -> V_191 ) ;
return - V_183 ;
}
V_27 = F_113 ( V_302 ) ;
if ( V_27 )
return V_27 ;
V_34 = V_2 -> V_5 . V_36 -> V_306 ( V_2 , V_167 , V_302 ) ;
if ( F_110 ( V_34 ) ) {
F_63 ( L_51 ) ;
return F_111 ( V_34 ) ;
}
F_2 ( & V_167 -> V_184 ) ;
V_302 -> V_177 = V_34 -> V_13 . V_14 ;
F_23 ( & V_34 -> V_39 , & V_167 -> V_307 ) ;
F_63 ( L_52 , V_34 -> V_13 . V_14 ) ;
F_6 ( & V_167 -> V_184 ) ;
return V_27 ;
}
int F_119 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_33 * V_34 = NULL ;
struct V_33 * V_370 = NULL ;
T_1 * V_14 = V_165 ;
int V_371 = 0 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_2 ( & V_167 -> V_184 ) ;
F_2 ( & V_2 -> V_5 . V_37 ) ;
V_34 = F_26 ( V_2 , * V_14 ) ;
if ( ! V_34 )
goto V_372;
F_3 (fbl, &file_priv->fbs, filp_head)
if ( V_34 == V_370 )
V_371 = 1 ;
if ( ! V_371 )
goto V_372;
F_36 ( V_2 , V_34 ) ;
F_120 ( & V_34 -> V_39 ) ;
F_6 ( & V_2 -> V_5 . V_37 ) ;
F_6 ( & V_167 -> V_184 ) ;
F_40 ( V_34 ) ;
return 0 ;
V_372:
F_6 ( & V_2 -> V_5 . V_37 ) ;
F_6 ( & V_167 -> V_184 ) ;
return - V_183 ;
}
int F_121 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_299 * V_302 = V_165 ;
struct V_33 * V_34 ;
int V_27 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
V_34 = F_28 ( V_2 , V_302 -> V_177 ) ;
if ( ! V_34 )
return - V_183 ;
V_302 -> V_261 = V_34 -> V_261 ;
V_302 -> V_260 = V_34 -> V_260 ;
V_302 -> V_290 = V_34 -> V_290 ;
V_302 -> V_289 = V_34 -> V_373 ;
V_302 -> V_304 = V_34 -> V_303 [ 0 ] ;
if ( V_34 -> V_36 -> V_374 )
V_27 = V_34 -> V_36 -> V_374 ( V_34 , V_167 , & V_302 -> V_286 ) ;
else
V_27 = - V_375 ;
F_30 ( V_34 ) ;
return V_27 ;
}
int F_122 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_376 T_2 * V_377 ;
struct V_376 * V_378 = NULL ;
struct V_379 * V_302 = V_165 ;
struct V_33 * V_34 ;
unsigned V_161 ;
int V_380 ;
int V_27 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
V_34 = F_28 ( V_2 , V_302 -> V_177 ) ;
if ( ! V_34 )
return - V_183 ;
V_380 = V_302 -> V_380 ;
V_377 = (struct V_376 T_2 * ) ( unsigned long ) V_302 -> V_377 ;
if ( ! V_380 != ! V_377 ) {
V_27 = - V_183 ;
goto V_381;
}
V_161 = V_382 & V_302 -> V_161 ;
if ( V_161 & V_383 && ( V_380 % 2 ) ) {
V_27 = - V_183 ;
goto V_381;
}
if ( V_380 && V_377 ) {
if ( V_380 < 0 || V_380 > V_384 ) {
V_27 = - V_183 ;
goto V_381;
}
V_378 = F_66 ( V_380 * sizeof( * V_378 ) , V_30 ) ;
if ( ! V_378 ) {
V_27 = - V_85 ;
goto V_381;
}
V_27 = F_123 ( V_378 , V_377 ,
V_380 * sizeof( * V_378 ) ) ;
if ( V_27 ) {
V_27 = - V_187 ;
goto V_385;
}
}
if ( V_34 -> V_36 -> V_386 ) {
F_1 ( V_2 ) ;
V_27 = V_34 -> V_36 -> V_386 ( V_34 , V_167 , V_161 , V_302 -> V_387 ,
V_378 , V_380 ) ;
F_5 ( V_2 ) ;
} else {
V_27 = - V_388 ;
}
V_385:
F_49 ( V_378 ) ;
V_381:
F_30 ( V_34 ) ;
return V_27 ;
}
void F_124 ( struct V_166 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_189 -> V_2 ;
struct V_33 * V_34 , * V_389 ;
F_2 ( & V_82 -> V_184 ) ;
F_56 (fb, tfb, &priv->fbs, filp_head) {
F_2 ( & V_2 -> V_5 . V_37 ) ;
F_36 ( V_2 , V_34 ) ;
F_6 ( & V_2 -> V_5 . V_37 ) ;
F_120 ( & V_34 -> V_39 ) ;
F_40 ( V_34 ) ;
}
F_6 ( & V_82 -> V_184 ) ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_58 * V_59 )
{
F_47 ( & V_59 -> V_42 , & V_16 -> V_64 ) ;
}
int F_126 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_58 * V_59 )
{
struct V_15 * V_16 ;
int V_27 = 0 ;
struct V_58 * V_390 , * V_391 ;
F_127 ( V_392 ) ;
F_3 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_16 -> V_8 )
continue;
if ( V_16 -> V_8 -> V_4 == V_4 ) {
V_390 = F_128 ( V_2 , V_59 ) ;
if ( ! V_390 ) {
V_27 = - V_85 ;
goto V_40;
}
F_47 ( & V_390 -> V_42 , & V_392 ) ;
}
}
F_3 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_16 -> V_8 )
continue;
if ( V_16 -> V_8 -> V_4 == V_4 )
F_129 ( V_392 . V_391 , & V_16 -> V_64 ) ;
}
F_8 ( ! F_41 ( & V_392 ) ) ;
V_40:
F_56 (dup_mode, next, &list, head)
F_52 ( V_2 , V_390 ) ;
return V_27 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_58 * V_59 )
{
int V_371 = 0 ;
int V_27 = 0 ;
struct V_58 * V_393 , * V_73 ;
F_56 (match_mode, t, &connector->user_modes, head) {
if ( F_131 ( V_393 , V_59 ) ) {
F_39 ( & V_393 -> V_42 ) ;
F_52 ( V_2 , V_393 ) ;
V_371 = 1 ;
break;
}
}
if ( ! V_371 )
V_27 = - V_183 ;
return V_27 ;
}
int F_132 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_15 * V_16 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
F_130 ( V_2 , V_16 , V_59 ) ;
}
return 0 ;
}
int F_133 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_394 * V_395 = V_165 ;
struct V_15 * V_16 ;
struct V_58 * V_59 ;
struct V_24 * V_25 ;
struct V_147 * V_396 = & V_395 -> V_59 ;
int V_27 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_395 -> V_179 , V_62 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_40;
}
V_16 = F_95 ( V_25 ) ;
V_59 = F_65 ( V_2 ) ;
if ( ! V_59 ) {
V_27 = - V_85 ;
goto V_40;
}
V_27 = F_87 ( V_59 , V_396 ) ;
if ( V_27 ) {
F_63 ( L_43 ) ;
F_52 ( V_2 , V_59 ) ;
goto V_40;
}
F_125 ( V_2 , V_16 , V_59 ) ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_134 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_24 * V_25 ;
struct V_394 * V_395 = V_165 ;
struct V_15 * V_16 ;
struct V_58 V_59 ;
struct V_147 * V_396 = & V_395 -> V_59 ;
int V_27 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_395 -> V_179 , V_62 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_40;
}
V_16 = F_95 ( V_25 ) ;
V_27 = F_87 ( & V_59 , V_396 ) ;
if ( V_27 ) {
F_63 ( L_43 ) ;
goto V_40;
}
V_27 = F_130 ( V_2 , V_16 , & V_59 ) ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
struct V_90 * F_68 ( struct V_1 * V_2 , int V_161 ,
const char * V_12 , int V_397 )
{
struct V_90 * V_144 = NULL ;
int V_27 ;
V_144 = F_66 ( sizeof( struct V_90 ) , V_30 ) ;
if ( ! V_144 )
return NULL ;
if ( V_397 ) {
V_144 -> V_236 = F_66 ( sizeof( T_3 ) * V_397 , V_30 ) ;
if ( ! V_144 -> V_236 )
goto V_398;
}
V_27 = F_13 ( V_2 , & V_144 -> V_13 , V_399 ) ;
if ( V_27 )
goto V_398;
V_144 -> V_161 = V_161 ;
V_144 -> V_397 = V_397 ;
F_21 ( & V_144 -> V_400 ) ;
if ( V_12 ) {
strncpy ( V_144 -> V_12 , V_12 , V_401 ) ;
V_144 -> V_12 [ V_401 - 1 ] = '\0' ;
}
F_47 ( & V_144 -> V_42 , & V_2 -> V_5 . V_131 ) ;
return V_144 ;
V_398:
F_49 ( V_144 -> V_236 ) ;
F_49 ( V_144 ) ;
return NULL ;
}
struct V_90 * F_69 ( struct V_1 * V_2 , int V_161 ,
const char * V_12 ,
const struct V_402 * V_403 ,
int V_397 )
{
struct V_90 * V_144 ;
int V_105 , V_27 ;
V_161 |= V_115 ;
V_144 = F_68 ( V_2 , V_161 , V_12 , V_397 ) ;
if ( ! V_144 )
return NULL ;
for ( V_105 = 0 ; V_105 < V_397 ; V_105 ++ ) {
V_27 = F_74 ( V_144 , V_105 ,
V_403 [ V_105 ] . type ,
V_403 [ V_105 ] . V_12 ) ;
if ( V_27 ) {
F_83 ( V_2 , V_144 ) ;
return NULL ;
}
}
return V_144 ;
}
struct V_90 * F_135 ( struct V_1 * V_2 ,
int V_161 , const char * V_12 ,
const struct V_402 * V_403 ,
int V_397 )
{
struct V_90 * V_144 ;
int V_105 , V_27 ;
V_161 |= V_404 ;
V_144 = F_68 ( V_2 , V_161 , V_12 , V_397 ) ;
if ( ! V_144 )
return NULL ;
for ( V_105 = 0 ; V_105 < V_397 ; V_105 ++ ) {
V_27 = F_74 ( V_144 , V_105 ,
V_403 [ V_105 ] . type ,
V_403 [ V_105 ] . V_12 ) ;
if ( V_27 ) {
F_83 ( V_2 , V_144 ) ;
return NULL ;
}
}
return V_144 ;
}
struct V_90 * F_73 ( struct V_1 * V_2 , int V_161 ,
const char * V_12 ,
T_3 V_405 , T_3 V_406 )
{
struct V_90 * V_144 ;
V_161 |= V_407 ;
V_144 = F_68 ( V_2 , V_161 , V_12 , 2 ) ;
if ( ! V_144 )
return NULL ;
V_144 -> V_236 [ 0 ] = V_405 ;
V_144 -> V_236 [ 1 ] = V_406 ;
return V_144 ;
}
int F_74 ( struct V_90 * V_144 , int V_408 ,
T_3 V_409 , const char * V_12 )
{
struct V_410 * V_411 ;
if ( ! ( V_144 -> V_161 & ( V_115 | V_404 ) ) )
return - V_183 ;
if ( ( V_144 -> V_161 & V_404 ) && ( V_409 > 63 ) )
return - V_183 ;
if ( ! F_41 ( & V_144 -> V_400 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( V_411 -> V_409 == V_409 ) {
strncpy ( V_411 -> V_12 , V_12 , V_401 ) ;
V_411 -> V_12 [ V_401 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_411 = F_66 ( sizeof( struct V_410 ) , V_30 ) ;
if ( ! V_411 )
return - V_85 ;
strncpy ( V_411 -> V_12 , V_12 , V_401 ) ;
V_411 -> V_12 [ V_401 - 1 ] = '\0' ;
V_411 -> V_409 = V_409 ;
V_144 -> V_236 [ V_408 ] = V_409 ;
F_47 ( & V_411 -> V_42 , & V_144 -> V_400 ) ;
return 0 ;
}
void F_83 ( struct V_1 * V_2 , struct V_90 * V_144 )
{
struct V_410 * V_411 , * V_145 ;
F_56 (prop_enum, pt, &property->enum_blob_list, head) {
F_39 ( & V_411 -> V_42 ) ;
F_49 ( V_411 ) ;
}
if ( V_144 -> V_397 )
F_49 ( V_144 -> V_236 ) ;
F_15 ( V_2 , & V_144 -> V_13 ) ;
F_39 ( & V_144 -> V_42 ) ;
F_49 ( V_144 ) ;
}
void F_54 ( struct V_24 * V_25 ,
struct V_90 * V_144 ,
T_3 V_412 )
{
int V_63 = V_25 -> V_54 -> V_63 ;
if ( V_63 == V_413 ) {
F_86 ( 1 , L_61
L_62
L_63 ,
V_25 -> type ) ;
return;
}
V_25 -> V_54 -> V_235 [ V_63 ] = V_144 -> V_13 . V_14 ;
V_25 -> V_54 -> V_236 [ V_63 ] = V_412 ;
V_25 -> V_54 -> V_63 ++ ;
}
int F_136 ( struct V_24 * V_25 ,
struct V_90 * V_144 , T_3 V_414 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_25 -> V_54 -> V_63 ; V_105 ++ ) {
if ( V_25 -> V_54 -> V_235 [ V_105 ] == V_144 -> V_13 . V_14 ) {
V_25 -> V_54 -> V_236 [ V_105 ] = V_414 ;
return 0 ;
}
}
return - V_183 ;
}
int F_137 ( struct V_24 * V_25 ,
struct V_90 * V_144 , T_3 * V_414 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_25 -> V_54 -> V_63 ; V_105 ++ ) {
if ( V_25 -> V_54 -> V_235 [ V_105 ] == V_144 -> V_13 . V_14 ) {
* V_414 = V_25 -> V_54 -> V_236 [ V_105 ] ;
return 0 ;
}
}
return - V_183 ;
}
int F_138 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_24 * V_25 ;
struct V_415 * V_210 = V_165 ;
struct V_90 * V_144 ;
int V_416 = 0 ;
int V_417 = 0 ;
int V_418 = 0 ;
int V_27 = 0 , V_105 ;
int V_176 ;
struct V_410 * V_411 ;
struct V_419 T_2 * V_420 ;
struct V_421 * V_422 ;
T_1 T_2 * V_423 ;
T_3 T_2 * V_424 ;
T_1 T_2 * V_425 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_210 -> V_426 , V_399 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_427;
}
V_144 = F_139 ( V_25 ) ;
if ( V_144 -> V_161 & ( V_115 | V_404 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head)
V_416 ++ ;
} else if ( V_144 -> V_161 & V_93 ) {
F_3 (prop_blob, &property->enum_blob_list, head)
V_417 ++ ;
}
V_418 = V_144 -> V_397 ;
strncpy ( V_210 -> V_12 , V_144 -> V_12 , V_401 ) ;
V_210 -> V_12 [ V_401 - 1 ] = 0 ;
V_210 -> V_161 = V_144 -> V_161 ;
if ( ( V_210 -> V_428 >= V_418 ) && V_418 ) {
V_424 = ( T_3 T_2 * ) ( unsigned long ) V_210 -> V_424 ;
for ( V_105 = 0 ; V_105 < V_418 ; V_105 ++ ) {
if ( F_96 ( V_424 + V_105 , & V_144 -> V_236 [ V_105 ] , sizeof( T_3 ) ) ) {
V_27 = - V_187 ;
goto V_427;
}
}
}
V_210 -> V_428 = V_418 ;
if ( V_144 -> V_161 & ( V_115 | V_404 ) ) {
if ( ( V_210 -> V_429 >= V_416 ) && V_416 ) {
V_176 = 0 ;
V_420 = (struct V_419 T_2 * ) ( unsigned long ) V_210 -> V_430 ;
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( F_96 ( & V_420 [ V_176 ] . V_409 , & V_411 -> V_409 , sizeof( T_3 ) ) ) {
V_27 = - V_187 ;
goto V_427;
}
if ( F_96 ( & V_420 [ V_176 ] . V_12 ,
& V_411 -> V_12 , V_401 ) ) {
V_27 = - V_187 ;
goto V_427;
}
V_176 ++ ;
}
}
V_210 -> V_429 = V_416 ;
}
if ( V_144 -> V_161 & V_93 ) {
if ( ( V_210 -> V_429 >= V_417 ) && V_417 ) {
V_176 = 0 ;
V_423 = ( T_1 T_2 * ) ( unsigned long ) V_210 -> V_430 ;
V_425 = ( T_1 T_2 * ) ( unsigned long ) V_210 -> V_424 ;
F_3 (prop_blob, &property->enum_blob_list, head) {
if ( F_91 ( V_422 -> V_13 . V_14 , V_423 + V_176 ) ) {
V_27 = - V_187 ;
goto V_427;
}
if ( F_91 ( V_422 -> V_431 , V_425 + V_176 ) ) {
V_27 = - V_187 ;
goto V_427;
}
V_176 ++ ;
}
}
V_210 -> V_429 = V_417 ;
}
V_427:
F_5 ( V_2 ) ;
return V_27 ;
}
static struct V_421 * F_140 ( struct V_1 * V_2 , int V_431 ,
void * V_165 )
{
struct V_421 * V_432 ;
int V_27 ;
if ( ! V_431 || ! V_165 )
return NULL ;
V_432 = F_66 ( sizeof( struct V_421 ) + V_431 , V_30 ) ;
if ( ! V_432 )
return NULL ;
V_27 = F_13 ( V_2 , & V_432 -> V_13 , V_433 ) ;
if ( V_27 ) {
F_49 ( V_432 ) ;
return NULL ;
}
V_432 -> V_431 = V_431 ;
memcpy ( V_432 -> V_165 , V_165 , V_431 ) ;
F_47 ( & V_432 -> V_42 , & V_2 -> V_5 . V_132 ) ;
return V_432 ;
}
static void F_141 ( struct V_1 * V_2 ,
struct V_421 * V_432 )
{
F_15 ( V_2 , & V_432 -> V_13 ) ;
F_39 ( & V_432 -> V_42 ) ;
F_49 ( V_432 ) ;
}
int F_142 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_24 * V_25 ;
struct V_434 * V_210 = V_165 ;
struct V_421 * V_432 ;
int V_27 = 0 ;
void T_2 * V_435 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_210 -> V_436 , V_433 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_427;
}
V_432 = F_143 ( V_25 ) ;
if ( V_210 -> V_431 == V_432 -> V_431 ) {
V_435 = ( void T_2 * ) ( unsigned long ) V_210 -> V_165 ;
if ( F_96 ( V_435 , V_432 -> V_165 , V_432 -> V_431 ) ) {
V_27 = - V_187 ;
goto V_427;
}
}
V_210 -> V_431 = V_432 -> V_431 ;
V_427:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_144 ( struct V_15 * V_16 ,
struct V_91 * V_91 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
int V_27 , V_437 ;
if ( V_16 -> V_66 )
F_141 ( V_2 , V_16 -> V_66 ) ;
if ( ! V_91 ) {
V_16 -> V_66 = NULL ;
V_27 = F_136 ( & V_16 -> V_13 , V_2 -> V_5 . V_71 , 0 ) ;
return V_27 ;
}
V_437 = V_438 * ( 1 + V_91 -> V_439 ) ;
V_16 -> V_66 = F_140 ( V_16 -> V_2 ,
V_437 , V_91 ) ;
if ( ! V_16 -> V_66 )
return - V_183 ;
V_27 = F_136 ( & V_16 -> V_13 ,
V_2 -> V_5 . V_71 ,
V_16 -> V_66 -> V_13 . V_14 ) ;
return V_27 ;
}
static bool F_145 ( struct V_90 * V_144 ,
T_3 V_409 )
{
if ( V_144 -> V_161 & V_94 )
return false ;
if ( V_144 -> V_161 & V_407 ) {
if ( V_409 < V_144 -> V_236 [ 0 ] || V_409 > V_144 -> V_236 [ 1 ] )
return false ;
return true ;
} else if ( V_144 -> V_161 & V_404 ) {
int V_105 ;
T_3 V_440 = 0 ;
for ( V_105 = 0 ; V_105 < V_144 -> V_397 ; V_105 ++ )
V_440 |= ( 1ULL << V_144 -> V_236 [ V_105 ] ) ;
return ! ( V_409 & ~ V_440 ) ;
} else if ( V_144 -> V_161 & V_93 ) {
return true ;
} else {
int V_105 ;
for ( V_105 = 0 ; V_105 < V_144 -> V_397 ; V_105 ++ )
if ( V_144 -> V_236 [ V_105 ] == V_409 )
return true ;
return false ;
}
}
int F_146 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_441 * V_442 = V_165 ;
struct V_443 V_444 = {
. V_409 = V_442 -> V_409 ,
. V_426 = V_442 -> V_426 ,
. V_445 = V_442 -> V_179 ,
. V_26 = V_62
} ;
return F_147 ( V_2 , & V_444 , V_167 ) ;
}
static int F_148 ( struct V_24 * V_25 ,
struct V_90 * V_144 ,
T_3 V_409 )
{
int V_27 = - V_183 ;
struct V_15 * V_16 = F_95 ( V_25 ) ;
if ( V_144 == V_16 -> V_2 -> V_5 . V_72 ) {
if ( V_16 -> V_36 -> V_92 )
(* V_16 -> V_36 -> V_92 )( V_16 , ( int ) V_409 ) ;
V_27 = 0 ;
} else if ( V_16 -> V_36 -> V_446 )
V_27 = V_16 -> V_36 -> V_446 ( V_16 , V_144 , V_409 ) ;
if ( ! V_27 )
F_136 ( & V_16 -> V_13 , V_144 , V_409 ) ;
return V_27 ;
}
static int F_149 ( struct V_24 * V_25 ,
struct V_90 * V_144 ,
T_3 V_409 )
{
int V_27 = - V_183 ;
struct V_3 * V_4 = F_93 ( V_25 ) ;
if ( V_4 -> V_36 -> V_446 )
V_27 = V_4 -> V_36 -> V_446 ( V_4 , V_144 , V_409 ) ;
if ( ! V_27 )
F_136 ( V_25 , V_144 , V_409 ) ;
return V_27 ;
}
static int F_150 ( struct V_24 * V_25 ,
struct V_90 * V_144 ,
T_3 V_409 )
{
int V_27 = - V_183 ;
struct V_46 * V_47 = F_101 ( V_25 ) ;
if ( V_47 -> V_36 -> V_446 )
V_27 = V_47 -> V_36 -> V_446 ( V_47 , V_144 , V_409 ) ;
if ( ! V_27 )
F_136 ( V_25 , V_144 , V_409 ) ;
return V_27 ;
}
int F_151 ( struct V_1 * V_2 , void * V_165 ,
struct V_166 * V_167 )
{
struct V_447 * V_448 = V_165 ;
struct V_24 * V_25 ;
int V_27 = 0 ;
int V_105 ;
int V_176 = 0 ;
int V_212 = 0 ;
T_1 T_2 * V_233 ;
T_3 T_2 * V_234 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_448 -> V_445 , V_448 -> V_26 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_40;
}
if ( ! V_25 -> V_54 ) {
V_27 = - V_183 ;
goto V_40;
}
V_212 = V_25 -> V_54 -> V_63 ;
if ( ( V_448 -> V_232 >= V_212 ) && V_212 ) {
V_176 = 0 ;
V_233 = ( T_1 T_2 * ) ( unsigned long ) ( V_448 -> V_233 ) ;
V_234 = ( T_3 T_2 * ) ( unsigned long )
( V_448 -> V_234 ) ;
for ( V_105 = 0 ; V_105 < V_212 ; V_105 ++ ) {
if ( F_91 ( V_25 -> V_54 -> V_235 [ V_105 ] ,
V_233 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
if ( F_91 ( V_25 -> V_54 -> V_236 [ V_105 ] ,
V_234 + V_176 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_176 ++ ;
}
}
V_448 -> V_232 = V_212 ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_147 ( struct V_1 * V_2 , void * V_165 ,
struct V_166 * V_167 )
{
struct V_443 * V_448 = V_165 ;
struct V_24 * V_449 ;
struct V_24 * V_450 ;
struct V_90 * V_144 ;
int V_27 = - V_183 ;
int V_105 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_449 = F_17 ( V_2 , V_448 -> V_445 , V_448 -> V_26 ) ;
if ( ! V_449 )
goto V_40;
if ( ! V_449 -> V_54 )
goto V_40;
for ( V_105 = 0 ; V_105 < V_449 -> V_54 -> V_63 ; V_105 ++ )
if ( V_449 -> V_54 -> V_235 [ V_105 ] == V_448 -> V_426 )
break;
if ( V_105 == V_449 -> V_54 -> V_63 )
goto V_40;
V_450 = F_17 ( V_2 , V_448 -> V_426 ,
V_399 ) ;
if ( ! V_450 )
goto V_40;
V_144 = F_139 ( V_450 ) ;
if ( ! F_145 ( V_144 , V_448 -> V_409 ) )
goto V_40;
switch ( V_449 -> type ) {
case V_62 :
V_27 = F_148 ( V_449 , V_144 ,
V_448 -> V_409 ) ;
break;
case V_53 :
V_27 = F_149 ( V_449 , V_144 , V_448 -> V_409 ) ;
break;
case V_83 :
V_27 = F_150 ( V_449 , V_144 , V_448 -> V_409 ) ;
break;
}
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_152 ( struct V_15 * V_16 ,
struct V_7 * V_8 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_219 ; V_105 ++ ) {
if ( V_16 -> V_220 [ V_105 ] == 0 ) {
V_16 -> V_220 [ V_105 ] = V_8 -> V_13 . V_14 ;
return 0 ;
}
}
return - V_85 ;
}
void F_153 ( struct V_15 * V_16 ,
struct V_7 * V_8 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_219 ; V_105 ++ ) {
if ( V_16 -> V_220 [ V_105 ] == V_8 -> V_13 . V_14 ) {
V_16 -> V_220 [ V_105 ] = 0 ;
if ( V_16 -> V_8 == V_8 )
V_16 -> V_8 = NULL ;
break;
}
}
}
int F_154 ( struct V_3 * V_4 ,
int V_206 )
{
V_4 -> V_206 = V_206 ;
V_4 -> V_57 = F_66 ( V_206 * sizeof( V_451 ) * 3 , V_30 ) ;
if ( ! V_4 -> V_57 ) {
V_4 -> V_206 = 0 ;
return - V_85 ;
}
return 0 ;
}
int F_155 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_452 * V_453 = V_165 ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
void * V_454 , * V_455 , * V_456 ;
int V_437 ;
int V_27 = 0 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_453 -> V_178 , V_53 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_40;
}
V_4 = F_93 ( V_25 ) ;
if ( V_4 -> V_36 -> V_457 == NULL ) {
V_27 = - V_388 ;
goto V_40;
}
if ( V_453 -> V_206 != V_4 -> V_206 ) {
V_27 = - V_183 ;
goto V_40;
}
V_437 = V_453 -> V_206 * ( sizeof( V_451 ) ) ;
V_454 = V_4 -> V_57 ;
if ( F_123 ( V_454 , ( void T_2 * ) ( unsigned long ) V_453 -> V_458 , V_437 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_455 = V_454 + V_437 ;
if ( F_123 ( V_455 , ( void T_2 * ) ( unsigned long ) V_453 -> V_459 , V_437 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_456 = V_455 + V_437 ;
if ( F_123 ( V_456 , ( void T_2 * ) ( unsigned long ) V_453 -> V_460 , V_437 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_4 -> V_36 -> V_457 ( V_4 , V_454 , V_455 , V_456 , 0 , V_4 -> V_206 ) ;
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_156 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_452 * V_453 = V_165 ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
void * V_454 , * V_455 , * V_456 ;
int V_437 ;
int V_27 = 0 ;
if ( ! F_89 ( V_2 , V_182 ) )
return - V_183 ;
F_1 ( V_2 ) ;
V_25 = F_17 ( V_2 , V_453 -> V_178 , V_53 ) ;
if ( ! V_25 ) {
V_27 = - V_183 ;
goto V_40;
}
V_4 = F_93 ( V_25 ) ;
if ( V_453 -> V_206 != V_4 -> V_206 ) {
V_27 = - V_183 ;
goto V_40;
}
V_437 = V_453 -> V_206 * ( sizeof( V_451 ) ) ;
V_454 = V_4 -> V_57 ;
if ( F_96 ( ( void T_2 * ) ( unsigned long ) V_453 -> V_458 , V_454 , V_437 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_455 = V_454 + V_437 ;
if ( F_96 ( ( void T_2 * ) ( unsigned long ) V_453 -> V_459 , V_455 , V_437 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_456 = V_455 + V_437 ;
if ( F_96 ( ( void T_2 * ) ( unsigned long ) V_453 -> V_460 , V_456 , V_437 ) ) {
V_27 = - V_187 ;
goto V_40;
}
V_40:
F_5 ( V_2 ) ;
return V_27 ;
}
int F_157 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_461 * V_462 = V_165 ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
struct V_33 * V_34 = NULL , * V_256 = NULL ;
struct V_463 * V_464 = NULL ;
unsigned long V_161 ;
int V_149 , V_155 ;
int V_27 = - V_183 ;
if ( V_462 -> V_161 & ~ V_465 ||
V_462 -> V_466 != 0 )
return - V_183 ;
V_25 = F_17 ( V_2 , V_462 -> V_178 , V_53 ) ;
if ( ! V_25 )
return - V_183 ;
V_4 = F_93 ( V_25 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_34 == NULL ) {
V_27 = - V_467 ;
goto V_40;
}
if ( V_4 -> V_36 -> V_462 == NULL )
goto V_40;
V_34 = F_28 ( V_2 , V_462 -> V_177 ) ;
if ( ! V_34 )
goto V_40;
V_149 = V_4 -> V_59 . V_149 ;
V_155 = V_4 -> V_59 . V_155 ;
if ( V_4 -> V_52 )
F_105 ( V_149 , V_155 ) ;
if ( V_149 > V_34 -> V_260 ||
V_155 > V_34 -> V_261 ||
V_4 -> V_204 > V_34 -> V_260 - V_149 ||
V_4 -> V_205 > V_34 -> V_261 - V_155 ) {
F_63 ( L_44 ,
V_34 -> V_260 , V_34 -> V_261 , V_149 , V_155 , V_4 -> V_204 , V_4 -> V_205 ,
V_4 -> V_52 ? L_45 : L_46 ) ;
V_27 = - V_266 ;
goto V_40;
}
if ( V_462 -> V_161 & V_468 ) {
V_27 = - V_85 ;
F_158 ( & V_2 -> V_469 , V_161 ) ;
if ( V_167 -> V_470 < sizeof V_464 -> V_471 ) {
F_159 ( & V_2 -> V_469 , V_161 ) ;
goto V_40;
}
V_167 -> V_470 -= sizeof V_464 -> V_471 ;
F_159 ( & V_2 -> V_469 , V_161 ) ;
V_464 = F_66 ( sizeof *V_464 , V_30 ) ;
if ( V_464 == NULL ) {
F_158 ( & V_2 -> V_469 , V_161 ) ;
V_167 -> V_470 += sizeof V_464 -> V_471 ;
F_159 ( & V_2 -> V_469 , V_161 ) ;
goto V_40;
}
V_464 -> V_471 . V_13 . type = V_472 ;
V_464 -> V_471 . V_13 . V_431 = sizeof V_464 -> V_471 ;
V_464 -> V_471 . V_473 = V_462 -> V_473 ;
V_464 -> V_13 . V_471 = & V_464 -> V_471 . V_13 ;
V_464 -> V_13 . V_167 = V_167 ;
V_464 -> V_13 . V_45 =
( void ( * ) ( struct V_474 * ) ) F_49 ;
}
V_256 = V_4 -> V_34 ;
V_27 = V_4 -> V_36 -> V_462 ( V_4 , V_34 , V_464 ) ;
if ( V_27 ) {
if ( V_462 -> V_161 & V_468 ) {
F_158 ( & V_2 -> V_469 , V_161 ) ;
V_167 -> V_470 += sizeof V_464 -> V_471 ;
F_159 ( & V_2 -> V_469 , V_161 ) ;
F_49 ( V_464 ) ;
}
V_256 = NULL ;
} else {
F_8 ( V_4 -> V_34 != V_34 ) ;
V_34 = NULL ;
}
V_40:
if ( V_34 )
F_30 ( V_34 ) ;
if ( V_256 )
F_30 ( V_256 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_27 ;
}
void F_160 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
struct V_15 * V_16 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
if ( V_4 -> V_36 -> V_475 )
V_4 -> V_36 -> V_475 ( V_4 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
if ( V_8 -> V_36 -> V_475 )
V_8 -> V_36 -> V_475 ( V_8 ) ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_16 -> V_21 = V_67 ;
if ( V_16 -> V_36 -> V_475 )
V_16 -> V_36 -> V_475 ( V_16 ) ;
}
}
int F_161 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_476 * args = V_165 ;
if ( ! V_2 -> V_477 -> V_478 )
return - V_388 ;
return V_2 -> V_477 -> V_478 ( V_167 , V_2 , args ) ;
}
int F_162 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_479 * args = V_165 ;
if ( ! V_2 -> V_477 -> V_480 )
return - V_388 ;
return V_2 -> V_477 -> V_480 ( V_167 , V_2 , args -> V_286 , & args -> V_481 ) ;
}
int F_163 ( struct V_1 * V_2 ,
void * V_165 , struct V_166 * V_167 )
{
struct V_482 * args = V_165 ;
if ( ! V_2 -> V_477 -> V_483 )
return - V_388 ;
return V_2 -> V_477 -> V_483 ( V_167 , V_2 , args -> V_286 ) ;
}
void F_164 ( T_1 V_308 , unsigned int * V_290 ,
int * V_289 )
{
switch ( V_308 ) {
case V_292 :
case V_310 :
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
F_63 ( L_64 ) ;
* V_290 = 0 ;
* V_289 = 0 ;
break;
}
}
int F_116 ( T_1 V_308 )
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
int F_117 ( T_1 V_308 , int V_47 )
{
unsigned int V_290 ;
int V_289 ;
if ( V_47 >= F_116 ( V_308 ) )
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
return V_47 ? 2 : 1 ;
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
F_164 ( V_308 , & V_290 , & V_289 ) ;
return V_289 >> 3 ;
}
}
int F_114 ( T_1 V_308 )
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
int F_115 ( T_1 V_308 )
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
