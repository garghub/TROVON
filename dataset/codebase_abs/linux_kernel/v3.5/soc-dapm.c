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
static inline void F_27 ( struct V_8 * V_9 )
{
if ( V_9 -> V_19 && ! V_9 -> V_19 -> V_28 )
F_28 ( & V_9 -> V_19 -> V_29 ) ;
else if ( V_9 -> V_20 )
F_28 ( & V_9 -> V_20 -> V_29 ) ;
}
static inline void F_29 ( struct V_8 * V_9 )
{
if ( V_9 -> V_19 && ! V_9 -> V_19 -> V_28 )
F_30 ( & V_9 -> V_19 -> V_29 ) ;
else if ( V_9 -> V_20 )
F_30 ( & V_9 -> V_20 -> V_29 ) ;
}
static int F_31 ( struct V_8 * V_9 ,
unsigned short V_26 , unsigned int V_30 , unsigned int V_31 )
{
bool V_32 ;
unsigned int V_33 , V_34 ;
int V_35 ;
if ( V_9 -> V_19 && V_9 -> V_19 -> V_28 ) {
V_35 = F_32 ( V_9 -> V_19 -> V_36 ,
V_26 , V_30 , V_31 , & V_32 ) ;
if ( V_35 != 0 )
return V_35 ;
} else {
F_27 ( V_9 ) ;
V_35 = F_20 ( V_9 , V_26 ) ;
if ( V_35 < 0 ) {
F_29 ( V_9 ) ;
return V_35 ;
}
V_33 = V_35 ;
V_34 = ( V_33 & ~ V_30 ) | ( V_31 & V_30 ) ;
V_32 = V_33 != V_34 ;
if ( V_32 ) {
V_35 = F_24 ( V_9 , V_26 , V_34 ) ;
if ( V_35 < 0 ) {
F_29 ( V_9 ) ;
return V_35 ;
}
}
F_29 ( V_9 ) ;
}
return V_32 ;
}
static int F_33 ( struct V_18 * V_12 ,
enum V_37 V_38 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
int V_35 = 0 ;
F_34 ( V_14 , V_38 ) ;
if ( V_14 && V_14 -> V_39 )
V_35 = V_14 -> V_39 ( V_14 , V_12 , V_38 ) ;
if ( V_35 != 0 )
goto V_40;
if ( V_12 -> V_19 ) {
if ( V_12 -> V_19 -> V_41 -> V_39 )
V_35 = V_12 -> V_19 -> V_41 -> V_39 ( V_12 -> V_19 ,
V_38 ) ;
else
V_12 -> V_42 = V_38 ;
}
if ( V_35 != 0 )
goto V_40;
if ( V_14 && V_14 -> V_43 )
V_35 = V_14 -> V_43 ( V_14 , V_12 , V_38 ) ;
V_40:
F_35 ( V_14 , V_38 ) ;
return V_35 ;
}
static void F_36 ( struct V_8 * V_9 ,
struct V_44 * V_45 , int V_46 )
{
switch ( V_9 -> V_47 ) {
case V_48 :
case V_49 :
case V_50 : {
int V_27 ;
struct V_51 * V_52 = (struct V_51 * )
V_9 -> V_53 [ V_46 ] . V_54 ;
unsigned int V_26 = V_52 -> V_26 ;
unsigned int V_55 = V_52 -> V_55 ;
int V_56 = V_52 -> V_56 ;
unsigned int V_30 = ( 1 << F_37 ( V_56 ) ) - 1 ;
unsigned int V_57 = V_52 -> V_57 ;
V_27 = F_20 ( V_9 , V_26 ) ;
V_27 = ( V_27 >> V_55 ) & V_30 ;
if ( ( V_57 && ! V_27 ) || ( ! V_57 && V_27 ) )
V_45 -> V_58 = 1 ;
else
V_45 -> V_58 = 0 ;
}
break;
case V_59 : {
struct V_60 * V_61 = (struct V_60 * )
V_9 -> V_53 [ V_46 ] . V_54 ;
int V_27 , V_62 , V_63 ;
for ( V_63 = 1 ; V_63 < V_61 -> V_56 ; V_63 <<= 1 )
;
V_27 = F_20 ( V_9 , V_61 -> V_26 ) ;
V_62 = ( V_27 >> V_61 -> V_64 ) & ( V_63 - 1 ) ;
V_45 -> V_58 = 0 ;
for ( V_46 = 0 ; V_46 < V_61 -> V_56 ; V_46 ++ ) {
if ( ! ( strcmp ( V_45 -> V_13 , V_61 -> V_65 [ V_46 ] ) ) && V_62 == V_46 )
V_45 -> V_58 = 1 ;
}
}
break;
case V_66 : {
struct V_60 * V_61 = (struct V_60 * )
V_9 -> V_53 [ V_46 ] . V_54 ;
V_45 -> V_58 = 0 ;
if ( ! strcmp ( V_45 -> V_13 , V_61 -> V_65 [ 0 ] ) )
V_45 -> V_58 = 1 ;
}
break;
case V_67 : {
struct V_60 * V_61 = (struct V_60 * )
V_9 -> V_53 [ V_46 ] . V_54 ;
int V_27 , V_62 ;
V_27 = F_20 ( V_9 , V_61 -> V_26 ) ;
V_27 = ( V_27 >> V_61 -> V_64 ) & V_61 -> V_30 ;
for ( V_62 = 0 ; V_62 < V_61 -> V_56 ; V_62 ++ ) {
if ( V_27 == V_61 -> V_68 [ V_62 ] )
break;
}
V_45 -> V_58 = 0 ;
for ( V_46 = 0 ; V_46 < V_61 -> V_56 ; V_46 ++ ) {
if ( ! ( strcmp ( V_45 -> V_13 , V_61 -> V_65 [ V_46 ] ) ) && V_62 == V_46 )
V_45 -> V_58 = 1 ;
}
}
break;
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
case V_86 :
case V_87 :
V_45 -> V_58 = 1 ;
break;
case V_88 :
case V_89 :
V_45 -> V_58 = 0 ;
break;
}
}
static int F_38 ( struct V_18 * V_12 ,
struct V_8 * V_90 , struct V_8 * V_91 ,
struct V_44 * V_92 , const char * V_93 ,
const struct V_94 * V_95 )
{
struct V_60 * V_61 = (struct V_60 * ) V_95 -> V_54 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_61 -> V_56 ; V_46 ++ ) {
if ( ! ( strcmp ( V_93 , V_61 -> V_65 [ V_46 ] ) ) ) {
F_39 ( & V_92 -> V_96 , & V_12 -> V_14 -> V_97 ) ;
F_39 ( & V_92 -> V_98 , & V_91 -> V_99 ) ;
F_39 ( & V_92 -> V_100 , & V_90 -> V_101 ) ;
V_92 -> V_13 = ( char * ) V_61 -> V_65 [ V_46 ] ;
F_36 ( V_91 , V_92 , 0 ) ;
return 0 ;
}
}
return - V_102 ;
}
static int F_40 ( struct V_18 * V_12 ,
struct V_8 * V_90 , struct V_8 * V_91 ,
struct V_44 * V_92 , const char * V_93 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_91 -> V_103 ; V_46 ++ ) {
if ( ! strcmp ( V_93 , V_91 -> V_53 [ V_46 ] . V_13 ) ) {
F_39 ( & V_92 -> V_96 , & V_12 -> V_14 -> V_97 ) ;
F_39 ( & V_92 -> V_98 , & V_91 -> V_99 ) ;
F_39 ( & V_92 -> V_100 , & V_90 -> V_101 ) ;
V_92 -> V_13 = V_91 -> V_53 [ V_46 ] . V_13 ;
F_36 ( V_91 , V_92 , V_46 ) ;
return 0 ;
}
}
return - V_102 ;
}
static int F_41 ( struct V_18 * V_12 ,
struct V_8 * V_104 ,
const struct V_94 * V_105 ,
struct V_106 * * V_95 )
{
struct V_8 * V_9 ;
int V_46 ;
* V_95 = NULL ;
F_19 (w, &dapm->card->widgets, list) {
if ( V_9 == V_104 || V_9 -> V_12 != V_104 -> V_12 )
continue;
for ( V_46 = 0 ; V_46 < V_9 -> V_103 ; V_46 ++ ) {
if ( & V_9 -> V_53 [ V_46 ] == V_105 ) {
if ( V_9 -> V_107 )
* V_95 = V_9 -> V_107 [ V_46 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
int V_46 , V_35 = 0 ;
T_3 V_108 , V_109 ;
struct V_44 * V_92 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_110 ;
struct V_111 * V_112 ;
T_3 V_113 ;
if ( V_12 -> V_19 )
V_110 = V_12 -> V_19 -> V_114 ;
else
V_110 = NULL ;
if ( V_110 )
V_109 = strlen ( V_110 ) + 1 ;
else
V_109 = 0 ;
for ( V_46 = 0 ; V_46 < V_9 -> V_103 ; V_46 ++ ) {
F_19 (path, &w->sources, list_sink) {
if ( V_92 -> V_13 != ( char * ) V_9 -> V_53 [ V_46 ] . V_13 )
continue;
if ( V_9 -> V_107 [ V_46 ] ) {
V_92 -> V_95 = V_9 -> V_107 [ V_46 ] ;
continue;
}
V_113 = sizeof( struct V_111 ) +
sizeof( struct V_8 * ) ,
V_112 = F_43 ( V_113 , V_7 ) ;
if ( V_112 == NULL ) {
F_23 ( V_12 -> V_3 ,
L_5 ,
V_9 -> V_13 ) ;
return - V_115 ;
}
V_112 -> V_116 = 1 ;
V_112 -> V_117 [ 0 ] = V_9 ;
V_108 = strlen ( V_9 -> V_53 [ V_46 ] . V_13 ) + 1 ;
if ( V_9 -> V_47 != V_50 )
V_108 += 1 + strlen ( V_9 -> V_13 ) ;
V_92 -> V_118 = F_5 ( V_108 , V_7 ) ;
if ( V_92 -> V_118 == NULL ) {
F_7 ( V_112 ) ;
return - V_115 ;
}
switch ( V_9 -> V_47 ) {
default:
snprintf ( ( char * ) V_92 -> V_118 , V_108 ,
L_6 , V_9 -> V_13 + V_109 ,
V_9 -> V_53 [ V_46 ] . V_13 ) ;
break;
case V_50 :
snprintf ( ( char * ) V_92 -> V_118 , V_108 ,
L_1 , V_9 -> V_53 [ V_46 ] . V_13 ) ;
break;
}
( ( char * ) V_92 -> V_118 ) [ V_108 - 1 ] = '\0' ;
V_92 -> V_95 = F_44 ( & V_9 -> V_53 [ V_46 ] ,
V_112 , V_92 -> V_118 ,
V_110 ) ;
V_35 = F_45 ( V_14 , V_92 -> V_95 ) ;
if ( V_35 < 0 ) {
F_23 ( V_12 -> V_3 ,
L_7 ,
V_92 -> V_118 , V_35 ) ;
F_7 ( V_112 ) ;
F_7 ( V_92 -> V_118 ) ;
V_92 -> V_118 = NULL ;
return V_35 ;
}
V_9 -> V_107 [ V_46 ] = V_92 -> V_95 ;
}
}
return V_35 ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_44 * V_92 = NULL ;
struct V_106 * V_95 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_110 ;
T_3 V_109 ;
int V_35 ;
struct V_111 * V_112 ;
int V_119 , V_120 ;
T_3 V_113 ;
const char * V_13 ;
if ( V_9 -> V_103 != 1 ) {
F_23 ( V_12 -> V_3 ,
L_8 ,
V_9 -> V_13 ) ;
return - V_121 ;
}
V_119 = F_41 ( V_12 , V_9 , & V_9 -> V_53 [ 0 ] ,
& V_95 ) ;
if ( V_95 ) {
V_112 = V_95 -> V_122 ;
V_120 = V_112 -> V_116 + 1 ;
} else {
V_112 = NULL ;
V_120 = 1 ;
}
V_113 = sizeof( struct V_111 ) +
V_120 * sizeof( struct V_8 * ) ,
V_112 = F_47 ( V_112 , V_113 , V_7 ) ;
if ( V_112 == NULL ) {
F_23 ( V_12 -> V_3 ,
L_5 , V_9 -> V_13 ) ;
return - V_115 ;
}
V_112 -> V_116 = V_120 ;
V_112 -> V_117 [ V_120 - 1 ] = V_9 ;
if ( ! V_95 ) {
if ( V_12 -> V_19 )
V_110 = V_12 -> V_19 -> V_114 ;
else
V_110 = NULL ;
if ( V_119 ) {
V_13 = V_9 -> V_53 [ 0 ] . V_13 ;
V_109 = 0 ;
} else {
V_13 = V_9 -> V_13 ;
if ( V_110 )
V_109 = strlen ( V_110 ) + 1 ;
else
V_109 = 0 ;
}
V_95 = F_44 ( & V_9 -> V_53 [ 0 ] , V_112 ,
V_13 + V_109 , V_110 ) ;
V_35 = F_45 ( V_14 , V_95 ) ;
if ( V_35 < 0 ) {
F_23 ( V_12 -> V_3 , L_9 ,
V_9 -> V_13 , V_35 ) ;
F_7 ( V_112 ) ;
return V_35 ;
}
}
V_95 -> V_122 = V_112 ;
V_9 -> V_107 [ 0 ] = V_95 ;
F_19 (path, &w->sources, list_sink)
V_92 -> V_95 = V_95 ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 )
{
if ( V_9 -> V_103 )
F_23 ( V_9 -> V_12 -> V_3 ,
L_10 , V_9 -> V_13 ) ;
return 0 ;
}
static inline void F_49 ( struct V_18 * V_12 )
{
struct V_44 * V_45 ;
F_19 (p, &dapm->card->paths, list)
V_45 -> V_123 = 0 ;
}
static int F_50 ( struct V_8 * V_124 )
{
int V_38 = F_51 ( V_124 -> V_12 -> V_14 -> V_17 ) ;
switch ( V_38 ) {
case V_125 :
case V_126 :
if ( V_124 -> V_127 )
F_52 ( V_124 -> V_12 -> V_3 , L_11 ,
V_124 -> V_13 ) ;
return V_124 -> V_127 ;
default:
return 1 ;
}
}
static int F_53 ( struct V_111 * * V_96 ,
struct V_8 * V_9 )
{
struct V_111 * V_112 ;
int V_113 , V_120 , V_46 ;
if ( * V_96 == NULL )
return - V_121 ;
V_112 = * V_96 ;
for ( V_46 = 0 ; V_46 < V_112 -> V_116 ; V_46 ++ ) {
if ( V_112 -> V_117 [ V_46 ] == V_9 )
return 0 ;
}
V_120 = V_112 -> V_116 + 1 ;
V_113 = sizeof( struct V_111 ) +
V_120 * sizeof( struct V_8 * ) ;
* V_96 = F_47 ( V_112 , V_113 , V_7 ) ;
if ( * V_96 == NULL ) {
F_23 ( V_9 -> V_12 -> V_3 , L_12 ,
V_9 -> V_13 ) ;
return - V_115 ;
}
V_112 = * V_96 ;
F_52 ( V_9 -> V_12 -> V_3 , L_13 ,
V_9 -> V_13 , V_112 -> V_116 ) ;
V_112 -> V_117 [ V_112 -> V_116 ] = V_9 ;
V_112 -> V_116 ++ ;
return 1 ;
}
static int F_54 ( struct V_8 * V_124 ,
struct V_111 * * V_96 )
{
struct V_44 * V_92 ;
int V_128 = 0 ;
if ( V_124 -> V_25 >= 0 )
return V_124 -> V_25 ;
F_55 ( V_124 , V_129 ) ;
switch ( V_124 -> V_47 ) {
case V_78 :
case V_79 :
return 0 ;
default:
break;
}
switch ( V_124 -> V_47 ) {
case V_72 :
case V_81 :
case V_82 :
if ( V_124 -> V_130 ) {
V_124 -> V_25 = F_50 ( V_124 ) ;
return V_124 -> V_25 ;
}
default:
break;
}
if ( V_124 -> V_131 ) {
if ( V_124 -> V_47 == V_71 && ! V_124 -> V_132 ) {
V_124 -> V_25 = F_50 ( V_124 ) ;
return V_124 -> V_25 ;
}
if ( V_124 -> V_47 == V_83 ||
V_124 -> V_47 == V_85 ||
( V_124 -> V_47 == V_86 &&
! F_9 ( & V_124 -> V_99 ) ) ) {
V_124 -> V_25 = F_50 ( V_124 ) ;
return V_124 -> V_25 ;
}
}
F_19 (path, &widget->sinks, list_source) {
F_55 ( V_124 , V_133 ) ;
if ( V_92 -> V_134 )
continue;
if ( V_92 -> V_123 )
continue;
F_56 ( V_124 , V_92 ) ;
if ( V_92 -> V_135 && V_92 -> V_58 ) {
V_92 -> V_123 = 1 ;
if ( V_96 ) {
int V_136 ;
V_136 = F_53 ( V_96 , V_92 -> V_135 ) ;
if ( V_136 < 0 ) {
F_23 ( V_124 -> V_12 -> V_3 , L_14 ,
V_124 -> V_13 ) ;
return V_128 ;
}
}
V_128 += F_54 ( V_92 -> V_135 , V_96 ) ;
}
}
V_124 -> V_25 = V_128 ;
return V_128 ;
}
static int F_57 ( struct V_8 * V_124 ,
struct V_111 * * V_96 )
{
struct V_44 * V_92 ;
int V_128 = 0 ;
if ( V_124 -> V_24 >= 0 )
return V_124 -> V_24 ;
F_55 ( V_124 , V_129 ) ;
switch ( V_124 -> V_47 ) {
case V_78 :
case V_79 :
return 0 ;
default:
break;
}
switch ( V_124 -> V_47 ) {
case V_75 :
case V_80 :
case V_82 :
if ( V_124 -> V_130 ) {
V_124 -> V_24 = F_50 ( V_124 ) ;
return V_124 -> V_24 ;
}
default:
break;
}
if ( V_124 -> V_131 ) {
if ( V_124 -> V_47 == V_73 && ! V_124 -> V_132 ) {
V_124 -> V_24 = F_50 ( V_124 ) ;
return V_124 -> V_24 ;
}
if ( V_124 -> V_47 == V_77 ) {
V_124 -> V_24 = F_50 ( V_124 ) ;
return V_124 -> V_24 ;
}
if ( V_124 -> V_47 == V_84 ||
( V_124 -> V_47 == V_86 &&
! F_9 ( & V_124 -> V_101 ) ) ) {
V_124 -> V_24 = F_50 ( V_124 ) ;
return V_124 -> V_24 ;
}
if ( V_124 -> V_47 == V_74 ) {
V_124 -> V_24 = F_50 ( V_124 ) ;
return V_124 -> V_24 ;
}
}
F_19 (path, &widget->sources, list_sink) {
F_55 ( V_124 , V_133 ) ;
if ( V_92 -> V_134 )
continue;
if ( V_92 -> V_123 )
continue;
F_58 ( V_124 , V_92 ) ;
if ( V_92 -> V_137 && V_92 -> V_58 ) {
V_92 -> V_123 = 1 ;
if ( V_96 ) {
int V_136 ;
V_136 = F_53 ( V_96 , V_92 -> V_137 ) ;
if ( V_136 < 0 ) {
F_23 ( V_124 -> V_12 -> V_3 , L_14 ,
V_124 -> V_13 ) ;
return V_128 ;
}
}
V_128 += F_57 ( V_92 -> V_137 , V_96 ) ;
}
}
V_124 -> V_24 = V_128 ;
return V_128 ;
}
int F_59 ( struct V_138 * V_139 , int V_140 ,
struct V_111 * * V_96 )
{
struct V_21 * V_14 = V_139 -> V_14 ;
int V_97 ;
F_60 ( & V_14 -> V_141 , V_142 ) ;
F_18 ( V_14 ) ;
if ( V_140 == V_143 )
V_97 = F_54 ( V_139 -> V_144 , V_96 ) ;
else
V_97 = F_57 ( V_139 -> V_145 , V_96 ) ;
F_61 ( V_97 , V_140 ) ;
F_49 ( & V_14 -> V_12 ) ;
F_30 ( & V_14 -> V_141 ) ;
return V_97 ;
}
int F_62 ( struct V_8 * V_9 ,
struct V_106 * V_95 , int V_146 )
{
unsigned int V_27 ;
if ( F_63 ( V_146 ) )
V_27 = V_9 -> V_147 ;
else
V_27 = V_9 -> V_148 ;
F_31 ( V_9 , - ( V_9 -> V_26 + 1 ) ,
V_9 -> V_30 << V_9 -> V_55 , V_27 << V_9 -> V_55 ) ;
return 0 ;
}
int F_64 ( struct V_8 * V_9 ,
struct V_106 * V_95 , int V_146 )
{
if ( F_63 ( V_146 ) )
return F_65 ( V_9 -> V_149 ) ;
else
return F_66 ( V_9 -> V_149 , V_9 -> V_55 ) ;
}
static int F_67 ( struct V_8 * V_9 )
{
if ( V_9 -> V_23 )
return V_9 -> V_150 ;
if ( V_9 -> V_151 )
V_9 -> V_150 = 1 ;
else
V_9 -> V_150 = V_9 -> V_152 ( V_9 ) ;
V_9 -> V_23 = true ;
return V_9 -> V_150 ;
}
static int F_68 ( struct V_8 * V_9 )
{
int V_153 , V_40 ;
F_55 ( V_9 , V_154 ) ;
V_153 = F_57 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
V_40 = F_54 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
return V_40 != 0 && V_153 != 0 ;
}
static int F_69 ( struct V_8 * V_9 )
{
F_55 ( V_9 , V_154 ) ;
if ( V_9 -> V_130 )
return V_9 -> V_130 ;
return F_68 ( V_9 ) ;
}
static int F_70 ( struct V_8 * V_9 )
{
int V_153 ;
F_55 ( V_9 , V_154 ) ;
if ( V_9 -> V_130 ) {
V_153 = F_57 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
return V_153 != 0 ;
} else {
return F_68 ( V_9 ) ;
}
}
static int F_71 ( struct V_8 * V_9 )
{
int V_40 ;
F_55 ( V_9 , V_154 ) ;
if ( V_9 -> V_130 ) {
V_40 = F_54 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
return V_40 != 0 ;
} else {
return F_68 ( V_9 ) ;
}
}
static int F_72 ( struct V_8 * V_9 )
{
struct V_44 * V_92 ;
F_55 ( V_9 , V_154 ) ;
F_19 (path, &w->sinks, list_source) {
F_55 ( V_9 , V_133 ) ;
if ( V_92 -> V_134 )
continue;
if ( V_92 -> V_131 &&
! V_92 -> V_131 ( V_92 -> V_137 , V_92 -> V_135 ) )
continue;
if ( ! V_92 -> V_135 )
continue;
if ( F_67 ( V_92 -> V_135 ) )
return 1 ;
}
F_49 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_73 ( struct V_8 * V_9 )
{
return 1 ;
}
static int F_74 ( struct V_8 * V_155 ,
struct V_8 * V_156 ,
bool V_157 )
{
int * V_158 ;
if ( V_157 )
V_158 = V_159 ;
else
V_158 = V_160 ;
if ( V_158 [ V_155 -> V_47 ] != V_158 [ V_156 -> V_47 ] )
return V_158 [ V_155 -> V_47 ] - V_158 [ V_156 -> V_47 ] ;
if ( V_155 -> V_161 != V_156 -> V_161 ) {
if ( V_157 )
return V_155 -> V_161 - V_156 -> V_161 ;
else
return V_156 -> V_161 - V_155 -> V_161 ;
}
if ( V_155 -> V_26 != V_156 -> V_26 )
return V_155 -> V_26 - V_156 -> V_26 ;
if ( V_155 -> V_12 != V_156 -> V_12 )
return ( unsigned long ) V_155 -> V_12 - ( unsigned long ) V_156 -> V_12 ;
return 0 ;
}
static void F_75 ( struct V_8 * V_162 ,
struct V_163 * V_96 ,
bool V_157 )
{
struct V_8 * V_9 ;
F_19 (w, list, power_list)
if ( F_74 ( V_162 , V_9 , V_157 ) < 0 ) {
F_12 ( & V_162 -> V_164 , & V_9 -> V_164 ) ;
return;
}
F_12 ( & V_162 -> V_164 , V_96 ) ;
}
static void F_76 ( struct V_18 * V_12 ,
struct V_8 * V_9 , int V_146 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
const char * V_165 ;
int V_166 , V_35 ;
switch ( V_146 ) {
case V_167 :
V_165 = L_15 ;
V_166 = 1 ;
break;
case V_168 :
V_165 = L_16 ;
V_166 = 1 ;
break;
case V_169 :
V_165 = L_17 ;
V_166 = 0 ;
break;
case V_170 :
V_165 = L_18 ;
V_166 = 0 ;
break;
default:
F_16 () ;
return;
}
if ( V_9 -> V_166 != V_166 )
return;
if ( V_9 -> V_146 && ( V_9 -> V_171 & V_146 ) ) {
F_4 ( V_12 -> V_3 , V_14 -> V_1 , L_19 ,
V_9 -> V_13 , V_165 ) ;
F_77 ( V_9 , V_146 ) ;
V_35 = V_9 -> V_146 ( V_9 , NULL , V_146 ) ;
F_78 ( V_9 , V_146 ) ;
if ( V_35 < 0 )
F_79 ( L_20 ,
V_165 , V_9 -> V_13 , V_35 ) ;
}
}
static void F_80 ( struct V_18 * V_12 ,
struct V_163 * V_172 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
int V_26 , V_166 ;
unsigned int V_31 = 0 ;
unsigned int V_30 = 0 ;
unsigned int V_173 ;
V_26 = F_81 ( V_172 , struct V_8 ,
V_164 ) -> V_26 ;
F_19 (w, pending, power_list) {
V_173 = 1 << V_9 -> V_55 ;
F_82 ( V_26 != V_9 -> V_26 ) ;
if ( V_9 -> V_57 )
V_166 = ! V_9 -> V_166 ;
else
V_166 = V_9 -> V_166 ;
V_30 |= V_173 ;
if ( V_166 )
V_31 |= V_173 ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_21 ,
V_9 -> V_13 , V_26 , V_31 , V_30 ) ;
F_76 ( V_12 , V_9 , V_167 ) ;
F_76 ( V_12 , V_9 , V_169 ) ;
}
if ( V_26 >= 0 ) {
V_9 = F_81 ( V_172 , struct V_8 ,
V_164 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_22 ,
V_31 , V_30 , V_26 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_31 ( V_9 , V_26 , V_30 , V_31 ) ;
}
F_19 (w, pending, power_list) {
F_76 ( V_12 , V_9 , V_168 ) ;
F_76 ( V_12 , V_9 , V_170 ) ;
}
}
static void F_83 ( struct V_18 * V_12 ,
struct V_163 * V_96 , int V_146 , bool V_157 )
{
struct V_8 * V_9 , * V_174 ;
F_84 ( V_172 ) ;
int V_175 = - 1 ;
int V_176 = - 1 ;
int V_177 = V_178 ;
struct V_18 * V_179 = NULL ;
int V_35 , V_46 ;
int * V_158 ;
if ( V_157 )
V_158 = V_159 ;
else
V_158 = V_160 ;
F_85 (w, n, list, power_list) {
V_35 = 0 ;
if ( V_158 [ V_9 -> V_47 ] != V_175 || V_9 -> V_26 != V_177 ||
V_9 -> V_12 != V_179 || V_9 -> V_161 != V_176 ) {
if ( ! F_9 ( & V_172 ) )
F_80 ( V_179 , & V_172 ) ;
if ( V_179 && V_179 -> V_180 ) {
for ( V_46 = 0 ; V_46 < F_86 ( V_159 ) ; V_46 ++ )
if ( V_158 [ V_46 ] == V_175 )
V_179 -> V_180 ( V_179 ,
V_46 ,
V_176 ) ;
}
F_87 ( & V_172 ) ;
V_175 = - 1 ;
V_176 = V_181 ;
V_177 = V_178 ;
V_179 = NULL ;
}
switch ( V_9 -> V_47 ) {
case V_88 :
if ( ! V_9 -> V_146 )
F_88 ( V_9 , V_174 , V_96 ,
V_164 ) ;
if ( V_146 == V_182 )
V_35 = V_9 -> V_146 ( V_9 ,
NULL , V_167 ) ;
else if ( V_146 == V_183 )
V_35 = V_9 -> V_146 ( V_9 ,
NULL , V_169 ) ;
break;
case V_89 :
if ( ! V_9 -> V_146 )
F_88 ( V_9 , V_174 , V_96 ,
V_164 ) ;
if ( V_146 == V_182 )
V_35 = V_9 -> V_146 ( V_9 ,
NULL , V_168 ) ;
else if ( V_146 == V_183 )
V_35 = V_9 -> V_146 ( V_9 ,
NULL , V_170 ) ;
break;
default:
V_175 = V_158 [ V_9 -> V_47 ] ;
V_176 = V_9 -> V_161 ;
V_177 = V_9 -> V_26 ;
V_179 = V_9 -> V_12 ;
F_89 ( & V_9 -> V_164 , & V_172 ) ;
break;
}
if ( V_35 < 0 )
F_23 ( V_9 -> V_12 -> V_3 ,
L_23 , V_35 ) ;
}
if ( ! F_9 ( & V_172 ) )
F_80 ( V_179 , & V_172 ) ;
if ( V_179 && V_179 -> V_180 ) {
for ( V_46 = 0 ; V_46 < F_86 ( V_159 ) ; V_46 ++ )
if ( V_158 [ V_46 ] == V_175 )
V_179 -> V_180 ( V_179 ,
V_46 , V_176 ) ;
}
}
static void F_90 ( struct V_18 * V_12 )
{
struct V_184 * V_185 = V_12 -> V_185 ;
struct V_8 * V_9 ;
int V_35 ;
if ( ! V_185 )
return;
V_9 = V_185 -> V_124 ;
if ( V_9 -> V_146 &&
( V_9 -> V_171 & V_186 ) ) {
V_35 = V_9 -> V_146 ( V_9 , V_185 -> V_95 , V_186 ) ;
if ( V_35 != 0 )
F_79 ( L_24 ,
V_9 -> V_13 , V_35 ) ;
}
V_35 = F_31 ( V_9 , V_185 -> V_26 , V_185 -> V_30 ,
V_185 -> V_27 ) ;
if ( V_35 < 0 )
F_79 ( L_25 , V_9 -> V_13 , V_35 ) ;
if ( V_9 -> V_146 &&
( V_9 -> V_171 & V_187 ) ) {
V_35 = V_9 -> V_146 ( V_9 , V_185 -> V_95 , V_187 ) ;
if ( V_35 != 0 )
F_79 ( L_26 ,
V_9 -> V_13 , V_35 ) ;
}
}
static void F_91 ( void * V_188 , T_4 V_189 )
{
struct V_18 * V_190 = V_188 ;
int V_35 ;
if ( V_190 -> V_42 == V_191 &&
V_190 -> V_192 != V_191 ) {
if ( V_190 -> V_3 )
F_92 ( V_190 -> V_3 ) ;
V_35 = F_33 ( V_190 , V_193 ) ;
if ( V_35 != 0 )
F_23 ( V_190 -> V_3 ,
L_27 , V_35 ) ;
}
if ( V_190 -> V_42 != V_190 -> V_192 ) {
V_35 = F_33 ( V_190 , V_194 ) ;
if ( V_35 != 0 )
F_23 ( V_190 -> V_3 ,
L_28 , V_35 ) ;
}
}
static void F_93 ( void * V_188 , T_4 V_189 )
{
struct V_18 * V_190 = V_188 ;
int V_35 ;
if ( V_190 -> V_42 == V_194 &&
( V_190 -> V_192 == V_193 ||
V_190 -> V_192 == V_191 ) ) {
V_35 = F_33 ( V_190 , V_193 ) ;
if ( V_35 != 0 )
F_23 ( V_190 -> V_3 , L_29 ,
V_35 ) ;
}
if ( V_190 -> V_42 == V_193 &&
V_190 -> V_192 == V_191 ) {
V_35 = F_33 ( V_190 , V_191 ) ;
if ( V_35 != 0 )
F_23 ( V_190 -> V_3 , L_30 , V_35 ) ;
if ( V_190 -> V_3 )
F_94 ( V_190 -> V_3 ) ;
}
if ( V_190 -> V_42 == V_194 &&
V_190 -> V_192 == V_195 ) {
V_35 = F_33 ( V_190 , V_195 ) ;
if ( V_35 != 0 )
F_23 ( V_190 -> V_3 , L_31 ,
V_35 ) ;
}
}
static void F_95 ( struct V_8 * V_196 ,
bool V_166 , bool V_58 )
{
if ( ! V_58 )
return;
if ( V_166 != V_196 -> V_166 )
F_10 ( V_196 , L_32 ) ;
}
static void F_96 ( struct V_8 * V_9 , bool V_166 ,
struct V_163 * V_197 ,
struct V_163 * V_198 )
{
struct V_44 * V_92 ;
if ( V_9 -> V_166 == V_166 )
return;
F_97 ( V_9 , V_166 ) ;
F_19 (path, &w->sources, list_sink) {
if ( V_92 -> V_137 ) {
F_95 ( V_92 -> V_137 , V_166 ,
V_92 -> V_58 ) ;
}
}
switch ( V_9 -> V_47 ) {
case V_78 :
case V_79 :
break;
default:
F_19 (path, &w->sinks, list_source) {
if ( V_92 -> V_135 ) {
F_95 ( V_92 -> V_135 , V_166 ,
V_92 -> V_58 ) ;
}
}
break;
}
if ( V_166 )
F_75 ( V_9 , V_197 , true ) ;
else
F_75 ( V_9 , V_198 , false ) ;
V_9 -> V_166 = V_166 ;
}
static void F_98 ( struct V_8 * V_9 ,
struct V_163 * V_197 ,
struct V_163 * V_198 )
{
int V_166 ;
switch ( V_9 -> V_47 ) {
case V_88 :
F_75 ( V_9 , V_198 , false ) ;
break;
case V_89 :
F_75 ( V_9 , V_197 , true ) ;
break;
default:
V_166 = F_67 ( V_9 ) ;
F_96 ( V_9 , V_166 , V_197 , V_198 ) ;
break;
}
}
static int F_99 ( struct V_18 * V_12 , int V_146 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
struct V_18 * V_190 ;
F_84 ( V_197 ) ;
F_84 ( V_198 ) ;
F_84 ( V_199 ) ;
enum V_37 V_200 ;
F_100 ( V_14 ) ;
F_19 (d, &card->dapm_list, list) {
if ( V_190 -> V_201 )
V_190 -> V_192 = V_191 ;
else
V_190 -> V_192 = V_193 ;
}
F_18 ( V_14 ) ;
F_19 (w, &card->dapm_dirty, dirty) {
F_98 ( V_9 , & V_197 , & V_198 ) ;
}
F_19 (w, &card->widgets, list) {
F_101 ( & V_9 -> V_10 ) ;
if ( V_9 -> V_166 ) {
V_190 = V_9 -> V_12 ;
switch ( V_9 -> V_47 ) {
case V_74 :
break;
case V_78 :
case V_79 :
case V_76 :
if ( V_190 -> V_192 < V_193 )
V_190 -> V_192 = V_193 ;
break;
default:
V_190 -> V_192 = V_195 ;
break;
}
}
}
V_200 = V_191 ;
F_19 (d, &card->dapm_list, list)
if ( V_190 -> V_192 > V_200 )
V_200 = V_190 -> V_192 ;
F_19 (d, &card->dapm_list, list)
if ( ! V_190 -> V_201 )
V_190 -> V_192 = V_200 ;
F_102 ( V_14 ) ;
F_19 (d, &dapm->card->dapm_list, list)
F_103 ( F_91 , V_190 ,
& V_199 ) ;
F_104 ( & V_199 ) ;
F_83 ( V_12 , & V_198 , V_146 , false ) ;
F_90 ( V_12 ) ;
F_83 ( V_12 , & V_197 , V_146 , true ) ;
F_19 (d, &dapm->card->dapm_list, list)
F_103 ( F_93 , V_190 ,
& V_199 ) ;
F_104 ( & V_199 ) ;
F_19 (d, &card->dapm_list, list) {
if ( V_190 -> V_202 )
V_190 -> V_202 ( V_190 , V_146 ) ;
}
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_33 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_105 ( V_14 ) ;
return 0 ;
}
static T_5 F_106 ( struct V_203 * V_203 ,
char T_6 * V_204 ,
T_3 V_205 , T_7 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_122 ;
char * V_5 ;
int V_153 , V_40 ;
T_5 V_35 ;
struct V_44 * V_45 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_115 ;
V_153 = F_57 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
V_40 = F_54 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
V_35 = snprintf ( V_5 , V_6 , L_34 ,
V_9 -> V_13 , V_9 -> V_166 ? L_35 : L_36 ,
V_9 -> V_151 ? L_37 : L_38 , V_153 , V_40 ) ;
if ( V_9 -> V_26 >= 0 )
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 ,
L_39 ,
V_9 -> V_26 , V_9 -> V_26 , V_9 -> V_55 ) ;
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 , L_40 ) ;
if ( V_9 -> V_207 )
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 , L_41 ,
V_9 -> V_207 ,
V_9 -> V_130 ? L_42 : L_43 ) ;
F_19 (p, &w->sources, list_sink) {
if ( V_45 -> V_131 && ! V_45 -> V_131 ( V_9 , V_45 -> V_135 ) )
continue;
if ( V_45 -> V_58 )
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 ,
L_44 ,
V_45 -> V_13 ? V_45 -> V_13 : L_45 ,
V_45 -> V_137 -> V_13 ) ;
}
F_19 (p, &w->sinks, list_source) {
if ( V_45 -> V_131 && ! V_45 -> V_131 ( V_9 , V_45 -> V_135 ) )
continue;
if ( V_45 -> V_58 )
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 ,
L_46 ,
V_45 -> V_13 ? V_45 -> V_13 : L_45 ,
V_45 -> V_135 -> V_13 ) ;
}
V_35 = F_107 ( V_204 , V_205 , V_206 , V_5 , V_35 ) ;
F_7 ( V_5 ) ;
return V_35 ;
}
static T_5 F_108 ( struct V_203 * V_203 , char T_6 * V_204 ,
T_3 V_205 , T_7 * V_206 )
{
struct V_18 * V_12 = V_203 -> V_122 ;
char * V_38 ;
switch ( V_12 -> V_42 ) {
case V_195 :
V_38 = L_47 ;
break;
case V_194 :
V_38 = L_48 ;
break;
case V_193 :
V_38 = L_49 ;
break;
case V_191 :
V_38 = L_50 ;
break;
default:
F_16 () ;
V_38 = L_51 ;
break;
}
return F_107 ( V_204 , V_205 , V_206 , V_38 ,
strlen ( V_38 ) ) ;
}
void F_109 ( struct V_18 * V_12 ,
struct V_208 * V_209 )
{
struct V_208 * V_190 ;
V_12 -> V_210 = F_110 ( L_52 , V_209 ) ;
if ( ! V_12 -> V_210 ) {
F_111 ( V_12 -> V_3 ,
L_53 ) ;
return;
}
V_190 = F_112 ( L_54 , 0444 ,
V_12 -> V_210 , V_12 ,
& V_211 ) ;
if ( ! V_190 )
F_111 ( V_12 -> V_3 ,
L_55 ) ;
}
static void F_113 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_208 * V_190 ;
if ( ! V_12 -> V_210 || ! V_9 -> V_13 )
return;
V_190 = F_112 ( V_9 -> V_13 , 0444 ,
V_12 -> V_210 , V_9 ,
& V_212 ) ;
if ( ! V_190 )
F_111 ( V_9 -> V_12 -> V_3 ,
L_56 ,
V_9 -> V_13 ) ;
}
static void F_114 ( struct V_18 * V_12 )
{
F_115 ( V_12 -> V_210 ) ;
}
void F_109 ( struct V_18 * V_12 ,
struct V_208 * V_209 )
{
}
static inline void F_113 ( struct V_8 * V_9 )
{
}
static inline void F_114 ( struct V_18 * V_12 )
{
}
static int F_116 ( struct V_8 * V_124 ,
struct V_106 * V_95 , int V_213 , struct V_60 * V_61 )
{
struct V_44 * V_92 ;
int V_214 = 0 ;
if ( V_124 -> V_47 != V_59 &&
V_124 -> V_47 != V_66 &&
V_124 -> V_47 != V_67 )
return - V_102 ;
F_19 (path, &widget->dapm->card->paths, list) {
if ( V_92 -> V_95 != V_95 )
continue;
if ( ! V_92 -> V_13 || ! V_61 -> V_65 [ V_213 ] )
continue;
V_214 = 1 ;
if ( ! ( strcmp ( V_92 -> V_13 , V_61 -> V_65 [ V_213 ] ) ) ) {
V_92 -> V_58 = 1 ;
F_10 ( V_92 -> V_137 , L_57 ) ;
} else {
if ( V_92 -> V_58 )
F_10 ( V_92 -> V_137 ,
L_58 ) ;
V_92 -> V_58 = 0 ;
}
}
if ( V_214 ) {
F_10 ( V_124 , L_59 ) ;
F_99 ( V_124 -> V_12 , V_215 ) ;
}
return V_214 ;
}
int F_117 ( struct V_8 * V_124 ,
struct V_106 * V_95 , int V_213 , struct V_60 * V_61 )
{
struct V_21 * V_14 = V_124 -> V_12 -> V_14 ;
int V_35 ;
F_60 ( & V_14 -> V_141 , V_142 ) ;
V_35 = F_116 ( V_124 , V_95 , V_213 , V_61 ) ;
F_30 ( & V_14 -> V_141 ) ;
if ( V_35 > 0 )
F_118 ( V_124 ) ;
return V_35 ;
}
static int F_119 ( struct V_8 * V_124 ,
struct V_106 * V_95 , int V_58 )
{
struct V_44 * V_92 ;
int V_214 = 0 ;
if ( V_124 -> V_47 != V_49 &&
V_124 -> V_47 != V_50 &&
V_124 -> V_47 != V_48 )
return - V_102 ;
F_19 (path, &widget->dapm->card->paths, list) {
if ( V_92 -> V_95 != V_95 )
continue;
V_214 = 1 ;
V_92 -> V_58 = V_58 ;
F_10 ( V_92 -> V_137 , L_60 ) ;
}
if ( V_214 ) {
F_10 ( V_124 , L_61 ) ;
F_99 ( V_124 -> V_12 , V_215 ) ;
}
return V_214 ;
}
int F_120 ( struct V_8 * V_124 ,
struct V_106 * V_95 , int V_58 )
{
struct V_21 * V_14 = V_124 -> V_12 -> V_14 ;
int V_35 ;
F_60 ( & V_14 -> V_141 , V_142 ) ;
V_35 = F_119 ( V_124 , V_95 , V_58 ) ;
F_30 ( & V_14 -> V_141 ) ;
if ( V_35 > 0 )
F_118 ( V_124 ) ;
return V_35 ;
}
static T_5 F_121 ( struct V_2 * V_3 ,
struct V_216 * V_217 , char * V_5 )
{
struct V_218 * V_219 = F_122 ( V_3 ) ;
struct V_220 * V_19 = V_219 -> V_19 ;
struct V_8 * V_9 ;
int V_205 = 0 ;
char * V_221 = L_62 ;
F_19 (w, &codec->card->widgets, list) {
if ( V_9 -> V_12 != & V_19 -> V_12 )
continue;
switch ( V_9 -> V_47 ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_76 :
case V_75 :
case V_72 :
case V_69 :
case V_70 :
case V_49 :
case V_50 :
case V_78 :
case V_79 :
if ( V_9 -> V_13 )
V_205 += sprintf ( V_5 + V_205 , L_63 ,
V_9 -> V_13 , V_9 -> V_166 ? L_35 : L_36 ) ;
break;
default:
break;
}
}
switch ( V_19 -> V_12 . V_42 ) {
case V_195 :
V_221 = L_35 ;
break;
case V_194 :
V_221 = L_64 ;
break;
case V_193 :
V_221 = L_65 ;
break;
case V_191 :
V_221 = L_36 ;
break;
}
V_205 += sprintf ( V_5 + V_205 , L_66 , V_221 ) ;
return V_205 ;
}
int F_123 ( struct V_2 * V_3 )
{
return F_124 ( V_3 , & V_222 ) ;
}
static void F_125 ( struct V_2 * V_3 )
{
F_126 ( V_3 , & V_222 ) ;
}
static void F_127 ( struct V_18 * V_12 )
{
struct V_8 * V_9 , * V_223 ;
struct V_44 * V_45 , * V_224 ;
F_85 (w, next_w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
F_128 ( & V_9 -> V_96 ) ;
F_85 (p, next_p, &w->sources, list_sink) {
F_128 ( & V_45 -> V_98 ) ;
F_128 ( & V_45 -> V_100 ) ;
F_128 ( & V_45 -> V_96 ) ;
F_7 ( V_45 -> V_118 ) ;
F_7 ( V_45 ) ;
}
F_85 (p, next_p, &w->sinks, list_source) {
F_128 ( & V_45 -> V_98 ) ;
F_128 ( & V_45 -> V_100 ) ;
F_128 ( & V_45 -> V_96 ) ;
F_7 ( V_45 -> V_118 ) ;
F_7 ( V_45 ) ;
}
F_7 ( V_9 -> V_107 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
}
static struct V_8 * F_129 (
struct V_18 * V_12 , const char * V_225 ,
bool V_226 )
{
struct V_8 * V_9 ;
struct V_8 * V_227 = NULL ;
F_19 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_9 -> V_13 , V_225 ) ) {
if ( V_9 -> V_12 == V_12 )
return V_9 ;
else
V_227 = V_9 ;
}
}
if ( V_226 )
return V_227 ;
return NULL ;
}
static int F_130 ( struct V_18 * V_12 ,
const char * V_225 , int V_228 )
{
struct V_8 * V_9 = F_129 ( V_12 , V_225 , true ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_67 , V_225 ) ;
return - V_121 ;
}
if ( V_9 -> V_131 != V_228 )
F_10 ( V_9 , L_68 ) ;
V_9 -> V_131 = V_228 ;
if ( V_228 == 0 )
V_9 -> V_151 = 0 ;
return 0 ;
}
int F_131 ( struct V_18 * V_12 )
{
int V_35 ;
if ( ! V_12 -> V_14 || ! V_12 -> V_14 -> V_229 )
return 0 ;
F_60 ( & V_12 -> V_14 -> V_141 , V_142 ) ;
V_35 = F_99 ( V_12 , V_215 ) ;
F_30 ( & V_12 -> V_14 -> V_141 ) ;
return V_35 ;
}
static int F_132 ( struct V_18 * V_12 ,
const struct V_230 * V_231 )
{
struct V_44 * V_92 ;
struct V_8 * V_232 = NULL , * V_233 = NULL , * V_9 ;
struct V_8 * V_234 = NULL , * V_235 = NULL ;
const char * V_135 ;
const char * V_236 = V_231 -> V_236 ;
const char * V_137 ;
char V_237 [ 80 ] ;
char V_238 [ 80 ] ;
int V_35 = 0 ;
if ( V_12 -> V_19 && V_12 -> V_19 -> V_114 ) {
snprintf ( V_237 , sizeof( V_237 ) , L_6 ,
V_12 -> V_19 -> V_114 , V_231 -> V_135 ) ;
V_135 = V_237 ;
snprintf ( V_238 , sizeof( V_238 ) , L_6 ,
V_12 -> V_19 -> V_114 , V_231 -> V_137 ) ;
V_137 = V_238 ;
} else {
V_135 = V_231 -> V_135 ;
V_137 = V_231 -> V_137 ;
}
F_19 (w, &dapm->card->widgets, list) {
if ( ! V_233 && ! ( strcmp ( V_9 -> V_13 , V_135 ) ) ) {
V_235 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_233 = V_9 ;
continue;
}
if ( ! V_232 && ! ( strcmp ( V_9 -> V_13 , V_137 ) ) ) {
V_234 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_232 = V_9 ;
}
}
if ( ! V_233 )
V_233 = V_235 ;
if ( ! V_232 )
V_232 = V_234 ;
if ( V_232 == NULL || V_233 == NULL )
return - V_102 ;
V_92 = F_43 ( sizeof( struct V_44 ) , V_7 ) ;
if ( ! V_92 )
return - V_115 ;
V_92 -> V_137 = V_232 ;
V_92 -> V_135 = V_233 ;
V_92 -> V_131 = V_231 -> V_131 ;
F_87 ( & V_92 -> V_96 ) ;
F_87 ( & V_92 -> V_100 ) ;
F_87 ( & V_92 -> V_98 ) ;
if ( V_233 -> V_47 == V_73 ) {
if ( V_232 -> V_47 == V_76 ||
V_232 -> V_47 == V_84 ||
V_232 -> V_47 == V_86 ||
V_232 -> V_47 == V_71 )
V_233 -> V_132 = 1 ;
}
if ( V_232 -> V_47 == V_71 ) {
if ( V_233 -> V_47 == V_85 ||
V_233 -> V_47 == V_83 ||
V_233 -> V_47 == V_86 ||
V_233 -> V_47 == V_73 )
V_232 -> V_132 = 1 ;
}
if ( V_236 == NULL ) {
F_39 ( & V_92 -> V_96 , & V_12 -> V_14 -> V_97 ) ;
F_39 ( & V_92 -> V_98 , & V_233 -> V_99 ) ;
F_39 ( & V_92 -> V_100 , & V_232 -> V_101 ) ;
V_92 -> V_58 = 1 ;
return 0 ;
}
switch ( V_233 -> V_47 ) {
case V_72 :
case V_75 :
case V_69 :
case V_70 :
case V_73 :
case V_71 :
case V_74 :
case V_76 :
case V_77 :
case V_88 :
case V_89 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_87 :
F_39 ( & V_92 -> V_96 , & V_12 -> V_14 -> V_97 ) ;
F_39 ( & V_92 -> V_98 , & V_233 -> V_99 ) ;
F_39 ( & V_92 -> V_100 , & V_232 -> V_101 ) ;
V_92 -> V_58 = 1 ;
return 0 ;
case V_59 :
case V_66 :
case V_67 :
V_35 = F_38 ( V_12 , V_232 , V_233 , V_92 , V_236 ,
& V_233 -> V_53 [ 0 ] ) ;
if ( V_35 != 0 )
goto V_136;
break;
case V_48 :
case V_49 :
case V_50 :
V_35 = F_40 ( V_12 , V_232 , V_233 , V_92 , V_236 ) ;
if ( V_35 != 0 )
goto V_136;
break;
case V_83 :
case V_84 :
case V_86 :
case V_85 :
F_39 ( & V_92 -> V_96 , & V_12 -> V_14 -> V_97 ) ;
F_39 ( & V_92 -> V_98 , & V_233 -> V_99 ) ;
F_39 ( & V_92 -> V_100 , & V_232 -> V_101 ) ;
V_92 -> V_58 = 0 ;
return 0 ;
}
return 0 ;
V_136:
F_111 ( V_12 -> V_3 , L_69 ,
V_137 , V_236 , V_135 ) ;
F_7 ( V_92 ) ;
return V_35 ;
}
int F_133 ( struct V_18 * V_12 ,
const struct V_230 * V_231 , int V_239 )
{
int V_46 , V_35 = 0 ;
F_60 ( & V_12 -> V_14 -> V_141 , V_240 ) ;
for ( V_46 = 0 ; V_46 < V_239 ; V_46 ++ ) {
V_35 = F_132 ( V_12 , V_231 ) ;
if ( V_35 < 0 ) {
F_23 ( V_12 -> V_3 , L_70 ,
V_231 -> V_137 , V_231 -> V_135 ) ;
break;
}
V_231 ++ ;
}
F_30 ( & V_12 -> V_14 -> V_141 ) ;
return V_35 ;
}
static int F_134 ( struct V_18 * V_12 ,
const struct V_230 * V_231 )
{
struct V_8 * V_137 = F_129 ( V_12 ,
V_231 -> V_137 ,
true ) ;
struct V_8 * V_135 = F_129 ( V_12 ,
V_231 -> V_135 ,
true ) ;
struct V_44 * V_92 ;
int V_205 = 0 ;
if ( ! V_137 ) {
F_23 ( V_12 -> V_3 , L_71 ,
V_231 -> V_137 ) ;
return - V_102 ;
}
if ( ! V_135 ) {
F_23 ( V_12 -> V_3 , L_72 ,
V_231 -> V_135 ) ;
return - V_102 ;
}
if ( V_231 -> V_236 || V_231 -> V_131 )
F_111 ( V_12 -> V_3 , L_73 ,
V_231 -> V_137 , V_231 -> V_135 ) ;
F_19 (path, &source->sinks, list_source) {
if ( V_92 -> V_135 == V_135 ) {
V_92 -> V_134 = 1 ;
V_205 ++ ;
}
}
if ( V_205 == 0 )
F_23 ( V_12 -> V_3 , L_74 ,
V_231 -> V_137 , V_231 -> V_135 ) ;
if ( V_205 > 1 )
F_111 ( V_12 -> V_3 , L_75 ,
V_205 , V_231 -> V_137 , V_231 -> V_135 ) ;
return 0 ;
}
int F_135 ( struct V_18 * V_12 ,
const struct V_230 * V_231 , int V_239 )
{
int V_46 , V_136 ;
int V_35 = 0 ;
F_60 ( & V_12 -> V_14 -> V_141 , V_240 ) ;
for ( V_46 = 0 ; V_46 < V_239 ; V_46 ++ ) {
V_136 = F_134 ( V_12 , V_231 ) ;
if ( V_136 )
V_35 = V_136 ;
V_231 ++ ;
}
F_30 ( & V_12 -> V_14 -> V_141 ) ;
return V_35 ;
}
int F_136 ( struct V_18 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
F_60 ( & V_12 -> V_14 -> V_141 , V_240 ) ;
F_19 (w, &dapm->card->widgets, list)
{
if ( V_9 -> V_34 )
continue;
if ( V_9 -> V_103 ) {
V_9 -> V_107 = F_43 ( V_9 -> V_103 *
sizeof( struct V_106 * ) ,
V_7 ) ;
if ( ! V_9 -> V_107 ) {
F_30 ( & V_12 -> V_14 -> V_141 ) ;
return - V_115 ;
}
}
switch( V_9 -> V_47 ) {
case V_48 :
case V_49 :
case V_50 :
F_42 ( V_9 ) ;
break;
case V_59 :
case V_66 :
case V_67 :
F_46 ( V_9 ) ;
break;
case V_69 :
case V_70 :
F_48 ( V_9 ) ;
break;
default:
break;
}
if ( V_9 -> V_26 >= 0 ) {
V_27 = F_20 ( V_9 , V_9 -> V_26 ) ;
V_27 &= 1 << V_9 -> V_55 ;
if ( V_9 -> V_57 )
V_27 = ! V_27 ;
if ( V_27 )
V_9 -> V_166 = 1 ;
}
V_9 -> V_34 = 1 ;
F_10 ( V_9 , L_76 ) ;
F_113 ( V_9 ) ;
}
F_99 ( V_12 , V_215 ) ;
F_30 ( & V_12 -> V_14 -> V_141 ) ;
return 0 ;
}
int F_137 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_111 * V_112 = F_138 ( V_95 ) ;
struct V_8 * V_124 = V_112 -> V_117 [ 0 ] ;
struct V_51 * V_52 =
(struct V_51 * ) V_95 -> V_54 ;
unsigned int V_26 = V_52 -> V_26 ;
unsigned int V_55 = V_52 -> V_55 ;
unsigned int V_243 = V_52 -> V_243 ;
int V_56 = V_52 -> V_56 ;
unsigned int V_57 = V_52 -> V_57 ;
unsigned int V_30 = ( 1 << F_37 ( V_56 ) ) - 1 ;
V_242 -> V_31 . integer . V_31 [ 0 ] =
( F_21 ( V_124 -> V_19 , V_26 ) >> V_55 ) & V_30 ;
if ( V_55 != V_243 )
V_242 -> V_31 . integer . V_31 [ 1 ] =
( F_21 ( V_124 -> V_19 , V_26 ) >> V_243 ) & V_30 ;
if ( V_57 ) {
V_242 -> V_31 . integer . V_31 [ 0 ] =
V_56 - V_242 -> V_31 . integer . V_31 [ 0 ] ;
if ( V_55 != V_243 )
V_242 -> V_31 . integer . V_31 [ 1 ] =
V_56 - V_242 -> V_31 . integer . V_31 [ 1 ] ;
}
return 0 ;
}
int F_139 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_111 * V_112 = F_138 ( V_95 ) ;
struct V_8 * V_124 = V_112 -> V_117 [ 0 ] ;
struct V_220 * V_19 = V_124 -> V_19 ;
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_51 * V_52 =
(struct V_51 * ) V_95 -> V_54 ;
unsigned int V_26 = V_52 -> V_26 ;
unsigned int V_55 = V_52 -> V_55 ;
int V_56 = V_52 -> V_56 ;
unsigned int V_30 = ( 1 << F_37 ( V_56 ) ) - 1 ;
unsigned int V_57 = V_52 -> V_57 ;
unsigned int V_27 ;
int V_58 , V_32 ;
struct V_184 V_185 ;
int V_244 ;
V_27 = ( V_242 -> V_31 . integer . V_31 [ 0 ] & V_30 ) ;
if ( V_57 )
V_27 = V_56 - V_27 ;
V_30 = V_30 << V_55 ;
V_27 = V_27 << V_55 ;
if ( V_27 )
V_58 = V_57 ? 0 : 1 ;
else
V_58 = V_57 ? 1 : 0 ;
F_60 ( & V_14 -> V_141 , V_142 ) ;
V_32 = F_140 ( V_124 -> V_19 , V_26 , V_30 , V_27 ) ;
if ( V_32 ) {
for ( V_244 = 0 ; V_244 < V_112 -> V_116 ; V_244 ++ ) {
V_124 = V_112 -> V_117 [ V_244 ] ;
V_124 -> V_31 = V_27 ;
V_185 . V_95 = V_95 ;
V_185 . V_124 = V_124 ;
V_185 . V_26 = V_26 ;
V_185 . V_30 = V_30 ;
V_185 . V_27 = V_27 ;
V_124 -> V_12 -> V_185 = & V_185 ;
F_119 ( V_124 , V_95 , V_58 ) ;
V_124 -> V_12 -> V_185 = NULL ;
}
}
F_30 ( & V_14 -> V_141 ) ;
return 0 ;
}
int F_141 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_111 * V_112 = F_138 ( V_95 ) ;
struct V_8 * V_124 = V_112 -> V_117 [ 0 ] ;
struct V_60 * V_61 = (struct V_60 * ) V_95 -> V_54 ;
unsigned int V_27 , V_63 ;
for ( V_63 = 1 ; V_63 < V_61 -> V_56 ; V_63 <<= 1 )
;
V_27 = F_21 ( V_124 -> V_19 , V_61 -> V_26 ) ;
V_242 -> V_31 . V_245 . V_62 [ 0 ] = ( V_27 >> V_61 -> V_64 ) & ( V_63 - 1 ) ;
if ( V_61 -> V_64 != V_61 -> V_246 )
V_242 -> V_31 . V_245 . V_62 [ 1 ] =
( V_27 >> V_61 -> V_246 ) & ( V_63 - 1 ) ;
return 0 ;
}
int F_142 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_111 * V_112 = F_138 ( V_95 ) ;
struct V_8 * V_124 = V_112 -> V_117 [ 0 ] ;
struct V_220 * V_19 = V_124 -> V_19 ;
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_60 * V_61 = (struct V_60 * ) V_95 -> V_54 ;
unsigned int V_27 , V_213 , V_32 ;
unsigned int V_30 , V_63 ;
struct V_184 V_185 ;
int V_244 ;
for ( V_63 = 1 ; V_63 < V_61 -> V_56 ; V_63 <<= 1 )
;
if ( V_242 -> V_31 . V_245 . V_62 [ 0 ] > V_61 -> V_56 - 1 )
return - V_121 ;
V_213 = V_242 -> V_31 . V_245 . V_62 [ 0 ] ;
V_27 = V_213 << V_61 -> V_64 ;
V_30 = ( V_63 - 1 ) << V_61 -> V_64 ;
if ( V_61 -> V_64 != V_61 -> V_246 ) {
if ( V_242 -> V_31 . V_245 . V_62 [ 1 ] > V_61 -> V_56 - 1 )
return - V_121 ;
V_27 |= V_242 -> V_31 . V_245 . V_62 [ 1 ] << V_61 -> V_246 ;
V_30 |= ( V_63 - 1 ) << V_61 -> V_246 ;
}
F_60 ( & V_14 -> V_141 , V_142 ) ;
V_32 = F_140 ( V_124 -> V_19 , V_61 -> V_26 , V_30 , V_27 ) ;
if ( V_32 ) {
for ( V_244 = 0 ; V_244 < V_112 -> V_116 ; V_244 ++ ) {
V_124 = V_112 -> V_117 [ V_244 ] ;
V_124 -> V_31 = V_27 ;
V_185 . V_95 = V_95 ;
V_185 . V_124 = V_124 ;
V_185 . V_26 = V_61 -> V_26 ;
V_185 . V_30 = V_30 ;
V_185 . V_27 = V_27 ;
V_124 -> V_12 -> V_185 = & V_185 ;
F_116 ( V_124 , V_95 , V_213 , V_61 ) ;
V_124 -> V_12 -> V_185 = NULL ;
}
}
F_30 ( & V_14 -> V_141 ) ;
return V_32 ;
}
int F_143 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_111 * V_112 = F_138 ( V_95 ) ;
struct V_8 * V_124 = V_112 -> V_117 [ 0 ] ;
V_242 -> V_31 . V_245 . V_62 [ 0 ] = V_124 -> V_31 ;
return 0 ;
}
int F_144 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_111 * V_112 = F_138 ( V_95 ) ;
struct V_8 * V_124 = V_112 -> V_117 [ 0 ] ;
struct V_220 * V_19 = V_124 -> V_19 ;
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_60 * V_61 =
(struct V_60 * ) V_95 -> V_54 ;
int V_32 ;
int V_35 = 0 ;
int V_244 ;
if ( V_242 -> V_31 . V_245 . V_62 [ 0 ] >= V_61 -> V_56 )
return - V_121 ;
F_60 ( & V_14 -> V_141 , V_142 ) ;
V_32 = V_124 -> V_31 != V_242 -> V_31 . V_245 . V_62 [ 0 ] ;
if ( V_32 ) {
for ( V_244 = 0 ; V_244 < V_112 -> V_116 ; V_244 ++ ) {
V_124 = V_112 -> V_117 [ V_244 ] ;
V_124 -> V_31 = V_242 -> V_31 . V_245 . V_62 [ 0 ] ;
F_116 ( V_124 , V_95 , V_124 -> V_31 , V_61 ) ;
}
}
F_30 ( & V_14 -> V_141 ) ;
return V_35 ;
}
int F_145 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_111 * V_112 = F_138 ( V_95 ) ;
struct V_8 * V_124 = V_112 -> V_117 [ 0 ] ;
struct V_60 * V_61 = (struct V_60 * ) V_95 -> V_54 ;
unsigned int V_247 , V_27 , V_213 ;
V_247 = F_21 ( V_124 -> V_19 , V_61 -> V_26 ) ;
V_27 = ( V_247 >> V_61 -> V_64 ) & V_61 -> V_30 ;
for ( V_213 = 0 ; V_213 < V_61 -> V_56 ; V_213 ++ ) {
if ( V_27 == V_61 -> V_68 [ V_213 ] )
break;
}
V_242 -> V_31 . V_245 . V_62 [ 0 ] = V_213 ;
if ( V_61 -> V_64 != V_61 -> V_246 ) {
V_27 = ( V_247 >> V_61 -> V_246 ) & V_61 -> V_30 ;
for ( V_213 = 0 ; V_213 < V_61 -> V_56 ; V_213 ++ ) {
if ( V_27 == V_61 -> V_68 [ V_213 ] )
break;
}
V_242 -> V_31 . V_245 . V_62 [ 1 ] = V_213 ;
}
return 0 ;
}
int F_146 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_111 * V_112 = F_138 ( V_95 ) ;
struct V_8 * V_124 = V_112 -> V_117 [ 0 ] ;
struct V_220 * V_19 = V_124 -> V_19 ;
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_60 * V_61 = (struct V_60 * ) V_95 -> V_54 ;
unsigned int V_27 , V_213 , V_32 ;
unsigned int V_30 ;
struct V_184 V_185 ;
int V_244 ;
if ( V_242 -> V_31 . V_245 . V_62 [ 0 ] > V_61 -> V_56 - 1 )
return - V_121 ;
V_213 = V_242 -> V_31 . V_245 . V_62 [ 0 ] ;
V_27 = V_61 -> V_68 [ V_242 -> V_31 . V_245 . V_62 [ 0 ] ] << V_61 -> V_64 ;
V_30 = V_61 -> V_30 << V_61 -> V_64 ;
if ( V_61 -> V_64 != V_61 -> V_246 ) {
if ( V_242 -> V_31 . V_245 . V_62 [ 1 ] > V_61 -> V_56 - 1 )
return - V_121 ;
V_27 |= V_61 -> V_68 [ V_242 -> V_31 . V_245 . V_62 [ 1 ] ] << V_61 -> V_246 ;
V_30 |= V_61 -> V_30 << V_61 -> V_246 ;
}
F_60 ( & V_14 -> V_141 , V_142 ) ;
V_32 = F_140 ( V_124 -> V_19 , V_61 -> V_26 , V_30 , V_27 ) ;
if ( V_32 ) {
for ( V_244 = 0 ; V_244 < V_112 -> V_116 ; V_244 ++ ) {
V_124 = V_112 -> V_117 [ V_244 ] ;
V_124 -> V_31 = V_27 ;
V_185 . V_95 = V_95 ;
V_185 . V_124 = V_124 ;
V_185 . V_26 = V_61 -> V_26 ;
V_185 . V_30 = V_30 ;
V_185 . V_27 = V_27 ;
V_124 -> V_12 -> V_185 = & V_185 ;
F_116 ( V_124 , V_95 , V_213 , V_61 ) ;
V_124 -> V_12 -> V_185 = NULL ;
}
}
F_30 ( & V_14 -> V_141 ) ;
return V_32 ;
}
int F_147 ( struct V_106 * V_95 ,
struct V_248 * V_249 )
{
V_249 -> type = V_250 ;
V_249 -> V_205 = 1 ;
V_249 -> V_31 . integer . V_251 = 0 ;
V_249 -> V_31 . integer . V_56 = 1 ;
return 0 ;
}
int F_148 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_21 * V_14 = F_138 ( V_95 ) ;
const char * V_225 = ( const char * ) V_95 -> V_54 ;
F_60 ( & V_14 -> V_141 , V_142 ) ;
V_242 -> V_31 . integer . V_31 [ 0 ] =
F_149 ( & V_14 -> V_12 , V_225 ) ;
F_30 ( & V_14 -> V_141 ) ;
return 0 ;
}
int F_150 ( struct V_106 * V_95 ,
struct V_241 * V_242 )
{
struct V_21 * V_14 = F_138 ( V_95 ) ;
const char * V_225 = ( const char * ) V_95 -> V_54 ;
F_60 ( & V_14 -> V_141 , V_142 ) ;
if ( V_242 -> V_31 . integer . V_31 [ 0 ] )
F_151 ( & V_14 -> V_12 , V_225 ) ;
else
F_152 ( & V_14 -> V_12 , V_225 ) ;
F_30 ( & V_14 -> V_141 ) ;
F_131 ( & V_14 -> V_12 ) ;
return 0 ;
}
static struct V_8 *
F_153 ( struct V_18 * V_12 ,
const struct V_8 * V_124 )
{
struct V_8 * V_9 ;
T_3 V_108 ;
int V_35 ;
if ( ( V_9 = F_13 ( V_124 ) ) == NULL )
return NULL ;
switch ( V_9 -> V_47 ) {
case V_79 :
V_9 -> V_149 = F_154 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_155 ( V_9 -> V_149 ) ) {
V_35 = F_156 ( V_9 -> V_149 ) ;
F_23 ( V_12 -> V_3 , L_77 ,
V_9 -> V_13 , V_35 ) ;
return NULL ;
}
break;
default:
break;
}
V_108 = strlen ( V_124 -> V_13 ) + 1 ;
if ( V_12 -> V_19 && V_12 -> V_19 -> V_114 )
V_108 += 1 + strlen ( V_12 -> V_19 -> V_114 ) ;
V_9 -> V_13 = F_5 ( V_108 , V_7 ) ;
if ( V_9 -> V_13 == NULL ) {
F_7 ( V_9 ) ;
return NULL ;
}
if ( V_12 -> V_19 && V_12 -> V_19 -> V_114 )
snprintf ( ( char * ) V_9 -> V_13 , V_108 , L_6 ,
V_12 -> V_19 -> V_114 , V_124 -> V_13 ) ;
else
snprintf ( ( char * ) V_9 -> V_13 , V_108 , L_1 , V_124 -> V_13 ) ;
switch ( V_9 -> V_47 ) {
case V_48 :
case V_49 :
case V_50 :
V_9 -> V_152 = F_68 ;
break;
case V_59 :
case V_66 :
case V_67 :
V_9 -> V_152 = F_68 ;
break;
case V_72 :
case V_81 :
V_9 -> V_152 = F_70 ;
break;
case V_75 :
case V_80 :
V_9 -> V_152 = F_71 ;
break;
case V_69 :
case V_70 :
case V_73 :
case V_71 :
case V_76 :
case V_85 :
case V_83 :
case V_84 :
case V_86 :
case V_87 :
V_9 -> V_152 = F_68 ;
break;
case V_78 :
case V_79 :
V_9 -> V_152 = F_72 ;
break;
case V_82 :
V_9 -> V_152 = F_69 ;
break;
default:
V_9 -> V_152 = F_73 ;
break;
}
V_12 -> V_252 ++ ;
V_9 -> V_12 = V_12 ;
V_9 -> V_19 = V_12 -> V_19 ;
V_9 -> V_20 = V_12 -> V_20 ;
F_87 ( & V_9 -> V_99 ) ;
F_87 ( & V_9 -> V_101 ) ;
F_87 ( & V_9 -> V_96 ) ;
F_87 ( & V_9 -> V_10 ) ;
F_39 ( & V_9 -> V_96 , & V_12 -> V_14 -> V_117 ) ;
V_9 -> V_131 = 1 ;
return V_9 ;
}
int F_157 ( struct V_18 * V_12 ,
const struct V_8 * V_124 ,
int V_239 )
{
struct V_8 * V_9 ;
int V_46 ;
int V_35 = 0 ;
F_60 ( & V_12 -> V_14 -> V_141 , V_240 ) ;
for ( V_46 = 0 ; V_46 < V_239 ; V_46 ++ ) {
V_9 = F_153 ( V_12 , V_124 ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 ,
L_78 ,
V_124 -> V_13 ) ;
V_35 = - V_115 ;
break;
}
V_124 ++ ;
}
F_30 ( & V_12 -> V_14 -> V_141 ) ;
return V_35 ;
}
static int F_158 ( struct V_8 * V_9 ,
struct V_106 * V_95 , int V_146 )
{
struct V_44 * V_253 , * V_254 ;
struct V_138 * V_137 , * V_135 ;
const struct V_255 * V_256 = V_9 -> V_257 ;
struct V_258 V_259 ;
struct V_260 * V_257 = NULL ;
T_8 V_4 ;
int V_35 ;
F_82 ( ! V_256 ) ;
F_82 ( F_9 ( & V_9 -> V_99 ) || F_9 ( & V_9 -> V_101 ) ) ;
V_253 = F_81 ( & V_9 -> V_99 , struct V_44 ,
V_98 ) ;
V_254 = F_81 ( & V_9 -> V_101 , struct V_44 ,
V_100 ) ;
F_82 ( ! V_253 || ! V_254 ) ;
F_82 ( ! V_254 -> V_137 || ! V_253 -> V_135 ) ;
F_82 ( ! V_253 -> V_137 || ! V_254 -> V_135 ) ;
V_137 = V_253 -> V_137 -> V_261 ;
V_135 = V_254 -> V_135 -> V_261 ;
if ( V_256 -> V_262 ) {
V_4 = F_159 ( V_256 -> V_262 ) - 1 ;
} else {
F_111 ( V_9 -> V_12 -> V_3 , L_79 ,
V_256 -> V_262 ) ;
V_4 = 0 ;
}
V_257 = F_43 ( sizeof( * V_257 ) , V_7 ) ;
if ( ! V_257 ) {
V_35 = - V_115 ;
goto V_40;
}
F_160 ( F_161 ( V_257 , V_263 ) , V_4 ) ;
F_162 ( V_257 , V_264 ) -> V_251 =
V_256 -> V_265 ;
F_162 ( V_257 , V_264 ) -> V_56 =
V_256 -> V_266 ;
F_162 ( V_257 , V_267 ) -> V_251
= V_256 -> V_268 ;
F_162 ( V_257 , V_267 ) -> V_56
= V_256 -> V_269 ;
memset ( & V_259 , 0 , sizeof( V_259 ) ) ;
switch ( V_146 ) {
case V_167 :
if ( V_137 -> V_41 -> V_270 && V_137 -> V_41 -> V_270 -> V_271 ) {
V_259 . V_140 = V_272 ;
V_35 = V_137 -> V_41 -> V_270 -> V_271 ( & V_259 ,
V_257 , V_137 ) ;
if ( V_35 != 0 ) {
F_23 ( V_137 -> V_3 ,
L_80 , V_35 ) ;
goto V_40;
}
}
if ( V_135 -> V_41 -> V_270 && V_135 -> V_41 -> V_270 -> V_271 ) {
V_259 . V_140 = V_143 ;
V_35 = V_135 -> V_41 -> V_270 -> V_271 ( & V_259 , V_257 ,
V_135 ) ;
if ( V_35 != 0 ) {
F_23 ( V_135 -> V_3 ,
L_80 , V_35 ) ;
goto V_40;
}
}
break;
case V_168 :
V_35 = F_163 ( V_135 , 0 ) ;
if ( V_35 != 0 && V_35 != - V_273 )
F_111 ( V_135 -> V_3 , L_81 , V_35 ) ;
V_35 = 0 ;
break;
case V_169 :
V_35 = F_163 ( V_135 , 1 ) ;
if ( V_35 != 0 && V_35 != - V_273 )
F_111 ( V_135 -> V_3 , L_82 , V_35 ) ;
V_35 = 0 ;
break;
default:
F_16 () ;
return - V_121 ;
}
V_40:
F_7 ( V_257 ) ;
return V_35 ;
}
int F_164 ( struct V_21 * V_14 ,
const struct V_255 * V_257 ,
struct V_8 * V_137 ,
struct V_8 * V_135 )
{
struct V_230 V_274 [ 2 ] ;
struct V_8 V_275 ;
struct V_8 * V_9 ;
T_3 V_276 ;
char * V_277 ;
V_276 = strlen ( V_137 -> V_13 ) + strlen ( V_135 -> V_13 ) + 2 ;
V_277 = F_165 ( V_14 -> V_3 , V_276 , V_7 ) ;
if ( ! V_277 )
return - V_115 ;
snprintf ( V_277 , V_276 , L_83 , V_137 -> V_13 , V_135 -> V_13 ) ;
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
V_275 . V_26 = V_178 ;
V_275 . V_47 = V_87 ;
V_275 . V_13 = V_277 ;
V_275 . V_146 = F_158 ;
V_275 . V_171 = V_167 | V_168 |
V_169 ;
F_52 ( V_14 -> V_3 , L_84 , V_277 ) ;
V_9 = F_153 ( & V_14 -> V_12 , & V_275 ) ;
if ( ! V_9 ) {
F_23 ( V_14 -> V_3 , L_85 ,
V_277 ) ;
return - V_115 ;
}
V_9 -> V_257 = V_257 ;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
V_274 [ 0 ] . V_137 = V_137 -> V_13 ;
V_274 [ 0 ] . V_135 = V_277 ;
V_274 [ 1 ] . V_137 = V_277 ;
V_274 [ 1 ] . V_135 = V_135 -> V_13 ;
return F_133 ( & V_14 -> V_12 , V_274 ,
F_86 ( V_274 ) ) ;
}
int F_166 ( struct V_18 * V_12 ,
struct V_138 * V_139 )
{
struct V_8 V_275 ;
struct V_8 * V_9 ;
F_167 ( V_12 -> V_3 != V_139 -> V_3 ) ;
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
V_275 . V_26 = V_178 ;
if ( V_139 -> V_41 -> V_278 . V_279 ) {
V_275 . V_47 = V_82 ;
V_275 . V_13 = V_139 -> V_41 -> V_278 . V_279 ;
V_275 . V_207 = V_139 -> V_41 -> V_278 . V_279 ;
F_52 ( V_139 -> V_3 , L_84 ,
V_275 . V_13 ) ;
V_9 = F_153 ( V_12 , & V_275 ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_85 ,
V_139 -> V_41 -> V_278 . V_279 ) ;
}
V_9 -> V_261 = V_139 ;
V_139 -> V_144 = V_9 ;
}
if ( V_139 -> V_41 -> V_280 . V_279 ) {
V_275 . V_47 = V_82 ;
V_275 . V_13 = V_139 -> V_41 -> V_280 . V_279 ;
V_275 . V_207 = V_139 -> V_41 -> V_280 . V_279 ;
F_52 ( V_139 -> V_3 , L_84 ,
V_275 . V_13 ) ;
V_9 = F_153 ( V_12 , & V_275 ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_85 ,
V_139 -> V_41 -> V_280 . V_279 ) ;
}
V_9 -> V_261 = V_139 ;
V_139 -> V_145 = V_9 ;
}
return 0 ;
}
int F_168 ( struct V_21 * V_14 )
{
struct V_8 * V_281 , * V_9 ;
struct V_138 * V_139 ;
struct V_230 V_282 ;
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
F_19 (dai_w, &card->widgets, list) {
if ( V_281 -> V_47 != V_82 )
continue;
V_139 = V_281 -> V_261 ;
F_19 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_281 -> V_12 )
continue;
if ( V_9 -> V_47 == V_82 )
continue;
if ( ! V_9 -> V_207 )
continue;
if ( V_139 -> V_41 -> V_278 . V_279 &&
strstr ( V_9 -> V_207 ,
V_139 -> V_41 -> V_278 . V_279 ) ) {
V_282 . V_137 = V_139 -> V_144 -> V_13 ;
V_282 . V_135 = V_9 -> V_13 ;
F_52 ( V_139 -> V_3 , L_86 ,
V_282 . V_137 , V_282 . V_135 ) ;
F_132 ( V_9 -> V_12 , & V_282 ) ;
}
if ( V_139 -> V_41 -> V_280 . V_279 &&
strstr ( V_9 -> V_207 ,
V_139 -> V_41 -> V_280 . V_279 ) ) {
V_282 . V_137 = V_9 -> V_13 ;
V_282 . V_135 = V_139 -> V_145 -> V_13 ;
F_52 ( V_139 -> V_3 , L_86 ,
V_282 . V_137 , V_282 . V_135 ) ;
F_132 ( V_9 -> V_12 , & V_282 ) ;
}
}
}
return 0 ;
}
static void F_169 ( struct V_218 * V_219 , int V_140 ,
int V_146 )
{
struct V_8 * V_283 , * V_284 ;
struct V_138 * V_285 = V_219 -> V_285 ;
struct V_138 * V_286 = V_219 -> V_286 ;
if ( V_140 == V_143 ) {
V_283 = V_285 -> V_144 ;
V_284 = V_286 -> V_144 ;
} else {
V_283 = V_285 -> V_145 ;
V_284 = V_286 -> V_145 ;
}
if ( V_283 ) {
F_10 ( V_283 , L_87 ) ;
switch ( V_146 ) {
case V_182 :
V_283 -> V_130 = 1 ;
break;
case V_183 :
V_283 -> V_130 = 0 ;
break;
case V_287 :
case V_288 :
case V_289 :
case V_290 :
break;
}
}
if ( V_284 ) {
F_10 ( V_284 , L_87 ) ;
switch ( V_146 ) {
case V_182 :
V_284 -> V_130 = 1 ;
break;
case V_183 :
V_284 -> V_130 = 0 ;
break;
case V_287 :
case V_288 :
case V_289 :
case V_290 :
break;
}
}
F_99 ( & V_219 -> V_14 -> V_12 , V_146 ) ;
}
void F_170 ( struct V_218 * V_219 , int V_140 ,
int V_146 )
{
struct V_21 * V_14 = V_219 -> V_14 ;
F_60 ( & V_14 -> V_141 , V_142 ) ;
F_169 ( V_219 , V_140 , V_146 ) ;
F_30 ( & V_14 -> V_141 ) ;
}
int F_151 ( struct V_18 * V_12 , const char * V_225 )
{
return F_130 ( V_12 , V_225 , 1 ) ;
}
int F_171 ( struct V_18 * V_12 ,
const char * V_225 )
{
struct V_8 * V_9 = F_129 ( V_12 , V_225 , true ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_67 , V_225 ) ;
return - V_121 ;
}
F_52 ( V_9 -> V_12 -> V_3 , L_88 , V_225 ) ;
V_9 -> V_131 = 1 ;
V_9 -> V_151 = 1 ;
F_10 ( V_9 , L_89 ) ;
return 0 ;
}
int F_152 ( struct V_18 * V_12 ,
const char * V_225 )
{
return F_130 ( V_12 , V_225 , 0 ) ;
}
int F_172 ( struct V_18 * V_12 , const char * V_225 )
{
return F_130 ( V_12 , V_225 , 0 ) ;
}
int F_149 ( struct V_18 * V_12 ,
const char * V_225 )
{
struct V_8 * V_9 = F_129 ( V_12 , V_225 , true ) ;
if ( V_9 )
return V_9 -> V_131 ;
return 0 ;
}
int F_173 ( struct V_18 * V_12 ,
const char * V_225 )
{
struct V_8 * V_9 = F_129 ( V_12 , V_225 , false ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_67 , V_225 ) ;
return - V_121 ;
}
V_9 -> V_127 = 1 ;
return 0 ;
}
static bool F_174 ( struct V_21 * V_14 ,
struct V_8 * V_9 )
{
struct V_44 * V_45 ;
F_19 (p, &card->paths, list) {
if ( ( V_45 -> V_137 == V_9 ) || ( V_45 -> V_135 == V_9 ) ) {
F_52 ( V_14 -> V_3 ,
L_90 ,
V_45 -> V_137 -> V_13 , V_45 -> V_137 -> V_47 , V_45 -> V_137 -> V_12 ,
V_45 -> V_135 -> V_13 , V_45 -> V_135 -> V_47 , V_45 -> V_135 -> V_12 ) ;
if ( V_45 -> V_137 -> V_12 != V_45 -> V_135 -> V_12 )
return true ;
if ( V_45 -> V_135 -> V_47 == V_73 ) {
switch ( V_45 -> V_137 -> V_47 ) {
case V_71 :
case V_76 :
return true ;
default:
break;
}
}
}
}
return false ;
}
void F_175 ( struct V_220 * V_19 )
{
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_18 * V_12 = & V_19 -> V_12 ;
struct V_8 * V_9 ;
F_52 ( V_19 -> V_3 , L_91 ,
& V_14 -> V_12 , & V_19 -> V_12 ) ;
F_19 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
switch ( V_9 -> V_47 ) {
case V_73 :
case V_71 :
case V_76 :
F_52 ( V_19 -> V_3 , L_92 ,
V_9 -> V_13 ) ;
if ( ! F_174 ( V_14 , V_9 ) ) {
F_52 ( V_19 -> V_3 ,
L_93 ) ;
F_172 ( V_12 , V_9 -> V_13 ) ;
}
break;
default:
break;
}
}
}
void F_176 ( struct V_18 * V_12 )
{
F_125 ( V_12 -> V_3 ) ;
F_114 ( V_12 ) ;
F_127 ( V_12 ) ;
F_128 ( & V_12 -> V_96 ) ;
}
static void F_177 ( struct V_18 * V_12 )
{
struct V_8 * V_9 ;
F_84 ( V_198 ) ;
int V_291 = 0 ;
F_19 (w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
if ( V_9 -> V_166 ) {
F_75 ( V_9 , & V_198 , false ) ;
V_9 -> V_166 = 0 ;
V_291 = 1 ;
}
}
if ( V_291 ) {
if ( V_12 -> V_42 == V_195 )
F_33 ( V_12 ,
V_194 ) ;
F_83 ( V_12 , & V_198 , 0 , false ) ;
if ( V_12 -> V_42 == V_194 )
F_33 ( V_12 ,
V_193 ) ;
}
}
void F_178 ( struct V_21 * V_14 )
{
struct V_220 * V_19 ;
F_19 (codec, &card->codec_dev_list, list) {
F_177 ( & V_19 -> V_12 ) ;
if ( V_19 -> V_12 . V_42 == V_193 )
F_33 ( & V_19 -> V_12 ,
V_191 ) ;
}
}
