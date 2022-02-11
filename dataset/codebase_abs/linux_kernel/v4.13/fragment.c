int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = F_2 ( V_3 ) ;
int V_9 = F_3 ( V_3 ) ;
T_1 V_10 = F_4 ( V_6 -> V_11 [ V_8 ] ) ;
struct V_12 V_13 ;
int V_14 ;
V_14 = F_5 ( V_2 , & V_13 , & V_10 ,
& V_9 , sizeof( V_13 ) ) ;
if ( V_14 < 0 )
return V_14 ;
* V_4 = F_4 ( V_13 . V_10 ) ;
V_14 = F_6 ( V_13 . V_14 ) ;
return V_14 ;
}
T_2 * F_7 ( struct V_1 * V_2 ,
T_1 V_15 , T_1 V_16 , unsigned int V_17 )
{
unsigned int V_18 = F_8 ( V_17 ) ;
T_2 * V_19 ;
if ( V_15 + V_18 > V_16 )
return F_9 ( - V_20 ) ;
V_19 = F_10 ( V_2 , V_15 , V_18 ) ;
if ( ! F_11 ( V_19 ) && F_4 ( V_19 [ 0 ] ) >= V_15 ) {
F_12 ( V_19 ) ;
return F_9 ( - V_20 ) ;
}
return V_19 ;
}
