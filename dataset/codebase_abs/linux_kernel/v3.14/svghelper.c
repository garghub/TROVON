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
}
void F_6 ( int V_22 , T_1 V_15 , T_1 V_16 , const char * type )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_26 ,
F_3 ( V_15 ) , F_3 ( V_16 ) - F_3 ( V_15 ) , V_22 * V_3 , V_23 , type ) ;
}
void F_7 ( int V_22 , int V_1 , T_1 V_15 , T_1 V_16 , const char * V_24 )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_27 ) ;
fprintf ( V_18 , L_28 , V_1 ,
F_8 ( V_16 - V_15 ) ) ;
if ( V_24 )
fprintf ( V_18 , L_29 , V_24 ) ;
F_6 ( V_22 , V_15 , V_16 , L_30 ) ;
fprintf ( V_18 , L_31 ) ;
}
void F_9 ( int V_22 , int V_1 , T_1 V_15 , T_1 V_16 , const char * V_24 )
{
double V_25 ;
const char * type ;
if ( ! V_18 )
return;
if ( V_26 && V_16 - V_15 > V_26 )
type = L_32 ;
else
type = L_33 ;
fprintf ( V_18 , L_27 ) ;
fprintf ( V_18 , L_34 ,
V_1 , F_8 ( V_16 - V_15 ) ) ;
if ( V_24 )
fprintf ( V_18 , L_35 , V_24 ) ;
fprintf ( V_18 , L_26 ,
F_3 ( V_15 ) , F_3 ( V_16 ) - F_3 ( V_15 ) , V_22 * V_3 , V_23 ,
type ) ;
V_25 = ( F_3 ( V_16 ) - F_3 ( V_15 ) ) ;
if ( V_1 > 9 )
V_25 = V_25 / 2 ;
if ( V_25 > 1.25 )
V_25 = 1.25 ;
V_25 = F_4 ( V_25 ) ;
if ( V_25 > V_27 )
fprintf ( V_18 , L_36 ,
F_3 ( V_15 ) , V_22 * V_3 + V_23 - 1 , V_25 , V_1 + 1 ) ;
fprintf ( V_18 , L_31 ) ;
}
static char * F_8 ( T_1 V_28 )
{
static char V_29 [ 80 ] ;
V_29 [ 0 ] = 0 ;
if ( V_28 < 1000 )
return V_29 ;
if ( V_28 < 1000 * 1000 ) {
sprintf ( V_29 , L_37 , V_28 / 1000.0 ) ;
return V_29 ;
}
sprintf ( V_29 , L_38 , V_28 / 1000.0 / 1000 ) ;
return V_29 ;
}
void F_10 ( int V_22 , int V_1 , T_1 V_15 , T_1 V_16 , const char * V_24 )
{
char * V_29 ;
const char * V_30 ;
double V_31 ;
if ( ! V_18 )
return;
V_30 = L_39 ;
if ( V_16 - V_15 > 10 * 1000000 )
V_30 = L_40 ;
V_29 = F_8 ( V_16 - V_15 ) ;
V_31 = 1.0 * ( F_3 ( V_16 ) - F_3 ( V_15 ) ) ;
if ( V_31 > 3 )
V_31 = 3 ;
V_31 = F_4 ( V_31 ) ;
fprintf ( V_18 , L_41 , F_3 ( V_15 ) , V_22 * V_3 ) ;
fprintf ( V_18 , L_42 , V_1 , F_8 ( V_16 - V_15 ) ) ;
if ( V_24 )
fprintf ( V_18 , L_43 , V_24 ) ;
fprintf ( V_18 , L_44 ,
F_3 ( V_16 ) - F_3 ( V_15 ) , V_23 , V_30 ) ;
if ( V_31 > V_27 )
fprintf ( V_18 , L_45 ,
V_31 , V_29 ) ;
fprintf ( V_18 , L_31 ) ;
}
static char * F_11 ( void )
{
static char V_32 [ 255 ] ;
char V_33 [ 256 ] ;
T_2 * V_34 ;
V_32 [ 0 ] = 0 ;
V_34 = fopen ( L_46 , L_47 ) ;
if ( V_34 ) {
while ( fgets ( V_33 , 255 , V_34 ) ) {
if ( strstr ( V_33 , L_48 ) ) {
strncpy ( V_32 , & V_33 [ 13 ] , 255 ) ;
break;
}
}
fclose ( V_34 ) ;
}
V_34 = fopen ( L_49 , L_47 ) ;
if ( V_34 ) {
while ( fgets ( V_33 , 255 , V_34 ) ) {
unsigned int V_35 ;
V_35 = F_12 ( V_33 , NULL , 10 ) ;
if ( V_35 > V_36 )
V_36 = V_35 ;
}
fclose ( V_34 ) ;
}
return V_32 ;
}
void F_13 ( int V_1 , T_1 V_37 , T_1 V_38 )
{
char V_39 [ 80 ] ;
if ( ! V_18 )
return;
V_36 = V_37 ;
V_40 = V_38 ;
fprintf ( V_18 , L_27 ) ;
fprintf ( V_18 , L_50 ,
F_3 ( V_7 ) ,
F_3 ( V_8 ) - F_3 ( V_7 ) ,
F_2 ( V_1 ) , V_3 + V_23 ) ;
sprintf ( V_39 , L_51 , ( int ) V_1 ) ;
fprintf ( V_18 , L_52 ,
10 + F_3 ( V_7 ) , F_2 ( V_1 ) + V_23 / 2 , V_39 ) ;
fprintf ( V_18 , L_53 ,
10 + F_3 ( V_7 ) , F_2 ( V_1 ) + V_3 + V_23 - 4 , F_11 () ) ;
fprintf ( V_18 , L_31 ) ;
}
void F_14 ( int V_1 , T_1 V_15 , T_1 V_16 , int V_41 , const char * V_42 , const char * V_24 )
{
double V_43 ;
const char * type ;
if ( ! V_18 )
return;
if ( V_26 && V_16 - V_15 >= V_26 )
type = L_32 ;
else if ( V_44 && strstr ( V_42 , V_44 ) )
type = L_32 ;
else
type = L_33 ;
fprintf ( V_18 , L_41 , F_3 ( V_15 ) , F_2 ( V_1 ) ) ;
fprintf ( V_18 , L_54 , V_41 , V_42 , F_8 ( V_16 - V_15 ) ) ;
if ( V_24 )
fprintf ( V_18 , L_35 , V_24 ) ;
fprintf ( V_18 , L_44 ,
F_3 ( V_16 ) - F_3 ( V_15 ) , V_3 + V_23 , type ) ;
V_43 = F_3 ( V_16 ) - F_3 ( V_15 ) ;
if ( V_43 > 6 )
V_43 = 6 ;
V_43 = F_4 ( V_43 ) ;
if ( V_43 > V_27 )
fprintf ( V_18 , L_55 ,
V_43 , V_42 ) ;
fprintf ( V_18 , L_31 ) ;
}
void F_15 ( int V_1 , T_1 V_15 , T_1 V_16 , int type )
{
double V_43 ;
char V_30 [ 128 ] ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_27 ) ;
if ( type > 6 )
type = 6 ;
sprintf ( V_30 , L_56 , type ) ;
fprintf ( V_18 , L_57 ,
V_30 ,
F_3 ( V_15 ) , F_3 ( V_16 ) - F_3 ( V_15 ) ,
F_2 ( V_1 ) , V_3 + V_23 ) ;
V_43 = ( F_3 ( V_16 ) - F_3 ( V_15 ) ) / 2.0 ;
if ( V_43 > 6 )
V_43 = 6 ;
V_43 = F_4 ( V_43 ) ;
if ( V_43 > V_27 )
fprintf ( V_18 , L_58 ,
F_3 ( V_15 ) , F_2 ( V_1 ) + V_43 , V_43 , type ) ;
fprintf ( V_18 , L_31 ) ;
}
static char * F_16 ( unsigned long V_45 )
{
static char V_46 [ 1024 ] ;
unsigned long long V_47 ;
memset ( V_46 , 0 , 1024 ) ;
V_47 = V_45 ;
sprintf ( V_46 , L_59 , V_47 ) ;
if ( V_47 > 1000 )
sprintf ( V_46 , L_60 , ( V_47 + 500 ) / 1000 ) ;
if ( V_47 > 1500000 )
sprintf ( V_46 , L_61 , ( V_47 + 5000.0 ) / 1000000 ) ;
if ( V_47 == V_40 )
sprintf ( V_46 , L_62 ) ;
return V_46 ;
}
void F_17 ( int V_1 , T_1 V_15 , T_1 V_16 , T_1 V_35 )
{
double V_48 = 0 ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_27 ) ;
if ( V_36 )
V_48 = V_35 * 1.0 / V_36 * ( V_23 + V_3 ) ;
V_48 = 1 + F_2 ( V_1 ) + V_3 + V_23 - V_48 ;
fprintf ( V_18 , L_63 ,
F_3 ( V_15 ) , F_3 ( V_16 ) , V_48 , V_48 ) ;
fprintf ( V_18 , L_64 ,
F_3 ( V_15 ) , V_48 + 0.9 , F_16 ( V_35 ) ) ;
fprintf ( V_18 , L_31 ) ;
}
void F_18 ( T_1 V_15 , int V_49 , char * V_50 , int V_51 , char * V_52 , const char * V_24 )
{
double V_48 ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_27 ) ;
fprintf ( V_18 , L_65 ,
V_50 ? V_50 : L_66 ,
V_52 ? V_52 : L_66 ) ;
if ( V_24 )
fprintf ( V_18 , L_67 , V_24 ) ;
if ( V_49 < V_51 ) {
if ( V_49 ) {
fprintf ( V_18 , L_68 ,
F_3 ( V_15 ) , V_49 * V_3 + V_23 , F_3 ( V_15 ) , V_49 * V_3 + V_23 + V_3 / 32 ) ;
if ( V_52 )
fprintf ( V_18 , L_69 ,
F_3 ( V_15 ) , V_49 * V_3 + V_23 + V_23 / 48 , V_52 ) ;
}
if ( V_51 ) {
fprintf ( V_18 , L_68 ,
F_3 ( V_15 ) , V_51 * V_3 - V_3 / 32 , F_3 ( V_15 ) , V_51 * V_3 ) ;
if ( V_50 )
fprintf ( V_18 , L_69 ,
F_3 ( V_15 ) , V_51 * V_3 - V_3 / 32 , V_50 ) ;
}
} else {
if ( V_51 ) {
fprintf ( V_18 , L_68 ,
F_3 ( V_15 ) , V_51 * V_3 + V_23 , F_3 ( V_15 ) , V_51 * V_3 + V_23 + V_3 / 32 ) ;
if ( V_50 )
fprintf ( V_18 , L_70 ,
F_3 ( V_15 ) , V_51 * V_3 + V_23 + V_3 / 48 , V_50 ) ;
}
if ( V_49 ) {
fprintf ( V_18 , L_68 ,
F_3 ( V_15 ) , V_49 * V_3 - V_3 / 32 , F_3 ( V_15 ) , V_49 * V_3 ) ;
if ( V_52 )
fprintf ( V_18 , L_70 ,
F_3 ( V_15 ) , V_49 * V_3 - V_23 / 32 , V_52 ) ;
}
}
V_48 = V_49 * V_3 ;
if ( V_51 > V_49 )
V_48 += V_23 ;
if ( V_49 )
fprintf ( V_18 , L_71 ,
F_3 ( V_15 ) , V_48 ) ;
fprintf ( V_18 , L_31 ) ;
}
void F_19 ( T_1 V_15 , int V_49 , int V_51 , const char * V_24 )
{
double V_48 ;
if ( ! V_18 )
return;
fprintf ( V_18 , L_27 ) ;
if ( V_24 )
fprintf ( V_18 , L_67 , V_24 ) ;
if ( V_49 < V_51 )
fprintf ( V_18 , L_68 ,
F_3 ( V_15 ) , V_49 * V_3 + V_23 , F_3 ( V_15 ) , V_51 * V_3 ) ;
else
fprintf ( V_18 , L_68 ,
F_3 ( V_15 ) , V_51 * V_3 + V_23 , F_3 ( V_15 ) , V_49 * V_3 ) ;
V_48 = V_49 * V_3 ;
if ( V_51 > V_49 )
V_48 += V_23 ;
fprintf ( V_18 , L_71 ,
F_3 ( V_15 ) , V_48 ) ;
fprintf ( V_18 , L_31 ) ;
}
void F_20 ( T_1 V_15 , int V_53 , const char * V_24 )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_27 ) ;
fprintf ( V_18 , L_72 ) ;
if ( V_24 )
fprintf ( V_18 , L_67 , V_24 ) ;
fprintf ( V_18 , L_73 ,
F_3 ( V_15 ) , V_53 * V_3 ) ;
fprintf ( V_18 , L_73 ,
F_3 ( V_15 ) , V_53 * V_3 + V_23 ) ;
fprintf ( V_18 , L_31 ) ;
}
void F_21 ( int V_22 , T_1 V_15 , const char * V_29 )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_52 ,
F_3 ( V_15 ) , V_22 * V_3 + V_23 / 2 , V_29 ) ;
}
static void F_22 ( int V_5 , const char * V_29 , const char * V_30 )
{
double V_54 ;
V_54 = V_23 / 2 ;
fprintf ( V_18 , L_74 ,
V_5 , V_54 , V_54 , V_30 ) ;
fprintf ( V_18 , L_75 ,
V_5 + V_54 + 5 , V_54 , 0.8 * V_54 , V_29 ) ;
}
void F_23 ( void )
{
if ( ! V_18 )
return;
fprintf ( V_18 , L_27 ) ;
F_22 ( 0 , L_76 , L_33 ) ;
F_22 ( 100 , L_77 , L_78 ) ;
F_22 ( 200 , L_79 , L_80 ) ;
F_22 ( 350 , L_81 , L_82 ) ;
F_22 ( 550 , L_83 , L_84 ) ;
F_22 ( 650 , L_85 , L_39 ) ;
F_22 ( 800 , L_86 , L_30 ) ;
fprintf ( V_18 , L_31 ) ;
}
void F_24 ( void )
{
T_1 V_55 ;
if ( ! V_18 )
return;
V_55 = V_7 ;
while ( V_55 < V_8 ) {
int V_56 = 220 ;
double V_57 = 0.075 ;
if ( ( V_55 % 100000000 ) == 0 ) {
V_57 = 0.5 ;
V_56 = 192 ;
}
if ( ( V_55 % 1000000000 ) == 0 ) {
V_57 = 2.0 ;
V_56 = 128 ;
}
fprintf ( V_18 , L_87 V_21 L_88 ,
F_3 ( V_55 ) , V_3 / 2 , F_3 ( V_55 ) , V_20 , V_56 , V_56 , V_56 , V_57 ) ;
V_55 += 10000000 ;
}
}
void F_25 ( void )
{
if ( V_18 ) {
fprintf ( V_18 , L_89 ) ;
fclose ( V_18 ) ;
V_18 = NULL ;
}
}
static void F_26 ( int * V_58 , struct V_59 * V_60 , int V_1 , int * V_61 )
{
int V_55 ;
int V_62 ;
for ( V_55 = 0 ; V_55 < V_60 -> V_63 ; V_55 ++ ) {
if ( ! F_27 ( V_1 , F_28 ( & V_60 -> V_64 [ V_55 ] ) ) )
continue;
F_29 (thr,
cpumask_bits(&t->sib_thr[i]),
MAX_NR_CPUS)
if ( V_58 [ V_62 ] == - 1 )
V_58 [ V_62 ] = ( * V_61 ) ++ ;
}
}
static void F_30 ( int * V_58 , struct V_59 * V_60 )
{
int V_61 = 0 ;
int V_55 ;
int V_1 ;
for ( V_55 = 0 ; V_55 < V_60 -> V_65 ; V_55 ++ )
F_29 (cpu,
cpumask_bits(&t->sib_core[i]),
MAX_NR_CPUS)
F_26 ( V_58 , V_60 , V_1 , & V_61 ) ;
}
static int F_31 ( char * V_66 , T_3 * V_67 )
{
int V_55 ;
int V_68 = 0 ;
struct V_69 * V_70 ;
int V_71 ;
V_70 = F_32 ( V_66 ) ;
if ( ! V_70 )
return - 1 ;
for ( V_55 = 0 ; V_55 < V_70 -> V_72 ; V_55 ++ ) {
V_71 = V_70 -> V_58 [ V_55 ] ;
if ( V_71 >= V_73 ) {
V_68 = - 1 ;
break;
}
F_33 ( V_71 , F_28 ( V_67 ) ) ;
}
F_34 ( V_70 ) ;
return V_68 ;
}
int F_35 ( char * V_74 , int V_65 ,
char * V_64 , int V_63 )
{
int V_55 ;
struct V_59 V_60 ;
V_60 . V_65 = V_65 ;
V_60 . V_63 = V_63 ;
V_60 . V_74 = calloc ( V_65 , sizeof( T_3 ) ) ;
V_60 . V_64 = calloc ( V_63 , sizeof( T_3 ) ) ;
if ( ! V_60 . V_74 || ! V_60 . V_64 ) {
fprintf ( V_19 , L_90 ) ;
goto exit;
}
for ( V_55 = 0 ; V_55 < V_65 ; V_55 ++ ) {
if ( F_31 ( V_74 , & V_60 . V_74 [ V_55 ] ) ) {
fprintf ( V_19 , L_91 ) ;
goto exit;
}
V_74 += strlen ( V_74 ) + 1 ;
}
for ( V_55 = 0 ; V_55 < V_63 ; V_55 ++ ) {
if ( F_31 ( V_64 , & V_60 . V_64 [ V_55 ] ) ) {
fprintf ( V_19 , L_91 ) ;
goto exit;
}
V_64 += strlen ( V_64 ) + 1 ;
}
V_2 = malloc ( sizeof( int ) * V_73 ) ;
if ( ! V_2 ) {
fprintf ( V_19 , L_90 ) ;
goto exit;
}
for ( V_55 = 0 ; V_55 < V_73 ; V_55 ++ )
V_2 [ V_55 ] = - 1 ;
F_30 ( V_2 , & V_60 ) ;
return 0 ;
exit:
F_36 ( & V_60 . V_74 ) ;
F_36 ( & V_60 . V_64 ) ;
return - 1 ;
}
