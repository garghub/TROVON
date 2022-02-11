int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
void *
F_3 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_1 V_3 , int V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_4 ( sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
return F_5 ( - V_11 ) ;
V_9 = F_6 ( V_2 , V_3 , & V_8 -> V_12 ) ;
if ( V_9 ) {
F_7 ( V_8 ) ;
return ( V_9 == - V_13 ) ? NULL : F_5 ( V_9 ) ;
}
V_9 = F_8 ( V_2 , & V_8 -> V_12 , V_6 , & V_8 -> V_14 ) ;
if ( ! V_9 ) {
F_7 ( V_8 ) ;
return F_5 ( - V_15 ) ;
}
return V_8 ;
}
void
F_9 ( struct V_1 * V_2 , void * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_7 * V_8 = V_16 ;
T_1 V_20 = V_8 -> V_12 . V_20 ;
if ( V_18 -> V_21 >= V_22 )
V_20 += 4 ;
F_10 ( V_2 , V_20 , & V_8 -> V_14 ) ;
if ( V_18 -> V_21 < V_23 && V_20 == V_24 ) {
if ( V_18 -> V_21 == V_25 )
F_11 ( V_2 , 0x1002c4 , 0 , 1 << 20 ) ;
F_11 ( V_2 , 0x1002c0 , 0 , 1 << 8 ) ;
}
F_7 ( V_8 ) ;
}
