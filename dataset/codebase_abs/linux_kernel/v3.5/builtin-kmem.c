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
static void F_16 ( union V_54 * T_6 V_37 , void * V_28 ,
int V_10 , T_3 T_4 , struct V_38 * V_38 )
{
struct V_35 * V_36 ;
int type ;
type = F_17 ( V_28 ) ;
V_36 = F_18 ( type ) ;
if ( ! strcmp ( V_36 -> V_55 , L_15 ) ||
! strcmp ( V_36 -> V_55 , L_16 ) ) {
F_12 ( V_28 , V_36 , V_10 , T_4 , V_38 , 0 ) ;
return;
}
if ( ! strcmp ( V_36 -> V_55 , L_17 ) ||
! strcmp ( V_36 -> V_55 , L_18 ) ) {
F_12 ( V_28 , V_36 , V_10 , T_4 , V_38 , 1 ) ;
return;
}
if ( ! strcmp ( V_36 -> V_55 , L_19 ) ||
! strcmp ( V_36 -> V_55 , L_20 ) ) {
F_15 ( V_28 , V_36 , V_10 , T_4 , V_38 ) ;
return;
}
}
static int F_19 ( struct V_56 * T_7 V_37 ,
union V_54 * V_36 ,
struct V_57 * V_58 ,
struct V_59 * T_8 V_37 ,
struct V_60 * V_60 )
{
struct V_38 * V_38 = F_20 ( V_60 , V_36 -> V_61 . V_62 ) ;
if ( V_38 == NULL ) {
F_21 ( L_21 ,
V_36 -> V_63 . type ) ;
return - 1 ;
}
F_22 ( L_22 , V_38 -> V_64 , V_38 -> V_62 ) ;
F_16 ( V_36 , V_58 -> V_65 , V_58 -> V_10 ,
V_58 -> time , V_38 ) ;
return 0 ;
}
static double F_23 ( unsigned long V_66 , unsigned long V_67 )
{
if ( V_67 == 0 )
return 0.0 ;
else
return 100.0 - ( 100.0 * V_66 / V_67 ) ;
}
static void F_24 ( struct V_45 * V_46 , struct V_68 * V_69 ,
int V_70 , int V_71 )
{
struct V_23 * V_72 ;
struct V_60 * V_60 ;
printf ( L_23 , V_73 ) ;
printf ( L_24 , V_71 ? L_25 : L_26 ) ;
printf ( L_27 ) ;
printf ( L_23 , V_73 ) ;
V_72 = F_25 ( V_46 ) ;
V_60 = F_26 ( V_69 ) ;
if ( ! V_60 ) {
F_27 ( L_28 ) ;
return;
}
while ( V_72 && V_70 -- ) {
struct V_27 * V_28 = F_8 ( V_72 , struct V_27 ,
V_24 ) ;
struct V_74 * V_75 = NULL ;
struct V_76 * V_76 ;
char V_12 [ V_77 ] ;
T_3 V_78 ;
if ( V_71 ) {
V_78 = V_28 -> V_19 ;
if ( ! V_79 )
V_75 = F_28 ( V_60 , V_78 , & V_76 , NULL ) ;
} else
V_78 = V_28 -> V_20 ;
if ( V_75 != NULL )
snprintf ( V_12 , sizeof( V_12 ) , L_29 V_80 L_30 , V_75 -> V_55 ,
V_78 - V_76 -> V_81 ( V_76 , V_75 -> V_82 ) ) ;
else
snprintf ( V_12 , sizeof( V_12 ) , L_31 V_80 L_30 , V_78 ) ;
printf ( L_24 , V_12 ) ;
printf ( L_32 ,
( unsigned long long ) V_28 -> V_22 ,
( unsigned long ) V_28 -> V_22 / V_28 -> V_31 ,
( unsigned long long ) V_28 -> V_21 ,
( unsigned long ) V_28 -> V_21 / V_28 -> V_31 ,
( unsigned long ) V_28 -> V_31 ,
( unsigned long ) V_28 -> V_32 ,
F_23 ( V_28 -> V_21 , V_28 -> V_22 ) ) ;
V_72 = F_29 ( V_72 ) ;
}
if ( V_70 == - 1 )
printf ( L_33 ) ;
printf ( L_23 , V_73 ) ;
}
static void F_30 ( void )
{
printf ( L_34 ) ;
printf ( L_35 , V_41 ) ;
printf ( L_36 , V_42 ) ;
printf ( L_37 ,
V_42 - V_41 ) ;
printf ( L_38 ,
F_23 ( V_41 , V_42 ) ) ;
printf ( L_39 , V_43 , V_44 ) ;
}
static void F_31 ( struct V_68 * V_69 )
{
if ( V_83 )
F_24 ( & V_84 , V_69 , V_85 , 1 ) ;
if ( V_86 )
F_24 ( & V_87 , V_69 , V_88 , 0 ) ;
F_30 () ;
}
static void F_32 ( struct V_45 * V_46 , struct V_27 * V_28 ,
struct V_89 * V_90 )
{
struct V_23 * * V_91 = & ( V_46 -> V_23 ) ;
struct V_23 * V_26 = NULL ;
struct V_92 * V_93 ;
while ( * V_91 ) {
struct V_27 * V_94 ;
int V_49 = 0 ;
V_94 = F_8 ( * V_91 , struct V_27 , V_24 ) ;
V_26 = * V_91 ;
F_33 (sort, sort_list, list) {
V_49 = V_93 -> V_49 ( V_28 , V_94 ) ;
if ( V_49 )
break;
}
if ( V_49 > 0 )
V_91 = & ( ( * V_91 ) -> V_30 ) ;
else
V_91 = & ( ( * V_91 ) -> V_29 ) ;
}
F_9 ( & V_28 -> V_24 , V_26 , V_91 ) ;
F_10 ( & V_28 -> V_24 , V_46 ) ;
}
static void F_34 ( struct V_45 * V_46 , struct V_45 * V_95 ,
struct V_89 * V_90 )
{
struct V_23 * V_24 ;
struct V_27 * V_28 ;
for (; ; ) {
V_24 = F_25 ( V_46 ) ;
if ( ! V_24 )
break;
F_35 ( V_24 , V_46 ) ;
V_28 = F_8 ( V_24 , struct V_27 , V_24 ) ;
F_32 ( V_95 , V_28 , V_90 ) ;
}
}
static void F_36 ( void )
{
F_34 ( & V_25 , & V_87 , & V_96 ) ;
F_34 ( & V_34 , & V_84 , & V_97 ) ;
}
static int F_37 ( void )
{
int V_98 = - V_99 ;
struct V_68 * V_69 = F_38 ( V_100 , V_101 ,
0 , false , & V_102 ) ;
if ( V_69 == NULL )
return - V_103 ;
if ( F_39 ( V_69 ) < 0 )
goto V_104;
if ( ! F_40 ( V_69 , L_40 ) )
goto V_104;
F_41 () ;
V_98 = F_42 ( V_69 , & V_102 ) ;
if ( V_98 != 0 )
goto V_104;
F_36 () ;
F_31 ( V_69 ) ;
V_104:
F_43 ( V_69 ) ;
return V_98 ;
}
static int V_52 ( struct V_27 * V_105 , struct V_27 * V_106 )
{
if ( V_105 -> V_20 < V_106 -> V_20 )
return - 1 ;
else if ( V_105 -> V_20 > V_106 -> V_20 )
return 1 ;
return 0 ;
}
static int V_53 ( struct V_27 * V_105 , struct V_27 * V_106 )
{
if ( V_105 -> V_19 < V_106 -> V_19 )
return - 1 ;
else if ( V_105 -> V_19 > V_106 -> V_19 )
return 1 ;
return 0 ;
}
static int F_44 ( struct V_27 * V_105 , struct V_27 * V_106 )
{
if ( V_105 -> V_31 < V_106 -> V_31 )
return - 1 ;
else if ( V_105 -> V_31 > V_106 -> V_31 )
return 1 ;
return 0 ;
}
static int F_45 ( struct V_27 * V_105 , struct V_27 * V_106 )
{
if ( V_105 -> V_22 < V_106 -> V_22 )
return - 1 ;
else if ( V_105 -> V_22 > V_106 -> V_22 )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_27 * V_105 , struct V_27 * V_106 )
{
double V_107 , V_108 ;
V_107 = F_23 ( V_105 -> V_21 , V_105 -> V_22 ) ;
V_108 = F_23 ( V_106 -> V_21 , V_106 -> V_22 ) ;
if ( V_107 < V_108 )
return - 1 ;
else if ( V_107 > V_108 )
return 1 ;
return 0 ;
}
static int F_47 ( struct V_27 * V_105 , struct V_27 * V_106 )
{
if ( V_105 -> V_32 < V_106 -> V_32 )
return - 1 ;
else if ( V_105 -> V_32 > V_106 -> V_32 )
return 1 ;
return 0 ;
}
static int F_48 ( const char * V_109 , struct V_89 * V_110 )
{
struct V_92 * V_93 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_111 ; V_2 ++ ) {
if ( ! strcmp ( V_112 [ V_2 ] -> V_55 , V_109 ) ) {
V_93 = malloc ( sizeof( * V_93 ) ) ;
if ( ! V_93 )
F_2 ( L_9 ) ;
memcpy ( V_93 , V_112 [ V_2 ] , sizeof( * V_93 ) ) ;
F_49 ( & V_93 -> V_110 , V_110 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_50 ( struct V_89 * V_90 , const char * V_113 )
{
char * V_109 ;
char * V_114 = F_51 ( V_113 ) ;
if ( ! V_114 )
F_2 ( L_41 ) ;
while ( true ) {
V_109 = F_52 ( & V_114 , L_42 ) ;
if ( ! V_109 )
break;
if ( F_48 ( V_109 , V_90 ) < 0 ) {
error ( L_43 , V_109 ) ;
free ( V_114 ) ;
return - 1 ;
}
}
free ( V_114 ) ;
return 0 ;
}
static int F_53 ( const struct V_115 * T_9 V_37 ,
const char * V_113 , int T_10 V_37 )
{
if ( ! V_113 )
return - 1 ;
if ( V_83 > V_86 )
return F_50 ( & V_97 , V_113 ) ;
else
return F_50 ( & V_96 , V_113 ) ;
return 0 ;
}
static int F_54 ( const struct V_115 * T_9 V_37 ,
const char * V_113 V_37 , int T_10 V_37 )
{
V_83 = ( V_86 + 1 ) ;
return 0 ;
}
static int F_55 ( const struct V_115 * T_9 V_37 ,
const char * V_113 V_37 , int T_10 V_37 )
{
V_86 = ( V_83 + 1 ) ;
return 0 ;
}
static int F_56 ( const struct V_115 * T_9 V_37 ,
const char * V_113 , int T_10 V_37 )
{
int V_116 ;
if ( ! V_113 )
return - 1 ;
V_116 = strtoul ( V_113 , NULL , 10 ) ;
if ( V_83 > V_86 )
V_85 = V_116 ;
else
V_88 = V_116 ;
return 0 ;
}
static int F_57 ( int V_117 , const char * * V_118 )
{
unsigned int V_119 , V_2 , V_120 ;
const char * * V_121 ;
V_119 = F_58 ( V_122 ) + V_117 - 1 ;
V_121 = calloc ( V_119 + 1 , sizeof( char * ) ) ;
if ( V_121 == NULL )
return - V_103 ;
for ( V_2 = 0 ; V_2 < F_58 ( V_122 ) ; V_2 ++ )
V_121 [ V_2 ] = F_51 ( V_122 [ V_2 ] ) ;
for ( V_120 = 1 ; V_120 < ( unsigned int ) V_117 ; V_120 ++ , V_2 ++ )
V_121 [ V_2 ] = V_118 [ V_120 ] ;
return F_59 ( V_2 , V_121 , NULL ) ;
}
int F_60 ( int V_117 , const char * * V_118 , const char * T_11 V_37 )
{
V_117 = F_61 ( V_117 , V_118 , V_123 , V_124 , 0 ) ;
if ( ! V_117 )
F_62 ( V_124 , V_123 ) ;
F_63 () ;
if ( ! strncmp ( V_118 [ 0 ] , L_44 , 3 ) ) {
return F_57 ( V_117 , V_118 ) ;
} else if ( ! strcmp ( V_118 [ 0 ] , L_45 ) ) {
F_3 () ;
if ( F_64 ( & V_97 ) )
F_50 ( & V_97 , V_125 ) ;
if ( F_64 ( & V_96 ) )
F_50 ( & V_96 , V_125 ) ;
return F_37 () ;
} else
F_62 ( V_124 , V_123 ) ;
return 0 ;
}
