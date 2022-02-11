static void F_1 ( int V_1 )
{
T_1 V_2 ;
T_2 V_3 = 0 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ )
F_2 ( V_1 , & V_2 , & V_3 , V_5 ) ;
}
static void F_3 ( void )
{
if ( V_6 )
printf ( L_1
L_2 ) ;
else
printf ( L_3
L_4 ) ;
}
static void F_4 ( int V_1 )
{
T_1 V_2 ;
T_2 V_3 ;
T_2 V_7 [ V_4 ] ;
T_2 V_8 = 0 ;
T_2 V_9 = 0 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
V_3 = 0 ;
F_5 ( V_1 , & V_2 , & V_3 ) ;
V_7 [ V_2 ] = V_3 ;
V_9 += V_3 ;
if ( V_3 > V_8 )
V_8 = V_3 ;
}
F_1 ( V_1 ) ;
for ( V_2 = V_6 ? 0 : 29 ; V_2 < V_4 ; V_2 ++ ) {
int V_10 = V_11 * V_7 [ V_2 ] / ( V_8 + 1 ) ;
if ( V_12 )
printf ( L_5 , V_13 [ V_10 ] ) ;
else
printf ( L_6 , V_14 [ V_10 ] , V_15 ) ;
}
printf ( L_7 , V_9 ) ;
}
int main ( int V_16 , char * * V_17 )
{
char V_18 [ 256 ] ;
int V_19 ;
snprintf ( V_18 , sizeof( V_18 ) , L_8 , V_17 [ 0 ] ) ;
if ( F_6 ( V_18 ) ) {
printf ( L_5 , V_20 ) ;
return 1 ;
}
for ( V_19 = 1 ; V_19 < V_16 ; V_19 ++ ) {
if ( strcmp ( V_17 [ V_19 ] , L_9 ) == 0 ) {
V_6 = true ;
} else if ( strcmp ( V_17 [ V_19 ] , L_10 ) == 0 ) {
V_12 = true ;
} else if ( strcmp ( V_17 [ V_19 ] , L_11 ) == 0 ) {
printf ( L_12
L_13
L_14 ) ;
return 1 ;
}
}
printf ( L_15 ) ;
if ( V_12 )
printf ( L_16 , V_13 [ V_11 - 1 ] ) ;
else
printf ( L_17 , V_14 [ V_11 - 1 ] , V_15 ) ;
printf ( L_18 ) ;
if ( V_12 )
printf ( L_16 , V_13 [ 0 ] ) ;
else
printf ( L_17 , V_14 [ 0 ] , V_15 ) ;
printf ( L_19 ) ;
for ( V_19 = 0 ; ; V_19 ++ ) {
if ( V_19 % 20 == 0 )
F_3 () ;
F_4 ( V_21 [ 1 ] ) ;
F_7 ( 2 ) ;
}
return 0 ;
}
