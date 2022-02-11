T_1 F_1 ( void * V_1 , T_2 V_2 )
{
T_1 V_3 = { V_4 , V_5 , V_1 } ;
T_3 * V_6 = ( T_3 * ) V_1 ;
if ( ! V_1 || V_2 < sizeof( T_3 ) || V_1 != F_2 ( V_1 ) ) {
T_1 error = { NULL , NULL , NULL } ;
return error ;
}
V_6 -> V_7 = V_1 ;
V_6 -> V_8 = ( char * ) V_1 + V_2 ;
F_3 ( V_6 , sizeof( T_3 ) ) ;
return V_3 ;
}
void * F_4 ( void * V_9 , T_2 * V_10 )
{
T_3 * V_6 = ( T_3 * ) V_9 ;
* V_10 = ( V_11 const * ) V_6 -> V_8 - ( V_11 * ) F_2 ( V_6 -> V_7 ) ;
return F_3 ( V_6 , * V_10 ) ;
}
void * V_4 ( void * V_9 , T_2 V_10 )
{
T_3 * V_6 = ( T_3 * ) V_9 ;
return F_3 ( V_6 , V_10 ) ;
}
void V_5 ( void * V_9 , void * V_12 )
{
( void ) V_9 ;
( void ) V_12 ;
}
void * F_5 ( T_2 V_10 , T_1 V_13 ) { return V_13 . V_14 ( V_13 . V_9 , V_10 ) ; }
void F_6 ( void * V_7 , T_1 V_13 )
{
if ( V_7 != NULL )
V_13 . V_15 ( V_13 . V_9 , V_7 ) ;
}
