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
static int F_30 ( void )
{
int V_86 = - V_87 ;
struct V_52 * V_53 ;
const struct V_88 V_89 [] = {
{ L_25 , F_7 , } ,
{ L_26 , F_7 , } ,
{ L_27 , F_9 , } ,
{ L_28 , F_9 , } ,
{ L_29 , F_12 , } ,
{ L_30 , F_12 , } ,
} ;
struct V_90 V_91 = {
. V_92 = V_93 ,
. V_94 = V_95 ,
} ;
V_53 = F_31 ( & V_91 , false , & V_96 ) ;
if ( V_53 == NULL )
return - V_97 ;
if ( F_32 ( V_53 ) < 0 )
goto V_98;
if ( ! F_33 ( V_53 , L_31 ) )
goto V_98;
if ( F_34 ( V_53 , V_89 ) ) {
F_3 ( L_32 ) ;
return - 1 ;
}
F_35 () ;
V_86 = F_36 ( V_53 , & V_96 ) ;
if ( V_86 != 0 )
goto V_98;
F_29 () ;
F_24 ( V_53 ) ;
V_98:
F_37 ( V_53 ) ;
return V_86 ;
}
static int V_37 ( struct V_10 * V_99 , struct V_10 * V_100 )
{
if ( V_99 -> V_2 < V_100 -> V_2 )
return - 1 ;
else if ( V_99 -> V_2 > V_100 -> V_2 )
return 1 ;
return 0 ;
}
static int V_38 ( struct V_10 * V_99 , struct V_10 * V_100 )
{
if ( V_99 -> V_1 < V_100 -> V_1 )
return - 1 ;
else if ( V_99 -> V_1 > V_100 -> V_1 )
return 1 ;
return 0 ;
}
static int F_38 ( struct V_10 * V_99 , struct V_10 * V_100 )
{
if ( V_99 -> V_14 < V_100 -> V_14 )
return - 1 ;
else if ( V_99 -> V_14 > V_100 -> V_14 )
return 1 ;
return 0 ;
}
static int F_39 ( struct V_10 * V_99 , struct V_10 * V_100 )
{
if ( V_99 -> V_4 < V_100 -> V_4 )
return - 1 ;
else if ( V_99 -> V_4 > V_100 -> V_4 )
return 1 ;
return 0 ;
}
static int F_40 ( struct V_10 * V_99 , struct V_10 * V_100 )
{
double V_101 , V_102 ;
V_101 = F_18 ( V_99 -> V_3 , V_99 -> V_4 ) ;
V_102 = F_18 ( V_100 -> V_3 , V_100 -> V_4 ) ;
if ( V_101 < V_102 )
return - 1 ;
else if ( V_101 > V_102 )
return 1 ;
return 0 ;
}
static int F_41 ( struct V_10 * V_99 , struct V_10 * V_100 )
{
if ( V_99 -> V_16 < V_100 -> V_16 )
return - 1 ;
else if ( V_99 -> V_16 > V_100 -> V_16 )
return 1 ;
return 0 ;
}
static int F_42 ( const char * V_103 , struct V_77 * V_104 )
{
struct V_80 * V_81 ;
int V_105 ;
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ ) {
if ( ! strcmp ( V_107 [ V_105 ] -> V_68 , V_103 ) ) {
V_81 = F_43 ( V_107 [ V_105 ] , sizeof( * V_107 [ V_105 ] ) ) ;
if ( ! V_81 ) {
F_3 ( L_33 , V_15 ) ;
return - 1 ;
}
F_44 ( & V_81 -> V_104 , V_104 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_45 ( struct V_77 * V_78 , const char * V_108 )
{
char * V_103 ;
char * V_109 = F_46 ( V_108 ) ;
if ( ! V_109 ) {
F_3 ( L_34 , V_15 ) ;
return - 1 ;
}
while ( true ) {
V_103 = F_47 ( & V_109 , L_35 ) ;
if ( ! V_103 )
break;
if ( F_42 ( V_103 , V_78 ) < 0 ) {
error ( L_36 , V_103 ) ;
free ( V_109 ) ;
return - 1 ;
}
}
free ( V_109 ) ;
return 0 ;
}
static int F_48 ( const struct V_110 * T_5 V_40 ,
const char * V_108 , int T_6 V_40 )
{
if ( ! V_108 )
return - 1 ;
if ( V_71 > V_74 )
return F_45 ( & V_85 , V_108 ) ;
else
return F_45 ( & V_84 , V_108 ) ;
return 0 ;
}
static int F_49 ( const struct V_110 * T_5 V_40 ,
const char * V_108 V_40 ,
int T_6 V_40 )
{
V_71 = ( V_74 + 1 ) ;
return 0 ;
}
static int F_50 ( const struct V_110 * T_5 V_40 ,
const char * V_108 V_40 ,
int T_6 V_40 )
{
V_74 = ( V_71 + 1 ) ;
return 0 ;
}
static int F_51 ( const struct V_110 * T_5 V_40 ,
const char * V_108 , int T_6 V_40 )
{
int V_111 ;
if ( ! V_108 )
return - 1 ;
V_111 = strtoul ( V_108 , NULL , 10 ) ;
if ( V_71 > V_74 )
V_73 = V_111 ;
else
V_76 = V_111 ;
return 0 ;
}
static int F_52 ( int V_112 , const char * * V_113 )
{
const char * const V_114 [] = {
L_37 , L_38 , L_39 , L_40 , L_41 ,
L_42 , L_25 ,
L_42 , L_27 ,
L_42 , L_29 ,
L_42 , L_26 ,
L_42 , L_28 ,
L_42 , L_30 ,
} ;
unsigned int V_115 , V_105 , V_116 ;
const char * * V_117 ;
V_115 = F_53 ( V_114 ) + V_112 - 1 ;
V_117 = calloc ( V_115 + 1 , sizeof( char * ) ) ;
if ( V_117 == NULL )
return - V_97 ;
for ( V_105 = 0 ; V_105 < F_53 ( V_114 ) ; V_105 ++ )
V_117 [ V_105 ] = F_46 ( V_114 [ V_105 ] ) ;
for ( V_116 = 1 ; V_116 < ( unsigned int ) V_112 ; V_116 ++ , V_105 ++ )
V_117 [ V_105 ] = V_113 [ V_116 ] ;
return F_54 ( V_105 , V_117 , NULL ) ;
}
int F_55 ( int V_112 , const char * * V_113 , const char * T_7 V_40 )
{
const char * const V_118 = L_43 ;
const struct V_110 V_119 [] = {
F_56 ( 'i' , L_44 , & V_93 , L_45 , L_46 ) ,
F_57 ( 0 , L_47 , NULL , NULL ,
L_48 , F_49 ) ,
F_57 ( 0 , L_49 , NULL , NULL ,
L_50 , F_50 ) ,
F_58 ( 's' , L_51 , NULL , L_52 ,
L_53 ,
F_48 ) ,
F_58 ( 'l' , L_54 , NULL , L_55 , L_56 , F_51 ) ,
F_59 ( 0 , L_57 , & V_66 , L_58 ) ,
F_60 ()
} ;
const char * const V_120 [] = { L_37 , L_59 , NULL } ;
const char * V_121 [] = {
NULL ,
NULL
} ;
V_112 = F_61 ( V_112 , V_113 , V_119 ,
V_120 , V_121 , 0 ) ;
if ( ! V_112 )
F_62 ( V_121 , V_119 ) ;
F_63 () ;
if ( ! strncmp ( V_113 [ 0 ] , L_60 , 3 ) ) {
return F_52 ( V_112 , V_113 ) ;
} else if ( ! strcmp ( V_113 [ 0 ] , L_59 ) ) {
if ( F_64 () )
return - 1 ;
if ( F_65 ( & V_85 ) )
F_45 ( & V_85 , V_118 ) ;
if ( F_65 ( & V_84 ) )
F_45 ( & V_84 , V_118 ) ;
return F_30 () ;
} else
F_62 ( V_121 , V_119 ) ;
return 0 ;
}
