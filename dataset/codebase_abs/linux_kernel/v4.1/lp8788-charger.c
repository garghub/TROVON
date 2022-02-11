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
struct V_1 * V_2 = F_4 ( V_10 -> V_15 . V_16 ) ;
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
static int F_9 ( struct V_1 * V_2 , int * V_45 )
{
struct V_46 * V_47 = V_2 -> V_48 [ V_49 ] ;
if ( ! V_47 )
return - V_24 ;
return F_10 ( V_47 , V_45 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
return F_9 ( V_2 , & V_14 -> V_19 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
struct V_50 * V_4 = V_2 -> V_4 ;
struct V_51 * V_52 = V_2 -> V_52 ;
unsigned int V_53 ;
int V_54 ;
enum V_25 V_26 ;
T_1 V_3 ;
int V_27 ;
if ( ! V_52 )
return - V_24 ;
V_53 = V_52 -> V_55 ;
if ( V_53 == 0 )
return - V_24 ;
V_27 = F_2 ( V_4 , V_5 , & V_3 ) ;
if ( V_27 )
return V_27 ;
V_26 = ( V_3 & V_28 ) >> V_29 ;
if ( V_26 == V_37 ) {
V_14 -> V_19 = V_56 ;
} else {
V_27 = F_9 ( V_2 , & V_54 ) ;
if ( V_27 )
return V_27 ;
V_14 -> V_19 = ( V_54 * V_56 ) / V_53 ;
V_14 -> V_19 = F_13 ( V_14 -> V_19 , V_56 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
struct V_46 * V_47 = V_2 -> V_48 [ V_57 ] ;
int V_45 ;
int V_27 ;
if ( ! V_47 )
return - V_24 ;
V_27 = F_10 ( V_47 , & V_45 ) ;
if ( V_27 < 0 )
return - V_24 ;
V_14 -> V_19 = V_45 * 10 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
T_1 V_17 ;
F_2 ( V_2 -> V_4 , V_58 , & V_17 ) ;
V_17 &= V_59 ;
V_14 -> V_19 = V_22 *
( F_5 ( int , V_17 , V_23 ) + 1 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
union V_13 * V_14 )
{
T_1 V_17 ;
F_2 ( V_2 -> V_4 , V_60 , & V_17 ) ;
V_17 &= V_61 ;
V_14 -> V_19 = V_62 + V_63 * V_17 ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 ,
enum V_11 V_12 ,
union V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_15 . V_16 ) ;
switch ( V_12 ) {
case V_64 :
return F_6 ( V_2 , V_14 ) ;
case V_65 :
return F_7 ( V_2 , V_14 ) ;
case V_66 :
return F_8 ( V_2 , V_14 ) ;
case V_67 :
return F_11 ( V_2 , V_14 ) ;
case V_68 :
return F_12 ( V_2 , V_14 ) ;
case V_69 :
return F_14 ( V_2 , V_14 ) ;
case V_70 :
return F_15 ( V_2 , V_14 ) ;
case V_71 :
return F_16 ( V_2 , V_14 ) ;
default:
return - V_24 ;
}
}
static inline bool F_18 ( T_1 V_72 )
{
return V_72 >= V_73 && V_72 <= V_74 ;
}
static int F_19 ( struct V_75 * V_76 ,
struct V_1 * V_2 )
{
struct V_50 * V_4 = V_2 -> V_4 ;
struct V_51 * V_52 = V_2 -> V_52 ;
struct V_77 * V_78 ;
int V_79 ;
int V_27 ;
if ( ! V_52 || ! V_52 -> V_80 ) {
F_20 ( & V_76 -> V_15 , L_1 ) ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_52 -> V_81 ; V_79 ++ ) {
V_78 = V_52 -> V_80 + V_79 ;
if ( ! V_78 )
continue;
if ( F_18 ( V_78 -> V_72 ) ) {
V_27 = F_21 ( V_4 , V_78 -> V_72 , V_78 -> V_14 ) ;
if ( V_27 )
return V_27 ;
}
}
return 0 ;
}
static int F_22 ( struct V_75 * V_76 ,
struct V_1 * V_2 )
{
struct V_82 V_83 = {} ;
V_83 . V_84 = V_85 ;
V_83 . V_86 = F_23 ( V_85 ) ;
V_2 -> V_87 = F_24 ( & V_76 -> V_15 ,
& V_88 ,
& V_83 ) ;
if ( F_25 ( V_2 -> V_87 ) )
return - V_89 ;
V_2 -> V_90 = F_24 ( & V_76 -> V_15 ,
& V_91 , NULL ) ;
if ( F_25 ( V_2 -> V_90 ) ) {
F_26 ( V_2 -> V_87 ) ;
return - V_89 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_90 ) ;
F_26 ( V_2 -> V_87 ) ;
}
static void F_28 ( struct V_92 * V_93 )
{
struct V_1 * V_2 =
F_29 ( V_93 , struct V_1 , V_94 ) ;
struct V_51 * V_52 = V_2 -> V_52 ;
enum F_28 V_95 = F_1 ( V_2 ) ;
V_52 -> V_96 ( V_2 -> V_4 , V_95 ) ;
}
static bool F_30 ( struct V_1 * V_2 , int V_97 , int * V_98 )
{
bool V_99 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_100 ; V_79 ++ ) {
if ( V_2 -> V_101 [ V_79 ] . V_97 == V_97 ) {
* V_98 = V_2 -> V_101 [ V_79 ] . V_102 ;
V_99 = true ;
break;
}
}
return V_99 ;
}
static T_2 F_31 ( int V_97 , void * V_103 )
{
struct V_1 * V_2 = V_103 ;
struct V_51 * V_52 = V_2 -> V_52 ;
int V_98 = - 1 ;
if ( ! F_30 ( V_2 , V_97 , & V_98 ) )
return V_104 ;
switch ( V_98 ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
F_32 ( V_2 -> V_87 ) ;
F_32 ( V_2 -> V_90 ) ;
break;
default:
break;
}
if ( ! V_52 )
goto V_110;
if ( V_52 -> V_96 && V_98 == V_105 )
F_33 ( & V_2 -> V_94 ) ;
V_110:
return V_111 ;
}
static int F_34 ( struct V_75 * V_76 ,
struct V_1 * V_2 , const char * V_112 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 = V_2 -> V_4 -> V_116 ;
int V_117 ;
int V_118 ;
int V_97 ;
int V_119 ;
int V_79 ;
int V_27 ;
V_114 = F_35 ( V_76 , V_120 , V_112 ) ;
if ( ! V_114 )
return 0 ;
V_117 = V_114 -> V_121 ;
V_118 = V_114 -> V_122 ;
for ( V_79 = V_117 ; V_79 <= V_118 ; V_79 ++ ) {
V_119 = V_2 -> V_100 ;
V_97 = F_36 ( V_116 , V_79 ) ;
V_2 -> V_101 [ V_119 ] . V_97 = V_97 ;
V_2 -> V_101 [ V_119 ] . V_102 = V_79 ;
V_2 -> V_100 ++ ;
V_27 = F_37 ( V_97 , NULL ,
F_31 ,
0 , V_112 , V_2 ) ;
if ( V_27 )
break;
}
if ( V_79 <= V_118 )
goto V_123;
return 0 ;
V_123:
for ( V_79 = 0 ; V_79 < V_2 -> V_100 ; V_79 ++ )
F_38 ( V_2 -> V_101 [ V_79 ] . V_97 , V_2 ) ;
return V_27 ;
}
static int F_39 ( struct V_75 * V_76 ,
struct V_1 * V_2 )
{
const char * V_112 [] = {
V_124 , V_125 , V_126
} ;
int V_79 ;
int V_27 ;
F_40 ( & V_2 -> V_94 , F_28 ) ;
V_2 -> V_100 = 0 ;
for ( V_79 = 0 ; V_79 < F_23 ( V_112 ) ; V_79 ++ ) {
V_27 = F_34 ( V_76 , V_2 , V_112 [ V_79 ] ) ;
if ( V_27 ) {
F_41 ( & V_76 -> V_15 , L_2 , V_112 [ V_79 ] ) ;
return V_27 ;
}
}
if ( V_2 -> V_100 > V_127 ) {
F_42 ( & V_76 -> V_15 , L_3 ,
V_2 -> V_100 ) ;
return - V_24 ;
}
return 0 ;
}
static void F_43 ( struct V_75 * V_76 ,
struct V_1 * V_2 )
{
int V_79 ;
int V_128 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_100 ; V_79 ++ ) {
V_128 = V_2 -> V_101 [ V_79 ] . V_97 ;
if ( ! V_128 )
continue;
F_38 ( V_128 , V_2 ) ;
}
}
static void F_44 ( struct V_129 * V_15 ,
struct V_1 * V_2 )
{
struct V_51 * V_52 = V_2 -> V_52 ;
struct V_46 * V_48 ;
if ( ! V_52 )
return;
V_48 = F_45 ( V_15 , V_52 -> V_130 ) ;
V_2 -> V_48 [ V_49 ] = F_25 ( V_48 ) ? NULL : V_48 ;
V_48 = F_45 ( V_15 , V_52 -> V_131 ) ;
V_2 -> V_48 [ V_57 ] = F_25 ( V_48 ) ? NULL : V_48 ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_132 ; V_79 ++ ) {
if ( ! V_2 -> V_48 [ V_79 ] )
continue;
F_47 ( V_2 -> V_48 [ V_79 ] ) ;
V_2 -> V_48 [ V_79 ] = NULL ;
}
}
static T_3 F_48 ( struct V_129 * V_15 ,
struct V_133 * V_134 , char * V_135 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
enum V_25 V_26 ;
char * V_136 [ V_137 ] = {
[ V_30 ] = L_4 ,
[ V_138 ] = L_5 ,
[ V_139 ] = L_6 ,
[ V_32 ] = L_7 ,
[ V_33 ] = L_8 ,
[ V_34 ] = L_9 ,
[ V_37 ] = L_10 ,
[ V_140 ] = L_11 ,
[ V_141 ] = L_12 ,
[ V_35 ] = L_13 ,
} ;
T_1 V_3 ;
F_2 ( V_2 -> V_4 , V_5 , & V_3 ) ;
V_26 = ( V_3 & V_28 ) >> V_29 ;
return F_49 ( V_135 , V_142 , L_14 , V_136 [ V_26 ] ) ;
}
static T_3 F_50 ( struct V_129 * V_15 ,
struct V_133 * V_134 , char * V_135 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
char * V_143 [] = { L_15 , L_16 , L_17 , L_18 ,
L_19 , L_20 , L_21 L_22 } ;
T_1 V_14 ;
F_2 ( V_2 -> V_4 , V_144 , & V_14 ) ;
V_14 = ( V_14 & V_145 ) >> V_146 ;
return F_49 ( V_135 , V_142 , L_23 ,
V_143 [ V_14 ] ) ;
}
static T_3 F_51 ( struct V_129 * V_15 ,
struct V_133 * V_134 , char * V_135 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
char * V_147 [] = { L_24 , L_25 , L_26 , L_27 } ;
char * V_148 [] = { L_28 , L_29 , L_30 , L_31 } ;
char * V_149 ;
T_1 V_14 ;
T_1 V_150 ;
F_2 ( V_2 -> V_4 , V_144 , & V_14 ) ;
V_150 = V_14 & V_151 ;
V_14 = ( V_14 & V_152 ) >> V_153 ;
V_149 = V_150 ? V_147 [ V_14 ] : V_148 [ V_14 ] ;
return F_49 ( V_135 , V_142 , L_32 , V_149 ) ;
}
static int F_52 ( struct V_75 * V_76 )
{
struct V_50 * V_4 = F_4 ( V_76 -> V_15 . V_16 ) ;
struct V_1 * V_2 ;
struct V_129 * V_15 = & V_76 -> V_15 ;
int V_27 ;
V_2 = F_53 ( V_15 , sizeof( struct V_1 ) , V_154 ) ;
if ( ! V_2 )
return - V_155 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_52 = V_4 -> V_52 ? V_4 -> V_52 -> V_156 : NULL ;
F_54 ( V_76 , V_2 ) ;
V_27 = F_19 ( V_76 , V_2 ) ;
if ( V_27 )
return V_27 ;
F_44 ( & V_76 -> V_15 , V_2 ) ;
V_27 = F_22 ( V_76 , V_2 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_55 ( & V_76 -> V_15 . V_157 , & V_158 ) ;
if ( V_27 ) {
F_27 ( V_2 ) ;
return V_27 ;
}
V_27 = F_39 ( V_76 , V_2 ) ;
if ( V_27 )
F_41 ( V_15 , L_33 , V_27 ) ;
return 0 ;
}
static int F_56 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_57 ( V_76 ) ;
F_58 ( & V_2 -> V_94 ) ;
F_43 ( V_76 , V_2 ) ;
F_59 ( & V_76 -> V_15 . V_157 , & V_158 ) ;
F_27 ( V_2 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
