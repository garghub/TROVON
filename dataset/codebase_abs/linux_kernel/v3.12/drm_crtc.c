void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
F_4 ( & V_4 -> V_6 , & V_2 -> V_5 . V_6 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
F_6 ( & V_4 -> V_6 ) ;
F_6 ( & V_2 -> V_5 . V_6 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_7 )
return;
F_3 (crtc, &dev->mode_config.crtc_list, head)
F_8 ( ! F_9 ( & V_4 -> V_6 ) ) ;
F_8 ( ! F_9 ( & V_2 -> V_5 . V_6 ) ) ;
}
void F_10 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_11 ( V_9 ) ; V_8 ++ )
F_12 ( & V_9 [ V_8 ] . V_10 ) ;
}
void F_13 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_11 ( V_9 ) ; V_8 ++ )
F_14 ( & V_9 [ V_8 ] . V_10 ) ;
}
const char * F_15 ( const struct V_11 * V_12 )
{
static char V_13 [ 32 ] ;
snprintf ( V_13 , 32 , L_1 ,
V_14 [ V_12 -> V_15 ] . V_16 ,
V_12 -> V_17 . V_18 ) ;
return V_13 ;
}
const char * F_16 ( const struct V_19 * V_20 )
{
static char V_13 [ 32 ] ;
snprintf ( V_13 , 32 , L_1 ,
V_9 [ V_20 -> V_21 ] . V_16 ,
V_20 -> V_22 ) ;
return V_13 ;
}
const char * F_17 ( enum V_23 V_24 )
{
if ( V_24 == V_25 )
return L_2 ;
else if ( V_24 == V_26 )
return L_3 ;
else
return L_4 ;
}
static char F_18 ( int V_27 )
{
return isascii ( V_27 ) && isprint ( V_27 ) ? V_27 : '?' ;
}
const char * F_19 ( T_1 V_28 )
{
static char V_13 [ 32 ] ;
snprintf ( V_13 , sizeof( V_13 ) ,
L_5 ,
F_18 ( V_28 & 0xff ) ,
F_18 ( ( V_28 >> 8 ) & 0xff ) ,
F_18 ( ( V_28 >> 16 ) & 0xff ) ,
F_18 ( ( V_28 >> 24 ) & 0x7f ) ,
V_28 & V_29 ? L_6 : L_7 ,
V_28 ) ;
return V_13 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_30 * V_31 , T_1 V_32 )
{
int V_33 ;
F_2 ( & V_2 -> V_5 . V_34 ) ;
V_33 = F_21 ( & V_2 -> V_5 . V_35 , V_31 , 1 , 0 , V_36 ) ;
if ( V_33 >= 0 ) {
V_31 -> V_18 = V_33 ;
V_31 -> type = V_32 ;
}
F_6 ( & V_2 -> V_5 . V_34 ) ;
return V_33 < 0 ? V_33 : 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_30 * V_37 )
{
F_2 ( & V_2 -> V_5 . V_34 ) ;
F_23 ( & V_2 -> V_5 . V_35 , V_37 -> V_18 ) ;
F_6 ( & V_2 -> V_5 . V_34 ) ;
}
struct V_30 * F_24 ( struct V_1 * V_2 ,
T_1 V_18 , T_1 type )
{
struct V_30 * V_31 = NULL ;
F_8 ( type == V_38 ) ;
F_2 ( & V_2 -> V_5 . V_34 ) ;
V_31 = F_25 ( & V_2 -> V_5 . V_35 , V_18 ) ;
if ( ! V_31 || ( V_31 -> type != type ) || ( V_31 -> V_18 != V_18 ) )
V_31 = NULL ;
F_6 ( & V_2 -> V_5 . V_34 ) ;
return V_31 ;
}
int F_26 ( struct V_1 * V_2 , struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
int V_33 ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
F_27 ( & V_40 -> V_44 ) ;
F_28 ( & V_40 -> V_45 ) ;
V_40 -> V_2 = V_2 ;
V_40 -> V_42 = V_42 ;
V_33 = F_20 ( V_2 , & V_40 -> V_17 , V_38 ) ;
if ( V_33 )
goto V_46;
F_29 ( V_40 ) ;
V_2 -> V_5 . V_47 ++ ;
F_30 ( & V_40 -> V_48 , & V_2 -> V_5 . V_49 ) ;
V_46:
F_6 ( & V_2 -> V_5 . V_43 ) ;
return 0 ;
}
static void F_31 ( struct V_50 * V_50 )
{
struct V_39 * V_40 =
F_32 ( V_50 , struct V_39 , V_44 ) ;
V_40 -> V_42 -> V_51 ( V_40 ) ;
}
static struct V_39 * F_33 ( struct V_1 * V_2 ,
T_1 V_18 )
{
struct V_30 * V_31 = NULL ;
struct V_39 * V_40 ;
F_2 ( & V_2 -> V_5 . V_34 ) ;
V_31 = F_25 ( & V_2 -> V_5 . V_35 , V_18 ) ;
if ( ! V_31 || ( V_31 -> type != V_38 ) || ( V_31 -> V_18 != V_18 ) )
V_40 = NULL ;
else
V_40 = F_34 ( V_31 ) ;
F_6 ( & V_2 -> V_5 . V_34 ) ;
return V_40 ;
}
struct V_39 * F_35 ( struct V_1 * V_2 ,
T_1 V_18 )
{
struct V_39 * V_40 ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
V_40 = F_33 ( V_2 , V_18 ) ;
if ( V_40 )
F_29 ( V_40 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
return V_40 ;
}
void F_36 ( struct V_39 * V_40 )
{
F_37 ( L_8 , V_40 -> V_17 . V_18 ) ;
F_38 ( & V_40 -> V_44 , F_31 ) ;
}
void F_29 ( struct V_39 * V_40 )
{
F_37 ( L_8 , V_40 -> V_17 . V_18 ) ;
F_39 ( & V_40 -> V_44 ) ;
}
static void F_40 ( struct V_50 * V_50 )
{
F_41 () ;
}
static void F_42 ( struct V_39 * V_40 )
{
F_37 ( L_8 , V_40 -> V_17 . V_18 ) ;
F_38 ( & V_40 -> V_44 , F_40 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
F_2 ( & V_2 -> V_5 . V_34 ) ;
F_23 ( & V_2 -> V_5 . V_35 , V_40 -> V_17 . V_18 ) ;
F_6 ( & V_2 -> V_5 . V_34 ) ;
V_40 -> V_17 . V_18 = 0 ;
F_42 ( V_40 ) ;
}
void F_44 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
F_43 ( V_2 , V_40 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
}
void F_45 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
F_46 ( & V_40 -> V_48 ) ;
V_2 -> V_5 . V_47 -- ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
}
void F_47 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_3 * V_4 ;
struct V_52 * V_53 ;
struct V_54 V_55 ;
int V_33 ;
F_8 ( ! F_48 ( & V_40 -> V_45 ) ) ;
if ( F_49 ( & V_40 -> V_44 . V_44 ) > 1 ) {
F_1 ( V_2 ) ;
F_3 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_4 -> V_40 == V_40 ) {
memset ( & V_55 , 0 , sizeof( struct V_54 ) ) ;
V_55 . V_4 = V_4 ;
V_55 . V_40 = NULL ;
V_33 = F_50 ( & V_55 ) ;
if ( V_33 )
F_51 ( L_9 , V_4 ) ;
}
}
F_3 (plane, &dev->mode_config.plane_list, head) {
if ( V_53 -> V_40 == V_40 )
F_52 ( V_53 ) ;
}
F_5 ( V_2 ) ;
}
F_36 ( V_40 ) ;
}
int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_56 * V_42 )
{
int V_33 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_42 = V_42 ;
V_4 -> V_57 = false ;
F_1 ( V_2 ) ;
F_54 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_6 , & V_2 -> V_5 . V_6 ) ;
V_33 = F_20 ( V_2 , & V_4 -> V_17 , V_58 ) ;
if ( V_33 )
goto V_46;
V_4 -> V_17 . V_59 = & V_4 -> V_59 ;
F_55 ( & V_4 -> V_48 , & V_2 -> V_5 . V_60 ) ;
V_2 -> V_5 . V_61 ++ ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_56 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_57 ( V_4 -> V_62 ) ;
V_4 -> V_62 = NULL ;
F_22 ( V_2 , & V_4 -> V_17 ) ;
F_46 ( & V_4 -> V_48 ) ;
V_2 -> V_5 . V_61 -- ;
}
void F_58 ( struct V_19 * V_20 ,
struct V_63 * V_64 )
{
F_55 ( & V_64 -> V_48 , & V_20 -> V_65 ) ;
}
static void F_59 ( struct V_19 * V_20 ,
struct V_63 * V_64 )
{
F_46 ( & V_64 -> V_48 ) ;
F_60 ( V_20 -> V_2 , V_64 ) ;
}
int F_61 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const struct V_66 * V_42 ,
int V_21 )
{
int V_33 ;
struct V_10 * V_67 =
& V_9 [ V_21 ] . V_10 ;
F_1 ( V_2 ) ;
V_33 = F_20 ( V_2 , & V_20 -> V_17 , V_68 ) ;
if ( V_33 )
goto V_46;
V_20 -> V_17 . V_59 = & V_20 -> V_59 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_42 = V_42 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_22 =
F_62 ( V_67 , 1 , 0 , V_36 ) ;
if ( V_20 -> V_22 < 0 ) {
V_33 = V_20 -> V_22 ;
F_22 ( V_2 , & V_20 -> V_17 ) ;
goto V_46;
}
F_28 ( & V_20 -> V_65 ) ;
F_28 ( & V_20 -> V_69 ) ;
V_20 -> V_70 = NULL ;
V_20 -> V_24 = V_71 ;
F_55 ( & V_20 -> V_48 , & V_2 -> V_5 . V_72 ) ;
V_2 -> V_5 . V_73 ++ ;
if ( V_21 != V_74 )
F_63 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_75 ,
0 ) ;
F_63 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_76 , 0 ) ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_64 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_63 * V_64 , * V_77 ;
F_65 (mode, t, &connector->probed_modes, head)
F_59 ( V_20 , V_64 ) ;
F_65 (mode, t, &connector->modes, head)
F_59 ( V_20 , V_64 ) ;
F_66 ( & V_9 [ V_20 -> V_21 ] . V_10 ,
V_20 -> V_22 ) ;
F_22 ( V_2 , & V_20 -> V_17 ) ;
F_46 ( & V_20 -> V_48 ) ;
V_2 -> V_5 . V_73 -- ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
F_3 (connector, &dev->mode_config.connector_list, head)
F_68 ( V_20 ) ;
}
int F_69 ( struct V_1 * V_2 , struct V_78 * V_79 ,
const struct V_80 * V_42 )
{
int V_33 ;
F_1 ( V_2 ) ;
V_33 = F_20 ( V_2 , & V_79 -> V_17 , V_81 ) ;
if ( V_33 )
goto V_46;
V_79 -> V_2 = V_2 ;
V_79 -> V_42 = V_42 ;
F_55 ( & V_79 -> V_48 , & V_2 -> V_5 . V_82 ) ;
V_2 -> V_5 . V_83 ++ ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_70 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
F_1 ( V_2 ) ;
F_22 ( V_2 , & V_79 -> V_17 ) ;
F_46 ( & V_79 -> V_48 ) ;
V_2 -> V_5 . V_83 -- ;
F_5 ( V_2 ) ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
const struct V_84 * V_42 ,
int V_15 )
{
int V_33 ;
F_1 ( V_2 ) ;
V_33 = F_20 ( V_2 , & V_12 -> V_17 , V_85 ) ;
if ( V_33 )
goto V_46;
V_12 -> V_2 = V_2 ;
V_12 -> V_15 = V_15 ;
V_12 -> V_42 = V_42 ;
F_55 ( & V_12 -> V_48 , & V_2 -> V_5 . V_86 ) ;
V_2 -> V_5 . V_87 ++ ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_72 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_1 ( V_2 ) ;
F_22 ( V_2 , & V_12 -> V_17 ) ;
F_46 ( & V_12 -> V_48 ) ;
V_2 -> V_5 . V_87 -- ;
F_5 ( V_2 ) ;
}
int F_73 ( struct V_1 * V_2 , struct V_52 * V_53 ,
unsigned long V_88 ,
const struct V_89 * V_42 ,
const T_1 * V_90 , T_1 V_91 ,
bool V_92 )
{
int V_33 ;
F_1 ( V_2 ) ;
V_33 = F_20 ( V_2 , & V_53 -> V_17 , V_93 ) ;
if ( V_33 )
goto V_46;
V_53 -> V_17 . V_59 = & V_53 -> V_59 ;
V_53 -> V_2 = V_2 ;
V_53 -> V_42 = V_42 ;
V_53 -> V_94 = F_74 ( sizeof( T_1 ) * V_91 ,
V_36 ) ;
if ( ! V_53 -> V_94 ) {
F_75 ( L_10 ) ;
F_22 ( V_2 , & V_53 -> V_17 ) ;
V_33 = - V_95 ;
goto V_46;
}
memcpy ( V_53 -> V_94 , V_90 , V_91 * sizeof( T_1 ) ) ;
V_53 -> V_91 = V_91 ;
V_53 -> V_88 = V_88 ;
if ( ! V_92 ) {
F_55 ( & V_53 -> V_48 , & V_2 -> V_5 . V_96 ) ;
V_2 -> V_5 . V_97 ++ ;
} else {
F_28 ( & V_53 -> V_48 ) ;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
void F_76 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
F_1 ( V_2 ) ;
F_57 ( V_53 -> V_94 ) ;
F_22 ( V_2 , & V_53 -> V_17 ) ;
if ( ! F_48 ( & V_53 -> V_48 ) ) {
F_46 ( & V_53 -> V_48 ) ;
V_2 -> V_5 . V_97 -- ;
}
F_5 ( V_2 ) ;
}
void F_52 ( struct V_52 * V_53 )
{
int V_33 ;
if ( ! V_53 -> V_40 )
return;
V_33 = V_53 -> V_42 -> V_98 ( V_53 ) ;
if ( V_33 )
F_51 ( L_11 ) ;
F_42 ( V_53 -> V_40 ) ;
V_53 -> V_40 = NULL ;
V_53 -> V_4 = NULL ;
}
struct V_63 * F_77 ( struct V_1 * V_2 )
{
struct V_63 * V_99 ;
V_99 = F_78 ( sizeof( struct V_63 ) , V_36 ) ;
if ( ! V_99 )
return NULL ;
if ( F_20 ( V_2 , & V_99 -> V_17 , V_100 ) ) {
F_57 ( V_99 ) ;
return NULL ;
}
return V_99 ;
}
void F_60 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
if ( ! V_64 )
return;
F_22 ( V_2 , & V_64 -> V_17 ) ;
F_57 ( V_64 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_101 * V_102 ;
struct V_101 * V_103 ;
V_102 = F_80 ( V_2 , V_104 |
V_105 ,
L_12 , 0 ) ;
V_2 -> V_5 . V_75 = V_102 ;
V_103 = F_81 ( V_2 , 0 ,
L_13 , V_106 ,
F_11 ( V_106 ) ) ;
V_2 -> V_5 . V_76 = V_103 ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 )
{
struct V_101 * V_107 ;
struct V_101 * V_108 ;
if ( V_2 -> V_5 . V_109 )
return 0 ;
V_107 =
F_81 ( V_2 , 0 ,
L_14 ,
V_110 ,
F_11 ( V_110 ) ) ;
V_2 -> V_5 . V_109 = V_107 ;
V_108 = F_81 ( V_2 , V_105 ,
L_15 ,
V_111 ,
F_11 ( V_111 ) ) ;
V_2 -> V_5 . V_112 = V_108 ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 , int V_113 ,
char * V_69 [] )
{
struct V_101 * V_114 ;
struct V_101 * V_115 ;
int V_8 ;
if ( V_2 -> V_5 . V_116 )
return 0 ;
V_114 = F_81 ( V_2 , 0 ,
L_14 ,
V_117 ,
F_11 ( V_117 ) ) ;
V_2 -> V_5 . V_116 = V_114 ;
V_115 =
F_81 ( V_2 , V_105 ,
L_15 ,
V_118 ,
F_11 ( V_118 ) ) ;
V_2 -> V_5 . V_119 = V_115 ;
V_2 -> V_5 . V_120 =
F_84 ( V_2 , 0 , L_16 , 0 , 100 ) ;
V_2 -> V_5 . V_121 =
F_84 ( V_2 , 0 , L_17 , 0 , 100 ) ;
V_2 -> V_5 . V_122 =
F_84 ( V_2 , 0 , L_18 , 0 , 100 ) ;
V_2 -> V_5 . V_123 =
F_84 ( V_2 , 0 , L_19 , 0 , 100 ) ;
V_2 -> V_5 . V_124 =
F_80 ( V_2 , V_125 ,
L_20 , V_113 ) ;
for ( V_8 = 0 ; V_8 < V_113 ; V_8 ++ )
F_85 ( V_2 -> V_5 . V_124 , V_8 ,
V_8 , V_69 [ V_8 ] ) ;
V_2 -> V_5 . V_126 =
F_84 ( V_2 , 0 , L_21 , 0 , 100 ) ;
V_2 -> V_5 . V_127 =
F_84 ( V_2 , 0 , L_22 , 0 , 100 ) ;
V_2 -> V_5 . V_128 =
F_84 ( V_2 , 0 , L_23 , 0 , 100 ) ;
V_2 -> V_5 . V_129 =
F_84 ( V_2 , 0 , L_24 , 0 , 100 ) ;
V_2 -> V_5 . V_130 =
F_84 ( V_2 , 0 , L_25 , 0 , 100 ) ;
V_2 -> V_5 . V_131 =
F_84 ( V_2 , 0 , L_26 , 0 , 100 ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 )
{
struct V_101 * V_132 ;
if ( V_2 -> V_5 . V_133 )
return 0 ;
V_132 =
F_81 ( V_2 , 0 , L_27 ,
V_134 ,
F_11 ( V_134 ) ) ;
V_2 -> V_5 . V_133 = V_132 ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 )
{
struct V_101 * V_135 ;
if ( V_2 -> V_5 . V_136 )
return 0 ;
V_135 =
F_81 ( V_2 , V_105 ,
L_28 ,
V_137 ,
F_11 ( V_137 ) ) ;
V_2 -> V_5 . V_136 = V_135 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_138 * V_139 )
{
T_1 V_140 = 0 ;
V_140 += V_2 -> V_5 . V_61 ;
V_140 += V_2 -> V_5 . V_73 ;
V_140 += V_2 -> V_5 . V_87 ;
V_140 += V_2 -> V_5 . V_83 ;
V_139 -> V_141 = F_78 ( V_140 * sizeof( T_1 ) , V_36 ) ;
if ( ! V_139 -> V_141 )
return - V_95 ;
V_139 -> V_142 = 0 ;
V_139 -> V_143 = 0 ;
V_139 -> V_144 = 0 ;
V_139 -> V_145 = 0 ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_19 * V_20 ;
struct V_78 * V_79 ;
int V_33 ;
if ( ( V_33 = F_88 ( V_2 , V_139 ) ) )
return V_33 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
V_139 -> V_141 [ V_139 -> V_142 ++ ] = V_4 -> V_17 . V_18 ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
V_139 -> V_141 [ V_139 -> V_142 + V_139 -> V_144 ++ ] =
V_12 -> V_17 . V_18 ;
F_3 (connector, &dev->mode_config.connector_list, head)
V_139 -> V_141 [ V_139 -> V_142 + V_139 -> V_144 +
V_139 -> V_143 ++ ] = V_20 -> V_17 . V_18 ;
F_3 (bridge, &dev->mode_config.bridge_list, head)
V_139 -> V_141 [ V_139 -> V_142 + V_139 -> V_144 +
V_139 -> V_143 + V_139 -> V_145 ++ ] =
V_79 -> V_17 . V_18 ;
return 0 ;
}
static void F_90 ( struct V_146 * V_46 ,
const struct V_63 * V_147 )
{
F_91 ( V_147 -> V_148 > V_149 || V_147 -> V_150 > V_149 ||
V_147 -> V_151 > V_149 || V_147 -> V_152 > V_149 ||
V_147 -> V_153 > V_149 || V_147 -> V_154 > V_149 ||
V_147 -> V_155 > V_149 || V_147 -> V_156 > V_149 ||
V_147 -> V_157 > V_149 || V_147 -> V_158 > V_149 ,
L_29 ) ;
V_46 -> clock = V_147 -> clock ;
V_46 -> V_148 = V_147 -> V_148 ;
V_46 -> V_150 = V_147 -> V_150 ;
V_46 -> V_151 = V_147 -> V_151 ;
V_46 -> V_152 = V_147 -> V_152 ;
V_46 -> V_153 = V_147 -> V_153 ;
V_46 -> V_154 = V_147 -> V_154 ;
V_46 -> V_155 = V_147 -> V_155 ;
V_46 -> V_156 = V_147 -> V_156 ;
V_46 -> V_157 = V_147 -> V_157 ;
V_46 -> V_158 = V_147 -> V_158 ;
V_46 -> V_159 = V_147 -> V_159 ;
V_46 -> V_160 = V_147 -> V_160 ;
V_46 -> type = V_147 -> type ;
strncpy ( V_46 -> V_16 , V_147 -> V_16 , V_161 ) ;
V_46 -> V_16 [ V_161 - 1 ] = 0 ;
}
static int F_92 ( struct V_63 * V_46 ,
const struct V_146 * V_147 )
{
if ( V_147 -> clock > V_162 || V_147 -> V_159 > V_162 )
return - V_163 ;
V_46 -> clock = V_147 -> clock ;
V_46 -> V_148 = V_147 -> V_148 ;
V_46 -> V_150 = V_147 -> V_150 ;
V_46 -> V_151 = V_147 -> V_151 ;
V_46 -> V_152 = V_147 -> V_152 ;
V_46 -> V_153 = V_147 -> V_153 ;
V_46 -> V_154 = V_147 -> V_154 ;
V_46 -> V_155 = V_147 -> V_155 ;
V_46 -> V_156 = V_147 -> V_156 ;
V_46 -> V_157 = V_147 -> V_157 ;
V_46 -> V_158 = V_147 -> V_158 ;
V_46 -> V_159 = V_147 -> V_159 ;
V_46 -> V_160 = V_147 -> V_160 ;
V_46 -> type = V_147 -> type ;
strncpy ( V_46 -> V_16 , V_147 -> V_16 , V_161 ) ;
V_46 -> V_16 [ V_161 - 1 ] = 0 ;
return 0 ;
}
int F_93 ( struct V_1 * V_2 , void * V_164 ,
struct V_165 * V_166 )
{
struct V_167 * V_168 = V_164 ;
struct V_169 * V_170 ;
struct V_39 * V_40 ;
struct V_19 * V_20 ;
struct V_3 * V_4 ;
struct V_11 * V_12 ;
int V_33 = 0 ;
int V_171 = 0 ;
int V_172 = 0 ;
int V_173 = 0 ;
int V_174 = 0 ;
int V_175 = 0 , V_8 ;
T_1 T_2 * V_176 ;
T_1 T_2 * V_177 ;
T_1 T_2 * V_178 ;
T_1 T_2 * V_179 ;
struct V_138 * V_180 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_2 ( & V_166 -> V_183 ) ;
F_95 (lh, &file_priv->fbs)
V_173 ++ ;
if ( V_168 -> V_184 >= V_173 ) {
V_175 = 0 ;
V_176 = ( T_1 T_2 * ) ( unsigned long ) V_168 -> V_185 ;
F_3 (fb, &file_priv->fbs, filp_head) {
if ( F_96 ( V_40 -> V_17 . V_18 , V_176 + V_175 ) ) {
F_6 ( & V_166 -> V_183 ) ;
return - V_186 ;
}
V_175 ++ ;
}
}
V_168 -> V_184 = V_173 ;
F_6 ( & V_166 -> V_183 ) ;
F_1 ( V_2 ) ;
V_180 = & V_166 -> V_187 -> V_188 -> V_180 ;
if ( V_166 -> V_187 -> V_188 -> type == V_189 ) {
F_95 (lh, &dev->mode_config.crtc_list)
V_172 ++ ;
F_95 (lh, &dev->mode_config.connector_list)
V_171 ++ ;
F_95 (lh, &dev->mode_config.encoder_list)
V_174 ++ ;
} else {
V_172 = V_180 -> V_142 ;
V_171 = V_180 -> V_143 ;
V_174 = V_180 -> V_144 ;
}
V_168 -> V_190 = V_2 -> V_5 . V_190 ;
V_168 -> V_191 = V_2 -> V_5 . V_191 ;
V_168 -> V_192 = V_2 -> V_5 . V_192 ;
V_168 -> V_193 = V_2 -> V_5 . V_193 ;
if ( V_168 -> V_194 >= V_172 ) {
V_175 = 0 ;
V_177 = ( T_1 T_2 * ) ( unsigned long ) V_168 -> V_195 ;
if ( V_166 -> V_187 -> V_188 -> type == V_189 ) {
F_3 (crtc, &dev->mode_config.crtc_list,
head) {
F_75 ( L_30 , V_4 -> V_17 . V_18 ) ;
if ( F_96 ( V_4 -> V_17 . V_18 , V_177 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
} else {
for ( V_8 = 0 ; V_8 < V_180 -> V_142 ; V_8 ++ ) {
if ( F_96 ( V_180 -> V_141 [ V_8 ] ,
V_177 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
}
}
V_168 -> V_194 = V_172 ;
if ( V_168 -> V_196 >= V_174 ) {
V_175 = 0 ;
V_179 = ( T_1 T_2 * ) ( unsigned long ) V_168 -> V_197 ;
if ( V_166 -> V_187 -> V_188 -> type == V_189 ) {
F_3 (encoder,
&dev->mode_config.encoder_list,
head) {
F_75 ( L_31 , V_12 -> V_17 . V_18 ,
F_15 ( V_12 ) ) ;
if ( F_96 ( V_12 -> V_17 . V_18 , V_179 +
V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
} else {
for ( V_8 = V_180 -> V_142 ; V_8 < V_180 -> V_142 + V_180 -> V_144 ; V_8 ++ ) {
if ( F_96 ( V_180 -> V_141 [ V_8 ] ,
V_179 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
}
}
V_168 -> V_196 = V_174 ;
if ( V_168 -> V_198 >= V_171 ) {
V_175 = 0 ;
V_178 = ( T_1 T_2 * ) ( unsigned long ) V_168 -> V_199 ;
if ( V_166 -> V_187 -> V_188 -> type == V_189 ) {
F_3 (connector,
&dev->mode_config.connector_list,
head) {
F_75 ( L_32 ,
V_20 -> V_17 . V_18 ,
F_16 ( V_20 ) ) ;
if ( F_96 ( V_20 -> V_17 . V_18 ,
V_178 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
} else {
int V_200 = V_180 -> V_142 +
V_180 -> V_144 ;
for ( V_8 = V_200 ; V_8 < V_200 + V_180 -> V_143 ; V_8 ++ ) {
if ( F_96 ( V_180 -> V_141 [ V_8 ] ,
V_178 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
}
}
V_168 -> V_198 = V_171 ;
F_75 ( L_33 , V_168 -> V_194 ,
V_168 -> V_198 , V_168 -> V_196 ) ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_97 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_201 * V_202 = V_164 ;
struct V_3 * V_4 ;
struct V_30 * V_31 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_202 -> V_177 ,
V_58 ) ;
if ( ! V_31 ) {
V_33 = - V_182 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
V_202 -> V_203 = V_4 -> V_203 ;
V_202 -> V_204 = V_4 -> V_204 ;
V_202 -> V_205 = V_4 -> V_205 ;
if ( V_4 -> V_40 )
V_202 -> V_176 = V_4 -> V_40 -> V_17 . V_18 ;
else
V_202 -> V_176 = 0 ;
if ( V_4 -> V_206 ) {
F_90 ( & V_202 -> V_64 , & V_4 -> V_64 ) ;
V_202 -> V_207 = 1 ;
} else {
V_202 -> V_207 = 0 ;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_99 ( struct V_1 * V_2 , void * V_164 ,
struct V_165 * V_166 )
{
struct V_208 * V_209 = V_164 ;
struct V_30 * V_31 ;
struct V_19 * V_20 ;
struct V_63 * V_64 ;
int V_210 = 0 ;
int V_211 = 0 ;
int V_212 = 0 ;
int V_33 = 0 ;
int V_175 = 0 ;
int V_8 ;
struct V_146 V_213 ;
struct V_146 T_2 * V_214 ;
T_1 T_2 * V_215 ;
T_3 T_2 * V_216 ;
T_1 T_2 * V_217 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
memset ( & V_213 , 0 , sizeof( struct V_146 ) ) ;
F_75 ( L_34 , V_209 -> V_178 ) ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_31 = F_24 ( V_2 , V_209 -> V_178 ,
V_68 ) ;
if ( ! V_31 ) {
V_33 = - V_182 ;
goto V_46;
}
V_20 = F_100 ( V_31 ) ;
V_211 = V_20 -> V_59 . V_218 ;
for ( V_8 = 0 ; V_8 < V_219 ; V_8 ++ ) {
if ( V_20 -> V_220 [ V_8 ] != 0 ) {
V_212 ++ ;
}
}
if ( V_209 -> V_221 == 0 ) {
V_20 -> V_42 -> V_222 ( V_20 ,
V_2 -> V_5 . V_192 ,
V_2 -> V_5 . V_190 ) ;
}
F_3 (mode, &connector->modes, head)
V_210 ++ ;
V_209 -> V_178 = V_20 -> V_17 . V_18 ;
V_209 -> V_21 = V_20 -> V_21 ;
V_209 -> V_22 = V_20 -> V_22 ;
V_209 -> V_223 = V_20 -> V_224 . V_225 ;
V_209 -> V_226 = V_20 -> V_224 . V_227 ;
V_209 -> V_228 = V_20 -> V_224 . V_229 ;
V_209 -> V_230 = V_20 -> V_24 ;
if ( V_20 -> V_12 )
V_209 -> V_179 = V_20 -> V_12 -> V_17 . V_18 ;
else
V_209 -> V_179 = 0 ;
if ( ( V_209 -> V_221 >= V_210 ) && V_210 ) {
V_175 = 0 ;
V_214 = (struct V_146 T_2 * ) ( unsigned long ) V_209 -> V_231 ;
F_3 (mode, &connector->modes, head) {
F_90 ( & V_213 , V_64 ) ;
if ( F_101 ( V_214 + V_175 ,
& V_213 , sizeof( V_213 ) ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
}
V_209 -> V_221 = V_210 ;
if ( ( V_209 -> V_232 >= V_211 ) && V_211 ) {
V_175 = 0 ;
V_215 = ( T_1 T_2 * ) ( unsigned long ) ( V_209 -> V_233 ) ;
V_216 = ( T_3 T_2 * ) ( unsigned long ) ( V_209 -> V_234 ) ;
for ( V_8 = 0 ; V_8 < V_20 -> V_59 . V_218 ; V_8 ++ ) {
if ( F_96 ( V_20 -> V_59 . V_235 [ V_8 ] ,
V_215 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
if ( F_96 ( V_20 -> V_59 . V_236 [ V_8 ] ,
V_216 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
}
V_209 -> V_232 = V_211 ;
if ( ( V_209 -> V_196 >= V_212 ) && V_212 ) {
V_175 = 0 ;
V_217 = ( T_1 T_2 * ) ( unsigned long ) ( V_209 -> V_237 ) ;
for ( V_8 = 0 ; V_8 < V_219 ; V_8 ++ ) {
if ( V_20 -> V_220 [ V_8 ] != 0 ) {
if ( F_96 ( V_20 -> V_220 [ V_8 ] ,
V_217 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
}
}
V_209 -> V_196 = V_212 ;
V_46:
F_6 ( & V_2 -> V_5 . V_6 ) ;
return V_33 ;
}
int F_102 ( struct V_1 * V_2 , void * V_164 ,
struct V_165 * V_166 )
{
struct V_238 * V_239 = V_164 ;
struct V_30 * V_31 ;
struct V_11 * V_12 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_239 -> V_179 ,
V_85 ) ;
if ( ! V_31 ) {
V_33 = - V_182 ;
goto V_46;
}
V_12 = F_103 ( V_31 ) ;
if ( V_12 -> V_4 )
V_239 -> V_177 = V_12 -> V_4 -> V_17 . V_18 ;
else
V_239 -> V_177 = 0 ;
V_239 -> V_15 = V_12 -> V_15 ;
V_239 -> V_179 = V_12 -> V_17 . V_18 ;
V_239 -> V_88 = V_12 -> V_88 ;
V_239 -> V_240 = V_12 -> V_240 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_104 ( struct V_1 * V_2 , void * V_164 ,
struct V_165 * V_166 )
{
struct V_241 * V_242 = V_164 ;
struct V_243 * V_244 ;
struct V_52 * V_53 ;
T_1 T_2 * V_245 ;
int V_175 = 0 , V_33 = 0 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_244 = & V_2 -> V_5 ;
if ( V_244 -> V_97 &&
( V_242 -> V_246 >= V_244 -> V_97 ) ) {
V_245 = ( T_1 T_2 * ) ( unsigned long ) V_242 -> V_247 ;
F_3 (plane, &config->plane_list, head) {
if ( F_96 ( V_53 -> V_17 . V_18 , V_245 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
}
V_242 -> V_246 = V_244 -> V_97 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_105 ( struct V_1 * V_2 , void * V_164 ,
struct V_165 * V_166 )
{
struct V_248 * V_242 = V_164 ;
struct V_30 * V_31 ;
struct V_52 * V_53 ;
T_1 T_2 * V_249 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_242 -> V_250 ,
V_93 ) ;
if ( ! V_31 ) {
V_33 = - V_251 ;
goto V_46;
}
V_53 = F_106 ( V_31 ) ;
if ( V_53 -> V_4 )
V_242 -> V_177 = V_53 -> V_4 -> V_17 . V_18 ;
else
V_242 -> V_177 = 0 ;
if ( V_53 -> V_40 )
V_242 -> V_176 = V_53 -> V_40 -> V_17 . V_18 ;
else
V_242 -> V_176 = 0 ;
V_242 -> V_250 = V_53 -> V_17 . V_18 ;
V_242 -> V_88 = V_53 -> V_88 ;
V_242 -> V_205 = 0 ;
if ( V_53 -> V_91 &&
( V_242 -> V_252 >= V_53 -> V_91 ) ) {
V_249 = ( T_1 T_2 * ) ( unsigned long ) V_242 -> V_253 ;
if ( F_101 ( V_249 ,
V_53 -> V_94 ,
sizeof( T_1 ) * V_53 -> V_91 ) ) {
V_33 = - V_186 ;
goto V_46;
}
}
V_242 -> V_252 = V_53 -> V_91 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_107 ( struct V_1 * V_2 , void * V_164 ,
struct V_165 * V_166 )
{
struct V_254 * V_255 = V_164 ;
struct V_30 * V_31 ;
struct V_52 * V_53 ;
struct V_3 * V_4 ;
struct V_39 * V_40 = NULL , * V_256 = NULL ;
int V_33 = 0 ;
unsigned int V_257 , V_258 ;
int V_8 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
V_31 = F_24 ( V_2 , V_255 -> V_250 ,
V_93 ) ;
if ( ! V_31 ) {
F_75 ( L_35 ,
V_255 -> V_250 ) ;
return - V_251 ;
}
V_53 = F_106 ( V_31 ) ;
if ( ! V_255 -> V_176 ) {
F_1 ( V_2 ) ;
V_256 = V_53 -> V_40 ;
V_53 -> V_42 -> V_98 ( V_53 ) ;
V_53 -> V_4 = NULL ;
V_53 -> V_40 = NULL ;
F_5 ( V_2 ) ;
goto V_46;
}
V_31 = F_24 ( V_2 , V_255 -> V_177 ,
V_58 ) ;
if ( ! V_31 ) {
F_75 ( L_36 ,
V_255 -> V_177 ) ;
V_33 = - V_251 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
V_40 = F_35 ( V_2 , V_255 -> V_176 ) ;
if ( ! V_40 ) {
F_75 ( L_37 ,
V_255 -> V_176 ) ;
V_33 = - V_251 ;
goto V_46;
}
for ( V_8 = 0 ; V_8 < V_53 -> V_91 ; V_8 ++ )
if ( V_40 -> V_259 == V_53 -> V_94 [ V_8 ] )
break;
if ( V_8 == V_53 -> V_91 ) {
F_75 ( L_38 ,
F_19 ( V_40 -> V_259 ) ) ;
V_33 = - V_182 ;
goto V_46;
}
V_257 = V_40 -> V_260 << 16 ;
V_258 = V_40 -> V_261 << 16 ;
if ( V_255 -> V_262 > V_257 ||
V_255 -> V_263 > V_257 - V_255 -> V_262 ||
V_255 -> V_264 > V_258 ||
V_255 -> V_265 > V_258 - V_255 -> V_264 ) {
F_75 ( L_39
L_40 ,
V_255 -> V_262 >> 16 ,
( ( V_255 -> V_262 & 0xffff ) * 15625 ) >> 10 ,
V_255 -> V_264 >> 16 ,
( ( V_255 -> V_264 & 0xffff ) * 15625 ) >> 10 ,
V_255 -> V_263 >> 16 ,
( ( V_255 -> V_263 & 0xffff ) * 15625 ) >> 10 ,
V_255 -> V_265 >> 16 ,
( ( V_255 -> V_265 & 0xffff ) * 15625 ) >> 10 ) ;
V_33 = - V_266 ;
goto V_46;
}
if ( V_255 -> V_267 > V_162 ||
V_255 -> V_268 > V_162 - ( V_269 ) V_255 -> V_267 ||
V_255 -> V_270 > V_162 ||
V_255 -> V_271 > V_162 - ( V_269 ) V_255 -> V_270 ) {
F_75 ( L_41 ,
V_255 -> V_267 , V_255 -> V_270 ,
V_255 -> V_268 , V_255 -> V_271 ) ;
V_33 = - V_163 ;
goto V_46;
}
F_1 ( V_2 ) ;
V_33 = V_53 -> V_42 -> V_272 ( V_53 , V_4 , V_40 ,
V_255 -> V_268 , V_255 -> V_271 ,
V_255 -> V_267 , V_255 -> V_270 ,
V_255 -> V_263 , V_255 -> V_265 ,
V_255 -> V_262 , V_255 -> V_264 ) ;
if ( ! V_33 ) {
V_256 = V_53 -> V_40 ;
V_53 -> V_4 = V_4 ;
V_53 -> V_40 = V_40 ;
V_40 = NULL ;
}
F_5 ( V_2 ) ;
V_46:
if ( V_40 )
F_36 ( V_40 ) ;
if ( V_256 )
F_36 ( V_256 ) ;
return V_33 ;
}
int F_50 ( struct V_54 * V_55 )
{
struct V_3 * V_4 = V_55 -> V_4 ;
struct V_39 * V_40 ;
struct V_3 * V_273 ;
int V_33 ;
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_273 -> V_256 = V_273 -> V_40 ;
V_40 = V_55 -> V_40 ;
V_33 = V_4 -> V_42 -> V_274 ( V_55 ) ;
if ( V_33 == 0 ) {
F_8 ( V_40 != V_4 -> V_40 ) ;
}
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_273 -> V_40 )
F_29 ( V_273 -> V_40 ) ;
if ( V_273 -> V_256 )
F_36 ( V_273 -> V_256 ) ;
}
return V_33 ;
}
int F_108 ( struct V_1 * V_2 , void * V_164 ,
struct V_165 * V_166 )
{
struct V_243 * V_244 = & V_2 -> V_5 ;
struct V_201 * V_275 = V_164 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
struct V_19 * * V_276 = NULL , * V_20 ;
struct V_39 * V_40 = NULL ;
struct V_63 * V_64 = NULL ;
struct V_54 V_55 ;
T_1 T_2 * V_277 ;
int V_33 ;
int V_8 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
if ( V_275 -> V_203 > V_162 || V_275 -> V_204 > V_162 )
return - V_163 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_275 -> V_177 ,
V_58 ) ;
if ( ! V_31 ) {
F_75 ( L_42 , V_275 -> V_177 ) ;
V_33 = - V_182 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
F_75 ( L_30 , V_4 -> V_17 . V_18 ) ;
if ( V_275 -> V_207 ) {
int V_148 , V_154 ;
if ( V_275 -> V_176 == - 1 ) {
if ( ! V_4 -> V_40 ) {
F_75 ( L_43 ) ;
V_33 = - V_182 ;
goto V_46;
}
V_40 = V_4 -> V_40 ;
F_29 ( V_40 ) ;
} else {
V_40 = F_35 ( V_2 , V_275 -> V_176 ) ;
if ( ! V_40 ) {
F_75 ( L_44 ,
V_275 -> V_176 ) ;
V_33 = - V_182 ;
goto V_46;
}
}
V_64 = F_77 ( V_2 ) ;
if ( ! V_64 ) {
V_33 = - V_95 ;
goto V_46;
}
V_33 = F_92 ( V_64 , & V_275 -> V_64 ) ;
if ( V_33 ) {
F_75 ( L_45 ) ;
goto V_46;
}
F_109 ( V_64 , V_278 ) ;
V_148 = V_64 -> V_148 ;
V_154 = V_64 -> V_154 ;
if ( V_4 -> V_57 )
F_110 ( V_148 , V_154 ) ;
if ( V_148 > V_40 -> V_260 ||
V_154 > V_40 -> V_261 ||
V_275 -> V_203 > V_40 -> V_260 - V_148 ||
V_275 -> V_204 > V_40 -> V_261 - V_154 ) {
F_75 ( L_46 ,
V_40 -> V_260 , V_40 -> V_261 ,
V_148 , V_154 , V_275 -> V_203 , V_275 -> V_204 ,
V_4 -> V_57 ? L_47 : L_48 ) ;
V_33 = - V_266 ;
goto V_46;
}
}
if ( V_275 -> V_198 == 0 && V_64 ) {
F_75 ( L_49 ) ;
V_33 = - V_182 ;
goto V_46;
}
if ( V_275 -> V_198 > 0 && ( ! V_64 || ! V_40 ) ) {
F_75 ( L_50 ,
V_275 -> V_198 ) ;
V_33 = - V_182 ;
goto V_46;
}
if ( V_275 -> V_198 > 0 ) {
T_4 V_279 ;
if ( V_275 -> V_198 > V_244 -> V_73 ) {
V_33 = - V_182 ;
goto V_46;
}
V_276 = F_74 ( V_275 -> V_198 *
sizeof( struct V_19 * ) ,
V_36 ) ;
if ( ! V_276 ) {
V_33 = - V_95 ;
goto V_46;
}
for ( V_8 = 0 ; V_8 < V_275 -> V_198 ; V_8 ++ ) {
V_277 = ( T_1 T_2 * ) ( unsigned long ) V_275 -> V_277 ;
if ( F_111 ( V_279 , & V_277 [ V_8 ] ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_31 = F_24 ( V_2 , V_279 ,
V_68 ) ;
if ( ! V_31 ) {
F_75 ( L_51 ,
V_279 ) ;
V_33 = - V_182 ;
goto V_46;
}
V_20 = F_100 ( V_31 ) ;
F_75 ( L_32 ,
V_20 -> V_17 . V_18 ,
F_16 ( V_20 ) ) ;
V_276 [ V_8 ] = V_20 ;
}
}
V_55 . V_4 = V_4 ;
V_55 . V_203 = V_275 -> V_203 ;
V_55 . V_204 = V_275 -> V_204 ;
V_55 . V_64 = V_64 ;
V_55 . V_280 = V_276 ;
V_55 . V_143 = V_275 -> V_198 ;
V_55 . V_40 = V_40 ;
V_33 = F_50 ( & V_55 ) ;
V_46:
if ( V_40 )
F_36 ( V_40 ) ;
F_57 ( V_276 ) ;
F_60 ( V_2 , V_64 ) ;
F_5 ( V_2 ) ;
return V_33 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_281 * V_282 ,
struct V_165 * V_166 )
{
struct V_30 * V_31 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
if ( ! V_282 -> V_160 || ( ~ V_283 & V_282 -> V_160 ) )
return - V_182 ;
V_31 = F_24 ( V_2 , V_282 -> V_177 , V_58 ) ;
if ( ! V_31 ) {
F_75 ( L_42 , V_282 -> V_177 ) ;
return - V_182 ;
}
V_4 = F_98 ( V_31 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_282 -> V_160 & V_284 ) {
if ( ! V_4 -> V_42 -> V_285 && ! V_4 -> V_42 -> V_286 ) {
V_33 = - V_287 ;
goto V_46;
}
if ( V_4 -> V_42 -> V_286 )
V_33 = V_4 -> V_42 -> V_286 ( V_4 , V_166 , V_282 -> V_288 ,
V_282 -> V_260 , V_282 -> V_261 , V_282 -> V_289 , V_282 -> V_290 ) ;
else
V_33 = V_4 -> V_42 -> V_285 ( V_4 , V_166 , V_282 -> V_288 ,
V_282 -> V_260 , V_282 -> V_261 ) ;
}
if ( V_282 -> V_160 & V_291 ) {
if ( V_4 -> V_42 -> V_292 ) {
V_33 = V_4 -> V_42 -> V_292 ( V_4 , V_282 -> V_203 , V_282 -> V_204 ) ;
} else {
V_33 = - V_186 ;
goto V_46;
}
}
V_46:
F_6 ( & V_4 -> V_6 ) ;
return V_33 ;
}
int F_113 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_293 * V_282 = V_164 ;
struct V_281 V_294 ;
memcpy ( & V_294 , V_282 , sizeof( struct V_293 ) ) ;
V_294 . V_289 = V_294 . V_290 = 0 ;
return F_112 ( V_2 , & V_294 , V_166 ) ;
}
int F_114 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_281 * V_282 = V_164 ;
return F_112 ( V_2 , V_282 , V_166 ) ;
}
T_1 F_115 ( T_1 V_295 , T_1 V_296 )
{
T_1 V_297 ;
switch ( V_295 ) {
case 8 :
V_297 = V_298 ;
break;
case 16 :
if ( V_296 == 15 )
V_297 = V_299 ;
else
V_297 = V_300 ;
break;
case 24 :
V_297 = V_301 ;
break;
case 32 :
if ( V_296 == 24 )
V_297 = V_302 ;
else if ( V_296 == 30 )
V_297 = V_303 ;
else
V_297 = V_304 ;
break;
default:
F_51 ( L_52 ) ;
V_297 = V_302 ;
break;
}
return V_297 ;
}
int F_116 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_305 * V_306 = V_164 ;
struct V_307 V_308 = {} ;
struct V_243 * V_244 = & V_2 -> V_5 ;
struct V_39 * V_40 ;
int V_33 = 0 ;
V_308 . V_176 = V_306 -> V_176 ;
V_308 . V_260 = V_306 -> V_260 ;
V_308 . V_261 = V_306 -> V_261 ;
V_308 . V_309 [ 0 ] = V_306 -> V_310 ;
V_308 . V_259 = F_115 ( V_306 -> V_295 , V_306 -> V_296 ) ;
V_308 . V_311 [ 0 ] = V_306 -> V_288 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
if ( ( V_244 -> V_193 > V_308 . V_260 ) || ( V_308 . V_260 > V_244 -> V_192 ) )
return - V_182 ;
if ( ( V_244 -> V_191 > V_308 . V_261 ) || ( V_308 . V_261 > V_244 -> V_190 ) )
return - V_182 ;
V_40 = V_2 -> V_5 . V_42 -> V_312 ( V_2 , V_166 , & V_308 ) ;
if ( F_117 ( V_40 ) ) {
F_75 ( L_53 ) ;
return F_118 ( V_40 ) ;
}
F_2 ( & V_166 -> V_183 ) ;
V_306 -> V_176 = V_40 -> V_17 . V_18 ;
F_30 ( & V_40 -> V_45 , & V_166 -> V_313 ) ;
F_75 ( L_54 , V_40 -> V_17 . V_18 ) ;
F_6 ( & V_166 -> V_183 ) ;
return V_33 ;
}
static int F_119 ( const struct V_307 * V_308 )
{
T_1 V_28 = V_308 -> V_259 & ~ V_29 ;
switch ( V_28 ) {
case V_298 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_299 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_300 :
case V_331 :
case V_301 :
case V_332 :
case V_302 :
case V_333 :
case V_334 :
case V_335 :
case V_304 :
case V_336 :
case V_337 :
case V_338 :
case V_303 :
case V_339 :
case V_340 :
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
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
return 0 ;
default:
return - V_182 ;
}
}
static int F_120 ( const struct V_307 * V_308 )
{
int V_33 , V_367 , V_368 , V_369 , V_8 ;
V_33 = F_119 ( V_308 ) ;
if ( V_33 ) {
F_75 ( L_55 ,
F_19 ( V_308 -> V_259 ) ) ;
return V_33 ;
}
V_367 = F_121 ( V_308 -> V_259 ) ;
V_368 = F_122 ( V_308 -> V_259 ) ;
V_369 = F_123 ( V_308 -> V_259 ) ;
if ( V_308 -> V_260 == 0 || V_308 -> V_260 % V_367 ) {
F_75 ( L_56 , V_308 -> V_261 ) ;
return - V_182 ;
}
if ( V_308 -> V_261 == 0 || V_308 -> V_261 % V_368 ) {
F_75 ( L_57 , V_308 -> V_261 ) ;
return - V_182 ;
}
for ( V_8 = 0 ; V_8 < V_369 ; V_8 ++ ) {
unsigned int V_260 = V_308 -> V_260 / ( V_8 != 0 ? V_367 : 1 ) ;
unsigned int V_261 = V_308 -> V_261 / ( V_8 != 0 ? V_368 : 1 ) ;
unsigned int V_370 = F_124 ( V_308 -> V_259 , V_8 ) ;
if ( ! V_308 -> V_311 [ V_8 ] ) {
F_75 ( L_58 , V_8 ) ;
return - V_182 ;
}
if ( ( T_3 ) V_260 * V_370 > V_371 )
return - V_163 ;
if ( ( T_3 ) V_261 * V_308 -> V_309 [ V_8 ] + V_308 -> V_372 [ V_8 ] > V_371 )
return - V_163 ;
if ( V_308 -> V_309 [ V_8 ] < V_260 * V_370 ) {
F_75 ( L_59 , V_308 -> V_309 [ V_8 ] , V_8 ) ;
return - V_182 ;
}
}
return 0 ;
}
int F_125 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_307 * V_308 = V_164 ;
struct V_243 * V_244 = & V_2 -> V_5 ;
struct V_39 * V_40 ;
int V_33 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
if ( V_308 -> V_160 & ~ V_373 ) {
F_75 ( L_60 , V_308 -> V_160 ) ;
return - V_182 ;
}
if ( ( V_244 -> V_193 > V_308 -> V_260 ) || ( V_308 -> V_260 > V_244 -> V_192 ) ) {
F_75 ( L_61 ,
V_308 -> V_260 , V_244 -> V_193 , V_244 -> V_192 ) ;
return - V_182 ;
}
if ( ( V_244 -> V_191 > V_308 -> V_261 ) || ( V_308 -> V_261 > V_244 -> V_190 ) ) {
F_75 ( L_62 ,
V_308 -> V_261 , V_244 -> V_191 , V_244 -> V_190 ) ;
return - V_182 ;
}
V_33 = F_120 ( V_308 ) ;
if ( V_33 )
return V_33 ;
V_40 = V_2 -> V_5 . V_42 -> V_312 ( V_2 , V_166 , V_308 ) ;
if ( F_117 ( V_40 ) ) {
F_75 ( L_53 ) ;
return F_118 ( V_40 ) ;
}
F_2 ( & V_166 -> V_183 ) ;
V_308 -> V_176 = V_40 -> V_17 . V_18 ;
F_30 ( & V_40 -> V_45 , & V_166 -> V_313 ) ;
F_75 ( L_54 , V_40 -> V_17 . V_18 ) ;
F_6 ( & V_166 -> V_183 ) ;
return V_33 ;
}
int F_126 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_39 * V_40 = NULL ;
struct V_39 * V_374 = NULL ;
T_1 * V_18 = V_164 ;
int V_375 = 0 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_2 ( & V_166 -> V_183 ) ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
V_40 = F_33 ( V_2 , * V_18 ) ;
if ( ! V_40 )
goto V_376;
F_3 (fbl, &file_priv->fbs, filp_head)
if ( V_40 == V_374 )
V_375 = 1 ;
if ( ! V_375 )
goto V_376;
F_43 ( V_2 , V_40 ) ;
F_127 ( & V_40 -> V_45 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
F_6 ( & V_166 -> V_183 ) ;
F_47 ( V_40 ) ;
return 0 ;
V_376:
F_6 ( & V_2 -> V_5 . V_43 ) ;
F_6 ( & V_166 -> V_183 ) ;
return - V_182 ;
}
int F_128 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_305 * V_308 = V_164 ;
struct V_39 * V_40 ;
int V_33 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
V_40 = F_35 ( V_2 , V_308 -> V_176 ) ;
if ( ! V_40 )
return - V_182 ;
V_308 -> V_261 = V_40 -> V_261 ;
V_308 -> V_260 = V_40 -> V_260 ;
V_308 -> V_296 = V_40 -> V_296 ;
V_308 -> V_295 = V_40 -> V_377 ;
V_308 -> V_310 = V_40 -> V_309 [ 0 ] ;
if ( V_40 -> V_42 -> V_378 ) {
if ( V_166 -> V_379 || F_129 ( V_380 ) ) {
V_33 = V_40 -> V_42 -> V_378 ( V_40 , V_166 ,
& V_308 -> V_288 ) ;
} else {
V_308 -> V_288 = 0 ;
V_33 = 0 ;
}
} else {
V_33 = - V_381 ;
}
F_36 ( V_40 ) ;
return V_33 ;
}
int F_130 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_382 T_2 * V_383 ;
struct V_382 * V_384 = NULL ;
struct V_385 * V_308 = V_164 ;
struct V_39 * V_40 ;
unsigned V_160 ;
int V_386 ;
int V_33 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
V_40 = F_35 ( V_2 , V_308 -> V_176 ) ;
if ( ! V_40 )
return - V_182 ;
V_386 = V_308 -> V_386 ;
V_383 = (struct V_382 T_2 * ) ( unsigned long ) V_308 -> V_383 ;
if ( ! V_386 != ! V_383 ) {
V_33 = - V_182 ;
goto V_387;
}
V_160 = V_388 & V_308 -> V_160 ;
if ( V_160 & V_389 && ( V_386 % 2 ) ) {
V_33 = - V_182 ;
goto V_387;
}
if ( V_386 && V_383 ) {
if ( V_386 < 0 || V_386 > V_390 ) {
V_33 = - V_182 ;
goto V_387;
}
V_384 = F_78 ( V_386 * sizeof( * V_384 ) , V_36 ) ;
if ( ! V_384 ) {
V_33 = - V_95 ;
goto V_387;
}
V_33 = F_131 ( V_384 , V_383 ,
V_386 * sizeof( * V_384 ) ) ;
if ( V_33 ) {
V_33 = - V_186 ;
goto V_391;
}
}
if ( V_40 -> V_42 -> V_392 ) {
F_1 ( V_2 ) ;
V_33 = V_40 -> V_42 -> V_392 ( V_40 , V_166 , V_160 , V_308 -> V_393 ,
V_384 , V_386 ) ;
F_5 ( V_2 ) ;
} else {
V_33 = - V_394 ;
}
V_391:
F_57 ( V_384 ) ;
V_387:
F_36 ( V_40 ) ;
return V_33 ;
}
void F_132 ( struct V_165 * V_92 )
{
struct V_1 * V_2 = V_92 -> V_188 -> V_2 ;
struct V_39 * V_40 , * V_395 ;
F_2 ( & V_92 -> V_183 ) ;
F_65 (fb, tfb, &priv->fbs, filp_head) {
F_2 ( & V_2 -> V_5 . V_43 ) ;
F_43 ( V_2 , V_40 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
F_127 ( & V_40 -> V_45 ) ;
F_47 ( V_40 ) ;
}
F_6 ( & V_92 -> V_183 ) ;
}
struct V_101 * F_80 ( struct V_1 * V_2 , int V_160 ,
const char * V_16 , int V_396 )
{
struct V_101 * V_397 = NULL ;
int V_33 ;
V_397 = F_78 ( sizeof( struct V_101 ) , V_36 ) ;
if ( ! V_397 )
return NULL ;
if ( V_396 ) {
V_397 -> V_236 = F_78 ( sizeof( T_3 ) * V_396 , V_36 ) ;
if ( ! V_397 -> V_236 )
goto V_398;
}
V_33 = F_20 ( V_2 , & V_397 -> V_17 , V_399 ) ;
if ( V_33 )
goto V_398;
V_397 -> V_160 = V_160 ;
V_397 -> V_396 = V_396 ;
F_28 ( & V_397 -> V_400 ) ;
if ( V_16 ) {
strncpy ( V_397 -> V_16 , V_16 , V_401 ) ;
V_397 -> V_16 [ V_401 - 1 ] = '\0' ;
}
F_55 ( & V_397 -> V_48 , & V_2 -> V_5 . V_402 ) ;
return V_397 ;
V_398:
F_57 ( V_397 -> V_236 ) ;
F_57 ( V_397 ) ;
return NULL ;
}
struct V_101 * F_81 ( struct V_1 * V_2 , int V_160 ,
const char * V_16 ,
const struct V_403 * V_404 ,
int V_396 )
{
struct V_101 * V_397 ;
int V_8 , V_33 ;
V_160 |= V_125 ;
V_397 = F_80 ( V_2 , V_160 , V_16 , V_396 ) ;
if ( ! V_397 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_396 ; V_8 ++ ) {
V_33 = F_85 ( V_397 , V_8 ,
V_404 [ V_8 ] . type ,
V_404 [ V_8 ] . V_16 ) ;
if ( V_33 ) {
F_133 ( V_2 , V_397 ) ;
return NULL ;
}
}
return V_397 ;
}
struct V_101 * F_134 ( struct V_1 * V_2 ,
int V_160 , const char * V_16 ,
const struct V_403 * V_404 ,
int V_396 )
{
struct V_101 * V_397 ;
int V_8 , V_33 ;
V_160 |= V_405 ;
V_397 = F_80 ( V_2 , V_160 , V_16 , V_396 ) ;
if ( ! V_397 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_396 ; V_8 ++ ) {
V_33 = F_85 ( V_397 , V_8 ,
V_404 [ V_8 ] . type ,
V_404 [ V_8 ] . V_16 ) ;
if ( V_33 ) {
F_133 ( V_2 , V_397 ) ;
return NULL ;
}
}
return V_397 ;
}
struct V_101 * F_84 ( struct V_1 * V_2 , int V_160 ,
const char * V_16 ,
T_3 V_406 , T_3 V_407 )
{
struct V_101 * V_397 ;
V_160 |= V_408 ;
V_397 = F_80 ( V_2 , V_160 , V_16 , 2 ) ;
if ( ! V_397 )
return NULL ;
V_397 -> V_236 [ 0 ] = V_406 ;
V_397 -> V_236 [ 1 ] = V_407 ;
return V_397 ;
}
int F_85 ( struct V_101 * V_397 , int V_409 ,
T_3 V_410 , const char * V_16 )
{
struct V_411 * V_412 ;
if ( ! ( V_397 -> V_160 & ( V_125 | V_405 ) ) )
return - V_182 ;
if ( ( V_397 -> V_160 & V_405 ) && ( V_410 > 63 ) )
return - V_182 ;
if ( ! F_48 ( & V_397 -> V_400 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( V_412 -> V_410 == V_410 ) {
strncpy ( V_412 -> V_16 , V_16 , V_401 ) ;
V_412 -> V_16 [ V_401 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_412 = F_78 ( sizeof( struct V_411 ) , V_36 ) ;
if ( ! V_412 )
return - V_95 ;
strncpy ( V_412 -> V_16 , V_16 , V_401 ) ;
V_412 -> V_16 [ V_401 - 1 ] = '\0' ;
V_412 -> V_410 = V_410 ;
V_397 -> V_236 [ V_409 ] = V_410 ;
F_55 ( & V_412 -> V_48 , & V_397 -> V_400 ) ;
return 0 ;
}
void F_133 ( struct V_1 * V_2 , struct V_101 * V_397 )
{
struct V_411 * V_412 , * V_413 ;
F_65 (prop_enum, pt, &property->enum_blob_list, head) {
F_46 ( & V_412 -> V_48 ) ;
F_57 ( V_412 ) ;
}
if ( V_397 -> V_396 )
F_57 ( V_397 -> V_236 ) ;
F_22 ( V_2 , & V_397 -> V_17 ) ;
F_46 ( & V_397 -> V_48 ) ;
F_57 ( V_397 ) ;
}
void F_63 ( struct V_30 * V_31 ,
struct V_101 * V_397 ,
T_3 V_414 )
{
int V_218 = V_31 -> V_59 -> V_218 ;
if ( V_218 == V_415 ) {
F_91 ( 1 , L_63
L_64
L_65 ,
V_31 -> type ) ;
return;
}
V_31 -> V_59 -> V_235 [ V_218 ] = V_397 -> V_17 . V_18 ;
V_31 -> V_59 -> V_236 [ V_218 ] = V_414 ;
V_31 -> V_59 -> V_218 ++ ;
}
int F_135 ( struct V_30 * V_31 ,
struct V_101 * V_397 , T_3 V_416 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 -> V_59 -> V_218 ; V_8 ++ ) {
if ( V_31 -> V_59 -> V_235 [ V_8 ] == V_397 -> V_17 . V_18 ) {
V_31 -> V_59 -> V_236 [ V_8 ] = V_416 ;
return 0 ;
}
}
return - V_182 ;
}
int F_136 ( struct V_30 * V_31 ,
struct V_101 * V_397 , T_3 * V_416 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 -> V_59 -> V_218 ; V_8 ++ ) {
if ( V_31 -> V_59 -> V_235 [ V_8 ] == V_397 -> V_17 . V_18 ) {
* V_416 = V_31 -> V_59 -> V_236 [ V_8 ] ;
return 0 ;
}
}
return - V_182 ;
}
int F_137 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_30 * V_31 ;
struct V_417 * V_209 = V_164 ;
struct V_101 * V_397 ;
int V_418 = 0 ;
int V_419 = 0 ;
int V_420 = 0 ;
int V_33 = 0 , V_8 ;
int V_175 ;
struct V_411 * V_412 ;
struct V_421 T_2 * V_422 ;
struct V_423 * V_424 ;
T_1 T_2 * V_425 ;
T_3 T_2 * V_426 ;
T_1 T_2 * V_427 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_209 -> V_428 , V_399 ) ;
if ( ! V_31 ) {
V_33 = - V_182 ;
goto V_429;
}
V_397 = F_138 ( V_31 ) ;
if ( V_397 -> V_160 & ( V_125 | V_405 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head)
V_418 ++ ;
} else if ( V_397 -> V_160 & V_104 ) {
F_3 (prop_blob, &property->enum_blob_list, head)
V_419 ++ ;
}
V_420 = V_397 -> V_396 ;
strncpy ( V_209 -> V_16 , V_397 -> V_16 , V_401 ) ;
V_209 -> V_16 [ V_401 - 1 ] = 0 ;
V_209 -> V_160 = V_397 -> V_160 ;
if ( ( V_209 -> V_430 >= V_420 ) && V_420 ) {
V_426 = ( T_3 T_2 * ) ( unsigned long ) V_209 -> V_426 ;
for ( V_8 = 0 ; V_8 < V_420 ; V_8 ++ ) {
if ( F_101 ( V_426 + V_8 , & V_397 -> V_236 [ V_8 ] , sizeof( T_3 ) ) ) {
V_33 = - V_186 ;
goto V_429;
}
}
}
V_209 -> V_430 = V_420 ;
if ( V_397 -> V_160 & ( V_125 | V_405 ) ) {
if ( ( V_209 -> V_431 >= V_418 ) && V_418 ) {
V_175 = 0 ;
V_422 = (struct V_421 T_2 * ) ( unsigned long ) V_209 -> V_432 ;
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( F_101 ( & V_422 [ V_175 ] . V_410 , & V_412 -> V_410 , sizeof( T_3 ) ) ) {
V_33 = - V_186 ;
goto V_429;
}
if ( F_101 ( & V_422 [ V_175 ] . V_16 ,
& V_412 -> V_16 , V_401 ) ) {
V_33 = - V_186 ;
goto V_429;
}
V_175 ++ ;
}
}
V_209 -> V_431 = V_418 ;
}
if ( V_397 -> V_160 & V_104 ) {
if ( ( V_209 -> V_431 >= V_419 ) && V_419 ) {
V_175 = 0 ;
V_425 = ( T_1 T_2 * ) ( unsigned long ) V_209 -> V_432 ;
V_427 = ( T_1 T_2 * ) ( unsigned long ) V_209 -> V_426 ;
F_3 (prop_blob, &property->enum_blob_list, head) {
if ( F_96 ( V_424 -> V_17 . V_18 , V_425 + V_175 ) ) {
V_33 = - V_186 ;
goto V_429;
}
if ( F_96 ( V_424 -> V_433 , V_427 + V_175 ) ) {
V_33 = - V_186 ;
goto V_429;
}
V_175 ++ ;
}
}
V_209 -> V_431 = V_419 ;
}
V_429:
F_5 ( V_2 ) ;
return V_33 ;
}
static struct V_423 * F_139 ( struct V_1 * V_2 , int V_433 ,
void * V_164 )
{
struct V_423 * V_434 ;
int V_33 ;
if ( ! V_433 || ! V_164 )
return NULL ;
V_434 = F_78 ( sizeof( struct V_423 ) + V_433 , V_36 ) ;
if ( ! V_434 )
return NULL ;
V_33 = F_20 ( V_2 , & V_434 -> V_17 , V_435 ) ;
if ( V_33 ) {
F_57 ( V_434 ) ;
return NULL ;
}
V_434 -> V_433 = V_433 ;
memcpy ( V_434 -> V_164 , V_164 , V_433 ) ;
F_55 ( & V_434 -> V_48 , & V_2 -> V_5 . V_436 ) ;
return V_434 ;
}
static void F_140 ( struct V_1 * V_2 ,
struct V_423 * V_434 )
{
F_22 ( V_2 , & V_434 -> V_17 ) ;
F_46 ( & V_434 -> V_48 ) ;
F_57 ( V_434 ) ;
}
int F_141 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_30 * V_31 ;
struct V_437 * V_209 = V_164 ;
struct V_423 * V_434 ;
int V_33 = 0 ;
void T_2 * V_438 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_209 -> V_439 , V_435 ) ;
if ( ! V_31 ) {
V_33 = - V_182 ;
goto V_429;
}
V_434 = F_142 ( V_31 ) ;
if ( V_209 -> V_433 == V_434 -> V_433 ) {
V_438 = ( void T_2 * ) ( unsigned long ) V_209 -> V_164 ;
if ( F_101 ( V_438 , V_434 -> V_164 , V_434 -> V_433 ) ) {
V_33 = - V_186 ;
goto V_429;
}
}
V_209 -> V_433 = V_434 -> V_433 ;
V_429:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_143 ( struct V_19 * V_20 ,
struct V_102 * V_102 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_33 , V_440 ;
if ( V_20 -> V_70 )
F_140 ( V_2 , V_20 -> V_70 ) ;
if ( ! V_102 ) {
V_20 -> V_70 = NULL ;
V_33 = F_135 ( & V_20 -> V_17 , V_2 -> V_5 . V_75 , 0 ) ;
return V_33 ;
}
V_440 = V_441 * ( 1 + V_102 -> V_442 ) ;
V_20 -> V_70 = F_139 ( V_20 -> V_2 ,
V_440 , V_102 ) ;
if ( ! V_20 -> V_70 )
return - V_182 ;
V_33 = F_135 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_75 ,
V_20 -> V_70 -> V_17 . V_18 ) ;
return V_33 ;
}
static bool F_144 ( struct V_101 * V_397 ,
T_3 V_410 )
{
if ( V_397 -> V_160 & V_105 )
return false ;
if ( V_397 -> V_160 & V_408 ) {
if ( V_410 < V_397 -> V_236 [ 0 ] || V_410 > V_397 -> V_236 [ 1 ] )
return false ;
return true ;
} else if ( V_397 -> V_160 & V_405 ) {
int V_8 ;
T_3 V_443 = 0 ;
for ( V_8 = 0 ; V_8 < V_397 -> V_396 ; V_8 ++ )
V_443 |= ( 1ULL << V_397 -> V_236 [ V_8 ] ) ;
return ! ( V_410 & ~ V_443 ) ;
} else if ( V_397 -> V_160 & V_104 ) {
return true ;
} else {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_397 -> V_396 ; V_8 ++ )
if ( V_397 -> V_236 [ V_8 ] == V_410 )
return true ;
return false ;
}
}
int F_145 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_444 * V_445 = V_164 ;
struct V_446 V_447 = {
. V_410 = V_445 -> V_410 ,
. V_428 = V_445 -> V_428 ,
. V_448 = V_445 -> V_178 ,
. V_32 = V_68
} ;
return F_146 ( V_2 , & V_447 , V_166 ) ;
}
static int F_147 ( struct V_30 * V_31 ,
struct V_101 * V_397 ,
T_3 V_410 )
{
int V_33 = - V_182 ;
struct V_19 * V_20 = F_100 ( V_31 ) ;
if ( V_397 == V_20 -> V_2 -> V_5 . V_76 ) {
if ( V_20 -> V_42 -> V_103 )
(* V_20 -> V_42 -> V_103 )( V_20 , ( int ) V_410 ) ;
V_33 = 0 ;
} else if ( V_20 -> V_42 -> V_449 )
V_33 = V_20 -> V_42 -> V_449 ( V_20 , V_397 , V_410 ) ;
if ( ! V_33 )
F_135 ( & V_20 -> V_17 , V_397 , V_410 ) ;
return V_33 ;
}
static int F_148 ( struct V_30 * V_31 ,
struct V_101 * V_397 ,
T_3 V_410 )
{
int V_33 = - V_182 ;
struct V_3 * V_4 = F_98 ( V_31 ) ;
if ( V_4 -> V_42 -> V_449 )
V_33 = V_4 -> V_42 -> V_449 ( V_4 , V_397 , V_410 ) ;
if ( ! V_33 )
F_135 ( V_31 , V_397 , V_410 ) ;
return V_33 ;
}
static int F_149 ( struct V_30 * V_31 ,
struct V_101 * V_397 ,
T_3 V_410 )
{
int V_33 = - V_182 ;
struct V_52 * V_53 = F_106 ( V_31 ) ;
if ( V_53 -> V_42 -> V_449 )
V_33 = V_53 -> V_42 -> V_449 ( V_53 , V_397 , V_410 ) ;
if ( ! V_33 )
F_135 ( V_31 , V_397 , V_410 ) ;
return V_33 ;
}
int F_150 ( struct V_1 * V_2 , void * V_164 ,
struct V_165 * V_166 )
{
struct V_450 * V_451 = V_164 ;
struct V_30 * V_31 ;
int V_33 = 0 ;
int V_8 ;
int V_175 = 0 ;
int V_211 = 0 ;
T_1 T_2 * V_233 ;
T_3 T_2 * V_234 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_451 -> V_448 , V_451 -> V_32 ) ;
if ( ! V_31 ) {
V_33 = - V_182 ;
goto V_46;
}
if ( ! V_31 -> V_59 ) {
V_33 = - V_182 ;
goto V_46;
}
V_211 = V_31 -> V_59 -> V_218 ;
if ( ( V_451 -> V_232 >= V_211 ) && V_211 ) {
V_175 = 0 ;
V_233 = ( T_1 T_2 * ) ( unsigned long ) ( V_451 -> V_233 ) ;
V_234 = ( T_3 T_2 * ) ( unsigned long )
( V_451 -> V_234 ) ;
for ( V_8 = 0 ; V_8 < V_211 ; V_8 ++ ) {
if ( F_96 ( V_31 -> V_59 -> V_235 [ V_8 ] ,
V_233 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
if ( F_96 ( V_31 -> V_59 -> V_236 [ V_8 ] ,
V_234 + V_175 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_175 ++ ;
}
}
V_451 -> V_232 = V_211 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_146 ( struct V_1 * V_2 , void * V_164 ,
struct V_165 * V_166 )
{
struct V_446 * V_451 = V_164 ;
struct V_30 * V_452 ;
struct V_30 * V_453 ;
struct V_101 * V_397 ;
int V_33 = - V_182 ;
int V_8 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_452 = F_24 ( V_2 , V_451 -> V_448 , V_451 -> V_32 ) ;
if ( ! V_452 )
goto V_46;
if ( ! V_452 -> V_59 )
goto V_46;
for ( V_8 = 0 ; V_8 < V_452 -> V_59 -> V_218 ; V_8 ++ )
if ( V_452 -> V_59 -> V_235 [ V_8 ] == V_451 -> V_428 )
break;
if ( V_8 == V_452 -> V_59 -> V_218 )
goto V_46;
V_453 = F_24 ( V_2 , V_451 -> V_428 ,
V_399 ) ;
if ( ! V_453 )
goto V_46;
V_397 = F_138 ( V_453 ) ;
if ( ! F_144 ( V_397 , V_451 -> V_410 ) )
goto V_46;
switch ( V_452 -> type ) {
case V_68 :
V_33 = F_147 ( V_452 , V_397 ,
V_451 -> V_410 ) ;
break;
case V_58 :
V_33 = F_148 ( V_452 , V_397 , V_451 -> V_410 ) ;
break;
case V_93 :
V_33 = F_149 ( V_452 , V_397 , V_451 -> V_410 ) ;
break;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_151 ( struct V_19 * V_20 ,
struct V_11 * V_12 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_219 ; V_8 ++ ) {
if ( V_20 -> V_220 [ V_8 ] == 0 ) {
V_20 -> V_220 [ V_8 ] = V_12 -> V_17 . V_18 ;
return 0 ;
}
}
return - V_95 ;
}
void F_152 ( struct V_19 * V_20 ,
struct V_11 * V_12 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_219 ; V_8 ++ ) {
if ( V_20 -> V_220 [ V_8 ] == V_12 -> V_17 . V_18 ) {
V_20 -> V_220 [ V_8 ] = 0 ;
if ( V_20 -> V_12 == V_12 )
V_20 -> V_12 = NULL ;
break;
}
}
}
int F_153 ( struct V_3 * V_4 ,
int V_205 )
{
V_4 -> V_205 = V_205 ;
V_4 -> V_62 = F_78 ( V_205 * sizeof( V_454 ) * 3 , V_36 ) ;
if ( ! V_4 -> V_62 ) {
V_4 -> V_205 = 0 ;
return - V_95 ;
}
return 0 ;
}
int F_154 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_455 * V_456 = V_164 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
void * V_457 , * V_458 , * V_459 ;
int V_440 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_456 -> V_177 , V_58 ) ;
if ( ! V_31 ) {
V_33 = - V_182 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
if ( V_4 -> V_42 -> V_460 == NULL ) {
V_33 = - V_394 ;
goto V_46;
}
if ( V_456 -> V_205 != V_4 -> V_205 ) {
V_33 = - V_182 ;
goto V_46;
}
V_440 = V_456 -> V_205 * ( sizeof( V_454 ) ) ;
V_457 = V_4 -> V_62 ;
if ( F_131 ( V_457 , ( void T_2 * ) ( unsigned long ) V_456 -> V_461 , V_440 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_458 = V_457 + V_440 ;
if ( F_131 ( V_458 , ( void T_2 * ) ( unsigned long ) V_456 -> V_462 , V_440 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_459 = V_458 + V_440 ;
if ( F_131 ( V_459 , ( void T_2 * ) ( unsigned long ) V_456 -> V_463 , V_440 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_4 -> V_42 -> V_460 ( V_4 , V_457 , V_458 , V_459 , 0 , V_4 -> V_205 ) ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_155 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_455 * V_456 = V_164 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
void * V_457 , * V_458 , * V_459 ;
int V_440 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_181 ) )
return - V_182 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_456 -> V_177 , V_58 ) ;
if ( ! V_31 ) {
V_33 = - V_182 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
if ( V_456 -> V_205 != V_4 -> V_205 ) {
V_33 = - V_182 ;
goto V_46;
}
V_440 = V_456 -> V_205 * ( sizeof( V_454 ) ) ;
V_457 = V_4 -> V_62 ;
if ( F_101 ( ( void T_2 * ) ( unsigned long ) V_456 -> V_461 , V_457 , V_440 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_458 = V_457 + V_440 ;
if ( F_101 ( ( void T_2 * ) ( unsigned long ) V_456 -> V_462 , V_458 , V_440 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_459 = V_458 + V_440 ;
if ( F_101 ( ( void T_2 * ) ( unsigned long ) V_456 -> V_463 , V_459 , V_440 ) ) {
V_33 = - V_186 ;
goto V_46;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_156 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_464 * V_465 = V_164 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
struct V_39 * V_40 = NULL , * V_256 = NULL ;
struct V_466 * V_467 = NULL ;
unsigned long V_160 ;
int V_148 , V_154 ;
int V_33 = - V_182 ;
if ( V_465 -> V_160 & ~ V_468 ||
V_465 -> V_469 != 0 )
return - V_182 ;
if ( ( V_465 -> V_160 & V_470 ) && ! V_2 -> V_5 . V_471 )
return - V_182 ;
V_31 = F_24 ( V_2 , V_465 -> V_177 , V_58 ) ;
if ( ! V_31 )
return - V_182 ;
V_4 = F_98 ( V_31 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_40 == NULL ) {
V_33 = - V_472 ;
goto V_46;
}
if ( V_4 -> V_42 -> V_465 == NULL )
goto V_46;
V_40 = F_35 ( V_2 , V_465 -> V_176 ) ;
if ( ! V_40 )
goto V_46;
V_148 = V_4 -> V_64 . V_148 ;
V_154 = V_4 -> V_64 . V_154 ;
if ( V_4 -> V_57 )
F_110 ( V_148 , V_154 ) ;
if ( V_148 > V_40 -> V_260 ||
V_154 > V_40 -> V_261 ||
V_4 -> V_203 > V_40 -> V_260 - V_148 ||
V_4 -> V_204 > V_40 -> V_261 - V_154 ) {
F_75 ( L_46 ,
V_40 -> V_260 , V_40 -> V_261 , V_148 , V_154 , V_4 -> V_203 , V_4 -> V_204 ,
V_4 -> V_57 ? L_47 : L_48 ) ;
V_33 = - V_266 ;
goto V_46;
}
if ( V_4 -> V_40 -> V_259 != V_40 -> V_259 ) {
F_75 ( L_66 ) ;
V_33 = - V_182 ;
goto V_46;
}
if ( V_465 -> V_160 & V_473 ) {
V_33 = - V_95 ;
F_157 ( & V_2 -> V_474 , V_160 ) ;
if ( V_166 -> V_475 < sizeof V_467 -> V_476 ) {
F_158 ( & V_2 -> V_474 , V_160 ) ;
goto V_46;
}
V_166 -> V_475 -= sizeof V_467 -> V_476 ;
F_158 ( & V_2 -> V_474 , V_160 ) ;
V_467 = F_78 ( sizeof *V_467 , V_36 ) ;
if ( V_467 == NULL ) {
F_157 ( & V_2 -> V_474 , V_160 ) ;
V_166 -> V_475 += sizeof V_467 -> V_476 ;
F_158 ( & V_2 -> V_474 , V_160 ) ;
goto V_46;
}
V_467 -> V_476 . V_17 . type = V_477 ;
V_467 -> V_476 . V_17 . V_433 = sizeof V_467 -> V_476 ;
V_467 -> V_476 . V_478 = V_465 -> V_478 ;
V_467 -> V_17 . V_476 = & V_467 -> V_476 . V_17 ;
V_467 -> V_17 . V_166 = V_166 ;
V_467 -> V_17 . V_51 =
( void ( * ) ( struct V_479 * ) ) F_57 ;
}
V_256 = V_4 -> V_40 ;
V_33 = V_4 -> V_42 -> V_465 ( V_4 , V_40 , V_467 , V_465 -> V_160 ) ;
if ( V_33 ) {
if ( V_465 -> V_160 & V_473 ) {
F_157 ( & V_2 -> V_474 , V_160 ) ;
V_166 -> V_475 += sizeof V_467 -> V_476 ;
F_158 ( & V_2 -> V_474 , V_160 ) ;
F_57 ( V_467 ) ;
}
V_256 = NULL ;
} else {
F_8 ( V_4 -> V_40 != V_40 ) ;
V_40 = NULL ;
}
V_46:
if ( V_40 )
F_36 ( V_40 ) ;
if ( V_256 )
F_36 ( V_256 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_33 ;
}
void F_159 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_19 * V_20 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
if ( V_4 -> V_42 -> V_480 )
V_4 -> V_42 -> V_480 ( V_4 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
if ( V_12 -> V_42 -> V_480 )
V_12 -> V_42 -> V_480 ( V_12 ) ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_20 -> V_24 = V_71 ;
if ( V_20 -> V_42 -> V_480 )
V_20 -> V_42 -> V_480 ( V_20 ) ;
}
}
int F_160 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_481 * args = V_164 ;
if ( ! V_2 -> V_482 -> V_483 )
return - V_394 ;
return V_2 -> V_482 -> V_483 ( V_166 , V_2 , args ) ;
}
int F_161 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_484 * args = V_164 ;
if ( ! V_2 -> V_482 -> V_485 )
return - V_394 ;
return V_2 -> V_482 -> V_485 ( V_166 , V_2 , args -> V_288 , & args -> V_486 ) ;
}
int F_162 ( struct V_1 * V_2 ,
void * V_164 , struct V_165 * V_166 )
{
struct V_487 * args = V_164 ;
if ( ! V_2 -> V_482 -> V_488 )
return - V_394 ;
return V_2 -> V_482 -> V_488 ( V_166 , V_2 , args -> V_288 ) ;
}
void F_163 ( T_1 V_28 , unsigned int * V_296 ,
int * V_295 )
{
switch ( V_28 ) {
case V_298 :
case V_314 :
case V_315 :
* V_296 = 8 ;
* V_295 = 8 ;
break;
case V_299 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
* V_296 = 15 ;
* V_295 = 16 ;
break;
case V_300 :
case V_331 :
* V_296 = 16 ;
* V_295 = 16 ;
break;
case V_301 :
case V_332 :
* V_296 = 24 ;
* V_295 = 24 ;
break;
case V_302 :
case V_333 :
case V_334 :
case V_335 :
* V_296 = 24 ;
* V_295 = 32 ;
break;
case V_303 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
* V_296 = 30 ;
* V_295 = 32 ;
break;
case V_304 :
case V_336 :
case V_337 :
case V_338 :
* V_296 = 32 ;
* V_295 = 32 ;
break;
default:
F_75 ( L_67 ) ;
* V_296 = 0 ;
* V_295 = 0 ;
break;
}
}
int F_123 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
return 3 ;
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
return 2 ;
default:
return 1 ;
}
}
int F_124 ( T_1 V_28 , int V_53 )
{
unsigned int V_296 ;
int V_295 ;
if ( V_53 >= F_123 ( V_28 ) )
return 0 ;
switch ( V_28 ) {
case V_346 :
case V_347 :
case V_348 :
case V_349 :
return 2 ;
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
return V_53 ? 2 : 1 ;
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
return 1 ;
default:
F_163 ( V_28 , & V_296 , & V_295 ) ;
return V_295 >> 3 ;
}
}
int F_121 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_359 :
case V_360 :
case V_357 :
case V_358 :
return 4 ;
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_363 :
case V_364 :
case V_361 :
case V_362 :
return 2 ;
default:
return 1 ;
}
}
int F_122 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_357 :
case V_358 :
return 4 ;
case V_361 :
case V_362 :
case V_351 :
case V_352 :
return 2 ;
default:
return 1 ;
}
}
void F_164 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_5 . V_6 ) ;
F_54 ( & V_2 -> V_5 . V_34 ) ;
F_54 ( & V_2 -> V_5 . V_43 ) ;
F_28 ( & V_2 -> V_5 . V_49 ) ;
F_28 ( & V_2 -> V_5 . V_60 ) ;
F_28 ( & V_2 -> V_5 . V_72 ) ;
F_28 ( & V_2 -> V_5 . V_82 ) ;
F_28 ( & V_2 -> V_5 . V_86 ) ;
F_28 ( & V_2 -> V_5 . V_402 ) ;
F_28 ( & V_2 -> V_5 . V_436 ) ;
F_28 ( & V_2 -> V_5 . V_96 ) ;
F_165 ( & V_2 -> V_5 . V_35 ) ;
F_1 ( V_2 ) ;
F_79 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_5 . V_47 = 0 ;
V_2 -> V_5 . V_73 = 0 ;
V_2 -> V_5 . V_61 = 0 ;
V_2 -> V_5 . V_87 = 0 ;
}
void F_166 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_489 ;
struct V_3 * V_4 , * V_490 ;
struct V_11 * V_12 , * V_491 ;
struct V_78 * V_79 , * V_492 ;
struct V_39 * V_40 , * V_493 ;
struct V_101 * V_397 , * V_413 ;
struct V_423 * V_434 , * V_494 ;
struct V_52 * V_53 , * V_495 ;
F_65 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_12 -> V_42 -> V_51 ( V_12 ) ;
}
F_65 (bridge, brt,
&dev->mode_config.bridge_list, head) {
V_79 -> V_42 -> V_51 ( V_79 ) ;
}
F_65 (connector, ot,
&dev->mode_config.connector_list, head) {
V_20 -> V_42 -> V_51 ( V_20 ) ;
}
F_65 (property, pt, &dev->mode_config.property_list,
head) {
F_133 ( V_2 , V_397 ) ;
}
F_65 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_140 ( V_2 , V_434 ) ;
}
F_8 ( ! F_48 ( & V_2 -> V_5 . V_49 ) ) ;
F_65 (fb, fbt, &dev->mode_config.fb_list, head) {
F_47 ( V_40 ) ;
}
F_65 (plane, plt, &dev->mode_config.plane_list,
head) {
V_53 -> V_42 -> V_51 ( V_53 ) ;
}
F_65 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_4 -> V_42 -> V_51 ( V_4 ) ;
}
F_167 ( & V_2 -> V_5 . V_35 ) ;
}
