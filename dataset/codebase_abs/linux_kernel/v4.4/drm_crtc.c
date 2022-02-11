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
return V_22 ;
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
struct V_16 * V_17 ;
if ( ! V_33 )
return;
V_17 = V_33 -> V_17 ;
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
struct V_16 * V_17 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 V_51 ;
int V_22 ;
if ( ! V_33 )
return;
V_17 = V_33 -> V_17 ;
F_22 ( ! F_44 ( & V_33 -> V_38 ) ) ;
if ( F_36 ( & V_33 -> V_37 . V_37 ) > 1 ) {
F_45 ( V_17 ) ;
F_46 (crtc, dev) {
if ( V_47 -> V_52 -> V_33 == V_33 ) {
memset ( & V_51 , 0 , sizeof( struct V_50 ) ) ;
V_51 . V_47 = V_47 ;
V_51 . V_33 = NULL ;
V_22 = F_47 ( & V_51 ) ;
if ( V_22 )
F_48 ( L_8 , V_47 ) ;
}
}
F_49 (plane, dev) {
if ( V_49 -> V_33 == V_33 )
F_50 ( V_49 ) ;
}
F_51 ( V_17 ) ;
}
F_34 ( V_33 ) ;
}
int F_52 ( struct V_16 * V_17 , struct V_46 * V_47 ,
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
F_53 ( & V_47 -> V_59 ) ;
V_22 = F_14 ( V_17 , & V_47 -> V_39 , V_60 ) ;
if ( V_22 )
return V_22 ;
V_47 -> V_39 . V_61 = & V_47 -> V_61 ;
F_54 ( & V_47 -> V_42 , & V_56 -> V_62 ) ;
V_56 -> V_63 ++ ;
V_47 -> V_52 = V_52 ;
V_47 -> V_53 = V_53 ;
if ( V_52 )
V_52 -> V_64 = 1 << F_55 ( V_47 ) ;
if ( V_53 )
V_53 -> V_64 = 1 << F_55 ( V_47 ) ;
if ( F_56 ( V_17 , V_65 ) ) {
F_57 ( & V_47 -> V_39 , V_56 -> V_66 , 0 ) ;
F_57 ( & V_47 -> V_39 , V_56 -> V_67 , 0 ) ;
}
return 0 ;
}
void F_58 ( struct V_46 * V_47 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
F_59 ( V_47 -> V_68 ) ;
V_47 -> V_68 = NULL ;
F_60 ( & V_47 -> V_59 ) ;
F_17 ( V_17 , & V_47 -> V_39 ) ;
F_42 ( & V_47 -> V_42 ) ;
V_17 -> V_23 . V_63 -- ;
F_22 ( V_47 -> V_69 && ! V_47 -> V_35 -> V_70 ) ;
if ( V_47 -> V_69 && V_47 -> V_35 -> V_70 )
V_47 -> V_35 -> V_70 ( V_47 , V_47 -> V_69 ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
}
unsigned int F_55 ( struct V_46 * V_47 )
{
unsigned int V_71 = 0 ;
struct V_46 * V_72 ;
F_46 (tmp, crtc->dev) {
if ( V_72 == V_47 )
return V_71 ;
V_71 ++ ;
}
F_61 () ;
}
static void F_62 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
F_42 ( & V_76 -> V_42 ) ;
F_63 ( V_74 -> V_17 , V_76 ) ;
}
int F_64 ( struct V_77 * V_78 ,
const T_2 * V_79 ,
unsigned int V_80 )
{
T_2 * V_81 = NULL ;
if ( ! V_79 && V_80 )
return - V_82 ;
if ( V_79 && V_80 ) {
V_81 = F_65 ( V_79 , sizeof( * V_79 ) * V_80 ,
V_26 ) ;
if ( ! V_81 )
return - V_83 ;
}
F_59 ( V_78 -> V_84 ) ;
V_78 -> V_84 = V_81 ;
V_78 -> V_85 = V_80 ;
return 0 ;
}
static void F_66 ( struct V_73 * V_74 )
{
struct V_86 * V_76 = & V_74 -> V_87 ;
char * V_88 = NULL ;
if ( F_67 ( V_74 -> V_11 , & V_88 ) )
return;
if ( ! F_68 ( V_88 ,
V_74 ,
V_76 ) )
return;
if ( V_76 -> V_89 ) {
const char * V_90 ;
switch ( V_76 -> V_89 ) {
case V_91 :
V_90 = L_9 ;
break;
case V_92 :
V_90 = L_10 ;
break;
default:
case V_93 :
V_90 = L_11 ;
break;
}
F_69 ( L_12 , V_74 -> V_11 , V_90 ) ;
V_74 -> V_89 = V_76 -> V_89 ;
}
F_70 ( L_13 ,
V_74 -> V_11 ,
V_76 -> V_94 , V_76 -> V_95 ,
V_76 -> V_96 ? V_76 -> V_97 : 60 ,
V_76 -> V_98 ? L_14 : L_15 ,
V_76 -> V_99 ? L_16 : L_15 ,
V_76 -> V_100 ? L_17 : L_15 ) ;
}
int F_71 ( struct V_16 * V_17 ,
struct V_73 * V_74 ,
const struct V_101 * V_35 ,
int V_102 )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
int V_22 ;
struct V_3 * V_103 =
& V_2 [ V_102 ] . V_3 ;
F_45 ( V_17 ) ;
V_22 = F_10 ( V_17 , & V_74 -> V_39 , V_104 , false ) ;
if ( V_22 )
goto V_105;
V_74 -> V_39 . V_61 = & V_74 -> V_61 ;
V_74 -> V_17 = V_17 ;
V_74 -> V_35 = V_35 ;
V_74 -> V_102 = V_102 ;
V_74 -> V_106 =
F_72 ( V_103 , 1 , 0 , V_26 ) ;
if ( V_74 -> V_106 < 0 ) {
V_22 = V_74 -> V_106 ;
goto V_107;
}
V_74 -> V_11 =
F_73 ( V_26 , L_18 ,
V_2 [ V_102 ] . V_11 ,
V_74 -> V_106 ) ;
if ( ! V_74 -> V_11 ) {
V_22 = - V_83 ;
goto V_107;
}
F_25 ( & V_74 -> V_108 ) ;
F_25 ( & V_74 -> V_109 ) ;
V_74 -> V_110 = NULL ;
V_74 -> V_5 = V_111 ;
F_66 ( V_74 ) ;
F_54 ( & V_74 -> V_42 , & V_56 -> V_112 ) ;
V_56 -> V_113 ++ ;
if ( V_102 != V_114 )
F_57 ( & V_74 -> V_39 ,
V_56 -> V_115 ,
0 ) ;
F_57 ( & V_74 -> V_39 ,
V_56 -> V_116 , 0 ) ;
if ( F_56 ( V_17 , V_65 ) ) {
F_57 ( & V_74 -> V_39 , V_56 -> V_117 , 0 ) ;
}
V_74 -> V_118 = NULL ;
V_107:
if ( V_22 )
F_17 ( V_17 , & V_74 -> V_39 ) ;
V_105:
F_51 ( V_17 ) ;
return V_22 ;
}
void F_74 ( struct V_73 * V_74 )
{
struct V_16 * V_17 = V_74 -> V_17 ;
struct V_75 * V_76 , * V_119 ;
if ( V_74 -> V_120 ) {
F_75 ( V_17 , V_74 -> V_120 ) ;
V_74 -> V_120 = NULL ;
}
F_76 (mode, t, &connector->probed_modes, head)
F_62 ( V_74 , V_76 ) ;
F_76 (mode, t, &connector->modes, head)
F_62 ( V_74 , V_76 ) ;
F_77 ( & V_2 [ V_74 -> V_102 ] . V_3 ,
V_74 -> V_106 ) ;
F_59 ( V_74 -> V_121 . V_84 ) ;
F_17 ( V_17 , & V_74 -> V_39 ) ;
F_59 ( V_74 -> V_11 ) ;
V_74 -> V_11 = NULL ;
F_42 ( & V_74 -> V_42 ) ;
V_17 -> V_23 . V_113 -- ;
F_22 ( V_74 -> V_69 && ! V_74 -> V_35 -> V_70 ) ;
if ( V_74 -> V_69 && V_74 -> V_35 -> V_70 )
V_74 -> V_35 -> V_70 ( V_74 ,
V_74 -> V_69 ) ;
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
}
unsigned int F_78 ( struct V_73 * V_74 )
{
unsigned int V_71 = 0 ;
struct V_73 * V_72 ;
struct V_55 * V_56 = & V_74 -> V_17 -> V_23 ;
F_22 ( ! F_79 ( & V_56 -> V_122 ) ) ;
F_80 (tmp, connector->dev) {
if ( V_72 == V_74 )
return V_71 ;
V_71 ++ ;
}
F_61 () ;
}
int F_81 ( struct V_73 * V_74 )
{
int V_22 ;
F_15 ( V_74 -> V_17 , & V_74 -> V_39 ) ;
V_22 = F_82 ( V_74 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_83 ( V_74 ) ;
if ( V_22 ) {
F_84 ( V_74 ) ;
return V_22 ;
}
return 0 ;
}
void F_85 ( struct V_73 * V_74 )
{
F_84 ( V_74 ) ;
F_86 ( V_74 ) ;
}
void F_87 ( struct V_16 * V_17 )
{
struct V_73 * V_74 ;
F_88 (connector, &dev->mode_config.connector_list, head)
F_85 ( V_74 ) ;
}
int F_89 ( struct V_16 * V_17 ,
struct V_123 * V_124 ,
const struct V_125 * V_35 ,
int V_126 )
{
int V_22 ;
F_45 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_124 -> V_39 , V_127 ) ;
if ( V_22 )
goto V_105;
V_124 -> V_17 = V_17 ;
V_124 -> V_126 = V_126 ;
V_124 -> V_35 = V_35 ;
V_124 -> V_11 = F_73 ( V_26 , L_18 ,
V_128 [ V_126 ] . V_11 ,
V_124 -> V_39 . V_27 ) ;
if ( ! V_124 -> V_11 ) {
V_22 = - V_83 ;
goto V_107;
}
F_54 ( & V_124 -> V_42 , & V_17 -> V_23 . V_129 ) ;
V_17 -> V_23 . V_130 ++ ;
V_107:
if ( V_22 )
F_17 ( V_17 , & V_124 -> V_39 ) ;
V_105:
F_51 ( V_17 ) ;
return V_22 ;
}
void F_90 ( struct V_123 * V_124 )
{
struct V_16 * V_17 = V_124 -> V_17 ;
F_45 ( V_17 ) ;
F_17 ( V_17 , & V_124 -> V_39 ) ;
F_59 ( V_124 -> V_11 ) ;
F_42 ( & V_124 -> V_42 ) ;
V_17 -> V_23 . V_130 -- ;
F_51 ( V_17 ) ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
}
int F_91 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_64 ,
const struct V_131 * V_35 ,
const T_1 * V_79 , unsigned int V_132 ,
enum V_133 type )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
int V_22 ;
V_22 = F_14 ( V_17 , & V_49 -> V_39 , V_134 ) ;
if ( V_22 )
return V_22 ;
F_53 ( & V_49 -> V_59 ) ;
V_49 -> V_39 . V_61 = & V_49 -> V_61 ;
V_49 -> V_17 = V_17 ;
V_49 -> V_35 = V_35 ;
V_49 -> V_135 = F_92 ( V_132 , sizeof( T_1 ) ,
V_26 ) ;
if ( ! V_49 -> V_135 ) {
F_70 ( L_19 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
return - V_83 ;
}
memcpy ( V_49 -> V_135 , V_79 , V_132 * sizeof( T_1 ) ) ;
V_49 -> V_132 = V_132 ;
V_49 -> V_64 = V_64 ;
V_49 -> type = type ;
F_54 ( & V_49 -> V_42 , & V_56 -> V_136 ) ;
V_56 -> V_137 ++ ;
if ( V_49 -> type == V_138 )
V_56 -> V_139 ++ ;
F_57 ( & V_49 -> V_39 ,
V_56 -> V_140 ,
V_49 -> type ) ;
if ( F_56 ( V_17 , V_65 ) ) {
F_57 ( & V_49 -> V_39 , V_56 -> V_141 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_117 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_142 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_143 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_144 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_145 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_146 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_147 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_148 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_149 , 0 ) ;
}
return 0 ;
}
int F_93 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_64 ,
const struct V_131 * V_35 ,
const T_1 * V_79 , unsigned int V_132 ,
bool V_150 )
{
enum V_133 type ;
type = V_150 ? V_57 : V_138 ;
return F_91 ( V_17 , V_49 , V_64 , V_35 ,
V_79 , V_132 , type ) ;
}
void F_94 ( struct V_48 * V_49 )
{
struct V_16 * V_17 = V_49 -> V_17 ;
F_45 ( V_17 ) ;
F_59 ( V_49 -> V_135 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
F_95 ( F_44 ( & V_49 -> V_42 ) ) ;
F_42 ( & V_49 -> V_42 ) ;
V_17 -> V_23 . V_137 -- ;
if ( V_49 -> type == V_138 )
V_17 -> V_23 . V_139 -- ;
F_51 ( V_17 ) ;
F_22 ( V_49 -> V_69 && ! V_49 -> V_35 -> V_70 ) ;
if ( V_49 -> V_69 && V_49 -> V_35 -> V_70 )
V_49 -> V_35 -> V_70 ( V_49 , V_49 -> V_69 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
}
unsigned int F_96 ( struct V_48 * V_49 )
{
unsigned int V_71 = 0 ;
struct V_48 * V_72 ;
F_49 (tmp, plane->dev) {
if ( V_72 == V_49 )
return V_71 ;
V_71 ++ ;
}
F_61 () ;
}
struct V_48 *
F_97 ( struct V_16 * V_17 , int V_151 )
{
struct V_48 * V_49 ;
unsigned int V_1 = 0 ;
F_49 (plane, dev) {
if ( V_1 == V_151 )
return V_49 ;
V_1 ++ ;
}
return NULL ;
}
void F_50 ( struct V_48 * V_49 )
{
int V_22 ;
if ( ! V_49 -> V_33 )
return;
V_49 -> V_152 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_153 ( V_49 ) ;
if ( V_22 ) {
F_48 ( L_20 ) ;
V_49 -> V_152 = NULL ;
return;
}
F_34 ( V_49 -> V_152 ) ;
V_49 -> V_152 = NULL ;
V_49 -> V_33 = NULL ;
V_49 -> V_47 = NULL ;
}
static int F_98 ( struct V_16 * V_17 )
{
struct V_154 * V_155 ;
V_155 = F_99 ( V_17 , V_156 |
V_157 ,
L_21 , 0 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_115 = V_155 ;
V_155 = F_100 ( V_17 , 0 ,
L_22 , V_158 ,
F_2 ( V_158 ) ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_116 = V_155 ;
V_155 = F_99 ( V_17 ,
V_156 |
V_157 ,
L_23 , 0 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_159 = V_155 ;
V_155 = F_99 ( V_17 ,
V_156 |
V_157 ,
L_24 , 0 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_160 = V_155 ;
V_155 = F_100 ( V_17 , V_157 ,
L_25 , V_161 ,
F_2 ( V_161 ) ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_140 = V_155 ;
V_155 = F_101 ( V_17 , V_162 ,
L_26 , 0 , V_163 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_146 = V_155 ;
V_155 = F_101 ( V_17 , V_162 ,
L_27 , 0 , V_163 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_147 = V_155 ;
V_155 = F_101 ( V_17 , V_162 ,
L_28 , 0 , V_163 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_148 = V_155 ;
V_155 = F_101 ( V_17 , V_162 ,
L_29 , 0 , V_163 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_149 = V_155 ;
V_155 = F_102 ( V_17 , V_162 ,
L_30 , V_164 , V_165 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_142 = V_155 ;
V_155 = F_102 ( V_17 , V_162 ,
L_31 , V_164 , V_165 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_143 = V_155 ;
V_155 = F_101 ( V_17 , V_162 ,
L_32 , 0 , V_165 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_144 = V_155 ;
V_155 = F_101 ( V_17 , V_162 ,
L_33 , 0 , V_165 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_145 = V_155 ;
V_155 = F_103 ( V_17 , V_162 ,
L_34 , V_30 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_141 = V_155 ;
V_155 = F_103 ( V_17 , V_162 ,
L_35 , V_60 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_117 = V_155 ;
V_155 = F_104 ( V_17 , V_162 ,
L_36 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_66 = V_155 ;
V_155 = F_99 ( V_17 ,
V_162 | V_156 ,
L_37 , 0 ) ;
if ( ! V_155 )
return - V_83 ;
V_17 -> V_23 . V_67 = V_155 ;
return 0 ;
}
int F_105 ( struct V_16 * V_17 )
{
struct V_154 * V_166 ;
struct V_154 * V_167 ;
if ( V_17 -> V_23 . V_168 )
return 0 ;
V_166 =
F_100 ( V_17 , 0 ,
L_38 ,
V_169 ,
F_2 ( V_169 ) ) ;
V_17 -> V_23 . V_168 = V_166 ;
V_167 = F_100 ( V_17 , V_157 ,
L_39 ,
V_170 ,
F_2 ( V_170 ) ) ;
V_17 -> V_23 . V_171 = V_167 ;
return 0 ;
}
int F_106 ( struct V_16 * V_17 ,
unsigned int V_172 ,
const char * const V_109 [] )
{
struct V_154 * V_173 ;
struct V_154 * V_174 ;
unsigned int V_1 ;
if ( V_17 -> V_23 . V_175 )
return 0 ;
V_173 = F_100 ( V_17 , 0 ,
L_38 ,
V_176 ,
F_2 ( V_176 ) ) ;
if ( ! V_173 )
goto V_177;
V_17 -> V_23 . V_175 = V_173 ;
V_174 =
F_100 ( V_17 , V_157 ,
L_39 ,
V_178 ,
F_2 ( V_178 ) ) ;
if ( ! V_174 )
goto V_177;
V_17 -> V_23 . V_179 = V_174 ;
V_17 -> V_23 . V_180 =
F_101 ( V_17 , 0 , L_40 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_180 )
goto V_177;
V_17 -> V_23 . V_181 =
F_101 ( V_17 , 0 , L_41 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_181 )
goto V_177;
V_17 -> V_23 . V_182 =
F_101 ( V_17 , 0 , L_42 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_182 )
goto V_177;
V_17 -> V_23 . V_183 =
F_101 ( V_17 , 0 , L_43 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_183 )
goto V_177;
V_17 -> V_23 . V_184 =
F_99 ( V_17 , V_185 ,
L_44 , V_172 ) ;
if ( ! V_17 -> V_23 . V_184 )
goto V_177;
for ( V_1 = 0 ; V_1 < V_172 ; V_1 ++ )
F_107 ( V_17 -> V_23 . V_184 , V_1 ,
V_1 , V_109 [ V_1 ] ) ;
V_17 -> V_23 . V_186 =
F_101 ( V_17 , 0 , L_45 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_186 )
goto V_177;
V_17 -> V_23 . V_187 =
F_101 ( V_17 , 0 , L_46 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_187 )
goto V_177;
V_17 -> V_23 . V_188 =
F_101 ( V_17 , 0 , L_47 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_188 )
goto V_177;
V_17 -> V_23 . V_189 =
F_101 ( V_17 , 0 , L_48 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_189 )
goto V_177;
V_17 -> V_23 . V_190 =
F_101 ( V_17 , 0 , L_49 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_190 )
goto V_177;
V_17 -> V_23 . V_191 =
F_101 ( V_17 , 0 , L_50 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_191 )
goto V_177;
return 0 ;
V_177:
return - V_83 ;
}
int F_108 ( struct V_16 * V_17 )
{
struct V_154 * V_192 ;
if ( V_17 -> V_23 . V_193 )
return 0 ;
V_192 =
F_100 ( V_17 , 0 , L_51 ,
V_194 ,
F_2 ( V_194 ) ) ;
V_17 -> V_23 . V_193 = V_192 ;
return 0 ;
}
int F_109 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_195 )
return 0 ;
V_17 -> V_23 . V_195 =
F_100 ( V_17 , 0 , L_52 ,
V_196 ,
F_2 ( V_196 ) ) ;
if ( V_17 -> V_23 . V_195 == NULL )
return - V_83 ;
return 0 ;
}
int F_110 ( struct V_16 * V_17 )
{
struct V_154 * V_197 ;
if ( V_17 -> V_23 . V_198 )
return 0 ;
V_197 =
F_100 ( V_17 , V_157 ,
L_53 ,
V_199 ,
F_2 ( V_199 ) ) ;
V_17 -> V_23 . V_198 = V_197 ;
return 0 ;
}
int F_111 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_200 && V_17 -> V_23 . V_201 )
return 0 ;
V_17 -> V_23 . V_200 =
F_101 ( V_17 , V_157 , L_54 , 0 , 0xffffffff ) ;
V_17 -> V_23 . V_201 =
F_101 ( V_17 , V_157 , L_55 , 0 , 0xffffffff ) ;
if ( V_17 -> V_23 . V_200 == NULL ||
V_17 -> V_23 . V_201 == NULL )
return - V_83 ;
return 0 ;
}
int F_112 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_205 * V_206 = V_202 ;
struct V_207 * V_208 ;
struct V_32 * V_33 ;
struct V_73 * V_74 ;
struct V_46 * V_47 ;
struct V_123 * V_124 ;
int V_22 = 0 ;
int V_209 = 0 ;
int V_210 = 0 ;
int V_211 = 0 ;
int V_212 = 0 ;
int V_213 = 0 ;
T_1 T_3 * V_214 ;
T_1 T_3 * V_215 ;
T_1 T_3 * V_216 ;
T_1 T_3 * V_217 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
F_11 ( & V_204 -> V_219 ) ;
F_113 (lh, &file_priv->fbs)
V_211 ++ ;
if ( V_206 -> V_220 >= V_211 ) {
V_213 = 0 ;
V_214 = ( T_1 T_3 * ) ( unsigned long ) V_206 -> V_221 ;
F_88 (fb, &file_priv->fbs, filp_head) {
if ( F_114 ( V_33 -> V_39 . V_27 , V_214 + V_213 ) ) {
F_13 ( & V_204 -> V_219 ) ;
return - V_222 ;
}
V_213 ++ ;
}
}
V_206 -> V_220 = V_211 ;
F_13 ( & V_204 -> V_219 ) ;
F_11 ( & V_17 -> V_23 . V_59 ) ;
F_46 (crtc, dev)
V_210 ++ ;
F_80 (connector, dev)
V_209 ++ ;
F_115 (encoder, dev)
V_212 ++ ;
V_206 -> V_223 = V_17 -> V_23 . V_223 ;
V_206 -> V_224 = V_17 -> V_23 . V_224 ;
V_206 -> V_225 = V_17 -> V_23 . V_225 ;
V_206 -> V_226 = V_17 -> V_23 . V_226 ;
if ( V_206 -> V_227 >= V_210 ) {
V_213 = 0 ;
V_215 = ( T_1 T_3 * ) ( unsigned long ) V_206 -> V_228 ;
F_46 (crtc, dev) {
F_70 ( L_56 , V_47 -> V_39 . V_27 ) ;
if ( F_114 ( V_47 -> V_39 . V_27 , V_215 + V_213 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_213 ++ ;
}
}
V_206 -> V_227 = V_210 ;
if ( V_206 -> V_229 >= V_212 ) {
V_213 = 0 ;
V_217 = ( T_1 T_3 * ) ( unsigned long ) V_206 -> V_230 ;
F_115 (encoder, dev) {
F_70 ( L_57 , V_124 -> V_39 . V_27 ,
V_124 -> V_11 ) ;
if ( F_114 ( V_124 -> V_39 . V_27 , V_217 +
V_213 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_213 ++ ;
}
}
V_206 -> V_229 = V_212 ;
if ( V_206 -> V_231 >= V_209 ) {
V_213 = 0 ;
V_216 = ( T_1 T_3 * ) ( unsigned long ) V_206 -> V_232 ;
F_80 (connector, dev) {
F_70 ( L_58 ,
V_74 -> V_39 . V_27 ,
V_74 -> V_11 ) ;
if ( F_114 ( V_74 -> V_39 . V_27 ,
V_216 + V_213 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_213 ++ ;
}
}
V_206 -> V_231 = V_209 ;
F_70 ( L_59 , V_206 -> V_227 ,
V_206 -> V_231 , V_206 -> V_229 ) ;
V_40:
F_13 ( & V_17 -> V_23 . V_59 ) ;
return V_22 ;
}
int F_116 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_233 * V_234 = V_202 ;
struct V_46 * V_47 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
V_47 = F_117 ( V_17 , V_234 -> V_215 ) ;
if ( ! V_47 )
return - V_235 ;
F_118 ( V_47 , V_47 -> V_52 ) ;
V_234 -> V_236 = V_47 -> V_236 ;
if ( V_47 -> V_52 -> V_33 )
V_234 -> V_214 = V_47 -> V_52 -> V_33 -> V_39 . V_27 ;
else
V_234 -> V_214 = 0 ;
if ( V_47 -> V_69 ) {
V_234 -> V_237 = V_47 -> V_52 -> V_69 -> V_238 >> 16 ;
V_234 -> V_239 = V_47 -> V_52 -> V_69 -> V_240 >> 16 ;
if ( V_47 -> V_69 -> V_241 ) {
F_119 ( & V_234 -> V_76 , & V_47 -> V_69 -> V_76 ) ;
V_234 -> V_242 = 1 ;
} else {
V_234 -> V_242 = 0 ;
}
} else {
V_234 -> V_237 = V_47 -> V_237 ;
V_234 -> V_239 = V_47 -> V_239 ;
if ( V_47 -> V_243 ) {
F_119 ( & V_234 -> V_76 , & V_47 -> V_76 ) ;
V_234 -> V_242 = 1 ;
} else {
V_234 -> V_242 = 0 ;
}
}
F_120 ( V_47 ) ;
return 0 ;
}
static bool F_121 ( const struct V_75 * V_76 ,
const struct V_203 * V_204 )
{
if ( ! V_204 -> V_244 && F_122 ( V_76 ) )
return false ;
return true ;
}
static struct V_123 * F_123 ( struct V_73 * V_74 )
{
if ( V_74 -> V_69 )
return V_74 -> V_69 -> V_245 ;
return V_74 -> V_124 ;
}
static int F_124 ( struct V_18 * V_19 , bool V_246 ,
T_1 T_3 * V_247 , T_4 T_3 * V_248 ,
T_1 * V_249 )
{
int V_250 ;
int V_1 , V_22 , V_213 ;
V_250 = V_19 -> V_61 -> V_251 ;
if ( ! V_246 )
V_250 -= V_19 -> V_61 -> V_252 ;
if ( ( * V_249 >= V_250 ) && V_250 ) {
for ( V_1 = 0 , V_213 = 0 ; V_213 < V_250 ; V_1 ++ ) {
struct V_154 * V_155 = V_19 -> V_61 -> V_61 [ V_1 ] ;
T_4 V_253 ;
if ( ( V_155 -> V_254 & V_162 ) && ! V_246 )
continue;
V_22 = F_125 ( V_19 , V_155 , & V_253 ) ;
if ( V_22 )
return V_22 ;
if ( F_114 ( V_155 -> V_39 . V_27 , V_247 + V_213 ) )
return - V_222 ;
if ( F_114 ( V_253 , V_248 + V_213 ) )
return - V_222 ;
V_213 ++ ;
}
}
* V_249 = V_250 ;
return 0 ;
}
int F_126 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_255 * V_256 = V_202 ;
struct V_73 * V_74 ;
struct V_123 * V_124 ;
struct V_75 * V_76 ;
int V_257 = 0 ;
int V_258 = 0 ;
int V_22 = 0 ;
int V_213 = 0 ;
int V_1 ;
struct V_259 V_260 ;
struct V_259 T_3 * V_261 ;
T_1 T_3 * V_262 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
memset ( & V_260 , 0 , sizeof( struct V_259 ) ) ;
F_70 ( L_60 , V_256 -> V_216 ) ;
F_11 ( & V_17 -> V_23 . V_59 ) ;
V_74 = F_127 ( V_17 , V_256 -> V_216 ) ;
if ( ! V_74 ) {
V_22 = - V_235 ;
goto V_105;
}
for ( V_1 = 0 ; V_1 < V_263 ; V_1 ++ )
if ( V_74 -> V_264 [ V_1 ] != 0 )
V_258 ++ ;
if ( V_256 -> V_265 == 0 ) {
V_74 -> V_35 -> V_266 ( V_74 ,
V_17 -> V_23 . V_225 ,
V_17 -> V_23 . V_223 ) ;
}
F_88 (mode, &connector->modes, head)
if ( F_121 ( V_76 , V_204 ) )
V_257 ++ ;
V_256 -> V_216 = V_74 -> V_39 . V_27 ;
V_256 -> V_102 = V_74 -> V_102 ;
V_256 -> V_106 = V_74 -> V_106 ;
V_256 -> V_267 = V_74 -> V_121 . V_268 ;
V_256 -> V_269 = V_74 -> V_121 . V_270 ;
V_256 -> V_271 = V_74 -> V_121 . V_8 ;
V_256 -> V_272 = V_74 -> V_5 ;
F_128 ( & V_17 -> V_23 . V_122 , NULL ) ;
V_124 = F_123 ( V_74 ) ;
if ( V_124 )
V_256 -> V_217 = V_124 -> V_39 . V_27 ;
else
V_256 -> V_217 = 0 ;
if ( ( V_256 -> V_265 >= V_257 ) && V_257 ) {
V_213 = 0 ;
V_261 = (struct V_259 T_3 * ) ( unsigned long ) V_256 -> V_273 ;
F_88 (mode, &connector->modes, head) {
if ( ! F_121 ( V_76 , V_204 ) )
continue;
F_119 ( & V_260 , V_76 ) ;
if ( F_129 ( V_261 + V_213 ,
& V_260 , sizeof( V_260 ) ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_213 ++ ;
}
}
V_256 -> V_265 = V_257 ;
V_22 = F_124 ( & V_74 -> V_39 , V_204 -> V_246 ,
( T_1 T_3 * ) ( unsigned long ) ( V_256 -> V_274 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_256 -> V_275 ) ,
& V_256 -> V_276 ) ;
if ( V_22 )
goto V_40;
if ( ( V_256 -> V_229 >= V_258 ) && V_258 ) {
V_213 = 0 ;
V_262 = ( T_1 T_3 * ) ( unsigned long ) ( V_256 -> V_277 ) ;
for ( V_1 = 0 ; V_1 < V_263 ; V_1 ++ ) {
if ( V_74 -> V_264 [ V_1 ] != 0 ) {
if ( F_114 ( V_74 -> V_264 [ V_1 ] ,
V_262 + V_213 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_213 ++ ;
}
}
}
V_256 -> V_229 = V_258 ;
V_40:
F_130 ( & V_17 -> V_23 . V_122 ) ;
V_105:
F_13 ( & V_17 -> V_23 . V_59 ) ;
return V_22 ;
}
static struct V_46 * F_131 ( struct V_123 * V_124 )
{
struct V_73 * V_74 ;
struct V_16 * V_17 = V_124 -> V_17 ;
bool V_278 = false ;
F_80 (connector, dev) {
if ( ! V_74 -> V_69 )
continue;
V_278 = true ;
if ( V_74 -> V_69 -> V_245 != V_124 )
continue;
return V_74 -> V_69 -> V_47 ;
}
if ( V_278 )
return NULL ;
return V_124 -> V_47 ;
}
int F_132 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_279 * V_280 = V_202 ;
struct V_123 * V_124 ;
struct V_46 * V_47 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
V_124 = F_133 ( V_17 , V_280 -> V_217 ) ;
if ( ! V_124 )
return - V_235 ;
F_128 ( & V_17 -> V_23 . V_122 , NULL ) ;
V_47 = F_131 ( V_124 ) ;
if ( V_47 )
V_280 -> V_215 = V_47 -> V_39 . V_27 ;
else
V_280 -> V_215 = 0 ;
F_130 ( & V_17 -> V_23 . V_122 ) ;
V_280 -> V_126 = V_124 -> V_126 ;
V_280 -> V_217 = V_124 -> V_39 . V_27 ;
V_280 -> V_64 = V_124 -> V_64 ;
V_280 -> V_281 = V_124 -> V_281 ;
return 0 ;
}
int F_134 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_282 * V_283 = V_202 ;
struct V_55 * V_56 ;
struct V_48 * V_49 ;
T_1 T_3 * V_284 ;
int V_213 = 0 ;
unsigned V_285 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
V_56 = & V_17 -> V_23 ;
if ( V_204 -> V_286 )
V_285 = V_56 -> V_137 ;
else
V_285 = V_56 -> V_139 ;
if ( V_285 &&
( V_283 -> V_287 >= V_285 ) ) {
V_284 = ( T_1 T_3 * ) ( unsigned long ) V_283 -> V_288 ;
F_49 (plane, dev) {
if ( V_49 -> type != V_138 &&
! V_204 -> V_286 )
continue;
if ( F_114 ( V_49 -> V_39 . V_27 , V_284 + V_213 ) )
return - V_222 ;
V_213 ++ ;
}
}
V_283 -> V_287 = V_285 ;
return 0 ;
}
int F_135 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_289 * V_283 = V_202 ;
struct V_48 * V_49 ;
T_1 T_3 * V_290 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
V_49 = F_136 ( V_17 , V_283 -> V_291 ) ;
if ( ! V_49 )
return - V_235 ;
F_128 ( & V_49 -> V_59 , NULL ) ;
if ( V_49 -> V_47 )
V_283 -> V_215 = V_49 -> V_47 -> V_39 . V_27 ;
else
V_283 -> V_215 = 0 ;
if ( V_49 -> V_33 )
V_283 -> V_214 = V_49 -> V_33 -> V_39 . V_27 ;
else
V_283 -> V_214 = 0 ;
F_130 ( & V_49 -> V_59 ) ;
V_283 -> V_291 = V_49 -> V_39 . V_27 ;
V_283 -> V_64 = V_49 -> V_64 ;
V_283 -> V_236 = 0 ;
if ( V_49 -> V_132 &&
( V_283 -> V_292 >= V_49 -> V_132 ) ) {
V_290 = ( T_1 T_3 * ) ( unsigned long ) V_283 -> V_293 ;
if ( F_129 ( V_290 ,
V_49 -> V_135 ,
sizeof( T_1 ) * V_49 -> V_132 ) ) {
return - V_222 ;
}
}
V_283 -> V_292 = V_49 -> V_132 ;
return 0 ;
}
int F_137 ( const struct V_48 * V_49 , T_2 V_13 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_49 -> V_132 ; V_1 ++ ) {
if ( V_13 == V_49 -> V_135 [ V_1 ] )
return 0 ;
}
return - V_82 ;
}
static int F_138 ( T_1 V_238 , T_1 V_240 ,
T_1 V_294 , T_1 V_295 ,
const struct V_32 * V_33 )
{
unsigned int V_296 , V_297 ;
V_296 = V_33 -> V_298 << 16 ;
V_297 = V_33 -> V_299 << 16 ;
if ( V_294 > V_296 ||
V_238 > V_296 - V_294 ||
V_295 > V_297 ||
V_240 > V_297 - V_295 ) {
F_70 ( L_61
L_62 ,
V_294 >> 16 , ( ( V_294 & 0xffff ) * 15625 ) >> 10 ,
V_295 >> 16 , ( ( V_295 & 0xffff ) * 15625 ) >> 10 ,
V_238 >> 16 , ( ( V_238 & 0xffff ) * 15625 ) >> 10 ,
V_240 >> 16 , ( ( V_240 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_300 ;
}
return 0 ;
}
static int F_139 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_5 V_301 , T_5 V_302 ,
T_1 V_303 , T_1 V_304 ,
T_1 V_238 , T_1 V_240 ,
T_1 V_294 , T_1 V_295 )
{
int V_22 = 0 ;
if ( ! V_33 ) {
V_49 -> V_152 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_153 ( V_49 ) ;
if ( ! V_22 ) {
V_49 -> V_47 = NULL ;
V_49 -> V_33 = NULL ;
} else {
V_49 -> V_152 = NULL ;
}
goto V_40;
}
if ( ! ( V_49 -> V_64 & F_140 ( V_47 ) ) ) {
F_70 ( L_63 ) ;
V_22 = - V_82 ;
goto V_40;
}
V_22 = F_137 ( V_49 , V_33 -> V_305 ) ;
if ( V_22 ) {
F_70 ( L_64 ,
F_9 ( V_33 -> V_305 ) ) ;
goto V_40;
}
if ( V_303 > V_165 ||
V_301 > V_165 - ( T_5 ) V_303 ||
V_304 > V_165 ||
V_302 > V_165 - ( T_5 ) V_304 ) {
F_70 ( L_65 ,
V_303 , V_304 , V_301 , V_302 ) ;
V_22 = - V_306 ;
goto V_40;
}
V_22 = F_138 ( V_238 , V_240 , V_294 , V_295 , V_33 ) ;
if ( V_22 )
goto V_40;
V_49 -> V_152 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_307 ( V_49 , V_47 , V_33 ,
V_301 , V_302 , V_303 , V_304 ,
V_238 , V_240 , V_294 , V_295 ) ;
if ( ! V_22 ) {
V_49 -> V_47 = V_47 ;
V_49 -> V_33 = V_33 ;
V_33 = NULL ;
} else {
V_49 -> V_152 = NULL ;
}
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
if ( V_49 -> V_152 )
F_34 ( V_49 -> V_152 ) ;
V_49 -> V_152 = NULL ;
return V_22 ;
}
static int F_141 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_5 V_301 , T_5 V_302 ,
T_1 V_303 , T_1 V_304 ,
T_1 V_238 , T_1 V_240 ,
T_1 V_294 , T_1 V_295 )
{
int V_22 ;
F_45 ( V_49 -> V_17 ) ;
V_22 = F_139 ( V_49 , V_47 , V_33 ,
V_301 , V_302 , V_303 , V_304 ,
V_238 , V_240 , V_294 , V_295 ) ;
F_51 ( V_49 -> V_17 ) ;
return V_22 ;
}
int F_142 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_308 * V_309 = V_202 ;
struct V_48 * V_49 ;
struct V_46 * V_47 = NULL ;
struct V_32 * V_33 = NULL ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
V_49 = F_136 ( V_17 , V_309 -> V_291 ) ;
if ( ! V_49 ) {
F_70 ( L_66 ,
V_309 -> V_291 ) ;
return - V_235 ;
}
if ( V_309 -> V_214 ) {
V_33 = F_32 ( V_17 , V_309 -> V_214 ) ;
if ( ! V_33 ) {
F_70 ( L_67 ,
V_309 -> V_214 ) ;
return - V_235 ;
}
V_47 = F_117 ( V_17 , V_309 -> V_215 ) ;
if ( ! V_47 ) {
F_70 ( L_68 ,
V_309 -> V_215 ) ;
return - V_235 ;
}
}
return F_141 ( V_49 , V_47 , V_33 ,
V_309 -> V_301 , V_309 -> V_302 ,
V_309 -> V_303 , V_309 -> V_304 ,
V_309 -> V_238 , V_309 -> V_240 ,
V_309 -> V_294 , V_309 -> V_295 ) ;
}
int F_47 ( struct V_50 * V_51 )
{
struct V_46 * V_47 = V_51 -> V_47 ;
struct V_32 * V_33 ;
struct V_46 * V_72 ;
int V_22 ;
F_46 (tmp, crtc->dev)
V_72 -> V_52 -> V_152 = V_72 -> V_52 -> V_33 ;
V_33 = V_51 -> V_33 ;
V_22 = V_47 -> V_35 -> V_310 ( V_51 ) ;
if ( V_22 == 0 ) {
V_47 -> V_52 -> V_47 = V_47 ;
V_47 -> V_52 -> V_33 = V_33 ;
}
F_46 (tmp, crtc->dev) {
if ( V_72 -> V_52 -> V_33 )
F_38 ( V_72 -> V_52 -> V_33 ) ;
if ( V_72 -> V_52 -> V_152 )
F_34 ( V_72 -> V_52 -> V_152 ) ;
V_72 -> V_52 -> V_152 = NULL ;
}
return V_22 ;
}
void F_143 ( const struct V_75 * V_76 ,
int * V_311 , int * V_312 )
{
struct V_75 V_313 ;
F_144 ( & V_313 , V_76 ) ;
F_145 ( & V_313 , V_314 ) ;
* V_311 = V_313 . V_315 ;
* V_312 = V_313 . V_316 ;
}
int F_146 ( const struct V_46 * V_47 ,
int V_237 , int V_239 ,
const struct V_75 * V_76 ,
const struct V_32 * V_33 )
{
int V_311 , V_312 ;
F_143 ( V_76 , & V_311 , & V_312 ) ;
if ( V_47 -> V_69 &&
V_47 -> V_52 -> V_69 -> V_317 & ( F_147 ( V_318 ) |
F_147 ( V_319 ) ) )
F_148 ( V_311 , V_312 ) ;
return F_138 ( V_237 << 16 , V_239 << 16 ,
V_311 << 16 , V_312 << 16 , V_33 ) ;
}
int F_149 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
struct V_233 * V_320 = V_202 ;
struct V_46 * V_47 ;
struct V_73 * * V_321 = NULL , * V_74 ;
struct V_32 * V_33 = NULL ;
struct V_75 * V_76 = NULL ;
struct V_50 V_51 ;
T_1 T_3 * V_322 ;
int V_22 ;
int V_1 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
if ( V_320 -> V_237 & 0xffff0000 || V_320 -> V_239 & 0xffff0000 )
return - V_306 ;
F_45 ( V_17 ) ;
V_47 = F_117 ( V_17 , V_320 -> V_215 ) ;
if ( ! V_47 ) {
F_70 ( L_69 , V_320 -> V_215 ) ;
V_22 = - V_235 ;
goto V_40;
}
F_70 ( L_56 , V_47 -> V_39 . V_27 ) ;
if ( V_320 -> V_242 ) {
if ( V_320 -> V_214 == - 1 ) {
if ( ! V_47 -> V_52 -> V_33 ) {
F_70 ( L_70 ) ;
V_22 = - V_82 ;
goto V_40;
}
V_33 = V_47 -> V_52 -> V_33 ;
F_38 ( V_33 ) ;
} else {
V_33 = F_32 ( V_17 , V_320 -> V_214 ) ;
if ( ! V_33 ) {
F_70 ( L_71 ,
V_320 -> V_214 ) ;
V_22 = - V_235 ;
goto V_40;
}
}
V_76 = F_150 ( V_17 ) ;
if ( ! V_76 ) {
V_22 = - V_83 ;
goto V_40;
}
V_22 = F_151 ( V_76 , & V_320 -> V_76 ) ;
if ( V_22 ) {
F_70 ( L_72 ) ;
goto V_40;
}
F_145 ( V_76 , V_323 ) ;
if ( ! V_47 -> V_52 -> V_324 ) {
V_22 = F_137 ( V_47 -> V_52 ,
V_33 -> V_305 ) ;
if ( V_22 ) {
F_70 ( L_64 ,
F_9 ( V_33 -> V_305 ) ) ;
goto V_40;
}
}
V_22 = F_146 ( V_47 , V_320 -> V_237 , V_320 -> V_239 ,
V_76 , V_33 ) ;
if ( V_22 )
goto V_40;
}
if ( V_320 -> V_231 == 0 && V_76 ) {
F_70 ( L_73 ) ;
V_22 = - V_82 ;
goto V_40;
}
if ( V_320 -> V_231 > 0 && ( ! V_76 || ! V_33 ) ) {
F_70 ( L_74 ,
V_320 -> V_231 ) ;
V_22 = - V_82 ;
goto V_40;
}
if ( V_320 -> V_231 > 0 ) {
T_2 V_325 ;
if ( V_320 -> V_231 > V_56 -> V_113 ) {
V_22 = - V_82 ;
goto V_40;
}
V_321 = F_92 ( V_320 -> V_231 ,
sizeof( struct V_73 * ) ,
V_26 ) ;
if ( ! V_321 ) {
V_22 = - V_83 ;
goto V_40;
}
for ( V_1 = 0 ; V_1 < V_320 -> V_231 ; V_1 ++ ) {
V_322 = ( T_1 T_3 * ) ( unsigned long ) V_320 -> V_322 ;
if ( F_152 ( V_325 , & V_322 [ V_1 ] ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_74 = F_127 ( V_17 , V_325 ) ;
if ( ! V_74 ) {
F_70 ( L_75 ,
V_325 ) ;
V_22 = - V_235 ;
goto V_40;
}
F_70 ( L_58 ,
V_74 -> V_39 . V_27 ,
V_74 -> V_11 ) ;
V_321 [ V_1 ] = V_74 ;
}
}
V_51 . V_47 = V_47 ;
V_51 . V_237 = V_320 -> V_237 ;
V_51 . V_239 = V_320 -> V_239 ;
V_51 . V_76 = V_76 ;
V_51 . V_326 = V_321 ;
V_51 . V_327 = V_320 -> V_231 ;
V_51 . V_33 = V_33 ;
V_22 = F_47 ( & V_51 ) ;
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
F_59 ( V_321 ) ;
F_63 ( V_17 , V_76 ) ;
F_51 ( V_17 ) ;
return V_22 ;
}
static int F_153 ( struct V_46 * V_47 ,
struct V_328 * V_329 ,
struct V_203 * V_204 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
struct V_32 * V_33 = NULL ;
struct V_330 V_331 = {
. V_298 = V_329 -> V_298 ,
. V_299 = V_329 -> V_299 ,
. V_305 = V_332 ,
. V_333 = { V_329 -> V_298 * 4 } ,
. V_334 = { V_329 -> V_335 } ,
} ;
T_5 V_301 , V_302 ;
T_1 V_303 = 0 , V_304 = 0 ;
T_1 V_294 = 0 , V_295 = 0 ;
int V_22 = 0 ;
F_95 ( ! V_47 -> V_53 ) ;
F_22 ( V_47 -> V_53 -> V_47 != V_47 && V_47 -> V_53 -> V_47 != NULL ) ;
if ( V_329 -> V_254 & V_336 ) {
if ( V_329 -> V_335 ) {
V_33 = F_154 ( V_17 , & V_331 , V_204 ) ;
if ( F_155 ( V_33 ) ) {
F_70 ( L_76 ) ;
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
if ( V_329 -> V_254 & V_337 ) {
V_301 = V_329 -> V_237 ;
V_302 = V_329 -> V_239 ;
} else {
V_301 = V_47 -> V_338 ;
V_302 = V_47 -> V_339 ;
}
if ( V_33 ) {
V_303 = V_33 -> V_298 ;
V_304 = V_33 -> V_299 ;
V_294 = V_33 -> V_298 << 16 ;
V_295 = V_33 -> V_299 << 16 ;
}
V_22 = F_139 ( V_47 -> V_53 , V_47 , V_33 ,
V_301 , V_302 , V_303 , V_304 ,
0 , 0 , V_294 , V_295 ) ;
if ( V_22 == 0 && V_329 -> V_254 & V_337 ) {
V_47 -> V_338 = V_329 -> V_237 ;
V_47 -> V_339 = V_329 -> V_239 ;
}
return V_22 ;
}
static int F_157 ( struct V_16 * V_17 ,
struct V_328 * V_329 ,
struct V_203 * V_204 )
{
struct V_46 * V_47 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
if ( ! V_329 -> V_254 || ( ~ V_340 & V_329 -> V_254 ) )
return - V_82 ;
V_47 = F_117 ( V_17 , V_329 -> V_215 ) ;
if ( ! V_47 ) {
F_70 ( L_69 , V_329 -> V_215 ) ;
return - V_235 ;
}
F_118 ( V_47 , V_47 -> V_53 ) ;
if ( V_47 -> V_53 ) {
V_22 = F_153 ( V_47 , V_329 , V_204 ) ;
goto V_40;
}
if ( V_329 -> V_254 & V_336 ) {
if ( ! V_47 -> V_35 -> V_341 && ! V_47 -> V_35 -> V_342 ) {
V_22 = - V_343 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_342 )
V_22 = V_47 -> V_35 -> V_342 ( V_47 , V_204 , V_329 -> V_335 ,
V_329 -> V_298 , V_329 -> V_299 , V_329 -> V_344 , V_329 -> V_345 ) ;
else
V_22 = V_47 -> V_35 -> V_341 ( V_47 , V_204 , V_329 -> V_335 ,
V_329 -> V_298 , V_329 -> V_299 ) ;
}
if ( V_329 -> V_254 & V_337 ) {
if ( V_47 -> V_35 -> V_346 ) {
V_22 = V_47 -> V_35 -> V_346 ( V_47 , V_329 -> V_237 , V_329 -> V_239 ) ;
} else {
V_22 = - V_222 ;
goto V_40;
}
}
V_40:
F_120 ( V_47 ) ;
return V_22 ;
}
int F_158 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_347 * V_329 = V_202 ;
struct V_328 V_348 ;
memcpy ( & V_348 , V_329 , sizeof( struct V_347 ) ) ;
V_348 . V_344 = V_348 . V_345 = 0 ;
return F_157 ( V_17 , & V_348 , V_204 ) ;
}
int F_159 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_328 * V_329 = V_202 ;
return F_157 ( V_17 , V_329 , V_204 ) ;
}
T_1 F_160 ( T_1 V_349 , T_1 V_350 )
{
T_1 V_351 ;
switch ( V_349 ) {
case 8 :
V_351 = V_352 ;
break;
case 16 :
if ( V_350 == 15 )
V_351 = V_353 ;
else
V_351 = V_354 ;
break;
case 24 :
V_351 = V_355 ;
break;
case 32 :
if ( V_350 == 24 )
V_351 = V_356 ;
else if ( V_350 == 30 )
V_351 = V_357 ;
else
V_351 = V_332 ;
break;
default:
F_48 ( L_77 ) ;
V_351 = V_356 ;
break;
}
return V_351 ;
}
int F_161 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_358 * V_359 = V_202 ;
struct V_330 V_360 = {} ;
int V_22 ;
V_360 . V_214 = V_359 -> V_214 ;
V_360 . V_298 = V_359 -> V_298 ;
V_360 . V_299 = V_359 -> V_299 ;
V_360 . V_333 [ 0 ] = V_359 -> V_361 ;
V_360 . V_305 = F_160 ( V_359 -> V_349 , V_359 -> V_350 ) ;
V_360 . V_334 [ 0 ] = V_359 -> V_335 ;
V_22 = F_162 ( V_17 , & V_360 , V_204 ) ;
if ( V_22 )
return V_22 ;
V_359 -> V_214 = V_360 . V_214 ;
return 0 ;
}
static int F_163 ( const struct V_330 * V_360 )
{
T_1 V_13 = V_360 -> V_305 & ~ V_15 ;
switch ( V_13 ) {
case V_352 :
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
case V_353 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_354 :
case V_379 :
case V_355 :
case V_380 :
case V_356 :
case V_381 :
case V_382 :
case V_383 :
case V_332 :
case V_384 :
case V_385 :
case V_386 :
case V_357 :
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
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
return 0 ;
default:
F_70 ( L_78 ,
F_9 ( V_360 -> V_305 ) ) ;
return - V_82 ;
}
}
static int F_164 ( const struct V_330 * V_360 )
{
int V_22 , V_415 , V_416 , V_285 , V_1 ;
V_22 = F_163 ( V_360 ) ;
if ( V_22 ) {
F_70 ( L_79 ,
F_9 ( V_360 -> V_305 ) ) ;
return V_22 ;
}
V_415 = F_165 ( V_360 -> V_305 ) ;
V_416 = F_166 ( V_360 -> V_305 ) ;
V_285 = F_167 ( V_360 -> V_305 ) ;
if ( V_360 -> V_298 == 0 || V_360 -> V_298 % V_415 ) {
F_70 ( L_80 , V_360 -> V_298 ) ;
return - V_82 ;
}
if ( V_360 -> V_299 == 0 || V_360 -> V_299 % V_416 ) {
F_70 ( L_81 , V_360 -> V_299 ) ;
return - V_82 ;
}
for ( V_1 = 0 ; V_1 < V_285 ; V_1 ++ ) {
unsigned int V_298 = V_360 -> V_298 / ( V_1 != 0 ? V_415 : 1 ) ;
unsigned int V_299 = V_360 -> V_299 / ( V_1 != 0 ? V_416 : 1 ) ;
unsigned int V_417 = F_168 ( V_360 -> V_305 , V_1 ) ;
if ( ! V_360 -> V_334 [ V_1 ] ) {
F_70 ( L_82 , V_1 ) ;
return - V_82 ;
}
if ( ( T_4 ) V_298 * V_417 > V_163 )
return - V_306 ;
if ( ( T_4 ) V_299 * V_360 -> V_333 [ V_1 ] + V_360 -> V_418 [ V_1 ] > V_163 )
return - V_306 ;
if ( V_360 -> V_333 [ V_1 ] < V_298 * V_417 ) {
F_70 ( L_83 , V_360 -> V_333 [ V_1 ] , V_1 ) ;
return - V_82 ;
}
if ( V_360 -> V_419 [ V_1 ] && ! ( V_360 -> V_254 & V_420 ) ) {
F_70 ( L_84 ,
V_360 -> V_419 [ V_1 ] , V_1 ) ;
return - V_82 ;
}
switch ( V_360 -> V_419 [ V_1 ] ) {
case V_421 :
if ( V_360 -> V_305 != V_399 ||
V_298 % 128 || V_299 % 32 ||
V_360 -> V_333 [ V_1 ] % 128 ) {
F_70 ( L_85 , V_1 ) ;
return - V_82 ;
}
break;
default:
break;
}
}
for ( V_1 = V_285 ; V_1 < 4 ; V_1 ++ ) {
if ( V_360 -> V_419 [ V_1 ] ) {
F_70 ( L_86 , V_1 ) ;
return - V_82 ;
}
if ( ! ( V_360 -> V_254 & V_420 ) )
continue;
if ( V_360 -> V_334 [ V_1 ] ) {
F_70 ( L_87 , V_1 ) ;
return - V_82 ;
}
if ( V_360 -> V_333 [ V_1 ] ) {
F_70 ( L_88 , V_1 ) ;
return - V_82 ;
}
if ( V_360 -> V_418 [ V_1 ] ) {
F_70 ( L_89 , V_1 ) ;
return - V_82 ;
}
}
return 0 ;
}
static struct V_32 *
F_154 ( struct V_16 * V_17 ,
struct V_330 * V_360 ,
struct V_203 * V_204 )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
struct V_32 * V_33 ;
int V_22 ;
if ( V_360 -> V_254 & ~ ( V_422 | V_420 ) ) {
F_70 ( L_90 , V_360 -> V_254 ) ;
return F_169 ( - V_82 ) ;
}
if ( ( V_56 -> V_226 > V_360 -> V_298 ) || ( V_360 -> V_298 > V_56 -> V_225 ) ) {
F_70 ( L_91 ,
V_360 -> V_298 , V_56 -> V_226 , V_56 -> V_225 ) ;
return F_169 ( - V_82 ) ;
}
if ( ( V_56 -> V_224 > V_360 -> V_299 ) || ( V_360 -> V_299 > V_56 -> V_223 ) ) {
F_70 ( L_92 ,
V_360 -> V_299 , V_56 -> V_224 , V_56 -> V_223 ) ;
return F_169 ( - V_82 ) ;
}
if ( V_360 -> V_254 & V_420 &&
! V_17 -> V_23 . V_423 ) {
F_70 ( L_93 ) ;
return F_169 ( - V_82 ) ;
}
V_22 = F_164 ( V_360 ) ;
if ( V_22 )
return F_169 ( V_22 ) ;
V_33 = V_17 -> V_23 . V_35 -> V_424 ( V_17 , V_204 , V_360 ) ;
if ( F_155 ( V_33 ) ) {
F_70 ( L_94 ) ;
return V_33 ;
}
return V_33 ;
}
int F_162 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_330 * V_360 = V_202 ;
struct V_32 * V_33 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
V_33 = F_154 ( V_17 , V_360 , V_204 ) ;
if ( F_155 ( V_33 ) )
return F_156 ( V_33 ) ;
F_70 ( L_95 , V_33 -> V_39 . V_27 ) ;
F_11 ( & V_204 -> V_219 ) ;
V_360 -> V_214 = V_33 -> V_39 . V_27 ;
F_26 ( & V_33 -> V_38 , & V_204 -> V_425 ) ;
F_13 ( & V_204 -> V_219 ) ;
return 0 ;
}
int F_170 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_32 * V_33 = NULL ;
struct V_32 * V_426 = NULL ;
T_1 * V_27 = V_202 ;
int V_427 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
F_11 ( & V_204 -> V_219 ) ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
V_33 = F_30 ( V_17 , * V_27 ) ;
if ( ! V_33 )
goto V_428;
F_88 (fbl, &file_priv->fbs, filp_head)
if ( V_33 == V_426 )
V_427 = 1 ;
if ( ! V_427 )
goto V_428;
F_171 ( & V_33 -> V_38 ) ;
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_204 -> V_219 ) ;
F_34 ( V_33 ) ;
return 0 ;
V_428:
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_204 -> V_219 ) ;
return - V_235 ;
}
int F_172 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_358 * V_360 = V_202 ;
struct V_32 * V_33 ;
int V_22 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
V_33 = F_32 ( V_17 , V_360 -> V_214 ) ;
if ( ! V_33 )
return - V_235 ;
V_360 -> V_299 = V_33 -> V_299 ;
V_360 -> V_298 = V_33 -> V_298 ;
V_360 -> V_350 = V_33 -> V_350 ;
V_360 -> V_349 = V_33 -> V_429 ;
V_360 -> V_361 = V_33 -> V_333 [ 0 ] ;
if ( V_33 -> V_35 -> V_430 ) {
if ( V_204 -> V_431 || F_173 ( V_432 ) ||
F_174 ( V_204 ) ) {
V_22 = V_33 -> V_35 -> V_430 ( V_33 , V_204 ,
& V_360 -> V_335 ) ;
} else {
V_360 -> V_335 = 0 ;
V_22 = 0 ;
}
} else {
V_22 = - V_433 ;
}
F_34 ( V_33 ) ;
return V_22 ;
}
int F_175 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_434 T_3 * V_435 ;
struct V_434 * V_436 = NULL ;
struct V_437 * V_360 = V_202 ;
struct V_32 * V_33 ;
unsigned V_254 ;
int V_438 ;
int V_22 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
V_33 = F_32 ( V_17 , V_360 -> V_214 ) ;
if ( ! V_33 )
return - V_235 ;
V_438 = V_360 -> V_438 ;
V_435 = (struct V_434 T_3 * ) ( unsigned long ) V_360 -> V_435 ;
if ( ! V_438 != ! V_435 ) {
V_22 = - V_82 ;
goto V_439;
}
V_254 = V_440 & V_360 -> V_254 ;
if ( V_254 & V_441 && ( V_438 % 2 ) ) {
V_22 = - V_82 ;
goto V_439;
}
if ( V_438 && V_435 ) {
if ( V_438 < 0 || V_438 > V_442 ) {
V_22 = - V_82 ;
goto V_439;
}
V_436 = F_176 ( V_438 , sizeof( * V_436 ) , V_26 ) ;
if ( ! V_436 ) {
V_22 = - V_83 ;
goto V_439;
}
V_22 = F_177 ( V_436 , V_435 ,
V_438 * sizeof( * V_436 ) ) ;
if ( V_22 ) {
V_22 = - V_222 ;
goto V_443;
}
}
if ( V_33 -> V_35 -> V_444 ) {
V_22 = V_33 -> V_35 -> V_444 ( V_33 , V_204 , V_254 , V_360 -> V_445 ,
V_436 , V_438 ) ;
} else {
V_22 = - V_446 ;
}
V_443:
F_59 ( V_436 ) ;
V_439:
F_34 ( V_33 ) ;
return V_22 ;
}
void F_178 ( struct V_203 * V_447 )
{
struct V_32 * V_33 , * V_448 ;
F_76 (fb, tfb, &priv->fbs, filp_head) {
F_171 ( & V_33 -> V_38 ) ;
F_34 ( V_33 ) ;
}
}
struct V_154 * F_99 ( struct V_16 * V_17 , int V_254 ,
const char * V_11 , int V_449 )
{
struct V_154 * V_450 = NULL ;
int V_22 ;
V_450 = F_179 ( sizeof( struct V_154 ) , V_26 ) ;
if ( ! V_450 )
return NULL ;
V_450 -> V_17 = V_17 ;
if ( V_449 ) {
V_450 -> V_451 = F_176 ( V_449 , sizeof( T_4 ) ,
V_26 ) ;
if ( ! V_450 -> V_451 )
goto V_452;
}
V_22 = F_14 ( V_17 , & V_450 -> V_39 , V_453 ) ;
if ( V_22 )
goto V_452;
V_450 -> V_254 = V_254 ;
V_450 -> V_449 = V_449 ;
F_25 ( & V_450 -> V_454 ) ;
if ( V_11 ) {
strncpy ( V_450 -> V_11 , V_11 , V_455 ) ;
V_450 -> V_11 [ V_455 - 1 ] = '\0' ;
}
F_54 ( & V_450 -> V_42 , & V_17 -> V_23 . V_456 ) ;
F_22 ( ! F_180 ( V_450 ) ) ;
return V_450 ;
V_452:
F_59 ( V_450 -> V_451 ) ;
F_59 ( V_450 ) ;
return NULL ;
}
struct V_154 * F_100 ( struct V_16 * V_17 , int V_254 ,
const char * V_11 ,
const struct V_457 * V_458 ,
int V_449 )
{
struct V_154 * V_450 ;
int V_1 , V_22 ;
V_254 |= V_185 ;
V_450 = F_99 ( V_17 , V_254 , V_11 , V_449 ) ;
if ( ! V_450 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_449 ; V_1 ++ ) {
V_22 = F_107 ( V_450 , V_1 ,
V_458 [ V_1 ] . type ,
V_458 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_181 ( V_17 , V_450 ) ;
return NULL ;
}
}
return V_450 ;
}
struct V_154 * F_182 ( struct V_16 * V_17 ,
int V_254 , const char * V_11 ,
const struct V_457 * V_458 ,
int V_459 ,
T_4 V_460 )
{
struct V_154 * V_450 ;
int V_1 , V_22 , V_71 = 0 ;
int V_449 = F_183 ( V_460 ) ;
V_254 |= V_461 ;
V_450 = F_99 ( V_17 , V_254 , V_11 , V_449 ) ;
if ( ! V_450 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_459 ; V_1 ++ ) {
if ( ! ( V_460 & ( 1ULL << V_458 [ V_1 ] . type ) ) )
continue;
if ( F_22 ( V_71 >= V_449 ) ) {
F_181 ( V_17 , V_450 ) ;
return NULL ;
}
V_22 = F_107 ( V_450 , V_71 ++ ,
V_458 [ V_1 ] . type ,
V_458 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_181 ( V_17 , V_450 ) ;
return NULL ;
}
}
return V_450 ;
}
static struct V_154 * F_184 ( struct V_16 * V_17 ,
int V_254 , const char * V_11 ,
T_4 V_462 , T_4 V_463 )
{
struct V_154 * V_450 ;
V_450 = F_99 ( V_17 , V_254 , V_11 , 2 ) ;
if ( ! V_450 )
return NULL ;
V_450 -> V_451 [ 0 ] = V_462 ;
V_450 -> V_451 [ 1 ] = V_463 ;
return V_450 ;
}
struct V_154 * F_101 ( struct V_16 * V_17 , int V_254 ,
const char * V_11 ,
T_4 V_462 , T_4 V_463 )
{
return F_184 ( V_17 , V_464 | V_254 ,
V_11 , V_462 , V_463 ) ;
}
struct V_154 * F_102 ( struct V_16 * V_17 ,
int V_254 , const char * V_11 ,
T_6 V_462 , T_6 V_463 )
{
return F_184 ( V_17 , V_465 | V_254 ,
V_11 , F_185 ( V_462 ) , F_185 ( V_463 ) ) ;
}
struct V_154 * F_103 ( struct V_16 * V_17 ,
int V_254 , const char * V_11 , T_1 type )
{
struct V_154 * V_450 ;
V_254 |= V_466 ;
if ( F_22 ( ! ( V_254 & V_162 ) ) )
return NULL ;
V_450 = F_99 ( V_17 , V_254 , V_11 , 1 ) ;
if ( ! V_450 )
return NULL ;
V_450 -> V_451 [ 0 ] = type ;
return V_450 ;
}
struct V_154 * F_104 ( struct V_16 * V_17 , int V_254 ,
const char * V_11 )
{
return F_101 ( V_17 , V_254 , V_11 , 0 , 1 ) ;
}
int F_107 ( struct V_154 * V_450 , int V_71 ,
T_4 V_467 , const char * V_11 )
{
struct V_468 * V_469 ;
if ( ! ( F_186 ( V_450 , V_185 ) ||
F_186 ( V_450 , V_461 ) ) )
return - V_82 ;
if ( F_186 ( V_450 , V_461 ) &&
( V_467 > 63 ) )
return - V_82 ;
if ( ! F_44 ( & V_450 -> V_454 ) ) {
F_88 (prop_enum, &property->enum_list, head) {
if ( V_469 -> V_467 == V_467 ) {
strncpy ( V_469 -> V_11 , V_11 , V_455 ) ;
V_469 -> V_11 [ V_455 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_469 = F_179 ( sizeof( struct V_468 ) , V_26 ) ;
if ( ! V_469 )
return - V_83 ;
strncpy ( V_469 -> V_11 , V_11 , V_455 ) ;
V_469 -> V_11 [ V_455 - 1 ] = '\0' ;
V_469 -> V_467 = V_467 ;
V_450 -> V_451 [ V_71 ] = V_467 ;
F_54 ( & V_469 -> V_42 , & V_450 -> V_454 ) ;
return 0 ;
}
void F_181 ( struct V_16 * V_17 , struct V_154 * V_450 )
{
struct V_468 * V_469 , * V_470 ;
F_76 (prop_enum, pt, &property->enum_list, head) {
F_42 ( & V_469 -> V_42 ) ;
F_59 ( V_469 ) ;
}
if ( V_450 -> V_449 )
F_59 ( V_450 -> V_451 ) ;
F_17 ( V_17 , & V_450 -> V_39 ) ;
F_42 ( & V_450 -> V_42 ) ;
F_59 ( V_450 ) ;
}
void F_57 ( struct V_18 * V_19 ,
struct V_154 * V_450 ,
T_4 V_471 )
{
int V_251 = V_19 -> V_61 -> V_251 ;
if ( V_251 == V_472 ) {
F_187 ( 1 , L_96
L_97
L_98 ,
V_19 -> type ) ;
return;
}
V_19 -> V_61 -> V_61 [ V_251 ] = V_450 ;
V_19 -> V_61 -> V_451 [ V_251 ] = V_471 ;
V_19 -> V_61 -> V_251 ++ ;
if ( V_450 -> V_254 & V_162 )
V_19 -> V_61 -> V_252 ++ ;
}
int F_188 ( struct V_18 * V_19 ,
struct V_154 * V_450 , T_4 V_253 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_61 -> V_251 ; V_1 ++ ) {
if ( V_19 -> V_61 -> V_61 [ V_1 ] == V_450 ) {
V_19 -> V_61 -> V_451 [ V_1 ] = V_253 ;
return 0 ;
}
}
return - V_82 ;
}
int F_125 ( struct V_18 * V_19 ,
struct V_154 * V_450 , T_4 * V_253 )
{
int V_1 ;
if ( F_56 ( V_450 -> V_17 , V_65 ) &&
! ( V_450 -> V_254 & V_157 ) )
return F_189 ( V_19 , V_450 , V_253 ) ;
for ( V_1 = 0 ; V_1 < V_19 -> V_61 -> V_251 ; V_1 ++ ) {
if ( V_19 -> V_61 -> V_61 [ V_1 ] == V_450 ) {
* V_253 = V_19 -> V_61 -> V_451 [ V_1 ] ;
return 0 ;
}
}
return - V_82 ;
}
int F_190 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_473 * V_256 = V_202 ;
struct V_154 * V_450 ;
int V_474 = 0 ;
int V_475 = 0 ;
int V_22 = 0 , V_1 ;
int V_213 ;
struct V_468 * V_469 ;
struct V_476 T_3 * V_477 ;
T_4 T_3 * V_478 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
F_45 ( V_17 ) ;
V_450 = F_191 ( V_17 , V_256 -> V_479 ) ;
if ( ! V_450 ) {
V_22 = - V_235 ;
goto V_480;
}
if ( F_186 ( V_450 , V_185 ) ||
F_186 ( V_450 , V_461 ) ) {
F_88 (prop_enum, &property->enum_list, head)
V_474 ++ ;
}
V_475 = V_450 -> V_449 ;
strncpy ( V_256 -> V_11 , V_450 -> V_11 , V_455 ) ;
V_256 -> V_11 [ V_455 - 1 ] = 0 ;
V_256 -> V_254 = V_450 -> V_254 ;
if ( ( V_256 -> V_481 >= V_475 ) && V_475 ) {
V_478 = ( T_4 T_3 * ) ( unsigned long ) V_256 -> V_478 ;
for ( V_1 = 0 ; V_1 < V_475 ; V_1 ++ ) {
if ( F_129 ( V_478 + V_1 , & V_450 -> V_451 [ V_1 ] , sizeof( T_4 ) ) ) {
V_22 = - V_222 ;
goto V_480;
}
}
}
V_256 -> V_481 = V_475 ;
if ( F_186 ( V_450 , V_185 ) ||
F_186 ( V_450 , V_461 ) ) {
if ( ( V_256 -> V_482 >= V_474 ) && V_474 ) {
V_213 = 0 ;
V_477 = (struct V_476 T_3 * ) ( unsigned long ) V_256 -> V_483 ;
F_88 (prop_enum, &property->enum_list, head) {
if ( F_129 ( & V_477 [ V_213 ] . V_467 , & V_469 -> V_467 , sizeof( T_4 ) ) ) {
V_22 = - V_222 ;
goto V_480;
}
if ( F_129 ( & V_477 [ V_213 ] . V_11 ,
& V_469 -> V_11 , V_455 ) ) {
V_22 = - V_222 ;
goto V_480;
}
V_213 ++ ;
}
}
V_256 -> V_482 = V_474 ;
}
if ( F_186 ( V_450 , V_156 ) )
V_256 -> V_482 = 0 ;
V_480:
F_51 ( V_17 ) ;
return V_22 ;
}
struct V_484 *
F_192 ( struct V_16 * V_17 , T_7 V_485 ,
const void * V_202 )
{
struct V_484 * V_486 ;
int V_22 ;
if ( ! V_485 || V_485 > V_487 - sizeof( struct V_484 ) )
return F_169 ( - V_82 ) ;
V_486 = F_179 ( sizeof( struct V_484 ) + V_485 , V_26 ) ;
if ( ! V_486 )
return F_169 ( - V_83 ) ;
F_25 ( & V_486 -> V_488 ) ;
V_486 -> V_485 = V_485 ;
V_486 -> V_17 = V_17 ;
if ( V_202 )
memcpy ( V_486 -> V_202 , V_202 , V_485 ) ;
F_11 ( & V_17 -> V_23 . V_489 ) ;
V_22 = F_14 ( V_17 , & V_486 -> V_39 , V_31 ) ;
if ( V_22 ) {
F_59 ( V_486 ) ;
F_13 ( & V_17 -> V_23 . V_489 ) ;
return F_169 ( - V_82 ) ;
}
F_24 ( & V_486 -> V_37 ) ;
F_54 ( & V_486 -> V_490 ,
& V_17 -> V_23 . V_491 ) ;
F_13 ( & V_17 -> V_23 . V_489 ) ;
return V_486 ;
}
static void F_193 ( struct V_44 * V_44 )
{
struct V_484 * V_486 =
F_29 ( V_44 , struct V_484 , V_37 ) ;
F_22 ( ! F_194 ( & V_486 -> V_17 -> V_23 . V_489 ) ) ;
F_42 ( & V_486 -> V_490 ) ;
F_42 ( & V_486 -> V_488 ) ;
F_17 ( V_486 -> V_17 , & V_486 -> V_39 ) ;
F_59 ( V_486 ) ;
}
void F_195 ( struct V_484 * V_486 )
{
struct V_16 * V_17 ;
if ( ! V_486 )
return;
V_17 = V_486 -> V_17 ;
F_35 ( L_99 , V_486 , V_486 -> V_39 . V_27 , F_36 ( & V_486 -> V_37 . V_37 ) ) ;
if ( F_196 ( & V_486 -> V_37 , F_193 ,
& V_17 -> V_23 . V_489 ) )
F_13 ( & V_17 -> V_23 . V_489 ) ;
else
F_197 ( & V_17 -> V_23 . V_489 ) ;
}
static void F_198 ( struct V_484 * V_486 )
{
if ( ! V_486 )
return;
F_35 ( L_99 , V_486 , V_486 -> V_39 . V_27 , F_36 ( & V_486 -> V_37 . V_37 ) ) ;
F_37 ( & V_486 -> V_37 , F_193 ) ;
}
void F_199 ( struct V_16 * V_17 ,
struct V_203 * V_204 )
{
struct V_484 * V_486 , * V_492 ;
F_11 ( & V_17 -> V_23 . V_489 ) ;
F_76 (blob, bt, &file_priv->blobs, head_file) {
F_171 ( & V_486 -> V_488 ) ;
F_198 ( V_486 ) ;
}
F_13 ( & V_17 -> V_23 . V_489 ) ;
}
struct V_484 * F_200 ( struct V_484 * V_486 )
{
F_35 ( L_99 , V_486 , V_486 -> V_39 . V_27 , F_36 ( & V_486 -> V_37 . V_37 ) ) ;
F_39 ( & V_486 -> V_37 ) ;
return V_486 ;
}
static struct V_484 * F_201 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_18 * V_19 = NULL ;
struct V_484 * V_486 ;
F_22 ( ! F_194 ( & V_17 -> V_23 . V_489 ) ) ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_19 = F_20 ( & V_17 -> V_23 . V_25 , V_27 ) ;
if ( ! V_19 || ( V_19 -> type != V_31 ) || ( V_19 -> V_27 != V_27 ) )
V_486 = NULL ;
else
V_486 = F_202 ( V_19 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_486 ;
}
struct V_484 * F_203 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_484 * V_486 ;
F_11 ( & V_17 -> V_23 . V_489 ) ;
V_486 = F_201 ( V_17 , V_27 ) ;
if ( V_486 ) {
if ( ! F_33 ( & V_486 -> V_37 ) )
V_486 = NULL ;
}
F_13 ( & V_17 -> V_23 . V_489 ) ;
return V_486 ;
}
static int F_204 ( struct V_16 * V_17 ,
struct V_484 * * V_493 ,
T_7 V_485 ,
const void * V_202 ,
struct V_18 * V_494 ,
struct V_154 * V_495 )
{
struct V_484 * V_496 = NULL ;
struct V_484 * V_497 = NULL ;
int V_22 ;
F_22 ( V_493 == NULL ) ;
V_497 = * V_493 ;
if ( V_485 && V_202 ) {
V_496 = F_192 ( V_17 , V_485 , V_202 ) ;
if ( F_155 ( V_496 ) )
return F_156 ( V_496 ) ;
}
if ( V_494 ) {
V_22 = F_188 ( V_494 ,
V_495 ,
V_496 ?
V_496 -> V_39 . V_27 : 0 ) ;
if ( V_22 != 0 )
goto V_498;
}
F_195 ( V_497 ) ;
* V_493 = V_496 ;
return 0 ;
V_498:
F_195 ( V_496 ) ;
return V_22 ;
}
int F_205 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_499 * V_256 = V_202 ;
struct V_484 * V_486 ;
int V_22 = 0 ;
void T_3 * V_500 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
F_45 ( V_17 ) ;
F_11 ( & V_17 -> V_23 . V_489 ) ;
V_486 = F_201 ( V_17 , V_256 -> V_501 ) ;
if ( ! V_486 ) {
V_22 = - V_235 ;
goto V_480;
}
if ( V_256 -> V_485 == V_486 -> V_485 ) {
V_500 = ( void T_3 * ) ( unsigned long ) V_256 -> V_202 ;
if ( F_129 ( V_500 , V_486 -> V_202 , V_486 -> V_485 ) ) {
V_22 = - V_222 ;
goto V_480;
}
}
V_256 -> V_485 = V_486 -> V_485 ;
V_480:
F_13 ( & V_17 -> V_23 . V_489 ) ;
F_51 ( V_17 ) ;
return V_22 ;
}
int F_206 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_502 * V_256 = V_202 ;
struct V_484 * V_486 ;
void T_3 * V_500 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
V_486 = F_192 ( V_17 , V_256 -> V_485 , NULL ) ;
if ( F_155 ( V_486 ) )
return F_156 ( V_486 ) ;
V_500 = ( void T_3 * ) ( unsigned long ) V_256 -> V_202 ;
if ( F_177 ( V_486 -> V_202 , V_500 , V_256 -> V_485 ) ) {
V_22 = - V_222 ;
goto V_503;
}
F_11 ( & V_17 -> V_23 . V_489 ) ;
V_256 -> V_501 = V_486 -> V_39 . V_27 ;
F_54 ( & V_486 -> V_488 , & V_204 -> V_504 ) ;
F_13 ( & V_17 -> V_23 . V_489 ) ;
return 0 ;
V_503:
F_195 ( V_486 ) ;
return V_22 ;
}
int F_207 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_505 * V_256 = V_202 ;
struct V_484 * V_486 = NULL , * V_492 ;
bool V_427 = false ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
F_11 ( & V_17 -> V_23 . V_489 ) ;
V_486 = F_201 ( V_17 , V_256 -> V_501 ) ;
if ( ! V_486 ) {
V_22 = - V_235 ;
goto V_506;
}
F_88 (bt, &file_priv->blobs, head_file) {
if ( V_492 == V_486 ) {
V_427 = true ;
break;
}
}
if ( ! V_427 ) {
V_22 = - V_507 ;
goto V_506;
}
F_171 ( & V_486 -> V_488 ) ;
F_198 ( V_486 ) ;
F_13 ( & V_17 -> V_23 . V_489 ) ;
return 0 ;
V_506:
F_13 ( & V_17 -> V_23 . V_489 ) ;
return V_22 ;
}
int F_208 ( struct V_73 * V_74 ,
const char * V_508 )
{
struct V_16 * V_17 = V_74 -> V_17 ;
int V_22 ;
V_22 = F_204 ( V_17 ,
& V_74 -> V_509 ,
strlen ( V_508 ) + 1 ,
V_508 ,
& V_74 -> V_39 ,
V_17 -> V_23 . V_159 ) ;
return V_22 ;
}
int F_209 ( struct V_73 * V_74 )
{
struct V_16 * V_17 = V_74 -> V_17 ;
char V_510 [ 256 ] ;
int V_22 ;
if ( ! V_74 -> V_511 ) {
V_22 = F_204 ( V_17 ,
& V_74 -> V_512 ,
0 ,
NULL ,
& V_74 -> V_39 ,
V_17 -> V_23 . V_160 ) ;
return V_22 ;
}
snprintf ( V_510 , 256 , L_100 ,
V_74 -> V_120 -> V_27 , V_74 -> V_513 ,
V_74 -> V_514 , V_74 -> V_515 ,
V_74 -> V_516 , V_74 -> V_517 ,
V_74 -> V_518 , V_74 -> V_519 ) ;
V_22 = F_204 ( V_17 ,
& V_74 -> V_512 ,
strlen ( V_510 ) + 1 ,
V_510 ,
& V_74 -> V_39 ,
V_17 -> V_23 . V_160 ) ;
return V_22 ;
}
int F_210 ( struct V_73 * V_74 ,
const struct V_520 * V_520 )
{
struct V_16 * V_17 = V_74 -> V_17 ;
T_7 V_521 = 0 ;
int V_22 ;
if ( V_74 -> V_522 )
return 0 ;
if ( V_520 )
V_521 = V_523 * ( 1 + V_520 -> V_524 ) ;
V_22 = F_204 ( V_17 ,
& V_74 -> V_110 ,
V_521 ,
V_520 ,
& V_74 -> V_39 ,
V_17 -> V_23 . V_115 ) ;
return V_22 ;
}
bool F_211 ( struct V_154 * V_450 ,
T_4 V_467 , struct V_18 * * V_525 )
{
int V_1 ;
if ( V_450 -> V_254 & V_157 )
return false ;
* V_525 = NULL ;
if ( F_186 ( V_450 , V_464 ) ) {
if ( V_467 < V_450 -> V_451 [ 0 ] || V_467 > V_450 -> V_451 [ 1 ] )
return false ;
return true ;
} else if ( F_186 ( V_450 , V_465 ) ) {
T_6 V_526 = F_212 ( V_467 ) ;
if ( V_526 < F_212 ( V_450 -> V_451 [ 0 ] ) ||
V_526 > F_212 ( V_450 -> V_451 [ 1 ] ) )
return false ;
return true ;
} else if ( F_186 ( V_450 , V_461 ) ) {
T_4 V_527 = 0 ;
for ( V_1 = 0 ; V_1 < V_450 -> V_449 ; V_1 ++ )
V_527 |= ( 1ULL << V_450 -> V_451 [ V_1 ] ) ;
return ! ( V_467 & ~ V_527 ) ;
} else if ( F_186 ( V_450 , V_156 ) ) {
struct V_484 * V_486 ;
if ( V_467 == 0 )
return true ;
V_486 = F_203 ( V_450 -> V_17 , V_467 ) ;
if ( V_486 ) {
* V_525 = & V_486 -> V_39 ;
return true ;
} else {
return false ;
}
} else if ( F_186 ( V_450 , V_466 ) ) {
if ( V_467 == 0 )
return true ;
if ( V_450 -> V_451 [ 0 ] == V_30 ) {
struct V_32 * V_33 ;
V_33 = F_32 ( V_450 -> V_17 , V_467 ) ;
if ( V_33 ) {
* V_525 = & V_33 -> V_39 ;
return true ;
} else {
return false ;
}
} else {
return F_19 ( V_450 -> V_17 , V_467 , V_450 -> V_451 [ 0 ] ) != NULL ;
}
}
for ( V_1 = 0 ; V_1 < V_450 -> V_449 ; V_1 ++ )
if ( V_450 -> V_451 [ V_1 ] == V_467 )
return true ;
return false ;
}
void F_213 ( struct V_154 * V_450 ,
struct V_18 * V_525 )
{
if ( ! V_525 )
return;
if ( F_186 ( V_450 , V_466 ) ) {
if ( V_450 -> V_451 [ 0 ] == V_30 )
F_34 ( F_31 ( V_525 ) ) ;
} else if ( F_186 ( V_450 , V_156 ) )
F_195 ( F_202 ( V_525 ) ) ;
}
int F_214 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_528 * V_529 = V_202 ;
struct V_530 V_531 = {
. V_467 = V_529 -> V_467 ,
. V_479 = V_529 -> V_479 ,
. V_532 = V_529 -> V_216 ,
. V_20 = V_104
} ;
return F_215 ( V_17 , & V_531 , V_204 ) ;
}
static int F_216 ( struct V_18 * V_19 ,
struct V_154 * V_450 ,
T_4 V_467 )
{
int V_22 = - V_82 ;
struct V_73 * V_74 = F_217 ( V_19 ) ;
if ( V_450 == V_74 -> V_17 -> V_23 . V_116 ) {
V_22 = 0 ;
if ( V_74 -> V_35 -> V_533 )
V_22 = (* V_74 -> V_35 -> V_533 )( V_74 , ( int ) V_467 ) ;
} else if ( V_74 -> V_35 -> V_534 )
V_22 = V_74 -> V_35 -> V_534 ( V_74 , V_450 , V_467 ) ;
if ( ! V_22 )
F_188 ( & V_74 -> V_39 , V_450 , V_467 ) ;
return V_22 ;
}
static int F_218 ( struct V_18 * V_19 ,
struct V_154 * V_450 ,
T_4 V_467 )
{
int V_22 = - V_82 ;
struct V_46 * V_47 = F_219 ( V_19 ) ;
if ( V_47 -> V_35 -> V_534 )
V_22 = V_47 -> V_35 -> V_534 ( V_47 , V_450 , V_467 ) ;
if ( ! V_22 )
F_188 ( V_19 , V_450 , V_467 ) ;
return V_22 ;
}
int F_220 ( struct V_48 * V_49 ,
struct V_154 * V_450 ,
T_4 V_467 )
{
int V_22 = - V_82 ;
struct V_18 * V_19 = & V_49 -> V_39 ;
if ( V_49 -> V_35 -> V_534 )
V_22 = V_49 -> V_35 -> V_534 ( V_49 , V_450 , V_467 ) ;
if ( ! V_22 )
F_188 ( V_19 , V_450 , V_467 ) ;
return V_22 ;
}
int F_221 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_535 * V_536 = V_202 ;
struct V_18 * V_19 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
F_45 ( V_17 ) ;
V_19 = F_21 ( V_17 , V_536 -> V_532 , V_536 -> V_20 ) ;
if ( ! V_19 ) {
V_22 = - V_235 ;
goto V_40;
}
if ( ! V_19 -> V_61 ) {
V_22 = - V_82 ;
goto V_40;
}
V_22 = F_124 ( V_19 , V_204 -> V_246 ,
( T_1 T_3 * ) ( unsigned long ) ( V_536 -> V_274 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_536 -> V_275 ) ,
& V_536 -> V_276 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_215 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_530 * V_536 = V_202 ;
struct V_18 * V_537 ;
struct V_18 * V_538 ;
struct V_154 * V_450 ;
int V_1 , V_22 = - V_82 ;
struct V_18 * V_525 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
F_45 ( V_17 ) ;
V_537 = F_21 ( V_17 , V_536 -> V_532 , V_536 -> V_20 ) ;
if ( ! V_537 ) {
V_22 = - V_235 ;
goto V_40;
}
if ( ! V_537 -> V_61 )
goto V_40;
for ( V_1 = 0 ; V_1 < V_537 -> V_61 -> V_251 ; V_1 ++ )
if ( V_537 -> V_61 -> V_61 [ V_1 ] -> V_39 . V_27 == V_536 -> V_479 )
break;
if ( V_1 == V_537 -> V_61 -> V_251 )
goto V_40;
V_538 = F_21 ( V_17 , V_536 -> V_479 ,
V_453 ) ;
if ( ! V_538 ) {
V_22 = - V_235 ;
goto V_40;
}
V_450 = F_222 ( V_538 ) ;
if ( ! F_211 ( V_450 , V_536 -> V_467 , & V_525 ) )
goto V_40;
switch ( V_537 -> type ) {
case V_104 :
V_22 = F_216 ( V_537 , V_450 ,
V_536 -> V_467 ) ;
break;
case V_60 :
V_22 = F_218 ( V_537 , V_450 , V_536 -> V_467 ) ;
break;
case V_134 :
V_22 = F_220 ( F_223 ( V_537 ) ,
V_450 , V_536 -> V_467 ) ;
break;
}
F_213 ( V_450 , V_525 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_224 ( struct V_73 * V_74 ,
struct V_123 * V_124 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_263 ; V_1 ++ ) {
if ( V_74 -> V_264 [ V_1 ] == 0 ) {
V_74 -> V_264 [ V_1 ] = V_124 -> V_39 . V_27 ;
return 0 ;
}
}
return - V_83 ;
}
int F_225 ( struct V_46 * V_47 ,
int V_236 )
{
V_47 -> V_236 = V_236 ;
V_47 -> V_68 = F_176 ( V_236 , sizeof( V_539 ) * 3 ,
V_26 ) ;
if ( ! V_47 -> V_68 ) {
V_47 -> V_236 = 0 ;
return - V_83 ;
}
return 0 ;
}
int F_226 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_540 * V_541 = V_202 ;
struct V_46 * V_47 ;
void * V_542 , * V_543 , * V_544 ;
int V_521 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
F_45 ( V_17 ) ;
V_47 = F_117 ( V_17 , V_541 -> V_215 ) ;
if ( ! V_47 ) {
V_22 = - V_235 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_545 == NULL ) {
V_22 = - V_446 ;
goto V_40;
}
if ( V_541 -> V_236 != V_47 -> V_236 ) {
V_22 = - V_82 ;
goto V_40;
}
V_521 = V_541 -> V_236 * ( sizeof( V_539 ) ) ;
V_542 = V_47 -> V_68 ;
if ( F_177 ( V_542 , ( void T_3 * ) ( unsigned long ) V_541 -> V_546 , V_521 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_543 = V_542 + V_521 ;
if ( F_177 ( V_543 , ( void T_3 * ) ( unsigned long ) V_541 -> V_547 , V_521 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_544 = V_543 + V_521 ;
if ( F_177 ( V_544 , ( void T_3 * ) ( unsigned long ) V_541 -> V_548 , V_521 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_47 -> V_35 -> V_545 ( V_47 , V_542 , V_543 , V_544 , 0 , V_47 -> V_236 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_227 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_540 * V_541 = V_202 ;
struct V_46 * V_47 ;
void * V_542 , * V_543 , * V_544 ;
int V_521 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_82 ;
F_45 ( V_17 ) ;
V_47 = F_117 ( V_17 , V_541 -> V_215 ) ;
if ( ! V_47 ) {
V_22 = - V_235 ;
goto V_40;
}
if ( V_541 -> V_236 != V_47 -> V_236 ) {
V_22 = - V_82 ;
goto V_40;
}
V_521 = V_541 -> V_236 * ( sizeof( V_539 ) ) ;
V_542 = V_47 -> V_68 ;
if ( F_129 ( ( void T_3 * ) ( unsigned long ) V_541 -> V_546 , V_542 , V_521 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_543 = V_542 + V_521 ;
if ( F_129 ( ( void T_3 * ) ( unsigned long ) V_541 -> V_547 , V_543 , V_521 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_544 = V_543 + V_521 ;
if ( F_129 ( ( void T_3 * ) ( unsigned long ) V_541 -> V_548 , V_544 , V_521 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_228 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_549 * V_550 = V_202 ;
struct V_46 * V_47 ;
struct V_32 * V_33 = NULL ;
struct V_551 * V_552 = NULL ;
unsigned long V_254 ;
int V_22 = - V_82 ;
if ( V_550 -> V_254 & ~ V_553 ||
V_550 -> V_554 != 0 )
return - V_82 ;
if ( ( V_550 -> V_254 & V_555 ) && ! V_17 -> V_23 . V_556 )
return - V_82 ;
V_47 = F_117 ( V_17 , V_550 -> V_215 ) ;
if ( ! V_47 )
return - V_235 ;
F_118 ( V_47 , V_47 -> V_52 ) ;
if ( V_47 -> V_52 -> V_33 == NULL ) {
V_22 = - V_557 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_550 == NULL )
goto V_40;
V_33 = F_32 ( V_17 , V_550 -> V_214 ) ;
if ( ! V_33 ) {
V_22 = - V_235 ;
goto V_40;
}
if ( V_47 -> V_69 ) {
const struct V_558 * V_69 = V_47 -> V_52 -> V_69 ;
V_22 = F_138 ( V_69 -> V_238 , V_69 -> V_240 ,
V_69 -> V_294 , V_69 -> V_295 , V_33 ) ;
} else {
V_22 = F_146 ( V_47 , V_47 -> V_237 , V_47 -> V_239 , & V_47 -> V_76 , V_33 ) ;
}
if ( V_22 )
goto V_40;
if ( V_47 -> V_52 -> V_33 -> V_305 != V_33 -> V_305 ) {
F_70 ( L_101 ) ;
V_22 = - V_82 ;
goto V_40;
}
if ( V_550 -> V_254 & V_559 ) {
V_22 = - V_83 ;
F_229 ( & V_17 -> V_560 , V_254 ) ;
if ( V_204 -> V_561 < sizeof( V_552 -> V_562 ) ) {
F_230 ( & V_17 -> V_560 , V_254 ) ;
goto V_40;
}
V_204 -> V_561 -= sizeof( V_552 -> V_562 ) ;
F_230 ( & V_17 -> V_560 , V_254 ) ;
V_552 = F_179 ( sizeof( * V_552 ) , V_26 ) ;
if ( V_552 == NULL ) {
F_229 ( & V_17 -> V_560 , V_254 ) ;
V_204 -> V_561 += sizeof( V_552 -> V_562 ) ;
F_230 ( & V_17 -> V_560 , V_254 ) ;
goto V_40;
}
V_552 -> V_562 . V_39 . type = V_563 ;
V_552 -> V_562 . V_39 . V_485 = sizeof( V_552 -> V_562 ) ;
V_552 -> V_562 . V_564 = V_550 -> V_564 ;
V_552 -> V_39 . V_562 = & V_552 -> V_562 . V_39 ;
V_552 -> V_39 . V_204 = V_204 ;
V_552 -> V_39 . V_45 =
( void ( * ) ( struct V_565 * ) ) F_59 ;
}
V_47 -> V_52 -> V_152 = V_47 -> V_52 -> V_33 ;
V_22 = V_47 -> V_35 -> V_550 ( V_47 , V_33 , V_552 , V_550 -> V_254 ) ;
if ( V_22 ) {
if ( V_550 -> V_254 & V_559 ) {
F_229 ( & V_17 -> V_560 , V_254 ) ;
V_204 -> V_561 += sizeof( V_552 -> V_562 ) ;
F_230 ( & V_17 -> V_560 , V_254 ) ;
F_59 ( V_552 ) ;
}
V_47 -> V_52 -> V_152 = NULL ;
} else {
V_47 -> V_52 -> V_33 = V_33 ;
V_33 = NULL ;
}
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
if ( V_47 -> V_52 -> V_152 )
F_34 ( V_47 -> V_52 -> V_152 ) ;
V_47 -> V_52 -> V_152 = NULL ;
F_120 ( V_47 ) ;
return V_22 ;
}
void F_231 ( struct V_16 * V_17 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_123 * V_124 ;
struct V_73 * V_74 ;
F_49 (plane, dev)
if ( V_49 -> V_35 -> V_566 )
V_49 -> V_35 -> V_566 ( V_49 ) ;
F_46 (crtc, dev)
if ( V_47 -> V_35 -> V_566 )
V_47 -> V_35 -> V_566 ( V_47 ) ;
F_115 (encoder, dev)
if ( V_124 -> V_35 -> V_566 )
V_124 -> V_35 -> V_566 ( V_124 ) ;
F_11 ( & V_17 -> V_23 . V_59 ) ;
F_80 (connector, dev)
if ( V_74 -> V_35 -> V_566 )
V_74 -> V_35 -> V_566 ( V_74 ) ;
F_13 ( & V_17 -> V_23 . V_59 ) ;
}
int F_232 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_567 * args = V_202 ;
T_2 V_417 , V_568 , V_521 ;
if ( ! V_17 -> V_569 -> V_570 )
return - V_446 ;
if ( ! args -> V_298 || ! args -> V_299 || ! args -> V_349 )
return - V_82 ;
V_417 = F_233 ( args -> V_349 , 8 ) ;
if ( ! V_417 || V_417 > 0xffffffffU / args -> V_298 )
return - V_82 ;
V_568 = V_417 * args -> V_298 ;
if ( args -> V_299 > 0xffffffffU / V_568 )
return - V_82 ;
V_521 = args -> V_299 * V_568 ;
if ( F_234 ( V_521 ) == 0 )
return - V_82 ;
args -> V_335 = 0 ;
args -> V_361 = 0 ;
args -> V_521 = 0 ;
return V_17 -> V_569 -> V_570 ( V_204 , V_17 , args ) ;
}
int F_235 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_571 * args = V_202 ;
if ( ! V_17 -> V_569 -> V_572 )
return - V_446 ;
return V_17 -> V_569 -> V_572 ( V_204 , V_17 , args -> V_335 , & args -> V_573 ) ;
}
int F_236 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_574 * args = V_202 ;
if ( ! V_17 -> V_569 -> V_575 )
return - V_446 ;
return V_17 -> V_569 -> V_575 ( V_204 , V_17 , args -> V_335 ) ;
}
void F_237 ( T_1 V_13 , unsigned int * V_350 ,
int * V_349 )
{
switch ( V_13 ) {
case V_352 :
case V_362 :
case V_363 :
* V_350 = 8 ;
* V_349 = 8 ;
break;
case V_353 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
* V_350 = 15 ;
* V_349 = 16 ;
break;
case V_354 :
case V_379 :
* V_350 = 16 ;
* V_349 = 16 ;
break;
case V_355 :
case V_380 :
* V_350 = 24 ;
* V_349 = 24 ;
break;
case V_356 :
case V_381 :
case V_382 :
case V_383 :
* V_350 = 24 ;
* V_349 = 32 ;
break;
case V_357 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
* V_350 = 30 ;
* V_349 = 32 ;
break;
case V_332 :
case V_384 :
case V_385 :
case V_386 :
* V_350 = 32 ;
* V_349 = 32 ;
break;
default:
F_70 ( L_102 ,
F_9 ( V_13 ) ) ;
* V_350 = 0 ;
* V_349 = 0 ;
break;
}
}
int F_167 ( T_1 V_13 )
{
switch ( V_13 ) {
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
return 3 ;
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
return 2 ;
default:
return 1 ;
}
}
int F_168 ( T_1 V_13 , int V_49 )
{
unsigned int V_350 ;
int V_349 ;
if ( V_49 >= F_167 ( V_13 ) )
return 0 ;
switch ( V_13 ) {
case V_394 :
case V_395 :
case V_396 :
case V_397 :
return 2 ;
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
return V_49 ? 2 : 1 ;
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
return 1 ;
default:
F_237 ( V_13 , & V_350 , & V_349 ) ;
return V_349 >> 3 ;
}
}
int F_165 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_407 :
case V_408 :
case V_405 :
case V_406 :
return 4 ;
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_411 :
case V_412 :
case V_409 :
case V_410 :
return 2 ;
default:
return 1 ;
}
}
int F_166 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_405 :
case V_406 :
return 4 ;
case V_409 :
case V_410 :
case V_399 :
case V_400 :
return 2 ;
default:
return 1 ;
}
}
unsigned int F_238 ( unsigned int V_317 ,
unsigned int V_576 )
{
if ( V_317 & ~ V_576 ) {
V_317 ^= F_147 ( V_577 ) | F_147 ( V_578 ) ;
V_317 = ( V_317 & V_579 ) |
F_147 ( ( F_239 ( V_317 & V_580 ) + 1 ) % 4 ) ;
}
return V_317 ;
}
void F_240 ( struct V_16 * V_17 )
{
F_241 ( & V_17 -> V_23 . V_59 ) ;
F_53 ( & V_17 -> V_23 . V_122 ) ;
F_241 ( & V_17 -> V_23 . V_24 ) ;
F_241 ( & V_17 -> V_23 . V_36 ) ;
F_241 ( & V_17 -> V_23 . V_489 ) ;
F_25 ( & V_17 -> V_23 . V_43 ) ;
F_25 ( & V_17 -> V_23 . V_62 ) ;
F_25 ( & V_17 -> V_23 . V_112 ) ;
F_25 ( & V_17 -> V_23 . V_129 ) ;
F_25 ( & V_17 -> V_23 . V_456 ) ;
F_25 ( & V_17 -> V_23 . V_491 ) ;
F_25 ( & V_17 -> V_23 . V_136 ) ;
F_242 ( & V_17 -> V_23 . V_25 ) ;
F_242 ( & V_17 -> V_23 . V_581 ) ;
F_45 ( V_17 ) ;
F_98 ( V_17 ) ;
F_51 ( V_17 ) ;
V_17 -> V_23 . V_41 = 0 ;
V_17 -> V_23 . V_113 = 0 ;
V_17 -> V_23 . V_63 = 0 ;
V_17 -> V_23 . V_130 = 0 ;
V_17 -> V_23 . V_139 = 0 ;
V_17 -> V_23 . V_137 = 0 ;
}
void F_243 ( struct V_16 * V_17 )
{
struct V_73 * V_74 , * V_582 ;
struct V_46 * V_47 , * V_583 ;
struct V_123 * V_124 , * V_584 ;
struct V_32 * V_33 , * V_585 ;
struct V_154 * V_450 , * V_470 ;
struct V_484 * V_486 , * V_492 ;
struct V_48 * V_49 , * V_586 ;
F_76 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_124 -> V_35 -> V_45 ( V_124 ) ;
}
F_76 (connector, ot,
&dev->mode_config.connector_list, head) {
V_74 -> V_35 -> V_45 ( V_74 ) ;
}
F_76 (property, pt, &dev->mode_config.property_list,
head) {
F_181 ( V_17 , V_450 ) ;
}
F_76 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_195 ( V_486 ) ;
}
F_22 ( ! F_44 ( & V_17 -> V_23 . V_43 ) ) ;
F_76 (fb, fbt, &dev->mode_config.fb_list, head) {
F_28 ( & V_33 -> V_37 ) ;
}
F_76 (plane, plt, &dev->mode_config.plane_list,
head) {
V_49 -> V_35 -> V_45 ( V_49 ) ;
}
F_76 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_47 -> V_35 -> V_45 ( V_47 ) ;
}
F_244 ( & V_17 -> V_23 . V_581 ) ;
F_244 ( & V_17 -> V_23 . V_25 ) ;
F_60 ( & V_17 -> V_23 . V_122 ) ;
}
struct V_154 * F_245 ( struct V_16 * V_17 ,
unsigned int V_576 )
{
static const struct V_457 V_458 [] = {
{ V_587 , L_103 } ,
{ V_318 , L_104 } ,
{ V_588 , L_105 } ,
{ V_319 , L_106 } ,
{ V_577 , L_107 } ,
{ V_578 , L_108 } ,
} ;
return F_182 ( V_17 , 0 , L_109 ,
V_458 , F_2 ( V_458 ) ,
V_576 ) ;
}
static void F_246 ( struct V_44 * V_44 )
{
struct V_589 * V_590 = F_29 ( V_44 , struct V_589 , V_37 ) ;
struct V_16 * V_17 = V_590 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_581 , V_590 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
F_59 ( V_590 ) ;
}
void F_75 ( struct V_16 * V_17 ,
struct V_589 * V_590 )
{
F_37 ( & V_590 -> V_37 , F_246 ) ;
}
struct V_589 * F_247 ( struct V_16 * V_17 ,
char V_591 [ 8 ] )
{
struct V_589 * V_590 ;
int V_27 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_248 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_590 -> V_592 , V_591 , 8 ) ) {
if ( ! F_33 ( & V_590 -> V_37 ) )
V_590 = NULL ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_590 ;
}
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return NULL ;
}
struct V_589 * F_249 ( struct V_16 * V_17 ,
char V_591 [ 8 ] )
{
struct V_589 * V_590 ;
int V_22 ;
V_590 = F_179 ( sizeof( * V_590 ) , V_26 ) ;
if ( ! V_590 )
return F_169 ( - V_83 ) ;
F_24 ( & V_590 -> V_37 ) ;
memcpy ( V_590 -> V_592 , V_591 , 8 ) ;
V_590 -> V_17 = V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_22 = F_12 ( & V_17 -> V_23 . V_581 , V_590 , 1 , 0 , V_26 ) ;
if ( V_22 >= 0 ) {
V_590 -> V_27 = V_22 ;
} else {
F_59 ( V_590 ) ;
V_590 = F_169 ( V_22 ) ;
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_590 ;
}
