int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * * V_5 )
{
return F_2 ( V_4 , V_5 ) ;
}
static int F_3 ( struct V_3 * V_4 )
{
int V_6 , V_7 = 0 ;
struct V_8 * V_9 = F_4 ( V_4 ) ;
V_6 = F_5 ( V_9 ) ;
if ( V_6 < V_10 )
V_6 = V_10 ;
if ( ! V_4 -> V_11 && V_4 -> V_12 > V_6 ) {
V_4 -> V_13 = V_9 -> V_13 ;
F_6 ( V_4 , V_14 , 0 , V_6 ) ;
V_7 = - V_15 ;
}
return V_7 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_16 ;
V_16 = F_3 ( V_4 ) ;
if ( V_16 )
return V_16 ;
F_8 ( V_4 ) -> V_17 = F_9 ( V_4 ) -> V_18 ;
return F_10 ( V_4 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_16 ;
V_16 = F_12 ( V_2 , V_4 ) ;
if ( V_16 )
return V_16 ;
memset ( F_13 ( V_4 ) , 0 , sizeof( * F_13 ( V_4 ) ) ) ;
#ifdef F_14
F_13 ( V_4 ) -> V_19 |= V_20 ;
#endif
V_4 -> V_17 = F_15 ( V_21 ) ;
V_4 -> V_11 = 1 ;
return V_2 -> V_22 -> V_23 ( V_2 , V_4 ) ;
}
int F_16 ( struct V_3 * V_4 )
{
#ifdef F_14
F_13 ( V_4 ) -> V_19 |= V_20 ;
#endif
V_4 -> V_17 = F_15 ( V_21 ) ;
return F_17 ( V_4 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_1 * V_2 = V_9 -> V_24 ;
if ( ( V_2 && V_2 -> V_25 . V_26 == V_27 ) &&
( ( V_4 -> V_12 > F_19 ( V_4 ) && ! F_20 ( V_4 ) ) ||
F_21 ( F_4 ( V_4 ) ) ) ) {
return F_22 ( V_4 , V_2 -> V_22 -> V_28 -> V_29 ) ;
}
return V_2 -> V_22 -> V_28 -> V_29 ( V_4 ) ;
}
int F_23 ( struct V_3 * V_4 )
{
return F_24 ( V_30 , V_31 , V_4 , NULL ,
F_4 ( V_4 ) -> V_13 , F_18 ) ;
}
