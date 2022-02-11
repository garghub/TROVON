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
if ( V_34 < 1000 )
return V_35 ;
if ( V_34 < 1000 * 1000 ) {
sprintf ( V_35 , L_44 , V_34 / 1000.0 ) ;
return V_35 ;
}
sprintf ( V_35 , L_45 , V_34 / 1000.0 / 1000 ) ;
return V_35 ;
}
void F_14 ( int V_23 , int V_1 , T_1 V_15 , T_1 V_16 , const char * V_30 )
{
char * V_35 ;
const char * V_36 ;
double V_37 ;
if ( ! V_18 )
return;
V_36 = L_46 ;
if ( V_16 - V_15 > 10 * 1000000 )
V_36 = L_47 ;
V_35 = F_12 ( V_16 - V_15 ) ;
V_37 = 1.0 * ( F_3 ( V_16 ) - F_3 ( V_15 ) ) ;
if ( V_37 > 3 )
V_37 = 3 ;
V_37 = F_4 ( V_37 ) ;
fprintf ( V_18 , L_48 , F_3 ( V_15 ) , V_23 * V_3 ) ;
fprintf ( V_18 , L_49 , V_1 , F_12 ( V_16 - V_15 ) ) ;
if ( V_30 )
fprintf ( V_18 , L_50 , V_30 ) ;
fprintf ( V_18 , L_51 ,
F_3 ( V_16 ) - F_3 ( V_15 ) , V_29 , V_36 ) ;
if ( V_37 > V_33 )
fprintf ( V_18 , L_52 ,
V_37 , V_35 ) ;
fprintf ( V_18 , L_35 ) ;
}
static char * F_15 ( void )
{
static char V_38 [ 255 ] ;
char V_39 [ 256 ] ;
T_2 * V_40 ;
V_38 [ 0 ] = 0 ;
V_40 = fopen ( L_53 , L_54 ) ;
if ( V_40 ) {
while ( fgets ( V_39 , 255 , V_40 ) ) {
if ( strstr ( V_39 , L_55 ) ) {
strncpy ( V_38 , & V_39 [ 13 ] , 255 ) ;
break;
}
}
fclose ( V_40 ) ;
}
V_40 = fopen ( L_56 , L_54 ) ;
if ( V_40 ) {
while ( fgets ( V_39 , 255 , V_40 ) ) {
unsigned int V_41 ;
V_41 = F_16 ( V_39 , NULL , 10 ) ;
if ( V_41 > V_42 )
V_42 = V_41 ;
}
fclose ( V_40 ) ;
}
return V_38 ;
}
void F_17 ( int V_1 , T_1 V_43 , T_1 V_44 )
{
char V_45 [ 80 ] ;
if ( ! V_18 )
return;
V_42 = V_43 ;
V_46 = V_44 ;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_57 ,
F_3 ( V_7 ) ,
F_3 ( V_8 ) - F_3 ( V_7 ) ,
F_2 ( V_1 ) , V_3 + V_29 ) ;
sprintf ( V_45 , L_58 , ( int ) V_1 ) ;
fprintf ( V_18 , L_59 ,
10 + F_3 ( V_7 ) , F_2 ( V_1 ) + V_29 / 2 , V_45 ) ;
fprintf ( V_18 , L_60 ,
10 + F_3 ( V_7 ) , F_2 ( V_1 ) + V_3 + V_29 - 4 , F_15 () ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_18 ( int V_1 , T_1 V_15 , T_1 V_16 , int V_47 , const char * V_48 , const char * V_30 )
{
double V_49 ;
const char * type ;
if ( ! V_18 )
return;
if ( V_32 && V_16 - V_15 >= V_32 )
type = L_39 ;
else if ( V_50 && strstr ( V_48 , V_50 ) )
type = L_39 ;
else
type = L_40 ;
fprintf ( V_18 , L_48 , F_3 ( V_15 ) , F_2 ( V_1 ) ) ;
fprintf ( V_18 , L_61 , V_47 , V_48 , F_12 ( V_16 - V_15 ) ) ;
if ( V_30 )
fprintf ( V_18 , L_42 , V_30 ) ;
fprintf ( V_18 , L_51 ,
F_3 ( V_16 ) - F_3 ( V_15 ) , V_3 + V_29 , type ) ;
V_49 = F_3 ( V_16 ) - F_3 ( V_15 ) ;
if ( V_49 > 6 )
V_49 = 6 ;
V_49 = F_4 ( V_49 ) ;
if ( V_49 > V_33 )
fprintf ( V_18 , L_62 ,
V_49 , V_48 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_19 ( int V_1 , T_1 V_15 , T_1 V_16 , int type )
{
double V_49 ;
char V_36 [ 128 ] ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
if ( type > 6 )
type = 6 ;
sprintf ( V_36 , L_63 , type ) ;
fprintf ( V_18 , L_64 ,
V_36 ,
F_3 ( V_15 ) , F_3 ( V_16 ) - F_3 ( V_15 ) ,
F_2 ( V_1 ) , V_3 + V_29 ) ;
V_49 = ( F_3 ( V_16 ) - F_3 ( V_15 ) ) / 2.0 ;
if ( V_49 > 6 )
V_49 = 6 ;
V_49 = F_4 ( V_49 ) ;
if ( V_49 > V_33 )
fprintf ( V_18 , L_65 ,
F_3 ( V_15 ) , F_2 ( V_1 ) + V_49 , V_49 , type ) ;
fprintf ( V_18 , L_35 ) ;
}
static char * F_20 ( unsigned long V_51 )
{
static char V_52 [ 1024 ] ;
unsigned long long V_53 ;
memset ( V_52 , 0 , 1024 ) ;
V_53 = V_51 ;
sprintf ( V_52 , L_66 , V_53 ) ;
if ( V_53 > 1000 )
sprintf ( V_52 , L_67 , ( V_53 + 500 ) / 1000 ) ;
if ( V_53 > 1500000 )
sprintf ( V_52 , L_68 , ( V_53 + 5000.0 ) / 1000000 ) ;
if ( V_53 == V_46 )
sprintf ( V_52 , L_69 ) ;
return V_52 ;
}
void F_21 ( int V_1 , T_1 V_15 , T_1 V_16 , T_1 V_41 )
{
double V_22 = 0 ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
if ( V_42 )
V_22 = V_41 * 1.0 / V_42 * ( V_29 + V_3 ) ;
V_22 = 1 + F_2 ( V_1 ) + V_3 + V_29 - V_22 ;
fprintf ( V_18 , L_70 ,
F_3 ( V_15 ) , F_3 ( V_16 ) , V_22 , V_22 ) ;
fprintf ( V_18 , L_71 ,
F_3 ( V_15 ) , V_22 + 0.9 , F_20 ( V_41 ) ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_22 ( T_1 V_15 , int V_54 , char * V_55 , int V_56 , char * V_57 , const char * V_30 )
{
double V_22 ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_72 ,
V_55 ? V_55 : L_73 ,
V_57 ? V_57 : L_73 ) ;
if ( V_30 )
fprintf ( V_18 , L_74 , V_30 ) ;
if ( V_54 < V_56 ) {
if ( V_54 ) {
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_54 * V_3 + V_29 , F_3 ( V_15 ) , V_54 * V_3 + V_29 + V_3 / 32 ) ;
if ( V_57 )
fprintf ( V_18 , L_76 ,
F_3 ( V_15 ) , V_54 * V_3 + V_29 + V_29 / 48 , V_57 ) ;
}
if ( V_56 ) {
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_56 * V_3 - V_3 / 32 , F_3 ( V_15 ) , V_56 * V_3 ) ;
if ( V_55 )
fprintf ( V_18 , L_76 ,
F_3 ( V_15 ) , V_56 * V_3 - V_3 / 32 , V_55 ) ;
}
} else {
if ( V_56 ) {
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_56 * V_3 + V_29 , F_3 ( V_15 ) , V_56 * V_3 + V_29 + V_3 / 32 ) ;
if ( V_55 )
fprintf ( V_18 , L_77 ,
F_3 ( V_15 ) , V_56 * V_3 + V_29 + V_3 / 48 , V_55 ) ;
}
if ( V_54 ) {
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_54 * V_3 - V_3 / 32 , F_3 ( V_15 ) , V_54 * V_3 ) ;
if ( V_57 )
fprintf ( V_18 , L_77 ,
F_3 ( V_15 ) , V_54 * V_3 - V_29 / 32 , V_57 ) ;
}
}
V_22 = V_54 * V_3 ;
if ( V_56 > V_54 )
V_22 += V_29 ;
if ( V_54 )
fprintf ( V_18 , L_78 ,
F_3 ( V_15 ) , V_22 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_23 ( T_1 V_15 , int V_54 , int V_56 , const char * V_30 )
{
double V_22 ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
if ( V_30 )
fprintf ( V_18 , L_74 , V_30 ) ;
if ( V_54 < V_56 )
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_54 * V_3 + V_29 , F_3 ( V_15 ) , V_56 * V_3 ) ;
else
fprintf ( V_18 , L_75 ,
F_3 ( V_15 ) , V_56 * V_3 + V_29 , F_3 ( V_15 ) , V_54 * V_3 ) ;
V_22 = V_54 * V_3 ;
if ( V_56 > V_54 )
V_22 += V_29 ;
fprintf ( V_18 , L_78 ,
F_3 ( V_15 ) , V_22 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_24 ( T_1 V_15 , int V_58 , const char * V_30 )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_32 ) ;
fprintf ( V_18 , L_79 ) ;
if ( V_30 )
fprintf ( V_18 , L_74 , V_30 ) ;
fprintf ( V_18 , L_80 ,
F_3 ( V_15 ) , V_58 * V_3 ) ;
fprintf ( V_18 , L_80 ,
F_3 ( V_15 ) , V_58 * V_3 + V_29 ) ;
fprintf ( V_18 , L_35 ) ;
}
void F_25 ( int V_23 , T_1 V_15 , const char * V_35 )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_59 ,
F_3 ( V_15 ) , V_23 * V_3 + V_29 / 2 , V_35 ) ;
}
static void F_26 ( int V_5 , const char * V_35 , const char * V_36 )
{
double V_59 ;
V_59 = V_29 / 2 ;
fprintf ( V_18 , L_81 ,
V_5 , V_59 , V_59 , V_36 ) ;
fprintf ( V_18 , L_82 ,
V_5 + V_59 + 5 , V_59 , 0.8 * V_59 , V_35 ) ;
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
void F_29 ( double V_60 )
{
T_1 V_61 ;
if ( ! V_18 )
return;
V_61 = V_7 ;
while ( V_61 < V_8 ) {
int V_62 = 220 ;
double V_63 = 0.075 ;
if ( ( V_61 % 100000000 ) == 0 ) {
V_63 = 0.5 ;
V_62 = 192 ;
}
if ( ( V_61 % 1000000000 ) == 0 ) {
V_63 = 2.0 ;
V_62 = 128 ;
}
if ( V_63 >= V_60 )
fprintf ( V_18 , L_104 V_21 L_105 ,
F_3 ( V_61 ) , V_3 / 2 , F_3 ( V_61 ) ,
V_20 , V_62 , V_62 , V_62 , V_63 ) ;
V_61 += 10000000 ;
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
static void F_31 ( int * V_64 , struct V_65 * V_66 , int V_1 , int * V_67 )
{
int V_61 ;
int V_68 ;
for ( V_61 = 0 ; V_61 < V_66 -> V_69 ; V_61 ++ ) {
if ( ! F_32 ( V_1 , F_33 ( & V_66 -> V_70 [ V_61 ] ) ) )
continue;
F_34 (thr,
cpumask_bits(&t->sib_thr[i]),
MAX_NR_CPUS)
if ( V_64 [ V_68 ] == - 1 )
V_64 [ V_68 ] = ( * V_67 ) ++ ;
}
}
static void F_35 ( int * V_64 , struct V_65 * V_66 )
{
int V_67 = 0 ;
int V_61 ;
int V_1 ;
for ( V_61 = 0 ; V_61 < V_66 -> V_71 ; V_61 ++ )
F_34 (cpu,
cpumask_bits(&t->sib_core[i]),
MAX_NR_CPUS)
F_31 ( V_64 , V_66 , V_1 , & V_67 ) ;
}
static int F_36 ( char * V_72 , T_3 * V_73 )
{
int V_61 ;
int V_74 = 0 ;
struct V_75 * V_76 ;
int V_77 ;
V_76 = F_37 ( V_72 ) ;
if ( ! V_76 )
return - 1 ;
for ( V_61 = 0 ; V_61 < V_76 -> V_78 ; V_61 ++ ) {
V_77 = V_76 -> V_64 [ V_61 ] ;
if ( V_77 >= V_79 ) {
V_74 = - 1 ;
break;
}
F_38 ( V_77 , F_33 ( V_73 ) ) ;
}
F_39 ( V_76 ) ;
return V_74 ;
}
int F_40 ( char * V_80 , int V_71 ,
char * V_70 , int V_69 )
{
int V_61 ;
struct V_65 V_66 ;
V_66 . V_71 = V_71 ;
V_66 . V_69 = V_69 ;
V_66 . V_80 = calloc ( V_71 , sizeof( T_3 ) ) ;
V_66 . V_70 = calloc ( V_69 , sizeof( T_3 ) ) ;
if ( ! V_66 . V_80 || ! V_66 . V_70 ) {
fprintf ( V_19 , L_107 ) ;
goto exit;
}
for ( V_61 = 0 ; V_61 < V_71 ; V_61 ++ ) {
if ( F_36 ( V_80 , & V_66 . V_80 [ V_61 ] ) ) {
fprintf ( V_19 , L_108 ) ;
goto exit;
}
V_80 += strlen ( V_80 ) + 1 ;
}
for ( V_61 = 0 ; V_61 < V_69 ; V_61 ++ ) {
if ( F_36 ( V_70 , & V_66 . V_70 [ V_61 ] ) ) {
fprintf ( V_19 , L_108 ) ;
goto exit;
}
V_70 += strlen ( V_70 ) + 1 ;
}
V_2 = malloc ( sizeof( int ) * V_79 ) ;
if ( ! V_2 ) {
fprintf ( V_19 , L_107 ) ;
goto exit;
}
for ( V_61 = 0 ; V_61 < V_79 ; V_61 ++ )
V_2 [ V_61 ] = - 1 ;
F_35 ( V_2 , & V_66 ) ;
return 0 ;
exit:
F_41 ( & V_66 . V_80 ) ;
F_41 ( & V_66 . V_70 ) ;
return - 1 ;
}
