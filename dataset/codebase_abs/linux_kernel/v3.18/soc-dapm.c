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
unsigned int F_36 ( const struct V_25 * V_26 )
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
char * V_111 = NULL ;
const char * V_17 ;
int V_73 = 0 ;
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
if ( ! V_26 ) {
V_73 = - V_31 ;
goto V_114;
}
V_26 -> V_115 = F_27 ;
V_73 = F_21 ( V_14 , V_26 ) ;
if ( V_73 ) {
F_63 ( V_26 ) ;
goto V_114;
}
V_73 = F_64 ( V_3 , V_26 ) ;
if ( V_73 < 0 ) {
F_23 ( V_2 -> V_8 ,
L_6 ,
V_14 -> V_17 , V_17 , V_73 ) ;
goto V_114;
}
}
V_73 = F_30 ( V_26 , V_14 ) ;
if ( V_73 == 0 )
V_14 -> V_103 [ V_104 ] = V_26 ;
V_114:
F_9 ( V_111 ) ;
return V_73 ;
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
struct V_61 * V_116 )
{
struct V_56 * V_98 ;
F_17 (p, sink, list_source) {
if ( V_98 -> V_117 ) {
V_98 -> V_117 = 0 ;
F_68 ( V_2 , & V_98 -> V_116 -> V_95 ) ;
}
}
}
static void F_69 ( struct V_1 * V_2 ,
struct V_61 * V_59 )
{
struct V_56 * V_98 ;
F_17 (p, source, list_sink) {
if ( V_98 -> V_117 ) {
V_98 -> V_117 = 0 ;
F_69 ( V_2 , & V_98 -> V_59 -> V_93 ) ;
}
}
}
static int F_70 ( struct V_13 * V_24 )
{
int V_72 = F_71 ( V_24 -> V_2 -> V_3 -> V_105 ) ;
switch ( V_72 ) {
case V_118 :
case V_119 :
if ( V_24 -> V_120 )
F_72 ( V_24 -> V_2 -> V_8 , L_10 ,
V_24 -> V_17 ) ;
return V_24 -> V_120 ;
default:
return 1 ;
}
}
static int F_73 ( struct V_51 * * V_91 ,
struct V_13 * V_14 )
{
struct V_51 * V_50 ;
int V_121 , V_122 , V_86 ;
if ( * V_91 == NULL )
return - V_113 ;
V_50 = * V_91 ;
for ( V_86 = 0 ; V_86 < V_50 -> V_54 ; V_86 ++ ) {
if ( V_50 -> V_55 [ V_86 ] == V_14 )
return 0 ;
}
V_122 = V_50 -> V_54 + 1 ;
V_121 = sizeof( struct V_51 ) +
V_122 * sizeof( struct V_13 * ) ;
* V_91 = F_31 ( V_50 , V_121 , V_12 ) ;
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
int V_123 = 0 ;
if ( V_24 -> V_67 >= 0 )
return V_24 -> V_67 ;
F_75 ( V_24 , V_124 ) ;
switch ( V_24 -> V_20 ) {
case V_125 :
case V_126 :
case V_127 :
case V_46 :
return 0 ;
default:
break;
}
switch ( V_24 -> V_20 ) {
case V_128 :
case V_129 :
case V_130 :
if ( V_24 -> V_131 ) {
V_24 -> V_67 = F_70 ( V_24 ) ;
return V_24 -> V_67 ;
}
default:
break;
}
if ( V_24 -> V_132 ) {
if ( V_24 -> V_20 == V_22 && ! V_24 -> V_133 ) {
V_24 -> V_67 = F_70 ( V_24 ) ;
return V_24 -> V_67 ;
}
if ( V_24 -> V_20 == V_134 ||
V_24 -> V_20 == V_135 ||
( V_24 -> V_20 == V_136 &&
! F_11 ( & V_24 -> V_93 ) ) ) {
V_24 -> V_67 = F_70 ( V_24 ) ;
return V_24 -> V_67 ;
}
}
F_17 (path, &widget->sinks, list_source) {
F_75 ( V_24 , V_137 ) ;
if ( V_57 -> V_138 )
continue;
if ( V_57 -> V_139 )
return 1 ;
if ( V_57 -> V_117 )
continue;
F_76 ( V_24 , V_57 ) ;
if ( V_57 -> V_116 && V_57 -> V_96 ) {
V_57 -> V_117 = 1 ;
V_57 -> V_139 = 1 ;
if ( V_91 ) {
int V_140 ;
V_140 = F_73 ( V_91 , V_57 -> V_116 ) ;
if ( V_140 < 0 ) {
F_23 ( V_24 -> V_2 -> V_8 ,
L_13 ,
V_24 -> V_17 ) ;
V_57 -> V_139 = 0 ;
return V_123 ;
}
}
V_123 += F_74 ( V_57 -> V_116 , V_91 ) ;
V_57 -> V_139 = 0 ;
}
}
V_24 -> V_67 = V_123 ;
return V_123 ;
}
static int F_77 ( struct V_13 * V_24 ,
struct V_51 * * V_91 )
{
struct V_56 * V_57 ;
int V_123 = 0 ;
if ( V_24 -> V_66 >= 0 )
return V_24 -> V_66 ;
F_75 ( V_24 , V_124 ) ;
switch ( V_24 -> V_20 ) {
case V_125 :
case V_126 :
case V_127 :
case V_46 :
return 0 ;
default:
break;
}
switch ( V_24 -> V_20 ) {
case V_141 :
case V_142 :
case V_143 :
if ( V_24 -> V_131 ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
default:
break;
}
if ( V_24 -> V_132 ) {
if ( V_24 -> V_20 == V_21 && ! V_24 -> V_133 ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
if ( V_24 -> V_20 == V_144 ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
if ( V_24 -> V_20 == V_145 ||
( V_24 -> V_20 == V_136 &&
! F_11 ( & V_24 -> V_95 ) ) ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
if ( V_24 -> V_20 == V_146 ) {
V_24 -> V_66 = F_70 ( V_24 ) ;
return V_24 -> V_66 ;
}
}
F_17 (path, &widget->sources, list_sink) {
F_75 ( V_24 , V_137 ) ;
if ( V_57 -> V_138 )
continue;
if ( V_57 -> V_139 )
return 1 ;
if ( V_57 -> V_117 )
continue;
F_78 ( V_24 , V_57 ) ;
if ( V_57 -> V_59 && V_57 -> V_96 ) {
V_57 -> V_117 = 1 ;
V_57 -> V_139 = 1 ;
if ( V_91 ) {
int V_140 ;
V_140 = F_73 ( V_91 , V_57 -> V_59 ) ;
if ( V_140 < 0 ) {
F_23 ( V_24 -> V_2 -> V_8 ,
L_13 ,
V_24 -> V_17 ) ;
V_57 -> V_139 = 0 ;
return V_123 ;
}
}
V_123 += F_77 ( V_57 -> V_59 , V_91 ) ;
V_57 -> V_139 = 0 ;
}
}
V_24 -> V_66 = V_123 ;
return V_123 ;
}
int F_79 ( struct V_147 * V_148 , int V_149 ,
struct V_51 * * V_91 )
{
struct V_19 * V_3 = V_148 -> V_3 ;
int V_32 ;
F_80 ( & V_3 -> V_5 , V_150 ) ;
F_41 ( V_3 ) ;
if ( V_149 == V_151 ) {
V_32 = F_74 ( V_148 -> V_152 , V_91 ) ;
F_68 ( & V_3 -> V_2 ,
& V_148 -> V_152 -> V_95 ) ;
} else {
V_32 = F_77 ( V_148 -> V_153 , V_91 ) ;
F_69 ( & V_3 -> V_2 ,
& V_148 -> V_153 -> V_93 ) ;
}
F_81 ( V_32 , V_149 ) ;
F_18 ( & V_3 -> V_5 ) ;
return V_32 ;
}
int F_82 ( struct V_13 * V_14 ,
struct V_25 * V_26 , int V_154 )
{
int V_73 ;
F_49 ( V_14 -> V_2 ) ;
if ( F_83 ( V_154 ) ) {
if ( V_14 -> V_45 & V_155 ) {
V_73 = F_84 ( V_14 -> V_156 , false ) ;
if ( V_73 != 0 )
F_85 ( V_14 -> V_2 -> V_8 ,
L_14 ,
V_14 -> V_17 , V_73 ) ;
}
return F_86 ( V_14 -> V_156 ) ;
} else {
if ( V_14 -> V_45 & V_155 ) {
V_73 = F_84 ( V_14 -> V_156 , true ) ;
if ( V_73 != 0 )
F_85 ( V_14 -> V_2 -> V_8 ,
L_15 ,
V_14 -> V_17 , V_73 ) ;
}
return F_87 ( V_14 -> V_156 , V_14 -> V_42 ) ;
}
}
int F_88 ( struct V_13 * V_14 ,
struct V_25 * V_26 , int V_154 )
{
if ( ! V_14 -> V_157 )
return - V_70 ;
F_49 ( V_14 -> V_2 ) ;
#ifdef F_89
if ( F_83 ( V_154 ) ) {
return F_90 ( V_14 -> V_157 ) ;
} else {
F_91 ( V_14 -> V_157 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_92 ( struct V_13 * V_14 )
{
if ( V_14 -> V_65 )
return V_14 -> V_64 ;
if ( V_14 -> V_158 )
V_14 -> V_64 = 1 ;
else
V_14 -> V_64 = V_14 -> V_159 ( V_14 ) ;
V_14 -> V_65 = true ;
return V_14 -> V_64 ;
}
static int F_93 ( struct V_13 * V_14 )
{
int V_160 , V_75 ;
F_75 ( V_14 , V_161 ) ;
V_160 = F_77 ( V_14 , NULL ) ;
F_69 ( V_14 -> V_2 , & V_14 -> V_93 ) ;
V_75 = F_74 ( V_14 , NULL ) ;
F_68 ( V_14 -> V_2 , & V_14 -> V_95 ) ;
return V_75 != 0 && V_160 != 0 ;
}
static int F_94 ( struct V_13 * V_14 )
{
int V_160 ;
F_75 ( V_14 , V_161 ) ;
if ( V_14 -> V_131 ) {
V_160 = F_77 ( V_14 , NULL ) ;
F_69 ( V_14 -> V_2 , & V_14 -> V_93 ) ;
return V_160 != 0 ;
} else {
return F_93 ( V_14 ) ;
}
}
static int F_95 ( struct V_13 * V_14 )
{
int V_75 ;
F_75 ( V_14 , V_161 ) ;
if ( V_14 -> V_131 ) {
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
F_75 ( V_14 , V_161 ) ;
F_17 (path, &w->sinks, list_source) {
F_75 ( V_14 , V_137 ) ;
if ( V_57 -> V_138 )
continue;
if ( V_57 -> V_132 &&
! V_57 -> V_132 ( V_57 -> V_59 , V_57 -> V_116 ) )
continue;
if ( ! V_57 -> V_116 )
continue;
if ( F_92 ( V_57 -> V_116 ) )
return 1 ;
}
return 0 ;
}
static int F_97 ( struct V_13 * V_14 )
{
return 1 ;
}
static int F_98 ( struct V_13 * V_162 ,
struct V_13 * V_163 ,
bool V_164 )
{
int * V_165 ;
if ( V_164 )
V_165 = V_166 ;
else
V_165 = V_167 ;
if ( V_165 [ V_162 -> V_20 ] != V_165 [ V_163 -> V_20 ] )
return V_165 [ V_162 -> V_20 ] - V_165 [ V_163 -> V_20 ] ;
if ( V_162 -> V_168 != V_163 -> V_168 ) {
if ( V_164 )
return V_162 -> V_168 - V_163 -> V_168 ;
else
return V_163 -> V_168 - V_162 -> V_168 ;
}
if ( V_162 -> V_39 != V_163 -> V_39 )
return V_162 -> V_39 - V_163 -> V_39 ;
if ( V_162 -> V_2 != V_163 -> V_2 )
return ( unsigned long ) V_162 -> V_2 - ( unsigned long ) V_163 -> V_2 ;
return 0 ;
}
static void F_99 ( struct V_13 * V_169 ,
struct V_61 * V_91 ,
bool V_164 )
{
struct V_13 * V_14 ;
F_17 (w, list, power_list)
if ( F_98 ( V_169 , V_14 , V_164 ) < 0 ) {
F_14 ( & V_169 -> V_170 , & V_14 -> V_170 ) ;
return;
}
F_14 ( & V_169 -> V_170 , V_91 ) ;
}
static void F_100 ( struct V_19 * V_3 ,
struct V_13 * V_14 , int V_154 )
{
const char * V_171 ;
int V_60 , V_73 ;
switch ( V_154 ) {
case V_172 :
V_171 = L_16 ;
V_60 = 1 ;
break;
case V_173 :
V_171 = L_17 ;
V_60 = 1 ;
break;
case V_174 :
V_171 = L_18 ;
V_60 = 0 ;
break;
case V_175 :
V_171 = L_19 ;
V_60 = 0 ;
break;
case V_176 :
V_171 = L_20 ;
V_60 = 1 ;
break;
case V_177 :
V_171 = L_21 ;
V_60 = 0 ;
break;
default:
F_101 ( 1 , L_22 , V_154 ) ;
return;
}
if ( V_14 -> V_64 != V_60 )
return;
if ( V_14 -> V_154 && ( V_14 -> V_178 & V_154 ) ) {
F_6 ( V_14 -> V_2 -> V_8 , V_3 -> V_6 , L_23 ,
V_14 -> V_17 , V_171 ) ;
F_49 ( V_14 -> V_2 ) ;
F_102 ( V_14 , V_154 ) ;
V_73 = V_14 -> V_154 ( V_14 , NULL , V_154 ) ;
F_103 ( V_14 , V_154 ) ;
if ( V_73 < 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_24 ,
V_171 , V_14 -> V_17 , V_73 ) ;
}
}
static void F_104 ( struct V_19 * V_3 ,
struct V_61 * V_179 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
int V_39 ;
unsigned int V_47 = 0 ;
unsigned int V_40 = 0 ;
V_14 = F_105 ( V_179 , struct V_13 , V_170 ) ;
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
F_100 ( V_3 , V_14 , V_172 ) ;
F_100 ( V_3 , V_14 , V_174 ) ;
}
if ( V_39 >= 0 ) {
F_6 ( V_2 -> V_8 , V_3 -> V_6 ,
L_26 ,
V_47 , V_40 , V_39 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_45 ( V_2 , V_39 , V_40 , V_47 ) ;
}
F_17 (w, pending, power_list) {
F_100 ( V_3 , V_14 , V_173 ) ;
F_100 ( V_3 , V_14 , V_175 ) ;
}
}
static void F_107 ( struct V_19 * V_3 ,
struct V_61 * V_91 , int V_154 , bool V_164 )
{
struct V_13 * V_14 , * V_53 ;
struct V_1 * V_180 ;
F_108 ( V_179 ) ;
int V_181 = - 1 ;
int V_182 = - 1 ;
int V_183 = V_87 ;
struct V_1 * V_184 = NULL ;
int V_73 , V_86 ;
int * V_165 ;
if ( V_164 )
V_165 = V_166 ;
else
V_165 = V_167 ;
F_109 (w, n, list, power_list) {
V_73 = 0 ;
if ( V_165 [ V_14 -> V_20 ] != V_181 || V_14 -> V_39 != V_183 ||
V_14 -> V_2 != V_184 || V_14 -> V_168 != V_182 ) {
if ( ! F_11 ( & V_179 ) )
F_104 ( V_3 , & V_179 ) ;
if ( V_184 && V_184 -> V_185 ) {
for ( V_86 = 0 ; V_86 < F_110 ( V_166 ) ; V_86 ++ )
if ( V_165 [ V_86 ] == V_181 )
V_184 -> V_185 ( V_184 ,
V_86 ,
V_182 ) ;
}
if ( V_184 && V_14 -> V_2 != V_184 )
F_49 ( V_184 ) ;
F_24 ( & V_179 ) ;
V_181 = - 1 ;
V_182 = V_186 ;
V_183 = V_87 ;
V_184 = NULL ;
}
switch ( V_14 -> V_20 ) {
case V_187 :
if ( ! V_14 -> V_154 )
F_111 ( V_14 , V_53 , V_91 ,
V_170 ) ;
if ( V_154 == V_188 )
V_73 = V_14 -> V_154 ( V_14 ,
NULL , V_172 ) ;
else if ( V_154 == V_189 )
V_73 = V_14 -> V_154 ( V_14 ,
NULL , V_174 ) ;
break;
case V_190 :
if ( ! V_14 -> V_154 )
F_111 ( V_14 , V_53 , V_91 ,
V_170 ) ;
if ( V_154 == V_188 )
V_73 = V_14 -> V_154 ( V_14 ,
NULL , V_173 ) ;
else if ( V_154 == V_189 )
V_73 = V_14 -> V_154 ( V_14 ,
NULL , V_175 ) ;
break;
default:
V_181 = V_165 [ V_14 -> V_20 ] ;
V_182 = V_14 -> V_168 ;
V_183 = V_14 -> V_39 ;
V_184 = V_14 -> V_2 ;
F_112 ( & V_14 -> V_170 , & V_179 ) ;
break;
}
if ( V_73 < 0 )
F_23 ( V_14 -> V_2 -> V_8 ,
L_27 , V_73 ) ;
}
if ( ! F_11 ( & V_179 ) )
F_104 ( V_3 , & V_179 ) ;
if ( V_184 && V_184 -> V_185 ) {
for ( V_86 = 0 ; V_86 < F_110 ( V_166 ) ; V_86 ++ )
if ( V_165 [ V_86 ] == V_181 )
V_184 -> V_185 ( V_184 ,
V_86 , V_182 ) ;
}
F_17 (d, &card->dapm_list, list) {
F_49 ( V_180 ) ;
}
}
static void F_113 ( struct V_19 * V_3 )
{
struct V_191 * V_192 = V_3 -> V_192 ;
struct V_51 * V_50 ;
struct V_13 * V_14 = NULL ;
unsigned int V_193 ;
int V_73 ;
if ( ! V_192 || ! F_34 ( V_192 -> V_26 ) )
return;
V_50 = F_29 ( V_192 -> V_26 ) ;
for ( V_193 = 0 ; V_193 < V_50 -> V_54 ; V_193 ++ ) {
V_14 = V_50 -> V_55 [ V_193 ] ;
if ( V_14 -> V_154 && ( V_14 -> V_178 & V_194 ) ) {
V_73 = V_14 -> V_154 ( V_14 , V_192 -> V_26 , V_194 ) ;
if ( V_73 != 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_28 ,
V_14 -> V_17 , V_73 ) ;
}
}
if ( ! V_14 )
return;
V_73 = F_45 ( V_14 -> V_2 , V_192 -> V_39 , V_192 -> V_40 ,
V_192 -> V_84 ) ;
if ( V_73 < 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_29 ,
V_14 -> V_17 , V_73 ) ;
for ( V_193 = 0 ; V_193 < V_50 -> V_54 ; V_193 ++ ) {
V_14 = V_50 -> V_55 [ V_193 ] ;
if ( V_14 -> V_154 && ( V_14 -> V_178 & V_195 ) ) {
V_73 = V_14 -> V_154 ( V_14 , V_192 -> V_26 , V_195 ) ;
if ( V_73 != 0 )
F_23 ( V_14 -> V_2 -> V_8 , L_30 ,
V_14 -> V_17 , V_73 ) ;
}
}
}
static void F_114 ( void * V_28 , T_4 V_196 )
{
struct V_1 * V_180 = V_28 ;
int V_73 ;
if ( V_180 -> V_76 == V_197 &&
V_180 -> V_198 != V_197 ) {
if ( V_180 -> V_8 )
F_115 ( V_180 -> V_8 ) ;
V_73 = F_51 ( V_180 , V_199 ) ;
if ( V_73 != 0 )
F_23 ( V_180 -> V_8 ,
L_31 , V_73 ) ;
}
if ( ( V_180 -> V_198 == V_200 &&
V_180 -> V_76 != V_200 ) ||
( V_180 -> V_198 != V_200 &&
V_180 -> V_76 == V_200 ) ) {
V_73 = F_51 ( V_180 , V_201 ) ;
if ( V_73 != 0 )
F_23 ( V_180 -> V_8 ,
L_32 , V_73 ) ;
}
}
static void F_116 ( void * V_28 , T_4 V_196 )
{
struct V_1 * V_180 = V_28 ;
int V_73 ;
if ( V_180 -> V_76 == V_201 &&
( V_180 -> V_198 == V_199 ||
V_180 -> V_198 == V_197 ) ) {
V_73 = F_51 ( V_180 , V_199 ) ;
if ( V_73 != 0 )
F_23 ( V_180 -> V_8 , L_33 ,
V_73 ) ;
}
if ( V_180 -> V_76 == V_199 &&
V_180 -> V_198 == V_197 ) {
V_73 = F_51 ( V_180 , V_197 ) ;
if ( V_73 != 0 )
F_23 ( V_180 -> V_8 , L_34 ,
V_73 ) ;
if ( V_180 -> V_8 )
F_117 ( V_180 -> V_8 ) ;
}
if ( V_180 -> V_76 == V_201 &&
V_180 -> V_198 == V_200 ) {
V_73 = F_51 ( V_180 , V_200 ) ;
if ( V_73 != 0 )
F_23 ( V_180 -> V_8 , L_35 ,
V_73 ) ;
}
}
static void F_118 ( struct V_13 * V_202 ,
bool V_60 , bool V_96 )
{
if ( ! V_96 )
return;
if ( V_60 != V_202 -> V_60 )
F_12 ( V_202 , L_36 ) ;
}
static void F_119 ( struct V_13 * V_14 , bool V_60 ,
struct V_61 * V_203 ,
struct V_61 * V_204 )
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
case V_125 :
case V_126 :
case V_127 :
case V_46 :
break;
default:
F_17 (path, &w->sinks, list_source) {
if ( V_57 -> V_116 ) {
F_118 ( V_57 -> V_116 , V_60 ,
V_57 -> V_96 ) ;
}
}
break;
}
if ( V_60 )
F_99 ( V_14 , V_203 , true ) ;
else
F_99 ( V_14 , V_204 , false ) ;
}
static void F_121 ( struct V_13 * V_14 ,
struct V_61 * V_203 ,
struct V_61 * V_204 )
{
int V_60 ;
switch ( V_14 -> V_20 ) {
case V_187 :
F_99 ( V_14 , V_204 , false ) ;
break;
case V_190 :
F_99 ( V_14 , V_203 , true ) ;
break;
default:
V_60 = F_92 ( V_14 ) ;
F_119 ( V_14 , V_60 , V_203 , V_204 ) ;
break;
}
}
static bool F_122 ( struct V_1 * V_2 )
{
if ( V_2 -> V_205 )
return true ;
switch ( F_71 ( V_2 -> V_3 -> V_105 ) ) {
case V_118 :
case V_119 :
return V_2 -> V_206 ;
default:
break;
}
return false ;
}
static int F_123 ( struct V_19 * V_3 , int V_154 )
{
struct V_13 * V_14 ;
struct V_1 * V_180 ;
F_108 ( V_203 ) ;
F_108 ( V_204 ) ;
F_124 ( V_207 ) ;
enum V_71 V_208 ;
F_2 ( & V_3 -> V_5 ) ;
F_125 ( V_3 ) ;
F_17 (d, &card->dapm_list, list) {
if ( F_122 ( V_180 ) )
V_180 -> V_198 = V_197 ;
else
V_180 -> V_198 = V_199 ;
}
F_41 ( V_3 ) ;
F_17 (w, &card->dapm_dirty, dirty) {
F_121 ( V_14 , & V_203 , & V_204 ) ;
}
F_17 (w, &card->widgets, list) {
switch ( V_14 -> V_20 ) {
case V_187 :
case V_190 :
break;
default:
F_126 ( & V_14 -> V_15 ) ;
break;
}
if ( V_14 -> V_64 ) {
V_180 = V_14 -> V_2 ;
switch ( V_14 -> V_20 ) {
case V_146 :
case V_144 :
break;
case V_125 :
case V_126 :
case V_127 :
case V_209 :
if ( V_180 -> V_198 < V_199 )
V_180 -> V_198 = V_199 ;
break;
default:
V_180 -> V_198 = V_200 ;
break;
}
}
}
V_208 = V_197 ;
F_17 (d, &card->dapm_list, list)
if ( V_180 -> V_198 > V_208 )
V_208 = V_180 -> V_198 ;
F_17 (d, &card->dapm_list, list)
if ( ! F_122 ( V_180 ) )
V_180 -> V_198 = V_208 ;
F_127 ( V_3 ) ;
F_114 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_180 != & V_3 -> V_2 )
F_128 ( F_114 , V_180 ,
& V_207 ) ;
}
F_129 ( & V_207 ) ;
F_17 (w, &down_list, power_list) {
F_100 ( V_3 , V_14 , V_177 ) ;
}
F_17 (w, &up_list, power_list) {
F_100 ( V_3 , V_14 , V_176 ) ;
}
F_107 ( V_3 , & V_204 , V_154 , false ) ;
F_113 ( V_3 ) ;
F_107 ( V_3 , & V_203 , V_154 , true ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_180 != & V_3 -> V_2 )
F_128 ( F_116 , V_180 ,
& V_207 ) ;
}
F_129 ( & V_207 ) ;
F_116 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_180 -> V_210 )
V_180 -> V_210 ( V_180 , V_154 ) ;
}
F_6 ( V_3 -> V_8 , V_3 -> V_6 ,
L_37 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_130 ( V_3 ) ;
return 0 ;
}
static T_5 F_131 ( struct V_211 * V_211 ,
char T_6 * V_212 ,
T_3 V_213 , T_7 * V_214 )
{
struct V_13 * V_14 = V_211 -> V_48 ;
char * V_10 ;
int V_160 , V_75 ;
T_5 V_73 ;
struct V_56 * V_98 = NULL ;
V_10 = F_7 ( V_11 , V_12 ) ;
if ( ! V_10 )
return - V_31 ;
V_160 = F_77 ( V_14 , NULL ) ;
F_69 ( V_14 -> V_2 , & V_14 -> V_93 ) ;
V_75 = F_74 ( V_14 , NULL ) ;
F_68 ( V_14 -> V_2 , & V_14 -> V_95 ) ;
V_73 = snprintf ( V_10 , V_11 , L_38 ,
V_14 -> V_17 , V_14 -> V_60 ? L_39 : L_40 ,
V_14 -> V_158 ? L_41 : L_42 , V_160 , V_75 ) ;
if ( V_14 -> V_39 >= 0 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 ,
L_43 ,
V_14 -> V_39 , V_14 -> V_39 , V_14 -> V_40 << V_14 -> V_42 ) ;
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 , L_44 ) ;
if ( V_14 -> V_215 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 , L_45 ,
V_14 -> V_215 ,
V_14 -> V_131 ? L_46 : L_47 ) ;
F_17 (p, &w->sources, list_sink) {
if ( V_98 -> V_132 && ! V_98 -> V_132 ( V_14 , V_98 -> V_59 ) )
continue;
if ( V_98 -> V_96 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 ,
L_48 ,
V_98 -> V_17 ? V_98 -> V_17 : L_49 ,
V_98 -> V_59 -> V_17 ) ;
}
F_17 (p, &w->sinks, list_source) {
if ( V_98 -> V_132 && ! V_98 -> V_132 ( V_14 , V_98 -> V_116 ) )
continue;
if ( V_98 -> V_96 )
V_73 += snprintf ( V_10 + V_73 , V_11 - V_73 ,
L_50 ,
V_98 -> V_17 ? V_98 -> V_17 : L_49 ,
V_98 -> V_116 -> V_17 ) ;
}
V_73 = F_132 ( V_212 , V_213 , V_214 , V_10 , V_73 ) ;
F_9 ( V_10 ) ;
return V_73 ;
}
static T_5 F_133 ( struct V_211 * V_211 , char T_6 * V_212 ,
T_3 V_213 , T_7 * V_214 )
{
struct V_1 * V_2 = V_211 -> V_48 ;
char * V_72 ;
switch ( V_2 -> V_76 ) {
case V_200 :
V_72 = L_51 ;
break;
case V_201 :
V_72 = L_52 ;
break;
case V_199 :
V_72 = L_53 ;
break;
case V_197 :
V_72 = L_54 ;
break;
default:
F_101 ( 1 , L_55 , V_2 -> V_76 ) ;
V_72 = L_56 ;
break;
}
return F_132 ( V_212 , V_213 , V_214 , V_72 ,
strlen ( V_72 ) ) ;
}
void F_134 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
struct V_216 * V_180 ;
V_2 -> V_218 = F_135 ( L_57 , V_217 ) ;
if ( ! V_2 -> V_218 ) {
F_85 ( V_2 -> V_8 ,
L_58 ) ;
return;
}
V_180 = F_136 ( L_59 , 0444 ,
V_2 -> V_218 , V_2 ,
& V_219 ) ;
if ( ! V_180 )
F_85 ( V_2 -> V_8 ,
L_60 ) ;
}
static void F_137 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_216 * V_180 ;
if ( ! V_2 -> V_218 || ! V_14 -> V_17 )
return;
V_180 = F_136 ( V_14 -> V_17 , 0444 ,
V_2 -> V_218 , V_14 ,
& V_220 ) ;
if ( ! V_180 )
F_85 ( V_14 -> V_2 -> V_8 ,
L_61 ,
V_14 -> V_17 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
F_139 ( V_2 -> V_218 ) ;
}
void F_134 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
}
static inline void F_137 ( struct V_13 * V_14 )
{
}
static inline void F_138 ( struct V_1 * V_2 )
{
}
static int F_140 ( struct V_19 * V_3 ,
struct V_25 * V_26 , int V_221 , struct V_82 * V_83 )
{
struct V_56 * V_57 ;
int V_222 = 0 ;
F_2 ( & V_3 -> V_5 ) ;
F_141 (path, kcontrol) {
if ( ! V_57 -> V_17 || ! V_83 -> V_90 [ V_221 ] )
continue;
V_222 = 1 ;
if ( ! ( strcmp ( V_57 -> V_17 , V_83 -> V_90 [ V_221 ] ) ) ) {
V_57 -> V_96 = 1 ;
F_12 ( V_57 -> V_59 , L_62 ) ;
} else {
if ( V_57 -> V_96 )
F_12 ( V_57 -> V_59 ,
L_63 ) ;
V_57 -> V_96 = 0 ;
}
F_12 ( V_57 -> V_116 , L_64 ) ;
}
if ( V_222 )
F_123 ( V_3 , V_223 ) ;
return V_222 ;
}
int F_142 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_221 , struct V_82 * V_83 ,
struct V_191 * V_192 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
int V_73 ;
F_80 ( & V_3 -> V_5 , V_150 ) ;
V_3 -> V_192 = V_192 ;
V_73 = F_140 ( V_3 , V_26 , V_221 , V_83 ) ;
V_3 -> V_192 = NULL ;
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_143 ( V_3 ) ;
return V_73 ;
}
static int F_144 ( struct V_19 * V_3 ,
struct V_25 * V_26 , int V_96 )
{
struct V_56 * V_57 ;
int V_222 = 0 ;
F_2 ( & V_3 -> V_5 ) ;
F_141 (path, kcontrol) {
V_222 = 1 ;
V_57 -> V_96 = V_96 ;
F_12 ( V_57 -> V_59 , L_65 ) ;
F_12 ( V_57 -> V_116 , L_66 ) ;
}
if ( V_222 )
F_123 ( V_3 , V_223 ) ;
return V_222 ;
}
int F_145 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_96 ,
struct V_191 * V_192 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
int V_73 ;
F_80 ( & V_3 -> V_5 , V_150 ) ;
V_3 -> V_192 = V_192 ;
V_73 = F_144 ( V_3 , V_26 , V_96 ) ;
V_3 -> V_192 = NULL ;
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_143 ( V_3 ) ;
return V_73 ;
}
static T_5 F_146 ( struct V_62 * V_224 , char * V_10 )
{
struct V_13 * V_14 ;
int V_213 = 0 ;
char * V_225 = L_67 ;
F_17 (w, &codec->component.card->widgets, list) {
if ( V_14 -> V_2 != & V_224 -> V_2 )
continue;
switch ( V_14 -> V_20 ) {
case V_134 :
case V_145 :
case V_135 :
case V_136 :
case V_209 :
case V_141 :
case V_128 :
case V_226 :
case V_227 :
case V_34 :
case V_35 :
case V_125 :
case V_126 :
case V_127 :
if ( V_14 -> V_17 )
V_213 += sprintf ( V_10 + V_213 , L_68 ,
V_14 -> V_17 , V_14 -> V_60 ? L_39 : L_40 ) ;
break;
default:
break;
}
}
switch ( V_224 -> V_2 . V_76 ) {
case V_200 :
V_225 = L_39 ;
break;
case V_201 :
V_225 = L_69 ;
break;
case V_199 :
V_225 = L_70 ;
break;
case V_197 :
V_225 = L_40 ;
break;
}
V_213 += sprintf ( V_10 + V_213 , L_71 , V_225 ) ;
return V_213 ;
}
static T_5 F_147 ( struct V_7 * V_8 ,
struct V_228 * V_229 , char * V_10 )
{
struct V_230 * V_231 = F_148 ( V_8 ) ;
int V_86 , V_213 = 0 ;
for ( V_86 = 0 ; V_86 < V_231 -> V_232 ; V_86 ++ ) {
struct V_62 * V_224 = V_231 -> V_233 [ V_86 ] -> V_224 ;
V_213 += F_146 ( V_224 , V_10 + V_213 ) ;
}
return V_213 ;
}
int F_149 ( struct V_7 * V_8 )
{
return F_150 ( V_8 , & V_234 ) ;
}
static void F_151 ( struct V_7 * V_8 )
{
F_152 ( V_8 , & V_234 ) ;
}
static void F_153 ( struct V_56 * V_57 )
{
F_154 ( & V_57 -> V_92 ) ;
F_154 ( & V_57 -> V_94 ) ;
F_154 ( & V_57 -> V_58 ) ;
F_154 ( & V_57 -> V_91 ) ;
F_9 ( V_57 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_235 ;
struct V_56 * V_98 , * V_236 ;
F_109 (w, next_w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
F_154 ( & V_14 -> V_91 ) ;
F_109 (p, next_p, &w->sources, list_sink)
F_153 ( V_98 ) ;
F_109 (p, next_p, &w->sinks, list_source)
F_153 ( V_98 ) ;
F_9 ( V_14 -> V_103 ) ;
F_9 ( V_14 -> V_17 ) ;
F_9 ( V_14 ) ;
}
}
static struct V_13 * F_156 (
struct V_1 * V_2 , const char * V_237 ,
bool V_238 )
{
struct V_13 * V_14 ;
struct V_13 * V_239 = NULL ;
F_17 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_14 -> V_17 , V_237 ) ) {
if ( V_14 -> V_2 == V_2 )
return V_14 ;
else
V_239 = V_14 ;
}
}
if ( V_238 )
return V_239 ;
return NULL ;
}
static int F_157 ( struct V_1 * V_2 ,
const char * V_237 , int V_240 )
{
struct V_13 * V_14 = F_156 ( V_2 , V_237 , true ) ;
F_1 ( V_2 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_72 , V_237 ) ;
return - V_113 ;
}
if ( V_14 -> V_132 != V_240 )
F_12 ( V_14 , L_73 ) ;
V_14 -> V_132 = V_240 ;
if ( V_240 == 0 )
V_14 -> V_158 = 0 ;
return 0 ;
}
int F_158 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_3 -> V_4 )
return 0 ;
return F_123 ( V_2 -> V_3 , V_223 ) ;
}
int F_159 ( struct V_1 * V_2 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_150 ) ;
V_73 = F_158 ( V_2 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_13 * V_241 , struct V_13 * V_242 ,
const char * V_243 ,
int (* V_132)( struct V_13 * V_59 ,
struct V_13 * V_116 ) )
{
struct V_56 * V_57 ;
int V_73 ;
V_57 = F_22 ( sizeof( struct V_56 ) , V_12 ) ;
if ( ! V_57 )
return - V_31 ;
V_57 -> V_59 = V_241 ;
V_57 -> V_116 = V_242 ;
V_57 -> V_132 = V_132 ;
F_24 ( & V_57 -> V_91 ) ;
F_24 ( & V_57 -> V_58 ) ;
F_24 ( & V_57 -> V_94 ) ;
F_24 ( & V_57 -> V_92 ) ;
if ( V_242 -> V_20 == V_21 ) {
if ( V_241 -> V_20 == V_209 ||
V_241 -> V_20 == V_145 ||
V_241 -> V_20 == V_136 ||
V_241 -> V_20 == V_22 )
V_242 -> V_133 = 1 ;
}
if ( V_241 -> V_20 == V_22 ) {
if ( V_242 -> V_20 == V_135 ||
V_242 -> V_20 == V_134 ||
V_242 -> V_20 == V_136 ||
V_242 -> V_20 == V_21 )
V_241 -> V_133 = 1 ;
}
F_12 ( V_241 , L_74 ) ;
F_12 ( V_242 , L_74 ) ;
if ( V_243 == NULL ) {
F_56 ( & V_57 -> V_91 , & V_2 -> V_3 -> V_32 ) ;
F_56 ( & V_57 -> V_92 , & V_242 -> V_93 ) ;
F_56 ( & V_57 -> V_94 , & V_241 -> V_95 ) ;
V_57 -> V_96 = 1 ;
return 0 ;
}
switch ( V_242 -> V_20 ) {
case V_128 :
case V_141 :
case V_226 :
case V_227 :
case V_21 :
case V_22 :
case V_146 :
case V_209 :
case V_144 :
case V_187 :
case V_190 :
case V_125 :
case V_126 :
case V_127 :
case V_142 :
case V_129 :
case V_143 :
case V_130 :
case V_244 :
case V_46 :
F_56 ( & V_57 -> V_91 , & V_2 -> V_3 -> V_32 ) ;
F_56 ( & V_57 -> V_92 , & V_242 -> V_93 ) ;
F_56 ( & V_57 -> V_94 , & V_241 -> V_95 ) ;
V_57 -> V_96 = 1 ;
return 0 ;
case V_112 :
V_73 = F_54 ( V_2 , V_241 , V_242 , V_57 , V_243 ,
& V_242 -> V_99 [ 0 ] ) ;
if ( V_73 != 0 )
goto V_140;
break;
case V_33 :
case V_34 :
case V_35 :
V_73 = F_58 ( V_2 , V_241 , V_242 , V_57 , V_243 ) ;
if ( V_73 != 0 )
goto V_140;
break;
case V_134 :
case V_145 :
case V_136 :
case V_135 :
F_56 ( & V_57 -> V_91 , & V_2 -> V_3 -> V_32 ) ;
F_56 ( & V_57 -> V_92 , & V_242 -> V_93 ) ;
F_56 ( & V_57 -> V_94 , & V_241 -> V_95 ) ;
V_57 -> V_96 = 0 ;
return 0 ;
}
return 0 ;
V_140:
F_9 ( V_57 ) ;
return V_73 ;
}
static int F_160 ( struct V_1 * V_2 ,
const struct V_245 * V_246 )
{
struct V_13 * V_241 = NULL , * V_242 = NULL , * V_14 ;
struct V_13 * V_247 = NULL , * V_248 = NULL ;
const char * V_116 ;
const char * V_59 ;
char V_249 [ 80 ] ;
char V_250 [ 80 ] ;
const char * V_106 ;
int V_73 ;
V_106 = F_42 ( V_2 ) ;
if ( V_106 ) {
snprintf ( V_249 , sizeof( V_249 ) , L_5 ,
V_106 , V_246 -> V_116 ) ;
V_116 = V_249 ;
snprintf ( V_250 , sizeof( V_250 ) , L_5 ,
V_106 , V_246 -> V_59 ) ;
V_59 = V_250 ;
} else {
V_116 = V_246 -> V_116 ;
V_59 = V_246 -> V_59 ;
}
F_17 (w, &dapm->card->widgets, list) {
if ( ! V_242 && ! ( strcmp ( V_14 -> V_17 , V_116 ) ) ) {
V_248 = V_14 ;
if ( V_14 -> V_2 == V_2 )
V_242 = V_14 ;
continue;
}
if ( ! V_241 && ! ( strcmp ( V_14 -> V_17 , V_59 ) ) ) {
V_247 = V_14 ;
if ( V_14 -> V_2 == V_2 )
V_241 = V_14 ;
}
}
if ( ! V_242 )
V_242 = V_248 ;
if ( ! V_241 )
V_241 = V_247 ;
if ( V_241 == NULL ) {
F_23 ( V_2 -> V_8 , L_75 ,
V_246 -> V_59 ) ;
return - V_97 ;
}
if ( V_242 == NULL ) {
F_23 ( V_2 -> V_8 , L_76 ,
V_246 -> V_116 ) ;
return - V_97 ;
}
V_73 = F_33 ( V_2 , V_241 , V_242 , V_246 -> V_243 ,
V_246 -> V_132 ) ;
if ( V_73 )
goto V_140;
return 0 ;
V_140:
F_85 ( V_2 -> V_8 , L_77 ,
V_59 , V_246 -> V_243 , V_116 ) ;
return V_73 ;
}
static int F_161 ( struct V_1 * V_2 ,
const struct V_245 * V_246 )
{
struct V_56 * V_57 , * V_98 ;
const char * V_116 ;
const char * V_59 ;
char V_249 [ 80 ] ;
char V_250 [ 80 ] ;
const char * V_106 ;
if ( V_246 -> V_243 ) {
F_23 ( V_2 -> V_8 ,
L_78 ) ;
return - V_113 ;
}
V_106 = F_42 ( V_2 ) ;
if ( V_106 ) {
snprintf ( V_249 , sizeof( V_249 ) , L_5 ,
V_106 , V_246 -> V_116 ) ;
V_116 = V_249 ;
snprintf ( V_250 , sizeof( V_250 ) , L_5 ,
V_106 , V_246 -> V_59 ) ;
V_59 = V_250 ;
} else {
V_116 = V_246 -> V_116 ;
V_59 = V_246 -> V_59 ;
}
V_57 = NULL ;
F_17 (p, &dapm->card->paths, list) {
if ( strcmp ( V_98 -> V_59 -> V_17 , V_59 ) != 0 )
continue;
if ( strcmp ( V_98 -> V_116 -> V_17 , V_116 ) != 0 )
continue;
V_57 = V_98 ;
break;
}
if ( V_57 ) {
F_12 ( V_57 -> V_59 , L_79 ) ;
F_12 ( V_57 -> V_116 , L_79 ) ;
F_153 ( V_57 ) ;
} else {
F_85 ( V_2 -> V_8 , L_80 ,
V_59 , V_116 ) ;
}
return 0 ;
}
int F_162 ( struct V_1 * V_2 ,
const struct V_245 * V_246 , int V_251 )
{
int V_86 , V_252 , V_73 = 0 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_253 ) ;
for ( V_86 = 0 ; V_86 < V_251 ; V_86 ++ ) {
V_252 = F_160 ( V_2 , V_246 ) ;
if ( V_252 < 0 ) {
F_23 ( V_2 -> V_8 , L_81 ,
V_246 -> V_59 ,
V_246 -> V_243 ? V_246 -> V_243 : L_82 ,
V_246 -> V_116 ) ;
V_73 = V_252 ;
}
V_246 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_163 ( struct V_1 * V_2 ,
const struct V_245 * V_246 , int V_251 )
{
int V_86 , V_73 = 0 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_253 ) ;
for ( V_86 = 0 ; V_86 < V_251 ; V_86 ++ ) {
F_161 ( V_2 , V_246 ) ;
V_246 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
static int F_164 ( struct V_1 * V_2 ,
const struct V_245 * V_246 )
{
struct V_13 * V_59 = F_156 ( V_2 ,
V_246 -> V_59 ,
true ) ;
struct V_13 * V_116 = F_156 ( V_2 ,
V_246 -> V_116 ,
true ) ;
struct V_56 * V_57 ;
int V_213 = 0 ;
if ( ! V_59 ) {
F_23 ( V_2 -> V_8 , L_83 ,
V_246 -> V_59 ) ;
return - V_97 ;
}
if ( ! V_116 ) {
F_23 ( V_2 -> V_8 , L_84 ,
V_246 -> V_116 ) ;
return - V_97 ;
}
if ( V_246 -> V_243 || V_246 -> V_132 )
F_85 ( V_2 -> V_8 , L_85 ,
V_246 -> V_59 , V_246 -> V_116 ) ;
F_17 (path, &source->sinks, list_source) {
if ( V_57 -> V_116 == V_116 ) {
V_57 -> V_138 = 1 ;
V_213 ++ ;
}
}
if ( V_213 == 0 )
F_23 ( V_2 -> V_8 , L_86 ,
V_246 -> V_59 , V_246 -> V_116 ) ;
if ( V_213 > 1 )
F_85 ( V_2 -> V_8 , L_87 ,
V_213 , V_246 -> V_59 , V_246 -> V_116 ) ;
return 0 ;
}
int F_165 ( struct V_1 * V_2 ,
const struct V_245 * V_246 , int V_251 )
{
int V_86 , V_140 ;
int V_73 = 0 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_253 ) ;
for ( V_86 = 0 ; V_86 < V_251 ; V_86 ++ ) {
V_140 = F_164 ( V_2 , V_246 ) ;
if ( V_140 )
V_73 = V_140 ;
V_246 ++ ;
}
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_166 ( struct V_19 * V_3 )
{
struct V_13 * V_14 ;
unsigned int V_84 ;
F_80 ( & V_3 -> V_5 , V_253 ) ;
F_17 (w, &card->widgets, list)
{
if ( V_14 -> V_254 )
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
case V_226 :
case V_227 :
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
V_14 -> V_254 = 1 ;
F_12 ( V_14 , L_88 ) ;
F_137 ( V_14 ) ;
}
F_123 ( V_3 , V_223 ) ;
F_18 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_167 ( struct V_25 * V_26 ,
struct V_255 * V_256 )
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
if ( F_168 ( V_30 ) )
F_85 ( V_2 -> V_8 ,
L_89 ,
V_26 -> V_20 . V_17 ) ;
F_80 ( & V_3 -> V_5 , V_150 ) ;
if ( F_34 ( V_26 ) && V_39 != V_87 ) {
V_73 = F_43 ( V_2 , V_39 , & V_84 ) ;
V_84 = ( V_84 >> V_42 ) & V_40 ;
} else {
V_84 = F_36 ( V_26 ) ;
}
F_18 ( & V_3 -> V_5 ) ;
if ( V_43 )
V_256 -> V_47 . integer . V_47 [ 0 ] = V_41 - V_84 ;
else
V_256 -> V_47 . integer . V_47 [ 0 ] = V_84 ;
return V_73 ;
}
int F_169 ( struct V_25 * V_26 ,
struct V_255 * V_256 )
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
int V_96 , V_257 , V_258 = 0 ;
struct V_191 V_192 ;
int V_73 = 0 ;
if ( F_168 ( V_30 ) )
F_85 ( V_2 -> V_8 ,
L_89 ,
V_26 -> V_20 . V_17 ) ;
V_84 = ( V_256 -> V_47 . integer . V_47 [ 0 ] & V_40 ) ;
V_96 = ! ! V_84 ;
if ( V_43 )
V_84 = V_41 - V_84 ;
F_80 ( & V_3 -> V_5 , V_150 ) ;
V_257 = F_37 ( V_26 , V_84 ) ;
if ( V_39 != V_87 ) {
V_40 = V_40 << V_42 ;
V_84 = V_84 << V_42 ;
V_258 = F_47 ( V_2 , V_39 , V_40 , V_84 ) ;
}
if ( V_257 || V_258 ) {
if ( V_258 ) {
V_192 . V_26 = V_26 ;
V_192 . V_39 = V_39 ;
V_192 . V_40 = V_40 ;
V_192 . V_84 = V_84 ;
V_3 -> V_192 = & V_192 ;
}
V_257 |= V_258 ;
V_73 = F_144 ( V_3 , V_26 , V_96 ) ;
V_3 -> V_192 = NULL ;
}
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_143 ( V_3 ) ;
return V_257 ;
}
int F_170 ( struct V_25 * V_26 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = F_38 ( V_26 ) ;
struct V_82 * V_83 = (struct V_82 * ) V_26 -> V_36 ;
unsigned int V_259 , V_84 ;
if ( V_83 -> V_39 != V_87 ) {
int V_73 = F_43 ( V_2 , V_83 -> V_39 , & V_259 ) ;
if ( V_73 )
return V_73 ;
} else {
V_259 = F_36 ( V_26 ) ;
}
V_84 = ( V_259 >> V_83 -> V_88 ) & V_83 -> V_40 ;
V_256 -> V_47 . V_260 . V_85 [ 0 ] = F_55 ( V_83 , V_84 ) ;
if ( V_83 -> V_88 != V_83 -> V_261 ) {
V_84 = ( V_259 >> V_83 -> V_261 ) & V_83 -> V_40 ;
V_84 = F_55 ( V_83 , V_84 ) ;
V_256 -> V_47 . V_260 . V_85 [ 1 ] = V_84 ;
}
return 0 ;
}
int F_171 ( struct V_25 * V_26 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = F_38 ( V_26 ) ;
struct V_19 * V_3 = V_2 -> V_3 ;
struct V_82 * V_83 = (struct V_82 * ) V_26 -> V_36 ;
unsigned int * V_85 = V_256 -> V_47 . V_260 . V_85 ;
unsigned int V_84 , V_257 ;
unsigned int V_40 ;
struct V_191 V_192 ;
int V_73 = 0 ;
if ( V_85 [ 0 ] >= V_83 -> V_89 )
return - V_113 ;
V_84 = F_172 ( V_83 , V_85 [ 0 ] ) << V_83 -> V_88 ;
V_40 = V_83 -> V_40 << V_83 -> V_88 ;
if ( V_83 -> V_88 != V_83 -> V_261 ) {
if ( V_85 [ 1 ] > V_83 -> V_89 )
return - V_113 ;
V_84 |= F_172 ( V_83 , V_85 [ 1 ] ) << V_83 -> V_88 ;
V_40 |= V_83 -> V_40 << V_83 -> V_261 ;
}
F_80 ( & V_3 -> V_5 , V_150 ) ;
if ( V_83 -> V_39 != V_87 )
V_257 = F_47 ( V_2 , V_83 -> V_39 , V_40 , V_84 ) ;
else
V_257 = F_37 ( V_26 , V_84 ) ;
if ( V_257 ) {
if ( V_83 -> V_39 != V_87 ) {
V_192 . V_26 = V_26 ;
V_192 . V_39 = V_83 -> V_39 ;
V_192 . V_40 = V_40 ;
V_192 . V_84 = V_84 ;
V_3 -> V_192 = & V_192 ;
}
V_73 = F_140 ( V_3 , V_26 , V_85 [ 0 ] , V_83 ) ;
V_3 -> V_192 = NULL ;
}
F_18 ( & V_3 -> V_5 ) ;
if ( V_73 > 0 )
F_143 ( V_3 ) ;
return V_257 ;
}
int F_173 ( struct V_25 * V_26 ,
struct V_262 * V_263 )
{
V_263 -> type = V_264 ;
V_263 -> V_213 = 1 ;
V_263 -> V_47 . integer . V_265 = 0 ;
V_263 -> V_47 . integer . V_41 = 1 ;
return 0 ;
}
int F_174 ( struct V_25 * V_26 ,
struct V_255 * V_256 )
{
struct V_19 * V_3 = F_28 ( V_26 ) ;
const char * V_237 = ( const char * ) V_26 -> V_36 ;
F_80 ( & V_3 -> V_5 , V_150 ) ;
V_256 -> V_47 . integer . V_47 [ 0 ] =
F_175 ( & V_3 -> V_2 , V_237 ) ;
F_18 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_176 ( struct V_25 * V_26 ,
struct V_255 * V_256 )
{
struct V_19 * V_3 = F_28 ( V_26 ) ;
const char * V_237 = ( const char * ) V_26 -> V_36 ;
if ( V_256 -> V_47 . integer . V_47 [ 0 ] )
F_177 ( & V_3 -> V_2 , V_237 ) ;
else
F_178 ( & V_3 -> V_2 , V_237 ) ;
F_159 ( & V_3 -> V_2 ) ;
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
case V_126 :
V_14 -> V_156 = F_179 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_180 ( V_14 -> V_156 ) ) {
V_73 = F_181 ( V_14 -> V_156 ) ;
F_23 ( V_2 -> V_8 , L_90 ,
V_14 -> V_17 , V_73 ) ;
return NULL ;
}
if ( V_14 -> V_45 & V_155 ) {
V_73 = F_84 ( V_14 -> V_156 , true ) ;
if ( V_73 != 0 )
F_85 ( V_14 -> V_2 -> V_8 ,
L_15 ,
V_14 -> V_17 , V_73 ) ;
}
break;
case V_127 :
#ifdef F_182
V_14 -> V_157 = F_183 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_180 ( V_14 -> V_157 ) ) {
V_73 = F_181 ( V_14 -> V_157 ) ;
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
V_14 -> V_159 = F_93 ;
break;
case V_112 :
V_14 -> V_159 = F_93 ;
break;
case V_130 :
V_14 -> V_159 = F_94 ;
break;
case V_143 :
V_14 -> V_159 = F_95 ;
break;
case V_128 :
case V_129 :
case V_141 :
case V_142 :
case V_226 :
case V_227 :
case V_21 :
case V_22 :
case V_209 :
case V_135 :
case V_134 :
case V_145 :
case V_136 :
case V_244 :
V_14 -> V_159 = F_93 ;
break;
case V_125 :
case V_126 :
case V_127 :
case V_46 :
V_14 -> V_159 = F_96 ;
break;
default:
V_14 -> V_159 = F_97 ;
break;
}
V_14 -> V_2 = V_2 ;
if ( V_2 -> V_68 )
V_14 -> V_224 = V_2 -> V_68 -> V_224 ;
F_24 ( & V_14 -> V_93 ) ;
F_24 ( & V_14 -> V_95 ) ;
F_24 ( & V_14 -> V_91 ) ;
F_24 ( & V_14 -> V_15 ) ;
F_56 ( & V_14 -> V_91 , & V_2 -> V_3 -> V_55 ) ;
V_14 -> V_132 = 1 ;
return V_14 ;
}
int F_184 ( struct V_1 * V_2 ,
const struct V_13 * V_24 ,
int V_251 )
{
struct V_13 * V_14 ;
int V_86 ;
int V_73 = 0 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_253 ) ;
for ( V_86 = 0 ; V_86 < V_251 ; V_86 ++ ) {
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
static int F_185 ( struct V_13 * V_14 ,
struct V_25 * V_26 , int V_154 )
{
struct V_56 * V_266 , * V_267 ;
struct V_147 * V_59 , * V_116 ;
const struct V_268 * V_269 = V_14 -> V_270 ;
struct V_271 V_272 ;
struct V_273 * V_270 = NULL ;
T_8 V_9 ;
int V_73 ;
if ( F_106 ( ! V_269 ) ||
F_106 ( F_11 ( & V_14 -> V_93 ) || F_11 ( & V_14 -> V_95 ) ) )
return - V_113 ;
V_266 = F_105 ( & V_14 -> V_93 , struct V_56 ,
V_92 ) ;
V_267 = F_105 ( & V_14 -> V_95 , struct V_56 ,
V_94 ) ;
if ( F_106 ( ! V_266 || ! V_267 ) ||
F_106 ( ! V_267 -> V_59 || ! V_266 -> V_116 ) ||
F_106 ( ! V_266 -> V_59 || ! V_267 -> V_116 ) )
return - V_113 ;
V_59 = V_266 -> V_59 -> V_274 ;
V_116 = V_267 -> V_116 -> V_274 ;
if ( V_269 -> V_275 ) {
V_9 = F_186 ( V_269 -> V_275 ) - 1 ;
} else {
F_85 ( V_14 -> V_2 -> V_8 , L_92 ,
V_269 -> V_275 ) ;
V_9 = 0 ;
}
V_270 = F_22 ( sizeof( * V_270 ) , V_12 ) ;
if ( ! V_270 ) {
V_73 = - V_31 ;
goto V_75;
}
F_187 ( F_188 ( V_270 , V_276 ) , V_9 ) ;
F_189 ( V_270 , V_277 ) -> V_265 =
V_269 -> V_278 ;
F_189 ( V_270 , V_277 ) -> V_41 =
V_269 -> V_279 ;
F_189 ( V_270 , V_280 ) -> V_265
= V_269 -> V_281 ;
F_189 ( V_270 , V_280 ) -> V_41
= V_269 -> V_282 ;
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
switch ( V_154 ) {
case V_172 :
V_272 . V_149 = V_283 ;
V_73 = F_190 ( & V_272 , V_270 , V_59 ) ;
if ( V_73 < 0 )
goto V_75;
V_272 . V_149 = V_151 ;
V_73 = F_190 ( & V_272 , V_270 , V_116 ) ;
if ( V_73 < 0 )
goto V_75;
break;
case V_173 :
V_73 = F_191 ( V_116 , 0 ,
V_151 ) ;
if ( V_73 != 0 && V_73 != - V_284 )
F_85 ( V_116 -> V_8 , L_93 , V_73 ) ;
V_73 = 0 ;
break;
case V_174 :
V_73 = F_191 ( V_116 , 1 ,
V_151 ) ;
if ( V_73 != 0 && V_73 != - V_284 )
F_85 ( V_116 -> V_8 , L_94 , V_73 ) ;
V_73 = 0 ;
break;
default:
F_101 ( 1 , L_22 , V_154 ) ;
return - V_113 ;
}
V_75:
F_9 ( V_270 ) ;
return V_73 ;
}
int F_192 ( struct V_19 * V_3 ,
const struct V_268 * V_270 ,
struct V_13 * V_59 ,
struct V_13 * V_116 )
{
struct V_13 V_38 ;
struct V_13 * V_14 ;
T_3 V_285 ;
char * V_286 ;
int V_73 ;
V_285 = strlen ( V_59 -> V_17 ) + strlen ( V_116 -> V_17 ) + 2 ;
V_286 = F_193 ( V_3 -> V_8 , V_285 , V_12 ) ;
if ( ! V_286 )
return - V_31 ;
snprintf ( V_286 , V_285 , L_95 , V_59 -> V_17 , V_116 -> V_17 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_39 = V_87 ;
V_38 . V_20 = V_244 ;
V_38 . V_17 = V_286 ;
V_38 . V_154 = F_185 ;
V_38 . V_178 = V_172 | V_173 |
V_174 ;
F_72 ( V_3 -> V_8 , L_96 , V_286 ) ;
V_14 = F_26 ( & V_3 -> V_2 , & V_38 ) ;
if ( ! V_14 ) {
F_23 ( V_3 -> V_8 , L_97 ,
V_286 ) ;
return - V_31 ;
}
V_14 -> V_270 = V_270 ;
V_73 = F_33 ( & V_3 -> V_2 , V_59 , V_14 , NULL , NULL ) ;
if ( V_73 )
return V_73 ;
return F_33 ( & V_3 -> V_2 , V_14 , V_116 , NULL , NULL ) ;
}
int F_194 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_13 V_38 ;
struct V_13 * V_14 ;
F_106 ( V_2 -> V_8 != V_148 -> V_8 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_39 = V_87 ;
if ( V_148 -> V_287 -> V_288 . V_289 ) {
V_38 . V_20 = V_143 ;
V_38 . V_17 = V_148 -> V_287 -> V_288 . V_289 ;
V_38 . V_215 = V_148 -> V_287 -> V_288 . V_289 ;
F_72 ( V_148 -> V_8 , L_96 ,
V_38 . V_17 ) ;
V_14 = F_26 ( V_2 , & V_38 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_97 ,
V_148 -> V_287 -> V_288 . V_289 ) ;
return - V_31 ;
}
V_14 -> V_274 = V_148 ;
V_148 -> V_152 = V_14 ;
}
if ( V_148 -> V_287 -> V_290 . V_289 ) {
V_38 . V_20 = V_130 ;
V_38 . V_17 = V_148 -> V_287 -> V_290 . V_289 ;
V_38 . V_215 = V_148 -> V_287 -> V_290 . V_289 ;
F_72 ( V_148 -> V_8 , L_96 ,
V_38 . V_17 ) ;
V_14 = F_26 ( V_2 , & V_38 ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_97 ,
V_148 -> V_287 -> V_290 . V_289 ) ;
return - V_31 ;
}
V_14 -> V_274 = V_148 ;
V_148 -> V_153 = V_14 ;
}
return 0 ;
}
int F_195 ( struct V_19 * V_3 )
{
struct V_13 * V_291 , * V_14 ;
struct V_13 * V_78 , * V_116 ;
struct V_147 * V_148 ;
F_17 (dai_w, &card->widgets, list) {
switch ( V_291 -> V_20 ) {
case V_143 :
case V_130 :
break;
default:
continue;
}
V_148 = V_291 -> V_274 ;
F_17 (w, &card->widgets, list) {
if ( V_14 -> V_2 != V_291 -> V_2 )
continue;
switch ( V_14 -> V_20 ) {
case V_143 :
case V_130 :
continue;
default:
break;
}
if ( ! V_14 -> V_215 || ! strstr ( V_14 -> V_215 , V_291 -> V_17 ) )
continue;
if ( V_291 -> V_20 == V_143 ) {
V_78 = V_291 ;
V_116 = V_14 ;
} else {
V_78 = V_14 ;
V_116 = V_291 ;
}
F_72 ( V_148 -> V_8 , L_98 , V_78 -> V_17 , V_116 -> V_17 ) ;
F_33 ( V_14 -> V_2 , V_78 , V_116 , NULL , NULL ) ;
}
}
return 0 ;
}
static void F_196 ( struct V_19 * V_3 ,
struct V_230 * V_231 )
{
struct V_147 * V_292 = V_231 -> V_292 ;
struct V_13 * V_116 , * V_59 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_231 -> V_232 ; V_86 ++ ) {
struct V_147 * V_293 = V_231 -> V_233 [ V_86 ] ;
if ( F_197 ( V_293 ) ||
F_197 ( V_292 ) )
continue;
if ( V_293 -> V_152 && V_292 -> V_152 ) {
V_59 = V_292 -> V_152 ;
V_116 = V_293 -> V_152 ;
F_72 ( V_231 -> V_8 , L_99 ,
V_292 -> V_68 -> V_17 , V_59 -> V_17 ,
V_293 -> V_68 -> V_17 , V_116 -> V_17 ) ;
F_33 ( & V_3 -> V_2 , V_59 , V_116 ,
NULL , NULL ) ;
}
if ( V_293 -> V_153 && V_292 -> V_153 ) {
V_59 = V_293 -> V_153 ;
V_116 = V_292 -> V_153 ;
F_72 ( V_231 -> V_8 , L_99 ,
V_293 -> V_68 -> V_17 , V_59 -> V_17 ,
V_292 -> V_68 -> V_17 , V_116 -> V_17 ) ;
F_33 ( & V_3 -> V_2 , V_59 , V_116 ,
NULL , NULL ) ;
}
}
}
static void F_198 ( struct V_147 * V_148 , int V_149 ,
int V_154 )
{
struct V_13 * V_14 ;
if ( V_149 == V_151 )
V_14 = V_148 -> V_152 ;
else
V_14 = V_148 -> V_153 ;
if ( V_14 ) {
F_12 ( V_14 , L_100 ) ;
switch ( V_154 ) {
case V_188 :
V_14 -> V_131 = 1 ;
break;
case V_189 :
V_14 -> V_131 = 0 ;
break;
case V_294 :
case V_295 :
case V_296 :
case V_297 :
break;
}
}
}
void F_199 ( struct V_19 * V_3 )
{
struct V_230 * V_231 = V_3 -> V_231 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_3 -> V_298 ; V_86 ++ ) {
V_231 = & V_3 -> V_231 [ V_86 ] ;
if ( V_231 -> V_299 -> V_300 || V_231 -> V_299 -> V_270 )
continue;
F_196 ( V_3 , V_231 ) ;
}
}
static void F_200 ( struct V_230 * V_231 , int V_149 ,
int V_154 )
{
int V_86 ;
F_198 ( V_231 -> V_292 , V_149 , V_154 ) ;
for ( V_86 = 0 ; V_86 < V_231 -> V_232 ; V_86 ++ )
F_198 ( V_231 -> V_233 [ V_86 ] , V_149 , V_154 ) ;
F_123 ( V_231 -> V_3 , V_154 ) ;
}
void F_201 ( struct V_230 * V_231 , int V_149 ,
int V_154 )
{
struct V_19 * V_3 = V_231 -> V_3 ;
F_80 ( & V_3 -> V_5 , V_150 ) ;
F_200 ( V_231 , V_149 , V_154 ) ;
F_18 ( & V_3 -> V_5 ) ;
}
int F_202 ( struct V_1 * V_2 ,
const char * V_237 )
{
return F_157 ( V_2 , V_237 , 1 ) ;
}
int F_177 ( struct V_1 * V_2 , const char * V_237 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_150 ) ;
V_73 = F_157 ( V_2 , V_237 , 1 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_203 ( struct V_1 * V_2 ,
const char * V_237 )
{
struct V_13 * V_14 = F_156 ( V_2 , V_237 , true ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_101 , V_237 ) ;
return - V_113 ;
}
F_72 ( V_14 -> V_2 -> V_8 , L_102 , V_237 ) ;
V_14 -> V_132 = 1 ;
V_14 -> V_158 = 1 ;
F_12 ( V_14 , L_103 ) ;
return 0 ;
}
int F_204 ( struct V_1 * V_2 ,
const char * V_237 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_150 ) ;
V_73 = F_203 ( V_2 , V_237 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_205 ( struct V_1 * V_2 ,
const char * V_237 )
{
return F_157 ( V_2 , V_237 , 0 ) ;
}
int F_178 ( struct V_1 * V_2 ,
const char * V_237 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_150 ) ;
V_73 = F_157 ( V_2 , V_237 , 0 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_206 ( struct V_1 * V_2 ,
const char * V_237 )
{
return F_157 ( V_2 , V_237 , 0 ) ;
}
int F_207 ( struct V_1 * V_2 , const char * V_237 )
{
int V_73 ;
F_80 ( & V_2 -> V_3 -> V_5 , V_150 ) ;
V_73 = F_157 ( V_2 , V_237 , 0 ) ;
F_18 ( & V_2 -> V_3 -> V_5 ) ;
return V_73 ;
}
int F_175 ( struct V_1 * V_2 ,
const char * V_237 )
{
struct V_13 * V_14 = F_156 ( V_2 , V_237 , true ) ;
if ( V_14 )
return V_14 -> V_132 ;
return 0 ;
}
int F_208 ( struct V_1 * V_2 ,
const char * V_237 )
{
struct V_13 * V_14 = F_156 ( V_2 , V_237 , false ) ;
if ( ! V_14 ) {
F_23 ( V_2 -> V_8 , L_101 , V_237 ) ;
return - V_113 ;
}
V_14 -> V_120 = 1 ;
return 0 ;
}
static bool F_209 ( struct V_19 * V_3 ,
struct V_13 * V_14 )
{
struct V_56 * V_98 ;
F_17 (p, &card->paths, list) {
if ( ( V_98 -> V_59 == V_14 ) || ( V_98 -> V_116 == V_14 ) ) {
F_72 ( V_3 -> V_8 ,
L_104 ,
V_98 -> V_59 -> V_17 , V_98 -> V_59 -> V_20 , V_98 -> V_59 -> V_2 ,
V_98 -> V_116 -> V_17 , V_98 -> V_116 -> V_20 , V_98 -> V_116 -> V_2 ) ;
if ( V_98 -> V_59 -> V_2 != V_98 -> V_116 -> V_2 )
return true ;
if ( V_98 -> V_116 -> V_20 == V_21 ) {
switch ( V_98 -> V_59 -> V_20 ) {
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
void F_210 ( struct V_19 * V_3 )
{
struct V_13 * V_14 ;
F_72 ( V_3 -> V_8 , L_105 , & V_3 -> V_2 ) ;
F_17 (w, &card->widgets, list) {
switch ( V_14 -> V_20 ) {
case V_21 :
case V_22 :
case V_209 :
F_72 ( V_3 -> V_8 , L_106 ,
V_14 -> V_17 ) ;
if ( ! F_209 ( V_3 , V_14 ) ) {
F_72 ( V_3 -> V_8 ,
L_107 ) ;
F_207 ( V_14 -> V_2 , V_14 -> V_17 ) ;
}
break;
default:
break;
}
}
}
void F_211 ( struct V_1 * V_2 )
{
F_151 ( V_2 -> V_8 ) ;
F_138 ( V_2 ) ;
F_155 ( V_2 ) ;
F_154 ( & V_2 -> V_91 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
struct V_13 * V_14 ;
F_108 ( V_204 ) ;
int V_301 = 0 ;
F_16 ( & V_3 -> V_5 ) ;
F_17 (w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
if ( V_14 -> V_60 ) {
F_99 ( V_14 , & V_204 , false ) ;
V_14 -> V_60 = 0 ;
V_301 = 1 ;
}
}
if ( V_301 ) {
if ( V_2 -> V_76 == V_200 )
F_51 ( V_2 ,
V_201 ) ;
F_107 ( V_3 , & V_204 , 0 , false ) ;
if ( V_2 -> V_76 == V_201 )
F_51 ( V_2 ,
V_199 ) ;
}
F_18 ( & V_3 -> V_5 ) ;
}
void F_213 ( struct V_19 * V_3 )
{
struct V_1 * V_2 ;
F_17 (dapm, &card->dapm_list, list) {
if ( V_2 != & V_3 -> V_2 ) {
F_212 ( V_2 ) ;
if ( V_2 -> V_76 == V_199 )
F_51 ( V_2 ,
V_197 ) ;
}
}
F_212 ( & V_3 -> V_2 ) ;
if ( V_3 -> V_2 . V_76 == V_199 )
F_51 ( & V_3 -> V_2 ,
V_197 ) ;
}
