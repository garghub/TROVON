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
}
}
static void F_6 ( unsigned long V_19 , unsigned long V_20 ,
int V_21 , int V_22 , int V_10 )
{
struct V_23 * * V_24 = & V_25 . V_23 ;
struct V_23 * V_26 = NULL ;
struct V_27 * V_28 = NULL ;
while ( * V_24 ) {
V_26 = * V_24 ;
V_28 = F_7 ( * V_24 , struct V_27 , V_24 ) ;
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
F_8 ( & V_28 -> V_24 , V_26 , V_24 ) ;
F_9 ( & V_28 -> V_24 , & V_25 ) ;
}
V_28 -> V_19 = V_19 ;
V_28 -> V_33 = V_10 ;
}
static void F_10 ( unsigned long V_19 ,
int V_21 , int V_22 )
{
struct V_23 * * V_24 = & V_34 . V_23 ;
struct V_23 * V_26 = NULL ;
struct V_27 * V_28 = NULL ;
while ( * V_24 ) {
V_26 = * V_24 ;
V_28 = F_7 ( * V_24 , struct V_27 , V_24 ) ;
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
F_8 ( & V_28 -> V_24 , V_26 , V_24 ) ;
F_9 ( & V_28 -> V_24 , & V_34 ) ;
}
}
static void F_11 ( void * V_28 ,
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
V_20 = F_12 ( V_35 , L_10 , V_28 ) ;
V_19 = F_12 ( V_35 , L_11 , V_28 ) ;
V_21 = F_12 ( V_35 , L_12 , V_28 ) ;
V_22 = F_12 ( V_35 , L_13 , V_28 ) ;
F_6 ( V_19 , V_20 , V_21 , V_22 , V_10 ) ;
F_10 ( V_19 , V_21 , V_22 ) ;
V_40 += V_21 ;
V_41 += V_22 ;
if ( V_24 ) {
V_38 = V_4 [ V_10 ] ;
V_39 = F_12 ( V_35 , L_14 , V_28 ) ;
if ( V_38 != V_39 )
V_42 ++ ;
}
V_43 ++ ;
}
static struct V_27 * F_13 ( unsigned long V_20 ,
unsigned long V_19 ,
struct V_44 * V_45 ,
T_5 V_46 )
{
struct V_23 * V_24 = V_45 -> V_23 ;
struct V_27 V_47 = { . V_20 = V_20 , . V_19 = V_19 } ;
while ( V_24 ) {
struct V_27 * V_28 ;
int V_48 ;
V_28 = F_7 ( V_24 , struct V_27 , V_24 ) ;
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
static void F_14 ( void * V_28 ,
struct V_35 * V_35 ,
int V_10 ,
T_3 T_4 V_36 ,
struct V_37 * V_37 V_36 )
{
unsigned long V_20 ;
struct V_27 * V_49 , * V_50 ;
V_20 = F_12 ( V_35 , L_10 , V_28 ) ;
V_49 = F_13 ( V_20 , 0 , & V_25 , V_51 ) ;
if ( ! V_49 )
return;
if ( V_10 != V_49 -> V_33 ) {
V_49 -> V_32 ++ ;
V_50 = F_13 ( 0 , V_49 -> V_19 ,
& V_34 , V_52 ) ;
assert ( V_50 ) ;
V_50 -> V_32 ++ ;
}
V_49 -> V_33 = - 1 ;
}
static void F_15 ( union V_53 * T_6 V_36 , void * V_28 ,
int V_10 , T_3 T_4 , struct V_37 * V_37 )
{
struct V_35 * V_35 ;
int type ;
type = F_16 ( V_28 ) ;
V_35 = F_17 ( type ) ;
if ( ! strcmp ( V_35 -> V_54 , L_15 ) ||
! strcmp ( V_35 -> V_54 , L_16 ) ) {
F_11 ( V_28 , V_35 , V_10 , T_4 , V_37 , 0 ) ;
return;
}
if ( ! strcmp ( V_35 -> V_54 , L_17 ) ||
! strcmp ( V_35 -> V_54 , L_18 ) ) {
F_11 ( V_28 , V_35 , V_10 , T_4 , V_37 , 1 ) ;
return;
}
if ( ! strcmp ( V_35 -> V_54 , L_19 ) ||
! strcmp ( V_35 -> V_54 , L_20 ) ) {
F_14 ( V_28 , V_35 , V_10 , T_4 , V_37 ) ;
return;
}
}
static int F_18 ( union V_53 * V_35 ,
struct V_55 * V_56 ,
struct V_57 * T_7 V_36 ,
struct V_58 * V_59 )
{
struct V_37 * V_37 = F_19 ( V_59 , V_35 -> V_60 . V_61 ) ;
if ( V_37 == NULL ) {
F_20 ( L_21 ,
V_35 -> V_62 . type ) ;
return - 1 ;
}
F_21 ( L_22 , V_37 -> V_63 , V_37 -> V_61 ) ;
F_15 ( V_35 , V_56 -> V_64 , V_56 -> V_10 ,
V_56 -> time , V_37 ) ;
return 0 ;
}
static double F_22 ( unsigned long V_65 , unsigned long V_66 )
{
if ( V_66 == 0 )
return 0.0 ;
else
return 100.0 - ( 100.0 * V_65 / V_66 ) ;
}
static void F_23 ( struct V_44 * V_45 , struct V_58 * V_59 ,
int V_67 , int V_68 )
{
struct V_23 * V_69 ;
struct V_70 * V_70 ;
printf ( L_23 , V_71 ) ;
printf ( L_24 , V_68 ? L_25 : L_26 ) ;
printf ( L_27 ) ;
printf ( L_23 , V_71 ) ;
V_69 = F_24 ( V_45 ) ;
V_70 = F_25 ( V_59 ) ;
if ( ! V_70 ) {
F_26 ( L_28 ) ;
return;
}
while ( V_69 && V_67 -- ) {
struct V_27 * V_28 = F_7 ( V_69 , struct V_27 ,
V_24 ) ;
struct V_72 * V_73 = NULL ;
struct V_74 * V_74 ;
char V_12 [ V_75 ] ;
T_3 V_76 ;
if ( V_68 ) {
V_76 = V_28 -> V_19 ;
if ( ! V_77 )
V_73 = F_27 ( V_70 , V_76 , & V_74 , NULL ) ;
} else
V_76 = V_28 -> V_20 ;
if ( V_73 != NULL )
snprintf ( V_12 , sizeof( V_12 ) , L_29 V_78 L_30 , V_73 -> V_54 ,
V_76 - V_74 -> V_79 ( V_74 , V_73 -> V_80 ) ) ;
else
snprintf ( V_12 , sizeof( V_12 ) , L_31 V_78 L_30 , V_76 ) ;
printf ( L_24 , V_12 ) ;
printf ( L_32 ,
( unsigned long long ) V_28 -> V_22 ,
( unsigned long ) V_28 -> V_22 / V_28 -> V_31 ,
( unsigned long long ) V_28 -> V_21 ,
( unsigned long ) V_28 -> V_21 / V_28 -> V_31 ,
( unsigned long ) V_28 -> V_31 ,
( unsigned long ) V_28 -> V_32 ,
F_22 ( V_28 -> V_21 , V_28 -> V_22 ) ) ;
V_69 = F_28 ( V_69 ) ;
}
if ( V_67 == - 1 )
printf ( L_33 ) ;
printf ( L_23 , V_71 ) ;
}
static void F_29 ( void )
{
printf ( L_34 ) ;
printf ( L_35 , V_40 ) ;
printf ( L_36 , V_41 ) ;
printf ( L_37 ,
V_41 - V_40 ) ;
printf ( L_38 ,
F_22 ( V_40 , V_41 ) ) ;
printf ( L_39 , V_42 , V_43 ) ;
}
static void F_30 ( struct V_58 * V_59 )
{
if ( V_81 )
F_23 ( & V_82 , V_59 , V_83 , 1 ) ;
if ( V_84 )
F_23 ( & V_85 , V_59 , V_86 , 0 ) ;
F_29 () ;
}
static void F_31 ( struct V_44 * V_45 , struct V_27 * V_28 ,
struct V_87 * V_88 )
{
struct V_23 * * V_89 = & ( V_45 -> V_23 ) ;
struct V_23 * V_26 = NULL ;
struct V_90 * V_91 ;
while ( * V_89 ) {
struct V_27 * V_92 ;
int V_48 = 0 ;
V_92 = F_7 ( * V_89 , struct V_27 , V_24 ) ;
V_26 = * V_89 ;
F_32 (sort, sort_list, list) {
V_48 = V_91 -> V_48 ( V_28 , V_92 ) ;
if ( V_48 )
break;
}
if ( V_48 > 0 )
V_89 = & ( ( * V_89 ) -> V_30 ) ;
else
V_89 = & ( ( * V_89 ) -> V_29 ) ;
}
F_8 ( & V_28 -> V_24 , V_26 , V_89 ) ;
F_9 ( & V_28 -> V_24 , V_45 ) ;
}
static void F_33 ( struct V_44 * V_45 , struct V_44 * V_93 ,
struct V_87 * V_88 )
{
struct V_23 * V_24 ;
struct V_27 * V_28 ;
for (; ; ) {
V_24 = F_24 ( V_45 ) ;
if ( ! V_24 )
break;
F_34 ( V_24 , V_45 ) ;
V_28 = F_7 ( V_24 , struct V_27 , V_24 ) ;
F_31 ( V_93 , V_28 , V_88 ) ;
}
}
static void F_35 ( void )
{
F_33 ( & V_25 , & V_85 , & V_94 ) ;
F_33 ( & V_34 , & V_82 , & V_95 ) ;
}
static int F_36 ( void )
{
int V_96 = - V_97 ;
struct V_58 * V_59 = F_37 ( V_98 , V_99 ,
0 , false , & V_100 ) ;
if ( V_59 == NULL )
return - V_101 ;
if ( F_38 ( V_59 ) < 0 )
goto V_102;
if ( ! F_39 ( V_59 , L_40 ) )
goto V_102;
F_40 () ;
V_96 = F_41 ( V_59 , & V_100 ) ;
if ( V_96 != 0 )
goto V_102;
F_35 () ;
F_30 ( V_59 ) ;
V_102:
F_42 ( V_59 ) ;
return V_96 ;
}
static int V_51 ( struct V_27 * V_103 , struct V_27 * V_104 )
{
if ( V_103 -> V_20 < V_104 -> V_20 )
return - 1 ;
else if ( V_103 -> V_20 > V_104 -> V_20 )
return 1 ;
return 0 ;
}
static int V_52 ( struct V_27 * V_103 , struct V_27 * V_104 )
{
if ( V_103 -> V_19 < V_104 -> V_19 )
return - 1 ;
else if ( V_103 -> V_19 > V_104 -> V_19 )
return 1 ;
return 0 ;
}
static int F_43 ( struct V_27 * V_103 , struct V_27 * V_104 )
{
if ( V_103 -> V_31 < V_104 -> V_31 )
return - 1 ;
else if ( V_103 -> V_31 > V_104 -> V_31 )
return 1 ;
return 0 ;
}
static int F_44 ( struct V_27 * V_103 , struct V_27 * V_104 )
{
if ( V_103 -> V_22 < V_104 -> V_22 )
return - 1 ;
else if ( V_103 -> V_22 > V_104 -> V_22 )
return 1 ;
return 0 ;
}
static int F_45 ( struct V_27 * V_103 , struct V_27 * V_104 )
{
double V_105 , V_106 ;
V_105 = F_22 ( V_103 -> V_21 , V_103 -> V_22 ) ;
V_106 = F_22 ( V_104 -> V_21 , V_104 -> V_22 ) ;
if ( V_105 < V_106 )
return - 1 ;
else if ( V_105 > V_106 )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_27 * V_103 , struct V_27 * V_104 )
{
if ( V_103 -> V_32 < V_104 -> V_32 )
return - 1 ;
else if ( V_103 -> V_32 > V_104 -> V_32 )
return 1 ;
return 0 ;
}
static int F_47 ( const char * V_107 , struct V_87 * V_108 )
{
struct V_90 * V_91 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_109 ; V_2 ++ ) {
if ( ! strcmp ( V_110 [ V_2 ] -> V_54 , V_107 ) ) {
V_91 = malloc ( sizeof( * V_91 ) ) ;
if ( ! V_91 )
F_2 ( L_9 ) ;
memcpy ( V_91 , V_110 [ V_2 ] , sizeof( * V_91 ) ) ;
F_48 ( & V_91 -> V_108 , V_108 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_49 ( struct V_87 * V_88 , const char * V_111 )
{
char * V_107 ;
char * V_112 = F_50 ( V_111 ) ;
if ( ! V_112 )
F_2 ( L_41 ) ;
while ( true ) {
V_107 = F_51 ( & V_112 , L_42 ) ;
if ( ! V_107 )
break;
if ( F_47 ( V_107 , V_88 ) < 0 ) {
error ( L_43 , V_107 ) ;
return - 1 ;
}
}
free ( V_112 ) ;
return 0 ;
}
static int F_52 ( const struct V_113 * T_8 V_36 ,
const char * V_111 , int T_9 V_36 )
{
if ( ! V_111 )
return - 1 ;
if ( V_81 > V_84 )
return F_49 ( & V_95 , V_111 ) ;
else
return F_49 ( & V_94 , V_111 ) ;
return 0 ;
}
static int F_53 ( const struct V_113 * T_8 V_36 ,
const char * V_111 V_36 , int T_9 V_36 )
{
V_81 = ( V_84 + 1 ) ;
return 0 ;
}
static int F_54 ( const struct V_113 * T_8 V_36 ,
const char * V_111 V_36 , int T_9 V_36 )
{
V_84 = ( V_81 + 1 ) ;
return 0 ;
}
static int F_55 ( const struct V_113 * T_8 V_36 ,
const char * V_111 , int T_9 V_36 )
{
int V_114 ;
if ( ! V_111 )
return - 1 ;
V_114 = strtoul ( V_111 , NULL , 10 ) ;
if ( V_81 > V_84 )
V_83 = V_114 ;
else
V_86 = V_114 ;
return 0 ;
}
static int F_56 ( int V_115 , const char * * V_116 )
{
unsigned int V_117 , V_2 , V_118 ;
const char * * V_119 ;
V_117 = F_57 ( V_120 ) + V_115 - 1 ;
V_119 = calloc ( V_117 + 1 , sizeof( char * ) ) ;
if ( V_119 == NULL )
return - V_101 ;
for ( V_2 = 0 ; V_2 < F_57 ( V_120 ) ; V_2 ++ )
V_119 [ V_2 ] = F_50 ( V_120 [ V_2 ] ) ;
for ( V_118 = 1 ; V_118 < ( unsigned int ) V_115 ; V_118 ++ , V_2 ++ )
V_119 [ V_2 ] = V_116 [ V_118 ] ;
return F_58 ( V_2 , V_119 , NULL ) ;
}
int F_59 ( int V_115 , const char * * V_116 , const char * T_10 V_36 )
{
V_115 = F_60 ( V_115 , V_116 , V_121 , V_122 , 0 ) ;
if ( ! V_115 )
F_61 ( V_122 , V_121 ) ;
F_62 () ;
if ( ! strncmp ( V_116 [ 0 ] , L_44 , 3 ) ) {
return F_56 ( V_115 , V_116 ) ;
} else if ( ! strcmp ( V_116 [ 0 ] , L_45 ) ) {
F_3 () ;
if ( F_63 ( & V_95 ) )
F_49 ( & V_95 , V_123 ) ;
if ( F_63 ( & V_94 ) )
F_49 ( & V_94 , V_123 ) ;
return F_36 () ;
} else
F_61 ( V_122 , V_121 ) ;
return 0 ;
}
