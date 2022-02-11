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
bool V_21 ,
void (* F_11)( struct V_22 * V_22 ) )
{
int V_23 ;
F_12 ( & V_17 -> V_24 . V_25 ) ;
V_23 = F_13 ( & V_17 -> V_24 . V_26 , V_21 ? V_19 : NULL , 1 , 0 , V_27 ) ;
if ( V_23 >= 0 ) {
V_19 -> V_28 = V_23 ;
V_19 -> type = V_20 ;
if ( F_11 ) {
V_19 -> V_29 = F_11 ;
F_14 ( & V_19 -> V_30 ) ;
}
}
F_15 ( & V_17 -> V_24 . V_25 ) ;
return V_23 < 0 ? V_23 : 0 ;
}
int F_16 ( struct V_16 * V_17 ,
struct V_18 * V_19 , T_1 V_20 )
{
return F_10 ( V_17 , V_19 , V_20 , true , NULL ) ;
}
static void F_17 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
F_12 ( & V_17 -> V_24 . V_25 ) ;
F_18 ( & V_17 -> V_24 . V_26 , V_19 , V_19 -> V_28 ) ;
F_15 ( & V_17 -> V_24 . V_25 ) ;
}
void F_19 ( struct V_16 * V_17 ,
struct V_18 * V_31 )
{
F_12 ( & V_17 -> V_24 . V_25 ) ;
if ( V_31 -> V_28 ) {
F_20 ( & V_17 -> V_24 . V_26 , V_31 -> V_28 ) ;
V_31 -> V_28 = 0 ;
}
F_15 ( & V_17 -> V_24 . V_25 ) ;
}
static struct V_18 * F_21 ( struct V_16 * V_17 ,
T_1 V_28 , T_1 type )
{
struct V_18 * V_19 = NULL ;
F_12 ( & V_17 -> V_24 . V_25 ) ;
V_19 = F_22 ( & V_17 -> V_24 . V_26 , V_28 ) ;
if ( V_19 && type != V_32 && V_19 -> type != type )
V_19 = NULL ;
if ( V_19 && V_19 -> V_28 != V_28 )
V_19 = NULL ;
if ( V_19 && V_19 -> V_29 ) {
if ( ! F_23 ( & V_19 -> V_30 ) )
V_19 = NULL ;
}
F_15 ( & V_17 -> V_24 . V_25 ) ;
return V_19 ;
}
struct V_18 * F_24 ( struct V_16 * V_17 ,
T_1 V_28 , T_1 type )
{
struct V_18 * V_19 = NULL ;
V_19 = F_21 ( V_17 , V_28 , type ) ;
return V_19 ;
}
void F_25 ( struct V_18 * V_19 )
{
if ( V_19 -> V_29 ) {
F_26 ( L_7 , V_19 -> V_28 , F_27 ( & V_19 -> V_30 . V_30 ) ) ;
F_28 ( & V_19 -> V_30 , V_19 -> V_29 ) ;
}
}
void F_29 ( struct V_18 * V_19 )
{
if ( V_19 -> V_29 ) {
F_26 ( L_7 , V_19 -> V_28 , F_27 ( & V_19 -> V_30 . V_30 ) ) ;
F_30 ( & V_19 -> V_30 ) ;
}
}
static void F_31 ( struct V_22 * V_22 )
{
struct V_33 * V_34 =
F_32 ( V_22 , struct V_33 , V_35 . V_30 ) ;
struct V_16 * V_17 = V_34 -> V_17 ;
F_19 ( V_17 , & V_34 -> V_35 ) ;
V_34 -> V_36 -> V_37 ( V_34 ) ;
}
int F_33 ( struct V_16 * V_17 , struct V_33 * V_34 ,
const struct V_38 * V_36 )
{
int V_23 ;
F_34 ( & V_34 -> V_39 ) ;
V_34 -> V_17 = V_17 ;
V_34 -> V_36 = V_36 ;
V_23 = F_10 ( V_17 , & V_34 -> V_35 , V_40 ,
false , F_31 ) ;
if ( V_23 )
goto V_41;
F_12 ( & V_17 -> V_24 . V_42 ) ;
V_17 -> V_24 . V_43 ++ ;
F_35 ( & V_34 -> V_44 , & V_17 -> V_24 . V_45 ) ;
F_15 ( & V_17 -> V_24 . V_42 ) ;
F_17 ( V_17 , & V_34 -> V_35 ) ;
V_41:
return V_23 ;
}
struct V_33 * F_36 ( struct V_16 * V_17 ,
T_1 V_28 )
{
struct V_18 * V_19 ;
struct V_33 * V_34 = NULL ;
V_19 = F_21 ( V_17 , V_28 , V_40 ) ;
if ( V_19 )
V_34 = F_37 ( V_19 ) ;
return V_34 ;
}
void F_38 ( struct V_33 * V_34 )
{
struct V_16 * V_17 ;
if ( ! V_34 )
return;
V_17 = V_34 -> V_17 ;
F_19 ( V_17 , & V_34 -> V_35 ) ;
}
void F_39 ( struct V_33 * V_34 )
{
struct V_16 * V_17 = V_34 -> V_17 ;
F_12 ( & V_17 -> V_24 . V_42 ) ;
F_40 ( & V_34 -> V_44 ) ;
V_17 -> V_24 . V_43 -- ;
F_15 ( & V_17 -> V_24 . V_42 ) ;
}
void F_41 ( struct V_33 * V_34 )
{
struct V_16 * V_17 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 V_51 ;
int V_23 ;
if ( ! V_34 )
return;
V_17 = V_34 -> V_17 ;
F_42 ( ! F_43 ( & V_34 -> V_39 ) ) ;
if ( F_44 ( V_34 ) > 1 ) {
F_45 ( V_17 ) ;
F_46 (crtc, dev) {
if ( V_47 -> V_52 -> V_34 == V_34 ) {
memset ( & V_51 , 0 , sizeof( struct V_50 ) ) ;
V_51 . V_47 = V_47 ;
V_51 . V_34 = NULL ;
V_23 = F_47 ( & V_51 ) ;
if ( V_23 )
F_48 ( L_8 , V_47 ) ;
}
}
F_49 (plane, dev) {
if ( V_49 -> V_34 == V_34 )
F_50 ( V_49 ) ;
}
F_51 ( V_17 ) ;
}
F_52 ( V_34 ) ;
}
static unsigned int F_53 ( struct V_16 * V_17 )
{
unsigned int V_53 = 0 ;
struct V_46 * V_54 ;
F_46 (tmp, dev) {
V_53 ++ ;
}
return V_53 ;
}
int F_54 ( struct V_16 * V_17 , struct V_46 * V_47 ,
struct V_48 * V_52 ,
struct V_48 * V_55 ,
const struct V_56 * V_36 ,
const char * V_11 , ... )
{
struct V_57 * V_58 = & V_17 -> V_24 ;
int V_23 ;
F_42 ( V_52 && V_52 -> type != V_59 ) ;
F_42 ( V_55 && V_55 -> type != V_60 ) ;
V_47 -> V_17 = V_17 ;
V_47 -> V_36 = V_36 ;
F_55 ( & V_47 -> V_61 ) ;
V_23 = F_16 ( V_17 , & V_47 -> V_35 , V_62 ) ;
if ( V_23 )
return V_23 ;
if ( V_11 ) {
T_2 V_63 ;
va_start ( V_63 , V_11 ) ;
V_47 -> V_11 = F_56 ( V_27 , V_11 , V_63 ) ;
va_end ( V_63 ) ;
} else {
V_47 -> V_11 = F_57 ( V_27 , L_9 ,
F_53 ( V_17 ) ) ;
}
if ( ! V_47 -> V_11 ) {
F_19 ( V_17 , & V_47 -> V_35 ) ;
return - V_64 ;
}
V_47 -> V_35 . V_65 = & V_47 -> V_65 ;
F_58 ( & V_47 -> V_44 , & V_58 -> V_66 ) ;
V_58 -> V_67 ++ ;
V_47 -> V_52 = V_52 ;
V_47 -> V_55 = V_55 ;
if ( V_52 )
V_52 -> V_68 = 1 << F_59 ( V_47 ) ;
if ( V_55 )
V_55 -> V_68 = 1 << F_59 ( V_47 ) ;
if ( F_60 ( V_17 , V_69 ) ) {
F_61 ( & V_47 -> V_35 , V_58 -> V_70 , 0 ) ;
F_61 ( & V_47 -> V_35 , V_58 -> V_71 , 0 ) ;
}
return 0 ;
}
void F_62 ( struct V_46 * V_47 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
F_63 ( V_47 -> V_72 ) ;
V_47 -> V_72 = NULL ;
F_64 ( & V_47 -> V_61 ) ;
F_19 ( V_17 , & V_47 -> V_35 ) ;
F_40 ( & V_47 -> V_44 ) ;
V_17 -> V_24 . V_67 -- ;
F_42 ( V_47 -> V_73 && ! V_47 -> V_36 -> V_74 ) ;
if ( V_47 -> V_73 && V_47 -> V_36 -> V_74 )
V_47 -> V_36 -> V_74 ( V_47 , V_47 -> V_73 ) ;
F_63 ( V_47 -> V_11 ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
}
unsigned int F_59 ( struct V_46 * V_47 )
{
unsigned int V_75 = 0 ;
struct V_46 * V_54 ;
F_46 (tmp, crtc->dev) {
if ( V_54 == V_47 )
return V_75 ;
V_75 ++ ;
}
F_65 () ;
}
static void F_66 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
F_40 ( & V_79 -> V_44 ) ;
F_67 ( V_77 -> V_17 , V_79 ) ;
}
int F_68 ( struct V_80 * V_81 ,
const T_3 * V_82 ,
unsigned int V_83 )
{
T_3 * V_84 = NULL ;
if ( ! V_82 && V_83 )
return - V_85 ;
if ( V_82 && V_83 ) {
V_84 = F_69 ( V_82 , sizeof( * V_82 ) * V_83 ,
V_27 ) ;
if ( ! V_84 )
return - V_64 ;
}
F_63 ( V_81 -> V_86 ) ;
V_81 -> V_86 = V_84 ;
V_81 -> V_87 = V_83 ;
return 0 ;
}
static void F_70 ( struct V_76 * V_77 )
{
struct V_88 * V_79 = & V_77 -> V_89 ;
char * V_90 = NULL ;
if ( F_71 ( V_77 -> V_11 , & V_90 ) )
return;
if ( ! F_72 ( V_90 ,
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
F_73 ( L_13 , V_77 -> V_11 , V_92 ) ;
V_77 -> V_91 = V_79 -> V_91 ;
}
F_74 ( L_14 ,
V_77 -> V_11 ,
V_79 -> V_96 , V_79 -> V_97 ,
V_79 -> V_98 ? V_79 -> V_99 : 60 ,
V_79 -> V_100 ? L_15 : L_16 ,
V_79 -> V_101 ? L_17 : L_16 ,
V_79 -> V_102 ? L_18 : L_16 ) ;
}
static void F_75 ( struct V_22 * V_22 )
{
struct V_76 * V_77 =
F_32 ( V_22 , struct V_76 , V_35 . V_30 ) ;
struct V_16 * V_17 = V_77 -> V_17 ;
F_19 ( V_17 , & V_77 -> V_35 ) ;
V_77 -> V_36 -> V_37 ( V_77 ) ;
}
int F_76 ( struct V_16 * V_17 ,
struct V_76 * V_77 ,
const struct V_103 * V_36 ,
int V_104 )
{
struct V_57 * V_58 = & V_17 -> V_24 ;
int V_23 ;
struct V_3 * V_105 =
& V_2 [ V_104 ] . V_3 ;
F_45 ( V_17 ) ;
V_23 = F_10 ( V_17 , & V_77 -> V_35 ,
V_106 ,
false , F_75 ) ;
if ( V_23 )
goto V_107;
V_77 -> V_35 . V_65 = & V_77 -> V_65 ;
V_77 -> V_17 = V_17 ;
V_77 -> V_36 = V_36 ;
V_77 -> V_108 = F_77 ( & V_58 -> V_105 , 0 , 0 , V_27 ) ;
if ( V_77 -> V_108 < 0 ) {
V_23 = V_77 -> V_108 ;
goto V_109;
}
V_77 -> V_104 = V_104 ;
V_77 -> V_110 =
F_77 ( V_105 , 1 , 0 , V_27 ) ;
if ( V_77 -> V_110 < 0 ) {
V_23 = V_77 -> V_110 ;
goto V_111;
}
V_77 -> V_11 =
F_57 ( V_27 , L_19 ,
V_2 [ V_104 ] . V_11 ,
V_77 -> V_110 ) ;
if ( ! V_77 -> V_11 ) {
V_23 = - V_64 ;
goto V_112;
}
F_34 ( & V_77 -> V_113 ) ;
F_34 ( & V_77 -> V_114 ) ;
V_77 -> V_115 = NULL ;
V_77 -> V_5 = V_116 ;
F_70 ( V_77 ) ;
F_58 ( & V_77 -> V_44 , & V_58 -> V_117 ) ;
V_58 -> V_118 ++ ;
if ( V_104 != V_119 )
F_61 ( & V_77 -> V_35 ,
V_58 -> V_120 ,
0 ) ;
F_61 ( & V_77 -> V_35 ,
V_58 -> V_121 , 0 ) ;
if ( F_60 ( V_17 , V_69 ) ) {
F_61 ( & V_77 -> V_35 , V_58 -> V_122 , 0 ) ;
}
V_77 -> V_123 = NULL ;
V_112:
if ( V_23 )
F_78 ( V_105 , V_77 -> V_110 ) ;
V_111:
if ( V_23 )
F_78 ( & V_58 -> V_105 , V_77 -> V_108 ) ;
V_109:
if ( V_23 )
F_19 ( V_17 , & V_77 -> V_35 ) ;
V_107:
F_51 ( V_17 ) ;
return V_23 ;
}
void F_79 ( struct V_76 * V_77 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
struct V_78 * V_79 , * V_124 ;
if ( V_77 -> V_125 ) {
F_80 ( V_17 , V_77 -> V_125 ) ;
V_77 -> V_125 = NULL ;
}
F_81 (mode, t, &connector->probed_modes, head)
F_66 ( V_77 , V_79 ) ;
F_81 (mode, t, &connector->modes, head)
F_66 ( V_77 , V_79 ) ;
F_78 ( & V_2 [ V_77 -> V_104 ] . V_3 ,
V_77 -> V_110 ) ;
F_78 ( & V_17 -> V_24 . V_105 ,
V_77 -> V_108 ) ;
F_63 ( V_77 -> V_126 . V_86 ) ;
F_19 ( V_17 , & V_77 -> V_35 ) ;
F_63 ( V_77 -> V_11 ) ;
V_77 -> V_11 = NULL ;
F_40 ( & V_77 -> V_44 ) ;
V_17 -> V_24 . V_118 -- ;
F_42 ( V_77 -> V_73 && ! V_77 -> V_36 -> V_74 ) ;
if ( V_77 -> V_73 && V_77 -> V_36 -> V_74 )
V_77 -> V_36 -> V_74 ( V_77 ,
V_77 -> V_73 ) ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
}
int F_82 ( struct V_76 * V_77 )
{
int V_23 ;
V_23 = F_83 ( V_77 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_84 ( V_77 ) ;
if ( V_23 ) {
F_85 ( V_77 ) ;
return V_23 ;
}
F_17 ( V_77 -> V_17 , & V_77 -> V_35 ) ;
return 0 ;
}
void F_86 ( struct V_76 * V_77 )
{
F_85 ( V_77 ) ;
F_87 ( V_77 ) ;
}
int F_88 ( struct V_16 * V_17 )
{
struct V_76 * V_77 ;
int V_23 ;
F_12 ( & V_17 -> V_24 . V_61 ) ;
F_89 (connector, dev) {
V_23 = F_82 ( V_77 ) ;
if ( V_23 )
goto V_127;
}
F_15 ( & V_17 -> V_24 . V_61 ) ;
return 0 ;
V_127:
F_15 ( & V_17 -> V_24 . V_61 ) ;
F_90 ( V_17 ) ;
return V_23 ;
}
void F_90 ( struct V_16 * V_17 )
{
struct V_76 * V_77 ;
F_91 (connector, &dev->mode_config.connector_list, head)
F_86 ( V_77 ) ;
}
int F_92 ( struct V_16 * V_17 ,
struct V_128 * V_129 ,
const struct V_130 * V_36 ,
int V_131 , const char * V_11 , ... )
{
int V_23 ;
F_45 ( V_17 ) ;
V_23 = F_16 ( V_17 , & V_129 -> V_35 , V_132 ) ;
if ( V_23 )
goto V_107;
V_129 -> V_17 = V_17 ;
V_129 -> V_131 = V_131 ;
V_129 -> V_36 = V_36 ;
if ( V_11 ) {
T_2 V_63 ;
va_start ( V_63 , V_11 ) ;
V_129 -> V_11 = F_56 ( V_27 , V_11 , V_63 ) ;
va_end ( V_63 ) ;
} else {
V_129 -> V_11 = F_57 ( V_27 , L_19 ,
V_133 [ V_131 ] . V_11 ,
V_129 -> V_35 . V_28 ) ;
}
if ( ! V_129 -> V_11 ) {
V_23 = - V_64 ;
goto V_109;
}
F_58 ( & V_129 -> V_44 , & V_17 -> V_24 . V_134 ) ;
V_17 -> V_24 . V_135 ++ ;
V_109:
if ( V_23 )
F_19 ( V_17 , & V_129 -> V_35 ) ;
V_107:
F_51 ( V_17 ) ;
return V_23 ;
}
unsigned int F_93 ( struct V_128 * V_129 )
{
unsigned int V_75 = 0 ;
struct V_128 * V_54 ;
F_94 (tmp, encoder->dev) {
if ( V_54 == V_129 )
return V_75 ;
V_75 ++ ;
}
F_65 () ;
}
void F_95 ( struct V_128 * V_129 )
{
struct V_16 * V_17 = V_129 -> V_17 ;
F_45 ( V_17 ) ;
F_19 ( V_17 , & V_129 -> V_35 ) ;
F_63 ( V_129 -> V_11 ) ;
F_40 ( & V_129 -> V_44 ) ;
V_17 -> V_24 . V_135 -- ;
F_51 ( V_17 ) ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
}
static unsigned int F_96 ( struct V_16 * V_17 )
{
unsigned int V_53 = 0 ;
struct V_48 * V_54 ;
F_49 (tmp, dev) {
V_53 ++ ;
}
return V_53 ;
}
int F_97 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_68 ,
const struct V_136 * V_36 ,
const T_1 * V_82 , unsigned int V_137 ,
enum V_138 type ,
const char * V_11 , ... )
{
struct V_57 * V_58 = & V_17 -> V_24 ;
int V_23 ;
V_23 = F_16 ( V_17 , & V_49 -> V_35 , V_139 ) ;
if ( V_23 )
return V_23 ;
F_55 ( & V_49 -> V_61 ) ;
V_49 -> V_35 . V_65 = & V_49 -> V_65 ;
V_49 -> V_17 = V_17 ;
V_49 -> V_36 = V_36 ;
V_49 -> V_140 = F_98 ( V_137 , sizeof( T_1 ) ,
V_27 ) ;
if ( ! V_49 -> V_140 ) {
F_74 ( L_20 ) ;
F_19 ( V_17 , & V_49 -> V_35 ) ;
return - V_64 ;
}
if ( V_11 ) {
T_2 V_63 ;
va_start ( V_63 , V_11 ) ;
V_49 -> V_11 = F_56 ( V_27 , V_11 , V_63 ) ;
va_end ( V_63 ) ;
} else {
V_49 -> V_11 = F_57 ( V_27 , L_21 ,
F_96 ( V_17 ) ) ;
}
if ( ! V_49 -> V_11 ) {
F_63 ( V_49 -> V_140 ) ;
F_19 ( V_17 , & V_49 -> V_35 ) ;
return - V_64 ;
}
memcpy ( V_49 -> V_140 , V_82 , V_137 * sizeof( T_1 ) ) ;
V_49 -> V_137 = V_137 ;
V_49 -> V_68 = V_68 ;
V_49 -> type = type ;
F_58 ( & V_49 -> V_44 , & V_58 -> V_141 ) ;
V_58 -> V_142 ++ ;
if ( V_49 -> type == V_143 )
V_58 -> V_144 ++ ;
F_61 ( & V_49 -> V_35 ,
V_58 -> V_145 ,
V_49 -> type ) ;
if ( F_60 ( V_17 , V_69 ) ) {
F_61 ( & V_49 -> V_35 , V_58 -> V_146 , 0 ) ;
F_61 ( & V_49 -> V_35 , V_58 -> V_122 , 0 ) ;
F_61 ( & V_49 -> V_35 , V_58 -> V_147 , 0 ) ;
F_61 ( & V_49 -> V_35 , V_58 -> V_148 , 0 ) ;
F_61 ( & V_49 -> V_35 , V_58 -> V_149 , 0 ) ;
F_61 ( & V_49 -> V_35 , V_58 -> V_150 , 0 ) ;
F_61 ( & V_49 -> V_35 , V_58 -> V_151 , 0 ) ;
F_61 ( & V_49 -> V_35 , V_58 -> V_152 , 0 ) ;
F_61 ( & V_49 -> V_35 , V_58 -> V_153 , 0 ) ;
F_61 ( & V_49 -> V_35 , V_58 -> V_154 , 0 ) ;
}
return 0 ;
}
int F_99 ( struct V_16 * V_17 , struct V_48 * V_49 ,
unsigned long V_68 ,
const struct V_136 * V_36 ,
const T_1 * V_82 , unsigned int V_137 ,
bool V_155 )
{
enum V_138 type ;
type = V_155 ? V_59 : V_143 ;
return F_97 ( V_17 , V_49 , V_68 , V_36 ,
V_82 , V_137 , type , NULL ) ;
}
void F_100 ( struct V_48 * V_49 )
{
struct V_16 * V_17 = V_49 -> V_17 ;
F_45 ( V_17 ) ;
F_63 ( V_49 -> V_140 ) ;
F_19 ( V_17 , & V_49 -> V_35 ) ;
F_101 ( F_43 ( & V_49 -> V_44 ) ) ;
F_40 ( & V_49 -> V_44 ) ;
V_17 -> V_24 . V_142 -- ;
if ( V_49 -> type == V_143 )
V_17 -> V_24 . V_144 -- ;
F_51 ( V_17 ) ;
F_42 ( V_49 -> V_73 && ! V_49 -> V_36 -> V_74 ) ;
if ( V_49 -> V_73 && V_49 -> V_36 -> V_74 )
V_49 -> V_36 -> V_74 ( V_49 , V_49 -> V_73 ) ;
F_63 ( V_49 -> V_11 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
}
unsigned int F_102 ( struct V_48 * V_49 )
{
unsigned int V_75 = 0 ;
struct V_48 * V_54 ;
F_49 (tmp, plane->dev) {
if ( V_54 == V_49 )
return V_75 ;
V_75 ++ ;
}
F_65 () ;
}
struct V_48 *
F_103 ( struct V_16 * V_17 , int V_156 )
{
struct V_48 * V_49 ;
unsigned int V_1 = 0 ;
F_49 (plane, dev) {
if ( V_1 == V_156 )
return V_49 ;
V_1 ++ ;
}
return NULL ;
}
void F_50 ( struct V_48 * V_49 )
{
int V_23 ;
if ( ! V_49 -> V_34 )
return;
V_49 -> V_157 = V_49 -> V_34 ;
V_23 = V_49 -> V_36 -> V_158 ( V_49 ) ;
if ( V_23 ) {
F_48 ( L_22 ) ;
V_49 -> V_157 = NULL ;
return;
}
F_52 ( V_49 -> V_157 ) ;
V_49 -> V_157 = NULL ;
V_49 -> V_34 = NULL ;
V_49 -> V_47 = NULL ;
}
static int F_104 ( struct V_16 * V_17 )
{
struct V_159 * V_160 ;
V_160 = F_105 ( V_17 , V_161 |
V_162 ,
L_23 , 0 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_120 = V_160 ;
V_160 = F_106 ( V_17 , 0 ,
L_24 , V_163 ,
F_2 ( V_163 ) ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_121 = V_160 ;
V_160 = F_105 ( V_17 ,
V_161 |
V_162 ,
L_25 , 0 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_164 = V_160 ;
V_160 = F_105 ( V_17 ,
V_161 |
V_162 ,
L_26 , 0 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_165 = V_160 ;
V_160 = F_106 ( V_17 , V_162 ,
L_27 , V_166 ,
F_2 ( V_166 ) ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_145 = V_160 ;
V_160 = F_107 ( V_17 , V_167 ,
L_28 , 0 , V_168 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_151 = V_160 ;
V_160 = F_107 ( V_17 , V_167 ,
L_29 , 0 , V_168 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_152 = V_160 ;
V_160 = F_107 ( V_17 , V_167 ,
L_30 , 0 , V_168 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_153 = V_160 ;
V_160 = F_107 ( V_17 , V_167 ,
L_31 , 0 , V_168 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_154 = V_160 ;
V_160 = F_108 ( V_17 , V_167 ,
L_32 , V_169 , V_170 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_147 = V_160 ;
V_160 = F_108 ( V_17 , V_167 ,
L_33 , V_169 , V_170 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_148 = V_160 ;
V_160 = F_107 ( V_17 , V_167 ,
L_34 , 0 , V_170 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_149 = V_160 ;
V_160 = F_107 ( V_17 , V_167 ,
L_35 , 0 , V_170 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_150 = V_160 ;
V_160 = F_109 ( V_17 , V_167 ,
L_36 , V_40 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_146 = V_160 ;
V_160 = F_109 ( V_17 , V_167 ,
L_37 , V_62 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_122 = V_160 ;
V_160 = F_110 ( V_17 , V_167 ,
L_38 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_70 = V_160 ;
V_160 = F_105 ( V_17 ,
V_167 | V_161 ,
L_39 , 0 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_71 = V_160 ;
V_160 = F_105 ( V_17 ,
V_161 ,
L_40 , 0 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_171 = V_160 ;
V_160 = F_107 ( V_17 ,
V_162 ,
L_41 , 0 , V_168 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_172 = V_160 ;
V_160 = F_105 ( V_17 ,
V_161 ,
L_42 , 0 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_173 = V_160 ;
V_160 = F_105 ( V_17 ,
V_161 ,
L_43 , 0 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_174 = V_160 ;
V_160 = F_107 ( V_17 ,
V_162 ,
L_44 , 0 , V_168 ) ;
if ( ! V_160 )
return - V_64 ;
V_17 -> V_24 . V_175 = V_160 ;
return 0 ;
}
int F_111 ( struct V_16 * V_17 )
{
struct V_159 * V_176 ;
struct V_159 * V_177 ;
if ( V_17 -> V_24 . V_178 )
return 0 ;
V_176 =
F_106 ( V_17 , 0 ,
L_45 ,
V_179 ,
F_2 ( V_179 ) ) ;
V_17 -> V_24 . V_178 = V_176 ;
V_177 = F_106 ( V_17 , V_162 ,
L_46 ,
V_180 ,
F_2 ( V_180 ) ) ;
V_17 -> V_24 . V_181 = V_177 ;
return 0 ;
}
int F_112 ( struct V_16 * V_17 ,
unsigned int V_182 ,
const char * const V_114 [] )
{
struct V_159 * V_183 ;
struct V_159 * V_184 ;
unsigned int V_1 ;
if ( V_17 -> V_24 . V_185 )
return 0 ;
V_183 = F_106 ( V_17 , 0 ,
L_45 ,
V_186 ,
F_2 ( V_186 ) ) ;
if ( ! V_183 )
goto V_187;
V_17 -> V_24 . V_185 = V_183 ;
V_184 =
F_106 ( V_17 , V_162 ,
L_46 ,
V_188 ,
F_2 ( V_188 ) ) ;
if ( ! V_184 )
goto V_187;
V_17 -> V_24 . V_189 = V_184 ;
V_17 -> V_24 . V_190 =
F_107 ( V_17 , 0 , L_47 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_190 )
goto V_187;
V_17 -> V_24 . V_191 =
F_107 ( V_17 , 0 , L_48 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_191 )
goto V_187;
V_17 -> V_24 . V_192 =
F_107 ( V_17 , 0 , L_49 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_192 )
goto V_187;
V_17 -> V_24 . V_193 =
F_107 ( V_17 , 0 , L_50 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_193 )
goto V_187;
V_17 -> V_24 . V_194 =
F_105 ( V_17 , V_195 ,
L_51 , V_182 ) ;
if ( ! V_17 -> V_24 . V_194 )
goto V_187;
for ( V_1 = 0 ; V_1 < V_182 ; V_1 ++ )
F_113 ( V_17 -> V_24 . V_194 , V_1 ,
V_1 , V_114 [ V_1 ] ) ;
V_17 -> V_24 . V_196 =
F_107 ( V_17 , 0 , L_52 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_196 )
goto V_187;
V_17 -> V_24 . V_197 =
F_107 ( V_17 , 0 , L_53 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_197 )
goto V_187;
V_17 -> V_24 . V_198 =
F_107 ( V_17 , 0 , L_54 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_198 )
goto V_187;
V_17 -> V_24 . V_199 =
F_107 ( V_17 , 0 , L_55 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_199 )
goto V_187;
V_17 -> V_24 . V_200 =
F_107 ( V_17 , 0 , L_56 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_200 )
goto V_187;
V_17 -> V_24 . V_201 =
F_107 ( V_17 , 0 , L_57 , 0 , 100 ) ;
if ( ! V_17 -> V_24 . V_201 )
goto V_187;
return 0 ;
V_187:
return - V_64 ;
}
int F_114 ( struct V_16 * V_17 )
{
struct V_159 * V_202 ;
if ( V_17 -> V_24 . V_203 )
return 0 ;
V_202 =
F_106 ( V_17 , 0 , L_58 ,
V_204 ,
F_2 ( V_204 ) ) ;
V_17 -> V_24 . V_203 = V_202 ;
return 0 ;
}
int F_115 ( struct V_16 * V_17 )
{
if ( V_17 -> V_24 . V_205 )
return 0 ;
V_17 -> V_24 . V_205 =
F_106 ( V_17 , 0 , L_59 ,
V_206 ,
F_2 ( V_206 ) ) ;
if ( V_17 -> V_24 . V_205 == NULL )
return - V_64 ;
return 0 ;
}
int F_116 ( struct V_16 * V_17 )
{
struct V_159 * V_207 ;
if ( V_17 -> V_24 . V_208 )
return 0 ;
V_207 =
F_106 ( V_17 , V_162 ,
L_60 ,
V_209 ,
F_2 ( V_209 ) ) ;
V_17 -> V_24 . V_208 = V_207 ;
return 0 ;
}
int F_117 ( struct V_16 * V_17 )
{
if ( V_17 -> V_24 . V_210 && V_17 -> V_24 . V_211 )
return 0 ;
V_17 -> V_24 . V_210 =
F_107 ( V_17 , V_162 , L_61 , 0 , 0xffffffff ) ;
V_17 -> V_24 . V_211 =
F_107 ( V_17 , V_162 , L_62 , 0 , 0xffffffff ) ;
if ( V_17 -> V_24 . V_210 == NULL ||
V_17 -> V_24 . V_211 == NULL )
return - V_64 ;
return 0 ;
}
int F_118 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_215 * V_216 = V_212 ;
struct V_217 * V_218 ;
struct V_33 * V_34 ;
struct V_76 * V_77 ;
struct V_46 * V_47 ;
struct V_128 * V_129 ;
int V_23 = 0 ;
int V_219 = 0 ;
int V_220 = 0 ;
int V_221 = 0 ;
int V_222 = 0 ;
int V_223 = 0 ;
T_1 T_4 * V_224 ;
T_1 T_4 * V_225 ;
T_1 T_4 * V_108 ;
T_1 T_4 * V_226 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
F_12 ( & V_214 -> V_228 ) ;
F_119 (lh, &file_priv->fbs)
V_221 ++ ;
if ( V_216 -> V_229 >= V_221 ) {
V_223 = 0 ;
V_224 = ( T_1 T_4 * ) ( unsigned long ) V_216 -> V_230 ;
F_91 (fb, &file_priv->fbs, filp_head) {
if ( F_120 ( V_34 -> V_35 . V_28 , V_224 + V_223 ) ) {
F_15 ( & V_214 -> V_228 ) ;
return - V_231 ;
}
V_223 ++ ;
}
}
V_216 -> V_229 = V_221 ;
F_15 ( & V_214 -> V_228 ) ;
F_12 ( & V_17 -> V_24 . V_61 ) ;
F_46 (crtc, dev)
V_220 ++ ;
F_89 (connector, dev)
V_219 ++ ;
F_94 (encoder, dev)
V_222 ++ ;
V_216 -> V_232 = V_17 -> V_24 . V_232 ;
V_216 -> V_233 = V_17 -> V_24 . V_233 ;
V_216 -> V_234 = V_17 -> V_24 . V_234 ;
V_216 -> V_235 = V_17 -> V_24 . V_235 ;
if ( V_216 -> V_236 >= V_220 ) {
V_223 = 0 ;
V_225 = ( T_1 T_4 * ) ( unsigned long ) V_216 -> V_237 ;
F_46 (crtc, dev) {
if ( F_120 ( V_47 -> V_35 . V_28 , V_225 + V_223 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_223 ++ ;
}
}
V_216 -> V_236 = V_220 ;
if ( V_216 -> V_238 >= V_222 ) {
V_223 = 0 ;
V_226 = ( T_1 T_4 * ) ( unsigned long ) V_216 -> V_239 ;
F_94 (encoder, dev) {
if ( F_120 ( V_129 -> V_35 . V_28 , V_226 +
V_223 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_223 ++ ;
}
}
V_216 -> V_238 = V_222 ;
if ( V_216 -> V_240 >= V_219 ) {
V_223 = 0 ;
V_108 = ( T_1 T_4 * ) ( unsigned long ) V_216 -> V_241 ;
F_89 (connector, dev) {
if ( F_120 ( V_77 -> V_35 . V_28 ,
V_108 + V_223 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_223 ++ ;
}
}
V_216 -> V_240 = V_219 ;
V_41:
F_15 ( & V_17 -> V_24 . V_61 ) ;
return V_23 ;
}
int F_121 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_242 * V_243 = V_212 ;
struct V_46 * V_47 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_47 = F_122 ( V_17 , V_243 -> V_225 ) ;
if ( ! V_47 )
return - V_244 ;
F_123 ( V_47 , V_47 -> V_52 ) ;
V_243 -> V_245 = V_47 -> V_245 ;
if ( V_47 -> V_52 -> V_34 )
V_243 -> V_224 = V_47 -> V_52 -> V_34 -> V_35 . V_28 ;
else
V_243 -> V_224 = 0 ;
if ( V_47 -> V_73 ) {
V_243 -> V_246 = V_47 -> V_52 -> V_73 -> V_247 >> 16 ;
V_243 -> V_248 = V_47 -> V_52 -> V_73 -> V_249 >> 16 ;
if ( V_47 -> V_73 -> V_250 ) {
F_124 ( & V_243 -> V_79 , & V_47 -> V_73 -> V_79 ) ;
V_243 -> V_251 = 1 ;
} else {
V_243 -> V_251 = 0 ;
}
} else {
V_243 -> V_246 = V_47 -> V_246 ;
V_243 -> V_248 = V_47 -> V_248 ;
if ( V_47 -> V_252 ) {
F_124 ( & V_243 -> V_79 , & V_47 -> V_79 ) ;
V_243 -> V_251 = 1 ;
} else {
V_243 -> V_251 = 0 ;
}
}
F_125 ( V_47 ) ;
return 0 ;
}
static bool F_126 ( const struct V_78 * V_79 ,
const struct V_213 * V_214 )
{
if ( ! V_214 -> V_253 && F_127 ( V_79 ) )
return false ;
return true ;
}
static struct V_128 * F_128 ( struct V_76 * V_77 )
{
if ( V_77 -> V_73 )
return V_77 -> V_73 -> V_254 ;
return V_77 -> V_129 ;
}
static int F_129 ( struct V_18 * V_19 , bool V_255 ,
T_1 T_4 * V_256 , T_5 T_4 * V_257 ,
T_1 * V_258 )
{
int V_259 ;
int V_1 , V_23 , V_223 ;
V_259 = V_19 -> V_65 -> V_260 ;
if ( ! V_255 )
V_259 -= V_19 -> V_65 -> V_261 ;
if ( ( * V_258 >= V_259 ) && V_259 ) {
for ( V_1 = 0 , V_223 = 0 ; V_223 < V_259 ; V_1 ++ ) {
struct V_159 * V_160 = V_19 -> V_65 -> V_65 [ V_1 ] ;
T_5 V_262 ;
if ( ( V_160 -> V_263 & V_167 ) && ! V_255 )
continue;
V_23 = F_130 ( V_19 , V_160 , & V_262 ) ;
if ( V_23 )
return V_23 ;
if ( F_120 ( V_160 -> V_35 . V_28 , V_256 + V_223 ) )
return - V_231 ;
if ( F_120 ( V_262 , V_257 + V_223 ) )
return - V_231 ;
V_223 ++ ;
}
}
* V_258 = V_259 ;
return 0 ;
}
int F_131 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_264 * V_265 = V_212 ;
struct V_76 * V_77 ;
struct V_128 * V_129 ;
struct V_78 * V_79 ;
int V_266 = 0 ;
int V_267 = 0 ;
int V_23 = 0 ;
int V_223 = 0 ;
int V_1 ;
struct V_268 V_269 ;
struct V_268 T_4 * V_270 ;
T_1 T_4 * V_271 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
memset ( & V_269 , 0 , sizeof( struct V_268 ) ) ;
F_12 ( & V_17 -> V_24 . V_61 ) ;
V_77 = F_132 ( V_17 , V_265 -> V_108 ) ;
if ( ! V_77 ) {
V_23 = - V_244 ;
goto V_107;
}
for ( V_1 = 0 ; V_1 < V_272 ; V_1 ++ )
if ( V_77 -> V_273 [ V_1 ] != 0 )
V_267 ++ ;
if ( V_265 -> V_274 == 0 ) {
V_77 -> V_36 -> V_275 ( V_77 ,
V_17 -> V_24 . V_234 ,
V_17 -> V_24 . V_232 ) ;
}
F_91 (mode, &connector->modes, head)
if ( F_126 ( V_79 , V_214 ) )
V_266 ++ ;
V_265 -> V_108 = V_77 -> V_35 . V_28 ;
V_265 -> V_104 = V_77 -> V_104 ;
V_265 -> V_110 = V_77 -> V_110 ;
V_265 -> V_276 = V_77 -> V_126 . V_277 ;
V_265 -> V_278 = V_77 -> V_126 . V_279 ;
V_265 -> V_280 = V_77 -> V_126 . V_8 ;
V_265 -> V_281 = V_77 -> V_5 ;
F_133 ( & V_17 -> V_24 . V_282 , NULL ) ;
V_129 = F_128 ( V_77 ) ;
if ( V_129 )
V_265 -> V_226 = V_129 -> V_35 . V_28 ;
else
V_265 -> V_226 = 0 ;
if ( ( V_265 -> V_274 >= V_266 ) && V_266 ) {
V_223 = 0 ;
V_270 = (struct V_268 T_4 * ) ( unsigned long ) V_265 -> V_283 ;
F_91 (mode, &connector->modes, head) {
if ( ! F_126 ( V_79 , V_214 ) )
continue;
F_124 ( & V_269 , V_79 ) ;
if ( F_134 ( V_270 + V_223 ,
& V_269 , sizeof( V_269 ) ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_223 ++ ;
}
}
V_265 -> V_274 = V_266 ;
V_23 = F_129 ( & V_77 -> V_35 , V_214 -> V_255 ,
( T_1 T_4 * ) ( unsigned long ) ( V_265 -> V_284 ) ,
( T_5 T_4 * ) ( unsigned long ) ( V_265 -> V_285 ) ,
& V_265 -> V_286 ) ;
if ( V_23 )
goto V_41;
if ( ( V_265 -> V_238 >= V_267 ) && V_267 ) {
V_223 = 0 ;
V_271 = ( T_1 T_4 * ) ( unsigned long ) ( V_265 -> V_287 ) ;
for ( V_1 = 0 ; V_1 < V_272 ; V_1 ++ ) {
if ( V_77 -> V_273 [ V_1 ] != 0 ) {
if ( F_120 ( V_77 -> V_273 [ V_1 ] ,
V_271 + V_223 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_223 ++ ;
}
}
}
V_265 -> V_238 = V_267 ;
V_41:
F_135 ( & V_17 -> V_24 . V_282 ) ;
F_136 ( V_77 ) ;
V_107:
F_15 ( & V_17 -> V_24 . V_61 ) ;
return V_23 ;
}
static struct V_46 * F_137 ( struct V_128 * V_129 )
{
struct V_76 * V_77 ;
struct V_16 * V_17 = V_129 -> V_17 ;
bool V_288 = false ;
F_89 (connector, dev) {
if ( ! V_77 -> V_73 )
continue;
V_288 = true ;
if ( V_77 -> V_73 -> V_254 != V_129 )
continue;
return V_77 -> V_73 -> V_47 ;
}
if ( V_288 )
return NULL ;
return V_129 -> V_47 ;
}
int F_138 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_289 * V_290 = V_212 ;
struct V_128 * V_129 ;
struct V_46 * V_47 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_129 = F_139 ( V_17 , V_290 -> V_226 ) ;
if ( ! V_129 )
return - V_244 ;
F_133 ( & V_17 -> V_24 . V_282 , NULL ) ;
V_47 = F_137 ( V_129 ) ;
if ( V_47 )
V_290 -> V_225 = V_47 -> V_35 . V_28 ;
else
V_290 -> V_225 = 0 ;
F_135 ( & V_17 -> V_24 . V_282 ) ;
V_290 -> V_131 = V_129 -> V_131 ;
V_290 -> V_226 = V_129 -> V_35 . V_28 ;
V_290 -> V_68 = V_129 -> V_68 ;
V_290 -> V_291 = V_129 -> V_291 ;
return 0 ;
}
int F_140 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_292 * V_293 = V_212 ;
struct V_57 * V_58 ;
struct V_48 * V_49 ;
T_1 T_4 * V_294 ;
int V_223 = 0 ;
unsigned V_295 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_58 = & V_17 -> V_24 ;
if ( V_214 -> V_296 )
V_295 = V_58 -> V_142 ;
else
V_295 = V_58 -> V_144 ;
if ( V_295 &&
( V_293 -> V_297 >= V_295 ) ) {
V_294 = ( T_1 T_4 * ) ( unsigned long ) V_293 -> V_298 ;
F_49 (plane, dev) {
if ( V_49 -> type != V_143 &&
! V_214 -> V_296 )
continue;
if ( F_120 ( V_49 -> V_35 . V_28 , V_294 + V_223 ) )
return - V_231 ;
V_223 ++ ;
}
}
V_293 -> V_297 = V_295 ;
return 0 ;
}
int F_141 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_299 * V_293 = V_212 ;
struct V_48 * V_49 ;
T_1 T_4 * V_300 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_49 = F_142 ( V_17 , V_293 -> V_301 ) ;
if ( ! V_49 )
return - V_244 ;
F_133 ( & V_49 -> V_61 , NULL ) ;
if ( V_49 -> V_47 )
V_293 -> V_225 = V_49 -> V_47 -> V_35 . V_28 ;
else
V_293 -> V_225 = 0 ;
if ( V_49 -> V_34 )
V_293 -> V_224 = V_49 -> V_34 -> V_35 . V_28 ;
else
V_293 -> V_224 = 0 ;
F_135 ( & V_49 -> V_61 ) ;
V_293 -> V_301 = V_49 -> V_35 . V_28 ;
V_293 -> V_68 = V_49 -> V_68 ;
V_293 -> V_245 = 0 ;
if ( V_49 -> V_137 &&
( V_293 -> V_302 >= V_49 -> V_137 ) ) {
V_300 = ( T_1 T_4 * ) ( unsigned long ) V_293 -> V_303 ;
if ( F_134 ( V_300 ,
V_49 -> V_140 ,
sizeof( T_1 ) * V_49 -> V_137 ) ) {
return - V_231 ;
}
}
V_293 -> V_302 = V_49 -> V_137 ;
return 0 ;
}
int F_143 ( const struct V_48 * V_49 , T_3 V_13 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_49 -> V_137 ; V_1 ++ ) {
if ( V_13 == V_49 -> V_140 [ V_1 ] )
return 0 ;
}
return - V_85 ;
}
static int F_144 ( T_1 V_247 , T_1 V_249 ,
T_1 V_304 , T_1 V_305 ,
const struct V_33 * V_34 )
{
unsigned int V_306 , V_307 ;
V_306 = V_34 -> V_308 << 16 ;
V_307 = V_34 -> V_309 << 16 ;
if ( V_304 > V_306 ||
V_247 > V_306 - V_304 ||
V_305 > V_307 ||
V_249 > V_307 - V_305 ) {
F_74 ( L_63
L_64 ,
V_304 >> 16 , ( ( V_304 & 0xffff ) * 15625 ) >> 10 ,
V_305 >> 16 , ( ( V_305 & 0xffff ) * 15625 ) >> 10 ,
V_247 >> 16 , ( ( V_247 & 0xffff ) * 15625 ) >> 10 ,
V_249 >> 16 , ( ( V_249 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_310 ;
}
return 0 ;
}
static int F_145 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_33 * V_34 ,
T_6 V_311 , T_6 V_312 ,
T_1 V_313 , T_1 V_314 ,
T_1 V_247 , T_1 V_249 ,
T_1 V_304 , T_1 V_305 )
{
int V_23 = 0 ;
if ( ! V_34 ) {
V_49 -> V_157 = V_49 -> V_34 ;
V_23 = V_49 -> V_36 -> V_158 ( V_49 ) ;
if ( ! V_23 ) {
V_49 -> V_47 = NULL ;
V_49 -> V_34 = NULL ;
} else {
V_49 -> V_157 = NULL ;
}
goto V_41;
}
if ( ! ( V_49 -> V_68 & F_146 ( V_47 ) ) ) {
F_74 ( L_65 ) ;
V_23 = - V_85 ;
goto V_41;
}
V_23 = F_143 ( V_49 , V_34 -> V_315 ) ;
if ( V_23 ) {
F_74 ( L_66 ,
F_9 ( V_34 -> V_315 ) ) ;
goto V_41;
}
if ( V_313 > V_170 ||
V_311 > V_170 - ( T_6 ) V_313 ||
V_314 > V_170 ||
V_312 > V_170 - ( T_6 ) V_314 ) {
F_74 ( L_67 ,
V_313 , V_314 , V_311 , V_312 ) ;
V_23 = - V_316 ;
goto V_41;
}
V_23 = F_144 ( V_247 , V_249 , V_304 , V_305 , V_34 ) ;
if ( V_23 )
goto V_41;
V_49 -> V_157 = V_49 -> V_34 ;
V_23 = V_49 -> V_36 -> V_317 ( V_49 , V_47 , V_34 ,
V_311 , V_312 , V_313 , V_314 ,
V_247 , V_249 , V_304 , V_305 ) ;
if ( ! V_23 ) {
V_49 -> V_47 = V_47 ;
V_49 -> V_34 = V_34 ;
V_34 = NULL ;
} else {
V_49 -> V_157 = NULL ;
}
V_41:
if ( V_34 )
F_52 ( V_34 ) ;
if ( V_49 -> V_157 )
F_52 ( V_49 -> V_157 ) ;
V_49 -> V_157 = NULL ;
return V_23 ;
}
static int F_147 ( struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_33 * V_34 ,
T_6 V_311 , T_6 V_312 ,
T_1 V_313 , T_1 V_314 ,
T_1 V_247 , T_1 V_249 ,
T_1 V_304 , T_1 V_305 )
{
int V_23 ;
F_45 ( V_49 -> V_17 ) ;
V_23 = F_145 ( V_49 , V_47 , V_34 ,
V_311 , V_312 , V_313 , V_314 ,
V_247 , V_249 , V_304 , V_305 ) ;
F_51 ( V_49 -> V_17 ) ;
return V_23 ;
}
int F_148 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_318 * V_319 = V_212 ;
struct V_48 * V_49 ;
struct V_46 * V_47 = NULL ;
struct V_33 * V_34 = NULL ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_49 = F_142 ( V_17 , V_319 -> V_301 ) ;
if ( ! V_49 ) {
F_74 ( L_68 ,
V_319 -> V_301 ) ;
return - V_244 ;
}
if ( V_319 -> V_224 ) {
V_34 = F_36 ( V_17 , V_319 -> V_224 ) ;
if ( ! V_34 ) {
F_74 ( L_69 ,
V_319 -> V_224 ) ;
return - V_244 ;
}
V_47 = F_122 ( V_17 , V_319 -> V_225 ) ;
if ( ! V_47 ) {
F_74 ( L_70 ,
V_319 -> V_225 ) ;
return - V_244 ;
}
}
return F_147 ( V_49 , V_47 , V_34 ,
V_319 -> V_311 , V_319 -> V_312 ,
V_319 -> V_313 , V_319 -> V_314 ,
V_319 -> V_247 , V_319 -> V_249 ,
V_319 -> V_304 , V_319 -> V_305 ) ;
}
int F_47 ( struct V_50 * V_51 )
{
struct V_46 * V_47 = V_51 -> V_47 ;
struct V_33 * V_34 ;
struct V_46 * V_54 ;
int V_23 ;
F_46 (tmp, crtc->dev)
V_54 -> V_52 -> V_157 = V_54 -> V_52 -> V_34 ;
V_34 = V_51 -> V_34 ;
V_23 = V_47 -> V_36 -> V_320 ( V_51 ) ;
if ( V_23 == 0 ) {
V_47 -> V_52 -> V_47 = V_47 ;
V_47 -> V_52 -> V_34 = V_34 ;
}
F_46 (tmp, crtc->dev) {
if ( V_54 -> V_52 -> V_34 )
F_149 ( V_54 -> V_52 -> V_34 ) ;
if ( V_54 -> V_52 -> V_157 )
F_52 ( V_54 -> V_52 -> V_157 ) ;
V_54 -> V_52 -> V_157 = NULL ;
}
return V_23 ;
}
void F_150 ( const struct V_78 * V_79 ,
int * V_321 , int * V_322 )
{
struct V_78 V_323 ;
F_151 ( & V_323 , V_79 ) ;
F_152 ( & V_323 , V_324 ) ;
* V_321 = V_323 . V_325 ;
* V_322 = V_323 . V_326 ;
}
int F_153 ( const struct V_46 * V_47 ,
int V_246 , int V_248 ,
const struct V_78 * V_79 ,
const struct V_33 * V_34 )
{
int V_321 , V_322 ;
F_150 ( V_79 , & V_321 , & V_322 ) ;
if ( V_47 -> V_73 &&
V_47 -> V_52 -> V_73 -> V_327 & ( F_154 ( V_328 ) |
F_154 ( V_329 ) ) )
F_155 ( V_321 , V_322 ) ;
return F_144 ( V_246 << 16 , V_248 << 16 ,
V_321 << 16 , V_322 << 16 , V_34 ) ;
}
int F_156 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_57 * V_58 = & V_17 -> V_24 ;
struct V_242 * V_330 = V_212 ;
struct V_46 * V_47 ;
struct V_76 * * V_331 = NULL , * V_77 ;
struct V_33 * V_34 = NULL ;
struct V_78 * V_79 = NULL ;
struct V_50 V_51 ;
T_1 T_4 * V_332 ;
int V_23 ;
int V_1 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
if ( V_330 -> V_246 & 0xffff0000 || V_330 -> V_248 & 0xffff0000 )
return - V_316 ;
F_45 ( V_17 ) ;
V_47 = F_122 ( V_17 , V_330 -> V_225 ) ;
if ( ! V_47 ) {
F_74 ( L_71 , V_330 -> V_225 ) ;
V_23 = - V_244 ;
goto V_41;
}
F_74 ( L_72 , V_47 -> V_35 . V_28 , V_47 -> V_11 ) ;
if ( V_330 -> V_251 ) {
if ( V_330 -> V_224 == - 1 ) {
if ( ! V_47 -> V_52 -> V_34 ) {
F_74 ( L_73 ) ;
V_23 = - V_85 ;
goto V_41;
}
V_34 = V_47 -> V_52 -> V_34 ;
F_149 ( V_34 ) ;
} else {
V_34 = F_36 ( V_17 , V_330 -> V_224 ) ;
if ( ! V_34 ) {
F_74 ( L_74 ,
V_330 -> V_224 ) ;
V_23 = - V_244 ;
goto V_41;
}
}
V_79 = F_157 ( V_17 ) ;
if ( ! V_79 ) {
V_23 = - V_64 ;
goto V_41;
}
V_23 = F_158 ( V_79 , & V_330 -> V_79 ) ;
if ( V_23 ) {
F_74 ( L_75 ) ;
goto V_41;
}
if ( ! V_47 -> V_52 -> V_333 ) {
V_23 = F_143 ( V_47 -> V_52 ,
V_34 -> V_315 ) ;
if ( V_23 ) {
F_74 ( L_66 ,
F_9 ( V_34 -> V_315 ) ) ;
goto V_41;
}
}
V_23 = F_153 ( V_47 , V_330 -> V_246 , V_330 -> V_248 ,
V_79 , V_34 ) ;
if ( V_23 )
goto V_41;
}
if ( V_330 -> V_240 == 0 && V_79 ) {
F_74 ( L_76 ) ;
V_23 = - V_85 ;
goto V_41;
}
if ( V_330 -> V_240 > 0 && ( ! V_79 || ! V_34 ) ) {
F_74 ( L_77 ,
V_330 -> V_240 ) ;
V_23 = - V_85 ;
goto V_41;
}
if ( V_330 -> V_240 > 0 ) {
T_3 V_334 ;
if ( V_330 -> V_240 > V_58 -> V_118 ) {
V_23 = - V_85 ;
goto V_41;
}
V_331 = F_98 ( V_330 -> V_240 ,
sizeof( struct V_76 * ) ,
V_27 ) ;
if ( ! V_331 ) {
V_23 = - V_64 ;
goto V_41;
}
for ( V_1 = 0 ; V_1 < V_330 -> V_240 ; V_1 ++ ) {
V_331 [ V_1 ] = NULL ;
V_332 = ( T_1 T_4 * ) ( unsigned long ) V_330 -> V_332 ;
if ( F_159 ( V_334 , & V_332 [ V_1 ] ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_77 = F_132 ( V_17 , V_334 ) ;
if ( ! V_77 ) {
F_74 ( L_78 ,
V_334 ) ;
V_23 = - V_244 ;
goto V_41;
}
F_74 ( L_79 ,
V_77 -> V_35 . V_28 ,
V_77 -> V_11 ) ;
V_331 [ V_1 ] = V_77 ;
}
}
V_51 . V_47 = V_47 ;
V_51 . V_246 = V_330 -> V_246 ;
V_51 . V_248 = V_330 -> V_248 ;
V_51 . V_79 = V_79 ;
V_51 . V_335 = V_331 ;
V_51 . V_336 = V_330 -> V_240 ;
V_51 . V_34 = V_34 ;
V_23 = F_47 ( & V_51 ) ;
V_41:
if ( V_34 )
F_52 ( V_34 ) ;
if ( V_331 ) {
for ( V_1 = 0 ; V_1 < V_330 -> V_240 ; V_1 ++ ) {
if ( V_331 [ V_1 ] )
F_136 ( V_331 [ V_1 ] ) ;
}
}
F_63 ( V_331 ) ;
F_67 ( V_17 , V_79 ) ;
F_51 ( V_17 ) ;
return V_23 ;
}
static int F_160 ( struct V_46 * V_47 ,
struct V_337 * V_338 ,
struct V_213 * V_214 )
{
struct V_16 * V_17 = V_47 -> V_17 ;
struct V_33 * V_34 = NULL ;
struct V_339 V_340 = {
. V_308 = V_338 -> V_308 ,
. V_309 = V_338 -> V_309 ,
. V_315 = V_341 ,
. V_342 = { V_338 -> V_308 * 4 } ,
. V_343 = { V_338 -> V_344 } ,
} ;
T_6 V_311 , V_312 ;
T_1 V_313 = 0 , V_314 = 0 ;
T_1 V_304 = 0 , V_305 = 0 ;
int V_23 = 0 ;
F_101 ( ! V_47 -> V_55 ) ;
F_42 ( V_47 -> V_55 -> V_47 != V_47 && V_47 -> V_55 -> V_47 != NULL ) ;
if ( V_338 -> V_263 & V_345 ) {
if ( V_338 -> V_344 ) {
V_34 = F_161 ( V_17 , & V_340 , V_214 ) ;
if ( F_162 ( V_34 ) ) {
F_74 ( L_80 ) ;
return F_163 ( V_34 ) ;
}
} else {
V_34 = NULL ;
}
} else {
V_34 = V_47 -> V_55 -> V_34 ;
if ( V_34 )
F_149 ( V_34 ) ;
}
if ( V_338 -> V_263 & V_346 ) {
V_311 = V_338 -> V_246 ;
V_312 = V_338 -> V_248 ;
} else {
V_311 = V_47 -> V_347 ;
V_312 = V_47 -> V_348 ;
}
if ( V_34 ) {
V_313 = V_34 -> V_308 ;
V_314 = V_34 -> V_309 ;
V_304 = V_34 -> V_308 << 16 ;
V_305 = V_34 -> V_309 << 16 ;
}
V_23 = F_145 ( V_47 -> V_55 , V_47 , V_34 ,
V_311 , V_312 , V_313 , V_314 ,
0 , 0 , V_304 , V_305 ) ;
if ( V_23 == 0 && V_338 -> V_263 & V_346 ) {
V_47 -> V_347 = V_338 -> V_246 ;
V_47 -> V_348 = V_338 -> V_248 ;
}
return V_23 ;
}
static int F_164 ( struct V_16 * V_17 ,
struct V_337 * V_338 ,
struct V_213 * V_214 )
{
struct V_46 * V_47 ;
int V_23 = 0 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
if ( ! V_338 -> V_263 || ( ~ V_349 & V_338 -> V_263 ) )
return - V_85 ;
V_47 = F_122 ( V_17 , V_338 -> V_225 ) ;
if ( ! V_47 ) {
F_74 ( L_71 , V_338 -> V_225 ) ;
return - V_244 ;
}
F_123 ( V_47 , V_47 -> V_55 ) ;
if ( V_47 -> V_55 ) {
V_23 = F_160 ( V_47 , V_338 , V_214 ) ;
goto V_41;
}
if ( V_338 -> V_263 & V_345 ) {
if ( ! V_47 -> V_36 -> V_350 && ! V_47 -> V_36 -> V_351 ) {
V_23 = - V_352 ;
goto V_41;
}
if ( V_47 -> V_36 -> V_351 )
V_23 = V_47 -> V_36 -> V_351 ( V_47 , V_214 , V_338 -> V_344 ,
V_338 -> V_308 , V_338 -> V_309 , V_338 -> V_353 , V_338 -> V_354 ) ;
else
V_23 = V_47 -> V_36 -> V_350 ( V_47 , V_214 , V_338 -> V_344 ,
V_338 -> V_308 , V_338 -> V_309 ) ;
}
if ( V_338 -> V_263 & V_346 ) {
if ( V_47 -> V_36 -> V_355 ) {
V_23 = V_47 -> V_36 -> V_355 ( V_47 , V_338 -> V_246 , V_338 -> V_248 ) ;
} else {
V_23 = - V_231 ;
goto V_41;
}
}
V_41:
F_125 ( V_47 ) ;
return V_23 ;
}
int F_165 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_356 * V_338 = V_212 ;
struct V_337 V_357 ;
memcpy ( & V_357 , V_338 , sizeof( struct V_356 ) ) ;
V_357 . V_353 = V_357 . V_354 = 0 ;
return F_164 ( V_17 , & V_357 , V_214 ) ;
}
int F_166 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_337 * V_338 = V_212 ;
return F_164 ( V_17 , V_338 , V_214 ) ;
}
T_1 F_167 ( T_1 V_358 , T_1 V_359 )
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
F_48 ( L_81 ) ;
V_360 = V_365 ;
break;
}
return V_360 ;
}
int F_168 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_367 * V_368 = V_212 ;
struct V_339 V_369 = {} ;
int V_23 ;
V_369 . V_224 = V_368 -> V_224 ;
V_369 . V_308 = V_368 -> V_308 ;
V_369 . V_309 = V_368 -> V_309 ;
V_369 . V_342 [ 0 ] = V_368 -> V_370 ;
V_369 . V_315 = F_167 ( V_368 -> V_358 , V_368 -> V_359 ) ;
V_369 . V_343 [ 0 ] = V_368 -> V_344 ;
V_23 = F_169 ( V_17 , & V_369 , V_214 ) ;
if ( V_23 )
return V_23 ;
V_368 -> V_224 = V_369 . V_224 ;
return 0 ;
}
static int F_170 ( const struct V_339 * V_369 )
{
T_1 V_13 = V_369 -> V_315 & ~ V_15 ;
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
F_74 ( L_82 ,
F_9 ( V_369 -> V_315 ) ) ;
return - V_85 ;
}
}
static int F_171 ( const struct V_339 * V_369 )
{
int V_23 , V_424 , V_425 , V_295 , V_1 ;
V_23 = F_170 ( V_369 ) ;
if ( V_23 ) {
F_74 ( L_83 ,
F_9 ( V_369 -> V_315 ) ) ;
return V_23 ;
}
V_424 = F_172 ( V_369 -> V_315 ) ;
V_425 = F_173 ( V_369 -> V_315 ) ;
V_295 = F_174 ( V_369 -> V_315 ) ;
if ( V_369 -> V_308 == 0 || V_369 -> V_308 % V_424 ) {
F_74 ( L_84 , V_369 -> V_308 ) ;
return - V_85 ;
}
if ( V_369 -> V_309 == 0 || V_369 -> V_309 % V_425 ) {
F_74 ( L_85 , V_369 -> V_309 ) ;
return - V_85 ;
}
for ( V_1 = 0 ; V_1 < V_295 ; V_1 ++ ) {
unsigned int V_308 = V_369 -> V_308 / ( V_1 != 0 ? V_424 : 1 ) ;
unsigned int V_309 = V_369 -> V_309 / ( V_1 != 0 ? V_425 : 1 ) ;
unsigned int V_426 = F_175 ( V_369 -> V_315 , V_1 ) ;
if ( ! V_369 -> V_343 [ V_1 ] ) {
F_74 ( L_86 , V_1 ) ;
return - V_85 ;
}
if ( ( T_5 ) V_308 * V_426 > V_168 )
return - V_316 ;
if ( ( T_5 ) V_309 * V_369 -> V_342 [ V_1 ] + V_369 -> V_427 [ V_1 ] > V_168 )
return - V_316 ;
if ( V_369 -> V_342 [ V_1 ] < V_308 * V_426 ) {
F_74 ( L_87 , V_369 -> V_342 [ V_1 ] , V_1 ) ;
return - V_85 ;
}
if ( V_369 -> V_428 [ V_1 ] && ! ( V_369 -> V_263 & V_429 ) ) {
F_74 ( L_88 ,
V_369 -> V_428 [ V_1 ] , V_1 ) ;
return - V_85 ;
}
switch ( V_369 -> V_428 [ V_1 ] ) {
case V_430 :
if ( V_369 -> V_315 != V_408 ||
V_308 % 128 || V_309 % 32 ||
V_369 -> V_342 [ V_1 ] % 128 ) {
F_74 ( L_89 , V_1 ) ;
return - V_85 ;
}
break;
default:
break;
}
}
for ( V_1 = V_295 ; V_1 < 4 ; V_1 ++ ) {
if ( V_369 -> V_428 [ V_1 ] ) {
F_74 ( L_90 , V_1 ) ;
return - V_85 ;
}
if ( ! ( V_369 -> V_263 & V_429 ) )
continue;
if ( V_369 -> V_343 [ V_1 ] ) {
F_74 ( L_91 , V_1 ) ;
return - V_85 ;
}
if ( V_369 -> V_342 [ V_1 ] ) {
F_74 ( L_92 , V_1 ) ;
return - V_85 ;
}
if ( V_369 -> V_427 [ V_1 ] ) {
F_74 ( L_93 , V_1 ) ;
return - V_85 ;
}
}
return 0 ;
}
static struct V_33 *
F_161 ( struct V_16 * V_17 ,
const struct V_339 * V_369 ,
struct V_213 * V_214 )
{
struct V_57 * V_58 = & V_17 -> V_24 ;
struct V_33 * V_34 ;
int V_23 ;
if ( V_369 -> V_263 & ~ ( V_431 | V_429 ) ) {
F_74 ( L_94 , V_369 -> V_263 ) ;
return F_176 ( - V_85 ) ;
}
if ( ( V_58 -> V_235 > V_369 -> V_308 ) || ( V_369 -> V_308 > V_58 -> V_234 ) ) {
F_74 ( L_95 ,
V_369 -> V_308 , V_58 -> V_235 , V_58 -> V_234 ) ;
return F_176 ( - V_85 ) ;
}
if ( ( V_58 -> V_233 > V_369 -> V_309 ) || ( V_369 -> V_309 > V_58 -> V_232 ) ) {
F_74 ( L_96 ,
V_369 -> V_309 , V_58 -> V_233 , V_58 -> V_232 ) ;
return F_176 ( - V_85 ) ;
}
if ( V_369 -> V_263 & V_429 &&
! V_17 -> V_24 . V_432 ) {
F_74 ( L_97 ) ;
return F_176 ( - V_85 ) ;
}
V_23 = F_171 ( V_369 ) ;
if ( V_23 )
return F_176 ( V_23 ) ;
V_34 = V_17 -> V_24 . V_36 -> V_433 ( V_17 , V_214 , V_369 ) ;
if ( F_162 ( V_34 ) ) {
F_74 ( L_98 ) ;
return V_34 ;
}
return V_34 ;
}
int F_169 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_339 * V_369 = V_212 ;
struct V_33 * V_34 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_34 = F_161 ( V_17 , V_369 , V_214 ) ;
if ( F_162 ( V_34 ) )
return F_163 ( V_34 ) ;
F_74 ( L_99 , V_34 -> V_35 . V_28 ) ;
V_369 -> V_224 = V_34 -> V_35 . V_28 ;
F_12 ( & V_214 -> V_228 ) ;
F_35 ( & V_34 -> V_39 , & V_214 -> V_434 ) ;
F_15 ( & V_214 -> V_228 ) ;
return 0 ;
}
static void F_177 ( struct V_435 * V_436 )
{
struct V_437 * V_438 = F_32 ( V_436 , F_178 ( * V_438 ) , V_439 ) ;
while ( ! F_43 ( & V_438 -> V_434 ) ) {
struct V_33 * V_34 =
F_179 ( & V_438 -> V_434 , F_178 ( * V_34 ) , V_39 ) ;
F_180 ( & V_34 -> V_39 ) ;
F_41 ( V_34 ) ;
}
}
int F_181 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_33 * V_34 = NULL ;
struct V_33 * V_440 = NULL ;
T_1 * V_28 = V_212 ;
int V_441 = 0 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_34 = F_36 ( V_17 , * V_28 ) ;
if ( ! V_34 )
return - V_244 ;
F_12 ( & V_214 -> V_228 ) ;
F_91 (fbl, &file_priv->fbs, filp_head)
if ( V_34 == V_440 )
V_441 = 1 ;
if ( ! V_441 ) {
F_15 ( & V_214 -> V_228 ) ;
goto V_442;
}
F_180 ( & V_34 -> V_39 ) ;
F_15 ( & V_214 -> V_228 ) ;
F_52 ( V_34 ) ;
if ( F_44 ( V_34 ) > 1 ) {
struct V_437 V_438 ;
F_182 ( & V_438 . V_439 , F_177 ) ;
F_34 ( & V_438 . V_434 ) ;
F_58 ( & V_34 -> V_39 , & V_438 . V_434 ) ;
F_183 ( & V_438 . V_439 ) ;
F_184 ( & V_438 . V_439 ) ;
F_185 ( & V_438 . V_439 ) ;
} else
F_52 ( V_34 ) ;
return 0 ;
V_442:
F_52 ( V_34 ) ;
return - V_244 ;
}
int F_186 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_367 * V_369 = V_212 ;
struct V_33 * V_34 ;
int V_23 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_34 = F_36 ( V_17 , V_369 -> V_224 ) ;
if ( ! V_34 )
return - V_244 ;
V_369 -> V_309 = V_34 -> V_309 ;
V_369 -> V_308 = V_34 -> V_308 ;
V_369 -> V_359 = V_34 -> V_359 ;
V_369 -> V_358 = V_34 -> V_443 ;
V_369 -> V_370 = V_34 -> V_342 [ 0 ] ;
if ( V_34 -> V_36 -> V_444 ) {
if ( V_214 -> V_445 || F_187 ( V_446 ) ||
F_188 ( V_214 ) ) {
V_23 = V_34 -> V_36 -> V_444 ( V_34 , V_214 ,
& V_369 -> V_344 ) ;
} else {
V_369 -> V_344 = 0 ;
V_23 = 0 ;
}
} else {
V_23 = - V_447 ;
}
F_52 ( V_34 ) ;
return V_23 ;
}
int F_189 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_448 T_4 * V_449 ;
struct V_448 * V_450 = NULL ;
struct V_451 * V_369 = V_212 ;
struct V_33 * V_34 ;
unsigned V_263 ;
int V_452 ;
int V_23 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_34 = F_36 ( V_17 , V_369 -> V_224 ) ;
if ( ! V_34 )
return - V_244 ;
V_452 = V_369 -> V_452 ;
V_449 = (struct V_448 T_4 * ) ( unsigned long ) V_369 -> V_449 ;
if ( ! V_452 != ! V_449 ) {
V_23 = - V_85 ;
goto V_453;
}
V_263 = V_454 & V_369 -> V_263 ;
if ( V_263 & V_455 && ( V_452 % 2 ) ) {
V_23 = - V_85 ;
goto V_453;
}
if ( V_452 && V_449 ) {
if ( V_452 < 0 || V_452 > V_456 ) {
V_23 = - V_85 ;
goto V_453;
}
V_450 = F_190 ( V_452 , sizeof( * V_450 ) , V_27 ) ;
if ( ! V_450 ) {
V_23 = - V_64 ;
goto V_453;
}
V_23 = F_191 ( V_450 , V_449 ,
V_452 * sizeof( * V_450 ) ) ;
if ( V_23 ) {
V_23 = - V_231 ;
goto V_457;
}
}
if ( V_34 -> V_36 -> V_458 ) {
V_23 = V_34 -> V_36 -> V_458 ( V_34 , V_214 , V_263 , V_369 -> V_459 ,
V_450 , V_452 ) ;
} else {
V_23 = - V_460 ;
}
V_457:
F_63 ( V_450 ) ;
V_453:
F_52 ( V_34 ) ;
return V_23 ;
}
void F_192 ( struct V_213 * V_461 )
{
struct V_33 * V_34 , * V_462 ;
struct V_437 V_438 ;
F_34 ( & V_438 . V_434 ) ;
F_81 (fb, tfb, &priv->fbs, filp_head) {
if ( F_44 ( V_34 ) > 1 ) {
F_193 ( & V_34 -> V_39 , & V_438 . V_434 ) ;
} else {
F_180 ( & V_34 -> V_39 ) ;
F_52 ( V_34 ) ;
}
}
if ( ! F_43 ( & V_438 . V_434 ) ) {
F_182 ( & V_438 . V_439 , F_177 ) ;
F_183 ( & V_438 . V_439 ) ;
F_184 ( & V_438 . V_439 ) ;
F_185 ( & V_438 . V_439 ) ;
}
}
struct V_159 * F_105 ( struct V_16 * V_17 , int V_263 ,
const char * V_11 , int V_463 )
{
struct V_159 * V_464 = NULL ;
int V_23 ;
V_464 = F_194 ( sizeof( struct V_159 ) , V_27 ) ;
if ( ! V_464 )
return NULL ;
V_464 -> V_17 = V_17 ;
if ( V_463 ) {
V_464 -> V_465 = F_190 ( V_463 , sizeof( T_5 ) ,
V_27 ) ;
if ( ! V_464 -> V_465 )
goto V_466;
}
V_23 = F_16 ( V_17 , & V_464 -> V_35 , V_467 ) ;
if ( V_23 )
goto V_466;
V_464 -> V_263 = V_263 ;
V_464 -> V_463 = V_463 ;
F_34 ( & V_464 -> V_468 ) ;
if ( V_11 ) {
strncpy ( V_464 -> V_11 , V_11 , V_469 ) ;
V_464 -> V_11 [ V_469 - 1 ] = '\0' ;
}
F_58 ( & V_464 -> V_44 , & V_17 -> V_24 . V_470 ) ;
F_42 ( ! F_195 ( V_464 ) ) ;
return V_464 ;
V_466:
F_63 ( V_464 -> V_465 ) ;
F_63 ( V_464 ) ;
return NULL ;
}
struct V_159 * F_106 ( struct V_16 * V_17 , int V_263 ,
const char * V_11 ,
const struct V_471 * V_472 ,
int V_463 )
{
struct V_159 * V_464 ;
int V_1 , V_23 ;
V_263 |= V_195 ;
V_464 = F_105 ( V_17 , V_263 , V_11 , V_463 ) ;
if ( ! V_464 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_463 ; V_1 ++ ) {
V_23 = F_113 ( V_464 , V_1 ,
V_472 [ V_1 ] . type ,
V_472 [ V_1 ] . V_11 ) ;
if ( V_23 ) {
F_196 ( V_17 , V_464 ) ;
return NULL ;
}
}
return V_464 ;
}
struct V_159 * F_197 ( struct V_16 * V_17 ,
int V_263 , const char * V_11 ,
const struct V_471 * V_472 ,
int V_473 ,
T_5 V_474 )
{
struct V_159 * V_464 ;
int V_1 , V_23 , V_75 = 0 ;
int V_463 = F_198 ( V_474 ) ;
V_263 |= V_475 ;
V_464 = F_105 ( V_17 , V_263 , V_11 , V_463 ) ;
if ( ! V_464 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_473 ; V_1 ++ ) {
if ( ! ( V_474 & ( 1ULL << V_472 [ V_1 ] . type ) ) )
continue;
if ( F_42 ( V_75 >= V_463 ) ) {
F_196 ( V_17 , V_464 ) ;
return NULL ;
}
V_23 = F_113 ( V_464 , V_75 ++ ,
V_472 [ V_1 ] . type ,
V_472 [ V_1 ] . V_11 ) ;
if ( V_23 ) {
F_196 ( V_17 , V_464 ) ;
return NULL ;
}
}
return V_464 ;
}
static struct V_159 * F_199 ( struct V_16 * V_17 ,
int V_263 , const char * V_11 ,
T_5 V_476 , T_5 V_477 )
{
struct V_159 * V_464 ;
V_464 = F_105 ( V_17 , V_263 , V_11 , 2 ) ;
if ( ! V_464 )
return NULL ;
V_464 -> V_465 [ 0 ] = V_476 ;
V_464 -> V_465 [ 1 ] = V_477 ;
return V_464 ;
}
struct V_159 * F_107 ( struct V_16 * V_17 , int V_263 ,
const char * V_11 ,
T_5 V_476 , T_5 V_477 )
{
return F_199 ( V_17 , V_478 | V_263 ,
V_11 , V_476 , V_477 ) ;
}
struct V_159 * F_108 ( struct V_16 * V_17 ,
int V_263 , const char * V_11 ,
T_7 V_476 , T_7 V_477 )
{
return F_199 ( V_17 , V_479 | V_263 ,
V_11 , F_200 ( V_476 ) , F_200 ( V_477 ) ) ;
}
struct V_159 * F_109 ( struct V_16 * V_17 ,
int V_263 , const char * V_11 , T_1 type )
{
struct V_159 * V_464 ;
V_263 |= V_480 ;
if ( F_42 ( ! ( V_263 & V_167 ) ) )
return NULL ;
V_464 = F_105 ( V_17 , V_263 , V_11 , 1 ) ;
if ( ! V_464 )
return NULL ;
V_464 -> V_465 [ 0 ] = type ;
return V_464 ;
}
struct V_159 * F_110 ( struct V_16 * V_17 , int V_263 ,
const char * V_11 )
{
return F_107 ( V_17 , V_263 , V_11 , 0 , 1 ) ;
}
int F_113 ( struct V_159 * V_464 , int V_75 ,
T_5 V_481 , const char * V_11 )
{
struct V_482 * V_483 ;
if ( ! ( F_201 ( V_464 , V_195 ) ||
F_201 ( V_464 , V_475 ) ) )
return - V_85 ;
if ( F_201 ( V_464 , V_475 ) &&
( V_481 > 63 ) )
return - V_85 ;
if ( ! F_43 ( & V_464 -> V_468 ) ) {
F_91 (prop_enum, &property->enum_list, head) {
if ( V_483 -> V_481 == V_481 ) {
strncpy ( V_483 -> V_11 , V_11 , V_469 ) ;
V_483 -> V_11 [ V_469 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_483 = F_194 ( sizeof( struct V_482 ) , V_27 ) ;
if ( ! V_483 )
return - V_64 ;
strncpy ( V_483 -> V_11 , V_11 , V_469 ) ;
V_483 -> V_11 [ V_469 - 1 ] = '\0' ;
V_483 -> V_481 = V_481 ;
V_464 -> V_465 [ V_75 ] = V_481 ;
F_58 ( & V_483 -> V_44 , & V_464 -> V_468 ) ;
return 0 ;
}
void F_196 ( struct V_16 * V_17 , struct V_159 * V_464 )
{
struct V_482 * V_483 , * V_484 ;
F_81 (prop_enum, pt, &property->enum_list, head) {
F_40 ( & V_483 -> V_44 ) ;
F_63 ( V_483 ) ;
}
if ( V_464 -> V_463 )
F_63 ( V_464 -> V_465 ) ;
F_19 ( V_17 , & V_464 -> V_35 ) ;
F_40 ( & V_464 -> V_44 ) ;
F_63 ( V_464 ) ;
}
void F_61 ( struct V_18 * V_19 ,
struct V_159 * V_464 ,
T_5 V_485 )
{
int V_260 = V_19 -> V_65 -> V_260 ;
if ( V_260 == V_486 ) {
F_202 ( 1 , L_100
L_101
L_102 ,
V_19 -> type ) ;
return;
}
V_19 -> V_65 -> V_65 [ V_260 ] = V_464 ;
V_19 -> V_65 -> V_465 [ V_260 ] = V_485 ;
V_19 -> V_65 -> V_260 ++ ;
if ( V_464 -> V_263 & V_167 )
V_19 -> V_65 -> V_261 ++ ;
}
int F_203 ( struct V_18 * V_19 ,
struct V_159 * V_464 , T_5 V_262 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_19 -> V_65 -> V_260 ; V_1 ++ ) {
if ( V_19 -> V_65 -> V_65 [ V_1 ] == V_464 ) {
V_19 -> V_65 -> V_465 [ V_1 ] = V_262 ;
return 0 ;
}
}
return - V_85 ;
}
int F_130 ( struct V_18 * V_19 ,
struct V_159 * V_464 , T_5 * V_262 )
{
int V_1 ;
if ( F_60 ( V_464 -> V_17 , V_69 ) &&
! ( V_464 -> V_263 & V_162 ) )
return F_204 ( V_19 , V_464 , V_262 ) ;
for ( V_1 = 0 ; V_1 < V_19 -> V_65 -> V_260 ; V_1 ++ ) {
if ( V_19 -> V_65 -> V_65 [ V_1 ] == V_464 ) {
* V_262 = V_19 -> V_65 -> V_465 [ V_1 ] ;
return 0 ;
}
}
return - V_85 ;
}
int F_205 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_487 * V_265 = V_212 ;
struct V_159 * V_464 ;
int V_488 = 0 ;
int V_489 = 0 ;
int V_23 = 0 , V_1 ;
int V_223 ;
struct V_482 * V_483 ;
struct V_490 T_4 * V_491 ;
T_5 T_4 * V_492 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_464 = F_206 ( V_17 , V_265 -> V_493 ) ;
if ( ! V_464 ) {
V_23 = - V_244 ;
goto V_494;
}
if ( F_201 ( V_464 , V_195 ) ||
F_201 ( V_464 , V_475 ) ) {
F_91 (prop_enum, &property->enum_list, head)
V_488 ++ ;
}
V_489 = V_464 -> V_463 ;
strncpy ( V_265 -> V_11 , V_464 -> V_11 , V_469 ) ;
V_265 -> V_11 [ V_469 - 1 ] = 0 ;
V_265 -> V_263 = V_464 -> V_263 ;
if ( ( V_265 -> V_495 >= V_489 ) && V_489 ) {
V_492 = ( T_5 T_4 * ) ( unsigned long ) V_265 -> V_492 ;
for ( V_1 = 0 ; V_1 < V_489 ; V_1 ++ ) {
if ( F_134 ( V_492 + V_1 , & V_464 -> V_465 [ V_1 ] , sizeof( T_5 ) ) ) {
V_23 = - V_231 ;
goto V_494;
}
}
}
V_265 -> V_495 = V_489 ;
if ( F_201 ( V_464 , V_195 ) ||
F_201 ( V_464 , V_475 ) ) {
if ( ( V_265 -> V_496 >= V_488 ) && V_488 ) {
V_223 = 0 ;
V_491 = (struct V_490 T_4 * ) ( unsigned long ) V_265 -> V_497 ;
F_91 (prop_enum, &property->enum_list, head) {
if ( F_134 ( & V_491 [ V_223 ] . V_481 , & V_483 -> V_481 , sizeof( T_5 ) ) ) {
V_23 = - V_231 ;
goto V_494;
}
if ( F_134 ( & V_491 [ V_223 ] . V_11 ,
& V_483 -> V_11 , V_469 ) ) {
V_23 = - V_231 ;
goto V_494;
}
V_223 ++ ;
}
}
V_265 -> V_496 = V_488 ;
}
if ( F_201 ( V_464 , V_161 ) )
V_265 -> V_496 = 0 ;
V_494:
F_51 ( V_17 ) ;
return V_23 ;
}
static void F_207 ( struct V_22 * V_22 )
{
struct V_498 * V_499 =
F_32 ( V_22 , struct V_498 , V_35 . V_30 ) ;
F_12 ( & V_499 -> V_17 -> V_24 . V_500 ) ;
F_40 ( & V_499 -> V_501 ) ;
F_15 ( & V_499 -> V_17 -> V_24 . V_500 ) ;
F_19 ( V_499 -> V_17 , & V_499 -> V_35 ) ;
F_63 ( V_499 ) ;
}
struct V_498 *
F_208 ( struct V_16 * V_17 , T_8 V_502 ,
const void * V_212 )
{
struct V_498 * V_499 ;
int V_23 ;
if ( ! V_502 || V_502 > V_503 - sizeof( struct V_498 ) )
return F_176 ( - V_85 ) ;
V_499 = F_194 ( sizeof( struct V_498 ) + V_502 , V_27 ) ;
if ( ! V_499 )
return F_176 ( - V_64 ) ;
F_34 ( & V_499 -> V_504 ) ;
V_499 -> V_502 = V_502 ;
V_499 -> V_17 = V_17 ;
if ( V_212 )
memcpy ( V_499 -> V_212 , V_212 , V_502 ) ;
V_23 = F_10 ( V_17 , & V_499 -> V_35 , V_505 ,
true , F_207 ) ;
if ( V_23 ) {
F_63 ( V_499 ) ;
return F_176 ( - V_85 ) ;
}
F_12 ( & V_17 -> V_24 . V_500 ) ;
F_58 ( & V_499 -> V_501 ,
& V_17 -> V_24 . V_506 ) ;
F_15 ( & V_17 -> V_24 . V_500 ) ;
return V_499 ;
}
void F_209 ( struct V_498 * V_499 )
{
if ( ! V_499 )
return;
F_25 ( & V_499 -> V_35 ) ;
}
void F_210 ( struct V_16 * V_17 ,
struct V_213 * V_214 )
{
struct V_498 * V_499 , * V_507 ;
F_81 (blob, bt, &file_priv->blobs, head_file) {
F_180 ( & V_499 -> V_504 ) ;
F_209 ( V_499 ) ;
}
}
struct V_498 * F_211 ( struct V_498 * V_499 )
{
F_29 ( & V_499 -> V_35 ) ;
return V_499 ;
}
struct V_498 * F_212 ( struct V_16 * V_17 ,
T_1 V_28 )
{
struct V_18 * V_19 ;
struct V_498 * V_499 = NULL ;
V_19 = F_21 ( V_17 , V_28 , V_505 ) ;
if ( V_19 )
V_499 = F_213 ( V_19 ) ;
return V_499 ;
}
static int F_214 ( struct V_16 * V_17 ,
struct V_498 * * V_508 ,
T_8 V_502 ,
const void * V_212 ,
struct V_18 * V_509 ,
struct V_159 * V_510 )
{
struct V_498 * V_511 = NULL ;
struct V_498 * V_512 = NULL ;
int V_23 ;
F_42 ( V_508 == NULL ) ;
V_512 = * V_508 ;
if ( V_502 && V_212 ) {
V_511 = F_208 ( V_17 , V_502 , V_212 ) ;
if ( F_162 ( V_511 ) )
return F_163 ( V_511 ) ;
}
if ( V_509 ) {
V_23 = F_203 ( V_509 ,
V_510 ,
V_511 ?
V_511 -> V_35 . V_28 : 0 ) ;
if ( V_23 != 0 )
goto V_513;
}
F_209 ( V_512 ) ;
* V_508 = V_511 ;
return 0 ;
V_513:
F_209 ( V_511 ) ;
return V_23 ;
}
int F_215 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_514 * V_265 = V_212 ;
struct V_498 * V_499 ;
int V_23 = 0 ;
void T_4 * V_515 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_499 = F_212 ( V_17 , V_265 -> V_516 ) ;
if ( ! V_499 )
return - V_244 ;
if ( V_265 -> V_502 == V_499 -> V_502 ) {
V_515 = ( void T_4 * ) ( unsigned long ) V_265 -> V_212 ;
if ( F_134 ( V_515 , V_499 -> V_212 , V_499 -> V_502 ) ) {
V_23 = - V_231 ;
goto V_517;
}
}
V_265 -> V_502 = V_499 -> V_502 ;
V_517:
F_209 ( V_499 ) ;
return V_23 ;
}
int F_216 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_518 * V_265 = V_212 ;
struct V_498 * V_499 ;
void T_4 * V_515 ;
int V_23 = 0 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_499 = F_208 ( V_17 , V_265 -> V_502 , NULL ) ;
if ( F_162 ( V_499 ) )
return F_163 ( V_499 ) ;
V_515 = ( void T_4 * ) ( unsigned long ) V_265 -> V_212 ;
if ( F_191 ( V_499 -> V_212 , V_515 , V_265 -> V_502 ) ) {
V_23 = - V_231 ;
goto V_519;
}
F_12 ( & V_17 -> V_24 . V_500 ) ;
V_265 -> V_516 = V_499 -> V_35 . V_28 ;
F_58 ( & V_499 -> V_504 , & V_214 -> V_520 ) ;
F_15 ( & V_17 -> V_24 . V_500 ) ;
return 0 ;
V_519:
F_209 ( V_499 ) ;
return V_23 ;
}
int F_217 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_521 * V_265 = V_212 ;
struct V_498 * V_499 = NULL , * V_507 ;
bool V_441 = false ;
int V_23 = 0 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
V_499 = F_212 ( V_17 , V_265 -> V_516 ) ;
if ( ! V_499 )
return - V_244 ;
F_12 ( & V_17 -> V_24 . V_500 ) ;
F_91 (bt, &file_priv->blobs, head_file) {
if ( V_507 == V_499 ) {
V_441 = true ;
break;
}
}
if ( ! V_441 ) {
V_23 = - V_522 ;
goto V_127;
}
F_180 ( & V_499 -> V_504 ) ;
F_15 ( & V_17 -> V_24 . V_500 ) ;
F_209 ( V_499 ) ;
F_209 ( V_499 ) ;
return 0 ;
V_127:
F_15 ( & V_17 -> V_24 . V_500 ) ;
F_209 ( V_499 ) ;
return V_23 ;
}
int F_218 ( struct V_76 * V_77 ,
const char * V_523 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
int V_23 ;
V_23 = F_214 ( V_17 ,
& V_77 -> V_524 ,
strlen ( V_523 ) + 1 ,
V_523 ,
& V_77 -> V_35 ,
V_17 -> V_24 . V_164 ) ;
return V_23 ;
}
int F_219 ( struct V_76 * V_77 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
char V_525 [ 256 ] ;
int V_23 ;
if ( ! V_77 -> V_526 ) {
V_23 = F_214 ( V_17 ,
& V_77 -> V_527 ,
0 ,
NULL ,
& V_77 -> V_35 ,
V_17 -> V_24 . V_165 ) ;
return V_23 ;
}
snprintf ( V_525 , 256 , L_103 ,
V_77 -> V_125 -> V_28 , V_77 -> V_528 ,
V_77 -> V_529 , V_77 -> V_530 ,
V_77 -> V_531 , V_77 -> V_532 ,
V_77 -> V_533 , V_77 -> V_534 ) ;
V_23 = F_214 ( V_17 ,
& V_77 -> V_527 ,
strlen ( V_525 ) + 1 ,
V_525 ,
& V_77 -> V_35 ,
V_17 -> V_24 . V_165 ) ;
return V_23 ;
}
int F_220 ( struct V_76 * V_77 ,
const struct V_535 * V_535 )
{
struct V_16 * V_17 = V_77 -> V_17 ;
T_8 V_536 = 0 ;
int V_23 ;
if ( V_77 -> V_537 )
return 0 ;
if ( V_535 )
V_536 = V_538 * ( 1 + V_535 -> V_539 ) ;
V_23 = F_214 ( V_17 ,
& V_77 -> V_115 ,
V_536 ,
V_535 ,
& V_77 -> V_35 ,
V_17 -> V_24 . V_120 ) ;
return V_23 ;
}
bool F_221 ( struct V_159 * V_464 ,
T_5 V_481 , struct V_18 * * V_540 )
{
int V_1 ;
if ( V_464 -> V_263 & V_162 )
return false ;
* V_540 = NULL ;
if ( F_201 ( V_464 , V_478 ) ) {
if ( V_481 < V_464 -> V_465 [ 0 ] || V_481 > V_464 -> V_465 [ 1 ] )
return false ;
return true ;
} else if ( F_201 ( V_464 , V_479 ) ) {
T_7 V_541 = F_222 ( V_481 ) ;
if ( V_541 < F_222 ( V_464 -> V_465 [ 0 ] ) ||
V_541 > F_222 ( V_464 -> V_465 [ 1 ] ) )
return false ;
return true ;
} else if ( F_201 ( V_464 , V_475 ) ) {
T_5 V_542 = 0 ;
for ( V_1 = 0 ; V_1 < V_464 -> V_463 ; V_1 ++ )
V_542 |= ( 1ULL << V_464 -> V_465 [ V_1 ] ) ;
return ! ( V_481 & ~ V_542 ) ;
} else if ( F_201 ( V_464 , V_161 ) ) {
struct V_498 * V_499 ;
if ( V_481 == 0 )
return true ;
V_499 = F_212 ( V_464 -> V_17 , V_481 ) ;
if ( V_499 ) {
* V_540 = & V_499 -> V_35 ;
return true ;
} else {
return false ;
}
} else if ( F_201 ( V_464 , V_480 ) ) {
if ( V_481 == 0 )
return true ;
* V_540 = F_21 ( V_464 -> V_17 , V_481 , V_464 -> V_465 [ 0 ] ) ;
return * V_540 != NULL ;
}
for ( V_1 = 0 ; V_1 < V_464 -> V_463 ; V_1 ++ )
if ( V_464 -> V_465 [ V_1 ] == V_481 )
return true ;
return false ;
}
void F_223 ( struct V_159 * V_464 ,
struct V_18 * V_540 )
{
if ( ! V_540 )
return;
if ( F_201 ( V_464 , V_480 ) ) {
F_25 ( V_540 ) ;
} else if ( F_201 ( V_464 , V_161 ) )
F_209 ( F_213 ( V_540 ) ) ;
}
int F_224 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_543 * V_544 = V_212 ;
struct V_545 V_546 = {
. V_481 = V_544 -> V_481 ,
. V_493 = V_544 -> V_493 ,
. V_547 = V_544 -> V_108 ,
. V_20 = V_106
} ;
return F_225 ( V_17 , & V_546 , V_214 ) ;
}
static int F_226 ( struct V_18 * V_19 ,
struct V_159 * V_464 ,
T_5 V_481 )
{
int V_23 = - V_85 ;
struct V_76 * V_77 = F_227 ( V_19 ) ;
if ( V_464 == V_77 -> V_17 -> V_24 . V_121 ) {
V_23 = (* V_77 -> V_36 -> V_548 )( V_77 , ( int ) V_481 ) ;
} else if ( V_77 -> V_36 -> V_549 )
V_23 = V_77 -> V_36 -> V_549 ( V_77 , V_464 , V_481 ) ;
if ( ! V_23 )
F_203 ( & V_77 -> V_35 , V_464 , V_481 ) ;
return V_23 ;
}
static int F_228 ( struct V_18 * V_19 ,
struct V_159 * V_464 ,
T_5 V_481 )
{
int V_23 = - V_85 ;
struct V_46 * V_47 = F_229 ( V_19 ) ;
if ( V_47 -> V_36 -> V_549 )
V_23 = V_47 -> V_36 -> V_549 ( V_47 , V_464 , V_481 ) ;
if ( ! V_23 )
F_203 ( V_19 , V_464 , V_481 ) ;
return V_23 ;
}
int F_230 ( struct V_48 * V_49 ,
struct V_159 * V_464 ,
T_5 V_481 )
{
int V_23 = - V_85 ;
struct V_18 * V_19 = & V_49 -> V_35 ;
if ( V_49 -> V_36 -> V_549 )
V_23 = V_49 -> V_36 -> V_549 ( V_49 , V_464 , V_481 ) ;
if ( ! V_23 )
F_203 ( V_19 , V_464 , V_481 ) ;
return V_23 ;
}
int F_231 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_550 * V_438 = V_212 ;
struct V_18 * V_19 ;
int V_23 = 0 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_19 = F_24 ( V_17 , V_438 -> V_547 , V_438 -> V_20 ) ;
if ( ! V_19 ) {
V_23 = - V_244 ;
goto V_41;
}
if ( ! V_19 -> V_65 ) {
V_23 = - V_85 ;
goto V_551;
}
V_23 = F_129 ( V_19 , V_214 -> V_255 ,
( T_1 T_4 * ) ( unsigned long ) ( V_438 -> V_284 ) ,
( T_5 T_4 * ) ( unsigned long ) ( V_438 -> V_285 ) ,
& V_438 -> V_286 ) ;
V_551:
F_25 ( V_19 ) ;
V_41:
F_51 ( V_17 ) ;
return V_23 ;
}
int F_225 ( struct V_16 * V_17 , void * V_212 ,
struct V_213 * V_214 )
{
struct V_545 * V_438 = V_212 ;
struct V_18 * V_552 ;
struct V_18 * V_553 ;
struct V_159 * V_464 ;
int V_1 , V_23 = - V_85 ;
struct V_18 * V_540 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_552 = F_24 ( V_17 , V_438 -> V_547 , V_438 -> V_20 ) ;
if ( ! V_552 ) {
V_23 = - V_244 ;
goto V_41;
}
if ( ! V_552 -> V_65 )
goto V_551;
for ( V_1 = 0 ; V_1 < V_552 -> V_65 -> V_260 ; V_1 ++ )
if ( V_552 -> V_65 -> V_65 [ V_1 ] -> V_35 . V_28 == V_438 -> V_493 )
break;
if ( V_1 == V_552 -> V_65 -> V_260 )
goto V_551;
V_553 = F_24 ( V_17 , V_438 -> V_493 ,
V_467 ) ;
if ( ! V_553 ) {
V_23 = - V_244 ;
goto V_551;
}
V_464 = F_232 ( V_553 ) ;
if ( ! F_221 ( V_464 , V_438 -> V_481 , & V_540 ) )
goto V_551;
switch ( V_552 -> type ) {
case V_106 :
V_23 = F_226 ( V_552 , V_464 ,
V_438 -> V_481 ) ;
break;
case V_62 :
V_23 = F_228 ( V_552 , V_464 , V_438 -> V_481 ) ;
break;
case V_139 :
V_23 = F_230 ( F_233 ( V_552 ) ,
V_464 , V_438 -> V_481 ) ;
break;
}
F_223 ( V_464 , V_540 ) ;
V_551:
F_25 ( V_552 ) ;
V_41:
F_51 ( V_17 ) ;
return V_23 ;
}
int F_234 ( struct V_76 * V_77 ,
struct V_128 * V_129 )
{
int V_1 ;
if ( F_42 ( V_77 -> V_129 ) )
return - V_85 ;
for ( V_1 = 0 ; V_1 < V_272 ; V_1 ++ ) {
if ( V_77 -> V_273 [ V_1 ] == 0 ) {
V_77 -> V_273 [ V_1 ] = V_129 -> V_35 . V_28 ;
return 0 ;
}
}
return - V_64 ;
}
int F_235 ( struct V_46 * V_47 ,
int V_245 )
{
V_47 -> V_245 = V_245 ;
V_47 -> V_72 = F_190 ( V_245 , sizeof( V_554 ) * 3 ,
V_27 ) ;
if ( ! V_47 -> V_72 ) {
V_47 -> V_245 = 0 ;
return - V_64 ;
}
return 0 ;
}
int F_236 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_555 * V_556 = V_212 ;
struct V_46 * V_47 ;
void * V_557 , * V_558 , * V_559 ;
int V_536 ;
int V_23 = 0 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_47 = F_122 ( V_17 , V_556 -> V_225 ) ;
if ( ! V_47 ) {
V_23 = - V_244 ;
goto V_41;
}
if ( V_47 -> V_36 -> V_560 == NULL ) {
V_23 = - V_460 ;
goto V_41;
}
if ( V_556 -> V_245 != V_47 -> V_245 ) {
V_23 = - V_85 ;
goto V_41;
}
V_536 = V_556 -> V_245 * ( sizeof( V_554 ) ) ;
V_557 = V_47 -> V_72 ;
if ( F_191 ( V_557 , ( void T_4 * ) ( unsigned long ) V_556 -> V_561 , V_536 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_558 = V_557 + V_536 ;
if ( F_191 ( V_558 , ( void T_4 * ) ( unsigned long ) V_556 -> V_562 , V_536 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_559 = V_558 + V_536 ;
if ( F_191 ( V_559 , ( void T_4 * ) ( unsigned long ) V_556 -> V_563 , V_536 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_47 -> V_36 -> V_560 ( V_47 , V_557 , V_558 , V_559 , 0 , V_47 -> V_245 ) ;
V_41:
F_51 ( V_17 ) ;
return V_23 ;
}
int F_237 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_555 * V_556 = V_212 ;
struct V_46 * V_47 ;
void * V_557 , * V_558 , * V_559 ;
int V_536 ;
int V_23 = 0 ;
if ( ! F_60 ( V_17 , V_227 ) )
return - V_85 ;
F_45 ( V_17 ) ;
V_47 = F_122 ( V_17 , V_556 -> V_225 ) ;
if ( ! V_47 ) {
V_23 = - V_244 ;
goto V_41;
}
if ( V_556 -> V_245 != V_47 -> V_245 ) {
V_23 = - V_85 ;
goto V_41;
}
V_536 = V_556 -> V_245 * ( sizeof( V_554 ) ) ;
V_557 = V_47 -> V_72 ;
if ( F_134 ( ( void T_4 * ) ( unsigned long ) V_556 -> V_561 , V_557 , V_536 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_558 = V_557 + V_536 ;
if ( F_134 ( ( void T_4 * ) ( unsigned long ) V_556 -> V_562 , V_558 , V_536 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_559 = V_558 + V_536 ;
if ( F_134 ( ( void T_4 * ) ( unsigned long ) V_556 -> V_563 , V_559 , V_536 ) ) {
V_23 = - V_231 ;
goto V_41;
}
V_41:
F_51 ( V_17 ) ;
return V_23 ;
}
int F_238 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_564 * V_565 = V_212 ;
struct V_46 * V_47 ;
struct V_33 * V_34 = NULL ;
struct V_566 * V_567 = NULL ;
int V_23 = - V_85 ;
if ( V_565 -> V_263 & ~ V_568 ||
V_565 -> V_569 != 0 )
return - V_85 ;
if ( ( V_565 -> V_263 & V_570 ) && ! V_17 -> V_24 . V_571 )
return - V_85 ;
V_47 = F_122 ( V_17 , V_565 -> V_225 ) ;
if ( ! V_47 )
return - V_244 ;
F_123 ( V_47 , V_47 -> V_52 ) ;
if ( V_47 -> V_52 -> V_34 == NULL ) {
V_23 = - V_572 ;
goto V_41;
}
if ( V_47 -> V_36 -> V_565 == NULL )
goto V_41;
V_34 = F_36 ( V_17 , V_565 -> V_224 ) ;
if ( ! V_34 ) {
V_23 = - V_244 ;
goto V_41;
}
if ( V_47 -> V_73 ) {
const struct V_573 * V_73 = V_47 -> V_52 -> V_73 ;
V_23 = F_144 ( V_73 -> V_247 , V_73 -> V_249 ,
V_73 -> V_304 , V_73 -> V_305 , V_34 ) ;
} else {
V_23 = F_153 ( V_47 , V_47 -> V_246 , V_47 -> V_248 , & V_47 -> V_79 , V_34 ) ;
}
if ( V_23 )
goto V_41;
if ( V_47 -> V_52 -> V_34 -> V_315 != V_34 -> V_315 ) {
F_74 ( L_104 ) ;
V_23 = - V_85 ;
goto V_41;
}
if ( V_565 -> V_263 & V_574 ) {
V_567 = F_194 ( sizeof *V_567 , V_27 ) ;
if ( ! V_567 ) {
V_23 = - V_64 ;
goto V_41;
}
V_567 -> V_575 . V_35 . type = V_576 ;
V_567 -> V_575 . V_35 . V_502 = sizeof( V_567 -> V_575 ) ;
V_567 -> V_575 . V_577 = V_565 -> V_577 ;
V_23 = F_239 ( V_17 , V_214 , & V_567 -> V_35 , & V_567 -> V_575 . V_35 ) ;
if ( V_23 ) {
F_63 ( V_567 ) ;
goto V_41;
}
}
V_47 -> V_52 -> V_157 = V_47 -> V_52 -> V_34 ;
V_23 = V_47 -> V_36 -> V_565 ( V_47 , V_34 , V_567 , V_565 -> V_263 ) ;
if ( V_23 ) {
if ( V_565 -> V_263 & V_574 )
F_240 ( V_17 , & V_567 -> V_35 ) ;
V_47 -> V_52 -> V_157 = NULL ;
} else {
V_47 -> V_52 -> V_34 = V_34 ;
V_34 = NULL ;
}
V_41:
if ( V_34 )
F_52 ( V_34 ) ;
if ( V_47 -> V_52 -> V_157 )
F_52 ( V_47 -> V_52 -> V_157 ) ;
V_47 -> V_52 -> V_157 = NULL ;
F_125 ( V_47 ) ;
return V_23 ;
}
void F_241 ( struct V_16 * V_17 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_128 * V_129 ;
struct V_76 * V_77 ;
F_49 (plane, dev)
if ( V_49 -> V_36 -> V_578 )
V_49 -> V_36 -> V_578 ( V_49 ) ;
F_46 (crtc, dev)
if ( V_47 -> V_36 -> V_578 )
V_47 -> V_36 -> V_578 ( V_47 ) ;
F_94 (encoder, dev)
if ( V_129 -> V_36 -> V_578 )
V_129 -> V_36 -> V_578 ( V_129 ) ;
F_12 ( & V_17 -> V_24 . V_61 ) ;
F_89 (connector, dev)
if ( V_77 -> V_36 -> V_578 )
V_77 -> V_36 -> V_578 ( V_77 ) ;
F_15 ( & V_17 -> V_24 . V_61 ) ;
}
int F_242 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_579 * args = V_212 ;
T_3 V_426 , V_580 , V_536 ;
if ( ! V_17 -> V_581 -> V_582 )
return - V_460 ;
if ( ! args -> V_308 || ! args -> V_309 || ! args -> V_358 )
return - V_85 ;
V_426 = F_243 ( args -> V_358 , 8 ) ;
if ( ! V_426 || V_426 > 0xffffffffU / args -> V_308 )
return - V_85 ;
V_580 = V_426 * args -> V_308 ;
if ( args -> V_309 > 0xffffffffU / V_580 )
return - V_85 ;
V_536 = args -> V_309 * V_580 ;
if ( F_244 ( V_536 ) == 0 )
return - V_85 ;
args -> V_344 = 0 ;
args -> V_370 = 0 ;
args -> V_536 = 0 ;
return V_17 -> V_581 -> V_582 ( V_214 , V_17 , args ) ;
}
int F_245 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_583 * args = V_212 ;
if ( ! V_17 -> V_581 -> V_584 )
return - V_460 ;
return V_17 -> V_581 -> V_584 ( V_214 , V_17 , args -> V_344 , & args -> V_585 ) ;
}
int F_246 ( struct V_16 * V_17 ,
void * V_212 , struct V_213 * V_214 )
{
struct V_586 * args = V_212 ;
if ( ! V_17 -> V_581 -> V_587 )
return - V_460 ;
return V_17 -> V_581 -> V_587 ( V_214 , V_17 , args -> V_344 ) ;
}
void F_247 ( T_1 V_13 , unsigned int * V_359 ,
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
F_74 ( L_105 ,
F_9 ( V_13 ) ) ;
* V_359 = 0 ;
* V_358 = 0 ;
break;
}
}
int F_174 ( T_1 V_13 )
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
int F_175 ( T_1 V_13 , int V_49 )
{
unsigned int V_359 ;
int V_358 ;
if ( V_49 >= F_174 ( V_13 ) )
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
F_247 ( V_13 , & V_359 , & V_358 ) ;
return V_358 >> 3 ;
}
}
int F_172 ( T_1 V_13 )
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
int F_173 ( T_1 V_13 )
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
int F_248 ( int V_308 , T_1 V_13 , int V_49 )
{
if ( V_49 >= F_174 ( V_13 ) )
return 0 ;
if ( V_49 == 0 )
return V_308 ;
return V_308 / F_172 ( V_13 ) ;
}
int F_249 ( int V_309 , T_1 V_13 , int V_49 )
{
if ( V_49 >= F_174 ( V_13 ) )
return 0 ;
if ( V_49 == 0 )
return V_309 ;
return V_309 / F_173 ( V_13 ) ;
}
unsigned int F_250 ( unsigned int V_327 ,
unsigned int V_588 )
{
if ( V_327 & ~ V_588 ) {
V_327 ^= F_154 ( V_589 ) | F_154 ( V_590 ) ;
V_327 = ( V_327 & V_591 ) |
F_154 ( ( F_251 ( V_327 & V_592 ) + 1 ) % 4 ) ;
}
return V_327 ;
}
void F_252 ( struct V_16 * V_17 )
{
F_253 ( & V_17 -> V_24 . V_61 ) ;
F_55 ( & V_17 -> V_24 . V_282 ) ;
F_253 ( & V_17 -> V_24 . V_25 ) ;
F_253 ( & V_17 -> V_24 . V_42 ) ;
F_253 ( & V_17 -> V_24 . V_500 ) ;
F_34 ( & V_17 -> V_24 . V_45 ) ;
F_34 ( & V_17 -> V_24 . V_66 ) ;
F_34 ( & V_17 -> V_24 . V_117 ) ;
F_34 ( & V_17 -> V_24 . V_134 ) ;
F_34 ( & V_17 -> V_24 . V_470 ) ;
F_34 ( & V_17 -> V_24 . V_506 ) ;
F_34 ( & V_17 -> V_24 . V_141 ) ;
F_254 ( & V_17 -> V_24 . V_26 ) ;
F_254 ( & V_17 -> V_24 . V_593 ) ;
F_3 ( & V_17 -> V_24 . V_105 ) ;
F_45 ( V_17 ) ;
F_104 ( V_17 ) ;
F_51 ( V_17 ) ;
V_17 -> V_24 . V_43 = 0 ;
V_17 -> V_24 . V_118 = 0 ;
V_17 -> V_24 . V_67 = 0 ;
V_17 -> V_24 . V_135 = 0 ;
V_17 -> V_24 . V_144 = 0 ;
V_17 -> V_24 . V_142 = 0 ;
}
void F_255 ( struct V_16 * V_17 )
{
struct V_76 * V_77 , * V_594 ;
struct V_46 * V_47 , * V_595 ;
struct V_128 * V_129 , * V_596 ;
struct V_33 * V_34 , * V_597 ;
struct V_159 * V_464 , * V_484 ;
struct V_498 * V_499 , * V_507 ;
struct V_48 * V_49 , * V_598 ;
F_81 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_129 -> V_36 -> V_37 ( V_129 ) ;
}
F_81 (connector, ot,
&dev->mode_config.connector_list, head) {
V_77 -> V_36 -> V_37 ( V_77 ) ;
}
F_81 (property, pt, &dev->mode_config.property_list,
head) {
F_196 ( V_17 , V_464 ) ;
}
F_81 (plane, plt, &dev->mode_config.plane_list,
head) {
V_49 -> V_36 -> V_37 ( V_49 ) ;
}
F_81 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_47 -> V_36 -> V_37 ( V_47 ) ;
}
F_81 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_209 ( V_499 ) ;
}
F_42 ( ! F_43 ( & V_17 -> V_24 . V_45 ) ) ;
F_81 (fb, fbt, &dev->mode_config.fb_list, head) {
F_31 ( & V_34 -> V_35 . V_30 ) ;
}
F_5 ( & V_17 -> V_24 . V_105 ) ;
F_256 ( & V_17 -> V_24 . V_593 ) ;
F_256 ( & V_17 -> V_24 . V_26 ) ;
F_64 ( & V_17 -> V_24 . V_282 ) ;
}
struct V_159 * F_257 ( struct V_16 * V_17 ,
unsigned int V_588 )
{
static const struct V_471 V_472 [] = {
{ V_599 , L_106 } ,
{ V_328 , L_107 } ,
{ V_600 , L_108 } ,
{ V_329 , L_109 } ,
{ V_589 , L_110 } ,
{ V_590 , L_111 } ,
} ;
return F_197 ( V_17 , 0 , L_112 ,
V_472 , F_2 ( V_472 ) ,
V_588 ) ;
}
static void F_258 ( struct V_22 * V_22 )
{
struct V_601 * V_602 = F_32 ( V_22 , struct V_601 , V_30 ) ;
struct V_16 * V_17 = V_602 -> V_17 ;
F_12 ( & V_17 -> V_24 . V_25 ) ;
F_20 ( & V_17 -> V_24 . V_593 , V_602 -> V_28 ) ;
F_15 ( & V_17 -> V_24 . V_25 ) ;
F_63 ( V_602 ) ;
}
void F_80 ( struct V_16 * V_17 ,
struct V_601 * V_602 )
{
F_28 ( & V_602 -> V_30 , F_258 ) ;
}
struct V_601 * F_259 ( struct V_16 * V_17 ,
char V_603 [ 8 ] )
{
struct V_601 * V_602 ;
int V_28 ;
F_12 ( & V_17 -> V_24 . V_25 ) ;
F_260 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_602 -> V_604 , V_603 , 8 ) ) {
if ( ! F_23 ( & V_602 -> V_30 ) )
V_602 = NULL ;
F_15 ( & V_17 -> V_24 . V_25 ) ;
return V_602 ;
}
}
F_15 ( & V_17 -> V_24 . V_25 ) ;
return NULL ;
}
struct V_601 * F_261 ( struct V_16 * V_17 ,
char V_603 [ 8 ] )
{
struct V_601 * V_602 ;
int V_23 ;
V_602 = F_194 ( sizeof( * V_602 ) , V_27 ) ;
if ( ! V_602 )
return F_176 ( - V_64 ) ;
F_14 ( & V_602 -> V_30 ) ;
memcpy ( V_602 -> V_604 , V_603 , 8 ) ;
V_602 -> V_17 = V_17 ;
F_12 ( & V_17 -> V_24 . V_25 ) ;
V_23 = F_13 ( & V_17 -> V_24 . V_593 , V_602 , 1 , 0 , V_27 ) ;
if ( V_23 >= 0 ) {
V_602 -> V_28 = V_23 ;
} else {
F_63 ( V_602 ) ;
V_602 = F_176 ( V_23 ) ;
}
F_15 ( & V_17 -> V_24 . V_25 ) ;
return V_602 ;
}
