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
static unsigned int F_52 ( struct V_16 * V_17 )
{
unsigned int V_53 = 0 ;
struct V_46 * V_54 ;
F_46 (tmp, dev) {
V_53 ++ ;
}
return V_53 ;
}
int F_53 ( struct V_16 * V_17 , struct V_46 * V_47 ,
struct V_48 * V_52 ,
struct V_48 * V_55 ,
const struct V_56 * V_35 ,
const char * V_11 , ... )
{
struct V_57 * V_58 = & V_17 -> V_23 ;
int V_22 ;
F_22 ( V_52 && V_52 -> type != V_59 ) ;
F_22 ( V_55 && V_55 -> type != V_60 ) ;
V_47 -> V_17 = V_17 ;
V_47 -> V_35 = V_35 ;
F_54 ( & V_47 -> V_61 ) ;
V_22 = F_14 ( V_17 , & V_47 -> V_39 , V_62 ) ;
if ( V_22 )
return V_22 ;
if ( V_11 ) {
T_2 V_63 ;
va_start ( V_63 , V_11 ) ;
V_47 -> V_11 = F_55 ( V_26 , V_11 , V_63 ) ;
va_end ( V_63 ) ;
} else {
V_47 -> V_11 = F_56 ( V_26 , L_9 ,
F_52 ( V_17 ) ) ;
}
if ( ! V_47 -> V_11 ) {
F_17 ( V_17 , & V_47 -> V_39 ) ;
return - V_64 ;
}
V_47 -> V_39 . V_65 = & V_47 -> V_65 ;
F_57 ( & V_47 -> V_42 , & V_58 -> V_66 ) ;
V_58 -> V_67 ++ ;
V_47 -> V_52 = V_52 ;
V_47 -> V_55 = V_55 ;
if ( V_52 )
V_52 -> V_68 = 1 << F_58 ( V_47 ) ;
if ( V_55 )
V_55 -> V_68 = 1 << F_58 ( V_47 ) ;
if ( F_59 ( V_17 , V_69 ) ) {
F_60 ( & V_47 -> V_39 , V_58 -> V_70 , 0 ) ;
F_60 ( & V_47 -> V_39 , V_58 -> V_71 , 0 ) ;
}
return 0 ;
}
void F_61 ( struct V_46 * V_47 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
F_62 ( V_47 -> V_72 ) ;
V_47 -> V_72 = NULL ;
F_63 ( & V_47 -> V_61 ) ;
F_17 ( V_17 , & V_47 -> V_39 ) ;
F_42 ( & V_47 -> V_42 ) ;
V_17 -> V_23 . V_67 -- ;
F_22 ( V_47 -> V_73 && ! V_47 -> V_35 -> V_74 ) ;
if ( V_47 -> V_73 && V_47 -> V_35 -> V_74 )
V_47 -> V_35 -> V_74 ( V_47 , V_47 -> V_73 ) ;
F_62 ( V_47 -> V_11 ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
}
unsigned int F_58 ( struct V_46 * V_47 )
{
unsigned int V_75 = 0 ;
struct V_46 * V_54 ;
F_46 (tmp, crtc->dev) {
if ( V_54 == V_47 )
return V_75 ;
V_75 ++ ;
}
F_64 () ;
}
static void F_65 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
F_42 ( & V_79 -> V_42 ) ;
F_66 ( V_77 -> V_17 , V_79 ) ;
}
int F_67 ( struct V_80 * V_81 ,
const T_3 * V_82 ,
unsigned int V_83 )
{
T_3 * V_84 = NULL ;
if ( ! V_82 && V_83 )
return - V_85 ;
if ( V_82 && V_83 ) {
V_84 = F_68 ( V_82 , sizeof( * V_82 ) * V_83 ,
V_26 ) ;
if ( ! V_84 )
return - V_64 ;
}
F_62 ( V_81 -> V_86 ) ;
V_81 -> V_86 = V_84 ;
V_81 -> V_87 = V_83 ;
return 0 ;
}
static void F_69 ( struct V_76 * V_77 )
{
struct V_88 * V_79 = & V_77 -> V_89 ;
char * V_90 = NULL ;
if ( F_70 ( V_77 -> V_11 , & V_90 ) )
return;
if ( ! F_71 ( V_90 ,
V_77 ,
V_79 ) )
return;
if ( V_79 -> V_91 ) {
const char * V_92 ;
switch ( V_79 -> V_91 ) {
case V_93 :
V_92 = L_10 ;
break;
case V_94 :
V_92 = L_11 ;
break;
default:
case V_95 :
V_92 = L_12 ;
break;
}
F_72 ( L_13 , V_77 -> V_11 , V_92 ) ;
V_77 -> V_91 = V_79 -> V_91 ;
}
F_73 ( L_14 ,
V_77 -> V_11 ,
V_79 -> V_96 , V_79 -> V_97 ,
V_79 -> V_98 ? V_79 -> V_99 : 60 ,
V_79 -> V_100 ? L_15 : L_16 ,
V_79 -> V_101 ? L_17 : L_16 ,
V_79 -> V_102 ? L_18 : L_16 ) ;
}
int F_74 ( struct V_16 * V_17 ,
struct V_76 * V_77 ,
const struct V_103 * V_35 ,
int V_104 )
{
struct V_57 * V_58 = & V_17 -> V_23 ;
int V_22 ;
struct V_3 * V_105 =
& V_2 [ V_104 ] . V_3 ;
F_45 ( V_17 ) ;
V_22 = F_10 ( V_17 , & V_77 -> V_39 , V_106 , false ) ;
if ( V_22 )
goto V_107;
V_77 -> V_39 . V_65 = & V_77 -> V_65 ;
V_77 -> V_17 = V_17 ;
V_77 -> V_35 = V_35 ;
V_77 -> V_108 = F_75 ( & V_58 -> V_105 , 0 , 0 , V_26 ) ;
if ( V_77 -> V_108 < 0 ) {
V_22 = V_77 -> V_108 ;
goto V_109;
}
V_77 -> V_104 = V_104 ;
V_77 -> V_110 =
F_75 ( V_105 , 1 , 0 , V_26 ) ;
if ( V_77 -> V_110 < 0 ) {
V_22 = V_77 -> V_110 ;
goto V_111;
}
V_77 -> V_11 =
F_56 ( V_26 , L_19 ,
V_2 [ V_104 ] . V_11 ,
V_77 -> V_110 ) ;
if ( ! V_77 -> V_11 ) {
V_22 = - V_64 ;
goto V_112;
}
F_25 ( & V_77 -> V_113 ) ;
F_25 ( & V_77 -> V_114 ) ;
V_77 -> V_115 = NULL ;
V_77 -> V_5 = V_116 ;
F_69 ( V_77 ) ;
F_57 ( & V_77 -> V_42 , & V_58 -> V_117 ) ;
V_58 -> V_118 ++ ;
if ( V_104 != V_119 )
F_60 ( & V_77 -> V_39 ,
V_58 -> V_120 ,
0 ) ;
F_60 ( & V_77 -> V_39 ,
V_58 -> V_121 , 0 ) ;
if ( F_59 ( V_17 , V_69 ) ) {
F_60 ( & V_77 -> V_39 , V_58 -> V_122 , 0 ) ;
}
V_77 -> V_123 = NULL ;
V_112:
if ( V_22 )
F_76 ( V_105 , V_77 -> V_110 ) ;
V_111:
if ( V_22 )
F_76 ( & V_58 -> V_105 , V_77 -> V_108 ) ;
V_109:
if ( V_22 )
F_17 ( V_17 , & V_77 -> V_39 ) ;
V_107:
F_51 ( V_17 ) ;
return V_22 ;
}
void F_77 ( struct V_76 * V_77 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
struct V_78 * V_79 , * V_124 ;
if ( V_77 -> V_125 ) {
F_78 ( V_17 , V_77 -> V_125 ) ;
V_77 -> V_125 = NULL ;
}
F_79 (mode, t, &connector->probed_modes, head)
F_65 ( V_77 , V_79 ) ;
F_79 (mode, t, &connector->modes, head)
F_65 ( V_77 , V_79 ) ;
F_76 ( & V_2 [ V_77 -> V_104 ] . V_3 ,
V_77 -> V_110 ) ;
F_76 ( & V_17 -> V_23 . V_105 ,
V_77 -> V_108 ) ;
F_62 ( V_77 -> V_126 . V_86 ) ;
F_17 ( V_17 , & V_77 -> V_39 ) ;
F_62 ( V_77 -> V_11 ) ;
V_77 -> V_11 = NULL ;
F_42 ( & V_77 -> V_42 ) ;
V_17 -> V_23 . V_118 -- ;
F_22 ( V_77 -> V_73 && ! V_77 -> V_35 -> V_74 ) ;
if ( V_77 -> V_73 && V_77 -> V_35 -> V_74 )
V_77 -> V_35 -> V_74 ( V_77 ,
V_77 -> V_73 ) ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
}
int F_80 ( struct V_76 * V_77 )
{
int V_22 ;
F_15 ( V_77 -> V_17 , & V_77 -> V_39 ) ;
V_22 = F_81 ( V_77 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_82 ( V_77 ) ;
if ( V_22 ) {
F_83 ( V_77 ) ;
return V_22 ;
}
return 0 ;
}
void F_84 ( struct V_76 * V_77 )
{
F_83 ( V_77 ) ;
F_85 ( V_77 ) ;
}
void F_86 ( struct V_16 * V_17 )
{
struct V_76 * V_77 ;
F_87 (connector, &dev->mode_config.connector_list, head)
F_84 ( V_77 ) ;
}
int F_88 ( struct V_16 * V_17 ,
struct V_127 * V_128 ,
const struct V_129 * V_35 ,
int V_130 , const char * V_11 , ... )
{
int V_22 ;
F_45 ( V_17 ) ;
V_22 = F_14 ( V_17 , & V_128 -> V_39 , V_131 ) ;
if ( V_22 )
goto V_107;
V_128 -> V_17 = V_17 ;
V_128 -> V_130 = V_130 ;
V_128 -> V_35 = V_35 ;
if ( V_11 ) {
T_2 V_63 ;
va_start ( V_63 , V_11 ) ;
V_128 -> V_11 = F_55 ( V_26 , V_11 , V_63 ) ;
va_end ( V_63 ) ;
} else {
V_128 -> V_11 = F_56 ( V_26 , L_19 ,
V_132 [ V_130 ] . V_11 ,
V_128 -> V_39 . V_27 ) ;
}
if ( ! V_128 -> V_11 ) {
V_22 = - V_64 ;
goto V_109;
}
F_57 ( & V_128 -> V_42 , & V_17 -> V_23 . V_133 ) ;
V_17 -> V_23 . V_134 ++ ;
V_109:
if ( V_22 )
F_17 ( V_17 , & V_128 -> V_39 ) ;
V_107:
F_51 ( V_17 ) ;
return V_22 ;
}
void F_89 ( struct V_127 * V_128 )
{
struct V_16 * V_17 = V_128 -> V_17 ;
F_45 ( V_17 ) ;
F_17 ( V_17 , & V_128 -> V_39 ) ;
F_62 ( V_128 -> V_11 ) ;
F_42 ( & V_128 -> V_42 ) ;
V_17 -> V_23 . V_134 -- ;
F_51 ( V_17 ) ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
}
static unsigned int F_90 ( struct V_16 * V_17 )
{
unsigned int V_53 = 0 ;
struct V_48 * V_54 ;
F_49 (tmp, dev) {
V_53 ++ ;
}
return V_53 ;
}
int F_91 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_68 ,
const struct V_135 * V_35 ,
const T_1 * V_82 , unsigned int V_136 ,
enum V_137 type ,
const char * V_11 , ... )
{
struct V_57 * V_58 = & V_17 -> V_23 ;
int V_22 ;
V_22 = F_14 ( V_17 , & V_49 -> V_39 , V_138 ) ;
if ( V_22 )
return V_22 ;
F_54 ( & V_49 -> V_61 ) ;
V_49 -> V_39 . V_65 = & V_49 -> V_65 ;
V_49 -> V_17 = V_17 ;
V_49 -> V_35 = V_35 ;
V_49 -> V_139 = F_92 ( V_136 , sizeof( T_1 ) ,
V_26 ) ;
if ( ! V_49 -> V_139 ) {
F_73 ( L_20 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
return - V_64 ;
}
if ( V_11 ) {
T_2 V_63 ;
va_start ( V_63 , V_11 ) ;
V_49 -> V_11 = F_55 ( V_26 , V_11 , V_63 ) ;
va_end ( V_63 ) ;
} else {
V_49 -> V_11 = F_56 ( V_26 , L_21 ,
F_90 ( V_17 ) ) ;
}
if ( ! V_49 -> V_11 ) {
F_62 ( V_49 -> V_139 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
return - V_64 ;
}
memcpy ( V_49 -> V_139 , V_82 , V_136 * sizeof( T_1 ) ) ;
V_49 -> V_136 = V_136 ;
V_49 -> V_68 = V_68 ;
V_49 -> type = type ;
F_57 ( & V_49 -> V_42 , & V_58 -> V_140 ) ;
V_58 -> V_141 ++ ;
if ( V_49 -> type == V_142 )
V_58 -> V_143 ++ ;
F_60 ( & V_49 -> V_39 ,
V_58 -> V_144 ,
V_49 -> type ) ;
if ( F_59 ( V_17 , V_69 ) ) {
F_60 ( & V_49 -> V_39 , V_58 -> V_145 , 0 ) ;
F_60 ( & V_49 -> V_39 , V_58 -> V_122 , 0 ) ;
F_60 ( & V_49 -> V_39 , V_58 -> V_146 , 0 ) ;
F_60 ( & V_49 -> V_39 , V_58 -> V_147 , 0 ) ;
F_60 ( & V_49 -> V_39 , V_58 -> V_148 , 0 ) ;
F_60 ( & V_49 -> V_39 , V_58 -> V_149 , 0 ) ;
F_60 ( & V_49 -> V_39 , V_58 -> V_150 , 0 ) ;
F_60 ( & V_49 -> V_39 , V_58 -> V_151 , 0 ) ;
F_60 ( & V_49 -> V_39 , V_58 -> V_152 , 0 ) ;
F_60 ( & V_49 -> V_39 , V_58 -> V_153 , 0 ) ;
}
return 0 ;
}
int F_93 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_68 ,
const struct V_135 * V_35 ,
const T_1 * V_82 , unsigned int V_136 ,
bool V_154 )
{
enum V_137 type ;
type = V_154 ? V_59 : V_142 ;
return F_91 ( V_17 , V_49 , V_68 , V_35 ,
V_82 , V_136 , type , NULL ) ;
}
void F_94 ( struct V_48 * V_49 )
{
struct V_16 * V_17 = V_49 -> V_17 ;
F_45 ( V_17 ) ;
F_62 ( V_49 -> V_139 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
F_95 ( F_44 ( & V_49 -> V_42 ) ) ;
F_42 ( & V_49 -> V_42 ) ;
V_17 -> V_23 . V_141 -- ;
if ( V_49 -> type == V_142 )
V_17 -> V_23 . V_143 -- ;
F_51 ( V_17 ) ;
F_22 ( V_49 -> V_73 && ! V_49 -> V_35 -> V_74 ) ;
if ( V_49 -> V_73 && V_49 -> V_35 -> V_74 )
V_49 -> V_35 -> V_74 ( V_49 , V_49 -> V_73 ) ;
F_62 ( V_49 -> V_11 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
}
unsigned int F_96 ( struct V_48 * V_49 )
{
unsigned int V_75 = 0 ;
struct V_48 * V_54 ;
F_49 (tmp, plane->dev) {
if ( V_54 == V_49 )
return V_75 ;
V_75 ++ ;
}
F_64 () ;
}
struct V_48 *
F_97 ( struct V_16 * V_17 , int V_155 )
{
struct V_48 * V_49 ;
unsigned int V_1 = 0 ;
F_49 (plane, dev) {
if ( V_1 == V_155 )
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
V_49 -> V_156 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_157 ( V_49 ) ;
if ( V_22 ) {
F_48 ( L_22 ) ;
V_49 -> V_156 = NULL ;
return;
}
F_34 ( V_49 -> V_156 ) ;
V_49 -> V_156 = NULL ;
V_49 -> V_33 = NULL ;
V_49 -> V_47 = NULL ;
}
static int F_98 ( struct V_16 * V_17 )
{
struct V_158 * V_159 ;
V_159 = F_99 ( V_17 , V_160 |
V_161 ,
L_23 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_120 = V_159 ;
V_159 = F_100 ( V_17 , 0 ,
L_24 , V_162 ,
F_2 ( V_162 ) ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_121 = V_159 ;
V_159 = F_99 ( V_17 ,
V_160 |
V_161 ,
L_25 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_163 = V_159 ;
V_159 = F_99 ( V_17 ,
V_160 |
V_161 ,
L_26 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_164 = V_159 ;
V_159 = F_100 ( V_17 , V_161 ,
L_27 , V_165 ,
F_2 ( V_165 ) ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_144 = V_159 ;
V_159 = F_101 ( V_17 , V_166 ,
L_28 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_150 = V_159 ;
V_159 = F_101 ( V_17 , V_166 ,
L_29 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_151 = V_159 ;
V_159 = F_101 ( V_17 , V_166 ,
L_30 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_152 = V_159 ;
V_159 = F_101 ( V_17 , V_166 ,
L_31 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_153 = V_159 ;
V_159 = F_102 ( V_17 , V_166 ,
L_32 , V_168 , V_169 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_146 = V_159 ;
V_159 = F_102 ( V_17 , V_166 ,
L_33 , V_168 , V_169 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_147 = V_159 ;
V_159 = F_101 ( V_17 , V_166 ,
L_34 , 0 , V_169 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_148 = V_159 ;
V_159 = F_101 ( V_17 , V_166 ,
L_35 , 0 , V_169 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_149 = V_159 ;
V_159 = F_103 ( V_17 , V_166 ,
L_36 , V_30 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_145 = V_159 ;
V_159 = F_103 ( V_17 , V_166 ,
L_37 , V_62 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_122 = V_159 ;
V_159 = F_104 ( V_17 , V_166 ,
L_38 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_70 = V_159 ;
V_159 = F_99 ( V_17 ,
V_166 | V_160 ,
L_39 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_71 = V_159 ;
return 0 ;
}
int F_105 ( struct V_16 * V_17 )
{
struct V_158 * V_170 ;
struct V_158 * V_171 ;
if ( V_17 -> V_23 . V_172 )
return 0 ;
V_170 =
F_100 ( V_17 , 0 ,
L_40 ,
V_173 ,
F_2 ( V_173 ) ) ;
V_17 -> V_23 . V_172 = V_170 ;
V_171 = F_100 ( V_17 , V_161 ,
L_41 ,
V_174 ,
F_2 ( V_174 ) ) ;
V_17 -> V_23 . V_175 = V_171 ;
return 0 ;
}
int F_106 ( struct V_16 * V_17 ,
unsigned int V_176 ,
const char * const V_114 [] )
{
struct V_158 * V_177 ;
struct V_158 * V_178 ;
unsigned int V_1 ;
if ( V_17 -> V_23 . V_179 )
return 0 ;
V_177 = F_100 ( V_17 , 0 ,
L_40 ,
V_180 ,
F_2 ( V_180 ) ) ;
if ( ! V_177 )
goto V_181;
V_17 -> V_23 . V_179 = V_177 ;
V_178 =
F_100 ( V_17 , V_161 ,
L_41 ,
V_182 ,
F_2 ( V_182 ) ) ;
if ( ! V_178 )
goto V_181;
V_17 -> V_23 . V_183 = V_178 ;
V_17 -> V_23 . V_184 =
F_101 ( V_17 , 0 , L_42 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_184 )
goto V_181;
V_17 -> V_23 . V_185 =
F_101 ( V_17 , 0 , L_43 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_185 )
goto V_181;
V_17 -> V_23 . V_186 =
F_101 ( V_17 , 0 , L_44 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_186 )
goto V_181;
V_17 -> V_23 . V_187 =
F_101 ( V_17 , 0 , L_45 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_187 )
goto V_181;
V_17 -> V_23 . V_188 =
F_99 ( V_17 , V_189 ,
L_46 , V_176 ) ;
if ( ! V_17 -> V_23 . V_188 )
goto V_181;
for ( V_1 = 0 ; V_1 < V_176 ; V_1 ++ )
F_107 ( V_17 -> V_23 . V_188 , V_1 ,
V_1 , V_114 [ V_1 ] ) ;
V_17 -> V_23 . V_190 =
F_101 ( V_17 , 0 , L_47 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_190 )
goto V_181;
V_17 -> V_23 . V_191 =
F_101 ( V_17 , 0 , L_48 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_191 )
goto V_181;
V_17 -> V_23 . V_192 =
F_101 ( V_17 , 0 , L_49 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_192 )
goto V_181;
V_17 -> V_23 . V_193 =
F_101 ( V_17 , 0 , L_50 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_193 )
goto V_181;
V_17 -> V_23 . V_194 =
F_101 ( V_17 , 0 , L_51 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_194 )
goto V_181;
V_17 -> V_23 . V_195 =
F_101 ( V_17 , 0 , L_52 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_195 )
goto V_181;
return 0 ;
V_181:
return - V_64 ;
}
int F_108 ( struct V_16 * V_17 )
{
struct V_158 * V_196 ;
if ( V_17 -> V_23 . V_197 )
return 0 ;
V_196 =
F_100 ( V_17 , 0 , L_53 ,
V_198 ,
F_2 ( V_198 ) ) ;
V_17 -> V_23 . V_197 = V_196 ;
return 0 ;
}
int F_109 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_199 )
return 0 ;
V_17 -> V_23 . V_199 =
F_100 ( V_17 , 0 , L_54 ,
V_200 ,
F_2 ( V_200 ) ) ;
if ( V_17 -> V_23 . V_199 == NULL )
return - V_64 ;
return 0 ;
}
int F_110 ( struct V_16 * V_17 )
{
struct V_158 * V_201 ;
if ( V_17 -> V_23 . V_202 )
return 0 ;
V_201 =
F_100 ( V_17 , V_161 ,
L_55 ,
V_203 ,
F_2 ( V_203 ) ) ;
V_17 -> V_23 . V_202 = V_201 ;
return 0 ;
}
int F_111 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_204 && V_17 -> V_23 . V_205 )
return 0 ;
V_17 -> V_23 . V_204 =
F_101 ( V_17 , V_161 , L_56 , 0 , 0xffffffff ) ;
V_17 -> V_23 . V_205 =
F_101 ( V_17 , V_161 , L_57 , 0 , 0xffffffff ) ;
if ( V_17 -> V_23 . V_204 == NULL ||
V_17 -> V_23 . V_205 == NULL )
return - V_64 ;
return 0 ;
}
int F_112 ( struct V_16 * V_17 , void * V_206 ,
struct V_207 * V_208 )
{
struct V_209 * V_210 = V_206 ;
struct V_211 * V_212 ;
struct V_32 * V_33 ;
struct V_76 * V_77 ;
struct V_46 * V_47 ;
struct V_127 * V_128 ;
int V_22 = 0 ;
int V_213 = 0 ;
int V_214 = 0 ;
int V_215 = 0 ;
int V_216 = 0 ;
int V_217 = 0 ;
T_1 T_4 * V_218 ;
T_1 T_4 * V_219 ;
T_1 T_4 * V_108 ;
T_1 T_4 * V_220 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
F_11 ( & V_208 -> V_222 ) ;
F_113 (lh, &file_priv->fbs)
V_215 ++ ;
if ( V_210 -> V_223 >= V_215 ) {
V_217 = 0 ;
V_218 = ( T_1 T_4 * ) ( unsigned long ) V_210 -> V_224 ;
F_87 (fb, &file_priv->fbs, filp_head) {
if ( F_114 ( V_33 -> V_39 . V_27 , V_218 + V_217 ) ) {
F_13 ( & V_208 -> V_222 ) ;
return - V_225 ;
}
V_217 ++ ;
}
}
V_210 -> V_223 = V_215 ;
F_13 ( & V_208 -> V_222 ) ;
F_11 ( & V_17 -> V_23 . V_61 ) ;
F_46 (crtc, dev)
V_214 ++ ;
F_115 (connector, dev)
V_213 ++ ;
F_116 (encoder, dev)
V_216 ++ ;
V_210 -> V_226 = V_17 -> V_23 . V_226 ;
V_210 -> V_227 = V_17 -> V_23 . V_227 ;
V_210 -> V_228 = V_17 -> V_23 . V_228 ;
V_210 -> V_229 = V_17 -> V_23 . V_229 ;
if ( V_210 -> V_230 >= V_214 ) {
V_217 = 0 ;
V_219 = ( T_1 T_4 * ) ( unsigned long ) V_210 -> V_231 ;
F_46 (crtc, dev) {
F_73 ( L_58 ,
V_47 -> V_39 . V_27 , V_47 -> V_11 ) ;
if ( F_114 ( V_47 -> V_39 . V_27 , V_219 + V_217 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_217 ++ ;
}
}
V_210 -> V_230 = V_214 ;
if ( V_210 -> V_232 >= V_216 ) {
V_217 = 0 ;
V_220 = ( T_1 T_4 * ) ( unsigned long ) V_210 -> V_233 ;
F_116 (encoder, dev) {
F_73 ( L_59 , V_128 -> V_39 . V_27 ,
V_128 -> V_11 ) ;
if ( F_114 ( V_128 -> V_39 . V_27 , V_220 +
V_217 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_217 ++ ;
}
}
V_210 -> V_232 = V_216 ;
if ( V_210 -> V_234 >= V_213 ) {
V_217 = 0 ;
V_108 = ( T_1 T_4 * ) ( unsigned long ) V_210 -> V_235 ;
F_115 (connector, dev) {
F_73 ( L_60 ,
V_77 -> V_39 . V_27 ,
V_77 -> V_11 ) ;
if ( F_114 ( V_77 -> V_39 . V_27 ,
V_108 + V_217 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_217 ++ ;
}
}
V_210 -> V_234 = V_213 ;
F_73 ( L_61 , V_210 -> V_230 ,
V_210 -> V_234 , V_210 -> V_232 ) ;
V_40:
F_13 ( & V_17 -> V_23 . V_61 ) ;
return V_22 ;
}
int F_117 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_236 * V_237 = V_206 ;
struct V_46 * V_47 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
V_47 = F_118 ( V_17 , V_237 -> V_219 ) ;
if ( ! V_47 )
return - V_238 ;
F_119 ( V_47 , V_47 -> V_52 ) ;
V_237 -> V_239 = V_47 -> V_239 ;
if ( V_47 -> V_52 -> V_33 )
V_237 -> V_218 = V_47 -> V_52 -> V_33 -> V_39 . V_27 ;
else
V_237 -> V_218 = 0 ;
if ( V_47 -> V_73 ) {
V_237 -> V_240 = V_47 -> V_52 -> V_73 -> V_241 >> 16 ;
V_237 -> V_242 = V_47 -> V_52 -> V_73 -> V_243 >> 16 ;
if ( V_47 -> V_73 -> V_244 ) {
F_120 ( & V_237 -> V_79 , & V_47 -> V_73 -> V_79 ) ;
V_237 -> V_245 = 1 ;
} else {
V_237 -> V_245 = 0 ;
}
} else {
V_237 -> V_240 = V_47 -> V_240 ;
V_237 -> V_242 = V_47 -> V_242 ;
if ( V_47 -> V_246 ) {
F_120 ( & V_237 -> V_79 , & V_47 -> V_79 ) ;
V_237 -> V_245 = 1 ;
} else {
V_237 -> V_245 = 0 ;
}
}
F_121 ( V_47 ) ;
return 0 ;
}
static bool F_122 ( const struct V_78 * V_79 ,
const struct V_207 * V_208 )
{
if ( ! V_208 -> V_247 && F_123 ( V_79 ) )
return false ;
return true ;
}
static struct V_127 * F_124 ( struct V_76 * V_77 )
{
if ( V_77 -> V_73 )
return V_77 -> V_73 -> V_248 ;
return V_77 -> V_128 ;
}
static int F_125 ( struct V_18 * V_19 , bool V_249 ,
T_1 T_4 * V_250 , T_5 T_4 * V_251 ,
T_1 * V_252 )
{
int V_253 ;
int V_1 , V_22 , V_217 ;
V_253 = V_19 -> V_65 -> V_254 ;
if ( ! V_249 )
V_253 -= V_19 -> V_65 -> V_255 ;
if ( ( * V_252 >= V_253 ) && V_253 ) {
for ( V_1 = 0 , V_217 = 0 ; V_217 < V_253 ; V_1 ++ ) {
struct V_158 * V_159 = V_19 -> V_65 -> V_65 [ V_1 ] ;
T_5 V_256 ;
if ( ( V_159 -> V_257 & V_166 ) && ! V_249 )
continue;
V_22 = F_126 ( V_19 , V_159 , & V_256 ) ;
if ( V_22 )
return V_22 ;
if ( F_114 ( V_159 -> V_39 . V_27 , V_250 + V_217 ) )
return - V_225 ;
if ( F_114 ( V_256 , V_251 + V_217 ) )
return - V_225 ;
V_217 ++ ;
}
}
* V_252 = V_253 ;
return 0 ;
}
int F_127 ( struct V_16 * V_17 , void * V_206 ,
struct V_207 * V_208 )
{
struct V_258 * V_259 = V_206 ;
struct V_76 * V_77 ;
struct V_127 * V_128 ;
struct V_78 * V_79 ;
int V_260 = 0 ;
int V_261 = 0 ;
int V_22 = 0 ;
int V_217 = 0 ;
int V_1 ;
struct V_262 V_263 ;
struct V_262 T_4 * V_264 ;
T_1 T_4 * V_265 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
memset ( & V_263 , 0 , sizeof( struct V_262 ) ) ;
F_73 ( L_62 , V_259 -> V_108 ) ;
F_11 ( & V_17 -> V_23 . V_61 ) ;
V_77 = F_128 ( V_17 , V_259 -> V_108 ) ;
if ( ! V_77 ) {
V_22 = - V_238 ;
goto V_107;
}
for ( V_1 = 0 ; V_1 < V_266 ; V_1 ++ )
if ( V_77 -> V_267 [ V_1 ] != 0 )
V_261 ++ ;
if ( V_259 -> V_268 == 0 ) {
V_77 -> V_35 -> V_269 ( V_77 ,
V_17 -> V_23 . V_228 ,
V_17 -> V_23 . V_226 ) ;
}
F_87 (mode, &connector->modes, head)
if ( F_122 ( V_79 , V_208 ) )
V_260 ++ ;
V_259 -> V_108 = V_77 -> V_39 . V_27 ;
V_259 -> V_104 = V_77 -> V_104 ;
V_259 -> V_110 = V_77 -> V_110 ;
V_259 -> V_270 = V_77 -> V_126 . V_271 ;
V_259 -> V_272 = V_77 -> V_126 . V_273 ;
V_259 -> V_274 = V_77 -> V_126 . V_8 ;
V_259 -> V_275 = V_77 -> V_5 ;
F_129 ( & V_17 -> V_23 . V_276 , NULL ) ;
V_128 = F_124 ( V_77 ) ;
if ( V_128 )
V_259 -> V_220 = V_128 -> V_39 . V_27 ;
else
V_259 -> V_220 = 0 ;
if ( ( V_259 -> V_268 >= V_260 ) && V_260 ) {
V_217 = 0 ;
V_264 = (struct V_262 T_4 * ) ( unsigned long ) V_259 -> V_277 ;
F_87 (mode, &connector->modes, head) {
if ( ! F_122 ( V_79 , V_208 ) )
continue;
F_120 ( & V_263 , V_79 ) ;
if ( F_130 ( V_264 + V_217 ,
& V_263 , sizeof( V_263 ) ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_217 ++ ;
}
}
V_259 -> V_268 = V_260 ;
V_22 = F_125 ( & V_77 -> V_39 , V_208 -> V_249 ,
( T_1 T_4 * ) ( unsigned long ) ( V_259 -> V_278 ) ,
( T_5 T_4 * ) ( unsigned long ) ( V_259 -> V_279 ) ,
& V_259 -> V_280 ) ;
if ( V_22 )
goto V_40;
if ( ( V_259 -> V_232 >= V_261 ) && V_261 ) {
V_217 = 0 ;
V_265 = ( T_1 T_4 * ) ( unsigned long ) ( V_259 -> V_281 ) ;
for ( V_1 = 0 ; V_1 < V_266 ; V_1 ++ ) {
if ( V_77 -> V_267 [ V_1 ] != 0 ) {
if ( F_114 ( V_77 -> V_267 [ V_1 ] ,
V_265 + V_217 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_217 ++ ;
}
}
}
V_259 -> V_232 = V_261 ;
V_40:
F_131 ( & V_17 -> V_23 . V_276 ) ;
V_107:
F_13 ( & V_17 -> V_23 . V_61 ) ;
return V_22 ;
}
static struct V_46 * F_132 ( struct V_127 * V_128 )
{
struct V_76 * V_77 ;
struct V_16 * V_17 = V_128 -> V_17 ;
bool V_282 = false ;
F_115 (connector, dev) {
if ( ! V_77 -> V_73 )
continue;
V_282 = true ;
if ( V_77 -> V_73 -> V_248 != V_128 )
continue;
return V_77 -> V_73 -> V_47 ;
}
if ( V_282 )
return NULL ;
return V_128 -> V_47 ;
}
int F_133 ( struct V_16 * V_17 , void * V_206 ,
struct V_207 * V_208 )
{
struct V_283 * V_284 = V_206 ;
struct V_127 * V_128 ;
struct V_46 * V_47 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
V_128 = F_134 ( V_17 , V_284 -> V_220 ) ;
if ( ! V_128 )
return - V_238 ;
F_129 ( & V_17 -> V_23 . V_276 , NULL ) ;
V_47 = F_132 ( V_128 ) ;
if ( V_47 )
V_284 -> V_219 = V_47 -> V_39 . V_27 ;
else
V_284 -> V_219 = 0 ;
F_131 ( & V_17 -> V_23 . V_276 ) ;
V_284 -> V_130 = V_128 -> V_130 ;
V_284 -> V_220 = V_128 -> V_39 . V_27 ;
V_284 -> V_68 = V_128 -> V_68 ;
V_284 -> V_285 = V_128 -> V_285 ;
return 0 ;
}
int F_135 ( struct V_16 * V_17 , void * V_206 ,
struct V_207 * V_208 )
{
struct V_286 * V_287 = V_206 ;
struct V_57 * V_58 ;
struct V_48 * V_49 ;
T_1 T_4 * V_288 ;
int V_217 = 0 ;
unsigned V_289 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
V_58 = & V_17 -> V_23 ;
if ( V_208 -> V_290 )
V_289 = V_58 -> V_141 ;
else
V_289 = V_58 -> V_143 ;
if ( V_289 &&
( V_287 -> V_291 >= V_289 ) ) {
V_288 = ( T_1 T_4 * ) ( unsigned long ) V_287 -> V_292 ;
F_49 (plane, dev) {
if ( V_49 -> type != V_142 &&
! V_208 -> V_290 )
continue;
if ( F_114 ( V_49 -> V_39 . V_27 , V_288 + V_217 ) )
return - V_225 ;
V_217 ++ ;
}
}
V_287 -> V_291 = V_289 ;
return 0 ;
}
int F_136 ( struct V_16 * V_17 , void * V_206 ,
struct V_207 * V_208 )
{
struct V_293 * V_287 = V_206 ;
struct V_48 * V_49 ;
T_1 T_4 * V_294 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
V_49 = F_137 ( V_17 , V_287 -> V_295 ) ;
if ( ! V_49 )
return - V_238 ;
F_129 ( & V_49 -> V_61 , NULL ) ;
if ( V_49 -> V_47 )
V_287 -> V_219 = V_49 -> V_47 -> V_39 . V_27 ;
else
V_287 -> V_219 = 0 ;
if ( V_49 -> V_33 )
V_287 -> V_218 = V_49 -> V_33 -> V_39 . V_27 ;
else
V_287 -> V_218 = 0 ;
F_131 ( & V_49 -> V_61 ) ;
V_287 -> V_295 = V_49 -> V_39 . V_27 ;
V_287 -> V_68 = V_49 -> V_68 ;
V_287 -> V_239 = 0 ;
if ( V_49 -> V_136 &&
( V_287 -> V_296 >= V_49 -> V_136 ) ) {
V_294 = ( T_1 T_4 * ) ( unsigned long ) V_287 -> V_297 ;
if ( F_130 ( V_294 ,
V_49 -> V_139 ,
sizeof( T_1 ) * V_49 -> V_136 ) ) {
return - V_225 ;
}
}
V_287 -> V_296 = V_49 -> V_136 ;
return 0 ;
}
int F_138 ( const struct V_48 * V_49 , T_3 V_13 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_49 -> V_136 ; V_1 ++ ) {
if ( V_13 == V_49 -> V_139 [ V_1 ] )
return 0 ;
}
return - V_85 ;
}
static int F_139 ( T_1 V_241 , T_1 V_243 ,
T_1 V_298 , T_1 V_299 ,
const struct V_32 * V_33 )
{
unsigned int V_300 , V_301 ;
V_300 = V_33 -> V_302 << 16 ;
V_301 = V_33 -> V_303 << 16 ;
if ( V_298 > V_300 ||
V_241 > V_300 - V_298 ||
V_299 > V_301 ||
V_243 > V_301 - V_299 ) {
F_73 ( L_63
L_64 ,
V_298 >> 16 , ( ( V_298 & 0xffff ) * 15625 ) >> 10 ,
V_299 >> 16 , ( ( V_299 & 0xffff ) * 15625 ) >> 10 ,
V_241 >> 16 , ( ( V_241 & 0xffff ) * 15625 ) >> 10 ,
V_243 >> 16 , ( ( V_243 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_304 ;
}
return 0 ;
}
static int F_140 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_6 V_305 , T_6 V_306 ,
T_1 V_307 , T_1 V_308 ,
T_1 V_241 , T_1 V_243 ,
T_1 V_298 , T_1 V_299 )
{
int V_22 = 0 ;
if ( ! V_33 ) {
V_49 -> V_156 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_157 ( V_49 ) ;
if ( ! V_22 ) {
V_49 -> V_47 = NULL ;
V_49 -> V_33 = NULL ;
} else {
V_49 -> V_156 = NULL ;
}
goto V_40;
}
if ( ! ( V_49 -> V_68 & F_141 ( V_47 ) ) ) {
F_73 ( L_65 ) ;
V_22 = - V_85 ;
goto V_40;
}
V_22 = F_138 ( V_49 , V_33 -> V_309 ) ;
if ( V_22 ) {
F_73 ( L_66 ,
F_9 ( V_33 -> V_309 ) ) ;
goto V_40;
}
if ( V_307 > V_169 ||
V_305 > V_169 - ( T_6 ) V_307 ||
V_308 > V_169 ||
V_306 > V_169 - ( T_6 ) V_308 ) {
F_73 ( L_67 ,
V_307 , V_308 , V_305 , V_306 ) ;
V_22 = - V_310 ;
goto V_40;
}
V_22 = F_139 ( V_241 , V_243 , V_298 , V_299 , V_33 ) ;
if ( V_22 )
goto V_40;
V_49 -> V_156 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_311 ( V_49 , V_47 , V_33 ,
V_305 , V_306 , V_307 , V_308 ,
V_241 , V_243 , V_298 , V_299 ) ;
if ( ! V_22 ) {
V_49 -> V_47 = V_47 ;
V_49 -> V_33 = V_33 ;
V_33 = NULL ;
} else {
V_49 -> V_156 = NULL ;
}
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
if ( V_49 -> V_156 )
F_34 ( V_49 -> V_156 ) ;
V_49 -> V_156 = NULL ;
return V_22 ;
}
static int F_142 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_6 V_305 , T_6 V_306 ,
T_1 V_307 , T_1 V_308 ,
T_1 V_241 , T_1 V_243 ,
T_1 V_298 , T_1 V_299 )
{
int V_22 ;
F_45 ( V_49 -> V_17 ) ;
V_22 = F_140 ( V_49 , V_47 , V_33 ,
V_305 , V_306 , V_307 , V_308 ,
V_241 , V_243 , V_298 , V_299 ) ;
F_51 ( V_49 -> V_17 ) ;
return V_22 ;
}
int F_143 ( struct V_16 * V_17 , void * V_206 ,
struct V_207 * V_208 )
{
struct V_312 * V_313 = V_206 ;
struct V_48 * V_49 ;
struct V_46 * V_47 = NULL ;
struct V_32 * V_33 = NULL ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
V_49 = F_137 ( V_17 , V_313 -> V_295 ) ;
if ( ! V_49 ) {
F_73 ( L_68 ,
V_313 -> V_295 ) ;
return - V_238 ;
}
if ( V_313 -> V_218 ) {
V_33 = F_32 ( V_17 , V_313 -> V_218 ) ;
if ( ! V_33 ) {
F_73 ( L_69 ,
V_313 -> V_218 ) ;
return - V_238 ;
}
V_47 = F_118 ( V_17 , V_313 -> V_219 ) ;
if ( ! V_47 ) {
F_73 ( L_70 ,
V_313 -> V_219 ) ;
return - V_238 ;
}
}
return F_142 ( V_49 , V_47 , V_33 ,
V_313 -> V_305 , V_313 -> V_306 ,
V_313 -> V_307 , V_313 -> V_308 ,
V_313 -> V_241 , V_313 -> V_243 ,
V_313 -> V_298 , V_313 -> V_299 ) ;
}
int F_47 ( struct V_50 * V_51 )
{
struct V_46 * V_47 = V_51 -> V_47 ;
struct V_32 * V_33 ;
struct V_46 * V_54 ;
int V_22 ;
F_46 (tmp, crtc->dev)
V_54 -> V_52 -> V_156 = V_54 -> V_52 -> V_33 ;
V_33 = V_51 -> V_33 ;
V_22 = V_47 -> V_35 -> V_314 ( V_51 ) ;
if ( V_22 == 0 ) {
V_47 -> V_52 -> V_47 = V_47 ;
V_47 -> V_52 -> V_33 = V_33 ;
}
F_46 (tmp, crtc->dev) {
if ( V_54 -> V_52 -> V_33 )
F_38 ( V_54 -> V_52 -> V_33 ) ;
if ( V_54 -> V_52 -> V_156 )
F_34 ( V_54 -> V_52 -> V_156 ) ;
V_54 -> V_52 -> V_156 = NULL ;
}
return V_22 ;
}
void F_144 ( const struct V_78 * V_79 ,
int * V_315 , int * V_316 )
{
struct V_78 V_317 ;
F_145 ( & V_317 , V_79 ) ;
F_146 ( & V_317 , V_318 ) ;
* V_315 = V_317 . V_319 ;
* V_316 = V_317 . V_320 ;
}
int F_147 ( const struct V_46 * V_47 ,
int V_240 , int V_242 ,
const struct V_78 * V_79 ,
const struct V_32 * V_33 )
{
int V_315 , V_316 ;
F_144 ( V_79 , & V_315 , & V_316 ) ;
if ( V_47 -> V_73 &&
V_47 -> V_52 -> V_73 -> V_321 & ( F_148 ( V_322 ) |
F_148 ( V_323 ) ) )
F_149 ( V_315 , V_316 ) ;
return F_139 ( V_240 << 16 , V_242 << 16 ,
V_315 << 16 , V_316 << 16 , V_33 ) ;
}
int F_150 ( struct V_16 * V_17 , void * V_206 ,
struct V_207 * V_208 )
{
struct V_57 * V_58 = & V_17 -> V_23 ;
struct V_236 * V_324 = V_206 ;
struct V_46 * V_47 ;
struct V_76 * * V_325 = NULL , * V_77 ;
struct V_32 * V_33 = NULL ;
struct V_78 * V_79 = NULL ;
struct V_50 V_51 ;
T_1 T_4 * V_326 ;
int V_22 ;
int V_1 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
if ( V_324 -> V_240 & 0xffff0000 || V_324 -> V_242 & 0xffff0000 )
return - V_310 ;
F_45 ( V_17 ) ;
V_47 = F_118 ( V_17 , V_324 -> V_219 ) ;
if ( ! V_47 ) {
F_73 ( L_71 , V_324 -> V_219 ) ;
V_22 = - V_238 ;
goto V_40;
}
F_73 ( L_58 , V_47 -> V_39 . V_27 , V_47 -> V_11 ) ;
if ( V_324 -> V_245 ) {
if ( V_324 -> V_218 == - 1 ) {
if ( ! V_47 -> V_52 -> V_33 ) {
F_73 ( L_72 ) ;
V_22 = - V_85 ;
goto V_40;
}
V_33 = V_47 -> V_52 -> V_33 ;
F_38 ( V_33 ) ;
} else {
V_33 = F_32 ( V_17 , V_324 -> V_218 ) ;
if ( ! V_33 ) {
F_73 ( L_73 ,
V_324 -> V_218 ) ;
V_22 = - V_238 ;
goto V_40;
}
}
V_79 = F_151 ( V_17 ) ;
if ( ! V_79 ) {
V_22 = - V_64 ;
goto V_40;
}
V_22 = F_152 ( V_79 , & V_324 -> V_79 ) ;
if ( V_22 ) {
F_73 ( L_74 ) ;
goto V_40;
}
F_146 ( V_79 , V_327 ) ;
if ( ! V_47 -> V_52 -> V_328 ) {
V_22 = F_138 ( V_47 -> V_52 ,
V_33 -> V_309 ) ;
if ( V_22 ) {
F_73 ( L_66 ,
F_9 ( V_33 -> V_309 ) ) ;
goto V_40;
}
}
V_22 = F_147 ( V_47 , V_324 -> V_240 , V_324 -> V_242 ,
V_79 , V_33 ) ;
if ( V_22 )
goto V_40;
}
if ( V_324 -> V_234 == 0 && V_79 ) {
F_73 ( L_75 ) ;
V_22 = - V_85 ;
goto V_40;
}
if ( V_324 -> V_234 > 0 && ( ! V_79 || ! V_33 ) ) {
F_73 ( L_76 ,
V_324 -> V_234 ) ;
V_22 = - V_85 ;
goto V_40;
}
if ( V_324 -> V_234 > 0 ) {
T_3 V_329 ;
if ( V_324 -> V_234 > V_58 -> V_118 ) {
V_22 = - V_85 ;
goto V_40;
}
V_325 = F_92 ( V_324 -> V_234 ,
sizeof( struct V_76 * ) ,
V_26 ) ;
if ( ! V_325 ) {
V_22 = - V_64 ;
goto V_40;
}
for ( V_1 = 0 ; V_1 < V_324 -> V_234 ; V_1 ++ ) {
V_326 = ( T_1 T_4 * ) ( unsigned long ) V_324 -> V_326 ;
if ( F_153 ( V_329 , & V_326 [ V_1 ] ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_77 = F_128 ( V_17 , V_329 ) ;
if ( ! V_77 ) {
F_73 ( L_77 ,
V_329 ) ;
V_22 = - V_238 ;
goto V_40;
}
F_73 ( L_60 ,
V_77 -> V_39 . V_27 ,
V_77 -> V_11 ) ;
V_325 [ V_1 ] = V_77 ;
}
}
V_51 . V_47 = V_47 ;
V_51 . V_240 = V_324 -> V_240 ;
V_51 . V_242 = V_324 -> V_242 ;
V_51 . V_79 = V_79 ;
V_51 . V_330 = V_325 ;
V_51 . V_331 = V_324 -> V_234 ;
V_51 . V_33 = V_33 ;
V_22 = F_47 ( & V_51 ) ;
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
F_62 ( V_325 ) ;
F_66 ( V_17 , V_79 ) ;
F_51 ( V_17 ) ;
return V_22 ;
}
static int F_154 ( struct V_46 * V_47 ,
struct V_332 * V_333 ,
struct V_207 * V_208 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
struct V_32 * V_33 = NULL ;
struct V_334 V_335 = {
. V_302 = V_333 -> V_302 ,
. V_303 = V_333 -> V_303 ,
. V_309 = V_336 ,
. V_337 = { V_333 -> V_302 * 4 } ,
. V_338 = { V_333 -> V_339 } ,
} ;
T_6 V_305 , V_306 ;
T_1 V_307 = 0 , V_308 = 0 ;
T_1 V_298 = 0 , V_299 = 0 ;
int V_22 = 0 ;
F_95 ( ! V_47 -> V_55 ) ;
F_22 ( V_47 -> V_55 -> V_47 != V_47 && V_47 -> V_55 -> V_47 != NULL ) ;
if ( V_333 -> V_257 & V_340 ) {
if ( V_333 -> V_339 ) {
V_33 = F_155 ( V_17 , & V_335 , V_208 ) ;
if ( F_156 ( V_33 ) ) {
F_73 ( L_78 ) ;
return F_157 ( V_33 ) ;
}
} else {
V_33 = NULL ;
}
} else {
V_33 = V_47 -> V_55 -> V_33 ;
if ( V_33 )
F_38 ( V_33 ) ;
}
if ( V_333 -> V_257 & V_341 ) {
V_305 = V_333 -> V_240 ;
V_306 = V_333 -> V_242 ;
} else {
V_305 = V_47 -> V_342 ;
V_306 = V_47 -> V_343 ;
}
if ( V_33 ) {
V_307 = V_33 -> V_302 ;
V_308 = V_33 -> V_303 ;
V_298 = V_33 -> V_302 << 16 ;
V_299 = V_33 -> V_303 << 16 ;
}
V_22 = F_140 ( V_47 -> V_55 , V_47 , V_33 ,
V_305 , V_306 , V_307 , V_308 ,
0 , 0 , V_298 , V_299 ) ;
if ( V_22 == 0 && V_333 -> V_257 & V_341 ) {
V_47 -> V_342 = V_333 -> V_240 ;
V_47 -> V_343 = V_333 -> V_242 ;
}
return V_22 ;
}
static int F_158 ( struct V_16 * V_17 ,
struct V_332 * V_333 ,
struct V_207 * V_208 )
{
struct V_46 * V_47 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
if ( ! V_333 -> V_257 || ( ~ V_344 & V_333 -> V_257 ) )
return - V_85 ;
V_47 = F_118 ( V_17 , V_333 -> V_219 ) ;
if ( ! V_47 ) {
F_73 ( L_71 , V_333 -> V_219 ) ;
return - V_238 ;
}
F_119 ( V_47 , V_47 -> V_55 ) ;
if ( V_47 -> V_55 ) {
V_22 = F_154 ( V_47 , V_333 , V_208 ) ;
goto V_40;
}
if ( V_333 -> V_257 & V_340 ) {
if ( ! V_47 -> V_35 -> V_345 && ! V_47 -> V_35 -> V_346 ) {
V_22 = - V_347 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_346 )
V_22 = V_47 -> V_35 -> V_346 ( V_47 , V_208 , V_333 -> V_339 ,
V_333 -> V_302 , V_333 -> V_303 , V_333 -> V_348 , V_333 -> V_349 ) ;
else
V_22 = V_47 -> V_35 -> V_345 ( V_47 , V_208 , V_333 -> V_339 ,
V_333 -> V_302 , V_333 -> V_303 ) ;
}
if ( V_333 -> V_257 & V_341 ) {
if ( V_47 -> V_35 -> V_350 ) {
V_22 = V_47 -> V_35 -> V_350 ( V_47 , V_333 -> V_240 , V_333 -> V_242 ) ;
} else {
V_22 = - V_225 ;
goto V_40;
}
}
V_40:
F_121 ( V_47 ) ;
return V_22 ;
}
int F_159 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_351 * V_333 = V_206 ;
struct V_332 V_352 ;
memcpy ( & V_352 , V_333 , sizeof( struct V_351 ) ) ;
V_352 . V_348 = V_352 . V_349 = 0 ;
return F_158 ( V_17 , & V_352 , V_208 ) ;
}
int F_160 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_332 * V_333 = V_206 ;
return F_158 ( V_17 , V_333 , V_208 ) ;
}
T_1 F_161 ( T_1 V_353 , T_1 V_354 )
{
T_1 V_355 ;
switch ( V_353 ) {
case 8 :
V_355 = V_356 ;
break;
case 16 :
if ( V_354 == 15 )
V_355 = V_357 ;
else
V_355 = V_358 ;
break;
case 24 :
V_355 = V_359 ;
break;
case 32 :
if ( V_354 == 24 )
V_355 = V_360 ;
else if ( V_354 == 30 )
V_355 = V_361 ;
else
V_355 = V_336 ;
break;
default:
F_48 ( L_79 ) ;
V_355 = V_360 ;
break;
}
return V_355 ;
}
int F_162 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_362 * V_363 = V_206 ;
struct V_334 V_364 = {} ;
int V_22 ;
V_364 . V_218 = V_363 -> V_218 ;
V_364 . V_302 = V_363 -> V_302 ;
V_364 . V_303 = V_363 -> V_303 ;
V_364 . V_337 [ 0 ] = V_363 -> V_365 ;
V_364 . V_309 = F_161 ( V_363 -> V_353 , V_363 -> V_354 ) ;
V_364 . V_338 [ 0 ] = V_363 -> V_339 ;
V_22 = F_163 ( V_17 , & V_364 , V_208 ) ;
if ( V_22 )
return V_22 ;
V_363 -> V_218 = V_364 . V_218 ;
return 0 ;
}
static int F_164 ( const struct V_334 * V_364 )
{
T_1 V_13 = V_364 -> V_309 & ~ V_15 ;
switch ( V_13 ) {
case V_356 :
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
case V_357 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_358 :
case V_383 :
case V_359 :
case V_384 :
case V_360 :
case V_385 :
case V_386 :
case V_387 :
case V_336 :
case V_388 :
case V_389 :
case V_390 :
case V_361 :
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
case V_416 :
case V_417 :
case V_418 :
return 0 ;
default:
F_73 ( L_80 ,
F_9 ( V_364 -> V_309 ) ) ;
return - V_85 ;
}
}
static int F_165 ( const struct V_334 * V_364 )
{
int V_22 , V_419 , V_420 , V_289 , V_1 ;
V_22 = F_164 ( V_364 ) ;
if ( V_22 ) {
F_73 ( L_81 ,
F_9 ( V_364 -> V_309 ) ) ;
return V_22 ;
}
V_419 = F_166 ( V_364 -> V_309 ) ;
V_420 = F_167 ( V_364 -> V_309 ) ;
V_289 = F_168 ( V_364 -> V_309 ) ;
if ( V_364 -> V_302 == 0 || V_364 -> V_302 % V_419 ) {
F_73 ( L_82 , V_364 -> V_302 ) ;
return - V_85 ;
}
if ( V_364 -> V_303 == 0 || V_364 -> V_303 % V_420 ) {
F_73 ( L_83 , V_364 -> V_303 ) ;
return - V_85 ;
}
for ( V_1 = 0 ; V_1 < V_289 ; V_1 ++ ) {
unsigned int V_302 = V_364 -> V_302 / ( V_1 != 0 ? V_419 : 1 ) ;
unsigned int V_303 = V_364 -> V_303 / ( V_1 != 0 ? V_420 : 1 ) ;
unsigned int V_421 = F_169 ( V_364 -> V_309 , V_1 ) ;
if ( ! V_364 -> V_338 [ V_1 ] ) {
F_73 ( L_84 , V_1 ) ;
return - V_85 ;
}
if ( ( T_5 ) V_302 * V_421 > V_167 )
return - V_310 ;
if ( ( T_5 ) V_303 * V_364 -> V_337 [ V_1 ] + V_364 -> V_422 [ V_1 ] > V_167 )
return - V_310 ;
if ( V_364 -> V_337 [ V_1 ] < V_302 * V_421 ) {
F_73 ( L_85 , V_364 -> V_337 [ V_1 ] , V_1 ) ;
return - V_85 ;
}
if ( V_364 -> V_423 [ V_1 ] && ! ( V_364 -> V_257 & V_424 ) ) {
F_73 ( L_86 ,
V_364 -> V_423 [ V_1 ] , V_1 ) ;
return - V_85 ;
}
switch ( V_364 -> V_423 [ V_1 ] ) {
case V_425 :
if ( V_364 -> V_309 != V_403 ||
V_302 % 128 || V_303 % 32 ||
V_364 -> V_337 [ V_1 ] % 128 ) {
F_73 ( L_87 , V_1 ) ;
return - V_85 ;
}
break;
default:
break;
}
}
for ( V_1 = V_289 ; V_1 < 4 ; V_1 ++ ) {
if ( V_364 -> V_423 [ V_1 ] ) {
F_73 ( L_88 , V_1 ) ;
return - V_85 ;
}
if ( ! ( V_364 -> V_257 & V_424 ) )
continue;
if ( V_364 -> V_338 [ V_1 ] ) {
F_73 ( L_89 , V_1 ) ;
return - V_85 ;
}
if ( V_364 -> V_337 [ V_1 ] ) {
F_73 ( L_90 , V_1 ) ;
return - V_85 ;
}
if ( V_364 -> V_422 [ V_1 ] ) {
F_73 ( L_91 , V_1 ) ;
return - V_85 ;
}
}
return 0 ;
}
static struct V_32 *
F_155 ( struct V_16 * V_17 ,
const struct V_334 * V_364 ,
struct V_207 * V_208 )
{
struct V_57 * V_58 = & V_17 -> V_23 ;
struct V_32 * V_33 ;
int V_22 ;
if ( V_364 -> V_257 & ~ ( V_426 | V_424 ) ) {
F_73 ( L_92 , V_364 -> V_257 ) ;
return F_170 ( - V_85 ) ;
}
if ( ( V_58 -> V_229 > V_364 -> V_302 ) || ( V_364 -> V_302 > V_58 -> V_228 ) ) {
F_73 ( L_93 ,
V_364 -> V_302 , V_58 -> V_229 , V_58 -> V_228 ) ;
return F_170 ( - V_85 ) ;
}
if ( ( V_58 -> V_227 > V_364 -> V_303 ) || ( V_364 -> V_303 > V_58 -> V_226 ) ) {
F_73 ( L_94 ,
V_364 -> V_303 , V_58 -> V_227 , V_58 -> V_226 ) ;
return F_170 ( - V_85 ) ;
}
if ( V_364 -> V_257 & V_424 &&
! V_17 -> V_23 . V_427 ) {
F_73 ( L_95 ) ;
return F_170 ( - V_85 ) ;
}
V_22 = F_165 ( V_364 ) ;
if ( V_22 )
return F_170 ( V_22 ) ;
V_33 = V_17 -> V_23 . V_35 -> V_428 ( V_17 , V_208 , V_364 ) ;
if ( F_156 ( V_33 ) ) {
F_73 ( L_96 ) ;
return V_33 ;
}
return V_33 ;
}
int F_163 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_334 * V_364 = V_206 ;
struct V_32 * V_33 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
V_33 = F_155 ( V_17 , V_364 , V_208 ) ;
if ( F_156 ( V_33 ) )
return F_157 ( V_33 ) ;
F_73 ( L_97 , V_33 -> V_39 . V_27 ) ;
F_11 ( & V_208 -> V_222 ) ;
V_364 -> V_218 = V_33 -> V_39 . V_27 ;
F_26 ( & V_33 -> V_38 , & V_208 -> V_429 ) ;
F_13 ( & V_208 -> V_222 ) ;
return 0 ;
}
int F_171 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_32 * V_33 = NULL ;
struct V_32 * V_430 = NULL ;
T_1 * V_27 = V_206 ;
int V_431 = 0 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
F_11 ( & V_208 -> V_222 ) ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
V_33 = F_30 ( V_17 , * V_27 ) ;
if ( ! V_33 )
goto V_432;
F_87 (fbl, &file_priv->fbs, filp_head)
if ( V_33 == V_430 )
V_431 = 1 ;
if ( ! V_431 )
goto V_432;
F_172 ( & V_33 -> V_38 ) ;
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_208 -> V_222 ) ;
F_34 ( V_33 ) ;
return 0 ;
V_432:
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_208 -> V_222 ) ;
return - V_238 ;
}
int F_173 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_362 * V_364 = V_206 ;
struct V_32 * V_33 ;
int V_22 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
V_33 = F_32 ( V_17 , V_364 -> V_218 ) ;
if ( ! V_33 )
return - V_238 ;
V_364 -> V_303 = V_33 -> V_303 ;
V_364 -> V_302 = V_33 -> V_302 ;
V_364 -> V_354 = V_33 -> V_354 ;
V_364 -> V_353 = V_33 -> V_433 ;
V_364 -> V_365 = V_33 -> V_337 [ 0 ] ;
if ( V_33 -> V_35 -> V_434 ) {
if ( V_208 -> V_435 || F_174 ( V_436 ) ||
F_175 ( V_208 ) ) {
V_22 = V_33 -> V_35 -> V_434 ( V_33 , V_208 ,
& V_364 -> V_339 ) ;
} else {
V_364 -> V_339 = 0 ;
V_22 = 0 ;
}
} else {
V_22 = - V_437 ;
}
F_34 ( V_33 ) ;
return V_22 ;
}
int F_176 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_438 T_4 * V_439 ;
struct V_438 * V_440 = NULL ;
struct V_441 * V_364 = V_206 ;
struct V_32 * V_33 ;
unsigned V_257 ;
int V_442 ;
int V_22 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
V_33 = F_32 ( V_17 , V_364 -> V_218 ) ;
if ( ! V_33 )
return - V_238 ;
V_442 = V_364 -> V_442 ;
V_439 = (struct V_438 T_4 * ) ( unsigned long ) V_364 -> V_439 ;
if ( ! V_442 != ! V_439 ) {
V_22 = - V_85 ;
goto V_443;
}
V_257 = V_444 & V_364 -> V_257 ;
if ( V_257 & V_445 && ( V_442 % 2 ) ) {
V_22 = - V_85 ;
goto V_443;
}
if ( V_442 && V_439 ) {
if ( V_442 < 0 || V_442 > V_446 ) {
V_22 = - V_85 ;
goto V_443;
}
V_440 = F_177 ( V_442 , sizeof( * V_440 ) , V_26 ) ;
if ( ! V_440 ) {
V_22 = - V_64 ;
goto V_443;
}
V_22 = F_178 ( V_440 , V_439 ,
V_442 * sizeof( * V_440 ) ) ;
if ( V_22 ) {
V_22 = - V_225 ;
goto V_447;
}
}
if ( V_33 -> V_35 -> V_448 ) {
V_22 = V_33 -> V_35 -> V_448 ( V_33 , V_208 , V_257 , V_364 -> V_449 ,
V_440 , V_442 ) ;
} else {
V_22 = - V_450 ;
}
V_447:
F_62 ( V_440 ) ;
V_443:
F_34 ( V_33 ) ;
return V_22 ;
}
void F_179 ( struct V_207 * V_451 )
{
struct V_32 * V_33 , * V_452 ;
F_79 (fb, tfb, &priv->fbs, filp_head) {
F_172 ( & V_33 -> V_38 ) ;
F_34 ( V_33 ) ;
}
}
struct V_158 * F_99 ( struct V_16 * V_17 , int V_257 ,
const char * V_11 , int V_453 )
{
struct V_158 * V_454 = NULL ;
int V_22 ;
V_454 = F_180 ( sizeof( struct V_158 ) , V_26 ) ;
if ( ! V_454 )
return NULL ;
V_454 -> V_17 = V_17 ;
if ( V_453 ) {
V_454 -> V_455 = F_177 ( V_453 , sizeof( T_5 ) ,
V_26 ) ;
if ( ! V_454 -> V_455 )
goto V_456;
}
V_22 = F_14 ( V_17 , & V_454 -> V_39 , V_457 ) ;
if ( V_22 )
goto V_456;
V_454 -> V_257 = V_257 ;
V_454 -> V_453 = V_453 ;
F_25 ( & V_454 -> V_458 ) ;
if ( V_11 ) {
strncpy ( V_454 -> V_11 , V_11 , V_459 ) ;
V_454 -> V_11 [ V_459 - 1 ] = '\0' ;
}
F_57 ( & V_454 -> V_42 , & V_17 -> V_23 . V_460 ) ;
F_22 ( ! F_181 ( V_454 ) ) ;
return V_454 ;
V_456:
F_62 ( V_454 -> V_455 ) ;
F_62 ( V_454 ) ;
return NULL ;
}
struct V_158 * F_100 ( struct V_16 * V_17 , int V_257 ,
const char * V_11 ,
const struct V_461 * V_462 ,
int V_453 )
{
struct V_158 * V_454 ;
int V_1 , V_22 ;
V_257 |= V_189 ;
V_454 = F_99 ( V_17 , V_257 , V_11 , V_453 ) ;
if ( ! V_454 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_453 ; V_1 ++ ) {
V_22 = F_107 ( V_454 , V_1 ,
V_462 [ V_1 ] . type ,
V_462 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_182 ( V_17 , V_454 ) ;
return NULL ;
}
}
return V_454 ;
}
struct V_158 * F_183 ( struct V_16 * V_17 ,
int V_257 , const char * V_11 ,
const struct V_461 * V_462 ,
int V_463 ,
T_5 V_464 )
{
struct V_158 * V_454 ;
int V_1 , V_22 , V_75 = 0 ;
int V_453 = F_184 ( V_464 ) ;
V_257 |= V_465 ;
V_454 = F_99 ( V_17 , V_257 , V_11 , V_453 ) ;
if ( ! V_454 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_463 ; V_1 ++ ) {
if ( ! ( V_464 & ( 1ULL << V_462 [ V_1 ] . type ) ) )
continue;
if ( F_22 ( V_75 >= V_453 ) ) {
F_182 ( V_17 , V_454 ) ;
return NULL ;
}
V_22 = F_107 ( V_454 , V_75 ++ ,
V_462 [ V_1 ] . type ,
V_462 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_182 ( V_17 , V_454 ) ;
return NULL ;
}
}
return V_454 ;
}
static struct V_158 * F_185 ( struct V_16 * V_17 ,
int V_257 , const char * V_11 ,
T_5 V_466 , T_5 V_467 )
{
struct V_158 * V_454 ;
V_454 = F_99 ( V_17 , V_257 , V_11 , 2 ) ;
if ( ! V_454 )
return NULL ;
V_454 -> V_455 [ 0 ] = V_466 ;
V_454 -> V_455 [ 1 ] = V_467 ;
return V_454 ;
}
struct V_158 * F_101 ( struct V_16 * V_17 , int V_257 ,
const char * V_11 ,
T_5 V_466 , T_5 V_467 )
{
return F_185 ( V_17 , V_468 | V_257 ,
V_11 , V_466 , V_467 ) ;
}
struct V_158 * F_102 ( struct V_16 * V_17 ,
int V_257 , const char * V_11 ,
T_7 V_466 , T_7 V_467 )
{
return F_185 ( V_17 , V_469 | V_257 ,
V_11 , F_186 ( V_466 ) , F_186 ( V_467 ) ) ;
}
struct V_158 * F_103 ( struct V_16 * V_17 ,
int V_257 , const char * V_11 , T_1 type )
{
struct V_158 * V_454 ;
V_257 |= V_470 ;
if ( F_22 ( ! ( V_257 & V_166 ) ) )
return NULL ;
V_454 = F_99 ( V_17 , V_257 , V_11 , 1 ) ;
if ( ! V_454 )
return NULL ;
V_454 -> V_455 [ 0 ] = type ;
return V_454 ;
}
struct V_158 * F_104 ( struct V_16 * V_17 , int V_257 ,
const char * V_11 )
{
return F_101 ( V_17 , V_257 , V_11 , 0 , 1 ) ;
}
int F_107 ( struct V_158 * V_454 , int V_75 ,
T_5 V_471 , const char * V_11 )
{
struct V_472 * V_473 ;
if ( ! ( F_187 ( V_454 , V_189 ) ||
F_187 ( V_454 , V_465 ) ) )
return - V_85 ;
if ( F_187 ( V_454 , V_465 ) &&
( V_471 > 63 ) )
return - V_85 ;
if ( ! F_44 ( & V_454 -> V_458 ) ) {
F_87 (prop_enum, &property->enum_list, head) {
if ( V_473 -> V_471 == V_471 ) {
strncpy ( V_473 -> V_11 , V_11 , V_459 ) ;
V_473 -> V_11 [ V_459 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_473 = F_180 ( sizeof( struct V_472 ) , V_26 ) ;
if ( ! V_473 )
return - V_64 ;
strncpy ( V_473 -> V_11 , V_11 , V_459 ) ;
V_473 -> V_11 [ V_459 - 1 ] = '\0' ;
V_473 -> V_471 = V_471 ;
V_454 -> V_455 [ V_75 ] = V_471 ;
F_57 ( & V_473 -> V_42 , & V_454 -> V_458 ) ;
return 0 ;
}
void F_182 ( struct V_16 * V_17 , struct V_158 * V_454 )
{
struct V_472 * V_473 , * V_474 ;
F_79 (prop_enum, pt, &property->enum_list, head) {
F_42 ( & V_473 -> V_42 ) ;
F_62 ( V_473 ) ;
}
if ( V_454 -> V_453 )
F_62 ( V_454 -> V_455 ) ;
F_17 ( V_17 , & V_454 -> V_39 ) ;
F_42 ( & V_454 -> V_42 ) ;
F_62 ( V_454 ) ;
}
void F_60 ( struct V_18 * V_19 ,
struct V_158 * V_454 ,
T_5 V_475 )
{
int V_254 = V_19 -> V_65 -> V_254 ;
if ( V_254 == V_476 ) {
F_188 ( 1 , L_98
L_99
L_100 ,
V_19 -> type ) ;
return;
}
V_19 -> V_65 -> V_65 [ V_254 ] = V_454 ;
V_19 -> V_65 -> V_455 [ V_254 ] = V_475 ;
V_19 -> V_65 -> V_254 ++ ;
if ( V_454 -> V_257 & V_166 )
V_19 -> V_65 -> V_255 ++ ;
}
int F_189 ( struct V_18 * V_19 ,
struct V_158 * V_454 , T_5 V_256 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_65 -> V_254 ; V_1 ++ ) {
if ( V_19 -> V_65 -> V_65 [ V_1 ] == V_454 ) {
V_19 -> V_65 -> V_455 [ V_1 ] = V_256 ;
return 0 ;
}
}
return - V_85 ;
}
int F_126 ( struct V_18 * V_19 ,
struct V_158 * V_454 , T_5 * V_256 )
{
int V_1 ;
if ( F_59 ( V_454 -> V_17 , V_69 ) &&
! ( V_454 -> V_257 & V_161 ) )
return F_190 ( V_19 , V_454 , V_256 ) ;
for ( V_1 = 0 ; V_1 < V_19 -> V_65 -> V_254 ; V_1 ++ ) {
if ( V_19 -> V_65 -> V_65 [ V_1 ] == V_454 ) {
* V_256 = V_19 -> V_65 -> V_455 [ V_1 ] ;
return 0 ;
}
}
return - V_85 ;
}
int F_191 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_477 * V_259 = V_206 ;
struct V_158 * V_454 ;
int V_478 = 0 ;
int V_479 = 0 ;
int V_22 = 0 , V_1 ;
int V_217 ;
struct V_472 * V_473 ;
struct V_480 T_4 * V_481 ;
T_5 T_4 * V_482 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_454 = F_192 ( V_17 , V_259 -> V_483 ) ;
if ( ! V_454 ) {
V_22 = - V_238 ;
goto V_484;
}
if ( F_187 ( V_454 , V_189 ) ||
F_187 ( V_454 , V_465 ) ) {
F_87 (prop_enum, &property->enum_list, head)
V_478 ++ ;
}
V_479 = V_454 -> V_453 ;
strncpy ( V_259 -> V_11 , V_454 -> V_11 , V_459 ) ;
V_259 -> V_11 [ V_459 - 1 ] = 0 ;
V_259 -> V_257 = V_454 -> V_257 ;
if ( ( V_259 -> V_485 >= V_479 ) && V_479 ) {
V_482 = ( T_5 T_4 * ) ( unsigned long ) V_259 -> V_482 ;
for ( V_1 = 0 ; V_1 < V_479 ; V_1 ++ ) {
if ( F_130 ( V_482 + V_1 , & V_454 -> V_455 [ V_1 ] , sizeof( T_5 ) ) ) {
V_22 = - V_225 ;
goto V_484;
}
}
}
V_259 -> V_485 = V_479 ;
if ( F_187 ( V_454 , V_189 ) ||
F_187 ( V_454 , V_465 ) ) {
if ( ( V_259 -> V_486 >= V_478 ) && V_478 ) {
V_217 = 0 ;
V_481 = (struct V_480 T_4 * ) ( unsigned long ) V_259 -> V_487 ;
F_87 (prop_enum, &property->enum_list, head) {
if ( F_130 ( & V_481 [ V_217 ] . V_471 , & V_473 -> V_471 , sizeof( T_5 ) ) ) {
V_22 = - V_225 ;
goto V_484;
}
if ( F_130 ( & V_481 [ V_217 ] . V_11 ,
& V_473 -> V_11 , V_459 ) ) {
V_22 = - V_225 ;
goto V_484;
}
V_217 ++ ;
}
}
V_259 -> V_486 = V_478 ;
}
if ( F_187 ( V_454 , V_160 ) )
V_259 -> V_486 = 0 ;
V_484:
F_51 ( V_17 ) ;
return V_22 ;
}
struct V_488 *
F_193 ( struct V_16 * V_17 , T_8 V_489 ,
const void * V_206 )
{
struct V_488 * V_490 ;
int V_22 ;
if ( ! V_489 || V_489 > V_491 - sizeof( struct V_488 ) )
return F_170 ( - V_85 ) ;
V_490 = F_180 ( sizeof( struct V_488 ) + V_489 , V_26 ) ;
if ( ! V_490 )
return F_170 ( - V_64 ) ;
F_25 ( & V_490 -> V_492 ) ;
V_490 -> V_489 = V_489 ;
V_490 -> V_17 = V_17 ;
if ( V_206 )
memcpy ( V_490 -> V_206 , V_206 , V_489 ) ;
F_11 ( & V_17 -> V_23 . V_493 ) ;
V_22 = F_14 ( V_17 , & V_490 -> V_39 , V_31 ) ;
if ( V_22 ) {
F_62 ( V_490 ) ;
F_13 ( & V_17 -> V_23 . V_493 ) ;
return F_170 ( - V_85 ) ;
}
F_24 ( & V_490 -> V_37 ) ;
F_57 ( & V_490 -> V_494 ,
& V_17 -> V_23 . V_495 ) ;
F_13 ( & V_17 -> V_23 . V_493 ) ;
return V_490 ;
}
static void F_194 ( struct V_44 * V_44 )
{
struct V_488 * V_490 =
F_29 ( V_44 , struct V_488 , V_37 ) ;
F_22 ( ! F_195 ( & V_490 -> V_17 -> V_23 . V_493 ) ) ;
F_42 ( & V_490 -> V_494 ) ;
F_42 ( & V_490 -> V_492 ) ;
F_17 ( V_490 -> V_17 , & V_490 -> V_39 ) ;
F_62 ( V_490 ) ;
}
void F_196 ( struct V_488 * V_490 )
{
struct V_16 * V_17 ;
if ( ! V_490 )
return;
V_17 = V_490 -> V_17 ;
F_35 ( L_101 , V_490 , V_490 -> V_39 . V_27 , F_36 ( & V_490 -> V_37 . V_37 ) ) ;
if ( F_197 ( & V_490 -> V_37 , F_194 ,
& V_17 -> V_23 . V_493 ) )
F_13 ( & V_17 -> V_23 . V_493 ) ;
else
F_198 ( & V_17 -> V_23 . V_493 ) ;
}
static void F_199 ( struct V_488 * V_490 )
{
if ( ! V_490 )
return;
F_35 ( L_101 , V_490 , V_490 -> V_39 . V_27 , F_36 ( & V_490 -> V_37 . V_37 ) ) ;
F_37 ( & V_490 -> V_37 , F_194 ) ;
}
void F_200 ( struct V_16 * V_17 ,
struct V_207 * V_208 )
{
struct V_488 * V_490 , * V_496 ;
F_11 ( & V_17 -> V_23 . V_493 ) ;
F_79 (blob, bt, &file_priv->blobs, head_file) {
F_172 ( & V_490 -> V_492 ) ;
F_199 ( V_490 ) ;
}
F_13 ( & V_17 -> V_23 . V_493 ) ;
}
struct V_488 * F_201 ( struct V_488 * V_490 )
{
F_35 ( L_101 , V_490 , V_490 -> V_39 . V_27 , F_36 ( & V_490 -> V_37 . V_37 ) ) ;
F_39 ( & V_490 -> V_37 ) ;
return V_490 ;
}
static struct V_488 * F_202 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_18 * V_19 = NULL ;
struct V_488 * V_490 ;
F_22 ( ! F_195 ( & V_17 -> V_23 . V_493 ) ) ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_19 = F_20 ( & V_17 -> V_23 . V_25 , V_27 ) ;
if ( ! V_19 || ( V_19 -> type != V_31 ) || ( V_19 -> V_27 != V_27 ) )
V_490 = NULL ;
else
V_490 = F_203 ( V_19 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_490 ;
}
struct V_488 * F_204 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_488 * V_490 ;
F_11 ( & V_17 -> V_23 . V_493 ) ;
V_490 = F_202 ( V_17 , V_27 ) ;
if ( V_490 ) {
if ( ! F_33 ( & V_490 -> V_37 ) )
V_490 = NULL ;
}
F_13 ( & V_17 -> V_23 . V_493 ) ;
return V_490 ;
}
static int F_205 ( struct V_16 * V_17 ,
struct V_488 * * V_497 ,
T_8 V_489 ,
const void * V_206 ,
struct V_18 * V_498 ,
struct V_158 * V_499 )
{
struct V_488 * V_500 = NULL ;
struct V_488 * V_501 = NULL ;
int V_22 ;
F_22 ( V_497 == NULL ) ;
V_501 = * V_497 ;
if ( V_489 && V_206 ) {
V_500 = F_193 ( V_17 , V_489 , V_206 ) ;
if ( F_156 ( V_500 ) )
return F_157 ( V_500 ) ;
}
if ( V_498 ) {
V_22 = F_189 ( V_498 ,
V_499 ,
V_500 ?
V_500 -> V_39 . V_27 : 0 ) ;
if ( V_22 != 0 )
goto V_502;
}
F_196 ( V_501 ) ;
* V_497 = V_500 ;
return 0 ;
V_502:
F_196 ( V_500 ) ;
return V_22 ;
}
int F_206 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_503 * V_259 = V_206 ;
struct V_488 * V_490 ;
int V_22 = 0 ;
void T_4 * V_504 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
F_45 ( V_17 ) ;
F_11 ( & V_17 -> V_23 . V_493 ) ;
V_490 = F_202 ( V_17 , V_259 -> V_505 ) ;
if ( ! V_490 ) {
V_22 = - V_238 ;
goto V_484;
}
if ( V_259 -> V_489 == V_490 -> V_489 ) {
V_504 = ( void T_4 * ) ( unsigned long ) V_259 -> V_206 ;
if ( F_130 ( V_504 , V_490 -> V_206 , V_490 -> V_489 ) ) {
V_22 = - V_225 ;
goto V_484;
}
}
V_259 -> V_489 = V_490 -> V_489 ;
V_484:
F_13 ( & V_17 -> V_23 . V_493 ) ;
F_51 ( V_17 ) ;
return V_22 ;
}
int F_207 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_506 * V_259 = V_206 ;
struct V_488 * V_490 ;
void T_4 * V_504 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
V_490 = F_193 ( V_17 , V_259 -> V_489 , NULL ) ;
if ( F_156 ( V_490 ) )
return F_157 ( V_490 ) ;
V_504 = ( void T_4 * ) ( unsigned long ) V_259 -> V_206 ;
if ( F_178 ( V_490 -> V_206 , V_504 , V_259 -> V_489 ) ) {
V_22 = - V_225 ;
goto V_507;
}
F_11 ( & V_17 -> V_23 . V_493 ) ;
V_259 -> V_505 = V_490 -> V_39 . V_27 ;
F_57 ( & V_490 -> V_492 , & V_208 -> V_508 ) ;
F_13 ( & V_17 -> V_23 . V_493 ) ;
return 0 ;
V_507:
F_196 ( V_490 ) ;
return V_22 ;
}
int F_208 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_509 * V_259 = V_206 ;
struct V_488 * V_490 = NULL , * V_496 ;
bool V_431 = false ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
F_11 ( & V_17 -> V_23 . V_493 ) ;
V_490 = F_202 ( V_17 , V_259 -> V_505 ) ;
if ( ! V_490 ) {
V_22 = - V_238 ;
goto V_510;
}
F_87 (bt, &file_priv->blobs, head_file) {
if ( V_496 == V_490 ) {
V_431 = true ;
break;
}
}
if ( ! V_431 ) {
V_22 = - V_511 ;
goto V_510;
}
F_172 ( & V_490 -> V_492 ) ;
F_199 ( V_490 ) ;
F_13 ( & V_17 -> V_23 . V_493 ) ;
return 0 ;
V_510:
F_13 ( & V_17 -> V_23 . V_493 ) ;
return V_22 ;
}
int F_209 ( struct V_76 * V_77 ,
const char * V_512 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
int V_22 ;
V_22 = F_205 ( V_17 ,
& V_77 -> V_513 ,
strlen ( V_512 ) + 1 ,
V_512 ,
& V_77 -> V_39 ,
V_17 -> V_23 . V_163 ) ;
return V_22 ;
}
int F_210 ( struct V_76 * V_77 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
char V_514 [ 256 ] ;
int V_22 ;
if ( ! V_77 -> V_515 ) {
V_22 = F_205 ( V_17 ,
& V_77 -> V_516 ,
0 ,
NULL ,
& V_77 -> V_39 ,
V_17 -> V_23 . V_164 ) ;
return V_22 ;
}
snprintf ( V_514 , 256 , L_102 ,
V_77 -> V_125 -> V_27 , V_77 -> V_517 ,
V_77 -> V_518 , V_77 -> V_519 ,
V_77 -> V_520 , V_77 -> V_521 ,
V_77 -> V_522 , V_77 -> V_523 ) ;
V_22 = F_205 ( V_17 ,
& V_77 -> V_516 ,
strlen ( V_514 ) + 1 ,
V_514 ,
& V_77 -> V_39 ,
V_17 -> V_23 . V_164 ) ;
return V_22 ;
}
int F_211 ( struct V_76 * V_77 ,
const struct V_524 * V_524 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
T_8 V_525 = 0 ;
int V_22 ;
if ( V_77 -> V_526 )
return 0 ;
if ( V_524 )
V_525 = V_527 * ( 1 + V_524 -> V_528 ) ;
V_22 = F_205 ( V_17 ,
& V_77 -> V_115 ,
V_525 ,
V_524 ,
& V_77 -> V_39 ,
V_17 -> V_23 . V_120 ) ;
return V_22 ;
}
bool F_212 ( struct V_158 * V_454 ,
T_5 V_471 , struct V_18 * * V_529 )
{
int V_1 ;
if ( V_454 -> V_257 & V_161 )
return false ;
* V_529 = NULL ;
if ( F_187 ( V_454 , V_468 ) ) {
if ( V_471 < V_454 -> V_455 [ 0 ] || V_471 > V_454 -> V_455 [ 1 ] )
return false ;
return true ;
} else if ( F_187 ( V_454 , V_469 ) ) {
T_7 V_530 = F_213 ( V_471 ) ;
if ( V_530 < F_213 ( V_454 -> V_455 [ 0 ] ) ||
V_530 > F_213 ( V_454 -> V_455 [ 1 ] ) )
return false ;
return true ;
} else if ( F_187 ( V_454 , V_465 ) ) {
T_5 V_531 = 0 ;
for ( V_1 = 0 ; V_1 < V_454 -> V_453 ; V_1 ++ )
V_531 |= ( 1ULL << V_454 -> V_455 [ V_1 ] ) ;
return ! ( V_471 & ~ V_531 ) ;
} else if ( F_187 ( V_454 , V_160 ) ) {
struct V_488 * V_490 ;
if ( V_471 == 0 )
return true ;
V_490 = F_204 ( V_454 -> V_17 , V_471 ) ;
if ( V_490 ) {
* V_529 = & V_490 -> V_39 ;
return true ;
} else {
return false ;
}
} else if ( F_187 ( V_454 , V_470 ) ) {
if ( V_471 == 0 )
return true ;
if ( V_454 -> V_455 [ 0 ] == V_30 ) {
struct V_32 * V_33 ;
V_33 = F_32 ( V_454 -> V_17 , V_471 ) ;
if ( V_33 ) {
* V_529 = & V_33 -> V_39 ;
return true ;
} else {
return false ;
}
} else {
return F_19 ( V_454 -> V_17 , V_471 , V_454 -> V_455 [ 0 ] ) != NULL ;
}
}
for ( V_1 = 0 ; V_1 < V_454 -> V_453 ; V_1 ++ )
if ( V_454 -> V_455 [ V_1 ] == V_471 )
return true ;
return false ;
}
void F_214 ( struct V_158 * V_454 ,
struct V_18 * V_529 )
{
if ( ! V_529 )
return;
if ( F_187 ( V_454 , V_470 ) ) {
if ( V_454 -> V_455 [ 0 ] == V_30 )
F_34 ( F_31 ( V_529 ) ) ;
} else if ( F_187 ( V_454 , V_160 ) )
F_196 ( F_203 ( V_529 ) ) ;
}
int F_215 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_532 * V_533 = V_206 ;
struct V_534 V_535 = {
. V_471 = V_533 -> V_471 ,
. V_483 = V_533 -> V_483 ,
. V_536 = V_533 -> V_108 ,
. V_20 = V_106
} ;
return F_216 ( V_17 , & V_535 , V_208 ) ;
}
static int F_217 ( struct V_18 * V_19 ,
struct V_158 * V_454 ,
T_5 V_471 )
{
int V_22 = - V_85 ;
struct V_76 * V_77 = F_218 ( V_19 ) ;
if ( V_454 == V_77 -> V_17 -> V_23 . V_121 ) {
V_22 = (* V_77 -> V_35 -> V_537 )( V_77 , ( int ) V_471 ) ;
} else if ( V_77 -> V_35 -> V_538 )
V_22 = V_77 -> V_35 -> V_538 ( V_77 , V_454 , V_471 ) ;
if ( ! V_22 )
F_189 ( & V_77 -> V_39 , V_454 , V_471 ) ;
return V_22 ;
}
static int F_219 ( struct V_18 * V_19 ,
struct V_158 * V_454 ,
T_5 V_471 )
{
int V_22 = - V_85 ;
struct V_46 * V_47 = F_220 ( V_19 ) ;
if ( V_47 -> V_35 -> V_538 )
V_22 = V_47 -> V_35 -> V_538 ( V_47 , V_454 , V_471 ) ;
if ( ! V_22 )
F_189 ( V_19 , V_454 , V_471 ) ;
return V_22 ;
}
int F_221 ( struct V_48 * V_49 ,
struct V_158 * V_454 ,
T_5 V_471 )
{
int V_22 = - V_85 ;
struct V_18 * V_19 = & V_49 -> V_39 ;
if ( V_49 -> V_35 -> V_538 )
V_22 = V_49 -> V_35 -> V_538 ( V_49 , V_454 , V_471 ) ;
if ( ! V_22 )
F_189 ( V_19 , V_454 , V_471 ) ;
return V_22 ;
}
int F_222 ( struct V_16 * V_17 , void * V_206 ,
struct V_207 * V_208 )
{
struct V_539 * V_540 = V_206 ;
struct V_18 * V_19 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_19 = F_21 ( V_17 , V_540 -> V_536 , V_540 -> V_20 ) ;
if ( ! V_19 ) {
V_22 = - V_238 ;
goto V_40;
}
if ( ! V_19 -> V_65 ) {
V_22 = - V_85 ;
goto V_40;
}
V_22 = F_125 ( V_19 , V_208 -> V_249 ,
( T_1 T_4 * ) ( unsigned long ) ( V_540 -> V_278 ) ,
( T_5 T_4 * ) ( unsigned long ) ( V_540 -> V_279 ) ,
& V_540 -> V_280 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_216 ( struct V_16 * V_17 , void * V_206 ,
struct V_207 * V_208 )
{
struct V_534 * V_540 = V_206 ;
struct V_18 * V_541 ;
struct V_18 * V_542 ;
struct V_158 * V_454 ;
int V_1 , V_22 = - V_85 ;
struct V_18 * V_529 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_541 = F_21 ( V_17 , V_540 -> V_536 , V_540 -> V_20 ) ;
if ( ! V_541 ) {
V_22 = - V_238 ;
goto V_40;
}
if ( ! V_541 -> V_65 )
goto V_40;
for ( V_1 = 0 ; V_1 < V_541 -> V_65 -> V_254 ; V_1 ++ )
if ( V_541 -> V_65 -> V_65 [ V_1 ] -> V_39 . V_27 == V_540 -> V_483 )
break;
if ( V_1 == V_541 -> V_65 -> V_254 )
goto V_40;
V_542 = F_21 ( V_17 , V_540 -> V_483 ,
V_457 ) ;
if ( ! V_542 ) {
V_22 = - V_238 ;
goto V_40;
}
V_454 = F_223 ( V_542 ) ;
if ( ! F_212 ( V_454 , V_540 -> V_471 , & V_529 ) )
goto V_40;
switch ( V_541 -> type ) {
case V_106 :
V_22 = F_217 ( V_541 , V_454 ,
V_540 -> V_471 ) ;
break;
case V_62 :
V_22 = F_219 ( V_541 , V_454 , V_540 -> V_471 ) ;
break;
case V_138 :
V_22 = F_221 ( F_224 ( V_541 ) ,
V_454 , V_540 -> V_471 ) ;
break;
}
F_214 ( V_454 , V_529 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_225 ( struct V_76 * V_77 ,
struct V_127 * V_128 )
{
int V_1 ;
if ( F_22 ( V_77 -> V_128 ) )
return - V_85 ;
for ( V_1 = 0 ; V_1 < V_266 ; V_1 ++ ) {
if ( V_77 -> V_267 [ V_1 ] == 0 ) {
V_77 -> V_267 [ V_1 ] = V_128 -> V_39 . V_27 ;
return 0 ;
}
}
return - V_64 ;
}
int F_226 ( struct V_46 * V_47 ,
int V_239 )
{
V_47 -> V_239 = V_239 ;
V_47 -> V_72 = F_177 ( V_239 , sizeof( V_543 ) * 3 ,
V_26 ) ;
if ( ! V_47 -> V_72 ) {
V_47 -> V_239 = 0 ;
return - V_64 ;
}
return 0 ;
}
int F_227 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_544 * V_545 = V_206 ;
struct V_46 * V_47 ;
void * V_546 , * V_547 , * V_548 ;
int V_525 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_47 = F_118 ( V_17 , V_545 -> V_219 ) ;
if ( ! V_47 ) {
V_22 = - V_238 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_549 == NULL ) {
V_22 = - V_450 ;
goto V_40;
}
if ( V_545 -> V_239 != V_47 -> V_239 ) {
V_22 = - V_85 ;
goto V_40;
}
V_525 = V_545 -> V_239 * ( sizeof( V_543 ) ) ;
V_546 = V_47 -> V_72 ;
if ( F_178 ( V_546 , ( void T_4 * ) ( unsigned long ) V_545 -> V_550 , V_525 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_547 = V_546 + V_525 ;
if ( F_178 ( V_547 , ( void T_4 * ) ( unsigned long ) V_545 -> V_551 , V_525 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_548 = V_547 + V_525 ;
if ( F_178 ( V_548 , ( void T_4 * ) ( unsigned long ) V_545 -> V_552 , V_525 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_47 -> V_35 -> V_549 ( V_47 , V_546 , V_547 , V_548 , 0 , V_47 -> V_239 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_228 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_544 * V_545 = V_206 ;
struct V_46 * V_47 ;
void * V_546 , * V_547 , * V_548 ;
int V_525 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_221 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_47 = F_118 ( V_17 , V_545 -> V_219 ) ;
if ( ! V_47 ) {
V_22 = - V_238 ;
goto V_40;
}
if ( V_545 -> V_239 != V_47 -> V_239 ) {
V_22 = - V_85 ;
goto V_40;
}
V_525 = V_545 -> V_239 * ( sizeof( V_543 ) ) ;
V_546 = V_47 -> V_72 ;
if ( F_130 ( ( void T_4 * ) ( unsigned long ) V_545 -> V_550 , V_546 , V_525 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_547 = V_546 + V_525 ;
if ( F_130 ( ( void T_4 * ) ( unsigned long ) V_545 -> V_551 , V_547 , V_525 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_548 = V_547 + V_525 ;
if ( F_130 ( ( void T_4 * ) ( unsigned long ) V_545 -> V_552 , V_548 , V_525 ) ) {
V_22 = - V_225 ;
goto V_40;
}
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_229 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_553 * V_554 = V_206 ;
struct V_46 * V_47 ;
struct V_32 * V_33 = NULL ;
struct V_555 * V_556 = NULL ;
unsigned long V_257 ;
int V_22 = - V_85 ;
if ( V_554 -> V_257 & ~ V_557 ||
V_554 -> V_558 != 0 )
return - V_85 ;
if ( ( V_554 -> V_257 & V_559 ) && ! V_17 -> V_23 . V_560 )
return - V_85 ;
V_47 = F_118 ( V_17 , V_554 -> V_219 ) ;
if ( ! V_47 )
return - V_238 ;
F_119 ( V_47 , V_47 -> V_52 ) ;
if ( V_47 -> V_52 -> V_33 == NULL ) {
V_22 = - V_561 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_554 == NULL )
goto V_40;
V_33 = F_32 ( V_17 , V_554 -> V_218 ) ;
if ( ! V_33 ) {
V_22 = - V_238 ;
goto V_40;
}
if ( V_47 -> V_73 ) {
const struct V_562 * V_73 = V_47 -> V_52 -> V_73 ;
V_22 = F_139 ( V_73 -> V_241 , V_73 -> V_243 ,
V_73 -> V_298 , V_73 -> V_299 , V_33 ) ;
} else {
V_22 = F_147 ( V_47 , V_47 -> V_240 , V_47 -> V_242 , & V_47 -> V_79 , V_33 ) ;
}
if ( V_22 )
goto V_40;
if ( V_47 -> V_52 -> V_33 -> V_309 != V_33 -> V_309 ) {
F_73 ( L_103 ) ;
V_22 = - V_85 ;
goto V_40;
}
if ( V_554 -> V_257 & V_563 ) {
V_22 = - V_64 ;
F_230 ( & V_17 -> V_564 , V_257 ) ;
if ( V_208 -> V_565 < sizeof( V_556 -> V_566 ) ) {
F_231 ( & V_17 -> V_564 , V_257 ) ;
goto V_40;
}
V_208 -> V_565 -= sizeof( V_556 -> V_566 ) ;
F_231 ( & V_17 -> V_564 , V_257 ) ;
V_556 = F_180 ( sizeof( * V_556 ) , V_26 ) ;
if ( V_556 == NULL ) {
F_230 ( & V_17 -> V_564 , V_257 ) ;
V_208 -> V_565 += sizeof( V_556 -> V_566 ) ;
F_231 ( & V_17 -> V_564 , V_257 ) ;
goto V_40;
}
V_556 -> V_566 . V_39 . type = V_567 ;
V_556 -> V_566 . V_39 . V_489 = sizeof( V_556 -> V_566 ) ;
V_556 -> V_566 . V_568 = V_554 -> V_568 ;
V_556 -> V_39 . V_566 = & V_556 -> V_566 . V_39 ;
V_556 -> V_39 . V_208 = V_208 ;
V_556 -> V_39 . V_45 =
( void ( * ) ( struct V_569 * ) ) F_62 ;
}
V_47 -> V_52 -> V_156 = V_47 -> V_52 -> V_33 ;
V_22 = V_47 -> V_35 -> V_554 ( V_47 , V_33 , V_556 , V_554 -> V_257 ) ;
if ( V_22 ) {
if ( V_554 -> V_257 & V_563 ) {
F_230 ( & V_17 -> V_564 , V_257 ) ;
V_208 -> V_565 += sizeof( V_556 -> V_566 ) ;
F_231 ( & V_17 -> V_564 , V_257 ) ;
F_62 ( V_556 ) ;
}
V_47 -> V_52 -> V_156 = NULL ;
} else {
V_47 -> V_52 -> V_33 = V_33 ;
V_33 = NULL ;
}
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
if ( V_47 -> V_52 -> V_156 )
F_34 ( V_47 -> V_52 -> V_156 ) ;
V_47 -> V_52 -> V_156 = NULL ;
F_121 ( V_47 ) ;
return V_22 ;
}
void F_232 ( struct V_16 * V_17 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_127 * V_128 ;
struct V_76 * V_77 ;
F_49 (plane, dev)
if ( V_49 -> V_35 -> V_570 )
V_49 -> V_35 -> V_570 ( V_49 ) ;
F_46 (crtc, dev)
if ( V_47 -> V_35 -> V_570 )
V_47 -> V_35 -> V_570 ( V_47 ) ;
F_116 (encoder, dev)
if ( V_128 -> V_35 -> V_570 )
V_128 -> V_35 -> V_570 ( V_128 ) ;
F_11 ( & V_17 -> V_23 . V_61 ) ;
F_115 (connector, dev)
if ( V_77 -> V_35 -> V_570 )
V_77 -> V_35 -> V_570 ( V_77 ) ;
F_13 ( & V_17 -> V_23 . V_61 ) ;
}
int F_233 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_571 * args = V_206 ;
T_3 V_421 , V_572 , V_525 ;
if ( ! V_17 -> V_573 -> V_574 )
return - V_450 ;
if ( ! args -> V_302 || ! args -> V_303 || ! args -> V_353 )
return - V_85 ;
V_421 = F_234 ( args -> V_353 , 8 ) ;
if ( ! V_421 || V_421 > 0xffffffffU / args -> V_302 )
return - V_85 ;
V_572 = V_421 * args -> V_302 ;
if ( args -> V_303 > 0xffffffffU / V_572 )
return - V_85 ;
V_525 = args -> V_303 * V_572 ;
if ( F_235 ( V_525 ) == 0 )
return - V_85 ;
args -> V_339 = 0 ;
args -> V_365 = 0 ;
args -> V_525 = 0 ;
return V_17 -> V_573 -> V_574 ( V_208 , V_17 , args ) ;
}
int F_236 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_575 * args = V_206 ;
if ( ! V_17 -> V_573 -> V_576 )
return - V_450 ;
return V_17 -> V_573 -> V_576 ( V_208 , V_17 , args -> V_339 , & args -> V_577 ) ;
}
int F_237 ( struct V_16 * V_17 ,
void * V_206 , struct V_207 * V_208 )
{
struct V_578 * args = V_206 ;
if ( ! V_17 -> V_573 -> V_579 )
return - V_450 ;
return V_17 -> V_573 -> V_579 ( V_208 , V_17 , args -> V_339 ) ;
}
void F_238 ( T_1 V_13 , unsigned int * V_354 ,
int * V_353 )
{
switch ( V_13 ) {
case V_356 :
case V_366 :
case V_367 :
* V_354 = 8 ;
* V_353 = 8 ;
break;
case V_357 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
* V_354 = 15 ;
* V_353 = 16 ;
break;
case V_358 :
case V_383 :
* V_354 = 16 ;
* V_353 = 16 ;
break;
case V_359 :
case V_384 :
* V_354 = 24 ;
* V_353 = 24 ;
break;
case V_360 :
case V_385 :
case V_386 :
case V_387 :
* V_354 = 24 ;
* V_353 = 32 ;
break;
case V_361 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
* V_354 = 30 ;
* V_353 = 32 ;
break;
case V_336 :
case V_388 :
case V_389 :
case V_390 :
* V_354 = 32 ;
* V_353 = 32 ;
break;
default:
F_73 ( L_104 ,
F_9 ( V_13 ) ) ;
* V_354 = 0 ;
* V_353 = 0 ;
break;
}
}
int F_168 ( T_1 V_13 )
{
switch ( V_13 ) {
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
return 3 ;
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
return 2 ;
default:
return 1 ;
}
}
int F_169 ( T_1 V_13 , int V_49 )
{
unsigned int V_354 ;
int V_353 ;
if ( V_49 >= F_168 ( V_13 ) )
return 0 ;
switch ( V_13 ) {
case V_398 :
case V_399 :
case V_400 :
case V_401 :
return 2 ;
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
return V_49 ? 2 : 1 ;
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
return 1 ;
default:
F_238 ( V_13 , & V_354 , & V_353 ) ;
return V_353 >> 3 ;
}
}
int F_166 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_411 :
case V_412 :
case V_409 :
case V_410 :
return 4 ;
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_415 :
case V_416 :
case V_413 :
case V_414 :
return 2 ;
default:
return 1 ;
}
}
int F_167 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_409 :
case V_410 :
return 4 ;
case V_413 :
case V_414 :
case V_403 :
case V_404 :
return 2 ;
default:
return 1 ;
}
}
unsigned int F_239 ( unsigned int V_321 ,
unsigned int V_580 )
{
if ( V_321 & ~ V_580 ) {
V_321 ^= F_148 ( V_581 ) | F_148 ( V_582 ) ;
V_321 = ( V_321 & V_583 ) |
F_148 ( ( F_240 ( V_321 & V_584 ) + 1 ) % 4 ) ;
}
return V_321 ;
}
void F_241 ( struct V_16 * V_17 )
{
F_242 ( & V_17 -> V_23 . V_61 ) ;
F_54 ( & V_17 -> V_23 . V_276 ) ;
F_242 ( & V_17 -> V_23 . V_24 ) ;
F_242 ( & V_17 -> V_23 . V_36 ) ;
F_242 ( & V_17 -> V_23 . V_493 ) ;
F_25 ( & V_17 -> V_23 . V_43 ) ;
F_25 ( & V_17 -> V_23 . V_66 ) ;
F_25 ( & V_17 -> V_23 . V_117 ) ;
F_25 ( & V_17 -> V_23 . V_133 ) ;
F_25 ( & V_17 -> V_23 . V_460 ) ;
F_25 ( & V_17 -> V_23 . V_495 ) ;
F_25 ( & V_17 -> V_23 . V_140 ) ;
F_243 ( & V_17 -> V_23 . V_25 ) ;
F_243 ( & V_17 -> V_23 . V_585 ) ;
F_3 ( & V_17 -> V_23 . V_105 ) ;
F_45 ( V_17 ) ;
F_98 ( V_17 ) ;
F_51 ( V_17 ) ;
V_17 -> V_23 . V_41 = 0 ;
V_17 -> V_23 . V_118 = 0 ;
V_17 -> V_23 . V_67 = 0 ;
V_17 -> V_23 . V_134 = 0 ;
V_17 -> V_23 . V_143 = 0 ;
V_17 -> V_23 . V_141 = 0 ;
}
void F_244 ( struct V_16 * V_17 )
{
struct V_76 * V_77 , * V_586 ;
struct V_46 * V_47 , * V_587 ;
struct V_127 * V_128 , * V_588 ;
struct V_32 * V_33 , * V_589 ;
struct V_158 * V_454 , * V_474 ;
struct V_488 * V_490 , * V_496 ;
struct V_48 * V_49 , * V_590 ;
F_79 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_128 -> V_35 -> V_45 ( V_128 ) ;
}
F_79 (connector, ot,
&dev->mode_config.connector_list, head) {
V_77 -> V_35 -> V_45 ( V_77 ) ;
}
F_79 (property, pt, &dev->mode_config.property_list,
head) {
F_182 ( V_17 , V_454 ) ;
}
F_79 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_196 ( V_490 ) ;
}
F_22 ( ! F_44 ( & V_17 -> V_23 . V_43 ) ) ;
F_79 (fb, fbt, &dev->mode_config.fb_list, head) {
F_28 ( & V_33 -> V_37 ) ;
}
F_79 (plane, plt, &dev->mode_config.plane_list,
head) {
V_49 -> V_35 -> V_45 ( V_49 ) ;
}
F_79 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_47 -> V_35 -> V_45 ( V_47 ) ;
}
F_5 ( & V_17 -> V_23 . V_105 ) ;
F_245 ( & V_17 -> V_23 . V_585 ) ;
F_245 ( & V_17 -> V_23 . V_25 ) ;
F_63 ( & V_17 -> V_23 . V_276 ) ;
}
struct V_158 * F_246 ( struct V_16 * V_17 ,
unsigned int V_580 )
{
static const struct V_461 V_462 [] = {
{ V_591 , L_105 } ,
{ V_322 , L_106 } ,
{ V_592 , L_107 } ,
{ V_323 , L_108 } ,
{ V_581 , L_109 } ,
{ V_582 , L_110 } ,
} ;
return F_183 ( V_17 , 0 , L_111 ,
V_462 , F_2 ( V_462 ) ,
V_580 ) ;
}
static void F_247 ( struct V_44 * V_44 )
{
struct V_593 * V_594 = F_29 ( V_44 , struct V_593 , V_37 ) ;
struct V_16 * V_17 = V_594 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_585 , V_594 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
F_62 ( V_594 ) ;
}
void F_78 ( struct V_16 * V_17 ,
struct V_593 * V_594 )
{
F_37 ( & V_594 -> V_37 , F_247 ) ;
}
struct V_593 * F_248 ( struct V_16 * V_17 ,
char V_595 [ 8 ] )
{
struct V_593 * V_594 ;
int V_27 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_249 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_594 -> V_596 , V_595 , 8 ) ) {
if ( ! F_33 ( & V_594 -> V_37 ) )
V_594 = NULL ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_594 ;
}
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return NULL ;
}
struct V_593 * F_250 ( struct V_16 * V_17 ,
char V_595 [ 8 ] )
{
struct V_593 * V_594 ;
int V_22 ;
V_594 = F_180 ( sizeof( * V_594 ) , V_26 ) ;
if ( ! V_594 )
return F_170 ( - V_64 ) ;
F_24 ( & V_594 -> V_37 ) ;
memcpy ( V_594 -> V_596 , V_595 , 8 ) ;
V_594 -> V_17 = V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_22 = F_12 ( & V_17 -> V_23 . V_585 , V_594 , 1 , 0 , V_26 ) ;
if ( V_22 >= 0 ) {
V_594 -> V_27 = V_22 ;
} else {
F_62 ( V_594 ) ;
V_594 = F_170 ( V_22 ) ;
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_594 ;
}
