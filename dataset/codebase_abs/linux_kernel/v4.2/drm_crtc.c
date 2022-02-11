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
if ( V_19 &&
( V_19 -> type == V_30 ||
V_19 -> type == V_31 ) )
V_19 = NULL ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_19 ;
}
struct V_18 * F_21 ( struct V_16 * V_17 ,
T_1 V_27 , T_1 type )
{
struct V_18 * V_19 = NULL ;
F_22 ( type == V_30 || type == V_31 ) ;
V_19 = F_19 ( V_17 , V_27 , type ) ;
return V_19 ;
}
int F_23 ( struct V_16 * V_17 , struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
int V_22 ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
F_24 ( & V_33 -> V_37 ) ;
F_25 ( & V_33 -> V_38 ) ;
V_33 -> V_17 = V_17 ;
V_33 -> V_35 = V_35 ;
V_22 = F_14 ( V_17 , & V_33 -> V_39 , V_30 ) ;
if ( V_22 )
goto V_40;
V_17 -> V_23 . V_41 ++ ;
F_26 ( & V_33 -> V_42 , & V_17 -> V_23 . V_43 ) ;
V_40:
F_13 ( & V_17 -> V_23 . V_36 ) ;
return 0 ;
}
static void F_27 ( struct V_16 * V_17 ,
struct V_32 * V_33 )
{
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_25 , V_33 -> V_39 . V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
V_33 -> V_39 . V_27 = 0 ;
}
static void F_28 ( struct V_44 * V_44 )
{
struct V_32 * V_33 =
F_29 ( V_44 , struct V_32 , V_37 ) ;
struct V_16 * V_17 = V_33 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
if ( V_33 -> V_39 . V_27 ) {
F_27 ( V_17 , V_33 ) ;
}
F_13 ( & V_17 -> V_23 . V_36 ) ;
V_33 -> V_35 -> V_45 ( V_33 ) ;
}
static struct V_32 * F_30 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_18 * V_19 = NULL ;
struct V_32 * V_33 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_19 = F_20 ( & V_17 -> V_23 . V_25 , V_27 ) ;
if ( ! V_19 || ( V_19 -> type != V_30 ) || ( V_19 -> V_27 != V_27 ) )
V_33 = NULL ;
else
V_33 = F_31 ( V_19 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_33 ;
}
struct V_32 * F_32 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_32 * V_33 ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
V_33 = F_30 ( V_17 , V_27 ) ;
if ( V_33 ) {
if ( ! F_33 ( & V_33 -> V_37 ) )
V_33 = NULL ;
}
F_13 ( & V_17 -> V_23 . V_36 ) ;
return V_33 ;
}
void F_34 ( struct V_32 * V_33 )
{
F_35 ( L_7 , V_33 , V_33 -> V_39 . V_27 , F_36 ( & V_33 -> V_37 . V_37 ) ) ;
F_37 ( & V_33 -> V_37 , F_28 ) ;
}
void F_38 ( struct V_32 * V_33 )
{
F_35 ( L_7 , V_33 , V_33 -> V_39 . V_27 , F_36 ( & V_33 -> V_37 . V_37 ) ) ;
F_39 ( & V_33 -> V_37 ) ;
}
void F_40 ( struct V_32 * V_33 )
{
struct V_16 * V_17 = V_33 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
F_27 ( V_17 , V_33 ) ;
F_13 ( & V_17 -> V_23 . V_36 ) ;
}
void F_41 ( struct V_32 * V_33 )
{
struct V_16 * V_17 = V_33 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
F_42 ( & V_33 -> V_42 ) ;
V_17 -> V_23 . V_41 -- ;
F_13 ( & V_17 -> V_23 . V_36 ) ;
}
void F_43 ( struct V_32 * V_33 )
{
struct V_16 * V_17 = V_33 -> V_17 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 V_51 ;
int V_22 ;
F_22 ( ! F_44 ( & V_33 -> V_38 ) ) ;
if ( F_36 ( & V_33 -> V_37 . V_37 ) > 1 ) {
F_45 ( V_17 ) ;
F_46 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_47 -> V_52 -> V_33 == V_33 ) {
memset ( & V_51 , 0 , sizeof( struct V_50 ) ) ;
V_51 . V_47 = V_47 ;
V_51 . V_33 = NULL ;
V_22 = F_47 ( & V_51 ) ;
if ( V_22 )
F_48 ( L_8 , V_47 ) ;
}
}
F_46 (plane, &dev->mode_config.plane_list, head) {
if ( V_49 -> V_33 == V_33 )
F_49 ( V_49 ) ;
}
F_50 ( V_17 ) ;
}
F_34 ( V_33 ) ;
}
int F_51 ( struct V_16 * V_17 , struct V_46 * V_47 ,
struct V_48 * V_52 ,
struct V_48 * V_53 ,
const struct V_54 * V_35 )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
int V_22 ;
F_22 ( V_52 && V_52 -> type != V_57 ) ;
F_22 ( V_53 && V_53 -> type != V_58 ) ;
V_47 -> V_17 = V_17 ;
V_47 -> V_35 = V_35 ;
V_47 -> V_59 = false ;
F_52 ( & V_47 -> V_60 ) ;
V_22 = F_14 ( V_17 , & V_47 -> V_39 , V_61 ) ;
if ( V_22 )
return V_22 ;
V_47 -> V_39 . V_62 = & V_47 -> V_62 ;
F_53 ( & V_47 -> V_42 , & V_56 -> V_63 ) ;
V_56 -> V_64 ++ ;
V_47 -> V_52 = V_52 ;
V_47 -> V_53 = V_53 ;
if ( V_52 )
V_52 -> V_65 = 1 << F_54 ( V_47 ) ;
if ( V_53 )
V_53 -> V_65 = 1 << F_54 ( V_47 ) ;
if ( F_55 ( V_17 , V_66 ) ) {
F_56 ( & V_47 -> V_39 , V_56 -> V_67 , 0 ) ;
F_56 ( & V_47 -> V_39 , V_56 -> V_68 , 0 ) ;
}
return 0 ;
}
void F_57 ( struct V_46 * V_47 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
F_58 ( V_47 -> V_69 ) ;
V_47 -> V_69 = NULL ;
F_59 ( & V_47 -> V_60 ) ;
F_17 ( V_17 , & V_47 -> V_39 ) ;
F_42 ( & V_47 -> V_42 ) ;
V_17 -> V_23 . V_64 -- ;
F_22 ( V_47 -> V_70 && ! V_47 -> V_35 -> V_71 ) ;
if ( V_47 -> V_70 && V_47 -> V_35 -> V_71 )
V_47 -> V_35 -> V_71 ( V_47 , V_47 -> V_70 ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
}
unsigned int F_54 ( struct V_46 * V_47 )
{
unsigned int V_72 = 0 ;
struct V_46 * V_73 ;
F_46 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_73 == V_47 )
return V_72 ;
V_72 ++ ;
}
F_60 () ;
}
static void F_61 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
F_42 ( & V_77 -> V_42 ) ;
F_62 ( V_75 -> V_17 , V_77 ) ;
}
int F_63 ( struct V_78 * V_79 ,
const T_2 * V_80 ,
unsigned int V_81 )
{
T_2 * V_82 = NULL ;
if ( ! V_80 && V_81 )
return - V_83 ;
if ( V_80 && V_81 ) {
V_82 = F_64 ( V_80 , sizeof( * V_80 ) * V_81 ,
V_26 ) ;
if ( ! V_82 )
return - V_84 ;
}
F_58 ( V_79 -> V_85 ) ;
V_79 -> V_85 = V_82 ;
V_79 -> V_86 = V_81 ;
return 0 ;
}
static void F_65 ( struct V_74 * V_75 )
{
struct V_87 * V_77 = & V_75 -> V_88 ;
char * V_89 = NULL ;
if ( F_66 ( V_75 -> V_11 , & V_89 ) )
return;
if ( ! F_67 ( V_89 ,
V_75 ,
V_77 ) )
return;
if ( V_77 -> V_90 ) {
const char * V_91 ;
switch ( V_77 -> V_90 ) {
case V_92 :
V_91 = L_9 ;
break;
case V_93 :
V_91 = L_10 ;
break;
default:
case V_94 :
V_91 = L_11 ;
break;
}
F_68 ( L_12 , V_75 -> V_11 , V_91 ) ;
V_75 -> V_90 = V_77 -> V_90 ;
}
F_69 ( L_13 ,
V_75 -> V_11 ,
V_77 -> V_95 , V_77 -> V_96 ,
V_77 -> V_97 ? V_77 -> V_98 : 60 ,
V_77 -> V_99 ? L_14 : L_15 ,
V_77 -> V_100 ? L_16 : L_15 ,
V_77 -> V_101 ? L_17 : L_15 ) ;
}
int F_70 ( struct V_16 * V_17 ,
struct V_74 * V_75 ,
const struct V_102 * V_35 ,
int V_103 )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
int V_22 ;
struct V_3 * V_104 =
& V_2 [ V_103 ] . V_3 ;
F_45 ( V_17 ) ;
V_22 = F_10 ( V_17 , & V_75 -> V_39 , V_105 , false ) ;
if ( V_22 )
goto V_106;
V_75 -> V_39 . V_62 = & V_75 -> V_62 ;
V_75 -> V_17 = V_17 ;
V_75 -> V_35 = V_35 ;
V_75 -> V_103 = V_103 ;
V_75 -> V_107 =
F_71 ( V_104 , 1 , 0 , V_26 ) ;
if ( V_75 -> V_107 < 0 ) {
V_22 = V_75 -> V_107 ;
goto V_108;
}
V_75 -> V_11 =
F_72 ( V_26 , L_18 ,
V_2 [ V_103 ] . V_11 ,
V_75 -> V_107 ) ;
if ( ! V_75 -> V_11 ) {
V_22 = - V_84 ;
goto V_108;
}
F_25 ( & V_75 -> V_109 ) ;
F_25 ( & V_75 -> V_110 ) ;
V_75 -> V_111 = NULL ;
V_75 -> V_5 = V_112 ;
F_65 ( V_75 ) ;
F_53 ( & V_75 -> V_42 , & V_56 -> V_113 ) ;
V_56 -> V_114 ++ ;
if ( V_103 != V_115 )
F_56 ( & V_75 -> V_39 ,
V_56 -> V_116 ,
0 ) ;
F_56 ( & V_75 -> V_39 ,
V_56 -> V_117 , 0 ) ;
if ( F_55 ( V_17 , V_66 ) ) {
F_56 ( & V_75 -> V_39 , V_56 -> V_118 , 0 ) ;
}
V_75 -> V_119 = NULL ;
V_108:
if ( V_22 )
F_17 ( V_17 , & V_75 -> V_39 ) ;
V_106:
F_50 ( V_17 ) ;
return V_22 ;
}
void F_73 ( struct V_74 * V_75 )
{
struct V_16 * V_17 = V_75 -> V_17 ;
struct V_76 * V_77 , * V_120 ;
if ( V_75 -> V_121 ) {
F_74 ( V_17 , V_75 -> V_121 ) ;
V_75 -> V_121 = NULL ;
}
F_75 (mode, t, &connector->probed_modes, head)
F_61 ( V_75 , V_77 ) ;
F_75 (mode, t, &connector->modes, head)
F_61 ( V_75 , V_77 ) ;
F_76 ( & V_2 [ V_75 -> V_103 ] . V_3 ,
V_75 -> V_107 ) ;
F_58 ( V_75 -> V_122 . V_85 ) ;
F_17 ( V_17 , & V_75 -> V_39 ) ;
F_58 ( V_75 -> V_11 ) ;
V_75 -> V_11 = NULL ;
F_42 ( & V_75 -> V_42 ) ;
V_17 -> V_23 . V_114 -- ;
F_22 ( V_75 -> V_70 && ! V_75 -> V_35 -> V_71 ) ;
if ( V_75 -> V_70 && V_75 -> V_35 -> V_71 )
V_75 -> V_35 -> V_71 ( V_75 ,
V_75 -> V_70 ) ;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
}
unsigned int F_77 ( struct V_74 * V_75 )
{
unsigned int V_72 = 0 ;
struct V_74 * V_73 ;
struct V_55 * V_56 = & V_75 -> V_17 -> V_23 ;
F_22 ( ! F_78 ( & V_56 -> V_123 ) ) ;
F_46 (tmp, &connector->dev->mode_config.connector_list, head) {
if ( V_73 == V_75 )
return V_72 ;
V_72 ++ ;
}
F_60 () ;
}
int F_79 ( struct V_74 * V_75 )
{
int V_22 ;
F_15 ( V_75 -> V_17 , & V_75 -> V_39 ) ;
V_22 = F_80 ( V_75 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_81 ( V_75 ) ;
if ( V_22 ) {
F_82 ( V_75 ) ;
return V_22 ;
}
return 0 ;
}
void F_83 ( struct V_74 * V_75 )
{
F_82 ( V_75 ) ;
F_84 ( V_75 ) ;
}
void F_85 ( struct V_16 * V_17 )
{
struct V_74 * V_75 ;
F_46 (connector, &dev->mode_config.connector_list, head)
F_83 ( V_75 ) ;
}
int F_86 ( struct V_16 * V_17 ,
struct V_124 * V_125 ,
const struct V_126 * V_35 ,
int V_127 )
{
int V_22 ;
F_45 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_125 -> V_39 , V_128 ) ;
if ( V_22 )
goto V_106;
V_125 -> V_17 = V_17 ;
V_125 -> V_127 = V_127 ;
V_125 -> V_35 = V_35 ;
V_125 -> V_11 = F_72 ( V_26 , L_18 ,
V_129 [ V_127 ] . V_11 ,
V_125 -> V_39 . V_27 ) ;
if ( ! V_125 -> V_11 ) {
V_22 = - V_84 ;
goto V_108;
}
F_53 ( & V_125 -> V_42 , & V_17 -> V_23 . V_130 ) ;
V_17 -> V_23 . V_131 ++ ;
V_108:
if ( V_22 )
F_17 ( V_17 , & V_125 -> V_39 ) ;
V_106:
F_50 ( V_17 ) ;
return V_22 ;
}
void F_87 ( struct V_124 * V_125 )
{
struct V_16 * V_17 = V_125 -> V_17 ;
F_45 ( V_17 ) ;
F_17 ( V_17 , & V_125 -> V_39 ) ;
F_58 ( V_125 -> V_11 ) ;
F_42 ( & V_125 -> V_42 ) ;
V_17 -> V_23 . V_131 -- ;
F_50 ( V_17 ) ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
}
int F_88 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_65 ,
const struct V_132 * V_35 ,
const T_1 * V_80 , T_1 V_133 ,
enum V_134 type )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
int V_22 ;
V_22 = F_14 ( V_17 , & V_49 -> V_39 , V_135 ) ;
if ( V_22 )
return V_22 ;
F_52 ( & V_49 -> V_60 ) ;
V_49 -> V_39 . V_62 = & V_49 -> V_62 ;
V_49 -> V_17 = V_17 ;
V_49 -> V_35 = V_35 ;
V_49 -> V_136 = F_89 ( V_133 , sizeof( T_1 ) ,
V_26 ) ;
if ( ! V_49 -> V_136 ) {
F_69 ( L_19 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
return - V_84 ;
}
memcpy ( V_49 -> V_136 , V_80 , V_133 * sizeof( T_1 ) ) ;
V_49 -> V_133 = V_133 ;
V_49 -> V_65 = V_65 ;
V_49 -> type = type ;
F_53 ( & V_49 -> V_42 , & V_56 -> V_137 ) ;
V_56 -> V_138 ++ ;
if ( V_49 -> type == V_139 )
V_56 -> V_140 ++ ;
F_56 ( & V_49 -> V_39 ,
V_56 -> V_141 ,
V_49 -> type ) ;
if ( F_55 ( V_17 , V_66 ) ) {
F_56 ( & V_49 -> V_39 , V_56 -> V_142 , 0 ) ;
F_56 ( & V_49 -> V_39 , V_56 -> V_118 , 0 ) ;
F_56 ( & V_49 -> V_39 , V_56 -> V_143 , 0 ) ;
F_56 ( & V_49 -> V_39 , V_56 -> V_144 , 0 ) ;
F_56 ( & V_49 -> V_39 , V_56 -> V_145 , 0 ) ;
F_56 ( & V_49 -> V_39 , V_56 -> V_146 , 0 ) ;
F_56 ( & V_49 -> V_39 , V_56 -> V_147 , 0 ) ;
F_56 ( & V_49 -> V_39 , V_56 -> V_148 , 0 ) ;
F_56 ( & V_49 -> V_39 , V_56 -> V_149 , 0 ) ;
F_56 ( & V_49 -> V_39 , V_56 -> V_150 , 0 ) ;
}
return 0 ;
}
int F_90 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_65 ,
const struct V_132 * V_35 ,
const T_1 * V_80 , T_1 V_133 ,
bool V_151 )
{
enum V_134 type ;
type = V_151 ? V_57 : V_139 ;
return F_88 ( V_17 , V_49 , V_65 , V_35 ,
V_80 , V_133 , type ) ;
}
void F_91 ( struct V_48 * V_49 )
{
struct V_16 * V_17 = V_49 -> V_17 ;
F_45 ( V_17 ) ;
F_58 ( V_49 -> V_136 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
F_92 ( F_44 ( & V_49 -> V_42 ) ) ;
F_42 ( & V_49 -> V_42 ) ;
V_17 -> V_23 . V_138 -- ;
if ( V_49 -> type == V_139 )
V_17 -> V_23 . V_140 -- ;
F_50 ( V_17 ) ;
F_22 ( V_49 -> V_70 && ! V_49 -> V_35 -> V_71 ) ;
if ( V_49 -> V_70 && V_49 -> V_35 -> V_71 )
V_49 -> V_35 -> V_71 ( V_49 , V_49 -> V_70 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
}
unsigned int F_93 ( struct V_48 * V_49 )
{
unsigned int V_72 = 0 ;
struct V_48 * V_73 ;
F_46 (tmp, &plane->dev->mode_config.plane_list, head) {
if ( V_73 == V_49 )
return V_72 ;
V_72 ++ ;
}
F_60 () ;
}
struct V_48 *
F_94 ( struct V_16 * V_17 , int V_152 )
{
struct V_48 * V_49 ;
unsigned int V_1 = 0 ;
F_46 (plane, &dev->mode_config.plane_list, head) {
if ( V_1 == V_152 )
return V_49 ;
V_1 ++ ;
}
return NULL ;
}
void F_49 ( struct V_48 * V_49 )
{
int V_22 ;
if ( ! V_49 -> V_33 )
return;
V_49 -> V_153 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_154 ( V_49 ) ;
if ( V_22 ) {
F_48 ( L_20 ) ;
V_49 -> V_153 = NULL ;
return;
}
F_34 ( V_49 -> V_153 ) ;
V_49 -> V_153 = NULL ;
V_49 -> V_33 = NULL ;
V_49 -> V_47 = NULL ;
}
static int F_95 ( struct V_16 * V_17 )
{
struct V_155 * V_156 ;
V_156 = F_96 ( V_17 , V_157 |
V_158 ,
L_21 , 0 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_116 = V_156 ;
V_156 = F_97 ( V_17 , 0 ,
L_22 , V_159 ,
F_2 ( V_159 ) ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_117 = V_156 ;
V_156 = F_96 ( V_17 ,
V_157 |
V_158 ,
L_23 , 0 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_160 = V_156 ;
V_156 = F_96 ( V_17 ,
V_157 |
V_158 ,
L_24 , 0 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_161 = V_156 ;
V_156 = F_97 ( V_17 , V_158 ,
L_25 , V_162 ,
F_2 ( V_162 ) ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_141 = V_156 ;
V_156 = F_98 ( V_17 , V_163 ,
L_26 , 0 , V_164 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_147 = V_156 ;
V_156 = F_98 ( V_17 , V_163 ,
L_27 , 0 , V_164 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_148 = V_156 ;
V_156 = F_98 ( V_17 , V_163 ,
L_28 , 0 , V_164 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_149 = V_156 ;
V_156 = F_98 ( V_17 , V_163 ,
L_29 , 0 , V_164 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_150 = V_156 ;
V_156 = F_99 ( V_17 , V_163 ,
L_30 , V_165 , V_166 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_143 = V_156 ;
V_156 = F_99 ( V_17 , V_163 ,
L_31 , V_165 , V_166 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_144 = V_156 ;
V_156 = F_98 ( V_17 , V_163 ,
L_32 , 0 , V_166 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_145 = V_156 ;
V_156 = F_98 ( V_17 , V_163 ,
L_33 , 0 , V_166 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_146 = V_156 ;
V_156 = F_100 ( V_17 , V_163 ,
L_34 , V_30 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_142 = V_156 ;
V_156 = F_100 ( V_17 , V_163 ,
L_35 , V_61 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_118 = V_156 ;
V_156 = F_101 ( V_17 , V_163 ,
L_36 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_67 = V_156 ;
V_156 = F_96 ( V_17 ,
V_163 | V_157 ,
L_37 , 0 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_68 = V_156 ;
return 0 ;
}
int F_102 ( struct V_16 * V_17 )
{
struct V_155 * V_167 ;
struct V_155 * V_168 ;
if ( V_17 -> V_23 . V_169 )
return 0 ;
V_167 =
F_97 ( V_17 , 0 ,
L_38 ,
V_170 ,
F_2 ( V_170 ) ) ;
V_17 -> V_23 . V_169 = V_167 ;
V_168 = F_97 ( V_17 , V_158 ,
L_39 ,
V_171 ,
F_2 ( V_171 ) ) ;
V_17 -> V_23 . V_172 = V_168 ;
return 0 ;
}
int F_103 ( struct V_16 * V_17 ,
unsigned int V_173 ,
char * V_110 [] )
{
struct V_155 * V_174 ;
struct V_155 * V_175 ;
unsigned int V_1 ;
if ( V_17 -> V_23 . V_176 )
return 0 ;
V_174 = F_97 ( V_17 , 0 ,
L_38 ,
V_177 ,
F_2 ( V_177 ) ) ;
V_17 -> V_23 . V_176 = V_174 ;
V_175 =
F_97 ( V_17 , V_158 ,
L_39 ,
V_178 ,
F_2 ( V_178 ) ) ;
V_17 -> V_23 . V_179 = V_175 ;
V_17 -> V_23 . V_180 =
F_98 ( V_17 , 0 , L_40 , 0 , 100 ) ;
V_17 -> V_23 . V_181 =
F_98 ( V_17 , 0 , L_41 , 0 , 100 ) ;
V_17 -> V_23 . V_182 =
F_98 ( V_17 , 0 , L_42 , 0 , 100 ) ;
V_17 -> V_23 . V_183 =
F_98 ( V_17 , 0 , L_43 , 0 , 100 ) ;
V_17 -> V_23 . V_184 =
F_96 ( V_17 , V_185 ,
L_44 , V_173 ) ;
for ( V_1 = 0 ; V_1 < V_173 ; V_1 ++ )
F_104 ( V_17 -> V_23 . V_184 , V_1 ,
V_1 , V_110 [ V_1 ] ) ;
V_17 -> V_23 . V_186 =
F_98 ( V_17 , 0 , L_45 , 0 , 100 ) ;
V_17 -> V_23 . V_187 =
F_98 ( V_17 , 0 , L_46 , 0 , 100 ) ;
V_17 -> V_23 . V_188 =
F_98 ( V_17 , 0 , L_47 , 0 , 100 ) ;
V_17 -> V_23 . V_189 =
F_98 ( V_17 , 0 , L_48 , 0 , 100 ) ;
V_17 -> V_23 . V_190 =
F_98 ( V_17 , 0 , L_49 , 0 , 100 ) ;
V_17 -> V_23 . V_191 =
F_98 ( V_17 , 0 , L_50 , 0 , 100 ) ;
return 0 ;
}
int F_105 ( struct V_16 * V_17 )
{
struct V_155 * V_192 ;
if ( V_17 -> V_23 . V_193 )
return 0 ;
V_192 =
F_97 ( V_17 , 0 , L_51 ,
V_194 ,
F_2 ( V_194 ) ) ;
V_17 -> V_23 . V_193 = V_192 ;
return 0 ;
}
int F_106 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_195 )
return 0 ;
V_17 -> V_23 . V_195 =
F_97 ( V_17 , 0 , L_52 ,
V_196 ,
F_2 ( V_196 ) ) ;
if ( V_17 -> V_23 . V_195 == NULL )
return - V_84 ;
return 0 ;
}
int F_107 ( struct V_16 * V_17 )
{
struct V_155 * V_197 ;
if ( V_17 -> V_23 . V_198 )
return 0 ;
V_197 =
F_97 ( V_17 , V_158 ,
L_53 ,
V_199 ,
F_2 ( V_199 ) ) ;
V_17 -> V_23 . V_198 = V_197 ;
return 0 ;
}
int F_108 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_200 && V_17 -> V_23 . V_201 )
return 0 ;
V_17 -> V_23 . V_200 =
F_98 ( V_17 , V_158 , L_54 , 0 , 0xffffffff ) ;
V_17 -> V_23 . V_201 =
F_98 ( V_17 , V_158 , L_55 , 0 , 0xffffffff ) ;
if ( V_17 -> V_23 . V_200 == NULL ||
V_17 -> V_23 . V_201 == NULL )
return - V_84 ;
return 0 ;
}
static int F_109 ( struct V_16 * V_17 , struct V_202 * V_203 )
{
T_1 V_204 = 0 ;
V_204 += V_17 -> V_23 . V_64 ;
V_204 += V_17 -> V_23 . V_114 ;
V_204 += V_17 -> V_23 . V_131 ;
V_203 -> V_205 = F_110 ( V_204 , sizeof( T_1 ) , V_26 ) ;
if ( ! V_203 -> V_205 )
return - V_84 ;
V_203 -> V_206 = 0 ;
V_203 -> V_207 = 0 ;
V_203 -> V_208 = 0 ;
return 0 ;
}
void F_111 ( struct V_202 * V_203 )
{
F_58 ( V_203 -> V_205 ) ;
V_203 -> V_205 = NULL ;
}
int F_112 ( struct V_16 * V_17 ,
struct V_202 * V_203 )
{
struct V_46 * V_47 ;
struct V_124 * V_125 ;
struct V_74 * V_75 ;
int V_22 ;
V_22 = F_109 ( V_17 , V_203 ) ;
if ( V_22 )
return V_22 ;
F_46 (crtc, &dev->mode_config.crtc_list, head)
V_203 -> V_205 [ V_203 -> V_206 ++ ] = V_47 -> V_39 . V_27 ;
F_46 (encoder, &dev->mode_config.encoder_list, head)
V_203 -> V_205 [ V_203 -> V_206 + V_203 -> V_208 ++ ] =
V_125 -> V_39 . V_27 ;
F_46 (connector, &dev->mode_config.connector_list, head)
V_203 -> V_205 [ V_203 -> V_206 + V_203 -> V_208 +
V_203 -> V_207 ++ ] = V_75 -> V_39 . V_27 ;
return 0 ;
}
void F_113 ( struct V_16 * V_17 )
{
F_45 ( V_17 ) ;
F_111 ( & V_17 -> V_52 -> V_209 ) ;
F_112 ( V_17 , & V_17 -> V_52 -> V_209 ) ;
F_50 ( V_17 ) ;
}
int F_114 ( struct V_16 * V_17 , void * V_210 ,
struct V_211 * V_212 )
{
struct V_213 * V_214 = V_210 ;
struct V_215 * V_216 ;
struct V_32 * V_33 ;
struct V_74 * V_75 ;
struct V_46 * V_47 ;
struct V_124 * V_125 ;
int V_22 = 0 ;
int V_217 = 0 ;
int V_218 = 0 ;
int V_219 = 0 ;
int V_220 = 0 ;
int V_221 = 0 , V_1 ;
T_1 T_3 * V_222 ;
T_1 T_3 * V_223 ;
T_1 T_3 * V_224 ;
T_1 T_3 * V_225 ;
struct V_202 * V_209 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
F_11 ( & V_212 -> V_227 ) ;
F_115 (lh, &file_priv->fbs)
V_219 ++ ;
if ( V_214 -> V_228 >= V_219 ) {
V_221 = 0 ;
V_222 = ( T_1 T_3 * ) ( unsigned long ) V_214 -> V_229 ;
F_46 (fb, &file_priv->fbs, filp_head) {
if ( F_116 ( V_33 -> V_39 . V_27 , V_222 + V_221 ) ) {
F_13 ( & V_212 -> V_227 ) ;
return - V_230 ;
}
V_221 ++ ;
}
}
V_214 -> V_228 = V_219 ;
F_13 ( & V_212 -> V_227 ) ;
F_11 ( & V_17 -> V_23 . V_60 ) ;
if ( ! F_117 ( V_212 ) ) {
V_209 = NULL ;
F_115 (lh, &dev->mode_config.crtc_list)
V_218 ++ ;
F_115 (lh, &dev->mode_config.connector_list)
V_217 ++ ;
F_115 (lh, &dev->mode_config.encoder_list)
V_220 ++ ;
} else {
V_209 = & V_212 -> V_231 -> V_232 -> V_209 ;
V_218 = V_209 -> V_206 ;
V_217 = V_209 -> V_207 ;
V_220 = V_209 -> V_208 ;
}
V_214 -> V_233 = V_17 -> V_23 . V_233 ;
V_214 -> V_234 = V_17 -> V_23 . V_234 ;
V_214 -> V_235 = V_17 -> V_23 . V_235 ;
V_214 -> V_236 = V_17 -> V_23 . V_236 ;
if ( V_214 -> V_237 >= V_218 ) {
V_221 = 0 ;
V_223 = ( T_1 T_3 * ) ( unsigned long ) V_214 -> V_238 ;
if ( ! V_209 ) {
F_46 (crtc, &dev->mode_config.crtc_list,
head) {
F_69 ( L_56 , V_47 -> V_39 . V_27 ) ;
if ( F_116 ( V_47 -> V_39 . V_27 , V_223 + V_221 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_221 ++ ;
}
} else {
for ( V_1 = 0 ; V_1 < V_209 -> V_206 ; V_1 ++ ) {
if ( F_116 ( V_209 -> V_205 [ V_1 ] ,
V_223 + V_221 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_221 ++ ;
}
}
}
V_214 -> V_237 = V_218 ;
if ( V_214 -> V_239 >= V_220 ) {
V_221 = 0 ;
V_225 = ( T_1 T_3 * ) ( unsigned long ) V_214 -> V_240 ;
if ( ! V_209 ) {
F_46 (encoder,
&dev->mode_config.encoder_list,
head) {
F_69 ( L_57 , V_125 -> V_39 . V_27 ,
V_125 -> V_11 ) ;
if ( F_116 ( V_125 -> V_39 . V_27 , V_225 +
V_221 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_221 ++ ;
}
} else {
for ( V_1 = V_209 -> V_206 ; V_1 < V_209 -> V_206 + V_209 -> V_208 ; V_1 ++ ) {
if ( F_116 ( V_209 -> V_205 [ V_1 ] ,
V_225 + V_221 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_221 ++ ;
}
}
}
V_214 -> V_239 = V_220 ;
if ( V_214 -> V_241 >= V_217 ) {
V_221 = 0 ;
V_224 = ( T_1 T_3 * ) ( unsigned long ) V_214 -> V_242 ;
if ( ! V_209 ) {
F_46 (connector,
&dev->mode_config.connector_list,
head) {
F_69 ( L_58 ,
V_75 -> V_39 . V_27 ,
V_75 -> V_11 ) ;
if ( F_116 ( V_75 -> V_39 . V_27 ,
V_224 + V_221 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_221 ++ ;
}
} else {
int V_243 = V_209 -> V_206 +
V_209 -> V_208 ;
for ( V_1 = V_243 ; V_1 < V_243 + V_209 -> V_207 ; V_1 ++ ) {
if ( F_116 ( V_209 -> V_205 [ V_1 ] ,
V_224 + V_221 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_221 ++ ;
}
}
}
V_214 -> V_241 = V_217 ;
F_69 ( L_59 , V_214 -> V_237 ,
V_214 -> V_241 , V_214 -> V_239 ) ;
V_40:
F_13 ( & V_17 -> V_23 . V_60 ) ;
return V_22 ;
}
int F_118 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_244 * V_245 = V_210 ;
struct V_46 * V_47 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
V_47 = F_119 ( V_17 , V_245 -> V_223 ) ;
if ( ! V_47 )
return - V_246 ;
F_120 ( V_47 , V_47 -> V_52 ) ;
V_245 -> V_247 = V_47 -> V_247 ;
if ( V_47 -> V_52 -> V_33 )
V_245 -> V_222 = V_47 -> V_52 -> V_33 -> V_39 . V_27 ;
else
V_245 -> V_222 = 0 ;
if ( V_47 -> V_70 ) {
V_245 -> V_248 = V_47 -> V_52 -> V_70 -> V_249 >> 16 ;
V_245 -> V_250 = V_47 -> V_52 -> V_70 -> V_251 >> 16 ;
if ( V_47 -> V_70 -> V_252 ) {
F_121 ( & V_245 -> V_77 , & V_47 -> V_70 -> V_77 ) ;
V_245 -> V_253 = 1 ;
} else {
V_245 -> V_253 = 0 ;
}
} else {
V_245 -> V_248 = V_47 -> V_248 ;
V_245 -> V_250 = V_47 -> V_250 ;
if ( V_47 -> V_254 ) {
F_121 ( & V_245 -> V_77 , & V_47 -> V_77 ) ;
V_245 -> V_253 = 1 ;
} else {
V_245 -> V_253 = 0 ;
}
}
F_122 ( V_47 ) ;
return 0 ;
}
static bool F_123 ( const struct V_76 * V_77 ,
const struct V_211 * V_212 )
{
if ( ! V_212 -> V_255 && F_124 ( V_77 ) )
return false ;
return true ;
}
static struct V_124 * F_125 ( struct V_74 * V_75 )
{
if ( V_75 -> V_70 )
return V_75 -> V_70 -> V_256 ;
return V_75 -> V_125 ;
}
static int F_126 ( struct V_18 * V_19 , bool V_257 ,
T_1 T_3 * V_258 , T_4 T_3 * V_259 ,
T_1 * V_260 )
{
int V_261 ;
int V_1 , V_22 , V_221 ;
V_261 = V_19 -> V_62 -> V_262 ;
if ( ! V_257 )
V_261 -= V_19 -> V_62 -> V_263 ;
if ( ( * V_260 >= V_261 ) && V_261 ) {
for ( V_1 = 0 , V_221 = 0 ; V_221 < V_261 ; V_1 ++ ) {
struct V_155 * V_156 = V_19 -> V_62 -> V_62 [ V_1 ] ;
T_4 V_264 ;
if ( ( V_156 -> V_265 & V_163 ) && ! V_257 )
continue;
V_22 = F_127 ( V_19 , V_156 , & V_264 ) ;
if ( V_22 )
return V_22 ;
if ( F_116 ( V_156 -> V_39 . V_27 , V_258 + V_221 ) )
return - V_230 ;
if ( F_116 ( V_264 , V_259 + V_221 ) )
return - V_230 ;
V_221 ++ ;
}
}
* V_260 = V_261 ;
return 0 ;
}
int F_128 ( struct V_16 * V_17 , void * V_210 ,
struct V_211 * V_212 )
{
struct V_266 * V_267 = V_210 ;
struct V_74 * V_75 ;
struct V_124 * V_125 ;
struct V_76 * V_77 ;
int V_268 = 0 ;
int V_269 = 0 ;
int V_22 = 0 ;
int V_221 = 0 ;
int V_1 ;
struct V_270 V_271 ;
struct V_270 T_3 * V_272 ;
T_1 T_3 * V_273 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
memset ( & V_271 , 0 , sizeof( struct V_270 ) ) ;
F_69 ( L_60 , V_267 -> V_224 ) ;
F_11 ( & V_17 -> V_23 . V_60 ) ;
V_75 = F_129 ( V_17 , V_267 -> V_224 ) ;
if ( ! V_75 ) {
V_22 = - V_246 ;
goto V_106;
}
for ( V_1 = 0 ; V_1 < V_274 ; V_1 ++ )
if ( V_75 -> V_275 [ V_1 ] != 0 )
V_269 ++ ;
if ( V_267 -> V_276 == 0 ) {
V_75 -> V_35 -> V_277 ( V_75 ,
V_17 -> V_23 . V_235 ,
V_17 -> V_23 . V_233 ) ;
}
F_46 (mode, &connector->modes, head)
if ( F_123 ( V_77 , V_212 ) )
V_268 ++ ;
V_267 -> V_224 = V_75 -> V_39 . V_27 ;
V_267 -> V_103 = V_75 -> V_103 ;
V_267 -> V_107 = V_75 -> V_107 ;
V_267 -> V_278 = V_75 -> V_122 . V_279 ;
V_267 -> V_280 = V_75 -> V_122 . V_281 ;
V_267 -> V_282 = V_75 -> V_122 . V_8 ;
V_267 -> V_283 = V_75 -> V_5 ;
F_130 ( & V_17 -> V_23 . V_123 , NULL ) ;
V_125 = F_125 ( V_75 ) ;
if ( V_125 )
V_267 -> V_225 = V_125 -> V_39 . V_27 ;
else
V_267 -> V_225 = 0 ;
if ( ( V_267 -> V_276 >= V_268 ) && V_268 ) {
V_221 = 0 ;
V_272 = (struct V_270 T_3 * ) ( unsigned long ) V_267 -> V_284 ;
F_46 (mode, &connector->modes, head) {
if ( ! F_123 ( V_77 , V_212 ) )
continue;
F_121 ( & V_271 , V_77 ) ;
if ( F_131 ( V_272 + V_221 ,
& V_271 , sizeof( V_271 ) ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_221 ++ ;
}
}
V_267 -> V_276 = V_268 ;
V_22 = F_126 ( & V_75 -> V_39 , V_212 -> V_257 ,
( T_1 T_3 * ) ( unsigned long ) ( V_267 -> V_285 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_267 -> V_286 ) ,
& V_267 -> V_287 ) ;
if ( V_22 )
goto V_40;
if ( ( V_267 -> V_239 >= V_269 ) && V_269 ) {
V_221 = 0 ;
V_273 = ( T_1 T_3 * ) ( unsigned long ) ( V_267 -> V_288 ) ;
for ( V_1 = 0 ; V_1 < V_274 ; V_1 ++ ) {
if ( V_75 -> V_275 [ V_1 ] != 0 ) {
if ( F_116 ( V_75 -> V_275 [ V_1 ] ,
V_273 + V_221 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_221 ++ ;
}
}
}
V_267 -> V_239 = V_269 ;
V_40:
F_132 ( & V_17 -> V_23 . V_123 ) ;
V_106:
F_13 ( & V_17 -> V_23 . V_60 ) ;
return V_22 ;
}
static struct V_46 * F_133 ( struct V_124 * V_125 )
{
struct V_74 * V_75 ;
struct V_16 * V_17 = V_125 -> V_17 ;
bool V_289 = false ;
F_46 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_75 -> V_70 )
continue;
V_289 = true ;
if ( V_75 -> V_70 -> V_256 != V_125 )
continue;
return V_75 -> V_70 -> V_47 ;
}
if ( V_289 )
return NULL ;
return V_125 -> V_47 ;
}
int F_134 ( struct V_16 * V_17 , void * V_210 ,
struct V_211 * V_212 )
{
struct V_290 * V_291 = V_210 ;
struct V_124 * V_125 ;
struct V_46 * V_47 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
V_125 = F_135 ( V_17 , V_291 -> V_225 ) ;
if ( ! V_125 )
return - V_246 ;
F_130 ( & V_17 -> V_23 . V_123 , NULL ) ;
V_47 = F_133 ( V_125 ) ;
if ( V_47 )
V_291 -> V_223 = V_47 -> V_39 . V_27 ;
else
V_291 -> V_223 = 0 ;
F_132 ( & V_17 -> V_23 . V_123 ) ;
V_291 -> V_127 = V_125 -> V_127 ;
V_291 -> V_225 = V_125 -> V_39 . V_27 ;
V_291 -> V_65 = V_125 -> V_65 ;
V_291 -> V_292 = V_125 -> V_292 ;
return 0 ;
}
int F_136 ( struct V_16 * V_17 , void * V_210 ,
struct V_211 * V_212 )
{
struct V_293 * V_294 = V_210 ;
struct V_55 * V_56 ;
struct V_48 * V_49 ;
T_1 T_3 * V_295 ;
int V_221 = 0 ;
unsigned V_296 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
V_56 = & V_17 -> V_23 ;
if ( V_212 -> V_297 )
V_296 = V_56 -> V_138 ;
else
V_296 = V_56 -> V_140 ;
if ( V_296 &&
( V_294 -> V_298 >= V_296 ) ) {
V_295 = ( T_1 T_3 * ) ( unsigned long ) V_294 -> V_299 ;
F_46 (plane, &config->plane_list, head) {
if ( V_49 -> type != V_139 &&
! V_212 -> V_297 )
continue;
if ( F_116 ( V_49 -> V_39 . V_27 , V_295 + V_221 ) )
return - V_230 ;
V_221 ++ ;
}
}
V_294 -> V_298 = V_296 ;
return 0 ;
}
int F_137 ( struct V_16 * V_17 , void * V_210 ,
struct V_211 * V_212 )
{
struct V_300 * V_294 = V_210 ;
struct V_48 * V_49 ;
T_1 T_3 * V_301 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
V_49 = F_138 ( V_17 , V_294 -> V_302 ) ;
if ( ! V_49 )
return - V_246 ;
F_130 ( & V_49 -> V_60 , NULL ) ;
if ( V_49 -> V_47 )
V_294 -> V_223 = V_49 -> V_47 -> V_39 . V_27 ;
else
V_294 -> V_223 = 0 ;
if ( V_49 -> V_33 )
V_294 -> V_222 = V_49 -> V_33 -> V_39 . V_27 ;
else
V_294 -> V_222 = 0 ;
F_132 ( & V_49 -> V_60 ) ;
V_294 -> V_302 = V_49 -> V_39 . V_27 ;
V_294 -> V_65 = V_49 -> V_65 ;
V_294 -> V_247 = 0 ;
if ( V_49 -> V_133 &&
( V_294 -> V_303 >= V_49 -> V_133 ) ) {
V_301 = ( T_1 T_3 * ) ( unsigned long ) V_294 -> V_304 ;
if ( F_131 ( V_301 ,
V_49 -> V_136 ,
sizeof( T_1 ) * V_49 -> V_133 ) ) {
return - V_230 ;
}
}
V_294 -> V_303 = V_49 -> V_133 ;
return 0 ;
}
int F_139 ( const struct V_48 * V_49 , T_2 V_13 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_49 -> V_133 ; V_1 ++ ) {
if ( V_13 == V_49 -> V_136 [ V_1 ] )
return 0 ;
}
return - V_83 ;
}
static int F_140 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_5 V_305 , T_5 V_306 ,
T_1 V_307 , T_1 V_308 ,
T_1 V_249 , T_1 V_251 ,
T_1 V_309 , T_1 V_310 )
{
int V_22 = 0 ;
unsigned int V_311 , V_312 ;
if ( ! V_33 ) {
V_49 -> V_153 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_154 ( V_49 ) ;
if ( ! V_22 ) {
V_49 -> V_47 = NULL ;
V_49 -> V_33 = NULL ;
} else {
V_49 -> V_153 = NULL ;
}
goto V_40;
}
if ( ! ( V_49 -> V_65 & F_141 ( V_47 ) ) ) {
F_69 ( L_61 ) ;
V_22 = - V_83 ;
goto V_40;
}
V_22 = F_139 ( V_49 , V_33 -> V_313 ) ;
if ( V_22 ) {
F_69 ( L_62 ,
F_9 ( V_33 -> V_313 ) ) ;
goto V_40;
}
if ( V_307 > V_166 ||
V_305 > V_166 - ( T_5 ) V_307 ||
V_308 > V_166 ||
V_306 > V_166 - ( T_5 ) V_308 ) {
F_69 ( L_63 ,
V_307 , V_308 , V_305 , V_306 ) ;
return - V_314 ;
}
V_311 = V_33 -> V_315 << 16 ;
V_312 = V_33 -> V_316 << 16 ;
if ( V_309 > V_311 ||
V_249 > V_311 - V_309 ||
V_310 > V_312 ||
V_251 > V_312 - V_310 ) {
F_69 ( L_64
L_65 ,
V_309 >> 16 , ( ( V_309 & 0xffff ) * 15625 ) >> 10 ,
V_310 >> 16 , ( ( V_310 & 0xffff ) * 15625 ) >> 10 ,
V_249 >> 16 , ( ( V_249 & 0xffff ) * 15625 ) >> 10 ,
V_251 >> 16 , ( ( V_251 & 0xffff ) * 15625 ) >> 10 ) ;
V_22 = - V_317 ;
goto V_40;
}
V_49 -> V_153 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_318 ( V_49 , V_47 , V_33 ,
V_305 , V_306 , V_307 , V_308 ,
V_249 , V_251 , V_309 , V_310 ) ;
if ( ! V_22 ) {
V_49 -> V_47 = V_47 ;
V_49 -> V_33 = V_33 ;
V_33 = NULL ;
} else {
V_49 -> V_153 = NULL ;
}
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
if ( V_49 -> V_153 )
F_34 ( V_49 -> V_153 ) ;
V_49 -> V_153 = NULL ;
return V_22 ;
}
static int F_142 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_5 V_305 , T_5 V_306 ,
T_1 V_307 , T_1 V_308 ,
T_1 V_249 , T_1 V_251 ,
T_1 V_309 , T_1 V_310 )
{
int V_22 ;
F_45 ( V_49 -> V_17 ) ;
V_22 = F_140 ( V_49 , V_47 , V_33 ,
V_305 , V_306 , V_307 , V_308 ,
V_249 , V_251 , V_309 , V_310 ) ;
F_50 ( V_49 -> V_17 ) ;
return V_22 ;
}
int F_143 ( struct V_16 * V_17 , void * V_210 ,
struct V_211 * V_212 )
{
struct V_319 * V_320 = V_210 ;
struct V_48 * V_49 ;
struct V_46 * V_47 = NULL ;
struct V_32 * V_33 = NULL ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
V_49 = F_138 ( V_17 , V_320 -> V_302 ) ;
if ( ! V_49 ) {
F_69 ( L_66 ,
V_320 -> V_302 ) ;
return - V_246 ;
}
if ( V_320 -> V_222 ) {
V_33 = F_32 ( V_17 , V_320 -> V_222 ) ;
if ( ! V_33 ) {
F_69 ( L_67 ,
V_320 -> V_222 ) ;
return - V_246 ;
}
V_47 = F_119 ( V_17 , V_320 -> V_223 ) ;
if ( ! V_47 ) {
F_69 ( L_68 ,
V_320 -> V_223 ) ;
return - V_246 ;
}
}
return F_142 ( V_49 , V_47 , V_33 ,
V_320 -> V_305 , V_320 -> V_306 ,
V_320 -> V_307 , V_320 -> V_308 ,
V_320 -> V_249 , V_320 -> V_251 ,
V_320 -> V_309 , V_320 -> V_310 ) ;
}
int F_47 ( struct V_50 * V_51 )
{
struct V_46 * V_47 = V_51 -> V_47 ;
struct V_32 * V_33 ;
struct V_46 * V_73 ;
int V_22 ;
F_46 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_73 -> V_52 -> V_153 = V_73 -> V_52 -> V_33 ;
V_33 = V_51 -> V_33 ;
V_22 = V_47 -> V_35 -> V_321 ( V_51 ) ;
if ( V_22 == 0 ) {
V_47 -> V_52 -> V_47 = V_47 ;
V_47 -> V_52 -> V_33 = V_33 ;
}
F_46 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_73 -> V_52 -> V_33 )
F_38 ( V_73 -> V_52 -> V_33 ) ;
if ( V_73 -> V_52 -> V_153 )
F_34 ( V_73 -> V_52 -> V_153 ) ;
V_73 -> V_52 -> V_153 = NULL ;
}
return V_22 ;
}
void F_144 ( const struct V_76 * V_77 ,
int * V_322 , int * V_323 )
{
struct V_76 V_324 ;
F_145 ( & V_324 , V_77 ) ;
F_146 ( & V_324 , V_325 ) ;
* V_322 = V_324 . V_326 ;
* V_323 = V_324 . V_327 ;
}
int F_147 ( const struct V_46 * V_47 ,
int V_248 , int V_250 ,
const struct V_76 * V_77 ,
const struct V_32 * V_33 )
{
int V_322 , V_323 ;
F_144 ( V_77 , & V_322 , & V_323 ) ;
if ( V_47 -> V_59 )
F_148 ( V_322 , V_323 ) ;
if ( V_322 > V_33 -> V_315 ||
V_323 > V_33 -> V_316 ||
V_248 > V_33 -> V_315 - V_322 ||
V_250 > V_33 -> V_316 - V_323 ) {
F_69 ( L_69 ,
V_33 -> V_315 , V_33 -> V_316 , V_322 , V_323 , V_248 , V_250 ,
V_47 -> V_59 ? L_70 : L_15 ) ;
return - V_317 ;
}
return 0 ;
}
int F_149 ( struct V_16 * V_17 , void * V_210 ,
struct V_211 * V_212 )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
struct V_244 * V_328 = V_210 ;
struct V_46 * V_47 ;
struct V_74 * * V_329 = NULL , * V_75 ;
struct V_32 * V_33 = NULL ;
struct V_76 * V_77 = NULL ;
struct V_50 V_51 ;
T_1 T_3 * V_330 ;
int V_22 ;
int V_1 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
if ( V_328 -> V_248 & 0xffff0000 || V_328 -> V_250 & 0xffff0000 )
return - V_314 ;
F_45 ( V_17 ) ;
V_47 = F_119 ( V_17 , V_328 -> V_223 ) ;
if ( ! V_47 ) {
F_69 ( L_71 , V_328 -> V_223 ) ;
V_22 = - V_246 ;
goto V_40;
}
F_69 ( L_56 , V_47 -> V_39 . V_27 ) ;
if ( V_328 -> V_253 ) {
if ( V_328 -> V_222 == - 1 ) {
if ( ! V_47 -> V_52 -> V_33 ) {
F_69 ( L_72 ) ;
V_22 = - V_83 ;
goto V_40;
}
V_33 = V_47 -> V_52 -> V_33 ;
F_38 ( V_33 ) ;
} else {
V_33 = F_32 ( V_17 , V_328 -> V_222 ) ;
if ( ! V_33 ) {
F_69 ( L_73 ,
V_328 -> V_222 ) ;
V_22 = - V_246 ;
goto V_40;
}
}
V_77 = F_150 ( V_17 ) ;
if ( ! V_77 ) {
V_22 = - V_84 ;
goto V_40;
}
V_22 = F_151 ( V_77 , & V_328 -> V_77 ) ;
if ( V_22 ) {
F_69 ( L_74 ) ;
goto V_40;
}
F_146 ( V_77 , V_331 ) ;
if ( ! V_47 -> V_52 -> V_332 ) {
V_22 = F_139 ( V_47 -> V_52 ,
V_33 -> V_313 ) ;
if ( V_22 ) {
F_69 ( L_62 ,
F_9 ( V_33 -> V_313 ) ) ;
goto V_40;
}
}
V_22 = F_147 ( V_47 , V_328 -> V_248 , V_328 -> V_250 ,
V_77 , V_33 ) ;
if ( V_22 )
goto V_40;
}
if ( V_328 -> V_241 == 0 && V_77 ) {
F_69 ( L_75 ) ;
V_22 = - V_83 ;
goto V_40;
}
if ( V_328 -> V_241 > 0 && ( ! V_77 || ! V_33 ) ) {
F_69 ( L_76 ,
V_328 -> V_241 ) ;
V_22 = - V_83 ;
goto V_40;
}
if ( V_328 -> V_241 > 0 ) {
T_2 V_333 ;
if ( V_328 -> V_241 > V_56 -> V_114 ) {
V_22 = - V_83 ;
goto V_40;
}
V_329 = F_89 ( V_328 -> V_241 ,
sizeof( struct V_74 * ) ,
V_26 ) ;
if ( ! V_329 ) {
V_22 = - V_84 ;
goto V_40;
}
for ( V_1 = 0 ; V_1 < V_328 -> V_241 ; V_1 ++ ) {
V_330 = ( T_1 T_3 * ) ( unsigned long ) V_328 -> V_330 ;
if ( F_152 ( V_333 , & V_330 [ V_1 ] ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_75 = F_129 ( V_17 , V_333 ) ;
if ( ! V_75 ) {
F_69 ( L_77 ,
V_333 ) ;
V_22 = - V_246 ;
goto V_40;
}
F_69 ( L_58 ,
V_75 -> V_39 . V_27 ,
V_75 -> V_11 ) ;
V_329 [ V_1 ] = V_75 ;
}
}
V_51 . V_47 = V_47 ;
V_51 . V_248 = V_328 -> V_248 ;
V_51 . V_250 = V_328 -> V_250 ;
V_51 . V_77 = V_77 ;
V_51 . V_334 = V_329 ;
V_51 . V_207 = V_328 -> V_241 ;
V_51 . V_33 = V_33 ;
V_22 = F_47 ( & V_51 ) ;
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
F_58 ( V_329 ) ;
F_62 ( V_17 , V_77 ) ;
F_50 ( V_17 ) ;
return V_22 ;
}
static int F_153 ( struct V_46 * V_47 ,
struct V_335 * V_336 ,
struct V_211 * V_212 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
struct V_32 * V_33 = NULL ;
struct V_337 V_338 = {
. V_315 = V_336 -> V_315 ,
. V_316 = V_336 -> V_316 ,
. V_313 = V_339 ,
. V_340 = { V_336 -> V_315 * 4 } ,
. V_341 = { V_336 -> V_342 } ,
} ;
T_5 V_305 , V_306 ;
T_1 V_307 = 0 , V_308 = 0 ;
T_1 V_309 = 0 , V_310 = 0 ;
int V_22 = 0 ;
F_92 ( ! V_47 -> V_53 ) ;
F_22 ( V_47 -> V_53 -> V_47 != V_47 && V_47 -> V_53 -> V_47 != NULL ) ;
if ( V_336 -> V_265 & V_343 ) {
if ( V_336 -> V_342 ) {
V_33 = F_154 ( V_17 , & V_338 , V_212 ) ;
if ( F_155 ( V_33 ) ) {
F_69 ( L_78 ) ;
return F_156 ( V_33 ) ;
}
} else {
V_33 = NULL ;
}
} else {
V_33 = V_47 -> V_53 -> V_33 ;
if ( V_33 )
F_38 ( V_33 ) ;
}
if ( V_336 -> V_265 & V_344 ) {
V_305 = V_336 -> V_248 ;
V_306 = V_336 -> V_250 ;
} else {
V_305 = V_47 -> V_345 ;
V_306 = V_47 -> V_346 ;
}
if ( V_33 ) {
V_307 = V_33 -> V_315 ;
V_308 = V_33 -> V_316 ;
V_309 = V_33 -> V_315 << 16 ;
V_310 = V_33 -> V_316 << 16 ;
}
V_22 = F_140 ( V_47 -> V_53 , V_47 , V_33 ,
V_305 , V_306 , V_307 , V_308 ,
0 , 0 , V_309 , V_310 ) ;
if ( V_22 == 0 && V_336 -> V_265 & V_344 ) {
V_47 -> V_345 = V_336 -> V_248 ;
V_47 -> V_346 = V_336 -> V_250 ;
}
return V_22 ;
}
static int F_157 ( struct V_16 * V_17 ,
struct V_335 * V_336 ,
struct V_211 * V_212 )
{
struct V_46 * V_47 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
if ( ! V_336 -> V_265 || ( ~ V_347 & V_336 -> V_265 ) )
return - V_83 ;
V_47 = F_119 ( V_17 , V_336 -> V_223 ) ;
if ( ! V_47 ) {
F_69 ( L_71 , V_336 -> V_223 ) ;
return - V_246 ;
}
F_120 ( V_47 , V_47 -> V_53 ) ;
if ( V_47 -> V_53 ) {
V_22 = F_153 ( V_47 , V_336 , V_212 ) ;
goto V_40;
}
if ( V_336 -> V_265 & V_343 ) {
if ( ! V_47 -> V_35 -> V_348 && ! V_47 -> V_35 -> V_349 ) {
V_22 = - V_350 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_349 )
V_22 = V_47 -> V_35 -> V_349 ( V_47 , V_212 , V_336 -> V_342 ,
V_336 -> V_315 , V_336 -> V_316 , V_336 -> V_351 , V_336 -> V_352 ) ;
else
V_22 = V_47 -> V_35 -> V_348 ( V_47 , V_212 , V_336 -> V_342 ,
V_336 -> V_315 , V_336 -> V_316 ) ;
}
if ( V_336 -> V_265 & V_344 ) {
if ( V_47 -> V_35 -> V_353 ) {
V_22 = V_47 -> V_35 -> V_353 ( V_47 , V_336 -> V_248 , V_336 -> V_250 ) ;
} else {
V_22 = - V_230 ;
goto V_40;
}
}
V_40:
F_122 ( V_47 ) ;
return V_22 ;
}
int F_158 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_354 * V_336 = V_210 ;
struct V_335 V_355 ;
memcpy ( & V_355 , V_336 , sizeof( struct V_354 ) ) ;
V_355 . V_351 = V_355 . V_352 = 0 ;
return F_157 ( V_17 , & V_355 , V_212 ) ;
}
int F_159 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_335 * V_336 = V_210 ;
return F_157 ( V_17 , V_336 , V_212 ) ;
}
T_1 F_160 ( T_1 V_356 , T_1 V_357 )
{
T_1 V_358 ;
switch ( V_356 ) {
case 8 :
V_358 = V_359 ;
break;
case 16 :
if ( V_357 == 15 )
V_358 = V_360 ;
else
V_358 = V_361 ;
break;
case 24 :
V_358 = V_362 ;
break;
case 32 :
if ( V_357 == 24 )
V_358 = V_363 ;
else if ( V_357 == 30 )
V_358 = V_364 ;
else
V_358 = V_339 ;
break;
default:
F_48 ( L_79 ) ;
V_358 = V_363 ;
break;
}
return V_358 ;
}
int F_161 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_365 * V_366 = V_210 ;
struct V_337 V_367 = {} ;
int V_22 ;
V_367 . V_222 = V_366 -> V_222 ;
V_367 . V_315 = V_366 -> V_315 ;
V_367 . V_316 = V_366 -> V_316 ;
V_367 . V_340 [ 0 ] = V_366 -> V_368 ;
V_367 . V_313 = F_160 ( V_366 -> V_356 , V_366 -> V_357 ) ;
V_367 . V_341 [ 0 ] = V_366 -> V_342 ;
V_22 = F_162 ( V_17 , & V_367 , V_212 ) ;
if ( V_22 )
return V_22 ;
V_366 -> V_222 = V_367 . V_222 ;
return 0 ;
}
static int F_163 ( const struct V_337 * V_367 )
{
T_1 V_13 = V_367 -> V_313 & ~ V_15 ;
switch ( V_13 ) {
case V_359 :
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
case V_360 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_361 :
case V_386 :
case V_362 :
case V_387 :
case V_363 :
case V_388 :
case V_389 :
case V_390 :
case V_339 :
case V_391 :
case V_392 :
case V_393 :
case V_364 :
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
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
return 0 ;
default:
F_69 ( L_80 ,
F_9 ( V_367 -> V_313 ) ) ;
return - V_83 ;
}
}
static int F_164 ( const struct V_337 * V_367 )
{
int V_22 , V_422 , V_423 , V_296 , V_1 ;
V_22 = F_163 ( V_367 ) ;
if ( V_22 ) {
F_69 ( L_81 ,
F_9 ( V_367 -> V_313 ) ) ;
return V_22 ;
}
V_422 = F_165 ( V_367 -> V_313 ) ;
V_423 = F_166 ( V_367 -> V_313 ) ;
V_296 = F_167 ( V_367 -> V_313 ) ;
if ( V_367 -> V_315 == 0 || V_367 -> V_315 % V_422 ) {
F_69 ( L_82 , V_367 -> V_315 ) ;
return - V_83 ;
}
if ( V_367 -> V_316 == 0 || V_367 -> V_316 % V_423 ) {
F_69 ( L_83 , V_367 -> V_316 ) ;
return - V_83 ;
}
for ( V_1 = 0 ; V_1 < V_296 ; V_1 ++ ) {
unsigned int V_315 = V_367 -> V_315 / ( V_1 != 0 ? V_422 : 1 ) ;
unsigned int V_316 = V_367 -> V_316 / ( V_1 != 0 ? V_423 : 1 ) ;
unsigned int V_424 = F_168 ( V_367 -> V_313 , V_1 ) ;
if ( ! V_367 -> V_341 [ V_1 ] ) {
F_69 ( L_84 , V_1 ) ;
return - V_83 ;
}
if ( ( T_4 ) V_315 * V_424 > V_164 )
return - V_314 ;
if ( ( T_4 ) V_316 * V_367 -> V_340 [ V_1 ] + V_367 -> V_425 [ V_1 ] > V_164 )
return - V_314 ;
if ( V_367 -> V_340 [ V_1 ] < V_315 * V_424 ) {
F_69 ( L_85 , V_367 -> V_340 [ V_1 ] , V_1 ) ;
return - V_83 ;
}
if ( V_367 -> V_426 [ V_1 ] && ! ( V_367 -> V_265 & V_427 ) ) {
F_69 ( L_86 ,
V_367 -> V_426 [ V_1 ] , V_1 ) ;
return - V_83 ;
}
switch ( V_367 -> V_426 [ V_1 ] ) {
case V_428 :
if ( V_367 -> V_313 != V_406 ||
V_315 % 128 || V_316 % 32 ||
V_367 -> V_340 [ V_1 ] % 128 ) {
F_69 ( L_87 , V_1 ) ;
return - V_83 ;
}
break;
default:
break;
}
}
for ( V_1 = V_296 ; V_1 < 4 ; V_1 ++ ) {
if ( V_367 -> V_426 [ V_1 ] ) {
F_69 ( L_88 , V_1 ) ;
return - V_83 ;
}
if ( ! ( V_367 -> V_265 & V_427 ) )
continue;
if ( V_367 -> V_341 [ V_1 ] ) {
F_69 ( L_89 , V_1 ) ;
return - V_83 ;
}
if ( V_367 -> V_340 [ V_1 ] ) {
F_69 ( L_90 , V_1 ) ;
return - V_83 ;
}
if ( V_367 -> V_425 [ V_1 ] ) {
F_69 ( L_91 , V_1 ) ;
return - V_83 ;
}
}
return 0 ;
}
static struct V_32 *
F_154 ( struct V_16 * V_17 ,
struct V_337 * V_367 ,
struct V_211 * V_212 )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
struct V_32 * V_33 ;
int V_22 ;
if ( V_367 -> V_265 & ~ ( V_429 | V_427 ) ) {
F_69 ( L_92 , V_367 -> V_265 ) ;
return F_169 ( - V_83 ) ;
}
if ( ( V_56 -> V_236 > V_367 -> V_315 ) || ( V_367 -> V_315 > V_56 -> V_235 ) ) {
F_69 ( L_93 ,
V_367 -> V_315 , V_56 -> V_236 , V_56 -> V_235 ) ;
return F_169 ( - V_83 ) ;
}
if ( ( V_56 -> V_234 > V_367 -> V_316 ) || ( V_367 -> V_316 > V_56 -> V_233 ) ) {
F_69 ( L_94 ,
V_367 -> V_316 , V_56 -> V_234 , V_56 -> V_233 ) ;
return F_169 ( - V_83 ) ;
}
if ( V_367 -> V_265 & V_427 &&
! V_17 -> V_23 . V_430 ) {
F_69 ( L_95 ) ;
return F_169 ( - V_83 ) ;
}
V_22 = F_164 ( V_367 ) ;
if ( V_22 )
return F_169 ( V_22 ) ;
V_33 = V_17 -> V_23 . V_35 -> V_431 ( V_17 , V_212 , V_367 ) ;
if ( F_155 ( V_33 ) ) {
F_69 ( L_96 ) ;
return V_33 ;
}
return V_33 ;
}
int F_162 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_337 * V_367 = V_210 ;
struct V_32 * V_33 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
V_33 = F_154 ( V_17 , V_367 , V_212 ) ;
if ( F_155 ( V_33 ) )
return F_156 ( V_33 ) ;
F_69 ( L_97 , V_33 -> V_39 . V_27 ) ;
F_11 ( & V_212 -> V_227 ) ;
V_367 -> V_222 = V_33 -> V_39 . V_27 ;
F_26 ( & V_33 -> V_38 , & V_212 -> V_432 ) ;
F_13 ( & V_212 -> V_227 ) ;
return 0 ;
}
int F_170 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_32 * V_33 = NULL ;
struct V_32 * V_433 = NULL ;
T_1 * V_27 = V_210 ;
int V_434 = 0 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
F_11 ( & V_212 -> V_227 ) ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
V_33 = F_30 ( V_17 , * V_27 ) ;
if ( ! V_33 )
goto V_435;
F_46 (fbl, &file_priv->fbs, filp_head)
if ( V_33 == V_433 )
V_434 = 1 ;
if ( ! V_434 )
goto V_435;
F_27 ( V_17 , V_33 ) ;
F_171 ( & V_33 -> V_38 ) ;
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_212 -> V_227 ) ;
F_43 ( V_33 ) ;
return 0 ;
V_435:
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_212 -> V_227 ) ;
return - V_246 ;
}
int F_172 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_365 * V_367 = V_210 ;
struct V_32 * V_33 ;
int V_22 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
V_33 = F_32 ( V_17 , V_367 -> V_222 ) ;
if ( ! V_33 )
return - V_246 ;
V_367 -> V_316 = V_33 -> V_316 ;
V_367 -> V_315 = V_33 -> V_315 ;
V_367 -> V_357 = V_33 -> V_357 ;
V_367 -> V_356 = V_33 -> V_436 ;
V_367 -> V_368 = V_33 -> V_340 [ 0 ] ;
if ( V_33 -> V_35 -> V_437 ) {
if ( V_212 -> V_438 || F_173 ( V_439 ) ||
F_174 ( V_212 ) ) {
V_22 = V_33 -> V_35 -> V_437 ( V_33 , V_212 ,
& V_367 -> V_342 ) ;
} else {
V_367 -> V_342 = 0 ;
V_22 = 0 ;
}
} else {
V_22 = - V_440 ;
}
F_34 ( V_33 ) ;
return V_22 ;
}
int F_175 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_441 T_3 * V_442 ;
struct V_441 * V_443 = NULL ;
struct V_444 * V_367 = V_210 ;
struct V_32 * V_33 ;
unsigned V_265 ;
int V_445 ;
int V_22 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
V_33 = F_32 ( V_17 , V_367 -> V_222 ) ;
if ( ! V_33 )
return - V_246 ;
V_445 = V_367 -> V_445 ;
V_442 = (struct V_441 T_3 * ) ( unsigned long ) V_367 -> V_442 ;
if ( ! V_445 != ! V_442 ) {
V_22 = - V_83 ;
goto V_446;
}
V_265 = V_447 & V_367 -> V_265 ;
if ( V_265 & V_448 && ( V_445 % 2 ) ) {
V_22 = - V_83 ;
goto V_446;
}
if ( V_445 && V_442 ) {
if ( V_445 < 0 || V_445 > V_449 ) {
V_22 = - V_83 ;
goto V_446;
}
V_443 = F_110 ( V_445 , sizeof( * V_443 ) , V_26 ) ;
if ( ! V_443 ) {
V_22 = - V_84 ;
goto V_446;
}
V_22 = F_176 ( V_443 , V_442 ,
V_445 * sizeof( * V_443 ) ) ;
if ( V_22 ) {
V_22 = - V_230 ;
goto V_450;
}
}
if ( V_33 -> V_35 -> V_451 ) {
V_22 = V_33 -> V_35 -> V_451 ( V_33 , V_212 , V_265 , V_367 -> V_452 ,
V_443 , V_445 ) ;
} else {
V_22 = - V_453 ;
}
V_450:
F_58 ( V_443 ) ;
V_446:
F_34 ( V_33 ) ;
return V_22 ;
}
void F_177 ( struct V_211 * V_454 )
{
struct V_16 * V_17 = V_454 -> V_232 -> V_17 ;
struct V_32 * V_33 , * V_455 ;
F_75 (fb, tfb, &priv->fbs, filp_head) {
F_11 ( & V_17 -> V_23 . V_36 ) ;
F_27 ( V_17 , V_33 ) ;
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_171 ( & V_33 -> V_38 ) ;
F_43 ( V_33 ) ;
}
}
struct V_155 * F_96 ( struct V_16 * V_17 , int V_265 ,
const char * V_11 , int V_456 )
{
struct V_155 * V_457 = NULL ;
int V_22 ;
V_457 = F_178 ( sizeof( struct V_155 ) , V_26 ) ;
if ( ! V_457 )
return NULL ;
V_457 -> V_17 = V_17 ;
if ( V_456 ) {
V_457 -> V_458 = F_110 ( V_456 , sizeof( T_4 ) ,
V_26 ) ;
if ( ! V_457 -> V_458 )
goto V_459;
}
V_22 = F_14 ( V_17 , & V_457 -> V_39 , V_460 ) ;
if ( V_22 )
goto V_459;
V_457 -> V_265 = V_265 ;
V_457 -> V_456 = V_456 ;
F_25 ( & V_457 -> V_461 ) ;
if ( V_11 ) {
strncpy ( V_457 -> V_11 , V_11 , V_462 ) ;
V_457 -> V_11 [ V_462 - 1 ] = '\0' ;
}
F_53 ( & V_457 -> V_42 , & V_17 -> V_23 . V_463 ) ;
F_22 ( ! F_179 ( V_457 ) ) ;
return V_457 ;
V_459:
F_58 ( V_457 -> V_458 ) ;
F_58 ( V_457 ) ;
return NULL ;
}
struct V_155 * F_97 ( struct V_16 * V_17 , int V_265 ,
const char * V_11 ,
const struct V_464 * V_465 ,
int V_456 )
{
struct V_155 * V_457 ;
int V_1 , V_22 ;
V_265 |= V_185 ;
V_457 = F_96 ( V_17 , V_265 , V_11 , V_456 ) ;
if ( ! V_457 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_456 ; V_1 ++ ) {
V_22 = F_104 ( V_457 , V_1 ,
V_465 [ V_1 ] . type ,
V_465 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_180 ( V_17 , V_457 ) ;
return NULL ;
}
}
return V_457 ;
}
struct V_155 * F_181 ( struct V_16 * V_17 ,
int V_265 , const char * V_11 ,
const struct V_464 * V_465 ,
int V_466 ,
T_4 V_467 )
{
struct V_155 * V_457 ;
int V_1 , V_22 , V_72 = 0 ;
int V_456 = F_182 ( V_467 ) ;
V_265 |= V_468 ;
V_457 = F_96 ( V_17 , V_265 , V_11 , V_456 ) ;
if ( ! V_457 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_466 ; V_1 ++ ) {
if ( ! ( V_467 & ( 1ULL << V_465 [ V_1 ] . type ) ) )
continue;
if ( F_22 ( V_72 >= V_456 ) ) {
F_180 ( V_17 , V_457 ) ;
return NULL ;
}
V_22 = F_104 ( V_457 , V_72 ++ ,
V_465 [ V_1 ] . type ,
V_465 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_180 ( V_17 , V_457 ) ;
return NULL ;
}
}
return V_457 ;
}
static struct V_155 * F_183 ( struct V_16 * V_17 ,
int V_265 , const char * V_11 ,
T_4 V_469 , T_4 V_470 )
{
struct V_155 * V_457 ;
V_457 = F_96 ( V_17 , V_265 , V_11 , 2 ) ;
if ( ! V_457 )
return NULL ;
V_457 -> V_458 [ 0 ] = V_469 ;
V_457 -> V_458 [ 1 ] = V_470 ;
return V_457 ;
}
struct V_155 * F_98 ( struct V_16 * V_17 , int V_265 ,
const char * V_11 ,
T_4 V_469 , T_4 V_470 )
{
return F_183 ( V_17 , V_471 | V_265 ,
V_11 , V_469 , V_470 ) ;
}
struct V_155 * F_99 ( struct V_16 * V_17 ,
int V_265 , const char * V_11 ,
T_6 V_469 , T_6 V_470 )
{
return F_183 ( V_17 , V_472 | V_265 ,
V_11 , F_184 ( V_469 ) , F_184 ( V_470 ) ) ;
}
struct V_155 * F_100 ( struct V_16 * V_17 ,
int V_265 , const char * V_11 , T_1 type )
{
struct V_155 * V_457 ;
V_265 |= V_473 ;
if ( F_22 ( ! ( V_265 & V_163 ) ) )
return NULL ;
V_457 = F_96 ( V_17 , V_265 , V_11 , 1 ) ;
if ( ! V_457 )
return NULL ;
V_457 -> V_458 [ 0 ] = type ;
return V_457 ;
}
struct V_155 * F_101 ( struct V_16 * V_17 , int V_265 ,
const char * V_11 )
{
return F_98 ( V_17 , V_265 , V_11 , 0 , 1 ) ;
}
int F_104 ( struct V_155 * V_457 , int V_72 ,
T_4 V_474 , const char * V_11 )
{
struct V_475 * V_476 ;
if ( ! ( F_185 ( V_457 , V_185 ) ||
F_185 ( V_457 , V_468 ) ) )
return - V_83 ;
if ( F_185 ( V_457 , V_468 ) &&
( V_474 > 63 ) )
return - V_83 ;
if ( ! F_44 ( & V_457 -> V_461 ) ) {
F_46 (prop_enum, &property->enum_list, head) {
if ( V_476 -> V_474 == V_474 ) {
strncpy ( V_476 -> V_11 , V_11 , V_462 ) ;
V_476 -> V_11 [ V_462 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_476 = F_178 ( sizeof( struct V_475 ) , V_26 ) ;
if ( ! V_476 )
return - V_84 ;
strncpy ( V_476 -> V_11 , V_11 , V_462 ) ;
V_476 -> V_11 [ V_462 - 1 ] = '\0' ;
V_476 -> V_474 = V_474 ;
V_457 -> V_458 [ V_72 ] = V_474 ;
F_53 ( & V_476 -> V_42 , & V_457 -> V_461 ) ;
return 0 ;
}
void F_180 ( struct V_16 * V_17 , struct V_155 * V_457 )
{
struct V_475 * V_476 , * V_477 ;
F_75 (prop_enum, pt, &property->enum_list, head) {
F_42 ( & V_476 -> V_42 ) ;
F_58 ( V_476 ) ;
}
if ( V_457 -> V_456 )
F_58 ( V_457 -> V_458 ) ;
F_17 ( V_17 , & V_457 -> V_39 ) ;
F_42 ( & V_457 -> V_42 ) ;
F_58 ( V_457 ) ;
}
void F_56 ( struct V_18 * V_19 ,
struct V_155 * V_457 ,
T_4 V_478 )
{
int V_262 = V_19 -> V_62 -> V_262 ;
if ( V_262 == V_479 ) {
F_186 ( 1 , L_98
L_99
L_100 ,
V_19 -> type ) ;
return;
}
V_19 -> V_62 -> V_62 [ V_262 ] = V_457 ;
V_19 -> V_62 -> V_458 [ V_262 ] = V_478 ;
V_19 -> V_62 -> V_262 ++ ;
if ( V_457 -> V_265 & V_163 )
V_19 -> V_62 -> V_263 ++ ;
}
int F_187 ( struct V_18 * V_19 ,
struct V_155 * V_457 , T_4 V_264 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_62 -> V_262 ; V_1 ++ ) {
if ( V_19 -> V_62 -> V_62 [ V_1 ] == V_457 ) {
V_19 -> V_62 -> V_458 [ V_1 ] = V_264 ;
return 0 ;
}
}
return - V_83 ;
}
int F_127 ( struct V_18 * V_19 ,
struct V_155 * V_457 , T_4 * V_264 )
{
int V_1 ;
if ( F_55 ( V_457 -> V_17 , V_66 ) &&
! ( V_457 -> V_265 & V_158 ) )
return F_188 ( V_19 , V_457 , V_264 ) ;
for ( V_1 = 0 ; V_1 < V_19 -> V_62 -> V_262 ; V_1 ++ ) {
if ( V_19 -> V_62 -> V_62 [ V_1 ] == V_457 ) {
* V_264 = V_19 -> V_62 -> V_458 [ V_1 ] ;
return 0 ;
}
}
return - V_83 ;
}
int F_189 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_480 * V_267 = V_210 ;
struct V_155 * V_457 ;
int V_481 = 0 ;
int V_482 = 0 ;
int V_22 = 0 , V_1 ;
int V_221 ;
struct V_475 * V_476 ;
struct V_483 T_3 * V_484 ;
T_4 T_3 * V_485 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_457 = F_190 ( V_17 , V_267 -> V_486 ) ;
if ( ! V_457 ) {
V_22 = - V_246 ;
goto V_487;
}
if ( F_185 ( V_457 , V_185 ) ||
F_185 ( V_457 , V_468 ) ) {
F_46 (prop_enum, &property->enum_list, head)
V_481 ++ ;
}
V_482 = V_457 -> V_456 ;
strncpy ( V_267 -> V_11 , V_457 -> V_11 , V_462 ) ;
V_267 -> V_11 [ V_462 - 1 ] = 0 ;
V_267 -> V_265 = V_457 -> V_265 ;
if ( ( V_267 -> V_488 >= V_482 ) && V_482 ) {
V_485 = ( T_4 T_3 * ) ( unsigned long ) V_267 -> V_485 ;
for ( V_1 = 0 ; V_1 < V_482 ; V_1 ++ ) {
if ( F_131 ( V_485 + V_1 , & V_457 -> V_458 [ V_1 ] , sizeof( T_4 ) ) ) {
V_22 = - V_230 ;
goto V_487;
}
}
}
V_267 -> V_488 = V_482 ;
if ( F_185 ( V_457 , V_185 ) ||
F_185 ( V_457 , V_468 ) ) {
if ( ( V_267 -> V_489 >= V_481 ) && V_481 ) {
V_221 = 0 ;
V_484 = (struct V_483 T_3 * ) ( unsigned long ) V_267 -> V_490 ;
F_46 (prop_enum, &property->enum_list, head) {
if ( F_131 ( & V_484 [ V_221 ] . V_474 , & V_476 -> V_474 , sizeof( T_4 ) ) ) {
V_22 = - V_230 ;
goto V_487;
}
if ( F_131 ( & V_484 [ V_221 ] . V_11 ,
& V_476 -> V_11 , V_462 ) ) {
V_22 = - V_230 ;
goto V_487;
}
V_221 ++ ;
}
}
V_267 -> V_489 = V_481 ;
}
if ( F_185 ( V_457 , V_157 ) )
V_267 -> V_489 = 0 ;
V_487:
F_50 ( V_17 ) ;
return V_22 ;
}
struct V_491 *
F_191 ( struct V_16 * V_17 , T_7 V_492 ,
const void * V_210 )
{
struct V_491 * V_493 ;
int V_22 ;
if ( ! V_492 )
return F_169 ( - V_83 ) ;
V_493 = F_178 ( sizeof( struct V_491 ) + V_492 , V_26 ) ;
if ( ! V_493 )
return F_169 ( - V_84 ) ;
F_25 ( & V_493 -> V_494 ) ;
V_493 -> V_492 = V_492 ;
V_493 -> V_17 = V_17 ;
if ( V_210 )
memcpy ( V_493 -> V_210 , V_210 , V_492 ) ;
F_11 ( & V_17 -> V_23 . V_495 ) ;
V_22 = F_14 ( V_17 , & V_493 -> V_39 , V_31 ) ;
if ( V_22 ) {
F_58 ( V_493 ) ;
F_13 ( & V_17 -> V_23 . V_495 ) ;
return F_169 ( - V_83 ) ;
}
F_24 ( & V_493 -> V_37 ) ;
F_53 ( & V_493 -> V_496 ,
& V_17 -> V_23 . V_497 ) ;
F_13 ( & V_17 -> V_23 . V_495 ) ;
return V_493 ;
}
static void F_192 ( struct V_44 * V_44 )
{
struct V_491 * V_493 =
F_29 ( V_44 , struct V_491 , V_37 ) ;
F_22 ( ! F_193 ( & V_493 -> V_17 -> V_23 . V_495 ) ) ;
F_42 ( & V_493 -> V_496 ) ;
F_42 ( & V_493 -> V_494 ) ;
F_17 ( V_493 -> V_17 , & V_493 -> V_39 ) ;
F_58 ( V_493 ) ;
}
void F_194 ( struct V_491 * V_493 )
{
struct V_16 * V_17 ;
if ( ! V_493 )
return;
V_17 = V_493 -> V_17 ;
F_35 ( L_101 , V_493 , V_493 -> V_39 . V_27 , F_36 ( & V_493 -> V_37 . V_37 ) ) ;
if ( F_195 ( & V_493 -> V_37 , F_192 ,
& V_17 -> V_23 . V_495 ) )
F_13 ( & V_17 -> V_23 . V_495 ) ;
else
F_196 ( & V_17 -> V_23 . V_495 ) ;
}
static void F_197 ( struct V_491 * V_493 )
{
if ( ! V_493 )
return;
F_35 ( L_101 , V_493 , V_493 -> V_39 . V_27 , F_36 ( & V_493 -> V_37 . V_37 ) ) ;
F_37 ( & V_493 -> V_37 , F_192 ) ;
}
void F_198 ( struct V_16 * V_17 ,
struct V_211 * V_212 )
{
struct V_491 * V_493 , * V_498 ;
F_11 ( & V_17 -> V_23 . V_495 ) ;
F_75 (blob, bt, &file_priv->blobs, head_file) {
F_171 ( & V_493 -> V_494 ) ;
F_197 ( V_493 ) ;
}
F_13 ( & V_17 -> V_23 . V_495 ) ;
}
struct V_491 * F_199 ( struct V_491 * V_493 )
{
F_35 ( L_101 , V_493 , V_493 -> V_39 . V_27 , F_36 ( & V_493 -> V_37 . V_37 ) ) ;
F_39 ( & V_493 -> V_37 ) ;
return V_493 ;
}
static struct V_491 * F_200 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_18 * V_19 = NULL ;
struct V_491 * V_493 ;
F_22 ( ! F_193 ( & V_17 -> V_23 . V_495 ) ) ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_19 = F_20 ( & V_17 -> V_23 . V_25 , V_27 ) ;
if ( ! V_19 || ( V_19 -> type != V_31 ) || ( V_19 -> V_27 != V_27 ) )
V_493 = NULL ;
else
V_493 = F_201 ( V_19 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_493 ;
}
struct V_491 * F_202 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_491 * V_493 ;
F_11 ( & V_17 -> V_23 . V_495 ) ;
V_493 = F_200 ( V_17 , V_27 ) ;
if ( V_493 ) {
if ( ! F_33 ( & V_493 -> V_37 ) )
V_493 = NULL ;
}
F_13 ( & V_17 -> V_23 . V_495 ) ;
return V_493 ;
}
static int F_203 ( struct V_16 * V_17 ,
struct V_491 * * V_499 ,
T_7 V_492 ,
const void * V_210 ,
struct V_18 * V_500 ,
struct V_155 * V_501 )
{
struct V_491 * V_502 = NULL ;
struct V_491 * V_503 = NULL ;
int V_22 ;
F_22 ( V_499 == NULL ) ;
V_503 = * V_499 ;
if ( V_492 && V_210 ) {
V_502 = F_191 ( V_17 , V_492 , V_210 ) ;
if ( F_155 ( V_502 ) )
return F_156 ( V_502 ) ;
}
if ( V_500 ) {
V_22 = F_187 ( V_500 ,
V_501 ,
V_502 ?
V_502 -> V_39 . V_27 : 0 ) ;
if ( V_22 != 0 )
goto V_504;
}
if ( V_503 )
F_194 ( V_503 ) ;
* V_499 = V_502 ;
return 0 ;
V_504:
F_194 ( V_502 ) ;
return V_22 ;
}
int F_204 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_505 * V_267 = V_210 ;
struct V_491 * V_493 ;
int V_22 = 0 ;
void T_3 * V_506 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
F_45 ( V_17 ) ;
F_11 ( & V_17 -> V_23 . V_495 ) ;
V_493 = F_200 ( V_17 , V_267 -> V_507 ) ;
if ( ! V_493 ) {
V_22 = - V_246 ;
goto V_487;
}
if ( V_267 -> V_492 == V_493 -> V_492 ) {
V_506 = ( void T_3 * ) ( unsigned long ) V_267 -> V_210 ;
if ( F_131 ( V_506 , V_493 -> V_210 , V_493 -> V_492 ) ) {
V_22 = - V_230 ;
goto V_487;
}
}
V_267 -> V_492 = V_493 -> V_492 ;
V_487:
F_13 ( & V_17 -> V_23 . V_495 ) ;
F_50 ( V_17 ) ;
return V_22 ;
}
int F_205 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_508 * V_267 = V_210 ;
struct V_491 * V_493 ;
void T_3 * V_506 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
V_493 = F_191 ( V_17 , V_267 -> V_492 , NULL ) ;
if ( F_155 ( V_493 ) )
return F_156 ( V_493 ) ;
V_506 = ( void T_3 * ) ( unsigned long ) V_267 -> V_210 ;
if ( F_176 ( V_493 -> V_210 , V_506 , V_267 -> V_492 ) ) {
V_22 = - V_230 ;
goto V_509;
}
F_11 ( & V_17 -> V_23 . V_495 ) ;
V_267 -> V_507 = V_493 -> V_39 . V_27 ;
F_53 ( & V_212 -> V_510 , & V_493 -> V_494 ) ;
F_13 ( & V_17 -> V_23 . V_495 ) ;
return 0 ;
V_509:
F_194 ( V_493 ) ;
return V_22 ;
}
int F_206 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_511 * V_267 = V_210 ;
struct V_491 * V_493 = NULL , * V_498 ;
bool V_434 = false ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
F_11 ( & V_17 -> V_23 . V_495 ) ;
V_493 = F_200 ( V_17 , V_267 -> V_507 ) ;
if ( ! V_493 ) {
V_22 = - V_246 ;
goto V_512;
}
F_46 (bt, &file_priv->blobs, head_file) {
if ( V_498 == V_493 ) {
V_434 = true ;
break;
}
}
if ( ! V_434 ) {
V_22 = - V_513 ;
goto V_512;
}
F_171 ( & V_493 -> V_494 ) ;
F_197 ( V_493 ) ;
F_13 ( & V_17 -> V_23 . V_495 ) ;
return 0 ;
V_512:
F_13 ( & V_17 -> V_23 . V_495 ) ;
return V_22 ;
}
int F_207 ( struct V_74 * V_75 ,
const char * V_514 )
{
struct V_16 * V_17 = V_75 -> V_17 ;
int V_22 ;
V_22 = F_203 ( V_17 ,
& V_75 -> V_515 ,
strlen ( V_514 ) + 1 ,
V_514 ,
& V_75 -> V_39 ,
V_17 -> V_23 . V_160 ) ;
return V_22 ;
}
int F_208 ( struct V_74 * V_75 )
{
struct V_16 * V_17 = V_75 -> V_17 ;
char V_516 [ 256 ] ;
int V_22 ;
if ( ! V_75 -> V_517 ) {
V_22 = F_203 ( V_17 ,
& V_75 -> V_518 ,
0 ,
NULL ,
& V_75 -> V_39 ,
V_17 -> V_23 . V_161 ) ;
return V_22 ;
}
snprintf ( V_516 , 256 , L_102 ,
V_75 -> V_121 -> V_27 , V_75 -> V_519 ,
V_75 -> V_520 , V_75 -> V_521 ,
V_75 -> V_522 , V_75 -> V_523 ,
V_75 -> V_524 , V_75 -> V_525 ) ;
V_22 = F_203 ( V_17 ,
& V_75 -> V_518 ,
strlen ( V_516 ) + 1 ,
V_516 ,
& V_75 -> V_39 ,
V_17 -> V_23 . V_161 ) ;
return V_22 ;
}
int F_209 ( struct V_74 * V_75 ,
const struct V_526 * V_526 )
{
struct V_16 * V_17 = V_75 -> V_17 ;
T_7 V_527 = 0 ;
int V_22 ;
if ( V_75 -> V_528 )
return 0 ;
if ( V_526 )
V_527 = V_529 * ( 1 + V_526 -> V_530 ) ;
V_22 = F_203 ( V_17 ,
& V_75 -> V_111 ,
V_527 ,
V_526 ,
& V_75 -> V_39 ,
V_17 -> V_23 . V_116 ) ;
return V_22 ;
}
bool F_210 ( struct V_155 * V_457 ,
T_4 V_474 , struct V_18 * * V_531 )
{
int V_1 ;
if ( V_457 -> V_265 & V_158 )
return false ;
* V_531 = NULL ;
if ( F_185 ( V_457 , V_471 ) ) {
if ( V_474 < V_457 -> V_458 [ 0 ] || V_474 > V_457 -> V_458 [ 1 ] )
return false ;
return true ;
} else if ( F_185 ( V_457 , V_472 ) ) {
T_6 V_532 = F_211 ( V_474 ) ;
if ( V_532 < F_211 ( V_457 -> V_458 [ 0 ] ) ||
V_532 > F_211 ( V_457 -> V_458 [ 1 ] ) )
return false ;
return true ;
} else if ( F_185 ( V_457 , V_468 ) ) {
T_4 V_533 = 0 ;
for ( V_1 = 0 ; V_1 < V_457 -> V_456 ; V_1 ++ )
V_533 |= ( 1ULL << V_457 -> V_458 [ V_1 ] ) ;
return ! ( V_474 & ~ V_533 ) ;
} else if ( F_185 ( V_457 , V_157 ) ) {
struct V_491 * V_493 ;
if ( V_474 == 0 )
return true ;
V_493 = F_202 ( V_457 -> V_17 , V_474 ) ;
if ( V_493 ) {
* V_531 = & V_493 -> V_39 ;
return true ;
} else {
return false ;
}
} else if ( F_185 ( V_457 , V_473 ) ) {
if ( V_474 == 0 )
return true ;
if ( V_457 -> V_458 [ 0 ] == V_30 ) {
struct V_32 * V_33 ;
V_33 = F_32 ( V_457 -> V_17 , V_474 ) ;
if ( V_33 ) {
* V_531 = & V_33 -> V_39 ;
return true ;
} else {
return false ;
}
} else {
return F_19 ( V_457 -> V_17 , V_474 , V_457 -> V_458 [ 0 ] ) != NULL ;
}
}
for ( V_1 = 0 ; V_1 < V_457 -> V_456 ; V_1 ++ )
if ( V_457 -> V_458 [ V_1 ] == V_474 )
return true ;
return false ;
}
void F_212 ( struct V_155 * V_457 ,
struct V_18 * V_531 )
{
if ( ! V_531 )
return;
if ( F_185 ( V_457 , V_473 ) ) {
if ( V_457 -> V_458 [ 0 ] == V_30 )
F_34 ( F_31 ( V_531 ) ) ;
} else if ( F_185 ( V_457 , V_157 ) )
F_194 ( F_201 ( V_531 ) ) ;
}
int F_213 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_534 * V_535 = V_210 ;
struct V_536 V_537 = {
. V_474 = V_535 -> V_474 ,
. V_486 = V_535 -> V_486 ,
. V_538 = V_535 -> V_224 ,
. V_20 = V_105
} ;
return F_214 ( V_17 , & V_537 , V_212 ) ;
}
static int F_215 ( struct V_18 * V_19 ,
struct V_155 * V_457 ,
T_4 V_474 )
{
int V_22 = - V_83 ;
struct V_74 * V_75 = F_216 ( V_19 ) ;
if ( V_457 == V_75 -> V_17 -> V_23 . V_117 ) {
if ( V_75 -> V_35 -> V_539 )
(* V_75 -> V_35 -> V_539 )( V_75 , ( int ) V_474 ) ;
V_22 = 0 ;
} else if ( V_75 -> V_35 -> V_540 )
V_22 = V_75 -> V_35 -> V_540 ( V_75 , V_457 , V_474 ) ;
if ( ! V_22 )
F_187 ( & V_75 -> V_39 , V_457 , V_474 ) ;
return V_22 ;
}
static int F_217 ( struct V_18 * V_19 ,
struct V_155 * V_457 ,
T_4 V_474 )
{
int V_22 = - V_83 ;
struct V_46 * V_47 = F_218 ( V_19 ) ;
if ( V_47 -> V_35 -> V_540 )
V_22 = V_47 -> V_35 -> V_540 ( V_47 , V_457 , V_474 ) ;
if ( ! V_22 )
F_187 ( V_19 , V_457 , V_474 ) ;
return V_22 ;
}
int F_219 ( struct V_48 * V_49 ,
struct V_155 * V_457 ,
T_4 V_474 )
{
int V_22 = - V_83 ;
struct V_18 * V_19 = & V_49 -> V_39 ;
if ( V_49 -> V_35 -> V_540 )
V_22 = V_49 -> V_35 -> V_540 ( V_49 , V_457 , V_474 ) ;
if ( ! V_22 )
F_187 ( V_19 , V_457 , V_474 ) ;
return V_22 ;
}
int F_220 ( struct V_16 * V_17 , void * V_210 ,
struct V_211 * V_212 )
{
struct V_541 * V_542 = V_210 ;
struct V_18 * V_19 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_19 = F_21 ( V_17 , V_542 -> V_538 , V_542 -> V_20 ) ;
if ( ! V_19 ) {
V_22 = - V_246 ;
goto V_40;
}
if ( ! V_19 -> V_62 ) {
V_22 = - V_83 ;
goto V_40;
}
V_22 = F_126 ( V_19 , V_212 -> V_257 ,
( T_1 T_3 * ) ( unsigned long ) ( V_542 -> V_285 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_542 -> V_286 ) ,
& V_542 -> V_287 ) ;
V_40:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_214 ( struct V_16 * V_17 , void * V_210 ,
struct V_211 * V_212 )
{
struct V_536 * V_542 = V_210 ;
struct V_18 * V_543 ;
struct V_18 * V_544 ;
struct V_155 * V_457 ;
int V_1 , V_22 = - V_83 ;
struct V_18 * V_531 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_543 = F_21 ( V_17 , V_542 -> V_538 , V_542 -> V_20 ) ;
if ( ! V_543 ) {
V_22 = - V_246 ;
goto V_40;
}
if ( ! V_543 -> V_62 )
goto V_40;
for ( V_1 = 0 ; V_1 < V_543 -> V_62 -> V_262 ; V_1 ++ )
if ( V_543 -> V_62 -> V_62 [ V_1 ] -> V_39 . V_27 == V_542 -> V_486 )
break;
if ( V_1 == V_543 -> V_62 -> V_262 )
goto V_40;
V_544 = F_21 ( V_17 , V_542 -> V_486 ,
V_460 ) ;
if ( ! V_544 ) {
V_22 = - V_246 ;
goto V_40;
}
V_457 = F_221 ( V_544 ) ;
if ( ! F_210 ( V_457 , V_542 -> V_474 , & V_531 ) )
goto V_40;
switch ( V_543 -> type ) {
case V_105 :
V_22 = F_215 ( V_543 , V_457 ,
V_542 -> V_474 ) ;
break;
case V_61 :
V_22 = F_217 ( V_543 , V_457 , V_542 -> V_474 ) ;
break;
case V_135 :
V_22 = F_219 ( F_222 ( V_543 ) ,
V_457 , V_542 -> V_474 ) ;
break;
}
F_212 ( V_457 , V_531 ) ;
V_40:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_223 ( struct V_74 * V_75 ,
struct V_124 * V_125 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_274 ; V_1 ++ ) {
if ( V_75 -> V_275 [ V_1 ] == 0 ) {
V_75 -> V_275 [ V_1 ] = V_125 -> V_39 . V_27 ;
return 0 ;
}
}
return - V_84 ;
}
int F_224 ( struct V_46 * V_47 ,
int V_247 )
{
V_47 -> V_247 = V_247 ;
V_47 -> V_69 = F_110 ( V_247 , sizeof( V_545 ) * 3 ,
V_26 ) ;
if ( ! V_47 -> V_69 ) {
V_47 -> V_247 = 0 ;
return - V_84 ;
}
return 0 ;
}
int F_225 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_546 * V_547 = V_210 ;
struct V_46 * V_47 ;
void * V_548 , * V_549 , * V_550 ;
int V_527 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_47 = F_119 ( V_17 , V_547 -> V_223 ) ;
if ( ! V_47 ) {
V_22 = - V_246 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_551 == NULL ) {
V_22 = - V_453 ;
goto V_40;
}
if ( V_547 -> V_247 != V_47 -> V_247 ) {
V_22 = - V_83 ;
goto V_40;
}
V_527 = V_547 -> V_247 * ( sizeof( V_545 ) ) ;
V_548 = V_47 -> V_69 ;
if ( F_176 ( V_548 , ( void T_3 * ) ( unsigned long ) V_547 -> V_552 , V_527 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_549 = V_548 + V_527 ;
if ( F_176 ( V_549 , ( void T_3 * ) ( unsigned long ) V_547 -> V_553 , V_527 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_550 = V_549 + V_527 ;
if ( F_176 ( V_550 , ( void T_3 * ) ( unsigned long ) V_547 -> V_554 , V_527 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_47 -> V_35 -> V_551 ( V_47 , V_548 , V_549 , V_550 , 0 , V_47 -> V_247 ) ;
V_40:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_226 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_546 * V_547 = V_210 ;
struct V_46 * V_47 ;
void * V_548 , * V_549 , * V_550 ;
int V_527 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_226 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_47 = F_119 ( V_17 , V_547 -> V_223 ) ;
if ( ! V_47 ) {
V_22 = - V_246 ;
goto V_40;
}
if ( V_547 -> V_247 != V_47 -> V_247 ) {
V_22 = - V_83 ;
goto V_40;
}
V_527 = V_547 -> V_247 * ( sizeof( V_545 ) ) ;
V_548 = V_47 -> V_69 ;
if ( F_131 ( ( void T_3 * ) ( unsigned long ) V_547 -> V_552 , V_548 , V_527 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_549 = V_548 + V_527 ;
if ( F_131 ( ( void T_3 * ) ( unsigned long ) V_547 -> V_553 , V_549 , V_527 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_550 = V_549 + V_527 ;
if ( F_131 ( ( void T_3 * ) ( unsigned long ) V_547 -> V_554 , V_550 , V_527 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_40:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_227 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_555 * V_556 = V_210 ;
struct V_46 * V_47 ;
struct V_32 * V_33 = NULL ;
struct V_557 * V_558 = NULL ;
unsigned long V_265 ;
int V_22 = - V_83 ;
if ( V_556 -> V_265 & ~ V_559 ||
V_556 -> V_560 != 0 )
return - V_83 ;
if ( ( V_556 -> V_265 & V_561 ) && ! V_17 -> V_23 . V_562 )
return - V_83 ;
V_47 = F_119 ( V_17 , V_556 -> V_223 ) ;
if ( ! V_47 )
return - V_246 ;
F_120 ( V_47 , V_47 -> V_52 ) ;
if ( V_47 -> V_52 -> V_33 == NULL ) {
V_22 = - V_563 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_556 == NULL )
goto V_40;
V_33 = F_32 ( V_17 , V_556 -> V_222 ) ;
if ( ! V_33 ) {
V_22 = - V_246 ;
goto V_40;
}
V_22 = F_147 ( V_47 , V_47 -> V_248 , V_47 -> V_250 , & V_47 -> V_77 , V_33 ) ;
if ( V_22 )
goto V_40;
if ( V_47 -> V_52 -> V_33 -> V_313 != V_33 -> V_313 ) {
F_69 ( L_103 ) ;
V_22 = - V_83 ;
goto V_40;
}
if ( V_556 -> V_265 & V_564 ) {
V_22 = - V_84 ;
F_228 ( & V_17 -> V_565 , V_265 ) ;
if ( V_212 -> V_566 < sizeof( V_558 -> V_567 ) ) {
F_229 ( & V_17 -> V_565 , V_265 ) ;
goto V_40;
}
V_212 -> V_566 -= sizeof( V_558 -> V_567 ) ;
F_229 ( & V_17 -> V_565 , V_265 ) ;
V_558 = F_178 ( sizeof( * V_558 ) , V_26 ) ;
if ( V_558 == NULL ) {
F_228 ( & V_17 -> V_565 , V_265 ) ;
V_212 -> V_566 += sizeof( V_558 -> V_567 ) ;
F_229 ( & V_17 -> V_565 , V_265 ) ;
goto V_40;
}
V_558 -> V_567 . V_39 . type = V_568 ;
V_558 -> V_567 . V_39 . V_492 = sizeof( V_558 -> V_567 ) ;
V_558 -> V_567 . V_569 = V_556 -> V_569 ;
V_558 -> V_39 . V_567 = & V_558 -> V_567 . V_39 ;
V_558 -> V_39 . V_212 = V_212 ;
V_558 -> V_39 . V_45 =
( void ( * ) ( struct V_570 * ) ) F_58 ;
}
V_47 -> V_52 -> V_153 = V_47 -> V_52 -> V_33 ;
V_22 = V_47 -> V_35 -> V_556 ( V_47 , V_33 , V_558 , V_556 -> V_265 ) ;
if ( V_22 ) {
if ( V_556 -> V_265 & V_564 ) {
F_228 ( & V_17 -> V_565 , V_265 ) ;
V_212 -> V_566 += sizeof( V_558 -> V_567 ) ;
F_229 ( & V_17 -> V_565 , V_265 ) ;
F_58 ( V_558 ) ;
}
V_47 -> V_52 -> V_153 = NULL ;
} else {
F_22 ( V_47 -> V_52 -> V_33 != V_33 ) ;
V_33 = NULL ;
}
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
if ( V_47 -> V_52 -> V_153 )
F_34 ( V_47 -> V_52 -> V_153 ) ;
V_47 -> V_52 -> V_153 = NULL ;
F_122 ( V_47 ) ;
return V_22 ;
}
void F_230 ( struct V_16 * V_17 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_124 * V_125 ;
struct V_74 * V_75 ;
F_46 (plane, &dev->mode_config.plane_list, head)
if ( V_49 -> V_35 -> V_571 )
V_49 -> V_35 -> V_571 ( V_49 ) ;
F_46 (crtc, &dev->mode_config.crtc_list, head)
if ( V_47 -> V_35 -> V_571 )
V_47 -> V_35 -> V_571 ( V_47 ) ;
F_46 (encoder, &dev->mode_config.encoder_list, head)
if ( V_125 -> V_35 -> V_571 )
V_125 -> V_35 -> V_571 ( V_125 ) ;
F_46 (connector, &dev->mode_config.connector_list, head)
if ( V_75 -> V_35 -> V_571 )
V_75 -> V_35 -> V_571 ( V_75 ) ;
}
int F_231 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_572 * args = V_210 ;
T_2 V_424 , V_573 , V_527 ;
if ( ! V_17 -> V_574 -> V_575 )
return - V_453 ;
if ( ! args -> V_315 || ! args -> V_316 || ! args -> V_356 )
return - V_83 ;
V_424 = F_232 ( args -> V_356 , 8 ) ;
if ( ! V_424 || V_424 > 0xffffffffU / args -> V_315 )
return - V_83 ;
V_573 = V_424 * args -> V_315 ;
if ( args -> V_316 > 0xffffffffU / V_573 )
return - V_83 ;
V_527 = args -> V_316 * V_573 ;
if ( F_233 ( V_527 ) == 0 )
return - V_83 ;
args -> V_342 = 0 ;
args -> V_368 = 0 ;
args -> V_527 = 0 ;
return V_17 -> V_574 -> V_575 ( V_212 , V_17 , args ) ;
}
int F_234 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_576 * args = V_210 ;
if ( ! V_17 -> V_574 -> V_577 )
return - V_453 ;
return V_17 -> V_574 -> V_577 ( V_212 , V_17 , args -> V_342 , & args -> V_578 ) ;
}
int F_235 ( struct V_16 * V_17 ,
void * V_210 , struct V_211 * V_212 )
{
struct V_579 * args = V_210 ;
if ( ! V_17 -> V_574 -> V_580 )
return - V_453 ;
return V_17 -> V_574 -> V_580 ( V_212 , V_17 , args -> V_342 ) ;
}
void F_236 ( T_1 V_13 , unsigned int * V_357 ,
int * V_356 )
{
switch ( V_13 ) {
case V_359 :
case V_369 :
case V_370 :
* V_357 = 8 ;
* V_356 = 8 ;
break;
case V_360 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
* V_357 = 15 ;
* V_356 = 16 ;
break;
case V_361 :
case V_386 :
* V_357 = 16 ;
* V_356 = 16 ;
break;
case V_362 :
case V_387 :
* V_357 = 24 ;
* V_356 = 24 ;
break;
case V_363 :
case V_388 :
case V_389 :
case V_390 :
* V_357 = 24 ;
* V_356 = 32 ;
break;
case V_364 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
* V_357 = 30 ;
* V_356 = 32 ;
break;
case V_339 :
case V_391 :
case V_392 :
case V_393 :
* V_357 = 32 ;
* V_356 = 32 ;
break;
default:
F_69 ( L_104 ,
F_9 ( V_13 ) ) ;
* V_357 = 0 ;
* V_356 = 0 ;
break;
}
}
int F_167 ( T_1 V_13 )
{
switch ( V_13 ) {
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
return 3 ;
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
return 2 ;
default:
return 1 ;
}
}
int F_168 ( T_1 V_13 , int V_49 )
{
unsigned int V_357 ;
int V_356 ;
if ( V_49 >= F_167 ( V_13 ) )
return 0 ;
switch ( V_13 ) {
case V_401 :
case V_402 :
case V_403 :
case V_404 :
return 2 ;
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
return V_49 ? 2 : 1 ;
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
return 1 ;
default:
F_236 ( V_13 , & V_357 , & V_356 ) ;
return V_356 >> 3 ;
}
}
int F_165 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_414 :
case V_415 :
case V_412 :
case V_413 :
return 4 ;
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_418 :
case V_419 :
case V_416 :
case V_417 :
return 2 ;
default:
return 1 ;
}
}
int F_166 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_412 :
case V_413 :
return 4 ;
case V_416 :
case V_417 :
case V_406 :
case V_407 :
return 2 ;
default:
return 1 ;
}
}
unsigned int F_237 ( unsigned int V_581 ,
unsigned int V_582 )
{
if ( V_581 & ~ V_582 ) {
V_581 ^= F_238 ( V_583 ) | F_238 ( V_584 ) ;
V_581 = ( V_581 & ~ 0xf ) | F_238 ( ( F_239 ( V_581 & 0xf ) + 1 ) % 4 ) ;
}
return V_581 ;
}
void F_240 ( struct V_16 * V_17 )
{
F_241 ( & V_17 -> V_23 . V_60 ) ;
F_52 ( & V_17 -> V_23 . V_123 ) ;
F_241 ( & V_17 -> V_23 . V_24 ) ;
F_241 ( & V_17 -> V_23 . V_36 ) ;
F_241 ( & V_17 -> V_23 . V_495 ) ;
F_25 ( & V_17 -> V_23 . V_43 ) ;
F_25 ( & V_17 -> V_23 . V_63 ) ;
F_25 ( & V_17 -> V_23 . V_113 ) ;
F_25 ( & V_17 -> V_23 . V_130 ) ;
F_25 ( & V_17 -> V_23 . V_463 ) ;
F_25 ( & V_17 -> V_23 . V_497 ) ;
F_25 ( & V_17 -> V_23 . V_137 ) ;
F_242 ( & V_17 -> V_23 . V_25 ) ;
F_242 ( & V_17 -> V_23 . V_585 ) ;
F_45 ( V_17 ) ;
F_95 ( V_17 ) ;
F_50 ( V_17 ) ;
V_17 -> V_23 . V_41 = 0 ;
V_17 -> V_23 . V_114 = 0 ;
V_17 -> V_23 . V_64 = 0 ;
V_17 -> V_23 . V_131 = 0 ;
V_17 -> V_23 . V_140 = 0 ;
V_17 -> V_23 . V_138 = 0 ;
}
void F_243 ( struct V_16 * V_17 )
{
struct V_74 * V_75 , * V_586 ;
struct V_46 * V_47 , * V_587 ;
struct V_124 * V_125 , * V_588 ;
struct V_32 * V_33 , * V_589 ;
struct V_155 * V_457 , * V_477 ;
struct V_491 * V_493 , * V_498 ;
struct V_48 * V_49 , * V_590 ;
F_75 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_125 -> V_35 -> V_45 ( V_125 ) ;
}
F_75 (connector, ot,
&dev->mode_config.connector_list, head) {
V_75 -> V_35 -> V_45 ( V_75 ) ;
}
F_75 (property, pt, &dev->mode_config.property_list,
head) {
F_180 ( V_17 , V_457 ) ;
}
F_75 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_194 ( V_493 ) ;
}
F_22 ( ! F_44 ( & V_17 -> V_23 . V_43 ) ) ;
F_75 (fb, fbt, &dev->mode_config.fb_list, head) {
F_43 ( V_33 ) ;
}
F_75 (plane, plt, &dev->mode_config.plane_list,
head) {
V_49 -> V_35 -> V_45 ( V_49 ) ;
}
F_75 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_47 -> V_35 -> V_45 ( V_47 ) ;
}
F_244 ( & V_17 -> V_23 . V_585 ) ;
F_244 ( & V_17 -> V_23 . V_25 ) ;
F_59 ( & V_17 -> V_23 . V_123 ) ;
}
struct V_155 * F_245 ( struct V_16 * V_17 ,
unsigned int V_582 )
{
static const struct V_464 V_465 [] = {
{ V_591 , L_105 } ,
{ V_592 , L_106 } ,
{ V_593 , L_107 } ,
{ V_594 , L_108 } ,
{ V_583 , L_109 } ,
{ V_584 , L_110 } ,
} ;
return F_181 ( V_17 , 0 , L_111 ,
V_465 , F_2 ( V_465 ) ,
V_582 ) ;
}
static void F_246 ( struct V_44 * V_44 )
{
struct V_595 * V_596 = F_29 ( V_44 , struct V_595 , V_37 ) ;
struct V_16 * V_17 = V_596 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_585 , V_596 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
F_58 ( V_596 ) ;
}
void F_74 ( struct V_16 * V_17 ,
struct V_595 * V_596 )
{
F_37 ( & V_596 -> V_37 , F_246 ) ;
}
struct V_595 * F_247 ( struct V_16 * V_17 ,
char V_597 [ 8 ] )
{
struct V_595 * V_596 ;
int V_27 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_248 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_596 -> V_598 , V_597 , 8 ) ) {
if ( ! F_33 ( & V_596 -> V_37 ) )
V_596 = NULL ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_596 ;
}
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return NULL ;
}
struct V_595 * F_249 ( struct V_16 * V_17 ,
char V_597 [ 8 ] )
{
struct V_595 * V_596 ;
int V_22 ;
V_596 = F_178 ( sizeof( * V_596 ) , V_26 ) ;
if ( ! V_596 )
return F_169 ( - V_84 ) ;
F_24 ( & V_596 -> V_37 ) ;
memcpy ( V_596 -> V_598 , V_597 , 8 ) ;
V_596 -> V_17 = V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_22 = F_12 ( & V_17 -> V_23 . V_585 , V_596 , 1 , 0 , V_26 ) ;
if ( V_22 >= 0 ) {
V_596 -> V_27 = V_22 ;
} else {
F_58 ( V_596 ) ;
V_596 = F_169 ( V_22 ) ;
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_596 ;
}
