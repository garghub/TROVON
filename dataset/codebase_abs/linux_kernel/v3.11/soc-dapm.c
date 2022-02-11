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
if ( V_65 < V_64 -> V_59 && ! strcmp ( V_49 -> V_13 , V_64 -> V_67 [ V_65 ] ) )
V_49 -> V_61 = 1 ;
else
V_49 -> V_61 = 0 ;
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
if ( V_65 < V_64 -> V_59 && ! strcmp ( V_49 -> V_13 , V_64 -> V_67 [ V_65 ] ) )
V_49 -> V_61 = 1 ;
else
V_49 -> V_61 = 0 ;
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
case V_89 :
V_49 -> V_61 = 1 ;
break;
case V_90 :
case V_91 :
V_49 -> V_61 = 0 ;
break;
}
}
static int F_39 ( struct V_16 * V_12 ,
struct V_8 * V_92 , struct V_8 * V_93 ,
struct V_48 * V_94 , const char * V_95 ,
const struct V_96 * V_97 )
{
struct V_63 * V_64 = (struct V_63 * ) V_97 -> V_57 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_64 -> V_59 ; V_50 ++ ) {
if ( ! ( strcmp ( V_95 , V_64 -> V_67 [ V_50 ] ) ) ) {
F_40 ( & V_94 -> V_98 , & V_12 -> V_14 -> V_99 ) ;
F_40 ( & V_94 -> V_100 , & V_93 -> V_101 ) ;
F_40 ( & V_94 -> V_102 , & V_92 -> V_103 ) ;
V_94 -> V_13 = ( char * ) V_64 -> V_67 [ V_50 ] ;
F_37 ( V_93 , V_94 , 0 ) ;
return 0 ;
}
}
return - V_104 ;
}
static int F_41 ( struct V_16 * V_12 ,
struct V_8 * V_92 , struct V_8 * V_93 ,
struct V_48 * V_94 , const char * V_95 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_93 -> V_105 ; V_50 ++ ) {
if ( ! strcmp ( V_95 , V_93 -> V_56 [ V_50 ] . V_13 ) ) {
F_40 ( & V_94 -> V_98 , & V_12 -> V_14 -> V_99 ) ;
F_40 ( & V_94 -> V_100 , & V_93 -> V_101 ) ;
F_40 ( & V_94 -> V_102 , & V_92 -> V_103 ) ;
V_94 -> V_13 = V_93 -> V_56 [ V_50 ] . V_13 ;
F_37 ( V_93 , V_94 , V_50 ) ;
return 0 ;
}
}
return - V_104 ;
}
static int F_42 ( struct V_16 * V_12 ,
struct V_8 * V_106 ,
const struct V_96 * V_107 ,
struct V_108 * * V_97 )
{
struct V_8 * V_9 ;
int V_50 ;
* V_97 = NULL ;
F_15 (w, &dapm->card->widgets, list) {
if ( V_9 == V_106 || V_9 -> V_12 != V_106 -> V_12 )
continue;
for ( V_50 = 0 ; V_50 < V_9 -> V_105 ; V_50 ++ ) {
if ( & V_9 -> V_56 [ V_50 ] == V_107 ) {
if ( V_9 -> V_109 )
* V_97 = V_9 -> V_109 [ V_50 ] ;
return 1 ;
}
}
}
return 0 ;
}
static void F_43 ( struct V_108 * V_110 )
{
F_7 ( V_110 -> V_111 ) ;
}
static int F_44 ( struct V_8 * V_9 ,
int V_112 , struct V_48 * V_94 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_23 * V_14 = V_12 -> V_14 -> V_23 ;
const char * V_113 ;
T_3 V_114 ;
int V_115 ;
struct V_108 * V_97 ;
struct V_116 * V_117 ;
int V_118 ;
T_3 V_119 ;
bool V_120 , V_121 ;
char * V_122 ;
const char * V_13 ;
int V_39 ;
if ( V_12 -> V_24 )
V_113 = V_12 -> V_24 -> V_123 ;
else
V_113 = NULL ;
if ( V_113 )
V_114 = strlen ( V_113 ) + 1 ;
else
V_114 = 0 ;
V_115 = F_42 ( V_12 , V_9 , & V_9 -> V_56 [ V_112 ] ,
& V_97 ) ;
if ( V_97 ) {
V_117 = V_97 -> V_111 ;
V_118 = V_117 -> V_124 + 1 ;
} else {
V_117 = NULL ;
V_118 = 1 ;
}
V_119 = sizeof( struct V_116 ) +
V_118 * sizeof( struct V_8 * ) ;
V_117 = F_45 ( V_117 , V_119 , V_7 ) ;
if ( V_117 == NULL ) {
F_26 ( V_12 -> V_3 , L_6 ,
V_9 -> V_13 ) ;
return - V_125 ;
}
V_117 -> V_124 = V_118 ;
V_117 -> V_126 [ V_118 - 1 ] = V_9 ;
if ( ! V_97 ) {
if ( V_115 ) {
V_120 = false ;
V_121 = true ;
} else {
switch ( V_9 -> V_19 ) {
case V_51 :
case V_52 :
V_120 = true ;
V_121 = true ;
break;
case V_53 :
V_120 = false ;
V_121 = true ;
break;
case V_62 :
case V_68 :
case V_69 :
V_120 = true ;
V_121 = false ;
break;
default:
F_7 ( V_117 ) ;
return - V_127 ;
}
}
if ( V_120 && V_121 ) {
V_122 = F_46 ( V_7 , L_7 ,
V_9 -> V_13 + V_114 ,
V_9 -> V_56 [ V_112 ] . V_13 ) ;
if ( V_122 == NULL ) {
F_7 ( V_117 ) ;
return - V_125 ;
}
V_13 = V_122 ;
} else if ( V_120 ) {
V_122 = NULL ;
V_13 = V_9 -> V_13 + V_114 ;
} else {
V_122 = NULL ;
V_13 = V_9 -> V_56 [ V_112 ] . V_13 ;
}
V_97 = F_47 ( & V_9 -> V_56 [ V_112 ] , V_117 , V_13 ,
V_113 ) ;
V_97 -> V_128 = F_43 ;
F_7 ( V_122 ) ;
V_39 = F_48 ( V_14 , V_97 ) ;
if ( V_39 < 0 ) {
F_26 ( V_12 -> V_3 ,
L_8 ,
V_9 -> V_13 , V_13 , V_39 ) ;
F_7 ( V_117 ) ;
return V_39 ;
}
}
V_97 -> V_111 = V_117 ;
V_9 -> V_109 [ V_112 ] = V_97 ;
V_94 -> V_97 = V_97 ;
return 0 ;
}
static int F_49 ( struct V_8 * V_9 )
{
int V_50 , V_39 ;
struct V_48 * V_94 ;
for ( V_50 = 0 ; V_50 < V_9 -> V_105 ; V_50 ++ ) {
F_15 (path, &w->sources, list_sink) {
if ( V_94 -> V_13 != ( char * ) V_9 -> V_56 [ V_50 ] . V_13 )
continue;
if ( V_9 -> V_109 [ V_50 ] ) {
V_94 -> V_97 = V_9 -> V_109 [ V_50 ] ;
continue;
}
V_39 = F_44 ( V_9 , V_50 , V_94 ) ;
if ( V_39 < 0 )
return V_39 ;
}
}
return 0 ;
}
static int F_50 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_48 * V_94 ;
int V_39 ;
if ( V_9 -> V_105 != 1 ) {
F_26 ( V_12 -> V_3 ,
L_9 ,
V_9 -> V_13 ) ;
return - V_127 ;
}
if ( F_9 ( & V_9 -> V_101 ) ) {
F_26 ( V_12 -> V_3 , L_10 , V_9 -> V_13 ) ;
return - V_127 ;
}
V_94 = F_51 ( & V_9 -> V_101 , struct V_48 ,
V_100 ) ;
V_39 = F_44 ( V_9 , 0 , V_94 ) ;
if ( V_39 < 0 )
return V_39 ;
F_15 (path, &w->sources, list_sink)
V_94 -> V_97 = V_9 -> V_109 [ 0 ] ;
return 0 ;
}
static int F_52 ( struct V_8 * V_9 )
{
if ( V_9 -> V_105 )
F_26 ( V_9 -> V_12 -> V_3 ,
L_11 , V_9 -> V_13 ) ;
return 0 ;
}
static void F_53 ( struct V_16 * V_12 ,
struct V_129 * V_130 )
{
struct V_48 * V_49 ;
F_15 (p, sink, list_source) {
if ( V_49 -> V_131 ) {
V_49 -> V_131 = 0 ;
F_53 ( V_12 , & V_49 -> V_130 -> V_103 ) ;
}
}
}
static void F_54 ( struct V_16 * V_12 ,
struct V_129 * V_132 )
{
struct V_48 * V_49 ;
F_15 (p, source, list_sink) {
if ( V_49 -> V_131 ) {
V_49 -> V_131 = 0 ;
F_54 ( V_12 , & V_49 -> V_132 -> V_101 ) ;
}
}
}
static int F_55 ( struct V_8 * V_133 )
{
int V_42 = F_56 ( V_133 -> V_12 -> V_14 -> V_23 ) ;
switch ( V_42 ) {
case V_134 :
case V_135 :
if ( V_133 -> V_136 )
F_57 ( V_133 -> V_12 -> V_3 , L_12 ,
V_133 -> V_13 ) ;
return V_133 -> V_136 ;
default:
return 1 ;
}
}
static int F_58 ( struct V_116 * * V_98 ,
struct V_8 * V_9 )
{
struct V_116 * V_117 ;
int V_119 , V_118 , V_50 ;
if ( * V_98 == NULL )
return - V_127 ;
V_117 = * V_98 ;
for ( V_50 = 0 ; V_50 < V_117 -> V_124 ; V_50 ++ ) {
if ( V_117 -> V_126 [ V_50 ] == V_9 )
return 0 ;
}
V_118 = V_117 -> V_124 + 1 ;
V_119 = sizeof( struct V_116 ) +
V_118 * sizeof( struct V_8 * ) ;
* V_98 = F_45 ( V_117 , V_119 , V_7 ) ;
if ( * V_98 == NULL ) {
F_26 ( V_9 -> V_12 -> V_3 , L_6 ,
V_9 -> V_13 ) ;
return - V_125 ;
}
V_117 = * V_98 ;
F_57 ( V_9 -> V_12 -> V_3 , L_13 ,
V_9 -> V_13 , V_117 -> V_124 ) ;
V_117 -> V_126 [ V_117 -> V_124 ] = V_9 ;
V_117 -> V_124 ++ ;
return 1 ;
}
static int F_59 ( struct V_8 * V_133 ,
struct V_116 * * V_98 )
{
struct V_48 * V_94 ;
int V_137 = 0 ;
if ( V_133 -> V_29 >= 0 )
return V_133 -> V_29 ;
F_60 ( V_133 , V_138 ) ;
switch ( V_133 -> V_19 ) {
case V_78 :
case V_79 :
case V_80 :
return 0 ;
default:
break;
}
switch ( V_133 -> V_19 ) {
case V_73 :
case V_82 :
case V_84 :
if ( V_133 -> V_139 ) {
V_133 -> V_29 = F_55 ( V_133 ) ;
return V_133 -> V_29 ;
}
default:
break;
}
if ( V_133 -> V_140 ) {
if ( V_133 -> V_19 == V_21 && ! V_133 -> V_141 ) {
V_133 -> V_29 = F_55 ( V_133 ) ;
return V_133 -> V_29 ;
}
if ( V_133 -> V_19 == V_85 ||
V_133 -> V_19 == V_87 ||
( V_133 -> V_19 == V_88 &&
! F_9 ( & V_133 -> V_101 ) ) ) {
V_133 -> V_29 = F_55 ( V_133 ) ;
return V_133 -> V_29 ;
}
}
F_15 (path, &widget->sinks, list_source) {
F_60 ( V_133 , V_142 ) ;
if ( V_94 -> V_143 )
continue;
if ( V_94 -> V_144 )
return 1 ;
if ( V_94 -> V_131 )
continue;
F_61 ( V_133 , V_94 ) ;
if ( V_94 -> V_130 && V_94 -> V_61 ) {
V_94 -> V_131 = 1 ;
V_94 -> V_144 = 1 ;
if ( V_98 ) {
int V_145 ;
V_145 = F_58 ( V_98 , V_94 -> V_130 ) ;
if ( V_145 < 0 ) {
F_26 ( V_133 -> V_12 -> V_3 ,
L_14 ,
V_133 -> V_13 ) ;
V_94 -> V_144 = 0 ;
return V_137 ;
}
}
V_137 += F_59 ( V_94 -> V_130 , V_98 ) ;
V_94 -> V_144 = 0 ;
}
}
V_133 -> V_29 = V_137 ;
return V_137 ;
}
static int F_62 ( struct V_8 * V_133 ,
struct V_116 * * V_98 )
{
struct V_48 * V_94 ;
int V_137 = 0 ;
if ( V_133 -> V_28 >= 0 )
return V_133 -> V_28 ;
F_60 ( V_133 , V_138 ) ;
switch ( V_133 -> V_19 ) {
case V_78 :
case V_79 :
case V_80 :
return 0 ;
default:
break;
}
switch ( V_133 -> V_19 ) {
case V_75 :
case V_81 :
case V_83 :
if ( V_133 -> V_139 ) {
V_133 -> V_28 = F_55 ( V_133 ) ;
return V_133 -> V_28 ;
}
default:
break;
}
if ( V_133 -> V_140 ) {
if ( V_133 -> V_19 == V_20 && ! V_133 -> V_141 ) {
V_133 -> V_28 = F_55 ( V_133 ) ;
return V_133 -> V_28 ;
}
if ( V_133 -> V_19 == V_77 ) {
V_133 -> V_28 = F_55 ( V_133 ) ;
return V_133 -> V_28 ;
}
if ( V_133 -> V_19 == V_86 ||
( V_133 -> V_19 == V_88 &&
! F_9 ( & V_133 -> V_103 ) ) ) {
V_133 -> V_28 = F_55 ( V_133 ) ;
return V_133 -> V_28 ;
}
if ( V_133 -> V_19 == V_74 ) {
V_133 -> V_28 = F_55 ( V_133 ) ;
return V_133 -> V_28 ;
}
}
F_15 (path, &widget->sources, list_sink) {
F_60 ( V_133 , V_142 ) ;
if ( V_94 -> V_143 )
continue;
if ( V_94 -> V_144 )
return 1 ;
if ( V_94 -> V_131 )
continue;
F_63 ( V_133 , V_94 ) ;
if ( V_94 -> V_132 && V_94 -> V_61 ) {
V_94 -> V_131 = 1 ;
V_94 -> V_144 = 1 ;
if ( V_98 ) {
int V_145 ;
V_145 = F_58 ( V_98 , V_94 -> V_132 ) ;
if ( V_145 < 0 ) {
F_26 ( V_133 -> V_12 -> V_3 ,
L_14 ,
V_133 -> V_13 ) ;
V_94 -> V_144 = 0 ;
return V_137 ;
}
}
V_137 += F_62 ( V_94 -> V_132 , V_98 ) ;
V_94 -> V_144 = 0 ;
}
}
V_133 -> V_28 = V_137 ;
return V_137 ;
}
int F_64 ( struct V_146 * V_147 , int V_148 ,
struct V_116 * * V_98 )
{
struct V_17 * V_14 = V_147 -> V_14 ;
int V_99 ;
F_65 ( & V_14 -> V_18 , V_149 ) ;
F_22 ( V_14 ) ;
if ( V_148 == V_150 ) {
V_99 = F_59 ( V_147 -> V_151 , V_98 ) ;
F_53 ( & V_14 -> V_12 ,
& V_147 -> V_151 -> V_103 ) ;
} else {
V_99 = F_62 ( V_147 -> V_152 , V_98 ) ;
F_54 ( & V_14 -> V_12 ,
& V_147 -> V_152 -> V_101 ) ;
}
F_66 ( V_99 , V_148 ) ;
F_16 ( & V_14 -> V_18 ) ;
return V_99 ;
}
int F_67 ( struct V_8 * V_9 ,
struct V_108 * V_97 , int V_153 )
{
unsigned int V_31 ;
if ( F_68 ( V_153 ) )
V_31 = V_9 -> V_154 ;
else
V_31 = V_9 -> V_155 ;
F_32 ( V_9 , - ( V_9 -> V_30 + 1 ) ,
V_9 -> V_34 << V_9 -> V_58 , V_31 << V_9 -> V_58 ) ;
return 0 ;
}
int F_69 ( struct V_8 * V_9 ,
struct V_108 * V_97 , int V_153 )
{
int V_39 ;
if ( F_68 ( V_153 ) ) {
if ( V_9 -> V_60 & V_156 ) {
V_39 = F_70 ( V_9 -> V_157 , false ) ;
if ( V_39 != 0 )
F_71 ( V_9 -> V_12 -> V_3 ,
L_15 ,
V_9 -> V_13 , V_39 ) ;
}
return F_72 ( V_9 -> V_157 ) ;
} else {
if ( V_9 -> V_60 & V_156 ) {
V_39 = F_70 ( V_9 -> V_157 , true ) ;
if ( V_39 != 0 )
F_71 ( V_9 -> V_12 -> V_3 ,
L_16 ,
V_9 -> V_13 , V_39 ) ;
}
return F_73 ( V_9 -> V_157 , V_9 -> V_58 ) ;
}
}
int F_74 ( struct V_8 * V_9 ,
struct V_108 * V_97 , int V_153 )
{
if ( ! V_9 -> V_158 )
return - V_159 ;
#ifdef F_75
if ( F_68 ( V_153 ) ) {
return F_76 ( V_9 -> V_158 ) ;
} else {
F_77 ( V_9 -> V_158 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_78 ( struct V_8 * V_9 )
{
if ( V_9 -> V_27 )
return V_9 -> V_160 ;
if ( V_9 -> V_161 )
V_9 -> V_160 = 1 ;
else
V_9 -> V_160 = V_9 -> V_162 ( V_9 ) ;
V_9 -> V_27 = true ;
return V_9 -> V_160 ;
}
static int F_79 ( struct V_8 * V_9 )
{
int V_163 , V_44 ;
F_60 ( V_9 , V_164 ) ;
V_163 = F_62 ( V_9 , NULL ) ;
F_54 ( V_9 -> V_12 , & V_9 -> V_101 ) ;
V_44 = F_59 ( V_9 , NULL ) ;
F_53 ( V_9 -> V_12 , & V_9 -> V_103 ) ;
return V_44 != 0 && V_163 != 0 ;
}
static int F_80 ( struct V_8 * V_9 )
{
int V_163 ;
F_60 ( V_9 , V_164 ) ;
if ( V_9 -> V_139 ) {
V_163 = F_62 ( V_9 , NULL ) ;
F_54 ( V_9 -> V_12 , & V_9 -> V_101 ) ;
return V_163 != 0 ;
} else {
return F_79 ( V_9 ) ;
}
}
static int F_81 ( struct V_8 * V_9 )
{
int V_44 ;
F_60 ( V_9 , V_164 ) ;
if ( V_9 -> V_139 ) {
V_44 = F_59 ( V_9 , NULL ) ;
F_53 ( V_9 -> V_12 , & V_9 -> V_103 ) ;
return V_44 != 0 ;
} else {
return F_79 ( V_9 ) ;
}
}
static int F_82 ( struct V_8 * V_9 )
{
struct V_48 * V_94 ;
F_60 ( V_9 , V_164 ) ;
F_15 (path, &w->sinks, list_source) {
F_60 ( V_9 , V_142 ) ;
if ( V_94 -> V_143 )
continue;
if ( V_94 -> V_140 &&
! V_94 -> V_140 ( V_94 -> V_132 , V_94 -> V_130 ) )
continue;
if ( ! V_94 -> V_130 )
continue;
if ( F_78 ( V_94 -> V_130 ) )
return 1 ;
}
return 0 ;
}
static int F_83 ( struct V_8 * V_9 )
{
return 1 ;
}
static int F_84 ( struct V_8 * V_165 ,
struct V_8 * V_166 ,
bool V_167 )
{
int * V_168 ;
if ( V_167 )
V_168 = V_169 ;
else
V_168 = V_170 ;
if ( V_168 [ V_165 -> V_19 ] != V_168 [ V_166 -> V_19 ] )
return V_168 [ V_165 -> V_19 ] - V_168 [ V_166 -> V_19 ] ;
if ( V_165 -> V_171 != V_166 -> V_171 ) {
if ( V_167 )
return V_165 -> V_171 - V_166 -> V_171 ;
else
return V_166 -> V_171 - V_165 -> V_171 ;
}
if ( V_165 -> V_30 != V_166 -> V_30 )
return V_165 -> V_30 - V_166 -> V_30 ;
if ( V_165 -> V_12 != V_166 -> V_12 )
return ( unsigned long ) V_165 -> V_12 - ( unsigned long ) V_166 -> V_12 ;
return 0 ;
}
static void F_85 ( struct V_8 * V_172 ,
struct V_129 * V_98 ,
bool V_167 )
{
struct V_8 * V_9 ;
F_15 (w, list, power_list)
if ( F_84 ( V_172 , V_9 , V_167 ) < 0 ) {
F_12 ( & V_172 -> V_173 , & V_9 -> V_173 ) ;
return;
}
F_12 ( & V_172 -> V_173 , V_98 ) ;
}
static void F_86 ( struct V_16 * V_12 ,
struct V_8 * V_9 , int V_153 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
const char * V_174 ;
int V_175 , V_39 ;
switch ( V_153 ) {
case V_176 :
V_174 = L_17 ;
V_175 = 1 ;
break;
case V_177 :
V_174 = L_18 ;
V_175 = 1 ;
break;
case V_178 :
V_174 = L_19 ;
V_175 = 0 ;
break;
case V_179 :
V_174 = L_20 ;
V_175 = 0 ;
break;
case V_180 :
V_174 = L_21 ;
V_175 = 1 ;
break;
case V_181 :
V_174 = L_22 ;
V_175 = 0 ;
break;
default:
F_20 () ;
return;
}
if ( V_9 -> V_175 != V_175 )
return;
if ( V_9 -> V_153 && ( V_9 -> V_182 & V_153 ) ) {
F_4 ( V_12 -> V_3 , V_14 -> V_1 , L_23 ,
V_9 -> V_13 , V_174 ) ;
F_87 ( V_9 , V_153 ) ;
V_39 = V_9 -> V_153 ( V_9 , NULL , V_153 ) ;
F_88 ( V_9 , V_153 ) ;
if ( V_39 < 0 )
F_26 ( V_12 -> V_3 , L_24 ,
V_174 , V_9 -> V_13 , V_39 ) ;
}
}
static void F_89 ( struct V_16 * V_12 ,
struct V_129 * V_183 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
int V_30 , V_175 ;
unsigned int V_35 = 0 ;
unsigned int V_34 = 0 ;
unsigned int V_184 ;
V_30 = F_51 ( V_183 , struct V_8 ,
V_173 ) -> V_30 ;
F_15 (w, pending, power_list) {
V_184 = 1 << V_9 -> V_58 ;
F_90 ( V_30 != V_9 -> V_30 ) ;
if ( V_9 -> V_60 )
V_175 = ! V_9 -> V_175 ;
else
V_175 = V_9 -> V_175 ;
V_34 |= V_184 ;
if ( V_175 )
V_35 |= V_184 ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_25 ,
V_9 -> V_13 , V_30 , V_35 , V_34 ) ;
F_86 ( V_12 , V_9 , V_176 ) ;
F_86 ( V_12 , V_9 , V_178 ) ;
}
if ( V_30 >= 0 ) {
V_9 = F_51 ( V_183 , struct V_8 ,
V_173 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_26 ,
V_35 , V_34 , V_30 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_32 ( V_9 , V_30 , V_34 , V_35 ) ;
}
F_15 (w, pending, power_list) {
F_86 ( V_12 , V_9 , V_177 ) ;
F_86 ( V_12 , V_9 , V_179 ) ;
}
}
static void F_91 ( struct V_16 * V_12 ,
struct V_129 * V_98 , int V_153 , bool V_167 )
{
struct V_8 * V_9 , * V_185 ;
F_92 ( V_183 ) ;
int V_186 = - 1 ;
int V_187 = - 1 ;
int V_188 = V_189 ;
struct V_16 * V_190 = NULL ;
int V_39 , V_50 ;
int * V_168 ;
if ( V_167 )
V_168 = V_169 ;
else
V_168 = V_170 ;
F_93 (w, n, list, power_list) {
V_39 = 0 ;
if ( V_168 [ V_9 -> V_19 ] != V_186 || V_9 -> V_30 != V_188 ||
V_9 -> V_12 != V_190 || V_9 -> V_171 != V_187 ) {
if ( ! F_9 ( & V_183 ) )
F_89 ( V_190 , & V_183 ) ;
if ( V_190 && V_190 -> V_191 ) {
for ( V_50 = 0 ; V_50 < F_94 ( V_169 ) ; V_50 ++ )
if ( V_168 [ V_50 ] == V_186 )
V_190 -> V_191 ( V_190 ,
V_50 ,
V_187 ) ;
}
F_95 ( & V_183 ) ;
V_186 = - 1 ;
V_187 = V_192 ;
V_188 = V_189 ;
V_190 = NULL ;
}
switch ( V_9 -> V_19 ) {
case V_90 :
if ( ! V_9 -> V_153 )
F_96 ( V_9 , V_185 , V_98 ,
V_173 ) ;
if ( V_153 == V_193 )
V_39 = V_9 -> V_153 ( V_9 ,
NULL , V_176 ) ;
else if ( V_153 == V_194 )
V_39 = V_9 -> V_153 ( V_9 ,
NULL , V_178 ) ;
break;
case V_91 :
if ( ! V_9 -> V_153 )
F_96 ( V_9 , V_185 , V_98 ,
V_173 ) ;
if ( V_153 == V_193 )
V_39 = V_9 -> V_153 ( V_9 ,
NULL , V_177 ) ;
else if ( V_153 == V_194 )
V_39 = V_9 -> V_153 ( V_9 ,
NULL , V_179 ) ;
break;
default:
V_186 = V_168 [ V_9 -> V_19 ] ;
V_187 = V_9 -> V_171 ;
V_188 = V_9 -> V_30 ;
V_190 = V_9 -> V_12 ;
F_97 ( & V_9 -> V_173 , & V_183 ) ;
break;
}
if ( V_39 < 0 )
F_26 ( V_9 -> V_12 -> V_3 ,
L_27 , V_39 ) ;
}
if ( ! F_9 ( & V_183 ) )
F_89 ( V_190 , & V_183 ) ;
if ( V_190 && V_190 -> V_191 ) {
for ( V_50 = 0 ; V_50 < F_94 ( V_169 ) ; V_50 ++ )
if ( V_168 [ V_50 ] == V_186 )
V_190 -> V_191 ( V_190 ,
V_50 , V_187 ) ;
}
}
static void F_98 ( struct V_16 * V_12 )
{
struct V_195 * V_196 = V_12 -> V_196 ;
struct V_8 * V_9 ;
int V_39 ;
if ( ! V_196 )
return;
V_9 = V_196 -> V_133 ;
if ( V_9 -> V_153 &&
( V_9 -> V_182 & V_197 ) ) {
V_39 = V_9 -> V_153 ( V_9 , V_196 -> V_97 , V_197 ) ;
if ( V_39 != 0 )
F_26 ( V_12 -> V_3 , L_28 ,
V_9 -> V_13 , V_39 ) ;
}
V_39 = F_32 ( V_9 , V_196 -> V_30 , V_196 -> V_34 ,
V_196 -> V_31 ) ;
if ( V_39 < 0 )
F_26 ( V_12 -> V_3 , L_29 ,
V_9 -> V_13 , V_39 ) ;
if ( V_9 -> V_153 &&
( V_9 -> V_182 & V_198 ) ) {
V_39 = V_9 -> V_153 ( V_9 , V_196 -> V_97 , V_198 ) ;
if ( V_39 != 0 )
F_26 ( V_12 -> V_3 , L_30 ,
V_9 -> V_13 , V_39 ) ;
}
}
static void F_99 ( void * V_199 , T_4 V_200 )
{
struct V_16 * V_201 = V_199 ;
int V_39 ;
if ( V_201 -> V_46 == V_202 &&
V_201 -> V_203 != V_202 ) {
if ( V_201 -> V_3 )
F_100 ( V_201 -> V_3 ) ;
V_39 = F_34 ( V_201 , V_204 ) ;
if ( V_39 != 0 )
F_26 ( V_201 -> V_3 ,
L_31 , V_39 ) ;
}
if ( V_201 -> V_46 != V_201 -> V_203 ) {
V_39 = F_34 ( V_201 , V_205 ) ;
if ( V_39 != 0 )
F_26 ( V_201 -> V_3 ,
L_32 , V_39 ) ;
}
}
static void F_101 ( void * V_199 , T_4 V_200 )
{
struct V_16 * V_201 = V_199 ;
int V_39 ;
if ( V_201 -> V_46 == V_205 &&
( V_201 -> V_203 == V_204 ||
V_201 -> V_203 == V_202 ) ) {
V_39 = F_34 ( V_201 , V_204 ) ;
if ( V_39 != 0 )
F_26 ( V_201 -> V_3 , L_33 ,
V_39 ) ;
}
if ( V_201 -> V_46 == V_204 &&
V_201 -> V_203 == V_202 ) {
V_39 = F_34 ( V_201 , V_202 ) ;
if ( V_39 != 0 )
F_26 ( V_201 -> V_3 , L_34 ,
V_39 ) ;
if ( V_201 -> V_3 )
F_102 ( V_201 -> V_3 ) ;
}
if ( V_201 -> V_46 == V_205 &&
V_201 -> V_203 == V_206 ) {
V_39 = F_34 ( V_201 , V_206 ) ;
if ( V_39 != 0 )
F_26 ( V_201 -> V_3 , L_35 ,
V_39 ) ;
}
}
static void F_103 ( struct V_8 * V_207 ,
bool V_175 , bool V_61 )
{
if ( ! V_61 )
return;
if ( V_175 != V_207 -> V_175 )
F_10 ( V_207 , L_36 ) ;
}
static void F_104 ( struct V_8 * V_9 , bool V_175 ,
struct V_129 * V_208 ,
struct V_129 * V_209 )
{
struct V_48 * V_94 ;
if ( V_9 -> V_175 == V_175 )
return;
F_105 ( V_9 , V_175 ) ;
F_15 (path, &w->sources, list_sink) {
if ( V_94 -> V_132 ) {
F_103 ( V_94 -> V_132 , V_175 ,
V_94 -> V_61 ) ;
}
}
switch ( V_9 -> V_19 ) {
case V_78 :
case V_79 :
case V_80 :
break;
default:
F_15 (path, &w->sinks, list_source) {
if ( V_94 -> V_130 ) {
F_103 ( V_94 -> V_130 , V_175 ,
V_94 -> V_61 ) ;
}
}
break;
}
if ( V_175 )
F_85 ( V_9 , V_208 , true ) ;
else
F_85 ( V_9 , V_209 , false ) ;
V_9 -> V_175 = V_175 ;
}
static void F_106 ( struct V_8 * V_9 ,
struct V_129 * V_208 ,
struct V_129 * V_209 )
{
int V_175 ;
switch ( V_9 -> V_19 ) {
case V_90 :
F_85 ( V_9 , V_209 , false ) ;
break;
case V_91 :
F_85 ( V_9 , V_208 , true ) ;
break;
default:
V_175 = F_78 ( V_9 ) ;
F_104 ( V_9 , V_175 , V_208 , V_209 ) ;
break;
}
}
static int F_107 ( struct V_16 * V_12 , int V_153 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
struct V_16 * V_201 ;
F_92 ( V_208 ) ;
F_92 ( V_209 ) ;
F_108 ( V_210 ) ;
enum V_41 V_211 ;
F_109 ( V_14 ) ;
F_15 (d, &card->dapm_list, list) {
if ( V_201 -> V_212 )
V_201 -> V_203 = V_202 ;
else
V_201 -> V_203 = V_204 ;
}
F_22 ( V_14 ) ;
F_15 (w, &card->dapm_dirty, dirty) {
F_106 ( V_9 , & V_208 , & V_209 ) ;
}
F_15 (w, &card->widgets, list) {
switch ( V_9 -> V_19 ) {
case V_90 :
case V_91 :
break;
default:
F_110 ( & V_9 -> V_10 ) ;
break;
}
if ( V_9 -> V_175 ) {
V_201 = V_9 -> V_12 ;
switch ( V_9 -> V_19 ) {
case V_74 :
break;
case V_78 :
case V_79 :
case V_80 :
case V_76 :
if ( V_201 -> V_203 < V_204 )
V_201 -> V_203 = V_204 ;
break;
default:
V_201 -> V_203 = V_206 ;
break;
}
}
}
V_211 = V_202 ;
F_15 (d, &card->dapm_list, list)
if ( V_201 -> V_203 > V_211 )
V_211 = V_201 -> V_203 ;
F_15 (d, &card->dapm_list, list)
if ( ! V_201 -> V_212 )
V_201 -> V_203 = V_211 ;
F_111 ( V_14 ) ;
F_15 (d, &dapm->card->dapm_list, list)
F_112 ( F_99 , V_201 ,
& V_210 ) ;
F_113 ( & V_210 ) ;
F_15 (w, &down_list, power_list) {
F_86 ( V_12 , V_9 , V_181 ) ;
}
F_15 (w, &up_list, power_list) {
F_86 ( V_12 , V_9 , V_180 ) ;
}
F_91 ( V_12 , & V_209 , V_153 , false ) ;
F_98 ( V_12 ) ;
F_91 ( V_12 , & V_208 , V_153 , true ) ;
F_15 (d, &dapm->card->dapm_list, list)
F_112 ( F_101 , V_201 ,
& V_210 ) ;
F_113 ( & V_210 ) ;
F_15 (d, &card->dapm_list, list) {
if ( V_201 -> V_213 )
V_201 -> V_213 ( V_201 , V_153 ) ;
}
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_37 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_114 ( V_14 ) ;
return 0 ;
}
static T_5 F_115 ( struct V_214 * V_214 ,
char T_6 * V_215 ,
T_3 V_216 , T_7 * V_217 )
{
struct V_8 * V_9 = V_214 -> V_111 ;
char * V_5 ;
int V_163 , V_44 ;
T_5 V_39 ;
struct V_48 * V_49 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_125 ;
V_163 = F_62 ( V_9 , NULL ) ;
F_54 ( V_9 -> V_12 , & V_9 -> V_101 ) ;
V_44 = F_59 ( V_9 , NULL ) ;
F_53 ( V_9 -> V_12 , & V_9 -> V_103 ) ;
V_39 = snprintf ( V_5 , V_6 , L_38 ,
V_9 -> V_13 , V_9 -> V_175 ? L_39 : L_40 ,
V_9 -> V_161 ? L_41 : L_42 , V_163 , V_44 ) ;
if ( V_9 -> V_30 >= 0 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 ,
L_43 ,
V_9 -> V_30 , V_9 -> V_30 , V_9 -> V_58 ) ;
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 , L_44 ) ;
if ( V_9 -> V_218 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 , L_45 ,
V_9 -> V_218 ,
V_9 -> V_139 ? L_46 : L_47 ) ;
F_15 (p, &w->sources, list_sink) {
if ( V_49 -> V_140 && ! V_49 -> V_140 ( V_9 , V_49 -> V_130 ) )
continue;
if ( V_49 -> V_61 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 ,
L_48 ,
V_49 -> V_13 ? V_49 -> V_13 : L_49 ,
V_49 -> V_132 -> V_13 ) ;
}
F_15 (p, &w->sinks, list_source) {
if ( V_49 -> V_140 && ! V_49 -> V_140 ( V_9 , V_49 -> V_130 ) )
continue;
if ( V_49 -> V_61 )
V_39 += snprintf ( V_5 + V_39 , V_6 - V_39 ,
L_50 ,
V_49 -> V_13 ? V_49 -> V_13 : L_49 ,
V_49 -> V_130 -> V_13 ) ;
}
V_39 = F_116 ( V_215 , V_216 , V_217 , V_5 , V_39 ) ;
F_7 ( V_5 ) ;
return V_39 ;
}
static T_5 F_117 ( struct V_214 * V_214 , char T_6 * V_215 ,
T_3 V_216 , T_7 * V_217 )
{
struct V_16 * V_12 = V_214 -> V_111 ;
char * V_42 ;
switch ( V_12 -> V_46 ) {
case V_206 :
V_42 = L_51 ;
break;
case V_205 :
V_42 = L_52 ;
break;
case V_204 :
V_42 = L_53 ;
break;
case V_202 :
V_42 = L_54 ;
break;
default:
F_20 () ;
V_42 = L_55 ;
break;
}
return F_116 ( V_215 , V_216 , V_217 , V_42 ,
strlen ( V_42 ) ) ;
}
void F_118 ( struct V_16 * V_12 ,
struct V_219 * V_220 )
{
struct V_219 * V_201 ;
V_12 -> V_221 = F_119 ( L_56 , V_220 ) ;
if ( ! V_12 -> V_221 ) {
F_71 ( V_12 -> V_3 ,
L_57 ) ;
return;
}
V_201 = F_120 ( L_58 , 0444 ,
V_12 -> V_221 , V_12 ,
& V_222 ) ;
if ( ! V_201 )
F_71 ( V_12 -> V_3 ,
L_59 ) ;
}
static void F_121 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_219 * V_201 ;
if ( ! V_12 -> V_221 || ! V_9 -> V_13 )
return;
V_201 = F_120 ( V_9 -> V_13 , 0444 ,
V_12 -> V_221 , V_9 ,
& V_223 ) ;
if ( ! V_201 )
F_71 ( V_9 -> V_12 -> V_3 ,
L_60 ,
V_9 -> V_13 ) ;
}
static void F_122 ( struct V_16 * V_12 )
{
F_123 ( V_12 -> V_221 ) ;
}
void F_118 ( struct V_16 * V_12 ,
struct V_219 * V_220 )
{
}
static inline void F_121 ( struct V_8 * V_9 )
{
}
static inline void F_122 ( struct V_16 * V_12 )
{
}
static int F_124 ( struct V_8 * V_133 ,
struct V_108 * V_97 , int V_224 , struct V_63 * V_64 )
{
struct V_48 * V_94 ;
int V_225 = 0 ;
if ( V_133 -> V_19 != V_62 &&
V_133 -> V_19 != V_68 &&
V_133 -> V_19 != V_69 )
return - V_104 ;
F_15 (path, &widget->dapm->card->paths, list) {
if ( V_94 -> V_97 != V_97 )
continue;
if ( ! V_94 -> V_13 || ! V_64 -> V_67 [ V_224 ] )
continue;
V_225 = 1 ;
if ( ! ( strcmp ( V_94 -> V_13 , V_64 -> V_67 [ V_224 ] ) ) ) {
V_94 -> V_61 = 1 ;
F_10 ( V_94 -> V_132 , L_61 ) ;
} else {
if ( V_94 -> V_61 )
F_10 ( V_94 -> V_132 ,
L_62 ) ;
V_94 -> V_61 = 0 ;
}
}
if ( V_225 ) {
F_10 ( V_133 , L_63 ) ;
F_107 ( V_133 -> V_12 , V_226 ) ;
}
return V_225 ;
}
int F_125 ( struct V_8 * V_133 ,
struct V_108 * V_97 , int V_224 , struct V_63 * V_64 )
{
struct V_17 * V_14 = V_133 -> V_12 -> V_14 ;
int V_39 ;
F_65 ( & V_14 -> V_18 , V_149 ) ;
V_39 = F_124 ( V_133 , V_97 , V_224 , V_64 ) ;
F_16 ( & V_14 -> V_18 ) ;
if ( V_39 > 0 )
F_126 ( V_133 ) ;
return V_39 ;
}
static int F_127 ( struct V_8 * V_133 ,
struct V_108 * V_97 , int V_61 )
{
struct V_48 * V_94 ;
int V_225 = 0 ;
if ( V_133 -> V_19 != V_52 &&
V_133 -> V_19 != V_53 &&
V_133 -> V_19 != V_51 )
return - V_104 ;
F_15 (path, &widget->dapm->card->paths, list) {
if ( V_94 -> V_97 != V_97 )
continue;
V_225 = 1 ;
V_94 -> V_61 = V_61 ;
F_10 ( V_94 -> V_132 , L_64 ) ;
}
if ( V_225 ) {
F_10 ( V_133 , L_65 ) ;
F_107 ( V_133 -> V_12 , V_226 ) ;
}
return V_225 ;
}
int F_128 ( struct V_8 * V_133 ,
struct V_108 * V_97 , int V_61 )
{
struct V_17 * V_14 = V_133 -> V_12 -> V_14 ;
int V_39 ;
F_65 ( & V_14 -> V_18 , V_149 ) ;
V_39 = F_127 ( V_133 , V_97 , V_61 ) ;
F_16 ( & V_14 -> V_18 ) ;
if ( V_39 > 0 )
F_126 ( V_133 ) ;
return V_39 ;
}
static T_5 F_129 ( struct V_2 * V_3 ,
struct V_227 * V_228 , char * V_5 )
{
struct V_229 * V_230 = F_130 ( V_3 ) ;
struct V_231 * V_24 = V_230 -> V_24 ;
struct V_8 * V_9 ;
int V_216 = 0 ;
char * V_232 = L_66 ;
F_15 (w, &codec->card->widgets, list) {
if ( V_9 -> V_12 != & V_24 -> V_12 )
continue;
switch ( V_9 -> V_19 ) {
case V_85 :
case V_86 :
case V_87 :
case V_88 :
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
V_216 += sprintf ( V_5 + V_216 , L_67 ,
V_9 -> V_13 , V_9 -> V_175 ? L_39 : L_40 ) ;
break;
default:
break;
}
}
switch ( V_24 -> V_12 . V_46 ) {
case V_206 :
V_232 = L_39 ;
break;
case V_205 :
V_232 = L_68 ;
break;
case V_204 :
V_232 = L_69 ;
break;
case V_202 :
V_232 = L_40 ;
break;
}
V_216 += sprintf ( V_5 + V_216 , L_70 , V_232 ) ;
return V_216 ;
}
int F_131 ( struct V_2 * V_3 )
{
return F_132 ( V_3 , & V_233 ) ;
}
static void F_133 ( struct V_2 * V_3 )
{
F_134 ( V_3 , & V_233 ) ;
}
static void F_135 ( struct V_48 * V_94 )
{
F_136 ( & V_94 -> V_100 ) ;
F_136 ( & V_94 -> V_102 ) ;
F_136 ( & V_94 -> V_98 ) ;
F_7 ( V_94 ) ;
}
static void F_137 ( struct V_16 * V_12 )
{
struct V_8 * V_9 , * V_234 ;
struct V_48 * V_49 , * V_235 ;
F_93 (w, next_w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
F_136 ( & V_9 -> V_98 ) ;
F_93 (p, next_p, &w->sources, list_sink)
F_135 ( V_49 ) ;
F_93 (p, next_p, &w->sinks, list_source)
F_135 ( V_49 ) ;
F_7 ( V_9 -> V_109 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
}
static struct V_8 * F_138 (
struct V_16 * V_12 , const char * V_236 ,
bool V_237 )
{
struct V_8 * V_9 ;
struct V_8 * V_238 = NULL ;
F_15 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_9 -> V_13 , V_236 ) ) {
if ( V_9 -> V_12 == V_12 )
return V_9 ;
else
V_238 = V_9 ;
}
}
if ( V_237 )
return V_238 ;
return NULL ;
}
static int F_139 ( struct V_16 * V_12 ,
const char * V_236 , int V_239 )
{
struct V_8 * V_9 = F_138 ( V_12 , V_236 , true ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_71 , V_236 ) ;
return - V_127 ;
}
if ( V_9 -> V_140 != V_239 )
F_10 ( V_9 , L_72 ) ;
V_9 -> V_140 = V_239 ;
if ( V_239 == 0 )
V_9 -> V_161 = 0 ;
return 0 ;
}
int F_140 ( struct V_16 * V_12 )
{
int V_39 ;
if ( ! V_12 -> V_14 || ! V_12 -> V_14 -> V_240 )
return 0 ;
F_65 ( & V_12 -> V_14 -> V_18 , V_149 ) ;
V_39 = F_107 ( V_12 , V_226 ) ;
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
static int F_141 ( struct V_16 * V_12 ,
const struct V_241 * V_242 )
{
struct V_48 * V_94 ;
struct V_8 * V_243 = NULL , * V_244 = NULL , * V_9 ;
struct V_8 * V_245 = NULL , * V_246 = NULL ;
const char * V_130 ;
const char * V_247 = V_242 -> V_247 ;
const char * V_132 ;
char V_248 [ 80 ] ;
char V_249 [ 80 ] ;
int V_39 = 0 ;
if ( V_12 -> V_24 && V_12 -> V_24 -> V_123 ) {
snprintf ( V_248 , sizeof( V_248 ) , L_7 ,
V_12 -> V_24 -> V_123 , V_242 -> V_130 ) ;
V_130 = V_248 ;
snprintf ( V_249 , sizeof( V_249 ) , L_7 ,
V_12 -> V_24 -> V_123 , V_242 -> V_132 ) ;
V_132 = V_249 ;
} else {
V_130 = V_242 -> V_130 ;
V_132 = V_242 -> V_132 ;
}
F_15 (w, &dapm->card->widgets, list) {
if ( ! V_244 && ! ( strcmp ( V_9 -> V_13 , V_130 ) ) ) {
V_246 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_244 = V_9 ;
continue;
}
if ( ! V_243 && ! ( strcmp ( V_9 -> V_13 , V_132 ) ) ) {
V_245 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_243 = V_9 ;
}
}
if ( ! V_244 )
V_244 = V_246 ;
if ( ! V_243 )
V_243 = V_245 ;
if ( V_243 == NULL ) {
F_26 ( V_12 -> V_3 , L_73 ,
V_242 -> V_132 ) ;
return - V_104 ;
}
if ( V_244 == NULL ) {
F_26 ( V_12 -> V_3 , L_74 ,
V_242 -> V_130 ) ;
return - V_104 ;
}
V_94 = F_142 ( sizeof( struct V_48 ) , V_7 ) ;
if ( ! V_94 )
return - V_125 ;
V_94 -> V_132 = V_243 ;
V_94 -> V_130 = V_244 ;
V_94 -> V_140 = V_242 -> V_140 ;
F_95 ( & V_94 -> V_98 ) ;
F_95 ( & V_94 -> V_102 ) ;
F_95 ( & V_94 -> V_100 ) ;
if ( V_244 -> V_19 == V_20 ) {
if ( V_243 -> V_19 == V_76 ||
V_243 -> V_19 == V_86 ||
V_243 -> V_19 == V_88 ||
V_243 -> V_19 == V_21 )
V_244 -> V_141 = 1 ;
}
if ( V_243 -> V_19 == V_21 ) {
if ( V_244 -> V_19 == V_87 ||
V_244 -> V_19 == V_85 ||
V_244 -> V_19 == V_88 ||
V_244 -> V_19 == V_20 )
V_243 -> V_141 = 1 ;
}
if ( V_247 == NULL ) {
F_40 ( & V_94 -> V_98 , & V_12 -> V_14 -> V_99 ) ;
F_40 ( & V_94 -> V_100 , & V_244 -> V_101 ) ;
F_40 ( & V_94 -> V_102 , & V_243 -> V_103 ) ;
V_94 -> V_61 = 1 ;
return 0 ;
}
switch ( V_244 -> V_19 ) {
case V_73 :
case V_75 :
case V_71 :
case V_72 :
case V_20 :
case V_21 :
case V_74 :
case V_76 :
case V_77 :
case V_90 :
case V_91 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_89 :
F_40 ( & V_94 -> V_98 , & V_12 -> V_14 -> V_99 ) ;
F_40 ( & V_94 -> V_100 , & V_244 -> V_101 ) ;
F_40 ( & V_94 -> V_102 , & V_243 -> V_103 ) ;
V_94 -> V_61 = 1 ;
return 0 ;
case V_62 :
case V_68 :
case V_69 :
V_39 = F_39 ( V_12 , V_243 , V_244 , V_94 , V_247 ,
& V_244 -> V_56 [ 0 ] ) ;
if ( V_39 != 0 )
goto V_145;
break;
case V_51 :
case V_52 :
case V_53 :
V_39 = F_41 ( V_12 , V_243 , V_244 , V_94 , V_247 ) ;
if ( V_39 != 0 )
goto V_145;
break;
case V_85 :
case V_86 :
case V_88 :
case V_87 :
F_40 ( & V_94 -> V_98 , & V_12 -> V_14 -> V_99 ) ;
F_40 ( & V_94 -> V_100 , & V_244 -> V_101 ) ;
F_40 ( & V_94 -> V_102 , & V_243 -> V_103 ) ;
V_94 -> V_61 = 0 ;
return 0 ;
}
F_10 ( V_243 , L_75 ) ;
F_10 ( V_244 , L_75 ) ;
return 0 ;
V_145:
F_71 ( V_12 -> V_3 , L_76 ,
V_132 , V_247 , V_130 ) ;
F_7 ( V_94 ) ;
return V_39 ;
}
static int F_143 ( struct V_16 * V_12 ,
const struct V_241 * V_242 )
{
struct V_48 * V_94 , * V_49 ;
const char * V_130 ;
const char * V_132 ;
char V_248 [ 80 ] ;
char V_249 [ 80 ] ;
if ( V_242 -> V_247 ) {
F_26 ( V_12 -> V_3 ,
L_77 ) ;
return - V_127 ;
}
if ( V_12 -> V_24 && V_12 -> V_24 -> V_123 ) {
snprintf ( V_248 , sizeof( V_248 ) , L_7 ,
V_12 -> V_24 -> V_123 , V_242 -> V_130 ) ;
V_130 = V_248 ;
snprintf ( V_249 , sizeof( V_249 ) , L_7 ,
V_12 -> V_24 -> V_123 , V_242 -> V_132 ) ;
V_132 = V_249 ;
} else {
V_130 = V_242 -> V_130 ;
V_132 = V_242 -> V_132 ;
}
V_94 = NULL ;
F_15 (p, &dapm->card->paths, list) {
if ( strcmp ( V_49 -> V_132 -> V_13 , V_132 ) != 0 )
continue;
if ( strcmp ( V_49 -> V_130 -> V_13 , V_130 ) != 0 )
continue;
V_94 = V_49 ;
break;
}
if ( V_94 ) {
F_10 ( V_94 -> V_132 , L_78 ) ;
F_10 ( V_94 -> V_130 , L_78 ) ;
F_135 ( V_94 ) ;
} else {
F_71 ( V_12 -> V_3 , L_79 ,
V_132 , V_130 ) ;
}
return 0 ;
}
int F_144 ( struct V_16 * V_12 ,
const struct V_241 * V_242 , int V_250 )
{
int V_50 , V_251 , V_39 = 0 ;
F_65 ( & V_12 -> V_14 -> V_18 , V_252 ) ;
for ( V_50 = 0 ; V_50 < V_250 ; V_50 ++ ) {
V_251 = F_141 ( V_12 , V_242 ) ;
if ( V_251 < 0 ) {
F_26 ( V_12 -> V_3 , L_80 ,
V_242 -> V_132 ,
V_242 -> V_247 ? V_242 -> V_247 : L_81 ,
V_242 -> V_130 ) ;
V_39 = V_251 ;
}
V_242 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
int F_145 ( struct V_16 * V_12 ,
const struct V_241 * V_242 , int V_250 )
{
int V_50 , V_39 = 0 ;
F_65 ( & V_12 -> V_14 -> V_18 , V_252 ) ;
for ( V_50 = 0 ; V_50 < V_250 ; V_50 ++ ) {
F_143 ( V_12 , V_242 ) ;
V_242 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
static int F_146 ( struct V_16 * V_12 ,
const struct V_241 * V_242 )
{
struct V_8 * V_132 = F_138 ( V_12 ,
V_242 -> V_132 ,
true ) ;
struct V_8 * V_130 = F_138 ( V_12 ,
V_242 -> V_130 ,
true ) ;
struct V_48 * V_94 ;
int V_216 = 0 ;
if ( ! V_132 ) {
F_26 ( V_12 -> V_3 , L_82 ,
V_242 -> V_132 ) ;
return - V_104 ;
}
if ( ! V_130 ) {
F_26 ( V_12 -> V_3 , L_83 ,
V_242 -> V_130 ) ;
return - V_104 ;
}
if ( V_242 -> V_247 || V_242 -> V_140 )
F_71 ( V_12 -> V_3 , L_84 ,
V_242 -> V_132 , V_242 -> V_130 ) ;
F_15 (path, &source->sinks, list_source) {
if ( V_94 -> V_130 == V_130 ) {
V_94 -> V_143 = 1 ;
V_216 ++ ;
}
}
if ( V_216 == 0 )
F_26 ( V_12 -> V_3 , L_85 ,
V_242 -> V_132 , V_242 -> V_130 ) ;
if ( V_216 > 1 )
F_71 ( V_12 -> V_3 , L_86 ,
V_216 , V_242 -> V_132 , V_242 -> V_130 ) ;
return 0 ;
}
int F_147 ( struct V_16 * V_12 ,
const struct V_241 * V_242 , int V_250 )
{
int V_50 , V_145 ;
int V_39 = 0 ;
F_65 ( & V_12 -> V_14 -> V_18 , V_252 ) ;
for ( V_50 = 0 ; V_50 < V_250 ; V_50 ++ ) {
V_145 = F_146 ( V_12 , V_242 ) ;
if ( V_145 )
V_39 = V_145 ;
V_242 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
int F_148 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_31 ;
F_65 ( & V_12 -> V_14 -> V_18 , V_252 ) ;
F_15 (w, &dapm->card->widgets, list)
{
if ( V_9 -> V_38 )
continue;
if ( V_9 -> V_105 ) {
V_9 -> V_109 = F_142 ( V_9 -> V_105 *
sizeof( struct V_108 * ) ,
V_7 ) ;
if ( ! V_9 -> V_109 ) {
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return - V_125 ;
}
}
switch( V_9 -> V_19 ) {
case V_51 :
case V_52 :
case V_53 :
F_49 ( V_9 ) ;
break;
case V_62 :
case V_68 :
case V_69 :
F_50 ( V_9 ) ;
break;
case V_71 :
case V_72 :
F_52 ( V_9 ) ;
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
V_9 -> V_175 = 1 ;
}
V_9 -> V_38 = 1 ;
F_10 ( V_9 , L_87 ) ;
F_121 ( V_9 ) ;
}
F_107 ( V_12 , V_226 ) ;
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return 0 ;
}
int F_149 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_116 * V_117 = F_150 ( V_97 ) ;
struct V_8 * V_133 = V_117 -> V_126 [ 0 ] ;
struct V_54 * V_55 =
(struct V_54 * ) V_97 -> V_57 ;
unsigned int V_30 = V_55 -> V_30 ;
unsigned int V_58 = V_55 -> V_58 ;
int V_59 = V_55 -> V_59 ;
unsigned int V_34 = ( 1 << F_38 ( V_59 ) ) - 1 ;
unsigned int V_60 = V_55 -> V_60 ;
if ( F_151 ( V_55 ) )
F_71 ( V_133 -> V_12 -> V_3 ,
L_88 ,
V_97 -> V_19 . V_13 ) ;
V_254 -> V_35 . integer . V_35 [ 0 ] =
( F_24 ( V_133 -> V_24 , V_30 ) >> V_58 ) & V_34 ;
if ( V_60 )
V_254 -> V_35 . integer . V_35 [ 0 ] =
V_59 - V_254 -> V_35 . integer . V_35 [ 0 ] ;
return 0 ;
}
int F_152 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_116 * V_117 = F_150 ( V_97 ) ;
struct V_8 * V_133 = V_117 -> V_126 [ 0 ] ;
struct V_231 * V_24 = V_133 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_54 * V_55 =
(struct V_54 * ) V_97 -> V_57 ;
unsigned int V_30 = V_55 -> V_30 ;
unsigned int V_58 = V_55 -> V_58 ;
int V_59 = V_55 -> V_59 ;
unsigned int V_34 = ( 1 << F_38 ( V_59 ) ) - 1 ;
unsigned int V_60 = V_55 -> V_60 ;
unsigned int V_31 ;
int V_61 , V_36 ;
struct V_195 V_196 ;
int V_255 ;
if ( F_151 ( V_55 ) )
F_71 ( V_133 -> V_12 -> V_3 ,
L_88 ,
V_97 -> V_19 . V_13 ) ;
V_31 = ( V_254 -> V_35 . integer . V_35 [ 0 ] & V_34 ) ;
V_61 = ! ! V_31 ;
if ( V_60 )
V_31 = V_59 - V_31 ;
V_34 = V_34 << V_58 ;
V_31 = V_31 << V_58 ;
F_65 ( & V_14 -> V_18 , V_149 ) ;
V_36 = F_153 ( V_133 -> V_24 , V_30 , V_34 , V_31 ) ;
if ( V_36 ) {
for ( V_255 = 0 ; V_255 < V_117 -> V_124 ; V_255 ++ ) {
V_133 = V_117 -> V_126 [ V_255 ] ;
V_133 -> V_35 = V_31 ;
V_196 . V_97 = V_97 ;
V_196 . V_133 = V_133 ;
V_196 . V_30 = V_30 ;
V_196 . V_34 = V_34 ;
V_196 . V_31 = V_31 ;
V_133 -> V_12 -> V_196 = & V_196 ;
F_127 ( V_133 , V_97 , V_61 ) ;
V_133 -> V_12 -> V_196 = NULL ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_36 ;
}
int F_154 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_116 * V_117 = F_150 ( V_97 ) ;
struct V_8 * V_133 = V_117 -> V_126 [ 0 ] ;
struct V_63 * V_64 = (struct V_63 * ) V_97 -> V_57 ;
unsigned int V_31 ;
V_31 = F_24 ( V_133 -> V_24 , V_64 -> V_30 ) ;
V_254 -> V_35 . V_256 . V_65 [ 0 ] = ( V_31 >> V_64 -> V_66 ) & V_64 -> V_34 ;
if ( V_64 -> V_66 != V_64 -> V_257 )
V_254 -> V_35 . V_256 . V_65 [ 1 ] =
( V_31 >> V_64 -> V_257 ) & V_64 -> V_34 ;
return 0 ;
}
int F_155 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_116 * V_117 = F_150 ( V_97 ) ;
struct V_8 * V_133 = V_117 -> V_126 [ 0 ] ;
struct V_231 * V_24 = V_133 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_63 * V_64 = (struct V_63 * ) V_97 -> V_57 ;
unsigned int V_31 , V_224 , V_36 ;
unsigned int V_34 ;
struct V_195 V_196 ;
int V_255 ;
if ( V_254 -> V_35 . V_256 . V_65 [ 0 ] > V_64 -> V_59 - 1 )
return - V_127 ;
V_224 = V_254 -> V_35 . V_256 . V_65 [ 0 ] ;
V_31 = V_224 << V_64 -> V_66 ;
V_34 = V_64 -> V_34 << V_64 -> V_66 ;
if ( V_64 -> V_66 != V_64 -> V_257 ) {
if ( V_254 -> V_35 . V_256 . V_65 [ 1 ] > V_64 -> V_59 - 1 )
return - V_127 ;
V_31 |= V_254 -> V_35 . V_256 . V_65 [ 1 ] << V_64 -> V_257 ;
V_34 |= V_64 -> V_34 << V_64 -> V_257 ;
}
F_65 ( & V_14 -> V_18 , V_149 ) ;
V_36 = F_153 ( V_133 -> V_24 , V_64 -> V_30 , V_34 , V_31 ) ;
if ( V_36 ) {
for ( V_255 = 0 ; V_255 < V_117 -> V_124 ; V_255 ++ ) {
V_133 = V_117 -> V_126 [ V_255 ] ;
V_133 -> V_35 = V_31 ;
V_196 . V_97 = V_97 ;
V_196 . V_133 = V_133 ;
V_196 . V_30 = V_64 -> V_30 ;
V_196 . V_34 = V_34 ;
V_196 . V_31 = V_31 ;
V_133 -> V_12 -> V_196 = & V_196 ;
F_124 ( V_133 , V_97 , V_224 , V_64 ) ;
V_133 -> V_12 -> V_196 = NULL ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_36 ;
}
int F_156 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_116 * V_117 = F_150 ( V_97 ) ;
struct V_8 * V_133 = V_117 -> V_126 [ 0 ] ;
V_254 -> V_35 . V_256 . V_65 [ 0 ] = V_133 -> V_35 ;
return 0 ;
}
int F_157 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_116 * V_117 = F_150 ( V_97 ) ;
struct V_8 * V_133 = V_117 -> V_126 [ 0 ] ;
struct V_231 * V_24 = V_133 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_63 * V_64 =
(struct V_63 * ) V_97 -> V_57 ;
int V_36 ;
int V_255 ;
if ( V_254 -> V_35 . V_256 . V_65 [ 0 ] >= V_64 -> V_59 )
return - V_127 ;
F_65 ( & V_14 -> V_18 , V_149 ) ;
V_36 = V_133 -> V_35 != V_254 -> V_35 . V_256 . V_65 [ 0 ] ;
if ( V_36 ) {
for ( V_255 = 0 ; V_255 < V_117 -> V_124 ; V_255 ++ ) {
V_133 = V_117 -> V_126 [ V_255 ] ;
V_133 -> V_35 = V_254 -> V_35 . V_256 . V_65 [ 0 ] ;
F_124 ( V_133 , V_97 , V_133 -> V_35 , V_64 ) ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_36 ;
}
int F_158 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_116 * V_117 = F_150 ( V_97 ) ;
struct V_8 * V_133 = V_117 -> V_126 [ 0 ] ;
struct V_63 * V_64 = (struct V_63 * ) V_97 -> V_57 ;
unsigned int V_258 , V_31 , V_224 ;
V_258 = F_24 ( V_133 -> V_24 , V_64 -> V_30 ) ;
V_31 = ( V_258 >> V_64 -> V_66 ) & V_64 -> V_34 ;
for ( V_224 = 0 ; V_224 < V_64 -> V_59 ; V_224 ++ ) {
if ( V_31 == V_64 -> V_70 [ V_224 ] )
break;
}
V_254 -> V_35 . V_256 . V_65 [ 0 ] = V_224 ;
if ( V_64 -> V_66 != V_64 -> V_257 ) {
V_31 = ( V_258 >> V_64 -> V_257 ) & V_64 -> V_34 ;
for ( V_224 = 0 ; V_224 < V_64 -> V_59 ; V_224 ++ ) {
if ( V_31 == V_64 -> V_70 [ V_224 ] )
break;
}
V_254 -> V_35 . V_256 . V_65 [ 1 ] = V_224 ;
}
return 0 ;
}
int F_159 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_116 * V_117 = F_150 ( V_97 ) ;
struct V_8 * V_133 = V_117 -> V_126 [ 0 ] ;
struct V_231 * V_24 = V_133 -> V_24 ;
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_63 * V_64 = (struct V_63 * ) V_97 -> V_57 ;
unsigned int V_31 , V_224 , V_36 ;
unsigned int V_34 ;
struct V_195 V_196 ;
int V_255 ;
if ( V_254 -> V_35 . V_256 . V_65 [ 0 ] > V_64 -> V_59 - 1 )
return - V_127 ;
V_224 = V_254 -> V_35 . V_256 . V_65 [ 0 ] ;
V_31 = V_64 -> V_70 [ V_254 -> V_35 . V_256 . V_65 [ 0 ] ] << V_64 -> V_66 ;
V_34 = V_64 -> V_34 << V_64 -> V_66 ;
if ( V_64 -> V_66 != V_64 -> V_257 ) {
if ( V_254 -> V_35 . V_256 . V_65 [ 1 ] > V_64 -> V_59 - 1 )
return - V_127 ;
V_31 |= V_64 -> V_70 [ V_254 -> V_35 . V_256 . V_65 [ 1 ] ] << V_64 -> V_257 ;
V_34 |= V_64 -> V_34 << V_64 -> V_257 ;
}
F_65 ( & V_14 -> V_18 , V_149 ) ;
V_36 = F_153 ( V_133 -> V_24 , V_64 -> V_30 , V_34 , V_31 ) ;
if ( V_36 ) {
for ( V_255 = 0 ; V_255 < V_117 -> V_124 ; V_255 ++ ) {
V_133 = V_117 -> V_126 [ V_255 ] ;
V_133 -> V_35 = V_31 ;
V_196 . V_97 = V_97 ;
V_196 . V_133 = V_133 ;
V_196 . V_30 = V_64 -> V_30 ;
V_196 . V_34 = V_34 ;
V_196 . V_31 = V_31 ;
V_133 -> V_12 -> V_196 = & V_196 ;
F_124 ( V_133 , V_97 , V_224 , V_64 ) ;
V_133 -> V_12 -> V_196 = NULL ;
}
}
F_16 ( & V_14 -> V_18 ) ;
return V_36 ;
}
int F_160 ( struct V_108 * V_97 ,
struct V_259 * V_260 )
{
V_260 -> type = V_261 ;
V_260 -> V_216 = 1 ;
V_260 -> V_35 . integer . V_262 = 0 ;
V_260 -> V_35 . integer . V_59 = 1 ;
return 0 ;
}
int F_161 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_17 * V_14 = F_150 ( V_97 ) ;
const char * V_236 = ( const char * ) V_97 -> V_57 ;
F_65 ( & V_14 -> V_18 , V_149 ) ;
V_254 -> V_35 . integer . V_35 [ 0 ] =
F_162 ( & V_14 -> V_12 , V_236 ) ;
F_16 ( & V_14 -> V_18 ) ;
return 0 ;
}
int F_163 ( struct V_108 * V_97 ,
struct V_253 * V_254 )
{
struct V_17 * V_14 = F_150 ( V_97 ) ;
const char * V_236 = ( const char * ) V_97 -> V_57 ;
F_65 ( & V_14 -> V_18 , V_149 ) ;
if ( V_254 -> V_35 . integer . V_35 [ 0 ] )
F_164 ( & V_14 -> V_12 , V_236 ) ;
else
F_165 ( & V_14 -> V_12 , V_236 ) ;
F_16 ( & V_14 -> V_18 ) ;
F_140 ( & V_14 -> V_12 ) ;
return 0 ;
}
static struct V_8 *
F_166 ( struct V_16 * V_12 ,
const struct V_8 * V_133 )
{
struct V_8 * V_9 ;
int V_39 ;
if ( ( V_9 = F_17 ( V_133 ) ) == NULL )
return NULL ;
switch ( V_9 -> V_19 ) {
case V_79 :
V_9 -> V_157 = F_167 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_168 ( V_9 -> V_157 ) ) {
V_39 = F_169 ( V_9 -> V_157 ) ;
F_26 ( V_12 -> V_3 , L_89 ,
V_9 -> V_13 , V_39 ) ;
return NULL ;
}
if ( V_9 -> V_60 & V_156 ) {
V_39 = F_70 ( V_9 -> V_157 , true ) ;
if ( V_39 != 0 )
F_71 ( V_9 -> V_12 -> V_3 ,
L_16 ,
V_9 -> V_13 , V_39 ) ;
}
break;
case V_80 :
#ifdef F_170
V_9 -> V_158 = F_171 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_168 ( V_9 -> V_158 ) ) {
V_39 = F_169 ( V_9 -> V_158 ) ;
F_26 ( V_12 -> V_3 , L_89 ,
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
if ( V_12 -> V_24 && V_12 -> V_24 -> V_123 )
V_9 -> V_13 = F_46 ( V_7 , L_7 ,
V_12 -> V_24 -> V_123 , V_133 -> V_13 ) ;
else
V_9 -> V_13 = F_46 ( V_7 , L_1 , V_133 -> V_13 ) ;
if ( V_9 -> V_13 == NULL ) {
F_7 ( V_9 ) ;
return NULL ;
}
switch ( V_9 -> V_19 ) {
case V_51 :
case V_52 :
case V_53 :
V_9 -> V_162 = F_79 ;
break;
case V_62 :
case V_68 :
case V_69 :
V_9 -> V_162 = F_79 ;
break;
case V_73 :
case V_82 :
case V_84 :
V_9 -> V_162 = F_80 ;
break;
case V_75 :
case V_81 :
case V_83 :
V_9 -> V_162 = F_81 ;
break;
case V_71 :
case V_72 :
case V_20 :
case V_21 :
case V_76 :
case V_87 :
case V_85 :
case V_86 :
case V_88 :
case V_89 :
V_9 -> V_162 = F_79 ;
break;
case V_78 :
case V_79 :
case V_80 :
V_9 -> V_162 = F_82 ;
break;
default:
V_9 -> V_162 = F_83 ;
break;
}
V_9 -> V_12 = V_12 ;
V_9 -> V_24 = V_12 -> V_24 ;
V_9 -> V_25 = V_12 -> V_25 ;
F_95 ( & V_9 -> V_101 ) ;
F_95 ( & V_9 -> V_103 ) ;
F_95 ( & V_9 -> V_98 ) ;
F_95 ( & V_9 -> V_10 ) ;
F_40 ( & V_9 -> V_98 , & V_12 -> V_14 -> V_126 ) ;
V_9 -> V_140 = 1 ;
return V_9 ;
}
int F_172 ( struct V_16 * V_12 ,
const struct V_8 * V_133 ,
int V_250 )
{
struct V_8 * V_9 ;
int V_50 ;
int V_39 = 0 ;
F_65 ( & V_12 -> V_14 -> V_18 , V_252 ) ;
for ( V_50 = 0 ; V_50 < V_250 ; V_50 ++ ) {
V_9 = F_166 ( V_12 , V_133 ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 ,
L_90 ,
V_133 -> V_13 ) ;
V_39 = - V_125 ;
break;
}
V_133 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_39 ;
}
static int F_173 ( struct V_8 * V_9 ,
struct V_108 * V_97 , int V_153 )
{
struct V_48 * V_263 , * V_264 ;
struct V_146 * V_132 , * V_130 ;
const struct V_265 * V_266 = V_9 -> V_267 ;
struct V_268 V_269 ;
struct V_270 * V_267 = NULL ;
T_8 V_4 ;
int V_39 ;
F_90 ( ! V_266 ) ;
F_90 ( F_9 ( & V_9 -> V_101 ) || F_9 ( & V_9 -> V_103 ) ) ;
V_263 = F_51 ( & V_9 -> V_101 , struct V_48 ,
V_100 ) ;
V_264 = F_51 ( & V_9 -> V_103 , struct V_48 ,
V_102 ) ;
F_90 ( ! V_263 || ! V_264 ) ;
F_90 ( ! V_264 -> V_132 || ! V_263 -> V_130 ) ;
F_90 ( ! V_263 -> V_132 || ! V_264 -> V_130 ) ;
V_132 = V_263 -> V_132 -> V_271 ;
V_130 = V_264 -> V_130 -> V_271 ;
if ( V_266 -> V_272 ) {
V_4 = F_174 ( V_266 -> V_272 ) - 1 ;
} else {
F_71 ( V_9 -> V_12 -> V_3 , L_91 ,
V_266 -> V_272 ) ;
V_4 = 0 ;
}
V_267 = F_142 ( sizeof( * V_267 ) , V_7 ) ;
if ( ! V_267 ) {
V_39 = - V_125 ;
goto V_44;
}
F_175 ( F_176 ( V_267 , V_273 ) , V_4 ) ;
F_177 ( V_267 , V_274 ) -> V_262 =
V_266 -> V_275 ;
F_177 ( V_267 , V_274 ) -> V_59 =
V_266 -> V_276 ;
F_177 ( V_267 , V_277 ) -> V_262
= V_266 -> V_278 ;
F_177 ( V_267 , V_277 ) -> V_59
= V_266 -> V_279 ;
memset ( & V_269 , 0 , sizeof( V_269 ) ) ;
switch ( V_153 ) {
case V_176 :
if ( V_132 -> V_45 -> V_280 && V_132 -> V_45 -> V_280 -> V_281 ) {
V_269 . V_148 = V_282 ;
V_39 = V_132 -> V_45 -> V_280 -> V_281 ( & V_269 ,
V_267 , V_132 ) ;
if ( V_39 != 0 ) {
F_26 ( V_132 -> V_3 ,
L_92 , V_39 ) ;
goto V_44;
}
}
if ( V_130 -> V_45 -> V_280 && V_130 -> V_45 -> V_280 -> V_281 ) {
V_269 . V_148 = V_150 ;
V_39 = V_130 -> V_45 -> V_280 -> V_281 ( & V_269 , V_267 ,
V_130 ) ;
if ( V_39 != 0 ) {
F_26 ( V_130 -> V_3 ,
L_92 , V_39 ) ;
goto V_44;
}
}
break;
case V_177 :
V_39 = F_178 ( V_130 , 0 ,
V_150 ) ;
if ( V_39 != 0 && V_39 != - V_283 )
F_71 ( V_130 -> V_3 , L_93 , V_39 ) ;
V_39 = 0 ;
break;
case V_178 :
V_39 = F_178 ( V_130 , 1 ,
V_150 ) ;
if ( V_39 != 0 && V_39 != - V_283 )
F_71 ( V_130 -> V_3 , L_94 , V_39 ) ;
V_39 = 0 ;
break;
default:
F_20 () ;
return - V_127 ;
}
V_44:
F_7 ( V_267 ) ;
return V_39 ;
}
int F_179 ( struct V_17 * V_14 ,
const struct V_265 * V_267 ,
struct V_8 * V_132 ,
struct V_8 * V_130 )
{
struct V_241 V_284 [ 2 ] ;
struct V_8 V_285 ;
struct V_8 * V_9 ;
T_3 V_286 ;
char * V_287 ;
V_286 = strlen ( V_132 -> V_13 ) + strlen ( V_130 -> V_13 ) + 2 ;
V_287 = F_180 ( V_14 -> V_3 , V_286 , V_7 ) ;
if ( ! V_287 )
return - V_125 ;
snprintf ( V_287 , V_286 , L_95 , V_132 -> V_13 , V_130 -> V_13 ) ;
memset ( & V_285 , 0 , sizeof( V_285 ) ) ;
V_285 . V_30 = V_189 ;
V_285 . V_19 = V_89 ;
V_285 . V_13 = V_287 ;
V_285 . V_153 = F_173 ;
V_285 . V_182 = V_176 | V_177 |
V_178 ;
F_57 ( V_14 -> V_3 , L_96 , V_287 ) ;
V_9 = F_166 ( & V_14 -> V_12 , & V_285 ) ;
if ( ! V_9 ) {
F_26 ( V_14 -> V_3 , L_97 ,
V_287 ) ;
return - V_125 ;
}
V_9 -> V_267 = V_267 ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_284 [ 0 ] . V_132 = V_132 -> V_13 ;
V_284 [ 0 ] . V_130 = V_287 ;
V_284 [ 1 ] . V_132 = V_287 ;
V_284 [ 1 ] . V_130 = V_130 -> V_13 ;
return F_144 ( & V_14 -> V_12 , V_284 ,
F_94 ( V_284 ) ) ;
}
int F_181 ( struct V_16 * V_12 ,
struct V_146 * V_147 )
{
struct V_8 V_285 ;
struct V_8 * V_9 ;
F_182 ( V_12 -> V_3 != V_147 -> V_3 ) ;
memset ( & V_285 , 0 , sizeof( V_285 ) ) ;
V_285 . V_30 = V_189 ;
if ( V_147 -> V_45 -> V_288 . V_289 ) {
V_285 . V_19 = V_83 ;
V_285 . V_13 = V_147 -> V_45 -> V_288 . V_289 ;
V_285 . V_218 = V_147 -> V_45 -> V_288 . V_289 ;
F_57 ( V_147 -> V_3 , L_96 ,
V_285 . V_13 ) ;
V_9 = F_166 ( V_12 , & V_285 ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_97 ,
V_147 -> V_45 -> V_288 . V_289 ) ;
}
V_9 -> V_271 = V_147 ;
V_147 -> V_151 = V_9 ;
}
if ( V_147 -> V_45 -> V_290 . V_289 ) {
V_285 . V_19 = V_84 ;
V_285 . V_13 = V_147 -> V_45 -> V_290 . V_289 ;
V_285 . V_218 = V_147 -> V_45 -> V_290 . V_289 ;
F_57 ( V_147 -> V_3 , L_96 ,
V_285 . V_13 ) ;
V_9 = F_166 ( V_12 , & V_285 ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_97 ,
V_147 -> V_45 -> V_290 . V_289 ) ;
}
V_9 -> V_271 = V_147 ;
V_147 -> V_152 = V_9 ;
}
return 0 ;
}
int F_183 ( struct V_17 * V_14 )
{
struct V_8 * V_291 , * V_9 ;
struct V_146 * V_147 ;
struct V_241 V_251 ;
memset ( & V_251 , 0 , sizeof( V_251 ) ) ;
F_15 (dai_w, &card->widgets, list) {
switch ( V_291 -> V_19 ) {
case V_83 :
case V_84 :
break;
default:
continue;
}
V_147 = V_291 -> V_271 ;
F_15 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_291 -> V_12 )
continue;
switch ( V_9 -> V_19 ) {
case V_83 :
case V_84 :
continue;
default:
break;
}
if ( ! V_9 -> V_218 )
continue;
if ( V_147 -> V_45 -> V_288 . V_289 &&
strstr ( V_9 -> V_218 ,
V_147 -> V_45 -> V_288 . V_289 ) ) {
V_251 . V_132 = V_147 -> V_151 -> V_13 ;
V_251 . V_130 = V_9 -> V_13 ;
F_57 ( V_147 -> V_3 , L_98 ,
V_251 . V_132 , V_251 . V_130 ) ;
F_141 ( V_9 -> V_12 , & V_251 ) ;
}
if ( V_147 -> V_45 -> V_290 . V_289 &&
strstr ( V_9 -> V_218 ,
V_147 -> V_45 -> V_290 . V_289 ) ) {
V_251 . V_132 = V_9 -> V_13 ;
V_251 . V_130 = V_147 -> V_152 -> V_13 ;
F_57 ( V_147 -> V_3 , L_98 ,
V_251 . V_132 , V_251 . V_130 ) ;
F_141 ( V_9 -> V_12 , & V_251 ) ;
}
}
}
return 0 ;
}
static void F_184 ( struct V_229 * V_230 , int V_148 ,
int V_153 )
{
struct V_8 * V_292 , * V_293 ;
struct V_146 * V_294 = V_230 -> V_294 ;
struct V_146 * V_295 = V_230 -> V_295 ;
if ( V_148 == V_150 ) {
V_292 = V_294 -> V_151 ;
V_293 = V_295 -> V_151 ;
} else {
V_292 = V_294 -> V_152 ;
V_293 = V_295 -> V_152 ;
}
if ( V_292 ) {
F_10 ( V_292 , L_99 ) ;
switch ( V_153 ) {
case V_193 :
V_292 -> V_139 = 1 ;
break;
case V_194 :
V_292 -> V_139 = 0 ;
break;
case V_296 :
case V_297 :
case V_298 :
case V_299 :
break;
}
}
if ( V_293 ) {
F_10 ( V_293 , L_99 ) ;
switch ( V_153 ) {
case V_193 :
V_293 -> V_139 = 1 ;
break;
case V_194 :
V_293 -> V_139 = 0 ;
break;
case V_296 :
case V_297 :
case V_298 :
case V_299 :
break;
}
}
F_107 ( & V_230 -> V_14 -> V_12 , V_153 ) ;
}
void F_185 ( struct V_229 * V_230 , int V_148 ,
int V_153 )
{
struct V_17 * V_14 = V_230 -> V_14 ;
F_65 ( & V_14 -> V_18 , V_149 ) ;
F_184 ( V_230 , V_148 , V_153 ) ;
F_16 ( & V_14 -> V_18 ) ;
}
int F_164 ( struct V_16 * V_12 , const char * V_236 )
{
return F_139 ( V_12 , V_236 , 1 ) ;
}
int F_186 ( struct V_16 * V_12 ,
const char * V_236 )
{
struct V_8 * V_9 = F_138 ( V_12 , V_236 , true ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_100 , V_236 ) ;
return - V_127 ;
}
F_57 ( V_9 -> V_12 -> V_3 , L_101 , V_236 ) ;
V_9 -> V_140 = 1 ;
V_9 -> V_161 = 1 ;
F_10 ( V_9 , L_102 ) ;
return 0 ;
}
int F_165 ( struct V_16 * V_12 ,
const char * V_236 )
{
return F_139 ( V_12 , V_236 , 0 ) ;
}
int F_187 ( struct V_16 * V_12 , const char * V_236 )
{
return F_139 ( V_12 , V_236 , 0 ) ;
}
int F_162 ( struct V_16 * V_12 ,
const char * V_236 )
{
struct V_8 * V_9 = F_138 ( V_12 , V_236 , true ) ;
if ( V_9 )
return V_9 -> V_140 ;
return 0 ;
}
int F_188 ( struct V_16 * V_12 ,
const char * V_236 )
{
struct V_8 * V_9 = F_138 ( V_12 , V_236 , false ) ;
if ( ! V_9 ) {
F_26 ( V_12 -> V_3 , L_100 , V_236 ) ;
return - V_127 ;
}
V_9 -> V_136 = 1 ;
return 0 ;
}
static bool F_189 ( struct V_17 * V_14 ,
struct V_8 * V_9 )
{
struct V_48 * V_49 ;
F_15 (p, &card->paths, list) {
if ( ( V_49 -> V_132 == V_9 ) || ( V_49 -> V_130 == V_9 ) ) {
F_57 ( V_14 -> V_3 ,
L_103 ,
V_49 -> V_132 -> V_13 , V_49 -> V_132 -> V_19 , V_49 -> V_132 -> V_12 ,
V_49 -> V_130 -> V_13 , V_49 -> V_130 -> V_19 , V_49 -> V_130 -> V_12 ) ;
if ( V_49 -> V_132 -> V_12 != V_49 -> V_130 -> V_12 )
return true ;
if ( V_49 -> V_130 -> V_19 == V_20 ) {
switch ( V_49 -> V_132 -> V_19 ) {
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
void F_190 ( struct V_231 * V_24 )
{
struct V_17 * V_14 = V_24 -> V_14 ;
struct V_16 * V_12 = & V_24 -> V_12 ;
struct V_8 * V_9 ;
F_57 ( V_24 -> V_3 , L_104 ,
& V_14 -> V_12 , & V_24 -> V_12 ) ;
F_15 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
switch ( V_9 -> V_19 ) {
case V_20 :
case V_21 :
case V_76 :
F_57 ( V_24 -> V_3 , L_105 ,
V_9 -> V_13 ) ;
if ( ! F_189 ( V_14 , V_9 ) ) {
F_57 ( V_24 -> V_3 ,
L_106 ) ;
F_187 ( V_12 , V_9 -> V_13 ) ;
}
break;
default:
break;
}
}
}
void F_191 ( struct V_16 * V_12 )
{
F_133 ( V_12 -> V_3 ) ;
F_122 ( V_12 ) ;
F_137 ( V_12 ) ;
F_136 ( & V_12 -> V_98 ) ;
}
static void F_192 ( struct V_16 * V_12 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
F_92 ( V_209 ) ;
int V_300 = 0 ;
F_14 ( & V_14 -> V_18 ) ;
F_15 (w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
if ( V_9 -> V_175 ) {
F_85 ( V_9 , & V_209 , false ) ;
V_9 -> V_175 = 0 ;
V_300 = 1 ;
}
}
if ( V_300 ) {
if ( V_12 -> V_46 == V_206 )
F_34 ( V_12 ,
V_205 ) ;
F_91 ( V_12 , & V_209 , 0 , false ) ;
if ( V_12 -> V_46 == V_205 )
F_34 ( V_12 ,
V_204 ) ;
}
F_16 ( & V_14 -> V_18 ) ;
}
void F_193 ( struct V_17 * V_14 )
{
struct V_231 * V_24 ;
F_15 (codec, &card->codec_dev_list, card_list) {
F_192 ( & V_24 -> V_12 ) ;
if ( V_24 -> V_12 . V_46 == V_204 )
F_34 ( & V_24 -> V_12 ,
V_202 ) ;
}
}
