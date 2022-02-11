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
} else if ( ! V_14 || V_12 != & V_14 -> V_12 ) {
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
if ( V_57 )
V_27 = V_56 - V_27 ;
V_45 -> V_58 = ! ! V_27 ;
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
case V_88 :
V_45 -> V_58 = 1 ;
break;
case V_89 :
case V_90 :
V_45 -> V_58 = 0 ;
break;
}
}
static int F_38 ( struct V_18 * V_12 ,
struct V_8 * V_91 , struct V_8 * V_92 ,
struct V_44 * V_93 , const char * V_94 ,
const struct V_95 * V_96 )
{
struct V_60 * V_61 = (struct V_60 * ) V_96 -> V_54 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_61 -> V_56 ; V_46 ++ ) {
if ( ! ( strcmp ( V_94 , V_61 -> V_65 [ V_46 ] ) ) ) {
F_39 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_39 ( & V_93 -> V_99 , & V_92 -> V_100 ) ;
F_39 ( & V_93 -> V_101 , & V_91 -> V_102 ) ;
V_93 -> V_13 = ( char * ) V_61 -> V_65 [ V_46 ] ;
F_36 ( V_92 , V_93 , 0 ) ;
return 0 ;
}
}
return - V_103 ;
}
static int F_40 ( struct V_18 * V_12 ,
struct V_8 * V_91 , struct V_8 * V_92 ,
struct V_44 * V_93 , const char * V_94 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_92 -> V_104 ; V_46 ++ ) {
if ( ! strcmp ( V_94 , V_92 -> V_53 [ V_46 ] . V_13 ) ) {
F_39 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_39 ( & V_93 -> V_99 , & V_92 -> V_100 ) ;
F_39 ( & V_93 -> V_101 , & V_91 -> V_102 ) ;
V_93 -> V_13 = V_92 -> V_53 [ V_46 ] . V_13 ;
F_36 ( V_92 , V_93 , V_46 ) ;
return 0 ;
}
}
return - V_103 ;
}
static int F_41 ( struct V_18 * V_12 ,
struct V_8 * V_105 ,
const struct V_95 * V_106 ,
struct V_107 * * V_96 )
{
struct V_8 * V_9 ;
int V_46 ;
* V_96 = NULL ;
F_19 (w, &dapm->card->widgets, list) {
if ( V_9 == V_105 || V_9 -> V_12 != V_105 -> V_12 )
continue;
for ( V_46 = 0 ; V_46 < V_9 -> V_104 ; V_46 ++ ) {
if ( & V_9 -> V_53 [ V_46 ] == V_106 ) {
if ( V_9 -> V_108 )
* V_96 = V_9 -> V_108 [ V_46 ] ;
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
T_3 V_109 , V_110 ;
struct V_44 * V_93 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_111 ;
struct V_112 * V_113 ;
T_3 V_114 ;
if ( V_12 -> V_19 )
V_111 = V_12 -> V_19 -> V_115 ;
else
V_111 = NULL ;
if ( V_111 )
V_110 = strlen ( V_111 ) + 1 ;
else
V_110 = 0 ;
for ( V_46 = 0 ; V_46 < V_9 -> V_104 ; V_46 ++ ) {
F_19 (path, &w->sources, list_sink) {
if ( V_93 -> V_13 != ( char * ) V_9 -> V_53 [ V_46 ] . V_13 )
continue;
if ( V_9 -> V_108 [ V_46 ] ) {
V_93 -> V_96 = V_9 -> V_108 [ V_46 ] ;
continue;
}
V_114 = sizeof( struct V_112 ) +
sizeof( struct V_8 * ) ,
V_113 = F_43 ( V_114 , V_7 ) ;
if ( V_113 == NULL ) {
F_23 ( V_12 -> V_3 ,
L_5 ,
V_9 -> V_13 ) ;
return - V_116 ;
}
V_113 -> V_117 = 1 ;
V_113 -> V_118 [ 0 ] = V_9 ;
V_109 = strlen ( V_9 -> V_53 [ V_46 ] . V_13 ) + 1 ;
if ( V_9 -> V_47 != V_50 )
V_109 += 1 + strlen ( V_9 -> V_13 ) ;
V_93 -> V_119 = F_5 ( V_109 , V_7 ) ;
if ( V_93 -> V_119 == NULL ) {
F_7 ( V_113 ) ;
return - V_116 ;
}
switch ( V_9 -> V_47 ) {
default:
snprintf ( ( char * ) V_93 -> V_119 , V_109 ,
L_6 , V_9 -> V_13 + V_110 ,
V_9 -> V_53 [ V_46 ] . V_13 ) ;
break;
case V_50 :
snprintf ( ( char * ) V_93 -> V_119 , V_109 ,
L_1 , V_9 -> V_53 [ V_46 ] . V_13 ) ;
break;
}
( ( char * ) V_93 -> V_119 ) [ V_109 - 1 ] = '\0' ;
V_93 -> V_96 = F_44 ( & V_9 -> V_53 [ V_46 ] ,
V_113 , V_93 -> V_119 ,
V_111 ) ;
V_35 = F_45 ( V_14 , V_93 -> V_96 ) ;
if ( V_35 < 0 ) {
F_23 ( V_12 -> V_3 ,
L_7 ,
V_93 -> V_119 , V_35 ) ;
F_7 ( V_113 ) ;
F_7 ( V_93 -> V_119 ) ;
V_93 -> V_119 = NULL ;
return V_35 ;
}
V_9 -> V_108 [ V_46 ] = V_93 -> V_96 ;
}
}
return V_35 ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_44 * V_93 = NULL ;
struct V_107 * V_96 ;
struct V_17 * V_14 = V_12 -> V_14 -> V_17 ;
const char * V_111 ;
T_3 V_110 ;
int V_35 ;
struct V_112 * V_113 ;
int V_120 , V_121 ;
T_3 V_114 ;
const char * V_13 ;
if ( V_9 -> V_104 != 1 ) {
F_23 ( V_12 -> V_3 ,
L_8 ,
V_9 -> V_13 ) ;
return - V_122 ;
}
V_120 = F_41 ( V_12 , V_9 , & V_9 -> V_53 [ 0 ] ,
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
V_113 = F_47 ( V_113 , V_114 , V_7 ) ;
if ( V_113 == NULL ) {
F_23 ( V_12 -> V_3 ,
L_5 , V_9 -> V_13 ) ;
return - V_116 ;
}
V_113 -> V_117 = V_121 ;
V_113 -> V_118 [ V_121 - 1 ] = V_9 ;
if ( ! V_96 ) {
if ( V_12 -> V_19 )
V_111 = V_12 -> V_19 -> V_115 ;
else
V_111 = NULL ;
if ( V_120 ) {
V_13 = V_9 -> V_53 [ 0 ] . V_13 ;
V_110 = 0 ;
} else {
V_13 = V_9 -> V_13 ;
if ( V_111 )
V_110 = strlen ( V_111 ) + 1 ;
else
V_110 = 0 ;
}
V_96 = F_44 ( & V_9 -> V_53 [ 0 ] , V_113 ,
V_13 + V_110 , V_111 ) ;
V_35 = F_45 ( V_14 , V_96 ) ;
if ( V_35 < 0 ) {
F_23 ( V_12 -> V_3 , L_9 ,
V_9 -> V_13 , V_35 ) ;
F_7 ( V_113 ) ;
return V_35 ;
}
}
V_96 -> V_123 = V_113 ;
V_9 -> V_108 [ 0 ] = V_96 ;
F_19 (path, &w->sources, list_sink)
V_93 -> V_96 = V_96 ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 )
{
if ( V_9 -> V_104 )
F_23 ( V_9 -> V_12 -> V_3 ,
L_10 , V_9 -> V_13 ) ;
return 0 ;
}
static inline void F_49 ( struct V_18 * V_12 )
{
struct V_44 * V_45 ;
F_19 (p, &dapm->card->paths, list)
V_45 -> V_124 = 0 ;
}
static int F_50 ( struct V_8 * V_125 )
{
int V_38 = F_51 ( V_125 -> V_12 -> V_14 -> V_17 ) ;
switch ( V_38 ) {
case V_126 :
case V_127 :
if ( V_125 -> V_128 )
F_52 ( V_125 -> V_12 -> V_3 , L_11 ,
V_125 -> V_13 ) ;
return V_125 -> V_128 ;
default:
return 1 ;
}
}
static int F_53 ( struct V_112 * * V_97 ,
struct V_8 * V_9 )
{
struct V_112 * V_113 ;
int V_114 , V_121 , V_46 ;
if ( * V_97 == NULL )
return - V_122 ;
V_113 = * V_97 ;
for ( V_46 = 0 ; V_46 < V_113 -> V_117 ; V_46 ++ ) {
if ( V_113 -> V_118 [ V_46 ] == V_9 )
return 0 ;
}
V_121 = V_113 -> V_117 + 1 ;
V_114 = sizeof( struct V_112 ) +
V_121 * sizeof( struct V_8 * ) ;
* V_97 = F_47 ( V_113 , V_114 , V_7 ) ;
if ( * V_97 == NULL ) {
F_23 ( V_9 -> V_12 -> V_3 , L_12 ,
V_9 -> V_13 ) ;
return - V_116 ;
}
V_113 = * V_97 ;
F_52 ( V_9 -> V_12 -> V_3 , L_13 ,
V_9 -> V_13 , V_113 -> V_117 ) ;
V_113 -> V_118 [ V_113 -> V_117 ] = V_9 ;
V_113 -> V_117 ++ ;
return 1 ;
}
static int F_54 ( struct V_8 * V_125 ,
struct V_112 * * V_97 )
{
struct V_44 * V_93 ;
int V_129 = 0 ;
if ( V_125 -> V_25 >= 0 )
return V_125 -> V_25 ;
F_55 ( V_125 , V_130 ) ;
switch ( V_125 -> V_47 ) {
case V_78 :
case V_79 :
case V_80 :
return 0 ;
default:
break;
}
switch ( V_125 -> V_47 ) {
case V_72 :
case V_82 :
case V_83 :
if ( V_125 -> V_131 ) {
V_125 -> V_25 = F_50 ( V_125 ) ;
return V_125 -> V_25 ;
}
default:
break;
}
if ( V_125 -> V_132 ) {
if ( V_125 -> V_47 == V_71 && ! V_125 -> V_133 ) {
V_125 -> V_25 = F_50 ( V_125 ) ;
return V_125 -> V_25 ;
}
if ( V_125 -> V_47 == V_84 ||
V_125 -> V_47 == V_86 ||
( V_125 -> V_47 == V_87 &&
! F_9 ( & V_125 -> V_100 ) ) ) {
V_125 -> V_25 = F_50 ( V_125 ) ;
return V_125 -> V_25 ;
}
}
F_19 (path, &widget->sinks, list_source) {
F_55 ( V_125 , V_134 ) ;
if ( V_93 -> V_135 )
continue;
if ( V_93 -> V_124 )
continue;
F_56 ( V_125 , V_93 ) ;
if ( V_93 -> V_136 && V_93 -> V_58 ) {
V_93 -> V_124 = 1 ;
if ( V_97 ) {
int V_137 ;
V_137 = F_53 ( V_97 , V_93 -> V_136 ) ;
if ( V_137 < 0 ) {
F_23 ( V_125 -> V_12 -> V_3 , L_14 ,
V_125 -> V_13 ) ;
return V_129 ;
}
}
V_129 += F_54 ( V_93 -> V_136 , V_97 ) ;
}
}
V_125 -> V_25 = V_129 ;
return V_129 ;
}
static int F_57 ( struct V_8 * V_125 ,
struct V_112 * * V_97 )
{
struct V_44 * V_93 ;
int V_129 = 0 ;
if ( V_125 -> V_24 >= 0 )
return V_125 -> V_24 ;
F_55 ( V_125 , V_130 ) ;
switch ( V_125 -> V_47 ) {
case V_78 :
case V_79 :
case V_80 :
return 0 ;
default:
break;
}
switch ( V_125 -> V_47 ) {
case V_75 :
case V_81 :
case V_83 :
if ( V_125 -> V_131 ) {
V_125 -> V_24 = F_50 ( V_125 ) ;
return V_125 -> V_24 ;
}
default:
break;
}
if ( V_125 -> V_132 ) {
if ( V_125 -> V_47 == V_73 && ! V_125 -> V_133 ) {
V_125 -> V_24 = F_50 ( V_125 ) ;
return V_125 -> V_24 ;
}
if ( V_125 -> V_47 == V_77 ) {
V_125 -> V_24 = F_50 ( V_125 ) ;
return V_125 -> V_24 ;
}
if ( V_125 -> V_47 == V_85 ||
( V_125 -> V_47 == V_87 &&
! F_9 ( & V_125 -> V_102 ) ) ) {
V_125 -> V_24 = F_50 ( V_125 ) ;
return V_125 -> V_24 ;
}
if ( V_125 -> V_47 == V_74 ) {
V_125 -> V_24 = F_50 ( V_125 ) ;
return V_125 -> V_24 ;
}
}
F_19 (path, &widget->sources, list_sink) {
F_55 ( V_125 , V_134 ) ;
if ( V_93 -> V_135 )
continue;
if ( V_93 -> V_124 )
continue;
F_58 ( V_125 , V_93 ) ;
if ( V_93 -> V_138 && V_93 -> V_58 ) {
V_93 -> V_124 = 1 ;
if ( V_97 ) {
int V_137 ;
V_137 = F_53 ( V_97 , V_93 -> V_138 ) ;
if ( V_137 < 0 ) {
F_23 ( V_125 -> V_12 -> V_3 , L_14 ,
V_125 -> V_13 ) ;
return V_129 ;
}
}
V_129 += F_57 ( V_93 -> V_138 , V_97 ) ;
}
}
V_125 -> V_24 = V_129 ;
return V_129 ;
}
int F_59 ( struct V_139 * V_140 , int V_141 ,
struct V_112 * * V_97 )
{
struct V_21 * V_14 = V_140 -> V_14 ;
int V_98 ;
F_60 ( & V_14 -> V_142 , V_143 ) ;
F_18 ( V_14 ) ;
if ( V_141 == V_144 )
V_98 = F_54 ( V_140 -> V_145 , V_97 ) ;
else
V_98 = F_57 ( V_140 -> V_146 , V_97 ) ;
F_61 ( V_98 , V_141 ) ;
F_49 ( & V_14 -> V_12 ) ;
F_30 ( & V_14 -> V_142 ) ;
return V_98 ;
}
int F_62 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_147 )
{
unsigned int V_27 ;
if ( F_63 ( V_147 ) )
V_27 = V_9 -> V_148 ;
else
V_27 = V_9 -> V_149 ;
F_31 ( V_9 , - ( V_9 -> V_26 + 1 ) ,
V_9 -> V_30 << V_9 -> V_55 , V_27 << V_9 -> V_55 ) ;
return 0 ;
}
int F_64 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_147 )
{
if ( F_63 ( V_147 ) )
return F_65 ( V_9 -> V_150 ) ;
else
return F_66 ( V_9 -> V_150 , V_9 -> V_55 ) ;
}
int F_67 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_147 )
{
if ( ! V_9 -> V_151 )
return - V_152 ;
#ifdef F_68
if ( F_63 ( V_147 ) ) {
return F_69 ( V_9 -> V_151 ) ;
} else {
F_70 ( V_9 -> V_151 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_71 ( struct V_8 * V_9 )
{
if ( V_9 -> V_23 )
return V_9 -> V_153 ;
if ( V_9 -> V_154 )
V_9 -> V_153 = 1 ;
else
V_9 -> V_153 = V_9 -> V_155 ( V_9 ) ;
V_9 -> V_23 = true ;
return V_9 -> V_153 ;
}
static int F_72 ( struct V_8 * V_9 )
{
int V_156 , V_40 ;
F_55 ( V_9 , V_157 ) ;
V_156 = F_57 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
V_40 = F_54 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
return V_40 != 0 && V_156 != 0 ;
}
static int F_73 ( struct V_8 * V_9 )
{
F_55 ( V_9 , V_157 ) ;
if ( V_9 -> V_131 )
return V_9 -> V_131 ;
return F_72 ( V_9 ) ;
}
static int F_74 ( struct V_8 * V_9 )
{
int V_156 ;
F_55 ( V_9 , V_157 ) ;
if ( V_9 -> V_131 ) {
V_156 = F_57 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
return V_156 != 0 ;
} else {
return F_72 ( V_9 ) ;
}
}
static int F_75 ( struct V_8 * V_9 )
{
int V_40 ;
F_55 ( V_9 , V_157 ) ;
if ( V_9 -> V_131 ) {
V_40 = F_54 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
return V_40 != 0 ;
} else {
return F_72 ( V_9 ) ;
}
}
static int F_76 ( struct V_8 * V_9 )
{
struct V_44 * V_93 ;
F_55 ( V_9 , V_157 ) ;
F_19 (path, &w->sinks, list_source) {
F_55 ( V_9 , V_134 ) ;
if ( V_93 -> V_135 )
continue;
if ( V_93 -> V_132 &&
! V_93 -> V_132 ( V_93 -> V_138 , V_93 -> V_136 ) )
continue;
if ( ! V_93 -> V_136 )
continue;
if ( F_71 ( V_93 -> V_136 ) )
return 1 ;
}
F_49 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_77 ( struct V_8 * V_9 )
{
return 1 ;
}
static int F_78 ( struct V_8 * V_158 ,
struct V_8 * V_159 ,
bool V_160 )
{
int * V_161 ;
if ( V_160 )
V_161 = V_162 ;
else
V_161 = V_163 ;
if ( V_161 [ V_158 -> V_47 ] != V_161 [ V_159 -> V_47 ] )
return V_161 [ V_158 -> V_47 ] - V_161 [ V_159 -> V_47 ] ;
if ( V_158 -> V_164 != V_159 -> V_164 ) {
if ( V_160 )
return V_158 -> V_164 - V_159 -> V_164 ;
else
return V_159 -> V_164 - V_158 -> V_164 ;
}
if ( V_158 -> V_26 != V_159 -> V_26 )
return V_158 -> V_26 - V_159 -> V_26 ;
if ( V_158 -> V_12 != V_159 -> V_12 )
return ( unsigned long ) V_158 -> V_12 - ( unsigned long ) V_159 -> V_12 ;
return 0 ;
}
static void F_79 ( struct V_8 * V_165 ,
struct V_166 * V_97 ,
bool V_160 )
{
struct V_8 * V_9 ;
F_19 (w, list, power_list)
if ( F_78 ( V_165 , V_9 , V_160 ) < 0 ) {
F_12 ( & V_165 -> V_167 , & V_9 -> V_167 ) ;
return;
}
F_12 ( & V_165 -> V_167 , V_97 ) ;
}
static void F_80 ( struct V_18 * V_12 ,
struct V_8 * V_9 , int V_147 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
const char * V_168 ;
int V_169 , V_35 ;
switch ( V_147 ) {
case V_170 :
V_168 = L_15 ;
V_169 = 1 ;
break;
case V_171 :
V_168 = L_16 ;
V_169 = 1 ;
break;
case V_172 :
V_168 = L_17 ;
V_169 = 0 ;
break;
case V_173 :
V_168 = L_18 ;
V_169 = 0 ;
break;
default:
F_16 () ;
return;
}
if ( V_9 -> V_169 != V_169 )
return;
if ( V_9 -> V_147 && ( V_9 -> V_174 & V_147 ) ) {
F_4 ( V_12 -> V_3 , V_14 -> V_1 , L_19 ,
V_9 -> V_13 , V_168 ) ;
F_81 ( V_9 , V_147 ) ;
V_35 = V_9 -> V_147 ( V_9 , NULL , V_147 ) ;
F_82 ( V_9 , V_147 ) ;
if ( V_35 < 0 )
F_83 ( L_20 ,
V_168 , V_9 -> V_13 , V_35 ) ;
}
}
static void F_84 ( struct V_18 * V_12 ,
struct V_166 * V_175 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
int V_26 , V_169 ;
unsigned int V_31 = 0 ;
unsigned int V_30 = 0 ;
unsigned int V_176 ;
V_26 = F_85 ( V_175 , struct V_8 ,
V_167 ) -> V_26 ;
F_19 (w, pending, power_list) {
V_176 = 1 << V_9 -> V_55 ;
F_86 ( V_26 != V_9 -> V_26 ) ;
if ( V_9 -> V_57 )
V_169 = ! V_9 -> V_169 ;
else
V_169 = V_9 -> V_169 ;
V_30 |= V_176 ;
if ( V_169 )
V_31 |= V_176 ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_21 ,
V_9 -> V_13 , V_26 , V_31 , V_30 ) ;
F_80 ( V_12 , V_9 , V_170 ) ;
F_80 ( V_12 , V_9 , V_172 ) ;
}
if ( V_26 >= 0 ) {
V_9 = F_85 ( V_175 , struct V_8 ,
V_167 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_22 ,
V_31 , V_30 , V_26 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_31 ( V_9 , V_26 , V_30 , V_31 ) ;
}
F_19 (w, pending, power_list) {
F_80 ( V_12 , V_9 , V_171 ) ;
F_80 ( V_12 , V_9 , V_173 ) ;
}
}
static void F_87 ( struct V_18 * V_12 ,
struct V_166 * V_97 , int V_147 , bool V_160 )
{
struct V_8 * V_9 , * V_177 ;
F_88 ( V_175 ) ;
int V_178 = - 1 ;
int V_179 = - 1 ;
int V_180 = V_181 ;
struct V_18 * V_182 = NULL ;
int V_35 , V_46 ;
int * V_161 ;
if ( V_160 )
V_161 = V_162 ;
else
V_161 = V_163 ;
F_89 (w, n, list, power_list) {
V_35 = 0 ;
if ( V_161 [ V_9 -> V_47 ] != V_178 || V_9 -> V_26 != V_180 ||
V_9 -> V_12 != V_182 || V_9 -> V_164 != V_179 ) {
if ( ! F_9 ( & V_175 ) )
F_84 ( V_182 , & V_175 ) ;
if ( V_182 && V_182 -> V_183 ) {
for ( V_46 = 0 ; V_46 < F_90 ( V_162 ) ; V_46 ++ )
if ( V_161 [ V_46 ] == V_178 )
V_182 -> V_183 ( V_182 ,
V_46 ,
V_179 ) ;
}
F_91 ( & V_175 ) ;
V_178 = - 1 ;
V_179 = V_184 ;
V_180 = V_181 ;
V_182 = NULL ;
}
switch ( V_9 -> V_47 ) {
case V_89 :
if ( ! V_9 -> V_147 )
F_92 ( V_9 , V_177 , V_97 ,
V_167 ) ;
if ( V_147 == V_185 )
V_35 = V_9 -> V_147 ( V_9 ,
NULL , V_170 ) ;
else if ( V_147 == V_186 )
V_35 = V_9 -> V_147 ( V_9 ,
NULL , V_172 ) ;
break;
case V_90 :
if ( ! V_9 -> V_147 )
F_92 ( V_9 , V_177 , V_97 ,
V_167 ) ;
if ( V_147 == V_185 )
V_35 = V_9 -> V_147 ( V_9 ,
NULL , V_171 ) ;
else if ( V_147 == V_186 )
V_35 = V_9 -> V_147 ( V_9 ,
NULL , V_173 ) ;
break;
default:
V_178 = V_161 [ V_9 -> V_47 ] ;
V_179 = V_9 -> V_164 ;
V_180 = V_9 -> V_26 ;
V_182 = V_9 -> V_12 ;
F_93 ( & V_9 -> V_167 , & V_175 ) ;
break;
}
if ( V_35 < 0 )
F_23 ( V_9 -> V_12 -> V_3 ,
L_23 , V_35 ) ;
}
if ( ! F_9 ( & V_175 ) )
F_84 ( V_182 , & V_175 ) ;
if ( V_182 && V_182 -> V_183 ) {
for ( V_46 = 0 ; V_46 < F_90 ( V_162 ) ; V_46 ++ )
if ( V_161 [ V_46 ] == V_178 )
V_182 -> V_183 ( V_182 ,
V_46 , V_179 ) ;
}
}
static void F_94 ( struct V_18 * V_12 )
{
struct V_187 * V_188 = V_12 -> V_188 ;
struct V_8 * V_9 ;
int V_35 ;
if ( ! V_188 )
return;
V_9 = V_188 -> V_125 ;
if ( V_9 -> V_147 &&
( V_9 -> V_174 & V_189 ) ) {
V_35 = V_9 -> V_147 ( V_9 , V_188 -> V_96 , V_189 ) ;
if ( V_35 != 0 )
F_83 ( L_24 ,
V_9 -> V_13 , V_35 ) ;
}
V_35 = F_31 ( V_9 , V_188 -> V_26 , V_188 -> V_30 ,
V_188 -> V_27 ) ;
if ( V_35 < 0 )
F_83 ( L_25 , V_9 -> V_13 , V_35 ) ;
if ( V_9 -> V_147 &&
( V_9 -> V_174 & V_190 ) ) {
V_35 = V_9 -> V_147 ( V_9 , V_188 -> V_96 , V_190 ) ;
if ( V_35 != 0 )
F_83 ( L_26 ,
V_9 -> V_13 , V_35 ) ;
}
}
static void F_95 ( void * V_191 , T_4 V_192 )
{
struct V_18 * V_193 = V_191 ;
int V_35 ;
if ( V_193 -> V_42 == V_194 &&
V_193 -> V_195 != V_194 ) {
if ( V_193 -> V_3 )
F_96 ( V_193 -> V_3 ) ;
V_35 = F_33 ( V_193 , V_196 ) ;
if ( V_35 != 0 )
F_23 ( V_193 -> V_3 ,
L_27 , V_35 ) ;
}
if ( V_193 -> V_42 != V_193 -> V_195 ) {
V_35 = F_33 ( V_193 , V_197 ) ;
if ( V_35 != 0 )
F_23 ( V_193 -> V_3 ,
L_28 , V_35 ) ;
}
}
static void F_97 ( void * V_191 , T_4 V_192 )
{
struct V_18 * V_193 = V_191 ;
int V_35 ;
if ( V_193 -> V_42 == V_197 &&
( V_193 -> V_195 == V_196 ||
V_193 -> V_195 == V_194 ) ) {
V_35 = F_33 ( V_193 , V_196 ) ;
if ( V_35 != 0 )
F_23 ( V_193 -> V_3 , L_29 ,
V_35 ) ;
}
if ( V_193 -> V_42 == V_196 &&
V_193 -> V_195 == V_194 ) {
V_35 = F_33 ( V_193 , V_194 ) ;
if ( V_35 != 0 )
F_23 ( V_193 -> V_3 , L_30 , V_35 ) ;
if ( V_193 -> V_3 )
F_98 ( V_193 -> V_3 ) ;
}
if ( V_193 -> V_42 == V_197 &&
V_193 -> V_195 == V_198 ) {
V_35 = F_33 ( V_193 , V_198 ) ;
if ( V_35 != 0 )
F_23 ( V_193 -> V_3 , L_31 ,
V_35 ) ;
}
}
static void F_99 ( struct V_8 * V_199 ,
bool V_169 , bool V_58 )
{
if ( ! V_58 )
return;
if ( V_169 != V_199 -> V_169 )
F_10 ( V_199 , L_32 ) ;
}
static void F_100 ( struct V_8 * V_9 , bool V_169 ,
struct V_166 * V_200 ,
struct V_166 * V_201 )
{
struct V_44 * V_93 ;
if ( V_9 -> V_169 == V_169 )
return;
F_101 ( V_9 , V_169 ) ;
F_19 (path, &w->sources, list_sink) {
if ( V_93 -> V_138 ) {
F_99 ( V_93 -> V_138 , V_169 ,
V_93 -> V_58 ) ;
}
}
switch ( V_9 -> V_47 ) {
case V_78 :
case V_79 :
case V_80 :
break;
default:
F_19 (path, &w->sinks, list_source) {
if ( V_93 -> V_136 ) {
F_99 ( V_93 -> V_136 , V_169 ,
V_93 -> V_58 ) ;
}
}
break;
}
if ( V_169 )
F_79 ( V_9 , V_200 , true ) ;
else
F_79 ( V_9 , V_201 , false ) ;
V_9 -> V_169 = V_169 ;
}
static void F_102 ( struct V_8 * V_9 ,
struct V_166 * V_200 ,
struct V_166 * V_201 )
{
int V_169 ;
switch ( V_9 -> V_47 ) {
case V_89 :
F_79 ( V_9 , V_201 , false ) ;
break;
case V_90 :
F_79 ( V_9 , V_200 , true ) ;
break;
default:
V_169 = F_71 ( V_9 ) ;
F_100 ( V_9 , V_169 , V_200 , V_201 ) ;
break;
}
}
static int F_103 ( struct V_18 * V_12 , int V_147 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
struct V_18 * V_193 ;
F_88 ( V_200 ) ;
F_88 ( V_201 ) ;
F_104 ( V_202 ) ;
enum V_37 V_203 ;
F_105 ( V_14 ) ;
F_19 (d, &card->dapm_list, list) {
if ( V_193 -> V_204 )
V_193 -> V_195 = V_194 ;
else
V_193 -> V_195 = V_196 ;
}
F_18 ( V_14 ) ;
F_19 (w, &card->dapm_dirty, dirty) {
F_102 ( V_9 , & V_200 , & V_201 ) ;
}
F_19 (w, &card->widgets, list) {
switch ( V_9 -> V_47 ) {
case V_89 :
case V_90 :
break;
default:
F_106 ( & V_9 -> V_10 ) ;
break;
}
if ( V_9 -> V_169 ) {
V_193 = V_9 -> V_12 ;
switch ( V_9 -> V_47 ) {
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
F_19 (d, &card->dapm_list, list)
if ( V_193 -> V_195 > V_203 )
V_203 = V_193 -> V_195 ;
F_19 (d, &card->dapm_list, list)
if ( ! V_193 -> V_204 )
V_193 -> V_195 = V_203 ;
F_107 ( V_14 ) ;
F_19 (d, &dapm->card->dapm_list, list)
F_108 ( F_95 , V_193 ,
& V_202 ) ;
F_109 ( & V_202 ) ;
F_87 ( V_12 , & V_201 , V_147 , false ) ;
F_94 ( V_12 ) ;
F_87 ( V_12 , & V_200 , V_147 , true ) ;
F_19 (d, &dapm->card->dapm_list, list)
F_108 ( F_97 , V_193 ,
& V_202 ) ;
F_109 ( & V_202 ) ;
F_19 (d, &card->dapm_list, list) {
if ( V_193 -> V_205 )
V_193 -> V_205 ( V_193 , V_147 ) ;
}
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_33 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_110 ( V_14 ) ;
return 0 ;
}
static T_5 F_111 ( struct V_206 * V_206 ,
char T_6 * V_207 ,
T_3 V_208 , T_7 * V_209 )
{
struct V_8 * V_9 = V_206 -> V_123 ;
char * V_5 ;
int V_156 , V_40 ;
T_5 V_35 ;
struct V_44 * V_45 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_116 ;
V_156 = F_57 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
V_40 = F_54 ( V_9 , NULL ) ;
F_49 ( V_9 -> V_12 ) ;
V_35 = snprintf ( V_5 , V_6 , L_34 ,
V_9 -> V_13 , V_9 -> V_169 ? L_35 : L_36 ,
V_9 -> V_154 ? L_37 : L_38 , V_156 , V_40 ) ;
if ( V_9 -> V_26 >= 0 )
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 ,
L_39 ,
V_9 -> V_26 , V_9 -> V_26 , V_9 -> V_55 ) ;
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 , L_40 ) ;
if ( V_9 -> V_210 )
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 , L_41 ,
V_9 -> V_210 ,
V_9 -> V_131 ? L_42 : L_43 ) ;
F_19 (p, &w->sources, list_sink) {
if ( V_45 -> V_132 && ! V_45 -> V_132 ( V_9 , V_45 -> V_136 ) )
continue;
if ( V_45 -> V_58 )
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 ,
L_44 ,
V_45 -> V_13 ? V_45 -> V_13 : L_45 ,
V_45 -> V_138 -> V_13 ) ;
}
F_19 (p, &w->sinks, list_source) {
if ( V_45 -> V_132 && ! V_45 -> V_132 ( V_9 , V_45 -> V_136 ) )
continue;
if ( V_45 -> V_58 )
V_35 += snprintf ( V_5 + V_35 , V_6 - V_35 ,
L_46 ,
V_45 -> V_13 ? V_45 -> V_13 : L_45 ,
V_45 -> V_136 -> V_13 ) ;
}
V_35 = F_112 ( V_207 , V_208 , V_209 , V_5 , V_35 ) ;
F_7 ( V_5 ) ;
return V_35 ;
}
static T_5 F_113 ( struct V_206 * V_206 , char T_6 * V_207 ,
T_3 V_208 , T_7 * V_209 )
{
struct V_18 * V_12 = V_206 -> V_123 ;
char * V_38 ;
switch ( V_12 -> V_42 ) {
case V_198 :
V_38 = L_47 ;
break;
case V_197 :
V_38 = L_48 ;
break;
case V_196 :
V_38 = L_49 ;
break;
case V_194 :
V_38 = L_50 ;
break;
default:
F_16 () ;
V_38 = L_51 ;
break;
}
return F_112 ( V_207 , V_208 , V_209 , V_38 ,
strlen ( V_38 ) ) ;
}
void F_114 ( struct V_18 * V_12 ,
struct V_211 * V_212 )
{
struct V_211 * V_193 ;
V_12 -> V_213 = F_115 ( L_52 , V_212 ) ;
if ( ! V_12 -> V_213 ) {
F_116 ( V_12 -> V_3 ,
L_53 ) ;
return;
}
V_193 = F_117 ( L_54 , 0444 ,
V_12 -> V_213 , V_12 ,
& V_214 ) ;
if ( ! V_193 )
F_116 ( V_12 -> V_3 ,
L_55 ) ;
}
static void F_118 ( struct V_8 * V_9 )
{
struct V_18 * V_12 = V_9 -> V_12 ;
struct V_211 * V_193 ;
if ( ! V_12 -> V_213 || ! V_9 -> V_13 )
return;
V_193 = F_117 ( V_9 -> V_13 , 0444 ,
V_12 -> V_213 , V_9 ,
& V_215 ) ;
if ( ! V_193 )
F_116 ( V_9 -> V_12 -> V_3 ,
L_56 ,
V_9 -> V_13 ) ;
}
static void F_119 ( struct V_18 * V_12 )
{
F_120 ( V_12 -> V_213 ) ;
}
void F_114 ( struct V_18 * V_12 ,
struct V_211 * V_212 )
{
}
static inline void F_118 ( struct V_8 * V_9 )
{
}
static inline void F_119 ( struct V_18 * V_12 )
{
}
static int F_121 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_216 , struct V_60 * V_61 )
{
struct V_44 * V_93 ;
int V_217 = 0 ;
if ( V_125 -> V_47 != V_59 &&
V_125 -> V_47 != V_66 &&
V_125 -> V_47 != V_67 )
return - V_103 ;
F_19 (path, &widget->dapm->card->paths, list) {
if ( V_93 -> V_96 != V_96 )
continue;
if ( ! V_93 -> V_13 || ! V_61 -> V_65 [ V_216 ] )
continue;
V_217 = 1 ;
if ( ! ( strcmp ( V_93 -> V_13 , V_61 -> V_65 [ V_216 ] ) ) ) {
V_93 -> V_58 = 1 ;
F_10 ( V_93 -> V_138 , L_57 ) ;
} else {
if ( V_93 -> V_58 )
F_10 ( V_93 -> V_138 ,
L_58 ) ;
V_93 -> V_58 = 0 ;
}
}
if ( V_217 ) {
F_10 ( V_125 , L_59 ) ;
F_103 ( V_125 -> V_12 , V_218 ) ;
}
return V_217 ;
}
int F_122 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_216 , struct V_60 * V_61 )
{
struct V_21 * V_14 = V_125 -> V_12 -> V_14 ;
int V_35 ;
F_60 ( & V_14 -> V_142 , V_143 ) ;
V_35 = F_121 ( V_125 , V_96 , V_216 , V_61 ) ;
F_30 ( & V_14 -> V_142 ) ;
if ( V_35 > 0 )
F_123 ( V_125 ) ;
return V_35 ;
}
static int F_124 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_58 )
{
struct V_44 * V_93 ;
int V_217 = 0 ;
if ( V_125 -> V_47 != V_49 &&
V_125 -> V_47 != V_50 &&
V_125 -> V_47 != V_48 )
return - V_103 ;
F_19 (path, &widget->dapm->card->paths, list) {
if ( V_93 -> V_96 != V_96 )
continue;
V_217 = 1 ;
V_93 -> V_58 = V_58 ;
F_10 ( V_93 -> V_138 , L_60 ) ;
}
if ( V_217 ) {
F_10 ( V_125 , L_61 ) ;
F_103 ( V_125 -> V_12 , V_218 ) ;
}
return V_217 ;
}
int F_125 ( struct V_8 * V_125 ,
struct V_107 * V_96 , int V_58 )
{
struct V_21 * V_14 = V_125 -> V_12 -> V_14 ;
int V_35 ;
F_60 ( & V_14 -> V_142 , V_143 ) ;
V_35 = F_124 ( V_125 , V_96 , V_58 ) ;
F_30 ( & V_14 -> V_142 ) ;
if ( V_35 > 0 )
F_123 ( V_125 ) ;
return V_35 ;
}
static T_5 F_126 ( struct V_2 * V_3 ,
struct V_219 * V_220 , char * V_5 )
{
struct V_221 * V_222 = F_127 ( V_3 ) ;
struct V_223 * V_19 = V_222 -> V_19 ;
struct V_8 * V_9 ;
int V_208 = 0 ;
char * V_224 = L_62 ;
F_19 (w, &codec->card->widgets, list) {
if ( V_9 -> V_12 != & V_19 -> V_12 )
continue;
switch ( V_9 -> V_47 ) {
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_76 :
case V_75 :
case V_72 :
case V_69 :
case V_70 :
case V_49 :
case V_50 :
case V_78 :
case V_79 :
case V_80 :
if ( V_9 -> V_13 )
V_208 += sprintf ( V_5 + V_208 , L_63 ,
V_9 -> V_13 , V_9 -> V_169 ? L_35 : L_36 ) ;
break;
default:
break;
}
}
switch ( V_19 -> V_12 . V_42 ) {
case V_198 :
V_224 = L_35 ;
break;
case V_197 :
V_224 = L_64 ;
break;
case V_196 :
V_224 = L_65 ;
break;
case V_194 :
V_224 = L_36 ;
break;
}
V_208 += sprintf ( V_5 + V_208 , L_66 , V_224 ) ;
return V_208 ;
}
int F_128 ( struct V_2 * V_3 )
{
return F_129 ( V_3 , & V_225 ) ;
}
static void F_130 ( struct V_2 * V_3 )
{
F_131 ( V_3 , & V_225 ) ;
}
static void F_132 ( struct V_18 * V_12 )
{
struct V_8 * V_9 , * V_226 ;
struct V_44 * V_45 , * V_227 ;
F_89 (w, next_w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
F_133 ( & V_9 -> V_97 ) ;
F_89 (p, next_p, &w->sources, list_sink) {
F_133 ( & V_45 -> V_99 ) ;
F_133 ( & V_45 -> V_101 ) ;
F_133 ( & V_45 -> V_97 ) ;
F_7 ( V_45 -> V_119 ) ;
F_7 ( V_45 ) ;
}
F_89 (p, next_p, &w->sinks, list_source) {
F_133 ( & V_45 -> V_99 ) ;
F_133 ( & V_45 -> V_101 ) ;
F_133 ( & V_45 -> V_97 ) ;
F_7 ( V_45 -> V_119 ) ;
F_7 ( V_45 ) ;
}
F_7 ( V_9 -> V_108 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
}
static struct V_8 * F_134 (
struct V_18 * V_12 , const char * V_228 ,
bool V_229 )
{
struct V_8 * V_9 ;
struct V_8 * V_230 = NULL ;
F_19 (w, &dapm->card->widgets, list) {
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
static int F_135 ( struct V_18 * V_12 ,
const char * V_228 , int V_231 )
{
struct V_8 * V_9 = F_134 ( V_12 , V_228 , true ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_67 , V_228 ) ;
return - V_122 ;
}
if ( V_9 -> V_132 != V_231 )
F_10 ( V_9 , L_68 ) ;
V_9 -> V_132 = V_231 ;
if ( V_231 == 0 )
V_9 -> V_154 = 0 ;
return 0 ;
}
int F_136 ( struct V_18 * V_12 )
{
int V_35 ;
if ( ! V_12 -> V_14 || ! V_12 -> V_14 -> V_232 )
return 0 ;
F_60 ( & V_12 -> V_14 -> V_142 , V_143 ) ;
V_35 = F_103 ( V_12 , V_218 ) ;
F_30 ( & V_12 -> V_14 -> V_142 ) ;
return V_35 ;
}
static int F_137 ( struct V_18 * V_12 ,
const struct V_233 * V_234 )
{
struct V_44 * V_93 ;
struct V_8 * V_235 = NULL , * V_236 = NULL , * V_9 ;
struct V_8 * V_237 = NULL , * V_238 = NULL ;
const char * V_136 ;
const char * V_239 = V_234 -> V_239 ;
const char * V_138 ;
char V_240 [ 80 ] ;
char V_241 [ 80 ] ;
int V_35 = 0 ;
if ( V_12 -> V_19 && V_12 -> V_19 -> V_115 ) {
snprintf ( V_240 , sizeof( V_240 ) , L_6 ,
V_12 -> V_19 -> V_115 , V_234 -> V_136 ) ;
V_136 = V_240 ;
snprintf ( V_241 , sizeof( V_241 ) , L_6 ,
V_12 -> V_19 -> V_115 , V_234 -> V_138 ) ;
V_138 = V_241 ;
} else {
V_136 = V_234 -> V_136 ;
V_138 = V_234 -> V_138 ;
}
F_19 (w, &dapm->card->widgets, list) {
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
if ( V_235 == NULL || V_236 == NULL )
return - V_103 ;
V_93 = F_43 ( sizeof( struct V_44 ) , V_7 ) ;
if ( ! V_93 )
return - V_116 ;
V_93 -> V_138 = V_235 ;
V_93 -> V_136 = V_236 ;
V_93 -> V_132 = V_234 -> V_132 ;
F_91 ( & V_93 -> V_97 ) ;
F_91 ( & V_93 -> V_101 ) ;
F_91 ( & V_93 -> V_99 ) ;
if ( V_236 -> V_47 == V_73 ) {
if ( V_235 -> V_47 == V_76 ||
V_235 -> V_47 == V_85 ||
V_235 -> V_47 == V_87 ||
V_235 -> V_47 == V_71 )
V_236 -> V_133 = 1 ;
}
if ( V_235 -> V_47 == V_71 ) {
if ( V_236 -> V_47 == V_86 ||
V_236 -> V_47 == V_84 ||
V_236 -> V_47 == V_87 ||
V_236 -> V_47 == V_73 )
V_235 -> V_133 = 1 ;
}
if ( V_239 == NULL ) {
F_39 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_39 ( & V_93 -> V_99 , & V_236 -> V_100 ) ;
F_39 ( & V_93 -> V_101 , & V_235 -> V_102 ) ;
V_93 -> V_58 = 1 ;
return 0 ;
}
switch ( V_236 -> V_47 ) {
case V_72 :
case V_75 :
case V_69 :
case V_70 :
case V_73 :
case V_71 :
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
F_39 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_39 ( & V_93 -> V_99 , & V_236 -> V_100 ) ;
F_39 ( & V_93 -> V_101 , & V_235 -> V_102 ) ;
V_93 -> V_58 = 1 ;
return 0 ;
case V_59 :
case V_66 :
case V_67 :
V_35 = F_38 ( V_12 , V_235 , V_236 , V_93 , V_239 ,
& V_236 -> V_53 [ 0 ] ) ;
if ( V_35 != 0 )
goto V_137;
break;
case V_48 :
case V_49 :
case V_50 :
V_35 = F_40 ( V_12 , V_235 , V_236 , V_93 , V_239 ) ;
if ( V_35 != 0 )
goto V_137;
break;
case V_84 :
case V_85 :
case V_87 :
case V_86 :
F_39 ( & V_93 -> V_97 , & V_12 -> V_14 -> V_98 ) ;
F_39 ( & V_93 -> V_99 , & V_236 -> V_100 ) ;
F_39 ( & V_93 -> V_101 , & V_235 -> V_102 ) ;
V_93 -> V_58 = 0 ;
return 0 ;
}
F_10 ( V_235 , L_69 ) ;
F_10 ( V_236 , L_69 ) ;
return 0 ;
V_137:
F_116 ( V_12 -> V_3 , L_70 ,
V_138 , V_239 , V_136 ) ;
F_7 ( V_93 ) ;
return V_35 ;
}
static int F_138 ( struct V_18 * V_12 ,
const struct V_233 * V_234 )
{
struct V_44 * V_93 , * V_45 ;
const char * V_136 ;
const char * V_138 ;
char V_240 [ 80 ] ;
char V_241 [ 80 ] ;
if ( V_234 -> V_239 ) {
F_23 ( V_12 -> V_3 ,
L_71 ) ;
return - V_122 ;
}
if ( V_12 -> V_19 && V_12 -> V_19 -> V_115 ) {
snprintf ( V_240 , sizeof( V_240 ) , L_6 ,
V_12 -> V_19 -> V_115 , V_234 -> V_136 ) ;
V_136 = V_240 ;
snprintf ( V_241 , sizeof( V_241 ) , L_6 ,
V_12 -> V_19 -> V_115 , V_234 -> V_138 ) ;
V_138 = V_241 ;
} else {
V_136 = V_234 -> V_136 ;
V_138 = V_234 -> V_138 ;
}
V_93 = NULL ;
F_19 (p, &dapm->card->paths, list) {
if ( strcmp ( V_45 -> V_138 -> V_13 , V_138 ) != 0 )
continue;
if ( strcmp ( V_45 -> V_136 -> V_13 , V_136 ) != 0 )
continue;
V_93 = V_45 ;
break;
}
if ( V_93 ) {
F_10 ( V_93 -> V_138 , L_72 ) ;
F_10 ( V_93 -> V_136 , L_72 ) ;
F_133 ( & V_93 -> V_97 ) ;
F_133 ( & V_93 -> V_99 ) ;
F_133 ( & V_93 -> V_101 ) ;
F_7 ( V_93 ) ;
} else {
F_116 ( V_12 -> V_3 , L_73 ,
V_138 , V_136 ) ;
}
return 0 ;
}
int F_139 ( struct V_18 * V_12 ,
const struct V_233 * V_234 , int V_242 )
{
int V_46 , V_243 , V_35 = 0 ;
F_60 ( & V_12 -> V_14 -> V_142 , V_244 ) ;
for ( V_46 = 0 ; V_46 < V_242 ; V_46 ++ ) {
V_243 = F_137 ( V_12 , V_234 ) ;
if ( V_243 < 0 ) {
F_23 ( V_12 -> V_3 , L_74 ,
V_234 -> V_138 , V_234 -> V_136 ) ;
V_35 = V_243 ;
}
V_234 ++ ;
}
F_30 ( & V_12 -> V_14 -> V_142 ) ;
return V_35 ;
}
int F_140 ( struct V_18 * V_12 ,
const struct V_233 * V_234 , int V_242 )
{
int V_46 , V_35 = 0 ;
F_60 ( & V_12 -> V_14 -> V_142 , V_244 ) ;
for ( V_46 = 0 ; V_46 < V_242 ; V_46 ++ ) {
F_138 ( V_12 , V_234 ) ;
V_234 ++ ;
}
F_30 ( & V_12 -> V_14 -> V_142 ) ;
return V_35 ;
}
static int F_141 ( struct V_18 * V_12 ,
const struct V_233 * V_234 )
{
struct V_8 * V_138 = F_134 ( V_12 ,
V_234 -> V_138 ,
true ) ;
struct V_8 * V_136 = F_134 ( V_12 ,
V_234 -> V_136 ,
true ) ;
struct V_44 * V_93 ;
int V_208 = 0 ;
if ( ! V_138 ) {
F_23 ( V_12 -> V_3 , L_75 ,
V_234 -> V_138 ) ;
return - V_103 ;
}
if ( ! V_136 ) {
F_23 ( V_12 -> V_3 , L_76 ,
V_234 -> V_136 ) ;
return - V_103 ;
}
if ( V_234 -> V_239 || V_234 -> V_132 )
F_116 ( V_12 -> V_3 , L_77 ,
V_234 -> V_138 , V_234 -> V_136 ) ;
F_19 (path, &source->sinks, list_source) {
if ( V_93 -> V_136 == V_136 ) {
V_93 -> V_135 = 1 ;
V_208 ++ ;
}
}
if ( V_208 == 0 )
F_23 ( V_12 -> V_3 , L_78 ,
V_234 -> V_138 , V_234 -> V_136 ) ;
if ( V_208 > 1 )
F_116 ( V_12 -> V_3 , L_79 ,
V_208 , V_234 -> V_138 , V_234 -> V_136 ) ;
return 0 ;
}
int F_142 ( struct V_18 * V_12 ,
const struct V_233 * V_234 , int V_242 )
{
int V_46 , V_137 ;
int V_35 = 0 ;
F_60 ( & V_12 -> V_14 -> V_142 , V_244 ) ;
for ( V_46 = 0 ; V_46 < V_242 ; V_46 ++ ) {
V_137 = F_141 ( V_12 , V_234 ) ;
if ( V_137 )
V_35 = V_137 ;
V_234 ++ ;
}
F_30 ( & V_12 -> V_14 -> V_142 ) ;
return V_35 ;
}
int F_143 ( struct V_18 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
F_60 ( & V_12 -> V_14 -> V_142 , V_244 ) ;
F_19 (w, &dapm->card->widgets, list)
{
if ( V_9 -> V_34 )
continue;
if ( V_9 -> V_104 ) {
V_9 -> V_108 = F_43 ( V_9 -> V_104 *
sizeof( struct V_107 * ) ,
V_7 ) ;
if ( ! V_9 -> V_108 ) {
F_30 ( & V_12 -> V_14 -> V_142 ) ;
return - V_116 ;
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
V_9 -> V_169 = 1 ;
}
V_9 -> V_34 = 1 ;
F_10 ( V_9 , L_80 ) ;
F_118 ( V_9 ) ;
}
F_103 ( V_12 , V_218 ) ;
F_30 ( & V_12 -> V_14 -> V_142 ) ;
return 0 ;
}
int F_144 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_145 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_51 * V_52 =
(struct V_51 * ) V_96 -> V_54 ;
unsigned int V_26 = V_52 -> V_26 ;
unsigned int V_55 = V_52 -> V_55 ;
int V_56 = V_52 -> V_56 ;
unsigned int V_30 = ( 1 << F_37 ( V_56 ) ) - 1 ;
unsigned int V_57 = V_52 -> V_57 ;
if ( F_146 ( V_52 ) )
F_116 ( V_125 -> V_12 -> V_3 ,
L_81 ,
V_96 -> V_47 . V_13 ) ;
V_246 -> V_31 . integer . V_31 [ 0 ] =
( F_21 ( V_125 -> V_19 , V_26 ) >> V_55 ) & V_30 ;
if ( V_57 )
V_246 -> V_31 . integer . V_31 [ 0 ] =
V_56 - V_246 -> V_31 . integer . V_31 [ 0 ] ;
return 0 ;
}
int F_147 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_145 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_223 * V_19 = V_125 -> V_19 ;
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_51 * V_52 =
(struct V_51 * ) V_96 -> V_54 ;
unsigned int V_26 = V_52 -> V_26 ;
unsigned int V_55 = V_52 -> V_55 ;
int V_56 = V_52 -> V_56 ;
unsigned int V_30 = ( 1 << F_37 ( V_56 ) ) - 1 ;
unsigned int V_57 = V_52 -> V_57 ;
unsigned int V_27 ;
int V_58 , V_32 ;
struct V_187 V_188 ;
int V_247 ;
if ( F_146 ( V_52 ) )
F_116 ( V_125 -> V_12 -> V_3 ,
L_81 ,
V_96 -> V_47 . V_13 ) ;
V_27 = ( V_246 -> V_31 . integer . V_31 [ 0 ] & V_30 ) ;
V_58 = ! ! V_27 ;
if ( V_57 )
V_27 = V_56 - V_27 ;
V_30 = V_30 << V_55 ;
V_27 = V_27 << V_55 ;
F_60 ( & V_14 -> V_142 , V_143 ) ;
V_32 = F_148 ( V_125 -> V_19 , V_26 , V_30 , V_27 ) ;
if ( V_32 ) {
for ( V_247 = 0 ; V_247 < V_113 -> V_117 ; V_247 ++ ) {
V_125 = V_113 -> V_118 [ V_247 ] ;
V_125 -> V_31 = V_27 ;
V_188 . V_96 = V_96 ;
V_188 . V_125 = V_125 ;
V_188 . V_26 = V_26 ;
V_188 . V_30 = V_30 ;
V_188 . V_27 = V_27 ;
V_125 -> V_12 -> V_188 = & V_188 ;
F_124 ( V_125 , V_96 , V_58 ) ;
V_125 -> V_12 -> V_188 = NULL ;
}
}
F_30 ( & V_14 -> V_142 ) ;
return 0 ;
}
int F_149 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_145 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_60 * V_61 = (struct V_60 * ) V_96 -> V_54 ;
unsigned int V_27 , V_63 ;
for ( V_63 = 1 ; V_63 < V_61 -> V_56 ; V_63 <<= 1 )
;
V_27 = F_21 ( V_125 -> V_19 , V_61 -> V_26 ) ;
V_246 -> V_31 . V_248 . V_62 [ 0 ] = ( V_27 >> V_61 -> V_64 ) & ( V_63 - 1 ) ;
if ( V_61 -> V_64 != V_61 -> V_249 )
V_246 -> V_31 . V_248 . V_62 [ 1 ] =
( V_27 >> V_61 -> V_249 ) & ( V_63 - 1 ) ;
return 0 ;
}
int F_150 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_145 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_223 * V_19 = V_125 -> V_19 ;
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_60 * V_61 = (struct V_60 * ) V_96 -> V_54 ;
unsigned int V_27 , V_216 , V_32 ;
unsigned int V_30 , V_63 ;
struct V_187 V_188 ;
int V_247 ;
for ( V_63 = 1 ; V_63 < V_61 -> V_56 ; V_63 <<= 1 )
;
if ( V_246 -> V_31 . V_248 . V_62 [ 0 ] > V_61 -> V_56 - 1 )
return - V_122 ;
V_216 = V_246 -> V_31 . V_248 . V_62 [ 0 ] ;
V_27 = V_216 << V_61 -> V_64 ;
V_30 = ( V_63 - 1 ) << V_61 -> V_64 ;
if ( V_61 -> V_64 != V_61 -> V_249 ) {
if ( V_246 -> V_31 . V_248 . V_62 [ 1 ] > V_61 -> V_56 - 1 )
return - V_122 ;
V_27 |= V_246 -> V_31 . V_248 . V_62 [ 1 ] << V_61 -> V_249 ;
V_30 |= ( V_63 - 1 ) << V_61 -> V_249 ;
}
F_60 ( & V_14 -> V_142 , V_143 ) ;
V_32 = F_148 ( V_125 -> V_19 , V_61 -> V_26 , V_30 , V_27 ) ;
if ( V_32 ) {
for ( V_247 = 0 ; V_247 < V_113 -> V_117 ; V_247 ++ ) {
V_125 = V_113 -> V_118 [ V_247 ] ;
V_125 -> V_31 = V_27 ;
V_188 . V_96 = V_96 ;
V_188 . V_125 = V_125 ;
V_188 . V_26 = V_61 -> V_26 ;
V_188 . V_30 = V_30 ;
V_188 . V_27 = V_27 ;
V_125 -> V_12 -> V_188 = & V_188 ;
F_121 ( V_125 , V_96 , V_216 , V_61 ) ;
V_125 -> V_12 -> V_188 = NULL ;
}
}
F_30 ( & V_14 -> V_142 ) ;
return V_32 ;
}
int F_151 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_145 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
V_246 -> V_31 . V_248 . V_62 [ 0 ] = V_125 -> V_31 ;
return 0 ;
}
int F_152 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_145 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_223 * V_19 = V_125 -> V_19 ;
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_60 * V_61 =
(struct V_60 * ) V_96 -> V_54 ;
int V_32 ;
int V_35 = 0 ;
int V_247 ;
if ( V_246 -> V_31 . V_248 . V_62 [ 0 ] >= V_61 -> V_56 )
return - V_122 ;
F_60 ( & V_14 -> V_142 , V_143 ) ;
V_32 = V_125 -> V_31 != V_246 -> V_31 . V_248 . V_62 [ 0 ] ;
if ( V_32 ) {
for ( V_247 = 0 ; V_247 < V_113 -> V_117 ; V_247 ++ ) {
V_125 = V_113 -> V_118 [ V_247 ] ;
V_125 -> V_31 = V_246 -> V_31 . V_248 . V_62 [ 0 ] ;
F_121 ( V_125 , V_96 , V_125 -> V_31 , V_61 ) ;
}
}
F_30 ( & V_14 -> V_142 ) ;
return V_35 ;
}
int F_153 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_145 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_60 * V_61 = (struct V_60 * ) V_96 -> V_54 ;
unsigned int V_250 , V_27 , V_216 ;
V_250 = F_21 ( V_125 -> V_19 , V_61 -> V_26 ) ;
V_27 = ( V_250 >> V_61 -> V_64 ) & V_61 -> V_30 ;
for ( V_216 = 0 ; V_216 < V_61 -> V_56 ; V_216 ++ ) {
if ( V_27 == V_61 -> V_68 [ V_216 ] )
break;
}
V_246 -> V_31 . V_248 . V_62 [ 0 ] = V_216 ;
if ( V_61 -> V_64 != V_61 -> V_249 ) {
V_27 = ( V_250 >> V_61 -> V_249 ) & V_61 -> V_30 ;
for ( V_216 = 0 ; V_216 < V_61 -> V_56 ; V_216 ++ ) {
if ( V_27 == V_61 -> V_68 [ V_216 ] )
break;
}
V_246 -> V_31 . V_248 . V_62 [ 1 ] = V_216 ;
}
return 0 ;
}
int F_154 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_112 * V_113 = F_145 ( V_96 ) ;
struct V_8 * V_125 = V_113 -> V_118 [ 0 ] ;
struct V_223 * V_19 = V_125 -> V_19 ;
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_60 * V_61 = (struct V_60 * ) V_96 -> V_54 ;
unsigned int V_27 , V_216 , V_32 ;
unsigned int V_30 ;
struct V_187 V_188 ;
int V_247 ;
if ( V_246 -> V_31 . V_248 . V_62 [ 0 ] > V_61 -> V_56 - 1 )
return - V_122 ;
V_216 = V_246 -> V_31 . V_248 . V_62 [ 0 ] ;
V_27 = V_61 -> V_68 [ V_246 -> V_31 . V_248 . V_62 [ 0 ] ] << V_61 -> V_64 ;
V_30 = V_61 -> V_30 << V_61 -> V_64 ;
if ( V_61 -> V_64 != V_61 -> V_249 ) {
if ( V_246 -> V_31 . V_248 . V_62 [ 1 ] > V_61 -> V_56 - 1 )
return - V_122 ;
V_27 |= V_61 -> V_68 [ V_246 -> V_31 . V_248 . V_62 [ 1 ] ] << V_61 -> V_249 ;
V_30 |= V_61 -> V_30 << V_61 -> V_249 ;
}
F_60 ( & V_14 -> V_142 , V_143 ) ;
V_32 = F_148 ( V_125 -> V_19 , V_61 -> V_26 , V_30 , V_27 ) ;
if ( V_32 ) {
for ( V_247 = 0 ; V_247 < V_113 -> V_117 ; V_247 ++ ) {
V_125 = V_113 -> V_118 [ V_247 ] ;
V_125 -> V_31 = V_27 ;
V_188 . V_96 = V_96 ;
V_188 . V_125 = V_125 ;
V_188 . V_26 = V_61 -> V_26 ;
V_188 . V_30 = V_30 ;
V_188 . V_27 = V_27 ;
V_125 -> V_12 -> V_188 = & V_188 ;
F_121 ( V_125 , V_96 , V_216 , V_61 ) ;
V_125 -> V_12 -> V_188 = NULL ;
}
}
F_30 ( & V_14 -> V_142 ) ;
return V_32 ;
}
int F_155 ( struct V_107 * V_96 ,
struct V_251 * V_252 )
{
V_252 -> type = V_253 ;
V_252 -> V_208 = 1 ;
V_252 -> V_31 . integer . V_254 = 0 ;
V_252 -> V_31 . integer . V_56 = 1 ;
return 0 ;
}
int F_156 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_21 * V_14 = F_145 ( V_96 ) ;
const char * V_228 = ( const char * ) V_96 -> V_54 ;
F_60 ( & V_14 -> V_142 , V_143 ) ;
V_246 -> V_31 . integer . V_31 [ 0 ] =
F_157 ( & V_14 -> V_12 , V_228 ) ;
F_30 ( & V_14 -> V_142 ) ;
return 0 ;
}
int F_158 ( struct V_107 * V_96 ,
struct V_245 * V_246 )
{
struct V_21 * V_14 = F_145 ( V_96 ) ;
const char * V_228 = ( const char * ) V_96 -> V_54 ;
F_60 ( & V_14 -> V_142 , V_143 ) ;
if ( V_246 -> V_31 . integer . V_31 [ 0 ] )
F_159 ( & V_14 -> V_12 , V_228 ) ;
else
F_160 ( & V_14 -> V_12 , V_228 ) ;
F_30 ( & V_14 -> V_142 ) ;
F_136 ( & V_14 -> V_12 ) ;
return 0 ;
}
static struct V_8 *
F_161 ( struct V_18 * V_12 ,
const struct V_8 * V_125 )
{
struct V_8 * V_9 ;
T_3 V_109 ;
int V_35 ;
if ( ( V_9 = F_13 ( V_125 ) ) == NULL )
return NULL ;
switch ( V_9 -> V_47 ) {
case V_79 :
V_9 -> V_150 = F_162 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_163 ( V_9 -> V_150 ) ) {
V_35 = F_164 ( V_9 -> V_150 ) ;
F_23 ( V_12 -> V_3 , L_82 ,
V_9 -> V_13 , V_35 ) ;
return NULL ;
}
break;
case V_80 :
#ifdef F_165
V_9 -> V_151 = F_166 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_163 ( V_9 -> V_151 ) ) {
V_35 = F_164 ( V_9 -> V_151 ) ;
F_23 ( V_12 -> V_3 , L_82 ,
V_9 -> V_13 , V_35 ) ;
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
if ( V_12 -> V_19 && V_12 -> V_19 -> V_115 )
V_109 += 1 + strlen ( V_12 -> V_19 -> V_115 ) ;
V_9 -> V_13 = F_5 ( V_109 , V_7 ) ;
if ( V_9 -> V_13 == NULL ) {
F_7 ( V_9 ) ;
return NULL ;
}
if ( V_12 -> V_19 && V_12 -> V_19 -> V_115 )
snprintf ( ( char * ) V_9 -> V_13 , V_109 , L_6 ,
V_12 -> V_19 -> V_115 , V_125 -> V_13 ) ;
else
snprintf ( ( char * ) V_9 -> V_13 , V_109 , L_1 , V_125 -> V_13 ) ;
switch ( V_9 -> V_47 ) {
case V_48 :
case V_49 :
case V_50 :
V_9 -> V_155 = F_72 ;
break;
case V_59 :
case V_66 :
case V_67 :
V_9 -> V_155 = F_72 ;
break;
case V_72 :
case V_82 :
V_9 -> V_155 = F_74 ;
break;
case V_75 :
case V_81 :
V_9 -> V_155 = F_75 ;
break;
case V_69 :
case V_70 :
case V_73 :
case V_71 :
case V_76 :
case V_86 :
case V_84 :
case V_85 :
case V_87 :
case V_88 :
V_9 -> V_155 = F_72 ;
break;
case V_78 :
case V_79 :
case V_80 :
V_9 -> V_155 = F_76 ;
break;
case V_83 :
V_9 -> V_155 = F_73 ;
break;
default:
V_9 -> V_155 = F_77 ;
break;
}
V_12 -> V_255 ++ ;
V_9 -> V_12 = V_12 ;
V_9 -> V_19 = V_12 -> V_19 ;
V_9 -> V_20 = V_12 -> V_20 ;
F_91 ( & V_9 -> V_100 ) ;
F_91 ( & V_9 -> V_102 ) ;
F_91 ( & V_9 -> V_97 ) ;
F_91 ( & V_9 -> V_10 ) ;
F_39 ( & V_9 -> V_97 , & V_12 -> V_14 -> V_118 ) ;
V_9 -> V_132 = 1 ;
return V_9 ;
}
int F_167 ( struct V_18 * V_12 ,
const struct V_8 * V_125 ,
int V_242 )
{
struct V_8 * V_9 ;
int V_46 ;
int V_35 = 0 ;
F_60 ( & V_12 -> V_14 -> V_142 , V_244 ) ;
for ( V_46 = 0 ; V_46 < V_242 ; V_46 ++ ) {
V_9 = F_161 ( V_12 , V_125 ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 ,
L_83 ,
V_125 -> V_13 ) ;
V_35 = - V_116 ;
break;
}
V_125 ++ ;
}
F_30 ( & V_12 -> V_14 -> V_142 ) ;
return V_35 ;
}
static int F_168 ( struct V_8 * V_9 ,
struct V_107 * V_96 , int V_147 )
{
struct V_44 * V_256 , * V_257 ;
struct V_139 * V_138 , * V_136 ;
const struct V_258 * V_259 = V_9 -> V_260 ;
struct V_261 V_262 ;
struct V_263 * V_260 = NULL ;
T_8 V_4 ;
int V_35 ;
F_86 ( ! V_259 ) ;
F_86 ( F_9 ( & V_9 -> V_100 ) || F_9 ( & V_9 -> V_102 ) ) ;
V_256 = F_85 ( & V_9 -> V_100 , struct V_44 ,
V_99 ) ;
V_257 = F_85 ( & V_9 -> V_102 , struct V_44 ,
V_101 ) ;
F_86 ( ! V_256 || ! V_257 ) ;
F_86 ( ! V_257 -> V_138 || ! V_256 -> V_136 ) ;
F_86 ( ! V_256 -> V_138 || ! V_257 -> V_136 ) ;
V_138 = V_256 -> V_138 -> V_264 ;
V_136 = V_257 -> V_136 -> V_264 ;
if ( V_259 -> V_265 ) {
V_4 = F_169 ( V_259 -> V_265 ) - 1 ;
} else {
F_116 ( V_9 -> V_12 -> V_3 , L_84 ,
V_259 -> V_265 ) ;
V_4 = 0 ;
}
V_260 = F_43 ( sizeof( * V_260 ) , V_7 ) ;
if ( ! V_260 ) {
V_35 = - V_116 ;
goto V_40;
}
F_170 ( F_171 ( V_260 , V_266 ) , V_4 ) ;
F_172 ( V_260 , V_267 ) -> V_254 =
V_259 -> V_268 ;
F_172 ( V_260 , V_267 ) -> V_56 =
V_259 -> V_269 ;
F_172 ( V_260 , V_270 ) -> V_254
= V_259 -> V_271 ;
F_172 ( V_260 , V_270 ) -> V_56
= V_259 -> V_272 ;
memset ( & V_262 , 0 , sizeof( V_262 ) ) ;
switch ( V_147 ) {
case V_170 :
if ( V_138 -> V_41 -> V_273 && V_138 -> V_41 -> V_273 -> V_274 ) {
V_262 . V_141 = V_275 ;
V_35 = V_138 -> V_41 -> V_273 -> V_274 ( & V_262 ,
V_260 , V_138 ) ;
if ( V_35 != 0 ) {
F_23 ( V_138 -> V_3 ,
L_85 , V_35 ) ;
goto V_40;
}
}
if ( V_136 -> V_41 -> V_273 && V_136 -> V_41 -> V_273 -> V_274 ) {
V_262 . V_141 = V_144 ;
V_35 = V_136 -> V_41 -> V_273 -> V_274 ( & V_262 , V_260 ,
V_136 ) ;
if ( V_35 != 0 ) {
F_23 ( V_136 -> V_3 ,
L_85 , V_35 ) ;
goto V_40;
}
}
break;
case V_171 :
V_35 = F_173 ( V_136 , 0 ) ;
if ( V_35 != 0 && V_35 != - V_276 )
F_116 ( V_136 -> V_3 , L_86 , V_35 ) ;
V_35 = 0 ;
break;
case V_172 :
V_35 = F_173 ( V_136 , 1 ) ;
if ( V_35 != 0 && V_35 != - V_276 )
F_116 ( V_136 -> V_3 , L_87 , V_35 ) ;
V_35 = 0 ;
break;
default:
F_16 () ;
return - V_122 ;
}
V_40:
F_7 ( V_260 ) ;
return V_35 ;
}
int F_174 ( struct V_21 * V_14 ,
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
V_280 = F_175 ( V_14 -> V_3 , V_279 , V_7 ) ;
if ( ! V_280 )
return - V_116 ;
snprintf ( V_280 , V_279 , L_88 , V_138 -> V_13 , V_136 -> V_13 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_278 . V_26 = V_181 ;
V_278 . V_47 = V_88 ;
V_278 . V_13 = V_280 ;
V_278 . V_147 = F_168 ;
V_278 . V_174 = V_170 | V_171 |
V_172 ;
F_52 ( V_14 -> V_3 , L_89 , V_280 ) ;
V_9 = F_161 ( & V_14 -> V_12 , & V_278 ) ;
if ( ! V_9 ) {
F_23 ( V_14 -> V_3 , L_90 ,
V_280 ) ;
return - V_116 ;
}
V_9 -> V_260 = V_260 ;
memset ( & V_277 , 0 , sizeof( V_277 ) ) ;
V_277 [ 0 ] . V_138 = V_138 -> V_13 ;
V_277 [ 0 ] . V_136 = V_280 ;
V_277 [ 1 ] . V_138 = V_280 ;
V_277 [ 1 ] . V_136 = V_136 -> V_13 ;
return F_139 ( & V_14 -> V_12 , V_277 ,
F_90 ( V_277 ) ) ;
}
int F_176 ( struct V_18 * V_12 ,
struct V_139 * V_140 )
{
struct V_8 V_278 ;
struct V_8 * V_9 ;
F_177 ( V_12 -> V_3 != V_140 -> V_3 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_278 . V_26 = V_181 ;
if ( V_140 -> V_41 -> V_281 . V_282 ) {
V_278 . V_47 = V_83 ;
V_278 . V_13 = V_140 -> V_41 -> V_281 . V_282 ;
V_278 . V_210 = V_140 -> V_41 -> V_281 . V_282 ;
F_52 ( V_140 -> V_3 , L_89 ,
V_278 . V_13 ) ;
V_9 = F_161 ( V_12 , & V_278 ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_90 ,
V_140 -> V_41 -> V_281 . V_282 ) ;
}
V_9 -> V_264 = V_140 ;
V_140 -> V_145 = V_9 ;
}
if ( V_140 -> V_41 -> V_283 . V_282 ) {
V_278 . V_47 = V_83 ;
V_278 . V_13 = V_140 -> V_41 -> V_283 . V_282 ;
V_278 . V_210 = V_140 -> V_41 -> V_283 . V_282 ;
F_52 ( V_140 -> V_3 , L_89 ,
V_278 . V_13 ) ;
V_9 = F_161 ( V_12 , & V_278 ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_90 ,
V_140 -> V_41 -> V_283 . V_282 ) ;
}
V_9 -> V_264 = V_140 ;
V_140 -> V_146 = V_9 ;
}
return 0 ;
}
int F_178 ( struct V_21 * V_14 )
{
struct V_8 * V_284 , * V_9 ;
struct V_139 * V_140 ;
struct V_233 V_243 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
F_19 (dai_w, &card->widgets, list) {
if ( V_284 -> V_47 != V_83 )
continue;
V_140 = V_284 -> V_264 ;
F_19 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_284 -> V_12 )
continue;
if ( V_9 -> V_47 == V_83 )
continue;
if ( ! V_9 -> V_210 )
continue;
if ( V_140 -> V_41 -> V_281 . V_282 &&
strstr ( V_9 -> V_210 ,
V_140 -> V_41 -> V_281 . V_282 ) ) {
V_243 . V_138 = V_140 -> V_145 -> V_13 ;
V_243 . V_136 = V_9 -> V_13 ;
F_52 ( V_140 -> V_3 , L_91 ,
V_243 . V_138 , V_243 . V_136 ) ;
F_137 ( V_9 -> V_12 , & V_243 ) ;
}
if ( V_140 -> V_41 -> V_283 . V_282 &&
strstr ( V_9 -> V_210 ,
V_140 -> V_41 -> V_283 . V_282 ) ) {
V_243 . V_138 = V_9 -> V_13 ;
V_243 . V_136 = V_140 -> V_146 -> V_13 ;
F_52 ( V_140 -> V_3 , L_91 ,
V_243 . V_138 , V_243 . V_136 ) ;
F_137 ( V_9 -> V_12 , & V_243 ) ;
}
}
}
return 0 ;
}
static void F_179 ( struct V_221 * V_222 , int V_141 ,
int V_147 )
{
struct V_8 * V_285 , * V_286 ;
struct V_139 * V_287 = V_222 -> V_287 ;
struct V_139 * V_288 = V_222 -> V_288 ;
if ( V_141 == V_144 ) {
V_285 = V_287 -> V_145 ;
V_286 = V_288 -> V_145 ;
} else {
V_285 = V_287 -> V_146 ;
V_286 = V_288 -> V_146 ;
}
if ( V_285 ) {
F_10 ( V_285 , L_92 ) ;
switch ( V_147 ) {
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
F_10 ( V_286 , L_92 ) ;
switch ( V_147 ) {
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
F_103 ( & V_222 -> V_14 -> V_12 , V_147 ) ;
}
void F_180 ( struct V_221 * V_222 , int V_141 ,
int V_147 )
{
struct V_21 * V_14 = V_222 -> V_14 ;
F_60 ( & V_14 -> V_142 , V_143 ) ;
F_179 ( V_222 , V_141 , V_147 ) ;
F_30 ( & V_14 -> V_142 ) ;
}
int F_159 ( struct V_18 * V_12 , const char * V_228 )
{
return F_135 ( V_12 , V_228 , 1 ) ;
}
int F_181 ( struct V_18 * V_12 ,
const char * V_228 )
{
struct V_8 * V_9 = F_134 ( V_12 , V_228 , true ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_67 , V_228 ) ;
return - V_122 ;
}
F_52 ( V_9 -> V_12 -> V_3 , L_93 , V_228 ) ;
V_9 -> V_132 = 1 ;
V_9 -> V_154 = 1 ;
F_10 ( V_9 , L_94 ) ;
return 0 ;
}
int F_160 ( struct V_18 * V_12 ,
const char * V_228 )
{
return F_135 ( V_12 , V_228 , 0 ) ;
}
int F_182 ( struct V_18 * V_12 , const char * V_228 )
{
return F_135 ( V_12 , V_228 , 0 ) ;
}
int F_157 ( struct V_18 * V_12 ,
const char * V_228 )
{
struct V_8 * V_9 = F_134 ( V_12 , V_228 , true ) ;
if ( V_9 )
return V_9 -> V_132 ;
return 0 ;
}
int F_183 ( struct V_18 * V_12 ,
const char * V_228 )
{
struct V_8 * V_9 = F_134 ( V_12 , V_228 , false ) ;
if ( ! V_9 ) {
F_23 ( V_12 -> V_3 , L_67 , V_228 ) ;
return - V_122 ;
}
V_9 -> V_128 = 1 ;
return 0 ;
}
static bool F_184 ( struct V_21 * V_14 ,
struct V_8 * V_9 )
{
struct V_44 * V_45 ;
F_19 (p, &card->paths, list) {
if ( ( V_45 -> V_138 == V_9 ) || ( V_45 -> V_136 == V_9 ) ) {
F_52 ( V_14 -> V_3 ,
L_95 ,
V_45 -> V_138 -> V_13 , V_45 -> V_138 -> V_47 , V_45 -> V_138 -> V_12 ,
V_45 -> V_136 -> V_13 , V_45 -> V_136 -> V_47 , V_45 -> V_136 -> V_12 ) ;
if ( V_45 -> V_138 -> V_12 != V_45 -> V_136 -> V_12 )
return true ;
if ( V_45 -> V_136 -> V_47 == V_73 ) {
switch ( V_45 -> V_138 -> V_47 ) {
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
void F_185 ( struct V_223 * V_19 )
{
struct V_21 * V_14 = V_19 -> V_14 ;
struct V_18 * V_12 = & V_19 -> V_12 ;
struct V_8 * V_9 ;
F_52 ( V_19 -> V_3 , L_96 ,
& V_14 -> V_12 , & V_19 -> V_12 ) ;
F_19 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
switch ( V_9 -> V_47 ) {
case V_73 :
case V_71 :
case V_76 :
F_52 ( V_19 -> V_3 , L_97 ,
V_9 -> V_13 ) ;
if ( ! F_184 ( V_14 , V_9 ) ) {
F_52 ( V_19 -> V_3 ,
L_98 ) ;
F_182 ( V_12 , V_9 -> V_13 ) ;
}
break;
default:
break;
}
}
}
void F_186 ( struct V_18 * V_12 )
{
F_130 ( V_12 -> V_3 ) ;
F_119 ( V_12 ) ;
F_132 ( V_12 ) ;
F_133 ( & V_12 -> V_97 ) ;
}
static void F_187 ( struct V_18 * V_12 )
{
struct V_21 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
F_88 ( V_201 ) ;
int V_293 = 0 ;
F_28 ( & V_14 -> V_142 ) ;
F_19 (w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
if ( V_9 -> V_169 ) {
F_79 ( V_9 , & V_201 , false ) ;
V_9 -> V_169 = 0 ;
V_293 = 1 ;
}
}
if ( V_293 ) {
if ( V_12 -> V_42 == V_198 )
F_33 ( V_12 ,
V_197 ) ;
F_87 ( V_12 , & V_201 , 0 , false ) ;
if ( V_12 -> V_42 == V_197 )
F_33 ( V_12 ,
V_196 ) ;
}
F_30 ( & V_14 -> V_142 ) ;
}
void F_188 ( struct V_21 * V_14 )
{
struct V_223 * V_19 ;
F_19 (codec, &card->codec_dev_list, list) {
F_187 ( & V_19 -> V_12 ) ;
if ( V_19 -> V_12 . V_42 == V_196 )
F_33 ( & V_19 -> V_12 ,
V_194 ) ;
}
}
