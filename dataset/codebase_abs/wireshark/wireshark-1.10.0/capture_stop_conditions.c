void F_1 ( void ) {
F_2 ( V_1 ,
V_2 ,
V_3 ,
V_4 ,
V_5 ) ;
F_2 ( V_6 ,
V_7 ,
V_8 ,
V_9 ,
V_10 ) ;
}
void F_3 ( void ) {
F_4 ( V_1 ) ;
F_4 ( V_6 ) ;
}
static T_1 * V_2 ( T_1 * V_11 , T_2 V_12 ) {
T_3 * V_13 = NULL ;
if( ( V_13 = ( T_3 * ) F_5 ( sizeof( T_3 ) ) ) == NULL )
return NULL ;
V_13 -> V_14 = time ( NULL ) ;
V_13 -> V_15 = va_arg ( V_12 , V_16 ) ;
F_6 ( V_11 , ( void * ) V_13 ) ;
return V_11 ;
}
static void V_3 ( T_1 * V_11 ) {
F_7 ( F_8 ( V_11 ) ) ;
}
static T_4 V_4 ( T_1 * V_11 , T_2 V_12 V_17 ) {
T_3 * V_13 = ( T_3 * ) F_8 ( V_11 ) ;
V_16 V_18 ;
if( V_13 -> V_15 == 0 ) return FALSE ;
V_18 = ( V_16 ) ( time ( NULL ) - V_13 -> V_14 ) ;
if( V_18 >= V_13 -> V_15 ) return TRUE ;
return FALSE ;
}
static void V_5 ( T_1 * V_11 ) {
( ( T_3 * ) F_8 ( V_11 ) ) -> V_14 = time ( NULL ) ;
}
static T_1 * V_7 ( T_1 * V_11 , T_2 V_12 ) {
T_5 * V_13 = NULL ;
if( ( V_13 = ( T_5 * ) F_5 ( sizeof( T_5 ) ) ) == NULL )
return NULL ;
V_13 -> V_19 = va_arg ( V_12 , long ) ;
F_6 ( V_11 , ( void * ) V_13 ) ;
return V_11 ;
}
static void V_8 ( T_1 * V_11 ) {
F_7 ( F_8 ( V_11 ) ) ;
}
static T_4 V_9 ( T_1 * V_11 , T_2 V_12 ) {
T_5 * V_13 = ( T_5 * ) F_8 ( V_11 ) ;
if( V_13 -> V_19 == 0 ) return FALSE ;
if( va_arg ( V_12 , long ) >= V_13 -> V_19 ) {
return TRUE ;
}
return FALSE ;
}
static void V_10 ( T_1 * V_11 V_17 ) {
}
