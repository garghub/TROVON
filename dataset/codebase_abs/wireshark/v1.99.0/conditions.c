T_1 * F_1 ( const char * V_1 , ... ) {
T_2 V_2 ;
T_1 * V_3 = NULL ;
T_1 * V_4 = NULL ;
T_3 * V_5 = NULL ;
char * V_6 = NULL ;
F_2 () ;
if ( ( V_5 = ( T_3 * ) F_3 ( V_7 , V_1 ) ) == NULL ) {
F_4 ( L_1 , V_1 ) ;
return NULL ;
}
if ( ( V_4 = ( T_1 * ) F_5 ( sizeof( T_1 ) ) ) == NULL )
return NULL ;
V_4 -> V_8 = NULL ;
V_4 -> V_9 = V_5 -> V_9 ;
V_4 -> V_10 = V_5 -> V_10 ;
V_4 -> V_1 = F_6 ( V_1 ) ;
va_start ( V_2 , V_1 ) ;
V_3 = ( V_5 -> V_11 ) ( V_4 , V_2 ) ;
va_end ( V_2 ) ;
if ( V_3 == NULL ) {
F_7 ( V_4 ) ;
F_7 ( V_6 ) ;
}
return V_3 ;
}
void F_8 ( T_1 * V_3 ) {
T_3 * V_5 = NULL ;
const char * V_1 ;
if ( V_3 == NULL )
return;
V_1 = V_3 -> V_1 ;
F_2 () ;
V_5 = ( T_3 * ) F_3 ( V_7 , V_1 ) ;
if ( V_5 != NULL )
( V_5 -> V_12 ) ( V_3 ) ;
F_7 ( V_3 -> V_1 ) ;
F_7 ( V_3 ) ;
}
T_4 F_9 ( T_1 * V_3 , ... ) {
T_2 V_2 ;
T_4 V_13 = FALSE ;
if ( V_3 == NULL )
return FALSE ;
va_start ( V_2 , V_3 ) ;
V_13 = ( V_3 -> V_9 ) ( V_3 , V_2 ) ;
va_end ( V_2 ) ;
return V_13 ;
}
void F_10 ( T_1 * V_3 ) {
if ( V_3 != NULL )
( V_3 -> V_10 ) ( V_3 ) ;
}
void * F_11 ( T_1 * V_3 ) {
return V_3 -> V_8 ;
}
void F_12 ( T_1 * V_3 , void * V_8 ) {
V_3 -> V_8 = V_8 ;
}
T_4 F_13 ( const char * V_1 ,
T_5 V_11 ,
T_6 V_12 ,
T_7 V_9 ,
T_8 V_10 ) {
char * V_14 = NULL ;
T_3 * V_5 = NULL ;
if ( ( V_11 == NULL ) || ( V_12 == NULL ) ||
( V_9 == NULL ) || ( V_10 == NULL ) || ( V_1 == NULL ) )
return FALSE ;
F_2 () ;
if ( F_3 ( V_7 , V_1 ) != NULL ) {
F_4 ( L_2 , V_1 ) ;
return FALSE ;
}
V_14 = F_6 ( V_1 ) ;
if ( ( V_5 = ( T_3 * ) F_5 ( sizeof( T_3 ) ) ) == NULL ) {
F_7 ( V_14 ) ;
return FALSE ;
}
V_5 -> V_11 = V_11 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_10 = V_10 ;
F_14 ( V_7 , V_14 , V_5 ) ;
return TRUE ;
}
void F_15 ( const char * V_1 ) {
const char * V_14 = ( const char * ) V_1 ;
T_3 * V_5 = NULL ;
F_2 () ;
F_16 ( V_7 ,
V_15 ,
( V_16 ) V_14 ) ;
V_5 = ( T_3 * ) F_3 ( V_7 , V_1 ) ;
F_17 ( V_7 , V_1 ) ;
F_7 ( V_17 ) ;
V_17 = NULL ;
F_7 ( V_5 ) ;
}
static void F_2 ( void ) {
if ( V_7 != NULL )
return;
V_7 = F_18 ( V_18 , V_19 ) ;
}
void V_15 ( V_16 V_14 ,
V_16 T_9 V_20 ,
V_16 V_8 ) {
char * V_1 = ( char * ) V_8 ;
char * V_21 = ( char * ) V_14 ;
if ( strcmp ( V_1 , V_21 ) == 0 )
V_17 = V_21 ;
}
