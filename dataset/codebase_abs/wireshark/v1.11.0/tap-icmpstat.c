static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
F_2 ( V_2 -> V_3 ) ;
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
V_2 -> V_4 = 1.0 * V_5 ;
}
static T_2 F_3 ( T_3 V_6 , T_3 V_7 )
{
double V_8 , V_9 ;
V_8 = * ( double * ) V_6 ;
V_9 = * ( double * ) V_7 ;
if ( V_8 < V_9 )
return - 1 ;
if ( V_8 > V_9 )
return 1 ;
return 0 ;
}
static int
F_4 ( void * V_1 , T_4 * T_5 V_10 , T_6 * T_7 V_10 , const void * V_11 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
const T_8 * V_12 = ( const T_8 * ) V_11 ;
double V_13 , * V_14 ;
if ( V_12 == NULL )
return 0 ;
if ( V_12 -> V_15 ) {
V_13 = F_5 ( & V_12 -> V_13 ) ;
V_14 = F_6 ( double , 1 ) ;
if ( V_14 == NULL )
return 0 ;
* V_14 = V_13 ;
V_2 -> V_3 = F_7 ( V_2 -> V_3 , V_14 ) ;
V_2 -> V_16 ++ ;
if ( V_2 -> V_4 > V_13 ) {
V_2 -> V_17 = V_12 -> V_15 ;
V_2 -> V_4 = V_13 ;
}
if ( V_2 -> V_18 < V_13 ) {
V_2 -> V_19 = V_12 -> V_15 ;
V_2 -> V_18 = V_13 ;
}
V_2 -> V_20 += V_13 ;
} else if ( V_12 -> V_21 )
V_2 -> V_22 ++ ;
else
return 0 ;
return 1 ;
}
static void F_8 ( T_1 * V_2 , double * V_23 , double * V_24 , double * V_25 )
{
T_9 * V_26 ;
double V_27 ;
double V_28 = 0.0 ;
V_2 -> V_3 = F_9 ( V_2 -> V_3 , F_3 ) ;
V_26 = V_2 -> V_3 ;
if ( V_2 -> V_16 == 0 || V_26 == NULL ) {
* V_23 = 0.0 ;
* V_24 = 0.0 ;
* V_25 = 0.0 ;
return;
}
* V_23 = V_2 -> V_20 / V_2 -> V_16 ;
if ( V_2 -> V_16 & 1 )
* V_24 = * ( double * ) F_10 ( V_26 , V_2 -> V_16 / 2 ) ;
else {
* V_24 =
( * ( double * ) F_10 ( V_26 , ( V_2 -> V_16 - 1 ) / 2 ) +
* ( double * ) F_10 ( V_26 , V_2 -> V_16 / 2 ) ) / 2 ;
}
for ( ; V_26 ; V_26 = F_11 ( V_26 ) ) {
V_27 = * ( double * ) V_26 -> V_11 - * V_23 ;
V_28 += V_27 * V_27 ;
}
if ( V_2 -> V_16 > 1 )
* V_25 = sqrt ( V_28 / ( V_2 -> V_16 - 1 ) ) ;
else
* V_25 = 0.0 ;
}
static void
F_12 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
unsigned int V_29 ;
double V_23 , V_25 , V_24 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 , V_2 -> V_30 ? V_2 -> V_30 : L_5 ) ;
printf ( L_6 ) ;
if ( V_2 -> V_22 ) {
V_29 = V_2 -> V_22 - V_2 -> V_16 ;
F_8 ( V_2 , & V_23 , & V_24 , & V_25 ) ;
printf ( L_7 ,
V_2 -> V_22 , V_2 -> V_16 , V_29 ,
100.0 * V_29 / V_2 -> V_22 ) ;
printf ( L_8 ) ;
printf ( L_9 ,
V_2 -> V_4 >= V_5 ? 0.0 : V_2 -> V_4 ,
V_2 -> V_18 , V_23 , V_24 , V_25 ,
V_2 -> V_17 , V_2 -> V_19 ) ;
} else {
printf ( L_10 ) ;
printf ( L_8 ) ;
printf ( L_11 ) ;
}
printf ( L_2 ) ;
}
static void
F_13 ( const char * V_31 , void * T_10 V_10 )
{
T_1 * V_2 ;
const char * V_30 = NULL ;
T_11 * V_32 ;
if ( strstr ( V_31 , L_12 ) )
V_30 = V_31 + strlen ( L_12 ) ;
V_2 = ( T_1 * ) F_14 ( sizeof( T_1 ) ) ;
if ( V_2 == NULL ) {
fprintf ( V_33 , L_13 ) ;
exit ( 1 ) ;
}
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
V_2 -> V_4 = 1.0 * V_5 ;
if ( V_30 )
V_2 -> V_30 = F_15 ( V_30 ) ;
V_32 = F_16 ( L_14 , V_2 , V_2 -> V_30 ,
V_34 , F_1 , F_4 , F_12 ) ;
if ( V_32 ) {
if ( V_2 -> V_30 )
F_17 ( V_2 -> V_30 ) ;
F_17 ( V_2 ) ;
fprintf ( V_33 , L_15 ,
V_32 -> V_35 ) ;
F_18 ( V_32 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_19 ( void )
{
F_20 ( L_16 , F_13 , NULL ) ;
}
