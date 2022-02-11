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
if ( V_93 -> V_124 )
continue;
F_57 ( V_125 , V_93 ) ;
if ( V_93 -> V_136 && V_93 -> V_61 ) {
V_93 -> V_124 = 1 ;
if ( V_97 ) {
int V_137 ;
V_137 = F_54 ( V_97 , V_93 -> V_136 ) ;
if ( V_137 < 0 ) {
F_26 ( V_125 -> V_12 -> V_3 ,
L_15 ,
V_125 -> V_13 ) ;
return V_129 ;
}
}
V_129 += F_55 ( V_93 -> V_136 , V_97 ) ;
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
if ( V_93 -> V_124 )
continue;
F_59 ( V_125 , V_93 ) ;
if ( V_93 -> V_138 && V_93 -> V_61 ) {
V_93 -> V_124 = 1 ;
if ( V_97 ) {
int V_137 ;
V_137 = F_54 ( V_97 , V_93 -> V_138 ) ;
if ( V_137 < 0 ) {
F_26 ( V_125 -> V_12 -> V_3 ,
L_15 ,
V_125 -> V_13 ) ;
return V_129 ;
}
}
V_129 += F_58 ( V_93 -> V_138 , V_97 ) ;
}
}
V_125 -> V_28 = V_129 ;
return V_129 ;
}
int F_60 ( struct V_139 * V_140 , int V_141 ,
struct V_112 * * V_97 )
{
struct V_17 * V_14 = V_140 -> V_14 ;
int V_98 ;
F_61 ( & V_14 -> V_18 , V_142 ) ;
F_22 ( V_14 ) ;
if ( V_141 == V_143 )
V_98 = F_55 ( V_140 -> V_144 , V_97 ) ;
else
V_98 = F_58 ( V_140 -> V_145 , V_97 ) ;
F_62 ( V_98 , V_141 ) ;
F_50 ( & V_14 -> V_12 ) ;
F_16 ( & V_14 -> V_18 ) ;
return V_98 ;
}
int F_63 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_146 )
{
unsigned int V_31 ;
if ( F_64 ( V_146 ) )
V_31 = V_9 -> V_147 ;
else
V_31 = V_9 -> V_148 ;
F_32 ( V_9 , - ( V_9 -> V_30 + 1 ) ,
V_9 -> V_34 << V_9 -> V_58 , V_31 << V_9 -> V_58 ) ;
return 0 ;
}
int F_65 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_146 )
{
int V_39 ;
if ( F_64 ( V_146 ) ) {
if ( V_9 -> V_60 & V_149 ) {
V_39 = F_66 ( V_9 -> V_150 , false ) ;
if ( V_39 != 0 )
F_67 ( V_9 -> V_12 -> V_3 ,
L_16 ,
V_9 -> V_13 , V_39 ) ;
}
return F_68 ( V_9 -> V_150 ) ;
} else {
if ( V_9 -> V_60 & V_149 ) {
V_39 = F_66 ( V_9 -> V_150 , true ) ;
if ( V_39 != 0 )
F_67 ( V_9 -> V_12 -> V_3 ,
L_17 ,
V_9 -> V_13 , V_39 ) ;
}
return F_69 ( V_9 -> V_150 , V_9 -> V_58 ) ;
}
}
int F_70 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_146 )
{
if ( ! V_9 -> V_151 )
return - V_152 ;
#ifdef F_71
if ( F_64 ( V_146 ) ) {
return F_72 ( V_9 -> V_151 ) ;
} else {
F_73 ( V_9 -> V_151 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_74 ( struct V_8 * V_9 )
{
if ( V_9 -> V_27 )
return V_9 -> V_153 ;
if ( V_9 -> V_154 )
V_9 -> V_153 = 1 ;
else
V_9 -> V_153 = V_9 -> V_155 ( V_9 ) ;
V_9 -> V_27 = true ;
return V_9 -> V_153 ;
}
static int F_75 ( struct V_8 * V_9 )
{
int V_156 , V_44 ;
F_56 ( V_9 , V_157 ) ;
V_156 = F_58 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
V_44 = F_55 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
return V_44 != 0 && V_156 != 0 ;
}
static int F_76 ( struct V_8 * V_9 )
{
F_56 ( V_9 , V_157 ) ;
if ( V_9 -> V_131 )
return V_9 -> V_131 ;
return F_75 ( V_9 ) ;
}
static int F_77 ( struct V_8 * V_9 )
{
int V_156 ;
F_56 ( V_9 , V_157 ) ;
if ( V_9 -> V_131 ) {
V_156 = F_58 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
return V_156 != 0 ;
} else {
return F_75 ( V_9 ) ;
}
}
static int F_78 ( struct V_8 * V_9 )
{
int V_44 ;
F_56 ( V_9 , V_157 ) ;
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
F_56 ( V_9 , V_157 ) ;
F_15 (path, &w->sinks, list_source) {
F_56 ( V_9 , V_134 ) ;
if ( V_93 -> V_135 )
continue;
if ( V_93 -> V_132 &&
! V_93 -> V_132 ( V_93 -> V_138 , V_93 -> V_136 ) )
continue;
if ( ! V_93 -> V_136 )
continue;
if ( F_74 ( V_93 -> V_136 ) )
return 1 ;
}
F_50 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_80 ( struct V_8 * V_9 )
{
return 1 ;
}
static int F_81 ( struct V_8 * V_158 ,
struct V_8 * V_159 ,
bool V_160 )
{
int * V_161 ;
if ( V_160 )
V_161 = V_162 ;
else
V_161 = V_163 ;
if ( V_161 [ V_158 -> V_19 ] != V_161 [ V_159 -> V_19 ] )
return V_161 [ V_158 -> V_19 ] - V_161 [ V_159 -> V_19 ] ;
if ( V_158 -> V_164 != V_159 -> V_164 ) {
if ( V_160 )
return V_158 -> V_164 - V_159 -> V_164 ;
else
return V_159 -> V_164 - V_158 -> V_164 ;
}
if ( V_158 -> V_30 != V_159 -> V_30 )
return V_158 -> V_30 - V_159 -> V_30 ;
if ( V_158 -> V_12 != V_159 -> V_12 )
return ( unsigned long ) V_158 -> V_12 - ( unsigned long ) V_159 -> V_12 ;
return 0 ;
}
static void F_82 ( struct V_8 * V_165 ,
struct V_166 * V_97 ,
bool V_160 )
{
struct V_8 * V_9 ;
F_15 (w, list, power_list)
if ( F_81 ( V_165 , V_9 , V_160 ) < 0 ) {
F_12 ( & V_165 -> V_167 , & V_9 -> V_167 ) ;
return;
}
F_12 ( & V_165 -> V_167 , V_97 ) ;
}
static void F_83 ( struct V_16 * V_12 ,
struct V_8 * V_9 , int V_146 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
const char * V_168 ;
int V_169 , V_39 ;
switch ( V_146 ) {
case V_170 :
V_168 = L_18 ;
V_169 = 1 ;
break;
case V_171 :
V_168 = L_19 ;
V_169 = 1 ;
break;
case V_172 :
V_168 = L_20 ;
V_169 = 0 ;
break;
case V_173 :
V_168 = L_21 ;
V_169 = 0 ;
break;
default:
F_20 () ;
return;
}
if ( V_9 -> V_169 != V_169 )
return;
if ( V_9 -> V_146 && ( V_9 -> V_174 & V_146 ) ) {
F_4 ( V_12 -> V_3 , V_14 -> V_1 , L_22 ,
V_9 -> V_13 , V_168 ) ;
F_84 ( V_9 , V_146 ) ;
V_39 = V_9 -> V_146 ( V_9 , NULL , V_146 ) ;
F_85 ( V_9 , V_146 ) ;
if ( V_39 < 0 )
F_26 ( V_12 -> V_3 , L_23 ,
V_168 , V_9 -> V_13 , V_39 ) ;
}
}
static void F_86 ( struct V_16 * V_12 ,
struct V_166 * V_175 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
int V_30 , V_169 ;
unsigned int V_35 = 0 ;
unsigned int V_34 = 0 ;
unsigned int V_176 ;
V_30 = F_87 ( V_175 , struct V_8 ,
V_167 ) -> V_30 ;
F_15 (w, pending, power_list) {
V_176 = 1 << V_9 -> V_58 ;
F_88 ( V_30 != V_9 -> V_30 ) ;
if ( V_9 -> V_60 )
V_169 = ! V_9 -> V_169 ;
else
V_169 = V_9 -> V_169 ;
V_34 |= V_176 ;
if ( V_169 )
V_35 |= V_176 ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_24 ,
V_9 -> V_13 , V_30 , V_35 , V_34 ) ;
F_83 ( V_12 , V_9 , V_170 ) ;
F_83 ( V_12 , V_9 , V_172 ) ;
}
if ( V_30 >= 0 ) {
V_9 = F_87 ( V_175 , struct V_8 ,
V_167 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_25 ,
V_35 , V_34 , V_30 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_32 ( V_9 , V_30 , V_34 , V_35 ) ;
}
F_15 (w, pending, power_list) {
F_83 ( V_12 , V_9 , V_171 ) ;
F_83 ( V_12 , V_9 , V_173 ) ;
}
}
static void F_89 ( struct V_16 * V_12 ,
struct V_166 * V_97 , int V_146 , bool V_160 )
{
struct V_8 * V_9 , * V_177 ;
F_90 ( V_175 ) ;
int V_178 = - 1 ;
int V_179 = - 1 ;
int V_180 = V_181 ;
struct V_16 * V_182 = NULL ;
int V_39 , V_50 ;
int * V_161 ;
if ( V_160 )
V_161 = V_162 ;
else
V_161 = V_163 ;
F_91 (w, n, list, power_list) {
V_39 = 0 ;
if ( V_161 [ V_9 -> V_19 ] != V_178 || V_9 -> V_30 != V_180 ||
V_9 -> V_12 != V_182 || V_9 -> V_164 != V_179 ) {
if ( ! F_9 ( & V_175 ) )
F_86 ( V_182 , & V_175 ) ;
if ( V_182 && V_182 -> V_183 ) {
for ( V_50 = 0 ; V_50 < F_92 ( V_162 ) ; V_50 ++ )
if ( V_161 [ V_50 ] == V_178 )
V_182 -> V_183 ( V_182 ,
V_50 ,
V_179 ) ;
}
F_93 ( & V_175 ) ;
V_178 = - 1 ;
V_179 = V_184 ;
V_180 = V_181 ;
V_182 = NULL ;
}
switch ( V_9 -> V_19 ) {
case V_89 :
if ( ! V_9 -> V_146 )
F_94 ( V_9 , V_177 , V_97 ,
V_167 ) ;
if ( V_146 == V_185 )
V_39 = V_9 -> V_146 ( V_9 ,
NULL , V_170 ) ;
else if ( V_146 == V_186 )
V_39 = V_9 -> V_146 ( V_9 ,
NULL , V_172 ) ;
break;
case V_90 :
if ( ! V_9 -> V_146 )
F_94 ( V_9 , V_177 , V_97 ,
V_167 ) ;
if ( V_146 == V_185 )
V_39 = V_9 -> V_146 ( V_9 ,
NULL , V_171 ) ;
else if ( V_146 == V_186 )
V_39 = V_9 -> V_146 ( V_9 ,
NULL , V_173 ) ;
break;
default:
V_178 = V_161 [ V_9 -> V_19 ] ;
V_179 = V_9 -> V_164 ;
V_180 = V_9 -> V_30 ;
V_182 = V_9 -> V_12 ;
F_95 ( & V_9 -> V_167 , & V_175 ) ;
break;
}
if ( V_39 < 0 )
F_26 ( V_9 -> V_12 -> V_3 ,
L_26 , V_39 ) ;
}
if ( ! F_9 ( & V_175 ) )
F_86 ( V_182 , & V_175 ) ;
if ( V_182 && V_182 -> V_183 ) {
for ( V_50 = 0 ; V_50 < F_92 ( V_162 ) ; V_50 ++ )
if ( V_161 [ V_50 ] == V_178 )
V_182 -> V_183 ( V_182 ,
V_50 , V_179 ) ;
}
}
static void F_96 ( struct V_16 * V_12 )
{
struct V_187 * V_188 = V_12 -> V_188 ;
struct V_8 * V_9 ;
int V_39 ;
if ( ! V_188 )
return;
V_9 = V_188 -> V_125 ;
if ( V_9 -> V_146 &&
( V_9 -> V_174 & V_189 ) ) {
V_39 = V_9 -> V_146 ( V_9 , V_188 -> V_96 , V_189 ) ;
if ( V_39 != 0 )
F_26 ( V_12 -> V_3 , L_27 ,
V_9 -> V_13 , V_39 ) ;
}
V_39 = F_32 ( V_9 , V_188 -> V_30 , V_188 -> V_34 ,
V_188 -> V_31 ) ;
if ( V_39 < 0 )
F_26 ( V_12 -> V_3 , L_28 ,
V_9 -> V_13 , V_39 ) ;
if ( V_9 -> V_146 &&
( V_9 -> V_174 & V_190 ) ) {
V_39 = V_9 -> V_146 ( V_9 , V_188 -> V_96 , V_190 ) ;
if ( V_39 != 0 )
F_26 ( V_12 -> V_3 , L_29 ,
V_9 -> V_13 , V_39 ) ;
}
}
static void F_97 ( void * V_191 , T_4 V_192 )
{
struct V_16 * V_193 = V_191 ;
int V_39 ;
if ( V_193 -> V_46 == V_194 &&
V_193 -> V_195 != V_194 ) {
if ( V_193 -> V_3 )
F_98 ( V_193 -> V_3 ) ;
V_39 = F_34 ( V_193 , V_196 ) ;
if ( V_39 != 0 )
F_26 ( V_193 -> V_3 ,
L_30 , V_39 ) ;
}
if ( V_193 -> V_46 != V_193 -> V_195 ) {
V_39 = F_34 ( V_193 , V_197 ) ;
if ( V_39 != 0 )
F_26 ( V_193 -> V_3 ,
L_31 , V_39 ) ;
}
}
static void F_99 ( void * V_191 , T_4 V_192 )
{
struct V_16 * V_193 = V_191 ;
int V_39 ;
if ( V_193 -> V_46 == V_197 &&
( V_193 -> V_195 == V_196 ||
V_193 -> V_195 == V_194 ) ) {
V_39 = F_34 ( V_193 , V_196 ) ;
if ( V_39 != 0 )
F_26 ( V_193 -> V_3 , L_32 ,
V_39 ) ;
}
if ( V_193 -> V_46 == V_196 &&
V_193 -> V_195 == V_194 ) {
V_39 = F_34 ( V_193 , V_194 ) ;
if ( V_39 != 0 )
F_26 ( V_193 -> V_3 , L_33 ,
V_39 ) ;
if ( V_193 -> V_3 )
F_100 ( V_193 -> V_3 ) ;
}
if ( V_193 -> V_46 == V_197 &&
V_193 -> V_195 == V_198 ) {
V_39 = F_34 ( V_193 , V_198 ) ;
if ( V_39 != 0 )
F_26 ( V_193 -> V_3 , L_34 ,
V_39 ) ;
}
}
static void F_101 ( struct V_8 * V_199 ,
bool V_169 , bool V_61 )
{
if ( ! V_61 )
return;
if ( V_169 != V_199 -> V_169 )
F_10 ( V_199 , L_35 ) ;
}
static void F_102 ( struct V_8 * V_9 , bool V_169 ,
struct V_166 * V_200 ,
struct V_166 * V_201 )
{
struct V_48 * V_93 ;
if ( V_9 -> V_169 == V_169 )
return;
F_103 ( V_9 , V_169 ) ;
F_15 (path, &w->sources, list_sink) {
if ( V_93 -> V_138 ) {
F_101 ( V_93 -> V_138 , V_169 ,
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
if ( V_93 -> V_136 ) {
F_101 ( V_93 -> V_136 , V_169 ,
V_93 -> V_61 ) ;
}
}
break;
}
if ( V_169 )
F_82 ( V_9 , V_200 , true ) ;
else
F_82 ( V_9 , V_201 , false ) ;
V_9 -> V_169 = V_169 ;
}
static void F_104 ( struct V_8 * V_9 ,
struct V_166 * V_200 ,
struct V_166 * V_201 )
{
int V_169 ;
switch ( V_9 -> V_19 ) {
case V_89 :
F_82 ( V_9 , V_201 , false ) ;
break;
case V_90 :
F_82 ( V_9 , V_200 , true ) ;
break;
default:
V_169 = F_74 ( V_9 ) ;
F_102 ( V_9 , V_169 , V_200 , V_201 ) ;
break;
}
}
static int F_105 ( struct V_16 * V_12 , int V_146 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
struct V_16 * V_193 ;
F_90 ( V_200 ) ;
F_90 ( V_201 ) ;
F_106 ( V_202 ) ;
enum V_41 V_203 ;
F_107 ( V_14 ) ;
F_15 (d, &card->dapm_list, list) {
if ( V_193 -> V_204 )
V_193 -> V_195 = V_194 ;
else
V_193 -> V_195 = V_196 ;
}
F_22 ( V_14 ) ;
F_15 (w, &card->dapm_dirty, dirty) {
F_104 ( V_9 , & V_200 , & V_201 ) ;
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
if ( V_9 -> V_169 ) {
V_193 = V_9 -> V_12 ;
switch ( V_9 -> V_19 ) {
case V_74 :
break;
case V_78 :
case V_79 :
case V_80 :
case V_76 :
if ( V_193 -> V_195 < V_196 )
V_193 -> V_195 = V_196 ;
break;
default:
V_193 -> V_195 = V_198 ;
break;
}
}
}
V_203 = V_194 ;
F_15 (d, &card->dapm_list, list)
if ( V_193 -> V_195 > V_203 )
V_203 = V_193 -> V_195 ;
F_15 (d, &card->dapm_list, list)
if ( ! V_193 -> V_204 )
V_193 -> V_195 = V_203 ;
F_109 ( V_14 ) ;
F_15 (d, &dapm->card->dapm_list, list)
F_110 ( F_97 , V_193 ,
& V_202 ) ;
F_111 ( & V_202 ) ;
F_89 ( V_12 , & V_201 , V_146 , false ) ;
F_96 ( V_12 ) ;
F_89 ( V_12 , & V_200 , V_146 , true ) ;
F_15 (d, &dapm->card->dapm_list, list)
F_110 ( F_99 , V_193 ,
& V_202 ) ;
F_111 ( & V_202 ) ;
F_15 (d, &card->dapm_list, list) {
if ( V_193 -> V_205 )
V_193 -> V_205 ( V_193 , V_146 ) ;
}
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_36 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_112 ( V_14 ) ;
return 0 ;
}
static T_5 F_113 ( struct V_206 * V_206 ,
char T_6 * V_207 ,
T_3 V_208 , T_7 * V_209 )
{
struct V_8 * V_9 = V_206 -> V_123 ;
char * V_5 ;
int V_156 , V_44 ;
T_5 V_39 ;
struct V_48 * V_49 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_116 ;
V_156 = F_58 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
V_44 = F_55 ( V_9 , NULL ) ;
F_50 ( V_9 -> V_12 ) ;
V_39 = snprintf ( V_5 , V_6 , L_37 ,
V_9 -> V_13 , V_9 -> V_169 ? L_38 : L_39 ,
V_9 -> V_154 ? L_40 : L_41 , V_156 , V_44 ) ;
if ( V_9 -> V_30 >= 0 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 ,
L_42 ,
V_9 -> V_30 , V_9 -> V_30 , V_9 -> V_58 ) ;
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 , L_43 ) ;
if ( V_9 -> V_210 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 , L_44 ,
V_9 -> V_210 ,
V_9 -> V_131 ? L_45 : L_46 ) ;
F_15 (p, &w->sources, list_sink) {
if ( V_49 -> V_132 && ! V_49 -> V_132 ( V_9 , V_49 -> V_136 ) )
continue;
if ( V_49 -> V_61 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 ,
L_47 ,
V_49 -> V_13 ? V_49 -> V_13 : L_48 ,
V_49 -> V_138 -> V_13 ) ;
}
F_15 (p, &w->sinks, list_source) {
if ( V_49 -> V_132 && ! V_49 -> V_132 ( V_9 , V_49 -> V_136 ) )
continue;
if ( V_49 -> V_61 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 ,
L_49 ,
V_49 -> V_13 ? V_49 -> V_13 : L_48 ,
V_49 -> V_136 -> V_13 ) ;
}
V_39 = F_114 ( V_207 , V_208 , V_209 , V_5 , V_39 ) ;
F_7 ( V_5 ) ;
return V_39 ;
}
static T_5 F_115 ( struct V_206 * V_206 , char T_6 * V_207 ,
T_3 V_208 , T_7 * V_209 )
{
struct V_16 * V_12 = V_206 -> V_123 ;
char * V_42 ;
switch ( V_12 -> V_46 ) {
case V_198 :
V_42 = L_50 ;
break;
case V_197 :
V_42 = L_51 ;
break;
case V_196 :
V_42 = L_52 ;
break;
case V_194 :
V_42 = L_53 ;
break;
default:
F_20 () ;
V_42 = L_54 ;
break;
}
return F_114 ( V_207 , V_208 , V_209 , V_42 ,
strlen ( V_42 ) ) ;
}
void F_116 ( struct V_16 * V_12 ,
struct V_211 * V_212 )
{
struct V_211 * V_193 ;
V_12 -> V_213 = F_117 ( L_55 , V_212 ) ;
if ( ! V_12 -> V_213 ) {
F_67 ( V_12 -> V_3 ,
L_56 ) ;
return;
}
V_193 = F_118 ( L_57 , 0444 ,
V_12 -> V_213 , V_12 ,
& V_214 ) ;
if ( ! V_193 )
F_67 ( V_12 -> V_3 ,
L_58 ) ;
}
static void F_119 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_211 * V_193 ;
if ( ! V_12 -> V_213 || ! V_9 -> V_13 )
return;
V_193 = F_118 ( V_9 -> V_13 , 0444 ,
V_12 -> V_213 , V_9 ,
& V_215 ) ;
if ( ! V_193 )
F_67 ( V_9 -> V_12 -> V_3 ,
L_59 ,
V_9 -> V_13 ) ;
}
static void F_120 ( struct V_16 * V_12 )
{
F_121 ( V_12 -> V_213 ) ;
}
void F_116 ( struct V_16 * V_12 ,
struct V_211 * V_212 )
{
}
static inline void F_119 ( struct V_8 * V_9 )
{
}
static inline void F_120 ( struct V_16 * V_12 )
{
}
static int F_122 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_216 , struct V_63 * V_64 )
{
struct V_48 * V_93 ;
int V_217 = 0 ;
if ( V_125 -> V_19 != V_62 &&
V_125 -> V_19 != V_68 &&
V_125 -> V_19 != V_69 )
return - V_103 ;
F_15 (path, &widget->dapm->card->paths, list) {
if ( V_93 -> V_96 != V_96 )
continue;
if ( ! V_93 -> V_13 || ! V_64 -> V_67 [ V_216 ] )
continue;
V_217 = 1 ;
if ( ! ( strcmp ( V_93 -> V_13 , V_64 -> V_67 [ V_216 ] ) ) ) {
V_93 -> V_61 = 1 ;
F_10 ( V_93 -> V_138 , L_60 ) ;
} else {
if ( V_93 -> V_61 )
F_10 ( V_93 -> V_138 ,
L_61 ) ;
V_93 -> V_61 = 0 ;
}
}
if ( V_217 ) {
F_10 ( V_125 , L_62 ) ;
F_105 ( V_125 -> V_12 , V_218 ) ;
}
return V_217 ;
}
int F_123 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_216 , struct V_63 * V_64 )
{
struct V_17 * V_14 = V_125 -> V_12 -> V_14 ;
int V_39 ;
F_61 ( & V_14 -> V_18 , V_142 ) ;
V_39 = F_122 ( V_125 , V_96 , V_216 , V_64 ) ;
F_16 ( & V_14 -> V_18 ) ;
if ( V_39 > 0 )
F_124 ( V_125 ) ;
return V_39 ;
}
static int F_125 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_61 )
{
struct V_48 * V_93 ;
int V_217 = 0 ;
if ( V_125 -> V_19 != V_52 &&
V_125 -> V_19 != V_53 &&
V_125 -> V_19 != V_51 )
return - V_103 ;
F_15 (path, &widget->dapm->card->paths, list) {
if ( V_93 -> V_96 != V_96 )
continue;
V_217 = 1 ;
V_93 -> V_61 = V_61 ;
F_10 ( V_93 -> V_138 , L_63 ) ;
}
if ( V_217 ) {
F_10 ( V_125 , L_64 ) ;
F_105 ( V_125 -> V_12 , V_218 ) ;
}
return V_217 ;
}
int F_126 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_61 )
{
struct V_17 * V_14 = V_125 -> V_12 -> V_14 ;
int V_39 ;
F_61 ( & V_14 -> V_18 , V_142 ) ;
V_39 = F_125 ( V_125 , V_96 , V_61 ) ;
F_16 ( & V_14 -> V_18 ) ;
if ( V_39 > 0 )
F_124 ( V_125 ) ;
return V_39 ;
}
static T_5 F_127 ( struct V_2 * V_3 ,
struct V_219 * V_220 , char * V_5 )
{
struct V_221 * V_222 = F_128 ( V_3 ) ;
struct V_223 * V_24 = V_222 -> V_24 ;
struct V_8 * V_9 ;
int V_208 = 0 ;
char * V_224 = L_65 ;
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
V_208 += sprintf ( V_5 + V_208 , L_66 ,
V_9 -> V_13 , V_9 -> V_169 ? L_38 : L_39 ) ;
break;
default:
break;
}
}
switch ( V_24 -> V_12 . V_46 ) {
case V_198 :
V_224 = L_38 ;
break;
case V_197 :
V_224 = L_67 ;
break;
case V_196 :
V_224 = L_68 ;
break;
case V_194 :
V_224 = L_39 ;
break;
}
V_208 += sprintf ( V_5 + V_208 , L_69 , V_224 ) ;
return V_208 ;
}
int F_129 ( struct V_2 * V_3 )
{
return F_130 ( V_3 , & V_225 ) ;
}
static void F_131 ( struct V_2 * V_3 )
{
F_132 ( V_3 , & V_225 ) ;
}
static void F_133 ( struct V_16 * V_12 )
{
struct V_8 * V_9 , * V_226 ;
struct V_48 * V_49 , * V_227 ;
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
struct V_16 * V_12 , const char * V_228 ,
bool V_229 )
{
struct V_8 * V_9 ;
struct V_8 * V_230 = NULL ;
F_15 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_9 -> V_13 , V_228 ) ) {
if ( V_9 -> V_12 == V_12 )
return V_9 ;
else
V_230 = V_9 ;
}
}
if ( V_229 )
return V_230 ;
return NULL ;
}
static int F_136 ( struct V_16 * V_12 ,
const char * V_228 , int V_231 )
{
struct V_8 * V_9 = F_135 ( V_12 , V_228 , true ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_70 , V_228 ) ;
return - V_122 ;
}
if ( V_9 -> V_132 != V_231 )
F_10 ( V_9 , L_71 ) ;
V_9 -> V_132 = V_231 ;
if ( V_231 == 0 )
V_9 -> V_154 = 0 ;
return 0 ;
}
int F_137 ( struct V_16 * V_12 )
{
int V_39 ;
if ( ! V_12 -> V_14 || ! V_12 -> V_14 -> V_232 )
return 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_142 ) ;
V_39 = F_105 ( V_12 , V_218 ) ;
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
static int F_138 ( struct V_16 * V_12 ,
const struct V_233 * V_234 )
{
struct V_48 * V_93 ;
struct V_8 * V_235 = NULL , * V_236 = NULL , * V_9 ;
struct V_8 * V_237 = NULL , * V_238 = NULL ;
const char * V_136 ;
const char * V_239 = V_234 -> V_239 ;
const char * V_138 ;
char V_240 [ 80 ] ;
char V_241 [ 80 ] ;
int V_39 = 0 ;
if ( V_12 -> V_24 && V_12 -> V_24 -> V_115 ) {
snprintf ( V_240 , sizeof( V_240 ) , L_7 ,
V_12 -> V_24 -> V_115 , V_234 -> V_136 ) ;
V_136 = V_240 ;
snprintf ( V_241 , sizeof( V_241 ) , L_7 ,
V_12 -> V_24 -> V_115 , V_234 -> V_138 ) ;
V_138 = V_241 ;
} else {
V_136 = V_234 -> V_136 ;
V_138 = V_234 -> V_138 ;
}
F_15 (w, &dapm->card->widgets, list) {
if ( ! V_236 && ! ( strcmp ( V_9 -> V_13 , V_136 ) ) ) {
V_238 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_236 = V_9 ;
continue;
}
if ( ! V_235 && ! ( strcmp ( V_9 -> V_13 , V_138 ) ) ) {
V_237 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_235 = V_9 ;
}
}
if ( ! V_236 )
V_236 = V_238 ;
if ( ! V_235 )
V_235 = V_237 ;
if ( V_235 == NULL ) {
F_26 ( V_12 -> V_3 , L_72 ,
V_234 -> V_138 ) ;
return - V_103 ;
}
if ( V_236 == NULL ) {
F_26 ( V_12 -> V_3 , L_73 ,
V_234 -> V_136 ) ;
return - V_103 ;
}
V_93 = F_44 ( sizeof( struct V_48 ) , V_7 ) ;
if ( ! V_93 )
return - V_116 ;
V_93 -> V_138 = V_235 ;
V_93 -> V_136 = V_236 ;
V_93 -> V_132 = V_234 -> V_132 ;
F_93 ( & V_93 -> V_97 ) ;
F_93 ( & V_93 -> V_101 ) ;
F_93 ( & V_93 -> V_99 ) ;
if ( V_236 -> V_19 == V_20 ) {
if ( V_235 -> V_19 == V_76 ||
V_235 -> V_19 == V_85 ||
V_235 -> V_19 == V_87 ||
V_235 -> V_19 == V_21 )
V_236 -> V_133 = 1 ;
}
if ( V_235 -> V_19 == V_21 ) {
if ( V_236 -> V_19 == V_86 ||
V_236 -> V_19 == V_84 ||
V_236 -> V_19 == V_87 ||
V_236 -> V_19 == V_20 )
V_235 -> V_133 = 1 ;
}
if ( V_239 == NULL ) {
F_40 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_40 ( & V_93 -> V_99 , & V_236 -> V_100 ) ;
F_40 ( & V_93 -> V_101 , & V_235 -> V_102 ) ;
V_93 -> V_61 = 1 ;
return 0 ;
}
switch ( V_236 -> V_19 ) {
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
F_40 ( & V_93 -> V_99 , & V_236 -> V_100 ) ;
F_40 ( & V_93 -> V_101 , & V_235 -> V_102 ) ;
V_93 -> V_61 = 1 ;
return 0 ;
case V_62 :
case V_68 :
case V_69 :
V_39 = F_39 ( V_12 , V_235 , V_236 , V_93 , V_239 ,
& V_236 -> V_56 [ 0 ] ) ;
if ( V_39 != 0 )
goto V_137;
break;
case V_51 :
case V_52 :
case V_53 :
V_39 = F_41 ( V_12 , V_235 , V_236 , V_93 , V_239 ) ;
if ( V_39 != 0 )
goto V_137;
break;
case V_84 :
case V_85 :
case V_87 :
case V_86 :
F_40 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_40 ( & V_93 -> V_99 , & V_236 -> V_100 ) ;
F_40 ( & V_93 -> V_101 , & V_235 -> V_102 ) ;
V_93 -> V_61 = 0 ;
return 0 ;
}
F_10 ( V_235 , L_74 ) ;
F_10 ( V_236 , L_74 ) ;
return 0 ;
V_137:
F_67 ( V_12 -> V_3 , L_75 ,
V_138 , V_239 , V_136 ) ;
F_7 ( V_93 ) ;
return V_39 ;
}
static int F_139 ( struct V_16 * V_12 ,
const struct V_233 * V_234 )
{
struct V_48 * V_93 , * V_49 ;
const char * V_136 ;
const char * V_138 ;
char V_240 [ 80 ] ;
char V_241 [ 80 ] ;
if ( V_234 -> V_239 ) {
F_26 ( V_12 -> V_3 ,
L_76 ) ;
return - V_122 ;
}
if ( V_12 -> V_24 && V_12 -> V_24 -> V_115 ) {
snprintf ( V_240 , sizeof( V_240 ) , L_7 ,
V_12 -> V_24 -> V_115 , V_234 -> V_136 ) ;
V_136 = V_240 ;
snprintf ( V_241 , sizeof( V_241 ) , L_7 ,
V_12 -> V_24 -> V_115 , V_234 -> V_138 ) ;
V_138 = V_241 ;
} else {
V_136 = V_234 -> V_136 ;
V_138 = V_234 -> V_138 ;
}
V_93 = NULL ;
F_15 (p, &dapm->card->paths, list) {
if ( strcmp ( V_49 -> V_138 -> V_13 , V_138 ) != 0 )
continue;
if ( strcmp ( V_49 -> V_136 -> V_13 , V_136 ) != 0 )
continue;
V_93 = V_49 ;
break;
}
if ( V_93 ) {
F_10 ( V_93 -> V_138 , L_77 ) ;
F_10 ( V_93 -> V_136 , L_77 ) ;
F_134 ( & V_93 -> V_97 ) ;
F_134 ( & V_93 -> V_99 ) ;
F_134 ( & V_93 -> V_101 ) ;
F_7 ( V_93 ) ;
} else {
F_67 ( V_12 -> V_3 , L_78 ,
V_138 , V_136 ) ;
}
return 0 ;
}
int F_140 ( struct V_16 * V_12 ,
const struct V_233 * V_234 , int V_242 )
{
int V_50 , V_243 , V_39 = 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_244 ) ;
for ( V_50 = 0 ; V_50 < V_242 ; V_50 ++ ) {
V_243 = F_138 ( V_12 , V_234 ) ;
if ( V_243 < 0 ) {
F_26 ( V_12 -> V_3 , L_79 ,
V_234 -> V_138 ,
V_234 -> V_239 ? V_234 -> V_239 : L_80 ,
V_234 -> V_136 ) ;
V_39 = V_243 ;
}
V_234 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
int F_141 ( struct V_16 * V_12 ,
const struct V_233 * V_234 , int V_242 )
{
int V_50 , V_39 = 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_244 ) ;
for ( V_50 = 0 ; V_50 < V_242 ; V_50 ++ ) {
F_139 ( V_12 , V_234 ) ;
V_234 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
static int F_142 ( struct V_16 * V_12 ,
const struct V_233 * V_234 )
{
struct V_8 * V_138 = F_135 ( V_12 ,
V_234 -> V_138 ,
true ) ;
struct V_8 * V_136 = F_135 ( V_12 ,
V_234 -> V_136 ,
true ) ;
struct V_48 * V_93 ;
int V_208 = 0 ;
if ( ! V_138 ) {
F_26 ( V_12 -> V_3 , L_81 ,
V_234 -> V_138 ) ;
return - V_103 ;
}
if ( ! V_136 ) {
F_26 ( V_12 -> V_3 , L_82 ,
V_234 -> V_136 ) ;
return - V_103 ;
}
if ( V_234 -> V_239 || V_234 -> V_132 )
F_67 ( V_12 -> V_3 , L_83 ,
V_234 -> V_138 , V_234 -> V_136 ) ;
F_15 (path, &source->sinks, list_source) {
if ( V_93 -> V_136 == V_136 ) {
V_93 -> V_135 = 1 ;
V_208 ++ ;
}
}
if ( V_208 == 0 )
F_26 ( V_12 -> V_3 , L_84 ,
V_234 -> V_138 , V_234 -> V_136 ) ;
if ( V_208 > 1 )
F_67 ( V_12 -> V_3 , L_85 ,
V_208 , V_234 -> V_138 , V_234 -> V_136 ) ;
return 0 ;
}
int F_143 ( struct V_16 * V_12 ,
const struct V_233 * V_234 , int V_242 )
{
int V_50 , V_137 ;
int V_39 = 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_244 ) ;
for ( V_50 = 0 ; V_50 < V_242 ; V_50 ++ ) {
V_137 = F_142 ( V_12 , V_234 ) ;
if ( V_137 )
V_39 = V_137 ;
V_234 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
int F_144 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_31 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_244 ) ;
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
V_9 -> V_169 = 1 ;
}
V_9 -> V_38 = 1 ;
F_10 ( V_9 , L_86 ) ;
F_119 ( V_9 ) ;
}
F_105 ( V_12 , V_218 ) ;
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return 0 ;
}
int F_145 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
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
V_246 -> V_35 . integer . V_35 [ 0 ] =
( F_24 ( V_125 -> V_24 , V_30 ) >> V_58 ) & V_34 ;
if ( V_60 )
V_246 -> V_35 . integer . V_35 [ 0 ] =
V_59 - V_246 -> V_35 . integer . V_35 [ 0 ] ;
return 0 ;
}
int F_148 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_223 * V_24 = V_125 -> V_24 ;
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
struct V_187 V_188 ;
int V_247 ;
if ( F_147 ( V_55 ) )
F_67 ( V_125 -> V_12 -> V_3 ,
L_87 ,
V_96 -> V_19 . V_13 ) ;
V_31 = ( V_246 -> V_35 . integer . V_35 [ 0 ] & V_34 ) ;
V_61 = ! ! V_31 ;
if ( V_60 )
V_31 = V_59 - V_31 ;
V_34 = V_34 << V_58 ;
V_31 = V_31 << V_58 ;
F_61 ( & V_14 -> V_18 , V_142 ) ;
V_36 = F_149 ( V_125 -> V_24 , V_30 , V_34 , V_31 ) ;
if ( V_36 ) {
for ( V_247 = 0 ; V_247 < V_113 -> V_117 ; V_247 ++ ) {
V_125 = V_113 -> V_118 [ V_247 ] ;
V_125 -> V_35 = V_31 ;
V_188 . V_96 = V_96 ;
V_188 . V_125 = V_125 ;
V_188 . V_30 = V_30 ;
V_188 . V_34 = V_34 ;
V_188 . V_31 = V_31 ;
V_125 -> V_12 -> V_188 = & V_188 ;
F_125 ( V_125 , V_96 , V_61 ) ;
V_125 -> V_12 -> V_188 = NULL ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return 0 ;
}
int F_150 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_63 * V_64 = (struct V_63 * ) V_96 -> V_57 ;
unsigned int V_31 ;
V_31 = F_24 ( V_125 -> V_24 , V_64 -> V_30 ) ;
V_246 -> V_35 . V_248 . V_65 [ 0 ] = ( V_31 >> V_64 -> V_66 ) & V_64 -> V_34 ;
if ( V_64 -> V_66 != V_64 -> V_249 )
V_246 -> V_35 . V_248 . V_65 [ 1 ] =
( V_31 >> V_64 -> V_249 ) & V_64 -> V_34 ;
return 0 ;
}
int F_151 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_223 * V_24 = V_125 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_63 * V_64 = (struct V_63 * ) V_96 -> V_57 ;
unsigned int V_31 , V_216 , V_36 ;
unsigned int V_34 ;
struct V_187 V_188 ;
int V_247 ;
if ( V_246 -> V_35 . V_248 . V_65 [ 0 ] > V_64 -> V_59 - 1 )
return - V_122 ;
V_216 = V_246 -> V_35 . V_248 . V_65 [ 0 ] ;
V_31 = V_216 << V_64 -> V_66 ;
V_34 = V_64 -> V_34 << V_64 -> V_66 ;
if ( V_64 -> V_66 != V_64 -> V_249 ) {
if ( V_246 -> V_35 . V_248 . V_65 [ 1 ] > V_64 -> V_59 - 1 )
return - V_122 ;
V_31 |= V_246 -> V_35 . V_248 . V_65 [ 1 ] << V_64 -> V_249 ;
V_34 |= V_64 -> V_34 << V_64 -> V_249 ;
}
F_61 ( & V_14 -> V_18 , V_142 ) ;
V_36 = F_149 ( V_125 -> V_24 , V_64 -> V_30 , V_34 , V_31 ) ;
if ( V_36 ) {
for ( V_247 = 0 ; V_247 < V_113 -> V_117 ; V_247 ++ ) {
V_125 = V_113 -> V_118 [ V_247 ] ;
V_125 -> V_35 = V_31 ;
V_188 . V_96 = V_96 ;
V_188 . V_125 = V_125 ;
V_188 . V_30 = V_64 -> V_30 ;
V_188 . V_34 = V_34 ;
V_188 . V_31 = V_31 ;
V_125 -> V_12 -> V_188 = & V_188 ;
F_122 ( V_125 , V_96 , V_216 , V_64 ) ;
V_125 -> V_12 -> V_188 = NULL ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_36 ;
}
int F_152 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
V_246 -> V_35 . V_248 . V_65 [ 0 ] = V_125 -> V_35 ;
return 0 ;
}
int F_153 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_223 * V_24 = V_125 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_63 * V_64 =
(struct V_63 * ) V_96 -> V_57 ;
int V_36 ;
int V_39 = 0 ;
int V_247 ;
if ( V_246 -> V_35 . V_248 . V_65 [ 0 ] >= V_64 -> V_59 )
return - V_122 ;
F_61 ( & V_14 -> V_18 , V_142 ) ;
V_36 = V_125 -> V_35 != V_246 -> V_35 . V_248 . V_65 [ 0 ] ;
if ( V_36 ) {
for ( V_247 = 0 ; V_247 < V_113 -> V_117 ; V_247 ++ ) {
V_125 = V_113 -> V_118 [ V_247 ] ;
V_125 -> V_35 = V_246 -> V_35 . V_248 . V_65 [ 0 ] ;
F_122 ( V_125 , V_96 , V_125 -> V_35 , V_64 ) ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_39 ;
}
int F_154 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_63 * V_64 = (struct V_63 * ) V_96 -> V_57 ;
unsigned int V_250 , V_31 , V_216 ;
V_250 = F_24 ( V_125 -> V_24 , V_64 -> V_30 ) ;
V_31 = ( V_250 >> V_64 -> V_66 ) & V_64 -> V_34 ;
for ( V_216 = 0 ; V_216 < V_64 -> V_59 ; V_216 ++ ) {
if ( V_31 == V_64 -> V_70 [ V_216 ] )
break;
}
V_246 -> V_35 . V_248 . V_65 [ 0 ] = V_216 ;
if ( V_64 -> V_66 != V_64 -> V_249 ) {
V_31 = ( V_250 >> V_64 -> V_249 ) & V_64 -> V_34 ;
for ( V_216 = 0 ; V_216 < V_64 -> V_59 ; V_216 ++ ) {
if ( V_31 == V_64 -> V_70 [ V_216 ] )
break;
}
V_246 -> V_35 . V_248 . V_65 [ 1 ] = V_216 ;
}
return 0 ;
}
int F_155 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_146 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_223 * V_24 = V_125 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_63 * V_64 = (struct V_63 * ) V_96 -> V_57 ;
unsigned int V_31 , V_216 , V_36 ;
unsigned int V_34 ;
struct V_187 V_188 ;
int V_247 ;
if ( V_246 -> V_35 . V_248 . V_65 [ 0 ] > V_64 -> V_59 - 1 )
return - V_122 ;
V_216 = V_246 -> V_35 . V_248 . V_65 [ 0 ] ;
V_31 = V_64 -> V_70 [ V_246 -> V_35 . V_248 . V_65 [ 0 ] ] << V_64 -> V_66 ;
V_34 = V_64 -> V_34 << V_64 -> V_66 ;
if ( V_64 -> V_66 != V_64 -> V_249 ) {
if ( V_246 -> V_35 . V_248 . V_65 [ 1 ] > V_64 -> V_59 - 1 )
return - V_122 ;
V_31 |= V_64 -> V_70 [ V_246 -> V_35 . V_248 . V_65 [ 1 ] ] << V_64 -> V_249 ;
V_34 |= V_64 -> V_34 << V_64 -> V_249 ;
}
F_61 ( & V_14 -> V_18 , V_142 ) ;
V_36 = F_149 ( V_125 -> V_24 , V_64 -> V_30 , V_34 , V_31 ) ;
if ( V_36 ) {
for ( V_247 = 0 ; V_247 < V_113 -> V_117 ; V_247 ++ ) {
V_125 = V_113 -> V_118 [ V_247 ] ;
V_125 -> V_35 = V_31 ;
V_188 . V_96 = V_96 ;
V_188 . V_125 = V_125 ;
V_188 . V_30 = V_64 -> V_30 ;
V_188 . V_34 = V_34 ;
V_188 . V_31 = V_31 ;
V_125 -> V_12 -> V_188 = & V_188 ;
F_122 ( V_125 , V_96 , V_216 , V_64 ) ;
V_125 -> V_12 -> V_188 = NULL ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_36 ;
}
int F_156 ( struct V_107 * V_96 ,
struct V_251 * V_252 )
{
V_252 -> type = V_253 ;
V_252 -> V_208 = 1 ;
V_252 -> V_35 . integer . V_254 = 0 ;
V_252 -> V_35 . integer . V_59 = 1 ;
return 0 ;
}
int F_157 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_17 * V_14 = F_146 ( V_96 ) ;
const char * V_228 = ( const char * ) V_96 -> V_57 ;
F_61 ( & V_14 -> V_18 , V_142 ) ;
V_246 -> V_35 . integer . V_35 [ 0 ] =
F_158 ( & V_14 -> V_12 , V_228 ) ;
F_16 ( & V_14 -> V_18 ) ;
return 0 ;
}
int F_159 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_17 * V_14 = F_146 ( V_96 ) ;
const char * V_228 = ( const char * ) V_96 -> V_57 ;
F_61 ( & V_14 -> V_18 , V_142 ) ;
if ( V_246 -> V_35 . integer . V_35 [ 0 ] )
F_160 ( & V_14 -> V_12 , V_228 ) ;
else
F_161 ( & V_14 -> V_12 , V_228 ) ;
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
V_9 -> V_150 = F_163 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_164 ( V_9 -> V_150 ) ) {
V_39 = F_165 ( V_9 -> V_150 ) ;
F_26 ( V_12 -> V_3 , L_88 ,
V_9 -> V_13 , V_39 ) ;
return NULL ;
}
if ( V_9 -> V_60 & V_149 ) {
V_39 = F_66 ( V_9 -> V_150 , true ) ;
if ( V_39 != 0 )
F_67 ( V_9 -> V_12 -> V_3 ,
L_17 ,
V_9 -> V_13 , V_39 ) ;
}
break;
case V_80 :
#ifdef F_166
V_9 -> V_151 = F_167 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_164 ( V_9 -> V_151 ) ) {
V_39 = F_165 ( V_9 -> V_151 ) ;
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
V_9 -> V_155 = F_75 ;
break;
case V_62 :
case V_68 :
case V_69 :
V_9 -> V_155 = F_75 ;
break;
case V_73 :
case V_82 :
V_9 -> V_155 = F_77 ;
break;
case V_75 :
case V_81 :
V_9 -> V_155 = F_78 ;
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
V_9 -> V_155 = F_75 ;
break;
case V_78 :
case V_79 :
case V_80 :
V_9 -> V_155 = F_79 ;
break;
case V_83 :
V_9 -> V_155 = F_76 ;
break;
default:
V_9 -> V_155 = F_80 ;
break;
}
V_12 -> V_255 ++ ;
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
int V_242 )
{
struct V_8 * V_9 ;
int V_50 ;
int V_39 = 0 ;
F_61 ( & V_12 -> V_14 -> V_18 , V_244 ) ;
for ( V_50 = 0 ; V_50 < V_242 ; V_50 ++ ) {
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
struct V_107 * V_96 , int V_146 )
{
struct V_48 * V_256 , * V_257 ;
struct V_139 * V_138 , * V_136 ;
const struct V_258 * V_259 = V_9 -> V_260 ;
struct V_261 V_262 ;
struct V_263 * V_260 = NULL ;
T_8 V_4 ;
int V_39 ;
F_88 ( ! V_259 ) ;
F_88 ( F_9 ( & V_9 -> V_100 ) || F_9 ( & V_9 -> V_102 ) ) ;
V_256 = F_87 ( & V_9 -> V_100 , struct V_48 ,
V_99 ) ;
V_257 = F_87 ( & V_9 -> V_102 , struct V_48 ,
V_101 ) ;
F_88 ( ! V_256 || ! V_257 ) ;
F_88 ( ! V_257 -> V_138 || ! V_256 -> V_136 ) ;
F_88 ( ! V_256 -> V_138 || ! V_257 -> V_136 ) ;
V_138 = V_256 -> V_138 -> V_264 ;
V_136 = V_257 -> V_136 -> V_264 ;
if ( V_259 -> V_265 ) {
V_4 = F_170 ( V_259 -> V_265 ) - 1 ;
} else {
F_67 ( V_9 -> V_12 -> V_3 , L_90 ,
V_259 -> V_265 ) ;
V_4 = 0 ;
}
V_260 = F_44 ( sizeof( * V_260 ) , V_7 ) ;
if ( ! V_260 ) {
V_39 = - V_116 ;
goto V_44;
}
F_171 ( F_172 ( V_260 , V_266 ) , V_4 ) ;
F_173 ( V_260 , V_267 ) -> V_254 =
V_259 -> V_268 ;
F_173 ( V_260 , V_267 ) -> V_59 =
V_259 -> V_269 ;
F_173 ( V_260 , V_270 ) -> V_254
= V_259 -> V_271 ;
F_173 ( V_260 , V_270 ) -> V_59
= V_259 -> V_272 ;
memset ( & V_262 , 0 , sizeof( V_262 ) ) ;
switch ( V_146 ) {
case V_170 :
if ( V_138 -> V_45 -> V_273 && V_138 -> V_45 -> V_273 -> V_274 ) {
V_262 . V_141 = V_275 ;
V_39 = V_138 -> V_45 -> V_273 -> V_274 ( & V_262 ,
V_260 , V_138 ) ;
if ( V_39 != 0 ) {
F_26 ( V_138 -> V_3 ,
L_91 , V_39 ) ;
goto V_44;
}
}
if ( V_136 -> V_45 -> V_273 && V_136 -> V_45 -> V_273 -> V_274 ) {
V_262 . V_141 = V_143 ;
V_39 = V_136 -> V_45 -> V_273 -> V_274 ( & V_262 , V_260 ,
V_136 ) ;
if ( V_39 != 0 ) {
F_26 ( V_136 -> V_3 ,
L_91 , V_39 ) ;
goto V_44;
}
}
break;
case V_171 :
V_39 = F_174 ( V_136 , 0 ) ;
if ( V_39 != 0 && V_39 != - V_276 )
F_67 ( V_136 -> V_3 , L_92 , V_39 ) ;
V_39 = 0 ;
break;
case V_172 :
V_39 = F_174 ( V_136 , 1 ) ;
if ( V_39 != 0 && V_39 != - V_276 )
F_67 ( V_136 -> V_3 , L_93 , V_39 ) ;
V_39 = 0 ;
break;
default:
F_20 () ;
return - V_122 ;
}
V_44:
F_7 ( V_260 ) ;
return V_39 ;
}
int F_175 ( struct V_17 * V_14 ,
const struct V_258 * V_260 ,
struct V_8 * V_138 ,
struct V_8 * V_136 )
{
struct V_233 V_277 [ 2 ] ;
struct V_8 V_278 ;
struct V_8 * V_9 ;
T_3 V_279 ;
char * V_280 ;
V_279 = strlen ( V_138 -> V_13 ) + strlen ( V_136 -> V_13 ) + 2 ;
V_280 = F_176 ( V_14 -> V_3 , V_279 , V_7 ) ;
if ( ! V_280 )
return - V_116 ;
snprintf ( V_280 , V_279 , L_94 , V_138 -> V_13 , V_136 -> V_13 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_278 . V_30 = V_181 ;
V_278 . V_19 = V_88 ;
V_278 . V_13 = V_280 ;
V_278 . V_146 = F_169 ;
V_278 . V_174 = V_170 | V_171 |
V_172 ;
F_53 ( V_14 -> V_3 , L_95 , V_280 ) ;
V_9 = F_162 ( & V_14 -> V_12 , & V_278 ) ;
if ( ! V_9 ) {
F_26 ( V_14 -> V_3 , L_96 ,
V_280 ) ;
return - V_116 ;
}
V_9 -> V_260 = V_260 ;
memset ( & V_277 , 0 , sizeof( V_277 ) ) ;
V_277 [ 0 ] . V_138 = V_138 -> V_13 ;
V_277 [ 0 ] . V_136 = V_280 ;
V_277 [ 1 ] . V_138 = V_280 ;
V_277 [ 1 ] . V_136 = V_136 -> V_13 ;
return F_140 ( & V_14 -> V_12 , V_277 ,
F_92 ( V_277 ) ) ;
}
int F_177 ( struct V_16 * V_12 ,
struct V_139 * V_140 )
{
struct V_8 V_278 ;
struct V_8 * V_9 ;
F_178 ( V_12 -> V_3 != V_140 -> V_3 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_278 . V_30 = V_181 ;
if ( V_140 -> V_45 -> V_281 . V_282 ) {
V_278 . V_19 = V_83 ;
V_278 . V_13 = V_140 -> V_45 -> V_281 . V_282 ;
V_278 . V_210 = V_140 -> V_45 -> V_281 . V_282 ;
F_53 ( V_140 -> V_3 , L_95 ,
V_278 . V_13 ) ;
V_9 = F_162 ( V_12 , & V_278 ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_96 ,
V_140 -> V_45 -> V_281 . V_282 ) ;
}
V_9 -> V_264 = V_140 ;
V_140 -> V_144 = V_9 ;
}
if ( V_140 -> V_45 -> V_283 . V_282 ) {
V_278 . V_19 = V_83 ;
V_278 . V_13 = V_140 -> V_45 -> V_283 . V_282 ;
V_278 . V_210 = V_140 -> V_45 -> V_283 . V_282 ;
F_53 ( V_140 -> V_3 , L_95 ,
V_278 . V_13 ) ;
V_9 = F_162 ( V_12 , & V_278 ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_96 ,
V_140 -> V_45 -> V_283 . V_282 ) ;
}
V_9 -> V_264 = V_140 ;
V_140 -> V_145 = V_9 ;
}
return 0 ;
}
int F_179 ( struct V_17 * V_14 )
{
struct V_8 * V_284 , * V_9 ;
struct V_139 * V_140 ;
struct V_233 V_243 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
F_15 (dai_w, &card->widgets, list) {
if ( V_284 -> V_19 != V_83 )
continue;
V_140 = V_284 -> V_264 ;
F_15 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_284 -> V_12 )
continue;
if ( V_9 -> V_19 == V_83 )
continue;
if ( ! V_9 -> V_210 )
continue;
if ( V_140 -> V_45 -> V_281 . V_282 &&
strstr ( V_9 -> V_210 ,
V_140 -> V_45 -> V_281 . V_282 ) ) {
V_243 . V_138 = V_140 -> V_144 -> V_13 ;
V_243 . V_136 = V_9 -> V_13 ;
F_53 ( V_140 -> V_3 , L_97 ,
V_243 . V_138 , V_243 . V_136 ) ;
F_138 ( V_9 -> V_12 , & V_243 ) ;
}
if ( V_140 -> V_45 -> V_283 . V_282 &&
strstr ( V_9 -> V_210 ,
V_140 -> V_45 -> V_283 . V_282 ) ) {
V_243 . V_138 = V_9 -> V_13 ;
V_243 . V_136 = V_140 -> V_145 -> V_13 ;
F_53 ( V_140 -> V_3 , L_97 ,
V_243 . V_138 , V_243 . V_136 ) ;
F_138 ( V_9 -> V_12 , & V_243 ) ;
}
}
}
return 0 ;
}
static void F_180 ( struct V_221 * V_222 , int V_141 ,
int V_146 )
{
struct V_8 * V_285 , * V_286 ;
struct V_139 * V_287 = V_222 -> V_287 ;
struct V_139 * V_288 = V_222 -> V_288 ;
if ( V_141 == V_143 ) {
V_285 = V_287 -> V_144 ;
V_286 = V_288 -> V_144 ;
} else {
V_285 = V_287 -> V_145 ;
V_286 = V_288 -> V_145 ;
}
if ( V_285 ) {
F_10 ( V_285 , L_98 ) ;
switch ( V_146 ) {
case V_185 :
V_285 -> V_131 = 1 ;
break;
case V_186 :
V_285 -> V_131 = 0 ;
break;
case V_289 :
case V_290 :
case V_291 :
case V_292 :
break;
}
}
if ( V_286 ) {
F_10 ( V_286 , L_98 ) ;
switch ( V_146 ) {
case V_185 :
V_286 -> V_131 = 1 ;
break;
case V_186 :
V_286 -> V_131 = 0 ;
break;
case V_289 :
case V_290 :
case V_291 :
case V_292 :
break;
}
}
F_105 ( & V_222 -> V_14 -> V_12 , V_146 ) ;
}
void F_181 ( struct V_221 * V_222 , int V_141 ,
int V_146 )
{
struct V_17 * V_14 = V_222 -> V_14 ;
F_61 ( & V_14 -> V_18 , V_142 ) ;
F_180 ( V_222 , V_141 , V_146 ) ;
F_16 ( & V_14 -> V_18 ) ;
}
int F_160 ( struct V_16 * V_12 , const char * V_228 )
{
return F_136 ( V_12 , V_228 , 1 ) ;
}
int F_182 ( struct V_16 * V_12 ,
const char * V_228 )
{
struct V_8 * V_9 = F_135 ( V_12 , V_228 , true ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_99 , V_228 ) ;
return - V_122 ;
}
F_53 ( V_9 -> V_12 -> V_3 , L_100 , V_228 ) ;
V_9 -> V_132 = 1 ;
V_9 -> V_154 = 1 ;
F_10 ( V_9 , L_101 ) ;
return 0 ;
}
int F_161 ( struct V_16 * V_12 ,
const char * V_228 )
{
return F_136 ( V_12 , V_228 , 0 ) ;
}
int F_183 ( struct V_16 * V_12 , const char * V_228 )
{
return F_136 ( V_12 , V_228 , 0 ) ;
}
int F_158 ( struct V_16 * V_12 ,
const char * V_228 )
{
struct V_8 * V_9 = F_135 ( V_12 , V_228 , true ) ;
if ( V_9 )
return V_9 -> V_132 ;
return 0 ;
}
int F_184 ( struct V_16 * V_12 ,
const char * V_228 )
{
struct V_8 * V_9 = F_135 ( V_12 , V_228 , false ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_99 , V_228 ) ;
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
if ( ( V_49 -> V_138 == V_9 ) || ( V_49 -> V_136 == V_9 ) ) {
F_53 ( V_14 -> V_3 ,
L_102 ,
V_49 -> V_138 -> V_13 , V_49 -> V_138 -> V_19 , V_49 -> V_138 -> V_12 ,
V_49 -> V_136 -> V_13 , V_49 -> V_136 -> V_19 , V_49 -> V_136 -> V_12 ) ;
if ( V_49 -> V_138 -> V_12 != V_49 -> V_136 -> V_12 )
return true ;
if ( V_49 -> V_136 -> V_19 == V_20 ) {
switch ( V_49 -> V_138 -> V_19 ) {
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
void F_186 ( struct V_223 * V_24 )
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
F_90 ( V_201 ) ;
int V_293 = 0 ;
F_14 ( & V_14 -> V_18 ) ;
F_15 (w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
if ( V_9 -> V_169 ) {
F_82 ( V_9 , & V_201 , false ) ;
V_9 -> V_169 = 0 ;
V_293 = 1 ;
}
}
if ( V_293 ) {
if ( V_12 -> V_46 == V_198 )
F_34 ( V_12 ,
V_197 ) ;
F_89 ( V_12 , & V_201 , 0 , false ) ;
if ( V_12 -> V_46 == V_197 )
F_34 ( V_12 ,
V_196 ) ;
}
F_16 ( & V_14 -> V_18 ) ;
}
void F_189 ( struct V_17 * V_14 )
{
struct V_223 * V_24 ;
F_15 (codec, &card->codec_dev_list, card_list) {
F_188 ( & V_24 -> V_12 ) ;
if ( V_24 -> V_12 . V_46 == V_196 )
F_34 ( & V_24 -> V_12 ,
V_194 ) ;
}
}
