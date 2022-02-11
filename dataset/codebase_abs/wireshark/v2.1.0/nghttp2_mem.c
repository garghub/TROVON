static void * F_1 ( T_1 V_1 , void * T_2 V_2 ) {
return malloc ( V_1 ) ;
}
static void F_2 ( void * V_3 , void * T_2 V_2 ) { free ( V_3 ) ; }
static void * F_3 ( T_1 V_4 , T_1 V_1 ,
void * T_2 V_2 ) {
return calloc ( V_4 , V_1 ) ;
}
static void * F_4 ( void * V_3 , T_1 V_1 , void * T_2 V_2 ) {
return realloc ( V_3 , V_1 ) ;
}
T_3 * F_5 ( void ) { return & V_5 ; }
void * F_6 ( T_3 * V_6 , T_1 V_1 ) {
return V_6 -> malloc ( V_1 , V_6 -> T_2 ) ;
}
void F_7 ( T_3 * V_6 , void * V_3 ) {
V_6 -> free ( V_3 , V_6 -> T_2 ) ;
}
void F_8 ( T_4 V_7 , void * V_3 , void * T_2 ) {
V_7 ( V_3 , T_2 ) ;
}
void * F_9 ( T_3 * V_6 , T_1 V_4 , T_1 V_1 ) {
return V_6 -> calloc ( V_4 , V_1 , V_6 -> T_2 ) ;
}
void * F_10 ( T_3 * V_6 , void * V_3 , T_1 V_1 ) {
return V_6 -> realloc ( V_3 , V_1 , V_6 -> T_2 ) ;
}
