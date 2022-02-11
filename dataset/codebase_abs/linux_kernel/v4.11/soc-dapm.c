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
static T_3 void F_15 (
struct V_13 * V_14 , enum V_19 V_20 )
{
enum V_19 V_21 = F_16 ( V_20 ) ;
struct V_13 * V_22 ;
struct V_23 * V_24 ;
F_17 ( V_25 ) ;
F_1 ( V_14 -> V_2 ) ;
if ( V_14 -> V_26 [ V_20 ] == - 1 )
return;
F_14 ( & V_14 -> V_27 , & V_25 ) ;
V_14 -> V_26 [ V_20 ] = - 1 ;
F_18 (w, &list, work_list) {
F_19 (w, dir, p) {
if ( V_24 -> V_28 || V_24 -> V_29 || ! V_24 -> V_30 )
continue;
V_22 = V_24 -> V_22 [ V_21 ] ;
if ( V_22 -> V_26 [ V_20 ] != - 1 ) {
V_22 -> V_26 [ V_20 ] = - 1 ;
F_14 ( & V_22 -> V_27 , & V_25 ) ;
}
}
}
}
static void F_20 ( struct V_13 * V_14 )
{
F_15 ( V_14 , V_31 ) ;
}
static void F_21 ( struct V_13 * V_14 )
{
F_15 ( V_14 , V_32 ) ;
}
static void F_22 ( struct V_23 * V_24 )
{
if ( V_24 -> V_29 || V_24 -> V_28 )
return;
if ( V_24 -> V_33 -> V_26 [ V_31 ] != 0 )
F_20 ( V_24 -> V_34 ) ;
if ( V_24 -> V_34 -> V_26 [ V_32 ] != 0 )
F_21 ( V_24 -> V_33 ) ;
}
void F_23 ( struct V_35 * V_3 )
{
struct V_13 * V_14 ;
F_24 ( & V_3 -> V_5 ) ;
F_18 (w, &card->widgets, list) {
if ( V_14 -> V_36 ) {
F_12 ( V_14 , L_3 ) ;
if ( V_14 -> V_36 & V_37 )
F_21 ( V_14 ) ;
if ( V_14 -> V_36 & V_38 )
F_20 ( V_14 ) ;
}
}
F_25 ( & V_3 -> V_5 ) ;
}
static inline struct V_13 * F_26 (
const struct V_13 * V_39 )
{
return F_27 ( V_39 , sizeof( * V_39 ) , V_12 ) ;
}
static int F_28 ( struct V_13 * V_40 ,
struct V_41 * V_42 , const char * V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
const char * V_17 ;
int V_50 ;
V_45 = F_29 ( sizeof( * V_45 ) , V_12 ) ;
if ( ! V_45 )
return - V_51 ;
F_30 ( & V_45 -> V_52 ) ;
switch ( V_40 -> V_53 ) {
case V_54 :
case V_55 :
case V_56 :
V_47 = (struct V_46 * ) V_42 -> V_57 ;
if ( V_47 -> V_58 && F_31 ( V_47 ) )
F_32 ( V_40 -> V_2 -> V_8 ,
L_4 ,
V_43 ) ;
if ( V_47 -> V_58 ) {
struct V_13 V_59 ;
V_17 = F_33 ( V_12 , L_5 , V_43 ,
L_6 ) ;
if ( ! V_17 ) {
V_50 = - V_51 ;
goto V_60;
}
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_61 = V_47 -> V_61 ;
V_59 . V_62 = ( 1 << F_34 ( V_47 -> V_63 ) ) - 1 ;
V_59 . V_64 = V_47 -> V_64 ;
if ( V_47 -> V_65 )
V_59 . V_66 = V_47 -> V_63 ;
else
V_59 . V_66 = 0 ;
V_59 . V_67 = V_59 . V_66 ;
V_59 . V_53 = V_68 ;
V_59 . V_17 = V_17 ;
V_45 -> V_69 = V_59 . V_67 ;
V_45 -> V_40 =
F_35 ( V_40 -> V_2 ,
& V_59 ) ;
F_9 ( V_17 ) ;
if ( F_36 ( V_45 -> V_40 ) ) {
V_50 = F_37 ( V_45 -> V_40 ) ;
goto V_60;
}
if ( ! V_45 -> V_40 ) {
V_50 = - V_51 ;
goto V_60;
}
}
break;
case V_70 :
case V_71 :
V_49 = (struct V_48 * ) V_42 -> V_57 ;
if ( V_49 -> V_58 ) {
struct V_13 V_59 ;
V_17 = F_33 ( V_12 , L_5 , V_43 ,
L_6 ) ;
if ( ! V_17 ) {
V_50 = - V_51 ;
goto V_60;
}
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_61 = V_49 -> V_61 ;
V_59 . V_62 = V_49 -> V_62 << V_49 -> V_72 ;
V_59 . V_64 = V_49 -> V_72 ;
V_59 . V_66 = F_38 ( V_49 , 0 ) ;
V_59 . V_67 = V_59 . V_66 ;
V_59 . V_53 = V_68 ;
V_59 . V_17 = V_17 ;
V_45 -> V_69 = V_59 . V_67 ;
V_45 -> V_40 = F_35 (
V_40 -> V_2 , & V_59 ) ;
F_9 ( V_17 ) ;
if ( F_36 ( V_45 -> V_40 ) ) {
V_50 = F_37 ( V_45 -> V_40 ) ;
goto V_60;
}
if ( ! V_45 -> V_40 ) {
V_50 = - V_51 ;
goto V_60;
}
F_39 ( V_40 -> V_2 , V_45 -> V_40 ,
V_40 , NULL , NULL ) ;
}
break;
default:
break;
}
V_42 -> V_73 = V_45 ;
return 0 ;
V_60:
F_9 ( V_45 ) ;
return V_50 ;
}
static void F_40 ( struct V_41 * V_74 )
{
struct V_44 * V_45 = F_41 ( V_74 ) ;
F_9 ( V_45 -> V_75 ) ;
F_9 ( V_45 ) ;
}
static struct V_76 * F_42 (
const struct V_41 * V_42 )
{
struct V_44 * V_45 = F_41 ( V_42 ) ;
return V_45 -> V_75 ;
}
static int F_43 ( struct V_41 * V_42 ,
struct V_13 * V_40 )
{
struct V_44 * V_45 = F_41 ( V_42 ) ;
struct V_76 * V_77 ;
unsigned int V_78 ;
if ( V_45 -> V_75 )
V_78 = V_45 -> V_75 -> V_79 + 1 ;
else
V_78 = 1 ;
V_77 = F_44 ( V_45 -> V_75 ,
sizeof( * V_77 ) + sizeof( V_40 ) * V_78 , V_12 ) ;
if ( ! V_77 )
return - V_51 ;
V_77 -> V_80 [ V_78 - 1 ] = V_40 ;
V_77 -> V_79 = V_78 ;
V_45 -> V_75 = V_77 ;
return 0 ;
}
static void F_45 ( const struct V_41 * V_42 ,
struct V_23 * V_81 )
{
struct V_44 * V_45 = F_41 ( V_42 ) ;
F_14 ( & V_81 -> V_82 , & V_45 -> V_52 ) ;
}
static bool F_46 ( const struct V_41 * V_42 )
{
struct V_44 * V_45 = F_41 ( V_42 ) ;
if ( ! V_45 -> V_40 )
return true ;
return V_45 -> V_40 -> V_83 ;
}
static struct V_84 * F_47 (
const struct V_41 * V_42 )
{
struct V_44 * V_45 = F_41 ( V_42 ) ;
return & V_45 -> V_52 ;
}
unsigned int F_48 ( const struct V_41 * V_42 )
{
struct V_44 * V_45 = F_41 ( V_42 ) ;
return V_45 -> V_69 ;
}
static bool F_49 ( const struct V_41 * V_42 ,
unsigned int V_69 )
{
struct V_44 * V_45 = F_41 ( V_42 ) ;
if ( V_45 -> V_69 == V_69 )
return false ;
if ( V_45 -> V_40 )
V_45 -> V_40 -> V_67 = V_69 ;
V_45 -> V_69 = V_69 ;
return true ;
}
struct V_13 * F_50 (
struct V_41 * V_42 )
{
return F_42 ( V_42 ) -> V_80 [ 0 ] ;
}
struct V_1 * F_51 (
struct V_41 * V_42 )
{
return F_42 ( V_42 ) -> V_80 [ 0 ] -> V_2 ;
}
static void F_52 ( struct V_35 * V_3 )
{
struct V_13 * V_14 ;
F_2 ( & V_3 -> V_5 ) ;
memset ( & V_3 -> V_85 , 0 , sizeof( V_3 -> V_85 ) ) ;
F_18 (w, &card->widgets, list) {
V_14 -> V_86 = V_14 -> V_83 ;
V_14 -> V_87 = false ;
}
}
static const char * F_53 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_88 )
return NULL ;
return V_2 -> V_88 -> V_89 ;
}
static int F_54 ( struct V_1 * V_2 , int V_61 ,
unsigned int * V_69 )
{
if ( ! V_2 -> V_88 )
return - V_90 ;
return F_55 ( V_2 -> V_88 , V_61 , V_69 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
int V_61 , unsigned int V_62 , unsigned int V_69 )
{
if ( ! V_2 -> V_88 )
return - V_90 ;
return F_57 ( V_2 -> V_88 , V_61 ,
V_62 , V_69 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
int V_61 , unsigned int V_62 , unsigned int V_69 )
{
if ( ! V_2 -> V_88 )
return - V_90 ;
return F_59 ( V_2 -> V_88 , V_61 , V_62 , V_69 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_88 )
F_61 ( V_2 -> V_88 ) ;
}
static struct V_13 *
F_62 ( struct V_91 * V_92 , const char * V_17 )
{
struct V_13 * V_14 = V_92 -> V_40 ;
struct V_84 * V_75 ;
const int V_93 = 2 ;
int V_94 = 0 ;
if ( V_14 ) {
V_75 = & V_14 -> V_2 -> V_3 -> V_80 ;
F_63 (w, wlist, list) {
if ( ! strcmp ( V_17 , V_14 -> V_17 ) )
return V_14 ;
if ( ++ V_94 == V_93 )
break;
}
}
return NULL ;
}
static inline void F_64 ( struct V_91 * V_92 ,
struct V_13 * V_14 )
{
V_92 -> V_40 = V_14 ;
}
int F_65 ( struct V_1 * V_2 ,
enum V_95 V_96 )
{
int V_50 = 0 ;
if ( V_2 -> V_97 )
V_50 = V_2 -> V_97 ( V_2 , V_96 ) ;
if ( V_50 == 0 )
V_2 -> V_98 = V_96 ;
return V_50 ;
}
static int F_66 ( struct V_1 * V_2 ,
enum V_95 V_96 )
{
struct V_35 * V_3 = V_2 -> V_3 ;
int V_50 = 0 ;
F_67 ( V_3 , V_96 ) ;
if ( V_3 && V_3 -> V_97 )
V_50 = V_3 -> V_97 ( V_3 , V_2 , V_96 ) ;
if ( V_50 != 0 )
goto V_99;
if ( ! V_3 || V_2 != & V_3 -> V_2 )
V_50 = F_65 ( V_2 , V_96 ) ;
if ( V_50 != 0 )
goto V_99;
if ( V_3 && V_3 -> V_100 )
V_50 = V_3 -> V_100 ( V_3 , V_2 , V_96 ) ;
V_99:
F_68 ( V_3 , V_96 ) ;
return V_50 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_23 * V_81 , const char * V_101 ,
struct V_13 * V_14 )
{
const struct V_102 * V_42 = & V_14 -> V_103 [ 0 ] ;
struct V_48 * V_49 = (struct V_48 * ) V_42 -> V_57 ;
unsigned int V_104 , V_105 ;
int V_94 ;
if ( V_49 -> V_61 != V_106 ) {
F_54 ( V_2 , V_49 -> V_61 , & V_104 ) ;
V_104 = ( V_104 >> V_49 -> V_72 ) & V_49 -> V_62 ;
V_105 = F_70 ( V_49 , V_104 ) ;
} else {
V_105 = 0 ;
}
for ( V_94 = 0 ; V_94 < V_49 -> V_107 ; V_94 ++ ) {
if ( ! ( strcmp ( V_101 , V_49 -> V_108 [ V_94 ] ) ) ) {
V_81 -> V_17 = V_49 -> V_108 [ V_94 ] ;
if ( V_94 == V_105 )
V_81 -> V_30 = 1 ;
else
V_81 -> V_30 = 0 ;
return 0 ;
}
}
return - V_109 ;
}
static void F_71 ( struct V_23 * V_24 , int V_94 ,
int V_110 )
{
struct V_46 * V_47 = (struct V_46 * )
V_24 -> V_34 -> V_103 [ V_94 ] . V_57 ;
unsigned int V_61 = V_47 -> V_61 ;
unsigned int V_64 = V_47 -> V_64 ;
unsigned int V_63 = V_47 -> V_63 ;
unsigned int V_62 = ( 1 << F_34 ( V_63 ) ) - 1 ;
unsigned int V_65 = V_47 -> V_65 ;
unsigned int V_104 ;
if ( V_61 != V_106 ) {
F_54 ( V_24 -> V_34 -> V_2 , V_61 , & V_104 ) ;
if ( F_31 ( V_47 ) && V_110 > 0 ) {
if ( V_61 != V_47 -> V_111 )
F_54 ( V_24 -> V_34 -> V_2 , V_47 -> V_111 , & V_104 ) ;
V_104 = ( V_104 >> V_47 -> V_112 ) & V_62 ;
} else {
V_104 = ( V_104 >> V_64 ) & V_62 ;
}
if ( V_65 )
V_104 = V_63 - V_104 ;
V_24 -> V_30 = ! ! V_104 ;
} else {
V_24 -> V_30 = 0 ;
}
}
static int F_72 ( struct V_1 * V_2 ,
struct V_23 * V_81 , const char * V_101 )
{
int V_94 , V_110 = 0 ;
for ( V_94 = 0 ; V_94 < V_81 -> V_34 -> V_113 ; V_94 ++ ) {
if ( ! strcmp ( V_101 , V_81 -> V_34 -> V_103 [ V_94 ] . V_17 ) ) {
V_81 -> V_17 = V_81 -> V_34 -> V_103 [ V_94 ] . V_17 ;
F_71 ( V_81 , V_94 , V_110 ++ ) ;
return 0 ;
}
}
return - V_109 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_13 * V_114 ,
const struct V_102 * V_115 ,
struct V_41 * * V_42 )
{
struct V_13 * V_14 ;
int V_94 ;
* V_42 = NULL ;
F_18 (w, &dapm->card->widgets, list) {
if ( V_14 == V_114 || V_14 -> V_2 != V_114 -> V_2 )
continue;
for ( V_94 = 0 ; V_94 < V_14 -> V_113 ; V_94 ++ ) {
if ( & V_14 -> V_103 [ V_94 ] == V_115 ) {
if ( V_14 -> V_116 )
* V_42 = V_14 -> V_116 [ V_94 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_74 ( struct V_13 * V_14 ,
int V_117 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_118 * V_3 = V_2 -> V_3 -> V_118 ;
const char * V_119 ;
T_4 V_120 ;
int V_121 ;
struct V_41 * V_42 ;
bool V_122 , V_123 ;
char * V_124 = NULL ;
const char * V_17 ;
int V_50 = 0 ;
V_119 = F_53 ( V_2 ) ;
if ( V_119 )
V_120 = strlen ( V_119 ) + 1 ;
else
V_120 = 0 ;
V_121 = F_73 ( V_2 , V_14 , & V_14 -> V_103 [ V_117 ] ,
& V_42 ) ;
if ( ! V_42 ) {
if ( V_121 ) {
V_122 = false ;
V_123 = true ;
} else {
switch ( V_14 -> V_53 ) {
case V_54 :
case V_55 :
case V_125 :
case V_126 :
V_122 = true ;
V_123 = true ;
break;
case V_56 :
V_122 = false ;
V_123 = true ;
break;
case V_70 :
case V_71 :
V_122 = true ;
V_123 = false ;
break;
default:
return - V_127 ;
}
}
if ( V_122 && V_123 ) {
V_124 = F_33 ( V_12 , L_5 ,
V_14 -> V_17 + V_120 ,
V_14 -> V_103 [ V_117 ] . V_17 ) ;
if ( V_124 == NULL )
return - V_51 ;
V_17 = V_124 ;
} else if ( V_122 ) {
V_124 = NULL ;
V_17 = V_14 -> V_17 + V_120 ;
} else {
V_124 = NULL ;
V_17 = V_14 -> V_103 [ V_117 ] . V_17 ;
}
V_42 = F_75 ( & V_14 -> V_103 [ V_117 ] , NULL , V_17 ,
V_119 ) ;
if ( ! V_42 ) {
V_50 = - V_51 ;
goto V_128;
}
V_42 -> V_129 = F_40 ;
V_50 = F_28 ( V_14 , V_42 , V_17 ) ;
if ( V_50 ) {
F_76 ( V_42 ) ;
goto V_128;
}
V_50 = F_77 ( V_3 , V_42 ) ;
if ( V_50 < 0 ) {
F_78 ( V_2 -> V_8 ,
L_7 ,
V_14 -> V_17 , V_17 , V_50 ) ;
goto V_128;
}
}
V_50 = F_43 ( V_42 , V_14 ) ;
if ( V_50 == 0 )
V_14 -> V_116 [ V_117 ] = V_42 ;
V_128:
F_9 ( V_124 ) ;
return V_50 ;
}
static int F_79 ( struct V_13 * V_14 )
{
int V_94 , V_50 ;
struct V_23 * V_81 ;
struct V_44 * V_45 ;
for ( V_94 = 0 ; V_94 < V_14 -> V_113 ; V_94 ++ ) {
F_80 (w, path) {
if ( V_81 -> V_17 != ( char * ) V_14 -> V_103 [ V_94 ] . V_17 )
continue;
if ( ! V_14 -> V_116 [ V_94 ] ) {
V_50 = F_74 ( V_14 , V_94 ) ;
if ( V_50 < 0 )
return V_50 ;
}
F_45 ( V_14 -> V_116 [ V_94 ] , V_81 ) ;
V_45 = F_41 ( V_14 -> V_116 [ V_94 ] ) ;
if ( V_45 -> V_40 )
F_39 ( V_45 -> V_40 -> V_2 ,
V_45 -> V_40 ,
V_81 -> V_33 ,
NULL , NULL ) ;
}
}
return 0 ;
}
static int F_81 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
enum V_19 V_20 ;
struct V_23 * V_81 ;
const char * type ;
int V_50 ;
switch ( V_14 -> V_53 ) {
case V_71 :
V_20 = V_32 ;
type = L_8 ;
break;
case V_70 :
V_20 = V_31 ;
type = L_9 ;
break;
default:
return - V_127 ;
}
if ( V_14 -> V_113 != 1 ) {
F_78 ( V_2 -> V_8 ,
L_10 , type ,
V_14 -> V_17 ) ;
return - V_127 ;
}
if ( F_11 ( & V_14 -> V_130 [ V_20 ] ) ) {
F_78 ( V_2 -> V_8 , L_11 , type , V_14 -> V_17 ) ;
return - V_127 ;
}
V_50 = F_74 ( V_14 , 0 ) ;
if ( V_50 < 0 )
return V_50 ;
F_19 (w, dir, path) {
if ( V_81 -> V_17 )
F_45 ( V_14 -> V_116 [ 0 ] , V_81 ) ;
}
return 0 ;
}
static int F_82 ( struct V_13 * V_14 )
{
int V_94 , V_50 ;
for ( V_94 = 0 ; V_94 < V_14 -> V_113 ; V_94 ++ ) {
V_50 = F_74 ( V_14 , V_94 ) ;
if ( V_50 < 0 )
return V_50 ;
}
return 0 ;
}
static int F_83 ( struct V_13 * V_14 )
{
int V_94 , V_50 ;
struct V_41 * V_42 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_118 * V_3 = V_2 -> V_3 -> V_118 ;
if ( V_14 -> V_131 <= 1 )
return 0 ;
for ( V_94 = 0 ; V_94 < V_14 -> V_113 ; V_94 ++ ) {
V_42 = F_75 ( & V_14 -> V_103 [ V_94 ] , V_14 ,
V_14 -> V_17 , NULL ) ;
V_50 = F_77 ( V_3 , V_42 ) ;
if ( V_50 < 0 ) {
F_78 ( V_2 -> V_8 ,
L_7 ,
V_14 -> V_17 , V_14 -> V_103 [ V_94 ] . V_17 , V_50 ) ;
return V_50 ;
}
V_42 -> V_73 = V_14 ;
V_14 -> V_116 [ V_94 ] = V_42 ;
}
return 0 ;
}
static int F_84 ( struct V_13 * V_40 )
{
int V_96 = F_85 ( V_40 -> V_2 -> V_3 -> V_118 ) ;
switch ( V_96 ) {
case V_132 :
case V_133 :
if ( V_40 -> V_134 )
F_86 ( V_40 -> V_2 -> V_8 , L_12 ,
V_40 -> V_17 ) ;
return V_40 -> V_134 ;
default:
return 1 ;
}
}
static int F_87 ( struct V_76 * * V_25 ,
struct V_84 * V_80 )
{
struct V_13 * V_14 ;
struct V_84 * V_135 ;
unsigned int V_136 = 0 ;
unsigned int V_94 = 0 ;
F_88 (it, widgets)
V_136 ++ ;
* V_25 = F_29 ( sizeof( * * V_25 ) + V_136 * sizeof( * V_14 ) , V_12 ) ;
if ( * V_25 == NULL )
return - V_51 ;
F_18 ( V_14 , V_80 , V_27 )
( * V_25 ) -> V_80 [ V_94 ++ ] = V_14 ;
( * V_25 ) -> V_79 = V_94 ;
return 0 ;
}
static T_3 int F_89 ( struct V_13 * V_40 ,
struct V_84 * V_25 , enum V_19 V_20 ,
int (* F_90)( struct V_13 * , struct V_84 * ,
bool (* F_91)( struct V_13 * ,
enum V_19 ) ) ,
bool (* F_91)( struct V_13 * ,
enum V_19 ) )
{
enum V_19 V_21 = F_16 ( V_20 ) ;
struct V_23 * V_81 ;
int V_137 = 0 ;
if ( V_40 -> V_26 [ V_20 ] >= 0 )
return V_40 -> V_26 [ V_20 ] ;
F_92 ( V_40 , V_138 ) ;
if ( V_25 )
F_14 ( & V_40 -> V_27 , V_25 ) ;
if ( F_91 && F_91 ( V_40 , V_20 ) ) {
V_40 -> V_26 [ V_20 ] = 1 ;
return V_40 -> V_26 [ V_20 ] ;
}
if ( ( V_40 -> V_36 & F_93 ( V_20 ) ) && V_40 -> V_139 ) {
V_40 -> V_26 [ V_20 ] = F_84 ( V_40 ) ;
return V_40 -> V_26 [ V_20 ] ;
}
F_19 (widget, rdir, path) {
F_92 ( V_40 , V_140 ) ;
if ( V_81 -> V_29 || V_81 -> V_28 )
continue;
if ( V_81 -> V_141 )
return 1 ;
F_94 ( V_40 , V_20 , V_81 ) ;
if ( V_81 -> V_30 ) {
V_81 -> V_141 = 1 ;
V_137 += F_90 ( V_81 -> V_22 [ V_20 ] , V_25 , F_91 ) ;
V_81 -> V_141 = 0 ;
}
}
V_40 -> V_26 [ V_20 ] = V_137 ;
return V_137 ;
}
static int F_95 ( struct V_13 * V_40 ,
struct V_84 * V_25 ,
bool (* F_91)( struct V_13 * V_94 ,
enum V_19 ) )
{
return F_89 ( V_40 , V_25 , V_32 ,
F_95 , F_91 ) ;
}
static int F_96 ( struct V_13 * V_40 ,
struct V_84 * V_25 ,
bool (* F_91)( struct V_13 * V_94 ,
enum V_19 ) )
{
return F_89 ( V_40 , V_25 , V_31 ,
F_96 , F_91 ) ;
}
int F_97 ( struct V_142 * V_143 , int V_144 ,
struct V_76 * * V_25 ,
bool (* F_91)( struct V_13 * ,
enum V_19 ) )
{
struct V_35 * V_3 = V_143 -> V_88 -> V_3 ;
struct V_13 * V_14 ;
F_17 ( V_80 ) ;
int V_52 ;
int V_50 ;
F_98 ( & V_3 -> V_5 , V_145 ) ;
F_18 (w, &card->widgets, list) {
V_14 -> V_26 [ V_31 ] = - 1 ;
V_14 -> V_26 [ V_32 ] = - 1 ;
}
if ( V_144 == V_146 )
V_52 = F_95 ( V_143 -> V_147 , & V_80 ,
F_91 ) ;
else
V_52 = F_96 ( V_143 -> V_148 , & V_80 ,
F_91 ) ;
F_99 ( V_80 . V_149 ) ;
V_50 = F_87 ( V_25 , & V_80 ) ;
if ( V_50 )
V_52 = V_50 ;
F_100 ( V_52 , V_144 ) ;
F_25 ( & V_3 -> V_5 ) ;
return V_52 ;
}
int F_101 ( struct V_13 * V_14 ,
struct V_41 * V_42 , int V_150 )
{
int V_50 ;
F_60 ( V_14 -> V_2 ) ;
if ( F_102 ( V_150 ) ) {
if ( V_14 -> V_67 & V_151 ) {
V_50 = F_103 ( V_14 -> V_152 , false ) ;
if ( V_50 != 0 )
F_32 ( V_14 -> V_2 -> V_8 ,
L_13 ,
V_14 -> V_17 , V_50 ) ;
}
return F_104 ( V_14 -> V_152 ) ;
} else {
if ( V_14 -> V_67 & V_151 ) {
V_50 = F_103 ( V_14 -> V_152 , true ) ;
if ( V_50 != 0 )
F_32 ( V_14 -> V_2 -> V_8 ,
L_14 ,
V_14 -> V_17 , V_50 ) ;
}
return F_105 ( V_14 -> V_152 , V_14 -> V_64 ) ;
}
}
int F_106 ( struct V_13 * V_14 ,
struct V_41 * V_42 , int V_150 )
{
if ( ! V_14 -> V_153 )
return - V_90 ;
F_60 ( V_14 -> V_2 ) ;
#ifdef F_107
if ( F_102 ( V_150 ) ) {
return F_108 ( V_14 -> V_153 ) ;
} else {
F_109 ( V_14 -> V_153 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_110 ( struct V_13 * V_14 )
{
if ( V_14 -> V_87 )
return V_14 -> V_86 ;
if ( V_14 -> V_154 )
V_14 -> V_86 = 1 ;
else
V_14 -> V_86 = V_14 -> V_155 ( V_14 ) ;
V_14 -> V_87 = true ;
return V_14 -> V_86 ;
}
static int F_111 ( struct V_13 * V_14 )
{
int V_156 , V_99 ;
F_92 ( V_14 , V_157 ) ;
V_156 = F_96 ( V_14 , NULL , NULL ) ;
V_99 = F_95 ( V_14 , NULL , NULL ) ;
return V_99 != 0 && V_156 != 0 ;
}
static int F_112 ( struct V_13 * V_14 )
{
struct V_23 * V_81 ;
F_92 ( V_14 , V_157 ) ;
F_113 (w, path) {
F_92 ( V_14 , V_140 ) ;
if ( V_81 -> V_29 )
continue;
if ( V_81 -> V_139 &&
! V_81 -> V_139 ( V_81 -> V_33 , V_81 -> V_34 ) )
continue;
if ( F_110 ( V_81 -> V_34 ) )
return 1 ;
}
return 0 ;
}
static int F_114 ( struct V_13 * V_14 )
{
return V_14 -> V_139 ;
}
static int F_115 ( struct V_13 * V_158 ,
struct V_13 * V_159 ,
bool V_160 )
{
int * V_161 ;
if ( V_160 )
V_161 = V_162 ;
else
V_161 = V_163 ;
if ( V_161 [ V_158 -> V_53 ] != V_161 [ V_159 -> V_53 ] )
return V_161 [ V_158 -> V_53 ] - V_161 [ V_159 -> V_53 ] ;
if ( V_158 -> V_164 != V_159 -> V_164 ) {
if ( V_160 )
return V_158 -> V_164 - V_159 -> V_164 ;
else
return V_159 -> V_164 - V_158 -> V_164 ;
}
if ( V_158 -> V_61 != V_159 -> V_61 )
return V_158 -> V_61 - V_159 -> V_61 ;
if ( V_158 -> V_2 != V_159 -> V_2 )
return ( unsigned long ) V_158 -> V_2 - ( unsigned long ) V_159 -> V_2 ;
return 0 ;
}
static void F_116 ( struct V_13 * V_165 ,
struct V_84 * V_25 ,
bool V_160 )
{
struct V_13 * V_14 ;
F_18 (w, list, power_list)
if ( F_115 ( V_165 , V_14 , V_160 ) < 0 ) {
F_14 ( & V_165 -> V_166 , & V_14 -> V_166 ) ;
return;
}
F_14 ( & V_165 -> V_166 , V_25 ) ;
}
static void F_117 ( struct V_35 * V_3 ,
struct V_13 * V_14 , int V_150 )
{
const char * V_167 ;
int V_83 , V_50 ;
switch ( V_150 ) {
case V_168 :
V_167 = L_15 ;
V_83 = 1 ;
break;
case V_169 :
V_167 = L_16 ;
V_83 = 1 ;
break;
case V_170 :
V_167 = L_17 ;
V_83 = 0 ;
break;
case V_171 :
V_167 = L_18 ;
V_83 = 0 ;
break;
case V_172 :
V_167 = L_19 ;
V_83 = 1 ;
break;
case V_173 :
V_167 = L_20 ;
V_83 = 0 ;
break;
default:
F_118 ( 1 , L_21 , V_150 ) ;
return;
}
if ( V_14 -> V_86 != V_83 )
return;
if ( V_14 -> V_150 && ( V_14 -> V_174 & V_150 ) ) {
F_6 ( V_14 -> V_2 -> V_8 , V_3 -> V_6 , L_22 ,
V_14 -> V_17 , V_167 ) ;
F_60 ( V_14 -> V_2 ) ;
F_119 ( V_14 , V_150 ) ;
V_50 = V_14 -> V_150 ( V_14 , NULL , V_150 ) ;
F_120 ( V_14 , V_150 ) ;
if ( V_50 < 0 )
F_78 ( V_14 -> V_2 -> V_8 , L_23 ,
V_167 , V_14 -> V_17 , V_50 ) ;
}
}
static void F_121 ( struct V_35 * V_3 ,
struct V_84 * V_175 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
int V_61 ;
unsigned int V_69 = 0 ;
unsigned int V_62 = 0 ;
V_14 = F_122 ( V_175 , struct V_13 , V_166 ) ;
V_61 = V_14 -> V_61 ;
V_2 = V_14 -> V_2 ;
F_18 (w, pending, power_list) {
F_123 ( V_61 != V_14 -> V_61 || V_2 != V_14 -> V_2 ) ;
V_14 -> V_83 = V_14 -> V_86 ;
V_62 |= V_14 -> V_62 << V_14 -> V_64 ;
if ( V_14 -> V_83 )
V_69 |= V_14 -> V_67 << V_14 -> V_64 ;
else
V_69 |= V_14 -> V_66 << V_14 -> V_64 ;
F_6 ( V_2 -> V_8 , V_3 -> V_6 ,
L_24 ,
V_14 -> V_17 , V_61 , V_69 , V_62 ) ;
F_117 ( V_3 , V_14 , V_168 ) ;
F_117 ( V_3 , V_14 , V_170 ) ;
}
if ( V_61 >= 0 ) {
F_6 ( V_2 -> V_8 , V_3 -> V_6 ,
L_25 ,
V_69 , V_62 , V_61 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_56 ( V_2 , V_61 , V_62 , V_69 ) ;
}
F_18 (w, pending, power_list) {
F_117 ( V_3 , V_14 , V_169 ) ;
F_117 ( V_3 , V_14 , V_171 ) ;
}
}
static void F_124 ( struct V_35 * V_3 ,
struct V_84 * V_25 , int V_150 , bool V_160 )
{
struct V_13 * V_14 , * V_78 ;
struct V_1 * V_176 ;
F_17 ( V_175 ) ;
int V_177 = - 1 ;
int V_178 = - 1 ;
int V_179 = V_106 ;
struct V_1 * V_180 = NULL ;
int V_50 , V_94 ;
int * V_161 ;
if ( V_160 )
V_161 = V_162 ;
else
V_161 = V_163 ;
F_125 (w, n, list, power_list) {
V_50 = 0 ;
if ( V_161 [ V_14 -> V_53 ] != V_177 || V_14 -> V_61 != V_179 ||
V_14 -> V_2 != V_180 || V_14 -> V_164 != V_178 ) {
if ( ! F_11 ( & V_175 ) )
F_121 ( V_3 , & V_175 ) ;
if ( V_180 && V_180 -> V_181 ) {
for ( V_94 = 0 ; V_94 < F_126 ( V_162 ) ; V_94 ++ )
if ( V_161 [ V_94 ] == V_177 )
V_180 -> V_181 ( V_180 ,
V_94 ,
V_178 ) ;
}
if ( V_180 && V_14 -> V_2 != V_180 )
F_60 ( V_180 ) ;
F_30 ( & V_175 ) ;
V_177 = - 1 ;
V_178 = V_182 ;
V_179 = V_106 ;
V_180 = NULL ;
}
switch ( V_14 -> V_53 ) {
case V_183 :
if ( ! V_14 -> V_150 )
F_127 ( V_14 , V_78 , V_25 ,
V_166 ) ;
if ( V_150 == V_184 )
V_50 = V_14 -> V_150 ( V_14 ,
NULL , V_168 ) ;
else if ( V_150 == V_185 )
V_50 = V_14 -> V_150 ( V_14 ,
NULL , V_170 ) ;
break;
case V_186 :
if ( ! V_14 -> V_150 )
F_127 ( V_14 , V_78 , V_25 ,
V_166 ) ;
if ( V_150 == V_184 )
V_50 = V_14 -> V_150 ( V_14 ,
NULL , V_169 ) ;
else if ( V_150 == V_185 )
V_50 = V_14 -> V_150 ( V_14 ,
NULL , V_171 ) ;
break;
default:
V_177 = V_161 [ V_14 -> V_53 ] ;
V_178 = V_14 -> V_164 ;
V_179 = V_14 -> V_61 ;
V_180 = V_14 -> V_2 ;
F_128 ( & V_14 -> V_166 , & V_175 ) ;
break;
}
if ( V_50 < 0 )
F_78 ( V_14 -> V_2 -> V_8 ,
L_26 , V_50 ) ;
}
if ( ! F_11 ( & V_175 ) )
F_121 ( V_3 , & V_175 ) ;
if ( V_180 && V_180 -> V_181 ) {
for ( V_94 = 0 ; V_94 < F_126 ( V_162 ) ; V_94 ++ )
if ( V_161 [ V_94 ] == V_177 )
V_180 -> V_181 ( V_180 ,
V_94 , V_178 ) ;
}
F_18 (d, &card->dapm_list, list) {
F_60 ( V_176 ) ;
}
}
static void F_129 ( struct V_35 * V_3 )
{
struct V_187 * V_188 = V_3 -> V_188 ;
struct V_76 * V_75 ;
struct V_13 * V_14 = NULL ;
unsigned int V_189 ;
int V_50 ;
if ( ! V_188 || ! F_46 ( V_188 -> V_42 ) )
return;
V_75 = F_42 ( V_188 -> V_42 ) ;
for ( V_189 = 0 ; V_189 < V_75 -> V_79 ; V_189 ++ ) {
V_14 = V_75 -> V_80 [ V_189 ] ;
if ( V_14 -> V_150 && ( V_14 -> V_174 & V_190 ) ) {
V_50 = V_14 -> V_150 ( V_14 , V_188 -> V_42 , V_190 ) ;
if ( V_50 != 0 )
F_78 ( V_14 -> V_2 -> V_8 , L_27 ,
V_14 -> V_17 , V_50 ) ;
}
}
if ( ! V_14 )
return;
V_50 = F_56 ( V_14 -> V_2 , V_188 -> V_61 , V_188 -> V_62 ,
V_188 -> V_104 ) ;
if ( V_50 < 0 )
F_78 ( V_14 -> V_2 -> V_8 , L_28 ,
V_14 -> V_17 , V_50 ) ;
if ( V_188 -> V_191 ) {
V_50 = F_56 ( V_14 -> V_2 , V_188 -> V_192 ,
V_188 -> V_193 , V_188 -> V_194 ) ;
if ( V_50 < 0 )
F_78 ( V_14 -> V_2 -> V_8 ,
L_28 ,
V_14 -> V_17 , V_50 ) ;
}
for ( V_189 = 0 ; V_189 < V_75 -> V_79 ; V_189 ++ ) {
V_14 = V_75 -> V_80 [ V_189 ] ;
if ( V_14 -> V_150 && ( V_14 -> V_174 & V_195 ) ) {
V_50 = V_14 -> V_150 ( V_14 , V_188 -> V_42 , V_195 ) ;
if ( V_50 != 0 )
F_78 ( V_14 -> V_2 -> V_8 , L_29 ,
V_14 -> V_17 , V_50 ) ;
}
}
}
static void F_130 ( void * V_45 , T_5 V_196 )
{
struct V_1 * V_176 = V_45 ;
int V_50 ;
if ( V_176 -> V_98 == V_197 &&
V_176 -> V_198 != V_197 ) {
if ( V_176 -> V_8 )
F_131 ( V_176 -> V_8 ) ;
V_50 = F_66 ( V_176 , V_199 ) ;
if ( V_50 != 0 )
F_78 ( V_176 -> V_8 ,
L_30 , V_50 ) ;
}
if ( ( V_176 -> V_198 == V_200 &&
V_176 -> V_98 != V_200 ) ||
( V_176 -> V_198 != V_200 &&
V_176 -> V_98 == V_200 ) ) {
V_50 = F_66 ( V_176 , V_201 ) ;
if ( V_50 != 0 )
F_78 ( V_176 -> V_8 ,
L_31 , V_50 ) ;
}
}
static void F_132 ( void * V_45 , T_5 V_196 )
{
struct V_1 * V_176 = V_45 ;
int V_50 ;
if ( V_176 -> V_98 == V_201 &&
( V_176 -> V_198 == V_199 ||
V_176 -> V_198 == V_197 ) ) {
V_50 = F_66 ( V_176 , V_199 ) ;
if ( V_50 != 0 )
F_78 ( V_176 -> V_8 , L_32 ,
V_50 ) ;
}
if ( V_176 -> V_98 == V_199 &&
V_176 -> V_198 == V_197 ) {
V_50 = F_66 ( V_176 , V_197 ) ;
if ( V_50 != 0 )
F_78 ( V_176 -> V_8 , L_33 ,
V_50 ) ;
if ( V_176 -> V_8 )
F_133 ( V_176 -> V_8 ) ;
}
if ( V_176 -> V_98 == V_201 &&
V_176 -> V_198 == V_200 ) {
V_50 = F_66 ( V_176 , V_200 ) ;
if ( V_50 != 0 )
F_78 ( V_176 -> V_8 , L_34 ,
V_50 ) ;
}
}
static void F_134 ( struct V_13 * V_202 ,
bool V_83 , bool V_30 )
{
if ( ! V_30 )
return;
if ( V_83 != V_202 -> V_83 )
F_12 ( V_202 , L_35 ) ;
}
static void F_135 ( struct V_13 * V_14 , bool V_83 ,
struct V_84 * V_203 ,
struct V_84 * V_204 )
{
struct V_23 * V_81 ;
if ( V_14 -> V_83 == V_83 )
return;
F_136 ( V_14 , V_83 ) ;
F_80 (w, path)
F_134 ( V_81 -> V_33 , V_83 , V_81 -> V_30 ) ;
if ( ! V_14 -> V_28 ) {
F_113 (w, path)
F_134 ( V_81 -> V_34 , V_83 ,
V_81 -> V_30 ) ;
}
if ( V_83 )
F_116 ( V_14 , V_203 , true ) ;
else
F_116 ( V_14 , V_204 , false ) ;
}
static void F_137 ( struct V_13 * V_14 ,
struct V_84 * V_203 ,
struct V_84 * V_204 )
{
int V_83 ;
switch ( V_14 -> V_53 ) {
case V_183 :
F_116 ( V_14 , V_204 , false ) ;
break;
case V_186 :
F_116 ( V_14 , V_203 , true ) ;
break;
default:
V_83 = F_110 ( V_14 ) ;
F_135 ( V_14 , V_83 , V_203 , V_204 ) ;
break;
}
}
static bool F_138 ( struct V_1 * V_2 )
{
if ( V_2 -> V_205 )
return true ;
switch ( F_85 ( V_2 -> V_3 -> V_118 ) ) {
case V_132 :
case V_133 :
return V_2 -> V_206 ;
default:
break;
}
return false ;
}
static int F_139 ( struct V_35 * V_3 , int V_150 )
{
struct V_13 * V_14 ;
struct V_1 * V_176 ;
F_17 ( V_203 ) ;
F_17 ( V_204 ) ;
F_140 ( V_207 ) ;
enum V_95 V_208 ;
F_2 ( & V_3 -> V_5 ) ;
F_141 ( V_3 ) ;
F_18 (d, &card->dapm_list, list) {
if ( F_138 ( V_176 ) )
V_176 -> V_198 = V_197 ;
else
V_176 -> V_198 = V_199 ;
}
F_52 ( V_3 ) ;
F_18 (w, &card->dapm_dirty, dirty) {
F_137 ( V_14 , & V_203 , & V_204 ) ;
}
F_18 (w, &card->widgets, list) {
switch ( V_14 -> V_53 ) {
case V_183 :
case V_186 :
break;
default:
F_142 ( & V_14 -> V_15 ) ;
break;
}
if ( V_14 -> V_86 ) {
V_176 = V_14 -> V_2 ;
switch ( V_14 -> V_53 ) {
case V_209 :
case V_210 :
break;
case V_211 :
case V_212 :
case V_213 :
case V_214 :
if ( V_176 -> V_198 < V_199 )
V_176 -> V_198 = V_199 ;
break;
default:
V_176 -> V_198 = V_200 ;
break;
}
}
}
V_208 = V_197 ;
F_18 (d, &card->dapm_list, list)
if ( V_176 -> V_198 > V_208 )
V_208 = V_176 -> V_198 ;
F_18 (d, &card->dapm_list, list)
if ( ! F_138 ( V_176 ) )
V_176 -> V_198 = V_208 ;
F_143 ( V_3 ) ;
F_130 ( & V_3 -> V_2 , 0 ) ;
F_18 (d, &card->dapm_list, list) {
if ( V_176 != & V_3 -> V_2 )
F_144 ( F_130 , V_176 ,
& V_207 ) ;
}
F_145 ( & V_207 ) ;
F_18 (w, &down_list, power_list) {
F_117 ( V_3 , V_14 , V_173 ) ;
}
F_18 (w, &up_list, power_list) {
F_117 ( V_3 , V_14 , V_172 ) ;
}
F_124 ( V_3 , & V_204 , V_150 , false ) ;
F_129 ( V_3 ) ;
F_124 ( V_3 , & V_203 , V_150 , true ) ;
F_18 (d, &card->dapm_list, list) {
if ( V_176 != & V_3 -> V_2 )
F_144 ( F_132 , V_176 ,
& V_207 ) ;
}
F_145 ( & V_207 ) ;
F_132 ( & V_3 -> V_2 , 0 ) ;
F_18 (d, &card->dapm_list, list) {
if ( V_176 -> V_215 )
V_176 -> V_215 ( V_176 , V_150 ) ;
}
F_6 ( V_3 -> V_8 , V_3 -> V_6 ,
L_36 , V_3 -> V_6 ) ;
F_3 ( V_3 -> V_6 ) ;
F_146 ( V_3 ) ;
return 0 ;
}
static T_6 F_147 ( struct V_216 * V_216 ,
char T_7 * V_217 ,
T_4 V_218 , T_8 * V_219 )
{
struct V_13 * V_14 = V_216 -> V_73 ;
struct V_35 * V_3 = V_14 -> V_2 -> V_3 ;
enum V_19 V_20 , V_21 ;
char * V_10 ;
int V_156 , V_99 ;
T_6 V_50 ;
struct V_23 * V_24 = NULL ;
V_10 = F_7 ( V_11 , V_12 ) ;
if ( ! V_10 )
return - V_51 ;
F_24 ( & V_3 -> V_5 ) ;
if ( V_14 -> V_28 ) {
V_156 = 0 ;
V_99 = 0 ;
} else {
V_156 = F_96 ( V_14 , NULL , NULL ) ;
V_99 = F_95 ( V_14 , NULL , NULL ) ;
}
V_50 = snprintf ( V_10 , V_11 , L_37 ,
V_14 -> V_17 , V_14 -> V_83 ? L_38 : L_39 ,
V_14 -> V_154 ? L_40 : L_41 , V_156 , V_99 ) ;
if ( V_14 -> V_61 >= 0 )
V_50 += snprintf ( V_10 + V_50 , V_11 - V_50 ,
L_42 ,
V_14 -> V_61 , V_14 -> V_61 , V_14 -> V_62 << V_14 -> V_64 ) ;
V_50 += snprintf ( V_10 + V_50 , V_11 - V_50 , L_43 ) ;
if ( V_14 -> V_220 )
V_50 += snprintf ( V_10 + V_50 , V_11 - V_50 , L_44 ,
V_14 -> V_220 ,
V_14 -> V_221 ? L_45 : L_46 ) ;
F_148 (dir) {
V_21 = F_16 ( V_20 ) ;
F_19 (w, dir, p) {
if ( V_24 -> V_139 && ! V_24 -> V_139 ( V_14 , V_24 -> V_22 [ V_21 ] ) )
continue;
if ( ! V_24 -> V_30 )
continue;
V_50 += snprintf ( V_10 + V_50 , V_11 - V_50 ,
L_47 ,
( V_21 == V_31 ) ? L_48 : L_49 ,
V_24 -> V_17 ? V_24 -> V_17 : L_50 ,
V_24 -> V_22 [ V_21 ] -> V_17 ) ;
}
}
F_25 ( & V_3 -> V_5 ) ;
V_50 = F_149 ( V_217 , V_218 , V_219 , V_10 , V_50 ) ;
F_9 ( V_10 ) ;
return V_50 ;
}
static T_6 F_150 ( struct V_216 * V_216 , char T_7 * V_217 ,
T_4 V_218 , T_8 * V_219 )
{
struct V_1 * V_2 = V_216 -> V_73 ;
char * V_96 ;
switch ( V_2 -> V_98 ) {
case V_200 :
V_96 = L_51 ;
break;
case V_201 :
V_96 = L_52 ;
break;
case V_199 :
V_96 = L_53 ;
break;
case V_197 :
V_96 = L_54 ;
break;
default:
F_118 ( 1 , L_55 , V_2 -> V_98 ) ;
V_96 = L_56 ;
break;
}
return F_149 ( V_217 , V_218 , V_219 , V_96 ,
strlen ( V_96 ) ) ;
}
void F_151 ( struct V_1 * V_2 ,
struct V_222 * V_223 )
{
struct V_222 * V_176 ;
if ( ! V_223 )
return;
V_2 -> V_224 = F_152 ( L_57 , V_223 ) ;
if ( ! V_2 -> V_224 ) {
F_32 ( V_2 -> V_8 ,
L_58 ) ;
return;
}
V_176 = F_153 ( L_59 , 0444 ,
V_2 -> V_224 , V_2 ,
& V_225 ) ;
if ( ! V_176 )
F_32 ( V_2 -> V_8 ,
L_60 ) ;
}
static void F_154 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_222 * V_176 ;
if ( ! V_2 -> V_224 || ! V_14 -> V_17 )
return;
V_176 = F_153 ( V_14 -> V_17 , 0444 ,
V_2 -> V_224 , V_14 ,
& V_226 ) ;
if ( ! V_176 )
F_32 ( V_14 -> V_2 -> V_8 ,
L_61 ,
V_14 -> V_17 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
F_156 ( V_2 -> V_224 ) ;
}
void F_151 ( struct V_1 * V_2 ,
struct V_222 * V_223 )
{
}
static inline void F_154 ( struct V_13 * V_14 )
{
}
static inline void F_155 ( struct V_1 * V_2 )
{
}
static void F_157 ( struct V_23 * V_81 ,
bool V_30 , const char * V_16 )
{
if ( V_81 -> V_30 == V_30 )
return;
V_81 -> V_30 = V_30 ;
F_12 ( V_81 -> V_33 , V_16 ) ;
F_12 ( V_81 -> V_34 , V_16 ) ;
F_22 ( V_81 ) ;
}
static int F_158 ( struct V_35 * V_3 ,
struct V_41 * V_42 , int V_227 , struct V_48 * V_49 )
{
struct V_23 * V_81 ;
int V_228 = 0 ;
bool V_30 ;
F_2 ( & V_3 -> V_5 ) ;
F_159 (path, kcontrol) {
V_228 = 1 ;
if ( ! ( strcmp ( V_81 -> V_17 , V_49 -> V_108 [ V_227 ] ) ) )
V_30 = true ;
else
V_30 = false ;
F_157 ( V_81 , V_30 , L_62 ) ;
}
if ( V_228 )
F_139 ( V_3 , V_229 ) ;
return V_228 ;
}
int F_160 ( struct V_1 * V_2 ,
struct V_41 * V_42 , int V_227 , struct V_48 * V_49 ,
struct V_187 * V_188 )
{
struct V_35 * V_3 = V_2 -> V_3 ;
int V_50 ;
F_98 ( & V_3 -> V_5 , V_145 ) ;
V_3 -> V_188 = V_188 ;
V_50 = F_158 ( V_3 , V_42 , V_227 , V_49 ) ;
V_3 -> V_188 = NULL ;
F_25 ( & V_3 -> V_5 ) ;
if ( V_50 > 0 )
F_161 ( V_3 ) ;
return V_50 ;
}
static int F_162 ( struct V_35 * V_3 ,
struct V_41 * V_42 ,
int V_30 , int V_230 )
{
struct V_23 * V_81 ;
int V_228 = 0 ;
F_2 ( & V_3 -> V_5 ) ;
F_159 (path, kcontrol) {
if ( V_228 && V_230 >= 0 )
F_157 ( V_81 , V_230 , L_63 ) ;
else
F_157 ( V_81 , V_30 , L_63 ) ;
V_228 = 1 ;
}
if ( V_228 )
F_139 ( V_3 , V_229 ) ;
return V_228 ;
}
int F_163 ( struct V_1 * V_2 ,
struct V_41 * V_42 , int V_30 ,
struct V_187 * V_188 )
{
struct V_35 * V_3 = V_2 -> V_3 ;
int V_50 ;
F_98 ( & V_3 -> V_5 , V_145 ) ;
V_3 -> V_188 = V_188 ;
V_50 = F_162 ( V_3 , V_42 , V_30 , - 1 ) ;
V_3 -> V_188 = NULL ;
F_25 ( & V_3 -> V_5 ) ;
if ( V_50 > 0 )
F_161 ( V_3 ) ;
return V_50 ;
}
static T_6 F_164 ( struct V_231 * V_232 ,
char * V_10 )
{
struct V_1 * V_2 = F_165 ( V_232 ) ;
struct V_13 * V_14 ;
int V_218 = 0 ;
char * V_233 = L_64 ;
if ( ! V_232 -> V_3 )
return 0 ;
F_18 (w, &cmpnt->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
switch ( V_14 -> V_53 ) {
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_214 :
case V_238 :
case V_239 :
case V_125 :
case V_126 :
case V_55 :
case V_56 :
case V_211 :
case V_212 :
case V_213 :
if ( V_14 -> V_17 )
V_218 += sprintf ( V_10 + V_218 , L_65 ,
V_14 -> V_17 , V_14 -> V_83 ? L_38 : L_39 ) ;
break;
default:
break;
}
}
switch ( F_166 ( V_2 ) ) {
case V_200 :
V_233 = L_38 ;
break;
case V_201 :
V_233 = L_66 ;
break;
case V_199 :
V_233 = L_67 ;
break;
case V_197 :
V_233 = L_39 ;
break;
}
V_218 += sprintf ( V_10 + V_218 , L_68 , V_233 ) ;
return V_218 ;
}
static T_6 F_167 ( struct V_7 * V_8 ,
struct V_240 * V_241 , char * V_10 )
{
struct V_242 * V_243 = F_168 ( V_8 ) ;
int V_94 , V_218 = 0 ;
F_24 ( & V_243 -> V_3 -> V_5 ) ;
for ( V_94 = 0 ; V_94 < V_243 -> V_244 ; V_94 ++ ) {
struct V_231 * V_232 = V_243 -> V_245 [ V_94 ] -> V_88 ;
V_218 += F_164 ( V_232 , V_10 + V_218 ) ;
}
F_25 ( & V_243 -> V_3 -> V_5 ) ;
return V_218 ;
}
static void F_169 ( struct V_23 * V_81 )
{
F_99 ( & V_81 -> V_246 [ V_31 ] ) ;
F_99 ( & V_81 -> V_246 [ V_32 ] ) ;
F_99 ( & V_81 -> V_82 ) ;
F_99 ( & V_81 -> V_25 ) ;
F_9 ( V_81 ) ;
}
void F_170 ( struct V_13 * V_14 )
{
struct V_23 * V_24 , * V_247 ;
enum V_19 V_20 ;
F_99 ( & V_14 -> V_25 ) ;
F_148 (dir) {
F_171 (w, dir, p, next_p)
F_169 ( V_24 ) ;
}
F_9 ( V_14 -> V_116 ) ;
F_172 ( V_14 -> V_17 ) ;
F_9 ( V_14 ) ;
}
void F_173 ( struct V_1 * V_2 )
{
V_2 -> V_248 . V_40 = NULL ;
V_2 -> V_249 . V_40 = NULL ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_250 ;
F_125 (w, next_w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
F_170 ( V_14 ) ;
}
F_173 ( V_2 ) ;
}
static struct V_13 * F_175 (
struct V_1 * V_2 , const char * V_251 ,
bool V_252 )
{
struct V_13 * V_14 ;
struct V_13 * V_253 = NULL ;
F_18 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_14 -> V_17 , V_251 ) ) {
if ( V_14 -> V_2 == V_2 )
return V_14 ;
else
V_253 = V_14 ;
}
}
if ( V_252 )
return V_253 ;
return NULL ;
}
static int F_176 ( struct V_1 * V_2 ,
const char * V_251 , int V_254 )
{
struct V_13 * V_14 = F_175 ( V_2 , V_251 , true ) ;
F_1 ( V_2 ) ;
if ( ! V_14 ) {
F_78 ( V_2 -> V_8 , L_69 , V_251 ) ;
return - V_127 ;
}
if ( V_14 -> V_139 != V_254 ) {
F_12 ( V_14 , L_70 ) ;
F_20 ( V_14 ) ;
F_21 ( V_14 ) ;
}
V_14 -> V_139 = V_254 ;
if ( V_254 == 0 )
V_14 -> V_154 = 0 ;
return 0 ;
}
int F_177 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_3 -> V_4 )
return 0 ;
return F_139 ( V_2 -> V_3 , V_229 ) ;
}
int F_178 ( struct V_1 * V_2 )
{
int V_50 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_145 ) ;
V_50 = F_177 ( V_2 ) ;
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return V_50 ;
}
static void F_179 ( struct V_13 * V_14 )
{
enum V_19 V_20 ;
struct V_23 * V_24 ;
unsigned int V_255 ;
switch ( V_14 -> V_53 ) {
case V_256 :
if ( V_14 -> V_2 -> V_3 -> V_257 )
return;
V_255 = V_38 ;
F_80 (w, p) {
if ( V_24 -> V_33 -> V_53 == V_214 ||
V_24 -> V_33 -> V_53 == V_235 ||
V_24 -> V_33 -> V_53 == V_237 ||
V_24 -> V_33 -> V_53 == V_258 ) {
V_255 = 0 ;
break;
}
}
break;
case V_258 :
if ( V_14 -> V_2 -> V_3 -> V_257 )
return;
V_255 = V_37 ;
F_113 (w, p) {
if ( V_24 -> V_34 -> V_53 == V_236 ||
V_24 -> V_34 -> V_53 == V_234 ||
V_24 -> V_34 -> V_53 == V_237 ||
V_24 -> V_34 -> V_53 == V_256 ) {
V_255 = 0 ;
break;
}
}
break;
case V_237 :
V_255 = 0 ;
F_148 (dir) {
if ( ! F_11 ( & V_14 -> V_130 [ V_20 ] ) )
V_255 |= F_93 ( V_20 ) ;
}
break;
default:
return;
}
V_14 -> V_36 = V_255 ;
}
static int F_180 ( struct V_1 * V_2 ,
struct V_13 * V_33 , struct V_13 * V_34 ,
const char * V_259 )
{
bool V_260 = false ;
bool V_261 = false ;
if ( ! V_259 )
return 0 ;
switch ( V_33 -> V_53 ) {
case V_70 :
V_260 = true ;
break;
default:
break;
}
switch ( V_34 -> V_53 ) {
case V_71 :
case V_54 :
case V_55 :
case V_56 :
V_261 = true ;
break;
default:
break;
}
if ( V_260 && V_261 ) {
F_78 ( V_2 -> V_8 ,
L_71 ,
V_33 -> V_17 , V_259 , V_34 -> V_17 ) ;
return - V_127 ;
} else if ( ! V_260 && ! V_261 ) {
F_78 ( V_2 -> V_8 ,
L_72 ,
V_33 -> V_17 , V_259 , V_34 -> V_17 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_13 * V_262 , struct V_13 * V_263 ,
const char * V_259 ,
int (* V_139)( struct V_13 * V_33 ,
struct V_13 * V_34 ) )
{
struct V_13 * V_80 [ 2 ] ;
enum V_19 V_20 ;
struct V_23 * V_81 ;
int V_50 ;
if ( V_263 -> V_28 && ! V_262 -> V_28 ) {
F_78 ( V_2 -> V_8 ,
L_73 ,
V_262 -> V_17 , V_263 -> V_17 ) ;
return - V_127 ;
}
if ( V_139 && ! V_262 -> V_28 ) {
F_78 ( V_2 -> V_8 ,
L_74 ,
V_262 -> V_17 , V_263 -> V_17 ) ;
return - V_127 ;
}
if ( V_262 -> V_28 && V_259 ) {
F_78 ( V_2 -> V_8 ,
L_75 ,
V_262 -> V_17 , V_259 , V_263 -> V_17 ) ;
return - V_127 ;
}
V_50 = F_180 ( V_2 , V_262 , V_263 , V_259 ) ;
if ( V_50 )
return V_50 ;
V_81 = F_29 ( sizeof( struct V_23 ) , V_12 ) ;
if ( ! V_81 )
return - V_51 ;
V_81 -> V_22 [ V_31 ] = V_262 ;
V_81 -> V_22 [ V_32 ] = V_263 ;
V_80 [ V_31 ] = V_262 ;
V_80 [ V_32 ] = V_263 ;
V_81 -> V_139 = V_139 ;
F_30 ( & V_81 -> V_25 ) ;
F_30 ( & V_81 -> V_82 ) ;
if ( V_262 -> V_28 || V_263 -> V_28 )
V_81 -> V_28 = 1 ;
if ( V_259 == NULL ) {
V_81 -> V_30 = 1 ;
} else {
switch ( V_262 -> V_53 ) {
case V_70 :
V_50 = F_69 ( V_2 , V_81 , V_259 , V_262 ) ;
if ( V_50 )
goto V_264;
break;
default:
break;
}
switch ( V_263 -> V_53 ) {
case V_71 :
V_50 = F_69 ( V_2 , V_81 , V_259 , V_263 ) ;
if ( V_50 != 0 )
goto V_264;
break;
case V_54 :
case V_55 :
case V_56 :
V_50 = F_72 ( V_2 , V_81 , V_259 ) ;
if ( V_50 != 0 )
goto V_264;
break;
default:
break;
}
}
F_181 ( & V_81 -> V_25 , & V_2 -> V_3 -> V_52 ) ;
F_148 (dir)
F_181 ( & V_81 -> V_246 [ V_20 ] , & V_80 [ V_20 ] -> V_130 [ V_20 ] ) ;
F_148 (dir) {
F_179 ( V_80 [ V_20 ] ) ;
F_12 ( V_80 [ V_20 ] , L_76 ) ;
}
if ( V_2 -> V_3 -> V_4 && V_81 -> V_30 )
F_22 ( V_81 ) ;
return 0 ;
V_264:
F_9 ( V_81 ) ;
return V_50 ;
}
static int F_182 ( struct V_1 * V_2 ,
const struct V_265 * V_266 )
{
struct V_13 * V_262 = NULL , * V_263 = NULL , * V_14 ;
struct V_13 * V_267 = NULL , * V_268 = NULL ;
const char * V_34 ;
const char * V_33 ;
char V_269 [ 80 ] ;
char V_270 [ 80 ] ;
const char * V_119 ;
int V_50 ;
V_119 = F_53 ( V_2 ) ;
if ( V_119 ) {
snprintf ( V_269 , sizeof( V_269 ) , L_5 ,
V_119 , V_266 -> V_34 ) ;
V_34 = V_269 ;
snprintf ( V_270 , sizeof( V_270 ) , L_5 ,
V_119 , V_266 -> V_33 ) ;
V_33 = V_270 ;
} else {
V_34 = V_266 -> V_34 ;
V_33 = V_266 -> V_33 ;
}
V_262 = F_62 ( & V_2 -> V_249 , V_33 ) ;
V_263 = F_62 ( & V_2 -> V_248 , V_34 ) ;
if ( V_263 && V_262 )
goto V_271;
F_18 (w, &dapm->card->widgets, list) {
if ( ! V_263 && ! ( strcmp ( V_14 -> V_17 , V_34 ) ) ) {
V_268 = V_14 ;
if ( V_14 -> V_2 == V_2 ) {
V_263 = V_14 ;
if ( V_262 )
break;
}
continue;
}
if ( ! V_262 && ! ( strcmp ( V_14 -> V_17 , V_33 ) ) ) {
V_267 = V_14 ;
if ( V_14 -> V_2 == V_2 ) {
V_262 = V_14 ;
if ( V_263 )
break;
}
}
}
if ( ! V_263 )
V_263 = V_268 ;
if ( ! V_262 )
V_262 = V_267 ;
if ( V_262 == NULL ) {
F_78 ( V_2 -> V_8 , L_77 ,
V_266 -> V_33 ) ;
return - V_109 ;
}
if ( V_263 == NULL ) {
F_78 ( V_2 -> V_8 , L_78 ,
V_266 -> V_34 ) ;
return - V_109 ;
}
V_271:
F_64 ( & V_2 -> V_248 , V_263 ) ;
F_64 ( & V_2 -> V_249 , V_262 ) ;
V_50 = F_39 ( V_2 , V_262 , V_263 , V_266 -> V_259 ,
V_266 -> V_139 ) ;
if ( V_50 )
goto V_264;
return 0 ;
V_264:
F_32 ( V_2 -> V_8 , L_79 ,
V_33 , V_266 -> V_259 , V_34 ) ;
return V_50 ;
}
static int F_183 ( struct V_1 * V_2 ,
const struct V_265 * V_266 )
{
struct V_13 * V_262 , * V_263 ;
struct V_23 * V_81 , * V_24 ;
const char * V_34 ;
const char * V_33 ;
char V_269 [ 80 ] ;
char V_270 [ 80 ] ;
const char * V_119 ;
if ( V_266 -> V_259 ) {
F_78 ( V_2 -> V_8 ,
L_80 ) ;
return - V_127 ;
}
V_119 = F_53 ( V_2 ) ;
if ( V_119 ) {
snprintf ( V_269 , sizeof( V_269 ) , L_5 ,
V_119 , V_266 -> V_34 ) ;
V_34 = V_269 ;
snprintf ( V_270 , sizeof( V_270 ) , L_5 ,
V_119 , V_266 -> V_33 ) ;
V_33 = V_270 ;
} else {
V_34 = V_266 -> V_34 ;
V_33 = V_266 -> V_33 ;
}
V_81 = NULL ;
F_18 (p, &dapm->card->paths, list) {
if ( strcmp ( V_24 -> V_33 -> V_17 , V_33 ) != 0 )
continue;
if ( strcmp ( V_24 -> V_34 -> V_17 , V_34 ) != 0 )
continue;
V_81 = V_24 ;
break;
}
if ( V_81 ) {
V_262 = V_81 -> V_33 ;
V_263 = V_81 -> V_34 ;
F_12 ( V_262 , L_81 ) ;
F_12 ( V_263 , L_81 ) ;
if ( V_81 -> V_30 )
F_22 ( V_81 ) ;
F_169 ( V_81 ) ;
F_179 ( V_262 ) ;
F_179 ( V_263 ) ;
} else {
F_32 ( V_2 -> V_8 , L_82 ,
V_33 , V_34 ) ;
}
return 0 ;
}
int F_184 ( struct V_1 * V_2 ,
const struct V_265 * V_266 , int V_272 )
{
int V_94 , V_273 , V_50 = 0 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_274 ) ;
for ( V_94 = 0 ; V_94 < V_272 ; V_94 ++ ) {
V_273 = F_182 ( V_2 , V_266 ) ;
if ( V_273 < 0 ) {
F_78 ( V_2 -> V_8 , L_83 ,
V_266 -> V_33 ,
V_266 -> V_259 ? V_266 -> V_259 : L_84 ,
V_266 -> V_34 ) ;
V_50 = V_273 ;
}
V_266 ++ ;
}
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return V_50 ;
}
int F_185 ( struct V_1 * V_2 ,
const struct V_265 * V_266 , int V_272 )
{
int V_94 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_274 ) ;
for ( V_94 = 0 ; V_94 < V_272 ; V_94 ++ ) {
F_183 ( V_2 , V_266 ) ;
V_266 ++ ;
}
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return 0 ;
}
static int F_186 ( struct V_1 * V_2 ,
const struct V_265 * V_266 )
{
struct V_13 * V_33 = F_175 ( V_2 ,
V_266 -> V_33 ,
true ) ;
struct V_13 * V_34 = F_175 ( V_2 ,
V_266 -> V_34 ,
true ) ;
struct V_23 * V_81 ;
int V_218 = 0 ;
if ( ! V_33 ) {
F_78 ( V_2 -> V_8 , L_85 ,
V_266 -> V_33 ) ;
return - V_109 ;
}
if ( ! V_34 ) {
F_78 ( V_2 -> V_8 , L_86 ,
V_266 -> V_34 ) ;
return - V_109 ;
}
if ( V_266 -> V_259 || V_266 -> V_139 )
F_32 ( V_2 -> V_8 , L_87 ,
V_266 -> V_33 , V_266 -> V_34 ) ;
F_113 (source, path) {
if ( V_81 -> V_34 == V_34 ) {
V_81 -> V_29 = 1 ;
V_218 ++ ;
}
}
if ( V_218 == 0 )
F_78 ( V_2 -> V_8 , L_88 ,
V_266 -> V_33 , V_266 -> V_34 ) ;
if ( V_218 > 1 )
F_32 ( V_2 -> V_8 , L_89 ,
V_218 , V_266 -> V_33 , V_266 -> V_34 ) ;
return 0 ;
}
int F_187 ( struct V_1 * V_2 ,
const struct V_265 * V_266 , int V_272 )
{
int V_94 , V_264 ;
int V_50 = 0 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_274 ) ;
for ( V_94 = 0 ; V_94 < V_272 ; V_94 ++ ) {
V_264 = F_186 ( V_2 , V_266 ) ;
if ( V_264 )
V_50 = V_264 ;
V_266 ++ ;
}
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return V_50 ;
}
int F_188 ( struct V_35 * V_3 )
{
struct V_13 * V_14 ;
unsigned int V_104 ;
F_98 ( & V_3 -> V_5 , V_274 ) ;
F_18 (w, &card->widgets, list)
{
if ( V_14 -> V_275 )
continue;
if ( V_14 -> V_113 ) {
V_14 -> V_116 = F_29 ( V_14 -> V_113 *
sizeof( struct V_41 * ) ,
V_12 ) ;
if ( ! V_14 -> V_116 ) {
F_25 ( & V_3 -> V_5 ) ;
return - V_51 ;
}
}
switch( V_14 -> V_53 ) {
case V_54 :
case V_55 :
case V_56 :
F_79 ( V_14 ) ;
break;
case V_71 :
case V_70 :
F_81 ( V_14 ) ;
break;
case V_125 :
case V_126 :
F_82 ( V_14 ) ;
break;
case V_276 :
F_83 ( V_14 ) ;
break;
default:
break;
}
if ( V_14 -> V_61 >= 0 ) {
F_54 ( V_14 -> V_2 , V_14 -> V_61 , & V_104 ) ;
V_104 = V_104 >> V_14 -> V_64 ;
V_104 &= V_14 -> V_62 ;
if ( V_104 == V_14 -> V_67 )
V_14 -> V_83 = 1 ;
}
V_14 -> V_275 = 1 ;
F_12 ( V_14 , L_90 ) ;
F_154 ( V_14 ) ;
}
F_139 ( V_3 , V_229 ) ;
F_25 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_189 ( struct V_41 * V_42 ,
struct V_277 * V_278 )
{
struct V_1 * V_2 = F_51 ( V_42 ) ;
struct V_35 * V_3 = V_2 -> V_3 ;
struct V_46 * V_47 =
(struct V_46 * ) V_42 -> V_57 ;
int V_61 = V_47 -> V_61 ;
unsigned int V_64 = V_47 -> V_64 ;
int V_63 = V_47 -> V_63 ;
unsigned int V_279 = F_34 ( V_63 ) ;
unsigned int V_62 = ( 1 << F_34 ( V_63 ) ) - 1 ;
unsigned int V_65 = V_47 -> V_65 ;
unsigned int V_280 , V_104 , V_281 = 0 ;
int V_50 = 0 ;
F_98 ( & V_3 -> V_5 , V_145 ) ;
if ( F_46 ( V_42 ) && V_61 != V_106 ) {
V_50 = F_54 ( V_2 , V_61 , & V_280 ) ;
V_104 = ( V_280 >> V_64 ) & V_62 ;
if ( V_50 == 0 && V_61 != V_47 -> V_111 )
V_50 = F_54 ( V_2 , V_47 -> V_111 , & V_280 ) ;
if ( F_31 ( V_47 ) )
V_281 = ( V_280 >> V_47 -> V_112 ) & V_62 ;
} else {
V_280 = F_48 ( V_42 ) ;
V_104 = V_280 & V_62 ;
if ( F_31 ( V_47 ) )
V_281 = ( V_280 >> V_279 ) & V_62 ;
}
F_25 ( & V_3 -> V_5 ) ;
if ( V_50 )
return V_50 ;
if ( V_65 )
V_278 -> V_69 . integer . V_69 [ 0 ] = V_63 - V_104 ;
else
V_278 -> V_69 . integer . V_69 [ 0 ] = V_104 ;
if ( F_31 ( V_47 ) ) {
if ( V_65 )
V_278 -> V_69 . integer . V_69 [ 1 ] = V_63 - V_281 ;
else
V_278 -> V_69 . integer . V_69 [ 1 ] = V_281 ;
}
return V_50 ;
}
int F_190 ( struct V_41 * V_42 ,
struct V_277 * V_278 )
{
struct V_1 * V_2 = F_51 ( V_42 ) ;
struct V_35 * V_3 = V_2 -> V_3 ;
struct V_46 * V_47 =
(struct V_46 * ) V_42 -> V_57 ;
int V_61 = V_47 -> V_61 ;
unsigned int V_64 = V_47 -> V_64 ;
int V_63 = V_47 -> V_63 ;
unsigned int V_279 = F_34 ( V_63 ) ;
unsigned int V_62 = ( 1 << V_279 ) - 1 ;
unsigned int V_65 = V_47 -> V_65 ;
unsigned int V_104 , V_281 = 0 ;
int V_30 , V_230 = - 1 , V_282 , V_283 = 0 ;
struct V_187 V_188 = { NULL } ;
int V_50 = 0 ;
V_104 = ( V_278 -> V_69 . integer . V_69 [ 0 ] & V_62 ) ;
V_30 = ! ! V_104 ;
if ( V_65 )
V_104 = V_63 - V_104 ;
if ( F_31 ( V_47 ) ) {
V_281 = ( V_278 -> V_69 . integer . V_69 [ 1 ] & V_62 ) ;
V_230 = ! ! V_281 ;
if ( V_65 )
V_281 = V_63 - V_281 ;
}
F_98 ( & V_3 -> V_5 , V_145 ) ;
if ( V_279 > sizeof( unsigned int ) * 8 / 2 )
F_32 ( V_2 -> V_8 ,
L_91 ,
V_42 -> V_53 . V_17 ) ;
V_282 = F_49 ( V_42 , V_104 | ( V_281 << V_279 ) ) ;
if ( V_61 != V_106 ) {
V_104 = V_104 << V_64 ;
V_281 = V_281 << V_47 -> V_112 ;
V_283 = F_58 ( V_2 , V_61 , V_62 << V_64 , V_104 ) ;
if ( F_31 ( V_47 ) )
V_283 |= F_58 ( V_2 , V_47 -> V_111 ,
V_62 << V_47 -> V_112 ,
V_281 ) ;
}
if ( V_282 || V_283 ) {
if ( V_283 ) {
if ( F_31 ( V_47 ) ) {
V_188 . V_191 = true ;
V_188 . V_192 = V_47 -> V_111 ;
V_188 . V_193 = V_62 << V_47 -> V_112 ;
V_188 . V_194 = V_281 ;
}
V_188 . V_42 = V_42 ;
V_188 . V_61 = V_61 ;
V_188 . V_62 = V_62 << V_64 ;
V_188 . V_104 = V_104 ;
V_3 -> V_188 = & V_188 ;
}
V_282 |= V_283 ;
V_50 = F_162 ( V_3 , V_42 , V_30 ,
V_230 ) ;
V_3 -> V_188 = NULL ;
}
F_25 ( & V_3 -> V_5 ) ;
if ( V_50 > 0 )
F_161 ( V_3 ) ;
return V_282 ;
}
int F_191 ( struct V_41 * V_42 ,
struct V_277 * V_278 )
{
struct V_1 * V_2 = F_51 ( V_42 ) ;
struct V_35 * V_3 = V_2 -> V_3 ;
struct V_48 * V_49 = (struct V_48 * ) V_42 -> V_57 ;
unsigned int V_280 , V_104 ;
F_98 ( & V_3 -> V_5 , V_145 ) ;
if ( V_49 -> V_61 != V_106 && F_46 ( V_42 ) ) {
int V_50 = F_54 ( V_2 , V_49 -> V_61 , & V_280 ) ;
if ( V_50 ) {
F_25 ( & V_3 -> V_5 ) ;
return V_50 ;
}
} else {
V_280 = F_48 ( V_42 ) ;
}
F_25 ( & V_3 -> V_5 ) ;
V_104 = ( V_280 >> V_49 -> V_72 ) & V_49 -> V_62 ;
V_278 -> V_69 . V_284 . V_105 [ 0 ] = F_70 ( V_49 , V_104 ) ;
if ( V_49 -> V_72 != V_49 -> V_285 ) {
V_104 = ( V_280 >> V_49 -> V_285 ) & V_49 -> V_62 ;
V_104 = F_70 ( V_49 , V_104 ) ;
V_278 -> V_69 . V_284 . V_105 [ 1 ] = V_104 ;
}
return 0 ;
}
int F_192 ( struct V_41 * V_42 ,
struct V_277 * V_278 )
{
struct V_1 * V_2 = F_51 ( V_42 ) ;
struct V_35 * V_3 = V_2 -> V_3 ;
struct V_48 * V_49 = (struct V_48 * ) V_42 -> V_57 ;
unsigned int * V_105 = V_278 -> V_69 . V_284 . V_105 ;
unsigned int V_104 , V_282 , V_283 = 0 ;
unsigned int V_62 ;
struct V_187 V_188 = { NULL } ;
int V_50 = 0 ;
if ( V_105 [ 0 ] >= V_49 -> V_107 )
return - V_127 ;
V_104 = F_38 ( V_49 , V_105 [ 0 ] ) << V_49 -> V_72 ;
V_62 = V_49 -> V_62 << V_49 -> V_72 ;
if ( V_49 -> V_72 != V_49 -> V_285 ) {
if ( V_105 [ 1 ] > V_49 -> V_107 )
return - V_127 ;
V_104 |= F_38 ( V_49 , V_105 [ 1 ] ) << V_49 -> V_285 ;
V_62 |= V_49 -> V_62 << V_49 -> V_285 ;
}
F_98 ( & V_3 -> V_5 , V_145 ) ;
V_282 = F_49 ( V_42 , V_104 ) ;
if ( V_49 -> V_61 != V_106 )
V_283 = F_58 ( V_2 , V_49 -> V_61 , V_62 , V_104 ) ;
if ( V_282 || V_283 ) {
if ( V_283 ) {
V_188 . V_42 = V_42 ;
V_188 . V_61 = V_49 -> V_61 ;
V_188 . V_62 = V_62 ;
V_188 . V_104 = V_104 ;
V_3 -> V_188 = & V_188 ;
}
V_282 |= V_283 ;
V_50 = F_158 ( V_3 , V_42 , V_105 [ 0 ] , V_49 ) ;
V_3 -> V_188 = NULL ;
}
F_25 ( & V_3 -> V_5 ) ;
if ( V_50 > 0 )
F_161 ( V_3 ) ;
return V_282 ;
}
int F_193 ( struct V_41 * V_42 ,
struct V_286 * V_287 )
{
V_287 -> type = V_288 ;
V_287 -> V_218 = 1 ;
V_287 -> V_69 . integer . V_289 = 0 ;
V_287 -> V_69 . integer . V_63 = 1 ;
return 0 ;
}
int F_194 ( struct V_41 * V_42 ,
struct V_277 * V_278 )
{
struct V_35 * V_3 = F_41 ( V_42 ) ;
const char * V_251 = ( const char * ) V_42 -> V_57 ;
F_98 ( & V_3 -> V_5 , V_145 ) ;
V_278 -> V_69 . integer . V_69 [ 0 ] =
F_195 ( & V_3 -> V_2 , V_251 ) ;
F_25 ( & V_3 -> V_5 ) ;
return 0 ;
}
int F_196 ( struct V_41 * V_42 ,
struct V_277 * V_278 )
{
struct V_35 * V_3 = F_41 ( V_42 ) ;
const char * V_251 = ( const char * ) V_42 -> V_57 ;
if ( V_278 -> V_69 . integer . V_69 [ 0 ] )
F_197 ( & V_3 -> V_2 , V_251 ) ;
else
F_198 ( & V_3 -> V_2 , V_251 ) ;
F_178 ( & V_3 -> V_2 ) ;
return 0 ;
}
struct V_13 *
F_199 ( struct V_1 * V_2 ,
const struct V_13 * V_40 )
{
struct V_13 * V_14 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_145 ) ;
V_14 = F_35 ( V_2 , V_40 ) ;
if ( F_36 ( V_14 ) ) {
int V_50 = F_37 ( V_14 ) ;
if ( V_50 != - V_290 )
F_78 ( V_2 -> V_8 ,
L_92 ,
V_40 -> V_17 , V_50 ) ;
goto V_291;
}
if ( ! V_14 )
F_78 ( V_2 -> V_8 ,
L_93 ,
V_40 -> V_17 ) ;
V_291:
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return V_14 ;
}
struct V_13 *
F_35 ( struct V_1 * V_2 ,
const struct V_13 * V_40 )
{
enum V_19 V_20 ;
struct V_13 * V_14 ;
const char * V_119 ;
int V_50 ;
if ( ( V_14 = F_26 ( V_40 ) ) == NULL )
return NULL ;
switch ( V_14 -> V_53 ) {
case V_212 :
V_14 -> V_152 = F_200 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_36 ( V_14 -> V_152 ) ) {
V_50 = F_37 ( V_14 -> V_152 ) ;
if ( V_50 == - V_290 )
return F_201 ( V_50 ) ;
F_78 ( V_2 -> V_8 , L_94 ,
V_14 -> V_17 , V_50 ) ;
return NULL ;
}
if ( V_14 -> V_67 & V_151 ) {
V_50 = F_103 ( V_14 -> V_152 , true ) ;
if ( V_50 != 0 )
F_32 ( V_14 -> V_2 -> V_8 ,
L_14 ,
V_14 -> V_17 , V_50 ) ;
}
break;
case V_213 :
#ifdef F_202
V_14 -> V_153 = F_203 ( V_2 -> V_8 , V_14 -> V_17 ) ;
if ( F_36 ( V_14 -> V_153 ) ) {
V_50 = F_37 ( V_14 -> V_153 ) ;
if ( V_50 == - V_290 )
return F_201 ( V_50 ) ;
F_78 ( V_2 -> V_8 , L_94 ,
V_14 -> V_17 , V_50 ) ;
return NULL ;
}
#else
return NULL ;
#endif
break;
default:
break;
}
V_119 = F_53 ( V_2 ) ;
if ( V_119 )
V_14 -> V_17 = F_33 ( V_12 , L_5 , V_119 , V_40 -> V_17 ) ;
else
V_14 -> V_17 = F_204 ( V_40 -> V_17 , V_12 ) ;
if ( V_14 -> V_17 == NULL ) {
F_9 ( V_14 ) ;
return NULL ;
}
switch ( V_14 -> V_53 ) {
case V_235 :
V_14 -> V_36 = V_38 ;
V_14 -> V_155 = F_111 ;
break;
case V_256 :
if ( ! V_2 -> V_3 -> V_257 )
V_14 -> V_36 = V_38 ;
V_14 -> V_155 = F_111 ;
break;
case V_236 :
case V_234 :
V_14 -> V_36 = V_37 ;
V_14 -> V_155 = F_111 ;
break;
case V_258 :
if ( ! V_2 -> V_3 -> V_257 )
V_14 -> V_36 = V_37 ;
V_14 -> V_155 = F_111 ;
break;
case V_210 :
case V_209 :
V_14 -> V_36 = V_38 ;
V_14 -> V_155 = F_114 ;
break;
case V_292 :
V_14 -> V_36 = V_37 ;
V_14 -> V_155 = F_114 ;
break;
case V_71 :
case V_70 :
case V_54 :
case V_55 :
case V_56 :
case V_239 :
case V_293 :
case V_238 :
case V_294 :
case V_125 :
case V_126 :
case V_214 :
case V_237 :
case V_276 :
case V_295 :
case V_296 :
V_14 -> V_155 = F_111 ;
break;
case V_211 :
case V_212 :
case V_213 :
case V_68 :
V_14 -> V_28 = 1 ;
V_14 -> V_155 = F_112 ;
break;
default:
V_14 -> V_155 = F_114 ;
break;
}
V_14 -> V_2 = V_2 ;
F_30 ( & V_14 -> V_25 ) ;
F_30 ( & V_14 -> V_15 ) ;
F_14 ( & V_14 -> V_25 , & V_2 -> V_3 -> V_80 ) ;
F_148 (dir) {
F_30 ( & V_14 -> V_130 [ V_20 ] ) ;
V_14 -> V_26 [ V_20 ] = - 1 ;
}
V_14 -> V_139 = 1 ;
return V_14 ;
}
int F_205 ( struct V_1 * V_2 ,
const struct V_13 * V_40 ,
int V_272 )
{
struct V_13 * V_14 ;
int V_94 ;
int V_50 = 0 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_274 ) ;
for ( V_94 = 0 ; V_94 < V_272 ; V_94 ++ ) {
V_14 = F_35 ( V_2 , V_40 ) ;
if ( F_36 ( V_14 ) ) {
V_50 = F_37 ( V_14 ) ;
if ( V_50 == - V_290 )
break;
F_78 ( V_2 -> V_8 ,
L_92 ,
V_40 -> V_17 , V_50 ) ;
break;
}
if ( ! V_14 ) {
F_78 ( V_2 -> V_8 ,
L_93 ,
V_40 -> V_17 ) ;
V_50 = - V_51 ;
break;
}
V_40 ++ ;
}
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return V_50 ;
}
static int F_206 ( struct V_13 * V_14 ,
struct V_41 * V_42 , int V_150 )
{
struct V_23 * V_297 , * V_298 ;
struct V_142 * V_33 , * V_34 ;
const struct V_299 * V_300 = V_14 -> V_301 + V_14 -> V_302 ;
struct V_303 V_304 ;
struct V_305 * V_301 = NULL ;
struct V_306 * V_307 = NULL ;
T_9 V_9 ;
int V_50 ;
if ( F_123 ( ! V_300 ) ||
F_123 ( F_11 ( & V_14 -> V_130 [ V_32 ] ) ||
F_11 ( & V_14 -> V_130 [ V_31 ] ) ) )
return - V_127 ;
V_297 = F_122 ( & V_14 -> V_130 [ V_32 ] ,
struct V_23 ,
V_246 [ V_32 ] ) ;
V_298 = F_122 ( & V_14 -> V_130 [ V_31 ] ,
struct V_23 ,
V_246 [ V_31 ] ) ;
V_33 = V_297 -> V_33 -> V_308 ;
V_34 = V_298 -> V_34 -> V_308 ;
if ( V_300 -> V_309 ) {
V_9 = F_207 ( V_300 -> V_309 ) - 1 ;
} else {
F_32 ( V_14 -> V_2 -> V_8 , L_95 ,
V_300 -> V_309 ) ;
V_9 = 0 ;
}
V_301 = F_29 ( sizeof( * V_301 ) , V_12 ) ;
if ( ! V_301 ) {
V_50 = - V_51 ;
goto V_99;
}
F_208 ( F_209 ( V_301 , V_310 ) , V_9 ) ;
F_210 ( V_301 , V_311 ) -> V_289 =
V_300 -> V_312 ;
F_210 ( V_301 , V_311 ) -> V_63 =
V_300 -> V_313 ;
F_210 ( V_301 , V_314 ) -> V_289
= V_300 -> V_315 ;
F_210 ( V_301 , V_314 ) -> V_63
= V_300 -> V_316 ;
memset ( & V_304 , 0 , sizeof( V_304 ) ) ;
V_307 = F_29 ( sizeof( * V_307 ) , V_12 ) ;
if ( ! V_307 ) {
V_50 = - V_51 ;
goto V_99;
}
V_304 . V_307 = V_307 ;
switch ( V_150 ) {
case V_168 :
V_304 . V_144 = V_317 ;
if ( V_33 -> V_318 -> V_319 && V_33 -> V_318 -> V_319 -> V_320 ) {
V_50 = V_33 -> V_318 -> V_319 -> V_320 ( & V_304 , V_33 ) ;
if ( V_50 < 0 ) {
F_78 ( V_33 -> V_8 ,
L_96 , V_50 ) ;
goto V_99;
}
V_33 -> V_221 ++ ;
}
V_50 = F_211 ( & V_304 , V_301 , V_33 ) ;
if ( V_50 < 0 )
goto V_99;
V_304 . V_144 = V_146 ;
if ( V_34 -> V_318 -> V_319 && V_34 -> V_318 -> V_319 -> V_320 ) {
V_50 = V_34 -> V_318 -> V_319 -> V_320 ( & V_304 , V_34 ) ;
if ( V_50 < 0 ) {
F_78 ( V_34 -> V_8 ,
L_96 , V_50 ) ;
goto V_99;
}
V_34 -> V_221 ++ ;
}
V_50 = F_211 ( & V_304 , V_301 , V_34 ) ;
if ( V_50 < 0 )
goto V_99;
break;
case V_169 :
V_50 = F_212 ( V_34 , 0 ,
V_146 ) ;
if ( V_50 != 0 && V_50 != - V_321 )
F_32 ( V_34 -> V_8 , L_97 , V_50 ) ;
V_50 = 0 ;
break;
case V_170 :
V_50 = F_212 ( V_34 , 1 ,
V_146 ) ;
if ( V_50 != 0 && V_50 != - V_321 )
F_32 ( V_34 -> V_8 , L_98 , V_50 ) ;
V_50 = 0 ;
V_33 -> V_221 -- ;
if ( V_33 -> V_318 -> V_319 && V_33 -> V_318 -> V_319 -> V_322 ) {
V_304 . V_144 = V_317 ;
V_33 -> V_318 -> V_319 -> V_322 ( & V_304 , V_33 ) ;
}
V_34 -> V_221 -- ;
if ( V_34 -> V_318 -> V_319 && V_34 -> V_318 -> V_319 -> V_322 ) {
V_304 . V_144 = V_146 ;
V_34 -> V_318 -> V_319 -> V_322 ( & V_304 , V_34 ) ;
}
break;
default:
F_118 ( 1 , L_21 , V_150 ) ;
V_50 = - V_127 ;
}
V_99:
F_9 ( V_307 ) ;
F_9 ( V_301 ) ;
return V_50 ;
}
static int F_213 ( struct V_41 * V_42 ,
struct V_277 * V_278 )
{
struct V_13 * V_14 = F_41 ( V_42 ) ;
V_278 -> V_69 . V_284 . V_105 [ 0 ] = V_14 -> V_302 ;
return 0 ;
}
static int F_214 ( struct V_41 * V_42 ,
struct V_277 * V_278 )
{
struct V_13 * V_14 = F_41 ( V_42 ) ;
if ( V_14 -> V_83 )
return - V_323 ;
if ( V_278 -> V_69 . V_284 . V_105 [ 0 ] == V_14 -> V_302 )
return 0 ;
if ( V_278 -> V_69 . V_284 . V_105 [ 0 ] >= V_14 -> V_131 )
return - V_127 ;
V_14 -> V_302 = V_278 -> V_69 . V_284 . V_105 [ 0 ] ;
return 0 ;
}
int F_215 ( struct V_35 * V_3 ,
const struct V_299 * V_301 ,
unsigned int V_131 ,
struct V_13 * V_33 ,
struct V_13 * V_34 )
{
struct V_13 V_59 ;
struct V_13 * V_14 ;
char * V_324 ;
int V_50 , V_218 ;
unsigned long V_57 ;
const char * * V_325 ;
struct V_48 V_326 [] = {
F_216 ( 0 , 0 , 0 , NULL ) ,
} ;
struct V_102 V_327 [] = {
F_217 ( NULL , V_326 [ 0 ] ,
F_213 ,
F_214 ) ,
} ;
const struct V_299 * V_300 = V_301 ;
V_325 = F_218 ( V_3 -> V_8 , V_131 ,
sizeof( char * ) , V_12 ) ;
if ( ! V_325 )
return - V_51 ;
V_324 = F_219 ( V_3 -> V_8 , V_12 , L_99 ,
V_33 -> V_17 , V_34 -> V_17 ) ;
if ( ! V_324 ) {
V_50 = - V_51 ;
goto V_328;
}
for ( V_218 = 0 ; V_218 < V_131 ; V_218 ++ ) {
if ( ! V_300 -> V_329 ) {
F_32 ( V_3 -> V_2 . V_8 ,
L_100 ,
V_218 , V_324 ) ;
V_325 [ V_218 ] =
F_219 ( V_3 -> V_8 , V_12 ,
L_101 ,
V_218 ) ;
if ( ! V_325 [ V_218 ] ) {
V_50 = - V_51 ;
goto V_330;
}
} else {
V_325 [ V_218 ] = F_220 ( V_3 -> V_8 ,
V_300 -> V_329 ,
strlen ( V_300 -> V_329 ) + 1 ,
V_12 ) ;
if ( ! V_325 [ V_218 ] ) {
V_50 = - V_51 ;
goto V_330;
}
}
V_300 ++ ;
}
V_326 [ 0 ] . V_107 = V_131 ;
V_326 [ 0 ] . V_108 = V_325 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_61 = V_106 ;
V_59 . V_53 = V_276 ;
V_59 . V_17 = V_324 ;
V_59 . V_150 = F_206 ;
V_59 . V_174 = V_168 | V_169 |
V_170 ;
V_59 . V_113 = 1 ;
V_57 =
( unsigned long ) F_220 ( V_3 -> V_8 ,
( void * ) ( V_327 [ 0 ] . V_57 ) ,
sizeof( struct V_48 ) , V_12 ) ;
if ( ! V_57 ) {
F_78 ( V_3 -> V_8 , L_102 ,
V_324 ) ;
V_50 = - V_51 ;
goto V_330;
}
V_327 [ 0 ] . V_57 = V_57 ;
V_59 . V_103 =
F_220 ( V_3 -> V_8 , & V_327 [ 0 ] ,
sizeof( struct V_102 ) ,
V_12 ) ;
if ( ! V_59 . V_103 ) {
F_78 ( V_3 -> V_8 , L_102 ,
V_324 ) ;
V_50 = - V_51 ;
goto V_331;
}
F_86 ( V_3 -> V_8 , L_103 , V_324 ) ;
V_14 = F_35 ( & V_3 -> V_2 , & V_59 ) ;
if ( F_36 ( V_14 ) ) {
V_50 = F_37 ( V_14 ) ;
if ( V_50 != - V_290 )
F_78 ( V_3 -> V_8 ,
L_104 ,
V_324 , V_50 ) ;
goto V_332;
}
if ( ! V_14 ) {
F_78 ( V_3 -> V_8 , L_105 ,
V_324 ) ;
V_50 = - V_51 ;
goto V_332;
}
V_14 -> V_301 = V_301 ;
V_14 -> V_131 = V_131 ;
V_50 = F_39 ( & V_3 -> V_2 , V_33 , V_14 , NULL , NULL ) ;
if ( V_50 )
goto V_333;
return F_39 ( & V_3 -> V_2 , V_14 , V_34 , NULL , NULL ) ;
V_333:
F_221 ( V_3 -> V_8 , V_14 ) ;
V_332:
F_221 ( V_3 -> V_8 , ( void * ) V_59 . V_103 ) ;
V_331:
F_221 ( V_3 -> V_8 , ( void * ) V_57 ) ;
V_330:
F_221 ( V_3 -> V_8 , V_324 ) ;
V_328:
for ( V_218 = 0 ; V_218 < V_131 ; V_218 ++ )
F_221 ( V_3 -> V_8 , ( void * ) V_325 [ V_218 ] ) ;
F_221 ( V_3 -> V_8 , V_325 ) ;
return V_50 ;
}
int F_222 ( struct V_1 * V_2 ,
struct V_142 * V_143 )
{
struct V_13 V_59 ;
struct V_13 * V_14 ;
F_123 ( V_2 -> V_8 != V_143 -> V_8 ) ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_61 = V_106 ;
if ( V_143 -> V_318 -> V_334 . V_329 ) {
V_59 . V_53 = V_296 ;
V_59 . V_17 = V_143 -> V_318 -> V_334 . V_329 ;
V_59 . V_220 = V_143 -> V_318 -> V_334 . V_329 ;
F_86 ( V_143 -> V_8 , L_103 ,
V_59 . V_17 ) ;
V_14 = F_35 ( V_2 , & V_59 ) ;
if ( F_36 ( V_14 ) ) {
int V_50 = F_37 ( V_14 ) ;
if ( V_50 != - V_290 )
F_78 ( V_2 -> V_8 ,
L_104 ,
V_143 -> V_318 -> V_334 . V_329 , V_50 ) ;
return V_50 ;
}
if ( ! V_14 ) {
F_78 ( V_2 -> V_8 , L_105 ,
V_143 -> V_318 -> V_334 . V_329 ) ;
return - V_51 ;
}
V_14 -> V_308 = V_143 ;
V_143 -> V_147 = V_14 ;
}
if ( V_143 -> V_318 -> V_335 . V_329 ) {
V_59 . V_53 = V_295 ;
V_59 . V_17 = V_143 -> V_318 -> V_335 . V_329 ;
V_59 . V_220 = V_143 -> V_318 -> V_335 . V_329 ;
F_86 ( V_143 -> V_8 , L_103 ,
V_59 . V_17 ) ;
V_14 = F_35 ( V_2 , & V_59 ) ;
if ( F_36 ( V_14 ) ) {
int V_50 = F_37 ( V_14 ) ;
if ( V_50 != - V_290 )
F_78 ( V_2 -> V_8 ,
L_104 ,
V_143 -> V_318 -> V_334 . V_329 , V_50 ) ;
return V_50 ;
}
if ( ! V_14 ) {
F_78 ( V_2 -> V_8 , L_105 ,
V_143 -> V_318 -> V_335 . V_329 ) ;
return - V_51 ;
}
V_14 -> V_308 = V_143 ;
V_143 -> V_148 = V_14 ;
}
return 0 ;
}
int F_223 ( struct V_35 * V_3 )
{
struct V_13 * V_336 , * V_14 ;
struct V_13 * V_337 , * V_34 ;
struct V_142 * V_143 ;
F_18 (dai_w, &card->widgets, list) {
switch ( V_336 -> V_53 ) {
case V_296 :
case V_295 :
break;
default:
continue;
}
V_143 = V_336 -> V_308 ;
F_18 (w, &card->widgets, list) {
if ( V_14 -> V_2 != V_336 -> V_2 )
continue;
switch ( V_14 -> V_53 ) {
case V_296 :
case V_295 :
continue;
default:
break;
}
if ( ! V_14 -> V_220 || ! strstr ( V_14 -> V_220 , V_336 -> V_220 ) )
continue;
if ( V_336 -> V_53 == V_296 ) {
V_337 = V_336 ;
V_34 = V_14 ;
} else {
V_337 = V_14 ;
V_34 = V_336 ;
}
F_86 ( V_143 -> V_8 , L_106 , V_337 -> V_17 , V_34 -> V_17 ) ;
F_39 ( V_14 -> V_2 , V_337 , V_34 , NULL , NULL ) ;
}
}
return 0 ;
}
static void F_224 ( struct V_35 * V_3 ,
struct V_242 * V_243 )
{
struct V_142 * V_338 = V_243 -> V_338 ;
struct V_13 * V_34 , * V_33 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_243 -> V_244 ; V_94 ++ ) {
struct V_142 * V_339 = V_243 -> V_245 [ V_94 ] ;
if ( V_339 -> V_147 && V_338 -> V_147 ) {
V_33 = V_338 -> V_147 ;
V_34 = V_339 -> V_147 ;
F_86 ( V_243 -> V_8 , L_107 ,
V_338 -> V_88 -> V_17 , V_33 -> V_17 ,
V_339 -> V_88 -> V_17 , V_34 -> V_17 ) ;
F_39 ( & V_3 -> V_2 , V_33 , V_34 ,
NULL , NULL ) ;
}
if ( V_339 -> V_148 && V_338 -> V_148 ) {
V_33 = V_339 -> V_148 ;
V_34 = V_338 -> V_148 ;
F_86 ( V_243 -> V_8 , L_107 ,
V_339 -> V_88 -> V_17 , V_33 -> V_17 ,
V_338 -> V_88 -> V_17 , V_34 -> V_17 ) ;
F_39 ( & V_3 -> V_2 , V_33 , V_34 ,
NULL , NULL ) ;
}
}
}
static void F_225 ( struct V_142 * V_143 , int V_144 ,
int V_150 )
{
struct V_13 * V_14 ;
unsigned int V_255 ;
if ( V_144 == V_146 )
V_14 = V_143 -> V_147 ;
else
V_14 = V_143 -> V_148 ;
if ( V_14 ) {
F_12 ( V_14 , L_108 ) ;
if ( V_14 -> V_53 == V_296 ) {
V_255 = V_38 ;
F_20 ( V_14 ) ;
} else {
V_255 = V_37 ;
F_21 ( V_14 ) ;
}
switch ( V_150 ) {
case V_184 :
V_14 -> V_221 = 1 ;
V_14 -> V_36 = V_255 ;
break;
case V_185 :
V_14 -> V_221 = 0 ;
V_14 -> V_36 = 0 ;
break;
case V_340 :
case V_341 :
case V_342 :
case V_343 :
break;
}
}
}
void F_226 ( struct V_35 * V_3 )
{
struct V_242 * V_243 ;
F_18 (rtd, &card->rtd_list, list) {
if ( V_243 -> V_344 -> V_345 || V_243 -> V_344 -> V_301 )
continue;
F_224 ( V_3 , V_243 ) ;
}
}
static void F_227 ( struct V_242 * V_243 , int V_144 ,
int V_150 )
{
int V_94 ;
F_225 ( V_243 -> V_338 , V_144 , V_150 ) ;
for ( V_94 = 0 ; V_94 < V_243 -> V_244 ; V_94 ++ )
F_225 ( V_243 -> V_245 [ V_94 ] , V_144 , V_150 ) ;
F_139 ( V_243 -> V_3 , V_150 ) ;
}
void F_228 ( struct V_242 * V_243 , int V_144 ,
int V_150 )
{
struct V_35 * V_3 = V_243 -> V_3 ;
F_98 ( & V_3 -> V_5 , V_145 ) ;
F_227 ( V_243 , V_144 , V_150 ) ;
F_25 ( & V_3 -> V_5 ) ;
}
int F_229 ( struct V_1 * V_2 ,
const char * V_251 )
{
return F_176 ( V_2 , V_251 , 1 ) ;
}
int F_197 ( struct V_1 * V_2 , const char * V_251 )
{
int V_50 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_145 ) ;
V_50 = F_176 ( V_2 , V_251 , 1 ) ;
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return V_50 ;
}
int F_230 ( struct V_1 * V_2 ,
const char * V_251 )
{
struct V_13 * V_14 = F_175 ( V_2 , V_251 , true ) ;
if ( ! V_14 ) {
F_78 ( V_2 -> V_8 , L_109 , V_251 ) ;
return - V_127 ;
}
F_86 ( V_14 -> V_2 -> V_8 , L_110 , V_251 ) ;
if ( ! V_14 -> V_139 ) {
F_20 ( V_14 ) ;
F_21 ( V_14 ) ;
V_14 -> V_139 = 1 ;
}
V_14 -> V_154 = 1 ;
F_12 ( V_14 , L_111 ) ;
return 0 ;
}
int F_231 ( struct V_1 * V_2 ,
const char * V_251 )
{
int V_50 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_145 ) ;
V_50 = F_230 ( V_2 , V_251 ) ;
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return V_50 ;
}
int F_232 ( struct V_1 * V_2 ,
const char * V_251 )
{
return F_176 ( V_2 , V_251 , 0 ) ;
}
int F_198 ( struct V_1 * V_2 ,
const char * V_251 )
{
int V_50 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_145 ) ;
V_50 = F_176 ( V_2 , V_251 , 0 ) ;
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return V_50 ;
}
int F_233 ( struct V_1 * V_2 ,
const char * V_251 )
{
return F_176 ( V_2 , V_251 , 0 ) ;
}
int F_234 ( struct V_1 * V_2 , const char * V_251 )
{
int V_50 ;
F_98 ( & V_2 -> V_3 -> V_5 , V_145 ) ;
V_50 = F_176 ( V_2 , V_251 , 0 ) ;
F_25 ( & V_2 -> V_3 -> V_5 ) ;
return V_50 ;
}
int F_195 ( struct V_1 * V_2 ,
const char * V_251 )
{
struct V_13 * V_14 = F_175 ( V_2 , V_251 , true ) ;
if ( V_14 )
return V_14 -> V_139 ;
return 0 ;
}
int F_235 ( struct V_1 * V_2 ,
const char * V_251 )
{
struct V_13 * V_14 = F_175 ( V_2 , V_251 , false ) ;
if ( ! V_14 ) {
F_78 ( V_2 -> V_8 , L_109 , V_251 ) ;
return - V_127 ;
}
V_14 -> V_134 = 1 ;
return 0 ;
}
void F_236 ( struct V_1 * V_2 )
{
F_155 ( V_2 ) ;
F_174 ( V_2 ) ;
F_99 ( & V_2 -> V_25 ) ;
}
static void F_237 ( struct V_1 * V_2 )
{
struct V_35 * V_3 = V_2 -> V_3 ;
struct V_13 * V_14 ;
F_17 ( V_204 ) ;
int V_346 = 0 ;
F_24 ( & V_3 -> V_5 ) ;
F_18 (w, &dapm->card->widgets, list) {
if ( V_14 -> V_2 != V_2 )
continue;
if ( V_14 -> V_83 ) {
F_116 ( V_14 , & V_204 , false ) ;
V_14 -> V_83 = 0 ;
V_346 = 1 ;
}
}
if ( V_346 ) {
if ( V_2 -> V_98 == V_200 )
F_66 ( V_2 ,
V_201 ) ;
F_124 ( V_3 , & V_204 , 0 , false ) ;
if ( V_2 -> V_98 == V_201 )
F_66 ( V_2 ,
V_199 ) ;
}
F_25 ( & V_3 -> V_5 ) ;
}
void F_238 ( struct V_35 * V_3 )
{
struct V_1 * V_2 ;
F_18 (dapm, &card->dapm_list, list) {
if ( V_2 != & V_3 -> V_2 ) {
F_237 ( V_2 ) ;
if ( V_2 -> V_98 == V_199 )
F_66 ( V_2 ,
V_197 ) ;
}
}
F_237 ( & V_3 -> V_2 ) ;
if ( V_3 -> V_2 . V_98 == V_199 )
F_66 ( & V_3 -> V_2 ,
V_197 ) ;
}
