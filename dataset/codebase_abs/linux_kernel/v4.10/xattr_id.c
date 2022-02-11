int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int * V_4 , unsigned int * V_5 , unsigned long long * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 = F_2 ( V_3 ) ;
int V_11 = F_3 ( V_3 ) ;
T_1 V_12 = F_4 ( V_8 -> V_13 [ V_10 ] ) ;
struct V_14 V_15 ;
int V_16 ;
V_16 = F_5 ( V_2 , & V_15 , & V_12 , & V_11 ,
sizeof( V_15 ) ) ;
if ( V_16 < 0 )
return V_16 ;
* V_6 = F_4 ( V_15 . V_6 ) ;
* V_5 = F_6 ( V_15 . V_5 ) ;
* V_4 = F_6 ( V_15 . V_4 ) ;
return 0 ;
}
T_2 * F_7 ( struct V_1 * V_2 , T_1 V_17 ,
T_1 * V_18 , int * V_19 )
{
unsigned int V_20 ;
struct V_21 * V_22 ;
V_22 = F_8 ( V_2 , V_17 , sizeof( * V_22 ) ) ;
if ( F_9 ( V_22 ) )
return ( T_2 * ) V_22 ;
* V_18 = F_4 ( V_22 -> V_18 ) ;
* V_19 = F_6 ( V_22 -> V_19 ) ;
F_10 ( V_22 ) ;
if ( * V_19 == 0 )
return F_11 ( - V_23 ) ;
if ( * V_18 >= V_17 )
return F_11 ( - V_23 ) ;
V_20 = F_12 ( * V_19 ) ;
F_13 ( L_1 , V_20 ) ;
return F_8 ( V_2 , V_17 + sizeof( * V_22 ) , V_20 ) ;
}
