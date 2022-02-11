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
int F_27 ( struct V_1 * V_2 ,
struct V_34 * V_35 , T_1 V_36 )
{
int V_8 ;
F_4 ( & V_2 -> V_5 . V_37 ) ;
V_8 = F_28 ( & V_2 -> V_5 . V_38 , V_35 , 1 , 0 , V_9 ) ;
if ( V_8 >= 0 ) {
V_35 -> V_39 = V_8 ;
V_35 -> type = V_36 ;
}
F_14 ( & V_2 -> V_5 . V_37 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_34 * V_40 )
{
F_4 ( & V_2 -> V_5 . V_37 ) ;
F_30 ( & V_2 -> V_5 . V_38 , V_40 -> V_39 ) ;
F_14 ( & V_2 -> V_5 . V_37 ) ;
}
static struct V_34 * F_31 ( struct V_1 * V_2 ,
T_1 V_39 , T_1 type )
{
struct V_34 * V_35 = NULL ;
F_4 ( & V_2 -> V_5 . V_37 ) ;
V_35 = F_32 ( & V_2 -> V_5 . V_38 , V_39 ) ;
if ( ! V_35 || ( type != V_41 && V_35 -> type != type ) ||
( V_35 -> V_39 != V_39 ) )
V_35 = NULL ;
F_14 ( & V_2 -> V_5 . V_37 ) ;
return V_35 ;
}
struct V_34 * F_33 ( struct V_1 * V_2 ,
T_1 V_39 , T_1 type )
{
struct V_34 * V_35 = NULL ;
F_3 ( type == V_42 ) ;
V_35 = F_31 ( V_2 , V_39 , type ) ;
if ( V_35 && ( V_35 -> type == V_42 ) )
V_35 = NULL ;
return V_35 ;
}
int F_34 ( struct V_1 * V_2 , struct V_43 * V_44 ,
const struct V_45 * V_46 )
{
int V_8 ;
F_4 ( & V_2 -> V_5 . V_47 ) ;
F_35 ( & V_44 -> V_48 ) ;
F_36 ( & V_44 -> V_49 ) ;
V_44 -> V_2 = V_2 ;
V_44 -> V_46 = V_46 ;
V_8 = F_27 ( V_2 , & V_44 -> V_50 , V_42 ) ;
if ( V_8 )
goto V_51;
F_37 ( V_44 ) ;
V_2 -> V_5 . V_52 ++ ;
F_38 ( & V_44 -> V_53 , & V_2 -> V_5 . V_54 ) ;
V_51:
F_14 ( & V_2 -> V_5 . V_47 ) ;
return 0 ;
}
static void F_39 ( struct V_55 * V_55 )
{
struct V_43 * V_44 =
F_40 ( V_55 , struct V_43 , V_48 ) ;
V_44 -> V_46 -> V_56 ( V_44 ) ;
}
static struct V_43 * F_41 ( struct V_1 * V_2 ,
T_1 V_39 )
{
struct V_34 * V_35 = NULL ;
struct V_43 * V_44 ;
F_4 ( & V_2 -> V_5 . V_37 ) ;
V_35 = F_32 ( & V_2 -> V_5 . V_38 , V_39 ) ;
if ( ! V_35 || ( V_35 -> type != V_42 ) || ( V_35 -> V_39 != V_39 ) )
V_44 = NULL ;
else
V_44 = F_42 ( V_35 ) ;
F_14 ( & V_2 -> V_5 . V_37 ) ;
return V_44 ;
}
struct V_43 * F_43 ( struct V_1 * V_2 ,
T_1 V_39 )
{
struct V_43 * V_44 ;
F_4 ( & V_2 -> V_5 . V_47 ) ;
V_44 = F_41 ( V_2 , V_39 ) ;
if ( V_44 )
F_37 ( V_44 ) ;
F_14 ( & V_2 -> V_5 . V_47 ) ;
return V_44 ;
}
void F_44 ( struct V_43 * V_44 )
{
F_45 ( L_7 , V_44 , V_44 -> V_50 . V_39 , F_46 ( & V_44 -> V_48 . V_48 ) ) ;
F_47 ( & V_44 -> V_48 , F_39 ) ;
}
void F_37 ( struct V_43 * V_44 )
{
F_45 ( L_7 , V_44 , V_44 -> V_50 . V_39 , F_46 ( & V_44 -> V_48 . V_48 ) ) ;
F_48 ( & V_44 -> V_48 ) ;
}
static void F_49 ( struct V_55 * V_55 )
{
F_50 () ;
}
static void F_51 ( struct V_43 * V_44 )
{
F_45 ( L_7 , V_44 , V_44 -> V_50 . V_39 , F_46 ( & V_44 -> V_48 . V_48 ) ) ;
F_47 ( & V_44 -> V_48 , F_49 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
F_4 ( & V_2 -> V_5 . V_37 ) ;
F_30 ( & V_2 -> V_5 . V_38 , V_44 -> V_50 . V_39 ) ;
F_14 ( & V_2 -> V_5 . V_37 ) ;
V_44 -> V_50 . V_39 = 0 ;
F_51 ( V_44 ) ;
}
void F_53 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
F_4 ( & V_2 -> V_5 . V_47 ) ;
F_52 ( V_2 , V_44 ) ;
F_14 ( & V_2 -> V_5 . V_47 ) ;
}
void F_54 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
F_4 ( & V_2 -> V_5 . V_47 ) ;
F_55 ( & V_44 -> V_53 ) ;
V_2 -> V_5 . V_52 -- ;
F_14 ( & V_2 -> V_5 . V_47 ) ;
}
void F_56 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_16 * V_17 ;
struct V_57 * V_58 ;
struct V_59 V_60 ;
int V_8 ;
F_3 ( ! F_57 ( & V_44 -> V_49 ) ) ;
if ( F_46 ( & V_44 -> V_48 . V_48 ) > 1 ) {
F_1 ( V_2 ) ;
F_15 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_17 -> V_61 -> V_44 == V_44 ) {
memset ( & V_60 , 0 , sizeof( struct V_59 ) ) ;
V_60 . V_17 = V_17 ;
V_60 . V_44 = NULL ;
V_8 = F_58 ( & V_60 ) ;
if ( V_8 )
F_59 ( L_8 , V_17 ) ;
}
}
F_15 (plane, &dev->mode_config.plane_list, head) {
if ( V_58 -> V_44 == V_44 )
F_60 ( V_58 ) ;
}
F_10 ( V_2 ) ;
}
F_44 ( V_44 ) ;
}
int F_61 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_57 * V_61 ,
void * V_62 ,
const struct V_63 * V_46 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_8 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_64 = false ;
F_1 ( V_2 ) ;
F_62 ( & V_17 -> V_10 ) ;
F_6 ( & V_17 -> V_10 , V_4 -> V_14 ) ;
V_8 = F_27 ( V_2 , & V_17 -> V_50 , V_65 ) ;
if ( V_8 )
goto V_51;
V_17 -> V_50 . V_66 = & V_17 -> V_66 ;
F_63 ( & V_17 -> V_53 , & V_4 -> V_67 ) ;
V_4 -> V_68 ++ ;
V_17 -> V_61 = V_61 ;
if ( V_61 )
V_61 -> V_69 = 1 << F_64 ( V_17 ) ;
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
void F_65 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
F_13 ( V_17 -> V_70 ) ;
V_17 -> V_70 = NULL ;
F_66 ( & V_17 -> V_10 ) ;
F_29 ( V_2 , & V_17 -> V_50 ) ;
F_55 ( & V_17 -> V_53 ) ;
V_2 -> V_5 . V_68 -- ;
}
unsigned int F_64 ( struct V_16 * V_17 )
{
unsigned int V_71 = 0 ;
struct V_16 * V_72 ;
F_15 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_72 == V_17 )
return V_71 ;
V_71 ++ ;
}
F_50 () ;
}
static void F_67 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
F_55 ( & V_76 -> V_53 ) ;
F_68 ( V_74 -> V_2 , V_76 ) ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
const struct V_77 * V_46 ,
int V_78 )
{
int V_8 ;
struct V_21 * V_79 =
& V_20 [ V_78 ] . V_21 ;
F_1 ( V_2 ) ;
V_8 = F_27 ( V_2 , & V_74 -> V_50 , V_80 ) ;
if ( V_8 )
goto V_81;
V_74 -> V_50 . V_66 = & V_74 -> V_66 ;
V_74 -> V_2 = V_2 ;
V_74 -> V_46 = V_46 ;
V_74 -> V_78 = V_78 ;
V_74 -> V_82 =
F_70 ( V_79 , 1 , 0 , V_9 ) ;
if ( V_74 -> V_82 < 0 ) {
V_8 = V_74 -> V_82 ;
goto V_83;
}
V_74 -> V_29 =
F_71 ( V_9 , L_9 ,
V_20 [ V_78 ] . V_29 ,
V_74 -> V_82 ) ;
if ( ! V_74 -> V_29 ) {
V_8 = - V_84 ;
goto V_83;
}
F_36 ( & V_74 -> V_85 ) ;
F_36 ( & V_74 -> V_86 ) ;
V_74 -> V_87 = NULL ;
V_74 -> V_23 = V_88 ;
F_63 ( & V_74 -> V_53 , & V_2 -> V_5 . V_89 ) ;
V_2 -> V_5 . V_90 ++ ;
if ( V_78 != V_91 )
F_72 ( & V_74 -> V_50 ,
V_2 -> V_5 . V_92 ,
0 ) ;
F_72 ( & V_74 -> V_50 ,
V_2 -> V_5 . V_93 , 0 ) ;
V_83:
if ( V_8 )
F_29 ( V_2 , & V_74 -> V_50 ) ;
V_81:
F_10 ( V_2 ) ;
return V_8 ;
}
void F_73 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
struct V_75 * V_76 , * V_94 ;
F_74 (mode, t, &connector->probed_modes, head)
F_67 ( V_74 , V_76 ) ;
F_74 (mode, t, &connector->modes, head)
F_67 ( V_74 , V_76 ) ;
F_75 ( & V_20 [ V_74 -> V_78 ] . V_21 ,
V_74 -> V_82 ) ;
F_29 ( V_2 , & V_74 -> V_50 ) ;
F_13 ( V_74 -> V_29 ) ;
V_74 -> V_29 = NULL ;
F_55 ( & V_74 -> V_53 ) ;
V_2 -> V_5 . V_90 -- ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_73 * V_74 ;
F_15 (connector, &dev->mode_config.connector_list, head)
F_77 ( V_74 ) ;
}
int F_78 ( struct V_1 * V_2 , struct V_95 * V_96 ,
const struct V_97 * V_46 )
{
int V_8 ;
F_1 ( V_2 ) ;
V_8 = F_27 ( V_2 , & V_96 -> V_50 , V_98 ) ;
if ( V_8 )
goto V_51;
V_96 -> V_2 = V_2 ;
V_96 -> V_46 = V_46 ;
F_63 ( & V_96 -> V_53 , & V_2 -> V_5 . V_99 ) ;
V_2 -> V_5 . V_100 ++ ;
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
void F_79 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
F_1 ( V_2 ) ;
F_29 ( V_2 , & V_96 -> V_50 ) ;
F_55 ( & V_96 -> V_53 ) ;
V_2 -> V_5 . V_100 -- ;
F_10 ( V_2 ) ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_101 * V_102 ,
const struct V_103 * V_46 ,
int V_104 )
{
int V_8 ;
F_1 ( V_2 ) ;
V_8 = F_27 ( V_2 , & V_102 -> V_50 , V_105 ) ;
if ( V_8 )
goto V_81;
V_102 -> V_2 = V_2 ;
V_102 -> V_104 = V_104 ;
V_102 -> V_46 = V_46 ;
V_102 -> V_29 = F_71 ( V_9 , L_9 ,
V_106 [ V_104 ] . V_29 ,
V_102 -> V_50 . V_39 ) ;
if ( ! V_102 -> V_29 ) {
V_8 = - V_84 ;
goto V_83;
}
F_63 ( & V_102 -> V_53 , & V_2 -> V_5 . V_107 ) ;
V_2 -> V_5 . V_108 ++ ;
V_83:
if ( V_8 )
F_29 ( V_2 , & V_102 -> V_50 ) ;
V_81:
F_10 ( V_2 ) ;
return V_8 ;
}
void F_81 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
F_1 ( V_2 ) ;
F_29 ( V_2 , & V_102 -> V_50 ) ;
F_13 ( V_102 -> V_29 ) ;
V_102 -> V_29 = NULL ;
F_55 ( & V_102 -> V_53 ) ;
V_2 -> V_5 . V_108 -- ;
F_10 ( V_2 ) ;
}
int F_82 ( struct V_1 * V_2 , struct V_57 * V_58 ,
unsigned long V_69 ,
const struct V_109 * V_46 ,
const T_1 * V_110 , T_1 V_111 ,
enum V_112 type )
{
int V_8 ;
F_1 ( V_2 ) ;
V_8 = F_27 ( V_2 , & V_58 -> V_50 , V_113 ) ;
if ( V_8 )
goto V_51;
V_58 -> V_50 . V_66 = & V_58 -> V_66 ;
V_58 -> V_2 = V_2 ;
V_58 -> V_46 = V_46 ;
V_58 -> V_114 = F_83 ( sizeof( T_1 ) * V_111 ,
V_9 ) ;
if ( ! V_58 -> V_114 ) {
F_84 ( L_10 ) ;
F_29 ( V_2 , & V_58 -> V_50 ) ;
V_8 = - V_84 ;
goto V_51;
}
memcpy ( V_58 -> V_114 , V_110 , V_111 * sizeof( T_1 ) ) ;
V_58 -> V_111 = V_111 ;
V_58 -> V_69 = V_69 ;
V_58 -> type = type ;
F_63 ( & V_58 -> V_53 , & V_2 -> V_5 . V_115 ) ;
V_2 -> V_5 . V_116 ++ ;
if ( V_58 -> type == V_117 )
V_2 -> V_5 . V_118 ++ ;
F_72 ( & V_58 -> V_50 ,
V_2 -> V_5 . V_119 ,
V_58 -> type ) ;
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_85 ( struct V_1 * V_2 , struct V_57 * V_58 ,
unsigned long V_69 ,
const struct V_109 * V_46 ,
const T_1 * V_110 , T_1 V_111 ,
bool V_120 )
{
enum V_112 type ;
type = V_120 ? V_121 : V_117 ;
return F_82 ( V_2 , V_58 , V_69 , V_46 ,
V_110 , V_111 , type ) ;
}
void F_86 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
F_1 ( V_2 ) ;
F_13 ( V_58 -> V_114 ) ;
F_29 ( V_2 , & V_58 -> V_50 ) ;
F_87 ( F_57 ( & V_58 -> V_53 ) ) ;
F_55 ( & V_58 -> V_53 ) ;
V_2 -> V_5 . V_116 -- ;
if ( V_58 -> type == V_117 )
V_2 -> V_5 . V_118 -- ;
F_10 ( V_2 ) ;
}
void F_60 ( struct V_57 * V_58 )
{
struct V_43 * V_122 = V_58 -> V_44 ;
int V_8 ;
if ( ! V_122 )
return;
V_8 = V_58 -> V_46 -> V_123 ( V_58 ) ;
if ( V_8 ) {
F_59 ( L_11 ) ;
return;
}
F_51 ( V_122 ) ;
V_58 -> V_44 = NULL ;
V_58 -> V_17 = NULL ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_124 * V_125 ;
struct V_124 * V_126 ;
V_125 = F_89 ( V_2 , V_127 |
V_128 ,
L_12 , 0 ) ;
V_2 -> V_5 . V_92 = V_125 ;
V_126 = F_90 ( V_2 , 0 ,
L_13 , V_129 ,
F_19 ( V_129 ) ) ;
V_2 -> V_5 . V_93 = V_126 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_124 * type ;
type = F_90 ( V_2 , V_128 ,
L_14 , V_130 ,
F_19 ( V_130 ) ) ;
V_2 -> V_5 . V_119 = type ;
return 0 ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_124 * V_131 ;
struct V_124 * V_132 ;
if ( V_2 -> V_5 . V_133 )
return 0 ;
V_131 =
F_90 ( V_2 , 0 ,
L_15 ,
V_134 ,
F_19 ( V_134 ) ) ;
V_2 -> V_5 . V_133 = V_131 ;
V_132 = F_90 ( V_2 , V_128 ,
L_16 ,
V_135 ,
F_19 ( V_135 ) ) ;
V_2 -> V_5 . V_136 = V_132 ;
return 0 ;
}
int F_93 ( struct V_1 * V_2 , int V_137 ,
char * V_86 [] )
{
struct V_124 * V_138 ;
struct V_124 * V_139 ;
int V_19 ;
if ( V_2 -> V_5 . V_140 )
return 0 ;
V_138 = F_90 ( V_2 , 0 ,
L_15 ,
V_141 ,
F_19 ( V_141 ) ) ;
V_2 -> V_5 . V_140 = V_138 ;
V_139 =
F_90 ( V_2 , V_128 ,
L_16 ,
V_142 ,
F_19 ( V_142 ) ) ;
V_2 -> V_5 . V_143 = V_139 ;
V_2 -> V_5 . V_144 =
F_94 ( V_2 , 0 , L_17 , 0 , 100 ) ;
V_2 -> V_5 . V_145 =
F_94 ( V_2 , 0 , L_18 , 0 , 100 ) ;
V_2 -> V_5 . V_146 =
F_94 ( V_2 , 0 , L_19 , 0 , 100 ) ;
V_2 -> V_5 . V_147 =
F_94 ( V_2 , 0 , L_20 , 0 , 100 ) ;
V_2 -> V_5 . V_148 =
F_89 ( V_2 , V_149 ,
L_21 , V_137 ) ;
for ( V_19 = 0 ; V_19 < V_137 ; V_19 ++ )
F_95 ( V_2 -> V_5 . V_148 , V_19 ,
V_19 , V_86 [ V_19 ] ) ;
V_2 -> V_5 . V_150 =
F_94 ( V_2 , 0 , L_22 , 0 , 100 ) ;
V_2 -> V_5 . V_151 =
F_94 ( V_2 , 0 , L_23 , 0 , 100 ) ;
V_2 -> V_5 . V_152 =
F_94 ( V_2 , 0 , L_24 , 0 , 100 ) ;
V_2 -> V_5 . V_153 =
F_94 ( V_2 , 0 , L_25 , 0 , 100 ) ;
V_2 -> V_5 . V_154 =
F_94 ( V_2 , 0 , L_26 , 0 , 100 ) ;
V_2 -> V_5 . V_155 =
F_94 ( V_2 , 0 , L_27 , 0 , 100 ) ;
return 0 ;
}
int F_96 ( struct V_1 * V_2 )
{
struct V_124 * V_156 ;
if ( V_2 -> V_5 . V_157 )
return 0 ;
V_156 =
F_90 ( V_2 , 0 , L_28 ,
V_158 ,
F_19 ( V_158 ) ) ;
V_2 -> V_5 . V_157 = V_156 ;
return 0 ;
}
int F_97 ( struct V_1 * V_2 )
{
struct V_124 * V_159 ;
if ( V_2 -> V_5 . V_160 )
return 0 ;
V_159 =
F_90 ( V_2 , V_128 ,
L_29 ,
V_161 ,
F_19 ( V_161 ) ) ;
V_2 -> V_5 . V_160 = V_159 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
T_1 V_164 = 0 ;
V_164 += V_2 -> V_5 . V_68 ;
V_164 += V_2 -> V_5 . V_90 ;
V_164 += V_2 -> V_5 . V_108 ;
V_164 += V_2 -> V_5 . V_100 ;
V_163 -> V_165 = F_2 ( V_164 * sizeof( T_1 ) , V_9 ) ;
if ( ! V_163 -> V_165 )
return - V_84 ;
V_163 -> V_166 = 0 ;
V_163 -> V_167 = 0 ;
V_163 -> V_168 = 0 ;
V_163 -> V_169 = 0 ;
return 0 ;
}
void F_99 ( struct V_162 * V_163 )
{
F_13 ( V_163 -> V_165 ) ;
V_163 -> V_165 = NULL ;
}
int F_100 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
struct V_16 * V_17 ;
struct V_101 * V_102 ;
struct V_73 * V_74 ;
struct V_95 * V_96 ;
int V_8 ;
if ( ( V_8 = F_98 ( V_2 , V_163 ) ) )
return V_8 ;
F_15 (crtc, &dev->mode_config.crtc_list, head)
V_163 -> V_165 [ V_163 -> V_166 ++ ] = V_17 -> V_50 . V_39 ;
F_15 (encoder, &dev->mode_config.encoder_list, head)
V_163 -> V_165 [ V_163 -> V_166 + V_163 -> V_168 ++ ] =
V_102 -> V_50 . V_39 ;
F_15 (connector, &dev->mode_config.connector_list, head)
V_163 -> V_165 [ V_163 -> V_166 + V_163 -> V_168 +
V_163 -> V_167 ++ ] = V_74 -> V_50 . V_39 ;
F_15 (bridge, &dev->mode_config.bridge_list, head)
V_163 -> V_165 [ V_163 -> V_166 + V_163 -> V_168 +
V_163 -> V_167 + V_163 -> V_169 ++ ] =
V_96 -> V_50 . V_39 ;
return 0 ;
}
static void F_101 ( struct V_170 * V_51 ,
const struct V_75 * V_171 )
{
F_102 ( V_171 -> V_172 > V_173 || V_171 -> V_174 > V_173 ||
V_171 -> V_175 > V_173 || V_171 -> V_176 > V_173 ||
V_171 -> V_177 > V_173 || V_171 -> V_178 > V_173 ||
V_171 -> V_179 > V_173 || V_171 -> V_180 > V_173 ||
V_171 -> V_181 > V_173 || V_171 -> V_182 > V_173 ,
L_30 ) ;
V_51 -> clock = V_171 -> clock ;
V_51 -> V_172 = V_171 -> V_172 ;
V_51 -> V_174 = V_171 -> V_174 ;
V_51 -> V_175 = V_171 -> V_175 ;
V_51 -> V_176 = V_171 -> V_176 ;
V_51 -> V_177 = V_171 -> V_177 ;
V_51 -> V_178 = V_171 -> V_178 ;
V_51 -> V_179 = V_171 -> V_179 ;
V_51 -> V_180 = V_171 -> V_180 ;
V_51 -> V_181 = V_171 -> V_181 ;
V_51 -> V_182 = V_171 -> V_182 ;
V_51 -> V_183 = V_171 -> V_183 ;
V_51 -> V_184 = V_171 -> V_184 ;
V_51 -> type = V_171 -> type ;
strncpy ( V_51 -> V_29 , V_171 -> V_29 , V_185 ) ;
V_51 -> V_29 [ V_185 - 1 ] = 0 ;
}
static int F_103 ( struct V_75 * V_51 ,
const struct V_170 * V_171 )
{
if ( V_171 -> clock > V_186 || V_171 -> V_183 > V_186 )
return - V_187 ;
if ( ( V_171 -> V_184 & V_188 ) > V_189 )
return - V_190 ;
V_51 -> clock = V_171 -> clock ;
V_51 -> V_172 = V_171 -> V_172 ;
V_51 -> V_174 = V_171 -> V_174 ;
V_51 -> V_175 = V_171 -> V_175 ;
V_51 -> V_176 = V_171 -> V_176 ;
V_51 -> V_177 = V_171 -> V_177 ;
V_51 -> V_178 = V_171 -> V_178 ;
V_51 -> V_179 = V_171 -> V_179 ;
V_51 -> V_180 = V_171 -> V_180 ;
V_51 -> V_181 = V_171 -> V_181 ;
V_51 -> V_182 = V_171 -> V_182 ;
V_51 -> V_183 = V_171 -> V_183 ;
V_51 -> V_184 = V_171 -> V_184 ;
V_51 -> type = V_171 -> type ;
strncpy ( V_51 -> V_29 , V_171 -> V_29 , V_185 ) ;
V_51 -> V_29 [ V_185 - 1 ] = 0 ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 , void * V_191 ,
struct V_192 * V_193 )
{
struct V_194 * V_195 = V_191 ;
struct V_196 * V_197 ;
struct V_43 * V_44 ;
struct V_73 * V_74 ;
struct V_16 * V_17 ;
struct V_101 * V_102 ;
int V_8 = 0 ;
int V_198 = 0 ;
int V_199 = 0 ;
int V_200 = 0 ;
int V_201 = 0 ;
int V_202 = 0 , V_19 ;
T_1 T_2 * V_203 ;
T_1 T_2 * V_204 ;
T_1 T_2 * V_205 ;
T_1 T_2 * V_206 ;
struct V_162 * V_207 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_4 ( & V_193 -> V_209 ) ;
F_106 (lh, &file_priv->fbs)
V_200 ++ ;
if ( V_195 -> V_210 >= V_200 ) {
V_202 = 0 ;
V_203 = ( T_1 T_2 * ) ( unsigned long ) V_195 -> V_211 ;
F_15 (fb, &file_priv->fbs, filp_head) {
if ( F_107 ( V_44 -> V_50 . V_39 , V_203 + V_202 ) ) {
F_14 ( & V_193 -> V_209 ) ;
return - V_212 ;
}
V_202 ++ ;
}
}
V_195 -> V_210 = V_200 ;
F_14 ( & V_193 -> V_209 ) ;
F_1 ( V_2 ) ;
if ( ! F_108 ( V_193 ) ) {
V_207 = NULL ;
F_106 (lh, &dev->mode_config.crtc_list)
V_199 ++ ;
F_106 (lh, &dev->mode_config.connector_list)
V_198 ++ ;
F_106 (lh, &dev->mode_config.encoder_list)
V_201 ++ ;
} else {
V_207 = & V_193 -> V_213 -> V_214 -> V_207 ;
V_199 = V_207 -> V_166 ;
V_198 = V_207 -> V_167 ;
V_201 = V_207 -> V_168 ;
}
V_195 -> V_215 = V_2 -> V_5 . V_215 ;
V_195 -> V_216 = V_2 -> V_5 . V_216 ;
V_195 -> V_217 = V_2 -> V_5 . V_217 ;
V_195 -> V_218 = V_2 -> V_5 . V_218 ;
if ( V_195 -> V_219 >= V_199 ) {
V_202 = 0 ;
V_204 = ( T_1 T_2 * ) ( unsigned long ) V_195 -> V_220 ;
if ( ! V_207 ) {
F_15 (crtc, &dev->mode_config.crtc_list,
head) {
F_84 ( L_31 , V_17 -> V_50 . V_39 ) ;
if ( F_107 ( V_17 -> V_50 . V_39 , V_204 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
} else {
for ( V_19 = 0 ; V_19 < V_207 -> V_166 ; V_19 ++ ) {
if ( F_107 ( V_207 -> V_165 [ V_19 ] ,
V_204 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
}
}
V_195 -> V_219 = V_199 ;
if ( V_195 -> V_221 >= V_201 ) {
V_202 = 0 ;
V_206 = ( T_1 T_2 * ) ( unsigned long ) V_195 -> V_222 ;
if ( ! V_207 ) {
F_15 (encoder,
&dev->mode_config.encoder_list,
head) {
F_84 ( L_32 , V_102 -> V_50 . V_39 ,
V_102 -> V_29 ) ;
if ( F_107 ( V_102 -> V_50 . V_39 , V_206 +
V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
} else {
for ( V_19 = V_207 -> V_166 ; V_19 < V_207 -> V_166 + V_207 -> V_168 ; V_19 ++ ) {
if ( F_107 ( V_207 -> V_165 [ V_19 ] ,
V_206 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
}
}
V_195 -> V_221 = V_201 ;
if ( V_195 -> V_223 >= V_198 ) {
V_202 = 0 ;
V_205 = ( T_1 T_2 * ) ( unsigned long ) V_195 -> V_224 ;
if ( ! V_207 ) {
F_15 (connector,
&dev->mode_config.connector_list,
head) {
F_84 ( L_33 ,
V_74 -> V_50 . V_39 ,
V_74 -> V_29 ) ;
if ( F_107 ( V_74 -> V_50 . V_39 ,
V_205 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
} else {
int V_225 = V_207 -> V_166 +
V_207 -> V_168 ;
for ( V_19 = V_225 ; V_19 < V_225 + V_207 -> V_167 ; V_19 ++ ) {
if ( F_107 ( V_207 -> V_165 [ V_19 ] ,
V_205 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
}
}
V_195 -> V_223 = V_198 ;
F_84 ( L_34 , V_195 -> V_219 ,
V_195 -> V_223 , V_195 -> V_221 ) ;
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_109 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_226 * V_227 = V_191 ;
struct V_16 * V_17 ;
int V_8 = 0 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_17 = F_110 ( V_2 , V_227 -> V_204 ) ;
if ( ! V_17 ) {
V_8 = - V_228 ;
goto V_51;
}
V_227 -> V_229 = V_17 -> V_229 ;
V_227 -> V_230 = V_17 -> V_230 ;
V_227 -> V_231 = V_17 -> V_231 ;
if ( V_17 -> V_61 -> V_44 )
V_227 -> V_203 = V_17 -> V_61 -> V_44 -> V_50 . V_39 ;
else
V_227 -> V_203 = 0 ;
if ( V_17 -> V_232 ) {
F_101 ( & V_227 -> V_76 , & V_17 -> V_76 ) ;
V_227 -> V_233 = 1 ;
} else {
V_227 -> V_233 = 0 ;
}
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
static bool F_111 ( const struct V_75 * V_76 ,
const struct V_192 * V_193 )
{
if ( ! V_193 -> V_234 && F_112 ( V_76 ) )
return false ;
return true ;
}
int F_113 ( struct V_1 * V_2 , void * V_191 ,
struct V_192 * V_193 )
{
struct V_235 * V_236 = V_191 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
int V_237 = 0 ;
int V_238 = 0 ;
int V_239 = 0 ;
int V_8 = 0 ;
int V_202 = 0 ;
int V_19 ;
struct V_170 V_240 ;
struct V_170 T_2 * V_241 ;
T_1 T_2 * V_242 ;
T_3 T_2 * V_243 ;
T_1 T_2 * V_244 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
memset ( & V_240 , 0 , sizeof( struct V_170 ) ) ;
F_84 ( L_35 , V_236 -> V_205 ) ;
F_4 ( & V_2 -> V_5 . V_10 ) ;
V_74 = F_114 ( V_2 , V_236 -> V_205 ) ;
if ( ! V_74 ) {
V_8 = - V_228 ;
goto V_51;
}
V_238 = V_74 -> V_66 . V_245 ;
for ( V_19 = 0 ; V_19 < V_246 ; V_19 ++ ) {
if ( V_74 -> V_247 [ V_19 ] != 0 ) {
V_239 ++ ;
}
}
if ( V_236 -> V_248 == 0 ) {
V_74 -> V_46 -> V_249 ( V_74 ,
V_2 -> V_5 . V_217 ,
V_2 -> V_5 . V_215 ) ;
}
F_15 (mode, &connector->modes, head)
if ( F_111 ( V_76 , V_193 ) )
V_237 ++ ;
V_236 -> V_205 = V_74 -> V_50 . V_39 ;
V_236 -> V_78 = V_74 -> V_78 ;
V_236 -> V_82 = V_74 -> V_82 ;
V_236 -> V_250 = V_74 -> V_251 . V_252 ;
V_236 -> V_253 = V_74 -> V_251 . V_254 ;
V_236 -> V_255 = V_74 -> V_251 . V_26 ;
V_236 -> V_256 = V_74 -> V_23 ;
F_6 ( & V_2 -> V_5 . V_12 , NULL ) ;
if ( V_74 -> V_102 )
V_236 -> V_206 = V_74 -> V_102 -> V_50 . V_39 ;
else
V_236 -> V_206 = 0 ;
F_115 ( & V_2 -> V_5 . V_12 ) ;
if ( ( V_236 -> V_248 >= V_237 ) && V_237 ) {
V_202 = 0 ;
V_241 = (struct V_170 T_2 * ) ( unsigned long ) V_236 -> V_257 ;
F_15 (mode, &connector->modes, head) {
if ( ! F_111 ( V_76 , V_193 ) )
continue;
F_101 ( & V_240 , V_76 ) ;
if ( F_116 ( V_241 + V_202 ,
& V_240 , sizeof( V_240 ) ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
}
V_236 -> V_248 = V_237 ;
if ( ( V_236 -> V_258 >= V_238 ) && V_238 ) {
V_202 = 0 ;
V_242 = ( T_1 T_2 * ) ( unsigned long ) ( V_236 -> V_259 ) ;
V_243 = ( T_3 T_2 * ) ( unsigned long ) ( V_236 -> V_260 ) ;
for ( V_19 = 0 ; V_19 < V_74 -> V_66 . V_245 ; V_19 ++ ) {
if ( F_107 ( V_74 -> V_66 . V_261 [ V_19 ] ,
V_242 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
if ( F_107 ( V_74 -> V_66 . V_262 [ V_19 ] ,
V_243 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
}
V_236 -> V_258 = V_238 ;
if ( ( V_236 -> V_221 >= V_239 ) && V_239 ) {
V_202 = 0 ;
V_244 = ( T_1 T_2 * ) ( unsigned long ) ( V_236 -> V_263 ) ;
for ( V_19 = 0 ; V_19 < V_246 ; V_19 ++ ) {
if ( V_74 -> V_247 [ V_19 ] != 0 ) {
if ( F_107 ( V_74 -> V_247 [ V_19 ] ,
V_244 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
}
}
V_236 -> V_221 = V_239 ;
V_51:
F_14 ( & V_2 -> V_5 . V_10 ) ;
return V_8 ;
}
int F_117 ( struct V_1 * V_2 , void * V_191 ,
struct V_192 * V_193 )
{
struct V_264 * V_265 = V_191 ;
struct V_101 * V_102 ;
int V_8 = 0 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_102 = F_118 ( V_2 , V_265 -> V_206 ) ;
if ( ! V_102 ) {
V_8 = - V_228 ;
goto V_51;
}
if ( V_102 -> V_17 )
V_265 -> V_204 = V_102 -> V_17 -> V_50 . V_39 ;
else
V_265 -> V_204 = 0 ;
V_265 -> V_104 = V_102 -> V_104 ;
V_265 -> V_206 = V_102 -> V_50 . V_39 ;
V_265 -> V_69 = V_102 -> V_69 ;
V_265 -> V_266 = V_102 -> V_266 ;
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_119 ( struct V_1 * V_2 , void * V_191 ,
struct V_192 * V_193 )
{
struct V_267 * V_268 = V_191 ;
struct V_3 * V_4 ;
struct V_57 * V_58 ;
T_1 T_2 * V_269 ;
int V_202 = 0 , V_8 = 0 ;
unsigned V_270 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_4 = & V_2 -> V_5 ;
if ( V_193 -> V_271 )
V_270 = V_4 -> V_116 ;
else
V_270 = V_4 -> V_118 ;
if ( V_270 &&
( V_268 -> V_272 >= V_270 ) ) {
V_269 = ( T_1 T_2 * ) ( unsigned long ) V_268 -> V_273 ;
F_15 (plane, &config->plane_list, head) {
if ( V_58 -> type != V_117 &&
! V_193 -> V_271 )
continue;
if ( F_107 ( V_58 -> V_50 . V_39 , V_269 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
}
V_268 -> V_272 = V_270 ;
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_120 ( struct V_1 * V_2 , void * V_191 ,
struct V_192 * V_193 )
{
struct V_274 * V_268 = V_191 ;
struct V_57 * V_58 ;
T_1 T_2 * V_275 ;
int V_8 = 0 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_58 = F_121 ( V_2 , V_268 -> V_276 ) ;
if ( ! V_58 ) {
V_8 = - V_228 ;
goto V_51;
}
if ( V_58 -> V_17 )
V_268 -> V_204 = V_58 -> V_17 -> V_50 . V_39 ;
else
V_268 -> V_204 = 0 ;
if ( V_58 -> V_44 )
V_268 -> V_203 = V_58 -> V_44 -> V_50 . V_39 ;
else
V_268 -> V_203 = 0 ;
V_268 -> V_276 = V_58 -> V_50 . V_39 ;
V_268 -> V_69 = V_58 -> V_69 ;
V_268 -> V_231 = 0 ;
if ( V_58 -> V_111 &&
( V_268 -> V_277 >= V_58 -> V_111 ) ) {
V_275 = ( T_1 T_2 * ) ( unsigned long ) V_268 -> V_278 ;
if ( F_116 ( V_275 ,
V_58 -> V_114 ,
sizeof( T_1 ) * V_58 -> V_111 ) ) {
V_8 = - V_212 ;
goto V_51;
}
}
V_268 -> V_277 = V_58 -> V_111 ;
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_122 ( struct V_1 * V_2 , void * V_191 ,
struct V_192 * V_193 )
{
struct V_279 * V_280 = V_191 ;
struct V_57 * V_58 ;
struct V_16 * V_17 ;
struct V_43 * V_44 = NULL , * V_122 = NULL ;
int V_8 = 0 ;
unsigned int V_281 , V_282 ;
int V_19 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
V_58 = F_121 ( V_2 , V_280 -> V_276 ) ;
if ( ! V_58 ) {
F_84 ( L_36 ,
V_280 -> V_276 ) ;
return - V_228 ;
}
if ( ! V_280 -> V_203 ) {
F_1 ( V_2 ) ;
V_122 = V_58 -> V_44 ;
V_8 = V_58 -> V_46 -> V_123 ( V_58 ) ;
if ( ! V_8 ) {
V_58 -> V_17 = NULL ;
V_58 -> V_44 = NULL ;
} else {
V_122 = NULL ;
}
F_10 ( V_2 ) ;
goto V_51;
}
V_17 = F_110 ( V_2 , V_280 -> V_204 ) ;
if ( ! V_17 ) {
F_84 ( L_37 ,
V_280 -> V_204 ) ;
V_8 = - V_228 ;
goto V_51;
}
if ( ! ( V_58 -> V_69 & F_123 ( V_17 ) ) ) {
F_84 ( L_38 ) ;
V_8 = - V_190 ;
goto V_51;
}
V_44 = F_43 ( V_2 , V_280 -> V_203 ) ;
if ( ! V_44 ) {
F_84 ( L_39 ,
V_280 -> V_203 ) ;
V_8 = - V_228 ;
goto V_51;
}
for ( V_19 = 0 ; V_19 < V_58 -> V_111 ; V_19 ++ )
if ( V_44 -> V_283 == V_58 -> V_114 [ V_19 ] )
break;
if ( V_19 == V_58 -> V_111 ) {
F_84 ( L_40 ,
F_26 ( V_44 -> V_283 ) ) ;
V_8 = - V_190 ;
goto V_51;
}
V_281 = V_44 -> V_284 << 16 ;
V_282 = V_44 -> V_285 << 16 ;
if ( V_280 -> V_286 > V_281 ||
V_280 -> V_287 > V_281 - V_280 -> V_286 ||
V_280 -> V_288 > V_282 ||
V_280 -> V_289 > V_282 - V_280 -> V_288 ) {
F_84 ( L_41
L_42 ,
V_280 -> V_286 >> 16 ,
( ( V_280 -> V_286 & 0xffff ) * 15625 ) >> 10 ,
V_280 -> V_288 >> 16 ,
( ( V_280 -> V_288 & 0xffff ) * 15625 ) >> 10 ,
V_280 -> V_287 >> 16 ,
( ( V_280 -> V_287 & 0xffff ) * 15625 ) >> 10 ,
V_280 -> V_289 >> 16 ,
( ( V_280 -> V_289 & 0xffff ) * 15625 ) >> 10 ) ;
V_8 = - V_290 ;
goto V_51;
}
if ( V_280 -> V_291 > V_186 ||
V_280 -> V_292 > V_186 - ( V_293 ) V_280 -> V_291 ||
V_280 -> V_294 > V_186 ||
V_280 -> V_295 > V_186 - ( V_293 ) V_280 -> V_294 ) {
F_84 ( L_43 ,
V_280 -> V_291 , V_280 -> V_294 ,
V_280 -> V_292 , V_280 -> V_295 ) ;
V_8 = - V_187 ;
goto V_51;
}
F_1 ( V_2 ) ;
V_122 = V_58 -> V_44 ;
V_8 = V_58 -> V_46 -> V_296 ( V_58 , V_17 , V_44 ,
V_280 -> V_292 , V_280 -> V_295 ,
V_280 -> V_291 , V_280 -> V_294 ,
V_280 -> V_287 , V_280 -> V_289 ,
V_280 -> V_286 , V_280 -> V_288 ) ;
if ( ! V_8 ) {
V_58 -> V_17 = V_17 ;
V_58 -> V_44 = V_44 ;
V_44 = NULL ;
} else {
V_122 = NULL ;
}
F_10 ( V_2 ) ;
V_51:
if ( V_44 )
F_44 ( V_44 ) ;
if ( V_122 )
F_44 ( V_122 ) ;
return V_8 ;
}
int F_58 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = V_60 -> V_17 ;
struct V_43 * V_44 ;
struct V_16 * V_72 ;
int V_8 ;
F_15 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_72 -> V_122 = V_72 -> V_61 -> V_44 ;
V_44 = V_60 -> V_44 ;
V_8 = V_17 -> V_46 -> V_297 ( V_60 ) ;
if ( V_8 == 0 ) {
V_17 -> V_61 -> V_17 = V_17 ;
V_17 -> V_61 -> V_44 = V_44 ;
}
F_15 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_72 -> V_61 -> V_44 )
F_37 ( V_72 -> V_61 -> V_44 ) ;
if ( V_72 -> V_122 )
F_44 ( V_72 -> V_122 ) ;
}
return V_8 ;
}
int F_124 ( const struct V_16 * V_17 ,
int V_229 , int V_230 ,
const struct V_75 * V_76 ,
const struct V_43 * V_44 )
{
int V_172 , V_178 ;
V_172 = V_76 -> V_172 ;
V_178 = V_76 -> V_178 ;
if ( F_112 ( V_76 ) ) {
struct V_75 V_298 = * V_76 ;
F_125 ( & V_298 , V_299 ) ;
V_172 = V_298 . V_300 ;
V_178 = V_298 . V_301 ;
}
if ( V_17 -> V_64 )
F_126 ( V_172 , V_178 ) ;
if ( V_172 > V_44 -> V_284 ||
V_178 > V_44 -> V_285 ||
V_229 > V_44 -> V_284 - V_172 ||
V_230 > V_44 -> V_285 - V_178 ) {
F_84 ( L_44 ,
V_44 -> V_284 , V_44 -> V_285 , V_172 , V_178 , V_229 , V_230 ,
V_17 -> V_64 ? L_45 : L_46 ) ;
return - V_290 ;
}
return 0 ;
}
int F_127 ( struct V_1 * V_2 , void * V_191 ,
struct V_192 * V_193 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_226 * V_302 = V_191 ;
struct V_16 * V_17 ;
struct V_73 * * V_303 = NULL , * V_74 ;
struct V_43 * V_44 = NULL ;
struct V_75 * V_76 = NULL ;
struct V_59 V_60 ;
T_1 T_2 * V_304 ;
int V_8 ;
int V_19 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
if ( V_302 -> V_229 > V_186 || V_302 -> V_230 > V_186 )
return - V_187 ;
F_1 ( V_2 ) ;
V_17 = F_110 ( V_2 , V_302 -> V_204 ) ;
if ( ! V_17 ) {
F_84 ( L_47 , V_302 -> V_204 ) ;
V_8 = - V_228 ;
goto V_51;
}
F_84 ( L_31 , V_17 -> V_50 . V_39 ) ;
if ( V_302 -> V_233 ) {
if ( V_302 -> V_203 == - 1 ) {
if ( ! V_17 -> V_61 -> V_44 ) {
F_84 ( L_48 ) ;
V_8 = - V_190 ;
goto V_51;
}
V_44 = V_17 -> V_61 -> V_44 ;
F_37 ( V_44 ) ;
} else {
V_44 = F_43 ( V_2 , V_302 -> V_203 ) ;
if ( ! V_44 ) {
F_84 ( L_49 ,
V_302 -> V_203 ) ;
V_8 = - V_228 ;
goto V_51;
}
}
V_76 = F_128 ( V_2 ) ;
if ( ! V_76 ) {
V_8 = - V_84 ;
goto V_51;
}
V_8 = F_103 ( V_76 , & V_302 -> V_76 ) ;
if ( V_8 ) {
F_84 ( L_50 ) ;
goto V_51;
}
F_125 ( V_76 , V_305 ) ;
V_8 = F_124 ( V_17 , V_302 -> V_229 , V_302 -> V_230 ,
V_76 , V_44 ) ;
if ( V_8 )
goto V_51;
}
if ( V_302 -> V_223 == 0 && V_76 ) {
F_84 ( L_51 ) ;
V_8 = - V_190 ;
goto V_51;
}
if ( V_302 -> V_223 > 0 && ( ! V_76 || ! V_44 ) ) {
F_84 ( L_52 ,
V_302 -> V_223 ) ;
V_8 = - V_190 ;
goto V_51;
}
if ( V_302 -> V_223 > 0 ) {
T_4 V_306 ;
if ( V_302 -> V_223 > V_4 -> V_90 ) {
V_8 = - V_190 ;
goto V_51;
}
V_303 = F_83 ( V_302 -> V_223 *
sizeof( struct V_73 * ) ,
V_9 ) ;
if ( ! V_303 ) {
V_8 = - V_84 ;
goto V_51;
}
for ( V_19 = 0 ; V_19 < V_302 -> V_223 ; V_19 ++ ) {
V_304 = ( T_1 T_2 * ) ( unsigned long ) V_302 -> V_304 ;
if ( F_129 ( V_306 , & V_304 [ V_19 ] ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_74 = F_114 ( V_2 , V_306 ) ;
if ( ! V_74 ) {
F_84 ( L_53 ,
V_306 ) ;
V_8 = - V_228 ;
goto V_51;
}
F_84 ( L_33 ,
V_74 -> V_50 . V_39 ,
V_74 -> V_29 ) ;
V_303 [ V_19 ] = V_74 ;
}
}
V_60 . V_17 = V_17 ;
V_60 . V_229 = V_302 -> V_229 ;
V_60 . V_230 = V_302 -> V_230 ;
V_60 . V_76 = V_76 ;
V_60 . V_307 = V_303 ;
V_60 . V_167 = V_302 -> V_223 ;
V_60 . V_44 = V_44 ;
V_8 = F_58 ( & V_60 ) ;
V_51:
if ( V_44 )
F_44 ( V_44 ) ;
F_13 ( V_303 ) ;
F_68 ( V_2 , V_76 ) ;
F_10 ( V_2 ) ;
return V_8 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_308 * V_309 ,
struct V_192 * V_193 )
{
struct V_16 * V_17 ;
int V_8 = 0 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
if ( ! V_309 -> V_184 || ( ~ V_310 & V_309 -> V_184 ) )
return - V_190 ;
V_17 = F_110 ( V_2 , V_309 -> V_204 ) ;
if ( ! V_17 ) {
F_84 ( L_47 , V_309 -> V_204 ) ;
return - V_228 ;
}
F_6 ( & V_17 -> V_10 , NULL ) ;
if ( V_309 -> V_184 & V_311 ) {
if ( ! V_17 -> V_46 -> V_312 && ! V_17 -> V_46 -> V_313 ) {
V_8 = - V_314 ;
goto V_51;
}
if ( V_17 -> V_46 -> V_313 )
V_8 = V_17 -> V_46 -> V_313 ( V_17 , V_193 , V_309 -> V_315 ,
V_309 -> V_284 , V_309 -> V_285 , V_309 -> V_316 , V_309 -> V_317 ) ;
else
V_8 = V_17 -> V_46 -> V_312 ( V_17 , V_193 , V_309 -> V_315 ,
V_309 -> V_284 , V_309 -> V_285 ) ;
}
if ( V_309 -> V_184 & V_318 ) {
if ( V_17 -> V_46 -> V_319 ) {
V_8 = V_17 -> V_46 -> V_319 ( V_17 , V_309 -> V_229 , V_309 -> V_230 ) ;
} else {
V_8 = - V_212 ;
goto V_51;
}
}
V_51:
F_115 ( & V_17 -> V_10 ) ;
return V_8 ;
}
int F_131 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_320 * V_309 = V_191 ;
struct V_308 V_321 ;
memcpy ( & V_321 , V_309 , sizeof( struct V_320 ) ) ;
V_321 . V_316 = V_321 . V_317 = 0 ;
return F_130 ( V_2 , & V_321 , V_193 ) ;
}
int F_132 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_308 * V_309 = V_191 ;
return F_130 ( V_2 , V_309 , V_193 ) ;
}
T_1 F_133 ( T_1 V_322 , T_1 V_323 )
{
T_1 V_324 ;
switch ( V_322 ) {
case 8 :
V_324 = V_325 ;
break;
case 16 :
if ( V_323 == 15 )
V_324 = V_326 ;
else
V_324 = V_327 ;
break;
case 24 :
V_324 = V_328 ;
break;
case 32 :
if ( V_323 == 24 )
V_324 = V_329 ;
else if ( V_323 == 30 )
V_324 = V_330 ;
else
V_324 = V_331 ;
break;
default:
F_59 ( L_54 ) ;
V_324 = V_329 ;
break;
}
return V_324 ;
}
int F_134 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_332 * V_333 = V_191 ;
struct V_334 V_335 = {} ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_43 * V_44 ;
int V_8 = 0 ;
V_335 . V_203 = V_333 -> V_203 ;
V_335 . V_284 = V_333 -> V_284 ;
V_335 . V_285 = V_333 -> V_285 ;
V_335 . V_336 [ 0 ] = V_333 -> V_337 ;
V_335 . V_283 = F_133 ( V_333 -> V_322 , V_333 -> V_323 ) ;
V_335 . V_338 [ 0 ] = V_333 -> V_315 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
if ( ( V_4 -> V_218 > V_335 . V_284 ) || ( V_335 . V_284 > V_4 -> V_217 ) )
return - V_190 ;
if ( ( V_4 -> V_216 > V_335 . V_285 ) || ( V_335 . V_285 > V_4 -> V_215 ) )
return - V_190 ;
V_44 = V_2 -> V_5 . V_46 -> V_339 ( V_2 , V_193 , & V_335 ) ;
if ( F_135 ( V_44 ) ) {
F_84 ( L_55 ) ;
return F_136 ( V_44 ) ;
}
F_4 ( & V_193 -> V_209 ) ;
V_333 -> V_203 = V_44 -> V_50 . V_39 ;
F_38 ( & V_44 -> V_49 , & V_193 -> V_340 ) ;
F_84 ( L_56 , V_44 -> V_50 . V_39 ) ;
F_14 ( & V_193 -> V_209 ) ;
return V_8 ;
}
static int F_137 ( const struct V_334 * V_335 )
{
T_1 V_31 = V_335 -> V_283 & ~ V_33 ;
switch ( V_31 ) {
case V_325 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_326 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_327 :
case V_358 :
case V_328 :
case V_359 :
case V_329 :
case V_360 :
case V_361 :
case V_362 :
case V_331 :
case V_363 :
case V_364 :
case V_365 :
case V_330 :
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
return 0 ;
default:
F_84 ( L_57 ,
F_26 ( V_335 -> V_283 ) ) ;
return - V_190 ;
}
}
static int F_138 ( const struct V_334 * V_335 )
{
int V_8 , V_394 , V_395 , V_270 , V_19 ;
V_8 = F_137 ( V_335 ) ;
if ( V_8 ) {
F_84 ( L_58 ,
F_26 ( V_335 -> V_283 ) ) ;
return V_8 ;
}
V_394 = F_139 ( V_335 -> V_283 ) ;
V_395 = F_140 ( V_335 -> V_283 ) ;
V_270 = F_141 ( V_335 -> V_283 ) ;
if ( V_335 -> V_284 == 0 || V_335 -> V_284 % V_394 ) {
F_84 ( L_59 , V_335 -> V_285 ) ;
return - V_190 ;
}
if ( V_335 -> V_285 == 0 || V_335 -> V_285 % V_395 ) {
F_84 ( L_60 , V_335 -> V_285 ) ;
return - V_190 ;
}
for ( V_19 = 0 ; V_19 < V_270 ; V_19 ++ ) {
unsigned int V_284 = V_335 -> V_284 / ( V_19 != 0 ? V_394 : 1 ) ;
unsigned int V_285 = V_335 -> V_285 / ( V_19 != 0 ? V_395 : 1 ) ;
unsigned int V_396 = F_142 ( V_335 -> V_283 , V_19 ) ;
if ( ! V_335 -> V_338 [ V_19 ] ) {
F_84 ( L_61 , V_19 ) ;
return - V_190 ;
}
if ( ( T_3 ) V_284 * V_396 > V_397 )
return - V_187 ;
if ( ( T_3 ) V_285 * V_335 -> V_336 [ V_19 ] + V_335 -> V_398 [ V_19 ] > V_397 )
return - V_187 ;
if ( V_335 -> V_336 [ V_19 ] < V_284 * V_396 ) {
F_84 ( L_62 , V_335 -> V_336 [ V_19 ] , V_19 ) ;
return - V_190 ;
}
}
return 0 ;
}
int F_143 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_334 * V_335 = V_191 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_43 * V_44 ;
int V_8 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
if ( V_335 -> V_184 & ~ V_399 ) {
F_84 ( L_63 , V_335 -> V_184 ) ;
return - V_190 ;
}
if ( ( V_4 -> V_218 > V_335 -> V_284 ) || ( V_335 -> V_284 > V_4 -> V_217 ) ) {
F_84 ( L_64 ,
V_335 -> V_284 , V_4 -> V_218 , V_4 -> V_217 ) ;
return - V_190 ;
}
if ( ( V_4 -> V_216 > V_335 -> V_285 ) || ( V_335 -> V_285 > V_4 -> V_215 ) ) {
F_84 ( L_65 ,
V_335 -> V_285 , V_4 -> V_216 , V_4 -> V_215 ) ;
return - V_190 ;
}
V_8 = F_138 ( V_335 ) ;
if ( V_8 )
return V_8 ;
V_44 = V_2 -> V_5 . V_46 -> V_339 ( V_2 , V_193 , V_335 ) ;
if ( F_135 ( V_44 ) ) {
F_84 ( L_55 ) ;
return F_136 ( V_44 ) ;
}
F_4 ( & V_193 -> V_209 ) ;
V_335 -> V_203 = V_44 -> V_50 . V_39 ;
F_38 ( & V_44 -> V_49 , & V_193 -> V_340 ) ;
F_84 ( L_56 , V_44 -> V_50 . V_39 ) ;
F_14 ( & V_193 -> V_209 ) ;
return V_8 ;
}
int F_144 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_43 * V_44 = NULL ;
struct V_43 * V_400 = NULL ;
T_1 * V_39 = V_191 ;
int V_401 = 0 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_4 ( & V_193 -> V_209 ) ;
F_4 ( & V_2 -> V_5 . V_47 ) ;
V_44 = F_41 ( V_2 , * V_39 ) ;
if ( ! V_44 )
goto V_402;
F_15 (fbl, &file_priv->fbs, filp_head)
if ( V_44 == V_400 )
V_401 = 1 ;
if ( ! V_401 )
goto V_402;
F_52 ( V_2 , V_44 ) ;
F_145 ( & V_44 -> V_49 ) ;
F_14 ( & V_2 -> V_5 . V_47 ) ;
F_14 ( & V_193 -> V_209 ) ;
F_56 ( V_44 ) ;
return 0 ;
V_402:
F_14 ( & V_2 -> V_5 . V_47 ) ;
F_14 ( & V_193 -> V_209 ) ;
return - V_228 ;
}
int F_146 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_332 * V_335 = V_191 ;
struct V_43 * V_44 ;
int V_8 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
V_44 = F_43 ( V_2 , V_335 -> V_203 ) ;
if ( ! V_44 )
return - V_228 ;
V_335 -> V_285 = V_44 -> V_285 ;
V_335 -> V_284 = V_44 -> V_284 ;
V_335 -> V_323 = V_44 -> V_323 ;
V_335 -> V_322 = V_44 -> V_403 ;
V_335 -> V_337 = V_44 -> V_336 [ 0 ] ;
if ( V_44 -> V_46 -> V_404 ) {
if ( V_193 -> V_405 || F_147 ( V_406 ) ||
F_148 ( V_193 ) ) {
V_8 = V_44 -> V_46 -> V_404 ( V_44 , V_193 ,
& V_335 -> V_315 ) ;
} else {
V_335 -> V_315 = 0 ;
V_8 = 0 ;
}
} else {
V_8 = - V_407 ;
}
F_44 ( V_44 ) ;
return V_8 ;
}
int F_149 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_408 T_2 * V_409 ;
struct V_408 * V_410 = NULL ;
struct V_411 * V_335 = V_191 ;
struct V_43 * V_44 ;
unsigned V_184 ;
int V_412 ;
int V_8 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
V_44 = F_43 ( V_2 , V_335 -> V_203 ) ;
if ( ! V_44 )
return - V_228 ;
V_412 = V_335 -> V_412 ;
V_409 = (struct V_408 T_2 * ) ( unsigned long ) V_335 -> V_409 ;
if ( ! V_412 != ! V_409 ) {
V_8 = - V_190 ;
goto V_413;
}
V_184 = V_414 & V_335 -> V_184 ;
if ( V_184 & V_415 && ( V_412 % 2 ) ) {
V_8 = - V_190 ;
goto V_413;
}
if ( V_412 && V_409 ) {
if ( V_412 < 0 || V_412 > V_416 ) {
V_8 = - V_190 ;
goto V_413;
}
V_410 = F_2 ( V_412 * sizeof( * V_410 ) , V_9 ) ;
if ( ! V_410 ) {
V_8 = - V_84 ;
goto V_413;
}
V_8 = F_150 ( V_410 , V_409 ,
V_412 * sizeof( * V_410 ) ) ;
if ( V_8 ) {
V_8 = - V_212 ;
goto V_417;
}
}
if ( V_44 -> V_46 -> V_418 ) {
V_8 = V_44 -> V_46 -> V_418 ( V_44 , V_193 , V_184 , V_335 -> V_419 ,
V_410 , V_412 ) ;
} else {
V_8 = - V_420 ;
}
V_417:
F_13 ( V_410 ) ;
V_413:
F_44 ( V_44 ) ;
return V_8 ;
}
void F_151 ( struct V_192 * V_421 )
{
struct V_1 * V_2 = V_421 -> V_214 -> V_2 ;
struct V_43 * V_44 , * V_422 ;
F_4 ( & V_421 -> V_209 ) ;
F_74 (fb, tfb, &priv->fbs, filp_head) {
F_4 ( & V_2 -> V_5 . V_47 ) ;
F_52 ( V_2 , V_44 ) ;
F_14 ( & V_2 -> V_5 . V_47 ) ;
F_145 ( & V_44 -> V_49 ) ;
F_56 ( V_44 ) ;
}
F_14 ( & V_421 -> V_209 ) ;
}
struct V_124 * F_89 ( struct V_1 * V_2 , int V_184 ,
const char * V_29 , int V_423 )
{
struct V_124 * V_424 = NULL ;
int V_8 ;
V_424 = F_2 ( sizeof( struct V_124 ) , V_9 ) ;
if ( ! V_424 )
return NULL ;
V_424 -> V_2 = V_2 ;
if ( V_423 ) {
V_424 -> V_262 = F_2 ( sizeof( T_3 ) * V_423 , V_9 ) ;
if ( ! V_424 -> V_262 )
goto V_13;
}
V_8 = F_27 ( V_2 , & V_424 -> V_50 , V_425 ) ;
if ( V_8 )
goto V_13;
V_424 -> V_184 = V_184 ;
V_424 -> V_423 = V_423 ;
F_36 ( & V_424 -> V_426 ) ;
if ( V_29 ) {
strncpy ( V_424 -> V_29 , V_29 , V_427 ) ;
V_424 -> V_29 [ V_427 - 1 ] = '\0' ;
}
F_63 ( & V_424 -> V_53 , & V_2 -> V_5 . V_428 ) ;
F_3 ( ! F_152 ( V_424 ) ) ;
return V_424 ;
V_13:
F_13 ( V_424 -> V_262 ) ;
F_13 ( V_424 ) ;
return NULL ;
}
struct V_124 * F_90 ( struct V_1 * V_2 , int V_184 ,
const char * V_29 ,
const struct V_429 * V_430 ,
int V_423 )
{
struct V_124 * V_424 ;
int V_19 , V_8 ;
V_184 |= V_149 ;
V_424 = F_89 ( V_2 , V_184 , V_29 , V_423 ) ;
if ( ! V_424 )
return NULL ;
for ( V_19 = 0 ; V_19 < V_423 ; V_19 ++ ) {
V_8 = F_95 ( V_424 , V_19 ,
V_430 [ V_19 ] . type ,
V_430 [ V_19 ] . V_29 ) ;
if ( V_8 ) {
F_153 ( V_2 , V_424 ) ;
return NULL ;
}
}
return V_424 ;
}
struct V_124 * F_154 ( struct V_1 * V_2 ,
int V_184 , const char * V_29 ,
const struct V_429 * V_430 ,
int V_423 )
{
struct V_124 * V_424 ;
int V_19 , V_8 ;
V_184 |= V_431 ;
V_424 = F_89 ( V_2 , V_184 , V_29 , V_423 ) ;
if ( ! V_424 )
return NULL ;
for ( V_19 = 0 ; V_19 < V_423 ; V_19 ++ ) {
V_8 = F_95 ( V_424 , V_19 ,
V_430 [ V_19 ] . type ,
V_430 [ V_19 ] . V_29 ) ;
if ( V_8 ) {
F_153 ( V_2 , V_424 ) ;
return NULL ;
}
}
return V_424 ;
}
static struct V_124 * F_155 ( struct V_1 * V_2 ,
int V_184 , const char * V_29 ,
T_3 V_432 , T_3 V_433 )
{
struct V_124 * V_424 ;
V_424 = F_89 ( V_2 , V_184 , V_29 , 2 ) ;
if ( ! V_424 )
return NULL ;
V_424 -> V_262 [ 0 ] = V_432 ;
V_424 -> V_262 [ 1 ] = V_433 ;
return V_424 ;
}
struct V_124 * F_94 ( struct V_1 * V_2 , int V_184 ,
const char * V_29 ,
T_3 V_432 , T_3 V_433 )
{
return F_155 ( V_2 , V_434 | V_184 ,
V_29 , V_432 , V_433 ) ;
}
struct V_124 * F_156 ( struct V_1 * V_2 ,
int V_184 , const char * V_29 ,
T_5 V_432 , T_5 V_433 )
{
return F_155 ( V_2 , V_435 | V_184 ,
V_29 , F_157 ( V_432 ) , F_157 ( V_433 ) ) ;
}
struct V_124 * F_158 ( struct V_1 * V_2 ,
int V_184 , const char * V_29 , T_1 type )
{
struct V_124 * V_424 ;
V_184 |= V_436 ;
V_424 = F_89 ( V_2 , V_184 , V_29 , 1 ) ;
if ( ! V_424 )
return NULL ;
V_424 -> V_262 [ 0 ] = type ;
return V_424 ;
}
int F_95 ( struct V_124 * V_424 , int V_71 ,
T_3 V_437 , const char * V_29 )
{
struct V_438 * V_439 ;
if ( ! ( F_159 ( V_424 , V_149 ) ||
F_159 ( V_424 , V_431 ) ) )
return - V_190 ;
if ( F_159 ( V_424 , V_431 ) &&
( V_437 > 63 ) )
return - V_190 ;
if ( ! F_57 ( & V_424 -> V_426 ) ) {
F_15 (prop_enum, &property->enum_blob_list, head) {
if ( V_439 -> V_437 == V_437 ) {
strncpy ( V_439 -> V_29 , V_29 , V_427 ) ;
V_439 -> V_29 [ V_427 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_439 = F_2 ( sizeof( struct V_438 ) , V_9 ) ;
if ( ! V_439 )
return - V_84 ;
strncpy ( V_439 -> V_29 , V_29 , V_427 ) ;
V_439 -> V_29 [ V_427 - 1 ] = '\0' ;
V_439 -> V_437 = V_437 ;
V_424 -> V_262 [ V_71 ] = V_437 ;
F_63 ( & V_439 -> V_53 , & V_424 -> V_426 ) ;
return 0 ;
}
void F_153 ( struct V_1 * V_2 , struct V_124 * V_424 )
{
struct V_438 * V_439 , * V_440 ;
F_74 (prop_enum, pt, &property->enum_blob_list, head) {
F_55 ( & V_439 -> V_53 ) ;
F_13 ( V_439 ) ;
}
if ( V_424 -> V_423 )
F_13 ( V_424 -> V_262 ) ;
F_29 ( V_2 , & V_424 -> V_50 ) ;
F_55 ( & V_424 -> V_53 ) ;
F_13 ( V_424 ) ;
}
void F_72 ( struct V_34 * V_35 ,
struct V_124 * V_424 ,
T_3 V_441 )
{
int V_245 = V_35 -> V_66 -> V_245 ;
if ( V_245 == V_442 ) {
F_102 ( 1 , L_66
L_67
L_68 ,
V_35 -> type ) ;
return;
}
V_35 -> V_66 -> V_261 [ V_245 ] = V_424 -> V_50 . V_39 ;
V_35 -> V_66 -> V_262 [ V_245 ] = V_441 ;
V_35 -> V_66 -> V_245 ++ ;
}
int F_160 ( struct V_34 * V_35 ,
struct V_124 * V_424 , T_3 V_443 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_35 -> V_66 -> V_245 ; V_19 ++ ) {
if ( V_35 -> V_66 -> V_261 [ V_19 ] == V_424 -> V_50 . V_39 ) {
V_35 -> V_66 -> V_262 [ V_19 ] = V_443 ;
return 0 ;
}
}
return - V_190 ;
}
int F_161 ( struct V_34 * V_35 ,
struct V_124 * V_424 , T_3 * V_443 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_35 -> V_66 -> V_245 ; V_19 ++ ) {
if ( V_35 -> V_66 -> V_261 [ V_19 ] == V_424 -> V_50 . V_39 ) {
* V_443 = V_35 -> V_66 -> V_262 [ V_19 ] ;
return 0 ;
}
}
return - V_190 ;
}
int F_162 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_444 * V_236 = V_191 ;
struct V_124 * V_424 ;
int V_445 = 0 ;
int V_446 = 0 ;
int V_447 = 0 ;
int V_8 = 0 , V_19 ;
int V_202 ;
struct V_438 * V_439 ;
struct V_448 T_2 * V_449 ;
struct V_450 * V_451 ;
T_1 T_2 * V_452 ;
T_3 T_2 * V_453 ;
T_1 T_2 * V_454 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_424 = F_163 ( V_2 , V_236 -> V_455 ) ;
if ( ! V_424 ) {
V_8 = - V_228 ;
goto V_456;
}
if ( F_159 ( V_424 , V_149 ) ||
F_159 ( V_424 , V_431 ) ) {
F_15 (prop_enum, &property->enum_blob_list, head)
V_445 ++ ;
} else if ( F_159 ( V_424 , V_127 ) ) {
F_15 (prop_blob, &property->enum_blob_list, head)
V_446 ++ ;
}
V_447 = V_424 -> V_423 ;
strncpy ( V_236 -> V_29 , V_424 -> V_29 , V_427 ) ;
V_236 -> V_29 [ V_427 - 1 ] = 0 ;
V_236 -> V_184 = V_424 -> V_184 ;
if ( ( V_236 -> V_457 >= V_447 ) && V_447 ) {
V_453 = ( T_3 T_2 * ) ( unsigned long ) V_236 -> V_453 ;
for ( V_19 = 0 ; V_19 < V_447 ; V_19 ++ ) {
if ( F_116 ( V_453 + V_19 , & V_424 -> V_262 [ V_19 ] , sizeof( T_3 ) ) ) {
V_8 = - V_212 ;
goto V_456;
}
}
}
V_236 -> V_457 = V_447 ;
if ( F_159 ( V_424 , V_149 ) ||
F_159 ( V_424 , V_431 ) ) {
if ( ( V_236 -> V_458 >= V_445 ) && V_445 ) {
V_202 = 0 ;
V_449 = (struct V_448 T_2 * ) ( unsigned long ) V_236 -> V_459 ;
F_15 (prop_enum, &property->enum_blob_list, head) {
if ( F_116 ( & V_449 [ V_202 ] . V_437 , & V_439 -> V_437 , sizeof( T_3 ) ) ) {
V_8 = - V_212 ;
goto V_456;
}
if ( F_116 ( & V_449 [ V_202 ] . V_29 ,
& V_439 -> V_29 , V_427 ) ) {
V_8 = - V_212 ;
goto V_456;
}
V_202 ++ ;
}
}
V_236 -> V_458 = V_445 ;
}
if ( F_159 ( V_424 , V_127 ) ) {
if ( ( V_236 -> V_458 >= V_446 ) && V_446 ) {
V_202 = 0 ;
V_452 = ( T_1 T_2 * ) ( unsigned long ) V_236 -> V_459 ;
V_454 = ( T_1 T_2 * ) ( unsigned long ) V_236 -> V_453 ;
F_15 (prop_blob, &property->enum_blob_list, head) {
if ( F_107 ( V_451 -> V_50 . V_39 , V_452 + V_202 ) ) {
V_8 = - V_212 ;
goto V_456;
}
if ( F_107 ( V_451 -> V_460 , V_454 + V_202 ) ) {
V_8 = - V_212 ;
goto V_456;
}
V_202 ++ ;
}
}
V_236 -> V_458 = V_446 ;
}
V_456:
F_10 ( V_2 ) ;
return V_8 ;
}
static struct V_450 * F_164 ( struct V_1 * V_2 , int V_460 ,
void * V_191 )
{
struct V_450 * V_461 ;
int V_8 ;
if ( ! V_460 || ! V_191 )
return NULL ;
V_461 = F_2 ( sizeof( struct V_450 ) + V_460 , V_9 ) ;
if ( ! V_461 )
return NULL ;
V_8 = F_27 ( V_2 , & V_461 -> V_50 , V_462 ) ;
if ( V_8 ) {
F_13 ( V_461 ) ;
return NULL ;
}
V_461 -> V_460 = V_460 ;
memcpy ( V_461 -> V_191 , V_191 , V_460 ) ;
F_63 ( & V_461 -> V_53 , & V_2 -> V_5 . V_463 ) ;
return V_461 ;
}
static void F_165 ( struct V_1 * V_2 ,
struct V_450 * V_461 )
{
F_29 ( V_2 , & V_461 -> V_50 ) ;
F_55 ( & V_461 -> V_53 ) ;
F_13 ( V_461 ) ;
}
int F_166 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_464 * V_236 = V_191 ;
struct V_450 * V_461 ;
int V_8 = 0 ;
void T_2 * V_465 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_461 = F_167 ( V_2 , V_236 -> V_466 ) ;
if ( ! V_461 ) {
V_8 = - V_228 ;
goto V_456;
}
if ( V_236 -> V_460 == V_461 -> V_460 ) {
V_465 = ( void T_2 * ) ( unsigned long ) V_236 -> V_191 ;
if ( F_116 ( V_465 , V_461 -> V_191 , V_461 -> V_460 ) ) {
V_8 = - V_212 ;
goto V_456;
}
}
V_236 -> V_460 = V_461 -> V_460 ;
V_456:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_168 ( struct V_73 * V_74 ,
struct V_125 * V_125 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
int V_8 , V_467 ;
if ( V_74 -> V_87 )
F_165 ( V_2 , V_74 -> V_87 ) ;
if ( ! V_125 ) {
V_74 -> V_87 = NULL ;
V_8 = F_160 ( & V_74 -> V_50 , V_2 -> V_5 . V_92 , 0 ) ;
return V_8 ;
}
V_467 = V_468 * ( 1 + V_125 -> V_469 ) ;
V_74 -> V_87 = F_164 ( V_74 -> V_2 ,
V_467 , V_125 ) ;
if ( ! V_74 -> V_87 )
return - V_190 ;
V_8 = F_160 ( & V_74 -> V_50 ,
V_2 -> V_5 . V_92 ,
V_74 -> V_87 -> V_50 . V_39 ) ;
return V_8 ;
}
static bool F_169 ( struct V_124 * V_424 ,
T_3 V_437 )
{
if ( V_424 -> V_184 & V_128 )
return false ;
if ( F_159 ( V_424 , V_434 ) ) {
if ( V_437 < V_424 -> V_262 [ 0 ] || V_437 > V_424 -> V_262 [ 1 ] )
return false ;
return true ;
} else if ( F_159 ( V_424 , V_435 ) ) {
T_5 V_470 = F_170 ( V_437 ) ;
if ( V_470 < F_170 ( V_424 -> V_262 [ 0 ] ) ||
V_470 > F_170 ( V_424 -> V_262 [ 1 ] ) )
return false ;
return true ;
} else if ( F_159 ( V_424 , V_431 ) ) {
int V_19 ;
T_3 V_471 = 0 ;
for ( V_19 = 0 ; V_19 < V_424 -> V_423 ; V_19 ++ )
V_471 |= ( 1ULL << V_424 -> V_262 [ V_19 ] ) ;
return ! ( V_437 & ~ V_471 ) ;
} else if ( F_159 ( V_424 , V_127 ) ) {
return true ;
} else if ( F_159 ( V_424 , V_436 ) ) {
struct V_34 * V_35 ;
if ( V_437 == 0 )
return true ;
V_35 = F_31 ( V_424 -> V_2 , V_437 , V_424 -> V_262 [ 0 ] ) ;
return V_35 != NULL ;
} else {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_424 -> V_423 ; V_19 ++ )
if ( V_424 -> V_262 [ V_19 ] == V_437 )
return true ;
return false ;
}
}
int F_171 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_472 * V_473 = V_191 ;
struct V_474 V_475 = {
. V_437 = V_473 -> V_437 ,
. V_455 = V_473 -> V_455 ,
. V_476 = V_473 -> V_205 ,
. V_36 = V_80
} ;
return F_172 ( V_2 , & V_475 , V_193 ) ;
}
static int F_173 ( struct V_34 * V_35 ,
struct V_124 * V_424 ,
T_3 V_437 )
{
int V_8 = - V_190 ;
struct V_73 * V_74 = F_174 ( V_35 ) ;
if ( V_424 == V_74 -> V_2 -> V_5 . V_93 ) {
if ( V_74 -> V_46 -> V_126 )
(* V_74 -> V_46 -> V_126 )( V_74 , ( int ) V_437 ) ;
V_8 = 0 ;
} else if ( V_74 -> V_46 -> V_477 )
V_8 = V_74 -> V_46 -> V_477 ( V_74 , V_424 , V_437 ) ;
if ( ! V_8 )
F_160 ( & V_74 -> V_50 , V_424 , V_437 ) ;
return V_8 ;
}
static int F_175 ( struct V_34 * V_35 ,
struct V_124 * V_424 ,
T_3 V_437 )
{
int V_8 = - V_190 ;
struct V_16 * V_17 = F_176 ( V_35 ) ;
if ( V_17 -> V_46 -> V_477 )
V_8 = V_17 -> V_46 -> V_477 ( V_17 , V_424 , V_437 ) ;
if ( ! V_8 )
F_160 ( V_35 , V_424 , V_437 ) ;
return V_8 ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_124 * V_424 ,
T_3 V_437 )
{
int V_8 = - V_190 ;
struct V_57 * V_58 = F_178 ( V_35 ) ;
if ( V_58 -> V_46 -> V_477 )
V_8 = V_58 -> V_46 -> V_477 ( V_58 , V_424 , V_437 ) ;
if ( ! V_8 )
F_160 ( V_35 , V_424 , V_437 ) ;
return V_8 ;
}
int F_179 ( struct V_1 * V_2 , void * V_191 ,
struct V_192 * V_193 )
{
struct V_478 * V_479 = V_191 ;
struct V_34 * V_35 ;
int V_8 = 0 ;
int V_19 ;
int V_202 = 0 ;
int V_238 = 0 ;
T_1 T_2 * V_259 ;
T_3 T_2 * V_260 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_35 = F_33 ( V_2 , V_479 -> V_476 , V_479 -> V_36 ) ;
if ( ! V_35 ) {
V_8 = - V_228 ;
goto V_51;
}
if ( ! V_35 -> V_66 ) {
V_8 = - V_190 ;
goto V_51;
}
V_238 = V_35 -> V_66 -> V_245 ;
if ( ( V_479 -> V_258 >= V_238 ) && V_238 ) {
V_202 = 0 ;
V_259 = ( T_1 T_2 * ) ( unsigned long ) ( V_479 -> V_259 ) ;
V_260 = ( T_3 T_2 * ) ( unsigned long )
( V_479 -> V_260 ) ;
for ( V_19 = 0 ; V_19 < V_238 ; V_19 ++ ) {
if ( F_107 ( V_35 -> V_66 -> V_261 [ V_19 ] ,
V_259 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
if ( F_107 ( V_35 -> V_66 -> V_262 [ V_19 ] ,
V_260 + V_202 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_202 ++ ;
}
}
V_479 -> V_258 = V_238 ;
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_172 ( struct V_1 * V_2 , void * V_191 ,
struct V_192 * V_193 )
{
struct V_474 * V_479 = V_191 ;
struct V_34 * V_480 ;
struct V_34 * V_481 ;
struct V_124 * V_424 ;
int V_8 = - V_190 ;
int V_19 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_480 = F_33 ( V_2 , V_479 -> V_476 , V_479 -> V_36 ) ;
if ( ! V_480 ) {
V_8 = - V_228 ;
goto V_51;
}
if ( ! V_480 -> V_66 )
goto V_51;
for ( V_19 = 0 ; V_19 < V_480 -> V_66 -> V_245 ; V_19 ++ )
if ( V_480 -> V_66 -> V_261 [ V_19 ] == V_479 -> V_455 )
break;
if ( V_19 == V_480 -> V_66 -> V_245 )
goto V_51;
V_481 = F_33 ( V_2 , V_479 -> V_455 ,
V_425 ) ;
if ( ! V_481 ) {
V_8 = - V_228 ;
goto V_51;
}
V_424 = F_180 ( V_481 ) ;
if ( ! F_169 ( V_424 , V_479 -> V_437 ) )
goto V_51;
switch ( V_480 -> type ) {
case V_80 :
V_8 = F_173 ( V_480 , V_424 ,
V_479 -> V_437 ) ;
break;
case V_65 :
V_8 = F_175 ( V_480 , V_424 , V_479 -> V_437 ) ;
break;
case V_113 :
V_8 = F_177 ( V_480 , V_424 , V_479 -> V_437 ) ;
break;
}
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_181 ( struct V_73 * V_74 ,
struct V_101 * V_102 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_246 ; V_19 ++ ) {
if ( V_74 -> V_247 [ V_19 ] == 0 ) {
V_74 -> V_247 [ V_19 ] = V_102 -> V_50 . V_39 ;
return 0 ;
}
}
return - V_84 ;
}
int F_182 ( struct V_16 * V_17 ,
int V_231 )
{
V_17 -> V_231 = V_231 ;
V_17 -> V_70 = F_2 ( V_231 * sizeof( V_482 ) * 3 , V_9 ) ;
if ( ! V_17 -> V_70 ) {
V_17 -> V_231 = 0 ;
return - V_84 ;
}
return 0 ;
}
int F_183 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_483 * V_484 = V_191 ;
struct V_16 * V_17 ;
void * V_485 , * V_486 , * V_487 ;
int V_467 ;
int V_8 = 0 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_17 = F_110 ( V_2 , V_484 -> V_204 ) ;
if ( ! V_17 ) {
V_8 = - V_228 ;
goto V_51;
}
if ( V_17 -> V_46 -> V_488 == NULL ) {
V_8 = - V_420 ;
goto V_51;
}
if ( V_484 -> V_231 != V_17 -> V_231 ) {
V_8 = - V_190 ;
goto V_51;
}
V_467 = V_484 -> V_231 * ( sizeof( V_482 ) ) ;
V_485 = V_17 -> V_70 ;
if ( F_150 ( V_485 , ( void T_2 * ) ( unsigned long ) V_484 -> V_489 , V_467 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_486 = V_485 + V_467 ;
if ( F_150 ( V_486 , ( void T_2 * ) ( unsigned long ) V_484 -> V_490 , V_467 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_487 = V_486 + V_467 ;
if ( F_150 ( V_487 , ( void T_2 * ) ( unsigned long ) V_484 -> V_491 , V_467 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_17 -> V_46 -> V_488 ( V_17 , V_485 , V_486 , V_487 , 0 , V_17 -> V_231 ) ;
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_184 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_483 * V_484 = V_191 ;
struct V_16 * V_17 ;
void * V_485 , * V_486 , * V_487 ;
int V_467 ;
int V_8 = 0 ;
if ( ! F_105 ( V_2 , V_208 ) )
return - V_190 ;
F_1 ( V_2 ) ;
V_17 = F_110 ( V_2 , V_484 -> V_204 ) ;
if ( ! V_17 ) {
V_8 = - V_228 ;
goto V_51;
}
if ( V_484 -> V_231 != V_17 -> V_231 ) {
V_8 = - V_190 ;
goto V_51;
}
V_467 = V_484 -> V_231 * ( sizeof( V_482 ) ) ;
V_485 = V_17 -> V_70 ;
if ( F_116 ( ( void T_2 * ) ( unsigned long ) V_484 -> V_489 , V_485 , V_467 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_486 = V_485 + V_467 ;
if ( F_116 ( ( void T_2 * ) ( unsigned long ) V_484 -> V_490 , V_486 , V_467 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_487 = V_486 + V_467 ;
if ( F_116 ( ( void T_2 * ) ( unsigned long ) V_484 -> V_491 , V_487 , V_467 ) ) {
V_8 = - V_212 ;
goto V_51;
}
V_51:
F_10 ( V_2 ) ;
return V_8 ;
}
int F_185 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_492 * V_493 = V_191 ;
struct V_16 * V_17 ;
struct V_43 * V_44 = NULL , * V_122 = NULL ;
struct V_494 * V_495 = NULL ;
unsigned long V_184 ;
int V_8 = - V_190 ;
if ( V_493 -> V_184 & ~ V_496 ||
V_493 -> V_497 != 0 )
return - V_190 ;
if ( ( V_493 -> V_184 & V_498 ) && ! V_2 -> V_5 . V_499 )
return - V_190 ;
V_17 = F_110 ( V_2 , V_493 -> V_204 ) ;
if ( ! V_17 )
return - V_228 ;
F_6 ( & V_17 -> V_10 , NULL ) ;
if ( V_17 -> V_61 -> V_44 == NULL ) {
V_8 = - V_500 ;
goto V_51;
}
if ( V_17 -> V_46 -> V_493 == NULL )
goto V_51;
V_44 = F_43 ( V_2 , V_493 -> V_203 ) ;
if ( ! V_44 ) {
V_8 = - V_228 ;
goto V_51;
}
V_8 = F_124 ( V_17 , V_17 -> V_229 , V_17 -> V_230 , & V_17 -> V_76 , V_44 ) ;
if ( V_8 )
goto V_51;
if ( V_17 -> V_61 -> V_44 -> V_283 != V_44 -> V_283 ) {
F_84 ( L_69 ) ;
V_8 = - V_190 ;
goto V_51;
}
if ( V_493 -> V_184 & V_501 ) {
V_8 = - V_84 ;
F_186 ( & V_2 -> V_502 , V_184 ) ;
if ( V_193 -> V_503 < sizeof V_495 -> V_504 ) {
F_187 ( & V_2 -> V_502 , V_184 ) ;
goto V_51;
}
V_193 -> V_503 -= sizeof V_495 -> V_504 ;
F_187 ( & V_2 -> V_502 , V_184 ) ;
V_495 = F_2 ( sizeof *V_495 , V_9 ) ;
if ( V_495 == NULL ) {
F_186 ( & V_2 -> V_502 , V_184 ) ;
V_193 -> V_503 += sizeof V_495 -> V_504 ;
F_187 ( & V_2 -> V_502 , V_184 ) ;
goto V_51;
}
V_495 -> V_504 . V_50 . type = V_505 ;
V_495 -> V_504 . V_50 . V_460 = sizeof V_495 -> V_504 ;
V_495 -> V_504 . V_506 = V_493 -> V_506 ;
V_495 -> V_50 . V_504 = & V_495 -> V_504 . V_50 ;
V_495 -> V_50 . V_193 = V_193 ;
V_495 -> V_50 . V_56 =
( void ( * ) ( struct V_507 * ) ) F_13 ;
}
V_122 = V_17 -> V_61 -> V_44 ;
V_8 = V_17 -> V_46 -> V_493 ( V_17 , V_44 , V_495 , V_493 -> V_184 ) ;
if ( V_8 ) {
if ( V_493 -> V_184 & V_501 ) {
F_186 ( & V_2 -> V_502 , V_184 ) ;
V_193 -> V_503 += sizeof V_495 -> V_504 ;
F_187 ( & V_2 -> V_502 , V_184 ) ;
F_13 ( V_495 ) ;
}
V_122 = NULL ;
} else {
F_3 ( V_17 -> V_61 -> V_44 != V_44 ) ;
V_44 = NULL ;
}
V_51:
if ( V_44 )
F_44 ( V_44 ) ;
if ( V_122 )
F_44 ( V_122 ) ;
F_115 ( & V_17 -> V_10 ) ;
return V_8 ;
}
void F_188 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_101 * V_102 ;
struct V_73 * V_74 ;
F_15 (crtc, &dev->mode_config.crtc_list, head)
if ( V_17 -> V_46 -> V_508 )
V_17 -> V_46 -> V_508 ( V_17 ) ;
F_15 (encoder, &dev->mode_config.encoder_list, head)
if ( V_102 -> V_46 -> V_508 )
V_102 -> V_46 -> V_508 ( V_102 ) ;
F_15 (connector, &dev->mode_config.connector_list, head) {
V_74 -> V_23 = V_88 ;
if ( V_74 -> V_46 -> V_508 )
V_74 -> V_46 -> V_508 ( V_74 ) ;
}
}
int F_189 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_509 * args = V_191 ;
T_4 V_396 , V_510 , V_467 ;
if ( ! V_2 -> V_511 -> V_512 )
return - V_420 ;
if ( ! args -> V_284 || ! args -> V_285 || ! args -> V_322 )
return - V_190 ;
V_396 = F_190 ( args -> V_322 , 8 ) ;
if ( V_396 > 0xffffffffU / args -> V_284 )
return - V_190 ;
V_510 = V_396 * args -> V_284 ;
if ( args -> V_285 > 0xffffffffU / V_510 )
return - V_190 ;
V_467 = args -> V_285 * V_510 ;
if ( F_191 ( V_467 ) == 0 )
return - V_190 ;
return V_2 -> V_511 -> V_512 ( V_193 , V_2 , args ) ;
}
int F_192 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_513 * args = V_191 ;
if ( ! V_2 -> V_511 -> V_514 )
return - V_420 ;
return V_2 -> V_511 -> V_514 ( V_193 , V_2 , args -> V_315 , & args -> V_515 ) ;
}
int F_193 ( struct V_1 * V_2 ,
void * V_191 , struct V_192 * V_193 )
{
struct V_516 * args = V_191 ;
if ( ! V_2 -> V_511 -> V_517 )
return - V_420 ;
return V_2 -> V_511 -> V_517 ( V_193 , V_2 , args -> V_315 ) ;
}
void F_194 ( T_1 V_31 , unsigned int * V_323 ,
int * V_322 )
{
switch ( V_31 ) {
case V_325 :
case V_341 :
case V_342 :
* V_323 = 8 ;
* V_322 = 8 ;
break;
case V_326 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
* V_323 = 15 ;
* V_322 = 16 ;
break;
case V_327 :
case V_358 :
* V_323 = 16 ;
* V_322 = 16 ;
break;
case V_328 :
case V_359 :
* V_323 = 24 ;
* V_322 = 24 ;
break;
case V_329 :
case V_360 :
case V_361 :
case V_362 :
* V_323 = 24 ;
* V_322 = 32 ;
break;
case V_330 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
* V_323 = 30 ;
* V_322 = 32 ;
break;
case V_331 :
case V_363 :
case V_364 :
case V_365 :
* V_323 = 32 ;
* V_322 = 32 ;
break;
default:
F_84 ( L_70 ,
F_26 ( V_31 ) ) ;
* V_323 = 0 ;
* V_322 = 0 ;
break;
}
}
int F_141 ( T_1 V_31 )
{
switch ( V_31 ) {
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
return 3 ;
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
return 2 ;
default:
return 1 ;
}
}
int F_142 ( T_1 V_31 , int V_58 )
{
unsigned int V_323 ;
int V_322 ;
if ( V_58 >= F_141 ( V_31 ) )
return 0 ;
switch ( V_31 ) {
case V_373 :
case V_374 :
case V_375 :
case V_376 :
return 2 ;
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
return V_58 ? 2 : 1 ;
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
return 1 ;
default:
F_194 ( V_31 , & V_323 , & V_322 ) ;
return V_322 >> 3 ;
}
}
int F_139 ( T_1 V_31 )
{
switch ( V_31 ) {
case V_386 :
case V_387 :
case V_384 :
case V_385 :
return 4 ;
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_390 :
case V_391 :
case V_388 :
case V_389 :
return 2 ;
default:
return 1 ;
}
}
int F_140 ( T_1 V_31 )
{
switch ( V_31 ) {
case V_384 :
case V_385 :
return 4 ;
case V_388 :
case V_389 :
case V_378 :
case V_379 :
return 2 ;
default:
return 1 ;
}
}
void F_195 ( struct V_1 * V_2 )
{
F_196 ( & V_2 -> V_5 . V_10 ) ;
F_62 ( & V_2 -> V_5 . V_12 ) ;
F_196 ( & V_2 -> V_5 . V_37 ) ;
F_196 ( & V_2 -> V_5 . V_47 ) ;
F_36 ( & V_2 -> V_5 . V_54 ) ;
F_36 ( & V_2 -> V_5 . V_67 ) ;
F_36 ( & V_2 -> V_5 . V_89 ) ;
F_36 ( & V_2 -> V_5 . V_99 ) ;
F_36 ( & V_2 -> V_5 . V_107 ) ;
F_36 ( & V_2 -> V_5 . V_428 ) ;
F_36 ( & V_2 -> V_5 . V_463 ) ;
F_36 ( & V_2 -> V_5 . V_115 ) ;
F_197 ( & V_2 -> V_5 . V_38 ) ;
F_1 ( V_2 ) ;
F_88 ( V_2 ) ;
F_91 ( V_2 ) ;
F_10 ( V_2 ) ;
V_2 -> V_5 . V_52 = 0 ;
V_2 -> V_5 . V_90 = 0 ;
V_2 -> V_5 . V_68 = 0 ;
V_2 -> V_5 . V_108 = 0 ;
V_2 -> V_5 . V_118 = 0 ;
V_2 -> V_5 . V_116 = 0 ;
}
void F_198 ( struct V_1 * V_2 )
{
struct V_73 * V_74 , * V_518 ;
struct V_16 * V_17 , * V_519 ;
struct V_101 * V_102 , * V_520 ;
struct V_95 * V_96 , * V_521 ;
struct V_43 * V_44 , * V_522 ;
struct V_124 * V_424 , * V_440 ;
struct V_450 * V_461 , * V_523 ;
struct V_57 * V_58 , * V_524 ;
F_74 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_102 -> V_46 -> V_56 ( V_102 ) ;
}
F_74 (bridge, brt,
&dev->mode_config.bridge_list, head) {
V_96 -> V_46 -> V_56 ( V_96 ) ;
}
F_74 (connector, ot,
&dev->mode_config.connector_list, head) {
V_74 -> V_46 -> V_56 ( V_74 ) ;
}
F_74 (property, pt, &dev->mode_config.property_list,
head) {
F_153 ( V_2 , V_424 ) ;
}
F_74 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_165 ( V_2 , V_461 ) ;
}
F_3 ( ! F_57 ( & V_2 -> V_5 . V_54 ) ) ;
F_74 (fb, fbt, &dev->mode_config.fb_list, head) {
F_56 ( V_44 ) ;
}
F_74 (plane, plt, &dev->mode_config.plane_list,
head) {
V_58 -> V_46 -> V_56 ( V_58 ) ;
}
F_74 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_17 -> V_46 -> V_56 ( V_17 ) ;
}
F_199 ( & V_2 -> V_5 . V_38 ) ;
F_66 ( & V_2 -> V_5 . V_12 ) ;
}
