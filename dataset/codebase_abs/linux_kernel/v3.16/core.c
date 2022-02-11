char * F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return L_1 ;
return V_2 -> V_3 -> V_4 ;
}
void F_2 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_7 * V_3 ,
enum V_8 type ,
int V_9 )
{
V_2 -> V_6 = V_6 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_3 = V_3 ;
V_2 -> type = type ;
}
static void F_3 ( struct V_10 * V_11 )
{
V_11 -> V_12 = 1 ;
F_4 ( & V_11 -> V_13 ) ;
}
void F_5 ( struct V_10 * V_11 )
{
V_11 -> V_14 = 0 ;
V_11 -> V_12 = 2 ;
F_6 ( V_11 ) ;
}
void F_7 ( struct V_10 * V_11 )
{
V_11 -> V_12 = 0 ;
F_8 ( & V_11 -> V_13 ) ;
F_9 ( V_11 -> V_15 ) ;
}
static void F_10 ( void * V_16 )
{
struct V_10 * V_11 = (struct V_10 * ) V_16 ;
struct V_1 * V_2 = F_11 ( V_11 ) ;
struct V_5 * V_6 = F_12 ( F_11 ( V_11 ) ) ;
struct V_17 * V_18 = F_13 ( V_2 ) ;
unsigned long V_19 ;
F_14 ( V_6 , V_19 ) ;
if ( V_11 -> V_12 )
F_3 ( V_11 ) ;
F_15 ( V_6 , V_19 ) ;
F_16 ( V_18 , V_18 -> V_20 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
struct V_5 * V_6 = F_12 ( V_2 ) ;
struct V_17 * V_18 = F_13 ( V_2 ) ;
struct V_21 * V_22 = F_17 ( V_18 ) ;
struct V_23 * V_24 = F_18 ( V_6 ) ;
struct V_25 * V_26 ;
T_1 V_27 ;
T_2 V_28 = V_18 -> V_20 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_11 -> V_12 ; V_29 ++ ) {
V_27 = V_22 -> V_30 +
F_19 ( V_18 , V_11 -> V_14 + V_28 ) ;
V_11 -> V_14 = V_28 ;
V_26 = F_20 (
V_11 -> V_15 , V_27 , V_28 , V_11 -> V_31 ,
V_32 | V_33 ) ;
if ( ! V_26 ) {
F_21 ( V_24 , L_2 ) ;
return;
}
V_26 -> V_34 = F_10 ;
V_26 -> V_35 = V_11 ;
if ( F_22 ( V_26 ) < 0 ) {
F_21 ( V_24 , L_3 ) ;
return;
}
F_23 ( V_11 -> V_15 ) ;
}
}
static void F_24 ( struct V_36 * V_13 )
{
struct V_10 * V_11 = F_25 ( V_13 , struct V_10 , V_13 ) ;
F_6 ( V_11 ) ;
}
int F_26 ( struct V_10 * V_11 )
{
return ! ! V_11 -> V_15 ;
}
static int F_27 ( char * V_37 , struct V_1 * V_2 )
{
if ( V_2 )
return snprintf ( V_37 , V_38 / 2 , L_4 ,
F_1 ( V_2 ) , F_28 ( V_2 ) ) ;
else
return snprintf ( V_37 , V_38 / 2 , L_5 ) ;
}
static void F_29 ( struct V_10 * V_11 ,
int V_39 , char * V_37 )
{
struct V_1 * V_40 = F_11 ( V_11 ) ;
struct V_17 * V_18 = F_13 ( V_40 ) ;
struct V_1 * V_41 = F_30 ( V_18 ) ;
struct V_1 * V_42 = F_31 ( V_18 ) ;
struct V_1 * V_43 = F_32 ( V_18 ) ;
struct V_1 * V_2 [ V_44 ] ;
struct V_1 * V_45 , * V_46 ;
int V_29 , V_47 ;
for ( V_29 = 0 ; V_29 < V_44 ; V_29 ++ )
V_2 [ V_29 ] = NULL ;
V_2 [ 0 ] = NULL ;
V_47 = 1 ;
for ( V_29 = 1 ; V_29 < V_44 ; V_29 ++ ) {
if ( ! V_42 ) {
V_2 [ V_29 ] = V_41 ;
break;
} else if ( ! V_43 ) {
V_2 [ V_29 ] = V_42 ;
V_42 = NULL ;
} else {
V_2 [ V_29 ] = V_43 ;
V_43 = NULL ;
}
if ( V_2 [ V_29 ] == V_40 )
V_47 = V_29 ;
}
if ( V_39 ) {
V_45 = V_2 [ V_47 - 1 ] ;
V_46 = V_2 [ V_47 ] ;
} else {
V_45 = V_2 [ V_47 ] ;
V_46 = V_2 [ V_47 - 1 ] ;
}
V_47 = 0 ;
V_47 = F_27 ( V_37 + V_47 , V_45 ) ;
* ( V_37 + V_47 ++ ) = '_' ;
V_47 = F_27 ( V_37 + V_47 , V_46 ) ;
}
int F_33 ( struct V_5 * V_6 , struct V_10 * V_11 ,
int V_39 , int V_9 )
{
struct V_23 * V_24 = F_18 ( V_6 ) ;
struct V_48 V_49 ;
char V_37 [ V_38 ] ;
T_3 V_50 ;
int V_51 ;
if ( V_11 -> V_15 ) {
F_21 ( V_24 , L_6 ) ;
return - V_52 ;
}
F_34 ( V_50 ) ;
F_35 ( V_53 , V_50 ) ;
if ( V_24 -> V_54 )
F_29 ( V_11 , V_39 , V_37 ) ;
else
snprintf ( V_37 , V_38 ,
V_39 ? L_7 : L_8 ) ;
F_36 ( V_24 , L_9 , V_37 ) ;
V_11 -> V_15 = F_37 ( V_50 , V_55 ,
( void * ) V_9 , V_24 ,
V_37 ) ;
if ( ! V_11 -> V_15 ) {
F_21 ( V_24 , L_10 ) ;
return - V_52 ;
}
F_38 ( V_6 , V_11 , & V_49 , V_39 , V_9 ) ;
V_51 = F_39 ( V_11 -> V_15 , & V_49 ) ;
if ( V_51 < 0 )
goto V_56;
V_11 -> V_31 = V_39 ? V_57 : V_58 ;
F_40 ( & V_11 -> V_13 , F_24 ) ;
return 0 ;
V_56:
F_41 ( V_6 , V_11 ) ;
return V_51 ;
}
void F_41 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
if ( V_11 -> V_15 )
F_42 ( V_11 -> V_15 ) ;
V_11 -> V_15 = NULL ;
}
T_4 F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_12 ( V_2 ) ;
struct V_17 * V_18 = F_13 ( V_2 ) ;
struct V_21 * V_22 = F_17 ( V_18 ) ;
struct V_23 * V_24 = F_18 ( V_6 ) ;
T_4 V_59 = V_22 -> V_60 ;
switch ( V_22 -> V_61 ) {
case 16 :
V_59 |= ( 8 << 16 ) ;
break;
case 32 :
V_59 |= ( 0 << 16 ) ;
break;
default:
F_44 ( V_24 , L_11 ) ;
return 0 ;
}
return V_59 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
if ( ! V_2 )
return - V_52 ;
if ( V_18 -> V_2 [ V_2 -> type ] ) {
struct V_5 * V_6 = F_12 ( V_2 ) ;
struct V_23 * V_24 = F_18 ( V_6 ) ;
F_21 ( V_24 , L_12 ,
F_1 ( V_2 ) ,
F_28 ( V_2 ) ) ;
return - V_52 ;
}
V_18 -> V_2 [ V_2 -> type ] = V_2 ;
V_2 -> V_18 = V_18 ;
return 0 ;
}
int F_46 ( struct V_5 * V_6 , struct V_62 * V_63 )
{
int V_9 = V_63 - V_6 -> V_63 ;
if ( ( V_9 < 0 ) || ( V_9 >= F_47 ( V_6 ) ) )
return - V_64 ;
return V_9 ;
}
struct V_62 * F_48 ( struct V_5 * V_6 , int V_9 )
{
if ( ( V_9 < 0 ) || ( V_9 >= F_47 ( V_6 ) ) )
return NULL ;
return V_6 -> V_63 + V_9 ;
}
static struct V_62 * F_49 ( struct V_65 * V_66 )
{
struct V_5 * V_6 = F_50 ( V_66 ) ;
return F_48 ( V_6 , V_66 -> V_9 ) ;
}
int F_51 ( struct V_62 * V_63 , struct V_17 * V_18 )
{
return & V_63 -> V_67 == V_18 ;
}
int F_19 ( struct V_17 * V_18 , int V_68 )
{
struct V_69 * V_70 = V_18 -> V_70 ;
struct V_21 * V_22 = V_70 -> V_22 ;
int V_71 = V_18 -> V_72 + V_68 ;
V_71 %= ( V_22 -> V_73 * V_18 -> V_20 ) ;
return V_71 ;
}
void F_16 ( struct V_17 * V_18 , int V_74 )
{
V_18 -> V_72 += V_74 ;
if ( V_18 -> V_72 >= V_18 -> V_75 ) {
struct V_69 * V_70 = V_18 -> V_70 ;
struct V_21 * V_22 = V_70 -> V_22 ;
V_18 -> V_76 ++ ;
V_18 -> V_75 += V_18 -> V_20 ;
if ( V_18 -> V_76 >= V_22 -> V_73 ) {
V_18 -> V_72 = 0 ;
V_18 -> V_76 = 0 ;
V_18 -> V_75 = V_18 -> V_20 ;
}
F_52 ( V_70 ) ;
}
}
static int F_53 ( struct V_17 * V_18 ,
struct V_69 * V_70 )
{
struct V_21 * V_22 = V_70 -> V_22 ;
V_18 -> V_70 = V_70 ;
V_18 -> V_72 = 0 ;
V_18 -> V_76 = 0 ;
V_18 -> V_20 = V_22 -> V_77 *
V_22 -> V_60 *
F_54 ( V_22 , 1 ) ;
V_18 -> V_75 = V_18 -> V_20 ;
return 0 ;
}
static
struct V_65 * F_55 ( struct V_69 * V_70 )
{
struct V_78 * V_79 = V_70 -> V_80 ;
return V_79 -> V_81 ;
}
static
struct V_17 * F_56 ( struct V_62 * V_63 ,
struct V_69 * V_70 )
{
if ( V_70 -> V_82 == V_83 )
return & V_63 -> V_67 ;
else
return & V_63 -> V_84 ;
}
static int F_57 ( struct V_69 * V_70 , int V_85 ,
struct V_65 * V_66 )
{
struct V_5 * V_6 = F_50 ( V_66 ) ;
struct V_62 * V_63 = F_49 ( V_66 ) ;
struct V_17 * V_18 = F_56 ( V_63 , V_70 ) ;
int V_86 = F_28 ( F_30 ( V_18 ) ) ;
int V_51 ;
unsigned long V_19 ;
F_14 ( V_6 , V_19 ) ;
switch ( V_85 ) {
case V_87 :
V_51 = F_53 ( V_18 , V_70 ) ;
if ( V_51 < 0 )
goto V_88;
V_51 = F_58 ( V_6 , V_66 , V_89 , V_86 ) ;
if ( V_51 < 0 )
goto V_88;
V_51 = F_59 ( V_90 , V_18 , V_63 ) ;
if ( V_51 < 0 )
goto V_88;
V_51 = F_59 ( V_89 , V_18 , V_63 ) ;
if ( V_51 < 0 )
goto V_88;
break;
case V_91 :
V_51 = F_59 ( V_92 , V_18 , V_63 ) ;
if ( V_51 < 0 )
goto V_88;
V_51 = F_59 ( V_93 , V_18 , V_63 ) ;
if ( V_51 < 0 )
goto V_88;
V_51 = F_58 ( V_6 , V_66 , V_92 , V_86 ) ;
if ( V_51 < 0 )
goto V_88;
break;
default:
V_51 = - V_64 ;
}
V_88:
F_15 ( V_6 , V_19 ) ;
return V_51 ;
}
static int F_60 ( struct V_65 * V_66 , unsigned int V_94 )
{
struct V_62 * V_63 = F_49 ( V_66 ) ;
switch ( V_94 & V_95 ) {
case V_96 :
V_63 -> V_97 = 0 ;
break;
case V_98 :
V_63 -> V_97 = 1 ;
break;
default:
return - V_64 ;
}
switch ( V_94 & V_99 ) {
case V_100 :
V_63 -> V_101 = 0 ;
V_63 -> V_102 = 1 ;
break;
case V_103 :
V_63 -> V_101 = 1 ;
V_63 -> V_102 = 0 ;
break;
case V_104 :
V_63 -> V_101 = 1 ;
V_63 -> V_102 = 1 ;
break;
case V_105 :
default:
V_63 -> V_101 = 0 ;
V_63 -> V_102 = 0 ;
break;
}
switch ( V_94 & V_106 ) {
case V_107 :
V_63 -> V_108 = 0 ;
V_63 -> V_109 = 0 ;
break;
case V_110 :
V_63 -> V_108 = 1 ;
V_63 -> V_109 = 0 ;
break;
case V_111 :
V_63 -> V_108 = 1 ;
V_63 -> V_109 = 1 ;
break;
}
return 0 ;
}
static int F_61 ( struct V_5 * V_6 ,
struct V_62 * V_63 ,
struct V_17 * V_18 )
{
int V_51 ;
V_51 = F_62 ( V_6 , V_18 , V_42 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = F_62 ( V_6 , V_18 , V_41 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = F_62 ( V_6 , V_18 , V_43 ) ;
if ( V_51 < 0 )
return V_51 ;
return V_51 ;
}
static void F_63 ( struct V_112 * V_113 ,
const struct V_114 * V_115 ,
struct V_5 * V_6 )
{
struct V_116 * V_117 , * V_118 ;
struct V_116 * V_119 , * V_120 ;
struct V_116 * V_121 , * V_122 ;
struct V_116 * V_67 , * V_84 ;
struct V_123 * V_124 ;
struct V_125 * V_126 = F_64 ( V_6 ) ;
struct V_23 * V_24 = & V_113 -> V_24 ;
int V_127 , V_29 ;
int V_128 , V_129 , V_130 ;
if ( ! V_115 )
return;
V_117 = F_65 ( V_24 -> V_54 , L_13 ) ;
if ( ! V_117 )
return;
V_127 = F_66 ( V_117 ) ;
if ( ! V_127 )
return;
V_124 = F_67 ( V_24 ,
sizeof( struct V_123 ) * V_127 ,
V_131 ) ;
if ( ! V_124 ) {
F_21 ( V_24 , L_14 ) ;
return;
}
V_126 -> V_132 = V_127 ;
V_126 -> V_124 = V_124 ;
V_119 = F_65 ( V_24 -> V_54 , L_15 ) ;
V_121 = F_65 ( V_24 -> V_54 , L_16 ) ;
#define F_68 ( V_4 ) \
if (name##_node) { \
struct rsnd_##name##_platform_info *name##_info; \
\
name##_i = 0; \
for_each_child_of_node(name##_node, name##_np) { \
name##_info = info->name##_info + name##_i; \
\
if (name##_np == playback) \
dai_info->playback.name = name##_info; \
if (name##_np == capture) \
dai_info->capture.name = name##_info; \
\
name##_i++; \
} \
}
V_128 = 0 ;
F_69 (dai_node, dai_np) {
V_124 = V_126 -> V_124 + V_128 ;
for ( V_29 = 0 ; ; V_29 ++ ) {
V_67 = F_70 ( V_118 , L_17 , V_29 ) ;
V_84 = F_70 ( V_118 , L_18 , V_29 ) ;
if ( ! V_67 && ! V_84 )
break;
F_68 ( V_41 ) ;
F_68 ( V_42 ) ;
if ( V_67 )
F_71 ( V_67 ) ;
if ( V_84 )
F_71 ( V_84 ) ;
}
V_128 ++ ;
}
}
static int F_72 ( struct V_112 * V_113 ,
const struct V_114 * V_115 ,
struct V_5 * V_6 )
{
struct V_133 * V_134 ;
struct V_125 * V_126 = F_64 ( V_6 ) ;
struct V_62 * V_63 ;
struct V_135 * V_136 , * V_137 ;
struct V_23 * V_24 = F_18 ( V_6 ) ;
int V_138 ;
int V_29 ;
F_63 ( V_113 , V_115 , V_6 ) ;
V_138 = V_126 -> V_132 ;
if ( ! V_138 ) {
F_21 ( V_24 , L_19 ) ;
return - V_52 ;
}
V_134 = F_67 ( V_24 , sizeof( * V_134 ) * V_138 , V_131 ) ;
V_63 = F_67 ( V_24 , sizeof( * V_63 ) * V_138 , V_131 ) ;
if ( ! V_134 || ! V_63 ) {
F_21 ( V_24 , L_20 ) ;
return - V_139 ;
}
V_6 -> V_140 = V_138 ;
V_6 -> V_141 = V_134 ;
V_6 -> V_63 = V_63 ;
for ( V_29 = 0 ; V_29 < V_138 ; V_29 ++ ) {
V_63 [ V_29 ] . V_126 = & V_126 -> V_124 [ V_29 ] ;
V_136 = V_63 [ V_29 ] . V_126 -> V_67 . V_41 ;
V_137 = V_63 [ V_29 ] . V_126 -> V_84 . V_41 ;
snprintf ( V_63 [ V_29 ] . V_4 , V_142 , L_21 , V_29 ) ;
V_134 [ V_29 ] . V_4 = V_63 [ V_29 ] . V_4 ;
V_134 [ V_29 ] . V_3 = & V_143 ;
if ( V_136 ) {
V_134 [ V_29 ] . V_67 . V_144 = V_145 ;
V_134 [ V_29 ] . V_67 . V_146 = V_147 ;
V_134 [ V_29 ] . V_67 . V_148 = 2 ;
V_134 [ V_29 ] . V_67 . V_149 = 2 ;
V_63 [ V_29 ] . V_67 . V_126 = & V_126 -> V_124 [ V_29 ] . V_67 ;
F_61 ( V_6 , & V_63 [ V_29 ] , & V_63 [ V_29 ] . V_67 ) ;
}
if ( V_137 ) {
V_134 [ V_29 ] . V_84 . V_144 = V_145 ;
V_134 [ V_29 ] . V_84 . V_146 = V_147 ;
V_134 [ V_29 ] . V_84 . V_148 = 2 ;
V_134 [ V_29 ] . V_84 . V_149 = 2 ;
V_63 [ V_29 ] . V_84 . V_126 = & V_126 -> V_124 [ V_29 ] . V_84 ;
F_61 ( V_6 , & V_63 [ V_29 ] , & V_63 [ V_29 ] . V_84 ) ;
}
F_36 ( V_24 , L_22 , V_63 [ V_29 ] . V_4 ,
V_136 ? L_23 : L_24 ,
V_137 ? L_18 : L_25 ) ;
}
return 0 ;
}
static int F_73 ( struct V_69 * V_70 )
{
struct V_21 * V_22 = V_70 -> V_22 ;
int V_51 = 0 ;
F_74 ( V_70 , & V_150 ) ;
V_51 = F_75 ( V_22 ,
V_151 ) ;
return V_51 ;
}
static int F_76 ( struct V_69 * V_70 ,
struct V_152 * V_153 )
{
return F_77 ( V_70 ,
F_78 ( V_153 ) ) ;
}
static T_5 F_79 ( struct V_69 * V_70 )
{
struct V_21 * V_22 = V_70 -> V_22 ;
struct V_65 * V_66 = F_55 ( V_70 ) ;
struct V_62 * V_63 = F_49 ( V_66 ) ;
struct V_17 * V_18 = F_56 ( V_63 , V_70 ) ;
return F_80 ( V_22 , V_18 -> V_72 ) ;
}
static int F_81 ( struct V_78 * V_79 )
{
struct V_5 * V_6 = F_50 ( V_79 -> V_81 ) ;
struct V_62 * V_63 ;
int V_29 , V_51 ;
F_82 (rdai, priv, i) {
V_51 = F_59 ( V_154 , & V_63 -> V_67 , V_63 , V_79 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_59 ( V_154 , & V_63 -> V_84 , V_63 , V_79 ) ;
if ( V_51 )
return V_51 ;
}
return F_83 (
V_79 -> V_155 ,
V_156 ,
V_79 -> V_157 -> V_158 -> V_24 ,
V_159 , V_160 ) ;
}
static void F_84 ( struct V_161 * V_155 )
{
F_85 ( V_155 ) ;
}
static int F_86 ( struct V_112 * V_113 )
{
struct V_125 * V_126 ;
struct V_5 * V_6 ;
struct V_23 * V_24 = & V_113 -> V_24 ;
struct V_62 * V_63 ;
const struct V_162 * V_163 = F_87 ( V_164 , V_24 ) ;
const struct V_114 * V_115 ;
int (* F_88 [])( struct V_112 * V_113 ,
const struct V_114 * V_115 ,
struct V_5 * V_6 ) = {
V_165 ,
rsnd_ssi_probe,
rsnd_src_probe,
rsnd_dvc_probe,
rsnd_adg_probe,
rsnd_dai_probe,
}
int F_89 ( struct V_112 * V_113 )
{
struct V_5 * V_6 = F_90 ( & V_113 -> V_24 ) ;
struct V_62 * V_63 ;
int V_51 , V_29 ;
F_91 ( & V_113 -> V_24 ) ;
F_82 (rdai, priv, i) {
V_51 = F_59 ( remove , & V_63 -> V_67 , V_63 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_59 ( remove , & V_63 -> V_84 , V_63 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
