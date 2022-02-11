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
static inline struct V_10 * F_10 (
struct V_11 * V_12 )
{
if ( V_12 -> V_13 )
return V_12 -> V_13 -> V_14 -> V_10 ;
else if ( V_12 -> V_15 )
return V_12 -> V_15 -> V_14 -> V_10 ;
else
F_11 () ;
return NULL ;
}
static inline struct V_16 * F_12 (
struct V_11 * V_12 )
{
if ( V_12 -> V_13 )
return V_12 -> V_13 -> V_14 ;
else if ( V_12 -> V_15 )
return V_12 -> V_15 -> V_14 ;
else
F_11 () ;
return NULL ;
}
static int F_13 ( struct V_8 * V_17 , int V_18 )
{
if ( V_17 -> V_13 )
return F_14 ( V_17 -> V_13 , V_18 ) ;
else if ( V_17 -> V_15 )
return F_15 ( V_17 -> V_15 , V_18 ) ;
F_16 ( V_17 -> V_12 -> V_3 , L_2 ) ;
return - 1 ;
}
static int F_17 ( struct V_8 * V_17 , int V_18 , int V_19 )
{
if ( V_17 -> V_13 )
return F_18 ( V_17 -> V_13 , V_18 , V_19 ) ;
else if ( V_17 -> V_15 )
return F_19 ( V_17 -> V_15 , V_18 , V_19 ) ;
F_16 ( V_17 -> V_12 -> V_3 , L_3 ) ;
return - 1 ;
}
static int F_20 ( struct V_8 * V_17 ,
unsigned short V_18 , unsigned int V_20 , unsigned int V_21 )
{
int V_22 ;
unsigned int V_23 , V_24 ;
int V_25 ;
V_25 = F_13 ( V_17 , V_18 ) ;
if ( V_25 < 0 )
return V_25 ;
V_23 = V_25 ;
V_24 = ( V_23 & ~ V_20 ) | ( V_21 & V_20 ) ;
V_22 = V_23 != V_24 ;
if ( V_22 ) {
V_25 = F_17 ( V_17 , V_18 , V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return V_22 ;
}
static int F_21 ( struct V_11 * V_12 ,
enum V_26 V_27 )
{
struct V_16 * V_14 = V_12 -> V_14 ;
int V_25 = 0 ;
F_22 ( V_14 , V_27 ) ;
if ( V_14 && V_14 -> V_28 )
V_25 = V_14 -> V_28 ( V_14 , V_12 , V_27 ) ;
if ( V_25 != 0 )
goto V_29;
if ( V_12 -> V_13 ) {
if ( V_12 -> V_13 -> V_30 -> V_28 )
V_25 = V_12 -> V_13 -> V_30 -> V_28 ( V_12 -> V_13 ,
V_27 ) ;
else
V_12 -> V_31 = V_27 ;
}
if ( V_25 != 0 )
goto V_29;
if ( V_14 && V_14 -> V_32 )
V_25 = V_14 -> V_32 ( V_14 , V_12 , V_27 ) ;
V_29:
F_23 ( V_14 , V_27 ) ;
return V_25 ;
}
static void F_24 ( struct V_8 * V_17 ,
struct V_33 * V_34 , int V_35 )
{
switch ( V_17 -> V_36 ) {
case V_37 :
case V_38 :
case V_39 : {
int V_19 ;
struct V_40 * V_41 = (struct V_40 * )
V_17 -> V_42 [ V_35 ] . V_43 ;
unsigned int V_18 = V_41 -> V_18 ;
unsigned int V_44 = V_41 -> V_44 ;
int V_45 = V_41 -> V_45 ;
unsigned int V_20 = ( 1 << F_25 ( V_45 ) ) - 1 ;
unsigned int V_46 = V_41 -> V_46 ;
V_19 = F_13 ( V_17 , V_18 ) ;
V_19 = ( V_19 >> V_44 ) & V_20 ;
if ( ( V_46 && ! V_19 ) || ( ! V_46 && V_19 ) )
V_34 -> V_47 = 1 ;
else
V_34 -> V_47 = 0 ;
}
break;
case V_48 : {
struct V_49 * V_50 = (struct V_49 * )
V_17 -> V_42 [ V_35 ] . V_43 ;
int V_19 , V_51 , V_52 ;
for ( V_52 = 1 ; V_52 < V_50 -> V_45 ; V_52 <<= 1 )
;
V_19 = F_13 ( V_17 , V_50 -> V_18 ) ;
V_51 = ( V_19 >> V_50 -> V_53 ) & ( V_52 - 1 ) ;
V_34 -> V_47 = 0 ;
for ( V_35 = 0 ; V_35 < V_50 -> V_45 ; V_35 ++ ) {
if ( ! ( strcmp ( V_34 -> V_54 , V_50 -> V_55 [ V_35 ] ) ) && V_51 == V_35 )
V_34 -> V_47 = 1 ;
}
}
break;
case V_56 : {
struct V_49 * V_50 = (struct V_49 * )
V_17 -> V_42 [ V_35 ] . V_43 ;
V_34 -> V_47 = 0 ;
if ( ! strcmp ( V_34 -> V_54 , V_50 -> V_55 [ 0 ] ) )
V_34 -> V_47 = 1 ;
}
break;
case V_57 : {
struct V_49 * V_50 = (struct V_49 * )
V_17 -> V_42 [ V_35 ] . V_43 ;
int V_19 , V_51 ;
V_19 = F_13 ( V_17 , V_50 -> V_18 ) ;
V_19 = ( V_19 >> V_50 -> V_53 ) & V_50 -> V_20 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_45 ; V_51 ++ ) {
if ( V_19 == V_50 -> V_58 [ V_51 ] )
break;
}
V_34 -> V_47 = 0 ;
for ( V_35 = 0 ; V_35 < V_50 -> V_45 ; V_35 ++ ) {
if ( ! ( strcmp ( V_34 -> V_54 , V_50 -> V_55 [ V_35 ] ) ) && V_51 == V_35 )
V_34 -> V_47 = 1 ;
}
}
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_34 -> V_47 = 1 ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_34 -> V_47 = 0 ;
break;
}
}
static int F_26 ( struct V_11 * V_12 ,
struct V_8 * V_76 , struct V_8 * V_77 ,
struct V_33 * V_78 , const char * V_79 ,
const struct V_80 * V_81 )
{
struct V_49 * V_50 = (struct V_49 * ) V_81 -> V_43 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_50 -> V_45 ; V_35 ++ ) {
if ( ! ( strcmp ( V_79 , V_50 -> V_55 [ V_35 ] ) ) ) {
F_27 ( & V_78 -> V_82 , & V_12 -> V_14 -> V_83 ) ;
F_27 ( & V_78 -> V_84 , & V_77 -> V_85 ) ;
F_27 ( & V_78 -> V_86 , & V_76 -> V_87 ) ;
V_78 -> V_54 = ( char * ) V_50 -> V_55 [ V_35 ] ;
F_24 ( V_77 , V_78 , 0 ) ;
return 0 ;
}
}
return - V_88 ;
}
static int F_28 ( struct V_11 * V_12 ,
struct V_8 * V_76 , struct V_8 * V_77 ,
struct V_33 * V_78 , const char * V_79 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_77 -> V_89 ; V_35 ++ ) {
if ( ! strcmp ( V_79 , V_77 -> V_42 [ V_35 ] . V_54 ) ) {
F_27 ( & V_78 -> V_82 , & V_12 -> V_14 -> V_83 ) ;
F_27 ( & V_78 -> V_84 , & V_77 -> V_85 ) ;
F_27 ( & V_78 -> V_86 , & V_76 -> V_87 ) ;
V_78 -> V_54 = V_77 -> V_42 [ V_35 ] . V_54 ;
F_24 ( V_77 , V_78 , V_35 ) ;
return 0 ;
}
}
return - V_88 ;
}
static int F_29 ( struct V_11 * V_12 ,
struct V_8 * V_90 ,
const struct V_80 * V_91 ,
struct V_92 * * V_81 )
{
struct V_8 * V_17 ;
int V_35 ;
* V_81 = NULL ;
F_30 (w, &dapm->card->widgets, list) {
if ( V_17 == V_90 || V_17 -> V_12 != V_90 -> V_12 )
continue;
for ( V_35 = 0 ; V_35 < V_17 -> V_89 ; V_35 ++ ) {
if ( & V_17 -> V_42 [ V_35 ] == V_91 ) {
if ( V_17 -> V_93 )
* V_81 = V_17 -> V_93 [ V_35 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_31 ( struct V_8 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
int V_35 , V_25 = 0 ;
T_3 V_94 , V_95 ;
struct V_33 * V_78 ;
struct V_10 * V_14 = V_12 -> V_14 -> V_10 ;
const char * V_96 ;
struct V_97 * V_98 ;
T_3 V_99 ;
if ( V_12 -> V_13 )
V_96 = V_12 -> V_13 -> V_100 ;
else
V_96 = NULL ;
if ( V_96 )
V_95 = strlen ( V_96 ) + 1 ;
else
V_95 = 0 ;
for ( V_35 = 0 ; V_35 < V_17 -> V_89 ; V_35 ++ ) {
F_30 (path, &w->sources, list_sink) {
if ( V_78 -> V_54 != ( char * ) V_17 -> V_42 [ V_35 ] . V_54 )
continue;
V_99 = sizeof( struct V_97 ) +
sizeof( struct V_8 * ) ,
V_98 = F_32 ( V_99 , V_7 ) ;
if ( V_98 == NULL ) {
F_16 ( V_12 -> V_3 ,
L_4 ,
V_17 -> V_54 ) ;
return - V_101 ;
}
V_98 -> V_102 = 1 ;
V_98 -> V_103 [ 0 ] = V_17 ;
V_94 = strlen ( V_17 -> V_42 [ V_35 ] . V_54 ) + 1 ;
if ( V_17 -> V_36 != V_39 )
V_94 += 1 + strlen ( V_17 -> V_54 ) ;
V_78 -> V_104 = F_5 ( V_94 , V_7 ) ;
if ( V_78 -> V_104 == NULL ) {
F_7 ( V_98 ) ;
return - V_101 ;
}
switch ( V_17 -> V_36 ) {
default:
snprintf ( V_78 -> V_104 , V_94 , L_5 ,
V_17 -> V_54 + V_95 ,
V_17 -> V_42 [ V_35 ] . V_54 ) ;
break;
case V_39 :
snprintf ( V_78 -> V_104 , V_94 , L_1 ,
V_17 -> V_42 [ V_35 ] . V_54 ) ;
break;
}
V_78 -> V_104 [ V_94 - 1 ] = '\0' ;
V_78 -> V_81 = F_33 ( & V_17 -> V_42 [ V_35 ] ,
V_98 , V_78 -> V_104 ,
V_96 ) ;
V_25 = F_34 ( V_14 , V_78 -> V_81 ) ;
if ( V_25 < 0 ) {
F_16 ( V_12 -> V_3 ,
L_6 ,
V_78 -> V_104 , V_25 ) ;
F_7 ( V_98 ) ;
F_7 ( V_78 -> V_104 ) ;
V_78 -> V_104 = NULL ;
return V_25 ;
}
V_17 -> V_93 [ V_35 ] = V_78 -> V_81 ;
}
}
return V_25 ;
}
static int F_35 ( struct V_8 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_33 * V_78 = NULL ;
struct V_92 * V_81 ;
struct V_10 * V_14 = V_12 -> V_14 -> V_10 ;
const char * V_96 ;
T_3 V_95 ;
int V_25 ;
struct V_97 * V_98 ;
int V_105 , V_106 ;
T_3 V_99 ;
char * V_54 ;
if ( V_17 -> V_89 != 1 ) {
F_16 ( V_12 -> V_3 ,
L_7 ,
V_17 -> V_54 ) ;
return - V_107 ;
}
V_105 = F_29 ( V_12 , V_17 , & V_17 -> V_42 [ 0 ] ,
& V_81 ) ;
if ( V_81 ) {
V_98 = V_81 -> V_108 ;
V_106 = V_98 -> V_102 + 1 ;
} else {
V_98 = NULL ;
V_106 = 1 ;
}
V_99 = sizeof( struct V_97 ) +
V_106 * sizeof( struct V_8 * ) ,
V_98 = F_36 ( V_98 , V_99 , V_7 ) ;
if ( V_98 == NULL ) {
F_16 ( V_12 -> V_3 ,
L_4 , V_17 -> V_54 ) ;
return - V_101 ;
}
V_98 -> V_102 = V_106 ;
V_98 -> V_103 [ V_106 - 1 ] = V_17 ;
if ( ! V_81 ) {
if ( V_12 -> V_13 )
V_96 = V_12 -> V_13 -> V_100 ;
else
V_96 = NULL ;
if ( V_105 ) {
V_54 = V_17 -> V_42 [ 0 ] . V_54 ;
V_95 = 0 ;
} else {
V_54 = V_17 -> V_54 ;
if ( V_96 )
V_95 = strlen ( V_96 ) + 1 ;
else
V_95 = 0 ;
}
V_81 = F_33 ( & V_17 -> V_42 [ 0 ] , V_98 ,
V_54 + V_95 , V_96 ) ;
V_25 = F_34 ( V_14 , V_81 ) ;
if ( V_25 < 0 ) {
F_16 ( V_12 -> V_3 ,
L_8 , V_17 -> V_54 ) ;
F_7 ( V_98 ) ;
return V_25 ;
}
}
V_81 -> V_108 = V_98 ;
V_17 -> V_93 [ 0 ] = V_81 ;
F_30 (path, &w->sources, list_sink)
V_78 -> V_81 = V_81 ;
return 0 ;
}
static int F_37 ( struct V_8 * V_17 )
{
if ( V_17 -> V_89 )
F_16 ( V_17 -> V_12 -> V_3 ,
L_9 , V_17 -> V_54 ) ;
return 0 ;
}
static inline void F_38 ( struct V_11 * V_12 )
{
struct V_33 * V_34 ;
F_30 (p, &dapm->card->paths, list)
V_34 -> V_109 = 0 ;
}
static int F_39 ( struct V_8 * V_110 )
{
int V_27 = F_40 ( V_110 -> V_12 -> V_14 -> V_10 ) ;
switch ( V_27 ) {
case V_111 :
case V_112 :
if ( V_110 -> V_113 )
F_41 ( V_110 -> V_12 -> V_3 , L_10 ,
V_110 -> V_54 ) ;
return V_110 -> V_113 ;
default:
return 1 ;
}
}
static int F_42 ( struct V_8 * V_110 )
{
struct V_33 * V_78 ;
int V_114 = 0 ;
if ( V_110 -> V_36 == V_67 )
return 0 ;
switch ( V_110 -> V_36 ) {
case V_62 :
case V_69 :
if ( V_110 -> V_115 )
return F_39 ( V_110 ) ;
default:
break;
}
if ( V_110 -> V_116 ) {
if ( V_110 -> V_36 == V_61 && ! V_110 -> V_117 )
return F_39 ( V_110 ) ;
if ( V_110 -> V_36 == V_70 || V_110 -> V_36 == V_72 ||
( V_110 -> V_36 == V_73 && ! F_43 ( & V_110 -> V_85 ) ) )
return F_39 ( V_110 ) ;
}
F_30 (path, &widget->sinks, list_source) {
if ( V_78 -> V_118 )
continue;
if ( V_78 -> V_109 )
continue;
if ( V_78 -> V_119 && V_78 -> V_47 ) {
V_78 -> V_109 = 1 ;
V_114 += F_42 ( V_78 -> V_119 ) ;
}
}
return V_114 ;
}
static int F_44 ( struct V_8 * V_110 )
{
struct V_33 * V_78 ;
int V_114 = 0 ;
if ( V_110 -> V_36 == V_67 )
return 0 ;
switch ( V_110 -> V_36 ) {
case V_64 :
case V_68 :
if ( V_110 -> V_115 )
return F_39 ( V_110 ) ;
default:
break;
}
if ( V_110 -> V_116 ) {
if ( V_110 -> V_36 == V_63 && ! V_110 -> V_117 )
return F_39 ( V_110 ) ;
if ( V_110 -> V_36 == V_66 )
return F_39 ( V_110 ) ;
if ( V_110 -> V_36 == V_71 ||
( V_110 -> V_36 == V_73 && ! F_43 ( & V_110 -> V_87 ) ) )
return F_39 ( V_110 ) ;
}
F_30 (path, &widget->sources, list_sink) {
if ( V_78 -> V_118 )
continue;
if ( V_78 -> V_109 )
continue;
if ( V_78 -> V_120 && V_78 -> V_47 ) {
V_78 -> V_109 = 1 ;
V_114 += F_44 ( V_78 -> V_120 ) ;
}
}
return V_114 ;
}
int F_45 ( struct V_8 * V_17 ,
struct V_92 * V_81 , int V_121 )
{
unsigned int V_19 ;
if ( F_46 ( V_121 ) )
V_19 = V_17 -> V_122 ;
else
V_19 = V_17 -> V_123 ;
F_20 ( V_17 , - ( V_17 -> V_18 + 1 ) ,
V_17 -> V_20 << V_17 -> V_44 , V_19 << V_17 -> V_44 ) ;
return 0 ;
}
static int F_47 ( struct V_8 * V_17 )
{
int V_124 , V_29 ;
V_124 = F_44 ( V_17 ) ;
F_38 ( V_17 -> V_12 ) ;
V_29 = F_42 ( V_17 ) ;
F_38 ( V_17 -> V_12 ) ;
return V_29 != 0 && V_124 != 0 ;
}
static int F_48 ( struct V_8 * V_17 )
{
int V_124 ;
if ( V_17 -> V_115 ) {
V_124 = F_44 ( V_17 ) ;
F_38 ( V_17 -> V_12 ) ;
return V_124 != 0 ;
} else {
return F_47 ( V_17 ) ;
}
}
static int F_49 ( struct V_8 * V_17 )
{
int V_29 ;
if ( V_17 -> V_115 ) {
V_29 = F_42 ( V_17 ) ;
F_38 ( V_17 -> V_12 ) ;
return V_29 != 0 ;
} else {
return F_47 ( V_17 ) ;
}
}
static int F_50 ( struct V_8 * V_17 )
{
struct V_33 * V_78 ;
int V_125 = 0 ;
F_30 (path, &w->sinks, list_source) {
if ( V_78 -> V_118 )
continue;
if ( V_78 -> V_116 &&
! V_78 -> V_116 ( V_78 -> V_120 , V_78 -> V_119 ) )
continue;
if ( ! V_78 -> V_119 )
continue;
if ( V_78 -> V_119 -> V_126 ) {
V_125 = 1 ;
break;
}
if ( V_78 -> V_119 -> V_127 &&
V_78 -> V_119 -> V_127 ( V_78 -> V_119 ) ) {
V_125 = 1 ;
break;
}
}
F_38 ( V_17 -> V_12 ) ;
return V_125 ;
}
static int F_51 ( struct V_8 * V_128 ,
struct V_8 * V_129 ,
bool V_130 )
{
int * V_131 ;
if ( V_130 )
V_131 = V_132 ;
else
V_131 = V_133 ;
if ( V_131 [ V_128 -> V_36 ] != V_131 [ V_129 -> V_36 ] )
return V_131 [ V_128 -> V_36 ] - V_131 [ V_129 -> V_36 ] ;
if ( V_128 -> V_134 != V_129 -> V_134 ) {
if ( V_130 )
return V_128 -> V_134 - V_129 -> V_134 ;
else
return V_129 -> V_134 - V_128 -> V_134 ;
}
if ( V_128 -> V_18 != V_129 -> V_18 )
return V_128 -> V_18 - V_129 -> V_18 ;
if ( V_128 -> V_12 != V_129 -> V_12 )
return ( unsigned long ) V_128 -> V_12 - ( unsigned long ) V_129 -> V_12 ;
return 0 ;
}
static void F_52 ( struct V_8 * V_135 ,
struct V_136 * V_82 ,
bool V_130 )
{
struct V_8 * V_17 ;
F_30 (w, list, power_list)
if ( F_51 ( V_135 , V_17 , V_130 ) < 0 ) {
F_53 ( & V_135 -> V_137 , & V_17 -> V_137 ) ;
return;
}
F_53 ( & V_135 -> V_137 , V_82 ) ;
}
static void F_54 ( struct V_11 * V_12 ,
struct V_8 * V_17 , int V_121 )
{
struct V_16 * V_14 = V_12 -> V_14 ;
const char * V_138 ;
int V_125 , V_25 ;
switch ( V_121 ) {
case V_139 :
V_138 = L_11 ;
V_125 = 1 ;
break;
case V_140 :
V_138 = L_12 ;
V_125 = 1 ;
break;
case V_141 :
V_138 = L_13 ;
V_125 = 0 ;
break;
case V_142 :
V_138 = L_14 ;
V_125 = 0 ;
break;
default:
F_11 () ;
return;
}
if ( V_17 -> V_125 != V_125 )
return;
if ( V_17 -> V_121 && ( V_17 -> V_143 & V_121 ) ) {
F_4 ( V_12 -> V_3 , V_14 -> V_1 , L_15 ,
V_17 -> V_54 , V_138 ) ;
F_55 ( V_17 , V_121 ) ;
V_25 = V_17 -> V_121 ( V_17 , NULL , V_121 ) ;
F_56 ( V_17 , V_121 ) ;
if ( V_25 < 0 )
F_57 ( L_16 ,
V_138 , V_17 -> V_54 , V_25 ) ;
}
}
static void F_58 ( struct V_11 * V_12 ,
struct V_136 * V_144 )
{
struct V_16 * V_14 = V_12 -> V_14 ;
struct V_8 * V_17 ;
int V_18 , V_125 ;
unsigned int V_21 = 0 ;
unsigned int V_20 = 0 ;
unsigned int V_145 ;
V_18 = F_59 ( V_144 , struct V_8 ,
V_137 ) -> V_18 ;
F_30 (w, pending, power_list) {
V_145 = 1 << V_17 -> V_44 ;
F_60 ( V_18 != V_17 -> V_18 ) ;
if ( V_17 -> V_46 )
V_125 = ! V_17 -> V_125 ;
else
V_125 = V_17 -> V_125 ;
V_20 |= V_145 ;
if ( V_125 )
V_21 |= V_145 ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_17 ,
V_17 -> V_54 , V_18 , V_21 , V_20 ) ;
F_54 ( V_12 , V_17 , V_139 ) ;
F_54 ( V_12 , V_17 , V_141 ) ;
}
if ( V_18 >= 0 ) {
V_17 = F_59 ( V_144 , struct V_8 ,
V_137 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_18 ,
V_21 , V_20 , V_18 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_20 ( V_17 , V_18 , V_20 , V_21 ) ;
}
F_30 (w, pending, power_list) {
F_54 ( V_12 , V_17 , V_140 ) ;
F_54 ( V_12 , V_17 , V_142 ) ;
}
}
static void F_61 ( struct V_11 * V_12 ,
struct V_136 * V_82 , int V_121 , bool V_130 )
{
struct V_8 * V_17 , * V_146 ;
F_62 ( V_144 ) ;
int V_147 = - 1 ;
int V_148 = - 1 ;
int V_149 = V_150 ;
struct V_11 * V_151 = NULL ;
int V_25 , V_35 ;
int * V_131 ;
if ( V_130 )
V_131 = V_132 ;
else
V_131 = V_133 ;
F_63 (w, n, list, power_list) {
V_25 = 0 ;
if ( V_131 [ V_17 -> V_36 ] != V_147 || V_17 -> V_18 != V_149 ||
V_17 -> V_12 != V_151 || V_17 -> V_134 != V_148 ) {
if ( ! F_43 ( & V_144 ) )
F_58 ( V_151 , & V_144 ) ;
if ( V_151 && V_151 -> V_152 ) {
for ( V_35 = 0 ; V_35 < F_64 ( V_132 ) ; V_35 ++ )
if ( V_131 [ V_35 ] == V_147 )
V_151 -> V_152 ( V_151 ,
V_35 ,
V_148 ) ;
}
F_65 ( & V_144 ) ;
V_147 = - 1 ;
V_148 = V_153 ;
V_149 = V_150 ;
V_151 = NULL ;
}
switch ( V_17 -> V_36 ) {
case V_74 :
if ( ! V_17 -> V_121 )
F_66 ( V_17 , V_146 , V_82 ,
V_137 ) ;
if ( V_121 == V_154 )
V_25 = V_17 -> V_121 ( V_17 ,
NULL , V_139 ) ;
else if ( V_121 == V_155 )
V_25 = V_17 -> V_121 ( V_17 ,
NULL , V_141 ) ;
break;
case V_75 :
if ( ! V_17 -> V_121 )
F_66 ( V_17 , V_146 , V_82 ,
V_137 ) ;
if ( V_121 == V_154 )
V_25 = V_17 -> V_121 ( V_17 ,
NULL , V_140 ) ;
else if ( V_121 == V_155 )
V_25 = V_17 -> V_121 ( V_17 ,
NULL , V_142 ) ;
break;
default:
V_147 = V_131 [ V_17 -> V_36 ] ;
V_148 = V_17 -> V_134 ;
V_149 = V_17 -> V_18 ;
V_151 = V_17 -> V_12 ;
F_67 ( & V_17 -> V_137 , & V_144 ) ;
break;
}
if ( V_25 < 0 )
F_16 ( V_17 -> V_12 -> V_3 ,
L_19 , V_25 ) ;
}
if ( ! F_43 ( & V_144 ) )
F_58 ( V_151 , & V_144 ) ;
if ( V_151 && V_151 -> V_152 ) {
for ( V_35 = 0 ; V_35 < F_64 ( V_132 ) ; V_35 ++ )
if ( V_131 [ V_35 ] == V_147 )
V_151 -> V_152 ( V_151 ,
V_35 , V_148 ) ;
}
}
static void F_68 ( struct V_11 * V_12 )
{
struct V_156 * V_157 = V_12 -> V_157 ;
struct V_8 * V_17 ;
int V_25 ;
if ( ! V_157 )
return;
V_17 = V_157 -> V_110 ;
if ( V_17 -> V_121 &&
( V_17 -> V_143 & V_158 ) ) {
V_25 = V_17 -> V_121 ( V_17 , V_157 -> V_81 , V_158 ) ;
if ( V_25 != 0 )
F_57 ( L_20 ,
V_17 -> V_54 , V_25 ) ;
}
V_25 = F_69 ( V_17 -> V_13 , V_157 -> V_18 , V_157 -> V_20 ,
V_157 -> V_19 ) ;
if ( V_25 < 0 )
F_57 ( L_21 , V_17 -> V_54 , V_25 ) ;
if ( V_17 -> V_121 &&
( V_17 -> V_143 & V_159 ) ) {
V_25 = V_17 -> V_121 ( V_17 , V_157 -> V_81 , V_159 ) ;
if ( V_25 != 0 )
F_57 ( L_22 ,
V_17 -> V_54 , V_25 ) ;
}
}
static void F_70 ( void * V_160 , T_4 V_161 )
{
struct V_11 * V_162 = V_160 ;
int V_25 ;
if ( V_162 -> V_31 == V_163 &&
V_162 -> V_164 != V_163 ) {
V_25 = F_21 ( V_162 , V_165 ) ;
if ( V_25 != 0 )
F_16 ( V_162 -> V_3 ,
L_23 , V_25 ) ;
}
if ( V_162 -> V_31 != V_162 -> V_164 ) {
V_25 = F_21 ( V_162 , V_166 ) ;
if ( V_25 != 0 )
F_16 ( V_162 -> V_3 ,
L_24 , V_25 ) ;
}
}
static void F_71 ( void * V_160 , T_4 V_161 )
{
struct V_11 * V_162 = V_160 ;
int V_25 ;
if ( V_162 -> V_31 == V_166 &&
( V_162 -> V_164 == V_165 ||
V_162 -> V_164 == V_163 ) ) {
V_25 = F_21 ( V_162 , V_165 ) ;
if ( V_25 != 0 )
F_16 ( V_162 -> V_3 , L_25 ,
V_25 ) ;
}
if ( V_162 -> V_31 == V_165 &&
V_162 -> V_164 == V_163 ) {
V_25 = F_21 ( V_162 , V_163 ) ;
if ( V_25 != 0 )
F_16 ( V_162 -> V_3 , L_26 , V_25 ) ;
}
if ( V_162 -> V_31 == V_166 &&
V_162 -> V_164 == V_167 ) {
V_25 = F_21 ( V_162 , V_167 ) ;
if ( V_25 != 0 )
F_16 ( V_162 -> V_3 , L_27 ,
V_25 ) ;
}
}
static int F_72 ( struct V_11 * V_12 , int V_121 )
{
struct V_16 * V_14 = V_12 -> V_14 ;
struct V_8 * V_17 ;
struct V_11 * V_162 ;
F_62 ( V_168 ) ;
F_62 ( V_169 ) ;
F_62 ( V_170 ) ;
enum V_26 V_171 ;
int V_125 ;
F_73 ( V_14 ) ;
F_30 (d, &card->dapm_list, list) {
if ( V_162 -> V_172 || V_162 -> V_13 == NULL ) {
if ( V_162 -> V_173 )
V_162 -> V_164 = V_163 ;
else
V_162 -> V_164 = V_165 ;
}
}
F_30 (w, &card->widgets, list) {
switch ( V_17 -> V_36 ) {
case V_74 :
F_52 ( V_17 , & V_169 , false ) ;
break;
case V_75 :
F_52 ( V_17 , & V_168 , true ) ;
break;
default:
if ( ! V_17 -> V_127 )
continue;
if ( ! V_17 -> V_126 )
V_125 = V_17 -> V_127 ( V_17 ) ;
else
V_125 = 1 ;
if ( V_125 ) {
V_162 = V_17 -> V_12 ;
switch ( V_17 -> V_36 ) {
case V_67 :
case V_65 :
if ( V_162 -> V_164 < V_165 )
V_162 -> V_164 = V_165 ;
break;
default:
V_162 -> V_164 = V_167 ;
break;
}
}
if ( V_17 -> V_125 == V_125 )
continue;
F_74 ( V_17 , V_125 ) ;
if ( V_125 )
F_52 ( V_17 , & V_168 , true ) ;
else
F_52 ( V_17 , & V_169 , false ) ;
V_17 -> V_125 = V_125 ;
break;
}
}
if ( ! V_12 -> V_172 ) {
switch ( V_121 ) {
case V_154 :
case V_174 :
V_12 -> V_164 = V_167 ;
break;
case V_155 :
if ( V_12 -> V_13 -> V_115 )
V_12 -> V_164 = V_167 ;
else
V_12 -> V_164 = V_165 ;
break;
case V_175 :
V_12 -> V_164 = V_165 ;
break;
case V_176 :
V_12 -> V_164 = V_12 -> V_31 ;
break;
default:
break;
}
}
V_171 = V_163 ;
F_30 (d, &card->dapm_list, list)
if ( V_162 -> V_164 > V_171 )
V_171 = V_162 -> V_164 ;
F_30 (d, &card->dapm_list, list)
V_162 -> V_164 = V_171 ;
F_30 (d, &dapm->card->dapm_list, list)
F_75 ( F_70 , V_162 ,
& V_170 ) ;
F_76 ( & V_170 ) ;
F_61 ( V_12 , & V_169 , V_121 , false ) ;
F_68 ( V_12 ) ;
F_61 ( V_12 , & V_168 , V_121 , true ) ;
F_30 (d, &dapm->card->dapm_list, list)
F_75 ( F_71 , V_162 ,
& V_170 ) ;
F_76 ( & V_170 ) ;
F_4 ( V_12 -> V_3 , V_14 -> V_1 ,
L_28 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_77 ( V_14 ) ;
return 0 ;
}
static int F_78 ( struct V_177 * V_177 , struct V_178 * V_178 )
{
V_178 -> V_108 = V_177 -> V_179 ;
return 0 ;
}
static T_5 F_79 ( struct V_178 * V_178 ,
char T_6 * V_180 ,
T_3 V_181 , T_7 * V_182 )
{
struct V_8 * V_17 = V_178 -> V_108 ;
char * V_5 ;
int V_124 , V_29 ;
T_5 V_25 ;
struct V_33 * V_34 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_101 ;
V_124 = F_44 ( V_17 ) ;
F_38 ( V_17 -> V_12 ) ;
V_29 = F_42 ( V_17 ) ;
F_38 ( V_17 -> V_12 ) ;
V_25 = snprintf ( V_5 , V_6 , L_29 ,
V_17 -> V_54 , V_17 -> V_125 ? L_30 : L_31 , V_124 , V_29 ) ;
if ( V_17 -> V_18 >= 0 )
V_25 += snprintf ( V_5 + V_25 , V_6 - V_25 ,
L_32 ,
V_17 -> V_18 , V_17 -> V_18 , V_17 -> V_44 ) ;
V_25 += snprintf ( V_5 + V_25 , V_6 - V_25 , L_33 ) ;
if ( V_17 -> V_183 )
V_25 += snprintf ( V_5 + V_25 , V_6 - V_25 , L_34 ,
V_17 -> V_183 ,
V_17 -> V_115 ? L_35 : L_36 ) ;
F_30 (p, &w->sources, list_sink) {
if ( V_34 -> V_116 && ! V_34 -> V_116 ( V_17 , V_34 -> V_119 ) )
continue;
if ( V_34 -> V_47 )
V_25 += snprintf ( V_5 + V_25 , V_6 - V_25 ,
L_37 ,
V_34 -> V_54 ? V_34 -> V_54 : L_38 ,
V_34 -> V_120 -> V_54 ) ;
}
F_30 (p, &w->sinks, list_source) {
if ( V_34 -> V_116 && ! V_34 -> V_116 ( V_17 , V_34 -> V_119 ) )
continue;
if ( V_34 -> V_47 )
V_25 += snprintf ( V_5 + V_25 , V_6 - V_25 ,
L_39 ,
V_34 -> V_54 ? V_34 -> V_54 : L_38 ,
V_34 -> V_119 -> V_54 ) ;
}
V_25 = F_80 ( V_180 , V_181 , V_182 , V_5 , V_25 ) ;
F_7 ( V_5 ) ;
return V_25 ;
}
static int F_81 ( struct V_177 * V_177 , struct V_178 * V_178 )
{
V_178 -> V_108 = V_177 -> V_179 ;
return 0 ;
}
static T_5 F_82 ( struct V_178 * V_178 , char T_6 * V_180 ,
T_3 V_181 , T_7 * V_182 )
{
struct V_11 * V_12 = V_178 -> V_108 ;
char * V_27 ;
switch ( V_12 -> V_31 ) {
case V_167 :
V_27 = L_40 ;
break;
case V_166 :
V_27 = L_41 ;
break;
case V_165 :
V_27 = L_42 ;
break;
case V_163 :
V_27 = L_43 ;
break;
default:
F_11 () ;
V_27 = L_44 ;
break;
}
return F_80 ( V_180 , V_181 , V_182 , V_27 ,
strlen ( V_27 ) ) ;
}
void F_83 ( struct V_11 * V_12 ,
struct V_184 * V_185 )
{
struct V_184 * V_162 ;
V_12 -> V_186 = F_84 ( L_45 , V_185 ) ;
if ( ! V_12 -> V_186 ) {
F_85 ( V_187
L_46 ) ;
return;
}
V_162 = F_86 ( L_47 , 0444 ,
V_12 -> V_186 , V_12 ,
& V_188 ) ;
if ( ! V_162 )
F_87 ( V_12 -> V_3 ,
L_48 ) ;
}
static void F_88 ( struct V_8 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_184 * V_162 ;
if ( ! V_12 -> V_186 || ! V_17 -> V_54 )
return;
V_162 = F_86 ( V_17 -> V_54 , 0444 ,
V_12 -> V_186 , V_17 ,
& V_189 ) ;
if ( ! V_162 )
F_87 ( V_17 -> V_12 -> V_3 ,
L_49 ,
V_17 -> V_54 ) ;
}
static void F_89 ( struct V_11 * V_12 )
{
F_90 ( V_12 -> V_186 ) ;
}
void F_83 ( struct V_11 * V_12 ,
struct V_184 * V_185 )
{
}
static inline void F_88 ( struct V_8 * V_17 )
{
}
static inline void F_89 ( struct V_11 * V_12 )
{
}
static int F_91 ( struct V_8 * V_110 ,
struct V_92 * V_81 , int V_22 ,
int V_190 , struct V_49 * V_50 )
{
struct V_33 * V_78 ;
int V_191 = 0 ;
if ( V_110 -> V_36 != V_48 &&
V_110 -> V_36 != V_56 &&
V_110 -> V_36 != V_57 )
return - V_88 ;
if ( ! V_22 )
return 0 ;
F_30 (path, &widget->dapm->card->paths, list) {
if ( V_78 -> V_81 != V_81 )
continue;
if ( ! V_78 -> V_54 || ! V_50 -> V_55 [ V_190 ] )
continue;
V_191 = 1 ;
if ( ! ( strcmp ( V_78 -> V_54 , V_50 -> V_55 [ V_190 ] ) ) )
V_78 -> V_47 = 1 ;
else
V_78 -> V_47 = 0 ;
}
if ( V_191 )
F_72 ( V_110 -> V_12 , V_176 ) ;
return 0 ;
}
static int F_92 ( struct V_8 * V_110 ,
struct V_92 * V_81 , int V_47 )
{
struct V_33 * V_78 ;
int V_191 = 0 ;
if ( V_110 -> V_36 != V_38 &&
V_110 -> V_36 != V_39 &&
V_110 -> V_36 != V_37 )
return - V_88 ;
F_30 (path, &widget->dapm->card->paths, list) {
if ( V_78 -> V_81 != V_81 )
continue;
V_191 = 1 ;
V_78 -> V_47 = V_47 ;
break;
}
if ( V_191 )
F_72 ( V_110 -> V_12 , V_176 ) ;
return 0 ;
}
static T_5 F_93 ( struct V_2 * V_3 ,
struct V_192 * V_193 , char * V_5 )
{
struct V_194 * V_195 =
F_94 ( V_3 , struct V_194 , V_3 ) ;
struct V_196 * V_13 = V_195 -> V_13 ;
struct V_8 * V_17 ;
int V_181 = 0 ;
char * V_197 = L_50 ;
F_30 (w, &codec->card->widgets, list) {
if ( V_17 -> V_12 != & V_13 -> V_12 )
continue;
switch ( V_17 -> V_36 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_65 :
case V_64 :
case V_62 :
case V_59 :
case V_60 :
case V_38 :
case V_39 :
case V_67 :
if ( V_17 -> V_54 )
V_181 += sprintf ( V_5 + V_181 , L_51 ,
V_17 -> V_54 , V_17 -> V_125 ? L_30 : L_31 ) ;
break;
default:
break;
}
}
switch ( V_13 -> V_12 . V_31 ) {
case V_167 :
V_197 = L_30 ;
break;
case V_166 :
V_197 = L_52 ;
break;
case V_165 :
V_197 = L_53 ;
break;
case V_163 :
V_197 = L_31 ;
break;
}
V_181 += sprintf ( V_5 + V_181 , L_54 , V_197 ) ;
return V_181 ;
}
int F_95 ( struct V_2 * V_3 )
{
return F_96 ( V_3 , & V_198 ) ;
}
static void F_97 ( struct V_2 * V_3 )
{
F_98 ( V_3 , & V_198 ) ;
}
static void F_99 ( struct V_11 * V_12 )
{
struct V_8 * V_17 , * V_199 ;
struct V_33 * V_34 , * V_200 ;
F_63 (w, next_w, &dapm->card->widgets, list) {
if ( V_17 -> V_12 != V_12 )
continue;
F_100 ( & V_17 -> V_82 ) ;
F_63 (p, next_p, &w->sources, list_sink) {
F_100 ( & V_34 -> V_84 ) ;
F_100 ( & V_34 -> V_86 ) ;
F_100 ( & V_34 -> V_82 ) ;
F_7 ( V_34 -> V_104 ) ;
F_7 ( V_34 ) ;
}
F_63 (p, next_p, &w->sinks, list_source) {
F_100 ( & V_34 -> V_84 ) ;
F_100 ( & V_34 -> V_86 ) ;
F_100 ( & V_34 -> V_82 ) ;
F_7 ( V_34 -> V_104 ) ;
F_7 ( V_34 ) ;
}
F_7 ( V_17 -> V_93 ) ;
F_7 ( V_17 -> V_54 ) ;
F_7 ( V_17 ) ;
}
}
static struct V_8 * F_101 (
struct V_11 * V_12 , const char * V_201 ,
bool V_202 )
{
struct V_8 * V_17 ;
struct V_8 * V_203 = NULL ;
F_30 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_17 -> V_54 , V_201 ) ) {
if ( V_17 -> V_12 == V_12 )
return V_17 ;
else
V_203 = V_17 ;
}
}
if ( V_202 )
return V_203 ;
return NULL ;
}
static int F_102 ( struct V_11 * V_12 ,
const char * V_201 , int V_204 )
{
struct V_8 * V_17 = F_101 ( V_12 , V_201 , true ) ;
if ( ! V_17 ) {
F_16 ( V_12 -> V_3 , L_55 , V_201 ) ;
return - V_107 ;
}
V_17 -> V_116 = V_204 ;
if ( V_204 == 0 )
V_17 -> V_126 = 0 ;
return 0 ;
}
int F_103 ( struct V_11 * V_12 )
{
return F_72 ( V_12 , V_176 ) ;
}
static int F_104 ( struct V_11 * V_12 ,
const struct V_205 * V_206 )
{
struct V_33 * V_78 ;
struct V_8 * V_207 = NULL , * V_208 = NULL , * V_17 ;
struct V_8 * V_209 = NULL , * V_210 = NULL ;
const char * V_119 ;
const char * V_211 = V_206 -> V_211 ;
const char * V_120 ;
char V_212 [ 80 ] ;
char V_213 [ 80 ] ;
int V_25 = 0 ;
if ( V_12 -> V_13 && V_12 -> V_13 -> V_100 ) {
snprintf ( V_212 , sizeof( V_212 ) , L_5 ,
V_12 -> V_13 -> V_100 , V_206 -> V_119 ) ;
V_119 = V_212 ;
snprintf ( V_213 , sizeof( V_213 ) , L_5 ,
V_12 -> V_13 -> V_100 , V_206 -> V_120 ) ;
V_120 = V_213 ;
} else {
V_119 = V_206 -> V_119 ;
V_120 = V_206 -> V_120 ;
}
F_30 (w, &dapm->card->widgets, list) {
if ( ! V_208 && ! ( strcmp ( V_17 -> V_54 , V_119 ) ) ) {
V_210 = V_17 ;
if ( V_17 -> V_12 == V_12 )
V_208 = V_17 ;
continue;
}
if ( ! V_207 && ! ( strcmp ( V_17 -> V_54 , V_120 ) ) ) {
V_209 = V_17 ;
if ( V_17 -> V_12 == V_12 )
V_207 = V_17 ;
}
}
if ( ! V_208 )
V_208 = V_210 ;
if ( ! V_207 )
V_207 = V_209 ;
if ( V_207 == NULL || V_208 == NULL )
return - V_88 ;
V_78 = F_32 ( sizeof( struct V_33 ) , V_7 ) ;
if ( ! V_78 )
return - V_101 ;
V_78 -> V_120 = V_207 ;
V_78 -> V_119 = V_208 ;
V_78 -> V_116 = V_206 -> V_116 ;
F_65 ( & V_78 -> V_82 ) ;
F_65 ( & V_78 -> V_86 ) ;
F_65 ( & V_78 -> V_84 ) ;
if ( V_208 -> V_36 == V_63 ) {
if ( V_207 -> V_36 == V_65 ||
V_207 -> V_36 == V_71 ||
V_207 -> V_36 == V_73 ||
V_207 -> V_36 == V_61 )
V_208 -> V_117 = 1 ;
}
if ( V_207 -> V_36 == V_61 ) {
if ( V_208 -> V_36 == V_72 ||
V_208 -> V_36 == V_70 ||
V_208 -> V_36 == V_73 ||
V_208 -> V_36 == V_63 )
V_207 -> V_117 = 1 ;
}
if ( V_211 == NULL ) {
F_27 ( & V_78 -> V_82 , & V_12 -> V_14 -> V_83 ) ;
F_27 ( & V_78 -> V_84 , & V_208 -> V_85 ) ;
F_27 ( & V_78 -> V_86 , & V_207 -> V_87 ) ;
V_78 -> V_47 = 1 ;
return 0 ;
}
switch ( V_208 -> V_36 ) {
case V_62 :
case V_64 :
case V_59 :
case V_60 :
case V_63 :
case V_61 :
case V_65 :
case V_66 :
case V_74 :
case V_75 :
case V_67 :
case V_68 :
case V_69 :
F_27 ( & V_78 -> V_82 , & V_12 -> V_14 -> V_83 ) ;
F_27 ( & V_78 -> V_84 , & V_208 -> V_85 ) ;
F_27 ( & V_78 -> V_86 , & V_207 -> V_87 ) ;
V_78 -> V_47 = 1 ;
return 0 ;
case V_48 :
case V_56 :
case V_57 :
V_25 = F_26 ( V_12 , V_207 , V_208 , V_78 , V_211 ,
& V_208 -> V_42 [ 0 ] ) ;
if ( V_25 != 0 )
goto V_214;
break;
case V_37 :
case V_38 :
case V_39 :
V_25 = F_28 ( V_12 , V_207 , V_208 , V_78 , V_211 ) ;
if ( V_25 != 0 )
goto V_214;
break;
case V_70 :
case V_71 :
case V_73 :
case V_72 :
F_27 ( & V_78 -> V_82 , & V_12 -> V_14 -> V_83 ) ;
F_27 ( & V_78 -> V_84 , & V_208 -> V_85 ) ;
F_27 ( & V_78 -> V_86 , & V_207 -> V_87 ) ;
V_78 -> V_47 = 0 ;
return 0 ;
}
return 0 ;
V_214:
F_87 ( V_12 -> V_3 , L_56 ,
V_120 , V_211 , V_119 ) ;
F_7 ( V_78 ) ;
return V_25 ;
}
int F_105 ( struct V_11 * V_12 ,
const struct V_205 * V_206 , int V_215 )
{
int V_35 , V_25 ;
for ( V_35 = 0 ; V_35 < V_215 ; V_35 ++ ) {
V_25 = F_104 ( V_12 , V_206 ) ;
if ( V_25 < 0 ) {
F_16 ( V_12 -> V_3 , L_57 ,
V_206 -> V_120 , V_206 -> V_119 ) ;
return V_25 ;
}
V_206 ++ ;
}
return 0 ;
}
static int F_106 ( struct V_11 * V_12 ,
const struct V_205 * V_206 )
{
struct V_8 * V_120 = F_101 ( V_12 ,
V_206 -> V_120 ,
true ) ;
struct V_8 * V_119 = F_101 ( V_12 ,
V_206 -> V_119 ,
true ) ;
struct V_33 * V_78 ;
int V_181 = 0 ;
if ( ! V_120 ) {
F_16 ( V_12 -> V_3 , L_58 ,
V_206 -> V_120 ) ;
return - V_88 ;
}
if ( ! V_119 ) {
F_16 ( V_12 -> V_3 , L_59 ,
V_206 -> V_119 ) ;
return - V_88 ;
}
if ( V_206 -> V_211 || V_206 -> V_116 )
F_87 ( V_12 -> V_3 , L_60 ,
V_206 -> V_120 , V_206 -> V_119 ) ;
F_30 (path, &source->sinks, list_source) {
if ( V_78 -> V_119 == V_119 ) {
V_78 -> V_118 = 1 ;
V_181 ++ ;
}
}
if ( V_181 == 0 )
F_16 ( V_12 -> V_3 , L_61 ,
V_206 -> V_120 , V_206 -> V_119 ) ;
if ( V_181 > 1 )
F_87 ( V_12 -> V_3 , L_62 ,
V_181 , V_206 -> V_120 , V_206 -> V_119 ) ;
return 0 ;
}
int F_107 ( struct V_11 * V_12 ,
const struct V_205 * V_206 , int V_215 )
{
int V_35 , V_214 ;
int V_25 = 0 ;
for ( V_35 = 0 ; V_35 < V_215 ; V_35 ++ ) {
V_214 = F_106 ( V_12 , V_206 ) ;
if ( V_214 )
V_25 = V_214 ;
V_206 ++ ;
}
return V_25 ;
}
int F_108 ( struct V_11 * V_12 )
{
struct V_8 * V_17 ;
unsigned int V_19 ;
F_30 (w, &dapm->card->widgets, list)
{
if ( V_17 -> V_24 )
continue;
if ( V_17 -> V_89 ) {
V_17 -> V_93 = F_32 ( V_17 -> V_89 *
sizeof( struct V_92 * ) ,
V_7 ) ;
if ( ! V_17 -> V_93 )
return - V_101 ;
}
switch( V_17 -> V_36 ) {
case V_37 :
case V_38 :
case V_39 :
V_17 -> V_127 = F_47 ;
F_31 ( V_17 ) ;
break;
case V_48 :
case V_56 :
case V_57 :
V_17 -> V_127 = F_47 ;
F_35 ( V_17 ) ;
break;
case V_62 :
case V_69 :
V_17 -> V_127 = F_48 ;
break;
case V_64 :
case V_68 :
V_17 -> V_127 = F_49 ;
break;
case V_59 :
case V_60 :
V_17 -> V_127 = F_47 ;
F_37 ( V_17 ) ;
break;
case V_63 :
case V_61 :
case V_65 :
case V_72 :
case V_70 :
case V_71 :
case V_73 :
V_17 -> V_127 = F_47 ;
break;
case V_67 :
V_17 -> V_127 = F_50 ;
case V_66 :
case V_74 :
case V_75 :
break;
}
if ( V_17 -> V_18 >= 0 ) {
V_19 = F_13 ( V_17 , V_17 -> V_18 ) ;
V_19 &= 1 << V_17 -> V_44 ;
if ( V_17 -> V_46 )
V_19 = ! V_19 ;
if ( V_19 )
V_17 -> V_125 = 1 ;
}
V_17 -> V_24 = 1 ;
F_88 ( V_17 ) ;
}
F_72 ( V_12 , V_176 ) ;
return 0 ;
}
int F_109 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_97 * V_98 = F_110 ( V_81 ) ;
struct V_8 * V_110 = V_98 -> V_103 [ 0 ] ;
struct V_40 * V_41 =
(struct V_40 * ) V_81 -> V_43 ;
unsigned int V_18 = V_41 -> V_18 ;
unsigned int V_44 = V_41 -> V_44 ;
unsigned int V_218 = V_41 -> V_218 ;
int V_45 = V_41 -> V_45 ;
unsigned int V_46 = V_41 -> V_46 ;
unsigned int V_20 = ( 1 << F_25 ( V_45 ) ) - 1 ;
V_217 -> V_21 . integer . V_21 [ 0 ] =
( F_14 ( V_110 -> V_13 , V_18 ) >> V_44 ) & V_20 ;
if ( V_44 != V_218 )
V_217 -> V_21 . integer . V_21 [ 1 ] =
( F_14 ( V_110 -> V_13 , V_18 ) >> V_218 ) & V_20 ;
if ( V_46 ) {
V_217 -> V_21 . integer . V_21 [ 0 ] =
V_45 - V_217 -> V_21 . integer . V_21 [ 0 ] ;
if ( V_44 != V_218 )
V_217 -> V_21 . integer . V_21 [ 1 ] =
V_45 - V_217 -> V_21 . integer . V_21 [ 1 ] ;
}
return 0 ;
}
int F_111 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_97 * V_98 = F_110 ( V_81 ) ;
struct V_8 * V_110 = V_98 -> V_103 [ 0 ] ;
struct V_196 * V_13 = V_110 -> V_13 ;
struct V_40 * V_41 =
(struct V_40 * ) V_81 -> V_43 ;
unsigned int V_18 = V_41 -> V_18 ;
unsigned int V_44 = V_41 -> V_44 ;
int V_45 = V_41 -> V_45 ;
unsigned int V_20 = ( 1 << F_25 ( V_45 ) ) - 1 ;
unsigned int V_46 = V_41 -> V_46 ;
unsigned int V_19 ;
int V_47 , V_22 ;
struct V_156 V_157 ;
int V_219 ;
V_19 = ( V_217 -> V_21 . integer . V_21 [ 0 ] & V_20 ) ;
if ( V_46 )
V_19 = V_45 - V_19 ;
V_20 = V_20 << V_44 ;
V_19 = V_19 << V_44 ;
if ( V_19 )
V_47 = V_46 ? 0 : 1 ;
else
V_47 = V_46 ? 1 : 0 ;
F_112 ( & V_13 -> V_220 ) ;
V_22 = F_113 ( V_110 -> V_13 , V_18 , V_20 , V_19 ) ;
if ( V_22 ) {
for ( V_219 = 0 ; V_219 < V_98 -> V_102 ; V_219 ++ ) {
V_110 = V_98 -> V_103 [ V_219 ] ;
V_110 -> V_21 = V_19 ;
V_157 . V_81 = V_81 ;
V_157 . V_110 = V_110 ;
V_157 . V_18 = V_18 ;
V_157 . V_20 = V_20 ;
V_157 . V_19 = V_19 ;
V_110 -> V_12 -> V_157 = & V_157 ;
F_92 ( V_110 , V_81 , V_47 ) ;
V_110 -> V_12 -> V_157 = NULL ;
}
}
F_114 ( & V_13 -> V_220 ) ;
return 0 ;
}
int F_115 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_97 * V_98 = F_110 ( V_81 ) ;
struct V_8 * V_110 = V_98 -> V_103 [ 0 ] ;
struct V_49 * V_50 = (struct V_49 * ) V_81 -> V_43 ;
unsigned int V_19 , V_52 ;
for ( V_52 = 1 ; V_52 < V_50 -> V_45 ; V_52 <<= 1 )
;
V_19 = F_14 ( V_110 -> V_13 , V_50 -> V_18 ) ;
V_217 -> V_21 . V_221 . V_51 [ 0 ] = ( V_19 >> V_50 -> V_53 ) & ( V_52 - 1 ) ;
if ( V_50 -> V_53 != V_50 -> V_222 )
V_217 -> V_21 . V_221 . V_51 [ 1 ] =
( V_19 >> V_50 -> V_222 ) & ( V_52 - 1 ) ;
return 0 ;
}
int F_116 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_97 * V_98 = F_110 ( V_81 ) ;
struct V_8 * V_110 = V_98 -> V_103 [ 0 ] ;
struct V_196 * V_13 = V_110 -> V_13 ;
struct V_49 * V_50 = (struct V_49 * ) V_81 -> V_43 ;
unsigned int V_19 , V_190 , V_22 ;
unsigned int V_20 , V_52 ;
struct V_156 V_157 ;
int V_219 ;
for ( V_52 = 1 ; V_52 < V_50 -> V_45 ; V_52 <<= 1 )
;
if ( V_217 -> V_21 . V_221 . V_51 [ 0 ] > V_50 -> V_45 - 1 )
return - V_107 ;
V_190 = V_217 -> V_21 . V_221 . V_51 [ 0 ] ;
V_19 = V_190 << V_50 -> V_53 ;
V_20 = ( V_52 - 1 ) << V_50 -> V_53 ;
if ( V_50 -> V_53 != V_50 -> V_222 ) {
if ( V_217 -> V_21 . V_221 . V_51 [ 1 ] > V_50 -> V_45 - 1 )
return - V_107 ;
V_19 |= V_217 -> V_21 . V_221 . V_51 [ 1 ] << V_50 -> V_222 ;
V_20 |= ( V_52 - 1 ) << V_50 -> V_222 ;
}
F_112 ( & V_13 -> V_220 ) ;
V_22 = F_113 ( V_110 -> V_13 , V_50 -> V_18 , V_20 , V_19 ) ;
if ( V_22 ) {
for ( V_219 = 0 ; V_219 < V_98 -> V_102 ; V_219 ++ ) {
V_110 = V_98 -> V_103 [ V_219 ] ;
V_110 -> V_21 = V_19 ;
V_157 . V_81 = V_81 ;
V_157 . V_110 = V_110 ;
V_157 . V_18 = V_50 -> V_18 ;
V_157 . V_20 = V_20 ;
V_157 . V_19 = V_19 ;
V_110 -> V_12 -> V_157 = & V_157 ;
F_91 ( V_110 , V_81 , V_22 , V_190 , V_50 ) ;
V_110 -> V_12 -> V_157 = NULL ;
}
}
F_114 ( & V_13 -> V_220 ) ;
return V_22 ;
}
int F_117 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_97 * V_98 = F_110 ( V_81 ) ;
struct V_8 * V_110 = V_98 -> V_103 [ 0 ] ;
V_217 -> V_21 . V_221 . V_51 [ 0 ] = V_110 -> V_21 ;
return 0 ;
}
int F_118 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_97 * V_98 = F_110 ( V_81 ) ;
struct V_8 * V_110 = V_98 -> V_103 [ 0 ] ;
struct V_196 * V_13 = V_110 -> V_13 ;
struct V_49 * V_50 =
(struct V_49 * ) V_81 -> V_43 ;
int V_22 ;
int V_25 = 0 ;
int V_219 ;
if ( V_217 -> V_21 . V_221 . V_51 [ 0 ] >= V_50 -> V_45 )
return - V_107 ;
F_112 ( & V_13 -> V_220 ) ;
V_22 = V_110 -> V_21 != V_217 -> V_21 . V_221 . V_51 [ 0 ] ;
if ( V_22 ) {
for ( V_219 = 0 ; V_219 < V_98 -> V_102 ; V_219 ++ ) {
V_110 = V_98 -> V_103 [ V_219 ] ;
V_110 -> V_21 = V_217 -> V_21 . V_221 . V_51 [ 0 ] ;
F_91 ( V_110 , V_81 , V_22 ,
V_110 -> V_21 , V_50 ) ;
}
}
F_114 ( & V_13 -> V_220 ) ;
return V_25 ;
}
int F_119 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_97 * V_98 = F_110 ( V_81 ) ;
struct V_8 * V_110 = V_98 -> V_103 [ 0 ] ;
struct V_49 * V_50 = (struct V_49 * ) V_81 -> V_43 ;
unsigned int V_223 , V_19 , V_190 ;
V_223 = F_14 ( V_110 -> V_13 , V_50 -> V_18 ) ;
V_19 = ( V_223 >> V_50 -> V_53 ) & V_50 -> V_20 ;
for ( V_190 = 0 ; V_190 < V_50 -> V_45 ; V_190 ++ ) {
if ( V_19 == V_50 -> V_58 [ V_190 ] )
break;
}
V_217 -> V_21 . V_221 . V_51 [ 0 ] = V_190 ;
if ( V_50 -> V_53 != V_50 -> V_222 ) {
V_19 = ( V_223 >> V_50 -> V_222 ) & V_50 -> V_20 ;
for ( V_190 = 0 ; V_190 < V_50 -> V_45 ; V_190 ++ ) {
if ( V_19 == V_50 -> V_58 [ V_190 ] )
break;
}
V_217 -> V_21 . V_221 . V_51 [ 1 ] = V_190 ;
}
return 0 ;
}
int F_120 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_97 * V_98 = F_110 ( V_81 ) ;
struct V_8 * V_110 = V_98 -> V_103 [ 0 ] ;
struct V_196 * V_13 = V_110 -> V_13 ;
struct V_49 * V_50 = (struct V_49 * ) V_81 -> V_43 ;
unsigned int V_19 , V_190 , V_22 ;
unsigned int V_20 ;
struct V_156 V_157 ;
int V_219 ;
if ( V_217 -> V_21 . V_221 . V_51 [ 0 ] > V_50 -> V_45 - 1 )
return - V_107 ;
V_190 = V_217 -> V_21 . V_221 . V_51 [ 0 ] ;
V_19 = V_50 -> V_58 [ V_217 -> V_21 . V_221 . V_51 [ 0 ] ] << V_50 -> V_53 ;
V_20 = V_50 -> V_20 << V_50 -> V_53 ;
if ( V_50 -> V_53 != V_50 -> V_222 ) {
if ( V_217 -> V_21 . V_221 . V_51 [ 1 ] > V_50 -> V_45 - 1 )
return - V_107 ;
V_19 |= V_50 -> V_58 [ V_217 -> V_21 . V_221 . V_51 [ 1 ] ] << V_50 -> V_222 ;
V_20 |= V_50 -> V_20 << V_50 -> V_222 ;
}
F_112 ( & V_13 -> V_220 ) ;
V_22 = F_113 ( V_110 -> V_13 , V_50 -> V_18 , V_20 , V_19 ) ;
if ( V_22 ) {
for ( V_219 = 0 ; V_219 < V_98 -> V_102 ; V_219 ++ ) {
V_110 = V_98 -> V_103 [ V_219 ] ;
V_110 -> V_21 = V_19 ;
V_157 . V_81 = V_81 ;
V_157 . V_110 = V_110 ;
V_157 . V_18 = V_50 -> V_18 ;
V_157 . V_20 = V_20 ;
V_157 . V_19 = V_19 ;
V_110 -> V_12 -> V_157 = & V_157 ;
F_91 ( V_110 , V_81 , V_22 , V_190 , V_50 ) ;
V_110 -> V_12 -> V_157 = NULL ;
}
}
F_114 ( & V_13 -> V_220 ) ;
return V_22 ;
}
int F_121 ( struct V_92 * V_81 ,
struct V_224 * V_225 )
{
V_225 -> type = V_226 ;
V_225 -> V_181 = 1 ;
V_225 -> V_21 . integer . V_227 = 0 ;
V_225 -> V_21 . integer . V_45 = 1 ;
return 0 ;
}
int F_122 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_196 * V_13 = F_110 ( V_81 ) ;
const char * V_201 = ( const char * ) V_81 -> V_43 ;
F_112 ( & V_13 -> V_220 ) ;
V_217 -> V_21 . integer . V_21 [ 0 ] =
F_123 ( & V_13 -> V_12 , V_201 ) ;
F_114 ( & V_13 -> V_220 ) ;
return 0 ;
}
int F_124 ( struct V_92 * V_81 ,
struct V_216 * V_217 )
{
struct V_196 * V_13 = F_110 ( V_81 ) ;
const char * V_201 = ( const char * ) V_81 -> V_43 ;
F_112 ( & V_13 -> V_220 ) ;
if ( V_217 -> V_21 . integer . V_21 [ 0 ] )
F_125 ( & V_13 -> V_12 , V_201 ) ;
else
F_126 ( & V_13 -> V_12 , V_201 ) ;
F_103 ( & V_13 -> V_12 ) ;
F_114 ( & V_13 -> V_220 ) ;
return 0 ;
}
int F_127 ( struct V_11 * V_12 ,
const struct V_8 * V_110 )
{
struct V_8 * V_17 ;
T_3 V_94 ;
if ( ( V_17 = F_8 ( V_110 ) ) == NULL )
return - V_101 ;
V_94 = strlen ( V_110 -> V_54 ) + 1 ;
if ( V_12 -> V_13 && V_12 -> V_13 -> V_100 )
V_94 += 1 + strlen ( V_12 -> V_13 -> V_100 ) ;
V_17 -> V_54 = F_5 ( V_94 , V_7 ) ;
if ( V_17 -> V_54 == NULL ) {
F_7 ( V_17 ) ;
return - V_101 ;
}
if ( V_12 -> V_13 && V_12 -> V_13 -> V_100 )
snprintf ( V_17 -> V_54 , V_94 , L_5 ,
V_12 -> V_13 -> V_100 , V_110 -> V_54 ) ;
else
snprintf ( V_17 -> V_54 , V_94 , L_1 , V_110 -> V_54 ) ;
V_12 -> V_172 ++ ;
V_17 -> V_12 = V_12 ;
V_17 -> V_13 = V_12 -> V_13 ;
V_17 -> V_15 = V_12 -> V_15 ;
F_65 ( & V_17 -> V_85 ) ;
F_65 ( & V_17 -> V_87 ) ;
F_65 ( & V_17 -> V_82 ) ;
F_27 ( & V_17 -> V_82 , & V_12 -> V_14 -> V_103 ) ;
V_17 -> V_116 = 1 ;
return 0 ;
}
int F_128 ( struct V_11 * V_12 ,
const struct V_8 * V_110 ,
int V_215 )
{
int V_35 , V_25 ;
for ( V_35 = 0 ; V_35 < V_215 ; V_35 ++ ) {
V_25 = F_127 ( V_12 , V_110 ) ;
if ( V_25 < 0 ) {
F_16 ( V_12 -> V_3 ,
L_63 ,
V_110 -> V_54 , V_25 ) ;
return V_25 ;
}
V_110 ++ ;
}
return 0 ;
}
static void F_129 ( struct V_11 * V_12 ,
const char * V_228 , int V_121 )
{
struct V_8 * V_17 ;
F_30 (w, &dapm->card->widgets, list)
{
if ( ! V_17 -> V_183 || V_17 -> V_12 != V_12 )
continue;
F_41 ( V_17 -> V_12 -> V_3 , L_64 ,
V_17 -> V_54 , V_17 -> V_183 , V_228 , V_121 ) ;
if ( strstr ( V_17 -> V_183 , V_228 ) ) {
switch( V_121 ) {
case V_154 :
V_17 -> V_115 = 1 ;
break;
case V_155 :
V_17 -> V_115 = 0 ;
break;
case V_175 :
case V_174 :
case V_229 :
case V_230 :
break;
}
}
}
F_72 ( V_12 , V_121 ) ;
}
int F_130 ( struct V_194 * V_195 ,
const char * V_228 , int V_121 )
{
struct V_196 * V_13 = V_195 -> V_13 ;
if ( V_228 == NULL )
return 0 ;
F_112 ( & V_13 -> V_220 ) ;
F_129 ( & V_13 -> V_12 , V_228 , V_121 ) ;
F_114 ( & V_13 -> V_220 ) ;
return 0 ;
}
int F_125 ( struct V_11 * V_12 , const char * V_201 )
{
return F_102 ( V_12 , V_201 , 1 ) ;
}
int F_131 ( struct V_11 * V_12 ,
const char * V_201 )
{
struct V_8 * V_17 = F_101 ( V_12 , V_201 , true ) ;
if ( ! V_17 ) {
F_16 ( V_12 -> V_3 , L_55 , V_201 ) ;
return - V_107 ;
}
F_41 ( V_17 -> V_12 -> V_3 , L_65 , V_201 ) ;
V_17 -> V_116 = 1 ;
V_17 -> V_126 = 1 ;
return 0 ;
}
int F_126 ( struct V_11 * V_12 ,
const char * V_201 )
{
return F_102 ( V_12 , V_201 , 0 ) ;
}
int F_132 ( struct V_11 * V_12 , const char * V_201 )
{
return F_102 ( V_12 , V_201 , 0 ) ;
}
int F_123 ( struct V_11 * V_12 ,
const char * V_201 )
{
struct V_8 * V_17 = F_101 ( V_12 , V_201 , true ) ;
if ( V_17 )
return V_17 -> V_116 ;
return 0 ;
}
int F_133 ( struct V_11 * V_12 ,
const char * V_201 )
{
struct V_8 * V_17 = F_101 ( V_12 , V_201 , false ) ;
if ( ! V_17 ) {
F_16 ( V_12 -> V_3 , L_55 , V_201 ) ;
return - V_107 ;
}
V_17 -> V_113 = 1 ;
return 0 ;
}
void F_134 ( struct V_11 * V_12 )
{
F_97 ( V_12 -> V_3 ) ;
F_89 ( V_12 ) ;
F_99 ( V_12 ) ;
F_100 ( & V_12 -> V_82 ) ;
}
static void F_135 ( struct V_11 * V_12 )
{
struct V_8 * V_17 ;
F_62 ( V_169 ) ;
int V_231 = 0 ;
F_30 (w, &dapm->card->widgets, list) {
if ( V_17 -> V_12 != V_12 )
continue;
if ( V_17 -> V_125 ) {
F_52 ( V_17 , & V_169 , false ) ;
V_17 -> V_125 = 0 ;
V_231 = 1 ;
}
}
if ( V_231 ) {
F_21 ( V_12 , V_166 ) ;
F_61 ( V_12 , & V_169 , 0 , false ) ;
F_21 ( V_12 , V_165 ) ;
}
}
void F_136 ( struct V_16 * V_14 )
{
struct V_196 * V_13 ;
F_30 (codec, &card->codec_dev_list, list) {
F_135 ( & V_13 -> V_12 ) ;
F_21 ( & V_13 -> V_12 , V_163 ) ;
}
}
