static int F_1 ( void )
{
T_1 * V_1 ;
int V_2 , V_3 = - 1 ;
V_1 = fopen ( L_1 , L_2 ) ;
if ( ! V_1 ) {
V_4 = 4096 ;
return 0 ;
}
if ( fscanf ( V_1 , L_3 , & V_4 ) < 1 ) {
F_2 ( L_4 ) ;
goto V_5;
}
V_4 ++ ;
V_6 = calloc ( V_4 , sizeof( int ) ) ;
if ( ! V_6 ) {
F_2 ( L_5 , V_7 ) ;
goto V_5;
}
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ )
V_6 [ V_2 ] = - 1 ;
V_3 = 0 ;
V_5:
fclose ( V_1 ) ;
return V_3 ;
}
static int F_3 ( void )
{
struct V_8 * V_9 , * V_10 ;
T_2 * V_11 , * V_12 ;
unsigned int V_13 , V_14 ;
char V_15 [ V_16 ] ;
if ( F_1 () )
return - 1 ;
V_11 = F_4 ( V_17 ) ;
if ( ! V_11 )
return - 1 ;
while ( ( V_9 = F_5 ( V_11 ) ) != NULL ) {
if ( V_9 -> V_18 != V_19 ||
sscanf ( V_9 -> V_20 , L_6 , & V_14 ) < 1 )
continue;
snprintf ( V_15 , V_16 , L_7 , V_17 , V_9 -> V_20 ) ;
V_12 = F_4 ( V_15 ) ;
if ( ! V_12 )
continue;
while ( ( V_10 = F_5 ( V_12 ) ) != NULL ) {
if ( V_10 -> V_18 != V_21 ||
sscanf ( V_10 -> V_20 , L_8 , & V_13 ) < 1 )
continue;
V_6 [ V_13 ] = V_14 ;
}
F_6 ( V_12 ) ;
}
F_6 ( V_11 ) ;
return 0 ;
}
static int F_7 ( unsigned long V_22 , unsigned long V_23 ,
int V_24 , int V_25 , int V_13 )
{
struct V_26 * * V_27 = & V_28 . V_26 ;
struct V_26 * V_29 = NULL ;
struct V_30 * V_31 = NULL ;
while ( * V_27 ) {
V_29 = * V_27 ;
V_31 = F_8 ( * V_27 , struct V_30 , V_27 ) ;
if ( V_23 > V_31 -> V_23 )
V_27 = & ( * V_27 ) -> V_32 ;
else if ( V_23 < V_31 -> V_23 )
V_27 = & ( * V_27 ) -> V_33 ;
else
break;
}
if ( V_31 && V_31 -> V_23 == V_23 ) {
V_31 -> V_34 ++ ;
V_31 -> V_24 += V_24 ;
V_31 -> V_25 += V_25 ;
} else {
V_31 = malloc ( sizeof( * V_31 ) ) ;
if ( ! V_31 ) {
F_2 ( L_9 , V_7 ) ;
return - 1 ;
}
V_31 -> V_23 = V_23 ;
V_31 -> V_35 = 0 ;
V_31 -> V_34 = 1 ;
V_31 -> V_24 = V_24 ;
V_31 -> V_25 = V_25 ;
F_9 ( & V_31 -> V_27 , V_29 , V_27 ) ;
F_10 ( & V_31 -> V_27 , & V_28 ) ;
}
V_31 -> V_22 = V_22 ;
V_31 -> V_36 = V_13 ;
return 0 ;
}
static int F_11 ( unsigned long V_22 ,
int V_24 , int V_25 )
{
struct V_26 * * V_27 = & V_37 . V_26 ;
struct V_26 * V_29 = NULL ;
struct V_30 * V_31 = NULL ;
while ( * V_27 ) {
V_29 = * V_27 ;
V_31 = F_8 ( * V_27 , struct V_30 , V_27 ) ;
if ( V_22 > V_31 -> V_22 )
V_27 = & ( * V_27 ) -> V_32 ;
else if ( V_22 < V_31 -> V_22 )
V_27 = & ( * V_27 ) -> V_33 ;
else
break;
}
if ( V_31 && V_31 -> V_22 == V_22 ) {
V_31 -> V_34 ++ ;
V_31 -> V_24 += V_24 ;
V_31 -> V_25 += V_25 ;
} else {
V_31 = malloc ( sizeof( * V_31 ) ) ;
if ( ! V_31 ) {
F_2 ( L_9 , V_7 ) ;
return - 1 ;
}
V_31 -> V_22 = V_22 ;
V_31 -> V_35 = 0 ;
V_31 -> V_34 = 1 ;
V_31 -> V_24 = V_24 ;
V_31 -> V_25 = V_25 ;
F_9 ( & V_31 -> V_27 , V_29 , V_27 ) ;
F_10 ( & V_31 -> V_27 , & V_37 ) ;
}
return 0 ;
}
static int F_12 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
unsigned long V_23 = F_13 ( V_39 , V_41 , L_10 ) ,
V_22 = F_13 ( V_39 , V_41 , L_11 ) ;
int V_24 = F_13 ( V_39 , V_41 , L_12 ) ,
V_25 = F_13 ( V_39 , V_41 , L_13 ) ;
if ( F_7 ( V_22 , V_23 , V_24 , V_25 , V_41 -> V_13 ) ||
F_11 ( V_22 , V_24 , V_25 ) )
return - 1 ;
V_42 += V_24 ;
V_43 += V_25 ;
V_44 ++ ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
int V_45 = F_12 ( V_39 , V_41 ) ;
if ( ! V_45 ) {
int V_46 = V_6 [ V_41 -> V_13 ] ,
V_47 = F_13 ( V_39 , V_41 , L_14 ) ;
if ( V_46 != V_47 )
V_48 ++ ;
}
return V_45 ;
}
static struct V_30 * F_15 ( unsigned long V_23 ,
unsigned long V_22 ,
struct V_49 * V_50 ,
T_3 V_51 )
{
struct V_26 * V_27 = V_50 -> V_26 ;
struct V_30 V_52 = { . V_23 = V_23 , . V_22 = V_22 } ;
while ( V_27 ) {
struct V_30 * V_31 ;
int V_53 ;
V_31 = F_8 ( V_27 , struct V_30 , V_27 ) ;
V_53 = V_51 ( & V_52 , V_31 ) ;
if ( V_53 < 0 )
V_27 = V_27 -> V_33 ;
else if ( V_53 > 0 )
V_27 = V_27 -> V_32 ;
else
return V_31 ;
}
return NULL ;
}
static int F_16 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
unsigned long V_23 = F_13 ( V_39 , V_41 , L_10 ) ;
struct V_30 * V_54 , * V_55 ;
V_54 = F_15 ( V_23 , 0 , & V_28 , V_56 ) ;
if ( ! V_54 )
return 0 ;
if ( ( short ) V_41 -> V_13 != V_54 -> V_36 ) {
V_54 -> V_35 ++ ;
V_55 = F_15 ( 0 , V_54 -> V_22 ,
& V_37 , V_57 ) ;
if ( ! V_55 )
return - 1 ;
V_55 -> V_35 ++ ;
}
V_54 -> V_36 = - 1 ;
return 0 ;
}
static int F_17 ( struct V_58 * T_4 V_59 ,
union V_60 * V_61 ,
struct V_40 * V_41 ,
struct V_38 * V_39 ,
struct V_62 * V_62 )
{
struct V_63 * V_63 = F_18 ( V_62 , V_61 -> V_64 . V_65 ) ;
if ( V_63 == NULL ) {
F_19 ( L_15 ,
V_61 -> V_66 . type ) ;
return - 1 ;
}
F_20 ( L_16 , V_63 -> V_67 , V_63 -> V_65 ) ;
if ( V_39 -> V_68 . V_69 != NULL ) {
T_5 V_70 = V_39 -> V_68 . V_69 ;
return V_70 ( V_39 , V_41 ) ;
}
return 0 ;
}
static double F_21 ( unsigned long V_71 , unsigned long V_72 )
{
if ( V_72 == 0 )
return 0.0 ;
else
return 100.0 - ( 100.0 * V_71 / V_72 ) ;
}
static void F_22 ( struct V_49 * V_50 , struct V_73 * V_74 ,
int V_75 , int V_76 )
{
struct V_26 * V_77 ;
struct V_62 * V_62 ;
printf ( L_17 , V_78 ) ;
printf ( L_18 , V_76 ? L_19 : L_20 ) ;
printf ( L_21 ) ;
printf ( L_17 , V_78 ) ;
V_77 = F_23 ( V_50 ) ;
V_62 = F_24 ( V_74 ) ;
if ( ! V_62 ) {
F_2 ( L_22 ) ;
return;
}
while ( V_77 && V_75 -- ) {
struct V_30 * V_31 = F_8 ( V_77 , struct V_30 ,
V_27 ) ;
struct V_79 * V_80 = NULL ;
struct V_81 * V_81 ;
char V_15 [ V_82 ] ;
T_6 V_83 ;
if ( V_76 ) {
V_83 = V_31 -> V_22 ;
if ( ! V_84 )
V_80 = F_25 ( V_62 , V_83 , & V_81 , NULL ) ;
} else
V_83 = V_31 -> V_23 ;
if ( V_80 != NULL )
snprintf ( V_15 , sizeof( V_15 ) , L_23 V_85 L_24 , V_80 -> V_86 ,
V_83 - V_81 -> V_87 ( V_81 , V_80 -> V_88 ) ) ;
else
snprintf ( V_15 , sizeof( V_15 ) , L_25 V_85 L_24 , V_83 ) ;
printf ( L_18 , V_15 ) ;
printf ( L_26 ,
( unsigned long long ) V_31 -> V_25 ,
( unsigned long ) V_31 -> V_25 / V_31 -> V_34 ,
( unsigned long long ) V_31 -> V_24 ,
( unsigned long ) V_31 -> V_24 / V_31 -> V_34 ,
( unsigned long ) V_31 -> V_34 ,
( unsigned long ) V_31 -> V_35 ,
F_21 ( V_31 -> V_24 , V_31 -> V_25 ) ) ;
V_77 = F_26 ( V_77 ) ;
}
if ( V_75 == - 1 )
printf ( L_27 ) ;
printf ( L_17 , V_78 ) ;
}
static void F_27 ( void )
{
printf ( L_28 ) ;
printf ( L_29 , V_42 ) ;
printf ( L_30 , V_43 ) ;
printf ( L_31 ,
V_43 - V_42 ) ;
printf ( L_32 ,
F_21 ( V_42 , V_43 ) ) ;
printf ( L_33 , V_48 , V_44 ) ;
}
static void F_28 ( struct V_73 * V_74 )
{
if ( V_89 )
F_22 ( & V_90 , V_74 , V_91 , 1 ) ;
if ( V_92 )
F_22 ( & V_93 , V_74 , V_94 , 0 ) ;
F_27 () ;
}
static void F_29 ( struct V_49 * V_50 , struct V_30 * V_31 ,
struct V_95 * V_96 )
{
struct V_26 * * V_97 = & ( V_50 -> V_26 ) ;
struct V_26 * V_29 = NULL ;
struct V_98 * V_99 ;
while ( * V_97 ) {
struct V_30 * V_100 ;
int V_53 = 0 ;
V_100 = F_8 ( * V_97 , struct V_30 , V_27 ) ;
V_29 = * V_97 ;
F_30 (sort, sort_list, list) {
V_53 = V_99 -> V_53 ( V_31 , V_100 ) ;
if ( V_53 )
break;
}
if ( V_53 > 0 )
V_97 = & ( ( * V_97 ) -> V_33 ) ;
else
V_97 = & ( ( * V_97 ) -> V_32 ) ;
}
F_9 ( & V_31 -> V_27 , V_29 , V_97 ) ;
F_10 ( & V_31 -> V_27 , V_50 ) ;
}
static void F_31 ( struct V_49 * V_50 , struct V_49 * V_101 ,
struct V_95 * V_96 )
{
struct V_26 * V_27 ;
struct V_30 * V_31 ;
for (; ; ) {
V_27 = F_23 ( V_50 ) ;
if ( ! V_27 )
break;
F_32 ( V_27 , V_50 ) ;
V_31 = F_8 ( V_27 , struct V_30 , V_27 ) ;
F_29 ( V_101 , V_31 , V_96 ) ;
}
}
static void F_33 ( void )
{
F_31 ( & V_28 , & V_93 , & V_102 ) ;
F_31 ( & V_37 , & V_90 , & V_103 ) ;
}
static int F_34 ( const char * V_104 )
{
int V_3 = - V_105 ;
struct V_73 * V_74 ;
const struct V_106 V_107 [] = {
{ L_34 , F_12 , } ,
{ L_35 , F_12 , } ,
{ L_36 , F_14 , } ,
{ L_37 , F_14 , } ,
{ L_38 , F_16 , } ,
{ L_39 , F_16 , } ,
} ;
V_74 = F_35 ( V_104 , V_108 , 0 , false , & V_109 ) ;
if ( V_74 == NULL )
return - V_110 ;
if ( F_36 ( V_74 ) < 0 )
goto V_111;
if ( ! F_37 ( V_74 , L_40 ) )
goto V_111;
if ( F_38 ( V_74 , V_107 ) ) {
F_2 ( L_41 ) ;
return - 1 ;
}
F_39 () ;
V_3 = F_40 ( V_74 , & V_109 ) ;
if ( V_3 != 0 )
goto V_111;
F_33 () ;
F_28 ( V_74 ) ;
V_111:
F_41 ( V_74 ) ;
return V_3 ;
}
static int V_56 ( struct V_30 * V_112 , struct V_30 * V_113 )
{
if ( V_112 -> V_23 < V_113 -> V_23 )
return - 1 ;
else if ( V_112 -> V_23 > V_113 -> V_23 )
return 1 ;
return 0 ;
}
static int V_57 ( struct V_30 * V_112 , struct V_30 * V_113 )
{
if ( V_112 -> V_22 < V_113 -> V_22 )
return - 1 ;
else if ( V_112 -> V_22 > V_113 -> V_22 )
return 1 ;
return 0 ;
}
static int F_42 ( struct V_30 * V_112 , struct V_30 * V_113 )
{
if ( V_112 -> V_34 < V_113 -> V_34 )
return - 1 ;
else if ( V_112 -> V_34 > V_113 -> V_34 )
return 1 ;
return 0 ;
}
static int F_43 ( struct V_30 * V_112 , struct V_30 * V_113 )
{
if ( V_112 -> V_25 < V_113 -> V_25 )
return - 1 ;
else if ( V_112 -> V_25 > V_113 -> V_25 )
return 1 ;
return 0 ;
}
static int F_44 ( struct V_30 * V_112 , struct V_30 * V_113 )
{
double V_114 , V_115 ;
V_114 = F_21 ( V_112 -> V_24 , V_112 -> V_25 ) ;
V_115 = F_21 ( V_113 -> V_24 , V_113 -> V_25 ) ;
if ( V_114 < V_115 )
return - 1 ;
else if ( V_114 > V_115 )
return 1 ;
return 0 ;
}
static int F_45 ( struct V_30 * V_112 , struct V_30 * V_113 )
{
if ( V_112 -> V_35 < V_113 -> V_35 )
return - 1 ;
else if ( V_112 -> V_35 > V_113 -> V_35 )
return 1 ;
return 0 ;
}
static int F_46 ( const char * V_116 , struct V_95 * V_117 )
{
struct V_98 * V_99 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_118 ; V_2 ++ ) {
if ( ! strcmp ( V_119 [ V_2 ] -> V_86 , V_116 ) ) {
V_99 = malloc ( sizeof( * V_99 ) ) ;
if ( ! V_99 ) {
F_2 ( L_9 , V_7 ) ;
return - 1 ;
}
memcpy ( V_99 , V_119 [ V_2 ] , sizeof( * V_99 ) ) ;
F_47 ( & V_99 -> V_117 , V_117 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_48 ( struct V_95 * V_96 , const char * V_120 )
{
char * V_116 ;
char * V_121 = F_49 ( V_120 ) ;
if ( ! V_121 ) {
F_2 ( L_42 , V_7 ) ;
return - 1 ;
}
while ( true ) {
V_116 = F_50 ( & V_121 , L_43 ) ;
if ( ! V_116 )
break;
if ( F_46 ( V_116 , V_96 ) < 0 ) {
error ( L_44 , V_116 ) ;
free ( V_121 ) ;
return - 1 ;
}
}
free ( V_121 ) ;
return 0 ;
}
static int F_51 ( const struct V_122 * T_7 V_59 ,
const char * V_120 , int T_8 V_59 )
{
if ( ! V_120 )
return - 1 ;
if ( V_89 > V_92 )
return F_48 ( & V_103 , V_120 ) ;
else
return F_48 ( & V_102 , V_120 ) ;
return 0 ;
}
static int F_52 ( const struct V_122 * T_7 V_59 ,
const char * V_120 V_59 ,
int T_8 V_59 )
{
V_89 = ( V_92 + 1 ) ;
return 0 ;
}
static int F_53 ( const struct V_122 * T_7 V_59 ,
const char * V_120 V_59 ,
int T_8 V_59 )
{
V_92 = ( V_89 + 1 ) ;
return 0 ;
}
static int F_54 ( const struct V_122 * T_7 V_59 ,
const char * V_120 , int T_8 V_59 )
{
int V_123 ;
if ( ! V_120 )
return - 1 ;
V_123 = strtoul ( V_120 , NULL , 10 ) ;
if ( V_89 > V_92 )
V_91 = V_123 ;
else
V_94 = V_123 ;
return 0 ;
}
static int F_55 ( int V_124 , const char * * V_125 )
{
const char * const V_126 [] = {
L_45 , L_46 , L_47 , L_48 , L_49 , L_50 ,
L_51 , L_34 ,
L_51 , L_36 ,
L_51 , L_38 ,
L_51 , L_35 ,
L_51 , L_37 ,
L_51 , L_39 ,
} ;
unsigned int V_127 , V_2 , V_128 ;
const char * * V_129 ;
V_127 = F_56 ( V_126 ) + V_124 - 1 ;
V_129 = calloc ( V_127 + 1 , sizeof( char * ) ) ;
if ( V_129 == NULL )
return - V_110 ;
for ( V_2 = 0 ; V_2 < F_56 ( V_126 ) ; V_2 ++ )
V_129 [ V_2 ] = F_49 ( V_126 [ V_2 ] ) ;
for ( V_128 = 1 ; V_128 < ( unsigned int ) V_124 ; V_128 ++ , V_2 ++ )
V_129 [ V_2 ] = V_125 [ V_128 ] ;
return F_57 ( V_2 , V_129 , NULL ) ;
}
int F_58 ( int V_124 , const char * * V_125 , const char * T_9 V_59 )
{
const char * const V_130 = L_52 ;
const char * V_104 = NULL ;
const struct V_122 V_131 [] = {
F_59 ( 'i' , L_53 , & V_104 , L_54 , L_55 ) ,
F_60 ( 0 , L_56 , NULL , NULL ,
L_57 , F_52 ) ,
F_60 ( 0 , L_58 , NULL , NULL ,
L_59 , F_53 ) ,
F_61 ( 's' , L_60 , NULL , L_61 ,
L_62 ,
F_51 ) ,
F_61 ( 'l' , L_63 , NULL , L_64 , L_65 , F_54 ) ,
F_62 ( 0 , L_66 , & V_84 , L_67 ) ,
F_63 ()
} ;
const char * const V_132 [] = {
L_68 ,
NULL
} ;
V_124 = F_64 ( V_124 , V_125 , V_131 , V_132 , 0 ) ;
if ( ! V_124 )
F_65 ( V_132 , V_131 ) ;
F_66 () ;
if ( ! strncmp ( V_125 [ 0 ] , L_69 , 3 ) ) {
return F_55 ( V_124 , V_125 ) ;
} else if ( ! strcmp ( V_125 [ 0 ] , L_70 ) ) {
if ( F_3 () )
return - 1 ;
if ( F_67 ( & V_103 ) )
F_48 ( & V_103 , V_130 ) ;
if ( F_67 ( & V_102 ) )
F_48 ( & V_102 , V_130 ) ;
return F_34 ( V_104 ) ;
} else
F_65 ( V_132 , V_131 ) ;
return 0 ;
}
