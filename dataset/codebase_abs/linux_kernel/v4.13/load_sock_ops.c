static void F_1 ( char * V_1 )
{
printf ( L_1 , V_1 ) ;
printf ( L_2
L_3 ) ;
printf ( L_4 ) ;
printf ( L_5 ) ;
printf ( L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 , V_1 ) ;
printf ( L_10 ) ;
printf ( L_11 ) ;
printf ( L_8 ) ;
exit ( 1 ) ;
}
int main ( int V_2 , char * * V_3 )
{
int V_4 = 0 ;
int error = 0 ;
char * V_5 ;
char V_6 [ 500 ] ;
char * V_7 ;
int V_8 ;
if ( V_2 < 3 )
F_1 ( V_3 [ 0 ] ) ;
if ( ! strcmp ( V_3 [ 1 ] , L_12 ) ) {
V_5 = V_3 [ 2 ] ;
V_8 = F_2 ( V_5 , V_9 , V_10 ) ;
error = F_3 ( V_8 , V_11 ) ;
if ( error ) {
printf ( L_13 ,
error , strerror ( V_12 ) ) ;
return 2 ;
}
return 0 ;
} else if ( ! strcmp ( V_3 [ 1 ] , L_14 ) ) {
F_1 ( V_3 [ 0 ] ) ;
} else if ( ! strcmp ( V_3 [ 1 ] , L_15 ) ) {
V_4 = 1 ;
if ( V_2 < 4 )
F_1 ( V_3 [ 0 ] ) ;
}
V_7 = V_3 [ V_2 - 1 ] ;
V_5 = V_3 [ V_2 - 2 ] ;
if ( strlen ( V_7 ) > 480 ) {
fprintf ( V_13 , L_16 ) ;
return 3 ;
}
V_8 = F_2 ( V_5 , V_9 , V_10 ) ;
if ( ! strcmp ( V_7 + strlen ( V_7 ) - 2 , L_17 ) )
strcpy ( V_6 , V_7 ) ;
else
sprintf ( V_6 , L_18 , V_7 ) ;
if ( V_4 )
printf ( L_19 , V_6 ) ;
if ( F_4 ( V_6 ) ) {
printf ( L_20 , V_6 ) ;
printf ( L_21 , V_14 ) ;
return 4 ;
}
if ( V_4 )
printf ( L_22 , V_6 ) ;
error = F_5 ( V_15 [ 0 ] , V_8 , V_11 , 0 ) ;
if ( error ) {
printf ( L_23 ,
error , strerror ( V_12 ) ) ;
return 5 ;
} else if ( V_4 ) {
F_6 () ;
}
return error ;
}
