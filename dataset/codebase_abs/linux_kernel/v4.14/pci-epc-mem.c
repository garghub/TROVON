static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
unsigned int V_5 = F_2 ( V_2 -> V_6 ) ;
V_3 -- ;
V_3 >>= V_5 ;
#if V_7 == 32
V_4 = F_3 ( V_3 ) ;
#else
V_4 = F_4 ( V_3 ) ;
#endif
return V_4 ;
}
int F_5 ( struct V_8 * V_9 , T_2 V_10 , T_1 V_3 ,
T_1 V_6 )
{
int V_11 ;
struct V_1 * V_2 ;
unsigned long * V_12 ;
unsigned int V_5 ;
int V_13 ;
int V_14 ;
if ( V_6 < V_15 )
V_6 = V_15 ;
V_5 = F_2 ( V_6 ) ;
V_13 = V_3 >> V_5 ;
V_14 = F_6 ( V_13 ) * sizeof( long ) ;
V_2 = F_7 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 ) {
V_11 = - V_17 ;
goto V_18;
}
V_12 = F_7 ( V_14 , V_16 ) ;
if ( ! V_12 ) {
V_11 = - V_17 ;
goto V_19;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_3 = V_3 ;
V_9 -> V_2 = V_2 ;
return 0 ;
V_19:
F_8 ( V_2 ) ;
V_18:
return V_11 ;
}
void F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
V_9 -> V_2 = NULL ;
F_8 ( V_2 -> V_12 ) ;
F_8 ( V_2 ) ;
}
void T_3 * F_10 ( struct V_8 * V_9 ,
T_2 * V_20 , T_1 V_3 )
{
int V_21 ;
void T_3 * V_22 ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_5 = F_2 ( V_2 -> V_6 ) ;
int V_4 ;
V_3 = F_11 ( V_3 , V_2 -> V_6 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
V_21 = F_12 ( V_2 -> V_12 , V_2 -> V_13 , V_4 ) ;
if ( V_21 < 0 )
return NULL ;
* V_20 = V_2 -> V_10 + ( V_21 << V_5 ) ;
V_22 = F_13 ( * V_20 , V_3 ) ;
if ( ! V_22 )
F_14 ( V_2 -> V_12 , V_21 , V_4 ) ;
return V_22 ;
}
void F_15 ( struct V_8 * V_9 , T_2 V_20 ,
void T_3 * V_22 , T_1 V_3 )
{
int V_21 ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_5 = F_2 ( V_2 -> V_6 ) ;
int V_4 ;
F_16 ( V_22 ) ;
V_21 = ( V_20 - V_2 -> V_10 ) >> V_5 ;
V_3 = F_11 ( V_3 , V_2 -> V_6 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
F_14 ( V_2 -> V_12 , V_21 , V_4 ) ;
}
