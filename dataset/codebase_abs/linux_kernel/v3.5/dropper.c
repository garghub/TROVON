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
if ( F_5 ( V_19 , 2 , & V_17 ) ) {
perror ( L_1 ) ;
return 1 ;
}
return 0 ;
}
int main ( int V_20 , char * * V_21 )
{
if ( V_20 < 5 ) {
fprintf ( V_22 , L_2
L_3
L_4
L_5
L_6 , V_23 , V_24 ) ;
return 1 ;
}
if ( F_1 ( strtol ( V_21 [ 1 ] , NULL , 0 ) , strtol ( V_21 [ 2 ] , NULL , 0 ) ,
strtol ( V_21 [ 3 ] , NULL , 0 ) ) )
return 1 ;
F_6 ( V_21 [ 4 ] , & V_21 [ 4 ] ) ;
printf ( L_7 ) ;
return 255 ;
}
