static int F_1 ( int V_1 )
{
unsigned char args [ 4 ] = { V_2 , 0 , 0 , 0 } ;
int V_3 ;
if ( F_2 ( V_1 , V_4 , & args )
&& ( args [ 0 ] = V_5 )
&& F_2 ( V_1 , V_4 , & args ) ) {
if ( V_6 != V_7 || args [ 0 ] != 0 || args [ 1 ] != 0 ) {
V_3 = - 1 ;
} else
V_3 = 0 ;
} else {
V_3 = ( args [ 2 ] == 255 ) ? 1 : 0 ;
}
F_3 ( printf ( L_1 , V_3 ) ) ;
return V_3 ;
}
static char * F_4 ( int V_8 )
{
if ( V_8 == - 1 ) return L_2 ;
if ( V_8 == 0 ) return L_3 ;
if ( V_8 == 1 ) return L_4 ;
return L_5 ;
}
static char * F_5 ( T_1 time )
{
char * V_9 = ctime ( & time ) ;
V_9 [ strlen ( V_9 ) - 1 ] = 0 ;
return V_9 ;
}
static void F_6 ( int V_1 )
{
T_1 V_10 ;
int V_11 ;
T_1 V_12 ;
int V_13 ;
T_1 V_14 = 0 ;
T_1 V_15 ;
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
T_1 V_18 = 0 ;
T_1 V_19 = 0 ;
int V_20 = 0 ;
float V_21 ;
printf ( L_6 ) ;
V_11 = F_1 ( V_1 ) ;
V_10 = V_12 = time ( 0 ) ;
printf ( L_7 , F_4 ( V_11 ) ) ;
while( ! V_22 ) {
F_7 ( 1 ) ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 != V_11 || V_22 ) {
V_20 ++ ;
V_14 = time ( 0 ) ;
V_15 = V_14 - V_12 ;
if ( V_11 == 1 ) V_16 += V_15 ;
else if ( V_11 == 0 ) V_17 += V_15 ;
else V_18 += V_15 ;
V_11 = V_13 ;
V_12 = V_14 ;
printf ( L_8 , F_5 ( V_14 ) ,
F_4 ( V_13 ) ) ;
}
}
V_20 -- ;
V_19 = time ( 0 ) - V_10 ;
printf ( L_9 , V_14 - V_10 ) ;
printf ( L_10 , V_20 ) ;
V_21 = ( float ) V_17 / ( float ) V_19 * 100 ;
printf ( L_11 , V_17 , V_21 ) ;
V_21 = ( float ) V_16 / ( float ) V_19 * 100 ;
printf ( L_12 , V_16 , V_21 ) ;
V_21 = ( float ) V_18 / ( float ) V_19 * 100 ;
printf ( L_13 , V_18 , V_21 ) ;
}
static void F_8 ( int V_23 )
{
V_22 = 1 ;
}
static void F_9 ( void )
{
puts ( L_14 ) ;
exit ( 0 ) ;
}
int main ( int V_24 , char * * V_25 )
{
int V_1 ;
char * V_26 = 0 ;
int V_27 = 60 ;
if ( V_24 == 2 )
V_26 = V_25 [ 1 ] ;
else if ( V_24 == 4 ) {
V_27 = atoi ( V_25 [ 2 ] ) ;
V_26 = V_25 [ 3 ] ;
} else
F_9 () ;
if ( ! ( V_1 = F_10 ( V_26 , V_28 | V_29 ) ) ) {
printf ( L_15 , V_26 , strerror ( V_6 ) ) ;
exit ( - 1 ) ;
}
if ( V_27 ) {
printf ( L_16
L_17 , V_27 ) ;
F_7 ( V_27 ) ;
} else
puts ( L_18 ) ;
signal ( V_30 , F_8 ) ;
F_6 ( V_1 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
