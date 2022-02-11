int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long * V_8 ;
int V_9 = V_4 >> V_10 ;
int V_11 = F_2 ( V_9 ) * sizeof( long ) ;
V_7 = F_3 ( sizeof( * V_7 ) , V_12 ) ;
if ( ! V_7 ) {
V_5 = - V_13 ;
goto V_14;
}
V_8 = F_3 ( V_11 , V_12 ) ;
if ( ! V_8 ) {
V_5 = - V_13 ;
goto V_15;
}
V_7 -> V_8 = V_8 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_4 = V_4 ;
V_2 -> V_7 = V_7 ;
return 0 ;
V_15:
F_4 ( V_7 ) ;
V_14:
return V_5 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_2 -> V_7 = NULL ;
F_4 ( V_7 -> V_8 ) ;
F_4 ( V_7 ) ;
}
void T_3 * F_6 ( struct V_1 * V_2 ,
T_1 * V_16 , T_2 V_4 )
{
int V_17 ;
void T_3 * V_18 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_19 = F_7 ( V_4 ) ;
V_17 = F_8 ( V_7 -> V_8 , V_7 -> V_9 , V_19 ) ;
if ( V_17 < 0 )
return NULL ;
* V_16 = V_7 -> V_3 + ( V_17 << V_10 ) ;
V_18 = F_9 ( * V_16 , V_4 ) ;
if ( ! V_18 )
F_10 ( V_7 -> V_8 , V_17 , V_19 ) ;
return V_18 ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_16 ,
void T_3 * V_18 , T_2 V_4 )
{
int V_17 ;
int V_19 = F_7 ( V_4 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_12 ( V_18 ) ;
V_17 = ( V_16 - V_7 -> V_3 ) >> V_10 ;
F_10 ( V_7 -> V_8 , V_17 , V_19 ) ;
}
