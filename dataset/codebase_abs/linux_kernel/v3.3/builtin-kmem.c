static void F_1 ( void )
{
T_1 * V_1 ;
int V_2 ;
V_1 = fopen ( L_1 , L_2 ) ;
if ( ! V_1 ) {
V_3 = 4096 ;
return;
}
if ( fscanf ( V_1 , L_3 , & V_3 ) < 1 )
F_2 ( L_4 ) ;
V_3 ++ ;
V_4 = calloc ( V_3 , sizeof( int ) ) ;
if ( ! V_4 )
F_2 ( L_5 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_4 [ V_2 ] = - 1 ;
fclose ( V_1 ) ;
}
static void F_3 ( void )
{
struct V_5 * V_6 , * V_7 ;
T_2 * V_8 , * V_9 ;
unsigned int V_10 , V_11 ;
char V_12 [ V_13 ] ;
F_1 () ;
V_8 = F_4 ( V_14 ) ;
if ( ! V_8 )
return;
while ( ( V_6 = F_5 ( V_8 ) ) != NULL ) {
if ( V_6 -> V_15 != V_16 ||
sscanf ( V_6 -> V_17 , L_6 , & V_11 ) < 1 )
continue;
snprintf ( V_12 , V_13 , L_7 , V_14 , V_6 -> V_17 ) ;
V_9 = F_4 ( V_12 ) ;
if ( ! V_9 )
continue;
while ( ( V_7 = F_5 ( V_9 ) ) != NULL ) {
if ( V_7 -> V_15 != V_18 ||
sscanf ( V_7 -> V_17 , L_8 , & V_10 ) < 1 )
continue;
V_4 [ V_10 ] = V_11 ;
}
F_6 ( V_9 ) ;
}
F_6 ( V_8 ) ;
}
static void F_7 ( unsigned long V_19 , unsigned long V_20 ,
int V_21 , int V_22 , int V_10 )
{
struct V_23 * * V_24 = & V_25 . V_23 ;
struct V_23 * V_26 = NULL ;
struct V_27 * V_28 = NULL ;
while ( * V_24 ) {
V_26 = * V_24 ;
V_28 = F_8 ( * V_24 , struct V_27 , V_24 ) ;
if ( V_20 > V_28 -> V_20 )
V_24 = & ( * V_24 ) -> V_29 ;
else if ( V_20 < V_28 -> V_20 )
V_24 = & ( * V_24 ) -> V_30 ;
else
break;
}
if ( V_28 && V_28 -> V_20 == V_20 ) {
V_28 -> V_31 ++ ;
V_28 -> V_21 += V_21 ;
V_28 -> V_22 += V_22 ;
} else {
V_28 = malloc ( sizeof( * V_28 ) ) ;
if ( ! V_28 )
F_2 ( L_9 ) ;
V_28 -> V_20 = V_20 ;
V_28 -> V_32 = 0 ;
V_28 -> V_31 = 1 ;
V_28 -> V_21 = V_21 ;
V_28 -> V_22 = V_22 ;
F_9 ( & V_28 -> V_24 , V_26 , V_24 ) ;
F_10 ( & V_28 -> V_24 , & V_25 ) ;
}
V_28 -> V_19 = V_19 ;
V_28 -> V_33 = V_10 ;
}
static void F_11 ( unsigned long V_19 ,
int V_21 , int V_22 )
{
struct V_23 * * V_24 = & V_34 . V_23 ;
struct V_23 * V_26 = NULL ;
struct V_27 * V_28 = NULL ;
while ( * V_24 ) {
V_26 = * V_24 ;
V_28 = F_8 ( * V_24 , struct V_27 , V_24 ) ;
if ( V_19 > V_28 -> V_19 )
V_24 = & ( * V_24 ) -> V_29 ;
else if ( V_19 < V_28 -> V_19 )
V_24 = & ( * V_24 ) -> V_30 ;
else
break;
}
if ( V_28 && V_28 -> V_19 == V_19 ) {
V_28 -> V_31 ++ ;
V_28 -> V_21 += V_21 ;
V_28 -> V_22 += V_22 ;
} else {
V_28 = malloc ( sizeof( * V_28 ) ) ;
if ( ! V_28 )
F_2 ( L_9 ) ;
V_28 -> V_19 = V_19 ;
V_28 -> V_32 = 0 ;
V_28 -> V_31 = 1 ;
V_28 -> V_21 = V_21 ;
V_28 -> V_22 = V_22 ;
F_9 ( & V_28 -> V_24 , V_26 , V_24 ) ;
F_10 ( & V_28 -> V_24 , & V_34 ) ;
}
}
static void F_12 ( void * V_28 ,
struct V_35 * V_35 ,
int V_10 ,
T_3 T_4 V_36 ,
struct V_37 * V_37 V_36 ,
int V_24 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_21 ;
int V_22 ;
int V_38 , V_39 ;
V_20 = F_13 ( V_35 , L_10 , V_28 ) ;
V_19 = F_13 ( V_35 , L_11 , V_28 ) ;
V_21 = F_13 ( V_35 , L_12 , V_28 ) ;
V_22 = F_13 ( V_35 , L_13 , V_28 ) ;
F_7 ( V_19 , V_20 , V_21 , V_22 , V_10 ) ;
F_11 ( V_19 , V_21 , V_22 ) ;
V_40 += V_21 ;
V_41 += V_22 ;
if ( V_24 ) {
V_38 = V_4 [ V_10 ] ;
V_39 = F_13 ( V_35 , L_14 , V_28 ) ;
if ( V_38 != V_39 )
V_42 ++ ;
}
V_43 ++ ;
}
static struct V_27 * F_14 ( unsigned long V_20 ,
unsigned long V_19 ,
struct V_44 * V_45 ,
T_5 V_46 )
{
struct V_23 * V_24 = V_45 -> V_23 ;
struct V_27 V_47 = { . V_20 = V_20 , . V_19 = V_19 } ;
while ( V_24 ) {
struct V_27 * V_28 ;
int V_48 ;
V_28 = F_8 ( V_24 , struct V_27 , V_24 ) ;
V_48 = V_46 ( & V_47 , V_28 ) ;
if ( V_48 < 0 )
V_24 = V_24 -> V_30 ;
else if ( V_48 > 0 )
V_24 = V_24 -> V_29 ;
else
return V_28 ;
}
return NULL ;
}
static void F_15 ( void * V_28 ,
struct V_35 * V_35 ,
int V_10 ,
T_3 T_4 V_36 ,
struct V_37 * V_37 V_36 )
{
unsigned long V_20 ;
struct V_27 * V_49 , * V_50 ;
V_20 = F_13 ( V_35 , L_10 , V_28 ) ;
V_49 = F_14 ( V_20 , 0 , & V_25 , V_51 ) ;
if ( ! V_49 )
return;
if ( V_10 != V_49 -> V_33 ) {
V_49 -> V_32 ++ ;
V_50 = F_14 ( 0 , V_49 -> V_19 ,
& V_34 , V_52 ) ;
assert ( V_50 ) ;
V_50 -> V_32 ++ ;
}
V_49 -> V_33 = - 1 ;
}
static void F_16 ( union V_53 * T_6 V_36 , void * V_28 ,
int V_10 , T_3 T_4 , struct V_37 * V_37 )
{
struct V_35 * V_35 ;
int type ;
type = F_17 ( V_28 ) ;
V_35 = F_18 ( type ) ;
if ( ! strcmp ( V_35 -> V_54 , L_15 ) ||
! strcmp ( V_35 -> V_54 , L_16 ) ) {
F_12 ( V_28 , V_35 , V_10 , T_4 , V_37 , 0 ) ;
return;
}
if ( ! strcmp ( V_35 -> V_54 , L_17 ) ||
! strcmp ( V_35 -> V_54 , L_18 ) ) {
F_12 ( V_28 , V_35 , V_10 , T_4 , V_37 , 1 ) ;
return;
}
if ( ! strcmp ( V_35 -> V_54 , L_19 ) ||
! strcmp ( V_35 -> V_54 , L_20 ) ) {
F_15 ( V_28 , V_35 , V_10 , T_4 , V_37 ) ;
return;
}
}
static int F_19 ( struct V_55 * T_7 V_36 ,
union V_53 * V_35 ,
struct V_56 * V_57 ,
struct V_58 * T_8 V_36 ,
struct V_59 * V_59 )
{
struct V_37 * V_37 = F_20 ( V_59 , V_35 -> V_60 . V_61 ) ;
if ( V_37 == NULL ) {
F_21 ( L_21 ,
V_35 -> V_62 . type ) ;
return - 1 ;
}
F_22 ( L_22 , V_37 -> V_63 , V_37 -> V_61 ) ;
F_16 ( V_35 , V_57 -> V_64 , V_57 -> V_10 ,
V_57 -> time , V_37 ) ;
return 0 ;
}
static double F_23 ( unsigned long V_65 , unsigned long V_66 )
{
if ( V_66 == 0 )
return 0.0 ;
else
return 100.0 - ( 100.0 * V_65 / V_66 ) ;
}
static void F_24 ( struct V_44 * V_45 , struct V_67 * V_68 ,
int V_69 , int V_70 )
{
struct V_23 * V_71 ;
struct V_59 * V_59 ;
printf ( L_23 , V_72 ) ;
printf ( L_24 , V_70 ? L_25 : L_26 ) ;
printf ( L_27 ) ;
printf ( L_23 , V_72 ) ;
V_71 = F_25 ( V_45 ) ;
V_59 = F_26 ( V_68 ) ;
if ( ! V_59 ) {
F_27 ( L_28 ) ;
return;
}
while ( V_71 && V_69 -- ) {
struct V_27 * V_28 = F_8 ( V_71 , struct V_27 ,
V_24 ) ;
struct V_73 * V_74 = NULL ;
struct V_75 * V_75 ;
char V_12 [ V_76 ] ;
T_3 V_77 ;
if ( V_70 ) {
V_77 = V_28 -> V_19 ;
if ( ! V_78 )
V_74 = F_28 ( V_59 , V_77 , & V_75 , NULL ) ;
} else
V_77 = V_28 -> V_20 ;
if ( V_74 != NULL )
snprintf ( V_12 , sizeof( V_12 ) , L_29 V_79 L_30 , V_74 -> V_54 ,
V_77 - V_75 -> V_80 ( V_75 , V_74 -> V_81 ) ) ;
else
snprintf ( V_12 , sizeof( V_12 ) , L_31 V_79 L_30 , V_77 ) ;
printf ( L_24 , V_12 ) ;
printf ( L_32 ,
( unsigned long long ) V_28 -> V_22 ,
( unsigned long ) V_28 -> V_22 / V_28 -> V_31 ,
( unsigned long long ) V_28 -> V_21 ,
( unsigned long ) V_28 -> V_21 / V_28 -> V_31 ,
( unsigned long ) V_28 -> V_31 ,
( unsigned long ) V_28 -> V_32 ,
F_23 ( V_28 -> V_21 , V_28 -> V_22 ) ) ;
V_71 = F_29 ( V_71 ) ;
}
if ( V_69 == - 1 )
printf ( L_33 ) ;
printf ( L_23 , V_72 ) ;
}
static void F_30 ( void )
{
printf ( L_34 ) ;
printf ( L_35 , V_40 ) ;
printf ( L_36 , V_41 ) ;
printf ( L_37 ,
V_41 - V_40 ) ;
printf ( L_38 ,
F_23 ( V_40 , V_41 ) ) ;
printf ( L_39 , V_42 , V_43 ) ;
}
static void F_31 ( struct V_67 * V_68 )
{
if ( V_82 )
F_24 ( & V_83 , V_68 , V_84 , 1 ) ;
if ( V_85 )
F_24 ( & V_86 , V_68 , V_87 , 0 ) ;
F_30 () ;
}
static void F_32 ( struct V_44 * V_45 , struct V_27 * V_28 ,
struct V_88 * V_89 )
{
struct V_23 * * V_90 = & ( V_45 -> V_23 ) ;
struct V_23 * V_26 = NULL ;
struct V_91 * V_92 ;
while ( * V_90 ) {
struct V_27 * V_93 ;
int V_48 = 0 ;
V_93 = F_8 ( * V_90 , struct V_27 , V_24 ) ;
V_26 = * V_90 ;
F_33 (sort, sort_list, list) {
V_48 = V_92 -> V_48 ( V_28 , V_93 ) ;
if ( V_48 )
break;
}
if ( V_48 > 0 )
V_90 = & ( ( * V_90 ) -> V_30 ) ;
else
V_90 = & ( ( * V_90 ) -> V_29 ) ;
}
F_9 ( & V_28 -> V_24 , V_26 , V_90 ) ;
F_10 ( & V_28 -> V_24 , V_45 ) ;
}
static void F_34 ( struct V_44 * V_45 , struct V_44 * V_94 ,
struct V_88 * V_89 )
{
struct V_23 * V_24 ;
struct V_27 * V_28 ;
for (; ; ) {
V_24 = F_25 ( V_45 ) ;
if ( ! V_24 )
break;
F_35 ( V_24 , V_45 ) ;
V_28 = F_8 ( V_24 , struct V_27 , V_24 ) ;
F_32 ( V_94 , V_28 , V_89 ) ;
}
}
static void F_36 ( void )
{
F_34 ( & V_25 , & V_86 , & V_95 ) ;
F_34 ( & V_34 , & V_83 , & V_96 ) ;
}
static int F_37 ( void )
{
int V_97 = - V_98 ;
struct V_67 * V_68 = F_38 ( V_99 , V_100 ,
0 , false , & V_101 ) ;
if ( V_68 == NULL )
return - V_102 ;
if ( F_39 ( V_68 ) < 0 )
goto V_103;
if ( ! F_40 ( V_68 , L_40 ) )
goto V_103;
F_41 () ;
V_97 = F_42 ( V_68 , & V_101 ) ;
if ( V_97 != 0 )
goto V_103;
F_36 () ;
F_31 ( V_68 ) ;
V_103:
F_43 ( V_68 ) ;
return V_97 ;
}
static int V_51 ( struct V_27 * V_104 , struct V_27 * V_105 )
{
if ( V_104 -> V_20 < V_105 -> V_20 )
return - 1 ;
else if ( V_104 -> V_20 > V_105 -> V_20 )
return 1 ;
return 0 ;
}
static int V_52 ( struct V_27 * V_104 , struct V_27 * V_105 )
{
if ( V_104 -> V_19 < V_105 -> V_19 )
return - 1 ;
else if ( V_104 -> V_19 > V_105 -> V_19 )
return 1 ;
return 0 ;
}
static int F_44 ( struct V_27 * V_104 , struct V_27 * V_105 )
{
if ( V_104 -> V_31 < V_105 -> V_31 )
return - 1 ;
else if ( V_104 -> V_31 > V_105 -> V_31 )
return 1 ;
return 0 ;
}
static int F_45 ( struct V_27 * V_104 , struct V_27 * V_105 )
{
if ( V_104 -> V_22 < V_105 -> V_22 )
return - 1 ;
else if ( V_104 -> V_22 > V_105 -> V_22 )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_27 * V_104 , struct V_27 * V_105 )
{
double V_106 , V_107 ;
V_106 = F_23 ( V_104 -> V_21 , V_104 -> V_22 ) ;
V_107 = F_23 ( V_105 -> V_21 , V_105 -> V_22 ) ;
if ( V_106 < V_107 )
return - 1 ;
else if ( V_106 > V_107 )
return 1 ;
return 0 ;
}
static int F_47 ( struct V_27 * V_104 , struct V_27 * V_105 )
{
if ( V_104 -> V_32 < V_105 -> V_32 )
return - 1 ;
else if ( V_104 -> V_32 > V_105 -> V_32 )
return 1 ;
return 0 ;
}
static int F_48 ( const char * V_108 , struct V_88 * V_109 )
{
struct V_91 * V_92 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_110 ; V_2 ++ ) {
if ( ! strcmp ( V_111 [ V_2 ] -> V_54 , V_108 ) ) {
V_92 = malloc ( sizeof( * V_92 ) ) ;
if ( ! V_92 )
F_2 ( L_9 ) ;
memcpy ( V_92 , V_111 [ V_2 ] , sizeof( * V_92 ) ) ;
F_49 ( & V_92 -> V_109 , V_109 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_50 ( struct V_88 * V_89 , const char * V_112 )
{
char * V_108 ;
char * V_113 = F_51 ( V_112 ) ;
if ( ! V_113 )
F_2 ( L_41 ) ;
while ( true ) {
V_108 = F_52 ( & V_113 , L_42 ) ;
if ( ! V_108 )
break;
if ( F_48 ( V_108 , V_89 ) < 0 ) {
error ( L_43 , V_108 ) ;
free ( V_113 ) ;
return - 1 ;
}
}
free ( V_113 ) ;
return 0 ;
}
static int F_53 ( const struct V_114 * T_9 V_36 ,
const char * V_112 , int T_10 V_36 )
{
if ( ! V_112 )
return - 1 ;
if ( V_82 > V_85 )
return F_50 ( & V_96 , V_112 ) ;
else
return F_50 ( & V_95 , V_112 ) ;
return 0 ;
}
static int F_54 ( const struct V_114 * T_9 V_36 ,
const char * V_112 V_36 , int T_10 V_36 )
{
V_82 = ( V_85 + 1 ) ;
return 0 ;
}
static int F_55 ( const struct V_114 * T_9 V_36 ,
const char * V_112 V_36 , int T_10 V_36 )
{
V_85 = ( V_82 + 1 ) ;
return 0 ;
}
static int F_56 ( const struct V_114 * T_9 V_36 ,
const char * V_112 , int T_10 V_36 )
{
int V_115 ;
if ( ! V_112 )
return - 1 ;
V_115 = strtoul ( V_112 , NULL , 10 ) ;
if ( V_82 > V_85 )
V_84 = V_115 ;
else
V_87 = V_115 ;
return 0 ;
}
static int F_57 ( int V_116 , const char * * V_117 )
{
unsigned int V_118 , V_2 , V_119 ;
const char * * V_120 ;
V_118 = F_58 ( V_121 ) + V_116 - 1 ;
V_120 = calloc ( V_118 + 1 , sizeof( char * ) ) ;
if ( V_120 == NULL )
return - V_102 ;
for ( V_2 = 0 ; V_2 < F_58 ( V_121 ) ; V_2 ++ )
V_120 [ V_2 ] = F_51 ( V_121 [ V_2 ] ) ;
for ( V_119 = 1 ; V_119 < ( unsigned int ) V_116 ; V_119 ++ , V_2 ++ )
V_120 [ V_2 ] = V_117 [ V_119 ] ;
return F_59 ( V_2 , V_120 , NULL ) ;
}
int F_60 ( int V_116 , const char * * V_117 , const char * T_11 V_36 )
{
V_116 = F_61 ( V_116 , V_117 , V_122 , V_123 , 0 ) ;
if ( ! V_116 )
F_62 ( V_123 , V_122 ) ;
F_63 () ;
if ( ! strncmp ( V_117 [ 0 ] , L_44 , 3 ) ) {
return F_57 ( V_116 , V_117 ) ;
} else if ( ! strcmp ( V_117 [ 0 ] , L_45 ) ) {
F_3 () ;
if ( F_64 ( & V_96 ) )
F_50 ( & V_96 , V_124 ) ;
if ( F_64 ( & V_95 ) )
F_50 ( & V_95 , V_124 ) ;
return F_37 () ;
} else
F_62 ( V_123 , V_122 ) ;
return 0 ;
}
