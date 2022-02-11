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
V_46 -> V_17 = V_17 ;
V_46 -> V_34 = V_34 ;
V_46 -> V_56 = false ;
F_52 ( & V_46 -> V_57 ) ;
V_22 = F_14 ( V_17 , & V_46 -> V_38 , V_58 ) ;
if ( V_22 )
return V_22 ;
V_46 -> V_38 . V_59 = & V_46 -> V_59 ;
F_53 ( & V_46 -> V_41 , & V_55 -> V_60 ) ;
V_55 -> V_61 ++ ;
V_46 -> V_51 = V_51 ;
V_46 -> V_52 = V_52 ;
if ( V_51 )
V_51 -> V_62 = 1 << F_54 ( V_46 ) ;
if ( V_52 )
V_52 -> V_62 = 1 << F_54 ( V_46 ) ;
if ( F_55 ( V_17 , V_63 ) ) {
F_56 ( & V_46 -> V_38 , V_55 -> V_64 , 0 ) ;
}
return 0 ;
}
void F_57 ( struct V_45 * V_46 )
{
struct V_16 * V_17 = V_46 -> V_17 ;
F_58 ( V_46 -> V_65 ) ;
V_46 -> V_65 = NULL ;
F_59 ( & V_46 -> V_57 ) ;
F_17 ( V_17 , & V_46 -> V_38 ) ;
F_42 ( & V_46 -> V_41 ) ;
V_17 -> V_23 . V_61 -- ;
F_22 ( V_46 -> V_66 && ! V_46 -> V_34 -> V_67 ) ;
if ( V_46 -> V_66 && V_46 -> V_34 -> V_67 )
V_46 -> V_34 -> V_67 ( V_46 , V_46 -> V_66 ) ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
}
unsigned int F_54 ( struct V_45 * V_46 )
{
unsigned int V_68 = 0 ;
struct V_45 * V_69 ;
F_46 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_69 == V_46 )
return V_68 ;
V_68 ++ ;
}
F_60 () ;
}
static void F_61 ( struct V_70 * V_71 ,
struct V_72 * V_73 )
{
F_42 ( & V_73 -> V_41 ) ;
F_62 ( V_71 -> V_17 , V_73 ) ;
}
int F_63 ( struct V_74 * V_75 ,
const T_2 * V_76 ,
unsigned int V_77 )
{
T_2 * V_78 = NULL ;
if ( ! V_76 && V_77 )
return - V_79 ;
if ( V_76 && V_77 ) {
V_78 = F_64 ( V_76 , sizeof( * V_76 ) * V_77 ,
V_26 ) ;
if ( ! V_78 )
return - V_80 ;
}
F_58 ( V_75 -> V_81 ) ;
V_75 -> V_81 = V_78 ;
V_75 -> V_82 = V_77 ;
return 0 ;
}
static void F_65 ( struct V_70 * V_71 )
{
struct V_83 * V_73 = & V_71 -> V_84 ;
char * V_85 = NULL ;
if ( F_66 ( V_71 -> V_11 , & V_85 ) )
return;
if ( ! F_67 ( V_85 ,
V_71 ,
V_73 ) )
return;
if ( V_73 -> V_86 ) {
const char * V_87 ;
switch ( V_73 -> V_86 ) {
case V_88 :
V_87 = L_9 ;
break;
case V_89 :
V_87 = L_10 ;
break;
default:
case V_90 :
V_87 = L_11 ;
break;
}
F_68 ( L_12 , V_71 -> V_11 , V_87 ) ;
V_71 -> V_86 = V_73 -> V_86 ;
}
F_69 ( L_13 ,
V_71 -> V_11 ,
V_73 -> V_91 , V_73 -> V_92 ,
V_73 -> V_93 ? V_73 -> V_94 : 60 ,
V_73 -> V_95 ? L_14 : L_15 ,
V_73 -> V_96 ? L_16 : L_15 ,
V_73 -> V_97 ? L_17 : L_15 ) ;
}
int F_70 ( struct V_16 * V_17 ,
struct V_70 * V_71 ,
const struct V_98 * V_34 ,
int V_99 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
int V_22 ;
struct V_3 * V_100 =
& V_2 [ V_99 ] . V_3 ;
F_45 ( V_17 ) ;
V_22 = F_10 ( V_17 , & V_71 -> V_38 , V_101 , false ) ;
if ( V_22 )
goto V_102;
V_71 -> V_38 . V_59 = & V_71 -> V_59 ;
V_71 -> V_17 = V_17 ;
V_71 -> V_34 = V_34 ;
V_71 -> V_99 = V_99 ;
V_71 -> V_103 =
F_71 ( V_100 , 1 , 0 , V_26 ) ;
if ( V_71 -> V_103 < 0 ) {
V_22 = V_71 -> V_103 ;
goto V_104;
}
V_71 -> V_11 =
F_72 ( V_26 , L_18 ,
V_2 [ V_99 ] . V_11 ,
V_71 -> V_103 ) ;
if ( ! V_71 -> V_11 ) {
V_22 = - V_80 ;
goto V_104;
}
F_25 ( & V_71 -> V_105 ) ;
F_25 ( & V_71 -> V_106 ) ;
V_71 -> V_107 = NULL ;
V_71 -> V_5 = V_108 ;
F_65 ( V_71 ) ;
F_53 ( & V_71 -> V_41 , & V_55 -> V_109 ) ;
V_55 -> V_110 ++ ;
if ( V_99 != V_111 )
F_56 ( & V_71 -> V_38 ,
V_55 -> V_112 ,
0 ) ;
F_56 ( & V_71 -> V_38 ,
V_55 -> V_113 , 0 ) ;
if ( F_55 ( V_17 , V_63 ) ) {
F_56 ( & V_71 -> V_38 , V_55 -> V_114 , 0 ) ;
}
V_71 -> V_115 = NULL ;
V_104:
if ( V_22 )
F_17 ( V_17 , & V_71 -> V_38 ) ;
V_102:
F_50 ( V_17 ) ;
return V_22 ;
}
void F_73 ( struct V_70 * V_71 )
{
struct V_16 * V_17 = V_71 -> V_17 ;
struct V_72 * V_73 , * V_116 ;
if ( V_71 -> V_117 ) {
F_74 ( V_17 , V_71 -> V_117 ) ;
V_71 -> V_117 = NULL ;
}
F_75 (mode, t, &connector->probed_modes, head)
F_61 ( V_71 , V_73 ) ;
F_75 (mode, t, &connector->modes, head)
F_61 ( V_71 , V_73 ) ;
F_76 ( & V_2 [ V_71 -> V_99 ] . V_3 ,
V_71 -> V_103 ) ;
F_58 ( V_71 -> V_118 . V_81 ) ;
F_17 ( V_17 , & V_71 -> V_38 ) ;
F_58 ( V_71 -> V_11 ) ;
V_71 -> V_11 = NULL ;
F_42 ( & V_71 -> V_41 ) ;
V_17 -> V_23 . V_110 -- ;
F_22 ( V_71 -> V_66 && ! V_71 -> V_34 -> V_67 ) ;
if ( V_71 -> V_66 && V_71 -> V_34 -> V_67 )
V_71 -> V_34 -> V_67 ( V_71 ,
V_71 -> V_66 ) ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
}
unsigned int F_77 ( struct V_70 * V_71 )
{
unsigned int V_68 = 0 ;
struct V_70 * V_69 ;
struct V_54 * V_55 = & V_71 -> V_17 -> V_23 ;
F_22 ( ! F_78 ( & V_55 -> V_119 ) ) ;
F_46 (tmp, &connector->dev->mode_config.connector_list, head) {
if ( V_69 == V_71 )
return V_68 ;
V_68 ++ ;
}
F_60 () ;
}
int F_79 ( struct V_70 * V_71 )
{
int V_22 ;
F_15 ( V_71 -> V_17 , & V_71 -> V_38 ) ;
V_22 = F_80 ( V_71 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_81 ( V_71 ) ;
if ( V_22 ) {
F_82 ( V_71 ) ;
return V_22 ;
}
return 0 ;
}
void F_83 ( struct V_70 * V_71 )
{
F_82 ( V_71 ) ;
F_84 ( V_71 ) ;
}
void F_85 ( struct V_16 * V_17 )
{
struct V_70 * V_71 ;
F_46 (connector, &dev->mode_config.connector_list, head)
F_83 ( V_71 ) ;
}
int F_86 ( struct V_16 * V_17 ,
struct V_120 * V_121 ,
const struct V_122 * V_34 ,
int V_123 )
{
int V_22 ;
F_45 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_121 -> V_38 , V_124 ) ;
if ( V_22 )
goto V_102;
V_121 -> V_17 = V_17 ;
V_121 -> V_123 = V_123 ;
V_121 -> V_34 = V_34 ;
V_121 -> V_11 = F_72 ( V_26 , L_18 ,
V_125 [ V_123 ] . V_11 ,
V_121 -> V_38 . V_27 ) ;
if ( ! V_121 -> V_11 ) {
V_22 = - V_80 ;
goto V_104;
}
F_53 ( & V_121 -> V_41 , & V_17 -> V_23 . V_126 ) ;
V_17 -> V_23 . V_127 ++ ;
V_104:
if ( V_22 )
F_17 ( V_17 , & V_121 -> V_38 ) ;
V_102:
F_50 ( V_17 ) ;
return V_22 ;
}
void F_87 ( struct V_120 * V_121 )
{
struct V_16 * V_17 = V_121 -> V_17 ;
F_45 ( V_17 ) ;
F_17 ( V_17 , & V_121 -> V_38 ) ;
F_58 ( V_121 -> V_11 ) ;
F_42 ( & V_121 -> V_41 ) ;
V_17 -> V_23 . V_127 -- ;
F_50 ( V_17 ) ;
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
}
int F_88 ( struct V_16 * V_17 , struct V_47 * V_48 ,
unsigned long V_62 ,
const struct V_128 * V_34 ,
const T_1 * V_76 , T_1 V_129 ,
enum V_130 type )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
int V_22 ;
V_22 = F_14 ( V_17 , & V_48 -> V_38 , V_131 ) ;
if ( V_22 )
return V_22 ;
F_52 ( & V_48 -> V_57 ) ;
V_48 -> V_38 . V_59 = & V_48 -> V_59 ;
V_48 -> V_17 = V_17 ;
V_48 -> V_34 = V_34 ;
V_48 -> V_132 = F_89 ( V_129 , sizeof( T_1 ) ,
V_26 ) ;
if ( ! V_48 -> V_132 ) {
F_69 ( L_19 ) ;
F_17 ( V_17 , & V_48 -> V_38 ) ;
return - V_80 ;
}
memcpy ( V_48 -> V_132 , V_76 , V_129 * sizeof( T_1 ) ) ;
V_48 -> V_129 = V_129 ;
V_48 -> V_62 = V_62 ;
V_48 -> type = type ;
F_53 ( & V_48 -> V_41 , & V_55 -> V_133 ) ;
V_55 -> V_134 ++ ;
if ( V_48 -> type == V_135 )
V_55 -> V_136 ++ ;
F_56 ( & V_48 -> V_38 ,
V_55 -> V_137 ,
V_48 -> type ) ;
if ( F_55 ( V_17 , V_63 ) ) {
F_56 ( & V_48 -> V_38 , V_55 -> V_138 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_114 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_139 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_140 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_141 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_142 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_143 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_144 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_145 , 0 ) ;
F_56 ( & V_48 -> V_38 , V_55 -> V_146 , 0 ) ;
}
return 0 ;
}
int F_90 ( struct V_16 * V_17 , struct V_47 * V_48 ,
unsigned long V_62 ,
const struct V_128 * V_34 ,
const T_1 * V_76 , T_1 V_129 ,
bool V_147 )
{
enum V_130 type ;
type = V_147 ? V_148 : V_135 ;
return F_88 ( V_17 , V_48 , V_62 , V_34 ,
V_76 , V_129 , type ) ;
}
void F_91 ( struct V_47 * V_48 )
{
struct V_16 * V_17 = V_48 -> V_17 ;
F_45 ( V_17 ) ;
F_58 ( V_48 -> V_132 ) ;
F_17 ( V_17 , & V_48 -> V_38 ) ;
F_92 ( F_44 ( & V_48 -> V_41 ) ) ;
F_42 ( & V_48 -> V_41 ) ;
V_17 -> V_23 . V_134 -- ;
if ( V_48 -> type == V_135 )
V_17 -> V_23 . V_136 -- ;
F_50 ( V_17 ) ;
F_22 ( V_48 -> V_66 && ! V_48 -> V_34 -> V_67 ) ;
if ( V_48 -> V_66 && V_48 -> V_34 -> V_67 )
V_48 -> V_34 -> V_67 ( V_48 , V_48 -> V_66 ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
}
unsigned int F_93 ( struct V_47 * V_48 )
{
unsigned int V_68 = 0 ;
struct V_47 * V_69 ;
F_46 (tmp, &plane->dev->mode_config.plane_list, head) {
if ( V_69 == V_48 )
return V_68 ;
V_68 ++ ;
}
F_60 () ;
}
void F_49 ( struct V_47 * V_48 )
{
int V_22 ;
if ( ! V_48 -> V_32 )
return;
V_48 -> V_149 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_150 ( V_48 ) ;
if ( V_22 ) {
F_48 ( L_20 ) ;
V_48 -> V_149 = NULL ;
return;
}
F_34 ( V_48 -> V_149 ) ;
V_48 -> V_149 = NULL ;
V_48 -> V_32 = NULL ;
V_48 -> V_46 = NULL ;
}
static int F_94 ( struct V_16 * V_17 )
{
struct V_151 * V_152 ;
V_152 = F_95 ( V_17 , V_153 |
V_154 ,
L_21 , 0 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_112 = V_152 ;
V_152 = F_96 ( V_17 , 0 ,
L_22 , V_155 ,
F_2 ( V_155 ) ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_113 = V_152 ;
V_152 = F_95 ( V_17 ,
V_153 |
V_154 ,
L_23 , 0 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_156 = V_152 ;
V_152 = F_95 ( V_17 ,
V_153 |
V_154 ,
L_24 , 0 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_157 = V_152 ;
V_152 = F_96 ( V_17 , V_154 ,
L_25 , V_158 ,
F_2 ( V_158 ) ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_137 = V_152 ;
V_152 = F_97 ( V_17 , V_159 ,
L_26 , 0 , V_160 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_143 = V_152 ;
V_152 = F_97 ( V_17 , V_159 ,
L_27 , 0 , V_160 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_144 = V_152 ;
V_152 = F_97 ( V_17 , V_159 ,
L_28 , 0 , V_160 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_145 = V_152 ;
V_152 = F_97 ( V_17 , V_159 ,
L_29 , 0 , V_160 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_146 = V_152 ;
V_152 = F_98 ( V_17 , V_159 ,
L_30 , V_161 , V_162 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_139 = V_152 ;
V_152 = F_98 ( V_17 , V_159 ,
L_31 , V_161 , V_162 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_140 = V_152 ;
V_152 = F_97 ( V_17 , V_159 ,
L_32 , 0 , V_162 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_141 = V_152 ;
V_152 = F_97 ( V_17 , V_159 ,
L_33 , 0 , V_162 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_142 = V_152 ;
V_152 = F_99 ( V_17 , V_159 ,
L_34 , V_30 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_138 = V_152 ;
V_152 = F_99 ( V_17 , V_159 ,
L_35 , V_58 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_114 = V_152 ;
V_152 = F_100 ( V_17 , V_159 ,
L_36 ) ;
if ( ! V_152 )
return - V_80 ;
V_17 -> V_23 . V_64 = V_152 ;
return 0 ;
}
int F_101 ( struct V_16 * V_17 )
{
struct V_151 * V_163 ;
struct V_151 * V_164 ;
if ( V_17 -> V_23 . V_165 )
return 0 ;
V_163 =
F_96 ( V_17 , 0 ,
L_37 ,
V_166 ,
F_2 ( V_166 ) ) ;
V_17 -> V_23 . V_165 = V_163 ;
V_164 = F_96 ( V_17 , V_154 ,
L_38 ,
V_167 ,
F_2 ( V_167 ) ) ;
V_17 -> V_23 . V_168 = V_164 ;
return 0 ;
}
int F_102 ( struct V_16 * V_17 ,
unsigned int V_169 ,
char * V_106 [] )
{
struct V_151 * V_170 ;
struct V_151 * V_171 ;
unsigned int V_1 ;
if ( V_17 -> V_23 . V_172 )
return 0 ;
V_170 = F_96 ( V_17 , 0 ,
L_37 ,
V_173 ,
F_2 ( V_173 ) ) ;
V_17 -> V_23 . V_172 = V_170 ;
V_171 =
F_96 ( V_17 , V_154 ,
L_38 ,
V_174 ,
F_2 ( V_174 ) ) ;
V_17 -> V_23 . V_175 = V_171 ;
V_17 -> V_23 . V_176 =
F_97 ( V_17 , 0 , L_39 , 0 , 100 ) ;
V_17 -> V_23 . V_177 =
F_97 ( V_17 , 0 , L_40 , 0 , 100 ) ;
V_17 -> V_23 . V_178 =
F_97 ( V_17 , 0 , L_41 , 0 , 100 ) ;
V_17 -> V_23 . V_179 =
F_97 ( V_17 , 0 , L_42 , 0 , 100 ) ;
V_17 -> V_23 . V_180 =
F_95 ( V_17 , V_181 ,
L_43 , V_169 ) ;
for ( V_1 = 0 ; V_1 < V_169 ; V_1 ++ )
F_103 ( V_17 -> V_23 . V_180 , V_1 ,
V_1 , V_106 [ V_1 ] ) ;
V_17 -> V_23 . V_182 =
F_97 ( V_17 , 0 , L_44 , 0 , 100 ) ;
V_17 -> V_23 . V_183 =
F_97 ( V_17 , 0 , L_45 , 0 , 100 ) ;
V_17 -> V_23 . V_184 =
F_97 ( V_17 , 0 , L_46 , 0 , 100 ) ;
V_17 -> V_23 . V_185 =
F_97 ( V_17 , 0 , L_47 , 0 , 100 ) ;
V_17 -> V_23 . V_186 =
F_97 ( V_17 , 0 , L_48 , 0 , 100 ) ;
V_17 -> V_23 . V_187 =
F_97 ( V_17 , 0 , L_49 , 0 , 100 ) ;
return 0 ;
}
int F_104 ( struct V_16 * V_17 )
{
struct V_151 * V_188 ;
if ( V_17 -> V_23 . V_189 )
return 0 ;
V_188 =
F_96 ( V_17 , 0 , L_50 ,
V_190 ,
F_2 ( V_190 ) ) ;
V_17 -> V_23 . V_189 = V_188 ;
return 0 ;
}
int F_105 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_191 )
return 0 ;
V_17 -> V_23 . V_191 =
F_96 ( V_17 , 0 , L_51 ,
V_192 ,
F_2 ( V_192 ) ) ;
if ( V_17 -> V_23 . V_191 == NULL )
return - V_80 ;
return 0 ;
}
int F_106 ( struct V_16 * V_17 )
{
struct V_151 * V_193 ;
if ( V_17 -> V_23 . V_194 )
return 0 ;
V_193 =
F_96 ( V_17 , V_154 ,
L_52 ,
V_195 ,
F_2 ( V_195 ) ) ;
V_17 -> V_23 . V_194 = V_193 ;
return 0 ;
}
int F_107 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_196 && V_17 -> V_23 . V_197 )
return 0 ;
V_17 -> V_23 . V_196 =
F_97 ( V_17 , V_154 , L_53 , 0 , 0xffffffff ) ;
V_17 -> V_23 . V_197 =
F_97 ( V_17 , V_154 , L_54 , 0 , 0xffffffff ) ;
if ( V_17 -> V_23 . V_196 == NULL ||
V_17 -> V_23 . V_197 == NULL )
return - V_80 ;
return 0 ;
}
static int F_108 ( struct V_16 * V_17 , struct V_198 * V_199 )
{
T_1 V_200 = 0 ;
V_200 += V_17 -> V_23 . V_61 ;
V_200 += V_17 -> V_23 . V_110 ;
V_200 += V_17 -> V_23 . V_127 ;
V_199 -> V_201 = F_109 ( V_200 , sizeof( T_1 ) , V_26 ) ;
if ( ! V_199 -> V_201 )
return - V_80 ;
V_199 -> V_202 = 0 ;
V_199 -> V_203 = 0 ;
V_199 -> V_204 = 0 ;
return 0 ;
}
void F_110 ( struct V_198 * V_199 )
{
F_58 ( V_199 -> V_201 ) ;
V_199 -> V_201 = NULL ;
}
int F_111 ( struct V_16 * V_17 ,
struct V_198 * V_199 )
{
struct V_45 * V_46 ;
struct V_120 * V_121 ;
struct V_70 * V_71 ;
int V_22 ;
V_22 = F_108 ( V_17 , V_199 ) ;
if ( V_22 )
return V_22 ;
F_46 (crtc, &dev->mode_config.crtc_list, head)
V_199 -> V_201 [ V_199 -> V_202 ++ ] = V_46 -> V_38 . V_27 ;
F_46 (encoder, &dev->mode_config.encoder_list, head)
V_199 -> V_201 [ V_199 -> V_202 + V_199 -> V_204 ++ ] =
V_121 -> V_38 . V_27 ;
F_46 (connector, &dev->mode_config.connector_list, head)
V_199 -> V_201 [ V_199 -> V_202 + V_199 -> V_204 +
V_199 -> V_203 ++ ] = V_71 -> V_38 . V_27 ;
return 0 ;
}
void F_112 ( struct V_16 * V_17 )
{
F_45 ( V_17 ) ;
F_110 ( & V_17 -> V_51 -> V_205 ) ;
F_111 ( V_17 , & V_17 -> V_51 -> V_205 ) ;
F_50 ( V_17 ) ;
}
static void F_113 ( struct V_206 * V_39 ,
const struct V_72 * V_207 )
{
F_114 ( V_207 -> V_208 > V_209 || V_207 -> V_210 > V_209 ||
V_207 -> V_211 > V_209 || V_207 -> V_212 > V_209 ||
V_207 -> V_213 > V_209 || V_207 -> V_214 > V_209 ||
V_207 -> V_215 > V_209 || V_207 -> V_216 > V_209 ||
V_207 -> V_217 > V_209 || V_207 -> V_218 > V_209 ,
L_55 ) ;
V_39 -> clock = V_207 -> clock ;
V_39 -> V_208 = V_207 -> V_208 ;
V_39 -> V_210 = V_207 -> V_210 ;
V_39 -> V_211 = V_207 -> V_211 ;
V_39 -> V_212 = V_207 -> V_212 ;
V_39 -> V_213 = V_207 -> V_213 ;
V_39 -> V_214 = V_207 -> V_214 ;
V_39 -> V_215 = V_207 -> V_215 ;
V_39 -> V_216 = V_207 -> V_216 ;
V_39 -> V_217 = V_207 -> V_217 ;
V_39 -> V_218 = V_207 -> V_218 ;
V_39 -> V_219 = V_207 -> V_219 ;
V_39 -> V_220 = V_207 -> V_220 ;
V_39 -> type = V_207 -> type ;
strncpy ( V_39 -> V_11 , V_207 -> V_11 , V_221 ) ;
V_39 -> V_11 [ V_221 - 1 ] = 0 ;
}
static int F_115 ( struct V_72 * V_39 ,
const struct V_206 * V_207 )
{
if ( V_207 -> clock > V_162 || V_207 -> V_219 > V_162 )
return - V_222 ;
if ( ( V_207 -> V_220 & V_223 ) > V_224 )
return - V_79 ;
V_39 -> clock = V_207 -> clock ;
V_39 -> V_208 = V_207 -> V_208 ;
V_39 -> V_210 = V_207 -> V_210 ;
V_39 -> V_211 = V_207 -> V_211 ;
V_39 -> V_212 = V_207 -> V_212 ;
V_39 -> V_213 = V_207 -> V_213 ;
V_39 -> V_214 = V_207 -> V_214 ;
V_39 -> V_215 = V_207 -> V_215 ;
V_39 -> V_216 = V_207 -> V_216 ;
V_39 -> V_217 = V_207 -> V_217 ;
V_39 -> V_218 = V_207 -> V_218 ;
V_39 -> V_219 = V_207 -> V_219 ;
V_39 -> V_220 = V_207 -> V_220 ;
V_39 -> type = V_207 -> type ;
strncpy ( V_39 -> V_11 , V_207 -> V_11 , V_221 ) ;
V_39 -> V_11 [ V_221 - 1 ] = 0 ;
return 0 ;
}
int F_116 ( struct V_16 * V_17 , void * V_225 ,
struct V_226 * V_227 )
{
struct V_228 * V_229 = V_225 ;
struct V_230 * V_231 ;
struct V_31 * V_32 ;
struct V_70 * V_71 ;
struct V_45 * V_46 ;
struct V_120 * V_121 ;
int V_22 = 0 ;
int V_232 = 0 ;
int V_233 = 0 ;
int V_234 = 0 ;
int V_235 = 0 ;
int V_236 = 0 , V_1 ;
T_1 T_3 * V_237 ;
T_1 T_3 * V_238 ;
T_1 T_3 * V_239 ;
T_1 T_3 * V_240 ;
struct V_198 * V_205 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
F_11 ( & V_227 -> V_242 ) ;
F_117 (lh, &file_priv->fbs)
V_234 ++ ;
if ( V_229 -> V_243 >= V_234 ) {
V_236 = 0 ;
V_237 = ( T_1 T_3 * ) ( unsigned long ) V_229 -> V_244 ;
F_46 (fb, &file_priv->fbs, filp_head) {
if ( F_118 ( V_32 -> V_38 . V_27 , V_237 + V_236 ) ) {
F_13 ( & V_227 -> V_242 ) ;
return - V_245 ;
}
V_236 ++ ;
}
}
V_229 -> V_243 = V_234 ;
F_13 ( & V_227 -> V_242 ) ;
F_11 ( & V_17 -> V_23 . V_57 ) ;
if ( ! F_119 ( V_227 ) ) {
V_205 = NULL ;
F_117 (lh, &dev->mode_config.crtc_list)
V_233 ++ ;
F_117 (lh, &dev->mode_config.connector_list)
V_232 ++ ;
F_117 (lh, &dev->mode_config.encoder_list)
V_235 ++ ;
} else {
V_205 = & V_227 -> V_246 -> V_247 -> V_205 ;
V_233 = V_205 -> V_202 ;
V_232 = V_205 -> V_203 ;
V_235 = V_205 -> V_204 ;
}
V_229 -> V_248 = V_17 -> V_23 . V_248 ;
V_229 -> V_249 = V_17 -> V_23 . V_249 ;
V_229 -> V_250 = V_17 -> V_23 . V_250 ;
V_229 -> V_251 = V_17 -> V_23 . V_251 ;
if ( V_229 -> V_252 >= V_233 ) {
V_236 = 0 ;
V_238 = ( T_1 T_3 * ) ( unsigned long ) V_229 -> V_253 ;
if ( ! V_205 ) {
F_46 (crtc, &dev->mode_config.crtc_list,
head) {
F_69 ( L_56 , V_46 -> V_38 . V_27 ) ;
if ( F_118 ( V_46 -> V_38 . V_27 , V_238 + V_236 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_236 ++ ;
}
} else {
for ( V_1 = 0 ; V_1 < V_205 -> V_202 ; V_1 ++ ) {
if ( F_118 ( V_205 -> V_201 [ V_1 ] ,
V_238 + V_236 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_236 ++ ;
}
}
}
V_229 -> V_252 = V_233 ;
if ( V_229 -> V_254 >= V_235 ) {
V_236 = 0 ;
V_240 = ( T_1 T_3 * ) ( unsigned long ) V_229 -> V_255 ;
if ( ! V_205 ) {
F_46 (encoder,
&dev->mode_config.encoder_list,
head) {
F_69 ( L_57 , V_121 -> V_38 . V_27 ,
V_121 -> V_11 ) ;
if ( F_118 ( V_121 -> V_38 . V_27 , V_240 +
V_236 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_236 ++ ;
}
} else {
for ( V_1 = V_205 -> V_202 ; V_1 < V_205 -> V_202 + V_205 -> V_204 ; V_1 ++ ) {
if ( F_118 ( V_205 -> V_201 [ V_1 ] ,
V_240 + V_236 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_236 ++ ;
}
}
}
V_229 -> V_254 = V_235 ;
if ( V_229 -> V_256 >= V_232 ) {
V_236 = 0 ;
V_239 = ( T_1 T_3 * ) ( unsigned long ) V_229 -> V_257 ;
if ( ! V_205 ) {
F_46 (connector,
&dev->mode_config.connector_list,
head) {
F_69 ( L_58 ,
V_71 -> V_38 . V_27 ,
V_71 -> V_11 ) ;
if ( F_118 ( V_71 -> V_38 . V_27 ,
V_239 + V_236 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_236 ++ ;
}
} else {
int V_258 = V_205 -> V_202 +
V_205 -> V_204 ;
for ( V_1 = V_258 ; V_1 < V_258 + V_205 -> V_203 ; V_1 ++ ) {
if ( F_118 ( V_205 -> V_201 [ V_1 ] ,
V_239 + V_236 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_236 ++ ;
}
}
}
V_229 -> V_256 = V_232 ;
F_69 ( L_59 , V_229 -> V_252 ,
V_229 -> V_256 , V_229 -> V_254 ) ;
V_39:
F_13 ( & V_17 -> V_23 . V_57 ) ;
return V_22 ;
}
int F_120 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_259 * V_260 = V_225 ;
struct V_45 * V_46 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
V_46 = F_121 ( V_17 , V_260 -> V_238 ) ;
if ( ! V_46 )
return - V_261 ;
F_122 ( V_46 , V_46 -> V_51 ) ;
V_260 -> V_262 = V_46 -> V_262 ;
V_260 -> V_263 = V_46 -> V_263 ;
V_260 -> V_264 = V_46 -> V_264 ;
if ( V_46 -> V_51 -> V_32 )
V_260 -> V_237 = V_46 -> V_51 -> V_32 -> V_38 . V_27 ;
else
V_260 -> V_237 = 0 ;
if ( V_46 -> V_265 ) {
F_113 ( & V_260 -> V_73 , & V_46 -> V_73 ) ;
V_260 -> V_266 = 1 ;
} else {
V_260 -> V_266 = 0 ;
}
F_123 ( V_46 ) ;
return 0 ;
}
static bool F_124 ( const struct V_72 * V_73 ,
const struct V_226 * V_227 )
{
if ( ! V_227 -> V_267 && F_125 ( V_73 ) )
return false ;
return true ;
}
static struct V_120 * F_126 ( struct V_70 * V_71 )
{
if ( V_71 -> V_66 )
return V_71 -> V_66 -> V_268 ;
return V_71 -> V_121 ;
}
static int F_127 ( struct V_18 * V_19 , bool V_269 ,
T_1 T_3 * V_270 , T_4 T_3 * V_271 ,
T_1 * V_272 )
{
int V_273 ;
int V_1 , V_22 , V_236 ;
V_273 = V_19 -> V_59 -> V_274 ;
if ( ! V_269 )
V_273 -= V_19 -> V_59 -> V_275 ;
if ( ( * V_272 >= V_273 ) && V_273 ) {
for ( V_1 = 0 , V_236 = 0 ; V_236 < V_273 ; V_1 ++ ) {
struct V_151 * V_152 = V_19 -> V_59 -> V_59 [ V_1 ] ;
T_4 V_276 ;
if ( ( V_152 -> V_220 & V_159 ) && ! V_269 )
continue;
V_22 = F_128 ( V_19 , V_152 , & V_276 ) ;
if ( V_22 )
return V_22 ;
if ( F_118 ( V_152 -> V_38 . V_27 , V_270 + V_236 ) )
return - V_245 ;
if ( F_118 ( V_276 , V_271 + V_236 ) )
return - V_245 ;
V_236 ++ ;
}
}
* V_272 = V_273 ;
return 0 ;
}
int F_129 ( struct V_16 * V_17 , void * V_225 ,
struct V_226 * V_227 )
{
struct V_277 * V_278 = V_225 ;
struct V_70 * V_71 ;
struct V_120 * V_121 ;
struct V_72 * V_73 ;
int V_279 = 0 ;
int V_280 = 0 ;
int V_22 = 0 ;
int V_236 = 0 ;
int V_1 ;
struct V_206 V_281 ;
struct V_206 T_3 * V_282 ;
T_1 T_3 * V_283 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
memset ( & V_281 , 0 , sizeof( struct V_206 ) ) ;
F_69 ( L_60 , V_278 -> V_239 ) ;
F_11 ( & V_17 -> V_23 . V_57 ) ;
V_71 = F_130 ( V_17 , V_278 -> V_239 ) ;
if ( ! V_71 ) {
V_22 = - V_261 ;
goto V_102;
}
for ( V_1 = 0 ; V_1 < V_284 ; V_1 ++ )
if ( V_71 -> V_285 [ V_1 ] != 0 )
V_280 ++ ;
if ( V_278 -> V_286 == 0 ) {
V_71 -> V_34 -> V_287 ( V_71 ,
V_17 -> V_23 . V_250 ,
V_17 -> V_23 . V_248 ) ;
}
F_46 (mode, &connector->modes, head)
if ( F_124 ( V_73 , V_227 ) )
V_279 ++ ;
V_278 -> V_239 = V_71 -> V_38 . V_27 ;
V_278 -> V_99 = V_71 -> V_99 ;
V_278 -> V_103 = V_71 -> V_103 ;
V_278 -> V_288 = V_71 -> V_118 . V_289 ;
V_278 -> V_290 = V_71 -> V_118 . V_291 ;
V_278 -> V_292 = V_71 -> V_118 . V_8 ;
V_278 -> V_293 = V_71 -> V_5 ;
F_131 ( & V_17 -> V_23 . V_119 , NULL ) ;
V_121 = F_126 ( V_71 ) ;
if ( V_121 )
V_278 -> V_240 = V_121 -> V_38 . V_27 ;
else
V_278 -> V_240 = 0 ;
if ( ( V_278 -> V_286 >= V_279 ) && V_279 ) {
V_236 = 0 ;
V_282 = (struct V_206 T_3 * ) ( unsigned long ) V_278 -> V_294 ;
F_46 (mode, &connector->modes, head) {
if ( ! F_124 ( V_73 , V_227 ) )
continue;
F_113 ( & V_281 , V_73 ) ;
if ( F_132 ( V_282 + V_236 ,
& V_281 , sizeof( V_281 ) ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_236 ++ ;
}
}
V_278 -> V_286 = V_279 ;
V_22 = F_127 ( & V_71 -> V_38 , V_227 -> V_269 ,
( T_1 T_3 * ) ( unsigned long ) ( V_278 -> V_295 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_278 -> V_296 ) ,
& V_278 -> V_297 ) ;
if ( V_22 )
goto V_39;
if ( ( V_278 -> V_254 >= V_280 ) && V_280 ) {
V_236 = 0 ;
V_283 = ( T_1 T_3 * ) ( unsigned long ) ( V_278 -> V_298 ) ;
for ( V_1 = 0 ; V_1 < V_284 ; V_1 ++ ) {
if ( V_71 -> V_285 [ V_1 ] != 0 ) {
if ( F_118 ( V_71 -> V_285 [ V_1 ] ,
V_283 + V_236 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_236 ++ ;
}
}
}
V_278 -> V_254 = V_280 ;
V_39:
F_133 ( & V_17 -> V_23 . V_119 ) ;
V_102:
F_13 ( & V_17 -> V_23 . V_57 ) ;
return V_22 ;
}
static struct V_45 * F_134 ( struct V_120 * V_121 )
{
struct V_70 * V_71 ;
struct V_16 * V_17 = V_121 -> V_17 ;
bool V_299 = false ;
F_46 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_71 -> V_66 )
continue;
V_299 = true ;
if ( V_71 -> V_66 -> V_268 != V_121 )
continue;
return V_71 -> V_66 -> V_46 ;
}
if ( V_299 )
return NULL ;
return V_121 -> V_46 ;
}
int F_135 ( struct V_16 * V_17 , void * V_225 ,
struct V_226 * V_227 )
{
struct V_300 * V_301 = V_225 ;
struct V_120 * V_121 ;
struct V_45 * V_46 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
V_121 = F_136 ( V_17 , V_301 -> V_240 ) ;
if ( ! V_121 )
return - V_261 ;
F_131 ( & V_17 -> V_23 . V_119 , NULL ) ;
V_46 = F_134 ( V_121 ) ;
if ( V_46 )
V_301 -> V_238 = V_46 -> V_38 . V_27 ;
else if ( V_121 -> V_46 )
V_301 -> V_238 = V_121 -> V_46 -> V_38 . V_27 ;
else
V_301 -> V_238 = 0 ;
F_133 ( & V_17 -> V_23 . V_119 ) ;
V_301 -> V_123 = V_121 -> V_123 ;
V_301 -> V_240 = V_121 -> V_38 . V_27 ;
V_301 -> V_62 = V_121 -> V_62 ;
V_301 -> V_302 = V_121 -> V_302 ;
return 0 ;
}
int F_137 ( struct V_16 * V_17 , void * V_225 ,
struct V_226 * V_227 )
{
struct V_303 * V_304 = V_225 ;
struct V_54 * V_55 ;
struct V_47 * V_48 ;
T_1 T_3 * V_305 ;
int V_236 = 0 ;
unsigned V_306 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
V_55 = & V_17 -> V_23 ;
if ( V_227 -> V_307 )
V_306 = V_55 -> V_134 ;
else
V_306 = V_55 -> V_136 ;
if ( V_306 &&
( V_304 -> V_308 >= V_306 ) ) {
V_305 = ( T_1 T_3 * ) ( unsigned long ) V_304 -> V_309 ;
F_46 (plane, &config->plane_list, head) {
if ( V_48 -> type != V_135 &&
! V_227 -> V_307 )
continue;
if ( F_118 ( V_48 -> V_38 . V_27 , V_305 + V_236 ) )
return - V_245 ;
V_236 ++ ;
}
}
V_304 -> V_308 = V_306 ;
return 0 ;
}
int F_138 ( struct V_16 * V_17 , void * V_225 ,
struct V_226 * V_227 )
{
struct V_310 * V_304 = V_225 ;
struct V_47 * V_48 ;
T_1 T_3 * V_311 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
V_48 = F_139 ( V_17 , V_304 -> V_312 ) ;
if ( ! V_48 )
return - V_261 ;
F_131 ( & V_48 -> V_57 , NULL ) ;
if ( V_48 -> V_46 )
V_304 -> V_238 = V_48 -> V_46 -> V_38 . V_27 ;
else
V_304 -> V_238 = 0 ;
if ( V_48 -> V_32 )
V_304 -> V_237 = V_48 -> V_32 -> V_38 . V_27 ;
else
V_304 -> V_237 = 0 ;
F_133 ( & V_48 -> V_57 ) ;
V_304 -> V_312 = V_48 -> V_38 . V_27 ;
V_304 -> V_62 = V_48 -> V_62 ;
V_304 -> V_264 = 0 ;
if ( V_48 -> V_129 &&
( V_304 -> V_313 >= V_48 -> V_129 ) ) {
V_311 = ( T_1 T_3 * ) ( unsigned long ) V_304 -> V_314 ;
if ( F_132 ( V_311 ,
V_48 -> V_132 ,
sizeof( T_1 ) * V_48 -> V_129 ) ) {
return - V_245 ;
}
}
V_304 -> V_313 = V_48 -> V_129 ;
return 0 ;
}
static int F_140 ( struct V_47 * V_48 ,
struct V_45 * V_46 ,
struct V_31 * V_32 ,
T_5 V_315 , T_5 V_316 ,
T_1 V_317 , T_1 V_318 ,
T_1 V_319 , T_1 V_320 ,
T_1 V_321 , T_1 V_322 )
{
int V_22 = 0 ;
unsigned int V_323 , V_324 ;
unsigned int V_1 ;
if ( ! V_32 ) {
V_48 -> V_149 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_150 ( V_48 ) ;
if ( ! V_22 ) {
V_48 -> V_46 = NULL ;
V_48 -> V_32 = NULL ;
} else {
V_48 -> V_149 = NULL ;
}
goto V_39;
}
if ( ! ( V_48 -> V_62 & F_141 ( V_46 ) ) ) {
F_69 ( L_61 ) ;
V_22 = - V_79 ;
goto V_39;
}
for ( V_1 = 0 ; V_1 < V_48 -> V_129 ; V_1 ++ )
if ( V_32 -> V_325 == V_48 -> V_132 [ V_1 ] )
break;
if ( V_1 == V_48 -> V_129 ) {
F_69 ( L_62 ,
F_9 ( V_32 -> V_325 ) ) ;
V_22 = - V_79 ;
goto V_39;
}
V_323 = V_32 -> V_326 << 16 ;
V_324 = V_32 -> V_327 << 16 ;
if ( V_321 > V_323 ||
V_319 > V_323 - V_321 ||
V_322 > V_324 ||
V_320 > V_324 - V_322 ) {
F_69 ( L_63
L_64 ,
V_321 >> 16 , ( ( V_321 & 0xffff ) * 15625 ) >> 10 ,
V_322 >> 16 , ( ( V_322 & 0xffff ) * 15625 ) >> 10 ,
V_319 >> 16 , ( ( V_319 & 0xffff ) * 15625 ) >> 10 ,
V_320 >> 16 , ( ( V_320 & 0xffff ) * 15625 ) >> 10 ) ;
V_22 = - V_328 ;
goto V_39;
}
V_48 -> V_149 = V_48 -> V_32 ;
V_22 = V_48 -> V_34 -> V_329 ( V_48 , V_46 , V_32 ,
V_315 , V_316 , V_317 , V_318 ,
V_319 , V_320 , V_321 , V_322 ) ;
if ( ! V_22 ) {
V_48 -> V_46 = V_46 ;
V_48 -> V_32 = V_32 ;
V_32 = NULL ;
} else {
V_48 -> V_149 = NULL ;
}
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
if ( V_48 -> V_149 )
F_34 ( V_48 -> V_149 ) ;
V_48 -> V_149 = NULL ;
return V_22 ;
}
static int F_142 ( struct V_47 * V_48 ,
struct V_45 * V_46 ,
struct V_31 * V_32 ,
T_5 V_315 , T_5 V_316 ,
T_1 V_317 , T_1 V_318 ,
T_1 V_319 , T_1 V_320 ,
T_1 V_321 , T_1 V_322 )
{
int V_22 ;
F_45 ( V_48 -> V_17 ) ;
V_22 = F_140 ( V_48 , V_46 , V_32 ,
V_315 , V_316 , V_317 , V_318 ,
V_319 , V_320 , V_321 , V_322 ) ;
F_50 ( V_48 -> V_17 ) ;
return V_22 ;
}
int F_143 ( struct V_16 * V_17 , void * V_225 ,
struct V_226 * V_227 )
{
struct V_330 * V_331 = V_225 ;
struct V_47 * V_48 ;
struct V_45 * V_46 = NULL ;
struct V_31 * V_32 = NULL ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
if ( V_331 -> V_317 > V_162 ||
V_331 -> V_315 > V_162 - ( T_5 ) V_331 -> V_317 ||
V_331 -> V_318 > V_162 ||
V_331 -> V_316 > V_162 - ( T_5 ) V_331 -> V_318 ) {
F_69 ( L_65 ,
V_331 -> V_317 , V_331 -> V_318 ,
V_331 -> V_315 , V_331 -> V_316 ) ;
return - V_222 ;
}
V_48 = F_139 ( V_17 , V_331 -> V_312 ) ;
if ( ! V_48 ) {
F_69 ( L_66 ,
V_331 -> V_312 ) ;
return - V_261 ;
}
if ( V_331 -> V_237 ) {
V_32 = F_32 ( V_17 , V_331 -> V_237 ) ;
if ( ! V_32 ) {
F_69 ( L_67 ,
V_331 -> V_237 ) ;
return - V_261 ;
}
V_46 = F_121 ( V_17 , V_331 -> V_238 ) ;
if ( ! V_46 ) {
F_69 ( L_68 ,
V_331 -> V_238 ) ;
return - V_261 ;
}
}
return F_142 ( V_48 , V_46 , V_32 ,
V_331 -> V_315 , V_331 -> V_316 ,
V_331 -> V_317 , V_331 -> V_318 ,
V_331 -> V_319 , V_331 -> V_320 ,
V_331 -> V_321 , V_331 -> V_322 ) ;
}
int F_47 ( struct V_49 * V_50 )
{
struct V_45 * V_46 = V_50 -> V_46 ;
struct V_31 * V_32 ;
struct V_45 * V_69 ;
int V_22 ;
F_46 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_69 -> V_51 -> V_149 = V_69 -> V_51 -> V_32 ;
V_32 = V_50 -> V_32 ;
V_22 = V_46 -> V_34 -> V_332 ( V_50 ) ;
if ( V_22 == 0 ) {
V_46 -> V_51 -> V_46 = V_46 ;
V_46 -> V_51 -> V_32 = V_32 ;
}
F_46 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_69 -> V_51 -> V_32 )
F_38 ( V_69 -> V_51 -> V_32 ) ;
if ( V_69 -> V_51 -> V_149 )
F_34 ( V_69 -> V_51 -> V_149 ) ;
V_69 -> V_51 -> V_149 = NULL ;
}
return V_22 ;
}
void F_144 ( const struct V_72 * V_73 ,
int * V_208 , int * V_214 )
{
struct V_72 V_333 ;
F_145 ( & V_333 , V_73 ) ;
F_146 ( & V_333 , V_334 ) ;
* V_208 = V_333 . V_335 ;
* V_214 = V_333 . V_336 ;
}
int F_147 ( const struct V_45 * V_46 ,
int V_262 , int V_263 ,
const struct V_72 * V_73 ,
const struct V_31 * V_32 )
{
int V_208 , V_214 ;
F_144 ( V_73 , & V_208 , & V_214 ) ;
if ( V_46 -> V_56 )
F_148 ( V_208 , V_214 ) ;
if ( V_208 > V_32 -> V_326 ||
V_214 > V_32 -> V_327 ||
V_262 > V_32 -> V_326 - V_208 ||
V_263 > V_32 -> V_327 - V_214 ) {
F_69 ( L_69 ,
V_32 -> V_326 , V_32 -> V_327 , V_208 , V_214 , V_262 , V_263 ,
V_46 -> V_56 ? L_70 : L_15 ) ;
return - V_328 ;
}
return 0 ;
}
int F_149 ( struct V_16 * V_17 , void * V_225 ,
struct V_226 * V_227 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
struct V_259 * V_337 = V_225 ;
struct V_45 * V_46 ;
struct V_70 * * V_338 = NULL , * V_71 ;
struct V_31 * V_32 = NULL ;
struct V_72 * V_73 = NULL ;
struct V_49 V_50 ;
T_1 T_3 * V_339 ;
int V_22 ;
int V_1 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
if ( V_337 -> V_262 > V_162 || V_337 -> V_263 > V_162 )
return - V_222 ;
F_45 ( V_17 ) ;
V_46 = F_121 ( V_17 , V_337 -> V_238 ) ;
if ( ! V_46 ) {
F_69 ( L_71 , V_337 -> V_238 ) ;
V_22 = - V_261 ;
goto V_39;
}
F_69 ( L_56 , V_46 -> V_38 . V_27 ) ;
if ( V_337 -> V_266 ) {
if ( V_337 -> V_237 == - 1 ) {
if ( ! V_46 -> V_51 -> V_32 ) {
F_69 ( L_72 ) ;
V_22 = - V_79 ;
goto V_39;
}
V_32 = V_46 -> V_51 -> V_32 ;
F_38 ( V_32 ) ;
} else {
V_32 = F_32 ( V_17 , V_337 -> V_237 ) ;
if ( ! V_32 ) {
F_69 ( L_73 ,
V_337 -> V_237 ) ;
V_22 = - V_261 ;
goto V_39;
}
}
V_73 = F_150 ( V_17 ) ;
if ( ! V_73 ) {
V_22 = - V_80 ;
goto V_39;
}
V_22 = F_115 ( V_73 , & V_337 -> V_73 ) ;
if ( V_22 ) {
F_69 ( L_74 ) ;
goto V_39;
}
V_73 -> V_5 = F_151 ( V_73 ) ;
if ( V_73 -> V_5 != V_340 ) {
V_22 = - V_79 ;
goto V_39;
}
F_146 ( V_73 , V_341 ) ;
V_22 = F_147 ( V_46 , V_337 -> V_262 , V_337 -> V_263 ,
V_73 , V_32 ) ;
if ( V_22 )
goto V_39;
}
if ( V_337 -> V_256 == 0 && V_73 ) {
F_69 ( L_75 ) ;
V_22 = - V_79 ;
goto V_39;
}
if ( V_337 -> V_256 > 0 && ( ! V_73 || ! V_32 ) ) {
F_69 ( L_76 ,
V_337 -> V_256 ) ;
V_22 = - V_79 ;
goto V_39;
}
if ( V_337 -> V_256 > 0 ) {
T_2 V_342 ;
if ( V_337 -> V_256 > V_55 -> V_110 ) {
V_22 = - V_79 ;
goto V_39;
}
V_338 = F_89 ( V_337 -> V_256 ,
sizeof( struct V_70 * ) ,
V_26 ) ;
if ( ! V_338 ) {
V_22 = - V_80 ;
goto V_39;
}
for ( V_1 = 0 ; V_1 < V_337 -> V_256 ; V_1 ++ ) {
V_339 = ( T_1 T_3 * ) ( unsigned long ) V_337 -> V_339 ;
if ( F_152 ( V_342 , & V_339 [ V_1 ] ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_71 = F_130 ( V_17 , V_342 ) ;
if ( ! V_71 ) {
F_69 ( L_77 ,
V_342 ) ;
V_22 = - V_261 ;
goto V_39;
}
F_69 ( L_58 ,
V_71 -> V_38 . V_27 ,
V_71 -> V_11 ) ;
V_338 [ V_1 ] = V_71 ;
}
}
V_50 . V_46 = V_46 ;
V_50 . V_262 = V_337 -> V_262 ;
V_50 . V_263 = V_337 -> V_263 ;
V_50 . V_73 = V_73 ;
V_50 . V_343 = V_338 ;
V_50 . V_203 = V_337 -> V_256 ;
V_50 . V_32 = V_32 ;
V_22 = F_47 ( & V_50 ) ;
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
F_58 ( V_338 ) ;
F_62 ( V_17 , V_73 ) ;
F_50 ( V_17 ) ;
return V_22 ;
}
static int F_153 ( struct V_45 * V_46 ,
struct V_344 * V_345 ,
struct V_226 * V_227 )
{
struct V_16 * V_17 = V_46 -> V_17 ;
struct V_31 * V_32 = NULL ;
struct V_346 V_347 = {
. V_326 = V_345 -> V_326 ,
. V_327 = V_345 -> V_327 ,
. V_325 = V_348 ,
. V_349 = { V_345 -> V_326 * 4 } ,
. V_350 = { V_345 -> V_351 } ,
} ;
T_5 V_315 , V_316 ;
T_1 V_317 = 0 , V_318 = 0 ;
T_1 V_321 = 0 , V_322 = 0 ;
int V_22 = 0 ;
F_92 ( ! V_46 -> V_52 ) ;
F_22 ( V_46 -> V_52 -> V_46 != V_46 && V_46 -> V_52 -> V_46 != NULL ) ;
if ( V_345 -> V_220 & V_352 ) {
if ( V_345 -> V_351 ) {
V_32 = F_154 ( V_17 , & V_347 , V_227 ) ;
if ( F_155 ( V_32 ) ) {
F_69 ( L_78 ) ;
return F_156 ( V_32 ) ;
}
} else {
V_32 = NULL ;
}
} else {
V_32 = V_46 -> V_52 -> V_32 ;
if ( V_32 )
F_38 ( V_32 ) ;
}
if ( V_345 -> V_220 & V_353 ) {
V_315 = V_345 -> V_262 ;
V_316 = V_345 -> V_263 ;
} else {
V_315 = V_46 -> V_354 ;
V_316 = V_46 -> V_355 ;
}
if ( V_32 ) {
V_317 = V_32 -> V_326 ;
V_318 = V_32 -> V_327 ;
V_321 = V_32 -> V_326 << 16 ;
V_322 = V_32 -> V_327 << 16 ;
}
V_22 = F_140 ( V_46 -> V_52 , V_46 , V_32 ,
V_315 , V_316 , V_317 , V_318 ,
0 , 0 , V_321 , V_322 ) ;
if ( V_22 == 0 && V_345 -> V_220 & V_353 ) {
V_46 -> V_354 = V_345 -> V_262 ;
V_46 -> V_355 = V_345 -> V_263 ;
}
return V_22 ;
}
static int F_157 ( struct V_16 * V_17 ,
struct V_344 * V_345 ,
struct V_226 * V_227 )
{
struct V_45 * V_46 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
if ( ! V_345 -> V_220 || ( ~ V_356 & V_345 -> V_220 ) )
return - V_79 ;
V_46 = F_121 ( V_17 , V_345 -> V_238 ) ;
if ( ! V_46 ) {
F_69 ( L_71 , V_345 -> V_238 ) ;
return - V_261 ;
}
F_122 ( V_46 , V_46 -> V_52 ) ;
if ( V_46 -> V_52 ) {
V_22 = F_153 ( V_46 , V_345 , V_227 ) ;
goto V_39;
}
if ( V_345 -> V_220 & V_352 ) {
if ( ! V_46 -> V_34 -> V_357 && ! V_46 -> V_34 -> V_358 ) {
V_22 = - V_359 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_358 )
V_22 = V_46 -> V_34 -> V_358 ( V_46 , V_227 , V_345 -> V_351 ,
V_345 -> V_326 , V_345 -> V_327 , V_345 -> V_360 , V_345 -> V_361 ) ;
else
V_22 = V_46 -> V_34 -> V_357 ( V_46 , V_227 , V_345 -> V_351 ,
V_345 -> V_326 , V_345 -> V_327 ) ;
}
if ( V_345 -> V_220 & V_353 ) {
if ( V_46 -> V_34 -> V_362 ) {
V_22 = V_46 -> V_34 -> V_362 ( V_46 , V_345 -> V_262 , V_345 -> V_263 ) ;
} else {
V_22 = - V_245 ;
goto V_39;
}
}
V_39:
F_123 ( V_46 ) ;
return V_22 ;
}
int F_158 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_363 * V_345 = V_225 ;
struct V_344 V_364 ;
memcpy ( & V_364 , V_345 , sizeof( struct V_363 ) ) ;
V_364 . V_360 = V_364 . V_361 = 0 ;
return F_157 ( V_17 , & V_364 , V_227 ) ;
}
int F_159 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_344 * V_345 = V_225 ;
return F_157 ( V_17 , V_345 , V_227 ) ;
}
T_1 F_160 ( T_1 V_365 , T_1 V_366 )
{
T_1 V_367 ;
switch ( V_365 ) {
case 8 :
V_367 = V_368 ;
break;
case 16 :
if ( V_366 == 15 )
V_367 = V_369 ;
else
V_367 = V_370 ;
break;
case 24 :
V_367 = V_371 ;
break;
case 32 :
if ( V_366 == 24 )
V_367 = V_372 ;
else if ( V_366 == 30 )
V_367 = V_373 ;
else
V_367 = V_348 ;
break;
default:
F_48 ( L_79 ) ;
V_367 = V_372 ;
break;
}
return V_367 ;
}
int F_161 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_374 * V_375 = V_225 ;
struct V_346 V_376 = {} ;
int V_22 ;
V_376 . V_237 = V_375 -> V_237 ;
V_376 . V_326 = V_375 -> V_326 ;
V_376 . V_327 = V_375 -> V_327 ;
V_376 . V_349 [ 0 ] = V_375 -> V_377 ;
V_376 . V_325 = F_160 ( V_375 -> V_365 , V_375 -> V_366 ) ;
V_376 . V_350 [ 0 ] = V_375 -> V_351 ;
V_22 = F_162 ( V_17 , & V_376 , V_227 ) ;
if ( V_22 )
return V_22 ;
V_375 -> V_237 = V_376 . V_237 ;
return 0 ;
}
static int F_163 ( const struct V_346 * V_376 )
{
T_1 V_13 = V_376 -> V_325 & ~ V_15 ;
switch ( V_13 ) {
case V_368 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_369 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_370 :
case V_395 :
case V_371 :
case V_396 :
case V_372 :
case V_397 :
case V_398 :
case V_399 :
case V_348 :
case V_400 :
case V_401 :
case V_402 :
case V_373 :
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
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
return 0 ;
default:
F_69 ( L_80 ,
F_9 ( V_376 -> V_325 ) ) ;
return - V_79 ;
}
}
static int F_164 ( const struct V_346 * V_376 )
{
int V_22 , V_431 , V_432 , V_306 , V_1 ;
V_22 = F_163 ( V_376 ) ;
if ( V_22 ) {
F_69 ( L_81 ,
F_9 ( V_376 -> V_325 ) ) ;
return V_22 ;
}
V_431 = F_165 ( V_376 -> V_325 ) ;
V_432 = F_166 ( V_376 -> V_325 ) ;
V_306 = F_167 ( V_376 -> V_325 ) ;
if ( V_376 -> V_326 == 0 || V_376 -> V_326 % V_431 ) {
F_69 ( L_82 , V_376 -> V_326 ) ;
return - V_79 ;
}
if ( V_376 -> V_327 == 0 || V_376 -> V_327 % V_432 ) {
F_69 ( L_83 , V_376 -> V_327 ) ;
return - V_79 ;
}
for ( V_1 = 0 ; V_1 < V_306 ; V_1 ++ ) {
unsigned int V_326 = V_376 -> V_326 / ( V_1 != 0 ? V_431 : 1 ) ;
unsigned int V_327 = V_376 -> V_327 / ( V_1 != 0 ? V_432 : 1 ) ;
unsigned int V_433 = F_168 ( V_376 -> V_325 , V_1 ) ;
if ( ! V_376 -> V_350 [ V_1 ] ) {
F_69 ( L_84 , V_1 ) ;
return - V_79 ;
}
if ( ( T_4 ) V_326 * V_433 > V_160 )
return - V_222 ;
if ( ( T_4 ) V_327 * V_376 -> V_349 [ V_1 ] + V_376 -> V_434 [ V_1 ] > V_160 )
return - V_222 ;
if ( V_376 -> V_349 [ V_1 ] < V_326 * V_433 ) {
F_69 ( L_85 , V_376 -> V_349 [ V_1 ] , V_1 ) ;
return - V_79 ;
}
}
return 0 ;
}
static struct V_31 *
F_154 ( struct V_16 * V_17 ,
struct V_346 * V_376 ,
struct V_226 * V_227 )
{
struct V_54 * V_55 = & V_17 -> V_23 ;
struct V_31 * V_32 ;
int V_22 ;
if ( V_376 -> V_220 & ~ V_435 ) {
F_69 ( L_86 , V_376 -> V_220 ) ;
return F_169 ( - V_79 ) ;
}
if ( ( V_55 -> V_251 > V_376 -> V_326 ) || ( V_376 -> V_326 > V_55 -> V_250 ) ) {
F_69 ( L_87 ,
V_376 -> V_326 , V_55 -> V_251 , V_55 -> V_250 ) ;
return F_169 ( - V_79 ) ;
}
if ( ( V_55 -> V_249 > V_376 -> V_327 ) || ( V_376 -> V_327 > V_55 -> V_248 ) ) {
F_69 ( L_88 ,
V_376 -> V_327 , V_55 -> V_249 , V_55 -> V_248 ) ;
return F_169 ( - V_79 ) ;
}
V_22 = F_164 ( V_376 ) ;
if ( V_22 )
return F_169 ( V_22 ) ;
V_32 = V_17 -> V_23 . V_34 -> V_436 ( V_17 , V_227 , V_376 ) ;
if ( F_155 ( V_32 ) ) {
F_69 ( L_89 ) ;
return V_32 ;
}
return V_32 ;
}
int F_162 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_346 * V_376 = V_225 ;
struct V_31 * V_32 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
V_32 = F_154 ( V_17 , V_376 , V_227 ) ;
if ( F_155 ( V_32 ) )
return F_156 ( V_32 ) ;
F_69 ( L_90 , V_32 -> V_38 . V_27 ) ;
F_11 ( & V_227 -> V_242 ) ;
V_376 -> V_237 = V_32 -> V_38 . V_27 ;
F_26 ( & V_32 -> V_37 , & V_227 -> V_437 ) ;
F_13 ( & V_227 -> V_242 ) ;
return 0 ;
}
int F_170 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_31 * V_32 = NULL ;
struct V_31 * V_438 = NULL ;
T_1 * V_27 = V_225 ;
int V_439 = 0 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
F_11 ( & V_227 -> V_242 ) ;
F_11 ( & V_17 -> V_23 . V_35 ) ;
V_32 = F_30 ( V_17 , * V_27 ) ;
if ( ! V_32 )
goto V_440;
F_46 (fbl, &file_priv->fbs, filp_head)
if ( V_32 == V_438 )
V_439 = 1 ;
if ( ! V_439 )
goto V_440;
F_27 ( V_17 , V_32 ) ;
F_171 ( & V_32 -> V_37 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_13 ( & V_227 -> V_242 ) ;
F_43 ( V_32 ) ;
return 0 ;
V_440:
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_13 ( & V_227 -> V_242 ) ;
return - V_261 ;
}
int F_172 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_374 * V_376 = V_225 ;
struct V_31 * V_32 ;
int V_22 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
V_32 = F_32 ( V_17 , V_376 -> V_237 ) ;
if ( ! V_32 )
return - V_261 ;
V_376 -> V_327 = V_32 -> V_327 ;
V_376 -> V_326 = V_32 -> V_326 ;
V_376 -> V_366 = V_32 -> V_366 ;
V_376 -> V_365 = V_32 -> V_441 ;
V_376 -> V_377 = V_32 -> V_349 [ 0 ] ;
if ( V_32 -> V_34 -> V_442 ) {
if ( V_227 -> V_443 || F_173 ( V_444 ) ||
F_174 ( V_227 ) ) {
V_22 = V_32 -> V_34 -> V_442 ( V_32 , V_227 ,
& V_376 -> V_351 ) ;
} else {
V_376 -> V_351 = 0 ;
V_22 = 0 ;
}
} else {
V_22 = - V_445 ;
}
F_34 ( V_32 ) ;
return V_22 ;
}
int F_175 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_446 T_3 * V_447 ;
struct V_446 * V_448 = NULL ;
struct V_449 * V_376 = V_225 ;
struct V_31 * V_32 ;
unsigned V_220 ;
int V_450 ;
int V_22 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
V_32 = F_32 ( V_17 , V_376 -> V_237 ) ;
if ( ! V_32 )
return - V_261 ;
V_450 = V_376 -> V_450 ;
V_447 = (struct V_446 T_3 * ) ( unsigned long ) V_376 -> V_447 ;
if ( ! V_450 != ! V_447 ) {
V_22 = - V_79 ;
goto V_451;
}
V_220 = V_452 & V_376 -> V_220 ;
if ( V_220 & V_453 && ( V_450 % 2 ) ) {
V_22 = - V_79 ;
goto V_451;
}
if ( V_450 && V_447 ) {
if ( V_450 < 0 || V_450 > V_454 ) {
V_22 = - V_79 ;
goto V_451;
}
V_448 = F_109 ( V_450 , sizeof( * V_448 ) , V_26 ) ;
if ( ! V_448 ) {
V_22 = - V_80 ;
goto V_451;
}
V_22 = F_176 ( V_448 , V_447 ,
V_450 * sizeof( * V_448 ) ) ;
if ( V_22 ) {
V_22 = - V_245 ;
goto V_455;
}
}
if ( V_32 -> V_34 -> V_456 ) {
V_22 = V_32 -> V_34 -> V_456 ( V_32 , V_227 , V_220 , V_376 -> V_457 ,
V_448 , V_450 ) ;
} else {
V_22 = - V_458 ;
}
V_455:
F_58 ( V_448 ) ;
V_451:
F_34 ( V_32 ) ;
return V_22 ;
}
void F_177 ( struct V_226 * V_459 )
{
struct V_16 * V_17 = V_459 -> V_247 -> V_17 ;
struct V_31 * V_32 , * V_460 ;
F_75 (fb, tfb, &priv->fbs, filp_head) {
F_11 ( & V_17 -> V_23 . V_35 ) ;
F_27 ( V_17 , V_32 ) ;
F_13 ( & V_17 -> V_23 . V_35 ) ;
F_171 ( & V_32 -> V_37 ) ;
F_43 ( V_32 ) ;
}
}
struct V_151 * F_95 ( struct V_16 * V_17 , int V_220 ,
const char * V_11 , int V_461 )
{
struct V_151 * V_462 = NULL ;
int V_22 ;
V_462 = F_178 ( sizeof( struct V_151 ) , V_26 ) ;
if ( ! V_462 )
return NULL ;
V_462 -> V_17 = V_17 ;
if ( V_461 ) {
V_462 -> V_463 = F_109 ( V_461 , sizeof( T_4 ) ,
V_26 ) ;
if ( ! V_462 -> V_463 )
goto V_464;
}
V_22 = F_14 ( V_17 , & V_462 -> V_38 , V_465 ) ;
if ( V_22 )
goto V_464;
V_462 -> V_220 = V_220 ;
V_462 -> V_461 = V_461 ;
F_25 ( & V_462 -> V_466 ) ;
if ( V_11 ) {
strncpy ( V_462 -> V_11 , V_11 , V_467 ) ;
V_462 -> V_11 [ V_467 - 1 ] = '\0' ;
}
F_53 ( & V_462 -> V_41 , & V_17 -> V_23 . V_468 ) ;
F_22 ( ! F_179 ( V_462 ) ) ;
return V_462 ;
V_464:
F_58 ( V_462 -> V_463 ) ;
F_58 ( V_462 ) ;
return NULL ;
}
struct V_151 * F_96 ( struct V_16 * V_17 , int V_220 ,
const char * V_11 ,
const struct V_469 * V_470 ,
int V_461 )
{
struct V_151 * V_462 ;
int V_1 , V_22 ;
V_220 |= V_181 ;
V_462 = F_95 ( V_17 , V_220 , V_11 , V_461 ) ;
if ( ! V_462 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_461 ; V_1 ++ ) {
V_22 = F_103 ( V_462 , V_1 ,
V_470 [ V_1 ] . type ,
V_470 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_180 ( V_17 , V_462 ) ;
return NULL ;
}
}
return V_462 ;
}
struct V_151 * F_181 ( struct V_16 * V_17 ,
int V_220 , const char * V_11 ,
const struct V_469 * V_470 ,
int V_471 ,
T_4 V_472 )
{
struct V_151 * V_462 ;
int V_1 , V_22 , V_68 = 0 ;
int V_461 = F_182 ( V_472 ) ;
V_220 |= V_473 ;
V_462 = F_95 ( V_17 , V_220 , V_11 , V_461 ) ;
if ( ! V_462 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_471 ; V_1 ++ ) {
if ( ! ( V_472 & ( 1ULL << V_470 [ V_1 ] . type ) ) )
continue;
if ( F_22 ( V_68 >= V_461 ) ) {
F_180 ( V_17 , V_462 ) ;
return NULL ;
}
V_22 = F_103 ( V_462 , V_68 ++ ,
V_470 [ V_1 ] . type ,
V_470 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_180 ( V_17 , V_462 ) ;
return NULL ;
}
}
return V_462 ;
}
static struct V_151 * F_183 ( struct V_16 * V_17 ,
int V_220 , const char * V_11 ,
T_4 V_474 , T_4 V_475 )
{
struct V_151 * V_462 ;
V_462 = F_95 ( V_17 , V_220 , V_11 , 2 ) ;
if ( ! V_462 )
return NULL ;
V_462 -> V_463 [ 0 ] = V_474 ;
V_462 -> V_463 [ 1 ] = V_475 ;
return V_462 ;
}
struct V_151 * F_97 ( struct V_16 * V_17 , int V_220 ,
const char * V_11 ,
T_4 V_474 , T_4 V_475 )
{
return F_183 ( V_17 , V_476 | V_220 ,
V_11 , V_474 , V_475 ) ;
}
struct V_151 * F_98 ( struct V_16 * V_17 ,
int V_220 , const char * V_11 ,
T_6 V_474 , T_6 V_475 )
{
return F_183 ( V_17 , V_477 | V_220 ,
V_11 , F_184 ( V_474 ) , F_184 ( V_475 ) ) ;
}
struct V_151 * F_99 ( struct V_16 * V_17 ,
int V_220 , const char * V_11 , T_1 type )
{
struct V_151 * V_462 ;
V_220 |= V_478 ;
if ( F_22 ( ! ( V_220 & V_159 ) ) )
return NULL ;
V_462 = F_95 ( V_17 , V_220 , V_11 , 1 ) ;
if ( ! V_462 )
return NULL ;
V_462 -> V_463 [ 0 ] = type ;
return V_462 ;
}
struct V_151 * F_100 ( struct V_16 * V_17 , int V_220 ,
const char * V_11 )
{
return F_97 ( V_17 , V_220 , V_11 , 0 , 1 ) ;
}
int F_103 ( struct V_151 * V_462 , int V_68 ,
T_4 V_479 , const char * V_11 )
{
struct V_480 * V_481 ;
if ( ! ( F_185 ( V_462 , V_181 ) ||
F_185 ( V_462 , V_473 ) ) )
return - V_79 ;
if ( F_185 ( V_462 , V_473 ) &&
( V_479 > 63 ) )
return - V_79 ;
if ( ! F_44 ( & V_462 -> V_466 ) ) {
F_46 (prop_enum, &property->enum_list, head) {
if ( V_481 -> V_479 == V_479 ) {
strncpy ( V_481 -> V_11 , V_11 , V_467 ) ;
V_481 -> V_11 [ V_467 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_481 = F_178 ( sizeof( struct V_480 ) , V_26 ) ;
if ( ! V_481 )
return - V_80 ;
strncpy ( V_481 -> V_11 , V_11 , V_467 ) ;
V_481 -> V_11 [ V_467 - 1 ] = '\0' ;
V_481 -> V_479 = V_479 ;
V_462 -> V_463 [ V_68 ] = V_479 ;
F_53 ( & V_481 -> V_41 , & V_462 -> V_466 ) ;
return 0 ;
}
void F_180 ( struct V_16 * V_17 , struct V_151 * V_462 )
{
struct V_480 * V_481 , * V_482 ;
F_75 (prop_enum, pt, &property->enum_list, head) {
F_42 ( & V_481 -> V_41 ) ;
F_58 ( V_481 ) ;
}
if ( V_462 -> V_461 )
F_58 ( V_462 -> V_463 ) ;
F_17 ( V_17 , & V_462 -> V_38 ) ;
F_42 ( & V_462 -> V_41 ) ;
F_58 ( V_462 ) ;
}
void F_56 ( struct V_18 * V_19 ,
struct V_151 * V_462 ,
T_4 V_483 )
{
int V_274 = V_19 -> V_59 -> V_274 ;
if ( V_274 == V_484 ) {
F_114 ( 1 , L_91
L_92
L_93 ,
V_19 -> type ) ;
return;
}
V_19 -> V_59 -> V_59 [ V_274 ] = V_462 ;
V_19 -> V_59 -> V_463 [ V_274 ] = V_483 ;
V_19 -> V_59 -> V_274 ++ ;
if ( V_462 -> V_220 & V_159 )
V_19 -> V_59 -> V_275 ++ ;
}
int F_186 ( struct V_18 * V_19 ,
struct V_151 * V_462 , T_4 V_276 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_59 -> V_274 ; V_1 ++ ) {
if ( V_19 -> V_59 -> V_59 [ V_1 ] == V_462 ) {
V_19 -> V_59 -> V_463 [ V_1 ] = V_276 ;
return 0 ;
}
}
return - V_79 ;
}
int F_128 ( struct V_18 * V_19 ,
struct V_151 * V_462 , T_4 * V_276 )
{
int V_1 ;
if ( F_55 ( V_462 -> V_17 , V_63 ) &&
! ( V_462 -> V_220 & V_154 ) )
return F_187 ( V_19 , V_462 , V_276 ) ;
for ( V_1 = 0 ; V_1 < V_19 -> V_59 -> V_274 ; V_1 ++ ) {
if ( V_19 -> V_59 -> V_59 [ V_1 ] == V_462 ) {
* V_276 = V_19 -> V_59 -> V_463 [ V_1 ] ;
return 0 ;
}
}
return - V_79 ;
}
int F_188 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_485 * V_278 = V_225 ;
struct V_151 * V_462 ;
int V_486 = 0 ;
int V_487 = 0 ;
int V_22 = 0 , V_1 ;
int V_236 ;
struct V_480 * V_481 ;
struct V_488 T_3 * V_489 ;
T_4 T_3 * V_490 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
F_45 ( V_17 ) ;
V_462 = F_189 ( V_17 , V_278 -> V_491 ) ;
if ( ! V_462 ) {
V_22 = - V_261 ;
goto V_492;
}
if ( F_185 ( V_462 , V_181 ) ||
F_185 ( V_462 , V_473 ) ) {
F_46 (prop_enum, &property->enum_list, head)
V_486 ++ ;
}
V_487 = V_462 -> V_461 ;
strncpy ( V_278 -> V_11 , V_462 -> V_11 , V_467 ) ;
V_278 -> V_11 [ V_467 - 1 ] = 0 ;
V_278 -> V_220 = V_462 -> V_220 ;
if ( ( V_278 -> V_493 >= V_487 ) && V_487 ) {
V_490 = ( T_4 T_3 * ) ( unsigned long ) V_278 -> V_490 ;
for ( V_1 = 0 ; V_1 < V_487 ; V_1 ++ ) {
if ( F_132 ( V_490 + V_1 , & V_462 -> V_463 [ V_1 ] , sizeof( T_4 ) ) ) {
V_22 = - V_245 ;
goto V_492;
}
}
}
V_278 -> V_493 = V_487 ;
if ( F_185 ( V_462 , V_181 ) ||
F_185 ( V_462 , V_473 ) ) {
if ( ( V_278 -> V_494 >= V_486 ) && V_486 ) {
V_236 = 0 ;
V_489 = (struct V_488 T_3 * ) ( unsigned long ) V_278 -> V_495 ;
F_46 (prop_enum, &property->enum_list, head) {
if ( F_132 ( & V_489 [ V_236 ] . V_479 , & V_481 -> V_479 , sizeof( T_4 ) ) ) {
V_22 = - V_245 ;
goto V_492;
}
if ( F_132 ( & V_489 [ V_236 ] . V_11 ,
& V_481 -> V_11 , V_467 ) ) {
V_22 = - V_245 ;
goto V_492;
}
V_236 ++ ;
}
}
V_278 -> V_494 = V_486 ;
}
if ( F_185 ( V_462 , V_153 ) )
V_278 -> V_494 = 0 ;
V_492:
F_50 ( V_17 ) ;
return V_22 ;
}
static struct V_496 *
F_190 ( struct V_16 * V_17 , T_7 V_497 ,
const void * V_225 )
{
struct V_496 * V_498 ;
int V_22 ;
if ( ! V_497 || ! V_225 )
return NULL ;
V_498 = F_178 ( sizeof( struct V_496 ) + V_497 , V_26 ) ;
if ( ! V_498 )
return NULL ;
V_22 = F_14 ( V_17 , & V_498 -> V_38 , V_499 ) ;
if ( V_22 ) {
F_58 ( V_498 ) ;
return NULL ;
}
V_498 -> V_497 = V_497 ;
memcpy ( V_498 -> V_225 , V_225 , V_497 ) ;
F_53 ( & V_498 -> V_41 , & V_17 -> V_23 . V_500 ) ;
return V_498 ;
}
static void F_191 ( struct V_16 * V_17 ,
struct V_496 * V_498 )
{
F_17 ( V_17 , & V_498 -> V_38 ) ;
F_42 ( & V_498 -> V_41 ) ;
F_58 ( V_498 ) ;
}
int F_192 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_501 * V_278 = V_225 ;
struct V_496 * V_498 ;
int V_22 = 0 ;
void T_3 * V_502 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
F_45 ( V_17 ) ;
V_498 = F_193 ( V_17 , V_278 -> V_503 ) ;
if ( ! V_498 ) {
V_22 = - V_261 ;
goto V_492;
}
if ( V_278 -> V_497 == V_498 -> V_497 ) {
V_502 = ( void T_3 * ) ( unsigned long ) V_278 -> V_225 ;
if ( F_132 ( V_502 , V_498 -> V_225 , V_498 -> V_497 ) ) {
V_22 = - V_245 ;
goto V_492;
}
}
V_278 -> V_497 = V_498 -> V_497 ;
V_492:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_194 ( struct V_70 * V_71 ,
const char * V_504 )
{
struct V_16 * V_17 = V_71 -> V_17 ;
T_7 V_505 = strlen ( V_504 ) + 1 ;
int V_22 ;
V_71 -> V_506 = F_190 ( V_71 -> V_17 ,
V_505 , V_504 ) ;
if ( ! V_71 -> V_506 )
return - V_79 ;
V_22 = F_186 ( & V_71 -> V_38 ,
V_17 -> V_23 . V_156 ,
V_71 -> V_506 -> V_38 . V_27 ) ;
return V_22 ;
}
int F_195 ( struct V_70 * V_71 )
{
struct V_16 * V_17 = V_71 -> V_17 ;
int V_22 , V_505 ;
char V_507 [ 256 ] ;
if ( V_71 -> V_508 )
F_191 ( V_17 , V_71 -> V_508 ) ;
if ( ! V_71 -> V_509 ) {
V_71 -> V_508 = NULL ;
V_22 = F_186 ( & V_71 -> V_38 ,
V_17 -> V_23 . V_157 , 0 ) ;
return V_22 ;
}
snprintf ( V_507 , 256 , L_94 ,
V_71 -> V_117 -> V_27 , V_71 -> V_510 ,
V_71 -> V_511 , V_71 -> V_512 ,
V_71 -> V_513 , V_71 -> V_514 ,
V_71 -> V_515 , V_71 -> V_516 ) ;
V_505 = strlen ( V_507 ) + 1 ;
V_71 -> V_508 = F_190 ( V_71 -> V_17 ,
V_505 , V_507 ) ;
if ( ! V_71 -> V_508 )
return - V_79 ;
V_22 = F_186 ( & V_71 -> V_38 ,
V_17 -> V_23 . V_157 ,
V_71 -> V_508 -> V_38 . V_27 ) ;
return V_22 ;
}
int F_196 ( struct V_70 * V_71 ,
const struct V_517 * V_517 )
{
struct V_16 * V_17 = V_71 -> V_17 ;
T_7 V_505 ;
int V_22 ;
if ( V_71 -> V_518 )
return 0 ;
if ( V_71 -> V_107 )
F_191 ( V_17 , V_71 -> V_107 ) ;
if ( ! V_517 ) {
V_71 -> V_107 = NULL ;
V_22 = F_186 ( & V_71 -> V_38 , V_17 -> V_23 . V_112 , 0 ) ;
return V_22 ;
}
V_505 = V_519 * ( 1 + V_517 -> V_520 ) ;
V_71 -> V_107 = F_190 ( V_71 -> V_17 ,
V_505 , V_517 ) ;
if ( ! V_71 -> V_107 )
return - V_79 ;
V_22 = F_186 ( & V_71 -> V_38 ,
V_17 -> V_23 . V_112 ,
V_71 -> V_107 -> V_38 . V_27 ) ;
return V_22 ;
}
bool F_197 ( struct V_151 * V_462 ,
T_4 V_479 , struct V_18 * * V_521 )
{
int V_1 ;
if ( V_462 -> V_220 & V_154 )
return false ;
* V_521 = NULL ;
if ( F_185 ( V_462 , V_476 ) ) {
if ( V_479 < V_462 -> V_463 [ 0 ] || V_479 > V_462 -> V_463 [ 1 ] )
return false ;
return true ;
} else if ( F_185 ( V_462 , V_477 ) ) {
T_6 V_522 = F_198 ( V_479 ) ;
if ( V_522 < F_198 ( V_462 -> V_463 [ 0 ] ) ||
V_522 > F_198 ( V_462 -> V_463 [ 1 ] ) )
return false ;
return true ;
} else if ( F_185 ( V_462 , V_473 ) ) {
T_4 V_523 = 0 ;
for ( V_1 = 0 ; V_1 < V_462 -> V_461 ; V_1 ++ )
V_523 |= ( 1ULL << V_462 -> V_463 [ V_1 ] ) ;
return ! ( V_479 & ~ V_523 ) ;
} else if ( F_185 ( V_462 , V_153 ) ) {
return true ;
} else if ( F_185 ( V_462 , V_478 ) ) {
if ( V_479 == 0 )
return true ;
if ( V_462 -> V_463 [ 0 ] == V_30 ) {
struct V_31 * V_32 ;
V_32 = F_32 ( V_462 -> V_17 , V_479 ) ;
if ( V_32 ) {
* V_521 = & V_32 -> V_38 ;
return true ;
} else {
return false ;
}
} else {
return F_19 ( V_462 -> V_17 , V_479 , V_462 -> V_463 [ 0 ] ) != NULL ;
}
}
for ( V_1 = 0 ; V_1 < V_462 -> V_461 ; V_1 ++ )
if ( V_462 -> V_463 [ V_1 ] == V_479 )
return true ;
return false ;
}
void F_199 ( struct V_151 * V_462 ,
struct V_18 * V_521 )
{
if ( ! V_521 )
return;
if ( F_185 ( V_462 , V_478 ) ) {
if ( V_462 -> V_463 [ 0 ] == V_30 )
F_34 ( F_31 ( V_521 ) ) ;
}
}
int F_200 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_524 * V_525 = V_225 ;
struct V_526 V_527 = {
. V_479 = V_525 -> V_479 ,
. V_491 = V_525 -> V_491 ,
. V_528 = V_525 -> V_239 ,
. V_20 = V_101
} ;
return F_201 ( V_17 , & V_527 , V_227 ) ;
}
static int F_202 ( struct V_18 * V_19 ,
struct V_151 * V_462 ,
T_4 V_479 )
{
int V_22 = - V_79 ;
struct V_70 * V_71 = F_203 ( V_19 ) ;
if ( V_462 == V_71 -> V_17 -> V_23 . V_113 ) {
if ( V_71 -> V_34 -> V_529 )
(* V_71 -> V_34 -> V_529 )( V_71 , ( int ) V_479 ) ;
V_22 = 0 ;
} else if ( V_71 -> V_34 -> V_530 )
V_22 = V_71 -> V_34 -> V_530 ( V_71 , V_462 , V_479 ) ;
if ( ! V_22 )
F_186 ( & V_71 -> V_38 , V_462 , V_479 ) ;
return V_22 ;
}
static int F_204 ( struct V_18 * V_19 ,
struct V_151 * V_462 ,
T_4 V_479 )
{
int V_22 = - V_79 ;
struct V_45 * V_46 = F_205 ( V_19 ) ;
if ( V_46 -> V_34 -> V_530 )
V_22 = V_46 -> V_34 -> V_530 ( V_46 , V_462 , V_479 ) ;
if ( ! V_22 )
F_186 ( V_19 , V_462 , V_479 ) ;
return V_22 ;
}
int F_206 ( struct V_47 * V_48 ,
struct V_151 * V_462 ,
T_4 V_479 )
{
int V_22 = - V_79 ;
struct V_18 * V_19 = & V_48 -> V_38 ;
if ( V_48 -> V_34 -> V_530 )
V_22 = V_48 -> V_34 -> V_530 ( V_48 , V_462 , V_479 ) ;
if ( ! V_22 )
F_186 ( V_19 , V_462 , V_479 ) ;
return V_22 ;
}
int F_207 ( struct V_16 * V_17 , void * V_225 ,
struct V_226 * V_227 )
{
struct V_531 * V_532 = V_225 ;
struct V_18 * V_19 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
F_45 ( V_17 ) ;
V_19 = F_21 ( V_17 , V_532 -> V_528 , V_532 -> V_20 ) ;
if ( ! V_19 ) {
V_22 = - V_261 ;
goto V_39;
}
if ( ! V_19 -> V_59 ) {
V_22 = - V_79 ;
goto V_39;
}
V_22 = F_127 ( V_19 , V_227 -> V_269 ,
( T_1 T_3 * ) ( unsigned long ) ( V_532 -> V_295 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_532 -> V_296 ) ,
& V_532 -> V_297 ) ;
V_39:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_201 ( struct V_16 * V_17 , void * V_225 ,
struct V_226 * V_227 )
{
struct V_526 * V_532 = V_225 ;
struct V_18 * V_533 ;
struct V_18 * V_534 ;
struct V_151 * V_462 ;
int V_1 , V_22 = - V_79 ;
struct V_18 * V_521 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
F_45 ( V_17 ) ;
V_533 = F_21 ( V_17 , V_532 -> V_528 , V_532 -> V_20 ) ;
if ( ! V_533 ) {
V_22 = - V_261 ;
goto V_39;
}
if ( ! V_533 -> V_59 )
goto V_39;
for ( V_1 = 0 ; V_1 < V_533 -> V_59 -> V_274 ; V_1 ++ )
if ( V_533 -> V_59 -> V_59 [ V_1 ] -> V_38 . V_27 == V_532 -> V_491 )
break;
if ( V_1 == V_533 -> V_59 -> V_274 )
goto V_39;
V_534 = F_21 ( V_17 , V_532 -> V_491 ,
V_465 ) ;
if ( ! V_534 ) {
V_22 = - V_261 ;
goto V_39;
}
V_462 = F_208 ( V_534 ) ;
if ( ! F_197 ( V_462 , V_532 -> V_479 , & V_521 ) )
goto V_39;
switch ( V_533 -> type ) {
case V_101 :
V_22 = F_202 ( V_533 , V_462 ,
V_532 -> V_479 ) ;
break;
case V_58 :
V_22 = F_204 ( V_533 , V_462 , V_532 -> V_479 ) ;
break;
case V_131 :
V_22 = F_206 ( F_209 ( V_533 ) ,
V_462 , V_532 -> V_479 ) ;
break;
}
F_199 ( V_462 , V_521 ) ;
V_39:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_210 ( struct V_70 * V_71 ,
struct V_120 * V_121 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_284 ; V_1 ++ ) {
if ( V_71 -> V_285 [ V_1 ] == 0 ) {
V_71 -> V_285 [ V_1 ] = V_121 -> V_38 . V_27 ;
return 0 ;
}
}
return - V_80 ;
}
int F_211 ( struct V_45 * V_46 ,
int V_264 )
{
V_46 -> V_264 = V_264 ;
V_46 -> V_65 = F_109 ( V_264 , sizeof( V_535 ) * 3 ,
V_26 ) ;
if ( ! V_46 -> V_65 ) {
V_46 -> V_264 = 0 ;
return - V_80 ;
}
return 0 ;
}
int F_212 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_536 * V_537 = V_225 ;
struct V_45 * V_46 ;
void * V_538 , * V_539 , * V_540 ;
int V_505 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
F_45 ( V_17 ) ;
V_46 = F_121 ( V_17 , V_537 -> V_238 ) ;
if ( ! V_46 ) {
V_22 = - V_261 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_541 == NULL ) {
V_22 = - V_458 ;
goto V_39;
}
if ( V_537 -> V_264 != V_46 -> V_264 ) {
V_22 = - V_79 ;
goto V_39;
}
V_505 = V_537 -> V_264 * ( sizeof( V_535 ) ) ;
V_538 = V_46 -> V_65 ;
if ( F_176 ( V_538 , ( void T_3 * ) ( unsigned long ) V_537 -> V_542 , V_505 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_539 = V_538 + V_505 ;
if ( F_176 ( V_539 , ( void T_3 * ) ( unsigned long ) V_537 -> V_543 , V_505 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_540 = V_539 + V_505 ;
if ( F_176 ( V_540 , ( void T_3 * ) ( unsigned long ) V_537 -> V_544 , V_505 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_46 -> V_34 -> V_541 ( V_46 , V_538 , V_539 , V_540 , 0 , V_46 -> V_264 ) ;
V_39:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_213 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_536 * V_537 = V_225 ;
struct V_45 * V_46 ;
void * V_538 , * V_539 , * V_540 ;
int V_505 ;
int V_22 = 0 ;
if ( ! F_55 ( V_17 , V_241 ) )
return - V_79 ;
F_45 ( V_17 ) ;
V_46 = F_121 ( V_17 , V_537 -> V_238 ) ;
if ( ! V_46 ) {
V_22 = - V_261 ;
goto V_39;
}
if ( V_537 -> V_264 != V_46 -> V_264 ) {
V_22 = - V_79 ;
goto V_39;
}
V_505 = V_537 -> V_264 * ( sizeof( V_535 ) ) ;
V_538 = V_46 -> V_65 ;
if ( F_132 ( ( void T_3 * ) ( unsigned long ) V_537 -> V_542 , V_538 , V_505 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_539 = V_538 + V_505 ;
if ( F_132 ( ( void T_3 * ) ( unsigned long ) V_537 -> V_543 , V_539 , V_505 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_540 = V_539 + V_505 ;
if ( F_132 ( ( void T_3 * ) ( unsigned long ) V_537 -> V_544 , V_540 , V_505 ) ) {
V_22 = - V_245 ;
goto V_39;
}
V_39:
F_50 ( V_17 ) ;
return V_22 ;
}
int F_214 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_545 * V_546 = V_225 ;
struct V_45 * V_46 ;
struct V_31 * V_32 = NULL ;
struct V_547 * V_548 = NULL ;
unsigned long V_220 ;
int V_22 = - V_79 ;
if ( V_546 -> V_220 & ~ V_549 ||
V_546 -> V_550 != 0 )
return - V_79 ;
if ( ( V_546 -> V_220 & V_551 ) && ! V_17 -> V_23 . V_552 )
return - V_79 ;
V_46 = F_121 ( V_17 , V_546 -> V_238 ) ;
if ( ! V_46 )
return - V_261 ;
F_122 ( V_46 , V_46 -> V_51 ) ;
if ( V_46 -> V_51 -> V_32 == NULL ) {
V_22 = - V_553 ;
goto V_39;
}
if ( V_46 -> V_34 -> V_546 == NULL )
goto V_39;
V_32 = F_32 ( V_17 , V_546 -> V_237 ) ;
if ( ! V_32 ) {
V_22 = - V_261 ;
goto V_39;
}
V_22 = F_147 ( V_46 , V_46 -> V_262 , V_46 -> V_263 , & V_46 -> V_73 , V_32 ) ;
if ( V_22 )
goto V_39;
if ( V_46 -> V_51 -> V_32 -> V_325 != V_32 -> V_325 ) {
F_69 ( L_95 ) ;
V_22 = - V_79 ;
goto V_39;
}
if ( V_546 -> V_220 & V_554 ) {
V_22 = - V_80 ;
F_215 ( & V_17 -> V_555 , V_220 ) ;
if ( V_227 -> V_556 < sizeof( V_548 -> V_557 ) ) {
F_216 ( & V_17 -> V_555 , V_220 ) ;
goto V_39;
}
V_227 -> V_556 -= sizeof( V_548 -> V_557 ) ;
F_216 ( & V_17 -> V_555 , V_220 ) ;
V_548 = F_178 ( sizeof( * V_548 ) , V_26 ) ;
if ( V_548 == NULL ) {
F_215 ( & V_17 -> V_555 , V_220 ) ;
V_227 -> V_556 += sizeof( V_548 -> V_557 ) ;
F_216 ( & V_17 -> V_555 , V_220 ) ;
goto V_39;
}
V_548 -> V_557 . V_38 . type = V_558 ;
V_548 -> V_557 . V_38 . V_497 = sizeof( V_548 -> V_557 ) ;
V_548 -> V_557 . V_559 = V_546 -> V_559 ;
V_548 -> V_38 . V_557 = & V_548 -> V_557 . V_38 ;
V_548 -> V_38 . V_227 = V_227 ;
V_548 -> V_38 . V_44 =
( void ( * ) ( struct V_560 * ) ) F_58 ;
}
V_46 -> V_51 -> V_149 = V_46 -> V_51 -> V_32 ;
V_22 = V_46 -> V_34 -> V_546 ( V_46 , V_32 , V_548 , V_546 -> V_220 ) ;
if ( V_22 ) {
if ( V_546 -> V_220 & V_554 ) {
F_215 ( & V_17 -> V_555 , V_220 ) ;
V_227 -> V_556 += sizeof( V_548 -> V_557 ) ;
F_216 ( & V_17 -> V_555 , V_220 ) ;
F_58 ( V_548 ) ;
}
V_46 -> V_51 -> V_149 = NULL ;
} else {
F_22 ( V_46 -> V_51 -> V_32 != V_32 ) ;
V_32 = NULL ;
}
V_39:
if ( V_32 )
F_34 ( V_32 ) ;
if ( V_46 -> V_51 -> V_149 )
F_34 ( V_46 -> V_51 -> V_149 ) ;
V_46 -> V_51 -> V_149 = NULL ;
F_123 ( V_46 ) ;
return V_22 ;
}
void F_217 ( struct V_16 * V_17 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_120 * V_121 ;
struct V_70 * V_71 ;
F_46 (plane, &dev->mode_config.plane_list, head)
if ( V_48 -> V_34 -> V_561 )
V_48 -> V_34 -> V_561 ( V_48 ) ;
F_46 (crtc, &dev->mode_config.crtc_list, head)
if ( V_46 -> V_34 -> V_561 )
V_46 -> V_34 -> V_561 ( V_46 ) ;
F_46 (encoder, &dev->mode_config.encoder_list, head)
if ( V_121 -> V_34 -> V_561 )
V_121 -> V_34 -> V_561 ( V_121 ) ;
F_46 (connector, &dev->mode_config.connector_list, head) {
V_71 -> V_5 = V_108 ;
if ( V_71 -> V_34 -> V_561 )
V_71 -> V_34 -> V_561 ( V_71 ) ;
}
}
int F_218 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_562 * args = V_225 ;
T_2 V_433 , V_563 , V_505 ;
if ( ! V_17 -> V_564 -> V_565 )
return - V_458 ;
if ( ! args -> V_326 || ! args -> V_327 || ! args -> V_365 )
return - V_79 ;
V_433 = F_219 ( args -> V_365 , 8 ) ;
if ( ! V_433 || V_433 > 0xffffffffU / args -> V_326 )
return - V_79 ;
V_563 = V_433 * args -> V_326 ;
if ( args -> V_327 > 0xffffffffU / V_563 )
return - V_79 ;
V_505 = args -> V_327 * V_563 ;
if ( F_220 ( V_505 ) == 0 )
return - V_79 ;
args -> V_351 = 0 ;
args -> V_377 = 0 ;
args -> V_505 = 0 ;
return V_17 -> V_564 -> V_565 ( V_227 , V_17 , args ) ;
}
int F_221 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_566 * args = V_225 ;
if ( ! V_17 -> V_564 -> V_567 )
return - V_458 ;
return V_17 -> V_564 -> V_567 ( V_227 , V_17 , args -> V_351 , & args -> V_568 ) ;
}
int F_222 ( struct V_16 * V_17 ,
void * V_225 , struct V_226 * V_227 )
{
struct V_569 * args = V_225 ;
if ( ! V_17 -> V_564 -> V_570 )
return - V_458 ;
return V_17 -> V_564 -> V_570 ( V_227 , V_17 , args -> V_351 ) ;
}
void F_223 ( T_1 V_13 , unsigned int * V_366 ,
int * V_365 )
{
switch ( V_13 ) {
case V_368 :
case V_378 :
case V_379 :
* V_366 = 8 ;
* V_365 = 8 ;
break;
case V_369 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
* V_366 = 15 ;
* V_365 = 16 ;
break;
case V_370 :
case V_395 :
* V_366 = 16 ;
* V_365 = 16 ;
break;
case V_371 :
case V_396 :
* V_366 = 24 ;
* V_365 = 24 ;
break;
case V_372 :
case V_397 :
case V_398 :
case V_399 :
* V_366 = 24 ;
* V_365 = 32 ;
break;
case V_373 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
* V_366 = 30 ;
* V_365 = 32 ;
break;
case V_348 :
case V_400 :
case V_401 :
case V_402 :
* V_366 = 32 ;
* V_365 = 32 ;
break;
default:
F_69 ( L_96 ,
F_9 ( V_13 ) ) ;
* V_366 = 0 ;
* V_365 = 0 ;
break;
}
}
int F_167 ( T_1 V_13 )
{
switch ( V_13 ) {
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
return 3 ;
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
return 2 ;
default:
return 1 ;
}
}
int F_168 ( T_1 V_13 , int V_48 )
{
unsigned int V_366 ;
int V_365 ;
if ( V_48 >= F_167 ( V_13 ) )
return 0 ;
switch ( V_13 ) {
case V_410 :
case V_411 :
case V_412 :
case V_413 :
return 2 ;
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
return V_48 ? 2 : 1 ;
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
return 1 ;
default:
F_223 ( V_13 , & V_366 , & V_365 ) ;
return V_365 >> 3 ;
}
}
int F_165 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_423 :
case V_424 :
case V_421 :
case V_422 :
return 4 ;
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_427 :
case V_428 :
case V_425 :
case V_426 :
return 2 ;
default:
return 1 ;
}
}
int F_166 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_421 :
case V_422 :
return 4 ;
case V_425 :
case V_426 :
case V_415 :
case V_416 :
return 2 ;
default:
return 1 ;
}
}
unsigned int F_224 ( unsigned int V_571 ,
unsigned int V_572 )
{
if ( V_571 & ~ V_572 ) {
V_571 ^= F_225 ( V_573 ) | F_225 ( V_574 ) ;
V_571 = ( V_571 & ~ 0xf ) | F_225 ( ( F_226 ( V_571 & 0xf ) + 1 ) % 4 ) ;
}
return V_571 ;
}
void F_227 ( struct V_16 * V_17 )
{
F_228 ( & V_17 -> V_23 . V_57 ) ;
F_52 ( & V_17 -> V_23 . V_119 ) ;
F_228 ( & V_17 -> V_23 . V_24 ) ;
F_228 ( & V_17 -> V_23 . V_35 ) ;
F_25 ( & V_17 -> V_23 . V_42 ) ;
F_25 ( & V_17 -> V_23 . V_60 ) ;
F_25 ( & V_17 -> V_23 . V_109 ) ;
F_25 ( & V_17 -> V_23 . V_126 ) ;
F_25 ( & V_17 -> V_23 . V_468 ) ;
F_25 ( & V_17 -> V_23 . V_500 ) ;
F_25 ( & V_17 -> V_23 . V_133 ) ;
F_229 ( & V_17 -> V_23 . V_25 ) ;
F_229 ( & V_17 -> V_23 . V_575 ) ;
F_45 ( V_17 ) ;
F_94 ( V_17 ) ;
F_50 ( V_17 ) ;
V_17 -> V_23 . V_40 = 0 ;
V_17 -> V_23 . V_110 = 0 ;
V_17 -> V_23 . V_61 = 0 ;
V_17 -> V_23 . V_127 = 0 ;
V_17 -> V_23 . V_136 = 0 ;
V_17 -> V_23 . V_134 = 0 ;
}
void F_230 ( struct V_16 * V_17 )
{
struct V_70 * V_71 , * V_576 ;
struct V_45 * V_46 , * V_577 ;
struct V_120 * V_121 , * V_578 ;
struct V_31 * V_32 , * V_579 ;
struct V_151 * V_462 , * V_482 ;
struct V_496 * V_498 , * V_580 ;
struct V_47 * V_48 , * V_581 ;
F_75 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_121 -> V_34 -> V_44 ( V_121 ) ;
}
F_75 (connector, ot,
&dev->mode_config.connector_list, head) {
V_71 -> V_34 -> V_44 ( V_71 ) ;
}
F_75 (property, pt, &dev->mode_config.property_list,
head) {
F_180 ( V_17 , V_462 ) ;
}
F_75 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_191 ( V_17 , V_498 ) ;
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
F_231 ( & V_17 -> V_23 . V_575 ) ;
F_231 ( & V_17 -> V_23 . V_25 ) ;
F_59 ( & V_17 -> V_23 . V_119 ) ;
}
struct V_151 * F_232 ( struct V_16 * V_17 ,
unsigned int V_572 )
{
static const struct V_469 V_470 [] = {
{ V_582 , L_97 } ,
{ V_583 , L_98 } ,
{ V_584 , L_99 } ,
{ V_585 , L_100 } ,
{ V_573 , L_101 } ,
{ V_574 , L_102 } ,
} ;
return F_181 ( V_17 , 0 , L_103 ,
V_470 , F_2 ( V_470 ) ,
V_572 ) ;
}
static void F_233 ( struct V_43 * V_43 )
{
struct V_586 * V_587 = F_29 ( V_43 , struct V_586 , V_36 ) ;
struct V_16 * V_17 = V_587 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_575 , V_587 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
F_58 ( V_587 ) ;
}
void F_74 ( struct V_16 * V_17 ,
struct V_586 * V_587 )
{
F_37 ( & V_587 -> V_36 , F_233 ) ;
}
struct V_586 * F_234 ( struct V_16 * V_17 ,
char V_588 [ 8 ] )
{
struct V_586 * V_587 ;
int V_27 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_235 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_587 -> V_589 , V_588 , 8 ) ) {
if ( ! F_33 ( & V_587 -> V_36 ) )
V_587 = NULL ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_587 ;
}
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return NULL ;
}
struct V_586 * F_236 ( struct V_16 * V_17 ,
char V_588 [ 8 ] )
{
struct V_586 * V_587 ;
int V_22 ;
V_587 = F_178 ( sizeof( * V_587 ) , V_26 ) ;
if ( ! V_587 )
return F_169 ( - V_80 ) ;
F_24 ( & V_587 -> V_36 ) ;
memcpy ( V_587 -> V_589 , V_588 , 8 ) ;
V_587 -> V_17 = V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_22 = F_12 ( & V_17 -> V_23 . V_575 , V_587 , 1 , 0 , V_26 ) ;
if ( V_22 >= 0 ) {
V_587 -> V_27 = V_22 ;
} else {
F_58 ( V_587 ) ;
V_587 = F_169 ( V_22 ) ;
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_587 ;
}
