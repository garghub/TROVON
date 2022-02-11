static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 ,
int V_5 , bool V_6 )
{
unsigned int V_7 = V_2 -> V_8 . V_9 + V_10 ;
if ( ! F_2 ( V_3 , V_7 ) )
return - V_11 ;
return F_3 ( V_3 , 0 , V_7 , V_5 ) ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 ,
int V_5 , bool V_6 )
{
struct V_12 V_13 ;
V_13 . V_14 = V_2 -> V_13 . V_14 ;
V_13 . V_15 = V_2 -> V_13 . V_15 ;
V_13 . V_16 = V_2 -> V_13 . V_16 ;
V_13 . V_17 = V_2 -> V_13 . V_17 ;
V_13 . V_18 = V_2 -> V_13 . V_18 ;
if ( ! F_5 ( V_3 ) )
return - V_19 ;
return F_6 ( V_3 , & V_13 ) ;
}
int F_7 ( struct V_3 * V_3 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 = & V_3 -> V_24 . V_25 ;
T_1 V_26 = V_23 -> V_27 ;
int V_28 , V_29 ;
V_21 = F_8 ( V_26 , sizeof( struct V_1 ) ,
V_30 ) ;
if ( ! V_21 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
V_21 [ V_28 ] . V_32 = V_28 ;
V_21 [ V_28 ] . type = V_33 ;
V_21 [ V_28 ] . V_34 . V_8 . V_8 = 0 ;
V_21 [ V_28 ] . V_34 . V_8 . V_9 = V_28 ;
}
V_29 = F_9 ( V_3 , V_21 , V_26 , 0 ) ;
F_10 ( V_21 ) ;
return V_29 ;
}
