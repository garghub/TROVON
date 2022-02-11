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
if ( ( V_147 -> V_160 & V_164 ) > V_165 )
return - V_166 ;
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
int F_93 ( struct V_1 * V_2 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_170 * V_171 = V_167 ;
struct V_172 * V_173 ;
struct V_39 * V_40 ;
struct V_19 * V_20 ;
struct V_3 * V_4 ;
struct V_11 * V_12 ;
int V_33 = 0 ;
int V_174 = 0 ;
int V_175 = 0 ;
int V_176 = 0 ;
int V_177 = 0 ;
int V_178 = 0 , V_8 ;
T_1 T_2 * V_179 ;
T_1 T_2 * V_180 ;
T_1 T_2 * V_181 ;
T_1 T_2 * V_182 ;
struct V_138 * V_183 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_2 ( & V_169 -> V_185 ) ;
F_95 (lh, &file_priv->fbs)
V_176 ++ ;
if ( V_171 -> V_186 >= V_176 ) {
V_178 = 0 ;
V_179 = ( T_1 T_2 * ) ( unsigned long ) V_171 -> V_187 ;
F_3 (fb, &file_priv->fbs, filp_head) {
if ( F_96 ( V_40 -> V_17 . V_18 , V_179 + V_178 ) ) {
F_6 ( & V_169 -> V_185 ) ;
return - V_188 ;
}
V_178 ++ ;
}
}
V_171 -> V_186 = V_176 ;
F_6 ( & V_169 -> V_185 ) ;
F_1 ( V_2 ) ;
V_183 = & V_169 -> V_189 -> V_190 -> V_183 ;
if ( V_169 -> V_189 -> V_190 -> type == V_191 ) {
F_95 (lh, &dev->mode_config.crtc_list)
V_175 ++ ;
F_95 (lh, &dev->mode_config.connector_list)
V_174 ++ ;
F_95 (lh, &dev->mode_config.encoder_list)
V_177 ++ ;
} else {
V_175 = V_183 -> V_142 ;
V_174 = V_183 -> V_143 ;
V_177 = V_183 -> V_144 ;
}
V_171 -> V_192 = V_2 -> V_5 . V_192 ;
V_171 -> V_193 = V_2 -> V_5 . V_193 ;
V_171 -> V_194 = V_2 -> V_5 . V_194 ;
V_171 -> V_195 = V_2 -> V_5 . V_195 ;
if ( V_171 -> V_196 >= V_175 ) {
V_178 = 0 ;
V_180 = ( T_1 T_2 * ) ( unsigned long ) V_171 -> V_197 ;
if ( V_169 -> V_189 -> V_190 -> type == V_191 ) {
F_3 (crtc, &dev->mode_config.crtc_list,
head) {
F_75 ( L_30 , V_4 -> V_17 . V_18 ) ;
if ( F_96 ( V_4 -> V_17 . V_18 , V_180 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
} else {
for ( V_8 = 0 ; V_8 < V_183 -> V_142 ; V_8 ++ ) {
if ( F_96 ( V_183 -> V_141 [ V_8 ] ,
V_180 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
}
}
V_171 -> V_196 = V_175 ;
if ( V_171 -> V_198 >= V_177 ) {
V_178 = 0 ;
V_182 = ( T_1 T_2 * ) ( unsigned long ) V_171 -> V_199 ;
if ( V_169 -> V_189 -> V_190 -> type == V_191 ) {
F_3 (encoder,
&dev->mode_config.encoder_list,
head) {
F_75 ( L_31 , V_12 -> V_17 . V_18 ,
F_15 ( V_12 ) ) ;
if ( F_96 ( V_12 -> V_17 . V_18 , V_182 +
V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
} else {
for ( V_8 = V_183 -> V_142 ; V_8 < V_183 -> V_142 + V_183 -> V_144 ; V_8 ++ ) {
if ( F_96 ( V_183 -> V_141 [ V_8 ] ,
V_182 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
}
}
V_171 -> V_198 = V_177 ;
if ( V_171 -> V_200 >= V_174 ) {
V_178 = 0 ;
V_181 = ( T_1 T_2 * ) ( unsigned long ) V_171 -> V_201 ;
if ( V_169 -> V_189 -> V_190 -> type == V_191 ) {
F_3 (connector,
&dev->mode_config.connector_list,
head) {
F_75 ( L_32 ,
V_20 -> V_17 . V_18 ,
F_16 ( V_20 ) ) ;
if ( F_96 ( V_20 -> V_17 . V_18 ,
V_181 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
} else {
int V_202 = V_183 -> V_142 +
V_183 -> V_144 ;
for ( V_8 = V_202 ; V_8 < V_202 + V_183 -> V_143 ; V_8 ++ ) {
if ( F_96 ( V_183 -> V_141 [ V_8 ] ,
V_181 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
}
}
V_171 -> V_200 = V_174 ;
F_75 ( L_33 , V_171 -> V_196 ,
V_171 -> V_200 , V_171 -> V_198 ) ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_97 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_203 * V_204 = V_167 ;
struct V_3 * V_4 ;
struct V_30 * V_31 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_204 -> V_180 ,
V_58 ) ;
if ( ! V_31 ) {
V_33 = - V_205 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
V_204 -> V_206 = V_4 -> V_206 ;
V_204 -> V_207 = V_4 -> V_207 ;
V_204 -> V_208 = V_4 -> V_208 ;
if ( V_4 -> V_40 )
V_204 -> V_179 = V_4 -> V_40 -> V_17 . V_18 ;
else
V_204 -> V_179 = 0 ;
if ( V_4 -> V_209 ) {
F_90 ( & V_204 -> V_64 , & V_4 -> V_64 ) ;
V_204 -> V_210 = 1 ;
} else {
V_204 -> V_210 = 0 ;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
static bool F_99 ( const struct V_63 * V_64 ,
const struct V_168 * V_169 )
{
if ( ! V_169 -> V_211 && F_100 ( V_64 ) )
return false ;
return true ;
}
int F_101 ( struct V_1 * V_2 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_212 * V_213 = V_167 ;
struct V_30 * V_31 ;
struct V_19 * V_20 ;
struct V_63 * V_64 ;
int V_214 = 0 ;
int V_215 = 0 ;
int V_216 = 0 ;
int V_33 = 0 ;
int V_178 = 0 ;
int V_8 ;
struct V_146 V_217 ;
struct V_146 T_2 * V_218 ;
T_1 T_2 * V_219 ;
T_3 T_2 * V_220 ;
T_1 T_2 * V_221 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
memset ( & V_217 , 0 , sizeof( struct V_146 ) ) ;
F_75 ( L_34 , V_213 -> V_181 ) ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_31 = F_24 ( V_2 , V_213 -> V_181 ,
V_68 ) ;
if ( ! V_31 ) {
V_33 = - V_205 ;
goto V_46;
}
V_20 = F_102 ( V_31 ) ;
V_215 = V_20 -> V_59 . V_222 ;
for ( V_8 = 0 ; V_8 < V_223 ; V_8 ++ ) {
if ( V_20 -> V_224 [ V_8 ] != 0 ) {
V_216 ++ ;
}
}
if ( V_213 -> V_225 == 0 ) {
V_20 -> V_42 -> V_226 ( V_20 ,
V_2 -> V_5 . V_194 ,
V_2 -> V_5 . V_192 ) ;
}
F_3 (mode, &connector->modes, head)
if ( F_99 ( V_64 , V_169 ) )
V_214 ++ ;
V_213 -> V_181 = V_20 -> V_17 . V_18 ;
V_213 -> V_21 = V_20 -> V_21 ;
V_213 -> V_22 = V_20 -> V_22 ;
V_213 -> V_227 = V_20 -> V_228 . V_229 ;
V_213 -> V_230 = V_20 -> V_228 . V_231 ;
V_213 -> V_232 = V_20 -> V_228 . V_233 ;
V_213 -> V_234 = V_20 -> V_24 ;
if ( V_20 -> V_12 )
V_213 -> V_182 = V_20 -> V_12 -> V_17 . V_18 ;
else
V_213 -> V_182 = 0 ;
if ( ( V_213 -> V_225 >= V_214 ) && V_214 ) {
V_178 = 0 ;
V_218 = (struct V_146 T_2 * ) ( unsigned long ) V_213 -> V_235 ;
F_3 (mode, &connector->modes, head) {
if ( ! F_99 ( V_64 , V_169 ) )
continue;
F_90 ( & V_217 , V_64 ) ;
if ( F_103 ( V_218 + V_178 ,
& V_217 , sizeof( V_217 ) ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
}
V_213 -> V_225 = V_214 ;
if ( ( V_213 -> V_236 >= V_215 ) && V_215 ) {
V_178 = 0 ;
V_219 = ( T_1 T_2 * ) ( unsigned long ) ( V_213 -> V_237 ) ;
V_220 = ( T_3 T_2 * ) ( unsigned long ) ( V_213 -> V_238 ) ;
for ( V_8 = 0 ; V_8 < V_20 -> V_59 . V_222 ; V_8 ++ ) {
if ( F_96 ( V_20 -> V_59 . V_239 [ V_8 ] ,
V_219 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
if ( F_96 ( V_20 -> V_59 . V_240 [ V_8 ] ,
V_220 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
}
V_213 -> V_236 = V_215 ;
if ( ( V_213 -> V_198 >= V_216 ) && V_216 ) {
V_178 = 0 ;
V_221 = ( T_1 T_2 * ) ( unsigned long ) ( V_213 -> V_241 ) ;
for ( V_8 = 0 ; V_8 < V_223 ; V_8 ++ ) {
if ( V_20 -> V_224 [ V_8 ] != 0 ) {
if ( F_96 ( V_20 -> V_224 [ V_8 ] ,
V_221 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
}
}
V_213 -> V_198 = V_216 ;
V_46:
F_6 ( & V_2 -> V_5 . V_6 ) ;
return V_33 ;
}
int F_104 ( struct V_1 * V_2 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_242 * V_243 = V_167 ;
struct V_30 * V_31 ;
struct V_11 * V_12 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_243 -> V_182 ,
V_85 ) ;
if ( ! V_31 ) {
V_33 = - V_205 ;
goto V_46;
}
V_12 = F_105 ( V_31 ) ;
if ( V_12 -> V_4 )
V_243 -> V_180 = V_12 -> V_4 -> V_17 . V_18 ;
else
V_243 -> V_180 = 0 ;
V_243 -> V_15 = V_12 -> V_15 ;
V_243 -> V_182 = V_12 -> V_17 . V_18 ;
V_243 -> V_88 = V_12 -> V_88 ;
V_243 -> V_244 = V_12 -> V_244 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_106 ( struct V_1 * V_2 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_245 * V_246 = V_167 ;
struct V_247 * V_248 ;
struct V_52 * V_53 ;
T_1 T_2 * V_249 ;
int V_178 = 0 , V_33 = 0 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_248 = & V_2 -> V_5 ;
if ( V_248 -> V_97 &&
( V_246 -> V_250 >= V_248 -> V_97 ) ) {
V_249 = ( T_1 T_2 * ) ( unsigned long ) V_246 -> V_251 ;
F_3 (plane, &config->plane_list, head) {
if ( F_96 ( V_53 -> V_17 . V_18 , V_249 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
}
V_246 -> V_250 = V_248 -> V_97 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_107 ( struct V_1 * V_2 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_252 * V_246 = V_167 ;
struct V_30 * V_31 ;
struct V_52 * V_53 ;
T_1 T_2 * V_253 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_246 -> V_254 ,
V_93 ) ;
if ( ! V_31 ) {
V_33 = - V_205 ;
goto V_46;
}
V_53 = F_108 ( V_31 ) ;
if ( V_53 -> V_4 )
V_246 -> V_180 = V_53 -> V_4 -> V_17 . V_18 ;
else
V_246 -> V_180 = 0 ;
if ( V_53 -> V_40 )
V_246 -> V_179 = V_53 -> V_40 -> V_17 . V_18 ;
else
V_246 -> V_179 = 0 ;
V_246 -> V_254 = V_53 -> V_17 . V_18 ;
V_246 -> V_88 = V_53 -> V_88 ;
V_246 -> V_208 = 0 ;
if ( V_53 -> V_91 &&
( V_246 -> V_255 >= V_53 -> V_91 ) ) {
V_253 = ( T_1 T_2 * ) ( unsigned long ) V_246 -> V_256 ;
if ( F_103 ( V_253 ,
V_53 -> V_94 ,
sizeof( T_1 ) * V_53 -> V_91 ) ) {
V_33 = - V_188 ;
goto V_46;
}
}
V_246 -> V_255 = V_53 -> V_91 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_109 ( struct V_1 * V_2 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_257 * V_258 = V_167 ;
struct V_30 * V_31 ;
struct V_52 * V_53 ;
struct V_3 * V_4 ;
struct V_39 * V_40 = NULL , * V_259 = NULL ;
int V_33 = 0 ;
unsigned int V_260 , V_261 ;
int V_8 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
V_31 = F_24 ( V_2 , V_258 -> V_254 ,
V_93 ) ;
if ( ! V_31 ) {
F_75 ( L_35 ,
V_258 -> V_254 ) ;
return - V_205 ;
}
V_53 = F_108 ( V_31 ) ;
if ( ! V_258 -> V_179 ) {
F_1 ( V_2 ) ;
V_259 = V_53 -> V_40 ;
V_53 -> V_42 -> V_98 ( V_53 ) ;
V_53 -> V_4 = NULL ;
V_53 -> V_40 = NULL ;
F_5 ( V_2 ) ;
goto V_46;
}
V_31 = F_24 ( V_2 , V_258 -> V_180 ,
V_58 ) ;
if ( ! V_31 ) {
F_75 ( L_36 ,
V_258 -> V_180 ) ;
V_33 = - V_205 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
V_40 = F_35 ( V_2 , V_258 -> V_179 ) ;
if ( ! V_40 ) {
F_75 ( L_37 ,
V_258 -> V_179 ) ;
V_33 = - V_205 ;
goto V_46;
}
for ( V_8 = 0 ; V_8 < V_53 -> V_91 ; V_8 ++ )
if ( V_40 -> V_262 == V_53 -> V_94 [ V_8 ] )
break;
if ( V_8 == V_53 -> V_91 ) {
F_75 ( L_38 ,
F_19 ( V_40 -> V_262 ) ) ;
V_33 = - V_166 ;
goto V_46;
}
V_260 = V_40 -> V_263 << 16 ;
V_261 = V_40 -> V_264 << 16 ;
if ( V_258 -> V_265 > V_260 ||
V_258 -> V_266 > V_260 - V_258 -> V_265 ||
V_258 -> V_267 > V_261 ||
V_258 -> V_268 > V_261 - V_258 -> V_267 ) {
F_75 ( L_39
L_40 ,
V_258 -> V_265 >> 16 ,
( ( V_258 -> V_265 & 0xffff ) * 15625 ) >> 10 ,
V_258 -> V_267 >> 16 ,
( ( V_258 -> V_267 & 0xffff ) * 15625 ) >> 10 ,
V_258 -> V_266 >> 16 ,
( ( V_258 -> V_266 & 0xffff ) * 15625 ) >> 10 ,
V_258 -> V_268 >> 16 ,
( ( V_258 -> V_268 & 0xffff ) * 15625 ) >> 10 ) ;
V_33 = - V_269 ;
goto V_46;
}
if ( V_258 -> V_270 > V_162 ||
V_258 -> V_271 > V_162 - ( V_272 ) V_258 -> V_270 ||
V_258 -> V_273 > V_162 ||
V_258 -> V_274 > V_162 - ( V_272 ) V_258 -> V_273 ) {
F_75 ( L_41 ,
V_258 -> V_270 , V_258 -> V_273 ,
V_258 -> V_271 , V_258 -> V_274 ) ;
V_33 = - V_163 ;
goto V_46;
}
F_1 ( V_2 ) ;
V_33 = V_53 -> V_42 -> V_275 ( V_53 , V_4 , V_40 ,
V_258 -> V_271 , V_258 -> V_274 ,
V_258 -> V_270 , V_258 -> V_273 ,
V_258 -> V_266 , V_258 -> V_268 ,
V_258 -> V_265 , V_258 -> V_267 ) ;
if ( ! V_33 ) {
V_259 = V_53 -> V_40 ;
V_53 -> V_4 = V_4 ;
V_53 -> V_40 = V_40 ;
V_40 = NULL ;
}
F_5 ( V_2 ) ;
V_46:
if ( V_40 )
F_36 ( V_40 ) ;
if ( V_259 )
F_36 ( V_259 ) ;
return V_33 ;
}
int F_50 ( struct V_54 * V_55 )
{
struct V_3 * V_4 = V_55 -> V_4 ;
struct V_39 * V_40 ;
struct V_3 * V_276 ;
int V_33 ;
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head)
V_276 -> V_259 = V_276 -> V_40 ;
V_40 = V_55 -> V_40 ;
V_33 = V_4 -> V_42 -> V_277 ( V_55 ) ;
if ( V_33 == 0 ) {
F_8 ( V_40 != V_4 -> V_40 ) ;
}
F_3 (tmp, &crtc->dev->mode_config.crtc_list, head) {
if ( V_276 -> V_40 )
F_29 ( V_276 -> V_40 ) ;
if ( V_276 -> V_259 )
F_36 ( V_276 -> V_259 ) ;
}
return V_33 ;
}
static int F_110 ( const struct V_3 * V_4 ,
int V_206 , int V_207 ,
const struct V_63 * V_64 ,
const struct V_39 * V_40 )
{
int V_148 , V_154 ;
V_148 = V_64 -> V_148 ;
V_154 = V_64 -> V_154 ;
if ( F_100 ( V_64 ) ) {
struct V_63 V_278 = * V_64 ;
F_111 ( & V_278 , V_279 ) ;
V_148 = V_278 . V_280 ;
V_154 = V_278 . V_281 ;
}
if ( V_4 -> V_57 )
F_112 ( V_148 , V_154 ) ;
if ( V_148 > V_40 -> V_263 ||
V_154 > V_40 -> V_264 ||
V_206 > V_40 -> V_263 - V_148 ||
V_207 > V_40 -> V_264 - V_154 ) {
F_75 ( L_42 ,
V_40 -> V_263 , V_40 -> V_264 , V_148 , V_154 , V_206 , V_207 ,
V_4 -> V_57 ? L_43 : L_44 ) ;
return - V_269 ;
}
return 0 ;
}
int F_113 ( struct V_1 * V_2 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_247 * V_248 = & V_2 -> V_5 ;
struct V_203 * V_282 = V_167 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
struct V_19 * * V_283 = NULL , * V_20 ;
struct V_39 * V_40 = NULL ;
struct V_63 * V_64 = NULL ;
struct V_54 V_55 ;
T_1 T_2 * V_284 ;
int V_33 ;
int V_8 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
if ( V_282 -> V_206 > V_162 || V_282 -> V_207 > V_162 )
return - V_163 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_282 -> V_180 ,
V_58 ) ;
if ( ! V_31 ) {
F_75 ( L_45 , V_282 -> V_180 ) ;
V_33 = - V_205 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
F_75 ( L_30 , V_4 -> V_17 . V_18 ) ;
if ( V_282 -> V_210 ) {
if ( V_282 -> V_179 == - 1 ) {
if ( ! V_4 -> V_40 ) {
F_75 ( L_46 ) ;
V_33 = - V_166 ;
goto V_46;
}
V_40 = V_4 -> V_40 ;
F_29 ( V_40 ) ;
} else {
V_40 = F_35 ( V_2 , V_282 -> V_179 ) ;
if ( ! V_40 ) {
F_75 ( L_47 ,
V_282 -> V_179 ) ;
V_33 = - V_205 ;
goto V_46;
}
}
V_64 = F_77 ( V_2 ) ;
if ( ! V_64 ) {
V_33 = - V_95 ;
goto V_46;
}
V_33 = F_92 ( V_64 , & V_282 -> V_64 ) ;
if ( V_33 ) {
F_75 ( L_48 ) ;
goto V_46;
}
F_111 ( V_64 , V_285 ) ;
V_33 = F_110 ( V_4 , V_282 -> V_206 , V_282 -> V_207 ,
V_64 , V_40 ) ;
if ( V_33 )
goto V_46;
}
if ( V_282 -> V_200 == 0 && V_64 ) {
F_75 ( L_49 ) ;
V_33 = - V_166 ;
goto V_46;
}
if ( V_282 -> V_200 > 0 && ( ! V_64 || ! V_40 ) ) {
F_75 ( L_50 ,
V_282 -> V_200 ) ;
V_33 = - V_166 ;
goto V_46;
}
if ( V_282 -> V_200 > 0 ) {
T_4 V_286 ;
if ( V_282 -> V_200 > V_248 -> V_73 ) {
V_33 = - V_166 ;
goto V_46;
}
V_283 = F_74 ( V_282 -> V_200 *
sizeof( struct V_19 * ) ,
V_36 ) ;
if ( ! V_283 ) {
V_33 = - V_95 ;
goto V_46;
}
for ( V_8 = 0 ; V_8 < V_282 -> V_200 ; V_8 ++ ) {
V_284 = ( T_1 T_2 * ) ( unsigned long ) V_282 -> V_284 ;
if ( F_114 ( V_286 , & V_284 [ V_8 ] ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_31 = F_24 ( V_2 , V_286 ,
V_68 ) ;
if ( ! V_31 ) {
F_75 ( L_51 ,
V_286 ) ;
V_33 = - V_205 ;
goto V_46;
}
V_20 = F_102 ( V_31 ) ;
F_75 ( L_32 ,
V_20 -> V_17 . V_18 ,
F_16 ( V_20 ) ) ;
V_283 [ V_8 ] = V_20 ;
}
}
V_55 . V_4 = V_4 ;
V_55 . V_206 = V_282 -> V_206 ;
V_55 . V_207 = V_282 -> V_207 ;
V_55 . V_64 = V_64 ;
V_55 . V_287 = V_283 ;
V_55 . V_143 = V_282 -> V_200 ;
V_55 . V_40 = V_40 ;
V_33 = F_50 ( & V_55 ) ;
V_46:
if ( V_40 )
F_36 ( V_40 ) ;
F_57 ( V_283 ) ;
F_60 ( V_2 , V_64 ) ;
F_5 ( V_2 ) ;
return V_33 ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_288 * V_289 ,
struct V_168 * V_169 )
{
struct V_30 * V_31 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
if ( ! V_289 -> V_160 || ( ~ V_290 & V_289 -> V_160 ) )
return - V_166 ;
V_31 = F_24 ( V_2 , V_289 -> V_180 , V_58 ) ;
if ( ! V_31 ) {
F_75 ( L_45 , V_289 -> V_180 ) ;
return - V_205 ;
}
V_4 = F_98 ( V_31 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_289 -> V_160 & V_291 ) {
if ( ! V_4 -> V_42 -> V_292 && ! V_4 -> V_42 -> V_293 ) {
V_33 = - V_294 ;
goto V_46;
}
if ( V_4 -> V_42 -> V_293 )
V_33 = V_4 -> V_42 -> V_293 ( V_4 , V_169 , V_289 -> V_295 ,
V_289 -> V_263 , V_289 -> V_264 , V_289 -> V_296 , V_289 -> V_297 ) ;
else
V_33 = V_4 -> V_42 -> V_292 ( V_4 , V_169 , V_289 -> V_295 ,
V_289 -> V_263 , V_289 -> V_264 ) ;
}
if ( V_289 -> V_160 & V_298 ) {
if ( V_4 -> V_42 -> V_299 ) {
V_33 = V_4 -> V_42 -> V_299 ( V_4 , V_289 -> V_206 , V_289 -> V_207 ) ;
} else {
V_33 = - V_188 ;
goto V_46;
}
}
V_46:
F_6 ( & V_4 -> V_6 ) ;
return V_33 ;
}
int F_116 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_300 * V_289 = V_167 ;
struct V_288 V_301 ;
memcpy ( & V_301 , V_289 , sizeof( struct V_300 ) ) ;
V_301 . V_296 = V_301 . V_297 = 0 ;
return F_115 ( V_2 , & V_301 , V_169 ) ;
}
int F_117 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_288 * V_289 = V_167 ;
return F_115 ( V_2 , V_289 , V_169 ) ;
}
T_1 F_118 ( T_1 V_302 , T_1 V_303 )
{
T_1 V_304 ;
switch ( V_302 ) {
case 8 :
V_304 = V_305 ;
break;
case 16 :
if ( V_303 == 15 )
V_304 = V_306 ;
else
V_304 = V_307 ;
break;
case 24 :
V_304 = V_308 ;
break;
case 32 :
if ( V_303 == 24 )
V_304 = V_309 ;
else if ( V_303 == 30 )
V_304 = V_310 ;
else
V_304 = V_311 ;
break;
default:
F_51 ( L_52 ) ;
V_304 = V_309 ;
break;
}
return V_304 ;
}
int F_119 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_312 * V_313 = V_167 ;
struct V_314 V_315 = {} ;
struct V_247 * V_248 = & V_2 -> V_5 ;
struct V_39 * V_40 ;
int V_33 = 0 ;
V_315 . V_179 = V_313 -> V_179 ;
V_315 . V_263 = V_313 -> V_263 ;
V_315 . V_264 = V_313 -> V_264 ;
V_315 . V_316 [ 0 ] = V_313 -> V_317 ;
V_315 . V_262 = F_118 ( V_313 -> V_302 , V_313 -> V_303 ) ;
V_315 . V_318 [ 0 ] = V_313 -> V_295 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
if ( ( V_248 -> V_195 > V_315 . V_263 ) || ( V_315 . V_263 > V_248 -> V_194 ) )
return - V_166 ;
if ( ( V_248 -> V_193 > V_315 . V_264 ) || ( V_315 . V_264 > V_248 -> V_192 ) )
return - V_166 ;
V_40 = V_2 -> V_5 . V_42 -> V_319 ( V_2 , V_169 , & V_315 ) ;
if ( F_120 ( V_40 ) ) {
F_75 ( L_53 ) ;
return F_121 ( V_40 ) ;
}
F_2 ( & V_169 -> V_185 ) ;
V_313 -> V_179 = V_40 -> V_17 . V_18 ;
F_30 ( & V_40 -> V_45 , & V_169 -> V_320 ) ;
F_75 ( L_54 , V_40 -> V_17 . V_18 ) ;
F_6 ( & V_169 -> V_185 ) ;
return V_33 ;
}
static int F_122 ( const struct V_314 * V_315 )
{
T_1 V_28 = V_315 -> V_262 & ~ V_29 ;
switch ( V_28 ) {
case V_305 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_306 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_307 :
case V_338 :
case V_308 :
case V_339 :
case V_309 :
case V_340 :
case V_341 :
case V_342 :
case V_311 :
case V_343 :
case V_344 :
case V_345 :
case V_310 :
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
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
return 0 ;
default:
F_75 ( L_55 ,
F_19 ( V_315 -> V_262 ) ) ;
return - V_166 ;
}
}
static int F_123 ( const struct V_314 * V_315 )
{
int V_33 , V_374 , V_375 , V_376 , V_8 ;
V_33 = F_122 ( V_315 ) ;
if ( V_33 ) {
F_75 ( L_56 ,
F_19 ( V_315 -> V_262 ) ) ;
return V_33 ;
}
V_374 = F_124 ( V_315 -> V_262 ) ;
V_375 = F_125 ( V_315 -> V_262 ) ;
V_376 = F_126 ( V_315 -> V_262 ) ;
if ( V_315 -> V_263 == 0 || V_315 -> V_263 % V_374 ) {
F_75 ( L_57 , V_315 -> V_264 ) ;
return - V_166 ;
}
if ( V_315 -> V_264 == 0 || V_315 -> V_264 % V_375 ) {
F_75 ( L_58 , V_315 -> V_264 ) ;
return - V_166 ;
}
for ( V_8 = 0 ; V_8 < V_376 ; V_8 ++ ) {
unsigned int V_263 = V_315 -> V_263 / ( V_8 != 0 ? V_374 : 1 ) ;
unsigned int V_264 = V_315 -> V_264 / ( V_8 != 0 ? V_375 : 1 ) ;
unsigned int V_377 = F_127 ( V_315 -> V_262 , V_8 ) ;
if ( ! V_315 -> V_318 [ V_8 ] ) {
F_75 ( L_59 , V_8 ) ;
return - V_166 ;
}
if ( ( T_3 ) V_263 * V_377 > V_378 )
return - V_163 ;
if ( ( T_3 ) V_264 * V_315 -> V_316 [ V_8 ] + V_315 -> V_379 [ V_8 ] > V_378 )
return - V_163 ;
if ( V_315 -> V_316 [ V_8 ] < V_263 * V_377 ) {
F_75 ( L_60 , V_315 -> V_316 [ V_8 ] , V_8 ) ;
return - V_166 ;
}
}
return 0 ;
}
int F_128 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_314 * V_315 = V_167 ;
struct V_247 * V_248 = & V_2 -> V_5 ;
struct V_39 * V_40 ;
int V_33 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
if ( V_315 -> V_160 & ~ V_380 ) {
F_75 ( L_61 , V_315 -> V_160 ) ;
return - V_166 ;
}
if ( ( V_248 -> V_195 > V_315 -> V_263 ) || ( V_315 -> V_263 > V_248 -> V_194 ) ) {
F_75 ( L_62 ,
V_315 -> V_263 , V_248 -> V_195 , V_248 -> V_194 ) ;
return - V_166 ;
}
if ( ( V_248 -> V_193 > V_315 -> V_264 ) || ( V_315 -> V_264 > V_248 -> V_192 ) ) {
F_75 ( L_63 ,
V_315 -> V_264 , V_248 -> V_193 , V_248 -> V_192 ) ;
return - V_166 ;
}
V_33 = F_123 ( V_315 ) ;
if ( V_33 )
return V_33 ;
V_40 = V_2 -> V_5 . V_42 -> V_319 ( V_2 , V_169 , V_315 ) ;
if ( F_120 ( V_40 ) ) {
F_75 ( L_53 ) ;
return F_121 ( V_40 ) ;
}
F_2 ( & V_169 -> V_185 ) ;
V_315 -> V_179 = V_40 -> V_17 . V_18 ;
F_30 ( & V_40 -> V_45 , & V_169 -> V_320 ) ;
F_75 ( L_54 , V_40 -> V_17 . V_18 ) ;
F_6 ( & V_169 -> V_185 ) ;
return V_33 ;
}
int F_129 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_39 * V_40 = NULL ;
struct V_39 * V_381 = NULL ;
T_1 * V_18 = V_167 ;
int V_382 = 0 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_2 ( & V_169 -> V_185 ) ;
F_2 ( & V_2 -> V_5 . V_43 ) ;
V_40 = F_33 ( V_2 , * V_18 ) ;
if ( ! V_40 )
goto V_383;
F_3 (fbl, &file_priv->fbs, filp_head)
if ( V_40 == V_381 )
V_382 = 1 ;
if ( ! V_382 )
goto V_383;
F_43 ( V_2 , V_40 ) ;
F_130 ( & V_40 -> V_45 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
F_6 ( & V_169 -> V_185 ) ;
F_47 ( V_40 ) ;
return 0 ;
V_383:
F_6 ( & V_2 -> V_5 . V_43 ) ;
F_6 ( & V_169 -> V_185 ) ;
return - V_205 ;
}
int F_131 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_312 * V_315 = V_167 ;
struct V_39 * V_40 ;
int V_33 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
V_40 = F_35 ( V_2 , V_315 -> V_179 ) ;
if ( ! V_40 )
return - V_205 ;
V_315 -> V_264 = V_40 -> V_264 ;
V_315 -> V_263 = V_40 -> V_263 ;
V_315 -> V_303 = V_40 -> V_303 ;
V_315 -> V_302 = V_40 -> V_384 ;
V_315 -> V_317 = V_40 -> V_316 [ 0 ] ;
if ( V_40 -> V_42 -> V_385 ) {
if ( V_169 -> V_386 || F_132 ( V_387 ) ) {
V_33 = V_40 -> V_42 -> V_385 ( V_40 , V_169 ,
& V_315 -> V_295 ) ;
} else {
V_315 -> V_295 = 0 ;
V_33 = 0 ;
}
} else {
V_33 = - V_388 ;
}
F_36 ( V_40 ) ;
return V_33 ;
}
int F_133 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_389 T_2 * V_390 ;
struct V_389 * V_391 = NULL ;
struct V_392 * V_315 = V_167 ;
struct V_39 * V_40 ;
unsigned V_160 ;
int V_393 ;
int V_33 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
V_40 = F_35 ( V_2 , V_315 -> V_179 ) ;
if ( ! V_40 )
return - V_205 ;
V_393 = V_315 -> V_393 ;
V_390 = (struct V_389 T_2 * ) ( unsigned long ) V_315 -> V_390 ;
if ( ! V_393 != ! V_390 ) {
V_33 = - V_166 ;
goto V_394;
}
V_160 = V_395 & V_315 -> V_160 ;
if ( V_160 & V_396 && ( V_393 % 2 ) ) {
V_33 = - V_166 ;
goto V_394;
}
if ( V_393 && V_390 ) {
if ( V_393 < 0 || V_393 > V_397 ) {
V_33 = - V_166 ;
goto V_394;
}
V_391 = F_78 ( V_393 * sizeof( * V_391 ) , V_36 ) ;
if ( ! V_391 ) {
V_33 = - V_95 ;
goto V_394;
}
V_33 = F_134 ( V_391 , V_390 ,
V_393 * sizeof( * V_391 ) ) ;
if ( V_33 ) {
V_33 = - V_188 ;
goto V_398;
}
}
if ( V_40 -> V_42 -> V_399 ) {
F_1 ( V_2 ) ;
V_33 = V_40 -> V_42 -> V_399 ( V_40 , V_169 , V_160 , V_315 -> V_400 ,
V_391 , V_393 ) ;
F_5 ( V_2 ) ;
} else {
V_33 = - V_401 ;
}
V_398:
F_57 ( V_391 ) ;
V_394:
F_36 ( V_40 ) ;
return V_33 ;
}
void F_135 ( struct V_168 * V_92 )
{
struct V_1 * V_2 = V_92 -> V_190 -> V_2 ;
struct V_39 * V_40 , * V_402 ;
F_2 ( & V_92 -> V_185 ) ;
F_65 (fb, tfb, &priv->fbs, filp_head) {
F_2 ( & V_2 -> V_5 . V_43 ) ;
F_43 ( V_2 , V_40 ) ;
F_6 ( & V_2 -> V_5 . V_43 ) ;
F_130 ( & V_40 -> V_45 ) ;
F_47 ( V_40 ) ;
}
F_6 ( & V_92 -> V_185 ) ;
}
struct V_101 * F_80 ( struct V_1 * V_2 , int V_160 ,
const char * V_16 , int V_403 )
{
struct V_101 * V_404 = NULL ;
int V_33 ;
V_404 = F_78 ( sizeof( struct V_101 ) , V_36 ) ;
if ( ! V_404 )
return NULL ;
if ( V_403 ) {
V_404 -> V_240 = F_78 ( sizeof( T_3 ) * V_403 , V_36 ) ;
if ( ! V_404 -> V_240 )
goto V_405;
}
V_33 = F_20 ( V_2 , & V_404 -> V_17 , V_406 ) ;
if ( V_33 )
goto V_405;
V_404 -> V_160 = V_160 ;
V_404 -> V_403 = V_403 ;
F_28 ( & V_404 -> V_407 ) ;
if ( V_16 ) {
strncpy ( V_404 -> V_16 , V_16 , V_408 ) ;
V_404 -> V_16 [ V_408 - 1 ] = '\0' ;
}
F_55 ( & V_404 -> V_48 , & V_2 -> V_5 . V_409 ) ;
return V_404 ;
V_405:
F_57 ( V_404 -> V_240 ) ;
F_57 ( V_404 ) ;
return NULL ;
}
struct V_101 * F_81 ( struct V_1 * V_2 , int V_160 ,
const char * V_16 ,
const struct V_410 * V_411 ,
int V_403 )
{
struct V_101 * V_404 ;
int V_8 , V_33 ;
V_160 |= V_125 ;
V_404 = F_80 ( V_2 , V_160 , V_16 , V_403 ) ;
if ( ! V_404 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_403 ; V_8 ++ ) {
V_33 = F_85 ( V_404 , V_8 ,
V_411 [ V_8 ] . type ,
V_411 [ V_8 ] . V_16 ) ;
if ( V_33 ) {
F_136 ( V_2 , V_404 ) ;
return NULL ;
}
}
return V_404 ;
}
struct V_101 * F_137 ( struct V_1 * V_2 ,
int V_160 , const char * V_16 ,
const struct V_410 * V_411 ,
int V_403 )
{
struct V_101 * V_404 ;
int V_8 , V_33 ;
V_160 |= V_412 ;
V_404 = F_80 ( V_2 , V_160 , V_16 , V_403 ) ;
if ( ! V_404 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_403 ; V_8 ++ ) {
V_33 = F_85 ( V_404 , V_8 ,
V_411 [ V_8 ] . type ,
V_411 [ V_8 ] . V_16 ) ;
if ( V_33 ) {
F_136 ( V_2 , V_404 ) ;
return NULL ;
}
}
return V_404 ;
}
struct V_101 * F_84 ( struct V_1 * V_2 , int V_160 ,
const char * V_16 ,
T_3 V_413 , T_3 V_414 )
{
struct V_101 * V_404 ;
V_160 |= V_415 ;
V_404 = F_80 ( V_2 , V_160 , V_16 , 2 ) ;
if ( ! V_404 )
return NULL ;
V_404 -> V_240 [ 0 ] = V_413 ;
V_404 -> V_240 [ 1 ] = V_414 ;
return V_404 ;
}
int F_85 ( struct V_101 * V_404 , int V_416 ,
T_3 V_417 , const char * V_16 )
{
struct V_418 * V_419 ;
if ( ! ( V_404 -> V_160 & ( V_125 | V_412 ) ) )
return - V_166 ;
if ( ( V_404 -> V_160 & V_412 ) && ( V_417 > 63 ) )
return - V_166 ;
if ( ! F_48 ( & V_404 -> V_407 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( V_419 -> V_417 == V_417 ) {
strncpy ( V_419 -> V_16 , V_16 , V_408 ) ;
V_419 -> V_16 [ V_408 - 1 ] = '\0' ;
return 0 ;
}
}
}
V_419 = F_78 ( sizeof( struct V_418 ) , V_36 ) ;
if ( ! V_419 )
return - V_95 ;
strncpy ( V_419 -> V_16 , V_16 , V_408 ) ;
V_419 -> V_16 [ V_408 - 1 ] = '\0' ;
V_419 -> V_417 = V_417 ;
V_404 -> V_240 [ V_416 ] = V_417 ;
F_55 ( & V_419 -> V_48 , & V_404 -> V_407 ) ;
return 0 ;
}
void F_136 ( struct V_1 * V_2 , struct V_101 * V_404 )
{
struct V_418 * V_419 , * V_420 ;
F_65 (prop_enum, pt, &property->enum_blob_list, head) {
F_46 ( & V_419 -> V_48 ) ;
F_57 ( V_419 ) ;
}
if ( V_404 -> V_403 )
F_57 ( V_404 -> V_240 ) ;
F_22 ( V_2 , & V_404 -> V_17 ) ;
F_46 ( & V_404 -> V_48 ) ;
F_57 ( V_404 ) ;
}
void F_63 ( struct V_30 * V_31 ,
struct V_101 * V_404 ,
T_3 V_421 )
{
int V_222 = V_31 -> V_59 -> V_222 ;
if ( V_222 == V_422 ) {
F_91 ( 1 , L_64
L_65
L_66 ,
V_31 -> type ) ;
return;
}
V_31 -> V_59 -> V_239 [ V_222 ] = V_404 -> V_17 . V_18 ;
V_31 -> V_59 -> V_240 [ V_222 ] = V_421 ;
V_31 -> V_59 -> V_222 ++ ;
}
int F_138 ( struct V_30 * V_31 ,
struct V_101 * V_404 , T_3 V_423 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 -> V_59 -> V_222 ; V_8 ++ ) {
if ( V_31 -> V_59 -> V_239 [ V_8 ] == V_404 -> V_17 . V_18 ) {
V_31 -> V_59 -> V_240 [ V_8 ] = V_423 ;
return 0 ;
}
}
return - V_166 ;
}
int F_139 ( struct V_30 * V_31 ,
struct V_101 * V_404 , T_3 * V_423 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 -> V_59 -> V_222 ; V_8 ++ ) {
if ( V_31 -> V_59 -> V_239 [ V_8 ] == V_404 -> V_17 . V_18 ) {
* V_423 = V_31 -> V_59 -> V_240 [ V_8 ] ;
return 0 ;
}
}
return - V_166 ;
}
int F_140 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_30 * V_31 ;
struct V_424 * V_213 = V_167 ;
struct V_101 * V_404 ;
int V_425 = 0 ;
int V_426 = 0 ;
int V_427 = 0 ;
int V_33 = 0 , V_8 ;
int V_178 ;
struct V_418 * V_419 ;
struct V_428 T_2 * V_429 ;
struct V_430 * V_431 ;
T_1 T_2 * V_432 ;
T_3 T_2 * V_433 ;
T_1 T_2 * V_434 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_213 -> V_435 , V_406 ) ;
if ( ! V_31 ) {
V_33 = - V_205 ;
goto V_436;
}
V_404 = F_141 ( V_31 ) ;
if ( V_404 -> V_160 & ( V_125 | V_412 ) ) {
F_3 (prop_enum, &property->enum_blob_list, head)
V_425 ++ ;
} else if ( V_404 -> V_160 & V_104 ) {
F_3 (prop_blob, &property->enum_blob_list, head)
V_426 ++ ;
}
V_427 = V_404 -> V_403 ;
strncpy ( V_213 -> V_16 , V_404 -> V_16 , V_408 ) ;
V_213 -> V_16 [ V_408 - 1 ] = 0 ;
V_213 -> V_160 = V_404 -> V_160 ;
if ( ( V_213 -> V_437 >= V_427 ) && V_427 ) {
V_433 = ( T_3 T_2 * ) ( unsigned long ) V_213 -> V_433 ;
for ( V_8 = 0 ; V_8 < V_427 ; V_8 ++ ) {
if ( F_103 ( V_433 + V_8 , & V_404 -> V_240 [ V_8 ] , sizeof( T_3 ) ) ) {
V_33 = - V_188 ;
goto V_436;
}
}
}
V_213 -> V_437 = V_427 ;
if ( V_404 -> V_160 & ( V_125 | V_412 ) ) {
if ( ( V_213 -> V_438 >= V_425 ) && V_425 ) {
V_178 = 0 ;
V_429 = (struct V_428 T_2 * ) ( unsigned long ) V_213 -> V_439 ;
F_3 (prop_enum, &property->enum_blob_list, head) {
if ( F_103 ( & V_429 [ V_178 ] . V_417 , & V_419 -> V_417 , sizeof( T_3 ) ) ) {
V_33 = - V_188 ;
goto V_436;
}
if ( F_103 ( & V_429 [ V_178 ] . V_16 ,
& V_419 -> V_16 , V_408 ) ) {
V_33 = - V_188 ;
goto V_436;
}
V_178 ++ ;
}
}
V_213 -> V_438 = V_425 ;
}
if ( V_404 -> V_160 & V_104 ) {
if ( ( V_213 -> V_438 >= V_426 ) && V_426 ) {
V_178 = 0 ;
V_432 = ( T_1 T_2 * ) ( unsigned long ) V_213 -> V_439 ;
V_434 = ( T_1 T_2 * ) ( unsigned long ) V_213 -> V_433 ;
F_3 (prop_blob, &property->enum_blob_list, head) {
if ( F_96 ( V_431 -> V_17 . V_18 , V_432 + V_178 ) ) {
V_33 = - V_188 ;
goto V_436;
}
if ( F_96 ( V_431 -> V_440 , V_434 + V_178 ) ) {
V_33 = - V_188 ;
goto V_436;
}
V_178 ++ ;
}
}
V_213 -> V_438 = V_426 ;
}
V_436:
F_5 ( V_2 ) ;
return V_33 ;
}
static struct V_430 * F_142 ( struct V_1 * V_2 , int V_440 ,
void * V_167 )
{
struct V_430 * V_441 ;
int V_33 ;
if ( ! V_440 || ! V_167 )
return NULL ;
V_441 = F_78 ( sizeof( struct V_430 ) + V_440 , V_36 ) ;
if ( ! V_441 )
return NULL ;
V_33 = F_20 ( V_2 , & V_441 -> V_17 , V_442 ) ;
if ( V_33 ) {
F_57 ( V_441 ) ;
return NULL ;
}
V_441 -> V_440 = V_440 ;
memcpy ( V_441 -> V_167 , V_167 , V_440 ) ;
F_55 ( & V_441 -> V_48 , & V_2 -> V_5 . V_443 ) ;
return V_441 ;
}
static void F_143 ( struct V_1 * V_2 ,
struct V_430 * V_441 )
{
F_22 ( V_2 , & V_441 -> V_17 ) ;
F_46 ( & V_441 -> V_48 ) ;
F_57 ( V_441 ) ;
}
int F_144 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_30 * V_31 ;
struct V_444 * V_213 = V_167 ;
struct V_430 * V_441 ;
int V_33 = 0 ;
void T_2 * V_445 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_213 -> V_446 , V_442 ) ;
if ( ! V_31 ) {
V_33 = - V_205 ;
goto V_436;
}
V_441 = F_145 ( V_31 ) ;
if ( V_213 -> V_440 == V_441 -> V_440 ) {
V_445 = ( void T_2 * ) ( unsigned long ) V_213 -> V_167 ;
if ( F_103 ( V_445 , V_441 -> V_167 , V_441 -> V_440 ) ) {
V_33 = - V_188 ;
goto V_436;
}
}
V_213 -> V_440 = V_441 -> V_440 ;
V_436:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_146 ( struct V_19 * V_20 ,
struct V_102 * V_102 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_33 , V_447 ;
if ( V_20 -> V_70 )
F_143 ( V_2 , V_20 -> V_70 ) ;
if ( ! V_102 ) {
V_20 -> V_70 = NULL ;
V_33 = F_138 ( & V_20 -> V_17 , V_2 -> V_5 . V_75 , 0 ) ;
return V_33 ;
}
V_447 = V_448 * ( 1 + V_102 -> V_449 ) ;
V_20 -> V_70 = F_142 ( V_20 -> V_2 ,
V_447 , V_102 ) ;
if ( ! V_20 -> V_70 )
return - V_166 ;
V_33 = F_138 ( & V_20 -> V_17 ,
V_2 -> V_5 . V_75 ,
V_20 -> V_70 -> V_17 . V_18 ) ;
return V_33 ;
}
static bool F_147 ( struct V_101 * V_404 ,
T_3 V_417 )
{
if ( V_404 -> V_160 & V_105 )
return false ;
if ( V_404 -> V_160 & V_415 ) {
if ( V_417 < V_404 -> V_240 [ 0 ] || V_417 > V_404 -> V_240 [ 1 ] )
return false ;
return true ;
} else if ( V_404 -> V_160 & V_412 ) {
int V_8 ;
T_3 V_450 = 0 ;
for ( V_8 = 0 ; V_8 < V_404 -> V_403 ; V_8 ++ )
V_450 |= ( 1ULL << V_404 -> V_240 [ V_8 ] ) ;
return ! ( V_417 & ~ V_450 ) ;
} else if ( V_404 -> V_160 & V_104 ) {
return true ;
} else {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_404 -> V_403 ; V_8 ++ )
if ( V_404 -> V_240 [ V_8 ] == V_417 )
return true ;
return false ;
}
}
int F_148 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_451 * V_452 = V_167 ;
struct V_453 V_454 = {
. V_417 = V_452 -> V_417 ,
. V_435 = V_452 -> V_435 ,
. V_455 = V_452 -> V_181 ,
. V_32 = V_68
} ;
return F_149 ( V_2 , & V_454 , V_169 ) ;
}
static int F_150 ( struct V_30 * V_31 ,
struct V_101 * V_404 ,
T_3 V_417 )
{
int V_33 = - V_166 ;
struct V_19 * V_20 = F_102 ( V_31 ) ;
if ( V_404 == V_20 -> V_2 -> V_5 . V_76 ) {
if ( V_20 -> V_42 -> V_103 )
(* V_20 -> V_42 -> V_103 )( V_20 , ( int ) V_417 ) ;
V_33 = 0 ;
} else if ( V_20 -> V_42 -> V_456 )
V_33 = V_20 -> V_42 -> V_456 ( V_20 , V_404 , V_417 ) ;
if ( ! V_33 )
F_138 ( & V_20 -> V_17 , V_404 , V_417 ) ;
return V_33 ;
}
static int F_151 ( struct V_30 * V_31 ,
struct V_101 * V_404 ,
T_3 V_417 )
{
int V_33 = - V_166 ;
struct V_3 * V_4 = F_98 ( V_31 ) ;
if ( V_4 -> V_42 -> V_456 )
V_33 = V_4 -> V_42 -> V_456 ( V_4 , V_404 , V_417 ) ;
if ( ! V_33 )
F_138 ( V_31 , V_404 , V_417 ) ;
return V_33 ;
}
static int F_152 ( struct V_30 * V_31 ,
struct V_101 * V_404 ,
T_3 V_417 )
{
int V_33 = - V_166 ;
struct V_52 * V_53 = F_108 ( V_31 ) ;
if ( V_53 -> V_42 -> V_456 )
V_33 = V_53 -> V_42 -> V_456 ( V_53 , V_404 , V_417 ) ;
if ( ! V_33 )
F_138 ( V_31 , V_404 , V_417 ) ;
return V_33 ;
}
int F_153 ( struct V_1 * V_2 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_457 * V_458 = V_167 ;
struct V_30 * V_31 ;
int V_33 = 0 ;
int V_8 ;
int V_178 = 0 ;
int V_215 = 0 ;
T_1 T_2 * V_237 ;
T_3 T_2 * V_238 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_458 -> V_455 , V_458 -> V_32 ) ;
if ( ! V_31 ) {
V_33 = - V_205 ;
goto V_46;
}
if ( ! V_31 -> V_59 ) {
V_33 = - V_166 ;
goto V_46;
}
V_215 = V_31 -> V_59 -> V_222 ;
if ( ( V_458 -> V_236 >= V_215 ) && V_215 ) {
V_178 = 0 ;
V_237 = ( T_1 T_2 * ) ( unsigned long ) ( V_458 -> V_237 ) ;
V_238 = ( T_3 T_2 * ) ( unsigned long )
( V_458 -> V_238 ) ;
for ( V_8 = 0 ; V_8 < V_215 ; V_8 ++ ) {
if ( F_96 ( V_31 -> V_59 -> V_239 [ V_8 ] ,
V_237 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
if ( F_96 ( V_31 -> V_59 -> V_240 [ V_8 ] ,
V_238 + V_178 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_178 ++ ;
}
}
V_458 -> V_236 = V_215 ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_149 ( struct V_1 * V_2 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_453 * V_458 = V_167 ;
struct V_30 * V_459 ;
struct V_30 * V_460 ;
struct V_101 * V_404 ;
int V_33 = - V_166 ;
int V_8 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_459 = F_24 ( V_2 , V_458 -> V_455 , V_458 -> V_32 ) ;
if ( ! V_459 ) {
V_33 = - V_205 ;
goto V_46;
}
if ( ! V_459 -> V_59 )
goto V_46;
for ( V_8 = 0 ; V_8 < V_459 -> V_59 -> V_222 ; V_8 ++ )
if ( V_459 -> V_59 -> V_239 [ V_8 ] == V_458 -> V_435 )
break;
if ( V_8 == V_459 -> V_59 -> V_222 )
goto V_46;
V_460 = F_24 ( V_2 , V_458 -> V_435 ,
V_406 ) ;
if ( ! V_460 ) {
V_33 = - V_205 ;
goto V_46;
}
V_404 = F_141 ( V_460 ) ;
if ( ! F_147 ( V_404 , V_458 -> V_417 ) )
goto V_46;
switch ( V_459 -> type ) {
case V_68 :
V_33 = F_150 ( V_459 , V_404 ,
V_458 -> V_417 ) ;
break;
case V_58 :
V_33 = F_151 ( V_459 , V_404 , V_458 -> V_417 ) ;
break;
case V_93 :
V_33 = F_152 ( V_459 , V_404 , V_458 -> V_417 ) ;
break;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_154 ( struct V_19 * V_20 ,
struct V_11 * V_12 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_223 ; V_8 ++ ) {
if ( V_20 -> V_224 [ V_8 ] == 0 ) {
V_20 -> V_224 [ V_8 ] = V_12 -> V_17 . V_18 ;
return 0 ;
}
}
return - V_95 ;
}
void F_155 ( struct V_19 * V_20 ,
struct V_11 * V_12 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_223 ; V_8 ++ ) {
if ( V_20 -> V_224 [ V_8 ] == V_12 -> V_17 . V_18 ) {
V_20 -> V_224 [ V_8 ] = 0 ;
if ( V_20 -> V_12 == V_12 )
V_20 -> V_12 = NULL ;
break;
}
}
}
int F_156 ( struct V_3 * V_4 ,
int V_208 )
{
V_4 -> V_208 = V_208 ;
V_4 -> V_62 = F_78 ( V_208 * sizeof( V_461 ) * 3 , V_36 ) ;
if ( ! V_4 -> V_62 ) {
V_4 -> V_208 = 0 ;
return - V_95 ;
}
return 0 ;
}
int F_157 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_462 * V_463 = V_167 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
void * V_464 , * V_465 , * V_466 ;
int V_447 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_463 -> V_180 , V_58 ) ;
if ( ! V_31 ) {
V_33 = - V_205 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
if ( V_4 -> V_42 -> V_467 == NULL ) {
V_33 = - V_401 ;
goto V_46;
}
if ( V_463 -> V_208 != V_4 -> V_208 ) {
V_33 = - V_166 ;
goto V_46;
}
V_447 = V_463 -> V_208 * ( sizeof( V_461 ) ) ;
V_464 = V_4 -> V_62 ;
if ( F_134 ( V_464 , ( void T_2 * ) ( unsigned long ) V_463 -> V_468 , V_447 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_465 = V_464 + V_447 ;
if ( F_134 ( V_465 , ( void T_2 * ) ( unsigned long ) V_463 -> V_469 , V_447 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_466 = V_465 + V_447 ;
if ( F_134 ( V_466 , ( void T_2 * ) ( unsigned long ) V_463 -> V_470 , V_447 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_4 -> V_42 -> V_467 ( V_4 , V_464 , V_465 , V_466 , 0 , V_4 -> V_208 ) ;
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_158 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_462 * V_463 = V_167 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
void * V_464 , * V_465 , * V_466 ;
int V_447 ;
int V_33 = 0 ;
if ( ! F_94 ( V_2 , V_184 ) )
return - V_166 ;
F_1 ( V_2 ) ;
V_31 = F_24 ( V_2 , V_463 -> V_180 , V_58 ) ;
if ( ! V_31 ) {
V_33 = - V_205 ;
goto V_46;
}
V_4 = F_98 ( V_31 ) ;
if ( V_463 -> V_208 != V_4 -> V_208 ) {
V_33 = - V_166 ;
goto V_46;
}
V_447 = V_463 -> V_208 * ( sizeof( V_461 ) ) ;
V_464 = V_4 -> V_62 ;
if ( F_103 ( ( void T_2 * ) ( unsigned long ) V_463 -> V_468 , V_464 , V_447 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_465 = V_464 + V_447 ;
if ( F_103 ( ( void T_2 * ) ( unsigned long ) V_463 -> V_469 , V_465 , V_447 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_466 = V_465 + V_447 ;
if ( F_103 ( ( void T_2 * ) ( unsigned long ) V_463 -> V_470 , V_466 , V_447 ) ) {
V_33 = - V_188 ;
goto V_46;
}
V_46:
F_5 ( V_2 ) ;
return V_33 ;
}
int F_159 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_471 * V_472 = V_167 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
struct V_39 * V_40 = NULL , * V_259 = NULL ;
struct V_473 * V_474 = NULL ;
unsigned long V_160 ;
int V_33 = - V_166 ;
if ( V_472 -> V_160 & ~ V_475 ||
V_472 -> V_476 != 0 )
return - V_166 ;
if ( ( V_472 -> V_160 & V_477 ) && ! V_2 -> V_5 . V_478 )
return - V_166 ;
V_31 = F_24 ( V_2 , V_472 -> V_180 , V_58 ) ;
if ( ! V_31 )
return - V_205 ;
V_4 = F_98 ( V_31 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_40 == NULL ) {
V_33 = - V_479 ;
goto V_46;
}
if ( V_4 -> V_42 -> V_472 == NULL )
goto V_46;
V_40 = F_35 ( V_2 , V_472 -> V_179 ) ;
if ( ! V_40 ) {
V_33 = - V_205 ;
goto V_46;
}
V_33 = F_110 ( V_4 , V_4 -> V_206 , V_4 -> V_207 , & V_4 -> V_64 , V_40 ) ;
if ( V_33 )
goto V_46;
if ( V_4 -> V_40 -> V_262 != V_40 -> V_262 ) {
F_75 ( L_67 ) ;
V_33 = - V_166 ;
goto V_46;
}
if ( V_472 -> V_160 & V_480 ) {
V_33 = - V_95 ;
F_160 ( & V_2 -> V_481 , V_160 ) ;
if ( V_169 -> V_482 < sizeof V_474 -> V_483 ) {
F_161 ( & V_2 -> V_481 , V_160 ) ;
goto V_46;
}
V_169 -> V_482 -= sizeof V_474 -> V_483 ;
F_161 ( & V_2 -> V_481 , V_160 ) ;
V_474 = F_78 ( sizeof *V_474 , V_36 ) ;
if ( V_474 == NULL ) {
F_160 ( & V_2 -> V_481 , V_160 ) ;
V_169 -> V_482 += sizeof V_474 -> V_483 ;
F_161 ( & V_2 -> V_481 , V_160 ) ;
goto V_46;
}
V_474 -> V_483 . V_17 . type = V_484 ;
V_474 -> V_483 . V_17 . V_440 = sizeof V_474 -> V_483 ;
V_474 -> V_483 . V_485 = V_472 -> V_485 ;
V_474 -> V_17 . V_483 = & V_474 -> V_483 . V_17 ;
V_474 -> V_17 . V_169 = V_169 ;
V_474 -> V_17 . V_51 =
( void ( * ) ( struct V_486 * ) ) F_57 ;
}
V_259 = V_4 -> V_40 ;
V_33 = V_4 -> V_42 -> V_472 ( V_4 , V_40 , V_474 , V_472 -> V_160 ) ;
if ( V_33 ) {
if ( V_472 -> V_160 & V_480 ) {
F_160 ( & V_2 -> V_481 , V_160 ) ;
V_169 -> V_482 += sizeof V_474 -> V_483 ;
F_161 ( & V_2 -> V_481 , V_160 ) ;
F_57 ( V_474 ) ;
}
V_259 = NULL ;
} else {
F_8 ( V_4 -> V_40 != V_40 ) ;
V_40 = NULL ;
}
V_46:
if ( V_40 )
F_36 ( V_40 ) ;
if ( V_259 )
F_36 ( V_259 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_33 ;
}
void F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_19 * V_20 ;
F_3 (crtc, &dev->mode_config.crtc_list, head)
if ( V_4 -> V_42 -> V_487 )
V_4 -> V_42 -> V_487 ( V_4 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head)
if ( V_12 -> V_42 -> V_487 )
V_12 -> V_42 -> V_487 ( V_12 ) ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_20 -> V_24 = V_71 ;
if ( V_20 -> V_42 -> V_487 )
V_20 -> V_42 -> V_487 ( V_20 ) ;
}
}
int F_163 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_488 * args = V_167 ;
if ( ! V_2 -> V_489 -> V_490 )
return - V_401 ;
return V_2 -> V_489 -> V_490 ( V_169 , V_2 , args ) ;
}
int F_164 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_491 * args = V_167 ;
if ( ! V_2 -> V_489 -> V_492 )
return - V_401 ;
return V_2 -> V_489 -> V_492 ( V_169 , V_2 , args -> V_295 , & args -> V_493 ) ;
}
int F_165 ( struct V_1 * V_2 ,
void * V_167 , struct V_168 * V_169 )
{
struct V_494 * args = V_167 ;
if ( ! V_2 -> V_489 -> V_495 )
return - V_401 ;
return V_2 -> V_489 -> V_495 ( V_169 , V_2 , args -> V_295 ) ;
}
void F_166 ( T_1 V_28 , unsigned int * V_303 ,
int * V_302 )
{
switch ( V_28 ) {
case V_305 :
case V_321 :
case V_322 :
* V_303 = 8 ;
* V_302 = 8 ;
break;
case V_306 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
* V_303 = 15 ;
* V_302 = 16 ;
break;
case V_307 :
case V_338 :
* V_303 = 16 ;
* V_302 = 16 ;
break;
case V_308 :
case V_339 :
* V_303 = 24 ;
* V_302 = 24 ;
break;
case V_309 :
case V_340 :
case V_341 :
case V_342 :
* V_303 = 24 ;
* V_302 = 32 ;
break;
case V_310 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
* V_303 = 30 ;
* V_302 = 32 ;
break;
case V_311 :
case V_343 :
case V_344 :
case V_345 :
* V_303 = 32 ;
* V_302 = 32 ;
break;
default:
F_75 ( L_68 ,
F_19 ( V_28 ) ) ;
* V_303 = 0 ;
* V_302 = 0 ;
break;
}
}
int F_126 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
return 3 ;
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
return 2 ;
default:
return 1 ;
}
}
int F_127 ( T_1 V_28 , int V_53 )
{
unsigned int V_303 ;
int V_302 ;
if ( V_53 >= F_126 ( V_28 ) )
return 0 ;
switch ( V_28 ) {
case V_353 :
case V_354 :
case V_355 :
case V_356 :
return 2 ;
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
return V_53 ? 2 : 1 ;
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
return 1 ;
default:
F_166 ( V_28 , & V_303 , & V_302 ) ;
return V_302 >> 3 ;
}
}
int F_124 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_366 :
case V_367 :
case V_364 :
case V_365 :
return 4 ;
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_370 :
case V_371 :
case V_368 :
case V_369 :
return 2 ;
default:
return 1 ;
}
}
int F_125 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_364 :
case V_365 :
return 4 ;
case V_368 :
case V_369 :
case V_358 :
case V_359 :
return 2 ;
default:
return 1 ;
}
}
void F_167 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_5 . V_6 ) ;
F_54 ( & V_2 -> V_5 . V_34 ) ;
F_54 ( & V_2 -> V_5 . V_43 ) ;
F_28 ( & V_2 -> V_5 . V_49 ) ;
F_28 ( & V_2 -> V_5 . V_60 ) ;
F_28 ( & V_2 -> V_5 . V_72 ) ;
F_28 ( & V_2 -> V_5 . V_82 ) ;
F_28 ( & V_2 -> V_5 . V_86 ) ;
F_28 ( & V_2 -> V_5 . V_409 ) ;
F_28 ( & V_2 -> V_5 . V_443 ) ;
F_28 ( & V_2 -> V_5 . V_96 ) ;
F_168 ( & V_2 -> V_5 . V_35 ) ;
F_1 ( V_2 ) ;
F_79 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_5 . V_47 = 0 ;
V_2 -> V_5 . V_73 = 0 ;
V_2 -> V_5 . V_61 = 0 ;
V_2 -> V_5 . V_87 = 0 ;
}
void F_169 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_496 ;
struct V_3 * V_4 , * V_497 ;
struct V_11 * V_12 , * V_498 ;
struct V_78 * V_79 , * V_499 ;
struct V_39 * V_40 , * V_500 ;
struct V_101 * V_404 , * V_420 ;
struct V_430 * V_441 , * V_501 ;
struct V_52 * V_53 , * V_502 ;
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
F_136 ( V_2 , V_404 ) ;
}
F_65 (blob, bt, &dev->mode_config.property_blob_list,
head) {
F_143 ( V_2 , V_441 ) ;
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
F_170 ( & V_2 -> V_5 . V_35 ) ;
}
