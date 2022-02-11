const T_1 * F_1 ( void ) { return V_1 ; }
void F_2 ( const T_1 * V_2 ) { V_1 = V_2 ; }
void F_3 ( const char * V_3 ,
T_2 V_4 ,
void (* F_4)( T_3 ) ,
T_3 V_5 ,
T_4 V_6 ) {
T_5 * V_7 = ( T_5 * ) F_5 ( sizeof( T_5 ) ) ;
V_7 -> V_3 = F_6 ( V_3 ) ;
V_7 -> V_4 = V_4 ;
V_7 -> F_4 = F_4 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_6 = V_6 ;
V_7 -> V_8 = NULL ;
if ( ! V_9 ) {
V_9 = V_7 ;
} else {
T_5 * V_10 ;
for ( V_10 = V_9 ; V_10 -> V_8 ; V_10 = V_10 -> V_8 ) ;
V_10 -> V_8 = V_7 ;
}
}
void F_7 ( T_6 V_11 ) {
T_5 * V_10 ;
for ( V_10 = V_9 ; V_10 ; V_10 = V_10 -> V_8 ) {
V_11 ( V_10 -> V_3 , V_10 -> V_4 , V_10 -> F_4 , V_10 -> V_5 , V_10 -> V_6 ) ;
}
}
