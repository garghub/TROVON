static inline T_1 F_1 ( const void * V_1 )
{
return * ( T_1 * ) V_1 ;
}
static inline void F_2 ( T_1 V_2 , void * V_1 )
{
* ( T_1 * ) V_1 = V_2 ;
}
void F_3 ( const struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 )
{
unsigned long V_8 = F_4 ( V_7 ) ;
F_5 ( V_4 , (struct V_9 * ) V_8 ,
struct V_9 , V_10 , V_6 ) ;
}
