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
void F_10 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_11 ( V_9 ) ; V_8 ++ )
F_12 ( & V_9 [ V_8 ] . V_10 ) ;
}
void F_13 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_11 ( V_9 ) ; V_8 ++ )
F_14 ( & V_9 [ V_8 ] . V_10 ) ;
}
const char * F_15 ( const struct V_11 * V_12 )
{
static char V_13 [ 32 ] ;
snprintf ( V_13 , 32 , L_1 ,
V_14 [ V_12 -> V_15 ] . V_16 ,
V_12 -> V_17 . V_18 ) ;
return V_13 ;
}
const char * F_16 ( const struct V_19 * V_20 )
{
static char V_13 [ 32 ] ;
snprintf ( V_13 , 32 , L_1 ,
V_9 [ V_20 -> V_21 ] . V_16 ,
V_20 -> V_22 ) ;
return V_13 ;
}
const char * F_17 ( enum V_23 V_24 )
{
if ( V_24 == V_25 )
return L_2 ;
else if ( V_24 == V_26 )
return L_3 ;
else
return L_4 ;
}
static char F_18 ( int V_27 )
{
return isascii ( V_27 ) && isprint ( V_27 ) ? V_27 : '?' ;
}
const char * F_19 ( T_1 V_28 )
{
static char V_13 [ 32 ] ;
snprintf ( V_13 , sizeof( V_13 ) ,
L_5 ,
F_18 ( V_28 & 0xff ) ,
F_18 ( ( V_28 >> 8 ) & 0xff ) ,
F_18 ( ( V_28 >> 16 ) & 0xff ) ,
F_18 ( ( V_28 >> 24 ) & 0x7f ) ,
V_28 & V_29 ? L_6 : L_7 ,
V_28 ) ;
return V_13 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_30 * V_31 , T_1 V_32 )
{
int V_33 ;
F_2 ( & V_2 -> V_5 . V_34 ) ;
V_33 = F_21 ( & V_2 -> V_5 . V_35 , V_31 , 1 , 0 , V_36 ) ;
if ( V_33 >= 0 ) {
V_31 -> V_18 = V_33 ;
V_31 -> type = V_32 ;
}
F_6 ( & V_2 -> V_5 . V_34 ) ;
return V_33 < 0 ? V_33 : 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_30 * V_37 )
{
F_2 ( & V_2 -> V_5 . V_34 ) ;
F_23 ( & V_2 -> V_5 . V_35 , V_37 -> V_18 ) ;
F_6 ( & V_2 -> V_5 . V_34 ) ;
}
struct V_30 * F_24 ( struct V_1 * V_2 ,
T_1 V_18 , T_1 type )
{
struct V_30 * V_31 = NULL ;
F_8 ( type == V_38 ) ;
F_2 ( & V_2 -> V_5 . V_34 ) ;
V_31 = F_25 ( & V_2 -> V_5 . V_35 , V_18 ) ;
if ( ! V_31 || ( V_31 -> type != type ) || ( V_31 -> V_18 != V_18 ) )
V_31 = NULL ;
F_6 ( & V_2 -> V_5 . V_34 ) ;
return V_31 ;
}
int F_26 ( struct V_1 * V_2 , struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
int V_33 ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
F_27 ( & V_40 -> V_44 ) ;
F_28 ( & V_40 -> V_45 ) ;
V_40 -> V_2 = V_2 ;
V_40 -> V_42 = V_42 ;
V_33 = F_20 ( V_2 , & V_40 -> V_17 , V_38 ) ;
if ( V_33 )
goto V_46;
F_29 ( V_40 ) ;
V_2 -> V_5 . V_47 ++ ;
F_30 ( & V_40 -> V_48 , & V_2 -> V_5 . V_49 ) ;
V_46:
F_6 ( & V_2 -> V_5 . V_43 ) ;
return 0 ;
}
static void F_31 ( struct V_50 * V_50 )
{
struct V_39 * V_40 =
F_32 ( V_50 , struct V_39 , V_44 ) ;
V_40 -> V_42 -> V_51 ( V_40 ) ;
}
static struct V_39 * F_33 ( struct V_1 * V_2 ,
T_1 V_18 )
{
struct V_30 * V_31 = NULL ;
struct V_39 * V_40 ;
F_2 ( & V_2 -> V_5 . V_34 ) ;
V_31 = F_25 ( & V_2 -> V_5 . V_35 , V_18 ) ;
if ( ! V_31 || ( V_31 -> type != V_38 ) || ( V_31 -> V_18 != V_18 ) )
V_40 = NULL ;
else
V_40 = F_34 ( V_31 ) ;
F_6 ( & V_2 -> V_5 . V_34 ) ;
return V_40 ;
}
struct V_39 * F_35 ( struct V_1 * V_2 ,
T_1 V_18 )
{
struct V_39 * V_40 ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
V_40 = F_33 ( V_2 , V_18 ) ;
if ( V_40 )
F_29 ( V_40 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
return V_40 ;
}
void F_36 ( struct V_39 * V_40 )
{
F_37 ( L_8 , V_40 -> V_17 . V_18 ) ;
F_38 ( & V_40 -> V_44 , F_31 ) ;
}
void F_29 ( struct V_39 * V_40 )
{
F_37 ( L_8 , V_40 -> V_17 . V_18 ) ;
F_39 ( & V_40 -> V_44 ) ;
}
static void F_40 ( struct V_50 * V_50 )
{
F_41 () ;
}
static void F_42 ( struct V_39 * V_40 )
{
F_37 ( L_8 , V_40 -> V_17 . V_18 ) ;
F_38 ( & V_40 -> V_44 , F_40 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
F_2 ( & V_2 -> V_5 . V_34 ) ;
F_23 ( & V_2 -> V_5 . V_35 , V_40 -> V_17 . V_18 ) ;
F_6 ( & V_2 -> V_5 . V_34 ) ;
V_40 -> V_17 . V_18 = 0 ;
F_42 ( V_40 ) ;
}
void F_44 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
F_43 ( V_2 , V_40 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
}
void F_45 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
F_46 ( & V_40 -> V_48 ) ;
V_2 -> V_5 . V_47 -- ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
}
void F_47 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_3 * V_4 ;
struct V_52 * V_53 ;
struct V_54 V_55 ;
int V_33 ;
F_8 ( ! F_48 ( & V_40 -> V_45 ) ) ;
if ( F_49 ( & V_40 -> V_44 . V_44 ) > 1 ) {
F_1 ( V_2 ) ;
F_3 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_4 -> V_40 == V_40 ) {
memset ( & V_55 , 0 , sizeof( struct V_54 ) ) ;
V_55 . V_4 = V_4 ;
V_55 . V_40 = NULL ;
V_33 = F_50 ( & V_55 ) ;
if ( V_33 )
F_51 ( L_9 , V_4 ) ;
}
}
F_3 (plane, &dev->mode_config.plane_list, head) {
if ( V_53 -> V_40 == V_40 )
F_52 ( V_53 ) ;
}
F_5 ( V_2 ) ;
}
F_36 ( V_40 ) ;
}
int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_56 * V_42 )
{
int V_33 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_42 = V_42 ;
V_4 -> V_57 = false ;
F_1 ( V_2 ) ;
F_54 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_6 , & V_2 -> V_5 . V_6 ) ;
V_33 = F_20 ( V_2 , & V_4 -> V_17 , V_58 ) ;
if ( V_33 )
goto V_46;
V_4 -> V_17 . V_59 = & V_4 -> V_59 ;
F_55 ( & V_4 -> V_48 , & V_2 -> V_5 . V_60 ) ;
V_2 -> V_5 . V_61 ++ ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_56 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_57 ( V_4 -> V_62 ) ;
V_4 -> V_62 = NULL ;
F_22 ( V_2 , & V_4 -> V_17 ) ;
F_46 ( & V_4 -> V_48 ) ;
V_2 -> V_5 . V_61 -- ;
}
unsigned int F_58 ( struct V_3 * V_4 )
{
unsigned int V_63 = 0 ;
struct V_3 * V_64 ;
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_64 == V_4 )
return V_63 ;
V_63 ++ ;
}
F_41 () ;
}
void F_59 ( struct V_19 * V_20 ,
struct V_65 * V_66 )
{
F_55 ( & V_66 -> V_48 , & V_20 -> V_67 ) ;
}
static void F_60 ( struct V_19 * V_20 ,
struct V_65 * V_66 )
{
F_46 ( & V_66 -> V_48 ) ;
F_61 ( V_20 -> V_2 , V_66 ) ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const struct V_68 * V_42 ,
int V_21 )
{
int V_33 ;
struct V_10 * V_69 =
& V_9 [ V_21 ] . V_10 ;
F_1 ( V_2 ) ;
V_33 = F_20 ( V_2 , & V_20 -> V_17 , V_70 ) ;
if ( V_33 )
goto V_46;
V_20 -> V_17 . V_59 = & V_20 -> V_59 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_42 = V_42 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_22 =
F_63 ( V_69 , 1 , 0 , V_36 ) ;
if ( V_20 -> V_22 < 0 ) {
V_33 = V_20 -> V_22 ;
F_22 ( V_2 , & V_20 -> V_17 ) ;
goto V_46;
}
F_28 ( & V_20 -> V_67 ) ;
F_28 ( & V_20 -> V_71 ) ;
V_20 -> V_72 = NULL ;
V_20 -> V_24 = V_73 ;
F_55 ( & V_20 -> V_48 , & V_2 -> V_5 . V_74 ) ;
V_2 -> V_5 . V_75 ++ ;
if ( V_21 != V_76 )
F_64 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_77 ,
0 ) ;
F_64 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_78 , 0 ) ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_65 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_65 * V_66 , * V_79 ;
F_66 (mode, t, &connector->probed_modes, head)
F_60 ( V_20 , V_66 ) ;
F_66 (mode, t, &connector->modes, head)
F_60 ( V_20 , V_66 ) ;
F_67 ( & V_9 [ V_20 -> V_21 ] . V_10 ,
V_20 -> V_22 ) ;
F_22 ( V_2 , & V_20 -> V_17 ) ;
F_46 ( & V_20 -> V_48 ) ;
V_2 -> V_5 . V_75 -- ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
F_3 (connector, &dev->mode_config.connector_list, head)
F_69 ( V_20 ) ;
}
int F_70 ( struct V_1 * V_2 , struct V_80 * V_81 ,
const struct V_82 * V_42 )
{
int V_33 ;
F_1 ( V_2 ) ;
V_33 = F_20 ( V_2 , & V_81 -> V_17 , V_83 ) ;
if ( V_33 )
goto V_46;
V_81 -> V_2 = V_2 ;
V_81 -> V_42 = V_42 ;
F_55 ( & V_81 -> V_48 , & V_2 -> V_5 . V_84 ) ;
V_2 -> V_5 . V_85 ++ ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_71 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = V_81 -> V_2 ;
F_1 ( V_2 ) ;
F_22 ( V_2 , & V_81 -> V_17 ) ;
F_46 ( & V_81 -> V_48 ) ;
V_2 -> V_5 . V_85 -- ;
F_5 ( V_2 ) ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
const struct V_86 * V_42 ,
int V_15 )
{
int V_33 ;
F_1 ( V_2 ) ;
V_33 = F_20 ( V_2 , & V_12 -> V_17 , V_87 ) ;
if ( V_33 )
goto V_46;
V_12 -> V_2 = V_2 ;
V_12 -> V_15 = V_15 ;
V_12 -> V_42 = V_42 ;
F_55 ( & V_12 -> V_48 , & V_2 -> V_5 . V_88 ) ;
V_2 -> V_5 . V_89 ++ ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_73 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_1 ( V_2 ) ;
F_22 ( V_2 , & V_12 -> V_17 ) ;
F_46 ( & V_12 -> V_48 ) ;
V_2 -> V_5 . V_89 -- ;
F_5 ( V_2 ) ;
}
int F_74 ( struct V_1 * V_2 , struct V_52 * V_53 ,
unsigned long V_90 ,
const struct V_91 * V_42 ,
const T_1 * V_92 , T_1 V_93 ,
bool V_94 )
{
int V_33 ;
F_1 ( V_2 ) ;
V_33 = F_20 ( V_2 , & V_53 -> V_17 , V_95 ) ;
if ( V_33 )
goto V_46;
V_53 -> V_17 . V_59 = & V_53 -> V_59 ;
V_53 -> V_2 = V_2 ;
V_53 -> V_42 = V_42 ;
V_53 -> V_96 = F_75 ( sizeof( T_1 ) * V_93 ,
V_36 ) ;
if ( ! V_53 -> V_96 ) {
F_76 ( L_10 ) ;
F_22 ( V_2 , & V_53 -> V_17 ) ;
V_33 = - V_97 ;
goto V_46;
}
memcpy ( V_53 -> V_96 , V_92 , V_93 * sizeof( T_1 ) ) ;
V_53 -> V_93 = V_93 ;
V_53 -> V_90 = V_90 ;
if ( ! V_94 ) {
F_55 ( & V_53 -> V_48 , & V_2 -> V_5 . V_98 ) ;
V_2 -> V_5 . V_99 ++ ;
} else {
F_28 ( & V_53 -> V_48 ) ;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_77 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
F_1 ( V_2 ) ;
F_57 ( V_53 -> V_96 ) ;
F_22 ( V_2 , & V_53 -> V_17 ) ;
if ( ! F_48 ( & V_53 -> V_48 ) ) {
F_46 ( & V_53 -> V_48 ) ;
V_2 -> V_5 . V_99 -- ;
}
F_5 ( V_2 ) ;
}
void F_52 ( struct V_52 * V_53 )
{
int V_33 ;
if ( ! V_53 -> V_40 )
return;
V_33 = V_53 -> V_42 -> V_100 ( V_53 ) ;
if ( V_33 )
F_51 ( L_11 ) ;
F_42 ( V_53 -> V_40 ) ;
V_53 -> V_40 = NULL ;
V_53 -> V_4 = NULL ;
}
struct V_65 * F_78 ( struct V_1 * V_2 )
{
struct V_65 * V_101 ;
V_101 = F_79 ( sizeof( struct V_65 ) , V_36 ) ;
if ( ! V_101 )
return NULL ;
if ( F_20 ( V_2 , & V_101 -> V_17 , V_102 ) ) {
F_57 ( V_101 ) ;
return NULL ;
}
return V_101 ;
}
void F_61 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
if ( ! V_66 )
return;
F_22 ( V_2 , & V_66 -> V_17 ) ;
F_57 ( V_66 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_103 * V_104 ;
struct V_103 * V_105 ;
V_104 = F_81 ( V_2 , V_106 |
V_107 ,
L_12 , 0 ) ;
V_2 -> V_5 . V_77 = V_104 ;
V_105 = F_82 ( V_2 , 0 ,
L_13 , V_108 ,
F_11 ( V_108 ) ) ;
V_2 -> V_5 . V_78 = V_105 ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
struct V_103 * V_109 ;
struct V_103 * V_110 ;
if ( V_2 -> V_5 . V_111 )
return 0 ;
V_109 =
F_82 ( V_2 , 0 ,
L_14 ,
V_112 ,
F_11 ( V_112 ) ) ;
V_2 -> V_5 . V_111 = V_109 ;
V_110 = F_82 ( V_2 , V_107 ,
L_15 ,
V_113 ,
F_11 ( V_113 ) ) ;
V_2 -> V_5 . V_114 = V_110 ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 , int V_115 ,
char * V_71 [] )
{
struct V_103 * V_116 ;
struct V_103 * V_117 ;
int V_8 ;
if ( V_2 -> V_5 . V_118 )
return 0 ;
V_116 = F_82 ( V_2 , 0 ,
L_14 ,
V_119 ,
F_11 ( V_119 ) ) ;
V_2 -> V_5 . V_118 = V_116 ;
V_117 =
F_82 ( V_2 , V_107 ,
L_15 ,
V_120 ,
F_11 ( V_120 ) ) ;
V_2 -> V_5 . V_121 = V_117 ;
V_2 -> V_5 . V_122 =
F_85 ( V_2 , 0 , L_16 , 0 , 100 ) ;
V_2 -> V_5 . V_123 =
F_85 ( V_2 , 0 , L_17 , 0 , 100 ) ;
V_2 -> V_5 . V_124 =
F_85 ( V_2 , 0 , L_18 , 0 , 100 ) ;
V_2 -> V_5 . V_125 =
F_85 ( V_2 , 0 , L_19 , 0 , 100 ) ;
V_2 -> V_5 . V_126 =
F_81 ( V_2 , V_127 ,
L_20 , V_115 ) ;
for ( V_8 = 0 ; V_8 < V_115 ; V_8 ++ )
F_86 ( V_2 -> V_5 . V_126 , V_8 ,
V_8 , V_71 [ V_8 ] ) ;
V_2 -> V_5 . V_128 =
F_85 ( V_2 , 0 , L_21 , 0 , 100 ) ;
V_2 -> V_5 . V_129 =
F_85 ( V_2 , 0 , L_22 , 0 , 100 ) ;
V_2 -> V_5 . V_130 =
F_85 ( V_2 , 0 , L_23 , 0 , 100 ) ;
V_2 -> V_5 . V_131 =
F_85 ( V_2 , 0 , L_24 , 0 , 100 ) ;
V_2 -> V_5 . V_132 =
F_85 ( V_2 , 0 , L_25 , 0 , 100 ) ;
V_2 -> V_5 . V_133 =
F_85 ( V_2 , 0 , L_26 , 0 , 100 ) ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 )
{
struct V_103 * V_134 ;
if ( V_2 -> V_5 . V_135 )
return 0 ;
V_134 =
F_82 ( V_2 , 0 , L_27 ,
V_136 ,
F_11 ( V_136 ) ) ;
V_2 -> V_5 . V_135 = V_134 ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 )
{
struct V_103 * V_137 ;
if ( V_2 -> V_5 . V_138 )
return 0 ;
V_137 =
F_82 ( V_2 , V_107 ,
L_28 ,
V_139 ,
F_11 ( V_139 ) ) ;
V_2 -> V_5 . V_138 = V_137 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_140 * V_141 )
{
T_1 V_142 = 0 ;
V_142 += V_2 -> V_5 . V_61 ;
V_142 += V_2 -> V_5 . V_75 ;
V_142 += V_2 -> V_5 . V_89 ;
V_142 += V_2 -> V_5 . V_85 ;
V_141 -> V_143 = F_79 ( V_142 * sizeof( T_1 ) , V_36 ) ;
if ( ! V_141 -> V_143 )
return - V_97 ;
V_141 -> V_144 = 0 ;
V_141 -> V_145 = 0 ;
V_141 -> V_146 = 0 ;
V_141 -> V_147 = 0 ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_140 * V_141 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_19 * V_20 ;
struct V_80 * V_81 ;
int V_33 ;
if ( ( V_33 = F_89 ( V_2 , V_141 ) ) )
return V_33 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
V_141 -> V_143 [ V_141 -> V_144 ++ ] = V_4 -> V_17 . V_18 ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
V_141 -> V_143 [ V_141 -> V_144 + V_141 -> V_146 ++ ] =
V_12 -> V_17 . V_18 ;
F_3 (connector, &dev->mode_config.connector_list, head)
V_141 -> V_143 [ V_141 -> V_144 + V_141 -> V_146 +
V_141 -> V_145 ++ ] = V_20 -> V_17 . V_18 ;
F_3 (bridge, &dev->mode_config.bridge_list, head)
V_141 -> V_143 [ V_141 -> V_144 + V_141 -> V_146 +
V_141 -> V_145 + V_141 -> V_147 ++ ] =
V_81 -> V_17 . V_18 ;
return 0 ;
}
static void F_91 ( struct V_148 * V_46 ,
const struct V_65 * V_149 )
{
F_92 ( V_149 -> V_150 > V_151 || V_149 -> V_152 > V_151 ||
V_149 -> V_153 > V_151 || V_149 -> V_154 > V_151 ||
V_149 -> V_155 > V_151 || V_149 -> V_156 > V_151 ||
V_149 -> V_157 > V_151 || V_149 -> V_158 > V_151 ||
V_149 -> V_159 > V_151 || V_149 -> V_160 > V_151 ,
L_29 ) ;
V_46 -> clock = V_149 -> clock ;
V_46 -> V_150 = V_149 -> V_150 ;
V_46 -> V_152 = V_149 -> V_152 ;
V_46 -> V_153 = V_149 -> V_153 ;
V_46 -> V_154 = V_149 -> V_154 ;
V_46 -> V_155 = V_149 -> V_155 ;
V_46 -> V_156 = V_149 -> V_156 ;
V_46 -> V_157 = V_149 -> V_157 ;
V_46 -> V_158 = V_149 -> V_158 ;
V_46 -> V_159 = V_149 -> V_159 ;
V_46 -> V_160 = V_149 -> V_160 ;
V_46 -> V_161 = V_149 -> V_161 ;
V_46 -> V_162 = V_149 -> V_162 ;
V_46 -> type = V_149 -> type ;
strncpy ( V_46 -> V_16 , V_149 -> V_16 , V_163 ) ;
V_46 -> V_16 [ V_163 - 1 ] = 0 ;
}
static int F_93 ( struct V_65 * V_46 ,
const struct V_148 * V_149 )
{
if ( V_149 -> clock > V_164 || V_149 -> V_161 > V_164 )
return - V_165 ;
if ( ( V_149 -> V_162 & V_166 ) > V_167 )
return - V_168 ;
V_46 -> clock = V_149 -> clock ;
V_46 -> V_150 = V_149 -> V_150 ;
V_46 -> V_152 = V_149 -> V_152 ;
V_46 -> V_153 = V_149 -> V_153 ;
V_46 -> V_154 = V_149 -> V_154 ;
V_46 -> V_155 = V_149 -> V_155 ;
V_46 -> V_156 = V_149 -> V_156 ;
V_46 -> V_157 = V_149 -> V_157 ;
V_46 -> V_158 = V_149 -> V_158 ;
V_46 -> V_159 = V_149 -> V_159 ;
V_46 -> V_160 = V_149 -> V_160 ;
V_46 -> V_161 = V_149 -> V_161 ;
V_46 -> V_162 = V_149 -> V_162 ;
V_46 -> type = V_149 -> type ;
strncpy ( V_46 -> V_16 , V_149 -> V_16 , V_163 ) ;
V_46 -> V_16 [ V_163 - 1 ] = 0 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 , void * V_169 ,
struct V_170 * V_171 )
{
struct V_172 * V_173 = V_169 ;
struct V_174 * V_175 ;
struct V_39 * V_40 ;
struct V_19 * V_20 ;
struct V_3 * V_4 ;
struct V_11 * V_12 ;
int V_33 = 0 ;
int V_176 = 0 ;
int V_177 = 0 ;
int V_178 = 0 ;
int V_179 = 0 ;
int V_180 = 0 , V_8 ;
T_1 T_2 * V_181 ;
T_1 T_2 * V_182 ;
T_1 T_2 * V_183 ;
T_1 T_2 * V_184 ;
struct V_140 * V_185 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_2 ( & V_171 -> V_187 ) ;
F_96 (lh, &file_priv->fbs)
V_178 ++ ;
if ( V_173 -> V_188 >= V_178 ) {
V_180 = 0 ;
V_181 = ( T_1 T_2 * ) ( unsigned long ) V_173 -> V_189 ;
F_3 (fb, &file_priv->fbs, filp_head) {
if ( F_97 ( V_40 -> V_17 . V_18 , V_181 + V_180 ) ) {
F_6 ( & V_171 -> V_187 ) ;
return - V_190 ;
}
V_180 ++ ;
}
}
V_173 -> V_188 = V_178 ;
F_6 ( & V_171 -> V_187 ) ;
F_1 ( V_2 ) ;
V_185 = & V_171 -> V_191 -> V_192 -> V_185 ;
if ( V_171 -> V_191 -> V_192 -> type == V_193 ) {
F_96 (lh, &dev->mode_config.crtc_list)
V_177 ++ ;
F_96 (lh, &dev->mode_config.connector_list)
V_176 ++ ;
F_96 (lh, &dev->mode_config.encoder_list)
V_179 ++ ;
} else {
V_177 = V_185 -> V_144 ;
V_176 = V_185 -> V_145 ;
V_179 = V_185 -> V_146 ;
}
V_173 -> V_194 = V_2 -> V_5 . V_194 ;
V_173 -> V_195 = V_2 -> V_5 . V_195 ;
V_173 -> V_196 = V_2 -> V_5 . V_196 ;
V_173 -> V_197 = V_2 -> V_5 . V_197 ;
if ( V_173 -> V_198 >= V_177 ) {
V_180 = 0 ;
V_182 = ( T_1 T_2 * ) ( unsigned long ) V_173 -> V_199 ;
if ( V_171 -> V_191 -> V_192 -> type == V_193 ) {
F_3 (crtc, &dev->mode_config.crtc_list,
head) {
F_76 ( L_30 , V_4 -> V_17 . V_18 ) ;
if ( F_97 ( V_4 -> V_17 . V_18 , V_182 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
} else {
for ( V_8 = 0 ; V_8 < V_185 -> V_144 ; V_8 ++ ) {
if ( F_97 ( V_185 -> V_143 [ V_8 ] ,
V_182 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
}
}
V_173 -> V_198 = V_177 ;
if ( V_173 -> V_200 >= V_179 ) {
V_180 = 0 ;
V_184 = ( T_1 T_2 * ) ( unsigned long ) V_173 -> V_201 ;
if ( V_171 -> V_191 -> V_192 -> type == V_193 ) {
F_3 (encoder,
&dev->mode_config.encoder_list,
head) {
F_76 ( L_31 , V_12 -> V_17 . V_18 ,
F_15 ( V_12 ) ) ;
if ( F_97 ( V_12 -> V_17 . V_18 , V_184 +
V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
} else {
for ( V_8 = V_185 -> V_144 ; V_8 < V_185 -> V_144 + V_185 -> V_146 ; V_8 ++ ) {
if ( F_97 ( V_185 -> V_143 [ V_8 ] ,
V_184 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
}
}
V_173 -> V_200 = V_179 ;
if ( V_173 -> V_202 >= V_176 ) {
V_180 = 0 ;
V_183 = ( T_1 T_2 * ) ( unsigned long ) V_173 -> V_203 ;
if ( V_171 -> V_191 -> V_192 -> type == V_193 ) {
F_3 (connector,
&dev->mode_config.connector_list,
head) {
F_76 ( L_32 ,
V_20 -> V_17 . V_18 ,
F_16 ( V_20 ) ) ;
if ( F_97 ( V_20 -> V_17 . V_18 ,
V_183 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
} else {
int V_204 = V_185 -> V_144 +
V_185 -> V_146 ;
for ( V_8 = V_204 ; V_8 < V_204 + V_185 -> V_145 ; V_8 ++ ) {
if ( F_97 ( V_185 -> V_143 [ V_8 ] ,
V_183 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
}
}
V_173 -> V_202 = V_176 ;
F_76 ( L_33 , V_173 -> V_198 ,
V_173 -> V_202 , V_173 -> V_200 ) ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_98 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_205 * V_206 = V_169 ;
struct V_3 * V_4 ;
struct V_30 * V_31 ;
int V_33 = 0 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_206 -> V_182 ,
V_58 ) ;
if ( ! V_31 ) {
V_33 = - V_207 ;
goto V_46;
}
V_4 = F_99 ( V_31 ) ;
V_206 -> V_208 = V_4 -> V_208 ;
V_206 -> V_209 = V_4 -> V_209 ;
V_206 -> V_210 = V_4 -> V_210 ;
if ( V_4 -> V_40 )
V_206 -> V_181 = V_4 -> V_40 -> V_17 . V_18 ;
else
V_206 -> V_181 = 0 ;
if ( V_4 -> V_211 ) {
F_91 ( & V_206 -> V_66 , & V_4 -> V_66 ) ;
V_206 -> V_212 = 1 ;
} else {
V_206 -> V_212 = 0 ;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
static bool F_100 ( const struct V_65 * V_66 ,
const struct V_170 * V_171 )
{
if ( ! V_171 -> V_213 && F_101 ( V_66 ) )
return false ;
return true ;
}
int F_102 ( struct V_1 * V_2 , void * V_169 ,
struct V_170 * V_171 )
{
struct V_214 * V_215 = V_169 ;
struct V_30 * V_31 ;
struct V_19 * V_20 ;
struct V_65 * V_66 ;
int V_216 = 0 ;
int V_217 = 0 ;
int V_218 = 0 ;
int V_33 = 0 ;
int V_180 = 0 ;
int V_8 ;
struct V_148 V_219 ;
struct V_148 T_2 * V_220 ;
T_1 T_2 * V_221 ;
T_3 T_2 * V_222 ;
T_1 T_2 * V_223 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
memset ( & V_219 , 0 , sizeof( struct V_148 ) ) ;
F_76 ( L_34 , V_215 -> V_183 ) ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_31 = F_24 ( V_2 , V_215 -> V_183 ,
V_70 ) ;
if ( ! V_31 ) {
V_33 = - V_207 ;
goto V_46;
}
V_20 = F_103 ( V_31 ) ;
V_217 = V_20 -> V_59 . V_224 ;
for ( V_8 = 0 ; V_8 < V_225 ; V_8 ++ ) {
if ( V_20 -> V_226 [ V_8 ] != 0 ) {
V_218 ++ ;
}
}
if ( V_215 -> V_227 == 0 ) {
V_20 -> V_42 -> V_228 ( V_20 ,
V_2 -> V_5 . V_196 ,
V_2 -> V_5 . V_194 ) ;
}
F_3 (mode, &connector->modes, head)
if ( F_100 ( V_66 , V_171 ) )
V_216 ++ ;
V_215 -> V_183 = V_20 -> V_17 . V_18 ;
V_215 -> V_21 = V_20 -> V_21 ;
V_215 -> V_22 = V_20 -> V_22 ;
V_215 -> V_229 = V_20 -> V_230 . V_231 ;
V_215 -> V_232 = V_20 -> V_230 . V_233 ;
V_215 -> V_234 = V_20 -> V_230 . V_235 ;
V_215 -> V_236 = V_20 -> V_24 ;
if ( V_20 -> V_12 )
V_215 -> V_184 = V_20 -> V_12 -> V_17 . V_18 ;
else
V_215 -> V_184 = 0 ;
if ( ( V_215 -> V_227 >= V_216 ) && V_216 ) {
V_180 = 0 ;
V_220 = (struct V_148 T_2 * ) ( unsigned long ) V_215 -> V_237 ;
F_3 (mode, &connector->modes, head) {
if ( ! F_100 ( V_66 , V_171 ) )
continue;
F_91 ( & V_219 , V_66 ) ;
if ( F_104 ( V_220 + V_180 ,
& V_219 , sizeof( V_219 ) ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
}
V_215 -> V_227 = V_216 ;
if ( ( V_215 -> V_238 >= V_217 ) && V_217 ) {
V_180 = 0 ;
V_221 = ( T_1 T_2 * ) ( unsigned long ) ( V_215 -> V_239 ) ;
V_222 = ( T_3 T_2 * ) ( unsigned long ) ( V_215 -> V_240 ) ;
for ( V_8 = 0 ; V_8 < V_20 -> V_59 . V_224 ; V_8 ++ ) {
if ( F_97 ( V_20 -> V_59 . V_241 [ V_8 ] ,
V_221 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
if ( F_97 ( V_20 -> V_59 . V_242 [ V_8 ] ,
V_222 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
}
V_215 -> V_238 = V_217 ;
if ( ( V_215 -> V_200 >= V_218 ) && V_218 ) {
V_180 = 0 ;
V_223 = ( T_1 T_2 * ) ( unsigned long ) ( V_215 -> V_243 ) ;
for ( V_8 = 0 ; V_8 < V_225 ; V_8 ++ ) {
if ( V_20 -> V_226 [ V_8 ] != 0 ) {
if ( F_97 ( V_20 -> V_226 [ V_8 ] ,
V_223 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
}
}
V_215 -> V_200 = V_218 ;
V_46:
F_6 ( & V_2 -> V_5 . V_6 ) ;
return V_33 ;
}
int F_105 ( struct V_1 * V_2 , void * V_169 ,
struct V_170 * V_171 )
{
struct V_244 * V_245 = V_169 ;
struct V_30 * V_31 ;
struct V_11 * V_12 ;
int V_33 = 0 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_245 -> V_184 ,
V_87 ) ;
if ( ! V_31 ) {
V_33 = - V_207 ;
goto V_46;
}
V_12 = F_106 ( V_31 ) ;
if ( V_12 -> V_4 )
V_245 -> V_182 = V_12 -> V_4 -> V_17 . V_18 ;
else
V_245 -> V_182 = 0 ;
V_245 -> V_15 = V_12 -> V_15 ;
V_245 -> V_184 = V_12 -> V_17 . V_18 ;
V_245 -> V_90 = V_12 -> V_90 ;
V_245 -> V_246 = V_12 -> V_246 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_107 ( struct V_1 * V_2 , void * V_169 ,
struct V_170 * V_171 )
{
struct V_247 * V_248 = V_169 ;
struct V_249 * V_250 ;
struct V_52 * V_53 ;
T_1 T_2 * V_251 ;
int V_180 = 0 , V_33 = 0 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_250 = & V_2 -> V_5 ;
if ( V_250 -> V_99 &&
( V_248 -> V_252 >= V_250 -> V_99 ) ) {
V_251 = ( T_1 T_2 * ) ( unsigned long ) V_248 -> V_253 ;
F_3 (plane, &config->plane_list, head) {
if ( F_97 ( V_53 -> V_17 . V_18 , V_251 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
}
V_248 -> V_252 = V_250 -> V_99 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_108 ( struct V_1 * V_2 , void * V_169 ,
struct V_170 * V_171 )
{
struct V_254 * V_248 = V_169 ;
struct V_30 * V_31 ;
struct V_52 * V_53 ;
T_1 T_2 * V_255 ;
int V_33 = 0 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_248 -> V_256 ,
V_95 ) ;
if ( ! V_31 ) {
V_33 = - V_207 ;
goto V_46;
}
V_53 = F_109 ( V_31 ) ;
if ( V_53 -> V_4 )
V_248 -> V_182 = V_53 -> V_4 -> V_17 . V_18 ;
else
V_248 -> V_182 = 0 ;
if ( V_53 -> V_40 )
V_248 -> V_181 = V_53 -> V_40 -> V_17 . V_18 ;
else
V_248 -> V_181 = 0 ;
V_248 -> V_256 = V_53 -> V_17 . V_18 ;
V_248 -> V_90 = V_53 -> V_90 ;
V_248 -> V_210 = 0 ;
if ( V_53 -> V_93 &&
( V_248 -> V_257 >= V_53 -> V_93 ) ) {
V_255 = ( T_1 T_2 * ) ( unsigned long ) V_248 -> V_258 ;
if ( F_104 ( V_255 ,
V_53 -> V_96 ,
sizeof( T_1 ) * V_53 -> V_93 ) ) {
V_33 = - V_190 ;
goto V_46;
}
}
V_248 -> V_257 = V_53 -> V_93 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_110 ( struct V_1 * V_2 , void * V_169 ,
struct V_170 * V_171 )
{
struct V_259 * V_260 = V_169 ;
struct V_30 * V_31 ;
struct V_52 * V_53 ;
struct V_3 * V_4 ;
struct V_39 * V_40 = NULL , * V_261 = NULL ;
int V_33 = 0 ;
unsigned int V_262 , V_263 ;
int V_8 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
V_31 = F_24 ( V_2 , V_260 -> V_256 ,
V_95 ) ;
if ( ! V_31 ) {
F_76 ( L_35 ,
V_260 -> V_256 ) ;
return - V_207 ;
}
V_53 = F_109 ( V_31 ) ;
if ( ! V_260 -> V_181 ) {
F_1 ( V_2 ) ;
V_261 = V_53 -> V_40 ;
V_53 -> V_42 -> V_100 ( V_53 ) ;
V_53 -> V_4 = NULL ;
V_53 -> V_40 = NULL ;
F_5 ( V_2 ) ;
goto V_46;
}
V_31 = F_24 ( V_2 , V_260 -> V_182 ,
V_58 ) ;
if ( ! V_31 ) {
F_76 ( L_36 ,
V_260 -> V_182 ) ;
V_33 = - V_207 ;
goto V_46;
}
V_4 = F_99 ( V_31 ) ;
V_40 = F_35 ( V_2 , V_260 -> V_181 ) ;
if ( ! V_40 ) {
F_76 ( L_37 ,
V_260 -> V_181 ) ;
V_33 = - V_207 ;
goto V_46;
}
for ( V_8 = 0 ; V_8 < V_53 -> V_93 ; V_8 ++ )
if ( V_40 -> V_264 == V_53 -> V_96 [ V_8 ] )
break;
if ( V_8 == V_53 -> V_93 ) {
F_76 ( L_38 ,
F_19 ( V_40 -> V_264 ) ) ;
V_33 = - V_168 ;
goto V_46;
}
V_262 = V_40 -> V_265 << 16 ;
V_263 = V_40 -> V_266 << 16 ;
if ( V_260 -> V_267 > V_262 ||
V_260 -> V_268 > V_262 - V_260 -> V_267 ||
V_260 -> V_269 > V_263 ||
V_260 -> V_270 > V_263 - V_260 -> V_269 ) {
F_76 ( L_39
L_40 ,
V_260 -> V_267 >> 16 ,
( ( V_260 -> V_267 & 0xffff ) * 15625 ) >> 10 ,
V_260 -> V_269 >> 16 ,
( ( V_260 -> V_269 & 0xffff ) * 15625 ) >> 10 ,
V_260 -> V_268 >> 16 ,
( ( V_260 -> V_268 & 0xffff ) * 15625 ) >> 10 ,
V_260 -> V_270 >> 16 ,
( ( V_260 -> V_270 & 0xffff ) * 15625 ) >> 10 ) ;
V_33 = - V_271 ;
goto V_46;
}
if ( V_260 -> V_272 > V_164 ||
V_260 -> V_273 > V_164 - ( V_274 ) V_260 -> V_272 ||
V_260 -> V_275 > V_164 ||
V_260 -> V_276 > V_164 - ( V_274 ) V_260 -> V_275 ) {
F_76 ( L_41 ,
V_260 -> V_272 , V_260 -> V_275 ,
V_260 -> V_273 , V_260 -> V_276 ) ;
V_33 = - V_165 ;
goto V_46;
}
F_1 ( V_2 ) ;
V_33 = V_53 -> V_42 -> V_277 ( V_53 , V_4 , V_40 ,
V_260 -> V_273 , V_260 -> V_276 ,
V_260 -> V_272 , V_260 -> V_275 ,
V_260 -> V_268 , V_260 -> V_270 ,
V_260 -> V_267 , V_260 -> V_269 ) ;
if ( ! V_33 ) {
V_261 = V_53 -> V_40 ;
V_53 -> V_4 = V_4 ;
V_53 -> V_40 = V_40 ;
V_40 = NULL ;
}
F_5 ( V_2 ) ;
V_46:
if ( V_40 )
F_36 ( V_40 ) ;
if ( V_261 )
F_36 ( V_261 ) ;
return V_33 ;
}
int F_50 ( struct V_54 * V_55 )
{
struct V_3 * V_4 = V_55 -> V_4 ;
struct V_39 * V_40 ;
struct V_3 * V_64 ;
int V_33 ;
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_64 -> V_261 = V_64 -> V_40 ;
V_40 = V_55 -> V_40 ;
V_33 = V_4 -> V_42 -> V_278 ( V_55 ) ;
if ( V_33 == 0 ) {
F_8 ( V_40 != V_4 -> V_40 ) ;
}
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_64 -> V_40 )
F_29 ( V_64 -> V_40 ) ;
if ( V_64 -> V_261 )
F_36 ( V_64 -> V_261 ) ;
}
return V_33 ;
}
static int F_111 ( const struct V_3 * V_4 ,
int V_208 , int V_209 ,
const struct V_65 * V_66 ,
const struct V_39 * V_40 )
{
int V_150 , V_156 ;
V_150 = V_66 -> V_150 ;
V_156 = V_66 -> V_156 ;
if ( F_101 ( V_66 ) ) {
struct V_65 V_279 = * V_66 ;
F_112 ( & V_279 , V_280 ) ;
V_150 = V_279 . V_281 ;
V_156 = V_279 . V_282 ;
}
if ( V_4 -> V_57 )
F_113 ( V_150 , V_156 ) ;
if ( V_150 > V_40 -> V_265 ||
V_156 > V_40 -> V_266 ||
V_208 > V_40 -> V_265 - V_150 ||
V_209 > V_40 -> V_266 - V_156 ) {
F_76 ( L_42 ,
V_40 -> V_265 , V_40 -> V_266 , V_150 , V_156 , V_208 , V_209 ,
V_4 -> V_57 ? L_43 : L_44 ) ;
return - V_271 ;
}
return 0 ;
}
int F_114 ( struct V_1 * V_2 , void * V_169 ,
struct V_170 * V_171 )
{
struct V_249 * V_250 = & V_2 -> V_5 ;
struct V_205 * V_283 = V_169 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
struct V_19 * * V_284 = NULL , * V_20 ;
struct V_39 * V_40 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_54 V_55 ;
T_1 T_2 * V_285 ;
int V_33 ;
int V_8 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
if ( V_283 -> V_208 > V_164 || V_283 -> V_209 > V_164 )
return - V_165 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_283 -> V_182 ,
V_58 ) ;
if ( ! V_31 ) {
F_76 ( L_45 , V_283 -> V_182 ) ;
V_33 = - V_207 ;
goto V_46;
}
V_4 = F_99 ( V_31 ) ;
F_76 ( L_30 , V_4 -> V_17 . V_18 ) ;
if ( V_283 -> V_212 ) {
if ( V_283 -> V_181 == - 1 ) {
if ( ! V_4 -> V_40 ) {
F_76 ( L_46 ) ;
V_33 = - V_168 ;
goto V_46;
}
V_40 = V_4 -> V_40 ;
F_29 ( V_40 ) ;
} else {
V_40 = F_35 ( V_2 , V_283 -> V_181 ) ;
if ( ! V_40 ) {
F_76 ( L_47 ,
V_283 -> V_181 ) ;
V_33 = - V_207 ;
goto V_46;
}
}
V_66 = F_78 ( V_2 ) ;
if ( ! V_66 ) {
V_33 = - V_97 ;
goto V_46;
}
V_33 = F_93 ( V_66 , & V_283 -> V_66 ) ;
if ( V_33 ) {
F_76 ( L_48 ) ;
goto V_46;
}
F_112 ( V_66 , V_286 ) ;
V_33 = F_111 ( V_4 , V_283 -> V_208 , V_283 -> V_209 ,
V_66 , V_40 ) ;
if ( V_33 )
goto V_46;
}
if ( V_283 -> V_202 == 0 && V_66 ) {
F_76 ( L_49 ) ;
V_33 = - V_168 ;
goto V_46;
}
if ( V_283 -> V_202 > 0 && ( ! V_66 || ! V_40 ) ) {
F_76 ( L_50 ,
V_283 -> V_202 ) ;
V_33 = - V_168 ;
goto V_46;
}
if ( V_283 -> V_202 > 0 ) {
T_4 V_287 ;
if ( V_283 -> V_202 > V_250 -> V_75 ) {
V_33 = - V_168 ;
goto V_46;
}
V_284 = F_75 ( V_283 -> V_202 *
sizeof( struct V_19 * ) ,
V_36 ) ;
if ( ! V_284 ) {
V_33 = - V_97 ;
goto V_46;
}
for ( V_8 = 0 ; V_8 < V_283 -> V_202 ; V_8 ++ ) {
V_285 = ( T_1 T_2 * ) ( unsigned long ) V_283 -> V_285 ;
if ( F_115 ( V_287 , & V_285 [ V_8 ] ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_31 = F_24 ( V_2 , V_287 ,
V_70 ) ;
if ( ! V_31 ) {
F_76 ( L_51 ,
V_287 ) ;
V_33 = - V_207 ;
goto V_46;
}
V_20 = F_103 ( V_31 ) ;
F_76 ( L_32 ,
V_20 -> V_17 . V_18 ,
F_16 ( V_20 ) ) ;
V_284 [ V_8 ] = V_20 ;
}
}
V_55 . V_4 = V_4 ;
V_55 . V_208 = V_283 -> V_208 ;
V_55 . V_209 = V_283 -> V_209 ;
V_55 . V_66 = V_66 ;
V_55 . V_288 = V_284 ;
V_55 . V_145 = V_283 -> V_202 ;
V_55 . V_40 = V_40 ;
V_33 = F_50 ( & V_55 ) ;
V_46:
if ( V_40 )
F_36 ( V_40 ) ;
F_57 ( V_284 ) ;
F_61 ( V_2 , V_66 ) ;
F_5 ( V_2 ) ;
return V_33 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_289 * V_290 ,
struct V_170 * V_171 )
{
struct V_30 * V_31 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
if ( ! V_290 -> V_162 || ( ~ V_291 & V_290 -> V_162 ) )
return - V_168 ;
V_31 = F_24 ( V_2 , V_290 -> V_182 , V_58 ) ;
if ( ! V_31 ) {
F_76 ( L_45 , V_290 -> V_182 ) ;
return - V_207 ;
}
V_4 = F_99 ( V_31 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_290 -> V_162 & V_292 ) {
if ( ! V_4 -> V_42 -> V_293 && ! V_4 -> V_42 -> V_294 ) {
V_33 = - V_295 ;
goto V_46;
}
if ( V_4 -> V_42 -> V_294 )
V_33 = V_4 -> V_42 -> V_294 ( V_4 , V_171 , V_290 -> V_296 ,
V_290 -> V_265 , V_290 -> V_266 , V_290 -> V_297 , V_290 -> V_298 ) ;
else
V_33 = V_4 -> V_42 -> V_293 ( V_4 , V_171 , V_290 -> V_296 ,
V_290 -> V_265 , V_290 -> V_266 ) ;
}
if ( V_290 -> V_162 & V_299 ) {
if ( V_4 -> V_42 -> V_300 ) {
V_33 = V_4 -> V_42 -> V_300 ( V_4 , V_290 -> V_208 , V_290 -> V_209 ) ;
} else {
V_33 = - V_190 ;
goto V_46;
}
}
V_46:
F_6 ( & V_4 -> V_6 ) ;
return V_33 ;
}
int F_117 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_301 * V_290 = V_169 ;
struct V_289 V_302 ;
memcpy ( & V_302 , V_290 , sizeof( struct V_301 ) ) ;
V_302 . V_297 = V_302 . V_298 = 0 ;
return F_116 ( V_2 , & V_302 , V_171 ) ;
}
int F_118 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_289 * V_290 = V_169 ;
return F_116 ( V_2 , V_290 , V_171 ) ;
}
T_1 F_119 ( T_1 V_303 , T_1 V_304 )
{
T_1 V_305 ;
switch ( V_303 ) {
case 8 :
V_305 = V_306 ;
break;
case 16 :
if ( V_304 == 15 )
V_305 = V_307 ;
else
V_305 = V_308 ;
break;
case 24 :
V_305 = V_309 ;
break;
case 32 :
if ( V_304 == 24 )
V_305 = V_310 ;
else if ( V_304 == 30 )
V_305 = V_311 ;
else
V_305 = V_312 ;
break;
default:
F_51 ( L_52 ) ;
V_305 = V_310 ;
break;
}
return V_305 ;
}
int F_120 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_313 * V_314 = V_169 ;
struct V_315 V_316 = {} ;
struct V_249 * V_250 = & V_2 -> V_5 ;
struct V_39 * V_40 ;
int V_33 = 0 ;
V_316 . V_181 = V_314 -> V_181 ;
V_316 . V_265 = V_314 -> V_265 ;
V_316 . V_266 = V_314 -> V_266 ;
V_316 . V_317 [ 0 ] = V_314 -> V_318 ;
V_316 . V_264 = F_119 ( V_314 -> V_303 , V_314 -> V_304 ) ;
V_316 . V_319 [ 0 ] = V_314 -> V_296 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
if ( ( V_250 -> V_197 > V_316 . V_265 ) || ( V_316 . V_265 > V_250 -> V_196 ) )
return - V_168 ;
if ( ( V_250 -> V_195 > V_316 . V_266 ) || ( V_316 . V_266 > V_250 -> V_194 ) )
return - V_168 ;
V_40 = V_2 -> V_5 . V_42 -> V_320 ( V_2 , V_171 , & V_316 ) ;
if ( F_121 ( V_40 ) ) {
F_76 ( L_53 ) ;
return F_122 ( V_40 ) ;
}
F_2 ( & V_171 -> V_187 ) ;
V_314 -> V_181 = V_40 -> V_17 . V_18 ;
F_30 ( & V_40 -> V_45 , & V_171 -> V_321 ) ;
F_76 ( L_54 , V_40 -> V_17 . V_18 ) ;
F_6 ( & V_171 -> V_187 ) ;
return V_33 ;
}
static int F_123 ( const struct V_315 * V_316 )
{
T_1 V_28 = V_316 -> V_264 & ~ V_29 ;
switch ( V_28 ) {
case V_306 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_307 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_308 :
case V_339 :
case V_309 :
case V_340 :
case V_310 :
case V_341 :
case V_342 :
case V_343 :
case V_312 :
case V_344 :
case V_345 :
case V_346 :
case V_311 :
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
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
return 0 ;
default:
F_76 ( L_55 ,
F_19 ( V_316 -> V_264 ) ) ;
return - V_168 ;
}
}
static int F_124 ( const struct V_315 * V_316 )
{
int V_33 , V_375 , V_376 , V_377 , V_8 ;
V_33 = F_123 ( V_316 ) ;
if ( V_33 ) {
F_76 ( L_56 ,
F_19 ( V_316 -> V_264 ) ) ;
return V_33 ;
}
V_375 = F_125 ( V_316 -> V_264 ) ;
V_376 = F_126 ( V_316 -> V_264 ) ;
V_377 = F_127 ( V_316 -> V_264 ) ;
if ( V_316 -> V_265 == 0 || V_316 -> V_265 % V_375 ) {
F_76 ( L_57 , V_316 -> V_266 ) ;
return - V_168 ;
}
if ( V_316 -> V_266 == 0 || V_316 -> V_266 % V_376 ) {
F_76 ( L_58 , V_316 -> V_266 ) ;
return - V_168 ;
}
for ( V_8 = 0 ; V_8 < V_377 ; V_8 ++ ) {
unsigned int V_265 = V_316 -> V_265 / ( V_8 != 0 ? V_375 : 1 ) ;
unsigned int V_266 = V_316 -> V_266 / ( V_8 != 0 ? V_376 : 1 ) ;
unsigned int V_378 = F_128 ( V_316 -> V_264 , V_8 ) ;
if ( ! V_316 -> V_319 [ V_8 ] ) {
F_76 ( L_59 , V_8 ) ;
return - V_168 ;
}
if ( ( T_3 ) V_265 * V_378 > V_379 )
return - V_165 ;
if ( ( T_3 ) V_266 * V_316 -> V_317 [ V_8 ] + V_316 -> V_380 [ V_8 ] > V_379 )
return - V_165 ;
if ( V_316 -> V_317 [ V_8 ] < V_265 * V_378 ) {
F_76 ( L_60 , V_316 -> V_317 [ V_8 ] , V_8 ) ;
return - V_168 ;
}
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_315 * V_316 = V_169 ;
struct V_249 * V_250 = & V_2 -> V_5 ;
struct V_39 * V_40 ;
int V_33 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
if ( V_316 -> V_162 & ~ V_381 ) {
F_76 ( L_61 , V_316 -> V_162 ) ;
return - V_168 ;
}
if ( ( V_250 -> V_197 > V_316 -> V_265 ) || ( V_316 -> V_265 > V_250 -> V_196 ) ) {
F_76 ( L_62 ,
V_316 -> V_265 , V_250 -> V_197 , V_250 -> V_196 ) ;
return - V_168 ;
}
if ( ( V_250 -> V_195 > V_316 -> V_266 ) || ( V_316 -> V_266 > V_250 -> V_194 ) ) {
F_76 ( L_63 ,
V_316 -> V_266 , V_250 -> V_195 , V_250 -> V_194 ) ;
return - V_168 ;
}
V_33 = F_124 ( V_316 ) ;
if ( V_33 )
return V_33 ;
V_40 = V_2 -> V_5 . V_42 -> V_320 ( V_2 , V_171 , V_316 ) ;
if ( F_121 ( V_40 ) ) {
F_76 ( L_53 ) ;
return F_122 ( V_40 ) ;
}
F_2 ( & V_171 -> V_187 ) ;
V_316 -> V_181 = V_40 -> V_17 . V_18 ;
F_30 ( & V_40 -> V_45 , & V_171 -> V_321 ) ;
F_76 ( L_54 , V_40 -> V_17 . V_18 ) ;
F_6 ( & V_171 -> V_187 ) ;
return V_33 ;
}
int F_130 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_39 * V_40 = NULL ;
struct V_39 * V_382 = NULL ;
T_1 * V_18 = V_169 ;
int V_383 = 0 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_2 ( & V_171 -> V_187 ) ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
V_40 = F_33 ( V_2 , * V_18 ) ;
if ( ! V_40 )
goto V_384;
F_3 (fbl, &file_priv->fbs, filp_head)
if ( V_40 == V_382 )
V_383 = 1 ;
if ( ! V_383 )
goto V_384;
F_43 ( V_2 , V_40 ) ;
F_131 ( & V_40 -> V_45 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
F_6 ( & V_171 -> V_187 ) ;
F_47 ( V_40 ) ;
return 0 ;
V_384:
F_6 ( & V_2 -> V_5 . V_43 ) ;
F_6 ( & V_171 -> V_187 ) ;
return - V_207 ;
}
int F_132 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_313 * V_316 = V_169 ;
struct V_39 * V_40 ;
int V_33 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
V_40 = F_35 ( V_2 , V_316 -> V_181 ) ;
if ( ! V_40 )
return - V_207 ;
V_316 -> V_266 = V_40 -> V_266 ;
V_316 -> V_265 = V_40 -> V_265 ;
V_316 -> V_304 = V_40 -> V_304 ;
V_316 -> V_303 = V_40 -> V_385 ;
V_316 -> V_318 = V_40 -> V_317 [ 0 ] ;
if ( V_40 -> V_42 -> V_386 ) {
if ( V_171 -> V_387 || F_133 ( V_388 ) ) {
V_33 = V_40 -> V_42 -> V_386 ( V_40 , V_171 ,
& V_316 -> V_296 ) ;
} else {
V_316 -> V_296 = 0 ;
V_33 = 0 ;
}
} else {
V_33 = - V_389 ;
}
F_36 ( V_40 ) ;
return V_33 ;
}
int F_134 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_390 T_2 * V_391 ;
struct V_390 * V_392 = NULL ;
struct V_393 * V_316 = V_169 ;
struct V_39 * V_40 ;
unsigned V_162 ;
int V_394 ;
int V_33 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
V_40 = F_35 ( V_2 , V_316 -> V_181 ) ;
if ( ! V_40 )
return - V_207 ;
V_394 = V_316 -> V_394 ;
V_391 = (struct V_390 T_2 * ) ( unsigned long ) V_316 -> V_391 ;
if ( ! V_394 != ! V_391 ) {
V_33 = - V_168 ;
goto V_395;
}
V_162 = V_396 & V_316 -> V_162 ;
if ( V_162 & V_397 && ( V_394 % 2 ) ) {
V_33 = - V_168 ;
goto V_395;
}
if ( V_394 && V_391 ) {
if ( V_394 < 0 || V_394 > V_398 ) {
V_33 = - V_168 ;
goto V_395;
}
V_392 = F_79 ( V_394 * sizeof( * V_392 ) , V_36 ) ;
if ( ! V_392 ) {
V_33 = - V_97 ;
goto V_395;
}
V_33 = F_135 ( V_392 , V_391 ,
V_394 * sizeof( * V_392 ) ) ;
if ( V_33 ) {
V_33 = - V_190 ;
goto V_399;
}
}
if ( V_40 -> V_42 -> V_400 ) {
V_33 = V_40 -> V_42 -> V_400 ( V_40 , V_171 , V_162 , V_316 -> V_401 ,
V_392 , V_394 ) ;
} else {
V_33 = - V_402 ;
}
V_399:
F_57 ( V_392 ) ;
V_395:
F_36 ( V_40 ) ;
return V_33 ;
}
void F_136 ( struct V_170 * V_94 )
{
struct V_1 * V_2 = V_94 -> V_192 -> V_2 ;
struct V_39 * V_40 , * V_403 ;
F_2 ( & V_94 -> V_187 ) ;
F_66 (fb, tfb, &priv->fbs, filp_head) {
F_2 ( & V_2 -> V_5 . V_43 ) ;
F_43 ( V_2 , V_40 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
F_131 ( & V_40 -> V_45 ) ;
F_47 ( V_40 ) ;
}
F_6 ( & V_94 -> V_187 ) ;
}
struct V_103 * F_81 ( struct V_1 * V_2 , int V_162 ,
const char * V_16 , int V_404 )
{
struct V_103 * V_405 = NULL ;
int V_33 ;
V_405 = F_79 ( sizeof( struct V_103 ) , V_36 ) ;
if ( ! V_405 )
return NULL ;
if ( V_404 ) {
V_405 -> V_242 = F_79 ( sizeof( T_3 ) * V_404 , V_36 ) ;
if ( ! V_405 -> V_242 )
goto V_406;
}
V_33 = F_20 ( V_2 , & V_405 -> V_17 , V_407 ) ;
if ( V_33 )
goto V_406;
V_405 -> V_162 = V_162 ;
V_405 -> V_404 = V_404 ;
F_28 ( & V_405 -> V_408 ) ;
if ( V_16 ) {
strncpy ( V_405 -> V_16 , V_16 , V_409 ) ;
V_405 -> V_16 [ V_409 - 1 ] = '\0' ;
}
F_55 ( & V_405 -> V_48 , & V_2 -> V_5 . V_410 ) ;
return V_405 ;
V_406:
F_57 ( V_405 -> V_242 ) ;
F_57 ( V_405 ) ;
return NULL ;
}
struct V_103 * F_82 ( struct V_1 * V_2 , int V_162 ,
const char * V_16 ,
const struct V_411 * V_412 ,
int V_404 )
{
struct V_103 * V_405 ;
int V_8 , V_33 ;
V_162 |= V_127 ;
V_405 = F_81 ( V_2 , V_162 , V_16 , V_404 ) ;
if ( ! V_405 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_404 ; V_8 ++ ) {
V_33 = F_86 ( V_405 , V_8 ,
V_412 [ V_8 ] . type ,
V_412 [ V_8 ] . V_16 ) ;
if ( V_33 ) {
F_137 ( V_2 , V_405 ) ;
return NULL ;
}
}
return V_405 ;
}
struct V_103 * F_138 ( struct V_1 * V_2 ,
int V_162 , const char * V_16 ,
const struct V_411 * V_412 ,
int V_404 )
{
struct V_103 * V_405 ;
int V_8 , V_33 ;
V_162 |= V_413 ;
V_405 = F_81 ( V_2 , V_162 , V_16 , V_404 ) ;
if ( ! V_405 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_404 ; V_8 ++ ) {
V_33 = F_86 ( V_405 , V_8 ,
V_412 [ V_8 ] . type ,
V_412 [ V_8 ] . V_16 ) ;
if ( V_33 ) {
F_137 ( V_2 , V_405 ) ;
return NULL ;
}
}
return V_405 ;
}
struct V_103 * F_85 ( struct V_1 * V_2 , int V_162 ,
const char * V_16 ,
T_3 V_414 , T_3 V_415 )
{
struct V_103 * V_405 ;
V_162 |= V_416 ;
V_405 = F_81 ( V_2 , V_162 , V_16 , 2 ) ;
if ( ! V_405 )
return NULL ;
V_405 -> V_242 [ 0 ] = V_414 ;
V_405 -> V_242 [ 1 ] = V_415 ;
return V_405 ;
}
int F_86 ( struct V_103 * V_405 , int V_63 ,
T_3 V_417 , const char * V_16 )
{
struct V_418 * V_419 ;
if ( ! ( V_405 -> V_162 & ( V_127 | V_413 ) ) )
return - V_168 ;
if ( ( V_405 -> V_162 & V_413 ) && ( V_417 > 63 ) )
return - V_168 ;
if ( ! F_48 ( & V_405 -> V_408 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( V_419 -> V_417 == V_417 ) {
strncpy ( V_419 -> V_16 , V_16 , V_409 ) ;
V_419 -> V_16 [ V_409 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_419 = F_79 ( sizeof( struct V_418 ) , V_36 ) ;
if ( ! V_419 )
return - V_97 ;
strncpy ( V_419 -> V_16 , V_16 , V_409 ) ;
V_419 -> V_16 [ V_409 - 1 ] = '\0' ;
V_419 -> V_417 = V_417 ;
V_405 -> V_242 [ V_63 ] = V_417 ;
F_55 ( & V_419 -> V_48 , & V_405 -> V_408 ) ;
return 0 ;
}
void F_137 ( struct V_1 * V_2 , struct V_103 * V_405 )
{
struct V_418 * V_419 , * V_420 ;
F_66 (prop_enum, pt, &property->enum_blob_list, head) {
F_46 ( & V_419 -> V_48 ) ;
F_57 ( V_419 ) ;
}
if ( V_405 -> V_404 )
F_57 ( V_405 -> V_242 ) ;
F_22 ( V_2 , & V_405 -> V_17 ) ;
F_46 ( & V_405 -> V_48 ) ;
F_57 ( V_405 ) ;
}
void F_64 ( struct V_30 * V_31 ,
struct V_103 * V_405 ,
T_3 V_421 )
{
int V_224 = V_31 -> V_59 -> V_224 ;
if ( V_224 == V_422 ) {
F_92 ( 1 , L_64
L_65
L_66 ,
V_31 -> type ) ;
return;
}
V_31 -> V_59 -> V_241 [ V_224 ] = V_405 -> V_17 . V_18 ;
V_31 -> V_59 -> V_242 [ V_224 ] = V_421 ;
V_31 -> V_59 -> V_224 ++ ;
}
int F_139 ( struct V_30 * V_31 ,
struct V_103 * V_405 , T_3 V_423 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 -> V_59 -> V_224 ; V_8 ++ ) {
if ( V_31 -> V_59 -> V_241 [ V_8 ] == V_405 -> V_17 . V_18 ) {
V_31 -> V_59 -> V_242 [ V_8 ] = V_423 ;
return 0 ;
}
}
return - V_168 ;
}
int F_140 ( struct V_30 * V_31 ,
struct V_103 * V_405 , T_3 * V_423 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 -> V_59 -> V_224 ; V_8 ++ ) {
if ( V_31 -> V_59 -> V_241 [ V_8 ] == V_405 -> V_17 . V_18 ) {
* V_423 = V_31 -> V_59 -> V_242 [ V_8 ] ;
return 0 ;
}
}
return - V_168 ;
}
int F_141 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_30 * V_31 ;
struct V_424 * V_215 = V_169 ;
struct V_103 * V_405 ;
int V_425 = 0 ;
int V_426 = 0 ;
int V_427 = 0 ;
int V_33 = 0 , V_8 ;
int V_180 ;
struct V_418 * V_419 ;
struct V_428 T_2 * V_429 ;
struct V_430 * V_431 ;
T_1 T_2 * V_432 ;
T_3 T_2 * V_433 ;
T_1 T_2 * V_434 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_215 -> V_435 , V_407 ) ;
if ( ! V_31 ) {
V_33 = - V_207 ;
goto V_436;
}
V_405 = F_142 ( V_31 ) ;
if ( V_405 -> V_162 & ( V_127 | V_413 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head)
V_425 ++ ;
} else if ( V_405 -> V_162 & V_106 ) {
F_3 (prop_blob, &property->enum_blob_list, head)
V_426 ++ ;
}
V_427 = V_405 -> V_404 ;
strncpy ( V_215 -> V_16 , V_405 -> V_16 , V_409 ) ;
V_215 -> V_16 [ V_409 - 1 ] = 0 ;
V_215 -> V_162 = V_405 -> V_162 ;
if ( ( V_215 -> V_437 >= V_427 ) && V_427 ) {
V_433 = ( T_3 T_2 * ) ( unsigned long ) V_215 -> V_433 ;
for ( V_8 = 0 ; V_8 < V_427 ; V_8 ++ ) {
if ( F_104 ( V_433 + V_8 , & V_405 -> V_242 [ V_8 ] , sizeof( T_3 ) ) ) {
V_33 = - V_190 ;
goto V_436;
}
}
}
V_215 -> V_437 = V_427 ;
if ( V_405 -> V_162 & ( V_127 | V_413 ) ) {
if ( ( V_215 -> V_438 >= V_425 ) && V_425 ) {
V_180 = 0 ;
V_429 = (struct V_428 T_2 * ) ( unsigned long ) V_215 -> V_439 ;
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( F_104 ( & V_429 [ V_180 ] . V_417 , & V_419 -> V_417 , sizeof( T_3 ) ) ) {
V_33 = - V_190 ;
goto V_436;
}
if ( F_104 ( & V_429 [ V_180 ] . V_16 ,
& V_419 -> V_16 , V_409 ) ) {
V_33 = - V_190 ;
goto V_436;
}
V_180 ++ ;
}
}
V_215 -> V_438 = V_425 ;
}
if ( V_405 -> V_162 & V_106 ) {
if ( ( V_215 -> V_438 >= V_426 ) && V_426 ) {
V_180 = 0 ;
V_432 = ( T_1 T_2 * ) ( unsigned long ) V_215 -> V_439 ;
V_434 = ( T_1 T_2 * ) ( unsigned long ) V_215 -> V_433 ;
F_3 (prop_blob, &property->enum_blob_list, head) {
if ( F_97 ( V_431 -> V_17 . V_18 , V_432 + V_180 ) ) {
V_33 = - V_190 ;
goto V_436;
}
if ( F_97 ( V_431 -> V_440 , V_434 + V_180 ) ) {
V_33 = - V_190 ;
goto V_436;
}
V_180 ++ ;
}
}
V_215 -> V_438 = V_426 ;
}
V_436:
F_5 ( V_2 ) ;
return V_33 ;
}
static struct V_430 * F_143 ( struct V_1 * V_2 , int V_440 ,
void * V_169 )
{
struct V_430 * V_441 ;
int V_33 ;
if ( ! V_440 || ! V_169 )
return NULL ;
V_441 = F_79 ( sizeof( struct V_430 ) + V_440 , V_36 ) ;
if ( ! V_441 )
return NULL ;
V_33 = F_20 ( V_2 , & V_441 -> V_17 , V_442 ) ;
if ( V_33 ) {
F_57 ( V_441 ) ;
return NULL ;
}
V_441 -> V_440 = V_440 ;
memcpy ( V_441 -> V_169 , V_169 , V_440 ) ;
F_55 ( & V_441 -> V_48 , & V_2 -> V_5 . V_443 ) ;
return V_441 ;
}
static void F_144 ( struct V_1 * V_2 ,
struct V_430 * V_441 )
{
F_22 ( V_2 , & V_441 -> V_17 ) ;
F_46 ( & V_441 -> V_48 ) ;
F_57 ( V_441 ) ;
}
int F_145 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_30 * V_31 ;
struct V_444 * V_215 = V_169 ;
struct V_430 * V_441 ;
int V_33 = 0 ;
void T_2 * V_445 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_215 -> V_446 , V_442 ) ;
if ( ! V_31 ) {
V_33 = - V_207 ;
goto V_436;
}
V_441 = F_146 ( V_31 ) ;
if ( V_215 -> V_440 == V_441 -> V_440 ) {
V_445 = ( void T_2 * ) ( unsigned long ) V_215 -> V_169 ;
if ( F_104 ( V_445 , V_441 -> V_169 , V_441 -> V_440 ) ) {
V_33 = - V_190 ;
goto V_436;
}
}
V_215 -> V_440 = V_441 -> V_440 ;
V_436:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_147 ( struct V_19 * V_20 ,
struct V_104 * V_104 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_33 , V_447 ;
if ( V_20 -> V_72 )
F_144 ( V_2 , V_20 -> V_72 ) ;
if ( ! V_104 ) {
V_20 -> V_72 = NULL ;
V_33 = F_139 ( & V_20 -> V_17 , V_2 -> V_5 . V_77 , 0 ) ;
return V_33 ;
}
V_447 = V_448 * ( 1 + V_104 -> V_449 ) ;
V_20 -> V_72 = F_143 ( V_20 -> V_2 ,
V_447 , V_104 ) ;
if ( ! V_20 -> V_72 )
return - V_168 ;
V_33 = F_139 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_77 ,
V_20 -> V_72 -> V_17 . V_18 ) ;
return V_33 ;
}
static bool F_148 ( struct V_103 * V_405 ,
T_3 V_417 )
{
if ( V_405 -> V_162 & V_107 )
return false ;
if ( V_405 -> V_162 & V_416 ) {
if ( V_417 < V_405 -> V_242 [ 0 ] || V_417 > V_405 -> V_242 [ 1 ] )
return false ;
return true ;
} else if ( V_405 -> V_162 & V_413 ) {
int V_8 ;
T_3 V_450 = 0 ;
for ( V_8 = 0 ; V_8 < V_405 -> V_404 ; V_8 ++ )
V_450 |= ( 1ULL << V_405 -> V_242 [ V_8 ] ) ;
return ! ( V_417 & ~ V_450 ) ;
} else if ( V_405 -> V_162 & V_106 ) {
return true ;
} else {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_405 -> V_404 ; V_8 ++ )
if ( V_405 -> V_242 [ V_8 ] == V_417 )
return true ;
return false ;
}
}
int F_149 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_451 * V_452 = V_169 ;
struct V_453 V_454 = {
. V_417 = V_452 -> V_417 ,
. V_435 = V_452 -> V_435 ,
. V_455 = V_452 -> V_183 ,
. V_32 = V_70
} ;
return F_150 ( V_2 , & V_454 , V_171 ) ;
}
static int F_151 ( struct V_30 * V_31 ,
struct V_103 * V_405 ,
T_3 V_417 )
{
int V_33 = - V_168 ;
struct V_19 * V_20 = F_103 ( V_31 ) ;
if ( V_405 == V_20 -> V_2 -> V_5 . V_78 ) {
if ( V_20 -> V_42 -> V_105 )
(* V_20 -> V_42 -> V_105 )( V_20 , ( int ) V_417 ) ;
V_33 = 0 ;
} else if ( V_20 -> V_42 -> V_456 )
V_33 = V_20 -> V_42 -> V_456 ( V_20 , V_405 , V_417 ) ;
if ( ! V_33 )
F_139 ( & V_20 -> V_17 , V_405 , V_417 ) ;
return V_33 ;
}
static int F_152 ( struct V_30 * V_31 ,
struct V_103 * V_405 ,
T_3 V_417 )
{
int V_33 = - V_168 ;
struct V_3 * V_4 = F_99 ( V_31 ) ;
if ( V_4 -> V_42 -> V_456 )
V_33 = V_4 -> V_42 -> V_456 ( V_4 , V_405 , V_417 ) ;
if ( ! V_33 )
F_139 ( V_31 , V_405 , V_417 ) ;
return V_33 ;
}
static int F_153 ( struct V_30 * V_31 ,
struct V_103 * V_405 ,
T_3 V_417 )
{
int V_33 = - V_168 ;
struct V_52 * V_53 = F_109 ( V_31 ) ;
if ( V_53 -> V_42 -> V_456 )
V_33 = V_53 -> V_42 -> V_456 ( V_53 , V_405 , V_417 ) ;
if ( ! V_33 )
F_139 ( V_31 , V_405 , V_417 ) ;
return V_33 ;
}
int F_154 ( struct V_1 * V_2 , void * V_169 ,
struct V_170 * V_171 )
{
struct V_457 * V_458 = V_169 ;
struct V_30 * V_31 ;
int V_33 = 0 ;
int V_8 ;
int V_180 = 0 ;
int V_217 = 0 ;
T_1 T_2 * V_239 ;
T_3 T_2 * V_240 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_458 -> V_455 , V_458 -> V_32 ) ;
if ( ! V_31 ) {
V_33 = - V_207 ;
goto V_46;
}
if ( ! V_31 -> V_59 ) {
V_33 = - V_168 ;
goto V_46;
}
V_217 = V_31 -> V_59 -> V_224 ;
if ( ( V_458 -> V_238 >= V_217 ) && V_217 ) {
V_180 = 0 ;
V_239 = ( T_1 T_2 * ) ( unsigned long ) ( V_458 -> V_239 ) ;
V_240 = ( T_3 T_2 * ) ( unsigned long )
( V_458 -> V_240 ) ;
for ( V_8 = 0 ; V_8 < V_217 ; V_8 ++ ) {
if ( F_97 ( V_31 -> V_59 -> V_241 [ V_8 ] ,
V_239 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
if ( F_97 ( V_31 -> V_59 -> V_242 [ V_8 ] ,
V_240 + V_180 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_180 ++ ;
}
}
V_458 -> V_238 = V_217 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_150 ( struct V_1 * V_2 , void * V_169 ,
struct V_170 * V_171 )
{
struct V_453 * V_458 = V_169 ;
struct V_30 * V_459 ;
struct V_30 * V_460 ;
struct V_103 * V_405 ;
int V_33 = - V_168 ;
int V_8 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_459 = F_24 ( V_2 , V_458 -> V_455 , V_458 -> V_32 ) ;
if ( ! V_459 ) {
V_33 = - V_207 ;
goto V_46;
}
if ( ! V_459 -> V_59 )
goto V_46;
for ( V_8 = 0 ; V_8 < V_459 -> V_59 -> V_224 ; V_8 ++ )
if ( V_459 -> V_59 -> V_241 [ V_8 ] == V_458 -> V_435 )
break;
if ( V_8 == V_459 -> V_59 -> V_224 )
goto V_46;
V_460 = F_24 ( V_2 , V_458 -> V_435 ,
V_407 ) ;
if ( ! V_460 ) {
V_33 = - V_207 ;
goto V_46;
}
V_405 = F_142 ( V_460 ) ;
if ( ! F_148 ( V_405 , V_458 -> V_417 ) )
goto V_46;
switch ( V_459 -> type ) {
case V_70 :
V_33 = F_151 ( V_459 , V_405 ,
V_458 -> V_417 ) ;
break;
case V_58 :
V_33 = F_152 ( V_459 , V_405 , V_458 -> V_417 ) ;
break;
case V_95 :
V_33 = F_153 ( V_459 , V_405 , V_458 -> V_417 ) ;
break;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_155 ( struct V_19 * V_20 ,
struct V_11 * V_12 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_225 ; V_8 ++ ) {
if ( V_20 -> V_226 [ V_8 ] == 0 ) {
V_20 -> V_226 [ V_8 ] = V_12 -> V_17 . V_18 ;
return 0 ;
}
}
return - V_97 ;
}
void F_156 ( struct V_19 * V_20 ,
struct V_11 * V_12 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_225 ; V_8 ++ ) {
if ( V_20 -> V_226 [ V_8 ] == V_12 -> V_17 . V_18 ) {
V_20 -> V_226 [ V_8 ] = 0 ;
if ( V_20 -> V_12 == V_12 )
V_20 -> V_12 = NULL ;
break;
}
}
}
int F_157 ( struct V_3 * V_4 ,
int V_210 )
{
V_4 -> V_210 = V_210 ;
V_4 -> V_62 = F_79 ( V_210 * sizeof( V_461 ) * 3 , V_36 ) ;
if ( ! V_4 -> V_62 ) {
V_4 -> V_210 = 0 ;
return - V_97 ;
}
return 0 ;
}
int F_158 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_462 * V_463 = V_169 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
void * V_464 , * V_465 , * V_466 ;
int V_447 ;
int V_33 = 0 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_463 -> V_182 , V_58 ) ;
if ( ! V_31 ) {
V_33 = - V_207 ;
goto V_46;
}
V_4 = F_99 ( V_31 ) ;
if ( V_4 -> V_42 -> V_467 == NULL ) {
V_33 = - V_402 ;
goto V_46;
}
if ( V_463 -> V_210 != V_4 -> V_210 ) {
V_33 = - V_168 ;
goto V_46;
}
V_447 = V_463 -> V_210 * ( sizeof( V_461 ) ) ;
V_464 = V_4 -> V_62 ;
if ( F_135 ( V_464 , ( void T_2 * ) ( unsigned long ) V_463 -> V_468 , V_447 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_465 = V_464 + V_447 ;
if ( F_135 ( V_465 , ( void T_2 * ) ( unsigned long ) V_463 -> V_469 , V_447 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_466 = V_465 + V_447 ;
if ( F_135 ( V_466 , ( void T_2 * ) ( unsigned long ) V_463 -> V_470 , V_447 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_4 -> V_42 -> V_467 ( V_4 , V_464 , V_465 , V_466 , 0 , V_4 -> V_210 ) ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_159 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_462 * V_463 = V_169 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
void * V_464 , * V_465 , * V_466 ;
int V_447 ;
int V_33 = 0 ;
if ( ! F_95 ( V_2 , V_186 ) )
return - V_168 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_463 -> V_182 , V_58 ) ;
if ( ! V_31 ) {
V_33 = - V_207 ;
goto V_46;
}
V_4 = F_99 ( V_31 ) ;
if ( V_463 -> V_210 != V_4 -> V_210 ) {
V_33 = - V_168 ;
goto V_46;
}
V_447 = V_463 -> V_210 * ( sizeof( V_461 ) ) ;
V_464 = V_4 -> V_62 ;
if ( F_104 ( ( void T_2 * ) ( unsigned long ) V_463 -> V_468 , V_464 , V_447 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_465 = V_464 + V_447 ;
if ( F_104 ( ( void T_2 * ) ( unsigned long ) V_463 -> V_469 , V_465 , V_447 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_466 = V_465 + V_447 ;
if ( F_104 ( ( void T_2 * ) ( unsigned long ) V_463 -> V_470 , V_466 , V_447 ) ) {
V_33 = - V_190 ;
goto V_46;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_160 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_471 * V_472 = V_169 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
struct V_39 * V_40 = NULL , * V_261 = NULL ;
struct V_473 * V_474 = NULL ;
unsigned long V_162 ;
int V_33 = - V_168 ;
if ( V_472 -> V_162 & ~ V_475 ||
V_472 -> V_476 != 0 )
return - V_168 ;
if ( ( V_472 -> V_162 & V_477 ) && ! V_2 -> V_5 . V_478 )
return - V_168 ;
V_31 = F_24 ( V_2 , V_472 -> V_182 , V_58 ) ;
if ( ! V_31 )
return - V_207 ;
V_4 = F_99 ( V_31 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_40 == NULL ) {
V_33 = - V_479 ;
goto V_46;
}
if ( V_4 -> V_42 -> V_472 == NULL )
goto V_46;
V_40 = F_35 ( V_2 , V_472 -> V_181 ) ;
if ( ! V_40 ) {
V_33 = - V_207 ;
goto V_46;
}
V_33 = F_111 ( V_4 , V_4 -> V_208 , V_4 -> V_209 , & V_4 -> V_66 , V_40 ) ;
if ( V_33 )
goto V_46;
if ( V_4 -> V_40 -> V_264 != V_40 -> V_264 ) {
F_76 ( L_67 ) ;
V_33 = - V_168 ;
goto V_46;
}
if ( V_472 -> V_162 & V_480 ) {
V_33 = - V_97 ;
F_161 ( & V_2 -> V_481 , V_162 ) ;
if ( V_171 -> V_482 < sizeof V_474 -> V_483 ) {
F_162 ( & V_2 -> V_481 , V_162 ) ;
goto V_46;
}
V_171 -> V_482 -= sizeof V_474 -> V_483 ;
F_162 ( & V_2 -> V_481 , V_162 ) ;
V_474 = F_79 ( sizeof *V_474 , V_36 ) ;
if ( V_474 == NULL ) {
F_161 ( & V_2 -> V_481 , V_162 ) ;
V_171 -> V_482 += sizeof V_474 -> V_483 ;
F_162 ( & V_2 -> V_481 , V_162 ) ;
goto V_46;
}
V_474 -> V_483 . V_17 . type = V_484 ;
V_474 -> V_483 . V_17 . V_440 = sizeof V_474 -> V_483 ;
V_474 -> V_483 . V_485 = V_472 -> V_485 ;
V_474 -> V_17 . V_483 = & V_474 -> V_483 . V_17 ;
V_474 -> V_17 . V_171 = V_171 ;
V_474 -> V_17 . V_51 =
( void ( * ) ( struct V_486 * ) ) F_57 ;
}
V_261 = V_4 -> V_40 ;
V_33 = V_4 -> V_42 -> V_472 ( V_4 , V_40 , V_474 , V_472 -> V_162 ) ;
if ( V_33 ) {
if ( V_472 -> V_162 & V_480 ) {
F_161 ( & V_2 -> V_481 , V_162 ) ;
V_171 -> V_482 += sizeof V_474 -> V_483 ;
F_162 ( & V_2 -> V_481 , V_162 ) ;
F_57 ( V_474 ) ;
}
V_261 = NULL ;
} else {
F_8 ( V_4 -> V_40 != V_40 ) ;
V_40 = NULL ;
}
V_46:
if ( V_40 )
F_36 ( V_40 ) ;
if ( V_261 )
F_36 ( V_261 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_33 ;
}
void F_163 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_19 * V_20 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
if ( V_4 -> V_42 -> V_487 )
V_4 -> V_42 -> V_487 ( V_4 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
if ( V_12 -> V_42 -> V_487 )
V_12 -> V_42 -> V_487 ( V_12 ) ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_20 -> V_24 = V_73 ;
if ( V_20 -> V_42 -> V_487 )
V_20 -> V_42 -> V_487 ( V_20 ) ;
}
}
int F_164 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_488 * args = V_169 ;
if ( ! V_2 -> V_489 -> V_490 )
return - V_402 ;
return V_2 -> V_489 -> V_490 ( V_171 , V_2 , args ) ;
}
int F_165 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_491 * args = V_169 ;
if ( ! V_2 -> V_489 -> V_492 )
return - V_402 ;
return V_2 -> V_489 -> V_492 ( V_171 , V_2 , args -> V_296 , & args -> V_493 ) ;
}
int F_166 ( struct V_1 * V_2 ,
void * V_169 , struct V_170 * V_171 )
{
struct V_494 * args = V_169 ;
if ( ! V_2 -> V_489 -> V_495 )
return - V_402 ;
return V_2 -> V_489 -> V_495 ( V_171 , V_2 , args -> V_296 ) ;
}
void F_167 ( T_1 V_28 , unsigned int * V_304 ,
int * V_303 )
{
switch ( V_28 ) {
case V_306 :
case V_322 :
case V_323 :
* V_304 = 8 ;
* V_303 = 8 ;
break;
case V_307 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
* V_304 = 15 ;
* V_303 = 16 ;
break;
case V_308 :
case V_339 :
* V_304 = 16 ;
* V_303 = 16 ;
break;
case V_309 :
case V_340 :
* V_304 = 24 ;
* V_303 = 24 ;
break;
case V_310 :
case V_341 :
case V_342 :
case V_343 :
* V_304 = 24 ;
* V_303 = 32 ;
break;
case V_311 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
* V_304 = 30 ;
* V_303 = 32 ;
break;
case V_312 :
case V_344 :
case V_345 :
case V_346 :
* V_304 = 32 ;
* V_303 = 32 ;
break;
default:
F_76 ( L_68 ,
F_19 ( V_28 ) ) ;
* V_304 = 0 ;
* V_303 = 0 ;
break;
}
}
int F_127 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
return 3 ;
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
return 2 ;
default:
return 1 ;
}
}
int F_128 ( T_1 V_28 , int V_53 )
{
unsigned int V_304 ;
int V_303 ;
if ( V_53 >= F_127 ( V_28 ) )
return 0 ;
switch ( V_28 ) {
case V_354 :
case V_355 :
case V_356 :
case V_357 :
return 2 ;
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
return V_53 ? 2 : 1 ;
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
return 1 ;
default:
F_167 ( V_28 , & V_304 , & V_303 ) ;
return V_303 >> 3 ;
}
}
int F_125 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_367 :
case V_368 :
case V_365 :
case V_366 :
return 4 ;
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_371 :
case V_372 :
case V_369 :
case V_370 :
return 2 ;
default:
return 1 ;
}
}
int F_126 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_365 :
case V_366 :
return 4 ;
case V_369 :
case V_370 :
case V_359 :
case V_360 :
return 2 ;
default:
return 1 ;
}
}
void F_168 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_5 . V_6 ) ;
F_54 ( & V_2 -> V_5 . V_34 ) ;
F_54 ( & V_2 -> V_5 . V_43 ) ;
F_28 ( & V_2 -> V_5 . V_49 ) ;
F_28 ( & V_2 -> V_5 . V_60 ) ;
F_28 ( & V_2 -> V_5 . V_74 ) ;
F_28 ( & V_2 -> V_5 . V_84 ) ;
F_28 ( & V_2 -> V_5 . V_88 ) ;
F_28 ( & V_2 -> V_5 . V_410 ) ;
F_28 ( & V_2 -> V_5 . V_443 ) ;
F_28 ( & V_2 -> V_5 . V_98 ) ;
F_169 ( & V_2 -> V_5 . V_35 ) ;
F_1 ( V_2 ) ;
F_80 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_5 . V_47 = 0 ;
V_2 -> V_5 . V_75 = 0 ;
V_2 -> V_5 . V_61 = 0 ;
V_2 -> V_5 . V_89 = 0 ;
}
void F_170 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_496 ;
struct V_3 * V_4 , * V_497 ;
struct V_11 * V_12 , * V_498 ;
struct V_80 * V_81 , * V_499 ;
struct V_39 * V_40 , * V_500 ;
struct V_103 * V_405 , * V_420 ;
struct V_430 * V_441 , * V_501 ;
struct V_52 * V_53 , * V_502 ;
F_66 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_12 -> V_42 -> V_51 ( V_12 ) ;
}
F_66 (bridge, brt,
&dev->mode_config.bridge_list, head) {
V_81 -> V_42 -> V_51 ( V_81 ) ;
}
F_66 (connector, ot,
&dev->mode_config.connector_list, head) {
V_20 -> V_42 -> V_51 ( V_20 ) ;
}
F_66 (property, pt, &dev->mode_config.property_list,
head) {
F_137 ( V_2 , V_405 ) ;
}
F_66 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_144 ( V_2 , V_441 ) ;
}
F_8 ( ! F_48 ( & V_2 -> V_5 . V_49 ) ) ;
F_66 (fb, fbt, &dev->mode_config.fb_list, head) {
F_47 ( V_40 ) ;
}
F_66 (plane, plt, &dev->mode_config.plane_list,
head) {
V_53 -> V_42 -> V_51 ( V_53 ) ;
}
F_66 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_4 -> V_42 -> V_51 ( V_4 ) ;
}
F_171 ( & V_2 -> V_5 . V_35 ) ;
}
