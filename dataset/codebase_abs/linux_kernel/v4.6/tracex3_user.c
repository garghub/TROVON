static void F_1 ( int V_1 )
{
unsigned int V_2 = F_2 ( V_3 ) ;
T_1 V_4 [ V_2 ] ;
T_2 V_5 ;
memset ( V_4 , 0 , sizeof( V_4 ) ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
F_3 ( V_1 , & V_5 , V_4 , V_7 ) ;
}
static void F_4 ( void )
{
if ( V_8 )
printf ( L_1
L_2 ) ;
else
printf ( L_3
L_4 ) ;
}
static void F_5 ( int V_1 )
{
unsigned int V_2 = F_2 ( V_3 ) ;
T_1 V_9 = 0 ;
long V_4 [ V_2 ] ;
T_1 V_10 = 0 ;
T_1 V_11 [ V_6 ] ;
T_1 V_12 ;
T_2 V_5 ;
int V_13 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
F_6 ( V_1 , & V_5 , V_4 ) ;
V_12 = 0 ;
for ( V_13 = 0 ; V_13 < V_2 ; V_13 ++ )
V_12 += V_4 [ V_13 ] ;
V_11 [ V_5 ] = V_12 ;
V_9 += V_12 ;
if ( V_12 > V_10 )
V_10 = V_12 ;
}
F_1 ( V_1 ) ;
for ( V_5 = V_8 ? 0 : 29 ; V_5 < V_6 ; V_5 ++ ) {
int V_14 = V_15 * V_11 [ V_5 ] / ( V_10 + 1 ) ;
if ( V_16 )
printf ( L_5 , V_17 [ V_14 ] ) ;
else
printf ( L_6 , V_18 [ V_14 ] , V_19 ) ;
}
printf ( L_7 , V_9 ) ;
}
int main ( int V_20 , char * * V_21 )
{
char V_22 [ 256 ] ;
int V_13 ;
snprintf ( V_22 , sizeof( V_22 ) , L_8 , V_21 [ 0 ] ) ;
if ( F_7 ( V_22 ) ) {
printf ( L_5 , V_23 ) ;
return 1 ;
}
for ( V_13 = 1 ; V_13 < V_20 ; V_13 ++ ) {
if ( strcmp ( V_21 [ V_13 ] , L_9 ) == 0 ) {
V_8 = true ;
} else if ( strcmp ( V_21 [ V_13 ] , L_10 ) == 0 ) {
V_16 = true ;
} else if ( strcmp ( V_21 [ V_13 ] , L_11 ) == 0 ) {
printf ( L_12
L_13
L_14 ) ;
return 1 ;
}
}
printf ( L_15 ) ;
if ( V_16 )
printf ( L_16 , V_17 [ V_15 - 1 ] ) ;
else
printf ( L_17 , V_18 [ V_15 - 1 ] , V_19 ) ;
printf ( L_18 ) ;
if ( V_16 )
printf ( L_16 , V_17 [ 0 ] ) ;
else
printf ( L_17 , V_18 [ 0 ] , V_19 ) ;
printf ( L_19 ) ;
for ( V_13 = 0 ; ; V_13 ++ ) {
if ( V_13 % 20 == 0 )
F_4 () ;
F_5 ( V_24 [ 1 ] ) ;
F_8 ( 2 ) ;
}
return 0 ;
}
