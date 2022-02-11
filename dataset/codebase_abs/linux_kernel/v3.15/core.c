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
int F_27 ( struct V_5 * V_6 , struct V_10 * V_11 ,
int V_37 , int V_9 )
{
struct V_23 * V_24 = F_18 ( V_6 ) ;
struct V_38 V_39 ;
T_3 V_40 ;
int V_41 ;
if ( V_11 -> V_15 ) {
F_21 ( V_24 , L_4 ) ;
return - V_42 ;
}
F_28 ( V_40 ) ;
F_29 ( V_43 , V_40 ) ;
V_11 -> V_15 = F_30 ( V_40 , V_44 ,
( void * ) V_9 , V_24 ,
V_37 ? L_5 : L_6 ) ;
if ( ! V_11 -> V_15 ) {
F_21 ( V_24 , L_7 ) ;
return - V_42 ;
}
V_39 . V_45 = V_9 ;
V_39 . V_46 = 0 ;
V_39 . V_47 = 0 ;
V_39 . V_48 = V_37 ? V_49 : V_50 ;
V_41 = F_31 ( V_11 -> V_15 , & V_39 ) ;
if ( V_41 < 0 )
goto V_51;
V_11 -> V_31 = V_37 ? V_52 : V_53 ;
F_32 ( & V_11 -> V_13 , F_24 ) ;
return 0 ;
V_51:
F_33 ( V_6 , V_11 ) ;
return V_41 ;
}
void F_33 ( struct V_5 * V_6 ,
struct V_10 * V_11 )
{
if ( V_11 -> V_15 )
F_34 ( V_11 -> V_15 ) ;
V_11 -> V_15 = NULL ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
if ( ! V_2 )
return - V_42 ;
if ( V_18 -> V_2 [ V_2 -> type ] ) {
struct V_5 * V_6 = F_12 ( V_2 ) ;
struct V_23 * V_24 = F_18 ( V_6 ) ;
F_21 ( V_24 , L_8 ,
F_1 ( V_2 ) ,
F_36 ( V_2 ) ) ;
return - V_42 ;
}
V_18 -> V_2 [ V_2 -> type ] = V_2 ;
V_2 -> V_18 = V_18 ;
return 0 ;
}
int F_37 ( struct V_5 * V_6 , struct V_54 * V_55 )
{
int V_9 = V_55 - V_6 -> V_55 ;
if ( ( V_9 < 0 ) || ( V_9 >= F_38 ( V_6 ) ) )
return - V_56 ;
return V_9 ;
}
struct V_54 * F_39 ( struct V_5 * V_6 , int V_9 )
{
if ( ( V_9 < 0 ) || ( V_9 >= F_38 ( V_6 ) ) )
return NULL ;
return V_6 -> V_55 + V_9 ;
}
static struct V_54 * F_40 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_41 ( V_58 ) ;
return F_39 ( V_6 , V_58 -> V_9 ) ;
}
int F_42 ( struct V_54 * V_55 , struct V_17 * V_18 )
{
return & V_55 -> V_59 == V_18 ;
}
int F_19 ( struct V_17 * V_18 , int V_60 )
{
struct V_61 * V_62 = V_18 -> V_62 ;
struct V_21 * V_22 = V_62 -> V_22 ;
int V_63 = V_18 -> V_64 + V_60 ;
V_63 %= ( V_22 -> V_65 * V_18 -> V_20 ) ;
return V_63 ;
}
void F_16 ( struct V_17 * V_18 , int V_66 )
{
V_18 -> V_64 += V_66 ;
if ( V_18 -> V_64 >= V_18 -> V_67 ) {
struct V_61 * V_62 = V_18 -> V_62 ;
struct V_21 * V_22 = V_62 -> V_22 ;
V_18 -> V_68 ++ ;
V_18 -> V_67 += V_18 -> V_20 ;
if ( V_18 -> V_68 >= V_22 -> V_65 ) {
V_18 -> V_64 = 0 ;
V_18 -> V_68 = 0 ;
V_18 -> V_67 = V_18 -> V_20 ;
}
F_43 ( V_62 ) ;
}
}
static int F_44 ( struct V_17 * V_18 ,
struct V_61 * V_62 )
{
struct V_21 * V_22 = V_62 -> V_22 ;
V_18 -> V_62 = V_62 ;
V_18 -> V_64 = 0 ;
V_18 -> V_68 = 0 ;
V_18 -> V_20 = V_22 -> V_69 *
V_22 -> V_70 *
F_45 ( V_22 , 1 ) ;
V_18 -> V_67 = V_18 -> V_20 ;
return 0 ;
}
static
struct V_57 * F_46 ( struct V_61 * V_62 )
{
struct V_71 * V_72 = V_62 -> V_73 ;
return V_72 -> V_74 ;
}
static
struct V_17 * F_47 ( struct V_54 * V_55 ,
struct V_61 * V_62 )
{
if ( V_62 -> V_75 == V_76 )
return & V_55 -> V_59 ;
else
return & V_55 -> V_77 ;
}
static int F_48 ( struct V_61 * V_62 , int V_78 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = F_41 ( V_58 ) ;
struct V_54 * V_55 = F_40 ( V_58 ) ;
struct V_17 * V_18 = F_47 ( V_55 , V_62 ) ;
struct V_1 * V_2 = F_49 ( V_6 ,
F_37 ( V_6 , V_55 ) ,
F_42 ( V_55 , V_18 ) ) ;
int V_79 = F_36 ( V_2 ) ;
int V_41 ;
unsigned long V_19 ;
F_14 ( V_6 , V_19 ) ;
switch ( V_78 ) {
case V_80 :
V_41 = F_44 ( V_18 , V_62 ) ;
if ( V_41 < 0 )
goto V_81;
V_41 = F_50 ( V_6 , V_58 , V_82 , V_79 ) ;
if ( V_41 < 0 )
goto V_81;
V_41 = F_51 ( V_55 , V_18 , V_83 ) ;
if ( V_41 < 0 )
goto V_81;
V_41 = F_51 ( V_55 , V_18 , V_82 ) ;
if ( V_41 < 0 )
goto V_81;
break;
case V_84 :
V_41 = F_51 ( V_55 , V_18 , V_85 ) ;
if ( V_41 < 0 )
goto V_81;
V_41 = F_51 ( V_55 , V_18 , V_86 ) ;
if ( V_41 < 0 )
goto V_81;
V_41 = F_50 ( V_6 , V_58 , V_85 , V_79 ) ;
if ( V_41 < 0 )
goto V_81;
break;
default:
V_41 = - V_56 ;
}
V_81:
F_15 ( V_6 , V_19 ) ;
return V_41 ;
}
static int F_52 ( struct V_57 * V_58 , unsigned int V_87 )
{
struct V_54 * V_55 = F_40 ( V_58 ) ;
switch ( V_87 & V_88 ) {
case V_89 :
V_55 -> V_90 = 0 ;
break;
case V_91 :
V_55 -> V_90 = 1 ;
break;
default:
return - V_56 ;
}
switch ( V_87 & V_92 ) {
case V_93 :
V_55 -> V_94 = 0 ;
V_55 -> V_95 = 1 ;
break;
case V_96 :
V_55 -> V_94 = 1 ;
V_55 -> V_95 = 0 ;
break;
case V_97 :
V_55 -> V_94 = 1 ;
V_55 -> V_95 = 1 ;
break;
case V_98 :
default:
V_55 -> V_94 = 0 ;
V_55 -> V_95 = 0 ;
break;
}
switch ( V_87 & V_99 ) {
case V_100 :
V_55 -> V_101 = 0 ;
V_55 -> V_102 = 0 ;
break;
case V_103 :
V_55 -> V_101 = 1 ;
V_55 -> V_102 = 0 ;
break;
case V_104 :
V_55 -> V_101 = 1 ;
V_55 -> V_102 = 1 ;
break;
}
return 0 ;
}
static int F_53 ( struct V_5 * V_6 ,
struct V_54 * V_55 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_105 * V_106 = V_55 -> V_107 ;
int V_41 ;
int V_79 = - 1 ;
int V_108 = - 1 ;
if ( V_106 ) {
if ( F_54 ( V_18 , V_109 ) )
V_79 = F_55 ( V_6 , V_18 , V_109 ) ;
if ( F_54 ( V_18 , V_110 ) )
V_108 = F_55 ( V_6 , V_18 , V_110 ) ;
} else {
V_2 = F_49 ( V_6 ,
F_37 ( V_6 , V_55 ) ,
F_42 ( V_55 , V_18 ) ) ;
if ( ! V_2 )
return 0 ;
V_79 = V_108 = F_36 ( V_2 ) ;
}
V_41 = 0 ;
if ( V_108 >= 0 ) {
V_2 = F_56 ( V_6 , V_108 ) ;
V_41 = F_35 ( V_2 , V_18 ) ;
if ( V_41 < 0 )
return V_41 ;
}
if ( V_79 >= 0 ) {
V_2 = F_57 ( V_6 , V_79 ) ;
V_41 = F_35 ( V_2 , V_18 ) ;
if ( V_41 < 0 )
return V_41 ;
}
return V_41 ;
}
static void F_58 ( struct V_111 * V_112 ,
const struct V_113 * V_114 ,
struct V_5 * V_6 )
{
struct V_115 * V_116 , * V_117 ;
struct V_115 * V_118 , * V_119 ;
struct V_115 * V_120 , * V_121 ;
struct V_115 * V_59 , * V_77 ;
struct V_105 * V_106 ;
struct V_122 * V_107 = F_59 ( V_6 ) ;
struct V_23 * V_24 = & V_112 -> V_24 ;
int V_123 , V_29 ;
int V_124 , V_125 , V_126 ;
if ( ! V_114 )
return;
V_116 = F_60 ( V_24 -> V_127 , L_9 ) ;
if ( ! V_116 )
return;
V_123 = F_61 ( V_116 ) ;
if ( ! V_123 )
return;
V_106 = F_62 ( V_24 ,
sizeof( struct V_105 ) * V_123 ,
V_128 ) ;
if ( ! V_106 ) {
F_21 ( V_24 , L_10 ) ;
return;
}
V_107 -> V_129 = V_123 ;
V_107 -> V_106 = V_106 ;
V_118 = F_60 ( V_24 -> V_127 , L_11 ) ;
V_120 = F_60 ( V_24 -> V_127 , L_12 ) ;
#define F_63 ( V_4 ) \
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
V_124 = 0 ;
F_64 (dai_node, dai_np) {
V_106 = V_107 -> V_106 + V_124 ;
for ( V_29 = 0 ; ; V_29 ++ ) {
V_59 = F_65 ( V_117 , L_13 , V_29 ) ;
V_77 = F_65 ( V_117 , L_14 , V_29 ) ;
if ( ! V_59 && ! V_77 )
break;
F_63 ( V_109 ) ;
F_63 ( V_110 ) ;
if ( V_59 )
F_66 ( V_59 ) ;
if ( V_77 )
F_66 ( V_77 ) ;
}
V_124 ++ ;
}
}
static int F_67 ( struct V_111 * V_112 ,
const struct V_113 * V_114 ,
struct V_5 * V_6 )
{
struct V_130 * V_131 ;
struct V_122 * V_107 = F_59 ( V_6 ) ;
struct V_54 * V_55 ;
struct V_1 * V_132 , * V_133 ;
struct V_23 * V_24 = F_18 ( V_6 ) ;
int V_134 ;
int V_29 ;
F_58 ( V_112 , V_114 , V_6 ) ;
V_134 = V_107 -> V_129 ;
if ( ! V_134 ) {
for ( V_134 = 0 ; V_134 < 32 ; V_134 ++ ) {
V_132 = F_49 ( V_6 , V_134 , 1 ) ;
V_133 = F_49 ( V_6 , V_134 , 0 ) ;
if ( ! V_132 && ! V_133 )
break;
}
}
if ( ! V_134 ) {
F_21 ( V_24 , L_15 ) ;
return - V_42 ;
}
V_131 = F_62 ( V_24 , sizeof( * V_131 ) * V_134 , V_128 ) ;
V_55 = F_62 ( V_24 , sizeof( * V_55 ) * V_134 , V_128 ) ;
if ( ! V_131 || ! V_55 ) {
F_21 ( V_24 , L_16 ) ;
return - V_135 ;
}
V_6 -> V_136 = V_134 ;
V_6 -> V_137 = V_131 ;
V_6 -> V_55 = V_55 ;
for ( V_29 = 0 ; V_29 < V_134 ; V_29 ++ ) {
if ( V_107 -> V_106 )
V_55 [ V_29 ] . V_107 = & V_107 -> V_106 [ V_29 ] ;
V_132 = F_49 ( V_6 , V_29 , 1 ) ;
V_133 = F_49 ( V_6 , V_29 , 0 ) ;
snprintf ( V_55 [ V_29 ] . V_4 , V_138 , L_17 , V_29 ) ;
V_131 [ V_29 ] . V_4 = V_55 [ V_29 ] . V_4 ;
V_131 [ V_29 ] . V_3 = & V_139 ;
if ( V_132 ) {
V_131 [ V_29 ] . V_59 . V_140 = V_141 ;
V_131 [ V_29 ] . V_59 . V_142 = V_143 ;
V_131 [ V_29 ] . V_59 . V_144 = 2 ;
V_131 [ V_29 ] . V_59 . V_145 = 2 ;
if ( V_107 -> V_106 )
V_55 [ V_29 ] . V_59 . V_107 = & V_107 -> V_106 [ V_29 ] . V_59 ;
F_53 ( V_6 , & V_55 [ V_29 ] , & V_55 [ V_29 ] . V_59 ) ;
}
if ( V_133 ) {
V_131 [ V_29 ] . V_77 . V_140 = V_141 ;
V_131 [ V_29 ] . V_77 . V_142 = V_143 ;
V_131 [ V_29 ] . V_77 . V_144 = 2 ;
V_131 [ V_29 ] . V_77 . V_145 = 2 ;
if ( V_107 -> V_106 )
V_55 [ V_29 ] . V_77 . V_107 = & V_107 -> V_106 [ V_29 ] . V_77 ;
F_53 ( V_6 , & V_55 [ V_29 ] , & V_55 [ V_29 ] . V_77 ) ;
}
F_68 ( V_24 , L_18 , V_55 [ V_29 ] . V_4 ,
V_132 ? L_19 : L_20 ,
V_133 ? L_14 : L_21 ) ;
}
return 0 ;
}
static int F_69 ( struct V_61 * V_62 )
{
struct V_21 * V_22 = V_62 -> V_22 ;
int V_41 = 0 ;
F_70 ( V_62 , & V_146 ) ;
V_41 = F_71 ( V_22 ,
V_147 ) ;
return V_41 ;
}
static int F_72 ( struct V_61 * V_62 ,
struct V_148 * V_149 )
{
return F_73 ( V_62 ,
F_74 ( V_149 ) ) ;
}
static T_4 F_75 ( struct V_61 * V_62 )
{
struct V_21 * V_22 = V_62 -> V_22 ;
struct V_57 * V_58 = F_46 ( V_62 ) ;
struct V_54 * V_55 = F_40 ( V_58 ) ;
struct V_17 * V_18 = F_47 ( V_55 , V_62 ) ;
return F_76 ( V_22 , V_18 -> V_64 ) ;
}
static int F_77 ( struct V_71 * V_72 )
{
return F_78 (
V_72 -> V_150 ,
V_151 ,
V_72 -> V_152 -> V_153 -> V_24 ,
V_154 , V_155 ) ;
}
static void F_79 ( struct V_156 * V_150 )
{
F_80 ( V_150 ) ;
}
static int F_81 ( struct V_111 * V_112 )
{
struct V_122 * V_107 ;
struct V_5 * V_6 ;
struct V_23 * V_24 = & V_112 -> V_24 ;
struct V_54 * V_55 ;
const struct V_157 * V_158 = F_82 ( V_159 , V_24 ) ;
const struct V_113 * V_114 ;
int (* F_83 [])( struct V_111 * V_112 ,
const struct V_113 * V_114 ,
struct V_5 * V_6 ) = {
V_160 ,
rsnd_ssi_probe,
rsnd_src_probe,
rsnd_adg_probe,
rsnd_dai_probe,
}
int F_84 ( struct V_111 * V_112 )
{
struct V_5 * V_6 = F_85 ( & V_112 -> V_24 ) ;
struct V_54 * V_55 ;
int V_41 , V_29 ;
F_86 ( & V_112 -> V_24 ) ;
F_87 (rdai, priv, i) {
V_41 = F_51 ( V_55 , & V_55 -> V_59 , remove ) ;
if ( V_41 )
return V_41 ;
V_41 = F_51 ( V_55 , & V_55 -> V_77 , remove ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
