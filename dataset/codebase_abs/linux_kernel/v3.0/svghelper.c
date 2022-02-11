static double F_1 ( int V_1 )
{
return 2 * V_1 + 1 ;
}
static double F_2 ( int V_1 )
{
return F_1 ( V_1 ) * V_2 ;
}
static double F_3 ( T_1 V_3 )
{
double V_4 ;
V_4 = 1.0 * V_5 * ( V_3 - V_6 ) / ( V_7 - V_6 ) ;
return V_4 ;
}
static double F_4 ( double V_8 )
{
int V_9 = 100 ;
double V_10 = 10.0 ;
if ( V_8 >= 10.0 )
return V_8 ;
while ( V_9 -- ) {
if ( V_8 >= V_10 )
return V_10 ;
V_10 = V_10 / 2.0 ;
}
return V_8 ;
}
void F_5 ( const char * V_11 , int V_12 , int V_13 , T_1 V_14 , T_1 V_15 )
{
int V_16 ;
V_17 = fopen ( V_11 , L_1 ) ;
if ( ! V_17 ) {
fprintf ( V_18 , L_2 , V_11 ) ;
return;
}
V_6 = V_14 ;
V_6 = V_6 / 100000000 * 100000000 ;
V_7 = V_15 ;
V_16 = ( V_7 - V_6 ) / 5000000 ;
if ( V_16 > V_5 )
V_5 = V_16 ;
V_19 = ( 1 + V_13 + F_1 ( V_12 ) ) * V_2 ;
fprintf ( V_17 , L_3 ) ;
fprintf ( V_17 , L_4 V_20 L_5 , V_5 , V_19 ) ;
fprintf ( V_17 , L_6 ) ;
fprintf ( V_17 , L_7 ) ;
fprintf ( V_17 , L_8 ) ;
fprintf ( V_17 , L_9 ) ;
fprintf ( V_17 , L_10 ) ;
fprintf ( V_17 , L_11 ) ;
fprintf ( V_17 , L_12 ) ;
fprintf ( V_17 , L_13 ) ;
fprintf ( V_17 , L_14 ) ;
fprintf ( V_17 , L_15 ) ;
fprintf ( V_17 , L_16 ) ;
fprintf ( V_17 , L_17 ) ;
fprintf ( V_17 , L_18 ) ;
fprintf ( V_17 , L_19 ) ;
fprintf ( V_17 , L_20 ) ;
fprintf ( V_17 , L_21 ) ;
fprintf ( V_17 , L_22 ) ;
fprintf ( V_17 , L_23 ) ;
}
void F_6 ( int V_21 , T_1 V_14 , T_1 V_15 , const char * type )
{
if ( ! V_17 )
return;
fprintf ( V_17 , L_24 ,
F_3 ( V_14 ) , F_3 ( V_15 ) - F_3 ( V_14 ) , V_21 * V_2 , V_22 , type ) ;
}
void F_7 ( int V_21 , int V_1 , T_1 V_14 , T_1 V_15 )
{
double V_23 ;
if ( ! V_17 )
return;
fprintf ( V_17 , L_25 ,
F_3 ( V_14 ) , F_3 ( V_15 ) - F_3 ( V_14 ) , V_21 * V_2 , V_22 ) ;
V_23 = ( F_3 ( V_15 ) - F_3 ( V_14 ) ) ;
if ( V_1 > 9 )
V_23 = V_23 / 2 ;
if ( V_23 > 1.25 )
V_23 = 1.25 ;
V_23 = F_4 ( V_23 ) ;
if ( V_23 > V_24 )
fprintf ( V_17 , L_26 ,
F_3 ( V_14 ) , V_21 * V_2 + V_22 - 1 , V_23 , V_1 + 1 ) ;
}
static char * F_8 ( T_1 V_25 )
{
static char V_26 [ 80 ] ;
V_26 [ 0 ] = 0 ;
if ( V_25 < 1000 )
return V_26 ;
if ( V_25 < 1000 * 1000 ) {
sprintf ( V_26 , L_27 , V_25 / 1000.0 ) ;
return V_26 ;
}
sprintf ( V_26 , L_28 , V_25 / 1000.0 / 1000 ) ;
return V_26 ;
}
void F_9 ( int V_21 , T_1 V_14 , T_1 V_15 )
{
char * V_26 ;
const char * V_27 ;
double V_28 ;
if ( ! V_17 )
return;
V_27 = L_29 ;
if ( V_15 - V_14 > 10 * 1000000 )
V_27 = L_30 ;
V_26 = F_8 ( V_15 - V_14 ) ;
V_28 = 1.0 * ( F_3 ( V_15 ) - F_3 ( V_14 ) ) ;
if ( V_28 > 3 )
V_28 = 3 ;
V_28 = F_4 ( V_28 ) ;
fprintf ( V_17 , L_31 , F_3 ( V_14 ) , V_21 * V_2 ) ;
fprintf ( V_17 , L_32 ,
F_3 ( V_15 ) - F_3 ( V_14 ) , V_22 , V_27 ) ;
if ( V_28 > V_24 )
fprintf ( V_17 , L_33 ,
V_28 , V_26 ) ;
fprintf ( V_17 , L_34 ) ;
}
static char * F_10 ( void )
{
static char V_29 [ 255 ] ;
char V_30 [ 256 ] ;
T_2 * V_31 ;
V_29 [ 0 ] = 0 ;
V_31 = fopen ( L_35 , L_36 ) ;
if ( V_31 ) {
while ( fgets ( V_30 , 255 , V_31 ) ) {
if ( strstr ( V_30 , L_37 ) ) {
strncpy ( V_29 , & V_30 [ 13 ] , 255 ) ;
break;
}
}
fclose ( V_31 ) ;
}
V_31 = fopen ( L_38 , L_36 ) ;
if ( V_31 ) {
while ( fgets ( V_30 , 255 , V_31 ) ) {
unsigned int V_32 ;
V_32 = F_11 ( V_30 , NULL , 10 ) ;
if ( V_32 > V_33 )
V_33 = V_32 ;
}
fclose ( V_31 ) ;
}
return V_29 ;
}
void F_12 ( int V_1 , T_1 V_34 , T_1 V_35 )
{
char V_36 [ 80 ] ;
if ( ! V_17 )
return;
V_33 = V_34 ;
V_37 = V_35 ;
fprintf ( V_17 , L_39 ,
F_3 ( V_6 ) ,
F_3 ( V_7 ) - F_3 ( V_6 ) ,
F_2 ( V_1 ) , V_2 + V_22 ) ;
sprintf ( V_36 , L_40 , ( int ) V_1 + 1 ) ;
fprintf ( V_17 , L_41 ,
10 + F_3 ( V_6 ) , F_2 ( V_1 ) + V_22 / 2 , V_36 ) ;
fprintf ( V_17 , L_42 ,
10 + F_3 ( V_6 ) , F_2 ( V_1 ) + V_2 + V_22 - 4 , F_10 () ) ;
}
void F_13 ( int V_1 , T_1 V_14 , T_1 V_15 , const char * type , const char * V_38 )
{
double V_39 ;
if ( ! V_17 )
return;
fprintf ( V_17 , L_31 , F_3 ( V_14 ) , F_2 ( V_1 ) ) ;
fprintf ( V_17 , L_32 ,
F_3 ( V_15 ) - F_3 ( V_14 ) , V_2 + V_22 , type ) ;
V_39 = F_3 ( V_15 ) - F_3 ( V_14 ) ;
if ( V_39 > 6 )
V_39 = 6 ;
V_39 = F_4 ( V_39 ) ;
if ( V_39 > V_24 )
fprintf ( V_17 , L_43 ,
V_39 , V_38 ) ;
fprintf ( V_17 , L_34 ) ;
}
void F_14 ( int V_1 , T_1 V_14 , T_1 V_15 , int type )
{
double V_39 ;
char V_27 [ 128 ] ;
if ( ! V_17 )
return;
if ( type > 6 )
type = 6 ;
sprintf ( V_27 , L_44 , type ) ;
fprintf ( V_17 , L_45 ,
V_27 ,
F_3 ( V_14 ) , F_3 ( V_15 ) - F_3 ( V_14 ) ,
F_2 ( V_1 ) , V_2 + V_22 ) ;
V_39 = ( F_3 ( V_15 ) - F_3 ( V_14 ) ) / 2.0 ;
if ( V_39 > 6 )
V_39 = 6 ;
V_39 = F_4 ( V_39 ) ;
if ( V_39 > V_24 )
fprintf ( V_17 , L_46 ,
F_3 ( V_14 ) , F_2 ( V_1 ) + V_39 , V_39 , type ) ;
}
static char * F_15 ( unsigned long V_40 )
{
static char V_41 [ 1024 ] ;
unsigned long long V_42 ;
memset ( V_41 , 0 , 1024 ) ;
V_42 = V_40 ;
sprintf ( V_41 , L_47 , V_42 ) ;
if ( V_42 > 1000 )
sprintf ( V_41 , L_48 , ( V_42 + 500 ) / 1000 ) ;
if ( V_42 > 1500000 )
sprintf ( V_41 , L_49 , ( V_42 + 5000.0 ) / 1000000 ) ;
if ( V_42 == V_37 )
sprintf ( V_41 , L_50 ) ;
return V_41 ;
}
void F_16 ( int V_1 , T_1 V_14 , T_1 V_15 , T_1 V_32 )
{
double V_43 = 0 ;
if ( ! V_17 )
return;
if ( V_33 )
V_43 = V_32 * 1.0 / V_33 * ( V_22 + V_2 ) ;
V_43 = 1 + F_2 ( V_1 ) + V_2 + V_22 - V_43 ;
fprintf ( V_17 , L_51 ,
F_3 ( V_14 ) , F_3 ( V_15 ) , V_43 , V_43 ) ;
fprintf ( V_17 , L_52 ,
F_3 ( V_14 ) , V_43 + 0.9 , F_15 ( V_32 ) ) ;
}
void F_17 ( T_1 V_14 , int V_44 , char * V_45 , int V_46 , char * V_47 )
{
double V_43 ;
if ( ! V_17 )
return;
if ( V_44 < V_46 ) {
if ( V_44 ) {
fprintf ( V_17 , L_53 ,
F_3 ( V_14 ) , V_44 * V_2 + V_22 , F_3 ( V_14 ) , V_44 * V_2 + V_22 + V_2 / 32 ) ;
if ( V_47 )
fprintf ( V_17 , L_54 ,
F_3 ( V_14 ) , V_44 * V_2 + V_22 + V_22 / 48 , V_47 ) ;
}
if ( V_46 ) {
fprintf ( V_17 , L_53 ,
F_3 ( V_14 ) , V_46 * V_2 - V_2 / 32 , F_3 ( V_14 ) , V_46 * V_2 ) ;
if ( V_45 )
fprintf ( V_17 , L_54 ,
F_3 ( V_14 ) , V_46 * V_2 - V_2 / 32 , V_45 ) ;
}
} else {
if ( V_46 ) {
fprintf ( V_17 , L_53 ,
F_3 ( V_14 ) , V_46 * V_2 + V_22 , F_3 ( V_14 ) , V_46 * V_2 + V_22 + V_2 / 32 ) ;
if ( V_45 )
fprintf ( V_17 , L_55 ,
F_3 ( V_14 ) , V_46 * V_2 + V_22 + V_2 / 48 , V_45 ) ;
}
if ( V_44 ) {
fprintf ( V_17 , L_53 ,
F_3 ( V_14 ) , V_44 * V_2 - V_2 / 32 , F_3 ( V_14 ) , V_44 * V_2 ) ;
if ( V_47 )
fprintf ( V_17 , L_55 ,
F_3 ( V_14 ) , V_44 * V_2 - V_22 / 32 , V_47 ) ;
}
}
V_43 = V_44 * V_2 ;
if ( V_46 > V_44 )
V_43 += V_22 ;
if ( V_44 )
fprintf ( V_17 , L_56 ,
F_3 ( V_14 ) , V_43 ) ;
}
void F_18 ( T_1 V_14 , int V_44 , int V_46 )
{
double V_43 ;
if ( ! V_17 )
return;
if ( V_44 < V_46 )
fprintf ( V_17 , L_53 ,
F_3 ( V_14 ) , V_44 * V_2 + V_22 , F_3 ( V_14 ) , V_46 * V_2 ) ;
else
fprintf ( V_17 , L_53 ,
F_3 ( V_14 ) , V_46 * V_2 + V_22 , F_3 ( V_14 ) , V_44 * V_2 ) ;
V_43 = V_44 * V_2 ;
if ( V_46 > V_44 )
V_43 += V_22 ;
fprintf ( V_17 , L_56 ,
F_3 ( V_14 ) , V_43 ) ;
}
void F_19 ( T_1 V_14 , int V_48 )
{
if ( ! V_17 )
return;
fprintf ( V_17 , L_57 ,
F_3 ( V_14 ) , V_48 * V_2 ) ;
fprintf ( V_17 , L_57 ,
F_3 ( V_14 ) , V_48 * V_2 + V_22 ) ;
}
void F_20 ( int V_21 , T_1 V_14 , const char * V_26 )
{
if ( ! V_17 )
return;
fprintf ( V_17 , L_41 ,
F_3 ( V_14 ) , V_21 * V_2 + V_22 / 2 , V_26 ) ;
}
static void F_21 ( int V_4 , const char * V_26 , const char * V_27 )
{
double V_49 ;
V_49 = V_22 / 2 ;
fprintf ( V_17 , L_58 ,
V_4 , V_49 , V_49 , V_27 ) ;
fprintf ( V_17 , L_59 ,
V_4 + V_49 + 5 , V_49 , 0.8 * V_49 , V_26 ) ;
}
void F_22 ( void )
{
if ( ! V_17 )
return;
F_21 ( 0 , L_60 , L_61 ) ;
F_21 ( 100 , L_62 , L_63 ) ;
F_21 ( 200 , L_64 , L_65 ) ;
F_21 ( 350 , L_66 , L_67 ) ;
F_21 ( 550 , L_68 , L_69 ) ;
F_21 ( 650 , L_70 , L_29 ) ;
F_21 ( 800 , L_71 , L_72 ) ;
}
void F_23 ( void )
{
T_1 V_50 ;
if ( ! V_17 )
return;
V_50 = V_6 ;
while ( V_50 < V_7 ) {
int V_51 = 220 ;
double V_52 = 0.075 ;
if ( ( V_50 % 100000000 ) == 0 ) {
V_52 = 0.5 ;
V_51 = 192 ;
}
if ( ( V_50 % 1000000000 ) == 0 ) {
V_52 = 2.0 ;
V_51 = 128 ;
}
fprintf ( V_17 , L_73 V_20 L_74 ,
F_3 ( V_50 ) , V_2 / 2 , F_3 ( V_50 ) , V_19 , V_51 , V_51 , V_51 , V_52 ) ;
V_50 += 10000000 ;
}
}
void F_24 ( void )
{
if ( V_17 ) {
fprintf ( V_17 , L_75 ) ;
fclose ( V_17 ) ;
V_17 = NULL ;
}
}
