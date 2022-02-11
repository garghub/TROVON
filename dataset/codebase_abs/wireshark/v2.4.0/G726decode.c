static inline void *
F_1 ( int V_1 , int V_2 )
{
T_1 * V_3 = F_2 ( NULL , V_1 , V_4 , V_2 ) ;
if ( ! V_3 ) {
return NULL ;
}
T_2 * V_5 = F_3 ( T_2 , 1 ) ;
V_5 -> V_5 = V_3 ;
V_5 -> V_1 = V_1 ;
return V_5 ;
}
void * F_4 ( void ) { return F_1 ( 16000 , V_6 ) ; }
void * F_5 ( void ) { return F_1 ( 24000 , V_6 ) ; }
void * F_6 ( void ) { return F_1 ( 32000 , V_6 ) ; }
void * F_7 ( void ) { return F_1 ( 40000 , V_6 ) ; }
void * F_8 ( void ) { return F_1 ( 16000 , V_7 ) ; }
void * F_9 ( void ) { return F_1 ( 24000 , V_7 ) ; }
void * F_10 ( void ) { return F_1 ( 32000 , V_7 ) ; }
void * F_11 ( void ) { return F_1 ( 40000 , V_7 ) ; }
void
F_12 ( void * V_8 )
{
T_2 * V_5 = ( T_2 * ) V_8 ;
if ( ! V_5 ) {
return;
}
F_13 ( V_5 -> V_5 ) ;
F_14 ( V_5 ) ;
}
unsigned
F_15 ( void * V_8 V_9 )
{
return 1 ;
}
unsigned
F_16 ( void * V_8 V_9 )
{
return 8000 ;
}
T_3
F_17 ( void * V_8 , const void * V_10 , T_3 V_11 , void * V_12 ,
T_3 * V_13 )
{
T_2 * V_5 = ( T_2 * ) V_8 ;
if ( ! V_5 ) {
return 0 ;
}
if ( ! V_12 || ! V_13 ) {
return V_11 * 8 / ( V_5 -> V_1 / 8000 ) * 2 ;
}
* V_13 = 2 * F_18 ( V_5 -> V_5 , ( V_14 * ) V_12 , ( const V_15 * ) V_10 , ( int ) V_11 ) ;
return * V_13 ;
}
