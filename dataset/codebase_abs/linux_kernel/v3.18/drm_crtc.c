void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_3 ( & V_2 [ V_1 ] . V_3 ) ;
}
void F_4 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_5 ( & V_2 [ V_1 ] . V_3 ) ;
}
const char * F_6 ( enum V_4 V_5 )
{
if ( V_5 == V_6 )
return L_1 ;
else if ( V_5 == V_7 )
return L_2 ;
else
return L_3 ;
}
const char * F_7 ( enum V_8 V_9 )
{
return V_10 [ V_9 ] . V_11 ;
}
static char F_8 ( int V_12 )
{
return isascii ( V_12 ) && isprint ( V_12 ) ? V_12 : '?' ;
}
const char * F_9 ( T_1 V_13 )
{
static char V_14 [ 32 ] ;
snprintf ( V_14 , sizeof( V_14 ) ,
L_4 ,
F_8 ( V_13 & 0xff ) ,
F_8 ( ( V_13 >> 8 ) & 0xff ) ,
F_8 ( ( V_13 >> 16 ) & 0xff ) ,
F_8 ( ( V_13 >> 24 ) & 0x7f ) ,
V_13 & V_15 ? L_5 : L_6 ,
V_13 ) ;
return V_14 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
T_1 V_20 ,
bool V_21 )
{
int V_22 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_22 = F_12 ( & V_17 -> V_23 . V_25 , V_21 ? V_19 : NULL , 1 , 0 , V_26 ) ;
if ( V_22 >= 0 ) {
V_19 -> V_27 = V_22 ;
V_19 -> type = V_20 ;
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_22 < 0 ? V_22 : 0 ;
}
int F_14 ( struct V_16 * V_17 ,
struct V_18 * V_19 , T_1 V_20 )
{
return F_10 ( V_17 , V_19 , V_20 , true ) ;
}
static void F_15 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_16 ( & V_17 -> V_23 . V_25 , V_19 , V_19 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
}
void F_17 ( struct V_16 * V_17 ,
struct V_18 * V_28 )
{
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_25 , V_28 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
}
static struct V_18 * F_19 ( struct V_16 * V_17 ,
T_1 V_27 , T_1 type )
{
struct V_18 * V_19 = NULL ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_19 = F_20 ( & V_17 -> V_23 . V_25 , V_27 ) ;
if ( V_19 && type != V_29 && V_19 -> type != type )
V_19 = NULL ;
if ( V_19 && V_19 -> V_27 != V_27 )
V_19 = NULL ;
if ( V_19 && ( V_19 -> type == V_30 ) )
V_19 = NULL ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_19 ;
}
struct V_18 * F_21 ( struct V_16 * V_17 ,
T_1 V_27 , T_1 type )
{
struct V_18 * V_19 = NULL ;
F_22 ( type == V_30 ) ;
V_19 = F_19 ( V_17 , V_27 , type ) ;
return V_19 ;
}
int F_23 ( struct V_16 * V_17 , struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
int V_22 ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
F_24 ( & V_32 -> V_36 ) ;
F_25 ( & V_32 -> V_37 ) ;
V_32 -> V_17 = V_17 ;
V_32 -> V_34 = V_34 ;
V_22 = F_14 ( V_17 , & V_32 -> V_38 , V_30 ) ;
if ( V_22 )
goto V_39;
V_17 -> V_23 . V_40 ++ ;
F_26 ( & V_32 -> V_41 , & V_17 -> V_23 . V_42 ) ;
V_39:
F_13 ( & V_17 -> V_23 . V_35 ) ;
return 0 ;
}
static void F_27 ( struct V_16 * V_17 ,
struct V_31 * V_32 )
{
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_25 , V_32 -> V_38 . V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
V_32 -> V_38 . V_27 = 0 ;
}
static void F_28 ( struct V_43 * V_43 )
{
struct V_31 * V_32 =
F_29 ( V_43 , struct V_31 , V_36 ) ;
struct V_16 * V_17 = V_32 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
if ( V_32 -> V_38 . V_27 ) {
F_27 ( V_17 , V_32 ) ;
}
F_13 ( & V_17 -> V_23 . V_35 ) ;
V_32 -> V_34 -> V_44 ( V_32 ) ;
}
static struct V_31 * F_30 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_18 * V_19 = NULL ;
struct V_31 * V_32 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_19 = F_20 ( & V_17 -> V_23 . V_25 , V_27 ) ;
if ( ! V_19 || ( V_19 -> type != V_30 ) || ( V_19 -> V_27 != V_27 ) )
V_32 = NULL ;
else
V_32 = F_31 ( V_19 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_32 ;
}
struct V_31 * F_32 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_31 * V_32 ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
V_32 = F_30 ( V_17 , V_27 ) ;
if ( V_32 ) {
if ( ! F_33 ( & V_32 -> V_36 ) )
V_32 = NULL ;
}
F_13 ( & V_17 -> V_23 . V_35 ) ;
return V_32 ;
}
void F_34 ( struct V_31 * V_32 )
{
F_35 ( L_7 , V_32 , V_32 -> V_38 . V_27 , F_36 ( & V_32 -> V_36 . V_36 ) ) ;
F_37 ( & V_32 -> V_36 , F_28 ) ;
}
void F_38 ( struct V_31 * V_32 )
{
F_35 ( L_7 , V_32 , V_32 -> V_38 . V_27 , F_36 ( & V_32 -> V_36 . V_36 ) ) ;
F_39 ( & V_32 -> V_36 ) ;
}
static void F_40 ( struct V_43 * V_43 )
{
F_41 () ;
}
static void F_42 ( struct V_31 * V_32 )
{
F_35 ( L_7 , V_32 , V_32 -> V_38 . V_27 , F_36 ( & V_32 -> V_36 . V_36 ) ) ;
F_37 ( & V_32 -> V_36 , F_40 ) ;
}
void F_43 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
F_27 ( V_17 , V_32 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
}
void F_44 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
F_45 ( & V_32 -> V_41 ) ;
V_17 -> V_23 . V_40 -- ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
}
void F_46 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_17 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 V_50 ;
int V_22 ;
F_22 ( ! F_47 ( & V_32 -> V_37 ) ) ;
if ( F_36 ( & V_32 -> V_36 . V_36 ) > 1 ) {
F_48 ( V_17 ) ;
F_49 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_46 -> V_51 -> V_32 == V_32 ) {
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_46 = V_46 ;
V_50 . V_32 = NULL ;
V_22 = F_50 ( & V_50 ) ;
if ( V_22 )
F_51 ( L_8 , V_46 ) ;
}
}
F_49 (plane, &dev->mode_config.plane_list, head) {
if ( V_48 -> V_32 == V_32 )
F_52 ( V_48 ) ;
}
F_53 ( V_17 ) ;
}
F_34 ( V_32 ) ;
}
int F_54 ( struct V_16 * V_17 , struct V_45 * V_46 ,
struct V_47 * V_51 ,
struct V_47 * V_52 ,
const struct V_53 * V_34 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
int V_22 ;
V_46 -> V_17 = V_17 ;
V_46 -> V_34 = V_34 ;
V_46 -> V_56 = false ;
F_55 ( & V_46 -> V_57 ) ;
V_22 = F_14 ( V_17 , & V_46 -> V_38 , V_58 ) ;
if ( V_22 )
goto V_39;
V_46 -> V_38 . V_59 = & V_46 -> V_59 ;
F_56 ( & V_46 -> V_41 , & V_55 -> V_60 ) ;
V_55 -> V_61 ++ ;
V_46 -> V_51 = V_51 ;
V_46 -> V_52 = V_52 ;
if ( V_51 )
V_51 -> V_62 = 1 << F_57 ( V_46 ) ;
if ( V_52 )
V_52 -> V_62 = 1 << F_57 ( V_46 ) ;
V_39:
return V_22 ;
}
void F_58 ( struct V_45 * V_46 )
{
struct V_16 * V_17 = V_46 -> V_17 ;
F_59 ( V_46 -> V_63 ) ;
V_46 -> V_63 = NULL ;
F_60 ( & V_46 -> V_57 ) ;
F_17 ( V_17 , & V_46 -> V_38 ) ;
F_45 ( & V_46 -> V_41 ) ;
V_17 -> V_23 . V_61 -- ;
}
unsigned int F_57 ( struct V_45 * V_46 )
{
unsigned int V_64 = 0 ;
struct V_45 * V_65 ;
F_49 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_65 == V_46 )
return V_64 ;
V_64 ++ ;
}
F_41 () ;
}
static void F_61 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
F_45 ( & V_69 -> V_41 ) ;
F_62 ( V_67 -> V_17 , V_69 ) ;
}
static void F_63 ( struct V_66 * V_67 )
{
struct V_70 * V_69 = & V_67 -> V_71 ;
char * V_72 = NULL ;
if ( F_64 ( V_67 -> V_11 , & V_72 ) )
return;
if ( ! F_65 ( V_72 ,
V_67 ,
V_69 ) )
return;
if ( V_69 -> V_73 ) {
const char * V_74 ;
switch ( V_69 -> V_73 ) {
case V_75 :
V_74 = L_9 ;
break;
case V_76 :
V_74 = L_10 ;
break;
default:
case V_77 :
V_74 = L_11 ;
break;
}
F_66 ( L_12 , V_67 -> V_11 , V_74 ) ;
V_67 -> V_73 = V_69 -> V_73 ;
}
F_67 ( L_13 ,
V_67 -> V_11 ,
V_69 -> V_78 , V_69 -> V_79 ,
V_69 -> V_80 ? V_69 -> V_81 : 60 ,
V_69 -> V_82 ? L_14 : L_15 ,
V_69 -> V_83 ? L_16 : L_15 ,
V_69 -> V_84 ? L_17 : L_15 ) ;
}
int F_68 ( struct V_16 * V_17 ,
struct V_66 * V_67 ,
const struct V_85 * V_34 ,
int V_86 )
{
int V_22 ;
struct V_3 * V_87 =
& V_2 [ V_86 ] . V_3 ;
F_48 ( V_17 ) ;
V_22 = F_10 ( V_17 , & V_67 -> V_38 , V_88 , false ) ;
if ( V_22 )
goto V_89;
V_67 -> V_38 . V_59 = & V_67 -> V_59 ;
V_67 -> V_17 = V_17 ;
V_67 -> V_34 = V_34 ;
V_67 -> V_86 = V_86 ;
V_67 -> V_90 =
F_69 ( V_87 , 1 , 0 , V_26 ) ;
if ( V_67 -> V_90 < 0 ) {
V_22 = V_67 -> V_90 ;
goto V_91;
}
V_67 -> V_11 =
F_70 ( V_26 , L_18 ,
V_2 [ V_86 ] . V_11 ,
V_67 -> V_90 ) ;
if ( ! V_67 -> V_11 ) {
V_22 = - V_92 ;
goto V_91;
}
F_25 ( & V_67 -> V_93 ) ;
F_25 ( & V_67 -> V_94 ) ;
V_67 -> V_95 = NULL ;
V_67 -> V_5 = V_96 ;
F_63 ( V_67 ) ;
F_56 ( & V_67 -> V_41 , & V_17 -> V_23 . V_97 ) ;
V_17 -> V_23 . V_98 ++ ;
if ( V_86 != V_99 )
F_71 ( & V_67 -> V_38 ,
V_17 -> V_23 . V_100 ,
0 ) ;
F_71 ( & V_67 -> V_38 ,
V_17 -> V_23 . V_101 , 0 ) ;
V_67 -> V_102 = NULL ;
V_91:
if ( V_22 )
F_17 ( V_17 , & V_67 -> V_38 ) ;
V_89:
F_53 ( V_17 ) ;
return V_22 ;
}
void F_72 ( struct V_66 * V_67 )
{
struct V_16 * V_17 = V_67 -> V_17 ;
struct V_68 * V_69 , * V_103 ;
F_73 (mode, t, &connector->probed_modes, head)
F_61 ( V_67 , V_69 ) ;
F_73 (mode, t, &connector->modes, head)
F_61 ( V_67 , V_69 ) ;
F_74 ( & V_2 [ V_67 -> V_86 ] . V_3 ,
V_67 -> V_90 ) ;
F_17 ( V_17 , & V_67 -> V_38 ) ;
F_59 ( V_67 -> V_11 ) ;
V_67 -> V_11 = NULL ;
F_45 ( & V_67 -> V_41 ) ;
V_17 -> V_23 . V_98 -- ;
}
unsigned int F_75 ( struct V_66 * V_67 )
{
unsigned int V_64 = 0 ;
struct V_66 * V_65 ;
F_49 (tmp, &connector->dev->mode_config.connector_list, head) {
if ( V_65 == V_67 )
return V_64 ;
V_64 ++ ;
}
F_41 () ;
}
int F_76 ( struct V_66 * V_67 )
{
int V_22 ;
F_15 ( V_67 -> V_17 , & V_67 -> V_38 ) ;
V_22 = F_77 ( V_67 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_78 ( V_67 ) ;
if ( V_22 ) {
F_79 ( V_67 ) ;
return V_22 ;
}
return 0 ;
}
void F_80 ( struct V_66 * V_67 )
{
F_79 ( V_67 ) ;
F_81 ( V_67 ) ;
}
void F_82 ( struct V_16 * V_17 )
{
struct V_66 * V_67 ;
F_49 (connector, &dev->mode_config.connector_list, head)
F_80 ( V_67 ) ;
}
int F_83 ( struct V_16 * V_17 , struct V_104 * V_105 ,
const struct V_106 * V_34 )
{
int V_22 ;
F_48 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_105 -> V_38 , V_107 ) ;
if ( V_22 )
goto V_39;
V_105 -> V_17 = V_17 ;
V_105 -> V_34 = V_34 ;
F_56 ( & V_105 -> V_41 , & V_17 -> V_23 . V_108 ) ;
V_17 -> V_23 . V_109 ++ ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
void F_84 ( struct V_104 * V_105 )
{
struct V_16 * V_17 = V_105 -> V_17 ;
F_48 ( V_17 ) ;
F_17 ( V_17 , & V_105 -> V_38 ) ;
F_45 ( & V_105 -> V_41 ) ;
V_17 -> V_23 . V_109 -- ;
F_53 ( V_17 ) ;
}
int F_85 ( struct V_16 * V_17 ,
struct V_110 * V_111 ,
const struct V_112 * V_34 ,
int V_113 )
{
int V_22 ;
F_48 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_111 -> V_38 , V_114 ) ;
if ( V_22 )
goto V_89;
V_111 -> V_17 = V_17 ;
V_111 -> V_113 = V_113 ;
V_111 -> V_34 = V_34 ;
V_111 -> V_11 = F_70 ( V_26 , L_18 ,
V_115 [ V_113 ] . V_11 ,
V_111 -> V_38 . V_27 ) ;
if ( ! V_111 -> V_11 ) {
V_22 = - V_92 ;
goto V_91;
}
F_56 ( & V_111 -> V_41 , & V_17 -> V_23 . V_116 ) ;
V_17 -> V_23 . V_117 ++ ;
V_91:
if ( V_22 )
F_17 ( V_17 , & V_111 -> V_38 ) ;
V_89:
F_53 ( V_17 ) ;
return V_22 ;
}
void F_86 ( struct V_110 * V_111 )
{
struct V_16 * V_17 = V_111 -> V_17 ;
F_48 ( V_17 ) ;
F_17 ( V_17 , & V_111 -> V_38 ) ;
F_59 ( V_111 -> V_11 ) ;
V_111 -> V_11 = NULL ;
F_45 ( & V_111 -> V_41 ) ;
V_17 -> V_23 . V_117 -- ;
F_53 ( V_17 ) ;
}
int F_87 ( struct V_16 * V_17 , struct V_47 * V_48 ,
unsigned long V_62 ,
const struct V_118 * V_34 ,
const T_1 * V_119 , T_1 V_120 ,
enum V_121 type )
{
int V_22 ;
F_48 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_48 -> V_38 , V_122 ) ;
if ( V_22 )
goto V_39;
V_48 -> V_38 . V_59 = & V_48 -> V_59 ;
V_48 -> V_17 = V_17 ;
V_48 -> V_34 = V_34 ;
V_48 -> V_123 = F_88 ( sizeof( T_1 ) * V_120 ,
V_26 ) ;
if ( ! V_48 -> V_123 ) {
F_67 ( L_19 ) ;
F_17 ( V_17 , & V_48 -> V_38 ) ;
V_22 = - V_92 ;
goto V_39;
}
memcpy ( V_48 -> V_123 , V_119 , V_120 * sizeof( T_1 ) ) ;
V_48 -> V_120 = V_120 ;
V_48 -> V_62 = V_62 ;
V_48 -> type = type ;
F_56 ( & V_48 -> V_41 , & V_17 -> V_23 . V_124 ) ;
V_17 -> V_23 . V_125 ++ ;
if ( V_48 -> type == V_126 )
V_17 -> V_23 . V_127 ++ ;
F_71 ( & V_48 -> V_38 ,
V_17 -> V_23 . V_128 ,
V_48 -> type ) ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_89 ( struct V_16 * V_17 , struct V_47 * V_48 ,
unsigned long V_62 ,
const struct V_118 * V_34 ,
const T_1 * V_119 , T_1 V_120 ,
bool V_129 )
{
enum V_121 type ;
type = V_129 ? V_130 : V_126 ;
return F_87 ( V_17 , V_48 , V_62 , V_34 ,
V_119 , V_120 , type ) ;
}
void F_90 ( struct V_47 * V_48 )
{
struct V_16 * V_17 = V_48 -> V_17 ;
F_48 ( V_17 ) ;
F_59 ( V_48 -> V_123 ) ;
F_17 ( V_17 , & V_48 -> V_38 ) ;
F_91 ( F_47 ( & V_48 -> V_41 ) ) ;
F_45 ( & V_48 -> V_41 ) ;
V_17 -> V_23 . V_125 -- ;
if ( V_48 -> type == V_126 )
V_17 -> V_23 . V_127 -- ;
F_53 ( V_17 ) ;
}
unsigned int F_92 ( struct V_47 * V_48 )
{
unsigned int V_64 = 0 ;
struct V_47 * V_65 ;
F_49 (tmp, &plane->dev->mode_config.plane_list, head) {
if ( V_65 == V_48 )
return V_64 ;
V_64 ++ ;
}
F_41 () ;
}
void F_52 ( struct V_47 * V_48 )
{
int V_22 ;
if ( ! V_48 -> V_32 )
return;
V_48 -> V_131 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_132 ( V_48 ) ;
if ( V_22 ) {
F_51 ( L_20 ) ;
V_48 -> V_131 = NULL ;
return;
}
F_42 ( V_48 -> V_131 ) ;
V_48 -> V_131 = NULL ;
V_48 -> V_32 = NULL ;
V_48 -> V_46 = NULL ;
}
static int F_93 ( struct V_16 * V_17 )
{
struct V_133 * V_134 ;
struct V_133 * V_135 ;
struct V_133 * V_136 ;
V_134 = F_94 ( V_17 , V_137 |
V_138 ,
L_21 , 0 ) ;
V_17 -> V_23 . V_100 = V_134 ;
V_135 = F_95 ( V_17 , 0 ,
L_22 , V_139 ,
F_2 ( V_139 ) ) ;
V_17 -> V_23 . V_101 = V_135 ;
V_136 = F_94 ( V_17 ,
V_137 |
V_138 ,
L_23 , 0 ) ;
V_17 -> V_23 . V_140 = V_136 ;
return 0 ;
}
static int F_96 ( struct V_16 * V_17 )
{
struct V_133 * type ;
type = F_95 ( V_17 , V_138 ,
L_24 , V_141 ,
F_2 ( V_141 ) ) ;
V_17 -> V_23 . V_128 = type ;
return 0 ;
}
int F_97 ( struct V_16 * V_17 )
{
struct V_133 * V_142 ;
struct V_133 * V_143 ;
if ( V_17 -> V_23 . V_144 )
return 0 ;
V_142 =
F_95 ( V_17 , 0 ,
L_25 ,
V_145 ,
F_2 ( V_145 ) ) ;
V_17 -> V_23 . V_144 = V_142 ;
V_143 = F_95 ( V_17 , V_138 ,
L_26 ,
V_146 ,
F_2 ( V_146 ) ) ;
V_17 -> V_23 . V_147 = V_143 ;
return 0 ;
}
int F_98 ( struct V_16 * V_17 , int V_148 ,
char * V_94 [] )
{
struct V_133 * V_149 ;
struct V_133 * V_150 ;
int V_1 ;
if ( V_17 -> V_23 . V_151 )
return 0 ;
V_149 = F_95 ( V_17 , 0 ,
L_25 ,
V_152 ,
F_2 ( V_152 ) ) ;
V_17 -> V_23 . V_151 = V_149 ;
V_150 =
F_95 ( V_17 , V_138 ,
L_26 ,
V_153 ,
F_2 ( V_153 ) ) ;
V_17 -> V_23 . V_154 = V_150 ;
V_17 -> V_23 . V_155 =
F_99 ( V_17 , 0 , L_27 , 0 , 100 ) ;
V_17 -> V_23 . V_156 =
F_99 ( V_17 , 0 , L_28 , 0 , 100 ) ;
V_17 -> V_23 . V_157 =
F_99 ( V_17 , 0 , L_29 , 0 , 100 ) ;
V_17 -> V_23 . V_158 =
F_99 ( V_17 , 0 , L_30 , 0 , 100 ) ;
V_17 -> V_23 . V_159 =
F_94 ( V_17 , V_160 ,
L_31 , V_148 ) ;
for ( V_1 = 0 ; V_1 < V_148 ; V_1 ++ )
F_100 ( V_17 -> V_23 . V_159 , V_1 ,
V_1 , V_94 [ V_1 ] ) ;
V_17 -> V_23 . V_161 =
F_99 ( V_17 , 0 , L_32 , 0 , 100 ) ;
V_17 -> V_23 . V_162 =
F_99 ( V_17 , 0 , L_33 , 0 , 100 ) ;
V_17 -> V_23 . V_163 =
F_99 ( V_17 , 0 , L_34 , 0 , 100 ) ;
V_17 -> V_23 . V_164 =
F_99 ( V_17 , 0 , L_35 , 0 , 100 ) ;
V_17 -> V_23 . V_165 =
F_99 ( V_17 , 0 , L_36 , 0 , 100 ) ;
V_17 -> V_23 . V_166 =
F_99 ( V_17 , 0 , L_37 , 0 , 100 ) ;
return 0 ;
}
int F_101 ( struct V_16 * V_17 )
{
struct V_133 * V_167 ;
if ( V_17 -> V_23 . V_168 )
return 0 ;
V_167 =
F_95 ( V_17 , 0 , L_38 ,
V_169 ,
F_2 ( V_169 ) ) ;
V_17 -> V_23 . V_168 = V_167 ;
return 0 ;
}
int F_102 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_170 )
return 0 ;
V_17 -> V_23 . V_170 =
F_95 ( V_17 , 0 , L_39 ,
V_171 ,
F_2 ( V_171 ) ) ;
if ( V_17 -> V_23 . V_170 == NULL )
return - V_92 ;
return 0 ;
}
int F_103 ( struct V_16 * V_17 )
{
struct V_133 * V_172 ;
if ( V_17 -> V_23 . V_173 )
return 0 ;
V_172 =
F_95 ( V_17 , V_138 ,
L_40 ,
V_174 ,
F_2 ( V_174 ) ) ;
V_17 -> V_23 . V_173 = V_172 ;
return 0 ;
}
static int F_104 ( struct V_16 * V_17 , struct V_175 * V_176 )
{
T_1 V_177 = 0 ;
V_177 += V_17 -> V_23 . V_61 ;
V_177 += V_17 -> V_23 . V_98 ;
V_177 += V_17 -> V_23 . V_117 ;
V_177 += V_17 -> V_23 . V_109 ;
V_176 -> V_178 = F_105 ( V_177 * sizeof( T_1 ) , V_26 ) ;
if ( ! V_176 -> V_178 )
return - V_92 ;
V_176 -> V_179 = 0 ;
V_176 -> V_180 = 0 ;
V_176 -> V_181 = 0 ;
V_176 -> V_182 = 0 ;
return 0 ;
}
void F_106 ( struct V_175 * V_176 )
{
F_59 ( V_176 -> V_178 ) ;
V_176 -> V_178 = NULL ;
}
int F_107 ( struct V_16 * V_17 ,
struct V_175 * V_176 )
{
struct V_45 * V_46 ;
struct V_110 * V_111 ;
struct V_66 * V_67 ;
struct V_104 * V_105 ;
int V_22 ;
if ( ( V_22 = F_104 ( V_17 , V_176 ) ) )
return V_22 ;
F_49 (crtc, &dev->mode_config.crtc_list, head)
V_176 -> V_178 [ V_176 -> V_179 ++ ] = V_46 -> V_38 . V_27 ;
F_49 (encoder, &dev->mode_config.encoder_list, head)
V_176 -> V_178 [ V_176 -> V_179 + V_176 -> V_181 ++ ] =
V_111 -> V_38 . V_27 ;
F_49 (connector, &dev->mode_config.connector_list, head)
V_176 -> V_178 [ V_176 -> V_179 + V_176 -> V_181 +
V_176 -> V_180 ++ ] = V_67 -> V_38 . V_27 ;
F_49 (bridge, &dev->mode_config.bridge_list, head)
V_176 -> V_178 [ V_176 -> V_179 + V_176 -> V_181 +
V_176 -> V_180 + V_176 -> V_182 ++ ] =
V_105 -> V_38 . V_27 ;
return 0 ;
}
void F_108 ( struct V_16 * V_17 )
{
F_48 ( V_17 ) ;
F_106 ( & V_17 -> V_51 -> V_183 ) ;
F_107 ( V_17 , & V_17 -> V_51 -> V_183 ) ;
F_53 ( V_17 ) ;
}
static void F_109 ( struct V_184 * V_39 ,
const struct V_68 * V_185 )
{
F_110 ( V_185 -> V_186 > V_187 || V_185 -> V_188 > V_187 ||
V_185 -> V_189 > V_187 || V_185 -> V_190 > V_187 ||
V_185 -> V_191 > V_187 || V_185 -> V_192 > V_187 ||
V_185 -> V_193 > V_187 || V_185 -> V_194 > V_187 ||
V_185 -> V_195 > V_187 || V_185 -> V_196 > V_187 ,
L_41 ) ;
V_39 -> clock = V_185 -> clock ;
V_39 -> V_186 = V_185 -> V_186 ;
V_39 -> V_188 = V_185 -> V_188 ;
V_39 -> V_189 = V_185 -> V_189 ;
V_39 -> V_190 = V_185 -> V_190 ;
V_39 -> V_191 = V_185 -> V_191 ;
V_39 -> V_192 = V_185 -> V_192 ;
V_39 -> V_193 = V_185 -> V_193 ;
V_39 -> V_194 = V_185 -> V_194 ;
V_39 -> V_195 = V_185 -> V_195 ;
V_39 -> V_196 = V_185 -> V_196 ;
V_39 -> V_197 = V_185 -> V_197 ;
V_39 -> V_198 = V_185 -> V_198 ;
V_39 -> type = V_185 -> type ;
strncpy ( V_39 -> V_11 , V_185 -> V_11 , V_199 ) ;
V_39 -> V_11 [ V_199 - 1 ] = 0 ;
}
static int F_111 ( struct V_68 * V_39 ,
const struct V_184 * V_185 )
{
if ( V_185 -> clock > V_200 || V_185 -> V_197 > V_200 )
return - V_201 ;
if ( ( V_185 -> V_198 & V_202 ) > V_203 )
return - V_204 ;
V_39 -> clock = V_185 -> clock ;
V_39 -> V_186 = V_185 -> V_186 ;
V_39 -> V_188 = V_185 -> V_188 ;
V_39 -> V_189 = V_185 -> V_189 ;
V_39 -> V_190 = V_185 -> V_190 ;
V_39 -> V_191 = V_185 -> V_191 ;
V_39 -> V_192 = V_185 -> V_192 ;
V_39 -> V_193 = V_185 -> V_193 ;
V_39 -> V_194 = V_185 -> V_194 ;
V_39 -> V_195 = V_185 -> V_195 ;
V_39 -> V_196 = V_185 -> V_196 ;
V_39 -> V_197 = V_185 -> V_197 ;
V_39 -> V_198 = V_185 -> V_198 ;
V_39 -> type = V_185 -> type ;
strncpy ( V_39 -> V_11 , V_185 -> V_11 , V_199 ) ;
V_39 -> V_11 [ V_199 - 1 ] = 0 ;
return 0 ;
}
int F_112 ( struct V_16 * V_17 , void * V_205 ,
struct V_206 * V_207 )
{
struct V_208 * V_209 = V_205 ;
struct V_210 * V_211 ;
struct V_31 * V_32 ;
struct V_66 * V_67 ;
struct V_45 * V_46 ;
struct V_110 * V_111 ;
int V_22 = 0 ;
int V_212 = 0 ;
int V_213 = 0 ;
int V_214 = 0 ;
int V_215 = 0 ;
int V_216 = 0 , V_1 ;
T_1 T_2 * V_217 ;
T_1 T_2 * V_218 ;
T_1 T_2 * V_219 ;
T_1 T_2 * V_220 ;
struct V_175 * V_183 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_11 ( & V_207 -> V_222 ) ;
F_114 (lh, &file_priv->fbs)
V_214 ++ ;
if ( V_209 -> V_223 >= V_214 ) {
V_216 = 0 ;
V_217 = ( T_1 T_2 * ) ( unsigned long ) V_209 -> V_224 ;
F_49 (fb, &file_priv->fbs, filp_head) {
if ( F_115 ( V_32 -> V_38 . V_27 , V_217 + V_216 ) ) {
F_13 ( & V_207 -> V_222 ) ;
return - V_225 ;
}
V_216 ++ ;
}
}
V_209 -> V_223 = V_214 ;
F_13 ( & V_207 -> V_222 ) ;
F_48 ( V_17 ) ;
if ( ! F_116 ( V_207 ) ) {
V_183 = NULL ;
F_114 (lh, &dev->mode_config.crtc_list)
V_213 ++ ;
F_114 (lh, &dev->mode_config.connector_list)
V_212 ++ ;
F_114 (lh, &dev->mode_config.encoder_list)
V_215 ++ ;
} else {
V_183 = & V_207 -> V_226 -> V_227 -> V_183 ;
V_213 = V_183 -> V_179 ;
V_212 = V_183 -> V_180 ;
V_215 = V_183 -> V_181 ;
}
V_209 -> V_228 = V_17 -> V_23 . V_228 ;
V_209 -> V_229 = V_17 -> V_23 . V_229 ;
V_209 -> V_230 = V_17 -> V_23 . V_230 ;
V_209 -> V_231 = V_17 -> V_23 . V_231 ;
if ( V_209 -> V_232 >= V_213 ) {
V_216 = 0 ;
V_218 = ( T_1 T_2 * ) ( unsigned long ) V_209 -> V_233 ;
if ( ! V_183 ) {
F_49 (crtc, &dev->mode_config.crtc_list,
head) {
F_67 ( L_42 , V_46 -> V_38 . V_27 ) ;
if ( F_115 ( V_46 -> V_38 . V_27 , V_218 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
} else {
for ( V_1 = 0 ; V_1 < V_183 -> V_179 ; V_1 ++ ) {
if ( F_115 ( V_183 -> V_178 [ V_1 ] ,
V_218 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
}
}
V_209 -> V_232 = V_213 ;
if ( V_209 -> V_234 >= V_215 ) {
V_216 = 0 ;
V_220 = ( T_1 T_2 * ) ( unsigned long ) V_209 -> V_235 ;
if ( ! V_183 ) {
F_49 (encoder,
&dev->mode_config.encoder_list,
head) {
F_67 ( L_43 , V_111 -> V_38 . V_27 ,
V_111 -> V_11 ) ;
if ( F_115 ( V_111 -> V_38 . V_27 , V_220 +
V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
} else {
for ( V_1 = V_183 -> V_179 ; V_1 < V_183 -> V_179 + V_183 -> V_181 ; V_1 ++ ) {
if ( F_115 ( V_183 -> V_178 [ V_1 ] ,
V_220 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
}
}
V_209 -> V_234 = V_215 ;
if ( V_209 -> V_236 >= V_212 ) {
V_216 = 0 ;
V_219 = ( T_1 T_2 * ) ( unsigned long ) V_209 -> V_237 ;
if ( ! V_183 ) {
F_49 (connector,
&dev->mode_config.connector_list,
head) {
F_67 ( L_44 ,
V_67 -> V_38 . V_27 ,
V_67 -> V_11 ) ;
if ( F_115 ( V_67 -> V_38 . V_27 ,
V_219 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
} else {
int V_238 = V_183 -> V_179 +
V_183 -> V_181 ;
for ( V_1 = V_238 ; V_1 < V_238 + V_183 -> V_180 ; V_1 ++ ) {
if ( F_115 ( V_183 -> V_178 [ V_1 ] ,
V_219 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
}
}
V_209 -> V_236 = V_212 ;
F_67 ( L_45 , V_209 -> V_232 ,
V_209 -> V_236 , V_209 -> V_234 ) ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_117 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_239 * V_240 = V_205 ;
struct V_45 * V_46 ;
int V_22 = 0 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_46 = F_118 ( V_17 , V_240 -> V_218 ) ;
if ( ! V_46 ) {
V_22 = - V_241 ;
goto V_39;
}
V_240 -> V_242 = V_46 -> V_242 ;
V_240 -> V_243 = V_46 -> V_243 ;
V_240 -> V_244 = V_46 -> V_244 ;
if ( V_46 -> V_51 -> V_32 )
V_240 -> V_217 = V_46 -> V_51 -> V_32 -> V_38 . V_27 ;
else
V_240 -> V_217 = 0 ;
if ( V_46 -> V_245 ) {
F_109 ( & V_240 -> V_69 , & V_46 -> V_69 ) ;
V_240 -> V_246 = 1 ;
} else {
V_240 -> V_246 = 0 ;
}
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
static bool F_119 ( const struct V_68 * V_69 ,
const struct V_206 * V_207 )
{
if ( ! V_207 -> V_247 && F_120 ( V_69 ) )
return false ;
return true ;
}
int F_121 ( struct V_16 * V_17 , void * V_205 ,
struct V_206 * V_207 )
{
struct V_248 * V_249 = V_205 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
int V_250 = 0 ;
int V_251 = 0 ;
int V_252 = 0 ;
int V_22 = 0 ;
int V_216 = 0 ;
int V_1 ;
struct V_184 V_253 ;
struct V_184 T_2 * V_254 ;
T_1 T_2 * V_255 ;
T_3 T_2 * V_256 ;
T_1 T_2 * V_257 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
memset ( & V_253 , 0 , sizeof( struct V_184 ) ) ;
F_67 ( L_46 , V_249 -> V_219 ) ;
F_11 ( & V_17 -> V_23 . V_57 ) ;
V_67 = F_122 ( V_17 , V_249 -> V_219 ) ;
if ( ! V_67 ) {
V_22 = - V_241 ;
goto V_39;
}
V_251 = V_67 -> V_59 . V_258 ;
for ( V_1 = 0 ; V_1 < V_259 ; V_1 ++ ) {
if ( V_67 -> V_260 [ V_1 ] != 0 ) {
V_252 ++ ;
}
}
if ( V_249 -> V_261 == 0 ) {
V_67 -> V_34 -> V_262 ( V_67 ,
V_17 -> V_23 . V_230 ,
V_17 -> V_23 . V_228 ) ;
}
F_49 (mode, &connector->modes, head)
if ( F_119 ( V_69 , V_207 ) )
V_250 ++ ;
V_249 -> V_219 = V_67 -> V_38 . V_27 ;
V_249 -> V_86 = V_67 -> V_86 ;
V_249 -> V_90 = V_67 -> V_90 ;
V_249 -> V_263 = V_67 -> V_264 . V_265 ;
V_249 -> V_266 = V_67 -> V_264 . V_267 ;
V_249 -> V_268 = V_67 -> V_264 . V_8 ;
V_249 -> V_269 = V_67 -> V_5 ;
F_123 ( & V_17 -> V_23 . V_270 , NULL ) ;
if ( V_67 -> V_111 )
V_249 -> V_220 = V_67 -> V_111 -> V_38 . V_27 ;
else
V_249 -> V_220 = 0 ;
F_124 ( & V_17 -> V_23 . V_270 ) ;
if ( ( V_249 -> V_261 >= V_250 ) && V_250 ) {
V_216 = 0 ;
V_254 = (struct V_184 T_2 * ) ( unsigned long ) V_249 -> V_271 ;
F_49 (mode, &connector->modes, head) {
if ( ! F_119 ( V_69 , V_207 ) )
continue;
F_109 ( & V_253 , V_69 ) ;
if ( F_125 ( V_254 + V_216 ,
& V_253 , sizeof( V_253 ) ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
}
V_249 -> V_261 = V_250 ;
if ( ( V_249 -> V_272 >= V_251 ) && V_251 ) {
V_216 = 0 ;
V_255 = ( T_1 T_2 * ) ( unsigned long ) ( V_249 -> V_273 ) ;
V_256 = ( T_3 T_2 * ) ( unsigned long ) ( V_249 -> V_274 ) ;
for ( V_1 = 0 ; V_1 < V_67 -> V_59 . V_258 ; V_1 ++ ) {
if ( F_115 ( V_67 -> V_59 . V_275 [ V_1 ] ,
V_255 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
if ( F_115 ( V_67 -> V_59 . V_276 [ V_1 ] ,
V_256 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
}
V_249 -> V_272 = V_251 ;
if ( ( V_249 -> V_234 >= V_252 ) && V_252 ) {
V_216 = 0 ;
V_257 = ( T_1 T_2 * ) ( unsigned long ) ( V_249 -> V_277 ) ;
for ( V_1 = 0 ; V_1 < V_259 ; V_1 ++ ) {
if ( V_67 -> V_260 [ V_1 ] != 0 ) {
if ( F_115 ( V_67 -> V_260 [ V_1 ] ,
V_257 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
}
}
V_249 -> V_234 = V_252 ;
V_39:
F_13 ( & V_17 -> V_23 . V_57 ) ;
return V_22 ;
}
int F_126 ( struct V_16 * V_17 , void * V_205 ,
struct V_206 * V_207 )
{
struct V_278 * V_279 = V_205 ;
struct V_110 * V_111 ;
int V_22 = 0 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_111 = F_127 ( V_17 , V_279 -> V_220 ) ;
if ( ! V_111 ) {
V_22 = - V_241 ;
goto V_39;
}
if ( V_111 -> V_46 )
V_279 -> V_218 = V_111 -> V_46 -> V_38 . V_27 ;
else
V_279 -> V_218 = 0 ;
V_279 -> V_113 = V_111 -> V_113 ;
V_279 -> V_220 = V_111 -> V_38 . V_27 ;
V_279 -> V_62 = V_111 -> V_62 ;
V_279 -> V_280 = V_111 -> V_280 ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_128 ( struct V_16 * V_17 , void * V_205 ,
struct V_206 * V_207 )
{
struct V_281 * V_282 = V_205 ;
struct V_54 * V_55 ;
struct V_47 * V_48 ;
T_1 T_2 * V_283 ;
int V_216 = 0 , V_22 = 0 ;
unsigned V_284 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_55 = & V_17 -> V_23 ;
if ( V_207 -> V_285 )
V_284 = V_55 -> V_125 ;
else
V_284 = V_55 -> V_127 ;
if ( V_284 &&
( V_282 -> V_286 >= V_284 ) ) {
V_283 = ( T_1 T_2 * ) ( unsigned long ) V_282 -> V_287 ;
F_49 (plane, &config->plane_list, head) {
if ( V_48 -> type != V_126 &&
! V_207 -> V_285 )
continue;
if ( F_115 ( V_48 -> V_38 . V_27 , V_283 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
}
V_282 -> V_286 = V_284 ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_129 ( struct V_16 * V_17 , void * V_205 ,
struct V_206 * V_207 )
{
struct V_288 * V_282 = V_205 ;
struct V_47 * V_48 ;
T_1 T_2 * V_289 ;
int V_22 = 0 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_48 = F_130 ( V_17 , V_282 -> V_290 ) ;
if ( ! V_48 ) {
V_22 = - V_241 ;
goto V_39;
}
if ( V_48 -> V_46 )
V_282 -> V_218 = V_48 -> V_46 -> V_38 . V_27 ;
else
V_282 -> V_218 = 0 ;
if ( V_48 -> V_32 )
V_282 -> V_217 = V_48 -> V_32 -> V_38 . V_27 ;
else
V_282 -> V_217 = 0 ;
V_282 -> V_290 = V_48 -> V_38 . V_27 ;
V_282 -> V_62 = V_48 -> V_62 ;
V_282 -> V_244 = 0 ;
if ( V_48 -> V_120 &&
( V_282 -> V_291 >= V_48 -> V_120 ) ) {
V_289 = ( T_1 T_2 * ) ( unsigned long ) V_282 -> V_292 ;
if ( F_125 ( V_289 ,
V_48 -> V_123 ,
sizeof( T_1 ) * V_48 -> V_120 ) ) {
V_22 = - V_225 ;
goto V_39;
}
}
V_282 -> V_291 = V_48 -> V_120 ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
static int F_131 ( struct V_47 * V_48 ,
struct V_45 * V_46 ,
struct V_31 * V_32 ,
T_4 V_293 , T_4 V_294 ,
T_1 V_295 , T_1 V_296 ,
T_1 V_297 , T_1 V_298 ,
T_1 V_299 , T_1 V_300 )
{
int V_22 = 0 ;
unsigned int V_301 , V_302 ;
int V_1 ;
if ( ! V_32 ) {
V_48 -> V_131 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_132 ( V_48 ) ;
if ( ! V_22 ) {
V_48 -> V_46 = NULL ;
V_48 -> V_32 = NULL ;
} else {
V_48 -> V_131 = NULL ;
}
goto V_39;
}
if ( ! ( V_48 -> V_62 & F_132 ( V_46 ) ) ) {
F_67 ( L_47 ) ;
V_22 = - V_204 ;
goto V_39;
}
for ( V_1 = 0 ; V_1 < V_48 -> V_120 ; V_1 ++ )
if ( V_32 -> V_303 == V_48 -> V_123 [ V_1 ] )
break;
if ( V_1 == V_48 -> V_120 ) {
F_67 ( L_48 ,
F_9 ( V_32 -> V_303 ) ) ;
V_22 = - V_204 ;
goto V_39;
}
V_301 = V_32 -> V_304 << 16 ;
V_302 = V_32 -> V_305 << 16 ;
if ( V_299 > V_301 ||
V_297 > V_301 - V_299 ||
V_300 > V_302 ||
V_298 > V_302 - V_300 ) {
F_67 ( L_49
L_50 ,
V_299 >> 16 , ( ( V_299 & 0xffff ) * 15625 ) >> 10 ,
V_300 >> 16 , ( ( V_300 & 0xffff ) * 15625 ) >> 10 ,
V_297 >> 16 , ( ( V_297 & 0xffff ) * 15625 ) >> 10 ,
V_298 >> 16 , ( ( V_298 & 0xffff ) * 15625 ) >> 10 ) ;
V_22 = - V_306 ;
goto V_39;
}
V_48 -> V_131 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_307 ( V_48 , V_46 , V_32 ,
V_293 , V_294 , V_295 , V_296 ,
V_297 , V_298 , V_299 , V_300 ) ;
if ( ! V_22 ) {
V_48 -> V_46 = V_46 ;
V_48 -> V_32 = V_32 ;
V_32 = NULL ;
} else {
V_48 -> V_131 = NULL ;
}
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
if ( V_48 -> V_131 )
F_34 ( V_48 -> V_131 ) ;
V_48 -> V_131 = NULL ;
return V_22 ;
}
static int F_133 ( struct V_47 * V_48 ,
struct V_45 * V_46 ,
struct V_31 * V_32 ,
T_4 V_293 , T_4 V_294 ,
T_1 V_295 , T_1 V_296 ,
T_1 V_297 , T_1 V_298 ,
T_1 V_299 , T_1 V_300 )
{
int V_22 ;
F_48 ( V_48 -> V_17 ) ;
V_22 = F_131 ( V_48 , V_46 , V_32 ,
V_293 , V_294 , V_295 , V_296 ,
V_297 , V_298 , V_299 , V_300 ) ;
F_53 ( V_48 -> V_17 ) ;
return V_22 ;
}
int F_134 ( struct V_16 * V_17 , void * V_205 ,
struct V_206 * V_207 )
{
struct V_308 * V_309 = V_205 ;
struct V_18 * V_19 ;
struct V_47 * V_48 ;
struct V_45 * V_46 = NULL ;
struct V_31 * V_32 = NULL ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
if ( V_309 -> V_295 > V_200 ||
V_309 -> V_293 > V_200 - ( T_4 ) V_309 -> V_295 ||
V_309 -> V_296 > V_200 ||
V_309 -> V_294 > V_200 - ( T_4 ) V_309 -> V_296 ) {
F_67 ( L_51 ,
V_309 -> V_295 , V_309 -> V_296 ,
V_309 -> V_293 , V_309 -> V_294 ) ;
return - V_201 ;
}
V_19 = F_21 ( V_17 , V_309 -> V_290 ,
V_122 ) ;
if ( ! V_19 ) {
F_67 ( L_52 ,
V_309 -> V_290 ) ;
return - V_241 ;
}
V_48 = F_135 ( V_19 ) ;
if ( V_309 -> V_217 ) {
V_32 = F_32 ( V_17 , V_309 -> V_217 ) ;
if ( ! V_32 ) {
F_67 ( L_53 ,
V_309 -> V_217 ) ;
return - V_241 ;
}
V_19 = F_21 ( V_17 , V_309 -> V_218 ,
V_58 ) ;
if ( ! V_19 ) {
F_67 ( L_54 ,
V_309 -> V_218 ) ;
return - V_241 ;
}
V_46 = F_136 ( V_19 ) ;
}
return F_133 ( V_48 , V_46 , V_32 ,
V_309 -> V_293 , V_309 -> V_294 ,
V_309 -> V_295 , V_309 -> V_296 ,
V_309 -> V_297 , V_309 -> V_298 ,
V_309 -> V_299 , V_309 -> V_300 ) ;
}
int F_50 ( struct V_49 * V_50 )
{
struct V_45 * V_46 = V_50 -> V_46 ;
struct V_31 * V_32 ;
struct V_45 * V_65 ;
int V_22 ;
F_49 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_65 -> V_51 -> V_131 = V_65 -> V_51 -> V_32 ;
V_32 = V_50 -> V_32 ;
V_22 = V_46 -> V_34 -> V_310 ( V_50 ) ;
if ( V_22 == 0 ) {
V_46 -> V_51 -> V_46 = V_46 ;
V_46 -> V_51 -> V_32 = V_32 ;
}
F_49 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_65 -> V_51 -> V_32 )
F_38 ( V_65 -> V_51 -> V_32 ) ;
if ( V_65 -> V_51 -> V_131 )
F_34 ( V_65 -> V_51 -> V_131 ) ;
V_65 -> V_51 -> V_131 = NULL ;
}
return V_22 ;
}
int F_137 ( const struct V_45 * V_46 ,
int V_242 , int V_243 ,
const struct V_68 * V_69 ,
const struct V_31 * V_32 )
{
int V_186 , V_192 ;
V_186 = V_69 -> V_186 ;
V_192 = V_69 -> V_192 ;
if ( F_120 ( V_69 ) ) {
struct V_68 V_311 = * V_69 ;
F_138 ( & V_311 , V_312 ) ;
V_186 = V_311 . V_313 ;
V_192 = V_311 . V_314 ;
}
if ( V_46 -> V_56 )
F_139 ( V_186 , V_192 ) ;
if ( V_186 > V_32 -> V_304 ||
V_192 > V_32 -> V_305 ||
V_242 > V_32 -> V_304 - V_186 ||
V_243 > V_32 -> V_305 - V_192 ) {
F_67 ( L_55 ,
V_32 -> V_304 , V_32 -> V_305 , V_186 , V_192 , V_242 , V_243 ,
V_46 -> V_56 ? L_56 : L_15 ) ;
return - V_306 ;
}
return 0 ;
}
int F_140 ( struct V_16 * V_17 , void * V_205 ,
struct V_206 * V_207 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
struct V_239 * V_315 = V_205 ;
struct V_45 * V_46 ;
struct V_66 * * V_316 = NULL , * V_67 ;
struct V_31 * V_32 = NULL ;
struct V_68 * V_69 = NULL ;
struct V_49 V_50 ;
T_1 T_2 * V_317 ;
int V_22 ;
int V_1 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
if ( V_315 -> V_242 > V_200 || V_315 -> V_243 > V_200 )
return - V_201 ;
F_48 ( V_17 ) ;
V_46 = F_118 ( V_17 , V_315 -> V_218 ) ;
if ( ! V_46 ) {
F_67 ( L_57 , V_315 -> V_218 ) ;
V_22 = - V_241 ;
goto V_39;
}
F_67 ( L_42 , V_46 -> V_38 . V_27 ) ;
if ( V_315 -> V_246 ) {
if ( V_315 -> V_217 == - 1 ) {
if ( ! V_46 -> V_51 -> V_32 ) {
F_67 ( L_58 ) ;
V_22 = - V_204 ;
goto V_39;
}
V_32 = V_46 -> V_51 -> V_32 ;
F_38 ( V_32 ) ;
} else {
V_32 = F_32 ( V_17 , V_315 -> V_217 ) ;
if ( ! V_32 ) {
F_67 ( L_59 ,
V_315 -> V_217 ) ;
V_22 = - V_241 ;
goto V_39;
}
}
V_69 = F_141 ( V_17 ) ;
if ( ! V_69 ) {
V_22 = - V_92 ;
goto V_39;
}
V_22 = F_111 ( V_69 , & V_315 -> V_69 ) ;
if ( V_22 ) {
F_67 ( L_60 ) ;
goto V_39;
}
F_138 ( V_69 , V_318 ) ;
V_22 = F_137 ( V_46 , V_315 -> V_242 , V_315 -> V_243 ,
V_69 , V_32 ) ;
if ( V_22 )
goto V_39;
}
if ( V_315 -> V_236 == 0 && V_69 ) {
F_67 ( L_61 ) ;
V_22 = - V_204 ;
goto V_39;
}
if ( V_315 -> V_236 > 0 && ( ! V_69 || ! V_32 ) ) {
F_67 ( L_62 ,
V_315 -> V_236 ) ;
V_22 = - V_204 ;
goto V_39;
}
if ( V_315 -> V_236 > 0 ) {
T_5 V_319 ;
if ( V_315 -> V_236 > V_55 -> V_98 ) {
V_22 = - V_204 ;
goto V_39;
}
V_316 = F_88 ( V_315 -> V_236 *
sizeof( struct V_66 * ) ,
V_26 ) ;
if ( ! V_316 ) {
V_22 = - V_92 ;
goto V_39;
}
for ( V_1 = 0 ; V_1 < V_315 -> V_236 ; V_1 ++ ) {
V_317 = ( T_1 T_2 * ) ( unsigned long ) V_315 -> V_317 ;
if ( F_142 ( V_319 , & V_317 [ V_1 ] ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_67 = F_122 ( V_17 , V_319 ) ;
if ( ! V_67 ) {
F_67 ( L_63 ,
V_319 ) ;
V_22 = - V_241 ;
goto V_39;
}
F_67 ( L_44 ,
V_67 -> V_38 . V_27 ,
V_67 -> V_11 ) ;
V_316 [ V_1 ] = V_67 ;
}
}
V_50 . V_46 = V_46 ;
V_50 . V_242 = V_315 -> V_242 ;
V_50 . V_243 = V_315 -> V_243 ;
V_50 . V_69 = V_69 ;
V_50 . V_320 = V_316 ;
V_50 . V_180 = V_315 -> V_236 ;
V_50 . V_32 = V_32 ;
V_22 = F_50 ( & V_50 ) ;
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
F_59 ( V_316 ) ;
F_62 ( V_17 , V_69 ) ;
F_53 ( V_17 ) ;
return V_22 ;
}
static int F_143 ( struct V_45 * V_46 ,
struct V_321 * V_322 ,
struct V_206 * V_207 )
{
struct V_16 * V_17 = V_46 -> V_17 ;
struct V_31 * V_32 = NULL ;
struct V_323 V_324 = {
. V_304 = V_322 -> V_304 ,
. V_305 = V_322 -> V_305 ,
. V_303 = V_325 ,
. V_326 = { V_322 -> V_304 * 4 } ,
. V_327 = { V_322 -> V_328 } ,
} ;
T_4 V_293 , V_294 ;
T_1 V_295 = 0 , V_296 = 0 ;
T_1 V_299 = 0 , V_300 = 0 ;
int V_22 = 0 ;
F_91 ( ! V_46 -> V_52 ) ;
F_22 ( V_46 -> V_52 -> V_46 != V_46 && V_46 -> V_52 -> V_46 != NULL ) ;
if ( V_322 -> V_198 & V_329 ) {
if ( V_322 -> V_328 ) {
V_32 = F_144 ( V_17 , & V_324 , V_207 ) ;
if ( F_145 ( V_32 ) ) {
F_67 ( L_64 ) ;
return F_146 ( V_32 ) ;
}
F_38 ( V_32 ) ;
} else {
V_32 = NULL ;
}
} else {
V_32 = V_46 -> V_52 -> V_32 ;
if ( V_32 )
F_38 ( V_32 ) ;
}
if ( V_322 -> V_198 & V_330 ) {
V_293 = V_322 -> V_242 ;
V_294 = V_322 -> V_243 ;
} else {
V_293 = V_46 -> V_331 ;
V_294 = V_46 -> V_332 ;
}
if ( V_32 ) {
V_295 = V_32 -> V_304 ;
V_296 = V_32 -> V_305 ;
V_299 = V_32 -> V_304 << 16 ;
V_300 = V_32 -> V_305 << 16 ;
}
V_22 = F_131 ( V_46 -> V_52 , V_46 , V_32 ,
V_293 , V_294 , V_295 , V_296 ,
0 , 0 , V_299 , V_300 ) ;
if ( V_22 == 0 && V_322 -> V_198 & V_330 ) {
V_46 -> V_331 = V_322 -> V_242 ;
V_46 -> V_332 = V_322 -> V_243 ;
}
return V_22 ;
}
static int F_147 ( struct V_16 * V_17 ,
struct V_321 * V_322 ,
struct V_206 * V_207 )
{
struct V_45 * V_46 ;
int V_22 = 0 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
if ( ! V_322 -> V_198 || ( ~ V_333 & V_322 -> V_198 ) )
return - V_204 ;
V_46 = F_118 ( V_17 , V_322 -> V_218 ) ;
if ( ! V_46 ) {
F_67 ( L_57 , V_322 -> V_218 ) ;
return - V_241 ;
}
F_148 ( V_46 ) ;
if ( V_46 -> V_52 ) {
V_22 = F_143 ( V_46 , V_322 , V_207 ) ;
goto V_39;
}
if ( V_322 -> V_198 & V_329 ) {
if ( ! V_46 -> V_34 -> V_334 && ! V_46 -> V_34 -> V_335 ) {
V_22 = - V_336 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_335 )
V_22 = V_46 -> V_34 -> V_335 ( V_46 , V_207 , V_322 -> V_328 ,
V_322 -> V_304 , V_322 -> V_305 , V_322 -> V_337 , V_322 -> V_338 ) ;
else
V_22 = V_46 -> V_34 -> V_334 ( V_46 , V_207 , V_322 -> V_328 ,
V_322 -> V_304 , V_322 -> V_305 ) ;
}
if ( V_322 -> V_198 & V_330 ) {
if ( V_46 -> V_34 -> V_339 ) {
V_22 = V_46 -> V_34 -> V_339 ( V_46 , V_322 -> V_242 , V_322 -> V_243 ) ;
} else {
V_22 = - V_225 ;
goto V_39;
}
}
V_39:
F_149 ( V_46 ) ;
return V_22 ;
}
int F_150 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_340 * V_322 = V_205 ;
struct V_321 V_341 ;
memcpy ( & V_341 , V_322 , sizeof( struct V_340 ) ) ;
V_341 . V_337 = V_341 . V_338 = 0 ;
return F_147 ( V_17 , & V_341 , V_207 ) ;
}
int F_151 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_321 * V_322 = V_205 ;
return F_147 ( V_17 , V_322 , V_207 ) ;
}
T_1 F_152 ( T_1 V_342 , T_1 V_343 )
{
T_1 V_344 ;
switch ( V_342 ) {
case 8 :
V_344 = V_345 ;
break;
case 16 :
if ( V_343 == 15 )
V_344 = V_346 ;
else
V_344 = V_347 ;
break;
case 24 :
V_344 = V_348 ;
break;
case 32 :
if ( V_343 == 24 )
V_344 = V_349 ;
else if ( V_343 == 30 )
V_344 = V_350 ;
else
V_344 = V_325 ;
break;
default:
F_51 ( L_65 ) ;
V_344 = V_349 ;
break;
}
return V_344 ;
}
int F_153 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_351 * V_352 = V_205 ;
struct V_323 V_353 = {} ;
struct V_54 * V_55 = & V_17 -> V_23 ;
struct V_31 * V_32 ;
int V_22 = 0 ;
V_353 . V_217 = V_352 -> V_217 ;
V_353 . V_304 = V_352 -> V_304 ;
V_353 . V_305 = V_352 -> V_305 ;
V_353 . V_326 [ 0 ] = V_352 -> V_354 ;
V_353 . V_303 = F_152 ( V_352 -> V_342 , V_352 -> V_343 ) ;
V_353 . V_327 [ 0 ] = V_352 -> V_328 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
if ( ( V_55 -> V_231 > V_353 . V_304 ) || ( V_353 . V_304 > V_55 -> V_230 ) )
return - V_204 ;
if ( ( V_55 -> V_229 > V_353 . V_305 ) || ( V_353 . V_305 > V_55 -> V_228 ) )
return - V_204 ;
V_32 = V_17 -> V_23 . V_34 -> V_355 ( V_17 , V_207 , & V_353 ) ;
if ( F_145 ( V_32 ) ) {
F_67 ( L_66 ) ;
return F_146 ( V_32 ) ;
}
F_11 ( & V_207 -> V_222 ) ;
V_352 -> V_217 = V_32 -> V_38 . V_27 ;
F_26 ( & V_32 -> V_37 , & V_207 -> V_356 ) ;
F_67 ( L_67 , V_32 -> V_38 . V_27 ) ;
F_13 ( & V_207 -> V_222 ) ;
return V_22 ;
}
static int F_154 ( const struct V_323 * V_353 )
{
T_1 V_13 = V_353 -> V_303 & ~ V_15 ;
switch ( V_13 ) {
case V_345 :
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
case V_346 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_347 :
case V_374 :
case V_348 :
case V_375 :
case V_349 :
case V_376 :
case V_377 :
case V_378 :
case V_325 :
case V_379 :
case V_380 :
case V_381 :
case V_350 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
return 0 ;
default:
F_67 ( L_68 ,
F_9 ( V_353 -> V_303 ) ) ;
return - V_204 ;
}
}
static int F_155 ( const struct V_323 * V_353 )
{
int V_22 , V_410 , V_411 , V_284 , V_1 ;
V_22 = F_154 ( V_353 ) ;
if ( V_22 ) {
F_67 ( L_69 ,
F_9 ( V_353 -> V_303 ) ) ;
return V_22 ;
}
V_410 = F_156 ( V_353 -> V_303 ) ;
V_411 = F_157 ( V_353 -> V_303 ) ;
V_284 = F_158 ( V_353 -> V_303 ) ;
if ( V_353 -> V_304 == 0 || V_353 -> V_304 % V_410 ) {
F_67 ( L_70 , V_353 -> V_305 ) ;
return - V_204 ;
}
if ( V_353 -> V_305 == 0 || V_353 -> V_305 % V_411 ) {
F_67 ( L_71 , V_353 -> V_305 ) ;
return - V_204 ;
}
for ( V_1 = 0 ; V_1 < V_284 ; V_1 ++ ) {
unsigned int V_304 = V_353 -> V_304 / ( V_1 != 0 ? V_410 : 1 ) ;
unsigned int V_305 = V_353 -> V_305 / ( V_1 != 0 ? V_411 : 1 ) ;
unsigned int V_412 = F_159 ( V_353 -> V_303 , V_1 ) ;
if ( ! V_353 -> V_327 [ V_1 ] ) {
F_67 ( L_72 , V_1 ) ;
return - V_204 ;
}
if ( ( T_3 ) V_304 * V_412 > V_413 )
return - V_201 ;
if ( ( T_3 ) V_305 * V_353 -> V_326 [ V_1 ] + V_353 -> V_414 [ V_1 ] > V_413 )
return - V_201 ;
if ( V_353 -> V_326 [ V_1 ] < V_304 * V_412 ) {
F_67 ( L_73 , V_353 -> V_326 [ V_1 ] , V_1 ) ;
return - V_204 ;
}
}
return 0 ;
}
static struct V_31 * F_144 ( struct V_16 * V_17 ,
struct V_323 * V_353 ,
struct V_206 * V_207 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
struct V_31 * V_32 ;
int V_22 ;
if ( V_353 -> V_198 & ~ V_415 ) {
F_67 ( L_74 , V_353 -> V_198 ) ;
return F_160 ( - V_204 ) ;
}
if ( ( V_55 -> V_231 > V_353 -> V_304 ) || ( V_353 -> V_304 > V_55 -> V_230 ) ) {
F_67 ( L_75 ,
V_353 -> V_304 , V_55 -> V_231 , V_55 -> V_230 ) ;
return F_160 ( - V_204 ) ;
}
if ( ( V_55 -> V_229 > V_353 -> V_305 ) || ( V_353 -> V_305 > V_55 -> V_228 ) ) {
F_67 ( L_76 ,
V_353 -> V_305 , V_55 -> V_229 , V_55 -> V_228 ) ;
return F_160 ( - V_204 ) ;
}
V_22 = F_155 ( V_353 ) ;
if ( V_22 )
return F_160 ( V_22 ) ;
V_32 = V_17 -> V_23 . V_34 -> V_355 ( V_17 , V_207 , V_353 ) ;
if ( F_145 ( V_32 ) ) {
F_67 ( L_66 ) ;
return V_32 ;
}
F_11 ( & V_207 -> V_222 ) ;
V_353 -> V_217 = V_32 -> V_38 . V_27 ;
F_26 ( & V_32 -> V_37 , & V_207 -> V_356 ) ;
F_67 ( L_67 , V_32 -> V_38 . V_27 ) ;
F_13 ( & V_207 -> V_222 ) ;
return V_32 ;
}
int F_161 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_31 * V_32 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
V_32 = F_144 ( V_17 , V_205 , V_207 ) ;
if ( F_145 ( V_32 ) )
return F_146 ( V_32 ) ;
return 0 ;
}
int F_162 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_31 * V_32 = NULL ;
struct V_31 * V_416 = NULL ;
T_1 * V_27 = V_205 ;
int V_417 = 0 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_11 ( & V_207 -> V_222 ) ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
V_32 = F_30 ( V_17 , * V_27 ) ;
if ( ! V_32 )
goto V_418;
F_49 (fbl, &file_priv->fbs, filp_head)
if ( V_32 == V_416 )
V_417 = 1 ;
if ( ! V_417 )
goto V_418;
F_27 ( V_17 , V_32 ) ;
F_163 ( & V_32 -> V_37 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_13 ( & V_207 -> V_222 ) ;
F_46 ( V_32 ) ;
return 0 ;
V_418:
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_13 ( & V_207 -> V_222 ) ;
return - V_241 ;
}
int F_164 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_351 * V_353 = V_205 ;
struct V_31 * V_32 ;
int V_22 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
V_32 = F_32 ( V_17 , V_353 -> V_217 ) ;
if ( ! V_32 )
return - V_241 ;
V_353 -> V_305 = V_32 -> V_305 ;
V_353 -> V_304 = V_32 -> V_304 ;
V_353 -> V_343 = V_32 -> V_343 ;
V_353 -> V_342 = V_32 -> V_419 ;
V_353 -> V_354 = V_32 -> V_326 [ 0 ] ;
if ( V_32 -> V_34 -> V_420 ) {
if ( V_207 -> V_421 || F_165 ( V_422 ) ||
F_166 ( V_207 ) ) {
V_22 = V_32 -> V_34 -> V_420 ( V_32 , V_207 ,
& V_353 -> V_328 ) ;
} else {
V_353 -> V_328 = 0 ;
V_22 = 0 ;
}
} else {
V_22 = - V_423 ;
}
F_34 ( V_32 ) ;
return V_22 ;
}
int F_167 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_424 T_2 * V_425 ;
struct V_424 * V_426 = NULL ;
struct V_427 * V_353 = V_205 ;
struct V_31 * V_32 ;
unsigned V_198 ;
int V_428 ;
int V_22 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
V_32 = F_32 ( V_17 , V_353 -> V_217 ) ;
if ( ! V_32 )
return - V_241 ;
V_428 = V_353 -> V_428 ;
V_425 = (struct V_424 T_2 * ) ( unsigned long ) V_353 -> V_425 ;
if ( ! V_428 != ! V_425 ) {
V_22 = - V_204 ;
goto V_429;
}
V_198 = V_430 & V_353 -> V_198 ;
if ( V_198 & V_431 && ( V_428 % 2 ) ) {
V_22 = - V_204 ;
goto V_429;
}
if ( V_428 && V_425 ) {
if ( V_428 < 0 || V_428 > V_432 ) {
V_22 = - V_204 ;
goto V_429;
}
V_426 = F_105 ( V_428 * sizeof( * V_426 ) , V_26 ) ;
if ( ! V_426 ) {
V_22 = - V_92 ;
goto V_429;
}
V_22 = F_168 ( V_426 , V_425 ,
V_428 * sizeof( * V_426 ) ) ;
if ( V_22 ) {
V_22 = - V_225 ;
goto V_433;
}
}
if ( V_32 -> V_34 -> V_434 ) {
V_22 = V_32 -> V_34 -> V_434 ( V_32 , V_207 , V_198 , V_353 -> V_435 ,
V_426 , V_428 ) ;
} else {
V_22 = - V_436 ;
}
V_433:
F_59 ( V_426 ) ;
V_429:
F_34 ( V_32 ) ;
return V_22 ;
}
void F_169 ( struct V_206 * V_437 )
{
struct V_16 * V_17 = V_437 -> V_227 -> V_17 ;
struct V_31 * V_32 , * V_438 ;
F_73 (fb, tfb, &priv->fbs, filp_head) {
F_11 ( & V_17 -> V_23 . V_35 ) ;
F_27 ( V_17 , V_32 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_163 ( & V_32 -> V_37 ) ;
F_46 ( V_32 ) ;
}
}
struct V_133 * F_94 ( struct V_16 * V_17 , int V_198 ,
const char * V_11 , int V_439 )
{
struct V_133 * V_440 = NULL ;
int V_22 ;
V_440 = F_105 ( sizeof( struct V_133 ) , V_26 ) ;
if ( ! V_440 )
return NULL ;
V_440 -> V_17 = V_17 ;
if ( V_439 ) {
V_440 -> V_276 = F_105 ( sizeof( T_3 ) * V_439 , V_26 ) ;
if ( ! V_440 -> V_276 )
goto V_441;
}
V_22 = F_14 ( V_17 , & V_440 -> V_38 , V_442 ) ;
if ( V_22 )
goto V_441;
V_440 -> V_198 = V_198 ;
V_440 -> V_439 = V_439 ;
F_25 ( & V_440 -> V_443 ) ;
if ( V_11 ) {
strncpy ( V_440 -> V_11 , V_11 , V_444 ) ;
V_440 -> V_11 [ V_444 - 1 ] = '\0' ;
}
F_56 ( & V_440 -> V_41 , & V_17 -> V_23 . V_445 ) ;
F_22 ( ! F_170 ( V_440 ) ) ;
return V_440 ;
V_441:
F_59 ( V_440 -> V_276 ) ;
F_59 ( V_440 ) ;
return NULL ;
}
struct V_133 * F_95 ( struct V_16 * V_17 , int V_198 ,
const char * V_11 ,
const struct V_446 * V_447 ,
int V_439 )
{
struct V_133 * V_440 ;
int V_1 , V_22 ;
V_198 |= V_160 ;
V_440 = F_94 ( V_17 , V_198 , V_11 , V_439 ) ;
if ( ! V_440 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_439 ; V_1 ++ ) {
V_22 = F_100 ( V_440 , V_1 ,
V_447 [ V_1 ] . type ,
V_447 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_171 ( V_17 , V_440 ) ;
return NULL ;
}
}
return V_440 ;
}
struct V_133 * F_172 ( struct V_16 * V_17 ,
int V_198 , const char * V_11 ,
const struct V_446 * V_447 ,
int V_448 ,
T_3 V_449 )
{
struct V_133 * V_440 ;
int V_1 , V_22 , V_64 = 0 ;
int V_439 = F_173 ( V_449 ) ;
V_198 |= V_450 ;
V_440 = F_94 ( V_17 , V_198 , V_11 , V_439 ) ;
if ( ! V_440 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_448 ; V_1 ++ ) {
if ( ! ( V_449 & ( 1ULL << V_447 [ V_1 ] . type ) ) )
continue;
if ( F_22 ( V_64 >= V_439 ) ) {
F_171 ( V_17 , V_440 ) ;
return NULL ;
}
V_22 = F_100 ( V_440 , V_64 ++ ,
V_447 [ V_1 ] . type ,
V_447 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_171 ( V_17 , V_440 ) ;
return NULL ;
}
}
return V_440 ;
}
static struct V_133 * F_174 ( struct V_16 * V_17 ,
int V_198 , const char * V_11 ,
T_3 V_451 , T_3 V_452 )
{
struct V_133 * V_440 ;
V_440 = F_94 ( V_17 , V_198 , V_11 , 2 ) ;
if ( ! V_440 )
return NULL ;
V_440 -> V_276 [ 0 ] = V_451 ;
V_440 -> V_276 [ 1 ] = V_452 ;
return V_440 ;
}
struct V_133 * F_99 ( struct V_16 * V_17 , int V_198 ,
const char * V_11 ,
T_3 V_451 , T_3 V_452 )
{
return F_174 ( V_17 , V_453 | V_198 ,
V_11 , V_451 , V_452 ) ;
}
struct V_133 * F_175 ( struct V_16 * V_17 ,
int V_198 , const char * V_11 ,
T_6 V_451 , T_6 V_452 )
{
return F_174 ( V_17 , V_454 | V_198 ,
V_11 , F_176 ( V_451 ) , F_176 ( V_452 ) ) ;
}
struct V_133 * F_177 ( struct V_16 * V_17 ,
int V_198 , const char * V_11 , T_1 type )
{
struct V_133 * V_440 ;
V_198 |= V_455 ;
V_440 = F_94 ( V_17 , V_198 , V_11 , 1 ) ;
if ( ! V_440 )
return NULL ;
V_440 -> V_276 [ 0 ] = type ;
return V_440 ;
}
int F_100 ( struct V_133 * V_440 , int V_64 ,
T_3 V_456 , const char * V_11 )
{
struct V_457 * V_458 ;
if ( ! ( F_178 ( V_440 , V_160 ) ||
F_178 ( V_440 , V_450 ) ) )
return - V_204 ;
if ( F_178 ( V_440 , V_450 ) &&
( V_456 > 63 ) )
return - V_204 ;
if ( ! F_47 ( & V_440 -> V_443 ) ) {
F_49 (prop_enum, &property->enum_blob_list, head) {
if ( V_458 -> V_456 == V_456 ) {
strncpy ( V_458 -> V_11 , V_11 , V_444 ) ;
V_458 -> V_11 [ V_444 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_458 = F_105 ( sizeof( struct V_457 ) , V_26 ) ;
if ( ! V_458 )
return - V_92 ;
strncpy ( V_458 -> V_11 , V_11 , V_444 ) ;
V_458 -> V_11 [ V_444 - 1 ] = '\0' ;
V_458 -> V_456 = V_456 ;
V_440 -> V_276 [ V_64 ] = V_456 ;
F_56 ( & V_458 -> V_41 , & V_440 -> V_443 ) ;
return 0 ;
}
void F_171 ( struct V_16 * V_17 , struct V_133 * V_440 )
{
struct V_457 * V_458 , * V_459 ;
F_73 (prop_enum, pt, &property->enum_blob_list, head) {
F_45 ( & V_458 -> V_41 ) ;
F_59 ( V_458 ) ;
}
if ( V_440 -> V_439 )
F_59 ( V_440 -> V_276 ) ;
F_17 ( V_17 , & V_440 -> V_38 ) ;
F_45 ( & V_440 -> V_41 ) ;
F_59 ( V_440 ) ;
}
void F_71 ( struct V_18 * V_19 ,
struct V_133 * V_440 ,
T_3 V_460 )
{
int V_258 = V_19 -> V_59 -> V_258 ;
if ( V_258 == V_461 ) {
F_110 ( 1 , L_77
L_78
L_79 ,
V_19 -> type ) ;
return;
}
V_19 -> V_59 -> V_275 [ V_258 ] = V_440 -> V_38 . V_27 ;
V_19 -> V_59 -> V_276 [ V_258 ] = V_460 ;
V_19 -> V_59 -> V_258 ++ ;
}
int F_179 ( struct V_18 * V_19 ,
struct V_133 * V_440 , T_3 V_462 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_59 -> V_258 ; V_1 ++ ) {
if ( V_19 -> V_59 -> V_275 [ V_1 ] == V_440 -> V_38 . V_27 ) {
V_19 -> V_59 -> V_276 [ V_1 ] = V_462 ;
return 0 ;
}
}
return - V_204 ;
}
int F_180 ( struct V_18 * V_19 ,
struct V_133 * V_440 , T_3 * V_462 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_59 -> V_258 ; V_1 ++ ) {
if ( V_19 -> V_59 -> V_275 [ V_1 ] == V_440 -> V_38 . V_27 ) {
* V_462 = V_19 -> V_59 -> V_276 [ V_1 ] ;
return 0 ;
}
}
return - V_204 ;
}
int F_181 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_463 * V_249 = V_205 ;
struct V_133 * V_440 ;
int V_464 = 0 ;
int V_465 = 0 ;
int V_466 = 0 ;
int V_22 = 0 , V_1 ;
int V_216 ;
struct V_457 * V_458 ;
struct V_467 T_2 * V_468 ;
struct V_469 * V_470 ;
T_1 T_2 * V_471 ;
T_3 T_2 * V_472 ;
T_1 T_2 * V_473 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_440 = F_182 ( V_17 , V_249 -> V_474 ) ;
if ( ! V_440 ) {
V_22 = - V_241 ;
goto V_475;
}
if ( F_178 ( V_440 , V_160 ) ||
F_178 ( V_440 , V_450 ) ) {
F_49 (prop_enum, &property->enum_blob_list, head)
V_464 ++ ;
} else if ( F_178 ( V_440 , V_137 ) ) {
F_49 (prop_blob, &property->enum_blob_list, head)
V_465 ++ ;
}
V_466 = V_440 -> V_439 ;
strncpy ( V_249 -> V_11 , V_440 -> V_11 , V_444 ) ;
V_249 -> V_11 [ V_444 - 1 ] = 0 ;
V_249 -> V_198 = V_440 -> V_198 ;
if ( ( V_249 -> V_476 >= V_466 ) && V_466 ) {
V_472 = ( T_3 T_2 * ) ( unsigned long ) V_249 -> V_472 ;
for ( V_1 = 0 ; V_1 < V_466 ; V_1 ++ ) {
if ( F_125 ( V_472 + V_1 , & V_440 -> V_276 [ V_1 ] , sizeof( T_3 ) ) ) {
V_22 = - V_225 ;
goto V_475;
}
}
}
V_249 -> V_476 = V_466 ;
if ( F_178 ( V_440 , V_160 ) ||
F_178 ( V_440 , V_450 ) ) {
if ( ( V_249 -> V_477 >= V_464 ) && V_464 ) {
V_216 = 0 ;
V_468 = (struct V_467 T_2 * ) ( unsigned long ) V_249 -> V_478 ;
F_49 (prop_enum, &property->enum_blob_list, head) {
if ( F_125 ( & V_468 [ V_216 ] . V_456 , & V_458 -> V_456 , sizeof( T_3 ) ) ) {
V_22 = - V_225 ;
goto V_475;
}
if ( F_125 ( & V_468 [ V_216 ] . V_11 ,
& V_458 -> V_11 , V_444 ) ) {
V_22 = - V_225 ;
goto V_475;
}
V_216 ++ ;
}
}
V_249 -> V_477 = V_464 ;
}
if ( F_178 ( V_440 , V_137 ) ) {
if ( ( V_249 -> V_477 >= V_465 ) && V_465 ) {
V_216 = 0 ;
V_471 = ( T_1 T_2 * ) ( unsigned long ) V_249 -> V_478 ;
V_473 = ( T_1 T_2 * ) ( unsigned long ) V_249 -> V_472 ;
F_49 (prop_blob, &property->enum_blob_list, head) {
if ( F_115 ( V_470 -> V_38 . V_27 , V_471 + V_216 ) ) {
V_22 = - V_225 ;
goto V_475;
}
if ( F_115 ( V_470 -> V_479 , V_473 + V_216 ) ) {
V_22 = - V_225 ;
goto V_475;
}
V_216 ++ ;
}
}
V_249 -> V_477 = V_465 ;
}
V_475:
F_53 ( V_17 ) ;
return V_22 ;
}
static struct V_469 * F_183 ( struct V_16 * V_17 , int V_479 ,
void * V_205 )
{
struct V_469 * V_480 ;
int V_22 ;
if ( ! V_479 || ! V_205 )
return NULL ;
V_480 = F_105 ( sizeof( struct V_469 ) + V_479 , V_26 ) ;
if ( ! V_480 )
return NULL ;
V_22 = F_14 ( V_17 , & V_480 -> V_38 , V_481 ) ;
if ( V_22 ) {
F_59 ( V_480 ) ;
return NULL ;
}
V_480 -> V_479 = V_479 ;
memcpy ( V_480 -> V_205 , V_205 , V_479 ) ;
F_56 ( & V_480 -> V_41 , & V_17 -> V_23 . V_482 ) ;
return V_480 ;
}
static void F_184 ( struct V_16 * V_17 ,
struct V_469 * V_480 )
{
F_17 ( V_17 , & V_480 -> V_38 ) ;
F_45 ( & V_480 -> V_41 ) ;
F_59 ( V_480 ) ;
}
int F_185 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_483 * V_249 = V_205 ;
struct V_469 * V_480 ;
int V_22 = 0 ;
void T_2 * V_484 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_480 = F_186 ( V_17 , V_249 -> V_485 ) ;
if ( ! V_480 ) {
V_22 = - V_241 ;
goto V_475;
}
if ( V_249 -> V_479 == V_480 -> V_479 ) {
V_484 = ( void T_2 * ) ( unsigned long ) V_249 -> V_205 ;
if ( F_125 ( V_484 , V_480 -> V_205 , V_480 -> V_479 ) ) {
V_22 = - V_225 ;
goto V_475;
}
}
V_249 -> V_479 = V_480 -> V_479 ;
V_475:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_187 ( struct V_66 * V_67 ,
char * V_486 )
{
struct V_16 * V_17 = V_67 -> V_17 ;
int V_22 , V_487 ;
V_487 = strlen ( V_486 ) + 1 ;
V_67 -> V_488 = F_183 ( V_67 -> V_17 ,
V_487 , V_486 ) ;
if ( ! V_67 -> V_488 )
return - V_204 ;
V_22 = F_179 ( & V_67 -> V_38 ,
V_17 -> V_23 . V_140 ,
V_67 -> V_488 -> V_38 . V_27 ) ;
return V_22 ;
}
int F_188 ( struct V_66 * V_67 ,
struct V_134 * V_134 )
{
struct V_16 * V_17 = V_67 -> V_17 ;
int V_22 , V_487 ;
if ( V_67 -> V_489 )
return 0 ;
if ( V_67 -> V_95 )
F_184 ( V_17 , V_67 -> V_95 ) ;
if ( ! V_134 ) {
V_67 -> V_95 = NULL ;
V_22 = F_179 ( & V_67 -> V_38 , V_17 -> V_23 . V_100 , 0 ) ;
return V_22 ;
}
V_487 = V_490 * ( 1 + V_134 -> V_491 ) ;
V_67 -> V_95 = F_183 ( V_67 -> V_17 ,
V_487 , V_134 ) ;
if ( ! V_67 -> V_95 )
return - V_204 ;
V_22 = F_179 ( & V_67 -> V_38 ,
V_17 -> V_23 . V_100 ,
V_67 -> V_95 -> V_38 . V_27 ) ;
return V_22 ;
}
static bool F_189 ( struct V_133 * V_440 ,
T_3 V_456 )
{
if ( V_440 -> V_198 & V_138 )
return false ;
if ( F_178 ( V_440 , V_453 ) ) {
if ( V_456 < V_440 -> V_276 [ 0 ] || V_456 > V_440 -> V_276 [ 1 ] )
return false ;
return true ;
} else if ( F_178 ( V_440 , V_454 ) ) {
T_6 V_492 = F_190 ( V_456 ) ;
if ( V_492 < F_190 ( V_440 -> V_276 [ 0 ] ) ||
V_492 > F_190 ( V_440 -> V_276 [ 1 ] ) )
return false ;
return true ;
} else if ( F_178 ( V_440 , V_450 ) ) {
int V_1 ;
T_3 V_493 = 0 ;
for ( V_1 = 0 ; V_1 < V_440 -> V_439 ; V_1 ++ )
V_493 |= ( 1ULL << V_440 -> V_276 [ V_1 ] ) ;
return ! ( V_456 & ~ V_493 ) ;
} else if ( F_178 ( V_440 , V_137 ) ) {
return true ;
} else if ( F_178 ( V_440 , V_455 ) ) {
struct V_18 * V_19 ;
if ( V_456 == 0 )
return true ;
V_19 = F_19 ( V_440 -> V_17 , V_456 , V_440 -> V_276 [ 0 ] ) ;
return V_19 != NULL ;
} else {
int V_1 ;
for ( V_1 = 0 ; V_1 < V_440 -> V_439 ; V_1 ++ )
if ( V_440 -> V_276 [ V_1 ] == V_456 )
return true ;
return false ;
}
}
int F_191 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_494 * V_495 = V_205 ;
struct V_496 V_497 = {
. V_456 = V_495 -> V_456 ,
. V_474 = V_495 -> V_474 ,
. V_498 = V_495 -> V_219 ,
. V_20 = V_88
} ;
return F_192 ( V_17 , & V_497 , V_207 ) ;
}
static int F_193 ( struct V_18 * V_19 ,
struct V_133 * V_440 ,
T_3 V_456 )
{
int V_22 = - V_204 ;
struct V_66 * V_67 = F_194 ( V_19 ) ;
if ( V_440 == V_67 -> V_17 -> V_23 . V_101 ) {
if ( V_67 -> V_34 -> V_135 )
(* V_67 -> V_34 -> V_135 )( V_67 , ( int ) V_456 ) ;
V_22 = 0 ;
} else if ( V_67 -> V_34 -> V_499 )
V_22 = V_67 -> V_34 -> V_499 ( V_67 , V_440 , V_456 ) ;
if ( ! V_22 )
F_179 ( & V_67 -> V_38 , V_440 , V_456 ) ;
return V_22 ;
}
static int F_195 ( struct V_18 * V_19 ,
struct V_133 * V_440 ,
T_3 V_456 )
{
int V_22 = - V_204 ;
struct V_45 * V_46 = F_136 ( V_19 ) ;
if ( V_46 -> V_34 -> V_499 )
V_22 = V_46 -> V_34 -> V_499 ( V_46 , V_440 , V_456 ) ;
if ( ! V_22 )
F_179 ( V_19 , V_440 , V_456 ) ;
return V_22 ;
}
int F_196 ( struct V_47 * V_48 ,
struct V_133 * V_440 ,
T_3 V_456 )
{
int V_22 = - V_204 ;
struct V_18 * V_19 = & V_48 -> V_38 ;
if ( V_48 -> V_34 -> V_499 )
V_22 = V_48 -> V_34 -> V_499 ( V_48 , V_440 , V_456 ) ;
if ( ! V_22 )
F_179 ( V_19 , V_440 , V_456 ) ;
return V_22 ;
}
int F_197 ( struct V_16 * V_17 , void * V_205 ,
struct V_206 * V_207 )
{
struct V_500 * V_501 = V_205 ;
struct V_18 * V_19 ;
int V_22 = 0 ;
int V_1 ;
int V_216 = 0 ;
int V_251 = 0 ;
T_1 T_2 * V_273 ;
T_3 T_2 * V_274 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_19 = F_21 ( V_17 , V_501 -> V_498 , V_501 -> V_20 ) ;
if ( ! V_19 ) {
V_22 = - V_241 ;
goto V_39;
}
if ( ! V_19 -> V_59 ) {
V_22 = - V_204 ;
goto V_39;
}
V_251 = V_19 -> V_59 -> V_258 ;
if ( ( V_501 -> V_272 >= V_251 ) && V_251 ) {
V_216 = 0 ;
V_273 = ( T_1 T_2 * ) ( unsigned long ) ( V_501 -> V_273 ) ;
V_274 = ( T_3 T_2 * ) ( unsigned long )
( V_501 -> V_274 ) ;
for ( V_1 = 0 ; V_1 < V_251 ; V_1 ++ ) {
if ( F_115 ( V_19 -> V_59 -> V_275 [ V_1 ] ,
V_273 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
if ( F_115 ( V_19 -> V_59 -> V_276 [ V_1 ] ,
V_274 + V_216 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_216 ++ ;
}
}
V_501 -> V_272 = V_251 ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_192 ( struct V_16 * V_17 , void * V_205 ,
struct V_206 * V_207 )
{
struct V_496 * V_501 = V_205 ;
struct V_18 * V_502 ;
struct V_18 * V_503 ;
struct V_133 * V_440 ;
int V_22 = - V_204 ;
int V_1 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_502 = F_21 ( V_17 , V_501 -> V_498 , V_501 -> V_20 ) ;
if ( ! V_502 ) {
V_22 = - V_241 ;
goto V_39;
}
if ( ! V_502 -> V_59 )
goto V_39;
for ( V_1 = 0 ; V_1 < V_502 -> V_59 -> V_258 ; V_1 ++ )
if ( V_502 -> V_59 -> V_275 [ V_1 ] == V_501 -> V_474 )
break;
if ( V_1 == V_502 -> V_59 -> V_258 )
goto V_39;
V_503 = F_21 ( V_17 , V_501 -> V_474 ,
V_442 ) ;
if ( ! V_503 ) {
V_22 = - V_241 ;
goto V_39;
}
V_440 = F_198 ( V_503 ) ;
if ( ! F_189 ( V_440 , V_501 -> V_456 ) )
goto V_39;
switch ( V_502 -> type ) {
case V_88 :
V_22 = F_193 ( V_502 , V_440 ,
V_501 -> V_456 ) ;
break;
case V_58 :
V_22 = F_195 ( V_502 , V_440 , V_501 -> V_456 ) ;
break;
case V_122 :
V_22 = F_196 ( F_135 ( V_502 ) ,
V_440 , V_501 -> V_456 ) ;
break;
}
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_199 ( struct V_66 * V_67 ,
struct V_110 * V_111 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_259 ; V_1 ++ ) {
if ( V_67 -> V_260 [ V_1 ] == 0 ) {
V_67 -> V_260 [ V_1 ] = V_111 -> V_38 . V_27 ;
return 0 ;
}
}
return - V_92 ;
}
int F_200 ( struct V_45 * V_46 ,
int V_244 )
{
V_46 -> V_244 = V_244 ;
V_46 -> V_63 = F_105 ( V_244 * sizeof( V_504 ) * 3 , V_26 ) ;
if ( ! V_46 -> V_63 ) {
V_46 -> V_244 = 0 ;
return - V_92 ;
}
return 0 ;
}
int F_201 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_505 * V_506 = V_205 ;
struct V_45 * V_46 ;
void * V_507 , * V_508 , * V_509 ;
int V_487 ;
int V_22 = 0 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_46 = F_118 ( V_17 , V_506 -> V_218 ) ;
if ( ! V_46 ) {
V_22 = - V_241 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_510 == NULL ) {
V_22 = - V_436 ;
goto V_39;
}
if ( V_506 -> V_244 != V_46 -> V_244 ) {
V_22 = - V_204 ;
goto V_39;
}
V_487 = V_506 -> V_244 * ( sizeof( V_504 ) ) ;
V_507 = V_46 -> V_63 ;
if ( F_168 ( V_507 , ( void T_2 * ) ( unsigned long ) V_506 -> V_511 , V_487 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_508 = V_507 + V_487 ;
if ( F_168 ( V_508 , ( void T_2 * ) ( unsigned long ) V_506 -> V_512 , V_487 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_509 = V_508 + V_487 ;
if ( F_168 ( V_509 , ( void T_2 * ) ( unsigned long ) V_506 -> V_513 , V_487 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_46 -> V_34 -> V_510 ( V_46 , V_507 , V_508 , V_509 , 0 , V_46 -> V_244 ) ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_202 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_505 * V_506 = V_205 ;
struct V_45 * V_46 ;
void * V_507 , * V_508 , * V_509 ;
int V_487 ;
int V_22 = 0 ;
if ( ! F_113 ( V_17 , V_221 ) )
return - V_204 ;
F_48 ( V_17 ) ;
V_46 = F_118 ( V_17 , V_506 -> V_218 ) ;
if ( ! V_46 ) {
V_22 = - V_241 ;
goto V_39;
}
if ( V_506 -> V_244 != V_46 -> V_244 ) {
V_22 = - V_204 ;
goto V_39;
}
V_487 = V_506 -> V_244 * ( sizeof( V_504 ) ) ;
V_507 = V_46 -> V_63 ;
if ( F_125 ( ( void T_2 * ) ( unsigned long ) V_506 -> V_511 , V_507 , V_487 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_508 = V_507 + V_487 ;
if ( F_125 ( ( void T_2 * ) ( unsigned long ) V_506 -> V_512 , V_508 , V_487 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_509 = V_508 + V_487 ;
if ( F_125 ( ( void T_2 * ) ( unsigned long ) V_506 -> V_513 , V_509 , V_487 ) ) {
V_22 = - V_225 ;
goto V_39;
}
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_203 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_514 * V_515 = V_205 ;
struct V_45 * V_46 ;
struct V_31 * V_32 = NULL ;
struct V_516 * V_517 = NULL ;
unsigned long V_198 ;
int V_22 = - V_204 ;
if ( V_515 -> V_198 & ~ V_518 ||
V_515 -> V_519 != 0 )
return - V_204 ;
if ( ( V_515 -> V_198 & V_520 ) && ! V_17 -> V_23 . V_521 )
return - V_204 ;
V_46 = F_118 ( V_17 , V_515 -> V_218 ) ;
if ( ! V_46 )
return - V_241 ;
F_148 ( V_46 ) ;
if ( V_46 -> V_51 -> V_32 == NULL ) {
V_22 = - V_522 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_515 == NULL )
goto V_39;
V_32 = F_32 ( V_17 , V_515 -> V_217 ) ;
if ( ! V_32 ) {
V_22 = - V_241 ;
goto V_39;
}
V_22 = F_137 ( V_46 , V_46 -> V_242 , V_46 -> V_243 , & V_46 -> V_69 , V_32 ) ;
if ( V_22 )
goto V_39;
if ( V_46 -> V_51 -> V_32 -> V_303 != V_32 -> V_303 ) {
F_67 ( L_80 ) ;
V_22 = - V_204 ;
goto V_39;
}
if ( V_515 -> V_198 & V_523 ) {
V_22 = - V_92 ;
F_204 ( & V_17 -> V_524 , V_198 ) ;
if ( V_207 -> V_525 < sizeof V_517 -> V_526 ) {
F_205 ( & V_17 -> V_524 , V_198 ) ;
goto V_39;
}
V_207 -> V_525 -= sizeof V_517 -> V_526 ;
F_205 ( & V_17 -> V_524 , V_198 ) ;
V_517 = F_105 ( sizeof *V_517 , V_26 ) ;
if ( V_517 == NULL ) {
F_204 ( & V_17 -> V_524 , V_198 ) ;
V_207 -> V_525 += sizeof V_517 -> V_526 ;
F_205 ( & V_17 -> V_524 , V_198 ) ;
goto V_39;
}
V_517 -> V_526 . V_38 . type = V_527 ;
V_517 -> V_526 . V_38 . V_479 = sizeof V_517 -> V_526 ;
V_517 -> V_526 . V_528 = V_515 -> V_528 ;
V_517 -> V_38 . V_526 = & V_517 -> V_526 . V_38 ;
V_517 -> V_38 . V_207 = V_207 ;
V_517 -> V_38 . V_44 =
( void ( * ) ( struct V_529 * ) ) F_59 ;
}
V_46 -> V_51 -> V_131 = V_46 -> V_51 -> V_32 ;
V_22 = V_46 -> V_34 -> V_515 ( V_46 , V_32 , V_517 , V_515 -> V_198 ) ;
if ( V_22 ) {
if ( V_515 -> V_198 & V_523 ) {
F_204 ( & V_17 -> V_524 , V_198 ) ;
V_207 -> V_525 += sizeof V_517 -> V_526 ;
F_205 ( & V_17 -> V_524 , V_198 ) ;
F_59 ( V_517 ) ;
}
V_46 -> V_51 -> V_131 = NULL ;
} else {
F_22 ( V_46 -> V_51 -> V_32 != V_32 ) ;
V_32 = NULL ;
}
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
if ( V_46 -> V_51 -> V_131 )
F_34 ( V_46 -> V_51 -> V_131 ) ;
V_46 -> V_51 -> V_131 = NULL ;
F_149 ( V_46 ) ;
return V_22 ;
}
void F_206 ( struct V_16 * V_17 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_110 * V_111 ;
struct V_66 * V_67 ;
F_49 (plane, &dev->mode_config.plane_list, head)
if ( V_48 -> V_34 -> V_530 )
V_48 -> V_34 -> V_530 ( V_48 ) ;
F_49 (crtc, &dev->mode_config.crtc_list, head)
if ( V_46 -> V_34 -> V_530 )
V_46 -> V_34 -> V_530 ( V_46 ) ;
F_49 (encoder, &dev->mode_config.encoder_list, head)
if ( V_111 -> V_34 -> V_530 )
V_111 -> V_34 -> V_530 ( V_111 ) ;
F_49 (connector, &dev->mode_config.connector_list, head) {
V_67 -> V_5 = V_96 ;
if ( V_67 -> V_34 -> V_530 )
V_67 -> V_34 -> V_530 ( V_67 ) ;
}
}
int F_207 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_531 * args = V_205 ;
T_5 V_412 , V_532 , V_487 ;
if ( ! V_17 -> V_533 -> V_534 )
return - V_436 ;
if ( ! args -> V_304 || ! args -> V_305 || ! args -> V_342 )
return - V_204 ;
V_412 = F_208 ( args -> V_342 , 8 ) ;
if ( ! V_412 || V_412 > 0xffffffffU / args -> V_304 )
return - V_204 ;
V_532 = V_412 * args -> V_304 ;
if ( args -> V_305 > 0xffffffffU / V_532 )
return - V_204 ;
V_487 = args -> V_305 * V_532 ;
if ( F_209 ( V_487 ) == 0 )
return - V_204 ;
return V_17 -> V_533 -> V_534 ( V_207 , V_17 , args ) ;
}
int F_210 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_535 * args = V_205 ;
if ( ! V_17 -> V_533 -> V_536 )
return - V_436 ;
return V_17 -> V_533 -> V_536 ( V_207 , V_17 , args -> V_328 , & args -> V_537 ) ;
}
int F_211 ( struct V_16 * V_17 ,
void * V_205 , struct V_206 * V_207 )
{
struct V_538 * args = V_205 ;
if ( ! V_17 -> V_533 -> V_539 )
return - V_436 ;
return V_17 -> V_533 -> V_539 ( V_207 , V_17 , args -> V_328 ) ;
}
void F_212 ( T_1 V_13 , unsigned int * V_343 ,
int * V_342 )
{
switch ( V_13 ) {
case V_345 :
case V_357 :
case V_358 :
* V_343 = 8 ;
* V_342 = 8 ;
break;
case V_346 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
* V_343 = 15 ;
* V_342 = 16 ;
break;
case V_347 :
case V_374 :
* V_343 = 16 ;
* V_342 = 16 ;
break;
case V_348 :
case V_375 :
* V_343 = 24 ;
* V_342 = 24 ;
break;
case V_349 :
case V_376 :
case V_377 :
case V_378 :
* V_343 = 24 ;
* V_342 = 32 ;
break;
case V_350 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
* V_343 = 30 ;
* V_342 = 32 ;
break;
case V_325 :
case V_379 :
case V_380 :
case V_381 :
* V_343 = 32 ;
* V_342 = 32 ;
break;
default:
F_67 ( L_81 ,
F_9 ( V_13 ) ) ;
* V_343 = 0 ;
* V_342 = 0 ;
break;
}
}
int F_158 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
return 3 ;
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
return 2 ;
default:
return 1 ;
}
}
int F_159 ( T_1 V_13 , int V_48 )
{
unsigned int V_343 ;
int V_342 ;
if ( V_48 >= F_158 ( V_13 ) )
return 0 ;
switch ( V_13 ) {
case V_389 :
case V_390 :
case V_391 :
case V_392 :
return 2 ;
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
return V_48 ? 2 : 1 ;
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
return 1 ;
default:
F_212 ( V_13 , & V_343 , & V_342 ) ;
return V_342 >> 3 ;
}
}
int F_156 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_402 :
case V_403 :
case V_400 :
case V_401 :
return 4 ;
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_406 :
case V_407 :
case V_404 :
case V_405 :
return 2 ;
default:
return 1 ;
}
}
int F_157 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_400 :
case V_401 :
return 4 ;
case V_404 :
case V_405 :
case V_394 :
case V_395 :
return 2 ;
default:
return 1 ;
}
}
unsigned int F_213 ( unsigned int V_540 ,
unsigned int V_541 )
{
if ( V_540 & ~ V_541 ) {
V_540 ^= F_214 ( V_542 ) | F_214 ( V_543 ) ;
V_540 = ( V_540 & ~ 0xf ) | F_214 ( ( F_215 ( V_540 & 0xf ) + 1 ) % 4 ) ;
}
return V_540 ;
}
void F_216 ( struct V_16 * V_17 )
{
F_217 ( & V_17 -> V_23 . V_57 ) ;
F_55 ( & V_17 -> V_23 . V_270 ) ;
F_217 ( & V_17 -> V_23 . V_24 ) ;
F_217 ( & V_17 -> V_23 . V_35 ) ;
F_25 ( & V_17 -> V_23 . V_42 ) ;
F_25 ( & V_17 -> V_23 . V_60 ) ;
F_25 ( & V_17 -> V_23 . V_97 ) ;
F_25 ( & V_17 -> V_23 . V_108 ) ;
F_25 ( & V_17 -> V_23 . V_116 ) ;
F_25 ( & V_17 -> V_23 . V_445 ) ;
F_25 ( & V_17 -> V_23 . V_482 ) ;
F_25 ( & V_17 -> V_23 . V_124 ) ;
F_218 ( & V_17 -> V_23 . V_25 ) ;
F_48 ( V_17 ) ;
F_93 ( V_17 ) ;
F_96 ( V_17 ) ;
F_53 ( V_17 ) ;
V_17 -> V_23 . V_40 = 0 ;
V_17 -> V_23 . V_98 = 0 ;
V_17 -> V_23 . V_61 = 0 ;
V_17 -> V_23 . V_117 = 0 ;
V_17 -> V_23 . V_127 = 0 ;
V_17 -> V_23 . V_125 = 0 ;
}
void F_219 ( struct V_16 * V_17 )
{
struct V_66 * V_67 , * V_544 ;
struct V_45 * V_46 , * V_545 ;
struct V_110 * V_111 , * V_546 ;
struct V_104 * V_105 , * V_547 ;
struct V_31 * V_32 , * V_548 ;
struct V_133 * V_440 , * V_459 ;
struct V_469 * V_480 , * V_549 ;
struct V_47 * V_48 , * V_550 ;
F_73 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_111 -> V_34 -> V_44 ( V_111 ) ;
}
F_73 (bridge, brt,
&dev->mode_config.bridge_list, head) {
V_105 -> V_34 -> V_44 ( V_105 ) ;
}
F_73 (connector, ot,
&dev->mode_config.connector_list, head) {
V_67 -> V_34 -> V_44 ( V_67 ) ;
}
F_73 (property, pt, &dev->mode_config.property_list,
head) {
F_171 ( V_17 , V_440 ) ;
}
F_73 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_184 ( V_17 , V_480 ) ;
}
F_22 ( ! F_47 ( & V_17 -> V_23 . V_42 ) ) ;
F_73 (fb, fbt, &dev->mode_config.fb_list, head) {
F_46 ( V_32 ) ;
}
F_73 (plane, plt, &dev->mode_config.plane_list,
head) {
V_48 -> V_34 -> V_44 ( V_48 ) ;
}
F_73 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_46 -> V_34 -> V_44 ( V_46 ) ;
}
F_220 ( & V_17 -> V_23 . V_25 ) ;
F_60 ( & V_17 -> V_23 . V_270 ) ;
}
struct V_133 * F_221 ( struct V_16 * V_17 ,
unsigned int V_541 )
{
static const struct V_446 V_447 [] = {
{ V_551 , L_82 } ,
{ V_552 , L_83 } ,
{ V_553 , L_84 } ,
{ V_554 , L_85 } ,
{ V_542 , L_86 } ,
{ V_543 , L_87 } ,
} ;
return F_172 ( V_17 , 0 , L_88 ,
V_447 , F_2 ( V_447 ) ,
V_541 ) ;
}
