int main ( int V_1 , char * * V_2 )
{
struct V_3 V_4 = {
. V_5 = 0 ,
} ;
static const char V_6 [] = L_1 ;
static const char V_7 [] = L_2 ;
char V_8 [ 256 ] ;
struct V_9 V_10 [] = {
V_11 ,
F_1 ( V_12 , V_13 ) ,
F_1 ( V_14 , V_13 ) ,
F_1 ( V_15 , F_2 ( & V_4 , V_16 ) ) ,
F_1 ( V_17 , F_2 ( & V_4 , V_18 ) ) ,
V_19 ,
F_3 ( & V_4 , V_18 ) ,
F_4 ( 0 ) ,
F_5 ( V_20 , V_19 ) ,
F_4 ( 1 ) ,
F_5 ( ( unsigned long ) V_8 , V_19 ) ,
F_4 ( 2 ) ,
F_6 ( sizeof( V_8 ) , V_19 ) ,
V_13 ,
F_3 ( & V_4 , V_16 ) ,
F_4 ( 0 ) ,
F_7 ( V_21 , F_2 ( & V_4 , V_22 ) ) ,
F_7 ( V_23 , F_2 ( & V_4 , V_22 ) ) ,
V_19 ,
F_3 ( & V_4 , V_22 ) ,
F_4 ( 1 ) ,
F_7 ( ( unsigned long ) V_6 , F_2 ( & V_4 , V_24 ) ) ,
F_7 ( ( unsigned long ) V_7 , F_2 ( & V_4 , V_25 ) ) ,
F_7 ( ( unsigned long ) V_8 , F_2 ( & V_4 , V_26 ) ) ,
V_19 ,
F_3 ( & V_4 , V_24 ) ,
F_4 ( 2 ) ,
F_8 ( sizeof( V_6 ) , V_13 ) ,
V_19 ,
F_3 ( & V_4 , V_25 ) ,
F_4 ( 2 ) ,
F_8 ( sizeof( V_7 ) , V_13 ) ,
V_19 ,
F_3 ( & V_4 , V_26 ) ,
F_4 ( 2 ) ,
F_8 ( sizeof( V_8 ) , V_13 ) ,
V_19 ,
} ;
struct V_27 V_28 = {
. V_10 = V_10 ,
. V_29 = ( unsigned short ) ( sizeof( V_10 ) / sizeof( V_10 [ 0 ] ) ) ,
} ;
T_1 V_30 ;
F_9 ( & V_4 , V_10 , sizeof( V_10 ) / sizeof( * V_10 ) ) ;
if ( F_10 ( V_31 , 1 , 0 , 0 , 0 ) ) {
perror ( L_3 ) ;
return 1 ;
}
if ( F_10 ( V_32 , V_33 , & V_28 ) ) {
perror ( L_4 ) ;
return 1 ;
}
F_11 ( V_15 , V_21 , V_6 , strlen ( V_6 ) ) ;
V_30 = F_11 ( V_17 , V_20 , V_8 , sizeof( V_8 ) - 1 ) ;
V_30 = ( V_30 > 0 ? V_30 : 0 ) ;
F_11 ( V_15 , V_23 , V_7 , strlen ( V_7 ) ) ;
F_11 ( V_15 , V_23 , V_8 , V_30 ) ;
F_11 ( V_15 , V_23 , V_7 , strlen ( V_7 ) + 2 ) ;
return 0 ;
}
