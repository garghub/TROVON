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
static void F_15 ( struct V_13 * V_14 )
{
struct V_13 * V_19 ;
struct V_20 * V_21 ;
F_16 ( V_22 ) ;
F_1 ( V_14 -> V_2 ) ;
if ( V_14 -> V_23 == - 1 )
return;
V_14 -> V_23 = - 1 ;
F_14 ( & V_14 -> V_24 , & V_22 ) ;
F_17 (w, &list, work_list) {
F_17 (p, &w->sinks, list_source) {
if ( V_21 -> V_25 || V_21 -> V_26 || ! V_21 -> V_27 )
continue;
V_19 = V_21 -> V_19 ;
if ( V_19 -> V_23 != - 1 ) {
V_19 -> V_23 = - 1 ;
F_14 ( & V_19 -> V_24 , & V_22 ) ;
}
}
}
}
static void F_18 ( struct V_13 * V_14 )
{
struct V_13 * V_28 ;
struct V_20 * V_21 ;
F_16 ( V_22 ) ;
F_1 ( V_14 -> V_2 ) ;
if ( V_14 -> V_29 == - 1 )
return;
V_14 -> V_29 = - 1 ;
F_14 ( & V_14 -> V_24 , & V_22 ) ;
F_17 (w, &list, work_list) {
F_17 (p, &w->sources, list_sink) {
if ( V_21 -> V_25 || V_21 -> V_26 || ! V_21 -> V_27 )
continue;
V_28 = V_21 -> V_28 ;
if ( V_28 -> V_29 != - 1 ) {
V_28 -> V_29 = - 1 ;
F_14 ( & V_28 -> V_24 , & V_22 ) ;
}
}
}
}
static void F_19 ( struct V_20 * V_21 )
{
if ( V_21 -> V_26 || V_21 -> V_25 )
return;
if ( V_21 -> V_28 -> V_23 != 0 )
F_15 ( V_21 -> V_19 ) ;
if ( V_21 -> V_19 -> V_29 != 0 )
F_18 ( V_21 -> V_28 ) ;
}
void F_20 ( struct V_30 * V_3 )
{
struct V_13 * V_14 ;
F_21 ( & V_3 -> V_5 ) ;
F_17 (w, &card->widgets, list) {
if ( V_14 -> V_31 || V_14 -> V_32 ) {
F_12 ( V_14 , L_3 ) ;
if ( V_14 -> V_31 )
F_18 ( V_14 ) ;
if ( V_14 -> V_32 )
F_15 ( V_14 ) ;
}
}
F_22 ( & V_3 -> V_5 ) ;
}
static inline struct V_13 * F_23 (
const struct V_13 * V_33 )
{
return F_24 ( V_33 , sizeof( * V_33 ) , V_12 ) ;
}
static int F_25 ( struct V_13 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_38 = F_26 ( sizeof( * V_38 ) , V_12 ) ;
if ( ! V_38 ) {
F_27 ( V_34 -> V_2 -> V_8 ,
L_4 ,
V_34 -> V_17 ) ;
return - V_41 ;
}
F_28 ( & V_38 -> V_42 ) ;
switch ( V_34 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
V_40 = (struct V_39 * ) V_36 -> V_47 ;
if ( V_40 -> V_48 ) {
struct V_13 V_49 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_50 = V_40 -> V_50 ;
V_49 . V_51 = ( 1 << F_29 ( V_40 -> V_52 ) ) - 1 ;
V_49 . V_53 = V_40 -> V_53 ;
if ( V_40 -> V_54 )
V_49 . V_55 = V_40 -> V_52 ;
else
V_49 . V_55 = 0 ;
V_49 . V_56 = V_49 . V_55 ;
V_49 . V_43 = V_57 ;
V_49 . V_17 = V_36 -> V_43 . V_17 ;
V_38 -> V_58 = V_49 . V_56 ;
V_38 -> V_34 = F_30 ( V_34 -> V_2 ,
& V_49 ) ;
if ( ! V_38 -> V_34 ) {
F_9 ( V_38 ) ;
return - V_41 ;
}
}
break;
default:
break;
}
V_36 -> V_59 = V_38 ;
return 0 ;
}
static void F_31 ( struct V_35 * V_60 )
{
struct V_37 * V_38 = F_32 ( V_60 ) ;
F_9 ( V_38 -> V_61 ) ;
F_9 ( V_38 ) ;
}
static struct V_62 * F_33 (
const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_32 ( V_36 ) ;
return V_38 -> V_61 ;
}
static int F_34 ( struct V_35 * V_36 ,
struct V_13 * V_34 )
{
struct V_37 * V_38 = F_32 ( V_36 ) ;
struct V_62 * V_63 ;
unsigned int V_64 ;
if ( V_38 -> V_61 )
V_64 = V_38 -> V_61 -> V_65 + 1 ;
else
V_64 = 1 ;
V_63 = F_35 ( V_38 -> V_61 ,
sizeof( * V_63 ) + sizeof( V_34 ) * V_64 , V_12 ) ;
if ( ! V_63 )
return - V_41 ;
V_63 -> V_66 [ V_64 - 1 ] = V_34 ;
V_63 -> V_65 = V_64 ;
V_38 -> V_61 = V_63 ;
return 0 ;
}
static void F_36 ( const struct V_35 * V_36 ,
struct V_20 * V_67 )
{
struct V_37 * V_38 = F_32 ( V_36 ) ;
F_14 ( & V_67 -> V_68 , & V_38 -> V_42 ) ;
if ( V_38 -> V_34 ) {
F_37 ( V_38 -> V_34 -> V_2 , V_38 -> V_34 ,
V_67 -> V_28 , NULL , NULL ) ;
}
}
static bool F_38 ( const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_32 ( V_36 ) ;
if ( ! V_38 -> V_34 )
return true ;
return V_38 -> V_34 -> V_69 ;
}
static struct V_70 * F_39 (
const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_32 ( V_36 ) ;
return & V_38 -> V_42 ;
}
unsigned int F_40 ( const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_32 ( V_36 ) ;
return V_38 -> V_58 ;
}
static bool F_41 ( const struct V_35 * V_36 ,
unsigned int V_58 )
{
struct V_37 * V_38 = F_32 ( V_36 ) ;
if ( V_38 -> V_58 == V_58 )
return false ;
if ( V_38 -> V_34 )
V_38 -> V_34 -> V_56 = V_58 ;
V_38 -> V_58 = V_58 ;
return true ;
}
struct V_1 * F_42 (
struct V_35 * V_36 )
{
return F_33 ( V_36 ) -> V_66 [ 0 ] -> V_2 ;
}
struct V_71 * F_43 ( struct V_35 * V_36 )
{
return F_44 ( F_42 ( V_36 ) ) ;
}
static void F_45 ( struct V_30 * V_3 )
{
struct V_13 * V_14 ;
F_2 ( & V_3 -> V_5 ) ;
memset ( & V_3 -> V_72 , 0 , sizeof( V_3 -> V_72 ) ) ;
F_17 (w, &card->widgets, list) {
V_14 -> V_73 = V_14 -> V_69 ;
V_14 -> V_74 = false ;
}
}
static const char * F_46 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_75 )
return NULL ;
return V_2 -> V_75 -> V_76 ;
}
static int F_47 ( struct V_1 * V_2 , int V_50 ,
unsigned int * V_58 )
{
if ( ! V_2 -> V_75 )
return - V_77 ;
return F_48 ( V_2 -> V_75 , V_50 , V_58 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
int V_50 , unsigned int V_51 , unsigned int V_58 )
{
if ( ! V_2 -> V_75 )
return - V_77 ;
return F_50 ( V_2 -> V_75 , V_50 ,
V_51 , V_58 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_50 , unsigned int V_51 , unsigned int V_58 )
{
if ( ! V_2 -> V_75 )
return - V_77 ;
return F_52 ( V_2 -> V_75 , V_50 , V_51 , V_58 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 )
F_54 ( V_2 -> V_75 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
enum V_78 V_79 )
{
struct V_30 * V_3 = V_2 -> V_3 ;
int V_80 = 0 ;
F_56 ( V_3 , V_79 ) ;
if ( V_3 && V_3 -> V_81 )
V_80 = V_3 -> V_81 ( V_3 , V_2 , V_79 ) ;
if ( V_80 != 0 )
goto V_82;
if ( V_2 -> V_81 )
V_80 = V_2 -> V_81 ( V_2 , V_79 ) ;
else if ( ! V_3 || V_2 != & V_3 -> V_2 )
V_2 -> V_83 = V_79 ;
if ( V_80 != 0 )
goto V_82;
if ( V_3 && V_3 -> V_84 )
V_80 = V_3 -> V_84 ( V_3 , V_2 , V_79 ) ;
V_82:
F_57 ( V_3 , V_79 ) ;
return V_80 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_20 * V_67 , const char * V_85 )
{
const struct V_86 * V_36 = & V_67 -> V_19 -> V_87 [ 0 ] ;
struct V_88 * V_89 = (struct V_88 * ) V_36 -> V_47 ;
unsigned int V_90 , V_91 ;
int V_92 ;
if ( V_89 -> V_50 != V_93 ) {
F_47 ( V_2 , V_89 -> V_50 , & V_90 ) ;
V_90 = ( V_90 >> V_89 -> V_94 ) & V_89 -> V_51 ;
V_91 = F_59 ( V_89 , V_90 ) ;
} else {
V_91 = 0 ;
}
for ( V_92 = 0 ; V_92 < V_89 -> V_95 ; V_92 ++ ) {
if ( ! ( strcmp ( V_85 , V_89 -> V_96 [ V_92 ] ) ) ) {
V_67 -> V_17 = V_89 -> V_96 [ V_92 ] ;
if ( V_92 == V_91 )
V_67 -> V_27 = 1 ;
else
V_67 -> V_27 = 0 ;
return 0 ;
}
}
return - V_97 ;
}
static void F_60 ( struct V_20 * V_21 , int V_92 )
{
struct V_39 * V_40 = (struct V_39 * )
V_21 -> V_19 -> V_87 [ V_92 ] . V_47 ;
unsigned int V_50 = V_40 -> V_50 ;
unsigned int V_53 = V_40 -> V_53 ;
unsigned int V_52 = V_40 -> V_52 ;
unsigned int V_51 = ( 1 << F_29 ( V_52 ) ) - 1 ;
unsigned int V_54 = V_40 -> V_54 ;
unsigned int V_90 ;
if ( V_50 != V_93 ) {
F_47 ( V_21 -> V_19 -> V_2 , V_50 , & V_90 ) ;
V_90 = ( V_90 >> V_53 ) & V_51 ;
if ( V_54 )
V_90 = V_52 - V_90 ;
V_21 -> V_27 = ! ! V_90 ;
} else {
V_21 -> V_27 = 0 ;
}
}
static int F_61 ( struct V_1 * V_2 ,
struct V_20 * V_67 , const char * V_85 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_67 -> V_19 -> V_98 ; V_92 ++ ) {
if ( ! strcmp ( V_85 , V_67 -> V_19 -> V_87 [ V_92 ] . V_17 ) ) {
V_67 -> V_17 = V_67 -> V_19 -> V_87 [ V_92 ] . V_17 ;
F_60 ( V_67 , V_92 ) ;
return 0 ;
}
}
return - V_97 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_13 * V_99 ,
const struct V_86 * V_100 ,
struct V_35 * * V_36 )
{
struct V_13 * V_14 ;
int V_92 ;
* V_36 = NULL ;
F_17 (w, &dapm->card->widgets, list) {
if ( V_14 == V_99 || V_14 -> V_2 != V_99 -> V_2 )
continue;
for ( V_92 = 0 ; V_92 < V_14 -> V_98 ; V_92 ++ ) {
if ( & V_14 -> V_87 [ V_92 ] == V_100 ) {
if ( V_14 -> V_101 )
* V_36 = V_14 -> V_101 [ V_92 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_63 ( struct V_13 * V_14 ,
int V_102 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_103 * V_3 = V_2 -> V_3 -> V_103 ;
const char * V_104 ;
T_3 V_105 ;
int V_106 ;
struct V_35 * V_36 ;
bool V_107 , V_108 ;
char * V_109 = NULL ;
const char * V_17 ;
int V_80 = 0 ;
V_104 = F_46 ( V_2 ) ;
if ( V_104 )
V_105 = strlen ( V_104 ) + 1 ;
else
V_105 = 0 ;
V_106 = F_62 ( V_2 , V_14 , & V_14 -> V_87 [ V_102 ] ,
& V_36 ) ;
if ( ! V_36 ) {
if ( V_106 ) {
V_107 = false ;
V_108 = true ;
} else {
switch ( V_14 -> V_43 ) {
case V_44 :
case V_45 :
V_107 = true ;
V_108 = true ;
break;
case V_46 :
V_107 = false ;
V_108 = true ;
break;
case V_110 :
V_107 = true ;
V_108 = false ;
break;
default:
return - V_111 ;
}
}
if ( V_107 && V_108 ) {
V_109 = F_64 ( V_12 , L_5 ,
V_14 -> V_17 + V_105 ,
V_14 -> V_87 [ V_102 ] . V_17 ) ;
if ( V_109 == NULL )
return - V_41 ;
V_17 = V_109 ;
} else if ( V_107 ) {
V_109 = NULL ;
V_17 = V_14 -> V_17 + V_105 ;
} else {
V_109 = NULL ;
V_17 = V_14 -> V_87 [ V_102 ] . V_17 ;
}
V_36 = F_65 ( & V_14 -> V_87 [ V_102 ] , NULL , V_17 ,
V_104 ) ;
if ( ! V_36 ) {
V_80 = - V_41 ;
goto V_112;
}
V_36 -> V_113 = F_31 ;
V_80 = F_25 ( V_14 , V_36 ) ;
if ( V_80 ) {
F_66 ( V_36 ) ;
goto V_112;
}
V_80 = F_67 ( V_3 , V_36 ) ;
if ( V_80 < 0 ) {
F_27 ( V_2 -> V_8 ,
L_6 ,
V_14 -> V_17 , V_17 , V_80 ) ;
goto V_112;
}
}
V_80 = F_34 ( V_36 , V_14 ) ;
if ( V_80 == 0 )
V_14 -> V_101 [ V_102 ] = V_36 ;
V_112:
F_9 ( V_109 ) ;
return V_80 ;
}
static int F_68 ( struct V_13 * V_14 )
{
int V_92 , V_80 ;
struct V_20 * V_67 ;
for ( V_92 = 0 ; V_92 < V_14 -> V_98 ; V_92 ++ ) {
F_17 (path, &w->sources, list_sink) {
if ( V_67 -> V_17 != ( char * ) V_14 -> V_87 [ V_92 ] . V_17 )
continue;
if ( V_14 -> V_101 [ V_92 ] ) {
F_36 ( V_14 -> V_101 [ V_92 ] , V_67 ) ;
continue;
}
V_80 = F_63 ( V_14 , V_92 ) ;
if ( V_80 < 0 )
return V_80 ;
F_36 ( V_14 -> V_101 [ V_92 ] , V_67 ) ;
}
}
return 0 ;
}
static int F_69 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_20 * V_67 ;
int V_80 ;
if ( V_14 -> V_98 != 1 ) {
F_27 ( V_2 -> V_8 ,
L_7 ,
V_14 -> V_17 ) ;
return - V_111 ;
}
if ( F_11 ( & V_14 -> V_114 ) ) {
F_27 ( V_2 -> V_8 , L_8 , V_14 -> V_17 ) ;
return - V_111 ;
}
V_80 = F_63 ( V_14 , 0 ) ;
if ( V_80 < 0 )
return V_80 ;
F_17 (path, &w->sources, list_sink) {
if ( V_67 -> V_17 )
F_36 ( V_14 -> V_101 [ 0 ] , V_67 ) ;
}
return 0 ;
}
static int F_70 ( struct V_13 * V_14 )
{
if ( V_14 -> V_98 )
F_27 ( V_14 -> V_2 -> V_8 ,
L_9 , V_14 -> V_17 ) ;
return 0 ;
}
static int F_71 ( struct V_13 * V_34 )
{
int V_79 = F_72 ( V_34 -> V_2 -> V_3 -> V_103 ) ;
switch ( V_79 ) {
case V_115 :
case V_116 :
if ( V_34 -> V_117 )
F_73 ( V_34 -> V_2 -> V_8 , L_10 ,
V_34 -> V_17 ) ;
return V_34 -> V_117 ;
default:
return 1 ;
}
}
static int F_74 ( struct V_62 * * V_22 ,
struct V_13 * V_14 )
{
struct V_62 * V_61 ;
int V_118 , V_119 , V_92 ;
if ( * V_22 == NULL )
return - V_111 ;
V_61 = * V_22 ;
for ( V_92 = 0 ; V_92 < V_61 -> V_65 ; V_92 ++ ) {
if ( V_61 -> V_66 [ V_92 ] == V_14 )
return 0 ;
}
V_119 = V_61 -> V_65 + 1 ;
V_118 = sizeof( struct V_62 ) +
V_119 * sizeof( struct V_13 * ) ;
* V_22 = F_35 ( V_61 , V_118 , V_12 ) ;
if ( * V_22 == NULL ) {
F_27 ( V_14 -> V_2 -> V_8 , L_11 ,
V_14 -> V_17 ) ;
return - V_41 ;
}
V_61 = * V_22 ;
F_73 ( V_14 -> V_2 -> V_8 , L_12 ,
V_14 -> V_17 , V_61 -> V_65 ) ;
V_61 -> V_66 [ V_61 -> V_65 ] = V_14 ;
V_61 -> V_65 ++ ;
return 1 ;
}
static int F_75 ( struct V_13 * V_34 ,
struct V_62 * * V_22 )
{
struct V_20 * V_67 ;
int V_120 = 0 ;
if ( V_34 -> V_29 >= 0 )
return V_34 -> V_29 ;
F_76 ( V_34 , V_121 ) ;
if ( V_34 -> V_31 && V_34 -> V_122 ) {
V_34 -> V_29 = F_71 ( V_34 ) ;
return V_34 -> V_29 ;
}
F_17 (path, &widget->sinks, list_source) {
F_76 ( V_34 , V_123 ) ;
if ( V_67 -> V_26 || V_67 -> V_25 )
continue;
if ( V_67 -> V_124 )
return 1 ;
F_77 ( V_34 , V_67 ) ;
if ( V_67 -> V_27 ) {
V_67 -> V_124 = 1 ;
if ( V_22 ) {
int V_125 ;
V_125 = F_74 ( V_22 , V_67 -> V_19 ) ;
if ( V_125 < 0 ) {
F_27 ( V_34 -> V_2 -> V_8 ,
L_13 ,
V_34 -> V_17 ) ;
V_67 -> V_124 = 0 ;
return V_120 ;
}
}
V_120 += F_75 ( V_67 -> V_19 , V_22 ) ;
V_67 -> V_124 = 0 ;
}
}
V_34 -> V_29 = V_120 ;
return V_120 ;
}
static int F_78 ( struct V_13 * V_34 ,
struct V_62 * * V_22 )
{
struct V_20 * V_67 ;
int V_120 = 0 ;
if ( V_34 -> V_23 >= 0 )
return V_34 -> V_23 ;
F_76 ( V_34 , V_121 ) ;
if ( V_34 -> V_32 && V_34 -> V_122 ) {
V_34 -> V_23 = F_71 ( V_34 ) ;
return V_34 -> V_23 ;
}
F_17 (path, &widget->sources, list_sink) {
F_76 ( V_34 , V_123 ) ;
if ( V_67 -> V_26 || V_67 -> V_25 )
continue;
if ( V_67 -> V_124 )
return 1 ;
F_79 ( V_34 , V_67 ) ;
if ( V_67 -> V_27 ) {
V_67 -> V_124 = 1 ;
if ( V_22 ) {
int V_125 ;
V_125 = F_74 ( V_22 , V_67 -> V_28 ) ;
if ( V_125 < 0 ) {
F_27 ( V_34 -> V_2 -> V_8 ,
L_13 ,
V_34 -> V_17 ) ;
V_67 -> V_124 = 0 ;
return V_120 ;
}
}
V_120 += F_78 ( V_67 -> V_28 , V_22 ) ;
V_67 -> V_124 = 0 ;
}
}
V_34 -> V_23 = V_120 ;
return V_120 ;
}
int F_80 ( struct V_126 * V_127 , int V_128 ,
struct V_62 * * V_22 )
{
struct V_30 * V_3 = V_127 -> V_75 -> V_3 ;
struct V_13 * V_14 ;
int V_42 ;
F_81 ( & V_3 -> V_5 , V_129 ) ;
F_17 (w, &card->widgets, list) {
V_14 -> V_23 = - 1 ;
V_14 -> V_29 = - 1 ;
}
if ( V_128 == V_130 )
V_42 = F_75 ( V_127 -> V_131 , V_22 ) ;
else
V_42 = F_78 ( V_127 -> V_132 , V_22 ) ;
F_82 ( V_42 , V_128 ) ;
F_22 ( & V_3 -> V_5 ) ;
return V_42 ;
}
int F_83 ( struct V_13 * V_14 ,
struct V_35 * V_36 , int V_133 )
{
int V_80 ;
F_53 ( V_14 -> V_2 ) ;
if ( F_84 ( V_133 ) ) {
if ( V_14 -> V_56 & V_134 ) {
V_80 = F_85 ( V_14 -> V_135 , false ) ;
if ( V_80 != 0 )
F_86 ( V_14 -> V_2 -> V_8 ,
L_14 ,
V_14 -> V_17 , V_80 ) ;
}
return F_87 ( V_14 -> V_135 ) ;
} else {
if ( V_14 -> V_56 & V_134 ) {
V_80 = F_85 ( V_14 -> V_135 , true ) ;
if ( V_80 != 0 )
F_86 ( V_14 -> V_2 -> V_8 ,
L_15 ,
V_14 -> V_17 , V_80 ) ;
}
return F_88 ( V_14 -> V_135 , V_14 -> V_53 ) ;
}
}
int F_89 ( struct V_13 * V_14 ,
struct V_35 * V_36 , int V_133 )
{
if ( ! V_14 -> V_136 )
return - V_77 ;
F_53 ( V_14 -> V_2 ) ;
#ifdef F_90
if ( F_84 ( V_133 ) ) {
return F_91 ( V_14 -> V_136 ) ;
} else {
F_92 ( V_14 -> V_136 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_93 ( struct V_13 * V_14 )
{
if ( V_14 -> V_74 )
return V_14 -> V_73 ;
if ( V_14 -> V_137 )
V_14 -> V_73 = 1 ;
else
V_14 -> V_73 = V_14 -> V_138 ( V_14 ) ;
V_14 -> V_74 = true ;
return V_14 -> V_73 ;
}
static int F_94 ( struct V_13 * V_14 )
{
int V_139 , V_82 ;
F_76 ( V_14 , V_140 ) ;
V_139 = F_78 ( V_14 , NULL ) ;
V_82 = F_75 ( V_14 , NULL ) ;
return V_82 != 0 && V_139 != 0 ;
}
static int F_95 ( struct V_13 * V_14 )
{
struct V_20 * V_67 ;
F_76 ( V_14 , V_140 ) ;
F_17 (path, &w->sinks, list_source) {
F_76 ( V_14 , V_123 ) ;
if ( V_67 -> V_26 )
continue;
if ( V_67 -> V_122 &&
! V_67 -> V_122 ( V_67 -> V_28 , V_67 -> V_19 ) )
continue;
if ( F_93 ( V_67 -> V_19 ) )
return 1 ;
}
return 0 ;
}
static int F_96 ( struct V_13 * V_14 )
{
return 1 ;
}
static int F_97 ( struct V_13 * V_141 ,
struct V_13 * V_142 ,
bool V_143 )
{
int * V_144 ;
if ( V_143 )
V_144 = V_145 ;
else
V_144 = V_146 ;
if ( V_144 [ V_141 -> V_43 ] != V_144 [ V_142 -> V_43 ] )
return V_144 [ V_141 -> V_43 ] - V_144 [ V_142 -> V_43 ] ;
if ( V_141 -> V_147 != V_142 -> V_147 ) {
if ( V_143 )
return V_141 -> V_147 - V_142 -> V_147 ;
else
return V_142 -> V_147 - V_141 -> V_147 ;
}
if ( V_141 -> V_50 != V_142 -> V_50 )
return V_141 -> V_50 - V_142 -> V_50 ;
if ( V_141 -> V_2 != V_142 -> V_2 )
return ( unsigned long ) V_141 -> V_2 - ( unsigned long ) V_142 -> V_2 ;
return 0 ;
}
static void F_98 ( struct V_13 * V_148 ,
struct V_70 * V_22 ,
bool V_143 )
{
struct V_13 * V_14 ;
F_17 (w, list, power_list)
if ( F_97 ( V_148 , V_14 , V_143 ) < 0 ) {
F_14 ( & V_148 -> V_149 , & V_14 -> V_149 ) ;
return;
}
F_14 ( & V_148 -> V_149 , V_22 ) ;
}
static void F_99 ( struct V_30 * V_3 ,
struct V_13 * V_14 , int V_133 )
{
const char * V_150 ;
int V_69 , V_80 ;
switch ( V_133 ) {
case V_151 :
V_150 = L_16 ;
V_69 = 1 ;
break;
case V_152 :
V_150 = L_17 ;
V_69 = 1 ;
break;
case V_153 :
V_150 = L_18 ;
V_69 = 0 ;
break;
case V_154 :
V_150 = L_19 ;
V_69 = 0 ;
break;
case V_155 :
V_150 = L_20 ;
V_69 = 1 ;
break;
case V_156 :
V_150 = L_21 ;
V_69 = 0 ;
break;
default:
F_100 ( 1 , L_22 , V_133 ) ;
return;
}
if ( V_14 -> V_73 != V_69 )
return;
if ( V_14 -> V_133 && ( V_14 -> V_157 & V_133 ) ) {
F_6 ( V_14 -> V_2 -> V_8 , V_3 -> V_6 , L_23 ,
V_14 -> V_17 , V_150 ) ;
F_53 ( V_14 -> V_2 ) ;
F_101 ( V_14 , V_133 ) ;
V_80 = V_14 -> V_133 ( V_14 , NULL , V_133 ) ;
F_102 ( V_14 , V_133 ) ;
if ( V_80 < 0 )
F_27 ( V_14 -> V_2 -> V_8 , L_24 ,
V_150 , V_14 -> V_17 , V_80 ) ;
}
}
static void F_103 ( struct V_30 * V_3 ,
struct V_70 * V_158 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
int V_50 ;
unsigned int V_58 = 0 ;
unsigned int V_51 = 0 ;
V_14 = F_104 ( V_158 , struct V_13 , V_149 ) ;
V_50 = V_14 -> V_50 ;
V_2 = V_14 -> V_2 ;
F_17 (w, pending, power_list) {
F_105 ( V_50 != V_14 -> V_50 || V_2 != V_14 -> V_2 ) ;
V_14 -> V_69 = V_14 -> V_73 ;
V_51 |= V_14 -> V_51 << V_14 -> V_53 ;
if ( V_14 -> V_69 )
V_58 |= V_14 -> V_56 << V_14 -> V_53 ;
else
V_58 |= V_14 -> V_55 << V_14 -> V_53 ;
F_6 ( V_2 -> V_8 , V_3 -> V_6 ,
L_25 ,
V_14 -> V_17 , V_50 , V_58 , V_51 ) ;
F_99 ( V_3 , V_14 , V_151 ) ;
F_99 ( V_3 , V_14 , V_153 ) ;
}
if ( V_50 >= 0 ) {
F_6 ( V_2 -> V_8 , V_3 -> V_6 ,
L_26 ,
V_58 , V_51 , V_50 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_49 ( V_2 , V_50 , V_51 , V_58 ) ;
}
F_17 (w, pending, power_list) {
F_99 ( V_3 , V_14 , V_152 ) ;
F_99 ( V_3 , V_14 , V_154 ) ;
}
}
static void F_106 ( struct V_30 * V_3 ,
struct V_70 * V_22 , int V_133 , bool V_143 )
{
struct V_13 * V_14 , * V_64 ;
struct V_1 * V_159 ;
F_16 ( V_158 ) ;
int V_160 = - 1 ;
int V_161 = - 1 ;
int V_162 = V_93 ;
struct V_1 * V_163 = NULL ;
int V_80 , V_92 ;
int * V_144 ;
if ( V_143 )
V_144 = V_145 ;
else
V_144 = V_146 ;
F_107 (w, n, list, power_list) {
V_80 = 0 ;
if ( V_144 [ V_14 -> V_43 ] != V_160 || V_14 -> V_50 != V_162 ||
V_14 -> V_2 != V_163 || V_14 -> V_147 != V_161 ) {
if ( ! F_11 ( & V_158 ) )
F_103 ( V_3 , & V_158 ) ;
if ( V_163 && V_163 -> V_164 ) {
for ( V_92 = 0 ; V_92 < F_108 ( V_145 ) ; V_92 ++ )
if ( V_144 [ V_92 ] == V_160 )
V_163 -> V_164 ( V_163 ,
V_92 ,
V_161 ) ;
}
if ( V_163 && V_14 -> V_2 != V_163 )
F_53 ( V_163 ) ;
F_28 ( & V_158 ) ;
V_160 = - 1 ;
V_161 = V_165 ;
V_162 = V_93 ;
V_163 = NULL ;
}
switch ( V_14 -> V_43 ) {
case V_166 :
if ( ! V_14 -> V_133 )
F_109 ( V_14 , V_64 , V_22 ,
V_149 ) ;
if ( V_133 == V_167 )
V_80 = V_14 -> V_133 ( V_14 ,
NULL , V_151 ) ;
else if ( V_133 == V_168 )
V_80 = V_14 -> V_133 ( V_14 ,
NULL , V_153 ) ;
break;
case V_169 :
if ( ! V_14 -> V_133 )
F_109 ( V_14 , V_64 , V_22 ,
V_149 ) ;
if ( V_133 == V_167 )
V_80 = V_14 -> V_133 ( V_14 ,
NULL , V_152 ) ;
else if ( V_133 == V_168 )
V_80 = V_14 -> V_133 ( V_14 ,
NULL , V_154 ) ;
break;
default:
V_160 = V_144 [ V_14 -> V_43 ] ;
V_161 = V_14 -> V_147 ;
V_162 = V_14 -> V_50 ;
V_163 = V_14 -> V_2 ;
F_110 ( & V_14 -> V_149 , & V_158 ) ;
break;
}
if ( V_80 < 0 )
F_27 ( V_14 -> V_2 -> V_8 ,
L_27 , V_80 ) ;
}
if ( ! F_11 ( & V_158 ) )
F_103 ( V_3 , & V_158 ) ;
if ( V_163 && V_163 -> V_164 ) {
for ( V_92 = 0 ; V_92 < F_108 ( V_145 ) ; V_92 ++ )
if ( V_144 [ V_92 ] == V_160 )
V_163 -> V_164 ( V_163 ,
V_92 , V_161 ) ;
}
F_17 (d, &card->dapm_list, list) {
F_53 ( V_159 ) ;
}
}
static void F_111 ( struct V_30 * V_3 )
{
struct V_170 * V_171 = V_3 -> V_171 ;
struct V_62 * V_61 ;
struct V_13 * V_14 = NULL ;
unsigned int V_172 ;
int V_80 ;
if ( ! V_171 || ! F_38 ( V_171 -> V_36 ) )
return;
V_61 = F_33 ( V_171 -> V_36 ) ;
for ( V_172 = 0 ; V_172 < V_61 -> V_65 ; V_172 ++ ) {
V_14 = V_61 -> V_66 [ V_172 ] ;
if ( V_14 -> V_133 && ( V_14 -> V_157 & V_173 ) ) {
V_80 = V_14 -> V_133 ( V_14 , V_171 -> V_36 , V_173 ) ;
if ( V_80 != 0 )
F_27 ( V_14 -> V_2 -> V_8 , L_28 ,
V_14 -> V_17 , V_80 ) ;
}
}
if ( ! V_14 )
return;
V_80 = F_49 ( V_14 -> V_2 , V_171 -> V_50 , V_171 -> V_51 ,
V_171 -> V_90 ) ;
if ( V_80 < 0 )
F_27 ( V_14 -> V_2 -> V_8 , L_29 ,
V_14 -> V_17 , V_80 ) ;
for ( V_172 = 0 ; V_172 < V_61 -> V_65 ; V_172 ++ ) {
V_14 = V_61 -> V_66 [ V_172 ] ;
if ( V_14 -> V_133 && ( V_14 -> V_157 & V_174 ) ) {
V_80 = V_14 -> V_133 ( V_14 , V_171 -> V_36 , V_174 ) ;
if ( V_80 != 0 )
F_27 ( V_14 -> V_2 -> V_8 , L_30 ,
V_14 -> V_17 , V_80 ) ;
}
}
}
static void F_112 ( void * V_38 , T_4 V_175 )
{
struct V_1 * V_159 = V_38 ;
int V_80 ;
if ( V_159 -> V_83 == V_176 &&
V_159 -> V_177 != V_176 ) {
if ( V_159 -> V_8 )
F_113 ( V_159 -> V_8 ) ;
V_80 = F_55 ( V_159 , V_178 ) ;
if ( V_80 != 0 )
F_27 ( V_159 -> V_8 ,
L_31 , V_80 ) ;
}
if ( ( V_159 -> V_177 == V_179 &&
V_159 -> V_83 != V_179 ) ||
( V_159 -> V_177 != V_179 &&
V_159 -> V_83 == V_179 ) ) {
V_80 = F_55 ( V_159 , V_180 ) ;
if ( V_80 != 0 )
F_27 ( V_159 -> V_8 ,
L_32 , V_80 ) ;
}
}
static void F_114 ( void * V_38 , T_4 V_175 )
{
struct V_1 * V_159 = V_38 ;
int V_80 ;
if ( V_159 -> V_83 == V_180 &&
( V_159 -> V_177 == V_178 ||
V_159 -> V_177 == V_176 ) ) {
V_80 = F_55 ( V_159 , V_178 ) ;
if ( V_80 != 0 )
F_27 ( V_159 -> V_8 , L_33 ,
V_80 ) ;
}
if ( V_159 -> V_83 == V_178 &&
V_159 -> V_177 == V_176 ) {
V_80 = F_55 ( V_159 , V_176 ) ;
if ( V_80 != 0 )
F_27 ( V_159 -> V_8 , L_34 ,
V_80 ) ;
if ( V_159 -> V_8 )
F_115 ( V_159 -> V_8 ) ;
}
if ( V_159 -> V_83 == V_180 &&
V_159 -> V_177 == V_179 ) {
V_80 = F_55 ( V_159 , V_179 ) ;
if ( V_80 != 0 )
F_27 ( V_159 -> V_8 , L_35 ,
V_80 ) ;
}
}
static void F_116 ( struct V_13 * V_181 ,
bool V_69 , bool V_27 )
{
if ( ! V_27 )
return;
if ( V_69 != V_181 -> V_69 )
F_12 ( V_181 , L_36 ) ;
}
static void F_117 ( struct V_13 * V_14 , bool V_69 ,
struct V_70 * V_182 ,
struct V_70 * V_183 )
{
struct V_20 * V_67 ;
if ( V_14 -> V_69 == V_69 )
return;
F_118 ( V_14 , V_69 ) ;
F_17 (path, &w->sources, list_sink)
F_116 ( V_67 -> V_28 , V_69 , V_67 -> V_27 ) ;
if ( ! V_14 -> V_25 ) {
F_17 (path, &w->sinks, list_source)
F_116 ( V_67 -> V_19 , V_69 ,
V_67 -> V_27 ) ;
}
if ( V_69 )
F_98 ( V_14 , V_182 , true ) ;
else
F_98 ( V_14 , V_183 , false ) ;
}
static void F_119 ( struct V_13 * V_14 ,
struct V_70 * V_182 ,
struct V_70 * V_183 )
{
int V_69 ;
switch ( V_14 -> V_43 ) {
case V_166 :
F_98 ( V_14 , V_183 , false ) ;
break;
case V_169 :
F_98 ( V_14 , V_182 , true ) ;
break;
default:
V_69 = F_93 ( V_14 ) ;
F_117 ( V_14 , V_69 , V_182 , V_183 ) ;
break;
}
}
static bool F_120 ( struct V_1 * V_2 )
{
if ( V_2 -> V_184 )
return true ;
switch ( F_72 ( V_2 -> V_3 -> V_103 ) ) {
case V_115 :
case V_116 :
return V_2 -> V_185 ;
default:
break;
}
return false ;
}
static int F_121 ( struct V_30 * V_3 , int V_133 )
{
struct V_13 * V_14 ;
struct V_1 * V_159 ;
F_16 ( V_182 ) ;
F_16 ( V_183 ) ;
F_122 ( V_186 ) ;
enum V_78 V_187 ;
F_2 ( & V_3 -> V_5 ) ;
F_123 ( V_3 ) ;
F_17 (d, &card->dapm_list, list) {
if ( F_120 ( V_159 ) )
V_159 -> V_177 = V_176 ;
else
V_159 -> V_177 = V_178 ;
}
F_45 ( V_3 ) ;
F_17 (w, &card->dapm_dirty, dirty) {
F_119 ( V_14 , & V_182 , & V_183 ) ;
}
F_17 (w, &card->widgets, list) {
switch ( V_14 -> V_43 ) {
case V_166 :
case V_169 :
break;
default:
F_124 ( & V_14 -> V_15 ) ;
break;
}
if ( V_14 -> V_73 ) {
V_159 = V_14 -> V_2 ;
switch ( V_14 -> V_43 ) {
case V_188 :
case V_189 :
break;
case V_190 :
case V_191 :
case V_192 :
case V_193 :
if ( V_159 -> V_177 < V_178 )
V_159 -> V_177 = V_178 ;
break;
default:
V_159 -> V_177 = V_179 ;
break;
}
}
}
V_187 = V_176 ;
F_17 (d, &card->dapm_list, list)
if ( V_159 -> V_177 > V_187 )
V_187 = V_159 -> V_177 ;
F_17 (d, &card->dapm_list, list)
if ( ! F_120 ( V_159 ) )
V_159 -> V_177 = V_187 ;
F_125 ( V_3 ) ;
F_112 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_159 != & V_3 -> V_2 )
F_126 ( F_112 , V_159 ,
& V_186 ) ;
}
F_127 ( & V_186 ) ;
F_17 (w, &down_list, power_list) {
F_99 ( V_3 , V_14 , V_156 ) ;
}
F_17 (w, &up_list, power_list) {
F_99 ( V_3 , V_14 , V_155 ) ;
}
F_106 ( V_3 , & V_183 , V_133 , false ) ;
F_111 ( V_3 ) ;
F_106 ( V_3 , & V_182 , V_133 , true ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_159 != & V_3 -> V_2 )
F_126 ( F_114 , V_159 ,
& V_186 ) ;
}
F_127 ( & V_186 ) ;
F_114 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_159 -> V_194 )
V_159 -> V_194 ( V_159 , V_133 ) ;
}
F_6 ( V_3 -> V_8 , V_3 -> V_6 ,
L_37 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_128 ( V_3 ) ;
return 0 ;
}
static T_5 F_129 ( struct V_195 * V_195 ,
char T_6 * V_196 ,
T_3 V_197 , T_7 * V_198 )
{
struct V_13 * V_14 = V_195 -> V_59 ;
char * V_10 ;
int V_139 , V_82 ;
T_5 V_80 ;
struct V_20 * V_21 = NULL ;
V_10 = F_7 ( V_11 , V_12 ) ;
if ( ! V_10 )
return - V_41 ;
if ( V_14 -> V_25 ) {
V_139 = 0 ;
V_82 = 0 ;
} else {
V_139 = F_78 ( V_14 , NULL ) ;
V_82 = F_75 ( V_14 , NULL ) ;
}
V_80 = snprintf ( V_10 , V_11 , L_38 ,
V_14 -> V_17 , V_14 -> V_69 ? L_39 : L_40 ,
V_14 -> V_137 ? L_41 : L_42 , V_139 , V_82 ) ;
if ( V_14 -> V_50 >= 0 )
V_80 += snprintf ( V_10 + V_80 , V_11 - V_80 ,
L_43 ,
V_14 -> V_50 , V_14 -> V_50 , V_14 -> V_51 << V_14 -> V_53 ) ;
V_80 += snprintf ( V_10 + V_80 , V_11 - V_80 , L_44 ) ;
if ( V_14 -> V_199 )
V_80 += snprintf ( V_10 + V_80 , V_11 - V_80 , L_45 ,
V_14 -> V_199 ,
V_14 -> V_200 ? L_46 : L_47 ) ;
F_17 (p, &w->sources, list_sink) {
if ( V_21 -> V_122 && ! V_21 -> V_122 ( V_14 , V_21 -> V_28 ) )
continue;
if ( V_21 -> V_27 )
V_80 += snprintf ( V_10 + V_80 , V_11 - V_80 ,
L_48 ,
V_21 -> V_17 ? V_21 -> V_17 : L_49 ,
V_21 -> V_28 -> V_17 ) ;
}
F_17 (p, &w->sinks, list_source) {
if ( V_21 -> V_122 && ! V_21 -> V_122 ( V_14 , V_21 -> V_19 ) )
continue;
if ( V_21 -> V_27 )
V_80 += snprintf ( V_10 + V_80 , V_11 - V_80 ,
L_50 ,
V_21 -> V_17 ? V_21 -> V_17 : L_49 ,
V_21 -> V_19 -> V_17 ) ;
}
V_80 = F_130 ( V_196 , V_197 , V_198 , V_10 , V_80 ) ;
F_9 ( V_10 ) ;
return V_80 ;
}
static T_5 F_131 ( struct V_195 * V_195 , char T_6 * V_196 ,
T_3 V_197 , T_7 * V_198 )
{
struct V_1 * V_2 = V_195 -> V_59 ;
char * V_79 ;
switch ( V_2 -> V_83 ) {
case V_179 :
V_79 = L_51 ;
break;
case V_180 :
V_79 = L_52 ;
break;
case V_178 :
V_79 = L_53 ;
break;
case V_176 :
V_79 = L_54 ;
break;
default:
F_100 ( 1 , L_55 , V_2 -> V_83 ) ;
V_79 = L_56 ;
break;
}
return F_130 ( V_196 , V_197 , V_198 , V_79 ,
strlen ( V_79 ) ) ;
}
void F_132 ( struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_201 * V_159 ;
V_2 -> V_203 = F_133 ( L_57 , V_202 ) ;
if ( ! V_2 -> V_203 ) {
F_86 ( V_2 -> V_8 ,
L_58 ) ;
return;
}
V_159 = F_134 ( L_59 , 0444 ,
V_2 -> V_203 , V_2 ,
& V_204 ) ;
if ( ! V_159 )
F_86 ( V_2 -> V_8 ,
L_60 ) ;
}
static void F_135 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_201 * V_159 ;
if ( ! V_2 -> V_203 || ! V_14 -> V_17 )
return;
V_159 = F_134 ( V_14 -> V_17 , 0444 ,
V_2 -> V_203 , V_14 ,
& V_205 ) ;
if ( ! V_159 )
F_86 ( V_14 -> V_2 -> V_8 ,
L_61 ,
V_14 -> V_17 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_137 ( V_2 -> V_203 ) ;
}
void F_132 ( struct V_1 * V_2 ,
struct V_201 * V_202 )
{
}
static inline void F_135 ( struct V_13 * V_14 )
{
}
static inline void F_136 ( struct V_1 * V_2 )
{
}
static void F_138 ( struct V_20 * V_67 ,
bool V_27 , const char * V_16 )
{
if ( V_67 -> V_27 == V_27 )
return;
V_67 -> V_27 = V_27 ;
F_12 ( V_67 -> V_28 , V_16 ) ;
F_12 ( V_67 -> V_19 , V_16 ) ;
F_19 ( V_67 ) ;
}
static int F_139 ( struct V_30 * V_3 ,
struct V_35 * V_36 , int V_206 , struct V_88 * V_89 )
{
struct V_20 * V_67 ;
int V_207 = 0 ;
bool V_27 ;
F_2 ( & V_3 -> V_5 ) ;
F_140 (path, kcontrol) {
V_207 = 1 ;
if ( ! ( strcmp ( V_67 -> V_17 , V_89 -> V_96 [ V_206 ] ) ) )
V_27 = true ;
else
V_27 = false ;
F_138 ( V_67 , V_27 , L_62 ) ;
}
if ( V_207 )
F_121 ( V_3 , V_208 ) ;
return V_207 ;
}
int F_141 ( struct V_1 * V_2 ,
struct V_35 * V_36 , int V_206 , struct V_88 * V_89 ,
struct V_170 * V_171 )
{
struct V_30 * V_3 = V_2 -> V_3 ;
int V_80 ;
F_81 ( & V_3 -> V_5 , V_129 ) ;
V_3 -> V_171 = V_171 ;
V_80 = F_139 ( V_3 , V_36 , V_206 , V_89 ) ;
V_3 -> V_171 = NULL ;
F_22 ( & V_3 -> V_5 ) ;
if ( V_80 > 0 )
F_142 ( V_3 ) ;
return V_80 ;
}
static int F_143 ( struct V_30 * V_3 ,
struct V_35 * V_36 , int V_27 )
{
struct V_20 * V_67 ;
int V_207 = 0 ;
F_2 ( & V_3 -> V_5 ) ;
F_140 (path, kcontrol) {
V_207 = 1 ;
F_138 ( V_67 , V_27 , L_63 ) ;
}
if ( V_207 )
F_121 ( V_3 , V_208 ) ;
return V_207 ;
}
int F_144 ( struct V_1 * V_2 ,
struct V_35 * V_36 , int V_27 ,
struct V_170 * V_171 )
{
struct V_30 * V_3 = V_2 -> V_3 ;
int V_80 ;
F_81 ( & V_3 -> V_5 , V_129 ) ;
V_3 -> V_171 = V_171 ;
V_80 = F_143 ( V_3 , V_36 , V_27 ) ;
V_3 -> V_171 = NULL ;
F_22 ( & V_3 -> V_5 ) ;
if ( V_80 > 0 )
F_142 ( V_3 ) ;
return V_80 ;
}
static T_5 F_145 ( struct V_71 * V_209 , char * V_10 )
{
struct V_13 * V_14 ;
int V_197 = 0 ;
char * V_210 = L_64 ;
F_17 (w, &codec->component.card->widgets, list) {
if ( V_14 -> V_2 != & V_209 -> V_2 )
continue;
switch ( V_14 -> V_43 ) {
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_193 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_45 :
case V_46 :
case V_190 :
case V_191 :
case V_192 :
if ( V_14 -> V_17 )
V_197 += sprintf ( V_10 + V_197 , L_65 ,
V_14 -> V_17 , V_14 -> V_69 ? L_39 : L_40 ) ;
break;
default:
break;
}
}
switch ( V_209 -> V_2 . V_83 ) {
case V_179 :
V_210 = L_39 ;
break;
case V_180 :
V_210 = L_66 ;
break;
case V_178 :
V_210 = L_67 ;
break;
case V_176 :
V_210 = L_40 ;
break;
}
V_197 += sprintf ( V_10 + V_197 , L_68 , V_210 ) ;
return V_197 ;
}
static T_5 F_146 ( struct V_7 * V_8 ,
struct V_219 * V_220 , char * V_10 )
{
struct V_221 * V_222 = F_147 ( V_8 ) ;
int V_92 , V_197 = 0 ;
for ( V_92 = 0 ; V_92 < V_222 -> V_223 ; V_92 ++ ) {
struct V_71 * V_209 = V_222 -> V_224 [ V_92 ] -> V_209 ;
V_197 += F_145 ( V_209 , V_10 + V_197 ) ;
}
return V_197 ;
}
static void F_148 ( struct V_20 * V_67 )
{
F_149 ( & V_67 -> V_225 ) ;
F_149 ( & V_67 -> V_226 ) ;
F_149 ( & V_67 -> V_68 ) ;
F_149 ( & V_67 -> V_22 ) ;
F_9 ( V_67 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_227 ;
struct V_20 * V_21 , * V_228 ;
F_107 (w, next_w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
F_149 ( & V_14 -> V_22 ) ;
F_107 (p, next_p, &w->sources, list_sink)
F_148 ( V_21 ) ;
F_107 (p, next_p, &w->sinks, list_source)
F_148 ( V_21 ) ;
F_9 ( V_14 -> V_101 ) ;
F_9 ( V_14 -> V_17 ) ;
F_9 ( V_14 ) ;
}
}
static struct V_13 * F_151 (
struct V_1 * V_2 , const char * V_229 ,
bool V_230 )
{
struct V_13 * V_14 ;
struct V_13 * V_231 = NULL ;
F_17 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_14 -> V_17 , V_229 ) ) {
if ( V_14 -> V_2 == V_2 )
return V_14 ;
else
V_231 = V_14 ;
}
}
if ( V_230 )
return V_231 ;
return NULL ;
}
static int F_152 ( struct V_1 * V_2 ,
const char * V_229 , int V_232 )
{
struct V_13 * V_14 = F_151 ( V_2 , V_229 , true ) ;
F_1 ( V_2 ) ;
if ( ! V_14 ) {
F_27 ( V_2 -> V_8 , L_69 , V_229 ) ;
return - V_111 ;
}
if ( V_14 -> V_122 != V_232 ) {
F_12 ( V_14 , L_70 ) ;
F_15 ( V_14 ) ;
F_18 ( V_14 ) ;
}
V_14 -> V_122 = V_232 ;
if ( V_232 == 0 )
V_14 -> V_137 = 0 ;
return 0 ;
}
int F_153 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_3 -> V_4 )
return 0 ;
return F_121 ( V_2 -> V_3 , V_208 ) ;
}
int F_154 ( struct V_1 * V_2 )
{
int V_80 ;
F_81 ( & V_2 -> V_3 -> V_5 , V_129 ) ;
V_80 = F_153 ( V_2 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_80 ;
}
static void F_155 ( struct V_13 * V_14 )
{
struct V_20 * V_21 ;
switch ( V_14 -> V_43 ) {
case V_233 :
if ( V_14 -> V_2 -> V_3 -> V_234 )
break;
V_14 -> V_32 = 1 ;
F_17 (p, &w->sources, list_sink) {
if ( V_21 -> V_28 -> V_43 == V_193 ||
V_21 -> V_28 -> V_43 == V_212 ||
V_21 -> V_28 -> V_43 == V_214 ||
V_21 -> V_28 -> V_43 == V_235 ) {
V_14 -> V_32 = 0 ;
break;
}
}
break;
case V_235 :
if ( V_14 -> V_2 -> V_3 -> V_234 )
break;
V_14 -> V_31 = 1 ;
F_17 (p, &w->sinks, list_source) {
if ( V_21 -> V_19 -> V_43 == V_213 ||
V_21 -> V_19 -> V_43 == V_211 ||
V_21 -> V_19 -> V_43 == V_214 ||
V_21 -> V_19 -> V_43 == V_233 ) {
V_14 -> V_31 = 0 ;
break;
}
}
break;
case V_214 :
V_14 -> V_31 = ! F_11 ( & V_14 -> V_114 ) ;
V_14 -> V_32 = ! F_11 ( & V_14 -> V_236 ) ;
break;
default:
break;
}
}
static int F_37 ( struct V_1 * V_2 ,
struct V_13 * V_237 , struct V_13 * V_238 ,
const char * V_239 ,
int (* V_122)( struct V_13 * V_28 ,
struct V_13 * V_19 ) )
{
struct V_20 * V_67 ;
int V_80 ;
if ( V_238 -> V_25 && ! V_237 -> V_25 ) {
F_27 ( V_2 -> V_8 ,
L_71 ,
V_237 -> V_17 , V_238 -> V_17 ) ;
return - V_111 ;
}
if ( V_122 && ! V_237 -> V_25 ) {
F_27 ( V_2 -> V_8 ,
L_72 ,
V_237 -> V_17 , V_238 -> V_17 ) ;
return - V_111 ;
}
if ( V_237 -> V_25 && V_239 ) {
F_27 ( V_2 -> V_8 ,
L_73 ,
V_237 -> V_17 , V_239 , V_238 -> V_17 ) ;
return - V_111 ;
}
V_67 = F_26 ( sizeof( struct V_20 ) , V_12 ) ;
if ( ! V_67 )
return - V_41 ;
V_67 -> V_28 = V_237 ;
V_67 -> V_19 = V_238 ;
V_67 -> V_122 = V_122 ;
F_28 ( & V_67 -> V_22 ) ;
F_28 ( & V_67 -> V_68 ) ;
F_28 ( & V_67 -> V_226 ) ;
F_28 ( & V_67 -> V_225 ) ;
if ( V_237 -> V_25 || V_238 -> V_25 )
V_67 -> V_25 = 1 ;
if ( V_239 == NULL ) {
V_67 -> V_27 = 1 ;
} else {
switch ( V_238 -> V_43 ) {
case V_110 :
V_80 = F_58 ( V_2 , V_67 , V_239 ) ;
if ( V_80 != 0 )
goto V_125;
break;
case V_44 :
case V_45 :
case V_46 :
V_80 = F_61 ( V_2 , V_67 , V_239 ) ;
if ( V_80 != 0 )
goto V_125;
break;
default:
F_27 ( V_2 -> V_8 ,
L_74 ,
V_237 -> V_17 , V_239 , V_238 -> V_17 ) ;
V_80 = - V_111 ;
goto V_125;
}
}
F_156 ( & V_67 -> V_22 , & V_2 -> V_3 -> V_42 ) ;
F_156 ( & V_67 -> V_225 , & V_238 -> V_114 ) ;
F_156 ( & V_67 -> V_226 , & V_237 -> V_236 ) ;
F_155 ( V_237 ) ;
F_155 ( V_238 ) ;
F_12 ( V_237 , L_75 ) ;
F_12 ( V_238 , L_75 ) ;
if ( V_2 -> V_3 -> V_4 && V_67 -> V_27 )
F_19 ( V_67 ) ;
return 0 ;
V_125:
F_9 ( V_67 ) ;
return V_80 ;
}
static int F_157 ( struct V_1 * V_2 ,
const struct V_240 * V_241 )
{
struct V_13 * V_237 = NULL , * V_238 = NULL , * V_14 ;
struct V_13 * V_242 = NULL , * V_243 = NULL ;
const char * V_19 ;
const char * V_28 ;
char V_244 [ 80 ] ;
char V_245 [ 80 ] ;
const char * V_104 ;
int V_80 ;
V_104 = F_46 ( V_2 ) ;
if ( V_104 ) {
snprintf ( V_244 , sizeof( V_244 ) , L_5 ,
V_104 , V_241 -> V_19 ) ;
V_19 = V_244 ;
snprintf ( V_245 , sizeof( V_245 ) , L_5 ,
V_104 , V_241 -> V_28 ) ;
V_28 = V_245 ;
} else {
V_19 = V_241 -> V_19 ;
V_28 = V_241 -> V_28 ;
}
F_17 (w, &dapm->card->widgets, list) {
if ( ! V_238 && ! ( strcmp ( V_14 -> V_17 , V_19 ) ) ) {
V_243 = V_14 ;
if ( V_14 -> V_2 == V_2 )
V_238 = V_14 ;
continue;
}
if ( ! V_237 && ! ( strcmp ( V_14 -> V_17 , V_28 ) ) ) {
V_242 = V_14 ;
if ( V_14 -> V_2 == V_2 )
V_237 = V_14 ;
}
}
if ( ! V_238 )
V_238 = V_243 ;
if ( ! V_237 )
V_237 = V_242 ;
if ( V_237 == NULL ) {
F_27 ( V_2 -> V_8 , L_76 ,
V_241 -> V_28 ) ;
return - V_97 ;
}
if ( V_238 == NULL ) {
F_27 ( V_2 -> V_8 , L_77 ,
V_241 -> V_19 ) ;
return - V_97 ;
}
V_80 = F_37 ( V_2 , V_237 , V_238 , V_241 -> V_239 ,
V_241 -> V_122 ) ;
if ( V_80 )
goto V_125;
return 0 ;
V_125:
F_86 ( V_2 -> V_8 , L_78 ,
V_28 , V_241 -> V_239 , V_19 ) ;
return V_80 ;
}
static int F_158 ( struct V_1 * V_2 ,
const struct V_240 * V_241 )
{
struct V_13 * V_237 , * V_238 ;
struct V_20 * V_67 , * V_21 ;
const char * V_19 ;
const char * V_28 ;
char V_244 [ 80 ] ;
char V_245 [ 80 ] ;
const char * V_104 ;
if ( V_241 -> V_239 ) {
F_27 ( V_2 -> V_8 ,
L_79 ) ;
return - V_111 ;
}
V_104 = F_46 ( V_2 ) ;
if ( V_104 ) {
snprintf ( V_244 , sizeof( V_244 ) , L_5 ,
V_104 , V_241 -> V_19 ) ;
V_19 = V_244 ;
snprintf ( V_245 , sizeof( V_245 ) , L_5 ,
V_104 , V_241 -> V_28 ) ;
V_28 = V_245 ;
} else {
V_19 = V_241 -> V_19 ;
V_28 = V_241 -> V_28 ;
}
V_67 = NULL ;
F_17 (p, &dapm->card->paths, list) {
if ( strcmp ( V_21 -> V_28 -> V_17 , V_28 ) != 0 )
continue;
if ( strcmp ( V_21 -> V_19 -> V_17 , V_19 ) != 0 )
continue;
V_67 = V_21 ;
break;
}
if ( V_67 ) {
V_237 = V_67 -> V_28 ;
V_238 = V_67 -> V_19 ;
F_12 ( V_237 , L_80 ) ;
F_12 ( V_238 , L_80 ) ;
if ( V_67 -> V_27 )
F_19 ( V_67 ) ;
F_148 ( V_67 ) ;
F_155 ( V_237 ) ;
F_155 ( V_238 ) ;
} else {
F_86 ( V_2 -> V_8 , L_81 ,
V_28 , V_19 ) ;
}
return 0 ;
}
int F_159 ( struct V_1 * V_2 ,
const struct V_240 * V_241 , int V_246 )
{
int V_92 , V_247 , V_80 = 0 ;
F_81 ( & V_2 -> V_3 -> V_5 , V_248 ) ;
for ( V_92 = 0 ; V_92 < V_246 ; V_92 ++ ) {
V_247 = F_157 ( V_2 , V_241 ) ;
if ( V_247 < 0 ) {
F_27 ( V_2 -> V_8 , L_82 ,
V_241 -> V_28 ,
V_241 -> V_239 ? V_241 -> V_239 : L_83 ,
V_241 -> V_19 ) ;
V_80 = V_247 ;
}
V_241 ++ ;
}
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_80 ;
}
int F_160 ( struct V_1 * V_2 ,
const struct V_240 * V_241 , int V_246 )
{
int V_92 , V_80 = 0 ;
F_81 ( & V_2 -> V_3 -> V_5 , V_248 ) ;
for ( V_92 = 0 ; V_92 < V_246 ; V_92 ++ ) {
F_158 ( V_2 , V_241 ) ;
V_241 ++ ;
}
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_80 ;
}
static int F_161 ( struct V_1 * V_2 ,
const struct V_240 * V_241 )
{
struct V_13 * V_28 = F_151 ( V_2 ,
V_241 -> V_28 ,
true ) ;
struct V_13 * V_19 = F_151 ( V_2 ,
V_241 -> V_19 ,
true ) ;
struct V_20 * V_67 ;
int V_197 = 0 ;
if ( ! V_28 ) {
F_27 ( V_2 -> V_8 , L_84 ,
V_241 -> V_28 ) ;
return - V_97 ;
}
if ( ! V_19 ) {
F_27 ( V_2 -> V_8 , L_85 ,
V_241 -> V_19 ) ;
return - V_97 ;
}
if ( V_241 -> V_239 || V_241 -> V_122 )
F_86 ( V_2 -> V_8 , L_86 ,
V_241 -> V_28 , V_241 -> V_19 ) ;
F_17 (path, &source->sinks, list_source) {
if ( V_67 -> V_19 == V_19 ) {
V_67 -> V_26 = 1 ;
V_197 ++ ;
}
}
if ( V_197 == 0 )
F_27 ( V_2 -> V_8 , L_87 ,
V_241 -> V_28 , V_241 -> V_19 ) ;
if ( V_197 > 1 )
F_86 ( V_2 -> V_8 , L_88 ,
V_197 , V_241 -> V_28 , V_241 -> V_19 ) ;
return 0 ;
}
int F_162 ( struct V_1 * V_2 ,
const struct V_240 * V_241 , int V_246 )
{
int V_92 , V_125 ;
int V_80 = 0 ;
F_81 ( & V_2 -> V_3 -> V_5 , V_248 ) ;
for ( V_92 = 0 ; V_92 < V_246 ; V_92 ++ ) {
V_125 = F_161 ( V_2 , V_241 ) ;
if ( V_125 )
V_80 = V_125 ;
V_241 ++ ;
}
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_80 ;
}
int F_163 ( struct V_30 * V_3 )
{
struct V_13 * V_14 ;
unsigned int V_90 ;
F_81 ( & V_3 -> V_5 , V_248 ) ;
F_17 (w, &card->widgets, list)
{
if ( V_14 -> V_249 )
continue;
if ( V_14 -> V_98 ) {
V_14 -> V_101 = F_26 ( V_14 -> V_98 *
sizeof( struct V_35 * ) ,
V_12 ) ;
if ( ! V_14 -> V_101 ) {
F_22 ( & V_3 -> V_5 ) ;
return - V_41 ;
}
}
switch( V_14 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
F_68 ( V_14 ) ;
break;
case V_110 :
F_69 ( V_14 ) ;
break;
case V_217 :
case V_218 :
F_70 ( V_14 ) ;
break;
default:
break;
}
if ( V_14 -> V_50 >= 0 ) {
F_47 ( V_14 -> V_2 , V_14 -> V_50 , & V_90 ) ;
V_90 = V_90 >> V_14 -> V_53 ;
V_90 &= V_14 -> V_51 ;
if ( V_90 == V_14 -> V_56 )
V_14 -> V_69 = 1 ;
}
V_14 -> V_249 = 1 ;
F_12 ( V_14 , L_89 ) ;
F_135 ( V_14 ) ;
}
F_121 ( V_3 , V_208 ) ;
F_22 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_164 ( struct V_35 * V_36 ,
struct V_250 * V_251 )
{
struct V_1 * V_2 = F_42 ( V_36 ) ;
struct V_30 * V_3 = V_2 -> V_3 ;
struct V_39 * V_40 =
(struct V_39 * ) V_36 -> V_47 ;
int V_50 = V_40 -> V_50 ;
unsigned int V_53 = V_40 -> V_53 ;
int V_52 = V_40 -> V_52 ;
unsigned int V_51 = ( 1 << F_29 ( V_52 ) ) - 1 ;
unsigned int V_54 = V_40 -> V_54 ;
unsigned int V_90 ;
int V_80 = 0 ;
if ( F_165 ( V_40 ) )
F_86 ( V_2 -> V_8 ,
L_90 ,
V_36 -> V_43 . V_17 ) ;
F_81 ( & V_3 -> V_5 , V_129 ) ;
if ( F_38 ( V_36 ) && V_50 != V_93 ) {
V_80 = F_47 ( V_2 , V_50 , & V_90 ) ;
V_90 = ( V_90 >> V_53 ) & V_51 ;
} else {
V_90 = F_40 ( V_36 ) ;
}
F_22 ( & V_3 -> V_5 ) ;
if ( V_54 )
V_251 -> V_58 . integer . V_58 [ 0 ] = V_52 - V_90 ;
else
V_251 -> V_58 . integer . V_58 [ 0 ] = V_90 ;
return V_80 ;
}
int F_166 ( struct V_35 * V_36 ,
struct V_250 * V_251 )
{
struct V_1 * V_2 = F_42 ( V_36 ) ;
struct V_30 * V_3 = V_2 -> V_3 ;
struct V_39 * V_40 =
(struct V_39 * ) V_36 -> V_47 ;
int V_50 = V_40 -> V_50 ;
unsigned int V_53 = V_40 -> V_53 ;
int V_52 = V_40 -> V_52 ;
unsigned int V_51 = ( 1 << F_29 ( V_52 ) ) - 1 ;
unsigned int V_54 = V_40 -> V_54 ;
unsigned int V_90 ;
int V_27 , V_252 , V_253 = 0 ;
struct V_170 V_171 ;
int V_80 = 0 ;
if ( F_165 ( V_40 ) )
F_86 ( V_2 -> V_8 ,
L_90 ,
V_36 -> V_43 . V_17 ) ;
V_90 = ( V_251 -> V_58 . integer . V_58 [ 0 ] & V_51 ) ;
V_27 = ! ! V_90 ;
if ( V_54 )
V_90 = V_52 - V_90 ;
F_81 ( & V_3 -> V_5 , V_129 ) ;
V_252 = F_41 ( V_36 , V_90 ) ;
if ( V_50 != V_93 ) {
V_51 = V_51 << V_53 ;
V_90 = V_90 << V_53 ;
V_253 = F_51 ( V_2 , V_50 , V_51 , V_90 ) ;
}
if ( V_252 || V_253 ) {
if ( V_253 ) {
V_171 . V_36 = V_36 ;
V_171 . V_50 = V_50 ;
V_171 . V_51 = V_51 ;
V_171 . V_90 = V_90 ;
V_3 -> V_171 = & V_171 ;
}
V_252 |= V_253 ;
V_80 = F_143 ( V_3 , V_36 , V_27 ) ;
V_3 -> V_171 = NULL ;
}
F_22 ( & V_3 -> V_5 ) ;
if ( V_80 > 0 )
F_142 ( V_3 ) ;
return V_252 ;
}
int F_167 ( struct V_35 * V_36 ,
struct V_250 * V_251 )
{
struct V_1 * V_2 = F_42 ( V_36 ) ;
struct V_88 * V_89 = (struct V_88 * ) V_36 -> V_47 ;
unsigned int V_254 , V_90 ;
if ( V_89 -> V_50 != V_93 ) {
int V_80 = F_47 ( V_2 , V_89 -> V_50 , & V_254 ) ;
if ( V_80 )
return V_80 ;
} else {
V_254 = F_40 ( V_36 ) ;
}
V_90 = ( V_254 >> V_89 -> V_94 ) & V_89 -> V_51 ;
V_251 -> V_58 . V_255 . V_91 [ 0 ] = F_59 ( V_89 , V_90 ) ;
if ( V_89 -> V_94 != V_89 -> V_256 ) {
V_90 = ( V_254 >> V_89 -> V_256 ) & V_89 -> V_51 ;
V_90 = F_59 ( V_89 , V_90 ) ;
V_251 -> V_58 . V_255 . V_91 [ 1 ] = V_90 ;
}
return 0 ;
}
int F_168 ( struct V_35 * V_36 ,
struct V_250 * V_251 )
{
struct V_1 * V_2 = F_42 ( V_36 ) ;
struct V_30 * V_3 = V_2 -> V_3 ;
struct V_88 * V_89 = (struct V_88 * ) V_36 -> V_47 ;
unsigned int * V_91 = V_251 -> V_58 . V_255 . V_91 ;
unsigned int V_90 , V_252 ;
unsigned int V_51 ;
struct V_170 V_171 ;
int V_80 = 0 ;
if ( V_91 [ 0 ] >= V_89 -> V_95 )
return - V_111 ;
V_90 = F_169 ( V_89 , V_91 [ 0 ] ) << V_89 -> V_94 ;
V_51 = V_89 -> V_51 << V_89 -> V_94 ;
if ( V_89 -> V_94 != V_89 -> V_256 ) {
if ( V_91 [ 1 ] > V_89 -> V_95 )
return - V_111 ;
V_90 |= F_169 ( V_89 , V_91 [ 1 ] ) << V_89 -> V_94 ;
V_51 |= V_89 -> V_51 << V_89 -> V_256 ;
}
F_81 ( & V_3 -> V_5 , V_129 ) ;
if ( V_89 -> V_50 != V_93 )
V_252 = F_51 ( V_2 , V_89 -> V_50 , V_51 , V_90 ) ;
else
V_252 = F_41 ( V_36 , V_90 ) ;
if ( V_252 ) {
if ( V_89 -> V_50 != V_93 ) {
V_171 . V_36 = V_36 ;
V_171 . V_50 = V_89 -> V_50 ;
V_171 . V_51 = V_51 ;
V_171 . V_90 = V_90 ;
V_3 -> V_171 = & V_171 ;
}
V_80 = F_139 ( V_3 , V_36 , V_91 [ 0 ] , V_89 ) ;
V_3 -> V_171 = NULL ;
}
F_22 ( & V_3 -> V_5 ) ;
if ( V_80 > 0 )
F_142 ( V_3 ) ;
return V_252 ;
}
int F_170 ( struct V_35 * V_36 ,
struct V_257 * V_258 )
{
V_258 -> type = V_259 ;
V_258 -> V_197 = 1 ;
V_258 -> V_58 . integer . V_260 = 0 ;
V_258 -> V_58 . integer . V_52 = 1 ;
return 0 ;
}
int F_171 ( struct V_35 * V_36 ,
struct V_250 * V_251 )
{
struct V_30 * V_3 = F_32 ( V_36 ) ;
const char * V_229 = ( const char * ) V_36 -> V_47 ;
F_81 ( & V_3 -> V_5 , V_129 ) ;
V_251 -> V_58 . integer . V_58 [ 0 ] =
F_172 ( & V_3 -> V_2 , V_229 ) ;
F_22 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_173 ( struct V_35 * V_36 ,
struct V_250 * V_251 )
{
struct V_30 * V_3 = F_32 ( V_36 ) ;
const char * V_229 = ( const char * ) V_36 -> V_47 ;
if ( V_251 -> V_58 . integer . V_58 [ 0 ] )
F_174 ( & V_3 -> V_2 , V_229 ) ;
else
F_175 ( & V_3 -> V_2 , V_229 ) ;
F_154 ( & V_3 -> V_2 ) ;
return 0 ;
}
static struct V_13 *
F_30 ( struct V_1 * V_2 ,
const struct V_13 * V_34 )
{
struct V_13 * V_14 ;
const char * V_104 ;
int V_80 ;
if ( ( V_14 = F_23 ( V_34 ) ) == NULL )
return NULL ;
switch ( V_14 -> V_43 ) {
case V_191 :
V_14 -> V_135 = F_176 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_177 ( V_14 -> V_135 ) ) {
V_80 = F_178 ( V_14 -> V_135 ) ;
F_27 ( V_2 -> V_8 , L_91 ,
V_14 -> V_17 , V_80 ) ;
return NULL ;
}
if ( V_14 -> V_56 & V_134 ) {
V_80 = F_85 ( V_14 -> V_135 , true ) ;
if ( V_80 != 0 )
F_86 ( V_14 -> V_2 -> V_8 ,
L_15 ,
V_14 -> V_17 , V_80 ) ;
}
break;
case V_192 :
#ifdef F_179
V_14 -> V_136 = F_180 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_177 ( V_14 -> V_136 ) ) {
V_80 = F_178 ( V_14 -> V_136 ) ;
F_27 ( V_2 -> V_8 , L_91 ,
V_14 -> V_17 , V_80 ) ;
return NULL ;
}
#else
return NULL ;
#endif
break;
default:
break;
}
V_104 = F_46 ( V_2 ) ;
if ( V_104 )
V_14 -> V_17 = F_64 ( V_12 , L_5 , V_104 , V_34 -> V_17 ) ;
else
V_14 -> V_17 = F_64 ( V_12 , L_1 , V_34 -> V_17 ) ;
if ( V_14 -> V_17 == NULL ) {
F_9 ( V_14 ) ;
return NULL ;
}
switch ( V_14 -> V_43 ) {
case V_212 :
V_14 -> V_32 = 1 ;
V_14 -> V_138 = F_94 ;
break;
case V_233 :
if ( ! V_2 -> V_3 -> V_234 )
V_14 -> V_32 = 1 ;
V_14 -> V_138 = F_94 ;
break;
case V_213 :
case V_211 :
V_14 -> V_31 = 1 ;
V_14 -> V_138 = F_94 ;
break;
case V_235 :
if ( ! V_2 -> V_3 -> V_234 )
V_14 -> V_31 = 1 ;
V_14 -> V_138 = F_94 ;
break;
case V_189 :
case V_188 :
V_14 -> V_32 = 1 ;
V_14 -> V_138 = F_96 ;
break;
case V_110 :
case V_44 :
case V_45 :
case V_46 :
case V_216 :
case V_261 :
case V_215 :
case V_262 :
case V_217 :
case V_218 :
case V_193 :
case V_214 :
case V_263 :
case V_264 :
case V_265 :
V_14 -> V_138 = F_94 ;
break;
case V_190 :
case V_191 :
case V_192 :
case V_57 :
V_14 -> V_25 = 1 ;
V_14 -> V_138 = F_95 ;
break;
default:
V_14 -> V_138 = F_96 ;
break;
}
V_14 -> V_2 = V_2 ;
F_28 ( & V_14 -> V_114 ) ;
F_28 ( & V_14 -> V_236 ) ;
F_28 ( & V_14 -> V_22 ) ;
F_28 ( & V_14 -> V_15 ) ;
F_156 ( & V_14 -> V_22 , & V_2 -> V_3 -> V_66 ) ;
V_14 -> V_23 = - 1 ;
V_14 -> V_29 = - 1 ;
V_14 -> V_122 = 1 ;
return V_14 ;
}
int F_181 ( struct V_1 * V_2 ,
const struct V_13 * V_34 ,
int V_246 )
{
struct V_13 * V_14 ;
int V_92 ;
int V_80 = 0 ;
F_81 ( & V_2 -> V_3 -> V_5 , V_248 ) ;
for ( V_92 = 0 ; V_92 < V_246 ; V_92 ++ ) {
V_14 = F_30 ( V_2 , V_34 ) ;
if ( ! V_14 ) {
F_27 ( V_2 -> V_8 ,
L_92 ,
V_34 -> V_17 ) ;
V_80 = - V_41 ;
break;
}
V_34 ++ ;
}
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_80 ;
}
static int F_182 ( struct V_13 * V_14 ,
struct V_35 * V_36 , int V_133 )
{
struct V_20 * V_266 , * V_267 ;
struct V_126 * V_28 , * V_19 ;
const struct V_268 * V_269 = V_14 -> V_270 ;
struct V_271 V_272 ;
struct V_273 * V_270 = NULL ;
T_8 V_9 ;
int V_80 ;
if ( F_105 ( ! V_269 ) ||
F_105 ( F_11 ( & V_14 -> V_114 ) || F_11 ( & V_14 -> V_236 ) ) )
return - V_111 ;
V_266 = F_104 ( & V_14 -> V_114 , struct V_20 ,
V_225 ) ;
V_267 = F_104 ( & V_14 -> V_236 , struct V_20 ,
V_226 ) ;
if ( F_105 ( ! V_266 || ! V_267 ) ||
F_105 ( ! V_267 -> V_28 || ! V_266 -> V_19 ) ||
F_105 ( ! V_266 -> V_28 || ! V_267 -> V_19 ) )
return - V_111 ;
V_28 = V_266 -> V_28 -> V_274 ;
V_19 = V_267 -> V_19 -> V_274 ;
if ( V_269 -> V_275 ) {
V_9 = F_183 ( V_269 -> V_275 ) - 1 ;
} else {
F_86 ( V_14 -> V_2 -> V_8 , L_93 ,
V_269 -> V_275 ) ;
V_9 = 0 ;
}
V_270 = F_26 ( sizeof( * V_270 ) , V_12 ) ;
if ( ! V_270 ) {
V_80 = - V_41 ;
goto V_82;
}
F_184 ( F_185 ( V_270 , V_276 ) , V_9 ) ;
F_186 ( V_270 , V_277 ) -> V_260 =
V_269 -> V_278 ;
F_186 ( V_270 , V_277 ) -> V_52 =
V_269 -> V_279 ;
F_186 ( V_270 , V_280 ) -> V_260
= V_269 -> V_281 ;
F_186 ( V_270 , V_280 ) -> V_52
= V_269 -> V_282 ;
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
switch ( V_133 ) {
case V_151 :
V_272 . V_128 = V_283 ;
V_80 = F_187 ( & V_272 , V_270 , V_28 ) ;
if ( V_80 < 0 )
goto V_82;
V_272 . V_128 = V_130 ;
V_80 = F_187 ( & V_272 , V_270 , V_19 ) ;
if ( V_80 < 0 )
goto V_82;
break;
case V_152 :
V_80 = F_188 ( V_19 , 0 ,
V_130 ) ;
if ( V_80 != 0 && V_80 != - V_284 )
F_86 ( V_19 -> V_8 , L_94 , V_80 ) ;
V_80 = 0 ;
break;
case V_153 :
V_80 = F_188 ( V_19 , 1 ,
V_130 ) ;
if ( V_80 != 0 && V_80 != - V_284 )
F_86 ( V_19 -> V_8 , L_95 , V_80 ) ;
V_80 = 0 ;
break;
default:
F_100 ( 1 , L_22 , V_133 ) ;
return - V_111 ;
}
V_82:
F_9 ( V_270 ) ;
return V_80 ;
}
int F_189 ( struct V_30 * V_3 ,
const struct V_268 * V_270 ,
struct V_13 * V_28 ,
struct V_13 * V_19 )
{
struct V_13 V_49 ;
struct V_13 * V_14 ;
T_3 V_285 ;
char * V_286 ;
int V_80 ;
V_285 = strlen ( V_28 -> V_17 ) + strlen ( V_19 -> V_17 ) + 2 ;
V_286 = F_190 ( V_3 -> V_8 , V_285 , V_12 ) ;
if ( ! V_286 )
return - V_41 ;
snprintf ( V_286 , V_285 , L_96 , V_28 -> V_17 , V_19 -> V_17 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_50 = V_93 ;
V_49 . V_43 = V_263 ;
V_49 . V_17 = V_286 ;
V_49 . V_133 = F_182 ;
V_49 . V_157 = V_151 | V_152 |
V_153 ;
F_73 ( V_3 -> V_8 , L_97 , V_286 ) ;
V_14 = F_30 ( & V_3 -> V_2 , & V_49 ) ;
if ( ! V_14 ) {
F_27 ( V_3 -> V_8 , L_98 ,
V_286 ) ;
return - V_41 ;
}
V_14 -> V_270 = V_270 ;
V_80 = F_37 ( & V_3 -> V_2 , V_28 , V_14 , NULL , NULL ) ;
if ( V_80 )
return V_80 ;
return F_37 ( & V_3 -> V_2 , V_14 , V_19 , NULL , NULL ) ;
}
int F_191 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
struct V_13 V_49 ;
struct V_13 * V_14 ;
F_105 ( V_2 -> V_8 != V_127 -> V_8 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_50 = V_93 ;
if ( V_127 -> V_287 -> V_288 . V_289 ) {
V_49 . V_43 = V_265 ;
V_49 . V_17 = V_127 -> V_287 -> V_288 . V_289 ;
V_49 . V_199 = V_127 -> V_287 -> V_288 . V_289 ;
F_73 ( V_127 -> V_8 , L_97 ,
V_49 . V_17 ) ;
V_14 = F_30 ( V_2 , & V_49 ) ;
if ( ! V_14 ) {
F_27 ( V_2 -> V_8 , L_98 ,
V_127 -> V_287 -> V_288 . V_289 ) ;
return - V_41 ;
}
V_14 -> V_274 = V_127 ;
V_127 -> V_131 = V_14 ;
}
if ( V_127 -> V_287 -> V_290 . V_289 ) {
V_49 . V_43 = V_264 ;
V_49 . V_17 = V_127 -> V_287 -> V_290 . V_289 ;
V_49 . V_199 = V_127 -> V_287 -> V_290 . V_289 ;
F_73 ( V_127 -> V_8 , L_97 ,
V_49 . V_17 ) ;
V_14 = F_30 ( V_2 , & V_49 ) ;
if ( ! V_14 ) {
F_27 ( V_2 -> V_8 , L_98 ,
V_127 -> V_287 -> V_290 . V_289 ) ;
return - V_41 ;
}
V_14 -> V_274 = V_127 ;
V_127 -> V_132 = V_14 ;
}
return 0 ;
}
int F_192 ( struct V_30 * V_3 )
{
struct V_13 * V_291 , * V_14 ;
struct V_13 * V_292 , * V_19 ;
struct V_126 * V_127 ;
F_17 (dai_w, &card->widgets, list) {
switch ( V_291 -> V_43 ) {
case V_265 :
case V_264 :
break;
default:
continue;
}
V_127 = V_291 -> V_274 ;
F_17 (w, &card->widgets, list) {
if ( V_14 -> V_2 != V_291 -> V_2 )
continue;
switch ( V_14 -> V_43 ) {
case V_265 :
case V_264 :
continue;
default:
break;
}
if ( ! V_14 -> V_199 || ! strstr ( V_14 -> V_199 , V_291 -> V_17 ) )
continue;
if ( V_291 -> V_43 == V_265 ) {
V_292 = V_291 ;
V_19 = V_14 ;
} else {
V_292 = V_14 ;
V_19 = V_291 ;
}
F_73 ( V_127 -> V_8 , L_99 , V_292 -> V_17 , V_19 -> V_17 ) ;
F_37 ( V_14 -> V_2 , V_292 , V_19 , NULL , NULL ) ;
}
}
return 0 ;
}
static void F_193 ( struct V_30 * V_3 ,
struct V_221 * V_222 )
{
struct V_126 * V_293 = V_222 -> V_293 ;
struct V_13 * V_19 , * V_28 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_222 -> V_223 ; V_92 ++ ) {
struct V_126 * V_294 = V_222 -> V_224 [ V_92 ] ;
if ( F_194 ( V_294 ) ||
F_194 ( V_293 ) )
continue;
if ( V_294 -> V_131 && V_293 -> V_131 ) {
V_28 = V_293 -> V_131 ;
V_19 = V_294 -> V_131 ;
F_73 ( V_222 -> V_8 , L_100 ,
V_293 -> V_75 -> V_17 , V_28 -> V_17 ,
V_294 -> V_75 -> V_17 , V_19 -> V_17 ) ;
F_37 ( & V_3 -> V_2 , V_28 , V_19 ,
NULL , NULL ) ;
}
if ( V_294 -> V_132 && V_293 -> V_132 ) {
V_28 = V_294 -> V_132 ;
V_19 = V_293 -> V_132 ;
F_73 ( V_222 -> V_8 , L_100 ,
V_294 -> V_75 -> V_17 , V_28 -> V_17 ,
V_293 -> V_75 -> V_17 , V_19 -> V_17 ) ;
F_37 ( & V_3 -> V_2 , V_28 , V_19 ,
NULL , NULL ) ;
}
}
}
static void F_195 ( struct V_126 * V_127 , int V_128 ,
int V_133 )
{
struct V_13 * V_14 ;
if ( V_128 == V_130 )
V_14 = V_127 -> V_131 ;
else
V_14 = V_127 -> V_132 ;
if ( V_14 ) {
F_12 ( V_14 , L_101 ) ;
switch ( V_133 ) {
case V_167 :
V_14 -> V_200 = 1 ;
break;
case V_168 :
V_14 -> V_200 = 0 ;
break;
case V_295 :
case V_296 :
case V_297 :
case V_298 :
break;
}
if ( V_14 -> V_43 == V_265 ) {
V_14 -> V_32 = V_14 -> V_200 ;
F_15 ( V_14 ) ;
} else {
V_14 -> V_31 = V_14 -> V_200 ;
F_18 ( V_14 ) ;
}
}
}
void F_196 ( struct V_30 * V_3 )
{
struct V_221 * V_222 = V_3 -> V_222 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_3 -> V_299 ; V_92 ++ ) {
V_222 = & V_3 -> V_222 [ V_92 ] ;
if ( V_222 -> V_300 -> V_301 || V_222 -> V_300 -> V_270 )
continue;
F_193 ( V_3 , V_222 ) ;
}
}
static void F_197 ( struct V_221 * V_222 , int V_128 ,
int V_133 )
{
int V_92 ;
F_195 ( V_222 -> V_293 , V_128 , V_133 ) ;
for ( V_92 = 0 ; V_92 < V_222 -> V_223 ; V_92 ++ )
F_195 ( V_222 -> V_224 [ V_92 ] , V_128 , V_133 ) ;
F_121 ( V_222 -> V_3 , V_133 ) ;
}
void F_198 ( struct V_221 * V_222 , int V_128 ,
int V_133 )
{
struct V_30 * V_3 = V_222 -> V_3 ;
F_81 ( & V_3 -> V_5 , V_129 ) ;
F_197 ( V_222 , V_128 , V_133 ) ;
F_22 ( & V_3 -> V_5 ) ;
}
int F_199 ( struct V_1 * V_2 ,
const char * V_229 )
{
return F_152 ( V_2 , V_229 , 1 ) ;
}
int F_174 ( struct V_1 * V_2 , const char * V_229 )
{
int V_80 ;
F_81 ( & V_2 -> V_3 -> V_5 , V_129 ) ;
V_80 = F_152 ( V_2 , V_229 , 1 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_80 ;
}
int F_200 ( struct V_1 * V_2 ,
const char * V_229 )
{
struct V_13 * V_14 = F_151 ( V_2 , V_229 , true ) ;
if ( ! V_14 ) {
F_27 ( V_2 -> V_8 , L_102 , V_229 ) ;
return - V_111 ;
}
F_73 ( V_14 -> V_2 -> V_8 , L_103 , V_229 ) ;
if ( ! V_14 -> V_122 ) {
F_15 ( V_14 ) ;
F_18 ( V_14 ) ;
V_14 -> V_122 = 1 ;
}
V_14 -> V_137 = 1 ;
F_12 ( V_14 , L_104 ) ;
return 0 ;
}
int F_201 ( struct V_1 * V_2 ,
const char * V_229 )
{
int V_80 ;
F_81 ( & V_2 -> V_3 -> V_5 , V_129 ) ;
V_80 = F_200 ( V_2 , V_229 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_80 ;
}
int F_202 ( struct V_1 * V_2 ,
const char * V_229 )
{
return F_152 ( V_2 , V_229 , 0 ) ;
}
int F_175 ( struct V_1 * V_2 ,
const char * V_229 )
{
int V_80 ;
F_81 ( & V_2 -> V_3 -> V_5 , V_129 ) ;
V_80 = F_152 ( V_2 , V_229 , 0 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_80 ;
}
int F_203 ( struct V_1 * V_2 ,
const char * V_229 )
{
return F_152 ( V_2 , V_229 , 0 ) ;
}
int F_204 ( struct V_1 * V_2 , const char * V_229 )
{
int V_80 ;
F_81 ( & V_2 -> V_3 -> V_5 , V_129 ) ;
V_80 = F_152 ( V_2 , V_229 , 0 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_80 ;
}
int F_172 ( struct V_1 * V_2 ,
const char * V_229 )
{
struct V_13 * V_14 = F_151 ( V_2 , V_229 , true ) ;
if ( V_14 )
return V_14 -> V_122 ;
return 0 ;
}
int F_205 ( struct V_1 * V_2 ,
const char * V_229 )
{
struct V_13 * V_14 = F_151 ( V_2 , V_229 , false ) ;
if ( ! V_14 ) {
F_27 ( V_2 -> V_8 , L_102 , V_229 ) ;
return - V_111 ;
}
V_14 -> V_117 = 1 ;
return 0 ;
}
void F_206 ( struct V_1 * V_2 )
{
F_136 ( V_2 ) ;
F_150 ( V_2 ) ;
F_149 ( & V_2 -> V_22 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_30 * V_3 = V_2 -> V_3 ;
struct V_13 * V_14 ;
F_16 ( V_183 ) ;
int V_302 = 0 ;
F_21 ( & V_3 -> V_5 ) ;
F_17 (w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
if ( V_14 -> V_69 ) {
F_98 ( V_14 , & V_183 , false ) ;
V_14 -> V_69 = 0 ;
V_302 = 1 ;
}
}
if ( V_302 ) {
if ( V_2 -> V_83 == V_179 )
F_55 ( V_2 ,
V_180 ) ;
F_106 ( V_3 , & V_183 , 0 , false ) ;
if ( V_2 -> V_83 == V_180 )
F_55 ( V_2 ,
V_178 ) ;
}
F_22 ( & V_3 -> V_5 ) ;
}
void F_208 ( struct V_30 * V_3 )
{
struct V_1 * V_2 ;
F_17 (dapm, &card->dapm_list, list) {
if ( V_2 != & V_3 -> V_2 ) {
F_207 ( V_2 ) ;
if ( V_2 -> V_83 == V_178 )
F_55 ( V_2 ,
V_176 ) ;
}
}
F_207 ( & V_3 -> V_2 ) ;
if ( V_3 -> V_2 . V_83 == V_178 )
F_55 ( & V_3 -> V_2 ,
V_176 ) ;
}
