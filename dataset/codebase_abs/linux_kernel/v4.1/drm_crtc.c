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
void F_40 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
F_27 ( V_17 , V_32 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
}
void F_41 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
F_42 ( & V_32 -> V_41 ) ;
V_17 -> V_23 . V_40 -- ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
}
void F_43 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_17 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 V_50 ;
int V_22 ;
F_22 ( ! F_44 ( & V_32 -> V_37 ) ) ;
if ( F_36 ( & V_32 -> V_36 . V_36 ) > 1 ) {
F_45 ( V_17 ) ;
F_46 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_46 -> V_51 -> V_32 == V_32 ) {
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_46 = V_46 ;
V_50 . V_32 = NULL ;
V_22 = F_47 ( & V_50 ) ;
if ( V_22 )
F_48 ( L_8 , V_46 ) ;
}
}
F_46 (plane, &dev->mode_config.plane_list, head) {
if ( V_48 -> V_32 == V_32 )
F_49 ( V_48 ) ;
}
F_50 ( V_17 ) ;
}
F_34 ( V_32 ) ;
}
int F_51 ( struct V_16 * V_17 , struct V_45 * V_46 ,
struct V_47 * V_51 ,
struct V_47 * V_52 ,
const struct V_53 * V_34 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
int V_22 ;
F_22 ( V_51 && V_51 -> type != V_56 ) ;
F_22 ( V_52 && V_52 -> type != V_57 ) ;
V_46 -> V_17 = V_17 ;
V_46 -> V_34 = V_34 ;
V_46 -> V_58 = false ;
F_52 ( & V_46 -> V_59 ) ;
V_22 = F_14 ( V_17 , & V_46 -> V_38 , V_60 ) ;
if ( V_22 )
return V_22 ;
V_46 -> V_38 . V_61 = & V_46 -> V_61 ;
F_53 ( & V_46 -> V_41 , & V_55 -> V_62 ) ;
V_55 -> V_63 ++ ;
V_46 -> V_51 = V_51 ;
V_46 -> V_52 = V_52 ;
if ( V_51 )
V_51 -> V_64 = 1 << F_54 ( V_46 ) ;
if ( V_52 )
V_52 -> V_64 = 1 << F_54 ( V_46 ) ;
if ( F_55 ( V_17 , V_65 ) ) {
F_56 ( & V_46 -> V_38 , V_55 -> V_66 , 0 ) ;
}
return 0 ;
}
void F_57 ( struct V_45 * V_46 )
{
struct V_16 * V_17 = V_46 -> V_17 ;
F_58 ( V_46 -> V_67 ) ;
V_46 -> V_67 = NULL ;
F_59 ( & V_46 -> V_59 ) ;
F_17 ( V_17 , & V_46 -> V_38 ) ;
F_42 ( & V_46 -> V_41 ) ;
V_17 -> V_23 . V_63 -- ;
F_22 ( V_46 -> V_68 && ! V_46 -> V_34 -> V_69 ) ;
if ( V_46 -> V_68 && V_46 -> V_34 -> V_69 )
V_46 -> V_34 -> V_69 ( V_46 , V_46 -> V_68 ) ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
}
unsigned int F_54 ( struct V_45 * V_46 )
{
unsigned int V_70 = 0 ;
struct V_45 * V_71 ;
F_46 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_71 == V_46 )
return V_70 ;
V_70 ++ ;
}
F_60 () ;
}
static void F_61 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
F_42 ( & V_75 -> V_41 ) ;
F_62 ( V_73 -> V_17 , V_75 ) ;
}
int F_63 ( struct V_76 * V_77 ,
const T_2 * V_78 ,
unsigned int V_79 )
{
T_2 * V_80 = NULL ;
if ( ! V_78 && V_79 )
return - V_81 ;
if ( V_78 && V_79 ) {
V_80 = F_64 ( V_78 , sizeof( * V_78 ) * V_79 ,
V_26 ) ;
if ( ! V_80 )
return - V_82 ;
}
F_58 ( V_77 -> V_83 ) ;
V_77 -> V_83 = V_80 ;
V_77 -> V_84 = V_79 ;
return 0 ;
}
static void F_65 ( struct V_72 * V_73 )
{
struct V_85 * V_75 = & V_73 -> V_86 ;
char * V_87 = NULL ;
if ( F_66 ( V_73 -> V_11 , & V_87 ) )
return;
if ( ! F_67 ( V_87 ,
V_73 ,
V_75 ) )
return;
if ( V_75 -> V_88 ) {
const char * V_89 ;
switch ( V_75 -> V_88 ) {
case V_90 :
V_89 = L_9 ;
break;
case V_91 :
V_89 = L_10 ;
break;
default:
case V_92 :
V_89 = L_11 ;
break;
}
F_68 ( L_12 , V_73 -> V_11 , V_89 ) ;
V_73 -> V_88 = V_75 -> V_88 ;
}
F_69 ( L_13 ,
V_73 -> V_11 ,
V_75 -> V_93 , V_75 -> V_94 ,
V_75 -> V_95 ? V_75 -> V_96 : 60 ,
V_75 -> V_97 ? L_14 : L_15 ,
V_75 -> V_98 ? L_16 : L_15 ,
V_75 -> V_99 ? L_17 : L_15 ) ;
}
int F_70 ( struct V_16 * V_17 ,
struct V_72 * V_73 ,
const struct V_100 * V_34 ,
int V_101 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
int V_22 ;
struct V_3 * V_102 =
& V_2 [ V_101 ] . V_3 ;
F_45 ( V_17 ) ;
V_22 = F_10 ( V_17 , & V_73 -> V_38 , V_103 , false ) ;
if ( V_22 )
goto V_104;
V_73 -> V_38 . V_61 = & V_73 -> V_61 ;
V_73 -> V_17 = V_17 ;
V_73 -> V_34 = V_34 ;
V_73 -> V_101 = V_101 ;
V_73 -> V_105 =
F_71 ( V_102 , 1 , 0 , V_26 ) ;
if ( V_73 -> V_105 < 0 ) {
V_22 = V_73 -> V_105 ;
goto V_106;
}
V_73 -> V_11 =
F_72 ( V_26 , L_18 ,
V_2 [ V_101 ] . V_11 ,
V_73 -> V_105 ) ;
if ( ! V_73 -> V_11 ) {
V_22 = - V_82 ;
goto V_106;
}
F_25 ( & V_73 -> V_107 ) ;
F_25 ( & V_73 -> V_108 ) ;
V_73 -> V_109 = NULL ;
V_73 -> V_5 = V_110 ;
F_65 ( V_73 ) ;
F_53 ( & V_73 -> V_41 , & V_55 -> V_111 ) ;
V_55 -> V_112 ++ ;
if ( V_101 != V_113 )
F_56 ( & V_73 -> V_38 ,
V_55 -> V_114 ,
0 ) ;
F_56 ( & V_73 -> V_38 ,
V_55 -> V_115 , 0 ) ;
if ( F_55 ( V_17 , V_65 ) ) {
F_56 ( & V_73 -> V_38 , V_55 -> V_116 , 0 ) ;
}
V_73 -> V_117 = NULL ;
V_106:
if ( V_22 )
F_17 ( V_17 , & V_73 -> V_38 ) ;
V_104:
F_50 ( V_17 ) ;
return V_22 ;
}
void F_73 ( struct V_72 * V_73 )
{
struct V_16 * V_17 = V_73 -> V_17 ;
struct V_74 * V_75 , * V_118 ;
if ( V_73 -> V_119 ) {
F_74 ( V_17 , V_73 -> V_119 ) ;
V_73 -> V_119 = NULL ;
}
F_75 (mode, t, &connector->probed_modes, head)
F_61 ( V_73 , V_75 ) ;
F_75 (mode, t, &connector->modes, head)
F_61 ( V_73 , V_75 ) ;
F_76 ( & V_2 [ V_73 -> V_101 ] . V_3 ,
V_73 -> V_105 ) ;
F_58 ( V_73 -> V_120 . V_83 ) ;
F_17 ( V_17 , & V_73 -> V_38 ) ;
F_58 ( V_73 -> V_11 ) ;
V_73 -> V_11 = NULL ;
F_42 ( & V_73 -> V_41 ) ;
V_17 -> V_23 . V_112 -- ;
F_22 ( V_73 -> V_68 && ! V_73 -> V_34 -> V_69 ) ;
if ( V_73 -> V_68 && V_73 -> V_34 -> V_69 )
V_73 -> V_34 -> V_69 ( V_73 ,
V_73 -> V_68 ) ;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
}
unsigned int F_77 ( struct V_72 * V_73 )
{
unsigned int V_70 = 0 ;
struct V_72 * V_71 ;
struct V_54 * V_55 = & V_73 -> V_17 -> V_23 ;
F_22 ( ! F_78 ( & V_55 -> V_121 ) ) ;
F_46 (tmp, &connector->dev->mode_config.connector_list, head) {
if ( V_71 == V_73 )
return V_70 ;
V_70 ++ ;
}
F_60 () ;
}
int F_79 ( struct V_72 * V_73 )
{
int V_22 ;
F_15 ( V_73 -> V_17 , & V_73 -> V_38 ) ;
V_22 = F_80 ( V_73 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_81 ( V_73 ) ;
if ( V_22 ) {
F_82 ( V_73 ) ;
return V_22 ;
}
return 0 ;
}
void F_83 ( struct V_72 * V_73 )
{
F_82 ( V_73 ) ;
F_84 ( V_73 ) ;
}
void F_85 ( struct V_16 * V_17 )
{
struct V_72 * V_73 ;
F_46 (connector, &dev->mode_config.connector_list, head)
F_83 ( V_73 ) ;
}
int F_86 ( struct V_16 * V_17 ,
struct V_122 * V_123 ,
const struct V_124 * V_34 ,
int V_125 )
{
int V_22 ;
F_45 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_123 -> V_38 , V_126 ) ;
if ( V_22 )
goto V_104;
V_123 -> V_17 = V_17 ;
V_123 -> V_125 = V_125 ;
V_123 -> V_34 = V_34 ;
V_123 -> V_11 = F_72 ( V_26 , L_18 ,
V_127 [ V_125 ] . V_11 ,
V_123 -> V_38 . V_27 ) ;
if ( ! V_123 -> V_11 ) {
V_22 = - V_82 ;
goto V_106;
}
F_53 ( & V_123 -> V_41 , & V_17 -> V_23 . V_128 ) ;
V_17 -> V_23 . V_129 ++ ;
V_106:
if ( V_22 )
F_17 ( V_17 , & V_123 -> V_38 ) ;
V_104:
F_50 ( V_17 ) ;
return V_22 ;
}
void F_87 ( struct V_122 * V_123 )
{
struct V_16 * V_17 = V_123 -> V_17 ;
F_45 ( V_17 ) ;
F_17 ( V_17 , & V_123 -> V_38 ) ;
F_58 ( V_123 -> V_11 ) ;
F_42 ( & V_123 -> V_41 ) ;
V_17 -> V_23 . V_129 -- ;
F_50 ( V_17 ) ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
}
int F_88 ( struct V_16 * V_17 , struct V_47 * V_48 ,
unsigned long V_64 ,
const struct V_130 * V_34 ,
const T_1 * V_78 , T_1 V_131 ,
enum V_132 type )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
int V_22 ;
V_22 = F_14 ( V_17 , & V_48 -> V_38 , V_133 ) ;
if ( V_22 )
return V_22 ;
F_52 ( & V_48 -> V_59 ) ;
V_48 -> V_38 . V_61 = & V_48 -> V_61 ;
V_48 -> V_17 = V_17 ;
V_48 -> V_34 = V_34 ;
V_48 -> V_134 = F_89 ( V_131 , sizeof( T_1 ) ,
V_26 ) ;
if ( ! V_48 -> V_134 ) {
F_69 ( L_19 ) ;
F_17 ( V_17 , & V_48 -> V_38 ) ;
return - V_82 ;
}
memcpy ( V_48 -> V_134 , V_78 , V_131 * sizeof( T_1 ) ) ;
V_48 -> V_131 = V_131 ;
V_48 -> V_64 = V_64 ;
V_48 -> type = type ;
F_53 ( & V_48 -> V_41 , & V_55 -> V_135 ) ;
V_55 -> V_136 ++ ;
if ( V_48 -> type == V_137 )
V_55 -> V_138 ++ ;
F_56 ( & V_48 -> V_38 ,
V_55 -> V_139 ,
V_48 -> type ) ;
if ( F_55 ( V_17 , V_65 ) ) {
F_56 ( & V_48 -> V_38 , V_55 -> V_140 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_116 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_141 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_142 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_143 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_144 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_145 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_146 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_147 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_148 , 0 ) ;
}
return 0 ;
}
int F_90 ( struct V_16 * V_17 , struct V_47 * V_48 ,
unsigned long V_64 ,
const struct V_130 * V_34 ,
const T_1 * V_78 , T_1 V_131 ,
bool V_149 )
{
enum V_132 type ;
type = V_149 ? V_56 : V_137 ;
return F_88 ( V_17 , V_48 , V_64 , V_34 ,
V_78 , V_131 , type ) ;
}
void F_91 ( struct V_47 * V_48 )
{
struct V_16 * V_17 = V_48 -> V_17 ;
F_45 ( V_17 ) ;
F_58 ( V_48 -> V_134 ) ;
F_17 ( V_17 , & V_48 -> V_38 ) ;
F_92 ( F_44 ( & V_48 -> V_41 ) ) ;
F_42 ( & V_48 -> V_41 ) ;
V_17 -> V_23 . V_136 -- ;
if ( V_48 -> type == V_137 )
V_17 -> V_23 . V_138 -- ;
F_50 ( V_17 ) ;
F_22 ( V_48 -> V_68 && ! V_48 -> V_34 -> V_69 ) ;
if ( V_48 -> V_68 && V_48 -> V_34 -> V_69 )
V_48 -> V_34 -> V_69 ( V_48 , V_48 -> V_68 ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
}
unsigned int F_93 ( struct V_47 * V_48 )
{
unsigned int V_70 = 0 ;
struct V_47 * V_71 ;
F_46 (tmp, &plane->dev->mode_config.plane_list, head) {
if ( V_71 == V_48 )
return V_70 ;
V_70 ++ ;
}
F_60 () ;
}
void F_49 ( struct V_47 * V_48 )
{
int V_22 ;
if ( ! V_48 -> V_32 )
return;
V_48 -> V_150 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_151 ( V_48 ) ;
if ( V_22 ) {
F_48 ( L_20 ) ;
V_48 -> V_150 = NULL ;
return;
}
F_34 ( V_48 -> V_150 ) ;
V_48 -> V_150 = NULL ;
V_48 -> V_32 = NULL ;
V_48 -> V_46 = NULL ;
}
static int F_94 ( struct V_16 * V_17 )
{
struct V_152 * V_153 ;
V_153 = F_95 ( V_17 , V_154 |
V_155 ,
L_21 , 0 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_114 = V_153 ;
V_153 = F_96 ( V_17 , 0 ,
L_22 , V_156 ,
F_2 ( V_156 ) ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_115 = V_153 ;
V_153 = F_95 ( V_17 ,
V_154 |
V_155 ,
L_23 , 0 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_157 = V_153 ;
V_153 = F_95 ( V_17 ,
V_154 |
V_155 ,
L_24 , 0 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_158 = V_153 ;
V_153 = F_96 ( V_17 , V_155 ,
L_25 , V_159 ,
F_2 ( V_159 ) ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_139 = V_153 ;
V_153 = F_97 ( V_17 , V_160 ,
L_26 , 0 , V_161 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_145 = V_153 ;
V_153 = F_97 ( V_17 , V_160 ,
L_27 , 0 , V_161 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_146 = V_153 ;
V_153 = F_97 ( V_17 , V_160 ,
L_28 , 0 , V_161 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_147 = V_153 ;
V_153 = F_97 ( V_17 , V_160 ,
L_29 , 0 , V_161 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_148 = V_153 ;
V_153 = F_98 ( V_17 , V_160 ,
L_30 , V_162 , V_163 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_141 = V_153 ;
V_153 = F_98 ( V_17 , V_160 ,
L_31 , V_162 , V_163 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_142 = V_153 ;
V_153 = F_97 ( V_17 , V_160 ,
L_32 , 0 , V_163 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_143 = V_153 ;
V_153 = F_97 ( V_17 , V_160 ,
L_33 , 0 , V_163 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_144 = V_153 ;
V_153 = F_99 ( V_17 , V_160 ,
L_34 , V_30 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_140 = V_153 ;
V_153 = F_99 ( V_17 , V_160 ,
L_35 , V_60 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_116 = V_153 ;
V_153 = F_100 ( V_17 , V_160 ,
L_36 ) ;
if ( ! V_153 )
return - V_82 ;
V_17 -> V_23 . V_66 = V_153 ;
return 0 ;
}
int F_101 ( struct V_16 * V_17 )
{
struct V_152 * V_164 ;
struct V_152 * V_165 ;
if ( V_17 -> V_23 . V_166 )
return 0 ;
V_164 =
F_96 ( V_17 , 0 ,
L_37 ,
V_167 ,
F_2 ( V_167 ) ) ;
V_17 -> V_23 . V_166 = V_164 ;
V_165 = F_96 ( V_17 , V_155 ,
L_38 ,
V_168 ,
F_2 ( V_168 ) ) ;
V_17 -> V_23 . V_169 = V_165 ;
return 0 ;
}
int F_102 ( struct V_16 * V_17 ,
unsigned int V_170 ,
char * V_108 [] )
{
struct V_152 * V_171 ;
struct V_152 * V_172 ;
unsigned int V_1 ;
if ( V_17 -> V_23 . V_173 )
return 0 ;
V_171 = F_96 ( V_17 , 0 ,
L_37 ,
V_174 ,
F_2 ( V_174 ) ) ;
V_17 -> V_23 . V_173 = V_171 ;
V_172 =
F_96 ( V_17 , V_155 ,
L_38 ,
V_175 ,
F_2 ( V_175 ) ) ;
V_17 -> V_23 . V_176 = V_172 ;
V_17 -> V_23 . V_177 =
F_97 ( V_17 , 0 , L_39 , 0 , 100 ) ;
V_17 -> V_23 . V_178 =
F_97 ( V_17 , 0 , L_40 , 0 , 100 ) ;
V_17 -> V_23 . V_179 =
F_97 ( V_17 , 0 , L_41 , 0 , 100 ) ;
V_17 -> V_23 . V_180 =
F_97 ( V_17 , 0 , L_42 , 0 , 100 ) ;
V_17 -> V_23 . V_181 =
F_95 ( V_17 , V_182 ,
L_43 , V_170 ) ;
for ( V_1 = 0 ; V_1 < V_170 ; V_1 ++ )
F_103 ( V_17 -> V_23 . V_181 , V_1 ,
V_1 , V_108 [ V_1 ] ) ;
V_17 -> V_23 . V_183 =
F_97 ( V_17 , 0 , L_44 , 0 , 100 ) ;
V_17 -> V_23 . V_184 =
F_97 ( V_17 , 0 , L_45 , 0 , 100 ) ;
V_17 -> V_23 . V_185 =
F_97 ( V_17 , 0 , L_46 , 0 , 100 ) ;
V_17 -> V_23 . V_186 =
F_97 ( V_17 , 0 , L_47 , 0 , 100 ) ;
V_17 -> V_23 . V_187 =
F_97 ( V_17 , 0 , L_48 , 0 , 100 ) ;
V_17 -> V_23 . V_188 =
F_97 ( V_17 , 0 , L_49 , 0 , 100 ) ;
return 0 ;
}
int F_104 ( struct V_16 * V_17 )
{
struct V_152 * V_189 ;
if ( V_17 -> V_23 . V_190 )
return 0 ;
V_189 =
F_96 ( V_17 , 0 , L_50 ,
V_191 ,
F_2 ( V_191 ) ) ;
V_17 -> V_23 . V_190 = V_189 ;
return 0 ;
}
int F_105 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_192 )
return 0 ;
V_17 -> V_23 . V_192 =
F_96 ( V_17 , 0 , L_51 ,
V_193 ,
F_2 ( V_193 ) ) ;
if ( V_17 -> V_23 . V_192 == NULL )
return - V_82 ;
return 0 ;
}
int F_106 ( struct V_16 * V_17 )
{
struct V_152 * V_194 ;
if ( V_17 -> V_23 . V_195 )
return 0 ;
V_194 =
F_96 ( V_17 , V_155 ,
L_52 ,
V_196 ,
F_2 ( V_196 ) ) ;
V_17 -> V_23 . V_195 = V_194 ;
return 0 ;
}
int F_107 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_197 && V_17 -> V_23 . V_198 )
return 0 ;
V_17 -> V_23 . V_197 =
F_97 ( V_17 , V_155 , L_53 , 0 , 0xffffffff ) ;
V_17 -> V_23 . V_198 =
F_97 ( V_17 , V_155 , L_54 , 0 , 0xffffffff ) ;
if ( V_17 -> V_23 . V_197 == NULL ||
V_17 -> V_23 . V_198 == NULL )
return - V_82 ;
return 0 ;
}
static int F_108 ( struct V_16 * V_17 , struct V_199 * V_200 )
{
T_1 V_201 = 0 ;
V_201 += V_17 -> V_23 . V_63 ;
V_201 += V_17 -> V_23 . V_112 ;
V_201 += V_17 -> V_23 . V_129 ;
V_200 -> V_202 = F_109 ( V_201 , sizeof( T_1 ) , V_26 ) ;
if ( ! V_200 -> V_202 )
return - V_82 ;
V_200 -> V_203 = 0 ;
V_200 -> V_204 = 0 ;
V_200 -> V_205 = 0 ;
return 0 ;
}
void F_110 ( struct V_199 * V_200 )
{
F_58 ( V_200 -> V_202 ) ;
V_200 -> V_202 = NULL ;
}
int F_111 ( struct V_16 * V_17 ,
struct V_199 * V_200 )
{
struct V_45 * V_46 ;
struct V_122 * V_123 ;
struct V_72 * V_73 ;
int V_22 ;
V_22 = F_108 ( V_17 , V_200 ) ;
if ( V_22 )
return V_22 ;
F_46 (crtc, &dev->mode_config.crtc_list, head)
V_200 -> V_202 [ V_200 -> V_203 ++ ] = V_46 -> V_38 . V_27 ;
F_46 (encoder, &dev->mode_config.encoder_list, head)
V_200 -> V_202 [ V_200 -> V_203 + V_200 -> V_205 ++ ] =
V_123 -> V_38 . V_27 ;
F_46 (connector, &dev->mode_config.connector_list, head)
V_200 -> V_202 [ V_200 -> V_203 + V_200 -> V_205 +
V_200 -> V_204 ++ ] = V_73 -> V_38 . V_27 ;
return 0 ;
}
void F_112 ( struct V_16 * V_17 )
{
F_45 ( V_17 ) ;
F_110 ( & V_17 -> V_51 -> V_206 ) ;
F_111 ( V_17 , & V_17 -> V_51 -> V_206 ) ;
F_50 ( V_17 ) ;
}
static void F_113 ( struct V_207 * V_39 ,
const struct V_74 * V_208 )
{
F_114 ( V_208 -> V_209 > V_210 || V_208 -> V_211 > V_210 ||
V_208 -> V_212 > V_210 || V_208 -> V_213 > V_210 ||
V_208 -> V_214 > V_210 || V_208 -> V_215 > V_210 ||
V_208 -> V_216 > V_210 || V_208 -> V_217 > V_210 ||
V_208 -> V_218 > V_210 || V_208 -> V_219 > V_210 ,
L_55 ) ;
V_39 -> clock = V_208 -> clock ;
V_39 -> V_209 = V_208 -> V_209 ;
V_39 -> V_211 = V_208 -> V_211 ;
V_39 -> V_212 = V_208 -> V_212 ;
V_39 -> V_213 = V_208 -> V_213 ;
V_39 -> V_214 = V_208 -> V_214 ;
V_39 -> V_215 = V_208 -> V_215 ;
V_39 -> V_216 = V_208 -> V_216 ;
V_39 -> V_217 = V_208 -> V_217 ;
V_39 -> V_218 = V_208 -> V_218 ;
V_39 -> V_219 = V_208 -> V_219 ;
V_39 -> V_220 = V_208 -> V_220 ;
V_39 -> V_221 = V_208 -> V_221 ;
V_39 -> type = V_208 -> type ;
strncpy ( V_39 -> V_11 , V_208 -> V_11 , V_222 ) ;
V_39 -> V_11 [ V_222 - 1 ] = 0 ;
}
static int F_115 ( struct V_74 * V_39 ,
const struct V_207 * V_208 )
{
if ( V_208 -> clock > V_163 || V_208 -> V_220 > V_163 )
return - V_223 ;
if ( ( V_208 -> V_221 & V_224 ) > V_225 )
return - V_81 ;
V_39 -> clock = V_208 -> clock ;
V_39 -> V_209 = V_208 -> V_209 ;
V_39 -> V_211 = V_208 -> V_211 ;
V_39 -> V_212 = V_208 -> V_212 ;
V_39 -> V_213 = V_208 -> V_213 ;
V_39 -> V_214 = V_208 -> V_214 ;
V_39 -> V_215 = V_208 -> V_215 ;
V_39 -> V_216 = V_208 -> V_216 ;
V_39 -> V_217 = V_208 -> V_217 ;
V_39 -> V_218 = V_208 -> V_218 ;
V_39 -> V_219 = V_208 -> V_219 ;
V_39 -> V_220 = V_208 -> V_220 ;
V_39 -> V_221 = V_208 -> V_221 ;
V_39 -> type = V_208 -> type ;
strncpy ( V_39 -> V_11 , V_208 -> V_11 , V_222 ) ;
V_39 -> V_11 [ V_222 - 1 ] = 0 ;
return 0 ;
}
int F_116 ( struct V_16 * V_17 , void * V_226 ,
struct V_227 * V_228 )
{
struct V_229 * V_230 = V_226 ;
struct V_231 * V_232 ;
struct V_31 * V_32 ;
struct V_72 * V_73 ;
struct V_45 * V_46 ;
struct V_122 * V_123 ;
int V_22 = 0 ;
int V_233 = 0 ;
int V_234 = 0 ;
int V_235 = 0 ;
int V_236 = 0 ;
int V_237 = 0 , V_1 ;
T_1 T_3 * V_238 ;
T_1 T_3 * V_239 ;
T_1 T_3 * V_240 ;
T_1 T_3 * V_241 ;
struct V_199 * V_206 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
F_11 ( & V_228 -> V_243 ) ;
F_117 (lh, &file_priv->fbs)
V_235 ++ ;
if ( V_230 -> V_244 >= V_235 ) {
V_237 = 0 ;
V_238 = ( T_1 T_3 * ) ( unsigned long ) V_230 -> V_245 ;
F_46 (fb, &file_priv->fbs, filp_head) {
if ( F_118 ( V_32 -> V_38 . V_27 , V_238 + V_237 ) ) {
F_13 ( & V_228 -> V_243 ) ;
return - V_246 ;
}
V_237 ++ ;
}
}
V_230 -> V_244 = V_235 ;
F_13 ( & V_228 -> V_243 ) ;
F_11 ( & V_17 -> V_23 . V_59 ) ;
if ( ! F_119 ( V_228 ) ) {
V_206 = NULL ;
F_117 (lh, &dev->mode_config.crtc_list)
V_234 ++ ;
F_117 (lh, &dev->mode_config.connector_list)
V_233 ++ ;
F_117 (lh, &dev->mode_config.encoder_list)
V_236 ++ ;
} else {
V_206 = & V_228 -> V_247 -> V_248 -> V_206 ;
V_234 = V_206 -> V_203 ;
V_233 = V_206 -> V_204 ;
V_236 = V_206 -> V_205 ;
}
V_230 -> V_249 = V_17 -> V_23 . V_249 ;
V_230 -> V_250 = V_17 -> V_23 . V_250 ;
V_230 -> V_251 = V_17 -> V_23 . V_251 ;
V_230 -> V_252 = V_17 -> V_23 . V_252 ;
if ( V_230 -> V_253 >= V_234 ) {
V_237 = 0 ;
V_239 = ( T_1 T_3 * ) ( unsigned long ) V_230 -> V_254 ;
if ( ! V_206 ) {
F_46 (crtc, &dev->mode_config.crtc_list,
head) {
F_69 ( L_56 , V_46 -> V_38 . V_27 ) ;
if ( F_118 ( V_46 -> V_38 . V_27 , V_239 + V_237 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_237 ++ ;
}
} else {
for ( V_1 = 0 ; V_1 < V_206 -> V_203 ; V_1 ++ ) {
if ( F_118 ( V_206 -> V_202 [ V_1 ] ,
V_239 + V_237 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_237 ++ ;
}
}
}
V_230 -> V_253 = V_234 ;
if ( V_230 -> V_255 >= V_236 ) {
V_237 = 0 ;
V_241 = ( T_1 T_3 * ) ( unsigned long ) V_230 -> V_256 ;
if ( ! V_206 ) {
F_46 (encoder,
&dev->mode_config.encoder_list,
head) {
F_69 ( L_57 , V_123 -> V_38 . V_27 ,
V_123 -> V_11 ) ;
if ( F_118 ( V_123 -> V_38 . V_27 , V_241 +
V_237 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_237 ++ ;
}
} else {
for ( V_1 = V_206 -> V_203 ; V_1 < V_206 -> V_203 + V_206 -> V_205 ; V_1 ++ ) {
if ( F_118 ( V_206 -> V_202 [ V_1 ] ,
V_241 + V_237 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_237 ++ ;
}
}
}
V_230 -> V_255 = V_236 ;
if ( V_230 -> V_257 >= V_233 ) {
V_237 = 0 ;
V_240 = ( T_1 T_3 * ) ( unsigned long ) V_230 -> V_258 ;
if ( ! V_206 ) {
F_46 (connector,
&dev->mode_config.connector_list,
head) {
F_69 ( L_58 ,
V_73 -> V_38 . V_27 ,
V_73 -> V_11 ) ;
if ( F_118 ( V_73 -> V_38 . V_27 ,
V_240 + V_237 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_237 ++ ;
}
} else {
int V_259 = V_206 -> V_203 +
V_206 -> V_205 ;
for ( V_1 = V_259 ; V_1 < V_259 + V_206 -> V_204 ; V_1 ++ ) {
if ( F_118 ( V_206 -> V_202 [ V_1 ] ,
V_240 + V_237 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_237 ++ ;
}
}
}
V_230 -> V_257 = V_233 ;
F_69 ( L_59 , V_230 -> V_253 ,
V_230 -> V_257 , V_230 -> V_255 ) ;
V_39:
F_13 ( & V_17 -> V_23 . V_59 ) ;
return V_22 ;
}
int F_120 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_260 * V_261 = V_226 ;
struct V_45 * V_46 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
V_46 = F_121 ( V_17 , V_261 -> V_239 ) ;
if ( ! V_46 )
return - V_262 ;
F_122 ( V_46 , V_46 -> V_51 ) ;
V_261 -> V_263 = V_46 -> V_263 ;
if ( V_46 -> V_51 -> V_32 )
V_261 -> V_238 = V_46 -> V_51 -> V_32 -> V_38 . V_27 ;
else
V_261 -> V_238 = 0 ;
if ( V_46 -> V_68 ) {
V_261 -> V_264 = V_46 -> V_51 -> V_68 -> V_265 >> 16 ;
V_261 -> V_266 = V_46 -> V_51 -> V_68 -> V_267 >> 16 ;
if ( V_46 -> V_68 -> V_268 ) {
F_113 ( & V_261 -> V_75 , & V_46 -> V_68 -> V_75 ) ;
V_261 -> V_269 = 1 ;
} else {
V_261 -> V_269 = 0 ;
}
} else {
V_261 -> V_264 = V_46 -> V_264 ;
V_261 -> V_266 = V_46 -> V_266 ;
if ( V_46 -> V_270 ) {
F_113 ( & V_261 -> V_75 , & V_46 -> V_75 ) ;
V_261 -> V_269 = 1 ;
} else {
V_261 -> V_269 = 0 ;
}
}
F_123 ( V_46 ) ;
return 0 ;
}
static bool F_124 ( const struct V_74 * V_75 ,
const struct V_227 * V_228 )
{
if ( ! V_228 -> V_271 && F_125 ( V_75 ) )
return false ;
return true ;
}
static struct V_122 * F_126 ( struct V_72 * V_73 )
{
if ( V_73 -> V_68 )
return V_73 -> V_68 -> V_272 ;
return V_73 -> V_123 ;
}
static int F_127 ( struct V_18 * V_19 , bool V_273 ,
T_1 T_3 * V_274 , T_4 T_3 * V_275 ,
T_1 * V_276 )
{
int V_277 ;
int V_1 , V_22 , V_237 ;
V_277 = V_19 -> V_61 -> V_278 ;
if ( ! V_273 )
V_277 -= V_19 -> V_61 -> V_279 ;
if ( ( * V_276 >= V_277 ) && V_277 ) {
for ( V_1 = 0 , V_237 = 0 ; V_237 < V_277 ; V_1 ++ ) {
struct V_152 * V_153 = V_19 -> V_61 -> V_61 [ V_1 ] ;
T_4 V_280 ;
if ( ( V_153 -> V_221 & V_160 ) && ! V_273 )
continue;
V_22 = F_128 ( V_19 , V_153 , & V_280 ) ;
if ( V_22 )
return V_22 ;
if ( F_118 ( V_153 -> V_38 . V_27 , V_274 + V_237 ) )
return - V_246 ;
if ( F_118 ( V_280 , V_275 + V_237 ) )
return - V_246 ;
V_237 ++ ;
}
}
* V_276 = V_277 ;
return 0 ;
}
int F_129 ( struct V_16 * V_17 , void * V_226 ,
struct V_227 * V_228 )
{
struct V_281 * V_282 = V_226 ;
struct V_72 * V_73 ;
struct V_122 * V_123 ;
struct V_74 * V_75 ;
int V_283 = 0 ;
int V_284 = 0 ;
int V_22 = 0 ;
int V_237 = 0 ;
int V_1 ;
struct V_207 V_285 ;
struct V_207 T_3 * V_286 ;
T_1 T_3 * V_287 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
memset ( & V_285 , 0 , sizeof( struct V_207 ) ) ;
F_69 ( L_60 , V_282 -> V_240 ) ;
F_11 ( & V_17 -> V_23 . V_59 ) ;
V_73 = F_130 ( V_17 , V_282 -> V_240 ) ;
if ( ! V_73 ) {
V_22 = - V_262 ;
goto V_104;
}
for ( V_1 = 0 ; V_1 < V_288 ; V_1 ++ )
if ( V_73 -> V_289 [ V_1 ] != 0 )
V_284 ++ ;
if ( V_282 -> V_290 == 0 ) {
V_73 -> V_34 -> V_291 ( V_73 ,
V_17 -> V_23 . V_251 ,
V_17 -> V_23 . V_249 ) ;
}
F_46 (mode, &connector->modes, head)
if ( F_124 ( V_75 , V_228 ) )
V_283 ++ ;
V_282 -> V_240 = V_73 -> V_38 . V_27 ;
V_282 -> V_101 = V_73 -> V_101 ;
V_282 -> V_105 = V_73 -> V_105 ;
V_282 -> V_292 = V_73 -> V_120 . V_293 ;
V_282 -> V_294 = V_73 -> V_120 . V_295 ;
V_282 -> V_296 = V_73 -> V_120 . V_8 ;
V_282 -> V_297 = V_73 -> V_5 ;
F_131 ( & V_17 -> V_23 . V_121 , NULL ) ;
V_123 = F_126 ( V_73 ) ;
if ( V_123 )
V_282 -> V_241 = V_123 -> V_38 . V_27 ;
else
V_282 -> V_241 = 0 ;
if ( ( V_282 -> V_290 >= V_283 ) && V_283 ) {
V_237 = 0 ;
V_286 = (struct V_207 T_3 * ) ( unsigned long ) V_282 -> V_298 ;
F_46 (mode, &connector->modes, head) {
if ( ! F_124 ( V_75 , V_228 ) )
continue;
F_113 ( & V_285 , V_75 ) ;
if ( F_132 ( V_286 + V_237 ,
& V_285 , sizeof( V_285 ) ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_237 ++ ;
}
}
V_282 -> V_290 = V_283 ;
V_22 = F_127 ( & V_73 -> V_38 , V_228 -> V_273 ,
( T_1 T_3 * ) ( unsigned long ) ( V_282 -> V_299 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_282 -> V_300 ) ,
& V_282 -> V_301 ) ;
if ( V_22 )
goto V_39;
if ( ( V_282 -> V_255 >= V_284 ) && V_284 ) {
V_237 = 0 ;
V_287 = ( T_1 T_3 * ) ( unsigned long ) ( V_282 -> V_302 ) ;
for ( V_1 = 0 ; V_1 < V_288 ; V_1 ++ ) {
if ( V_73 -> V_289 [ V_1 ] != 0 ) {
if ( F_118 ( V_73 -> V_289 [ V_1 ] ,
V_287 + V_237 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_237 ++ ;
}
}
}
V_282 -> V_255 = V_284 ;
V_39:
F_133 ( & V_17 -> V_23 . V_121 ) ;
V_104:
F_13 ( & V_17 -> V_23 . V_59 ) ;
return V_22 ;
}
static struct V_45 * F_134 ( struct V_122 * V_123 )
{
struct V_72 * V_73 ;
struct V_16 * V_17 = V_123 -> V_17 ;
bool V_303 = false ;
F_46 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_73 -> V_68 )
continue;
V_303 = true ;
if ( V_73 -> V_68 -> V_272 != V_123 )
continue;
return V_73 -> V_68 -> V_46 ;
}
if ( V_303 )
return NULL ;
return V_123 -> V_46 ;
}
int F_135 ( struct V_16 * V_17 , void * V_226 ,
struct V_227 * V_228 )
{
struct V_304 * V_305 = V_226 ;
struct V_122 * V_123 ;
struct V_45 * V_46 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
V_123 = F_136 ( V_17 , V_305 -> V_241 ) ;
if ( ! V_123 )
return - V_262 ;
F_131 ( & V_17 -> V_23 . V_121 , NULL ) ;
V_46 = F_134 ( V_123 ) ;
if ( V_46 )
V_305 -> V_239 = V_46 -> V_38 . V_27 ;
else
V_305 -> V_239 = 0 ;
F_133 ( & V_17 -> V_23 . V_121 ) ;
V_305 -> V_125 = V_123 -> V_125 ;
V_305 -> V_241 = V_123 -> V_38 . V_27 ;
V_305 -> V_64 = V_123 -> V_64 ;
V_305 -> V_306 = V_123 -> V_306 ;
return 0 ;
}
int F_137 ( struct V_16 * V_17 , void * V_226 ,
struct V_227 * V_228 )
{
struct V_307 * V_308 = V_226 ;
struct V_54 * V_55 ;
struct V_47 * V_48 ;
T_1 T_3 * V_309 ;
int V_237 = 0 ;
unsigned V_310 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
V_55 = & V_17 -> V_23 ;
if ( V_228 -> V_311 )
V_310 = V_55 -> V_136 ;
else
V_310 = V_55 -> V_138 ;
if ( V_310 &&
( V_308 -> V_312 >= V_310 ) ) {
V_309 = ( T_1 T_3 * ) ( unsigned long ) V_308 -> V_313 ;
F_46 (plane, &config->plane_list, head) {
if ( V_48 -> type != V_137 &&
! V_228 -> V_311 )
continue;
if ( F_118 ( V_48 -> V_38 . V_27 , V_309 + V_237 ) )
return - V_246 ;
V_237 ++ ;
}
}
V_308 -> V_312 = V_310 ;
return 0 ;
}
int F_138 ( struct V_16 * V_17 , void * V_226 ,
struct V_227 * V_228 )
{
struct V_314 * V_308 = V_226 ;
struct V_47 * V_48 ;
T_1 T_3 * V_315 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
V_48 = F_139 ( V_17 , V_308 -> V_316 ) ;
if ( ! V_48 )
return - V_262 ;
F_131 ( & V_48 -> V_59 , NULL ) ;
if ( V_48 -> V_46 )
V_308 -> V_239 = V_48 -> V_46 -> V_38 . V_27 ;
else
V_308 -> V_239 = 0 ;
if ( V_48 -> V_32 )
V_308 -> V_238 = V_48 -> V_32 -> V_38 . V_27 ;
else
V_308 -> V_238 = 0 ;
F_133 ( & V_48 -> V_59 ) ;
V_308 -> V_316 = V_48 -> V_38 . V_27 ;
V_308 -> V_64 = V_48 -> V_64 ;
V_308 -> V_263 = 0 ;
if ( V_48 -> V_131 &&
( V_308 -> V_317 >= V_48 -> V_131 ) ) {
V_315 = ( T_1 T_3 * ) ( unsigned long ) V_308 -> V_318 ;
if ( F_132 ( V_315 ,
V_48 -> V_134 ,
sizeof( T_1 ) * V_48 -> V_131 ) ) {
return - V_246 ;
}
}
V_308 -> V_317 = V_48 -> V_131 ;
return 0 ;
}
int F_140 ( const struct V_47 * V_48 , T_2 V_13 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_48 -> V_131 ; V_1 ++ ) {
if ( V_13 == V_48 -> V_134 [ V_1 ] )
return 0 ;
}
return - V_81 ;
}
static int F_141 ( struct V_47 * V_48 ,
struct V_45 * V_46 ,
struct V_31 * V_32 ,
T_5 V_319 , T_5 V_320 ,
T_1 V_321 , T_1 V_322 ,
T_1 V_265 , T_1 V_267 ,
T_1 V_323 , T_1 V_324 )
{
int V_22 = 0 ;
unsigned int V_325 , V_326 ;
if ( ! V_32 ) {
V_48 -> V_150 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_151 ( V_48 ) ;
if ( ! V_22 ) {
V_48 -> V_46 = NULL ;
V_48 -> V_32 = NULL ;
} else {
V_48 -> V_150 = NULL ;
}
goto V_39;
}
if ( ! ( V_48 -> V_64 & F_142 ( V_46 ) ) ) {
F_69 ( L_61 ) ;
V_22 = - V_81 ;
goto V_39;
}
V_22 = F_140 ( V_48 , V_32 -> V_327 ) ;
if ( V_22 ) {
F_69 ( L_62 ,
F_9 ( V_32 -> V_327 ) ) ;
goto V_39;
}
if ( V_321 > V_163 ||
V_319 > V_163 - ( T_5 ) V_321 ||
V_322 > V_163 ||
V_320 > V_163 - ( T_5 ) V_322 ) {
F_69 ( L_63 ,
V_321 , V_322 , V_319 , V_320 ) ;
return - V_223 ;
}
V_325 = V_32 -> V_328 << 16 ;
V_326 = V_32 -> V_329 << 16 ;
if ( V_323 > V_325 ||
V_265 > V_325 - V_323 ||
V_324 > V_326 ||
V_267 > V_326 - V_324 ) {
F_69 ( L_64
L_65 ,
V_323 >> 16 , ( ( V_323 & 0xffff ) * 15625 ) >> 10 ,
V_324 >> 16 , ( ( V_324 & 0xffff ) * 15625 ) >> 10 ,
V_265 >> 16 , ( ( V_265 & 0xffff ) * 15625 ) >> 10 ,
V_267 >> 16 , ( ( V_267 & 0xffff ) * 15625 ) >> 10 ) ;
V_22 = - V_330 ;
goto V_39;
}
V_48 -> V_150 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_331 ( V_48 , V_46 , V_32 ,
V_319 , V_320 , V_321 , V_322 ,
V_265 , V_267 , V_323 , V_324 ) ;
if ( ! V_22 ) {
V_48 -> V_46 = V_46 ;
V_48 -> V_32 = V_32 ;
V_32 = NULL ;
} else {
V_48 -> V_150 = NULL ;
}
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
if ( V_48 -> V_150 )
F_34 ( V_48 -> V_150 ) ;
V_48 -> V_150 = NULL ;
return V_22 ;
}
static int F_143 ( struct V_47 * V_48 ,
struct V_45 * V_46 ,
struct V_31 * V_32 ,
T_5 V_319 , T_5 V_320 ,
T_1 V_321 , T_1 V_322 ,
T_1 V_265 , T_1 V_267 ,
T_1 V_323 , T_1 V_324 )
{
int V_22 ;
F_45 ( V_48 -> V_17 ) ;
V_22 = F_141 ( V_48 , V_46 , V_32 ,
V_319 , V_320 , V_321 , V_322 ,
V_265 , V_267 , V_323 , V_324 ) ;
F_50 ( V_48 -> V_17 ) ;
return V_22 ;
}
int F_144 ( struct V_16 * V_17 , void * V_226 ,
struct V_227 * V_228 )
{
struct V_332 * V_333 = V_226 ;
struct V_47 * V_48 ;
struct V_45 * V_46 = NULL ;
struct V_31 * V_32 = NULL ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
V_48 = F_139 ( V_17 , V_333 -> V_316 ) ;
if ( ! V_48 ) {
F_69 ( L_66 ,
V_333 -> V_316 ) ;
return - V_262 ;
}
if ( V_333 -> V_238 ) {
V_32 = F_32 ( V_17 , V_333 -> V_238 ) ;
if ( ! V_32 ) {
F_69 ( L_67 ,
V_333 -> V_238 ) ;
return - V_262 ;
}
V_46 = F_121 ( V_17 , V_333 -> V_239 ) ;
if ( ! V_46 ) {
F_69 ( L_68 ,
V_333 -> V_239 ) ;
return - V_262 ;
}
}
return F_143 ( V_48 , V_46 , V_32 ,
V_333 -> V_319 , V_333 -> V_320 ,
V_333 -> V_321 , V_333 -> V_322 ,
V_333 -> V_265 , V_333 -> V_267 ,
V_333 -> V_323 , V_333 -> V_324 ) ;
}
int F_47 ( struct V_49 * V_50 )
{
struct V_45 * V_46 = V_50 -> V_46 ;
struct V_31 * V_32 ;
struct V_45 * V_71 ;
int V_22 ;
F_46 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_71 -> V_51 -> V_150 = V_71 -> V_51 -> V_32 ;
V_32 = V_50 -> V_32 ;
V_22 = V_46 -> V_34 -> V_334 ( V_50 ) ;
if ( V_22 == 0 ) {
V_46 -> V_51 -> V_46 = V_46 ;
V_46 -> V_51 -> V_32 = V_32 ;
}
F_46 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_71 -> V_51 -> V_32 )
F_38 ( V_71 -> V_51 -> V_32 ) ;
if ( V_71 -> V_51 -> V_150 )
F_34 ( V_71 -> V_51 -> V_150 ) ;
V_71 -> V_51 -> V_150 = NULL ;
}
return V_22 ;
}
void F_145 ( const struct V_74 * V_75 ,
int * V_209 , int * V_215 )
{
struct V_74 V_335 ;
F_146 ( & V_335 , V_75 ) ;
F_147 ( & V_335 , V_336 ) ;
* V_209 = V_335 . V_337 ;
* V_215 = V_335 . V_338 ;
}
int F_148 ( const struct V_45 * V_46 ,
int V_264 , int V_266 ,
const struct V_74 * V_75 ,
const struct V_31 * V_32 )
{
int V_209 , V_215 ;
F_145 ( V_75 , & V_209 , & V_215 ) ;
if ( V_46 -> V_58 )
F_149 ( V_209 , V_215 ) ;
if ( V_209 > V_32 -> V_328 ||
V_215 > V_32 -> V_329 ||
V_264 > V_32 -> V_328 - V_209 ||
V_266 > V_32 -> V_329 - V_215 ) {
F_69 ( L_69 ,
V_32 -> V_328 , V_32 -> V_329 , V_209 , V_215 , V_264 , V_266 ,
V_46 -> V_58 ? L_70 : L_15 ) ;
return - V_330 ;
}
return 0 ;
}
int F_150 ( struct V_16 * V_17 , void * V_226 ,
struct V_227 * V_228 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
struct V_260 * V_339 = V_226 ;
struct V_45 * V_46 ;
struct V_72 * * V_340 = NULL , * V_73 ;
struct V_31 * V_32 = NULL ;
struct V_74 * V_75 = NULL ;
struct V_49 V_50 ;
T_1 T_3 * V_341 ;
int V_22 ;
int V_1 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
if ( V_339 -> V_264 > V_163 || V_339 -> V_266 > V_163 )
return - V_223 ;
F_45 ( V_17 ) ;
V_46 = F_121 ( V_17 , V_339 -> V_239 ) ;
if ( ! V_46 ) {
F_69 ( L_71 , V_339 -> V_239 ) ;
V_22 = - V_262 ;
goto V_39;
}
F_69 ( L_56 , V_46 -> V_38 . V_27 ) ;
if ( V_339 -> V_269 ) {
if ( V_339 -> V_238 == - 1 ) {
if ( ! V_46 -> V_51 -> V_32 ) {
F_69 ( L_72 ) ;
V_22 = - V_81 ;
goto V_39;
}
V_32 = V_46 -> V_51 -> V_32 ;
F_38 ( V_32 ) ;
} else {
V_32 = F_32 ( V_17 , V_339 -> V_238 ) ;
if ( ! V_32 ) {
F_69 ( L_73 ,
V_339 -> V_238 ) ;
V_22 = - V_262 ;
goto V_39;
}
}
V_75 = F_151 ( V_17 ) ;
if ( ! V_75 ) {
V_22 = - V_82 ;
goto V_39;
}
V_22 = F_115 ( V_75 , & V_339 -> V_75 ) ;
if ( V_22 ) {
F_69 ( L_74 ) ;
goto V_39;
}
V_75 -> V_5 = F_152 ( V_75 ) ;
if ( V_75 -> V_5 != V_342 ) {
V_22 = - V_81 ;
goto V_39;
}
F_147 ( V_75 , V_343 ) ;
if ( ! V_46 -> V_51 -> V_344 ) {
V_22 = F_140 ( V_46 -> V_51 ,
V_32 -> V_327 ) ;
if ( V_22 ) {
F_69 ( L_62 ,
F_9 ( V_32 -> V_327 ) ) ;
goto V_39;
}
}
V_22 = F_148 ( V_46 , V_339 -> V_264 , V_339 -> V_266 ,
V_75 , V_32 ) ;
if ( V_22 )
goto V_39;
}
if ( V_339 -> V_257 == 0 && V_75 ) {
F_69 ( L_75 ) ;
V_22 = - V_81 ;
goto V_39;
}
if ( V_339 -> V_257 > 0 && ( ! V_75 || ! V_32 ) ) {
F_69 ( L_76 ,
V_339 -> V_257 ) ;
V_22 = - V_81 ;
goto V_39;
}
if ( V_339 -> V_257 > 0 ) {
T_2 V_345 ;
if ( V_339 -> V_257 > V_55 -> V_112 ) {
V_22 = - V_81 ;
goto V_39;
}
V_340 = F_89 ( V_339 -> V_257 ,
sizeof( struct V_72 * ) ,
V_26 ) ;
if ( ! V_340 ) {
V_22 = - V_82 ;
goto V_39;
}
for ( V_1 = 0 ; V_1 < V_339 -> V_257 ; V_1 ++ ) {
V_341 = ( T_1 T_3 * ) ( unsigned long ) V_339 -> V_341 ;
if ( F_153 ( V_345 , & V_341 [ V_1 ] ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_73 = F_130 ( V_17 , V_345 ) ;
if ( ! V_73 ) {
F_69 ( L_77 ,
V_345 ) ;
V_22 = - V_262 ;
goto V_39;
}
F_69 ( L_58 ,
V_73 -> V_38 . V_27 ,
V_73 -> V_11 ) ;
V_340 [ V_1 ] = V_73 ;
}
}
V_50 . V_46 = V_46 ;
V_50 . V_264 = V_339 -> V_264 ;
V_50 . V_266 = V_339 -> V_266 ;
V_50 . V_75 = V_75 ;
V_50 . V_346 = V_340 ;
V_50 . V_204 = V_339 -> V_257 ;
V_50 . V_32 = V_32 ;
V_22 = F_47 ( & V_50 ) ;
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
F_58 ( V_340 ) ;
F_62 ( V_17 , V_75 ) ;
F_50 ( V_17 ) ;
return V_22 ;
}
static int F_154 ( struct V_45 * V_46 ,
struct V_347 * V_348 ,
struct V_227 * V_228 )
{
struct V_16 * V_17 = V_46 -> V_17 ;
struct V_31 * V_32 = NULL ;
struct V_349 V_350 = {
. V_328 = V_348 -> V_328 ,
. V_329 = V_348 -> V_329 ,
. V_327 = V_351 ,
. V_352 = { V_348 -> V_328 * 4 } ,
. V_353 = { V_348 -> V_354 } ,
} ;
T_5 V_319 , V_320 ;
T_1 V_321 = 0 , V_322 = 0 ;
T_1 V_323 = 0 , V_324 = 0 ;
int V_22 = 0 ;
F_92 ( ! V_46 -> V_52 ) ;
F_22 ( V_46 -> V_52 -> V_46 != V_46 && V_46 -> V_52 -> V_46 != NULL ) ;
if ( V_348 -> V_221 & V_355 ) {
if ( V_348 -> V_354 ) {
V_32 = F_155 ( V_17 , & V_350 , V_228 ) ;
if ( F_156 ( V_32 ) ) {
F_69 ( L_78 ) ;
return F_157 ( V_32 ) ;
}
} else {
V_32 = NULL ;
}
} else {
V_32 = V_46 -> V_52 -> V_32 ;
if ( V_32 )
F_38 ( V_32 ) ;
}
if ( V_348 -> V_221 & V_356 ) {
V_319 = V_348 -> V_264 ;
V_320 = V_348 -> V_266 ;
} else {
V_319 = V_46 -> V_357 ;
V_320 = V_46 -> V_358 ;
}
if ( V_32 ) {
V_321 = V_32 -> V_328 ;
V_322 = V_32 -> V_329 ;
V_323 = V_32 -> V_328 << 16 ;
V_324 = V_32 -> V_329 << 16 ;
}
V_22 = F_141 ( V_46 -> V_52 , V_46 , V_32 ,
V_319 , V_320 , V_321 , V_322 ,
0 , 0 , V_323 , V_324 ) ;
if ( V_22 == 0 && V_348 -> V_221 & V_356 ) {
V_46 -> V_357 = V_348 -> V_264 ;
V_46 -> V_358 = V_348 -> V_266 ;
}
return V_22 ;
}
static int F_158 ( struct V_16 * V_17 ,
struct V_347 * V_348 ,
struct V_227 * V_228 )
{
struct V_45 * V_46 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
if ( ! V_348 -> V_221 || ( ~ V_359 & V_348 -> V_221 ) )
return - V_81 ;
V_46 = F_121 ( V_17 , V_348 -> V_239 ) ;
if ( ! V_46 ) {
F_69 ( L_71 , V_348 -> V_239 ) ;
return - V_262 ;
}
F_122 ( V_46 , V_46 -> V_52 ) ;
if ( V_46 -> V_52 ) {
V_22 = F_154 ( V_46 , V_348 , V_228 ) ;
goto V_39;
}
if ( V_348 -> V_221 & V_355 ) {
if ( ! V_46 -> V_34 -> V_360 && ! V_46 -> V_34 -> V_361 ) {
V_22 = - V_362 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_361 )
V_22 = V_46 -> V_34 -> V_361 ( V_46 , V_228 , V_348 -> V_354 ,
V_348 -> V_328 , V_348 -> V_329 , V_348 -> V_363 , V_348 -> V_364 ) ;
else
V_22 = V_46 -> V_34 -> V_360 ( V_46 , V_228 , V_348 -> V_354 ,
V_348 -> V_328 , V_348 -> V_329 ) ;
}
if ( V_348 -> V_221 & V_356 ) {
if ( V_46 -> V_34 -> V_365 ) {
V_22 = V_46 -> V_34 -> V_365 ( V_46 , V_348 -> V_264 , V_348 -> V_266 ) ;
} else {
V_22 = - V_246 ;
goto V_39;
}
}
V_39:
F_123 ( V_46 ) ;
return V_22 ;
}
int F_159 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_366 * V_348 = V_226 ;
struct V_347 V_367 ;
memcpy ( & V_367 , V_348 , sizeof( struct V_366 ) ) ;
V_367 . V_363 = V_367 . V_364 = 0 ;
return F_158 ( V_17 , & V_367 , V_228 ) ;
}
int F_160 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_347 * V_348 = V_226 ;
return F_158 ( V_17 , V_348 , V_228 ) ;
}
T_1 F_161 ( T_1 V_368 , T_1 V_369 )
{
T_1 V_370 ;
switch ( V_368 ) {
case 8 :
V_370 = V_371 ;
break;
case 16 :
if ( V_369 == 15 )
V_370 = V_372 ;
else
V_370 = V_373 ;
break;
case 24 :
V_370 = V_374 ;
break;
case 32 :
if ( V_369 == 24 )
V_370 = V_375 ;
else if ( V_369 == 30 )
V_370 = V_376 ;
else
V_370 = V_351 ;
break;
default:
F_48 ( L_79 ) ;
V_370 = V_375 ;
break;
}
return V_370 ;
}
int F_162 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_377 * V_378 = V_226 ;
struct V_349 V_379 = {} ;
int V_22 ;
V_379 . V_238 = V_378 -> V_238 ;
V_379 . V_328 = V_378 -> V_328 ;
V_379 . V_329 = V_378 -> V_329 ;
V_379 . V_352 [ 0 ] = V_378 -> V_380 ;
V_379 . V_327 = F_161 ( V_378 -> V_368 , V_378 -> V_369 ) ;
V_379 . V_353 [ 0 ] = V_378 -> V_354 ;
V_22 = F_163 ( V_17 , & V_379 , V_228 ) ;
if ( V_22 )
return V_22 ;
V_378 -> V_238 = V_379 . V_238 ;
return 0 ;
}
static int F_164 ( const struct V_349 * V_379 )
{
T_1 V_13 = V_379 -> V_327 & ~ V_15 ;
switch ( V_13 ) {
case V_371 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_372 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_373 :
case V_398 :
case V_374 :
case V_399 :
case V_375 :
case V_400 :
case V_401 :
case V_402 :
case V_351 :
case V_403 :
case V_404 :
case V_405 :
case V_376 :
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
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
return 0 ;
default:
F_69 ( L_80 ,
F_9 ( V_379 -> V_327 ) ) ;
return - V_81 ;
}
}
static int F_165 ( const struct V_349 * V_379 )
{
int V_22 , V_434 , V_435 , V_310 , V_1 ;
V_22 = F_164 ( V_379 ) ;
if ( V_22 ) {
F_69 ( L_81 ,
F_9 ( V_379 -> V_327 ) ) ;
return V_22 ;
}
V_434 = F_166 ( V_379 -> V_327 ) ;
V_435 = F_167 ( V_379 -> V_327 ) ;
V_310 = F_168 ( V_379 -> V_327 ) ;
if ( V_379 -> V_328 == 0 || V_379 -> V_328 % V_434 ) {
F_69 ( L_82 , V_379 -> V_328 ) ;
return - V_81 ;
}
if ( V_379 -> V_329 == 0 || V_379 -> V_329 % V_435 ) {
F_69 ( L_83 , V_379 -> V_329 ) ;
return - V_81 ;
}
for ( V_1 = 0 ; V_1 < V_310 ; V_1 ++ ) {
unsigned int V_328 = V_379 -> V_328 / ( V_1 != 0 ? V_434 : 1 ) ;
unsigned int V_329 = V_379 -> V_329 / ( V_1 != 0 ? V_435 : 1 ) ;
unsigned int V_436 = F_169 ( V_379 -> V_327 , V_1 ) ;
if ( ! V_379 -> V_353 [ V_1 ] ) {
F_69 ( L_84 , V_1 ) ;
return - V_81 ;
}
if ( ( T_4 ) V_328 * V_436 > V_161 )
return - V_223 ;
if ( ( T_4 ) V_329 * V_379 -> V_352 [ V_1 ] + V_379 -> V_437 [ V_1 ] > V_161 )
return - V_223 ;
if ( V_379 -> V_352 [ V_1 ] < V_328 * V_436 ) {
F_69 ( L_85 , V_379 -> V_352 [ V_1 ] , V_1 ) ;
return - V_81 ;
}
if ( V_379 -> V_438 [ V_1 ] && ! ( V_379 -> V_221 & V_439 ) ) {
F_69 ( L_86 ,
V_379 -> V_438 [ V_1 ] , V_1 ) ;
return - V_81 ;
}
}
return 0 ;
}
static struct V_31 *
F_155 ( struct V_16 * V_17 ,
struct V_349 * V_379 ,
struct V_227 * V_228 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
struct V_31 * V_32 ;
int V_22 ;
if ( V_379 -> V_221 & ~ ( V_440 | V_439 ) ) {
F_69 ( L_87 , V_379 -> V_221 ) ;
return F_170 ( - V_81 ) ;
}
if ( ( V_55 -> V_252 > V_379 -> V_328 ) || ( V_379 -> V_328 > V_55 -> V_251 ) ) {
F_69 ( L_88 ,
V_379 -> V_328 , V_55 -> V_252 , V_55 -> V_251 ) ;
return F_170 ( - V_81 ) ;
}
if ( ( V_55 -> V_250 > V_379 -> V_329 ) || ( V_379 -> V_329 > V_55 -> V_249 ) ) {
F_69 ( L_89 ,
V_379 -> V_329 , V_55 -> V_250 , V_55 -> V_249 ) ;
return F_170 ( - V_81 ) ;
}
if ( V_379 -> V_221 & V_439 &&
! V_17 -> V_23 . V_441 ) {
F_69 ( L_90 ) ;
return F_170 ( - V_81 ) ;
}
V_22 = F_165 ( V_379 ) ;
if ( V_22 )
return F_170 ( V_22 ) ;
V_32 = V_17 -> V_23 . V_34 -> V_442 ( V_17 , V_228 , V_379 ) ;
if ( F_156 ( V_32 ) ) {
F_69 ( L_91 ) ;
return V_32 ;
}
return V_32 ;
}
int F_163 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_349 * V_379 = V_226 ;
struct V_31 * V_32 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
V_32 = F_155 ( V_17 , V_379 , V_228 ) ;
if ( F_156 ( V_32 ) )
return F_157 ( V_32 ) ;
F_69 ( L_92 , V_32 -> V_38 . V_27 ) ;
F_11 ( & V_228 -> V_243 ) ;
V_379 -> V_238 = V_32 -> V_38 . V_27 ;
F_26 ( & V_32 -> V_37 , & V_228 -> V_443 ) ;
F_13 ( & V_228 -> V_243 ) ;
return 0 ;
}
int F_171 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_31 * V_32 = NULL ;
struct V_31 * V_444 = NULL ;
T_1 * V_27 = V_226 ;
int V_445 = 0 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
F_11 ( & V_228 -> V_243 ) ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
V_32 = F_30 ( V_17 , * V_27 ) ;
if ( ! V_32 )
goto V_446;
F_46 (fbl, &file_priv->fbs, filp_head)
if ( V_32 == V_444 )
V_445 = 1 ;
if ( ! V_445 )
goto V_446;
F_27 ( V_17 , V_32 ) ;
F_172 ( & V_32 -> V_37 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_13 ( & V_228 -> V_243 ) ;
F_43 ( V_32 ) ;
return 0 ;
V_446:
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_13 ( & V_228 -> V_243 ) ;
return - V_262 ;
}
int F_173 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_377 * V_379 = V_226 ;
struct V_31 * V_32 ;
int V_22 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
V_32 = F_32 ( V_17 , V_379 -> V_238 ) ;
if ( ! V_32 )
return - V_262 ;
V_379 -> V_329 = V_32 -> V_329 ;
V_379 -> V_328 = V_32 -> V_328 ;
V_379 -> V_369 = V_32 -> V_369 ;
V_379 -> V_368 = V_32 -> V_447 ;
V_379 -> V_380 = V_32 -> V_352 [ 0 ] ;
if ( V_32 -> V_34 -> V_448 ) {
if ( V_228 -> V_449 || F_174 ( V_450 ) ||
F_175 ( V_228 ) ) {
V_22 = V_32 -> V_34 -> V_448 ( V_32 , V_228 ,
& V_379 -> V_354 ) ;
} else {
V_379 -> V_354 = 0 ;
V_22 = 0 ;
}
} else {
V_22 = - V_451 ;
}
F_34 ( V_32 ) ;
return V_22 ;
}
int F_176 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_452 T_3 * V_453 ;
struct V_452 * V_454 = NULL ;
struct V_455 * V_379 = V_226 ;
struct V_31 * V_32 ;
unsigned V_221 ;
int V_456 ;
int V_22 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
V_32 = F_32 ( V_17 , V_379 -> V_238 ) ;
if ( ! V_32 )
return - V_262 ;
V_456 = V_379 -> V_456 ;
V_453 = (struct V_452 T_3 * ) ( unsigned long ) V_379 -> V_453 ;
if ( ! V_456 != ! V_453 ) {
V_22 = - V_81 ;
goto V_457;
}
V_221 = V_458 & V_379 -> V_221 ;
if ( V_221 & V_459 && ( V_456 % 2 ) ) {
V_22 = - V_81 ;
goto V_457;
}
if ( V_456 && V_453 ) {
if ( V_456 < 0 || V_456 > V_460 ) {
V_22 = - V_81 ;
goto V_457;
}
V_454 = F_109 ( V_456 , sizeof( * V_454 ) , V_26 ) ;
if ( ! V_454 ) {
V_22 = - V_82 ;
goto V_457;
}
V_22 = F_177 ( V_454 , V_453 ,
V_456 * sizeof( * V_454 ) ) ;
if ( V_22 ) {
V_22 = - V_246 ;
goto V_461;
}
}
if ( V_32 -> V_34 -> V_462 ) {
V_22 = V_32 -> V_34 -> V_462 ( V_32 , V_228 , V_221 , V_379 -> V_463 ,
V_454 , V_456 ) ;
} else {
V_22 = - V_464 ;
}
V_461:
F_58 ( V_454 ) ;
V_457:
F_34 ( V_32 ) ;
return V_22 ;
}
void F_178 ( struct V_227 * V_465 )
{
struct V_16 * V_17 = V_465 -> V_248 -> V_17 ;
struct V_31 * V_32 , * V_466 ;
F_75 (fb, tfb, &priv->fbs, filp_head) {
F_11 ( & V_17 -> V_23 . V_35 ) ;
F_27 ( V_17 , V_32 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_172 ( & V_32 -> V_37 ) ;
F_43 ( V_32 ) ;
}
}
struct V_152 * F_95 ( struct V_16 * V_17 , int V_221 ,
const char * V_11 , int V_467 )
{
struct V_152 * V_468 = NULL ;
int V_22 ;
V_468 = F_179 ( sizeof( struct V_152 ) , V_26 ) ;
if ( ! V_468 )
return NULL ;
V_468 -> V_17 = V_17 ;
if ( V_467 ) {
V_468 -> V_469 = F_109 ( V_467 , sizeof( T_4 ) ,
V_26 ) ;
if ( ! V_468 -> V_469 )
goto V_470;
}
V_22 = F_14 ( V_17 , & V_468 -> V_38 , V_471 ) ;
if ( V_22 )
goto V_470;
V_468 -> V_221 = V_221 ;
V_468 -> V_467 = V_467 ;
F_25 ( & V_468 -> V_472 ) ;
if ( V_11 ) {
strncpy ( V_468 -> V_11 , V_11 , V_473 ) ;
V_468 -> V_11 [ V_473 - 1 ] = '\0' ;
}
F_53 ( & V_468 -> V_41 , & V_17 -> V_23 . V_474 ) ;
F_22 ( ! F_180 ( V_468 ) ) ;
return V_468 ;
V_470:
F_58 ( V_468 -> V_469 ) ;
F_58 ( V_468 ) ;
return NULL ;
}
struct V_152 * F_96 ( struct V_16 * V_17 , int V_221 ,
const char * V_11 ,
const struct V_475 * V_476 ,
int V_467 )
{
struct V_152 * V_468 ;
int V_1 , V_22 ;
V_221 |= V_182 ;
V_468 = F_95 ( V_17 , V_221 , V_11 , V_467 ) ;
if ( ! V_468 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_467 ; V_1 ++ ) {
V_22 = F_103 ( V_468 , V_1 ,
V_476 [ V_1 ] . type ,
V_476 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_181 ( V_17 , V_468 ) ;
return NULL ;
}
}
return V_468 ;
}
struct V_152 * F_182 ( struct V_16 * V_17 ,
int V_221 , const char * V_11 ,
const struct V_475 * V_476 ,
int V_477 ,
T_4 V_478 )
{
struct V_152 * V_468 ;
int V_1 , V_22 , V_70 = 0 ;
int V_467 = F_183 ( V_478 ) ;
V_221 |= V_479 ;
V_468 = F_95 ( V_17 , V_221 , V_11 , V_467 ) ;
if ( ! V_468 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_477 ; V_1 ++ ) {
if ( ! ( V_478 & ( 1ULL << V_476 [ V_1 ] . type ) ) )
continue;
if ( F_22 ( V_70 >= V_467 ) ) {
F_181 ( V_17 , V_468 ) ;
return NULL ;
}
V_22 = F_103 ( V_468 , V_70 ++ ,
V_476 [ V_1 ] . type ,
V_476 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_181 ( V_17 , V_468 ) ;
return NULL ;
}
}
return V_468 ;
}
static struct V_152 * F_184 ( struct V_16 * V_17 ,
int V_221 , const char * V_11 ,
T_4 V_480 , T_4 V_481 )
{
struct V_152 * V_468 ;
V_468 = F_95 ( V_17 , V_221 , V_11 , 2 ) ;
if ( ! V_468 )
return NULL ;
V_468 -> V_469 [ 0 ] = V_480 ;
V_468 -> V_469 [ 1 ] = V_481 ;
return V_468 ;
}
struct V_152 * F_97 ( struct V_16 * V_17 , int V_221 ,
const char * V_11 ,
T_4 V_480 , T_4 V_481 )
{
return F_184 ( V_17 , V_482 | V_221 ,
V_11 , V_480 , V_481 ) ;
}
struct V_152 * F_98 ( struct V_16 * V_17 ,
int V_221 , const char * V_11 ,
T_6 V_480 , T_6 V_481 )
{
return F_184 ( V_17 , V_483 | V_221 ,
V_11 , F_185 ( V_480 ) , F_185 ( V_481 ) ) ;
}
struct V_152 * F_99 ( struct V_16 * V_17 ,
int V_221 , const char * V_11 , T_1 type )
{
struct V_152 * V_468 ;
V_221 |= V_484 ;
if ( F_22 ( ! ( V_221 & V_160 ) ) )
return NULL ;
V_468 = F_95 ( V_17 , V_221 , V_11 , 1 ) ;
if ( ! V_468 )
return NULL ;
V_468 -> V_469 [ 0 ] = type ;
return V_468 ;
}
struct V_152 * F_100 ( struct V_16 * V_17 , int V_221 ,
const char * V_11 )
{
return F_97 ( V_17 , V_221 , V_11 , 0 , 1 ) ;
}
int F_103 ( struct V_152 * V_468 , int V_70 ,
T_4 V_485 , const char * V_11 )
{
struct V_486 * V_487 ;
if ( ! ( F_186 ( V_468 , V_182 ) ||
F_186 ( V_468 , V_479 ) ) )
return - V_81 ;
if ( F_186 ( V_468 , V_479 ) &&
( V_485 > 63 ) )
return - V_81 ;
if ( ! F_44 ( & V_468 -> V_472 ) ) {
F_46 (prop_enum, &property->enum_list, head) {
if ( V_487 -> V_485 == V_485 ) {
strncpy ( V_487 -> V_11 , V_11 , V_473 ) ;
V_487 -> V_11 [ V_473 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_487 = F_179 ( sizeof( struct V_486 ) , V_26 ) ;
if ( ! V_487 )
return - V_82 ;
strncpy ( V_487 -> V_11 , V_11 , V_473 ) ;
V_487 -> V_11 [ V_473 - 1 ] = '\0' ;
V_487 -> V_485 = V_485 ;
V_468 -> V_469 [ V_70 ] = V_485 ;
F_53 ( & V_487 -> V_41 , & V_468 -> V_472 ) ;
return 0 ;
}
void F_181 ( struct V_16 * V_17 , struct V_152 * V_468 )
{
struct V_486 * V_487 , * V_488 ;
F_75 (prop_enum, pt, &property->enum_list, head) {
F_42 ( & V_487 -> V_41 ) ;
F_58 ( V_487 ) ;
}
if ( V_468 -> V_467 )
F_58 ( V_468 -> V_469 ) ;
F_17 ( V_17 , & V_468 -> V_38 ) ;
F_42 ( & V_468 -> V_41 ) ;
F_58 ( V_468 ) ;
}
void F_56 ( struct V_18 * V_19 ,
struct V_152 * V_468 ,
T_4 V_489 )
{
int V_278 = V_19 -> V_61 -> V_278 ;
if ( V_278 == V_490 ) {
F_114 ( 1 , L_93
L_94
L_95 ,
V_19 -> type ) ;
return;
}
V_19 -> V_61 -> V_61 [ V_278 ] = V_468 ;
V_19 -> V_61 -> V_469 [ V_278 ] = V_489 ;
V_19 -> V_61 -> V_278 ++ ;
if ( V_468 -> V_221 & V_160 )
V_19 -> V_61 -> V_279 ++ ;
}
int F_187 ( struct V_18 * V_19 ,
struct V_152 * V_468 , T_4 V_280 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_61 -> V_278 ; V_1 ++ ) {
if ( V_19 -> V_61 -> V_61 [ V_1 ] == V_468 ) {
V_19 -> V_61 -> V_469 [ V_1 ] = V_280 ;
return 0 ;
}
}
return - V_81 ;
}
int F_128 ( struct V_18 * V_19 ,
struct V_152 * V_468 , T_4 * V_280 )
{
int V_1 ;
if ( F_55 ( V_468 -> V_17 , V_65 ) &&
! ( V_468 -> V_221 & V_155 ) )
return F_188 ( V_19 , V_468 , V_280 ) ;
for ( V_1 = 0 ; V_1 < V_19 -> V_61 -> V_278 ; V_1 ++ ) {
if ( V_19 -> V_61 -> V_61 [ V_1 ] == V_468 ) {
* V_280 = V_19 -> V_61 -> V_469 [ V_1 ] ;
return 0 ;
}
}
return - V_81 ;
}
int F_189 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_491 * V_282 = V_226 ;
struct V_152 * V_468 ;
int V_492 = 0 ;
int V_493 = 0 ;
int V_22 = 0 , V_1 ;
int V_237 ;
struct V_486 * V_487 ;
struct V_494 T_3 * V_495 ;
T_4 T_3 * V_496 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
F_45 ( V_17 ) ;
V_468 = F_190 ( V_17 , V_282 -> V_497 ) ;
if ( ! V_468 ) {
V_22 = - V_262 ;
goto V_498;
}
if ( F_186 ( V_468 , V_182 ) ||
F_186 ( V_468 , V_479 ) ) {
F_46 (prop_enum, &property->enum_list, head)
V_492 ++ ;
}
V_493 = V_468 -> V_467 ;
strncpy ( V_282 -> V_11 , V_468 -> V_11 , V_473 ) ;
V_282 -> V_11 [ V_473 - 1 ] = 0 ;
V_282 -> V_221 = V_468 -> V_221 ;
if ( ( V_282 -> V_499 >= V_493 ) && V_493 ) {
V_496 = ( T_4 T_3 * ) ( unsigned long ) V_282 -> V_496 ;
for ( V_1 = 0 ; V_1 < V_493 ; V_1 ++ ) {
if ( F_132 ( V_496 + V_1 , & V_468 -> V_469 [ V_1 ] , sizeof( T_4 ) ) ) {
V_22 = - V_246 ;
goto V_498;
}
}
}
V_282 -> V_499 = V_493 ;
if ( F_186 ( V_468 , V_182 ) ||
F_186 ( V_468 , V_479 ) ) {
if ( ( V_282 -> V_500 >= V_492 ) && V_492 ) {
V_237 = 0 ;
V_495 = (struct V_494 T_3 * ) ( unsigned long ) V_282 -> V_501 ;
F_46 (prop_enum, &property->enum_list, head) {
if ( F_132 ( & V_495 [ V_237 ] . V_485 , & V_487 -> V_485 , sizeof( T_4 ) ) ) {
V_22 = - V_246 ;
goto V_498;
}
if ( F_132 ( & V_495 [ V_237 ] . V_11 ,
& V_487 -> V_11 , V_473 ) ) {
V_22 = - V_246 ;
goto V_498;
}
V_237 ++ ;
}
}
V_282 -> V_500 = V_492 ;
}
if ( F_186 ( V_468 , V_154 ) )
V_282 -> V_500 = 0 ;
V_498:
F_50 ( V_17 ) ;
return V_22 ;
}
static struct V_502 *
F_191 ( struct V_16 * V_17 , T_7 V_503 ,
const void * V_226 )
{
struct V_502 * V_504 ;
int V_22 ;
if ( ! V_503 || ! V_226 )
return NULL ;
V_504 = F_179 ( sizeof( struct V_502 ) + V_503 , V_26 ) ;
if ( ! V_504 )
return NULL ;
V_22 = F_14 ( V_17 , & V_504 -> V_38 , V_505 ) ;
if ( V_22 ) {
F_58 ( V_504 ) ;
return NULL ;
}
V_504 -> V_503 = V_503 ;
memcpy ( V_504 -> V_226 , V_226 , V_503 ) ;
F_53 ( & V_504 -> V_41 , & V_17 -> V_23 . V_506 ) ;
return V_504 ;
}
static void F_192 ( struct V_16 * V_17 ,
struct V_502 * V_504 )
{
F_17 ( V_17 , & V_504 -> V_38 ) ;
F_42 ( & V_504 -> V_41 ) ;
F_58 ( V_504 ) ;
}
int F_193 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_507 * V_282 = V_226 ;
struct V_502 * V_504 ;
int V_22 = 0 ;
void T_3 * V_508 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
F_45 ( V_17 ) ;
V_504 = F_194 ( V_17 , V_282 -> V_509 ) ;
if ( ! V_504 ) {
V_22 = - V_262 ;
goto V_498;
}
if ( V_282 -> V_503 == V_504 -> V_503 ) {
V_508 = ( void T_3 * ) ( unsigned long ) V_282 -> V_226 ;
if ( F_132 ( V_508 , V_504 -> V_226 , V_504 -> V_503 ) ) {
V_22 = - V_246 ;
goto V_498;
}
}
V_282 -> V_503 = V_504 -> V_503 ;
V_498:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_195 ( struct V_72 * V_73 ,
const char * V_510 )
{
struct V_16 * V_17 = V_73 -> V_17 ;
T_7 V_511 = strlen ( V_510 ) + 1 ;
int V_22 ;
V_73 -> V_512 = F_191 ( V_73 -> V_17 ,
V_511 , V_510 ) ;
if ( ! V_73 -> V_512 )
return - V_81 ;
V_22 = F_187 ( & V_73 -> V_38 ,
V_17 -> V_23 . V_157 ,
V_73 -> V_512 -> V_38 . V_27 ) ;
return V_22 ;
}
int F_196 ( struct V_72 * V_73 )
{
struct V_16 * V_17 = V_73 -> V_17 ;
int V_22 , V_511 ;
char V_513 [ 256 ] ;
if ( V_73 -> V_514 )
F_192 ( V_17 , V_73 -> V_514 ) ;
if ( ! V_73 -> V_515 ) {
V_73 -> V_514 = NULL ;
V_22 = F_187 ( & V_73 -> V_38 ,
V_17 -> V_23 . V_158 , 0 ) ;
return V_22 ;
}
snprintf ( V_513 , 256 , L_96 ,
V_73 -> V_119 -> V_27 , V_73 -> V_516 ,
V_73 -> V_517 , V_73 -> V_518 ,
V_73 -> V_519 , V_73 -> V_520 ,
V_73 -> V_521 , V_73 -> V_522 ) ;
V_511 = strlen ( V_513 ) + 1 ;
V_73 -> V_514 = F_191 ( V_73 -> V_17 ,
V_511 , V_513 ) ;
if ( ! V_73 -> V_514 )
return - V_81 ;
V_22 = F_187 ( & V_73 -> V_38 ,
V_17 -> V_23 . V_158 ,
V_73 -> V_514 -> V_38 . V_27 ) ;
return V_22 ;
}
int F_197 ( struct V_72 * V_73 ,
const struct V_523 * V_523 )
{
struct V_16 * V_17 = V_73 -> V_17 ;
T_7 V_511 ;
int V_22 ;
if ( V_73 -> V_524 )
return 0 ;
if ( V_73 -> V_109 )
F_192 ( V_17 , V_73 -> V_109 ) ;
if ( ! V_523 ) {
V_73 -> V_109 = NULL ;
V_22 = F_187 ( & V_73 -> V_38 , V_17 -> V_23 . V_114 , 0 ) ;
return V_22 ;
}
V_511 = V_525 * ( 1 + V_523 -> V_526 ) ;
V_73 -> V_109 = F_191 ( V_73 -> V_17 ,
V_511 , V_523 ) ;
if ( ! V_73 -> V_109 )
return - V_81 ;
V_22 = F_187 ( & V_73 -> V_38 ,
V_17 -> V_23 . V_114 ,
V_73 -> V_109 -> V_38 . V_27 ) ;
return V_22 ;
}
bool F_198 ( struct V_152 * V_468 ,
T_4 V_485 , struct V_18 * * V_527 )
{
int V_1 ;
if ( V_468 -> V_221 & V_155 )
return false ;
* V_527 = NULL ;
if ( F_186 ( V_468 , V_482 ) ) {
if ( V_485 < V_468 -> V_469 [ 0 ] || V_485 > V_468 -> V_469 [ 1 ] )
return false ;
return true ;
} else if ( F_186 ( V_468 , V_483 ) ) {
T_6 V_528 = F_199 ( V_485 ) ;
if ( V_528 < F_199 ( V_468 -> V_469 [ 0 ] ) ||
V_528 > F_199 ( V_468 -> V_469 [ 1 ] ) )
return false ;
return true ;
} else if ( F_186 ( V_468 , V_479 ) ) {
T_4 V_529 = 0 ;
for ( V_1 = 0 ; V_1 < V_468 -> V_467 ; V_1 ++ )
V_529 |= ( 1ULL << V_468 -> V_469 [ V_1 ] ) ;
return ! ( V_485 & ~ V_529 ) ;
} else if ( F_186 ( V_468 , V_154 ) ) {
return true ;
} else if ( F_186 ( V_468 , V_484 ) ) {
if ( V_485 == 0 )
return true ;
if ( V_468 -> V_469 [ 0 ] == V_30 ) {
struct V_31 * V_32 ;
V_32 = F_32 ( V_468 -> V_17 , V_485 ) ;
if ( V_32 ) {
* V_527 = & V_32 -> V_38 ;
return true ;
} else {
return false ;
}
} else {
return F_19 ( V_468 -> V_17 , V_485 , V_468 -> V_469 [ 0 ] ) != NULL ;
}
}
for ( V_1 = 0 ; V_1 < V_468 -> V_467 ; V_1 ++ )
if ( V_468 -> V_469 [ V_1 ] == V_485 )
return true ;
return false ;
}
void F_200 ( struct V_152 * V_468 ,
struct V_18 * V_527 )
{
if ( ! V_527 )
return;
if ( F_186 ( V_468 , V_484 ) ) {
if ( V_468 -> V_469 [ 0 ] == V_30 )
F_34 ( F_31 ( V_527 ) ) ;
}
}
int F_201 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_530 * V_531 = V_226 ;
struct V_532 V_533 = {
. V_485 = V_531 -> V_485 ,
. V_497 = V_531 -> V_497 ,
. V_534 = V_531 -> V_240 ,
. V_20 = V_103
} ;
return F_202 ( V_17 , & V_533 , V_228 ) ;
}
static int F_203 ( struct V_18 * V_19 ,
struct V_152 * V_468 ,
T_4 V_485 )
{
int V_22 = - V_81 ;
struct V_72 * V_73 = F_204 ( V_19 ) ;
if ( V_468 == V_73 -> V_17 -> V_23 . V_115 ) {
if ( V_73 -> V_34 -> V_535 )
(* V_73 -> V_34 -> V_535 )( V_73 , ( int ) V_485 ) ;
V_22 = 0 ;
} else if ( V_73 -> V_34 -> V_536 )
V_22 = V_73 -> V_34 -> V_536 ( V_73 , V_468 , V_485 ) ;
if ( ! V_22 )
F_187 ( & V_73 -> V_38 , V_468 , V_485 ) ;
return V_22 ;
}
static int F_205 ( struct V_18 * V_19 ,
struct V_152 * V_468 ,
T_4 V_485 )
{
int V_22 = - V_81 ;
struct V_45 * V_46 = F_206 ( V_19 ) ;
if ( V_46 -> V_34 -> V_536 )
V_22 = V_46 -> V_34 -> V_536 ( V_46 , V_468 , V_485 ) ;
if ( ! V_22 )
F_187 ( V_19 , V_468 , V_485 ) ;
return V_22 ;
}
int F_207 ( struct V_47 * V_48 ,
struct V_152 * V_468 ,
T_4 V_485 )
{
int V_22 = - V_81 ;
struct V_18 * V_19 = & V_48 -> V_38 ;
if ( V_48 -> V_34 -> V_536 )
V_22 = V_48 -> V_34 -> V_536 ( V_48 , V_468 , V_485 ) ;
if ( ! V_22 )
F_187 ( V_19 , V_468 , V_485 ) ;
return V_22 ;
}
int F_208 ( struct V_16 * V_17 , void * V_226 ,
struct V_227 * V_228 )
{
struct V_537 * V_538 = V_226 ;
struct V_18 * V_19 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
F_45 ( V_17 ) ;
V_19 = F_21 ( V_17 , V_538 -> V_534 , V_538 -> V_20 ) ;
if ( ! V_19 ) {
V_22 = - V_262 ;
goto V_39;
}
if ( ! V_19 -> V_61 ) {
V_22 = - V_81 ;
goto V_39;
}
V_22 = F_127 ( V_19 , V_228 -> V_273 ,
( T_1 T_3 * ) ( unsigned long ) ( V_538 -> V_299 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_538 -> V_300 ) ,
& V_538 -> V_301 ) ;
V_39:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_202 ( struct V_16 * V_17 , void * V_226 ,
struct V_227 * V_228 )
{
struct V_532 * V_538 = V_226 ;
struct V_18 * V_539 ;
struct V_18 * V_540 ;
struct V_152 * V_468 ;
int V_1 , V_22 = - V_81 ;
struct V_18 * V_527 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
F_45 ( V_17 ) ;
V_539 = F_21 ( V_17 , V_538 -> V_534 , V_538 -> V_20 ) ;
if ( ! V_539 ) {
V_22 = - V_262 ;
goto V_39;
}
if ( ! V_539 -> V_61 )
goto V_39;
for ( V_1 = 0 ; V_1 < V_539 -> V_61 -> V_278 ; V_1 ++ )
if ( V_539 -> V_61 -> V_61 [ V_1 ] -> V_38 . V_27 == V_538 -> V_497 )
break;
if ( V_1 == V_539 -> V_61 -> V_278 )
goto V_39;
V_540 = F_21 ( V_17 , V_538 -> V_497 ,
V_471 ) ;
if ( ! V_540 ) {
V_22 = - V_262 ;
goto V_39;
}
V_468 = F_209 ( V_540 ) ;
if ( ! F_198 ( V_468 , V_538 -> V_485 , & V_527 ) )
goto V_39;
switch ( V_539 -> type ) {
case V_103 :
V_22 = F_203 ( V_539 , V_468 ,
V_538 -> V_485 ) ;
break;
case V_60 :
V_22 = F_205 ( V_539 , V_468 , V_538 -> V_485 ) ;
break;
case V_133 :
V_22 = F_207 ( F_210 ( V_539 ) ,
V_468 , V_538 -> V_485 ) ;
break;
}
F_200 ( V_468 , V_527 ) ;
V_39:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_211 ( struct V_72 * V_73 ,
struct V_122 * V_123 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_288 ; V_1 ++ ) {
if ( V_73 -> V_289 [ V_1 ] == 0 ) {
V_73 -> V_289 [ V_1 ] = V_123 -> V_38 . V_27 ;
return 0 ;
}
}
return - V_82 ;
}
int F_212 ( struct V_45 * V_46 ,
int V_263 )
{
V_46 -> V_263 = V_263 ;
V_46 -> V_67 = F_109 ( V_263 , sizeof( V_541 ) * 3 ,
V_26 ) ;
if ( ! V_46 -> V_67 ) {
V_46 -> V_263 = 0 ;
return - V_82 ;
}
return 0 ;
}
int F_213 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_542 * V_543 = V_226 ;
struct V_45 * V_46 ;
void * V_544 , * V_545 , * V_546 ;
int V_511 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
F_45 ( V_17 ) ;
V_46 = F_121 ( V_17 , V_543 -> V_239 ) ;
if ( ! V_46 ) {
V_22 = - V_262 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_547 == NULL ) {
V_22 = - V_464 ;
goto V_39;
}
if ( V_543 -> V_263 != V_46 -> V_263 ) {
V_22 = - V_81 ;
goto V_39;
}
V_511 = V_543 -> V_263 * ( sizeof( V_541 ) ) ;
V_544 = V_46 -> V_67 ;
if ( F_177 ( V_544 , ( void T_3 * ) ( unsigned long ) V_543 -> V_548 , V_511 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_545 = V_544 + V_511 ;
if ( F_177 ( V_545 , ( void T_3 * ) ( unsigned long ) V_543 -> V_549 , V_511 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_546 = V_545 + V_511 ;
if ( F_177 ( V_546 , ( void T_3 * ) ( unsigned long ) V_543 -> V_550 , V_511 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_46 -> V_34 -> V_547 ( V_46 , V_544 , V_545 , V_546 , 0 , V_46 -> V_263 ) ;
V_39:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_214 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_542 * V_543 = V_226 ;
struct V_45 * V_46 ;
void * V_544 , * V_545 , * V_546 ;
int V_511 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_242 ) )
return - V_81 ;
F_45 ( V_17 ) ;
V_46 = F_121 ( V_17 , V_543 -> V_239 ) ;
if ( ! V_46 ) {
V_22 = - V_262 ;
goto V_39;
}
if ( V_543 -> V_263 != V_46 -> V_263 ) {
V_22 = - V_81 ;
goto V_39;
}
V_511 = V_543 -> V_263 * ( sizeof( V_541 ) ) ;
V_544 = V_46 -> V_67 ;
if ( F_132 ( ( void T_3 * ) ( unsigned long ) V_543 -> V_548 , V_544 , V_511 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_545 = V_544 + V_511 ;
if ( F_132 ( ( void T_3 * ) ( unsigned long ) V_543 -> V_549 , V_545 , V_511 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_546 = V_545 + V_511 ;
if ( F_132 ( ( void T_3 * ) ( unsigned long ) V_543 -> V_550 , V_546 , V_511 ) ) {
V_22 = - V_246 ;
goto V_39;
}
V_39:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_215 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_551 * V_552 = V_226 ;
struct V_45 * V_46 ;
struct V_31 * V_32 = NULL ;
struct V_553 * V_554 = NULL ;
unsigned long V_221 ;
int V_22 = - V_81 ;
if ( V_552 -> V_221 & ~ V_555 ||
V_552 -> V_556 != 0 )
return - V_81 ;
if ( ( V_552 -> V_221 & V_557 ) && ! V_17 -> V_23 . V_558 )
return - V_81 ;
V_46 = F_121 ( V_17 , V_552 -> V_239 ) ;
if ( ! V_46 )
return - V_262 ;
F_122 ( V_46 , V_46 -> V_51 ) ;
if ( V_46 -> V_51 -> V_32 == NULL ) {
V_22 = - V_559 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_552 == NULL )
goto V_39;
V_32 = F_32 ( V_17 , V_552 -> V_238 ) ;
if ( ! V_32 ) {
V_22 = - V_262 ;
goto V_39;
}
V_22 = F_148 ( V_46 , V_46 -> V_264 , V_46 -> V_266 , & V_46 -> V_75 , V_32 ) ;
if ( V_22 )
goto V_39;
if ( V_46 -> V_51 -> V_32 -> V_327 != V_32 -> V_327 ) {
F_69 ( L_97 ) ;
V_22 = - V_81 ;
goto V_39;
}
if ( V_552 -> V_221 & V_560 ) {
V_22 = - V_82 ;
F_216 ( & V_17 -> V_561 , V_221 ) ;
if ( V_228 -> V_562 < sizeof( V_554 -> V_563 ) ) {
F_217 ( & V_17 -> V_561 , V_221 ) ;
goto V_39;
}
V_228 -> V_562 -= sizeof( V_554 -> V_563 ) ;
F_217 ( & V_17 -> V_561 , V_221 ) ;
V_554 = F_179 ( sizeof( * V_554 ) , V_26 ) ;
if ( V_554 == NULL ) {
F_216 ( & V_17 -> V_561 , V_221 ) ;
V_228 -> V_562 += sizeof( V_554 -> V_563 ) ;
F_217 ( & V_17 -> V_561 , V_221 ) ;
goto V_39;
}
V_554 -> V_563 . V_38 . type = V_564 ;
V_554 -> V_563 . V_38 . V_503 = sizeof( V_554 -> V_563 ) ;
V_554 -> V_563 . V_565 = V_552 -> V_565 ;
V_554 -> V_38 . V_563 = & V_554 -> V_563 . V_38 ;
V_554 -> V_38 . V_228 = V_228 ;
V_554 -> V_38 . V_44 =
( void ( * ) ( struct V_566 * ) ) F_58 ;
}
V_46 -> V_51 -> V_150 = V_46 -> V_51 -> V_32 ;
V_22 = V_46 -> V_34 -> V_552 ( V_46 , V_32 , V_554 , V_552 -> V_221 ) ;
if ( V_22 ) {
if ( V_552 -> V_221 & V_560 ) {
F_216 ( & V_17 -> V_561 , V_221 ) ;
V_228 -> V_562 += sizeof( V_554 -> V_563 ) ;
F_217 ( & V_17 -> V_561 , V_221 ) ;
F_58 ( V_554 ) ;
}
V_46 -> V_51 -> V_150 = NULL ;
} else {
F_22 ( V_46 -> V_51 -> V_32 != V_32 ) ;
V_32 = NULL ;
}
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
if ( V_46 -> V_51 -> V_150 )
F_34 ( V_46 -> V_51 -> V_150 ) ;
V_46 -> V_51 -> V_150 = NULL ;
F_123 ( V_46 ) ;
return V_22 ;
}
void F_218 ( struct V_16 * V_17 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_122 * V_123 ;
struct V_72 * V_73 ;
F_46 (plane, &dev->mode_config.plane_list, head)
if ( V_48 -> V_34 -> V_567 )
V_48 -> V_34 -> V_567 ( V_48 ) ;
F_46 (crtc, &dev->mode_config.crtc_list, head)
if ( V_46 -> V_34 -> V_567 )
V_46 -> V_34 -> V_567 ( V_46 ) ;
F_46 (encoder, &dev->mode_config.encoder_list, head)
if ( V_123 -> V_34 -> V_567 )
V_123 -> V_34 -> V_567 ( V_123 ) ;
F_46 (connector, &dev->mode_config.connector_list, head) {
V_73 -> V_5 = V_110 ;
if ( V_73 -> V_34 -> V_567 )
V_73 -> V_34 -> V_567 ( V_73 ) ;
}
}
int F_219 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_568 * args = V_226 ;
T_2 V_436 , V_569 , V_511 ;
if ( ! V_17 -> V_570 -> V_571 )
return - V_464 ;
if ( ! args -> V_328 || ! args -> V_329 || ! args -> V_368 )
return - V_81 ;
V_436 = F_220 ( args -> V_368 , 8 ) ;
if ( ! V_436 || V_436 > 0xffffffffU / args -> V_328 )
return - V_81 ;
V_569 = V_436 * args -> V_328 ;
if ( args -> V_329 > 0xffffffffU / V_569 )
return - V_81 ;
V_511 = args -> V_329 * V_569 ;
if ( F_221 ( V_511 ) == 0 )
return - V_81 ;
args -> V_354 = 0 ;
args -> V_380 = 0 ;
args -> V_511 = 0 ;
return V_17 -> V_570 -> V_571 ( V_228 , V_17 , args ) ;
}
int F_222 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_572 * args = V_226 ;
if ( ! V_17 -> V_570 -> V_573 )
return - V_464 ;
return V_17 -> V_570 -> V_573 ( V_228 , V_17 , args -> V_354 , & args -> V_574 ) ;
}
int F_223 ( struct V_16 * V_17 ,
void * V_226 , struct V_227 * V_228 )
{
struct V_575 * args = V_226 ;
if ( ! V_17 -> V_570 -> V_576 )
return - V_464 ;
return V_17 -> V_570 -> V_576 ( V_228 , V_17 , args -> V_354 ) ;
}
void F_224 ( T_1 V_13 , unsigned int * V_369 ,
int * V_368 )
{
switch ( V_13 ) {
case V_371 :
case V_381 :
case V_382 :
* V_369 = 8 ;
* V_368 = 8 ;
break;
case V_372 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
* V_369 = 15 ;
* V_368 = 16 ;
break;
case V_373 :
case V_398 :
* V_369 = 16 ;
* V_368 = 16 ;
break;
case V_374 :
case V_399 :
* V_369 = 24 ;
* V_368 = 24 ;
break;
case V_375 :
case V_400 :
case V_401 :
case V_402 :
* V_369 = 24 ;
* V_368 = 32 ;
break;
case V_376 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
* V_369 = 30 ;
* V_368 = 32 ;
break;
case V_351 :
case V_403 :
case V_404 :
case V_405 :
* V_369 = 32 ;
* V_368 = 32 ;
break;
default:
F_69 ( L_98 ,
F_9 ( V_13 ) ) ;
* V_369 = 0 ;
* V_368 = 0 ;
break;
}
}
int F_168 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
return 3 ;
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
return 2 ;
default:
return 1 ;
}
}
int F_169 ( T_1 V_13 , int V_48 )
{
unsigned int V_369 ;
int V_368 ;
if ( V_48 >= F_168 ( V_13 ) )
return 0 ;
switch ( V_13 ) {
case V_413 :
case V_414 :
case V_415 :
case V_416 :
return 2 ;
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
return V_48 ? 2 : 1 ;
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
return 1 ;
default:
F_224 ( V_13 , & V_369 , & V_368 ) ;
return V_368 >> 3 ;
}
}
int F_166 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_426 :
case V_427 :
case V_424 :
case V_425 :
return 4 ;
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_430 :
case V_431 :
case V_428 :
case V_429 :
return 2 ;
default:
return 1 ;
}
}
int F_167 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_424 :
case V_425 :
return 4 ;
case V_428 :
case V_429 :
case V_418 :
case V_419 :
return 2 ;
default:
return 1 ;
}
}
unsigned int F_225 ( unsigned int V_577 ,
unsigned int V_578 )
{
if ( V_577 & ~ V_578 ) {
V_577 ^= F_226 ( V_579 ) | F_226 ( V_580 ) ;
V_577 = ( V_577 & ~ 0xf ) | F_226 ( ( F_227 ( V_577 & 0xf ) + 1 ) % 4 ) ;
}
return V_577 ;
}
void F_228 ( struct V_16 * V_17 )
{
F_229 ( & V_17 -> V_23 . V_59 ) ;
F_52 ( & V_17 -> V_23 . V_121 ) ;
F_229 ( & V_17 -> V_23 . V_24 ) ;
F_229 ( & V_17 -> V_23 . V_35 ) ;
F_25 ( & V_17 -> V_23 . V_42 ) ;
F_25 ( & V_17 -> V_23 . V_62 ) ;
F_25 ( & V_17 -> V_23 . V_111 ) ;
F_25 ( & V_17 -> V_23 . V_128 ) ;
F_25 ( & V_17 -> V_23 . V_474 ) ;
F_25 ( & V_17 -> V_23 . V_506 ) ;
F_25 ( & V_17 -> V_23 . V_135 ) ;
F_230 ( & V_17 -> V_23 . V_25 ) ;
F_230 ( & V_17 -> V_23 . V_581 ) ;
F_45 ( V_17 ) ;
F_94 ( V_17 ) ;
F_50 ( V_17 ) ;
V_17 -> V_23 . V_40 = 0 ;
V_17 -> V_23 . V_112 = 0 ;
V_17 -> V_23 . V_63 = 0 ;
V_17 -> V_23 . V_129 = 0 ;
V_17 -> V_23 . V_138 = 0 ;
V_17 -> V_23 . V_136 = 0 ;
}
void F_231 ( struct V_16 * V_17 )
{
struct V_72 * V_73 , * V_582 ;
struct V_45 * V_46 , * V_583 ;
struct V_122 * V_123 , * V_584 ;
struct V_31 * V_32 , * V_585 ;
struct V_152 * V_468 , * V_488 ;
struct V_502 * V_504 , * V_586 ;
struct V_47 * V_48 , * V_587 ;
F_75 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_123 -> V_34 -> V_44 ( V_123 ) ;
}
F_75 (connector, ot,
&dev->mode_config.connector_list, head) {
V_73 -> V_34 -> V_44 ( V_73 ) ;
}
F_75 (property, pt, &dev->mode_config.property_list,
head) {
F_181 ( V_17 , V_468 ) ;
}
F_75 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_192 ( V_17 , V_504 ) ;
}
F_22 ( ! F_44 ( & V_17 -> V_23 . V_42 ) ) ;
F_75 (fb, fbt, &dev->mode_config.fb_list, head) {
F_43 ( V_32 ) ;
}
F_75 (plane, plt, &dev->mode_config.plane_list,
head) {
V_48 -> V_34 -> V_44 ( V_48 ) ;
}
F_75 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_46 -> V_34 -> V_44 ( V_46 ) ;
}
F_232 ( & V_17 -> V_23 . V_581 ) ;
F_232 ( & V_17 -> V_23 . V_25 ) ;
F_59 ( & V_17 -> V_23 . V_121 ) ;
}
struct V_152 * F_233 ( struct V_16 * V_17 ,
unsigned int V_578 )
{
static const struct V_475 V_476 [] = {
{ V_588 , L_99 } ,
{ V_589 , L_100 } ,
{ V_590 , L_101 } ,
{ V_591 , L_102 } ,
{ V_579 , L_103 } ,
{ V_580 , L_104 } ,
} ;
return F_182 ( V_17 , 0 , L_105 ,
V_476 , F_2 ( V_476 ) ,
V_578 ) ;
}
static void F_234 ( struct V_43 * V_43 )
{
struct V_592 * V_593 = F_29 ( V_43 , struct V_592 , V_36 ) ;
struct V_16 * V_17 = V_593 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_581 , V_593 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
F_58 ( V_593 ) ;
}
void F_74 ( struct V_16 * V_17 ,
struct V_592 * V_593 )
{
F_37 ( & V_593 -> V_36 , F_234 ) ;
}
struct V_592 * F_235 ( struct V_16 * V_17 ,
char V_594 [ 8 ] )
{
struct V_592 * V_593 ;
int V_27 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_236 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_593 -> V_595 , V_594 , 8 ) ) {
if ( ! F_33 ( & V_593 -> V_36 ) )
V_593 = NULL ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_593 ;
}
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return NULL ;
}
struct V_592 * F_237 ( struct V_16 * V_17 ,
char V_594 [ 8 ] )
{
struct V_592 * V_593 ;
int V_22 ;
V_593 = F_179 ( sizeof( * V_593 ) , V_26 ) ;
if ( ! V_593 )
return F_170 ( - V_82 ) ;
F_24 ( & V_593 -> V_36 ) ;
memcpy ( V_593 -> V_595 , V_594 , 8 ) ;
V_593 -> V_17 = V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_22 = F_12 ( & V_17 -> V_23 . V_581 , V_593 , 1 , 0 , V_26 ) ;
if ( V_22 >= 0 ) {
V_593 -> V_27 = V_22 ;
} else {
F_58 ( V_593 ) ;
V_593 = F_170 ( V_22 ) ;
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_593 ;
}
