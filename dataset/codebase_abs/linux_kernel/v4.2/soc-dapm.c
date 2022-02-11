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
struct V_41 * V_42 ;
const char * V_17 ;
int V_43 ;
V_38 = F_26 ( sizeof( * V_38 ) , V_12 ) ;
if ( ! V_38 )
return - V_44 ;
F_27 ( & V_38 -> V_45 ) ;
switch ( V_34 -> V_46 ) {
case V_47 :
case V_48 :
case V_49 :
V_40 = (struct V_39 * ) V_36 -> V_50 ;
if ( V_40 -> V_51 ) {
struct V_13 V_52 ;
V_17 = F_28 ( V_12 , L_4 , V_36 -> V_46 . V_17 ,
L_5 ) ;
if ( ! V_17 ) {
V_43 = - V_44 ;
goto V_53;
}
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_54 = V_40 -> V_54 ;
V_52 . V_55 = ( 1 << F_29 ( V_40 -> V_56 ) ) - 1 ;
V_52 . V_57 = V_40 -> V_57 ;
if ( V_40 -> V_58 )
V_52 . V_59 = V_40 -> V_56 ;
else
V_52 . V_59 = 0 ;
V_52 . V_60 = V_52 . V_59 ;
V_52 . V_46 = V_61 ;
V_52 . V_17 = V_17 ;
V_38 -> V_62 = V_52 . V_60 ;
V_38 -> V_34 =
F_30 ( V_34 -> V_2 ,
& V_52 ) ;
F_9 ( V_17 ) ;
if ( ! V_38 -> V_34 ) {
V_43 = - V_44 ;
goto V_53;
}
}
break;
case V_63 :
case V_64 :
V_42 = (struct V_41 * ) V_36 -> V_50 ;
if ( V_42 -> V_51 ) {
struct V_13 V_52 ;
V_17 = F_28 ( V_12 , L_4 , V_36 -> V_46 . V_17 ,
L_5 ) ;
if ( ! V_17 ) {
V_43 = - V_44 ;
goto V_53;
}
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_54 = V_42 -> V_54 ;
V_52 . V_55 = V_42 -> V_55 << V_42 -> V_65 ;
V_52 . V_57 = V_42 -> V_65 ;
V_52 . V_59 = F_31 ( V_42 , 0 ) ;
V_52 . V_60 = V_52 . V_59 ;
V_52 . V_46 = V_61 ;
V_52 . V_17 = V_17 ;
V_38 -> V_62 = V_52 . V_60 ;
V_38 -> V_34 = F_30 (
V_34 -> V_2 , & V_52 ) ;
F_9 ( V_17 ) ;
if ( ! V_38 -> V_34 ) {
V_43 = - V_44 ;
goto V_53;
}
F_32 ( V_34 -> V_2 , V_38 -> V_34 ,
V_34 , NULL , NULL ) ;
}
break;
default:
break;
}
V_36 -> V_66 = V_38 ;
return 0 ;
V_53:
F_9 ( V_38 ) ;
return V_43 ;
}
static void F_33 ( struct V_35 * V_67 )
{
struct V_37 * V_38 = F_34 ( V_67 ) ;
F_9 ( V_38 -> V_68 ) ;
F_9 ( V_38 ) ;
}
static struct V_69 * F_35 (
const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_34 ( V_36 ) ;
return V_38 -> V_68 ;
}
static int F_36 ( struct V_35 * V_36 ,
struct V_13 * V_34 )
{
struct V_37 * V_38 = F_34 ( V_36 ) ;
struct V_69 * V_70 ;
unsigned int V_71 ;
if ( V_38 -> V_68 )
V_71 = V_38 -> V_68 -> V_72 + 1 ;
else
V_71 = 1 ;
V_70 = F_37 ( V_38 -> V_68 ,
sizeof( * V_70 ) + sizeof( V_34 ) * V_71 , V_12 ) ;
if ( ! V_70 )
return - V_44 ;
V_70 -> V_73 [ V_71 - 1 ] = V_34 ;
V_70 -> V_72 = V_71 ;
V_38 -> V_68 = V_70 ;
return 0 ;
}
static void F_38 ( const struct V_35 * V_36 ,
struct V_20 * V_74 )
{
struct V_37 * V_38 = F_34 ( V_36 ) ;
F_14 ( & V_74 -> V_75 , & V_38 -> V_45 ) ;
}
static bool F_39 ( const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_34 ( V_36 ) ;
if ( ! V_38 -> V_34 )
return true ;
return V_38 -> V_34 -> V_76 ;
}
static struct V_77 * F_40 (
const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_34 ( V_36 ) ;
return & V_38 -> V_45 ;
}
unsigned int F_41 ( const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_34 ( V_36 ) ;
return V_38 -> V_62 ;
}
static bool F_42 ( const struct V_35 * V_36 ,
unsigned int V_62 )
{
struct V_37 * V_38 = F_34 ( V_36 ) ;
if ( V_38 -> V_62 == V_62 )
return false ;
if ( V_38 -> V_34 )
V_38 -> V_34 -> V_60 = V_62 ;
V_38 -> V_62 = V_62 ;
return true ;
}
struct V_1 * F_43 (
struct V_35 * V_36 )
{
return F_35 ( V_36 ) -> V_73 [ 0 ] -> V_2 ;
}
static void F_44 ( struct V_30 * V_3 )
{
struct V_13 * V_14 ;
F_2 ( & V_3 -> V_5 ) ;
memset ( & V_3 -> V_78 , 0 , sizeof( V_3 -> V_78 ) ) ;
F_17 (w, &card->widgets, list) {
V_14 -> V_79 = V_14 -> V_76 ;
V_14 -> V_80 = false ;
}
}
static const char * F_45 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_81 )
return NULL ;
return V_2 -> V_81 -> V_82 ;
}
static int F_46 ( struct V_1 * V_2 , int V_54 ,
unsigned int * V_62 )
{
if ( ! V_2 -> V_81 )
return - V_83 ;
return F_47 ( V_2 -> V_81 , V_54 , V_62 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
int V_54 , unsigned int V_55 , unsigned int V_62 )
{
if ( ! V_2 -> V_81 )
return - V_83 ;
return F_49 ( V_2 -> V_81 , V_54 ,
V_55 , V_62 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_54 , unsigned int V_55 , unsigned int V_62 )
{
if ( ! V_2 -> V_81 )
return - V_83 ;
return F_51 ( V_2 -> V_81 , V_54 , V_55 , V_62 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_81 )
F_53 ( V_2 -> V_81 ) ;
}
static struct V_13 *
F_54 ( struct V_84 * V_85 , const char * V_17 )
{
struct V_13 * V_14 = V_85 -> V_34 ;
struct V_77 * V_68 ;
const int V_86 = 2 ;
int V_87 = 0 ;
if ( V_14 ) {
V_68 = & V_14 -> V_2 -> V_3 -> V_73 ;
F_55 (w, wlist, list) {
if ( ! strcmp ( V_17 , V_14 -> V_17 ) )
return V_14 ;
if ( ++ V_87 == V_86 )
break;
}
}
return NULL ;
}
static inline void F_56 ( struct V_84 * V_85 ,
struct V_13 * V_14 )
{
V_85 -> V_34 = V_14 ;
}
int F_57 ( struct V_1 * V_2 ,
enum V_88 V_89 )
{
int V_43 = 0 ;
if ( V_2 -> V_90 )
V_43 = V_2 -> V_90 ( V_2 , V_89 ) ;
if ( V_43 == 0 )
V_2 -> V_91 = V_89 ;
return V_43 ;
}
static int F_58 ( struct V_1 * V_2 ,
enum V_88 V_89 )
{
struct V_30 * V_3 = V_2 -> V_3 ;
int V_43 = 0 ;
F_59 ( V_3 , V_89 ) ;
if ( V_3 && V_3 -> V_90 )
V_43 = V_3 -> V_90 ( V_3 , V_2 , V_89 ) ;
if ( V_43 != 0 )
goto V_92;
if ( ! V_3 || V_2 != & V_3 -> V_2 )
V_43 = F_57 ( V_2 , V_89 ) ;
if ( V_43 != 0 )
goto V_92;
if ( V_3 && V_3 -> V_93 )
V_43 = V_3 -> V_93 ( V_3 , V_2 , V_89 ) ;
V_92:
F_60 ( V_3 , V_89 ) ;
return V_43 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_20 * V_74 , const char * V_94 ,
struct V_13 * V_14 )
{
const struct V_95 * V_36 = & V_14 -> V_96 [ 0 ] ;
struct V_41 * V_42 = (struct V_41 * ) V_36 -> V_50 ;
unsigned int V_97 , V_98 ;
int V_87 ;
if ( V_42 -> V_54 != V_99 ) {
F_46 ( V_2 , V_42 -> V_54 , & V_97 ) ;
V_97 = ( V_97 >> V_42 -> V_65 ) & V_42 -> V_55 ;
V_98 = F_62 ( V_42 , V_97 ) ;
} else {
V_98 = 0 ;
}
for ( V_87 = 0 ; V_87 < V_42 -> V_100 ; V_87 ++ ) {
if ( ! ( strcmp ( V_94 , V_42 -> V_101 [ V_87 ] ) ) ) {
V_74 -> V_17 = V_42 -> V_101 [ V_87 ] ;
if ( V_87 == V_98 )
V_74 -> V_27 = 1 ;
else
V_74 -> V_27 = 0 ;
return 0 ;
}
}
return - V_102 ;
}
static void F_63 ( struct V_20 * V_21 , int V_87 )
{
struct V_39 * V_40 = (struct V_39 * )
V_21 -> V_19 -> V_96 [ V_87 ] . V_50 ;
unsigned int V_54 = V_40 -> V_54 ;
unsigned int V_57 = V_40 -> V_57 ;
unsigned int V_56 = V_40 -> V_56 ;
unsigned int V_55 = ( 1 << F_29 ( V_56 ) ) - 1 ;
unsigned int V_58 = V_40 -> V_58 ;
unsigned int V_97 ;
if ( V_54 != V_99 ) {
F_46 ( V_21 -> V_19 -> V_2 , V_54 , & V_97 ) ;
V_97 = ( V_97 >> V_57 ) & V_55 ;
if ( V_58 )
V_97 = V_56 - V_97 ;
V_21 -> V_27 = ! ! V_97 ;
} else {
V_21 -> V_27 = 0 ;
}
}
static int F_64 ( struct V_1 * V_2 ,
struct V_20 * V_74 , const char * V_94 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_74 -> V_19 -> V_103 ; V_87 ++ ) {
if ( ! strcmp ( V_94 , V_74 -> V_19 -> V_96 [ V_87 ] . V_17 ) ) {
V_74 -> V_17 = V_74 -> V_19 -> V_96 [ V_87 ] . V_17 ;
F_63 ( V_74 , V_87 ) ;
return 0 ;
}
}
return - V_102 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_13 * V_104 ,
const struct V_95 * V_105 ,
struct V_35 * * V_36 )
{
struct V_13 * V_14 ;
int V_87 ;
* V_36 = NULL ;
F_17 (w, &dapm->card->widgets, list) {
if ( V_14 == V_104 || V_14 -> V_2 != V_104 -> V_2 )
continue;
for ( V_87 = 0 ; V_87 < V_14 -> V_103 ; V_87 ++ ) {
if ( & V_14 -> V_96 [ V_87 ] == V_105 ) {
if ( V_14 -> V_106 )
* V_36 = V_14 -> V_106 [ V_87 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_66 ( struct V_13 * V_14 ,
int V_107 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_108 * V_3 = V_2 -> V_3 -> V_108 ;
const char * V_109 ;
T_3 V_110 ;
int V_111 ;
struct V_35 * V_36 ;
bool V_112 , V_113 ;
char * V_114 = NULL ;
const char * V_17 ;
int V_43 = 0 ;
V_109 = F_45 ( V_2 ) ;
if ( V_109 )
V_110 = strlen ( V_109 ) + 1 ;
else
V_110 = 0 ;
V_111 = F_65 ( V_2 , V_14 , & V_14 -> V_96 [ V_107 ] ,
& V_36 ) ;
if ( ! V_36 ) {
if ( V_111 ) {
V_112 = false ;
V_113 = true ;
} else {
switch ( V_14 -> V_46 ) {
case V_47 :
case V_48 :
V_112 = true ;
V_113 = true ;
break;
case V_49 :
V_112 = false ;
V_113 = true ;
break;
case V_63 :
case V_64 :
V_112 = true ;
V_113 = false ;
break;
default:
return - V_115 ;
}
}
if ( V_112 && V_113 ) {
V_114 = F_28 ( V_12 , L_4 ,
V_14 -> V_17 + V_110 ,
V_14 -> V_96 [ V_107 ] . V_17 ) ;
if ( V_114 == NULL )
return - V_44 ;
V_17 = V_114 ;
} else if ( V_112 ) {
V_114 = NULL ;
V_17 = V_14 -> V_17 + V_110 ;
} else {
V_114 = NULL ;
V_17 = V_14 -> V_96 [ V_107 ] . V_17 ;
}
V_36 = F_67 ( & V_14 -> V_96 [ V_107 ] , NULL , V_17 ,
V_109 ) ;
if ( ! V_36 ) {
V_43 = - V_44 ;
goto V_116;
}
V_36 -> V_117 = F_33 ;
V_43 = F_25 ( V_14 , V_36 ) ;
if ( V_43 ) {
F_68 ( V_36 ) ;
goto V_116;
}
V_43 = F_69 ( V_3 , V_36 ) ;
if ( V_43 < 0 ) {
F_70 ( V_2 -> V_8 ,
L_6 ,
V_14 -> V_17 , V_17 , V_43 ) ;
goto V_116;
}
}
V_43 = F_36 ( V_36 , V_14 ) ;
if ( V_43 == 0 )
V_14 -> V_106 [ V_107 ] = V_36 ;
V_116:
F_9 ( V_114 ) ;
return V_43 ;
}
static int F_71 ( struct V_13 * V_14 )
{
int V_87 , V_43 ;
struct V_20 * V_74 ;
struct V_37 * V_38 ;
for ( V_87 = 0 ; V_87 < V_14 -> V_103 ; V_87 ++ ) {
F_17 (path, &w->sources, list_sink) {
if ( V_74 -> V_17 != ( char * ) V_14 -> V_96 [ V_87 ] . V_17 )
continue;
if ( ! V_14 -> V_106 [ V_87 ] ) {
V_43 = F_66 ( V_14 , V_87 ) ;
if ( V_43 < 0 )
return V_43 ;
}
F_38 ( V_14 -> V_106 [ V_87 ] , V_74 ) ;
V_38 = F_34 ( V_14 -> V_106 [ V_87 ] ) ;
if ( V_38 -> V_34 )
F_32 ( V_38 -> V_34 -> V_2 ,
V_38 -> V_34 ,
V_74 -> V_28 ,
NULL , NULL ) ;
}
}
return 0 ;
}
static int F_72 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_20 * V_74 ;
struct V_77 * V_45 ;
const char * type ;
int V_43 ;
switch ( V_14 -> V_46 ) {
case V_64 :
V_45 = & V_14 -> V_118 ;
type = L_7 ;
break;
case V_63 :
V_45 = & V_14 -> V_119 ;
type = L_8 ;
break;
default:
return - V_115 ;
}
if ( V_14 -> V_103 != 1 ) {
F_70 ( V_2 -> V_8 ,
L_9 , type ,
V_14 -> V_17 ) ;
return - V_115 ;
}
if ( F_11 ( V_45 ) ) {
F_70 ( V_2 -> V_8 , L_10 , type , V_14 -> V_17 ) ;
return - V_115 ;
}
V_43 = F_66 ( V_14 , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_14 -> V_46 == V_64 ) {
F_17 (path, &w->sources, list_sink) {
if ( V_74 -> V_17 )
F_38 ( V_14 -> V_106 [ 0 ] , V_74 ) ;
}
} else {
F_17 (path, &w->sinks, list_source) {
if ( V_74 -> V_17 )
F_38 ( V_14 -> V_106 [ 0 ] , V_74 ) ;
}
}
return 0 ;
}
static int F_73 ( struct V_13 * V_14 )
{
if ( V_14 -> V_103 )
F_70 ( V_14 -> V_2 -> V_8 ,
L_11 , V_14 -> V_17 ) ;
return 0 ;
}
static int F_74 ( struct V_13 * V_14 )
{
int V_87 , V_43 ;
struct V_35 * V_36 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_108 * V_3 = V_2 -> V_3 -> V_108 ;
if ( V_14 -> V_120 <= 1 )
return 0 ;
for ( V_87 = 0 ; V_87 < V_14 -> V_103 ; V_87 ++ ) {
V_36 = F_67 ( & V_14 -> V_96 [ V_87 ] , V_14 ,
V_14 -> V_17 , NULL ) ;
V_43 = F_69 ( V_3 , V_36 ) ;
if ( V_43 < 0 ) {
F_70 ( V_2 -> V_8 ,
L_6 ,
V_14 -> V_17 , V_14 -> V_96 [ V_87 ] . V_17 , V_43 ) ;
return V_43 ;
}
V_36 -> V_66 = V_14 ;
V_14 -> V_106 [ V_87 ] = V_36 ;
}
return 0 ;
}
static int F_75 ( struct V_13 * V_34 )
{
int V_89 = F_76 ( V_34 -> V_2 -> V_3 -> V_108 ) ;
switch ( V_89 ) {
case V_121 :
case V_122 :
if ( V_34 -> V_123 )
F_77 ( V_34 -> V_2 -> V_8 , L_12 ,
V_34 -> V_17 ) ;
return V_34 -> V_123 ;
default:
return 1 ;
}
}
static int F_78 ( struct V_69 * * V_22 ,
struct V_13 * V_14 )
{
struct V_69 * V_68 ;
int V_124 , V_125 , V_87 ;
if ( * V_22 == NULL )
return - V_115 ;
V_68 = * V_22 ;
for ( V_87 = 0 ; V_87 < V_68 -> V_72 ; V_87 ++ ) {
if ( V_68 -> V_73 [ V_87 ] == V_14 )
return 0 ;
}
V_125 = V_68 -> V_72 + 1 ;
V_124 = sizeof( struct V_69 ) +
V_125 * sizeof( struct V_13 * ) ;
* V_22 = F_37 ( V_68 , V_124 , V_12 ) ;
if ( * V_22 == NULL ) {
F_70 ( V_14 -> V_2 -> V_8 , L_13 ,
V_14 -> V_17 ) ;
return - V_44 ;
}
V_68 = * V_22 ;
F_77 ( V_14 -> V_2 -> V_8 , L_14 ,
V_14 -> V_17 , V_68 -> V_72 ) ;
V_68 -> V_73 [ V_68 -> V_72 ] = V_14 ;
V_68 -> V_72 ++ ;
return 1 ;
}
static int F_79 ( struct V_13 * V_34 ,
struct V_69 * * V_22 )
{
struct V_20 * V_74 ;
int V_126 = 0 ;
if ( V_34 -> V_29 >= 0 )
return V_34 -> V_29 ;
F_80 ( V_34 , V_127 ) ;
if ( V_34 -> V_31 && V_34 -> V_128 ) {
V_34 -> V_29 = F_75 ( V_34 ) ;
return V_34 -> V_29 ;
}
F_17 (path, &widget->sinks, list_source) {
F_80 ( V_34 , V_129 ) ;
if ( V_74 -> V_26 || V_74 -> V_25 )
continue;
if ( V_74 -> V_130 )
return 1 ;
F_81 ( V_34 , V_74 ) ;
if ( V_74 -> V_27 ) {
V_74 -> V_130 = 1 ;
if ( V_22 ) {
int V_131 ;
V_131 = F_78 ( V_22 , V_74 -> V_19 ) ;
if ( V_131 < 0 ) {
F_70 ( V_34 -> V_2 -> V_8 ,
L_15 ,
V_34 -> V_17 ) ;
V_74 -> V_130 = 0 ;
return V_126 ;
}
}
V_126 += F_79 ( V_74 -> V_19 , V_22 ) ;
V_74 -> V_130 = 0 ;
}
}
V_34 -> V_29 = V_126 ;
return V_126 ;
}
static int F_82 ( struct V_13 * V_34 ,
struct V_69 * * V_22 )
{
struct V_20 * V_74 ;
int V_126 = 0 ;
if ( V_34 -> V_23 >= 0 )
return V_34 -> V_23 ;
F_80 ( V_34 , V_127 ) ;
if ( V_34 -> V_32 && V_34 -> V_128 ) {
V_34 -> V_23 = F_75 ( V_34 ) ;
return V_34 -> V_23 ;
}
F_17 (path, &widget->sources, list_sink) {
F_80 ( V_34 , V_129 ) ;
if ( V_74 -> V_26 || V_74 -> V_25 )
continue;
if ( V_74 -> V_130 )
return 1 ;
F_83 ( V_34 , V_74 ) ;
if ( V_74 -> V_27 ) {
V_74 -> V_130 = 1 ;
if ( V_22 ) {
int V_131 ;
V_131 = F_78 ( V_22 , V_74 -> V_28 ) ;
if ( V_131 < 0 ) {
F_70 ( V_34 -> V_2 -> V_8 ,
L_15 ,
V_34 -> V_17 ) ;
V_74 -> V_130 = 0 ;
return V_126 ;
}
}
V_126 += F_82 ( V_74 -> V_28 , V_22 ) ;
V_74 -> V_130 = 0 ;
}
}
V_34 -> V_23 = V_126 ;
return V_126 ;
}
int F_84 ( struct V_132 * V_133 , int V_134 ,
struct V_69 * * V_22 )
{
struct V_30 * V_3 = V_133 -> V_81 -> V_3 ;
struct V_13 * V_14 ;
int V_45 ;
F_85 ( & V_3 -> V_5 , V_135 ) ;
F_17 (w, &card->widgets, list) {
V_14 -> V_23 = - 1 ;
V_14 -> V_29 = - 1 ;
}
if ( V_134 == V_136 )
V_45 = F_79 ( V_133 -> V_137 , V_22 ) ;
else
V_45 = F_82 ( V_133 -> V_138 , V_22 ) ;
F_86 ( V_45 , V_134 ) ;
F_22 ( & V_3 -> V_5 ) ;
return V_45 ;
}
int F_87 ( struct V_13 * V_14 ,
struct V_35 * V_36 , int V_139 )
{
int V_43 ;
F_52 ( V_14 -> V_2 ) ;
if ( F_88 ( V_139 ) ) {
if ( V_14 -> V_60 & V_140 ) {
V_43 = F_89 ( V_14 -> V_141 , false ) ;
if ( V_43 != 0 )
F_90 ( V_14 -> V_2 -> V_8 ,
L_16 ,
V_14 -> V_17 , V_43 ) ;
}
return F_91 ( V_14 -> V_141 ) ;
} else {
if ( V_14 -> V_60 & V_140 ) {
V_43 = F_89 ( V_14 -> V_141 , true ) ;
if ( V_43 != 0 )
F_90 ( V_14 -> V_2 -> V_8 ,
L_17 ,
V_14 -> V_17 , V_43 ) ;
}
return F_92 ( V_14 -> V_141 , V_14 -> V_57 ) ;
}
}
int F_93 ( struct V_13 * V_14 ,
struct V_35 * V_36 , int V_139 )
{
if ( ! V_14 -> V_142 )
return - V_83 ;
F_52 ( V_14 -> V_2 ) ;
#ifdef F_94
if ( F_88 ( V_139 ) ) {
return F_95 ( V_14 -> V_142 ) ;
} else {
F_96 ( V_14 -> V_142 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_97 ( struct V_13 * V_14 )
{
if ( V_14 -> V_80 )
return V_14 -> V_79 ;
if ( V_14 -> V_143 )
V_14 -> V_79 = 1 ;
else
V_14 -> V_79 = V_14 -> V_144 ( V_14 ) ;
V_14 -> V_80 = true ;
return V_14 -> V_79 ;
}
static int F_98 ( struct V_13 * V_14 )
{
int V_145 , V_92 ;
F_80 ( V_14 , V_146 ) ;
V_145 = F_82 ( V_14 , NULL ) ;
V_92 = F_79 ( V_14 , NULL ) ;
return V_92 != 0 && V_145 != 0 ;
}
static int F_99 ( struct V_13 * V_14 )
{
struct V_20 * V_74 ;
F_80 ( V_14 , V_146 ) ;
F_17 (path, &w->sinks, list_source) {
F_80 ( V_14 , V_129 ) ;
if ( V_74 -> V_26 )
continue;
if ( V_74 -> V_128 &&
! V_74 -> V_128 ( V_74 -> V_28 , V_74 -> V_19 ) )
continue;
if ( F_97 ( V_74 -> V_19 ) )
return 1 ;
}
return 0 ;
}
static int F_100 ( struct V_13 * V_14 )
{
return 1 ;
}
static int F_101 ( struct V_13 * V_147 ,
struct V_13 * V_148 ,
bool V_149 )
{
int * V_150 ;
if ( V_149 )
V_150 = V_151 ;
else
V_150 = V_152 ;
if ( V_150 [ V_147 -> V_46 ] != V_150 [ V_148 -> V_46 ] )
return V_150 [ V_147 -> V_46 ] - V_150 [ V_148 -> V_46 ] ;
if ( V_147 -> V_153 != V_148 -> V_153 ) {
if ( V_149 )
return V_147 -> V_153 - V_148 -> V_153 ;
else
return V_148 -> V_153 - V_147 -> V_153 ;
}
if ( V_147 -> V_54 != V_148 -> V_54 )
return V_147 -> V_54 - V_148 -> V_54 ;
if ( V_147 -> V_2 != V_148 -> V_2 )
return ( unsigned long ) V_147 -> V_2 - ( unsigned long ) V_148 -> V_2 ;
return 0 ;
}
static void F_102 ( struct V_13 * V_154 ,
struct V_77 * V_22 ,
bool V_149 )
{
struct V_13 * V_14 ;
F_17 (w, list, power_list)
if ( F_101 ( V_154 , V_14 , V_149 ) < 0 ) {
F_14 ( & V_154 -> V_155 , & V_14 -> V_155 ) ;
return;
}
F_14 ( & V_154 -> V_155 , V_22 ) ;
}
static void F_103 ( struct V_30 * V_3 ,
struct V_13 * V_14 , int V_139 )
{
const char * V_156 ;
int V_76 , V_43 ;
switch ( V_139 ) {
case V_157 :
V_156 = L_18 ;
V_76 = 1 ;
break;
case V_158 :
V_156 = L_19 ;
V_76 = 1 ;
break;
case V_159 :
V_156 = L_20 ;
V_76 = 0 ;
break;
case V_160 :
V_156 = L_21 ;
V_76 = 0 ;
break;
case V_161 :
V_156 = L_22 ;
V_76 = 1 ;
break;
case V_162 :
V_156 = L_23 ;
V_76 = 0 ;
break;
default:
F_104 ( 1 , L_24 , V_139 ) ;
return;
}
if ( V_14 -> V_79 != V_76 )
return;
if ( V_14 -> V_139 && ( V_14 -> V_163 & V_139 ) ) {
F_6 ( V_14 -> V_2 -> V_8 , V_3 -> V_6 , L_25 ,
V_14 -> V_17 , V_156 ) ;
F_52 ( V_14 -> V_2 ) ;
F_105 ( V_14 , V_139 ) ;
V_43 = V_14 -> V_139 ( V_14 , NULL , V_139 ) ;
F_106 ( V_14 , V_139 ) ;
if ( V_43 < 0 )
F_70 ( V_14 -> V_2 -> V_8 , L_26 ,
V_156 , V_14 -> V_17 , V_43 ) ;
}
}
static void F_107 ( struct V_30 * V_3 ,
struct V_77 * V_164 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
int V_54 ;
unsigned int V_62 = 0 ;
unsigned int V_55 = 0 ;
V_14 = F_108 ( V_164 , struct V_13 , V_155 ) ;
V_54 = V_14 -> V_54 ;
V_2 = V_14 -> V_2 ;
F_17 (w, pending, power_list) {
F_109 ( V_54 != V_14 -> V_54 || V_2 != V_14 -> V_2 ) ;
V_14 -> V_76 = V_14 -> V_79 ;
V_55 |= V_14 -> V_55 << V_14 -> V_57 ;
if ( V_14 -> V_76 )
V_62 |= V_14 -> V_60 << V_14 -> V_57 ;
else
V_62 |= V_14 -> V_59 << V_14 -> V_57 ;
F_6 ( V_2 -> V_8 , V_3 -> V_6 ,
L_27 ,
V_14 -> V_17 , V_54 , V_62 , V_55 ) ;
F_103 ( V_3 , V_14 , V_157 ) ;
F_103 ( V_3 , V_14 , V_159 ) ;
}
if ( V_54 >= 0 ) {
F_6 ( V_2 -> V_8 , V_3 -> V_6 ,
L_28 ,
V_62 , V_55 , V_54 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_48 ( V_2 , V_54 , V_55 , V_62 ) ;
}
F_17 (w, pending, power_list) {
F_103 ( V_3 , V_14 , V_158 ) ;
F_103 ( V_3 , V_14 , V_160 ) ;
}
}
static void F_110 ( struct V_30 * V_3 ,
struct V_77 * V_22 , int V_139 , bool V_149 )
{
struct V_13 * V_14 , * V_71 ;
struct V_1 * V_165 ;
F_16 ( V_164 ) ;
int V_166 = - 1 ;
int V_167 = - 1 ;
int V_168 = V_99 ;
struct V_1 * V_169 = NULL ;
int V_43 , V_87 ;
int * V_150 ;
if ( V_149 )
V_150 = V_151 ;
else
V_150 = V_152 ;
F_111 (w, n, list, power_list) {
V_43 = 0 ;
if ( V_150 [ V_14 -> V_46 ] != V_166 || V_14 -> V_54 != V_168 ||
V_14 -> V_2 != V_169 || V_14 -> V_153 != V_167 ) {
if ( ! F_11 ( & V_164 ) )
F_107 ( V_3 , & V_164 ) ;
if ( V_169 && V_169 -> V_170 ) {
for ( V_87 = 0 ; V_87 < F_112 ( V_151 ) ; V_87 ++ )
if ( V_150 [ V_87 ] == V_166 )
V_169 -> V_170 ( V_169 ,
V_87 ,
V_167 ) ;
}
if ( V_169 && V_14 -> V_2 != V_169 )
F_52 ( V_169 ) ;
F_27 ( & V_164 ) ;
V_166 = - 1 ;
V_167 = V_171 ;
V_168 = V_99 ;
V_169 = NULL ;
}
switch ( V_14 -> V_46 ) {
case V_172 :
if ( ! V_14 -> V_139 )
F_113 ( V_14 , V_71 , V_22 ,
V_155 ) ;
if ( V_139 == V_173 )
V_43 = V_14 -> V_139 ( V_14 ,
NULL , V_157 ) ;
else if ( V_139 == V_174 )
V_43 = V_14 -> V_139 ( V_14 ,
NULL , V_159 ) ;
break;
case V_175 :
if ( ! V_14 -> V_139 )
F_113 ( V_14 , V_71 , V_22 ,
V_155 ) ;
if ( V_139 == V_173 )
V_43 = V_14 -> V_139 ( V_14 ,
NULL , V_158 ) ;
else if ( V_139 == V_174 )
V_43 = V_14 -> V_139 ( V_14 ,
NULL , V_160 ) ;
break;
default:
V_166 = V_150 [ V_14 -> V_46 ] ;
V_167 = V_14 -> V_153 ;
V_168 = V_14 -> V_54 ;
V_169 = V_14 -> V_2 ;
F_114 ( & V_14 -> V_155 , & V_164 ) ;
break;
}
if ( V_43 < 0 )
F_70 ( V_14 -> V_2 -> V_8 ,
L_29 , V_43 ) ;
}
if ( ! F_11 ( & V_164 ) )
F_107 ( V_3 , & V_164 ) ;
if ( V_169 && V_169 -> V_170 ) {
for ( V_87 = 0 ; V_87 < F_112 ( V_151 ) ; V_87 ++ )
if ( V_150 [ V_87 ] == V_166 )
V_169 -> V_170 ( V_169 ,
V_87 , V_167 ) ;
}
F_17 (d, &card->dapm_list, list) {
F_52 ( V_165 ) ;
}
}
static void F_115 ( struct V_30 * V_3 )
{
struct V_176 * V_177 = V_3 -> V_177 ;
struct V_69 * V_68 ;
struct V_13 * V_14 = NULL ;
unsigned int V_178 ;
int V_43 ;
if ( ! V_177 || ! F_39 ( V_177 -> V_36 ) )
return;
V_68 = F_35 ( V_177 -> V_36 ) ;
for ( V_178 = 0 ; V_178 < V_68 -> V_72 ; V_178 ++ ) {
V_14 = V_68 -> V_73 [ V_178 ] ;
if ( V_14 -> V_139 && ( V_14 -> V_163 & V_179 ) ) {
V_43 = V_14 -> V_139 ( V_14 , V_177 -> V_36 , V_179 ) ;
if ( V_43 != 0 )
F_70 ( V_14 -> V_2 -> V_8 , L_30 ,
V_14 -> V_17 , V_43 ) ;
}
}
if ( ! V_14 )
return;
V_43 = F_48 ( V_14 -> V_2 , V_177 -> V_54 , V_177 -> V_55 ,
V_177 -> V_97 ) ;
if ( V_43 < 0 )
F_70 ( V_14 -> V_2 -> V_8 , L_31 ,
V_14 -> V_17 , V_43 ) ;
for ( V_178 = 0 ; V_178 < V_68 -> V_72 ; V_178 ++ ) {
V_14 = V_68 -> V_73 [ V_178 ] ;
if ( V_14 -> V_139 && ( V_14 -> V_163 & V_180 ) ) {
V_43 = V_14 -> V_139 ( V_14 , V_177 -> V_36 , V_180 ) ;
if ( V_43 != 0 )
F_70 ( V_14 -> V_2 -> V_8 , L_32 ,
V_14 -> V_17 , V_43 ) ;
}
}
}
static void F_116 ( void * V_38 , T_4 V_181 )
{
struct V_1 * V_165 = V_38 ;
int V_43 ;
if ( V_165 -> V_91 == V_182 &&
V_165 -> V_183 != V_182 ) {
if ( V_165 -> V_8 )
F_117 ( V_165 -> V_8 ) ;
V_43 = F_58 ( V_165 , V_184 ) ;
if ( V_43 != 0 )
F_70 ( V_165 -> V_8 ,
L_33 , V_43 ) ;
}
if ( ( V_165 -> V_183 == V_185 &&
V_165 -> V_91 != V_185 ) ||
( V_165 -> V_183 != V_185 &&
V_165 -> V_91 == V_185 ) ) {
V_43 = F_58 ( V_165 , V_186 ) ;
if ( V_43 != 0 )
F_70 ( V_165 -> V_8 ,
L_34 , V_43 ) ;
}
}
static void F_118 ( void * V_38 , T_4 V_181 )
{
struct V_1 * V_165 = V_38 ;
int V_43 ;
if ( V_165 -> V_91 == V_186 &&
( V_165 -> V_183 == V_184 ||
V_165 -> V_183 == V_182 ) ) {
V_43 = F_58 ( V_165 , V_184 ) ;
if ( V_43 != 0 )
F_70 ( V_165 -> V_8 , L_35 ,
V_43 ) ;
}
if ( V_165 -> V_91 == V_184 &&
V_165 -> V_183 == V_182 ) {
V_43 = F_58 ( V_165 , V_182 ) ;
if ( V_43 != 0 )
F_70 ( V_165 -> V_8 , L_36 ,
V_43 ) ;
if ( V_165 -> V_8 )
F_119 ( V_165 -> V_8 ) ;
}
if ( V_165 -> V_91 == V_186 &&
V_165 -> V_183 == V_185 ) {
V_43 = F_58 ( V_165 , V_185 ) ;
if ( V_43 != 0 )
F_70 ( V_165 -> V_8 , L_37 ,
V_43 ) ;
}
}
static void F_120 ( struct V_13 * V_187 ,
bool V_76 , bool V_27 )
{
if ( ! V_27 )
return;
if ( V_76 != V_187 -> V_76 )
F_12 ( V_187 , L_38 ) ;
}
static void F_121 ( struct V_13 * V_14 , bool V_76 ,
struct V_77 * V_188 ,
struct V_77 * V_189 )
{
struct V_20 * V_74 ;
if ( V_14 -> V_76 == V_76 )
return;
F_122 ( V_14 , V_76 ) ;
F_17 (path, &w->sources, list_sink)
F_120 ( V_74 -> V_28 , V_76 , V_74 -> V_27 ) ;
if ( ! V_14 -> V_25 ) {
F_17 (path, &w->sinks, list_source)
F_120 ( V_74 -> V_19 , V_76 ,
V_74 -> V_27 ) ;
}
if ( V_76 )
F_102 ( V_14 , V_188 , true ) ;
else
F_102 ( V_14 , V_189 , false ) ;
}
static void F_123 ( struct V_13 * V_14 ,
struct V_77 * V_188 ,
struct V_77 * V_189 )
{
int V_76 ;
switch ( V_14 -> V_46 ) {
case V_172 :
F_102 ( V_14 , V_189 , false ) ;
break;
case V_175 :
F_102 ( V_14 , V_188 , true ) ;
break;
default:
V_76 = F_97 ( V_14 ) ;
F_121 ( V_14 , V_76 , V_188 , V_189 ) ;
break;
}
}
static bool F_124 ( struct V_1 * V_2 )
{
if ( V_2 -> V_190 )
return true ;
switch ( F_76 ( V_2 -> V_3 -> V_108 ) ) {
case V_121 :
case V_122 :
return V_2 -> V_191 ;
default:
break;
}
return false ;
}
static int F_125 ( struct V_30 * V_3 , int V_139 )
{
struct V_13 * V_14 ;
struct V_1 * V_165 ;
F_16 ( V_188 ) ;
F_16 ( V_189 ) ;
F_126 ( V_192 ) ;
enum V_88 V_193 ;
F_2 ( & V_3 -> V_5 ) ;
F_127 ( V_3 ) ;
F_17 (d, &card->dapm_list, list) {
if ( F_124 ( V_165 ) )
V_165 -> V_183 = V_182 ;
else
V_165 -> V_183 = V_184 ;
}
F_44 ( V_3 ) ;
F_17 (w, &card->dapm_dirty, dirty) {
F_123 ( V_14 , & V_188 , & V_189 ) ;
}
F_17 (w, &card->widgets, list) {
switch ( V_14 -> V_46 ) {
case V_172 :
case V_175 :
break;
default:
F_128 ( & V_14 -> V_15 ) ;
break;
}
if ( V_14 -> V_79 ) {
V_165 = V_14 -> V_2 ;
switch ( V_14 -> V_46 ) {
case V_194 :
case V_195 :
break;
case V_196 :
case V_197 :
case V_198 :
case V_199 :
if ( V_165 -> V_183 < V_184 )
V_165 -> V_183 = V_184 ;
break;
default:
V_165 -> V_183 = V_185 ;
break;
}
}
}
V_193 = V_182 ;
F_17 (d, &card->dapm_list, list)
if ( V_165 -> V_183 > V_193 )
V_193 = V_165 -> V_183 ;
F_17 (d, &card->dapm_list, list)
if ( ! F_124 ( V_165 ) )
V_165 -> V_183 = V_193 ;
F_129 ( V_3 ) ;
F_116 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_165 != & V_3 -> V_2 )
F_130 ( F_116 , V_165 ,
& V_192 ) ;
}
F_131 ( & V_192 ) ;
F_17 (w, &down_list, power_list) {
F_103 ( V_3 , V_14 , V_162 ) ;
}
F_17 (w, &up_list, power_list) {
F_103 ( V_3 , V_14 , V_161 ) ;
}
F_110 ( V_3 , & V_189 , V_139 , false ) ;
F_115 ( V_3 ) ;
F_110 ( V_3 , & V_188 , V_139 , true ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_165 != & V_3 -> V_2 )
F_130 ( F_118 , V_165 ,
& V_192 ) ;
}
F_131 ( & V_192 ) ;
F_118 ( & V_3 -> V_2 , 0 ) ;
F_17 (d, &card->dapm_list, list) {
if ( V_165 -> V_200 )
V_165 -> V_200 ( V_165 , V_139 ) ;
}
F_6 ( V_3 -> V_8 , V_3 -> V_6 ,
L_39 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_132 ( V_3 ) ;
return 0 ;
}
static T_5 F_133 ( struct V_201 * V_201 ,
char T_6 * V_202 ,
T_3 V_203 , T_7 * V_204 )
{
struct V_13 * V_14 = V_201 -> V_66 ;
struct V_30 * V_3 = V_14 -> V_2 -> V_3 ;
char * V_10 ;
int V_145 , V_92 ;
T_5 V_43 ;
struct V_20 * V_21 = NULL ;
V_10 = F_7 ( V_11 , V_12 ) ;
if ( ! V_10 )
return - V_44 ;
F_21 ( & V_3 -> V_5 ) ;
if ( V_14 -> V_25 ) {
V_145 = 0 ;
V_92 = 0 ;
} else {
V_145 = F_82 ( V_14 , NULL ) ;
V_92 = F_79 ( V_14 , NULL ) ;
}
V_43 = snprintf ( V_10 , V_11 , L_40 ,
V_14 -> V_17 , V_14 -> V_76 ? L_41 : L_42 ,
V_14 -> V_143 ? L_43 : L_44 , V_145 , V_92 ) ;
if ( V_14 -> V_54 >= 0 )
V_43 += snprintf ( V_10 + V_43 , V_11 - V_43 ,
L_45 ,
V_14 -> V_54 , V_14 -> V_54 , V_14 -> V_55 << V_14 -> V_57 ) ;
V_43 += snprintf ( V_10 + V_43 , V_11 - V_43 , L_46 ) ;
if ( V_14 -> V_205 )
V_43 += snprintf ( V_10 + V_43 , V_11 - V_43 , L_47 ,
V_14 -> V_205 ,
V_14 -> V_206 ? L_48 : L_49 ) ;
F_17 (p, &w->sources, list_sink) {
if ( V_21 -> V_128 && ! V_21 -> V_128 ( V_14 , V_21 -> V_28 ) )
continue;
if ( V_21 -> V_27 )
V_43 += snprintf ( V_10 + V_43 , V_11 - V_43 ,
L_50 ,
V_21 -> V_17 ? V_21 -> V_17 : L_51 ,
V_21 -> V_28 -> V_17 ) ;
}
F_17 (p, &w->sinks, list_source) {
if ( V_21 -> V_128 && ! V_21 -> V_128 ( V_14 , V_21 -> V_19 ) )
continue;
if ( V_21 -> V_27 )
V_43 += snprintf ( V_10 + V_43 , V_11 - V_43 ,
L_52 ,
V_21 -> V_17 ? V_21 -> V_17 : L_51 ,
V_21 -> V_19 -> V_17 ) ;
}
F_22 ( & V_3 -> V_5 ) ;
V_43 = F_134 ( V_202 , V_203 , V_204 , V_10 , V_43 ) ;
F_9 ( V_10 ) ;
return V_43 ;
}
static T_5 F_135 ( struct V_201 * V_201 , char T_6 * V_202 ,
T_3 V_203 , T_7 * V_204 )
{
struct V_1 * V_2 = V_201 -> V_66 ;
char * V_89 ;
switch ( V_2 -> V_91 ) {
case V_185 :
V_89 = L_53 ;
break;
case V_186 :
V_89 = L_54 ;
break;
case V_184 :
V_89 = L_55 ;
break;
case V_182 :
V_89 = L_56 ;
break;
default:
F_104 ( 1 , L_57 , V_2 -> V_91 ) ;
V_89 = L_58 ;
break;
}
return F_134 ( V_202 , V_203 , V_204 , V_89 ,
strlen ( V_89 ) ) ;
}
void F_136 ( struct V_1 * V_2 ,
struct V_207 * V_208 )
{
struct V_207 * V_165 ;
if ( ! V_208 )
return;
V_2 -> V_209 = F_137 ( L_59 , V_208 ) ;
if ( ! V_2 -> V_209 ) {
F_90 ( V_2 -> V_8 ,
L_60 ) ;
return;
}
V_165 = F_138 ( L_61 , 0444 ,
V_2 -> V_209 , V_2 ,
& V_210 ) ;
if ( ! V_165 )
F_90 ( V_2 -> V_8 ,
L_62 ) ;
}
static void F_139 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_207 * V_165 ;
if ( ! V_2 -> V_209 || ! V_14 -> V_17 )
return;
V_165 = F_138 ( V_14 -> V_17 , 0444 ,
V_2 -> V_209 , V_14 ,
& V_211 ) ;
if ( ! V_165 )
F_90 ( V_14 -> V_2 -> V_8 ,
L_63 ,
V_14 -> V_17 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
F_141 ( V_2 -> V_209 ) ;
}
void F_136 ( struct V_1 * V_2 ,
struct V_207 * V_208 )
{
}
static inline void F_139 ( struct V_13 * V_14 )
{
}
static inline void F_140 ( struct V_1 * V_2 )
{
}
static void F_142 ( struct V_20 * V_74 ,
bool V_27 , const char * V_16 )
{
if ( V_74 -> V_27 == V_27 )
return;
V_74 -> V_27 = V_27 ;
F_12 ( V_74 -> V_28 , V_16 ) ;
F_12 ( V_74 -> V_19 , V_16 ) ;
F_19 ( V_74 ) ;
}
static int F_143 ( struct V_30 * V_3 ,
struct V_35 * V_36 , int V_212 , struct V_41 * V_42 )
{
struct V_20 * V_74 ;
int V_213 = 0 ;
bool V_27 ;
F_2 ( & V_3 -> V_5 ) ;
F_144 (path, kcontrol) {
V_213 = 1 ;
if ( ! ( strcmp ( V_74 -> V_17 , V_42 -> V_101 [ V_212 ] ) ) )
V_27 = true ;
else
V_27 = false ;
F_142 ( V_74 , V_27 , L_64 ) ;
}
if ( V_213 )
F_125 ( V_3 , V_214 ) ;
return V_213 ;
}
int F_145 ( struct V_1 * V_2 ,
struct V_35 * V_36 , int V_212 , struct V_41 * V_42 ,
struct V_176 * V_177 )
{
struct V_30 * V_3 = V_2 -> V_3 ;
int V_43 ;
F_85 ( & V_3 -> V_5 , V_135 ) ;
V_3 -> V_177 = V_177 ;
V_43 = F_143 ( V_3 , V_36 , V_212 , V_42 ) ;
V_3 -> V_177 = NULL ;
F_22 ( & V_3 -> V_5 ) ;
if ( V_43 > 0 )
F_146 ( V_3 ) ;
return V_43 ;
}
static int F_147 ( struct V_30 * V_3 ,
struct V_35 * V_36 , int V_27 )
{
struct V_20 * V_74 ;
int V_213 = 0 ;
F_2 ( & V_3 -> V_5 ) ;
F_144 (path, kcontrol) {
V_213 = 1 ;
F_142 ( V_74 , V_27 , L_65 ) ;
}
if ( V_213 )
F_125 ( V_3 , V_214 ) ;
return V_213 ;
}
int F_148 ( struct V_1 * V_2 ,
struct V_35 * V_36 , int V_27 ,
struct V_176 * V_177 )
{
struct V_30 * V_3 = V_2 -> V_3 ;
int V_43 ;
F_85 ( & V_3 -> V_5 , V_135 ) ;
V_3 -> V_177 = V_177 ;
V_43 = F_147 ( V_3 , V_36 , V_27 ) ;
V_3 -> V_177 = NULL ;
F_22 ( & V_3 -> V_5 ) ;
if ( V_43 > 0 )
F_146 ( V_3 ) ;
return V_43 ;
}
static T_5 F_149 ( struct V_215 * V_216 , char * V_10 )
{
struct V_13 * V_14 ;
int V_203 = 0 ;
char * V_217 = L_66 ;
F_17 (w, &codec->component.card->widgets, list) {
if ( V_14 -> V_2 != & V_216 -> V_2 )
continue;
switch ( V_14 -> V_46 ) {
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_199 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_48 :
case V_49 :
case V_196 :
case V_197 :
case V_198 :
if ( V_14 -> V_17 )
V_203 += sprintf ( V_10 + V_203 , L_67 ,
V_14 -> V_17 , V_14 -> V_76 ? L_41 : L_42 ) ;
break;
default:
break;
}
}
switch ( V_216 -> V_2 . V_91 ) {
case V_185 :
V_217 = L_41 ;
break;
case V_186 :
V_217 = L_68 ;
break;
case V_184 :
V_217 = L_69 ;
break;
case V_182 :
V_217 = L_42 ;
break;
}
V_203 += sprintf ( V_10 + V_203 , L_70 , V_217 ) ;
return V_203 ;
}
static T_5 F_150 ( struct V_7 * V_8 ,
struct V_226 * V_227 , char * V_10 )
{
struct V_228 * V_229 = F_151 ( V_8 ) ;
int V_87 , V_203 = 0 ;
F_21 ( & V_229 -> V_3 -> V_5 ) ;
for ( V_87 = 0 ; V_87 < V_229 -> V_230 ; V_87 ++ ) {
struct V_215 * V_216 = V_229 -> V_231 [ V_87 ] -> V_216 ;
V_203 += F_149 ( V_216 , V_10 + V_203 ) ;
}
F_22 ( & V_229 -> V_3 -> V_5 ) ;
return V_203 ;
}
static void F_152 ( struct V_20 * V_74 )
{
F_153 ( & V_74 -> V_232 ) ;
F_153 ( & V_74 -> V_233 ) ;
F_153 ( & V_74 -> V_75 ) ;
F_153 ( & V_74 -> V_22 ) ;
F_9 ( V_74 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_234 ;
struct V_20 * V_21 , * V_235 ;
F_111 (w, next_w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
F_153 ( & V_14 -> V_22 ) ;
F_111 (p, next_p, &w->sources, list_sink)
F_152 ( V_21 ) ;
F_111 (p, next_p, &w->sinks, list_source)
F_152 ( V_21 ) ;
F_9 ( V_14 -> V_106 ) ;
F_9 ( V_14 -> V_17 ) ;
F_9 ( V_14 ) ;
}
}
static struct V_13 * F_155 (
struct V_1 * V_2 , const char * V_236 ,
bool V_237 )
{
struct V_13 * V_14 ;
struct V_13 * V_238 = NULL ;
F_17 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_14 -> V_17 , V_236 ) ) {
if ( V_14 -> V_2 == V_2 )
return V_14 ;
else
V_238 = V_14 ;
}
}
if ( V_237 )
return V_238 ;
return NULL ;
}
static int F_156 ( struct V_1 * V_2 ,
const char * V_236 , int V_239 )
{
struct V_13 * V_14 = F_155 ( V_2 , V_236 , true ) ;
F_1 ( V_2 ) ;
if ( ! V_14 ) {
F_70 ( V_2 -> V_8 , L_71 , V_236 ) ;
return - V_115 ;
}
if ( V_14 -> V_128 != V_239 ) {
F_12 ( V_14 , L_72 ) ;
F_15 ( V_14 ) ;
F_18 ( V_14 ) ;
}
V_14 -> V_128 = V_239 ;
if ( V_239 == 0 )
V_14 -> V_143 = 0 ;
return 0 ;
}
int F_157 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_3 -> V_4 )
return 0 ;
return F_125 ( V_2 -> V_3 , V_214 ) ;
}
int F_158 ( struct V_1 * V_2 )
{
int V_43 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_135 ) ;
V_43 = F_157 ( V_2 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_43 ;
}
static void F_159 ( struct V_13 * V_14 )
{
struct V_20 * V_21 ;
switch ( V_14 -> V_46 ) {
case V_240 :
if ( V_14 -> V_2 -> V_3 -> V_241 )
break;
V_14 -> V_32 = 1 ;
F_17 (p, &w->sources, list_sink) {
if ( V_21 -> V_28 -> V_46 == V_199 ||
V_21 -> V_28 -> V_46 == V_219 ||
V_21 -> V_28 -> V_46 == V_221 ||
V_21 -> V_28 -> V_46 == V_242 ) {
V_14 -> V_32 = 0 ;
break;
}
}
break;
case V_242 :
if ( V_14 -> V_2 -> V_3 -> V_241 )
break;
V_14 -> V_31 = 1 ;
F_17 (p, &w->sinks, list_source) {
if ( V_21 -> V_19 -> V_46 == V_220 ||
V_21 -> V_19 -> V_46 == V_218 ||
V_21 -> V_19 -> V_46 == V_221 ||
V_21 -> V_19 -> V_46 == V_240 ) {
V_14 -> V_31 = 0 ;
break;
}
}
break;
case V_221 :
V_14 -> V_31 = ! F_11 ( & V_14 -> V_118 ) ;
V_14 -> V_32 = ! F_11 ( & V_14 -> V_119 ) ;
break;
default:
break;
}
}
static int F_160 ( struct V_1 * V_2 ,
struct V_13 * V_28 , struct V_13 * V_19 ,
const char * V_243 )
{
bool V_244 = false ;
bool V_245 = false ;
if ( ! V_243 )
return 0 ;
switch ( V_28 -> V_46 ) {
case V_63 :
V_244 = true ;
break;
default:
break;
}
switch ( V_19 -> V_46 ) {
case V_64 :
case V_47 :
case V_48 :
case V_49 :
V_245 = true ;
break;
default:
break;
}
if ( V_244 && V_245 ) {
F_70 ( V_2 -> V_8 ,
L_73 ,
V_28 -> V_17 , V_243 , V_19 -> V_17 ) ;
return - V_115 ;
} else if ( ! V_244 && ! V_245 ) {
F_70 ( V_2 -> V_8 ,
L_74 ,
V_28 -> V_17 , V_243 , V_19 -> V_17 ) ;
return - V_115 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_13 * V_246 , struct V_13 * V_247 ,
const char * V_243 ,
int (* V_128)( struct V_13 * V_28 ,
struct V_13 * V_19 ) )
{
struct V_20 * V_74 ;
int V_43 ;
if ( V_247 -> V_25 && ! V_246 -> V_25 ) {
F_70 ( V_2 -> V_8 ,
L_75 ,
V_246 -> V_17 , V_247 -> V_17 ) ;
return - V_115 ;
}
if ( V_128 && ! V_246 -> V_25 ) {
F_70 ( V_2 -> V_8 ,
L_76 ,
V_246 -> V_17 , V_247 -> V_17 ) ;
return - V_115 ;
}
if ( V_246 -> V_25 && V_243 ) {
F_70 ( V_2 -> V_8 ,
L_77 ,
V_246 -> V_17 , V_243 , V_247 -> V_17 ) ;
return - V_115 ;
}
V_43 = F_160 ( V_2 , V_246 , V_247 , V_243 ) ;
if ( V_43 )
return V_43 ;
V_74 = F_26 ( sizeof( struct V_20 ) , V_12 ) ;
if ( ! V_74 )
return - V_44 ;
V_74 -> V_28 = V_246 ;
V_74 -> V_19 = V_247 ;
V_74 -> V_128 = V_128 ;
F_27 ( & V_74 -> V_22 ) ;
F_27 ( & V_74 -> V_75 ) ;
F_27 ( & V_74 -> V_233 ) ;
F_27 ( & V_74 -> V_232 ) ;
if ( V_246 -> V_25 || V_247 -> V_25 )
V_74 -> V_25 = 1 ;
if ( V_243 == NULL ) {
V_74 -> V_27 = 1 ;
} else {
switch ( V_246 -> V_46 ) {
case V_63 :
V_43 = F_61 ( V_2 , V_74 , V_243 , V_246 ) ;
if ( V_43 )
goto V_131;
break;
default:
break;
}
switch ( V_247 -> V_46 ) {
case V_64 :
V_43 = F_61 ( V_2 , V_74 , V_243 , V_247 ) ;
if ( V_43 != 0 )
goto V_131;
break;
case V_47 :
case V_48 :
case V_49 :
V_43 = F_64 ( V_2 , V_74 , V_243 ) ;
if ( V_43 != 0 )
goto V_131;
break;
default:
break;
}
}
F_161 ( & V_74 -> V_22 , & V_2 -> V_3 -> V_45 ) ;
F_161 ( & V_74 -> V_232 , & V_247 -> V_118 ) ;
F_161 ( & V_74 -> V_233 , & V_246 -> V_119 ) ;
F_159 ( V_246 ) ;
F_159 ( V_247 ) ;
F_12 ( V_246 , L_78 ) ;
F_12 ( V_247 , L_78 ) ;
if ( V_2 -> V_3 -> V_4 && V_74 -> V_27 )
F_19 ( V_74 ) ;
return 0 ;
V_131:
F_9 ( V_74 ) ;
return V_43 ;
}
static int F_162 ( struct V_1 * V_2 ,
const struct V_248 * V_249 )
{
struct V_13 * V_246 = NULL , * V_247 = NULL , * V_14 ;
struct V_13 * V_250 = NULL , * V_251 = NULL ;
const char * V_19 ;
const char * V_28 ;
char V_252 [ 80 ] ;
char V_253 [ 80 ] ;
const char * V_109 ;
int V_43 ;
V_109 = F_45 ( V_2 ) ;
if ( V_109 ) {
snprintf ( V_252 , sizeof( V_252 ) , L_4 ,
V_109 , V_249 -> V_19 ) ;
V_19 = V_252 ;
snprintf ( V_253 , sizeof( V_253 ) , L_4 ,
V_109 , V_249 -> V_28 ) ;
V_28 = V_253 ;
} else {
V_19 = V_249 -> V_19 ;
V_28 = V_249 -> V_28 ;
}
V_246 = F_54 ( & V_2 -> V_254 , V_28 ) ;
V_247 = F_54 ( & V_2 -> V_255 , V_19 ) ;
if ( V_247 && V_246 )
goto V_256;
F_17 (w, &dapm->card->widgets, list) {
if ( ! V_247 && ! ( strcmp ( V_14 -> V_17 , V_19 ) ) ) {
V_251 = V_14 ;
if ( V_14 -> V_2 == V_2 ) {
V_247 = V_14 ;
if ( V_246 )
break;
}
continue;
}
if ( ! V_246 && ! ( strcmp ( V_14 -> V_17 , V_28 ) ) ) {
V_250 = V_14 ;
if ( V_14 -> V_2 == V_2 ) {
V_246 = V_14 ;
if ( V_247 )
break;
}
}
}
if ( ! V_247 )
V_247 = V_251 ;
if ( ! V_246 )
V_246 = V_250 ;
if ( V_246 == NULL ) {
F_70 ( V_2 -> V_8 , L_79 ,
V_249 -> V_28 ) ;
return - V_102 ;
}
if ( V_247 == NULL ) {
F_70 ( V_2 -> V_8 , L_80 ,
V_249 -> V_19 ) ;
return - V_102 ;
}
V_256:
F_56 ( & V_2 -> V_255 , V_247 ) ;
F_56 ( & V_2 -> V_254 , V_246 ) ;
V_43 = F_32 ( V_2 , V_246 , V_247 , V_249 -> V_243 ,
V_249 -> V_128 ) ;
if ( V_43 )
goto V_131;
return 0 ;
V_131:
F_90 ( V_2 -> V_8 , L_81 ,
V_28 , V_249 -> V_243 , V_19 ) ;
return V_43 ;
}
static int F_163 ( struct V_1 * V_2 ,
const struct V_248 * V_249 )
{
struct V_13 * V_246 , * V_247 ;
struct V_20 * V_74 , * V_21 ;
const char * V_19 ;
const char * V_28 ;
char V_252 [ 80 ] ;
char V_253 [ 80 ] ;
const char * V_109 ;
if ( V_249 -> V_243 ) {
F_70 ( V_2 -> V_8 ,
L_82 ) ;
return - V_115 ;
}
V_109 = F_45 ( V_2 ) ;
if ( V_109 ) {
snprintf ( V_252 , sizeof( V_252 ) , L_4 ,
V_109 , V_249 -> V_19 ) ;
V_19 = V_252 ;
snprintf ( V_253 , sizeof( V_253 ) , L_4 ,
V_109 , V_249 -> V_28 ) ;
V_28 = V_253 ;
} else {
V_19 = V_249 -> V_19 ;
V_28 = V_249 -> V_28 ;
}
V_74 = NULL ;
F_17 (p, &dapm->card->paths, list) {
if ( strcmp ( V_21 -> V_28 -> V_17 , V_28 ) != 0 )
continue;
if ( strcmp ( V_21 -> V_19 -> V_17 , V_19 ) != 0 )
continue;
V_74 = V_21 ;
break;
}
if ( V_74 ) {
V_246 = V_74 -> V_28 ;
V_247 = V_74 -> V_19 ;
F_12 ( V_246 , L_83 ) ;
F_12 ( V_247 , L_83 ) ;
if ( V_74 -> V_27 )
F_19 ( V_74 ) ;
F_152 ( V_74 ) ;
F_159 ( V_246 ) ;
F_159 ( V_247 ) ;
} else {
F_90 ( V_2 -> V_8 , L_84 ,
V_28 , V_19 ) ;
}
return 0 ;
}
int F_164 ( struct V_1 * V_2 ,
const struct V_248 * V_249 , int V_257 )
{
int V_87 , V_258 , V_43 = 0 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_259 ) ;
for ( V_87 = 0 ; V_87 < V_257 ; V_87 ++ ) {
V_258 = F_162 ( V_2 , V_249 ) ;
if ( V_258 < 0 ) {
F_70 ( V_2 -> V_8 , L_85 ,
V_249 -> V_28 ,
V_249 -> V_243 ? V_249 -> V_243 : L_86 ,
V_249 -> V_19 ) ;
V_43 = V_258 ;
}
V_249 ++ ;
}
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_43 ;
}
int F_165 ( struct V_1 * V_2 ,
const struct V_248 * V_249 , int V_257 )
{
int V_87 , V_43 = 0 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_259 ) ;
for ( V_87 = 0 ; V_87 < V_257 ; V_87 ++ ) {
F_163 ( V_2 , V_249 ) ;
V_249 ++ ;
}
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_43 ;
}
static int F_166 ( struct V_1 * V_2 ,
const struct V_248 * V_249 )
{
struct V_13 * V_28 = F_155 ( V_2 ,
V_249 -> V_28 ,
true ) ;
struct V_13 * V_19 = F_155 ( V_2 ,
V_249 -> V_19 ,
true ) ;
struct V_20 * V_74 ;
int V_203 = 0 ;
if ( ! V_28 ) {
F_70 ( V_2 -> V_8 , L_87 ,
V_249 -> V_28 ) ;
return - V_102 ;
}
if ( ! V_19 ) {
F_70 ( V_2 -> V_8 , L_88 ,
V_249 -> V_19 ) ;
return - V_102 ;
}
if ( V_249 -> V_243 || V_249 -> V_128 )
F_90 ( V_2 -> V_8 , L_89 ,
V_249 -> V_28 , V_249 -> V_19 ) ;
F_17 (path, &source->sinks, list_source) {
if ( V_74 -> V_19 == V_19 ) {
V_74 -> V_26 = 1 ;
V_203 ++ ;
}
}
if ( V_203 == 0 )
F_70 ( V_2 -> V_8 , L_90 ,
V_249 -> V_28 , V_249 -> V_19 ) ;
if ( V_203 > 1 )
F_90 ( V_2 -> V_8 , L_91 ,
V_203 , V_249 -> V_28 , V_249 -> V_19 ) ;
return 0 ;
}
int F_167 ( struct V_1 * V_2 ,
const struct V_248 * V_249 , int V_257 )
{
int V_87 , V_131 ;
int V_43 = 0 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_259 ) ;
for ( V_87 = 0 ; V_87 < V_257 ; V_87 ++ ) {
V_131 = F_166 ( V_2 , V_249 ) ;
if ( V_131 )
V_43 = V_131 ;
V_249 ++ ;
}
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_43 ;
}
int F_168 ( struct V_30 * V_3 )
{
struct V_13 * V_14 ;
unsigned int V_97 ;
F_85 ( & V_3 -> V_5 , V_259 ) ;
F_17 (w, &card->widgets, list)
{
if ( V_14 -> V_260 )
continue;
if ( V_14 -> V_103 ) {
V_14 -> V_106 = F_26 ( V_14 -> V_103 *
sizeof( struct V_35 * ) ,
V_12 ) ;
if ( ! V_14 -> V_106 ) {
F_22 ( & V_3 -> V_5 ) ;
return - V_44 ;
}
}
switch( V_14 -> V_46 ) {
case V_47 :
case V_48 :
case V_49 :
F_71 ( V_14 ) ;
break;
case V_64 :
case V_63 :
F_72 ( V_14 ) ;
break;
case V_224 :
case V_225 :
F_73 ( V_14 ) ;
break;
case V_261 :
F_74 ( V_14 ) ;
break;
default:
break;
}
if ( V_14 -> V_54 >= 0 ) {
F_46 ( V_14 -> V_2 , V_14 -> V_54 , & V_97 ) ;
V_97 = V_97 >> V_14 -> V_57 ;
V_97 &= V_14 -> V_55 ;
if ( V_97 == V_14 -> V_60 )
V_14 -> V_76 = 1 ;
}
V_14 -> V_260 = 1 ;
F_12 ( V_14 , L_92 ) ;
F_139 ( V_14 ) ;
}
F_125 ( V_3 , V_214 ) ;
F_22 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_169 ( struct V_35 * V_36 ,
struct V_262 * V_263 )
{
struct V_1 * V_2 = F_43 ( V_36 ) ;
struct V_30 * V_3 = V_2 -> V_3 ;
struct V_39 * V_40 =
(struct V_39 * ) V_36 -> V_50 ;
int V_54 = V_40 -> V_54 ;
unsigned int V_57 = V_40 -> V_57 ;
int V_56 = V_40 -> V_56 ;
unsigned int V_55 = ( 1 << F_29 ( V_56 ) ) - 1 ;
unsigned int V_58 = V_40 -> V_58 ;
unsigned int V_97 ;
int V_43 = 0 ;
if ( F_170 ( V_40 ) )
F_90 ( V_2 -> V_8 ,
L_93 ,
V_36 -> V_46 . V_17 ) ;
F_85 ( & V_3 -> V_5 , V_135 ) ;
if ( F_39 ( V_36 ) && V_54 != V_99 ) {
V_43 = F_46 ( V_2 , V_54 , & V_97 ) ;
V_97 = ( V_97 >> V_57 ) & V_55 ;
} else {
V_97 = F_41 ( V_36 ) ;
}
F_22 ( & V_3 -> V_5 ) ;
if ( V_58 )
V_263 -> V_62 . integer . V_62 [ 0 ] = V_56 - V_97 ;
else
V_263 -> V_62 . integer . V_62 [ 0 ] = V_97 ;
return V_43 ;
}
int F_171 ( struct V_35 * V_36 ,
struct V_262 * V_263 )
{
struct V_1 * V_2 = F_43 ( V_36 ) ;
struct V_30 * V_3 = V_2 -> V_3 ;
struct V_39 * V_40 =
(struct V_39 * ) V_36 -> V_50 ;
int V_54 = V_40 -> V_54 ;
unsigned int V_57 = V_40 -> V_57 ;
int V_56 = V_40 -> V_56 ;
unsigned int V_55 = ( 1 << F_29 ( V_56 ) ) - 1 ;
unsigned int V_58 = V_40 -> V_58 ;
unsigned int V_97 ;
int V_27 , V_264 , V_265 = 0 ;
struct V_176 V_177 ;
int V_43 = 0 ;
if ( F_170 ( V_40 ) )
F_90 ( V_2 -> V_8 ,
L_93 ,
V_36 -> V_46 . V_17 ) ;
V_97 = ( V_263 -> V_62 . integer . V_62 [ 0 ] & V_55 ) ;
V_27 = ! ! V_97 ;
if ( V_58 )
V_97 = V_56 - V_97 ;
F_85 ( & V_3 -> V_5 , V_135 ) ;
V_264 = F_42 ( V_36 , V_97 ) ;
if ( V_54 != V_99 ) {
V_55 = V_55 << V_57 ;
V_97 = V_97 << V_57 ;
V_265 = F_50 ( V_2 , V_54 , V_55 , V_97 ) ;
}
if ( V_264 || V_265 ) {
if ( V_265 ) {
V_177 . V_36 = V_36 ;
V_177 . V_54 = V_54 ;
V_177 . V_55 = V_55 ;
V_177 . V_97 = V_97 ;
V_3 -> V_177 = & V_177 ;
}
V_264 |= V_265 ;
V_43 = F_147 ( V_3 , V_36 , V_27 ) ;
V_3 -> V_177 = NULL ;
}
F_22 ( & V_3 -> V_5 ) ;
if ( V_43 > 0 )
F_146 ( V_3 ) ;
return V_264 ;
}
int F_172 ( struct V_35 * V_36 ,
struct V_262 * V_263 )
{
struct V_1 * V_2 = F_43 ( V_36 ) ;
struct V_30 * V_3 = V_2 -> V_3 ;
struct V_41 * V_42 = (struct V_41 * ) V_36 -> V_50 ;
unsigned int V_266 , V_97 ;
F_85 ( & V_3 -> V_5 , V_135 ) ;
if ( V_42 -> V_54 != V_99 && F_39 ( V_36 ) ) {
int V_43 = F_46 ( V_2 , V_42 -> V_54 , & V_266 ) ;
if ( V_43 ) {
F_22 ( & V_3 -> V_5 ) ;
return V_43 ;
}
} else {
V_266 = F_41 ( V_36 ) ;
}
F_22 ( & V_3 -> V_5 ) ;
V_97 = ( V_266 >> V_42 -> V_65 ) & V_42 -> V_55 ;
V_263 -> V_62 . V_267 . V_98 [ 0 ] = F_62 ( V_42 , V_97 ) ;
if ( V_42 -> V_65 != V_42 -> V_268 ) {
V_97 = ( V_266 >> V_42 -> V_268 ) & V_42 -> V_55 ;
V_97 = F_62 ( V_42 , V_97 ) ;
V_263 -> V_62 . V_267 . V_98 [ 1 ] = V_97 ;
}
return 0 ;
}
int F_173 ( struct V_35 * V_36 ,
struct V_262 * V_263 )
{
struct V_1 * V_2 = F_43 ( V_36 ) ;
struct V_30 * V_3 = V_2 -> V_3 ;
struct V_41 * V_42 = (struct V_41 * ) V_36 -> V_50 ;
unsigned int * V_98 = V_263 -> V_62 . V_267 . V_98 ;
unsigned int V_97 , V_264 , V_265 = 0 ;
unsigned int V_55 ;
struct V_176 V_177 ;
int V_43 = 0 ;
if ( V_98 [ 0 ] >= V_42 -> V_100 )
return - V_115 ;
V_97 = F_31 ( V_42 , V_98 [ 0 ] ) << V_42 -> V_65 ;
V_55 = V_42 -> V_55 << V_42 -> V_65 ;
if ( V_42 -> V_65 != V_42 -> V_268 ) {
if ( V_98 [ 1 ] > V_42 -> V_100 )
return - V_115 ;
V_97 |= F_31 ( V_42 , V_98 [ 1 ] ) << V_42 -> V_65 ;
V_55 |= V_42 -> V_55 << V_42 -> V_268 ;
}
F_85 ( & V_3 -> V_5 , V_135 ) ;
V_264 = F_42 ( V_36 , V_97 ) ;
if ( V_42 -> V_54 != V_99 )
V_265 = F_50 ( V_2 , V_42 -> V_54 , V_55 , V_97 ) ;
if ( V_264 || V_265 ) {
if ( V_265 ) {
V_177 . V_36 = V_36 ;
V_177 . V_54 = V_42 -> V_54 ;
V_177 . V_55 = V_55 ;
V_177 . V_97 = V_97 ;
V_3 -> V_177 = & V_177 ;
}
V_264 |= V_265 ;
V_43 = F_143 ( V_3 , V_36 , V_98 [ 0 ] , V_42 ) ;
V_3 -> V_177 = NULL ;
}
F_22 ( & V_3 -> V_5 ) ;
if ( V_43 > 0 )
F_146 ( V_3 ) ;
return V_264 ;
}
int F_174 ( struct V_35 * V_36 ,
struct V_269 * V_270 )
{
V_270 -> type = V_271 ;
V_270 -> V_203 = 1 ;
V_270 -> V_62 . integer . V_272 = 0 ;
V_270 -> V_62 . integer . V_56 = 1 ;
return 0 ;
}
int F_175 ( struct V_35 * V_36 ,
struct V_262 * V_263 )
{
struct V_30 * V_3 = F_34 ( V_36 ) ;
const char * V_236 = ( const char * ) V_36 -> V_50 ;
F_85 ( & V_3 -> V_5 , V_135 ) ;
V_263 -> V_62 . integer . V_62 [ 0 ] =
F_176 ( & V_3 -> V_2 , V_236 ) ;
F_22 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_177 ( struct V_35 * V_36 ,
struct V_262 * V_263 )
{
struct V_30 * V_3 = F_34 ( V_36 ) ;
const char * V_236 = ( const char * ) V_36 -> V_50 ;
if ( V_263 -> V_62 . integer . V_62 [ 0 ] )
F_178 ( & V_3 -> V_2 , V_236 ) ;
else
F_179 ( & V_3 -> V_2 , V_236 ) ;
F_158 ( & V_3 -> V_2 ) ;
return 0 ;
}
struct V_13 *
F_180 ( struct V_1 * V_2 ,
const struct V_13 * V_34 )
{
struct V_13 * V_14 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_135 ) ;
V_14 = F_30 ( V_2 , V_34 ) ;
if ( ! V_14 )
F_70 ( V_2 -> V_8 ,
L_94 ,
V_34 -> V_17 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_14 ;
}
struct V_13 *
F_30 ( struct V_1 * V_2 ,
const struct V_13 * V_34 )
{
struct V_13 * V_14 ;
const char * V_109 ;
int V_43 ;
if ( ( V_14 = F_23 ( V_34 ) ) == NULL )
return NULL ;
switch ( V_14 -> V_46 ) {
case V_197 :
V_14 -> V_141 = F_181 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_182 ( V_14 -> V_141 ) ) {
V_43 = F_183 ( V_14 -> V_141 ) ;
F_70 ( V_2 -> V_8 , L_95 ,
V_14 -> V_17 , V_43 ) ;
return NULL ;
}
if ( V_14 -> V_60 & V_140 ) {
V_43 = F_89 ( V_14 -> V_141 , true ) ;
if ( V_43 != 0 )
F_90 ( V_14 -> V_2 -> V_8 ,
L_17 ,
V_14 -> V_17 , V_43 ) ;
}
break;
case V_198 :
#ifdef F_184
V_14 -> V_142 = F_185 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_182 ( V_14 -> V_142 ) ) {
V_43 = F_183 ( V_14 -> V_142 ) ;
F_70 ( V_2 -> V_8 , L_95 ,
V_14 -> V_17 , V_43 ) ;
return NULL ;
}
#else
return NULL ;
#endif
break;
default:
break;
}
V_109 = F_45 ( V_2 ) ;
if ( V_109 )
V_14 -> V_17 = F_28 ( V_12 , L_4 , V_109 , V_34 -> V_17 ) ;
else
V_14 -> V_17 = F_28 ( V_12 , L_1 , V_34 -> V_17 ) ;
if ( V_14 -> V_17 == NULL ) {
F_9 ( V_14 ) ;
return NULL ;
}
switch ( V_14 -> V_46 ) {
case V_219 :
V_14 -> V_32 = 1 ;
V_14 -> V_144 = F_98 ;
break;
case V_240 :
if ( ! V_2 -> V_3 -> V_241 )
V_14 -> V_32 = 1 ;
V_14 -> V_144 = F_98 ;
break;
case V_220 :
case V_218 :
V_14 -> V_31 = 1 ;
V_14 -> V_144 = F_98 ;
break;
case V_242 :
if ( ! V_2 -> V_3 -> V_241 )
V_14 -> V_31 = 1 ;
V_14 -> V_144 = F_98 ;
break;
case V_195 :
case V_194 :
V_14 -> V_32 = 1 ;
V_14 -> V_144 = F_100 ;
break;
case V_64 :
case V_63 :
case V_47 :
case V_48 :
case V_49 :
case V_223 :
case V_273 :
case V_222 :
case V_274 :
case V_224 :
case V_225 :
case V_199 :
case V_221 :
case V_261 :
case V_275 :
case V_276 :
V_14 -> V_144 = F_98 ;
break;
case V_196 :
case V_197 :
case V_198 :
case V_61 :
V_14 -> V_25 = 1 ;
V_14 -> V_144 = F_99 ;
break;
default:
V_14 -> V_144 = F_100 ;
break;
}
V_14 -> V_2 = V_2 ;
F_27 ( & V_14 -> V_118 ) ;
F_27 ( & V_14 -> V_119 ) ;
F_27 ( & V_14 -> V_22 ) ;
F_27 ( & V_14 -> V_15 ) ;
F_14 ( & V_14 -> V_22 , & V_2 -> V_3 -> V_73 ) ;
V_14 -> V_23 = - 1 ;
V_14 -> V_29 = - 1 ;
V_14 -> V_128 = 1 ;
return V_14 ;
}
int F_186 ( struct V_1 * V_2 ,
const struct V_13 * V_34 ,
int V_257 )
{
struct V_13 * V_14 ;
int V_87 ;
int V_43 = 0 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_259 ) ;
for ( V_87 = 0 ; V_87 < V_257 ; V_87 ++ ) {
V_14 = F_30 ( V_2 , V_34 ) ;
if ( ! V_14 ) {
F_70 ( V_2 -> V_8 ,
L_94 ,
V_34 -> V_17 ) ;
V_43 = - V_44 ;
break;
}
V_34 ++ ;
}
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_43 ;
}
static int F_187 ( struct V_13 * V_14 ,
struct V_35 * V_36 , int V_139 )
{
struct V_20 * V_277 , * V_278 ;
struct V_132 * V_28 , * V_19 ;
const struct V_279 * V_280 = V_14 -> V_281 + V_14 -> V_282 ;
struct V_283 V_284 ;
struct V_285 * V_281 = NULL ;
T_8 V_9 ;
int V_43 ;
if ( F_109 ( ! V_280 ) ||
F_109 ( F_11 ( & V_14 -> V_118 ) || F_11 ( & V_14 -> V_119 ) ) )
return - V_115 ;
V_277 = F_108 ( & V_14 -> V_118 , struct V_20 ,
V_232 ) ;
V_278 = F_108 ( & V_14 -> V_119 , struct V_20 ,
V_233 ) ;
if ( F_109 ( ! V_277 || ! V_278 ) ||
F_109 ( ! V_278 -> V_28 || ! V_277 -> V_19 ) ||
F_109 ( ! V_277 -> V_28 || ! V_278 -> V_19 ) )
return - V_115 ;
V_28 = V_277 -> V_28 -> V_286 ;
V_19 = V_278 -> V_19 -> V_286 ;
if ( V_280 -> V_287 ) {
V_9 = F_188 ( V_280 -> V_287 ) - 1 ;
} else {
F_90 ( V_14 -> V_2 -> V_8 , L_96 ,
V_280 -> V_287 ) ;
V_9 = 0 ;
}
V_281 = F_26 ( sizeof( * V_281 ) , V_12 ) ;
if ( ! V_281 ) {
V_43 = - V_44 ;
goto V_92;
}
F_189 ( F_190 ( V_281 , V_288 ) , V_9 ) ;
F_191 ( V_281 , V_289 ) -> V_272 =
V_280 -> V_290 ;
F_191 ( V_281 , V_289 ) -> V_56 =
V_280 -> V_291 ;
F_191 ( V_281 , V_292 ) -> V_272
= V_280 -> V_293 ;
F_191 ( V_281 , V_292 ) -> V_56
= V_280 -> V_294 ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
switch ( V_139 ) {
case V_157 :
V_284 . V_134 = V_295 ;
V_43 = F_192 ( & V_284 , V_281 , V_28 ) ;
if ( V_43 < 0 )
goto V_92;
V_284 . V_134 = V_136 ;
V_43 = F_192 ( & V_284 , V_281 , V_19 ) ;
if ( V_43 < 0 )
goto V_92;
break;
case V_158 :
V_43 = F_193 ( V_19 , 0 ,
V_136 ) ;
if ( V_43 != 0 && V_43 != - V_296 )
F_90 ( V_19 -> V_8 , L_97 , V_43 ) ;
V_43 = 0 ;
break;
case V_159 :
V_43 = F_193 ( V_19 , 1 ,
V_136 ) ;
if ( V_43 != 0 && V_43 != - V_296 )
F_90 ( V_19 -> V_8 , L_98 , V_43 ) ;
V_43 = 0 ;
break;
default:
F_104 ( 1 , L_24 , V_139 ) ;
return - V_115 ;
}
V_92:
F_9 ( V_281 ) ;
return V_43 ;
}
static int F_194 ( struct V_35 * V_36 ,
struct V_262 * V_263 )
{
struct V_13 * V_14 = F_34 ( V_36 ) ;
V_263 -> V_62 . integer . V_62 [ 0 ] = V_14 -> V_282 ;
return 0 ;
}
static int F_195 ( struct V_35 * V_36 ,
struct V_262 * V_263 )
{
struct V_13 * V_14 = F_34 ( V_36 ) ;
if ( V_14 -> V_76 )
return - V_297 ;
if ( V_263 -> V_62 . integer . V_62 [ 0 ] == V_14 -> V_282 )
return 0 ;
if ( V_263 -> V_62 . integer . V_62 [ 0 ] >= V_14 -> V_120 )
return - V_115 ;
V_14 -> V_282 = V_263 -> V_62 . integer . V_62 [ 0 ] ;
return 0 ;
}
int F_196 ( struct V_30 * V_3 ,
const struct V_279 * V_281 ,
unsigned int V_120 ,
struct V_13 * V_28 ,
struct V_13 * V_19 )
{
struct V_13 V_52 ;
struct V_13 * V_14 ;
char * V_298 ;
int V_43 , V_203 ;
unsigned long V_50 ;
const char * * V_299 ;
struct V_41 V_300 [] = {
F_197 ( 0 , 0 , 0 , NULL ) ,
} ;
struct V_95 V_301 [] = {
F_198 ( NULL , V_300 [ 0 ] ,
F_194 ,
F_195 ) ,
} ;
const struct V_279 * V_280 = V_281 ;
V_299 = F_199 ( V_3 -> V_8 , V_120 ,
sizeof( char * ) , V_12 ) ;
if ( ! V_299 )
return - V_44 ;
V_298 = F_200 ( V_3 -> V_8 , V_12 , L_99 ,
V_28 -> V_17 , V_19 -> V_17 ) ;
if ( ! V_298 ) {
V_43 = - V_44 ;
goto V_302;
}
for ( V_203 = 0 ; V_203 < V_120 ; V_203 ++ ) {
if ( ! V_280 -> V_303 ) {
F_90 ( V_3 -> V_2 . V_8 ,
L_100 ,
V_203 , V_298 ) ;
V_299 [ V_203 ] =
F_200 ( V_3 -> V_8 , V_12 ,
L_101 ,
V_203 ) ;
if ( ! V_299 [ V_203 ] ) {
V_43 = - V_44 ;
goto V_304;
}
} else {
V_299 [ V_203 ] = F_201 ( V_3 -> V_8 ,
V_280 -> V_303 ,
strlen ( V_280 -> V_303 ) + 1 ,
V_12 ) ;
if ( ! V_299 [ V_203 ] ) {
V_43 = - V_44 ;
goto V_304;
}
}
V_280 ++ ;
}
V_300 [ 0 ] . V_100 = V_120 ;
V_300 [ 0 ] . V_101 = V_299 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_54 = V_99 ;
V_52 . V_46 = V_261 ;
V_52 . V_17 = V_298 ;
V_52 . V_139 = F_187 ;
V_52 . V_163 = V_157 | V_158 |
V_159 ;
V_52 . V_103 = 1 ;
V_50 =
( unsigned long ) F_201 ( V_3 -> V_8 ,
( void * ) ( V_301 [ 0 ] . V_50 ) ,
sizeof( struct V_41 ) , V_12 ) ;
if ( ! V_50 ) {
F_70 ( V_3 -> V_8 , L_102 ,
V_298 ) ;
V_43 = - V_44 ;
goto V_304;
}
V_301 [ 0 ] . V_50 = V_50 ;
V_52 . V_96 =
F_201 ( V_3 -> V_8 , & V_301 [ 0 ] ,
sizeof( struct V_95 ) ,
V_12 ) ;
if ( ! V_52 . V_96 ) {
F_70 ( V_3 -> V_8 , L_102 ,
V_298 ) ;
V_43 = - V_44 ;
goto V_305;
}
F_77 ( V_3 -> V_8 , L_103 , V_298 ) ;
V_14 = F_30 ( & V_3 -> V_2 , & V_52 ) ;
if ( ! V_14 ) {
F_70 ( V_3 -> V_8 , L_104 ,
V_298 ) ;
V_43 = - V_44 ;
goto V_306;
}
V_14 -> V_281 = V_281 ;
V_14 -> V_120 = V_120 ;
V_43 = F_32 ( & V_3 -> V_2 , V_28 , V_14 , NULL , NULL ) ;
if ( V_43 )
goto V_307;
return F_32 ( & V_3 -> V_2 , V_14 , V_19 , NULL , NULL ) ;
V_307:
F_202 ( V_3 -> V_8 , V_14 ) ;
V_306:
F_202 ( V_3 -> V_8 , ( void * ) V_52 . V_96 ) ;
V_305:
F_202 ( V_3 -> V_8 , ( void * ) V_50 ) ;
V_304:
F_202 ( V_3 -> V_8 , V_298 ) ;
V_302:
for ( V_203 = 0 ; V_203 < V_120 ; V_203 ++ )
F_202 ( V_3 -> V_8 , ( void * ) V_299 [ V_203 ] ) ;
F_202 ( V_3 -> V_8 , V_299 ) ;
return V_43 ;
}
int F_203 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_13 V_52 ;
struct V_13 * V_14 ;
F_109 ( V_2 -> V_8 != V_133 -> V_8 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_54 = V_99 ;
if ( V_133 -> V_308 -> V_309 . V_303 ) {
V_52 . V_46 = V_276 ;
V_52 . V_17 = V_133 -> V_308 -> V_309 . V_303 ;
V_52 . V_205 = V_133 -> V_308 -> V_309 . V_303 ;
F_77 ( V_133 -> V_8 , L_103 ,
V_52 . V_17 ) ;
V_14 = F_30 ( V_2 , & V_52 ) ;
if ( ! V_14 ) {
F_70 ( V_2 -> V_8 , L_104 ,
V_133 -> V_308 -> V_309 . V_303 ) ;
return - V_44 ;
}
V_14 -> V_286 = V_133 ;
V_133 -> V_137 = V_14 ;
}
if ( V_133 -> V_308 -> V_310 . V_303 ) {
V_52 . V_46 = V_275 ;
V_52 . V_17 = V_133 -> V_308 -> V_310 . V_303 ;
V_52 . V_205 = V_133 -> V_308 -> V_310 . V_303 ;
F_77 ( V_133 -> V_8 , L_103 ,
V_52 . V_17 ) ;
V_14 = F_30 ( V_2 , & V_52 ) ;
if ( ! V_14 ) {
F_70 ( V_2 -> V_8 , L_104 ,
V_133 -> V_308 -> V_310 . V_303 ) ;
return - V_44 ;
}
V_14 -> V_286 = V_133 ;
V_133 -> V_138 = V_14 ;
}
return 0 ;
}
int F_204 ( struct V_30 * V_3 )
{
struct V_13 * V_311 , * V_14 ;
struct V_13 * V_312 , * V_19 ;
struct V_132 * V_133 ;
F_17 (dai_w, &card->widgets, list) {
switch ( V_311 -> V_46 ) {
case V_276 :
case V_275 :
break;
default:
continue;
}
V_133 = V_311 -> V_286 ;
F_17 (w, &card->widgets, list) {
if ( V_14 -> V_2 != V_311 -> V_2 )
continue;
switch ( V_14 -> V_46 ) {
case V_276 :
case V_275 :
continue;
default:
break;
}
if ( ! V_14 -> V_205 || ! strstr ( V_14 -> V_205 , V_311 -> V_205 ) )
continue;
if ( V_311 -> V_46 == V_276 ) {
V_312 = V_311 ;
V_19 = V_14 ;
} else {
V_312 = V_14 ;
V_19 = V_311 ;
}
F_77 ( V_133 -> V_8 , L_105 , V_312 -> V_17 , V_19 -> V_17 ) ;
F_32 ( V_14 -> V_2 , V_312 , V_19 , NULL , NULL ) ;
}
}
return 0 ;
}
static void F_205 ( struct V_30 * V_3 ,
struct V_228 * V_229 )
{
struct V_132 * V_313 = V_229 -> V_313 ;
struct V_13 * V_19 , * V_28 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_229 -> V_230 ; V_87 ++ ) {
struct V_132 * V_314 = V_229 -> V_231 [ V_87 ] ;
if ( F_206 ( V_314 ) ||
F_206 ( V_313 ) )
continue;
if ( V_314 -> V_137 && V_313 -> V_137 ) {
V_28 = V_313 -> V_137 ;
V_19 = V_314 -> V_137 ;
F_77 ( V_229 -> V_8 , L_106 ,
V_313 -> V_81 -> V_17 , V_28 -> V_17 ,
V_314 -> V_81 -> V_17 , V_19 -> V_17 ) ;
F_32 ( & V_3 -> V_2 , V_28 , V_19 ,
NULL , NULL ) ;
}
if ( V_314 -> V_138 && V_313 -> V_138 ) {
V_28 = V_314 -> V_138 ;
V_19 = V_313 -> V_138 ;
F_77 ( V_229 -> V_8 , L_106 ,
V_314 -> V_81 -> V_17 , V_28 -> V_17 ,
V_313 -> V_81 -> V_17 , V_19 -> V_17 ) ;
F_32 ( & V_3 -> V_2 , V_28 , V_19 ,
NULL , NULL ) ;
}
}
}
static void F_207 ( struct V_132 * V_133 , int V_134 ,
int V_139 )
{
struct V_13 * V_14 ;
if ( V_134 == V_136 )
V_14 = V_133 -> V_137 ;
else
V_14 = V_133 -> V_138 ;
if ( V_14 ) {
F_12 ( V_14 , L_107 ) ;
switch ( V_139 ) {
case V_173 :
V_14 -> V_206 = 1 ;
break;
case V_174 :
V_14 -> V_206 = 0 ;
break;
case V_315 :
case V_316 :
case V_317 :
case V_318 :
break;
}
if ( V_14 -> V_46 == V_276 ) {
V_14 -> V_32 = V_14 -> V_206 ;
F_15 ( V_14 ) ;
} else {
V_14 -> V_31 = V_14 -> V_206 ;
F_18 ( V_14 ) ;
}
}
}
void F_208 ( struct V_30 * V_3 )
{
struct V_228 * V_229 = V_3 -> V_229 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_3 -> V_319 ; V_87 ++ ) {
V_229 = & V_3 -> V_229 [ V_87 ] ;
if ( V_229 -> V_320 -> V_321 || V_229 -> V_320 -> V_281 )
continue;
F_205 ( V_3 , V_229 ) ;
}
}
static void F_209 ( struct V_228 * V_229 , int V_134 ,
int V_139 )
{
int V_87 ;
F_207 ( V_229 -> V_313 , V_134 , V_139 ) ;
for ( V_87 = 0 ; V_87 < V_229 -> V_230 ; V_87 ++ )
F_207 ( V_229 -> V_231 [ V_87 ] , V_134 , V_139 ) ;
F_125 ( V_229 -> V_3 , V_139 ) ;
}
void F_210 ( struct V_228 * V_229 , int V_134 ,
int V_139 )
{
struct V_30 * V_3 = V_229 -> V_3 ;
F_85 ( & V_3 -> V_5 , V_135 ) ;
F_209 ( V_229 , V_134 , V_139 ) ;
F_22 ( & V_3 -> V_5 ) ;
}
int F_211 ( struct V_1 * V_2 ,
const char * V_236 )
{
return F_156 ( V_2 , V_236 , 1 ) ;
}
int F_178 ( struct V_1 * V_2 , const char * V_236 )
{
int V_43 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_135 ) ;
V_43 = F_156 ( V_2 , V_236 , 1 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_43 ;
}
int F_212 ( struct V_1 * V_2 ,
const char * V_236 )
{
struct V_13 * V_14 = F_155 ( V_2 , V_236 , true ) ;
if ( ! V_14 ) {
F_70 ( V_2 -> V_8 , L_108 , V_236 ) ;
return - V_115 ;
}
F_77 ( V_14 -> V_2 -> V_8 , L_109 , V_236 ) ;
if ( ! V_14 -> V_128 ) {
F_15 ( V_14 ) ;
F_18 ( V_14 ) ;
V_14 -> V_128 = 1 ;
}
V_14 -> V_143 = 1 ;
F_12 ( V_14 , L_110 ) ;
return 0 ;
}
int F_213 ( struct V_1 * V_2 ,
const char * V_236 )
{
int V_43 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_135 ) ;
V_43 = F_212 ( V_2 , V_236 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_43 ;
}
int F_214 ( struct V_1 * V_2 ,
const char * V_236 )
{
return F_156 ( V_2 , V_236 , 0 ) ;
}
int F_179 ( struct V_1 * V_2 ,
const char * V_236 )
{
int V_43 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_135 ) ;
V_43 = F_156 ( V_2 , V_236 , 0 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_43 ;
}
int F_215 ( struct V_1 * V_2 ,
const char * V_236 )
{
return F_156 ( V_2 , V_236 , 0 ) ;
}
int F_216 ( struct V_1 * V_2 , const char * V_236 )
{
int V_43 ;
F_85 ( & V_2 -> V_3 -> V_5 , V_135 ) ;
V_43 = F_156 ( V_2 , V_236 , 0 ) ;
F_22 ( & V_2 -> V_3 -> V_5 ) ;
return V_43 ;
}
int F_176 ( struct V_1 * V_2 ,
const char * V_236 )
{
struct V_13 * V_14 = F_155 ( V_2 , V_236 , true ) ;
if ( V_14 )
return V_14 -> V_128 ;
return 0 ;
}
int F_217 ( struct V_1 * V_2 ,
const char * V_236 )
{
struct V_13 * V_14 = F_155 ( V_2 , V_236 , false ) ;
if ( ! V_14 ) {
F_70 ( V_2 -> V_8 , L_108 , V_236 ) ;
return - V_115 ;
}
V_14 -> V_123 = 1 ;
return 0 ;
}
void F_218 ( struct V_1 * V_2 )
{
F_140 ( V_2 ) ;
F_154 ( V_2 ) ;
F_153 ( & V_2 -> V_22 ) ;
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_30 * V_3 = V_2 -> V_3 ;
struct V_13 * V_14 ;
F_16 ( V_189 ) ;
int V_322 = 0 ;
F_21 ( & V_3 -> V_5 ) ;
F_17 (w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
if ( V_14 -> V_76 ) {
F_102 ( V_14 , & V_189 , false ) ;
V_14 -> V_76 = 0 ;
V_322 = 1 ;
}
}
if ( V_322 ) {
if ( V_2 -> V_91 == V_185 )
F_58 ( V_2 ,
V_186 ) ;
F_110 ( V_3 , & V_189 , 0 , false ) ;
if ( V_2 -> V_91 == V_186 )
F_58 ( V_2 ,
V_184 ) ;
}
F_22 ( & V_3 -> V_5 ) ;
}
void F_220 ( struct V_30 * V_3 )
{
struct V_1 * V_2 ;
F_17 (dapm, &card->dapm_list, list) {
if ( V_2 != & V_3 -> V_2 ) {
F_219 ( V_2 ) ;
if ( V_2 -> V_91 == V_184 )
F_58 ( V_2 ,
V_182 ) ;
}
}
F_219 ( & V_3 -> V_2 ) ;
if ( V_3 -> V_2 . V_91 == V_184 )
F_58 ( & V_3 -> V_2 ,
V_182 ) ;
}
