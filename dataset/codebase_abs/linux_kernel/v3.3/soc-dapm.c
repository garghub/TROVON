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
static bool F_8 ( struct V_8 * V_9 )
{
return ! F_9 ( & V_9 -> V_10 ) ;
}
void F_10 ( struct V_8 * V_9 , const char * V_11 )
{
if ( ! F_8 ( V_9 ) ) {
F_11 ( V_9 -> V_12 -> V_3 , L_2 ,
V_9 -> V_13 , V_11 ) ;
F_12 ( & V_9 -> V_10 , & V_9 -> V_12 -> V_14 -> V_15 ) ;
}
}
static inline struct V_8 * F_13 (
const struct V_8 * V_16 )
{
return F_14 ( V_16 , sizeof( * V_16 ) , V_7 ) ;
}
static inline struct V_17 * F_15 (
struct V_18 * V_12 )
{
if ( V_12 -> V_19 )
return V_12 -> V_19 -> V_14 -> V_17 ;
else if ( V_12 -> V_20 )
return V_12 -> V_20 -> V_14 -> V_17 ;
else
F_16 () ;
return NULL ;
}
static inline struct V_21 * F_17 (
struct V_18 * V_12 )
{
if ( V_12 -> V_19 )
return V_12 -> V_19 -> V_14 ;
else if ( V_12 -> V_20 )
return V_12 -> V_20 -> V_14 ;
else
F_16 () ;
return NULL ;
}
static int F_18 ( struct V_8 * V_9 , int V_22 )
{
if ( V_9 -> V_19 )
return F_19 ( V_9 -> V_19 , V_22 ) ;
else if ( V_9 -> V_20 )
return F_20 ( V_9 -> V_20 , V_22 ) ;
F_21 ( V_9 -> V_12 -> V_3 , L_3 ) ;
return - 1 ;
}
static int F_22 ( struct V_8 * V_9 , int V_22 , int V_23 )
{
if ( V_9 -> V_19 )
return F_23 ( V_9 -> V_19 , V_22 , V_23 ) ;
else if ( V_9 -> V_20 )
return F_24 ( V_9 -> V_20 , V_22 , V_23 ) ;
F_21 ( V_9 -> V_12 -> V_3 , L_4 ) ;
return - 1 ;
}
static int F_25 ( struct V_8 * V_9 ,
unsigned short V_22 , unsigned int V_24 , unsigned int V_25 )
{
int V_26 ;
unsigned int V_27 , V_28 ;
int V_29 ;
V_29 = F_18 ( V_9 , V_22 ) ;
if ( V_29 < 0 )
return V_29 ;
V_27 = V_29 ;
V_28 = ( V_27 & ~ V_24 ) | ( V_25 & V_24 ) ;
V_26 = V_27 != V_28 ;
if ( V_26 ) {
V_29 = F_22 ( V_9 , V_22 , V_28 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return V_26 ;
}
static int F_26 ( struct V_18 * V_12 ,
enum V_30 V_31 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
int V_29 = 0 ;
F_27 ( V_14 , V_31 ) ;
if ( V_14 && V_14 -> V_32 )
V_29 = V_14 -> V_32 ( V_14 , V_12 , V_31 ) ;
if ( V_29 != 0 )
goto V_33;
if ( V_12 -> V_19 ) {
if ( V_12 -> V_19 -> V_34 -> V_32 )
V_29 = V_12 -> V_19 -> V_34 -> V_32 ( V_12 -> V_19 ,
V_31 ) ;
else
V_12 -> V_35 = V_31 ;
}
if ( V_29 != 0 )
goto V_33;
if ( V_14 && V_14 -> V_36 )
V_29 = V_14 -> V_36 ( V_14 , V_12 , V_31 ) ;
V_33:
F_28 ( V_14 , V_31 ) ;
return V_29 ;
}
static void F_29 ( struct V_8 * V_9 ,
struct V_37 * V_38 , int V_39 )
{
switch ( V_9 -> V_40 ) {
case V_41 :
case V_42 :
case V_43 : {
int V_23 ;
struct V_44 * V_45 = (struct V_44 * )
V_9 -> V_46 [ V_39 ] . V_47 ;
unsigned int V_22 = V_45 -> V_22 ;
unsigned int V_48 = V_45 -> V_48 ;
int V_49 = V_45 -> V_49 ;
unsigned int V_24 = ( 1 << F_30 ( V_49 ) ) - 1 ;
unsigned int V_50 = V_45 -> V_50 ;
V_23 = F_18 ( V_9 , V_22 ) ;
V_23 = ( V_23 >> V_48 ) & V_24 ;
if ( ( V_50 && ! V_23 ) || ( ! V_50 && V_23 ) )
V_38 -> V_51 = 1 ;
else
V_38 -> V_51 = 0 ;
}
break;
case V_52 : {
struct V_53 * V_54 = (struct V_53 * )
V_9 -> V_46 [ V_39 ] . V_47 ;
int V_23 , V_55 , V_56 ;
for ( V_56 = 1 ; V_56 < V_54 -> V_49 ; V_56 <<= 1 )
;
V_23 = F_18 ( V_9 , V_54 -> V_22 ) ;
V_55 = ( V_23 >> V_54 -> V_57 ) & ( V_56 - 1 ) ;
V_38 -> V_51 = 0 ;
for ( V_39 = 0 ; V_39 < V_54 -> V_49 ; V_39 ++ ) {
if ( ! ( strcmp ( V_38 -> V_13 , V_54 -> V_58 [ V_39 ] ) ) && V_55 == V_39 )
V_38 -> V_51 = 1 ;
}
}
break;
case V_59 : {
struct V_53 * V_54 = (struct V_53 * )
V_9 -> V_46 [ V_39 ] . V_47 ;
V_38 -> V_51 = 0 ;
if ( ! strcmp ( V_38 -> V_13 , V_54 -> V_58 [ 0 ] ) )
V_38 -> V_51 = 1 ;
}
break;
case V_60 : {
struct V_53 * V_54 = (struct V_53 * )
V_9 -> V_46 [ V_39 ] . V_47 ;
int V_23 , V_55 ;
V_23 = F_18 ( V_9 , V_54 -> V_22 ) ;
V_23 = ( V_23 >> V_54 -> V_57 ) & V_54 -> V_24 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_49 ; V_55 ++ ) {
if ( V_23 == V_54 -> V_61 [ V_55 ] )
break;
}
V_38 -> V_51 = 0 ;
for ( V_39 = 0 ; V_39 < V_54 -> V_49 ; V_39 ++ ) {
if ( ! ( strcmp ( V_38 -> V_13 , V_54 -> V_58 [ V_39 ] ) ) && V_55 == V_39 )
V_38 -> V_51 = 1 ;
}
}
break;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_38 -> V_51 = 1 ;
break;
case V_78 :
case V_79 :
V_38 -> V_51 = 0 ;
break;
}
}
static int F_31 ( struct V_18 * V_12 ,
struct V_8 * V_80 , struct V_8 * V_81 ,
struct V_37 * V_82 , const char * V_83 ,
const struct V_84 * V_85 )
{
struct V_53 * V_54 = (struct V_53 * ) V_85 -> V_47 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_54 -> V_49 ; V_39 ++ ) {
if ( ! ( strcmp ( V_83 , V_54 -> V_58 [ V_39 ] ) ) ) {
F_32 ( & V_82 -> V_86 , & V_12 -> V_14 -> V_87 ) ;
F_32 ( & V_82 -> V_88 , & V_81 -> V_89 ) ;
F_32 ( & V_82 -> V_90 , & V_80 -> V_91 ) ;
V_82 -> V_13 = ( char * ) V_54 -> V_58 [ V_39 ] ;
F_29 ( V_81 , V_82 , 0 ) ;
return 0 ;
}
}
return - V_92 ;
}
static int F_33 ( struct V_18 * V_12 ,
struct V_8 * V_80 , struct V_8 * V_81 ,
struct V_37 * V_82 , const char * V_83 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_81 -> V_93 ; V_39 ++ ) {
if ( ! strcmp ( V_83 , V_81 -> V_46 [ V_39 ] . V_13 ) ) {
F_32 ( & V_82 -> V_86 , & V_12 -> V_14 -> V_87 ) ;
F_32 ( & V_82 -> V_88 , & V_81 -> V_89 ) ;
F_32 ( & V_82 -> V_90 , & V_80 -> V_91 ) ;
V_82 -> V_13 = V_81 -> V_46 [ V_39 ] . V_13 ;
F_29 ( V_81 , V_82 , V_39 ) ;
return 0 ;
}
}
return - V_92 ;
}
static int F_34 ( struct V_18 * V_12 ,
struct V_8 * V_94 ,
const struct V_84 * V_95 ,
struct V_96 * * V_85 )
{
struct V_8 * V_9 ;
int V_39 ;
* V_85 = NULL ;
F_35 (w, &dapm->card->widgets, list) {
if ( V_9 == V_94 || V_9 -> V_12 != V_94 -> V_12 )
continue;
for ( V_39 = 0 ; V_39 < V_9 -> V_93 ; V_39 ++ ) {
if ( & V_9 -> V_46 [ V_39 ] == V_95 ) {
if ( V_9 -> V_97 )
* V_85 = V_9 -> V_97 [ V_39 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
int V_39 , V_29 = 0 ;
T_3 V_98 , V_99 ;
struct V_37 * V_82 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_100 ;
struct V_101 * V_102 ;
T_3 V_103 ;
if ( V_12 -> V_19 )
V_100 = V_12 -> V_19 -> V_104 ;
else
V_100 = NULL ;
if ( V_100 )
V_99 = strlen ( V_100 ) + 1 ;
else
V_99 = 0 ;
for ( V_39 = 0 ; V_39 < V_9 -> V_93 ; V_39 ++ ) {
F_35 (path, &w->sources, list_sink) {
if ( V_82 -> V_13 != ( char * ) V_9 -> V_46 [ V_39 ] . V_13 )
continue;
if ( V_9 -> V_97 [ V_39 ] ) {
V_82 -> V_85 = V_9 -> V_97 [ V_39 ] ;
continue;
}
V_103 = sizeof( struct V_101 ) +
sizeof( struct V_8 * ) ,
V_102 = F_37 ( V_103 , V_7 ) ;
if ( V_102 == NULL ) {
F_21 ( V_12 -> V_3 ,
L_5 ,
V_9 -> V_13 ) ;
return - V_105 ;
}
V_102 -> V_106 = 1 ;
V_102 -> V_107 [ 0 ] = V_9 ;
V_98 = strlen ( V_9 -> V_46 [ V_39 ] . V_13 ) + 1 ;
if ( V_9 -> V_40 != V_43 )
V_98 += 1 + strlen ( V_9 -> V_13 ) ;
V_82 -> V_108 = F_5 ( V_98 , V_7 ) ;
if ( V_82 -> V_108 == NULL ) {
F_7 ( V_102 ) ;
return - V_105 ;
}
switch ( V_9 -> V_40 ) {
default:
snprintf ( V_82 -> V_108 , V_98 , L_6 ,
V_9 -> V_13 + V_99 ,
V_9 -> V_46 [ V_39 ] . V_13 ) ;
break;
case V_43 :
snprintf ( V_82 -> V_108 , V_98 , L_1 ,
V_9 -> V_46 [ V_39 ] . V_13 ) ;
break;
}
V_82 -> V_108 [ V_98 - 1 ] = '\0' ;
V_82 -> V_85 = F_38 ( & V_9 -> V_46 [ V_39 ] ,
V_102 , V_82 -> V_108 ,
V_100 ) ;
V_29 = F_39 ( V_14 , V_82 -> V_85 ) ;
if ( V_29 < 0 ) {
F_21 ( V_12 -> V_3 ,
L_7 ,
V_82 -> V_108 , V_29 ) ;
F_7 ( V_102 ) ;
F_7 ( V_82 -> V_108 ) ;
V_82 -> V_108 = NULL ;
return V_29 ;
}
V_9 -> V_97 [ V_39 ] = V_82 -> V_85 ;
}
}
return V_29 ;
}
static int F_40 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_37 * V_82 = NULL ;
struct V_96 * V_85 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_100 ;
T_3 V_99 ;
int V_29 ;
struct V_101 * V_102 ;
int V_109 , V_110 ;
T_3 V_103 ;
char * V_13 ;
if ( V_9 -> V_93 != 1 ) {
F_21 ( V_12 -> V_3 ,
L_8 ,
V_9 -> V_13 ) ;
return - V_111 ;
}
V_109 = F_34 ( V_12 , V_9 , & V_9 -> V_46 [ 0 ] ,
& V_85 ) ;
if ( V_85 ) {
V_102 = V_85 -> V_112 ;
V_110 = V_102 -> V_106 + 1 ;
} else {
V_102 = NULL ;
V_110 = 1 ;
}
V_103 = sizeof( struct V_101 ) +
V_110 * sizeof( struct V_8 * ) ,
V_102 = F_41 ( V_102 , V_103 , V_7 ) ;
if ( V_102 == NULL ) {
F_21 ( V_12 -> V_3 ,
L_5 , V_9 -> V_13 ) ;
return - V_105 ;
}
V_102 -> V_106 = V_110 ;
V_102 -> V_107 [ V_110 - 1 ] = V_9 ;
if ( ! V_85 ) {
if ( V_12 -> V_19 )
V_100 = V_12 -> V_19 -> V_104 ;
else
V_100 = NULL ;
if ( V_109 ) {
V_13 = V_9 -> V_46 [ 0 ] . V_13 ;
V_99 = 0 ;
} else {
V_13 = V_9 -> V_13 ;
if ( V_100 )
V_99 = strlen ( V_100 ) + 1 ;
else
V_99 = 0 ;
}
V_85 = F_38 ( & V_9 -> V_46 [ 0 ] , V_102 ,
V_13 + V_99 , V_100 ) ;
V_29 = F_39 ( V_14 , V_85 ) ;
if ( V_29 < 0 ) {
F_21 ( V_12 -> V_3 , L_9 ,
V_9 -> V_13 , V_29 ) ;
F_7 ( V_102 ) ;
return V_29 ;
}
}
V_85 -> V_112 = V_102 ;
V_9 -> V_97 [ 0 ] = V_85 ;
F_35 (path, &w->sources, list_sink)
V_82 -> V_85 = V_85 ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 )
{
if ( V_9 -> V_93 )
F_21 ( V_9 -> V_12 -> V_3 ,
L_10 , V_9 -> V_13 ) ;
return 0 ;
}
static inline void F_43 ( struct V_18 * V_12 )
{
struct V_37 * V_38 ;
F_35 (p, &dapm->card->paths, list)
V_38 -> V_113 = 0 ;
}
static int F_44 ( struct V_8 * V_114 )
{
int V_31 = F_45 ( V_114 -> V_12 -> V_14 -> V_17 ) ;
switch ( V_31 ) {
case V_115 :
case V_116 :
if ( V_114 -> V_117 )
F_46 ( V_114 -> V_12 -> V_3 , L_11 ,
V_114 -> V_13 ) ;
return V_114 -> V_117 ;
default:
return 1 ;
}
}
static int F_47 ( struct V_8 * V_114 )
{
struct V_37 * V_82 ;
int V_118 = 0 ;
if ( V_114 -> V_119 >= 0 )
return V_114 -> V_119 ;
F_48 ( V_114 , V_120 ) ;
if ( V_114 -> V_40 == V_71 )
return 0 ;
switch ( V_114 -> V_40 ) {
case V_65 :
case V_73 :
if ( V_114 -> V_121 ) {
V_114 -> V_119 = F_44 ( V_114 ) ;
return V_114 -> V_119 ;
}
default:
break;
}
if ( V_114 -> V_122 ) {
if ( V_114 -> V_40 == V_64 && ! V_114 -> V_123 ) {
V_114 -> V_119 = F_44 ( V_114 ) ;
return V_114 -> V_119 ;
}
if ( V_114 -> V_40 == V_74 ||
V_114 -> V_40 == V_76 ||
( V_114 -> V_40 == V_77 &&
! F_9 ( & V_114 -> V_89 ) ) ) {
V_114 -> V_119 = F_44 ( V_114 ) ;
return V_114 -> V_119 ;
}
}
F_35 (path, &widget->sinks, list_source) {
F_48 ( V_114 , V_124 ) ;
if ( V_82 -> V_125 )
continue;
if ( V_82 -> V_113 )
continue;
if ( V_82 -> V_126 && V_82 -> V_51 ) {
V_82 -> V_113 = 1 ;
V_118 += F_47 ( V_82 -> V_126 ) ;
}
}
V_114 -> V_119 = V_118 ;
return V_118 ;
}
static int F_49 ( struct V_8 * V_114 )
{
struct V_37 * V_82 ;
int V_118 = 0 ;
if ( V_114 -> V_127 >= 0 )
return V_114 -> V_127 ;
F_48 ( V_114 , V_120 ) ;
if ( V_114 -> V_40 == V_71 )
return 0 ;
switch ( V_114 -> V_40 ) {
case V_68 :
case V_72 :
if ( V_114 -> V_121 ) {
V_114 -> V_127 = F_44 ( V_114 ) ;
return V_114 -> V_127 ;
}
default:
break;
}
if ( V_114 -> V_122 ) {
if ( V_114 -> V_40 == V_66 && ! V_114 -> V_123 ) {
V_114 -> V_127 = F_44 ( V_114 ) ;
return V_114 -> V_127 ;
}
if ( V_114 -> V_40 == V_70 ) {
V_114 -> V_127 = F_44 ( V_114 ) ;
return V_114 -> V_127 ;
}
if ( V_114 -> V_40 == V_75 ||
( V_114 -> V_40 == V_77 &&
! F_9 ( & V_114 -> V_91 ) ) ) {
V_114 -> V_127 = F_44 ( V_114 ) ;
return V_114 -> V_127 ;
}
if ( V_114 -> V_40 == V_67 ) {
V_114 -> V_127 = F_44 ( V_114 ) ;
return V_114 -> V_127 ;
}
}
F_35 (path, &widget->sources, list_sink) {
F_48 ( V_114 , V_124 ) ;
if ( V_82 -> V_125 )
continue;
if ( V_82 -> V_113 )
continue;
if ( V_82 -> V_128 && V_82 -> V_51 ) {
V_82 -> V_113 = 1 ;
V_118 += F_49 ( V_82 -> V_128 ) ;
}
}
V_114 -> V_127 = V_118 ;
return V_118 ;
}
int F_50 ( struct V_8 * V_9 ,
struct V_96 * V_85 , int V_129 )
{
unsigned int V_23 ;
if ( F_51 ( V_129 ) )
V_23 = V_9 -> V_130 ;
else
V_23 = V_9 -> V_131 ;
F_25 ( V_9 , - ( V_9 -> V_22 + 1 ) ,
V_9 -> V_24 << V_9 -> V_48 , V_23 << V_9 -> V_48 ) ;
return 0 ;
}
static int F_52 ( struct V_8 * V_9 )
{
if ( V_9 -> V_132 )
return V_9 -> V_133 ;
if ( V_9 -> V_134 )
V_9 -> V_133 = 1 ;
else
V_9 -> V_133 = V_9 -> V_135 ( V_9 ) ;
V_9 -> V_132 = true ;
return V_9 -> V_133 ;
}
static int F_53 ( struct V_8 * V_9 )
{
int V_136 , V_33 ;
F_48 ( V_9 , V_137 ) ;
V_136 = F_49 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
V_33 = F_47 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
return V_33 != 0 && V_136 != 0 ;
}
static int F_54 ( struct V_8 * V_9 )
{
int V_136 ;
F_48 ( V_9 , V_137 ) ;
if ( V_9 -> V_121 ) {
V_136 = F_49 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
return V_136 != 0 ;
} else {
return F_53 ( V_9 ) ;
}
}
static int F_55 ( struct V_8 * V_9 )
{
int V_33 ;
F_48 ( V_9 , V_137 ) ;
if ( V_9 -> V_121 ) {
V_33 = F_47 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
return V_33 != 0 ;
} else {
return F_53 ( V_9 ) ;
}
}
static int F_56 ( struct V_8 * V_9 )
{
struct V_37 * V_82 ;
F_48 ( V_9 , V_137 ) ;
F_35 (path, &w->sinks, list_source) {
F_48 ( V_9 , V_124 ) ;
if ( V_82 -> V_125 )
continue;
if ( V_82 -> V_122 &&
! V_82 -> V_122 ( V_82 -> V_128 , V_82 -> V_126 ) )
continue;
if ( ! V_82 -> V_126 )
continue;
if ( F_52 ( V_82 -> V_126 ) )
return 1 ;
}
F_43 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_57 ( struct V_8 * V_9 )
{
return 1 ;
}
static int F_58 ( struct V_8 * V_138 ,
struct V_8 * V_139 ,
bool V_140 )
{
int * V_141 ;
if ( V_140 )
V_141 = V_142 ;
else
V_141 = V_143 ;
if ( V_141 [ V_138 -> V_40 ] != V_141 [ V_139 -> V_40 ] )
return V_141 [ V_138 -> V_40 ] - V_141 [ V_139 -> V_40 ] ;
if ( V_138 -> V_144 != V_139 -> V_144 ) {
if ( V_140 )
return V_138 -> V_144 - V_139 -> V_144 ;
else
return V_139 -> V_144 - V_138 -> V_144 ;
}
if ( V_138 -> V_22 != V_139 -> V_22 )
return V_138 -> V_22 - V_139 -> V_22 ;
if ( V_138 -> V_12 != V_139 -> V_12 )
return ( unsigned long ) V_138 -> V_12 - ( unsigned long ) V_139 -> V_12 ;
return 0 ;
}
static void F_59 ( struct V_8 * V_145 ,
struct V_146 * V_86 ,
bool V_140 )
{
struct V_8 * V_9 ;
F_35 (w, list, power_list)
if ( F_58 ( V_145 , V_9 , V_140 ) < 0 ) {
F_12 ( & V_145 -> V_147 , & V_9 -> V_147 ) ;
return;
}
F_12 ( & V_145 -> V_147 , V_86 ) ;
}
static void F_60 ( struct V_18 * V_12 ,
struct V_8 * V_9 , int V_129 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
const char * V_148 ;
int V_149 , V_29 ;
switch ( V_129 ) {
case V_150 :
V_148 = L_12 ;
V_149 = 1 ;
break;
case V_151 :
V_148 = L_13 ;
V_149 = 1 ;
break;
case V_152 :
V_148 = L_14 ;
V_149 = 0 ;
break;
case V_153 :
V_148 = L_15 ;
V_149 = 0 ;
break;
default:
F_16 () ;
return;
}
if ( V_9 -> V_149 != V_149 )
return;
if ( V_9 -> V_129 && ( V_9 -> V_154 & V_129 ) ) {
F_4 ( V_12 -> V_3 , V_14 -> V_1 , L_16 ,
V_9 -> V_13 , V_148 ) ;
F_61 ( V_9 , V_129 ) ;
V_29 = V_9 -> V_129 ( V_9 , NULL , V_129 ) ;
F_62 ( V_9 , V_129 ) ;
if ( V_29 < 0 )
F_63 ( L_17 ,
V_148 , V_9 -> V_13 , V_29 ) ;
}
}
static void F_64 ( struct V_18 * V_12 ,
struct V_146 * V_155 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
int V_22 , V_149 ;
unsigned int V_25 = 0 ;
unsigned int V_24 = 0 ;
unsigned int V_156 ;
V_22 = F_65 ( V_155 , struct V_8 ,
V_147 ) -> V_22 ;
F_35 (w, pending, power_list) {
V_156 = 1 << V_9 -> V_48 ;
F_66 ( V_22 != V_9 -> V_22 ) ;
if ( V_9 -> V_50 )
V_149 = ! V_9 -> V_149 ;
else
V_149 = V_9 -> V_149 ;
V_24 |= V_156 ;
if ( V_149 )
V_25 |= V_156 ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_18 ,
V_9 -> V_13 , V_22 , V_25 , V_24 ) ;
F_60 ( V_12 , V_9 , V_150 ) ;
F_60 ( V_12 , V_9 , V_152 ) ;
}
if ( V_22 >= 0 ) {
V_9 = F_65 ( V_155 , struct V_8 ,
V_147 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_19 ,
V_25 , V_24 , V_22 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_25 ( V_9 , V_22 , V_24 , V_25 ) ;
}
F_35 (w, pending, power_list) {
F_60 ( V_12 , V_9 , V_151 ) ;
F_60 ( V_12 , V_9 , V_153 ) ;
}
}
static void F_67 ( struct V_18 * V_12 ,
struct V_146 * V_86 , int V_129 , bool V_140 )
{
struct V_8 * V_9 , * V_157 ;
F_68 ( V_155 ) ;
int V_158 = - 1 ;
int V_159 = - 1 ;
int V_160 = V_161 ;
struct V_18 * V_162 = NULL ;
int V_29 , V_39 ;
int * V_141 ;
if ( V_140 )
V_141 = V_142 ;
else
V_141 = V_143 ;
F_69 (w, n, list, power_list) {
V_29 = 0 ;
if ( V_141 [ V_9 -> V_40 ] != V_158 || V_9 -> V_22 != V_160 ||
V_9 -> V_12 != V_162 || V_9 -> V_144 != V_159 ) {
if ( ! F_9 ( & V_155 ) )
F_64 ( V_162 , & V_155 ) ;
if ( V_162 && V_162 -> V_163 ) {
for ( V_39 = 0 ; V_39 < F_70 ( V_142 ) ; V_39 ++ )
if ( V_141 [ V_39 ] == V_158 )
V_162 -> V_163 ( V_162 ,
V_39 ,
V_159 ) ;
}
F_71 ( & V_155 ) ;
V_158 = - 1 ;
V_159 = V_164 ;
V_160 = V_161 ;
V_162 = NULL ;
}
switch ( V_9 -> V_40 ) {
case V_78 :
if ( ! V_9 -> V_129 )
F_72 ( V_9 , V_157 , V_86 ,
V_147 ) ;
if ( V_129 == V_165 )
V_29 = V_9 -> V_129 ( V_9 ,
NULL , V_150 ) ;
else if ( V_129 == V_166 )
V_29 = V_9 -> V_129 ( V_9 ,
NULL , V_152 ) ;
break;
case V_79 :
if ( ! V_9 -> V_129 )
F_72 ( V_9 , V_157 , V_86 ,
V_147 ) ;
if ( V_129 == V_165 )
V_29 = V_9 -> V_129 ( V_9 ,
NULL , V_151 ) ;
else if ( V_129 == V_166 )
V_29 = V_9 -> V_129 ( V_9 ,
NULL , V_153 ) ;
break;
default:
V_158 = V_141 [ V_9 -> V_40 ] ;
V_159 = V_9 -> V_144 ;
V_160 = V_9 -> V_22 ;
V_162 = V_9 -> V_12 ;
F_73 ( & V_9 -> V_147 , & V_155 ) ;
break;
}
if ( V_29 < 0 )
F_21 ( V_9 -> V_12 -> V_3 ,
L_20 , V_29 ) ;
}
if ( ! F_9 ( & V_155 ) )
F_64 ( V_162 , & V_155 ) ;
if ( V_162 && V_162 -> V_163 ) {
for ( V_39 = 0 ; V_39 < F_70 ( V_142 ) ; V_39 ++ )
if ( V_141 [ V_39 ] == V_158 )
V_162 -> V_163 ( V_162 ,
V_39 , V_159 ) ;
}
}
static void F_74 ( struct V_18 * V_12 )
{
struct V_167 * V_168 = V_12 -> V_168 ;
struct V_8 * V_9 ;
int V_29 ;
if ( ! V_168 )
return;
V_9 = V_168 -> V_114 ;
if ( V_9 -> V_129 &&
( V_9 -> V_154 & V_169 ) ) {
V_29 = V_9 -> V_129 ( V_9 , V_168 -> V_85 , V_169 ) ;
if ( V_29 != 0 )
F_63 ( L_21 ,
V_9 -> V_13 , V_29 ) ;
}
V_29 = F_75 ( V_9 -> V_19 , V_168 -> V_22 , V_168 -> V_24 ,
V_168 -> V_23 ) ;
if ( V_29 < 0 )
F_63 ( L_22 , V_9 -> V_13 , V_29 ) ;
if ( V_9 -> V_129 &&
( V_9 -> V_154 & V_170 ) ) {
V_29 = V_9 -> V_129 ( V_9 , V_168 -> V_85 , V_170 ) ;
if ( V_29 != 0 )
F_63 ( L_23 ,
V_9 -> V_13 , V_29 ) ;
}
}
static void F_76 ( void * V_171 , T_4 V_172 )
{
struct V_18 * V_173 = V_171 ;
int V_29 ;
if ( V_173 -> V_35 == V_174 &&
V_173 -> V_175 != V_174 ) {
if ( V_173 -> V_3 )
F_77 ( V_173 -> V_3 ) ;
V_29 = F_26 ( V_173 , V_176 ) ;
if ( V_29 != 0 )
F_21 ( V_173 -> V_3 ,
L_24 , V_29 ) ;
}
if ( V_173 -> V_35 != V_173 -> V_175 ) {
V_29 = F_26 ( V_173 , V_177 ) ;
if ( V_29 != 0 )
F_21 ( V_173 -> V_3 ,
L_25 , V_29 ) ;
}
}
static void F_78 ( void * V_171 , T_4 V_172 )
{
struct V_18 * V_173 = V_171 ;
int V_29 ;
if ( V_173 -> V_35 == V_177 &&
( V_173 -> V_175 == V_176 ||
V_173 -> V_175 == V_174 ) ) {
V_29 = F_26 ( V_173 , V_176 ) ;
if ( V_29 != 0 )
F_21 ( V_173 -> V_3 , L_26 ,
V_29 ) ;
}
if ( V_173 -> V_35 == V_176 &&
V_173 -> V_175 == V_174 ) {
V_29 = F_26 ( V_173 , V_174 ) ;
if ( V_29 != 0 )
F_21 ( V_173 -> V_3 , L_27 , V_29 ) ;
if ( V_173 -> V_3 )
F_79 ( V_173 -> V_3 ) ;
}
if ( V_173 -> V_35 == V_177 &&
V_173 -> V_175 == V_178 ) {
V_29 = F_26 ( V_173 , V_178 ) ;
if ( V_29 != 0 )
F_21 ( V_173 -> V_3 , L_28 ,
V_29 ) ;
}
}
static void F_80 ( struct V_8 * V_179 ,
bool V_149 , bool V_51 )
{
if ( ! V_51 )
return;
if ( V_149 != V_179 -> V_149 )
F_10 ( V_179 , L_29 ) ;
}
static void F_81 ( struct V_8 * V_9 , bool V_149 ,
struct V_146 * V_180 ,
struct V_146 * V_181 )
{
struct V_37 * V_82 ;
if ( V_9 -> V_149 == V_149 )
return;
F_82 ( V_9 , V_149 ) ;
F_35 (path, &w->sources, list_sink) {
if ( V_82 -> V_128 ) {
F_80 ( V_82 -> V_128 , V_149 ,
V_82 -> V_51 ) ;
}
}
switch ( V_9 -> V_40 ) {
case V_71 :
break;
default:
F_35 (path, &w->sinks, list_source) {
if ( V_82 -> V_126 ) {
F_80 ( V_82 -> V_126 , V_149 ,
V_82 -> V_51 ) ;
}
}
break;
}
if ( V_149 )
F_59 ( V_9 , V_180 , true ) ;
else
F_59 ( V_9 , V_181 , false ) ;
V_9 -> V_149 = V_149 ;
}
static void F_83 ( struct V_8 * V_9 ,
struct V_146 * V_180 ,
struct V_146 * V_181 )
{
int V_149 ;
switch ( V_9 -> V_40 ) {
case V_78 :
F_59 ( V_9 , V_181 , false ) ;
break;
case V_79 :
F_59 ( V_9 , V_180 , true ) ;
break;
default:
V_149 = F_52 ( V_9 ) ;
F_81 ( V_9 , V_149 , V_180 , V_181 ) ;
break;
}
}
static int F_84 ( struct V_18 * V_12 , int V_129 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
struct V_18 * V_173 ;
F_68 ( V_180 ) ;
F_68 ( V_181 ) ;
F_68 ( V_182 ) ;
enum V_30 V_183 ;
F_85 ( V_14 ) ;
F_35 (d, &card->dapm_list, list) {
if ( V_173 -> V_184 || V_173 -> V_19 == NULL ) {
if ( V_173 -> V_185 )
V_173 -> V_175 = V_174 ;
else
V_173 -> V_175 = V_176 ;
}
}
memset ( & V_14 -> V_186 , 0 , sizeof( V_14 -> V_186 ) ) ;
F_35 (w, &card->widgets, list) {
V_9 -> V_132 = false ;
V_9 -> V_127 = - 1 ;
V_9 -> V_119 = - 1 ;
}
F_35 (w, &card->dapm_dirty, dirty) {
F_83 ( V_9 , & V_180 , & V_181 ) ;
}
F_35 (w, &card->widgets, list) {
F_86 ( & V_9 -> V_10 ) ;
if ( V_9 -> V_149 ) {
V_173 = V_9 -> V_12 ;
switch ( V_9 -> V_40 ) {
case V_71 :
case V_69 :
if ( V_173 -> V_175 < V_176 )
V_173 -> V_175 = V_176 ;
break;
default:
V_173 -> V_175 = V_178 ;
break;
}
}
}
if ( ! V_12 -> V_184 ) {
switch ( V_129 ) {
case V_165 :
case V_187 :
V_12 -> V_175 = V_178 ;
break;
case V_166 :
if ( V_12 -> V_19 && V_12 -> V_19 -> V_121 )
V_12 -> V_175 = V_178 ;
else
V_12 -> V_175 = V_176 ;
break;
case V_188 :
V_12 -> V_175 = V_176 ;
break;
case V_189 :
V_12 -> V_175 = V_12 -> V_35 ;
break;
default:
break;
}
}
V_183 = V_174 ;
F_35 (d, &card->dapm_list, list)
if ( V_173 -> V_175 > V_183 )
V_183 = V_173 -> V_175 ;
F_35 (d, &card->dapm_list, list)
if ( ! V_173 -> V_185 )
V_173 -> V_175 = V_183 ;
F_87 ( V_14 ) ;
F_35 (d, &dapm->card->dapm_list, list)
F_88 ( F_76 , V_173 ,
& V_182 ) ;
F_89 ( & V_182 ) ;
F_67 ( V_12 , & V_181 , V_129 , false ) ;
F_74 ( V_12 ) ;
F_67 ( V_12 , & V_180 , V_129 , true ) ;
F_35 (d, &dapm->card->dapm_list, list)
F_88 ( F_78 , V_173 ,
& V_182 ) ;
F_89 ( & V_182 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_30 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_90 ( V_14 ) ;
return 0 ;
}
static int F_91 ( struct V_190 * V_190 , struct V_191 * V_191 )
{
V_191 -> V_112 = V_190 -> V_192 ;
return 0 ;
}
static T_5 F_92 ( struct V_191 * V_191 ,
char T_6 * V_193 ,
T_3 V_194 , T_7 * V_195 )
{
struct V_8 * V_9 = V_191 -> V_112 ;
char * V_5 ;
int V_136 , V_33 ;
T_5 V_29 ;
struct V_37 * V_38 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_105 ;
V_136 = F_49 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
V_33 = F_47 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
V_29 = snprintf ( V_5 , V_6 , L_31 ,
V_9 -> V_13 , V_9 -> V_149 ? L_32 : L_33 , V_136 , V_33 ) ;
if ( V_9 -> V_22 >= 0 )
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 ,
L_34 ,
V_9 -> V_22 , V_9 -> V_22 , V_9 -> V_48 ) ;
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 , L_35 ) ;
if ( V_9 -> V_196 )
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 , L_36 ,
V_9 -> V_196 ,
V_9 -> V_121 ? L_37 : L_38 ) ;
F_35 (p, &w->sources, list_sink) {
if ( V_38 -> V_122 && ! V_38 -> V_122 ( V_9 , V_38 -> V_126 ) )
continue;
if ( V_38 -> V_51 )
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 ,
L_39 ,
V_38 -> V_13 ? V_38 -> V_13 : L_40 ,
V_38 -> V_128 -> V_13 ) ;
}
F_35 (p, &w->sinks, list_source) {
if ( V_38 -> V_122 && ! V_38 -> V_122 ( V_9 , V_38 -> V_126 ) )
continue;
if ( V_38 -> V_51 )
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 ,
L_41 ,
V_38 -> V_13 ? V_38 -> V_13 : L_40 ,
V_38 -> V_126 -> V_13 ) ;
}
V_29 = F_93 ( V_193 , V_194 , V_195 , V_5 , V_29 ) ;
F_7 ( V_5 ) ;
return V_29 ;
}
static int F_94 ( struct V_190 * V_190 , struct V_191 * V_191 )
{
V_191 -> V_112 = V_190 -> V_192 ;
return 0 ;
}
static T_5 F_95 ( struct V_191 * V_191 , char T_6 * V_193 ,
T_3 V_194 , T_7 * V_195 )
{
struct V_18 * V_12 = V_191 -> V_112 ;
char * V_31 ;
switch ( V_12 -> V_35 ) {
case V_178 :
V_31 = L_42 ;
break;
case V_177 :
V_31 = L_43 ;
break;
case V_176 :
V_31 = L_44 ;
break;
case V_174 :
V_31 = L_45 ;
break;
default:
F_16 () ;
V_31 = L_46 ;
break;
}
return F_93 ( V_193 , V_194 , V_195 , V_31 ,
strlen ( V_31 ) ) ;
}
void F_96 ( struct V_18 * V_12 ,
struct V_197 * V_198 )
{
struct V_197 * V_173 ;
V_12 -> V_199 = F_97 ( L_47 , V_198 ) ;
if ( ! V_12 -> V_199 ) {
F_98 ( V_200
L_48 ) ;
return;
}
V_173 = F_99 ( L_49 , 0444 ,
V_12 -> V_199 , V_12 ,
& V_201 ) ;
if ( ! V_173 )
F_100 ( V_12 -> V_3 ,
L_50 ) ;
}
static void F_101 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_197 * V_173 ;
if ( ! V_12 -> V_199 || ! V_9 -> V_13 )
return;
V_173 = F_99 ( V_9 -> V_13 , 0444 ,
V_12 -> V_199 , V_9 ,
& V_202 ) ;
if ( ! V_173 )
F_100 ( V_9 -> V_12 -> V_3 ,
L_51 ,
V_9 -> V_13 ) ;
}
static void F_102 ( struct V_18 * V_12 )
{
F_103 ( V_12 -> V_199 ) ;
}
void F_96 ( struct V_18 * V_12 ,
struct V_197 * V_198 )
{
}
static inline void F_101 ( struct V_8 * V_9 )
{
}
static inline void F_102 ( struct V_18 * V_12 )
{
}
static int F_104 ( struct V_8 * V_114 ,
struct V_96 * V_85 , int V_26 ,
int V_203 , struct V_53 * V_54 )
{
struct V_37 * V_82 ;
int V_204 = 0 ;
if ( V_114 -> V_40 != V_52 &&
V_114 -> V_40 != V_59 &&
V_114 -> V_40 != V_60 )
return - V_92 ;
if ( ! V_26 )
return 0 ;
F_35 (path, &widget->dapm->card->paths, list) {
if ( V_82 -> V_85 != V_85 )
continue;
if ( ! V_82 -> V_13 || ! V_54 -> V_58 [ V_203 ] )
continue;
V_204 = 1 ;
if ( ! ( strcmp ( V_82 -> V_13 , V_54 -> V_58 [ V_203 ] ) ) ) {
V_82 -> V_51 = 1 ;
F_10 ( V_82 -> V_128 , L_52 ) ;
} else {
if ( V_82 -> V_51 )
F_10 ( V_82 -> V_128 ,
L_53 ) ;
V_82 -> V_51 = 0 ;
}
}
if ( V_204 ) {
F_10 ( V_114 , L_54 ) ;
F_84 ( V_114 -> V_12 , V_189 ) ;
}
return 0 ;
}
static int F_105 ( struct V_8 * V_114 ,
struct V_96 * V_85 , int V_51 )
{
struct V_37 * V_82 ;
int V_204 = 0 ;
if ( V_114 -> V_40 != V_42 &&
V_114 -> V_40 != V_43 &&
V_114 -> V_40 != V_41 )
return - V_92 ;
F_35 (path, &widget->dapm->card->paths, list) {
if ( V_82 -> V_85 != V_85 )
continue;
V_204 = 1 ;
V_82 -> V_51 = V_51 ;
F_10 ( V_82 -> V_128 , L_55 ) ;
}
if ( V_204 ) {
F_10 ( V_114 , L_56 ) ;
F_84 ( V_114 -> V_12 , V_189 ) ;
}
return 0 ;
}
static T_5 F_106 ( struct V_2 * V_3 ,
struct V_205 * V_206 , char * V_5 )
{
struct V_207 * V_208 = F_107 ( V_3 ) ;
struct V_209 * V_19 = V_208 -> V_19 ;
struct V_8 * V_9 ;
int V_194 = 0 ;
char * V_210 = L_57 ;
F_35 (w, &codec->card->widgets, list) {
if ( V_9 -> V_12 != & V_19 -> V_12 )
continue;
switch ( V_9 -> V_40 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_69 :
case V_68 :
case V_65 :
case V_62 :
case V_63 :
case V_42 :
case V_43 :
case V_71 :
if ( V_9 -> V_13 )
V_194 += sprintf ( V_5 + V_194 , L_58 ,
V_9 -> V_13 , V_9 -> V_149 ? L_32 : L_33 ) ;
break;
default:
break;
}
}
switch ( V_19 -> V_12 . V_35 ) {
case V_178 :
V_210 = L_32 ;
break;
case V_177 :
V_210 = L_59 ;
break;
case V_176 :
V_210 = L_60 ;
break;
case V_174 :
V_210 = L_33 ;
break;
}
V_194 += sprintf ( V_5 + V_194 , L_61 , V_210 ) ;
return V_194 ;
}
int F_108 ( struct V_2 * V_3 )
{
return F_109 ( V_3 , & V_211 ) ;
}
static void F_110 ( struct V_2 * V_3 )
{
F_111 ( V_3 , & V_211 ) ;
}
static void F_112 ( struct V_18 * V_12 )
{
struct V_8 * V_9 , * V_212 ;
struct V_37 * V_38 , * V_213 ;
F_69 (w, next_w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
F_113 ( & V_9 -> V_86 ) ;
F_69 (p, next_p, &w->sources, list_sink) {
F_113 ( & V_38 -> V_88 ) ;
F_113 ( & V_38 -> V_90 ) ;
F_113 ( & V_38 -> V_86 ) ;
F_7 ( V_38 -> V_108 ) ;
F_7 ( V_38 ) ;
}
F_69 (p, next_p, &w->sinks, list_source) {
F_113 ( & V_38 -> V_88 ) ;
F_113 ( & V_38 -> V_90 ) ;
F_113 ( & V_38 -> V_86 ) ;
F_7 ( V_38 -> V_108 ) ;
F_7 ( V_38 ) ;
}
F_7 ( V_9 -> V_97 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
}
static struct V_8 * F_114 (
struct V_18 * V_12 , const char * V_214 ,
bool V_215 )
{
struct V_8 * V_9 ;
struct V_8 * V_216 = NULL ;
F_35 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_9 -> V_13 , V_214 ) ) {
if ( V_9 -> V_12 == V_12 )
return V_9 ;
else
V_216 = V_9 ;
}
}
if ( V_215 )
return V_216 ;
return NULL ;
}
static int F_115 ( struct V_18 * V_12 ,
const char * V_214 , int V_217 )
{
struct V_8 * V_9 = F_114 ( V_12 , V_214 , true ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_62 , V_214 ) ;
return - V_111 ;
}
V_9 -> V_122 = V_217 ;
if ( V_217 == 0 )
V_9 -> V_134 = 0 ;
F_10 ( V_9 , L_63 ) ;
return 0 ;
}
int F_116 ( struct V_18 * V_12 )
{
if ( ! V_12 -> V_14 || ! V_12 -> V_14 -> V_218 )
return 0 ;
return F_84 ( V_12 , V_189 ) ;
}
static int F_117 ( struct V_18 * V_12 ,
const struct V_219 * V_220 )
{
struct V_37 * V_82 ;
struct V_8 * V_221 = NULL , * V_222 = NULL , * V_9 ;
struct V_8 * V_223 = NULL , * V_224 = NULL ;
const char * V_126 ;
const char * V_225 = V_220 -> V_225 ;
const char * V_128 ;
char V_226 [ 80 ] ;
char V_227 [ 80 ] ;
int V_29 = 0 ;
if ( V_12 -> V_19 && V_12 -> V_19 -> V_104 ) {
snprintf ( V_226 , sizeof( V_226 ) , L_6 ,
V_12 -> V_19 -> V_104 , V_220 -> V_126 ) ;
V_126 = V_226 ;
snprintf ( V_227 , sizeof( V_227 ) , L_6 ,
V_12 -> V_19 -> V_104 , V_220 -> V_128 ) ;
V_128 = V_227 ;
} else {
V_126 = V_220 -> V_126 ;
V_128 = V_220 -> V_128 ;
}
F_35 (w, &dapm->card->widgets, list) {
if ( ! V_222 && ! ( strcmp ( V_9 -> V_13 , V_126 ) ) ) {
V_224 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_222 = V_9 ;
continue;
}
if ( ! V_221 && ! ( strcmp ( V_9 -> V_13 , V_128 ) ) ) {
V_223 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_221 = V_9 ;
}
}
if ( ! V_222 )
V_222 = V_224 ;
if ( ! V_221 )
V_221 = V_223 ;
if ( V_221 == NULL || V_222 == NULL )
return - V_92 ;
V_82 = F_37 ( sizeof( struct V_37 ) , V_7 ) ;
if ( ! V_82 )
return - V_105 ;
V_82 -> V_128 = V_221 ;
V_82 -> V_126 = V_222 ;
V_82 -> V_122 = V_220 -> V_122 ;
F_71 ( & V_82 -> V_86 ) ;
F_71 ( & V_82 -> V_90 ) ;
F_71 ( & V_82 -> V_88 ) ;
if ( V_222 -> V_40 == V_66 ) {
if ( V_221 -> V_40 == V_69 ||
V_221 -> V_40 == V_75 ||
V_221 -> V_40 == V_77 ||
V_221 -> V_40 == V_64 )
V_222 -> V_123 = 1 ;
}
if ( V_221 -> V_40 == V_64 ) {
if ( V_222 -> V_40 == V_76 ||
V_222 -> V_40 == V_74 ||
V_222 -> V_40 == V_77 ||
V_222 -> V_40 == V_66 )
V_221 -> V_123 = 1 ;
}
if ( V_225 == NULL ) {
F_32 ( & V_82 -> V_86 , & V_12 -> V_14 -> V_87 ) ;
F_32 ( & V_82 -> V_88 , & V_222 -> V_89 ) ;
F_32 ( & V_82 -> V_90 , & V_221 -> V_91 ) ;
V_82 -> V_51 = 1 ;
return 0 ;
}
switch ( V_222 -> V_40 ) {
case V_65 :
case V_68 :
case V_62 :
case V_63 :
case V_66 :
case V_64 :
case V_67 :
case V_69 :
case V_70 :
case V_78 :
case V_79 :
case V_71 :
case V_72 :
case V_73 :
F_32 ( & V_82 -> V_86 , & V_12 -> V_14 -> V_87 ) ;
F_32 ( & V_82 -> V_88 , & V_222 -> V_89 ) ;
F_32 ( & V_82 -> V_90 , & V_221 -> V_91 ) ;
V_82 -> V_51 = 1 ;
return 0 ;
case V_52 :
case V_59 :
case V_60 :
V_29 = F_31 ( V_12 , V_221 , V_222 , V_82 , V_225 ,
& V_222 -> V_46 [ 0 ] ) ;
if ( V_29 != 0 )
goto V_228;
break;
case V_41 :
case V_42 :
case V_43 :
V_29 = F_33 ( V_12 , V_221 , V_222 , V_82 , V_225 ) ;
if ( V_29 != 0 )
goto V_228;
break;
case V_74 :
case V_75 :
case V_77 :
case V_76 :
F_32 ( & V_82 -> V_86 , & V_12 -> V_14 -> V_87 ) ;
F_32 ( & V_82 -> V_88 , & V_222 -> V_89 ) ;
F_32 ( & V_82 -> V_90 , & V_221 -> V_91 ) ;
V_82 -> V_51 = 0 ;
return 0 ;
}
return 0 ;
V_228:
F_100 ( V_12 -> V_3 , L_64 ,
V_128 , V_225 , V_126 ) ;
F_7 ( V_82 ) ;
return V_29 ;
}
int F_118 ( struct V_18 * V_12 ,
const struct V_219 * V_220 , int V_229 )
{
int V_39 , V_29 ;
for ( V_39 = 0 ; V_39 < V_229 ; V_39 ++ ) {
V_29 = F_117 ( V_12 , V_220 ) ;
if ( V_29 < 0 ) {
F_21 ( V_12 -> V_3 , L_65 ,
V_220 -> V_128 , V_220 -> V_126 ) ;
return V_29 ;
}
V_220 ++ ;
}
return 0 ;
}
static int F_119 ( struct V_18 * V_12 ,
const struct V_219 * V_220 )
{
struct V_8 * V_128 = F_114 ( V_12 ,
V_220 -> V_128 ,
true ) ;
struct V_8 * V_126 = F_114 ( V_12 ,
V_220 -> V_126 ,
true ) ;
struct V_37 * V_82 ;
int V_194 = 0 ;
if ( ! V_128 ) {
F_21 ( V_12 -> V_3 , L_66 ,
V_220 -> V_128 ) ;
return - V_92 ;
}
if ( ! V_126 ) {
F_21 ( V_12 -> V_3 , L_67 ,
V_220 -> V_126 ) ;
return - V_92 ;
}
if ( V_220 -> V_225 || V_220 -> V_122 )
F_100 ( V_12 -> V_3 , L_68 ,
V_220 -> V_128 , V_220 -> V_126 ) ;
F_35 (path, &source->sinks, list_source) {
if ( V_82 -> V_126 == V_126 ) {
V_82 -> V_125 = 1 ;
V_194 ++ ;
}
}
if ( V_194 == 0 )
F_21 ( V_12 -> V_3 , L_69 ,
V_220 -> V_128 , V_220 -> V_126 ) ;
if ( V_194 > 1 )
F_100 ( V_12 -> V_3 , L_70 ,
V_194 , V_220 -> V_128 , V_220 -> V_126 ) ;
return 0 ;
}
int F_120 ( struct V_18 * V_12 ,
const struct V_219 * V_220 , int V_229 )
{
int V_39 , V_228 ;
int V_29 = 0 ;
for ( V_39 = 0 ; V_39 < V_229 ; V_39 ++ ) {
V_228 = F_119 ( V_12 , V_220 ) ;
if ( V_228 )
V_29 = V_228 ;
V_220 ++ ;
}
return V_29 ;
}
int F_121 ( struct V_18 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_23 ;
F_35 (w, &dapm->card->widgets, list)
{
if ( V_9 -> V_28 )
continue;
if ( V_9 -> V_93 ) {
V_9 -> V_97 = F_37 ( V_9 -> V_93 *
sizeof( struct V_96 * ) ,
V_7 ) ;
if ( ! V_9 -> V_97 )
return - V_105 ;
}
switch( V_9 -> V_40 ) {
case V_41 :
case V_42 :
case V_43 :
F_36 ( V_9 ) ;
break;
case V_52 :
case V_59 :
case V_60 :
F_40 ( V_9 ) ;
break;
case V_62 :
case V_63 :
F_42 ( V_9 ) ;
break;
default:
break;
}
if ( V_9 -> V_22 >= 0 ) {
V_23 = F_18 ( V_9 , V_9 -> V_22 ) ;
V_23 &= 1 << V_9 -> V_48 ;
if ( V_9 -> V_50 )
V_23 = ! V_23 ;
if ( V_23 )
V_9 -> V_149 = 1 ;
}
V_9 -> V_28 = 1 ;
F_10 ( V_9 , L_71 ) ;
F_101 ( V_9 ) ;
}
F_84 ( V_12 , V_189 ) ;
return 0 ;
}
int F_122 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_101 * V_102 = F_123 ( V_85 ) ;
struct V_8 * V_114 = V_102 -> V_107 [ 0 ] ;
struct V_44 * V_45 =
(struct V_44 * ) V_85 -> V_47 ;
unsigned int V_22 = V_45 -> V_22 ;
unsigned int V_48 = V_45 -> V_48 ;
unsigned int V_232 = V_45 -> V_232 ;
int V_49 = V_45 -> V_49 ;
unsigned int V_50 = V_45 -> V_50 ;
unsigned int V_24 = ( 1 << F_30 ( V_49 ) ) - 1 ;
V_231 -> V_25 . integer . V_25 [ 0 ] =
( F_19 ( V_114 -> V_19 , V_22 ) >> V_48 ) & V_24 ;
if ( V_48 != V_232 )
V_231 -> V_25 . integer . V_25 [ 1 ] =
( F_19 ( V_114 -> V_19 , V_22 ) >> V_232 ) & V_24 ;
if ( V_50 ) {
V_231 -> V_25 . integer . V_25 [ 0 ] =
V_49 - V_231 -> V_25 . integer . V_25 [ 0 ] ;
if ( V_48 != V_232 )
V_231 -> V_25 . integer . V_25 [ 1 ] =
V_49 - V_231 -> V_25 . integer . V_25 [ 1 ] ;
}
return 0 ;
}
int F_124 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_101 * V_102 = F_123 ( V_85 ) ;
struct V_8 * V_114 = V_102 -> V_107 [ 0 ] ;
struct V_209 * V_19 = V_114 -> V_19 ;
struct V_44 * V_45 =
(struct V_44 * ) V_85 -> V_47 ;
unsigned int V_22 = V_45 -> V_22 ;
unsigned int V_48 = V_45 -> V_48 ;
int V_49 = V_45 -> V_49 ;
unsigned int V_24 = ( 1 << F_30 ( V_49 ) ) - 1 ;
unsigned int V_50 = V_45 -> V_50 ;
unsigned int V_23 ;
int V_51 , V_26 ;
struct V_167 V_168 ;
int V_233 ;
V_23 = ( V_231 -> V_25 . integer . V_25 [ 0 ] & V_24 ) ;
if ( V_50 )
V_23 = V_49 - V_23 ;
V_24 = V_24 << V_48 ;
V_23 = V_23 << V_48 ;
if ( V_23 )
V_51 = V_50 ? 0 : 1 ;
else
V_51 = V_50 ? 1 : 0 ;
F_125 ( & V_19 -> V_234 ) ;
V_26 = F_126 ( V_114 -> V_19 , V_22 , V_24 , V_23 ) ;
if ( V_26 ) {
for ( V_233 = 0 ; V_233 < V_102 -> V_106 ; V_233 ++ ) {
V_114 = V_102 -> V_107 [ V_233 ] ;
V_114 -> V_25 = V_23 ;
V_168 . V_85 = V_85 ;
V_168 . V_114 = V_114 ;
V_168 . V_22 = V_22 ;
V_168 . V_24 = V_24 ;
V_168 . V_23 = V_23 ;
V_114 -> V_12 -> V_168 = & V_168 ;
F_105 ( V_114 , V_85 , V_51 ) ;
V_114 -> V_12 -> V_168 = NULL ;
}
}
F_127 ( & V_19 -> V_234 ) ;
return 0 ;
}
int F_128 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_101 * V_102 = F_123 ( V_85 ) ;
struct V_8 * V_114 = V_102 -> V_107 [ 0 ] ;
struct V_53 * V_54 = (struct V_53 * ) V_85 -> V_47 ;
unsigned int V_23 , V_56 ;
for ( V_56 = 1 ; V_56 < V_54 -> V_49 ; V_56 <<= 1 )
;
V_23 = F_19 ( V_114 -> V_19 , V_54 -> V_22 ) ;
V_231 -> V_25 . V_235 . V_55 [ 0 ] = ( V_23 >> V_54 -> V_57 ) & ( V_56 - 1 ) ;
if ( V_54 -> V_57 != V_54 -> V_236 )
V_231 -> V_25 . V_235 . V_55 [ 1 ] =
( V_23 >> V_54 -> V_236 ) & ( V_56 - 1 ) ;
return 0 ;
}
int F_129 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_101 * V_102 = F_123 ( V_85 ) ;
struct V_8 * V_114 = V_102 -> V_107 [ 0 ] ;
struct V_209 * V_19 = V_114 -> V_19 ;
struct V_53 * V_54 = (struct V_53 * ) V_85 -> V_47 ;
unsigned int V_23 , V_203 , V_26 ;
unsigned int V_24 , V_56 ;
struct V_167 V_168 ;
int V_233 ;
for ( V_56 = 1 ; V_56 < V_54 -> V_49 ; V_56 <<= 1 )
;
if ( V_231 -> V_25 . V_235 . V_55 [ 0 ] > V_54 -> V_49 - 1 )
return - V_111 ;
V_203 = V_231 -> V_25 . V_235 . V_55 [ 0 ] ;
V_23 = V_203 << V_54 -> V_57 ;
V_24 = ( V_56 - 1 ) << V_54 -> V_57 ;
if ( V_54 -> V_57 != V_54 -> V_236 ) {
if ( V_231 -> V_25 . V_235 . V_55 [ 1 ] > V_54 -> V_49 - 1 )
return - V_111 ;
V_23 |= V_231 -> V_25 . V_235 . V_55 [ 1 ] << V_54 -> V_236 ;
V_24 |= ( V_56 - 1 ) << V_54 -> V_236 ;
}
F_125 ( & V_19 -> V_234 ) ;
V_26 = F_126 ( V_114 -> V_19 , V_54 -> V_22 , V_24 , V_23 ) ;
if ( V_26 ) {
for ( V_233 = 0 ; V_233 < V_102 -> V_106 ; V_233 ++ ) {
V_114 = V_102 -> V_107 [ V_233 ] ;
V_114 -> V_25 = V_23 ;
V_168 . V_85 = V_85 ;
V_168 . V_114 = V_114 ;
V_168 . V_22 = V_54 -> V_22 ;
V_168 . V_24 = V_24 ;
V_168 . V_23 = V_23 ;
V_114 -> V_12 -> V_168 = & V_168 ;
F_104 ( V_114 , V_85 , V_26 , V_203 , V_54 ) ;
V_114 -> V_12 -> V_168 = NULL ;
}
}
F_127 ( & V_19 -> V_234 ) ;
return V_26 ;
}
int F_130 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_101 * V_102 = F_123 ( V_85 ) ;
struct V_8 * V_114 = V_102 -> V_107 [ 0 ] ;
V_231 -> V_25 . V_235 . V_55 [ 0 ] = V_114 -> V_25 ;
return 0 ;
}
int F_131 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_101 * V_102 = F_123 ( V_85 ) ;
struct V_8 * V_114 = V_102 -> V_107 [ 0 ] ;
struct V_209 * V_19 = V_114 -> V_19 ;
struct V_53 * V_54 =
(struct V_53 * ) V_85 -> V_47 ;
int V_26 ;
int V_29 = 0 ;
int V_233 ;
if ( V_231 -> V_25 . V_235 . V_55 [ 0 ] >= V_54 -> V_49 )
return - V_111 ;
F_125 ( & V_19 -> V_234 ) ;
V_26 = V_114 -> V_25 != V_231 -> V_25 . V_235 . V_55 [ 0 ] ;
if ( V_26 ) {
for ( V_233 = 0 ; V_233 < V_102 -> V_106 ; V_233 ++ ) {
V_114 = V_102 -> V_107 [ V_233 ] ;
V_114 -> V_25 = V_231 -> V_25 . V_235 . V_55 [ 0 ] ;
F_104 ( V_114 , V_85 , V_26 ,
V_114 -> V_25 , V_54 ) ;
}
}
F_127 ( & V_19 -> V_234 ) ;
return V_29 ;
}
int F_132 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_101 * V_102 = F_123 ( V_85 ) ;
struct V_8 * V_114 = V_102 -> V_107 [ 0 ] ;
struct V_53 * V_54 = (struct V_53 * ) V_85 -> V_47 ;
unsigned int V_237 , V_23 , V_203 ;
V_237 = F_19 ( V_114 -> V_19 , V_54 -> V_22 ) ;
V_23 = ( V_237 >> V_54 -> V_57 ) & V_54 -> V_24 ;
for ( V_203 = 0 ; V_203 < V_54 -> V_49 ; V_203 ++ ) {
if ( V_23 == V_54 -> V_61 [ V_203 ] )
break;
}
V_231 -> V_25 . V_235 . V_55 [ 0 ] = V_203 ;
if ( V_54 -> V_57 != V_54 -> V_236 ) {
V_23 = ( V_237 >> V_54 -> V_236 ) & V_54 -> V_24 ;
for ( V_203 = 0 ; V_203 < V_54 -> V_49 ; V_203 ++ ) {
if ( V_23 == V_54 -> V_61 [ V_203 ] )
break;
}
V_231 -> V_25 . V_235 . V_55 [ 1 ] = V_203 ;
}
return 0 ;
}
int F_133 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_101 * V_102 = F_123 ( V_85 ) ;
struct V_8 * V_114 = V_102 -> V_107 [ 0 ] ;
struct V_209 * V_19 = V_114 -> V_19 ;
struct V_53 * V_54 = (struct V_53 * ) V_85 -> V_47 ;
unsigned int V_23 , V_203 , V_26 ;
unsigned int V_24 ;
struct V_167 V_168 ;
int V_233 ;
if ( V_231 -> V_25 . V_235 . V_55 [ 0 ] > V_54 -> V_49 - 1 )
return - V_111 ;
V_203 = V_231 -> V_25 . V_235 . V_55 [ 0 ] ;
V_23 = V_54 -> V_61 [ V_231 -> V_25 . V_235 . V_55 [ 0 ] ] << V_54 -> V_57 ;
V_24 = V_54 -> V_24 << V_54 -> V_57 ;
if ( V_54 -> V_57 != V_54 -> V_236 ) {
if ( V_231 -> V_25 . V_235 . V_55 [ 1 ] > V_54 -> V_49 - 1 )
return - V_111 ;
V_23 |= V_54 -> V_61 [ V_231 -> V_25 . V_235 . V_55 [ 1 ] ] << V_54 -> V_236 ;
V_24 |= V_54 -> V_24 << V_54 -> V_236 ;
}
F_125 ( & V_19 -> V_234 ) ;
V_26 = F_126 ( V_114 -> V_19 , V_54 -> V_22 , V_24 , V_23 ) ;
if ( V_26 ) {
for ( V_233 = 0 ; V_233 < V_102 -> V_106 ; V_233 ++ ) {
V_114 = V_102 -> V_107 [ V_233 ] ;
V_114 -> V_25 = V_23 ;
V_168 . V_85 = V_85 ;
V_168 . V_114 = V_114 ;
V_168 . V_22 = V_54 -> V_22 ;
V_168 . V_24 = V_24 ;
V_168 . V_23 = V_23 ;
V_114 -> V_12 -> V_168 = & V_168 ;
F_104 ( V_114 , V_85 , V_26 , V_203 , V_54 ) ;
V_114 -> V_12 -> V_168 = NULL ;
}
}
F_127 ( & V_19 -> V_234 ) ;
return V_26 ;
}
int F_134 ( struct V_96 * V_85 ,
struct V_238 * V_239 )
{
V_239 -> type = V_240 ;
V_239 -> V_194 = 1 ;
V_239 -> V_25 . integer . V_241 = 0 ;
V_239 -> V_25 . integer . V_49 = 1 ;
return 0 ;
}
int F_135 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_209 * V_19 = F_123 ( V_85 ) ;
const char * V_214 = ( const char * ) V_85 -> V_47 ;
F_125 ( & V_19 -> V_234 ) ;
V_231 -> V_25 . integer . V_25 [ 0 ] =
F_136 ( & V_19 -> V_12 , V_214 ) ;
F_127 ( & V_19 -> V_234 ) ;
return 0 ;
}
int F_137 ( struct V_96 * V_85 ,
struct V_230 * V_231 )
{
struct V_209 * V_19 = F_123 ( V_85 ) ;
const char * V_214 = ( const char * ) V_85 -> V_47 ;
F_125 ( & V_19 -> V_234 ) ;
if ( V_231 -> V_25 . integer . V_25 [ 0 ] )
F_138 ( & V_19 -> V_12 , V_214 ) ;
else
F_139 ( & V_19 -> V_12 , V_214 ) ;
F_116 ( & V_19 -> V_12 ) ;
F_127 ( & V_19 -> V_234 ) ;
return 0 ;
}
int F_140 ( struct V_18 * V_12 ,
const struct V_8 * V_114 )
{
struct V_8 * V_9 ;
T_3 V_98 ;
if ( ( V_9 = F_13 ( V_114 ) ) == NULL )
return - V_105 ;
V_98 = strlen ( V_114 -> V_13 ) + 1 ;
if ( V_12 -> V_19 && V_12 -> V_19 -> V_104 )
V_98 += 1 + strlen ( V_12 -> V_19 -> V_104 ) ;
V_9 -> V_13 = F_5 ( V_98 , V_7 ) ;
if ( V_9 -> V_13 == NULL ) {
F_7 ( V_9 ) ;
return - V_105 ;
}
if ( V_12 -> V_19 && V_12 -> V_19 -> V_104 )
snprintf ( V_9 -> V_13 , V_98 , L_6 ,
V_12 -> V_19 -> V_104 , V_114 -> V_13 ) ;
else
snprintf ( V_9 -> V_13 , V_98 , L_1 , V_114 -> V_13 ) ;
switch ( V_9 -> V_40 ) {
case V_41 :
case V_42 :
case V_43 :
V_9 -> V_135 = F_53 ;
break;
case V_52 :
case V_59 :
case V_60 :
V_9 -> V_135 = F_53 ;
break;
case V_65 :
case V_73 :
V_9 -> V_135 = F_54 ;
break;
case V_68 :
case V_72 :
V_9 -> V_135 = F_55 ;
break;
case V_62 :
case V_63 :
case V_66 :
case V_64 :
case V_69 :
case V_76 :
case V_74 :
case V_75 :
case V_77 :
V_9 -> V_135 = F_53 ;
break;
case V_71 :
V_9 -> V_135 = F_56 ;
break;
default:
V_9 -> V_135 = F_57 ;
break;
}
V_12 -> V_184 ++ ;
V_9 -> V_12 = V_12 ;
V_9 -> V_19 = V_12 -> V_19 ;
V_9 -> V_20 = V_12 -> V_20 ;
F_71 ( & V_9 -> V_89 ) ;
F_71 ( & V_9 -> V_91 ) ;
F_71 ( & V_9 -> V_86 ) ;
F_71 ( & V_9 -> V_10 ) ;
F_32 ( & V_9 -> V_86 , & V_12 -> V_14 -> V_107 ) ;
V_9 -> V_122 = 1 ;
return 0 ;
}
int F_141 ( struct V_18 * V_12 ,
const struct V_8 * V_114 ,
int V_229 )
{
int V_39 , V_29 ;
for ( V_39 = 0 ; V_39 < V_229 ; V_39 ++ ) {
V_29 = F_140 ( V_12 , V_114 ) ;
if ( V_29 < 0 ) {
F_21 ( V_12 -> V_3 ,
L_72 ,
V_114 -> V_13 , V_29 ) ;
return V_29 ;
}
V_114 ++ ;
}
return 0 ;
}
static void F_142 ( struct V_18 * V_12 ,
const char * V_242 , int V_129 )
{
struct V_8 * V_9 ;
F_35 (w, &dapm->card->widgets, list)
{
if ( ! V_9 -> V_196 || V_9 -> V_12 != V_12 )
continue;
F_11 ( V_9 -> V_12 -> V_3 , L_73 ,
V_9 -> V_13 , V_9 -> V_196 , V_242 , V_129 ) ;
if ( strstr ( V_9 -> V_196 , V_242 ) ) {
F_10 ( V_9 , L_74 ) ;
switch( V_129 ) {
case V_165 :
V_9 -> V_121 = 1 ;
break;
case V_166 :
V_9 -> V_121 = 0 ;
break;
case V_188 :
case V_187 :
case V_243 :
case V_244 :
break;
}
}
}
F_84 ( V_12 , V_129 ) ;
if ( V_12 -> V_245 )
V_12 -> V_245 ( V_12 , V_129 ) ;
}
int F_143 ( struct V_207 * V_208 ,
const char * V_242 , int V_129 )
{
struct V_209 * V_19 = V_208 -> V_19 ;
if ( V_242 == NULL )
return 0 ;
F_125 ( & V_19 -> V_234 ) ;
F_142 ( & V_19 -> V_12 , V_242 , V_129 ) ;
F_127 ( & V_19 -> V_234 ) ;
return 0 ;
}
int F_138 ( struct V_18 * V_12 , const char * V_214 )
{
return F_115 ( V_12 , V_214 , 1 ) ;
}
int F_144 ( struct V_18 * V_12 ,
const char * V_214 )
{
struct V_8 * V_9 = F_114 ( V_12 , V_214 , true ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_62 , V_214 ) ;
return - V_111 ;
}
F_46 ( V_9 -> V_12 -> V_3 , L_75 , V_214 ) ;
V_9 -> V_122 = 1 ;
V_9 -> V_134 = 1 ;
F_10 ( V_9 , L_76 ) ;
return 0 ;
}
int F_139 ( struct V_18 * V_12 ,
const char * V_214 )
{
return F_115 ( V_12 , V_214 , 0 ) ;
}
int F_145 ( struct V_18 * V_12 , const char * V_214 )
{
return F_115 ( V_12 , V_214 , 0 ) ;
}
int F_136 ( struct V_18 * V_12 ,
const char * V_214 )
{
struct V_8 * V_9 = F_114 ( V_12 , V_214 , true ) ;
if ( V_9 )
return V_9 -> V_122 ;
return 0 ;
}
int F_146 ( struct V_18 * V_12 ,
const char * V_214 )
{
struct V_8 * V_9 = F_114 ( V_12 , V_214 , false ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_62 , V_214 ) ;
return - V_111 ;
}
V_9 -> V_117 = 1 ;
return 0 ;
}
static bool F_147 ( struct V_21 * V_14 ,
struct V_8 * V_9 )
{
struct V_37 * V_38 ;
F_35 (p, &card->paths, list) {
if ( ( V_38 -> V_128 == V_9 ) || ( V_38 -> V_126 == V_9 ) ) {
F_46 ( V_14 -> V_3 ,
L_77 ,
V_38 -> V_128 -> V_13 , V_38 -> V_128 -> V_40 , V_38 -> V_128 -> V_12 ,
V_38 -> V_126 -> V_13 , V_38 -> V_126 -> V_40 , V_38 -> V_126 -> V_12 ) ;
if ( V_38 -> V_128 -> V_12 != V_38 -> V_126 -> V_12 )
return true ;
if ( V_38 -> V_126 -> V_40 == V_66 ) {
switch ( V_38 -> V_128 -> V_40 ) {
case V_64 :
case V_69 :
return true ;
default:
break;
}
}
}
}
return false ;
}
void F_148 ( struct V_209 * V_19 )
{
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_18 * V_12 = & V_19 -> V_12 ;
struct V_8 * V_9 ;
F_46 ( V_19 -> V_3 , L_78 ,
& V_14 -> V_12 , & V_19 -> V_12 ) ;
F_35 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
switch ( V_9 -> V_40 ) {
case V_66 :
case V_64 :
case V_69 :
F_46 ( V_19 -> V_3 , L_79 ,
V_9 -> V_13 ) ;
if ( ! F_147 ( V_14 , V_9 ) ) {
F_46 ( V_19 -> V_3 ,
L_80 ) ;
F_145 ( V_12 , V_9 -> V_13 ) ;
}
break;
default:
break;
}
}
}
void F_149 ( struct V_18 * V_12 )
{
F_110 ( V_12 -> V_3 ) ;
F_102 ( V_12 ) ;
F_112 ( V_12 ) ;
F_113 ( & V_12 -> V_86 ) ;
}
static void F_150 ( struct V_18 * V_12 )
{
struct V_8 * V_9 ;
F_68 ( V_181 ) ;
int V_246 = 0 ;
F_35 (w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
if ( V_9 -> V_149 ) {
F_59 ( V_9 , & V_181 , false ) ;
V_9 -> V_149 = 0 ;
V_246 = 1 ;
}
}
if ( V_246 ) {
if ( V_12 -> V_35 == V_178 )
F_26 ( V_12 ,
V_177 ) ;
F_67 ( V_12 , & V_181 , 0 , false ) ;
if ( V_12 -> V_35 == V_177 )
F_26 ( V_12 ,
V_176 ) ;
}
}
void F_151 ( struct V_21 * V_14 )
{
struct V_209 * V_19 ;
F_35 (codec, &card->codec_dev_list, list) {
F_150 ( & V_19 -> V_12 ) ;
if ( V_19 -> V_12 . V_35 == V_176 )
F_26 ( & V_19 -> V_12 ,
V_174 ) ;
}
}
