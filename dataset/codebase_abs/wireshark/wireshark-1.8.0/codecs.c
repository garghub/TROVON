T_1
F_1 ( const char * V_1 )
{
return ( V_2 ) ? F_2 ( V_2 , V_1 ) : NULL ;
}
void
F_3 ( const char * V_1 , T_2 V_3 , T_3 V_4 , T_4 V_5 )
{
struct V_6 * V_7 ;
if ( V_2 == NULL ) {
V_2 = F_4 ( V_8 , V_9 ) ;
F_5 ( V_2 != NULL ) ;
}
F_5 ( F_2 ( V_2 , V_1 ) == NULL ) ;
V_7 = F_6 ( sizeof ( struct V_6 ) ) ;
V_7 -> V_1 = V_1 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_5 = V_5 ;
F_7 ( V_2 , ( V_10 ) V_1 , ( V_10 ) V_7 ) ;
}
void * F_8 ( T_1 V_11 )
{
if ( ! V_11 ) return NULL ;
return ( V_11 -> V_3 ) ( ) ;
}
void F_9 ( T_1 V_11 , void * V_12 )
{
if ( ! V_11 ) return;
( V_11 -> V_4 ) ( V_12 ) ;
}
int F_10 ( T_1 V_11 , void * V_12 , const void * V_13 , int V_14 , void * V_15 , int * V_16 )
{
if ( ! V_11 ) return 0 ;
return ( V_11 -> V_5 ) ( V_12 , V_13 , V_14 , V_15 , V_16 ) ;
}
