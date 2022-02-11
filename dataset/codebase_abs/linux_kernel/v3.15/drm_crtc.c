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
const char * F_18 ( enum V_27 V_28 )
{
return V_29 [ V_28 ] . V_16 ;
}
static char F_19 ( int V_30 )
{
return isascii ( V_30 ) && isprint ( V_30 ) ? V_30 : '?' ;
}
const char * F_20 ( T_1 V_31 )
{
static char V_13 [ 32 ] ;
snprintf ( V_13 , sizeof( V_13 ) ,
L_5 ,
F_19 ( V_31 & 0xff ) ,
F_19 ( ( V_31 >> 8 ) & 0xff ) ,
F_19 ( ( V_31 >> 16 ) & 0xff ) ,
F_19 ( ( V_31 >> 24 ) & 0x7f ) ,
V_31 & V_32 ? L_6 : L_7 ,
V_31 ) ;
return V_13 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 V_35 )
{
int V_36 ;
F_2 ( & V_2 -> V_5 . V_37 ) ;
V_36 = F_22 ( & V_2 -> V_5 . V_38 , V_34 , 1 , 0 , V_39 ) ;
if ( V_36 >= 0 ) {
V_34 -> V_18 = V_36 ;
V_34 -> type = V_35 ;
}
F_6 ( & V_2 -> V_5 . V_37 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_33 * V_40 )
{
F_2 ( & V_2 -> V_5 . V_37 ) ;
F_24 ( & V_2 -> V_5 . V_38 , V_40 -> V_18 ) ;
F_6 ( & V_2 -> V_5 . V_37 ) ;
}
struct V_33 * F_25 ( struct V_1 * V_2 ,
T_1 V_18 , T_1 type )
{
struct V_33 * V_34 = NULL ;
F_8 ( type == V_41 ) ;
F_2 ( & V_2 -> V_5 . V_37 ) ;
V_34 = F_26 ( & V_2 -> V_5 . V_38 , V_18 ) ;
if ( ! V_34 || ( V_34 -> type != type ) || ( V_34 -> V_18 != V_18 ) )
V_34 = NULL ;
F_6 ( & V_2 -> V_5 . V_37 ) ;
return V_34 ;
}
int F_27 ( struct V_1 * V_2 , struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
int V_36 ;
F_2 ( & V_2 -> V_5 . V_46 ) ;
F_28 ( & V_43 -> V_47 ) ;
F_29 ( & V_43 -> V_48 ) ;
V_43 -> V_2 = V_2 ;
V_43 -> V_45 = V_45 ;
V_36 = F_21 ( V_2 , & V_43 -> V_17 , V_41 ) ;
if ( V_36 )
goto V_49;
F_30 ( V_43 ) ;
V_2 -> V_5 . V_50 ++ ;
F_31 ( & V_43 -> V_51 , & V_2 -> V_5 . V_52 ) ;
V_49:
F_6 ( & V_2 -> V_5 . V_46 ) ;
return 0 ;
}
static void F_32 ( struct V_53 * V_53 )
{
struct V_42 * V_43 =
F_33 ( V_53 , struct V_42 , V_47 ) ;
V_43 -> V_45 -> V_54 ( V_43 ) ;
}
static struct V_42 * F_34 ( struct V_1 * V_2 ,
T_1 V_18 )
{
struct V_33 * V_34 = NULL ;
struct V_42 * V_43 ;
F_2 ( & V_2 -> V_5 . V_37 ) ;
V_34 = F_26 ( & V_2 -> V_5 . V_38 , V_18 ) ;
if ( ! V_34 || ( V_34 -> type != V_41 ) || ( V_34 -> V_18 != V_18 ) )
V_43 = NULL ;
else
V_43 = F_35 ( V_34 ) ;
F_6 ( & V_2 -> V_5 . V_37 ) ;
return V_43 ;
}
struct V_42 * F_36 ( struct V_1 * V_2 ,
T_1 V_18 )
{
struct V_42 * V_43 ;
F_2 ( & V_2 -> V_5 . V_46 ) ;
V_43 = F_34 ( V_2 , V_18 ) ;
if ( V_43 )
F_30 ( V_43 ) ;
F_6 ( & V_2 -> V_5 . V_46 ) ;
return V_43 ;
}
void F_37 ( struct V_42 * V_43 )
{
F_38 ( L_8 , V_43 -> V_17 . V_18 ) ;
F_39 ( & V_43 -> V_47 , F_32 ) ;
}
void F_30 ( struct V_42 * V_43 )
{
F_38 ( L_8 , V_43 -> V_17 . V_18 ) ;
F_40 ( & V_43 -> V_47 ) ;
}
static void F_41 ( struct V_53 * V_53 )
{
F_42 () ;
}
static void F_43 ( struct V_42 * V_43 )
{
F_38 ( L_8 , V_43 -> V_17 . V_18 ) ;
F_39 ( & V_43 -> V_47 , F_41 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
F_2 ( & V_2 -> V_5 . V_37 ) ;
F_24 ( & V_2 -> V_5 . V_38 , V_43 -> V_17 . V_18 ) ;
F_6 ( & V_2 -> V_5 . V_37 ) ;
V_43 -> V_17 . V_18 = 0 ;
F_43 ( V_43 ) ;
}
void F_45 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_46 ) ;
F_44 ( V_2 , V_43 ) ;
F_6 ( & V_2 -> V_5 . V_46 ) ;
}
void F_46 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_46 ) ;
F_47 ( & V_43 -> V_51 ) ;
V_2 -> V_5 . V_50 -- ;
F_6 ( & V_2 -> V_5 . V_46 ) ;
}
void F_48 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_3 * V_4 ;
struct V_55 * V_56 ;
struct V_57 V_58 ;
int V_36 ;
F_8 ( ! F_49 ( & V_43 -> V_48 ) ) ;
if ( F_50 ( & V_43 -> V_47 . V_47 ) > 1 ) {
F_1 ( V_2 ) ;
F_3 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_4 -> V_59 -> V_43 == V_43 ) {
memset ( & V_58 , 0 , sizeof( struct V_57 ) ) ;
V_58 . V_4 = V_4 ;
V_58 . V_43 = NULL ;
V_36 = F_51 ( & V_58 ) ;
if ( V_36 )
F_52 ( L_9 , V_4 ) ;
}
}
F_3 (plane, &dev->mode_config.plane_list, head) {
if ( V_56 -> V_43 == V_43 )
F_53 ( V_56 ) ;
}
F_5 ( V_2 ) ;
}
F_37 ( V_43 ) ;
}
int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_55 * V_59 ,
void * V_60 ,
const struct V_61 * V_45 )
{
int V_36 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_45 = V_45 ;
V_4 -> V_62 = false ;
F_1 ( V_2 ) ;
F_55 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_6 , & V_2 -> V_5 . V_6 ) ;
V_36 = F_21 ( V_2 , & V_4 -> V_17 , V_63 ) ;
if ( V_36 )
goto V_49;
V_4 -> V_17 . V_64 = & V_4 -> V_64 ;
F_56 ( & V_4 -> V_51 , & V_2 -> V_5 . V_65 ) ;
V_2 -> V_5 . V_66 ++ ;
V_4 -> V_59 = V_59 ;
if ( V_59 )
V_59 -> V_67 = 1 << F_57 ( V_4 ) ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
void F_58 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_59 ( V_4 -> V_68 ) ;
V_4 -> V_68 = NULL ;
F_23 ( V_2 , & V_4 -> V_17 ) ;
F_47 ( & V_4 -> V_51 ) ;
V_2 -> V_5 . V_66 -- ;
}
unsigned int F_57 ( struct V_3 * V_4 )
{
unsigned int V_69 = 0 ;
struct V_3 * V_70 ;
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_70 == V_4 )
return V_69 ;
V_69 ++ ;
}
F_42 () ;
}
static void F_60 ( struct V_19 * V_20 ,
struct V_71 * V_72 )
{
F_47 ( & V_72 -> V_51 ) ;
F_61 ( V_20 -> V_2 , V_72 ) ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const struct V_73 * V_45 ,
int V_21 )
{
int V_36 ;
struct V_10 * V_74 =
& V_9 [ V_21 ] . V_10 ;
F_1 ( V_2 ) ;
V_36 = F_21 ( V_2 , & V_20 -> V_17 , V_75 ) ;
if ( V_36 )
goto V_49;
V_20 -> V_17 . V_64 = & V_20 -> V_64 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_45 = V_45 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_22 =
F_63 ( V_74 , 1 , 0 , V_39 ) ;
if ( V_20 -> V_22 < 0 ) {
V_36 = V_20 -> V_22 ;
F_23 ( V_2 , & V_20 -> V_17 ) ;
goto V_49;
}
F_29 ( & V_20 -> V_76 ) ;
F_29 ( & V_20 -> V_77 ) ;
V_20 -> V_78 = NULL ;
V_20 -> V_24 = V_79 ;
F_56 ( & V_20 -> V_51 , & V_2 -> V_5 . V_80 ) ;
V_2 -> V_5 . V_81 ++ ;
if ( V_21 != V_82 )
F_64 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_83 ,
0 ) ;
F_64 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_84 , 0 ) ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
void F_65 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_71 * V_72 , * V_85 ;
F_66 (mode, t, &connector->probed_modes, head)
F_60 ( V_20 , V_72 ) ;
F_66 (mode, t, &connector->modes, head)
F_60 ( V_20 , V_72 ) ;
F_67 ( & V_9 [ V_20 -> V_21 ] . V_10 ,
V_20 -> V_22 ) ;
F_23 ( V_2 , & V_20 -> V_17 ) ;
F_47 ( & V_20 -> V_51 ) ;
V_2 -> V_5 . V_81 -- ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
F_3 (connector, &dev->mode_config.connector_list, head)
F_69 ( V_20 ) ;
}
int F_70 ( struct V_1 * V_2 , struct V_86 * V_87 ,
const struct V_88 * V_45 )
{
int V_36 ;
F_1 ( V_2 ) ;
V_36 = F_21 ( V_2 , & V_87 -> V_17 , V_89 ) ;
if ( V_36 )
goto V_49;
V_87 -> V_2 = V_2 ;
V_87 -> V_45 = V_45 ;
F_56 ( & V_87 -> V_51 , & V_2 -> V_5 . V_90 ) ;
V_2 -> V_5 . V_91 ++ ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
void F_71 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_2 ;
F_1 ( V_2 ) ;
F_23 ( V_2 , & V_87 -> V_17 ) ;
F_47 ( & V_87 -> V_51 ) ;
V_2 -> V_5 . V_91 -- ;
F_5 ( V_2 ) ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
const struct V_92 * V_45 ,
int V_15 )
{
int V_36 ;
F_1 ( V_2 ) ;
V_36 = F_21 ( V_2 , & V_12 -> V_17 , V_93 ) ;
if ( V_36 )
goto V_49;
V_12 -> V_2 = V_2 ;
V_12 -> V_15 = V_15 ;
V_12 -> V_45 = V_45 ;
F_56 ( & V_12 -> V_51 , & V_2 -> V_5 . V_94 ) ;
V_2 -> V_5 . V_95 ++ ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
void F_73 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_1 ( V_2 ) ;
F_23 ( V_2 , & V_12 -> V_17 ) ;
F_47 ( & V_12 -> V_51 ) ;
V_2 -> V_5 . V_95 -- ;
F_5 ( V_2 ) ;
}
int F_74 ( struct V_1 * V_2 , struct V_55 * V_56 ,
unsigned long V_67 ,
const struct V_96 * V_45 ,
const T_1 * V_97 , T_1 V_98 ,
enum V_99 type )
{
int V_36 ;
F_1 ( V_2 ) ;
V_36 = F_21 ( V_2 , & V_56 -> V_17 , V_100 ) ;
if ( V_36 )
goto V_49;
V_56 -> V_17 . V_64 = & V_56 -> V_64 ;
V_56 -> V_2 = V_2 ;
V_56 -> V_45 = V_45 ;
V_56 -> V_101 = F_75 ( sizeof( T_1 ) * V_98 ,
V_39 ) ;
if ( ! V_56 -> V_101 ) {
F_76 ( L_10 ) ;
F_23 ( V_2 , & V_56 -> V_17 ) ;
V_36 = - V_102 ;
goto V_49;
}
memcpy ( V_56 -> V_101 , V_97 , V_98 * sizeof( T_1 ) ) ;
V_56 -> V_98 = V_98 ;
V_56 -> V_67 = V_67 ;
V_56 -> type = type ;
F_56 ( & V_56 -> V_51 , & V_2 -> V_5 . V_103 ) ;
V_2 -> V_5 . V_104 ++ ;
if ( V_56 -> type == V_105 )
V_2 -> V_5 . V_106 ++ ;
F_64 ( & V_56 -> V_17 ,
V_2 -> V_5 . V_107 ,
V_56 -> type ) ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_77 ( struct V_1 * V_2 , struct V_55 * V_56 ,
unsigned long V_67 ,
const struct V_96 * V_45 ,
const T_1 * V_97 , T_1 V_98 ,
bool V_108 )
{
enum V_99 type ;
type = V_108 ? V_109 : V_105 ;
return F_74 ( V_2 , V_56 , V_67 , V_45 ,
V_97 , V_98 , type ) ;
}
void F_78 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
F_1 ( V_2 ) ;
F_59 ( V_56 -> V_101 ) ;
F_23 ( V_2 , & V_56 -> V_17 ) ;
F_79 ( F_49 ( & V_56 -> V_51 ) ) ;
F_47 ( & V_56 -> V_51 ) ;
V_2 -> V_5 . V_104 -- ;
if ( V_56 -> type == V_105 )
V_2 -> V_5 . V_106 -- ;
F_5 ( V_2 ) ;
}
void F_53 ( struct V_55 * V_56 )
{
int V_36 ;
if ( ! V_56 -> V_43 )
return;
V_36 = V_56 -> V_45 -> V_110 ( V_56 ) ;
if ( V_36 )
F_52 ( L_11 ) ;
F_43 ( V_56 -> V_43 ) ;
V_56 -> V_43 = NULL ;
V_56 -> V_4 = NULL ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
struct V_111 * V_113 ;
V_112 = F_81 ( V_2 , V_114 |
V_115 ,
L_12 , 0 ) ;
V_2 -> V_5 . V_83 = V_112 ;
V_113 = F_82 ( V_2 , 0 ,
L_13 , V_116 ,
F_11 ( V_116 ) ) ;
V_2 -> V_5 . V_84 = V_113 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_111 * type ;
type = F_82 ( V_2 , V_115 ,
L_14 , V_117 ,
F_11 ( V_117 ) ) ;
V_2 -> V_5 . V_107 = type ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 )
{
struct V_111 * V_118 ;
struct V_111 * V_119 ;
if ( V_2 -> V_5 . V_120 )
return 0 ;
V_118 =
F_82 ( V_2 , 0 ,
L_15 ,
V_121 ,
F_11 ( V_121 ) ) ;
V_2 -> V_5 . V_120 = V_118 ;
V_119 = F_82 ( V_2 , V_115 ,
L_16 ,
V_122 ,
F_11 ( V_122 ) ) ;
V_2 -> V_5 . V_123 = V_119 ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 , int V_124 ,
char * V_77 [] )
{
struct V_111 * V_125 ;
struct V_111 * V_126 ;
int V_8 ;
if ( V_2 -> V_5 . V_127 )
return 0 ;
V_125 = F_82 ( V_2 , 0 ,
L_15 ,
V_128 ,
F_11 ( V_128 ) ) ;
V_2 -> V_5 . V_127 = V_125 ;
V_126 =
F_82 ( V_2 , V_115 ,
L_16 ,
V_129 ,
F_11 ( V_129 ) ) ;
V_2 -> V_5 . V_130 = V_126 ;
V_2 -> V_5 . V_131 =
F_86 ( V_2 , 0 , L_17 , 0 , 100 ) ;
V_2 -> V_5 . V_132 =
F_86 ( V_2 , 0 , L_18 , 0 , 100 ) ;
V_2 -> V_5 . V_133 =
F_86 ( V_2 , 0 , L_19 , 0 , 100 ) ;
V_2 -> V_5 . V_134 =
F_86 ( V_2 , 0 , L_20 , 0 , 100 ) ;
V_2 -> V_5 . V_135 =
F_81 ( V_2 , V_136 ,
L_21 , V_124 ) ;
for ( V_8 = 0 ; V_8 < V_124 ; V_8 ++ )
F_87 ( V_2 -> V_5 . V_135 , V_8 ,
V_8 , V_77 [ V_8 ] ) ;
V_2 -> V_5 . V_137 =
F_86 ( V_2 , 0 , L_22 , 0 , 100 ) ;
V_2 -> V_5 . V_138 =
F_86 ( V_2 , 0 , L_23 , 0 , 100 ) ;
V_2 -> V_5 . V_139 =
F_86 ( V_2 , 0 , L_24 , 0 , 100 ) ;
V_2 -> V_5 . V_140 =
F_86 ( V_2 , 0 , L_25 , 0 , 100 ) ;
V_2 -> V_5 . V_141 =
F_86 ( V_2 , 0 , L_26 , 0 , 100 ) ;
V_2 -> V_5 . V_142 =
F_86 ( V_2 , 0 , L_27 , 0 , 100 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 )
{
struct V_111 * V_143 ;
if ( V_2 -> V_5 . V_144 )
return 0 ;
V_143 =
F_82 ( V_2 , 0 , L_28 ,
V_145 ,
F_11 ( V_145 ) ) ;
V_2 -> V_5 . V_144 = V_143 ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 )
{
struct V_111 * V_146 ;
if ( V_2 -> V_5 . V_147 )
return 0 ;
V_146 =
F_82 ( V_2 , V_115 ,
L_29 ,
V_148 ,
F_11 ( V_148 ) ) ;
V_2 -> V_5 . V_147 = V_146 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_149 * V_150 )
{
T_1 V_151 = 0 ;
V_151 += V_2 -> V_5 . V_66 ;
V_151 += V_2 -> V_5 . V_81 ;
V_151 += V_2 -> V_5 . V_95 ;
V_151 += V_2 -> V_5 . V_91 ;
V_150 -> V_152 = F_91 ( V_151 * sizeof( T_1 ) , V_39 ) ;
if ( ! V_150 -> V_152 )
return - V_102 ;
V_150 -> V_153 = 0 ;
V_150 -> V_154 = 0 ;
V_150 -> V_155 = 0 ;
V_150 -> V_156 = 0 ;
return 0 ;
}
int F_92 ( struct V_1 * V_2 ,
struct V_149 * V_150 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_19 * V_20 ;
struct V_86 * V_87 ;
int V_36 ;
if ( ( V_36 = F_90 ( V_2 , V_150 ) ) )
return V_36 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
V_150 -> V_152 [ V_150 -> V_153 ++ ] = V_4 -> V_17 . V_18 ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
V_150 -> V_152 [ V_150 -> V_153 + V_150 -> V_155 ++ ] =
V_12 -> V_17 . V_18 ;
F_3 (connector, &dev->mode_config.connector_list, head)
V_150 -> V_152 [ V_150 -> V_153 + V_150 -> V_155 +
V_150 -> V_154 ++ ] = V_20 -> V_17 . V_18 ;
F_3 (bridge, &dev->mode_config.bridge_list, head)
V_150 -> V_152 [ V_150 -> V_153 + V_150 -> V_155 +
V_150 -> V_154 + V_150 -> V_156 ++ ] =
V_87 -> V_17 . V_18 ;
return 0 ;
}
static void F_93 ( struct V_157 * V_49 ,
const struct V_71 * V_158 )
{
F_94 ( V_158 -> V_159 > V_160 || V_158 -> V_161 > V_160 ||
V_158 -> V_162 > V_160 || V_158 -> V_163 > V_160 ||
V_158 -> V_164 > V_160 || V_158 -> V_165 > V_160 ||
V_158 -> V_166 > V_160 || V_158 -> V_167 > V_160 ||
V_158 -> V_168 > V_160 || V_158 -> V_169 > V_160 ,
L_30 ) ;
V_49 -> clock = V_158 -> clock ;
V_49 -> V_159 = V_158 -> V_159 ;
V_49 -> V_161 = V_158 -> V_161 ;
V_49 -> V_162 = V_158 -> V_162 ;
V_49 -> V_163 = V_158 -> V_163 ;
V_49 -> V_164 = V_158 -> V_164 ;
V_49 -> V_165 = V_158 -> V_165 ;
V_49 -> V_166 = V_158 -> V_166 ;
V_49 -> V_167 = V_158 -> V_167 ;
V_49 -> V_168 = V_158 -> V_168 ;
V_49 -> V_169 = V_158 -> V_169 ;
V_49 -> V_170 = V_158 -> V_170 ;
V_49 -> V_171 = V_158 -> V_171 ;
V_49 -> type = V_158 -> type ;
strncpy ( V_49 -> V_16 , V_158 -> V_16 , V_172 ) ;
V_49 -> V_16 [ V_172 - 1 ] = 0 ;
}
static int F_95 ( struct V_71 * V_49 ,
const struct V_157 * V_158 )
{
if ( V_158 -> clock > V_173 || V_158 -> V_170 > V_173 )
return - V_174 ;
if ( ( V_158 -> V_171 & V_175 ) > V_176 )
return - V_177 ;
V_49 -> clock = V_158 -> clock ;
V_49 -> V_159 = V_158 -> V_159 ;
V_49 -> V_161 = V_158 -> V_161 ;
V_49 -> V_162 = V_158 -> V_162 ;
V_49 -> V_163 = V_158 -> V_163 ;
V_49 -> V_164 = V_158 -> V_164 ;
V_49 -> V_165 = V_158 -> V_165 ;
V_49 -> V_166 = V_158 -> V_166 ;
V_49 -> V_167 = V_158 -> V_167 ;
V_49 -> V_168 = V_158 -> V_168 ;
V_49 -> V_169 = V_158 -> V_169 ;
V_49 -> V_170 = V_158 -> V_170 ;
V_49 -> V_171 = V_158 -> V_171 ;
V_49 -> type = V_158 -> type ;
strncpy ( V_49 -> V_16 , V_158 -> V_16 , V_172 ) ;
V_49 -> V_16 [ V_172 - 1 ] = 0 ;
return 0 ;
}
int F_96 ( struct V_1 * V_2 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_181 * V_182 = V_178 ;
struct V_183 * V_184 ;
struct V_42 * V_43 ;
struct V_19 * V_20 ;
struct V_3 * V_4 ;
struct V_11 * V_12 ;
int V_36 = 0 ;
int V_185 = 0 ;
int V_186 = 0 ;
int V_187 = 0 ;
int V_188 = 0 ;
int V_189 = 0 , V_8 ;
T_1 T_2 * V_190 ;
T_1 T_2 * V_191 ;
T_1 T_2 * V_192 ;
T_1 T_2 * V_193 ;
struct V_149 * V_194 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_2 ( & V_180 -> V_196 ) ;
F_98 (lh, &file_priv->fbs)
V_187 ++ ;
if ( V_182 -> V_197 >= V_187 ) {
V_189 = 0 ;
V_190 = ( T_1 T_2 * ) ( unsigned long ) V_182 -> V_198 ;
F_3 (fb, &file_priv->fbs, filp_head) {
if ( F_99 ( V_43 -> V_17 . V_18 , V_190 + V_189 ) ) {
F_6 ( & V_180 -> V_196 ) ;
return - V_199 ;
}
V_189 ++ ;
}
}
V_182 -> V_197 = V_187 ;
F_6 ( & V_180 -> V_196 ) ;
F_1 ( V_2 ) ;
if ( ! F_100 ( V_180 ) ) {
V_194 = NULL ;
F_98 (lh, &dev->mode_config.crtc_list)
V_186 ++ ;
F_98 (lh, &dev->mode_config.connector_list)
V_185 ++ ;
F_98 (lh, &dev->mode_config.encoder_list)
V_188 ++ ;
} else {
V_194 = & V_180 -> V_200 -> V_201 -> V_194 ;
V_186 = V_194 -> V_153 ;
V_185 = V_194 -> V_154 ;
V_188 = V_194 -> V_155 ;
}
V_182 -> V_202 = V_2 -> V_5 . V_202 ;
V_182 -> V_203 = V_2 -> V_5 . V_203 ;
V_182 -> V_204 = V_2 -> V_5 . V_204 ;
V_182 -> V_205 = V_2 -> V_5 . V_205 ;
if ( V_182 -> V_206 >= V_186 ) {
V_189 = 0 ;
V_191 = ( T_1 T_2 * ) ( unsigned long ) V_182 -> V_207 ;
if ( ! V_194 ) {
F_3 (crtc, &dev->mode_config.crtc_list,
head) {
F_76 ( L_31 , V_4 -> V_17 . V_18 ) ;
if ( F_99 ( V_4 -> V_17 . V_18 , V_191 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
} else {
for ( V_8 = 0 ; V_8 < V_194 -> V_153 ; V_8 ++ ) {
if ( F_99 ( V_194 -> V_152 [ V_8 ] ,
V_191 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
}
}
V_182 -> V_206 = V_186 ;
if ( V_182 -> V_208 >= V_188 ) {
V_189 = 0 ;
V_193 = ( T_1 T_2 * ) ( unsigned long ) V_182 -> V_209 ;
if ( ! V_194 ) {
F_3 (encoder,
&dev->mode_config.encoder_list,
head) {
F_76 ( L_32 , V_12 -> V_17 . V_18 ,
F_15 ( V_12 ) ) ;
if ( F_99 ( V_12 -> V_17 . V_18 , V_193 +
V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
} else {
for ( V_8 = V_194 -> V_153 ; V_8 < V_194 -> V_153 + V_194 -> V_155 ; V_8 ++ ) {
if ( F_99 ( V_194 -> V_152 [ V_8 ] ,
V_193 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
}
}
V_182 -> V_208 = V_188 ;
if ( V_182 -> V_210 >= V_185 ) {
V_189 = 0 ;
V_192 = ( T_1 T_2 * ) ( unsigned long ) V_182 -> V_211 ;
if ( ! V_194 ) {
F_3 (connector,
&dev->mode_config.connector_list,
head) {
F_76 ( L_33 ,
V_20 -> V_17 . V_18 ,
F_16 ( V_20 ) ) ;
if ( F_99 ( V_20 -> V_17 . V_18 ,
V_192 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
} else {
int V_212 = V_194 -> V_153 +
V_194 -> V_155 ;
for ( V_8 = V_212 ; V_8 < V_212 + V_194 -> V_154 ; V_8 ++ ) {
if ( F_99 ( V_194 -> V_152 [ V_8 ] ,
V_192 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
}
}
V_182 -> V_210 = V_185 ;
F_76 ( L_34 , V_182 -> V_206 ,
V_182 -> V_210 , V_182 -> V_208 ) ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_101 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_213 * V_214 = V_178 ;
struct V_3 * V_4 ;
struct V_33 * V_34 ;
int V_36 = 0 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_34 = F_25 ( V_2 , V_214 -> V_191 ,
V_63 ) ;
if ( ! V_34 ) {
V_36 = - V_215 ;
goto V_49;
}
V_4 = F_102 ( V_34 ) ;
V_214 -> V_216 = V_4 -> V_216 ;
V_214 -> V_217 = V_4 -> V_217 ;
V_214 -> V_218 = V_4 -> V_218 ;
if ( V_4 -> V_59 -> V_43 )
V_214 -> V_190 = V_4 -> V_59 -> V_43 -> V_17 . V_18 ;
else
V_214 -> V_190 = 0 ;
if ( V_4 -> V_219 ) {
F_93 ( & V_214 -> V_72 , & V_4 -> V_72 ) ;
V_214 -> V_220 = 1 ;
} else {
V_214 -> V_220 = 0 ;
}
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
static bool F_103 ( const struct V_71 * V_72 ,
const struct V_179 * V_180 )
{
if ( ! V_180 -> V_221 && F_104 ( V_72 ) )
return false ;
return true ;
}
int F_105 ( struct V_1 * V_2 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_222 * V_223 = V_178 ;
struct V_33 * V_34 ;
struct V_19 * V_20 ;
struct V_71 * V_72 ;
int V_224 = 0 ;
int V_225 = 0 ;
int V_226 = 0 ;
int V_36 = 0 ;
int V_189 = 0 ;
int V_8 ;
struct V_157 V_227 ;
struct V_157 T_2 * V_228 ;
T_1 T_2 * V_229 ;
T_3 T_2 * V_230 ;
T_1 T_2 * V_231 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
memset ( & V_227 , 0 , sizeof( struct V_157 ) ) ;
F_76 ( L_35 , V_223 -> V_192 ) ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_34 = F_25 ( V_2 , V_223 -> V_192 ,
V_75 ) ;
if ( ! V_34 ) {
V_36 = - V_215 ;
goto V_49;
}
V_20 = F_106 ( V_34 ) ;
V_225 = V_20 -> V_64 . V_232 ;
for ( V_8 = 0 ; V_8 < V_233 ; V_8 ++ ) {
if ( V_20 -> V_234 [ V_8 ] != 0 ) {
V_226 ++ ;
}
}
if ( V_223 -> V_235 == 0 ) {
V_20 -> V_45 -> V_236 ( V_20 ,
V_2 -> V_5 . V_204 ,
V_2 -> V_5 . V_202 ) ;
}
F_3 (mode, &connector->modes, head)
if ( F_103 ( V_72 , V_180 ) )
V_224 ++ ;
V_223 -> V_192 = V_20 -> V_17 . V_18 ;
V_223 -> V_21 = V_20 -> V_21 ;
V_223 -> V_22 = V_20 -> V_22 ;
V_223 -> V_237 = V_20 -> V_238 . V_239 ;
V_223 -> V_240 = V_20 -> V_238 . V_241 ;
V_223 -> V_242 = V_20 -> V_238 . V_27 ;
V_223 -> V_243 = V_20 -> V_24 ;
if ( V_20 -> V_12 )
V_223 -> V_193 = V_20 -> V_12 -> V_17 . V_18 ;
else
V_223 -> V_193 = 0 ;
if ( ( V_223 -> V_235 >= V_224 ) && V_224 ) {
V_189 = 0 ;
V_228 = (struct V_157 T_2 * ) ( unsigned long ) V_223 -> V_244 ;
F_3 (mode, &connector->modes, head) {
if ( ! F_103 ( V_72 , V_180 ) )
continue;
F_93 ( & V_227 , V_72 ) ;
if ( F_107 ( V_228 + V_189 ,
& V_227 , sizeof( V_227 ) ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
}
V_223 -> V_235 = V_224 ;
if ( ( V_223 -> V_245 >= V_225 ) && V_225 ) {
V_189 = 0 ;
V_229 = ( T_1 T_2 * ) ( unsigned long ) ( V_223 -> V_246 ) ;
V_230 = ( T_3 T_2 * ) ( unsigned long ) ( V_223 -> V_247 ) ;
for ( V_8 = 0 ; V_8 < V_20 -> V_64 . V_232 ; V_8 ++ ) {
if ( F_99 ( V_20 -> V_64 . V_248 [ V_8 ] ,
V_229 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
if ( F_99 ( V_20 -> V_64 . V_249 [ V_8 ] ,
V_230 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
}
V_223 -> V_245 = V_225 ;
if ( ( V_223 -> V_208 >= V_226 ) && V_226 ) {
V_189 = 0 ;
V_231 = ( T_1 T_2 * ) ( unsigned long ) ( V_223 -> V_250 ) ;
for ( V_8 = 0 ; V_8 < V_233 ; V_8 ++ ) {
if ( V_20 -> V_234 [ V_8 ] != 0 ) {
if ( F_99 ( V_20 -> V_234 [ V_8 ] ,
V_231 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
}
}
V_223 -> V_208 = V_226 ;
V_49:
F_6 ( & V_2 -> V_5 . V_6 ) ;
return V_36 ;
}
int F_108 ( struct V_1 * V_2 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_251 * V_252 = V_178 ;
struct V_33 * V_34 ;
struct V_11 * V_12 ;
int V_36 = 0 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_34 = F_25 ( V_2 , V_252 -> V_193 ,
V_93 ) ;
if ( ! V_34 ) {
V_36 = - V_215 ;
goto V_49;
}
V_12 = F_109 ( V_34 ) ;
if ( V_12 -> V_4 )
V_252 -> V_191 = V_12 -> V_4 -> V_17 . V_18 ;
else
V_252 -> V_191 = 0 ;
V_252 -> V_15 = V_12 -> V_15 ;
V_252 -> V_193 = V_12 -> V_17 . V_18 ;
V_252 -> V_67 = V_12 -> V_67 ;
V_252 -> V_253 = V_12 -> V_253 ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_110 ( struct V_1 * V_2 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_254 * V_255 = V_178 ;
struct V_256 * V_257 ;
struct V_55 * V_56 ;
T_1 T_2 * V_258 ;
int V_189 = 0 , V_36 = 0 ;
unsigned V_259 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_257 = & V_2 -> V_5 ;
if ( V_180 -> V_260 )
V_259 = V_257 -> V_104 ;
else
V_259 = V_257 -> V_106 ;
if ( V_259 &&
( V_255 -> V_261 >= V_259 ) ) {
V_258 = ( T_1 T_2 * ) ( unsigned long ) V_255 -> V_262 ;
F_3 (plane, &config->plane_list, head) {
if ( V_56 -> type != V_105 &&
! V_180 -> V_260 )
continue;
if ( F_99 ( V_56 -> V_17 . V_18 , V_258 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
}
V_255 -> V_261 = V_259 ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_111 ( struct V_1 * V_2 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_263 * V_255 = V_178 ;
struct V_33 * V_34 ;
struct V_55 * V_56 ;
T_1 T_2 * V_264 ;
int V_36 = 0 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_34 = F_25 ( V_2 , V_255 -> V_265 ,
V_100 ) ;
if ( ! V_34 ) {
V_36 = - V_215 ;
goto V_49;
}
V_56 = F_112 ( V_34 ) ;
if ( V_56 -> V_4 )
V_255 -> V_191 = V_56 -> V_4 -> V_17 . V_18 ;
else
V_255 -> V_191 = 0 ;
if ( V_56 -> V_43 )
V_255 -> V_190 = V_56 -> V_43 -> V_17 . V_18 ;
else
V_255 -> V_190 = 0 ;
V_255 -> V_265 = V_56 -> V_17 . V_18 ;
V_255 -> V_67 = V_56 -> V_67 ;
V_255 -> V_218 = 0 ;
if ( V_56 -> V_98 &&
( V_255 -> V_266 >= V_56 -> V_98 ) ) {
V_264 = ( T_1 T_2 * ) ( unsigned long ) V_255 -> V_267 ;
if ( F_107 ( V_264 ,
V_56 -> V_101 ,
sizeof( T_1 ) * V_56 -> V_98 ) ) {
V_36 = - V_199 ;
goto V_49;
}
}
V_255 -> V_266 = V_56 -> V_98 ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_113 ( struct V_1 * V_2 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_268 * V_269 = V_178 ;
struct V_33 * V_34 ;
struct V_55 * V_56 ;
struct V_3 * V_4 ;
struct V_42 * V_43 = NULL , * V_270 = NULL ;
int V_36 = 0 ;
unsigned int V_271 , V_272 ;
int V_8 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
V_34 = F_25 ( V_2 , V_269 -> V_265 ,
V_100 ) ;
if ( ! V_34 ) {
F_76 ( L_36 ,
V_269 -> V_265 ) ;
return - V_215 ;
}
V_56 = F_112 ( V_34 ) ;
if ( ! V_269 -> V_190 ) {
F_1 ( V_2 ) ;
V_270 = V_56 -> V_43 ;
V_56 -> V_45 -> V_110 ( V_56 ) ;
V_56 -> V_4 = NULL ;
V_56 -> V_43 = NULL ;
F_5 ( V_2 ) ;
goto V_49;
}
V_34 = F_25 ( V_2 , V_269 -> V_191 ,
V_63 ) ;
if ( ! V_34 ) {
F_76 ( L_37 ,
V_269 -> V_191 ) ;
V_36 = - V_215 ;
goto V_49;
}
V_4 = F_102 ( V_34 ) ;
V_43 = F_36 ( V_2 , V_269 -> V_190 ) ;
if ( ! V_43 ) {
F_76 ( L_38 ,
V_269 -> V_190 ) ;
V_36 = - V_215 ;
goto V_49;
}
for ( V_8 = 0 ; V_8 < V_56 -> V_98 ; V_8 ++ )
if ( V_43 -> V_273 == V_56 -> V_101 [ V_8 ] )
break;
if ( V_8 == V_56 -> V_98 ) {
F_76 ( L_39 ,
F_20 ( V_43 -> V_273 ) ) ;
V_36 = - V_177 ;
goto V_49;
}
V_271 = V_43 -> V_274 << 16 ;
V_272 = V_43 -> V_275 << 16 ;
if ( V_269 -> V_276 > V_271 ||
V_269 -> V_277 > V_271 - V_269 -> V_276 ||
V_269 -> V_278 > V_272 ||
V_269 -> V_279 > V_272 - V_269 -> V_278 ) {
F_76 ( L_40
L_41 ,
V_269 -> V_276 >> 16 ,
( ( V_269 -> V_276 & 0xffff ) * 15625 ) >> 10 ,
V_269 -> V_278 >> 16 ,
( ( V_269 -> V_278 & 0xffff ) * 15625 ) >> 10 ,
V_269 -> V_277 >> 16 ,
( ( V_269 -> V_277 & 0xffff ) * 15625 ) >> 10 ,
V_269 -> V_279 >> 16 ,
( ( V_269 -> V_279 & 0xffff ) * 15625 ) >> 10 ) ;
V_36 = - V_280 ;
goto V_49;
}
if ( V_269 -> V_281 > V_173 ||
V_269 -> V_282 > V_173 - ( V_283 ) V_269 -> V_281 ||
V_269 -> V_284 > V_173 ||
V_269 -> V_285 > V_173 - ( V_283 ) V_269 -> V_284 ) {
F_76 ( L_42 ,
V_269 -> V_281 , V_269 -> V_284 ,
V_269 -> V_282 , V_269 -> V_285 ) ;
V_36 = - V_174 ;
goto V_49;
}
F_1 ( V_2 ) ;
V_36 = V_56 -> V_45 -> V_286 ( V_56 , V_4 , V_43 ,
V_269 -> V_282 , V_269 -> V_285 ,
V_269 -> V_281 , V_269 -> V_284 ,
V_269 -> V_277 , V_269 -> V_279 ,
V_269 -> V_276 , V_269 -> V_278 ) ;
if ( ! V_36 ) {
V_270 = V_56 -> V_43 ;
V_56 -> V_4 = V_4 ;
V_56 -> V_43 = V_43 ;
V_43 = NULL ;
}
F_5 ( V_2 ) ;
V_49:
if ( V_43 )
F_37 ( V_43 ) ;
if ( V_270 )
F_37 ( V_270 ) ;
return V_36 ;
}
int F_51 ( struct V_57 * V_58 )
{
struct V_3 * V_4 = V_58 -> V_4 ;
struct V_42 * V_43 ;
struct V_3 * V_70 ;
int V_36 ;
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_70 -> V_270 = V_70 -> V_59 -> V_43 ;
V_43 = V_58 -> V_43 ;
V_36 = V_4 -> V_45 -> V_287 ( V_58 ) ;
if ( V_36 == 0 ) {
V_4 -> V_59 -> V_4 = V_4 ;
F_8 ( V_43 != V_4 -> V_59 -> V_43 ) ;
}
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_70 -> V_59 -> V_43 )
F_30 ( V_70 -> V_59 -> V_43 ) ;
if ( V_70 -> V_270 )
F_37 ( V_70 -> V_270 ) ;
}
return V_36 ;
}
int F_114 ( const struct V_3 * V_4 ,
int V_216 , int V_217 ,
const struct V_71 * V_72 ,
const struct V_42 * V_43 )
{
int V_159 , V_165 ;
V_159 = V_72 -> V_159 ;
V_165 = V_72 -> V_165 ;
if ( F_104 ( V_72 ) ) {
struct V_71 V_288 = * V_72 ;
F_115 ( & V_288 , V_289 ) ;
V_159 = V_288 . V_290 ;
V_165 = V_288 . V_291 ;
}
if ( V_4 -> V_62 )
F_116 ( V_159 , V_165 ) ;
if ( V_159 > V_43 -> V_274 ||
V_165 > V_43 -> V_275 ||
V_216 > V_43 -> V_274 - V_159 ||
V_217 > V_43 -> V_275 - V_165 ) {
F_76 ( L_43 ,
V_43 -> V_274 , V_43 -> V_275 , V_159 , V_165 , V_216 , V_217 ,
V_4 -> V_62 ? L_44 : L_45 ) ;
return - V_280 ;
}
return 0 ;
}
int F_117 ( struct V_1 * V_2 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_256 * V_257 = & V_2 -> V_5 ;
struct V_213 * V_292 = V_178 ;
struct V_33 * V_34 ;
struct V_3 * V_4 ;
struct V_19 * * V_293 = NULL , * V_20 ;
struct V_42 * V_43 = NULL ;
struct V_71 * V_72 = NULL ;
struct V_57 V_58 ;
T_1 T_2 * V_294 ;
int V_36 ;
int V_8 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
if ( V_292 -> V_216 > V_173 || V_292 -> V_217 > V_173 )
return - V_174 ;
F_1 ( V_2 ) ;
V_34 = F_25 ( V_2 , V_292 -> V_191 ,
V_63 ) ;
if ( ! V_34 ) {
F_76 ( L_46 , V_292 -> V_191 ) ;
V_36 = - V_215 ;
goto V_49;
}
V_4 = F_102 ( V_34 ) ;
F_76 ( L_31 , V_4 -> V_17 . V_18 ) ;
if ( V_292 -> V_220 ) {
if ( V_292 -> V_190 == - 1 ) {
if ( ! V_4 -> V_59 -> V_43 ) {
F_76 ( L_47 ) ;
V_36 = - V_177 ;
goto V_49;
}
V_43 = V_4 -> V_59 -> V_43 ;
F_30 ( V_43 ) ;
} else {
V_43 = F_36 ( V_2 , V_292 -> V_190 ) ;
if ( ! V_43 ) {
F_76 ( L_48 ,
V_292 -> V_190 ) ;
V_36 = - V_215 ;
goto V_49;
}
}
V_72 = F_118 ( V_2 ) ;
if ( ! V_72 ) {
V_36 = - V_102 ;
goto V_49;
}
V_36 = F_95 ( V_72 , & V_292 -> V_72 ) ;
if ( V_36 ) {
F_76 ( L_49 ) ;
goto V_49;
}
F_115 ( V_72 , V_295 ) ;
V_36 = F_114 ( V_4 , V_292 -> V_216 , V_292 -> V_217 ,
V_72 , V_43 ) ;
if ( V_36 )
goto V_49;
}
if ( V_292 -> V_210 == 0 && V_72 ) {
F_76 ( L_50 ) ;
V_36 = - V_177 ;
goto V_49;
}
if ( V_292 -> V_210 > 0 && ( ! V_72 || ! V_43 ) ) {
F_76 ( L_51 ,
V_292 -> V_210 ) ;
V_36 = - V_177 ;
goto V_49;
}
if ( V_292 -> V_210 > 0 ) {
T_4 V_296 ;
if ( V_292 -> V_210 > V_257 -> V_81 ) {
V_36 = - V_177 ;
goto V_49;
}
V_293 = F_75 ( V_292 -> V_210 *
sizeof( struct V_19 * ) ,
V_39 ) ;
if ( ! V_293 ) {
V_36 = - V_102 ;
goto V_49;
}
for ( V_8 = 0 ; V_8 < V_292 -> V_210 ; V_8 ++ ) {
V_294 = ( T_1 T_2 * ) ( unsigned long ) V_292 -> V_294 ;
if ( F_119 ( V_296 , & V_294 [ V_8 ] ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_34 = F_25 ( V_2 , V_296 ,
V_75 ) ;
if ( ! V_34 ) {
F_76 ( L_52 ,
V_296 ) ;
V_36 = - V_215 ;
goto V_49;
}
V_20 = F_106 ( V_34 ) ;
F_76 ( L_33 ,
V_20 -> V_17 . V_18 ,
F_16 ( V_20 ) ) ;
V_293 [ V_8 ] = V_20 ;
}
}
V_58 . V_4 = V_4 ;
V_58 . V_216 = V_292 -> V_216 ;
V_58 . V_217 = V_292 -> V_217 ;
V_58 . V_72 = V_72 ;
V_58 . V_297 = V_293 ;
V_58 . V_154 = V_292 -> V_210 ;
V_58 . V_43 = V_43 ;
V_36 = F_51 ( & V_58 ) ;
V_49:
if ( V_43 )
F_37 ( V_43 ) ;
F_59 ( V_293 ) ;
F_61 ( V_2 , V_72 ) ;
F_5 ( V_2 ) ;
return V_36 ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_298 * V_299 ,
struct V_179 * V_180 )
{
struct V_33 * V_34 ;
struct V_3 * V_4 ;
int V_36 = 0 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
if ( ! V_299 -> V_171 || ( ~ V_300 & V_299 -> V_171 ) )
return - V_177 ;
V_34 = F_25 ( V_2 , V_299 -> V_191 , V_63 ) ;
if ( ! V_34 ) {
F_76 ( L_46 , V_299 -> V_191 ) ;
return - V_215 ;
}
V_4 = F_102 ( V_34 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_299 -> V_171 & V_301 ) {
if ( ! V_4 -> V_45 -> V_302 && ! V_4 -> V_45 -> V_303 ) {
V_36 = - V_304 ;
goto V_49;
}
if ( V_4 -> V_45 -> V_303 )
V_36 = V_4 -> V_45 -> V_303 ( V_4 , V_180 , V_299 -> V_305 ,
V_299 -> V_274 , V_299 -> V_275 , V_299 -> V_306 , V_299 -> V_307 ) ;
else
V_36 = V_4 -> V_45 -> V_302 ( V_4 , V_180 , V_299 -> V_305 ,
V_299 -> V_274 , V_299 -> V_275 ) ;
}
if ( V_299 -> V_171 & V_308 ) {
if ( V_4 -> V_45 -> V_309 ) {
V_36 = V_4 -> V_45 -> V_309 ( V_4 , V_299 -> V_216 , V_299 -> V_217 ) ;
} else {
V_36 = - V_199 ;
goto V_49;
}
}
V_49:
F_6 ( & V_4 -> V_6 ) ;
return V_36 ;
}
int F_121 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_310 * V_299 = V_178 ;
struct V_298 V_311 ;
memcpy ( & V_311 , V_299 , sizeof( struct V_310 ) ) ;
V_311 . V_306 = V_311 . V_307 = 0 ;
return F_120 ( V_2 , & V_311 , V_180 ) ;
}
int F_122 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_298 * V_299 = V_178 ;
return F_120 ( V_2 , V_299 , V_180 ) ;
}
T_1 F_123 ( T_1 V_312 , T_1 V_313 )
{
T_1 V_314 ;
switch ( V_312 ) {
case 8 :
V_314 = V_315 ;
break;
case 16 :
if ( V_313 == 15 )
V_314 = V_316 ;
else
V_314 = V_317 ;
break;
case 24 :
V_314 = V_318 ;
break;
case 32 :
if ( V_313 == 24 )
V_314 = V_319 ;
else if ( V_313 == 30 )
V_314 = V_320 ;
else
V_314 = V_321 ;
break;
default:
F_52 ( L_53 ) ;
V_314 = V_319 ;
break;
}
return V_314 ;
}
int F_124 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_322 * V_323 = V_178 ;
struct V_324 V_325 = {} ;
struct V_256 * V_257 = & V_2 -> V_5 ;
struct V_42 * V_43 ;
int V_36 = 0 ;
V_325 . V_190 = V_323 -> V_190 ;
V_325 . V_274 = V_323 -> V_274 ;
V_325 . V_275 = V_323 -> V_275 ;
V_325 . V_326 [ 0 ] = V_323 -> V_327 ;
V_325 . V_273 = F_123 ( V_323 -> V_312 , V_323 -> V_313 ) ;
V_325 . V_328 [ 0 ] = V_323 -> V_305 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
if ( ( V_257 -> V_205 > V_325 . V_274 ) || ( V_325 . V_274 > V_257 -> V_204 ) )
return - V_177 ;
if ( ( V_257 -> V_203 > V_325 . V_275 ) || ( V_325 . V_275 > V_257 -> V_202 ) )
return - V_177 ;
V_43 = V_2 -> V_5 . V_45 -> V_329 ( V_2 , V_180 , & V_325 ) ;
if ( F_125 ( V_43 ) ) {
F_76 ( L_54 ) ;
return F_126 ( V_43 ) ;
}
F_2 ( & V_180 -> V_196 ) ;
V_323 -> V_190 = V_43 -> V_17 . V_18 ;
F_31 ( & V_43 -> V_48 , & V_180 -> V_330 ) ;
F_76 ( L_55 , V_43 -> V_17 . V_18 ) ;
F_6 ( & V_180 -> V_196 ) ;
return V_36 ;
}
static int F_127 ( const struct V_324 * V_325 )
{
T_1 V_31 = V_325 -> V_273 & ~ V_32 ;
switch ( V_31 ) {
case V_315 :
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
case V_316 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_317 :
case V_348 :
case V_318 :
case V_349 :
case V_319 :
case V_350 :
case V_351 :
case V_352 :
case V_321 :
case V_353 :
case V_354 :
case V_355 :
case V_320 :
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
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
return 0 ;
default:
F_76 ( L_56 ,
F_20 ( V_325 -> V_273 ) ) ;
return - V_177 ;
}
}
static int F_128 ( const struct V_324 * V_325 )
{
int V_36 , V_384 , V_385 , V_259 , V_8 ;
V_36 = F_127 ( V_325 ) ;
if ( V_36 ) {
F_76 ( L_57 ,
F_20 ( V_325 -> V_273 ) ) ;
return V_36 ;
}
V_384 = F_129 ( V_325 -> V_273 ) ;
V_385 = F_130 ( V_325 -> V_273 ) ;
V_259 = F_131 ( V_325 -> V_273 ) ;
if ( V_325 -> V_274 == 0 || V_325 -> V_274 % V_384 ) {
F_76 ( L_58 , V_325 -> V_275 ) ;
return - V_177 ;
}
if ( V_325 -> V_275 == 0 || V_325 -> V_275 % V_385 ) {
F_76 ( L_59 , V_325 -> V_275 ) ;
return - V_177 ;
}
for ( V_8 = 0 ; V_8 < V_259 ; V_8 ++ ) {
unsigned int V_274 = V_325 -> V_274 / ( V_8 != 0 ? V_384 : 1 ) ;
unsigned int V_275 = V_325 -> V_275 / ( V_8 != 0 ? V_385 : 1 ) ;
unsigned int V_386 = F_132 ( V_325 -> V_273 , V_8 ) ;
if ( ! V_325 -> V_328 [ V_8 ] ) {
F_76 ( L_60 , V_8 ) ;
return - V_177 ;
}
if ( ( T_3 ) V_274 * V_386 > V_387 )
return - V_174 ;
if ( ( T_3 ) V_275 * V_325 -> V_326 [ V_8 ] + V_325 -> V_388 [ V_8 ] > V_387 )
return - V_174 ;
if ( V_325 -> V_326 [ V_8 ] < V_274 * V_386 ) {
F_76 ( L_61 , V_325 -> V_326 [ V_8 ] , V_8 ) ;
return - V_177 ;
}
}
return 0 ;
}
int F_133 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_324 * V_325 = V_178 ;
struct V_256 * V_257 = & V_2 -> V_5 ;
struct V_42 * V_43 ;
int V_36 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
if ( V_325 -> V_171 & ~ V_389 ) {
F_76 ( L_62 , V_325 -> V_171 ) ;
return - V_177 ;
}
if ( ( V_257 -> V_205 > V_325 -> V_274 ) || ( V_325 -> V_274 > V_257 -> V_204 ) ) {
F_76 ( L_63 ,
V_325 -> V_274 , V_257 -> V_205 , V_257 -> V_204 ) ;
return - V_177 ;
}
if ( ( V_257 -> V_203 > V_325 -> V_275 ) || ( V_325 -> V_275 > V_257 -> V_202 ) ) {
F_76 ( L_64 ,
V_325 -> V_275 , V_257 -> V_203 , V_257 -> V_202 ) ;
return - V_177 ;
}
V_36 = F_128 ( V_325 ) ;
if ( V_36 )
return V_36 ;
V_43 = V_2 -> V_5 . V_45 -> V_329 ( V_2 , V_180 , V_325 ) ;
if ( F_125 ( V_43 ) ) {
F_76 ( L_54 ) ;
return F_126 ( V_43 ) ;
}
F_2 ( & V_180 -> V_196 ) ;
V_325 -> V_190 = V_43 -> V_17 . V_18 ;
F_31 ( & V_43 -> V_48 , & V_180 -> V_330 ) ;
F_76 ( L_55 , V_43 -> V_17 . V_18 ) ;
F_6 ( & V_180 -> V_196 ) ;
return V_36 ;
}
int F_134 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_42 * V_43 = NULL ;
struct V_42 * V_390 = NULL ;
T_1 * V_18 = V_178 ;
int V_391 = 0 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_2 ( & V_180 -> V_196 ) ;
F_2 ( & V_2 -> V_5 . V_46 ) ;
V_43 = F_34 ( V_2 , * V_18 ) ;
if ( ! V_43 )
goto V_392;
F_3 (fbl, &file_priv->fbs, filp_head)
if ( V_43 == V_390 )
V_391 = 1 ;
if ( ! V_391 )
goto V_392;
F_44 ( V_2 , V_43 ) ;
F_135 ( & V_43 -> V_48 ) ;
F_6 ( & V_2 -> V_5 . V_46 ) ;
F_6 ( & V_180 -> V_196 ) ;
F_48 ( V_43 ) ;
return 0 ;
V_392:
F_6 ( & V_2 -> V_5 . V_46 ) ;
F_6 ( & V_180 -> V_196 ) ;
return - V_215 ;
}
int F_136 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_322 * V_325 = V_178 ;
struct V_42 * V_43 ;
int V_36 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
V_43 = F_36 ( V_2 , V_325 -> V_190 ) ;
if ( ! V_43 )
return - V_215 ;
V_325 -> V_275 = V_43 -> V_275 ;
V_325 -> V_274 = V_43 -> V_274 ;
V_325 -> V_313 = V_43 -> V_313 ;
V_325 -> V_312 = V_43 -> V_393 ;
V_325 -> V_327 = V_43 -> V_326 [ 0 ] ;
if ( V_43 -> V_45 -> V_394 ) {
if ( V_180 -> V_395 || F_137 ( V_396 ) ||
F_138 ( V_180 ) ) {
V_36 = V_43 -> V_45 -> V_394 ( V_43 , V_180 ,
& V_325 -> V_305 ) ;
} else {
V_325 -> V_305 = 0 ;
V_36 = 0 ;
}
} else {
V_36 = - V_397 ;
}
F_37 ( V_43 ) ;
return V_36 ;
}
int F_139 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_398 T_2 * V_399 ;
struct V_398 * V_400 = NULL ;
struct V_401 * V_325 = V_178 ;
struct V_42 * V_43 ;
unsigned V_171 ;
int V_402 ;
int V_36 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
V_43 = F_36 ( V_2 , V_325 -> V_190 ) ;
if ( ! V_43 )
return - V_215 ;
V_402 = V_325 -> V_402 ;
V_399 = (struct V_398 T_2 * ) ( unsigned long ) V_325 -> V_399 ;
if ( ! V_402 != ! V_399 ) {
V_36 = - V_177 ;
goto V_403;
}
V_171 = V_404 & V_325 -> V_171 ;
if ( V_171 & V_405 && ( V_402 % 2 ) ) {
V_36 = - V_177 ;
goto V_403;
}
if ( V_402 && V_399 ) {
if ( V_402 < 0 || V_402 > V_406 ) {
V_36 = - V_177 ;
goto V_403;
}
V_400 = F_91 ( V_402 * sizeof( * V_400 ) , V_39 ) ;
if ( ! V_400 ) {
V_36 = - V_102 ;
goto V_403;
}
V_36 = F_140 ( V_400 , V_399 ,
V_402 * sizeof( * V_400 ) ) ;
if ( V_36 ) {
V_36 = - V_199 ;
goto V_407;
}
}
if ( V_43 -> V_45 -> V_408 ) {
V_36 = V_43 -> V_45 -> V_408 ( V_43 , V_180 , V_171 , V_325 -> V_409 ,
V_400 , V_402 ) ;
} else {
V_36 = - V_410 ;
}
V_407:
F_59 ( V_400 ) ;
V_403:
F_37 ( V_43 ) ;
return V_36 ;
}
void F_141 ( struct V_179 * V_411 )
{
struct V_1 * V_2 = V_411 -> V_201 -> V_2 ;
struct V_42 * V_43 , * V_412 ;
F_2 ( & V_411 -> V_196 ) ;
F_66 (fb, tfb, &priv->fbs, filp_head) {
F_2 ( & V_2 -> V_5 . V_46 ) ;
F_44 ( V_2 , V_43 ) ;
F_6 ( & V_2 -> V_5 . V_46 ) ;
F_135 ( & V_43 -> V_48 ) ;
F_48 ( V_43 ) ;
}
F_6 ( & V_411 -> V_196 ) ;
}
struct V_111 * F_81 ( struct V_1 * V_2 , int V_171 ,
const char * V_16 , int V_413 )
{
struct V_111 * V_414 = NULL ;
int V_36 ;
V_414 = F_91 ( sizeof( struct V_111 ) , V_39 ) ;
if ( ! V_414 )
return NULL ;
if ( V_413 ) {
V_414 -> V_249 = F_91 ( sizeof( T_3 ) * V_413 , V_39 ) ;
if ( ! V_414 -> V_249 )
goto V_415;
}
V_36 = F_21 ( V_2 , & V_414 -> V_17 , V_416 ) ;
if ( V_36 )
goto V_415;
V_414 -> V_171 = V_171 ;
V_414 -> V_413 = V_413 ;
F_29 ( & V_414 -> V_417 ) ;
if ( V_16 ) {
strncpy ( V_414 -> V_16 , V_16 , V_418 ) ;
V_414 -> V_16 [ V_418 - 1 ] = '\0' ;
}
F_56 ( & V_414 -> V_51 , & V_2 -> V_5 . V_419 ) ;
return V_414 ;
V_415:
F_59 ( V_414 -> V_249 ) ;
F_59 ( V_414 ) ;
return NULL ;
}
struct V_111 * F_82 ( struct V_1 * V_2 , int V_171 ,
const char * V_16 ,
const struct V_420 * V_421 ,
int V_413 )
{
struct V_111 * V_414 ;
int V_8 , V_36 ;
V_171 |= V_136 ;
V_414 = F_81 ( V_2 , V_171 , V_16 , V_413 ) ;
if ( ! V_414 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_413 ; V_8 ++ ) {
V_36 = F_87 ( V_414 , V_8 ,
V_421 [ V_8 ] . type ,
V_421 [ V_8 ] . V_16 ) ;
if ( V_36 ) {
F_142 ( V_2 , V_414 ) ;
return NULL ;
}
}
return V_414 ;
}
struct V_111 * F_143 ( struct V_1 * V_2 ,
int V_171 , const char * V_16 ,
const struct V_420 * V_421 ,
int V_413 )
{
struct V_111 * V_414 ;
int V_8 , V_36 ;
V_171 |= V_422 ;
V_414 = F_81 ( V_2 , V_171 , V_16 , V_413 ) ;
if ( ! V_414 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_413 ; V_8 ++ ) {
V_36 = F_87 ( V_414 , V_8 ,
V_421 [ V_8 ] . type ,
V_421 [ V_8 ] . V_16 ) ;
if ( V_36 ) {
F_142 ( V_2 , V_414 ) ;
return NULL ;
}
}
return V_414 ;
}
struct V_111 * F_86 ( struct V_1 * V_2 , int V_171 ,
const char * V_16 ,
T_3 V_423 , T_3 V_424 )
{
struct V_111 * V_414 ;
V_171 |= V_425 ;
V_414 = F_81 ( V_2 , V_171 , V_16 , 2 ) ;
if ( ! V_414 )
return NULL ;
V_414 -> V_249 [ 0 ] = V_423 ;
V_414 -> V_249 [ 1 ] = V_424 ;
return V_414 ;
}
int F_87 ( struct V_111 * V_414 , int V_69 ,
T_3 V_426 , const char * V_16 )
{
struct V_427 * V_428 ;
if ( ! ( V_414 -> V_171 & ( V_136 | V_422 ) ) )
return - V_177 ;
if ( ( V_414 -> V_171 & V_422 ) && ( V_426 > 63 ) )
return - V_177 ;
if ( ! F_49 ( & V_414 -> V_417 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( V_428 -> V_426 == V_426 ) {
strncpy ( V_428 -> V_16 , V_16 , V_418 ) ;
V_428 -> V_16 [ V_418 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_428 = F_91 ( sizeof( struct V_427 ) , V_39 ) ;
if ( ! V_428 )
return - V_102 ;
strncpy ( V_428 -> V_16 , V_16 , V_418 ) ;
V_428 -> V_16 [ V_418 - 1 ] = '\0' ;
V_428 -> V_426 = V_426 ;
V_414 -> V_249 [ V_69 ] = V_426 ;
F_56 ( & V_428 -> V_51 , & V_414 -> V_417 ) ;
return 0 ;
}
void F_142 ( struct V_1 * V_2 , struct V_111 * V_414 )
{
struct V_427 * V_428 , * V_429 ;
F_66 (prop_enum, pt, &property->enum_blob_list, head) {
F_47 ( & V_428 -> V_51 ) ;
F_59 ( V_428 ) ;
}
if ( V_414 -> V_413 )
F_59 ( V_414 -> V_249 ) ;
F_23 ( V_2 , & V_414 -> V_17 ) ;
F_47 ( & V_414 -> V_51 ) ;
F_59 ( V_414 ) ;
}
void F_64 ( struct V_33 * V_34 ,
struct V_111 * V_414 ,
T_3 V_430 )
{
int V_232 = V_34 -> V_64 -> V_232 ;
if ( V_232 == V_431 ) {
F_94 ( 1 , L_65
L_66
L_67 ,
V_34 -> type ) ;
return;
}
V_34 -> V_64 -> V_248 [ V_232 ] = V_414 -> V_17 . V_18 ;
V_34 -> V_64 -> V_249 [ V_232 ] = V_430 ;
V_34 -> V_64 -> V_232 ++ ;
}
int F_144 ( struct V_33 * V_34 ,
struct V_111 * V_414 , T_3 V_432 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_34 -> V_64 -> V_232 ; V_8 ++ ) {
if ( V_34 -> V_64 -> V_248 [ V_8 ] == V_414 -> V_17 . V_18 ) {
V_34 -> V_64 -> V_249 [ V_8 ] = V_432 ;
return 0 ;
}
}
return - V_177 ;
}
int F_145 ( struct V_33 * V_34 ,
struct V_111 * V_414 , T_3 * V_432 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_34 -> V_64 -> V_232 ; V_8 ++ ) {
if ( V_34 -> V_64 -> V_248 [ V_8 ] == V_414 -> V_17 . V_18 ) {
* V_432 = V_34 -> V_64 -> V_249 [ V_8 ] ;
return 0 ;
}
}
return - V_177 ;
}
int F_146 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_33 * V_34 ;
struct V_433 * V_223 = V_178 ;
struct V_111 * V_414 ;
int V_434 = 0 ;
int V_435 = 0 ;
int V_436 = 0 ;
int V_36 = 0 , V_8 ;
int V_189 ;
struct V_427 * V_428 ;
struct V_437 T_2 * V_438 ;
struct V_439 * V_440 ;
T_1 T_2 * V_441 ;
T_3 T_2 * V_442 ;
T_1 T_2 * V_443 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_34 = F_25 ( V_2 , V_223 -> V_444 , V_416 ) ;
if ( ! V_34 ) {
V_36 = - V_215 ;
goto V_445;
}
V_414 = F_147 ( V_34 ) ;
if ( V_414 -> V_171 & ( V_136 | V_422 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head)
V_434 ++ ;
} else if ( V_414 -> V_171 & V_114 ) {
F_3 (prop_blob, &property->enum_blob_list, head)
V_435 ++ ;
}
V_436 = V_414 -> V_413 ;
strncpy ( V_223 -> V_16 , V_414 -> V_16 , V_418 ) ;
V_223 -> V_16 [ V_418 - 1 ] = 0 ;
V_223 -> V_171 = V_414 -> V_171 ;
if ( ( V_223 -> V_446 >= V_436 ) && V_436 ) {
V_442 = ( T_3 T_2 * ) ( unsigned long ) V_223 -> V_442 ;
for ( V_8 = 0 ; V_8 < V_436 ; V_8 ++ ) {
if ( F_107 ( V_442 + V_8 , & V_414 -> V_249 [ V_8 ] , sizeof( T_3 ) ) ) {
V_36 = - V_199 ;
goto V_445;
}
}
}
V_223 -> V_446 = V_436 ;
if ( V_414 -> V_171 & ( V_136 | V_422 ) ) {
if ( ( V_223 -> V_447 >= V_434 ) && V_434 ) {
V_189 = 0 ;
V_438 = (struct V_437 T_2 * ) ( unsigned long ) V_223 -> V_448 ;
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( F_107 ( & V_438 [ V_189 ] . V_426 , & V_428 -> V_426 , sizeof( T_3 ) ) ) {
V_36 = - V_199 ;
goto V_445;
}
if ( F_107 ( & V_438 [ V_189 ] . V_16 ,
& V_428 -> V_16 , V_418 ) ) {
V_36 = - V_199 ;
goto V_445;
}
V_189 ++ ;
}
}
V_223 -> V_447 = V_434 ;
}
if ( V_414 -> V_171 & V_114 ) {
if ( ( V_223 -> V_447 >= V_435 ) && V_435 ) {
V_189 = 0 ;
V_441 = ( T_1 T_2 * ) ( unsigned long ) V_223 -> V_448 ;
V_443 = ( T_1 T_2 * ) ( unsigned long ) V_223 -> V_442 ;
F_3 (prop_blob, &property->enum_blob_list, head) {
if ( F_99 ( V_440 -> V_17 . V_18 , V_441 + V_189 ) ) {
V_36 = - V_199 ;
goto V_445;
}
if ( F_99 ( V_440 -> V_449 , V_443 + V_189 ) ) {
V_36 = - V_199 ;
goto V_445;
}
V_189 ++ ;
}
}
V_223 -> V_447 = V_435 ;
}
V_445:
F_5 ( V_2 ) ;
return V_36 ;
}
static struct V_439 * F_148 ( struct V_1 * V_2 , int V_449 ,
void * V_178 )
{
struct V_439 * V_450 ;
int V_36 ;
if ( ! V_449 || ! V_178 )
return NULL ;
V_450 = F_91 ( sizeof( struct V_439 ) + V_449 , V_39 ) ;
if ( ! V_450 )
return NULL ;
V_36 = F_21 ( V_2 , & V_450 -> V_17 , V_451 ) ;
if ( V_36 ) {
F_59 ( V_450 ) ;
return NULL ;
}
V_450 -> V_449 = V_449 ;
memcpy ( V_450 -> V_178 , V_178 , V_449 ) ;
F_56 ( & V_450 -> V_51 , & V_2 -> V_5 . V_452 ) ;
return V_450 ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_439 * V_450 )
{
F_23 ( V_2 , & V_450 -> V_17 ) ;
F_47 ( & V_450 -> V_51 ) ;
F_59 ( V_450 ) ;
}
int F_150 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_33 * V_34 ;
struct V_453 * V_223 = V_178 ;
struct V_439 * V_450 ;
int V_36 = 0 ;
void T_2 * V_454 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_34 = F_25 ( V_2 , V_223 -> V_455 , V_451 ) ;
if ( ! V_34 ) {
V_36 = - V_215 ;
goto V_445;
}
V_450 = F_151 ( V_34 ) ;
if ( V_223 -> V_449 == V_450 -> V_449 ) {
V_454 = ( void T_2 * ) ( unsigned long ) V_223 -> V_178 ;
if ( F_107 ( V_454 , V_450 -> V_178 , V_450 -> V_449 ) ) {
V_36 = - V_199 ;
goto V_445;
}
}
V_223 -> V_449 = V_450 -> V_449 ;
V_445:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_152 ( struct V_19 * V_20 ,
struct V_112 * V_112 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_36 , V_456 ;
if ( V_20 -> V_78 )
F_149 ( V_2 , V_20 -> V_78 ) ;
if ( ! V_112 ) {
V_20 -> V_78 = NULL ;
V_36 = F_144 ( & V_20 -> V_17 , V_2 -> V_5 . V_83 , 0 ) ;
return V_36 ;
}
V_456 = V_457 * ( 1 + V_112 -> V_458 ) ;
V_20 -> V_78 = F_148 ( V_20 -> V_2 ,
V_456 , V_112 ) ;
if ( ! V_20 -> V_78 )
return - V_177 ;
V_36 = F_144 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_83 ,
V_20 -> V_78 -> V_17 . V_18 ) ;
return V_36 ;
}
static bool F_153 ( struct V_111 * V_414 ,
T_3 V_426 )
{
if ( V_414 -> V_171 & V_115 )
return false ;
if ( V_414 -> V_171 & V_425 ) {
if ( V_426 < V_414 -> V_249 [ 0 ] || V_426 > V_414 -> V_249 [ 1 ] )
return false ;
return true ;
} else if ( V_414 -> V_171 & V_422 ) {
int V_8 ;
T_3 V_459 = 0 ;
for ( V_8 = 0 ; V_8 < V_414 -> V_413 ; V_8 ++ )
V_459 |= ( 1ULL << V_414 -> V_249 [ V_8 ] ) ;
return ! ( V_426 & ~ V_459 ) ;
} else if ( V_414 -> V_171 & V_114 ) {
return true ;
} else {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_414 -> V_413 ; V_8 ++ )
if ( V_414 -> V_249 [ V_8 ] == V_426 )
return true ;
return false ;
}
}
int F_154 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_460 * V_461 = V_178 ;
struct V_462 V_463 = {
. V_426 = V_461 -> V_426 ,
. V_444 = V_461 -> V_444 ,
. V_464 = V_461 -> V_192 ,
. V_35 = V_75
} ;
return F_155 ( V_2 , & V_463 , V_180 ) ;
}
static int F_156 ( struct V_33 * V_34 ,
struct V_111 * V_414 ,
T_3 V_426 )
{
int V_36 = - V_177 ;
struct V_19 * V_20 = F_106 ( V_34 ) ;
if ( V_414 == V_20 -> V_2 -> V_5 . V_84 ) {
if ( V_20 -> V_45 -> V_113 )
(* V_20 -> V_45 -> V_113 )( V_20 , ( int ) V_426 ) ;
V_36 = 0 ;
} else if ( V_20 -> V_45 -> V_465 )
V_36 = V_20 -> V_45 -> V_465 ( V_20 , V_414 , V_426 ) ;
if ( ! V_36 )
F_144 ( & V_20 -> V_17 , V_414 , V_426 ) ;
return V_36 ;
}
static int F_157 ( struct V_33 * V_34 ,
struct V_111 * V_414 ,
T_3 V_426 )
{
int V_36 = - V_177 ;
struct V_3 * V_4 = F_102 ( V_34 ) ;
if ( V_4 -> V_45 -> V_465 )
V_36 = V_4 -> V_45 -> V_465 ( V_4 , V_414 , V_426 ) ;
if ( ! V_36 )
F_144 ( V_34 , V_414 , V_426 ) ;
return V_36 ;
}
static int F_158 ( struct V_33 * V_34 ,
struct V_111 * V_414 ,
T_3 V_426 )
{
int V_36 = - V_177 ;
struct V_55 * V_56 = F_112 ( V_34 ) ;
if ( V_56 -> V_45 -> V_465 )
V_36 = V_56 -> V_45 -> V_465 ( V_56 , V_414 , V_426 ) ;
if ( ! V_36 )
F_144 ( V_34 , V_414 , V_426 ) ;
return V_36 ;
}
int F_159 ( struct V_1 * V_2 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_466 * V_467 = V_178 ;
struct V_33 * V_34 ;
int V_36 = 0 ;
int V_8 ;
int V_189 = 0 ;
int V_225 = 0 ;
T_1 T_2 * V_246 ;
T_3 T_2 * V_247 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_34 = F_25 ( V_2 , V_467 -> V_464 , V_467 -> V_35 ) ;
if ( ! V_34 ) {
V_36 = - V_215 ;
goto V_49;
}
if ( ! V_34 -> V_64 ) {
V_36 = - V_177 ;
goto V_49;
}
V_225 = V_34 -> V_64 -> V_232 ;
if ( ( V_467 -> V_245 >= V_225 ) && V_225 ) {
V_189 = 0 ;
V_246 = ( T_1 T_2 * ) ( unsigned long ) ( V_467 -> V_246 ) ;
V_247 = ( T_3 T_2 * ) ( unsigned long )
( V_467 -> V_247 ) ;
for ( V_8 = 0 ; V_8 < V_225 ; V_8 ++ ) {
if ( F_99 ( V_34 -> V_64 -> V_248 [ V_8 ] ,
V_246 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
if ( F_99 ( V_34 -> V_64 -> V_249 [ V_8 ] ,
V_247 + V_189 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_189 ++ ;
}
}
V_467 -> V_245 = V_225 ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_155 ( struct V_1 * V_2 , void * V_178 ,
struct V_179 * V_180 )
{
struct V_462 * V_467 = V_178 ;
struct V_33 * V_468 ;
struct V_33 * V_469 ;
struct V_111 * V_414 ;
int V_36 = - V_177 ;
int V_8 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_468 = F_25 ( V_2 , V_467 -> V_464 , V_467 -> V_35 ) ;
if ( ! V_468 ) {
V_36 = - V_215 ;
goto V_49;
}
if ( ! V_468 -> V_64 )
goto V_49;
for ( V_8 = 0 ; V_8 < V_468 -> V_64 -> V_232 ; V_8 ++ )
if ( V_468 -> V_64 -> V_248 [ V_8 ] == V_467 -> V_444 )
break;
if ( V_8 == V_468 -> V_64 -> V_232 )
goto V_49;
V_469 = F_25 ( V_2 , V_467 -> V_444 ,
V_416 ) ;
if ( ! V_469 ) {
V_36 = - V_215 ;
goto V_49;
}
V_414 = F_147 ( V_469 ) ;
if ( ! F_153 ( V_414 , V_467 -> V_426 ) )
goto V_49;
switch ( V_468 -> type ) {
case V_75 :
V_36 = F_156 ( V_468 , V_414 ,
V_467 -> V_426 ) ;
break;
case V_63 :
V_36 = F_157 ( V_468 , V_414 , V_467 -> V_426 ) ;
break;
case V_100 :
V_36 = F_158 ( V_468 , V_414 , V_467 -> V_426 ) ;
break;
}
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_160 ( struct V_19 * V_20 ,
struct V_11 * V_12 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_233 ; V_8 ++ ) {
if ( V_20 -> V_234 [ V_8 ] == 0 ) {
V_20 -> V_234 [ V_8 ] = V_12 -> V_17 . V_18 ;
return 0 ;
}
}
return - V_102 ;
}
int F_161 ( struct V_3 * V_4 ,
int V_218 )
{
V_4 -> V_218 = V_218 ;
V_4 -> V_68 = F_91 ( V_218 * sizeof( V_470 ) * 3 , V_39 ) ;
if ( ! V_4 -> V_68 ) {
V_4 -> V_218 = 0 ;
return - V_102 ;
}
return 0 ;
}
int F_162 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_471 * V_472 = V_178 ;
struct V_33 * V_34 ;
struct V_3 * V_4 ;
void * V_473 , * V_474 , * V_475 ;
int V_456 ;
int V_36 = 0 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_34 = F_25 ( V_2 , V_472 -> V_191 , V_63 ) ;
if ( ! V_34 ) {
V_36 = - V_215 ;
goto V_49;
}
V_4 = F_102 ( V_34 ) ;
if ( V_4 -> V_45 -> V_476 == NULL ) {
V_36 = - V_410 ;
goto V_49;
}
if ( V_472 -> V_218 != V_4 -> V_218 ) {
V_36 = - V_177 ;
goto V_49;
}
V_456 = V_472 -> V_218 * ( sizeof( V_470 ) ) ;
V_473 = V_4 -> V_68 ;
if ( F_140 ( V_473 , ( void T_2 * ) ( unsigned long ) V_472 -> V_477 , V_456 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_474 = V_473 + V_456 ;
if ( F_140 ( V_474 , ( void T_2 * ) ( unsigned long ) V_472 -> V_478 , V_456 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_475 = V_474 + V_456 ;
if ( F_140 ( V_475 , ( void T_2 * ) ( unsigned long ) V_472 -> V_479 , V_456 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_4 -> V_45 -> V_476 ( V_4 , V_473 , V_474 , V_475 , 0 , V_4 -> V_218 ) ;
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_163 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_471 * V_472 = V_178 ;
struct V_33 * V_34 ;
struct V_3 * V_4 ;
void * V_473 , * V_474 , * V_475 ;
int V_456 ;
int V_36 = 0 ;
if ( ! F_97 ( V_2 , V_195 ) )
return - V_177 ;
F_1 ( V_2 ) ;
V_34 = F_25 ( V_2 , V_472 -> V_191 , V_63 ) ;
if ( ! V_34 ) {
V_36 = - V_215 ;
goto V_49;
}
V_4 = F_102 ( V_34 ) ;
if ( V_472 -> V_218 != V_4 -> V_218 ) {
V_36 = - V_177 ;
goto V_49;
}
V_456 = V_472 -> V_218 * ( sizeof( V_470 ) ) ;
V_473 = V_4 -> V_68 ;
if ( F_107 ( ( void T_2 * ) ( unsigned long ) V_472 -> V_477 , V_473 , V_456 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_474 = V_473 + V_456 ;
if ( F_107 ( ( void T_2 * ) ( unsigned long ) V_472 -> V_478 , V_474 , V_456 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_475 = V_474 + V_456 ;
if ( F_107 ( ( void T_2 * ) ( unsigned long ) V_472 -> V_479 , V_475 , V_456 ) ) {
V_36 = - V_199 ;
goto V_49;
}
V_49:
F_5 ( V_2 ) ;
return V_36 ;
}
int F_164 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_480 * V_481 = V_178 ;
struct V_33 * V_34 ;
struct V_3 * V_4 ;
struct V_42 * V_43 = NULL , * V_270 = NULL ;
struct V_482 * V_483 = NULL ;
unsigned long V_171 ;
int V_36 = - V_177 ;
if ( V_481 -> V_171 & ~ V_484 ||
V_481 -> V_485 != 0 )
return - V_177 ;
if ( ( V_481 -> V_171 & V_486 ) && ! V_2 -> V_5 . V_487 )
return - V_177 ;
V_34 = F_25 ( V_2 , V_481 -> V_191 , V_63 ) ;
if ( ! V_34 )
return - V_215 ;
V_4 = F_102 ( V_34 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_59 -> V_43 == NULL ) {
V_36 = - V_488 ;
goto V_49;
}
if ( V_4 -> V_45 -> V_481 == NULL )
goto V_49;
V_43 = F_36 ( V_2 , V_481 -> V_190 ) ;
if ( ! V_43 ) {
V_36 = - V_215 ;
goto V_49;
}
V_36 = F_114 ( V_4 , V_4 -> V_216 , V_4 -> V_217 , & V_4 -> V_72 , V_43 ) ;
if ( V_36 )
goto V_49;
if ( V_4 -> V_59 -> V_43 -> V_273 != V_43 -> V_273 ) {
F_76 ( L_68 ) ;
V_36 = - V_177 ;
goto V_49;
}
if ( V_481 -> V_171 & V_489 ) {
V_36 = - V_102 ;
F_165 ( & V_2 -> V_490 , V_171 ) ;
if ( V_180 -> V_491 < sizeof V_483 -> V_492 ) {
F_166 ( & V_2 -> V_490 , V_171 ) ;
goto V_49;
}
V_180 -> V_491 -= sizeof V_483 -> V_492 ;
F_166 ( & V_2 -> V_490 , V_171 ) ;
V_483 = F_91 ( sizeof *V_483 , V_39 ) ;
if ( V_483 == NULL ) {
F_165 ( & V_2 -> V_490 , V_171 ) ;
V_180 -> V_491 += sizeof V_483 -> V_492 ;
F_166 ( & V_2 -> V_490 , V_171 ) ;
goto V_49;
}
V_483 -> V_492 . V_17 . type = V_493 ;
V_483 -> V_492 . V_17 . V_449 = sizeof V_483 -> V_492 ;
V_483 -> V_492 . V_494 = V_481 -> V_494 ;
V_483 -> V_17 . V_492 = & V_483 -> V_492 . V_17 ;
V_483 -> V_17 . V_180 = V_180 ;
V_483 -> V_17 . V_54 =
( void ( * ) ( struct V_495 * ) ) F_59 ;
}
V_270 = V_4 -> V_59 -> V_43 ;
V_36 = V_4 -> V_45 -> V_481 ( V_4 , V_43 , V_483 , V_481 -> V_171 ) ;
if ( V_36 ) {
if ( V_481 -> V_171 & V_489 ) {
F_165 ( & V_2 -> V_490 , V_171 ) ;
V_180 -> V_491 += sizeof V_483 -> V_492 ;
F_166 ( & V_2 -> V_490 , V_171 ) ;
F_59 ( V_483 ) ;
}
V_270 = NULL ;
} else {
F_8 ( V_4 -> V_59 -> V_43 != V_43 ) ;
V_43 = NULL ;
}
V_49:
if ( V_43 )
F_37 ( V_43 ) ;
if ( V_270 )
F_37 ( V_270 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_36 ;
}
void F_167 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_19 * V_20 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
if ( V_4 -> V_45 -> V_496 )
V_4 -> V_45 -> V_496 ( V_4 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
if ( V_12 -> V_45 -> V_496 )
V_12 -> V_45 -> V_496 ( V_12 ) ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_20 -> V_24 = V_79 ;
if ( V_20 -> V_45 -> V_496 )
V_20 -> V_45 -> V_496 ( V_20 ) ;
}
}
int F_168 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_497 * args = V_178 ;
T_4 V_386 , V_498 , V_456 ;
if ( ! V_2 -> V_499 -> V_500 )
return - V_410 ;
if ( ! args -> V_274 || ! args -> V_275 || ! args -> V_312 )
return - V_177 ;
V_386 = F_169 ( args -> V_312 , 8 ) ;
if ( V_386 > 0xffffffffU / args -> V_274 )
return - V_177 ;
V_498 = V_386 * args -> V_274 ;
if ( args -> V_275 > 0xffffffffU / V_498 )
return - V_177 ;
V_456 = args -> V_275 * V_498 ;
if ( F_170 ( V_456 ) == 0 )
return - V_177 ;
return V_2 -> V_499 -> V_500 ( V_180 , V_2 , args ) ;
}
int F_171 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_501 * args = V_178 ;
if ( ! V_2 -> V_499 -> V_502 )
return - V_410 ;
return V_2 -> V_499 -> V_502 ( V_180 , V_2 , args -> V_305 , & args -> V_503 ) ;
}
int F_172 ( struct V_1 * V_2 ,
void * V_178 , struct V_179 * V_180 )
{
struct V_504 * args = V_178 ;
if ( ! V_2 -> V_499 -> V_505 )
return - V_410 ;
return V_2 -> V_499 -> V_505 ( V_180 , V_2 , args -> V_305 ) ;
}
void F_173 ( T_1 V_31 , unsigned int * V_313 ,
int * V_312 )
{
switch ( V_31 ) {
case V_315 :
case V_331 :
case V_332 :
* V_313 = 8 ;
* V_312 = 8 ;
break;
case V_316 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
* V_313 = 15 ;
* V_312 = 16 ;
break;
case V_317 :
case V_348 :
* V_313 = 16 ;
* V_312 = 16 ;
break;
case V_318 :
case V_349 :
* V_313 = 24 ;
* V_312 = 24 ;
break;
case V_319 :
case V_350 :
case V_351 :
case V_352 :
* V_313 = 24 ;
* V_312 = 32 ;
break;
case V_320 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
* V_313 = 30 ;
* V_312 = 32 ;
break;
case V_321 :
case V_353 :
case V_354 :
case V_355 :
* V_313 = 32 ;
* V_312 = 32 ;
break;
default:
F_76 ( L_69 ,
F_20 ( V_31 ) ) ;
* V_313 = 0 ;
* V_312 = 0 ;
break;
}
}
int F_131 ( T_1 V_31 )
{
switch ( V_31 ) {
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
return 3 ;
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
return 2 ;
default:
return 1 ;
}
}
int F_132 ( T_1 V_31 , int V_56 )
{
unsigned int V_313 ;
int V_312 ;
if ( V_56 >= F_131 ( V_31 ) )
return 0 ;
switch ( V_31 ) {
case V_363 :
case V_364 :
case V_365 :
case V_366 :
return 2 ;
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
return V_56 ? 2 : 1 ;
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
return 1 ;
default:
F_173 ( V_31 , & V_313 , & V_312 ) ;
return V_312 >> 3 ;
}
}
int F_129 ( T_1 V_31 )
{
switch ( V_31 ) {
case V_376 :
case V_377 :
case V_374 :
case V_375 :
return 4 ;
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_380 :
case V_381 :
case V_378 :
case V_379 :
return 2 ;
default:
return 1 ;
}
}
int F_130 ( T_1 V_31 )
{
switch ( V_31 ) {
case V_374 :
case V_375 :
return 4 ;
case V_378 :
case V_379 :
case V_368 :
case V_369 :
return 2 ;
default:
return 1 ;
}
}
void F_174 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_5 . V_6 ) ;
F_55 ( & V_2 -> V_5 . V_37 ) ;
F_55 ( & V_2 -> V_5 . V_46 ) ;
F_29 ( & V_2 -> V_5 . V_52 ) ;
F_29 ( & V_2 -> V_5 . V_65 ) ;
F_29 ( & V_2 -> V_5 . V_80 ) ;
F_29 ( & V_2 -> V_5 . V_90 ) ;
F_29 ( & V_2 -> V_5 . V_94 ) ;
F_29 ( & V_2 -> V_5 . V_419 ) ;
F_29 ( & V_2 -> V_5 . V_452 ) ;
F_29 ( & V_2 -> V_5 . V_103 ) ;
F_175 ( & V_2 -> V_5 . V_38 ) ;
F_1 ( V_2 ) ;
F_80 ( V_2 ) ;
F_83 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_5 . V_50 = 0 ;
V_2 -> V_5 . V_81 = 0 ;
V_2 -> V_5 . V_66 = 0 ;
V_2 -> V_5 . V_95 = 0 ;
V_2 -> V_5 . V_106 = 0 ;
V_2 -> V_5 . V_104 = 0 ;
}
void F_176 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_506 ;
struct V_3 * V_4 , * V_507 ;
struct V_11 * V_12 , * V_508 ;
struct V_86 * V_87 , * V_509 ;
struct V_42 * V_43 , * V_510 ;
struct V_111 * V_414 , * V_429 ;
struct V_439 * V_450 , * V_511 ;
struct V_55 * V_56 , * V_512 ;
F_66 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_12 -> V_45 -> V_54 ( V_12 ) ;
}
F_66 (bridge, brt,
&dev->mode_config.bridge_list, head) {
V_87 -> V_45 -> V_54 ( V_87 ) ;
}
F_66 (connector, ot,
&dev->mode_config.connector_list, head) {
V_20 -> V_45 -> V_54 ( V_20 ) ;
}
F_66 (property, pt, &dev->mode_config.property_list,
head) {
F_142 ( V_2 , V_414 ) ;
}
F_66 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_149 ( V_2 , V_450 ) ;
}
F_8 ( ! F_49 ( & V_2 -> V_5 . V_52 ) ) ;
F_66 (fb, fbt, &dev->mode_config.fb_list, head) {
F_48 ( V_43 ) ;
}
F_66 (plane, plt, &dev->mode_config.plane_list,
head) {
V_56 -> V_45 -> V_54 ( V_56 ) ;
}
F_66 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_4 -> V_45 -> V_54 ( V_4 ) ;
}
F_177 ( & V_2 -> V_5 . V_38 ) ;
}
