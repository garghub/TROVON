static void F_1 ( int V_1 )
{
unsigned int V_2 = F_2 () ;
T_1 V_3 [ V_2 ] ;
T_2 V_4 ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
F_3 ( V_1 , & V_4 , V_3 , V_6 ) ;
}
static void F_4 ( void )
{
if ( V_7 )
printf ( L_1
L_2 ) ;
else
printf ( L_3
L_4 ) ;
}
static void F_5 ( int V_1 )
{
unsigned int V_2 = F_2 () ;
T_1 V_8 = 0 ;
long V_3 [ V_2 ] ;
T_1 V_9 = 0 ;
T_1 V_10 [ V_5 ] ;
T_1 V_11 ;
T_2 V_4 ;
int V_12 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
F_6 ( V_1 , & V_4 , V_3 ) ;
V_11 = 0 ;
for ( V_12 = 0 ; V_12 < V_2 ; V_12 ++ )
V_11 += V_3 [ V_12 ] ;
V_10 [ V_4 ] = V_11 ;
V_8 += V_11 ;
if ( V_11 > V_9 )
V_9 = V_11 ;
}
F_1 ( V_1 ) ;
for ( V_4 = V_7 ? 0 : 29 ; V_4 < V_5 ; V_4 ++ ) {
int V_13 = V_14 * V_10 [ V_4 ] / ( V_9 + 1 ) ;
if ( V_15 )
printf ( L_5 , V_16 [ V_13 ] ) ;
else
printf ( L_6 , V_17 [ V_13 ] , V_18 ) ;
}
printf ( L_7 , V_8 ) ;
}
int main ( int V_19 , char * * V_20 )
{
struct V_21 V_22 = { 1024 * 1024 , V_23 } ;
char V_24 [ 256 ] ;
int V_12 ;
snprintf ( V_24 , sizeof( V_24 ) , L_8 , V_20 [ 0 ] ) ;
if ( F_7 ( V_25 , & V_22 ) ) {
perror ( L_9 ) ;
return 1 ;
}
if ( F_8 ( V_24 ) ) {
printf ( L_5 , V_26 ) ;
return 1 ;
}
for ( V_12 = 1 ; V_12 < V_19 ; V_12 ++ ) {
if ( strcmp ( V_20 [ V_12 ] , L_10 ) == 0 ) {
V_7 = true ;
} else if ( strcmp ( V_20 [ V_12 ] , L_11 ) == 0 ) {
V_15 = true ;
} else if ( strcmp ( V_20 [ V_12 ] , L_12 ) == 0 ) {
printf ( L_13
L_14
L_15 ) ;
return 1 ;
}
}
printf ( L_16 ) ;
if ( V_15 )
printf ( L_17 , V_16 [ V_14 - 1 ] ) ;
else
printf ( L_18 , V_17 [ V_14 - 1 ] , V_18 ) ;
printf ( L_19 ) ;
if ( V_15 )
printf ( L_17 , V_16 [ 0 ] ) ;
else
printf ( L_18 , V_17 [ 0 ] , V_18 ) ;
printf ( L_20 ) ;
for ( V_12 = 0 ; ; V_12 ++ ) {
if ( V_12 % 20 == 0 )
F_4 () ;
F_5 ( V_27 [ 1 ] ) ;
F_9 ( 2 ) ;
}
return 0 ;
}
