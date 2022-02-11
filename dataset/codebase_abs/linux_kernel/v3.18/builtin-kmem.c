static int F_1 ( unsigned long V_1 , unsigned long V_2 ,
int V_3 , int V_4 , int V_5 )
{
struct V_6 * * V_7 = & V_8 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
while ( * V_7 ) {
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_10 , V_7 ) ;
if ( V_2 > V_11 -> V_2 )
V_7 = & ( * V_7 ) -> V_12 ;
else if ( V_2 < V_11 -> V_2 )
V_7 = & ( * V_7 ) -> V_13 ;
else
break;
}
if ( V_11 && V_11 -> V_2 == V_2 ) {
V_11 -> V_14 ++ ;
V_11 -> V_3 += V_3 ;
V_11 -> V_4 += V_4 ;
} else {
V_11 = malloc ( sizeof( * V_11 ) ) ;
if ( ! V_11 ) {
F_3 ( L_1 , V_15 ) ;
return - 1 ;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_16 = 0 ;
V_11 -> V_14 = 1 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_4 = V_4 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_8 ) ;
}
V_11 -> V_1 = V_1 ;
V_11 -> V_17 = V_5 ;
return 0 ;
}
static int F_6 ( unsigned long V_1 ,
int V_3 , int V_4 )
{
struct V_6 * * V_7 = & V_18 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
while ( * V_7 ) {
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_10 , V_7 ) ;
if ( V_1 > V_11 -> V_1 )
V_7 = & ( * V_7 ) -> V_12 ;
else if ( V_1 < V_11 -> V_1 )
V_7 = & ( * V_7 ) -> V_13 ;
else
break;
}
if ( V_11 && V_11 -> V_1 == V_1 ) {
V_11 -> V_14 ++ ;
V_11 -> V_3 += V_3 ;
V_11 -> V_4 += V_4 ;
} else {
V_11 = malloc ( sizeof( * V_11 ) ) ;
if ( ! V_11 ) {
F_3 ( L_1 , V_15 ) ;
return - 1 ;
}
V_11 -> V_1 = V_1 ;
V_11 -> V_16 = 0 ;
V_11 -> V_14 = 1 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_4 = V_4 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_18 ) ;
}
return 0 ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
unsigned long V_2 = F_8 ( V_20 , V_22 , L_2 ) ,
V_1 = F_8 ( V_20 , V_22 , L_3 ) ;
int V_3 = F_8 ( V_20 , V_22 , L_4 ) ,
V_4 = F_8 ( V_20 , V_22 , L_5 ) ;
if ( F_1 ( V_1 , V_2 , V_3 , V_4 , V_22 -> V_5 ) ||
F_6 ( V_1 , V_3 , V_4 ) )
return - 1 ;
V_23 += V_3 ;
V_24 += V_4 ;
V_25 ++ ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
int V_26 = F_7 ( V_20 , V_22 ) ;
if ( ! V_26 ) {
int V_27 = F_10 ( V_22 -> V_5 ) ,
V_28 = F_8 ( V_20 , V_22 , L_6 ) ;
if ( V_27 != V_28 )
V_29 ++ ;
}
return V_26 ;
}
static struct V_10 * F_11 ( unsigned long V_2 ,
unsigned long V_1 ,
struct V_30 * V_31 ,
T_1 V_32 )
{
struct V_6 * V_7 = V_31 -> V_6 ;
struct V_10 V_33 = { . V_2 = V_2 , . V_1 = V_1 } ;
while ( V_7 ) {
struct V_10 * V_11 ;
int V_34 ;
V_11 = F_2 ( V_7 , struct V_10 , V_7 ) ;
V_34 = V_32 ( & V_33 , V_11 ) ;
if ( V_34 < 0 )
V_7 = V_7 -> V_13 ;
else if ( V_34 > 0 )
V_7 = V_7 -> V_12 ;
else
return V_11 ;
}
return NULL ;
}
static int F_12 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
unsigned long V_2 = F_8 ( V_20 , V_22 , L_2 ) ;
struct V_10 * V_35 , * V_36 ;
V_35 = F_11 ( V_2 , 0 , & V_8 , V_37 ) ;
if ( ! V_35 )
return 0 ;
if ( ( short ) V_22 -> V_5 != V_35 -> V_17 ) {
V_35 -> V_16 ++ ;
V_36 = F_11 ( 0 , V_35 -> V_1 ,
& V_18 , V_38 ) ;
if ( ! V_36 )
return - 1 ;
V_36 -> V_16 ++ ;
}
V_35 -> V_17 = - 1 ;
return 0 ;
}
static int F_13 ( struct V_39 * T_2 V_40 ,
union V_41 * V_42 ,
struct V_21 * V_22 ,
struct V_19 * V_20 ,
struct V_43 * V_43 )
{
struct V_44 * V_44 = F_14 ( V_43 , V_22 -> V_45 ,
V_22 -> V_46 ) ;
if ( V_44 == NULL ) {
F_15 ( L_7 ,
V_42 -> V_47 . type ) ;
return - 1 ;
}
F_16 ( L_8 , F_17 ( V_44 ) , V_44 -> V_46 ) ;
if ( V_20 -> V_48 != NULL ) {
T_3 V_49 = V_20 -> V_48 ;
return V_49 ( V_20 , V_22 ) ;
}
return 0 ;
}
static double F_18 ( unsigned long V_50 , unsigned long V_51 )
{
if ( V_51 == 0 )
return 0.0 ;
else
return 100.0 - ( 100.0 * V_50 / V_51 ) ;
}
static void F_19 ( struct V_30 * V_31 , struct V_52 * V_53 ,
int V_54 , int V_55 )
{
struct V_6 * V_56 ;
struct V_43 * V_43 = & V_53 -> V_57 . V_58 ;
printf ( L_9 , V_59 ) ;
printf ( L_10 , V_55 ? L_11 : L_12 ) ;
printf ( L_13 ) ;
printf ( L_9 , V_59 ) ;
V_56 = F_20 ( V_31 ) ;
while ( V_56 && V_54 -- ) {
struct V_10 * V_11 = F_2 ( V_56 , struct V_10 ,
V_7 ) ;
struct V_60 * V_61 = NULL ;
struct V_62 * V_62 ;
char V_63 [ V_64 ] ;
T_4 V_65 ;
if ( V_55 ) {
V_65 = V_11 -> V_1 ;
if ( ! V_66 )
V_61 = F_21 ( V_43 , V_65 , & V_62 , NULL ) ;
} else
V_65 = V_11 -> V_2 ;
if ( V_61 != NULL )
snprintf ( V_63 , sizeof( V_63 ) , L_14 V_67 L_15 , V_61 -> V_68 ,
V_65 - V_62 -> V_69 ( V_62 , V_61 -> V_70 ) ) ;
else
snprintf ( V_63 , sizeof( V_63 ) , L_16 V_67 L_15 , V_65 ) ;
printf ( L_10 , V_63 ) ;
printf ( L_17 ,
( unsigned long long ) V_11 -> V_4 ,
( unsigned long ) V_11 -> V_4 / V_11 -> V_14 ,
( unsigned long long ) V_11 -> V_3 ,
( unsigned long ) V_11 -> V_3 / V_11 -> V_14 ,
( unsigned long ) V_11 -> V_14 ,
( unsigned long ) V_11 -> V_16 ,
F_18 ( V_11 -> V_3 , V_11 -> V_4 ) ) ;
V_56 = F_22 ( V_56 ) ;
}
if ( V_54 == - 1 )
printf ( L_18 ) ;
printf ( L_9 , V_59 ) ;
}
static void F_23 ( void )
{
printf ( L_19 ) ;
printf ( L_20 , V_23 ) ;
printf ( L_21 , V_24 ) ;
printf ( L_22 ,
V_24 - V_23 ) ;
printf ( L_23 ,
F_18 ( V_23 , V_24 ) ) ;
printf ( L_24 , V_29 , V_25 ) ;
}
static void F_24 ( struct V_52 * V_53 )
{
if ( V_71 )
F_19 ( & V_72 , V_53 , V_73 , 1 ) ;
if ( V_74 )
F_19 ( & V_75 , V_53 , V_76 , 0 ) ;
F_23 () ;
}
static void F_25 ( struct V_30 * V_31 , struct V_10 * V_11 ,
struct V_77 * V_78 )
{
struct V_6 * * V_79 = & ( V_31 -> V_6 ) ;
struct V_6 * V_9 = NULL ;
struct V_80 * V_81 ;
while ( * V_79 ) {
struct V_10 * V_82 ;
int V_34 = 0 ;
V_82 = F_2 ( * V_79 , struct V_10 , V_7 ) ;
V_9 = * V_79 ;
F_26 (sort, sort_list, list) {
V_34 = V_81 -> V_34 ( V_11 , V_82 ) ;
if ( V_34 )
break;
}
if ( V_34 > 0 )
V_79 = & ( ( * V_79 ) -> V_13 ) ;
else
V_79 = & ( ( * V_79 ) -> V_12 ) ;
}
F_4 ( & V_11 -> V_7 , V_9 , V_79 ) ;
F_5 ( & V_11 -> V_7 , V_31 ) ;
}
static void F_27 ( struct V_30 * V_31 , struct V_30 * V_83 ,
struct V_77 * V_78 )
{
struct V_6 * V_7 ;
struct V_10 * V_11 ;
for (; ; ) {
V_7 = F_20 ( V_31 ) ;
if ( ! V_7 )
break;
F_28 ( V_7 , V_31 ) ;
V_11 = F_2 ( V_7 , struct V_10 , V_7 ) ;
F_25 ( V_83 , V_11 , V_78 ) ;
}
}
static void F_29 ( void )
{
F_27 ( & V_8 , & V_75 , & V_84 ) ;
F_27 ( & V_18 , & V_72 , & V_85 ) ;
}
static int F_30 ( struct V_52 * V_53 )
{
int V_86 = - V_87 ;
const struct V_88 V_89 [] = {
{ L_25 , F_7 , } ,
{ L_26 , F_7 , } ,
{ L_27 , F_9 , } ,
{ L_28 , F_9 , } ,
{ L_29 , F_12 , } ,
{ L_30 , F_12 , } ,
} ;
if ( ! F_31 ( V_53 , L_31 ) )
goto V_90;
if ( F_32 ( V_53 , V_89 ) ) {
F_3 ( L_32 ) ;
goto V_90;
}
F_33 () ;
V_86 = F_34 ( V_53 , & V_91 ) ;
if ( V_86 != 0 )
goto V_90;
F_29 () ;
F_24 ( V_53 ) ;
V_90:
return V_86 ;
}
static int V_37 ( struct V_10 * V_92 , struct V_10 * V_93 )
{
if ( V_92 -> V_2 < V_93 -> V_2 )
return - 1 ;
else if ( V_92 -> V_2 > V_93 -> V_2 )
return 1 ;
return 0 ;
}
static int V_38 ( struct V_10 * V_92 , struct V_10 * V_93 )
{
if ( V_92 -> V_1 < V_93 -> V_1 )
return - 1 ;
else if ( V_92 -> V_1 > V_93 -> V_1 )
return 1 ;
return 0 ;
}
static int F_35 ( struct V_10 * V_92 , struct V_10 * V_93 )
{
if ( V_92 -> V_14 < V_93 -> V_14 )
return - 1 ;
else if ( V_92 -> V_14 > V_93 -> V_14 )
return 1 ;
return 0 ;
}
static int F_36 ( struct V_10 * V_92 , struct V_10 * V_93 )
{
if ( V_92 -> V_4 < V_93 -> V_4 )
return - 1 ;
else if ( V_92 -> V_4 > V_93 -> V_4 )
return 1 ;
return 0 ;
}
static int F_37 ( struct V_10 * V_92 , struct V_10 * V_93 )
{
double V_94 , V_95 ;
V_94 = F_18 ( V_92 -> V_3 , V_92 -> V_4 ) ;
V_95 = F_18 ( V_93 -> V_3 , V_93 -> V_4 ) ;
if ( V_94 < V_95 )
return - 1 ;
else if ( V_94 > V_95 )
return 1 ;
return 0 ;
}
static int F_38 ( struct V_10 * V_92 , struct V_10 * V_93 )
{
if ( V_92 -> V_16 < V_93 -> V_16 )
return - 1 ;
else if ( V_92 -> V_16 > V_93 -> V_16 )
return 1 ;
return 0 ;
}
static int F_39 ( const char * V_96 , struct V_77 * V_97 )
{
struct V_80 * V_81 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_99 ; V_98 ++ ) {
if ( ! strcmp ( V_100 [ V_98 ] -> V_68 , V_96 ) ) {
V_81 = F_40 ( V_100 [ V_98 ] , sizeof( * V_100 [ V_98 ] ) ) ;
if ( ! V_81 ) {
F_3 ( L_33 , V_15 ) ;
return - 1 ;
}
F_41 ( & V_81 -> V_97 , V_97 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_42 ( struct V_77 * V_78 , const char * V_101 )
{
char * V_96 ;
char * V_102 = F_43 ( V_101 ) ;
if ( ! V_102 ) {
F_3 ( L_34 , V_15 ) ;
return - 1 ;
}
while ( true ) {
V_96 = F_44 ( & V_102 , L_35 ) ;
if ( ! V_96 )
break;
if ( F_39 ( V_96 , V_78 ) < 0 ) {
error ( L_36 , V_96 ) ;
free ( V_102 ) ;
return - 1 ;
}
}
free ( V_102 ) ;
return 0 ;
}
static int F_45 ( const struct V_103 * T_5 V_40 ,
const char * V_101 , int T_6 V_40 )
{
if ( ! V_101 )
return - 1 ;
if ( V_71 > V_74 )
return F_42 ( & V_85 , V_101 ) ;
else
return F_42 ( & V_84 , V_101 ) ;
return 0 ;
}
static int F_46 ( const struct V_103 * T_5 V_40 ,
const char * V_101 V_40 ,
int T_6 V_40 )
{
V_71 = ( V_74 + 1 ) ;
return 0 ;
}
static int F_47 ( const struct V_103 * T_5 V_40 ,
const char * V_101 V_40 ,
int T_6 V_40 )
{
V_74 = ( V_71 + 1 ) ;
return 0 ;
}
static int F_48 ( const struct V_103 * T_5 V_40 ,
const char * V_101 , int T_6 V_40 )
{
int V_104 ;
if ( ! V_101 )
return - 1 ;
V_104 = strtoul ( V_101 , NULL , 10 ) ;
if ( V_71 > V_74 )
V_73 = V_104 ;
else
V_76 = V_104 ;
return 0 ;
}
static int F_49 ( int V_105 , const char * * V_106 )
{
const char * const V_107 [] = {
L_37 , L_38 , L_39 , L_40 , L_41 ,
L_42 , L_25 ,
L_42 , L_27 ,
L_42 , L_29 ,
L_42 , L_26 ,
L_42 , L_28 ,
L_42 , L_30 ,
} ;
unsigned int V_108 , V_98 , V_109 ;
const char * * V_110 ;
V_108 = F_50 ( V_107 ) + V_105 - 1 ;
V_110 = calloc ( V_108 + 1 , sizeof( char * ) ) ;
if ( V_110 == NULL )
return - V_111 ;
for ( V_98 = 0 ; V_98 < F_50 ( V_107 ) ; V_98 ++ )
V_110 [ V_98 ] = F_43 ( V_107 [ V_98 ] ) ;
for ( V_109 = 1 ; V_109 < ( unsigned int ) V_105 ; V_109 ++ , V_98 ++ )
V_110 [ V_98 ] = V_106 [ V_109 ] ;
return F_51 ( V_98 , V_110 , NULL ) ;
}
int F_52 ( int V_105 , const char * * V_106 , const char * T_7 V_40 )
{
const char * const V_112 = L_43 ;
const struct V_103 V_113 [] = {
F_53 ( 'i' , L_44 , & V_114 , L_45 , L_46 ) ,
F_54 ( 0 , L_47 , NULL , NULL ,
L_48 , F_46 ) ,
F_54 ( 0 , L_49 , NULL , NULL ,
L_50 , F_47 ) ,
F_55 ( 's' , L_51 , NULL , L_52 ,
L_53 ,
F_45 ) ,
F_55 ( 'l' , L_54 , NULL , L_55 , L_56 , F_48 ) ,
F_56 ( 0 , L_57 , & V_66 , L_58 ) ,
F_57 ()
} ;
const char * const V_115 [] = { L_37 , L_59 , NULL } ;
const char * V_116 [] = {
NULL ,
NULL
} ;
struct V_52 * V_53 ;
struct V_117 V_118 = {
. V_119 = V_114 ,
. V_120 = V_121 ,
} ;
int V_26 = - 1 ;
V_105 = F_58 ( V_105 , V_106 , V_113 ,
V_115 , V_116 , 0 ) ;
if ( ! V_105 )
F_59 ( V_116 , V_113 ) ;
if ( ! strncmp ( V_106 [ 0 ] , L_60 , 3 ) ) {
F_60 ( NULL ) ;
return F_49 ( V_105 , V_106 ) ;
}
V_53 = F_61 ( & V_118 , false , & V_91 ) ;
if ( V_53 == NULL )
return - 1 ;
F_60 ( & V_53 -> V_47 . V_122 ) ;
if ( ! strcmp ( V_106 [ 0 ] , L_59 ) ) {
if ( F_62 () )
goto V_123;
if ( F_63 ( & V_85 ) )
F_42 ( & V_85 , V_112 ) ;
if ( F_63 ( & V_84 ) )
F_42 ( & V_84 , V_112 ) ;
V_26 = F_30 ( V_53 ) ;
} else
F_59 ( V_116 , V_113 ) ;
V_123:
F_64 ( V_53 ) ;
return V_26 ;
}
