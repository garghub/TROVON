void
F_1 ( T_1 * V_1 , T_1 * V_2 , const char * V_3 , const char * V_4 )
{
T_1 * V_5 ;
T_1 * V_6 ;
char * V_7 ;
F_2 ( F_3 ( V_1 ) , V_3 ) ;
F_4 ( F_5 ( V_1 ) , V_2 ) ;
F_6 ( F_5 ( V_2 ) , 10 ) ;
F_7 ( V_2 ) ;
V_5 = F_8 ( V_3 ) ;
F_9 ( F_10 ( V_2 ) , V_5 , FALSE , FALSE , 0 ) ;
F_7 ( V_5 ) ;
V_7 = F_11 ( L_1 , V_4 ? V_4 : L_2 ) ;
V_6 = F_8 ( V_7 ) ;
F_12 ( V_7 ) ;
F_13 ( F_14 ( V_6 ) , TRUE ) ;
F_9 ( F_10 ( V_2 ) , V_6 , FALSE , FALSE , 0 ) ;
F_7 ( V_6 ) ;
}
T_2 *
F_15 ( T_1 * V_8 , T_1 * V_9 , int V_10 , const T_3 * V_11 )
{
T_2 * V_12 ;
T_4 * V_13 ;
T_1 * V_14 ;
T_5 * V_15 ;
T_6 * V_16 ;
T_7 * V_17 ;
T_8 * V_18 ;
int V_19 ;
if ( V_10 <= 0 )
return NULL ;
V_18 = F_16 ( V_10 * sizeof( T_8 ) ) ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ )
V_18 [ V_19 ] = V_11 [ V_19 ] . type ;
V_13 = F_17 ( V_10 , V_18 ) ;
F_12 ( V_18 ) ;
V_14 = F_18 ( F_19 ( V_13 ) ) ;
V_12 = F_20 ( V_14 ) ;
F_21 ( F_22 ( V_13 ) ) ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ ) {
V_17 = F_23 () ;
if ( V_11 [ V_19 ] . V_20 == V_21 ) {
F_24 ( F_22 ( V_17 ) , L_3 , 1.0 , NULL ) ;
}
F_24 ( V_17 , L_4 , 0 , NULL ) ;
V_15 = F_25 ( V_11 [ V_19 ] . V_3 , V_17 , L_5 ,
V_19 , NULL ) ;
F_26 ( V_15 , TRUE ) ;
F_27 ( V_12 , V_15 ) ;
}
F_4 ( F_5 ( V_8 ) , F_28 ( V_12 ) ) ;
F_9 ( F_10 ( V_9 ) , V_8 , TRUE , TRUE , 0 ) ;
F_29 ( V_12 , FALSE ) ;
F_30 ( V_12 , FALSE ) ;
V_16 = F_31 ( F_20 ( V_12 ) ) ;
F_32 ( V_16 , V_22 ) ;
F_7 ( V_8 ) ;
return V_12 ;
}
