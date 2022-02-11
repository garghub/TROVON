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
void F_13 ( struct V_16 * V_12 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
F_14 ( & V_14 -> V_18 ) ;
F_15 (w, &card->widgets, list) {
switch ( V_9 -> V_19 ) {
case V_20 :
case V_21 :
F_10 ( V_9 , L_3 ) ;
break;
default:
break;
}
}
F_16 ( & V_14 -> V_18 ) ;
}
static inline struct V_8 * F_17 (
const struct V_8 * V_22 )
{
return F_18 ( V_22 , sizeof( * V_22 ) , V_7 ) ;
}
static inline struct V_23 * F_19 (
struct V_16 * V_12 )
{
if ( V_12 -> V_24 )
return V_12 -> V_24 -> V_14 -> V_23 ;
else if ( V_12 -> V_25 )
return V_12 -> V_25 -> V_14 -> V_23 ;
else
F_20 () ;
return NULL ;
}
static inline struct V_17 * F_21 (
struct V_16 * V_12 )
{
if ( V_12 -> V_24 )
return V_12 -> V_24 -> V_14 ;
else if ( V_12 -> V_25 )
return V_12 -> V_25 -> V_14 ;
else
F_20 () ;
return NULL ;
}
static void F_22 ( struct V_17 * V_14 )
{
struct V_8 * V_9 ;
memset ( & V_14 -> V_26 , 0 , sizeof( V_14 -> V_26 ) ) ;
F_15 (w, &card->widgets, list) {
V_9 -> V_27 = false ;
V_9 -> V_28 = - 1 ;
V_9 -> V_29 = - 1 ;
}
}
static int F_23 ( struct V_8 * V_9 , int V_30 )
{
if ( V_9 -> V_24 )
return F_24 ( V_9 -> V_24 , V_30 ) ;
else if ( V_9 -> V_25 )
return F_25 ( V_9 -> V_25 , V_30 ) ;
F_26 ( V_9 -> V_12 -> V_3 , L_4 ) ;
return - 1 ;
}
static int F_27 ( struct V_8 * V_9 , int V_30 , int V_31 )
{
if ( V_9 -> V_24 )
return F_28 ( V_9 -> V_24 , V_30 , V_31 ) ;
else if ( V_9 -> V_25 )
return F_29 ( V_9 -> V_25 , V_30 , V_31 ) ;
F_26 ( V_9 -> V_12 -> V_3 , L_5 ) ;
return - 1 ;
}
static inline void F_30 ( struct V_8 * V_9 )
{
if ( V_9 -> V_24 && ! V_9 -> V_24 -> V_32 )
F_14 ( & V_9 -> V_24 -> V_33 ) ;
else if ( V_9 -> V_25 )
F_14 ( & V_9 -> V_25 -> V_33 ) ;
}
static inline void F_31 ( struct V_8 * V_9 )
{
if ( V_9 -> V_24 && ! V_9 -> V_24 -> V_32 )
F_16 ( & V_9 -> V_24 -> V_33 ) ;
else if ( V_9 -> V_25 )
F_16 ( & V_9 -> V_25 -> V_33 ) ;
}
static int F_32 ( struct V_8 * V_9 ,
unsigned short V_30 , unsigned int V_34 , unsigned int V_35 )
{
bool V_36 ;
unsigned int V_37 , V_38 ;
int V_39 ;
if ( V_9 -> V_24 && V_9 -> V_24 -> V_32 ) {
V_39 = F_33 ( V_9 -> V_24 -> V_40 ,
V_30 , V_34 , V_35 , & V_36 ) ;
if ( V_39 != 0 )
return V_39 ;
} else {
F_30 ( V_9 ) ;
V_39 = F_23 ( V_9 , V_30 ) ;
if ( V_39 < 0 ) {
F_31 ( V_9 ) ;
return V_39 ;
}
V_37 = V_39 ;
V_38 = ( V_37 & ~ V_34 ) | ( V_35 & V_34 ) ;
V_36 = V_37 != V_38 ;
if ( V_36 ) {
V_39 = F_27 ( V_9 , V_30 , V_38 ) ;
if ( V_39 < 0 ) {
F_31 ( V_9 ) ;
return V_39 ;
}
}
F_31 ( V_9 ) ;
}
return V_36 ;
}
static int F_34 ( struct V_16 * V_12 ,
enum V_41 V_42 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
int V_39 = 0 ;
F_35 ( V_14 , V_42 ) ;
if ( V_14 && V_14 -> V_43 )
V_39 = V_14 -> V_43 ( V_14 , V_12 , V_42 ) ;
if ( V_39 != 0 )
goto V_44;
if ( V_12 -> V_24 ) {
if ( V_12 -> V_24 -> V_45 -> V_43 )
V_39 = V_12 -> V_24 -> V_45 -> V_43 ( V_12 -> V_24 ,
V_42 ) ;
else
V_12 -> V_46 = V_42 ;
} else if ( ! V_14 || V_12 != & V_14 -> V_12 ) {
V_12 -> V_46 = V_42 ;
}
if ( V_39 != 0 )
goto V_44;
if ( V_14 && V_14 -> V_47 )
V_39 = V_14 -> V_47 ( V_14 , V_12 , V_42 ) ;
V_44:
F_36 ( V_14 , V_42 ) ;
return V_39 ;
}
static void F_37 ( struct V_8 * V_9 ,
struct V_48 * V_49 , int V_50 )
{
switch ( V_9 -> V_19 ) {
case V_51 :
case V_52 :
case V_53 : {
int V_31 ;
struct V_54 * V_55 = (struct V_54 * )
V_9 -> V_56 [ V_50 ] . V_57 ;
unsigned int V_30 = V_55 -> V_30 ;
unsigned int V_58 = V_55 -> V_58 ;
int V_59 = V_55 -> V_59 ;
unsigned int V_34 = ( 1 << F_38 ( V_59 ) ) - 1 ;
unsigned int V_60 = V_55 -> V_60 ;
V_31 = F_23 ( V_9 , V_30 ) ;
V_31 = ( V_31 >> V_58 ) & V_34 ;
if ( V_60 )
V_31 = V_59 - V_31 ;
V_49 -> V_61 = ! ! V_31 ;
}
break;
case V_62 : {
struct V_63 * V_64 = (struct V_63 * )
V_9 -> V_56 [ V_50 ] . V_57 ;
int V_31 , V_65 ;
V_31 = F_23 ( V_9 , V_64 -> V_30 ) ;
V_65 = ( V_31 >> V_64 -> V_66 ) & V_64 -> V_34 ;
V_49 -> V_61 = 0 ;
for ( V_50 = 0 ; V_50 < V_64 -> V_59 ; V_50 ++ ) {
if ( ! ( strcmp ( V_49 -> V_13 , V_64 -> V_67 [ V_50 ] ) ) && V_65 == V_50 )
V_49 -> V_61 = 1 ;
}
}
break;
case V_68 : {
struct V_63 * V_64 = (struct V_63 * )
V_9 -> V_56 [ V_50 ] . V_57 ;
V_49 -> V_61 = 0 ;
if ( ! strcmp ( V_49 -> V_13 , V_64 -> V_67 [ 0 ] ) )
V_49 -> V_61 = 1 ;
}
break;
case V_69 : {
struct V_63 * V_64 = (struct V_63 * )
V_9 -> V_56 [ V_50 ] . V_57 ;
int V_31 , V_65 ;
V_31 = F_23 ( V_9 , V_64 -> V_30 ) ;
V_31 = ( V_31 >> V_64 -> V_66 ) & V_64 -> V_34 ;
for ( V_65 = 0 ; V_65 < V_64 -> V_59 ; V_65 ++ ) {
if ( V_31 == V_64 -> V_70 [ V_65 ] )
break;
}
V_49 -> V_61 = 0 ;
for ( V_50 = 0 ; V_50 < V_64 -> V_59 ; V_50 ++ ) {
if ( ! ( strcmp ( V_49 -> V_13 , V_64 -> V_67 [ V_50 ] ) ) && V_65 == V_50 )
V_49 -> V_61 = 1 ;
}
}
break;
case V_71 :
case V_72 :
case V_21 :
case V_73 :
case V_20 :
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
case V_88 :
V_49 -> V_61 = 1 ;
break;
case V_89 :
case V_90 :
V_49 -> V_61 = 0 ;
break;
}
}
static int F_39 ( struct V_16 * V_12 ,
struct V_8 * V_91 , struct V_8 * V_92 ,
struct V_48 * V_93 , const char * V_94 ,
const struct V_95 * V_96 )
{
struct V_63 * V_64 = (struct V_63 * ) V_96 -> V_57 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_64 -> V_59 ; V_50 ++ ) {
if ( ! ( strcmp ( V_94 , V_64 -> V_67 [ V_50 ] ) ) ) {
F_40 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_40 ( & V_93 -> V_99 , & V_92 -> V_100 ) ;
F_40 ( & V_93 -> V_101 , & V_91 -> V_102 ) ;
V_93 -> V_13 = ( char * ) V_64 -> V_67 [ V_50 ] ;
F_37 ( V_92 , V_93 , 0 ) ;
return 0 ;
}
}
return - V_103 ;
}
static int F_41 ( struct V_16 * V_12 ,
struct V_8 * V_91 , struct V_8 * V_92 ,
struct V_48 * V_93 , const char * V_94 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_92 -> V_104 ; V_50 ++ ) {
if ( ! strcmp ( V_94 , V_92 -> V_56 [ V_50 ] . V_13 ) ) {
F_40 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_40 ( & V_93 -> V_99 , & V_92 -> V_100 ) ;
F_40 ( & V_93 -> V_101 , & V_91 -> V_102 ) ;
V_93 -> V_13 = V_92 -> V_56 [ V_50 ] . V_13 ;
F_37 ( V_92 , V_93 , V_50 ) ;
return 0 ;
}
}
return - V_103 ;
}
static int F_42 ( struct V_16 * V_12 ,
struct V_8 * V_105 ,
const struct V_95 * V_106 ,
struct V_107 * * V_96 )
{
struct V_8 * V_9 ;
int V_50 ;
* V_96 = NULL ;
F_15 (w, &dapm->card->widgets, list) {
if ( V_9 == V_105 || V_9 -> V_12 != V_105 -> V_12 )
continue;
for ( V_50 = 0 ; V_50 < V_9 -> V_104 ; V_50 ++ ) {
if ( & V_9 -> V_56 [ V_50 ] == V_106 ) {
if ( V_9 -> V_108 )
* V_96 = V_9 -> V_108 [ V_50 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_43 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
int V_50 , V_39 = 0 ;
T_3 V_109 , V_110 ;
struct V_48 * V_93 ;
struct V_23 * V_14 = V_12 -> V_14 -> V_23 ;
const char * V_111 ;
struct V_112 * V_113 ;
T_3 V_114 ;
if ( V_12 -> V_24 )
V_111 = V_12 -> V_24 -> V_115 ;
else
V_111 = NULL ;
if ( V_111 )
V_110 = strlen ( V_111 ) + 1 ;
else
V_110 = 0 ;
for ( V_50 = 0 ; V_50 < V_9 -> V_104 ; V_50 ++ ) {
F_15 (path, &w->sources, list_sink) {
if ( V_93 -> V_13 != ( char * ) V_9 -> V_56 [ V_50 ] . V_13 )
continue;
if ( V_9 -> V_108 [ V_50 ] ) {
V_93 -> V_96 = V_9 -> V_108 [ V_50 ] ;
continue;
}
V_114 = sizeof( struct V_112 ) +
sizeof( struct V_8 * ) ,
V_113 = F_44 ( V_114 , V_7 ) ;
if ( V_113 == NULL ) {
F_26 ( V_12 -> V_3 ,
L_6 ,
V_9 -> V_13 ) ;
return - V_116 ;
}
V_113 -> V_117 = 1 ;
V_113 -> V_118 [ 0 ] = V_9 ;
V_109 = strlen ( V_9 -> V_56 [ V_50 ] . V_13 ) + 1 ;
if ( V_9 -> V_19 != V_53 )
V_109 += 1 + strlen ( V_9 -> V_13 ) ;
V_93 -> V_119 = F_5 ( V_109 , V_7 ) ;
if ( V_93 -> V_119 == NULL ) {
F_7 ( V_113 ) ;
return - V_116 ;
}
switch ( V_9 -> V_19 ) {
default:
snprintf ( ( char * ) V_93 -> V_119 , V_109 ,
L_7 , V_9 -> V_13 + V_110 ,
V_9 -> V_56 [ V_50 ] . V_13 ) ;
break;
case V_53 :
snprintf ( ( char * ) V_93 -> V_119 , V_109 ,
L_1 , V_9 -> V_56 [ V_50 ] . V_13 ) ;
break;
}
( ( char * ) V_93 -> V_119 ) [ V_109 - 1 ] = '\0' ;
V_93 -> V_96 = F_45 ( & V_9 -> V_56 [ V_50 ] ,
V_113 , V_93 -> V_119 ,
V_111 ) ;
V_39 = F_46 ( V_14 , V_93 -> V_96 ) ;
if ( V_39 < 0 ) {
F_26 ( V_12 -> V_3 , L_8
L_9 ,
V_9 -> V_13 , V_93 -> V_119 , V_39 ) ;
F_7 ( V_113 ) ;
F_7 ( V_93 -> V_119 ) ;
V_93 -> V_119 = NULL ;
return V_39 ;
}
V_9 -> V_108 [ V_50 ] = V_93 -> V_96 ;
}
}
return V_39 ;
}
static int F_47 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_48 * V_93 = NULL ;
struct V_107 * V_96 ;
struct V_23 * V_14 = V_12 -> V_14 -> V_23 ;
const char * V_111 ;
T_3 V_110 ;
int V_39 ;
struct V_112 * V_113 ;
int V_120 , V_121 ;
T_3 V_114 ;
const char * V_13 ;
if ( V_9 -> V_104 != 1 ) {
F_26 ( V_12 -> V_3 ,
L_10 ,
V_9 -> V_13 ) ;
return - V_122 ;
}
V_120 = F_42 ( V_12 , V_9 , & V_9 -> V_56 [ 0 ] ,
& V_96 ) ;
if ( V_96 ) {
V_113 = V_96 -> V_123 ;
V_121 = V_113 -> V_117 + 1 ;
} else {
V_113 = NULL ;
V_121 = 1 ;
}
V_114 = sizeof( struct V_112 ) +
V_121 * sizeof( struct V_8 * ) ,
V_113 = F_48 ( V_113 , V_114 , V_7 ) ;
if ( V_113 == NULL ) {
F_26 ( V_12 -> V_3 ,
L_6 , V_9 -> V_13 ) ;
return - V_116 ;
}
V_113 -> V_117 = V_121 ;
V_113 -> V_118 [ V_121 - 1 ] = V_9 ;
if ( ! V_96 ) {
if ( V_12 -> V_24 )
V_111 = V_12 -> V_24 -> V_115 ;
else
V_111 = NULL ;
if ( V_120 ) {
V_13 = V_9 -> V_56 [ 0 ] . V_13 ;
V_110 = 0 ;
} else {
V_13 = V_9 -> V_13 ;
if ( V_111 )
V_110 = strlen ( V_111 ) + 1 ;
else
V_110 = 0 ;
}
V_96 = F_45 ( & V_9 -> V_56 [ 0 ] , V_113 ,
V_13 + V_110 , V_111 ) ;
V_39 = F_46 ( V_14 , V_96 ) ;
if ( V_39 < 0 ) {
F_26 ( V_12 -> V_3 , L_11 ,
V_9 -> V_13 , V_39 ) ;
F_7 ( V_113 ) ;
return V_39 ;
}
}
V_96 -> V_123 = V_113 ;
V_9 -> V_108 [ 0 ] = V_96 ;
F_15 (path, &w->sources, list_sink)
V_93 -> V_96 = V_96 ;
return 0 ;
}
static int F_49 ( struct V_8 * V_9 )
{
if ( V_9 -> V_104 )
F_26 ( V_9 -> V_12 -> V_3 ,
L_12 , V_9 -> V_13 ) ;
return 0 ;
}
static inline void F_50 ( struct V_16 * V_12 )
{
struct V_48 * V_49 ;
F_15 (p, &dapm->card->paths, list)
V_49 -> V_124 = 0 ;
}
static int F_51 ( struct V_8 * V_125 )
{
int V_42 = F_52 ( V_125 -> V_12 -> V_14 -> V_23 ) ;
switch ( V_42 ) {
case V_126 :
case V_127 :
if ( V_125 -> V_128 )
F_53 ( V_125 -> V_12 -> V_3 , L_13 ,
V_125 -> V_13 ) ;
return V_125 -> V_128 ;
default:
return 1 ;
}
}
static int F_54 ( struct V_112 * * V_97 ,
struct V_8 * V_9 )
{
struct V_112 * V_113 ;
int V_114 , V_121 , V_50 ;
if ( * V_97 == NULL )
return - V_122 ;
V_113 = * V_97 ;
for ( V_50 = 0 ; V_50 < V_113 -> V_117 ; V_50 ++ ) {
if ( V_113 -> V_118 [ V_50 ] == V_9 )
return 0 ;
}
V_121 = V_113 -> V_117 + 1 ;
V_114 = sizeof( struct V_112 ) +
V_121 * sizeof( struct V_8 * ) ;
* V_97 = F_48 ( V_113 , V_114 , V_7 ) ;
if ( * V_97 == NULL ) {
F_26 ( V_9 -> V_12 -> V_3 , L_6 ,
V_9 -> V_13 ) ;
return - V_116 ;
}
V_113 = * V_97 ;
F_53 ( V_9 -> V_12 -> V_3 , L_14 ,
V_9 -> V_13 , V_113 -> V_117 ) ;
V_113 -> V_118 [ V_113 -> V_117 ] = V_9 ;
V_113 -> V_117 ++ ;
return 1 ;
}
static int F_55 ( struct V_8 * V_125 ,
struct V_112 * * V_97 )
{
struct V_48 * V_93 ;
int V_129 = 0 ;
if ( V_125 -> V_29 >= 0 )
return V_125 -> V_29 ;
F_56 ( V_125 , V_130 ) ;
switch ( V_125 -> V_19 ) {
case V_78 :
case V_79 :
case V_80 :
return 0 ;
default:
break;
}
switch ( V_125 -> V_19 ) {
case V_73 :
case V_82 :
case V_83 :
if ( V_125 -> V_131 ) {
V_125 -> V_29 = F_51 ( V_125 ) ;
return V_125 -> V_29 ;
}
default:
break;
}
if ( V_125 -> V_132 ) {
if ( V_125 -> V_19 == V_21 && ! V_125 -> V_133 ) {
V_125 -> V_29 = F_51 ( V_125 ) ;
return V_125 -> V_29 ;
}
if ( V_125 -> V_19 == V_84 ||
V_125 -> V_19 == V_86 ||
( V_125 -> V_19 == V_87 &&
! F_9 ( & V_125 -> V_100 ) ) ) {
V_125 -> V_29 = F_51 ( V_125 ) ;
return V_125 -> V_29 ;
}
}
F_15 (path, &widget->sinks, list_source) {
F_56 ( V_125 , V_134 ) ;
if ( V_93 -> V_135 )
continue;
if ( V_93 -> V_136 )
return 1 ;
if ( V_93 -> V_124 )
continue;
F_57 ( V_125 , V_93 ) ;
if ( V_93 -> V_137 && V_93 -> V_61 ) {
V_93 -> V_124 = 1 ;
V_93 -> V_136 = 1 ;
if ( V_97 ) {
int V_138 ;
V_138 = F_54 ( V_97 , V_93 -> V_137 ) ;
if ( V_138 < 0 ) {
F_26 ( V_125 -> V_12 -> V_3 ,
L_15 ,
V_125 -> V_13 ) ;
V_93 -> V_136 = 0 ;
return V_129 ;
}
}
V_129 += F_55 ( V_93 -> V_137 , V_97 ) ;
V_93 -> V_136 = 0 ;
}
}
V_125 -> V_29 = V_129 ;
return V_129 ;
}
static int F_58 ( struct V_8 * V_125 ,
struct V_112 * * V_97 )
{
struct V_48 * V_93 ;
int V_129 = 0 ;
if ( V_125 -> V_28 >= 0 )
return V_125 -> V_28 ;
F_56 ( V_125 , V_130 ) ;
switch ( V_125 -> V_19 ) {
case V_78 :
case V_79 :
case V_80 :
return 0 ;
default:
break;
}
switch ( V_125 -> V_19 ) {
case V_75 :
case V_81 :
case V_83 :
if ( V_125 -> V_131 ) {
V_125 -> V_28 = F_51 ( V_125 ) ;
return V_125 -> V_28 ;
}
default:
break;
}
if ( V_125 -> V_132 ) {
if ( V_125 -> V_19 == V_20 && ! V_125 -> V_133 ) {
V_125 -> V_28 = F_51 ( V_125 ) ;
return V_125 -> V_28 ;
}
if ( V_125 -> V_19 == V_77 ) {
V_125 -> V_28 = F_51 ( V_125 ) ;
return V_125 -> V_28 ;
}
if ( V_125 -> V_19 == V_85 ||
( V_125 -> V_19 == V_87 &&
! F_9 ( & V_125 -> V_102 ) ) ) {
V_125 -> V_28 = F_51 ( V_125 ) ;
return V_125 -> V_28 ;
}
if ( V_125 -> V_19 == V_74 ) {
V_125 -> V_28 = F_51 ( V_125 ) ;
return V_125 -> V_28 ;
}
}
F_15 (path, &widget->sources, list_sink) {
F_56 ( V_125 , V_134 ) ;
if ( V_93 -> V_135 )
continue;
if ( V_93 -> V_136 )
return 1 ;
if ( V_93 -> V_124 )
continue;
F_59 ( V_125 , V_93 ) ;
if ( V_93 -> V_139 && V_93 -> V_61 ) {
V_93 -> V_124 = 1 ;
V_93 -> V_136 = 1 ;
if ( V_97 ) {
int V_138 ;
V_138 = F_54 ( V_97 , V_93 -> V_139 ) ;
if ( V_138 < 0 ) {
F_26 ( V_125 -> V_12 -> V_3 ,
L_15 ,
V_125 -> V_13 ) ;
V_93 -> V_136 = 0 ;
return V_129 ;
}
}
V_129 += F_58 ( V_93 -> V_139 , V_97 ) ;
V_93 -> V_136 = 0 ;
}
}
V_125 -> V_28 = V_129 ;
return V_129 ;
}
int F_60 ( struct V_140 * V_141 , int V_142 ,
struct V_112 * * V_97 )
{
struct V_17 * V_14 = V_141 -> V_14 ;
int V_98 ;
F_61 ( & V_14 -> V_18 , V_143 ) ;
F_22 ( V_14 ) ;
if ( V_142 == V_144 )
V_98 = F_55 ( V_141 -> V_145 , V_97 ) ;
else
V_98 = F_58 ( V_141 -> V_146 , V_97 ) ;
F_62 ( V_98 , V_142 ) ;
F_50 ( & V_14 -> V_12 ) ;
F_16 ( & V_14 -> V_18 ) ;
return V_98 ;
}
int F_63 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_147 )
{
unsigned int V_31 ;
if ( F_64 ( V_147 ) )
V_31 = V_9 -> V_148 ;
else
V_31 = V_9 -> V_149 ;
F_32 ( V_9 , - ( V_9 -> V_30 + 1 ) ,
V_9 -> V_34 << V_9 -> V_58 , V_31 << V_9 -> V_58 ) ;
return 0 ;
}
int F_65 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_147 )
{
int V_39 ;
if ( F_64 ( V_147 ) ) {
if ( V_9 -> V_60 & V_150 ) {
V_39 = F_66 ( V_9 -> V_151 , false ) ;
if ( V_39 != 0 )
F_67 ( V_9 -> V_12 -> V_3 ,
L_16 ,
V_9 -> V_13 , V_39 ) ;
}
return F_68 ( V_9 -> V_151 ) ;
} else {
if ( V_9 -> V_60 & V_150 ) {
V_39 = F_66 ( V_9 -> V_151 , true ) ;
if ( V_39 != 0 )
F_67 ( V_9 -> V_12 -> V_3 ,
L_17 ,
V_9 -> V_13 , V_39 ) ;
}
return F_69 ( V_9 -> V_151 , V_9 -> V_58 ) ;
}
}
int F_70 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_147 )
{
if ( ! V_9 -> V_152 )
return - V_153 ;
#ifdef F_71
if ( F_64 ( V_147 ) ) {
return F_72 ( V_9 -> V_152 ) ;
} else {
F_73 ( V_9 -> V_152 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_74 ( struct V_8 * V_9 )
{
if ( V_9 -> V_27 )
return V_9 -> V_154 ;
if ( V_9 -> V_155 )
V_9 -> V_154 = 1 ;
else
V_9 -> V_154 = V_9 -> V_156 ( V_9 ) ;
V_9 -> V_27 = true ;
return V_9 -> V_154 ;
}
static int F_75 ( struct V_8 * V_9 )
{
int V_157 , V_44 ;
F_56 ( V_9 , V_158 ) ;
V_157 = F_58 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
V_44 = F_55 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
return V_44 != 0 && V_157 != 0 ;
}
static int F_76 ( struct V_8 * V_9 )
{
F_56 ( V_9 , V_158 ) ;
if ( V_9 -> V_131 )
return V_9 -> V_131 ;
return F_75 ( V_9 ) ;
}
static int F_77 ( struct V_8 * V_9 )
{
int V_157 ;
F_56 ( V_9 , V_158 ) ;
if ( V_9 -> V_131 ) {
V_157 = F_58 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
return V_157 != 0 ;
} else {
return F_75 ( V_9 ) ;
}
}
static int F_78 ( struct V_8 * V_9 )
{
int V_44 ;
F_56 ( V_9 , V_158 ) ;
if ( V_9 -> V_131 ) {
V_44 = F_55 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
return V_44 != 0 ;
} else {
return F_75 ( V_9 ) ;
}
}
static int F_79 ( struct V_8 * V_9 )
{
struct V_48 * V_93 ;
F_56 ( V_9 , V_158 ) ;
F_15 (path, &w->sinks, list_source) {
F_56 ( V_9 , V_134 ) ;
if ( V_93 -> V_135 )
continue;
if ( V_93 -> V_132 &&
! V_93 -> V_132 ( V_93 -> V_139 , V_93 -> V_137 ) )
continue;
if ( ! V_93 -> V_137 )
continue;
if ( F_74 ( V_93 -> V_137 ) )
return 1 ;
}
F_50 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_80 ( struct V_8 * V_9 )
{
return 1 ;
}
static int F_81 ( struct V_8 * V_159 ,
struct V_8 * V_160 ,
bool V_161 )
{
int * V_162 ;
if ( V_161 )
V_162 = V_163 ;
else
V_162 = V_164 ;
if ( V_162 [ V_159 -> V_19 ] != V_162 [ V_160 -> V_19 ] )
return V_162 [ V_159 -> V_19 ] - V_162 [ V_160 -> V_19 ] ;
if ( V_159 -> V_165 != V_160 -> V_165 ) {
if ( V_161 )
return V_159 -> V_165 - V_160 -> V_165 ;
else
return V_160 -> V_165 - V_159 -> V_165 ;
}
if ( V_159 -> V_30 != V_160 -> V_30 )
return V_159 -> V_30 - V_160 -> V_30 ;
if ( V_159 -> V_12 != V_160 -> V_12 )
return ( unsigned long ) V_159 -> V_12 - ( unsigned long ) V_160 -> V_12 ;
return 0 ;
}
static void F_82 ( struct V_8 * V_166 ,
struct V_167 * V_97 ,
bool V_161 )
{
struct V_8 * V_9 ;
F_15 (w, list, power_list)
if ( F_81 ( V_166 , V_9 , V_161 ) < 0 ) {
F_12 ( & V_166 -> V_168 , & V_9 -> V_168 ) ;
return;
}
F_12 ( & V_166 -> V_168 , V_97 ) ;
}
static void F_83 ( struct V_16 * V_12 ,
struct V_8 * V_9 , int V_147 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
const char * V_169 ;
int V_170 , V_39 ;
switch ( V_147 ) {
case V_171 :
V_169 = L_18 ;
V_170 = 1 ;
break;
case V_172 :
V_169 = L_19 ;
V_170 = 1 ;
break;
case V_173 :
V_169 = L_20 ;
V_170 = 0 ;
break;
case V_174 :
V_169 = L_21 ;
V_170 = 0 ;
break;
default:
F_20 () ;
return;
}
if ( V_9 -> V_170 != V_170 )
return;
if ( V_9 -> V_147 && ( V_9 -> V_175 & V_147 ) ) {
F_4 ( V_12 -> V_3 , V_14 -> V_1 , L_22 ,
V_9 -> V_13 , V_169 ) ;
F_84 ( V_9 , V_147 ) ;
V_39 = V_9 -> V_147 ( V_9 , NULL , V_147 ) ;
F_85 ( V_9 , V_147 ) ;
if ( V_39 < 0 )
F_26 ( V_12 -> V_3 , L_23 ,
V_169 , V_9 -> V_13 , V_39 ) ;
}
}
static void F_86 ( struct V_16 * V_12 ,
struct V_167 * V_176 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
int V_30 , V_170 ;
unsigned int V_35 = 0 ;
unsigned int V_34 = 0 ;
unsigned int V_177 ;
V_30 = F_87 ( V_176 , struct V_8 ,
V_168 ) -> V_30 ;
F_15 (w, pending, power_list) {
V_177 = 1 << V_9 -> V_58 ;
F_88 ( V_30 != V_9 -> V_30 ) ;
if ( V_9 -> V_60 )
V_170 = ! V_9 -> V_170 ;
else
V_170 = V_9 -> V_170 ;
V_34 |= V_177 ;
if ( V_170 )
V_35 |= V_177 ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_24 ,
V_9 -> V_13 , V_30 , V_35 , V_34 ) ;
F_83 ( V_12 , V_9 , V_171 ) ;
F_83 ( V_12 , V_9 , V_173 ) ;
}
if ( V_30 >= 0 ) {
V_9 = F_87 ( V_176 , struct V_8 ,
V_168 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_25 ,
V_35 , V_34 , V_30 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_32 ( V_9 , V_30 , V_34 , V_35 ) ;
}
F_15 (w, pending, power_list) {
F_83 ( V_12 , V_9 , V_172 ) ;
F_83 ( V_12 , V_9 , V_174 ) ;
}
}
static void F_89 ( struct V_16 * V_12 ,
struct V_167 * V_97 , int V_147 , bool V_161 )
{
struct V_8 * V_9 , * V_178 ;
F_90 ( V_176 ) ;
int V_179 = - 1 ;
int V_180 = - 1 ;
int V_181 = V_182 ;
struct V_16 * V_183 = NULL ;
int V_39 , V_50 ;
int * V_162 ;
if ( V_161 )
V_162 = V_163 ;
else
V_162 = V_164 ;
F_91 (w, n, list, power_list) {
V_39 = 0 ;
if ( V_162 [ V_9 -> V_19 ] != V_179 || V_9 -> V_30 != V_181 ||
V_9 -> V_12 != V_183 || V_9 -> V_165 != V_180 ) {
if ( ! F_9 ( & V_176 ) )
F_86 ( V_183 , & V_176 ) ;
if ( V_183 && V_183 -> V_184 ) {
for ( V_50 = 0 ; V_50 < F_92 ( V_163 ) ; V_50 ++ )
if ( V_162 [ V_50 ] == V_179 )
V_183 -> V_184 ( V_183 ,
V_50 ,
V_180 ) ;
}
F_93 ( & V_176 ) ;
V_179 = - 1 ;
V_180 = V_185 ;
V_181 = V_182 ;
V_183 = NULL ;
}
switch ( V_9 -> V_19 ) {
case V_89 :
if ( ! V_9 -> V_147 )
F_94 ( V_9 , V_178 , V_97 ,
V_168 ) ;
if ( V_147 == V_186 )
V_39 = V_9 -> V_147 ( V_9 ,
NULL , V_171 ) ;
else if ( V_147 == V_187 )
V_39 = V_9 -> V_147 ( V_9 ,
NULL , V_173 ) ;
break;
case V_90 :
if ( ! V_9 -> V_147 )
F_94 ( V_9 , V_178 , V_97 ,
V_168 ) ;
if ( V_147 == V_186 )
V_39 = V_9 -> V_147 ( V_9 ,
NULL , V_172 ) ;
else if ( V_147 == V_187 )
V_39 = V_9 -> V_147 ( V_9 ,
NULL , V_174 ) ;
break;
default:
V_179 = V_162 [ V_9 -> V_19 ] ;
V_180 = V_9 -> V_165 ;
V_181 = V_9 -> V_30 ;
V_183 = V_9 -> V_12 ;
F_95 ( & V_9 -> V_168 , & V_176 ) ;
break;
}
if ( V_39 < 0 )
F_26 ( V_9 -> V_12 -> V_3 ,
L_26 , V_39 ) ;
}
if ( ! F_9 ( & V_176 ) )
F_86 ( V_183 , & V_176 ) ;
if ( V_183 && V_183 -> V_184 ) {
for ( V_50 = 0 ; V_50 < F_92 ( V_163 ) ; V_50 ++ )
if ( V_162 [ V_50 ] == V_179 )
V_183 -> V_184 ( V_183 ,
V_50 , V_180 ) ;
}
}
static void F_96 ( struct V_16 * V_12 )
{
struct V_188 * V_189 = V_12 -> V_189 ;
struct V_8 * V_9 ;
int V_39 ;
if ( ! V_189 )
return;
V_9 = V_189 -> V_125 ;
if ( V_9 -> V_147 &&
( V_9 -> V_175 & V_190 ) ) {
V_39 = V_9 -> V_147 ( V_9 , V_189 -> V_96 , V_190 ) ;
if ( V_39 != 0 )
F_26 ( V_12 -> V_3 , L_27 ,
V_9 -> V_13 , V_39 ) ;
}
V_39 = F_32 ( V_9 , V_189 -> V_30 , V_189 -> V_34 ,
V_189 -> V_31 ) ;
if ( V_39 < 0 )
F_26 ( V_12 -> V_3 , L_28 ,
V_9 -> V_13 , V_39 ) ;
if ( V_9 -> V_147 &&
( V_9 -> V_175 & V_191 ) ) {
V_39 = V_9 -> V_147 ( V_9 , V_189 -> V_96 , V_191 ) ;
if ( V_39 != 0 )
F_26 ( V_12 -> V_3 , L_29 ,
V_9 -> V_13 , V_39 ) ;
}
}
static void F_97 ( void * V_192 , T_4 V_193 )
{
struct V_16 * V_194 = V_192 ;
int V_39 ;
if ( V_194 -> V_46 == V_195 &&
V_194 -> V_196 != V_195 ) {
if ( V_194 -> V_3 )
F_98 ( V_194 -> V_3 ) ;
V_39 = F_34 ( V_194 , V_197 ) ;
if ( V_39 != 0 )
F_26 ( V_194 -> V_3 ,
L_30 , V_39 ) ;
}
if ( V_194 -> V_46 != V_194 -> V_196 ) {
V_39 = F_34 ( V_194 , V_198 ) ;
if ( V_39 != 0 )
F_26 ( V_194 -> V_3 ,
L_31 , V_39 ) ;
}
}
static void F_99 ( void * V_192 , T_4 V_193 )
{
struct V_16 * V_194 = V_192 ;
int V_39 ;
if ( V_194 -> V_46 == V_198 &&
( V_194 -> V_196 == V_197 ||
V_194 -> V_196 == V_195 ) ) {
V_39 = F_34 ( V_194 , V_197 ) ;
if ( V_39 != 0 )
F_26 ( V_194 -> V_3 , L_32 ,
V_39 ) ;
}
if ( V_194 -> V_46 == V_197 &&
V_194 -> V_196 == V_195 ) {
V_39 = F_34 ( V_194 , V_195 ) ;
if ( V_39 != 0 )
F_26 ( V_194 -> V_3 , L_33 ,
V_39 ) ;
if ( V_194 -> V_3 )
F_100 ( V_194 -> V_3 ) ;
}
if ( V_194 -> V_46 == V_198 &&
V_194 -> V_196 == V_199 ) {
V_39 = F_34 ( V_194 , V_199 ) ;
if ( V_39 != 0 )
F_26 ( V_194 -> V_3 , L_34 ,
V_39 ) ;
}
}
static void F_101 ( struct V_8 * V_200 ,
bool V_170 , bool V_61 )
{
if ( ! V_61 )
return;
if ( V_170 != V_200 -> V_170 )
F_10 ( V_200 , L_35 ) ;
}
static void F_102 ( struct V_8 * V_9 , bool V_170 ,
struct V_167 * V_201 ,
struct V_167 * V_202 )
{
struct V_48 * V_93 ;
if ( V_9 -> V_170 == V_170 )
return;
F_103 ( V_9 , V_170 ) ;
F_15 (path, &w->sources, list_sink) {
if ( V_93 -> V_139 ) {
F_101 ( V_93 -> V_139 , V_170 ,
V_93 -> V_61 ) ;
}
}
switch ( V_9 -> V_19 ) {
case V_78 :
case V_79 :
case V_80 :
break;
default:
F_15 (path, &w->sinks, list_source) {
if ( V_93 -> V_137 ) {
F_101 ( V_93 -> V_137 , V_170 ,
V_93 -> V_61 ) ;
}
}
break;
}
if ( V_170 )
F_82 ( V_9 , V_201 , true ) ;
else
F_82 ( V_9 , V_202 , false ) ;
V_9 -> V_170 = V_170 ;
}
static void F_104 ( struct V_8 * V_9 ,
struct V_167 * V_201 ,
struct V_167 * V_202 )
{
int V_170 ;
switch ( V_9 -> V_19 ) {
case V_89 :
F_82 ( V_9 , V_202 , false ) ;
break;
case V_90 :
F_82 ( V_9 , V_201 , true ) ;
break;
default:
V_170 = F_74 ( V_9 ) ;
F_102 ( V_9 , V_170 , V_201 , V_202 ) ;
break;
}
}
static int F_105 ( struct V_16 * V_12 , int V_147 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
struct V_16 * V_194 ;
F_90 ( V_201 ) ;
F_90 ( V_202 ) ;
F_106 ( V_203 ) ;
enum V_41 V_204 ;
F_107 ( V_14 ) ;
F_15 (d, &card->dapm_list, list) {
if ( V_194 -> V_205 )
V_194 -> V_196 = V_195 ;
else
V_194 -> V_196 = V_197 ;
}
F_22 ( V_14 ) ;
F_15 (w, &card->dapm_dirty, dirty) {
F_104 ( V_9 , & V_201 , & V_202 ) ;
}
F_15 (w, &card->widgets, list) {
switch ( V_9 -> V_19 ) {
case V_89 :
case V_90 :
break;
default:
F_108 ( & V_9 -> V_10 ) ;
break;
}
if ( V_9 -> V_170 ) {
V_194 = V_9 -> V_12 ;
switch ( V_9 -> V_19 ) {
case V_74 :
break;
case V_78 :
case V_79 :
case V_80 :
case V_76 :
if ( V_194 -> V_196 < V_197 )
V_194 -> V_196 = V_197 ;
break;
default:
V_194 -> V_196 = V_199 ;
break;
}
}
}
V_204 = V_195 ;
F_15 (d, &card->dapm_list, list)
if ( V_194 -> V_196 > V_204 )
V_204 = V_194 -> V_196 ;
F_15 (d, &card->dapm_list, list)
if ( ! V_194 -> V_205 )
V_194 -> V_196 = V_204 ;
F_109 ( V_14 ) ;
F_15 (d, &dapm->card->dapm_list, list)
F_110 ( F_97 , V_194 ,
& V_203 ) ;
F_111 ( & V_203 ) ;
F_89 ( V_12 , & V_202 , V_147 , false ) ;
F_96 ( V_12 ) ;
F_89 ( V_12 , & V_201 , V_147 , true ) ;
F_15 (d, &dapm->card->dapm_list, list)
F_110 ( F_99 , V_194 ,
& V_203 ) ;
F_111 ( & V_203 ) ;
F_15 (d, &card->dapm_list, list) {
if ( V_194 -> V_206 )
V_194 -> V_206 ( V_194 , V_147 ) ;
}
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_36 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_112 ( V_14 ) ;
return 0 ;
}
static T_5 F_113 ( struct V_207 * V_207 ,
char T_6 * V_208 ,
T_3 V_209 , T_7 * V_210 )
{
struct V_8 * V_9 = V_207 -> V_123 ;
char * V_5 ;
int V_157 , V_44 ;
T_5 V_39 ;
struct V_48 * V_49 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_116 ;
V_157 = F_58 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
V_44 = F_55 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
V_39 = snprintf ( V_5 , V_6 , L_37 ,
V_9 -> V_13 , V_9 -> V_170 ? L_38 : L_39 ,
V_9 -> V_155 ? L_40 : L_41 , V_157 , V_44 ) ;
if ( V_9 -> V_30 >= 0 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 ,
L_42 ,
V_9 -> V_30 , V_9 -> V_30 , V_9 -> V_58 ) ;
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 , L_43 ) ;
if ( V_9 -> V_211 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 , L_44 ,
V_9 -> V_211 ,
V_9 -> V_131 ? L_45 : L_46 ) ;
F_15 (p, &w->sources, list_sink) {
if ( V_49 -> V_132 && ! V_49 -> V_132 ( V_9 , V_49 -> V_137 ) )
continue;
if ( V_49 -> V_61 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 ,
L_47 ,
V_49 -> V_13 ? V_49 -> V_13 : L_48 ,
V_49 -> V_139 -> V_13 ) ;
}
F_15 (p, &w->sinks, list_source) {
if ( V_49 -> V_132 && ! V_49 -> V_132 ( V_9 , V_49 -> V_137 ) )
continue;
if ( V_49 -> V_61 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 ,
L_49 ,
V_49 -> V_13 ? V_49 -> V_13 : L_48 ,
V_49 -> V_137 -> V_13 ) ;
}
V_39 = F_114 ( V_208 , V_209 , V_210 , V_5 , V_39 ) ;
F_7 ( V_5 ) ;
return V_39 ;
}
static T_5 F_115 ( struct V_207 * V_207 , char T_6 * V_208 ,
T_3 V_209 , T_7 * V_210 )
{
struct V_16 * V_12 = V_207 -> V_123 ;
char * V_42 ;
switch ( V_12 -> V_46 ) {
case V_199 :
V_42 = L_50 ;
break;
case V_198 :
V_42 = L_51 ;
break;
case V_197 :
V_42 = L_52 ;
break;
case V_195 :
V_42 = L_53 ;
break;
default:
F_20 () ;
V_42 = L_54 ;
break;
}
return F_114 ( V_208 , V_209 , V_210 , V_42 ,
strlen ( V_42 ) ) ;
}
void F_116 ( struct V_16 * V_12 ,
struct V_212 * V_213 )
{
struct V_212 * V_194 ;
V_12 -> V_214 = F_117 ( L_55 , V_213 ) ;
if ( ! V_12 -> V_214 ) {
F_67 ( V_12 -> V_3 ,
L_56 ) ;
return;
}
V_194 = F_118 ( L_57 , 0444 ,
V_12 -> V_214 , V_12 ,
& V_215 ) ;
if ( ! V_194 )
F_67 ( V_12 -> V_3 ,
L_58 ) ;
}
static void F_119 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_212 * V_194 ;
if ( ! V_12 -> V_214 || ! V_9 -> V_13 )
return;
V_194 = F_118 ( V_9 -> V_13 , 0444 ,
V_12 -> V_214 , V_9 ,
& V_216 ) ;
if ( ! V_194 )
F_67 ( V_9 -> V_12 -> V_3 ,
L_59 ,
V_9 -> V_13 ) ;
}
static void F_120 ( struct V_16 * V_12 )
{
F_121 ( V_12 -> V_214 ) ;
}
void F_116 ( struct V_16 * V_12 ,
struct V_212 * V_213 )
{
}
static inline void F_119 ( struct V_8 * V_9 )
{
}
static inline void F_120 ( struct V_16 * V_12 )
{
}
static int F_122 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_217 , struct V_63 * V_64 )
{
struct V_48 * V_93 ;
int V_218 = 0 ;
if ( V_125 -> V_19 != V_62 &&
V_125 -> V_19 != V_68 &&
V_125 -> V_19 != V_69 )
return - V_103 ;
F_15 (path, &widget->dapm->card->paths, list) {
if ( V_93 -> V_96 != V_96 )
continue;
if ( ! V_93 -> V_13 || ! V_64 -> V_67 [ V_217 ] )
continue;
V_218 = 1 ;
if ( ! ( strcmp ( V_93 -> V_13 , V_64 -> V_67 [ V_217 ] ) ) ) {
V_93 -> V_61 = 1 ;
F_10 ( V_93 -> V_139 , L_60 ) ;
} else {
if ( V_93 -> V_61 )
F_10 ( V_93 -> V_139 ,
L_61 ) ;
V_93 -> V_61 = 0 ;
}
}
if ( V_218 ) {
F_10 ( V_125 , L_62 ) ;
F_105 ( V_125 -> V_12 , V_219 ) ;
}
return V_218 ;
}
int F_123 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_217 , struct V_63 * V_64 )
{
struct V_17 * V_14 = V_125 -> V_12 -> V_14 ;
int V_39 ;
F_61 ( & V_14 -> V_18 , V_143 ) ;
V_39 = F_122 ( V_125 , V_96 , V_217 , V_64 ) ;
F_16 ( & V_14 -> V_18 ) ;
if ( V_39 > 0 )
F_124 ( V_125 ) ;
return V_39 ;
}
static int F_125 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_61 )
{
struct V_48 * V_93 ;
int V_218 = 0 ;
if ( V_125 -> V_19 != V_52 &&
V_125 -> V_19 != V_53 &&
V_125 -> V_19 != V_51 )
return - V_103 ;
F_15 (path, &widget->dapm->card->paths, list) {
if ( V_93 -> V_96 != V_96 )
continue;
V_218 = 1 ;
V_93 -> V_61 = V_61 ;
F_10 ( V_93 -> V_139 , L_63 ) ;
}
if ( V_218 ) {
F_10 ( V_125 , L_64 ) ;
F_105 ( V_125 -> V_12 , V_219 ) ;
}
return V_218 ;
}
int F_126 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_61 )
{
struct V_17 * V_14 = V_125 -> V_12 -> V_14 ;
int V_39 ;
F_61 ( & V_14 -> V_18 , V_143 ) ;
V_39 = F_125 ( V_125 , V_96 , V_61 ) ;
F_16 ( & V_14 -> V_18 ) ;
if ( V_39 > 0 )
F_124 ( V_125 ) ;
return V_39 ;
}
static T_5 F_127 ( struct V_2 * V_3 ,
struct V_220 * V_221 , char * V_5 )
{
struct V_222 * V_223 = F_128 ( V_3 ) ;
struct V_224 * V_24 = V_223 -> V_24 ;
struct V_8 * V_9 ;
int V_209 = 0 ;
char * V_225 = L_65 ;
F_15 (w, &codec->card->widgets, list) {
if ( V_9 -> V_12 != & V_24 -> V_12 )
continue;
switch ( V_9 -> V_19 ) {
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_76 :
case V_75 :
case V_73 :
case V_71 :
case V_72 :
case V_52 :
case V_53 :
case V_78 :
case V_79 :
case V_80 :
if ( V_9 -> V_13 )
V_209 += sprintf ( V_5 + V_209 , L_66 ,
V_9 -> V_13 , V_9 -> V_170 ? L_38 : L_39 ) ;
break;
default:
break;
}
}
switch ( V_24 -> V_12 . V_46 ) {
case V_199 :
V_225 = L_38 ;
break;
case V_198 :
V_225 = L_67 ;
break;
case V_197 :
V_225 = L_68 ;
break;
case V_195 :
V_225 = L_39 ;
break;
}
V_209 += sprintf ( V_5 + V_209 , L_69 , V_225 ) ;
return V_209 ;
}
int F_129 ( struct V_2 * V_3 )
{
return F_130 ( V_3 , & V_226 ) ;
}
static void F_131 ( struct V_2 * V_3 )
{
F_132 ( V_3 , & V_226 ) ;
}
static void F_133 ( struct V_16 * V_12 )
{
struct V_8 * V_9 , * V_227 ;
struct V_48 * V_49 , * V_228 ;
F_91 (w, next_w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
F_134 ( & V_9 -> V_97 ) ;
F_91 (p, next_p, &w->sources, list_sink) {
F_134 ( & V_49 -> V_99 ) ;
F_134 ( & V_49 -> V_101 ) ;
F_134 ( & V_49 -> V_97 ) ;
F_7 ( V_49 -> V_119 ) ;
F_7 ( V_49 ) ;
}
F_91 (p, next_p, &w->sinks, list_source) {
F_134 ( & V_49 -> V_99 ) ;
F_134 ( & V_49 -> V_101 ) ;
F_134 ( & V_49 -> V_97 ) ;
F_7 ( V_49 -> V_119 ) ;
F_7 ( V_49 ) ;
}
F_7 ( V_9 -> V_108 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
}
static struct V_8 * F_135 (
struct V_16 * V_12 , const char * V_229 ,
bool V_230 )
{
struct V_8 * V_9 ;
struct V_8 * V_231 = NULL ;
F_15 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_9 -> V_13 , V_229 ) ) {
if ( V_9 -> V_12 == V_12 )
return V_9 ;
else
V_231 = V_9 ;
}
}
if ( V_230 )
return V_231 ;
return NULL ;
}
static int F_136 ( struct V_16 * V_12 ,
const char * V_229 , int V_232 )
{
struct V_8 * V_9 = F_135 ( V_12 , V_229 , true ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_70 , V_229 ) ;
return - V_122 ;
}
if ( V_9 -> V_132 != V_232 )
F_10 ( V_9 , L_71 ) ;
V_9 -> V_132 = V_232 ;
if ( V_232 == 0 )
V_9 -> V_155 = 0 ;
return 0 ;
}
int F_137 ( struct V_16 * V_12 )
{
int V_39 ;
if ( ! V_12 -> V_14 || ! V_12 -> V_14 -> V_233 )
return 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_143 ) ;
V_39 = F_105 ( V_12 , V_219 ) ;
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
static int F_138 ( struct V_16 * V_12 ,
const struct V_234 * V_235 )
{
struct V_48 * V_93 ;
struct V_8 * V_236 = NULL , * V_237 = NULL , * V_9 ;
struct V_8 * V_238 = NULL , * V_239 = NULL ;
const char * V_137 ;
const char * V_240 = V_235 -> V_240 ;
const char * V_139 ;
char V_241 [ 80 ] ;
char V_242 [ 80 ] ;
int V_39 = 0 ;
if ( V_12 -> V_24 && V_12 -> V_24 -> V_115 ) {
snprintf ( V_241 , sizeof( V_241 ) , L_7 ,
V_12 -> V_24 -> V_115 , V_235 -> V_137 ) ;
V_137 = V_241 ;
snprintf ( V_242 , sizeof( V_242 ) , L_7 ,
V_12 -> V_24 -> V_115 , V_235 -> V_139 ) ;
V_139 = V_242 ;
} else {
V_137 = V_235 -> V_137 ;
V_139 = V_235 -> V_139 ;
}
F_15 (w, &dapm->card->widgets, list) {
if ( ! V_237 && ! ( strcmp ( V_9 -> V_13 , V_137 ) ) ) {
V_239 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_237 = V_9 ;
continue;
}
if ( ! V_236 && ! ( strcmp ( V_9 -> V_13 , V_139 ) ) ) {
V_238 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_236 = V_9 ;
}
}
if ( ! V_237 )
V_237 = V_239 ;
if ( ! V_236 )
V_236 = V_238 ;
if ( V_236 == NULL ) {
F_26 ( V_12 -> V_3 , L_72 ,
V_235 -> V_139 ) ;
return - V_103 ;
}
if ( V_237 == NULL ) {
F_26 ( V_12 -> V_3 , L_73 ,
V_235 -> V_137 ) ;
return - V_103 ;
}
V_93 = F_44 ( sizeof( struct V_48 ) , V_7 ) ;
if ( ! V_93 )
return - V_116 ;
V_93 -> V_139 = V_236 ;
V_93 -> V_137 = V_237 ;
V_93 -> V_132 = V_235 -> V_132 ;
F_93 ( & V_93 -> V_97 ) ;
F_93 ( & V_93 -> V_101 ) ;
F_93 ( & V_93 -> V_99 ) ;
if ( V_237 -> V_19 == V_20 ) {
if ( V_236 -> V_19 == V_76 ||
V_236 -> V_19 == V_85 ||
V_236 -> V_19 == V_87 ||
V_236 -> V_19 == V_21 )
V_237 -> V_133 = 1 ;
}
if ( V_236 -> V_19 == V_21 ) {
if ( V_237 -> V_19 == V_86 ||
V_237 -> V_19 == V_84 ||
V_237 -> V_19 == V_87 ||
V_237 -> V_19 == V_20 )
V_236 -> V_133 = 1 ;
}
if ( V_240 == NULL ) {
F_40 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_40 ( & V_93 -> V_99 , & V_237 -> V_100 ) ;
F_40 ( & V_93 -> V_101 , & V_236 -> V_102 ) ;
V_93 -> V_61 = 1 ;
return 0 ;
}
switch ( V_237 -> V_19 ) {
case V_73 :
case V_75 :
case V_71 :
case V_72 :
case V_20 :
case V_21 :
case V_74 :
case V_76 :
case V_77 :
case V_89 :
case V_90 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_88 :
F_40 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_40 ( & V_93 -> V_99 , & V_237 -> V_100 ) ;
F_40 ( & V_93 -> V_101 , & V_236 -> V_102 ) ;
V_93 -> V_61 = 1 ;
return 0 ;
case V_62 :
case V_68 :
case V_69 :
V_39 = F_39 ( V_12 , V_236 , V_237 , V_93 , V_240 ,
& V_237 -> V_56 [ 0 ] ) ;
if ( V_39 != 0 )
goto V_138;
break;
case V_51 :
case V_52 :
case V_53 :
V_39 = F_41 ( V_12 , V_236 , V_237 , V_93 , V_240 ) ;
if ( V_39 != 0 )
goto V_138;
break;
case V_84 :
case V_85 :
case V_87 :
case V_86 :
F_40 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_40 ( & V_93 -> V_99 , & V_237 -> V_100 ) ;
F_40 ( & V_93 -> V_101 , & V_236 -> V_102 ) ;
V_93 -> V_61 = 0 ;
return 0 ;
}
F_10 ( V_236 , L_74 ) ;
F_10 ( V_237 , L_74 ) ;
return 0 ;
V_138:
F_67 ( V_12 -> V_3 , L_75 ,
V_139 , V_240 , V_137 ) ;
F_7 ( V_93 ) ;
return V_39 ;
}
static int F_139 ( struct V_16 * V_12 ,
const struct V_234 * V_235 )
{
struct V_48 * V_93 , * V_49 ;
const char * V_137 ;
const char * V_139 ;
char V_241 [ 80 ] ;
char V_242 [ 80 ] ;
if ( V_235 -> V_240 ) {
F_26 ( V_12 -> V_3 ,
L_76 ) ;
return - V_122 ;
}
if ( V_12 -> V_24 && V_12 -> V_24 -> V_115 ) {
snprintf ( V_241 , sizeof( V_241 ) , L_7 ,
V_12 -> V_24 -> V_115 , V_235 -> V_137 ) ;
V_137 = V_241 ;
snprintf ( V_242 , sizeof( V_242 ) , L_7 ,
V_12 -> V_24 -> V_115 , V_235 -> V_139 ) ;
V_139 = V_242 ;
} else {
V_137 = V_235 -> V_137 ;
V_139 = V_235 -> V_139 ;
}
V_93 = NULL ;
F_15 (p, &dapm->card->paths, list) {
if ( strcmp ( V_49 -> V_139 -> V_13 , V_139 ) != 0 )
continue;
if ( strcmp ( V_49 -> V_137 -> V_13 , V_137 ) != 0 )
continue;
V_93 = V_49 ;
break;
}
if ( V_93 ) {
F_10 ( V_93 -> V_139 , L_77 ) ;
F_10 ( V_93 -> V_137 , L_77 ) ;
F_134 ( & V_93 -> V_97 ) ;
F_134 ( & V_93 -> V_99 ) ;
F_134 ( & V_93 -> V_101 ) ;
F_7 ( V_93 ) ;
} else {
F_67 ( V_12 -> V_3 , L_78 ,
V_139 , V_137 ) ;
}
return 0 ;
}
int F_140 ( struct V_16 * V_12 ,
const struct V_234 * V_235 , int V_243 )
{
int V_50 , V_244 , V_39 = 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_245 ) ;
for ( V_50 = 0 ; V_50 < V_243 ; V_50 ++ ) {
V_244 = F_138 ( V_12 , V_235 ) ;
if ( V_244 < 0 ) {
F_26 ( V_12 -> V_3 , L_79 ,
V_235 -> V_139 ,
V_235 -> V_240 ? V_235 -> V_240 : L_80 ,
V_235 -> V_137 ) ;
V_39 = V_244 ;
}
V_235 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
int F_141 ( struct V_16 * V_12 ,
const struct V_234 * V_235 , int V_243 )
{
int V_50 , V_39 = 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_245 ) ;
for ( V_50 = 0 ; V_50 < V_243 ; V_50 ++ ) {
F_139 ( V_12 , V_235 ) ;
V_235 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
static int F_142 ( struct V_16 * V_12 ,
const struct V_234 * V_235 )
{
struct V_8 * V_139 = F_135 ( V_12 ,
V_235 -> V_139 ,
true ) ;
struct V_8 * V_137 = F_135 ( V_12 ,
V_235 -> V_137 ,
true ) ;
struct V_48 * V_93 ;
int V_209 = 0 ;
if ( ! V_139 ) {
F_26 ( V_12 -> V_3 , L_81 ,
V_235 -> V_139 ) ;
return - V_103 ;
}
if ( ! V_137 ) {
F_26 ( V_12 -> V_3 , L_82 ,
V_235 -> V_137 ) ;
return - V_103 ;
}
if ( V_235 -> V_240 || V_235 -> V_132 )
F_67 ( V_12 -> V_3 , L_83 ,
V_235 -> V_139 , V_235 -> V_137 ) ;
F_15 (path, &source->sinks, list_source) {
if ( V_93 -> V_137 == V_137 ) {
V_93 -> V_135 = 1 ;
V_209 ++ ;
}
}
if ( V_209 == 0 )
F_26 ( V_12 -> V_3 , L_84 ,
V_235 -> V_139 , V_235 -> V_137 ) ;
if ( V_209 > 1 )
F_67 ( V_12 -> V_3 , L_85 ,
V_209 , V_235 -> V_139 , V_235 -> V_137 ) ;
return 0 ;
}
int F_143 ( struct V_16 * V_12 ,
const struct V_234 * V_235 , int V_243 )
{
int V_50 , V_138 ;
int V_39 = 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_245 ) ;
for ( V_50 = 0 ; V_50 < V_243 ; V_50 ++ ) {
V_138 = F_142 ( V_12 , V_235 ) ;
if ( V_138 )
V_39 = V_138 ;
V_235 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
int F_144 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_31 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_245 ) ;
F_15 (w, &dapm->card->widgets, list)
{
if ( V_9 -> V_38 )
continue;
if ( V_9 -> V_104 ) {
V_9 -> V_108 = F_44 ( V_9 -> V_104 *
sizeof( struct V_107 * ) ,
V_7 ) ;
if ( ! V_9 -> V_108 ) {
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return - V_116 ;
}
}
switch( V_9 -> V_19 ) {
case V_51 :
case V_52 :
case V_53 :
F_43 ( V_9 ) ;
break;
case V_62 :
case V_68 :
case V_69 :
F_47 ( V_9 ) ;
break;
case V_71 :
case V_72 :
F_49 ( V_9 ) ;
break;
default:
break;
}
if ( V_9 -> V_30 >= 0 ) {
V_31 = F_23 ( V_9 , V_9 -> V_30 ) ;
V_31 &= 1 << V_9 -> V_58 ;
if ( V_9 -> V_60 )
V_31 = ! V_31 ;
if ( V_31 )
V_9 -> V_170 = 1 ;
}
V_9 -> V_38 = 1 ;
F_10 ( V_9 , L_86 ) ;
F_119 ( V_9 ) ;
}
F_105 ( V_12 , V_219 ) ;
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return 0 ;
}
int F_145 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_54 * V_55 =
(struct V_54 * ) V_96 -> V_57 ;
unsigned int V_30 = V_55 -> V_30 ;
unsigned int V_58 = V_55 -> V_58 ;
int V_59 = V_55 -> V_59 ;
unsigned int V_34 = ( 1 << F_38 ( V_59 ) ) - 1 ;
unsigned int V_60 = V_55 -> V_60 ;
if ( F_147 ( V_55 ) )
F_67 ( V_125 -> V_12 -> V_3 ,
L_87 ,
V_96 -> V_19 . V_13 ) ;
V_247 -> V_35 . integer . V_35 [ 0 ] =
( F_24 ( V_125 -> V_24 , V_30 ) >> V_58 ) & V_34 ;
if ( V_60 )
V_247 -> V_35 . integer . V_35 [ 0 ] =
V_59 - V_247 -> V_35 . integer . V_35 [ 0 ] ;
return 0 ;
}
int F_148 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_224 * V_24 = V_125 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_54 * V_55 =
(struct V_54 * ) V_96 -> V_57 ;
unsigned int V_30 = V_55 -> V_30 ;
unsigned int V_58 = V_55 -> V_58 ;
int V_59 = V_55 -> V_59 ;
unsigned int V_34 = ( 1 << F_38 ( V_59 ) ) - 1 ;
unsigned int V_60 = V_55 -> V_60 ;
unsigned int V_31 ;
int V_61 , V_36 ;
struct V_188 V_189 ;
int V_248 ;
if ( F_147 ( V_55 ) )
F_67 ( V_125 -> V_12 -> V_3 ,
L_87 ,
V_96 -> V_19 . V_13 ) ;
V_31 = ( V_247 -> V_35 . integer . V_35 [ 0 ] & V_34 ) ;
V_61 = ! ! V_31 ;
if ( V_60 )
V_31 = V_59 - V_31 ;
V_34 = V_34 << V_58 ;
V_31 = V_31 << V_58 ;
F_61 ( & V_14 -> V_18 , V_143 ) ;
V_36 = F_149 ( V_125 -> V_24 , V_30 , V_34 , V_31 ) ;
if ( V_36 ) {
for ( V_248 = 0 ; V_248 < V_113 -> V_117 ; V_248 ++ ) {
V_125 = V_113 -> V_118 [ V_248 ] ;
V_125 -> V_35 = V_31 ;
V_189 . V_96 = V_96 ;
V_189 . V_125 = V_125 ;
V_189 . V_30 = V_30 ;
V_189 . V_34 = V_34 ;
V_189 . V_31 = V_31 ;
V_125 -> V_12 -> V_189 = & V_189 ;
F_125 ( V_125 , V_96 , V_61 ) ;
V_125 -> V_12 -> V_189 = NULL ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return 0 ;
}
int F_150 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_63 * V_64 = (struct V_63 * ) V_96 -> V_57 ;
unsigned int V_31 ;
V_31 = F_24 ( V_125 -> V_24 , V_64 -> V_30 ) ;
V_247 -> V_35 . V_249 . V_65 [ 0 ] = ( V_31 >> V_64 -> V_66 ) & V_64 -> V_34 ;
if ( V_64 -> V_66 != V_64 -> V_250 )
V_247 -> V_35 . V_249 . V_65 [ 1 ] =
( V_31 >> V_64 -> V_250 ) & V_64 -> V_34 ;
return 0 ;
}
int F_151 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_224 * V_24 = V_125 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_63 * V_64 = (struct V_63 * ) V_96 -> V_57 ;
unsigned int V_31 , V_217 , V_36 ;
unsigned int V_34 ;
struct V_188 V_189 ;
int V_248 ;
if ( V_247 -> V_35 . V_249 . V_65 [ 0 ] > V_64 -> V_59 - 1 )
return - V_122 ;
V_217 = V_247 -> V_35 . V_249 . V_65 [ 0 ] ;
V_31 = V_217 << V_64 -> V_66 ;
V_34 = V_64 -> V_34 << V_64 -> V_66 ;
if ( V_64 -> V_66 != V_64 -> V_250 ) {
if ( V_247 -> V_35 . V_249 . V_65 [ 1 ] > V_64 -> V_59 - 1 )
return - V_122 ;
V_31 |= V_247 -> V_35 . V_249 . V_65 [ 1 ] << V_64 -> V_250 ;
V_34 |= V_64 -> V_34 << V_64 -> V_250 ;
}
F_61 ( & V_14 -> V_18 , V_143 ) ;
V_36 = F_149 ( V_125 -> V_24 , V_64 -> V_30 , V_34 , V_31 ) ;
if ( V_36 ) {
for ( V_248 = 0 ; V_248 < V_113 -> V_117 ; V_248 ++ ) {
V_125 = V_113 -> V_118 [ V_248 ] ;
V_125 -> V_35 = V_31 ;
V_189 . V_96 = V_96 ;
V_189 . V_125 = V_125 ;
V_189 . V_30 = V_64 -> V_30 ;
V_189 . V_34 = V_34 ;
V_189 . V_31 = V_31 ;
V_125 -> V_12 -> V_189 = & V_189 ;
F_122 ( V_125 , V_96 , V_217 , V_64 ) ;
V_125 -> V_12 -> V_189 = NULL ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_36 ;
}
int F_152 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
V_247 -> V_35 . V_249 . V_65 [ 0 ] = V_125 -> V_35 ;
return 0 ;
}
int F_153 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_224 * V_24 = V_125 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_63 * V_64 =
(struct V_63 * ) V_96 -> V_57 ;
int V_36 ;
int V_39 = 0 ;
int V_248 ;
if ( V_247 -> V_35 . V_249 . V_65 [ 0 ] >= V_64 -> V_59 )
return - V_122 ;
F_61 ( & V_14 -> V_18 , V_143 ) ;
V_36 = V_125 -> V_35 != V_247 -> V_35 . V_249 . V_65 [ 0 ] ;
if ( V_36 ) {
for ( V_248 = 0 ; V_248 < V_113 -> V_117 ; V_248 ++ ) {
V_125 = V_113 -> V_118 [ V_248 ] ;
V_125 -> V_35 = V_247 -> V_35 . V_249 . V_65 [ 0 ] ;
F_122 ( V_125 , V_96 , V_125 -> V_35 , V_64 ) ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_39 ;
}
int F_154 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_63 * V_64 = (struct V_63 * ) V_96 -> V_57 ;
unsigned int V_251 , V_31 , V_217 ;
V_251 = F_24 ( V_125 -> V_24 , V_64 -> V_30 ) ;
V_31 = ( V_251 >> V_64 -> V_66 ) & V_64 -> V_34 ;
for ( V_217 = 0 ; V_217 < V_64 -> V_59 ; V_217 ++ ) {
if ( V_31 == V_64 -> V_70 [ V_217 ] )
break;
}
V_247 -> V_35 . V_249 . V_65 [ 0 ] = V_217 ;
if ( V_64 -> V_66 != V_64 -> V_250 ) {
V_31 = ( V_251 >> V_64 -> V_250 ) & V_64 -> V_34 ;
for ( V_217 = 0 ; V_217 < V_64 -> V_59 ; V_217 ++ ) {
if ( V_31 == V_64 -> V_70 [ V_217 ] )
break;
}
V_247 -> V_35 . V_249 . V_65 [ 1 ] = V_217 ;
}
return 0 ;
}
int F_155 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_224 * V_24 = V_125 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_63 * V_64 = (struct V_63 * ) V_96 -> V_57 ;
unsigned int V_31 , V_217 , V_36 ;
unsigned int V_34 ;
struct V_188 V_189 ;
int V_248 ;
if ( V_247 -> V_35 . V_249 . V_65 [ 0 ] > V_64 -> V_59 - 1 )
return - V_122 ;
V_217 = V_247 -> V_35 . V_249 . V_65 [ 0 ] ;
V_31 = V_64 -> V_70 [ V_247 -> V_35 . V_249 . V_65 [ 0 ] ] << V_64 -> V_66 ;
V_34 = V_64 -> V_34 << V_64 -> V_66 ;
if ( V_64 -> V_66 != V_64 -> V_250 ) {
if ( V_247 -> V_35 . V_249 . V_65 [ 1 ] > V_64 -> V_59 - 1 )
return - V_122 ;
V_31 |= V_64 -> V_70 [ V_247 -> V_35 . V_249 . V_65 [ 1 ] ] << V_64 -> V_250 ;
V_34 |= V_64 -> V_34 << V_64 -> V_250 ;
}
F_61 ( & V_14 -> V_18 , V_143 ) ;
V_36 = F_149 ( V_125 -> V_24 , V_64 -> V_30 , V_34 , V_31 ) ;
if ( V_36 ) {
for ( V_248 = 0 ; V_248 < V_113 -> V_117 ; V_248 ++ ) {
V_125 = V_113 -> V_118 [ V_248 ] ;
V_125 -> V_35 = V_31 ;
V_189 . V_96 = V_96 ;
V_189 . V_125 = V_125 ;
V_189 . V_30 = V_64 -> V_30 ;
V_189 . V_34 = V_34 ;
V_189 . V_31 = V_31 ;
V_125 -> V_12 -> V_189 = & V_189 ;
F_122 ( V_125 , V_96 , V_217 , V_64 ) ;
V_125 -> V_12 -> V_189 = NULL ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_36 ;
}
int F_156 ( struct V_107 * V_96 ,
struct V_252 * V_253 )
{
V_253 -> type = V_254 ;
V_253 -> V_209 = 1 ;
V_253 -> V_35 . integer . V_255 = 0 ;
V_253 -> V_35 . integer . V_59 = 1 ;
return 0 ;
}
int F_157 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_17 * V_14 = F_146 ( V_96 ) ;
const char * V_229 = ( const char * ) V_96 -> V_57 ;
F_61 ( & V_14 -> V_18 , V_143 ) ;
V_247 -> V_35 . integer . V_35 [ 0 ] =
F_158 ( & V_14 -> V_12 , V_229 ) ;
F_16 ( & V_14 -> V_18 ) ;
return 0 ;
}
int F_159 ( struct V_107 * V_96 ,
struct V_246 * V_247 )
{
struct V_17 * V_14 = F_146 ( V_96 ) ;
const char * V_229 = ( const char * ) V_96 -> V_57 ;
F_61 ( & V_14 -> V_18 , V_143 ) ;
if ( V_247 -> V_35 . integer . V_35 [ 0 ] )
F_160 ( & V_14 -> V_12 , V_229 ) ;
else
F_161 ( & V_14 -> V_12 , V_229 ) ;
F_16 ( & V_14 -> V_18 ) ;
F_137 ( & V_14 -> V_12 ) ;
return 0 ;
}
static struct V_8 *
F_162 ( struct V_16 * V_12 ,
const struct V_8 * V_125 )
{
struct V_8 * V_9 ;
T_3 V_109 ;
int V_39 ;
if ( ( V_9 = F_17 ( V_125 ) ) == NULL )
return NULL ;
switch ( V_9 -> V_19 ) {
case V_79 :
V_9 -> V_151 = F_163 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_164 ( V_9 -> V_151 ) ) {
V_39 = F_165 ( V_9 -> V_151 ) ;
F_26 ( V_12 -> V_3 , L_88 ,
V_9 -> V_13 , V_39 ) ;
return NULL ;
}
if ( V_9 -> V_60 & V_150 ) {
V_39 = F_66 ( V_9 -> V_151 , true ) ;
if ( V_39 != 0 )
F_67 ( V_9 -> V_12 -> V_3 ,
L_17 ,
V_9 -> V_13 , V_39 ) ;
}
break;
case V_80 :
#ifdef F_166
V_9 -> V_152 = F_167 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_164 ( V_9 -> V_152 ) ) {
V_39 = F_165 ( V_9 -> V_152 ) ;
F_26 ( V_12 -> V_3 , L_88 ,
V_9 -> V_13 , V_39 ) ;
return NULL ;
}
#else
return NULL ;
#endif
break;
default:
break;
}
V_109 = strlen ( V_125 -> V_13 ) + 1 ;
if ( V_12 -> V_24 && V_12 -> V_24 -> V_115 )
V_109 += 1 + strlen ( V_12 -> V_24 -> V_115 ) ;
V_9 -> V_13 = F_5 ( V_109 , V_7 ) ;
if ( V_9 -> V_13 == NULL ) {
F_7 ( V_9 ) ;
return NULL ;
}
if ( V_12 -> V_24 && V_12 -> V_24 -> V_115 )
snprintf ( ( char * ) V_9 -> V_13 , V_109 , L_7 ,
V_12 -> V_24 -> V_115 , V_125 -> V_13 ) ;
else
snprintf ( ( char * ) V_9 -> V_13 , V_109 , L_1 , V_125 -> V_13 ) ;
switch ( V_9 -> V_19 ) {
case V_51 :
case V_52 :
case V_53 :
V_9 -> V_156 = F_75 ;
break;
case V_62 :
case V_68 :
case V_69 :
V_9 -> V_156 = F_75 ;
break;
case V_73 :
case V_82 :
V_9 -> V_156 = F_77 ;
break;
case V_75 :
case V_81 :
V_9 -> V_156 = F_78 ;
break;
case V_71 :
case V_72 :
case V_20 :
case V_21 :
case V_76 :
case V_86 :
case V_84 :
case V_85 :
case V_87 :
case V_88 :
V_9 -> V_156 = F_75 ;
break;
case V_78 :
case V_79 :
case V_80 :
V_9 -> V_156 = F_79 ;
break;
case V_83 :
V_9 -> V_156 = F_76 ;
break;
default:
V_9 -> V_156 = F_80 ;
break;
}
V_12 -> V_256 ++ ;
V_9 -> V_12 = V_12 ;
V_9 -> V_24 = V_12 -> V_24 ;
V_9 -> V_25 = V_12 -> V_25 ;
F_93 ( & V_9 -> V_100 ) ;
F_93 ( & V_9 -> V_102 ) ;
F_93 ( & V_9 -> V_97 ) ;
F_93 ( & V_9 -> V_10 ) ;
F_40 ( & V_9 -> V_97 , & V_12 -> V_14 -> V_118 ) ;
V_9 -> V_132 = 1 ;
return V_9 ;
}
int F_168 ( struct V_16 * V_12 ,
const struct V_8 * V_125 ,
int V_243 )
{
struct V_8 * V_9 ;
int V_50 ;
int V_39 = 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_245 ) ;
for ( V_50 = 0 ; V_50 < V_243 ; V_50 ++ ) {
V_9 = F_162 ( V_12 , V_125 ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 ,
L_89 ,
V_125 -> V_13 ) ;
V_39 = - V_116 ;
break;
}
V_125 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
static int F_169 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_147 )
{
struct V_48 * V_257 , * V_258 ;
struct V_140 * V_139 , * V_137 ;
const struct V_259 * V_260 = V_9 -> V_261 ;
struct V_262 V_263 ;
struct V_264 * V_261 = NULL ;
T_8 V_4 ;
int V_39 ;
F_88 ( ! V_260 ) ;
F_88 ( F_9 ( & V_9 -> V_100 ) || F_9 ( & V_9 -> V_102 ) ) ;
V_257 = F_87 ( & V_9 -> V_100 , struct V_48 ,
V_99 ) ;
V_258 = F_87 ( & V_9 -> V_102 , struct V_48 ,
V_101 ) ;
F_88 ( ! V_257 || ! V_258 ) ;
F_88 ( ! V_258 -> V_139 || ! V_257 -> V_137 ) ;
F_88 ( ! V_257 -> V_139 || ! V_258 -> V_137 ) ;
V_139 = V_257 -> V_139 -> V_265 ;
V_137 = V_258 -> V_137 -> V_265 ;
if ( V_260 -> V_266 ) {
V_4 = F_170 ( V_260 -> V_266 ) - 1 ;
} else {
F_67 ( V_9 -> V_12 -> V_3 , L_90 ,
V_260 -> V_266 ) ;
V_4 = 0 ;
}
V_261 = F_44 ( sizeof( * V_261 ) , V_7 ) ;
if ( ! V_261 ) {
V_39 = - V_116 ;
goto V_44;
}
F_171 ( F_172 ( V_261 , V_267 ) , V_4 ) ;
F_173 ( V_261 , V_268 ) -> V_255 =
V_260 -> V_269 ;
F_173 ( V_261 , V_268 ) -> V_59 =
V_260 -> V_270 ;
F_173 ( V_261 , V_271 ) -> V_255
= V_260 -> V_272 ;
F_173 ( V_261 , V_271 ) -> V_59
= V_260 -> V_273 ;
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
switch ( V_147 ) {
case V_171 :
if ( V_139 -> V_45 -> V_274 && V_139 -> V_45 -> V_274 -> V_275 ) {
V_263 . V_142 = V_276 ;
V_39 = V_139 -> V_45 -> V_274 -> V_275 ( & V_263 ,
V_261 , V_139 ) ;
if ( V_39 != 0 ) {
F_26 ( V_139 -> V_3 ,
L_91 , V_39 ) ;
goto V_44;
}
}
if ( V_137 -> V_45 -> V_274 && V_137 -> V_45 -> V_274 -> V_275 ) {
V_263 . V_142 = V_144 ;
V_39 = V_137 -> V_45 -> V_274 -> V_275 ( & V_263 , V_261 ,
V_137 ) ;
if ( V_39 != 0 ) {
F_26 ( V_137 -> V_3 ,
L_91 , V_39 ) ;
goto V_44;
}
}
break;
case V_172 :
V_39 = F_174 ( V_137 , 0 ,
V_144 ) ;
if ( V_39 != 0 && V_39 != - V_277 )
F_67 ( V_137 -> V_3 , L_92 , V_39 ) ;
V_39 = 0 ;
break;
case V_173 :
V_39 = F_174 ( V_137 , 1 ,
V_144 ) ;
if ( V_39 != 0 && V_39 != - V_277 )
F_67 ( V_137 -> V_3 , L_93 , V_39 ) ;
V_39 = 0 ;
break;
default:
F_20 () ;
return - V_122 ;
}
V_44:
F_7 ( V_261 ) ;
return V_39 ;
}
int F_175 ( struct V_17 * V_14 ,
const struct V_259 * V_261 ,
struct V_8 * V_139 ,
struct V_8 * V_137 )
{
struct V_234 V_278 [ 2 ] ;
struct V_8 V_279 ;
struct V_8 * V_9 ;
T_3 V_280 ;
char * V_281 ;
V_280 = strlen ( V_139 -> V_13 ) + strlen ( V_137 -> V_13 ) + 2 ;
V_281 = F_176 ( V_14 -> V_3 , V_280 , V_7 ) ;
if ( ! V_281 )
return - V_116 ;
snprintf ( V_281 , V_280 , L_94 , V_139 -> V_13 , V_137 -> V_13 ) ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_279 . V_30 = V_182 ;
V_279 . V_19 = V_88 ;
V_279 . V_13 = V_281 ;
V_279 . V_147 = F_169 ;
V_279 . V_175 = V_171 | V_172 |
V_173 ;
F_53 ( V_14 -> V_3 , L_95 , V_281 ) ;
V_9 = F_162 ( & V_14 -> V_12 , & V_279 ) ;
if ( ! V_9 ) {
F_26 ( V_14 -> V_3 , L_96 ,
V_281 ) ;
return - V_116 ;
}
V_9 -> V_261 = V_261 ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_278 [ 0 ] . V_139 = V_139 -> V_13 ;
V_278 [ 0 ] . V_137 = V_281 ;
V_278 [ 1 ] . V_139 = V_281 ;
V_278 [ 1 ] . V_137 = V_137 -> V_13 ;
return F_140 ( & V_14 -> V_12 , V_278 ,
F_92 ( V_278 ) ) ;
}
int F_177 ( struct V_16 * V_12 ,
struct V_140 * V_141 )
{
struct V_8 V_279 ;
struct V_8 * V_9 ;
F_178 ( V_12 -> V_3 != V_141 -> V_3 ) ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_279 . V_30 = V_182 ;
if ( V_141 -> V_45 -> V_282 . V_283 ) {
V_279 . V_19 = V_83 ;
V_279 . V_13 = V_141 -> V_45 -> V_282 . V_283 ;
V_279 . V_211 = V_141 -> V_45 -> V_282 . V_283 ;
F_53 ( V_141 -> V_3 , L_95 ,
V_279 . V_13 ) ;
V_9 = F_162 ( V_12 , & V_279 ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_96 ,
V_141 -> V_45 -> V_282 . V_283 ) ;
}
V_9 -> V_265 = V_141 ;
V_141 -> V_145 = V_9 ;
}
if ( V_141 -> V_45 -> V_284 . V_283 ) {
V_279 . V_19 = V_83 ;
V_279 . V_13 = V_141 -> V_45 -> V_284 . V_283 ;
V_279 . V_211 = V_141 -> V_45 -> V_284 . V_283 ;
F_53 ( V_141 -> V_3 , L_95 ,
V_279 . V_13 ) ;
V_9 = F_162 ( V_12 , & V_279 ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_96 ,
V_141 -> V_45 -> V_284 . V_283 ) ;
}
V_9 -> V_265 = V_141 ;
V_141 -> V_146 = V_9 ;
}
return 0 ;
}
int F_179 ( struct V_17 * V_14 )
{
struct V_8 * V_285 , * V_9 ;
struct V_140 * V_141 ;
struct V_234 V_244 ;
memset ( & V_244 , 0 , sizeof( V_244 ) ) ;
F_15 (dai_w, &card->widgets, list) {
if ( V_285 -> V_19 != V_83 )
continue;
V_141 = V_285 -> V_265 ;
F_15 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_285 -> V_12 )
continue;
if ( V_9 -> V_19 == V_83 )
continue;
if ( ! V_9 -> V_211 )
continue;
if ( V_141 -> V_45 -> V_282 . V_283 &&
strstr ( V_9 -> V_211 ,
V_141 -> V_45 -> V_282 . V_283 ) ) {
V_244 . V_139 = V_141 -> V_145 -> V_13 ;
V_244 . V_137 = V_9 -> V_13 ;
F_53 ( V_141 -> V_3 , L_97 ,
V_244 . V_139 , V_244 . V_137 ) ;
F_138 ( V_9 -> V_12 , & V_244 ) ;
}
if ( V_141 -> V_45 -> V_284 . V_283 &&
strstr ( V_9 -> V_211 ,
V_141 -> V_45 -> V_284 . V_283 ) ) {
V_244 . V_139 = V_9 -> V_13 ;
V_244 . V_137 = V_141 -> V_146 -> V_13 ;
F_53 ( V_141 -> V_3 , L_97 ,
V_244 . V_139 , V_244 . V_137 ) ;
F_138 ( V_9 -> V_12 , & V_244 ) ;
}
}
}
return 0 ;
}
static void F_180 ( struct V_222 * V_223 , int V_142 ,
int V_147 )
{
struct V_8 * V_286 , * V_287 ;
struct V_140 * V_288 = V_223 -> V_288 ;
struct V_140 * V_289 = V_223 -> V_289 ;
if ( V_142 == V_144 ) {
V_286 = V_288 -> V_145 ;
V_287 = V_289 -> V_145 ;
} else {
V_286 = V_288 -> V_146 ;
V_287 = V_289 -> V_146 ;
}
if ( V_286 ) {
F_10 ( V_286 , L_98 ) ;
switch ( V_147 ) {
case V_186 :
V_286 -> V_131 = 1 ;
break;
case V_187 :
V_286 -> V_131 = 0 ;
break;
case V_290 :
case V_291 :
case V_292 :
case V_293 :
break;
}
}
if ( V_287 ) {
F_10 ( V_287 , L_98 ) ;
switch ( V_147 ) {
case V_186 :
V_287 -> V_131 = 1 ;
break;
case V_187 :
V_287 -> V_131 = 0 ;
break;
case V_290 :
case V_291 :
case V_292 :
case V_293 :
break;
}
}
F_105 ( & V_223 -> V_14 -> V_12 , V_147 ) ;
}
void F_181 ( struct V_222 * V_223 , int V_142 ,
int V_147 )
{
struct V_17 * V_14 = V_223 -> V_14 ;
F_61 ( & V_14 -> V_18 , V_143 ) ;
F_180 ( V_223 , V_142 , V_147 ) ;
F_16 ( & V_14 -> V_18 ) ;
}
int F_160 ( struct V_16 * V_12 , const char * V_229 )
{
return F_136 ( V_12 , V_229 , 1 ) ;
}
int F_182 ( struct V_16 * V_12 ,
const char * V_229 )
{
struct V_8 * V_9 = F_135 ( V_12 , V_229 , true ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_99 , V_229 ) ;
return - V_122 ;
}
F_53 ( V_9 -> V_12 -> V_3 , L_100 , V_229 ) ;
V_9 -> V_132 = 1 ;
V_9 -> V_155 = 1 ;
F_10 ( V_9 , L_101 ) ;
return 0 ;
}
int F_161 ( struct V_16 * V_12 ,
const char * V_229 )
{
return F_136 ( V_12 , V_229 , 0 ) ;
}
int F_183 ( struct V_16 * V_12 , const char * V_229 )
{
return F_136 ( V_12 , V_229 , 0 ) ;
}
int F_158 ( struct V_16 * V_12 ,
const char * V_229 )
{
struct V_8 * V_9 = F_135 ( V_12 , V_229 , true ) ;
if ( V_9 )
return V_9 -> V_132 ;
return 0 ;
}
int F_184 ( struct V_16 * V_12 ,
const char * V_229 )
{
struct V_8 * V_9 = F_135 ( V_12 , V_229 , false ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_99 , V_229 ) ;
return - V_122 ;
}
V_9 -> V_128 = 1 ;
return 0 ;
}
static bool F_185 ( struct V_17 * V_14 ,
struct V_8 * V_9 )
{
struct V_48 * V_49 ;
F_15 (p, &card->paths, list) {
if ( ( V_49 -> V_139 == V_9 ) || ( V_49 -> V_137 == V_9 ) ) {
F_53 ( V_14 -> V_3 ,
L_102 ,
V_49 -> V_139 -> V_13 , V_49 -> V_139 -> V_19 , V_49 -> V_139 -> V_12 ,
V_49 -> V_137 -> V_13 , V_49 -> V_137 -> V_19 , V_49 -> V_137 -> V_12 ) ;
if ( V_49 -> V_139 -> V_12 != V_49 -> V_137 -> V_12 )
return true ;
if ( V_49 -> V_137 -> V_19 == V_20 ) {
switch ( V_49 -> V_139 -> V_19 ) {
case V_21 :
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
void F_186 ( struct V_224 * V_24 )
{
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_16 * V_12 = & V_24 -> V_12 ;
struct V_8 * V_9 ;
F_53 ( V_24 -> V_3 , L_103 ,
& V_14 -> V_12 , & V_24 -> V_12 ) ;
F_15 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
switch ( V_9 -> V_19 ) {
case V_20 :
case V_21 :
case V_76 :
F_53 ( V_24 -> V_3 , L_104 ,
V_9 -> V_13 ) ;
if ( ! F_185 ( V_14 , V_9 ) ) {
F_53 ( V_24 -> V_3 ,
L_105 ) ;
F_183 ( V_12 , V_9 -> V_13 ) ;
}
break;
default:
break;
}
}
}
void F_187 ( struct V_16 * V_12 )
{
F_131 ( V_12 -> V_3 ) ;
F_120 ( V_12 ) ;
F_133 ( V_12 ) ;
F_134 ( & V_12 -> V_97 ) ;
}
static void F_188 ( struct V_16 * V_12 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
F_90 ( V_202 ) ;
int V_294 = 0 ;
F_14 ( & V_14 -> V_18 ) ;
F_15 (w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
if ( V_9 -> V_170 ) {
F_82 ( V_9 , & V_202 , false ) ;
V_9 -> V_170 = 0 ;
V_294 = 1 ;
}
}
if ( V_294 ) {
if ( V_12 -> V_46 == V_199 )
F_34 ( V_12 ,
V_198 ) ;
F_89 ( V_12 , & V_202 , 0 , false ) ;
if ( V_12 -> V_46 == V_198 )
F_34 ( V_12 ,
V_197 ) ;
}
F_16 ( & V_14 -> V_18 ) ;
}
void F_189 ( struct V_17 * V_14 )
{
struct V_224 * V_24 ;
F_15 (codec, &card->codec_dev_list, card_list) {
F_188 ( & V_24 -> V_12 ) ;
if ( V_24 -> V_12 . V_46 == V_197 )
F_34 ( & V_24 -> V_12 ,
V_195 ) ;
}
}
