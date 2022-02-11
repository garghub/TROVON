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
V_47 -> V_59 = false ;
F_53 ( & V_47 -> V_60 ) ;
V_22 = F_14 ( V_17 , & V_47 -> V_39 , V_61 ) ;
if ( V_22 )
return V_22 ;
V_47 -> V_39 . V_62 = & V_47 -> V_62 ;
F_54 ( & V_47 -> V_42 , & V_56 -> V_63 ) ;
V_56 -> V_64 ++ ;
V_47 -> V_52 = V_52 ;
V_47 -> V_53 = V_53 ;
if ( V_52 )
V_52 -> V_65 = 1 << F_55 ( V_47 ) ;
if ( V_53 )
V_53 -> V_65 = 1 << F_55 ( V_47 ) ;
if ( F_56 ( V_17 , V_66 ) ) {
F_57 ( & V_47 -> V_39 , V_56 -> V_67 , 0 ) ;
F_57 ( & V_47 -> V_39 , V_56 -> V_68 , 0 ) ;
}
return 0 ;
}
void F_58 ( struct V_46 * V_47 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
F_59 ( V_47 -> V_69 ) ;
V_47 -> V_69 = NULL ;
F_60 ( & V_47 -> V_60 ) ;
F_17 ( V_17 , & V_47 -> V_39 ) ;
F_42 ( & V_47 -> V_42 ) ;
V_17 -> V_23 . V_64 -- ;
F_22 ( V_47 -> V_70 && ! V_47 -> V_35 -> V_71 ) ;
if ( V_47 -> V_70 && V_47 -> V_35 -> V_71 )
V_47 -> V_35 -> V_71 ( V_47 , V_47 -> V_70 ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
}
unsigned int F_55 ( struct V_46 * V_47 )
{
unsigned int V_72 = 0 ;
struct V_46 * V_73 ;
F_46 (tmp, crtc->dev) {
if ( V_73 == V_47 )
return V_72 ;
V_72 ++ ;
}
F_61 () ;
}
static void F_62 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
F_42 ( & V_77 -> V_42 ) ;
F_63 ( V_75 -> V_17 , V_77 ) ;
}
int F_64 ( struct V_78 * V_79 ,
const T_2 * V_80 ,
unsigned int V_81 )
{
T_2 * V_82 = NULL ;
if ( ! V_80 && V_81 )
return - V_83 ;
if ( V_80 && V_81 ) {
V_82 = F_65 ( V_80 , sizeof( * V_80 ) * V_81 ,
V_26 ) ;
if ( ! V_82 )
return - V_84 ;
}
F_59 ( V_79 -> V_85 ) ;
V_79 -> V_85 = V_82 ;
V_79 -> V_86 = V_81 ;
return 0 ;
}
static void F_66 ( struct V_74 * V_75 )
{
struct V_87 * V_77 = & V_75 -> V_88 ;
char * V_89 = NULL ;
if ( F_67 ( V_75 -> V_11 , & V_89 ) )
return;
if ( ! F_68 ( V_89 ,
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
F_69 ( L_12 , V_75 -> V_11 , V_91 ) ;
V_75 -> V_90 = V_77 -> V_90 ;
}
F_70 ( L_13 ,
V_75 -> V_11 ,
V_77 -> V_95 , V_77 -> V_96 ,
V_77 -> V_97 ? V_77 -> V_98 : 60 ,
V_77 -> V_99 ? L_14 : L_15 ,
V_77 -> V_100 ? L_16 : L_15 ,
V_77 -> V_101 ? L_17 : L_15 ) ;
}
int F_71 ( struct V_16 * V_17 ,
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
F_72 ( V_104 , 1 , 0 , V_26 ) ;
if ( V_75 -> V_107 < 0 ) {
V_22 = V_75 -> V_107 ;
goto V_108;
}
V_75 -> V_11 =
F_73 ( V_26 , L_18 ,
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
F_66 ( V_75 ) ;
F_54 ( & V_75 -> V_42 , & V_56 -> V_113 ) ;
V_56 -> V_114 ++ ;
if ( V_103 != V_115 )
F_57 ( & V_75 -> V_39 ,
V_56 -> V_116 ,
0 ) ;
F_57 ( & V_75 -> V_39 ,
V_56 -> V_117 , 0 ) ;
if ( F_56 ( V_17 , V_66 ) ) {
F_57 ( & V_75 -> V_39 , V_56 -> V_118 , 0 ) ;
}
V_75 -> V_119 = NULL ;
V_108:
if ( V_22 )
F_17 ( V_17 , & V_75 -> V_39 ) ;
V_106:
F_51 ( V_17 ) ;
return V_22 ;
}
void F_74 ( struct V_74 * V_75 )
{
struct V_16 * V_17 = V_75 -> V_17 ;
struct V_76 * V_77 , * V_120 ;
if ( V_75 -> V_121 ) {
F_75 ( V_17 , V_75 -> V_121 ) ;
V_75 -> V_121 = NULL ;
}
F_76 (mode, t, &connector->probed_modes, head)
F_62 ( V_75 , V_77 ) ;
F_76 (mode, t, &connector->modes, head)
F_62 ( V_75 , V_77 ) ;
F_77 ( & V_2 [ V_75 -> V_103 ] . V_3 ,
V_75 -> V_107 ) ;
F_59 ( V_75 -> V_122 . V_85 ) ;
F_17 ( V_17 , & V_75 -> V_39 ) ;
F_59 ( V_75 -> V_11 ) ;
V_75 -> V_11 = NULL ;
F_42 ( & V_75 -> V_42 ) ;
V_17 -> V_23 . V_114 -- ;
F_22 ( V_75 -> V_70 && ! V_75 -> V_35 -> V_71 ) ;
if ( V_75 -> V_70 && V_75 -> V_35 -> V_71 )
V_75 -> V_35 -> V_71 ( V_75 ,
V_75 -> V_70 ) ;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
}
unsigned int F_78 ( struct V_74 * V_75 )
{
unsigned int V_72 = 0 ;
struct V_74 * V_73 ;
struct V_55 * V_56 = & V_75 -> V_17 -> V_23 ;
F_22 ( ! F_79 ( & V_56 -> V_123 ) ) ;
F_80 (tmp, connector->dev) {
if ( V_73 == V_75 )
return V_72 ;
V_72 ++ ;
}
F_61 () ;
}
int F_81 ( struct V_74 * V_75 )
{
int V_22 ;
F_15 ( V_75 -> V_17 , & V_75 -> V_39 ) ;
V_22 = F_82 ( V_75 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_83 ( V_75 ) ;
if ( V_22 ) {
F_84 ( V_75 ) ;
return V_22 ;
}
return 0 ;
}
void F_85 ( struct V_74 * V_75 )
{
F_84 ( V_75 ) ;
F_86 ( V_75 ) ;
}
void F_87 ( struct V_16 * V_17 )
{
struct V_74 * V_75 ;
F_88 (connector, &dev->mode_config.connector_list, head)
F_85 ( V_75 ) ;
}
int F_89 ( struct V_16 * V_17 ,
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
V_125 -> V_11 = F_73 ( V_26 , L_18 ,
V_129 [ V_127 ] . V_11 ,
V_125 -> V_39 . V_27 ) ;
if ( ! V_125 -> V_11 ) {
V_22 = - V_84 ;
goto V_108;
}
F_54 ( & V_125 -> V_42 , & V_17 -> V_23 . V_130 ) ;
V_17 -> V_23 . V_131 ++ ;
V_108:
if ( V_22 )
F_17 ( V_17 , & V_125 -> V_39 ) ;
V_106:
F_51 ( V_17 ) ;
return V_22 ;
}
void F_90 ( struct V_124 * V_125 )
{
struct V_16 * V_17 = V_125 -> V_17 ;
F_45 ( V_17 ) ;
F_17 ( V_17 , & V_125 -> V_39 ) ;
F_59 ( V_125 -> V_11 ) ;
F_42 ( & V_125 -> V_42 ) ;
V_17 -> V_23 . V_131 -- ;
F_51 ( V_17 ) ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
}
int F_91 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_65 ,
const struct V_132 * V_35 ,
const T_1 * V_80 , unsigned int V_133 ,
enum V_134 type )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
int V_22 ;
V_22 = F_14 ( V_17 , & V_49 -> V_39 , V_135 ) ;
if ( V_22 )
return V_22 ;
F_53 ( & V_49 -> V_60 ) ;
V_49 -> V_39 . V_62 = & V_49 -> V_62 ;
V_49 -> V_17 = V_17 ;
V_49 -> V_35 = V_35 ;
V_49 -> V_136 = F_92 ( V_133 , sizeof( T_1 ) ,
V_26 ) ;
if ( ! V_49 -> V_136 ) {
F_70 ( L_19 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
return - V_84 ;
}
memcpy ( V_49 -> V_136 , V_80 , V_133 * sizeof( T_1 ) ) ;
V_49 -> V_133 = V_133 ;
V_49 -> V_65 = V_65 ;
V_49 -> type = type ;
F_54 ( & V_49 -> V_42 , & V_56 -> V_137 ) ;
V_56 -> V_138 ++ ;
if ( V_49 -> type == V_139 )
V_56 -> V_140 ++ ;
F_57 ( & V_49 -> V_39 ,
V_56 -> V_141 ,
V_49 -> type ) ;
if ( F_56 ( V_17 , V_66 ) ) {
F_57 ( & V_49 -> V_39 , V_56 -> V_142 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_118 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_143 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_144 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_145 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_146 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_147 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_148 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_149 , 0 ) ;
F_57 ( & V_49 -> V_39 , V_56 -> V_150 , 0 ) ;
}
return 0 ;
}
int F_93 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_65 ,
const struct V_132 * V_35 ,
const T_1 * V_80 , unsigned int V_133 ,
bool V_151 )
{
enum V_134 type ;
type = V_151 ? V_57 : V_139 ;
return F_91 ( V_17 , V_49 , V_65 , V_35 ,
V_80 , V_133 , type ) ;
}
void F_94 ( struct V_48 * V_49 )
{
struct V_16 * V_17 = V_49 -> V_17 ;
F_45 ( V_17 ) ;
F_59 ( V_49 -> V_136 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
F_95 ( F_44 ( & V_49 -> V_42 ) ) ;
F_42 ( & V_49 -> V_42 ) ;
V_17 -> V_23 . V_138 -- ;
if ( V_49 -> type == V_139 )
V_17 -> V_23 . V_140 -- ;
F_51 ( V_17 ) ;
F_22 ( V_49 -> V_70 && ! V_49 -> V_35 -> V_71 ) ;
if ( V_49 -> V_70 && V_49 -> V_35 -> V_71 )
V_49 -> V_35 -> V_71 ( V_49 , V_49 -> V_70 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
}
unsigned int F_96 ( struct V_48 * V_49 )
{
unsigned int V_72 = 0 ;
struct V_48 * V_73 ;
F_49 (tmp, plane->dev) {
if ( V_73 == V_49 )
return V_72 ;
V_72 ++ ;
}
F_61 () ;
}
struct V_48 *
F_97 ( struct V_16 * V_17 , int V_152 )
{
struct V_48 * V_49 ;
unsigned int V_1 = 0 ;
F_49 (plane, dev) {
if ( V_1 == V_152 )
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
static int F_98 ( struct V_16 * V_17 )
{
struct V_155 * V_156 ;
V_156 = F_99 ( V_17 , V_157 |
V_158 ,
L_21 , 0 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_116 = V_156 ;
V_156 = F_100 ( V_17 , 0 ,
L_22 , V_159 ,
F_2 ( V_159 ) ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_117 = V_156 ;
V_156 = F_99 ( V_17 ,
V_157 |
V_158 ,
L_23 , 0 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_160 = V_156 ;
V_156 = F_99 ( V_17 ,
V_157 |
V_158 ,
L_24 , 0 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_161 = V_156 ;
V_156 = F_100 ( V_17 , V_158 ,
L_25 , V_162 ,
F_2 ( V_162 ) ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_141 = V_156 ;
V_156 = F_101 ( V_17 , V_163 ,
L_26 , 0 , V_164 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_147 = V_156 ;
V_156 = F_101 ( V_17 , V_163 ,
L_27 , 0 , V_164 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_148 = V_156 ;
V_156 = F_101 ( V_17 , V_163 ,
L_28 , 0 , V_164 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_149 = V_156 ;
V_156 = F_101 ( V_17 , V_163 ,
L_29 , 0 , V_164 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_150 = V_156 ;
V_156 = F_102 ( V_17 , V_163 ,
L_30 , V_165 , V_166 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_143 = V_156 ;
V_156 = F_102 ( V_17 , V_163 ,
L_31 , V_165 , V_166 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_144 = V_156 ;
V_156 = F_101 ( V_17 , V_163 ,
L_32 , 0 , V_166 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_145 = V_156 ;
V_156 = F_101 ( V_17 , V_163 ,
L_33 , 0 , V_166 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_146 = V_156 ;
V_156 = F_103 ( V_17 , V_163 ,
L_34 , V_30 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_142 = V_156 ;
V_156 = F_103 ( V_17 , V_163 ,
L_35 , V_61 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_118 = V_156 ;
V_156 = F_104 ( V_17 , V_163 ,
L_36 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_67 = V_156 ;
V_156 = F_99 ( V_17 ,
V_163 | V_157 ,
L_37 , 0 ) ;
if ( ! V_156 )
return - V_84 ;
V_17 -> V_23 . V_68 = V_156 ;
return 0 ;
}
int F_105 ( struct V_16 * V_17 )
{
struct V_155 * V_167 ;
struct V_155 * V_168 ;
if ( V_17 -> V_23 . V_169 )
return 0 ;
V_167 =
F_100 ( V_17 , 0 ,
L_38 ,
V_170 ,
F_2 ( V_170 ) ) ;
V_17 -> V_23 . V_169 = V_167 ;
V_168 = F_100 ( V_17 , V_158 ,
L_39 ,
V_171 ,
F_2 ( V_171 ) ) ;
V_17 -> V_23 . V_172 = V_168 ;
return 0 ;
}
int F_106 ( struct V_16 * V_17 ,
unsigned int V_173 ,
char * V_110 [] )
{
struct V_155 * V_174 ;
struct V_155 * V_175 ;
unsigned int V_1 ;
if ( V_17 -> V_23 . V_176 )
return 0 ;
V_174 = F_100 ( V_17 , 0 ,
L_38 ,
V_177 ,
F_2 ( V_177 ) ) ;
V_17 -> V_23 . V_176 = V_174 ;
V_175 =
F_100 ( V_17 , V_158 ,
L_39 ,
V_178 ,
F_2 ( V_178 ) ) ;
V_17 -> V_23 . V_179 = V_175 ;
V_17 -> V_23 . V_180 =
F_101 ( V_17 , 0 , L_40 , 0 , 100 ) ;
V_17 -> V_23 . V_181 =
F_101 ( V_17 , 0 , L_41 , 0 , 100 ) ;
V_17 -> V_23 . V_182 =
F_101 ( V_17 , 0 , L_42 , 0 , 100 ) ;
V_17 -> V_23 . V_183 =
F_101 ( V_17 , 0 , L_43 , 0 , 100 ) ;
V_17 -> V_23 . V_184 =
F_99 ( V_17 , V_185 ,
L_44 , V_173 ) ;
for ( V_1 = 0 ; V_1 < V_173 ; V_1 ++ )
F_107 ( V_17 -> V_23 . V_184 , V_1 ,
V_1 , V_110 [ V_1 ] ) ;
V_17 -> V_23 . V_186 =
F_101 ( V_17 , 0 , L_45 , 0 , 100 ) ;
V_17 -> V_23 . V_187 =
F_101 ( V_17 , 0 , L_46 , 0 , 100 ) ;
V_17 -> V_23 . V_188 =
F_101 ( V_17 , 0 , L_47 , 0 , 100 ) ;
V_17 -> V_23 . V_189 =
F_101 ( V_17 , 0 , L_48 , 0 , 100 ) ;
V_17 -> V_23 . V_190 =
F_101 ( V_17 , 0 , L_49 , 0 , 100 ) ;
V_17 -> V_23 . V_191 =
F_101 ( V_17 , 0 , L_50 , 0 , 100 ) ;
return 0 ;
}
int F_108 ( struct V_16 * V_17 )
{
struct V_155 * V_192 ;
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
return - V_84 ;
return 0 ;
}
int F_110 ( struct V_16 * V_17 )
{
struct V_155 * V_197 ;
if ( V_17 -> V_23 . V_198 )
return 0 ;
V_197 =
F_100 ( V_17 , V_158 ,
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
F_101 ( V_17 , V_158 , L_54 , 0 , 0xffffffff ) ;
V_17 -> V_23 . V_201 =
F_101 ( V_17 , V_158 , L_55 , 0 , 0xffffffff ) ;
if ( V_17 -> V_23 . V_200 == NULL ||
V_17 -> V_23 . V_201 == NULL )
return - V_84 ;
return 0 ;
}
int F_112 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_205 * V_206 = V_202 ;
struct V_207 * V_208 ;
struct V_32 * V_33 ;
struct V_74 * V_75 ;
struct V_46 * V_47 ;
struct V_124 * V_125 ;
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
return - V_83 ;
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
F_11 ( & V_17 -> V_23 . V_60 ) ;
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
F_70 ( L_57 , V_125 -> V_39 . V_27 ,
V_125 -> V_11 ) ;
if ( F_114 ( V_125 -> V_39 . V_27 , V_217 +
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
V_75 -> V_39 . V_27 ,
V_75 -> V_11 ) ;
if ( F_114 ( V_75 -> V_39 . V_27 ,
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
F_13 ( & V_17 -> V_23 . V_60 ) ;
return V_22 ;
}
int F_116 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_233 * V_234 = V_202 ;
struct V_46 * V_47 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
V_47 = F_117 ( V_17 , V_234 -> V_215 ) ;
if ( ! V_47 )
return - V_235 ;
F_118 ( V_47 , V_47 -> V_52 ) ;
V_234 -> V_236 = V_47 -> V_236 ;
if ( V_47 -> V_52 -> V_33 )
V_234 -> V_214 = V_47 -> V_52 -> V_33 -> V_39 . V_27 ;
else
V_234 -> V_214 = 0 ;
if ( V_47 -> V_70 ) {
V_234 -> V_237 = V_47 -> V_52 -> V_70 -> V_238 >> 16 ;
V_234 -> V_239 = V_47 -> V_52 -> V_70 -> V_240 >> 16 ;
if ( V_47 -> V_70 -> V_241 ) {
F_119 ( & V_234 -> V_77 , & V_47 -> V_70 -> V_77 ) ;
V_234 -> V_242 = 1 ;
} else {
V_234 -> V_242 = 0 ;
}
} else {
V_234 -> V_237 = V_47 -> V_237 ;
V_234 -> V_239 = V_47 -> V_239 ;
if ( V_47 -> V_243 ) {
F_119 ( & V_234 -> V_77 , & V_47 -> V_77 ) ;
V_234 -> V_242 = 1 ;
} else {
V_234 -> V_242 = 0 ;
}
}
F_120 ( V_47 ) ;
return 0 ;
}
static bool F_121 ( const struct V_76 * V_77 ,
const struct V_203 * V_204 )
{
if ( ! V_204 -> V_244 && F_122 ( V_77 ) )
return false ;
return true ;
}
static struct V_124 * F_123 ( struct V_74 * V_75 )
{
if ( V_75 -> V_70 )
return V_75 -> V_70 -> V_245 ;
return V_75 -> V_125 ;
}
static int F_124 ( struct V_18 * V_19 , bool V_246 ,
T_1 T_3 * V_247 , T_4 T_3 * V_248 ,
T_1 * V_249 )
{
int V_250 ;
int V_1 , V_22 , V_213 ;
V_250 = V_19 -> V_62 -> V_251 ;
if ( ! V_246 )
V_250 -= V_19 -> V_62 -> V_252 ;
if ( ( * V_249 >= V_250 ) && V_250 ) {
for ( V_1 = 0 , V_213 = 0 ; V_213 < V_250 ; V_1 ++ ) {
struct V_155 * V_156 = V_19 -> V_62 -> V_62 [ V_1 ] ;
T_4 V_253 ;
if ( ( V_156 -> V_254 & V_163 ) && ! V_246 )
continue;
V_22 = F_125 ( V_19 , V_156 , & V_253 ) ;
if ( V_22 )
return V_22 ;
if ( F_114 ( V_156 -> V_39 . V_27 , V_247 + V_213 ) )
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
struct V_74 * V_75 ;
struct V_124 * V_125 ;
struct V_76 * V_77 ;
int V_257 = 0 ;
int V_258 = 0 ;
int V_22 = 0 ;
int V_213 = 0 ;
int V_1 ;
struct V_259 V_260 ;
struct V_259 T_3 * V_261 ;
T_1 T_3 * V_262 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
memset ( & V_260 , 0 , sizeof( struct V_259 ) ) ;
F_70 ( L_60 , V_256 -> V_216 ) ;
F_11 ( & V_17 -> V_23 . V_60 ) ;
V_75 = F_127 ( V_17 , V_256 -> V_216 ) ;
if ( ! V_75 ) {
V_22 = - V_235 ;
goto V_106;
}
for ( V_1 = 0 ; V_1 < V_263 ; V_1 ++ )
if ( V_75 -> V_264 [ V_1 ] != 0 )
V_258 ++ ;
if ( V_256 -> V_265 == 0 ) {
V_75 -> V_35 -> V_266 ( V_75 ,
V_17 -> V_23 . V_225 ,
V_17 -> V_23 . V_223 ) ;
}
F_88 (mode, &connector->modes, head)
if ( F_121 ( V_77 , V_204 ) )
V_257 ++ ;
V_256 -> V_216 = V_75 -> V_39 . V_27 ;
V_256 -> V_103 = V_75 -> V_103 ;
V_256 -> V_107 = V_75 -> V_107 ;
V_256 -> V_267 = V_75 -> V_122 . V_268 ;
V_256 -> V_269 = V_75 -> V_122 . V_270 ;
V_256 -> V_271 = V_75 -> V_122 . V_8 ;
V_256 -> V_272 = V_75 -> V_5 ;
F_128 ( & V_17 -> V_23 . V_123 , NULL ) ;
V_125 = F_123 ( V_75 ) ;
if ( V_125 )
V_256 -> V_217 = V_125 -> V_39 . V_27 ;
else
V_256 -> V_217 = 0 ;
if ( ( V_256 -> V_265 >= V_257 ) && V_257 ) {
V_213 = 0 ;
V_261 = (struct V_259 T_3 * ) ( unsigned long ) V_256 -> V_273 ;
F_88 (mode, &connector->modes, head) {
if ( ! F_121 ( V_77 , V_204 ) )
continue;
F_119 ( & V_260 , V_77 ) ;
if ( F_129 ( V_261 + V_213 ,
& V_260 , sizeof( V_260 ) ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_213 ++ ;
}
}
V_256 -> V_265 = V_257 ;
V_22 = F_124 ( & V_75 -> V_39 , V_204 -> V_246 ,
( T_1 T_3 * ) ( unsigned long ) ( V_256 -> V_274 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_256 -> V_275 ) ,
& V_256 -> V_276 ) ;
if ( V_22 )
goto V_40;
if ( ( V_256 -> V_229 >= V_258 ) && V_258 ) {
V_213 = 0 ;
V_262 = ( T_1 T_3 * ) ( unsigned long ) ( V_256 -> V_277 ) ;
for ( V_1 = 0 ; V_1 < V_263 ; V_1 ++ ) {
if ( V_75 -> V_264 [ V_1 ] != 0 ) {
if ( F_114 ( V_75 -> V_264 [ V_1 ] ,
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
F_130 ( & V_17 -> V_23 . V_123 ) ;
V_106:
F_13 ( & V_17 -> V_23 . V_60 ) ;
return V_22 ;
}
static struct V_46 * F_131 ( struct V_124 * V_125 )
{
struct V_74 * V_75 ;
struct V_16 * V_17 = V_125 -> V_17 ;
bool V_278 = false ;
F_80 (connector, dev) {
if ( ! V_75 -> V_70 )
continue;
V_278 = true ;
if ( V_75 -> V_70 -> V_245 != V_125 )
continue;
return V_75 -> V_70 -> V_47 ;
}
if ( V_278 )
return NULL ;
return V_125 -> V_47 ;
}
int F_132 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_279 * V_280 = V_202 ;
struct V_124 * V_125 ;
struct V_46 * V_47 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
V_125 = F_133 ( V_17 , V_280 -> V_217 ) ;
if ( ! V_125 )
return - V_235 ;
F_128 ( & V_17 -> V_23 . V_123 , NULL ) ;
V_47 = F_131 ( V_125 ) ;
if ( V_47 )
V_280 -> V_215 = V_47 -> V_39 . V_27 ;
else
V_280 -> V_215 = 0 ;
F_130 ( & V_17 -> V_23 . V_123 ) ;
V_280 -> V_127 = V_125 -> V_127 ;
V_280 -> V_217 = V_125 -> V_39 . V_27 ;
V_280 -> V_65 = V_125 -> V_65 ;
V_280 -> V_281 = V_125 -> V_281 ;
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
return - V_83 ;
V_56 = & V_17 -> V_23 ;
if ( V_204 -> V_286 )
V_285 = V_56 -> V_138 ;
else
V_285 = V_56 -> V_140 ;
if ( V_285 &&
( V_283 -> V_287 >= V_285 ) ) {
V_284 = ( T_1 T_3 * ) ( unsigned long ) V_283 -> V_288 ;
F_49 (plane, dev) {
if ( V_49 -> type != V_139 &&
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
return - V_83 ;
V_49 = F_136 ( V_17 , V_283 -> V_291 ) ;
if ( ! V_49 )
return - V_235 ;
F_128 ( & V_49 -> V_60 , NULL ) ;
if ( V_49 -> V_47 )
V_283 -> V_215 = V_49 -> V_47 -> V_39 . V_27 ;
else
V_283 -> V_215 = 0 ;
if ( V_49 -> V_33 )
V_283 -> V_214 = V_49 -> V_33 -> V_39 . V_27 ;
else
V_283 -> V_214 = 0 ;
F_130 ( & V_49 -> V_60 ) ;
V_283 -> V_291 = V_49 -> V_39 . V_27 ;
V_283 -> V_65 = V_49 -> V_65 ;
V_283 -> V_236 = 0 ;
if ( V_49 -> V_133 &&
( V_283 -> V_292 >= V_49 -> V_133 ) ) {
V_290 = ( T_1 T_3 * ) ( unsigned long ) V_283 -> V_293 ;
if ( F_129 ( V_290 ,
V_49 -> V_136 ,
sizeof( T_1 ) * V_49 -> V_133 ) ) {
return - V_222 ;
}
}
V_283 -> V_292 = V_49 -> V_133 ;
return 0 ;
}
int F_137 ( const struct V_48 * V_49 , T_2 V_13 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_49 -> V_133 ; V_1 ++ ) {
if ( V_13 == V_49 -> V_136 [ V_1 ] )
return 0 ;
}
return - V_83 ;
}
static int F_138 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_5 V_294 , T_5 V_295 ,
T_1 V_296 , T_1 V_297 ,
T_1 V_238 , T_1 V_240 ,
T_1 V_298 , T_1 V_299 )
{
int V_22 = 0 ;
unsigned int V_300 , V_301 ;
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
if ( ! ( V_49 -> V_65 & F_139 ( V_47 ) ) ) {
F_70 ( L_61 ) ;
V_22 = - V_83 ;
goto V_40;
}
V_22 = F_137 ( V_49 , V_33 -> V_302 ) ;
if ( V_22 ) {
F_70 ( L_62 ,
F_9 ( V_33 -> V_302 ) ) ;
goto V_40;
}
if ( V_296 > V_166 ||
V_294 > V_166 - ( T_5 ) V_296 ||
V_297 > V_166 ||
V_295 > V_166 - ( T_5 ) V_297 ) {
F_70 ( L_63 ,
V_296 , V_297 , V_294 , V_295 ) ;
return - V_303 ;
}
V_300 = V_33 -> V_304 << 16 ;
V_301 = V_33 -> V_305 << 16 ;
if ( V_298 > V_300 ||
V_238 > V_300 - V_298 ||
V_299 > V_301 ||
V_240 > V_301 - V_299 ) {
F_70 ( L_64
L_65 ,
V_298 >> 16 , ( ( V_298 & 0xffff ) * 15625 ) >> 10 ,
V_299 >> 16 , ( ( V_299 & 0xffff ) * 15625 ) >> 10 ,
V_238 >> 16 , ( ( V_238 & 0xffff ) * 15625 ) >> 10 ,
V_240 >> 16 , ( ( V_240 & 0xffff ) * 15625 ) >> 10 ) ;
V_22 = - V_306 ;
goto V_40;
}
V_49 -> V_153 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_307 ( V_49 , V_47 , V_33 ,
V_294 , V_295 , V_296 , V_297 ,
V_238 , V_240 , V_298 , V_299 ) ;
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
static int F_140 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_5 V_294 , T_5 V_295 ,
T_1 V_296 , T_1 V_297 ,
T_1 V_238 , T_1 V_240 ,
T_1 V_298 , T_1 V_299 )
{
int V_22 ;
F_45 ( V_49 -> V_17 ) ;
V_22 = F_138 ( V_49 , V_47 , V_33 ,
V_294 , V_295 , V_296 , V_297 ,
V_238 , V_240 , V_298 , V_299 ) ;
F_51 ( V_49 -> V_17 ) ;
return V_22 ;
}
int F_141 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_308 * V_309 = V_202 ;
struct V_48 * V_49 ;
struct V_46 * V_47 = NULL ;
struct V_32 * V_33 = NULL ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
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
return F_140 ( V_49 , V_47 , V_33 ,
V_309 -> V_294 , V_309 -> V_295 ,
V_309 -> V_296 , V_309 -> V_297 ,
V_309 -> V_238 , V_309 -> V_240 ,
V_309 -> V_298 , V_309 -> V_299 ) ;
}
int F_47 ( struct V_50 * V_51 )
{
struct V_46 * V_47 = V_51 -> V_47 ;
struct V_32 * V_33 ;
struct V_46 * V_73 ;
int V_22 ;
F_46 (tmp, crtc->dev)
V_73 -> V_52 -> V_153 = V_73 -> V_52 -> V_33 ;
V_33 = V_51 -> V_33 ;
V_22 = V_47 -> V_35 -> V_310 ( V_51 ) ;
if ( V_22 == 0 ) {
V_47 -> V_52 -> V_47 = V_47 ;
V_47 -> V_52 -> V_33 = V_33 ;
}
F_46 (tmp, crtc->dev) {
if ( V_73 -> V_52 -> V_33 )
F_38 ( V_73 -> V_52 -> V_33 ) ;
if ( V_73 -> V_52 -> V_153 )
F_34 ( V_73 -> V_52 -> V_153 ) ;
V_73 -> V_52 -> V_153 = NULL ;
}
return V_22 ;
}
void F_142 ( const struct V_76 * V_77 ,
int * V_311 , int * V_312 )
{
struct V_76 V_313 ;
F_143 ( & V_313 , V_77 ) ;
F_144 ( & V_313 , V_314 ) ;
* V_311 = V_313 . V_315 ;
* V_312 = V_313 . V_316 ;
}
int F_145 ( const struct V_46 * V_47 ,
int V_237 , int V_239 ,
const struct V_76 * V_77 ,
const struct V_32 * V_33 )
{
int V_311 , V_312 ;
F_142 ( V_77 , & V_311 , & V_312 ) ;
if ( V_47 -> V_59 )
F_146 ( V_311 , V_312 ) ;
if ( V_311 > V_33 -> V_304 ||
V_312 > V_33 -> V_305 ||
V_237 > V_33 -> V_304 - V_311 ||
V_239 > V_33 -> V_305 - V_312 ) {
F_70 ( L_69 ,
V_33 -> V_304 , V_33 -> V_305 , V_311 , V_312 , V_237 , V_239 ,
V_47 -> V_59 ? L_70 : L_15 ) ;
return - V_306 ;
}
return 0 ;
}
int F_147 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
struct V_233 * V_317 = V_202 ;
struct V_46 * V_47 ;
struct V_74 * * V_318 = NULL , * V_75 ;
struct V_32 * V_33 = NULL ;
struct V_76 * V_77 = NULL ;
struct V_50 V_51 ;
T_1 T_3 * V_319 ;
int V_22 ;
int V_1 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
if ( V_317 -> V_237 & 0xffff0000 || V_317 -> V_239 & 0xffff0000 )
return - V_303 ;
F_45 ( V_17 ) ;
V_47 = F_117 ( V_17 , V_317 -> V_215 ) ;
if ( ! V_47 ) {
F_70 ( L_71 , V_317 -> V_215 ) ;
V_22 = - V_235 ;
goto V_40;
}
F_70 ( L_56 , V_47 -> V_39 . V_27 ) ;
if ( V_317 -> V_242 ) {
if ( V_317 -> V_214 == - 1 ) {
if ( ! V_47 -> V_52 -> V_33 ) {
F_70 ( L_72 ) ;
V_22 = - V_83 ;
goto V_40;
}
V_33 = V_47 -> V_52 -> V_33 ;
F_38 ( V_33 ) ;
} else {
V_33 = F_32 ( V_17 , V_317 -> V_214 ) ;
if ( ! V_33 ) {
F_70 ( L_73 ,
V_317 -> V_214 ) ;
V_22 = - V_235 ;
goto V_40;
}
}
V_77 = F_148 ( V_17 ) ;
if ( ! V_77 ) {
V_22 = - V_84 ;
goto V_40;
}
V_22 = F_149 ( V_77 , & V_317 -> V_77 ) ;
if ( V_22 ) {
F_70 ( L_74 ) ;
goto V_40;
}
F_144 ( V_77 , V_320 ) ;
if ( ! V_47 -> V_52 -> V_321 ) {
V_22 = F_137 ( V_47 -> V_52 ,
V_33 -> V_302 ) ;
if ( V_22 ) {
F_70 ( L_62 ,
F_9 ( V_33 -> V_302 ) ) ;
goto V_40;
}
}
V_22 = F_145 ( V_47 , V_317 -> V_237 , V_317 -> V_239 ,
V_77 , V_33 ) ;
if ( V_22 )
goto V_40;
}
if ( V_317 -> V_231 == 0 && V_77 ) {
F_70 ( L_75 ) ;
V_22 = - V_83 ;
goto V_40;
}
if ( V_317 -> V_231 > 0 && ( ! V_77 || ! V_33 ) ) {
F_70 ( L_76 ,
V_317 -> V_231 ) ;
V_22 = - V_83 ;
goto V_40;
}
if ( V_317 -> V_231 > 0 ) {
T_2 V_322 ;
if ( V_317 -> V_231 > V_56 -> V_114 ) {
V_22 = - V_83 ;
goto V_40;
}
V_318 = F_92 ( V_317 -> V_231 ,
sizeof( struct V_74 * ) ,
V_26 ) ;
if ( ! V_318 ) {
V_22 = - V_84 ;
goto V_40;
}
for ( V_1 = 0 ; V_1 < V_317 -> V_231 ; V_1 ++ ) {
V_319 = ( T_1 T_3 * ) ( unsigned long ) V_317 -> V_319 ;
if ( F_150 ( V_322 , & V_319 [ V_1 ] ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_75 = F_127 ( V_17 , V_322 ) ;
if ( ! V_75 ) {
F_70 ( L_77 ,
V_322 ) ;
V_22 = - V_235 ;
goto V_40;
}
F_70 ( L_58 ,
V_75 -> V_39 . V_27 ,
V_75 -> V_11 ) ;
V_318 [ V_1 ] = V_75 ;
}
}
V_51 . V_47 = V_47 ;
V_51 . V_237 = V_317 -> V_237 ;
V_51 . V_239 = V_317 -> V_239 ;
V_51 . V_77 = V_77 ;
V_51 . V_323 = V_318 ;
V_51 . V_324 = V_317 -> V_231 ;
V_51 . V_33 = V_33 ;
V_22 = F_47 ( & V_51 ) ;
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
F_59 ( V_318 ) ;
F_63 ( V_17 , V_77 ) ;
F_51 ( V_17 ) ;
return V_22 ;
}
static int F_151 ( struct V_46 * V_47 ,
struct V_325 * V_326 ,
struct V_203 * V_204 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
struct V_32 * V_33 = NULL ;
struct V_327 V_328 = {
. V_304 = V_326 -> V_304 ,
. V_305 = V_326 -> V_305 ,
. V_302 = V_329 ,
. V_330 = { V_326 -> V_304 * 4 } ,
. V_331 = { V_326 -> V_332 } ,
} ;
T_5 V_294 , V_295 ;
T_1 V_296 = 0 , V_297 = 0 ;
T_1 V_298 = 0 , V_299 = 0 ;
int V_22 = 0 ;
F_95 ( ! V_47 -> V_53 ) ;
F_22 ( V_47 -> V_53 -> V_47 != V_47 && V_47 -> V_53 -> V_47 != NULL ) ;
if ( V_326 -> V_254 & V_333 ) {
if ( V_326 -> V_332 ) {
V_33 = F_152 ( V_17 , & V_328 , V_204 ) ;
if ( F_153 ( V_33 ) ) {
F_70 ( L_78 ) ;
return F_154 ( V_33 ) ;
}
} else {
V_33 = NULL ;
}
} else {
V_33 = V_47 -> V_53 -> V_33 ;
if ( V_33 )
F_38 ( V_33 ) ;
}
if ( V_326 -> V_254 & V_334 ) {
V_294 = V_326 -> V_237 ;
V_295 = V_326 -> V_239 ;
} else {
V_294 = V_47 -> V_335 ;
V_295 = V_47 -> V_336 ;
}
if ( V_33 ) {
V_296 = V_33 -> V_304 ;
V_297 = V_33 -> V_305 ;
V_298 = V_33 -> V_304 << 16 ;
V_299 = V_33 -> V_305 << 16 ;
}
V_22 = F_138 ( V_47 -> V_53 , V_47 , V_33 ,
V_294 , V_295 , V_296 , V_297 ,
0 , 0 , V_298 , V_299 ) ;
if ( V_22 == 0 && V_326 -> V_254 & V_334 ) {
V_47 -> V_335 = V_326 -> V_237 ;
V_47 -> V_336 = V_326 -> V_239 ;
}
return V_22 ;
}
static int F_155 ( struct V_16 * V_17 ,
struct V_325 * V_326 ,
struct V_203 * V_204 )
{
struct V_46 * V_47 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
if ( ! V_326 -> V_254 || ( ~ V_337 & V_326 -> V_254 ) )
return - V_83 ;
V_47 = F_117 ( V_17 , V_326 -> V_215 ) ;
if ( ! V_47 ) {
F_70 ( L_71 , V_326 -> V_215 ) ;
return - V_235 ;
}
F_118 ( V_47 , V_47 -> V_53 ) ;
if ( V_47 -> V_53 ) {
V_22 = F_151 ( V_47 , V_326 , V_204 ) ;
goto V_40;
}
if ( V_326 -> V_254 & V_333 ) {
if ( ! V_47 -> V_35 -> V_338 && ! V_47 -> V_35 -> V_339 ) {
V_22 = - V_340 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_339 )
V_22 = V_47 -> V_35 -> V_339 ( V_47 , V_204 , V_326 -> V_332 ,
V_326 -> V_304 , V_326 -> V_305 , V_326 -> V_341 , V_326 -> V_342 ) ;
else
V_22 = V_47 -> V_35 -> V_338 ( V_47 , V_204 , V_326 -> V_332 ,
V_326 -> V_304 , V_326 -> V_305 ) ;
}
if ( V_326 -> V_254 & V_334 ) {
if ( V_47 -> V_35 -> V_343 ) {
V_22 = V_47 -> V_35 -> V_343 ( V_47 , V_326 -> V_237 , V_326 -> V_239 ) ;
} else {
V_22 = - V_222 ;
goto V_40;
}
}
V_40:
F_120 ( V_47 ) ;
return V_22 ;
}
int F_156 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_344 * V_326 = V_202 ;
struct V_325 V_345 ;
memcpy ( & V_345 , V_326 , sizeof( struct V_344 ) ) ;
V_345 . V_341 = V_345 . V_342 = 0 ;
return F_155 ( V_17 , & V_345 , V_204 ) ;
}
int F_157 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_325 * V_326 = V_202 ;
return F_155 ( V_17 , V_326 , V_204 ) ;
}
T_1 F_158 ( T_1 V_346 , T_1 V_347 )
{
T_1 V_348 ;
switch ( V_346 ) {
case 8 :
V_348 = V_349 ;
break;
case 16 :
if ( V_347 == 15 )
V_348 = V_350 ;
else
V_348 = V_351 ;
break;
case 24 :
V_348 = V_352 ;
break;
case 32 :
if ( V_347 == 24 )
V_348 = V_353 ;
else if ( V_347 == 30 )
V_348 = V_354 ;
else
V_348 = V_329 ;
break;
default:
F_48 ( L_79 ) ;
V_348 = V_353 ;
break;
}
return V_348 ;
}
int F_159 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_355 * V_356 = V_202 ;
struct V_327 V_357 = {} ;
int V_22 ;
V_357 . V_214 = V_356 -> V_214 ;
V_357 . V_304 = V_356 -> V_304 ;
V_357 . V_305 = V_356 -> V_305 ;
V_357 . V_330 [ 0 ] = V_356 -> V_358 ;
V_357 . V_302 = F_158 ( V_356 -> V_346 , V_356 -> V_347 ) ;
V_357 . V_331 [ 0 ] = V_356 -> V_332 ;
V_22 = F_160 ( V_17 , & V_357 , V_204 ) ;
if ( V_22 )
return V_22 ;
V_356 -> V_214 = V_357 . V_214 ;
return 0 ;
}
static int F_161 ( const struct V_327 * V_357 )
{
T_1 V_13 = V_357 -> V_302 & ~ V_15 ;
switch ( V_13 ) {
case V_349 :
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
case V_350 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_351 :
case V_376 :
case V_352 :
case V_377 :
case V_353 :
case V_378 :
case V_379 :
case V_380 :
case V_329 :
case V_381 :
case V_382 :
case V_383 :
case V_354 :
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
case V_410 :
case V_411 :
return 0 ;
default:
F_70 ( L_80 ,
F_9 ( V_357 -> V_302 ) ) ;
return - V_83 ;
}
}
static int F_162 ( const struct V_327 * V_357 )
{
int V_22 , V_412 , V_413 , V_285 , V_1 ;
V_22 = F_161 ( V_357 ) ;
if ( V_22 ) {
F_70 ( L_81 ,
F_9 ( V_357 -> V_302 ) ) ;
return V_22 ;
}
V_412 = F_163 ( V_357 -> V_302 ) ;
V_413 = F_164 ( V_357 -> V_302 ) ;
V_285 = F_165 ( V_357 -> V_302 ) ;
if ( V_357 -> V_304 == 0 || V_357 -> V_304 % V_412 ) {
F_70 ( L_82 , V_357 -> V_304 ) ;
return - V_83 ;
}
if ( V_357 -> V_305 == 0 || V_357 -> V_305 % V_413 ) {
F_70 ( L_83 , V_357 -> V_305 ) ;
return - V_83 ;
}
for ( V_1 = 0 ; V_1 < V_285 ; V_1 ++ ) {
unsigned int V_304 = V_357 -> V_304 / ( V_1 != 0 ? V_412 : 1 ) ;
unsigned int V_305 = V_357 -> V_305 / ( V_1 != 0 ? V_413 : 1 ) ;
unsigned int V_414 = F_166 ( V_357 -> V_302 , V_1 ) ;
if ( ! V_357 -> V_331 [ V_1 ] ) {
F_70 ( L_84 , V_1 ) ;
return - V_83 ;
}
if ( ( T_4 ) V_304 * V_414 > V_164 )
return - V_303 ;
if ( ( T_4 ) V_305 * V_357 -> V_330 [ V_1 ] + V_357 -> V_415 [ V_1 ] > V_164 )
return - V_303 ;
if ( V_357 -> V_330 [ V_1 ] < V_304 * V_414 ) {
F_70 ( L_85 , V_357 -> V_330 [ V_1 ] , V_1 ) ;
return - V_83 ;
}
if ( V_357 -> V_416 [ V_1 ] && ! ( V_357 -> V_254 & V_417 ) ) {
F_70 ( L_86 ,
V_357 -> V_416 [ V_1 ] , V_1 ) ;
return - V_83 ;
}
switch ( V_357 -> V_416 [ V_1 ] ) {
case V_418 :
if ( V_357 -> V_302 != V_396 ||
V_304 % 128 || V_305 % 32 ||
V_357 -> V_330 [ V_1 ] % 128 ) {
F_70 ( L_87 , V_1 ) ;
return - V_83 ;
}
break;
default:
break;
}
}
for ( V_1 = V_285 ; V_1 < 4 ; V_1 ++ ) {
if ( V_357 -> V_416 [ V_1 ] ) {
F_70 ( L_88 , V_1 ) ;
return - V_83 ;
}
if ( ! ( V_357 -> V_254 & V_417 ) )
continue;
if ( V_357 -> V_331 [ V_1 ] ) {
F_70 ( L_89 , V_1 ) ;
return - V_83 ;
}
if ( V_357 -> V_330 [ V_1 ] ) {
F_70 ( L_90 , V_1 ) ;
return - V_83 ;
}
if ( V_357 -> V_415 [ V_1 ] ) {
F_70 ( L_91 , V_1 ) ;
return - V_83 ;
}
}
return 0 ;
}
static struct V_32 *
F_152 ( struct V_16 * V_17 ,
struct V_327 * V_357 ,
struct V_203 * V_204 )
{
struct V_55 * V_56 = & V_17 -> V_23 ;
struct V_32 * V_33 ;
int V_22 ;
if ( V_357 -> V_254 & ~ ( V_419 | V_417 ) ) {
F_70 ( L_92 , V_357 -> V_254 ) ;
return F_167 ( - V_83 ) ;
}
if ( ( V_56 -> V_226 > V_357 -> V_304 ) || ( V_357 -> V_304 > V_56 -> V_225 ) ) {
F_70 ( L_93 ,
V_357 -> V_304 , V_56 -> V_226 , V_56 -> V_225 ) ;
return F_167 ( - V_83 ) ;
}
if ( ( V_56 -> V_224 > V_357 -> V_305 ) || ( V_357 -> V_305 > V_56 -> V_223 ) ) {
F_70 ( L_94 ,
V_357 -> V_305 , V_56 -> V_224 , V_56 -> V_223 ) ;
return F_167 ( - V_83 ) ;
}
if ( V_357 -> V_254 & V_417 &&
! V_17 -> V_23 . V_420 ) {
F_70 ( L_95 ) ;
return F_167 ( - V_83 ) ;
}
V_22 = F_162 ( V_357 ) ;
if ( V_22 )
return F_167 ( V_22 ) ;
V_33 = V_17 -> V_23 . V_35 -> V_421 ( V_17 , V_204 , V_357 ) ;
if ( F_153 ( V_33 ) ) {
F_70 ( L_96 ) ;
return V_33 ;
}
return V_33 ;
}
int F_160 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_327 * V_357 = V_202 ;
struct V_32 * V_33 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
V_33 = F_152 ( V_17 , V_357 , V_204 ) ;
if ( F_153 ( V_33 ) )
return F_154 ( V_33 ) ;
F_70 ( L_97 , V_33 -> V_39 . V_27 ) ;
F_11 ( & V_204 -> V_219 ) ;
V_357 -> V_214 = V_33 -> V_39 . V_27 ;
F_26 ( & V_33 -> V_38 , & V_204 -> V_422 ) ;
F_13 ( & V_204 -> V_219 ) ;
return 0 ;
}
int F_168 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_32 * V_33 = NULL ;
struct V_32 * V_423 = NULL ;
T_1 * V_27 = V_202 ;
int V_424 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
F_11 ( & V_204 -> V_219 ) ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
V_33 = F_30 ( V_17 , * V_27 ) ;
if ( ! V_33 )
goto V_425;
F_88 (fbl, &file_priv->fbs, filp_head)
if ( V_33 == V_423 )
V_424 = 1 ;
if ( ! V_424 )
goto V_425;
F_27 ( V_17 , V_33 ) ;
F_169 ( & V_33 -> V_38 ) ;
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_204 -> V_219 ) ;
F_43 ( V_33 ) ;
return 0 ;
V_425:
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_204 -> V_219 ) ;
return - V_235 ;
}
int F_170 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_355 * V_357 = V_202 ;
struct V_32 * V_33 ;
int V_22 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
V_33 = F_32 ( V_17 , V_357 -> V_214 ) ;
if ( ! V_33 )
return - V_235 ;
V_357 -> V_305 = V_33 -> V_305 ;
V_357 -> V_304 = V_33 -> V_304 ;
V_357 -> V_347 = V_33 -> V_347 ;
V_357 -> V_346 = V_33 -> V_426 ;
V_357 -> V_358 = V_33 -> V_330 [ 0 ] ;
if ( V_33 -> V_35 -> V_427 ) {
if ( V_204 -> V_428 || F_171 ( V_429 ) ||
F_172 ( V_204 ) ) {
V_22 = V_33 -> V_35 -> V_427 ( V_33 , V_204 ,
& V_357 -> V_332 ) ;
} else {
V_357 -> V_332 = 0 ;
V_22 = 0 ;
}
} else {
V_22 = - V_430 ;
}
F_34 ( V_33 ) ;
return V_22 ;
}
int F_173 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_431 T_3 * V_432 ;
struct V_431 * V_433 = NULL ;
struct V_434 * V_357 = V_202 ;
struct V_32 * V_33 ;
unsigned V_254 ;
int V_435 ;
int V_22 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
V_33 = F_32 ( V_17 , V_357 -> V_214 ) ;
if ( ! V_33 )
return - V_235 ;
V_435 = V_357 -> V_435 ;
V_432 = (struct V_431 T_3 * ) ( unsigned long ) V_357 -> V_432 ;
if ( ! V_435 != ! V_432 ) {
V_22 = - V_83 ;
goto V_436;
}
V_254 = V_437 & V_357 -> V_254 ;
if ( V_254 & V_438 && ( V_435 % 2 ) ) {
V_22 = - V_83 ;
goto V_436;
}
if ( V_435 && V_432 ) {
if ( V_435 < 0 || V_435 > V_439 ) {
V_22 = - V_83 ;
goto V_436;
}
V_433 = F_174 ( V_435 , sizeof( * V_433 ) , V_26 ) ;
if ( ! V_433 ) {
V_22 = - V_84 ;
goto V_436;
}
V_22 = F_175 ( V_433 , V_432 ,
V_435 * sizeof( * V_433 ) ) ;
if ( V_22 ) {
V_22 = - V_222 ;
goto V_440;
}
}
if ( V_33 -> V_35 -> V_441 ) {
V_22 = V_33 -> V_35 -> V_441 ( V_33 , V_204 , V_254 , V_357 -> V_442 ,
V_433 , V_435 ) ;
} else {
V_22 = - V_443 ;
}
V_440:
F_59 ( V_433 ) ;
V_436:
F_34 ( V_33 ) ;
return V_22 ;
}
void F_176 ( struct V_203 * V_444 )
{
struct V_16 * V_17 = V_444 -> V_445 -> V_17 ;
struct V_32 * V_33 , * V_446 ;
F_76 (fb, tfb, &priv->fbs, filp_head) {
F_11 ( & V_17 -> V_23 . V_36 ) ;
F_27 ( V_17 , V_33 ) ;
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_169 ( & V_33 -> V_38 ) ;
F_43 ( V_33 ) ;
}
}
struct V_155 * F_99 ( struct V_16 * V_17 , int V_254 ,
const char * V_11 , int V_447 )
{
struct V_155 * V_448 = NULL ;
int V_22 ;
V_448 = F_177 ( sizeof( struct V_155 ) , V_26 ) ;
if ( ! V_448 )
return NULL ;
V_448 -> V_17 = V_17 ;
if ( V_447 ) {
V_448 -> V_449 = F_174 ( V_447 , sizeof( T_4 ) ,
V_26 ) ;
if ( ! V_448 -> V_449 )
goto V_450;
}
V_22 = F_14 ( V_17 , & V_448 -> V_39 , V_451 ) ;
if ( V_22 )
goto V_450;
V_448 -> V_254 = V_254 ;
V_448 -> V_447 = V_447 ;
F_25 ( & V_448 -> V_452 ) ;
if ( V_11 ) {
strncpy ( V_448 -> V_11 , V_11 , V_453 ) ;
V_448 -> V_11 [ V_453 - 1 ] = '\0' ;
}
F_54 ( & V_448 -> V_42 , & V_17 -> V_23 . V_454 ) ;
F_22 ( ! F_178 ( V_448 ) ) ;
return V_448 ;
V_450:
F_59 ( V_448 -> V_449 ) ;
F_59 ( V_448 ) ;
return NULL ;
}
struct V_155 * F_100 ( struct V_16 * V_17 , int V_254 ,
const char * V_11 ,
const struct V_455 * V_456 ,
int V_447 )
{
struct V_155 * V_448 ;
int V_1 , V_22 ;
V_254 |= V_185 ;
V_448 = F_99 ( V_17 , V_254 , V_11 , V_447 ) ;
if ( ! V_448 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_447 ; V_1 ++ ) {
V_22 = F_107 ( V_448 , V_1 ,
V_456 [ V_1 ] . type ,
V_456 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_179 ( V_17 , V_448 ) ;
return NULL ;
}
}
return V_448 ;
}
struct V_155 * F_180 ( struct V_16 * V_17 ,
int V_254 , const char * V_11 ,
const struct V_455 * V_456 ,
int V_457 ,
T_4 V_458 )
{
struct V_155 * V_448 ;
int V_1 , V_22 , V_72 = 0 ;
int V_447 = F_181 ( V_458 ) ;
V_254 |= V_459 ;
V_448 = F_99 ( V_17 , V_254 , V_11 , V_447 ) ;
if ( ! V_448 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_457 ; V_1 ++ ) {
if ( ! ( V_458 & ( 1ULL << V_456 [ V_1 ] . type ) ) )
continue;
if ( F_22 ( V_72 >= V_447 ) ) {
F_179 ( V_17 , V_448 ) ;
return NULL ;
}
V_22 = F_107 ( V_448 , V_72 ++ ,
V_456 [ V_1 ] . type ,
V_456 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_179 ( V_17 , V_448 ) ;
return NULL ;
}
}
return V_448 ;
}
static struct V_155 * F_182 ( struct V_16 * V_17 ,
int V_254 , const char * V_11 ,
T_4 V_460 , T_4 V_461 )
{
struct V_155 * V_448 ;
V_448 = F_99 ( V_17 , V_254 , V_11 , 2 ) ;
if ( ! V_448 )
return NULL ;
V_448 -> V_449 [ 0 ] = V_460 ;
V_448 -> V_449 [ 1 ] = V_461 ;
return V_448 ;
}
struct V_155 * F_101 ( struct V_16 * V_17 , int V_254 ,
const char * V_11 ,
T_4 V_460 , T_4 V_461 )
{
return F_182 ( V_17 , V_462 | V_254 ,
V_11 , V_460 , V_461 ) ;
}
struct V_155 * F_102 ( struct V_16 * V_17 ,
int V_254 , const char * V_11 ,
T_6 V_460 , T_6 V_461 )
{
return F_182 ( V_17 , V_463 | V_254 ,
V_11 , F_183 ( V_460 ) , F_183 ( V_461 ) ) ;
}
struct V_155 * F_103 ( struct V_16 * V_17 ,
int V_254 , const char * V_11 , T_1 type )
{
struct V_155 * V_448 ;
V_254 |= V_464 ;
if ( F_22 ( ! ( V_254 & V_163 ) ) )
return NULL ;
V_448 = F_99 ( V_17 , V_254 , V_11 , 1 ) ;
if ( ! V_448 )
return NULL ;
V_448 -> V_449 [ 0 ] = type ;
return V_448 ;
}
struct V_155 * F_104 ( struct V_16 * V_17 , int V_254 ,
const char * V_11 )
{
return F_101 ( V_17 , V_254 , V_11 , 0 , 1 ) ;
}
int F_107 ( struct V_155 * V_448 , int V_72 ,
T_4 V_465 , const char * V_11 )
{
struct V_466 * V_467 ;
if ( ! ( F_184 ( V_448 , V_185 ) ||
F_184 ( V_448 , V_459 ) ) )
return - V_83 ;
if ( F_184 ( V_448 , V_459 ) &&
( V_465 > 63 ) )
return - V_83 ;
if ( ! F_44 ( & V_448 -> V_452 ) ) {
F_88 (prop_enum, &property->enum_list, head) {
if ( V_467 -> V_465 == V_465 ) {
strncpy ( V_467 -> V_11 , V_11 , V_453 ) ;
V_467 -> V_11 [ V_453 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_467 = F_177 ( sizeof( struct V_466 ) , V_26 ) ;
if ( ! V_467 )
return - V_84 ;
strncpy ( V_467 -> V_11 , V_11 , V_453 ) ;
V_467 -> V_11 [ V_453 - 1 ] = '\0' ;
V_467 -> V_465 = V_465 ;
V_448 -> V_449 [ V_72 ] = V_465 ;
F_54 ( & V_467 -> V_42 , & V_448 -> V_452 ) ;
return 0 ;
}
void F_179 ( struct V_16 * V_17 , struct V_155 * V_448 )
{
struct V_466 * V_467 , * V_468 ;
F_76 (prop_enum, pt, &property->enum_list, head) {
F_42 ( & V_467 -> V_42 ) ;
F_59 ( V_467 ) ;
}
if ( V_448 -> V_447 )
F_59 ( V_448 -> V_449 ) ;
F_17 ( V_17 , & V_448 -> V_39 ) ;
F_42 ( & V_448 -> V_42 ) ;
F_59 ( V_448 ) ;
}
void F_57 ( struct V_18 * V_19 ,
struct V_155 * V_448 ,
T_4 V_469 )
{
int V_251 = V_19 -> V_62 -> V_251 ;
if ( V_251 == V_470 ) {
F_185 ( 1 , L_98
L_99
L_100 ,
V_19 -> type ) ;
return;
}
V_19 -> V_62 -> V_62 [ V_251 ] = V_448 ;
V_19 -> V_62 -> V_449 [ V_251 ] = V_469 ;
V_19 -> V_62 -> V_251 ++ ;
if ( V_448 -> V_254 & V_163 )
V_19 -> V_62 -> V_252 ++ ;
}
int F_186 ( struct V_18 * V_19 ,
struct V_155 * V_448 , T_4 V_253 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_62 -> V_251 ; V_1 ++ ) {
if ( V_19 -> V_62 -> V_62 [ V_1 ] == V_448 ) {
V_19 -> V_62 -> V_449 [ V_1 ] = V_253 ;
return 0 ;
}
}
return - V_83 ;
}
int F_125 ( struct V_18 * V_19 ,
struct V_155 * V_448 , T_4 * V_253 )
{
int V_1 ;
if ( F_56 ( V_448 -> V_17 , V_66 ) &&
! ( V_448 -> V_254 & V_158 ) )
return F_187 ( V_19 , V_448 , V_253 ) ;
for ( V_1 = 0 ; V_1 < V_19 -> V_62 -> V_251 ; V_1 ++ ) {
if ( V_19 -> V_62 -> V_62 [ V_1 ] == V_448 ) {
* V_253 = V_19 -> V_62 -> V_449 [ V_1 ] ;
return 0 ;
}
}
return - V_83 ;
}
int F_188 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_471 * V_256 = V_202 ;
struct V_155 * V_448 ;
int V_472 = 0 ;
int V_473 = 0 ;
int V_22 = 0 , V_1 ;
int V_213 ;
struct V_466 * V_467 ;
struct V_474 T_3 * V_475 ;
T_4 T_3 * V_476 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_448 = F_189 ( V_17 , V_256 -> V_477 ) ;
if ( ! V_448 ) {
V_22 = - V_235 ;
goto V_478;
}
if ( F_184 ( V_448 , V_185 ) ||
F_184 ( V_448 , V_459 ) ) {
F_88 (prop_enum, &property->enum_list, head)
V_472 ++ ;
}
V_473 = V_448 -> V_447 ;
strncpy ( V_256 -> V_11 , V_448 -> V_11 , V_453 ) ;
V_256 -> V_11 [ V_453 - 1 ] = 0 ;
V_256 -> V_254 = V_448 -> V_254 ;
if ( ( V_256 -> V_479 >= V_473 ) && V_473 ) {
V_476 = ( T_4 T_3 * ) ( unsigned long ) V_256 -> V_476 ;
for ( V_1 = 0 ; V_1 < V_473 ; V_1 ++ ) {
if ( F_129 ( V_476 + V_1 , & V_448 -> V_449 [ V_1 ] , sizeof( T_4 ) ) ) {
V_22 = - V_222 ;
goto V_478;
}
}
}
V_256 -> V_479 = V_473 ;
if ( F_184 ( V_448 , V_185 ) ||
F_184 ( V_448 , V_459 ) ) {
if ( ( V_256 -> V_480 >= V_472 ) && V_472 ) {
V_213 = 0 ;
V_475 = (struct V_474 T_3 * ) ( unsigned long ) V_256 -> V_481 ;
F_88 (prop_enum, &property->enum_list, head) {
if ( F_129 ( & V_475 [ V_213 ] . V_465 , & V_467 -> V_465 , sizeof( T_4 ) ) ) {
V_22 = - V_222 ;
goto V_478;
}
if ( F_129 ( & V_475 [ V_213 ] . V_11 ,
& V_467 -> V_11 , V_453 ) ) {
V_22 = - V_222 ;
goto V_478;
}
V_213 ++ ;
}
}
V_256 -> V_480 = V_472 ;
}
if ( F_184 ( V_448 , V_157 ) )
V_256 -> V_480 = 0 ;
V_478:
F_51 ( V_17 ) ;
return V_22 ;
}
struct V_482 *
F_190 ( struct V_16 * V_17 , T_7 V_483 ,
const void * V_202 )
{
struct V_482 * V_484 ;
int V_22 ;
if ( ! V_483 || V_483 > V_485 - sizeof( struct V_482 ) )
return F_167 ( - V_83 ) ;
V_484 = F_177 ( sizeof( struct V_482 ) + V_483 , V_26 ) ;
if ( ! V_484 )
return F_167 ( - V_84 ) ;
F_25 ( & V_484 -> V_486 ) ;
V_484 -> V_483 = V_483 ;
V_484 -> V_17 = V_17 ;
if ( V_202 )
memcpy ( V_484 -> V_202 , V_202 , V_483 ) ;
F_11 ( & V_17 -> V_23 . V_487 ) ;
V_22 = F_14 ( V_17 , & V_484 -> V_39 , V_31 ) ;
if ( V_22 ) {
F_59 ( V_484 ) ;
F_13 ( & V_17 -> V_23 . V_487 ) ;
return F_167 ( - V_83 ) ;
}
F_24 ( & V_484 -> V_37 ) ;
F_54 ( & V_484 -> V_488 ,
& V_17 -> V_23 . V_489 ) ;
F_13 ( & V_17 -> V_23 . V_487 ) ;
return V_484 ;
}
static void F_191 ( struct V_44 * V_44 )
{
struct V_482 * V_484 =
F_29 ( V_44 , struct V_482 , V_37 ) ;
F_22 ( ! F_192 ( & V_484 -> V_17 -> V_23 . V_487 ) ) ;
F_42 ( & V_484 -> V_488 ) ;
F_42 ( & V_484 -> V_486 ) ;
F_17 ( V_484 -> V_17 , & V_484 -> V_39 ) ;
F_59 ( V_484 ) ;
}
void F_193 ( struct V_482 * V_484 )
{
struct V_16 * V_17 ;
if ( ! V_484 )
return;
V_17 = V_484 -> V_17 ;
F_35 ( L_101 , V_484 , V_484 -> V_39 . V_27 , F_36 ( & V_484 -> V_37 . V_37 ) ) ;
if ( F_194 ( & V_484 -> V_37 , F_191 ,
& V_17 -> V_23 . V_487 ) )
F_13 ( & V_17 -> V_23 . V_487 ) ;
else
F_195 ( & V_17 -> V_23 . V_487 ) ;
}
static void F_196 ( struct V_482 * V_484 )
{
if ( ! V_484 )
return;
F_35 ( L_101 , V_484 , V_484 -> V_39 . V_27 , F_36 ( & V_484 -> V_37 . V_37 ) ) ;
F_37 ( & V_484 -> V_37 , F_191 ) ;
}
void F_197 ( struct V_16 * V_17 ,
struct V_203 * V_204 )
{
struct V_482 * V_484 , * V_490 ;
F_11 ( & V_17 -> V_23 . V_487 ) ;
F_76 (blob, bt, &file_priv->blobs, head_file) {
F_169 ( & V_484 -> V_486 ) ;
F_196 ( V_484 ) ;
}
F_13 ( & V_17 -> V_23 . V_487 ) ;
}
struct V_482 * F_198 ( struct V_482 * V_484 )
{
F_35 ( L_101 , V_484 , V_484 -> V_39 . V_27 , F_36 ( & V_484 -> V_37 . V_37 ) ) ;
F_39 ( & V_484 -> V_37 ) ;
return V_484 ;
}
static struct V_482 * F_199 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_18 * V_19 = NULL ;
struct V_482 * V_484 ;
F_22 ( ! F_192 ( & V_17 -> V_23 . V_487 ) ) ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_19 = F_20 ( & V_17 -> V_23 . V_25 , V_27 ) ;
if ( ! V_19 || ( V_19 -> type != V_31 ) || ( V_19 -> V_27 != V_27 ) )
V_484 = NULL ;
else
V_484 = F_200 ( V_19 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_484 ;
}
struct V_482 * F_201 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_482 * V_484 ;
F_11 ( & V_17 -> V_23 . V_487 ) ;
V_484 = F_199 ( V_17 , V_27 ) ;
if ( V_484 ) {
if ( ! F_33 ( & V_484 -> V_37 ) )
V_484 = NULL ;
}
F_13 ( & V_17 -> V_23 . V_487 ) ;
return V_484 ;
}
static int F_202 ( struct V_16 * V_17 ,
struct V_482 * * V_491 ,
T_7 V_483 ,
const void * V_202 ,
struct V_18 * V_492 ,
struct V_155 * V_493 )
{
struct V_482 * V_494 = NULL ;
struct V_482 * V_495 = NULL ;
int V_22 ;
F_22 ( V_491 == NULL ) ;
V_495 = * V_491 ;
if ( V_483 && V_202 ) {
V_494 = F_190 ( V_17 , V_483 , V_202 ) ;
if ( F_153 ( V_494 ) )
return F_154 ( V_494 ) ;
}
if ( V_492 ) {
V_22 = F_186 ( V_492 ,
V_493 ,
V_494 ?
V_494 -> V_39 . V_27 : 0 ) ;
if ( V_22 != 0 )
goto V_496;
}
F_193 ( V_495 ) ;
* V_491 = V_494 ;
return 0 ;
V_496:
F_193 ( V_494 ) ;
return V_22 ;
}
int F_203 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_497 * V_256 = V_202 ;
struct V_482 * V_484 ;
int V_22 = 0 ;
void T_3 * V_498 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
F_45 ( V_17 ) ;
F_11 ( & V_17 -> V_23 . V_487 ) ;
V_484 = F_199 ( V_17 , V_256 -> V_499 ) ;
if ( ! V_484 ) {
V_22 = - V_235 ;
goto V_478;
}
if ( V_256 -> V_483 == V_484 -> V_483 ) {
V_498 = ( void T_3 * ) ( unsigned long ) V_256 -> V_202 ;
if ( F_129 ( V_498 , V_484 -> V_202 , V_484 -> V_483 ) ) {
V_22 = - V_222 ;
goto V_478;
}
}
V_256 -> V_483 = V_484 -> V_483 ;
V_478:
F_13 ( & V_17 -> V_23 . V_487 ) ;
F_51 ( V_17 ) ;
return V_22 ;
}
int F_204 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_500 * V_256 = V_202 ;
struct V_482 * V_484 ;
void T_3 * V_498 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
V_484 = F_190 ( V_17 , V_256 -> V_483 , NULL ) ;
if ( F_153 ( V_484 ) )
return F_154 ( V_484 ) ;
V_498 = ( void T_3 * ) ( unsigned long ) V_256 -> V_202 ;
if ( F_175 ( V_484 -> V_202 , V_498 , V_256 -> V_483 ) ) {
V_22 = - V_222 ;
goto V_501;
}
F_11 ( & V_17 -> V_23 . V_487 ) ;
V_256 -> V_499 = V_484 -> V_39 . V_27 ;
F_54 ( & V_484 -> V_486 , & V_204 -> V_502 ) ;
F_13 ( & V_17 -> V_23 . V_487 ) ;
return 0 ;
V_501:
F_193 ( V_484 ) ;
return V_22 ;
}
int F_205 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_503 * V_256 = V_202 ;
struct V_482 * V_484 = NULL , * V_490 ;
bool V_424 = false ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
F_11 ( & V_17 -> V_23 . V_487 ) ;
V_484 = F_199 ( V_17 , V_256 -> V_499 ) ;
if ( ! V_484 ) {
V_22 = - V_235 ;
goto V_504;
}
F_88 (bt, &file_priv->blobs, head_file) {
if ( V_490 == V_484 ) {
V_424 = true ;
break;
}
}
if ( ! V_424 ) {
V_22 = - V_505 ;
goto V_504;
}
F_169 ( & V_484 -> V_486 ) ;
F_196 ( V_484 ) ;
F_13 ( & V_17 -> V_23 . V_487 ) ;
return 0 ;
V_504:
F_13 ( & V_17 -> V_23 . V_487 ) ;
return V_22 ;
}
int F_206 ( struct V_74 * V_75 ,
const char * V_506 )
{
struct V_16 * V_17 = V_75 -> V_17 ;
int V_22 ;
V_22 = F_202 ( V_17 ,
& V_75 -> V_507 ,
strlen ( V_506 ) + 1 ,
V_506 ,
& V_75 -> V_39 ,
V_17 -> V_23 . V_160 ) ;
return V_22 ;
}
int F_207 ( struct V_74 * V_75 )
{
struct V_16 * V_17 = V_75 -> V_17 ;
char V_508 [ 256 ] ;
int V_22 ;
if ( ! V_75 -> V_509 ) {
V_22 = F_202 ( V_17 ,
& V_75 -> V_510 ,
0 ,
NULL ,
& V_75 -> V_39 ,
V_17 -> V_23 . V_161 ) ;
return V_22 ;
}
snprintf ( V_508 , 256 , L_102 ,
V_75 -> V_121 -> V_27 , V_75 -> V_511 ,
V_75 -> V_512 , V_75 -> V_513 ,
V_75 -> V_514 , V_75 -> V_515 ,
V_75 -> V_516 , V_75 -> V_517 ) ;
V_22 = F_202 ( V_17 ,
& V_75 -> V_510 ,
strlen ( V_508 ) + 1 ,
V_508 ,
& V_75 -> V_39 ,
V_17 -> V_23 . V_161 ) ;
return V_22 ;
}
int F_208 ( struct V_74 * V_75 ,
const struct V_518 * V_518 )
{
struct V_16 * V_17 = V_75 -> V_17 ;
T_7 V_519 = 0 ;
int V_22 ;
if ( V_75 -> V_520 )
return 0 ;
if ( V_518 )
V_519 = V_521 * ( 1 + V_518 -> V_522 ) ;
V_22 = F_202 ( V_17 ,
& V_75 -> V_111 ,
V_519 ,
V_518 ,
& V_75 -> V_39 ,
V_17 -> V_23 . V_116 ) ;
return V_22 ;
}
bool F_209 ( struct V_155 * V_448 ,
T_4 V_465 , struct V_18 * * V_523 )
{
int V_1 ;
if ( V_448 -> V_254 & V_158 )
return false ;
* V_523 = NULL ;
if ( F_184 ( V_448 , V_462 ) ) {
if ( V_465 < V_448 -> V_449 [ 0 ] || V_465 > V_448 -> V_449 [ 1 ] )
return false ;
return true ;
} else if ( F_184 ( V_448 , V_463 ) ) {
T_6 V_524 = F_210 ( V_465 ) ;
if ( V_524 < F_210 ( V_448 -> V_449 [ 0 ] ) ||
V_524 > F_210 ( V_448 -> V_449 [ 1 ] ) )
return false ;
return true ;
} else if ( F_184 ( V_448 , V_459 ) ) {
T_4 V_525 = 0 ;
for ( V_1 = 0 ; V_1 < V_448 -> V_447 ; V_1 ++ )
V_525 |= ( 1ULL << V_448 -> V_449 [ V_1 ] ) ;
return ! ( V_465 & ~ V_525 ) ;
} else if ( F_184 ( V_448 , V_157 ) ) {
struct V_482 * V_484 ;
if ( V_465 == 0 )
return true ;
V_484 = F_201 ( V_448 -> V_17 , V_465 ) ;
if ( V_484 ) {
* V_523 = & V_484 -> V_39 ;
return true ;
} else {
return false ;
}
} else if ( F_184 ( V_448 , V_464 ) ) {
if ( V_465 == 0 )
return true ;
if ( V_448 -> V_449 [ 0 ] == V_30 ) {
struct V_32 * V_33 ;
V_33 = F_32 ( V_448 -> V_17 , V_465 ) ;
if ( V_33 ) {
* V_523 = & V_33 -> V_39 ;
return true ;
} else {
return false ;
}
} else {
return F_19 ( V_448 -> V_17 , V_465 , V_448 -> V_449 [ 0 ] ) != NULL ;
}
}
for ( V_1 = 0 ; V_1 < V_448 -> V_447 ; V_1 ++ )
if ( V_448 -> V_449 [ V_1 ] == V_465 )
return true ;
return false ;
}
void F_211 ( struct V_155 * V_448 ,
struct V_18 * V_523 )
{
if ( ! V_523 )
return;
if ( F_184 ( V_448 , V_464 ) ) {
if ( V_448 -> V_449 [ 0 ] == V_30 )
F_34 ( F_31 ( V_523 ) ) ;
} else if ( F_184 ( V_448 , V_157 ) )
F_193 ( F_200 ( V_523 ) ) ;
}
int F_212 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_526 * V_527 = V_202 ;
struct V_528 V_529 = {
. V_465 = V_527 -> V_465 ,
. V_477 = V_527 -> V_477 ,
. V_530 = V_527 -> V_216 ,
. V_20 = V_105
} ;
return F_213 ( V_17 , & V_529 , V_204 ) ;
}
static int F_214 ( struct V_18 * V_19 ,
struct V_155 * V_448 ,
T_4 V_465 )
{
int V_22 = - V_83 ;
struct V_74 * V_75 = F_215 ( V_19 ) ;
if ( V_448 == V_75 -> V_17 -> V_23 . V_117 ) {
V_22 = 0 ;
if ( V_75 -> V_35 -> V_531 )
V_22 = (* V_75 -> V_35 -> V_531 )( V_75 , ( int ) V_465 ) ;
} else if ( V_75 -> V_35 -> V_532 )
V_22 = V_75 -> V_35 -> V_532 ( V_75 , V_448 , V_465 ) ;
if ( ! V_22 )
F_186 ( & V_75 -> V_39 , V_448 , V_465 ) ;
return V_22 ;
}
static int F_216 ( struct V_18 * V_19 ,
struct V_155 * V_448 ,
T_4 V_465 )
{
int V_22 = - V_83 ;
struct V_46 * V_47 = F_217 ( V_19 ) ;
if ( V_47 -> V_35 -> V_532 )
V_22 = V_47 -> V_35 -> V_532 ( V_47 , V_448 , V_465 ) ;
if ( ! V_22 )
F_186 ( V_19 , V_448 , V_465 ) ;
return V_22 ;
}
int F_218 ( struct V_48 * V_49 ,
struct V_155 * V_448 ,
T_4 V_465 )
{
int V_22 = - V_83 ;
struct V_18 * V_19 = & V_49 -> V_39 ;
if ( V_49 -> V_35 -> V_532 )
V_22 = V_49 -> V_35 -> V_532 ( V_49 , V_448 , V_465 ) ;
if ( ! V_22 )
F_186 ( V_19 , V_448 , V_465 ) ;
return V_22 ;
}
int F_219 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_533 * V_534 = V_202 ;
struct V_18 * V_19 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_19 = F_21 ( V_17 , V_534 -> V_530 , V_534 -> V_20 ) ;
if ( ! V_19 ) {
V_22 = - V_235 ;
goto V_40;
}
if ( ! V_19 -> V_62 ) {
V_22 = - V_83 ;
goto V_40;
}
V_22 = F_124 ( V_19 , V_204 -> V_246 ,
( T_1 T_3 * ) ( unsigned long ) ( V_534 -> V_274 ) ,
( T_4 T_3 * ) ( unsigned long ) ( V_534 -> V_275 ) ,
& V_534 -> V_276 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_213 ( struct V_16 * V_17 , void * V_202 ,
struct V_203 * V_204 )
{
struct V_528 * V_534 = V_202 ;
struct V_18 * V_535 ;
struct V_18 * V_536 ;
struct V_155 * V_448 ;
int V_1 , V_22 = - V_83 ;
struct V_18 * V_523 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_535 = F_21 ( V_17 , V_534 -> V_530 , V_534 -> V_20 ) ;
if ( ! V_535 ) {
V_22 = - V_235 ;
goto V_40;
}
if ( ! V_535 -> V_62 )
goto V_40;
for ( V_1 = 0 ; V_1 < V_535 -> V_62 -> V_251 ; V_1 ++ )
if ( V_535 -> V_62 -> V_62 [ V_1 ] -> V_39 . V_27 == V_534 -> V_477 )
break;
if ( V_1 == V_535 -> V_62 -> V_251 )
goto V_40;
V_536 = F_21 ( V_17 , V_534 -> V_477 ,
V_451 ) ;
if ( ! V_536 ) {
V_22 = - V_235 ;
goto V_40;
}
V_448 = F_220 ( V_536 ) ;
if ( ! F_209 ( V_448 , V_534 -> V_465 , & V_523 ) )
goto V_40;
switch ( V_535 -> type ) {
case V_105 :
V_22 = F_214 ( V_535 , V_448 ,
V_534 -> V_465 ) ;
break;
case V_61 :
V_22 = F_216 ( V_535 , V_448 , V_534 -> V_465 ) ;
break;
case V_135 :
V_22 = F_218 ( F_221 ( V_535 ) ,
V_448 , V_534 -> V_465 ) ;
break;
}
F_211 ( V_448 , V_523 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_222 ( struct V_74 * V_75 ,
struct V_124 * V_125 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_263 ; V_1 ++ ) {
if ( V_75 -> V_264 [ V_1 ] == 0 ) {
V_75 -> V_264 [ V_1 ] = V_125 -> V_39 . V_27 ;
return 0 ;
}
}
return - V_84 ;
}
int F_223 ( struct V_46 * V_47 ,
int V_236 )
{
V_47 -> V_236 = V_236 ;
V_47 -> V_69 = F_174 ( V_236 , sizeof( V_537 ) * 3 ,
V_26 ) ;
if ( ! V_47 -> V_69 ) {
V_47 -> V_236 = 0 ;
return - V_84 ;
}
return 0 ;
}
int F_224 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_538 * V_539 = V_202 ;
struct V_46 * V_47 ;
void * V_540 , * V_541 , * V_542 ;
int V_519 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_47 = F_117 ( V_17 , V_539 -> V_215 ) ;
if ( ! V_47 ) {
V_22 = - V_235 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_543 == NULL ) {
V_22 = - V_443 ;
goto V_40;
}
if ( V_539 -> V_236 != V_47 -> V_236 ) {
V_22 = - V_83 ;
goto V_40;
}
V_519 = V_539 -> V_236 * ( sizeof( V_537 ) ) ;
V_540 = V_47 -> V_69 ;
if ( F_175 ( V_540 , ( void T_3 * ) ( unsigned long ) V_539 -> V_544 , V_519 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_541 = V_540 + V_519 ;
if ( F_175 ( V_541 , ( void T_3 * ) ( unsigned long ) V_539 -> V_545 , V_519 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_542 = V_541 + V_519 ;
if ( F_175 ( V_542 , ( void T_3 * ) ( unsigned long ) V_539 -> V_546 , V_519 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_47 -> V_35 -> V_543 ( V_47 , V_540 , V_541 , V_542 , 0 , V_47 -> V_236 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_225 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_538 * V_539 = V_202 ;
struct V_46 * V_47 ;
void * V_540 , * V_541 , * V_542 ;
int V_519 ;
int V_22 = 0 ;
if ( ! F_56 ( V_17 , V_218 ) )
return - V_83 ;
F_45 ( V_17 ) ;
V_47 = F_117 ( V_17 , V_539 -> V_215 ) ;
if ( ! V_47 ) {
V_22 = - V_235 ;
goto V_40;
}
if ( V_539 -> V_236 != V_47 -> V_236 ) {
V_22 = - V_83 ;
goto V_40;
}
V_519 = V_539 -> V_236 * ( sizeof( V_537 ) ) ;
V_540 = V_47 -> V_69 ;
if ( F_129 ( ( void T_3 * ) ( unsigned long ) V_539 -> V_544 , V_540 , V_519 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_541 = V_540 + V_519 ;
if ( F_129 ( ( void T_3 * ) ( unsigned long ) V_539 -> V_545 , V_541 , V_519 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_542 = V_541 + V_519 ;
if ( F_129 ( ( void T_3 * ) ( unsigned long ) V_539 -> V_546 , V_542 , V_519 ) ) {
V_22 = - V_222 ;
goto V_40;
}
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_226 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_547 * V_548 = V_202 ;
struct V_46 * V_47 ;
struct V_32 * V_33 = NULL ;
struct V_549 * V_550 = NULL ;
unsigned long V_254 ;
int V_22 = - V_83 ;
if ( V_548 -> V_254 & ~ V_551 ||
V_548 -> V_552 != 0 )
return - V_83 ;
if ( ( V_548 -> V_254 & V_553 ) && ! V_17 -> V_23 . V_554 )
return - V_83 ;
V_47 = F_117 ( V_17 , V_548 -> V_215 ) ;
if ( ! V_47 )
return - V_235 ;
F_118 ( V_47 , V_47 -> V_52 ) ;
if ( V_47 -> V_52 -> V_33 == NULL ) {
V_22 = - V_555 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_548 == NULL )
goto V_40;
V_33 = F_32 ( V_17 , V_548 -> V_214 ) ;
if ( ! V_33 ) {
V_22 = - V_235 ;
goto V_40;
}
V_22 = F_145 ( V_47 , V_47 -> V_237 , V_47 -> V_239 , & V_47 -> V_77 , V_33 ) ;
if ( V_22 )
goto V_40;
if ( V_47 -> V_52 -> V_33 -> V_302 != V_33 -> V_302 ) {
F_70 ( L_103 ) ;
V_22 = - V_83 ;
goto V_40;
}
if ( V_548 -> V_254 & V_556 ) {
V_22 = - V_84 ;
F_227 ( & V_17 -> V_557 , V_254 ) ;
if ( V_204 -> V_558 < sizeof( V_550 -> V_559 ) ) {
F_228 ( & V_17 -> V_557 , V_254 ) ;
goto V_40;
}
V_204 -> V_558 -= sizeof( V_550 -> V_559 ) ;
F_228 ( & V_17 -> V_557 , V_254 ) ;
V_550 = F_177 ( sizeof( * V_550 ) , V_26 ) ;
if ( V_550 == NULL ) {
F_227 ( & V_17 -> V_557 , V_254 ) ;
V_204 -> V_558 += sizeof( V_550 -> V_559 ) ;
F_228 ( & V_17 -> V_557 , V_254 ) ;
goto V_40;
}
V_550 -> V_559 . V_39 . type = V_560 ;
V_550 -> V_559 . V_39 . V_483 = sizeof( V_550 -> V_559 ) ;
V_550 -> V_559 . V_561 = V_548 -> V_561 ;
V_550 -> V_39 . V_559 = & V_550 -> V_559 . V_39 ;
V_550 -> V_39 . V_204 = V_204 ;
V_550 -> V_39 . V_45 =
( void ( * ) ( struct V_562 * ) ) F_59 ;
}
V_47 -> V_52 -> V_153 = V_47 -> V_52 -> V_33 ;
V_22 = V_47 -> V_35 -> V_548 ( V_47 , V_33 , V_550 , V_548 -> V_254 ) ;
if ( V_22 ) {
if ( V_548 -> V_254 & V_556 ) {
F_227 ( & V_17 -> V_557 , V_254 ) ;
V_204 -> V_558 += sizeof( V_550 -> V_559 ) ;
F_228 ( & V_17 -> V_557 , V_254 ) ;
F_59 ( V_550 ) ;
}
V_47 -> V_52 -> V_153 = NULL ;
} else {
V_47 -> V_52 -> V_33 = V_33 ;
V_33 = NULL ;
}
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
if ( V_47 -> V_52 -> V_153 )
F_34 ( V_47 -> V_52 -> V_153 ) ;
V_47 -> V_52 -> V_153 = NULL ;
F_120 ( V_47 ) ;
return V_22 ;
}
void F_229 ( struct V_16 * V_17 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_124 * V_125 ;
struct V_74 * V_75 ;
F_49 (plane, dev)
if ( V_49 -> V_35 -> V_563 )
V_49 -> V_35 -> V_563 ( V_49 ) ;
F_46 (crtc, dev)
if ( V_47 -> V_35 -> V_563 )
V_47 -> V_35 -> V_563 ( V_47 ) ;
F_115 (encoder, dev)
if ( V_125 -> V_35 -> V_563 )
V_125 -> V_35 -> V_563 ( V_125 ) ;
F_11 ( & V_17 -> V_23 . V_60 ) ;
F_80 (connector, dev)
if ( V_75 -> V_35 -> V_563 )
V_75 -> V_35 -> V_563 ( V_75 ) ;
F_13 ( & V_17 -> V_23 . V_60 ) ;
}
int F_230 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_564 * args = V_202 ;
T_2 V_414 , V_565 , V_519 ;
if ( ! V_17 -> V_566 -> V_567 )
return - V_443 ;
if ( ! args -> V_304 || ! args -> V_305 || ! args -> V_346 )
return - V_83 ;
V_414 = F_231 ( args -> V_346 , 8 ) ;
if ( ! V_414 || V_414 > 0xffffffffU / args -> V_304 )
return - V_83 ;
V_565 = V_414 * args -> V_304 ;
if ( args -> V_305 > 0xffffffffU / V_565 )
return - V_83 ;
V_519 = args -> V_305 * V_565 ;
if ( F_232 ( V_519 ) == 0 )
return - V_83 ;
args -> V_332 = 0 ;
args -> V_358 = 0 ;
args -> V_519 = 0 ;
return V_17 -> V_566 -> V_567 ( V_204 , V_17 , args ) ;
}
int F_233 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_568 * args = V_202 ;
if ( ! V_17 -> V_566 -> V_569 )
return - V_443 ;
return V_17 -> V_566 -> V_569 ( V_204 , V_17 , args -> V_332 , & args -> V_570 ) ;
}
int F_234 ( struct V_16 * V_17 ,
void * V_202 , struct V_203 * V_204 )
{
struct V_571 * args = V_202 ;
if ( ! V_17 -> V_566 -> V_572 )
return - V_443 ;
return V_17 -> V_566 -> V_572 ( V_204 , V_17 , args -> V_332 ) ;
}
void F_235 ( T_1 V_13 , unsigned int * V_347 ,
int * V_346 )
{
switch ( V_13 ) {
case V_349 :
case V_359 :
case V_360 :
* V_347 = 8 ;
* V_346 = 8 ;
break;
case V_350 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
* V_347 = 15 ;
* V_346 = 16 ;
break;
case V_351 :
case V_376 :
* V_347 = 16 ;
* V_346 = 16 ;
break;
case V_352 :
case V_377 :
* V_347 = 24 ;
* V_346 = 24 ;
break;
case V_353 :
case V_378 :
case V_379 :
case V_380 :
* V_347 = 24 ;
* V_346 = 32 ;
break;
case V_354 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
* V_347 = 30 ;
* V_346 = 32 ;
break;
case V_329 :
case V_381 :
case V_382 :
case V_383 :
* V_347 = 32 ;
* V_346 = 32 ;
break;
default:
F_70 ( L_104 ,
F_9 ( V_13 ) ) ;
* V_347 = 0 ;
* V_346 = 0 ;
break;
}
}
int F_165 ( T_1 V_13 )
{
switch ( V_13 ) {
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
return 3 ;
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
return 2 ;
default:
return 1 ;
}
}
int F_166 ( T_1 V_13 , int V_49 )
{
unsigned int V_347 ;
int V_346 ;
if ( V_49 >= F_165 ( V_13 ) )
return 0 ;
switch ( V_13 ) {
case V_391 :
case V_392 :
case V_393 :
case V_394 :
return 2 ;
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
return V_49 ? 2 : 1 ;
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
return 1 ;
default:
F_235 ( V_13 , & V_347 , & V_346 ) ;
return V_346 >> 3 ;
}
}
int F_163 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_404 :
case V_405 :
case V_402 :
case V_403 :
return 4 ;
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_408 :
case V_409 :
case V_406 :
case V_407 :
return 2 ;
default:
return 1 ;
}
}
int F_164 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_402 :
case V_403 :
return 4 ;
case V_406 :
case V_407 :
case V_396 :
case V_397 :
return 2 ;
default:
return 1 ;
}
}
unsigned int F_236 ( unsigned int V_573 ,
unsigned int V_574 )
{
if ( V_573 & ~ V_574 ) {
V_573 ^= F_237 ( V_575 ) | F_237 ( V_576 ) ;
V_573 = ( V_573 & ~ 0xf ) | F_237 ( ( F_238 ( V_573 & 0xf ) + 1 ) % 4 ) ;
}
return V_573 ;
}
void F_239 ( struct V_16 * V_17 )
{
F_240 ( & V_17 -> V_23 . V_60 ) ;
F_53 ( & V_17 -> V_23 . V_123 ) ;
F_240 ( & V_17 -> V_23 . V_24 ) ;
F_240 ( & V_17 -> V_23 . V_36 ) ;
F_240 ( & V_17 -> V_23 . V_487 ) ;
F_25 ( & V_17 -> V_23 . V_43 ) ;
F_25 ( & V_17 -> V_23 . V_63 ) ;
F_25 ( & V_17 -> V_23 . V_113 ) ;
F_25 ( & V_17 -> V_23 . V_130 ) ;
F_25 ( & V_17 -> V_23 . V_454 ) ;
F_25 ( & V_17 -> V_23 . V_489 ) ;
F_25 ( & V_17 -> V_23 . V_137 ) ;
F_241 ( & V_17 -> V_23 . V_25 ) ;
F_241 ( & V_17 -> V_23 . V_577 ) ;
F_45 ( V_17 ) ;
F_98 ( V_17 ) ;
F_51 ( V_17 ) ;
V_17 -> V_23 . V_41 = 0 ;
V_17 -> V_23 . V_114 = 0 ;
V_17 -> V_23 . V_64 = 0 ;
V_17 -> V_23 . V_131 = 0 ;
V_17 -> V_23 . V_140 = 0 ;
V_17 -> V_23 . V_138 = 0 ;
}
void F_242 ( struct V_16 * V_17 )
{
struct V_74 * V_75 , * V_578 ;
struct V_46 * V_47 , * V_579 ;
struct V_124 * V_125 , * V_580 ;
struct V_32 * V_33 , * V_581 ;
struct V_155 * V_448 , * V_468 ;
struct V_482 * V_484 , * V_490 ;
struct V_48 * V_49 , * V_582 ;
F_76 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_125 -> V_35 -> V_45 ( V_125 ) ;
}
F_76 (connector, ot,
&dev->mode_config.connector_list, head) {
V_75 -> V_35 -> V_45 ( V_75 ) ;
}
F_76 (property, pt, &dev->mode_config.property_list,
head) {
F_179 ( V_17 , V_448 ) ;
}
F_76 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_193 ( V_484 ) ;
}
F_22 ( ! F_44 ( & V_17 -> V_23 . V_43 ) ) ;
F_76 (fb, fbt, &dev->mode_config.fb_list, head) {
F_43 ( V_33 ) ;
}
F_76 (plane, plt, &dev->mode_config.plane_list,
head) {
V_49 -> V_35 -> V_45 ( V_49 ) ;
}
F_76 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_47 -> V_35 -> V_45 ( V_47 ) ;
}
F_243 ( & V_17 -> V_23 . V_577 ) ;
F_243 ( & V_17 -> V_23 . V_25 ) ;
F_60 ( & V_17 -> V_23 . V_123 ) ;
}
struct V_155 * F_244 ( struct V_16 * V_17 ,
unsigned int V_574 )
{
static const struct V_455 V_456 [] = {
{ V_583 , L_105 } ,
{ V_584 , L_106 } ,
{ V_585 , L_107 } ,
{ V_586 , L_108 } ,
{ V_575 , L_109 } ,
{ V_576 , L_110 } ,
} ;
return F_180 ( V_17 , 0 , L_111 ,
V_456 , F_2 ( V_456 ) ,
V_574 ) ;
}
static void F_245 ( struct V_44 * V_44 )
{
struct V_587 * V_588 = F_29 ( V_44 , struct V_587 , V_37 ) ;
struct V_16 * V_17 = V_588 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_577 , V_588 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
F_59 ( V_588 ) ;
}
void F_75 ( struct V_16 * V_17 ,
struct V_587 * V_588 )
{
F_37 ( & V_588 -> V_37 , F_245 ) ;
}
struct V_587 * F_246 ( struct V_16 * V_17 ,
char V_589 [ 8 ] )
{
struct V_587 * V_588 ;
int V_27 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_247 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_588 -> V_590 , V_589 , 8 ) ) {
if ( ! F_33 ( & V_588 -> V_37 ) )
V_588 = NULL ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_588 ;
}
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return NULL ;
}
struct V_587 * F_248 ( struct V_16 * V_17 ,
char V_589 [ 8 ] )
{
struct V_587 * V_588 ;
int V_22 ;
V_588 = F_177 ( sizeof( * V_588 ) , V_26 ) ;
if ( ! V_588 )
return F_167 ( - V_84 ) ;
F_24 ( & V_588 -> V_37 ) ;
memcpy ( V_588 -> V_590 , V_589 , 8 ) ;
V_588 -> V_17 = V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_22 = F_12 ( & V_17 -> V_23 . V_577 , V_588 , 1 , 0 , V_26 ) ;
if ( V_22 >= 0 ) {
V_588 -> V_27 = V_22 ;
} else {
F_59 ( V_588 ) ;
V_588 = F_167 ( V_22 ) ;
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_588 ;
}
