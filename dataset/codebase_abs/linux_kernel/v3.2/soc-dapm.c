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
V_38 -> V_51 = 1 ;
break;
case V_77 :
case V_78 :
V_38 -> V_51 = 0 ;
break;
}
}
static int F_31 ( struct V_18 * V_12 ,
struct V_8 * V_79 , struct V_8 * V_80 ,
struct V_37 * V_81 , const char * V_82 ,
const struct V_83 * V_84 )
{
struct V_53 * V_54 = (struct V_53 * ) V_84 -> V_47 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_54 -> V_49 ; V_39 ++ ) {
if ( ! ( strcmp ( V_82 , V_54 -> V_58 [ V_39 ] ) ) ) {
F_32 ( & V_81 -> V_85 , & V_12 -> V_14 -> V_86 ) ;
F_32 ( & V_81 -> V_87 , & V_80 -> V_88 ) ;
F_32 ( & V_81 -> V_89 , & V_79 -> V_90 ) ;
V_81 -> V_13 = ( char * ) V_54 -> V_58 [ V_39 ] ;
F_29 ( V_80 , V_81 , 0 ) ;
return 0 ;
}
}
return - V_91 ;
}
static int F_33 ( struct V_18 * V_12 ,
struct V_8 * V_79 , struct V_8 * V_80 ,
struct V_37 * V_81 , const char * V_82 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_80 -> V_92 ; V_39 ++ ) {
if ( ! strcmp ( V_82 , V_80 -> V_46 [ V_39 ] . V_13 ) ) {
F_32 ( & V_81 -> V_85 , & V_12 -> V_14 -> V_86 ) ;
F_32 ( & V_81 -> V_87 , & V_80 -> V_88 ) ;
F_32 ( & V_81 -> V_89 , & V_79 -> V_90 ) ;
V_81 -> V_13 = V_80 -> V_46 [ V_39 ] . V_13 ;
F_29 ( V_80 , V_81 , V_39 ) ;
return 0 ;
}
}
return - V_91 ;
}
static int F_34 ( struct V_18 * V_12 ,
struct V_8 * V_93 ,
const struct V_83 * V_94 ,
struct V_95 * * V_84 )
{
struct V_8 * V_9 ;
int V_39 ;
* V_84 = NULL ;
F_35 (w, &dapm->card->widgets, list) {
if ( V_9 == V_93 || V_9 -> V_12 != V_93 -> V_12 )
continue;
for ( V_39 = 0 ; V_39 < V_9 -> V_92 ; V_39 ++ ) {
if ( & V_9 -> V_46 [ V_39 ] == V_94 ) {
if ( V_9 -> V_96 )
* V_84 = V_9 -> V_96 [ V_39 ] ;
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
T_3 V_97 , V_98 ;
struct V_37 * V_81 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_99 ;
struct V_100 * V_101 ;
T_3 V_102 ;
if ( V_12 -> V_19 )
V_99 = V_12 -> V_19 -> V_103 ;
else
V_99 = NULL ;
if ( V_99 )
V_98 = strlen ( V_99 ) + 1 ;
else
V_98 = 0 ;
for ( V_39 = 0 ; V_39 < V_9 -> V_92 ; V_39 ++ ) {
F_35 (path, &w->sources, list_sink) {
if ( V_81 -> V_13 != ( char * ) V_9 -> V_46 [ V_39 ] . V_13 )
continue;
if ( V_9 -> V_96 [ V_39 ] ) {
V_81 -> V_84 = V_9 -> V_96 [ V_39 ] ;
continue;
}
V_102 = sizeof( struct V_100 ) +
sizeof( struct V_8 * ) ,
V_101 = F_37 ( V_102 , V_7 ) ;
if ( V_101 == NULL ) {
F_21 ( V_12 -> V_3 ,
L_5 ,
V_9 -> V_13 ) ;
return - V_104 ;
}
V_101 -> V_105 = 1 ;
V_101 -> V_106 [ 0 ] = V_9 ;
V_97 = strlen ( V_9 -> V_46 [ V_39 ] . V_13 ) + 1 ;
if ( V_9 -> V_40 != V_43 )
V_97 += 1 + strlen ( V_9 -> V_13 ) ;
V_81 -> V_107 = F_5 ( V_97 , V_7 ) ;
if ( V_81 -> V_107 == NULL ) {
F_7 ( V_101 ) ;
return - V_104 ;
}
switch ( V_9 -> V_40 ) {
default:
snprintf ( V_81 -> V_107 , V_97 , L_6 ,
V_9 -> V_13 + V_98 ,
V_9 -> V_46 [ V_39 ] . V_13 ) ;
break;
case V_43 :
snprintf ( V_81 -> V_107 , V_97 , L_1 ,
V_9 -> V_46 [ V_39 ] . V_13 ) ;
break;
}
V_81 -> V_107 [ V_97 - 1 ] = '\0' ;
V_81 -> V_84 = F_38 ( & V_9 -> V_46 [ V_39 ] ,
V_101 , V_81 -> V_107 ,
V_99 ) ;
V_29 = F_39 ( V_14 , V_81 -> V_84 ) ;
if ( V_29 < 0 ) {
F_21 ( V_12 -> V_3 ,
L_7 ,
V_81 -> V_107 , V_29 ) ;
F_7 ( V_101 ) ;
F_7 ( V_81 -> V_107 ) ;
V_81 -> V_107 = NULL ;
return V_29 ;
}
V_9 -> V_96 [ V_39 ] = V_81 -> V_84 ;
}
}
return V_29 ;
}
static int F_40 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_37 * V_81 = NULL ;
struct V_95 * V_84 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_99 ;
T_3 V_98 ;
int V_29 ;
struct V_100 * V_101 ;
int V_108 , V_109 ;
T_3 V_102 ;
char * V_13 ;
if ( V_9 -> V_92 != 1 ) {
F_21 ( V_12 -> V_3 ,
L_8 ,
V_9 -> V_13 ) ;
return - V_110 ;
}
V_108 = F_34 ( V_12 , V_9 , & V_9 -> V_46 [ 0 ] ,
& V_84 ) ;
if ( V_84 ) {
V_101 = V_84 -> V_111 ;
V_109 = V_101 -> V_105 + 1 ;
} else {
V_101 = NULL ;
V_109 = 1 ;
}
V_102 = sizeof( struct V_100 ) +
V_109 * sizeof( struct V_8 * ) ,
V_101 = F_41 ( V_101 , V_102 , V_7 ) ;
if ( V_101 == NULL ) {
F_21 ( V_12 -> V_3 ,
L_5 , V_9 -> V_13 ) ;
return - V_104 ;
}
V_101 -> V_105 = V_109 ;
V_101 -> V_106 [ V_109 - 1 ] = V_9 ;
if ( ! V_84 ) {
if ( V_12 -> V_19 )
V_99 = V_12 -> V_19 -> V_103 ;
else
V_99 = NULL ;
if ( V_108 ) {
V_13 = V_9 -> V_46 [ 0 ] . V_13 ;
V_98 = 0 ;
} else {
V_13 = V_9 -> V_13 ;
if ( V_99 )
V_98 = strlen ( V_99 ) + 1 ;
else
V_98 = 0 ;
}
V_84 = F_38 ( & V_9 -> V_46 [ 0 ] , V_101 ,
V_13 + V_98 , V_99 ) ;
V_29 = F_39 ( V_14 , V_84 ) ;
if ( V_29 < 0 ) {
F_21 ( V_12 -> V_3 , L_9 ,
V_9 -> V_13 , V_29 ) ;
F_7 ( V_101 ) ;
return V_29 ;
}
}
V_84 -> V_111 = V_101 ;
V_9 -> V_96 [ 0 ] = V_84 ;
F_35 (path, &w->sources, list_sink)
V_81 -> V_84 = V_84 ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 )
{
if ( V_9 -> V_92 )
F_21 ( V_9 -> V_12 -> V_3 ,
L_10 , V_9 -> V_13 ) ;
return 0 ;
}
static inline void F_43 ( struct V_18 * V_12 )
{
struct V_37 * V_38 ;
F_35 (p, &dapm->card->paths, list)
V_38 -> V_112 = 0 ;
}
static int F_44 ( struct V_8 * V_113 )
{
int V_31 = F_45 ( V_113 -> V_12 -> V_14 -> V_17 ) ;
switch ( V_31 ) {
case V_114 :
case V_115 :
if ( V_113 -> V_116 )
F_46 ( V_113 -> V_12 -> V_3 , L_11 ,
V_113 -> V_13 ) ;
return V_113 -> V_116 ;
default:
return 1 ;
}
}
static int F_47 ( struct V_8 * V_113 )
{
struct V_37 * V_81 ;
int V_117 = 0 ;
if ( V_113 -> V_118 >= 0 )
return V_113 -> V_118 ;
F_48 ( V_113 , V_119 ) ;
if ( V_113 -> V_40 == V_70 )
return 0 ;
switch ( V_113 -> V_40 ) {
case V_65 :
case V_72 :
if ( V_113 -> V_120 ) {
V_113 -> V_118 = F_44 ( V_113 ) ;
return V_113 -> V_118 ;
}
default:
break;
}
if ( V_113 -> V_121 ) {
if ( V_113 -> V_40 == V_64 && ! V_113 -> V_122 ) {
V_113 -> V_118 = F_44 ( V_113 ) ;
return V_113 -> V_118 ;
}
if ( V_113 -> V_40 == V_73 ||
V_113 -> V_40 == V_75 ||
( V_113 -> V_40 == V_76 &&
! F_9 ( & V_113 -> V_88 ) ) ) {
V_113 -> V_118 = F_44 ( V_113 ) ;
return V_113 -> V_118 ;
}
}
F_35 (path, &widget->sinks, list_source) {
F_48 ( V_113 , V_123 ) ;
if ( V_81 -> V_124 )
continue;
if ( V_81 -> V_112 )
continue;
if ( V_81 -> V_125 && V_81 -> V_51 ) {
V_81 -> V_112 = 1 ;
V_117 += F_47 ( V_81 -> V_125 ) ;
}
}
V_113 -> V_118 = V_117 ;
return V_117 ;
}
static int F_49 ( struct V_8 * V_113 )
{
struct V_37 * V_81 ;
int V_117 = 0 ;
if ( V_113 -> V_126 >= 0 )
return V_113 -> V_126 ;
F_48 ( V_113 , V_119 ) ;
if ( V_113 -> V_40 == V_70 )
return 0 ;
switch ( V_113 -> V_40 ) {
case V_67 :
case V_71 :
if ( V_113 -> V_120 ) {
V_113 -> V_126 = F_44 ( V_113 ) ;
return V_113 -> V_126 ;
}
default:
break;
}
if ( V_113 -> V_121 ) {
if ( V_113 -> V_40 == V_66 && ! V_113 -> V_122 ) {
V_113 -> V_126 = F_44 ( V_113 ) ;
return V_113 -> V_126 ;
}
if ( V_113 -> V_40 == V_69 ) {
V_113 -> V_126 = F_44 ( V_113 ) ;
return V_113 -> V_126 ;
}
if ( V_113 -> V_40 == V_74 ||
( V_113 -> V_40 == V_76 &&
! F_9 ( & V_113 -> V_90 ) ) ) {
V_113 -> V_126 = F_44 ( V_113 ) ;
return V_113 -> V_126 ;
}
}
F_35 (path, &widget->sources, list_sink) {
F_48 ( V_113 , V_123 ) ;
if ( V_81 -> V_124 )
continue;
if ( V_81 -> V_112 )
continue;
if ( V_81 -> V_127 && V_81 -> V_51 ) {
V_81 -> V_112 = 1 ;
V_117 += F_49 ( V_81 -> V_127 ) ;
}
}
V_113 -> V_126 = V_117 ;
return V_117 ;
}
int F_50 ( struct V_8 * V_9 ,
struct V_95 * V_84 , int V_128 )
{
unsigned int V_23 ;
if ( F_51 ( V_128 ) )
V_23 = V_9 -> V_129 ;
else
V_23 = V_9 -> V_130 ;
F_25 ( V_9 , - ( V_9 -> V_22 + 1 ) ,
V_9 -> V_24 << V_9 -> V_48 , V_23 << V_9 -> V_48 ) ;
return 0 ;
}
static int F_52 ( struct V_8 * V_9 )
{
if ( V_9 -> V_131 )
return V_9 -> V_132 ;
if ( V_9 -> V_133 )
V_9 -> V_132 = 1 ;
else
V_9 -> V_132 = V_9 -> V_134 ( V_9 ) ;
V_9 -> V_131 = true ;
return V_9 -> V_132 ;
}
static int F_53 ( struct V_8 * V_9 )
{
int V_135 , V_33 ;
F_48 ( V_9 , V_136 ) ;
V_135 = F_49 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
V_33 = F_47 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
return V_33 != 0 && V_135 != 0 ;
}
static int F_54 ( struct V_8 * V_9 )
{
int V_135 ;
F_48 ( V_9 , V_136 ) ;
if ( V_9 -> V_120 ) {
V_135 = F_49 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
return V_135 != 0 ;
} else {
return F_53 ( V_9 ) ;
}
}
static int F_55 ( struct V_8 * V_9 )
{
int V_33 ;
F_48 ( V_9 , V_136 ) ;
if ( V_9 -> V_120 ) {
V_33 = F_47 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
return V_33 != 0 ;
} else {
return F_53 ( V_9 ) ;
}
}
static int F_56 ( struct V_8 * V_9 )
{
struct V_37 * V_81 ;
F_48 ( V_9 , V_136 ) ;
F_35 (path, &w->sinks, list_source) {
F_48 ( V_9 , V_123 ) ;
if ( V_81 -> V_124 )
continue;
if ( V_81 -> V_121 &&
! V_81 -> V_121 ( V_81 -> V_127 , V_81 -> V_125 ) )
continue;
if ( ! V_81 -> V_125 )
continue;
if ( F_52 ( V_81 -> V_125 ) )
return 1 ;
}
F_43 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_57 ( struct V_8 * V_9 )
{
return 1 ;
}
static int F_58 ( struct V_8 * V_137 ,
struct V_8 * V_138 ,
bool V_139 )
{
int * V_140 ;
if ( V_139 )
V_140 = V_141 ;
else
V_140 = V_142 ;
if ( V_140 [ V_137 -> V_40 ] != V_140 [ V_138 -> V_40 ] )
return V_140 [ V_137 -> V_40 ] - V_140 [ V_138 -> V_40 ] ;
if ( V_137 -> V_143 != V_138 -> V_143 ) {
if ( V_139 )
return V_137 -> V_143 - V_138 -> V_143 ;
else
return V_138 -> V_143 - V_137 -> V_143 ;
}
if ( V_137 -> V_22 != V_138 -> V_22 )
return V_137 -> V_22 - V_138 -> V_22 ;
if ( V_137 -> V_12 != V_138 -> V_12 )
return ( unsigned long ) V_137 -> V_12 - ( unsigned long ) V_138 -> V_12 ;
return 0 ;
}
static void F_59 ( struct V_8 * V_144 ,
struct V_145 * V_85 ,
bool V_139 )
{
struct V_8 * V_9 ;
F_35 (w, list, power_list)
if ( F_58 ( V_144 , V_9 , V_139 ) < 0 ) {
F_12 ( & V_144 -> V_146 , & V_9 -> V_146 ) ;
return;
}
F_12 ( & V_144 -> V_146 , V_85 ) ;
}
static void F_60 ( struct V_18 * V_12 ,
struct V_8 * V_9 , int V_128 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
const char * V_147 ;
int V_148 , V_29 ;
switch ( V_128 ) {
case V_149 :
V_147 = L_12 ;
V_148 = 1 ;
break;
case V_150 :
V_147 = L_13 ;
V_148 = 1 ;
break;
case V_151 :
V_147 = L_14 ;
V_148 = 0 ;
break;
case V_152 :
V_147 = L_15 ;
V_148 = 0 ;
break;
default:
F_16 () ;
return;
}
if ( V_9 -> V_148 != V_148 )
return;
if ( V_9 -> V_128 && ( V_9 -> V_153 & V_128 ) ) {
F_4 ( V_12 -> V_3 , V_14 -> V_1 , L_16 ,
V_9 -> V_13 , V_147 ) ;
F_61 ( V_9 , V_128 ) ;
V_29 = V_9 -> V_128 ( V_9 , NULL , V_128 ) ;
F_62 ( V_9 , V_128 ) ;
if ( V_29 < 0 )
F_63 ( L_17 ,
V_147 , V_9 -> V_13 , V_29 ) ;
}
}
static void F_64 ( struct V_18 * V_12 ,
struct V_145 * V_154 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
int V_22 , V_148 ;
unsigned int V_25 = 0 ;
unsigned int V_24 = 0 ;
unsigned int V_155 ;
V_22 = F_65 ( V_154 , struct V_8 ,
V_146 ) -> V_22 ;
F_35 (w, pending, power_list) {
V_155 = 1 << V_9 -> V_48 ;
F_66 ( V_22 != V_9 -> V_22 ) ;
if ( V_9 -> V_50 )
V_148 = ! V_9 -> V_148 ;
else
V_148 = V_9 -> V_148 ;
V_24 |= V_155 ;
if ( V_148 )
V_25 |= V_155 ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_18 ,
V_9 -> V_13 , V_22 , V_25 , V_24 ) ;
F_60 ( V_12 , V_9 , V_149 ) ;
F_60 ( V_12 , V_9 , V_151 ) ;
}
if ( V_22 >= 0 ) {
V_9 = F_65 ( V_154 , struct V_8 ,
V_146 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_19 ,
V_25 , V_24 , V_22 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_25 ( V_9 , V_22 , V_24 , V_25 ) ;
}
F_35 (w, pending, power_list) {
F_60 ( V_12 , V_9 , V_150 ) ;
F_60 ( V_12 , V_9 , V_152 ) ;
}
}
static void F_67 ( struct V_18 * V_12 ,
struct V_145 * V_85 , int V_128 , bool V_139 )
{
struct V_8 * V_9 , * V_156 ;
F_68 ( V_154 ) ;
int V_157 = - 1 ;
int V_158 = - 1 ;
int V_159 = V_160 ;
struct V_18 * V_161 = NULL ;
int V_29 , V_39 ;
int * V_140 ;
if ( V_139 )
V_140 = V_141 ;
else
V_140 = V_142 ;
F_69 (w, n, list, power_list) {
V_29 = 0 ;
if ( V_140 [ V_9 -> V_40 ] != V_157 || V_9 -> V_22 != V_159 ||
V_9 -> V_12 != V_161 || V_9 -> V_143 != V_158 ) {
if ( ! F_9 ( & V_154 ) )
F_64 ( V_161 , & V_154 ) ;
if ( V_161 && V_161 -> V_162 ) {
for ( V_39 = 0 ; V_39 < F_70 ( V_141 ) ; V_39 ++ )
if ( V_140 [ V_39 ] == V_157 )
V_161 -> V_162 ( V_161 ,
V_39 ,
V_158 ) ;
}
F_71 ( & V_154 ) ;
V_157 = - 1 ;
V_158 = V_163 ;
V_159 = V_160 ;
V_161 = NULL ;
}
switch ( V_9 -> V_40 ) {
case V_77 :
if ( ! V_9 -> V_128 )
F_72 ( V_9 , V_156 , V_85 ,
V_146 ) ;
if ( V_128 == V_164 )
V_29 = V_9 -> V_128 ( V_9 ,
NULL , V_149 ) ;
else if ( V_128 == V_165 )
V_29 = V_9 -> V_128 ( V_9 ,
NULL , V_151 ) ;
break;
case V_78 :
if ( ! V_9 -> V_128 )
F_72 ( V_9 , V_156 , V_85 ,
V_146 ) ;
if ( V_128 == V_164 )
V_29 = V_9 -> V_128 ( V_9 ,
NULL , V_150 ) ;
else if ( V_128 == V_165 )
V_29 = V_9 -> V_128 ( V_9 ,
NULL , V_152 ) ;
break;
default:
V_157 = V_140 [ V_9 -> V_40 ] ;
V_158 = V_9 -> V_143 ;
V_159 = V_9 -> V_22 ;
V_161 = V_9 -> V_12 ;
F_73 ( & V_9 -> V_146 , & V_154 ) ;
break;
}
if ( V_29 < 0 )
F_21 ( V_9 -> V_12 -> V_3 ,
L_20 , V_29 ) ;
}
if ( ! F_9 ( & V_154 ) )
F_64 ( V_161 , & V_154 ) ;
if ( V_161 && V_161 -> V_162 ) {
for ( V_39 = 0 ; V_39 < F_70 ( V_141 ) ; V_39 ++ )
if ( V_140 [ V_39 ] == V_157 )
V_161 -> V_162 ( V_161 ,
V_39 , V_158 ) ;
}
}
static void F_74 ( struct V_18 * V_12 )
{
struct V_166 * V_167 = V_12 -> V_167 ;
struct V_8 * V_9 ;
int V_29 ;
if ( ! V_167 )
return;
V_9 = V_167 -> V_113 ;
if ( V_9 -> V_128 &&
( V_9 -> V_153 & V_168 ) ) {
V_29 = V_9 -> V_128 ( V_9 , V_167 -> V_84 , V_168 ) ;
if ( V_29 != 0 )
F_63 ( L_21 ,
V_9 -> V_13 , V_29 ) ;
}
V_29 = F_75 ( V_9 -> V_19 , V_167 -> V_22 , V_167 -> V_24 ,
V_167 -> V_23 ) ;
if ( V_29 < 0 )
F_63 ( L_22 , V_9 -> V_13 , V_29 ) ;
if ( V_9 -> V_128 &&
( V_9 -> V_153 & V_169 ) ) {
V_29 = V_9 -> V_128 ( V_9 , V_167 -> V_84 , V_169 ) ;
if ( V_29 != 0 )
F_63 ( L_23 ,
V_9 -> V_13 , V_29 ) ;
}
}
static void F_76 ( void * V_170 , T_4 V_171 )
{
struct V_18 * V_172 = V_170 ;
int V_29 ;
if ( V_172 -> V_35 == V_173 &&
V_172 -> V_174 != V_173 ) {
V_29 = F_26 ( V_172 , V_175 ) ;
if ( V_29 != 0 )
F_21 ( V_172 -> V_3 ,
L_24 , V_29 ) ;
}
if ( V_172 -> V_35 != V_172 -> V_174 ) {
V_29 = F_26 ( V_172 , V_176 ) ;
if ( V_29 != 0 )
F_21 ( V_172 -> V_3 ,
L_25 , V_29 ) ;
}
}
static void F_77 ( void * V_170 , T_4 V_171 )
{
struct V_18 * V_172 = V_170 ;
int V_29 ;
if ( V_172 -> V_35 == V_176 &&
( V_172 -> V_174 == V_175 ||
V_172 -> V_174 == V_173 ) ) {
V_29 = F_26 ( V_172 , V_175 ) ;
if ( V_29 != 0 )
F_21 ( V_172 -> V_3 , L_26 ,
V_29 ) ;
}
if ( V_172 -> V_35 == V_175 &&
V_172 -> V_174 == V_173 ) {
V_29 = F_26 ( V_172 , V_173 ) ;
if ( V_29 != 0 )
F_21 ( V_172 -> V_3 , L_27 , V_29 ) ;
}
if ( V_172 -> V_35 == V_176 &&
V_172 -> V_174 == V_177 ) {
V_29 = F_26 ( V_172 , V_177 ) ;
if ( V_29 != 0 )
F_21 ( V_172 -> V_3 , L_28 ,
V_29 ) ;
}
}
static void F_78 ( struct V_8 * V_178 ,
bool V_148 , bool V_51 )
{
if ( ! V_51 )
return;
if ( V_148 != V_178 -> V_148 )
F_10 ( V_178 , L_29 ) ;
}
static void F_79 ( struct V_8 * V_9 , bool V_148 ,
struct V_145 * V_179 ,
struct V_145 * V_180 )
{
struct V_37 * V_81 ;
if ( V_9 -> V_148 == V_148 )
return;
F_80 ( V_9 , V_148 ) ;
F_35 (path, &w->sources, list_sink) {
if ( V_81 -> V_127 ) {
F_78 ( V_81 -> V_127 , V_148 ,
V_81 -> V_51 ) ;
}
}
switch ( V_9 -> V_40 ) {
case V_70 :
break;
default:
F_35 (path, &w->sinks, list_source) {
if ( V_81 -> V_125 ) {
F_78 ( V_81 -> V_125 , V_148 ,
V_81 -> V_51 ) ;
}
}
break;
}
if ( V_148 )
F_59 ( V_9 , V_179 , true ) ;
else
F_59 ( V_9 , V_180 , false ) ;
V_9 -> V_148 = V_148 ;
}
static void F_81 ( struct V_8 * V_9 ,
struct V_145 * V_179 ,
struct V_145 * V_180 )
{
int V_148 ;
switch ( V_9 -> V_40 ) {
case V_77 :
F_59 ( V_9 , V_180 , false ) ;
break;
case V_78 :
F_59 ( V_9 , V_179 , true ) ;
break;
default:
V_148 = F_52 ( V_9 ) ;
F_79 ( V_9 , V_148 , V_179 , V_180 ) ;
break;
}
}
static int F_82 ( struct V_18 * V_12 , int V_128 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
struct V_18 * V_172 ;
F_68 ( V_179 ) ;
F_68 ( V_180 ) ;
F_68 ( V_181 ) ;
enum V_30 V_182 ;
F_83 ( V_14 ) ;
F_35 (d, &card->dapm_list, list) {
if ( V_172 -> V_183 || V_172 -> V_19 == NULL ) {
if ( V_172 -> V_184 )
V_172 -> V_174 = V_173 ;
else
V_172 -> V_174 = V_175 ;
}
}
memset ( & V_14 -> V_185 , 0 , sizeof( V_14 -> V_185 ) ) ;
F_35 (w, &card->widgets, list) {
V_9 -> V_131 = false ;
V_9 -> V_126 = - 1 ;
V_9 -> V_118 = - 1 ;
}
F_35 (w, &card->dapm_dirty, dirty) {
F_81 ( V_9 , & V_179 , & V_180 ) ;
}
F_35 (w, &card->widgets, list) {
F_84 ( & V_9 -> V_10 ) ;
if ( V_9 -> V_148 ) {
V_172 = V_9 -> V_12 ;
switch ( V_9 -> V_40 ) {
case V_70 :
case V_68 :
if ( V_172 -> V_174 < V_175 )
V_172 -> V_174 = V_175 ;
break;
default:
V_172 -> V_174 = V_177 ;
break;
}
}
}
if ( ! V_12 -> V_183 ) {
switch ( V_128 ) {
case V_164 :
case V_186 :
V_12 -> V_174 = V_177 ;
break;
case V_165 :
if ( V_12 -> V_19 -> V_120 )
V_12 -> V_174 = V_177 ;
else
V_12 -> V_174 = V_175 ;
break;
case V_187 :
V_12 -> V_174 = V_175 ;
break;
case V_188 :
V_12 -> V_174 = V_12 -> V_35 ;
break;
default:
break;
}
}
V_182 = V_173 ;
F_35 (d, &card->dapm_list, list)
if ( V_172 -> V_174 > V_182 )
V_182 = V_172 -> V_174 ;
F_35 (d, &card->dapm_list, list)
if ( ! V_172 -> V_184 )
V_172 -> V_174 = V_182 ;
F_85 ( V_14 ) ;
F_35 (d, &dapm->card->dapm_list, list)
F_86 ( F_76 , V_172 ,
& V_181 ) ;
F_87 ( & V_181 ) ;
F_67 ( V_12 , & V_180 , V_128 , false ) ;
F_74 ( V_12 ) ;
F_67 ( V_12 , & V_179 , V_128 , true ) ;
F_35 (d, &dapm->card->dapm_list, list)
F_86 ( F_77 , V_172 ,
& V_181 ) ;
F_87 ( & V_181 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_30 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_88 ( V_14 ) ;
return 0 ;
}
static int F_89 ( struct V_189 * V_189 , struct V_190 * V_190 )
{
V_190 -> V_111 = V_189 -> V_191 ;
return 0 ;
}
static T_5 F_90 ( struct V_190 * V_190 ,
char T_6 * V_192 ,
T_3 V_193 , T_7 * V_194 )
{
struct V_8 * V_9 = V_190 -> V_111 ;
char * V_5 ;
int V_135 , V_33 ;
T_5 V_29 ;
struct V_37 * V_38 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_104 ;
V_135 = F_49 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
V_33 = F_47 ( V_9 ) ;
F_43 ( V_9 -> V_12 ) ;
V_29 = snprintf ( V_5 , V_6 , L_31 ,
V_9 -> V_13 , V_9 -> V_148 ? L_32 : L_33 , V_135 , V_33 ) ;
if ( V_9 -> V_22 >= 0 )
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 ,
L_34 ,
V_9 -> V_22 , V_9 -> V_22 , V_9 -> V_48 ) ;
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 , L_35 ) ;
if ( V_9 -> V_195 )
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 , L_36 ,
V_9 -> V_195 ,
V_9 -> V_120 ? L_37 : L_38 ) ;
F_35 (p, &w->sources, list_sink) {
if ( V_38 -> V_121 && ! V_38 -> V_121 ( V_9 , V_38 -> V_125 ) )
continue;
if ( V_38 -> V_51 )
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 ,
L_39 ,
V_38 -> V_13 ? V_38 -> V_13 : L_40 ,
V_38 -> V_127 -> V_13 ) ;
}
F_35 (p, &w->sinks, list_source) {
if ( V_38 -> V_121 && ! V_38 -> V_121 ( V_9 , V_38 -> V_125 ) )
continue;
if ( V_38 -> V_51 )
V_29 += snprintf ( V_5 + V_29 , V_6 - V_29 ,
L_41 ,
V_38 -> V_13 ? V_38 -> V_13 : L_40 ,
V_38 -> V_125 -> V_13 ) ;
}
V_29 = F_91 ( V_192 , V_193 , V_194 , V_5 , V_29 ) ;
F_7 ( V_5 ) ;
return V_29 ;
}
static int F_92 ( struct V_189 * V_189 , struct V_190 * V_190 )
{
V_190 -> V_111 = V_189 -> V_191 ;
return 0 ;
}
static T_5 F_93 ( struct V_190 * V_190 , char T_6 * V_192 ,
T_3 V_193 , T_7 * V_194 )
{
struct V_18 * V_12 = V_190 -> V_111 ;
char * V_31 ;
switch ( V_12 -> V_35 ) {
case V_177 :
V_31 = L_42 ;
break;
case V_176 :
V_31 = L_43 ;
break;
case V_175 :
V_31 = L_44 ;
break;
case V_173 :
V_31 = L_45 ;
break;
default:
F_16 () ;
V_31 = L_46 ;
break;
}
return F_91 ( V_192 , V_193 , V_194 , V_31 ,
strlen ( V_31 ) ) ;
}
void F_94 ( struct V_18 * V_12 ,
struct V_196 * V_197 )
{
struct V_196 * V_172 ;
V_12 -> V_198 = F_95 ( L_47 , V_197 ) ;
if ( ! V_12 -> V_198 ) {
F_96 ( V_199
L_48 ) ;
return;
}
V_172 = F_97 ( L_49 , 0444 ,
V_12 -> V_198 , V_12 ,
& V_200 ) ;
if ( ! V_172 )
F_98 ( V_12 -> V_3 ,
L_50 ) ;
}
static void F_99 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_196 * V_172 ;
if ( ! V_12 -> V_198 || ! V_9 -> V_13 )
return;
V_172 = F_97 ( V_9 -> V_13 , 0444 ,
V_12 -> V_198 , V_9 ,
& V_201 ) ;
if ( ! V_172 )
F_98 ( V_9 -> V_12 -> V_3 ,
L_51 ,
V_9 -> V_13 ) ;
}
static void F_100 ( struct V_18 * V_12 )
{
F_101 ( V_12 -> V_198 ) ;
}
void F_94 ( struct V_18 * V_12 ,
struct V_196 * V_197 )
{
}
static inline void F_99 ( struct V_8 * V_9 )
{
}
static inline void F_100 ( struct V_18 * V_12 )
{
}
static int F_102 ( struct V_8 * V_113 ,
struct V_95 * V_84 , int V_26 ,
int V_202 , struct V_53 * V_54 )
{
struct V_37 * V_81 ;
int V_203 = 0 ;
if ( V_113 -> V_40 != V_52 &&
V_113 -> V_40 != V_59 &&
V_113 -> V_40 != V_60 )
return - V_91 ;
if ( ! V_26 )
return 0 ;
F_35 (path, &widget->dapm->card->paths, list) {
if ( V_81 -> V_84 != V_84 )
continue;
if ( ! V_81 -> V_13 || ! V_54 -> V_58 [ V_202 ] )
continue;
V_203 = 1 ;
if ( ! ( strcmp ( V_81 -> V_13 , V_54 -> V_58 [ V_202 ] ) ) ) {
V_81 -> V_51 = 1 ;
F_10 ( V_81 -> V_127 , L_52 ) ;
} else {
if ( V_81 -> V_51 )
F_10 ( V_81 -> V_127 ,
L_53 ) ;
V_81 -> V_51 = 0 ;
}
}
if ( V_203 ) {
F_10 ( V_113 , L_54 ) ;
F_82 ( V_113 -> V_12 , V_188 ) ;
}
return 0 ;
}
static int F_103 ( struct V_8 * V_113 ,
struct V_95 * V_84 , int V_51 )
{
struct V_37 * V_81 ;
int V_203 = 0 ;
if ( V_113 -> V_40 != V_42 &&
V_113 -> V_40 != V_43 &&
V_113 -> V_40 != V_41 )
return - V_91 ;
F_35 (path, &widget->dapm->card->paths, list) {
if ( V_81 -> V_84 != V_84 )
continue;
V_203 = 1 ;
V_81 -> V_51 = V_51 ;
F_10 ( V_81 -> V_127 , L_55 ) ;
}
if ( V_203 ) {
F_10 ( V_113 , L_56 ) ;
F_82 ( V_113 -> V_12 , V_188 ) ;
}
return 0 ;
}
static T_5 F_104 ( struct V_2 * V_3 ,
struct V_204 * V_205 , char * V_5 )
{
struct V_206 * V_207 =
F_105 ( V_3 , struct V_206 , V_3 ) ;
struct V_208 * V_19 = V_207 -> V_19 ;
struct V_8 * V_9 ;
int V_193 = 0 ;
char * V_209 = L_57 ;
F_35 (w, &codec->card->widgets, list) {
if ( V_9 -> V_12 != & V_19 -> V_12 )
continue;
switch ( V_9 -> V_40 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_68 :
case V_67 :
case V_65 :
case V_62 :
case V_63 :
case V_42 :
case V_43 :
case V_70 :
if ( V_9 -> V_13 )
V_193 += sprintf ( V_5 + V_193 , L_58 ,
V_9 -> V_13 , V_9 -> V_148 ? L_32 : L_33 ) ;
break;
default:
break;
}
}
switch ( V_19 -> V_12 . V_35 ) {
case V_177 :
V_209 = L_32 ;
break;
case V_176 :
V_209 = L_59 ;
break;
case V_175 :
V_209 = L_60 ;
break;
case V_173 :
V_209 = L_33 ;
break;
}
V_193 += sprintf ( V_5 + V_193 , L_61 , V_209 ) ;
return V_193 ;
}
int F_106 ( struct V_2 * V_3 )
{
return F_107 ( V_3 , & V_210 ) ;
}
static void F_108 ( struct V_2 * V_3 )
{
F_109 ( V_3 , & V_210 ) ;
}
static void F_110 ( struct V_18 * V_12 )
{
struct V_8 * V_9 , * V_211 ;
struct V_37 * V_38 , * V_212 ;
F_69 (w, next_w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
F_111 ( & V_9 -> V_85 ) ;
F_69 (p, next_p, &w->sources, list_sink) {
F_111 ( & V_38 -> V_87 ) ;
F_111 ( & V_38 -> V_89 ) ;
F_111 ( & V_38 -> V_85 ) ;
F_7 ( V_38 -> V_107 ) ;
F_7 ( V_38 ) ;
}
F_69 (p, next_p, &w->sinks, list_source) {
F_111 ( & V_38 -> V_87 ) ;
F_111 ( & V_38 -> V_89 ) ;
F_111 ( & V_38 -> V_85 ) ;
F_7 ( V_38 -> V_107 ) ;
F_7 ( V_38 ) ;
}
F_7 ( V_9 -> V_96 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
}
static struct V_8 * F_112 (
struct V_18 * V_12 , const char * V_213 ,
bool V_214 )
{
struct V_8 * V_9 ;
struct V_8 * V_215 = NULL ;
F_35 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_9 -> V_13 , V_213 ) ) {
if ( V_9 -> V_12 == V_12 )
return V_9 ;
else
V_215 = V_9 ;
}
}
if ( V_214 )
return V_215 ;
return NULL ;
}
static int F_113 ( struct V_18 * V_12 ,
const char * V_213 , int V_216 )
{
struct V_8 * V_9 = F_112 ( V_12 , V_213 , true ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_62 , V_213 ) ;
return - V_110 ;
}
V_9 -> V_121 = V_216 ;
if ( V_216 == 0 )
V_9 -> V_133 = 0 ;
F_10 ( V_9 , L_63 ) ;
return 0 ;
}
int F_114 ( struct V_18 * V_12 )
{
if ( ! V_12 -> V_14 || ! V_12 -> V_14 -> V_217 )
return 0 ;
return F_82 ( V_12 , V_188 ) ;
}
static int F_115 ( struct V_18 * V_12 ,
const struct V_218 * V_219 )
{
struct V_37 * V_81 ;
struct V_8 * V_220 = NULL , * V_221 = NULL , * V_9 ;
struct V_8 * V_222 = NULL , * V_223 = NULL ;
const char * V_125 ;
const char * V_224 = V_219 -> V_224 ;
const char * V_127 ;
char V_225 [ 80 ] ;
char V_226 [ 80 ] ;
int V_29 = 0 ;
if ( V_12 -> V_19 && V_12 -> V_19 -> V_103 ) {
snprintf ( V_225 , sizeof( V_225 ) , L_6 ,
V_12 -> V_19 -> V_103 , V_219 -> V_125 ) ;
V_125 = V_225 ;
snprintf ( V_226 , sizeof( V_226 ) , L_6 ,
V_12 -> V_19 -> V_103 , V_219 -> V_127 ) ;
V_127 = V_226 ;
} else {
V_125 = V_219 -> V_125 ;
V_127 = V_219 -> V_127 ;
}
F_35 (w, &dapm->card->widgets, list) {
if ( ! V_221 && ! ( strcmp ( V_9 -> V_13 , V_125 ) ) ) {
V_223 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_221 = V_9 ;
continue;
}
if ( ! V_220 && ! ( strcmp ( V_9 -> V_13 , V_127 ) ) ) {
V_222 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_220 = V_9 ;
}
}
if ( ! V_221 )
V_221 = V_223 ;
if ( ! V_220 )
V_220 = V_222 ;
if ( V_220 == NULL || V_221 == NULL )
return - V_91 ;
V_81 = F_37 ( sizeof( struct V_37 ) , V_7 ) ;
if ( ! V_81 )
return - V_104 ;
V_81 -> V_127 = V_220 ;
V_81 -> V_125 = V_221 ;
V_81 -> V_121 = V_219 -> V_121 ;
F_71 ( & V_81 -> V_85 ) ;
F_71 ( & V_81 -> V_89 ) ;
F_71 ( & V_81 -> V_87 ) ;
if ( V_221 -> V_40 == V_66 ) {
if ( V_220 -> V_40 == V_68 ||
V_220 -> V_40 == V_74 ||
V_220 -> V_40 == V_76 ||
V_220 -> V_40 == V_64 )
V_221 -> V_122 = 1 ;
}
if ( V_220 -> V_40 == V_64 ) {
if ( V_221 -> V_40 == V_75 ||
V_221 -> V_40 == V_73 ||
V_221 -> V_40 == V_76 ||
V_221 -> V_40 == V_66 )
V_220 -> V_122 = 1 ;
}
if ( V_224 == NULL ) {
F_32 ( & V_81 -> V_85 , & V_12 -> V_14 -> V_86 ) ;
F_32 ( & V_81 -> V_87 , & V_221 -> V_88 ) ;
F_32 ( & V_81 -> V_89 , & V_220 -> V_90 ) ;
V_81 -> V_51 = 1 ;
return 0 ;
}
switch ( V_221 -> V_40 ) {
case V_65 :
case V_67 :
case V_62 :
case V_63 :
case V_66 :
case V_64 :
case V_68 :
case V_69 :
case V_77 :
case V_78 :
case V_70 :
case V_71 :
case V_72 :
F_32 ( & V_81 -> V_85 , & V_12 -> V_14 -> V_86 ) ;
F_32 ( & V_81 -> V_87 , & V_221 -> V_88 ) ;
F_32 ( & V_81 -> V_89 , & V_220 -> V_90 ) ;
V_81 -> V_51 = 1 ;
return 0 ;
case V_52 :
case V_59 :
case V_60 :
V_29 = F_31 ( V_12 , V_220 , V_221 , V_81 , V_224 ,
& V_221 -> V_46 [ 0 ] ) ;
if ( V_29 != 0 )
goto V_227;
break;
case V_41 :
case V_42 :
case V_43 :
V_29 = F_33 ( V_12 , V_220 , V_221 , V_81 , V_224 ) ;
if ( V_29 != 0 )
goto V_227;
break;
case V_73 :
case V_74 :
case V_76 :
case V_75 :
F_32 ( & V_81 -> V_85 , & V_12 -> V_14 -> V_86 ) ;
F_32 ( & V_81 -> V_87 , & V_221 -> V_88 ) ;
F_32 ( & V_81 -> V_89 , & V_220 -> V_90 ) ;
V_81 -> V_51 = 0 ;
return 0 ;
}
return 0 ;
V_227:
F_98 ( V_12 -> V_3 , L_64 ,
V_127 , V_224 , V_125 ) ;
F_7 ( V_81 ) ;
return V_29 ;
}
int F_116 ( struct V_18 * V_12 ,
const struct V_218 * V_219 , int V_228 )
{
int V_39 , V_29 ;
for ( V_39 = 0 ; V_39 < V_228 ; V_39 ++ ) {
V_29 = F_115 ( V_12 , V_219 ) ;
if ( V_29 < 0 ) {
F_21 ( V_12 -> V_3 , L_65 ,
V_219 -> V_127 , V_219 -> V_125 ) ;
return V_29 ;
}
V_219 ++ ;
}
return 0 ;
}
static int F_117 ( struct V_18 * V_12 ,
const struct V_218 * V_219 )
{
struct V_8 * V_127 = F_112 ( V_12 ,
V_219 -> V_127 ,
true ) ;
struct V_8 * V_125 = F_112 ( V_12 ,
V_219 -> V_125 ,
true ) ;
struct V_37 * V_81 ;
int V_193 = 0 ;
if ( ! V_127 ) {
F_21 ( V_12 -> V_3 , L_66 ,
V_219 -> V_127 ) ;
return - V_91 ;
}
if ( ! V_125 ) {
F_21 ( V_12 -> V_3 , L_67 ,
V_219 -> V_125 ) ;
return - V_91 ;
}
if ( V_219 -> V_224 || V_219 -> V_121 )
F_98 ( V_12 -> V_3 , L_68 ,
V_219 -> V_127 , V_219 -> V_125 ) ;
F_35 (path, &source->sinks, list_source) {
if ( V_81 -> V_125 == V_125 ) {
V_81 -> V_124 = 1 ;
V_193 ++ ;
}
}
if ( V_193 == 0 )
F_21 ( V_12 -> V_3 , L_69 ,
V_219 -> V_127 , V_219 -> V_125 ) ;
if ( V_193 > 1 )
F_98 ( V_12 -> V_3 , L_70 ,
V_193 , V_219 -> V_127 , V_219 -> V_125 ) ;
return 0 ;
}
int F_118 ( struct V_18 * V_12 ,
const struct V_218 * V_219 , int V_228 )
{
int V_39 , V_227 ;
int V_29 = 0 ;
for ( V_39 = 0 ; V_39 < V_228 ; V_39 ++ ) {
V_227 = F_117 ( V_12 , V_219 ) ;
if ( V_227 )
V_29 = V_227 ;
V_219 ++ ;
}
return V_29 ;
}
int F_119 ( struct V_18 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_23 ;
F_35 (w, &dapm->card->widgets, list)
{
if ( V_9 -> V_28 )
continue;
if ( V_9 -> V_92 ) {
V_9 -> V_96 = F_37 ( V_9 -> V_92 *
sizeof( struct V_95 * ) ,
V_7 ) ;
if ( ! V_9 -> V_96 )
return - V_104 ;
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
V_9 -> V_148 = 1 ;
}
V_9 -> V_28 = 1 ;
F_10 ( V_9 , L_71 ) ;
F_99 ( V_9 ) ;
}
F_82 ( V_12 , V_188 ) ;
return 0 ;
}
int F_120 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_100 * V_101 = F_121 ( V_84 ) ;
struct V_8 * V_113 = V_101 -> V_106 [ 0 ] ;
struct V_44 * V_45 =
(struct V_44 * ) V_84 -> V_47 ;
unsigned int V_22 = V_45 -> V_22 ;
unsigned int V_48 = V_45 -> V_48 ;
unsigned int V_231 = V_45 -> V_231 ;
int V_49 = V_45 -> V_49 ;
unsigned int V_50 = V_45 -> V_50 ;
unsigned int V_24 = ( 1 << F_30 ( V_49 ) ) - 1 ;
V_230 -> V_25 . integer . V_25 [ 0 ] =
( F_19 ( V_113 -> V_19 , V_22 ) >> V_48 ) & V_24 ;
if ( V_48 != V_231 )
V_230 -> V_25 . integer . V_25 [ 1 ] =
( F_19 ( V_113 -> V_19 , V_22 ) >> V_231 ) & V_24 ;
if ( V_50 ) {
V_230 -> V_25 . integer . V_25 [ 0 ] =
V_49 - V_230 -> V_25 . integer . V_25 [ 0 ] ;
if ( V_48 != V_231 )
V_230 -> V_25 . integer . V_25 [ 1 ] =
V_49 - V_230 -> V_25 . integer . V_25 [ 1 ] ;
}
return 0 ;
}
int F_122 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_100 * V_101 = F_121 ( V_84 ) ;
struct V_8 * V_113 = V_101 -> V_106 [ 0 ] ;
struct V_208 * V_19 = V_113 -> V_19 ;
struct V_44 * V_45 =
(struct V_44 * ) V_84 -> V_47 ;
unsigned int V_22 = V_45 -> V_22 ;
unsigned int V_48 = V_45 -> V_48 ;
int V_49 = V_45 -> V_49 ;
unsigned int V_24 = ( 1 << F_30 ( V_49 ) ) - 1 ;
unsigned int V_50 = V_45 -> V_50 ;
unsigned int V_23 ;
int V_51 , V_26 ;
struct V_166 V_167 ;
int V_232 ;
V_23 = ( V_230 -> V_25 . integer . V_25 [ 0 ] & V_24 ) ;
if ( V_50 )
V_23 = V_49 - V_23 ;
V_24 = V_24 << V_48 ;
V_23 = V_23 << V_48 ;
if ( V_23 )
V_51 = V_50 ? 0 : 1 ;
else
V_51 = V_50 ? 1 : 0 ;
F_123 ( & V_19 -> V_233 ) ;
V_26 = F_124 ( V_113 -> V_19 , V_22 , V_24 , V_23 ) ;
if ( V_26 ) {
for ( V_232 = 0 ; V_232 < V_101 -> V_105 ; V_232 ++ ) {
V_113 = V_101 -> V_106 [ V_232 ] ;
V_113 -> V_25 = V_23 ;
V_167 . V_84 = V_84 ;
V_167 . V_113 = V_113 ;
V_167 . V_22 = V_22 ;
V_167 . V_24 = V_24 ;
V_167 . V_23 = V_23 ;
V_113 -> V_12 -> V_167 = & V_167 ;
F_103 ( V_113 , V_84 , V_51 ) ;
V_113 -> V_12 -> V_167 = NULL ;
}
}
F_125 ( & V_19 -> V_233 ) ;
return 0 ;
}
int F_126 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_100 * V_101 = F_121 ( V_84 ) ;
struct V_8 * V_113 = V_101 -> V_106 [ 0 ] ;
struct V_53 * V_54 = (struct V_53 * ) V_84 -> V_47 ;
unsigned int V_23 , V_56 ;
for ( V_56 = 1 ; V_56 < V_54 -> V_49 ; V_56 <<= 1 )
;
V_23 = F_19 ( V_113 -> V_19 , V_54 -> V_22 ) ;
V_230 -> V_25 . V_234 . V_55 [ 0 ] = ( V_23 >> V_54 -> V_57 ) & ( V_56 - 1 ) ;
if ( V_54 -> V_57 != V_54 -> V_235 )
V_230 -> V_25 . V_234 . V_55 [ 1 ] =
( V_23 >> V_54 -> V_235 ) & ( V_56 - 1 ) ;
return 0 ;
}
int F_127 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_100 * V_101 = F_121 ( V_84 ) ;
struct V_8 * V_113 = V_101 -> V_106 [ 0 ] ;
struct V_208 * V_19 = V_113 -> V_19 ;
struct V_53 * V_54 = (struct V_53 * ) V_84 -> V_47 ;
unsigned int V_23 , V_202 , V_26 ;
unsigned int V_24 , V_56 ;
struct V_166 V_167 ;
int V_232 ;
for ( V_56 = 1 ; V_56 < V_54 -> V_49 ; V_56 <<= 1 )
;
if ( V_230 -> V_25 . V_234 . V_55 [ 0 ] > V_54 -> V_49 - 1 )
return - V_110 ;
V_202 = V_230 -> V_25 . V_234 . V_55 [ 0 ] ;
V_23 = V_202 << V_54 -> V_57 ;
V_24 = ( V_56 - 1 ) << V_54 -> V_57 ;
if ( V_54 -> V_57 != V_54 -> V_235 ) {
if ( V_230 -> V_25 . V_234 . V_55 [ 1 ] > V_54 -> V_49 - 1 )
return - V_110 ;
V_23 |= V_230 -> V_25 . V_234 . V_55 [ 1 ] << V_54 -> V_235 ;
V_24 |= ( V_56 - 1 ) << V_54 -> V_235 ;
}
F_123 ( & V_19 -> V_233 ) ;
V_26 = F_124 ( V_113 -> V_19 , V_54 -> V_22 , V_24 , V_23 ) ;
if ( V_26 ) {
for ( V_232 = 0 ; V_232 < V_101 -> V_105 ; V_232 ++ ) {
V_113 = V_101 -> V_106 [ V_232 ] ;
V_113 -> V_25 = V_23 ;
V_167 . V_84 = V_84 ;
V_167 . V_113 = V_113 ;
V_167 . V_22 = V_54 -> V_22 ;
V_167 . V_24 = V_24 ;
V_167 . V_23 = V_23 ;
V_113 -> V_12 -> V_167 = & V_167 ;
F_102 ( V_113 , V_84 , V_26 , V_202 , V_54 ) ;
V_113 -> V_12 -> V_167 = NULL ;
}
}
F_125 ( & V_19 -> V_233 ) ;
return V_26 ;
}
int F_128 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_100 * V_101 = F_121 ( V_84 ) ;
struct V_8 * V_113 = V_101 -> V_106 [ 0 ] ;
V_230 -> V_25 . V_234 . V_55 [ 0 ] = V_113 -> V_25 ;
return 0 ;
}
int F_129 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_100 * V_101 = F_121 ( V_84 ) ;
struct V_8 * V_113 = V_101 -> V_106 [ 0 ] ;
struct V_208 * V_19 = V_113 -> V_19 ;
struct V_53 * V_54 =
(struct V_53 * ) V_84 -> V_47 ;
int V_26 ;
int V_29 = 0 ;
int V_232 ;
if ( V_230 -> V_25 . V_234 . V_55 [ 0 ] >= V_54 -> V_49 )
return - V_110 ;
F_123 ( & V_19 -> V_233 ) ;
V_26 = V_113 -> V_25 != V_230 -> V_25 . V_234 . V_55 [ 0 ] ;
if ( V_26 ) {
for ( V_232 = 0 ; V_232 < V_101 -> V_105 ; V_232 ++ ) {
V_113 = V_101 -> V_106 [ V_232 ] ;
V_113 -> V_25 = V_230 -> V_25 . V_234 . V_55 [ 0 ] ;
F_102 ( V_113 , V_84 , V_26 ,
V_113 -> V_25 , V_54 ) ;
}
}
F_125 ( & V_19 -> V_233 ) ;
return V_29 ;
}
int F_130 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_100 * V_101 = F_121 ( V_84 ) ;
struct V_8 * V_113 = V_101 -> V_106 [ 0 ] ;
struct V_53 * V_54 = (struct V_53 * ) V_84 -> V_47 ;
unsigned int V_236 , V_23 , V_202 ;
V_236 = F_19 ( V_113 -> V_19 , V_54 -> V_22 ) ;
V_23 = ( V_236 >> V_54 -> V_57 ) & V_54 -> V_24 ;
for ( V_202 = 0 ; V_202 < V_54 -> V_49 ; V_202 ++ ) {
if ( V_23 == V_54 -> V_61 [ V_202 ] )
break;
}
V_230 -> V_25 . V_234 . V_55 [ 0 ] = V_202 ;
if ( V_54 -> V_57 != V_54 -> V_235 ) {
V_23 = ( V_236 >> V_54 -> V_235 ) & V_54 -> V_24 ;
for ( V_202 = 0 ; V_202 < V_54 -> V_49 ; V_202 ++ ) {
if ( V_23 == V_54 -> V_61 [ V_202 ] )
break;
}
V_230 -> V_25 . V_234 . V_55 [ 1 ] = V_202 ;
}
return 0 ;
}
int F_131 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_100 * V_101 = F_121 ( V_84 ) ;
struct V_8 * V_113 = V_101 -> V_106 [ 0 ] ;
struct V_208 * V_19 = V_113 -> V_19 ;
struct V_53 * V_54 = (struct V_53 * ) V_84 -> V_47 ;
unsigned int V_23 , V_202 , V_26 ;
unsigned int V_24 ;
struct V_166 V_167 ;
int V_232 ;
if ( V_230 -> V_25 . V_234 . V_55 [ 0 ] > V_54 -> V_49 - 1 )
return - V_110 ;
V_202 = V_230 -> V_25 . V_234 . V_55 [ 0 ] ;
V_23 = V_54 -> V_61 [ V_230 -> V_25 . V_234 . V_55 [ 0 ] ] << V_54 -> V_57 ;
V_24 = V_54 -> V_24 << V_54 -> V_57 ;
if ( V_54 -> V_57 != V_54 -> V_235 ) {
if ( V_230 -> V_25 . V_234 . V_55 [ 1 ] > V_54 -> V_49 - 1 )
return - V_110 ;
V_23 |= V_54 -> V_61 [ V_230 -> V_25 . V_234 . V_55 [ 1 ] ] << V_54 -> V_235 ;
V_24 |= V_54 -> V_24 << V_54 -> V_235 ;
}
F_123 ( & V_19 -> V_233 ) ;
V_26 = F_124 ( V_113 -> V_19 , V_54 -> V_22 , V_24 , V_23 ) ;
if ( V_26 ) {
for ( V_232 = 0 ; V_232 < V_101 -> V_105 ; V_232 ++ ) {
V_113 = V_101 -> V_106 [ V_232 ] ;
V_113 -> V_25 = V_23 ;
V_167 . V_84 = V_84 ;
V_167 . V_113 = V_113 ;
V_167 . V_22 = V_54 -> V_22 ;
V_167 . V_24 = V_24 ;
V_167 . V_23 = V_23 ;
V_113 -> V_12 -> V_167 = & V_167 ;
F_102 ( V_113 , V_84 , V_26 , V_202 , V_54 ) ;
V_113 -> V_12 -> V_167 = NULL ;
}
}
F_125 ( & V_19 -> V_233 ) ;
return V_26 ;
}
int F_132 ( struct V_95 * V_84 ,
struct V_237 * V_238 )
{
V_238 -> type = V_239 ;
V_238 -> V_193 = 1 ;
V_238 -> V_25 . integer . V_240 = 0 ;
V_238 -> V_25 . integer . V_49 = 1 ;
return 0 ;
}
int F_133 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_208 * V_19 = F_121 ( V_84 ) ;
const char * V_213 = ( const char * ) V_84 -> V_47 ;
F_123 ( & V_19 -> V_233 ) ;
V_230 -> V_25 . integer . V_25 [ 0 ] =
F_134 ( & V_19 -> V_12 , V_213 ) ;
F_125 ( & V_19 -> V_233 ) ;
return 0 ;
}
int F_135 ( struct V_95 * V_84 ,
struct V_229 * V_230 )
{
struct V_208 * V_19 = F_121 ( V_84 ) ;
const char * V_213 = ( const char * ) V_84 -> V_47 ;
F_123 ( & V_19 -> V_233 ) ;
if ( V_230 -> V_25 . integer . V_25 [ 0 ] )
F_136 ( & V_19 -> V_12 , V_213 ) ;
else
F_137 ( & V_19 -> V_12 , V_213 ) ;
F_114 ( & V_19 -> V_12 ) ;
F_125 ( & V_19 -> V_233 ) ;
return 0 ;
}
int F_138 ( struct V_18 * V_12 ,
const struct V_8 * V_113 )
{
struct V_8 * V_9 ;
T_3 V_97 ;
if ( ( V_9 = F_13 ( V_113 ) ) == NULL )
return - V_104 ;
V_97 = strlen ( V_113 -> V_13 ) + 1 ;
if ( V_12 -> V_19 && V_12 -> V_19 -> V_103 )
V_97 += 1 + strlen ( V_12 -> V_19 -> V_103 ) ;
V_9 -> V_13 = F_5 ( V_97 , V_7 ) ;
if ( V_9 -> V_13 == NULL ) {
F_7 ( V_9 ) ;
return - V_104 ;
}
if ( V_12 -> V_19 && V_12 -> V_19 -> V_103 )
snprintf ( V_9 -> V_13 , V_97 , L_6 ,
V_12 -> V_19 -> V_103 , V_113 -> V_13 ) ;
else
snprintf ( V_9 -> V_13 , V_97 , L_1 , V_113 -> V_13 ) ;
switch ( V_9 -> V_40 ) {
case V_41 :
case V_42 :
case V_43 :
V_9 -> V_134 = F_53 ;
break;
case V_52 :
case V_59 :
case V_60 :
V_9 -> V_134 = F_53 ;
break;
case V_65 :
case V_72 :
V_9 -> V_134 = F_54 ;
break;
case V_67 :
case V_71 :
V_9 -> V_134 = F_55 ;
break;
case V_62 :
case V_63 :
case V_66 :
case V_64 :
case V_68 :
case V_75 :
case V_73 :
case V_74 :
case V_76 :
V_9 -> V_134 = F_53 ;
break;
case V_70 :
V_9 -> V_134 = F_56 ;
break;
default:
V_9 -> V_134 = F_57 ;
break;
}
V_12 -> V_183 ++ ;
V_9 -> V_12 = V_12 ;
V_9 -> V_19 = V_12 -> V_19 ;
V_9 -> V_20 = V_12 -> V_20 ;
F_71 ( & V_9 -> V_88 ) ;
F_71 ( & V_9 -> V_90 ) ;
F_71 ( & V_9 -> V_85 ) ;
F_71 ( & V_9 -> V_10 ) ;
F_32 ( & V_9 -> V_85 , & V_12 -> V_14 -> V_106 ) ;
V_9 -> V_121 = 1 ;
return 0 ;
}
int F_139 ( struct V_18 * V_12 ,
const struct V_8 * V_113 ,
int V_228 )
{
int V_39 , V_29 ;
for ( V_39 = 0 ; V_39 < V_228 ; V_39 ++ ) {
V_29 = F_138 ( V_12 , V_113 ) ;
if ( V_29 < 0 ) {
F_21 ( V_12 -> V_3 ,
L_72 ,
V_113 -> V_13 , V_29 ) ;
return V_29 ;
}
V_113 ++ ;
}
return 0 ;
}
static void F_140 ( struct V_18 * V_12 ,
const char * V_241 , int V_128 )
{
struct V_8 * V_9 ;
F_35 (w, &dapm->card->widgets, list)
{
if ( ! V_9 -> V_195 || V_9 -> V_12 != V_12 )
continue;
F_11 ( V_9 -> V_12 -> V_3 , L_73 ,
V_9 -> V_13 , V_9 -> V_195 , V_241 , V_128 ) ;
if ( strstr ( V_9 -> V_195 , V_241 ) ) {
F_10 ( V_9 , L_74 ) ;
switch( V_128 ) {
case V_164 :
V_9 -> V_120 = 1 ;
break;
case V_165 :
V_9 -> V_120 = 0 ;
break;
case V_187 :
case V_186 :
case V_242 :
case V_243 :
break;
}
}
}
F_82 ( V_12 , V_128 ) ;
if ( V_12 -> V_244 )
V_12 -> V_244 ( V_12 , V_128 ) ;
}
int F_141 ( struct V_206 * V_207 ,
const char * V_241 , int V_128 )
{
struct V_208 * V_19 = V_207 -> V_19 ;
if ( V_241 == NULL )
return 0 ;
F_123 ( & V_19 -> V_233 ) ;
F_140 ( & V_19 -> V_12 , V_241 , V_128 ) ;
F_125 ( & V_19 -> V_233 ) ;
return 0 ;
}
int F_136 ( struct V_18 * V_12 , const char * V_213 )
{
return F_113 ( V_12 , V_213 , 1 ) ;
}
int F_142 ( struct V_18 * V_12 ,
const char * V_213 )
{
struct V_8 * V_9 = F_112 ( V_12 , V_213 , true ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_62 , V_213 ) ;
return - V_110 ;
}
F_46 ( V_9 -> V_12 -> V_3 , L_75 , V_213 ) ;
V_9 -> V_121 = 1 ;
V_9 -> V_133 = 1 ;
F_10 ( V_9 , L_76 ) ;
return 0 ;
}
int F_137 ( struct V_18 * V_12 ,
const char * V_213 )
{
return F_113 ( V_12 , V_213 , 0 ) ;
}
int F_143 ( struct V_18 * V_12 , const char * V_213 )
{
return F_113 ( V_12 , V_213 , 0 ) ;
}
int F_134 ( struct V_18 * V_12 ,
const char * V_213 )
{
struct V_8 * V_9 = F_112 ( V_12 , V_213 , true ) ;
if ( V_9 )
return V_9 -> V_121 ;
return 0 ;
}
int F_144 ( struct V_18 * V_12 ,
const char * V_213 )
{
struct V_8 * V_9 = F_112 ( V_12 , V_213 , false ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_62 , V_213 ) ;
return - V_110 ;
}
V_9 -> V_116 = 1 ;
return 0 ;
}
void F_145 ( struct V_18 * V_12 )
{
F_108 ( V_12 -> V_3 ) ;
F_100 ( V_12 ) ;
F_110 ( V_12 ) ;
F_111 ( & V_12 -> V_85 ) ;
}
static void F_146 ( struct V_18 * V_12 )
{
struct V_8 * V_9 ;
F_68 ( V_180 ) ;
int V_245 = 0 ;
F_35 (w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
if ( V_9 -> V_148 ) {
F_59 ( V_9 , & V_180 , false ) ;
V_9 -> V_148 = 0 ;
V_245 = 1 ;
}
}
if ( V_245 ) {
F_26 ( V_12 , V_176 ) ;
F_67 ( V_12 , & V_180 , 0 , false ) ;
F_26 ( V_12 , V_175 ) ;
}
}
void F_147 ( struct V_21 * V_14 )
{
struct V_208 * V_19 ;
F_35 (codec, &card->codec_dev_list, list) {
F_146 ( & V_19 -> V_12 ) ;
F_26 ( & V_19 -> V_12 , V_173 ) ;
}
}
