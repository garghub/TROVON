static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 -> V_4 , V_5 , & V_3 ) ;
V_3 &= V_6 ;
return V_3 == V_7 || V_3 == V_8 ;
}
static int F_3 ( struct V_9 * V_10 ,
enum V_11 V_12 ,
union V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_15 -> V_16 ) ;
T_1 V_17 ;
switch ( V_12 ) {
case V_18 :
V_14 -> V_19 = F_1 ( V_2 ) ;
break;
case V_20 :
F_2 ( V_2 -> V_4 , V_21 , & V_17 ) ;
V_14 -> V_19 = V_22 *
( F_5 ( int , V_17 , V_23 ) + 1 ) ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
enum V_25 V_26 ;
T_1 V_3 ;
int V_27 ;
V_27 = F_2 ( V_2 -> V_4 , V_5 , & V_3 ) ;
if ( V_27 )
return V_27 ;
V_26 = ( V_3 & V_28 ) >> V_29 ;
switch ( V_26 ) {
case V_30 :
V_14 -> V_19 = V_31 ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
V_14 -> V_19 = V_36 ;
break;
case V_37 :
V_14 -> V_19 = V_38 ;
break;
default:
V_14 -> V_19 = V_39 ;
break;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
T_1 V_3 ;
int V_27 ;
V_27 = F_2 ( V_2 -> V_4 , V_5 , & V_3 ) ;
if ( V_27 )
return V_27 ;
if ( V_3 & V_40 )
V_14 -> V_19 = V_41 ;
else if ( V_3 & V_42 )
V_14 -> V_19 = V_43 ;
else
V_14 -> V_19 = V_44 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
T_1 V_3 ;
int V_27 ;
V_27 = F_2 ( V_2 -> V_4 , V_5 , & V_3 ) ;
if ( V_27 )
return V_27 ;
V_14 -> V_19 = ! ( V_3 & V_40 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int * V_45 )
{
struct V_46 * V_47 = V_2 -> V_48 [ V_49 ] ;
int V_50 ;
int V_51 ;
int V_27 ;
if ( ! V_47 )
return - V_24 ;
V_27 = F_10 ( V_47 , & V_50 , & V_51 ) ;
if ( V_27 != V_52 )
return - V_24 ;
* V_45 = ( V_50 + V_51 * 1000000 ) / 1000 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
return F_9 ( V_2 , & V_14 -> V_19 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
struct V_53 * V_4 = V_2 -> V_4 ;
struct V_54 * V_55 = V_2 -> V_55 ;
unsigned int V_56 ;
unsigned int V_57 ;
enum V_25 V_26 ;
T_1 V_3 ;
int V_27 ;
if ( ! V_55 )
return - V_24 ;
V_56 = V_55 -> V_58 ;
if ( V_56 == 0 )
return - V_24 ;
V_27 = F_2 ( V_4 , V_5 , & V_3 ) ;
if ( V_27 )
return V_27 ;
V_26 = ( V_3 & V_28 ) >> V_29 ;
if ( V_26 == V_37 ) {
V_14 -> V_19 = V_59 ;
} else {
V_27 = F_9 ( V_2 , & V_57 ) ;
if ( V_27 )
return V_27 ;
V_14 -> V_19 = ( V_57 * V_59 ) / V_56 ;
V_14 -> V_19 = F_13 ( V_14 -> V_19 , V_59 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
struct V_46 * V_47 = V_2 -> V_48 [ V_60 ] ;
int V_50 ;
int V_51 ;
int V_27 ;
if ( ! V_47 )
return - V_24 ;
V_27 = F_10 ( V_47 , & V_50 , & V_51 ) ;
if ( V_27 != V_52 )
return - V_24 ;
V_14 -> V_19 = ( V_50 + V_51 * 1000000 ) / 100 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
T_1 V_17 ;
F_2 ( V_2 -> V_4 , V_61 , & V_17 ) ;
V_17 &= V_62 ;
V_14 -> V_19 = V_22 *
( F_5 ( int , V_17 , V_23 ) + 1 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
T_1 V_17 ;
F_2 ( V_2 -> V_4 , V_63 , & V_17 ) ;
V_17 &= V_64 ;
V_14 -> V_19 = V_65 + V_66 * V_17 ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 ,
enum V_11 V_12 ,
union V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_15 -> V_16 ) ;
switch ( V_12 ) {
case V_67 :
return F_6 ( V_2 , V_14 ) ;
case V_68 :
return F_7 ( V_2 , V_14 ) ;
case V_69 :
return F_8 ( V_2 , V_14 ) ;
case V_70 :
return F_11 ( V_2 , V_14 ) ;
case V_71 :
return F_12 ( V_2 , V_14 ) ;
case V_72 :
return F_14 ( V_2 , V_14 ) ;
case V_73 :
return F_15 ( V_2 , V_14 ) ;
case V_74 :
return F_16 ( V_2 , V_14 ) ;
default:
return - V_24 ;
}
}
static inline bool F_18 ( T_1 V_75 )
{
return V_75 >= V_76 && V_75 <= V_77 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_53 * V_4 = V_2 -> V_4 ;
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_78 * V_79 ;
int V_80 ;
int V_27 ;
if ( ! V_55 || ! V_55 -> V_81 ) {
F_20 ( V_4 -> V_15 , L_1 ) ;
return 0 ;
}
for ( V_80 = 0 ; V_80 < V_55 -> V_82 ; V_80 ++ ) {
V_79 = V_55 -> V_81 + V_80 ;
if ( ! V_79 )
continue;
if ( F_18 ( V_79 -> V_75 ) ) {
V_27 = F_21 ( V_4 , V_79 -> V_75 , V_79 -> V_14 ) ;
if ( V_27 )
return V_27 ;
}
}
return 0 ;
}
static int F_22 ( struct V_83 * V_84 ,
struct V_1 * V_2 )
{
V_2 -> V_85 . V_86 = V_87 ;
V_2 -> V_85 . type = V_88 ;
V_2 -> V_85 . V_89 = V_90 ;
V_2 -> V_85 . V_91 = F_23 ( V_90 ) ;
V_2 -> V_85 . V_92 = F_3 ;
V_2 -> V_85 . V_93 = V_94 ;
V_2 -> V_85 . V_95 = F_23 ( V_94 ) ;
if ( F_24 ( & V_84 -> V_15 , & V_2 -> V_85 ) )
return - V_96 ;
V_2 -> V_97 . V_86 = V_98 ;
V_2 -> V_97 . type = V_99 ;
V_2 -> V_97 . V_89 = V_100 ;
V_2 -> V_97 . V_91 = F_23 ( V_100 ) ;
V_2 -> V_97 . V_92 = F_17 ;
if ( F_24 ( & V_84 -> V_15 , & V_2 -> V_97 ) )
return - V_96 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_97 ) ;
F_26 ( & V_2 -> V_85 ) ;
}
static void F_27 ( struct V_101 * V_102 )
{
struct V_1 * V_2 =
F_28 ( V_102 , struct V_1 , V_103 ) ;
struct V_54 * V_55 = V_2 -> V_55 ;
enum F_27 V_104 = F_1 ( V_2 ) ;
V_55 -> V_105 ( V_2 -> V_4 , V_104 ) ;
}
static bool F_29 ( struct V_1 * V_2 , int V_106 , int * V_107 )
{
bool V_108 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_2 -> V_109 ; V_80 ++ ) {
if ( V_2 -> V_110 [ V_80 ] . V_106 == V_106 ) {
* V_107 = V_2 -> V_110 [ V_80 ] . V_111 ;
V_108 = true ;
break;
}
}
return V_108 ;
}
static T_2 F_30 ( int V_106 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
struct V_54 * V_55 = V_2 -> V_55 ;
int V_107 = - 1 ;
if ( ! F_29 ( V_2 , V_106 , & V_107 ) )
return V_113 ;
switch ( V_107 ) {
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
F_31 ( & V_2 -> V_85 ) ;
F_31 ( & V_2 -> V_97 ) ;
break;
default:
break;
}
if ( ! V_55 )
goto V_119;
if ( V_55 -> V_105 && V_107 == V_114 )
F_32 ( & V_2 -> V_103 ) ;
V_119:
return V_120 ;
}
static int F_33 ( struct V_83 * V_84 ,
struct V_1 * V_2 , const char * V_86 )
{
struct V_121 * V_122 ;
struct V_123 * V_124 = V_2 -> V_4 -> V_124 ;
int V_125 ;
int V_126 ;
int V_106 ;
int V_127 ;
int V_80 ;
int V_27 ;
V_122 = F_34 ( V_84 , V_128 , V_86 ) ;
if ( ! V_122 )
return 0 ;
V_125 = V_122 -> V_129 ;
V_126 = V_122 -> V_130 ;
for ( V_80 = V_125 ; V_80 <= V_126 ; V_80 ++ ) {
V_127 = V_2 -> V_109 ;
V_106 = F_35 ( V_124 , V_80 ) ;
V_2 -> V_110 [ V_127 ] . V_106 = V_106 ;
V_2 -> V_110 [ V_127 ] . V_111 = V_80 ;
V_2 -> V_109 ++ ;
V_27 = F_36 ( V_106 , NULL ,
F_30 ,
0 , V_86 , V_2 ) ;
if ( V_27 )
break;
}
if ( V_80 <= V_126 )
goto V_131;
return 0 ;
V_131:
for ( V_80 = 0 ; V_80 < V_2 -> V_109 ; V_80 ++ )
F_37 ( V_2 -> V_110 [ V_80 ] . V_106 , V_2 ) ;
return V_27 ;
}
static int F_38 ( struct V_83 * V_84 ,
struct V_1 * V_2 )
{
struct V_53 * V_4 = V_2 -> V_4 ;
const char * V_86 [] = {
V_132 , V_133 , V_134
} ;
int V_80 ;
int V_27 ;
F_39 ( & V_2 -> V_103 , F_27 ) ;
V_2 -> V_109 = 0 ;
for ( V_80 = 0 ; V_80 < F_23 ( V_86 ) ; V_80 ++ ) {
V_27 = F_33 ( V_84 , V_2 , V_86 [ V_80 ] ) ;
if ( V_27 ) {
F_40 ( V_4 -> V_15 , L_2 , V_86 [ V_80 ] ) ;
return V_27 ;
}
}
if ( V_2 -> V_109 > V_135 ) {
F_41 ( V_4 -> V_15 , L_3 ,
V_2 -> V_109 ) ;
return - V_24 ;
}
return 0 ;
}
static void F_42 ( struct V_83 * V_84 ,
struct V_1 * V_2 )
{
int V_80 ;
int V_136 ;
for ( V_80 = 0 ; V_80 < V_2 -> V_109 ; V_80 ++ ) {
V_136 = V_2 -> V_110 [ V_80 ] . V_106 ;
if ( ! V_136 )
continue;
F_37 ( V_136 , V_2 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_137 * V_15 = V_2 -> V_4 -> V_15 ;
struct V_46 * V_48 ;
enum V_138 V_107 ;
const char * V_139 [ V_140 ] = {
[ V_141 ] = L_4 ,
[ V_142 ] = L_5 ,
[ V_143 ] = L_6 ,
[ V_144 ] = L_7 ,
[ V_145 ] = L_8 ,
[ V_146 ] = L_9 ,
[ V_147 ] = L_10 ,
} ;
if ( ! V_55 )
return;
V_107 = V_55 -> V_148 ;
switch ( V_107 ) {
case V_141 :
case V_142 :
case V_143 :
V_48 = F_44 ( NULL , V_139 [ V_107 ] ) ;
V_2 -> V_48 [ V_49 ] = F_45 ( V_48 ) ? NULL : V_48 ;
break;
default:
F_41 ( V_15 , L_11 , V_107 ) ;
V_2 -> V_48 [ V_49 ] = NULL ;
break;
}
V_107 = V_55 -> V_149 ;
switch ( V_107 ) {
case V_144 :
case V_145 :
case V_146 :
case V_147 :
V_48 = F_44 ( NULL , V_139 [ V_107 ] ) ;
V_2 -> V_48 [ V_60 ] = F_45 ( V_48 ) ? NULL : V_48 ;
break;
default:
F_41 ( V_15 , L_12 , V_107 ) ;
V_2 -> V_48 [ V_60 ] = NULL ;
break;
}
}
static void F_46 ( struct V_1 * V_2 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_150 ; V_80 ++ ) {
if ( ! V_2 -> V_48 [ V_80 ] )
continue;
F_47 ( V_2 -> V_48 [ V_80 ] ) ;
V_2 -> V_48 [ V_80 ] = NULL ;
}
}
static T_3 F_48 ( struct V_137 * V_15 ,
struct V_151 * V_152 , char * V_153 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
enum V_25 V_26 ;
char * V_154 [ V_155 ] = {
[ V_30 ] = L_13 ,
[ V_156 ] = L_14 ,
[ V_157 ] = L_15 ,
[ V_32 ] = L_16 ,
[ V_33 ] = L_17 ,
[ V_34 ] = L_18 ,
[ V_37 ] = L_19 ,
[ V_158 ] = L_20 ,
[ V_159 ] = L_21 ,
[ V_35 ] = L_22 ,
} ;
T_1 V_3 ;
F_2 ( V_2 -> V_4 , V_5 , & V_3 ) ;
V_26 = ( V_3 & V_28 ) >> V_29 ;
return F_49 ( V_153 , V_160 , L_23 , V_154 [ V_26 ] ) ;
}
static T_3 F_50 ( struct V_137 * V_15 ,
struct V_151 * V_152 , char * V_153 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
char * V_161 [] = { L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 L_31 } ;
T_1 V_14 ;
F_2 ( V_2 -> V_4 , V_162 , & V_14 ) ;
V_14 = ( V_14 & V_163 ) >> V_164 ;
return F_49 ( V_153 , V_160 , L_32 ,
V_161 [ V_14 ] ) ;
}
static T_3 F_51 ( struct V_137 * V_15 ,
struct V_151 * V_152 , char * V_153 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
char * V_165 [] = { L_33 , L_34 , L_35 , L_36 } ;
char * V_166 [] = { L_37 , L_38 , L_39 , L_40 } ;
char * V_167 ;
T_1 V_14 ;
T_1 V_168 ;
F_2 ( V_2 -> V_4 , V_162 , & V_14 ) ;
V_168 = V_14 & V_169 ;
V_14 = ( V_14 & V_170 ) >> V_171 ;
V_167 = V_168 ? V_165 [ V_14 ] : V_166 [ V_14 ] ;
return F_49 ( V_153 , V_160 , L_41 ,
V_167 ) ;
}
static T_4 int F_52 ( struct V_83 * V_84 )
{
struct V_53 * V_4 = F_4 ( V_84 -> V_15 . V_16 ) ;
struct V_1 * V_2 ;
int V_27 ;
V_2 = F_53 ( V_4 -> V_15 , sizeof( struct V_1 ) , V_172 ) ;
if ( ! V_2 )
return - V_173 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_55 = V_4 -> V_55 ? V_4 -> V_55 -> V_174 : NULL ;
F_54 ( V_84 , V_2 ) ;
V_27 = F_19 ( V_2 ) ;
if ( V_27 )
return V_27 ;
F_43 ( V_2 ) ;
V_27 = F_22 ( V_84 , V_2 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_55 ( & V_84 -> V_15 . V_175 , & V_176 ) ;
if ( V_27 ) {
F_25 ( V_2 ) ;
return V_27 ;
}
V_27 = F_38 ( V_84 , V_2 ) ;
if ( V_27 )
F_40 ( V_4 -> V_15 , L_42 , V_27 ) ;
return 0 ;
}
static int T_5 F_56 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_57 ( V_84 ) ;
F_58 ( & V_2 -> V_103 ) ;
F_42 ( V_84 , V_2 ) ;
F_59 ( & V_84 -> V_15 . V_175 , & V_176 ) ;
F_25 ( V_2 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
