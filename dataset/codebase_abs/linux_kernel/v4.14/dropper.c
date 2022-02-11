static int F_1 ( int V_1 , int V_2 , int error )
{
struct V_3 V_4 [] = {
F_2 ( V_5 + V_6 + V_7 ,
( F_3 ( struct V_8 , V_2 ) ) ) ,
F_4 ( V_9 + V_10 + V_11 , V_2 , 0 , 3 ) ,
F_2 ( V_5 + V_6 + V_7 ,
( F_3 ( struct V_8 , V_1 ) ) ) ,
F_4 ( V_9 + V_10 + V_11 , V_1 , 0 , 1 ) ,
F_2 ( V_12 + V_11 ,
V_13 | ( error & V_14 ) ) ,
F_2 ( V_12 + V_11 , V_15 ) ,
} ;
struct V_16 V_17 = {
. V_18 = ( unsigned short ) ( sizeof( V_4 ) / sizeof( V_4 [ 0 ] ) ) ,
. V_4 = V_4 ,
} ;
if ( F_5 ( V_19 , 1 , 0 , 0 , 0 ) ) {
perror ( L_1 ) ;
return 1 ;
}
if ( F_5 ( V_20 , 2 , & V_17 ) ) {
perror ( L_2 ) ;
return 1 ;
}
return 0 ;
}
int main ( int V_21 , char * * V_22 )
{
if ( V_21 < 5 ) {
fprintf ( V_23 , L_3
L_4
L_5
L_6
L_7 , V_24 , V_25 ) ;
return 1 ;
}
if ( F_1 ( strtol ( V_22 [ 1 ] , NULL , 0 ) , strtol ( V_22 [ 2 ] , NULL , 0 ) ,
strtol ( V_22 [ 3 ] , NULL , 0 ) ) )
return 1 ;
F_6 ( V_22 [ 4 ] , & V_22 [ 4 ] ) ;
printf ( L_8 ) ;
return 255 ;
}
