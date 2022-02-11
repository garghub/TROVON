int F_1 ( int * V_1 , char * * * V_2 ) {
return 1 ;
}
int F_2 ( const T_1 * V_3 , T_2 V_4 ) {
int V_5 ;
T_3 * V_6 = F_3 () ;
F_4 ( V_6 , V_7 |
V_8 | V_9 |
V_10 | V_11 ) ;
F_5 ( V_6 , V_12 |
V_13 | V_14 ) ;
for ( V_5 = 0 ; V_15 [ V_5 ] != NULL ; ++ V_5 ) {
const T_1 * V_16 = V_3 ;
unsigned char * V_17 = NULL ;
const T_4 * V_18 = F_6 ( V_15 [ V_5 ] ) ;
T_5 * V_19 = F_7 ( NULL , & V_16 , V_4 , V_18 ) ;
if ( V_19 != NULL ) {
T_6 * V_20 = F_8 ( F_9 () ) ;
F_10 ( V_20 , V_19 , 4 , V_18 , V_6 ) ;
F_11 ( V_20 ) ;
F_12 ( V_19 , & V_17 , V_18 ) ;
F_13 ( V_17 ) ;
F_14 ( V_19 , V_18 ) ;
}
}
F_15 ( V_6 ) ;
return 0 ;
}
