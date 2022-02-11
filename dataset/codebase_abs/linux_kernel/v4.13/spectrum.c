static int F_1 ( struct V_1 * V_1 ,
T_1 V_2 , T_2 * V_3 ,
T_3 * V_4 , T_1 * V_5 )
{
struct V_6 * V_6 =
F_2 ( V_1 , struct V_6 , V_1 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
char V_8 [ V_9 ] ;
int V_10 ;
F_3 ( V_8 , V_2 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_12 ) , V_8 ) ;
if ( V_10 )
return V_10 ;
F_6 ( V_8 , V_3 , V_4 ,
V_5 ) ;
* V_4 = F_7 ( T_3 , * V_4 , 2 ) ;
* V_5 = F_8 ( T_1 , * V_5 ,
V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , T_2 * V_14 )
{
struct V_6 * V_6 =
F_2 ( V_1 , struct V_6 , V_1 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
char V_15 [ V_16 ] ;
T_3 V_17 ;
int V_10 ;
F_10 ( V_15 , 0 , 0 , 0 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_18 ) , V_15 ) ;
if ( V_10 )
return V_10 ;
F_11 ( V_15 , V_14 , NULL , & V_17 ) ;
if ( V_17 != V_19 )
return - V_20 ;
F_10 ( V_15 ,
V_21 ,
0 , * V_14 , 0 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_18 ) , V_15 ) ;
}
static int F_13 ( struct V_1 * V_1 ,
T_2 V_14 , T_1 V_2 ,
T_2 V_22 )
{
struct V_6 * V_6 =
F_2 ( V_1 , struct V_6 , V_1 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
char V_15 [ V_16 ] ;
F_10 ( V_15 , V_23 ,
V_2 , V_14 , V_22 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_18 ) , V_15 ) ;
}
static int F_14 ( struct V_1 * V_1 ,
T_2 V_14 , T_3 * V_24 , T_1 V_25 ,
T_2 V_26 )
{
struct V_6 * V_6 =
F_2 ( V_1 , struct V_6 , V_1 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
char V_27 [ V_28 ] ;
F_15 ( V_27 , V_14 , V_26 , V_25 , V_24 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_29 ) , V_27 ) ;
}
static int F_16 ( struct V_1 * V_1 ,
T_2 V_14 , T_1 V_2 )
{
struct V_6 * V_6 =
F_2 ( V_1 , struct V_6 , V_1 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
char V_15 [ V_16 ] ;
F_10 ( V_15 , V_30 ,
V_2 , V_14 , 0 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_18 ) , V_15 ) ;
}
static int F_17 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_6 * V_6 =
F_2 ( V_1 , struct V_6 , V_1 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
char V_15 [ V_16 ] ;
F_10 ( V_15 , V_31 , 0 ,
V_14 , 0 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_18 ) , V_15 ) ;
}
static int F_18 ( struct V_1 * V_1 , T_2 V_14 ,
enum V_32 * V_33 ,
enum V_34 * V_35 )
{
struct V_6 * V_6 =
F_2 ( V_1 , struct V_6 , V_1 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
char V_15 [ V_16 ] ;
T_3 V_17 ;
T_3 V_36 ;
int V_10 ;
F_10 ( V_15 , 0 , 0 , V_14 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_18 ) , V_15 ) ;
if ( V_10 )
return V_10 ;
F_11 ( V_15 , NULL , & V_36 , & V_17 ) ;
* V_33 = V_17 ;
* V_35 = F_8 ( enum V_34 , V_36 ,
V_37 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_6 * V_6 =
F_2 ( V_1 , struct V_6 , V_1 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
char V_15 [ V_16 ] ;
F_10 ( V_15 , V_38 , 0 ,
V_14 , 0 ) ;
F_12 ( V_7 -> V_11 , F_5 ( V_18 ) , V_15 ) ;
}
static void F_20 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_6 * V_6 =
F_2 ( V_1 , struct V_6 , V_1 ) ;
struct V_7 * V_7 = V_6 -> V_7 ;
char V_15 [ V_16 ] ;
F_10 ( V_15 ,
V_39 , 0 ,
V_14 , 0 ) ;
F_12 ( V_7 -> V_11 , F_5 ( V_18 ) , V_15 ) ;
}
static int F_21 ( struct V_7 * V_7 ,
const struct V_40 * V_40 )
{
struct V_6 V_6 = {
. V_1 = {
. V_41 = & V_42 ,
. V_43 = V_7 -> V_44 -> V_43 ,
. V_45 = strlen ( V_7 -> V_44 -> V_43 ) ,
} ,
. V_7 = V_7
} ;
return F_22 ( & V_6 . V_1 , V_40 ) ;
}
static bool F_23 ( const struct V_46 * V_47 ,
const struct V_46 * V_48 )
{
if ( V_47 -> V_49 != V_48 -> V_49 )
return V_47 -> V_49 > V_48 -> V_49 ;
if ( V_47 -> V_50 != V_48 -> V_50 )
return V_47 -> V_50 > V_48 -> V_50 ;
return V_47 -> V_51 >= V_48 -> V_51 ;
}
static int F_24 ( struct V_7 * V_7 )
{
const struct V_46 * V_52 = & V_7 -> V_44 -> V_53 ;
const struct V_40 * V_40 ;
int V_10 ;
if ( F_23 ( V_52 , & V_54 ) )
return 0 ;
F_25 ( V_7 -> V_44 -> V_55 , L_1 ,
V_52 -> V_49 , V_52 -> V_50 , V_52 -> V_51 ) ;
F_25 ( V_7 -> V_44 -> V_55 , L_2 ,
V_56 ) ;
V_10 = F_26 ( & V_40 , V_56 ,
V_7 -> V_44 -> V_55 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_3 ,
V_56 ) ;
return V_10 ;
}
V_10 = F_21 ( V_7 , V_40 ) ;
F_28 ( V_40 ) ;
return V_10 ;
}
int F_29 ( struct V_7 * V_7 ,
unsigned int V_57 , T_4 * V_58 ,
T_4 * V_59 )
{
char V_60 [ V_61 ] ;
int V_10 ;
F_30 ( V_60 , V_57 , V_62 ,
V_63 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_64 ) , V_60 ) ;
if ( V_10 )
return V_10 ;
* V_58 = F_31 ( V_60 ) ;
* V_59 = F_32 ( V_60 ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_7 ,
unsigned int V_57 )
{
char V_60 [ V_61 ] ;
F_30 ( V_60 , V_57 , V_65 ,
V_63 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_64 ) , V_60 ) ;
}
int F_34 ( struct V_7 * V_7 ,
unsigned int * V_66 )
{
int V_10 ;
V_10 = F_35 ( V_7 , V_67 ,
V_66 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_33 ( V_7 , * V_66 ) ;
if ( V_10 )
goto V_68;
return 0 ;
V_68:
F_36 ( V_7 , V_67 ,
* V_66 ) ;
return V_10 ;
}
void F_37 ( struct V_7 * V_7 ,
unsigned int V_57 )
{
F_36 ( V_7 , V_67 ,
V_57 ) ;
}
static void F_38 ( struct V_69 * V_70 ,
const struct V_71 * V_72 )
{
char * V_73 = F_39 ( V_70 , V_74 ) ;
memset ( V_73 , 0 , V_74 ) ;
F_40 ( V_73 , V_75 ) ;
F_41 ( V_73 , V_76 ) ;
F_42 ( V_73 , V_77 ) ;
F_43 ( V_73 , 0 ) ;
F_44 ( V_73 , 1 ) ;
F_45 ( V_73 , V_72 -> V_78 ) ;
F_46 ( V_73 , V_79 ) ;
}
int F_47 ( struct V_80 * V_80 , T_1 V_81 ,
T_3 V_82 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
enum V_83 V_84 ;
char * V_85 ;
int V_10 ;
switch ( V_82 ) {
case V_86 :
V_84 = V_87 ;
break;
case V_88 :
V_84 = V_89 ;
break;
case V_90 :
case V_91 :
case V_92 :
V_84 = V_93 ;
break;
default:
F_48 () ;
}
V_85 = F_49 ( V_94 , V_95 ) ;
if ( ! V_85 )
return - V_96 ;
F_50 ( V_85 , V_80 -> V_78 ) ;
F_51 ( V_85 , V_81 , V_84 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_97 ) , V_85 ) ;
F_52 ( V_85 ) ;
return V_10 ;
}
static int F_53 ( struct V_7 * V_7 )
{
char V_98 [ V_99 ] = { 0 } ;
int V_10 ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_100 ) , V_98 ) ;
if ( V_10 )
return V_10 ;
F_54 ( V_98 , V_7 -> V_101 ) ;
return 0 ;
}
static int F_55 ( struct V_7 * V_7 )
{
int V_102 ;
if ( ! F_56 ( V_7 -> V_11 , V_103 ) )
return - V_104 ;
V_7 -> V_105 . V_106 = F_57 ( V_7 -> V_11 ,
V_103 ) ;
V_7 -> V_105 . V_107 = F_58 ( V_7 -> V_105 . V_106 ,
sizeof( struct V_108 ) ,
V_95 ) ;
if ( ! V_7 -> V_105 . V_107 )
return - V_96 ;
for ( V_102 = 0 ; V_102 < V_7 -> V_105 . V_106 ; V_102 ++ )
F_59 ( & V_7 -> V_105 . V_107 [ V_102 ] . V_109 ) ;
return 0 ;
}
static void F_60 ( struct V_7 * V_7 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_7 -> V_105 . V_106 ; V_102 ++ ) {
struct V_108 * V_110 = & V_7 -> V_105 . V_107 [ V_102 ] ;
F_61 ( ! F_62 ( & V_110 -> V_109 ) ) ;
}
F_52 ( V_7 -> V_105 . V_107 ) ;
}
static struct V_108 *
F_63 ( struct V_80 * V_111 )
{
struct V_7 * V_7 = V_111 -> V_7 ;
struct V_108 * V_112 ;
char V_113 [ V_114 ] ;
T_3 V_78 = V_111 -> V_78 ;
int V_115 ;
int V_102 ;
int V_10 ;
V_115 = - 1 ;
for ( V_102 = 0 ; V_102 < V_7 -> V_105 . V_106 ; V_102 ++ ) {
if ( ! V_7 -> V_105 . V_107 [ V_102 ] . V_116 ) {
V_115 = V_102 ;
V_112 = & V_7 -> V_105 . V_107 [ V_102 ] ;
break;
}
}
if ( V_115 < 0 )
return NULL ;
F_64 ( V_113 , V_115 , V_78 , true ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_117 ) , V_113 ) ;
if ( V_10 )
return NULL ;
V_112 -> V_116 = true ;
V_112 -> V_118 = V_115 ;
V_112 -> V_119 = 1 ;
V_112 -> V_78 = V_78 ;
return V_112 ;
}
static void F_65 ( struct V_7 * V_7 ,
struct V_108 * V_112 )
{
T_3 V_78 = V_112 -> V_78 ;
char V_113 [ V_114 ] ;
int V_120 = V_112 -> V_118 ;
F_64 ( V_113 , V_120 , V_78 , false ) ;
F_12 ( V_7 -> V_11 , F_5 ( V_117 ) , V_113 ) ;
V_112 -> V_116 = false ;
}
static struct V_108 *
F_66 ( struct V_80 * V_111 )
{
struct V_7 * V_7 = V_111 -> V_7 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_7 -> V_105 . V_106 ; V_102 ++ ) {
struct V_108 * V_110 = & V_7 -> V_105 . V_107 [ V_102 ] ;
if ( V_110 -> V_116 && V_110 -> V_78 == V_111 -> V_78 )
return V_110 ;
}
return NULL ;
}
static struct V_108
* F_67 ( struct V_80 * V_111 )
{
struct V_108 * V_112 ;
V_112 = F_66 ( V_111 ) ;
if ( V_112 ) {
V_112 -> V_119 ++ ;
return V_112 ;
}
return F_63 ( V_111 ) ;
}
static int F_68 ( struct V_7 * V_7 ,
struct V_108 * V_112 )
{
F_69 ( ! V_112 -> V_119 ) ;
if ( -- V_112 -> V_119 == 0 )
F_65 ( V_7 , V_112 ) ;
return 0 ;
}
static bool F_70 ( struct V_80 * V_111 )
{
struct V_7 * V_7 = V_111 -> V_7 ;
struct V_121 * V_122 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_7 -> V_105 . V_106 ; V_102 ++ ) {
struct V_108 * V_110 = & V_7 -> V_105 . V_107 [ V_102 ] ;
F_71 (p, &curr->bound_ports_list, list)
if ( V_122 -> V_78 == V_111 -> V_78 &&
V_122 -> type == V_123 )
return true ;
}
return false ;
}
static int F_72 ( const struct V_7 * V_7 ,
int V_124 )
{
return F_73 ( V_7 , V_124 * 5 / 2 ) + 1 ;
}
static int F_74 ( struct V_80 * V_111 , T_1 V_124 )
{
struct V_7 * V_7 = V_111 -> V_7 ;
char V_125 [ V_126 ] ;
int V_10 ;
if ( F_70 ( V_111 ) ) {
T_2 V_127 = F_72 ( V_7 , V_124 ) ;
F_75 ( V_125 , V_111 -> V_78 , V_127 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_128 ) , V_125 ) ;
if ( V_10 ) {
F_76 ( V_111 -> V_55 , L_4 ) ;
return V_10 ;
}
}
return 0 ;
}
static struct V_121 *
F_77 ( struct V_80 * V_111 ,
struct V_108 * V_112 )
{
struct V_121 * V_122 ;
F_71 (p, &span_entry->bound_ports_list, list)
if ( V_111 -> V_78 == V_122 -> V_78 )
return V_122 ;
return NULL ;
}
static int
F_78 ( struct V_80 * V_111 ,
struct V_108 * V_112 ,
enum V_129 type )
{
struct V_121 * V_130 ;
struct V_7 * V_7 = V_111 -> V_7 ;
char V_131 [ V_132 ] ;
char V_125 [ V_126 ] ;
int V_120 = V_112 -> V_118 ;
int V_10 ;
if ( type == V_123 ) {
T_2 V_127 = F_72 ( V_7 ,
V_111 -> V_55 -> V_124 ) ;
F_75 ( V_125 , V_111 -> V_78 , V_127 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_128 ) , V_125 ) ;
if ( V_10 ) {
F_76 ( V_111 -> V_55 , L_5 ) ;
return V_10 ;
}
}
F_79 ( V_131 , V_111 -> V_78 ,
(enum V_133 ) type , true , V_120 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_134 ) , V_131 ) ;
if ( V_10 )
goto V_135;
V_130 = F_80 ( sizeof( * V_130 ) , V_95 ) ;
if ( ! V_130 ) {
V_10 = - V_96 ;
goto V_136;
}
V_130 -> V_78 = V_111 -> V_78 ;
V_130 -> type = type ;
F_81 ( & V_130 -> V_137 , & V_112 -> V_109 ) ;
return 0 ;
V_135:
V_136:
if ( type == V_123 ) {
F_75 ( V_125 , V_111 -> V_78 , 0 ) ;
F_12 ( V_7 -> V_11 , F_5 ( V_128 ) , V_125 ) ;
}
return V_10 ;
}
static void
F_82 ( struct V_80 * V_111 ,
struct V_108 * V_112 ,
enum V_129 type )
{
struct V_121 * V_130 ;
struct V_7 * V_7 = V_111 -> V_7 ;
char V_131 [ V_132 ] ;
char V_125 [ V_126 ] ;
int V_120 = V_112 -> V_118 ;
V_130 = F_77 ( V_111 , V_112 ) ;
if ( ! V_130 )
return;
F_79 ( V_131 , V_111 -> V_78 ,
(enum V_133 ) type , false , V_120 ) ;
F_12 ( V_7 -> V_11 , F_5 ( V_134 ) , V_131 ) ;
if ( type == V_123 ) {
F_75 ( V_125 , V_111 -> V_78 , 0 ) ;
F_12 ( V_7 -> V_11 , F_5 ( V_128 ) , V_125 ) ;
}
F_68 ( V_7 , V_112 ) ;
F_83 ( & V_130 -> V_137 ) ;
F_52 ( V_130 ) ;
}
static int F_84 ( struct V_80 * V_138 ,
struct V_80 * V_139 ,
enum V_129 type )
{
struct V_7 * V_7 = V_138 -> V_7 ;
struct V_108 * V_112 ;
int V_10 ;
V_112 = F_67 ( V_139 ) ;
if ( ! V_112 )
return - V_140 ;
F_85 ( V_138 -> V_55 , L_6 ,
V_112 -> V_118 ) ;
V_10 = F_78 ( V_138 , V_112 , type ) ;
if ( V_10 )
goto V_141;
return 0 ;
V_141:
F_68 ( V_7 , V_112 ) ;
return V_10 ;
}
static void F_86 ( struct V_80 * V_138 ,
struct V_80 * V_139 ,
enum V_129 type )
{
struct V_108 * V_112 ;
V_112 = F_66 ( V_139 ) ;
if ( ! V_112 ) {
F_76 ( V_138 -> V_55 , L_7 ) ;
return;
}
F_85 ( V_138 -> V_55 , L_8 ,
V_112 -> V_118 ) ;
F_82 ( V_138 , V_112 , type ) ;
}
static int F_87 ( struct V_80 * V_80 ,
bool V_142 , T_2 V_143 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_144 [ V_145 ] ;
F_88 ( V_144 , V_80 -> V_78 , V_142 , V_143 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_146 ) , V_144 ) ;
}
static int F_89 ( struct V_80 * V_80 ,
bool V_147 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_148 [ V_149 ] ;
F_90 ( V_148 , V_80 -> V_78 ,
V_147 ? V_150 :
V_151 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_152 ) , V_148 ) ;
}
static int F_91 ( struct V_80 * V_80 ,
unsigned char * V_153 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_154 [ V_155 ] ;
F_92 ( V_154 , true , V_80 -> V_78 ) ;
F_93 ( V_154 , V_153 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_156 ) , V_154 ) ;
}
static int F_94 ( struct V_80 * V_80 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
unsigned char * V_153 = V_80 -> V_55 -> V_157 ;
F_95 ( V_153 , V_7 -> V_101 ) ;
V_153 [ V_158 - 1 ] += V_80 -> V_78 ;
return F_91 ( V_80 , V_153 ) ;
}
static int F_96 ( struct V_80 * V_80 , T_1 V_124 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_159 [ V_160 ] ;
int V_161 ;
int V_10 ;
V_124 += V_74 + V_162 ;
F_97 ( V_159 , V_80 -> V_78 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_163 ) , V_159 ) ;
if ( V_10 )
return V_10 ;
V_161 = F_98 ( V_159 ) ;
if ( V_124 > V_161 )
return - V_164 ;
F_97 ( V_159 , V_80 -> V_78 , V_124 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_163 ) , V_159 ) ;
}
static int F_99 ( struct V_80 * V_80 , T_3 V_165 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_166 [ V_167 ] ;
F_100 ( V_166 , V_165 , V_80 -> V_78 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_168 ) , V_166 ) ;
}
int F_101 ( struct V_80 * V_80 , bool V_142 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_169 [ V_170 ] ;
F_102 ( V_169 , V_80 -> V_78 , V_142 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_171 ) , V_169 ) ;
}
int F_103 ( struct V_80 * V_80 , T_1 V_81 ,
bool V_172 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char * V_173 ;
int V_10 ;
V_173 = F_49 ( V_174 , V_95 ) ;
if ( ! V_173 )
return - V_96 ;
F_104 ( V_173 , V_80 -> V_78 , V_81 , V_81 ,
V_172 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_175 ) , V_173 ) ;
F_52 ( V_173 ) ;
return V_10 ;
}
static int F_105 ( struct V_80 * V_80 ,
T_1 V_81 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_176 [ V_177 ] ;
F_106 ( V_176 , V_80 -> V_78 , V_81 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_178 ) , V_176 ) ;
}
static int F_107 ( struct V_80 * V_80 ,
bool V_179 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_180 [ V_181 ] ;
F_108 ( V_180 , V_80 -> V_78 , V_179 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_182 ) , V_180 ) ;
}
int F_109 ( struct V_80 * V_80 , T_1 V_81 )
{
int V_10 ;
if ( ! V_81 ) {
V_10 = F_107 ( V_80 , false ) ;
if ( V_10 )
return V_10 ;
} else {
V_10 = F_105 ( V_80 , V_81 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_107 ( V_80 , true ) ;
if ( V_10 )
goto V_183;
}
V_80 -> V_184 = V_81 ;
return 0 ;
V_183:
F_105 ( V_80 , V_80 -> V_184 ) ;
return V_10 ;
}
static int
F_110 ( struct V_80 * V_80 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_185 [ V_186 ] ;
F_111 ( V_185 , V_80 -> V_78 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_187 ) , V_185 ) ;
}
static int F_112 ( struct V_7 * V_7 ,
T_3 V_78 , T_3 * V_188 ,
T_3 * V_189 , T_3 * V_190 )
{
char V_191 [ V_192 ] ;
int V_10 ;
F_113 ( V_191 , V_78 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_193 ) , V_191 ) ;
if ( V_10 )
return V_10 ;
* V_188 = F_114 ( V_191 , 0 ) ;
* V_189 = F_115 ( V_191 ) ;
* V_190 = F_116 ( V_191 , 0 ) ;
return 0 ;
}
static int F_117 ( struct V_80 * V_80 ,
T_3 V_194 , T_3 V_195 , T_3 V_196 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_191 [ V_192 ] ;
int V_102 ;
F_113 ( V_191 , V_80 -> V_78 ) ;
F_118 ( V_191 , V_195 ) ;
for ( V_102 = 0 ; V_102 < V_195 ; V_102 ++ ) {
F_119 ( V_191 , V_102 , V_194 ) ;
F_120 ( V_191 , V_102 , V_196 + V_102 ) ;
}
return F_12 ( V_7 -> V_11 , F_5 ( V_193 ) , V_191 ) ;
}
static int F_121 ( struct V_80 * V_80 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_191 [ V_192 ] ;
F_113 ( V_191 , V_80 -> V_78 ) ;
F_118 ( V_191 , 0 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_193 ) , V_191 ) ;
}
static int F_122 ( struct V_197 * V_55 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
int V_10 ;
V_10 = F_89 ( V_80 , true ) ;
if ( V_10 )
return V_10 ;
F_124 ( V_55 ) ;
return 0 ;
}
static int F_125 ( struct V_197 * V_55 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
F_126 ( V_55 ) ;
return F_89 ( V_80 , false ) ;
}
static T_5 F_127 ( struct V_69 * V_70 ,
struct V_197 * V_55 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
struct V_198 * V_199 ;
const struct V_71 V_72 = {
. V_78 = V_80 -> V_78 ,
. V_200 = false ,
} ;
T_4 V_201 ;
int V_10 ;
if ( F_128 ( V_7 -> V_11 , & V_72 ) )
return V_202 ;
if ( F_129 ( F_130 ( V_70 ) < V_74 ) ) {
struct V_69 * V_203 = V_70 ;
V_70 = F_131 ( V_70 , V_74 ) ;
if ( ! V_70 ) {
F_132 ( V_80 -> V_199 -> V_204 ) ;
F_133 ( V_203 ) ;
return V_205 ;
}
F_134 ( V_203 ) ;
}
if ( F_135 ( V_70 ) ) {
F_132 ( V_80 -> V_199 -> V_204 ) ;
return V_205 ;
}
F_38 ( V_70 , & V_72 ) ;
V_201 = V_70 -> V_201 - V_74 ;
V_10 = F_136 ( V_7 -> V_11 , V_70 , & V_72 ) ;
if ( ! V_10 ) {
V_199 = F_137 ( V_80 -> V_199 ) ;
F_138 ( & V_199 -> V_206 ) ;
V_199 -> V_207 ++ ;
V_199 -> V_208 += V_201 ;
F_139 ( & V_199 -> V_206 ) ;
} else {
F_132 ( V_80 -> V_199 -> V_204 ) ;
F_133 ( V_70 ) ;
}
return V_205 ;
}
static void F_140 ( struct V_197 * V_55 )
{
}
static int F_141 ( struct V_197 * V_55 , void * V_122 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_209 * V_153 = V_122 ;
int V_10 ;
if ( ! F_142 ( V_153 -> V_210 ) )
return - V_211 ;
V_10 = F_91 ( V_80 , V_153 -> V_210 ) ;
if ( V_10 )
return V_10 ;
memcpy ( V_55 -> V_157 , V_153 -> V_210 , V_55 -> V_212 ) ;
return 0 ;
}
static T_1 F_143 ( const struct V_7 * V_7 ,
int V_124 )
{
return 2 * F_73 ( V_7 , V_124 ) ;
}
static T_1 F_144 ( const struct V_7 * V_7 , int V_124 ,
T_1 V_213 )
{
V_213 = F_73 ( V_7 , F_145 ( V_213 ,
V_214 ) ) ;
return V_215 * V_213 + F_73 ( V_7 ,
V_124 ) ;
}
static T_1 F_146 ( const struct V_7 * V_7 , int V_124 ,
T_1 V_213 , bool V_216 , bool V_217 )
{
if ( V_216 )
return F_144 ( V_7 , V_124 , V_213 ) ;
else if ( V_217 )
return F_73 ( V_7 , V_218 ) ;
else
return 0 ;
}
static void F_147 ( char * V_219 , int V_115 , T_1 V_25 , T_1 V_220 ,
bool V_221 )
{
if ( V_221 )
F_148 ( V_219 , V_115 , V_25 ) ;
else
F_149 ( V_219 , V_115 , V_25 ,
V_220 ) ;
}
int F_150 ( struct V_80 * V_80 , int V_124 ,
T_3 * V_222 , bool V_223 ,
struct V_224 * V_225 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
T_3 V_226 = ! ! V_225 ? V_225 -> V_226 : 0 ;
T_1 V_213 = ! ! V_225 ? V_225 -> V_213 : 0 ;
char V_219 [ V_227 ] ;
int V_102 , V_228 , V_10 ;
F_151 ( V_219 , V_80 -> V_78 , 0 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_229 ) , V_219 ) ;
if ( V_10 )
return V_10 ;
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ ) {
bool V_231 = false ;
bool V_216 = false ;
bool V_221 ;
T_1 V_220 ;
for ( V_228 = 0 ; V_228 < V_230 ; V_228 ++ ) {
if ( V_222 [ V_228 ] == V_102 ) {
V_216 = V_226 & F_152 ( V_228 ) ;
V_231 = true ;
break;
}
}
if ( ! V_231 )
continue;
V_221 = ! ( V_216 || V_223 ) ;
V_220 = F_143 ( V_7 , V_124 ) ;
V_213 = F_146 ( V_7 , V_124 , V_213 , V_216 ,
V_223 ) ;
F_147 ( V_219 , V_102 , V_220 + V_213 , V_220 , V_221 ) ;
}
return F_12 ( V_7 -> V_11 , F_5 ( V_229 ) , V_219 ) ;
}
static int F_153 ( struct V_80 * V_80 ,
int V_124 , bool V_223 )
{
T_3 V_232 [ V_230 ] = { 0 } ;
bool V_233 = ! ! V_80 -> V_234 . V_235 ;
struct V_224 * V_225 ;
T_3 * V_222 ;
V_222 = V_233 ? V_80 -> V_234 . V_235 -> V_222 : V_232 ;
V_225 = V_233 ? V_80 -> V_234 . V_216 : NULL ;
return F_150 ( V_80 , V_124 , V_222 ,
V_223 , V_225 ) ;
}
static int F_154 ( struct V_197 * V_55 , int V_124 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
bool V_223 = F_155 ( V_80 ) ;
int V_10 ;
V_10 = F_153 ( V_80 , V_124 , V_223 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_74 ( V_80 , V_124 ) ;
if ( V_10 )
goto V_236;
V_10 = F_96 ( V_80 , V_124 ) ;
if ( V_10 )
goto V_237;
V_55 -> V_124 = V_124 ;
return 0 ;
V_237:
F_74 ( V_80 , V_55 -> V_124 ) ;
V_236:
F_153 ( V_80 , V_55 -> V_124 , V_223 ) ;
return V_10 ;
}
static int
F_156 ( const struct V_197 * V_55 ,
struct V_238 * V_239 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_198 * V_122 ;
T_4 V_240 , V_241 , V_207 , V_208 ;
T_2 V_204 = 0 ;
unsigned int V_242 ;
int V_102 ;
F_157 (i) {
V_122 = F_158 ( V_80 -> V_199 , V_102 ) ;
do {
V_242 = F_159 ( & V_122 -> V_206 ) ;
V_240 = V_122 -> V_240 ;
V_241 = V_122 -> V_241 ;
V_207 = V_122 -> V_207 ;
V_208 = V_122 -> V_208 ;
} while ( F_160 ( & V_122 -> V_206 , V_242 ) );
V_239 -> V_240 += V_240 ;
V_239 -> V_241 += V_241 ;
V_239 -> V_207 += V_207 ;
V_239 -> V_208 += V_208 ;
V_204 += V_122 -> V_204 ;
}
V_239 -> V_204 = V_204 ;
return 0 ;
}
static bool F_161 ( const struct V_197 * V_55 , int V_243 )
{
switch ( V_243 ) {
case V_244 :
return true ;
}
return false ;
}
static int F_162 ( int V_243 , const struct V_197 * V_55 ,
void * V_245 )
{
switch ( V_243 ) {
case V_244 :
return F_156 ( V_55 , V_245 ) ;
}
return - V_164 ;
}
static int F_163 ( struct V_197 * V_55 , int V_246 ,
int V_247 , char * V_248 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
F_164 ( V_248 , V_80 -> V_78 , V_246 , V_247 ) ;
return F_4 ( V_7 -> V_11 , F_5 ( V_249 ) , V_248 ) ;
}
static int F_165 ( struct V_197 * V_55 ,
struct V_238 * V_239 )
{
char V_248 [ V_250 ] ;
int V_10 ;
V_10 = F_163 ( V_55 , V_251 ,
0 , V_248 ) ;
if ( V_10 )
goto V_252;
V_239 -> V_207 =
F_166 ( V_248 ) ;
V_239 -> V_240 =
F_167 ( V_248 ) ;
V_239 -> V_208 =
F_168 ( V_248 ) ;
V_239 -> V_241 =
F_169 ( V_248 ) ;
V_239 -> V_253 =
F_170 ( V_248 ) ;
V_239 -> V_254 =
F_171 ( V_248 ) ;
V_239 -> V_255 =
F_172 ( V_248 ) ;
V_239 -> V_256 = (
F_173 ( V_248 ) +
F_174 ( V_248 ) +
F_175 ( V_248 ) ) ;
V_239 -> V_257 = ( V_239 -> V_254 +
V_239 -> V_255 + V_239 -> V_256 ) ;
V_252:
return V_10 ;
}
static void F_176 ( struct V_258 * V_259 )
{
struct V_80 * V_80 =
F_2 ( V_259 , struct V_80 ,
V_260 . V_261 . V_259 ) ;
if ( ! F_177 ( V_80 -> V_55 ) )
goto V_252;
F_165 ( V_80 -> V_55 ,
V_80 -> V_260 . V_262 ) ;
V_252:
F_178 ( & V_80 -> V_260 . V_261 ,
V_263 ) ;
}
static void
F_179 ( struct V_197 * V_55 ,
struct V_238 * V_239 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
memcpy ( V_239 , V_80 -> V_260 . V_262 , sizeof( * V_239 ) ) ;
}
static int F_180 ( struct V_80 * V_80 ,
T_1 V_264 , T_1 V_265 ,
bool V_266 , bool V_267 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char * V_268 ;
int V_10 ;
V_268 = F_49 ( V_269 , V_95 ) ;
if ( ! V_268 )
return - V_96 ;
F_181 ( V_268 , V_80 -> V_78 , V_264 ,
V_265 , V_266 , V_267 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_270 ) , V_268 ) ;
F_52 ( V_268 ) ;
return V_10 ;
}
int F_182 ( struct V_80 * V_80 , T_1 V_264 ,
T_1 V_265 , bool V_266 , bool V_267 )
{
T_1 V_81 , V_271 ;
int V_10 ;
for ( V_81 = V_264 ; V_81 <= V_265 ;
V_81 += V_272 ) {
V_271 = F_183 ( ( T_1 ) ( V_81 + V_272 - 1 ) ,
V_265 ) ;
V_10 = F_180 ( V_80 , V_81 , V_271 ,
V_266 , V_267 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_184 ( struct V_80 * V_80 )
{
struct V_273 * V_273 , * V_274 ;
F_185 (mlxsw_sp_port_vlan, tmp,
&mlxsw_sp_port->vlans_list, list)
F_186 ( V_273 ) ;
}
static struct V_273 *
F_187 ( struct V_80 * V_80 , T_1 V_81 )
{
struct V_273 * V_273 ;
bool V_267 = V_81 == 1 ;
int V_10 ;
V_10 = F_182 ( V_80 , V_81 , V_81 , true , V_267 ) ;
if ( V_10 )
return F_188 ( V_10 ) ;
V_273 = F_80 ( sizeof( * V_273 ) , V_95 ) ;
if ( ! V_273 ) {
V_10 = - V_96 ;
goto V_275;
}
V_273 -> V_80 = V_80 ;
V_273 -> V_81 = V_81 ;
F_189 ( & V_273 -> V_137 , & V_80 -> V_276 ) ;
return V_273 ;
V_275:
F_182 ( V_80 , V_81 , V_81 , false , false ) ;
return F_188 ( V_10 ) ;
}
static void
F_190 ( struct V_273 * V_273 )
{
struct V_80 * V_80 = V_273 -> V_80 ;
T_1 V_81 = V_273 -> V_81 ;
F_83 ( & V_273 -> V_137 ) ;
F_52 ( V_273 ) ;
F_182 ( V_80 , V_81 , V_81 , false , false ) ;
}
struct V_273 *
F_191 ( struct V_80 * V_80 , T_1 V_81 )
{
struct V_273 * V_273 ;
V_273 = F_192 ( V_80 , V_81 ) ;
if ( V_273 )
return V_273 ;
return F_187 ( V_80 , V_81 ) ;
}
void F_186 ( struct V_273 * V_273 )
{
struct V_277 * V_278 = V_273 -> V_278 ;
if ( V_273 -> V_279 )
F_193 ( V_273 ) ;
else if ( V_278 )
F_194 ( V_273 ) ;
F_190 ( V_273 ) ;
}
static int F_195 ( struct V_197 * V_55 ,
T_6 T_7 V_280 , T_1 V_81 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
if ( ! V_81 )
return 0 ;
return F_196 ( F_191 ( V_80 , V_81 ) ) ;
}
static int F_197 ( struct V_197 * V_55 ,
T_6 T_7 V_280 , T_1 V_81 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_273 * V_273 ;
if ( ! V_81 )
return 0 ;
V_273 = F_192 ( V_80 , V_81 ) ;
if ( ! V_273 )
return 0 ;
F_186 ( V_273 ) ;
return 0 ;
}
static int F_198 ( struct V_197 * V_55 , char * V_281 ,
T_8 V_201 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
T_3 V_194 = V_80 -> V_282 . V_194 ;
T_3 V_195 = V_80 -> V_282 . V_195 ;
T_3 V_196 = V_80 -> V_282 . V_196 ;
int V_10 ;
if ( ! V_80 -> V_283 )
V_10 = snprintf ( V_281 , V_201 , L_9 , V_194 + 1 ) ;
else
V_10 = snprintf ( V_281 , V_201 , L_10 , V_194 + 1 ,
V_196 / V_195 ) ;
if ( V_10 >= V_201 )
return - V_164 ;
return 0 ;
}
static struct V_284 *
F_199 ( struct V_80 * V_111 ,
unsigned long V_285 ) {
struct V_284 * V_286 ;
F_71 (mall_tc_entry, &port->mall_tc_list, list)
if ( V_286 -> V_285 == V_285 )
return V_286 ;
return NULL ;
}
static int
F_200 ( struct V_80 * V_80 ,
struct V_287 * V_288 ,
const struct V_289 * V_47 ,
bool V_290 )
{
struct V_291 * V_291 = F_201 ( V_80 -> V_55 ) ;
enum V_129 V_292 ;
struct V_80 * V_293 ;
struct V_197 * V_294 ;
int V_295 ;
V_295 = F_202 ( V_47 ) ;
V_294 = F_203 ( V_291 , V_295 ) ;
if ( ! V_294 ) {
F_76 ( V_80 -> V_55 , L_11 ) ;
return - V_164 ;
}
if ( ! F_204 ( V_294 ) ) {
F_76 ( V_80 -> V_55 , L_12 ) ;
return - V_296 ;
}
V_293 = F_123 ( V_294 ) ;
V_288 -> V_297 = V_293 -> V_78 ;
V_288 -> V_290 = V_290 ;
V_292 = V_290 ? V_298 : V_123 ;
return F_84 ( V_80 , V_293 , V_292 ) ;
}
static void
F_205 ( struct V_80 * V_80 ,
struct V_287 * V_288 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
enum V_129 V_292 ;
struct V_80 * V_293 ;
V_293 = V_7 -> V_299 [ V_288 -> V_297 ] ;
V_292 = V_288 -> V_290 ?
V_298 : V_123 ;
F_86 ( V_80 , V_293 , V_292 ) ;
}
static int
F_206 ( struct V_80 * V_80 ,
struct V_300 * V_301 ,
const struct V_289 * V_47 ,
bool V_290 )
{
int V_10 ;
if ( ! V_80 -> V_302 )
return - V_296 ;
if ( F_207 ( V_80 -> V_302 -> V_303 ) ) {
F_76 ( V_80 -> V_55 , L_13 ) ;
return - V_304 ;
}
if ( F_208 ( V_47 ) > V_305 ) {
F_76 ( V_80 -> V_55 , L_14 ) ;
return - V_296 ;
}
F_209 ( V_80 -> V_302 -> V_303 ,
F_210 ( V_47 ) ) ;
V_80 -> V_302 -> V_306 = F_211 ( V_47 ) ;
V_80 -> V_302 -> V_307 = F_212 ( V_47 ) ;
V_80 -> V_302 -> V_143 = F_208 ( V_47 ) ;
V_10 = F_87 ( V_80 , true , F_208 ( V_47 ) ) ;
if ( V_10 )
goto V_308;
return 0 ;
V_308:
F_213 ( V_80 -> V_302 -> V_303 , NULL ) ;
return V_10 ;
}
static void
F_214 ( struct V_80 * V_80 )
{
if ( ! V_80 -> V_302 )
return;
F_87 ( V_80 , false , 1 ) ;
F_213 ( V_80 -> V_302 -> V_303 , NULL ) ;
}
static int F_215 ( struct V_80 * V_80 ,
T_6 V_309 ,
struct V_300 * V_301 ,
bool V_290 )
{
struct V_284 * V_286 ;
const struct V_289 * V_47 ;
F_216 ( V_310 ) ;
int V_10 ;
if ( ! F_217 ( V_301 -> V_311 ) ) {
F_76 ( V_80 -> V_55 , L_15 ) ;
return - V_296 ;
}
V_286 = F_80 ( sizeof( * V_286 ) , V_95 ) ;
if ( ! V_286 )
return - V_96 ;
V_286 -> V_285 = V_301 -> V_285 ;
F_218 ( V_301 -> V_311 , & V_310 ) ;
V_47 = F_219 ( & V_310 , struct V_289 , V_137 ) ;
if ( F_220 ( V_47 ) && V_309 == F_221 ( V_312 ) ) {
struct V_287 * V_288 ;
V_286 -> type = V_313 ;
V_288 = & V_286 -> V_288 ;
V_10 = F_200 ( V_80 ,
V_288 , V_47 , V_290 ) ;
} else if ( F_222 ( V_47 ) && V_309 == F_221 ( V_312 ) ) {
V_286 -> type = V_314 ;
V_10 = F_206 ( V_80 , V_301 ,
V_47 , V_290 ) ;
} else {
V_10 = - V_296 ;
}
if ( V_10 )
goto V_315;
F_81 ( & V_286 -> V_137 , & V_80 -> V_316 ) ;
return 0 ;
V_315:
F_52 ( V_286 ) ;
return V_10 ;
}
static void F_223 ( struct V_80 * V_80 ,
struct V_300 * V_301 )
{
struct V_284 * V_286 ;
V_286 = F_199 ( V_80 ,
V_301 -> V_285 ) ;
if ( ! V_286 ) {
F_85 ( V_80 -> V_55 , L_16 ) ;
return;
}
F_83 ( & V_286 -> V_137 ) ;
switch ( V_286 -> type ) {
case V_313 :
F_205 ( V_80 ,
& V_286 -> V_288 ) ;
break;
case V_314 :
F_214 ( V_80 ) ;
break;
default:
F_69 ( 1 ) ;
}
F_52 ( V_286 ) ;
}
static int F_224 ( struct V_197 * V_55 , T_2 V_317 ,
T_2 V_318 , T_6 V_280 ,
struct V_319 * V_320 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
bool V_290 = F_225 ( V_317 ) == F_225 ( V_321 ) ;
if ( V_318 )
return - V_296 ;
switch ( V_320 -> type ) {
case V_322 :
switch ( V_320 -> V_323 -> V_324 ) {
case V_325 :
return F_215 ( V_80 ,
V_280 ,
V_320 -> V_323 ,
V_290 ) ;
case V_326 :
F_223 ( V_80 ,
V_320 -> V_323 ) ;
return 0 ;
default:
return - V_296 ;
}
case V_327 :
switch ( V_320 -> V_328 -> V_324 ) {
case V_329 :
return F_226 ( V_80 , V_290 ,
V_280 , V_320 -> V_328 ) ;
case V_330 :
F_227 ( V_80 , V_290 ,
V_320 -> V_328 ) ;
return 0 ;
case V_331 :
return F_228 ( V_80 , V_290 ,
V_320 -> V_328 ) ;
default:
return - V_296 ;
}
}
return - V_296 ;
}
static void F_229 ( struct V_197 * V_55 ,
struct V_332 * V_333 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
F_230 ( V_333 -> V_334 , V_335 , sizeof( V_333 -> V_334 ) ) ;
F_230 ( V_333 -> V_336 , V_337 ,
sizeof( V_333 -> V_336 ) ) ;
snprintf ( V_333 -> V_338 , sizeof( V_333 -> V_338 ) ,
L_17 ,
V_7 -> V_44 -> V_53 . V_49 ,
V_7 -> V_44 -> V_53 . V_50 ,
V_7 -> V_44 -> V_53 . V_51 ) ;
F_230 ( V_333 -> V_44 , V_7 -> V_44 -> V_339 ,
sizeof( V_333 -> V_44 ) ) ;
}
static void F_231 ( struct V_197 * V_55 ,
struct V_340 * V_217 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
V_217 -> V_341 = V_80 -> V_342 . V_341 ;
V_217 -> V_343 = V_80 -> V_342 . V_343 ;
}
static int F_232 ( struct V_80 * V_80 ,
struct V_340 * V_217 )
{
char V_344 [ V_345 ] ;
F_233 ( V_344 , V_80 -> V_78 ) ;
F_234 ( V_344 , V_217 -> V_341 ) ;
F_235 ( V_344 , V_217 -> V_343 ) ;
return F_12 ( V_80 -> V_7 -> V_11 , F_5 ( V_346 ) ,
V_344 ) ;
}
static int F_236 ( struct V_197 * V_55 ,
struct V_340 * V_217 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
bool V_223 = V_217 -> V_343 || V_217 -> V_341 ;
int V_10 ;
if ( V_80 -> V_234 . V_216 && V_80 -> V_234 . V_216 -> V_226 ) {
F_76 ( V_55 , L_18 ) ;
return - V_164 ;
}
if ( V_217 -> V_347 ) {
F_76 ( V_55 , L_19 ) ;
return - V_164 ;
}
V_10 = F_153 ( V_80 , V_55 -> V_124 , V_223 ) ;
if ( V_10 ) {
F_76 ( V_55 , L_20 ) ;
return V_10 ;
}
V_10 = F_232 ( V_80 , V_217 ) ;
if ( V_10 ) {
F_76 ( V_55 , L_21 ) ;
goto V_348;
}
V_80 -> V_342 . V_341 = V_217 -> V_341 ;
V_80 -> V_342 . V_343 = V_217 -> V_343 ;
return 0 ;
V_348:
V_223 = F_155 ( V_80 ) ;
F_153 ( V_80 , V_55 -> V_124 , V_223 ) ;
return V_10 ;
}
static void F_237 ( T_3 * * V_122 , int V_247 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_349 ; V_102 ++ ) {
snprintf ( * V_122 , V_350 , L_22 ,
V_351 [ V_102 ] . V_352 , V_247 ) ;
* V_122 += V_350 ;
}
}
static void F_238 ( T_3 * * V_122 , int V_320 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_353 ; V_102 ++ ) {
snprintf ( * V_122 , V_350 , L_22 ,
V_354 [ V_102 ] . V_352 , V_320 ) ;
* V_122 += V_350 ;
}
}
static void F_239 ( struct V_197 * V_55 ,
T_2 V_355 , T_3 * V_24 )
{
T_3 * V_122 = V_24 ;
int V_102 ;
switch ( V_355 ) {
case V_356 :
for ( V_102 = 0 ; V_102 < V_357 ; V_102 ++ ) {
memcpy ( V_122 , V_358 [ V_102 ] . V_352 ,
V_350 ) ;
V_122 += V_350 ;
}
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ )
F_237 ( & V_122 , V_102 ) ;
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ )
F_238 ( & V_122 , V_102 ) ;
break;
}
}
static int F_240 ( struct V_197 * V_55 ,
enum V_359 V_82 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
char V_360 [ V_361 ] ;
bool V_362 ;
switch ( V_82 ) {
case V_363 :
V_362 = true ;
break;
case V_364 :
V_362 = false ;
break;
default:
return - V_296 ;
}
F_241 ( V_360 , V_80 -> V_78 , V_362 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_365 ) , V_360 ) ;
}
static int
F_242 ( struct V_358 * * V_366 ,
int * V_367 , enum V_368 V_246 )
{
switch ( V_246 ) {
case V_251 :
* V_366 = V_358 ;
* V_367 = V_357 ;
break;
case V_369 :
* V_366 = V_351 ;
* V_367 = V_349 ;
break;
case V_370 :
* V_366 = V_354 ;
* V_367 = V_353 ;
break;
default:
F_69 ( 1 ) ;
return - V_296 ;
}
return 0 ;
}
static void F_243 ( struct V_197 * V_55 ,
enum V_368 V_246 , int V_247 ,
T_4 * V_24 , int V_371 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
struct V_358 * V_260 ;
char V_248 [ V_250 ] ;
int V_102 , V_201 ;
int V_10 ;
V_10 = F_242 ( & V_260 , & V_201 , V_246 ) ;
if ( V_10 )
return;
F_163 ( V_55 , V_246 , V_247 , V_248 ) ;
for ( V_102 = 0 ; V_102 < V_201 ; V_102 ++ ) {
V_24 [ V_371 + V_102 ] = V_260 [ V_102 ] . F_244 ( V_248 ) ;
if ( ! V_260 [ V_102 ] . V_372 )
continue;
V_24 [ V_371 + V_102 ] = F_245 ( V_7 ,
V_24 [ V_371 + V_102 ] ) ;
}
}
static void F_246 ( struct V_197 * V_55 ,
struct V_373 * V_239 , T_4 * V_24 )
{
int V_102 , V_371 = 0 ;
F_243 ( V_55 , V_251 , 0 ,
V_24 , V_371 ) ;
V_371 = V_357 ;
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ ) {
F_243 ( V_55 , V_369 , V_102 ,
V_24 , V_371 ) ;
V_371 += V_349 ;
}
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ ) {
F_243 ( V_55 , V_370 , V_102 ,
V_24 , V_371 ) ;
V_371 += V_353 ;
}
}
static int F_247 ( struct V_197 * V_55 , int V_374 )
{
switch ( V_374 ) {
case V_356 :
return V_375 ;
default:
return - V_296 ;
}
}
static void
F_248 ( T_2 V_376 ,
struct V_377 * V_378 )
{
if ( V_376 & ( V_379 |
V_380 |
V_381 |
V_382 |
V_383 |
V_384 ) )
F_249 ( V_378 , V_385 , V_386 ) ;
if ( V_376 & ( V_387 |
V_388 |
V_389 |
V_390 |
V_391 ) )
F_249 ( V_378 , V_385 , V_392 ) ;
}
static void F_250 ( T_2 V_376 , unsigned long * V_393 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_394 ; V_102 ++ ) {
if ( V_376 & V_395 [ V_102 ] . V_396 )
F_251 ( V_395 [ V_102 ] . V_397 ,
V_393 ) ;
}
}
static void F_252 ( bool V_398 , T_2 V_376 ,
struct V_377 * V_378 )
{
T_2 V_399 = V_400 ;
T_3 V_401 = V_402 ;
int V_102 ;
if ( ! V_398 )
goto V_252;
for ( V_102 = 0 ; V_102 < V_394 ; V_102 ++ ) {
if ( V_376 & V_395 [ V_102 ] . V_396 ) {
V_399 = V_395 [ V_102 ] . V_399 ;
V_401 = V_403 ;
break;
}
}
V_252:
V_378 -> V_404 . V_399 = V_399 ;
V_378 -> V_404 . V_401 = V_401 ;
}
static T_3 F_253 ( T_2 V_376 )
{
if ( V_376 & ( V_380 |
V_382 |
V_383 |
V_384 ) )
return V_405 ;
if ( V_376 & ( V_379 |
V_381 |
V_406 ) )
return V_407 ;
if ( V_376 & ( V_387 |
V_388 |
V_389 |
V_390 ) )
return V_408 ;
return V_409 ;
}
static T_2
F_254 ( const struct V_377 * V_378 )
{
T_2 V_410 = 0 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_394 ; V_102 ++ ) {
if ( F_255 ( V_395 [ V_102 ] . V_397 ,
V_378 -> V_411 . V_412 ) )
V_410 |= V_395 [ V_102 ] . V_396 ;
}
return V_410 ;
}
static T_2 F_256 ( T_2 V_399 )
{
T_2 V_410 = 0 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_394 ; V_102 ++ ) {
if ( V_399 == V_395 [ V_102 ] . V_399 )
V_410 |= V_395 [ V_102 ] . V_396 ;
}
return V_410 ;
}
static T_2 F_257 ( T_2 V_413 )
{
T_2 V_410 = 0 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_394 ; V_102 ++ ) {
if ( V_395 [ V_102 ] . V_399 <= V_413 )
V_410 |= V_395 [ V_102 ] . V_396 ;
}
return V_410 ;
}
static void F_258 ( T_2 V_414 ,
struct V_377 * V_378 )
{
F_249 ( V_378 , V_385 , V_415 ) ;
F_249 ( V_378 , V_385 , V_416 ) ;
F_249 ( V_378 , V_385 , V_417 ) ;
F_248 ( V_414 , V_378 ) ;
F_250 ( V_414 , V_378 -> V_411 . V_385 ) ;
}
static void F_259 ( T_2 V_418 , bool V_347 ,
struct V_377 * V_378 )
{
if ( ! V_347 )
return;
F_249 ( V_378 , V_412 , V_416 ) ;
F_250 ( V_418 , V_378 -> V_411 . V_412 ) ;
}
static void
F_260 ( T_2 V_419 , T_3 V_420 ,
struct V_377 * V_378 )
{
if ( V_420 != V_421 || ! V_419 )
return;
F_249 ( V_378 , V_422 , V_416 ) ;
F_250 ( V_419 , V_378 -> V_411 . V_422 ) ;
}
static int F_261 ( struct V_197 * V_55 ,
struct V_377 * V_378 )
{
T_2 V_414 , V_418 , V_423 , V_419 ;
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
char V_424 [ V_425 ] ;
T_3 V_420 ;
bool V_347 ;
int V_10 ;
V_347 = V_80 -> V_342 . V_347 ;
F_262 ( V_424 , V_80 -> V_78 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_426 ) , V_424 ) ;
if ( V_10 )
return V_10 ;
F_263 ( V_424 , & V_414 , & V_418 ,
& V_423 ) ;
F_258 ( V_414 , V_378 ) ;
F_259 ( V_418 , V_347 , V_378 ) ;
V_419 = F_264 ( V_424 ) ;
V_420 = F_265 ( V_424 ) ;
F_260 ( V_419 , V_420 , V_378 ) ;
V_378 -> V_404 . V_347 = V_347 ? V_427 : V_428 ;
V_378 -> V_404 . V_111 = F_253 ( V_423 ) ;
F_252 ( F_177 ( V_55 ) , V_423 ,
V_378 ) ;
return 0 ;
}
static int
F_266 ( struct V_197 * V_55 ,
const struct V_377 * V_378 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
char V_424 [ V_425 ] ;
T_2 V_414 , V_429 ;
bool V_347 ;
int V_10 ;
F_262 ( V_424 , V_80 -> V_78 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_426 ) , V_424 ) ;
if ( V_10 )
return V_10 ;
F_263 ( V_424 , & V_414 , NULL , NULL ) ;
V_347 = V_378 -> V_404 . V_347 == V_427 ;
V_429 = V_347 ?
F_254 ( V_378 ) :
F_256 ( V_378 -> V_404 . V_399 ) ;
V_429 = V_429 & V_414 ;
if ( ! V_429 ) {
F_76 ( V_55 , L_23 ) ;
return - V_164 ;
}
F_262 ( V_424 , V_80 -> V_78 ,
V_429 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_426 ) , V_424 ) ;
if ( V_10 )
return V_10 ;
if ( ! F_267 ( V_55 ) )
return 0 ;
V_80 -> V_342 . V_347 = V_347 ;
F_89 ( V_80 , false ) ;
F_89 ( V_80 , true ) ;
return 0 ;
}
static int F_268 ( struct V_197 * V_55 ,
struct V_430 * V_431 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
const struct V_40 * V_40 ;
int V_10 ;
if ( V_431 -> V_432 != V_433 )
return - V_296 ;
F_269 ( V_55 ) ;
F_270 () ;
V_10 = F_26 ( & V_40 , V_431 -> V_24 , & V_55 -> V_55 ) ;
if ( V_10 )
goto V_252;
V_10 = F_21 ( V_7 , V_40 ) ;
F_28 ( V_40 ) ;
V_252:
F_271 () ;
F_272 ( V_55 ) ;
return V_10 ;
}
static int F_273 ( struct V_80 * V_80 ,
T_1 V_26 , T_1 V_25 , void * V_24 ,
unsigned int * V_434 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_435 [ V_436 ] ;
char V_437 [ V_438 ] ;
int V_439 ;
int V_10 ;
V_25 = F_8 ( T_1 , V_25 , V_436 ) ;
F_274 ( V_437 , V_80 -> V_282 . V_194 ,
0 , 0 , V_26 , V_25 , V_440 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_441 ) , V_437 ) ;
if ( V_10 )
return V_10 ;
V_439 = F_275 ( V_437 ) ;
if ( V_439 )
return - V_104 ;
F_276 ( V_437 , V_435 ) ;
memcpy ( V_24 , V_435 , V_25 ) ;
* V_434 = V_25 ;
return 0 ;
}
static int F_277 ( struct V_197 * V_442 ,
struct V_443 * V_444 )
{
struct V_80 * V_80 = F_123 ( V_442 ) ;
T_3 V_445 [ V_446 ] ;
T_3 V_447 , V_448 ;
unsigned int V_449 ;
int V_10 ;
V_10 = F_273 ( V_80 , 0 ,
V_446 ,
V_445 , & V_449 ) ;
if ( V_10 )
return V_10 ;
if ( V_449 < V_446 )
return - V_104 ;
V_447 = V_445 [ V_450 ] ;
V_448 = V_445 [ V_451 ] ;
switch ( V_448 ) {
case V_452 :
V_444 -> type = V_453 ;
V_444 -> V_454 = V_455 ;
break;
case V_456 :
case V_457 :
if ( V_448 == V_457 ||
V_447 >= V_458 ) {
V_444 -> type = V_459 ;
V_444 -> V_454 = V_460 ;
} else {
V_444 -> type = V_453 ;
V_444 -> V_454 = V_455 ;
}
break;
case V_461 :
V_444 -> type = V_462 ;
V_444 -> V_454 = V_463 ;
break;
default:
return - V_164 ;
}
return 0 ;
}
static int F_278 ( struct V_197 * V_442 ,
struct V_464 * V_465 ,
T_3 * V_24 )
{
struct V_80 * V_80 = F_123 ( V_442 ) ;
int V_26 = V_465 -> V_26 ;
unsigned int V_449 ;
int V_102 = 0 ;
int V_10 ;
if ( ! V_465 -> V_201 )
return - V_164 ;
memset ( V_24 , 0 , V_465 -> V_201 ) ;
while ( V_102 < V_465 -> V_201 ) {
V_10 = F_273 ( V_80 , V_26 ,
V_465 -> V_201 - V_102 , V_24 + V_102 ,
& V_449 ) ;
if ( V_10 ) {
F_76 ( V_80 -> V_55 , L_24 ) ;
return V_10 ;
}
V_102 += V_449 ;
V_26 += V_449 ;
}
return 0 ;
}
static int
F_279 ( struct V_80 * V_80 , T_3 V_195 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
T_2 V_413 = V_466 * V_195 ;
char V_424 [ V_425 ] ;
T_2 V_418 ;
V_418 = F_257 ( V_413 ) ;
F_262 ( V_424 , V_80 -> V_78 ,
V_418 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_426 ) , V_424 ) ;
}
int F_280 ( struct V_80 * V_80 ,
enum V_467 V_468 , T_3 V_115 , T_3 V_469 ,
bool V_470 , T_3 V_471 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_472 [ V_473 ] ;
F_281 ( V_472 , V_80 -> V_78 , V_468 , V_115 ,
V_469 ) ;
F_282 ( V_472 , true ) ;
F_283 ( V_472 , V_470 ) ;
F_284 ( V_472 , V_471 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_474 ) , V_472 ) ;
}
int F_285 ( struct V_80 * V_80 ,
enum V_467 V_468 , T_3 V_115 ,
T_3 V_469 , T_2 V_475 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_472 [ V_473 ] ;
F_281 ( V_472 , V_80 -> V_78 , V_468 , V_115 ,
V_469 ) ;
F_286 ( V_472 , true ) ;
F_287 ( V_472 , V_475 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_474 ) , V_472 ) ;
}
int F_288 ( struct V_80 * V_80 ,
T_3 V_476 , T_3 V_477 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_478 [ V_479 ] ;
F_289 ( V_478 , V_80 -> V_78 , V_476 ,
V_477 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_480 ) , V_478 ) ;
}
static int F_290 ( struct V_80 * V_80 )
{
int V_10 , V_102 ;
V_10 = F_280 ( V_80 ,
V_481 , 0 , 0 , false ,
0 ) ;
if ( V_10 )
return V_10 ;
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ ) {
V_10 = F_280 ( V_80 ,
V_482 , V_102 ,
0 , false , 0 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ ) {
V_10 = F_280 ( V_80 ,
V_483 , V_102 , V_102 ,
false , 0 ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_285 ( V_80 ,
V_484 , 0 , 0 ,
V_485 ) ;
if ( V_10 )
return V_10 ;
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ ) {
V_10 = F_285 ( V_80 ,
V_482 ,
V_102 , 0 ,
V_485 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ ) {
V_10 = F_285 ( V_80 ,
V_483 ,
V_102 , V_102 ,
V_485 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_102 = 0 ; V_102 < V_230 ; V_102 ++ ) {
V_10 = F_288 ( V_80 , V_102 , 0 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_291 ( struct V_7 * V_7 , T_3 V_78 ,
bool V_283 , T_3 V_194 , T_3 V_195 , T_3 V_196 )
{
struct V_273 * V_273 ;
struct V_80 * V_80 ;
struct V_197 * V_55 ;
int V_10 ;
V_10 = F_292 ( V_7 -> V_11 , V_78 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_25 ,
V_78 ) ;
return V_10 ;
}
V_55 = F_293 ( sizeof( struct V_80 ) ) ;
if ( ! V_55 ) {
V_10 = - V_96 ;
goto V_486;
}
F_294 ( V_55 , V_7 -> V_44 -> V_55 ) ;
V_80 = F_123 ( V_55 ) ;
V_80 -> V_55 = V_55 ;
V_80 -> V_7 = V_7 ;
V_80 -> V_78 = V_78 ;
V_80 -> V_184 = 1 ;
V_80 -> V_283 = V_283 ;
V_80 -> V_282 . V_194 = V_194 ;
V_80 -> V_282 . V_195 = V_195 ;
V_80 -> V_282 . V_196 = V_196 ;
V_80 -> V_342 . V_347 = 1 ;
F_59 ( & V_80 -> V_276 ) ;
F_59 ( & V_80 -> V_316 ) ;
V_80 -> V_199 =
F_295 ( struct V_198 ) ;
if ( ! V_80 -> V_199 ) {
V_10 = - V_96 ;
goto V_487;
}
V_80 -> V_302 = F_80 ( sizeof( * V_80 -> V_302 ) ,
V_95 ) ;
if ( ! V_80 -> V_302 ) {
V_10 = - V_96 ;
goto V_488;
}
V_80 -> V_260 . V_262 =
F_80 ( sizeof( * V_80 -> V_260 . V_262 ) , V_95 ) ;
if ( ! V_80 -> V_260 . V_262 ) {
V_10 = - V_96 ;
goto V_489;
}
F_296 ( & V_80 -> V_260 . V_261 ,
& F_176 ) ;
V_55 -> V_490 = & V_491 ;
V_55 -> V_492 = & V_493 ;
V_10 = F_117 ( V_80 , V_194 , V_195 , V_196 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_26 ,
V_80 -> V_78 ) ;
goto V_494;
}
V_10 = F_99 ( V_80 , 0 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_27 ,
V_80 -> V_78 ) ;
goto V_495;
}
V_10 = F_94 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_28 ,
V_80 -> V_78 ) ;
goto V_496;
}
F_297 ( V_55 ) ;
V_55 -> V_497 |= V_498 | V_499 | V_500 |
V_501 | V_502 ;
V_55 -> V_503 |= V_502 ;
V_55 -> V_504 = 0 ;
V_55 -> V_161 = V_505 ;
V_55 -> V_506 = V_74 ;
V_10 = F_110 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_29 ,
V_80 -> V_78 ) ;
goto V_507;
}
V_10 = F_279 ( V_80 , V_195 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_30 ,
V_80 -> V_78 ) ;
goto V_508;
}
V_10 = F_96 ( V_80 , V_509 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_31 ,
V_80 -> V_78 ) ;
goto V_237;
}
V_10 = F_89 ( V_80 , false ) ;
if ( V_10 )
goto V_510;
V_10 = F_298 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_32 ,
V_80 -> V_78 ) ;
goto V_511;
}
V_10 = F_290 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_33 ,
V_80 -> V_78 ) ;
goto V_512;
}
V_10 = F_299 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_34 ,
V_80 -> V_78 ) ;
goto V_513;
}
V_10 = F_300 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_35 ,
V_80 -> V_78 ) ;
goto V_514;
}
V_273 = F_191 ( V_80 , 1 ) ;
if ( F_301 ( V_273 ) ) {
F_27 ( V_7 -> V_44 -> V_55 , L_36 ,
V_80 -> V_78 ) ;
goto V_515;
}
F_302 ( V_80 ) ;
V_7 -> V_299 [ V_78 ] = V_80 ;
V_10 = F_303 ( V_55 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_37 ,
V_80 -> V_78 ) ;
goto V_516;
}
F_304 ( V_7 -> V_11 , V_80 -> V_78 ,
V_80 , V_55 , V_80 -> V_283 ,
V_194 ) ;
F_178 ( & V_80 -> V_260 . V_261 , 0 ) ;
return 0 ;
V_516:
V_7 -> V_299 [ V_78 ] = NULL ;
F_305 ( V_80 ) ;
F_186 ( V_273 ) ;
V_515:
F_306 ( V_80 ) ;
V_514:
F_307 ( V_80 ) ;
V_513:
V_512:
V_511:
V_510:
V_237:
V_508:
V_507:
V_496:
F_99 ( V_80 , V_517 ) ;
V_495:
F_121 ( V_80 ) ;
V_494:
F_52 ( V_80 -> V_260 . V_262 ) ;
V_489:
F_52 ( V_80 -> V_302 ) ;
V_488:
F_308 ( V_80 -> V_199 ) ;
V_487:
F_309 ( V_55 ) ;
V_486:
F_310 ( V_7 -> V_11 , V_78 ) ;
return V_10 ;
}
static void F_311 ( struct V_7 * V_7 , T_3 V_78 )
{
struct V_80 * V_80 = V_7 -> V_299 [ V_78 ] ;
F_312 ( & V_80 -> V_260 . V_261 ) ;
F_313 ( V_7 -> V_11 , V_78 , V_7 ) ;
F_314 ( V_80 -> V_55 ) ;
V_7 -> V_299 [ V_78 ] = NULL ;
F_305 ( V_80 ) ;
F_184 ( V_80 ) ;
F_306 ( V_80 ) ;
F_307 ( V_80 ) ;
F_99 ( V_80 , V_517 ) ;
F_121 ( V_80 ) ;
F_52 ( V_80 -> V_260 . V_262 ) ;
F_52 ( V_80 -> V_302 ) ;
F_308 ( V_80 -> V_199 ) ;
F_61 ( ! F_62 ( & V_80 -> V_276 ) ) ;
F_309 ( V_80 -> V_55 ) ;
F_310 ( V_7 -> V_11 , V_78 ) ;
}
static bool F_315 ( struct V_7 * V_7 , T_3 V_78 )
{
return V_7 -> V_299 [ V_78 ] != NULL ;
}
static void F_316 ( struct V_7 * V_7 )
{
int V_102 ;
for ( V_102 = 1 ; V_102 < F_317 ( V_7 -> V_11 ) ; V_102 ++ )
if ( F_315 ( V_7 , V_102 ) )
F_311 ( V_7 , V_102 ) ;
F_52 ( V_7 -> V_518 ) ;
F_52 ( V_7 -> V_299 ) ;
}
static int F_318 ( struct V_7 * V_7 )
{
unsigned int V_519 = F_317 ( V_7 -> V_11 ) ;
T_3 V_194 , V_195 , V_196 ;
T_8 V_520 ;
int V_102 ;
int V_10 ;
V_520 = sizeof( struct V_80 * ) * V_519 ;
V_7 -> V_299 = F_80 ( V_520 , V_95 ) ;
if ( ! V_7 -> V_299 )
return - V_96 ;
V_7 -> V_518 = F_58 ( V_519 , sizeof( T_3 ) , V_95 ) ;
if ( ! V_7 -> V_518 ) {
V_10 = - V_96 ;
goto V_521;
}
for ( V_102 = 1 ; V_102 < V_519 ; V_102 ++ ) {
V_10 = F_112 ( V_7 , V_102 , & V_194 ,
& V_195 , & V_196 ) ;
if ( V_10 )
goto V_522;
if ( ! V_195 )
continue;
V_7 -> V_518 [ V_102 ] = V_194 ;
V_10 = F_291 ( V_7 , V_102 , false ,
V_194 , V_195 , V_196 ) ;
if ( V_10 )
goto V_523;
}
return 0 ;
V_523:
V_522:
for ( V_102 -- ; V_102 >= 1 ; V_102 -- )
if ( F_315 ( V_7 , V_102 ) )
F_311 ( V_7 , V_102 ) ;
F_52 ( V_7 -> V_518 ) ;
V_521:
F_52 ( V_7 -> V_299 ) ;
return V_10 ;
}
static T_3 F_319 ( T_3 V_78 )
{
T_3 V_26 = ( V_78 - 1 ) % V_524 ;
return V_78 - V_26 ;
}
static int F_320 ( struct V_7 * V_7 , T_3 V_525 ,
T_3 V_194 , unsigned int V_526 )
{
T_3 V_195 = V_527 / V_526 ;
int V_10 , V_102 ;
for ( V_102 = 0 ; V_102 < V_526 ; V_102 ++ ) {
V_10 = F_291 ( V_7 , V_525 + V_102 , true ,
V_194 , V_195 , V_102 * V_195 ) ;
if ( V_10 )
goto V_523;
}
return 0 ;
V_523:
for ( V_102 -- ; V_102 >= 0 ; V_102 -- )
if ( F_315 ( V_7 , V_525 + V_102 ) )
F_311 ( V_7 , V_525 + V_102 ) ;
return V_10 ;
}
static void F_321 ( struct V_7 * V_7 ,
T_3 V_525 , unsigned int V_526 )
{
T_3 V_78 , V_194 , V_195 = V_527 ;
int V_102 ;
V_526 = V_526 / 2 ;
for ( V_102 = 0 ; V_102 < V_526 ; V_102 ++ ) {
V_78 = V_525 + V_102 * 2 ;
V_194 = V_7 -> V_518 [ V_78 ] ;
F_291 ( V_7 , V_78 , false , V_194 ,
V_195 , 0 ) ;
}
}
static int F_322 ( struct V_528 * V_528 , T_3 V_78 ,
unsigned int V_526 )
{
struct V_7 * V_7 = F_323 ( V_528 ) ;
struct V_80 * V_80 ;
T_3 V_194 , V_529 , V_525 ;
int V_102 ;
int V_10 ;
V_80 = V_7 -> V_299 [ V_78 ] ;
if ( ! V_80 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_38 ,
V_78 ) ;
return - V_164 ;
}
V_194 = V_80 -> V_282 . V_194 ;
V_529 = V_80 -> V_282 . V_195 ;
if ( V_526 != 2 && V_526 != 4 ) {
F_76 ( V_80 -> V_55 , L_39 ) ;
return - V_164 ;
}
if ( V_529 != V_527 ) {
F_76 ( V_80 -> V_55 , L_40 ) ;
return - V_164 ;
}
if ( V_526 == 2 ) {
V_525 = V_78 ;
if ( V_7 -> V_299 [ V_525 + 1 ] ) {
F_76 ( V_80 -> V_55 , L_41 ) ;
return - V_164 ;
}
} else {
V_525 = F_319 ( V_78 ) ;
if ( V_7 -> V_299 [ V_525 + 1 ] ||
V_7 -> V_299 [ V_525 + 3 ] ) {
F_76 ( V_80 -> V_55 , L_41 ) ;
return - V_164 ;
}
}
for ( V_102 = 0 ; V_102 < V_526 ; V_102 ++ )
if ( F_315 ( V_7 , V_525 + V_102 ) )
F_311 ( V_7 , V_525 + V_102 ) ;
V_10 = F_320 ( V_7 , V_525 , V_194 , V_526 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_42 ) ;
goto V_530;
}
return 0 ;
V_530:
F_321 ( V_7 , V_525 , V_526 ) ;
return V_10 ;
}
static int F_324 ( struct V_528 * V_528 , T_3 V_78 )
{
struct V_7 * V_7 = F_323 ( V_528 ) ;
struct V_80 * V_80 ;
T_3 V_529 , V_525 ;
unsigned int V_526 ;
int V_102 ;
V_80 = V_7 -> V_299 [ V_78 ] ;
if ( ! V_80 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_38 ,
V_78 ) ;
return - V_164 ;
}
if ( ! V_80 -> V_283 ) {
F_76 ( V_80 -> V_55 , L_43 ) ;
return - V_164 ;
}
V_529 = V_80 -> V_282 . V_195 ;
V_526 = V_529 == 1 ? 4 : 2 ;
V_525 = F_319 ( V_78 ) ;
if ( V_526 == 2 && V_78 >= V_525 + 2 )
V_525 = V_525 + 2 ;
for ( V_102 = 0 ; V_102 < V_526 ; V_102 ++ )
if ( F_315 ( V_7 , V_525 + V_102 ) )
F_311 ( V_7 , V_525 + V_102 ) ;
F_321 ( V_7 , V_525 , V_526 ) ;
return 0 ;
}
static void F_325 ( const struct V_531 * V_532 ,
char * V_533 , void * V_534 )
{
struct V_7 * V_7 = V_534 ;
struct V_80 * V_80 ;
enum V_535 V_439 ;
T_3 V_78 ;
V_78 = F_326 ( V_533 ) ;
V_80 = V_7 -> V_299 [ V_78 ] ;
if ( ! V_80 )
return;
V_439 = F_327 ( V_533 ) ;
if ( V_439 == V_536 ) {
F_328 ( V_80 -> V_55 , L_44 ) ;
F_329 ( V_80 -> V_55 ) ;
} else {
F_328 ( V_80 -> V_55 , L_45 ) ;
F_297 ( V_80 -> V_55 ) ;
}
}
static void F_330 ( struct V_69 * V_70 ,
T_3 V_78 , void * V_534 )
{
struct V_7 * V_7 = V_534 ;
struct V_80 * V_80 = V_7 -> V_299 [ V_78 ] ;
struct V_198 * V_199 ;
if ( F_129 ( ! V_80 ) ) {
F_331 ( V_7 -> V_44 -> V_55 , L_46 ,
V_78 ) ;
return;
}
V_70 -> V_55 = V_80 -> V_55 ;
V_199 = F_137 ( V_80 -> V_199 ) ;
F_138 ( & V_199 -> V_206 ) ;
V_199 -> V_240 ++ ;
V_199 -> V_241 += V_70 -> V_201 ;
F_139 ( & V_199 -> V_206 ) ;
V_70 -> V_309 = F_332 ( V_70 , V_70 -> V_55 ) ;
F_333 ( V_70 ) ;
}
static void F_334 ( struct V_69 * V_70 , T_3 V_78 ,
void * V_534 )
{
V_70 -> V_537 = 1 ;
return F_330 ( V_70 , V_78 , V_534 ) ;
}
static void F_335 ( struct V_69 * V_70 , T_3 V_78 ,
void * V_534 )
{
struct V_7 * V_7 = V_534 ;
struct V_80 * V_80 = V_7 -> V_299 [ V_78 ] ;
struct V_303 * V_303 ;
T_2 V_25 ;
if ( F_129 ( ! V_80 ) ) {
F_331 ( V_7 -> V_44 -> V_55 , L_47 ,
V_78 ) ;
goto V_252;
}
if ( F_129 ( ! V_80 -> V_302 ) ) {
F_331 ( V_7 -> V_44 -> V_55 , L_48 ,
V_78 ) ;
goto V_252;
}
V_25 = V_80 -> V_302 -> V_306 ?
V_80 -> V_302 -> V_307 : V_70 -> V_201 ;
F_336 () ;
V_303 = F_337 ( V_80 -> V_302 -> V_303 ) ;
if ( ! V_303 )
goto V_538;
F_338 ( V_303 , V_70 , V_25 ,
V_80 -> V_55 -> V_295 , 0 ,
V_80 -> V_302 -> V_143 ) ;
V_538:
F_339 () ;
V_252:
F_340 ( V_70 ) ;
}
static int F_341 ( struct V_528 * V_528 )
{
char V_539 [ V_540 ] ;
enum V_541 V_542 ;
int V_543 ;
bool V_544 ;
T_3 V_545 ;
T_2 V_143 ;
int V_102 , V_10 ;
if ( ! F_56 ( V_528 , V_546 ) )
return - V_104 ;
V_543 = F_57 ( V_528 , V_546 ) ;
V_542 = V_547 ;
for ( V_102 = 0 ; V_102 < V_543 ; V_102 ++ ) {
V_544 = false ;
switch ( V_102 ) {
case V_548 :
case V_549 :
case V_550 :
case V_551 :
V_143 = 128 ;
V_545 = 7 ;
break;
case V_552 :
V_143 = 16 * 1024 ;
V_545 = 10 ;
break;
case V_553 :
case V_554 :
case V_555 :
case V_556 :
case V_557 :
case V_558 :
V_143 = 1024 ;
V_545 = 7 ;
break;
case V_559 :
V_544 = true ;
V_143 = 4 * 1024 ;
V_545 = 4 ;
break;
default:
continue;
}
F_342 ( V_539 , V_102 , V_542 , V_544 , V_143 ,
V_545 ) ;
V_10 = F_12 ( V_528 , F_5 ( V_560 ) , V_539 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_343 ( struct V_528 * V_528 )
{
char V_561 [ V_562 ] ;
enum V_563 V_102 ;
int V_543 ;
int V_564 ;
T_3 V_565 , V_320 ;
T_1 V_566 ;
int V_10 ;
if ( ! F_56 ( V_528 , V_567 ) )
return - V_104 ;
V_564 = F_57 ( V_528 , V_567 ) ;
V_543 = F_57 ( V_528 , V_546 ) ;
for ( V_102 = 0 ; V_102 < V_564 ; V_102 ++ ) {
V_566 = V_102 ;
switch ( V_102 ) {
case V_548 :
case V_549 :
case V_550 :
case V_551 :
V_565 = 5 ;
V_320 = 5 ;
break;
case V_553 :
case V_555 :
V_565 = 4 ;
V_320 = 4 ;
break;
case V_552 :
case V_559 :
V_565 = 3 ;
V_320 = 3 ;
break;
case V_554 :
V_565 = 2 ;
V_320 = 2 ;
break;
case V_556 :
case V_557 :
case V_558 :
V_565 = 1 ;
V_320 = 1 ;
break;
case V_568 :
V_565 = V_569 ;
V_320 = V_570 ;
V_566 = V_571 ;
break;
default:
continue;
}
if ( V_543 <= V_566 &&
V_566 != V_571 )
return - V_104 ;
F_344 ( V_561 , V_102 , V_566 , V_565 , V_320 ) ;
V_10 = F_12 ( V_528 , F_5 ( V_572 ) , V_561 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_345 ( struct V_7 * V_7 )
{
int V_102 ;
int V_10 ;
V_10 = F_341 ( V_7 -> V_11 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_343 ( V_7 -> V_11 ) ;
if ( V_10 )
return V_10 ;
for ( V_102 = 0 ; V_102 < F_346 ( V_573 ) ; V_102 ++ ) {
V_10 = F_347 ( V_7 -> V_11 ,
& V_573 [ V_102 ] ,
V_7 ) ;
if ( V_10 )
goto V_574;
}
return 0 ;
V_574:
for ( V_102 -- ; V_102 >= 0 ; V_102 -- ) {
F_348 ( V_7 -> V_11 ,
& V_573 [ V_102 ] ,
V_7 ) ;
}
return V_10 ;
}
static void F_349 ( struct V_7 * V_7 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < F_346 ( V_573 ) ; V_102 ++ ) {
F_348 ( V_7 -> V_11 ,
& V_573 [ V_102 ] ,
V_7 ) ;
}
}
static int F_350 ( struct V_7 * V_7 )
{
char V_575 [ V_576 ] ;
int V_10 ;
F_351 ( V_575 , V_577 |
V_578 |
V_579 |
V_580 |
V_581 |
V_582 |
V_583 |
V_584 |
V_585 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_586 ) , V_575 ) ;
if ( V_10 )
return V_10 ;
if ( ! F_56 ( V_7 -> V_11 , V_587 ) ||
! F_56 ( V_7 -> V_11 , V_588 ) )
return - V_104 ;
V_7 -> V_589 = F_58 ( F_57 ( V_7 -> V_11 , V_587 ) ,
sizeof( struct V_590 ) ,
V_95 ) ;
if ( ! V_7 -> V_589 )
return - V_96 ;
return 0 ;
}
static void F_352 ( struct V_7 * V_7 )
{
F_52 ( V_7 -> V_589 ) ;
}
static int F_353 ( struct V_528 * V_528 )
{
char V_561 [ V_562 ] ;
F_344 ( V_561 , V_591 ,
V_571 ,
V_569 ,
V_570 ) ;
return F_12 ( V_528 , F_5 ( V_572 ) , V_561 ) ;
}
static int F_354 ( struct V_528 * V_528 ,
const struct V_592 * V_592 )
{
struct V_7 * V_7 = F_323 ( V_528 ) ;
int V_10 ;
V_7 -> V_11 = V_528 ;
V_7 -> V_44 = V_592 ;
V_10 = F_24 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_49 ) ;
return V_10 ;
}
V_10 = F_53 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_50 ) ;
return V_10 ;
}
V_10 = F_355 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_51 ) ;
return V_10 ;
}
V_10 = F_345 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_52 ) ;
goto V_593;
}
V_10 = F_356 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_53 ) ;
goto V_594;
}
V_10 = F_350 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_54 ) ;
goto V_595;
}
V_10 = F_357 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_55 ) ;
goto V_596;
}
V_10 = F_358 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_56 ) ;
goto V_597;
}
V_10 = F_55 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_57 ) ;
goto V_598;
}
V_10 = F_359 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_58 ) ;
goto V_599;
}
V_10 = F_360 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_59 ) ;
goto V_600;
}
V_10 = F_361 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_60 ) ;
goto V_601;
}
V_10 = F_318 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_61 ) ;
goto V_602;
}
return 0 ;
V_602:
F_362 ( V_7 ) ;
V_601:
F_363 ( V_7 ) ;
V_600:
F_364 ( V_7 ) ;
V_599:
F_60 ( V_7 ) ;
V_598:
F_365 ( V_7 ) ;
V_597:
F_366 ( V_7 ) ;
V_596:
F_352 ( V_7 ) ;
V_595:
F_367 ( V_7 ) ;
V_594:
F_349 ( V_7 ) ;
V_593:
F_368 ( V_7 ) ;
return V_10 ;
}
static void F_369 ( struct V_528 * V_528 )
{
struct V_7 * V_7 = F_323 ( V_528 ) ;
F_316 ( V_7 ) ;
F_362 ( V_7 ) ;
F_363 ( V_7 ) ;
F_364 ( V_7 ) ;
F_60 ( V_7 ) ;
F_365 ( V_7 ) ;
F_366 ( V_7 ) ;
F_352 ( V_7 ) ;
F_367 ( V_7 ) ;
F_349 ( V_7 ) ;
F_368 ( V_7 ) ;
}
bool F_204 ( const struct V_197 * V_55 )
{
return V_55 -> V_490 == & V_491 ;
}
static int F_370 ( struct V_197 * V_603 , void * V_24 )
{
struct V_80 * * V_604 = V_24 ;
int V_605 = 0 ;
if ( F_204 ( V_603 ) ) {
* V_604 = F_123 ( V_603 ) ;
V_605 = 1 ;
}
return V_605 ;
}
struct V_80 * F_371 ( struct V_197 * V_55 )
{
struct V_80 * V_80 ;
if ( F_204 ( V_55 ) )
return F_123 ( V_55 ) ;
V_80 = NULL ;
F_372 ( V_55 , F_370 , & V_80 ) ;
return V_80 ;
}
struct V_7 * F_373 ( struct V_197 * V_55 )
{
struct V_80 * V_80 ;
V_80 = F_371 ( V_55 ) ;
return V_80 ? V_80 -> V_7 : NULL ;
}
struct V_80 * F_374 ( struct V_197 * V_55 )
{
struct V_80 * V_80 ;
if ( F_204 ( V_55 ) )
return F_123 ( V_55 ) ;
V_80 = NULL ;
F_375 ( V_55 , F_370 ,
& V_80 ) ;
return V_80 ;
}
struct V_80 * F_376 ( struct V_197 * V_55 )
{
struct V_80 * V_80 ;
F_336 () ;
V_80 = F_374 ( V_55 ) ;
if ( V_80 )
F_269 ( V_80 -> V_55 ) ;
F_339 () ;
return V_80 ;
}
void F_377 ( struct V_80 * V_80 )
{
F_272 ( V_80 -> V_55 ) ;
}
static int F_378 ( struct V_7 * V_7 , T_1 V_606 )
{
char V_607 [ V_608 ] ;
F_379 ( V_607 , V_606 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_609 ) , V_607 ) ;
}
static int F_380 ( struct V_7 * V_7 , T_1 V_606 )
{
char V_607 [ V_608 ] ;
F_381 ( V_607 , V_606 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_609 ) , V_607 ) ;
}
static int F_382 ( struct V_80 * V_80 ,
T_1 V_606 , T_3 V_610 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_611 [ V_612 ] ;
F_383 ( V_611 , V_80 -> V_78 ,
V_606 , V_610 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_613 ) , V_611 ) ;
}
static int F_384 ( struct V_80 * V_80 ,
T_1 V_606 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_611 [ V_612 ] ;
F_385 ( V_611 , V_80 -> V_78 ,
V_606 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_613 ) , V_611 ) ;
}
static int F_386 ( struct V_80 * V_80 ,
T_1 V_606 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_611 [ V_612 ] ;
F_387 ( V_611 , V_80 -> V_78 ,
V_606 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_613 ) , V_611 ) ;
}
static int F_388 ( struct V_80 * V_80 ,
T_1 V_606 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_611 [ V_612 ] ;
F_389 ( V_611 , V_80 -> V_78 ,
V_606 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_613 ) , V_611 ) ;
}
static int F_390 ( struct V_7 * V_7 ,
struct V_197 * V_614 ,
T_1 * V_615 )
{
struct V_590 * V_616 ;
int V_617 = - 1 ;
T_4 V_618 ;
int V_102 ;
V_618 = F_57 ( V_7 -> V_11 , V_587 ) ;
for ( V_102 = 0 ; V_102 < V_618 ; V_102 ++ ) {
V_616 = F_391 ( V_7 , V_102 ) ;
if ( V_616 -> V_119 ) {
if ( V_616 -> V_55 == V_614 ) {
* V_615 = V_102 ;
return 0 ;
}
} else if ( V_617 < 0 ) {
V_617 = V_102 ;
}
}
if ( V_617 < 0 )
return - V_20 ;
* V_615 = V_617 ;
return 0 ;
}
static bool
F_392 ( struct V_7 * V_7 ,
struct V_197 * V_614 ,
struct V_619 * V_620 )
{
T_1 V_606 ;
if ( F_390 ( V_7 , V_614 , & V_606 ) != 0 )
return false ;
if ( V_620 -> V_621 != V_622 )
return false ;
return true ;
}
static int F_393 ( struct V_7 * V_7 ,
T_1 V_606 , T_3 * V_623 )
{
T_4 V_624 ;
int V_102 ;
V_624 = F_57 ( V_7 -> V_11 ,
V_588 ) ;
for ( V_102 = 0 ; V_102 < V_624 ; V_102 ++ ) {
if ( ! F_394 ( V_7 , V_606 , V_102 ) ) {
* V_623 = V_102 ;
return 0 ;
}
}
return - V_20 ;
}
static int F_395 ( struct V_80 * V_80 ,
struct V_197 * V_614 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
struct V_273 * V_273 ;
struct V_590 * V_616 ;
T_1 V_606 ;
T_3 V_610 ;
int V_10 ;
V_10 = F_390 ( V_7 , V_614 , & V_606 ) ;
if ( V_10 )
return V_10 ;
V_616 = F_391 ( V_7 , V_606 ) ;
if ( ! V_616 -> V_119 ) {
V_10 = F_378 ( V_7 , V_606 ) ;
if ( V_10 )
return V_10 ;
V_616 -> V_55 = V_614 ;
}
V_10 = F_393 ( V_7 , V_606 , & V_610 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_382 ( V_80 , V_606 , V_610 ) ;
if ( V_10 )
goto V_625;
V_10 = F_386 ( V_80 , V_606 ) ;
if ( V_10 )
goto V_626;
F_396 ( V_7 -> V_11 , V_606 , V_610 ,
V_80 -> V_78 ) ;
V_80 -> V_606 = V_606 ;
V_80 -> V_627 = 1 ;
V_616 -> V_119 ++ ;
V_273 = F_192 ( V_80 , 1 ) ;
if ( V_273 -> V_278 )
F_194 ( V_273 ) ;
return 0 ;
V_626:
F_384 ( V_80 , V_606 ) ;
V_625:
if ( ! V_616 -> V_119 )
F_380 ( V_7 , V_606 ) ;
return V_10 ;
}
static void F_397 ( struct V_80 * V_80 ,
struct V_197 * V_614 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
T_1 V_606 = V_80 -> V_606 ;
struct V_590 * V_616 ;
if ( ! V_80 -> V_627 )
return;
V_616 = F_391 ( V_7 , V_606 ) ;
F_69 ( V_616 -> V_119 == 0 ) ;
F_388 ( V_80 , V_606 ) ;
F_384 ( V_80 , V_606 ) ;
F_184 ( V_80 ) ;
if ( V_616 -> V_119 == 1 )
F_380 ( V_7 , V_606 ) ;
F_398 ( V_7 -> V_11 , V_606 ,
V_80 -> V_78 ) ;
V_80 -> V_627 = 0 ;
V_616 -> V_119 -- ;
F_191 ( V_80 , 1 ) ;
F_109 ( V_80 , 1 ) ;
}
static int F_399 ( struct V_80 * V_80 ,
T_1 V_606 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_607 [ V_608 ] ;
F_400 ( V_607 , V_606 ,
V_80 -> V_78 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_609 ) , V_607 ) ;
}
static int F_401 ( struct V_80 * V_80 ,
T_1 V_606 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_607 [ V_608 ] ;
F_402 ( V_607 , V_606 ,
V_80 -> V_78 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_609 ) , V_607 ) ;
}
static int F_403 ( struct V_80 * V_80 ,
bool V_628 )
{
if ( V_628 )
return F_399 ( V_80 ,
V_80 -> V_606 ) ;
else
return F_401 ( V_80 ,
V_80 -> V_606 ) ;
}
static int F_404 ( struct V_80 * V_80 ,
struct V_629 * V_630 )
{
return F_403 ( V_80 , V_630 -> V_631 ) ;
}
static int F_405 ( struct V_80 * V_80 ,
bool V_142 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
enum V_83 V_84 ;
char * V_85 ;
T_1 V_81 ;
int V_10 ;
V_84 = V_142 ? V_87 :
V_93 ;
V_85 = F_49 ( V_94 , V_95 ) ;
if ( ! V_85 )
return - V_96 ;
F_50 ( V_85 , V_80 -> V_78 ) ;
for ( V_81 = 0 ; V_81 < V_632 ; V_81 ++ )
F_51 ( V_85 , V_81 , V_84 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_97 ) , V_85 ) ;
F_52 ( V_85 ) ;
return V_10 ;
}
static int F_406 ( struct V_80 * V_80 )
{
int V_10 ;
V_10 = F_101 ( V_80 , true ) ;
if ( V_10 )
return V_10 ;
V_10 = F_405 ( V_80 , true ) ;
if ( V_10 )
goto V_633;
V_10 = F_182 ( V_80 , 2 , V_632 - 1 ,
true , false ) ;
if ( V_10 )
goto V_634;
return 0 ;
V_634:
F_405 ( V_80 , false ) ;
V_633:
F_101 ( V_80 , false ) ;
return V_10 ;
}
static void F_407 ( struct V_80 * V_80 )
{
F_182 ( V_80 , 2 , V_632 - 1 ,
false , false ) ;
F_405 ( V_80 , false ) ;
F_101 ( V_80 , false ) ;
}
static int F_408 ( struct V_197 * V_603 ,
struct V_197 * V_55 ,
unsigned long V_635 , void * V_636 )
{
struct V_637 * V_630 ;
struct V_80 * V_80 ;
struct V_197 * V_638 ;
struct V_7 * V_7 ;
int V_10 = 0 ;
V_80 = F_123 ( V_55 ) ;
V_7 = V_80 -> V_7 ;
V_630 = V_636 ;
switch ( V_635 ) {
case V_639 :
V_638 = V_630 -> V_638 ;
if ( ! F_409 ( V_638 ) &&
! F_410 ( V_638 ) &&
! F_411 ( V_638 ) &&
! F_412 ( V_638 ) )
return - V_164 ;
if ( ! V_630 -> V_640 )
break;
if ( F_413 ( V_638 ) )
return - V_164 ;
if ( F_410 ( V_638 ) &&
! F_392 ( V_7 , V_638 ,
V_630 -> V_641 ) )
return - V_164 ;
if ( F_410 ( V_638 ) && F_414 ( V_55 ) )
return - V_164 ;
if ( F_415 ( V_55 ) && F_409 ( V_638 ) &&
! F_410 ( F_416 ( V_638 ) ) )
return - V_164 ;
if ( F_412 ( V_638 ) && F_414 ( V_55 ) )
return - V_164 ;
if ( F_417 ( V_55 ) && F_409 ( V_638 ) )
return - V_164 ;
break;
case V_642 :
V_638 = V_630 -> V_638 ;
if ( F_411 ( V_638 ) ) {
if ( V_630 -> V_640 )
V_10 = F_418 ( V_80 ,
V_603 ,
V_638 ) ;
else
F_419 ( V_80 ,
V_603 ,
V_638 ) ;
} else if ( F_410 ( V_638 ) ) {
if ( V_630 -> V_640 )
V_10 = F_395 ( V_80 ,
V_638 ) ;
else
F_397 ( V_80 ,
V_638 ) ;
} else if ( F_412 ( V_638 ) ) {
if ( V_630 -> V_640 )
V_10 = F_406 ( V_80 ) ;
else
F_407 ( V_80 ) ;
}
break;
}
return V_10 ;
}
static int F_420 ( struct V_197 * V_55 ,
unsigned long V_635 , void * V_636 )
{
struct V_643 * V_630 ;
struct V_80 * V_80 ;
int V_10 ;
V_80 = F_123 ( V_55 ) ;
V_630 = V_636 ;
switch ( V_635 ) {
case V_644 :
if ( F_415 ( V_55 ) && V_80 -> V_627 ) {
V_10 = F_404 ( V_80 ,
V_630 -> V_645 ) ;
if ( V_10 )
F_76 ( V_55 , L_62 ) ;
}
break;
}
return 0 ;
}
static int F_421 ( struct V_197 * V_603 ,
struct V_197 * V_646 ,
unsigned long V_635 , void * V_636 )
{
switch ( V_635 ) {
case V_639 :
case V_642 :
return F_408 ( V_603 , V_646 ,
V_635 , V_636 ) ;
case V_644 :
return F_420 ( V_646 , V_635 ,
V_636 ) ;
}
return 0 ;
}
static int F_422 ( struct V_197 * V_614 ,
unsigned long V_635 , void * V_636 )
{
struct V_197 * V_55 ;
struct V_647 * V_648 ;
int V_605 ;
F_423 (lag_dev, dev, iter) {
if ( F_204 ( V_55 ) ) {
V_605 = F_421 ( V_614 , V_55 , V_635 ,
V_636 ) ;
if ( V_605 )
return V_605 ;
}
}
return 0 ;
}
static int F_424 ( struct V_197 * V_649 ,
struct V_197 * V_55 ,
unsigned long V_635 , void * V_636 ,
T_1 V_81 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_637 * V_630 = V_636 ;
struct V_197 * V_638 ;
int V_10 = 0 ;
switch ( V_635 ) {
case V_639 :
V_638 = V_630 -> V_638 ;
if ( ! F_411 ( V_638 ) )
return - V_164 ;
if ( ! V_630 -> V_640 )
break;
if ( F_413 ( V_638 ) )
return - V_164 ;
break;
case V_642 :
V_638 = V_630 -> V_638 ;
if ( F_411 ( V_638 ) ) {
if ( V_630 -> V_640 )
V_10 = F_418 ( V_80 ,
V_649 ,
V_638 ) ;
else
F_419 ( V_80 ,
V_649 ,
V_638 ) ;
} else {
V_10 = - V_164 ;
F_69 ( 1 ) ;
}
break;
}
return V_10 ;
}
static int F_425 ( struct V_197 * V_649 ,
struct V_197 * V_614 ,
unsigned long V_635 ,
void * V_636 , T_1 V_81 )
{
struct V_197 * V_55 ;
struct V_647 * V_648 ;
int V_605 ;
F_423 (lag_dev, dev, iter) {
if ( F_204 ( V_55 ) ) {
V_605 = F_424 ( V_649 , V_55 ,
V_635 , V_636 ,
V_81 ) ;
if ( V_605 )
return V_605 ;
}
}
return 0 ;
}
static int F_426 ( struct V_197 * V_649 ,
unsigned long V_635 , void * V_636 )
{
struct V_197 * V_650 = F_416 ( V_649 ) ;
T_1 V_81 = F_427 ( V_649 ) ;
if ( F_204 ( V_650 ) )
return F_424 ( V_649 , V_650 ,
V_635 , V_636 , V_81 ) ;
else if ( F_410 ( V_650 ) )
return F_425 ( V_649 ,
V_650 , V_635 ,
V_636 , V_81 ) ;
return 0 ;
}
static bool F_428 ( unsigned long V_635 , void * V_636 )
{
struct V_637 * V_630 = V_636 ;
if ( V_635 != V_639 && V_635 != V_642 )
return false ;
return F_429 ( V_630 -> V_638 ) ;
}
static int F_430 ( struct V_651 * V_652 ,
unsigned long V_635 , void * V_636 )
{
struct V_197 * V_55 = F_431 ( V_636 ) ;
int V_10 = 0 ;
if ( V_635 == V_653 || V_635 == V_654 )
V_10 = F_432 ( V_55 ) ;
else if ( F_428 ( V_635 , V_636 ) )
V_10 = F_433 ( V_55 , V_635 , V_636 ) ;
else if ( F_204 ( V_55 ) )
V_10 = F_421 ( V_55 , V_55 , V_635 , V_636 ) ;
else if ( F_410 ( V_55 ) )
V_10 = F_422 ( V_55 , V_635 , V_636 ) ;
else if ( F_409 ( V_55 ) )
V_10 = F_426 ( V_55 , V_635 , V_636 ) ;
return F_434 ( V_10 ) ;
}
static int T_9 F_435 ( void )
{
int V_10 ;
F_436 ( & V_655 ) ;
F_437 ( & V_656 ) ;
F_438 ( & V_657 ) ;
V_10 = F_439 ( & V_658 ) ;
if ( V_10 )
goto V_659;
V_10 = F_440 ( & V_660 ) ;
if ( V_10 )
goto V_661;
return 0 ;
V_661:
F_441 ( & V_658 ) ;
V_659:
F_442 ( & V_657 ) ;
F_443 ( & V_656 ) ;
F_444 ( & V_655 ) ;
return V_10 ;
}
static void T_10 F_445 ( void )
{
F_446 ( & V_660 ) ;
F_441 ( & V_658 ) ;
F_442 ( & V_657 ) ;
F_443 ( & V_656 ) ;
F_444 ( & V_655 ) ;
}
