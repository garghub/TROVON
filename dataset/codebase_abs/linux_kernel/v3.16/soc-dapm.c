static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 && V_2 -> V_3 -> V_4 )
F_2 ( & V_2 -> V_3 -> V_5 ) ;
}
static void F_3 ( T_1 V_6 )
{
if ( V_6 )
F_4 ( F_5 ( V_6 ) ) ;
}
static void F_6 ( struct V_7 * V_8 , T_1 V_6 , const char * V_9 , ... )
{
T_2 args ;
char * V_10 ;
if ( ! V_6 )
return;
V_10 = F_7 ( V_11 , V_12 ) ;
if ( V_10 == NULL )
return;
va_start ( args , V_9 ) ;
vsnprintf ( V_10 , V_11 , V_9 , args ) ;
F_8 ( V_8 , L_1 , V_10 ) ;
va_end ( args ) ;
F_9 ( V_10 ) ;
}
static bool F_10 ( struct V_13 * V_14 )
{
return ! F_11 ( & V_14 -> V_15 ) ;
}
static void F_12 ( struct V_13 * V_14 , const char * V_16 )
{
F_1 ( V_14 -> V_2 ) ;
if ( ! F_10 ( V_14 ) ) {
F_13 ( V_14 -> V_2 -> V_8 , L_2 ,
V_14 -> V_17 , V_16 ) ;
F_14 ( & V_14 -> V_15 , & V_14 -> V_2 -> V_3 -> V_18 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
struct V_13 * V_14 ;
F_16 ( & V_3 -> V_5 ) ;
F_17 (w, &card->widgets, list) {
switch ( V_14 -> V_20 ) {
case V_21 :
case V_22 :
F_12 ( V_14 , L_3 ) ;
break;
default:
break;
}
}
F_18 ( & V_3 -> V_5 ) ;
}
static inline struct V_13 * F_19 (
const struct V_13 * V_23 )
{
return F_20 ( V_23 , sizeof( * V_23 ) , V_12 ) ;
}
static int F_21 ( struct V_13 * V_24 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
V_28 = F_22 ( sizeof( * V_28 ) , V_12 ) ;
if ( ! V_28 ) {
F_23 ( V_24 -> V_2 -> V_8 ,
L_4 ,
V_24 -> V_17 ) ;
return - V_31 ;
}
F_24 ( & V_28 -> V_32 ) ;
switch ( V_24 -> V_20 ) {
case V_33 :
case V_34 :
case V_35 :
V_30 = (struct V_29 * ) V_26 -> V_36 ;
if ( V_30 -> V_37 ) {
struct V_13 V_38 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_39 = V_30 -> V_39 ;
V_38 . V_40 = ( 1 << F_25 ( V_30 -> V_41 ) ) - 1 ;
V_38 . V_42 = V_30 -> V_42 ;
if ( V_30 -> V_43 )
V_38 . V_44 = V_30 -> V_41 ;
else
V_38 . V_44 = 0 ;
V_38 . V_45 = V_38 . V_44 ;
V_38 . V_20 = V_46 ;
V_38 . V_17 = V_26 -> V_20 . V_17 ;
V_28 -> V_47 = V_38 . V_45 ;
V_28 -> V_24 = F_26 ( V_24 -> V_2 ,
& V_38 ) ;
if ( ! V_28 -> V_24 ) {
F_9 ( V_28 ) ;
return - V_31 ;
}
}
break;
default:
break;
}
V_26 -> V_48 = V_28 ;
return 0 ;
}
static void F_27 ( struct V_25 * V_49 )
{
struct V_27 * V_28 = F_28 ( V_49 ) ;
F_9 ( V_28 -> V_50 ) ;
F_9 ( V_28 ) ;
}
static struct V_51 * F_29 (
const struct V_25 * V_26 )
{
struct V_27 * V_28 = F_28 ( V_26 ) ;
return V_28 -> V_50 ;
}
static int F_30 ( struct V_25 * V_26 ,
struct V_13 * V_24 )
{
struct V_27 * V_28 = F_28 ( V_26 ) ;
struct V_51 * V_52 ;
unsigned int V_53 ;
if ( V_28 -> V_50 )
V_53 = V_28 -> V_50 -> V_54 + 1 ;
else
V_53 = 1 ;
V_52 = F_31 ( V_28 -> V_50 ,
sizeof( * V_52 ) + sizeof( V_24 ) * V_53 , V_12 ) ;
if ( ! V_52 )
return - V_31 ;
V_52 -> V_55 [ V_53 - 1 ] = V_24 ;
V_52 -> V_54 = V_53 ;
V_28 -> V_50 = V_52 ;
return 0 ;
}
static void F_32 ( const struct V_25 * V_26 ,
struct V_56 * V_57 )
{
struct V_27 * V_28 = F_28 ( V_26 ) ;
F_14 ( & V_57 -> V_58 , & V_28 -> V_32 ) ;
if ( V_28 -> V_24 ) {
F_33 ( V_28 -> V_24 -> V_2 , V_28 -> V_24 ,
V_57 -> V_59 , NULL , NULL ) ;
}
}
static bool F_34 ( const struct V_25 * V_26 )
{
struct V_27 * V_28 = F_28 ( V_26 ) ;
if ( ! V_28 -> V_24 )
return true ;
return V_28 -> V_24 -> V_60 ;
}
static struct V_61 * F_35 (
const struct V_25 * V_26 )
{
struct V_27 * V_28 = F_28 ( V_26 ) ;
return & V_28 -> V_32 ;
}
static unsigned int F_36 ( const struct V_25 * V_26 )
{
struct V_27 * V_28 = F_28 ( V_26 ) ;
return V_28 -> V_47 ;
}
static bool F_37 ( const struct V_25 * V_26 ,
unsigned int V_47 )
{
struct V_27 * V_28 = F_28 ( V_26 ) ;
if ( V_28 -> V_47 == V_47 )
return false ;
if ( V_28 -> V_24 )
V_28 -> V_24 -> V_45 = V_47 ;
V_28 -> V_47 = V_47 ;
return true ;
}
struct V_62 * F_38 ( struct V_25 * V_26 )
{
return F_29 ( V_26 ) -> V_55 [ 0 ] -> V_63 ;
}
static void F_39 ( struct V_19 * V_3 )
{
struct V_13 * V_14 ;
F_2 ( & V_3 -> V_5 ) ;
memset ( & V_3 -> V_64 , 0 , sizeof( V_3 -> V_64 ) ) ;
F_17 (w, &card->widgets, list) {
V_14 -> V_65 = V_14 -> V_60 ;
V_14 -> V_66 = false ;
V_14 -> V_67 = - 1 ;
V_14 -> V_68 = - 1 ;
}
}
static int F_40 ( struct V_13 * V_14 , int V_39 ,
unsigned int * V_47 )
{
if ( ! V_14 -> V_2 -> V_69 )
return - V_70 ;
return F_41 ( V_14 -> V_2 -> V_69 , V_39 , V_47 ) ;
}
static int F_42 ( struct V_13 * V_14 ,
int V_39 , unsigned int V_40 , unsigned int V_47 )
{
if ( ! V_14 -> V_2 -> V_69 )
return - V_70 ;
return F_43 ( V_14 -> V_2 -> V_69 , V_39 ,
V_40 , V_47 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_69 )
F_45 ( V_2 -> V_69 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
enum V_71 V_72 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
int V_73 = 0 ;
F_47 ( V_3 , V_72 ) ;
if ( V_3 && V_3 -> V_74 )
V_73 = V_3 -> V_74 ( V_3 , V_2 , V_72 ) ;
if ( V_73 != 0 )
goto V_75;
if ( V_2 -> V_63 ) {
if ( V_2 -> V_63 -> V_76 -> V_74 )
V_73 = V_2 -> V_63 -> V_76 -> V_74 ( V_2 -> V_63 ,
V_72 ) ;
else
V_2 -> V_77 = V_72 ;
} else if ( ! V_3 || V_2 != & V_3 -> V_2 ) {
V_2 -> V_77 = V_72 ;
}
if ( V_73 != 0 )
goto V_75;
if ( V_3 && V_3 -> V_78 )
V_73 = V_3 -> V_78 ( V_3 , V_2 , V_72 ) ;
V_75:
F_48 ( V_3 , V_72 ) ;
return V_73 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_13 * V_79 , struct V_13 * V_80 ,
struct V_56 * V_57 , const char * V_81 ,
const struct V_82 * V_26 )
{
struct V_83 * V_84 = (struct V_83 * ) V_26 -> V_36 ;
unsigned int V_85 , V_86 ;
int V_87 ;
if ( V_84 -> V_39 != V_88 ) {
F_40 ( V_80 , V_84 -> V_39 , & V_85 ) ;
V_85 = ( V_85 >> V_84 -> V_89 ) & V_84 -> V_40 ;
V_86 = F_50 ( V_84 , V_85 ) ;
} else {
V_86 = 0 ;
}
for ( V_87 = 0 ; V_87 < V_84 -> V_90 ; V_87 ++ ) {
if ( ! ( strcmp ( V_81 , V_84 -> V_91 [ V_87 ] ) ) ) {
F_51 ( & V_57 -> V_92 , & V_2 -> V_3 -> V_32 ) ;
F_51 ( & V_57 -> V_93 , & V_80 -> V_94 ) ;
F_51 ( & V_57 -> V_95 , & V_79 -> V_96 ) ;
V_57 -> V_17 = ( char * ) V_84 -> V_91 [ V_87 ] ;
if ( V_87 == V_86 )
V_57 -> V_97 = 1 ;
else
V_57 -> V_97 = 0 ;
return 0 ;
}
}
return - V_98 ;
}
static void F_52 ( struct V_13 * V_14 ,
struct V_56 * V_99 , int V_87 )
{
struct V_29 * V_30 = (struct V_29 * )
V_14 -> V_100 [ V_87 ] . V_36 ;
unsigned int V_39 = V_30 -> V_39 ;
unsigned int V_42 = V_30 -> V_42 ;
unsigned int V_41 = V_30 -> V_41 ;
unsigned int V_40 = ( 1 << F_25 ( V_41 ) ) - 1 ;
unsigned int V_43 = V_30 -> V_43 ;
unsigned int V_85 ;
if ( V_39 != V_88 ) {
F_40 ( V_14 , V_39 , & V_85 ) ;
V_85 = ( V_85 >> V_42 ) & V_40 ;
if ( V_43 )
V_85 = V_41 - V_85 ;
V_99 -> V_97 = ! ! V_85 ;
} else {
V_99 -> V_97 = 0 ;
}
}
static int F_53 ( struct V_1 * V_2 ,
struct V_13 * V_79 , struct V_13 * V_80 ,
struct V_56 * V_57 , const char * V_81 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_80 -> V_101 ; V_87 ++ ) {
if ( ! strcmp ( V_81 , V_80 -> V_100 [ V_87 ] . V_17 ) ) {
F_51 ( & V_57 -> V_92 , & V_2 -> V_3 -> V_32 ) ;
F_51 ( & V_57 -> V_93 , & V_80 -> V_94 ) ;
F_51 ( & V_57 -> V_95 , & V_79 -> V_96 ) ;
V_57 -> V_17 = V_80 -> V_100 [ V_87 ] . V_17 ;
F_52 ( V_80 , V_57 , V_87 ) ;
return 0 ;
}
}
return - V_98 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_13 * V_102 ,
const struct V_82 * V_103 ,
struct V_25 * * V_26 )
{
struct V_13 * V_14 ;
int V_87 ;
* V_26 = NULL ;
F_17 (w, &dapm->card->widgets, list) {
if ( V_14 == V_102 || V_14 -> V_2 != V_102 -> V_2 )
continue;
for ( V_87 = 0 ; V_87 < V_14 -> V_101 ; V_87 ++ ) {
if ( & V_14 -> V_100 [ V_87 ] == V_103 ) {
if ( V_14 -> V_104 )
* V_26 = V_14 -> V_104 [ V_87 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_55 ( struct V_13 * V_14 ,
int V_105 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_106 * V_3 = V_2 -> V_3 -> V_106 ;
const char * V_107 ;
T_3 V_108 ;
int V_109 ;
struct V_25 * V_26 ;
bool V_110 , V_111 ;
char * V_112 ;
const char * V_17 ;
int V_73 ;
if ( V_2 -> V_63 )
V_107 = V_2 -> V_63 -> V_113 ;
else
V_107 = NULL ;
if ( V_107 )
V_108 = strlen ( V_107 ) + 1 ;
else
V_108 = 0 ;
V_109 = F_54 ( V_2 , V_14 , & V_14 -> V_100 [ V_105 ] ,
& V_26 ) ;
if ( ! V_26 ) {
if ( V_109 ) {
V_110 = false ;
V_111 = true ;
} else {
switch ( V_14 -> V_20 ) {
case V_33 :
case V_34 :
V_110 = true ;
V_111 = true ;
break;
case V_35 :
V_110 = false ;
V_111 = true ;
break;
case V_114 :
V_110 = true ;
V_111 = false ;
break;
default:
return - V_115 ;
}
}
if ( V_110 && V_111 ) {
V_112 = F_56 ( V_12 , L_5 ,
V_14 -> V_17 + V_108 ,
V_14 -> V_100 [ V_105 ] . V_17 ) ;
if ( V_112 == NULL )
return - V_31 ;
V_17 = V_112 ;
} else if ( V_110 ) {
V_112 = NULL ;
V_17 = V_14 -> V_17 + V_108 ;
} else {
V_112 = NULL ;
V_17 = V_14 -> V_100 [ V_105 ] . V_17 ;
}
V_26 = F_57 ( & V_14 -> V_100 [ V_105 ] , NULL , V_17 ,
V_107 ) ;
F_9 ( V_112 ) ;
if ( ! V_26 )
return - V_31 ;
V_26 -> V_116 = F_27 ;
V_73 = F_21 ( V_14 , V_26 ) ;
if ( V_73 ) {
F_58 ( V_26 ) ;
return V_73 ;
}
V_73 = F_59 ( V_3 , V_26 ) ;
if ( V_73 < 0 ) {
F_23 ( V_2 -> V_8 ,
L_6 ,
V_14 -> V_17 , V_17 , V_73 ) ;
return V_73 ;
}
}
V_73 = F_30 ( V_26 , V_14 ) ;
if ( V_73 )
return V_73 ;
V_14 -> V_104 [ V_105 ] = V_26 ;
return 0 ;
}
static int F_60 ( struct V_13 * V_14 )
{
int V_87 , V_73 ;
struct V_56 * V_57 ;
for ( V_87 = 0 ; V_87 < V_14 -> V_101 ; V_87 ++ ) {
F_17 (path, &w->sources, list_sink) {
if ( V_57 -> V_17 != ( char * ) V_14 -> V_100 [ V_87 ] . V_17 )
continue;
if ( V_14 -> V_104 [ V_87 ] ) {
F_32 ( V_14 -> V_104 [ V_87 ] , V_57 ) ;
continue;
}
V_73 = F_55 ( V_14 , V_87 ) ;
if ( V_73 < 0 )
return V_73 ;
F_32 ( V_14 -> V_104 [ V_87 ] , V_57 ) ;
}
}
return 0 ;
}
static int F_61 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_56 * V_57 ;
int V_73 ;
if ( V_14 -> V_101 != 1 ) {
F_23 ( V_2 -> V_8 ,
L_7 ,
V_14 -> V_17 ) ;
return - V_115 ;
}
if ( F_11 ( & V_14 -> V_94 ) ) {
F_23 ( V_2 -> V_8 , L_8 , V_14 -> V_17 ) ;
return - V_115 ;
}
V_73 = F_55 ( V_14 , 0 ) ;
if ( V_73 < 0 )
return V_73 ;
F_17 (path, &w->sources, list_sink)
F_32 ( V_14 -> V_104 [ 0 ] , V_57 ) ;
return 0 ;
}
static int F_62 ( struct V_13 * V_14 )
{
if ( V_14 -> V_101 )
F_23 ( V_14 -> V_2 -> V_8 ,
L_9 , V_14 -> V_17 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_61 * V_117 )
{
struct V_56 * V_99 ;
F_17 (p, sink, list_source) {
if ( V_99 -> V_118 ) {
V_99 -> V_118 = 0 ;
F_63 ( V_2 , & V_99 -> V_117 -> V_96 ) ;
}
}
}
static void F_64 ( struct V_1 * V_2 ,
struct V_61 * V_59 )
{
struct V_56 * V_99 ;
F_17 (p, source, list_sink) {
if ( V_99 -> V_118 ) {
V_99 -> V_118 = 0 ;
F_64 ( V_2 , & V_99 -> V_59 -> V_94 ) ;
}
}
}
static int F_65 ( struct V_13 * V_24 )
{
int V_72 = F_66 ( V_24 -> V_2 -> V_3 -> V_106 ) ;
switch ( V_72 ) {
case V_119 :
case V_120 :
if ( V_24 -> V_121 )
F_67 ( V_24 -> V_2 -> V_8 , L_10 ,
V_24 -> V_17 ) ;
return V_24 -> V_121 ;
default:
return 1 ;
}
}
static int F_68 ( struct V_51 * * V_92 ,
struct V_13 * V_14 )
{
struct V_51 * V_50 ;
int V_122 , V_123 , V_87 ;
if ( * V_92 == NULL )
return - V_115 ;
V_50 = * V_92 ;
for ( V_87 = 0 ; V_87 < V_50 -> V_54 ; V_87 ++ ) {
if ( V_50 -> V_55 [ V_87 ] == V_14 )
return 0 ;
}
V_123 = V_50 -> V_54 + 1 ;
V_122 = sizeof( struct V_51 ) +
V_123 * sizeof( struct V_13 * ) ;
* V_92 = F_31 ( V_50 , V_122 , V_12 ) ;
if ( * V_92 == NULL ) {
F_23 ( V_14 -> V_2 -> V_8 , L_11 ,
V_14 -> V_17 ) ;
return - V_31 ;
}
V_50 = * V_92 ;
F_67 ( V_14 -> V_2 -> V_8 , L_12 ,
V_14 -> V_17 , V_50 -> V_54 ) ;
V_50 -> V_55 [ V_50 -> V_54 ] = V_14 ;
V_50 -> V_54 ++ ;
return 1 ;
}
static int F_69 ( struct V_13 * V_24 ,
struct V_51 * * V_92 )
{
struct V_56 * V_57 ;
int V_124 = 0 ;
if ( V_24 -> V_68 >= 0 )
return V_24 -> V_68 ;
F_70 ( V_24 , V_125 ) ;
switch ( V_24 -> V_20 ) {
case V_126 :
case V_127 :
case V_128 :
case V_46 :
return 0 ;
default:
break;
}
switch ( V_24 -> V_20 ) {
case V_129 :
case V_130 :
case V_131 :
if ( V_24 -> V_132 ) {
V_24 -> V_68 = F_65 ( V_24 ) ;
return V_24 -> V_68 ;
}
default:
break;
}
if ( V_24 -> V_133 ) {
if ( V_24 -> V_20 == V_22 && ! V_24 -> V_134 ) {
V_24 -> V_68 = F_65 ( V_24 ) ;
return V_24 -> V_68 ;
}
if ( V_24 -> V_20 == V_135 ||
V_24 -> V_20 == V_136 ||
( V_24 -> V_20 == V_137 &&
! F_11 ( & V_24 -> V_94 ) ) ) {
V_24 -> V_68 = F_65 ( V_24 ) ;
return V_24 -> V_68 ;
}
}
F_17 (path, &widget->sinks, list_source) {
F_70 ( V_24 , V_138 ) ;
if ( V_57 -> V_139 )
continue;
if ( V_57 -> V_140 )
return 1 ;
if ( V_57 -> V_118 )
continue;
F_71 ( V_24 , V_57 ) ;
if ( V_57 -> V_117 && V_57 -> V_97 ) {
V_57 -> V_118 = 1 ;
V_57 -> V_140 = 1 ;
if ( V_92 ) {
int V_141 ;
V_141 = F_68 ( V_92 , V_57 -> V_117 ) ;
if ( V_141 < 0 ) {
F_23 ( V_24 -> V_2 -> V_8 ,
L_13 ,
V_24 -> V_17 ) ;
V_57 -> V_140 = 0 ;
return V_124 ;
}
}
V_124 += F_69 ( V_57 -> V_117 , V_92 ) ;
V_57 -> V_140 = 0 ;
}
}
V_24 -> V_68 = V_124 ;
return V_124 ;
}
static int F_72 ( struct V_13 * V_24 ,
struct V_51 * * V_92 )
{
struct V_56 * V_57 ;
int V_124 = 0 ;
if ( V_24 -> V_67 >= 0 )
return V_24 -> V_67 ;
F_70 ( V_24 , V_125 ) ;
switch ( V_24 -> V_20 ) {
case V_126 :
case V_127 :
case V_128 :
case V_46 :
return 0 ;
default:
break;
}
switch ( V_24 -> V_20 ) {
case V_142 :
case V_143 :
case V_144 :
if ( V_24 -> V_132 ) {
V_24 -> V_67 = F_65 ( V_24 ) ;
return V_24 -> V_67 ;
}
default:
break;
}
if ( V_24 -> V_133 ) {
if ( V_24 -> V_20 == V_21 && ! V_24 -> V_134 ) {
V_24 -> V_67 = F_65 ( V_24 ) ;
return V_24 -> V_67 ;
}
if ( V_24 -> V_20 == V_145 ) {
V_24 -> V_67 = F_65 ( V_24 ) ;
return V_24 -> V_67 ;
}
if ( V_24 -> V_20 == V_146 ||
( V_24 -> V_20 == V_137 &&
! F_11 ( & V_24 -> V_96 ) ) ) {
V_24 -> V_67 = F_65 ( V_24 ) ;
return V_24 -> V_67 ;
}
if ( V_24 -> V_20 == V_147 ) {
V_24 -> V_67 = F_65 ( V_24 ) ;
return V_24 -> V_67 ;
}
}
F_17 (path, &widget->sources, list_sink) {
F_70 ( V_24 , V_138 ) ;
if ( V_57 -> V_139 )
continue;
if ( V_57 -> V_140 )
return 1 ;
if ( V_57 -> V_118 )
continue;
F_73 ( V_24 , V_57 ) ;
if ( V_57 -> V_59 && V_57 -> V_97 ) {
V_57 -> V_118 = 1 ;
V_57 -> V_140 = 1 ;
if ( V_92 ) {
int V_141 ;
V_141 = F_68 ( V_92 , V_57 -> V_59 ) ;
if ( V_141 < 0 ) {
F_23 ( V_24 -> V_2 -> V_8 ,
L_13 ,
V_24 -> V_17 ) ;
V_57 -> V_140 = 0 ;
return V_124 ;
}
}
V_124 += F_72 ( V_57 -> V_59 , V_92 ) ;
V_57 -> V_140 = 0 ;
}
}
V_24 -> V_67 = V_124 ;
return V_124 ;
}
int F_74 ( struct V_148 * V_149 , int V_150 ,
struct V_51 * * V_92 )
{
struct V_19 * V_3 = V_149 -> V_3 ;
int V_32 ;
F_75 ( & V_3 -> V_5 , V_151 ) ;
F_39 ( V_3 ) ;
if ( V_150 == V_152 ) {
V_32 = F_69 ( V_149 -> V_153 , V_92 ) ;
F_63 ( & V_3 -> V_2 ,
& V_149 -> V_153 -> V_96 ) ;
} else {
V_32 = F_72 ( V_149 -> V_154 , V_92 ) ;
F_64 ( & V_3 -> V_2 ,
& V_149 -> V_154 -> V_94 ) ;
}
F_76 ( V_32 , V_150 ) ;
F_18 ( & V_3 -> V_5 ) ;
return V_32 ;
}
int F_77 ( struct V_13 * V_14 ,
struct V_25 * V_26 , int V_155 )
{
int V_73 ;
F_44 ( V_14 -> V_2 ) ;
if ( F_78 ( V_155 ) ) {
if ( V_14 -> V_45 & V_156 ) {
V_73 = F_79 ( V_14 -> V_157 , false ) ;
if ( V_73 != 0 )
F_80 ( V_14 -> V_2 -> V_8 ,
L_14 ,
V_14 -> V_17 , V_73 ) ;
}
return F_81 ( V_14 -> V_157 ) ;
} else {
if ( V_14 -> V_45 & V_156 ) {
V_73 = F_79 ( V_14 -> V_157 , true ) ;
if ( V_73 != 0 )
F_80 ( V_14 -> V_2 -> V_8 ,
L_15 ,
V_14 -> V_17 , V_73 ) ;
}
return F_82 ( V_14 -> V_157 , V_14 -> V_42 ) ;
}
}
int F_83 ( struct V_13 * V_14 ,
struct V_25 * V_26 , int V_155 )
{
if ( ! V_14 -> V_158 )
return - V_70 ;
F_44 ( V_14 -> V_2 ) ;
#ifdef F_84
if ( F_78 ( V_155 ) ) {
return F_85 ( V_14 -> V_158 ) ;
} else {
F_86 ( V_14 -> V_158 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_87 ( struct V_13 * V_14 )
{
if ( V_14 -> V_66 )
return V_14 -> V_65 ;
if ( V_14 -> V_159 )
V_14 -> V_65 = 1 ;
else
V_14 -> V_65 = V_14 -> V_160 ( V_14 ) ;
V_14 -> V_66 = true ;
return V_14 -> V_65 ;
}
static int F_88 ( struct V_13 * V_14 )
{
int V_161 , V_75 ;
F_70 ( V_14 , V_162 ) ;
V_161 = F_72 ( V_14 , NULL ) ;
F_64 ( V_14 -> V_2 , & V_14 -> V_94 ) ;
V_75 = F_69 ( V_14 , NULL ) ;
F_63 ( V_14 -> V_2 , & V_14 -> V_96 ) ;
return V_75 != 0 && V_161 != 0 ;
}
static int F_89 ( struct V_13 * V_14 )
{
int V_161 ;
F_70 ( V_14 , V_162 ) ;
if ( V_14 -> V_132 ) {
V_161 = F_72 ( V_14 , NULL ) ;
F_64 ( V_14 -> V_2 , & V_14 -> V_94 ) ;
return V_161 != 0 ;
} else {
return F_88 ( V_14 ) ;
}
}
static int F_90 ( struct V_13 * V_14 )
{
int V_75 ;
F_70 ( V_14 , V_162 ) ;
if ( V_14 -> V_132 ) {
V_75 = F_69 ( V_14 , NULL ) ;
F_63 ( V_14 -> V_2 , & V_14 -> V_96 ) ;
return V_75 != 0 ;
} else {
return F_88 ( V_14 ) ;
}
}
static int F_91 ( struct V_13 * V_14 )
{
struct V_56 * V_57 ;
F_70 ( V_14 , V_162 ) ;
F_17 (path, &w->sinks, list_source) {
F_70 ( V_14 , V_138 ) ;
if ( V_57 -> V_139 )
continue;
if ( V_57 -> V_133 &&
! V_57 -> V_133 ( V_57 -> V_59 , V_57 -> V_117 ) )
continue;
if ( ! V_57 -> V_117 )
continue;
if ( F_87 ( V_57 -> V_117 ) )
return 1 ;
}
return 0 ;
}
static int F_92 ( struct V_13 * V_14 )
{
return 1 ;
}
static int F_93 ( struct V_13 * V_163 ,
struct V_13 * V_164 ,
bool V_165 )
{
int * V_166 ;
if ( V_165 )
V_166 = V_167 ;
else
V_166 = V_168 ;
if ( V_166 [ V_163 -> V_20 ] != V_166 [ V_164 -> V_20 ] )
return V_166 [ V_163 -> V_20 ] - V_166 [ V_164 -> V_20 ] ;
if ( V_163 -> V_169 != V_164 -> V_169 ) {
if ( V_165 )
return V_163 -> V_169 - V_164 -> V_169 ;
else
return V_164 -> V_169 - V_163 -> V_169 ;
}
if ( V_163 -> V_39 != V_164 -> V_39 )
return V_163 -> V_39 - V_164 -> V_39 ;
if ( V_163 -> V_2 != V_164 -> V_2 )
return ( unsigned long ) V_163 -> V_2 - ( unsigned long ) V_164 -> V_2 ;
return 0 ;
}
static void F_94 ( struct V_13 * V_170 ,
struct V_61 * V_92 ,
bool V_165 )
{
struct V_13 * V_14 ;
F_17 (w, list, power_list)
if ( F_93 ( V_170 , V_14 , V_165 ) < 0 ) {
F_14 ( & V_170 -> V_171 , & V_14 -> V_171 ) ;
return;
}
F_14 ( & V_170 -> V_171 , V_92 ) ;
}
static void F_95 ( struct V_19 * V_3 ,
struct V_13 * V_14 , int V_155 )
{
const char * V_172 ;
int V_60 , V_73 ;
switch ( V_155 ) {
case V_173 :
V_172 = L_16 ;
V_60 = 1 ;
break;
case V_174 :
V_172 = L_17 ;
V_60 = 1 ;
break;
case V_175 :
V_172 = L_18 ;
V_60 = 0 ;
break;
case V_176 :
V_172 = L_19 ;
V_60 = 0 ;
break;
case V_177 :
V_172 = L_20 ;
V_60 = 1 ;
break;
case V_178 :
V_172 = L_21 ;
V_60 = 0 ;
break;
default:
F_96 ( 1 , L_22 , V_155 ) ;
return;
}
if ( V_14 -> V_65 != V_60 )
return;
if ( V_14 -> V_155 && ( V_14 -> V_179 & V_155 ) ) {
F_6 ( V_14 -> V_2 -> V_8 , V_3 -> V_6 , L_23 ,
V_14 -> V_17 , V_172 ) ;
F_44 ( V_14 -> V_2 ) ;
F_97 ( V_14 , V_155 ) ;
V_73 = V_14 -> V_155 ( V_14 , NULL , V_155 ) ;
F_98 ( V_14 , V_155 ) ;
if ( V_73 < 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_24 ,
V_172 , V_14 -> V_17 , V_73 ) ;
}
}
static void F_99 ( struct V_19 * V_3 ,
struct V_61 * V_180 )
{
struct V_13 * V_14 ;
int V_39 ;
unsigned int V_47 = 0 ;
unsigned int V_40 = 0 ;
V_39 = F_100 ( V_180 , struct V_13 ,
V_171 ) -> V_39 ;
F_17 (w, pending, power_list) {
F_101 ( V_39 != V_14 -> V_39 ) ;
V_14 -> V_60 = V_14 -> V_65 ;
V_40 |= V_14 -> V_40 << V_14 -> V_42 ;
if ( V_14 -> V_60 )
V_47 |= V_14 -> V_45 << V_14 -> V_42 ;
else
V_47 |= V_14 -> V_44 << V_14 -> V_42 ;
F_6 ( V_14 -> V_2 -> V_8 , V_3 -> V_6 ,
L_25 ,
V_14 -> V_17 , V_39 , V_47 , V_40 ) ;
F_95 ( V_3 , V_14 , V_173 ) ;
F_95 ( V_3 , V_14 , V_175 ) ;
}
if ( V_39 >= 0 ) {
V_14 = F_100 ( V_180 , struct V_13 ,
V_171 ) ;
F_6 ( V_14 -> V_2 -> V_8 , V_3 -> V_6 ,
L_26 ,
V_47 , V_40 , V_39 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_42 ( V_14 , V_39 , V_40 , V_47 ) ;
}
F_17 (w, pending, power_list) {
F_95 ( V_3 , V_14 , V_174 ) ;
F_95 ( V_3 , V_14 , V_176 ) ;
}
}
static void F_102 ( struct V_19 * V_3 ,
struct V_61 * V_92 , int V_155 , bool V_165 )
{
struct V_13 * V_14 , * V_53 ;
struct V_1 * V_181 ;
F_103 ( V_180 ) ;
int V_182 = - 1 ;
int V_183 = - 1 ;
int V_184 = V_88 ;
struct V_1 * V_185 = NULL ;
int V_73 , V_87 ;
int * V_166 ;
if ( V_165 )
V_166 = V_167 ;
else
V_166 = V_168 ;
F_104 (w, n, list, power_list) {
V_73 = 0 ;
if ( V_166 [ V_14 -> V_20 ] != V_182 || V_14 -> V_39 != V_184 ||
V_14 -> V_2 != V_185 || V_14 -> V_169 != V_183 ) {
if ( ! F_11 ( & V_180 ) )
F_99 ( V_3 , & V_180 ) ;
if ( V_185 && V_185 -> V_186 ) {
for ( V_87 = 0 ; V_87 < F_105 ( V_167 ) ; V_87 ++ )
if ( V_166 [ V_87 ] == V_182 )
V_185 -> V_186 ( V_185 ,
V_87 ,
V_183 ) ;
}
if ( V_185 && V_14 -> V_2 != V_185 )
F_44 ( V_185 ) ;
F_24 ( & V_180 ) ;
V_182 = - 1 ;
V_183 = V_187 ;
V_184 = V_88 ;
V_185 = NULL ;
}
switch ( V_14 -> V_20 ) {
case V_188 :
if ( ! V_14 -> V_155 )
F_106 ( V_14 , V_53 , V_92 ,
V_171 ) ;
if ( V_155 == V_189 )
V_73 = V_14 -> V_155 ( V_14 ,
NULL , V_173 ) ;
else if ( V_155 == V_190 )
V_73 = V_14 -> V_155 ( V_14 ,
NULL , V_175 ) ;
break;
case V_191 :
if ( ! V_14 -> V_155 )
F_106 ( V_14 , V_53 , V_92 ,
V_171 ) ;
if ( V_155 == V_189 )
V_73 = V_14 -> V_155 ( V_14 ,
NULL , V_174 ) ;
else if ( V_155 == V_190 )
V_73 = V_14 -> V_155 ( V_14 ,
NULL , V_176 ) ;
break;
default:
V_182 = V_166 [ V_14 -> V_20 ] ;
V_183 = V_14 -> V_169 ;
V_184 = V_14 -> V_39 ;
V_185 = V_14 -> V_2 ;
F_107 ( & V_14 -> V_171 , & V_180 ) ;
break;
}
if ( V_73 < 0 )
F_23 ( V_14 -> V_2 -> V_8 ,
L_27 , V_73 ) ;
}
if ( ! F_11 ( & V_180 ) )
F_99 ( V_3 , & V_180 ) ;
if ( V_185 && V_185 -> V_186 ) {
for ( V_87 = 0 ; V_87 < F_105 ( V_167 ) ; V_87 ++ )
if ( V_166 [ V_87 ] == V_182 )
V_185 -> V_186 ( V_185 ,
V_87 , V_183 ) ;
}
F_17 (d, &card->dapm_list, list) {
F_44 ( V_181 ) ;
}
}
static void F_108 ( struct V_19 * V_3 )
{
struct V_192 * V_193 = V_3 -> V_193 ;
struct V_51 * V_50 ;
struct V_13 * V_14 = NULL ;
unsigned int V_194 ;
int V_73 ;
if ( ! V_193 || ! F_34 ( V_193 -> V_26 ) )
return;
V_50 = F_29 ( V_193 -> V_26 ) ;
for ( V_194 = 0 ; V_194 < V_50 -> V_54 ; V_194 ++ ) {
V_14 = V_50 -> V_55 [ V_194 ] ;
if ( V_14 -> V_155 && ( V_14 -> V_179 & V_195 ) ) {
V_73 = V_14 -> V_155 ( V_14 , V_193 -> V_26 , V_195 ) ;
if ( V_73 != 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_28 ,
V_14 -> V_17 , V_73 ) ;
}
}
if ( ! V_14 )
return;
V_73 = F_42 ( V_14 , V_193 -> V_39 , V_193 -> V_40 , V_193 -> V_85 ) ;
if ( V_73 < 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_29 ,
V_14 -> V_17 , V_73 ) ;
for ( V_194 = 0 ; V_194 < V_50 -> V_54 ; V_194 ++ ) {
V_14 = V_50 -> V_55 [ V_194 ] ;
if ( V_14 -> V_155 && ( V_14 -> V_179 & V_196 ) ) {
V_73 = V_14 -> V_155 ( V_14 , V_193 -> V_26 , V_196 ) ;
if ( V_73 != 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_30 ,
V_14 -> V_17 , V_73 ) ;
}
}
}
static void F_109 ( void * V_28 , T_4 V_197 )
{
struct V_1 * V_181 = V_28 ;
int V_73 ;
if ( V_181 -> V_77 == V_198 &&
V_181 -> V_199 != V_198 ) {
if ( V_181 -> V_8 )
F_110 ( V_181 -> V_8 ) ;
V_73 = F_46 ( V_181 , V_200 ) ;
if ( V_73 != 0 )
F_23 ( V_181 -> V_8 ,
L_31 , V_73 ) ;
}
if ( ( V_181 -> V_199 == V_201 &&
V_181 -> V_77 != V_201 ) ||
( V_181 -> V_199 != V_201 &&
V_181 -> V_77 == V_201 ) ) {
V_73 = F_46 ( V_181 , V_202 ) ;
if ( V_73 != 0 )
F_23 ( V_181 -> V_8 ,
L_32 , V_73 ) ;
}
}
static void F_111 ( void * V_28 , T_4 V_197 )
{
struct V_1 * V_181 = V_28 ;
int V_73 ;
if ( V_181 -> V_77 == V_202 &&
( V_181 -> V_199 == V_200 ||
V_181 -> V_199 == V_198 ) ) {
V_73 = F_46 ( V_181 , V_200 ) ;
if ( V_73 != 0 )
F_23 ( V_181 -> V_8 , L_33 ,
V_73 ) ;
}
if ( V_181 -> V_77 == V_200 &&
V_181 -> V_199 == V_198 ) {
V_73 = F_46 ( V_181 , V_198 ) ;
if ( V_73 != 0 )
F_23 ( V_181 -> V_8 , L_34 ,
V_73 ) ;
if ( V_181 -> V_8 )
F_112 ( V_181 -> V_8 ) ;
}
if ( V_181 -> V_77 == V_202 &&
V_181 -> V_199 == V_201 ) {
V_73 = F_46 ( V_181 , V_201 ) ;
if ( V_73 != 0 )
F_23 ( V_181 -> V_8 , L_35 ,
V_73 ) ;
}
}
static void F_113 ( struct V_13 * V_203 ,
bool V_60 , bool V_97 )
{
if ( ! V_97 )
return;
if ( V_60 != V_203 -> V_60 )
F_12 ( V_203 , L_36 ) ;
}
static void F_114 ( struct V_13 * V_14 , bool V_60 ,
struct V_61 * V_204 ,
struct V_61 * V_205 )
{
struct V_56 * V_57 ;
if ( V_14 -> V_60 == V_60 )
return;
F_115 ( V_14 , V_60 ) ;
F_17 (path, &w->sources, list_sink) {
if ( V_57 -> V_59 ) {
F_113 ( V_57 -> V_59 , V_60 ,
V_57 -> V_97 ) ;
}
}
switch ( V_14 -> V_20 ) {
case V_126 :
case V_127 :
case V_128 :
case V_46 :
break;
default:
F_17 (path, &w->sinks, list_source) {
if ( V_57 -> V_117 ) {
F_113 ( V_57 -> V_117 , V_60 ,
V_57 -> V_97 ) ;
}
}
break;
}
if ( V_60 )
F_94 ( V_14 , V_204 , true ) ;
else
F_94 ( V_14 , V_205 , false ) ;
}
static void F_116 ( struct V_13 * V_14 ,
struct V_61 * V_204 ,
struct V_61 * V_205 )
{
int V_60 ;
switch ( V_14 -> V_20 ) {
case V_188 :
F_94 ( V_14 , V_205 , false ) ;
break;
case V_191 :
F_94 ( V_14 , V_204 , true ) ;
break;
default:
V_60 = F_87 ( V_14 ) ;
F_114 ( V_14 , V_60 , V_204 , V_205 ) ;
break;
}
}
static int F_117 ( struct V_19 * V_3 , int V_155 )
{
struct V_13 * V_14 ;
struct V_1 * V_181 ;
F_103 ( V_204 ) ;
F_103 ( V_205 ) ;
F_118 ( V_206 ) ;
enum V_71 V_207 ;
F_2 ( & V_3 -> V_5 ) ;
F_119 ( V_3 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_181 -> V_208 )
V_181 -> V_199 = V_198 ;
else
V_181 -> V_199 = V_200 ;
}
F_39 ( V_3 ) ;
F_17 (w, &card->dapm_dirty, dirty) {
F_116 ( V_14 , & V_204 , & V_205 ) ;
}
F_17 (w, &card->widgets, list) {
switch ( V_14 -> V_20 ) {
case V_188 :
case V_191 :
break;
default:
F_120 ( & V_14 -> V_15 ) ;
break;
}
if ( V_14 -> V_65 ) {
V_181 = V_14 -> V_2 ;
switch ( V_14 -> V_20 ) {
case V_147 :
case V_145 :
break;
case V_126 :
case V_127 :
case V_128 :
case V_209 :
if ( V_181 -> V_199 < V_200 )
V_181 -> V_199 = V_200 ;
break;
default:
V_181 -> V_199 = V_201 ;
break;
}
}
}
V_207 = V_198 ;
F_17 (d, &card->dapm_list, list)
if ( V_181 -> V_199 > V_207 )
V_207 = V_181 -> V_199 ;
F_17 (d, &card->dapm_list, list)
if ( ! V_181 -> V_208 )
V_181 -> V_199 = V_207 ;
F_121 ( V_3 ) ;
F_109 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_181 != & V_3 -> V_2 )
F_122 ( F_109 , V_181 ,
& V_206 ) ;
}
F_123 ( & V_206 ) ;
F_17 (w, &down_list, power_list) {
F_95 ( V_3 , V_14 , V_178 ) ;
}
F_17 (w, &up_list, power_list) {
F_95 ( V_3 , V_14 , V_177 ) ;
}
F_102 ( V_3 , & V_205 , V_155 , false ) ;
F_108 ( V_3 ) ;
F_102 ( V_3 , & V_204 , V_155 , true ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_181 != & V_3 -> V_2 )
F_122 ( F_111 , V_181 ,
& V_206 ) ;
}
F_123 ( & V_206 ) ;
F_111 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_181 -> V_210 )
V_181 -> V_210 ( V_181 , V_155 ) ;
}
F_6 ( V_3 -> V_8 , V_3 -> V_6 ,
L_37 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_124 ( V_3 ) ;
return 0 ;
}
static T_5 F_125 ( struct V_211 * V_211 ,
char T_6 * V_212 ,
T_3 V_213 , T_7 * V_214 )
{
struct V_13 * V_14 = V_211 -> V_48 ;
char * V_10 ;
int V_161 , V_75 ;
T_5 V_73 ;
struct V_56 * V_99 = NULL ;
V_10 = F_7 ( V_11 , V_12 ) ;
if ( ! V_10 )
return - V_31 ;
V_161 = F_72 ( V_14 , NULL ) ;
F_64 ( V_14 -> V_2 , & V_14 -> V_94 ) ;
V_75 = F_69 ( V_14 , NULL ) ;
F_63 ( V_14 -> V_2 , & V_14 -> V_96 ) ;
V_73 = snprintf ( V_10 , V_11 , L_38 ,
V_14 -> V_17 , V_14 -> V_60 ? L_39 : L_40 ,
V_14 -> V_159 ? L_41 : L_42 , V_161 , V_75 ) ;
if ( V_14 -> V_39 >= 0 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 ,
L_43 ,
V_14 -> V_39 , V_14 -> V_39 , V_14 -> V_40 << V_14 -> V_42 ) ;
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 , L_44 ) ;
if ( V_14 -> V_215 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 , L_45 ,
V_14 -> V_215 ,
V_14 -> V_132 ? L_46 : L_47 ) ;
F_17 (p, &w->sources, list_sink) {
if ( V_99 -> V_133 && ! V_99 -> V_133 ( V_14 , V_99 -> V_59 ) )
continue;
if ( V_99 -> V_97 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 ,
L_48 ,
V_99 -> V_17 ? V_99 -> V_17 : L_49 ,
V_99 -> V_59 -> V_17 ) ;
}
F_17 (p, &w->sinks, list_source) {
if ( V_99 -> V_133 && ! V_99 -> V_133 ( V_14 , V_99 -> V_117 ) )
continue;
if ( V_99 -> V_97 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 ,
L_50 ,
V_99 -> V_17 ? V_99 -> V_17 : L_49 ,
V_99 -> V_117 -> V_17 ) ;
}
V_73 = F_126 ( V_212 , V_213 , V_214 , V_10 , V_73 ) ;
F_9 ( V_10 ) ;
return V_73 ;
}
static T_5 F_127 ( struct V_211 * V_211 , char T_6 * V_212 ,
T_3 V_213 , T_7 * V_214 )
{
struct V_1 * V_2 = V_211 -> V_48 ;
char * V_72 ;
switch ( V_2 -> V_77 ) {
case V_201 :
V_72 = L_51 ;
break;
case V_202 :
V_72 = L_52 ;
break;
case V_200 :
V_72 = L_53 ;
break;
case V_198 :
V_72 = L_54 ;
break;
default:
F_96 ( 1 , L_55 , V_2 -> V_77 ) ;
V_72 = L_56 ;
break;
}
return F_126 ( V_212 , V_213 , V_214 , V_72 ,
strlen ( V_72 ) ) ;
}
void F_128 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
struct V_216 * V_181 ;
V_2 -> V_218 = F_129 ( L_57 , V_217 ) ;
if ( ! V_2 -> V_218 ) {
F_80 ( V_2 -> V_8 ,
L_58 ) ;
return;
}
V_181 = F_130 ( L_59 , 0444 ,
V_2 -> V_218 , V_2 ,
& V_219 ) ;
if ( ! V_181 )
F_80 ( V_2 -> V_8 ,
L_60 ) ;
}
static void F_131 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_216 * V_181 ;
if ( ! V_2 -> V_218 || ! V_14 -> V_17 )
return;
V_181 = F_130 ( V_14 -> V_17 , 0444 ,
V_2 -> V_218 , V_14 ,
& V_220 ) ;
if ( ! V_181 )
F_80 ( V_14 -> V_2 -> V_8 ,
L_61 ,
V_14 -> V_17 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_133 ( V_2 -> V_218 ) ;
}
void F_128 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
}
static inline void F_131 ( struct V_13 * V_14 )
{
}
static inline void F_132 ( struct V_1 * V_2 )
{
}
static int F_134 ( struct V_19 * V_3 ,
struct V_25 * V_26 , int V_221 , struct V_83 * V_84 )
{
struct V_56 * V_57 ;
int V_222 = 0 ;
F_2 ( & V_3 -> V_5 ) ;
F_135 (path, kcontrol) {
if ( ! V_57 -> V_17 || ! V_84 -> V_91 [ V_221 ] )
continue;
V_222 = 1 ;
if ( ! ( strcmp ( V_57 -> V_17 , V_84 -> V_91 [ V_221 ] ) ) ) {
V_57 -> V_97 = 1 ;
F_12 ( V_57 -> V_59 , L_62 ) ;
} else {
if ( V_57 -> V_97 )
F_12 ( V_57 -> V_59 ,
L_63 ) ;
V_57 -> V_97 = 0 ;
}
F_12 ( V_57 -> V_117 , L_64 ) ;
}
if ( V_222 )
F_117 ( V_3 , V_223 ) ;
return V_222 ;
}
int F_136 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_221 , struct V_83 * V_84 ,
struct V_192 * V_193 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
int V_73 ;
F_75 ( & V_3 -> V_5 , V_151 ) ;
V_3 -> V_193 = V_193 ;
V_73 = F_134 ( V_3 , V_26 , V_221 , V_84 ) ;
V_3 -> V_193 = NULL ;
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_137 ( V_3 ) ;
return V_73 ;
}
static int F_138 ( struct V_19 * V_3 ,
struct V_25 * V_26 , int V_97 )
{
struct V_56 * V_57 ;
int V_222 = 0 ;
F_2 ( & V_3 -> V_5 ) ;
F_135 (path, kcontrol) {
V_222 = 1 ;
V_57 -> V_97 = V_97 ;
F_12 ( V_57 -> V_59 , L_65 ) ;
F_12 ( V_57 -> V_117 , L_66 ) ;
}
if ( V_222 )
F_117 ( V_3 , V_223 ) ;
return V_222 ;
}
int F_139 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_97 ,
struct V_192 * V_193 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
int V_73 ;
F_75 ( & V_3 -> V_5 , V_151 ) ;
V_3 -> V_193 = V_193 ;
V_73 = F_138 ( V_3 , V_26 , V_97 ) ;
V_3 -> V_193 = NULL ;
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_137 ( V_3 ) ;
return V_73 ;
}
static T_5 F_140 ( struct V_7 * V_8 ,
struct V_224 * V_225 , char * V_10 )
{
struct V_226 * V_227 = F_141 ( V_8 ) ;
struct V_62 * V_63 = V_227 -> V_63 ;
struct V_13 * V_14 ;
int V_213 = 0 ;
char * V_228 = L_67 ;
F_17 (w, &codec->card->widgets, list) {
if ( V_14 -> V_2 != & V_63 -> V_2 )
continue;
switch ( V_14 -> V_20 ) {
case V_135 :
case V_146 :
case V_136 :
case V_137 :
case V_209 :
case V_142 :
case V_129 :
case V_229 :
case V_230 :
case V_34 :
case V_35 :
case V_126 :
case V_127 :
case V_128 :
if ( V_14 -> V_17 )
V_213 += sprintf ( V_10 + V_213 , L_68 ,
V_14 -> V_17 , V_14 -> V_60 ? L_39 : L_40 ) ;
break;
default:
break;
}
}
switch ( V_63 -> V_2 . V_77 ) {
case V_201 :
V_228 = L_39 ;
break;
case V_202 :
V_228 = L_69 ;
break;
case V_200 :
V_228 = L_70 ;
break;
case V_198 :
V_228 = L_40 ;
break;
}
V_213 += sprintf ( V_10 + V_213 , L_71 , V_228 ) ;
return V_213 ;
}
int F_142 ( struct V_7 * V_8 )
{
return F_143 ( V_8 , & V_231 ) ;
}
static void F_144 ( struct V_7 * V_8 )
{
F_145 ( V_8 , & V_231 ) ;
}
static void F_146 ( struct V_56 * V_57 )
{
F_147 ( & V_57 -> V_93 ) ;
F_147 ( & V_57 -> V_95 ) ;
F_147 ( & V_57 -> V_58 ) ;
F_147 ( & V_57 -> V_92 ) ;
F_9 ( V_57 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_232 ;
struct V_56 * V_99 , * V_233 ;
F_104 (w, next_w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
F_147 ( & V_14 -> V_92 ) ;
F_104 (p, next_p, &w->sources, list_sink)
F_146 ( V_99 ) ;
F_104 (p, next_p, &w->sinks, list_source)
F_146 ( V_99 ) ;
F_9 ( V_14 -> V_104 ) ;
F_9 ( V_14 -> V_17 ) ;
F_9 ( V_14 ) ;
}
}
static struct V_13 * F_149 (
struct V_1 * V_2 , const char * V_234 ,
bool V_235 )
{
struct V_13 * V_14 ;
struct V_13 * V_236 = NULL ;
F_17 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_14 -> V_17 , V_234 ) ) {
if ( V_14 -> V_2 == V_2 )
return V_14 ;
else
V_236 = V_14 ;
}
}
if ( V_235 )
return V_236 ;
return NULL ;
}
static int F_150 ( struct V_1 * V_2 ,
const char * V_234 , int V_237 )
{
struct V_13 * V_14 = F_149 ( V_2 , V_234 , true ) ;
F_1 ( V_2 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_72 , V_234 ) ;
return - V_115 ;
}
if ( V_14 -> V_133 != V_237 )
F_12 ( V_14 , L_73 ) ;
V_14 -> V_133 = V_237 ;
if ( V_237 == 0 )
V_14 -> V_159 = 0 ;
return 0 ;
}
int F_151 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_3 -> V_4 )
return 0 ;
return F_117 ( V_2 -> V_3 , V_223 ) ;
}
int F_152 ( struct V_1 * V_2 )
{
int V_73 ;
F_75 ( & V_2 -> V_3 -> V_5 , V_151 ) ;
V_73 = F_151 ( V_2 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_13 * V_238 , struct V_13 * V_239 ,
const char * V_240 ,
int (* V_133)( struct V_13 * V_59 ,
struct V_13 * V_117 ) )
{
struct V_56 * V_57 ;
int V_73 ;
V_57 = F_22 ( sizeof( struct V_56 ) , V_12 ) ;
if ( ! V_57 )
return - V_31 ;
V_57 -> V_59 = V_238 ;
V_57 -> V_117 = V_239 ;
V_57 -> V_133 = V_133 ;
F_24 ( & V_57 -> V_92 ) ;
F_24 ( & V_57 -> V_58 ) ;
F_24 ( & V_57 -> V_95 ) ;
F_24 ( & V_57 -> V_93 ) ;
if ( V_239 -> V_20 == V_21 ) {
if ( V_238 -> V_20 == V_209 ||
V_238 -> V_20 == V_146 ||
V_238 -> V_20 == V_137 ||
V_238 -> V_20 == V_22 )
V_239 -> V_134 = 1 ;
}
if ( V_238 -> V_20 == V_22 ) {
if ( V_239 -> V_20 == V_136 ||
V_239 -> V_20 == V_135 ||
V_239 -> V_20 == V_137 ||
V_239 -> V_20 == V_21 )
V_238 -> V_134 = 1 ;
}
F_12 ( V_238 , L_74 ) ;
F_12 ( V_239 , L_74 ) ;
if ( V_240 == NULL ) {
F_51 ( & V_57 -> V_92 , & V_2 -> V_3 -> V_32 ) ;
F_51 ( & V_57 -> V_93 , & V_239 -> V_94 ) ;
F_51 ( & V_57 -> V_95 , & V_238 -> V_96 ) ;
V_57 -> V_97 = 1 ;
return 0 ;
}
switch ( V_239 -> V_20 ) {
case V_129 :
case V_142 :
case V_229 :
case V_230 :
case V_21 :
case V_22 :
case V_147 :
case V_209 :
case V_145 :
case V_188 :
case V_191 :
case V_126 :
case V_127 :
case V_128 :
case V_143 :
case V_130 :
case V_144 :
case V_131 :
case V_241 :
case V_46 :
F_51 ( & V_57 -> V_92 , & V_2 -> V_3 -> V_32 ) ;
F_51 ( & V_57 -> V_93 , & V_239 -> V_94 ) ;
F_51 ( & V_57 -> V_95 , & V_238 -> V_96 ) ;
V_57 -> V_97 = 1 ;
return 0 ;
case V_114 :
V_73 = F_49 ( V_2 , V_238 , V_239 , V_57 , V_240 ,
& V_239 -> V_100 [ 0 ] ) ;
if ( V_73 != 0 )
goto V_141;
break;
case V_33 :
case V_34 :
case V_35 :
V_73 = F_53 ( V_2 , V_238 , V_239 , V_57 , V_240 ) ;
if ( V_73 != 0 )
goto V_141;
break;
case V_135 :
case V_146 :
case V_137 :
case V_136 :
F_51 ( & V_57 -> V_92 , & V_2 -> V_3 -> V_32 ) ;
F_51 ( & V_57 -> V_93 , & V_239 -> V_94 ) ;
F_51 ( & V_57 -> V_95 , & V_238 -> V_96 ) ;
V_57 -> V_97 = 0 ;
return 0 ;
}
return 0 ;
V_141:
F_9 ( V_57 ) ;
return V_73 ;
}
static int F_153 ( struct V_1 * V_2 ,
const struct V_242 * V_243 )
{
struct V_13 * V_238 = NULL , * V_239 = NULL , * V_14 ;
struct V_13 * V_244 = NULL , * V_245 = NULL ;
const char * V_117 ;
const char * V_59 ;
char V_246 [ 80 ] ;
char V_247 [ 80 ] ;
int V_73 ;
if ( V_2 -> V_63 && V_2 -> V_63 -> V_113 ) {
snprintf ( V_246 , sizeof( V_246 ) , L_5 ,
V_2 -> V_63 -> V_113 , V_243 -> V_117 ) ;
V_117 = V_246 ;
snprintf ( V_247 , sizeof( V_247 ) , L_5 ,
V_2 -> V_63 -> V_113 , V_243 -> V_59 ) ;
V_59 = V_247 ;
} else {
V_117 = V_243 -> V_117 ;
V_59 = V_243 -> V_59 ;
}
F_17 (w, &dapm->card->widgets, list) {
if ( ! V_239 && ! ( strcmp ( V_14 -> V_17 , V_117 ) ) ) {
V_245 = V_14 ;
if ( V_14 -> V_2 == V_2 )
V_239 = V_14 ;
continue;
}
if ( ! V_238 && ! ( strcmp ( V_14 -> V_17 , V_59 ) ) ) {
V_244 = V_14 ;
if ( V_14 -> V_2 == V_2 )
V_238 = V_14 ;
}
}
if ( ! V_239 )
V_239 = V_245 ;
if ( ! V_238 )
V_238 = V_244 ;
if ( V_238 == NULL ) {
F_23 ( V_2 -> V_8 , L_75 ,
V_243 -> V_59 ) ;
return - V_98 ;
}
if ( V_239 == NULL ) {
F_23 ( V_2 -> V_8 , L_76 ,
V_243 -> V_117 ) ;
return - V_98 ;
}
V_73 = F_33 ( V_2 , V_238 , V_239 , V_243 -> V_240 ,
V_243 -> V_133 ) ;
if ( V_73 )
goto V_141;
return 0 ;
V_141:
F_80 ( V_2 -> V_8 , L_77 ,
V_59 , V_243 -> V_240 , V_117 ) ;
return V_73 ;
}
static int F_154 ( struct V_1 * V_2 ,
const struct V_242 * V_243 )
{
struct V_56 * V_57 , * V_99 ;
const char * V_117 ;
const char * V_59 ;
char V_246 [ 80 ] ;
char V_247 [ 80 ] ;
if ( V_243 -> V_240 ) {
F_23 ( V_2 -> V_8 ,
L_78 ) ;
return - V_115 ;
}
if ( V_2 -> V_63 && V_2 -> V_63 -> V_113 ) {
snprintf ( V_246 , sizeof( V_246 ) , L_5 ,
V_2 -> V_63 -> V_113 , V_243 -> V_117 ) ;
V_117 = V_246 ;
snprintf ( V_247 , sizeof( V_247 ) , L_5 ,
V_2 -> V_63 -> V_113 , V_243 -> V_59 ) ;
V_59 = V_247 ;
} else {
V_117 = V_243 -> V_117 ;
V_59 = V_243 -> V_59 ;
}
V_57 = NULL ;
F_17 (p, &dapm->card->paths, list) {
if ( strcmp ( V_99 -> V_59 -> V_17 , V_59 ) != 0 )
continue;
if ( strcmp ( V_99 -> V_117 -> V_17 , V_117 ) != 0 )
continue;
V_57 = V_99 ;
break;
}
if ( V_57 ) {
F_12 ( V_57 -> V_59 , L_79 ) ;
F_12 ( V_57 -> V_117 , L_79 ) ;
F_146 ( V_57 ) ;
} else {
F_80 ( V_2 -> V_8 , L_80 ,
V_59 , V_117 ) ;
}
return 0 ;
}
int F_155 ( struct V_1 * V_2 ,
const struct V_242 * V_243 , int V_248 )
{
int V_87 , V_249 , V_73 = 0 ;
F_75 ( & V_2 -> V_3 -> V_5 , V_250 ) ;
for ( V_87 = 0 ; V_87 < V_248 ; V_87 ++ ) {
V_249 = F_153 ( V_2 , V_243 ) ;
if ( V_249 < 0 ) {
F_23 ( V_2 -> V_8 , L_81 ,
V_243 -> V_59 ,
V_243 -> V_240 ? V_243 -> V_240 : L_82 ,
V_243 -> V_117 ) ;
V_73 = V_249 ;
}
V_243 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_156 ( struct V_1 * V_2 ,
const struct V_242 * V_243 , int V_248 )
{
int V_87 , V_73 = 0 ;
F_75 ( & V_2 -> V_3 -> V_5 , V_250 ) ;
for ( V_87 = 0 ; V_87 < V_248 ; V_87 ++ ) {
F_154 ( V_2 , V_243 ) ;
V_243 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
static int F_157 ( struct V_1 * V_2 ,
const struct V_242 * V_243 )
{
struct V_13 * V_59 = F_149 ( V_2 ,
V_243 -> V_59 ,
true ) ;
struct V_13 * V_117 = F_149 ( V_2 ,
V_243 -> V_117 ,
true ) ;
struct V_56 * V_57 ;
int V_213 = 0 ;
if ( ! V_59 ) {
F_23 ( V_2 -> V_8 , L_83 ,
V_243 -> V_59 ) ;
return - V_98 ;
}
if ( ! V_117 ) {
F_23 ( V_2 -> V_8 , L_84 ,
V_243 -> V_117 ) ;
return - V_98 ;
}
if ( V_243 -> V_240 || V_243 -> V_133 )
F_80 ( V_2 -> V_8 , L_85 ,
V_243 -> V_59 , V_243 -> V_117 ) ;
F_17 (path, &source->sinks, list_source) {
if ( V_57 -> V_117 == V_117 ) {
V_57 -> V_139 = 1 ;
V_213 ++ ;
}
}
if ( V_213 == 0 )
F_23 ( V_2 -> V_8 , L_86 ,
V_243 -> V_59 , V_243 -> V_117 ) ;
if ( V_213 > 1 )
F_80 ( V_2 -> V_8 , L_87 ,
V_213 , V_243 -> V_59 , V_243 -> V_117 ) ;
return 0 ;
}
int F_158 ( struct V_1 * V_2 ,
const struct V_242 * V_243 , int V_248 )
{
int V_87 , V_141 ;
int V_73 = 0 ;
F_75 ( & V_2 -> V_3 -> V_5 , V_250 ) ;
for ( V_87 = 0 ; V_87 < V_248 ; V_87 ++ ) {
V_141 = F_157 ( V_2 , V_243 ) ;
if ( V_141 )
V_73 = V_141 ;
V_243 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_159 ( struct V_19 * V_3 )
{
struct V_13 * V_14 ;
unsigned int V_85 ;
F_75 ( & V_3 -> V_5 , V_250 ) ;
F_17 (w, &card->widgets, list)
{
if ( V_14 -> V_251 )
continue;
if ( V_14 -> V_101 ) {
V_14 -> V_104 = F_22 ( V_14 -> V_101 *
sizeof( struct V_25 * ) ,
V_12 ) ;
if ( ! V_14 -> V_104 ) {
F_18 ( & V_3 -> V_5 ) ;
return - V_31 ;
}
}
switch( V_14 -> V_20 ) {
case V_33 :
case V_34 :
case V_35 :
F_60 ( V_14 ) ;
break;
case V_114 :
F_61 ( V_14 ) ;
break;
case V_229 :
case V_230 :
F_62 ( V_14 ) ;
break;
default:
break;
}
if ( V_14 -> V_39 >= 0 ) {
F_40 ( V_14 , V_14 -> V_39 , & V_85 ) ;
V_85 = V_85 >> V_14 -> V_42 ;
V_85 &= V_14 -> V_40 ;
if ( V_85 == V_14 -> V_45 )
V_14 -> V_60 = 1 ;
}
V_14 -> V_251 = 1 ;
F_12 ( V_14 , L_88 ) ;
F_131 ( V_14 ) ;
}
F_117 ( V_3 , V_223 ) ;
F_18 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_160 ( struct V_25 * V_26 ,
struct V_252 * V_253 )
{
struct V_62 * V_63 = F_38 ( V_26 ) ;
struct V_19 * V_3 = V_63 -> V_3 ;
struct V_29 * V_30 =
(struct V_29 * ) V_26 -> V_36 ;
int V_39 = V_30 -> V_39 ;
unsigned int V_42 = V_30 -> V_42 ;
int V_41 = V_30 -> V_41 ;
unsigned int V_40 = ( 1 << F_25 ( V_41 ) ) - 1 ;
unsigned int V_43 = V_30 -> V_43 ;
unsigned int V_85 ;
if ( F_161 ( V_30 ) )
F_80 ( V_63 -> V_2 . V_8 ,
L_89 ,
V_26 -> V_20 . V_17 ) ;
F_75 ( & V_3 -> V_5 , V_151 ) ;
if ( F_34 ( V_26 ) && V_39 != V_88 )
V_85 = ( F_162 ( V_63 , V_39 ) >> V_42 ) & V_40 ;
else
V_85 = F_36 ( V_26 ) ;
F_18 ( & V_3 -> V_5 ) ;
if ( V_43 )
V_253 -> V_47 . integer . V_47 [ 0 ] = V_41 - V_85 ;
else
V_253 -> V_47 . integer . V_47 [ 0 ] = V_85 ;
return 0 ;
}
int F_163 ( struct V_25 * V_26 ,
struct V_252 * V_253 )
{
struct V_62 * V_63 = F_38 ( V_26 ) ;
struct V_19 * V_3 = V_63 -> V_3 ;
struct V_29 * V_30 =
(struct V_29 * ) V_26 -> V_36 ;
int V_39 = V_30 -> V_39 ;
unsigned int V_42 = V_30 -> V_42 ;
int V_41 = V_30 -> V_41 ;
unsigned int V_40 = ( 1 << F_25 ( V_41 ) ) - 1 ;
unsigned int V_43 = V_30 -> V_43 ;
unsigned int V_85 ;
int V_97 , V_254 , V_255 = 0 ;
struct V_192 V_193 ;
int V_73 = 0 ;
if ( F_161 ( V_30 ) )
F_80 ( V_63 -> V_2 . V_8 ,
L_89 ,
V_26 -> V_20 . V_17 ) ;
V_85 = ( V_253 -> V_47 . integer . V_47 [ 0 ] & V_40 ) ;
V_97 = ! ! V_85 ;
if ( V_43 )
V_85 = V_41 - V_85 ;
F_75 ( & V_3 -> V_5 , V_151 ) ;
V_254 = F_37 ( V_26 , V_85 ) ;
if ( V_39 != V_88 ) {
V_40 = V_40 << V_42 ;
V_85 = V_85 << V_42 ;
V_255 = F_164 ( V_63 , V_39 , V_40 , V_85 ) ;
}
if ( V_254 || V_255 ) {
if ( V_255 ) {
V_193 . V_26 = V_26 ;
V_193 . V_39 = V_39 ;
V_193 . V_40 = V_40 ;
V_193 . V_85 = V_85 ;
V_3 -> V_193 = & V_193 ;
}
V_254 |= V_255 ;
V_73 = F_138 ( V_3 , V_26 , V_97 ) ;
V_3 -> V_193 = NULL ;
}
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_137 ( V_3 ) ;
return V_254 ;
}
int F_165 ( struct V_25 * V_26 ,
struct V_252 * V_253 )
{
struct V_62 * V_63 = F_38 ( V_26 ) ;
struct V_83 * V_84 = (struct V_83 * ) V_26 -> V_36 ;
unsigned int V_256 , V_85 ;
if ( V_84 -> V_39 != V_88 )
V_256 = F_162 ( V_63 , V_84 -> V_39 ) ;
else
V_256 = F_36 ( V_26 ) ;
V_85 = ( V_256 >> V_84 -> V_89 ) & V_84 -> V_40 ;
V_253 -> V_47 . V_257 . V_86 [ 0 ] = F_50 ( V_84 , V_85 ) ;
if ( V_84 -> V_89 != V_84 -> V_258 ) {
V_85 = ( V_256 >> V_84 -> V_258 ) & V_84 -> V_40 ;
V_85 = F_50 ( V_84 , V_85 ) ;
V_253 -> V_47 . V_257 . V_86 [ 1 ] = V_85 ;
}
return 0 ;
}
int F_166 ( struct V_25 * V_26 ,
struct V_252 * V_253 )
{
struct V_62 * V_63 = F_38 ( V_26 ) ;
struct V_19 * V_3 = V_63 -> V_3 ;
struct V_83 * V_84 = (struct V_83 * ) V_26 -> V_36 ;
unsigned int * V_86 = V_253 -> V_47 . V_257 . V_86 ;
unsigned int V_85 , V_254 ;
unsigned int V_40 ;
struct V_192 V_193 ;
int V_73 = 0 ;
if ( V_86 [ 0 ] >= V_84 -> V_90 )
return - V_115 ;
V_85 = F_167 ( V_84 , V_86 [ 0 ] ) << V_84 -> V_89 ;
V_40 = V_84 -> V_40 << V_84 -> V_89 ;
if ( V_84 -> V_89 != V_84 -> V_258 ) {
if ( V_86 [ 1 ] > V_84 -> V_90 )
return - V_115 ;
V_85 |= F_167 ( V_84 , V_86 [ 1 ] ) << V_84 -> V_89 ;
V_40 |= V_84 -> V_40 << V_84 -> V_258 ;
}
F_75 ( & V_3 -> V_5 , V_151 ) ;
if ( V_84 -> V_39 != V_88 )
V_254 = F_164 ( V_63 , V_84 -> V_39 , V_40 , V_85 ) ;
else
V_254 = F_37 ( V_26 , V_85 ) ;
if ( V_254 ) {
if ( V_84 -> V_39 != V_88 ) {
V_193 . V_26 = V_26 ;
V_193 . V_39 = V_84 -> V_39 ;
V_193 . V_40 = V_40 ;
V_193 . V_85 = V_85 ;
V_3 -> V_193 = & V_193 ;
}
V_73 = F_134 ( V_3 , V_26 , V_86 [ 0 ] , V_84 ) ;
V_3 -> V_193 = NULL ;
}
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_137 ( V_3 ) ;
return V_254 ;
}
int F_168 ( struct V_25 * V_26 ,
struct V_259 * V_260 )
{
V_260 -> type = V_261 ;
V_260 -> V_213 = 1 ;
V_260 -> V_47 . integer . V_262 = 0 ;
V_260 -> V_47 . integer . V_41 = 1 ;
return 0 ;
}
int F_169 ( struct V_25 * V_26 ,
struct V_252 * V_253 )
{
struct V_19 * V_3 = F_28 ( V_26 ) ;
const char * V_234 = ( const char * ) V_26 -> V_36 ;
F_75 ( & V_3 -> V_5 , V_151 ) ;
V_253 -> V_47 . integer . V_47 [ 0 ] =
F_170 ( & V_3 -> V_2 , V_234 ) ;
F_18 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_171 ( struct V_25 * V_26 ,
struct V_252 * V_253 )
{
struct V_19 * V_3 = F_28 ( V_26 ) ;
const char * V_234 = ( const char * ) V_26 -> V_36 ;
if ( V_253 -> V_47 . integer . V_47 [ 0 ] )
F_172 ( & V_3 -> V_2 , V_234 ) ;
else
F_173 ( & V_3 -> V_2 , V_234 ) ;
F_152 ( & V_3 -> V_2 ) ;
return 0 ;
}
static struct V_13 *
F_26 ( struct V_1 * V_2 ,
const struct V_13 * V_24 )
{
struct V_13 * V_14 ;
int V_73 ;
if ( ( V_14 = F_19 ( V_24 ) ) == NULL )
return NULL ;
switch ( V_14 -> V_20 ) {
case V_127 :
V_14 -> V_157 = F_174 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_175 ( V_14 -> V_157 ) ) {
V_73 = F_176 ( V_14 -> V_157 ) ;
F_23 ( V_2 -> V_8 , L_90 ,
V_14 -> V_17 , V_73 ) ;
return NULL ;
}
if ( V_14 -> V_45 & V_156 ) {
V_73 = F_79 ( V_14 -> V_157 , true ) ;
if ( V_73 != 0 )
F_80 ( V_14 -> V_2 -> V_8 ,
L_15 ,
V_14 -> V_17 , V_73 ) ;
}
break;
case V_128 :
#ifdef F_177
V_14 -> V_158 = F_178 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_175 ( V_14 -> V_158 ) ) {
V_73 = F_176 ( V_14 -> V_158 ) ;
F_23 ( V_2 -> V_8 , L_90 ,
V_14 -> V_17 , V_73 ) ;
return NULL ;
}
#else
return NULL ;
#endif
break;
default:
break;
}
if ( V_2 -> V_63 && V_2 -> V_63 -> V_113 )
V_14 -> V_17 = F_56 ( V_12 , L_5 ,
V_2 -> V_63 -> V_113 , V_24 -> V_17 ) ;
else
V_14 -> V_17 = F_56 ( V_12 , L_1 , V_24 -> V_17 ) ;
if ( V_14 -> V_17 == NULL ) {
F_9 ( V_14 ) ;
return NULL ;
}
switch ( V_14 -> V_20 ) {
case V_33 :
case V_34 :
case V_35 :
V_14 -> V_160 = F_88 ;
break;
case V_114 :
V_14 -> V_160 = F_88 ;
break;
case V_131 :
V_14 -> V_160 = F_89 ;
break;
case V_144 :
V_14 -> V_160 = F_90 ;
break;
case V_129 :
case V_130 :
case V_142 :
case V_143 :
case V_229 :
case V_230 :
case V_21 :
case V_22 :
case V_209 :
case V_136 :
case V_135 :
case V_146 :
case V_137 :
case V_241 :
V_14 -> V_160 = F_88 ;
break;
case V_126 :
case V_127 :
case V_128 :
case V_46 :
V_14 -> V_160 = F_91 ;
break;
default:
V_14 -> V_160 = F_92 ;
break;
}
V_14 -> V_2 = V_2 ;
V_14 -> V_63 = V_2 -> V_63 ;
V_14 -> V_263 = V_2 -> V_263 ;
F_24 ( & V_14 -> V_94 ) ;
F_24 ( & V_14 -> V_96 ) ;
F_24 ( & V_14 -> V_92 ) ;
F_24 ( & V_14 -> V_15 ) ;
F_51 ( & V_14 -> V_92 , & V_2 -> V_3 -> V_55 ) ;
V_14 -> V_133 = 1 ;
return V_14 ;
}
int F_179 ( struct V_1 * V_2 ,
const struct V_13 * V_24 ,
int V_248 )
{
struct V_13 * V_14 ;
int V_87 ;
int V_73 = 0 ;
F_75 ( & V_2 -> V_3 -> V_5 , V_250 ) ;
for ( V_87 = 0 ; V_87 < V_248 ; V_87 ++ ) {
V_14 = F_26 ( V_2 , V_24 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 ,
L_91 ,
V_24 -> V_17 ) ;
V_73 = - V_31 ;
break;
}
V_24 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
static int F_180 ( struct V_13 * V_14 ,
struct V_25 * V_26 , int V_155 )
{
struct V_56 * V_264 , * V_265 ;
struct V_148 * V_59 , * V_117 ;
const struct V_266 * V_267 = V_14 -> V_268 ;
struct V_269 V_270 ;
struct V_271 * V_268 = NULL ;
T_8 V_9 ;
int V_73 ;
if ( F_101 ( ! V_267 ) ||
F_101 ( F_11 ( & V_14 -> V_94 ) || F_11 ( & V_14 -> V_96 ) ) )
return - V_115 ;
V_264 = F_100 ( & V_14 -> V_94 , struct V_56 ,
V_93 ) ;
V_265 = F_100 ( & V_14 -> V_96 , struct V_56 ,
V_95 ) ;
if ( F_101 ( ! V_264 || ! V_265 ) ||
F_101 ( ! V_265 -> V_59 || ! V_264 -> V_117 ) ||
F_101 ( ! V_264 -> V_59 || ! V_265 -> V_117 ) )
return - V_115 ;
V_59 = V_264 -> V_59 -> V_272 ;
V_117 = V_265 -> V_117 -> V_272 ;
if ( V_267 -> V_273 ) {
V_9 = F_181 ( V_267 -> V_273 ) - 1 ;
} else {
F_80 ( V_14 -> V_2 -> V_8 , L_92 ,
V_267 -> V_273 ) ;
V_9 = 0 ;
}
V_268 = F_22 ( sizeof( * V_268 ) , V_12 ) ;
if ( ! V_268 ) {
V_73 = - V_31 ;
goto V_75;
}
F_182 ( F_183 ( V_268 , V_274 ) , V_9 ) ;
F_184 ( V_268 , V_275 ) -> V_262 =
V_267 -> V_276 ;
F_184 ( V_268 , V_275 ) -> V_41 =
V_267 -> V_277 ;
F_184 ( V_268 , V_278 ) -> V_262
= V_267 -> V_279 ;
F_184 ( V_268 , V_278 ) -> V_41
= V_267 -> V_280 ;
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
switch ( V_155 ) {
case V_173 :
if ( V_59 -> V_76 -> V_281 && V_59 -> V_76 -> V_281 -> V_282 ) {
V_270 . V_150 = V_283 ;
V_73 = V_59 -> V_76 -> V_281 -> V_282 ( & V_270 ,
V_268 , V_59 ) ;
if ( V_73 != 0 ) {
F_23 ( V_59 -> V_8 ,
L_93 , V_73 ) ;
goto V_75;
}
}
if ( V_117 -> V_76 -> V_281 && V_117 -> V_76 -> V_281 -> V_282 ) {
V_270 . V_150 = V_152 ;
V_73 = V_117 -> V_76 -> V_281 -> V_282 ( & V_270 , V_268 ,
V_117 ) ;
if ( V_73 != 0 ) {
F_23 ( V_117 -> V_8 ,
L_93 , V_73 ) ;
goto V_75;
}
}
break;
case V_174 :
V_73 = F_185 ( V_117 , 0 ,
V_152 ) ;
if ( V_73 != 0 && V_73 != - V_284 )
F_80 ( V_117 -> V_8 , L_94 , V_73 ) ;
V_73 = 0 ;
break;
case V_175 :
V_73 = F_185 ( V_117 , 1 ,
V_152 ) ;
if ( V_73 != 0 && V_73 != - V_284 )
F_80 ( V_117 -> V_8 , L_95 , V_73 ) ;
V_73 = 0 ;
break;
default:
F_96 ( 1 , L_22 , V_155 ) ;
return - V_115 ;
}
V_75:
F_9 ( V_268 ) ;
return V_73 ;
}
int F_186 ( struct V_19 * V_3 ,
const struct V_266 * V_268 ,
struct V_13 * V_59 ,
struct V_13 * V_117 )
{
struct V_13 V_38 ;
struct V_13 * V_14 ;
T_3 V_285 ;
char * V_286 ;
int V_73 ;
V_285 = strlen ( V_59 -> V_17 ) + strlen ( V_117 -> V_17 ) + 2 ;
V_286 = F_187 ( V_3 -> V_8 , V_285 , V_12 ) ;
if ( ! V_286 )
return - V_31 ;
snprintf ( V_286 , V_285 , L_96 , V_59 -> V_17 , V_117 -> V_17 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_39 = V_88 ;
V_38 . V_20 = V_241 ;
V_38 . V_17 = V_286 ;
V_38 . V_155 = F_180 ;
V_38 . V_179 = V_173 | V_174 |
V_175 ;
F_67 ( V_3 -> V_8 , L_97 , V_286 ) ;
V_14 = F_26 ( & V_3 -> V_2 , & V_38 ) ;
if ( ! V_14 ) {
F_23 ( V_3 -> V_8 , L_98 ,
V_286 ) ;
return - V_31 ;
}
V_14 -> V_268 = V_268 ;
V_73 = F_33 ( & V_3 -> V_2 , V_59 , V_14 , NULL , NULL ) ;
if ( V_73 )
return V_73 ;
return F_33 ( & V_3 -> V_2 , V_14 , V_117 , NULL , NULL ) ;
}
int F_188 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
struct V_13 V_38 ;
struct V_13 * V_14 ;
F_101 ( V_2 -> V_8 != V_149 -> V_8 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_39 = V_88 ;
if ( V_149 -> V_76 -> V_287 . V_288 ) {
V_38 . V_20 = V_144 ;
V_38 . V_17 = V_149 -> V_76 -> V_287 . V_288 ;
V_38 . V_215 = V_149 -> V_76 -> V_287 . V_288 ;
F_67 ( V_149 -> V_8 , L_97 ,
V_38 . V_17 ) ;
V_14 = F_26 ( V_2 , & V_38 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_98 ,
V_149 -> V_76 -> V_287 . V_288 ) ;
return - V_31 ;
}
V_14 -> V_272 = V_149 ;
V_149 -> V_153 = V_14 ;
}
if ( V_149 -> V_76 -> V_289 . V_288 ) {
V_38 . V_20 = V_131 ;
V_38 . V_17 = V_149 -> V_76 -> V_289 . V_288 ;
V_38 . V_215 = V_149 -> V_76 -> V_289 . V_288 ;
F_67 ( V_149 -> V_8 , L_97 ,
V_38 . V_17 ) ;
V_14 = F_26 ( V_2 , & V_38 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_98 ,
V_149 -> V_76 -> V_289 . V_288 ) ;
return - V_31 ;
}
V_14 -> V_272 = V_149 ;
V_149 -> V_154 = V_14 ;
}
return 0 ;
}
int F_189 ( struct V_19 * V_3 )
{
struct V_13 * V_290 , * V_14 ;
struct V_13 * V_79 , * V_117 ;
struct V_148 * V_149 ;
F_17 (dai_w, &card->widgets, list) {
switch ( V_290 -> V_20 ) {
case V_144 :
case V_131 :
break;
default:
continue;
}
V_149 = V_290 -> V_272 ;
F_17 (w, &card->widgets, list) {
if ( V_14 -> V_2 != V_290 -> V_2 )
continue;
switch ( V_14 -> V_20 ) {
case V_144 :
case V_131 :
continue;
default:
break;
}
if ( ! V_14 -> V_215 || ! strstr ( V_14 -> V_215 , V_290 -> V_17 ) )
continue;
if ( V_290 -> V_20 == V_144 ) {
V_79 = V_290 ;
V_117 = V_14 ;
} else {
V_79 = V_14 ;
V_117 = V_290 ;
}
F_67 ( V_149 -> V_8 , L_99 , V_79 -> V_17 , V_117 -> V_17 ) ;
F_33 ( V_14 -> V_2 , V_79 , V_117 , NULL , NULL ) ;
}
}
return 0 ;
}
void F_190 ( struct V_19 * V_3 )
{
struct V_226 * V_227 = V_3 -> V_227 ;
struct V_13 * V_117 , * V_59 ;
struct V_148 * V_291 , * V_292 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_3 -> V_293 ; V_87 ++ ) {
V_227 = & V_3 -> V_227 [ V_87 ] ;
V_291 = V_227 -> V_291 ;
V_292 = V_227 -> V_292 ;
if ( V_227 -> V_294 -> V_295 || V_227 -> V_294 -> V_268 )
continue;
if ( F_191 ( V_292 ) ||
F_191 ( V_291 ) )
continue;
if ( V_292 -> V_153 && V_291 -> V_153 ) {
V_59 = V_291 -> V_153 ;
V_117 = V_292 -> V_153 ;
F_67 ( V_227 -> V_8 , L_100 ,
V_291 -> V_63 -> V_17 , V_59 -> V_17 ,
V_292 -> V_263 -> V_17 , V_117 -> V_17 ) ;
F_33 ( & V_3 -> V_2 , V_59 , V_117 ,
NULL , NULL ) ;
}
if ( V_292 -> V_154 && V_291 -> V_154 ) {
V_59 = V_292 -> V_154 ;
V_117 = V_291 -> V_154 ;
F_67 ( V_227 -> V_8 , L_100 ,
V_292 -> V_63 -> V_17 , V_59 -> V_17 ,
V_291 -> V_263 -> V_17 , V_117 -> V_17 ) ;
F_33 ( & V_3 -> V_2 , V_59 , V_117 ,
NULL , NULL ) ;
}
}
}
static void F_192 ( struct V_148 * V_149 , int V_150 ,
int V_155 )
{
struct V_13 * V_14 ;
if ( V_150 == V_152 )
V_14 = V_149 -> V_153 ;
else
V_14 = V_149 -> V_154 ;
if ( V_14 ) {
F_12 ( V_14 , L_101 ) ;
switch ( V_155 ) {
case V_189 :
V_14 -> V_132 = 1 ;
break;
case V_190 :
V_14 -> V_132 = 0 ;
break;
case V_296 :
case V_297 :
case V_298 :
case V_299 :
break;
}
}
}
static void F_193 ( struct V_226 * V_227 , int V_150 ,
int V_155 )
{
F_192 ( V_227 -> V_291 , V_150 , V_155 ) ;
F_192 ( V_227 -> V_292 , V_150 , V_155 ) ;
F_117 ( V_227 -> V_3 , V_155 ) ;
}
void F_194 ( struct V_226 * V_227 , int V_150 ,
int V_155 )
{
struct V_19 * V_3 = V_227 -> V_3 ;
F_75 ( & V_3 -> V_5 , V_151 ) ;
F_193 ( V_227 , V_150 , V_155 ) ;
F_18 ( & V_3 -> V_5 ) ;
}
int F_195 ( struct V_1 * V_2 ,
const char * V_234 )
{
return F_150 ( V_2 , V_234 , 1 ) ;
}
int F_172 ( struct V_1 * V_2 , const char * V_234 )
{
int V_73 ;
F_75 ( & V_2 -> V_3 -> V_5 , V_151 ) ;
V_73 = F_150 ( V_2 , V_234 , 1 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_196 ( struct V_1 * V_2 ,
const char * V_234 )
{
struct V_13 * V_14 = F_149 ( V_2 , V_234 , true ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_102 , V_234 ) ;
return - V_115 ;
}
F_67 ( V_14 -> V_2 -> V_8 , L_103 , V_234 ) ;
V_14 -> V_133 = 1 ;
V_14 -> V_159 = 1 ;
F_12 ( V_14 , L_104 ) ;
return 0 ;
}
int F_197 ( struct V_1 * V_2 ,
const char * V_234 )
{
int V_73 ;
F_75 ( & V_2 -> V_3 -> V_5 , V_151 ) ;
V_73 = F_196 ( V_2 , V_234 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_198 ( struct V_1 * V_2 ,
const char * V_234 )
{
return F_150 ( V_2 , V_234 , 0 ) ;
}
int F_173 ( struct V_1 * V_2 ,
const char * V_234 )
{
int V_73 ;
F_75 ( & V_2 -> V_3 -> V_5 , V_151 ) ;
V_73 = F_150 ( V_2 , V_234 , 0 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_199 ( struct V_1 * V_2 ,
const char * V_234 )
{
return F_150 ( V_2 , V_234 , 0 ) ;
}
int F_200 ( struct V_1 * V_2 , const char * V_234 )
{
int V_73 ;
F_75 ( & V_2 -> V_3 -> V_5 , V_151 ) ;
V_73 = F_150 ( V_2 , V_234 , 0 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_170 ( struct V_1 * V_2 ,
const char * V_234 )
{
struct V_13 * V_14 = F_149 ( V_2 , V_234 , true ) ;
if ( V_14 )
return V_14 -> V_133 ;
return 0 ;
}
int F_201 ( struct V_1 * V_2 ,
const char * V_234 )
{
struct V_13 * V_14 = F_149 ( V_2 , V_234 , false ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_102 , V_234 ) ;
return - V_115 ;
}
V_14 -> V_121 = 1 ;
return 0 ;
}
static bool F_202 ( struct V_19 * V_3 ,
struct V_13 * V_14 )
{
struct V_56 * V_99 ;
F_17 (p, &card->paths, list) {
if ( ( V_99 -> V_59 == V_14 ) || ( V_99 -> V_117 == V_14 ) ) {
F_67 ( V_3 -> V_8 ,
L_105 ,
V_99 -> V_59 -> V_17 , V_99 -> V_59 -> V_20 , V_99 -> V_59 -> V_2 ,
V_99 -> V_117 -> V_17 , V_99 -> V_117 -> V_20 , V_99 -> V_117 -> V_2 ) ;
if ( V_99 -> V_59 -> V_2 != V_99 -> V_117 -> V_2 )
return true ;
if ( V_99 -> V_117 -> V_20 == V_21 ) {
switch ( V_99 -> V_59 -> V_20 ) {
case V_22 :
case V_209 :
return true ;
default:
break;
}
}
}
}
return false ;
}
void F_203 ( struct V_62 * V_63 )
{
struct V_19 * V_3 = V_63 -> V_3 ;
struct V_1 * V_2 = & V_63 -> V_2 ;
struct V_13 * V_14 ;
F_67 ( V_63 -> V_8 , L_106 ,
& V_3 -> V_2 , & V_63 -> V_2 ) ;
F_17 (w, &card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
switch ( V_14 -> V_20 ) {
case V_21 :
case V_22 :
case V_209 :
F_67 ( V_63 -> V_8 , L_107 ,
V_14 -> V_17 ) ;
if ( ! F_202 ( V_3 , V_14 ) ) {
F_67 ( V_63 -> V_8 ,
L_108 ) ;
F_200 ( V_2 , V_14 -> V_17 ) ;
}
break;
default:
break;
}
}
}
void F_204 ( struct V_1 * V_2 )
{
F_144 ( V_2 -> V_8 ) ;
F_132 ( V_2 ) ;
F_148 ( V_2 ) ;
F_147 ( & V_2 -> V_92 ) ;
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
struct V_13 * V_14 ;
F_103 ( V_205 ) ;
int V_300 = 0 ;
F_16 ( & V_3 -> V_5 ) ;
F_17 (w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
if ( V_14 -> V_60 ) {
F_94 ( V_14 , & V_205 , false ) ;
V_14 -> V_60 = 0 ;
V_300 = 1 ;
}
}
if ( V_300 ) {
if ( V_2 -> V_77 == V_201 )
F_46 ( V_2 ,
V_202 ) ;
F_102 ( V_3 , & V_205 , 0 , false ) ;
if ( V_2 -> V_77 == V_202 )
F_46 ( V_2 ,
V_200 ) ;
}
F_18 ( & V_3 -> V_5 ) ;
}
void F_206 ( struct V_19 * V_3 )
{
struct V_1 * V_2 ;
F_17 (dapm, &card->dapm_list, list) {
if ( V_2 != & V_3 -> V_2 ) {
F_205 ( V_2 ) ;
if ( V_2 -> V_77 == V_200 )
F_46 ( V_2 ,
V_198 ) ;
}
}
F_205 ( & V_3 -> V_2 ) ;
if ( V_3 -> V_2 . V_77 == V_200 )
F_46 ( & V_3 -> V_2 ,
V_198 ) ;
}
