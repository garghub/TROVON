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
return V_22 ;
V_46 -> V_38 . V_59 = & V_46 -> V_59 ;
F_56 ( & V_46 -> V_41 , & V_55 -> V_60 ) ;
V_55 -> V_61 ++ ;
V_46 -> V_51 = V_51 ;
V_46 -> V_52 = V_52 ;
if ( V_51 )
V_51 -> V_62 = 1 << F_57 ( V_46 ) ;
if ( V_52 )
V_52 -> V_62 = 1 << F_57 ( V_46 ) ;
return 0 ;
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
F_22 ( V_46 -> V_64 && ! V_46 -> V_34 -> V_65 ) ;
if ( V_46 -> V_64 && V_46 -> V_34 -> V_65 )
V_46 -> V_34 -> V_65 ( V_46 , V_46 -> V_64 ) ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
}
unsigned int F_57 ( struct V_45 * V_46 )
{
unsigned int V_66 = 0 ;
struct V_45 * V_67 ;
F_49 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_67 == V_46 )
return V_66 ;
V_66 ++ ;
}
F_41 () ;
}
static void F_61 ( struct V_68 * V_69 ,
struct V_70 * V_71 )
{
F_45 ( & V_71 -> V_41 ) ;
F_62 ( V_69 -> V_17 , V_71 ) ;
}
static void F_63 ( struct V_68 * V_69 )
{
struct V_72 * V_71 = & V_69 -> V_73 ;
char * V_74 = NULL ;
if ( F_64 ( V_69 -> V_11 , & V_74 ) )
return;
if ( ! F_65 ( V_74 ,
V_69 ,
V_71 ) )
return;
if ( V_71 -> V_75 ) {
const char * V_76 ;
switch ( V_71 -> V_75 ) {
case V_77 :
V_76 = L_9 ;
break;
case V_78 :
V_76 = L_10 ;
break;
default:
case V_79 :
V_76 = L_11 ;
break;
}
F_66 ( L_12 , V_69 -> V_11 , V_76 ) ;
V_69 -> V_75 = V_71 -> V_75 ;
}
F_67 ( L_13 ,
V_69 -> V_11 ,
V_71 -> V_80 , V_71 -> V_81 ,
V_71 -> V_82 ? V_71 -> V_83 : 60 ,
V_71 -> V_84 ? L_14 : L_15 ,
V_71 -> V_85 ? L_16 : L_15 ,
V_71 -> V_86 ? L_17 : L_15 ) ;
}
int F_68 ( struct V_16 * V_17 ,
struct V_68 * V_69 ,
const struct V_87 * V_34 ,
int V_88 )
{
int V_22 ;
struct V_3 * V_89 =
& V_2 [ V_88 ] . V_3 ;
F_48 ( V_17 ) ;
V_22 = F_10 ( V_17 , & V_69 -> V_38 , V_90 , false ) ;
if ( V_22 )
goto V_91;
V_69 -> V_38 . V_59 = & V_69 -> V_59 ;
V_69 -> V_17 = V_17 ;
V_69 -> V_34 = V_34 ;
V_69 -> V_88 = V_88 ;
V_69 -> V_92 =
F_69 ( V_89 , 1 , 0 , V_26 ) ;
if ( V_69 -> V_92 < 0 ) {
V_22 = V_69 -> V_92 ;
goto V_93;
}
V_69 -> V_11 =
F_70 ( V_26 , L_18 ,
V_2 [ V_88 ] . V_11 ,
V_69 -> V_92 ) ;
if ( ! V_69 -> V_11 ) {
V_22 = - V_94 ;
goto V_93;
}
F_25 ( & V_69 -> V_95 ) ;
F_25 ( & V_69 -> V_96 ) ;
V_69 -> V_97 = NULL ;
V_69 -> V_5 = V_98 ;
F_63 ( V_69 ) ;
F_56 ( & V_69 -> V_41 , & V_17 -> V_23 . V_99 ) ;
V_17 -> V_23 . V_100 ++ ;
if ( V_88 != V_101 )
F_71 ( & V_69 -> V_38 ,
V_17 -> V_23 . V_102 ,
0 ) ;
F_71 ( & V_69 -> V_38 ,
V_17 -> V_23 . V_103 , 0 ) ;
V_69 -> V_104 = NULL ;
V_93:
if ( V_22 )
F_17 ( V_17 , & V_69 -> V_38 ) ;
V_91:
F_53 ( V_17 ) ;
return V_22 ;
}
void F_72 ( struct V_68 * V_69 )
{
struct V_16 * V_17 = V_69 -> V_17 ;
struct V_70 * V_71 , * V_105 ;
if ( V_69 -> V_106 ) {
F_73 ( V_17 , V_69 -> V_106 ) ;
V_69 -> V_106 = NULL ;
}
F_74 (mode, t, &connector->probed_modes, head)
F_61 ( V_69 , V_71 ) ;
F_74 (mode, t, &connector->modes, head)
F_61 ( V_69 , V_71 ) ;
F_75 ( & V_2 [ V_69 -> V_88 ] . V_3 ,
V_69 -> V_92 ) ;
F_17 ( V_17 , & V_69 -> V_38 ) ;
F_59 ( V_69 -> V_11 ) ;
V_69 -> V_11 = NULL ;
F_45 ( & V_69 -> V_41 ) ;
V_17 -> V_23 . V_100 -- ;
F_22 ( V_69 -> V_64 && ! V_69 -> V_34 -> V_65 ) ;
if ( V_69 -> V_64 && V_69 -> V_34 -> V_65 )
V_69 -> V_34 -> V_65 ( V_69 ,
V_69 -> V_64 ) ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
}
unsigned int F_76 ( struct V_68 * V_69 )
{
unsigned int V_66 = 0 ;
struct V_68 * V_67 ;
struct V_54 * V_55 = & V_69 -> V_17 -> V_23 ;
F_22 ( ! F_77 ( & V_55 -> V_107 ) ) ;
F_49 (tmp, &connector->dev->mode_config.connector_list, head) {
if ( V_67 == V_69 )
return V_66 ;
V_66 ++ ;
}
F_41 () ;
}
int F_78 ( struct V_68 * V_69 )
{
int V_22 ;
F_15 ( V_69 -> V_17 , & V_69 -> V_38 ) ;
V_22 = F_79 ( V_69 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_80 ( V_69 ) ;
if ( V_22 ) {
F_81 ( V_69 ) ;
return V_22 ;
}
return 0 ;
}
void F_82 ( struct V_68 * V_69 )
{
F_81 ( V_69 ) ;
F_83 ( V_69 ) ;
}
void F_84 ( struct V_16 * V_17 )
{
struct V_68 * V_69 ;
F_49 (connector, &dev->mode_config.connector_list, head)
F_82 ( V_69 ) ;
}
int F_85 ( struct V_16 * V_17 , struct V_108 * V_109 ,
const struct V_110 * V_34 )
{
int V_22 ;
F_48 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_109 -> V_38 , V_111 ) ;
if ( V_22 )
goto V_39;
V_109 -> V_17 = V_17 ;
V_109 -> V_34 = V_34 ;
F_56 ( & V_109 -> V_41 , & V_17 -> V_23 . V_112 ) ;
V_17 -> V_23 . V_113 ++ ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
void F_86 ( struct V_108 * V_109 )
{
struct V_16 * V_17 = V_109 -> V_17 ;
F_48 ( V_17 ) ;
F_17 ( V_17 , & V_109 -> V_38 ) ;
F_45 ( & V_109 -> V_41 ) ;
V_17 -> V_23 . V_113 -- ;
F_53 ( V_17 ) ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
}
int F_87 ( struct V_16 * V_17 ,
struct V_114 * V_115 ,
const struct V_116 * V_34 ,
int V_117 )
{
int V_22 ;
F_48 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_115 -> V_38 , V_118 ) ;
if ( V_22 )
goto V_91;
V_115 -> V_17 = V_17 ;
V_115 -> V_117 = V_117 ;
V_115 -> V_34 = V_34 ;
V_115 -> V_11 = F_70 ( V_26 , L_18 ,
V_119 [ V_117 ] . V_11 ,
V_115 -> V_38 . V_27 ) ;
if ( ! V_115 -> V_11 ) {
V_22 = - V_94 ;
goto V_93;
}
F_56 ( & V_115 -> V_41 , & V_17 -> V_23 . V_120 ) ;
V_17 -> V_23 . V_121 ++ ;
V_93:
if ( V_22 )
F_17 ( V_17 , & V_115 -> V_38 ) ;
V_91:
F_53 ( V_17 ) ;
return V_22 ;
}
void F_88 ( struct V_114 * V_115 )
{
struct V_16 * V_17 = V_115 -> V_17 ;
F_48 ( V_17 ) ;
F_17 ( V_17 , & V_115 -> V_38 ) ;
F_59 ( V_115 -> V_11 ) ;
F_45 ( & V_115 -> V_41 ) ;
V_17 -> V_23 . V_121 -- ;
F_53 ( V_17 ) ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
}
int F_89 ( struct V_16 * V_17 , struct V_47 * V_48 ,
unsigned long V_62 ,
const struct V_122 * V_34 ,
const T_1 * V_123 , T_1 V_124 ,
enum V_125 type )
{
int V_22 ;
V_22 = F_14 ( V_17 , & V_48 -> V_38 , V_126 ) ;
if ( V_22 )
return V_22 ;
F_55 ( & V_48 -> V_57 ) ;
V_48 -> V_38 . V_59 = & V_48 -> V_59 ;
V_48 -> V_17 = V_17 ;
V_48 -> V_34 = V_34 ;
V_48 -> V_127 = F_90 ( sizeof( T_1 ) * V_124 ,
V_26 ) ;
if ( ! V_48 -> V_127 ) {
F_67 ( L_19 ) ;
F_17 ( V_17 , & V_48 -> V_38 ) ;
return - V_94 ;
}
memcpy ( V_48 -> V_127 , V_123 , V_124 * sizeof( T_1 ) ) ;
V_48 -> V_124 = V_124 ;
V_48 -> V_62 = V_62 ;
V_48 -> type = type ;
F_56 ( & V_48 -> V_41 , & V_17 -> V_23 . V_128 ) ;
V_17 -> V_23 . V_129 ++ ;
if ( V_48 -> type == V_130 )
V_17 -> V_23 . V_131 ++ ;
F_71 ( & V_48 -> V_38 ,
V_17 -> V_23 . V_132 ,
V_48 -> type ) ;
return 0 ;
}
int F_91 ( struct V_16 * V_17 , struct V_47 * V_48 ,
unsigned long V_62 ,
const struct V_122 * V_34 ,
const T_1 * V_123 , T_1 V_124 ,
bool V_133 )
{
enum V_125 type ;
type = V_133 ? V_134 : V_130 ;
return F_89 ( V_17 , V_48 , V_62 , V_34 ,
V_123 , V_124 , type ) ;
}
void F_92 ( struct V_47 * V_48 )
{
struct V_16 * V_17 = V_48 -> V_17 ;
F_48 ( V_17 ) ;
F_59 ( V_48 -> V_127 ) ;
F_17 ( V_17 , & V_48 -> V_38 ) ;
F_93 ( F_47 ( & V_48 -> V_41 ) ) ;
F_45 ( & V_48 -> V_41 ) ;
V_17 -> V_23 . V_129 -- ;
if ( V_48 -> type == V_130 )
V_17 -> V_23 . V_131 -- ;
F_53 ( V_17 ) ;
F_22 ( V_48 -> V_64 && ! V_48 -> V_34 -> V_65 ) ;
if ( V_48 -> V_64 && V_48 -> V_34 -> V_65 )
V_48 -> V_34 -> V_65 ( V_48 , V_48 -> V_64 ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
}
unsigned int F_94 ( struct V_47 * V_48 )
{
unsigned int V_66 = 0 ;
struct V_47 * V_67 ;
F_49 (tmp, &plane->dev->mode_config.plane_list, head) {
if ( V_67 == V_48 )
return V_66 ;
V_66 ++ ;
}
F_41 () ;
}
void F_52 ( struct V_47 * V_48 )
{
int V_22 ;
if ( ! V_48 -> V_32 )
return;
V_48 -> V_135 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_136 ( V_48 ) ;
if ( V_22 ) {
F_51 ( L_20 ) ;
V_48 -> V_135 = NULL ;
return;
}
F_42 ( V_48 -> V_135 ) ;
V_48 -> V_135 = NULL ;
V_48 -> V_32 = NULL ;
V_48 -> V_46 = NULL ;
}
static int F_95 ( struct V_16 * V_17 )
{
struct V_137 * V_138 ;
struct V_137 * V_139 ;
struct V_137 * V_140 ;
V_138 = F_96 ( V_17 , V_141 |
V_142 ,
L_21 , 0 ) ;
V_17 -> V_23 . V_102 = V_138 ;
V_139 = F_97 ( V_17 , 0 ,
L_22 , V_143 ,
F_2 ( V_143 ) ) ;
V_17 -> V_23 . V_103 = V_139 ;
V_140 = F_96 ( V_17 ,
V_141 |
V_142 ,
L_23 , 0 ) ;
V_17 -> V_23 . V_144 = V_140 ;
V_17 -> V_23 . V_145 = F_96 ( V_17 ,
V_141 |
V_142 ,
L_24 , 0 ) ;
return 0 ;
}
static int F_98 ( struct V_16 * V_17 )
{
struct V_137 * type ;
type = F_97 ( V_17 , V_142 ,
L_25 , V_146 ,
F_2 ( V_146 ) ) ;
V_17 -> V_23 . V_132 = type ;
return 0 ;
}
int F_99 ( struct V_16 * V_17 )
{
struct V_137 * V_147 ;
struct V_137 * V_148 ;
if ( V_17 -> V_23 . V_149 )
return 0 ;
V_147 =
F_97 ( V_17 , 0 ,
L_26 ,
V_150 ,
F_2 ( V_150 ) ) ;
V_17 -> V_23 . V_149 = V_147 ;
V_148 = F_97 ( V_17 , V_142 ,
L_27 ,
V_151 ,
F_2 ( V_151 ) ) ;
V_17 -> V_23 . V_152 = V_148 ;
return 0 ;
}
int F_100 ( struct V_16 * V_17 ,
unsigned int V_153 ,
char * V_96 [] )
{
struct V_137 * V_154 ;
struct V_137 * V_155 ;
unsigned int V_1 ;
if ( V_17 -> V_23 . V_156 )
return 0 ;
V_154 = F_97 ( V_17 , 0 ,
L_26 ,
V_157 ,
F_2 ( V_157 ) ) ;
V_17 -> V_23 . V_156 = V_154 ;
V_155 =
F_97 ( V_17 , V_142 ,
L_27 ,
V_158 ,
F_2 ( V_158 ) ) ;
V_17 -> V_23 . V_159 = V_155 ;
V_17 -> V_23 . V_160 =
F_101 ( V_17 , 0 , L_28 , 0 , 100 ) ;
V_17 -> V_23 . V_161 =
F_101 ( V_17 , 0 , L_29 , 0 , 100 ) ;
V_17 -> V_23 . V_162 =
F_101 ( V_17 , 0 , L_30 , 0 , 100 ) ;
V_17 -> V_23 . V_163 =
F_101 ( V_17 , 0 , L_31 , 0 , 100 ) ;
V_17 -> V_23 . V_164 =
F_96 ( V_17 , V_165 ,
L_32 , V_153 ) ;
for ( V_1 = 0 ; V_1 < V_153 ; V_1 ++ )
F_102 ( V_17 -> V_23 . V_164 , V_1 ,
V_1 , V_96 [ V_1 ] ) ;
V_17 -> V_23 . V_166 =
F_101 ( V_17 , 0 , L_33 , 0 , 100 ) ;
V_17 -> V_23 . V_167 =
F_101 ( V_17 , 0 , L_34 , 0 , 100 ) ;
V_17 -> V_23 . V_168 =
F_101 ( V_17 , 0 , L_35 , 0 , 100 ) ;
V_17 -> V_23 . V_169 =
F_101 ( V_17 , 0 , L_36 , 0 , 100 ) ;
V_17 -> V_23 . V_170 =
F_101 ( V_17 , 0 , L_37 , 0 , 100 ) ;
V_17 -> V_23 . V_171 =
F_101 ( V_17 , 0 , L_38 , 0 , 100 ) ;
return 0 ;
}
int F_103 ( struct V_16 * V_17 )
{
struct V_137 * V_172 ;
if ( V_17 -> V_23 . V_173 )
return 0 ;
V_172 =
F_97 ( V_17 , 0 , L_39 ,
V_174 ,
F_2 ( V_174 ) ) ;
V_17 -> V_23 . V_173 = V_172 ;
return 0 ;
}
int F_104 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_175 )
return 0 ;
V_17 -> V_23 . V_175 =
F_97 ( V_17 , 0 , L_40 ,
V_176 ,
F_2 ( V_176 ) ) ;
if ( V_17 -> V_23 . V_175 == NULL )
return - V_94 ;
return 0 ;
}
int F_105 ( struct V_16 * V_17 )
{
struct V_137 * V_177 ;
if ( V_17 -> V_23 . V_178 )
return 0 ;
V_177 =
F_97 ( V_17 , V_142 ,
L_41 ,
V_179 ,
F_2 ( V_179 ) ) ;
V_17 -> V_23 . V_178 = V_177 ;
return 0 ;
}
int F_106 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_180 && V_17 -> V_23 . V_181 )
return 0 ;
V_17 -> V_23 . V_180 =
F_101 ( V_17 , V_142 , L_42 , 0 , 0xffffffff ) ;
V_17 -> V_23 . V_181 =
F_101 ( V_17 , V_142 , L_43 , 0 , 0xffffffff ) ;
if ( V_17 -> V_23 . V_180 == NULL ||
V_17 -> V_23 . V_181 == NULL )
return - V_94 ;
return 0 ;
}
static int F_107 ( struct V_16 * V_17 , struct V_182 * V_183 )
{
T_1 V_184 = 0 ;
V_184 += V_17 -> V_23 . V_61 ;
V_184 += V_17 -> V_23 . V_100 ;
V_184 += V_17 -> V_23 . V_121 ;
V_184 += V_17 -> V_23 . V_113 ;
V_183 -> V_185 = F_108 ( V_184 * sizeof( T_1 ) , V_26 ) ;
if ( ! V_183 -> V_185 )
return - V_94 ;
V_183 -> V_186 = 0 ;
V_183 -> V_187 = 0 ;
V_183 -> V_188 = 0 ;
V_183 -> V_189 = 0 ;
return 0 ;
}
void F_109 ( struct V_182 * V_183 )
{
F_59 ( V_183 -> V_185 ) ;
V_183 -> V_185 = NULL ;
}
int F_110 ( struct V_16 * V_17 ,
struct V_182 * V_183 )
{
struct V_45 * V_46 ;
struct V_114 * V_115 ;
struct V_68 * V_69 ;
struct V_108 * V_109 ;
int V_22 ;
if ( ( V_22 = F_107 ( V_17 , V_183 ) ) )
return V_22 ;
F_49 (crtc, &dev->mode_config.crtc_list, head)
V_183 -> V_185 [ V_183 -> V_186 ++ ] = V_46 -> V_38 . V_27 ;
F_49 (encoder, &dev->mode_config.encoder_list, head)
V_183 -> V_185 [ V_183 -> V_186 + V_183 -> V_188 ++ ] =
V_115 -> V_38 . V_27 ;
F_49 (connector, &dev->mode_config.connector_list, head)
V_183 -> V_185 [ V_183 -> V_186 + V_183 -> V_188 +
V_183 -> V_187 ++ ] = V_69 -> V_38 . V_27 ;
F_49 (bridge, &dev->mode_config.bridge_list, head)
V_183 -> V_185 [ V_183 -> V_186 + V_183 -> V_188 +
V_183 -> V_187 + V_183 -> V_189 ++ ] =
V_109 -> V_38 . V_27 ;
return 0 ;
}
void F_111 ( struct V_16 * V_17 )
{
F_48 ( V_17 ) ;
F_109 ( & V_17 -> V_51 -> V_190 ) ;
F_110 ( V_17 , & V_17 -> V_51 -> V_190 ) ;
F_53 ( V_17 ) ;
}
static void F_112 ( struct V_191 * V_39 ,
const struct V_70 * V_192 )
{
F_113 ( V_192 -> V_193 > V_194 || V_192 -> V_195 > V_194 ||
V_192 -> V_196 > V_194 || V_192 -> V_197 > V_194 ||
V_192 -> V_198 > V_194 || V_192 -> V_199 > V_194 ||
V_192 -> V_200 > V_194 || V_192 -> V_201 > V_194 ||
V_192 -> V_202 > V_194 || V_192 -> V_203 > V_194 ,
L_44 ) ;
V_39 -> clock = V_192 -> clock ;
V_39 -> V_193 = V_192 -> V_193 ;
V_39 -> V_195 = V_192 -> V_195 ;
V_39 -> V_196 = V_192 -> V_196 ;
V_39 -> V_197 = V_192 -> V_197 ;
V_39 -> V_198 = V_192 -> V_198 ;
V_39 -> V_199 = V_192 -> V_199 ;
V_39 -> V_200 = V_192 -> V_200 ;
V_39 -> V_201 = V_192 -> V_201 ;
V_39 -> V_202 = V_192 -> V_202 ;
V_39 -> V_203 = V_192 -> V_203 ;
V_39 -> V_204 = V_192 -> V_204 ;
V_39 -> V_205 = V_192 -> V_205 ;
V_39 -> type = V_192 -> type ;
strncpy ( V_39 -> V_11 , V_192 -> V_11 , V_206 ) ;
V_39 -> V_11 [ V_206 - 1 ] = 0 ;
}
static int F_114 ( struct V_70 * V_39 ,
const struct V_191 * V_192 )
{
if ( V_192 -> clock > V_207 || V_192 -> V_204 > V_207 )
return - V_208 ;
if ( ( V_192 -> V_205 & V_209 ) > V_210 )
return - V_211 ;
V_39 -> clock = V_192 -> clock ;
V_39 -> V_193 = V_192 -> V_193 ;
V_39 -> V_195 = V_192 -> V_195 ;
V_39 -> V_196 = V_192 -> V_196 ;
V_39 -> V_197 = V_192 -> V_197 ;
V_39 -> V_198 = V_192 -> V_198 ;
V_39 -> V_199 = V_192 -> V_199 ;
V_39 -> V_200 = V_192 -> V_200 ;
V_39 -> V_201 = V_192 -> V_201 ;
V_39 -> V_202 = V_192 -> V_202 ;
V_39 -> V_203 = V_192 -> V_203 ;
V_39 -> V_204 = V_192 -> V_204 ;
V_39 -> V_205 = V_192 -> V_205 ;
V_39 -> type = V_192 -> type ;
strncpy ( V_39 -> V_11 , V_192 -> V_11 , V_206 ) ;
V_39 -> V_11 [ V_206 - 1 ] = 0 ;
return 0 ;
}
int F_115 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_215 * V_216 = V_212 ;
struct V_217 * V_218 ;
struct V_31 * V_32 ;
struct V_68 * V_69 ;
struct V_45 * V_46 ;
struct V_114 * V_115 ;
int V_22 = 0 ;
int V_219 = 0 ;
int V_220 = 0 ;
int V_221 = 0 ;
int V_222 = 0 ;
int V_223 = 0 , V_1 ;
T_1 T_2 * V_224 ;
T_1 T_2 * V_225 ;
T_1 T_2 * V_226 ;
T_1 T_2 * V_227 ;
struct V_182 * V_190 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
F_11 ( & V_214 -> V_229 ) ;
F_117 (lh, &file_priv->fbs)
V_221 ++ ;
if ( V_216 -> V_230 >= V_221 ) {
V_223 = 0 ;
V_224 = ( T_1 T_2 * ) ( unsigned long ) V_216 -> V_231 ;
F_49 (fb, &file_priv->fbs, filp_head) {
if ( F_118 ( V_32 -> V_38 . V_27 , V_224 + V_223 ) ) {
F_13 ( & V_214 -> V_229 ) ;
return - V_232 ;
}
V_223 ++ ;
}
}
V_216 -> V_230 = V_221 ;
F_13 ( & V_214 -> V_229 ) ;
F_11 ( & V_17 -> V_23 . V_57 ) ;
if ( ! F_119 ( V_214 ) ) {
V_190 = NULL ;
F_117 (lh, &dev->mode_config.crtc_list)
V_220 ++ ;
F_117 (lh, &dev->mode_config.connector_list)
V_219 ++ ;
F_117 (lh, &dev->mode_config.encoder_list)
V_222 ++ ;
} else {
V_190 = & V_214 -> V_233 -> V_234 -> V_190 ;
V_220 = V_190 -> V_186 ;
V_219 = V_190 -> V_187 ;
V_222 = V_190 -> V_188 ;
}
V_216 -> V_235 = V_17 -> V_23 . V_235 ;
V_216 -> V_236 = V_17 -> V_23 . V_236 ;
V_216 -> V_237 = V_17 -> V_23 . V_237 ;
V_216 -> V_238 = V_17 -> V_23 . V_238 ;
if ( V_216 -> V_239 >= V_220 ) {
V_223 = 0 ;
V_225 = ( T_1 T_2 * ) ( unsigned long ) V_216 -> V_240 ;
if ( ! V_190 ) {
F_49 (crtc, &dev->mode_config.crtc_list,
head) {
F_67 ( L_45 , V_46 -> V_38 . V_27 ) ;
if ( F_118 ( V_46 -> V_38 . V_27 , V_225 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
} else {
for ( V_1 = 0 ; V_1 < V_190 -> V_186 ; V_1 ++ ) {
if ( F_118 ( V_190 -> V_185 [ V_1 ] ,
V_225 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
}
}
V_216 -> V_239 = V_220 ;
if ( V_216 -> V_241 >= V_222 ) {
V_223 = 0 ;
V_227 = ( T_1 T_2 * ) ( unsigned long ) V_216 -> V_242 ;
if ( ! V_190 ) {
F_49 (encoder,
&dev->mode_config.encoder_list,
head) {
F_67 ( L_46 , V_115 -> V_38 . V_27 ,
V_115 -> V_11 ) ;
if ( F_118 ( V_115 -> V_38 . V_27 , V_227 +
V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
} else {
for ( V_1 = V_190 -> V_186 ; V_1 < V_190 -> V_186 + V_190 -> V_188 ; V_1 ++ ) {
if ( F_118 ( V_190 -> V_185 [ V_1 ] ,
V_227 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
}
}
V_216 -> V_241 = V_222 ;
if ( V_216 -> V_243 >= V_219 ) {
V_223 = 0 ;
V_226 = ( T_1 T_2 * ) ( unsigned long ) V_216 -> V_244 ;
if ( ! V_190 ) {
F_49 (connector,
&dev->mode_config.connector_list,
head) {
F_67 ( L_47 ,
V_69 -> V_38 . V_27 ,
V_69 -> V_11 ) ;
if ( F_118 ( V_69 -> V_38 . V_27 ,
V_226 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
} else {
int V_245 = V_190 -> V_186 +
V_190 -> V_188 ;
for ( V_1 = V_245 ; V_1 < V_245 + V_190 -> V_187 ; V_1 ++ ) {
if ( F_118 ( V_190 -> V_185 [ V_1 ] ,
V_226 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
}
}
V_216 -> V_243 = V_219 ;
F_67 ( L_48 , V_216 -> V_239 ,
V_216 -> V_243 , V_216 -> V_241 ) ;
V_39:
F_13 ( & V_17 -> V_23 . V_57 ) ;
return V_22 ;
}
int F_120 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_246 * V_247 = V_212 ;
struct V_45 * V_46 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
V_46 = F_121 ( V_17 , V_247 -> V_225 ) ;
if ( ! V_46 )
return - V_248 ;
F_122 ( V_46 , V_46 -> V_51 ) ;
V_247 -> V_249 = V_46 -> V_249 ;
V_247 -> V_250 = V_46 -> V_250 ;
V_247 -> V_251 = V_46 -> V_251 ;
if ( V_46 -> V_51 -> V_32 )
V_247 -> V_224 = V_46 -> V_51 -> V_32 -> V_38 . V_27 ;
else
V_247 -> V_224 = 0 ;
if ( V_46 -> V_252 ) {
F_112 ( & V_247 -> V_71 , & V_46 -> V_71 ) ;
V_247 -> V_253 = 1 ;
} else {
V_247 -> V_253 = 0 ;
}
F_123 ( V_46 ) ;
return 0 ;
}
static bool F_124 ( const struct V_70 * V_71 ,
const struct V_213 * V_214 )
{
if ( ! V_214 -> V_254 && F_125 ( V_71 ) )
return false ;
return true ;
}
static struct V_114 * F_126 ( struct V_68 * V_69 )
{
if ( V_69 -> V_64 )
return V_69 -> V_64 -> V_255 ;
return V_69 -> V_115 ;
}
int F_127 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_256 * V_257 = V_212 ;
struct V_68 * V_69 ;
struct V_114 * V_115 ;
struct V_70 * V_71 ;
int V_258 = 0 ;
int V_259 = 0 ;
int V_260 = 0 ;
int V_22 = 0 ;
int V_223 = 0 ;
int V_1 ;
struct V_191 V_261 ;
struct V_191 T_2 * V_262 ;
T_1 T_2 * V_263 ;
T_3 T_2 * V_264 ;
T_1 T_2 * V_265 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
memset ( & V_261 , 0 , sizeof( struct V_191 ) ) ;
F_67 ( L_49 , V_257 -> V_226 ) ;
F_11 ( & V_17 -> V_23 . V_57 ) ;
V_69 = F_128 ( V_17 , V_257 -> V_226 ) ;
if ( ! V_69 ) {
V_22 = - V_248 ;
goto V_39;
}
V_259 = V_69 -> V_59 . V_266 ;
for ( V_1 = 0 ; V_1 < V_267 ; V_1 ++ ) {
if ( V_69 -> V_268 [ V_1 ] != 0 ) {
V_260 ++ ;
}
}
if ( V_257 -> V_269 == 0 ) {
V_69 -> V_34 -> V_270 ( V_69 ,
V_17 -> V_23 . V_237 ,
V_17 -> V_23 . V_235 ) ;
}
F_49 (mode, &connector->modes, head)
if ( F_124 ( V_71 , V_214 ) )
V_258 ++ ;
V_257 -> V_226 = V_69 -> V_38 . V_27 ;
V_257 -> V_88 = V_69 -> V_88 ;
V_257 -> V_92 = V_69 -> V_92 ;
V_257 -> V_271 = V_69 -> V_272 . V_273 ;
V_257 -> V_274 = V_69 -> V_272 . V_275 ;
V_257 -> V_276 = V_69 -> V_272 . V_8 ;
V_257 -> V_277 = V_69 -> V_5 ;
F_129 ( & V_17 -> V_23 . V_107 , NULL ) ;
V_115 = F_126 ( V_69 ) ;
if ( V_115 )
V_257 -> V_227 = V_115 -> V_38 . V_27 ;
else
V_257 -> V_227 = 0 ;
F_130 ( & V_17 -> V_23 . V_107 ) ;
if ( ( V_257 -> V_269 >= V_258 ) && V_258 ) {
V_223 = 0 ;
V_262 = (struct V_191 T_2 * ) ( unsigned long ) V_257 -> V_278 ;
F_49 (mode, &connector->modes, head) {
if ( ! F_124 ( V_71 , V_214 ) )
continue;
F_112 ( & V_261 , V_71 ) ;
if ( F_131 ( V_262 + V_223 ,
& V_261 , sizeof( V_261 ) ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
}
V_257 -> V_269 = V_258 ;
if ( ( V_257 -> V_279 >= V_259 ) && V_259 ) {
V_223 = 0 ;
V_263 = ( T_1 T_2 * ) ( unsigned long ) ( V_257 -> V_280 ) ;
V_264 = ( T_3 T_2 * ) ( unsigned long ) ( V_257 -> V_281 ) ;
for ( V_1 = 0 ; V_1 < V_69 -> V_59 . V_266 ; V_1 ++ ) {
if ( F_118 ( V_69 -> V_59 . V_282 [ V_1 ] ,
V_263 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
if ( F_118 ( V_69 -> V_59 . V_283 [ V_1 ] ,
V_264 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
}
V_257 -> V_279 = V_259 ;
if ( ( V_257 -> V_241 >= V_260 ) && V_260 ) {
V_223 = 0 ;
V_265 = ( T_1 T_2 * ) ( unsigned long ) ( V_257 -> V_284 ) ;
for ( V_1 = 0 ; V_1 < V_267 ; V_1 ++ ) {
if ( V_69 -> V_268 [ V_1 ] != 0 ) {
if ( F_118 ( V_69 -> V_268 [ V_1 ] ,
V_265 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
}
}
V_257 -> V_241 = V_260 ;
V_39:
F_13 ( & V_17 -> V_23 . V_57 ) ;
return V_22 ;
}
static struct V_45 * F_132 ( struct V_114 * V_115 )
{
struct V_68 * V_69 ;
struct V_16 * V_17 = V_115 -> V_17 ;
bool V_285 = false ;
F_49 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_69 -> V_64 )
continue;
V_285 = true ;
if ( V_69 -> V_64 -> V_255 != V_115 )
continue;
return V_69 -> V_64 -> V_46 ;
}
if ( V_285 )
return NULL ;
return V_115 -> V_46 ;
}
int F_133 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_286 * V_287 = V_212 ;
struct V_114 * V_115 ;
struct V_45 * V_46 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
V_115 = F_134 ( V_17 , V_287 -> V_227 ) ;
if ( ! V_115 )
return - V_248 ;
F_129 ( & V_17 -> V_23 . V_107 , NULL ) ;
V_46 = F_132 ( V_115 ) ;
if ( V_46 )
V_287 -> V_225 = V_46 -> V_38 . V_27 ;
else if ( V_115 -> V_46 )
V_287 -> V_225 = V_115 -> V_46 -> V_38 . V_27 ;
else
V_287 -> V_225 = 0 ;
F_130 ( & V_17 -> V_23 . V_107 ) ;
V_287 -> V_117 = V_115 -> V_117 ;
V_287 -> V_227 = V_115 -> V_38 . V_27 ;
V_287 -> V_62 = V_115 -> V_62 ;
V_287 -> V_288 = V_115 -> V_288 ;
return 0 ;
}
int F_135 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_289 * V_290 = V_212 ;
struct V_54 * V_55 ;
struct V_47 * V_48 ;
T_1 T_2 * V_291 ;
int V_223 = 0 ;
unsigned V_292 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
V_55 = & V_17 -> V_23 ;
if ( V_214 -> V_293 )
V_292 = V_55 -> V_129 ;
else
V_292 = V_55 -> V_131 ;
if ( V_292 &&
( V_290 -> V_294 >= V_292 ) ) {
V_291 = ( T_1 T_2 * ) ( unsigned long ) V_290 -> V_295 ;
F_49 (plane, &config->plane_list, head) {
if ( V_48 -> type != V_130 &&
! V_214 -> V_293 )
continue;
if ( F_118 ( V_48 -> V_38 . V_27 , V_291 + V_223 ) )
return - V_232 ;
V_223 ++ ;
}
}
V_290 -> V_294 = V_292 ;
return 0 ;
}
int F_136 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_296 * V_290 = V_212 ;
struct V_47 * V_48 ;
T_1 T_2 * V_297 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
V_48 = F_137 ( V_17 , V_290 -> V_298 ) ;
if ( ! V_48 )
return - V_248 ;
F_129 ( & V_48 -> V_57 , NULL ) ;
if ( V_48 -> V_46 )
V_290 -> V_225 = V_48 -> V_46 -> V_38 . V_27 ;
else
V_290 -> V_225 = 0 ;
if ( V_48 -> V_32 )
V_290 -> V_224 = V_48 -> V_32 -> V_38 . V_27 ;
else
V_290 -> V_224 = 0 ;
F_130 ( & V_48 -> V_57 ) ;
V_290 -> V_298 = V_48 -> V_38 . V_27 ;
V_290 -> V_62 = V_48 -> V_62 ;
V_290 -> V_251 = 0 ;
if ( V_48 -> V_124 &&
( V_290 -> V_299 >= V_48 -> V_124 ) ) {
V_297 = ( T_1 T_2 * ) ( unsigned long ) V_290 -> V_300 ;
if ( F_131 ( V_297 ,
V_48 -> V_127 ,
sizeof( T_1 ) * V_48 -> V_124 ) ) {
return - V_232 ;
}
}
V_290 -> V_299 = V_48 -> V_124 ;
return 0 ;
}
static int F_138 ( struct V_47 * V_48 ,
struct V_45 * V_46 ,
struct V_31 * V_32 ,
T_4 V_301 , T_4 V_302 ,
T_1 V_303 , T_1 V_304 ,
T_1 V_305 , T_1 V_306 ,
T_1 V_307 , T_1 V_308 )
{
int V_22 = 0 ;
unsigned int V_309 , V_310 ;
unsigned int V_1 ;
if ( ! V_32 ) {
V_48 -> V_135 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_136 ( V_48 ) ;
if ( ! V_22 ) {
V_48 -> V_46 = NULL ;
V_48 -> V_32 = NULL ;
} else {
V_48 -> V_135 = NULL ;
}
goto V_39;
}
if ( ! ( V_48 -> V_62 & F_139 ( V_46 ) ) ) {
F_67 ( L_50 ) ;
V_22 = - V_211 ;
goto V_39;
}
for ( V_1 = 0 ; V_1 < V_48 -> V_124 ; V_1 ++ )
if ( V_32 -> V_311 == V_48 -> V_127 [ V_1 ] )
break;
if ( V_1 == V_48 -> V_124 ) {
F_67 ( L_51 ,
F_9 ( V_32 -> V_311 ) ) ;
V_22 = - V_211 ;
goto V_39;
}
V_309 = V_32 -> V_312 << 16 ;
V_310 = V_32 -> V_313 << 16 ;
if ( V_307 > V_309 ||
V_305 > V_309 - V_307 ||
V_308 > V_310 ||
V_306 > V_310 - V_308 ) {
F_67 ( L_52
L_53 ,
V_307 >> 16 , ( ( V_307 & 0xffff ) * 15625 ) >> 10 ,
V_308 >> 16 , ( ( V_308 & 0xffff ) * 15625 ) >> 10 ,
V_305 >> 16 , ( ( V_305 & 0xffff ) * 15625 ) >> 10 ,
V_306 >> 16 , ( ( V_306 & 0xffff ) * 15625 ) >> 10 ) ;
V_22 = - V_314 ;
goto V_39;
}
V_48 -> V_135 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_315 ( V_48 , V_46 , V_32 ,
V_301 , V_302 , V_303 , V_304 ,
V_305 , V_306 , V_307 , V_308 ) ;
if ( ! V_22 ) {
V_48 -> V_46 = V_46 ;
V_48 -> V_32 = V_32 ;
V_32 = NULL ;
} else {
V_48 -> V_135 = NULL ;
}
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
if ( V_48 -> V_135 )
F_34 ( V_48 -> V_135 ) ;
V_48 -> V_135 = NULL ;
return V_22 ;
}
static int F_140 ( struct V_47 * V_48 ,
struct V_45 * V_46 ,
struct V_31 * V_32 ,
T_4 V_301 , T_4 V_302 ,
T_1 V_303 , T_1 V_304 ,
T_1 V_305 , T_1 V_306 ,
T_1 V_307 , T_1 V_308 )
{
int V_22 ;
F_48 ( V_48 -> V_17 ) ;
V_22 = F_138 ( V_48 , V_46 , V_32 ,
V_301 , V_302 , V_303 , V_304 ,
V_305 , V_306 , V_307 , V_308 ) ;
F_53 ( V_48 -> V_17 ) ;
return V_22 ;
}
int F_141 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_316 * V_317 = V_212 ;
struct V_47 * V_48 ;
struct V_45 * V_46 = NULL ;
struct V_31 * V_32 = NULL ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
if ( V_317 -> V_303 > V_207 ||
V_317 -> V_301 > V_207 - ( T_4 ) V_317 -> V_303 ||
V_317 -> V_304 > V_207 ||
V_317 -> V_302 > V_207 - ( T_4 ) V_317 -> V_304 ) {
F_67 ( L_54 ,
V_317 -> V_303 , V_317 -> V_304 ,
V_317 -> V_301 , V_317 -> V_302 ) ;
return - V_208 ;
}
V_48 = F_137 ( V_17 , V_317 -> V_298 ) ;
if ( ! V_48 ) {
F_67 ( L_55 ,
V_317 -> V_298 ) ;
return - V_248 ;
}
if ( V_317 -> V_224 ) {
V_32 = F_32 ( V_17 , V_317 -> V_224 ) ;
if ( ! V_32 ) {
F_67 ( L_56 ,
V_317 -> V_224 ) ;
return - V_248 ;
}
V_46 = F_121 ( V_17 , V_317 -> V_225 ) ;
if ( ! V_46 ) {
F_67 ( L_57 ,
V_317 -> V_225 ) ;
return - V_248 ;
}
}
return F_140 ( V_48 , V_46 , V_32 ,
V_317 -> V_301 , V_317 -> V_302 ,
V_317 -> V_303 , V_317 -> V_304 ,
V_317 -> V_305 , V_317 -> V_306 ,
V_317 -> V_307 , V_317 -> V_308 ) ;
}
int F_50 ( struct V_49 * V_50 )
{
struct V_45 * V_46 = V_50 -> V_46 ;
struct V_31 * V_32 ;
struct V_45 * V_67 ;
int V_22 ;
F_49 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_67 -> V_51 -> V_135 = V_67 -> V_51 -> V_32 ;
V_32 = V_50 -> V_32 ;
V_22 = V_46 -> V_34 -> V_318 ( V_50 ) ;
if ( V_22 == 0 ) {
V_46 -> V_51 -> V_46 = V_46 ;
V_46 -> V_51 -> V_32 = V_32 ;
}
F_49 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_67 -> V_51 -> V_32 )
F_38 ( V_67 -> V_51 -> V_32 ) ;
if ( V_67 -> V_51 -> V_135 )
F_34 ( V_67 -> V_51 -> V_135 ) ;
V_67 -> V_51 -> V_135 = NULL ;
}
return V_22 ;
}
int F_142 ( const struct V_45 * V_46 ,
int V_249 , int V_250 ,
const struct V_70 * V_71 ,
const struct V_31 * V_32 )
{
int V_193 , V_199 ;
V_193 = V_71 -> V_193 ;
V_199 = V_71 -> V_199 ;
if ( F_125 ( V_71 ) ) {
struct V_70 V_319 = * V_71 ;
F_143 ( & V_319 , V_320 ) ;
V_193 = V_319 . V_321 ;
V_199 = V_319 . V_322 ;
}
if ( V_46 -> V_56 )
F_144 ( V_193 , V_199 ) ;
if ( V_193 > V_32 -> V_312 ||
V_199 > V_32 -> V_313 ||
V_249 > V_32 -> V_312 - V_193 ||
V_250 > V_32 -> V_313 - V_199 ) {
F_67 ( L_58 ,
V_32 -> V_312 , V_32 -> V_313 , V_193 , V_199 , V_249 , V_250 ,
V_46 -> V_56 ? L_59 : L_15 ) ;
return - V_314 ;
}
return 0 ;
}
int F_145 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
struct V_246 * V_323 = V_212 ;
struct V_45 * V_46 ;
struct V_68 * * V_324 = NULL , * V_69 ;
struct V_31 * V_32 = NULL ;
struct V_70 * V_71 = NULL ;
struct V_49 V_50 ;
T_1 T_2 * V_325 ;
int V_22 ;
int V_1 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
if ( V_323 -> V_249 > V_207 || V_323 -> V_250 > V_207 )
return - V_208 ;
F_48 ( V_17 ) ;
V_46 = F_121 ( V_17 , V_323 -> V_225 ) ;
if ( ! V_46 ) {
F_67 ( L_60 , V_323 -> V_225 ) ;
V_22 = - V_248 ;
goto V_39;
}
F_67 ( L_45 , V_46 -> V_38 . V_27 ) ;
if ( V_323 -> V_253 ) {
if ( V_323 -> V_224 == - 1 ) {
if ( ! V_46 -> V_51 -> V_32 ) {
F_67 ( L_61 ) ;
V_22 = - V_211 ;
goto V_39;
}
V_32 = V_46 -> V_51 -> V_32 ;
F_38 ( V_32 ) ;
} else {
V_32 = F_32 ( V_17 , V_323 -> V_224 ) ;
if ( ! V_32 ) {
F_67 ( L_62 ,
V_323 -> V_224 ) ;
V_22 = - V_248 ;
goto V_39;
}
}
V_71 = F_146 ( V_17 ) ;
if ( ! V_71 ) {
V_22 = - V_94 ;
goto V_39;
}
V_22 = F_114 ( V_71 , & V_323 -> V_71 ) ;
if ( V_22 ) {
F_67 ( L_63 ) ;
goto V_39;
}
F_143 ( V_71 , V_326 ) ;
V_22 = F_142 ( V_46 , V_323 -> V_249 , V_323 -> V_250 ,
V_71 , V_32 ) ;
if ( V_22 )
goto V_39;
}
if ( V_323 -> V_243 == 0 && V_71 ) {
F_67 ( L_64 ) ;
V_22 = - V_211 ;
goto V_39;
}
if ( V_323 -> V_243 > 0 && ( ! V_71 || ! V_32 ) ) {
F_67 ( L_65 ,
V_323 -> V_243 ) ;
V_22 = - V_211 ;
goto V_39;
}
if ( V_323 -> V_243 > 0 ) {
T_5 V_327 ;
if ( V_323 -> V_243 > V_55 -> V_100 ) {
V_22 = - V_211 ;
goto V_39;
}
V_324 = F_90 ( V_323 -> V_243 *
sizeof( struct V_68 * ) ,
V_26 ) ;
if ( ! V_324 ) {
V_22 = - V_94 ;
goto V_39;
}
for ( V_1 = 0 ; V_1 < V_323 -> V_243 ; V_1 ++ ) {
V_325 = ( T_1 T_2 * ) ( unsigned long ) V_323 -> V_325 ;
if ( F_147 ( V_327 , & V_325 [ V_1 ] ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_69 = F_128 ( V_17 , V_327 ) ;
if ( ! V_69 ) {
F_67 ( L_66 ,
V_327 ) ;
V_22 = - V_248 ;
goto V_39;
}
F_67 ( L_47 ,
V_69 -> V_38 . V_27 ,
V_69 -> V_11 ) ;
V_324 [ V_1 ] = V_69 ;
}
}
V_50 . V_46 = V_46 ;
V_50 . V_249 = V_323 -> V_249 ;
V_50 . V_250 = V_323 -> V_250 ;
V_50 . V_71 = V_71 ;
V_50 . V_328 = V_324 ;
V_50 . V_187 = V_323 -> V_243 ;
V_50 . V_32 = V_32 ;
V_22 = F_50 ( & V_50 ) ;
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
F_59 ( V_324 ) ;
F_62 ( V_17 , V_71 ) ;
F_53 ( V_17 ) ;
return V_22 ;
}
static int F_148 ( struct V_45 * V_46 ,
struct V_329 * V_330 ,
struct V_213 * V_214 )
{
struct V_16 * V_17 = V_46 -> V_17 ;
struct V_31 * V_32 = NULL ;
struct V_331 V_332 = {
. V_312 = V_330 -> V_312 ,
. V_313 = V_330 -> V_313 ,
. V_311 = V_333 ,
. V_334 = { V_330 -> V_312 * 4 } ,
. V_335 = { V_330 -> V_336 } ,
} ;
T_4 V_301 , V_302 ;
T_1 V_303 = 0 , V_304 = 0 ;
T_1 V_307 = 0 , V_308 = 0 ;
int V_22 = 0 ;
F_93 ( ! V_46 -> V_52 ) ;
F_22 ( V_46 -> V_52 -> V_46 != V_46 && V_46 -> V_52 -> V_46 != NULL ) ;
if ( V_330 -> V_205 & V_337 ) {
if ( V_330 -> V_336 ) {
V_32 = F_149 ( V_17 , & V_332 , V_214 ) ;
if ( F_150 ( V_32 ) ) {
F_67 ( L_67 ) ;
return F_151 ( V_32 ) ;
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
if ( V_330 -> V_205 & V_338 ) {
V_301 = V_330 -> V_249 ;
V_302 = V_330 -> V_250 ;
} else {
V_301 = V_46 -> V_339 ;
V_302 = V_46 -> V_340 ;
}
if ( V_32 ) {
V_303 = V_32 -> V_312 ;
V_304 = V_32 -> V_313 ;
V_307 = V_32 -> V_312 << 16 ;
V_308 = V_32 -> V_313 << 16 ;
}
V_22 = F_138 ( V_46 -> V_52 , V_46 , V_32 ,
V_301 , V_302 , V_303 , V_304 ,
0 , 0 , V_307 , V_308 ) ;
if ( V_22 == 0 && V_330 -> V_205 & V_338 ) {
V_46 -> V_339 = V_330 -> V_249 ;
V_46 -> V_340 = V_330 -> V_250 ;
}
return V_22 ;
}
static int F_152 ( struct V_16 * V_17 ,
struct V_329 * V_330 ,
struct V_213 * V_214 )
{
struct V_45 * V_46 ;
int V_22 = 0 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
if ( ! V_330 -> V_205 || ( ~ V_341 & V_330 -> V_205 ) )
return - V_211 ;
V_46 = F_121 ( V_17 , V_330 -> V_225 ) ;
if ( ! V_46 ) {
F_67 ( L_60 , V_330 -> V_225 ) ;
return - V_248 ;
}
F_122 ( V_46 , V_46 -> V_52 ) ;
if ( V_46 -> V_52 ) {
V_22 = F_148 ( V_46 , V_330 , V_214 ) ;
goto V_39;
}
if ( V_330 -> V_205 & V_337 ) {
if ( ! V_46 -> V_34 -> V_342 && ! V_46 -> V_34 -> V_343 ) {
V_22 = - V_344 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_343 )
V_22 = V_46 -> V_34 -> V_343 ( V_46 , V_214 , V_330 -> V_336 ,
V_330 -> V_312 , V_330 -> V_313 , V_330 -> V_345 , V_330 -> V_346 ) ;
else
V_22 = V_46 -> V_34 -> V_342 ( V_46 , V_214 , V_330 -> V_336 ,
V_330 -> V_312 , V_330 -> V_313 ) ;
}
if ( V_330 -> V_205 & V_338 ) {
if ( V_46 -> V_34 -> V_347 ) {
V_22 = V_46 -> V_34 -> V_347 ( V_46 , V_330 -> V_249 , V_330 -> V_250 ) ;
} else {
V_22 = - V_232 ;
goto V_39;
}
}
V_39:
F_123 ( V_46 ) ;
return V_22 ;
}
int F_153 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_348 * V_330 = V_212 ;
struct V_329 V_349 ;
memcpy ( & V_349 , V_330 , sizeof( struct V_348 ) ) ;
V_349 . V_345 = V_349 . V_346 = 0 ;
return F_152 ( V_17 , & V_349 , V_214 ) ;
}
int F_154 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_329 * V_330 = V_212 ;
return F_152 ( V_17 , V_330 , V_214 ) ;
}
T_1 F_155 ( T_1 V_350 , T_1 V_351 )
{
T_1 V_352 ;
switch ( V_350 ) {
case 8 :
V_352 = V_353 ;
break;
case 16 :
if ( V_351 == 15 )
V_352 = V_354 ;
else
V_352 = V_355 ;
break;
case 24 :
V_352 = V_356 ;
break;
case 32 :
if ( V_351 == 24 )
V_352 = V_357 ;
else if ( V_351 == 30 )
V_352 = V_358 ;
else
V_352 = V_333 ;
break;
default:
F_51 ( L_68 ) ;
V_352 = V_357 ;
break;
}
return V_352 ;
}
int F_156 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_359 * V_360 = V_212 ;
struct V_331 V_361 = {} ;
int V_22 ;
V_361 . V_224 = V_360 -> V_224 ;
V_361 . V_312 = V_360 -> V_312 ;
V_361 . V_313 = V_360 -> V_313 ;
V_361 . V_334 [ 0 ] = V_360 -> V_362 ;
V_361 . V_311 = F_155 ( V_360 -> V_350 , V_360 -> V_351 ) ;
V_361 . V_335 [ 0 ] = V_360 -> V_336 ;
V_22 = F_157 ( V_17 , & V_361 , V_214 ) ;
if ( V_22 )
return V_22 ;
V_360 -> V_224 = V_361 . V_224 ;
return 0 ;
}
static int F_158 ( const struct V_331 * V_361 )
{
T_1 V_13 = V_361 -> V_311 & ~ V_15 ;
switch ( V_13 ) {
case V_353 :
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
case V_354 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_355 :
case V_380 :
case V_356 :
case V_381 :
case V_357 :
case V_382 :
case V_383 :
case V_384 :
case V_333 :
case V_385 :
case V_386 :
case V_387 :
case V_358 :
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
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
return 0 ;
default:
F_67 ( L_69 ,
F_9 ( V_361 -> V_311 ) ) ;
return - V_211 ;
}
}
static int F_159 ( const struct V_331 * V_361 )
{
int V_22 , V_416 , V_417 , V_292 , V_1 ;
V_22 = F_158 ( V_361 ) ;
if ( V_22 ) {
F_67 ( L_70 ,
F_9 ( V_361 -> V_311 ) ) ;
return V_22 ;
}
V_416 = F_160 ( V_361 -> V_311 ) ;
V_417 = F_161 ( V_361 -> V_311 ) ;
V_292 = F_162 ( V_361 -> V_311 ) ;
if ( V_361 -> V_312 == 0 || V_361 -> V_312 % V_416 ) {
F_67 ( L_71 , V_361 -> V_312 ) ;
return - V_211 ;
}
if ( V_361 -> V_313 == 0 || V_361 -> V_313 % V_417 ) {
F_67 ( L_72 , V_361 -> V_313 ) ;
return - V_211 ;
}
for ( V_1 = 0 ; V_1 < V_292 ; V_1 ++ ) {
unsigned int V_312 = V_361 -> V_312 / ( V_1 != 0 ? V_416 : 1 ) ;
unsigned int V_313 = V_361 -> V_313 / ( V_1 != 0 ? V_417 : 1 ) ;
unsigned int V_418 = F_163 ( V_361 -> V_311 , V_1 ) ;
if ( ! V_361 -> V_335 [ V_1 ] ) {
F_67 ( L_73 , V_1 ) ;
return - V_211 ;
}
if ( ( T_3 ) V_312 * V_418 > V_419 )
return - V_208 ;
if ( ( T_3 ) V_313 * V_361 -> V_334 [ V_1 ] + V_361 -> V_420 [ V_1 ] > V_419 )
return - V_208 ;
if ( V_361 -> V_334 [ V_1 ] < V_312 * V_418 ) {
F_67 ( L_74 , V_361 -> V_334 [ V_1 ] , V_1 ) ;
return - V_211 ;
}
}
return 0 ;
}
static struct V_31 * F_149 ( struct V_16 * V_17 ,
struct V_331 * V_361 ,
struct V_213 * V_214 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
struct V_31 * V_32 ;
int V_22 ;
if ( V_361 -> V_205 & ~ V_421 ) {
F_67 ( L_75 , V_361 -> V_205 ) ;
return F_164 ( - V_211 ) ;
}
if ( ( V_55 -> V_238 > V_361 -> V_312 ) || ( V_361 -> V_312 > V_55 -> V_237 ) ) {
F_67 ( L_76 ,
V_361 -> V_312 , V_55 -> V_238 , V_55 -> V_237 ) ;
return F_164 ( - V_211 ) ;
}
if ( ( V_55 -> V_236 > V_361 -> V_313 ) || ( V_361 -> V_313 > V_55 -> V_235 ) ) {
F_67 ( L_77 ,
V_361 -> V_313 , V_55 -> V_236 , V_55 -> V_235 ) ;
return F_164 ( - V_211 ) ;
}
V_22 = F_159 ( V_361 ) ;
if ( V_22 )
return F_164 ( V_22 ) ;
V_32 = V_17 -> V_23 . V_34 -> V_422 ( V_17 , V_214 , V_361 ) ;
if ( F_150 ( V_32 ) ) {
F_67 ( L_78 ) ;
return V_32 ;
}
F_11 ( & V_214 -> V_229 ) ;
V_361 -> V_224 = V_32 -> V_38 . V_27 ;
F_26 ( & V_32 -> V_37 , & V_214 -> V_423 ) ;
F_67 ( L_79 , V_32 -> V_38 . V_27 ) ;
F_13 ( & V_214 -> V_229 ) ;
return V_32 ;
}
int F_157 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_31 * V_32 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
V_32 = F_149 ( V_17 , V_212 , V_214 ) ;
if ( F_150 ( V_32 ) )
return F_151 ( V_32 ) ;
return 0 ;
}
int F_165 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_31 * V_32 = NULL ;
struct V_31 * V_424 = NULL ;
T_1 * V_27 = V_212 ;
int V_425 = 0 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
F_11 ( & V_214 -> V_229 ) ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
V_32 = F_30 ( V_17 , * V_27 ) ;
if ( ! V_32 )
goto V_426;
F_49 (fbl, &file_priv->fbs, filp_head)
if ( V_32 == V_424 )
V_425 = 1 ;
if ( ! V_425 )
goto V_426;
F_27 ( V_17 , V_32 ) ;
F_166 ( & V_32 -> V_37 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_13 ( & V_214 -> V_229 ) ;
F_46 ( V_32 ) ;
return 0 ;
V_426:
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_13 ( & V_214 -> V_229 ) ;
return - V_248 ;
}
int F_167 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_359 * V_361 = V_212 ;
struct V_31 * V_32 ;
int V_22 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
V_32 = F_32 ( V_17 , V_361 -> V_224 ) ;
if ( ! V_32 )
return - V_248 ;
V_361 -> V_313 = V_32 -> V_313 ;
V_361 -> V_312 = V_32 -> V_312 ;
V_361 -> V_351 = V_32 -> V_351 ;
V_361 -> V_350 = V_32 -> V_427 ;
V_361 -> V_362 = V_32 -> V_334 [ 0 ] ;
if ( V_32 -> V_34 -> V_428 ) {
if ( V_214 -> V_429 || F_168 ( V_430 ) ||
F_169 ( V_214 ) ) {
V_22 = V_32 -> V_34 -> V_428 ( V_32 , V_214 ,
& V_361 -> V_336 ) ;
} else {
V_361 -> V_336 = 0 ;
V_22 = 0 ;
}
} else {
V_22 = - V_431 ;
}
F_34 ( V_32 ) ;
return V_22 ;
}
int F_170 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_432 T_2 * V_433 ;
struct V_432 * V_434 = NULL ;
struct V_435 * V_361 = V_212 ;
struct V_31 * V_32 ;
unsigned V_205 ;
int V_436 ;
int V_22 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
V_32 = F_32 ( V_17 , V_361 -> V_224 ) ;
if ( ! V_32 )
return - V_248 ;
V_436 = V_361 -> V_436 ;
V_433 = (struct V_432 T_2 * ) ( unsigned long ) V_361 -> V_433 ;
if ( ! V_436 != ! V_433 ) {
V_22 = - V_211 ;
goto V_437;
}
V_205 = V_438 & V_361 -> V_205 ;
if ( V_205 & V_439 && ( V_436 % 2 ) ) {
V_22 = - V_211 ;
goto V_437;
}
if ( V_436 && V_433 ) {
if ( V_436 < 0 || V_436 > V_440 ) {
V_22 = - V_211 ;
goto V_437;
}
V_434 = F_108 ( V_436 * sizeof( * V_434 ) , V_26 ) ;
if ( ! V_434 ) {
V_22 = - V_94 ;
goto V_437;
}
V_22 = F_171 ( V_434 , V_433 ,
V_436 * sizeof( * V_434 ) ) ;
if ( V_22 ) {
V_22 = - V_232 ;
goto V_441;
}
}
if ( V_32 -> V_34 -> V_442 ) {
V_22 = V_32 -> V_34 -> V_442 ( V_32 , V_214 , V_205 , V_361 -> V_443 ,
V_434 , V_436 ) ;
} else {
V_22 = - V_444 ;
}
V_441:
F_59 ( V_434 ) ;
V_437:
F_34 ( V_32 ) ;
return V_22 ;
}
void F_172 ( struct V_213 * V_445 )
{
struct V_16 * V_17 = V_445 -> V_234 -> V_17 ;
struct V_31 * V_32 , * V_446 ;
F_74 (fb, tfb, &priv->fbs, filp_head) {
F_11 ( & V_17 -> V_23 . V_35 ) ;
F_27 ( V_17 , V_32 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_166 ( & V_32 -> V_37 ) ;
F_46 ( V_32 ) ;
}
}
struct V_137 * F_96 ( struct V_16 * V_17 , int V_205 ,
const char * V_11 , int V_447 )
{
struct V_137 * V_448 = NULL ;
int V_22 ;
V_448 = F_108 ( sizeof( struct V_137 ) , V_26 ) ;
if ( ! V_448 )
return NULL ;
V_448 -> V_17 = V_17 ;
if ( V_447 ) {
V_448 -> V_283 = F_108 ( sizeof( T_3 ) * V_447 , V_26 ) ;
if ( ! V_448 -> V_283 )
goto V_449;
}
V_22 = F_14 ( V_17 , & V_448 -> V_38 , V_450 ) ;
if ( V_22 )
goto V_449;
V_448 -> V_205 = V_205 ;
V_448 -> V_447 = V_447 ;
F_25 ( & V_448 -> V_451 ) ;
if ( V_11 ) {
strncpy ( V_448 -> V_11 , V_11 , V_452 ) ;
V_448 -> V_11 [ V_452 - 1 ] = '\0' ;
}
F_56 ( & V_448 -> V_41 , & V_17 -> V_23 . V_453 ) ;
F_22 ( ! F_173 ( V_448 ) ) ;
return V_448 ;
V_449:
F_59 ( V_448 -> V_283 ) ;
F_59 ( V_448 ) ;
return NULL ;
}
struct V_137 * F_97 ( struct V_16 * V_17 , int V_205 ,
const char * V_11 ,
const struct V_454 * V_455 ,
int V_447 )
{
struct V_137 * V_448 ;
int V_1 , V_22 ;
V_205 |= V_165 ;
V_448 = F_96 ( V_17 , V_205 , V_11 , V_447 ) ;
if ( ! V_448 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_447 ; V_1 ++ ) {
V_22 = F_102 ( V_448 , V_1 ,
V_455 [ V_1 ] . type ,
V_455 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_174 ( V_17 , V_448 ) ;
return NULL ;
}
}
return V_448 ;
}
struct V_137 * F_175 ( struct V_16 * V_17 ,
int V_205 , const char * V_11 ,
const struct V_454 * V_455 ,
int V_456 ,
T_3 V_457 )
{
struct V_137 * V_448 ;
int V_1 , V_22 , V_66 = 0 ;
int V_447 = F_176 ( V_457 ) ;
V_205 |= V_458 ;
V_448 = F_96 ( V_17 , V_205 , V_11 , V_447 ) ;
if ( ! V_448 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_456 ; V_1 ++ ) {
if ( ! ( V_457 & ( 1ULL << V_455 [ V_1 ] . type ) ) )
continue;
if ( F_22 ( V_66 >= V_447 ) ) {
F_174 ( V_17 , V_448 ) ;
return NULL ;
}
V_22 = F_102 ( V_448 , V_66 ++ ,
V_455 [ V_1 ] . type ,
V_455 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_174 ( V_17 , V_448 ) ;
return NULL ;
}
}
return V_448 ;
}
static struct V_137 * F_177 ( struct V_16 * V_17 ,
int V_205 , const char * V_11 ,
T_3 V_459 , T_3 V_460 )
{
struct V_137 * V_448 ;
V_448 = F_96 ( V_17 , V_205 , V_11 , 2 ) ;
if ( ! V_448 )
return NULL ;
V_448 -> V_283 [ 0 ] = V_459 ;
V_448 -> V_283 [ 1 ] = V_460 ;
return V_448 ;
}
struct V_137 * F_101 ( struct V_16 * V_17 , int V_205 ,
const char * V_11 ,
T_3 V_459 , T_3 V_460 )
{
return F_177 ( V_17 , V_461 | V_205 ,
V_11 , V_459 , V_460 ) ;
}
struct V_137 * F_178 ( struct V_16 * V_17 ,
int V_205 , const char * V_11 ,
T_6 V_459 , T_6 V_460 )
{
return F_177 ( V_17 , V_462 | V_205 ,
V_11 , F_179 ( V_459 ) , F_179 ( V_460 ) ) ;
}
struct V_137 * F_180 ( struct V_16 * V_17 ,
int V_205 , const char * V_11 , T_1 type )
{
struct V_137 * V_448 ;
V_205 |= V_463 ;
V_448 = F_96 ( V_17 , V_205 , V_11 , 1 ) ;
if ( ! V_448 )
return NULL ;
V_448 -> V_283 [ 0 ] = type ;
return V_448 ;
}
int F_102 ( struct V_137 * V_448 , int V_66 ,
T_3 V_464 , const char * V_11 )
{
struct V_465 * V_466 ;
if ( ! ( F_181 ( V_448 , V_165 ) ||
F_181 ( V_448 , V_458 ) ) )
return - V_211 ;
if ( F_181 ( V_448 , V_458 ) &&
( V_464 > 63 ) )
return - V_211 ;
if ( ! F_47 ( & V_448 -> V_451 ) ) {
F_49 (prop_enum, &property->enum_list, head) {
if ( V_466 -> V_464 == V_464 ) {
strncpy ( V_466 -> V_11 , V_11 , V_452 ) ;
V_466 -> V_11 [ V_452 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_466 = F_108 ( sizeof( struct V_465 ) , V_26 ) ;
if ( ! V_466 )
return - V_94 ;
strncpy ( V_466 -> V_11 , V_11 , V_452 ) ;
V_466 -> V_11 [ V_452 - 1 ] = '\0' ;
V_466 -> V_464 = V_464 ;
V_448 -> V_283 [ V_66 ] = V_464 ;
F_56 ( & V_466 -> V_41 , & V_448 -> V_451 ) ;
return 0 ;
}
void F_174 ( struct V_16 * V_17 , struct V_137 * V_448 )
{
struct V_465 * V_466 , * V_467 ;
F_74 (prop_enum, pt, &property->enum_list, head) {
F_45 ( & V_466 -> V_41 ) ;
F_59 ( V_466 ) ;
}
if ( V_448 -> V_447 )
F_59 ( V_448 -> V_283 ) ;
F_17 ( V_17 , & V_448 -> V_38 ) ;
F_45 ( & V_448 -> V_41 ) ;
F_59 ( V_448 ) ;
}
void F_71 ( struct V_18 * V_19 ,
struct V_137 * V_448 ,
T_3 V_468 )
{
int V_266 = V_19 -> V_59 -> V_266 ;
if ( V_266 == V_469 ) {
F_113 ( 1 , L_80
L_81
L_82 ,
V_19 -> type ) ;
return;
}
V_19 -> V_59 -> V_282 [ V_266 ] = V_448 -> V_38 . V_27 ;
V_19 -> V_59 -> V_283 [ V_266 ] = V_468 ;
V_19 -> V_59 -> V_266 ++ ;
}
int F_182 ( struct V_18 * V_19 ,
struct V_137 * V_448 , T_3 V_470 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_59 -> V_266 ; V_1 ++ ) {
if ( V_19 -> V_59 -> V_282 [ V_1 ] == V_448 -> V_38 . V_27 ) {
V_19 -> V_59 -> V_283 [ V_1 ] = V_470 ;
return 0 ;
}
}
return - V_211 ;
}
int F_183 ( struct V_18 * V_19 ,
struct V_137 * V_448 , T_3 * V_470 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_59 -> V_266 ; V_1 ++ ) {
if ( V_19 -> V_59 -> V_282 [ V_1 ] == V_448 -> V_38 . V_27 ) {
* V_470 = V_19 -> V_59 -> V_283 [ V_1 ] ;
return 0 ;
}
}
return - V_211 ;
}
int F_184 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_471 * V_257 = V_212 ;
struct V_137 * V_448 ;
int V_472 = 0 ;
int V_473 = 0 ;
int V_22 = 0 , V_1 ;
int V_223 ;
struct V_465 * V_466 ;
struct V_474 T_2 * V_475 ;
T_3 T_2 * V_476 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
F_48 ( V_17 ) ;
V_448 = F_185 ( V_17 , V_257 -> V_477 ) ;
if ( ! V_448 ) {
V_22 = - V_248 ;
goto V_478;
}
if ( F_181 ( V_448 , V_165 ) ||
F_181 ( V_448 , V_458 ) ) {
F_49 (prop_enum, &property->enum_list, head)
V_472 ++ ;
}
V_473 = V_448 -> V_447 ;
strncpy ( V_257 -> V_11 , V_448 -> V_11 , V_452 ) ;
V_257 -> V_11 [ V_452 - 1 ] = 0 ;
V_257 -> V_205 = V_448 -> V_205 ;
if ( ( V_257 -> V_479 >= V_473 ) && V_473 ) {
V_476 = ( T_3 T_2 * ) ( unsigned long ) V_257 -> V_476 ;
for ( V_1 = 0 ; V_1 < V_473 ; V_1 ++ ) {
if ( F_131 ( V_476 + V_1 , & V_448 -> V_283 [ V_1 ] , sizeof( T_3 ) ) ) {
V_22 = - V_232 ;
goto V_478;
}
}
}
V_257 -> V_479 = V_473 ;
if ( F_181 ( V_448 , V_165 ) ||
F_181 ( V_448 , V_458 ) ) {
if ( ( V_257 -> V_480 >= V_472 ) && V_472 ) {
V_223 = 0 ;
V_475 = (struct V_474 T_2 * ) ( unsigned long ) V_257 -> V_481 ;
F_49 (prop_enum, &property->enum_list, head) {
if ( F_131 ( & V_475 [ V_223 ] . V_464 , & V_466 -> V_464 , sizeof( T_3 ) ) ) {
V_22 = - V_232 ;
goto V_478;
}
if ( F_131 ( & V_475 [ V_223 ] . V_11 ,
& V_466 -> V_11 , V_452 ) ) {
V_22 = - V_232 ;
goto V_478;
}
V_223 ++ ;
}
}
V_257 -> V_480 = V_472 ;
}
if ( F_181 ( V_448 , V_141 ) )
V_257 -> V_480 = 0 ;
V_478:
F_53 ( V_17 ) ;
return V_22 ;
}
static struct V_482 *
F_186 ( struct V_16 * V_17 , T_7 V_483 ,
const void * V_212 )
{
struct V_482 * V_484 ;
int V_22 ;
if ( ! V_483 || ! V_212 )
return NULL ;
V_484 = F_108 ( sizeof( struct V_482 ) + V_483 , V_26 ) ;
if ( ! V_484 )
return NULL ;
V_22 = F_14 ( V_17 , & V_484 -> V_38 , V_485 ) ;
if ( V_22 ) {
F_59 ( V_484 ) ;
return NULL ;
}
V_484 -> V_483 = V_483 ;
memcpy ( V_484 -> V_212 , V_212 , V_483 ) ;
F_56 ( & V_484 -> V_41 , & V_17 -> V_23 . V_486 ) ;
return V_484 ;
}
static void F_187 ( struct V_16 * V_17 ,
struct V_482 * V_484 )
{
F_17 ( V_17 , & V_484 -> V_38 ) ;
F_45 ( & V_484 -> V_41 ) ;
F_59 ( V_484 ) ;
}
int F_188 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_487 * V_257 = V_212 ;
struct V_482 * V_484 ;
int V_22 = 0 ;
void T_2 * V_488 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
F_48 ( V_17 ) ;
V_484 = F_189 ( V_17 , V_257 -> V_489 ) ;
if ( ! V_484 ) {
V_22 = - V_248 ;
goto V_478;
}
if ( V_257 -> V_483 == V_484 -> V_483 ) {
V_488 = ( void T_2 * ) ( unsigned long ) V_257 -> V_212 ;
if ( F_131 ( V_488 , V_484 -> V_212 , V_484 -> V_483 ) ) {
V_22 = - V_232 ;
goto V_478;
}
}
V_257 -> V_483 = V_484 -> V_483 ;
V_478:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_190 ( struct V_68 * V_69 ,
const char * V_490 )
{
struct V_16 * V_17 = V_69 -> V_17 ;
T_7 V_491 = strlen ( V_490 ) + 1 ;
int V_22 ;
V_69 -> V_492 = F_186 ( V_69 -> V_17 ,
V_491 , V_490 ) ;
if ( ! V_69 -> V_492 )
return - V_211 ;
V_22 = F_182 ( & V_69 -> V_38 ,
V_17 -> V_23 . V_144 ,
V_69 -> V_492 -> V_38 . V_27 ) ;
return V_22 ;
}
int F_191 ( struct V_68 * V_69 )
{
struct V_16 * V_17 = V_69 -> V_17 ;
int V_22 , V_491 ;
char V_493 [ 256 ] ;
if ( V_69 -> V_494 )
F_187 ( V_17 , V_69 -> V_494 ) ;
if ( ! V_69 -> V_495 ) {
V_69 -> V_494 = NULL ;
V_22 = F_182 ( & V_69 -> V_38 ,
V_17 -> V_23 . V_145 , 0 ) ;
return V_22 ;
}
snprintf ( V_493 , 256 , L_83 ,
V_69 -> V_106 -> V_27 , V_69 -> V_496 ,
V_69 -> V_497 , V_69 -> V_498 ,
V_69 -> V_499 , V_69 -> V_500 ,
V_69 -> V_501 , V_69 -> V_502 ) ;
V_491 = strlen ( V_493 ) + 1 ;
V_69 -> V_494 = F_186 ( V_69 -> V_17 ,
V_491 , V_493 ) ;
if ( ! V_69 -> V_494 )
return - V_211 ;
V_22 = F_182 ( & V_69 -> V_38 ,
V_17 -> V_23 . V_145 ,
V_69 -> V_494 -> V_38 . V_27 ) ;
return V_22 ;
}
int F_192 ( struct V_68 * V_69 ,
const struct V_138 * V_138 )
{
struct V_16 * V_17 = V_69 -> V_17 ;
T_7 V_491 ;
int V_22 ;
if ( V_69 -> V_503 )
return 0 ;
if ( V_69 -> V_97 )
F_187 ( V_17 , V_69 -> V_97 ) ;
if ( ! V_138 ) {
V_69 -> V_97 = NULL ;
V_22 = F_182 ( & V_69 -> V_38 , V_17 -> V_23 . V_102 , 0 ) ;
return V_22 ;
}
V_491 = V_504 * ( 1 + V_138 -> V_505 ) ;
V_69 -> V_97 = F_186 ( V_69 -> V_17 ,
V_491 , V_138 ) ;
if ( ! V_69 -> V_97 )
return - V_211 ;
V_22 = F_182 ( & V_69 -> V_38 ,
V_17 -> V_23 . V_102 ,
V_69 -> V_97 -> V_38 . V_27 ) ;
return V_22 ;
}
static bool F_193 ( struct V_137 * V_448 ,
T_3 V_464 )
{
if ( V_448 -> V_205 & V_142 )
return false ;
if ( F_181 ( V_448 , V_461 ) ) {
if ( V_464 < V_448 -> V_283 [ 0 ] || V_464 > V_448 -> V_283 [ 1 ] )
return false ;
return true ;
} else if ( F_181 ( V_448 , V_462 ) ) {
T_6 V_506 = F_194 ( V_464 ) ;
if ( V_506 < F_194 ( V_448 -> V_283 [ 0 ] ) ||
V_506 > F_194 ( V_448 -> V_283 [ 1 ] ) )
return false ;
return true ;
} else if ( F_181 ( V_448 , V_458 ) ) {
int V_1 ;
T_3 V_507 = 0 ;
for ( V_1 = 0 ; V_1 < V_448 -> V_447 ; V_1 ++ )
V_507 |= ( 1ULL << V_448 -> V_283 [ V_1 ] ) ;
return ! ( V_464 & ~ V_507 ) ;
} else if ( F_181 ( V_448 , V_141 ) ) {
return true ;
} else if ( F_181 ( V_448 , V_463 ) ) {
struct V_18 * V_19 ;
if ( V_464 == 0 )
return true ;
V_19 = F_19 ( V_448 -> V_17 , V_464 , V_448 -> V_283 [ 0 ] ) ;
return V_19 != NULL ;
} else {
int V_1 ;
for ( V_1 = 0 ; V_1 < V_448 -> V_447 ; V_1 ++ )
if ( V_448 -> V_283 [ V_1 ] == V_464 )
return true ;
return false ;
}
}
int F_195 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_508 * V_509 = V_212 ;
struct V_510 V_511 = {
. V_464 = V_509 -> V_464 ,
. V_477 = V_509 -> V_477 ,
. V_512 = V_509 -> V_226 ,
. V_20 = V_90
} ;
return F_196 ( V_17 , & V_511 , V_214 ) ;
}
static int F_197 ( struct V_18 * V_19 ,
struct V_137 * V_448 ,
T_3 V_464 )
{
int V_22 = - V_211 ;
struct V_68 * V_69 = F_198 ( V_19 ) ;
if ( V_448 == V_69 -> V_17 -> V_23 . V_103 ) {
if ( V_69 -> V_34 -> V_139 )
(* V_69 -> V_34 -> V_139 )( V_69 , ( int ) V_464 ) ;
V_22 = 0 ;
} else if ( V_69 -> V_34 -> V_513 )
V_22 = V_69 -> V_34 -> V_513 ( V_69 , V_448 , V_464 ) ;
if ( ! V_22 )
F_182 ( & V_69 -> V_38 , V_448 , V_464 ) ;
return V_22 ;
}
static int F_199 ( struct V_18 * V_19 ,
struct V_137 * V_448 ,
T_3 V_464 )
{
int V_22 = - V_211 ;
struct V_45 * V_46 = F_200 ( V_19 ) ;
if ( V_46 -> V_34 -> V_513 )
V_22 = V_46 -> V_34 -> V_513 ( V_46 , V_448 , V_464 ) ;
if ( ! V_22 )
F_182 ( V_19 , V_448 , V_464 ) ;
return V_22 ;
}
int F_201 ( struct V_47 * V_48 ,
struct V_137 * V_448 ,
T_3 V_464 )
{
int V_22 = - V_211 ;
struct V_18 * V_19 = & V_48 -> V_38 ;
if ( V_48 -> V_34 -> V_513 )
V_22 = V_48 -> V_34 -> V_513 ( V_48 , V_448 , V_464 ) ;
if ( ! V_22 )
F_182 ( V_19 , V_448 , V_464 ) ;
return V_22 ;
}
int F_202 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_514 * V_515 = V_212 ;
struct V_18 * V_19 ;
int V_22 = 0 ;
int V_1 ;
int V_223 = 0 ;
int V_259 = 0 ;
T_1 T_2 * V_280 ;
T_3 T_2 * V_281 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
F_48 ( V_17 ) ;
V_19 = F_21 ( V_17 , V_515 -> V_512 , V_515 -> V_20 ) ;
if ( ! V_19 ) {
V_22 = - V_248 ;
goto V_39;
}
if ( ! V_19 -> V_59 ) {
V_22 = - V_211 ;
goto V_39;
}
V_259 = V_19 -> V_59 -> V_266 ;
if ( ( V_515 -> V_279 >= V_259 ) && V_259 ) {
V_223 = 0 ;
V_280 = ( T_1 T_2 * ) ( unsigned long ) ( V_515 -> V_280 ) ;
V_281 = ( T_3 T_2 * ) ( unsigned long )
( V_515 -> V_281 ) ;
for ( V_1 = 0 ; V_1 < V_259 ; V_1 ++ ) {
if ( F_118 ( V_19 -> V_59 -> V_282 [ V_1 ] ,
V_280 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
if ( F_118 ( V_19 -> V_59 -> V_283 [ V_1 ] ,
V_281 + V_223 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_223 ++ ;
}
}
V_515 -> V_279 = V_259 ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_196 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_510 * V_515 = V_212 ;
struct V_18 * V_516 ;
struct V_18 * V_517 ;
struct V_137 * V_448 ;
int V_22 = - V_211 ;
int V_1 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
F_48 ( V_17 ) ;
V_516 = F_21 ( V_17 , V_515 -> V_512 , V_515 -> V_20 ) ;
if ( ! V_516 ) {
V_22 = - V_248 ;
goto V_39;
}
if ( ! V_516 -> V_59 )
goto V_39;
for ( V_1 = 0 ; V_1 < V_516 -> V_59 -> V_266 ; V_1 ++ )
if ( V_516 -> V_59 -> V_282 [ V_1 ] == V_515 -> V_477 )
break;
if ( V_1 == V_516 -> V_59 -> V_266 )
goto V_39;
V_517 = F_21 ( V_17 , V_515 -> V_477 ,
V_450 ) ;
if ( ! V_517 ) {
V_22 = - V_248 ;
goto V_39;
}
V_448 = F_203 ( V_517 ) ;
if ( ! F_193 ( V_448 , V_515 -> V_464 ) )
goto V_39;
switch ( V_516 -> type ) {
case V_90 :
V_22 = F_197 ( V_516 , V_448 ,
V_515 -> V_464 ) ;
break;
case V_58 :
V_22 = F_199 ( V_516 , V_448 , V_515 -> V_464 ) ;
break;
case V_126 :
V_22 = F_201 ( F_204 ( V_516 ) ,
V_448 , V_515 -> V_464 ) ;
break;
}
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_205 ( struct V_68 * V_69 ,
struct V_114 * V_115 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_267 ; V_1 ++ ) {
if ( V_69 -> V_268 [ V_1 ] == 0 ) {
V_69 -> V_268 [ V_1 ] = V_115 -> V_38 . V_27 ;
return 0 ;
}
}
return - V_94 ;
}
int F_206 ( struct V_45 * V_46 ,
int V_251 )
{
V_46 -> V_251 = V_251 ;
V_46 -> V_63 = F_108 ( V_251 * sizeof( V_518 ) * 3 , V_26 ) ;
if ( ! V_46 -> V_63 ) {
V_46 -> V_251 = 0 ;
return - V_94 ;
}
return 0 ;
}
int F_207 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_519 * V_520 = V_212 ;
struct V_45 * V_46 ;
void * V_521 , * V_522 , * V_523 ;
int V_491 ;
int V_22 = 0 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
F_48 ( V_17 ) ;
V_46 = F_121 ( V_17 , V_520 -> V_225 ) ;
if ( ! V_46 ) {
V_22 = - V_248 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_524 == NULL ) {
V_22 = - V_444 ;
goto V_39;
}
if ( V_520 -> V_251 != V_46 -> V_251 ) {
V_22 = - V_211 ;
goto V_39;
}
V_491 = V_520 -> V_251 * ( sizeof( V_518 ) ) ;
V_521 = V_46 -> V_63 ;
if ( F_171 ( V_521 , ( void T_2 * ) ( unsigned long ) V_520 -> V_525 , V_491 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_522 = V_521 + V_491 ;
if ( F_171 ( V_522 , ( void T_2 * ) ( unsigned long ) V_520 -> V_526 , V_491 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_523 = V_522 + V_491 ;
if ( F_171 ( V_523 , ( void T_2 * ) ( unsigned long ) V_520 -> V_527 , V_491 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_46 -> V_34 -> V_524 ( V_46 , V_521 , V_522 , V_523 , 0 , V_46 -> V_251 ) ;
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_208 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_519 * V_520 = V_212 ;
struct V_45 * V_46 ;
void * V_521 , * V_522 , * V_523 ;
int V_491 ;
int V_22 = 0 ;
if ( ! F_116 ( V_17 , V_228 ) )
return - V_211 ;
F_48 ( V_17 ) ;
V_46 = F_121 ( V_17 , V_520 -> V_225 ) ;
if ( ! V_46 ) {
V_22 = - V_248 ;
goto V_39;
}
if ( V_520 -> V_251 != V_46 -> V_251 ) {
V_22 = - V_211 ;
goto V_39;
}
V_491 = V_520 -> V_251 * ( sizeof( V_518 ) ) ;
V_521 = V_46 -> V_63 ;
if ( F_131 ( ( void T_2 * ) ( unsigned long ) V_520 -> V_525 , V_521 , V_491 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_522 = V_521 + V_491 ;
if ( F_131 ( ( void T_2 * ) ( unsigned long ) V_520 -> V_526 , V_522 , V_491 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_523 = V_522 + V_491 ;
if ( F_131 ( ( void T_2 * ) ( unsigned long ) V_520 -> V_527 , V_523 , V_491 ) ) {
V_22 = - V_232 ;
goto V_39;
}
V_39:
F_53 ( V_17 ) ;
return V_22 ;
}
int F_209 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_528 * V_529 = V_212 ;
struct V_45 * V_46 ;
struct V_31 * V_32 = NULL ;
struct V_530 * V_531 = NULL ;
unsigned long V_205 ;
int V_22 = - V_211 ;
if ( V_529 -> V_205 & ~ V_532 ||
V_529 -> V_533 != 0 )
return - V_211 ;
if ( ( V_529 -> V_205 & V_534 ) && ! V_17 -> V_23 . V_535 )
return - V_211 ;
V_46 = F_121 ( V_17 , V_529 -> V_225 ) ;
if ( ! V_46 )
return - V_248 ;
F_122 ( V_46 , V_46 -> V_51 ) ;
if ( V_46 -> V_51 -> V_32 == NULL ) {
V_22 = - V_536 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_529 == NULL )
goto V_39;
V_32 = F_32 ( V_17 , V_529 -> V_224 ) ;
if ( ! V_32 ) {
V_22 = - V_248 ;
goto V_39;
}
V_22 = F_142 ( V_46 , V_46 -> V_249 , V_46 -> V_250 , & V_46 -> V_71 , V_32 ) ;
if ( V_22 )
goto V_39;
if ( V_46 -> V_51 -> V_32 -> V_311 != V_32 -> V_311 ) {
F_67 ( L_84 ) ;
V_22 = - V_211 ;
goto V_39;
}
if ( V_529 -> V_205 & V_537 ) {
V_22 = - V_94 ;
F_210 ( & V_17 -> V_538 , V_205 ) ;
if ( V_214 -> V_539 < sizeof V_531 -> V_540 ) {
F_211 ( & V_17 -> V_538 , V_205 ) ;
goto V_39;
}
V_214 -> V_539 -= sizeof V_531 -> V_540 ;
F_211 ( & V_17 -> V_538 , V_205 ) ;
V_531 = F_108 ( sizeof *V_531 , V_26 ) ;
if ( V_531 == NULL ) {
F_210 ( & V_17 -> V_538 , V_205 ) ;
V_214 -> V_539 += sizeof V_531 -> V_540 ;
F_211 ( & V_17 -> V_538 , V_205 ) ;
goto V_39;
}
V_531 -> V_540 . V_38 . type = V_541 ;
V_531 -> V_540 . V_38 . V_483 = sizeof V_531 -> V_540 ;
V_531 -> V_540 . V_542 = V_529 -> V_542 ;
V_531 -> V_38 . V_540 = & V_531 -> V_540 . V_38 ;
V_531 -> V_38 . V_214 = V_214 ;
V_531 -> V_38 . V_44 =
( void ( * ) ( struct V_543 * ) ) F_59 ;
}
V_46 -> V_51 -> V_135 = V_46 -> V_51 -> V_32 ;
V_22 = V_46 -> V_34 -> V_529 ( V_46 , V_32 , V_531 , V_529 -> V_205 ) ;
if ( V_22 ) {
if ( V_529 -> V_205 & V_537 ) {
F_210 ( & V_17 -> V_538 , V_205 ) ;
V_214 -> V_539 += sizeof V_531 -> V_540 ;
F_211 ( & V_17 -> V_538 , V_205 ) ;
F_59 ( V_531 ) ;
}
V_46 -> V_51 -> V_135 = NULL ;
} else {
F_22 ( V_46 -> V_51 -> V_32 != V_32 ) ;
V_32 = NULL ;
}
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
if ( V_46 -> V_51 -> V_135 )
F_34 ( V_46 -> V_51 -> V_135 ) ;
V_46 -> V_51 -> V_135 = NULL ;
F_123 ( V_46 ) ;
return V_22 ;
}
void F_212 ( struct V_16 * V_17 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_114 * V_115 ;
struct V_68 * V_69 ;
F_49 (plane, &dev->mode_config.plane_list, head)
if ( V_48 -> V_34 -> V_544 )
V_48 -> V_34 -> V_544 ( V_48 ) ;
F_49 (crtc, &dev->mode_config.crtc_list, head)
if ( V_46 -> V_34 -> V_544 )
V_46 -> V_34 -> V_544 ( V_46 ) ;
F_49 (encoder, &dev->mode_config.encoder_list, head)
if ( V_115 -> V_34 -> V_544 )
V_115 -> V_34 -> V_544 ( V_115 ) ;
F_49 (connector, &dev->mode_config.connector_list, head) {
V_69 -> V_5 = V_98 ;
if ( V_69 -> V_34 -> V_544 )
V_69 -> V_34 -> V_544 ( V_69 ) ;
}
}
int F_213 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_545 * args = V_212 ;
T_5 V_418 , V_546 , V_491 ;
if ( ! V_17 -> V_547 -> V_548 )
return - V_444 ;
if ( ! args -> V_312 || ! args -> V_313 || ! args -> V_350 )
return - V_211 ;
V_418 = F_214 ( args -> V_350 , 8 ) ;
if ( ! V_418 || V_418 > 0xffffffffU / args -> V_312 )
return - V_211 ;
V_546 = V_418 * args -> V_312 ;
if ( args -> V_313 > 0xffffffffU / V_546 )
return - V_211 ;
V_491 = args -> V_313 * V_546 ;
if ( F_215 ( V_491 ) == 0 )
return - V_211 ;
args -> V_336 = 0 ;
args -> V_362 = 0 ;
args -> V_491 = 0 ;
return V_17 -> V_547 -> V_548 ( V_214 , V_17 , args ) ;
}
int F_216 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_549 * args = V_212 ;
if ( ! V_17 -> V_547 -> V_550 )
return - V_444 ;
return V_17 -> V_547 -> V_550 ( V_214 , V_17 , args -> V_336 , & args -> V_551 ) ;
}
int F_217 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_552 * args = V_212 ;
if ( ! V_17 -> V_547 -> V_553 )
return - V_444 ;
return V_17 -> V_547 -> V_553 ( V_214 , V_17 , args -> V_336 ) ;
}
void F_218 ( T_1 V_13 , unsigned int * V_351 ,
int * V_350 )
{
switch ( V_13 ) {
case V_353 :
case V_363 :
case V_364 :
* V_351 = 8 ;
* V_350 = 8 ;
break;
case V_354 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
* V_351 = 15 ;
* V_350 = 16 ;
break;
case V_355 :
case V_380 :
* V_351 = 16 ;
* V_350 = 16 ;
break;
case V_356 :
case V_381 :
* V_351 = 24 ;
* V_350 = 24 ;
break;
case V_357 :
case V_382 :
case V_383 :
case V_384 :
* V_351 = 24 ;
* V_350 = 32 ;
break;
case V_358 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
* V_351 = 30 ;
* V_350 = 32 ;
break;
case V_333 :
case V_385 :
case V_386 :
case V_387 :
* V_351 = 32 ;
* V_350 = 32 ;
break;
default:
F_67 ( L_85 ,
F_9 ( V_13 ) ) ;
* V_351 = 0 ;
* V_350 = 0 ;
break;
}
}
int F_162 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
return 3 ;
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
return 2 ;
default:
return 1 ;
}
}
int F_163 ( T_1 V_13 , int V_48 )
{
unsigned int V_351 ;
int V_350 ;
if ( V_48 >= F_162 ( V_13 ) )
return 0 ;
switch ( V_13 ) {
case V_395 :
case V_396 :
case V_397 :
case V_398 :
return 2 ;
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
return V_48 ? 2 : 1 ;
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
return 1 ;
default:
F_218 ( V_13 , & V_351 , & V_350 ) ;
return V_350 >> 3 ;
}
}
int F_160 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_408 :
case V_409 :
case V_406 :
case V_407 :
return 4 ;
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_412 :
case V_413 :
case V_410 :
case V_411 :
return 2 ;
default:
return 1 ;
}
}
int F_161 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_406 :
case V_407 :
return 4 ;
case V_410 :
case V_411 :
case V_400 :
case V_401 :
return 2 ;
default:
return 1 ;
}
}
unsigned int F_219 ( unsigned int V_554 ,
unsigned int V_555 )
{
if ( V_554 & ~ V_555 ) {
V_554 ^= F_220 ( V_556 ) | F_220 ( V_557 ) ;
V_554 = ( V_554 & ~ 0xf ) | F_220 ( ( F_221 ( V_554 & 0xf ) + 1 ) % 4 ) ;
}
return V_554 ;
}
void F_222 ( struct V_16 * V_17 )
{
F_223 ( & V_17 -> V_23 . V_57 ) ;
F_55 ( & V_17 -> V_23 . V_107 ) ;
F_223 ( & V_17 -> V_23 . V_24 ) ;
F_223 ( & V_17 -> V_23 . V_35 ) ;
F_25 ( & V_17 -> V_23 . V_42 ) ;
F_25 ( & V_17 -> V_23 . V_60 ) ;
F_25 ( & V_17 -> V_23 . V_99 ) ;
F_25 ( & V_17 -> V_23 . V_112 ) ;
F_25 ( & V_17 -> V_23 . V_120 ) ;
F_25 ( & V_17 -> V_23 . V_453 ) ;
F_25 ( & V_17 -> V_23 . V_486 ) ;
F_25 ( & V_17 -> V_23 . V_128 ) ;
F_224 ( & V_17 -> V_23 . V_25 ) ;
F_224 ( & V_17 -> V_23 . V_558 ) ;
F_48 ( V_17 ) ;
F_95 ( V_17 ) ;
F_98 ( V_17 ) ;
F_53 ( V_17 ) ;
V_17 -> V_23 . V_40 = 0 ;
V_17 -> V_23 . V_100 = 0 ;
V_17 -> V_23 . V_61 = 0 ;
V_17 -> V_23 . V_121 = 0 ;
V_17 -> V_23 . V_131 = 0 ;
V_17 -> V_23 . V_129 = 0 ;
}
void F_225 ( struct V_16 * V_17 )
{
struct V_68 * V_69 , * V_559 ;
struct V_45 * V_46 , * V_560 ;
struct V_114 * V_115 , * V_561 ;
struct V_108 * V_109 , * V_562 ;
struct V_31 * V_32 , * V_563 ;
struct V_137 * V_448 , * V_467 ;
struct V_482 * V_484 , * V_564 ;
struct V_47 * V_48 , * V_565 ;
F_74 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_115 -> V_34 -> V_44 ( V_115 ) ;
}
F_74 (bridge, brt,
&dev->mode_config.bridge_list, head) {
V_109 -> V_34 -> V_44 ( V_109 ) ;
}
F_74 (connector, ot,
&dev->mode_config.connector_list, head) {
V_69 -> V_34 -> V_44 ( V_69 ) ;
}
F_74 (property, pt, &dev->mode_config.property_list,
head) {
F_174 ( V_17 , V_448 ) ;
}
F_74 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_187 ( V_17 , V_484 ) ;
}
F_22 ( ! F_47 ( & V_17 -> V_23 . V_42 ) ) ;
F_74 (fb, fbt, &dev->mode_config.fb_list, head) {
F_46 ( V_32 ) ;
}
F_74 (plane, plt, &dev->mode_config.plane_list,
head) {
V_48 -> V_34 -> V_44 ( V_48 ) ;
}
F_74 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_46 -> V_34 -> V_44 ( V_46 ) ;
}
F_226 ( & V_17 -> V_23 . V_558 ) ;
F_226 ( & V_17 -> V_23 . V_25 ) ;
F_60 ( & V_17 -> V_23 . V_107 ) ;
}
struct V_137 * F_227 ( struct V_16 * V_17 ,
unsigned int V_555 )
{
static const struct V_454 V_455 [] = {
{ V_566 , L_86 } ,
{ V_567 , L_87 } ,
{ V_568 , L_88 } ,
{ V_569 , L_89 } ,
{ V_556 , L_90 } ,
{ V_557 , L_91 } ,
} ;
return F_175 ( V_17 , 0 , L_92 ,
V_455 , F_2 ( V_455 ) ,
V_555 ) ;
}
static void F_228 ( struct V_43 * V_43 )
{
struct V_570 * V_571 = F_29 ( V_43 , struct V_570 , V_36 ) ;
struct V_16 * V_17 = V_571 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_558 , V_571 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
F_59 ( V_571 ) ;
}
void F_73 ( struct V_16 * V_17 ,
struct V_570 * V_571 )
{
F_37 ( & V_571 -> V_36 , F_228 ) ;
}
struct V_570 * F_229 ( struct V_16 * V_17 ,
char V_572 [ 8 ] )
{
struct V_570 * V_571 ;
int V_27 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_230 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_571 -> V_573 , V_572 , 8 ) ) {
if ( ! F_33 ( & V_571 -> V_36 ) )
V_571 = NULL ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_571 ;
}
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return NULL ;
}
struct V_570 * F_231 ( struct V_16 * V_17 ,
char V_572 [ 8 ] )
{
struct V_570 * V_571 ;
int V_22 ;
V_571 = F_108 ( sizeof( * V_571 ) , V_26 ) ;
if ( ! V_571 )
return F_164 ( - V_94 ) ;
F_24 ( & V_571 -> V_36 ) ;
memcpy ( V_571 -> V_573 , V_572 , 8 ) ;
V_571 -> V_17 = V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_22 = F_12 ( & V_17 -> V_23 . V_558 , V_571 , 1 , 0 , V_26 ) ;
if ( V_22 >= 0 ) {
V_571 -> V_27 = V_22 ;
} else {
F_59 ( V_571 ) ;
V_571 = F_164 ( V_22 ) ;
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_571 ;
}
