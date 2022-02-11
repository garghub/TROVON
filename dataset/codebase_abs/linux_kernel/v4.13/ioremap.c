static inline bool F_1 ( T_1 V_1 )
{
if ( F_2 () ) {
if ( V_1 >= V_2 )
return true ;
} else if ( V_1 >= V_3 && V_1 <= V_4 ) {
return true ;
}
return false ;
}
void T_2 * F_3 ( T_1 V_1 , unsigned long V_5 )
{
T_1 V_6 ;
V_6 = V_1 + V_5 - 1 ;
if ( ! V_5 || ( V_6 < V_1 ) )
return NULL ;
if ( F_1 ( V_1 ) )
return ( void T_2 * ) ( V_7 ) V_1 ;
return F_4 ( V_1 , V_5 , V_8 ) ;
}
void T_2 * F_4 ( T_1 V_1 , unsigned long V_5 ,
unsigned long V_9 )
{
unsigned long V_10 ;
struct V_11 * V_12 ;
T_1 V_13 , V_6 ;
T_3 V_14 = F_5 ( V_9 ) ;
V_6 = V_1 + V_5 - 1 ;
if ( ( ! V_5 ) || ( V_6 < V_1 ) )
return NULL ;
if ( ! F_6 () )
return NULL ;
V_14 = F_7 ( V_14 ) ;
V_13 = V_1 & ~ V_15 ;
V_1 &= V_15 ;
V_5 = F_8 ( V_6 + 1 ) - V_1 ;
V_12 = F_9 ( V_5 , V_16 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_17 = V_1 ;
V_10 = ( unsigned long ) V_12 -> V_18 ;
if ( F_10 ( V_10 , V_10 + V_5 , V_1 , V_14 ) ) {
F_11 ( ( void V_19 * ) V_10 ) ;
return NULL ;
}
return ( void T_2 * ) ( V_13 + ( char T_2 * ) V_10 ) ;
}
void F_12 ( const void T_2 * V_18 )
{
if ( F_1 ( ( T_1 ) ( V_7 ) V_18 ) )
return;
F_13 ( ( void * ) ( V_15 & ( unsigned long V_19 ) V_18 ) ) ;
}
