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
if ( V_58 )
* V_58 = F_31 ( V_60 ) ;
if ( V_59 )
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
F_66 ( struct V_7 * V_7 , T_3 V_78 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_7 -> V_105 . V_106 ; V_102 ++ ) {
struct V_108 * V_110 = & V_7 -> V_105 . V_107 [ V_102 ] ;
if ( V_110 -> V_116 && V_110 -> V_78 == V_78 )
return V_110 ;
}
return NULL ;
}
static struct V_108
* F_67 ( struct V_80 * V_111 )
{
struct V_108 * V_112 ;
V_112 = F_66 ( V_111 -> V_7 ,
V_111 -> V_78 ) ;
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
T_3 V_142 ,
enum V_129 type )
{
struct V_108 * V_112 ;
V_112 = F_66 ( V_138 -> V_7 ,
V_142 ) ;
if ( ! V_112 ) {
F_76 ( V_138 -> V_55 , L_7 ) ;
return;
}
F_85 ( V_138 -> V_55 , L_8 ,
V_112 -> V_118 ) ;
F_82 ( V_138 , V_112 , type ) ;
}
static int F_87 ( struct V_80 * V_80 ,
bool V_143 , T_2 V_144 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_145 [ V_146 ] ;
F_88 ( V_145 , V_80 -> V_78 , V_143 , V_144 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_147 ) , V_145 ) ;
}
static int F_89 ( struct V_80 * V_80 ,
bool V_148 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_149 [ V_150 ] ;
F_90 ( V_149 , V_80 -> V_78 ,
V_148 ? V_151 :
V_152 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_153 ) , V_149 ) ;
}
static int F_91 ( struct V_80 * V_80 ,
unsigned char * V_154 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_155 [ V_156 ] ;
F_92 ( V_155 , true , V_80 -> V_78 ) ;
F_93 ( V_155 , V_154 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_157 ) , V_155 ) ;
}
static int F_94 ( struct V_80 * V_80 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
unsigned char * V_154 = V_80 -> V_55 -> V_158 ;
F_95 ( V_154 , V_7 -> V_101 ) ;
V_154 [ V_159 - 1 ] += V_80 -> V_78 ;
return F_91 ( V_80 , V_154 ) ;
}
static int F_96 ( struct V_80 * V_80 , T_1 V_124 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_160 [ V_161 ] ;
int V_162 ;
int V_10 ;
V_124 += V_74 + V_163 ;
F_97 ( V_160 , V_80 -> V_78 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_164 ) , V_160 ) ;
if ( V_10 )
return V_10 ;
V_162 = F_98 ( V_160 ) ;
if ( V_124 > V_162 )
return - V_165 ;
F_97 ( V_160 , V_80 -> V_78 , V_124 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_164 ) , V_160 ) ;
}
static int F_99 ( struct V_80 * V_80 , T_3 V_166 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_167 [ V_168 ] ;
F_100 ( V_167 , V_166 , V_80 -> V_78 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_169 ) , V_167 ) ;
}
int F_101 ( struct V_80 * V_80 , bool V_143 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_170 [ V_171 ] ;
F_102 ( V_170 , V_80 -> V_78 , V_143 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_172 ) , V_170 ) ;
}
int F_103 ( struct V_80 * V_80 , T_1 V_81 ,
bool V_173 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char * V_174 ;
int V_10 ;
V_174 = F_49 ( V_175 , V_95 ) ;
if ( ! V_174 )
return - V_96 ;
F_104 ( V_174 , V_80 -> V_78 , V_81 , V_81 ,
V_173 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_176 ) , V_174 ) ;
F_52 ( V_174 ) ;
return V_10 ;
}
static int F_105 ( struct V_80 * V_80 ,
T_1 V_81 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_177 [ V_178 ] ;
F_106 ( V_177 , V_80 -> V_78 , V_81 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_179 ) , V_177 ) ;
}
static int F_107 ( struct V_80 * V_80 ,
bool V_180 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_181 [ V_182 ] ;
F_108 ( V_181 , V_80 -> V_78 , V_180 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_183 ) , V_181 ) ;
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
goto V_184;
}
V_80 -> V_185 = V_81 ;
return 0 ;
V_184:
F_105 ( V_80 , V_80 -> V_185 ) ;
return V_10 ;
}
static int
F_110 ( struct V_80 * V_80 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_186 [ V_187 ] ;
F_111 ( V_186 , V_80 -> V_78 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_188 ) , V_186 ) ;
}
static int F_112 ( struct V_7 * V_7 ,
T_3 V_78 , T_3 * V_189 ,
T_3 * V_190 , T_3 * V_191 )
{
char V_192 [ V_193 ] ;
int V_10 ;
F_113 ( V_192 , V_78 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_194 ) , V_192 ) ;
if ( V_10 )
return V_10 ;
* V_189 = F_114 ( V_192 , 0 ) ;
* V_190 = F_115 ( V_192 ) ;
* V_191 = F_116 ( V_192 , 0 ) ;
return 0 ;
}
static int F_117 ( struct V_80 * V_80 ,
T_3 V_195 , T_3 V_196 , T_3 V_197 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_192 [ V_193 ] ;
int V_102 ;
F_113 ( V_192 , V_80 -> V_78 ) ;
F_118 ( V_192 , V_196 ) ;
for ( V_102 = 0 ; V_102 < V_196 ; V_102 ++ ) {
F_119 ( V_192 , V_102 , V_195 ) ;
F_120 ( V_192 , V_102 , V_197 + V_102 ) ;
}
return F_12 ( V_7 -> V_11 , F_5 ( V_194 ) , V_192 ) ;
}
static int F_121 ( struct V_80 * V_80 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_192 [ V_193 ] ;
F_113 ( V_192 , V_80 -> V_78 ) ;
F_118 ( V_192 , 0 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_194 ) , V_192 ) ;
}
static int F_122 ( struct V_198 * V_55 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
int V_10 ;
V_10 = F_89 ( V_80 , true ) ;
if ( V_10 )
return V_10 ;
F_124 ( V_55 ) ;
return 0 ;
}
static int F_125 ( struct V_198 * V_55 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
F_126 ( V_55 ) ;
return F_89 ( V_80 , false ) ;
}
static T_5 F_127 ( struct V_69 * V_70 ,
struct V_198 * V_55 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
struct V_199 * V_200 ;
const struct V_71 V_72 = {
. V_78 = V_80 -> V_78 ,
. V_201 = false ,
} ;
T_4 V_202 ;
int V_10 ;
if ( F_128 ( V_7 -> V_11 , & V_72 ) )
return V_203 ;
if ( F_129 ( F_130 ( V_70 ) < V_74 ) ) {
struct V_69 * V_204 = V_70 ;
V_70 = F_131 ( V_70 , V_74 ) ;
if ( ! V_70 ) {
F_132 ( V_80 -> V_200 -> V_205 ) ;
F_133 ( V_204 ) ;
return V_206 ;
}
F_134 ( V_204 ) ;
}
if ( F_135 ( V_70 ) ) {
F_132 ( V_80 -> V_200 -> V_205 ) ;
return V_206 ;
}
F_38 ( V_70 , & V_72 ) ;
V_202 = V_70 -> V_202 - V_74 ;
V_10 = F_136 ( V_7 -> V_11 , V_70 , & V_72 ) ;
if ( ! V_10 ) {
V_200 = F_137 ( V_80 -> V_200 ) ;
F_138 ( & V_200 -> V_207 ) ;
V_200 -> V_208 ++ ;
V_200 -> V_209 += V_202 ;
F_139 ( & V_200 -> V_207 ) ;
} else {
F_132 ( V_80 -> V_200 -> V_205 ) ;
F_133 ( V_70 ) ;
}
return V_206 ;
}
static void F_140 ( struct V_198 * V_55 )
{
}
static int F_141 ( struct V_198 * V_55 , void * V_122 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_210 * V_154 = V_122 ;
int V_10 ;
if ( ! F_142 ( V_154 -> V_211 ) )
return - V_212 ;
V_10 = F_91 ( V_80 , V_154 -> V_211 ) ;
if ( V_10 )
return V_10 ;
memcpy ( V_55 -> V_158 , V_154 -> V_211 , V_55 -> V_213 ) ;
return 0 ;
}
static T_1 F_143 ( const struct V_7 * V_7 ,
int V_124 )
{
return 2 * F_73 ( V_7 , V_124 ) ;
}
static T_1 F_144 ( const struct V_7 * V_7 , int V_124 ,
T_1 V_214 )
{
V_214 = F_73 ( V_7 , F_145 ( V_214 ,
V_215 ) ) ;
return V_216 * V_214 + F_73 ( V_7 ,
V_124 ) ;
}
static T_1 F_146 ( const struct V_7 * V_7 , int V_124 ,
T_1 V_214 , bool V_217 , bool V_218 )
{
if ( V_217 )
return F_144 ( V_7 , V_124 , V_214 ) ;
else if ( V_218 )
return F_73 ( V_7 , V_219 ) ;
else
return 0 ;
}
static void F_147 ( char * V_220 , int V_115 , T_1 V_25 , T_1 V_221 ,
bool V_222 )
{
if ( V_222 )
F_148 ( V_220 , V_115 , V_25 ) ;
else
F_149 ( V_220 , V_115 , V_25 ,
V_221 ) ;
}
int F_150 ( struct V_80 * V_80 , int V_124 ,
T_3 * V_223 , bool V_224 ,
struct V_225 * V_226 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
T_3 V_227 = ! ! V_226 ? V_226 -> V_227 : 0 ;
T_1 V_214 = ! ! V_226 ? V_226 -> V_214 : 0 ;
char V_220 [ V_228 ] ;
int V_102 , V_229 , V_10 ;
F_151 ( V_220 , V_80 -> V_78 , 0 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_230 ) , V_220 ) ;
if ( V_10 )
return V_10 ;
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ ) {
bool V_232 = false ;
bool V_217 = false ;
bool V_222 ;
T_1 V_221 ;
for ( V_229 = 0 ; V_229 < V_231 ; V_229 ++ ) {
if ( V_223 [ V_229 ] == V_102 ) {
V_217 = V_227 & F_152 ( V_229 ) ;
V_232 = true ;
break;
}
}
if ( ! V_232 )
continue;
V_222 = ! ( V_217 || V_224 ) ;
V_221 = F_143 ( V_7 , V_124 ) ;
V_214 = F_146 ( V_7 , V_124 , V_214 , V_217 ,
V_224 ) ;
F_147 ( V_220 , V_102 , V_221 + V_214 , V_221 , V_222 ) ;
}
return F_12 ( V_7 -> V_11 , F_5 ( V_230 ) , V_220 ) ;
}
static int F_153 ( struct V_80 * V_80 ,
int V_124 , bool V_224 )
{
T_3 V_233 [ V_231 ] = { 0 } ;
bool V_234 = ! ! V_80 -> V_235 . V_236 ;
struct V_225 * V_226 ;
T_3 * V_223 ;
V_223 = V_234 ? V_80 -> V_235 . V_236 -> V_223 : V_233 ;
V_226 = V_234 ? V_80 -> V_235 . V_217 : NULL ;
return F_150 ( V_80 , V_124 , V_223 ,
V_224 , V_226 ) ;
}
static int F_154 ( struct V_198 * V_55 , int V_124 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
bool V_224 = F_155 ( V_80 ) ;
int V_10 ;
V_10 = F_153 ( V_80 , V_124 , V_224 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_74 ( V_80 , V_124 ) ;
if ( V_10 )
goto V_237;
V_10 = F_96 ( V_80 , V_124 ) ;
if ( V_10 )
goto V_238;
V_55 -> V_124 = V_124 ;
return 0 ;
V_238:
F_74 ( V_80 , V_55 -> V_124 ) ;
V_237:
F_153 ( V_80 , V_55 -> V_124 , V_224 ) ;
return V_10 ;
}
static int
F_156 ( const struct V_198 * V_55 ,
struct V_239 * V_240 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_199 * V_122 ;
T_4 V_241 , V_242 , V_208 , V_209 ;
T_2 V_205 = 0 ;
unsigned int V_243 ;
int V_102 ;
F_157 (i) {
V_122 = F_158 ( V_80 -> V_200 , V_102 ) ;
do {
V_243 = F_159 ( & V_122 -> V_207 ) ;
V_241 = V_122 -> V_241 ;
V_242 = V_122 -> V_242 ;
V_208 = V_122 -> V_208 ;
V_209 = V_122 -> V_209 ;
} while ( F_160 ( & V_122 -> V_207 , V_243 ) );
V_240 -> V_241 += V_241 ;
V_240 -> V_242 += V_242 ;
V_240 -> V_208 += V_208 ;
V_240 -> V_209 += V_209 ;
V_205 += V_122 -> V_205 ;
}
V_240 -> V_205 = V_205 ;
return 0 ;
}
static bool F_161 ( const struct V_198 * V_55 , int V_244 )
{
switch ( V_244 ) {
case V_245 :
return true ;
}
return false ;
}
static int F_162 ( int V_244 , const struct V_198 * V_55 ,
void * V_246 )
{
switch ( V_244 ) {
case V_245 :
return F_156 ( V_55 , V_246 ) ;
}
return - V_165 ;
}
static int F_163 ( struct V_198 * V_55 , int V_247 ,
int V_248 , char * V_249 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
F_164 ( V_249 , V_80 -> V_78 , V_247 , V_248 ) ;
return F_4 ( V_7 -> V_11 , F_5 ( V_250 ) , V_249 ) ;
}
static int F_165 ( struct V_198 * V_55 ,
struct V_239 * V_240 )
{
char V_249 [ V_251 ] ;
int V_10 ;
V_10 = F_163 ( V_55 , V_252 ,
0 , V_249 ) ;
if ( V_10 )
goto V_253;
V_240 -> V_208 =
F_166 ( V_249 ) ;
V_240 -> V_241 =
F_167 ( V_249 ) ;
V_240 -> V_209 =
F_168 ( V_249 ) ;
V_240 -> V_242 =
F_169 ( V_249 ) ;
V_240 -> V_254 =
F_170 ( V_249 ) ;
V_240 -> V_255 =
F_171 ( V_249 ) ;
V_240 -> V_256 =
F_172 ( V_249 ) ;
V_240 -> V_257 = (
F_173 ( V_249 ) +
F_174 ( V_249 ) +
F_175 ( V_249 ) ) ;
V_240 -> V_258 = ( V_240 -> V_255 +
V_240 -> V_256 + V_240 -> V_257 ) ;
V_253:
return V_10 ;
}
static void F_176 ( struct V_259 * V_260 )
{
struct V_80 * V_80 =
F_2 ( V_260 , struct V_80 ,
V_261 . V_262 . V_260 ) ;
if ( ! F_177 ( V_80 -> V_55 ) )
goto V_253;
F_165 ( V_80 -> V_55 ,
V_80 -> V_261 . V_263 ) ;
V_253:
F_178 ( & V_80 -> V_261 . V_262 ,
V_264 ) ;
}
static void
F_179 ( struct V_198 * V_55 ,
struct V_239 * V_240 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
memcpy ( V_240 , V_80 -> V_261 . V_263 , sizeof( * V_240 ) ) ;
}
static int F_180 ( struct V_80 * V_80 ,
T_1 V_265 , T_1 V_266 ,
bool V_267 , bool V_268 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char * V_269 ;
int V_10 ;
V_269 = F_49 ( V_270 , V_95 ) ;
if ( ! V_269 )
return - V_96 ;
F_181 ( V_269 , V_80 -> V_78 , V_265 ,
V_266 , V_267 , V_268 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_271 ) , V_269 ) ;
F_52 ( V_269 ) ;
return V_10 ;
}
int F_182 ( struct V_80 * V_80 , T_1 V_265 ,
T_1 V_266 , bool V_267 , bool V_268 )
{
T_1 V_81 , V_272 ;
int V_10 ;
for ( V_81 = V_265 ; V_81 <= V_266 ;
V_81 += V_273 ) {
V_272 = F_183 ( ( T_1 ) ( V_81 + V_273 - 1 ) ,
V_266 ) ;
V_10 = F_180 ( V_80 , V_81 , V_272 ,
V_267 , V_268 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_184 ( struct V_80 * V_80 )
{
struct V_274 * V_274 , * V_275 ;
F_185 (mlxsw_sp_port_vlan, tmp,
&mlxsw_sp_port->vlans_list, list)
F_186 ( V_274 ) ;
}
static struct V_274 *
F_187 ( struct V_80 * V_80 , T_1 V_81 )
{
struct V_274 * V_274 ;
bool V_268 = V_81 == 1 ;
int V_10 ;
V_10 = F_182 ( V_80 , V_81 , V_81 , true , V_268 ) ;
if ( V_10 )
return F_188 ( V_10 ) ;
V_274 = F_80 ( sizeof( * V_274 ) , V_95 ) ;
if ( ! V_274 ) {
V_10 = - V_96 ;
goto V_276;
}
V_274 -> V_80 = V_80 ;
V_274 -> V_81 = V_81 ;
F_189 ( & V_274 -> V_137 , & V_80 -> V_277 ) ;
return V_274 ;
V_276:
F_182 ( V_80 , V_81 , V_81 , false , false ) ;
return F_188 ( V_10 ) ;
}
static void
F_190 ( struct V_274 * V_274 )
{
struct V_80 * V_80 = V_274 -> V_80 ;
T_1 V_81 = V_274 -> V_81 ;
F_83 ( & V_274 -> V_137 ) ;
F_52 ( V_274 ) ;
F_182 ( V_80 , V_81 , V_81 , false , false ) ;
}
struct V_274 *
F_191 ( struct V_80 * V_80 , T_1 V_81 )
{
struct V_274 * V_274 ;
V_274 = F_192 ( V_80 , V_81 ) ;
if ( V_274 )
return V_274 ;
return F_187 ( V_80 , V_81 ) ;
}
void F_186 ( struct V_274 * V_274 )
{
struct V_278 * V_279 = V_274 -> V_279 ;
if ( V_274 -> V_280 )
F_193 ( V_274 ) ;
else if ( V_279 )
F_194 ( V_274 ) ;
F_190 ( V_274 ) ;
}
static int F_195 ( struct V_198 * V_55 ,
T_6 T_7 V_281 , T_1 V_81 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
if ( ! V_81 )
return 0 ;
return F_196 ( F_191 ( V_80 , V_81 ) ) ;
}
static int F_197 ( struct V_198 * V_55 ,
T_6 T_7 V_281 , T_1 V_81 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_274 * V_274 ;
if ( ! V_81 )
return 0 ;
V_274 = F_192 ( V_80 , V_81 ) ;
if ( ! V_274 )
return 0 ;
F_186 ( V_274 ) ;
return 0 ;
}
static int F_198 ( struct V_198 * V_55 , char * V_282 ,
T_8 V_202 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
T_3 V_195 = V_80 -> V_283 . V_195 ;
T_3 V_196 = V_80 -> V_283 . V_196 ;
T_3 V_197 = V_80 -> V_283 . V_197 ;
int V_10 ;
if ( ! V_80 -> V_284 )
V_10 = snprintf ( V_282 , V_202 , L_9 , V_195 + 1 ) ;
else
V_10 = snprintf ( V_282 , V_202 , L_10 , V_195 + 1 ,
V_197 / V_196 ) ;
if ( V_10 >= V_202 )
return - V_165 ;
return 0 ;
}
static struct V_285 *
F_199 ( struct V_80 * V_111 ,
unsigned long V_286 ) {
struct V_285 * V_287 ;
F_71 (mall_tc_entry, &port->mall_tc_list, list)
if ( V_287 -> V_286 == V_286 )
return V_287 ;
return NULL ;
}
static int
F_200 ( struct V_80 * V_80 ,
struct V_288 * V_289 ,
const struct V_290 * V_47 ,
bool V_291 )
{
struct V_292 * V_292 = F_201 ( V_80 -> V_55 ) ;
enum V_129 V_293 ;
struct V_80 * V_294 ;
struct V_198 * V_295 ;
int V_296 ;
V_296 = F_202 ( V_47 ) ;
V_295 = F_203 ( V_292 , V_296 ) ;
if ( ! V_295 ) {
F_76 ( V_80 -> V_55 , L_11 ) ;
return - V_165 ;
}
if ( ! F_204 ( V_295 ) ) {
F_76 ( V_80 -> V_55 , L_12 ) ;
return - V_297 ;
}
V_294 = F_123 ( V_295 ) ;
V_289 -> V_298 = V_294 -> V_78 ;
V_289 -> V_291 = V_291 ;
V_293 = V_291 ? V_299 : V_123 ;
return F_84 ( V_80 , V_294 , V_293 ) ;
}
static void
F_205 ( struct V_80 * V_80 ,
struct V_288 * V_289 )
{
enum V_129 V_293 ;
V_293 = V_289 -> V_291 ?
V_299 : V_123 ;
F_86 ( V_80 , V_289 -> V_298 ,
V_293 ) ;
}
static int
F_206 ( struct V_80 * V_80 ,
struct V_300 * V_301 ,
const struct V_290 * V_47 ,
bool V_291 )
{
int V_10 ;
if ( ! V_80 -> V_302 )
return - V_297 ;
if ( F_207 ( V_80 -> V_302 -> V_303 ) ) {
F_76 ( V_80 -> V_55 , L_13 ) ;
return - V_304 ;
}
if ( F_208 ( V_47 ) > V_305 ) {
F_76 ( V_80 -> V_55 , L_14 ) ;
return - V_297 ;
}
F_209 ( V_80 -> V_302 -> V_303 ,
F_210 ( V_47 ) ) ;
V_80 -> V_302 -> V_306 = F_211 ( V_47 ) ;
V_80 -> V_302 -> V_307 = F_212 ( V_47 ) ;
V_80 -> V_302 -> V_144 = F_208 ( V_47 ) ;
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
struct V_300 * V_309 ,
bool V_291 )
{
struct V_285 * V_287 ;
T_6 V_310 = V_309 -> V_311 . V_310 ;
const struct V_290 * V_47 ;
F_216 ( V_312 ) ;
int V_10 ;
if ( ! F_217 ( V_309 -> V_313 ) ) {
F_76 ( V_80 -> V_55 , L_15 ) ;
return - V_297 ;
}
V_287 = F_80 ( sizeof( * V_287 ) , V_95 ) ;
if ( ! V_287 )
return - V_96 ;
V_287 -> V_286 = V_309 -> V_286 ;
F_218 ( V_309 -> V_313 , & V_312 ) ;
V_47 = F_219 ( & V_312 , struct V_290 , V_137 ) ;
if ( F_220 ( V_47 ) && V_310 == F_221 ( V_314 ) ) {
struct V_288 * V_289 ;
V_287 -> type = V_315 ;
V_289 = & V_287 -> V_289 ;
V_10 = F_200 ( V_80 ,
V_289 , V_47 , V_291 ) ;
} else if ( F_222 ( V_47 ) && V_310 == F_221 ( V_314 ) ) {
V_287 -> type = V_316 ;
V_10 = F_206 ( V_80 , V_309 ,
V_47 , V_291 ) ;
} else {
V_10 = - V_297 ;
}
if ( V_10 )
goto V_317;
F_81 ( & V_287 -> V_137 , & V_80 -> V_318 ) ;
return 0 ;
V_317:
F_52 ( V_287 ) ;
return V_10 ;
}
static void F_223 ( struct V_80 * V_80 ,
struct V_300 * V_309 )
{
struct V_285 * V_287 ;
V_287 = F_199 ( V_80 ,
V_309 -> V_286 ) ;
if ( ! V_287 ) {
F_85 ( V_80 -> V_55 , L_16 ) ;
return;
}
F_83 ( & V_287 -> V_137 ) ;
switch ( V_287 -> type ) {
case V_315 :
F_205 ( V_80 ,
& V_287 -> V_289 ) ;
break;
case V_316 :
F_214 ( V_80 ) ;
break;
default:
F_69 ( 1 ) ;
}
F_52 ( V_287 ) ;
}
static int F_224 ( struct V_80 * V_80 ,
struct V_300 * V_309 )
{
bool V_291 ;
if ( F_225 ( V_309 -> V_311 . V_319 ) )
V_291 = true ;
else if ( F_226 ( V_309 -> V_311 . V_319 ) )
V_291 = false ;
else
return - V_297 ;
if ( V_309 -> V_311 . V_320 )
return - V_297 ;
switch ( V_309 -> V_321 ) {
case V_322 :
return F_215 ( V_80 , V_309 ,
V_291 ) ;
case V_323 :
F_223 ( V_80 , V_309 ) ;
return 0 ;
default:
return - V_297 ;
}
}
static int
F_227 ( struct V_80 * V_80 ,
struct V_324 * V_309 )
{
bool V_291 ;
if ( F_225 ( V_309 -> V_311 . V_319 ) )
V_291 = true ;
else if ( F_226 ( V_309 -> V_311 . V_319 ) )
V_291 = false ;
else
return - V_297 ;
switch ( V_309 -> V_321 ) {
case V_325 :
return F_228 ( V_80 , V_291 , V_309 ) ;
case V_326 :
F_229 ( V_80 , V_291 , V_309 ) ;
return 0 ;
case V_327 :
return F_230 ( V_80 , V_291 , V_309 ) ;
default:
return - V_297 ;
}
}
static int F_231 ( struct V_198 * V_55 , enum V_328 type ,
void * V_329 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
switch ( type ) {
case V_330 :
return F_224 ( V_80 , V_329 ) ;
case V_331 :
return F_227 ( V_80 , V_329 ) ;
default:
return - V_297 ;
}
}
static void F_232 ( struct V_198 * V_55 ,
struct V_332 * V_333 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
F_233 ( V_333 -> V_334 , V_335 , sizeof( V_333 -> V_334 ) ) ;
F_233 ( V_333 -> V_336 , V_337 ,
sizeof( V_333 -> V_336 ) ) ;
snprintf ( V_333 -> V_338 , sizeof( V_333 -> V_338 ) ,
L_17 ,
V_7 -> V_44 -> V_53 . V_49 ,
V_7 -> V_44 -> V_53 . V_50 ,
V_7 -> V_44 -> V_53 . V_51 ) ;
F_233 ( V_333 -> V_44 , V_7 -> V_44 -> V_339 ,
sizeof( V_333 -> V_44 ) ) ;
}
static void F_234 ( struct V_198 * V_55 ,
struct V_340 * V_218 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
V_218 -> V_341 = V_80 -> V_342 . V_341 ;
V_218 -> V_343 = V_80 -> V_342 . V_343 ;
}
static int F_235 ( struct V_80 * V_80 ,
struct V_340 * V_218 )
{
char V_344 [ V_345 ] ;
F_236 ( V_344 , V_80 -> V_78 ) ;
F_237 ( V_344 , V_218 -> V_341 ) ;
F_238 ( V_344 , V_218 -> V_343 ) ;
return F_12 ( V_80 -> V_7 -> V_11 , F_5 ( V_346 ) ,
V_344 ) ;
}
static int F_239 ( struct V_198 * V_55 ,
struct V_340 * V_218 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
bool V_224 = V_218 -> V_343 || V_218 -> V_341 ;
int V_10 ;
if ( V_80 -> V_235 . V_217 && V_80 -> V_235 . V_217 -> V_227 ) {
F_76 ( V_55 , L_18 ) ;
return - V_165 ;
}
if ( V_218 -> V_347 ) {
F_76 ( V_55 , L_19 ) ;
return - V_165 ;
}
V_10 = F_153 ( V_80 , V_55 -> V_124 , V_224 ) ;
if ( V_10 ) {
F_76 ( V_55 , L_20 ) ;
return V_10 ;
}
V_10 = F_235 ( V_80 , V_218 ) ;
if ( V_10 ) {
F_76 ( V_55 , L_21 ) ;
goto V_348;
}
V_80 -> V_342 . V_341 = V_218 -> V_341 ;
V_80 -> V_342 . V_343 = V_218 -> V_343 ;
return 0 ;
V_348:
V_224 = F_155 ( V_80 ) ;
F_153 ( V_80 , V_55 -> V_124 , V_224 ) ;
return V_10 ;
}
static void F_240 ( T_3 * * V_122 , int V_248 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_349 ; V_102 ++ ) {
snprintf ( * V_122 , V_350 , L_22 ,
V_351 [ V_102 ] . V_352 , V_248 ) ;
* V_122 += V_350 ;
}
}
static void F_241 ( T_3 * * V_122 , int V_353 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_354 ; V_102 ++ ) {
snprintf ( * V_122 , V_350 , L_22 ,
V_355 [ V_102 ] . V_352 , V_353 ) ;
* V_122 += V_350 ;
}
}
static void F_242 ( struct V_198 * V_55 ,
T_2 V_356 , T_3 * V_24 )
{
T_3 * V_122 = V_24 ;
int V_102 ;
switch ( V_356 ) {
case V_357 :
for ( V_102 = 0 ; V_102 < V_358 ; V_102 ++ ) {
memcpy ( V_122 , V_359 [ V_102 ] . V_352 ,
V_350 ) ;
V_122 += V_350 ;
}
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ )
F_240 ( & V_122 , V_102 ) ;
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ )
F_241 ( & V_122 , V_102 ) ;
break;
}
}
static int F_243 ( struct V_198 * V_55 ,
enum V_360 V_82 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
char V_361 [ V_362 ] ;
bool V_363 ;
switch ( V_82 ) {
case V_364 :
V_363 = true ;
break;
case V_365 :
V_363 = false ;
break;
default:
return - V_297 ;
}
F_244 ( V_361 , V_80 -> V_78 , V_363 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_366 ) , V_361 ) ;
}
static int
F_245 ( struct V_359 * * V_367 ,
int * V_368 , enum V_369 V_247 )
{
switch ( V_247 ) {
case V_252 :
* V_367 = V_359 ;
* V_368 = V_358 ;
break;
case V_370 :
* V_367 = V_351 ;
* V_368 = V_349 ;
break;
case V_371 :
* V_367 = V_355 ;
* V_368 = V_354 ;
break;
default:
F_69 ( 1 ) ;
return - V_297 ;
}
return 0 ;
}
static void F_246 ( struct V_198 * V_55 ,
enum V_369 V_247 , int V_248 ,
T_4 * V_24 , int V_372 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
struct V_359 * V_261 ;
char V_249 [ V_251 ] ;
int V_102 , V_202 ;
int V_10 ;
V_10 = F_245 ( & V_261 , & V_202 , V_247 ) ;
if ( V_10 )
return;
F_163 ( V_55 , V_247 , V_248 , V_249 ) ;
for ( V_102 = 0 ; V_102 < V_202 ; V_102 ++ ) {
V_24 [ V_372 + V_102 ] = V_261 [ V_102 ] . F_247 ( V_249 ) ;
if ( ! V_261 [ V_102 ] . V_373 )
continue;
V_24 [ V_372 + V_102 ] = F_248 ( V_7 ,
V_24 [ V_372 + V_102 ] ) ;
}
}
static void F_249 ( struct V_198 * V_55 ,
struct V_374 * V_240 , T_4 * V_24 )
{
int V_102 , V_372 = 0 ;
F_246 ( V_55 , V_252 , 0 ,
V_24 , V_372 ) ;
V_372 = V_358 ;
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ ) {
F_246 ( V_55 , V_370 , V_102 ,
V_24 , V_372 ) ;
V_372 += V_349 ;
}
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ ) {
F_246 ( V_55 , V_371 , V_102 ,
V_24 , V_372 ) ;
V_372 += V_354 ;
}
}
static int F_250 ( struct V_198 * V_55 , int V_375 )
{
switch ( V_375 ) {
case V_357 :
return V_376 ;
default:
return - V_297 ;
}
}
static void
F_251 ( T_2 V_377 ,
struct V_378 * V_379 )
{
if ( V_377 & ( V_380 |
V_381 |
V_382 |
V_383 |
V_384 |
V_385 ) )
F_252 ( V_379 , V_386 , V_387 ) ;
if ( V_377 & ( V_388 |
V_389 |
V_390 |
V_391 |
V_392 ) )
F_252 ( V_379 , V_386 , V_393 ) ;
}
static void F_253 ( T_2 V_377 , unsigned long * V_394 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_395 ; V_102 ++ ) {
if ( V_377 & V_396 [ V_102 ] . V_397 )
F_254 ( V_396 [ V_102 ] . V_398 ,
V_394 ) ;
}
}
static void F_255 ( bool V_399 , T_2 V_377 ,
struct V_378 * V_379 )
{
T_2 V_400 = V_401 ;
T_3 V_402 = V_403 ;
int V_102 ;
if ( ! V_399 )
goto V_253;
for ( V_102 = 0 ; V_102 < V_395 ; V_102 ++ ) {
if ( V_377 & V_396 [ V_102 ] . V_397 ) {
V_400 = V_396 [ V_102 ] . V_400 ;
V_402 = V_404 ;
break;
}
}
V_253:
V_379 -> V_405 . V_400 = V_400 ;
V_379 -> V_405 . V_402 = V_402 ;
}
static T_3 F_256 ( T_2 V_377 )
{
if ( V_377 & ( V_381 |
V_383 |
V_384 |
V_385 ) )
return V_406 ;
if ( V_377 & ( V_380 |
V_382 |
V_407 ) )
return V_408 ;
if ( V_377 & ( V_388 |
V_389 |
V_390 |
V_391 ) )
return V_409 ;
return V_410 ;
}
static T_2
F_257 ( const struct V_378 * V_379 )
{
T_2 V_411 = 0 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_395 ; V_102 ++ ) {
if ( F_258 ( V_396 [ V_102 ] . V_398 ,
V_379 -> V_412 . V_413 ) )
V_411 |= V_396 [ V_102 ] . V_397 ;
}
return V_411 ;
}
static T_2 F_259 ( T_2 V_400 )
{
T_2 V_411 = 0 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_395 ; V_102 ++ ) {
if ( V_400 == V_396 [ V_102 ] . V_400 )
V_411 |= V_396 [ V_102 ] . V_397 ;
}
return V_411 ;
}
static T_2 F_260 ( T_2 V_414 )
{
T_2 V_411 = 0 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_395 ; V_102 ++ ) {
if ( V_396 [ V_102 ] . V_400 <= V_414 )
V_411 |= V_396 [ V_102 ] . V_397 ;
}
return V_411 ;
}
static void F_261 ( T_2 V_415 ,
struct V_378 * V_379 )
{
F_252 ( V_379 , V_386 , V_416 ) ;
F_252 ( V_379 , V_386 , V_417 ) ;
F_252 ( V_379 , V_386 , V_418 ) ;
F_251 ( V_415 , V_379 ) ;
F_253 ( V_415 , V_379 -> V_412 . V_386 ) ;
}
static void F_262 ( T_2 V_419 , bool V_347 ,
struct V_378 * V_379 )
{
if ( ! V_347 )
return;
F_252 ( V_379 , V_413 , V_417 ) ;
F_253 ( V_419 , V_379 -> V_412 . V_413 ) ;
}
static void
F_263 ( T_2 V_420 , T_3 V_421 ,
struct V_378 * V_379 )
{
if ( V_421 != V_422 || ! V_420 )
return;
F_252 ( V_379 , V_423 , V_417 ) ;
F_253 ( V_420 , V_379 -> V_412 . V_423 ) ;
}
static int F_264 ( struct V_198 * V_55 ,
struct V_378 * V_379 )
{
T_2 V_415 , V_419 , V_424 , V_420 ;
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
char V_425 [ V_426 ] ;
T_3 V_421 ;
bool V_347 ;
int V_10 ;
V_347 = V_80 -> V_342 . V_347 ;
F_265 ( V_425 , V_80 -> V_78 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_427 ) , V_425 ) ;
if ( V_10 )
return V_10 ;
F_266 ( V_425 , & V_415 , & V_419 ,
& V_424 ) ;
F_261 ( V_415 , V_379 ) ;
F_262 ( V_419 , V_347 , V_379 ) ;
V_420 = F_267 ( V_425 ) ;
V_421 = F_268 ( V_425 ) ;
F_263 ( V_420 , V_421 , V_379 ) ;
V_379 -> V_405 . V_347 = V_347 ? V_428 : V_429 ;
V_379 -> V_405 . V_111 = F_256 ( V_424 ) ;
F_255 ( F_177 ( V_55 ) , V_424 ,
V_379 ) ;
return 0 ;
}
static int
F_269 ( struct V_198 * V_55 ,
const struct V_378 * V_379 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
char V_425 [ V_426 ] ;
T_2 V_415 , V_430 ;
bool V_347 ;
int V_10 ;
F_265 ( V_425 , V_80 -> V_78 , 0 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_427 ) , V_425 ) ;
if ( V_10 )
return V_10 ;
F_266 ( V_425 , & V_415 , NULL , NULL ) ;
V_347 = V_379 -> V_405 . V_347 == V_428 ;
V_430 = V_347 ?
F_257 ( V_379 ) :
F_259 ( V_379 -> V_405 . V_400 ) ;
V_430 = V_430 & V_415 ;
if ( ! V_430 ) {
F_76 ( V_55 , L_23 ) ;
return - V_165 ;
}
F_265 ( V_425 , V_80 -> V_78 ,
V_430 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_427 ) , V_425 ) ;
if ( V_10 )
return V_10 ;
if ( ! F_270 ( V_55 ) )
return 0 ;
V_80 -> V_342 . V_347 = V_347 ;
F_89 ( V_80 , false ) ;
F_89 ( V_80 , true ) ;
return 0 ;
}
static int F_271 ( struct V_198 * V_55 ,
struct V_431 * V_432 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_7 * V_7 = V_80 -> V_7 ;
const struct V_40 * V_40 ;
int V_10 ;
if ( V_432 -> V_433 != V_434 )
return - V_297 ;
F_272 ( V_55 ) ;
F_273 () ;
V_10 = F_26 ( & V_40 , V_432 -> V_24 , & V_55 -> V_55 ) ;
if ( V_10 )
goto V_253;
V_10 = F_21 ( V_7 , V_40 ) ;
F_28 ( V_40 ) ;
V_253:
F_274 () ;
F_275 ( V_55 ) ;
return V_10 ;
}
static int F_276 ( struct V_80 * V_80 ,
T_1 V_26 , T_1 V_25 , void * V_24 ,
unsigned int * V_435 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_436 [ V_437 ] ;
char V_438 [ V_439 ] ;
T_1 V_440 ;
int V_441 ;
int V_10 ;
V_25 = F_8 ( T_1 , V_25 , V_437 ) ;
if ( V_26 < V_442 &&
V_26 + V_25 > V_442 )
V_25 = V_442 - V_26 ;
V_440 = V_443 ;
if ( V_26 >= V_442 ) {
V_440 = V_444 ;
V_26 -= V_442 ;
}
F_277 ( V_438 , V_80 -> V_283 . V_195 ,
0 , 0 , V_26 , V_25 , V_440 ) ;
V_10 = F_4 ( V_7 -> V_11 , F_5 ( V_445 ) , V_438 ) ;
if ( V_10 )
return V_10 ;
V_441 = F_278 ( V_438 ) ;
if ( V_441 )
return - V_104 ;
F_279 ( V_438 , V_436 ) ;
memcpy ( V_24 , V_436 , V_25 ) ;
* V_435 = V_25 ;
return 0 ;
}
static int F_280 ( struct V_198 * V_446 ,
struct V_447 * V_448 )
{
struct V_80 * V_80 = F_123 ( V_446 ) ;
T_3 V_449 [ V_450 ] ;
T_3 V_451 , V_452 ;
unsigned int V_453 ;
int V_10 ;
V_10 = F_276 ( V_80 , 0 ,
V_450 ,
V_449 , & V_453 ) ;
if ( V_10 )
return V_10 ;
if ( V_453 < V_450 )
return - V_104 ;
V_451 = V_449 [ V_454 ] ;
V_452 = V_449 [ V_455 ] ;
switch ( V_452 ) {
case V_456 :
V_448 -> type = V_457 ;
V_448 -> V_458 = V_459 ;
break;
case V_460 :
case V_461 :
if ( V_452 == V_461 ||
V_451 >= V_462 ) {
V_448 -> type = V_463 ;
V_448 -> V_458 = V_464 ;
} else {
V_448 -> type = V_457 ;
V_448 -> V_458 = V_459 ;
}
break;
case V_465 :
V_448 -> type = V_466 ;
V_448 -> V_458 = V_467 ;
break;
default:
return - V_165 ;
}
return 0 ;
}
static int F_281 ( struct V_198 * V_446 ,
struct V_468 * V_469 ,
T_3 * V_24 )
{
struct V_80 * V_80 = F_123 ( V_446 ) ;
int V_26 = V_469 -> V_26 ;
unsigned int V_453 ;
int V_102 = 0 ;
int V_10 ;
if ( ! V_469 -> V_202 )
return - V_165 ;
memset ( V_24 , 0 , V_469 -> V_202 ) ;
while ( V_102 < V_469 -> V_202 ) {
V_10 = F_276 ( V_80 , V_26 ,
V_469 -> V_202 - V_102 , V_24 + V_102 ,
& V_453 ) ;
if ( V_10 ) {
F_76 ( V_80 -> V_55 , L_24 ) ;
return V_10 ;
}
V_102 += V_453 ;
V_26 += V_453 ;
}
return 0 ;
}
static int
F_282 ( struct V_80 * V_80 , T_3 V_196 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
T_2 V_414 = V_470 * V_196 ;
char V_425 [ V_426 ] ;
T_2 V_419 ;
V_419 = F_260 ( V_414 ) ;
F_265 ( V_425 , V_80 -> V_78 ,
V_419 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_427 ) , V_425 ) ;
}
int F_283 ( struct V_80 * V_80 ,
enum V_471 V_472 , T_3 V_115 , T_3 V_473 ,
bool V_474 , T_3 V_475 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_476 [ V_477 ] ;
F_284 ( V_476 , V_80 -> V_78 , V_472 , V_115 ,
V_473 ) ;
F_285 ( V_476 , true ) ;
F_286 ( V_476 , V_474 ) ;
F_287 ( V_476 , V_475 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_478 ) , V_476 ) ;
}
int F_288 ( struct V_80 * V_80 ,
enum V_471 V_472 , T_3 V_115 ,
T_3 V_473 , T_2 V_479 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_476 [ V_477 ] ;
F_284 ( V_476 , V_80 -> V_78 , V_472 , V_115 ,
V_473 ) ;
F_289 ( V_476 , true ) ;
F_290 ( V_476 , V_479 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_478 ) , V_476 ) ;
}
int F_291 ( struct V_80 * V_80 ,
T_3 V_480 , T_3 V_481 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_482 [ V_483 ] ;
F_292 ( V_482 , V_80 -> V_78 , V_480 ,
V_481 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_484 ) , V_482 ) ;
}
static int F_293 ( struct V_80 * V_80 )
{
int V_10 , V_102 ;
V_10 = F_283 ( V_80 ,
V_485 , 0 , 0 , false ,
0 ) ;
if ( V_10 )
return V_10 ;
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ ) {
V_10 = F_283 ( V_80 ,
V_486 , V_102 ,
0 , false , 0 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ ) {
V_10 = F_283 ( V_80 ,
V_487 , V_102 , V_102 ,
false , 0 ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_288 ( V_80 ,
V_488 , 0 , 0 ,
V_489 ) ;
if ( V_10 )
return V_10 ;
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ ) {
V_10 = F_288 ( V_80 ,
V_486 ,
V_102 , 0 ,
V_489 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ ) {
V_10 = F_288 ( V_80 ,
V_487 ,
V_102 , V_102 ,
V_489 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_102 = 0 ; V_102 < V_231 ; V_102 ++ ) {
V_10 = F_291 ( V_80 , V_102 , 0 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_294 ( struct V_7 * V_7 , T_3 V_78 ,
bool V_284 , T_3 V_195 , T_3 V_196 , T_3 V_197 )
{
struct V_274 * V_274 ;
struct V_80 * V_80 ;
struct V_198 * V_55 ;
int V_10 ;
V_10 = F_295 ( V_7 -> V_11 , V_78 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_25 ,
V_78 ) ;
return V_10 ;
}
V_55 = F_296 ( sizeof( struct V_80 ) ) ;
if ( ! V_55 ) {
V_10 = - V_96 ;
goto V_490;
}
F_297 ( V_55 , V_7 -> V_44 -> V_55 ) ;
V_80 = F_123 ( V_55 ) ;
V_80 -> V_55 = V_55 ;
V_80 -> V_7 = V_7 ;
V_80 -> V_78 = V_78 ;
V_80 -> V_185 = 1 ;
V_80 -> V_284 = V_284 ;
V_80 -> V_283 . V_195 = V_195 ;
V_80 -> V_283 . V_196 = V_196 ;
V_80 -> V_283 . V_197 = V_197 ;
V_80 -> V_342 . V_347 = 1 ;
F_59 ( & V_80 -> V_277 ) ;
F_59 ( & V_80 -> V_318 ) ;
V_80 -> V_200 =
F_298 ( struct V_199 ) ;
if ( ! V_80 -> V_200 ) {
V_10 = - V_96 ;
goto V_491;
}
V_80 -> V_302 = F_80 ( sizeof( * V_80 -> V_302 ) ,
V_95 ) ;
if ( ! V_80 -> V_302 ) {
V_10 = - V_96 ;
goto V_492;
}
V_80 -> V_261 . V_263 =
F_80 ( sizeof( * V_80 -> V_261 . V_263 ) , V_95 ) ;
if ( ! V_80 -> V_261 . V_263 ) {
V_10 = - V_96 ;
goto V_493;
}
F_299 ( & V_80 -> V_261 . V_262 ,
& F_176 ) ;
V_55 -> V_494 = & V_495 ;
V_55 -> V_496 = & V_497 ;
V_10 = F_117 ( V_80 , V_195 , V_196 , V_197 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_26 ,
V_80 -> V_78 ) ;
goto V_498;
}
V_10 = F_99 ( V_80 , 0 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_27 ,
V_80 -> V_78 ) ;
goto V_499;
}
V_10 = F_94 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_28 ,
V_80 -> V_78 ) ;
goto V_500;
}
F_300 ( V_55 ) ;
V_55 -> V_501 |= V_502 | V_503 | V_504 |
V_505 | V_506 ;
V_55 -> V_507 |= V_506 ;
V_55 -> V_508 = 0 ;
V_55 -> V_162 = V_509 ;
V_55 -> V_510 = V_74 ;
V_10 = F_110 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_29 ,
V_80 -> V_78 ) ;
goto V_511;
}
V_10 = F_282 ( V_80 , V_196 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_30 ,
V_80 -> V_78 ) ;
goto V_512;
}
V_10 = F_96 ( V_80 , V_513 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_31 ,
V_80 -> V_78 ) ;
goto V_238;
}
V_10 = F_89 ( V_80 , false ) ;
if ( V_10 )
goto V_514;
V_10 = F_301 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_32 ,
V_80 -> V_78 ) ;
goto V_515;
}
V_10 = F_293 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_33 ,
V_80 -> V_78 ) ;
goto V_516;
}
V_10 = F_302 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_34 ,
V_80 -> V_78 ) ;
goto V_517;
}
V_10 = F_303 ( V_80 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_35 ,
V_80 -> V_78 ) ;
goto V_518;
}
V_274 = F_191 ( V_80 , 1 ) ;
if ( F_304 ( V_274 ) ) {
F_27 ( V_7 -> V_44 -> V_55 , L_36 ,
V_80 -> V_78 ) ;
goto V_519;
}
F_305 ( V_80 ) ;
V_7 -> V_520 [ V_78 ] = V_80 ;
V_10 = F_306 ( V_55 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_37 ,
V_80 -> V_78 ) ;
goto V_521;
}
F_307 ( V_7 -> V_11 , V_80 -> V_78 ,
V_80 , V_55 , V_80 -> V_284 ,
V_195 ) ;
F_178 ( & V_80 -> V_261 . V_262 , 0 ) ;
return 0 ;
V_521:
V_7 -> V_520 [ V_78 ] = NULL ;
F_308 ( V_80 ) ;
F_186 ( V_274 ) ;
V_519:
F_309 ( V_80 ) ;
V_518:
F_310 ( V_80 ) ;
V_517:
V_516:
V_515:
V_514:
V_238:
V_512:
V_511:
V_500:
F_99 ( V_80 , V_522 ) ;
V_499:
F_121 ( V_80 ) ;
V_498:
F_52 ( V_80 -> V_261 . V_263 ) ;
V_493:
F_52 ( V_80 -> V_302 ) ;
V_492:
F_311 ( V_80 -> V_200 ) ;
V_491:
F_312 ( V_55 ) ;
V_490:
F_313 ( V_7 -> V_11 , V_78 ) ;
return V_10 ;
}
static void F_314 ( struct V_7 * V_7 , T_3 V_78 )
{
struct V_80 * V_80 = V_7 -> V_520 [ V_78 ] ;
F_315 ( & V_80 -> V_261 . V_262 ) ;
F_316 ( V_7 -> V_11 , V_78 , V_7 ) ;
F_317 ( V_80 -> V_55 ) ;
V_7 -> V_520 [ V_78 ] = NULL ;
F_308 ( V_80 ) ;
F_184 ( V_80 ) ;
F_309 ( V_80 ) ;
F_310 ( V_80 ) ;
F_99 ( V_80 , V_522 ) ;
F_121 ( V_80 ) ;
F_52 ( V_80 -> V_261 . V_263 ) ;
F_52 ( V_80 -> V_302 ) ;
F_311 ( V_80 -> V_200 ) ;
F_61 ( ! F_62 ( & V_80 -> V_277 ) ) ;
F_312 ( V_80 -> V_55 ) ;
F_313 ( V_7 -> V_11 , V_78 ) ;
}
static bool F_318 ( struct V_7 * V_7 , T_3 V_78 )
{
return V_7 -> V_520 [ V_78 ] != NULL ;
}
static void F_319 ( struct V_7 * V_7 )
{
int V_102 ;
for ( V_102 = 1 ; V_102 < F_320 ( V_7 -> V_11 ) ; V_102 ++ )
if ( F_318 ( V_7 , V_102 ) )
F_314 ( V_7 , V_102 ) ;
F_52 ( V_7 -> V_523 ) ;
F_52 ( V_7 -> V_520 ) ;
}
static int F_321 ( struct V_7 * V_7 )
{
unsigned int V_524 = F_320 ( V_7 -> V_11 ) ;
T_3 V_195 , V_196 , V_197 ;
T_8 V_525 ;
int V_102 ;
int V_10 ;
V_525 = sizeof( struct V_80 * ) * V_524 ;
V_7 -> V_520 = F_80 ( V_525 , V_95 ) ;
if ( ! V_7 -> V_520 )
return - V_96 ;
V_7 -> V_523 = F_58 ( V_524 , sizeof( T_3 ) , V_95 ) ;
if ( ! V_7 -> V_523 ) {
V_10 = - V_96 ;
goto V_526;
}
for ( V_102 = 1 ; V_102 < V_524 ; V_102 ++ ) {
V_10 = F_112 ( V_7 , V_102 , & V_195 ,
& V_196 , & V_197 ) ;
if ( V_10 )
goto V_527;
if ( ! V_196 )
continue;
V_7 -> V_523 [ V_102 ] = V_195 ;
V_10 = F_294 ( V_7 , V_102 , false ,
V_195 , V_196 , V_197 ) ;
if ( V_10 )
goto V_528;
}
return 0 ;
V_528:
V_527:
for ( V_102 -- ; V_102 >= 1 ; V_102 -- )
if ( F_318 ( V_7 , V_102 ) )
F_314 ( V_7 , V_102 ) ;
F_52 ( V_7 -> V_523 ) ;
V_526:
F_52 ( V_7 -> V_520 ) ;
return V_10 ;
}
static T_3 F_322 ( T_3 V_78 )
{
T_3 V_26 = ( V_78 - 1 ) % V_529 ;
return V_78 - V_26 ;
}
static int F_323 ( struct V_7 * V_7 , T_3 V_530 ,
T_3 V_195 , unsigned int V_531 )
{
T_3 V_196 = V_532 / V_531 ;
int V_10 , V_102 ;
for ( V_102 = 0 ; V_102 < V_531 ; V_102 ++ ) {
V_10 = F_294 ( V_7 , V_530 + V_102 , true ,
V_195 , V_196 , V_102 * V_196 ) ;
if ( V_10 )
goto V_528;
}
return 0 ;
V_528:
for ( V_102 -- ; V_102 >= 0 ; V_102 -- )
if ( F_318 ( V_7 , V_530 + V_102 ) )
F_314 ( V_7 , V_530 + V_102 ) ;
return V_10 ;
}
static void F_324 ( struct V_7 * V_7 ,
T_3 V_530 , unsigned int V_531 )
{
T_3 V_78 , V_195 , V_196 = V_532 ;
int V_102 ;
V_531 = V_531 / 2 ;
for ( V_102 = 0 ; V_102 < V_531 ; V_102 ++ ) {
V_78 = V_530 + V_102 * 2 ;
V_195 = V_7 -> V_523 [ V_78 ] ;
F_294 ( V_7 , V_78 , false , V_195 ,
V_196 , 0 ) ;
}
}
static int F_325 ( struct V_533 * V_533 , T_3 V_78 ,
unsigned int V_531 )
{
struct V_7 * V_7 = F_326 ( V_533 ) ;
struct V_80 * V_80 ;
T_3 V_195 , V_534 , V_530 ;
int V_102 ;
int V_10 ;
V_80 = V_7 -> V_520 [ V_78 ] ;
if ( ! V_80 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_38 ,
V_78 ) ;
return - V_165 ;
}
V_195 = V_80 -> V_283 . V_195 ;
V_534 = V_80 -> V_283 . V_196 ;
if ( V_531 != 2 && V_531 != 4 ) {
F_76 ( V_80 -> V_55 , L_39 ) ;
return - V_165 ;
}
if ( V_534 != V_532 ) {
F_76 ( V_80 -> V_55 , L_40 ) ;
return - V_165 ;
}
if ( V_531 == 2 ) {
V_530 = V_78 ;
if ( V_7 -> V_520 [ V_530 + 1 ] ) {
F_76 ( V_80 -> V_55 , L_41 ) ;
return - V_165 ;
}
} else {
V_530 = F_322 ( V_78 ) ;
if ( V_7 -> V_520 [ V_530 + 1 ] ||
V_7 -> V_520 [ V_530 + 3 ] ) {
F_76 ( V_80 -> V_55 , L_41 ) ;
return - V_165 ;
}
}
for ( V_102 = 0 ; V_102 < V_531 ; V_102 ++ )
if ( F_318 ( V_7 , V_530 + V_102 ) )
F_314 ( V_7 , V_530 + V_102 ) ;
V_10 = F_323 ( V_7 , V_530 , V_195 , V_531 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_42 ) ;
goto V_535;
}
return 0 ;
V_535:
F_324 ( V_7 , V_530 , V_531 ) ;
return V_10 ;
}
static int F_327 ( struct V_533 * V_533 , T_3 V_78 )
{
struct V_7 * V_7 = F_326 ( V_533 ) ;
struct V_80 * V_80 ;
T_3 V_534 , V_530 ;
unsigned int V_531 ;
int V_102 ;
V_80 = V_7 -> V_520 [ V_78 ] ;
if ( ! V_80 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_38 ,
V_78 ) ;
return - V_165 ;
}
if ( ! V_80 -> V_284 ) {
F_76 ( V_80 -> V_55 , L_43 ) ;
return - V_165 ;
}
V_534 = V_80 -> V_283 . V_196 ;
V_531 = V_534 == 1 ? 4 : 2 ;
V_530 = F_322 ( V_78 ) ;
if ( V_531 == 2 && V_78 >= V_530 + 2 )
V_530 = V_530 + 2 ;
for ( V_102 = 0 ; V_102 < V_531 ; V_102 ++ )
if ( F_318 ( V_7 , V_530 + V_102 ) )
F_314 ( V_7 , V_530 + V_102 ) ;
F_324 ( V_7 , V_530 , V_531 ) ;
return 0 ;
}
static void F_328 ( const struct V_536 * V_537 ,
char * V_538 , void * V_539 )
{
struct V_7 * V_7 = V_539 ;
struct V_80 * V_80 ;
enum V_540 V_441 ;
T_3 V_78 ;
V_78 = F_329 ( V_538 ) ;
V_80 = V_7 -> V_520 [ V_78 ] ;
if ( ! V_80 )
return;
V_441 = F_330 ( V_538 ) ;
if ( V_441 == V_541 ) {
F_331 ( V_80 -> V_55 , L_44 ) ;
F_332 ( V_80 -> V_55 ) ;
} else {
F_331 ( V_80 -> V_55 , L_45 ) ;
F_300 ( V_80 -> V_55 ) ;
}
}
static void F_333 ( struct V_69 * V_70 ,
T_3 V_78 , void * V_539 )
{
struct V_7 * V_7 = V_539 ;
struct V_80 * V_80 = V_7 -> V_520 [ V_78 ] ;
struct V_199 * V_200 ;
if ( F_129 ( ! V_80 ) ) {
F_334 ( V_7 -> V_44 -> V_55 , L_46 ,
V_78 ) ;
return;
}
V_70 -> V_55 = V_80 -> V_55 ;
V_200 = F_137 ( V_80 -> V_200 ) ;
F_138 ( & V_200 -> V_207 ) ;
V_200 -> V_241 ++ ;
V_200 -> V_242 += V_70 -> V_202 ;
F_139 ( & V_200 -> V_207 ) ;
V_70 -> V_310 = F_335 ( V_70 , V_70 -> V_55 ) ;
F_336 ( V_70 ) ;
}
static void F_337 ( struct V_69 * V_70 , T_3 V_78 ,
void * V_539 )
{
V_70 -> V_542 = 1 ;
return F_333 ( V_70 , V_78 , V_539 ) ;
}
static void F_338 ( struct V_69 * V_70 , T_3 V_78 ,
void * V_539 )
{
struct V_7 * V_7 = V_539 ;
struct V_80 * V_80 = V_7 -> V_520 [ V_78 ] ;
struct V_303 * V_303 ;
T_2 V_25 ;
if ( F_129 ( ! V_80 ) ) {
F_334 ( V_7 -> V_44 -> V_55 , L_47 ,
V_78 ) ;
goto V_253;
}
if ( F_129 ( ! V_80 -> V_302 ) ) {
F_334 ( V_7 -> V_44 -> V_55 , L_48 ,
V_78 ) ;
goto V_253;
}
V_25 = V_80 -> V_302 -> V_306 ?
V_80 -> V_302 -> V_307 : V_70 -> V_202 ;
F_339 () ;
V_303 = F_340 ( V_80 -> V_302 -> V_303 ) ;
if ( ! V_303 )
goto V_543;
F_341 ( V_303 , V_70 , V_25 ,
V_80 -> V_55 -> V_296 , 0 ,
V_80 -> V_302 -> V_144 ) ;
V_543:
F_342 () ;
V_253:
F_343 ( V_70 ) ;
}
static int F_344 ( struct V_533 * V_533 )
{
char V_544 [ V_545 ] ;
enum V_546 V_547 ;
int V_548 ;
bool V_549 ;
T_3 V_550 ;
T_2 V_144 ;
int V_102 , V_10 ;
if ( ! F_56 ( V_533 , V_551 ) )
return - V_104 ;
V_548 = F_57 ( V_533 , V_551 ) ;
V_547 = V_552 ;
for ( V_102 = 0 ; V_102 < V_548 ; V_102 ++ ) {
V_549 = false ;
switch ( V_102 ) {
case V_553 :
case V_554 :
case V_555 :
case V_556 :
V_144 = 128 ;
V_550 = 7 ;
break;
case V_557 :
case V_558 :
V_144 = 16 * 1024 ;
V_550 = 10 ;
break;
case V_559 :
case V_560 :
case V_561 :
case V_562 :
case V_563 :
case V_564 :
case V_565 :
V_144 = 1024 ;
V_550 = 7 ;
break;
case V_566 :
V_549 = true ;
V_144 = 4 * 1024 ;
V_550 = 4 ;
break;
default:
continue;
}
F_345 ( V_544 , V_102 , V_547 , V_549 , V_144 ,
V_550 ) ;
V_10 = F_12 ( V_533 , F_5 ( V_567 ) , V_544 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_346 ( struct V_533 * V_533 )
{
char V_568 [ V_569 ] ;
enum V_570 V_102 ;
int V_548 ;
int V_571 ;
T_3 V_572 , V_353 ;
T_1 V_573 ;
int V_10 ;
if ( ! F_56 ( V_533 , V_574 ) )
return - V_104 ;
V_571 = F_57 ( V_533 , V_574 ) ;
V_548 = F_57 ( V_533 , V_551 ) ;
for ( V_102 = 0 ; V_102 < V_571 ; V_102 ++ ) {
V_573 = V_102 ;
switch ( V_102 ) {
case V_553 :
case V_554 :
case V_555 :
case V_556 :
V_572 = 5 ;
V_353 = 5 ;
break;
case V_559 :
case V_561 :
V_572 = 4 ;
V_353 = 4 ;
break;
case V_557 :
case V_566 :
case V_558 :
V_572 = 3 ;
V_353 = 3 ;
break;
case V_560 :
case V_565 :
V_572 = 2 ;
V_353 = 2 ;
break;
case V_562 :
case V_563 :
case V_564 :
V_572 = 1 ;
V_353 = 1 ;
break;
case V_575 :
V_572 = V_576 ;
V_353 = V_577 ;
V_573 = V_578 ;
break;
default:
continue;
}
if ( V_548 <= V_573 &&
V_573 != V_578 )
return - V_104 ;
F_347 ( V_568 , V_102 , V_573 , V_572 , V_353 ) ;
V_10 = F_12 ( V_533 , F_5 ( V_579 ) , V_568 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_348 ( struct V_7 * V_7 )
{
int V_102 ;
int V_10 ;
V_10 = F_344 ( V_7 -> V_11 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_346 ( V_7 -> V_11 ) ;
if ( V_10 )
return V_10 ;
for ( V_102 = 0 ; V_102 < F_349 ( V_580 ) ; V_102 ++ ) {
V_10 = F_350 ( V_7 -> V_11 ,
& V_580 [ V_102 ] ,
V_7 ) ;
if ( V_10 )
goto V_581;
}
return 0 ;
V_581:
for ( V_102 -- ; V_102 >= 0 ; V_102 -- ) {
F_351 ( V_7 -> V_11 ,
& V_580 [ V_102 ] ,
V_7 ) ;
}
return V_10 ;
}
static void F_352 ( struct V_7 * V_7 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < F_349 ( V_580 ) ; V_102 ++ ) {
F_351 ( V_7 -> V_11 ,
& V_580 [ V_102 ] ,
V_7 ) ;
}
}
static int F_353 ( struct V_7 * V_7 )
{
char V_582 [ V_583 ] ;
int V_10 ;
F_354 ( V_582 , V_584 |
V_585 |
V_586 |
V_587 |
V_588 |
V_589 |
V_590 |
V_591 |
V_592 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_593 ) , V_582 ) ;
if ( V_10 )
return V_10 ;
if ( ! F_56 ( V_7 -> V_11 , V_594 ) ||
! F_56 ( V_7 -> V_11 , V_595 ) )
return - V_104 ;
V_7 -> V_596 = F_58 ( F_57 ( V_7 -> V_11 , V_594 ) ,
sizeof( struct V_597 ) ,
V_95 ) ;
if ( ! V_7 -> V_596 )
return - V_96 ;
return 0 ;
}
static void F_355 ( struct V_7 * V_7 )
{
F_52 ( V_7 -> V_596 ) ;
}
static int F_356 ( struct V_533 * V_533 )
{
char V_568 [ V_569 ] ;
F_347 ( V_568 , V_598 ,
V_578 ,
V_576 ,
V_577 ) ;
return F_12 ( V_533 , F_5 ( V_579 ) , V_568 ) ;
}
static int F_357 ( struct V_533 * V_533 ,
const struct V_599 * V_599 )
{
struct V_7 * V_7 = F_326 ( V_533 ) ;
int V_10 ;
V_7 -> V_11 = V_533 ;
V_7 -> V_44 = V_599 ;
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
V_10 = F_358 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_51 ) ;
return V_10 ;
}
V_10 = F_348 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_52 ) ;
goto V_600;
}
V_10 = F_359 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_53 ) ;
goto V_601;
}
V_10 = F_353 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_54 ) ;
goto V_602;
}
V_10 = F_360 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_55 ) ;
goto V_603;
}
V_10 = F_361 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_56 ) ;
goto V_604;
}
V_10 = F_55 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_57 ) ;
goto V_605;
}
V_10 = F_362 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_58 ) ;
goto V_606;
}
V_10 = F_363 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_59 ) ;
goto V_607;
}
V_10 = F_364 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_60 ) ;
goto V_608;
}
V_10 = F_321 ( V_7 ) ;
if ( V_10 ) {
F_27 ( V_7 -> V_44 -> V_55 , L_61 ) ;
goto V_609;
}
return 0 ;
V_609:
F_365 ( V_7 ) ;
V_608:
F_366 ( V_7 ) ;
V_607:
F_367 ( V_7 ) ;
V_606:
F_60 ( V_7 ) ;
V_605:
F_368 ( V_7 ) ;
V_604:
F_369 ( V_7 ) ;
V_603:
F_355 ( V_7 ) ;
V_602:
F_370 ( V_7 ) ;
V_601:
F_352 ( V_7 ) ;
V_600:
F_371 ( V_7 ) ;
return V_10 ;
}
static void F_372 ( struct V_533 * V_533 )
{
struct V_7 * V_7 = F_326 ( V_533 ) ;
F_319 ( V_7 ) ;
F_365 ( V_7 ) ;
F_366 ( V_7 ) ;
F_367 ( V_7 ) ;
F_60 ( V_7 ) ;
F_368 ( V_7 ) ;
F_369 ( V_7 ) ;
F_355 ( V_7 ) ;
F_370 ( V_7 ) ;
F_352 ( V_7 ) ;
F_371 ( V_7 ) ;
}
bool F_204 ( const struct V_198 * V_55 )
{
return V_55 -> V_494 == & V_495 ;
}
static int F_373 ( struct V_198 * V_610 , void * V_24 )
{
struct V_80 * * V_611 = V_24 ;
int V_612 = 0 ;
if ( F_204 ( V_610 ) ) {
* V_611 = F_123 ( V_610 ) ;
V_612 = 1 ;
}
return V_612 ;
}
struct V_80 * F_374 ( struct V_198 * V_55 )
{
struct V_80 * V_80 ;
if ( F_204 ( V_55 ) )
return F_123 ( V_55 ) ;
V_80 = NULL ;
F_375 ( V_55 , F_373 , & V_80 ) ;
return V_80 ;
}
struct V_7 * F_376 ( struct V_198 * V_55 )
{
struct V_80 * V_80 ;
V_80 = F_374 ( V_55 ) ;
return V_80 ? V_80 -> V_7 : NULL ;
}
struct V_80 * F_377 ( struct V_198 * V_55 )
{
struct V_80 * V_80 ;
if ( F_204 ( V_55 ) )
return F_123 ( V_55 ) ;
V_80 = NULL ;
F_378 ( V_55 , F_373 ,
& V_80 ) ;
return V_80 ;
}
struct V_80 * F_379 ( struct V_198 * V_55 )
{
struct V_80 * V_80 ;
F_339 () ;
V_80 = F_377 ( V_55 ) ;
if ( V_80 )
F_272 ( V_80 -> V_55 ) ;
F_342 () ;
return V_80 ;
}
void F_380 ( struct V_80 * V_80 )
{
F_275 ( V_80 -> V_55 ) ;
}
static int F_381 ( struct V_7 * V_7 , T_1 V_613 )
{
char V_614 [ V_615 ] ;
F_382 ( V_614 , V_613 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_616 ) , V_614 ) ;
}
static int F_383 ( struct V_7 * V_7 , T_1 V_613 )
{
char V_614 [ V_615 ] ;
F_384 ( V_614 , V_613 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_616 ) , V_614 ) ;
}
static int F_385 ( struct V_80 * V_80 ,
T_1 V_613 , T_3 V_617 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_618 [ V_619 ] ;
F_386 ( V_618 , V_80 -> V_78 ,
V_613 , V_617 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_620 ) , V_618 ) ;
}
static int F_387 ( struct V_80 * V_80 ,
T_1 V_613 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_618 [ V_619 ] ;
F_388 ( V_618 , V_80 -> V_78 ,
V_613 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_620 ) , V_618 ) ;
}
static int F_389 ( struct V_80 * V_80 ,
T_1 V_613 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_618 [ V_619 ] ;
F_390 ( V_618 , V_80 -> V_78 ,
V_613 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_620 ) , V_618 ) ;
}
static int F_391 ( struct V_80 * V_80 ,
T_1 V_613 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_618 [ V_619 ] ;
F_392 ( V_618 , V_80 -> V_78 ,
V_613 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_620 ) , V_618 ) ;
}
static int F_393 ( struct V_7 * V_7 ,
struct V_198 * V_621 ,
T_1 * V_622 )
{
struct V_597 * V_623 ;
int V_624 = - 1 ;
T_4 V_625 ;
int V_102 ;
V_625 = F_57 ( V_7 -> V_11 , V_594 ) ;
for ( V_102 = 0 ; V_102 < V_625 ; V_102 ++ ) {
V_623 = F_394 ( V_7 , V_102 ) ;
if ( V_623 -> V_119 ) {
if ( V_623 -> V_55 == V_621 ) {
* V_622 = V_102 ;
return 0 ;
}
} else if ( V_624 < 0 ) {
V_624 = V_102 ;
}
}
if ( V_624 < 0 )
return - V_20 ;
* V_622 = V_624 ;
return 0 ;
}
static bool
F_395 ( struct V_7 * V_7 ,
struct V_198 * V_621 ,
struct V_626 * V_627 )
{
T_1 V_613 ;
if ( F_393 ( V_7 , V_621 , & V_613 ) != 0 )
return false ;
if ( V_627 -> V_628 != V_629 )
return false ;
return true ;
}
static int F_396 ( struct V_7 * V_7 ,
T_1 V_613 , T_3 * V_630 )
{
T_4 V_631 ;
int V_102 ;
V_631 = F_57 ( V_7 -> V_11 ,
V_595 ) ;
for ( V_102 = 0 ; V_102 < V_631 ; V_102 ++ ) {
if ( ! F_397 ( V_7 , V_613 , V_102 ) ) {
* V_630 = V_102 ;
return 0 ;
}
}
return - V_20 ;
}
static int F_398 ( struct V_80 * V_80 ,
struct V_198 * V_621 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
struct V_274 * V_274 ;
struct V_597 * V_623 ;
T_1 V_613 ;
T_3 V_617 ;
int V_10 ;
V_10 = F_393 ( V_7 , V_621 , & V_613 ) ;
if ( V_10 )
return V_10 ;
V_623 = F_394 ( V_7 , V_613 ) ;
if ( ! V_623 -> V_119 ) {
V_10 = F_381 ( V_7 , V_613 ) ;
if ( V_10 )
return V_10 ;
V_623 -> V_55 = V_621 ;
}
V_10 = F_396 ( V_7 , V_613 , & V_617 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_385 ( V_80 , V_613 , V_617 ) ;
if ( V_10 )
goto V_632;
V_10 = F_389 ( V_80 , V_613 ) ;
if ( V_10 )
goto V_633;
F_399 ( V_7 -> V_11 , V_613 , V_617 ,
V_80 -> V_78 ) ;
V_80 -> V_613 = V_613 ;
V_80 -> V_634 = 1 ;
V_623 -> V_119 ++ ;
V_274 = F_192 ( V_80 , 1 ) ;
if ( V_274 -> V_279 )
F_194 ( V_274 ) ;
return 0 ;
V_633:
F_387 ( V_80 , V_613 ) ;
V_632:
if ( ! V_623 -> V_119 )
F_383 ( V_7 , V_613 ) ;
return V_10 ;
}
static void F_400 ( struct V_80 * V_80 ,
struct V_198 * V_621 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
T_1 V_613 = V_80 -> V_613 ;
struct V_597 * V_623 ;
if ( ! V_80 -> V_634 )
return;
V_623 = F_394 ( V_7 , V_613 ) ;
F_69 ( V_623 -> V_119 == 0 ) ;
F_391 ( V_80 , V_613 ) ;
F_387 ( V_80 , V_613 ) ;
F_184 ( V_80 ) ;
if ( V_623 -> V_119 == 1 )
F_383 ( V_7 , V_613 ) ;
F_401 ( V_7 -> V_11 , V_613 ,
V_80 -> V_78 ) ;
V_80 -> V_634 = 0 ;
V_623 -> V_119 -- ;
F_191 ( V_80 , 1 ) ;
F_109 ( V_80 , 1 ) ;
}
static int F_402 ( struct V_80 * V_80 ,
T_1 V_613 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_614 [ V_615 ] ;
F_403 ( V_614 , V_613 ,
V_80 -> V_78 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_616 ) , V_614 ) ;
}
static int F_404 ( struct V_80 * V_80 ,
T_1 V_613 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
char V_614 [ V_615 ] ;
F_405 ( V_614 , V_613 ,
V_80 -> V_78 ) ;
return F_12 ( V_7 -> V_11 , F_5 ( V_616 ) , V_614 ) ;
}
static int F_406 ( struct V_80 * V_80 ,
bool V_635 )
{
if ( V_635 )
return F_402 ( V_80 ,
V_80 -> V_613 ) ;
else
return F_404 ( V_80 ,
V_80 -> V_613 ) ;
}
static int F_407 ( struct V_80 * V_80 ,
struct V_636 * V_637 )
{
return F_406 ( V_80 , V_637 -> V_638 ) ;
}
static int F_408 ( struct V_80 * V_80 ,
bool V_143 )
{
struct V_7 * V_7 = V_80 -> V_7 ;
enum V_83 V_84 ;
char * V_85 ;
T_1 V_81 ;
int V_10 ;
V_84 = V_143 ? V_87 :
V_93 ;
V_85 = F_49 ( V_94 , V_95 ) ;
if ( ! V_85 )
return - V_96 ;
F_50 ( V_85 , V_80 -> V_78 ) ;
for ( V_81 = 0 ; V_81 < V_639 ; V_81 ++ )
F_51 ( V_85 , V_81 , V_84 ) ;
V_10 = F_12 ( V_7 -> V_11 , F_5 ( V_97 ) , V_85 ) ;
F_52 ( V_85 ) ;
return V_10 ;
}
static int F_409 ( struct V_80 * V_80 )
{
int V_10 ;
V_10 = F_101 ( V_80 , true ) ;
if ( V_10 )
return V_10 ;
V_10 = F_408 ( V_80 , true ) ;
if ( V_10 )
goto V_640;
V_10 = F_182 ( V_80 , 2 , V_639 - 1 ,
true , false ) ;
if ( V_10 )
goto V_641;
return 0 ;
V_641:
F_408 ( V_80 , false ) ;
V_640:
F_101 ( V_80 , false ) ;
return V_10 ;
}
static void F_410 ( struct V_80 * V_80 )
{
F_182 ( V_80 , 2 , V_639 - 1 ,
false , false ) ;
F_408 ( V_80 , false ) ;
F_101 ( V_80 , false ) ;
}
static int F_411 ( struct V_198 * V_610 ,
struct V_198 * V_55 ,
unsigned long V_642 , void * V_643 )
{
struct V_644 * V_637 ;
struct V_80 * V_80 ;
struct V_198 * V_645 ;
struct V_7 * V_7 ;
int V_10 = 0 ;
V_80 = F_123 ( V_55 ) ;
V_7 = V_80 -> V_7 ;
V_637 = V_643 ;
switch ( V_642 ) {
case V_646 :
V_645 = V_637 -> V_645 ;
if ( ! F_412 ( V_645 ) &&
! F_413 ( V_645 ) &&
! F_414 ( V_645 ) &&
! F_415 ( V_645 ) )
return - V_165 ;
if ( ! V_637 -> V_647 )
break;
if ( F_416 ( V_645 ) )
return - V_165 ;
if ( F_413 ( V_645 ) &&
! F_395 ( V_7 , V_645 ,
V_637 -> V_648 ) )
return - V_165 ;
if ( F_413 ( V_645 ) && F_417 ( V_55 ) )
return - V_165 ;
if ( F_418 ( V_55 ) && F_412 ( V_645 ) &&
! F_413 ( F_419 ( V_645 ) ) )
return - V_165 ;
if ( F_415 ( V_645 ) && F_417 ( V_55 ) )
return - V_165 ;
if ( F_420 ( V_55 ) && F_412 ( V_645 ) )
return - V_165 ;
break;
case V_649 :
V_645 = V_637 -> V_645 ;
if ( F_414 ( V_645 ) ) {
if ( V_637 -> V_647 )
V_10 = F_421 ( V_80 ,
V_610 ,
V_645 ) ;
else
F_422 ( V_80 ,
V_610 ,
V_645 ) ;
} else if ( F_413 ( V_645 ) ) {
if ( V_637 -> V_647 )
V_10 = F_398 ( V_80 ,
V_645 ) ;
else
F_400 ( V_80 ,
V_645 ) ;
} else if ( F_415 ( V_645 ) ) {
if ( V_637 -> V_647 )
V_10 = F_409 ( V_80 ) ;
else
F_410 ( V_80 ) ;
}
break;
}
return V_10 ;
}
static int F_423 ( struct V_198 * V_55 ,
unsigned long V_642 , void * V_643 )
{
struct V_650 * V_637 ;
struct V_80 * V_80 ;
int V_10 ;
V_80 = F_123 ( V_55 ) ;
V_637 = V_643 ;
switch ( V_642 ) {
case V_651 :
if ( F_418 ( V_55 ) && V_80 -> V_634 ) {
V_10 = F_407 ( V_80 ,
V_637 -> V_652 ) ;
if ( V_10 )
F_76 ( V_55 , L_62 ) ;
}
break;
}
return 0 ;
}
static int F_424 ( struct V_198 * V_610 ,
struct V_198 * V_653 ,
unsigned long V_642 , void * V_643 )
{
switch ( V_642 ) {
case V_646 :
case V_649 :
return F_411 ( V_610 , V_653 ,
V_642 , V_643 ) ;
case V_651 :
return F_423 ( V_653 , V_642 ,
V_643 ) ;
}
return 0 ;
}
static int F_425 ( struct V_198 * V_621 ,
unsigned long V_642 , void * V_643 )
{
struct V_198 * V_55 ;
struct V_654 * V_655 ;
int V_612 ;
F_426 (lag_dev, dev, iter) {
if ( F_204 ( V_55 ) ) {
V_612 = F_424 ( V_621 , V_55 , V_642 ,
V_643 ) ;
if ( V_612 )
return V_612 ;
}
}
return 0 ;
}
static int F_427 ( struct V_198 * V_656 ,
struct V_198 * V_55 ,
unsigned long V_642 , void * V_643 ,
T_1 V_81 )
{
struct V_80 * V_80 = F_123 ( V_55 ) ;
struct V_644 * V_637 = V_643 ;
struct V_198 * V_645 ;
int V_10 = 0 ;
switch ( V_642 ) {
case V_646 :
V_645 = V_637 -> V_645 ;
if ( ! F_414 ( V_645 ) )
return - V_165 ;
if ( ! V_637 -> V_647 )
break;
if ( F_416 ( V_645 ) )
return - V_165 ;
break;
case V_649 :
V_645 = V_637 -> V_645 ;
if ( F_414 ( V_645 ) ) {
if ( V_637 -> V_647 )
V_10 = F_421 ( V_80 ,
V_656 ,
V_645 ) ;
else
F_422 ( V_80 ,
V_656 ,
V_645 ) ;
} else {
V_10 = - V_165 ;
F_69 ( 1 ) ;
}
break;
}
return V_10 ;
}
static int F_428 ( struct V_198 * V_656 ,
struct V_198 * V_621 ,
unsigned long V_642 ,
void * V_643 , T_1 V_81 )
{
struct V_198 * V_55 ;
struct V_654 * V_655 ;
int V_612 ;
F_426 (lag_dev, dev, iter) {
if ( F_204 ( V_55 ) ) {
V_612 = F_427 ( V_656 , V_55 ,
V_642 , V_643 ,
V_81 ) ;
if ( V_612 )
return V_612 ;
}
}
return 0 ;
}
static int F_429 ( struct V_198 * V_656 ,
unsigned long V_642 , void * V_643 )
{
struct V_198 * V_657 = F_419 ( V_656 ) ;
T_1 V_81 = F_430 ( V_656 ) ;
if ( F_204 ( V_657 ) )
return F_427 ( V_656 , V_657 ,
V_642 , V_643 , V_81 ) ;
else if ( F_413 ( V_657 ) )
return F_428 ( V_656 ,
V_657 , V_642 ,
V_643 , V_81 ) ;
return 0 ;
}
static bool F_431 ( unsigned long V_642 , void * V_643 )
{
struct V_644 * V_637 = V_643 ;
if ( V_642 != V_646 && V_642 != V_649 )
return false ;
return F_432 ( V_637 -> V_645 ) ;
}
static int F_433 ( struct V_658 * V_659 ,
unsigned long V_642 , void * V_643 )
{
struct V_198 * V_55 = F_434 ( V_643 ) ;
int V_10 = 0 ;
if ( V_642 == V_660 || V_642 == V_661 )
V_10 = F_435 ( V_55 ) ;
else if ( F_431 ( V_642 , V_643 ) )
V_10 = F_436 ( V_55 , V_642 , V_643 ) ;
else if ( F_204 ( V_55 ) )
V_10 = F_424 ( V_55 , V_55 , V_642 , V_643 ) ;
else if ( F_413 ( V_55 ) )
V_10 = F_425 ( V_55 , V_642 , V_643 ) ;
else if ( F_412 ( V_55 ) )
V_10 = F_429 ( V_55 , V_642 , V_643 ) ;
return F_437 ( V_10 ) ;
}
static int T_9 F_438 ( void )
{
int V_10 ;
F_439 ( & V_662 ) ;
F_440 ( & V_663 ) ;
F_441 ( & V_664 ) ;
F_442 ( & V_665 ) ;
V_10 = F_443 ( & V_666 ) ;
if ( V_10 )
goto V_667;
V_10 = F_444 ( & V_668 ) ;
if ( V_10 )
goto V_669;
return 0 ;
V_669:
F_445 ( & V_666 ) ;
V_667:
F_446 ( & V_665 ) ;
F_447 ( & V_664 ) ;
F_448 ( & V_663 ) ;
F_449 ( & V_662 ) ;
return V_10 ;
}
static void T_10 F_450 ( void )
{
F_451 ( & V_668 ) ;
F_445 ( & V_666 ) ;
F_446 ( & V_665 ) ;
F_447 ( & V_664 ) ;
F_448 ( & V_663 ) ;
F_449 ( & V_662 ) ;
}
