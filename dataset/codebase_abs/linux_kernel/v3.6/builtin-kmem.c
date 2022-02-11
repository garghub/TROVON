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
struct V_35 * V_36 ,
int V_10 ,
T_3 T_4 V_37 ,
struct V_38 * V_38 V_37 ,
int V_24 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_21 ;
int V_22 ;
int V_39 , V_40 ;
V_20 = F_13 ( V_36 , L_10 , V_28 ) ;
V_19 = F_13 ( V_36 , L_11 , V_28 ) ;
V_21 = F_13 ( V_36 , L_12 , V_28 ) ;
V_22 = F_13 ( V_36 , L_13 , V_28 ) ;
F_7 ( V_19 , V_20 , V_21 , V_22 , V_10 ) ;
F_11 ( V_19 , V_21 , V_22 ) ;
V_41 += V_21 ;
V_42 += V_22 ;
if ( V_24 ) {
V_39 = V_4 [ V_10 ] ;
V_40 = F_13 ( V_36 , L_14 , V_28 ) ;
if ( V_39 != V_40 )
V_43 ++ ;
}
V_44 ++ ;
}
static struct V_27 * F_14 ( unsigned long V_20 ,
unsigned long V_19 ,
struct V_45 * V_46 ,
T_5 V_47 )
{
struct V_23 * V_24 = V_46 -> V_23 ;
struct V_27 V_48 = { . V_20 = V_20 , . V_19 = V_19 } ;
while ( V_24 ) {
struct V_27 * V_28 ;
int V_49 ;
V_28 = F_8 ( V_24 , struct V_27 , V_24 ) ;
V_49 = V_47 ( & V_48 , V_28 ) ;
if ( V_49 < 0 )
V_24 = V_24 -> V_30 ;
else if ( V_49 > 0 )
V_24 = V_24 -> V_29 ;
else
return V_28 ;
}
return NULL ;
}
static void F_15 ( void * V_28 ,
struct V_35 * V_36 ,
int V_10 ,
T_3 T_4 V_37 ,
struct V_38 * V_38 V_37 )
{
unsigned long V_20 ;
struct V_27 * V_50 , * V_51 ;
V_20 = F_13 ( V_36 , L_10 , V_28 ) ;
V_50 = F_14 ( V_20 , 0 , & V_25 , V_52 ) ;
if ( ! V_50 )
return;
if ( V_10 != V_50 -> V_33 ) {
V_50 -> V_32 ++ ;
V_51 = F_14 ( 0 , V_50 -> V_19 ,
& V_34 , V_53 ) ;
assert ( V_51 ) ;
V_51 -> V_32 ++ ;
}
V_50 -> V_33 = - 1 ;
}
static void F_16 ( struct V_54 * V_55 ,
union V_56 * T_6 V_37 , void * V_28 ,
int V_10 , T_3 T_4 , struct V_38 * V_38 )
{
struct V_57 * V_58 = F_17 ( V_55 , struct V_57 , V_55 ) ;
struct V_35 * V_36 ;
int type ;
type = F_18 ( V_58 -> V_59 -> V_60 , V_28 ) ;
V_36 = F_19 ( V_58 -> V_59 -> V_60 , type ) ;
if ( ! strcmp ( V_36 -> V_61 , L_15 ) ||
! strcmp ( V_36 -> V_61 , L_16 ) ) {
F_12 ( V_28 , V_36 , V_10 , T_4 , V_38 , 0 ) ;
return;
}
if ( ! strcmp ( V_36 -> V_61 , L_17 ) ||
! strcmp ( V_36 -> V_61 , L_18 ) ) {
F_12 ( V_28 , V_36 , V_10 , T_4 , V_38 , 1 ) ;
return;
}
if ( ! strcmp ( V_36 -> V_61 , L_19 ) ||
! strcmp ( V_36 -> V_61 , L_20 ) ) {
F_15 ( V_28 , V_36 , V_10 , T_4 , V_38 ) ;
return;
}
}
static int F_20 ( struct V_54 * V_55 ,
union V_56 * V_36 ,
struct V_62 * V_63 ,
struct V_64 * T_7 V_37 ,
struct V_65 * V_65 )
{
struct V_38 * V_38 = F_21 ( V_65 , V_36 -> V_66 . V_67 ) ;
if ( V_38 == NULL ) {
F_22 ( L_21 ,
V_36 -> V_68 . type ) ;
return - 1 ;
}
F_23 ( L_22 , V_38 -> V_69 , V_38 -> V_67 ) ;
F_16 ( V_55 , V_36 , V_63 -> V_70 , V_63 -> V_10 ,
V_63 -> time , V_38 ) ;
return 0 ;
}
static double F_24 ( unsigned long V_71 , unsigned long V_72 )
{
if ( V_72 == 0 )
return 0.0 ;
else
return 100.0 - ( 100.0 * V_71 / V_72 ) ;
}
static void F_25 ( struct V_45 * V_46 , struct V_73 * V_59 ,
int V_74 , int V_75 )
{
struct V_23 * V_76 ;
struct V_65 * V_65 ;
printf ( L_23 , V_77 ) ;
printf ( L_24 , V_75 ? L_25 : L_26 ) ;
printf ( L_27 ) ;
printf ( L_23 , V_77 ) ;
V_76 = F_26 ( V_46 ) ;
V_65 = F_27 ( V_59 ) ;
if ( ! V_65 ) {
F_28 ( L_28 ) ;
return;
}
while ( V_76 && V_74 -- ) {
struct V_27 * V_28 = F_8 ( V_76 , struct V_27 ,
V_24 ) ;
struct V_78 * V_79 = NULL ;
struct V_80 * V_80 ;
char V_12 [ V_81 ] ;
T_3 V_82 ;
if ( V_75 ) {
V_82 = V_28 -> V_19 ;
if ( ! V_83 )
V_79 = F_29 ( V_65 , V_82 , & V_80 , NULL ) ;
} else
V_82 = V_28 -> V_20 ;
if ( V_79 != NULL )
snprintf ( V_12 , sizeof( V_12 ) , L_29 V_84 L_30 , V_79 -> V_61 ,
V_82 - V_80 -> V_85 ( V_80 , V_79 -> V_86 ) ) ;
else
snprintf ( V_12 , sizeof( V_12 ) , L_31 V_84 L_30 , V_82 ) ;
printf ( L_24 , V_12 ) ;
printf ( L_32 ,
( unsigned long long ) V_28 -> V_22 ,
( unsigned long ) V_28 -> V_22 / V_28 -> V_31 ,
( unsigned long long ) V_28 -> V_21 ,
( unsigned long ) V_28 -> V_21 / V_28 -> V_31 ,
( unsigned long ) V_28 -> V_31 ,
( unsigned long ) V_28 -> V_32 ,
F_24 ( V_28 -> V_21 , V_28 -> V_22 ) ) ;
V_76 = F_30 ( V_76 ) ;
}
if ( V_74 == - 1 )
printf ( L_33 ) ;
printf ( L_23 , V_77 ) ;
}
static void F_31 ( void )
{
printf ( L_34 ) ;
printf ( L_35 , V_41 ) ;
printf ( L_36 , V_42 ) ;
printf ( L_37 ,
V_42 - V_41 ) ;
printf ( L_38 ,
F_24 ( V_41 , V_42 ) ) ;
printf ( L_39 , V_43 , V_44 ) ;
}
static void F_32 ( struct V_73 * V_59 )
{
if ( V_87 )
F_25 ( & V_88 , V_59 , V_89 , 1 ) ;
if ( V_90 )
F_25 ( & V_91 , V_59 , V_92 , 0 ) ;
F_31 () ;
}
static void F_33 ( struct V_45 * V_46 , struct V_27 * V_28 ,
struct V_93 * V_94 )
{
struct V_23 * * V_95 = & ( V_46 -> V_23 ) ;
struct V_23 * V_26 = NULL ;
struct V_96 * V_97 ;
while ( * V_95 ) {
struct V_27 * V_98 ;
int V_49 = 0 ;
V_98 = F_8 ( * V_95 , struct V_27 , V_24 ) ;
V_26 = * V_95 ;
F_34 (sort, sort_list, list) {
V_49 = V_97 -> V_49 ( V_28 , V_98 ) ;
if ( V_49 )
break;
}
if ( V_49 > 0 )
V_95 = & ( ( * V_95 ) -> V_30 ) ;
else
V_95 = & ( ( * V_95 ) -> V_29 ) ;
}
F_9 ( & V_28 -> V_24 , V_26 , V_95 ) ;
F_10 ( & V_28 -> V_24 , V_46 ) ;
}
static void F_35 ( struct V_45 * V_46 , struct V_45 * V_99 ,
struct V_93 * V_94 )
{
struct V_23 * V_24 ;
struct V_27 * V_28 ;
for (; ; ) {
V_24 = F_26 ( V_46 ) ;
if ( ! V_24 )
break;
F_36 ( V_24 , V_46 ) ;
V_28 = F_8 ( V_24 , struct V_27 , V_24 ) ;
F_33 ( V_99 , V_28 , V_94 ) ;
}
}
static void F_37 ( void )
{
F_35 ( & V_25 , & V_91 , & V_100 ) ;
F_35 ( & V_34 , & V_88 , & V_101 ) ;
}
static int F_38 ( void )
{
int V_102 = - V_103 ;
struct V_73 * V_59 ;
V_59 = F_39 ( V_104 , V_105 , 0 , false ,
& V_57 . V_55 ) ;
if ( V_59 == NULL )
return - V_106 ;
V_57 . V_59 = V_59 ;
if ( F_40 ( V_59 ) < 0 )
goto V_107;
if ( ! F_41 ( V_59 , L_40 ) )
goto V_107;
F_42 () ;
V_102 = F_43 ( V_59 , & V_57 . V_55 ) ;
if ( V_102 != 0 )
goto V_107;
F_37 () ;
F_32 ( V_59 ) ;
V_107:
F_44 ( V_59 ) ;
return V_102 ;
}
static int V_52 ( struct V_27 * V_108 , struct V_27 * V_109 )
{
if ( V_108 -> V_20 < V_109 -> V_20 )
return - 1 ;
else if ( V_108 -> V_20 > V_109 -> V_20 )
return 1 ;
return 0 ;
}
static int V_53 ( struct V_27 * V_108 , struct V_27 * V_109 )
{
if ( V_108 -> V_19 < V_109 -> V_19 )
return - 1 ;
else if ( V_108 -> V_19 > V_109 -> V_19 )
return 1 ;
return 0 ;
}
static int F_45 ( struct V_27 * V_108 , struct V_27 * V_109 )
{
if ( V_108 -> V_31 < V_109 -> V_31 )
return - 1 ;
else if ( V_108 -> V_31 > V_109 -> V_31 )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_27 * V_108 , struct V_27 * V_109 )
{
if ( V_108 -> V_22 < V_109 -> V_22 )
return - 1 ;
else if ( V_108 -> V_22 > V_109 -> V_22 )
return 1 ;
return 0 ;
}
static int F_47 ( struct V_27 * V_108 , struct V_27 * V_109 )
{
double V_110 , V_111 ;
V_110 = F_24 ( V_108 -> V_21 , V_108 -> V_22 ) ;
V_111 = F_24 ( V_109 -> V_21 , V_109 -> V_22 ) ;
if ( V_110 < V_111 )
return - 1 ;
else if ( V_110 > V_111 )
return 1 ;
return 0 ;
}
static int F_48 ( struct V_27 * V_108 , struct V_27 * V_109 )
{
if ( V_108 -> V_32 < V_109 -> V_32 )
return - 1 ;
else if ( V_108 -> V_32 > V_109 -> V_32 )
return 1 ;
return 0 ;
}
static int F_49 ( const char * V_112 , struct V_93 * V_113 )
{
struct V_96 * V_97 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_114 ; V_2 ++ ) {
if ( ! strcmp ( V_115 [ V_2 ] -> V_61 , V_112 ) ) {
V_97 = malloc ( sizeof( * V_97 ) ) ;
if ( ! V_97 )
F_2 ( L_9 ) ;
memcpy ( V_97 , V_115 [ V_2 ] , sizeof( * V_97 ) ) ;
F_50 ( & V_97 -> V_113 , V_113 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_51 ( struct V_93 * V_94 , const char * V_116 )
{
char * V_112 ;
char * V_117 = F_52 ( V_116 ) ;
if ( ! V_117 )
F_2 ( L_41 ) ;
while ( true ) {
V_112 = F_53 ( & V_117 , L_42 ) ;
if ( ! V_112 )
break;
if ( F_49 ( V_112 , V_94 ) < 0 ) {
error ( L_43 , V_112 ) ;
free ( V_117 ) ;
return - 1 ;
}
}
free ( V_117 ) ;
return 0 ;
}
static int F_54 ( const struct V_118 * T_8 V_37 ,
const char * V_116 , int T_9 V_37 )
{
if ( ! V_116 )
return - 1 ;
if ( V_87 > V_90 )
return F_51 ( & V_101 , V_116 ) ;
else
return F_51 ( & V_100 , V_116 ) ;
return 0 ;
}
static int F_55 ( const struct V_118 * T_8 V_37 ,
const char * V_116 V_37 , int T_9 V_37 )
{
V_87 = ( V_90 + 1 ) ;
return 0 ;
}
static int F_56 ( const struct V_118 * T_8 V_37 ,
const char * V_116 V_37 , int T_9 V_37 )
{
V_90 = ( V_87 + 1 ) ;
return 0 ;
}
static int F_57 ( const struct V_118 * T_8 V_37 ,
const char * V_116 , int T_9 V_37 )
{
int V_119 ;
if ( ! V_116 )
return - 1 ;
V_119 = strtoul ( V_116 , NULL , 10 ) ;
if ( V_87 > V_90 )
V_89 = V_119 ;
else
V_92 = V_119 ;
return 0 ;
}
static int F_58 ( int V_120 , const char * * V_121 )
{
unsigned int V_122 , V_2 , V_123 ;
const char * * V_124 ;
V_122 = F_59 ( V_125 ) + V_120 - 1 ;
V_124 = calloc ( V_122 + 1 , sizeof( char * ) ) ;
if ( V_124 == NULL )
return - V_106 ;
for ( V_2 = 0 ; V_2 < F_59 ( V_125 ) ; V_2 ++ )
V_124 [ V_2 ] = F_52 ( V_125 [ V_2 ] ) ;
for ( V_123 = 1 ; V_123 < ( unsigned int ) V_120 ; V_123 ++ , V_2 ++ )
V_124 [ V_2 ] = V_121 [ V_123 ] ;
return F_60 ( V_2 , V_124 , NULL ) ;
}
int F_61 ( int V_120 , const char * * V_121 , const char * T_10 V_37 )
{
V_120 = F_62 ( V_120 , V_121 , V_126 , V_127 , 0 ) ;
if ( ! V_120 )
F_63 ( V_127 , V_126 ) ;
F_64 () ;
if ( ! strncmp ( V_121 [ 0 ] , L_44 , 3 ) ) {
return F_58 ( V_120 , V_121 ) ;
} else if ( ! strcmp ( V_121 [ 0 ] , L_45 ) ) {
F_3 () ;
if ( F_65 ( & V_101 ) )
F_51 ( & V_101 , V_128 ) ;
if ( F_65 ( & V_100 ) )
F_51 ( & V_100 , V_128 ) ;
return F_38 () ;
} else
F_63 ( V_127 , V_126 ) ;
return 0 ;
}
