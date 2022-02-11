void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_9 ) ;
if ( F_3 ( ! V_7 ) )
return;
F_4 ( & V_4 -> V_10 ) ;
F_5 ( V_7 , 0 ) ;
V_11:
V_8 = F_6 ( & V_4 -> V_12 , V_7 ) ;
if ( V_8 )
goto V_13;
V_8 = F_7 ( V_2 , V_7 ) ;
if ( V_8 )
goto V_13;
F_3 ( V_4 -> V_14 ) ;
V_4 -> V_14 = V_7 ;
F_8 ( V_2 ) ;
return;
V_13:
if ( V_8 == - V_15 ) {
F_9 ( V_7 ) ;
goto V_11;
}
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_14 ;
if ( F_3 ( ! V_7 ) )
return;
V_4 -> V_14 = NULL ;
F_11 ( V_7 ) ;
F_12 ( V_7 ) ;
F_13 ( V_7 ) ;
F_14 ( & V_2 -> V_5 . V_10 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
if ( V_18 )
return;
F_15 (crtc, &dev->mode_config.crtc_list, head)
F_3 ( ! F_16 ( & V_17 -> V_10 ) ) ;
F_3 ( ! F_16 ( & V_2 -> V_5 . V_12 ) ) ;
F_3 ( ! F_17 ( & V_2 -> V_5 . V_10 ) ) ;
}
void F_18 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_20 ) ; V_19 ++ )
F_20 ( & V_20 [ V_19 ] . V_21 ) ;
}
void F_21 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_20 ) ; V_19 ++ )
F_22 ( & V_20 [ V_19 ] . V_21 ) ;
}
const char * F_23 ( enum V_22 V_23 )
{
if ( V_23 == V_24 )
return L_1 ;
else if ( V_23 == V_25 )
return L_2 ;
else
return L_3 ;
}
const char * F_24 ( enum V_26 V_27 )
{
return V_28 [ V_27 ] . V_29 ;
}
static char F_25 ( int V_30 )
{
return isascii ( V_30 ) && isprint ( V_30 ) ? V_30 : '?' ;
}
const char * F_26 ( T_1 V_31 )
{
static char V_32 [ 32 ] ;
snprintf ( V_32 , sizeof( V_32 ) ,
L_4 ,
F_25 ( V_31 & 0xff ) ,
F_25 ( ( V_31 >> 8 ) & 0xff ) ,
F_25 ( ( V_31 >> 16 ) & 0xff ) ,
F_25 ( ( V_31 >> 24 ) & 0x7f ) ,
V_31 & V_33 ? L_5 : L_6 ,
V_31 ) ;
return V_32 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
T_1 V_36 ,
bool V_37 )
{
int V_8 ;
F_4 ( & V_2 -> V_5 . V_38 ) ;
V_8 = F_28 ( & V_2 -> V_5 . V_39 , V_37 ? V_35 : NULL , 1 , 0 , V_9 ) ;
if ( V_8 >= 0 ) {
V_35 -> V_40 = V_8 ;
V_35 -> type = V_36 ;
}
F_14 ( & V_2 -> V_5 . V_38 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_34 * V_35 , T_1 V_36 )
{
return F_27 ( V_2 , V_35 , V_36 , true ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
F_4 ( & V_2 -> V_5 . V_38 ) ;
F_31 ( & V_2 -> V_5 . V_39 , V_35 , V_35 -> V_40 ) ;
F_14 ( & V_2 -> V_5 . V_38 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_34 * V_41 )
{
F_4 ( & V_2 -> V_5 . V_38 ) ;
F_33 ( & V_2 -> V_5 . V_39 , V_41 -> V_40 ) ;
F_14 ( & V_2 -> V_5 . V_38 ) ;
}
static struct V_34 * F_34 ( struct V_1 * V_2 ,
T_1 V_40 , T_1 type )
{
struct V_34 * V_35 = NULL ;
F_4 ( & V_2 -> V_5 . V_38 ) ;
V_35 = F_35 ( & V_2 -> V_5 . V_39 , V_40 ) ;
if ( V_35 && type != V_42 && V_35 -> type != type )
V_35 = NULL ;
if ( V_35 && V_35 -> V_40 != V_40 )
V_35 = NULL ;
if ( V_35 && ( V_35 -> type == V_43 ) )
V_35 = NULL ;
F_14 ( & V_2 -> V_5 . V_38 ) ;
return V_35 ;
}
struct V_34 * F_36 ( struct V_1 * V_2 ,
T_1 V_40 , T_1 type )
{
struct V_34 * V_35 = NULL ;
F_3 ( type == V_43 ) ;
V_35 = F_34 ( V_2 , V_40 , type ) ;
return V_35 ;
}
int F_37 ( struct V_1 * V_2 , struct V_44 * V_45 ,
const struct V_46 * V_47 )
{
int V_8 ;
F_4 ( & V_2 -> V_5 . V_48 ) ;
F_38 ( & V_45 -> V_49 ) ;
F_39 ( & V_45 -> V_50 ) ;
V_45 -> V_2 = V_2 ;
V_45 -> V_47 = V_47 ;
V_8 = F_29 ( V_2 , & V_45 -> V_51 , V_43 ) ;
if ( V_8 )
goto V_52;
F_40 ( V_45 ) ;
V_2 -> V_5 . V_53 ++ ;
F_41 ( & V_45 -> V_54 , & V_2 -> V_5 . V_55 ) ;
V_52:
F_14 ( & V_2 -> V_5 . V_48 ) ;
return 0 ;
}
static void F_42 ( struct V_56 * V_56 )
{
struct V_44 * V_45 =
F_43 ( V_56 , struct V_44 , V_49 ) ;
V_45 -> V_47 -> V_57 ( V_45 ) ;
}
static struct V_44 * F_44 ( struct V_1 * V_2 ,
T_1 V_40 )
{
struct V_34 * V_35 = NULL ;
struct V_44 * V_45 ;
F_4 ( & V_2 -> V_5 . V_38 ) ;
V_35 = F_35 ( & V_2 -> V_5 . V_39 , V_40 ) ;
if ( ! V_35 || ( V_35 -> type != V_43 ) || ( V_35 -> V_40 != V_40 ) )
V_45 = NULL ;
else
V_45 = F_45 ( V_35 ) ;
F_14 ( & V_2 -> V_5 . V_38 ) ;
return V_45 ;
}
struct V_44 * F_46 ( struct V_1 * V_2 ,
T_1 V_40 )
{
struct V_44 * V_45 ;
F_4 ( & V_2 -> V_5 . V_48 ) ;
V_45 = F_44 ( V_2 , V_40 ) ;
if ( V_45 )
F_40 ( V_45 ) ;
F_14 ( & V_2 -> V_5 . V_48 ) ;
return V_45 ;
}
void F_47 ( struct V_44 * V_45 )
{
F_48 ( L_7 , V_45 , V_45 -> V_51 . V_40 , F_49 ( & V_45 -> V_49 . V_49 ) ) ;
F_50 ( & V_45 -> V_49 , F_42 ) ;
}
void F_40 ( struct V_44 * V_45 )
{
F_48 ( L_7 , V_45 , V_45 -> V_51 . V_40 , F_49 ( & V_45 -> V_49 . V_49 ) ) ;
F_51 ( & V_45 -> V_49 ) ;
}
static void F_52 ( struct V_56 * V_56 )
{
F_53 () ;
}
static void F_54 ( struct V_44 * V_45 )
{
F_48 ( L_7 , V_45 , V_45 -> V_51 . V_40 , F_49 ( & V_45 -> V_49 . V_49 ) ) ;
F_50 ( & V_45 -> V_49 , F_52 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
F_4 ( & V_2 -> V_5 . V_38 ) ;
F_33 ( & V_2 -> V_5 . V_39 , V_45 -> V_51 . V_40 ) ;
F_14 ( & V_2 -> V_5 . V_38 ) ;
V_45 -> V_51 . V_40 = 0 ;
F_54 ( V_45 ) ;
}
void F_56 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
F_4 ( & V_2 -> V_5 . V_48 ) ;
F_55 ( V_2 , V_45 ) ;
F_14 ( & V_2 -> V_5 . V_48 ) ;
}
void F_57 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
F_4 ( & V_2 -> V_5 . V_48 ) ;
F_58 ( & V_45 -> V_54 ) ;
V_2 -> V_5 . V_53 -- ;
F_14 ( & V_2 -> V_5 . V_48 ) ;
}
void F_59 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_16 * V_17 ;
struct V_58 * V_59 ;
struct V_60 V_61 ;
int V_8 ;
F_3 ( ! F_60 ( & V_45 -> V_50 ) ) ;
if ( F_49 ( & V_45 -> V_49 . V_49 ) > 1 ) {
F_1 ( V_2 ) ;
F_15 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_17 -> V_62 -> V_45 == V_45 ) {
memset ( & V_61 , 0 , sizeof( struct V_60 ) ) ;
V_61 . V_17 = V_17 ;
V_61 . V_45 = NULL ;
V_8 = F_61 ( & V_61 ) ;
if ( V_8 )
F_62 ( L_8 , V_17 ) ;
}
}
F_15 (plane, &dev->mode_config.plane_list, head) {
if ( V_59 -> V_45 == V_45 )
F_63 ( V_59 ) ;
}
F_10 ( V_2 ) ;
}
F_47 ( V_45 ) ;
}
int F_64 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_58 * V_62 ,
struct V_58 * V_63 ,
const struct V_64 * V_47 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_8 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_47 = V_47 ;
V_17 -> V_65 = false ;
F_1 ( V_2 ) ;
F_65 ( & V_17 -> V_10 ) ;
F_6 ( & V_17 -> V_10 , V_4 -> V_14 ) ;
V_8 = F_29 ( V_2 , & V_17 -> V_51 , V_66 ) ;
if ( V_8 )
goto V_52;
V_17 -> V_51 . V_67 = & V_17 -> V_67 ;
F_66 ( & V_17 -> V_54 , & V_4 -> V_68 ) ;
V_4 -> V_69 ++ ;
V_17 -> V_62 = V_62 ;
V_17 -> V_63 = V_63 ;
if ( V_62 )
V_62 -> V_70 = 1 << F_67 ( V_17 ) ;
if ( V_63 )
V_63 -> V_70 = 1 << F_67 ( V_17 ) ;
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
void F_68 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
F_13 ( V_17 -> V_71 ) ;
V_17 -> V_71 = NULL ;
F_69 ( & V_17 -> V_10 ) ;
F_32 ( V_2 , & V_17 -> V_51 ) ;
F_58 ( & V_17 -> V_54 ) ;
V_2 -> V_5 . V_69 -- ;
}
unsigned int F_67 ( struct V_16 * V_17 )
{
unsigned int V_72 = 0 ;
struct V_16 * V_73 ;
F_15 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_73 == V_17 )
return V_72 ;
V_72 ++ ;
}
F_53 () ;
}
static void F_70 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
F_58 ( & V_77 -> V_54 ) ;
F_71 ( V_75 -> V_2 , V_77 ) ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
const struct V_78 * V_47 ,
int V_79 )
{
int V_8 ;
struct V_21 * V_80 =
& V_20 [ V_79 ] . V_21 ;
F_1 ( V_2 ) ;
V_8 = F_27 ( V_2 , & V_75 -> V_51 , V_81 , false ) ;
if ( V_8 )
goto V_82;
V_75 -> V_51 . V_67 = & V_75 -> V_67 ;
V_75 -> V_2 = V_2 ;
V_75 -> V_47 = V_47 ;
V_75 -> V_79 = V_79 ;
V_75 -> V_83 =
F_73 ( V_80 , 1 , 0 , V_9 ) ;
if ( V_75 -> V_83 < 0 ) {
V_8 = V_75 -> V_83 ;
goto V_84;
}
V_75 -> V_29 =
F_74 ( V_9 , L_9 ,
V_20 [ V_79 ] . V_29 ,
V_75 -> V_83 ) ;
if ( ! V_75 -> V_29 ) {
V_8 = - V_85 ;
goto V_84;
}
F_39 ( & V_75 -> V_86 ) ;
F_39 ( & V_75 -> V_87 ) ;
V_75 -> V_88 = NULL ;
V_75 -> V_23 = V_89 ;
F_66 ( & V_75 -> V_54 , & V_2 -> V_5 . V_90 ) ;
V_2 -> V_5 . V_91 ++ ;
if ( V_79 != V_92 )
F_75 ( & V_75 -> V_51 ,
V_2 -> V_5 . V_93 ,
0 ) ;
F_75 ( & V_75 -> V_51 ,
V_2 -> V_5 . V_94 , 0 ) ;
V_75 -> V_95 = NULL ;
V_84:
if ( V_8 )
F_32 ( V_2 , & V_75 -> V_51 ) ;
V_82:
F_10 ( V_2 ) ;
return V_8 ;
}
void F_76 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
struct V_76 * V_77 , * V_96 ;
F_77 (mode, t, &connector->probed_modes, head)
F_70 ( V_75 , V_77 ) ;
F_77 (mode, t, &connector->modes, head)
F_70 ( V_75 , V_77 ) ;
F_78 ( & V_20 [ V_75 -> V_79 ] . V_21 ,
V_75 -> V_83 ) ;
F_32 ( V_2 , & V_75 -> V_51 ) ;
F_13 ( V_75 -> V_29 ) ;
V_75 -> V_29 = NULL ;
F_58 ( & V_75 -> V_54 ) ;
V_2 -> V_5 . V_91 -- ;
}
int F_79 ( struct V_74 * V_75 )
{
int V_8 ;
F_30 ( V_75 -> V_2 , & V_75 -> V_51 ) ;
V_8 = F_80 ( V_75 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_81 ( V_75 ) ;
if ( V_8 ) {
F_82 ( V_75 ) ;
return V_8 ;
}
return 0 ;
}
void F_83 ( struct V_74 * V_75 )
{
F_82 ( V_75 ) ;
F_84 ( V_75 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
F_15 (connector, &dev->mode_config.connector_list, head)
F_83 ( V_75 ) ;
}
int F_86 ( struct V_1 * V_2 , struct V_97 * V_98 ,
const struct V_99 * V_47 )
{
int V_8 ;
F_1 ( V_2 ) ;
V_8 = F_29 ( V_2 , & V_98 -> V_51 , V_100 ) ;
if ( V_8 )
goto V_52;
V_98 -> V_2 = V_2 ;
V_98 -> V_47 = V_47 ;
F_66 ( & V_98 -> V_54 , & V_2 -> V_5 . V_101 ) ;
V_2 -> V_5 . V_102 ++ ;
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
void F_87 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = V_98 -> V_2 ;
F_1 ( V_2 ) ;
F_32 ( V_2 , & V_98 -> V_51 ) ;
F_58 ( & V_98 -> V_54 ) ;
V_2 -> V_5 . V_102 -- ;
F_10 ( V_2 ) ;
}
int F_88 ( struct V_1 * V_2 ,
struct V_103 * V_104 ,
const struct V_105 * V_47 ,
int V_106 )
{
int V_8 ;
F_1 ( V_2 ) ;
V_8 = F_29 ( V_2 , & V_104 -> V_51 , V_107 ) ;
if ( V_8 )
goto V_82;
V_104 -> V_2 = V_2 ;
V_104 -> V_106 = V_106 ;
V_104 -> V_47 = V_47 ;
V_104 -> V_29 = F_74 ( V_9 , L_9 ,
V_108 [ V_106 ] . V_29 ,
V_104 -> V_51 . V_40 ) ;
if ( ! V_104 -> V_29 ) {
V_8 = - V_85 ;
goto V_84;
}
F_66 ( & V_104 -> V_54 , & V_2 -> V_5 . V_109 ) ;
V_2 -> V_5 . V_110 ++ ;
V_84:
if ( V_8 )
F_32 ( V_2 , & V_104 -> V_51 ) ;
V_82:
F_10 ( V_2 ) ;
return V_8 ;
}
void F_89 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
F_1 ( V_2 ) ;
F_32 ( V_2 , & V_104 -> V_51 ) ;
F_13 ( V_104 -> V_29 ) ;
V_104 -> V_29 = NULL ;
F_58 ( & V_104 -> V_54 ) ;
V_2 -> V_5 . V_110 -- ;
F_10 ( V_2 ) ;
}
int F_90 ( struct V_1 * V_2 , struct V_58 * V_59 ,
unsigned long V_70 ,
const struct V_111 * V_47 ,
const T_1 * V_112 , T_1 V_113 ,
enum V_114 type )
{
int V_8 ;
F_1 ( V_2 ) ;
V_8 = F_29 ( V_2 , & V_59 -> V_51 , V_115 ) ;
if ( V_8 )
goto V_52;
V_59 -> V_51 . V_67 = & V_59 -> V_67 ;
V_59 -> V_2 = V_2 ;
V_59 -> V_47 = V_47 ;
V_59 -> V_116 = F_91 ( sizeof( T_1 ) * V_113 ,
V_9 ) ;
if ( ! V_59 -> V_116 ) {
F_92 ( L_10 ) ;
F_32 ( V_2 , & V_59 -> V_51 ) ;
V_8 = - V_85 ;
goto V_52;
}
memcpy ( V_59 -> V_116 , V_112 , V_113 * sizeof( T_1 ) ) ;
V_59 -> V_113 = V_113 ;
V_59 -> V_70 = V_70 ;
V_59 -> type = type ;
F_66 ( & V_59 -> V_54 , & V_2 -> V_5 . V_117 ) ;
V_2 -> V_5 . V_118 ++ ;
if ( V_59 -> type == V_119 )
V_2 -> V_5 . V_120 ++ ;
F_75 ( & V_59 -> V_51 ,
V_2 -> V_5 . V_121 ,
V_59 -> type ) ;
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_93 ( struct V_1 * V_2 , struct V_58 * V_59 ,
unsigned long V_70 ,
const struct V_111 * V_47 ,
const T_1 * V_112 , T_1 V_113 ,
bool V_122 )
{
enum V_114 type ;
type = V_122 ? V_123 : V_119 ;
return F_90 ( V_2 , V_59 , V_70 , V_47 ,
V_112 , V_113 , type ) ;
}
void F_94 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
F_1 ( V_2 ) ;
F_13 ( V_59 -> V_116 ) ;
F_32 ( V_2 , & V_59 -> V_51 ) ;
F_95 ( F_60 ( & V_59 -> V_54 ) ) ;
F_58 ( & V_59 -> V_54 ) ;
V_2 -> V_5 . V_118 -- ;
if ( V_59 -> type == V_119 )
V_2 -> V_5 . V_120 -- ;
F_10 ( V_2 ) ;
}
void F_63 ( struct V_58 * V_59 )
{
struct V_44 * V_124 = V_59 -> V_45 ;
int V_8 ;
if ( ! V_124 )
return;
V_8 = V_59 -> V_47 -> V_125 ( V_59 ) ;
if ( V_8 ) {
F_62 ( L_11 ) ;
return;
}
F_54 ( V_124 ) ;
V_59 -> V_45 = NULL ;
V_59 -> V_17 = NULL ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_126 * V_127 ;
struct V_126 * V_128 ;
struct V_126 * V_129 ;
V_127 = F_97 ( V_2 , V_130 |
V_131 ,
L_12 , 0 ) ;
V_2 -> V_5 . V_93 = V_127 ;
V_128 = F_98 ( V_2 , 0 ,
L_13 , V_132 ,
F_19 ( V_132 ) ) ;
V_2 -> V_5 . V_94 = V_128 ;
V_129 = F_97 ( V_2 ,
V_130 |
V_131 ,
L_14 , 0 ) ;
V_2 -> V_5 . V_133 = V_129 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_126 * type ;
type = F_98 ( V_2 , V_131 ,
L_15 , V_134 ,
F_19 ( V_134 ) ) ;
V_2 -> V_5 . V_121 = type ;
return 0 ;
}
int F_100 ( struct V_1 * V_2 )
{
struct V_126 * V_135 ;
struct V_126 * V_136 ;
if ( V_2 -> V_5 . V_137 )
return 0 ;
V_135 =
F_98 ( V_2 , 0 ,
L_16 ,
V_138 ,
F_19 ( V_138 ) ) ;
V_2 -> V_5 . V_137 = V_135 ;
V_136 = F_98 ( V_2 , V_131 ,
L_17 ,
V_139 ,
F_19 ( V_139 ) ) ;
V_2 -> V_5 . V_140 = V_136 ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , int V_141 ,
char * V_87 [] )
{
struct V_126 * V_142 ;
struct V_126 * V_143 ;
int V_19 ;
if ( V_2 -> V_5 . V_144 )
return 0 ;
V_142 = F_98 ( V_2 , 0 ,
L_16 ,
V_145 ,
F_19 ( V_145 ) ) ;
V_2 -> V_5 . V_144 = V_142 ;
V_143 =
F_98 ( V_2 , V_131 ,
L_17 ,
V_146 ,
F_19 ( V_146 ) ) ;
V_2 -> V_5 . V_147 = V_143 ;
V_2 -> V_5 . V_148 =
F_102 ( V_2 , 0 , L_18 , 0 , 100 ) ;
V_2 -> V_5 . V_149 =
F_102 ( V_2 , 0 , L_19 , 0 , 100 ) ;
V_2 -> V_5 . V_150 =
F_102 ( V_2 , 0 , L_20 , 0 , 100 ) ;
V_2 -> V_5 . V_151 =
F_102 ( V_2 , 0 , L_21 , 0 , 100 ) ;
V_2 -> V_5 . V_152 =
F_97 ( V_2 , V_153 ,
L_22 , V_141 ) ;
for ( V_19 = 0 ; V_19 < V_141 ; V_19 ++ )
F_103 ( V_2 -> V_5 . V_152 , V_19 ,
V_19 , V_87 [ V_19 ] ) ;
V_2 -> V_5 . V_154 =
F_102 ( V_2 , 0 , L_23 , 0 , 100 ) ;
V_2 -> V_5 . V_155 =
F_102 ( V_2 , 0 , L_24 , 0 , 100 ) ;
V_2 -> V_5 . V_156 =
F_102 ( V_2 , 0 , L_25 , 0 , 100 ) ;
V_2 -> V_5 . V_157 =
F_102 ( V_2 , 0 , L_26 , 0 , 100 ) ;
V_2 -> V_5 . V_158 =
F_102 ( V_2 , 0 , L_27 , 0 , 100 ) ;
V_2 -> V_5 . V_159 =
F_102 ( V_2 , 0 , L_28 , 0 , 100 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
struct V_126 * V_160 ;
if ( V_2 -> V_5 . V_161 )
return 0 ;
V_160 =
F_98 ( V_2 , 0 , L_29 ,
V_162 ,
F_19 ( V_162 ) ) ;
V_2 -> V_5 . V_161 = V_160 ;
return 0 ;
}
int F_105 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_163 )
return 0 ;
V_2 -> V_5 . V_163 =
F_98 ( V_2 , 0 , L_30 ,
V_164 ,
F_19 ( V_164 ) ) ;
if ( V_2 -> V_5 . V_163 == NULL )
return - V_85 ;
return 0 ;
}
int F_106 ( struct V_1 * V_2 )
{
struct V_126 * V_165 ;
if ( V_2 -> V_5 . V_166 )
return 0 ;
V_165 =
F_98 ( V_2 , V_131 ,
L_31 ,
V_167 ,
F_19 ( V_167 ) ) ;
V_2 -> V_5 . V_166 = V_165 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_168 * V_169 )
{
T_1 V_170 = 0 ;
V_170 += V_2 -> V_5 . V_69 ;
V_170 += V_2 -> V_5 . V_91 ;
V_170 += V_2 -> V_5 . V_110 ;
V_170 += V_2 -> V_5 . V_102 ;
V_169 -> V_171 = F_2 ( V_170 * sizeof( T_1 ) , V_9 ) ;
if ( ! V_169 -> V_171 )
return - V_85 ;
V_169 -> V_172 = 0 ;
V_169 -> V_173 = 0 ;
V_169 -> V_174 = 0 ;
V_169 -> V_175 = 0 ;
return 0 ;
}
void F_108 ( struct V_168 * V_169 )
{
F_13 ( V_169 -> V_171 ) ;
V_169 -> V_171 = NULL ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
struct V_16 * V_17 ;
struct V_103 * V_104 ;
struct V_74 * V_75 ;
struct V_97 * V_98 ;
int V_8 ;
if ( ( V_8 = F_107 ( V_2 , V_169 ) ) )
return V_8 ;
F_15 (crtc, &dev->mode_config.crtc_list, head)
V_169 -> V_171 [ V_169 -> V_172 ++ ] = V_17 -> V_51 . V_40 ;
F_15 (encoder, &dev->mode_config.encoder_list, head)
V_169 -> V_171 [ V_169 -> V_172 + V_169 -> V_174 ++ ] =
V_104 -> V_51 . V_40 ;
F_15 (connector, &dev->mode_config.connector_list, head)
V_169 -> V_171 [ V_169 -> V_172 + V_169 -> V_174 +
V_169 -> V_173 ++ ] = V_75 -> V_51 . V_40 ;
F_15 (bridge, &dev->mode_config.bridge_list, head)
V_169 -> V_171 [ V_169 -> V_172 + V_169 -> V_174 +
V_169 -> V_173 + V_169 -> V_175 ++ ] =
V_98 -> V_51 . V_40 ;
return 0 ;
}
void F_110 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_108 ( & V_2 -> V_62 -> V_176 ) ;
F_109 ( V_2 , & V_2 -> V_62 -> V_176 ) ;
F_10 ( V_2 ) ;
}
static void F_111 ( struct V_177 * V_52 ,
const struct V_76 * V_178 )
{
F_112 ( V_178 -> V_179 > V_180 || V_178 -> V_181 > V_180 ||
V_178 -> V_182 > V_180 || V_178 -> V_183 > V_180 ||
V_178 -> V_184 > V_180 || V_178 -> V_185 > V_180 ||
V_178 -> V_186 > V_180 || V_178 -> V_187 > V_180 ||
V_178 -> V_188 > V_180 || V_178 -> V_189 > V_180 ,
L_32 ) ;
V_52 -> clock = V_178 -> clock ;
V_52 -> V_179 = V_178 -> V_179 ;
V_52 -> V_181 = V_178 -> V_181 ;
V_52 -> V_182 = V_178 -> V_182 ;
V_52 -> V_183 = V_178 -> V_183 ;
V_52 -> V_184 = V_178 -> V_184 ;
V_52 -> V_185 = V_178 -> V_185 ;
V_52 -> V_186 = V_178 -> V_186 ;
V_52 -> V_187 = V_178 -> V_187 ;
V_52 -> V_188 = V_178 -> V_188 ;
V_52 -> V_189 = V_178 -> V_189 ;
V_52 -> V_190 = V_178 -> V_190 ;
V_52 -> V_191 = V_178 -> V_191 ;
V_52 -> type = V_178 -> type ;
strncpy ( V_52 -> V_29 , V_178 -> V_29 , V_192 ) ;
V_52 -> V_29 [ V_192 - 1 ] = 0 ;
}
static int F_113 ( struct V_76 * V_52 ,
const struct V_177 * V_178 )
{
if ( V_178 -> clock > V_193 || V_178 -> V_190 > V_193 )
return - V_194 ;
if ( ( V_178 -> V_191 & V_195 ) > V_196 )
return - V_197 ;
V_52 -> clock = V_178 -> clock ;
V_52 -> V_179 = V_178 -> V_179 ;
V_52 -> V_181 = V_178 -> V_181 ;
V_52 -> V_182 = V_178 -> V_182 ;
V_52 -> V_183 = V_178 -> V_183 ;
V_52 -> V_184 = V_178 -> V_184 ;
V_52 -> V_185 = V_178 -> V_185 ;
V_52 -> V_186 = V_178 -> V_186 ;
V_52 -> V_187 = V_178 -> V_187 ;
V_52 -> V_188 = V_178 -> V_188 ;
V_52 -> V_189 = V_178 -> V_189 ;
V_52 -> V_190 = V_178 -> V_190 ;
V_52 -> V_191 = V_178 -> V_191 ;
V_52 -> type = V_178 -> type ;
strncpy ( V_52 -> V_29 , V_178 -> V_29 , V_192 ) ;
V_52 -> V_29 [ V_192 - 1 ] = 0 ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_201 * V_202 = V_198 ;
struct V_203 * V_204 ;
struct V_44 * V_45 ;
struct V_74 * V_75 ;
struct V_16 * V_17 ;
struct V_103 * V_104 ;
int V_8 = 0 ;
int V_205 = 0 ;
int V_206 = 0 ;
int V_207 = 0 ;
int V_208 = 0 ;
int V_209 = 0 , V_19 ;
T_1 T_2 * V_210 ;
T_1 T_2 * V_211 ;
T_1 T_2 * V_212 ;
T_1 T_2 * V_213 ;
struct V_168 * V_176 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_4 ( & V_200 -> V_215 ) ;
F_116 (lh, &file_priv->fbs)
V_207 ++ ;
if ( V_202 -> V_216 >= V_207 ) {
V_209 = 0 ;
V_210 = ( T_1 T_2 * ) ( unsigned long ) V_202 -> V_217 ;
F_15 (fb, &file_priv->fbs, filp_head) {
if ( F_117 ( V_45 -> V_51 . V_40 , V_210 + V_209 ) ) {
F_14 ( & V_200 -> V_215 ) ;
return - V_218 ;
}
V_209 ++ ;
}
}
V_202 -> V_216 = V_207 ;
F_14 ( & V_200 -> V_215 ) ;
F_1 ( V_2 ) ;
if ( ! F_118 ( V_200 ) ) {
V_176 = NULL ;
F_116 (lh, &dev->mode_config.crtc_list)
V_206 ++ ;
F_116 (lh, &dev->mode_config.connector_list)
V_205 ++ ;
F_116 (lh, &dev->mode_config.encoder_list)
V_208 ++ ;
} else {
V_176 = & V_200 -> V_219 -> V_220 -> V_176 ;
V_206 = V_176 -> V_172 ;
V_205 = V_176 -> V_173 ;
V_208 = V_176 -> V_174 ;
}
V_202 -> V_221 = V_2 -> V_5 . V_221 ;
V_202 -> V_222 = V_2 -> V_5 . V_222 ;
V_202 -> V_223 = V_2 -> V_5 . V_223 ;
V_202 -> V_224 = V_2 -> V_5 . V_224 ;
if ( V_202 -> V_225 >= V_206 ) {
V_209 = 0 ;
V_211 = ( T_1 T_2 * ) ( unsigned long ) V_202 -> V_226 ;
if ( ! V_176 ) {
F_15 (crtc, &dev->mode_config.crtc_list,
head) {
F_92 ( L_33 , V_17 -> V_51 . V_40 ) ;
if ( F_117 ( V_17 -> V_51 . V_40 , V_211 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
} else {
for ( V_19 = 0 ; V_19 < V_176 -> V_172 ; V_19 ++ ) {
if ( F_117 ( V_176 -> V_171 [ V_19 ] ,
V_211 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
}
}
V_202 -> V_225 = V_206 ;
if ( V_202 -> V_227 >= V_208 ) {
V_209 = 0 ;
V_213 = ( T_1 T_2 * ) ( unsigned long ) V_202 -> V_228 ;
if ( ! V_176 ) {
F_15 (encoder,
&dev->mode_config.encoder_list,
head) {
F_92 ( L_34 , V_104 -> V_51 . V_40 ,
V_104 -> V_29 ) ;
if ( F_117 ( V_104 -> V_51 . V_40 , V_213 +
V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
} else {
for ( V_19 = V_176 -> V_172 ; V_19 < V_176 -> V_172 + V_176 -> V_174 ; V_19 ++ ) {
if ( F_117 ( V_176 -> V_171 [ V_19 ] ,
V_213 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
}
}
V_202 -> V_227 = V_208 ;
if ( V_202 -> V_229 >= V_205 ) {
V_209 = 0 ;
V_212 = ( T_1 T_2 * ) ( unsigned long ) V_202 -> V_230 ;
if ( ! V_176 ) {
F_15 (connector,
&dev->mode_config.connector_list,
head) {
F_92 ( L_35 ,
V_75 -> V_51 . V_40 ,
V_75 -> V_29 ) ;
if ( F_117 ( V_75 -> V_51 . V_40 ,
V_212 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
} else {
int V_231 = V_176 -> V_172 +
V_176 -> V_174 ;
for ( V_19 = V_231 ; V_19 < V_231 + V_176 -> V_173 ; V_19 ++ ) {
if ( F_117 ( V_176 -> V_171 [ V_19 ] ,
V_212 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
}
}
V_202 -> V_229 = V_205 ;
F_92 ( L_36 , V_202 -> V_225 ,
V_202 -> V_229 , V_202 -> V_227 ) ;
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_119 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_232 * V_233 = V_198 ;
struct V_16 * V_17 ;
int V_8 = 0 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_17 = F_120 ( V_2 , V_233 -> V_211 ) ;
if ( ! V_17 ) {
V_8 = - V_234 ;
goto V_52;
}
V_233 -> V_235 = V_17 -> V_235 ;
V_233 -> V_236 = V_17 -> V_236 ;
V_233 -> V_237 = V_17 -> V_237 ;
if ( V_17 -> V_62 -> V_45 )
V_233 -> V_210 = V_17 -> V_62 -> V_45 -> V_51 . V_40 ;
else
V_233 -> V_210 = 0 ;
if ( V_17 -> V_238 ) {
F_111 ( & V_233 -> V_77 , & V_17 -> V_77 ) ;
V_233 -> V_239 = 1 ;
} else {
V_233 -> V_239 = 0 ;
}
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
static bool F_121 ( const struct V_76 * V_77 ,
const struct V_199 * V_200 )
{
if ( ! V_200 -> V_240 && F_122 ( V_77 ) )
return false ;
return true ;
}
int F_123 ( struct V_1 * V_2 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_241 * V_242 = V_198 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
int V_243 = 0 ;
int V_244 = 0 ;
int V_245 = 0 ;
int V_8 = 0 ;
int V_209 = 0 ;
int V_19 ;
struct V_177 V_246 ;
struct V_177 T_2 * V_247 ;
T_1 T_2 * V_248 ;
T_3 T_2 * V_249 ;
T_1 T_2 * V_250 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
memset ( & V_246 , 0 , sizeof( struct V_177 ) ) ;
F_92 ( L_37 , V_242 -> V_212 ) ;
F_4 ( & V_2 -> V_5 . V_10 ) ;
V_75 = F_124 ( V_2 , V_242 -> V_212 ) ;
if ( ! V_75 ) {
V_8 = - V_234 ;
goto V_52;
}
V_244 = V_75 -> V_67 . V_251 ;
for ( V_19 = 0 ; V_19 < V_252 ; V_19 ++ ) {
if ( V_75 -> V_253 [ V_19 ] != 0 ) {
V_245 ++ ;
}
}
if ( V_242 -> V_254 == 0 ) {
V_75 -> V_47 -> V_255 ( V_75 ,
V_2 -> V_5 . V_223 ,
V_2 -> V_5 . V_221 ) ;
}
F_15 (mode, &connector->modes, head)
if ( F_121 ( V_77 , V_200 ) )
V_243 ++ ;
V_242 -> V_212 = V_75 -> V_51 . V_40 ;
V_242 -> V_79 = V_75 -> V_79 ;
V_242 -> V_83 = V_75 -> V_83 ;
V_242 -> V_256 = V_75 -> V_257 . V_258 ;
V_242 -> V_259 = V_75 -> V_257 . V_260 ;
V_242 -> V_261 = V_75 -> V_257 . V_26 ;
V_242 -> V_262 = V_75 -> V_23 ;
F_6 ( & V_2 -> V_5 . V_12 , NULL ) ;
if ( V_75 -> V_104 )
V_242 -> V_213 = V_75 -> V_104 -> V_51 . V_40 ;
else
V_242 -> V_213 = 0 ;
F_125 ( & V_2 -> V_5 . V_12 ) ;
if ( ( V_242 -> V_254 >= V_243 ) && V_243 ) {
V_209 = 0 ;
V_247 = (struct V_177 T_2 * ) ( unsigned long ) V_242 -> V_263 ;
F_15 (mode, &connector->modes, head) {
if ( ! F_121 ( V_77 , V_200 ) )
continue;
F_111 ( & V_246 , V_77 ) ;
if ( F_126 ( V_247 + V_209 ,
& V_246 , sizeof( V_246 ) ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
}
V_242 -> V_254 = V_243 ;
if ( ( V_242 -> V_264 >= V_244 ) && V_244 ) {
V_209 = 0 ;
V_248 = ( T_1 T_2 * ) ( unsigned long ) ( V_242 -> V_265 ) ;
V_249 = ( T_3 T_2 * ) ( unsigned long ) ( V_242 -> V_266 ) ;
for ( V_19 = 0 ; V_19 < V_75 -> V_67 . V_251 ; V_19 ++ ) {
if ( F_117 ( V_75 -> V_67 . V_267 [ V_19 ] ,
V_248 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
if ( F_117 ( V_75 -> V_67 . V_268 [ V_19 ] ,
V_249 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
}
V_242 -> V_264 = V_244 ;
if ( ( V_242 -> V_227 >= V_245 ) && V_245 ) {
V_209 = 0 ;
V_250 = ( T_1 T_2 * ) ( unsigned long ) ( V_242 -> V_269 ) ;
for ( V_19 = 0 ; V_19 < V_252 ; V_19 ++ ) {
if ( V_75 -> V_253 [ V_19 ] != 0 ) {
if ( F_117 ( V_75 -> V_253 [ V_19 ] ,
V_250 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
}
}
V_242 -> V_227 = V_245 ;
V_52:
F_14 ( & V_2 -> V_5 . V_10 ) ;
return V_8 ;
}
int F_127 ( struct V_1 * V_2 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_270 * V_271 = V_198 ;
struct V_103 * V_104 ;
int V_8 = 0 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_104 = F_128 ( V_2 , V_271 -> V_213 ) ;
if ( ! V_104 ) {
V_8 = - V_234 ;
goto V_52;
}
if ( V_104 -> V_17 )
V_271 -> V_211 = V_104 -> V_17 -> V_51 . V_40 ;
else
V_271 -> V_211 = 0 ;
V_271 -> V_106 = V_104 -> V_106 ;
V_271 -> V_213 = V_104 -> V_51 . V_40 ;
V_271 -> V_70 = V_104 -> V_70 ;
V_271 -> V_272 = V_104 -> V_272 ;
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_129 ( struct V_1 * V_2 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_273 * V_274 = V_198 ;
struct V_3 * V_4 ;
struct V_58 * V_59 ;
T_1 T_2 * V_275 ;
int V_209 = 0 , V_8 = 0 ;
unsigned V_276 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_4 = & V_2 -> V_5 ;
if ( V_200 -> V_277 )
V_276 = V_4 -> V_118 ;
else
V_276 = V_4 -> V_120 ;
if ( V_276 &&
( V_274 -> V_278 >= V_276 ) ) {
V_275 = ( T_1 T_2 * ) ( unsigned long ) V_274 -> V_279 ;
F_15 (plane, &config->plane_list, head) {
if ( V_59 -> type != V_119 &&
! V_200 -> V_277 )
continue;
if ( F_117 ( V_59 -> V_51 . V_40 , V_275 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
}
V_274 -> V_278 = V_276 ;
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_130 ( struct V_1 * V_2 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_280 * V_274 = V_198 ;
struct V_58 * V_59 ;
T_1 T_2 * V_281 ;
int V_8 = 0 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_59 = F_131 ( V_2 , V_274 -> V_282 ) ;
if ( ! V_59 ) {
V_8 = - V_234 ;
goto V_52;
}
if ( V_59 -> V_17 )
V_274 -> V_211 = V_59 -> V_17 -> V_51 . V_40 ;
else
V_274 -> V_211 = 0 ;
if ( V_59 -> V_45 )
V_274 -> V_210 = V_59 -> V_45 -> V_51 . V_40 ;
else
V_274 -> V_210 = 0 ;
V_274 -> V_282 = V_59 -> V_51 . V_40 ;
V_274 -> V_70 = V_59 -> V_70 ;
V_274 -> V_237 = 0 ;
if ( V_59 -> V_113 &&
( V_274 -> V_283 >= V_59 -> V_113 ) ) {
V_281 = ( T_1 T_2 * ) ( unsigned long ) V_274 -> V_284 ;
if ( F_126 ( V_281 ,
V_59 -> V_116 ,
sizeof( T_1 ) * V_59 -> V_113 ) ) {
V_8 = - V_218 ;
goto V_52;
}
}
V_274 -> V_283 = V_59 -> V_113 ;
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
static int F_132 ( struct V_58 * V_59 ,
struct V_16 * V_17 ,
struct V_44 * V_45 ,
T_4 V_285 , T_4 V_286 ,
T_1 V_287 , T_1 V_288 ,
T_1 V_289 , T_1 V_290 ,
T_1 V_291 , T_1 V_292 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_44 * V_124 = NULL ;
int V_8 = 0 ;
unsigned int V_293 , V_294 ;
int V_19 ;
if ( ! V_45 ) {
F_1 ( V_2 ) ;
V_124 = V_59 -> V_45 ;
V_8 = V_59 -> V_47 -> V_125 ( V_59 ) ;
if ( ! V_8 ) {
V_59 -> V_17 = NULL ;
V_59 -> V_45 = NULL ;
} else {
V_124 = NULL ;
}
F_10 ( V_2 ) ;
goto V_52;
}
if ( ! ( V_59 -> V_70 & F_133 ( V_17 ) ) ) {
F_92 ( L_38 ) ;
V_8 = - V_197 ;
goto V_52;
}
for ( V_19 = 0 ; V_19 < V_59 -> V_113 ; V_19 ++ )
if ( V_45 -> V_295 == V_59 -> V_116 [ V_19 ] )
break;
if ( V_19 == V_59 -> V_113 ) {
F_92 ( L_39 ,
F_26 ( V_45 -> V_295 ) ) ;
V_8 = - V_197 ;
goto V_52;
}
V_293 = V_45 -> V_296 << 16 ;
V_294 = V_45 -> V_297 << 16 ;
if ( V_291 > V_293 ||
V_289 > V_293 - V_291 ||
V_292 > V_294 ||
V_290 > V_294 - V_292 ) {
F_92 ( L_40
L_41 ,
V_291 >> 16 , ( ( V_291 & 0xffff ) * 15625 ) >> 10 ,
V_292 >> 16 , ( ( V_292 & 0xffff ) * 15625 ) >> 10 ,
V_289 >> 16 , ( ( V_289 & 0xffff ) * 15625 ) >> 10 ,
V_290 >> 16 , ( ( V_290 & 0xffff ) * 15625 ) >> 10 ) ;
V_8 = - V_298 ;
goto V_52;
}
F_1 ( V_2 ) ;
V_124 = V_59 -> V_45 ;
V_8 = V_59 -> V_47 -> V_299 ( V_59 , V_17 , V_45 ,
V_285 , V_286 , V_287 , V_288 ,
V_289 , V_290 , V_291 , V_292 ) ;
if ( ! V_8 ) {
V_59 -> V_17 = V_17 ;
V_59 -> V_45 = V_45 ;
V_45 = NULL ;
} else {
V_124 = NULL ;
}
F_10 ( V_2 ) ;
V_52:
if ( V_45 )
F_47 ( V_45 ) ;
if ( V_124 )
F_47 ( V_124 ) ;
return V_8 ;
}
int F_134 ( struct V_1 * V_2 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_300 * V_301 = V_198 ;
struct V_34 * V_35 ;
struct V_58 * V_59 ;
struct V_16 * V_17 = NULL ;
struct V_44 * V_45 = NULL ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
if ( V_301 -> V_287 > V_193 ||
V_301 -> V_285 > V_193 - ( T_4 ) V_301 -> V_287 ||
V_301 -> V_288 > V_193 ||
V_301 -> V_286 > V_193 - ( T_4 ) V_301 -> V_288 ) {
F_92 ( L_42 ,
V_301 -> V_287 , V_301 -> V_288 ,
V_301 -> V_285 , V_301 -> V_286 ) ;
return - V_194 ;
}
V_35 = F_36 ( V_2 , V_301 -> V_282 ,
V_115 ) ;
if ( ! V_35 ) {
F_92 ( L_43 ,
V_301 -> V_282 ) ;
return - V_234 ;
}
V_59 = F_135 ( V_35 ) ;
if ( V_301 -> V_210 ) {
V_45 = F_46 ( V_2 , V_301 -> V_210 ) ;
if ( ! V_45 ) {
F_92 ( L_44 ,
V_301 -> V_210 ) ;
return - V_234 ;
}
V_35 = F_36 ( V_2 , V_301 -> V_211 ,
V_66 ) ;
if ( ! V_35 ) {
F_92 ( L_45 ,
V_301 -> V_211 ) ;
return - V_234 ;
}
V_17 = F_136 ( V_35 ) ;
}
return F_132 ( V_59 , V_17 , V_45 ,
V_301 -> V_285 , V_301 -> V_286 ,
V_301 -> V_287 , V_301 -> V_288 ,
V_301 -> V_289 , V_301 -> V_290 ,
V_301 -> V_291 , V_301 -> V_292 ) ;
}
int F_61 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = V_61 -> V_17 ;
struct V_44 * V_45 ;
struct V_16 * V_73 ;
int V_8 ;
F_15 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_73 -> V_124 = V_73 -> V_62 -> V_45 ;
V_45 = V_61 -> V_45 ;
V_8 = V_17 -> V_47 -> V_302 ( V_61 ) ;
if ( V_8 == 0 ) {
V_17 -> V_62 -> V_17 = V_17 ;
V_17 -> V_62 -> V_45 = V_45 ;
}
F_15 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_73 -> V_62 -> V_45 )
F_40 ( V_73 -> V_62 -> V_45 ) ;
if ( V_73 -> V_124 )
F_47 ( V_73 -> V_124 ) ;
}
return V_8 ;
}
int F_137 ( const struct V_16 * V_17 ,
int V_235 , int V_236 ,
const struct V_76 * V_77 ,
const struct V_44 * V_45 )
{
int V_179 , V_185 ;
V_179 = V_77 -> V_179 ;
V_185 = V_77 -> V_185 ;
if ( F_122 ( V_77 ) ) {
struct V_76 V_303 = * V_77 ;
F_138 ( & V_303 , V_304 ) ;
V_179 = V_303 . V_305 ;
V_185 = V_303 . V_306 ;
}
if ( V_17 -> V_65 )
F_139 ( V_179 , V_185 ) ;
if ( V_179 > V_45 -> V_296 ||
V_185 > V_45 -> V_297 ||
V_235 > V_45 -> V_296 - V_179 ||
V_236 > V_45 -> V_297 - V_185 ) {
F_92 ( L_46 ,
V_45 -> V_296 , V_45 -> V_297 , V_179 , V_185 , V_235 , V_236 ,
V_17 -> V_65 ? L_47 : L_48 ) ;
return - V_298 ;
}
return 0 ;
}
int F_140 ( struct V_1 * V_2 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_232 * V_307 = V_198 ;
struct V_16 * V_17 ;
struct V_74 * * V_308 = NULL , * V_75 ;
struct V_44 * V_45 = NULL ;
struct V_76 * V_77 = NULL ;
struct V_60 V_61 ;
T_1 T_2 * V_309 ;
int V_8 ;
int V_19 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
if ( V_307 -> V_235 > V_193 || V_307 -> V_236 > V_193 )
return - V_194 ;
F_1 ( V_2 ) ;
V_17 = F_120 ( V_2 , V_307 -> V_211 ) ;
if ( ! V_17 ) {
F_92 ( L_49 , V_307 -> V_211 ) ;
V_8 = - V_234 ;
goto V_52;
}
F_92 ( L_33 , V_17 -> V_51 . V_40 ) ;
if ( V_307 -> V_239 ) {
if ( V_307 -> V_210 == - 1 ) {
if ( ! V_17 -> V_62 -> V_45 ) {
F_92 ( L_50 ) ;
V_8 = - V_197 ;
goto V_52;
}
V_45 = V_17 -> V_62 -> V_45 ;
F_40 ( V_45 ) ;
} else {
V_45 = F_46 ( V_2 , V_307 -> V_210 ) ;
if ( ! V_45 ) {
F_92 ( L_51 ,
V_307 -> V_210 ) ;
V_8 = - V_234 ;
goto V_52;
}
}
V_77 = F_141 ( V_2 ) ;
if ( ! V_77 ) {
V_8 = - V_85 ;
goto V_52;
}
V_8 = F_113 ( V_77 , & V_307 -> V_77 ) ;
if ( V_8 ) {
F_92 ( L_52 ) ;
goto V_52;
}
F_138 ( V_77 , V_310 ) ;
V_8 = F_137 ( V_17 , V_307 -> V_235 , V_307 -> V_236 ,
V_77 , V_45 ) ;
if ( V_8 )
goto V_52;
}
if ( V_307 -> V_229 == 0 && V_77 ) {
F_92 ( L_53 ) ;
V_8 = - V_197 ;
goto V_52;
}
if ( V_307 -> V_229 > 0 && ( ! V_77 || ! V_45 ) ) {
F_92 ( L_54 ,
V_307 -> V_229 ) ;
V_8 = - V_197 ;
goto V_52;
}
if ( V_307 -> V_229 > 0 ) {
T_5 V_311 ;
if ( V_307 -> V_229 > V_4 -> V_91 ) {
V_8 = - V_197 ;
goto V_52;
}
V_308 = F_91 ( V_307 -> V_229 *
sizeof( struct V_74 * ) ,
V_9 ) ;
if ( ! V_308 ) {
V_8 = - V_85 ;
goto V_52;
}
for ( V_19 = 0 ; V_19 < V_307 -> V_229 ; V_19 ++ ) {
V_309 = ( T_1 T_2 * ) ( unsigned long ) V_307 -> V_309 ;
if ( F_142 ( V_311 , & V_309 [ V_19 ] ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_75 = F_124 ( V_2 , V_311 ) ;
if ( ! V_75 ) {
F_92 ( L_55 ,
V_311 ) ;
V_8 = - V_234 ;
goto V_52;
}
F_92 ( L_35 ,
V_75 -> V_51 . V_40 ,
V_75 -> V_29 ) ;
V_308 [ V_19 ] = V_75 ;
}
}
V_61 . V_17 = V_17 ;
V_61 . V_235 = V_307 -> V_235 ;
V_61 . V_236 = V_307 -> V_236 ;
V_61 . V_77 = V_77 ;
V_61 . V_312 = V_308 ;
V_61 . V_173 = V_307 -> V_229 ;
V_61 . V_45 = V_45 ;
V_8 = F_61 ( & V_61 ) ;
V_52:
if ( V_45 )
F_47 ( V_45 ) ;
F_13 ( V_308 ) ;
F_71 ( V_2 , V_77 ) ;
F_10 ( V_2 ) ;
return V_8 ;
}
static int F_143 ( struct V_16 * V_17 ,
struct V_313 * V_314 ,
struct V_199 * V_200 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_44 * V_45 = NULL ;
struct V_315 V_316 = {
. V_296 = V_314 -> V_296 ,
. V_297 = V_314 -> V_297 ,
. V_295 = V_317 ,
. V_318 = { V_314 -> V_296 * 4 } ,
. V_319 = { V_314 -> V_320 } ,
} ;
T_4 V_285 , V_286 ;
T_1 V_287 = 0 , V_288 = 0 ;
T_1 V_291 = 0 , V_292 = 0 ;
int V_8 = 0 ;
F_95 ( ! V_17 -> V_63 ) ;
if ( V_314 -> V_191 & V_321 ) {
if ( V_314 -> V_320 ) {
V_45 = F_144 ( V_2 , & V_316 , V_200 ) ;
if ( F_145 ( V_45 ) ) {
F_92 ( L_56 ) ;
return F_146 ( V_45 ) ;
}
F_40 ( V_45 ) ;
} else {
V_45 = NULL ;
}
} else {
F_4 ( & V_2 -> V_5 . V_10 ) ;
V_45 = V_17 -> V_63 -> V_45 ;
if ( V_45 )
F_40 ( V_45 ) ;
F_14 ( & V_2 -> V_5 . V_10 ) ;
}
if ( V_314 -> V_191 & V_322 ) {
V_285 = V_314 -> V_235 ;
V_286 = V_314 -> V_236 ;
} else {
V_285 = V_17 -> V_323 ;
V_286 = V_17 -> V_324 ;
}
if ( V_45 ) {
V_287 = V_45 -> V_296 ;
V_288 = V_45 -> V_297 ;
V_291 = V_45 -> V_296 << 16 ;
V_292 = V_45 -> V_297 << 16 ;
}
V_8 = F_132 ( V_17 -> V_63 , V_17 , V_45 ,
V_285 , V_286 , V_287 , V_288 ,
0 , 0 , V_291 , V_292 ) ;
if ( V_8 == 0 && V_314 -> V_191 & V_322 ) {
V_17 -> V_323 = V_314 -> V_235 ;
V_17 -> V_324 = V_314 -> V_236 ;
}
return V_8 ;
}
static int F_147 ( struct V_1 * V_2 ,
struct V_313 * V_314 ,
struct V_199 * V_200 )
{
struct V_16 * V_17 ;
int V_8 = 0 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
if ( ! V_314 -> V_191 || ( ~ V_325 & V_314 -> V_191 ) )
return - V_197 ;
V_17 = F_120 ( V_2 , V_314 -> V_211 ) ;
if ( ! V_17 ) {
F_92 ( L_49 , V_314 -> V_211 ) ;
return - V_234 ;
}
if ( V_17 -> V_63 )
return F_143 ( V_17 , V_314 , V_200 ) ;
F_6 ( & V_17 -> V_10 , NULL ) ;
if ( V_314 -> V_191 & V_321 ) {
if ( ! V_17 -> V_47 -> V_326 && ! V_17 -> V_47 -> V_327 ) {
V_8 = - V_328 ;
goto V_52;
}
if ( V_17 -> V_47 -> V_327 )
V_8 = V_17 -> V_47 -> V_327 ( V_17 , V_200 , V_314 -> V_320 ,
V_314 -> V_296 , V_314 -> V_297 , V_314 -> V_329 , V_314 -> V_330 ) ;
else
V_8 = V_17 -> V_47 -> V_326 ( V_17 , V_200 , V_314 -> V_320 ,
V_314 -> V_296 , V_314 -> V_297 ) ;
}
if ( V_314 -> V_191 & V_322 ) {
if ( V_17 -> V_47 -> V_331 ) {
V_8 = V_17 -> V_47 -> V_331 ( V_17 , V_314 -> V_235 , V_314 -> V_236 ) ;
} else {
V_8 = - V_218 ;
goto V_52;
}
}
V_52:
F_125 ( & V_17 -> V_10 ) ;
return V_8 ;
}
int F_148 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_332 * V_314 = V_198 ;
struct V_313 V_333 ;
memcpy ( & V_333 , V_314 , sizeof( struct V_332 ) ) ;
V_333 . V_329 = V_333 . V_330 = 0 ;
return F_147 ( V_2 , & V_333 , V_200 ) ;
}
int F_149 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_313 * V_314 = V_198 ;
return F_147 ( V_2 , V_314 , V_200 ) ;
}
T_1 F_150 ( T_1 V_334 , T_1 V_335 )
{
T_1 V_336 ;
switch ( V_334 ) {
case 8 :
V_336 = V_337 ;
break;
case 16 :
if ( V_335 == 15 )
V_336 = V_338 ;
else
V_336 = V_339 ;
break;
case 24 :
V_336 = V_340 ;
break;
case 32 :
if ( V_335 == 24 )
V_336 = V_341 ;
else if ( V_335 == 30 )
V_336 = V_342 ;
else
V_336 = V_317 ;
break;
default:
F_62 ( L_57 ) ;
V_336 = V_341 ;
break;
}
return V_336 ;
}
int F_151 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_343 * V_344 = V_198 ;
struct V_315 V_345 = {} ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_44 * V_45 ;
int V_8 = 0 ;
V_345 . V_210 = V_344 -> V_210 ;
V_345 . V_296 = V_344 -> V_296 ;
V_345 . V_297 = V_344 -> V_297 ;
V_345 . V_318 [ 0 ] = V_344 -> V_346 ;
V_345 . V_295 = F_150 ( V_344 -> V_334 , V_344 -> V_335 ) ;
V_345 . V_319 [ 0 ] = V_344 -> V_320 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
if ( ( V_4 -> V_224 > V_345 . V_296 ) || ( V_345 . V_296 > V_4 -> V_223 ) )
return - V_197 ;
if ( ( V_4 -> V_222 > V_345 . V_297 ) || ( V_345 . V_297 > V_4 -> V_221 ) )
return - V_197 ;
V_45 = V_2 -> V_5 . V_47 -> V_347 ( V_2 , V_200 , & V_345 ) ;
if ( F_145 ( V_45 ) ) {
F_92 ( L_58 ) ;
return F_146 ( V_45 ) ;
}
F_4 ( & V_200 -> V_215 ) ;
V_344 -> V_210 = V_45 -> V_51 . V_40 ;
F_41 ( & V_45 -> V_50 , & V_200 -> V_348 ) ;
F_92 ( L_59 , V_45 -> V_51 . V_40 ) ;
F_14 ( & V_200 -> V_215 ) ;
return V_8 ;
}
static int F_152 ( const struct V_315 * V_345 )
{
T_1 V_31 = V_345 -> V_295 & ~ V_33 ;
switch ( V_31 ) {
case V_337 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_338 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_339 :
case V_366 :
case V_340 :
case V_367 :
case V_341 :
case V_368 :
case V_369 :
case V_370 :
case V_317 :
case V_371 :
case V_372 :
case V_373 :
case V_342 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
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
return 0 ;
default:
F_92 ( L_60 ,
F_26 ( V_345 -> V_295 ) ) ;
return - V_197 ;
}
}
static int F_153 ( const struct V_315 * V_345 )
{
int V_8 , V_402 , V_403 , V_276 , V_19 ;
V_8 = F_152 ( V_345 ) ;
if ( V_8 ) {
F_92 ( L_61 ,
F_26 ( V_345 -> V_295 ) ) ;
return V_8 ;
}
V_402 = F_154 ( V_345 -> V_295 ) ;
V_403 = F_155 ( V_345 -> V_295 ) ;
V_276 = F_156 ( V_345 -> V_295 ) ;
if ( V_345 -> V_296 == 0 || V_345 -> V_296 % V_402 ) {
F_92 ( L_62 , V_345 -> V_297 ) ;
return - V_197 ;
}
if ( V_345 -> V_297 == 0 || V_345 -> V_297 % V_403 ) {
F_92 ( L_63 , V_345 -> V_297 ) ;
return - V_197 ;
}
for ( V_19 = 0 ; V_19 < V_276 ; V_19 ++ ) {
unsigned int V_296 = V_345 -> V_296 / ( V_19 != 0 ? V_402 : 1 ) ;
unsigned int V_297 = V_345 -> V_297 / ( V_19 != 0 ? V_403 : 1 ) ;
unsigned int V_404 = F_157 ( V_345 -> V_295 , V_19 ) ;
if ( ! V_345 -> V_319 [ V_19 ] ) {
F_92 ( L_64 , V_19 ) ;
return - V_197 ;
}
if ( ( T_3 ) V_296 * V_404 > V_405 )
return - V_194 ;
if ( ( T_3 ) V_297 * V_345 -> V_318 [ V_19 ] + V_345 -> V_406 [ V_19 ] > V_405 )
return - V_194 ;
if ( V_345 -> V_318 [ V_19 ] < V_296 * V_404 ) {
F_92 ( L_65 , V_345 -> V_318 [ V_19 ] , V_19 ) ;
return - V_197 ;
}
}
return 0 ;
}
static struct V_44 * F_144 ( struct V_1 * V_2 ,
struct V_315 * V_345 ,
struct V_199 * V_200 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_44 * V_45 ;
int V_8 ;
if ( V_345 -> V_191 & ~ V_407 ) {
F_92 ( L_66 , V_345 -> V_191 ) ;
return F_158 ( - V_197 ) ;
}
if ( ( V_4 -> V_224 > V_345 -> V_296 ) || ( V_345 -> V_296 > V_4 -> V_223 ) ) {
F_92 ( L_67 ,
V_345 -> V_296 , V_4 -> V_224 , V_4 -> V_223 ) ;
return F_158 ( - V_197 ) ;
}
if ( ( V_4 -> V_222 > V_345 -> V_297 ) || ( V_345 -> V_297 > V_4 -> V_221 ) ) {
F_92 ( L_68 ,
V_345 -> V_297 , V_4 -> V_222 , V_4 -> V_221 ) ;
return F_158 ( - V_197 ) ;
}
V_8 = F_153 ( V_345 ) ;
if ( V_8 )
return F_158 ( V_8 ) ;
V_45 = V_2 -> V_5 . V_47 -> V_347 ( V_2 , V_200 , V_345 ) ;
if ( F_145 ( V_45 ) ) {
F_92 ( L_58 ) ;
return V_45 ;
}
F_4 ( & V_200 -> V_215 ) ;
V_345 -> V_210 = V_45 -> V_51 . V_40 ;
F_41 ( & V_45 -> V_50 , & V_200 -> V_348 ) ;
F_92 ( L_59 , V_45 -> V_51 . V_40 ) ;
F_14 ( & V_200 -> V_215 ) ;
return V_45 ;
}
int F_159 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_44 * V_45 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
V_45 = F_144 ( V_2 , V_198 , V_200 ) ;
if ( F_145 ( V_45 ) )
return F_146 ( V_45 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_44 * V_45 = NULL ;
struct V_44 * V_408 = NULL ;
T_1 * V_40 = V_198 ;
int V_409 = 0 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_4 ( & V_200 -> V_215 ) ;
F_4 ( & V_2 -> V_5 . V_48 ) ;
V_45 = F_44 ( V_2 , * V_40 ) ;
if ( ! V_45 )
goto V_410;
F_15 (fbl, &file_priv->fbs, filp_head)
if ( V_45 == V_408 )
V_409 = 1 ;
if ( ! V_409 )
goto V_410;
F_55 ( V_2 , V_45 ) ;
F_161 ( & V_45 -> V_50 ) ;
F_14 ( & V_2 -> V_5 . V_48 ) ;
F_14 ( & V_200 -> V_215 ) ;
F_59 ( V_45 ) ;
return 0 ;
V_410:
F_14 ( & V_2 -> V_5 . V_48 ) ;
F_14 ( & V_200 -> V_215 ) ;
return - V_234 ;
}
int F_162 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_343 * V_345 = V_198 ;
struct V_44 * V_45 ;
int V_8 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
V_45 = F_46 ( V_2 , V_345 -> V_210 ) ;
if ( ! V_45 )
return - V_234 ;
V_345 -> V_297 = V_45 -> V_297 ;
V_345 -> V_296 = V_45 -> V_296 ;
V_345 -> V_335 = V_45 -> V_335 ;
V_345 -> V_334 = V_45 -> V_411 ;
V_345 -> V_346 = V_45 -> V_318 [ 0 ] ;
if ( V_45 -> V_47 -> V_412 ) {
if ( V_200 -> V_413 || F_163 ( V_414 ) ||
F_164 ( V_200 ) ) {
V_8 = V_45 -> V_47 -> V_412 ( V_45 , V_200 ,
& V_345 -> V_320 ) ;
} else {
V_345 -> V_320 = 0 ;
V_8 = 0 ;
}
} else {
V_8 = - V_415 ;
}
F_47 ( V_45 ) ;
return V_8 ;
}
int F_165 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_416 T_2 * V_417 ;
struct V_416 * V_418 = NULL ;
struct V_419 * V_345 = V_198 ;
struct V_44 * V_45 ;
unsigned V_191 ;
int V_420 ;
int V_8 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
V_45 = F_46 ( V_2 , V_345 -> V_210 ) ;
if ( ! V_45 )
return - V_234 ;
V_420 = V_345 -> V_420 ;
V_417 = (struct V_416 T_2 * ) ( unsigned long ) V_345 -> V_417 ;
if ( ! V_420 != ! V_417 ) {
V_8 = - V_197 ;
goto V_421;
}
V_191 = V_422 & V_345 -> V_191 ;
if ( V_191 & V_423 && ( V_420 % 2 ) ) {
V_8 = - V_197 ;
goto V_421;
}
if ( V_420 && V_417 ) {
if ( V_420 < 0 || V_420 > V_424 ) {
V_8 = - V_197 ;
goto V_421;
}
V_418 = F_2 ( V_420 * sizeof( * V_418 ) , V_9 ) ;
if ( ! V_418 ) {
V_8 = - V_85 ;
goto V_421;
}
V_8 = F_166 ( V_418 , V_417 ,
V_420 * sizeof( * V_418 ) ) ;
if ( V_8 ) {
V_8 = - V_218 ;
goto V_425;
}
}
if ( V_45 -> V_47 -> V_426 ) {
V_8 = V_45 -> V_47 -> V_426 ( V_45 , V_200 , V_191 , V_345 -> V_427 ,
V_418 , V_420 ) ;
} else {
V_8 = - V_428 ;
}
V_425:
F_13 ( V_418 ) ;
V_421:
F_47 ( V_45 ) ;
return V_8 ;
}
void F_167 ( struct V_199 * V_429 )
{
struct V_1 * V_2 = V_429 -> V_220 -> V_2 ;
struct V_44 * V_45 , * V_430 ;
F_4 ( & V_429 -> V_215 ) ;
F_77 (fb, tfb, &priv->fbs, filp_head) {
F_4 ( & V_2 -> V_5 . V_48 ) ;
F_55 ( V_2 , V_45 ) ;
F_14 ( & V_2 -> V_5 . V_48 ) ;
F_161 ( & V_45 -> V_50 ) ;
F_59 ( V_45 ) ;
}
F_14 ( & V_429 -> V_215 ) ;
}
struct V_126 * F_97 ( struct V_1 * V_2 , int V_191 ,
const char * V_29 , int V_431 )
{
struct V_126 * V_432 = NULL ;
int V_8 ;
V_432 = F_2 ( sizeof( struct V_126 ) , V_9 ) ;
if ( ! V_432 )
return NULL ;
V_432 -> V_2 = V_2 ;
if ( V_431 ) {
V_432 -> V_268 = F_2 ( sizeof( T_3 ) * V_431 , V_9 ) ;
if ( ! V_432 -> V_268 )
goto V_13;
}
V_8 = F_29 ( V_2 , & V_432 -> V_51 , V_433 ) ;
if ( V_8 )
goto V_13;
V_432 -> V_191 = V_191 ;
V_432 -> V_431 = V_431 ;
F_39 ( & V_432 -> V_434 ) ;
if ( V_29 ) {
strncpy ( V_432 -> V_29 , V_29 , V_435 ) ;
V_432 -> V_29 [ V_435 - 1 ] = '\0' ;
}
F_66 ( & V_432 -> V_54 , & V_2 -> V_5 . V_436 ) ;
F_3 ( ! F_168 ( V_432 ) ) ;
return V_432 ;
V_13:
F_13 ( V_432 -> V_268 ) ;
F_13 ( V_432 ) ;
return NULL ;
}
struct V_126 * F_98 ( struct V_1 * V_2 , int V_191 ,
const char * V_29 ,
const struct V_437 * V_438 ,
int V_431 )
{
struct V_126 * V_432 ;
int V_19 , V_8 ;
V_191 |= V_153 ;
V_432 = F_97 ( V_2 , V_191 , V_29 , V_431 ) ;
if ( ! V_432 )
return NULL ;
for ( V_19 = 0 ; V_19 < V_431 ; V_19 ++ ) {
V_8 = F_103 ( V_432 , V_19 ,
V_438 [ V_19 ] . type ,
V_438 [ V_19 ] . V_29 ) ;
if ( V_8 ) {
F_169 ( V_2 , V_432 ) ;
return NULL ;
}
}
return V_432 ;
}
struct V_126 * F_170 ( struct V_1 * V_2 ,
int V_191 , const char * V_29 ,
const struct V_437 * V_438 ,
int V_439 ,
T_3 V_440 )
{
struct V_126 * V_432 ;
int V_19 , V_8 , V_72 = 0 ;
int V_431 = F_171 ( V_440 ) ;
V_191 |= V_441 ;
V_432 = F_97 ( V_2 , V_191 , V_29 , V_431 ) ;
if ( ! V_432 )
return NULL ;
for ( V_19 = 0 ; V_19 < V_439 ; V_19 ++ ) {
if ( ! ( V_440 & ( 1ULL << V_438 [ V_19 ] . type ) ) )
continue;
if ( F_3 ( V_72 >= V_431 ) ) {
F_169 ( V_2 , V_432 ) ;
return NULL ;
}
V_8 = F_103 ( V_432 , V_72 ++ ,
V_438 [ V_19 ] . type ,
V_438 [ V_19 ] . V_29 ) ;
if ( V_8 ) {
F_169 ( V_2 , V_432 ) ;
return NULL ;
}
}
return V_432 ;
}
static struct V_126 * F_172 ( struct V_1 * V_2 ,
int V_191 , const char * V_29 ,
T_3 V_442 , T_3 V_443 )
{
struct V_126 * V_432 ;
V_432 = F_97 ( V_2 , V_191 , V_29 , 2 ) ;
if ( ! V_432 )
return NULL ;
V_432 -> V_268 [ 0 ] = V_442 ;
V_432 -> V_268 [ 1 ] = V_443 ;
return V_432 ;
}
struct V_126 * F_102 ( struct V_1 * V_2 , int V_191 ,
const char * V_29 ,
T_3 V_442 , T_3 V_443 )
{
return F_172 ( V_2 , V_444 | V_191 ,
V_29 , V_442 , V_443 ) ;
}
struct V_126 * F_173 ( struct V_1 * V_2 ,
int V_191 , const char * V_29 ,
T_6 V_442 , T_6 V_443 )
{
return F_172 ( V_2 , V_445 | V_191 ,
V_29 , F_174 ( V_442 ) , F_174 ( V_443 ) ) ;
}
struct V_126 * F_175 ( struct V_1 * V_2 ,
int V_191 , const char * V_29 , T_1 type )
{
struct V_126 * V_432 ;
V_191 |= V_446 ;
V_432 = F_97 ( V_2 , V_191 , V_29 , 1 ) ;
if ( ! V_432 )
return NULL ;
V_432 -> V_268 [ 0 ] = type ;
return V_432 ;
}
int F_103 ( struct V_126 * V_432 , int V_72 ,
T_3 V_447 , const char * V_29 )
{
struct V_448 * V_449 ;
if ( ! ( F_176 ( V_432 , V_153 ) ||
F_176 ( V_432 , V_441 ) ) )
return - V_197 ;
if ( F_176 ( V_432 , V_441 ) &&
( V_447 > 63 ) )
return - V_197 ;
if ( ! F_60 ( & V_432 -> V_434 ) ) {
F_15 (prop_enum, &property->enum_blob_list, head) {
if ( V_449 -> V_447 == V_447 ) {
strncpy ( V_449 -> V_29 , V_29 , V_435 ) ;
V_449 -> V_29 [ V_435 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_449 = F_2 ( sizeof( struct V_448 ) , V_9 ) ;
if ( ! V_449 )
return - V_85 ;
strncpy ( V_449 -> V_29 , V_29 , V_435 ) ;
V_449 -> V_29 [ V_435 - 1 ] = '\0' ;
V_449 -> V_447 = V_447 ;
V_432 -> V_268 [ V_72 ] = V_447 ;
F_66 ( & V_449 -> V_54 , & V_432 -> V_434 ) ;
return 0 ;
}
void F_169 ( struct V_1 * V_2 , struct V_126 * V_432 )
{
struct V_448 * V_449 , * V_450 ;
F_77 (prop_enum, pt, &property->enum_blob_list, head) {
F_58 ( & V_449 -> V_54 ) ;
F_13 ( V_449 ) ;
}
if ( V_432 -> V_431 )
F_13 ( V_432 -> V_268 ) ;
F_32 ( V_2 , & V_432 -> V_51 ) ;
F_58 ( & V_432 -> V_54 ) ;
F_13 ( V_432 ) ;
}
void F_75 ( struct V_34 * V_35 ,
struct V_126 * V_432 ,
T_3 V_451 )
{
int V_251 = V_35 -> V_67 -> V_251 ;
if ( V_251 == V_452 ) {
F_112 ( 1 , L_69
L_70
L_71 ,
V_35 -> type ) ;
return;
}
V_35 -> V_67 -> V_267 [ V_251 ] = V_432 -> V_51 . V_40 ;
V_35 -> V_67 -> V_268 [ V_251 ] = V_451 ;
V_35 -> V_67 -> V_251 ++ ;
}
int F_177 ( struct V_34 * V_35 ,
struct V_126 * V_432 , T_3 V_453 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_35 -> V_67 -> V_251 ; V_19 ++ ) {
if ( V_35 -> V_67 -> V_267 [ V_19 ] == V_432 -> V_51 . V_40 ) {
V_35 -> V_67 -> V_268 [ V_19 ] = V_453 ;
return 0 ;
}
}
return - V_197 ;
}
int F_178 ( struct V_34 * V_35 ,
struct V_126 * V_432 , T_3 * V_453 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_35 -> V_67 -> V_251 ; V_19 ++ ) {
if ( V_35 -> V_67 -> V_267 [ V_19 ] == V_432 -> V_51 . V_40 ) {
* V_453 = V_35 -> V_67 -> V_268 [ V_19 ] ;
return 0 ;
}
}
return - V_197 ;
}
int F_179 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_454 * V_242 = V_198 ;
struct V_126 * V_432 ;
int V_455 = 0 ;
int V_456 = 0 ;
int V_457 = 0 ;
int V_8 = 0 , V_19 ;
int V_209 ;
struct V_448 * V_449 ;
struct V_458 T_2 * V_459 ;
struct V_460 * V_461 ;
T_1 T_2 * V_462 ;
T_3 T_2 * V_463 ;
T_1 T_2 * V_464 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_432 = F_180 ( V_2 , V_242 -> V_465 ) ;
if ( ! V_432 ) {
V_8 = - V_234 ;
goto V_466;
}
if ( F_176 ( V_432 , V_153 ) ||
F_176 ( V_432 , V_441 ) ) {
F_15 (prop_enum, &property->enum_blob_list, head)
V_455 ++ ;
} else if ( F_176 ( V_432 , V_130 ) ) {
F_15 (prop_blob, &property->enum_blob_list, head)
V_456 ++ ;
}
V_457 = V_432 -> V_431 ;
strncpy ( V_242 -> V_29 , V_432 -> V_29 , V_435 ) ;
V_242 -> V_29 [ V_435 - 1 ] = 0 ;
V_242 -> V_191 = V_432 -> V_191 ;
if ( ( V_242 -> V_467 >= V_457 ) && V_457 ) {
V_463 = ( T_3 T_2 * ) ( unsigned long ) V_242 -> V_463 ;
for ( V_19 = 0 ; V_19 < V_457 ; V_19 ++ ) {
if ( F_126 ( V_463 + V_19 , & V_432 -> V_268 [ V_19 ] , sizeof( T_3 ) ) ) {
V_8 = - V_218 ;
goto V_466;
}
}
}
V_242 -> V_467 = V_457 ;
if ( F_176 ( V_432 , V_153 ) ||
F_176 ( V_432 , V_441 ) ) {
if ( ( V_242 -> V_468 >= V_455 ) && V_455 ) {
V_209 = 0 ;
V_459 = (struct V_458 T_2 * ) ( unsigned long ) V_242 -> V_469 ;
F_15 (prop_enum, &property->enum_blob_list, head) {
if ( F_126 ( & V_459 [ V_209 ] . V_447 , & V_449 -> V_447 , sizeof( T_3 ) ) ) {
V_8 = - V_218 ;
goto V_466;
}
if ( F_126 ( & V_459 [ V_209 ] . V_29 ,
& V_449 -> V_29 , V_435 ) ) {
V_8 = - V_218 ;
goto V_466;
}
V_209 ++ ;
}
}
V_242 -> V_468 = V_455 ;
}
if ( F_176 ( V_432 , V_130 ) ) {
if ( ( V_242 -> V_468 >= V_456 ) && V_456 ) {
V_209 = 0 ;
V_462 = ( T_1 T_2 * ) ( unsigned long ) V_242 -> V_469 ;
V_464 = ( T_1 T_2 * ) ( unsigned long ) V_242 -> V_463 ;
F_15 (prop_blob, &property->enum_blob_list, head) {
if ( F_117 ( V_461 -> V_51 . V_40 , V_462 + V_209 ) ) {
V_8 = - V_218 ;
goto V_466;
}
if ( F_117 ( V_461 -> V_470 , V_464 + V_209 ) ) {
V_8 = - V_218 ;
goto V_466;
}
V_209 ++ ;
}
}
V_242 -> V_468 = V_456 ;
}
V_466:
F_10 ( V_2 ) ;
return V_8 ;
}
static struct V_460 * F_181 ( struct V_1 * V_2 , int V_470 ,
void * V_198 )
{
struct V_460 * V_471 ;
int V_8 ;
if ( ! V_470 || ! V_198 )
return NULL ;
V_471 = F_2 ( sizeof( struct V_460 ) + V_470 , V_9 ) ;
if ( ! V_471 )
return NULL ;
V_8 = F_29 ( V_2 , & V_471 -> V_51 , V_472 ) ;
if ( V_8 ) {
F_13 ( V_471 ) ;
return NULL ;
}
V_471 -> V_470 = V_470 ;
memcpy ( V_471 -> V_198 , V_198 , V_470 ) ;
F_66 ( & V_471 -> V_54 , & V_2 -> V_5 . V_473 ) ;
return V_471 ;
}
static void F_182 ( struct V_1 * V_2 ,
struct V_460 * V_471 )
{
F_32 ( V_2 , & V_471 -> V_51 ) ;
F_58 ( & V_471 -> V_54 ) ;
F_13 ( V_471 ) ;
}
int F_183 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_474 * V_242 = V_198 ;
struct V_460 * V_471 ;
int V_8 = 0 ;
void T_2 * V_475 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_471 = F_184 ( V_2 , V_242 -> V_476 ) ;
if ( ! V_471 ) {
V_8 = - V_234 ;
goto V_466;
}
if ( V_242 -> V_470 == V_471 -> V_470 ) {
V_475 = ( void T_2 * ) ( unsigned long ) V_242 -> V_198 ;
if ( F_126 ( V_475 , V_471 -> V_198 , V_471 -> V_470 ) ) {
V_8 = - V_218 ;
goto V_466;
}
}
V_242 -> V_470 = V_471 -> V_470 ;
V_466:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_185 ( struct V_74 * V_75 ,
char * V_477 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
int V_8 , V_478 ;
V_478 = strlen ( V_477 ) + 1 ;
V_75 -> V_479 = F_181 ( V_75 -> V_2 ,
V_478 , V_477 ) ;
if ( ! V_75 -> V_479 )
return - V_197 ;
V_8 = F_177 ( & V_75 -> V_51 ,
V_2 -> V_5 . V_133 ,
V_75 -> V_479 -> V_51 . V_40 ) ;
return V_8 ;
}
int F_186 ( struct V_74 * V_75 ,
struct V_127 * V_127 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
int V_8 , V_478 ;
if ( V_75 -> V_480 )
return 0 ;
if ( V_75 -> V_88 )
F_182 ( V_2 , V_75 -> V_88 ) ;
if ( ! V_127 ) {
V_75 -> V_88 = NULL ;
V_8 = F_177 ( & V_75 -> V_51 , V_2 -> V_5 . V_93 , 0 ) ;
return V_8 ;
}
V_478 = V_481 * ( 1 + V_127 -> V_482 ) ;
V_75 -> V_88 = F_181 ( V_75 -> V_2 ,
V_478 , V_127 ) ;
if ( ! V_75 -> V_88 )
return - V_197 ;
V_8 = F_177 ( & V_75 -> V_51 ,
V_2 -> V_5 . V_93 ,
V_75 -> V_88 -> V_51 . V_40 ) ;
return V_8 ;
}
static bool F_187 ( struct V_126 * V_432 ,
T_3 V_447 )
{
if ( V_432 -> V_191 & V_131 )
return false ;
if ( F_176 ( V_432 , V_444 ) ) {
if ( V_447 < V_432 -> V_268 [ 0 ] || V_447 > V_432 -> V_268 [ 1 ] )
return false ;
return true ;
} else if ( F_176 ( V_432 , V_445 ) ) {
T_6 V_483 = F_188 ( V_447 ) ;
if ( V_483 < F_188 ( V_432 -> V_268 [ 0 ] ) ||
V_483 > F_188 ( V_432 -> V_268 [ 1 ] ) )
return false ;
return true ;
} else if ( F_176 ( V_432 , V_441 ) ) {
int V_19 ;
T_3 V_484 = 0 ;
for ( V_19 = 0 ; V_19 < V_432 -> V_431 ; V_19 ++ )
V_484 |= ( 1ULL << V_432 -> V_268 [ V_19 ] ) ;
return ! ( V_447 & ~ V_484 ) ;
} else if ( F_176 ( V_432 , V_130 ) ) {
return true ;
} else if ( F_176 ( V_432 , V_446 ) ) {
struct V_34 * V_35 ;
if ( V_447 == 0 )
return true ;
V_35 = F_34 ( V_432 -> V_2 , V_447 , V_432 -> V_268 [ 0 ] ) ;
return V_35 != NULL ;
} else {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_432 -> V_431 ; V_19 ++ )
if ( V_432 -> V_268 [ V_19 ] == V_447 )
return true ;
return false ;
}
}
int F_189 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_485 * V_486 = V_198 ;
struct V_487 V_488 = {
. V_447 = V_486 -> V_447 ,
. V_465 = V_486 -> V_465 ,
. V_489 = V_486 -> V_212 ,
. V_36 = V_81
} ;
return F_190 ( V_2 , & V_488 , V_200 ) ;
}
static int F_191 ( struct V_34 * V_35 ,
struct V_126 * V_432 ,
T_3 V_447 )
{
int V_8 = - V_197 ;
struct V_74 * V_75 = F_192 ( V_35 ) ;
if ( V_432 == V_75 -> V_2 -> V_5 . V_94 ) {
if ( V_75 -> V_47 -> V_128 )
(* V_75 -> V_47 -> V_128 )( V_75 , ( int ) V_447 ) ;
V_8 = 0 ;
} else if ( V_75 -> V_47 -> V_490 )
V_8 = V_75 -> V_47 -> V_490 ( V_75 , V_432 , V_447 ) ;
if ( ! V_8 )
F_177 ( & V_75 -> V_51 , V_432 , V_447 ) ;
return V_8 ;
}
static int F_193 ( struct V_34 * V_35 ,
struct V_126 * V_432 ,
T_3 V_447 )
{
int V_8 = - V_197 ;
struct V_16 * V_17 = F_136 ( V_35 ) ;
if ( V_17 -> V_47 -> V_490 )
V_8 = V_17 -> V_47 -> V_490 ( V_17 , V_432 , V_447 ) ;
if ( ! V_8 )
F_177 ( V_35 , V_432 , V_447 ) ;
return V_8 ;
}
static int F_194 ( struct V_34 * V_35 ,
struct V_126 * V_432 ,
T_3 V_447 )
{
int V_8 = - V_197 ;
struct V_58 * V_59 = F_135 ( V_35 ) ;
if ( V_59 -> V_47 -> V_490 )
V_8 = V_59 -> V_47 -> V_490 ( V_59 , V_432 , V_447 ) ;
if ( ! V_8 )
F_177 ( V_35 , V_432 , V_447 ) ;
return V_8 ;
}
int F_195 ( struct V_1 * V_2 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_491 * V_492 = V_198 ;
struct V_34 * V_35 ;
int V_8 = 0 ;
int V_19 ;
int V_209 = 0 ;
int V_244 = 0 ;
T_1 T_2 * V_265 ;
T_3 T_2 * V_266 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_35 = F_36 ( V_2 , V_492 -> V_489 , V_492 -> V_36 ) ;
if ( ! V_35 ) {
V_8 = - V_234 ;
goto V_52;
}
if ( ! V_35 -> V_67 ) {
V_8 = - V_197 ;
goto V_52;
}
V_244 = V_35 -> V_67 -> V_251 ;
if ( ( V_492 -> V_264 >= V_244 ) && V_244 ) {
V_209 = 0 ;
V_265 = ( T_1 T_2 * ) ( unsigned long ) ( V_492 -> V_265 ) ;
V_266 = ( T_3 T_2 * ) ( unsigned long )
( V_492 -> V_266 ) ;
for ( V_19 = 0 ; V_19 < V_244 ; V_19 ++ ) {
if ( F_117 ( V_35 -> V_67 -> V_267 [ V_19 ] ,
V_265 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
if ( F_117 ( V_35 -> V_67 -> V_268 [ V_19 ] ,
V_266 + V_209 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_209 ++ ;
}
}
V_492 -> V_264 = V_244 ;
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_190 ( struct V_1 * V_2 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_487 * V_492 = V_198 ;
struct V_34 * V_493 ;
struct V_34 * V_494 ;
struct V_126 * V_432 ;
int V_8 = - V_197 ;
int V_19 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_493 = F_36 ( V_2 , V_492 -> V_489 , V_492 -> V_36 ) ;
if ( ! V_493 ) {
V_8 = - V_234 ;
goto V_52;
}
if ( ! V_493 -> V_67 )
goto V_52;
for ( V_19 = 0 ; V_19 < V_493 -> V_67 -> V_251 ; V_19 ++ )
if ( V_493 -> V_67 -> V_267 [ V_19 ] == V_492 -> V_465 )
break;
if ( V_19 == V_493 -> V_67 -> V_251 )
goto V_52;
V_494 = F_36 ( V_2 , V_492 -> V_465 ,
V_433 ) ;
if ( ! V_494 ) {
V_8 = - V_234 ;
goto V_52;
}
V_432 = F_196 ( V_494 ) ;
if ( ! F_187 ( V_432 , V_492 -> V_447 ) )
goto V_52;
switch ( V_493 -> type ) {
case V_81 :
V_8 = F_191 ( V_493 , V_432 ,
V_492 -> V_447 ) ;
break;
case V_66 :
V_8 = F_193 ( V_493 , V_432 , V_492 -> V_447 ) ;
break;
case V_115 :
V_8 = F_194 ( V_493 , V_432 , V_492 -> V_447 ) ;
break;
}
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_197 ( struct V_74 * V_75 ,
struct V_103 * V_104 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_252 ; V_19 ++ ) {
if ( V_75 -> V_253 [ V_19 ] == 0 ) {
V_75 -> V_253 [ V_19 ] = V_104 -> V_51 . V_40 ;
return 0 ;
}
}
return - V_85 ;
}
int F_198 ( struct V_16 * V_17 ,
int V_237 )
{
V_17 -> V_237 = V_237 ;
V_17 -> V_71 = F_2 ( V_237 * sizeof( V_495 ) * 3 , V_9 ) ;
if ( ! V_17 -> V_71 ) {
V_17 -> V_237 = 0 ;
return - V_85 ;
}
return 0 ;
}
int F_199 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_496 * V_497 = V_198 ;
struct V_16 * V_17 ;
void * V_498 , * V_499 , * V_500 ;
int V_478 ;
int V_8 = 0 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_17 = F_120 ( V_2 , V_497 -> V_211 ) ;
if ( ! V_17 ) {
V_8 = - V_234 ;
goto V_52;
}
if ( V_17 -> V_47 -> V_501 == NULL ) {
V_8 = - V_428 ;
goto V_52;
}
if ( V_497 -> V_237 != V_17 -> V_237 ) {
V_8 = - V_197 ;
goto V_52;
}
V_478 = V_497 -> V_237 * ( sizeof( V_495 ) ) ;
V_498 = V_17 -> V_71 ;
if ( F_166 ( V_498 , ( void T_2 * ) ( unsigned long ) V_497 -> V_502 , V_478 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_499 = V_498 + V_478 ;
if ( F_166 ( V_499 , ( void T_2 * ) ( unsigned long ) V_497 -> V_503 , V_478 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_500 = V_499 + V_478 ;
if ( F_166 ( V_500 , ( void T_2 * ) ( unsigned long ) V_497 -> V_504 , V_478 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_17 -> V_47 -> V_501 ( V_17 , V_498 , V_499 , V_500 , 0 , V_17 -> V_237 ) ;
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_200 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_496 * V_497 = V_198 ;
struct V_16 * V_17 ;
void * V_498 , * V_499 , * V_500 ;
int V_478 ;
int V_8 = 0 ;
if ( ! F_115 ( V_2 , V_214 ) )
return - V_197 ;
F_1 ( V_2 ) ;
V_17 = F_120 ( V_2 , V_497 -> V_211 ) ;
if ( ! V_17 ) {
V_8 = - V_234 ;
goto V_52;
}
if ( V_497 -> V_237 != V_17 -> V_237 ) {
V_8 = - V_197 ;
goto V_52;
}
V_478 = V_497 -> V_237 * ( sizeof( V_495 ) ) ;
V_498 = V_17 -> V_71 ;
if ( F_126 ( ( void T_2 * ) ( unsigned long ) V_497 -> V_502 , V_498 , V_478 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_499 = V_498 + V_478 ;
if ( F_126 ( ( void T_2 * ) ( unsigned long ) V_497 -> V_503 , V_499 , V_478 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_500 = V_499 + V_478 ;
if ( F_126 ( ( void T_2 * ) ( unsigned long ) V_497 -> V_504 , V_500 , V_478 ) ) {
V_8 = - V_218 ;
goto V_52;
}
V_52:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_201 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_505 * V_506 = V_198 ;
struct V_16 * V_17 ;
struct V_44 * V_45 = NULL , * V_124 = NULL ;
struct V_507 * V_508 = NULL ;
unsigned long V_191 ;
int V_8 = - V_197 ;
if ( V_506 -> V_191 & ~ V_509 ||
V_506 -> V_510 != 0 )
return - V_197 ;
if ( ( V_506 -> V_191 & V_511 ) && ! V_2 -> V_5 . V_512 )
return - V_197 ;
V_17 = F_120 ( V_2 , V_506 -> V_211 ) ;
if ( ! V_17 )
return - V_234 ;
F_6 ( & V_17 -> V_10 , NULL ) ;
if ( V_17 -> V_62 -> V_45 == NULL ) {
V_8 = - V_513 ;
goto V_52;
}
if ( V_17 -> V_47 -> V_506 == NULL )
goto V_52;
V_45 = F_46 ( V_2 , V_506 -> V_210 ) ;
if ( ! V_45 ) {
V_8 = - V_234 ;
goto V_52;
}
V_8 = F_137 ( V_17 , V_17 -> V_235 , V_17 -> V_236 , & V_17 -> V_77 , V_45 ) ;
if ( V_8 )
goto V_52;
if ( V_17 -> V_62 -> V_45 -> V_295 != V_45 -> V_295 ) {
F_92 ( L_72 ) ;
V_8 = - V_197 ;
goto V_52;
}
if ( V_506 -> V_191 & V_514 ) {
V_8 = - V_85 ;
F_202 ( & V_2 -> V_515 , V_191 ) ;
if ( V_200 -> V_516 < sizeof V_508 -> V_517 ) {
F_203 ( & V_2 -> V_515 , V_191 ) ;
goto V_52;
}
V_200 -> V_516 -= sizeof V_508 -> V_517 ;
F_203 ( & V_2 -> V_515 , V_191 ) ;
V_508 = F_2 ( sizeof *V_508 , V_9 ) ;
if ( V_508 == NULL ) {
F_202 ( & V_2 -> V_515 , V_191 ) ;
V_200 -> V_516 += sizeof V_508 -> V_517 ;
F_203 ( & V_2 -> V_515 , V_191 ) ;
goto V_52;
}
V_508 -> V_517 . V_51 . type = V_518 ;
V_508 -> V_517 . V_51 . V_470 = sizeof V_508 -> V_517 ;
V_508 -> V_517 . V_519 = V_506 -> V_519 ;
V_508 -> V_51 . V_517 = & V_508 -> V_517 . V_51 ;
V_508 -> V_51 . V_200 = V_200 ;
V_508 -> V_51 . V_57 =
( void ( * ) ( struct V_520 * ) ) F_13 ;
}
V_124 = V_17 -> V_62 -> V_45 ;
V_8 = V_17 -> V_47 -> V_506 ( V_17 , V_45 , V_508 , V_506 -> V_191 ) ;
if ( V_8 ) {
if ( V_506 -> V_191 & V_514 ) {
F_202 ( & V_2 -> V_515 , V_191 ) ;
V_200 -> V_516 += sizeof V_508 -> V_517 ;
F_203 ( & V_2 -> V_515 , V_191 ) ;
F_13 ( V_508 ) ;
}
V_124 = NULL ;
} else {
F_3 ( V_17 -> V_62 -> V_45 != V_45 ) ;
V_45 = NULL ;
}
V_52:
if ( V_45 )
F_47 ( V_45 ) ;
if ( V_124 )
F_47 ( V_124 ) ;
F_125 ( & V_17 -> V_10 ) ;
return V_8 ;
}
void F_204 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_103 * V_104 ;
struct V_74 * V_75 ;
F_15 (crtc, &dev->mode_config.crtc_list, head)
if ( V_17 -> V_47 -> V_521 )
V_17 -> V_47 -> V_521 ( V_17 ) ;
F_15 (encoder, &dev->mode_config.encoder_list, head)
if ( V_104 -> V_47 -> V_521 )
V_104 -> V_47 -> V_521 ( V_104 ) ;
F_15 (connector, &dev->mode_config.connector_list, head) {
V_75 -> V_23 = V_89 ;
if ( V_75 -> V_47 -> V_521 )
V_75 -> V_47 -> V_521 ( V_75 ) ;
}
}
int F_205 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_522 * args = V_198 ;
T_5 V_404 , V_523 , V_478 ;
if ( ! V_2 -> V_524 -> V_525 )
return - V_428 ;
if ( ! args -> V_296 || ! args -> V_297 || ! args -> V_334 )
return - V_197 ;
V_404 = F_206 ( args -> V_334 , 8 ) ;
if ( ! V_404 || V_404 > 0xffffffffU / args -> V_296 )
return - V_197 ;
V_523 = V_404 * args -> V_296 ;
if ( args -> V_297 > 0xffffffffU / V_523 )
return - V_197 ;
V_478 = args -> V_297 * V_523 ;
if ( F_207 ( V_478 ) == 0 )
return - V_197 ;
return V_2 -> V_524 -> V_525 ( V_200 , V_2 , args ) ;
}
int F_208 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_526 * args = V_198 ;
if ( ! V_2 -> V_524 -> V_527 )
return - V_428 ;
return V_2 -> V_524 -> V_527 ( V_200 , V_2 , args -> V_320 , & args -> V_528 ) ;
}
int F_209 ( struct V_1 * V_2 ,
void * V_198 , struct V_199 * V_200 )
{
struct V_529 * args = V_198 ;
if ( ! V_2 -> V_524 -> V_530 )
return - V_428 ;
return V_2 -> V_524 -> V_530 ( V_200 , V_2 , args -> V_320 ) ;
}
void F_210 ( T_1 V_31 , unsigned int * V_335 ,
int * V_334 )
{
switch ( V_31 ) {
case V_337 :
case V_349 :
case V_350 :
* V_335 = 8 ;
* V_334 = 8 ;
break;
case V_338 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
* V_335 = 15 ;
* V_334 = 16 ;
break;
case V_339 :
case V_366 :
* V_335 = 16 ;
* V_334 = 16 ;
break;
case V_340 :
case V_367 :
* V_335 = 24 ;
* V_334 = 24 ;
break;
case V_341 :
case V_368 :
case V_369 :
case V_370 :
* V_335 = 24 ;
* V_334 = 32 ;
break;
case V_342 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
* V_335 = 30 ;
* V_334 = 32 ;
break;
case V_317 :
case V_371 :
case V_372 :
case V_373 :
* V_335 = 32 ;
* V_334 = 32 ;
break;
default:
F_92 ( L_73 ,
F_26 ( V_31 ) ) ;
* V_335 = 0 ;
* V_334 = 0 ;
break;
}
}
int F_156 ( T_1 V_31 )
{
switch ( V_31 ) {
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
return 3 ;
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
return 2 ;
default:
return 1 ;
}
}
int F_157 ( T_1 V_31 , int V_59 )
{
unsigned int V_335 ;
int V_334 ;
if ( V_59 >= F_156 ( V_31 ) )
return 0 ;
switch ( V_31 ) {
case V_381 :
case V_382 :
case V_383 :
case V_384 :
return 2 ;
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
return V_59 ? 2 : 1 ;
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
return 1 ;
default:
F_210 ( V_31 , & V_335 , & V_334 ) ;
return V_334 >> 3 ;
}
}
int F_154 ( T_1 V_31 )
{
switch ( V_31 ) {
case V_394 :
case V_395 :
case V_392 :
case V_393 :
return 4 ;
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_398 :
case V_399 :
case V_396 :
case V_397 :
return 2 ;
default:
return 1 ;
}
}
int F_155 ( T_1 V_31 )
{
switch ( V_31 ) {
case V_392 :
case V_393 :
return 4 ;
case V_396 :
case V_397 :
case V_386 :
case V_387 :
return 2 ;
default:
return 1 ;
}
}
unsigned int F_211 ( unsigned int V_531 ,
unsigned int V_532 )
{
if ( V_531 & ~ V_532 ) {
V_531 ^= F_212 ( V_533 ) | F_212 ( V_534 ) ;
V_531 = ( V_531 & ~ 0xf ) | F_212 ( ( F_213 ( V_531 & 0xf ) + 1 ) % 4 ) ;
}
return V_531 ;
}
void F_214 ( struct V_1 * V_2 )
{
F_215 ( & V_2 -> V_5 . V_10 ) ;
F_65 ( & V_2 -> V_5 . V_12 ) ;
F_215 ( & V_2 -> V_5 . V_38 ) ;
F_215 ( & V_2 -> V_5 . V_48 ) ;
F_39 ( & V_2 -> V_5 . V_55 ) ;
F_39 ( & V_2 -> V_5 . V_68 ) ;
F_39 ( & V_2 -> V_5 . V_90 ) ;
F_39 ( & V_2 -> V_5 . V_101 ) ;
F_39 ( & V_2 -> V_5 . V_109 ) ;
F_39 ( & V_2 -> V_5 . V_436 ) ;
F_39 ( & V_2 -> V_5 . V_473 ) ;
F_39 ( & V_2 -> V_5 . V_117 ) ;
F_216 ( & V_2 -> V_5 . V_39 ) ;
F_1 ( V_2 ) ;
F_96 ( V_2 ) ;
F_99 ( V_2 ) ;
F_10 ( V_2 ) ;
V_2 -> V_5 . V_53 = 0 ;
V_2 -> V_5 . V_91 = 0 ;
V_2 -> V_5 . V_69 = 0 ;
V_2 -> V_5 . V_110 = 0 ;
V_2 -> V_5 . V_120 = 0 ;
V_2 -> V_5 . V_118 = 0 ;
}
void F_217 ( struct V_1 * V_2 )
{
struct V_74 * V_75 , * V_535 ;
struct V_16 * V_17 , * V_536 ;
struct V_103 * V_104 , * V_537 ;
struct V_97 * V_98 , * V_538 ;
struct V_44 * V_45 , * V_539 ;
struct V_126 * V_432 , * V_450 ;
struct V_460 * V_471 , * V_540 ;
struct V_58 * V_59 , * V_541 ;
F_77 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_104 -> V_47 -> V_57 ( V_104 ) ;
}
F_77 (bridge, brt,
&dev->mode_config.bridge_list, head) {
V_98 -> V_47 -> V_57 ( V_98 ) ;
}
F_77 (connector, ot,
&dev->mode_config.connector_list, head) {
V_75 -> V_47 -> V_57 ( V_75 ) ;
}
F_77 (property, pt, &dev->mode_config.property_list,
head) {
F_169 ( V_2 , V_432 ) ;
}
F_77 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_182 ( V_2 , V_471 ) ;
}
F_3 ( ! F_60 ( & V_2 -> V_5 . V_55 ) ) ;
F_77 (fb, fbt, &dev->mode_config.fb_list, head) {
F_59 ( V_45 ) ;
}
F_77 (plane, plt, &dev->mode_config.plane_list,
head) {
V_59 -> V_47 -> V_57 ( V_59 ) ;
}
F_77 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_17 -> V_47 -> V_57 ( V_17 ) ;
}
F_218 ( & V_2 -> V_5 . V_39 ) ;
F_69 ( & V_2 -> V_5 . V_12 ) ;
}
struct V_126 * F_219 ( struct V_1 * V_2 ,
unsigned int V_532 )
{
static const struct V_437 V_438 [] = {
{ V_542 , L_74 } ,
{ V_543 , L_75 } ,
{ V_544 , L_76 } ,
{ V_545 , L_77 } ,
{ V_533 , L_78 } ,
{ V_534 , L_79 } ,
} ;
return F_170 ( V_2 , 0 , L_80 ,
V_438 , F_19 ( V_438 ) ,
V_532 ) ;
}
