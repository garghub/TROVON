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
struct V_1 * F_38 (
struct V_25 * V_26 )
{
return F_29 ( V_26 ) -> V_55 [ 0 ] -> V_2 ;
}
struct V_62 * F_39 ( struct V_25 * V_26 )
{
return F_40 ( F_38 ( V_26 ) ) ;
}
static void F_41 ( struct V_19 * V_3 )
{
struct V_13 * V_14 ;
F_2 ( & V_3 -> V_5 ) ;
memset ( & V_3 -> V_63 , 0 , sizeof( V_3 -> V_63 ) ) ;
F_17 (w, &card->widgets, list) {
V_14 -> V_64 = V_14 -> V_60 ;
V_14 -> V_65 = false ;
V_14 -> V_66 = - 1 ;
V_14 -> V_67 = - 1 ;
}
}
static const char * F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_68 )
return NULL ;
return V_2 -> V_68 -> V_69 ;
}
static int F_43 ( struct V_1 * V_2 , int V_39 ,
unsigned int * V_47 )
{
if ( ! V_2 -> V_68 )
return - V_70 ;
return F_44 ( V_2 -> V_68 , V_39 , V_47 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
int V_39 , unsigned int V_40 , unsigned int V_47 )
{
if ( ! V_2 -> V_68 )
return - V_70 ;
return F_46 ( V_2 -> V_68 , V_39 ,
V_40 , V_47 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
int V_39 , unsigned int V_40 , unsigned int V_47 )
{
if ( ! V_2 -> V_68 )
return - V_70 ;
return F_48 ( V_2 -> V_68 , V_39 , V_40 , V_47 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 )
F_50 ( V_2 -> V_68 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_71 V_72 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
int V_73 = 0 ;
F_52 ( V_3 , V_72 ) ;
if ( V_3 && V_3 -> V_74 )
V_73 = V_3 -> V_74 ( V_3 , V_2 , V_72 ) ;
if ( V_73 != 0 )
goto V_75;
if ( V_2 -> V_74 )
V_73 = V_2 -> V_74 ( V_2 , V_72 ) ;
else if ( ! V_3 || V_2 != & V_3 -> V_2 )
V_2 -> V_76 = V_72 ;
if ( V_73 != 0 )
goto V_75;
if ( V_3 && V_3 -> V_77 )
V_73 = V_3 -> V_77 ( V_3 , V_2 , V_72 ) ;
V_75:
F_53 ( V_3 , V_72 ) ;
return V_73 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_13 * V_78 , struct V_13 * V_79 ,
struct V_56 * V_57 , const char * V_80 ,
const struct V_81 * V_26 )
{
struct V_82 * V_83 = (struct V_82 * ) V_26 -> V_36 ;
unsigned int V_84 , V_85 ;
int V_86 ;
if ( V_83 -> V_39 != V_87 ) {
F_43 ( V_2 , V_83 -> V_39 , & V_84 ) ;
V_84 = ( V_84 >> V_83 -> V_88 ) & V_83 -> V_40 ;
V_85 = F_55 ( V_83 , V_84 ) ;
} else {
V_85 = 0 ;
}
for ( V_86 = 0 ; V_86 < V_83 -> V_89 ; V_86 ++ ) {
if ( ! ( strcmp ( V_80 , V_83 -> V_90 [ V_86 ] ) ) ) {
F_56 ( & V_57 -> V_91 , & V_2 -> V_3 -> V_32 ) ;
F_56 ( & V_57 -> V_92 , & V_79 -> V_93 ) ;
F_56 ( & V_57 -> V_94 , & V_78 -> V_95 ) ;
V_57 -> V_17 = ( char * ) V_83 -> V_90 [ V_86 ] ;
if ( V_86 == V_85 )
V_57 -> V_96 = 1 ;
else
V_57 -> V_96 = 0 ;
return 0 ;
}
}
return - V_97 ;
}
static void F_57 ( struct V_13 * V_14 ,
struct V_56 * V_98 , int V_86 )
{
struct V_29 * V_30 = (struct V_29 * )
V_14 -> V_99 [ V_86 ] . V_36 ;
unsigned int V_39 = V_30 -> V_39 ;
unsigned int V_42 = V_30 -> V_42 ;
unsigned int V_41 = V_30 -> V_41 ;
unsigned int V_40 = ( 1 << F_25 ( V_41 ) ) - 1 ;
unsigned int V_43 = V_30 -> V_43 ;
unsigned int V_84 ;
if ( V_39 != V_87 ) {
F_43 ( V_14 -> V_2 , V_39 , & V_84 ) ;
V_84 = ( V_84 >> V_42 ) & V_40 ;
if ( V_43 )
V_84 = V_41 - V_84 ;
V_98 -> V_96 = ! ! V_84 ;
} else {
V_98 -> V_96 = 0 ;
}
}
static int F_58 ( struct V_1 * V_2 ,
struct V_13 * V_78 , struct V_13 * V_79 ,
struct V_56 * V_57 , const char * V_80 )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < V_79 -> V_100 ; V_86 ++ ) {
if ( ! strcmp ( V_80 , V_79 -> V_99 [ V_86 ] . V_17 ) ) {
F_56 ( & V_57 -> V_91 , & V_2 -> V_3 -> V_32 ) ;
F_56 ( & V_57 -> V_92 , & V_79 -> V_93 ) ;
F_56 ( & V_57 -> V_94 , & V_78 -> V_95 ) ;
V_57 -> V_17 = V_79 -> V_99 [ V_86 ] . V_17 ;
F_57 ( V_79 , V_57 , V_86 ) ;
return 0 ;
}
}
return - V_97 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_13 * V_101 ,
const struct V_81 * V_102 ,
struct V_25 * * V_26 )
{
struct V_13 * V_14 ;
int V_86 ;
* V_26 = NULL ;
F_17 (w, &dapm->card->widgets, list) {
if ( V_14 == V_101 || V_14 -> V_2 != V_101 -> V_2 )
continue;
for ( V_86 = 0 ; V_86 < V_14 -> V_100 ; V_86 ++ ) {
if ( & V_14 -> V_99 [ V_86 ] == V_102 ) {
if ( V_14 -> V_103 )
* V_26 = V_14 -> V_103 [ V_86 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_60 ( struct V_13 * V_14 ,
int V_104 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_105 * V_3 = V_2 -> V_3 -> V_105 ;
const char * V_106 ;
T_3 V_107 ;
int V_108 ;
struct V_25 * V_26 ;
bool V_109 , V_110 ;
char * V_111 ;
const char * V_17 ;
int V_73 ;
V_106 = F_42 ( V_2 ) ;
if ( V_106 )
V_107 = strlen ( V_106 ) + 1 ;
else
V_107 = 0 ;
V_108 = F_59 ( V_2 , V_14 , & V_14 -> V_99 [ V_104 ] ,
& V_26 ) ;
if ( ! V_26 ) {
if ( V_108 ) {
V_109 = false ;
V_110 = true ;
} else {
switch ( V_14 -> V_20 ) {
case V_33 :
case V_34 :
V_109 = true ;
V_110 = true ;
break;
case V_35 :
V_109 = false ;
V_110 = true ;
break;
case V_112 :
V_109 = true ;
V_110 = false ;
break;
default:
return - V_113 ;
}
}
if ( V_109 && V_110 ) {
V_111 = F_61 ( V_12 , L_5 ,
V_14 -> V_17 + V_107 ,
V_14 -> V_99 [ V_104 ] . V_17 ) ;
if ( V_111 == NULL )
return - V_31 ;
V_17 = V_111 ;
} else if ( V_109 ) {
V_111 = NULL ;
V_17 = V_14 -> V_17 + V_107 ;
} else {
V_111 = NULL ;
V_17 = V_14 -> V_99 [ V_104 ] . V_17 ;
}
V_26 = F_62 ( & V_14 -> V_99 [ V_104 ] , NULL , V_17 ,
V_106 ) ;
F_9 ( V_111 ) ;
if ( ! V_26 )
return - V_31 ;
V_26 -> V_114 = F_27 ;
V_73 = F_21 ( V_14 , V_26 ) ;
if ( V_73 ) {
F_63 ( V_26 ) ;
return V_73 ;
}
V_73 = F_64 ( V_3 , V_26 ) ;
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
V_14 -> V_103 [ V_104 ] = V_26 ;
return 0 ;
}
static int F_65 ( struct V_13 * V_14 )
{
int V_86 , V_73 ;
struct V_56 * V_57 ;
for ( V_86 = 0 ; V_86 < V_14 -> V_100 ; V_86 ++ ) {
F_17 (path, &w->sources, list_sink) {
if ( V_57 -> V_17 != ( char * ) V_14 -> V_99 [ V_86 ] . V_17 )
continue;
if ( V_14 -> V_103 [ V_86 ] ) {
F_32 ( V_14 -> V_103 [ V_86 ] , V_57 ) ;
continue;
}
V_73 = F_60 ( V_14 , V_86 ) ;
if ( V_73 < 0 )
return V_73 ;
F_32 ( V_14 -> V_103 [ V_86 ] , V_57 ) ;
}
}
return 0 ;
}
static int F_66 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_56 * V_57 ;
int V_73 ;
if ( V_14 -> V_100 != 1 ) {
F_23 ( V_2 -> V_8 ,
L_7 ,
V_14 -> V_17 ) ;
return - V_113 ;
}
if ( F_11 ( & V_14 -> V_93 ) ) {
F_23 ( V_2 -> V_8 , L_8 , V_14 -> V_17 ) ;
return - V_113 ;
}
V_73 = F_60 ( V_14 , 0 ) ;
if ( V_73 < 0 )
return V_73 ;
F_17 (path, &w->sources, list_sink)
F_32 ( V_14 -> V_103 [ 0 ] , V_57 ) ;
return 0 ;
}
static int F_67 ( struct V_13 * V_14 )
{
if ( V_14 -> V_100 )
F_23 ( V_14 -> V_2 -> V_8 ,
L_9 , V_14 -> V_17 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_61 * V_115 )
{
struct V_56 * V_98 ;
F_17 (p, sink, list_source) {
if ( V_98 -> V_116 ) {
V_98 -> V_116 = 0 ;
F_68 ( V_2 , & V_98 -> V_115 -> V_95 ) ;
}
}
}
static void F_69 ( struct V_1 * V_2 ,
struct V_61 * V_59 )
{
struct V_56 * V_98 ;
F_17 (p, source, list_sink) {
if ( V_98 -> V_116 ) {
V_98 -> V_116 = 0 ;
F_69 ( V_2 , & V_98 -> V_59 -> V_93 ) ;
}
}
}
static int F_70 ( struct V_13 * V_24 )
{
int V_72 = F_71 ( V_24 -> V_2 -> V_3 -> V_105 ) ;
switch ( V_72 ) {
case V_117 :
case V_118 :
if ( V_24 -> V_119 )
F_72 ( V_24 -> V_2 -> V_8 , L_10 ,
V_24 -> V_17 ) ;
return V_24 -> V_119 ;
default:
return 1 ;
}
}
static int F_73 ( struct V_51 * * V_91 ,
struct V_13 * V_14 )
{
struct V_51 * V_50 ;
int V_120 , V_121 , V_86 ;
if ( * V_91 == NULL )
return - V_113 ;
V_50 = * V_91 ;
for ( V_86 = 0 ; V_86 < V_50 -> V_54 ; V_86 ++ ) {
if ( V_50 -> V_55 [ V_86 ] == V_14 )
return 0 ;
}
V_121 = V_50 -> V_54 + 1 ;
V_120 = sizeof( struct V_51 ) +
V_121 * sizeof( struct V_13 * ) ;
* V_91 = F_31 ( V_50 , V_120 , V_12 ) ;
if ( * V_91 == NULL ) {
F_23 ( V_14 -> V_2 -> V_8 , L_11 ,
V_14 -> V_17 ) ;
return - V_31 ;
}
V_50 = * V_91 ;
F_72 ( V_14 -> V_2 -> V_8 , L_12 ,
V_14 -> V_17 , V_50 -> V_54 ) ;
V_50 -> V_55 [ V_50 -> V_54 ] = V_14 ;
V_50 -> V_54 ++ ;
return 1 ;
}
static int F_74 ( struct V_13 * V_24 ,
struct V_51 * * V_91 )
{
struct V_56 * V_57 ;
int V_122 = 0 ;
if ( V_24 -> V_67 >= 0 )
return V_24 -> V_67 ;
F_75 ( V_24 , V_123 ) ;
switch ( V_24 -> V_20 ) {
case V_124 :
case V_125 :
case V_126 :
case V_46 :
return 0 ;
default:
break;
}
switch ( V_24 -> V_20 ) {
case V_127 :
case V_128 :
case V_129 :
if ( V_24 -> V_130 ) {
V_24 -> V_67 = F_70 ( V_24 ) ;
return V_24 -> V_67 ;
}
default:
break;
}
if ( V_24 -> V_131 ) {
if ( V_24 -> V_20 == V_22 && ! V_24 -> V_132 ) {
V_24 -> V_67 = F_70 ( V_24 ) ;
return V_24 -> V_67 ;
}
if ( V_24 -> V_20 == V_133 ||
V_24 -> V_20 == V_134 ||
( V_24 -> V_20 == V_135 &&
! F_11 ( & V_24 -> V_93 ) ) ) {
V_24 -> V_67 = F_70 ( V_24 ) ;
return V_24 -> V_67 ;
}
}
F_17 (path, &widget->sinks, list_source) {
F_75 ( V_24 , V_136 ) ;
if ( V_57 -> V_137 )
continue;
if ( V_57 -> V_138 )
return 1 ;
if ( V_57 -> V_116 )
continue;
F_76 ( V_24 , V_57 ) ;
if ( V_57 -> V_115 && V_57 -> V_96 ) {
V_57 -> V_116 = 1 ;
V_57 -> V_138 = 1 ;
if ( V_91 ) {
int V_139 ;
V_139 = F_73 ( V_91 , V_57 -> V_115 ) ;
if ( V_139 < 0 ) {
F_23 ( V_24 -> V_2 -> V_8 ,
L_13 ,
V_24 -> V_17 ) ;
V_57 -> V_138 = 0 ;
return V_122 ;
}
}
V_122 += F_74 ( V_57 -> V_115 , V_91 ) ;
V_57 -> V_138 = 0 ;
}
}
V_24 -> V_67 = V_122 ;
return V_122 ;
}
static int F_77 ( struct V_13 * V_24 ,
struct V_51 * * V_91 )
{
struct V_56 * V_57 ;
int V_122 = 0 ;
if ( V_24 -> V_66 >= 0 )
return V_24 -> V_66 ;
F_75 ( V_24 , V_123 ) ;
switch ( V_24 -> V_20 ) {
case V_124 :
case V_125 :
case V_126 :
case V_46 :
return 0 ;
default:
break;
}
switch ( V_24 -> V_20 ) {
case V_140 :
case V_141 :
case V_142 :
if ( V_24 -> V_130 ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
default:
break;
}
if ( V_24 -> V_131 ) {
if ( V_24 -> V_20 == V_21 && ! V_24 -> V_132 ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
if ( V_24 -> V_20 == V_143 ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
if ( V_24 -> V_20 == V_144 ||
( V_24 -> V_20 == V_135 &&
! F_11 ( & V_24 -> V_95 ) ) ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
if ( V_24 -> V_20 == V_145 ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
}
F_17 (path, &widget->sources, list_sink) {
F_75 ( V_24 , V_136 ) ;
if ( V_57 -> V_137 )
continue;
if ( V_57 -> V_138 )
return 1 ;
if ( V_57 -> V_116 )
continue;
F_78 ( V_24 , V_57 ) ;
if ( V_57 -> V_59 && V_57 -> V_96 ) {
V_57 -> V_116 = 1 ;
V_57 -> V_138 = 1 ;
if ( V_91 ) {
int V_139 ;
V_139 = F_73 ( V_91 , V_57 -> V_59 ) ;
if ( V_139 < 0 ) {
F_23 ( V_24 -> V_2 -> V_8 ,
L_13 ,
V_24 -> V_17 ) ;
V_57 -> V_138 = 0 ;
return V_122 ;
}
}
V_122 += F_77 ( V_57 -> V_59 , V_91 ) ;
V_57 -> V_138 = 0 ;
}
}
V_24 -> V_66 = V_122 ;
return V_122 ;
}
int F_79 ( struct V_146 * V_147 , int V_148 ,
struct V_51 * * V_91 )
{
struct V_19 * V_3 = V_147 -> V_3 ;
int V_32 ;
F_80 ( & V_3 -> V_5 , V_149 ) ;
F_41 ( V_3 ) ;
if ( V_148 == V_150 ) {
V_32 = F_74 ( V_147 -> V_151 , V_91 ) ;
F_68 ( & V_3 -> V_2 ,
& V_147 -> V_151 -> V_95 ) ;
} else {
V_32 = F_77 ( V_147 -> V_152 , V_91 ) ;
F_69 ( & V_3 -> V_2 ,
& V_147 -> V_152 -> V_93 ) ;
}
F_81 ( V_32 , V_148 ) ;
F_18 ( & V_3 -> V_5 ) ;
return V_32 ;
}
int F_82 ( struct V_13 * V_14 ,
struct V_25 * V_26 , int V_153 )
{
int V_73 ;
F_49 ( V_14 -> V_2 ) ;
if ( F_83 ( V_153 ) ) {
if ( V_14 -> V_45 & V_154 ) {
V_73 = F_84 ( V_14 -> V_155 , false ) ;
if ( V_73 != 0 )
F_85 ( V_14 -> V_2 -> V_8 ,
L_14 ,
V_14 -> V_17 , V_73 ) ;
}
return F_86 ( V_14 -> V_155 ) ;
} else {
if ( V_14 -> V_45 & V_154 ) {
V_73 = F_84 ( V_14 -> V_155 , true ) ;
if ( V_73 != 0 )
F_85 ( V_14 -> V_2 -> V_8 ,
L_15 ,
V_14 -> V_17 , V_73 ) ;
}
return F_87 ( V_14 -> V_155 , V_14 -> V_42 ) ;
}
}
int F_88 ( struct V_13 * V_14 ,
struct V_25 * V_26 , int V_153 )
{
if ( ! V_14 -> V_156 )
return - V_70 ;
F_49 ( V_14 -> V_2 ) ;
#ifdef F_89
if ( F_83 ( V_153 ) ) {
return F_90 ( V_14 -> V_156 ) ;
} else {
F_91 ( V_14 -> V_156 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_92 ( struct V_13 * V_14 )
{
if ( V_14 -> V_65 )
return V_14 -> V_64 ;
if ( V_14 -> V_157 )
V_14 -> V_64 = 1 ;
else
V_14 -> V_64 = V_14 -> V_158 ( V_14 ) ;
V_14 -> V_65 = true ;
return V_14 -> V_64 ;
}
static int F_93 ( struct V_13 * V_14 )
{
int V_159 , V_75 ;
F_75 ( V_14 , V_160 ) ;
V_159 = F_77 ( V_14 , NULL ) ;
F_69 ( V_14 -> V_2 , & V_14 -> V_93 ) ;
V_75 = F_74 ( V_14 , NULL ) ;
F_68 ( V_14 -> V_2 , & V_14 -> V_95 ) ;
return V_75 != 0 && V_159 != 0 ;
}
static int F_94 ( struct V_13 * V_14 )
{
int V_159 ;
F_75 ( V_14 , V_160 ) ;
if ( V_14 -> V_130 ) {
V_159 = F_77 ( V_14 , NULL ) ;
F_69 ( V_14 -> V_2 , & V_14 -> V_93 ) ;
return V_159 != 0 ;
} else {
return F_93 ( V_14 ) ;
}
}
static int F_95 ( struct V_13 * V_14 )
{
int V_75 ;
F_75 ( V_14 , V_160 ) ;
if ( V_14 -> V_130 ) {
V_75 = F_74 ( V_14 , NULL ) ;
F_68 ( V_14 -> V_2 , & V_14 -> V_95 ) ;
return V_75 != 0 ;
} else {
return F_93 ( V_14 ) ;
}
}
static int F_96 ( struct V_13 * V_14 )
{
struct V_56 * V_57 ;
F_75 ( V_14 , V_160 ) ;
F_17 (path, &w->sinks, list_source) {
F_75 ( V_14 , V_136 ) ;
if ( V_57 -> V_137 )
continue;
if ( V_57 -> V_131 &&
! V_57 -> V_131 ( V_57 -> V_59 , V_57 -> V_115 ) )
continue;
if ( ! V_57 -> V_115 )
continue;
if ( F_92 ( V_57 -> V_115 ) )
return 1 ;
}
return 0 ;
}
static int F_97 ( struct V_13 * V_14 )
{
return 1 ;
}
static int F_98 ( struct V_13 * V_161 ,
struct V_13 * V_162 ,
bool V_163 )
{
int * V_164 ;
if ( V_163 )
V_164 = V_165 ;
else
V_164 = V_166 ;
if ( V_164 [ V_161 -> V_20 ] != V_164 [ V_162 -> V_20 ] )
return V_164 [ V_161 -> V_20 ] - V_164 [ V_162 -> V_20 ] ;
if ( V_161 -> V_167 != V_162 -> V_167 ) {
if ( V_163 )
return V_161 -> V_167 - V_162 -> V_167 ;
else
return V_162 -> V_167 - V_161 -> V_167 ;
}
if ( V_161 -> V_39 != V_162 -> V_39 )
return V_161 -> V_39 - V_162 -> V_39 ;
if ( V_161 -> V_2 != V_162 -> V_2 )
return ( unsigned long ) V_161 -> V_2 - ( unsigned long ) V_162 -> V_2 ;
return 0 ;
}
static void F_99 ( struct V_13 * V_168 ,
struct V_61 * V_91 ,
bool V_163 )
{
struct V_13 * V_14 ;
F_17 (w, list, power_list)
if ( F_98 ( V_168 , V_14 , V_163 ) < 0 ) {
F_14 ( & V_168 -> V_169 , & V_14 -> V_169 ) ;
return;
}
F_14 ( & V_168 -> V_169 , V_91 ) ;
}
static void F_100 ( struct V_19 * V_3 ,
struct V_13 * V_14 , int V_153 )
{
const char * V_170 ;
int V_60 , V_73 ;
switch ( V_153 ) {
case V_171 :
V_170 = L_16 ;
V_60 = 1 ;
break;
case V_172 :
V_170 = L_17 ;
V_60 = 1 ;
break;
case V_173 :
V_170 = L_18 ;
V_60 = 0 ;
break;
case V_174 :
V_170 = L_19 ;
V_60 = 0 ;
break;
case V_175 :
V_170 = L_20 ;
V_60 = 1 ;
break;
case V_176 :
V_170 = L_21 ;
V_60 = 0 ;
break;
default:
F_101 ( 1 , L_22 , V_153 ) ;
return;
}
if ( V_14 -> V_64 != V_60 )
return;
if ( V_14 -> V_153 && ( V_14 -> V_177 & V_153 ) ) {
F_6 ( V_14 -> V_2 -> V_8 , V_3 -> V_6 , L_23 ,
V_14 -> V_17 , V_170 ) ;
F_49 ( V_14 -> V_2 ) ;
F_102 ( V_14 , V_153 ) ;
V_73 = V_14 -> V_153 ( V_14 , NULL , V_153 ) ;
F_103 ( V_14 , V_153 ) ;
if ( V_73 < 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_24 ,
V_170 , V_14 -> V_17 , V_73 ) ;
}
}
static void F_104 ( struct V_19 * V_3 ,
struct V_61 * V_178 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
int V_39 ;
unsigned int V_47 = 0 ;
unsigned int V_40 = 0 ;
V_14 = F_105 ( V_178 , struct V_13 , V_169 ) ;
V_39 = V_14 -> V_39 ;
V_2 = V_14 -> V_2 ;
F_17 (w, pending, power_list) {
F_106 ( V_39 != V_14 -> V_39 || V_2 != V_14 -> V_2 ) ;
V_14 -> V_60 = V_14 -> V_64 ;
V_40 |= V_14 -> V_40 << V_14 -> V_42 ;
if ( V_14 -> V_60 )
V_47 |= V_14 -> V_45 << V_14 -> V_42 ;
else
V_47 |= V_14 -> V_44 << V_14 -> V_42 ;
F_6 ( V_2 -> V_8 , V_3 -> V_6 ,
L_25 ,
V_14 -> V_17 , V_39 , V_47 , V_40 ) ;
F_100 ( V_3 , V_14 , V_171 ) ;
F_100 ( V_3 , V_14 , V_173 ) ;
}
if ( V_39 >= 0 ) {
F_6 ( V_2 -> V_8 , V_3 -> V_6 ,
L_26 ,
V_47 , V_40 , V_39 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_45 ( V_2 , V_39 , V_40 , V_47 ) ;
}
F_17 (w, pending, power_list) {
F_100 ( V_3 , V_14 , V_172 ) ;
F_100 ( V_3 , V_14 , V_174 ) ;
}
}
static void F_107 ( struct V_19 * V_3 ,
struct V_61 * V_91 , int V_153 , bool V_163 )
{
struct V_13 * V_14 , * V_53 ;
struct V_1 * V_179 ;
F_108 ( V_178 ) ;
int V_180 = - 1 ;
int V_181 = - 1 ;
int V_182 = V_87 ;
struct V_1 * V_183 = NULL ;
int V_73 , V_86 ;
int * V_164 ;
if ( V_163 )
V_164 = V_165 ;
else
V_164 = V_166 ;
F_109 (w, n, list, power_list) {
V_73 = 0 ;
if ( V_164 [ V_14 -> V_20 ] != V_180 || V_14 -> V_39 != V_182 ||
V_14 -> V_2 != V_183 || V_14 -> V_167 != V_181 ) {
if ( ! F_11 ( & V_178 ) )
F_104 ( V_3 , & V_178 ) ;
if ( V_183 && V_183 -> V_184 ) {
for ( V_86 = 0 ; V_86 < F_110 ( V_165 ) ; V_86 ++ )
if ( V_164 [ V_86 ] == V_180 )
V_183 -> V_184 ( V_183 ,
V_86 ,
V_181 ) ;
}
if ( V_183 && V_14 -> V_2 != V_183 )
F_49 ( V_183 ) ;
F_24 ( & V_178 ) ;
V_180 = - 1 ;
V_181 = V_185 ;
V_182 = V_87 ;
V_183 = NULL ;
}
switch ( V_14 -> V_20 ) {
case V_186 :
if ( ! V_14 -> V_153 )
F_111 ( V_14 , V_53 , V_91 ,
V_169 ) ;
if ( V_153 == V_187 )
V_73 = V_14 -> V_153 ( V_14 ,
NULL , V_171 ) ;
else if ( V_153 == V_188 )
V_73 = V_14 -> V_153 ( V_14 ,
NULL , V_173 ) ;
break;
case V_189 :
if ( ! V_14 -> V_153 )
F_111 ( V_14 , V_53 , V_91 ,
V_169 ) ;
if ( V_153 == V_187 )
V_73 = V_14 -> V_153 ( V_14 ,
NULL , V_172 ) ;
else if ( V_153 == V_188 )
V_73 = V_14 -> V_153 ( V_14 ,
NULL , V_174 ) ;
break;
default:
V_180 = V_164 [ V_14 -> V_20 ] ;
V_181 = V_14 -> V_167 ;
V_182 = V_14 -> V_39 ;
V_183 = V_14 -> V_2 ;
F_112 ( & V_14 -> V_169 , & V_178 ) ;
break;
}
if ( V_73 < 0 )
F_23 ( V_14 -> V_2 -> V_8 ,
L_27 , V_73 ) ;
}
if ( ! F_11 ( & V_178 ) )
F_104 ( V_3 , & V_178 ) ;
if ( V_183 && V_183 -> V_184 ) {
for ( V_86 = 0 ; V_86 < F_110 ( V_165 ) ; V_86 ++ )
if ( V_164 [ V_86 ] == V_180 )
V_183 -> V_184 ( V_183 ,
V_86 , V_181 ) ;
}
F_17 (d, &card->dapm_list, list) {
F_49 ( V_179 ) ;
}
}
static void F_113 ( struct V_19 * V_3 )
{
struct V_190 * V_191 = V_3 -> V_191 ;
struct V_51 * V_50 ;
struct V_13 * V_14 = NULL ;
unsigned int V_192 ;
int V_73 ;
if ( ! V_191 || ! F_34 ( V_191 -> V_26 ) )
return;
V_50 = F_29 ( V_191 -> V_26 ) ;
for ( V_192 = 0 ; V_192 < V_50 -> V_54 ; V_192 ++ ) {
V_14 = V_50 -> V_55 [ V_192 ] ;
if ( V_14 -> V_153 && ( V_14 -> V_177 & V_193 ) ) {
V_73 = V_14 -> V_153 ( V_14 , V_191 -> V_26 , V_193 ) ;
if ( V_73 != 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_28 ,
V_14 -> V_17 , V_73 ) ;
}
}
if ( ! V_14 )
return;
V_73 = F_45 ( V_14 -> V_2 , V_191 -> V_39 , V_191 -> V_40 ,
V_191 -> V_84 ) ;
if ( V_73 < 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_29 ,
V_14 -> V_17 , V_73 ) ;
for ( V_192 = 0 ; V_192 < V_50 -> V_54 ; V_192 ++ ) {
V_14 = V_50 -> V_55 [ V_192 ] ;
if ( V_14 -> V_153 && ( V_14 -> V_177 & V_194 ) ) {
V_73 = V_14 -> V_153 ( V_14 , V_191 -> V_26 , V_194 ) ;
if ( V_73 != 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_30 ,
V_14 -> V_17 , V_73 ) ;
}
}
}
static void F_114 ( void * V_28 , T_4 V_195 )
{
struct V_1 * V_179 = V_28 ;
int V_73 ;
if ( V_179 -> V_76 == V_196 &&
V_179 -> V_197 != V_196 ) {
if ( V_179 -> V_8 )
F_115 ( V_179 -> V_8 ) ;
V_73 = F_51 ( V_179 , V_198 ) ;
if ( V_73 != 0 )
F_23 ( V_179 -> V_8 ,
L_31 , V_73 ) ;
}
if ( ( V_179 -> V_197 == V_199 &&
V_179 -> V_76 != V_199 ) ||
( V_179 -> V_197 != V_199 &&
V_179 -> V_76 == V_199 ) ) {
V_73 = F_51 ( V_179 , V_200 ) ;
if ( V_73 != 0 )
F_23 ( V_179 -> V_8 ,
L_32 , V_73 ) ;
}
}
static void F_116 ( void * V_28 , T_4 V_195 )
{
struct V_1 * V_179 = V_28 ;
int V_73 ;
if ( V_179 -> V_76 == V_200 &&
( V_179 -> V_197 == V_198 ||
V_179 -> V_197 == V_196 ) ) {
V_73 = F_51 ( V_179 , V_198 ) ;
if ( V_73 != 0 )
F_23 ( V_179 -> V_8 , L_33 ,
V_73 ) ;
}
if ( V_179 -> V_76 == V_198 &&
V_179 -> V_197 == V_196 ) {
V_73 = F_51 ( V_179 , V_196 ) ;
if ( V_73 != 0 )
F_23 ( V_179 -> V_8 , L_34 ,
V_73 ) ;
if ( V_179 -> V_8 )
F_117 ( V_179 -> V_8 ) ;
}
if ( V_179 -> V_76 == V_200 &&
V_179 -> V_197 == V_199 ) {
V_73 = F_51 ( V_179 , V_199 ) ;
if ( V_73 != 0 )
F_23 ( V_179 -> V_8 , L_35 ,
V_73 ) ;
}
}
static void F_118 ( struct V_13 * V_201 ,
bool V_60 , bool V_96 )
{
if ( ! V_96 )
return;
if ( V_60 != V_201 -> V_60 )
F_12 ( V_201 , L_36 ) ;
}
static void F_119 ( struct V_13 * V_14 , bool V_60 ,
struct V_61 * V_202 ,
struct V_61 * V_203 )
{
struct V_56 * V_57 ;
if ( V_14 -> V_60 == V_60 )
return;
F_120 ( V_14 , V_60 ) ;
F_17 (path, &w->sources, list_sink) {
if ( V_57 -> V_59 ) {
F_118 ( V_57 -> V_59 , V_60 ,
V_57 -> V_96 ) ;
}
}
switch ( V_14 -> V_20 ) {
case V_124 :
case V_125 :
case V_126 :
case V_46 :
break;
default:
F_17 (path, &w->sinks, list_source) {
if ( V_57 -> V_115 ) {
F_118 ( V_57 -> V_115 , V_60 ,
V_57 -> V_96 ) ;
}
}
break;
}
if ( V_60 )
F_99 ( V_14 , V_202 , true ) ;
else
F_99 ( V_14 , V_203 , false ) ;
}
static void F_121 ( struct V_13 * V_14 ,
struct V_61 * V_202 ,
struct V_61 * V_203 )
{
int V_60 ;
switch ( V_14 -> V_20 ) {
case V_186 :
F_99 ( V_14 , V_203 , false ) ;
break;
case V_189 :
F_99 ( V_14 , V_202 , true ) ;
break;
default:
V_60 = F_92 ( V_14 ) ;
F_119 ( V_14 , V_60 , V_202 , V_203 ) ;
break;
}
}
static int F_122 ( struct V_19 * V_3 , int V_153 )
{
struct V_13 * V_14 ;
struct V_1 * V_179 ;
F_108 ( V_202 ) ;
F_108 ( V_203 ) ;
F_123 ( V_204 ) ;
enum V_71 V_205 ;
F_2 ( & V_3 -> V_5 ) ;
F_124 ( V_3 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_179 -> V_206 )
V_179 -> V_197 = V_196 ;
else
V_179 -> V_197 = V_198 ;
}
F_41 ( V_3 ) ;
F_17 (w, &card->dapm_dirty, dirty) {
F_121 ( V_14 , & V_202 , & V_203 ) ;
}
F_17 (w, &card->widgets, list) {
switch ( V_14 -> V_20 ) {
case V_186 :
case V_189 :
break;
default:
F_125 ( & V_14 -> V_15 ) ;
break;
}
if ( V_14 -> V_64 ) {
V_179 = V_14 -> V_2 ;
switch ( V_14 -> V_20 ) {
case V_145 :
case V_143 :
break;
case V_124 :
case V_125 :
case V_126 :
case V_207 :
if ( V_179 -> V_197 < V_198 )
V_179 -> V_197 = V_198 ;
break;
default:
V_179 -> V_197 = V_199 ;
break;
}
}
}
V_205 = V_196 ;
F_17 (d, &card->dapm_list, list)
if ( V_179 -> V_197 > V_205 )
V_205 = V_179 -> V_197 ;
F_17 (d, &card->dapm_list, list)
if ( ! V_179 -> V_206 )
V_179 -> V_197 = V_205 ;
F_126 ( V_3 ) ;
F_114 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_179 != & V_3 -> V_2 )
F_127 ( F_114 , V_179 ,
& V_204 ) ;
}
F_128 ( & V_204 ) ;
F_17 (w, &down_list, power_list) {
F_100 ( V_3 , V_14 , V_176 ) ;
}
F_17 (w, &up_list, power_list) {
F_100 ( V_3 , V_14 , V_175 ) ;
}
F_107 ( V_3 , & V_203 , V_153 , false ) ;
F_113 ( V_3 ) ;
F_107 ( V_3 , & V_202 , V_153 , true ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_179 != & V_3 -> V_2 )
F_127 ( F_116 , V_179 ,
& V_204 ) ;
}
F_128 ( & V_204 ) ;
F_116 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_179 -> V_208 )
V_179 -> V_208 ( V_179 , V_153 ) ;
}
F_6 ( V_3 -> V_8 , V_3 -> V_6 ,
L_37 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_129 ( V_3 ) ;
return 0 ;
}
static T_5 F_130 ( struct V_209 * V_209 ,
char T_6 * V_210 ,
T_3 V_211 , T_7 * V_212 )
{
struct V_13 * V_14 = V_209 -> V_48 ;
char * V_10 ;
int V_159 , V_75 ;
T_5 V_73 ;
struct V_56 * V_98 = NULL ;
V_10 = F_7 ( V_11 , V_12 ) ;
if ( ! V_10 )
return - V_31 ;
V_159 = F_77 ( V_14 , NULL ) ;
F_69 ( V_14 -> V_2 , & V_14 -> V_93 ) ;
V_75 = F_74 ( V_14 , NULL ) ;
F_68 ( V_14 -> V_2 , & V_14 -> V_95 ) ;
V_73 = snprintf ( V_10 , V_11 , L_38 ,
V_14 -> V_17 , V_14 -> V_60 ? L_39 : L_40 ,
V_14 -> V_157 ? L_41 : L_42 , V_159 , V_75 ) ;
if ( V_14 -> V_39 >= 0 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 ,
L_43 ,
V_14 -> V_39 , V_14 -> V_39 , V_14 -> V_40 << V_14 -> V_42 ) ;
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 , L_44 ) ;
if ( V_14 -> V_213 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 , L_45 ,
V_14 -> V_213 ,
V_14 -> V_130 ? L_46 : L_47 ) ;
F_17 (p, &w->sources, list_sink) {
if ( V_98 -> V_131 && ! V_98 -> V_131 ( V_14 , V_98 -> V_59 ) )
continue;
if ( V_98 -> V_96 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 ,
L_48 ,
V_98 -> V_17 ? V_98 -> V_17 : L_49 ,
V_98 -> V_59 -> V_17 ) ;
}
F_17 (p, &w->sinks, list_source) {
if ( V_98 -> V_131 && ! V_98 -> V_131 ( V_14 , V_98 -> V_115 ) )
continue;
if ( V_98 -> V_96 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 ,
L_50 ,
V_98 -> V_17 ? V_98 -> V_17 : L_49 ,
V_98 -> V_115 -> V_17 ) ;
}
V_73 = F_131 ( V_210 , V_211 , V_212 , V_10 , V_73 ) ;
F_9 ( V_10 ) ;
return V_73 ;
}
static T_5 F_132 ( struct V_209 * V_209 , char T_6 * V_210 ,
T_3 V_211 , T_7 * V_212 )
{
struct V_1 * V_2 = V_209 -> V_48 ;
char * V_72 ;
switch ( V_2 -> V_76 ) {
case V_199 :
V_72 = L_51 ;
break;
case V_200 :
V_72 = L_52 ;
break;
case V_198 :
V_72 = L_53 ;
break;
case V_196 :
V_72 = L_54 ;
break;
default:
F_101 ( 1 , L_55 , V_2 -> V_76 ) ;
V_72 = L_56 ;
break;
}
return F_131 ( V_210 , V_211 , V_212 , V_72 ,
strlen ( V_72 ) ) ;
}
void F_133 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
struct V_214 * V_179 ;
V_2 -> V_216 = F_134 ( L_57 , V_215 ) ;
if ( ! V_2 -> V_216 ) {
F_85 ( V_2 -> V_8 ,
L_58 ) ;
return;
}
V_179 = F_135 ( L_59 , 0444 ,
V_2 -> V_216 , V_2 ,
& V_217 ) ;
if ( ! V_179 )
F_85 ( V_2 -> V_8 ,
L_60 ) ;
}
static void F_136 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_214 * V_179 ;
if ( ! V_2 -> V_216 || ! V_14 -> V_17 )
return;
V_179 = F_135 ( V_14 -> V_17 , 0444 ,
V_2 -> V_216 , V_14 ,
& V_218 ) ;
if ( ! V_179 )
F_85 ( V_14 -> V_2 -> V_8 ,
L_61 ,
V_14 -> V_17 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
F_138 ( V_2 -> V_216 ) ;
}
void F_133 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
}
static inline void F_136 ( struct V_13 * V_14 )
{
}
static inline void F_137 ( struct V_1 * V_2 )
{
}
static int F_139 ( struct V_19 * V_3 ,
struct V_25 * V_26 , int V_219 , struct V_82 * V_83 )
{
struct V_56 * V_57 ;
int V_220 = 0 ;
F_2 ( & V_3 -> V_5 ) ;
F_140 (path, kcontrol) {
if ( ! V_57 -> V_17 || ! V_83 -> V_90 [ V_219 ] )
continue;
V_220 = 1 ;
if ( ! ( strcmp ( V_57 -> V_17 , V_83 -> V_90 [ V_219 ] ) ) ) {
V_57 -> V_96 = 1 ;
F_12 ( V_57 -> V_59 , L_62 ) ;
} else {
if ( V_57 -> V_96 )
F_12 ( V_57 -> V_59 ,
L_63 ) ;
V_57 -> V_96 = 0 ;
}
F_12 ( V_57 -> V_115 , L_64 ) ;
}
if ( V_220 )
F_122 ( V_3 , V_221 ) ;
return V_220 ;
}
int F_141 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_219 , struct V_82 * V_83 ,
struct V_190 * V_191 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
int V_73 ;
F_80 ( & V_3 -> V_5 , V_149 ) ;
V_3 -> V_191 = V_191 ;
V_73 = F_139 ( V_3 , V_26 , V_219 , V_83 ) ;
V_3 -> V_191 = NULL ;
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_142 ( V_3 ) ;
return V_73 ;
}
static int F_143 ( struct V_19 * V_3 ,
struct V_25 * V_26 , int V_96 )
{
struct V_56 * V_57 ;
int V_220 = 0 ;
F_2 ( & V_3 -> V_5 ) ;
F_140 (path, kcontrol) {
V_220 = 1 ;
V_57 -> V_96 = V_96 ;
F_12 ( V_57 -> V_59 , L_65 ) ;
F_12 ( V_57 -> V_115 , L_66 ) ;
}
if ( V_220 )
F_122 ( V_3 , V_221 ) ;
return V_220 ;
}
int F_144 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_96 ,
struct V_190 * V_191 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
int V_73 ;
F_80 ( & V_3 -> V_5 , V_149 ) ;
V_3 -> V_191 = V_191 ;
V_73 = F_143 ( V_3 , V_26 , V_96 ) ;
V_3 -> V_191 = NULL ;
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_142 ( V_3 ) ;
return V_73 ;
}
static T_5 F_145 ( struct V_62 * V_222 , char * V_10 )
{
struct V_13 * V_14 ;
int V_211 = 0 ;
char * V_223 = L_67 ;
F_17 (w, &codec->component.card->widgets, list) {
if ( V_14 -> V_2 != & V_222 -> V_2 )
continue;
switch ( V_14 -> V_20 ) {
case V_133 :
case V_144 :
case V_134 :
case V_135 :
case V_207 :
case V_140 :
case V_127 :
case V_224 :
case V_225 :
case V_34 :
case V_35 :
case V_124 :
case V_125 :
case V_126 :
if ( V_14 -> V_17 )
V_211 += sprintf ( V_10 + V_211 , L_68 ,
V_14 -> V_17 , V_14 -> V_60 ? L_39 : L_40 ) ;
break;
default:
break;
}
}
switch ( V_222 -> V_2 . V_76 ) {
case V_199 :
V_223 = L_39 ;
break;
case V_200 :
V_223 = L_69 ;
break;
case V_198 :
V_223 = L_70 ;
break;
case V_196 :
V_223 = L_40 ;
break;
}
V_211 += sprintf ( V_10 + V_211 , L_71 , V_223 ) ;
return V_211 ;
}
static T_5 F_146 ( struct V_7 * V_8 ,
struct V_226 * V_227 , char * V_10 )
{
struct V_228 * V_229 = F_147 ( V_8 ) ;
int V_86 , V_211 = 0 ;
for ( V_86 = 0 ; V_86 < V_229 -> V_230 ; V_86 ++ ) {
struct V_62 * V_222 = V_229 -> V_231 [ V_86 ] -> V_222 ;
V_211 += F_145 ( V_222 , V_10 + V_211 ) ;
}
return V_211 ;
}
int F_148 ( struct V_7 * V_8 )
{
return F_149 ( V_8 , & V_232 ) ;
}
static void F_150 ( struct V_7 * V_8 )
{
F_151 ( V_8 , & V_232 ) ;
}
static void F_152 ( struct V_56 * V_57 )
{
F_153 ( & V_57 -> V_92 ) ;
F_153 ( & V_57 -> V_94 ) ;
F_153 ( & V_57 -> V_58 ) ;
F_153 ( & V_57 -> V_91 ) ;
F_9 ( V_57 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_233 ;
struct V_56 * V_98 , * V_234 ;
F_109 (w, next_w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
F_153 ( & V_14 -> V_91 ) ;
F_109 (p, next_p, &w->sources, list_sink)
F_152 ( V_98 ) ;
F_109 (p, next_p, &w->sinks, list_source)
F_152 ( V_98 ) ;
F_9 ( V_14 -> V_103 ) ;
F_9 ( V_14 -> V_17 ) ;
F_9 ( V_14 ) ;
}
}
static struct V_13 * F_155 (
struct V_1 * V_2 , const char * V_235 ,
bool V_236 )
{
struct V_13 * V_14 ;
struct V_13 * V_237 = NULL ;
F_17 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_14 -> V_17 , V_235 ) ) {
if ( V_14 -> V_2 == V_2 )
return V_14 ;
else
V_237 = V_14 ;
}
}
if ( V_236 )
return V_237 ;
return NULL ;
}
static int F_156 ( struct V_1 * V_2 ,
const char * V_235 , int V_238 )
{
struct V_13 * V_14 = F_155 ( V_2 , V_235 , true ) ;
F_1 ( V_2 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_72 , V_235 ) ;
return - V_113 ;
}
if ( V_14 -> V_131 != V_238 )
F_12 ( V_14 , L_73 ) ;
V_14 -> V_131 = V_238 ;
if ( V_238 == 0 )
V_14 -> V_157 = 0 ;
return 0 ;
}
int F_157 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_3 -> V_4 )
return 0 ;
return F_122 ( V_2 -> V_3 , V_221 ) ;
}
int F_158 ( struct V_1 * V_2 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_149 ) ;
V_73 = F_157 ( V_2 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_13 * V_239 , struct V_13 * V_240 ,
const char * V_241 ,
int (* V_131)( struct V_13 * V_59 ,
struct V_13 * V_115 ) )
{
struct V_56 * V_57 ;
int V_73 ;
V_57 = F_22 ( sizeof( struct V_56 ) , V_12 ) ;
if ( ! V_57 )
return - V_31 ;
V_57 -> V_59 = V_239 ;
V_57 -> V_115 = V_240 ;
V_57 -> V_131 = V_131 ;
F_24 ( & V_57 -> V_91 ) ;
F_24 ( & V_57 -> V_58 ) ;
F_24 ( & V_57 -> V_94 ) ;
F_24 ( & V_57 -> V_92 ) ;
if ( V_240 -> V_20 == V_21 ) {
if ( V_239 -> V_20 == V_207 ||
V_239 -> V_20 == V_144 ||
V_239 -> V_20 == V_135 ||
V_239 -> V_20 == V_22 )
V_240 -> V_132 = 1 ;
}
if ( V_239 -> V_20 == V_22 ) {
if ( V_240 -> V_20 == V_134 ||
V_240 -> V_20 == V_133 ||
V_240 -> V_20 == V_135 ||
V_240 -> V_20 == V_21 )
V_239 -> V_132 = 1 ;
}
F_12 ( V_239 , L_74 ) ;
F_12 ( V_240 , L_74 ) ;
if ( V_241 == NULL ) {
F_56 ( & V_57 -> V_91 , & V_2 -> V_3 -> V_32 ) ;
F_56 ( & V_57 -> V_92 , & V_240 -> V_93 ) ;
F_56 ( & V_57 -> V_94 , & V_239 -> V_95 ) ;
V_57 -> V_96 = 1 ;
return 0 ;
}
switch ( V_240 -> V_20 ) {
case V_127 :
case V_140 :
case V_224 :
case V_225 :
case V_21 :
case V_22 :
case V_145 :
case V_207 :
case V_143 :
case V_186 :
case V_189 :
case V_124 :
case V_125 :
case V_126 :
case V_141 :
case V_128 :
case V_142 :
case V_129 :
case V_242 :
case V_46 :
F_56 ( & V_57 -> V_91 , & V_2 -> V_3 -> V_32 ) ;
F_56 ( & V_57 -> V_92 , & V_240 -> V_93 ) ;
F_56 ( & V_57 -> V_94 , & V_239 -> V_95 ) ;
V_57 -> V_96 = 1 ;
return 0 ;
case V_112 :
V_73 = F_54 ( V_2 , V_239 , V_240 , V_57 , V_241 ,
& V_240 -> V_99 [ 0 ] ) ;
if ( V_73 != 0 )
goto V_139;
break;
case V_33 :
case V_34 :
case V_35 :
V_73 = F_58 ( V_2 , V_239 , V_240 , V_57 , V_241 ) ;
if ( V_73 != 0 )
goto V_139;
break;
case V_133 :
case V_144 :
case V_135 :
case V_134 :
F_56 ( & V_57 -> V_91 , & V_2 -> V_3 -> V_32 ) ;
F_56 ( & V_57 -> V_92 , & V_240 -> V_93 ) ;
F_56 ( & V_57 -> V_94 , & V_239 -> V_95 ) ;
V_57 -> V_96 = 0 ;
return 0 ;
}
return 0 ;
V_139:
F_9 ( V_57 ) ;
return V_73 ;
}
static int F_159 ( struct V_1 * V_2 ,
const struct V_243 * V_244 )
{
struct V_13 * V_239 = NULL , * V_240 = NULL , * V_14 ;
struct V_13 * V_245 = NULL , * V_246 = NULL ;
const char * V_115 ;
const char * V_59 ;
char V_247 [ 80 ] ;
char V_248 [ 80 ] ;
const char * V_106 ;
int V_73 ;
V_106 = F_42 ( V_2 ) ;
if ( V_106 ) {
snprintf ( V_247 , sizeof( V_247 ) , L_5 ,
V_106 , V_244 -> V_115 ) ;
V_115 = V_247 ;
snprintf ( V_248 , sizeof( V_248 ) , L_5 ,
V_106 , V_244 -> V_59 ) ;
V_59 = V_248 ;
} else {
V_115 = V_244 -> V_115 ;
V_59 = V_244 -> V_59 ;
}
F_17 (w, &dapm->card->widgets, list) {
if ( ! V_240 && ! ( strcmp ( V_14 -> V_17 , V_115 ) ) ) {
V_246 = V_14 ;
if ( V_14 -> V_2 == V_2 )
V_240 = V_14 ;
continue;
}
if ( ! V_239 && ! ( strcmp ( V_14 -> V_17 , V_59 ) ) ) {
V_245 = V_14 ;
if ( V_14 -> V_2 == V_2 )
V_239 = V_14 ;
}
}
if ( ! V_240 )
V_240 = V_246 ;
if ( ! V_239 )
V_239 = V_245 ;
if ( V_239 == NULL ) {
F_23 ( V_2 -> V_8 , L_75 ,
V_244 -> V_59 ) ;
return - V_97 ;
}
if ( V_240 == NULL ) {
F_23 ( V_2 -> V_8 , L_76 ,
V_244 -> V_115 ) ;
return - V_97 ;
}
V_73 = F_33 ( V_2 , V_239 , V_240 , V_244 -> V_241 ,
V_244 -> V_131 ) ;
if ( V_73 )
goto V_139;
return 0 ;
V_139:
F_85 ( V_2 -> V_8 , L_77 ,
V_59 , V_244 -> V_241 , V_115 ) ;
return V_73 ;
}
static int F_160 ( struct V_1 * V_2 ,
const struct V_243 * V_244 )
{
struct V_56 * V_57 , * V_98 ;
const char * V_115 ;
const char * V_59 ;
char V_247 [ 80 ] ;
char V_248 [ 80 ] ;
const char * V_106 ;
if ( V_244 -> V_241 ) {
F_23 ( V_2 -> V_8 ,
L_78 ) ;
return - V_113 ;
}
V_106 = F_42 ( V_2 ) ;
if ( V_106 ) {
snprintf ( V_247 , sizeof( V_247 ) , L_5 ,
V_106 , V_244 -> V_115 ) ;
V_115 = V_247 ;
snprintf ( V_248 , sizeof( V_248 ) , L_5 ,
V_106 , V_244 -> V_59 ) ;
V_59 = V_248 ;
} else {
V_115 = V_244 -> V_115 ;
V_59 = V_244 -> V_59 ;
}
V_57 = NULL ;
F_17 (p, &dapm->card->paths, list) {
if ( strcmp ( V_98 -> V_59 -> V_17 , V_59 ) != 0 )
continue;
if ( strcmp ( V_98 -> V_115 -> V_17 , V_115 ) != 0 )
continue;
V_57 = V_98 ;
break;
}
if ( V_57 ) {
F_12 ( V_57 -> V_59 , L_79 ) ;
F_12 ( V_57 -> V_115 , L_79 ) ;
F_152 ( V_57 ) ;
} else {
F_85 ( V_2 -> V_8 , L_80 ,
V_59 , V_115 ) ;
}
return 0 ;
}
int F_161 ( struct V_1 * V_2 ,
const struct V_243 * V_244 , int V_249 )
{
int V_86 , V_250 , V_73 = 0 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_251 ) ;
for ( V_86 = 0 ; V_86 < V_249 ; V_86 ++ ) {
V_250 = F_159 ( V_2 , V_244 ) ;
if ( V_250 < 0 ) {
F_23 ( V_2 -> V_8 , L_81 ,
V_244 -> V_59 ,
V_244 -> V_241 ? V_244 -> V_241 : L_82 ,
V_244 -> V_115 ) ;
V_73 = V_250 ;
}
V_244 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_162 ( struct V_1 * V_2 ,
const struct V_243 * V_244 , int V_249 )
{
int V_86 , V_73 = 0 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_251 ) ;
for ( V_86 = 0 ; V_86 < V_249 ; V_86 ++ ) {
F_160 ( V_2 , V_244 ) ;
V_244 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
static int F_163 ( struct V_1 * V_2 ,
const struct V_243 * V_244 )
{
struct V_13 * V_59 = F_155 ( V_2 ,
V_244 -> V_59 ,
true ) ;
struct V_13 * V_115 = F_155 ( V_2 ,
V_244 -> V_115 ,
true ) ;
struct V_56 * V_57 ;
int V_211 = 0 ;
if ( ! V_59 ) {
F_23 ( V_2 -> V_8 , L_83 ,
V_244 -> V_59 ) ;
return - V_97 ;
}
if ( ! V_115 ) {
F_23 ( V_2 -> V_8 , L_84 ,
V_244 -> V_115 ) ;
return - V_97 ;
}
if ( V_244 -> V_241 || V_244 -> V_131 )
F_85 ( V_2 -> V_8 , L_85 ,
V_244 -> V_59 , V_244 -> V_115 ) ;
F_17 (path, &source->sinks, list_source) {
if ( V_57 -> V_115 == V_115 ) {
V_57 -> V_137 = 1 ;
V_211 ++ ;
}
}
if ( V_211 == 0 )
F_23 ( V_2 -> V_8 , L_86 ,
V_244 -> V_59 , V_244 -> V_115 ) ;
if ( V_211 > 1 )
F_85 ( V_2 -> V_8 , L_87 ,
V_211 , V_244 -> V_59 , V_244 -> V_115 ) ;
return 0 ;
}
int F_164 ( struct V_1 * V_2 ,
const struct V_243 * V_244 , int V_249 )
{
int V_86 , V_139 ;
int V_73 = 0 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_251 ) ;
for ( V_86 = 0 ; V_86 < V_249 ; V_86 ++ ) {
V_139 = F_163 ( V_2 , V_244 ) ;
if ( V_139 )
V_73 = V_139 ;
V_244 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_165 ( struct V_19 * V_3 )
{
struct V_13 * V_14 ;
unsigned int V_84 ;
F_80 ( & V_3 -> V_5 , V_251 ) ;
F_17 (w, &card->widgets, list)
{
if ( V_14 -> V_252 )
continue;
if ( V_14 -> V_100 ) {
V_14 -> V_103 = F_22 ( V_14 -> V_100 *
sizeof( struct V_25 * ) ,
V_12 ) ;
if ( ! V_14 -> V_103 ) {
F_18 ( & V_3 -> V_5 ) ;
return - V_31 ;
}
}
switch( V_14 -> V_20 ) {
case V_33 :
case V_34 :
case V_35 :
F_65 ( V_14 ) ;
break;
case V_112 :
F_66 ( V_14 ) ;
break;
case V_224 :
case V_225 :
F_67 ( V_14 ) ;
break;
default:
break;
}
if ( V_14 -> V_39 >= 0 ) {
F_43 ( V_14 -> V_2 , V_14 -> V_39 , & V_84 ) ;
V_84 = V_84 >> V_14 -> V_42 ;
V_84 &= V_14 -> V_40 ;
if ( V_84 == V_14 -> V_45 )
V_14 -> V_60 = 1 ;
}
V_14 -> V_252 = 1 ;
F_12 ( V_14 , L_88 ) ;
F_136 ( V_14 ) ;
}
F_122 ( V_3 , V_221 ) ;
F_18 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_166 ( struct V_25 * V_26 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = F_38 ( V_26 ) ;
struct V_19 * V_3 = V_2 -> V_3 ;
struct V_29 * V_30 =
(struct V_29 * ) V_26 -> V_36 ;
int V_39 = V_30 -> V_39 ;
unsigned int V_42 = V_30 -> V_42 ;
int V_41 = V_30 -> V_41 ;
unsigned int V_40 = ( 1 << F_25 ( V_41 ) ) - 1 ;
unsigned int V_43 = V_30 -> V_43 ;
unsigned int V_84 ;
int V_73 = 0 ;
if ( F_167 ( V_30 ) )
F_85 ( V_2 -> V_8 ,
L_89 ,
V_26 -> V_20 . V_17 ) ;
F_80 ( & V_3 -> V_5 , V_149 ) ;
if ( F_34 ( V_26 ) && V_39 != V_87 ) {
V_73 = F_43 ( V_2 , V_39 , & V_84 ) ;
V_84 = ( V_84 >> V_42 ) & V_40 ;
} else {
V_84 = F_36 ( V_26 ) ;
}
F_18 ( & V_3 -> V_5 ) ;
if ( V_43 )
V_254 -> V_47 . integer . V_47 [ 0 ] = V_41 - V_84 ;
else
V_254 -> V_47 . integer . V_47 [ 0 ] = V_84 ;
return V_73 ;
}
int F_168 ( struct V_25 * V_26 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = F_38 ( V_26 ) ;
struct V_19 * V_3 = V_2 -> V_3 ;
struct V_29 * V_30 =
(struct V_29 * ) V_26 -> V_36 ;
int V_39 = V_30 -> V_39 ;
unsigned int V_42 = V_30 -> V_42 ;
int V_41 = V_30 -> V_41 ;
unsigned int V_40 = ( 1 << F_25 ( V_41 ) ) - 1 ;
unsigned int V_43 = V_30 -> V_43 ;
unsigned int V_84 ;
int V_96 , V_255 , V_256 = 0 ;
struct V_190 V_191 ;
int V_73 = 0 ;
if ( F_167 ( V_30 ) )
F_85 ( V_2 -> V_8 ,
L_89 ,
V_26 -> V_20 . V_17 ) ;
V_84 = ( V_254 -> V_47 . integer . V_47 [ 0 ] & V_40 ) ;
V_96 = ! ! V_84 ;
if ( V_43 )
V_84 = V_41 - V_84 ;
F_80 ( & V_3 -> V_5 , V_149 ) ;
V_255 = F_37 ( V_26 , V_84 ) ;
if ( V_39 != V_87 ) {
V_40 = V_40 << V_42 ;
V_84 = V_84 << V_42 ;
V_256 = F_47 ( V_2 , V_39 , V_40 , V_84 ) ;
}
if ( V_255 || V_256 ) {
if ( V_256 ) {
V_191 . V_26 = V_26 ;
V_191 . V_39 = V_39 ;
V_191 . V_40 = V_40 ;
V_191 . V_84 = V_84 ;
V_3 -> V_191 = & V_191 ;
}
V_255 |= V_256 ;
V_73 = F_143 ( V_3 , V_26 , V_96 ) ;
V_3 -> V_191 = NULL ;
}
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_142 ( V_3 ) ;
return V_255 ;
}
int F_169 ( struct V_25 * V_26 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = F_38 ( V_26 ) ;
struct V_82 * V_83 = (struct V_82 * ) V_26 -> V_36 ;
unsigned int V_257 , V_84 ;
if ( V_83 -> V_39 != V_87 ) {
int V_73 = F_43 ( V_2 , V_83 -> V_39 , & V_257 ) ;
if ( V_73 )
return V_73 ;
} else {
V_257 = F_36 ( V_26 ) ;
}
V_84 = ( V_257 >> V_83 -> V_88 ) & V_83 -> V_40 ;
V_254 -> V_47 . V_258 . V_85 [ 0 ] = F_55 ( V_83 , V_84 ) ;
if ( V_83 -> V_88 != V_83 -> V_259 ) {
V_84 = ( V_257 >> V_83 -> V_259 ) & V_83 -> V_40 ;
V_84 = F_55 ( V_83 , V_84 ) ;
V_254 -> V_47 . V_258 . V_85 [ 1 ] = V_84 ;
}
return 0 ;
}
int F_170 ( struct V_25 * V_26 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = F_38 ( V_26 ) ;
struct V_19 * V_3 = V_2 -> V_3 ;
struct V_82 * V_83 = (struct V_82 * ) V_26 -> V_36 ;
unsigned int * V_85 = V_254 -> V_47 . V_258 . V_85 ;
unsigned int V_84 , V_255 ;
unsigned int V_40 ;
struct V_190 V_191 ;
int V_73 = 0 ;
if ( V_85 [ 0 ] >= V_83 -> V_89 )
return - V_113 ;
V_84 = F_171 ( V_83 , V_85 [ 0 ] ) << V_83 -> V_88 ;
V_40 = V_83 -> V_40 << V_83 -> V_88 ;
if ( V_83 -> V_88 != V_83 -> V_259 ) {
if ( V_85 [ 1 ] > V_83 -> V_89 )
return - V_113 ;
V_84 |= F_171 ( V_83 , V_85 [ 1 ] ) << V_83 -> V_88 ;
V_40 |= V_83 -> V_40 << V_83 -> V_259 ;
}
F_80 ( & V_3 -> V_5 , V_149 ) ;
if ( V_83 -> V_39 != V_87 )
V_255 = F_47 ( V_2 , V_83 -> V_39 , V_40 , V_84 ) ;
else
V_255 = F_37 ( V_26 , V_84 ) ;
if ( V_255 ) {
if ( V_83 -> V_39 != V_87 ) {
V_191 . V_26 = V_26 ;
V_191 . V_39 = V_83 -> V_39 ;
V_191 . V_40 = V_40 ;
V_191 . V_84 = V_84 ;
V_3 -> V_191 = & V_191 ;
}
V_73 = F_139 ( V_3 , V_26 , V_85 [ 0 ] , V_83 ) ;
V_3 -> V_191 = NULL ;
}
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_142 ( V_3 ) ;
return V_255 ;
}
int F_172 ( struct V_25 * V_26 ,
struct V_260 * V_261 )
{
V_261 -> type = V_262 ;
V_261 -> V_211 = 1 ;
V_261 -> V_47 . integer . V_263 = 0 ;
V_261 -> V_47 . integer . V_41 = 1 ;
return 0 ;
}
int F_173 ( struct V_25 * V_26 ,
struct V_253 * V_254 )
{
struct V_19 * V_3 = F_28 ( V_26 ) ;
const char * V_235 = ( const char * ) V_26 -> V_36 ;
F_80 ( & V_3 -> V_5 , V_149 ) ;
V_254 -> V_47 . integer . V_47 [ 0 ] =
F_174 ( & V_3 -> V_2 , V_235 ) ;
F_18 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_175 ( struct V_25 * V_26 ,
struct V_253 * V_254 )
{
struct V_19 * V_3 = F_28 ( V_26 ) ;
const char * V_235 = ( const char * ) V_26 -> V_36 ;
if ( V_254 -> V_47 . integer . V_47 [ 0 ] )
F_176 ( & V_3 -> V_2 , V_235 ) ;
else
F_177 ( & V_3 -> V_2 , V_235 ) ;
F_158 ( & V_3 -> V_2 ) ;
return 0 ;
}
static struct V_13 *
F_26 ( struct V_1 * V_2 ,
const struct V_13 * V_24 )
{
struct V_13 * V_14 ;
const char * V_106 ;
int V_73 ;
if ( ( V_14 = F_19 ( V_24 ) ) == NULL )
return NULL ;
switch ( V_14 -> V_20 ) {
case V_125 :
V_14 -> V_155 = F_178 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_179 ( V_14 -> V_155 ) ) {
V_73 = F_180 ( V_14 -> V_155 ) ;
F_23 ( V_2 -> V_8 , L_90 ,
V_14 -> V_17 , V_73 ) ;
return NULL ;
}
if ( V_14 -> V_45 & V_154 ) {
V_73 = F_84 ( V_14 -> V_155 , true ) ;
if ( V_73 != 0 )
F_85 ( V_14 -> V_2 -> V_8 ,
L_15 ,
V_14 -> V_17 , V_73 ) ;
}
break;
case V_126 :
#ifdef F_181
V_14 -> V_156 = F_182 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_179 ( V_14 -> V_156 ) ) {
V_73 = F_180 ( V_14 -> V_156 ) ;
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
V_106 = F_42 ( V_2 ) ;
if ( V_106 )
V_14 -> V_17 = F_61 ( V_12 , L_5 , V_106 , V_24 -> V_17 ) ;
else
V_14 -> V_17 = F_61 ( V_12 , L_1 , V_24 -> V_17 ) ;
if ( V_14 -> V_17 == NULL ) {
F_9 ( V_14 ) ;
return NULL ;
}
switch ( V_14 -> V_20 ) {
case V_33 :
case V_34 :
case V_35 :
V_14 -> V_158 = F_93 ;
break;
case V_112 :
V_14 -> V_158 = F_93 ;
break;
case V_129 :
V_14 -> V_158 = F_94 ;
break;
case V_142 :
V_14 -> V_158 = F_95 ;
break;
case V_127 :
case V_128 :
case V_140 :
case V_141 :
case V_224 :
case V_225 :
case V_21 :
case V_22 :
case V_207 :
case V_134 :
case V_133 :
case V_144 :
case V_135 :
case V_242 :
V_14 -> V_158 = F_93 ;
break;
case V_124 :
case V_125 :
case V_126 :
case V_46 :
V_14 -> V_158 = F_96 ;
break;
default:
V_14 -> V_158 = F_97 ;
break;
}
V_14 -> V_2 = V_2 ;
V_14 -> V_222 = V_2 -> V_222 ;
F_24 ( & V_14 -> V_93 ) ;
F_24 ( & V_14 -> V_95 ) ;
F_24 ( & V_14 -> V_91 ) ;
F_24 ( & V_14 -> V_15 ) ;
F_56 ( & V_14 -> V_91 , & V_2 -> V_3 -> V_55 ) ;
V_14 -> V_131 = 1 ;
return V_14 ;
}
int F_183 ( struct V_1 * V_2 ,
const struct V_13 * V_24 ,
int V_249 )
{
struct V_13 * V_14 ;
int V_86 ;
int V_73 = 0 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_251 ) ;
for ( V_86 = 0 ; V_86 < V_249 ; V_86 ++ ) {
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
static int F_184 ( struct V_13 * V_14 ,
struct V_25 * V_26 , int V_153 )
{
struct V_56 * V_264 , * V_265 ;
struct V_146 * V_59 , * V_115 ;
const struct V_266 * V_267 = V_14 -> V_268 ;
struct V_269 V_270 ;
struct V_271 * V_268 = NULL ;
T_8 V_9 ;
int V_73 ;
if ( F_106 ( ! V_267 ) ||
F_106 ( F_11 ( & V_14 -> V_93 ) || F_11 ( & V_14 -> V_95 ) ) )
return - V_113 ;
V_264 = F_105 ( & V_14 -> V_93 , struct V_56 ,
V_92 ) ;
V_265 = F_105 ( & V_14 -> V_95 , struct V_56 ,
V_94 ) ;
if ( F_106 ( ! V_264 || ! V_265 ) ||
F_106 ( ! V_265 -> V_59 || ! V_264 -> V_115 ) ||
F_106 ( ! V_264 -> V_59 || ! V_265 -> V_115 ) )
return - V_113 ;
V_59 = V_264 -> V_59 -> V_272 ;
V_115 = V_265 -> V_115 -> V_272 ;
if ( V_267 -> V_273 ) {
V_9 = F_185 ( V_267 -> V_273 ) - 1 ;
} else {
F_85 ( V_14 -> V_2 -> V_8 , L_92 ,
V_267 -> V_273 ) ;
V_9 = 0 ;
}
V_268 = F_22 ( sizeof( * V_268 ) , V_12 ) ;
if ( ! V_268 ) {
V_73 = - V_31 ;
goto V_75;
}
F_186 ( F_187 ( V_268 , V_274 ) , V_9 ) ;
F_188 ( V_268 , V_275 ) -> V_263 =
V_267 -> V_276 ;
F_188 ( V_268 , V_275 ) -> V_41 =
V_267 -> V_277 ;
F_188 ( V_268 , V_278 ) -> V_263
= V_267 -> V_279 ;
F_188 ( V_268 , V_278 ) -> V_41
= V_267 -> V_280 ;
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
switch ( V_153 ) {
case V_171 :
V_270 . V_148 = V_281 ;
V_73 = F_189 ( & V_270 , V_268 , V_59 ) ;
if ( V_73 < 0 )
goto V_75;
V_270 . V_148 = V_150 ;
V_73 = F_189 ( & V_270 , V_268 , V_115 ) ;
if ( V_73 < 0 )
goto V_75;
break;
case V_172 :
V_73 = F_190 ( V_115 , 0 ,
V_150 ) ;
if ( V_73 != 0 && V_73 != - V_282 )
F_85 ( V_115 -> V_8 , L_93 , V_73 ) ;
V_73 = 0 ;
break;
case V_173 :
V_73 = F_190 ( V_115 , 1 ,
V_150 ) ;
if ( V_73 != 0 && V_73 != - V_282 )
F_85 ( V_115 -> V_8 , L_94 , V_73 ) ;
V_73 = 0 ;
break;
default:
F_101 ( 1 , L_22 , V_153 ) ;
return - V_113 ;
}
V_75:
F_9 ( V_268 ) ;
return V_73 ;
}
int F_191 ( struct V_19 * V_3 ,
const struct V_266 * V_268 ,
struct V_13 * V_59 ,
struct V_13 * V_115 )
{
struct V_13 V_38 ;
struct V_13 * V_14 ;
T_3 V_283 ;
char * V_284 ;
int V_73 ;
V_283 = strlen ( V_59 -> V_17 ) + strlen ( V_115 -> V_17 ) + 2 ;
V_284 = F_192 ( V_3 -> V_8 , V_283 , V_12 ) ;
if ( ! V_284 )
return - V_31 ;
snprintf ( V_284 , V_283 , L_95 , V_59 -> V_17 , V_115 -> V_17 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_39 = V_87 ;
V_38 . V_20 = V_242 ;
V_38 . V_17 = V_284 ;
V_38 . V_153 = F_184 ;
V_38 . V_177 = V_171 | V_172 |
V_173 ;
F_72 ( V_3 -> V_8 , L_96 , V_284 ) ;
V_14 = F_26 ( & V_3 -> V_2 , & V_38 ) ;
if ( ! V_14 ) {
F_23 ( V_3 -> V_8 , L_97 ,
V_284 ) ;
return - V_31 ;
}
V_14 -> V_268 = V_268 ;
V_73 = F_33 ( & V_3 -> V_2 , V_59 , V_14 , NULL , NULL ) ;
if ( V_73 )
return V_73 ;
return F_33 ( & V_3 -> V_2 , V_14 , V_115 , NULL , NULL ) ;
}
int F_193 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_13 V_38 ;
struct V_13 * V_14 ;
F_106 ( V_2 -> V_8 != V_147 -> V_8 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_39 = V_87 ;
if ( V_147 -> V_285 -> V_286 . V_287 ) {
V_38 . V_20 = V_142 ;
V_38 . V_17 = V_147 -> V_285 -> V_286 . V_287 ;
V_38 . V_213 = V_147 -> V_285 -> V_286 . V_287 ;
F_72 ( V_147 -> V_8 , L_96 ,
V_38 . V_17 ) ;
V_14 = F_26 ( V_2 , & V_38 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_97 ,
V_147 -> V_285 -> V_286 . V_287 ) ;
return - V_31 ;
}
V_14 -> V_272 = V_147 ;
V_147 -> V_151 = V_14 ;
}
if ( V_147 -> V_285 -> V_288 . V_287 ) {
V_38 . V_20 = V_129 ;
V_38 . V_17 = V_147 -> V_285 -> V_288 . V_287 ;
V_38 . V_213 = V_147 -> V_285 -> V_288 . V_287 ;
F_72 ( V_147 -> V_8 , L_96 ,
V_38 . V_17 ) ;
V_14 = F_26 ( V_2 , & V_38 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_97 ,
V_147 -> V_285 -> V_288 . V_287 ) ;
return - V_31 ;
}
V_14 -> V_272 = V_147 ;
V_147 -> V_152 = V_14 ;
}
return 0 ;
}
int F_194 ( struct V_19 * V_3 )
{
struct V_13 * V_289 , * V_14 ;
struct V_13 * V_78 , * V_115 ;
struct V_146 * V_147 ;
F_17 (dai_w, &card->widgets, list) {
switch ( V_289 -> V_20 ) {
case V_142 :
case V_129 :
break;
default:
continue;
}
V_147 = V_289 -> V_272 ;
F_17 (w, &card->widgets, list) {
if ( V_14 -> V_2 != V_289 -> V_2 )
continue;
switch ( V_14 -> V_20 ) {
case V_142 :
case V_129 :
continue;
default:
break;
}
if ( ! V_14 -> V_213 || ! strstr ( V_14 -> V_213 , V_289 -> V_17 ) )
continue;
if ( V_289 -> V_20 == V_142 ) {
V_78 = V_289 ;
V_115 = V_14 ;
} else {
V_78 = V_14 ;
V_115 = V_289 ;
}
F_72 ( V_147 -> V_8 , L_98 , V_78 -> V_17 , V_115 -> V_17 ) ;
F_33 ( V_14 -> V_2 , V_78 , V_115 , NULL , NULL ) ;
}
}
return 0 ;
}
static void F_195 ( struct V_19 * V_3 ,
struct V_228 * V_229 )
{
struct V_146 * V_290 = V_229 -> V_290 ;
struct V_13 * V_115 , * V_59 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_229 -> V_230 ; V_86 ++ ) {
struct V_146 * V_291 = V_229 -> V_231 [ V_86 ] ;
if ( F_196 ( V_291 ) ||
F_196 ( V_290 ) )
continue;
if ( V_291 -> V_151 && V_290 -> V_151 ) {
V_59 = V_290 -> V_151 ;
V_115 = V_291 -> V_151 ;
F_72 ( V_229 -> V_8 , L_99 ,
V_290 -> V_68 -> V_17 , V_59 -> V_17 ,
V_291 -> V_68 -> V_17 , V_115 -> V_17 ) ;
F_33 ( & V_3 -> V_2 , V_59 , V_115 ,
NULL , NULL ) ;
}
if ( V_291 -> V_152 && V_290 -> V_152 ) {
V_59 = V_291 -> V_152 ;
V_115 = V_290 -> V_152 ;
F_72 ( V_229 -> V_8 , L_99 ,
V_291 -> V_68 -> V_17 , V_59 -> V_17 ,
V_290 -> V_68 -> V_17 , V_115 -> V_17 ) ;
F_33 ( & V_3 -> V_2 , V_59 , V_115 ,
NULL , NULL ) ;
}
}
}
static void F_197 ( struct V_146 * V_147 , int V_148 ,
int V_153 )
{
struct V_13 * V_14 ;
if ( V_148 == V_150 )
V_14 = V_147 -> V_151 ;
else
V_14 = V_147 -> V_152 ;
if ( V_14 ) {
F_12 ( V_14 , L_100 ) ;
switch ( V_153 ) {
case V_187 :
V_14 -> V_130 = 1 ;
break;
case V_188 :
V_14 -> V_130 = 0 ;
break;
case V_292 :
case V_293 :
case V_294 :
case V_295 :
break;
}
}
}
void F_198 ( struct V_19 * V_3 )
{
struct V_228 * V_229 = V_3 -> V_229 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_3 -> V_296 ; V_86 ++ ) {
V_229 = & V_3 -> V_229 [ V_86 ] ;
if ( V_229 -> V_297 -> V_298 || V_229 -> V_297 -> V_268 )
continue;
F_195 ( V_3 , V_229 ) ;
}
}
static void F_199 ( struct V_228 * V_229 , int V_148 ,
int V_153 )
{
int V_86 ;
F_197 ( V_229 -> V_290 , V_148 , V_153 ) ;
for ( V_86 = 0 ; V_86 < V_229 -> V_230 ; V_86 ++ )
F_197 ( V_229 -> V_231 [ V_86 ] , V_148 , V_153 ) ;
F_122 ( V_229 -> V_3 , V_153 ) ;
}
void F_200 ( struct V_228 * V_229 , int V_148 ,
int V_153 )
{
struct V_19 * V_3 = V_229 -> V_3 ;
F_80 ( & V_3 -> V_5 , V_149 ) ;
F_199 ( V_229 , V_148 , V_153 ) ;
F_18 ( & V_3 -> V_5 ) ;
}
int F_201 ( struct V_1 * V_2 ,
const char * V_235 )
{
return F_156 ( V_2 , V_235 , 1 ) ;
}
int F_176 ( struct V_1 * V_2 , const char * V_235 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_149 ) ;
V_73 = F_156 ( V_2 , V_235 , 1 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_202 ( struct V_1 * V_2 ,
const char * V_235 )
{
struct V_13 * V_14 = F_155 ( V_2 , V_235 , true ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_101 , V_235 ) ;
return - V_113 ;
}
F_72 ( V_14 -> V_2 -> V_8 , L_102 , V_235 ) ;
V_14 -> V_131 = 1 ;
V_14 -> V_157 = 1 ;
F_12 ( V_14 , L_103 ) ;
return 0 ;
}
int F_203 ( struct V_1 * V_2 ,
const char * V_235 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_149 ) ;
V_73 = F_202 ( V_2 , V_235 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_204 ( struct V_1 * V_2 ,
const char * V_235 )
{
return F_156 ( V_2 , V_235 , 0 ) ;
}
int F_177 ( struct V_1 * V_2 ,
const char * V_235 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_149 ) ;
V_73 = F_156 ( V_2 , V_235 , 0 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_205 ( struct V_1 * V_2 ,
const char * V_235 )
{
return F_156 ( V_2 , V_235 , 0 ) ;
}
int F_206 ( struct V_1 * V_2 , const char * V_235 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_149 ) ;
V_73 = F_156 ( V_2 , V_235 , 0 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_174 ( struct V_1 * V_2 ,
const char * V_235 )
{
struct V_13 * V_14 = F_155 ( V_2 , V_235 , true ) ;
if ( V_14 )
return V_14 -> V_131 ;
return 0 ;
}
int F_207 ( struct V_1 * V_2 ,
const char * V_235 )
{
struct V_13 * V_14 = F_155 ( V_2 , V_235 , false ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_101 , V_235 ) ;
return - V_113 ;
}
V_14 -> V_119 = 1 ;
return 0 ;
}
static bool F_208 ( struct V_19 * V_3 ,
struct V_13 * V_14 )
{
struct V_56 * V_98 ;
F_17 (p, &card->paths, list) {
if ( ( V_98 -> V_59 == V_14 ) || ( V_98 -> V_115 == V_14 ) ) {
F_72 ( V_3 -> V_8 ,
L_104 ,
V_98 -> V_59 -> V_17 , V_98 -> V_59 -> V_20 , V_98 -> V_59 -> V_2 ,
V_98 -> V_115 -> V_17 , V_98 -> V_115 -> V_20 , V_98 -> V_115 -> V_2 ) ;
if ( V_98 -> V_59 -> V_2 != V_98 -> V_115 -> V_2 )
return true ;
if ( V_98 -> V_115 -> V_20 == V_21 ) {
switch ( V_98 -> V_59 -> V_20 ) {
case V_22 :
case V_207 :
return true ;
default:
break;
}
}
}
}
return false ;
}
void F_209 ( struct V_19 * V_3 )
{
struct V_13 * V_14 ;
F_72 ( V_3 -> V_8 , L_105 , & V_3 -> V_2 ) ;
F_17 (w, &card->widgets, list) {
switch ( V_14 -> V_20 ) {
case V_21 :
case V_22 :
case V_207 :
F_72 ( V_3 -> V_8 , L_106 ,
V_14 -> V_17 ) ;
if ( ! F_208 ( V_3 , V_14 ) ) {
F_72 ( V_3 -> V_8 ,
L_107 ) ;
F_206 ( V_14 -> V_2 , V_14 -> V_17 ) ;
}
break;
default:
break;
}
}
}
void F_210 ( struct V_1 * V_2 )
{
F_150 ( V_2 -> V_8 ) ;
F_137 ( V_2 ) ;
F_154 ( V_2 ) ;
F_153 ( & V_2 -> V_91 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
struct V_13 * V_14 ;
F_108 ( V_203 ) ;
int V_299 = 0 ;
F_16 ( & V_3 -> V_5 ) ;
F_17 (w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
if ( V_14 -> V_60 ) {
F_99 ( V_14 , & V_203 , false ) ;
V_14 -> V_60 = 0 ;
V_299 = 1 ;
}
}
if ( V_299 ) {
if ( V_2 -> V_76 == V_199 )
F_51 ( V_2 ,
V_200 ) ;
F_107 ( V_3 , & V_203 , 0 , false ) ;
if ( V_2 -> V_76 == V_200 )
F_51 ( V_2 ,
V_198 ) ;
}
F_18 ( & V_3 -> V_5 ) ;
}
void F_212 ( struct V_19 * V_3 )
{
struct V_1 * V_2 ;
F_17 (dapm, &card->dapm_list, list) {
if ( V_2 != & V_3 -> V_2 ) {
F_211 ( V_2 ) ;
if ( V_2 -> V_76 == V_198 )
F_51 ( V_2 ,
V_196 ) ;
}
}
F_211 ( & V_3 -> V_2 ) ;
if ( V_3 -> V_2 . V_76 == V_198 )
F_51 ( & V_3 -> V_2 ,
V_196 ) ;
}
