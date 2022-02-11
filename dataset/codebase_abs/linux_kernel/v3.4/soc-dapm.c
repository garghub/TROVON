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
static void F_18 ( struct V_21 * V_14 )
{
struct V_8 * V_9 ;
memset ( & V_14 -> V_22 , 0 , sizeof( V_14 -> V_22 ) ) ;
F_19 (w, &card->widgets, list) {
V_9 -> V_23 = false ;
V_9 -> V_24 = - 1 ;
V_9 -> V_25 = - 1 ;
}
}
static int F_20 ( struct V_8 * V_9 , int V_26 )
{
if ( V_9 -> V_19 )
return F_21 ( V_9 -> V_19 , V_26 ) ;
else if ( V_9 -> V_20 )
return F_22 ( V_9 -> V_20 , V_26 ) ;
F_23 ( V_9 -> V_12 -> V_3 , L_3 ) ;
return - 1 ;
}
static int F_24 ( struct V_8 * V_9 , int V_26 , int V_27 )
{
if ( V_9 -> V_19 )
return F_25 ( V_9 -> V_19 , V_26 , V_27 ) ;
else if ( V_9 -> V_20 )
return F_26 ( V_9 -> V_20 , V_26 , V_27 ) ;
F_23 ( V_9 -> V_12 -> V_3 , L_4 ) ;
return - 1 ;
}
static int F_27 ( struct V_8 * V_9 ,
unsigned short V_26 , unsigned int V_28 , unsigned int V_29 )
{
bool V_30 ;
unsigned int V_31 , V_32 ;
int V_33 ;
if ( V_9 -> V_19 && V_9 -> V_19 -> V_34 ) {
V_33 = F_28 ( V_9 -> V_19 -> V_35 ,
V_26 , V_28 , V_29 , & V_30 ) ;
if ( V_33 != 0 )
return V_33 ;
} else {
V_33 = F_20 ( V_9 , V_26 ) ;
if ( V_33 < 0 )
return V_33 ;
V_31 = V_33 ;
V_32 = ( V_31 & ~ V_28 ) | ( V_29 & V_28 ) ;
V_30 = V_31 != V_32 ;
if ( V_30 ) {
V_33 = F_24 ( V_9 , V_26 , V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return V_30 ;
}
static int F_29 ( struct V_18 * V_12 ,
enum V_36 V_37 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
int V_33 = 0 ;
F_30 ( V_14 , V_37 ) ;
if ( V_14 && V_14 -> V_38 )
V_33 = V_14 -> V_38 ( V_14 , V_12 , V_37 ) ;
if ( V_33 != 0 )
goto V_39;
if ( V_12 -> V_19 ) {
if ( V_12 -> V_19 -> V_40 -> V_38 )
V_33 = V_12 -> V_19 -> V_40 -> V_38 ( V_12 -> V_19 ,
V_37 ) ;
else
V_12 -> V_41 = V_37 ;
}
if ( V_33 != 0 )
goto V_39;
if ( V_14 && V_14 -> V_42 )
V_33 = V_14 -> V_42 ( V_14 , V_12 , V_37 ) ;
V_39:
F_31 ( V_14 , V_37 ) ;
return V_33 ;
}
static void F_32 ( struct V_8 * V_9 ,
struct V_43 * V_44 , int V_45 )
{
switch ( V_9 -> V_46 ) {
case V_47 :
case V_48 :
case V_49 : {
int V_27 ;
struct V_50 * V_51 = (struct V_50 * )
V_9 -> V_52 [ V_45 ] . V_53 ;
unsigned int V_26 = V_51 -> V_26 ;
unsigned int V_54 = V_51 -> V_54 ;
int V_55 = V_51 -> V_55 ;
unsigned int V_28 = ( 1 << F_33 ( V_55 ) ) - 1 ;
unsigned int V_56 = V_51 -> V_56 ;
V_27 = F_20 ( V_9 , V_26 ) ;
V_27 = ( V_27 >> V_54 ) & V_28 ;
if ( ( V_56 && ! V_27 ) || ( ! V_56 && V_27 ) )
V_44 -> V_57 = 1 ;
else
V_44 -> V_57 = 0 ;
}
break;
case V_58 : {
struct V_59 * V_60 = (struct V_59 * )
V_9 -> V_52 [ V_45 ] . V_53 ;
int V_27 , V_61 , V_62 ;
for ( V_62 = 1 ; V_62 < V_60 -> V_55 ; V_62 <<= 1 )
;
V_27 = F_20 ( V_9 , V_60 -> V_26 ) ;
V_61 = ( V_27 >> V_60 -> V_63 ) & ( V_62 - 1 ) ;
V_44 -> V_57 = 0 ;
for ( V_45 = 0 ; V_45 < V_60 -> V_55 ; V_45 ++ ) {
if ( ! ( strcmp ( V_44 -> V_13 , V_60 -> V_64 [ V_45 ] ) ) && V_61 == V_45 )
V_44 -> V_57 = 1 ;
}
}
break;
case V_65 : {
struct V_59 * V_60 = (struct V_59 * )
V_9 -> V_52 [ V_45 ] . V_53 ;
V_44 -> V_57 = 0 ;
if ( ! strcmp ( V_44 -> V_13 , V_60 -> V_64 [ 0 ] ) )
V_44 -> V_57 = 1 ;
}
break;
case V_66 : {
struct V_59 * V_60 = (struct V_59 * )
V_9 -> V_52 [ V_45 ] . V_53 ;
int V_27 , V_61 ;
V_27 = F_20 ( V_9 , V_60 -> V_26 ) ;
V_27 = ( V_27 >> V_60 -> V_63 ) & V_60 -> V_28 ;
for ( V_61 = 0 ; V_61 < V_60 -> V_55 ; V_61 ++ ) {
if ( V_27 == V_60 -> V_67 [ V_61 ] )
break;
}
V_44 -> V_57 = 0 ;
for ( V_45 = 0 ; V_45 < V_60 -> V_55 ; V_45 ++ ) {
if ( ! ( strcmp ( V_44 -> V_13 , V_60 -> V_64 [ V_45 ] ) ) && V_61 == V_45 )
V_44 -> V_57 = 1 ;
}
}
break;
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
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
V_44 -> V_57 = 1 ;
break;
case V_86 :
case V_87 :
V_44 -> V_57 = 0 ;
break;
}
}
static int F_34 ( struct V_18 * V_12 ,
struct V_8 * V_88 , struct V_8 * V_89 ,
struct V_43 * V_90 , const char * V_91 ,
const struct V_92 * V_93 )
{
struct V_59 * V_60 = (struct V_59 * ) V_93 -> V_53 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_60 -> V_55 ; V_45 ++ ) {
if ( ! ( strcmp ( V_91 , V_60 -> V_64 [ V_45 ] ) ) ) {
F_35 ( & V_90 -> V_94 , & V_12 -> V_14 -> V_95 ) ;
F_35 ( & V_90 -> V_96 , & V_89 -> V_97 ) ;
F_35 ( & V_90 -> V_98 , & V_88 -> V_99 ) ;
V_90 -> V_13 = ( char * ) V_60 -> V_64 [ V_45 ] ;
F_32 ( V_89 , V_90 , 0 ) ;
return 0 ;
}
}
return - V_100 ;
}
static int F_36 ( struct V_18 * V_12 ,
struct V_8 * V_88 , struct V_8 * V_89 ,
struct V_43 * V_90 , const char * V_91 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_89 -> V_101 ; V_45 ++ ) {
if ( ! strcmp ( V_91 , V_89 -> V_52 [ V_45 ] . V_13 ) ) {
F_35 ( & V_90 -> V_94 , & V_12 -> V_14 -> V_95 ) ;
F_35 ( & V_90 -> V_96 , & V_89 -> V_97 ) ;
F_35 ( & V_90 -> V_98 , & V_88 -> V_99 ) ;
V_90 -> V_13 = V_89 -> V_52 [ V_45 ] . V_13 ;
F_32 ( V_89 , V_90 , V_45 ) ;
return 0 ;
}
}
return - V_100 ;
}
static int F_37 ( struct V_18 * V_12 ,
struct V_8 * V_102 ,
const struct V_92 * V_103 ,
struct V_104 * * V_93 )
{
struct V_8 * V_9 ;
int V_45 ;
* V_93 = NULL ;
F_19 (w, &dapm->card->widgets, list) {
if ( V_9 == V_102 || V_9 -> V_12 != V_102 -> V_12 )
continue;
for ( V_45 = 0 ; V_45 < V_9 -> V_101 ; V_45 ++ ) {
if ( & V_9 -> V_52 [ V_45 ] == V_103 ) {
if ( V_9 -> V_105 )
* V_93 = V_9 -> V_105 [ V_45 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_38 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
int V_45 , V_33 = 0 ;
T_3 V_106 , V_107 ;
struct V_43 * V_90 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_108 ;
struct V_109 * V_110 ;
T_3 V_111 ;
if ( V_12 -> V_19 )
V_108 = V_12 -> V_19 -> V_112 ;
else
V_108 = NULL ;
if ( V_108 )
V_107 = strlen ( V_108 ) + 1 ;
else
V_107 = 0 ;
for ( V_45 = 0 ; V_45 < V_9 -> V_101 ; V_45 ++ ) {
F_19 (path, &w->sources, list_sink) {
if ( V_90 -> V_13 != ( char * ) V_9 -> V_52 [ V_45 ] . V_13 )
continue;
if ( V_9 -> V_105 [ V_45 ] ) {
V_90 -> V_93 = V_9 -> V_105 [ V_45 ] ;
continue;
}
V_111 = sizeof( struct V_109 ) +
sizeof( struct V_8 * ) ,
V_110 = F_39 ( V_111 , V_7 ) ;
if ( V_110 == NULL ) {
F_23 ( V_12 -> V_3 ,
L_5 ,
V_9 -> V_13 ) ;
return - V_113 ;
}
V_110 -> V_114 = 1 ;
V_110 -> V_115 [ 0 ] = V_9 ;
V_106 = strlen ( V_9 -> V_52 [ V_45 ] . V_13 ) + 1 ;
if ( V_9 -> V_46 != V_49 )
V_106 += 1 + strlen ( V_9 -> V_13 ) ;
V_90 -> V_116 = F_5 ( V_106 , V_7 ) ;
if ( V_90 -> V_116 == NULL ) {
F_7 ( V_110 ) ;
return - V_113 ;
}
switch ( V_9 -> V_46 ) {
default:
snprintf ( ( char * ) V_90 -> V_116 , V_106 ,
L_6 , V_9 -> V_13 + V_107 ,
V_9 -> V_52 [ V_45 ] . V_13 ) ;
break;
case V_49 :
snprintf ( ( char * ) V_90 -> V_116 , V_106 ,
L_1 , V_9 -> V_52 [ V_45 ] . V_13 ) ;
break;
}
( ( char * ) V_90 -> V_116 ) [ V_106 - 1 ] = '\0' ;
V_90 -> V_93 = F_40 ( & V_9 -> V_52 [ V_45 ] ,
V_110 , V_90 -> V_116 ,
V_108 ) ;
V_33 = F_41 ( V_14 , V_90 -> V_93 ) ;
if ( V_33 < 0 ) {
F_23 ( V_12 -> V_3 ,
L_7 ,
V_90 -> V_116 , V_33 ) ;
F_7 ( V_110 ) ;
F_7 ( V_90 -> V_116 ) ;
V_90 -> V_116 = NULL ;
return V_33 ;
}
V_9 -> V_105 [ V_45 ] = V_90 -> V_93 ;
}
}
return V_33 ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_43 * V_90 = NULL ;
struct V_104 * V_93 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_108 ;
T_3 V_107 ;
int V_33 ;
struct V_109 * V_110 ;
int V_117 , V_118 ;
T_3 V_111 ;
const char * V_13 ;
if ( V_9 -> V_101 != 1 ) {
F_23 ( V_12 -> V_3 ,
L_8 ,
V_9 -> V_13 ) ;
return - V_119 ;
}
V_117 = F_37 ( V_12 , V_9 , & V_9 -> V_52 [ 0 ] ,
& V_93 ) ;
if ( V_93 ) {
V_110 = V_93 -> V_120 ;
V_118 = V_110 -> V_114 + 1 ;
} else {
V_110 = NULL ;
V_118 = 1 ;
}
V_111 = sizeof( struct V_109 ) +
V_118 * sizeof( struct V_8 * ) ,
V_110 = F_43 ( V_110 , V_111 , V_7 ) ;
if ( V_110 == NULL ) {
F_23 ( V_12 -> V_3 ,
L_5 , V_9 -> V_13 ) ;
return - V_113 ;
}
V_110 -> V_114 = V_118 ;
V_110 -> V_115 [ V_118 - 1 ] = V_9 ;
if ( ! V_93 ) {
if ( V_12 -> V_19 )
V_108 = V_12 -> V_19 -> V_112 ;
else
V_108 = NULL ;
if ( V_117 ) {
V_13 = V_9 -> V_52 [ 0 ] . V_13 ;
V_107 = 0 ;
} else {
V_13 = V_9 -> V_13 ;
if ( V_108 )
V_107 = strlen ( V_108 ) + 1 ;
else
V_107 = 0 ;
}
V_93 = F_40 ( & V_9 -> V_52 [ 0 ] , V_110 ,
V_13 + V_107 , V_108 ) ;
V_33 = F_41 ( V_14 , V_93 ) ;
if ( V_33 < 0 ) {
F_23 ( V_12 -> V_3 , L_9 ,
V_9 -> V_13 , V_33 ) ;
F_7 ( V_110 ) ;
return V_33 ;
}
}
V_93 -> V_120 = V_110 ;
V_9 -> V_105 [ 0 ] = V_93 ;
F_19 (path, &w->sources, list_sink)
V_90 -> V_93 = V_93 ;
return 0 ;
}
static int F_44 ( struct V_8 * V_9 )
{
if ( V_9 -> V_101 )
F_23 ( V_9 -> V_12 -> V_3 ,
L_10 , V_9 -> V_13 ) ;
return 0 ;
}
static inline void F_45 ( struct V_18 * V_12 )
{
struct V_43 * V_44 ;
F_19 (p, &dapm->card->paths, list)
V_44 -> V_121 = 0 ;
}
static int F_46 ( struct V_8 * V_122 )
{
int V_37 = F_47 ( V_122 -> V_12 -> V_14 -> V_17 ) ;
switch ( V_37 ) {
case V_123 :
case V_124 :
if ( V_122 -> V_125 )
F_48 ( V_122 -> V_12 -> V_3 , L_11 ,
V_122 -> V_13 ) ;
return V_122 -> V_125 ;
default:
return 1 ;
}
}
static int F_49 ( struct V_8 * V_122 )
{
struct V_43 * V_90 ;
int V_126 = 0 ;
if ( V_122 -> V_25 >= 0 )
return V_122 -> V_25 ;
F_50 ( V_122 , V_127 ) ;
switch ( V_122 -> V_46 ) {
case V_77 :
case V_78 :
return 0 ;
default:
break;
}
switch ( V_122 -> V_46 ) {
case V_71 :
case V_80 :
case V_81 :
if ( V_122 -> V_128 ) {
V_122 -> V_25 = F_46 ( V_122 ) ;
return V_122 -> V_25 ;
}
default:
break;
}
if ( V_122 -> V_129 ) {
if ( V_122 -> V_46 == V_70 && ! V_122 -> V_130 ) {
V_122 -> V_25 = F_46 ( V_122 ) ;
return V_122 -> V_25 ;
}
if ( V_122 -> V_46 == V_82 ||
V_122 -> V_46 == V_84 ||
( V_122 -> V_46 == V_85 &&
! F_9 ( & V_122 -> V_97 ) ) ) {
V_122 -> V_25 = F_46 ( V_122 ) ;
return V_122 -> V_25 ;
}
}
F_19 (path, &widget->sinks, list_source) {
F_50 ( V_122 , V_131 ) ;
if ( V_90 -> V_132 )
continue;
if ( V_90 -> V_121 )
continue;
if ( V_90 -> V_133 && V_90 -> V_57 ) {
V_90 -> V_121 = 1 ;
V_126 += F_49 ( V_90 -> V_133 ) ;
}
}
V_122 -> V_25 = V_126 ;
return V_126 ;
}
static int F_51 ( struct V_8 * V_122 )
{
struct V_43 * V_90 ;
int V_126 = 0 ;
if ( V_122 -> V_24 >= 0 )
return V_122 -> V_24 ;
F_50 ( V_122 , V_127 ) ;
switch ( V_122 -> V_46 ) {
case V_77 :
case V_78 :
return 0 ;
default:
break;
}
switch ( V_122 -> V_46 ) {
case V_74 :
case V_79 :
case V_81 :
if ( V_122 -> V_128 ) {
V_122 -> V_24 = F_46 ( V_122 ) ;
return V_122 -> V_24 ;
}
default:
break;
}
if ( V_122 -> V_129 ) {
if ( V_122 -> V_46 == V_72 && ! V_122 -> V_130 ) {
V_122 -> V_24 = F_46 ( V_122 ) ;
return V_122 -> V_24 ;
}
if ( V_122 -> V_46 == V_76 ) {
V_122 -> V_24 = F_46 ( V_122 ) ;
return V_122 -> V_24 ;
}
if ( V_122 -> V_46 == V_83 ||
( V_122 -> V_46 == V_85 &&
! F_9 ( & V_122 -> V_99 ) ) ) {
V_122 -> V_24 = F_46 ( V_122 ) ;
return V_122 -> V_24 ;
}
if ( V_122 -> V_46 == V_73 ) {
V_122 -> V_24 = F_46 ( V_122 ) ;
return V_122 -> V_24 ;
}
}
F_19 (path, &widget->sources, list_sink) {
F_50 ( V_122 , V_131 ) ;
if ( V_90 -> V_132 )
continue;
if ( V_90 -> V_121 )
continue;
if ( V_90 -> V_134 && V_90 -> V_57 ) {
V_90 -> V_121 = 1 ;
V_126 += F_51 ( V_90 -> V_134 ) ;
}
}
V_122 -> V_24 = V_126 ;
return V_126 ;
}
int F_52 ( struct V_8 * V_9 ,
struct V_104 * V_93 , int V_135 )
{
unsigned int V_27 ;
if ( F_53 ( V_135 ) )
V_27 = V_9 -> V_136 ;
else
V_27 = V_9 -> V_137 ;
F_27 ( V_9 , - ( V_9 -> V_26 + 1 ) ,
V_9 -> V_28 << V_9 -> V_54 , V_27 << V_9 -> V_54 ) ;
return 0 ;
}
int F_54 ( struct V_8 * V_9 ,
struct V_104 * V_93 , int V_135 )
{
if ( F_53 ( V_135 ) )
return F_55 ( V_9 -> V_138 ) ;
else
return F_56 ( V_9 -> V_138 , V_9 -> V_54 ) ;
}
static int F_57 ( struct V_8 * V_9 )
{
if ( V_9 -> V_23 )
return V_9 -> V_139 ;
if ( V_9 -> V_140 )
V_9 -> V_139 = 1 ;
else
V_9 -> V_139 = V_9 -> V_141 ( V_9 ) ;
V_9 -> V_23 = true ;
return V_9 -> V_139 ;
}
static int F_58 ( struct V_8 * V_9 )
{
int V_142 , V_39 ;
F_50 ( V_9 , V_143 ) ;
V_142 = F_51 ( V_9 ) ;
F_45 ( V_9 -> V_12 ) ;
V_39 = F_49 ( V_9 ) ;
F_45 ( V_9 -> V_12 ) ;
return V_39 != 0 && V_142 != 0 ;
}
static int F_59 ( struct V_8 * V_9 )
{
F_50 ( V_9 , V_143 ) ;
return V_9 -> V_128 ;
}
static int F_60 ( struct V_8 * V_9 )
{
int V_142 ;
F_50 ( V_9 , V_143 ) ;
if ( V_9 -> V_128 ) {
V_142 = F_51 ( V_9 ) ;
F_45 ( V_9 -> V_12 ) ;
return V_142 != 0 ;
} else {
return F_58 ( V_9 ) ;
}
}
static int F_61 ( struct V_8 * V_9 )
{
int V_39 ;
F_50 ( V_9 , V_143 ) ;
if ( V_9 -> V_128 ) {
V_39 = F_49 ( V_9 ) ;
F_45 ( V_9 -> V_12 ) ;
return V_39 != 0 ;
} else {
return F_58 ( V_9 ) ;
}
}
static int F_62 ( struct V_8 * V_9 )
{
struct V_43 * V_90 ;
F_50 ( V_9 , V_143 ) ;
F_19 (path, &w->sinks, list_source) {
F_50 ( V_9 , V_131 ) ;
if ( V_90 -> V_132 )
continue;
if ( V_90 -> V_129 &&
! V_90 -> V_129 ( V_90 -> V_134 , V_90 -> V_133 ) )
continue;
if ( ! V_90 -> V_133 )
continue;
if ( F_57 ( V_90 -> V_133 ) )
return 1 ;
}
F_45 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_63 ( struct V_8 * V_9 )
{
return 1 ;
}
static int F_64 ( struct V_8 * V_144 ,
struct V_8 * V_145 ,
bool V_146 )
{
int * V_147 ;
if ( V_146 )
V_147 = V_148 ;
else
V_147 = V_149 ;
if ( V_147 [ V_144 -> V_46 ] != V_147 [ V_145 -> V_46 ] )
return V_147 [ V_144 -> V_46 ] - V_147 [ V_145 -> V_46 ] ;
if ( V_144 -> V_150 != V_145 -> V_150 ) {
if ( V_146 )
return V_144 -> V_150 - V_145 -> V_150 ;
else
return V_145 -> V_150 - V_144 -> V_150 ;
}
if ( V_144 -> V_26 != V_145 -> V_26 )
return V_144 -> V_26 - V_145 -> V_26 ;
if ( V_144 -> V_12 != V_145 -> V_12 )
return ( unsigned long ) V_144 -> V_12 - ( unsigned long ) V_145 -> V_12 ;
return 0 ;
}
static void F_65 ( struct V_8 * V_151 ,
struct V_152 * V_94 ,
bool V_146 )
{
struct V_8 * V_9 ;
F_19 (w, list, power_list)
if ( F_64 ( V_151 , V_9 , V_146 ) < 0 ) {
F_12 ( & V_151 -> V_153 , & V_9 -> V_153 ) ;
return;
}
F_12 ( & V_151 -> V_153 , V_94 ) ;
}
static void F_66 ( struct V_18 * V_12 ,
struct V_8 * V_9 , int V_135 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
const char * V_154 ;
int V_155 , V_33 ;
switch ( V_135 ) {
case V_156 :
V_154 = L_12 ;
V_155 = 1 ;
break;
case V_157 :
V_154 = L_13 ;
V_155 = 1 ;
break;
case V_158 :
V_154 = L_14 ;
V_155 = 0 ;
break;
case V_159 :
V_154 = L_15 ;
V_155 = 0 ;
break;
default:
F_16 () ;
return;
}
if ( V_9 -> V_155 != V_155 )
return;
if ( V_9 -> V_135 && ( V_9 -> V_160 & V_135 ) ) {
F_4 ( V_12 -> V_3 , V_14 -> V_1 , L_16 ,
V_9 -> V_13 , V_154 ) ;
F_67 ( V_9 , V_135 ) ;
V_33 = V_9 -> V_135 ( V_9 , NULL , V_135 ) ;
F_68 ( V_9 , V_135 ) ;
if ( V_33 < 0 )
F_69 ( L_17 ,
V_154 , V_9 -> V_13 , V_33 ) ;
}
}
static void F_70 ( struct V_18 * V_12 ,
struct V_152 * V_161 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
int V_26 , V_155 ;
unsigned int V_29 = 0 ;
unsigned int V_28 = 0 ;
unsigned int V_162 ;
V_26 = F_71 ( V_161 , struct V_8 ,
V_153 ) -> V_26 ;
F_19 (w, pending, power_list) {
V_162 = 1 << V_9 -> V_54 ;
F_72 ( V_26 != V_9 -> V_26 ) ;
if ( V_9 -> V_56 )
V_155 = ! V_9 -> V_155 ;
else
V_155 = V_9 -> V_155 ;
V_28 |= V_162 ;
if ( V_155 )
V_29 |= V_162 ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_18 ,
V_9 -> V_13 , V_26 , V_29 , V_28 ) ;
F_66 ( V_12 , V_9 , V_156 ) ;
F_66 ( V_12 , V_9 , V_158 ) ;
}
if ( V_26 >= 0 ) {
V_9 = F_71 ( V_161 , struct V_8 ,
V_153 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_19 ,
V_29 , V_28 , V_26 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_27 ( V_9 , V_26 , V_28 , V_29 ) ;
}
F_19 (w, pending, power_list) {
F_66 ( V_12 , V_9 , V_157 ) ;
F_66 ( V_12 , V_9 , V_159 ) ;
}
}
static void F_73 ( struct V_18 * V_12 ,
struct V_152 * V_94 , int V_135 , bool V_146 )
{
struct V_8 * V_9 , * V_163 ;
F_74 ( V_161 ) ;
int V_164 = - 1 ;
int V_165 = - 1 ;
int V_166 = V_167 ;
struct V_18 * V_168 = NULL ;
int V_33 , V_45 ;
int * V_147 ;
if ( V_146 )
V_147 = V_148 ;
else
V_147 = V_149 ;
F_75 (w, n, list, power_list) {
V_33 = 0 ;
if ( V_147 [ V_9 -> V_46 ] != V_164 || V_9 -> V_26 != V_166 ||
V_9 -> V_12 != V_168 || V_9 -> V_150 != V_165 ) {
if ( ! F_9 ( & V_161 ) )
F_70 ( V_168 , & V_161 ) ;
if ( V_168 && V_168 -> V_169 ) {
for ( V_45 = 0 ; V_45 < F_76 ( V_148 ) ; V_45 ++ )
if ( V_147 [ V_45 ] == V_164 )
V_168 -> V_169 ( V_168 ,
V_45 ,
V_165 ) ;
}
F_77 ( & V_161 ) ;
V_164 = - 1 ;
V_165 = V_170 ;
V_166 = V_167 ;
V_168 = NULL ;
}
switch ( V_9 -> V_46 ) {
case V_86 :
if ( ! V_9 -> V_135 )
F_78 ( V_9 , V_163 , V_94 ,
V_153 ) ;
if ( V_135 == V_171 )
V_33 = V_9 -> V_135 ( V_9 ,
NULL , V_156 ) ;
else if ( V_135 == V_172 )
V_33 = V_9 -> V_135 ( V_9 ,
NULL , V_158 ) ;
break;
case V_87 :
if ( ! V_9 -> V_135 )
F_78 ( V_9 , V_163 , V_94 ,
V_153 ) ;
if ( V_135 == V_171 )
V_33 = V_9 -> V_135 ( V_9 ,
NULL , V_157 ) ;
else if ( V_135 == V_172 )
V_33 = V_9 -> V_135 ( V_9 ,
NULL , V_159 ) ;
break;
default:
V_164 = V_147 [ V_9 -> V_46 ] ;
V_165 = V_9 -> V_150 ;
V_166 = V_9 -> V_26 ;
V_168 = V_9 -> V_12 ;
F_79 ( & V_9 -> V_153 , & V_161 ) ;
break;
}
if ( V_33 < 0 )
F_23 ( V_9 -> V_12 -> V_3 ,
L_20 , V_33 ) ;
}
if ( ! F_9 ( & V_161 ) )
F_70 ( V_168 , & V_161 ) ;
if ( V_168 && V_168 -> V_169 ) {
for ( V_45 = 0 ; V_45 < F_76 ( V_148 ) ; V_45 ++ )
if ( V_147 [ V_45 ] == V_164 )
V_168 -> V_169 ( V_168 ,
V_45 , V_165 ) ;
}
}
static void F_80 ( struct V_18 * V_12 )
{
struct V_173 * V_174 = V_12 -> V_174 ;
struct V_8 * V_9 ;
int V_33 ;
if ( ! V_174 )
return;
V_9 = V_174 -> V_122 ;
if ( V_9 -> V_135 &&
( V_9 -> V_160 & V_175 ) ) {
V_33 = V_9 -> V_135 ( V_9 , V_174 -> V_93 , V_175 ) ;
if ( V_33 != 0 )
F_69 ( L_21 ,
V_9 -> V_13 , V_33 ) ;
}
V_33 = F_81 ( V_9 -> V_19 , V_174 -> V_26 , V_174 -> V_28 ,
V_174 -> V_27 ) ;
if ( V_33 < 0 )
F_69 ( L_22 , V_9 -> V_13 , V_33 ) ;
if ( V_9 -> V_135 &&
( V_9 -> V_160 & V_176 ) ) {
V_33 = V_9 -> V_135 ( V_9 , V_174 -> V_93 , V_176 ) ;
if ( V_33 != 0 )
F_69 ( L_23 ,
V_9 -> V_13 , V_33 ) ;
}
}
static void F_82 ( void * V_177 , T_4 V_178 )
{
struct V_18 * V_179 = V_177 ;
int V_33 ;
if ( V_179 -> V_41 == V_180 &&
V_179 -> V_181 != V_180 ) {
if ( V_179 -> V_3 )
F_83 ( V_179 -> V_3 ) ;
V_33 = F_29 ( V_179 , V_182 ) ;
if ( V_33 != 0 )
F_23 ( V_179 -> V_3 ,
L_24 , V_33 ) ;
}
if ( V_179 -> V_41 != V_179 -> V_181 ) {
V_33 = F_29 ( V_179 , V_183 ) ;
if ( V_33 != 0 )
F_23 ( V_179 -> V_3 ,
L_25 , V_33 ) ;
}
}
static void F_84 ( void * V_177 , T_4 V_178 )
{
struct V_18 * V_179 = V_177 ;
int V_33 ;
if ( V_179 -> V_41 == V_183 &&
( V_179 -> V_181 == V_182 ||
V_179 -> V_181 == V_180 ) ) {
V_33 = F_29 ( V_179 , V_182 ) ;
if ( V_33 != 0 )
F_23 ( V_179 -> V_3 , L_26 ,
V_33 ) ;
}
if ( V_179 -> V_41 == V_182 &&
V_179 -> V_181 == V_180 ) {
V_33 = F_29 ( V_179 , V_180 ) ;
if ( V_33 != 0 )
F_23 ( V_179 -> V_3 , L_27 , V_33 ) ;
if ( V_179 -> V_3 )
F_85 ( V_179 -> V_3 ) ;
}
if ( V_179 -> V_41 == V_183 &&
V_179 -> V_181 == V_184 ) {
V_33 = F_29 ( V_179 , V_184 ) ;
if ( V_33 != 0 )
F_23 ( V_179 -> V_3 , L_28 ,
V_33 ) ;
}
}
static void F_86 ( struct V_8 * V_185 ,
bool V_155 , bool V_57 )
{
if ( ! V_57 )
return;
if ( V_155 != V_185 -> V_155 )
F_10 ( V_185 , L_29 ) ;
}
static void F_87 ( struct V_8 * V_9 , bool V_155 ,
struct V_152 * V_186 ,
struct V_152 * V_187 )
{
struct V_43 * V_90 ;
if ( V_9 -> V_155 == V_155 )
return;
F_88 ( V_9 , V_155 ) ;
F_19 (path, &w->sources, list_sink) {
if ( V_90 -> V_134 ) {
F_86 ( V_90 -> V_134 , V_155 ,
V_90 -> V_57 ) ;
}
}
switch ( V_9 -> V_46 ) {
case V_77 :
case V_78 :
break;
default:
F_19 (path, &w->sinks, list_source) {
if ( V_90 -> V_133 ) {
F_86 ( V_90 -> V_133 , V_155 ,
V_90 -> V_57 ) ;
}
}
break;
}
if ( V_155 )
F_65 ( V_9 , V_186 , true ) ;
else
F_65 ( V_9 , V_187 , false ) ;
V_9 -> V_155 = V_155 ;
}
static void F_89 ( struct V_8 * V_9 ,
struct V_152 * V_186 ,
struct V_152 * V_187 )
{
int V_155 ;
switch ( V_9 -> V_46 ) {
case V_86 :
F_65 ( V_9 , V_187 , false ) ;
break;
case V_87 :
F_65 ( V_9 , V_186 , true ) ;
break;
default:
V_155 = F_57 ( V_9 ) ;
F_87 ( V_9 , V_155 , V_186 , V_187 ) ;
break;
}
}
static int F_90 ( struct V_18 * V_12 , int V_135 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
struct V_18 * V_179 ;
F_74 ( V_186 ) ;
F_74 ( V_187 ) ;
F_74 ( V_188 ) ;
enum V_36 V_189 ;
F_91 ( V_14 ) ;
F_19 (d, &card->dapm_list, list) {
if ( V_179 -> V_190 || V_179 -> V_19 == NULL ) {
if ( V_179 -> V_191 )
V_179 -> V_181 = V_180 ;
else
V_179 -> V_181 = V_182 ;
}
}
F_18 ( V_14 ) ;
F_19 (w, &card->dapm_dirty, dirty) {
F_89 ( V_9 , & V_186 , & V_187 ) ;
}
F_19 (w, &card->widgets, list) {
F_92 ( & V_9 -> V_10 ) ;
if ( V_9 -> V_155 ) {
V_179 = V_9 -> V_12 ;
switch ( V_9 -> V_46 ) {
case V_73 :
break;
case V_77 :
case V_78 :
case V_75 :
if ( V_179 -> V_181 < V_182 )
V_179 -> V_181 = V_182 ;
break;
default:
V_179 -> V_181 = V_184 ;
break;
}
}
}
if ( ! V_12 -> V_190 ) {
switch ( V_135 ) {
case V_171 :
case V_192 :
V_12 -> V_181 = V_184 ;
break;
case V_172 :
if ( V_12 -> V_19 && V_12 -> V_19 -> V_128 )
V_12 -> V_181 = V_184 ;
else
V_12 -> V_181 = V_182 ;
break;
case V_193 :
V_12 -> V_181 = V_182 ;
break;
case V_194 :
V_12 -> V_181 = V_12 -> V_41 ;
break;
default:
break;
}
}
V_189 = V_180 ;
F_19 (d, &card->dapm_list, list)
if ( V_179 -> V_181 > V_189 )
V_189 = V_179 -> V_181 ;
F_19 (d, &card->dapm_list, list)
if ( ! V_179 -> V_191 )
V_179 -> V_181 = V_189 ;
F_93 ( V_14 ) ;
F_19 (d, &dapm->card->dapm_list, list)
F_94 ( F_82 , V_179 ,
& V_188 ) ;
F_95 ( & V_188 ) ;
F_73 ( V_12 , & V_187 , V_135 , false ) ;
F_80 ( V_12 ) ;
F_73 ( V_12 , & V_186 , V_135 , true ) ;
F_19 (d, &dapm->card->dapm_list, list)
F_94 ( F_84 , V_179 ,
& V_188 ) ;
F_95 ( & V_188 ) ;
F_19 (d, &card->dapm_list, list) {
if ( V_179 -> V_195 )
V_179 -> V_195 ( V_179 , V_135 ) ;
}
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_30 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_96 ( V_14 ) ;
return 0 ;
}
static T_5 F_97 ( struct V_196 * V_196 ,
char T_6 * V_197 ,
T_3 V_198 , T_7 * V_199 )
{
struct V_8 * V_9 = V_196 -> V_120 ;
char * V_5 ;
int V_142 , V_39 ;
T_5 V_33 ;
struct V_43 * V_44 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_113 ;
V_142 = F_51 ( V_9 ) ;
F_45 ( V_9 -> V_12 ) ;
V_39 = F_49 ( V_9 ) ;
F_45 ( V_9 -> V_12 ) ;
V_33 = snprintf ( V_5 , V_6 , L_31 ,
V_9 -> V_13 , V_9 -> V_155 ? L_32 : L_33 ,
V_9 -> V_140 ? L_34 : L_35 , V_142 , V_39 ) ;
if ( V_9 -> V_26 >= 0 )
V_33 += snprintf ( V_5 + V_33 , V_6 - V_33 ,
L_36 ,
V_9 -> V_26 , V_9 -> V_26 , V_9 -> V_54 ) ;
V_33 += snprintf ( V_5 + V_33 , V_6 - V_33 , L_37 ) ;
if ( V_9 -> V_200 )
V_33 += snprintf ( V_5 + V_33 , V_6 - V_33 , L_38 ,
V_9 -> V_200 ,
V_9 -> V_128 ? L_39 : L_40 ) ;
F_19 (p, &w->sources, list_sink) {
if ( V_44 -> V_129 && ! V_44 -> V_129 ( V_9 , V_44 -> V_133 ) )
continue;
if ( V_44 -> V_57 )
V_33 += snprintf ( V_5 + V_33 , V_6 - V_33 ,
L_41 ,
V_44 -> V_13 ? V_44 -> V_13 : L_42 ,
V_44 -> V_134 -> V_13 ) ;
}
F_19 (p, &w->sinks, list_source) {
if ( V_44 -> V_129 && ! V_44 -> V_129 ( V_9 , V_44 -> V_133 ) )
continue;
if ( V_44 -> V_57 )
V_33 += snprintf ( V_5 + V_33 , V_6 - V_33 ,
L_43 ,
V_44 -> V_13 ? V_44 -> V_13 : L_42 ,
V_44 -> V_133 -> V_13 ) ;
}
V_33 = F_98 ( V_197 , V_198 , V_199 , V_5 , V_33 ) ;
F_7 ( V_5 ) ;
return V_33 ;
}
static T_5 F_99 ( struct V_196 * V_196 , char T_6 * V_197 ,
T_3 V_198 , T_7 * V_199 )
{
struct V_18 * V_12 = V_196 -> V_120 ;
char * V_37 ;
switch ( V_12 -> V_41 ) {
case V_184 :
V_37 = L_44 ;
break;
case V_183 :
V_37 = L_45 ;
break;
case V_182 :
V_37 = L_46 ;
break;
case V_180 :
V_37 = L_47 ;
break;
default:
F_16 () ;
V_37 = L_48 ;
break;
}
return F_98 ( V_197 , V_198 , V_199 , V_37 ,
strlen ( V_37 ) ) ;
}
void F_100 ( struct V_18 * V_12 ,
struct V_201 * V_202 )
{
struct V_201 * V_179 ;
V_12 -> V_203 = F_101 ( L_49 , V_202 ) ;
if ( ! V_12 -> V_203 ) {
F_102 ( V_12 -> V_3 ,
L_50 ) ;
return;
}
V_179 = F_103 ( L_51 , 0444 ,
V_12 -> V_203 , V_12 ,
& V_204 ) ;
if ( ! V_179 )
F_102 ( V_12 -> V_3 ,
L_52 ) ;
}
static void F_104 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_201 * V_179 ;
if ( ! V_12 -> V_203 || ! V_9 -> V_13 )
return;
V_179 = F_103 ( V_9 -> V_13 , 0444 ,
V_12 -> V_203 , V_9 ,
& V_205 ) ;
if ( ! V_179 )
F_102 ( V_9 -> V_12 -> V_3 ,
L_53 ,
V_9 -> V_13 ) ;
}
static void F_105 ( struct V_18 * V_12 )
{
F_106 ( V_12 -> V_203 ) ;
}
void F_100 ( struct V_18 * V_12 ,
struct V_201 * V_202 )
{
}
static inline void F_104 ( struct V_8 * V_9 )
{
}
static inline void F_105 ( struct V_18 * V_12 )
{
}
int F_107 ( struct V_8 * V_122 ,
struct V_104 * V_93 , int V_206 , struct V_59 * V_60 )
{
struct V_43 * V_90 ;
int V_207 = 0 ;
if ( V_122 -> V_46 != V_58 &&
V_122 -> V_46 != V_65 &&
V_122 -> V_46 != V_66 )
return - V_100 ;
F_19 (path, &widget->dapm->card->paths, list) {
if ( V_90 -> V_93 != V_93 )
continue;
if ( ! V_90 -> V_13 || ! V_60 -> V_64 [ V_206 ] )
continue;
V_207 = 1 ;
if ( ! ( strcmp ( V_90 -> V_13 , V_60 -> V_64 [ V_206 ] ) ) ) {
V_90 -> V_57 = 1 ;
F_10 ( V_90 -> V_134 , L_54 ) ;
} else {
if ( V_90 -> V_57 )
F_10 ( V_90 -> V_134 ,
L_55 ) ;
V_90 -> V_57 = 0 ;
}
}
if ( V_207 ) {
F_10 ( V_122 , L_56 ) ;
F_90 ( V_122 -> V_12 , V_194 ) ;
}
return 0 ;
}
int F_108 ( struct V_8 * V_122 ,
struct V_104 * V_93 , int V_57 )
{
struct V_43 * V_90 ;
int V_207 = 0 ;
if ( V_122 -> V_46 != V_48 &&
V_122 -> V_46 != V_49 &&
V_122 -> V_46 != V_47 )
return - V_100 ;
F_19 (path, &widget->dapm->card->paths, list) {
if ( V_90 -> V_93 != V_93 )
continue;
V_207 = 1 ;
V_90 -> V_57 = V_57 ;
F_10 ( V_90 -> V_134 , L_57 ) ;
}
if ( V_207 ) {
F_10 ( V_122 , L_58 ) ;
F_90 ( V_122 -> V_12 , V_194 ) ;
}
return 0 ;
}
static T_5 F_109 ( struct V_2 * V_3 ,
struct V_208 * V_209 , char * V_5 )
{
struct V_210 * V_211 = F_110 ( V_3 ) ;
struct V_212 * V_19 = V_211 -> V_19 ;
struct V_8 * V_9 ;
int V_198 = 0 ;
char * V_213 = L_59 ;
F_19 (w, &codec->card->widgets, list) {
if ( V_9 -> V_12 != & V_19 -> V_12 )
continue;
switch ( V_9 -> V_46 ) {
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_75 :
case V_74 :
case V_71 :
case V_68 :
case V_69 :
case V_48 :
case V_49 :
case V_77 :
case V_78 :
if ( V_9 -> V_13 )
V_198 += sprintf ( V_5 + V_198 , L_60 ,
V_9 -> V_13 , V_9 -> V_155 ? L_32 : L_33 ) ;
break;
default:
break;
}
}
switch ( V_19 -> V_12 . V_41 ) {
case V_184 :
V_213 = L_32 ;
break;
case V_183 :
V_213 = L_61 ;
break;
case V_182 :
V_213 = L_62 ;
break;
case V_180 :
V_213 = L_33 ;
break;
}
V_198 += sprintf ( V_5 + V_198 , L_63 , V_213 ) ;
return V_198 ;
}
int F_111 ( struct V_2 * V_3 )
{
return F_112 ( V_3 , & V_214 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
F_114 ( V_3 , & V_214 ) ;
}
static void F_115 ( struct V_18 * V_12 )
{
struct V_8 * V_9 , * V_215 ;
struct V_43 * V_44 , * V_216 ;
F_75 (w, next_w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
F_116 ( & V_9 -> V_94 ) ;
F_75 (p, next_p, &w->sources, list_sink) {
F_116 ( & V_44 -> V_96 ) ;
F_116 ( & V_44 -> V_98 ) ;
F_116 ( & V_44 -> V_94 ) ;
F_7 ( V_44 -> V_116 ) ;
F_7 ( V_44 ) ;
}
F_75 (p, next_p, &w->sinks, list_source) {
F_116 ( & V_44 -> V_96 ) ;
F_116 ( & V_44 -> V_98 ) ;
F_116 ( & V_44 -> V_94 ) ;
F_7 ( V_44 -> V_116 ) ;
F_7 ( V_44 ) ;
}
F_7 ( V_9 -> V_105 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
}
static struct V_8 * F_117 (
struct V_18 * V_12 , const char * V_217 ,
bool V_218 )
{
struct V_8 * V_9 ;
struct V_8 * V_219 = NULL ;
F_19 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_9 -> V_13 , V_217 ) ) {
if ( V_9 -> V_12 == V_12 )
return V_9 ;
else
V_219 = V_9 ;
}
}
if ( V_218 )
return V_219 ;
return NULL ;
}
static int F_118 ( struct V_18 * V_12 ,
const char * V_217 , int V_220 )
{
struct V_8 * V_9 = F_117 ( V_12 , V_217 , true ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_64 , V_217 ) ;
return - V_119 ;
}
if ( V_9 -> V_129 != V_220 )
F_10 ( V_9 , L_65 ) ;
V_9 -> V_129 = V_220 ;
if ( V_220 == 0 )
V_9 -> V_140 = 0 ;
return 0 ;
}
int F_119 ( struct V_18 * V_12 )
{
if ( ! V_12 -> V_14 || ! V_12 -> V_14 -> V_221 )
return 0 ;
return F_90 ( V_12 , V_194 ) ;
}
static int F_120 ( struct V_18 * V_12 ,
const struct V_222 * V_223 )
{
struct V_43 * V_90 ;
struct V_8 * V_224 = NULL , * V_225 = NULL , * V_9 ;
struct V_8 * V_226 = NULL , * V_227 = NULL ;
const char * V_133 ;
const char * V_228 = V_223 -> V_228 ;
const char * V_134 ;
char V_229 [ 80 ] ;
char V_230 [ 80 ] ;
int V_33 = 0 ;
if ( V_12 -> V_19 && V_12 -> V_19 -> V_112 ) {
snprintf ( V_229 , sizeof( V_229 ) , L_6 ,
V_12 -> V_19 -> V_112 , V_223 -> V_133 ) ;
V_133 = V_229 ;
snprintf ( V_230 , sizeof( V_230 ) , L_6 ,
V_12 -> V_19 -> V_112 , V_223 -> V_134 ) ;
V_134 = V_230 ;
} else {
V_133 = V_223 -> V_133 ;
V_134 = V_223 -> V_134 ;
}
F_19 (w, &dapm->card->widgets, list) {
if ( ! V_225 && ! ( strcmp ( V_9 -> V_13 , V_133 ) ) ) {
V_227 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_225 = V_9 ;
continue;
}
if ( ! V_224 && ! ( strcmp ( V_9 -> V_13 , V_134 ) ) ) {
V_226 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_224 = V_9 ;
}
}
if ( ! V_225 )
V_225 = V_227 ;
if ( ! V_224 )
V_224 = V_226 ;
if ( V_224 == NULL || V_225 == NULL )
return - V_100 ;
V_90 = F_39 ( sizeof( struct V_43 ) , V_7 ) ;
if ( ! V_90 )
return - V_113 ;
V_90 -> V_134 = V_224 ;
V_90 -> V_133 = V_225 ;
V_90 -> V_129 = V_223 -> V_129 ;
F_77 ( & V_90 -> V_94 ) ;
F_77 ( & V_90 -> V_98 ) ;
F_77 ( & V_90 -> V_96 ) ;
if ( V_225 -> V_46 == V_72 ) {
if ( V_224 -> V_46 == V_75 ||
V_224 -> V_46 == V_83 ||
V_224 -> V_46 == V_85 ||
V_224 -> V_46 == V_70 )
V_225 -> V_130 = 1 ;
}
if ( V_224 -> V_46 == V_70 ) {
if ( V_225 -> V_46 == V_84 ||
V_225 -> V_46 == V_82 ||
V_225 -> V_46 == V_85 ||
V_225 -> V_46 == V_72 )
V_224 -> V_130 = 1 ;
}
if ( V_228 == NULL ) {
F_35 ( & V_90 -> V_94 , & V_12 -> V_14 -> V_95 ) ;
F_35 ( & V_90 -> V_96 , & V_225 -> V_97 ) ;
F_35 ( & V_90 -> V_98 , & V_224 -> V_99 ) ;
V_90 -> V_57 = 1 ;
return 0 ;
}
switch ( V_225 -> V_46 ) {
case V_71 :
case V_74 :
case V_68 :
case V_69 :
case V_72 :
case V_70 :
case V_73 :
case V_75 :
case V_76 :
case V_86 :
case V_87 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
F_35 ( & V_90 -> V_94 , & V_12 -> V_14 -> V_95 ) ;
F_35 ( & V_90 -> V_96 , & V_225 -> V_97 ) ;
F_35 ( & V_90 -> V_98 , & V_224 -> V_99 ) ;
V_90 -> V_57 = 1 ;
return 0 ;
case V_58 :
case V_65 :
case V_66 :
V_33 = F_34 ( V_12 , V_224 , V_225 , V_90 , V_228 ,
& V_225 -> V_52 [ 0 ] ) ;
if ( V_33 != 0 )
goto V_231;
break;
case V_47 :
case V_48 :
case V_49 :
V_33 = F_36 ( V_12 , V_224 , V_225 , V_90 , V_228 ) ;
if ( V_33 != 0 )
goto V_231;
break;
case V_82 :
case V_83 :
case V_85 :
case V_84 :
F_35 ( & V_90 -> V_94 , & V_12 -> V_14 -> V_95 ) ;
F_35 ( & V_90 -> V_96 , & V_225 -> V_97 ) ;
F_35 ( & V_90 -> V_98 , & V_224 -> V_99 ) ;
V_90 -> V_57 = 0 ;
return 0 ;
}
return 0 ;
V_231:
F_102 ( V_12 -> V_3 , L_66 ,
V_134 , V_228 , V_133 ) ;
F_7 ( V_90 ) ;
return V_33 ;
}
int F_121 ( struct V_18 * V_12 ,
const struct V_222 * V_223 , int V_232 )
{
int V_45 , V_33 ;
for ( V_45 = 0 ; V_45 < V_232 ; V_45 ++ ) {
V_33 = F_120 ( V_12 , V_223 ) ;
if ( V_33 < 0 ) {
F_23 ( V_12 -> V_3 , L_67 ,
V_223 -> V_134 , V_223 -> V_133 ) ;
return V_33 ;
}
V_223 ++ ;
}
return 0 ;
}
static int F_122 ( struct V_18 * V_12 ,
const struct V_222 * V_223 )
{
struct V_8 * V_134 = F_117 ( V_12 ,
V_223 -> V_134 ,
true ) ;
struct V_8 * V_133 = F_117 ( V_12 ,
V_223 -> V_133 ,
true ) ;
struct V_43 * V_90 ;
int V_198 = 0 ;
if ( ! V_134 ) {
F_23 ( V_12 -> V_3 , L_68 ,
V_223 -> V_134 ) ;
return - V_100 ;
}
if ( ! V_133 ) {
F_23 ( V_12 -> V_3 , L_69 ,
V_223 -> V_133 ) ;
return - V_100 ;
}
if ( V_223 -> V_228 || V_223 -> V_129 )
F_102 ( V_12 -> V_3 , L_70 ,
V_223 -> V_134 , V_223 -> V_133 ) ;
F_19 (path, &source->sinks, list_source) {
if ( V_90 -> V_133 == V_133 ) {
V_90 -> V_132 = 1 ;
V_198 ++ ;
}
}
if ( V_198 == 0 )
F_23 ( V_12 -> V_3 , L_71 ,
V_223 -> V_134 , V_223 -> V_133 ) ;
if ( V_198 > 1 )
F_102 ( V_12 -> V_3 , L_72 ,
V_198 , V_223 -> V_134 , V_223 -> V_133 ) ;
return 0 ;
}
int F_123 ( struct V_18 * V_12 ,
const struct V_222 * V_223 , int V_232 )
{
int V_45 , V_231 ;
int V_33 = 0 ;
for ( V_45 = 0 ; V_45 < V_232 ; V_45 ++ ) {
V_231 = F_122 ( V_12 , V_223 ) ;
if ( V_231 )
V_33 = V_231 ;
V_223 ++ ;
}
return V_33 ;
}
int F_124 ( struct V_18 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
F_19 (w, &dapm->card->widgets, list)
{
if ( V_9 -> V_32 )
continue;
if ( V_9 -> V_101 ) {
V_9 -> V_105 = F_39 ( V_9 -> V_101 *
sizeof( struct V_104 * ) ,
V_7 ) ;
if ( ! V_9 -> V_105 )
return - V_113 ;
}
switch( V_9 -> V_46 ) {
case V_47 :
case V_48 :
case V_49 :
F_38 ( V_9 ) ;
break;
case V_58 :
case V_65 :
case V_66 :
F_42 ( V_9 ) ;
break;
case V_68 :
case V_69 :
F_44 ( V_9 ) ;
break;
default:
break;
}
if ( V_9 -> V_26 >= 0 ) {
V_27 = F_20 ( V_9 , V_9 -> V_26 ) ;
V_27 &= 1 << V_9 -> V_54 ;
if ( V_9 -> V_56 )
V_27 = ! V_27 ;
if ( V_27 )
V_9 -> V_155 = 1 ;
}
V_9 -> V_32 = 1 ;
F_10 ( V_9 , L_73 ) ;
F_104 ( V_9 ) ;
}
F_90 ( V_12 , V_194 ) ;
return 0 ;
}
int F_125 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_109 * V_110 = F_126 ( V_93 ) ;
struct V_8 * V_122 = V_110 -> V_115 [ 0 ] ;
struct V_50 * V_51 =
(struct V_50 * ) V_93 -> V_53 ;
unsigned int V_26 = V_51 -> V_26 ;
unsigned int V_54 = V_51 -> V_54 ;
unsigned int V_235 = V_51 -> V_235 ;
int V_55 = V_51 -> V_55 ;
unsigned int V_56 = V_51 -> V_56 ;
unsigned int V_28 = ( 1 << F_33 ( V_55 ) ) - 1 ;
V_234 -> V_29 . integer . V_29 [ 0 ] =
( F_21 ( V_122 -> V_19 , V_26 ) >> V_54 ) & V_28 ;
if ( V_54 != V_235 )
V_234 -> V_29 . integer . V_29 [ 1 ] =
( F_21 ( V_122 -> V_19 , V_26 ) >> V_235 ) & V_28 ;
if ( V_56 ) {
V_234 -> V_29 . integer . V_29 [ 0 ] =
V_55 - V_234 -> V_29 . integer . V_29 [ 0 ] ;
if ( V_54 != V_235 )
V_234 -> V_29 . integer . V_29 [ 1 ] =
V_55 - V_234 -> V_29 . integer . V_29 [ 1 ] ;
}
return 0 ;
}
int F_127 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_109 * V_110 = F_126 ( V_93 ) ;
struct V_8 * V_122 = V_110 -> V_115 [ 0 ] ;
struct V_212 * V_19 = V_122 -> V_19 ;
struct V_50 * V_51 =
(struct V_50 * ) V_93 -> V_53 ;
unsigned int V_26 = V_51 -> V_26 ;
unsigned int V_54 = V_51 -> V_54 ;
int V_55 = V_51 -> V_55 ;
unsigned int V_28 = ( 1 << F_33 ( V_55 ) ) - 1 ;
unsigned int V_56 = V_51 -> V_56 ;
unsigned int V_27 ;
int V_57 , V_30 ;
struct V_173 V_174 ;
int V_236 ;
V_27 = ( V_234 -> V_29 . integer . V_29 [ 0 ] & V_28 ) ;
if ( V_56 )
V_27 = V_55 - V_27 ;
V_28 = V_28 << V_54 ;
V_27 = V_27 << V_54 ;
if ( V_27 )
V_57 = V_56 ? 0 : 1 ;
else
V_57 = V_56 ? 1 : 0 ;
F_128 ( & V_19 -> V_237 ) ;
V_30 = F_129 ( V_122 -> V_19 , V_26 , V_28 , V_27 ) ;
if ( V_30 ) {
for ( V_236 = 0 ; V_236 < V_110 -> V_114 ; V_236 ++ ) {
V_122 = V_110 -> V_115 [ V_236 ] ;
V_122 -> V_29 = V_27 ;
V_174 . V_93 = V_93 ;
V_174 . V_122 = V_122 ;
V_174 . V_26 = V_26 ;
V_174 . V_28 = V_28 ;
V_174 . V_27 = V_27 ;
V_122 -> V_12 -> V_174 = & V_174 ;
F_108 ( V_122 , V_93 , V_57 ) ;
V_122 -> V_12 -> V_174 = NULL ;
}
}
F_130 ( & V_19 -> V_237 ) ;
return 0 ;
}
int F_131 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_109 * V_110 = F_126 ( V_93 ) ;
struct V_8 * V_122 = V_110 -> V_115 [ 0 ] ;
struct V_59 * V_60 = (struct V_59 * ) V_93 -> V_53 ;
unsigned int V_27 , V_62 ;
for ( V_62 = 1 ; V_62 < V_60 -> V_55 ; V_62 <<= 1 )
;
V_27 = F_21 ( V_122 -> V_19 , V_60 -> V_26 ) ;
V_234 -> V_29 . V_238 . V_61 [ 0 ] = ( V_27 >> V_60 -> V_63 ) & ( V_62 - 1 ) ;
if ( V_60 -> V_63 != V_60 -> V_239 )
V_234 -> V_29 . V_238 . V_61 [ 1 ] =
( V_27 >> V_60 -> V_239 ) & ( V_62 - 1 ) ;
return 0 ;
}
int F_132 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_109 * V_110 = F_126 ( V_93 ) ;
struct V_8 * V_122 = V_110 -> V_115 [ 0 ] ;
struct V_212 * V_19 = V_122 -> V_19 ;
struct V_59 * V_60 = (struct V_59 * ) V_93 -> V_53 ;
unsigned int V_27 , V_206 , V_30 ;
unsigned int V_28 , V_62 ;
struct V_173 V_174 ;
int V_236 ;
for ( V_62 = 1 ; V_62 < V_60 -> V_55 ; V_62 <<= 1 )
;
if ( V_234 -> V_29 . V_238 . V_61 [ 0 ] > V_60 -> V_55 - 1 )
return - V_119 ;
V_206 = V_234 -> V_29 . V_238 . V_61 [ 0 ] ;
V_27 = V_206 << V_60 -> V_63 ;
V_28 = ( V_62 - 1 ) << V_60 -> V_63 ;
if ( V_60 -> V_63 != V_60 -> V_239 ) {
if ( V_234 -> V_29 . V_238 . V_61 [ 1 ] > V_60 -> V_55 - 1 )
return - V_119 ;
V_27 |= V_234 -> V_29 . V_238 . V_61 [ 1 ] << V_60 -> V_239 ;
V_28 |= ( V_62 - 1 ) << V_60 -> V_239 ;
}
F_128 ( & V_19 -> V_237 ) ;
V_30 = F_129 ( V_122 -> V_19 , V_60 -> V_26 , V_28 , V_27 ) ;
if ( V_30 ) {
for ( V_236 = 0 ; V_236 < V_110 -> V_114 ; V_236 ++ ) {
V_122 = V_110 -> V_115 [ V_236 ] ;
V_122 -> V_29 = V_27 ;
V_174 . V_93 = V_93 ;
V_174 . V_122 = V_122 ;
V_174 . V_26 = V_60 -> V_26 ;
V_174 . V_28 = V_28 ;
V_174 . V_27 = V_27 ;
V_122 -> V_12 -> V_174 = & V_174 ;
F_107 ( V_122 , V_93 , V_206 , V_60 ) ;
V_122 -> V_12 -> V_174 = NULL ;
}
}
F_130 ( & V_19 -> V_237 ) ;
return V_30 ;
}
int F_133 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_109 * V_110 = F_126 ( V_93 ) ;
struct V_8 * V_122 = V_110 -> V_115 [ 0 ] ;
V_234 -> V_29 . V_238 . V_61 [ 0 ] = V_122 -> V_29 ;
return 0 ;
}
int F_134 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_109 * V_110 = F_126 ( V_93 ) ;
struct V_8 * V_122 = V_110 -> V_115 [ 0 ] ;
struct V_212 * V_19 = V_122 -> V_19 ;
struct V_59 * V_60 =
(struct V_59 * ) V_93 -> V_53 ;
int V_30 ;
int V_33 = 0 ;
int V_236 ;
if ( V_234 -> V_29 . V_238 . V_61 [ 0 ] >= V_60 -> V_55 )
return - V_119 ;
F_128 ( & V_19 -> V_237 ) ;
V_30 = V_122 -> V_29 != V_234 -> V_29 . V_238 . V_61 [ 0 ] ;
if ( V_30 ) {
for ( V_236 = 0 ; V_236 < V_110 -> V_114 ; V_236 ++ ) {
V_122 = V_110 -> V_115 [ V_236 ] ;
V_122 -> V_29 = V_234 -> V_29 . V_238 . V_61 [ 0 ] ;
F_107 ( V_122 , V_93 , V_122 -> V_29 , V_60 ) ;
}
}
F_130 ( & V_19 -> V_237 ) ;
return V_33 ;
}
int F_135 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_109 * V_110 = F_126 ( V_93 ) ;
struct V_8 * V_122 = V_110 -> V_115 [ 0 ] ;
struct V_59 * V_60 = (struct V_59 * ) V_93 -> V_53 ;
unsigned int V_240 , V_27 , V_206 ;
V_240 = F_21 ( V_122 -> V_19 , V_60 -> V_26 ) ;
V_27 = ( V_240 >> V_60 -> V_63 ) & V_60 -> V_28 ;
for ( V_206 = 0 ; V_206 < V_60 -> V_55 ; V_206 ++ ) {
if ( V_27 == V_60 -> V_67 [ V_206 ] )
break;
}
V_234 -> V_29 . V_238 . V_61 [ 0 ] = V_206 ;
if ( V_60 -> V_63 != V_60 -> V_239 ) {
V_27 = ( V_240 >> V_60 -> V_239 ) & V_60 -> V_28 ;
for ( V_206 = 0 ; V_206 < V_60 -> V_55 ; V_206 ++ ) {
if ( V_27 == V_60 -> V_67 [ V_206 ] )
break;
}
V_234 -> V_29 . V_238 . V_61 [ 1 ] = V_206 ;
}
return 0 ;
}
int F_136 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_109 * V_110 = F_126 ( V_93 ) ;
struct V_8 * V_122 = V_110 -> V_115 [ 0 ] ;
struct V_212 * V_19 = V_122 -> V_19 ;
struct V_59 * V_60 = (struct V_59 * ) V_93 -> V_53 ;
unsigned int V_27 , V_206 , V_30 ;
unsigned int V_28 ;
struct V_173 V_174 ;
int V_236 ;
if ( V_234 -> V_29 . V_238 . V_61 [ 0 ] > V_60 -> V_55 - 1 )
return - V_119 ;
V_206 = V_234 -> V_29 . V_238 . V_61 [ 0 ] ;
V_27 = V_60 -> V_67 [ V_234 -> V_29 . V_238 . V_61 [ 0 ] ] << V_60 -> V_63 ;
V_28 = V_60 -> V_28 << V_60 -> V_63 ;
if ( V_60 -> V_63 != V_60 -> V_239 ) {
if ( V_234 -> V_29 . V_238 . V_61 [ 1 ] > V_60 -> V_55 - 1 )
return - V_119 ;
V_27 |= V_60 -> V_67 [ V_234 -> V_29 . V_238 . V_61 [ 1 ] ] << V_60 -> V_239 ;
V_28 |= V_60 -> V_28 << V_60 -> V_239 ;
}
F_128 ( & V_19 -> V_237 ) ;
V_30 = F_129 ( V_122 -> V_19 , V_60 -> V_26 , V_28 , V_27 ) ;
if ( V_30 ) {
for ( V_236 = 0 ; V_236 < V_110 -> V_114 ; V_236 ++ ) {
V_122 = V_110 -> V_115 [ V_236 ] ;
V_122 -> V_29 = V_27 ;
V_174 . V_93 = V_93 ;
V_174 . V_122 = V_122 ;
V_174 . V_26 = V_60 -> V_26 ;
V_174 . V_28 = V_28 ;
V_174 . V_27 = V_27 ;
V_122 -> V_12 -> V_174 = & V_174 ;
F_107 ( V_122 , V_93 , V_206 , V_60 ) ;
V_122 -> V_12 -> V_174 = NULL ;
}
}
F_130 ( & V_19 -> V_237 ) ;
return V_30 ;
}
int F_137 ( struct V_104 * V_93 ,
struct V_241 * V_242 )
{
V_242 -> type = V_243 ;
V_242 -> V_198 = 1 ;
V_242 -> V_29 . integer . V_244 = 0 ;
V_242 -> V_29 . integer . V_55 = 1 ;
return 0 ;
}
int F_138 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_21 * V_14 = F_126 ( V_93 ) ;
const char * V_217 = ( const char * ) V_93 -> V_53 ;
F_128 ( & V_14 -> V_237 ) ;
V_234 -> V_29 . integer . V_29 [ 0 ] =
F_139 ( & V_14 -> V_12 , V_217 ) ;
F_130 ( & V_14 -> V_237 ) ;
return 0 ;
}
int F_140 ( struct V_104 * V_93 ,
struct V_233 * V_234 )
{
struct V_21 * V_14 = F_126 ( V_93 ) ;
const char * V_217 = ( const char * ) V_93 -> V_53 ;
F_128 ( & V_14 -> V_237 ) ;
if ( V_234 -> V_29 . integer . V_29 [ 0 ] )
F_141 ( & V_14 -> V_12 , V_217 ) ;
else
F_142 ( & V_14 -> V_12 , V_217 ) ;
F_119 ( & V_14 -> V_12 ) ;
F_130 ( & V_14 -> V_237 ) ;
return 0 ;
}
static struct V_8 *
F_143 ( struct V_18 * V_12 ,
const struct V_8 * V_122 )
{
struct V_8 * V_9 ;
T_3 V_106 ;
int V_33 ;
if ( ( V_9 = F_13 ( V_122 ) ) == NULL )
return NULL ;
switch ( V_9 -> V_46 ) {
case V_78 :
V_9 -> V_138 = F_144 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_145 ( V_9 -> V_138 ) ) {
V_33 = F_146 ( V_9 -> V_138 ) ;
F_23 ( V_12 -> V_3 , L_74 ,
V_9 -> V_13 , V_33 ) ;
return NULL ;
}
break;
default:
break;
}
V_106 = strlen ( V_122 -> V_13 ) + 1 ;
if ( V_12 -> V_19 && V_12 -> V_19 -> V_112 )
V_106 += 1 + strlen ( V_12 -> V_19 -> V_112 ) ;
V_9 -> V_13 = F_5 ( V_106 , V_7 ) ;
if ( V_9 -> V_13 == NULL ) {
F_7 ( V_9 ) ;
return NULL ;
}
if ( V_12 -> V_19 && V_12 -> V_19 -> V_112 )
snprintf ( ( char * ) V_9 -> V_13 , V_106 , L_6 ,
V_12 -> V_19 -> V_112 , V_122 -> V_13 ) ;
else
snprintf ( ( char * ) V_9 -> V_13 , V_106 , L_1 , V_122 -> V_13 ) ;
switch ( V_9 -> V_46 ) {
case V_47 :
case V_48 :
case V_49 :
V_9 -> V_141 = F_58 ;
break;
case V_58 :
case V_65 :
case V_66 :
V_9 -> V_141 = F_58 ;
break;
case V_71 :
case V_80 :
V_9 -> V_141 = F_60 ;
break;
case V_74 :
case V_79 :
V_9 -> V_141 = F_61 ;
break;
case V_68 :
case V_69 :
case V_72 :
case V_70 :
case V_75 :
case V_84 :
case V_82 :
case V_83 :
case V_85 :
V_9 -> V_141 = F_58 ;
break;
case V_77 :
case V_78 :
V_9 -> V_141 = F_62 ;
break;
case V_81 :
V_9 -> V_141 = F_59 ;
break;
default:
V_9 -> V_141 = F_63 ;
break;
}
V_12 -> V_190 ++ ;
V_9 -> V_12 = V_12 ;
V_9 -> V_19 = V_12 -> V_19 ;
V_9 -> V_20 = V_12 -> V_20 ;
F_77 ( & V_9 -> V_97 ) ;
F_77 ( & V_9 -> V_99 ) ;
F_77 ( & V_9 -> V_94 ) ;
F_77 ( & V_9 -> V_10 ) ;
F_35 ( & V_9 -> V_94 , & V_12 -> V_14 -> V_115 ) ;
V_9 -> V_129 = 1 ;
return V_9 ;
}
int F_147 ( struct V_18 * V_12 ,
const struct V_8 * V_122 ,
int V_232 )
{
struct V_8 * V_9 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_232 ; V_45 ++ ) {
V_9 = F_143 ( V_12 , V_122 ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 ,
L_75 ,
V_122 -> V_13 ) ;
return - V_113 ;
}
V_122 ++ ;
}
return 0 ;
}
int F_148 ( struct V_18 * V_12 ,
struct V_245 * V_246 )
{
struct V_8 V_247 ;
struct V_8 * V_9 ;
F_149 ( V_12 -> V_3 != V_246 -> V_3 ) ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_26 = V_167 ;
if ( V_246 -> V_40 -> V_248 . V_249 ) {
V_247 . V_46 = V_81 ;
V_247 . V_13 = V_246 -> V_40 -> V_248 . V_249 ;
V_247 . V_200 = V_246 -> V_40 -> V_248 . V_249 ;
F_48 ( V_246 -> V_3 , L_76 ,
V_247 . V_13 ) ;
V_9 = F_143 ( V_12 , & V_247 ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_77 ,
V_246 -> V_40 -> V_248 . V_249 ) ;
}
V_9 -> V_138 = V_246 ;
V_246 -> V_250 = V_9 ;
}
if ( V_246 -> V_40 -> V_251 . V_249 ) {
V_247 . V_46 = V_81 ;
V_247 . V_13 = V_246 -> V_40 -> V_251 . V_249 ;
V_247 . V_200 = V_246 -> V_40 -> V_251 . V_249 ;
F_48 ( V_246 -> V_3 , L_76 ,
V_247 . V_13 ) ;
V_9 = F_143 ( V_12 , & V_247 ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_77 ,
V_246 -> V_40 -> V_251 . V_249 ) ;
}
V_9 -> V_138 = V_246 ;
V_246 -> V_252 = V_9 ;
}
return 0 ;
}
int F_150 ( struct V_21 * V_14 )
{
struct V_8 * V_253 , * V_9 ;
struct V_245 * V_246 ;
struct V_222 V_254 ;
memset ( & V_254 , 0 , sizeof( V_254 ) ) ;
F_19 (dai_w, &card->widgets, list) {
if ( V_253 -> V_46 != V_81 )
continue;
V_246 = V_253 -> V_138 ;
F_19 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_253 -> V_12 )
continue;
if ( V_9 -> V_46 == V_81 )
continue;
if ( ! V_9 -> V_200 )
continue;
if ( V_246 -> V_40 -> V_248 . V_249 &&
strstr ( V_9 -> V_200 ,
V_246 -> V_40 -> V_248 . V_249 ) ) {
V_254 . V_134 = V_246 -> V_250 -> V_13 ;
V_254 . V_133 = V_9 -> V_13 ;
F_48 ( V_246 -> V_3 , L_78 ,
V_254 . V_134 , V_254 . V_133 ) ;
F_120 ( V_9 -> V_12 , & V_254 ) ;
}
if ( V_246 -> V_40 -> V_251 . V_249 &&
strstr ( V_9 -> V_200 ,
V_246 -> V_40 -> V_251 . V_249 ) ) {
V_254 . V_134 = V_9 -> V_13 ;
V_254 . V_133 = V_246 -> V_252 -> V_13 ;
F_48 ( V_246 -> V_3 , L_78 ,
V_254 . V_134 , V_254 . V_133 ) ;
F_120 ( V_9 -> V_12 , & V_254 ) ;
}
}
}
return 0 ;
}
static void F_151 ( struct V_18 * V_12 ,
int V_255 , struct V_245 * V_246 ,
int V_135 )
{
struct V_8 * V_9 ;
if ( V_255 == V_256 )
V_9 = V_246 -> V_250 ;
else
V_9 = V_246 -> V_252 ;
if ( ! V_9 )
return;
F_10 ( V_9 , L_79 ) ;
switch ( V_135 ) {
case V_171 :
V_9 -> V_128 = 1 ;
break;
case V_172 :
V_9 -> V_128 = 0 ;
break;
case V_193 :
case V_192 :
case V_257 :
case V_258 :
break;
}
F_90 ( V_12 , V_135 ) ;
}
int F_152 ( struct V_210 * V_211 , int V_255 ,
struct V_245 * V_246 , int V_135 )
{
struct V_212 * V_19 = V_211 -> V_19 ;
F_128 ( & V_19 -> V_237 ) ;
F_151 ( & V_19 -> V_12 , V_255 , V_246 , V_135 ) ;
F_130 ( & V_19 -> V_237 ) ;
return 0 ;
}
int F_141 ( struct V_18 * V_12 , const char * V_217 )
{
return F_118 ( V_12 , V_217 , 1 ) ;
}
int F_153 ( struct V_18 * V_12 ,
const char * V_217 )
{
struct V_8 * V_9 = F_117 ( V_12 , V_217 , true ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_64 , V_217 ) ;
return - V_119 ;
}
F_48 ( V_9 -> V_12 -> V_3 , L_80 , V_217 ) ;
V_9 -> V_129 = 1 ;
V_9 -> V_140 = 1 ;
F_10 ( V_9 , L_81 ) ;
return 0 ;
}
int F_142 ( struct V_18 * V_12 ,
const char * V_217 )
{
return F_118 ( V_12 , V_217 , 0 ) ;
}
int F_154 ( struct V_18 * V_12 , const char * V_217 )
{
return F_118 ( V_12 , V_217 , 0 ) ;
}
int F_139 ( struct V_18 * V_12 ,
const char * V_217 )
{
struct V_8 * V_9 = F_117 ( V_12 , V_217 , true ) ;
if ( V_9 )
return V_9 -> V_129 ;
return 0 ;
}
int F_155 ( struct V_18 * V_12 ,
const char * V_217 )
{
struct V_8 * V_9 = F_117 ( V_12 , V_217 , false ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_64 , V_217 ) ;
return - V_119 ;
}
V_9 -> V_125 = 1 ;
return 0 ;
}
static bool F_156 ( struct V_21 * V_14 ,
struct V_8 * V_9 )
{
struct V_43 * V_44 ;
F_19 (p, &card->paths, list) {
if ( ( V_44 -> V_134 == V_9 ) || ( V_44 -> V_133 == V_9 ) ) {
F_48 ( V_14 -> V_3 ,
L_82 ,
V_44 -> V_134 -> V_13 , V_44 -> V_134 -> V_46 , V_44 -> V_134 -> V_12 ,
V_44 -> V_133 -> V_13 , V_44 -> V_133 -> V_46 , V_44 -> V_133 -> V_12 ) ;
if ( V_44 -> V_134 -> V_12 != V_44 -> V_133 -> V_12 )
return true ;
if ( V_44 -> V_133 -> V_46 == V_72 ) {
switch ( V_44 -> V_134 -> V_46 ) {
case V_70 :
case V_75 :
return true ;
default:
break;
}
}
}
}
return false ;
}
void F_157 ( struct V_212 * V_19 )
{
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_18 * V_12 = & V_19 -> V_12 ;
struct V_8 * V_9 ;
F_48 ( V_19 -> V_3 , L_83 ,
& V_14 -> V_12 , & V_19 -> V_12 ) ;
F_19 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
switch ( V_9 -> V_46 ) {
case V_72 :
case V_70 :
case V_75 :
F_48 ( V_19 -> V_3 , L_84 ,
V_9 -> V_13 ) ;
if ( ! F_156 ( V_14 , V_9 ) ) {
F_48 ( V_19 -> V_3 ,
L_85 ) ;
F_154 ( V_12 , V_9 -> V_13 ) ;
}
break;
default:
break;
}
}
}
void F_158 ( struct V_18 * V_12 )
{
F_113 ( V_12 -> V_3 ) ;
F_105 ( V_12 ) ;
F_115 ( V_12 ) ;
F_116 ( & V_12 -> V_94 ) ;
}
static void F_159 ( struct V_18 * V_12 )
{
struct V_8 * V_9 ;
F_74 ( V_187 ) ;
int V_259 = 0 ;
F_19 (w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
if ( V_9 -> V_155 ) {
F_65 ( V_9 , & V_187 , false ) ;
V_9 -> V_155 = 0 ;
V_259 = 1 ;
}
}
if ( V_259 ) {
if ( V_12 -> V_41 == V_184 )
F_29 ( V_12 ,
V_183 ) ;
F_73 ( V_12 , & V_187 , 0 , false ) ;
if ( V_12 -> V_41 == V_183 )
F_29 ( V_12 ,
V_182 ) ;
}
}
void F_160 ( struct V_21 * V_14 )
{
struct V_212 * V_19 ;
F_19 (codec, &card->codec_dev_list, list) {
F_159 ( & V_19 -> V_12 ) ;
if ( V_19 -> V_12 . V_41 == V_182 )
F_29 ( & V_19 -> V_12 ,
V_180 ) ;
}
}
