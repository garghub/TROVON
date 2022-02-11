int main ( int V_1 , char * * V_2 )
{
struct V_3 V_4 ;
static const char V_5 [] = L_1 ;
static const char V_6 [] = L_2 ;
char V_7 [ 256 ] ;
struct V_8 V_9 [] = {
V_10 ,
F_1 ( V_11 , V_12 ) ,
F_1 ( V_13 , V_12 ) ,
F_1 ( V_14 , F_2 ( & V_4 , V_15 ) ) ,
F_1 ( V_16 , F_2 ( & V_4 , V_17 ) ) ,
V_18 ,
F_3 ( & V_4 , V_17 ) ,
F_4 ( 0 ) ,
F_5 ( V_19 , V_18 ) ,
F_4 ( 1 ) ,
F_5 ( ( unsigned long ) V_7 , V_18 ) ,
F_4 ( 2 ) ,
F_6 ( sizeof( V_7 ) , V_18 ) ,
V_12 ,
F_3 ( & V_4 , V_15 ) ,
F_4 ( 0 ) ,
F_7 ( V_20 , F_2 ( & V_4 , V_21 ) ) ,
F_7 ( V_22 , F_2 ( & V_4 , V_21 ) ) ,
V_18 ,
F_3 ( & V_4 , V_21 ) ,
F_4 ( 1 ) ,
F_7 ( ( unsigned long ) V_5 , F_2 ( & V_4 , V_23 ) ) ,
F_7 ( ( unsigned long ) V_6 , F_2 ( & V_4 , V_24 ) ) ,
F_7 ( ( unsigned long ) V_7 , F_2 ( & V_4 , V_25 ) ) ,
V_18 ,
F_3 ( & V_4 , V_23 ) ,
F_4 ( 2 ) ,
F_8 ( sizeof( V_5 ) , V_12 ) ,
V_18 ,
F_3 ( & V_4 , V_24 ) ,
F_4 ( 2 ) ,
F_8 ( sizeof( V_6 ) , V_12 ) ,
V_18 ,
F_3 ( & V_4 , V_25 ) ,
F_4 ( 2 ) ,
F_8 ( sizeof( V_7 ) , V_12 ) ,
V_18 ,
} ;
struct V_26 V_27 = {
. V_9 = V_9 ,
. V_28 = ( unsigned short ) ( sizeof( V_9 ) / sizeof( V_9 [ 0 ] ) ) ,
} ;
T_1 V_29 ;
F_9 ( & V_4 , V_9 , sizeof( V_9 ) / sizeof( * V_9 ) ) ;
if ( F_10 ( V_30 , 1 , 0 , 0 , 0 ) ) {
perror ( L_3 ) ;
return 1 ;
}
if ( F_10 ( V_31 , V_32 , & V_27 ) ) {
perror ( L_4 ) ;
return 1 ;
}
F_11 ( V_14 , V_20 , V_5 , strlen ( V_5 ) ) ;
V_29 = F_11 ( V_16 , V_19 , V_7 , sizeof( V_7 ) - 1 ) ;
V_29 = ( V_29 > 0 ? V_29 : 0 ) ;
F_11 ( V_14 , V_22 , V_6 , strlen ( V_6 ) ) ;
F_11 ( V_14 , V_22 , V_7 , V_29 ) ;
F_11 ( V_14 , V_22 , V_6 , strlen ( V_6 ) + 2 ) ;
return 0 ;
}
