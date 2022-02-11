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
F_17 ( V_17 , & V_33 -> V_39 ) ;
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
unsigned int F_89 ( struct V_127 * V_128 )
{
unsigned int V_75 = 0 ;
struct V_127 * V_54 ;
F_90 (tmp, encoder->dev) {
if ( V_54 == V_128 )
return V_75 ;
V_75 ++ ;
}
F_64 () ;
}
void F_91 ( struct V_127 * V_128 )
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
static unsigned int F_92 ( struct V_16 * V_17 )
{
unsigned int V_53 = 0 ;
struct V_48 * V_54 ;
F_49 (tmp, dev) {
V_53 ++ ;
}
return V_53 ;
}
int F_93 ( struct V_16 * V_17 , struct V_48 * V_49 ,
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
V_49 -> V_139 = F_94 ( V_136 , sizeof( T_1 ) ,
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
F_92 ( V_17 ) ) ;
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
int F_95 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_68 ,
const struct V_135 * V_35 ,
const T_1 * V_82 , unsigned int V_136 ,
bool V_154 )
{
enum V_137 type ;
type = V_154 ? V_59 : V_142 ;
return F_93 ( V_17 , V_49 , V_68 , V_35 ,
V_82 , V_136 , type , NULL ) ;
}
void F_96 ( struct V_48 * V_49 )
{
struct V_16 * V_17 = V_49 -> V_17 ;
F_45 ( V_17 ) ;
F_62 ( V_49 -> V_139 ) ;
F_17 ( V_17 , & V_49 -> V_39 ) ;
F_97 ( F_44 ( & V_49 -> V_42 ) ) ;
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
unsigned int F_98 ( struct V_48 * V_49 )
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
F_99 ( struct V_16 * V_17 , int V_155 )
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
static int F_100 ( struct V_16 * V_17 )
{
struct V_158 * V_159 ;
V_159 = F_101 ( V_17 , V_160 |
V_161 ,
L_23 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_120 = V_159 ;
V_159 = F_102 ( V_17 , 0 ,
L_24 , V_162 ,
F_2 ( V_162 ) ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_121 = V_159 ;
V_159 = F_101 ( V_17 ,
V_160 |
V_161 ,
L_25 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_163 = V_159 ;
V_159 = F_101 ( V_17 ,
V_160 |
V_161 ,
L_26 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_164 = V_159 ;
V_159 = F_102 ( V_17 , V_161 ,
L_27 , V_165 ,
F_2 ( V_165 ) ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_144 = V_159 ;
V_159 = F_103 ( V_17 , V_166 ,
L_28 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_150 = V_159 ;
V_159 = F_103 ( V_17 , V_166 ,
L_29 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_151 = V_159 ;
V_159 = F_103 ( V_17 , V_166 ,
L_30 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_152 = V_159 ;
V_159 = F_103 ( V_17 , V_166 ,
L_31 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_153 = V_159 ;
V_159 = F_104 ( V_17 , V_166 ,
L_32 , V_168 , V_169 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_146 = V_159 ;
V_159 = F_104 ( V_17 , V_166 ,
L_33 , V_168 , V_169 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_147 = V_159 ;
V_159 = F_103 ( V_17 , V_166 ,
L_34 , 0 , V_169 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_148 = V_159 ;
V_159 = F_103 ( V_17 , V_166 ,
L_35 , 0 , V_169 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_149 = V_159 ;
V_159 = F_105 ( V_17 , V_166 ,
L_36 , V_30 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_145 = V_159 ;
V_159 = F_105 ( V_17 , V_166 ,
L_37 , V_62 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_122 = V_159 ;
V_159 = F_106 ( V_17 , V_166 ,
L_38 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_70 = V_159 ;
V_159 = F_101 ( V_17 ,
V_166 | V_160 ,
L_39 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_71 = V_159 ;
V_159 = F_101 ( V_17 ,
V_160 ,
L_40 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_170 = V_159 ;
V_159 = F_103 ( V_17 ,
V_161 ,
L_41 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_171 = V_159 ;
V_159 = F_101 ( V_17 ,
V_160 ,
L_42 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_172 = V_159 ;
V_159 = F_101 ( V_17 ,
V_160 ,
L_43 , 0 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_173 = V_159 ;
V_159 = F_103 ( V_17 ,
V_161 ,
L_44 , 0 , V_167 ) ;
if ( ! V_159 )
return - V_64 ;
V_17 -> V_23 . V_174 = V_159 ;
return 0 ;
}
int F_107 ( struct V_16 * V_17 )
{
struct V_158 * V_175 ;
struct V_158 * V_176 ;
if ( V_17 -> V_23 . V_177 )
return 0 ;
V_175 =
F_102 ( V_17 , 0 ,
L_45 ,
V_178 ,
F_2 ( V_178 ) ) ;
V_17 -> V_23 . V_177 = V_175 ;
V_176 = F_102 ( V_17 , V_161 ,
L_46 ,
V_179 ,
F_2 ( V_179 ) ) ;
V_17 -> V_23 . V_180 = V_176 ;
return 0 ;
}
int F_108 ( struct V_16 * V_17 ,
unsigned int V_181 ,
const char * const V_114 [] )
{
struct V_158 * V_182 ;
struct V_158 * V_183 ;
unsigned int V_1 ;
if ( V_17 -> V_23 . V_184 )
return 0 ;
V_182 = F_102 ( V_17 , 0 ,
L_45 ,
V_185 ,
F_2 ( V_185 ) ) ;
if ( ! V_182 )
goto V_186;
V_17 -> V_23 . V_184 = V_182 ;
V_183 =
F_102 ( V_17 , V_161 ,
L_46 ,
V_187 ,
F_2 ( V_187 ) ) ;
if ( ! V_183 )
goto V_186;
V_17 -> V_23 . V_188 = V_183 ;
V_17 -> V_23 . V_189 =
F_103 ( V_17 , 0 , L_47 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_189 )
goto V_186;
V_17 -> V_23 . V_190 =
F_103 ( V_17 , 0 , L_48 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_190 )
goto V_186;
V_17 -> V_23 . V_191 =
F_103 ( V_17 , 0 , L_49 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_191 )
goto V_186;
V_17 -> V_23 . V_192 =
F_103 ( V_17 , 0 , L_50 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_192 )
goto V_186;
V_17 -> V_23 . V_193 =
F_101 ( V_17 , V_194 ,
L_51 , V_181 ) ;
if ( ! V_17 -> V_23 . V_193 )
goto V_186;
for ( V_1 = 0 ; V_1 < V_181 ; V_1 ++ )
F_109 ( V_17 -> V_23 . V_193 , V_1 ,
V_1 , V_114 [ V_1 ] ) ;
V_17 -> V_23 . V_195 =
F_103 ( V_17 , 0 , L_52 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_195 )
goto V_186;
V_17 -> V_23 . V_196 =
F_103 ( V_17 , 0 , L_53 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_196 )
goto V_186;
V_17 -> V_23 . V_197 =
F_103 ( V_17 , 0 , L_54 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_197 )
goto V_186;
V_17 -> V_23 . V_198 =
F_103 ( V_17 , 0 , L_55 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_198 )
goto V_186;
V_17 -> V_23 . V_199 =
F_103 ( V_17 , 0 , L_56 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_199 )
goto V_186;
V_17 -> V_23 . V_200 =
F_103 ( V_17 , 0 , L_57 , 0 , 100 ) ;
if ( ! V_17 -> V_23 . V_200 )
goto V_186;
return 0 ;
V_186:
return - V_64 ;
}
int F_110 ( struct V_16 * V_17 )
{
struct V_158 * V_201 ;
if ( V_17 -> V_23 . V_202 )
return 0 ;
V_201 =
F_102 ( V_17 , 0 , L_58 ,
V_203 ,
F_2 ( V_203 ) ) ;
V_17 -> V_23 . V_202 = V_201 ;
return 0 ;
}
int F_111 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_204 )
return 0 ;
V_17 -> V_23 . V_204 =
F_102 ( V_17 , 0 , L_59 ,
V_205 ,
F_2 ( V_205 ) ) ;
if ( V_17 -> V_23 . V_204 == NULL )
return - V_64 ;
return 0 ;
}
int F_112 ( struct V_16 * V_17 )
{
struct V_158 * V_206 ;
if ( V_17 -> V_23 . V_207 )
return 0 ;
V_206 =
F_102 ( V_17 , V_161 ,
L_60 ,
V_208 ,
F_2 ( V_208 ) ) ;
V_17 -> V_23 . V_207 = V_206 ;
return 0 ;
}
int F_113 ( struct V_16 * V_17 )
{
if ( V_17 -> V_23 . V_209 && V_17 -> V_23 . V_210 )
return 0 ;
V_17 -> V_23 . V_209 =
F_103 ( V_17 , V_161 , L_61 , 0 , 0xffffffff ) ;
V_17 -> V_23 . V_210 =
F_103 ( V_17 , V_161 , L_62 , 0 , 0xffffffff ) ;
if ( V_17 -> V_23 . V_209 == NULL ||
V_17 -> V_23 . V_210 == NULL )
return - V_64 ;
return 0 ;
}
int F_114 ( struct V_16 * V_17 , void * V_211 ,
struct V_212 * V_213 )
{
struct V_214 * V_215 = V_211 ;
struct V_216 * V_217 ;
struct V_32 * V_33 ;
struct V_76 * V_77 ;
struct V_46 * V_47 ;
struct V_127 * V_128 ;
int V_22 = 0 ;
int V_218 = 0 ;
int V_219 = 0 ;
int V_220 = 0 ;
int V_221 = 0 ;
int V_222 = 0 ;
T_1 T_4 * V_223 ;
T_1 T_4 * V_224 ;
T_1 T_4 * V_108 ;
T_1 T_4 * V_225 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
F_11 ( & V_213 -> V_227 ) ;
F_115 (lh, &file_priv->fbs)
V_220 ++ ;
if ( V_215 -> V_228 >= V_220 ) {
V_222 = 0 ;
V_223 = ( T_1 T_4 * ) ( unsigned long ) V_215 -> V_229 ;
F_87 (fb, &file_priv->fbs, filp_head) {
if ( F_116 ( V_33 -> V_39 . V_27 , V_223 + V_222 ) ) {
F_13 ( & V_213 -> V_227 ) ;
return - V_230 ;
}
V_222 ++ ;
}
}
V_215 -> V_228 = V_220 ;
F_13 ( & V_213 -> V_227 ) ;
F_11 ( & V_17 -> V_23 . V_61 ) ;
F_46 (crtc, dev)
V_219 ++ ;
F_117 (connector, dev)
V_218 ++ ;
F_90 (encoder, dev)
V_221 ++ ;
V_215 -> V_231 = V_17 -> V_23 . V_231 ;
V_215 -> V_232 = V_17 -> V_23 . V_232 ;
V_215 -> V_233 = V_17 -> V_23 . V_233 ;
V_215 -> V_234 = V_17 -> V_23 . V_234 ;
if ( V_215 -> V_235 >= V_219 ) {
V_222 = 0 ;
V_224 = ( T_1 T_4 * ) ( unsigned long ) V_215 -> V_236 ;
F_46 (crtc, dev) {
F_73 ( L_63 ,
V_47 -> V_39 . V_27 , V_47 -> V_11 ) ;
if ( F_116 ( V_47 -> V_39 . V_27 , V_224 + V_222 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_222 ++ ;
}
}
V_215 -> V_235 = V_219 ;
if ( V_215 -> V_237 >= V_221 ) {
V_222 = 0 ;
V_225 = ( T_1 T_4 * ) ( unsigned long ) V_215 -> V_238 ;
F_90 (encoder, dev) {
F_73 ( L_64 , V_128 -> V_39 . V_27 ,
V_128 -> V_11 ) ;
if ( F_116 ( V_128 -> V_39 . V_27 , V_225 +
V_222 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_222 ++ ;
}
}
V_215 -> V_237 = V_221 ;
if ( V_215 -> V_239 >= V_218 ) {
V_222 = 0 ;
V_108 = ( T_1 T_4 * ) ( unsigned long ) V_215 -> V_240 ;
F_117 (connector, dev) {
F_73 ( L_65 ,
V_77 -> V_39 . V_27 ,
V_77 -> V_11 ) ;
if ( F_116 ( V_77 -> V_39 . V_27 ,
V_108 + V_222 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_222 ++ ;
}
}
V_215 -> V_239 = V_218 ;
F_73 ( L_66 , V_215 -> V_235 ,
V_215 -> V_239 , V_215 -> V_237 ) ;
V_40:
F_13 ( & V_17 -> V_23 . V_61 ) ;
return V_22 ;
}
int F_118 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_241 * V_242 = V_211 ;
struct V_46 * V_47 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
V_47 = F_119 ( V_17 , V_242 -> V_224 ) ;
if ( ! V_47 )
return - V_243 ;
F_120 ( V_47 , V_47 -> V_52 ) ;
V_242 -> V_244 = V_47 -> V_244 ;
if ( V_47 -> V_52 -> V_33 )
V_242 -> V_223 = V_47 -> V_52 -> V_33 -> V_39 . V_27 ;
else
V_242 -> V_223 = 0 ;
if ( V_47 -> V_73 ) {
V_242 -> V_245 = V_47 -> V_52 -> V_73 -> V_246 >> 16 ;
V_242 -> V_247 = V_47 -> V_52 -> V_73 -> V_248 >> 16 ;
if ( V_47 -> V_73 -> V_249 ) {
F_121 ( & V_242 -> V_79 , & V_47 -> V_73 -> V_79 ) ;
V_242 -> V_250 = 1 ;
} else {
V_242 -> V_250 = 0 ;
}
} else {
V_242 -> V_245 = V_47 -> V_245 ;
V_242 -> V_247 = V_47 -> V_247 ;
if ( V_47 -> V_251 ) {
F_121 ( & V_242 -> V_79 , & V_47 -> V_79 ) ;
V_242 -> V_250 = 1 ;
} else {
V_242 -> V_250 = 0 ;
}
}
F_122 ( V_47 ) ;
return 0 ;
}
static bool F_123 ( const struct V_78 * V_79 ,
const struct V_212 * V_213 )
{
if ( ! V_213 -> V_252 && F_124 ( V_79 ) )
return false ;
return true ;
}
static struct V_127 * F_125 ( struct V_76 * V_77 )
{
if ( V_77 -> V_73 )
return V_77 -> V_73 -> V_253 ;
return V_77 -> V_128 ;
}
static int F_126 ( struct V_18 * V_19 , bool V_254 ,
T_1 T_4 * V_255 , T_5 T_4 * V_256 ,
T_1 * V_257 )
{
int V_258 ;
int V_1 , V_22 , V_222 ;
V_258 = V_19 -> V_65 -> V_259 ;
if ( ! V_254 )
V_258 -= V_19 -> V_65 -> V_260 ;
if ( ( * V_257 >= V_258 ) && V_258 ) {
for ( V_1 = 0 , V_222 = 0 ; V_222 < V_258 ; V_1 ++ ) {
struct V_158 * V_159 = V_19 -> V_65 -> V_65 [ V_1 ] ;
T_5 V_261 ;
if ( ( V_159 -> V_262 & V_166 ) && ! V_254 )
continue;
V_22 = F_127 ( V_19 , V_159 , & V_261 ) ;
if ( V_22 )
return V_22 ;
if ( F_116 ( V_159 -> V_39 . V_27 , V_255 + V_222 ) )
return - V_230 ;
if ( F_116 ( V_261 , V_256 + V_222 ) )
return - V_230 ;
V_222 ++ ;
}
}
* V_257 = V_258 ;
return 0 ;
}
int F_128 ( struct V_16 * V_17 , void * V_211 ,
struct V_212 * V_213 )
{
struct V_263 * V_264 = V_211 ;
struct V_76 * V_77 ;
struct V_127 * V_128 ;
struct V_78 * V_79 ;
int V_265 = 0 ;
int V_266 = 0 ;
int V_22 = 0 ;
int V_222 = 0 ;
int V_1 ;
struct V_267 V_268 ;
struct V_267 T_4 * V_269 ;
T_1 T_4 * V_270 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
memset ( & V_268 , 0 , sizeof( struct V_267 ) ) ;
F_73 ( L_67 , V_264 -> V_108 ) ;
F_11 ( & V_17 -> V_23 . V_61 ) ;
V_77 = F_129 ( V_17 , V_264 -> V_108 ) ;
if ( ! V_77 ) {
V_22 = - V_243 ;
goto V_107;
}
for ( V_1 = 0 ; V_1 < V_271 ; V_1 ++ )
if ( V_77 -> V_272 [ V_1 ] != 0 )
V_266 ++ ;
if ( V_264 -> V_273 == 0 ) {
V_77 -> V_35 -> V_274 ( V_77 ,
V_17 -> V_23 . V_233 ,
V_17 -> V_23 . V_231 ) ;
}
F_87 (mode, &connector->modes, head)
if ( F_123 ( V_79 , V_213 ) )
V_265 ++ ;
V_264 -> V_108 = V_77 -> V_39 . V_27 ;
V_264 -> V_104 = V_77 -> V_104 ;
V_264 -> V_110 = V_77 -> V_110 ;
V_264 -> V_275 = V_77 -> V_126 . V_276 ;
V_264 -> V_277 = V_77 -> V_126 . V_278 ;
V_264 -> V_279 = V_77 -> V_126 . V_8 ;
V_264 -> V_280 = V_77 -> V_5 ;
F_130 ( & V_17 -> V_23 . V_281 , NULL ) ;
V_128 = F_125 ( V_77 ) ;
if ( V_128 )
V_264 -> V_225 = V_128 -> V_39 . V_27 ;
else
V_264 -> V_225 = 0 ;
if ( ( V_264 -> V_273 >= V_265 ) && V_265 ) {
V_222 = 0 ;
V_269 = (struct V_267 T_4 * ) ( unsigned long ) V_264 -> V_282 ;
F_87 (mode, &connector->modes, head) {
if ( ! F_123 ( V_79 , V_213 ) )
continue;
F_121 ( & V_268 , V_79 ) ;
if ( F_131 ( V_269 + V_222 ,
& V_268 , sizeof( V_268 ) ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_222 ++ ;
}
}
V_264 -> V_273 = V_265 ;
V_22 = F_126 ( & V_77 -> V_39 , V_213 -> V_254 ,
( T_1 T_4 * ) ( unsigned long ) ( V_264 -> V_283 ) ,
( T_5 T_4 * ) ( unsigned long ) ( V_264 -> V_284 ) ,
& V_264 -> V_285 ) ;
if ( V_22 )
goto V_40;
if ( ( V_264 -> V_237 >= V_266 ) && V_266 ) {
V_222 = 0 ;
V_270 = ( T_1 T_4 * ) ( unsigned long ) ( V_264 -> V_286 ) ;
for ( V_1 = 0 ; V_1 < V_271 ; V_1 ++ ) {
if ( V_77 -> V_272 [ V_1 ] != 0 ) {
if ( F_116 ( V_77 -> V_272 [ V_1 ] ,
V_270 + V_222 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_222 ++ ;
}
}
}
V_264 -> V_237 = V_266 ;
V_40:
F_132 ( & V_17 -> V_23 . V_281 ) ;
V_107:
F_13 ( & V_17 -> V_23 . V_61 ) ;
return V_22 ;
}
static struct V_46 * F_133 ( struct V_127 * V_128 )
{
struct V_76 * V_77 ;
struct V_16 * V_17 = V_128 -> V_17 ;
bool V_287 = false ;
F_117 (connector, dev) {
if ( ! V_77 -> V_73 )
continue;
V_287 = true ;
if ( V_77 -> V_73 -> V_253 != V_128 )
continue;
return V_77 -> V_73 -> V_47 ;
}
if ( V_287 )
return NULL ;
return V_128 -> V_47 ;
}
int F_134 ( struct V_16 * V_17 , void * V_211 ,
struct V_212 * V_213 )
{
struct V_288 * V_289 = V_211 ;
struct V_127 * V_128 ;
struct V_46 * V_47 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
V_128 = F_135 ( V_17 , V_289 -> V_225 ) ;
if ( ! V_128 )
return - V_243 ;
F_130 ( & V_17 -> V_23 . V_281 , NULL ) ;
V_47 = F_133 ( V_128 ) ;
if ( V_47 )
V_289 -> V_224 = V_47 -> V_39 . V_27 ;
else
V_289 -> V_224 = 0 ;
F_132 ( & V_17 -> V_23 . V_281 ) ;
V_289 -> V_130 = V_128 -> V_130 ;
V_289 -> V_225 = V_128 -> V_39 . V_27 ;
V_289 -> V_68 = V_128 -> V_68 ;
V_289 -> V_290 = V_128 -> V_290 ;
return 0 ;
}
int F_136 ( struct V_16 * V_17 , void * V_211 ,
struct V_212 * V_213 )
{
struct V_291 * V_292 = V_211 ;
struct V_57 * V_58 ;
struct V_48 * V_49 ;
T_1 T_4 * V_293 ;
int V_222 = 0 ;
unsigned V_294 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
V_58 = & V_17 -> V_23 ;
if ( V_213 -> V_295 )
V_294 = V_58 -> V_141 ;
else
V_294 = V_58 -> V_143 ;
if ( V_294 &&
( V_292 -> V_296 >= V_294 ) ) {
V_293 = ( T_1 T_4 * ) ( unsigned long ) V_292 -> V_297 ;
F_49 (plane, dev) {
if ( V_49 -> type != V_142 &&
! V_213 -> V_295 )
continue;
if ( F_116 ( V_49 -> V_39 . V_27 , V_293 + V_222 ) )
return - V_230 ;
V_222 ++ ;
}
}
V_292 -> V_296 = V_294 ;
return 0 ;
}
int F_137 ( struct V_16 * V_17 , void * V_211 ,
struct V_212 * V_213 )
{
struct V_298 * V_292 = V_211 ;
struct V_48 * V_49 ;
T_1 T_4 * V_299 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
V_49 = F_138 ( V_17 , V_292 -> V_300 ) ;
if ( ! V_49 )
return - V_243 ;
F_130 ( & V_49 -> V_61 , NULL ) ;
if ( V_49 -> V_47 )
V_292 -> V_224 = V_49 -> V_47 -> V_39 . V_27 ;
else
V_292 -> V_224 = 0 ;
if ( V_49 -> V_33 )
V_292 -> V_223 = V_49 -> V_33 -> V_39 . V_27 ;
else
V_292 -> V_223 = 0 ;
F_132 ( & V_49 -> V_61 ) ;
V_292 -> V_300 = V_49 -> V_39 . V_27 ;
V_292 -> V_68 = V_49 -> V_68 ;
V_292 -> V_244 = 0 ;
if ( V_49 -> V_136 &&
( V_292 -> V_301 >= V_49 -> V_136 ) ) {
V_299 = ( T_1 T_4 * ) ( unsigned long ) V_292 -> V_302 ;
if ( F_131 ( V_299 ,
V_49 -> V_139 ,
sizeof( T_1 ) * V_49 -> V_136 ) ) {
return - V_230 ;
}
}
V_292 -> V_301 = V_49 -> V_136 ;
return 0 ;
}
int F_139 ( const struct V_48 * V_49 , T_3 V_13 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_49 -> V_136 ; V_1 ++ ) {
if ( V_13 == V_49 -> V_139 [ V_1 ] )
return 0 ;
}
return - V_85 ;
}
static int F_140 ( T_1 V_246 , T_1 V_248 ,
T_1 V_303 , T_1 V_304 ,
const struct V_32 * V_33 )
{
unsigned int V_305 , V_306 ;
V_305 = V_33 -> V_307 << 16 ;
V_306 = V_33 -> V_308 << 16 ;
if ( V_303 > V_305 ||
V_246 > V_305 - V_303 ||
V_304 > V_306 ||
V_248 > V_306 - V_304 ) {
F_73 ( L_68
L_69 ,
V_303 >> 16 , ( ( V_303 & 0xffff ) * 15625 ) >> 10 ,
V_304 >> 16 , ( ( V_304 & 0xffff ) * 15625 ) >> 10 ,
V_246 >> 16 , ( ( V_246 & 0xffff ) * 15625 ) >> 10 ,
V_248 >> 16 , ( ( V_248 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_309 ;
}
return 0 ;
}
static int F_141 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_6 V_310 , T_6 V_311 ,
T_1 V_312 , T_1 V_313 ,
T_1 V_246 , T_1 V_248 ,
T_1 V_303 , T_1 V_304 )
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
if ( ! ( V_49 -> V_68 & F_142 ( V_47 ) ) ) {
F_73 ( L_70 ) ;
V_22 = - V_85 ;
goto V_40;
}
V_22 = F_139 ( V_49 , V_33 -> V_314 ) ;
if ( V_22 ) {
F_73 ( L_71 ,
F_9 ( V_33 -> V_314 ) ) ;
goto V_40;
}
if ( V_312 > V_169 ||
V_310 > V_169 - ( T_6 ) V_312 ||
V_313 > V_169 ||
V_311 > V_169 - ( T_6 ) V_313 ) {
F_73 ( L_72 ,
V_312 , V_313 , V_310 , V_311 ) ;
V_22 = - V_315 ;
goto V_40;
}
V_22 = F_140 ( V_246 , V_248 , V_303 , V_304 , V_33 ) ;
if ( V_22 )
goto V_40;
V_49 -> V_156 = V_49 -> V_33 ;
V_22 = V_49 -> V_35 -> V_316 ( V_49 , V_47 , V_33 ,
V_310 , V_311 , V_312 , V_313 ,
V_246 , V_248 , V_303 , V_304 ) ;
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
static int F_143 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_6 V_310 , T_6 V_311 ,
T_1 V_312 , T_1 V_313 ,
T_1 V_246 , T_1 V_248 ,
T_1 V_303 , T_1 V_304 )
{
int V_22 ;
F_45 ( V_49 -> V_17 ) ;
V_22 = F_141 ( V_49 , V_47 , V_33 ,
V_310 , V_311 , V_312 , V_313 ,
V_246 , V_248 , V_303 , V_304 ) ;
F_51 ( V_49 -> V_17 ) ;
return V_22 ;
}
int F_144 ( struct V_16 * V_17 , void * V_211 ,
struct V_212 * V_213 )
{
struct V_317 * V_318 = V_211 ;
struct V_48 * V_49 ;
struct V_46 * V_47 = NULL ;
struct V_32 * V_33 = NULL ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
V_49 = F_138 ( V_17 , V_318 -> V_300 ) ;
if ( ! V_49 ) {
F_73 ( L_73 ,
V_318 -> V_300 ) ;
return - V_243 ;
}
if ( V_318 -> V_223 ) {
V_33 = F_32 ( V_17 , V_318 -> V_223 ) ;
if ( ! V_33 ) {
F_73 ( L_74 ,
V_318 -> V_223 ) ;
return - V_243 ;
}
V_47 = F_119 ( V_17 , V_318 -> V_224 ) ;
if ( ! V_47 ) {
F_73 ( L_75 ,
V_318 -> V_224 ) ;
return - V_243 ;
}
}
return F_143 ( V_49 , V_47 , V_33 ,
V_318 -> V_310 , V_318 -> V_311 ,
V_318 -> V_312 , V_318 -> V_313 ,
V_318 -> V_246 , V_318 -> V_248 ,
V_318 -> V_303 , V_318 -> V_304 ) ;
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
V_22 = V_47 -> V_35 -> V_319 ( V_51 ) ;
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
void F_145 ( const struct V_78 * V_79 ,
int * V_320 , int * V_321 )
{
struct V_78 V_322 ;
F_146 ( & V_322 , V_79 ) ;
F_147 ( & V_322 , V_323 ) ;
* V_320 = V_322 . V_324 ;
* V_321 = V_322 . V_325 ;
}
int F_148 ( const struct V_46 * V_47 ,
int V_245 , int V_247 ,
const struct V_78 * V_79 ,
const struct V_32 * V_33 )
{
int V_320 , V_321 ;
F_145 ( V_79 , & V_320 , & V_321 ) ;
if ( V_47 -> V_73 &&
V_47 -> V_52 -> V_73 -> V_326 & ( F_149 ( V_327 ) |
F_149 ( V_328 ) ) )
F_150 ( V_320 , V_321 ) ;
return F_140 ( V_245 << 16 , V_247 << 16 ,
V_320 << 16 , V_321 << 16 , V_33 ) ;
}
int F_151 ( struct V_16 * V_17 , void * V_211 ,
struct V_212 * V_213 )
{
struct V_57 * V_58 = & V_17 -> V_23 ;
struct V_241 * V_329 = V_211 ;
struct V_46 * V_47 ;
struct V_76 * * V_330 = NULL , * V_77 ;
struct V_32 * V_33 = NULL ;
struct V_78 * V_79 = NULL ;
struct V_50 V_51 ;
T_1 T_4 * V_331 ;
int V_22 ;
int V_1 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
if ( V_329 -> V_245 & 0xffff0000 || V_329 -> V_247 & 0xffff0000 )
return - V_315 ;
F_45 ( V_17 ) ;
V_47 = F_119 ( V_17 , V_329 -> V_224 ) ;
if ( ! V_47 ) {
F_73 ( L_76 , V_329 -> V_224 ) ;
V_22 = - V_243 ;
goto V_40;
}
F_73 ( L_63 , V_47 -> V_39 . V_27 , V_47 -> V_11 ) ;
if ( V_329 -> V_250 ) {
if ( V_329 -> V_223 == - 1 ) {
if ( ! V_47 -> V_52 -> V_33 ) {
F_73 ( L_77 ) ;
V_22 = - V_85 ;
goto V_40;
}
V_33 = V_47 -> V_52 -> V_33 ;
F_38 ( V_33 ) ;
} else {
V_33 = F_32 ( V_17 , V_329 -> V_223 ) ;
if ( ! V_33 ) {
F_73 ( L_78 ,
V_329 -> V_223 ) ;
V_22 = - V_243 ;
goto V_40;
}
}
V_79 = F_152 ( V_17 ) ;
if ( ! V_79 ) {
V_22 = - V_64 ;
goto V_40;
}
V_22 = F_153 ( V_79 , & V_329 -> V_79 ) ;
if ( V_22 ) {
F_73 ( L_79 ) ;
goto V_40;
}
F_147 ( V_79 , V_332 ) ;
if ( ! V_47 -> V_52 -> V_333 ) {
V_22 = F_139 ( V_47 -> V_52 ,
V_33 -> V_314 ) ;
if ( V_22 ) {
F_73 ( L_71 ,
F_9 ( V_33 -> V_314 ) ) ;
goto V_40;
}
}
V_22 = F_148 ( V_47 , V_329 -> V_245 , V_329 -> V_247 ,
V_79 , V_33 ) ;
if ( V_22 )
goto V_40;
}
if ( V_329 -> V_239 == 0 && V_79 ) {
F_73 ( L_80 ) ;
V_22 = - V_85 ;
goto V_40;
}
if ( V_329 -> V_239 > 0 && ( ! V_79 || ! V_33 ) ) {
F_73 ( L_81 ,
V_329 -> V_239 ) ;
V_22 = - V_85 ;
goto V_40;
}
if ( V_329 -> V_239 > 0 ) {
T_3 V_334 ;
if ( V_329 -> V_239 > V_58 -> V_118 ) {
V_22 = - V_85 ;
goto V_40;
}
V_330 = F_94 ( V_329 -> V_239 ,
sizeof( struct V_76 * ) ,
V_26 ) ;
if ( ! V_330 ) {
V_22 = - V_64 ;
goto V_40;
}
for ( V_1 = 0 ; V_1 < V_329 -> V_239 ; V_1 ++ ) {
V_331 = ( T_1 T_4 * ) ( unsigned long ) V_329 -> V_331 ;
if ( F_154 ( V_334 , & V_331 [ V_1 ] ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_77 = F_129 ( V_17 , V_334 ) ;
if ( ! V_77 ) {
F_73 ( L_82 ,
V_334 ) ;
V_22 = - V_243 ;
goto V_40;
}
F_73 ( L_65 ,
V_77 -> V_39 . V_27 ,
V_77 -> V_11 ) ;
V_330 [ V_1 ] = V_77 ;
}
}
V_51 . V_47 = V_47 ;
V_51 . V_245 = V_329 -> V_245 ;
V_51 . V_247 = V_329 -> V_247 ;
V_51 . V_79 = V_79 ;
V_51 . V_335 = V_330 ;
V_51 . V_336 = V_329 -> V_239 ;
V_51 . V_33 = V_33 ;
V_22 = F_47 ( & V_51 ) ;
V_40:
if ( V_33 )
F_34 ( V_33 ) ;
F_62 ( V_330 ) ;
F_66 ( V_17 , V_79 ) ;
F_51 ( V_17 ) ;
return V_22 ;
}
static int F_155 ( struct V_46 * V_47 ,
struct V_337 * V_338 ,
struct V_212 * V_213 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
struct V_32 * V_33 = NULL ;
struct V_339 V_340 = {
. V_307 = V_338 -> V_307 ,
. V_308 = V_338 -> V_308 ,
. V_314 = V_341 ,
. V_342 = { V_338 -> V_307 * 4 } ,
. V_343 = { V_338 -> V_344 } ,
} ;
T_6 V_310 , V_311 ;
T_1 V_312 = 0 , V_313 = 0 ;
T_1 V_303 = 0 , V_304 = 0 ;
int V_22 = 0 ;
F_97 ( ! V_47 -> V_55 ) ;
F_22 ( V_47 -> V_55 -> V_47 != V_47 && V_47 -> V_55 -> V_47 != NULL ) ;
if ( V_338 -> V_262 & V_345 ) {
if ( V_338 -> V_344 ) {
V_33 = F_156 ( V_17 , & V_340 , V_213 ) ;
if ( F_157 ( V_33 ) ) {
F_73 ( L_83 ) ;
return F_158 ( V_33 ) ;
}
} else {
V_33 = NULL ;
}
} else {
V_33 = V_47 -> V_55 -> V_33 ;
if ( V_33 )
F_38 ( V_33 ) ;
}
if ( V_338 -> V_262 & V_346 ) {
V_310 = V_338 -> V_245 ;
V_311 = V_338 -> V_247 ;
} else {
V_310 = V_47 -> V_347 ;
V_311 = V_47 -> V_348 ;
}
if ( V_33 ) {
V_312 = V_33 -> V_307 ;
V_313 = V_33 -> V_308 ;
V_303 = V_33 -> V_307 << 16 ;
V_304 = V_33 -> V_308 << 16 ;
}
V_22 = F_141 ( V_47 -> V_55 , V_47 , V_33 ,
V_310 , V_311 , V_312 , V_313 ,
0 , 0 , V_303 , V_304 ) ;
if ( V_22 == 0 && V_338 -> V_262 & V_346 ) {
V_47 -> V_347 = V_338 -> V_245 ;
V_47 -> V_348 = V_338 -> V_247 ;
}
return V_22 ;
}
static int F_159 ( struct V_16 * V_17 ,
struct V_337 * V_338 ,
struct V_212 * V_213 )
{
struct V_46 * V_47 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
if ( ! V_338 -> V_262 || ( ~ V_349 & V_338 -> V_262 ) )
return - V_85 ;
V_47 = F_119 ( V_17 , V_338 -> V_224 ) ;
if ( ! V_47 ) {
F_73 ( L_76 , V_338 -> V_224 ) ;
return - V_243 ;
}
F_120 ( V_47 , V_47 -> V_55 ) ;
if ( V_47 -> V_55 ) {
V_22 = F_155 ( V_47 , V_338 , V_213 ) ;
goto V_40;
}
if ( V_338 -> V_262 & V_345 ) {
if ( ! V_47 -> V_35 -> V_350 && ! V_47 -> V_35 -> V_351 ) {
V_22 = - V_352 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_351 )
V_22 = V_47 -> V_35 -> V_351 ( V_47 , V_213 , V_338 -> V_344 ,
V_338 -> V_307 , V_338 -> V_308 , V_338 -> V_353 , V_338 -> V_354 ) ;
else
V_22 = V_47 -> V_35 -> V_350 ( V_47 , V_213 , V_338 -> V_344 ,
V_338 -> V_307 , V_338 -> V_308 ) ;
}
if ( V_338 -> V_262 & V_346 ) {
if ( V_47 -> V_35 -> V_355 ) {
V_22 = V_47 -> V_35 -> V_355 ( V_47 , V_338 -> V_245 , V_338 -> V_247 ) ;
} else {
V_22 = - V_230 ;
goto V_40;
}
}
V_40:
F_122 ( V_47 ) ;
return V_22 ;
}
int F_160 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_356 * V_338 = V_211 ;
struct V_337 V_357 ;
memcpy ( & V_357 , V_338 , sizeof( struct V_356 ) ) ;
V_357 . V_353 = V_357 . V_354 = 0 ;
return F_159 ( V_17 , & V_357 , V_213 ) ;
}
int F_161 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_337 * V_338 = V_211 ;
return F_159 ( V_17 , V_338 , V_213 ) ;
}
T_1 F_162 ( T_1 V_358 , T_1 V_359 )
{
T_1 V_360 ;
switch ( V_358 ) {
case 8 :
V_360 = V_361 ;
break;
case 16 :
if ( V_359 == 15 )
V_360 = V_362 ;
else
V_360 = V_363 ;
break;
case 24 :
V_360 = V_364 ;
break;
case 32 :
if ( V_359 == 24 )
V_360 = V_365 ;
else if ( V_359 == 30 )
V_360 = V_366 ;
else
V_360 = V_341 ;
break;
default:
F_48 ( L_84 ) ;
V_360 = V_365 ;
break;
}
return V_360 ;
}
int F_163 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_367 * V_368 = V_211 ;
struct V_339 V_369 = {} ;
int V_22 ;
V_369 . V_223 = V_368 -> V_223 ;
V_369 . V_307 = V_368 -> V_307 ;
V_369 . V_308 = V_368 -> V_308 ;
V_369 . V_342 [ 0 ] = V_368 -> V_370 ;
V_369 . V_314 = F_162 ( V_368 -> V_358 , V_368 -> V_359 ) ;
V_369 . V_343 [ 0 ] = V_368 -> V_344 ;
V_22 = F_164 ( V_17 , & V_369 , V_213 ) ;
if ( V_22 )
return V_22 ;
V_368 -> V_223 = V_369 . V_223 ;
return 0 ;
}
static int F_165 ( const struct V_339 * V_369 )
{
T_1 V_13 = V_369 -> V_314 & ~ V_15 ;
switch ( V_13 ) {
case V_361 :
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
case V_362 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_363 :
case V_388 :
case V_364 :
case V_389 :
case V_365 :
case V_390 :
case V_391 :
case V_392 :
case V_341 :
case V_393 :
case V_394 :
case V_395 :
case V_366 :
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
case V_422 :
case V_423 :
return 0 ;
default:
F_73 ( L_85 ,
F_9 ( V_369 -> V_314 ) ) ;
return - V_85 ;
}
}
static int F_166 ( const struct V_339 * V_369 )
{
int V_22 , V_424 , V_425 , V_294 , V_1 ;
V_22 = F_165 ( V_369 ) ;
if ( V_22 ) {
F_73 ( L_86 ,
F_9 ( V_369 -> V_314 ) ) ;
return V_22 ;
}
V_424 = F_167 ( V_369 -> V_314 ) ;
V_425 = F_168 ( V_369 -> V_314 ) ;
V_294 = F_169 ( V_369 -> V_314 ) ;
if ( V_369 -> V_307 == 0 || V_369 -> V_307 % V_424 ) {
F_73 ( L_87 , V_369 -> V_307 ) ;
return - V_85 ;
}
if ( V_369 -> V_308 == 0 || V_369 -> V_308 % V_425 ) {
F_73 ( L_88 , V_369 -> V_308 ) ;
return - V_85 ;
}
for ( V_1 = 0 ; V_1 < V_294 ; V_1 ++ ) {
unsigned int V_307 = V_369 -> V_307 / ( V_1 != 0 ? V_424 : 1 ) ;
unsigned int V_308 = V_369 -> V_308 / ( V_1 != 0 ? V_425 : 1 ) ;
unsigned int V_426 = F_170 ( V_369 -> V_314 , V_1 ) ;
if ( ! V_369 -> V_343 [ V_1 ] ) {
F_73 ( L_89 , V_1 ) ;
return - V_85 ;
}
if ( ( T_5 ) V_307 * V_426 > V_167 )
return - V_315 ;
if ( ( T_5 ) V_308 * V_369 -> V_342 [ V_1 ] + V_369 -> V_427 [ V_1 ] > V_167 )
return - V_315 ;
if ( V_369 -> V_342 [ V_1 ] < V_307 * V_426 ) {
F_73 ( L_90 , V_369 -> V_342 [ V_1 ] , V_1 ) ;
return - V_85 ;
}
if ( V_369 -> V_428 [ V_1 ] && ! ( V_369 -> V_262 & V_429 ) ) {
F_73 ( L_91 ,
V_369 -> V_428 [ V_1 ] , V_1 ) ;
return - V_85 ;
}
switch ( V_369 -> V_428 [ V_1 ] ) {
case V_430 :
if ( V_369 -> V_314 != V_408 ||
V_307 % 128 || V_308 % 32 ||
V_369 -> V_342 [ V_1 ] % 128 ) {
F_73 ( L_92 , V_1 ) ;
return - V_85 ;
}
break;
default:
break;
}
}
for ( V_1 = V_294 ; V_1 < 4 ; V_1 ++ ) {
if ( V_369 -> V_428 [ V_1 ] ) {
F_73 ( L_93 , V_1 ) ;
return - V_85 ;
}
if ( ! ( V_369 -> V_262 & V_429 ) )
continue;
if ( V_369 -> V_343 [ V_1 ] ) {
F_73 ( L_94 , V_1 ) ;
return - V_85 ;
}
if ( V_369 -> V_342 [ V_1 ] ) {
F_73 ( L_95 , V_1 ) ;
return - V_85 ;
}
if ( V_369 -> V_427 [ V_1 ] ) {
F_73 ( L_96 , V_1 ) ;
return - V_85 ;
}
}
return 0 ;
}
static struct V_32 *
F_156 ( struct V_16 * V_17 ,
const struct V_339 * V_369 ,
struct V_212 * V_213 )
{
struct V_57 * V_58 = & V_17 -> V_23 ;
struct V_32 * V_33 ;
int V_22 ;
if ( V_369 -> V_262 & ~ ( V_431 | V_429 ) ) {
F_73 ( L_97 , V_369 -> V_262 ) ;
return F_171 ( - V_85 ) ;
}
if ( ( V_58 -> V_234 > V_369 -> V_307 ) || ( V_369 -> V_307 > V_58 -> V_233 ) ) {
F_73 ( L_98 ,
V_369 -> V_307 , V_58 -> V_234 , V_58 -> V_233 ) ;
return F_171 ( - V_85 ) ;
}
if ( ( V_58 -> V_232 > V_369 -> V_308 ) || ( V_369 -> V_308 > V_58 -> V_231 ) ) {
F_73 ( L_99 ,
V_369 -> V_308 , V_58 -> V_232 , V_58 -> V_231 ) ;
return F_171 ( - V_85 ) ;
}
if ( V_369 -> V_262 & V_429 &&
! V_17 -> V_23 . V_432 ) {
F_73 ( L_100 ) ;
return F_171 ( - V_85 ) ;
}
V_22 = F_166 ( V_369 ) ;
if ( V_22 )
return F_171 ( V_22 ) ;
V_33 = V_17 -> V_23 . V_35 -> V_433 ( V_17 , V_213 , V_369 ) ;
if ( F_157 ( V_33 ) ) {
F_73 ( L_101 ) ;
return V_33 ;
}
return V_33 ;
}
int F_164 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_339 * V_369 = V_211 ;
struct V_32 * V_33 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
V_33 = F_156 ( V_17 , V_369 , V_213 ) ;
if ( F_157 ( V_33 ) )
return F_158 ( V_33 ) ;
F_73 ( L_102 , V_33 -> V_39 . V_27 ) ;
F_11 ( & V_213 -> V_227 ) ;
V_369 -> V_223 = V_33 -> V_39 . V_27 ;
F_26 ( & V_33 -> V_38 , & V_213 -> V_434 ) ;
F_13 ( & V_213 -> V_227 ) ;
return 0 ;
}
int F_172 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_32 * V_33 = NULL ;
struct V_32 * V_435 = NULL ;
T_1 * V_27 = V_211 ;
int V_436 = 0 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
F_11 ( & V_213 -> V_227 ) ;
F_11 ( & V_17 -> V_23 . V_36 ) ;
V_33 = F_30 ( V_17 , * V_27 ) ;
if ( ! V_33 )
goto V_437;
F_87 (fbl, &file_priv->fbs, filp_head)
if ( V_33 == V_435 )
V_436 = 1 ;
if ( ! V_436 )
goto V_437;
F_173 ( & V_33 -> V_38 ) ;
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_213 -> V_227 ) ;
F_34 ( V_33 ) ;
return 0 ;
V_437:
F_13 ( & V_17 -> V_23 . V_36 ) ;
F_13 ( & V_213 -> V_227 ) ;
return - V_243 ;
}
int F_174 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_367 * V_369 = V_211 ;
struct V_32 * V_33 ;
int V_22 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
V_33 = F_32 ( V_17 , V_369 -> V_223 ) ;
if ( ! V_33 )
return - V_243 ;
V_369 -> V_308 = V_33 -> V_308 ;
V_369 -> V_307 = V_33 -> V_307 ;
V_369 -> V_359 = V_33 -> V_359 ;
V_369 -> V_358 = V_33 -> V_438 ;
V_369 -> V_370 = V_33 -> V_342 [ 0 ] ;
if ( V_33 -> V_35 -> V_439 ) {
if ( V_213 -> V_440 || F_175 ( V_441 ) ||
F_176 ( V_213 ) ) {
V_22 = V_33 -> V_35 -> V_439 ( V_33 , V_213 ,
& V_369 -> V_344 ) ;
} else {
V_369 -> V_344 = 0 ;
V_22 = 0 ;
}
} else {
V_22 = - V_442 ;
}
F_34 ( V_33 ) ;
return V_22 ;
}
int F_177 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_443 T_4 * V_444 ;
struct V_443 * V_445 = NULL ;
struct V_446 * V_369 = V_211 ;
struct V_32 * V_33 ;
unsigned V_262 ;
int V_447 ;
int V_22 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
V_33 = F_32 ( V_17 , V_369 -> V_223 ) ;
if ( ! V_33 )
return - V_243 ;
V_447 = V_369 -> V_447 ;
V_444 = (struct V_443 T_4 * ) ( unsigned long ) V_369 -> V_444 ;
if ( ! V_447 != ! V_444 ) {
V_22 = - V_85 ;
goto V_448;
}
V_262 = V_449 & V_369 -> V_262 ;
if ( V_262 & V_450 && ( V_447 % 2 ) ) {
V_22 = - V_85 ;
goto V_448;
}
if ( V_447 && V_444 ) {
if ( V_447 < 0 || V_447 > V_451 ) {
V_22 = - V_85 ;
goto V_448;
}
V_445 = F_178 ( V_447 , sizeof( * V_445 ) , V_26 ) ;
if ( ! V_445 ) {
V_22 = - V_64 ;
goto V_448;
}
V_22 = F_179 ( V_445 , V_444 ,
V_447 * sizeof( * V_445 ) ) ;
if ( V_22 ) {
V_22 = - V_230 ;
goto V_452;
}
}
if ( V_33 -> V_35 -> V_453 ) {
V_22 = V_33 -> V_35 -> V_453 ( V_33 , V_213 , V_262 , V_369 -> V_454 ,
V_445 , V_447 ) ;
} else {
V_22 = - V_455 ;
}
V_452:
F_62 ( V_445 ) ;
V_448:
F_34 ( V_33 ) ;
return V_22 ;
}
void F_180 ( struct V_212 * V_456 )
{
struct V_32 * V_33 , * V_457 ;
F_79 (fb, tfb, &priv->fbs, filp_head) {
F_173 ( & V_33 -> V_38 ) ;
F_34 ( V_33 ) ;
}
}
struct V_158 * F_101 ( struct V_16 * V_17 , int V_262 ,
const char * V_11 , int V_458 )
{
struct V_158 * V_459 = NULL ;
int V_22 ;
V_459 = F_181 ( sizeof( struct V_158 ) , V_26 ) ;
if ( ! V_459 )
return NULL ;
V_459 -> V_17 = V_17 ;
if ( V_458 ) {
V_459 -> V_460 = F_178 ( V_458 , sizeof( T_5 ) ,
V_26 ) ;
if ( ! V_459 -> V_460 )
goto V_461;
}
V_22 = F_14 ( V_17 , & V_459 -> V_39 , V_462 ) ;
if ( V_22 )
goto V_461;
V_459 -> V_262 = V_262 ;
V_459 -> V_458 = V_458 ;
F_25 ( & V_459 -> V_463 ) ;
if ( V_11 ) {
strncpy ( V_459 -> V_11 , V_11 , V_464 ) ;
V_459 -> V_11 [ V_464 - 1 ] = '\0' ;
}
F_57 ( & V_459 -> V_42 , & V_17 -> V_23 . V_465 ) ;
F_22 ( ! F_182 ( V_459 ) ) ;
return V_459 ;
V_461:
F_62 ( V_459 -> V_460 ) ;
F_62 ( V_459 ) ;
return NULL ;
}
struct V_158 * F_102 ( struct V_16 * V_17 , int V_262 ,
const char * V_11 ,
const struct V_466 * V_467 ,
int V_458 )
{
struct V_158 * V_459 ;
int V_1 , V_22 ;
V_262 |= V_194 ;
V_459 = F_101 ( V_17 , V_262 , V_11 , V_458 ) ;
if ( ! V_459 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_458 ; V_1 ++ ) {
V_22 = F_109 ( V_459 , V_1 ,
V_467 [ V_1 ] . type ,
V_467 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_183 ( V_17 , V_459 ) ;
return NULL ;
}
}
return V_459 ;
}
struct V_158 * F_184 ( struct V_16 * V_17 ,
int V_262 , const char * V_11 ,
const struct V_466 * V_467 ,
int V_468 ,
T_5 V_469 )
{
struct V_158 * V_459 ;
int V_1 , V_22 , V_75 = 0 ;
int V_458 = F_185 ( V_469 ) ;
V_262 |= V_470 ;
V_459 = F_101 ( V_17 , V_262 , V_11 , V_458 ) ;
if ( ! V_459 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_468 ; V_1 ++ ) {
if ( ! ( V_469 & ( 1ULL << V_467 [ V_1 ] . type ) ) )
continue;
if ( F_22 ( V_75 >= V_458 ) ) {
F_183 ( V_17 , V_459 ) ;
return NULL ;
}
V_22 = F_109 ( V_459 , V_75 ++ ,
V_467 [ V_1 ] . type ,
V_467 [ V_1 ] . V_11 ) ;
if ( V_22 ) {
F_183 ( V_17 , V_459 ) ;
return NULL ;
}
}
return V_459 ;
}
static struct V_158 * F_186 ( struct V_16 * V_17 ,
int V_262 , const char * V_11 ,
T_5 V_471 , T_5 V_472 )
{
struct V_158 * V_459 ;
V_459 = F_101 ( V_17 , V_262 , V_11 , 2 ) ;
if ( ! V_459 )
return NULL ;
V_459 -> V_460 [ 0 ] = V_471 ;
V_459 -> V_460 [ 1 ] = V_472 ;
return V_459 ;
}
struct V_158 * F_103 ( struct V_16 * V_17 , int V_262 ,
const char * V_11 ,
T_5 V_471 , T_5 V_472 )
{
return F_186 ( V_17 , V_473 | V_262 ,
V_11 , V_471 , V_472 ) ;
}
struct V_158 * F_104 ( struct V_16 * V_17 ,
int V_262 , const char * V_11 ,
T_7 V_471 , T_7 V_472 )
{
return F_186 ( V_17 , V_474 | V_262 ,
V_11 , F_187 ( V_471 ) , F_187 ( V_472 ) ) ;
}
struct V_158 * F_105 ( struct V_16 * V_17 ,
int V_262 , const char * V_11 , T_1 type )
{
struct V_158 * V_459 ;
V_262 |= V_475 ;
if ( F_22 ( ! ( V_262 & V_166 ) ) )
return NULL ;
V_459 = F_101 ( V_17 , V_262 , V_11 , 1 ) ;
if ( ! V_459 )
return NULL ;
V_459 -> V_460 [ 0 ] = type ;
return V_459 ;
}
struct V_158 * F_106 ( struct V_16 * V_17 , int V_262 ,
const char * V_11 )
{
return F_103 ( V_17 , V_262 , V_11 , 0 , 1 ) ;
}
int F_109 ( struct V_158 * V_459 , int V_75 ,
T_5 V_476 , const char * V_11 )
{
struct V_477 * V_478 ;
if ( ! ( F_188 ( V_459 , V_194 ) ||
F_188 ( V_459 , V_470 ) ) )
return - V_85 ;
if ( F_188 ( V_459 , V_470 ) &&
( V_476 > 63 ) )
return - V_85 ;
if ( ! F_44 ( & V_459 -> V_463 ) ) {
F_87 (prop_enum, &property->enum_list, head) {
if ( V_478 -> V_476 == V_476 ) {
strncpy ( V_478 -> V_11 , V_11 , V_464 ) ;
V_478 -> V_11 [ V_464 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_478 = F_181 ( sizeof( struct V_477 ) , V_26 ) ;
if ( ! V_478 )
return - V_64 ;
strncpy ( V_478 -> V_11 , V_11 , V_464 ) ;
V_478 -> V_11 [ V_464 - 1 ] = '\0' ;
V_478 -> V_476 = V_476 ;
V_459 -> V_460 [ V_75 ] = V_476 ;
F_57 ( & V_478 -> V_42 , & V_459 -> V_463 ) ;
return 0 ;
}
void F_183 ( struct V_16 * V_17 , struct V_158 * V_459 )
{
struct V_477 * V_478 , * V_479 ;
F_79 (prop_enum, pt, &property->enum_list, head) {
F_42 ( & V_478 -> V_42 ) ;
F_62 ( V_478 ) ;
}
if ( V_459 -> V_458 )
F_62 ( V_459 -> V_460 ) ;
F_17 ( V_17 , & V_459 -> V_39 ) ;
F_42 ( & V_459 -> V_42 ) ;
F_62 ( V_459 ) ;
}
void F_60 ( struct V_18 * V_19 ,
struct V_158 * V_459 ,
T_5 V_480 )
{
int V_259 = V_19 -> V_65 -> V_259 ;
if ( V_259 == V_481 ) {
F_189 ( 1 , L_103
L_104
L_105 ,
V_19 -> type ) ;
return;
}
V_19 -> V_65 -> V_65 [ V_259 ] = V_459 ;
V_19 -> V_65 -> V_460 [ V_259 ] = V_480 ;
V_19 -> V_65 -> V_259 ++ ;
if ( V_459 -> V_262 & V_166 )
V_19 -> V_65 -> V_260 ++ ;
}
int F_190 ( struct V_18 * V_19 ,
struct V_158 * V_459 , T_5 V_261 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_65 -> V_259 ; V_1 ++ ) {
if ( V_19 -> V_65 -> V_65 [ V_1 ] == V_459 ) {
V_19 -> V_65 -> V_460 [ V_1 ] = V_261 ;
return 0 ;
}
}
return - V_85 ;
}
int F_127 ( struct V_18 * V_19 ,
struct V_158 * V_459 , T_5 * V_261 )
{
int V_1 ;
if ( F_59 ( V_459 -> V_17 , V_69 ) &&
! ( V_459 -> V_262 & V_161 ) )
return F_191 ( V_19 , V_459 , V_261 ) ;
for ( V_1 = 0 ; V_1 < V_19 -> V_65 -> V_259 ; V_1 ++ ) {
if ( V_19 -> V_65 -> V_65 [ V_1 ] == V_459 ) {
* V_261 = V_19 -> V_65 -> V_460 [ V_1 ] ;
return 0 ;
}
}
return - V_85 ;
}
int F_192 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_482 * V_264 = V_211 ;
struct V_158 * V_459 ;
int V_483 = 0 ;
int V_484 = 0 ;
int V_22 = 0 , V_1 ;
int V_222 ;
struct V_477 * V_478 ;
struct V_485 T_4 * V_486 ;
T_5 T_4 * V_487 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_459 = F_193 ( V_17 , V_264 -> V_488 ) ;
if ( ! V_459 ) {
V_22 = - V_243 ;
goto V_489;
}
if ( F_188 ( V_459 , V_194 ) ||
F_188 ( V_459 , V_470 ) ) {
F_87 (prop_enum, &property->enum_list, head)
V_483 ++ ;
}
V_484 = V_459 -> V_458 ;
strncpy ( V_264 -> V_11 , V_459 -> V_11 , V_464 ) ;
V_264 -> V_11 [ V_464 - 1 ] = 0 ;
V_264 -> V_262 = V_459 -> V_262 ;
if ( ( V_264 -> V_490 >= V_484 ) && V_484 ) {
V_487 = ( T_5 T_4 * ) ( unsigned long ) V_264 -> V_487 ;
for ( V_1 = 0 ; V_1 < V_484 ; V_1 ++ ) {
if ( F_131 ( V_487 + V_1 , & V_459 -> V_460 [ V_1 ] , sizeof( T_5 ) ) ) {
V_22 = - V_230 ;
goto V_489;
}
}
}
V_264 -> V_490 = V_484 ;
if ( F_188 ( V_459 , V_194 ) ||
F_188 ( V_459 , V_470 ) ) {
if ( ( V_264 -> V_491 >= V_483 ) && V_483 ) {
V_222 = 0 ;
V_486 = (struct V_485 T_4 * ) ( unsigned long ) V_264 -> V_492 ;
F_87 (prop_enum, &property->enum_list, head) {
if ( F_131 ( & V_486 [ V_222 ] . V_476 , & V_478 -> V_476 , sizeof( T_5 ) ) ) {
V_22 = - V_230 ;
goto V_489;
}
if ( F_131 ( & V_486 [ V_222 ] . V_11 ,
& V_478 -> V_11 , V_464 ) ) {
V_22 = - V_230 ;
goto V_489;
}
V_222 ++ ;
}
}
V_264 -> V_491 = V_483 ;
}
if ( F_188 ( V_459 , V_160 ) )
V_264 -> V_491 = 0 ;
V_489:
F_51 ( V_17 ) ;
return V_22 ;
}
struct V_493 *
F_194 ( struct V_16 * V_17 , T_8 V_494 ,
const void * V_211 )
{
struct V_493 * V_495 ;
int V_22 ;
if ( ! V_494 || V_494 > V_496 - sizeof( struct V_493 ) )
return F_171 ( - V_85 ) ;
V_495 = F_181 ( sizeof( struct V_493 ) + V_494 , V_26 ) ;
if ( ! V_495 )
return F_171 ( - V_64 ) ;
F_25 ( & V_495 -> V_497 ) ;
V_495 -> V_494 = V_494 ;
V_495 -> V_17 = V_17 ;
if ( V_211 )
memcpy ( V_495 -> V_211 , V_211 , V_494 ) ;
F_11 ( & V_17 -> V_23 . V_498 ) ;
V_22 = F_14 ( V_17 , & V_495 -> V_39 , V_31 ) ;
if ( V_22 ) {
F_62 ( V_495 ) ;
F_13 ( & V_17 -> V_23 . V_498 ) ;
return F_171 ( - V_85 ) ;
}
F_24 ( & V_495 -> V_37 ) ;
F_57 ( & V_495 -> V_499 ,
& V_17 -> V_23 . V_500 ) ;
F_13 ( & V_17 -> V_23 . V_498 ) ;
return V_495 ;
}
static void F_195 ( struct V_44 * V_44 )
{
struct V_493 * V_495 =
F_29 ( V_44 , struct V_493 , V_37 ) ;
F_22 ( ! F_196 ( & V_495 -> V_17 -> V_23 . V_498 ) ) ;
F_42 ( & V_495 -> V_499 ) ;
F_42 ( & V_495 -> V_497 ) ;
F_17 ( V_495 -> V_17 , & V_495 -> V_39 ) ;
F_62 ( V_495 ) ;
}
void F_197 ( struct V_493 * V_495 )
{
struct V_16 * V_17 ;
if ( ! V_495 )
return;
V_17 = V_495 -> V_17 ;
F_35 ( L_106 , V_495 , V_495 -> V_39 . V_27 , F_36 ( & V_495 -> V_37 . V_37 ) ) ;
if ( F_198 ( & V_495 -> V_37 , F_195 ,
& V_17 -> V_23 . V_498 ) )
F_13 ( & V_17 -> V_23 . V_498 ) ;
else
F_199 ( & V_17 -> V_23 . V_498 ) ;
}
static void F_200 ( struct V_493 * V_495 )
{
if ( ! V_495 )
return;
F_35 ( L_106 , V_495 , V_495 -> V_39 . V_27 , F_36 ( & V_495 -> V_37 . V_37 ) ) ;
F_37 ( & V_495 -> V_37 , F_195 ) ;
}
void F_201 ( struct V_16 * V_17 ,
struct V_212 * V_213 )
{
struct V_493 * V_495 , * V_501 ;
F_11 ( & V_17 -> V_23 . V_498 ) ;
F_79 (blob, bt, &file_priv->blobs, head_file) {
F_173 ( & V_495 -> V_497 ) ;
F_200 ( V_495 ) ;
}
F_13 ( & V_17 -> V_23 . V_498 ) ;
}
struct V_493 * F_202 ( struct V_493 * V_495 )
{
F_35 ( L_106 , V_495 , V_495 -> V_39 . V_27 , F_36 ( & V_495 -> V_37 . V_37 ) ) ;
F_39 ( & V_495 -> V_37 ) ;
return V_495 ;
}
static struct V_493 * F_203 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_18 * V_19 = NULL ;
struct V_493 * V_495 ;
F_22 ( ! F_196 ( & V_17 -> V_23 . V_498 ) ) ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_19 = F_20 ( & V_17 -> V_23 . V_25 , V_27 ) ;
if ( ! V_19 || ( V_19 -> type != V_31 ) || ( V_19 -> V_27 != V_27 ) )
V_495 = NULL ;
else
V_495 = F_204 ( V_19 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_495 ;
}
struct V_493 * F_205 ( struct V_16 * V_17 ,
T_1 V_27 )
{
struct V_493 * V_495 ;
F_11 ( & V_17 -> V_23 . V_498 ) ;
V_495 = F_203 ( V_17 , V_27 ) ;
if ( V_495 ) {
if ( ! F_33 ( & V_495 -> V_37 ) )
V_495 = NULL ;
}
F_13 ( & V_17 -> V_23 . V_498 ) ;
return V_495 ;
}
static int F_206 ( struct V_16 * V_17 ,
struct V_493 * * V_502 ,
T_8 V_494 ,
const void * V_211 ,
struct V_18 * V_503 ,
struct V_158 * V_504 )
{
struct V_493 * V_505 = NULL ;
struct V_493 * V_506 = NULL ;
int V_22 ;
F_22 ( V_502 == NULL ) ;
V_506 = * V_502 ;
if ( V_494 && V_211 ) {
V_505 = F_194 ( V_17 , V_494 , V_211 ) ;
if ( F_157 ( V_505 ) )
return F_158 ( V_505 ) ;
}
if ( V_503 ) {
V_22 = F_190 ( V_503 ,
V_504 ,
V_505 ?
V_505 -> V_39 . V_27 : 0 ) ;
if ( V_22 != 0 )
goto V_507;
}
F_197 ( V_506 ) ;
* V_502 = V_505 ;
return 0 ;
V_507:
F_197 ( V_505 ) ;
return V_22 ;
}
int F_207 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_508 * V_264 = V_211 ;
struct V_493 * V_495 ;
int V_22 = 0 ;
void T_4 * V_509 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
F_45 ( V_17 ) ;
F_11 ( & V_17 -> V_23 . V_498 ) ;
V_495 = F_203 ( V_17 , V_264 -> V_510 ) ;
if ( ! V_495 ) {
V_22 = - V_243 ;
goto V_489;
}
if ( V_264 -> V_494 == V_495 -> V_494 ) {
V_509 = ( void T_4 * ) ( unsigned long ) V_264 -> V_211 ;
if ( F_131 ( V_509 , V_495 -> V_211 , V_495 -> V_494 ) ) {
V_22 = - V_230 ;
goto V_489;
}
}
V_264 -> V_494 = V_495 -> V_494 ;
V_489:
F_13 ( & V_17 -> V_23 . V_498 ) ;
F_51 ( V_17 ) ;
return V_22 ;
}
int F_208 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_511 * V_264 = V_211 ;
struct V_493 * V_495 ;
void T_4 * V_509 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
V_495 = F_194 ( V_17 , V_264 -> V_494 , NULL ) ;
if ( F_157 ( V_495 ) )
return F_158 ( V_495 ) ;
V_509 = ( void T_4 * ) ( unsigned long ) V_264 -> V_211 ;
if ( F_179 ( V_495 -> V_211 , V_509 , V_264 -> V_494 ) ) {
V_22 = - V_230 ;
goto V_512;
}
F_11 ( & V_17 -> V_23 . V_498 ) ;
V_264 -> V_510 = V_495 -> V_39 . V_27 ;
F_57 ( & V_495 -> V_497 , & V_213 -> V_513 ) ;
F_13 ( & V_17 -> V_23 . V_498 ) ;
return 0 ;
V_512:
F_197 ( V_495 ) ;
return V_22 ;
}
int F_209 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_514 * V_264 = V_211 ;
struct V_493 * V_495 = NULL , * V_501 ;
bool V_436 = false ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
F_11 ( & V_17 -> V_23 . V_498 ) ;
V_495 = F_203 ( V_17 , V_264 -> V_510 ) ;
if ( ! V_495 ) {
V_22 = - V_243 ;
goto V_515;
}
F_87 (bt, &file_priv->blobs, head_file) {
if ( V_501 == V_495 ) {
V_436 = true ;
break;
}
}
if ( ! V_436 ) {
V_22 = - V_516 ;
goto V_515;
}
F_173 ( & V_495 -> V_497 ) ;
F_200 ( V_495 ) ;
F_13 ( & V_17 -> V_23 . V_498 ) ;
return 0 ;
V_515:
F_13 ( & V_17 -> V_23 . V_498 ) ;
return V_22 ;
}
int F_210 ( struct V_76 * V_77 ,
const char * V_517 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
int V_22 ;
V_22 = F_206 ( V_17 ,
& V_77 -> V_518 ,
strlen ( V_517 ) + 1 ,
V_517 ,
& V_77 -> V_39 ,
V_17 -> V_23 . V_163 ) ;
return V_22 ;
}
int F_211 ( struct V_76 * V_77 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
char V_519 [ 256 ] ;
int V_22 ;
if ( ! V_77 -> V_520 ) {
V_22 = F_206 ( V_17 ,
& V_77 -> V_521 ,
0 ,
NULL ,
& V_77 -> V_39 ,
V_17 -> V_23 . V_164 ) ;
return V_22 ;
}
snprintf ( V_519 , 256 , L_107 ,
V_77 -> V_125 -> V_27 , V_77 -> V_522 ,
V_77 -> V_523 , V_77 -> V_524 ,
V_77 -> V_525 , V_77 -> V_526 ,
V_77 -> V_527 , V_77 -> V_528 ) ;
V_22 = F_206 ( V_17 ,
& V_77 -> V_521 ,
strlen ( V_519 ) + 1 ,
V_519 ,
& V_77 -> V_39 ,
V_17 -> V_23 . V_164 ) ;
return V_22 ;
}
int F_212 ( struct V_76 * V_77 ,
const struct V_529 * V_529 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
T_8 V_530 = 0 ;
int V_22 ;
if ( V_77 -> V_531 )
return 0 ;
if ( V_529 )
V_530 = V_532 * ( 1 + V_529 -> V_533 ) ;
V_22 = F_206 ( V_17 ,
& V_77 -> V_115 ,
V_530 ,
V_529 ,
& V_77 -> V_39 ,
V_17 -> V_23 . V_120 ) ;
return V_22 ;
}
bool F_213 ( struct V_158 * V_459 ,
T_5 V_476 , struct V_18 * * V_534 )
{
int V_1 ;
if ( V_459 -> V_262 & V_161 )
return false ;
* V_534 = NULL ;
if ( F_188 ( V_459 , V_473 ) ) {
if ( V_476 < V_459 -> V_460 [ 0 ] || V_476 > V_459 -> V_460 [ 1 ] )
return false ;
return true ;
} else if ( F_188 ( V_459 , V_474 ) ) {
T_7 V_535 = F_214 ( V_476 ) ;
if ( V_535 < F_214 ( V_459 -> V_460 [ 0 ] ) ||
V_535 > F_214 ( V_459 -> V_460 [ 1 ] ) )
return false ;
return true ;
} else if ( F_188 ( V_459 , V_470 ) ) {
T_5 V_536 = 0 ;
for ( V_1 = 0 ; V_1 < V_459 -> V_458 ; V_1 ++ )
V_536 |= ( 1ULL << V_459 -> V_460 [ V_1 ] ) ;
return ! ( V_476 & ~ V_536 ) ;
} else if ( F_188 ( V_459 , V_160 ) ) {
struct V_493 * V_495 ;
if ( V_476 == 0 )
return true ;
V_495 = F_205 ( V_459 -> V_17 , V_476 ) ;
if ( V_495 ) {
* V_534 = & V_495 -> V_39 ;
return true ;
} else {
return false ;
}
} else if ( F_188 ( V_459 , V_475 ) ) {
if ( V_476 == 0 )
return true ;
if ( V_459 -> V_460 [ 0 ] == V_30 ) {
struct V_32 * V_33 ;
V_33 = F_32 ( V_459 -> V_17 , V_476 ) ;
if ( V_33 ) {
* V_534 = & V_33 -> V_39 ;
return true ;
} else {
return false ;
}
} else {
return F_19 ( V_459 -> V_17 , V_476 , V_459 -> V_460 [ 0 ] ) != NULL ;
}
}
for ( V_1 = 0 ; V_1 < V_459 -> V_458 ; V_1 ++ )
if ( V_459 -> V_460 [ V_1 ] == V_476 )
return true ;
return false ;
}
void F_215 ( struct V_158 * V_459 ,
struct V_18 * V_534 )
{
if ( ! V_534 )
return;
if ( F_188 ( V_459 , V_475 ) ) {
if ( V_459 -> V_460 [ 0 ] == V_30 )
F_34 ( F_31 ( V_534 ) ) ;
} else if ( F_188 ( V_459 , V_160 ) )
F_197 ( F_204 ( V_534 ) ) ;
}
int F_216 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_537 * V_538 = V_211 ;
struct V_539 V_540 = {
. V_476 = V_538 -> V_476 ,
. V_488 = V_538 -> V_488 ,
. V_541 = V_538 -> V_108 ,
. V_20 = V_106
} ;
return F_217 ( V_17 , & V_540 , V_213 ) ;
}
static int F_218 ( struct V_18 * V_19 ,
struct V_158 * V_459 ,
T_5 V_476 )
{
int V_22 = - V_85 ;
struct V_76 * V_77 = F_219 ( V_19 ) ;
if ( V_459 == V_77 -> V_17 -> V_23 . V_121 ) {
V_22 = (* V_77 -> V_35 -> V_542 )( V_77 , ( int ) V_476 ) ;
} else if ( V_77 -> V_35 -> V_543 )
V_22 = V_77 -> V_35 -> V_543 ( V_77 , V_459 , V_476 ) ;
if ( ! V_22 )
F_190 ( & V_77 -> V_39 , V_459 , V_476 ) ;
return V_22 ;
}
static int F_220 ( struct V_18 * V_19 ,
struct V_158 * V_459 ,
T_5 V_476 )
{
int V_22 = - V_85 ;
struct V_46 * V_47 = F_221 ( V_19 ) ;
if ( V_47 -> V_35 -> V_543 )
V_22 = V_47 -> V_35 -> V_543 ( V_47 , V_459 , V_476 ) ;
if ( ! V_22 )
F_190 ( V_19 , V_459 , V_476 ) ;
return V_22 ;
}
int F_222 ( struct V_48 * V_49 ,
struct V_158 * V_459 ,
T_5 V_476 )
{
int V_22 = - V_85 ;
struct V_18 * V_19 = & V_49 -> V_39 ;
if ( V_49 -> V_35 -> V_543 )
V_22 = V_49 -> V_35 -> V_543 ( V_49 , V_459 , V_476 ) ;
if ( ! V_22 )
F_190 ( V_19 , V_459 , V_476 ) ;
return V_22 ;
}
int F_223 ( struct V_16 * V_17 , void * V_211 ,
struct V_212 * V_213 )
{
struct V_544 * V_545 = V_211 ;
struct V_18 * V_19 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_19 = F_21 ( V_17 , V_545 -> V_541 , V_545 -> V_20 ) ;
if ( ! V_19 ) {
V_22 = - V_243 ;
goto V_40;
}
if ( ! V_19 -> V_65 ) {
V_22 = - V_85 ;
goto V_40;
}
V_22 = F_126 ( V_19 , V_213 -> V_254 ,
( T_1 T_4 * ) ( unsigned long ) ( V_545 -> V_283 ) ,
( T_5 T_4 * ) ( unsigned long ) ( V_545 -> V_284 ) ,
& V_545 -> V_285 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_217 ( struct V_16 * V_17 , void * V_211 ,
struct V_212 * V_213 )
{
struct V_539 * V_545 = V_211 ;
struct V_18 * V_546 ;
struct V_18 * V_547 ;
struct V_158 * V_459 ;
int V_1 , V_22 = - V_85 ;
struct V_18 * V_534 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_546 = F_21 ( V_17 , V_545 -> V_541 , V_545 -> V_20 ) ;
if ( ! V_546 ) {
V_22 = - V_243 ;
goto V_40;
}
if ( ! V_546 -> V_65 )
goto V_40;
for ( V_1 = 0 ; V_1 < V_546 -> V_65 -> V_259 ; V_1 ++ )
if ( V_546 -> V_65 -> V_65 [ V_1 ] -> V_39 . V_27 == V_545 -> V_488 )
break;
if ( V_1 == V_546 -> V_65 -> V_259 )
goto V_40;
V_547 = F_21 ( V_17 , V_545 -> V_488 ,
V_462 ) ;
if ( ! V_547 ) {
V_22 = - V_243 ;
goto V_40;
}
V_459 = F_224 ( V_547 ) ;
if ( ! F_213 ( V_459 , V_545 -> V_476 , & V_534 ) )
goto V_40;
switch ( V_546 -> type ) {
case V_106 :
V_22 = F_218 ( V_546 , V_459 ,
V_545 -> V_476 ) ;
break;
case V_62 :
V_22 = F_220 ( V_546 , V_459 , V_545 -> V_476 ) ;
break;
case V_138 :
V_22 = F_222 ( F_225 ( V_546 ) ,
V_459 , V_545 -> V_476 ) ;
break;
}
F_215 ( V_459 , V_534 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_226 ( struct V_76 * V_77 ,
struct V_127 * V_128 )
{
int V_1 ;
if ( F_22 ( V_77 -> V_128 ) )
return - V_85 ;
for ( V_1 = 0 ; V_1 < V_271 ; V_1 ++ ) {
if ( V_77 -> V_272 [ V_1 ] == 0 ) {
V_77 -> V_272 [ V_1 ] = V_128 -> V_39 . V_27 ;
return 0 ;
}
}
return - V_64 ;
}
int F_227 ( struct V_46 * V_47 ,
int V_244 )
{
V_47 -> V_244 = V_244 ;
V_47 -> V_72 = F_178 ( V_244 , sizeof( V_548 ) * 3 ,
V_26 ) ;
if ( ! V_47 -> V_72 ) {
V_47 -> V_244 = 0 ;
return - V_64 ;
}
return 0 ;
}
int F_228 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_549 * V_550 = V_211 ;
struct V_46 * V_47 ;
void * V_551 , * V_552 , * V_553 ;
int V_530 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_47 = F_119 ( V_17 , V_550 -> V_224 ) ;
if ( ! V_47 ) {
V_22 = - V_243 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_554 == NULL ) {
V_22 = - V_455 ;
goto V_40;
}
if ( V_550 -> V_244 != V_47 -> V_244 ) {
V_22 = - V_85 ;
goto V_40;
}
V_530 = V_550 -> V_244 * ( sizeof( V_548 ) ) ;
V_551 = V_47 -> V_72 ;
if ( F_179 ( V_551 , ( void T_4 * ) ( unsigned long ) V_550 -> V_555 , V_530 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_552 = V_551 + V_530 ;
if ( F_179 ( V_552 , ( void T_4 * ) ( unsigned long ) V_550 -> V_556 , V_530 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_553 = V_552 + V_530 ;
if ( F_179 ( V_553 , ( void T_4 * ) ( unsigned long ) V_550 -> V_557 , V_530 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_47 -> V_35 -> V_554 ( V_47 , V_551 , V_552 , V_553 , 0 , V_47 -> V_244 ) ;
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_229 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_549 * V_550 = V_211 ;
struct V_46 * V_47 ;
void * V_551 , * V_552 , * V_553 ;
int V_530 ;
int V_22 = 0 ;
if ( ! F_59 ( V_17 , V_226 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_47 = F_119 ( V_17 , V_550 -> V_224 ) ;
if ( ! V_47 ) {
V_22 = - V_243 ;
goto V_40;
}
if ( V_550 -> V_244 != V_47 -> V_244 ) {
V_22 = - V_85 ;
goto V_40;
}
V_530 = V_550 -> V_244 * ( sizeof( V_548 ) ) ;
V_551 = V_47 -> V_72 ;
if ( F_131 ( ( void T_4 * ) ( unsigned long ) V_550 -> V_555 , V_551 , V_530 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_552 = V_551 + V_530 ;
if ( F_131 ( ( void T_4 * ) ( unsigned long ) V_550 -> V_556 , V_552 , V_530 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_553 = V_552 + V_530 ;
if ( F_131 ( ( void T_4 * ) ( unsigned long ) V_550 -> V_557 , V_553 , V_530 ) ) {
V_22 = - V_230 ;
goto V_40;
}
V_40:
F_51 ( V_17 ) ;
return V_22 ;
}
int F_230 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_558 * V_559 = V_211 ;
struct V_46 * V_47 ;
struct V_32 * V_33 = NULL ;
struct V_560 * V_561 = NULL ;
int V_22 = - V_85 ;
if ( V_559 -> V_262 & ~ V_562 ||
V_559 -> V_563 != 0 )
return - V_85 ;
if ( ( V_559 -> V_262 & V_564 ) && ! V_17 -> V_23 . V_565 )
return - V_85 ;
V_47 = F_119 ( V_17 , V_559 -> V_224 ) ;
if ( ! V_47 )
return - V_243 ;
F_120 ( V_47 , V_47 -> V_52 ) ;
if ( V_47 -> V_52 -> V_33 == NULL ) {
V_22 = - V_566 ;
goto V_40;
}
if ( V_47 -> V_35 -> V_559 == NULL )
goto V_40;
V_33 = F_32 ( V_17 , V_559 -> V_223 ) ;
if ( ! V_33 ) {
V_22 = - V_243 ;
goto V_40;
}
if ( V_47 -> V_73 ) {
const struct V_567 * V_73 = V_47 -> V_52 -> V_73 ;
V_22 = F_140 ( V_73 -> V_246 , V_73 -> V_248 ,
V_73 -> V_303 , V_73 -> V_304 , V_33 ) ;
} else {
V_22 = F_148 ( V_47 , V_47 -> V_245 , V_47 -> V_247 , & V_47 -> V_79 , V_33 ) ;
}
if ( V_22 )
goto V_40;
if ( V_47 -> V_52 -> V_33 -> V_314 != V_33 -> V_314 ) {
F_73 ( L_108 ) ;
V_22 = - V_85 ;
goto V_40;
}
if ( V_559 -> V_262 & V_568 ) {
V_561 = F_181 ( sizeof *V_561 , V_26 ) ;
if ( ! V_561 ) {
V_22 = - V_64 ;
goto V_40;
}
V_561 -> V_569 . V_39 . type = V_570 ;
V_561 -> V_569 . V_39 . V_494 = sizeof( V_561 -> V_569 ) ;
V_561 -> V_569 . V_571 = V_559 -> V_571 ;
V_22 = F_231 ( V_17 , V_213 , & V_561 -> V_39 , & V_561 -> V_569 . V_39 ) ;
if ( V_22 ) {
F_62 ( V_561 ) ;
goto V_40;
}
}
V_47 -> V_52 -> V_156 = V_47 -> V_52 -> V_33 ;
V_22 = V_47 -> V_35 -> V_559 ( V_47 , V_33 , V_561 , V_559 -> V_262 ) ;
if ( V_22 ) {
if ( V_559 -> V_262 & V_568 )
F_232 ( V_17 , & V_561 -> V_39 ) ;
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
F_122 ( V_47 ) ;
return V_22 ;
}
void F_233 ( struct V_16 * V_17 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_127 * V_128 ;
struct V_76 * V_77 ;
F_49 (plane, dev)
if ( V_49 -> V_35 -> V_572 )
V_49 -> V_35 -> V_572 ( V_49 ) ;
F_46 (crtc, dev)
if ( V_47 -> V_35 -> V_572 )
V_47 -> V_35 -> V_572 ( V_47 ) ;
F_90 (encoder, dev)
if ( V_128 -> V_35 -> V_572 )
V_128 -> V_35 -> V_572 ( V_128 ) ;
F_11 ( & V_17 -> V_23 . V_61 ) ;
F_117 (connector, dev)
if ( V_77 -> V_35 -> V_572 )
V_77 -> V_35 -> V_572 ( V_77 ) ;
F_13 ( & V_17 -> V_23 . V_61 ) ;
}
int F_234 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_573 * args = V_211 ;
T_3 V_426 , V_574 , V_530 ;
if ( ! V_17 -> V_575 -> V_576 )
return - V_455 ;
if ( ! args -> V_307 || ! args -> V_308 || ! args -> V_358 )
return - V_85 ;
V_426 = F_235 ( args -> V_358 , 8 ) ;
if ( ! V_426 || V_426 > 0xffffffffU / args -> V_307 )
return - V_85 ;
V_574 = V_426 * args -> V_307 ;
if ( args -> V_308 > 0xffffffffU / V_574 )
return - V_85 ;
V_530 = args -> V_308 * V_574 ;
if ( F_236 ( V_530 ) == 0 )
return - V_85 ;
args -> V_344 = 0 ;
args -> V_370 = 0 ;
args -> V_530 = 0 ;
return V_17 -> V_575 -> V_576 ( V_213 , V_17 , args ) ;
}
int F_237 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_577 * args = V_211 ;
if ( ! V_17 -> V_575 -> V_578 )
return - V_455 ;
return V_17 -> V_575 -> V_578 ( V_213 , V_17 , args -> V_344 , & args -> V_579 ) ;
}
int F_238 ( struct V_16 * V_17 ,
void * V_211 , struct V_212 * V_213 )
{
struct V_580 * args = V_211 ;
if ( ! V_17 -> V_575 -> V_581 )
return - V_455 ;
return V_17 -> V_575 -> V_581 ( V_213 , V_17 , args -> V_344 ) ;
}
void F_239 ( T_1 V_13 , unsigned int * V_359 ,
int * V_358 )
{
switch ( V_13 ) {
case V_361 :
case V_371 :
case V_372 :
* V_359 = 8 ;
* V_358 = 8 ;
break;
case V_362 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
* V_359 = 15 ;
* V_358 = 16 ;
break;
case V_363 :
case V_388 :
* V_359 = 16 ;
* V_358 = 16 ;
break;
case V_364 :
case V_389 :
* V_359 = 24 ;
* V_358 = 24 ;
break;
case V_365 :
case V_390 :
case V_391 :
case V_392 :
* V_359 = 24 ;
* V_358 = 32 ;
break;
case V_366 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
* V_359 = 30 ;
* V_358 = 32 ;
break;
case V_341 :
case V_393 :
case V_394 :
case V_395 :
* V_359 = 32 ;
* V_358 = 32 ;
break;
default:
F_73 ( L_109 ,
F_9 ( V_13 ) ) ;
* V_359 = 0 ;
* V_358 = 0 ;
break;
}
}
int F_169 ( T_1 V_13 )
{
switch ( V_13 ) {
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
return 3 ;
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
return 2 ;
default:
return 1 ;
}
}
int F_170 ( T_1 V_13 , int V_49 )
{
unsigned int V_359 ;
int V_358 ;
if ( V_49 >= F_169 ( V_13 ) )
return 0 ;
switch ( V_13 ) {
case V_403 :
case V_404 :
case V_405 :
case V_406 :
return 2 ;
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
return V_49 ? 2 : 1 ;
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
return 1 ;
default:
F_239 ( V_13 , & V_359 , & V_358 ) ;
return V_358 >> 3 ;
}
}
int F_167 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_416 :
case V_417 :
case V_414 :
case V_415 :
return 4 ;
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_420 :
case V_421 :
case V_418 :
case V_419 :
return 2 ;
default:
return 1 ;
}
}
int F_168 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_414 :
case V_415 :
return 4 ;
case V_418 :
case V_419 :
case V_408 :
case V_409 :
return 2 ;
default:
return 1 ;
}
}
int F_240 ( int V_307 , T_1 V_13 , int V_49 )
{
if ( V_49 >= F_169 ( V_13 ) )
return 0 ;
if ( V_49 == 0 )
return V_307 ;
return V_307 / F_167 ( V_13 ) ;
}
int F_241 ( int V_308 , T_1 V_13 , int V_49 )
{
if ( V_49 >= F_169 ( V_13 ) )
return 0 ;
if ( V_49 == 0 )
return V_308 ;
return V_308 / F_168 ( V_13 ) ;
}
unsigned int F_242 ( unsigned int V_326 ,
unsigned int V_582 )
{
if ( V_326 & ~ V_582 ) {
V_326 ^= F_149 ( V_583 ) | F_149 ( V_584 ) ;
V_326 = ( V_326 & V_585 ) |
F_149 ( ( F_243 ( V_326 & V_586 ) + 1 ) % 4 ) ;
}
return V_326 ;
}
void F_244 ( struct V_16 * V_17 )
{
F_245 ( & V_17 -> V_23 . V_61 ) ;
F_54 ( & V_17 -> V_23 . V_281 ) ;
F_245 ( & V_17 -> V_23 . V_24 ) ;
F_245 ( & V_17 -> V_23 . V_36 ) ;
F_245 ( & V_17 -> V_23 . V_498 ) ;
F_25 ( & V_17 -> V_23 . V_43 ) ;
F_25 ( & V_17 -> V_23 . V_66 ) ;
F_25 ( & V_17 -> V_23 . V_117 ) ;
F_25 ( & V_17 -> V_23 . V_133 ) ;
F_25 ( & V_17 -> V_23 . V_465 ) ;
F_25 ( & V_17 -> V_23 . V_500 ) ;
F_25 ( & V_17 -> V_23 . V_140 ) ;
F_246 ( & V_17 -> V_23 . V_25 ) ;
F_246 ( & V_17 -> V_23 . V_587 ) ;
F_3 ( & V_17 -> V_23 . V_105 ) ;
F_45 ( V_17 ) ;
F_100 ( V_17 ) ;
F_51 ( V_17 ) ;
V_17 -> V_23 . V_41 = 0 ;
V_17 -> V_23 . V_118 = 0 ;
V_17 -> V_23 . V_67 = 0 ;
V_17 -> V_23 . V_134 = 0 ;
V_17 -> V_23 . V_143 = 0 ;
V_17 -> V_23 . V_141 = 0 ;
}
void F_247 ( struct V_16 * V_17 )
{
struct V_76 * V_77 , * V_588 ;
struct V_46 * V_47 , * V_589 ;
struct V_127 * V_128 , * V_590 ;
struct V_32 * V_33 , * V_591 ;
struct V_158 * V_459 , * V_479 ;
struct V_493 * V_495 , * V_501 ;
struct V_48 * V_49 , * V_592 ;
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
F_183 ( V_17 , V_459 ) ;
}
F_79 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_197 ( V_495 ) ;
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
F_248 ( & V_17 -> V_23 . V_587 ) ;
F_248 ( & V_17 -> V_23 . V_25 ) ;
F_63 ( & V_17 -> V_23 . V_281 ) ;
}
struct V_158 * F_249 ( struct V_16 * V_17 ,
unsigned int V_582 )
{
static const struct V_466 V_467 [] = {
{ V_593 , L_110 } ,
{ V_327 , L_111 } ,
{ V_594 , L_112 } ,
{ V_328 , L_113 } ,
{ V_583 , L_114 } ,
{ V_584 , L_115 } ,
} ;
return F_184 ( V_17 , 0 , L_116 ,
V_467 , F_2 ( V_467 ) ,
V_582 ) ;
}
static void F_250 ( struct V_44 * V_44 )
{
struct V_595 * V_596 = F_29 ( V_44 , struct V_595 , V_37 ) ;
struct V_16 * V_17 = V_596 -> V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_18 ( & V_17 -> V_23 . V_587 , V_596 -> V_27 ) ;
F_13 ( & V_17 -> V_23 . V_24 ) ;
F_62 ( V_596 ) ;
}
void F_78 ( struct V_16 * V_17 ,
struct V_595 * V_596 )
{
F_37 ( & V_596 -> V_37 , F_250 ) ;
}
struct V_595 * F_251 ( struct V_16 * V_17 ,
char V_597 [ 8 ] )
{
struct V_595 * V_596 ;
int V_27 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
F_252 (&dev->mode_config.tile_idr, tg, id) {
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
struct V_595 * F_253 ( struct V_16 * V_17 ,
char V_597 [ 8 ] )
{
struct V_595 * V_596 ;
int V_22 ;
V_596 = F_181 ( sizeof( * V_596 ) , V_26 ) ;
if ( ! V_596 )
return F_171 ( - V_64 ) ;
F_24 ( & V_596 -> V_37 ) ;
memcpy ( V_596 -> V_598 , V_597 , 8 ) ;
V_596 -> V_17 = V_17 ;
F_11 ( & V_17 -> V_23 . V_24 ) ;
V_22 = F_12 ( & V_17 -> V_23 . V_587 , V_596 , 1 , 0 , V_26 ) ;
if ( V_22 >= 0 ) {
V_596 -> V_27 = V_22 ;
} else {
F_62 ( V_596 ) ;
V_596 = F_171 ( V_22 ) ;
}
F_13 ( & V_17 -> V_23 . V_24 ) ;
return V_596 ;
}
