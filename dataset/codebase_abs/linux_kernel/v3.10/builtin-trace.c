static int F_1 ( const void * V_1 , const void * V_2 )
{
const struct V_3 * V_4 = V_2 ;
return strcmp ( V_1 , V_4 -> V_1 ) ;
}
static struct V_3 * F_2 ( const char * V_1 )
{
const int V_5 = F_3 ( V_6 ) ;
return bsearch ( V_1 , V_6 , V_5 , sizeof( struct V_3 ) , F_1 ) ;
}
static T_1 F_4 ( unsigned long V_7 , T_2 * V_8 )
{
double V_9 = ( double ) V_7 / V_10 ;
T_1 V_11 = fprintf ( V_8 , L_1 ) ;
if ( V_9 >= 1.0 )
V_11 += F_5 ( V_8 , V_12 , L_2 , V_9 ) ;
else if ( V_9 >= 0.01 )
V_11 += F_5 ( V_8 , V_13 , L_2 , V_9 ) ;
else
V_11 += F_5 ( V_8 , V_14 , L_2 , V_9 ) ;
return V_11 + fprintf ( stdout , L_3 ) ;
}
static struct V_15 * F_6 ( void )
{
return F_7 ( sizeof( struct V_15 ) ) ;
}
static struct V_15 * F_8 ( struct V_16 * V_16 )
{
struct V_15 * V_17 ;
if ( V_16 == NULL )
goto V_18;
if ( V_16 -> V_19 == NULL )
V_16 -> V_19 = F_6 () ;
if ( V_16 -> V_19 == NULL )
goto V_18;
V_17 = V_16 -> V_19 ;
++ V_17 -> V_20 ;
return V_17 ;
V_18:
F_5 ( stdout , V_12 ,
L_4 ) ;
return NULL ;
}
static bool F_9 ( struct V_21 * V_21 , double V_7 )
{
return V_7 < ( V_21 -> V_22 * V_10 ) ;
}
static T_1 F_10 ( struct V_21 * V_21 , T_3 V_23 , T_2 * V_8 )
{
double V_24 = ( double ) ( V_23 - V_21 -> V_25 ) / V_10 ;
return fprintf ( V_8 , L_5 , V_24 ) ;
}
static void F_11 ( int T_4 V_26 )
{
V_27 = true ;
}
static T_1 F_12 ( struct V_21 * V_21 , struct V_16 * V_16 ,
T_3 V_9 , T_3 V_23 , T_2 * V_8 )
{
T_1 V_11 = F_10 ( V_21 , V_23 , V_8 ) ;
V_11 += F_4 ( V_9 , V_8 ) ;
if ( V_21 -> V_28 )
V_11 += fprintf ( V_8 , L_6 , V_16 -> V_29 ) ;
return V_11 ;
}
static int F_13 ( struct V_30 * V_30 , union V_31 * V_32 )
{
int V_33 = 0 ;
switch ( V_32 -> V_34 . type ) {
case V_35 :
F_5 ( stdout , V_12 ,
L_7 V_36 L_8 , V_32 -> V_37 . V_37 ) ;
V_33 = F_14 ( V_30 , V_32 ) ;
default:
V_33 = F_15 ( V_30 , V_32 ) ;
break;
}
return V_33 ;
}
static int F_16 ( struct V_38 * T_5 V_26 ,
union V_31 * V_32 ,
struct V_39 * T_6 V_26 ,
struct V_30 * V_30 )
{
return F_13 ( V_30 , V_32 ) ;
}
static int F_17 ( struct V_21 * V_21 , struct V_40 * V_41 )
{
int V_42 = F_18 () ;
if ( V_42 )
return V_42 ;
F_19 ( & V_21 -> V_43 , L_9 , V_44 ) ;
F_20 ( & V_21 -> V_43 ) ;
if ( F_21 ( & V_21 -> V_45 . V_46 ) ) {
V_42 = F_22 ( NULL , V_41 -> V_47 ,
F_16 ,
& V_21 -> V_43 ) ;
} else {
V_42 = F_23 ( NULL , F_16 ,
& V_21 -> V_43 ) ;
}
if ( V_42 )
F_24 () ;
return V_42 ;
}
static int F_25 ( struct V_21 * V_21 , int V_48 )
{
char V_49 [ 128 ] ;
struct V_50 * V_51 ;
const char * V_1 = F_26 ( V_48 , V_21 -> V_52 ) ;
if ( V_1 == NULL )
return - 1 ;
if ( V_48 > V_21 -> V_53 . V_54 ) {
struct V_50 * V_55 = realloc ( V_21 -> V_53 . V_56 , ( V_48 + 1 ) * sizeof( * V_51 ) ) ;
if ( V_55 == NULL )
return - 1 ;
if ( V_21 -> V_53 . V_54 != - 1 ) {
memset ( V_55 + V_21 -> V_53 . V_54 + 1 , 0 ,
( V_48 - V_21 -> V_53 . V_54 ) * sizeof( * V_51 ) ) ;
} else {
memset ( V_55 , 0 , ( V_48 + 1 ) * sizeof( * V_51 ) ) ;
}
V_21 -> V_53 . V_56 = V_55 ;
V_21 -> V_53 . V_54 = V_48 ;
}
V_51 = V_21 -> V_53 . V_56 + V_48 ;
V_51 -> V_1 = V_1 ;
V_51 -> V_4 = F_2 ( V_51 -> V_1 ) ;
snprintf ( V_49 , sizeof( V_49 ) , L_10 , V_51 -> V_1 ) ;
V_51 -> V_57 = F_27 ( L_11 , V_49 ) ;
if ( V_51 -> V_57 == NULL && V_51 -> V_4 && V_51 -> V_4 -> V_58 ) {
snprintf ( V_49 , sizeof( V_49 ) , L_10 , V_51 -> V_4 -> V_58 ) ;
V_51 -> V_57 = F_27 ( L_11 , V_49 ) ;
}
return V_51 -> V_57 != NULL ? 0 : - 1 ;
}
static T_1 F_28 ( struct V_50 * V_51 , char * V_59 , T_1 V_60 ,
unsigned long * args )
{
int V_61 = 0 ;
T_1 V_11 = 0 ;
if ( V_51 -> V_57 != NULL ) {
struct V_62 * V_63 ;
for ( V_63 = V_51 -> V_57 -> V_64 . V_65 -> V_66 ; V_63 ; V_63 = V_63 -> V_66 ) {
V_11 += F_29 ( V_59 + V_11 , V_60 - V_11 ,
L_12 , V_11 ? L_13 : L_9 ,
V_63 -> V_1 , args [ V_61 ++ ] ) ;
}
} else {
while ( V_61 < 6 ) {
V_11 += F_29 ( V_59 + V_11 , V_60 - V_11 ,
L_14 ,
V_11 ? L_13 : L_9 , V_61 , args [ V_61 ] ) ;
++ V_61 ;
}
}
return V_11 ;
}
static struct V_50 * F_30 ( struct V_21 * V_21 ,
struct V_67 * V_68 ,
struct V_39 * T_6 )
{
int V_48 = F_31 ( V_68 , T_6 , L_15 ) ;
if ( V_48 < 0 ) {
printf ( L_16 , V_48 ) ;
return NULL ;
}
if ( ( V_48 > V_21 -> V_53 . V_54 || V_21 -> V_53 . V_56 [ V_48 ] . V_1 == NULL ) &&
F_25 ( V_21 , V_48 ) )
goto V_69;
if ( ( V_48 > V_21 -> V_53 . V_54 || V_21 -> V_53 . V_56 [ V_48 ] . V_1 == NULL ) )
goto V_69;
return & V_21 -> V_53 . V_56 [ V_48 ] ;
V_69:
printf ( L_17 , V_48 ) ;
if ( V_48 <= V_21 -> V_53 . V_54 && V_21 -> V_53 . V_56 [ V_48 ] . V_1 != NULL )
printf ( L_18 , V_21 -> V_53 . V_56 [ V_48 ] . V_1 ) ;
puts ( L_19 ) ;
return NULL ;
}
static int F_32 ( struct V_21 * V_21 , struct V_67 * V_68 ,
struct V_39 * T_6 )
{
char * V_70 ;
void * args ;
T_1 V_11 = 0 ;
struct V_16 * V_16 = F_33 ( & V_21 -> V_43 , T_6 -> V_71 ) ;
struct V_50 * V_51 = F_30 ( V_21 , V_68 , T_6 ) ;
struct V_15 * V_17 = F_8 ( V_16 ) ;
if ( V_17 == NULL || V_51 == NULL )
return - 1 ;
args = F_34 ( V_68 , T_6 , L_20 ) ;
if ( args == NULL ) {
printf ( L_21 ) ;
return - 1 ;
}
V_17 = V_16 -> V_19 ;
if ( V_17 -> V_72 == NULL ) {
V_17 -> V_72 = malloc ( 1024 ) ;
if ( ! V_17 -> V_72 )
return - 1 ;
}
V_17 -> V_73 = T_6 -> time ;
V_70 = V_17 -> V_72 ;
V_11 += F_29 ( V_70 + V_11 , 1024 - V_11 , L_22 , V_51 -> V_1 ) ;
V_11 += F_28 ( V_51 , V_70 + V_11 , 1024 - V_11 , args ) ;
if ( ! strcmp ( V_51 -> V_1 , L_23 ) || ! strcmp ( V_51 -> V_1 , L_24 ) ) {
if ( ! V_21 -> V_22 ) {
F_12 ( V_21 , V_16 , 1 , T_6 -> time , stdout ) ;
printf ( L_25 , V_17 -> V_72 ) ;
}
} else
V_17 -> V_74 = true ;
return 0 ;
}
static int F_35 ( struct V_21 * V_21 , struct V_67 * V_68 ,
struct V_39 * T_6 )
{
int V_33 ;
T_3 V_9 = 0 ;
struct V_16 * V_16 = F_33 ( & V_21 -> V_43 , T_6 -> V_71 ) ;
struct V_15 * V_17 = F_8 ( V_16 ) ;
struct V_50 * V_51 = F_30 ( V_21 , V_68 , T_6 ) ;
if ( V_17 == NULL || V_51 == NULL )
return - 1 ;
V_33 = F_31 ( V_68 , T_6 , L_26 ) ;
V_17 = V_16 -> V_19 ;
V_17 -> V_75 = T_6 -> time ;
if ( V_17 -> V_73 ) {
V_9 = T_6 -> time - V_17 -> V_73 ;
if ( F_9 ( V_21 , V_9 ) )
goto V_76;
} else if ( V_21 -> V_22 )
goto V_76;
F_12 ( V_21 , V_16 , V_9 , T_6 -> time , stdout ) ;
if ( V_17 -> V_74 ) {
printf ( L_27 , V_17 -> V_72 ) ;
} else {
printf ( L_28 ) ;
F_5 ( stdout , V_13 , L_29 ) ;
printf ( L_30 , V_51 -> V_1 ) ;
}
if ( V_33 < 0 && V_51 -> V_4 && V_51 -> V_4 -> V_77 ) {
char V_59 [ 256 ] ;
const char * V_78 = F_36 ( - V_33 , V_59 , sizeof( V_59 ) ) ,
* V_79 = F_37 ( - V_33 ) ;
printf ( L_31 , V_79 , V_78 ) ;
} else if ( V_33 == 0 && V_51 -> V_4 && V_51 -> V_4 -> V_80 )
printf ( L_32 ) ;
else
printf ( L_33 , V_33 ) ;
putchar ( '\n' ) ;
V_76:
V_17 -> V_74 = false ;
return 0 ;
}
static int F_38 ( struct V_21 * V_21 , struct V_67 * V_68 ,
struct V_39 * T_6 )
{
T_3 V_81 = F_31 ( V_68 , T_6 , L_34 ) ;
double V_82 = ( double ) V_81 / V_10 ;
struct V_16 * V_16 = F_33 ( & V_21 -> V_43 , T_6 -> V_71 ) ;
struct V_15 * V_17 = F_8 ( V_16 ) ;
if ( V_17 == NULL )
goto V_83;
V_17 -> V_82 += V_82 ;
V_21 -> V_82 += V_82 ;
return 0 ;
V_83:
printf ( L_35 V_36 L_36 V_36 L_37 ,
V_68 -> V_1 ,
F_39 ( V_68 , T_6 , L_38 ) ,
( V_84 ) F_31 ( V_68 , T_6 , L_39 ) ,
V_81 ,
F_31 ( V_68 , T_6 , L_40 ) ) ;
return 0 ;
}
static int F_40 ( struct V_21 * V_21 , int V_85 , const char * * V_86 )
{
struct V_40 * V_41 = F_41 () ;
struct V_67 * V_68 ;
int V_42 = - 1 , V_61 ;
unsigned long V_87 ;
const bool V_88 = V_85 > 0 ;
if ( V_41 == NULL ) {
printf ( L_41 ) ;
goto V_76;
}
if ( F_42 ( V_41 , L_42 , L_43 , F_32 ) ||
F_42 ( V_41 , L_42 , L_44 , F_35 ) ) {
printf ( L_45 ) ;
goto V_89;
}
if ( V_21 -> V_90 &&
F_42 ( V_41 , L_46 , L_47 ,
F_38 ) ) {
printf ( L_48 ) ;
goto V_89;
}
V_42 = F_43 ( V_41 , & V_21 -> V_45 . V_46 ) ;
if ( V_42 < 0 ) {
printf ( L_49 ) ;
goto V_89;
}
V_42 = F_17 ( V_21 , V_41 ) ;
if ( V_42 < 0 ) {
printf ( L_50 ) ;
goto V_91;
}
F_44 ( V_41 , & V_21 -> V_45 ) ;
signal ( V_92 , F_11 ) ;
signal ( V_93 , F_11 ) ;
if ( V_88 ) {
V_42 = F_45 ( V_41 , & V_21 -> V_45 . V_46 ,
V_86 , false , false ) ;
if ( V_42 < 0 ) {
printf ( L_51 ) ;
goto V_91;
}
}
V_42 = F_46 ( V_41 ) ;
if ( V_42 < 0 ) {
printf ( L_52 , strerror ( V_94 ) ) ;
goto V_91;
}
V_42 = F_47 ( V_41 , V_95 , false ) ;
if ( V_42 < 0 ) {
printf ( L_53 , strerror ( V_94 ) ) ;
goto V_96;
}
F_48 ( V_41 ) ;
if ( V_88 )
F_49 ( V_41 ) ;
V_21 -> V_28 = V_41 -> V_47 -> V_97 [ 0 ] == - 1 || V_41 -> V_47 -> V_98 > 1 ;
V_99:
V_87 = V_21 -> V_20 ;
for ( V_61 = 0 ; V_61 < V_41 -> V_100 ; V_61 ++ ) {
union V_31 * V_32 ;
while ( ( V_32 = F_50 ( V_41 , V_61 ) ) != NULL ) {
const T_7 type = V_32 -> V_34 . type ;
T_8 V_101 ;
struct V_39 T_6 ;
++ V_21 -> V_20 ;
V_42 = F_51 ( V_41 , V_32 , & T_6 ) ;
if ( V_42 ) {
printf ( L_54 , V_42 ) ;
continue;
}
if ( V_21 -> V_25 == 0 )
V_21 -> V_25 = T_6 . time ;
if ( type != V_102 ) {
F_13 ( & V_21 -> V_43 , V_32 ) ;
continue;
}
V_68 = F_52 ( V_41 , T_6 . V_48 ) ;
if ( V_68 == NULL ) {
printf ( L_55 V_36 L_56 , T_6 . V_48 ) ;
continue;
}
if ( T_6 . V_103 == NULL ) {
printf ( L_57 ,
F_53 ( V_68 ) , T_6 . V_71 ,
T_6 . V_104 , T_6 . V_105 ) ;
continue;
}
V_101 = V_68 -> V_101 . V_106 ;
V_101 ( V_21 , V_68 , & T_6 ) ;
}
}
if ( V_21 -> V_20 == V_87 ) {
if ( V_27 )
goto V_107;
F_54 ( V_41 -> V_108 , V_41 -> V_109 , - 1 ) ;
}
if ( V_27 )
F_55 ( V_41 ) ;
goto V_99;
V_107:
F_56 ( V_41 ) ;
V_96:
F_57 ( V_41 ) ;
V_91:
F_58 ( V_41 ) ;
V_89:
F_59 ( V_41 ) ;
V_76:
return V_42 ;
}
static T_1 F_60 ( T_2 * V_8 )
{
T_1 V_11 ;
V_11 = fprintf ( V_8 , L_58 ) ;
V_11 += fprintf ( V_8 , L_59 ) ;
V_11 += fprintf ( V_8 , L_60 ) ;
V_11 += fprintf ( V_8 , L_61 ) ;
return V_11 ;
}
static T_1 F_61 ( struct V_21 * V_21 , T_2 * V_8 )
{
T_1 V_11 = F_60 ( V_8 ) ;
struct V_110 * V_111 ;
for ( V_111 = F_62 ( & V_21 -> V_43 . V_47 ) ; V_111 ; V_111 = F_63 ( V_111 ) ) {
struct V_16 * V_16 = F_64 ( V_111 , struct V_16 , V_110 ) ;
struct V_15 * V_17 = V_16 -> V_19 ;
const char * V_112 ;
double V_113 ;
if ( V_17 == NULL )
continue;
V_113 = ( double ) V_17 -> V_20 / V_21 -> V_20 * 100.0 ;
V_112 = V_14 ;
if ( V_113 > 50.0 )
V_112 = V_12 ;
else if ( V_113 > 25.0 )
V_112 = V_114 ;
else if ( V_113 > 5.0 )
V_112 = V_13 ;
V_11 += F_5 ( V_8 , V_112 , L_62 , V_16 -> V_115 ) ;
V_11 += fprintf ( V_8 , L_63 , V_16 -> V_29 , V_17 -> V_20 ) ;
V_11 += F_5 ( V_8 , V_112 , L_64 , V_113 ) ;
V_11 += fprintf ( V_8 , L_65 , V_17 -> V_82 ) ;
}
return V_11 ;
}
static int F_65 ( const struct V_116 * V_117 , const char * V_118 ,
int T_9 V_26 )
{
struct V_21 * V_21 = V_117 -> V_119 ;
V_21 -> V_22 = atof ( V_118 ) ;
return 0 ;
}
int F_66 ( int V_85 , const char * * V_86 , const char * T_10 V_26 )
{
const char * const V_120 [] = {
L_66 ,
L_67 ,
NULL
} ;
struct V_21 V_21 = {
. V_52 = F_67 () ,
. V_53 = {
. V_54 = - 1 ,
} ,
. V_45 = {
. V_46 = {
. V_121 = V_95 ,
. V_122 = true ,
} ,
. V_123 = V_95 ,
. V_124 = V_125 ,
. V_126 = true ,
. V_127 = 1024 ,
} ,
} ;
const struct V_116 V_128 [] = {
F_68 ( 'p' , L_39 , & V_21 . V_45 . V_46 . V_29 , L_39 ,
L_68 ) ,
F_68 ( 0 , L_69 , & V_21 . V_45 . V_46 . V_71 , L_69 ,
L_70 ) ,
F_69 ( 0 , L_71 , & V_21 . V_45 . V_46 . V_129 ,
L_72 ) ,
F_68 ( 0 , L_73 , & V_21 . V_45 . V_46 . V_130 , L_73 ,
L_74 ) ,
F_69 ( 0 , L_75 , & V_21 . V_45 . V_131 ,
L_76 ) ,
F_70 ( 0 , L_77 , & V_21 . V_45 . V_127 ,
L_78 ) ,
F_68 ( 0 , L_79 , & V_21 . V_45 . V_46 . V_132 , L_80 ,
L_81 ) ,
F_71 ( 0 , L_82 , & V_21 , L_83 ,
L_84 ,
F_65 ) ,
F_69 ( 0 , L_46 , & V_21 . V_90 , L_85 ) ,
F_72 ()
} ;
int V_42 ;
char V_59 [ V_133 ] ;
V_85 = F_73 ( V_85 , V_86 , V_128 , V_120 , 0 ) ;
V_42 = F_74 ( & V_21 . V_45 . V_46 ) ;
if ( V_42 ) {
F_75 ( & V_21 . V_45 . V_46 , V_42 , V_59 , sizeof( V_59 ) ) ;
printf ( L_86 , V_59 ) ;
return V_42 ;
}
V_42 = F_76 ( & V_21 . V_45 . V_46 ) ;
if ( V_42 ) {
F_75 ( & V_21 . V_45 . V_46 , V_42 , V_59 , sizeof( V_59 ) ) ;
printf ( L_86 , V_59 ) ;
return V_42 ;
}
if ( ! V_85 && F_77 ( & V_21 . V_45 . V_46 ) )
V_21 . V_45 . V_46 . V_129 = true ;
V_42 = F_40 ( & V_21 , V_85 , V_86 ) ;
if ( V_21 . V_90 && ! V_42 )
F_61 ( & V_21 , stdout ) ;
return V_42 ;
}
