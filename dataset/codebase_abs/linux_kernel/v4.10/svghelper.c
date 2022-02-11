static double F_1 ( int V_1 )
{
return 2 * V_1 + 1 ;
}
static double F_2 ( int V_1 )
{
if ( V_2 )
return F_1 ( V_2 [ V_1 ] ) * V_3 ;
else
return F_1 ( V_1 ) * V_3 ;
}
static double F_3 ( T_1 V_4 )
{
double V_5 ;
V_5 = 1.0 * V_6 * ( V_4 - V_7 ) / ( V_8 - V_7 ) ;
return V_5 ;
}
static double F_4 ( double V_9 )
{
int V_10 = 100 ;
double V_11 = 10.0 ;
if ( V_9 >= 10.0 )
return V_9 ;
while ( V_10 -- ) {
if ( V_9 >= V_11 )
return V_11 ;
V_11 = V_11 / 2.0 ;
}
return V_9 ;
}
void F_5 ( const char * V_12 , int V_13 , int V_14 , T_1 V_15 , T_1 V_16 )
{
int V_17 ;
V_18 = fopen ( V_12 , L_1 ) ;
if ( ! V_18 ) {
fprintf ( V_19 , L_2 , V_12 ) ;
return;
}
V_7 = V_15 ;
V_7 = V_7 / 100000000 * 100000000 ;
V_8 = V_16 ;
V_17 = ( V_8 - V_7 ) / 5000000 ;
if ( V_17 > V_6 )
V_6 = V_17 ;
V_20 = ( 1 + V_14 + F_1 ( V_13 ) ) * V_3 ;
fprintf ( V_18 , L_3 ) ;
fprintf ( V_18 , L_4 ) ;
fprintf ( V_18 , L_5 V_21 L_6 , V_6 , V_20 ) ;
fprintf ( V_18 , L_7 ) ;
fprintf ( V_18 , L_8 ) ;
fprintf ( V_18 , L_9 ) ;
fprintf ( V_18 , L_10 ) ;
fprintf ( V_18 , L_11 ) ;
fprintf ( V_18 , L_12 ) ;
fprintf ( V_18 , L_13 ) ;
fprintf ( V_18 , L_14 ) ;
fprintf ( V_18 , L_15 ) ;
fprintf ( V_18 , L_16 ) ;
fprintf ( V_18 , L_17 ) ;
fprintf ( V_18 , L_18 ) ;
fprintf ( V_18 , L_19 ) ;
fprintf ( V_18 , L_20 ) ;
fprintf ( V_18 , L_21 ) ;
fprintf ( V_18 , L_22 ) ;
fprintf ( V_18 , L_23 ) ;
fprintf ( V_18 , L_24 ) ;
fprintf ( V_18 , L_25 ) ;
fprintf ( V_18 , L_26 ) ;
fprintf ( V_18 , L_27 ) ;
fprintf ( V_18 , L_28 ) ;
fprintf ( V_18 , L_29 ) ;
fprintf ( V_18 , L_30 ) ;
fprintf ( V_18 , L_31 ) ;
}
static double F_6 ( double V_22 )
{
if ( V_22 < 0.25 )
return 0.25 ;
else if ( V_22 < 0.50 )
return 0.50 ;
else if ( V_22 < 0.75 )
return 0.75 ;
else
return 0.100 ;
}
void F_7 ( int V_23 , T_1 V_15 , T_1 V_16 , double V_22 , const char * type , int V_24 , int V_25 , int V_26 )
{
double V_27 = F_3 ( V_16 ) - F_3 ( V_15 ) ;
V_22 = F_6 ( V_22 ) ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_33 , V_24 , V_25 , V_26 ) ;
fprintf ( V_18 , L_34 ,
F_3 ( V_15 ) ,
V_27 ,
V_23 * V_3 ,
V_28 * V_22 ,
type ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_8 ( int V_23 , T_1 V_15 , T_1 V_16 , double V_22 , const char * type , int V_24 , int V_25 , int V_26 )
{
double V_27 = F_3 ( V_16 ) - F_3 ( V_15 ) ;
V_22 = F_6 ( V_22 ) ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_33 , V_24 , V_25 , V_26 ) ;
fprintf ( V_18 , L_34 ,
F_3 ( V_15 ) ,
V_27 ,
V_23 * V_3 + V_29 - V_28 * V_22 ,
V_28 * V_22 ,
type ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_9 ( int V_23 , T_1 V_15 , T_1 V_16 , double V_22 , const char * type , int V_24 , int V_25 , int V_26 )
{
double V_27 = F_3 ( V_16 ) - F_3 ( V_15 ) ;
V_22 = F_6 ( V_22 ) ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_33 , V_24 , V_25 , V_26 ) ;
fprintf ( V_18 , L_34 ,
F_3 ( V_15 ) ,
V_27 ,
V_23 * V_3 + V_29 - V_29 * V_22 ,
V_29 * V_22 ,
type ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_10 ( int V_23 , T_1 V_15 , T_1 V_16 , const char * type )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_34 ,
F_3 ( V_15 ) , F_3 ( V_16 ) - F_3 ( V_15 ) , V_23 * V_3 , V_29 , type ) ;
}
void F_11 ( int V_23 , int V_1 , T_1 V_15 , T_1 V_16 , const char * V_30 )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_36 , V_1 ,
F_12 ( V_16 - V_15 ) ) ;
if ( V_30 )
fprintf ( V_18 , L_37 , V_30 ) ;
F_10 ( V_23 , V_15 , V_16 , L_38 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_13 ( int V_23 , int V_1 , T_1 V_15 , T_1 V_16 , const char * V_30 )
{
double V_31 ;
const char * type ;
if ( ! V_18 )
return;
if ( V_32 && V_16 - V_15 > V_32 )
type = L_39 ;
else
type = L_40 ;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_41 ,
V_1 , F_12 ( V_16 - V_15 ) ) ;
if ( V_30 )
fprintf ( V_18 , L_42 , V_30 ) ;
fprintf ( V_18 , L_34 ,
F_3 ( V_15 ) , F_3 ( V_16 ) - F_3 ( V_15 ) , V_23 * V_3 , V_29 ,
type ) ;
V_31 = ( F_3 ( V_16 ) - F_3 ( V_15 ) ) ;
if ( V_1 > 9 )
V_31 = V_31 / 2 ;
if ( V_31 > 1.25 )
V_31 = 1.25 ;
V_31 = F_4 ( V_31 ) ;
if ( V_31 > V_33 )
fprintf ( V_18 , L_43 ,
F_3 ( V_15 ) , V_23 * V_3 + V_29 - 1 , V_31 , V_1 + 1 ) ;
fprintf ( V_18 , L_35 ) ;
}
static char * F_12 ( T_1 V_34 )
{
static char V_35 [ 80 ] ;
V_35 [ 0 ] = 0 ;
if ( V_34 < V_36 )
return V_35 ;
if ( V_34 < V_37 ) {
sprintf ( V_35 , L_44 , V_34 / ( double ) V_36 ) ;
return V_35 ;
}
sprintf ( V_35 , L_45 , V_34 / ( double ) V_37 ) ;
return V_35 ;
}
void F_14 ( int V_23 , int V_1 , T_1 V_15 , T_1 V_16 , const char * V_30 )
{
char * V_35 ;
const char * V_38 ;
double V_39 ;
if ( ! V_18 )
return;
V_38 = L_46 ;
if ( V_16 - V_15 > 10 * V_37 )
V_38 = L_47 ;
V_35 = F_12 ( V_16 - V_15 ) ;
V_39 = 1.0 * ( F_3 ( V_16 ) - F_3 ( V_15 ) ) ;
if ( V_39 > 3 )
V_39 = 3 ;
V_39 = F_4 ( V_39 ) ;
fprintf ( V_18 , L_48 , F_3 ( V_15 ) , V_23 * V_3 ) ;
fprintf ( V_18 , L_49 , V_1 , F_12 ( V_16 - V_15 ) ) ;
if ( V_30 )
fprintf ( V_18 , L_50 , V_30 ) ;
fprintf ( V_18 , L_51 ,
F_3 ( V_16 ) - F_3 ( V_15 ) , V_29 , V_38 ) ;
if ( V_39 > V_33 )
fprintf ( V_18 , L_52 ,
V_39 , V_35 ) ;
fprintf ( V_18 , L_35 ) ;
}
static char * F_15 ( void )
{
static char V_40 [ 255 ] ;
char V_41 [ 256 ] ;
T_2 * V_42 ;
V_40 [ 0 ] = 0 ;
V_42 = fopen ( L_53 , L_54 ) ;
if ( V_42 ) {
while ( fgets ( V_41 , 255 , V_42 ) ) {
if ( strstr ( V_41 , L_55 ) ) {
strncpy ( V_40 , & V_41 [ 13 ] , 255 ) ;
break;
}
}
fclose ( V_42 ) ;
}
V_42 = fopen ( L_56 , L_54 ) ;
if ( V_42 ) {
while ( fgets ( V_41 , 255 , V_42 ) ) {
unsigned int V_43 ;
V_43 = F_16 ( V_41 , NULL , 10 ) ;
if ( V_43 > V_44 )
V_44 = V_43 ;
}
fclose ( V_42 ) ;
}
return V_40 ;
}
void F_17 ( int V_1 , T_1 V_45 , T_1 V_46 )
{
char V_47 [ 80 ] ;
if ( ! V_18 )
return;
V_44 = V_45 ;
V_48 = V_46 ;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_57 ,
F_3 ( V_7 ) ,
F_3 ( V_8 ) - F_3 ( V_7 ) ,
F_2 ( V_1 ) , V_3 + V_29 ) ;
sprintf ( V_47 , L_58 , ( int ) V_1 ) ;
fprintf ( V_18 , L_59 ,
10 + F_3 ( V_7 ) , F_2 ( V_1 ) + V_29 / 2 , V_47 ) ;
fprintf ( V_18 , L_60 ,
10 + F_3 ( V_7 ) , F_2 ( V_1 ) + V_3 + V_29 - 4 , F_15 () ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_18 ( int V_1 , T_1 V_15 , T_1 V_16 , int V_49 , const char * V_50 , const char * V_30 )
{
double V_51 ;
const char * type ;
if ( ! V_18 )
return;
if ( V_32 && V_16 - V_15 >= V_32 )
type = L_39 ;
else if ( V_52 && strstr ( V_50 , V_52 ) )
type = L_39 ;
else
type = L_40 ;
fprintf ( V_18 , L_48 , F_3 ( V_15 ) , F_2 ( V_1 ) ) ;
fprintf ( V_18 , L_61 , V_49 , V_50 , F_12 ( V_16 - V_15 ) ) ;
if ( V_30 )
fprintf ( V_18 , L_42 , V_30 ) ;
fprintf ( V_18 , L_51 ,
F_3 ( V_16 ) - F_3 ( V_15 ) , V_3 + V_29 , type ) ;
V_51 = F_3 ( V_16 ) - F_3 ( V_15 ) ;
if ( V_51 > 6 )
V_51 = 6 ;
V_51 = F_4 ( V_51 ) ;
if ( V_51 > V_33 )
fprintf ( V_18 , L_62 ,
V_51 , V_50 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_19 ( int V_1 , T_1 V_15 , T_1 V_16 , int type )
{
double V_51 ;
char V_38 [ 128 ] ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
if ( type > 6 )
type = 6 ;
sprintf ( V_38 , L_63 , type ) ;
fprintf ( V_18 , L_64 ,
V_38 ,
F_3 ( V_15 ) , F_3 ( V_16 ) - F_3 ( V_15 ) ,
F_2 ( V_1 ) , V_3 + V_29 ) ;
V_51 = ( F_3 ( V_16 ) - F_3 ( V_15 ) ) / 2.0 ;
if ( V_51 > 6 )
V_51 = 6 ;
V_51 = F_4 ( V_51 ) ;
if ( V_51 > V_33 )
fprintf ( V_18 , L_65 ,
F_3 ( V_15 ) , F_2 ( V_1 ) + V_51 , V_51 , type ) ;
fprintf ( V_18 , L_35 ) ;
}
static char * F_20 ( unsigned long V_53 )
{
static char V_54 [ 1024 ] ;
unsigned long long V_55 ;
memset ( V_54 , 0 , 1024 ) ;
V_55 = V_53 ;
sprintf ( V_54 , L_66 , V_55 ) ;
if ( V_55 > 1000 )
sprintf ( V_54 , L_67 , ( V_55 + 500 ) / 1000 ) ;
if ( V_55 > 1500000 )
sprintf ( V_54 , L_68 , ( V_55 + 5000.0 ) / 1000000 ) ;
if ( V_55 == V_48 )
sprintf ( V_54 , L_69 ) ;
return V_54 ;
}
void F_21 ( int V_1 , T_1 V_15 , T_1 V_16 , T_1 V_43 )
{
double V_22 = 0 ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
if ( V_44 )
V_22 = V_43 * 1.0 / V_44 * ( V_29 + V_3 ) ;
V_22 = 1 + F_2 ( V_1 ) + V_3 + V_29 - V_22 ;
fprintf ( V_18 , L_70 ,
F_3 ( V_15 ) , F_3 ( V_16 ) , V_22 , V_22 ) ;
fprintf ( V_18 , L_71 ,
F_3 ( V_15 ) , V_22 + 0.9 , F_20 ( V_43 ) ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_22 ( T_1 V_15 , int V_56 , char * V_57 , int V_58 , char * V_59 , const char * V_30 )
{
double V_22 ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_72 ,
V_57 ? V_57 : L_73 ,
V_59 ? V_59 : L_73 ) ;
if ( V_30 )
fprintf ( V_18 , L_74 , V_30 ) ;
if ( V_56 < V_58 ) {
if ( V_56 ) {
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_56 * V_3 + V_29 , F_3 ( V_15 ) , V_56 * V_3 + V_29 + V_3 / 32 ) ;
if ( V_59 )
fprintf ( V_18 , L_76 ,
F_3 ( V_15 ) , V_56 * V_3 + V_29 + V_29 / 48 , V_59 ) ;
}
if ( V_58 ) {
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_58 * V_3 - V_3 / 32 , F_3 ( V_15 ) , V_58 * V_3 ) ;
if ( V_57 )
fprintf ( V_18 , L_76 ,
F_3 ( V_15 ) , V_58 * V_3 - V_3 / 32 , V_57 ) ;
}
} else {
if ( V_58 ) {
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_58 * V_3 + V_29 , F_3 ( V_15 ) , V_58 * V_3 + V_29 + V_3 / 32 ) ;
if ( V_57 )
fprintf ( V_18 , L_77 ,
F_3 ( V_15 ) , V_58 * V_3 + V_29 + V_3 / 48 , V_57 ) ;
}
if ( V_56 ) {
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_56 * V_3 - V_3 / 32 , F_3 ( V_15 ) , V_56 * V_3 ) ;
if ( V_59 )
fprintf ( V_18 , L_77 ,
F_3 ( V_15 ) , V_56 * V_3 - V_29 / 32 , V_59 ) ;
}
}
V_22 = V_56 * V_3 ;
if ( V_58 > V_56 )
V_22 += V_29 ;
if ( V_56 )
fprintf ( V_18 , L_78 ,
F_3 ( V_15 ) , V_22 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_23 ( T_1 V_15 , int V_56 , int V_58 , const char * V_30 )
{
double V_22 ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
if ( V_30 )
fprintf ( V_18 , L_74 , V_30 ) ;
if ( V_56 < V_58 )
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_56 * V_3 + V_29 , F_3 ( V_15 ) , V_58 * V_3 ) ;
else
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_58 * V_3 + V_29 , F_3 ( V_15 ) , V_56 * V_3 ) ;
V_22 = V_56 * V_3 ;
if ( V_58 > V_56 )
V_22 += V_29 ;
fprintf ( V_18 , L_78 ,
F_3 ( V_15 ) , V_22 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_24 ( T_1 V_15 , int V_60 , const char * V_30 )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_79 ) ;
if ( V_30 )
fprintf ( V_18 , L_74 , V_30 ) ;
fprintf ( V_18 , L_80 ,
F_3 ( V_15 ) , V_60 * V_3 ) ;
fprintf ( V_18 , L_80 ,
F_3 ( V_15 ) , V_60 * V_3 + V_29 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_25 ( int V_23 , T_1 V_15 , const char * V_35 )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_59 ,
F_3 ( V_15 ) , V_23 * V_3 + V_29 / 2 , V_35 ) ;
}
static void F_26 ( int V_5 , const char * V_35 , const char * V_38 )
{
double V_61 ;
V_61 = V_29 / 2 ;
fprintf ( V_18 , L_81 ,
V_5 , V_61 , V_61 , V_38 ) ;
fprintf ( V_18 , L_82 ,
V_5 + V_61 + 5 , V_61 , 0.8 * V_61 , V_35 ) ;
}
void F_27 ( void )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
F_26 ( 0 , L_83 , L_84 ) ;
F_26 ( 100 , L_85 , L_86 ) ;
F_26 ( 200 , L_87 , L_88 ) ;
F_26 ( 300 , L_89 , L_90 ) ;
F_26 ( 400 , L_91 , L_92 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_28 ( void )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
F_26 ( 0 , L_93 , L_40 ) ;
F_26 ( 100 , L_94 , L_95 ) ;
F_26 ( 200 , L_96 , L_97 ) ;
F_26 ( 350 , L_98 , L_99 ) ;
F_26 ( 550 , L_100 , L_101 ) ;
F_26 ( 650 , L_102 , L_46 ) ;
F_26 ( 800 , L_103 , L_38 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_29 ( double V_62 )
{
T_1 V_63 ;
if ( ! V_18 )
return;
V_63 = V_7 ;
while ( V_63 < V_8 ) {
int V_64 = 220 ;
double V_65 = 0.075 ;
if ( ( V_63 % 100000000 ) == 0 ) {
V_65 = 0.5 ;
V_64 = 192 ;
}
if ( ( V_63 % 1000000000 ) == 0 ) {
V_65 = 2.0 ;
V_64 = 128 ;
}
if ( V_65 >= V_62 )
fprintf ( V_18 , L_104 V_21 L_105 ,
F_3 ( V_63 ) , V_3 / 2 , F_3 ( V_63 ) ,
V_20 , V_64 , V_64 , V_64 , V_65 ) ;
V_63 += 10000000 ;
}
}
void F_30 ( void )
{
if ( V_18 ) {
fprintf ( V_18 , L_106 ) ;
fclose ( V_18 ) ;
V_18 = NULL ;
}
}
static void F_31 ( int * V_66 , struct V_67 * V_68 , int V_1 , int * V_69 )
{
int V_63 ;
int V_70 ;
for ( V_63 = 0 ; V_63 < V_68 -> V_71 ; V_63 ++ ) {
if ( ! F_32 ( V_1 , F_33 ( & V_68 -> V_72 [ V_63 ] ) ) )
continue;
F_34 (thr,
cpumask_bits(&t->sib_thr[i]),
MAX_NR_CPUS)
if ( V_66 [ V_70 ] == - 1 )
V_66 [ V_70 ] = ( * V_69 ) ++ ;
}
}
static void F_35 ( int * V_66 , struct V_67 * V_68 )
{
int V_69 = 0 ;
int V_63 ;
int V_1 ;
for ( V_63 = 0 ; V_63 < V_68 -> V_73 ; V_63 ++ )
F_34 (cpu,
cpumask_bits(&t->sib_core[i]),
MAX_NR_CPUS)
F_31 ( V_66 , V_68 , V_1 , & V_69 ) ;
}
static int F_36 ( char * V_74 , T_3 * V_75 )
{
int V_63 ;
int V_76 = 0 ;
struct V_77 * V_78 ;
int V_79 ;
V_78 = F_37 ( V_74 ) ;
if ( ! V_78 )
return - 1 ;
for ( V_63 = 0 ; V_63 < V_78 -> V_80 ; V_63 ++ ) {
V_79 = V_78 -> V_66 [ V_63 ] ;
if ( V_79 >= V_81 ) {
V_76 = - 1 ;
break;
}
F_38 ( V_79 , F_33 ( V_75 ) ) ;
}
F_39 ( V_78 ) ;
return V_76 ;
}
int F_40 ( char * V_82 , int V_73 ,
char * V_72 , int V_71 )
{
int V_63 ;
struct V_67 V_68 ;
V_68 . V_73 = V_73 ;
V_68 . V_71 = V_71 ;
V_68 . V_82 = calloc ( V_73 , sizeof( T_3 ) ) ;
V_68 . V_72 = calloc ( V_71 , sizeof( T_3 ) ) ;
if ( ! V_68 . V_82 || ! V_68 . V_72 ) {
fprintf ( V_19 , L_107 ) ;
goto exit;
}
for ( V_63 = 0 ; V_63 < V_73 ; V_63 ++ ) {
if ( F_36 ( V_82 , & V_68 . V_82 [ V_63 ] ) ) {
fprintf ( V_19 , L_108 ) ;
goto exit;
}
V_82 += strlen ( V_82 ) + 1 ;
}
for ( V_63 = 0 ; V_63 < V_71 ; V_63 ++ ) {
if ( F_36 ( V_72 , & V_68 . V_72 [ V_63 ] ) ) {
fprintf ( V_19 , L_108 ) ;
goto exit;
}
V_72 += strlen ( V_72 ) + 1 ;
}
V_2 = malloc ( sizeof( int ) * V_81 ) ;
if ( ! V_2 ) {
fprintf ( V_19 , L_107 ) ;
goto exit;
}
for ( V_63 = 0 ; V_63 < V_81 ; V_63 ++ )
V_2 [ V_63 ] = - 1 ;
F_35 ( V_2 , & V_68 ) ;
return 0 ;
exit:
F_41 ( & V_68 . V_82 ) ;
F_41 ( & V_68 . V_72 ) ;
return - 1 ;
}
