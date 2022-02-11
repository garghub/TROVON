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
static int F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
T_1 V_16 ,
bool V_17 ,
void (* F_9)( struct V_18 * V_18 ) )
{
int V_19 ;
F_10 ( & V_13 -> V_20 . V_21 ) ;
V_19 = F_11 ( & V_13 -> V_20 . V_22 , V_17 ? V_15 : NULL , 1 , 0 , V_23 ) ;
if ( V_19 >= 0 ) {
V_15 -> V_24 = V_19 ;
V_15 -> type = V_16 ;
if ( F_9 ) {
V_15 -> V_25 = F_9 ;
F_12 ( & V_15 -> V_26 ) ;
}
}
F_13 ( & V_13 -> V_20 . V_21 ) ;
return V_19 < 0 ? V_19 : 0 ;
}
int F_14 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
return F_8 ( V_13 , V_15 , V_16 , true , NULL ) ;
}
static void F_15 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
F_10 ( & V_13 -> V_20 . V_21 ) ;
F_16 ( & V_13 -> V_20 . V_22 , V_15 , V_15 -> V_24 ) ;
F_13 ( & V_13 -> V_20 . V_21 ) ;
}
void F_17 ( struct V_12 * V_13 ,
struct V_14 * V_27 )
{
F_10 ( & V_13 -> V_20 . V_21 ) ;
if ( V_27 -> V_24 ) {
F_18 ( & V_13 -> V_20 . V_22 , V_27 -> V_24 ) ;
V_27 -> V_24 = 0 ;
}
F_13 ( & V_13 -> V_20 . V_21 ) ;
}
static struct V_14 * F_19 ( struct V_12 * V_13 ,
T_1 V_24 , T_1 type )
{
struct V_14 * V_15 = NULL ;
F_10 ( & V_13 -> V_20 . V_21 ) ;
V_15 = F_20 ( & V_13 -> V_20 . V_22 , V_24 ) ;
if ( V_15 && type != V_28 && V_15 -> type != type )
V_15 = NULL ;
if ( V_15 && V_15 -> V_24 != V_24 )
V_15 = NULL ;
if ( V_15 && V_15 -> V_25 ) {
if ( ! F_21 ( & V_15 -> V_26 ) )
V_15 = NULL ;
}
F_13 ( & V_13 -> V_20 . V_21 ) ;
return V_15 ;
}
struct V_14 * F_22 ( struct V_12 * V_13 ,
T_1 V_24 , T_1 type )
{
struct V_14 * V_15 = NULL ;
V_15 = F_19 ( V_13 , V_24 , type ) ;
return V_15 ;
}
void F_23 ( struct V_14 * V_15 )
{
if ( V_15 -> V_25 ) {
F_24 ( L_4 , V_15 -> V_24 , F_25 ( & V_15 -> V_26 . V_26 ) ) ;
F_26 ( & V_15 -> V_26 , V_15 -> V_25 ) ;
}
}
void F_27 ( struct V_14 * V_15 )
{
if ( V_15 -> V_25 ) {
F_24 ( L_4 , V_15 -> V_24 , F_25 ( & V_15 -> V_26 . V_26 ) ) ;
F_28 ( & V_15 -> V_26 ) ;
}
}
int F_29 ( struct V_29 * V_30 )
{
struct V_31 V_32 = {
. V_30 = V_30 ,
} ;
return F_30 ( & V_32 ) ;
}
int F_31 ( struct V_12 * V_13 )
{
struct V_29 * V_30 ;
int V_19 = 0 ;
F_32 ( V_13 ) ;
F_33 (crtc, dev)
if ( V_30 -> V_33 ) {
V_19 = F_29 ( V_30 ) ;
if ( V_19 )
goto V_34;
}
V_34:
F_34 ( V_13 ) ;
return V_19 ;
}
static void F_35 ( struct V_18 * V_18 )
{
struct V_35 * V_36 =
F_36 ( V_18 , struct V_35 , V_37 . V_26 ) ;
struct V_12 * V_13 = V_36 -> V_13 ;
F_17 ( V_13 , & V_36 -> V_37 ) ;
V_36 -> V_38 -> V_39 ( V_36 ) ;
}
int F_37 ( struct V_12 * V_13 , struct V_35 * V_36 ,
const struct V_40 * V_38 )
{
int V_19 ;
F_38 ( & V_36 -> V_41 ) ;
V_36 -> V_13 = V_13 ;
V_36 -> V_38 = V_38 ;
V_19 = F_8 ( V_13 , & V_36 -> V_37 , V_42 ,
false , F_35 ) ;
if ( V_19 )
goto V_34;
F_10 ( & V_13 -> V_20 . V_43 ) ;
V_13 -> V_20 . V_44 ++ ;
F_39 ( & V_36 -> V_45 , & V_13 -> V_20 . V_46 ) ;
F_13 ( & V_13 -> V_20 . V_43 ) ;
F_15 ( V_13 , & V_36 -> V_37 ) ;
V_34:
return V_19 ;
}
struct V_35 * F_40 ( struct V_12 * V_13 ,
T_1 V_24 )
{
struct V_14 * V_15 ;
struct V_35 * V_36 = NULL ;
V_15 = F_19 ( V_13 , V_24 , V_42 ) ;
if ( V_15 )
V_36 = F_41 ( V_15 ) ;
return V_36 ;
}
void F_42 ( struct V_35 * V_36 )
{
struct V_12 * V_13 ;
if ( ! V_36 )
return;
V_13 = V_36 -> V_13 ;
F_17 ( V_13 , & V_36 -> V_37 ) ;
}
void F_43 ( struct V_35 * V_36 )
{
struct V_12 * V_13 = V_36 -> V_13 ;
F_10 ( & V_13 -> V_20 . V_43 ) ;
F_44 ( & V_36 -> V_45 ) ;
V_13 -> V_20 . V_44 -- ;
F_13 ( & V_13 -> V_20 . V_43 ) ;
}
void F_45 ( struct V_35 * V_36 )
{
struct V_12 * V_13 ;
struct V_29 * V_30 ;
struct V_47 * V_48 ;
if ( ! V_36 )
return;
V_13 = V_36 -> V_13 ;
F_46 ( ! F_47 ( & V_36 -> V_41 ) ) ;
if ( F_48 ( V_36 ) > 1 ) {
F_32 ( V_13 ) ;
F_33 (crtc, dev) {
if ( V_30 -> V_49 -> V_36 == V_36 ) {
if ( F_29 ( V_30 ) )
F_49 ( L_5 , V_30 ) ;
}
}
F_50 (plane, dev) {
if ( V_48 -> V_36 == V_36 )
F_51 ( V_48 ) ;
}
F_34 ( V_13 ) ;
}
F_52 ( V_36 ) ;
}
static unsigned int F_53 ( struct V_12 * V_13 )
{
unsigned int V_50 = 0 ;
struct V_29 * V_51 ;
F_33 (tmp, dev) {
V_50 ++ ;
}
return V_50 ;
}
static int F_54 ( struct V_12 * V_13 )
{
struct V_29 * V_30 ;
int V_19 = 0 ;
F_33 (crtc, dev) {
if ( V_30 -> V_38 -> V_52 )
V_19 = V_30 -> V_38 -> V_52 ( V_30 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_55 ( struct V_12 * V_13 )
{
struct V_29 * V_30 ;
F_33 (crtc, dev) {
if ( V_30 -> V_38 -> V_53 )
V_30 -> V_38 -> V_53 ( V_30 ) ;
}
}
int F_56 ( struct V_12 * V_13 , struct V_29 * V_30 ,
struct V_47 * V_49 ,
struct V_47 * V_54 ,
const struct V_55 * V_38 ,
const char * V_11 , ... )
{
struct V_56 * V_57 = & V_13 -> V_20 ;
int V_19 ;
F_46 ( V_49 && V_49 -> type != V_58 ) ;
F_46 ( V_54 && V_54 -> type != V_59 ) ;
V_30 -> V_13 = V_13 ;
V_30 -> V_38 = V_38 ;
F_38 ( & V_30 -> V_60 ) ;
F_57 ( & V_30 -> V_61 ) ;
F_58 ( & V_30 -> V_62 ) ;
V_19 = F_14 ( V_13 , & V_30 -> V_37 , V_63 ) ;
if ( V_19 )
return V_19 ;
if ( V_11 ) {
T_2 V_64 ;
va_start ( V_64 , V_11 ) ;
V_30 -> V_11 = F_59 ( V_23 , V_11 , V_64 ) ;
va_end ( V_64 ) ;
} else {
V_30 -> V_11 = F_60 ( V_23 , L_6 ,
F_53 ( V_13 ) ) ;
}
if ( ! V_30 -> V_11 ) {
F_17 ( V_13 , & V_30 -> V_37 ) ;
return - V_65 ;
}
V_30 -> V_37 . V_66 = & V_30 -> V_66 ;
F_61 ( & V_30 -> V_45 , & V_57 -> V_67 ) ;
V_30 -> V_68 = V_57 -> V_69 ++ ;
V_30 -> V_49 = V_49 ;
V_30 -> V_54 = V_54 ;
if ( V_49 )
V_49 -> V_70 = 1 << F_62 ( V_30 ) ;
if ( V_54 )
V_54 -> V_70 = 1 << F_62 ( V_30 ) ;
if ( F_63 ( V_13 , V_71 ) ) {
F_64 ( & V_30 -> V_37 , V_57 -> V_72 , 0 ) ;
F_64 ( & V_30 -> V_37 , V_57 -> V_73 , 0 ) ;
}
return 0 ;
}
void F_65 ( struct V_29 * V_30 )
{
struct V_12 * V_13 = V_30 -> V_13 ;
F_66 ( V_30 -> V_74 ) ;
V_30 -> V_74 = NULL ;
F_67 ( & V_30 -> V_62 ) ;
F_17 ( V_13 , & V_30 -> V_37 ) ;
F_44 ( & V_30 -> V_45 ) ;
V_13 -> V_20 . V_69 -- ;
F_46 ( V_30 -> V_75 && ! V_30 -> V_38 -> V_76 ) ;
if ( V_30 -> V_75 && V_30 -> V_38 -> V_76 )
V_30 -> V_38 -> V_76 ( V_30 , V_30 -> V_75 ) ;
F_66 ( V_30 -> V_11 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
}
static void F_68 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
F_44 ( & V_80 -> V_45 ) ;
F_69 ( V_78 -> V_13 , V_80 ) ;
}
int F_70 ( struct V_81 * V_82 ,
const T_3 * V_83 ,
unsigned int V_84 )
{
T_3 * V_85 = NULL ;
if ( ! V_83 && V_84 )
return - V_86 ;
if ( V_83 && V_84 ) {
V_85 = F_71 ( V_83 , sizeof( * V_83 ) * V_84 ,
V_23 ) ;
if ( ! V_85 )
return - V_65 ;
}
F_66 ( V_82 -> V_87 ) ;
V_82 -> V_87 = V_85 ;
V_82 -> V_88 = V_84 ;
return 0 ;
}
static void F_72 ( struct V_77 * V_78 )
{
struct V_89 * V_80 = & V_78 -> V_90 ;
char * V_91 = NULL ;
if ( F_73 ( V_78 -> V_11 , & V_91 ) )
return;
if ( ! F_74 ( V_91 ,
V_78 ,
V_80 ) )
return;
if ( V_80 -> V_92 ) {
const char * V_93 ;
switch ( V_80 -> V_92 ) {
case V_94 :
V_93 = L_7 ;
break;
case V_95 :
V_93 = L_8 ;
break;
default:
case V_96 :
V_93 = L_9 ;
break;
}
F_75 ( L_10 , V_78 -> V_11 , V_93 ) ;
V_78 -> V_92 = V_80 -> V_92 ;
}
F_76 ( L_11 ,
V_78 -> V_11 ,
V_80 -> V_97 , V_80 -> V_98 ,
V_80 -> V_99 ? V_80 -> V_100 : 60 ,
V_80 -> V_101 ? L_12 : L_13 ,
V_80 -> V_102 ? L_14 : L_13 ,
V_80 -> V_103 ? L_15 : L_13 ) ;
}
static void F_77 ( struct V_18 * V_18 )
{
struct V_77 * V_78 =
F_36 ( V_18 , struct V_77 , V_37 . V_26 ) ;
struct V_12 * V_13 = V_78 -> V_13 ;
F_17 ( V_13 , & V_78 -> V_37 ) ;
V_78 -> V_38 -> V_39 ( V_78 ) ;
}
int F_78 ( struct V_12 * V_13 ,
struct V_77 * V_78 ,
const struct V_104 * V_38 ,
int V_105 )
{
struct V_56 * V_57 = & V_13 -> V_20 ;
int V_19 ;
struct V_3 * V_106 =
& V_2 [ V_105 ] . V_3 ;
F_32 ( V_13 ) ;
V_19 = F_8 ( V_13 , & V_78 -> V_37 ,
V_107 ,
false , F_77 ) ;
if ( V_19 )
goto V_108;
V_78 -> V_37 . V_66 = & V_78 -> V_66 ;
V_78 -> V_13 = V_13 ;
V_78 -> V_38 = V_38 ;
V_19 = F_79 ( & V_57 -> V_106 , 0 , 0 , V_23 ) ;
if ( V_19 < 0 )
goto V_109;
V_78 -> V_68 = V_19 ;
V_19 = 0 ;
V_78 -> V_105 = V_105 ;
V_78 -> V_110 =
F_79 ( V_106 , 1 , 0 , V_23 ) ;
if ( V_78 -> V_110 < 0 ) {
V_19 = V_78 -> V_110 ;
goto V_111;
}
V_78 -> V_11 =
F_60 ( V_23 , L_16 ,
V_2 [ V_105 ] . V_11 ,
V_78 -> V_110 ) ;
if ( ! V_78 -> V_11 ) {
V_19 = - V_65 ;
goto V_112;
}
F_38 ( & V_78 -> V_113 ) ;
F_38 ( & V_78 -> V_114 ) ;
V_78 -> V_115 = NULL ;
V_78 -> V_5 = V_116 ;
F_72 ( V_78 ) ;
F_61 ( & V_78 -> V_45 , & V_57 -> V_117 ) ;
V_57 -> V_118 ++ ;
if ( V_105 != V_119 )
F_64 ( & V_78 -> V_37 ,
V_57 -> V_120 ,
0 ) ;
F_64 ( & V_78 -> V_37 ,
V_57 -> V_121 , 0 ) ;
if ( F_63 ( V_13 , V_71 ) ) {
F_64 ( & V_78 -> V_37 , V_57 -> V_122 , 0 ) ;
}
V_78 -> V_123 = NULL ;
V_112:
if ( V_19 )
F_80 ( V_106 , V_78 -> V_110 ) ;
V_111:
if ( V_19 )
F_80 ( & V_57 -> V_106 , V_78 -> V_68 ) ;
V_109:
if ( V_19 )
F_17 ( V_13 , & V_78 -> V_37 ) ;
V_108:
F_34 ( V_13 ) ;
return V_19 ;
}
void F_81 ( struct V_77 * V_78 )
{
struct V_12 * V_13 = V_78 -> V_13 ;
struct V_79 * V_80 , * V_124 ;
if ( F_46 ( V_78 -> V_125 ) )
F_82 ( V_78 ) ;
if ( V_78 -> V_126 ) {
F_83 ( V_13 , V_78 -> V_126 ) ;
V_78 -> V_126 = NULL ;
}
F_84 (mode, t, &connector->probed_modes, head)
F_68 ( V_78 , V_80 ) ;
F_84 (mode, t, &connector->modes, head)
F_68 ( V_78 , V_80 ) ;
F_80 ( & V_2 [ V_78 -> V_105 ] . V_3 ,
V_78 -> V_110 ) ;
F_80 ( & V_13 -> V_20 . V_106 ,
V_78 -> V_68 ) ;
F_66 ( V_78 -> V_127 . V_87 ) ;
F_17 ( V_13 , & V_78 -> V_37 ) ;
F_66 ( V_78 -> V_11 ) ;
V_78 -> V_11 = NULL ;
F_44 ( & V_78 -> V_45 ) ;
V_13 -> V_20 . V_118 -- ;
F_46 ( V_78 -> V_75 && ! V_78 -> V_38 -> V_76 ) ;
if ( V_78 -> V_75 && V_78 -> V_38 -> V_76 )
V_78 -> V_38 -> V_76 ( V_78 ,
V_78 -> V_75 ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
}
int F_85 ( struct V_77 * V_78 )
{
int V_19 ;
if ( V_78 -> V_125 )
return 0 ;
V_19 = F_86 ( V_78 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_87 ( V_78 ) ;
if ( V_19 ) {
goto V_128;
}
if ( V_78 -> V_38 -> V_52 ) {
V_19 = V_78 -> V_38 -> V_52 ( V_78 ) ;
if ( V_19 )
goto V_129;
}
F_15 ( V_78 -> V_13 , & V_78 -> V_37 ) ;
V_78 -> V_125 = true ;
return 0 ;
V_129:
F_88 ( V_78 ) ;
V_128:
F_89 ( V_78 ) ;
return V_19 ;
}
void F_82 ( struct V_77 * V_78 )
{
if ( ! V_78 -> V_125 )
return;
if ( V_78 -> V_38 -> V_53 )
V_78 -> V_38 -> V_53 ( V_78 ) ;
F_89 ( V_78 ) ;
F_88 ( V_78 ) ;
V_78 -> V_125 = false ;
}
static void F_90 ( struct V_12 * V_13 )
{
struct V_77 * V_78 ;
F_91 (connector, &dev->mode_config.connector_list, head)
F_82 ( V_78 ) ;
}
static int F_92 ( struct V_12 * V_13 )
{
struct V_77 * V_78 ;
int V_19 ;
F_91 (connector, &dev->mode_config.connector_list, head) {
V_19 = F_85 ( V_78 ) ;
if ( V_19 )
goto V_130;
}
return 0 ;
V_130:
F_13 ( & V_13 -> V_20 . V_62 ) ;
F_90 ( V_13 ) ;
return V_19 ;
}
static int F_93 ( struct V_12 * V_13 )
{
struct V_131 * V_132 ;
int V_19 = 0 ;
F_94 (encoder, dev) {
if ( V_132 -> V_38 -> V_52 )
V_19 = V_132 -> V_38 -> V_52 ( V_132 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_95 ( struct V_12 * V_13 )
{
struct V_131 * V_132 ;
F_94 (encoder, dev) {
if ( V_132 -> V_38 -> V_53 )
V_132 -> V_38 -> V_53 ( V_132 ) ;
}
}
int F_96 ( struct V_12 * V_13 ,
struct V_131 * V_132 ,
const struct V_133 * V_38 ,
int V_134 , const char * V_11 , ... )
{
int V_19 ;
F_32 ( V_13 ) ;
V_19 = F_14 ( V_13 , & V_132 -> V_37 , V_135 ) ;
if ( V_19 )
goto V_108;
V_132 -> V_13 = V_13 ;
V_132 -> V_134 = V_134 ;
V_132 -> V_38 = V_38 ;
if ( V_11 ) {
T_2 V_64 ;
va_start ( V_64 , V_11 ) ;
V_132 -> V_11 = F_59 ( V_23 , V_11 , V_64 ) ;
va_end ( V_64 ) ;
} else {
V_132 -> V_11 = F_60 ( V_23 , L_16 ,
V_136 [ V_134 ] . V_11 ,
V_132 -> V_37 . V_24 ) ;
}
if ( ! V_132 -> V_11 ) {
V_19 = - V_65 ;
goto V_109;
}
F_61 ( & V_132 -> V_45 , & V_13 -> V_20 . V_137 ) ;
V_132 -> V_68 = V_13 -> V_20 . V_138 ++ ;
V_109:
if ( V_19 )
F_17 ( V_13 , & V_132 -> V_37 ) ;
V_108:
F_34 ( V_13 ) ;
return V_19 ;
}
void F_97 ( struct V_131 * V_132 )
{
struct V_12 * V_13 = V_132 -> V_13 ;
F_32 ( V_13 ) ;
F_17 ( V_13 , & V_132 -> V_37 ) ;
F_66 ( V_132 -> V_11 ) ;
F_44 ( & V_132 -> V_45 ) ;
V_13 -> V_20 . V_138 -- ;
F_34 ( V_13 ) ;
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
}
static unsigned int F_98 ( struct V_12 * V_13 )
{
unsigned int V_50 = 0 ;
struct V_47 * V_51 ;
F_50 (tmp, dev) {
V_50 ++ ;
}
return V_50 ;
}
int F_99 ( struct V_12 * V_13 , struct V_47 * V_48 ,
unsigned long V_70 ,
const struct V_139 * V_38 ,
const T_1 * V_83 , unsigned int V_140 ,
enum V_141 type ,
const char * V_11 , ... )
{
struct V_56 * V_57 = & V_13 -> V_20 ;
int V_19 ;
V_19 = F_14 ( V_13 , & V_48 -> V_37 , V_142 ) ;
if ( V_19 )
return V_19 ;
F_58 ( & V_48 -> V_62 ) ;
V_48 -> V_37 . V_66 = & V_48 -> V_66 ;
V_48 -> V_13 = V_13 ;
V_48 -> V_38 = V_38 ;
V_48 -> V_143 = F_100 ( V_140 , sizeof( T_1 ) ,
V_23 ) ;
if ( ! V_48 -> V_143 ) {
F_76 ( L_17 ) ;
F_17 ( V_13 , & V_48 -> V_37 ) ;
return - V_65 ;
}
if ( V_11 ) {
T_2 V_64 ;
va_start ( V_64 , V_11 ) ;
V_48 -> V_11 = F_59 ( V_23 , V_11 , V_64 ) ;
va_end ( V_64 ) ;
} else {
V_48 -> V_11 = F_60 ( V_23 , L_18 ,
F_98 ( V_13 ) ) ;
}
if ( ! V_48 -> V_11 ) {
F_66 ( V_48 -> V_143 ) ;
F_17 ( V_13 , & V_48 -> V_37 ) ;
return - V_65 ;
}
memcpy ( V_48 -> V_143 , V_83 , V_140 * sizeof( T_1 ) ) ;
V_48 -> V_140 = V_140 ;
V_48 -> V_70 = V_70 ;
V_48 -> type = type ;
F_61 ( & V_48 -> V_45 , & V_57 -> V_144 ) ;
V_48 -> V_68 = V_57 -> V_145 ++ ;
if ( V_48 -> type == V_146 )
V_57 -> V_147 ++ ;
F_64 ( & V_48 -> V_37 ,
V_57 -> V_148 ,
V_48 -> type ) ;
if ( F_63 ( V_13 , V_71 ) ) {
F_64 ( & V_48 -> V_37 , V_57 -> V_149 , 0 ) ;
F_64 ( & V_48 -> V_37 , V_57 -> V_122 , 0 ) ;
F_64 ( & V_48 -> V_37 , V_57 -> V_150 , 0 ) ;
F_64 ( & V_48 -> V_37 , V_57 -> V_151 , 0 ) ;
F_64 ( & V_48 -> V_37 , V_57 -> V_152 , 0 ) ;
F_64 ( & V_48 -> V_37 , V_57 -> V_153 , 0 ) ;
F_64 ( & V_48 -> V_37 , V_57 -> V_154 , 0 ) ;
F_64 ( & V_48 -> V_37 , V_57 -> V_155 , 0 ) ;
F_64 ( & V_48 -> V_37 , V_57 -> V_156 , 0 ) ;
F_64 ( & V_48 -> V_37 , V_57 -> V_157 , 0 ) ;
}
return 0 ;
}
static int F_101 ( struct V_12 * V_13 )
{
struct V_47 * V_48 ;
int V_19 = 0 ;
F_50 (plane, dev) {
if ( V_48 -> V_38 -> V_52 )
V_19 = V_48 -> V_38 -> V_52 ( V_48 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_102 ( struct V_12 * V_13 )
{
struct V_47 * V_48 ;
F_50 (plane, dev) {
if ( V_48 -> V_38 -> V_53 )
V_48 -> V_38 -> V_53 ( V_48 ) ;
}
}
int F_103 ( struct V_12 * V_13 , struct V_47 * V_48 ,
unsigned long V_70 ,
const struct V_139 * V_38 ,
const T_1 * V_83 , unsigned int V_140 ,
bool V_158 )
{
enum V_141 type ;
type = V_158 ? V_58 : V_146 ;
return F_99 ( V_13 , V_48 , V_70 , V_38 ,
V_83 , V_140 , type , NULL ) ;
}
void F_104 ( struct V_47 * V_48 )
{
struct V_12 * V_13 = V_48 -> V_13 ;
F_32 ( V_13 ) ;
F_66 ( V_48 -> V_143 ) ;
F_17 ( V_13 , & V_48 -> V_37 ) ;
F_105 ( F_47 ( & V_48 -> V_45 ) ) ;
F_44 ( & V_48 -> V_45 ) ;
V_13 -> V_20 . V_145 -- ;
if ( V_48 -> type == V_146 )
V_13 -> V_20 . V_147 -- ;
F_34 ( V_13 ) ;
F_46 ( V_48 -> V_75 && ! V_48 -> V_38 -> V_76 ) ;
if ( V_48 -> V_75 && V_48 -> V_38 -> V_76 )
V_48 -> V_38 -> V_76 ( V_48 , V_48 -> V_75 ) ;
F_66 ( V_48 -> V_11 ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
}
struct V_47 *
F_106 ( struct V_12 * V_13 , int V_159 )
{
struct V_47 * V_48 ;
F_50 (plane, dev)
if ( V_159 == V_48 -> V_68 )
return V_48 ;
return NULL ;
}
void F_51 ( struct V_47 * V_48 )
{
int V_19 ;
if ( ! V_48 -> V_36 )
return;
V_48 -> V_160 = V_48 -> V_36 ;
V_19 = V_48 -> V_38 -> V_161 ( V_48 ) ;
if ( V_19 ) {
F_49 ( L_19 ) ;
V_48 -> V_160 = NULL ;
return;
}
F_52 ( V_48 -> V_160 ) ;
V_48 -> V_160 = NULL ;
V_48 -> V_36 = NULL ;
V_48 -> V_30 = NULL ;
}
int F_107 ( struct V_12 * V_13 )
{
int V_19 ;
V_19 = F_101 ( V_13 ) ;
if ( V_19 )
goto V_162;
V_19 = F_54 ( V_13 ) ;
if ( V_19 )
goto V_163;
V_19 = F_93 ( V_13 ) ;
if ( V_19 )
goto V_164;
V_19 = F_92 ( V_13 ) ;
if ( V_19 )
goto V_165;
return 0 ;
V_165:
F_95 ( V_13 ) ;
V_164:
F_55 ( V_13 ) ;
V_163:
F_102 ( V_13 ) ;
V_162:
return V_19 ;
}
void F_108 ( struct V_12 * V_13 )
{
F_90 ( V_13 ) ;
F_95 ( V_13 ) ;
F_55 ( V_13 ) ;
F_102 ( V_13 ) ;
}
static int F_109 ( struct V_12 * V_13 )
{
struct V_166 * V_167 ;
V_167 = F_110 ( V_13 , V_168 |
V_169 ,
L_20 , 0 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_120 = V_167 ;
V_167 = F_111 ( V_13 , 0 ,
L_21 , V_170 ,
F_2 ( V_170 ) ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_121 = V_167 ;
V_167 = F_110 ( V_13 ,
V_168 |
V_169 ,
L_22 , 0 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_171 = V_167 ;
V_167 = F_110 ( V_13 ,
V_168 |
V_169 ,
L_23 , 0 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_172 = V_167 ;
V_167 = F_111 ( V_13 , V_169 ,
L_24 , V_173 ,
F_2 ( V_173 ) ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_148 = V_167 ;
V_167 = F_112 ( V_13 , V_174 ,
L_25 , 0 , V_175 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_154 = V_167 ;
V_167 = F_112 ( V_13 , V_174 ,
L_26 , 0 , V_175 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_155 = V_167 ;
V_167 = F_112 ( V_13 , V_174 ,
L_27 , 0 , V_175 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_156 = V_167 ;
V_167 = F_112 ( V_13 , V_174 ,
L_28 , 0 , V_175 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_157 = V_167 ;
V_167 = F_113 ( V_13 , V_174 ,
L_29 , V_176 , V_177 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_150 = V_167 ;
V_167 = F_113 ( V_13 , V_174 ,
L_30 , V_176 , V_177 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_151 = V_167 ;
V_167 = F_112 ( V_13 , V_174 ,
L_31 , 0 , V_177 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_152 = V_167 ;
V_167 = F_112 ( V_13 , V_174 ,
L_32 , 0 , V_177 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_153 = V_167 ;
V_167 = F_114 ( V_13 , V_174 ,
L_33 , V_42 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_149 = V_167 ;
V_167 = F_114 ( V_13 , V_174 ,
L_34 , V_63 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_122 = V_167 ;
V_167 = F_115 ( V_13 , V_174 ,
L_35 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_72 = V_167 ;
V_167 = F_110 ( V_13 ,
V_174 | V_168 ,
L_36 , 0 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_73 = V_167 ;
V_167 = F_110 ( V_13 ,
V_168 ,
L_37 , 0 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_178 = V_167 ;
V_167 = F_112 ( V_13 ,
V_169 ,
L_38 , 0 , V_175 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_179 = V_167 ;
V_167 = F_110 ( V_13 ,
V_168 ,
L_39 , 0 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_180 = V_167 ;
V_167 = F_110 ( V_13 ,
V_168 ,
L_40 , 0 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_181 = V_167 ;
V_167 = F_112 ( V_13 ,
V_169 ,
L_41 , 0 , V_175 ) ;
if ( ! V_167 )
return - V_65 ;
V_13 -> V_20 . V_182 = V_167 ;
return 0 ;
}
int F_116 ( struct V_12 * V_13 )
{
struct V_166 * V_183 ;
struct V_166 * V_184 ;
if ( V_13 -> V_20 . V_185 )
return 0 ;
V_183 =
F_111 ( V_13 , 0 ,
L_42 ,
V_186 ,
F_2 ( V_186 ) ) ;
V_13 -> V_20 . V_185 = V_183 ;
V_184 = F_111 ( V_13 , V_169 ,
L_43 ,
V_187 ,
F_2 ( V_187 ) ) ;
V_13 -> V_20 . V_188 = V_184 ;
return 0 ;
}
int F_117 ( struct V_12 * V_13 ,
unsigned int V_189 ,
const char * const V_114 [] )
{
struct V_166 * V_190 ;
struct V_166 * V_191 ;
unsigned int V_1 ;
if ( V_13 -> V_20 . V_192 )
return 0 ;
V_190 = F_111 ( V_13 , 0 ,
L_42 ,
V_193 ,
F_2 ( V_193 ) ) ;
if ( ! V_190 )
goto V_194;
V_13 -> V_20 . V_192 = V_190 ;
V_191 =
F_111 ( V_13 , V_169 ,
L_43 ,
V_195 ,
F_2 ( V_195 ) ) ;
if ( ! V_191 )
goto V_194;
V_13 -> V_20 . V_196 = V_191 ;
V_13 -> V_20 . V_197 =
F_112 ( V_13 , 0 , L_44 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_197 )
goto V_194;
V_13 -> V_20 . V_198 =
F_112 ( V_13 , 0 , L_45 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_198 )
goto V_194;
V_13 -> V_20 . V_199 =
F_112 ( V_13 , 0 , L_46 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_199 )
goto V_194;
V_13 -> V_20 . V_200 =
F_112 ( V_13 , 0 , L_47 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_200 )
goto V_194;
V_13 -> V_20 . V_201 =
F_110 ( V_13 , V_202 ,
L_48 , V_189 ) ;
if ( ! V_13 -> V_20 . V_201 )
goto V_194;
for ( V_1 = 0 ; V_1 < V_189 ; V_1 ++ )
F_118 ( V_13 -> V_20 . V_201 , V_1 ,
V_1 , V_114 [ V_1 ] ) ;
V_13 -> V_20 . V_203 =
F_112 ( V_13 , 0 , L_49 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_203 )
goto V_194;
V_13 -> V_20 . V_204 =
F_112 ( V_13 , 0 , L_50 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_204 )
goto V_194;
V_13 -> V_20 . V_205 =
F_112 ( V_13 , 0 , L_51 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_205 )
goto V_194;
V_13 -> V_20 . V_206 =
F_112 ( V_13 , 0 , L_52 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_206 )
goto V_194;
V_13 -> V_20 . V_207 =
F_112 ( V_13 , 0 , L_53 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_207 )
goto V_194;
V_13 -> V_20 . V_208 =
F_112 ( V_13 , 0 , L_54 , 0 , 100 ) ;
if ( ! V_13 -> V_20 . V_208 )
goto V_194;
return 0 ;
V_194:
return - V_65 ;
}
int F_119 ( struct V_12 * V_13 )
{
struct V_166 * V_209 ;
if ( V_13 -> V_20 . V_210 )
return 0 ;
V_209 =
F_111 ( V_13 , 0 , L_55 ,
V_211 ,
F_2 ( V_211 ) ) ;
V_13 -> V_20 . V_210 = V_209 ;
return 0 ;
}
int F_120 ( struct V_12 * V_13 )
{
if ( V_13 -> V_20 . V_212 )
return 0 ;
V_13 -> V_20 . V_212 =
F_111 ( V_13 , 0 , L_56 ,
V_213 ,
F_2 ( V_213 ) ) ;
if ( V_13 -> V_20 . V_212 == NULL )
return - V_65 ;
return 0 ;
}
int F_121 ( struct V_12 * V_13 )
{
struct V_166 * V_214 ;
if ( V_13 -> V_20 . V_215 )
return 0 ;
V_214 =
F_111 ( V_13 , V_169 ,
L_57 ,
V_216 ,
F_2 ( V_216 ) ) ;
V_13 -> V_20 . V_215 = V_214 ;
return 0 ;
}
int F_122 ( struct V_12 * V_13 )
{
if ( V_13 -> V_20 . V_217 && V_13 -> V_20 . V_218 )
return 0 ;
V_13 -> V_20 . V_217 =
F_112 ( V_13 , V_169 , L_58 , 0 , 0xffffffff ) ;
V_13 -> V_20 . V_218 =
F_112 ( V_13 , V_169 , L_59 , 0 , 0xffffffff ) ;
if ( V_13 -> V_20 . V_217 == NULL ||
V_13 -> V_20 . V_218 == NULL )
return - V_65 ;
return 0 ;
}
int F_123 ( struct V_12 * V_13 , void * V_219 ,
struct V_220 * V_221 )
{
struct V_222 * V_223 = V_219 ;
struct V_224 * V_225 ;
struct V_35 * V_36 ;
struct V_77 * V_78 ;
struct V_29 * V_30 ;
struct V_131 * V_132 ;
int V_19 = 0 ;
int V_226 = 0 ;
int V_227 = 0 ;
int V_228 = 0 ;
int V_229 = 0 ;
int V_230 = 0 ;
T_1 T_4 * V_231 ;
T_1 T_4 * V_232 ;
T_1 T_4 * V_233 ;
T_1 T_4 * V_234 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
F_10 ( & V_221 -> V_236 ) ;
F_124 (lh, &file_priv->fbs)
V_228 ++ ;
if ( V_223 -> V_237 >= V_228 ) {
V_230 = 0 ;
V_231 = ( T_1 T_4 * ) ( unsigned long ) V_223 -> V_238 ;
F_91 (fb, &file_priv->fbs, filp_head) {
if ( F_125 ( V_36 -> V_37 . V_24 , V_231 + V_230 ) ) {
F_13 ( & V_221 -> V_236 ) ;
return - V_239 ;
}
V_230 ++ ;
}
}
V_223 -> V_237 = V_228 ;
F_13 ( & V_221 -> V_236 ) ;
F_10 ( & V_13 -> V_20 . V_62 ) ;
F_33 (crtc, dev)
V_227 ++ ;
F_126 (connector, dev)
V_226 ++ ;
F_94 (encoder, dev)
V_229 ++ ;
V_223 -> V_240 = V_13 -> V_20 . V_240 ;
V_223 -> V_241 = V_13 -> V_20 . V_241 ;
V_223 -> V_242 = V_13 -> V_20 . V_242 ;
V_223 -> V_243 = V_13 -> V_20 . V_243 ;
if ( V_223 -> V_244 >= V_227 ) {
V_230 = 0 ;
V_232 = ( T_1 T_4 * ) ( unsigned long ) V_223 -> V_245 ;
F_33 (crtc, dev) {
if ( F_125 ( V_30 -> V_37 . V_24 , V_232 + V_230 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_230 ++ ;
}
}
V_223 -> V_244 = V_227 ;
if ( V_223 -> V_246 >= V_229 ) {
V_230 = 0 ;
V_234 = ( T_1 T_4 * ) ( unsigned long ) V_223 -> V_247 ;
F_94 (encoder, dev) {
if ( F_125 ( V_132 -> V_37 . V_24 , V_234 +
V_230 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_230 ++ ;
}
}
V_223 -> V_246 = V_229 ;
if ( V_223 -> V_248 >= V_226 ) {
V_230 = 0 ;
V_233 = ( T_1 T_4 * ) ( unsigned long ) V_223 -> V_249 ;
F_126 (connector, dev) {
if ( F_125 ( V_78 -> V_37 . V_24 ,
V_233 + V_230 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_230 ++ ;
}
}
V_223 -> V_248 = V_226 ;
V_34:
F_13 ( & V_13 -> V_20 . V_62 ) ;
return V_19 ;
}
int F_127 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_250 * V_251 = V_219 ;
struct V_29 * V_30 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_30 = F_128 ( V_13 , V_251 -> V_232 ) ;
if ( ! V_30 )
return - V_252 ;
F_129 ( V_30 , V_30 -> V_49 ) ;
V_251 -> V_253 = V_30 -> V_253 ;
if ( V_30 -> V_49 -> V_36 )
V_251 -> V_231 = V_30 -> V_49 -> V_36 -> V_37 . V_24 ;
else
V_251 -> V_231 = 0 ;
if ( V_30 -> V_75 ) {
V_251 -> V_254 = V_30 -> V_49 -> V_75 -> V_255 >> 16 ;
V_251 -> V_256 = V_30 -> V_49 -> V_75 -> V_257 >> 16 ;
if ( V_30 -> V_75 -> V_258 ) {
F_130 ( & V_251 -> V_80 , & V_30 -> V_75 -> V_80 ) ;
V_251 -> V_259 = 1 ;
} else {
V_251 -> V_259 = 0 ;
}
} else {
V_251 -> V_254 = V_30 -> V_254 ;
V_251 -> V_256 = V_30 -> V_256 ;
if ( V_30 -> V_33 ) {
F_130 ( & V_251 -> V_80 , & V_30 -> V_80 ) ;
V_251 -> V_259 = 1 ;
} else {
V_251 -> V_259 = 0 ;
}
}
F_131 ( V_30 ) ;
return 0 ;
}
static bool F_132 ( const struct V_79 * V_80 ,
const struct V_220 * V_221 )
{
if ( ! V_221 -> V_260 && F_133 ( V_80 ) )
return false ;
return true ;
}
static struct V_131 * F_134 ( struct V_77 * V_78 )
{
if ( V_78 -> V_75 )
return V_78 -> V_75 -> V_261 ;
return V_78 -> V_132 ;
}
static int F_135 ( struct V_14 * V_15 , bool V_262 ,
T_1 T_4 * V_263 , T_5 T_4 * V_264 ,
T_1 * V_265 )
{
int V_266 ;
int V_1 , V_19 , V_230 ;
V_266 = V_15 -> V_66 -> V_267 ;
if ( ! V_262 )
V_266 -= V_15 -> V_66 -> V_268 ;
if ( ( * V_265 >= V_266 ) && V_266 ) {
for ( V_1 = 0 , V_230 = 0 ; V_230 < V_266 ; V_1 ++ ) {
struct V_166 * V_167 = V_15 -> V_66 -> V_66 [ V_1 ] ;
T_5 V_269 ;
if ( ( V_167 -> V_270 & V_174 ) && ! V_262 )
continue;
V_19 = F_136 ( V_15 , V_167 , & V_269 ) ;
if ( V_19 )
return V_19 ;
if ( F_125 ( V_167 -> V_37 . V_24 , V_263 + V_230 ) )
return - V_239 ;
if ( F_125 ( V_269 , V_264 + V_230 ) )
return - V_239 ;
V_230 ++ ;
}
}
* V_265 = V_266 ;
return 0 ;
}
int F_137 ( struct V_12 * V_13 , void * V_219 ,
struct V_220 * V_221 )
{
struct V_271 * V_272 = V_219 ;
struct V_77 * V_78 ;
struct V_131 * V_132 ;
struct V_79 * V_80 ;
int V_273 = 0 ;
int V_274 = 0 ;
int V_19 = 0 ;
int V_230 = 0 ;
int V_1 ;
struct V_275 V_276 ;
struct V_275 T_4 * V_277 ;
T_1 T_4 * V_278 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
memset ( & V_276 , 0 , sizeof( struct V_275 ) ) ;
F_10 ( & V_13 -> V_20 . V_62 ) ;
V_78 = F_138 ( V_13 , V_272 -> V_233 ) ;
if ( ! V_78 ) {
V_19 = - V_252 ;
goto V_108;
}
for ( V_1 = 0 ; V_1 < V_279 ; V_1 ++ )
if ( V_78 -> V_280 [ V_1 ] != 0 )
V_274 ++ ;
if ( V_272 -> V_281 == 0 ) {
V_78 -> V_38 -> V_282 ( V_78 ,
V_13 -> V_20 . V_242 ,
V_13 -> V_20 . V_240 ) ;
}
F_91 (mode, &connector->modes, head)
if ( F_132 ( V_80 , V_221 ) )
V_273 ++ ;
V_272 -> V_233 = V_78 -> V_37 . V_24 ;
V_272 -> V_105 = V_78 -> V_105 ;
V_272 -> V_110 = V_78 -> V_110 ;
V_272 -> V_283 = V_78 -> V_127 . V_284 ;
V_272 -> V_285 = V_78 -> V_127 . V_286 ;
V_272 -> V_287 = V_78 -> V_127 . V_8 ;
V_272 -> V_288 = V_78 -> V_5 ;
F_139 ( & V_13 -> V_20 . V_289 , NULL ) ;
V_132 = F_134 ( V_78 ) ;
if ( V_132 )
V_272 -> V_234 = V_132 -> V_37 . V_24 ;
else
V_272 -> V_234 = 0 ;
if ( ( V_272 -> V_281 >= V_273 ) && V_273 ) {
V_230 = 0 ;
V_277 = (struct V_275 T_4 * ) ( unsigned long ) V_272 -> V_290 ;
F_91 (mode, &connector->modes, head) {
if ( ! F_132 ( V_80 , V_221 ) )
continue;
F_130 ( & V_276 , V_80 ) ;
if ( F_140 ( V_277 + V_230 ,
& V_276 , sizeof( V_276 ) ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_230 ++ ;
}
}
V_272 -> V_281 = V_273 ;
V_19 = F_135 ( & V_78 -> V_37 , V_221 -> V_262 ,
( T_1 T_4 * ) ( unsigned long ) ( V_272 -> V_291 ) ,
( T_5 T_4 * ) ( unsigned long ) ( V_272 -> V_292 ) ,
& V_272 -> V_293 ) ;
if ( V_19 )
goto V_34;
if ( ( V_272 -> V_246 >= V_274 ) && V_274 ) {
V_230 = 0 ;
V_278 = ( T_1 T_4 * ) ( unsigned long ) ( V_272 -> V_294 ) ;
for ( V_1 = 0 ; V_1 < V_279 ; V_1 ++ ) {
if ( V_78 -> V_280 [ V_1 ] != 0 ) {
if ( F_125 ( V_78 -> V_280 [ V_1 ] ,
V_278 + V_230 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_230 ++ ;
}
}
}
V_272 -> V_246 = V_274 ;
V_34:
F_141 ( & V_13 -> V_20 . V_289 ) ;
F_142 ( V_78 ) ;
V_108:
F_13 ( & V_13 -> V_20 . V_62 ) ;
return V_19 ;
}
static struct V_29 * F_143 ( struct V_131 * V_132 )
{
struct V_77 * V_78 ;
struct V_12 * V_13 = V_132 -> V_13 ;
bool V_295 = false ;
F_126 (connector, dev) {
if ( ! V_78 -> V_75 )
continue;
V_295 = true ;
if ( V_78 -> V_75 -> V_261 != V_132 )
continue;
return V_78 -> V_75 -> V_30 ;
}
if ( V_295 )
return NULL ;
return V_132 -> V_30 ;
}
int F_144 ( struct V_12 * V_13 , void * V_219 ,
struct V_220 * V_221 )
{
struct V_296 * V_297 = V_219 ;
struct V_131 * V_132 ;
struct V_29 * V_30 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_132 = F_145 ( V_13 , V_297 -> V_234 ) ;
if ( ! V_132 )
return - V_252 ;
F_139 ( & V_13 -> V_20 . V_289 , NULL ) ;
V_30 = F_143 ( V_132 ) ;
if ( V_30 )
V_297 -> V_232 = V_30 -> V_37 . V_24 ;
else
V_297 -> V_232 = 0 ;
F_141 ( & V_13 -> V_20 . V_289 ) ;
V_297 -> V_134 = V_132 -> V_134 ;
V_297 -> V_234 = V_132 -> V_37 . V_24 ;
V_297 -> V_70 = V_132 -> V_70 ;
V_297 -> V_298 = V_132 -> V_298 ;
return 0 ;
}
int F_146 ( struct V_12 * V_13 , void * V_219 ,
struct V_220 * V_221 )
{
struct V_299 * V_300 = V_219 ;
struct V_56 * V_57 ;
struct V_47 * V_48 ;
T_1 T_4 * V_301 ;
int V_230 = 0 ;
unsigned V_302 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_57 = & V_13 -> V_20 ;
if ( V_221 -> V_303 )
V_302 = V_57 -> V_145 ;
else
V_302 = V_57 -> V_147 ;
if ( V_302 &&
( V_300 -> V_304 >= V_302 ) ) {
V_301 = ( T_1 T_4 * ) ( unsigned long ) V_300 -> V_305 ;
F_50 (plane, dev) {
if ( V_48 -> type != V_146 &&
! V_221 -> V_303 )
continue;
if ( F_125 ( V_48 -> V_37 . V_24 , V_301 + V_230 ) )
return - V_239 ;
V_230 ++ ;
}
}
V_300 -> V_304 = V_302 ;
return 0 ;
}
int F_147 ( struct V_12 * V_13 , void * V_219 ,
struct V_220 * V_221 )
{
struct V_306 * V_300 = V_219 ;
struct V_47 * V_48 ;
T_1 T_4 * V_307 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_48 = F_148 ( V_13 , V_300 -> V_308 ) ;
if ( ! V_48 )
return - V_252 ;
F_139 ( & V_48 -> V_62 , NULL ) ;
if ( V_48 -> V_30 )
V_300 -> V_232 = V_48 -> V_30 -> V_37 . V_24 ;
else
V_300 -> V_232 = 0 ;
if ( V_48 -> V_36 )
V_300 -> V_231 = V_48 -> V_36 -> V_37 . V_24 ;
else
V_300 -> V_231 = 0 ;
F_141 ( & V_48 -> V_62 ) ;
V_300 -> V_308 = V_48 -> V_37 . V_24 ;
V_300 -> V_70 = V_48 -> V_70 ;
V_300 -> V_253 = 0 ;
if ( V_48 -> V_140 &&
( V_300 -> V_309 >= V_48 -> V_140 ) ) {
V_307 = ( T_1 T_4 * ) ( unsigned long ) V_300 -> V_310 ;
if ( F_140 ( V_307 ,
V_48 -> V_143 ,
sizeof( T_1 ) * V_48 -> V_140 ) ) {
return - V_239 ;
}
}
V_300 -> V_309 = V_48 -> V_140 ;
return 0 ;
}
int F_149 ( const struct V_47 * V_48 , T_3 V_311 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_48 -> V_140 ; V_1 ++ ) {
if ( V_311 == V_48 -> V_143 [ V_1 ] )
return 0 ;
}
return - V_86 ;
}
static int F_150 ( T_1 V_255 , T_1 V_257 ,
T_1 V_312 , T_1 V_313 ,
const struct V_35 * V_36 )
{
unsigned int V_314 , V_315 ;
V_314 = V_36 -> V_316 << 16 ;
V_315 = V_36 -> V_317 << 16 ;
if ( V_312 > V_314 ||
V_255 > V_314 - V_312 ||
V_313 > V_315 ||
V_257 > V_315 - V_313 ) {
F_76 ( L_60
L_61 ,
V_312 >> 16 , ( ( V_312 & 0xffff ) * 15625 ) >> 10 ,
V_313 >> 16 , ( ( V_313 & 0xffff ) * 15625 ) >> 10 ,
V_255 >> 16 , ( ( V_255 & 0xffff ) * 15625 ) >> 10 ,
V_257 >> 16 , ( ( V_257 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_318 ;
}
return 0 ;
}
static int F_151 ( struct V_47 * V_48 ,
struct V_29 * V_30 ,
struct V_35 * V_36 ,
T_6 V_319 , T_6 V_320 ,
T_1 V_321 , T_1 V_322 ,
T_1 V_255 , T_1 V_257 ,
T_1 V_312 , T_1 V_313 )
{
int V_19 = 0 ;
if ( ! V_36 ) {
V_48 -> V_160 = V_48 -> V_36 ;
V_19 = V_48 -> V_38 -> V_161 ( V_48 ) ;
if ( ! V_19 ) {
V_48 -> V_30 = NULL ;
V_48 -> V_36 = NULL ;
} else {
V_48 -> V_160 = NULL ;
}
goto V_34;
}
if ( ! ( V_48 -> V_70 & F_152 ( V_30 ) ) ) {
F_76 ( L_62 ) ;
V_19 = - V_86 ;
goto V_34;
}
V_19 = F_149 ( V_48 , V_36 -> V_323 ) ;
if ( V_19 ) {
F_76 ( L_63 ,
F_153 ( V_36 -> V_323 ) ) ;
goto V_34;
}
if ( V_321 > V_177 ||
V_319 > V_177 - ( T_6 ) V_321 ||
V_322 > V_177 ||
V_320 > V_177 - ( T_6 ) V_322 ) {
F_76 ( L_64 ,
V_321 , V_322 , V_319 , V_320 ) ;
V_19 = - V_324 ;
goto V_34;
}
V_19 = F_150 ( V_255 , V_257 , V_312 , V_313 , V_36 ) ;
if ( V_19 )
goto V_34;
V_48 -> V_160 = V_48 -> V_36 ;
V_19 = V_48 -> V_38 -> V_325 ( V_48 , V_30 , V_36 ,
V_319 , V_320 , V_321 , V_322 ,
V_255 , V_257 , V_312 , V_313 ) ;
if ( ! V_19 ) {
V_48 -> V_30 = V_30 ;
V_48 -> V_36 = V_36 ;
V_36 = NULL ;
} else {
V_48 -> V_160 = NULL ;
}
V_34:
if ( V_36 )
F_52 ( V_36 ) ;
if ( V_48 -> V_160 )
F_52 ( V_48 -> V_160 ) ;
V_48 -> V_160 = NULL ;
return V_19 ;
}
static int F_154 ( struct V_47 * V_48 ,
struct V_29 * V_30 ,
struct V_35 * V_36 ,
T_6 V_319 , T_6 V_320 ,
T_1 V_321 , T_1 V_322 ,
T_1 V_255 , T_1 V_257 ,
T_1 V_312 , T_1 V_313 )
{
int V_19 ;
F_32 ( V_48 -> V_13 ) ;
V_19 = F_151 ( V_48 , V_30 , V_36 ,
V_319 , V_320 , V_321 , V_322 ,
V_255 , V_257 , V_312 , V_313 ) ;
F_34 ( V_48 -> V_13 ) ;
return V_19 ;
}
int F_155 ( struct V_12 * V_13 , void * V_219 ,
struct V_220 * V_221 )
{
struct V_326 * V_327 = V_219 ;
struct V_47 * V_48 ;
struct V_29 * V_30 = NULL ;
struct V_35 * V_36 = NULL ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_48 = F_148 ( V_13 , V_327 -> V_308 ) ;
if ( ! V_48 ) {
F_76 ( L_65 ,
V_327 -> V_308 ) ;
return - V_252 ;
}
if ( V_327 -> V_231 ) {
V_36 = F_40 ( V_13 , V_327 -> V_231 ) ;
if ( ! V_36 ) {
F_76 ( L_66 ,
V_327 -> V_231 ) ;
return - V_252 ;
}
V_30 = F_128 ( V_13 , V_327 -> V_232 ) ;
if ( ! V_30 ) {
F_76 ( L_67 ,
V_327 -> V_232 ) ;
return - V_252 ;
}
}
return F_154 ( V_48 , V_30 , V_36 ,
V_327 -> V_319 , V_327 -> V_320 ,
V_327 -> V_321 , V_327 -> V_322 ,
V_327 -> V_255 , V_327 -> V_257 ,
V_327 -> V_312 , V_327 -> V_313 ) ;
}
int F_30 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_30 ;
struct V_35 * V_36 ;
struct V_29 * V_51 ;
int V_19 ;
F_33 (tmp, crtc->dev)
V_51 -> V_49 -> V_160 = V_51 -> V_49 -> V_36 ;
V_36 = V_32 -> V_36 ;
V_19 = V_30 -> V_38 -> V_328 ( V_32 ) ;
if ( V_19 == 0 ) {
V_30 -> V_49 -> V_30 = V_30 ;
V_30 -> V_49 -> V_36 = V_36 ;
}
F_33 (tmp, crtc->dev) {
if ( V_51 -> V_49 -> V_36 )
F_156 ( V_51 -> V_49 -> V_36 ) ;
if ( V_51 -> V_49 -> V_160 )
F_52 ( V_51 -> V_49 -> V_160 ) ;
V_51 -> V_49 -> V_160 = NULL ;
}
return V_19 ;
}
void F_157 ( const struct V_79 * V_80 ,
int * V_329 , int * V_330 )
{
struct V_79 V_331 ;
F_158 ( & V_331 , V_80 ) ;
F_159 ( & V_331 , V_332 ) ;
* V_329 = V_331 . V_333 ;
* V_330 = V_331 . V_334 ;
}
int F_160 ( const struct V_29 * V_30 ,
int V_254 , int V_256 ,
const struct V_79 * V_80 ,
const struct V_35 * V_36 )
{
int V_329 , V_330 ;
F_157 ( V_80 , & V_329 , & V_330 ) ;
if ( V_30 -> V_75 &&
V_30 -> V_49 -> V_75 -> V_335 & ( F_161 ( V_336 ) |
F_161 ( V_337 ) ) )
F_162 ( V_329 , V_330 ) ;
return F_150 ( V_254 << 16 , V_256 << 16 ,
V_329 << 16 , V_330 << 16 , V_36 ) ;
}
int F_163 ( struct V_12 * V_13 , void * V_219 ,
struct V_220 * V_221 )
{
struct V_56 * V_57 = & V_13 -> V_20 ;
struct V_250 * V_338 = V_219 ;
struct V_29 * V_30 ;
struct V_77 * * V_339 = NULL , * V_78 ;
struct V_35 * V_36 = NULL ;
struct V_79 * V_80 = NULL ;
struct V_31 V_32 ;
T_1 T_4 * V_340 ;
int V_19 ;
int V_1 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
if ( V_338 -> V_254 & 0xffff0000 || V_338 -> V_256 & 0xffff0000 )
return - V_324 ;
F_32 ( V_13 ) ;
V_30 = F_128 ( V_13 , V_338 -> V_232 ) ;
if ( ! V_30 ) {
F_76 ( L_68 , V_338 -> V_232 ) ;
V_19 = - V_252 ;
goto V_34;
}
F_76 ( L_69 , V_30 -> V_37 . V_24 , V_30 -> V_11 ) ;
if ( V_338 -> V_259 ) {
if ( V_338 -> V_231 == - 1 ) {
if ( ! V_30 -> V_49 -> V_36 ) {
F_76 ( L_70 ) ;
V_19 = - V_86 ;
goto V_34;
}
V_36 = V_30 -> V_49 -> V_36 ;
F_156 ( V_36 ) ;
} else {
V_36 = F_40 ( V_13 , V_338 -> V_231 ) ;
if ( ! V_36 ) {
F_76 ( L_71 ,
V_338 -> V_231 ) ;
V_19 = - V_252 ;
goto V_34;
}
}
V_80 = F_164 ( V_13 ) ;
if ( ! V_80 ) {
V_19 = - V_65 ;
goto V_34;
}
V_19 = F_165 ( V_80 , & V_338 -> V_80 ) ;
if ( V_19 ) {
F_76 ( L_72 ) ;
goto V_34;
}
if ( ! V_30 -> V_49 -> V_341 ) {
V_19 = F_149 ( V_30 -> V_49 ,
V_36 -> V_323 ) ;
if ( V_19 ) {
F_76 ( L_63 ,
F_153 ( V_36 -> V_323 ) ) ;
goto V_34;
}
}
V_19 = F_160 ( V_30 , V_338 -> V_254 , V_338 -> V_256 ,
V_80 , V_36 ) ;
if ( V_19 )
goto V_34;
}
if ( V_338 -> V_248 == 0 && V_80 ) {
F_76 ( L_73 ) ;
V_19 = - V_86 ;
goto V_34;
}
if ( V_338 -> V_248 > 0 && ( ! V_80 || ! V_36 ) ) {
F_76 ( L_74 ,
V_338 -> V_248 ) ;
V_19 = - V_86 ;
goto V_34;
}
if ( V_338 -> V_248 > 0 ) {
T_3 V_342 ;
if ( V_338 -> V_248 > V_57 -> V_118 ) {
V_19 = - V_86 ;
goto V_34;
}
V_339 = F_100 ( V_338 -> V_248 ,
sizeof( struct V_77 * ) ,
V_23 ) ;
if ( ! V_339 ) {
V_19 = - V_65 ;
goto V_34;
}
for ( V_1 = 0 ; V_1 < V_338 -> V_248 ; V_1 ++ ) {
V_339 [ V_1 ] = NULL ;
V_340 = ( T_1 T_4 * ) ( unsigned long ) V_338 -> V_340 ;
if ( F_166 ( V_342 , & V_340 [ V_1 ] ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_78 = F_138 ( V_13 , V_342 ) ;
if ( ! V_78 ) {
F_76 ( L_75 ,
V_342 ) ;
V_19 = - V_252 ;
goto V_34;
}
F_76 ( L_76 ,
V_78 -> V_37 . V_24 ,
V_78 -> V_11 ) ;
V_339 [ V_1 ] = V_78 ;
}
}
V_32 . V_30 = V_30 ;
V_32 . V_254 = V_338 -> V_254 ;
V_32 . V_256 = V_338 -> V_256 ;
V_32 . V_80 = V_80 ;
V_32 . V_343 = V_339 ;
V_32 . V_344 = V_338 -> V_248 ;
V_32 . V_36 = V_36 ;
V_19 = F_30 ( & V_32 ) ;
V_34:
if ( V_36 )
F_52 ( V_36 ) ;
if ( V_339 ) {
for ( V_1 = 0 ; V_1 < V_338 -> V_248 ; V_1 ++ ) {
if ( V_339 [ V_1 ] )
F_142 ( V_339 [ V_1 ] ) ;
}
}
F_66 ( V_339 ) ;
F_69 ( V_13 , V_80 ) ;
F_34 ( V_13 ) ;
return V_19 ;
}
static int F_167 ( struct V_29 * V_30 ,
struct V_345 * V_346 ,
struct V_220 * V_221 )
{
struct V_12 * V_13 = V_30 -> V_13 ;
struct V_35 * V_36 = NULL ;
struct V_347 V_348 = {
. V_316 = V_346 -> V_316 ,
. V_317 = V_346 -> V_317 ,
. V_323 = V_349 ,
. V_350 = { V_346 -> V_316 * 4 } ,
. V_351 = { V_346 -> V_352 } ,
} ;
T_6 V_319 , V_320 ;
T_1 V_321 = 0 , V_322 = 0 ;
T_1 V_312 = 0 , V_313 = 0 ;
int V_19 = 0 ;
F_105 ( ! V_30 -> V_54 ) ;
F_46 ( V_30 -> V_54 -> V_30 != V_30 && V_30 -> V_54 -> V_30 != NULL ) ;
if ( V_346 -> V_270 & V_353 ) {
if ( V_346 -> V_352 ) {
V_36 = F_168 ( V_13 , & V_348 , V_221 ) ;
if ( F_169 ( V_36 ) ) {
F_76 ( L_77 ) ;
return F_170 ( V_36 ) ;
}
V_36 -> V_354 = V_346 -> V_354 ;
V_36 -> V_355 = V_346 -> V_355 ;
} else {
V_36 = NULL ;
}
} else {
V_36 = V_30 -> V_54 -> V_36 ;
if ( V_36 )
F_156 ( V_36 ) ;
}
if ( V_346 -> V_270 & V_356 ) {
V_319 = V_346 -> V_254 ;
V_320 = V_346 -> V_256 ;
} else {
V_319 = V_30 -> V_357 ;
V_320 = V_30 -> V_358 ;
}
if ( V_36 ) {
V_321 = V_36 -> V_316 ;
V_322 = V_36 -> V_317 ;
V_312 = V_36 -> V_316 << 16 ;
V_313 = V_36 -> V_317 << 16 ;
}
V_19 = F_151 ( V_30 -> V_54 , V_30 , V_36 ,
V_319 , V_320 , V_321 , V_322 ,
0 , 0 , V_312 , V_313 ) ;
if ( V_19 == 0 && V_346 -> V_270 & V_356 ) {
V_30 -> V_357 = V_346 -> V_254 ;
V_30 -> V_358 = V_346 -> V_256 ;
}
return V_19 ;
}
static int F_171 ( struct V_12 * V_13 ,
struct V_345 * V_346 ,
struct V_220 * V_221 )
{
struct V_29 * V_30 ;
int V_19 = 0 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
if ( ! V_346 -> V_270 || ( ~ V_359 & V_346 -> V_270 ) )
return - V_86 ;
V_30 = F_128 ( V_13 , V_346 -> V_232 ) ;
if ( ! V_30 ) {
F_76 ( L_68 , V_346 -> V_232 ) ;
return - V_252 ;
}
F_129 ( V_30 , V_30 -> V_54 ) ;
if ( V_30 -> V_54 ) {
V_19 = F_167 ( V_30 , V_346 , V_221 ) ;
goto V_34;
}
if ( V_346 -> V_270 & V_353 ) {
if ( ! V_30 -> V_38 -> V_360 && ! V_30 -> V_38 -> V_361 ) {
V_19 = - V_362 ;
goto V_34;
}
if ( V_30 -> V_38 -> V_361 )
V_19 = V_30 -> V_38 -> V_361 ( V_30 , V_221 , V_346 -> V_352 ,
V_346 -> V_316 , V_346 -> V_317 , V_346 -> V_354 , V_346 -> V_355 ) ;
else
V_19 = V_30 -> V_38 -> V_360 ( V_30 , V_221 , V_346 -> V_352 ,
V_346 -> V_316 , V_346 -> V_317 ) ;
}
if ( V_346 -> V_270 & V_356 ) {
if ( V_30 -> V_38 -> V_363 ) {
V_19 = V_30 -> V_38 -> V_363 ( V_30 , V_346 -> V_254 , V_346 -> V_256 ) ;
} else {
V_19 = - V_239 ;
goto V_34;
}
}
V_34:
F_131 ( V_30 ) ;
return V_19 ;
}
int F_172 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_364 * V_346 = V_219 ;
struct V_345 V_365 ;
memcpy ( & V_365 , V_346 , sizeof( struct V_364 ) ) ;
V_365 . V_354 = V_365 . V_355 = 0 ;
return F_171 ( V_13 , & V_365 , V_221 ) ;
}
int F_173 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_345 * V_346 = V_219 ;
return F_171 ( V_13 , V_346 , V_221 ) ;
}
T_1 F_174 ( T_1 V_366 , T_1 V_367 )
{
T_1 V_368 ;
switch ( V_366 ) {
case 8 :
V_368 = V_369 ;
break;
case 16 :
if ( V_367 == 15 )
V_368 = V_370 ;
else
V_368 = V_371 ;
break;
case 24 :
V_368 = V_372 ;
break;
case 32 :
if ( V_367 == 24 )
V_368 = V_373 ;
else if ( V_367 == 30 )
V_368 = V_374 ;
else
V_368 = V_349 ;
break;
default:
F_49 ( L_78 ) ;
V_368 = V_373 ;
break;
}
return V_368 ;
}
int F_175 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_375 * V_376 = V_219 ;
struct V_347 V_377 = {} ;
int V_19 ;
V_377 . V_231 = V_376 -> V_231 ;
V_377 . V_316 = V_376 -> V_316 ;
V_377 . V_317 = V_376 -> V_317 ;
V_377 . V_350 [ 0 ] = V_376 -> V_378 ;
V_377 . V_323 = F_174 ( V_376 -> V_366 , V_376 -> V_367 ) ;
V_377 . V_351 [ 0 ] = V_376 -> V_352 ;
V_19 = F_176 ( V_13 , & V_377 , V_221 ) ;
if ( V_19 )
return V_19 ;
V_376 -> V_231 = V_377 . V_231 ;
return 0 ;
}
static int F_177 ( const struct V_347 * V_377 )
{
T_1 V_311 = V_377 -> V_323 & ~ V_379 ;
switch ( V_311 ) {
case V_369 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_370 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_371 :
case V_397 :
case V_372 :
case V_398 :
case V_373 :
case V_399 :
case V_400 :
case V_401 :
case V_349 :
case V_402 :
case V_403 :
case V_404 :
case V_374 :
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
case V_431 :
case V_432 :
return 0 ;
default:
F_76 ( L_79 ,
F_153 ( V_377 -> V_323 ) ) ;
return - V_86 ;
}
}
static int F_178 ( const struct V_347 * V_377 )
{
int V_19 , V_433 , V_434 , V_302 , V_1 ;
V_19 = F_177 ( V_377 ) ;
if ( V_19 ) {
F_76 ( L_80 ,
F_153 ( V_377 -> V_323 ) ) ;
return V_19 ;
}
V_433 = F_179 ( V_377 -> V_323 ) ;
V_434 = F_180 ( V_377 -> V_323 ) ;
V_302 = F_181 ( V_377 -> V_323 ) ;
if ( V_377 -> V_316 == 0 || V_377 -> V_316 % V_433 ) {
F_76 ( L_81 , V_377 -> V_316 ) ;
return - V_86 ;
}
if ( V_377 -> V_317 == 0 || V_377 -> V_317 % V_434 ) {
F_76 ( L_82 , V_377 -> V_317 ) ;
return - V_86 ;
}
for ( V_1 = 0 ; V_1 < V_302 ; V_1 ++ ) {
unsigned int V_316 = V_377 -> V_316 / ( V_1 != 0 ? V_433 : 1 ) ;
unsigned int V_317 = V_377 -> V_317 / ( V_1 != 0 ? V_434 : 1 ) ;
unsigned int V_435 = F_182 ( V_377 -> V_323 , V_1 ) ;
if ( ! V_377 -> V_351 [ V_1 ] ) {
F_76 ( L_83 , V_1 ) ;
return - V_86 ;
}
if ( ( T_5 ) V_316 * V_435 > V_175 )
return - V_324 ;
if ( ( T_5 ) V_317 * V_377 -> V_350 [ V_1 ] + V_377 -> V_436 [ V_1 ] > V_175 )
return - V_324 ;
if ( V_377 -> V_350 [ V_1 ] < V_316 * V_435 ) {
F_76 ( L_84 , V_377 -> V_350 [ V_1 ] , V_1 ) ;
return - V_86 ;
}
if ( V_377 -> V_437 [ V_1 ] && ! ( V_377 -> V_270 & V_438 ) ) {
F_76 ( L_85 ,
V_377 -> V_437 [ V_1 ] , V_1 ) ;
return - V_86 ;
}
switch ( V_377 -> V_437 [ V_1 ] ) {
case V_439 :
if ( V_377 -> V_323 != V_417 ||
V_316 % 128 || V_317 % 32 ||
V_377 -> V_350 [ V_1 ] % 128 ) {
F_76 ( L_86 , V_1 ) ;
return - V_86 ;
}
break;
default:
break;
}
}
for ( V_1 = V_302 ; V_1 < 4 ; V_1 ++ ) {
if ( V_377 -> V_437 [ V_1 ] ) {
F_76 ( L_87 , V_1 ) ;
return - V_86 ;
}
if ( ! ( V_377 -> V_270 & V_438 ) )
continue;
if ( V_377 -> V_351 [ V_1 ] ) {
F_76 ( L_88 , V_1 ) ;
return - V_86 ;
}
if ( V_377 -> V_350 [ V_1 ] ) {
F_76 ( L_89 , V_1 ) ;
return - V_86 ;
}
if ( V_377 -> V_436 [ V_1 ] ) {
F_76 ( L_90 , V_1 ) ;
return - V_86 ;
}
}
return 0 ;
}
static struct V_35 *
F_168 ( struct V_12 * V_13 ,
const struct V_347 * V_377 ,
struct V_220 * V_221 )
{
struct V_56 * V_57 = & V_13 -> V_20 ;
struct V_35 * V_36 ;
int V_19 ;
if ( V_377 -> V_270 & ~ ( V_440 | V_438 ) ) {
F_76 ( L_91 , V_377 -> V_270 ) ;
return F_183 ( - V_86 ) ;
}
if ( ( V_57 -> V_243 > V_377 -> V_316 ) || ( V_377 -> V_316 > V_57 -> V_242 ) ) {
F_76 ( L_92 ,
V_377 -> V_316 , V_57 -> V_243 , V_57 -> V_242 ) ;
return F_183 ( - V_86 ) ;
}
if ( ( V_57 -> V_241 > V_377 -> V_317 ) || ( V_377 -> V_317 > V_57 -> V_240 ) ) {
F_76 ( L_93 ,
V_377 -> V_317 , V_57 -> V_241 , V_57 -> V_240 ) ;
return F_183 ( - V_86 ) ;
}
if ( V_377 -> V_270 & V_438 &&
! V_13 -> V_20 . V_441 ) {
F_76 ( L_94 ) ;
return F_183 ( - V_86 ) ;
}
V_19 = F_178 ( V_377 ) ;
if ( V_19 )
return F_183 ( V_19 ) ;
V_36 = V_13 -> V_20 . V_38 -> V_442 ( V_13 , V_221 , V_377 ) ;
if ( F_169 ( V_36 ) ) {
F_76 ( L_95 ) ;
return V_36 ;
}
return V_36 ;
}
int F_176 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_347 * V_377 = V_219 ;
struct V_35 * V_36 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_36 = F_168 ( V_13 , V_377 , V_221 ) ;
if ( F_169 ( V_36 ) )
return F_170 ( V_36 ) ;
F_76 ( L_96 , V_36 -> V_37 . V_24 ) ;
V_377 -> V_231 = V_36 -> V_37 . V_24 ;
F_10 ( & V_221 -> V_236 ) ;
F_39 ( & V_36 -> V_41 , & V_221 -> V_443 ) ;
F_13 ( & V_221 -> V_236 ) ;
return 0 ;
}
static void F_184 ( struct V_444 * V_445 )
{
struct V_446 * V_447 = F_36 ( V_445 , F_185 ( * V_447 ) , V_448 ) ;
while ( ! F_47 ( & V_447 -> V_443 ) ) {
struct V_35 * V_36 =
F_186 ( & V_447 -> V_443 , F_185 ( * V_36 ) , V_41 ) ;
F_187 ( & V_36 -> V_41 ) ;
F_45 ( V_36 ) ;
}
}
int F_188 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_35 * V_36 = NULL ;
struct V_35 * V_449 = NULL ;
T_1 * V_24 = V_219 ;
int V_450 = 0 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_36 = F_40 ( V_13 , * V_24 ) ;
if ( ! V_36 )
return - V_252 ;
F_10 ( & V_221 -> V_236 ) ;
F_91 (fbl, &file_priv->fbs, filp_head)
if ( V_36 == V_449 )
V_450 = 1 ;
if ( ! V_450 ) {
F_13 ( & V_221 -> V_236 ) ;
goto V_451;
}
F_187 ( & V_36 -> V_41 ) ;
F_13 ( & V_221 -> V_236 ) ;
F_52 ( V_36 ) ;
if ( F_48 ( V_36 ) > 1 ) {
struct V_446 V_447 ;
F_189 ( & V_447 . V_448 , F_184 ) ;
F_38 ( & V_447 . V_443 ) ;
F_61 ( & V_36 -> V_41 , & V_447 . V_443 ) ;
F_190 ( & V_447 . V_448 ) ;
F_191 ( & V_447 . V_448 ) ;
F_192 ( & V_447 . V_448 ) ;
} else
F_52 ( V_36 ) ;
return 0 ;
V_451:
F_52 ( V_36 ) ;
return - V_252 ;
}
int F_193 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_375 * V_377 = V_219 ;
struct V_35 * V_36 ;
int V_19 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_36 = F_40 ( V_13 , V_377 -> V_231 ) ;
if ( ! V_36 )
return - V_252 ;
V_377 -> V_317 = V_36 -> V_317 ;
V_377 -> V_316 = V_36 -> V_316 ;
V_377 -> V_367 = V_36 -> V_367 ;
V_377 -> V_366 = V_36 -> V_452 ;
V_377 -> V_378 = V_36 -> V_350 [ 0 ] ;
if ( V_36 -> V_38 -> V_453 ) {
if ( F_194 ( V_221 ) || F_195 ( V_454 ) ||
F_196 ( V_221 ) ) {
V_19 = V_36 -> V_38 -> V_453 ( V_36 , V_221 ,
& V_377 -> V_352 ) ;
} else {
V_377 -> V_352 = 0 ;
V_19 = 0 ;
}
} else {
V_19 = - V_455 ;
}
F_52 ( V_36 ) ;
return V_19 ;
}
int F_197 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_456 T_4 * V_457 ;
struct V_456 * V_458 = NULL ;
struct V_459 * V_377 = V_219 ;
struct V_35 * V_36 ;
unsigned V_270 ;
int V_460 ;
int V_19 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_36 = F_40 ( V_13 , V_377 -> V_231 ) ;
if ( ! V_36 )
return - V_252 ;
V_460 = V_377 -> V_460 ;
V_457 = (struct V_456 T_4 * ) ( unsigned long ) V_377 -> V_457 ;
if ( ! V_460 != ! V_457 ) {
V_19 = - V_86 ;
goto V_461;
}
V_270 = V_462 & V_377 -> V_270 ;
if ( V_270 & V_463 && ( V_460 % 2 ) ) {
V_19 = - V_86 ;
goto V_461;
}
if ( V_460 && V_457 ) {
if ( V_460 < 0 || V_460 > V_464 ) {
V_19 = - V_86 ;
goto V_461;
}
V_458 = F_198 ( V_460 , sizeof( * V_458 ) , V_23 ) ;
if ( ! V_458 ) {
V_19 = - V_65 ;
goto V_461;
}
V_19 = F_199 ( V_458 , V_457 ,
V_460 * sizeof( * V_458 ) ) ;
if ( V_19 ) {
V_19 = - V_239 ;
goto V_465;
}
}
if ( V_36 -> V_38 -> V_466 ) {
V_19 = V_36 -> V_38 -> V_466 ( V_36 , V_221 , V_270 , V_377 -> V_467 ,
V_458 , V_460 ) ;
} else {
V_19 = - V_468 ;
}
V_465:
F_66 ( V_458 ) ;
V_461:
F_52 ( V_36 ) ;
return V_19 ;
}
void F_200 ( struct V_220 * V_469 )
{
struct V_35 * V_36 , * V_470 ;
struct V_446 V_447 ;
F_38 ( & V_447 . V_443 ) ;
F_84 (fb, tfb, &priv->fbs, filp_head) {
if ( F_48 ( V_36 ) > 1 ) {
F_201 ( & V_36 -> V_41 , & V_447 . V_443 ) ;
} else {
F_187 ( & V_36 -> V_41 ) ;
F_52 ( V_36 ) ;
}
}
if ( ! F_47 ( & V_447 . V_443 ) ) {
F_189 ( & V_447 . V_448 , F_184 ) ;
F_190 ( & V_447 . V_448 ) ;
F_191 ( & V_447 . V_448 ) ;
F_192 ( & V_447 . V_448 ) ;
}
}
static bool F_202 ( struct V_166 * V_471 )
{
if ( V_471 -> V_270 & V_472 )
return ! ( V_471 -> V_270 & V_473 ) ;
return ! ! ( V_471 -> V_270 & V_473 ) ;
}
struct V_166 * F_110 ( struct V_12 * V_13 , int V_270 ,
const char * V_11 , int V_474 )
{
struct V_166 * V_471 = NULL ;
int V_19 ;
V_471 = F_203 ( sizeof( struct V_166 ) , V_23 ) ;
if ( ! V_471 )
return NULL ;
V_471 -> V_13 = V_13 ;
if ( V_474 ) {
V_471 -> V_475 = F_198 ( V_474 , sizeof( T_5 ) ,
V_23 ) ;
if ( ! V_471 -> V_475 )
goto V_476;
}
V_19 = F_14 ( V_13 , & V_471 -> V_37 , V_477 ) ;
if ( V_19 )
goto V_476;
V_471 -> V_270 = V_270 ;
V_471 -> V_474 = V_474 ;
F_38 ( & V_471 -> V_478 ) ;
if ( V_11 ) {
strncpy ( V_471 -> V_11 , V_11 , V_479 ) ;
V_471 -> V_11 [ V_479 - 1 ] = '\0' ;
}
F_61 ( & V_471 -> V_45 , & V_13 -> V_20 . V_480 ) ;
F_46 ( ! F_202 ( V_471 ) ) ;
return V_471 ;
V_476:
F_66 ( V_471 -> V_475 ) ;
F_66 ( V_471 ) ;
return NULL ;
}
struct V_166 * F_111 ( struct V_12 * V_13 , int V_270 ,
const char * V_11 ,
const struct V_481 * V_482 ,
int V_474 )
{
struct V_166 * V_471 ;
int V_1 , V_19 ;
V_270 |= V_202 ;
V_471 = F_110 ( V_13 , V_270 , V_11 , V_474 ) ;
if ( ! V_471 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_474 ; V_1 ++ ) {
V_19 = F_118 ( V_471 , V_1 ,
V_482 [ V_1 ] . type ,
V_482 [ V_1 ] . V_11 ) ;
if ( V_19 ) {
F_204 ( V_13 , V_471 ) ;
return NULL ;
}
}
return V_471 ;
}
struct V_166 * F_205 ( struct V_12 * V_13 ,
int V_270 , const char * V_11 ,
const struct V_481 * V_482 ,
int V_483 ,
T_5 V_484 )
{
struct V_166 * V_471 ;
int V_1 , V_19 , V_68 = 0 ;
int V_474 = F_206 ( V_484 ) ;
V_270 |= V_485 ;
V_471 = F_110 ( V_13 , V_270 , V_11 , V_474 ) ;
if ( ! V_471 )
return NULL ;
for ( V_1 = 0 ; V_1 < V_483 ; V_1 ++ ) {
if ( ! ( V_484 & ( 1ULL << V_482 [ V_1 ] . type ) ) )
continue;
if ( F_46 ( V_68 >= V_474 ) ) {
F_204 ( V_13 , V_471 ) ;
return NULL ;
}
V_19 = F_118 ( V_471 , V_68 ++ ,
V_482 [ V_1 ] . type ,
V_482 [ V_1 ] . V_11 ) ;
if ( V_19 ) {
F_204 ( V_13 , V_471 ) ;
return NULL ;
}
}
return V_471 ;
}
static struct V_166 * F_207 ( struct V_12 * V_13 ,
int V_270 , const char * V_11 ,
T_5 V_486 , T_5 V_487 )
{
struct V_166 * V_471 ;
V_471 = F_110 ( V_13 , V_270 , V_11 , 2 ) ;
if ( ! V_471 )
return NULL ;
V_471 -> V_475 [ 0 ] = V_486 ;
V_471 -> V_475 [ 1 ] = V_487 ;
return V_471 ;
}
struct V_166 * F_112 ( struct V_12 * V_13 , int V_270 ,
const char * V_11 ,
T_5 V_486 , T_5 V_487 )
{
return F_207 ( V_13 , V_488 | V_270 ,
V_11 , V_486 , V_487 ) ;
}
struct V_166 * F_113 ( struct V_12 * V_13 ,
int V_270 , const char * V_11 ,
T_7 V_486 , T_7 V_487 )
{
return F_207 ( V_13 , V_489 | V_270 ,
V_11 , F_208 ( V_486 ) , F_208 ( V_487 ) ) ;
}
struct V_166 * F_114 ( struct V_12 * V_13 ,
int V_270 , const char * V_11 , T_1 type )
{
struct V_166 * V_471 ;
V_270 |= V_490 ;
if ( F_46 ( ! ( V_270 & V_174 ) ) )
return NULL ;
V_471 = F_110 ( V_13 , V_270 , V_11 , 1 ) ;
if ( ! V_471 )
return NULL ;
V_471 -> V_475 [ 0 ] = type ;
return V_471 ;
}
struct V_166 * F_115 ( struct V_12 * V_13 , int V_270 ,
const char * V_11 )
{
return F_112 ( V_13 , V_270 , V_11 , 0 , 1 ) ;
}
int F_118 ( struct V_166 * V_471 , int V_68 ,
T_5 V_491 , const char * V_11 )
{
struct V_492 * V_493 ;
if ( ! ( F_209 ( V_471 , V_202 ) ||
F_209 ( V_471 , V_485 ) ) )
return - V_86 ;
if ( F_209 ( V_471 , V_485 ) &&
( V_491 > 63 ) )
return - V_86 ;
if ( ! F_47 ( & V_471 -> V_478 ) ) {
F_91 (prop_enum, &property->enum_list, head) {
if ( V_493 -> V_491 == V_491 ) {
strncpy ( V_493 -> V_11 , V_11 , V_479 ) ;
V_493 -> V_11 [ V_479 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_493 = F_203 ( sizeof( struct V_492 ) , V_23 ) ;
if ( ! V_493 )
return - V_65 ;
strncpy ( V_493 -> V_11 , V_11 , V_479 ) ;
V_493 -> V_11 [ V_479 - 1 ] = '\0' ;
V_493 -> V_491 = V_491 ;
V_471 -> V_475 [ V_68 ] = V_491 ;
F_61 ( & V_493 -> V_45 , & V_471 -> V_478 ) ;
return 0 ;
}
void F_204 ( struct V_12 * V_13 , struct V_166 * V_471 )
{
struct V_492 * V_493 , * V_494 ;
F_84 (prop_enum, pt, &property->enum_list, head) {
F_44 ( & V_493 -> V_45 ) ;
F_66 ( V_493 ) ;
}
if ( V_471 -> V_474 )
F_66 ( V_471 -> V_475 ) ;
F_17 ( V_13 , & V_471 -> V_37 ) ;
F_44 ( & V_471 -> V_45 ) ;
F_66 ( V_471 ) ;
}
void F_64 ( struct V_14 * V_15 ,
struct V_166 * V_471 ,
T_5 V_495 )
{
int V_267 = V_15 -> V_66 -> V_267 ;
if ( V_267 == V_496 ) {
F_210 ( 1 , L_97
L_98
L_99 ,
V_15 -> type ) ;
return;
}
V_15 -> V_66 -> V_66 [ V_267 ] = V_471 ;
V_15 -> V_66 -> V_475 [ V_267 ] = V_495 ;
V_15 -> V_66 -> V_267 ++ ;
if ( V_471 -> V_270 & V_174 )
V_15 -> V_66 -> V_268 ++ ;
}
int F_211 ( struct V_14 * V_15 ,
struct V_166 * V_471 , T_5 V_269 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_15 -> V_66 -> V_267 ; V_1 ++ ) {
if ( V_15 -> V_66 -> V_66 [ V_1 ] == V_471 ) {
V_15 -> V_66 -> V_475 [ V_1 ] = V_269 ;
return 0 ;
}
}
return - V_86 ;
}
int F_136 ( struct V_14 * V_15 ,
struct V_166 * V_471 , T_5 * V_269 )
{
int V_1 ;
if ( F_63 ( V_471 -> V_13 , V_71 ) &&
! ( V_471 -> V_270 & V_169 ) )
return F_212 ( V_15 , V_471 , V_269 ) ;
for ( V_1 = 0 ; V_1 < V_15 -> V_66 -> V_267 ; V_1 ++ ) {
if ( V_15 -> V_66 -> V_66 [ V_1 ] == V_471 ) {
* V_269 = V_15 -> V_66 -> V_475 [ V_1 ] ;
return 0 ;
}
}
return - V_86 ;
}
int F_213 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_497 * V_272 = V_219 ;
struct V_166 * V_471 ;
int V_498 = 0 ;
int V_499 = 0 ;
int V_19 = 0 , V_1 ;
int V_230 ;
struct V_492 * V_493 ;
struct V_500 T_4 * V_501 ;
T_5 T_4 * V_502 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
F_32 ( V_13 ) ;
V_471 = F_214 ( V_13 , V_272 -> V_503 ) ;
if ( ! V_471 ) {
V_19 = - V_252 ;
goto V_504;
}
if ( F_209 ( V_471 , V_202 ) ||
F_209 ( V_471 , V_485 ) ) {
F_91 (prop_enum, &property->enum_list, head)
V_498 ++ ;
}
V_499 = V_471 -> V_474 ;
strncpy ( V_272 -> V_11 , V_471 -> V_11 , V_479 ) ;
V_272 -> V_11 [ V_479 - 1 ] = 0 ;
V_272 -> V_270 = V_471 -> V_270 ;
if ( ( V_272 -> V_505 >= V_499 ) && V_499 ) {
V_502 = ( T_5 T_4 * ) ( unsigned long ) V_272 -> V_502 ;
for ( V_1 = 0 ; V_1 < V_499 ; V_1 ++ ) {
if ( F_140 ( V_502 + V_1 , & V_471 -> V_475 [ V_1 ] , sizeof( T_5 ) ) ) {
V_19 = - V_239 ;
goto V_504;
}
}
}
V_272 -> V_505 = V_499 ;
if ( F_209 ( V_471 , V_202 ) ||
F_209 ( V_471 , V_485 ) ) {
if ( ( V_272 -> V_506 >= V_498 ) && V_498 ) {
V_230 = 0 ;
V_501 = (struct V_500 T_4 * ) ( unsigned long ) V_272 -> V_507 ;
F_91 (prop_enum, &property->enum_list, head) {
if ( F_140 ( & V_501 [ V_230 ] . V_491 , & V_493 -> V_491 , sizeof( T_5 ) ) ) {
V_19 = - V_239 ;
goto V_504;
}
if ( F_140 ( & V_501 [ V_230 ] . V_11 ,
& V_493 -> V_11 , V_479 ) ) {
V_19 = - V_239 ;
goto V_504;
}
V_230 ++ ;
}
}
V_272 -> V_506 = V_498 ;
}
if ( F_209 ( V_471 , V_168 ) )
V_272 -> V_506 = 0 ;
V_504:
F_34 ( V_13 ) ;
return V_19 ;
}
static void F_215 ( struct V_18 * V_18 )
{
struct V_508 * V_509 =
F_36 ( V_18 , struct V_508 , V_37 . V_26 ) ;
F_10 ( & V_509 -> V_13 -> V_20 . V_510 ) ;
F_44 ( & V_509 -> V_511 ) ;
F_13 ( & V_509 -> V_13 -> V_20 . V_510 ) ;
F_17 ( V_509 -> V_13 , & V_509 -> V_37 ) ;
F_66 ( V_509 ) ;
}
struct V_508 *
F_216 ( struct V_12 * V_13 , T_8 V_512 ,
const void * V_219 )
{
struct V_508 * V_509 ;
int V_19 ;
if ( ! V_512 || V_512 > V_513 - sizeof( struct V_508 ) )
return F_183 ( - V_86 ) ;
V_509 = F_203 ( sizeof( struct V_508 ) + V_512 , V_23 ) ;
if ( ! V_509 )
return F_183 ( - V_65 ) ;
F_38 ( & V_509 -> V_514 ) ;
V_509 -> V_512 = V_512 ;
V_509 -> V_13 = V_13 ;
if ( V_219 )
memcpy ( V_509 -> V_219 , V_219 , V_512 ) ;
V_19 = F_8 ( V_13 , & V_509 -> V_37 , V_515 ,
true , F_215 ) ;
if ( V_19 ) {
F_66 ( V_509 ) ;
return F_183 ( - V_86 ) ;
}
F_10 ( & V_13 -> V_20 . V_510 ) ;
F_61 ( & V_509 -> V_511 ,
& V_13 -> V_20 . V_516 ) ;
F_13 ( & V_13 -> V_20 . V_510 ) ;
return V_509 ;
}
void F_217 ( struct V_508 * V_509 )
{
if ( ! V_509 )
return;
F_23 ( & V_509 -> V_37 ) ;
}
void F_218 ( struct V_12 * V_13 ,
struct V_220 * V_221 )
{
struct V_508 * V_509 , * V_517 ;
F_84 (blob, bt, &file_priv->blobs, head_file) {
F_187 ( & V_509 -> V_514 ) ;
F_217 ( V_509 ) ;
}
}
struct V_508 * F_219 ( struct V_508 * V_509 )
{
F_27 ( & V_509 -> V_37 ) ;
return V_509 ;
}
struct V_508 * F_220 ( struct V_12 * V_13 ,
T_1 V_24 )
{
struct V_14 * V_15 ;
struct V_508 * V_509 = NULL ;
V_15 = F_19 ( V_13 , V_24 , V_515 ) ;
if ( V_15 )
V_509 = F_221 ( V_15 ) ;
return V_509 ;
}
static int F_222 ( struct V_12 * V_13 ,
struct V_508 * * V_518 ,
T_8 V_512 ,
const void * V_219 ,
struct V_14 * V_519 ,
struct V_166 * V_520 )
{
struct V_508 * V_521 = NULL ;
struct V_508 * V_522 = NULL ;
int V_19 ;
F_46 ( V_518 == NULL ) ;
V_522 = * V_518 ;
if ( V_512 && V_219 ) {
V_521 = F_216 ( V_13 , V_512 , V_219 ) ;
if ( F_169 ( V_521 ) )
return F_170 ( V_521 ) ;
}
if ( V_519 ) {
V_19 = F_211 ( V_519 ,
V_520 ,
V_521 ?
V_521 -> V_37 . V_24 : 0 ) ;
if ( V_19 != 0 )
goto V_523;
}
F_217 ( V_522 ) ;
* V_518 = V_521 ;
return 0 ;
V_523:
F_217 ( V_521 ) ;
return V_19 ;
}
int F_223 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_524 * V_272 = V_219 ;
struct V_508 * V_509 ;
int V_19 = 0 ;
void T_4 * V_525 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_509 = F_220 ( V_13 , V_272 -> V_526 ) ;
if ( ! V_509 )
return - V_252 ;
if ( V_272 -> V_512 == V_509 -> V_512 ) {
V_525 = ( void T_4 * ) ( unsigned long ) V_272 -> V_219 ;
if ( F_140 ( V_525 , V_509 -> V_219 , V_509 -> V_512 ) ) {
V_19 = - V_239 ;
goto V_527;
}
}
V_272 -> V_512 = V_509 -> V_512 ;
V_527:
F_217 ( V_509 ) ;
return V_19 ;
}
int F_224 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_528 * V_272 = V_219 ;
struct V_508 * V_509 ;
void T_4 * V_525 ;
int V_19 = 0 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_509 = F_216 ( V_13 , V_272 -> V_512 , NULL ) ;
if ( F_169 ( V_509 ) )
return F_170 ( V_509 ) ;
V_525 = ( void T_4 * ) ( unsigned long ) V_272 -> V_219 ;
if ( F_199 ( V_509 -> V_219 , V_525 , V_272 -> V_512 ) ) {
V_19 = - V_239 ;
goto V_529;
}
F_10 ( & V_13 -> V_20 . V_510 ) ;
V_272 -> V_526 = V_509 -> V_37 . V_24 ;
F_61 ( & V_509 -> V_514 , & V_221 -> V_530 ) ;
F_13 ( & V_13 -> V_20 . V_510 ) ;
return 0 ;
V_529:
F_217 ( V_509 ) ;
return V_19 ;
}
int F_225 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_531 * V_272 = V_219 ;
struct V_508 * V_509 = NULL , * V_517 ;
bool V_450 = false ;
int V_19 = 0 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
V_509 = F_220 ( V_13 , V_272 -> V_526 ) ;
if ( ! V_509 )
return - V_252 ;
F_10 ( & V_13 -> V_20 . V_510 ) ;
F_91 (bt, &file_priv->blobs, head_file) {
if ( V_517 == V_509 ) {
V_450 = true ;
break;
}
}
if ( ! V_450 ) {
V_19 = - V_532 ;
goto V_130;
}
F_187 ( & V_509 -> V_514 ) ;
F_13 ( & V_13 -> V_20 . V_510 ) ;
F_217 ( V_509 ) ;
F_217 ( V_509 ) ;
return 0 ;
V_130:
F_13 ( & V_13 -> V_20 . V_510 ) ;
F_217 ( V_509 ) ;
return V_19 ;
}
int F_226 ( struct V_77 * V_78 ,
const char * V_533 )
{
struct V_12 * V_13 = V_78 -> V_13 ;
int V_19 ;
V_19 = F_222 ( V_13 ,
& V_78 -> V_534 ,
strlen ( V_533 ) + 1 ,
V_533 ,
& V_78 -> V_37 ,
V_13 -> V_20 . V_171 ) ;
return V_19 ;
}
int F_227 ( struct V_77 * V_78 )
{
struct V_12 * V_13 = V_78 -> V_13 ;
char V_535 [ 256 ] ;
int V_19 ;
if ( ! V_78 -> V_536 ) {
V_19 = F_222 ( V_13 ,
& V_78 -> V_537 ,
0 ,
NULL ,
& V_78 -> V_37 ,
V_13 -> V_20 . V_172 ) ;
return V_19 ;
}
snprintf ( V_535 , 256 , L_100 ,
V_78 -> V_126 -> V_24 , V_78 -> V_538 ,
V_78 -> V_539 , V_78 -> V_540 ,
V_78 -> V_541 , V_78 -> V_542 ,
V_78 -> V_543 , V_78 -> V_544 ) ;
V_19 = F_222 ( V_13 ,
& V_78 -> V_537 ,
strlen ( V_535 ) + 1 ,
V_535 ,
& V_78 -> V_37 ,
V_13 -> V_20 . V_172 ) ;
return V_19 ;
}
int F_228 ( struct V_77 * V_78 ,
const struct V_545 * V_545 )
{
struct V_12 * V_13 = V_78 -> V_13 ;
T_8 V_546 = 0 ;
int V_19 ;
if ( V_78 -> V_547 )
return 0 ;
if ( V_545 )
V_546 = V_548 * ( 1 + V_545 -> V_549 ) ;
V_19 = F_222 ( V_13 ,
& V_78 -> V_115 ,
V_546 ,
V_545 ,
& V_78 -> V_37 ,
V_13 -> V_20 . V_120 ) ;
return V_19 ;
}
bool F_229 ( struct V_166 * V_471 ,
T_5 V_491 , struct V_14 * * V_550 )
{
int V_1 ;
if ( V_471 -> V_270 & V_169 )
return false ;
* V_550 = NULL ;
if ( F_209 ( V_471 , V_488 ) ) {
if ( V_491 < V_471 -> V_475 [ 0 ] || V_491 > V_471 -> V_475 [ 1 ] )
return false ;
return true ;
} else if ( F_209 ( V_471 , V_489 ) ) {
T_7 V_551 = F_230 ( V_491 ) ;
if ( V_551 < F_230 ( V_471 -> V_475 [ 0 ] ) ||
V_551 > F_230 ( V_471 -> V_475 [ 1 ] ) )
return false ;
return true ;
} else if ( F_209 ( V_471 , V_485 ) ) {
T_5 V_552 = 0 ;
for ( V_1 = 0 ; V_1 < V_471 -> V_474 ; V_1 ++ )
V_552 |= ( 1ULL << V_471 -> V_475 [ V_1 ] ) ;
return ! ( V_491 & ~ V_552 ) ;
} else if ( F_209 ( V_471 , V_168 ) ) {
struct V_508 * V_509 ;
if ( V_491 == 0 )
return true ;
V_509 = F_220 ( V_471 -> V_13 , V_491 ) ;
if ( V_509 ) {
* V_550 = & V_509 -> V_37 ;
return true ;
} else {
return false ;
}
} else if ( F_209 ( V_471 , V_490 ) ) {
if ( V_491 == 0 )
return true ;
* V_550 = F_19 ( V_471 -> V_13 , V_491 , V_471 -> V_475 [ 0 ] ) ;
return * V_550 != NULL ;
}
for ( V_1 = 0 ; V_1 < V_471 -> V_474 ; V_1 ++ )
if ( V_471 -> V_475 [ V_1 ] == V_491 )
return true ;
return false ;
}
void F_231 ( struct V_166 * V_471 ,
struct V_14 * V_550 )
{
if ( ! V_550 )
return;
if ( F_209 ( V_471 , V_490 ) ) {
F_23 ( V_550 ) ;
} else if ( F_209 ( V_471 , V_168 ) )
F_217 ( F_221 ( V_550 ) ) ;
}
int F_232 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_553 * V_554 = V_219 ;
struct V_555 V_556 = {
. V_491 = V_554 -> V_491 ,
. V_503 = V_554 -> V_503 ,
. V_557 = V_554 -> V_233 ,
. V_16 = V_107
} ;
return F_233 ( V_13 , & V_556 , V_221 ) ;
}
static int F_234 ( struct V_14 * V_15 ,
struct V_166 * V_471 ,
T_5 V_491 )
{
int V_19 = - V_86 ;
struct V_77 * V_78 = F_235 ( V_15 ) ;
if ( V_471 == V_78 -> V_13 -> V_20 . V_121 ) {
V_19 = (* V_78 -> V_38 -> V_558 )( V_78 , ( int ) V_491 ) ;
} else if ( V_78 -> V_38 -> V_559 )
V_19 = V_78 -> V_38 -> V_559 ( V_78 , V_471 , V_491 ) ;
if ( ! V_19 )
F_211 ( & V_78 -> V_37 , V_471 , V_491 ) ;
return V_19 ;
}
static int F_236 ( struct V_14 * V_15 ,
struct V_166 * V_471 ,
T_5 V_491 )
{
int V_19 = - V_86 ;
struct V_29 * V_30 = F_237 ( V_15 ) ;
if ( V_30 -> V_38 -> V_559 )
V_19 = V_30 -> V_38 -> V_559 ( V_30 , V_471 , V_491 ) ;
if ( ! V_19 )
F_211 ( V_15 , V_471 , V_491 ) ;
return V_19 ;
}
int F_238 ( struct V_47 * V_48 ,
struct V_166 * V_471 ,
T_5 V_491 )
{
int V_19 = - V_86 ;
struct V_14 * V_15 = & V_48 -> V_37 ;
if ( V_48 -> V_38 -> V_559 )
V_19 = V_48 -> V_38 -> V_559 ( V_48 , V_471 , V_491 ) ;
if ( ! V_19 )
F_211 ( V_15 , V_471 , V_491 ) ;
return V_19 ;
}
int F_239 ( struct V_12 * V_13 , void * V_219 ,
struct V_220 * V_221 )
{
struct V_560 * V_447 = V_219 ;
struct V_14 * V_15 ;
int V_19 = 0 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
F_32 ( V_13 ) ;
V_15 = F_22 ( V_13 , V_447 -> V_557 , V_447 -> V_16 ) ;
if ( ! V_15 ) {
V_19 = - V_252 ;
goto V_34;
}
if ( ! V_15 -> V_66 ) {
V_19 = - V_86 ;
goto V_561;
}
V_19 = F_135 ( V_15 , V_221 -> V_262 ,
( T_1 T_4 * ) ( unsigned long ) ( V_447 -> V_291 ) ,
( T_5 T_4 * ) ( unsigned long ) ( V_447 -> V_292 ) ,
& V_447 -> V_293 ) ;
V_561:
F_23 ( V_15 ) ;
V_34:
F_34 ( V_13 ) ;
return V_19 ;
}
int F_233 ( struct V_12 * V_13 , void * V_219 ,
struct V_220 * V_221 )
{
struct V_555 * V_447 = V_219 ;
struct V_14 * V_562 ;
struct V_14 * V_563 ;
struct V_166 * V_471 ;
int V_1 , V_19 = - V_86 ;
struct V_14 * V_550 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
F_32 ( V_13 ) ;
V_562 = F_22 ( V_13 , V_447 -> V_557 , V_447 -> V_16 ) ;
if ( ! V_562 ) {
V_19 = - V_252 ;
goto V_34;
}
if ( ! V_562 -> V_66 )
goto V_561;
for ( V_1 = 0 ; V_1 < V_562 -> V_66 -> V_267 ; V_1 ++ )
if ( V_562 -> V_66 -> V_66 [ V_1 ] -> V_37 . V_24 == V_447 -> V_503 )
break;
if ( V_1 == V_562 -> V_66 -> V_267 )
goto V_561;
V_563 = F_22 ( V_13 , V_447 -> V_503 ,
V_477 ) ;
if ( ! V_563 ) {
V_19 = - V_252 ;
goto V_561;
}
V_471 = F_240 ( V_563 ) ;
if ( ! F_229 ( V_471 , V_447 -> V_491 , & V_550 ) )
goto V_561;
switch ( V_562 -> type ) {
case V_107 :
V_19 = F_234 ( V_562 , V_471 ,
V_447 -> V_491 ) ;
break;
case V_63 :
V_19 = F_236 ( V_562 , V_471 , V_447 -> V_491 ) ;
break;
case V_142 :
V_19 = F_238 ( F_241 ( V_562 ) ,
V_471 , V_447 -> V_491 ) ;
break;
}
F_231 ( V_471 , V_550 ) ;
V_561:
F_23 ( V_562 ) ;
V_34:
F_34 ( V_13 ) ;
return V_19 ;
}
int F_242 ( struct V_77 * V_78 ,
struct V_131 * V_132 )
{
int V_1 ;
if ( F_46 ( V_78 -> V_132 ) )
return - V_86 ;
for ( V_1 = 0 ; V_1 < V_279 ; V_1 ++ ) {
if ( V_78 -> V_280 [ V_1 ] == 0 ) {
V_78 -> V_280 [ V_1 ] = V_132 -> V_37 . V_24 ;
return 0 ;
}
}
return - V_65 ;
}
int F_243 ( struct V_29 * V_30 ,
int V_253 )
{
T_9 * V_564 , * V_565 , * V_566 ;
int V_1 ;
V_30 -> V_253 = V_253 ;
V_30 -> V_74 = F_198 ( V_253 , sizeof( T_9 ) * 3 ,
V_23 ) ;
if ( ! V_30 -> V_74 ) {
V_30 -> V_253 = 0 ;
return - V_65 ;
}
V_564 = V_30 -> V_74 ;
V_565 = V_564 + V_253 ;
V_566 = V_565 + V_253 ;
for ( V_1 = 0 ; V_1 < V_253 ; V_1 ++ ) {
V_564 [ V_1 ] = V_1 << 8 ;
V_565 [ V_1 ] = V_1 << 8 ;
V_566 [ V_1 ] = V_1 << 8 ;
}
return 0 ;
}
int F_244 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_567 * V_568 = V_219 ;
struct V_29 * V_30 ;
void * V_564 , * V_565 , * V_566 ;
int V_546 ;
int V_19 = 0 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
F_32 ( V_13 ) ;
V_30 = F_128 ( V_13 , V_568 -> V_232 ) ;
if ( ! V_30 ) {
V_19 = - V_252 ;
goto V_34;
}
if ( V_30 -> V_38 -> V_569 == NULL ) {
V_19 = - V_468 ;
goto V_34;
}
if ( V_568 -> V_253 != V_30 -> V_253 ) {
V_19 = - V_86 ;
goto V_34;
}
V_546 = V_568 -> V_253 * ( sizeof( T_9 ) ) ;
V_564 = V_30 -> V_74 ;
if ( F_199 ( V_564 , ( void T_4 * ) ( unsigned long ) V_568 -> V_570 , V_546 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_565 = V_564 + V_546 ;
if ( F_199 ( V_565 , ( void T_4 * ) ( unsigned long ) V_568 -> V_571 , V_546 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_566 = V_565 + V_546 ;
if ( F_199 ( V_566 , ( void T_4 * ) ( unsigned long ) V_568 -> V_572 , V_546 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_19 = V_30 -> V_38 -> V_569 ( V_30 , V_564 , V_565 , V_566 , V_30 -> V_253 ) ;
V_34:
F_34 ( V_13 ) ;
return V_19 ;
}
int F_245 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_567 * V_568 = V_219 ;
struct V_29 * V_30 ;
void * V_564 , * V_565 , * V_566 ;
int V_546 ;
int V_19 = 0 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
F_32 ( V_13 ) ;
V_30 = F_128 ( V_13 , V_568 -> V_232 ) ;
if ( ! V_30 ) {
V_19 = - V_252 ;
goto V_34;
}
if ( V_568 -> V_253 != V_30 -> V_253 ) {
V_19 = - V_86 ;
goto V_34;
}
V_546 = V_568 -> V_253 * ( sizeof( T_9 ) ) ;
V_564 = V_30 -> V_74 ;
if ( F_140 ( ( void T_4 * ) ( unsigned long ) V_568 -> V_570 , V_564 , V_546 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_565 = V_564 + V_546 ;
if ( F_140 ( ( void T_4 * ) ( unsigned long ) V_568 -> V_571 , V_565 , V_546 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_566 = V_565 + V_546 ;
if ( F_140 ( ( void T_4 * ) ( unsigned long ) V_568 -> V_572 , V_566 , V_546 ) ) {
V_19 = - V_239 ;
goto V_34;
}
V_34:
F_34 ( V_13 ) ;
return V_19 ;
}
int F_246 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_573 * V_574 = V_219 ;
struct V_29 * V_30 ;
struct V_35 * V_36 = NULL ;
struct V_575 * V_576 = NULL ;
int V_19 = - V_86 ;
if ( ! F_63 ( V_13 , V_235 ) )
return - V_86 ;
if ( V_574 -> V_270 & ~ V_577 ||
V_574 -> V_578 != 0 )
return - V_86 ;
if ( ( V_574 -> V_270 & V_579 ) && ! V_13 -> V_20 . V_580 )
return - V_86 ;
V_30 = F_128 ( V_13 , V_574 -> V_232 ) ;
if ( ! V_30 )
return - V_252 ;
F_129 ( V_30 , V_30 -> V_49 ) ;
if ( V_30 -> V_49 -> V_36 == NULL ) {
V_19 = - V_581 ;
goto V_34;
}
if ( V_30 -> V_38 -> V_574 == NULL )
goto V_34;
V_36 = F_40 ( V_13 , V_574 -> V_231 ) ;
if ( ! V_36 ) {
V_19 = - V_252 ;
goto V_34;
}
if ( V_30 -> V_75 ) {
const struct V_582 * V_75 = V_30 -> V_49 -> V_75 ;
V_19 = F_150 ( V_75 -> V_255 , V_75 -> V_257 ,
V_75 -> V_312 , V_75 -> V_313 , V_36 ) ;
} else {
V_19 = F_160 ( V_30 , V_30 -> V_254 , V_30 -> V_256 , & V_30 -> V_80 , V_36 ) ;
}
if ( V_19 )
goto V_34;
if ( V_30 -> V_49 -> V_36 -> V_323 != V_36 -> V_323 ) {
F_76 ( L_101 ) ;
V_19 = - V_86 ;
goto V_34;
}
if ( V_574 -> V_270 & V_583 ) {
V_576 = F_203 ( sizeof *V_576 , V_23 ) ;
if ( ! V_576 ) {
V_19 = - V_65 ;
goto V_34;
}
V_576 -> V_584 . V_37 . type = V_585 ;
V_576 -> V_584 . V_37 . V_512 = sizeof( V_576 -> V_584 ) ;
V_576 -> V_584 . V_586 = V_574 -> V_586 ;
V_19 = F_247 ( V_13 , V_221 , & V_576 -> V_37 , & V_576 -> V_584 . V_37 ) ;
if ( V_19 ) {
F_66 ( V_576 ) ;
goto V_34;
}
}
V_30 -> V_49 -> V_160 = V_30 -> V_49 -> V_36 ;
V_19 = V_30 -> V_38 -> V_574 ( V_30 , V_36 , V_576 , V_574 -> V_270 ) ;
if ( V_19 ) {
if ( V_574 -> V_270 & V_583 )
F_248 ( V_13 , & V_576 -> V_37 ) ;
V_30 -> V_49 -> V_160 = NULL ;
} else {
V_30 -> V_49 -> V_36 = V_36 ;
V_36 = NULL ;
}
V_34:
if ( V_36 )
F_52 ( V_36 ) ;
if ( V_30 -> V_49 -> V_160 )
F_52 ( V_30 -> V_49 -> V_160 ) ;
V_30 -> V_49 -> V_160 = NULL ;
F_131 ( V_30 ) ;
return V_19 ;
}
void F_249 ( struct V_12 * V_13 )
{
struct V_29 * V_30 ;
struct V_47 * V_48 ;
struct V_131 * V_132 ;
struct V_77 * V_78 ;
F_50 (plane, dev)
if ( V_48 -> V_38 -> V_587 )
V_48 -> V_38 -> V_587 ( V_48 ) ;
F_33 (crtc, dev)
if ( V_30 -> V_38 -> V_587 )
V_30 -> V_38 -> V_587 ( V_30 ) ;
F_94 (encoder, dev)
if ( V_132 -> V_38 -> V_587 )
V_132 -> V_38 -> V_587 ( V_132 ) ;
F_10 ( & V_13 -> V_20 . V_62 ) ;
F_126 (connector, dev)
if ( V_78 -> V_38 -> V_587 )
V_78 -> V_38 -> V_587 ( V_78 ) ;
F_13 ( & V_13 -> V_20 . V_62 ) ;
}
int F_250 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_588 * args = V_219 ;
T_3 V_435 , V_589 , V_546 ;
if ( ! V_13 -> V_590 -> V_591 )
return - V_468 ;
if ( ! args -> V_316 || ! args -> V_317 || ! args -> V_366 )
return - V_86 ;
V_435 = F_251 ( args -> V_366 , 8 ) ;
if ( ! V_435 || V_435 > 0xffffffffU / args -> V_316 )
return - V_86 ;
V_589 = V_435 * args -> V_316 ;
if ( args -> V_317 > 0xffffffffU / V_589 )
return - V_86 ;
V_546 = args -> V_317 * V_589 ;
if ( F_252 ( V_546 ) == 0 )
return - V_86 ;
args -> V_352 = 0 ;
args -> V_378 = 0 ;
args -> V_546 = 0 ;
return V_13 -> V_590 -> V_591 ( V_221 , V_13 , args ) ;
}
int F_253 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_592 * args = V_219 ;
if ( ! V_13 -> V_590 -> V_593 )
return - V_468 ;
return V_13 -> V_590 -> V_593 ( V_221 , V_13 , args -> V_352 , & args -> V_594 ) ;
}
int F_254 ( struct V_12 * V_13 ,
void * V_219 , struct V_220 * V_221 )
{
struct V_595 * args = V_219 ;
if ( ! V_13 -> V_590 -> V_596 )
return - V_468 ;
return V_13 -> V_590 -> V_596 ( V_221 , V_13 , args -> V_352 ) ;
}
unsigned int F_255 ( unsigned int V_335 ,
unsigned int V_597 )
{
if ( V_335 & ~ V_597 ) {
V_335 ^= F_161 ( V_598 ) | F_161 ( V_599 ) ;
V_335 = ( V_335 & V_600 ) |
F_161 ( ( F_256 ( V_335 & V_601 ) + 1 ) % 4 ) ;
}
return V_335 ;
}
void F_257 ( struct V_12 * V_13 )
{
F_258 ( & V_13 -> V_20 . V_62 ) ;
F_58 ( & V_13 -> V_20 . V_289 ) ;
F_258 ( & V_13 -> V_20 . V_21 ) ;
F_258 ( & V_13 -> V_20 . V_43 ) ;
F_258 ( & V_13 -> V_20 . V_510 ) ;
F_38 ( & V_13 -> V_20 . V_46 ) ;
F_38 ( & V_13 -> V_20 . V_67 ) ;
F_38 ( & V_13 -> V_20 . V_117 ) ;
F_38 ( & V_13 -> V_20 . V_137 ) ;
F_38 ( & V_13 -> V_20 . V_480 ) ;
F_38 ( & V_13 -> V_20 . V_516 ) ;
F_38 ( & V_13 -> V_20 . V_144 ) ;
F_259 ( & V_13 -> V_20 . V_22 ) ;
F_259 ( & V_13 -> V_20 . V_602 ) ;
F_3 ( & V_13 -> V_20 . V_106 ) ;
F_32 ( V_13 ) ;
F_109 ( V_13 ) ;
F_34 ( V_13 ) ;
V_13 -> V_20 . V_44 = 0 ;
V_13 -> V_20 . V_118 = 0 ;
V_13 -> V_20 . V_69 = 0 ;
V_13 -> V_20 . V_138 = 0 ;
V_13 -> V_20 . V_147 = 0 ;
V_13 -> V_20 . V_145 = 0 ;
}
void F_260 ( struct V_12 * V_13 )
{
struct V_77 * V_78 , * V_603 ;
struct V_29 * V_30 , * V_604 ;
struct V_131 * V_132 , * V_605 ;
struct V_35 * V_36 , * V_606 ;
struct V_166 * V_471 , * V_494 ;
struct V_508 * V_509 , * V_517 ;
struct V_47 * V_48 , * V_607 ;
F_84 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_132 -> V_38 -> V_39 ( V_132 ) ;
}
F_84 (connector, ot,
&dev->mode_config.connector_list, head) {
V_78 -> V_38 -> V_39 ( V_78 ) ;
}
F_84 (property, pt, &dev->mode_config.property_list,
head) {
F_204 ( V_13 , V_471 ) ;
}
F_84 (plane, plt, &dev->mode_config.plane_list,
head) {
V_48 -> V_38 -> V_39 ( V_48 ) ;
}
F_84 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_30 -> V_38 -> V_39 ( V_30 ) ;
}
F_84 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_217 ( V_509 ) ;
}
F_46 ( ! F_47 ( & V_13 -> V_20 . V_46 ) ) ;
F_84 (fb, fbt, &dev->mode_config.fb_list, head) {
F_35 ( & V_36 -> V_37 . V_26 ) ;
}
F_5 ( & V_13 -> V_20 . V_106 ) ;
F_261 ( & V_13 -> V_20 . V_602 ) ;
F_261 ( & V_13 -> V_20 . V_22 ) ;
F_67 ( & V_13 -> V_20 . V_289 ) ;
}
struct V_166 * F_262 ( struct V_12 * V_13 ,
unsigned int V_597 )
{
static const struct V_481 V_482 [] = {
{ V_608 , L_102 } ,
{ V_336 , L_103 } ,
{ V_609 , L_104 } ,
{ V_337 , L_105 } ,
{ V_598 , L_106 } ,
{ V_599 , L_107 } ,
} ;
return F_205 ( V_13 , 0 , L_108 ,
V_482 , F_2 ( V_482 ) ,
V_597 ) ;
}
static void F_263 ( struct V_18 * V_18 )
{
struct V_610 * V_611 = F_36 ( V_18 , struct V_610 , V_26 ) ;
struct V_12 * V_13 = V_611 -> V_13 ;
F_10 ( & V_13 -> V_20 . V_21 ) ;
F_18 ( & V_13 -> V_20 . V_602 , V_611 -> V_24 ) ;
F_13 ( & V_13 -> V_20 . V_21 ) ;
F_66 ( V_611 ) ;
}
void F_83 ( struct V_12 * V_13 ,
struct V_610 * V_611 )
{
F_26 ( & V_611 -> V_26 , F_263 ) ;
}
struct V_610 * F_264 ( struct V_12 * V_13 ,
char V_612 [ 8 ] )
{
struct V_610 * V_611 ;
int V_24 ;
F_10 ( & V_13 -> V_20 . V_21 ) ;
F_265 (&dev->mode_config.tile_idr, tg, id) {
if ( ! memcmp ( V_611 -> V_613 , V_612 , 8 ) ) {
if ( ! F_21 ( & V_611 -> V_26 ) )
V_611 = NULL ;
F_13 ( & V_13 -> V_20 . V_21 ) ;
return V_611 ;
}
}
F_13 ( & V_13 -> V_20 . V_21 ) ;
return NULL ;
}
struct V_610 * F_266 ( struct V_12 * V_13 ,
char V_612 [ 8 ] )
{
struct V_610 * V_611 ;
int V_19 ;
V_611 = F_203 ( sizeof( * V_611 ) , V_23 ) ;
if ( ! V_611 )
return F_183 ( - V_65 ) ;
F_12 ( & V_611 -> V_26 ) ;
memcpy ( V_611 -> V_613 , V_612 , 8 ) ;
V_611 -> V_13 = V_13 ;
F_10 ( & V_13 -> V_20 . V_21 ) ;
V_19 = F_11 ( & V_13 -> V_20 . V_602 , V_611 , 1 , 0 , V_23 ) ;
if ( V_19 >= 0 ) {
V_611 -> V_24 = V_19 ;
} else {
F_66 ( V_611 ) ;
V_611 = F_183 ( V_19 ) ;
}
F_13 ( & V_13 -> V_20 . V_21 ) ;
return V_611 ;
}
void F_267 ( struct V_29 * V_30 ,
T_10 V_614 ,
bool V_615 ,
T_10 V_616 )
{
struct V_12 * V_13 = V_30 -> V_13 ;
struct V_56 * V_57 = & V_13 -> V_20 ;
if ( V_614 ) {
F_64 ( & V_30 -> V_37 ,
V_57 -> V_178 , 0 ) ;
F_64 ( & V_30 -> V_37 ,
V_57 -> V_179 ,
V_614 ) ;
}
if ( V_615 )
F_64 ( & V_30 -> V_37 ,
V_57 -> V_180 , 0 ) ;
if ( V_616 ) {
F_64 ( & V_30 -> V_37 ,
V_57 -> V_181 , 0 ) ;
F_64 ( & V_30 -> V_37 ,
V_57 -> V_182 ,
V_616 ) ;
}
}
