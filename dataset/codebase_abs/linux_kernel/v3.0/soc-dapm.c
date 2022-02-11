static void F_1 ( T_1 V_1 )
{
if ( V_1 )
F_2 ( F_3 ( V_1 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_1 , const char * V_4 , ... )
{
T_2 args ;
char * V_5 ;
if ( ! V_1 )
return;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( V_5 == NULL )
return;
va_start ( args , V_4 ) ;
vsnprintf ( V_5 , V_6 , V_4 , args ) ;
F_6 ( V_3 , L_1 , V_5 ) ;
va_end ( args ) ;
F_7 ( V_5 ) ;
}
static inline struct V_8 * F_8 (
const struct V_8 * V_9 )
{
return F_9 ( V_9 , sizeof( * V_9 ) , V_7 ) ;
}
static int F_10 ( struct V_10 * V_11 ,
enum V_12 V_13 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
int V_16 = 0 ;
switch ( V_13 ) {
case V_17 :
F_11 ( V_11 -> V_3 , L_2 ) ;
break;
case V_18 :
F_11 ( V_11 -> V_3 , L_3 ) ;
break;
case V_19 :
F_11 ( V_11 -> V_3 , L_4 ) ;
break;
case V_20 :
F_11 ( V_11 -> V_3 , L_5 ) ;
break;
default:
F_12 ( V_11 -> V_3 , L_6 , V_13 ) ;
return - V_21 ;
}
F_13 ( V_15 , V_13 ) ;
if ( V_15 && V_15 -> V_22 )
V_16 = V_15 -> V_22 ( V_15 , V_13 ) ;
if ( V_16 == 0 ) {
if ( V_11 -> V_23 && V_11 -> V_23 -> V_24 -> V_22 )
V_16 = V_11 -> V_23 -> V_24 -> V_22 ( V_11 -> V_23 , V_13 ) ;
else
V_11 -> V_25 = V_13 ;
}
if ( V_16 == 0 ) {
if ( V_15 && V_15 -> V_26 )
V_16 = V_15 -> V_26 ( V_15 , V_13 ) ;
}
F_14 ( V_15 , V_13 ) ;
return V_16 ;
}
static void F_15 ( struct V_8 * V_27 ,
struct V_28 * V_29 , int V_30 )
{
switch ( V_27 -> V_31 ) {
case V_32 :
case V_33 :
case V_34 : {
int V_35 ;
struct V_36 * V_37 = (struct V_36 * )
V_27 -> V_38 [ V_30 ] . V_39 ;
unsigned int V_40 = V_37 -> V_40 ;
unsigned int V_41 = V_37 -> V_41 ;
int V_42 = V_37 -> V_42 ;
unsigned int V_43 = ( 1 << F_16 ( V_42 ) ) - 1 ;
unsigned int V_44 = V_37 -> V_44 ;
V_35 = F_17 ( V_27 -> V_23 , V_40 ) ;
V_35 = ( V_35 >> V_41 ) & V_43 ;
if ( ( V_44 && ! V_35 ) || ( ! V_44 && V_35 ) )
V_29 -> V_45 = 1 ;
else
V_29 -> V_45 = 0 ;
}
break;
case V_46 : {
struct V_47 * V_48 = (struct V_47 * )
V_27 -> V_38 [ V_30 ] . V_39 ;
int V_35 , V_49 , V_50 ;
for ( V_50 = 1 ; V_50 < V_48 -> V_42 ; V_50 <<= 1 )
;
V_35 = F_17 ( V_27 -> V_23 , V_48 -> V_40 ) ;
V_49 = ( V_35 >> V_48 -> V_51 ) & ( V_50 - 1 ) ;
V_29 -> V_45 = 0 ;
for ( V_30 = 0 ; V_30 < V_48 -> V_42 ; V_30 ++ ) {
if ( ! ( strcmp ( V_29 -> V_52 , V_48 -> V_53 [ V_30 ] ) ) && V_49 == V_30 )
V_29 -> V_45 = 1 ;
}
}
break;
case V_54 : {
struct V_47 * V_48 = (struct V_47 * )
V_27 -> V_38 [ V_30 ] . V_39 ;
V_29 -> V_45 = 0 ;
if ( ! strcmp ( V_29 -> V_52 , V_48 -> V_53 [ 0 ] ) )
V_29 -> V_45 = 1 ;
}
break;
case V_55 : {
struct V_47 * V_48 = (struct V_47 * )
V_27 -> V_38 [ V_30 ] . V_39 ;
int V_35 , V_49 ;
V_35 = F_17 ( V_27 -> V_23 , V_48 -> V_40 ) ;
V_35 = ( V_35 >> V_48 -> V_51 ) & V_48 -> V_43 ;
for ( V_49 = 0 ; V_49 < V_48 -> V_42 ; V_49 ++ ) {
if ( V_35 == V_48 -> V_56 [ V_49 ] )
break;
}
V_29 -> V_45 = 0 ;
for ( V_30 = 0 ; V_30 < V_48 -> V_42 ; V_30 ++ ) {
if ( ! ( strcmp ( V_29 -> V_52 , V_48 -> V_53 [ V_30 ] ) ) && V_49 == V_30 )
V_29 -> V_45 = 1 ;
}
}
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_29 -> V_45 = 1 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_29 -> V_45 = 0 ;
break;
}
}
static int F_18 ( struct V_10 * V_11 ,
struct V_8 * V_74 , struct V_8 * V_75 ,
struct V_28 * V_76 , const char * V_77 ,
const struct V_78 * V_79 )
{
struct V_47 * V_48 = (struct V_47 * ) V_79 -> V_39 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_48 -> V_42 ; V_30 ++ ) {
if ( ! ( strcmp ( V_77 , V_48 -> V_53 [ V_30 ] ) ) ) {
F_19 ( & V_76 -> V_80 , & V_11 -> V_15 -> V_81 ) ;
F_19 ( & V_76 -> V_82 , & V_75 -> V_83 ) ;
F_19 ( & V_76 -> V_84 , & V_74 -> V_85 ) ;
V_76 -> V_52 = ( char * ) V_48 -> V_53 [ V_30 ] ;
F_15 ( V_75 , V_76 , 0 ) ;
return 0 ;
}
}
return - V_86 ;
}
static int F_20 ( struct V_10 * V_11 ,
struct V_8 * V_74 , struct V_8 * V_75 ,
struct V_28 * V_76 , const char * V_77 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_75 -> V_87 ; V_30 ++ ) {
if ( ! strcmp ( V_77 , V_75 -> V_38 [ V_30 ] . V_52 ) ) {
F_19 ( & V_76 -> V_80 , & V_11 -> V_15 -> V_81 ) ;
F_19 ( & V_76 -> V_82 , & V_75 -> V_83 ) ;
F_19 ( & V_76 -> V_84 , & V_74 -> V_85 ) ;
V_76 -> V_52 = V_75 -> V_38 [ V_30 ] . V_52 ;
F_15 ( V_75 , V_76 , V_30 ) ;
return 0 ;
}
}
return - V_86 ;
}
static int F_21 ( struct V_10 * V_11 ,
struct V_8 * V_88 ,
const struct V_78 * V_89 ,
struct V_90 * * V_79 )
{
struct V_8 * V_27 ;
int V_30 ;
* V_79 = NULL ;
F_22 (w, &dapm->card->widgets, list) {
if ( V_27 == V_88 || V_27 -> V_11 != V_88 -> V_11 )
continue;
for ( V_30 = 0 ; V_30 < V_27 -> V_87 ; V_30 ++ ) {
if ( & V_27 -> V_38 [ V_30 ] == V_89 ) {
if ( V_27 -> V_91 )
* V_79 = V_27 -> V_91 [ V_30 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_23 ( struct V_8 * V_27 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
int V_30 , V_16 = 0 ;
T_3 V_92 , V_93 ;
struct V_28 * V_76 ;
struct V_94 * V_15 = V_11 -> V_15 -> V_94 ;
const char * V_95 ;
struct V_96 * V_97 ;
T_3 V_98 ;
if ( V_11 -> V_23 )
V_95 = V_11 -> V_23 -> V_99 ;
else
V_95 = NULL ;
if ( V_95 )
V_93 = strlen ( V_95 ) + 1 ;
else
V_93 = 0 ;
for ( V_30 = 0 ; V_30 < V_27 -> V_87 ; V_30 ++ ) {
F_22 (path, &w->sources, list_sink) {
if ( V_76 -> V_52 != ( char * ) V_27 -> V_38 [ V_30 ] . V_52 )
continue;
V_98 = sizeof( struct V_96 ) +
sizeof( struct V_8 * ) ,
V_97 = F_24 ( V_98 , V_7 ) ;
if ( V_97 == NULL ) {
F_12 ( V_11 -> V_3 ,
L_7 ,
V_27 -> V_52 ) ;
return - V_100 ;
}
V_97 -> V_101 = 1 ;
V_97 -> V_102 [ 0 ] = V_27 ;
V_92 = strlen ( V_27 -> V_38 [ V_30 ] . V_52 ) + 1 ;
if ( V_27 -> V_31 != V_34 )
V_92 += 1 + strlen ( V_27 -> V_52 ) ;
V_76 -> V_103 = F_5 ( V_92 , V_7 ) ;
if ( V_76 -> V_103 == NULL ) {
F_7 ( V_97 ) ;
return - V_100 ;
}
switch ( V_27 -> V_31 ) {
default:
snprintf ( V_76 -> V_103 , V_92 , L_8 ,
V_27 -> V_52 + V_93 ,
V_27 -> V_38 [ V_30 ] . V_52 ) ;
break;
case V_34 :
snprintf ( V_76 -> V_103 , V_92 , L_1 ,
V_27 -> V_38 [ V_30 ] . V_52 ) ;
break;
}
V_76 -> V_103 [ V_92 - 1 ] = '\0' ;
V_76 -> V_79 = F_25 ( & V_27 -> V_38 [ V_30 ] ,
V_97 , V_76 -> V_103 ,
V_95 ) ;
V_16 = F_26 ( V_15 , V_76 -> V_79 ) ;
if ( V_16 < 0 ) {
F_12 ( V_11 -> V_3 ,
L_9 ,
V_76 -> V_103 , V_16 ) ;
F_7 ( V_97 ) ;
F_7 ( V_76 -> V_103 ) ;
V_76 -> V_103 = NULL ;
return V_16 ;
}
V_27 -> V_91 [ V_30 ] = V_76 -> V_79 ;
}
}
return V_16 ;
}
static int F_27 ( struct V_8 * V_27 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
struct V_28 * V_76 = NULL ;
struct V_90 * V_79 ;
struct V_94 * V_15 = V_11 -> V_15 -> V_94 ;
const char * V_95 ;
T_3 V_93 ;
int V_16 ;
struct V_96 * V_97 ;
int V_104 , V_105 ;
T_3 V_98 ;
char * V_52 ;
if ( V_27 -> V_87 != 1 ) {
F_12 ( V_11 -> V_3 ,
L_10 ,
V_27 -> V_52 ) ;
return - V_21 ;
}
V_104 = F_21 ( V_11 , V_27 , & V_27 -> V_38 [ 0 ] ,
& V_79 ) ;
if ( V_79 ) {
V_97 = V_79 -> V_106 ;
V_105 = V_97 -> V_101 + 1 ;
} else {
V_97 = NULL ;
V_105 = 1 ;
}
V_98 = sizeof( struct V_96 ) +
V_105 * sizeof( struct V_8 * ) ,
V_97 = F_28 ( V_97 , V_98 , V_7 ) ;
if ( V_97 == NULL ) {
F_12 ( V_11 -> V_3 ,
L_7 , V_27 -> V_52 ) ;
return - V_100 ;
}
V_97 -> V_101 = V_105 ;
V_97 -> V_102 [ V_105 - 1 ] = V_27 ;
if ( ! V_79 ) {
if ( V_11 -> V_23 )
V_95 = V_11 -> V_23 -> V_99 ;
else
V_95 = NULL ;
if ( V_104 ) {
V_52 = V_27 -> V_38 [ 0 ] . V_52 ;
V_93 = 0 ;
} else {
V_52 = V_27 -> V_52 ;
if ( V_95 )
V_93 = strlen ( V_95 ) + 1 ;
else
V_93 = 0 ;
}
V_79 = F_25 ( & V_27 -> V_38 [ 0 ] , V_97 ,
V_52 + V_93 , V_95 ) ;
V_16 = F_26 ( V_15 , V_79 ) ;
if ( V_16 < 0 ) {
F_12 ( V_11 -> V_3 ,
L_11 , V_27 -> V_52 ) ;
F_7 ( V_97 ) ;
return V_16 ;
}
}
V_79 -> V_106 = V_97 ;
V_27 -> V_91 [ 0 ] = V_79 ;
F_22 (path, &w->sources, list_sink)
V_76 -> V_79 = V_79 ;
return 0 ;
}
static int F_29 ( struct V_8 * V_27 )
{
if ( V_27 -> V_87 )
F_12 ( V_27 -> V_11 -> V_3 ,
L_12 , V_27 -> V_52 ) ;
return 0 ;
}
static inline void F_30 ( struct V_10 * V_11 )
{
struct V_28 * V_29 ;
F_22 (p, &dapm->card->paths, list)
V_29 -> V_107 = 0 ;
}
static int F_31 ( struct V_8 * V_108 )
{
int V_13 = F_32 ( V_108 -> V_11 -> V_15 -> V_94 ) ;
switch ( V_13 ) {
case V_109 :
case V_110 :
if ( V_108 -> V_111 )
F_11 ( V_108 -> V_11 -> V_3 , L_13 ,
V_108 -> V_52 ) ;
return V_108 -> V_111 ;
default:
return 1 ;
}
}
static int F_33 ( struct V_8 * V_108 )
{
struct V_28 * V_76 ;
int V_112 = 0 ;
if ( V_108 -> V_31 == V_65 )
return 0 ;
switch ( V_108 -> V_31 ) {
case V_60 :
case V_67 :
if ( V_108 -> V_113 )
return F_31 ( V_108 ) ;
default:
break;
}
if ( V_108 -> V_114 ) {
if ( V_108 -> V_31 == V_59 && ! V_108 -> V_115 )
return F_31 ( V_108 ) ;
if ( V_108 -> V_31 == V_68 || V_108 -> V_31 == V_70 ||
( V_108 -> V_31 == V_71 && ! F_34 ( & V_108 -> V_83 ) ) )
return F_31 ( V_108 ) ;
}
F_22 (path, &widget->sinks, list_source) {
if ( V_76 -> V_107 )
continue;
if ( V_76 -> V_116 && V_76 -> V_45 ) {
V_76 -> V_107 = 1 ;
V_112 += F_33 ( V_76 -> V_116 ) ;
}
}
return V_112 ;
}
static int F_35 ( struct V_8 * V_108 )
{
struct V_28 * V_76 ;
int V_112 = 0 ;
if ( V_108 -> V_31 == V_65 )
return 0 ;
switch ( V_108 -> V_31 ) {
case V_62 :
case V_66 :
if ( V_108 -> V_113 )
return F_31 ( V_108 ) ;
default:
break;
}
if ( V_108 -> V_114 ) {
if ( V_108 -> V_31 == V_61 && ! V_108 -> V_115 )
return F_31 ( V_108 ) ;
if ( V_108 -> V_31 == V_64 )
return F_31 ( V_108 ) ;
if ( V_108 -> V_31 == V_69 ||
( V_108 -> V_31 == V_71 && ! F_34 ( & V_108 -> V_85 ) ) )
return F_31 ( V_108 ) ;
}
F_22 (path, &widget->sources, list_sink) {
if ( V_76 -> V_107 )
continue;
if ( V_76 -> V_117 && V_76 -> V_45 ) {
V_76 -> V_107 = 1 ;
V_112 += F_35 ( V_76 -> V_117 ) ;
}
}
return V_112 ;
}
int F_36 ( struct V_8 * V_27 ,
struct V_90 * V_79 , int V_118 )
{
unsigned int V_35 ;
if ( F_37 ( V_118 ) )
V_35 = V_27 -> V_119 ;
else
V_35 = V_27 -> V_120 ;
F_38 ( V_27 -> V_23 , - ( V_27 -> V_40 + 1 ) ,
V_27 -> V_43 << V_27 -> V_41 , V_35 << V_27 -> V_41 ) ;
return 0 ;
}
static int F_39 ( struct V_8 * V_27 )
{
int V_121 , V_122 ;
V_121 = F_35 ( V_27 ) ;
F_30 ( V_27 -> V_11 ) ;
V_122 = F_33 ( V_27 ) ;
F_30 ( V_27 -> V_11 ) ;
return V_122 != 0 && V_121 != 0 ;
}
static int F_40 ( struct V_8 * V_27 )
{
int V_121 ;
if ( V_27 -> V_113 ) {
V_121 = F_35 ( V_27 ) ;
F_30 ( V_27 -> V_11 ) ;
return V_121 != 0 ;
} else {
return F_39 ( V_27 ) ;
}
}
static int F_41 ( struct V_8 * V_27 )
{
int V_122 ;
if ( V_27 -> V_113 ) {
V_122 = F_33 ( V_27 ) ;
F_30 ( V_27 -> V_11 ) ;
return V_122 != 0 ;
} else {
return F_39 ( V_27 ) ;
}
}
static int F_42 ( struct V_8 * V_27 )
{
struct V_28 * V_76 ;
int V_123 = 0 ;
F_22 (path, &w->sinks, list_source) {
if ( V_76 -> V_114 &&
! V_76 -> V_114 ( V_76 -> V_117 , V_76 -> V_116 ) )
continue;
if ( ! V_76 -> V_116 )
continue;
if ( V_76 -> V_116 -> V_124 ) {
V_123 = 1 ;
break;
}
if ( V_76 -> V_116 -> V_125 &&
V_76 -> V_116 -> V_125 ( V_76 -> V_116 ) ) {
V_123 = 1 ;
break;
}
}
F_30 ( V_27 -> V_11 ) ;
return V_123 ;
}
static int F_43 ( struct V_8 * V_126 ,
struct V_8 * V_127 ,
bool V_128 )
{
int * V_129 ;
if ( V_128 )
V_129 = V_130 ;
else
V_129 = V_131 ;
if ( V_129 [ V_126 -> V_31 ] != V_129 [ V_127 -> V_31 ] )
return V_129 [ V_126 -> V_31 ] - V_129 [ V_127 -> V_31 ] ;
if ( V_126 -> V_132 != V_127 -> V_132 ) {
if ( V_128 )
return V_126 -> V_132 - V_127 -> V_132 ;
else
return V_127 -> V_132 - V_126 -> V_132 ;
}
if ( V_126 -> V_40 != V_127 -> V_40 )
return V_126 -> V_40 - V_127 -> V_40 ;
if ( V_126 -> V_11 != V_127 -> V_11 )
return ( unsigned long ) V_126 -> V_11 - ( unsigned long ) V_127 -> V_11 ;
return 0 ;
}
static void F_44 ( struct V_8 * V_133 ,
struct V_134 * V_80 ,
bool V_128 )
{
struct V_8 * V_27 ;
F_22 (w, list, power_list)
if ( F_43 ( V_133 , V_27 , V_128 ) < 0 ) {
F_45 ( & V_133 -> V_135 , & V_27 -> V_135 ) ;
return;
}
F_45 ( & V_133 -> V_135 , V_80 ) ;
}
static void F_46 ( struct V_10 * V_11 ,
struct V_8 * V_27 , int V_118 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
const char * V_136 ;
int V_123 , V_16 ;
switch ( V_118 ) {
case V_137 :
V_136 = L_14 ;
V_123 = 1 ;
break;
case V_138 :
V_136 = L_15 ;
V_123 = 1 ;
break;
case V_139 :
V_136 = L_16 ;
V_123 = 0 ;
break;
case V_140 :
V_136 = L_17 ;
V_123 = 0 ;
break;
default:
F_47 () ;
return;
}
if ( V_27 -> V_123 != V_123 )
return;
if ( V_27 -> V_118 && ( V_27 -> V_141 & V_118 ) ) {
F_4 ( V_11 -> V_3 , V_15 -> V_1 , L_18 ,
V_27 -> V_52 , V_136 ) ;
F_48 ( V_27 , V_118 ) ;
V_16 = V_27 -> V_118 ( V_27 , NULL , V_118 ) ;
F_49 ( V_27 , V_118 ) ;
if ( V_16 < 0 )
F_50 ( L_19 ,
V_136 , V_27 -> V_52 , V_16 ) ;
}
}
static void F_51 ( struct V_10 * V_11 ,
struct V_134 * V_142 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
struct V_8 * V_27 ;
int V_40 , V_123 ;
unsigned int V_143 = 0 ;
unsigned int V_43 = 0 ;
unsigned int V_144 ;
V_40 = F_52 ( V_142 , struct V_8 ,
V_135 ) -> V_40 ;
F_22 (w, pending, power_list) {
V_144 = 1 << V_27 -> V_41 ;
F_53 ( V_40 != V_27 -> V_40 ) ;
if ( V_27 -> V_44 )
V_123 = ! V_27 -> V_123 ;
else
V_123 = V_27 -> V_123 ;
V_43 |= V_144 ;
if ( V_123 )
V_143 |= V_144 ;
F_4 ( V_11 -> V_3 , V_15 -> V_1 ,
L_20 ,
V_27 -> V_52 , V_40 , V_143 , V_43 ) ;
F_46 ( V_11 , V_27 , V_137 ) ;
F_46 ( V_11 , V_27 , V_139 ) ;
}
if ( V_40 >= 0 ) {
F_4 ( V_11 -> V_3 , V_15 -> V_1 ,
L_21 ,
V_143 , V_43 , V_40 , V_15 -> V_1 ) ;
F_1 ( V_15 -> V_1 ) ;
F_38 ( V_11 -> V_23 , V_40 , V_43 , V_143 ) ;
}
F_22 (w, pending, power_list) {
F_46 ( V_11 , V_27 , V_138 ) ;
F_46 ( V_11 , V_27 , V_140 ) ;
}
}
static void F_54 ( struct V_10 * V_11 ,
struct V_134 * V_80 , int V_118 , bool V_128 )
{
struct V_8 * V_27 , * V_145 ;
F_55 ( V_142 ) ;
int V_146 = - 1 ;
int V_147 = - 1 ;
int V_148 = V_149 ;
struct V_10 * V_150 = NULL ;
int V_16 , V_30 ;
int * V_129 ;
if ( V_128 )
V_129 = V_130 ;
else
V_129 = V_131 ;
F_56 (w, n, list, power_list) {
V_16 = 0 ;
if ( V_129 [ V_27 -> V_31 ] != V_146 || V_27 -> V_40 != V_148 ||
V_27 -> V_11 != V_150 || V_27 -> V_132 != V_147 ) {
if ( ! F_34 ( & V_142 ) )
F_51 ( V_150 , & V_142 ) ;
if ( V_150 && V_150 -> V_151 ) {
for ( V_30 = 0 ; V_30 < F_57 ( V_130 ) ; V_30 ++ )
if ( V_129 [ V_30 ] == V_146 )
V_150 -> V_151 ( V_150 ,
V_30 ,
V_147 ) ;
}
F_58 ( & V_142 ) ;
V_146 = - 1 ;
V_147 = - 1 ;
V_148 = V_149 ;
V_150 = NULL ;
}
switch ( V_27 -> V_31 ) {
case V_72 :
if ( ! V_27 -> V_118 )
F_59 ( V_27 , V_145 , V_80 ,
V_135 ) ;
if ( V_118 == V_152 )
V_16 = V_27 -> V_118 ( V_27 ,
NULL , V_137 ) ;
else if ( V_118 == V_153 )
V_16 = V_27 -> V_118 ( V_27 ,
NULL , V_139 ) ;
break;
case V_73 :
if ( ! V_27 -> V_118 )
F_59 ( V_27 , V_145 , V_80 ,
V_135 ) ;
if ( V_118 == V_152 )
V_16 = V_27 -> V_118 ( V_27 ,
NULL , V_138 ) ;
else if ( V_118 == V_153 )
V_16 = V_27 -> V_118 ( V_27 ,
NULL , V_140 ) ;
break;
default:
V_146 = V_129 [ V_27 -> V_31 ] ;
V_147 = V_27 -> V_132 ;
V_148 = V_27 -> V_40 ;
V_150 = V_27 -> V_11 ;
F_60 ( & V_27 -> V_135 , & V_142 ) ;
break;
}
if ( V_16 < 0 )
F_12 ( V_27 -> V_11 -> V_3 ,
L_22 , V_16 ) ;
}
if ( ! F_34 ( & V_142 ) )
F_51 ( V_150 , & V_142 ) ;
if ( V_150 && V_150 -> V_151 ) {
for ( V_30 = 0 ; V_30 < F_57 ( V_130 ) ; V_30 ++ )
if ( V_129 [ V_30 ] == V_146 )
V_150 -> V_151 ( V_150 ,
V_30 , V_147 ) ;
}
}
static void F_61 ( struct V_10 * V_11 )
{
struct V_154 * V_155 = V_11 -> V_155 ;
struct V_8 * V_27 ;
int V_16 ;
if ( ! V_155 )
return;
V_27 = V_155 -> V_108 ;
if ( V_27 -> V_118 &&
( V_27 -> V_141 & V_156 ) ) {
V_16 = V_27 -> V_118 ( V_27 , V_155 -> V_79 , V_156 ) ;
if ( V_16 != 0 )
F_50 ( L_23 ,
V_27 -> V_52 , V_16 ) ;
}
V_16 = F_38 ( V_27 -> V_23 , V_155 -> V_40 , V_155 -> V_43 ,
V_155 -> V_35 ) ;
if ( V_16 < 0 )
F_50 ( L_24 , V_27 -> V_52 , V_16 ) ;
if ( V_27 -> V_118 &&
( V_27 -> V_141 & V_157 ) ) {
V_16 = V_27 -> V_118 ( V_27 , V_155 -> V_79 , V_157 ) ;
if ( V_16 != 0 )
F_50 ( L_25 ,
V_27 -> V_52 , V_16 ) ;
}
}
static void F_62 ( void * V_158 , T_4 V_159 )
{
struct V_10 * V_160 = V_158 ;
int V_16 ;
if ( V_160 -> V_161 && V_160 -> V_25 == V_20 ) {
V_16 = F_10 ( V_160 , V_19 ) ;
if ( V_16 != 0 )
F_12 ( V_160 -> V_3 ,
L_26 , V_16 ) ;
}
if ( ( V_160 -> V_161 && V_160 -> V_25 == V_19 ) ||
( ! V_160 -> V_161 && V_160 -> V_25 == V_17 ) ) {
V_16 = F_10 ( V_160 , V_18 ) ;
if ( V_16 != 0 )
F_12 ( V_160 -> V_3 ,
L_27 , V_16 ) ;
}
}
static void F_63 ( void * V_158 , T_4 V_159 )
{
struct V_10 * V_160 = V_158 ;
int V_16 ;
if ( V_160 -> V_25 == V_18 && ! V_160 -> V_161 ) {
V_16 = F_10 ( V_160 , V_19 ) ;
if ( V_16 != 0 )
F_12 ( V_160 -> V_3 , L_28 ,
V_16 ) ;
}
if ( V_160 -> V_25 == V_19 && V_160 -> V_162 ) {
V_16 = F_10 ( V_160 , V_20 ) ;
if ( V_16 != 0 )
F_12 ( V_160 -> V_3 , L_29 , V_16 ) ;
}
if ( V_160 -> V_25 == V_18 && V_160 -> V_161 ) {
V_16 = F_10 ( V_160 , V_17 ) ;
if ( V_16 != 0 )
F_12 ( V_160 -> V_3 , L_30 ,
V_16 ) ;
}
}
static int F_64 ( struct V_10 * V_11 , int V_118 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
struct V_8 * V_27 ;
struct V_10 * V_160 ;
F_55 ( V_163 ) ;
F_55 ( V_164 ) ;
F_55 ( V_165 ) ;
int V_123 ;
F_65 ( V_15 ) ;
F_22 (d, &card->dapm_list, list)
if ( V_160 -> V_166 || V_160 -> V_23 == NULL )
V_160 -> V_161 = 0 ;
F_22 (w, &card->widgets, list) {
switch ( V_27 -> V_31 ) {
case V_72 :
F_44 ( V_27 , & V_164 , false ) ;
break;
case V_73 :
F_44 ( V_27 , & V_163 , true ) ;
break;
default:
if ( ! V_27 -> V_125 )
continue;
if ( ! V_27 -> V_124 )
V_123 = V_27 -> V_125 ( V_27 ) ;
else
V_123 = 1 ;
if ( V_123 )
V_27 -> V_11 -> V_161 = 1 ;
if ( V_27 -> V_123 == V_123 )
continue;
F_66 ( V_27 , V_123 ) ;
if ( V_123 )
F_44 ( V_27 , & V_163 , true ) ;
else
F_44 ( V_27 , & V_164 , false ) ;
V_27 -> V_123 = V_123 ;
break;
}
}
if ( ! V_11 -> V_166 ) {
switch ( V_118 ) {
case V_152 :
case V_167 :
V_11 -> V_161 = 1 ;
break;
case V_153 :
V_11 -> V_161 = ! ! V_11 -> V_23 -> V_113 ;
break;
case V_168 :
V_11 -> V_161 = 0 ;
break;
case V_169 :
switch ( V_11 -> V_25 ) {
case V_19 :
case V_20 :
V_11 -> V_161 = 0 ;
break;
default:
V_11 -> V_161 = 1 ;
break;
}
break;
default:
break;
}
}
V_123 = 0 ;
F_22 (d, &card->dapm_list, list)
if ( V_160 -> V_161 )
V_123 = 1 ;
F_22 (d, &card->dapm_list, list)
V_160 -> V_161 = V_123 ;
F_22 (d, &dapm->card->dapm_list, list)
F_67 ( F_62 , V_160 ,
& V_165 ) ;
F_68 ( & V_165 ) ;
F_54 ( V_11 , & V_164 , V_118 , false ) ;
F_61 ( V_11 ) ;
F_54 ( V_11 , & V_163 , V_118 , true ) ;
F_22 (d, &dapm->card->dapm_list, list)
F_67 ( F_63 , V_160 ,
& V_165 ) ;
F_68 ( & V_165 ) ;
F_4 ( V_11 -> V_3 , V_15 -> V_1 ,
L_31 , V_15 -> V_1 ) ;
F_1 ( V_15 -> V_1 ) ;
F_69 ( V_15 ) ;
return 0 ;
}
static int F_70 ( struct V_170 * V_170 , struct V_171 * V_171 )
{
V_171 -> V_106 = V_170 -> V_172 ;
return 0 ;
}
static T_5 F_71 ( struct V_171 * V_171 ,
char T_6 * V_173 ,
T_3 V_174 , T_7 * V_175 )
{
struct V_8 * V_27 = V_171 -> V_106 ;
char * V_5 ;
int V_121 , V_122 ;
T_5 V_16 ;
struct V_28 * V_29 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_100 ;
V_121 = F_35 ( V_27 ) ;
F_30 ( V_27 -> V_11 ) ;
V_122 = F_33 ( V_27 ) ;
F_30 ( V_27 -> V_11 ) ;
V_16 = snprintf ( V_5 , V_6 , L_32 ,
V_27 -> V_52 , V_27 -> V_123 ? L_33 : L_34 , V_121 , V_122 ) ;
if ( V_27 -> V_40 >= 0 )
V_16 += snprintf ( V_5 + V_16 , V_6 - V_16 ,
L_35 ,
V_27 -> V_40 , V_27 -> V_40 , V_27 -> V_41 ) ;
V_16 += snprintf ( V_5 + V_16 , V_6 - V_16 , L_36 ) ;
if ( V_27 -> V_176 )
V_16 += snprintf ( V_5 + V_16 , V_6 - V_16 , L_37 ,
V_27 -> V_176 ,
V_27 -> V_113 ? L_38 : L_39 ) ;
F_22 (p, &w->sources, list_sink) {
if ( V_29 -> V_114 && ! V_29 -> V_114 ( V_27 , V_29 -> V_116 ) )
continue;
if ( V_29 -> V_45 )
V_16 += snprintf ( V_5 + V_16 , V_6 - V_16 ,
L_40 ,
V_29 -> V_52 ? V_29 -> V_52 : L_41 ,
V_29 -> V_117 -> V_52 ) ;
}
F_22 (p, &w->sinks, list_source) {
if ( V_29 -> V_114 && ! V_29 -> V_114 ( V_27 , V_29 -> V_116 ) )
continue;
if ( V_29 -> V_45 )
V_16 += snprintf ( V_5 + V_16 , V_6 - V_16 ,
L_42 ,
V_29 -> V_52 ? V_29 -> V_52 : L_41 ,
V_29 -> V_116 -> V_52 ) ;
}
V_16 = F_72 ( V_173 , V_174 , V_175 , V_5 , V_16 ) ;
F_7 ( V_5 ) ;
return V_16 ;
}
static int F_73 ( struct V_170 * V_170 , struct V_171 * V_171 )
{
V_171 -> V_106 = V_170 -> V_172 ;
return 0 ;
}
static T_5 F_74 ( struct V_171 * V_171 , char T_6 * V_173 ,
T_3 V_174 , T_7 * V_175 )
{
struct V_10 * V_11 = V_171 -> V_106 ;
char * V_13 ;
switch ( V_11 -> V_25 ) {
case V_17 :
V_13 = L_43 ;
break;
case V_18 :
V_13 = L_44 ;
break;
case V_19 :
V_13 = L_45 ;
break;
case V_20 :
V_13 = L_46 ;
break;
default:
F_47 () ;
V_13 = L_47 ;
break;
}
return F_72 ( V_173 , V_174 , V_175 , V_13 ,
strlen ( V_13 ) ) ;
}
void F_75 ( struct V_10 * V_11 ,
struct V_177 * V_178 )
{
struct V_177 * V_160 ;
V_11 -> V_179 = F_76 ( L_48 , V_178 ) ;
if ( ! V_11 -> V_179 ) {
F_77 ( V_180
L_49 ) ;
return;
}
V_160 = F_78 ( L_50 , 0444 ,
V_11 -> V_179 , V_11 ,
& V_181 ) ;
if ( ! V_160 )
F_79 ( V_11 -> V_3 ,
L_51 ) ;
}
static void F_80 ( struct V_8 * V_27 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
struct V_177 * V_160 ;
if ( ! V_11 -> V_179 || ! V_27 -> V_52 )
return;
V_160 = F_78 ( V_27 -> V_52 , 0444 ,
V_11 -> V_179 , V_27 ,
& V_182 ) ;
if ( ! V_160 )
F_79 ( V_27 -> V_11 -> V_3 ,
L_52 ,
V_27 -> V_52 ) ;
}
static void F_81 ( struct V_10 * V_11 )
{
F_82 ( V_11 -> V_179 ) ;
}
void F_75 ( struct V_10 * V_11 ,
struct V_177 * V_178 )
{
}
static inline void F_80 ( struct V_8 * V_27 )
{
}
static inline void F_81 ( struct V_10 * V_11 )
{
}
static int F_83 ( struct V_8 * V_108 ,
struct V_90 * V_79 , int V_183 ,
int V_184 , struct V_47 * V_48 )
{
struct V_28 * V_76 ;
int V_185 = 0 ;
if ( V_108 -> V_31 != V_46 &&
V_108 -> V_31 != V_54 &&
V_108 -> V_31 != V_55 )
return - V_86 ;
if ( ! V_183 )
return 0 ;
F_22 (path, &widget->dapm->card->paths, list) {
if ( V_76 -> V_79 != V_79 )
continue;
if ( ! V_76 -> V_52 || ! V_48 -> V_53 [ V_184 ] )
continue;
V_185 = 1 ;
if ( ! ( strcmp ( V_76 -> V_52 , V_48 -> V_53 [ V_184 ] ) ) )
V_76 -> V_45 = 1 ;
else
V_76 -> V_45 = 0 ;
}
if ( V_185 )
F_64 ( V_108 -> V_11 , V_169 ) ;
return 0 ;
}
static int F_84 ( struct V_8 * V_108 ,
struct V_90 * V_79 , int V_45 )
{
struct V_28 * V_76 ;
int V_185 = 0 ;
if ( V_108 -> V_31 != V_33 &&
V_108 -> V_31 != V_34 &&
V_108 -> V_31 != V_32 )
return - V_86 ;
F_22 (path, &widget->dapm->card->paths, list) {
if ( V_76 -> V_79 != V_79 )
continue;
V_185 = 1 ;
V_76 -> V_45 = V_45 ;
break;
}
if ( V_185 )
F_64 ( V_108 -> V_11 , V_169 ) ;
return 0 ;
}
static T_5 F_85 ( struct V_2 * V_3 ,
struct V_186 * V_187 , char * V_5 )
{
struct V_188 * V_189 =
F_86 ( V_3 , struct V_188 , V_3 ) ;
struct V_190 * V_23 = V_189 -> V_23 ;
struct V_8 * V_27 ;
int V_174 = 0 ;
char * V_191 = L_53 ;
F_22 (w, &codec->card->widgets, list) {
if ( V_27 -> V_11 != & V_23 -> V_11 )
continue;
switch ( V_27 -> V_31 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_63 :
case V_62 :
case V_60 :
case V_57 :
case V_58 :
case V_33 :
case V_34 :
case V_65 :
if ( V_27 -> V_52 )
V_174 += sprintf ( V_5 + V_174 , L_54 ,
V_27 -> V_52 , V_27 -> V_123 ? L_33 : L_34 ) ;
break;
default:
break;
}
}
switch ( V_23 -> V_11 . V_25 ) {
case V_17 :
V_191 = L_33 ;
break;
case V_18 :
V_191 = L_55 ;
break;
case V_19 :
V_191 = L_56 ;
break;
case V_20 :
V_191 = L_34 ;
break;
}
V_174 += sprintf ( V_5 + V_174 , L_57 , V_191 ) ;
return V_174 ;
}
int F_87 ( struct V_2 * V_3 )
{
return F_88 ( V_3 , & V_192 ) ;
}
static void F_89 ( struct V_2 * V_3 )
{
F_90 ( V_3 , & V_192 ) ;
}
static void F_91 ( struct V_10 * V_11 )
{
struct V_8 * V_27 , * V_193 ;
struct V_28 * V_29 , * V_194 ;
F_56 (w, next_w, &dapm->card->widgets, list) {
if ( V_27 -> V_11 != V_11 )
continue;
F_92 ( & V_27 -> V_80 ) ;
F_56 (p, next_p, &w->sources, list_sink) {
F_92 ( & V_29 -> V_82 ) ;
F_92 ( & V_29 -> V_84 ) ;
F_92 ( & V_29 -> V_80 ) ;
F_7 ( V_29 -> V_103 ) ;
F_7 ( V_29 ) ;
}
F_56 (p, next_p, &w->sinks, list_source) {
F_92 ( & V_29 -> V_82 ) ;
F_92 ( & V_29 -> V_84 ) ;
F_92 ( & V_29 -> V_80 ) ;
F_7 ( V_29 -> V_103 ) ;
F_7 ( V_29 ) ;
}
F_7 ( V_27 -> V_91 ) ;
F_7 ( V_27 -> V_52 ) ;
F_7 ( V_27 ) ;
}
}
static struct V_8 * F_93 (
struct V_10 * V_11 , const char * V_195 ,
bool V_196 )
{
struct V_8 * V_27 ;
struct V_8 * V_197 = NULL ;
F_22 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_27 -> V_52 , V_195 ) ) {
if ( V_27 -> V_11 == V_11 )
return V_27 ;
else
V_197 = V_27 ;
}
}
if ( V_196 )
return V_197 ;
return NULL ;
}
static int F_94 ( struct V_10 * V_11 ,
const char * V_195 , int V_198 )
{
struct V_8 * V_27 = F_93 ( V_11 , V_195 , true ) ;
if ( ! V_27 ) {
F_12 ( V_11 -> V_3 , L_58 , V_195 ) ;
return - V_21 ;
}
V_27 -> V_114 = V_198 ;
if ( V_198 == 0 )
V_27 -> V_124 = 0 ;
return 0 ;
}
int F_95 ( struct V_10 * V_11 )
{
return F_64 ( V_11 , V_169 ) ;
}
static int F_96 ( struct V_10 * V_11 ,
const struct V_199 * V_200 )
{
struct V_28 * V_76 ;
struct V_8 * V_201 = NULL , * V_202 = NULL , * V_27 ;
struct V_8 * V_203 = NULL , * V_204 = NULL ;
const char * V_116 ;
const char * V_205 = V_200 -> V_205 ;
const char * V_117 ;
char V_206 [ 80 ] ;
char V_207 [ 80 ] ;
int V_16 = 0 ;
if ( V_11 -> V_23 && V_11 -> V_23 -> V_99 ) {
snprintf ( V_206 , sizeof( V_206 ) , L_8 ,
V_11 -> V_23 -> V_99 , V_200 -> V_116 ) ;
V_116 = V_206 ;
snprintf ( V_207 , sizeof( V_207 ) , L_8 ,
V_11 -> V_23 -> V_99 , V_200 -> V_117 ) ;
V_117 = V_207 ;
} else {
V_116 = V_200 -> V_116 ;
V_117 = V_200 -> V_117 ;
}
F_22 (w, &dapm->card->widgets, list) {
if ( ! V_202 && ! ( strcmp ( V_27 -> V_52 , V_116 ) ) ) {
V_204 = V_27 ;
if ( V_27 -> V_11 == V_11 )
V_202 = V_27 ;
continue;
}
if ( ! V_201 && ! ( strcmp ( V_27 -> V_52 , V_117 ) ) ) {
V_203 = V_27 ;
if ( V_27 -> V_11 == V_11 )
V_201 = V_27 ;
}
}
if ( ! V_202 )
V_202 = V_204 ;
if ( ! V_201 )
V_201 = V_203 ;
if ( V_201 == NULL || V_202 == NULL )
return - V_86 ;
V_76 = F_24 ( sizeof( struct V_28 ) , V_7 ) ;
if ( ! V_76 )
return - V_100 ;
V_76 -> V_117 = V_201 ;
V_76 -> V_116 = V_202 ;
V_76 -> V_114 = V_200 -> V_114 ;
F_58 ( & V_76 -> V_80 ) ;
F_58 ( & V_76 -> V_84 ) ;
F_58 ( & V_76 -> V_82 ) ;
if ( V_202 -> V_31 == V_61 ) {
if ( V_201 -> V_31 == V_63 ||
V_201 -> V_31 == V_69 ||
V_201 -> V_31 == V_71 ||
V_201 -> V_31 == V_59 )
V_202 -> V_115 = 1 ;
}
if ( V_201 -> V_31 == V_59 ) {
if ( V_202 -> V_31 == V_70 ||
V_202 -> V_31 == V_68 ||
V_202 -> V_31 == V_71 ||
V_202 -> V_31 == V_61 )
V_201 -> V_115 = 1 ;
}
if ( V_205 == NULL ) {
F_19 ( & V_76 -> V_80 , & V_11 -> V_15 -> V_81 ) ;
F_19 ( & V_76 -> V_82 , & V_202 -> V_83 ) ;
F_19 ( & V_76 -> V_84 , & V_201 -> V_85 ) ;
V_76 -> V_45 = 1 ;
return 0 ;
}
switch ( V_202 -> V_31 ) {
case V_60 :
case V_62 :
case V_57 :
case V_58 :
case V_61 :
case V_59 :
case V_63 :
case V_64 :
case V_72 :
case V_73 :
case V_65 :
case V_66 :
case V_67 :
F_19 ( & V_76 -> V_80 , & V_11 -> V_15 -> V_81 ) ;
F_19 ( & V_76 -> V_82 , & V_202 -> V_83 ) ;
F_19 ( & V_76 -> V_84 , & V_201 -> V_85 ) ;
V_76 -> V_45 = 1 ;
return 0 ;
case V_46 :
case V_54 :
case V_55 :
V_16 = F_18 ( V_11 , V_201 , V_202 , V_76 , V_205 ,
& V_202 -> V_38 [ 0 ] ) ;
if ( V_16 != 0 )
goto V_208;
break;
case V_32 :
case V_33 :
case V_34 :
V_16 = F_20 ( V_11 , V_201 , V_202 , V_76 , V_205 ) ;
if ( V_16 != 0 )
goto V_208;
break;
case V_68 :
case V_69 :
case V_71 :
case V_70 :
F_19 ( & V_76 -> V_80 , & V_11 -> V_15 -> V_81 ) ;
F_19 ( & V_76 -> V_82 , & V_202 -> V_83 ) ;
F_19 ( & V_76 -> V_84 , & V_201 -> V_85 ) ;
V_76 -> V_45 = 0 ;
return 0 ;
}
return 0 ;
V_208:
F_79 ( V_11 -> V_3 , L_59 ,
V_117 , V_205 , V_116 ) ;
F_7 ( V_76 ) ;
return V_16 ;
}
int F_97 ( struct V_10 * V_11 ,
const struct V_199 * V_200 , int V_209 )
{
int V_30 , V_16 ;
for ( V_30 = 0 ; V_30 < V_209 ; V_30 ++ ) {
V_16 = F_96 ( V_11 , V_200 ) ;
if ( V_16 < 0 ) {
F_12 ( V_11 -> V_3 , L_60 ,
V_200 -> V_117 , V_200 -> V_116 ) ;
return V_16 ;
}
V_200 ++ ;
}
return 0 ;
}
int F_98 ( struct V_10 * V_11 )
{
struct V_8 * V_27 ;
unsigned int V_35 ;
F_22 (w, &dapm->card->widgets, list)
{
if ( V_27 -> V_210 )
continue;
if ( V_27 -> V_87 ) {
V_27 -> V_91 = F_24 ( V_27 -> V_87 *
sizeof( struct V_90 * ) ,
V_7 ) ;
if ( ! V_27 -> V_91 )
return - V_100 ;
}
switch( V_27 -> V_31 ) {
case V_32 :
case V_33 :
case V_34 :
V_27 -> V_125 = F_39 ;
F_23 ( V_27 ) ;
break;
case V_46 :
case V_54 :
case V_55 :
V_27 -> V_125 = F_39 ;
F_27 ( V_27 ) ;
break;
case V_60 :
case V_67 :
V_27 -> V_125 = F_40 ;
break;
case V_62 :
case V_66 :
V_27 -> V_125 = F_41 ;
break;
case V_57 :
case V_58 :
V_27 -> V_125 = F_39 ;
F_29 ( V_27 ) ;
break;
case V_61 :
case V_59 :
case V_63 :
case V_70 :
case V_68 :
case V_69 :
case V_71 :
V_27 -> V_125 = F_39 ;
break;
case V_65 :
V_27 -> V_125 = F_42 ;
case V_64 :
case V_72 :
case V_73 :
break;
}
if ( V_27 -> V_40 >= 0 ) {
V_35 = F_17 ( V_27 -> V_23 , V_27 -> V_40 ) ;
V_35 &= 1 << V_27 -> V_41 ;
if ( V_27 -> V_44 )
V_35 = ! V_35 ;
if ( V_35 )
V_27 -> V_123 = 1 ;
}
V_27 -> V_210 = 1 ;
F_80 ( V_27 ) ;
}
F_64 ( V_11 , V_169 ) ;
return 0 ;
}
int F_99 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_96 * V_97 = F_100 ( V_79 ) ;
struct V_8 * V_108 = V_97 -> V_102 [ 0 ] ;
struct V_36 * V_37 =
(struct V_36 * ) V_79 -> V_39 ;
unsigned int V_40 = V_37 -> V_40 ;
unsigned int V_41 = V_37 -> V_41 ;
unsigned int V_213 = V_37 -> V_213 ;
int V_42 = V_37 -> V_42 ;
unsigned int V_44 = V_37 -> V_44 ;
unsigned int V_43 = ( 1 << F_16 ( V_42 ) ) - 1 ;
V_212 -> V_143 . integer . V_143 [ 0 ] =
( F_17 ( V_108 -> V_23 , V_40 ) >> V_41 ) & V_43 ;
if ( V_41 != V_213 )
V_212 -> V_143 . integer . V_143 [ 1 ] =
( F_17 ( V_108 -> V_23 , V_40 ) >> V_213 ) & V_43 ;
if ( V_44 ) {
V_212 -> V_143 . integer . V_143 [ 0 ] =
V_42 - V_212 -> V_143 . integer . V_143 [ 0 ] ;
if ( V_41 != V_213 )
V_212 -> V_143 . integer . V_143 [ 1 ] =
V_42 - V_212 -> V_143 . integer . V_143 [ 1 ] ;
}
return 0 ;
}
int F_101 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_96 * V_97 = F_100 ( V_79 ) ;
struct V_8 * V_108 = V_97 -> V_102 [ 0 ] ;
struct V_190 * V_23 = V_108 -> V_23 ;
struct V_36 * V_37 =
(struct V_36 * ) V_79 -> V_39 ;
unsigned int V_40 = V_37 -> V_40 ;
unsigned int V_41 = V_37 -> V_41 ;
int V_42 = V_37 -> V_42 ;
unsigned int V_43 = ( 1 << F_16 ( V_42 ) ) - 1 ;
unsigned int V_44 = V_37 -> V_44 ;
unsigned int V_35 ;
int V_45 , V_183 ;
struct V_154 V_155 ;
int V_214 ;
V_35 = ( V_212 -> V_143 . integer . V_143 [ 0 ] & V_43 ) ;
if ( V_44 )
V_35 = V_42 - V_35 ;
V_43 = V_43 << V_41 ;
V_35 = V_35 << V_41 ;
if ( V_35 )
V_45 = V_44 ? 0 : 1 ;
else
V_45 = V_44 ? 1 : 0 ;
F_102 ( & V_23 -> V_215 ) ;
V_183 = F_103 ( V_108 -> V_23 , V_40 , V_43 , V_35 ) ;
if ( V_183 ) {
for ( V_214 = 0 ; V_214 < V_97 -> V_101 ; V_214 ++ ) {
V_108 = V_97 -> V_102 [ V_214 ] ;
V_108 -> V_143 = V_35 ;
V_155 . V_79 = V_79 ;
V_155 . V_108 = V_108 ;
V_155 . V_40 = V_40 ;
V_155 . V_43 = V_43 ;
V_155 . V_35 = V_35 ;
V_108 -> V_11 -> V_155 = & V_155 ;
F_84 ( V_108 , V_79 , V_45 ) ;
V_108 -> V_11 -> V_155 = NULL ;
}
}
F_104 ( & V_23 -> V_215 ) ;
return 0 ;
}
int F_105 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_96 * V_97 = F_100 ( V_79 ) ;
struct V_8 * V_108 = V_97 -> V_102 [ 0 ] ;
struct V_47 * V_48 = (struct V_47 * ) V_79 -> V_39 ;
unsigned int V_35 , V_50 ;
for ( V_50 = 1 ; V_50 < V_48 -> V_42 ; V_50 <<= 1 )
;
V_35 = F_17 ( V_108 -> V_23 , V_48 -> V_40 ) ;
V_212 -> V_143 . V_216 . V_49 [ 0 ] = ( V_35 >> V_48 -> V_51 ) & ( V_50 - 1 ) ;
if ( V_48 -> V_51 != V_48 -> V_217 )
V_212 -> V_143 . V_216 . V_49 [ 1 ] =
( V_35 >> V_48 -> V_217 ) & ( V_50 - 1 ) ;
return 0 ;
}
int F_106 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_96 * V_97 = F_100 ( V_79 ) ;
struct V_8 * V_108 = V_97 -> V_102 [ 0 ] ;
struct V_190 * V_23 = V_108 -> V_23 ;
struct V_47 * V_48 = (struct V_47 * ) V_79 -> V_39 ;
unsigned int V_35 , V_184 , V_183 ;
unsigned int V_43 , V_50 ;
struct V_154 V_155 ;
int V_214 ;
for ( V_50 = 1 ; V_50 < V_48 -> V_42 ; V_50 <<= 1 )
;
if ( V_212 -> V_143 . V_216 . V_49 [ 0 ] > V_48 -> V_42 - 1 )
return - V_21 ;
V_184 = V_212 -> V_143 . V_216 . V_49 [ 0 ] ;
V_35 = V_184 << V_48 -> V_51 ;
V_43 = ( V_50 - 1 ) << V_48 -> V_51 ;
if ( V_48 -> V_51 != V_48 -> V_217 ) {
if ( V_212 -> V_143 . V_216 . V_49 [ 1 ] > V_48 -> V_42 - 1 )
return - V_21 ;
V_35 |= V_212 -> V_143 . V_216 . V_49 [ 1 ] << V_48 -> V_217 ;
V_43 |= ( V_50 - 1 ) << V_48 -> V_217 ;
}
F_102 ( & V_23 -> V_215 ) ;
V_183 = F_103 ( V_108 -> V_23 , V_48 -> V_40 , V_43 , V_35 ) ;
if ( V_183 ) {
for ( V_214 = 0 ; V_214 < V_97 -> V_101 ; V_214 ++ ) {
V_108 = V_97 -> V_102 [ V_214 ] ;
V_108 -> V_143 = V_35 ;
V_155 . V_79 = V_79 ;
V_155 . V_108 = V_108 ;
V_155 . V_40 = V_48 -> V_40 ;
V_155 . V_43 = V_43 ;
V_155 . V_35 = V_35 ;
V_108 -> V_11 -> V_155 = & V_155 ;
F_83 ( V_108 , V_79 , V_183 , V_184 , V_48 ) ;
V_108 -> V_11 -> V_155 = NULL ;
}
}
F_104 ( & V_23 -> V_215 ) ;
return V_183 ;
}
int F_107 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_96 * V_97 = F_100 ( V_79 ) ;
struct V_8 * V_108 = V_97 -> V_102 [ 0 ] ;
V_212 -> V_143 . V_216 . V_49 [ 0 ] = V_108 -> V_143 ;
return 0 ;
}
int F_108 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_96 * V_97 = F_100 ( V_79 ) ;
struct V_8 * V_108 = V_97 -> V_102 [ 0 ] ;
struct V_190 * V_23 = V_108 -> V_23 ;
struct V_47 * V_48 =
(struct V_47 * ) V_79 -> V_39 ;
int V_183 ;
int V_16 = 0 ;
int V_214 ;
if ( V_212 -> V_143 . V_216 . V_49 [ 0 ] >= V_48 -> V_42 )
return - V_21 ;
F_102 ( & V_23 -> V_215 ) ;
V_183 = V_108 -> V_143 != V_212 -> V_143 . V_216 . V_49 [ 0 ] ;
if ( V_183 ) {
for ( V_214 = 0 ; V_214 < V_97 -> V_101 ; V_214 ++ ) {
V_108 = V_97 -> V_102 [ V_214 ] ;
V_108 -> V_143 = V_212 -> V_143 . V_216 . V_49 [ 0 ] ;
F_83 ( V_108 , V_79 , V_183 ,
V_108 -> V_143 , V_48 ) ;
}
}
F_104 ( & V_23 -> V_215 ) ;
return V_16 ;
}
int F_109 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_96 * V_97 = F_100 ( V_79 ) ;
struct V_8 * V_108 = V_97 -> V_102 [ 0 ] ;
struct V_47 * V_48 = (struct V_47 * ) V_79 -> V_39 ;
unsigned int V_218 , V_35 , V_184 ;
V_218 = F_17 ( V_108 -> V_23 , V_48 -> V_40 ) ;
V_35 = ( V_218 >> V_48 -> V_51 ) & V_48 -> V_43 ;
for ( V_184 = 0 ; V_184 < V_48 -> V_42 ; V_184 ++ ) {
if ( V_35 == V_48 -> V_56 [ V_184 ] )
break;
}
V_212 -> V_143 . V_216 . V_49 [ 0 ] = V_184 ;
if ( V_48 -> V_51 != V_48 -> V_217 ) {
V_35 = ( V_218 >> V_48 -> V_217 ) & V_48 -> V_43 ;
for ( V_184 = 0 ; V_184 < V_48 -> V_42 ; V_184 ++ ) {
if ( V_35 == V_48 -> V_56 [ V_184 ] )
break;
}
V_212 -> V_143 . V_216 . V_49 [ 1 ] = V_184 ;
}
return 0 ;
}
int F_110 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_96 * V_97 = F_100 ( V_79 ) ;
struct V_8 * V_108 = V_97 -> V_102 [ 0 ] ;
struct V_190 * V_23 = V_108 -> V_23 ;
struct V_47 * V_48 = (struct V_47 * ) V_79 -> V_39 ;
unsigned int V_35 , V_184 , V_183 ;
unsigned int V_43 ;
struct V_154 V_155 ;
int V_214 ;
if ( V_212 -> V_143 . V_216 . V_49 [ 0 ] > V_48 -> V_42 - 1 )
return - V_21 ;
V_184 = V_212 -> V_143 . V_216 . V_49 [ 0 ] ;
V_35 = V_48 -> V_56 [ V_212 -> V_143 . V_216 . V_49 [ 0 ] ] << V_48 -> V_51 ;
V_43 = V_48 -> V_43 << V_48 -> V_51 ;
if ( V_48 -> V_51 != V_48 -> V_217 ) {
if ( V_212 -> V_143 . V_216 . V_49 [ 1 ] > V_48 -> V_42 - 1 )
return - V_21 ;
V_35 |= V_48 -> V_56 [ V_212 -> V_143 . V_216 . V_49 [ 1 ] ] << V_48 -> V_217 ;
V_43 |= V_48 -> V_43 << V_48 -> V_217 ;
}
F_102 ( & V_23 -> V_215 ) ;
V_183 = F_103 ( V_108 -> V_23 , V_48 -> V_40 , V_43 , V_35 ) ;
if ( V_183 ) {
for ( V_214 = 0 ; V_214 < V_97 -> V_101 ; V_214 ++ ) {
V_108 = V_97 -> V_102 [ V_214 ] ;
V_108 -> V_143 = V_35 ;
V_155 . V_79 = V_79 ;
V_155 . V_108 = V_108 ;
V_155 . V_40 = V_48 -> V_40 ;
V_155 . V_43 = V_43 ;
V_155 . V_35 = V_35 ;
V_108 -> V_11 -> V_155 = & V_155 ;
F_83 ( V_108 , V_79 , V_183 , V_184 , V_48 ) ;
V_108 -> V_11 -> V_155 = NULL ;
}
}
F_104 ( & V_23 -> V_215 ) ;
return V_183 ;
}
int F_111 ( struct V_90 * V_79 ,
struct V_219 * V_220 )
{
V_220 -> type = V_221 ;
V_220 -> V_174 = 1 ;
V_220 -> V_143 . integer . V_222 = 0 ;
V_220 -> V_143 . integer . V_42 = 1 ;
return 0 ;
}
int F_112 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_190 * V_23 = F_100 ( V_79 ) ;
const char * V_195 = ( const char * ) V_79 -> V_39 ;
F_102 ( & V_23 -> V_215 ) ;
V_212 -> V_143 . integer . V_143 [ 0 ] =
F_113 ( & V_23 -> V_11 , V_195 ) ;
F_104 ( & V_23 -> V_215 ) ;
return 0 ;
}
int F_114 ( struct V_90 * V_79 ,
struct V_211 * V_212 )
{
struct V_190 * V_23 = F_100 ( V_79 ) ;
const char * V_195 = ( const char * ) V_79 -> V_39 ;
F_102 ( & V_23 -> V_215 ) ;
if ( V_212 -> V_143 . integer . V_143 [ 0 ] )
F_115 ( & V_23 -> V_11 , V_195 ) ;
else
F_116 ( & V_23 -> V_11 , V_195 ) ;
F_95 ( & V_23 -> V_11 ) ;
F_104 ( & V_23 -> V_215 ) ;
return 0 ;
}
int F_117 ( struct V_10 * V_11 ,
const struct V_8 * V_108 )
{
struct V_8 * V_27 ;
T_3 V_92 ;
if ( ( V_27 = F_8 ( V_108 ) ) == NULL )
return - V_100 ;
V_92 = strlen ( V_108 -> V_52 ) + 1 ;
if ( V_11 -> V_23 && V_11 -> V_23 -> V_99 )
V_92 += 1 + strlen ( V_11 -> V_23 -> V_99 ) ;
V_27 -> V_52 = F_5 ( V_92 , V_7 ) ;
if ( V_27 -> V_52 == NULL ) {
F_7 ( V_27 ) ;
return - V_100 ;
}
if ( V_11 -> V_23 && V_11 -> V_23 -> V_99 )
snprintf ( V_27 -> V_52 , V_92 , L_8 ,
V_11 -> V_23 -> V_99 , V_108 -> V_52 ) ;
else
snprintf ( V_27 -> V_52 , V_92 , L_1 , V_108 -> V_52 ) ;
V_11 -> V_166 ++ ;
V_27 -> V_11 = V_11 ;
V_27 -> V_23 = V_11 -> V_23 ;
F_58 ( & V_27 -> V_83 ) ;
F_58 ( & V_27 -> V_85 ) ;
F_58 ( & V_27 -> V_80 ) ;
F_19 ( & V_27 -> V_80 , & V_11 -> V_15 -> V_102 ) ;
V_27 -> V_114 = 1 ;
return 0 ;
}
int F_118 ( struct V_10 * V_11 ,
const struct V_8 * V_108 ,
int V_209 )
{
int V_30 , V_16 ;
for ( V_30 = 0 ; V_30 < V_209 ; V_30 ++ ) {
V_16 = F_117 ( V_11 , V_108 ) ;
if ( V_16 < 0 ) {
F_12 ( V_11 -> V_3 ,
L_61 ,
V_108 -> V_52 , V_16 ) ;
return V_16 ;
}
V_108 ++ ;
}
return 0 ;
}
static void F_119 ( struct V_10 * V_11 ,
const char * V_223 , int V_118 )
{
struct V_8 * V_27 ;
F_22 (w, &dapm->card->widgets, list)
{
if ( ! V_27 -> V_176 || V_27 -> V_11 != V_11 )
continue;
F_11 ( V_27 -> V_11 -> V_3 , L_62 ,
V_27 -> V_52 , V_27 -> V_176 , V_223 , V_118 ) ;
if ( strstr ( V_27 -> V_176 , V_223 ) ) {
switch( V_118 ) {
case V_152 :
V_27 -> V_113 = 1 ;
break;
case V_153 :
V_27 -> V_113 = 0 ;
break;
case V_168 :
case V_167 :
case V_224 :
case V_225 :
break;
}
}
}
F_64 ( V_11 , V_118 ) ;
}
int F_120 ( struct V_188 * V_189 ,
const char * V_223 , int V_118 )
{
struct V_190 * V_23 = V_189 -> V_23 ;
if ( V_223 == NULL )
return 0 ;
F_102 ( & V_23 -> V_215 ) ;
F_119 ( & V_23 -> V_11 , V_223 , V_118 ) ;
F_104 ( & V_23 -> V_215 ) ;
return 0 ;
}
int F_115 ( struct V_10 * V_11 , const char * V_195 )
{
return F_94 ( V_11 , V_195 , 1 ) ;
}
int F_121 ( struct V_10 * V_11 ,
const char * V_195 )
{
struct V_8 * V_27 = F_93 ( V_11 , V_195 , true ) ;
if ( ! V_27 ) {
F_12 ( V_11 -> V_3 , L_58 , V_195 ) ;
return - V_21 ;
}
F_11 ( V_27 -> V_11 -> V_3 , L_63 , V_195 ) ;
V_27 -> V_114 = 1 ;
V_27 -> V_124 = 1 ;
return 0 ;
}
int F_116 ( struct V_10 * V_11 ,
const char * V_195 )
{
return F_94 ( V_11 , V_195 , 0 ) ;
}
int F_122 ( struct V_10 * V_11 , const char * V_195 )
{
return F_94 ( V_11 , V_195 , 0 ) ;
}
int F_113 ( struct V_10 * V_11 ,
const char * V_195 )
{
struct V_8 * V_27 = F_93 ( V_11 , V_195 , true ) ;
if ( V_27 )
return V_27 -> V_114 ;
return 0 ;
}
int F_123 ( struct V_10 * V_11 ,
const char * V_195 )
{
struct V_8 * V_27 = F_93 ( V_11 , V_195 , false ) ;
if ( ! V_27 ) {
F_12 ( V_11 -> V_3 , L_58 , V_195 ) ;
return - V_21 ;
}
V_27 -> V_111 = 1 ;
return 0 ;
}
void F_124 ( struct V_10 * V_11 )
{
F_89 ( V_11 -> V_3 ) ;
F_81 ( V_11 ) ;
F_91 ( V_11 ) ;
F_92 ( & V_11 -> V_80 ) ;
}
static void F_125 ( struct V_10 * V_11 )
{
struct V_8 * V_27 ;
F_55 ( V_164 ) ;
int V_226 = 0 ;
F_22 (w, &dapm->card->widgets, list) {
if ( V_27 -> V_11 != V_11 )
continue;
if ( V_27 -> V_123 ) {
F_44 ( V_27 , & V_164 , false ) ;
V_27 -> V_123 = 0 ;
V_226 = 1 ;
}
}
if ( V_226 ) {
F_10 ( V_11 , V_18 ) ;
F_54 ( V_11 , & V_164 , 0 , false ) ;
F_10 ( V_11 , V_19 ) ;
}
}
void F_126 ( struct V_14 * V_15 )
{
struct V_190 * V_23 ;
F_22 (codec, &card->codec_dev_list, list) {
F_125 ( & V_23 -> V_11 ) ;
F_10 ( & V_23 -> V_11 , V_20 ) ;
}
}
