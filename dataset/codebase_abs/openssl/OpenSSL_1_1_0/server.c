int F_1 ( int * V_1 , char * * * V_2 ) {
const T_1 * V_3 = V_4 ;
T_2 * V_5 ;
T_3 * V_6 ;
int V_7 ;
T_4 * V_8 ;
V_9 = F_2 ( F_3 () ) ;
V_5 = F_4 ( NULL , & V_3 , sizeof( V_4 ) ) ;
F_5 ( V_5 != NULL ) ;
V_6 = F_6 () ;
F_7 ( V_6 , V_5 ) ;
V_7 = F_8 ( V_9 , V_6 ) ;
F_5 ( V_7 == 1 ) ;
F_9 ( V_6 ) ;
V_3 = V_10 ;
V_8 = F_10 ( NULL , & V_3 , sizeof( V_10 ) ) ;
F_5 ( V_8 != NULL ) ;
V_7 = F_11 ( V_9 , V_8 ) ;
F_5 ( V_7 == 1 ) ;
F_12 ( V_8 ) ;
return 1 ;
}
int F_13 ( const T_1 * V_11 , T_5 V_12 ) {
T_6 * V_13 = F_14 ( V_9 ) ;
T_7 * V_14 = F_15 ( F_16 () ) ;
T_7 * V_15 = F_15 ( F_16 () ) ;
F_17 ( V_13 , V_14 , V_15 ) ;
F_18 ( V_13 ) ;
F_5 ( ( T_5 ) F_19 ( V_14 , V_11 , V_12 ) == V_12 ) ;
if ( F_20 ( V_13 ) == 1 ) {
T_1 V_16 [ 1024 ] ;
for (; ; ) {
if ( F_21 ( V_13 , V_16 , sizeof( V_16 ) ) <= 0 ) {
break;
}
}
}
F_22 ( V_13 ) ;
return 0 ;
}
