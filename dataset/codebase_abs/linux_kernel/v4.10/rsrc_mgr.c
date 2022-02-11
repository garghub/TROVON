int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 1 ;
return 0 ;
}
struct V_4 * F_2 ( T_1 V_5 ,
T_1 V_6 ,
unsigned long V_7 , const char * V_8 )
{
struct V_4 * V_9 = F_3 ( sizeof( * V_9 ) , V_10 ) ;
if ( V_9 ) {
V_9 -> V_8 = V_8 ;
V_9 -> V_5 = V_5 ;
V_9 -> V_6 = V_5 + V_6 - 1 ;
V_9 -> V_7 = V_7 ;
}
return V_9 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_11 ,
unsigned int * V_12 , unsigned int V_13 ,
unsigned int V_14 , struct V_4 * * V_15 )
{
if ( ! V_2 -> V_16 )
return - V_17 ;
* V_12 = V_2 -> V_16 | ( * V_12 & 0x0fff ) ;
* V_15 = NULL ;
return 0 ;
}
