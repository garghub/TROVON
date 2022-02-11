static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
V_7 = F_3 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_11 ;
V_10 = F_4 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_2 -> V_12 = F_5 ( V_5 , 1 ) ;
V_7 -> V_12 = V_2 -> V_12 ;
V_7 -> V_13 = F_5 ( V_5 , 0 ) ;
V_7 -> V_14 = F_5 ( V_5 , 2 ) ;
V_7 -> V_15 = F_5 ( V_5 , 3 ) ;
if ( V_5 -> V_16 > 0 ) {
V_10 = F_6 ( V_5 -> V_16 , V_17 , V_18 ,
V_2 -> V_19 , V_2 ) ;
if ( V_10 == 0 )
V_2 -> V_16 = V_5 -> V_16 ;
}
V_10 = F_7 ( V_2 , 3 ) ;
if ( V_10 )
return V_10 ;
V_9 = & V_2 -> V_20 [ 0 ] ;
V_9 -> type = V_21 ;
V_9 -> V_22 = V_23 ;
V_9 -> V_24 = 16 ;
V_9 -> V_25 = 1 ;
V_9 -> V_26 = & V_27 ;
V_9 -> V_28 = V_29 ;
V_9 -> V_30 = V_31 ;
V_9 -> V_32 = V_33 ;
V_9 -> V_34 = V_35 ;
V_9 = & V_2 -> V_20 [ 1 ] ;
V_9 -> type = V_36 ;
V_9 -> V_22 = V_23 | V_37 ;
V_9 -> V_24 = 16 ;
V_9 -> V_25 = 1 ;
V_9 -> V_26 = & V_27 ;
V_9 -> V_28 = V_38 ;
V_9 -> V_32 = V_39 ;
V_9 -> V_34 = V_40 ;
V_9 = & V_2 -> V_20 [ 2 ] ;
V_9 -> type = V_41 ;
V_9 -> V_22 = V_37 ;
V_9 -> V_24 = 1 ;
V_9 -> V_25 = 0 ;
V_9 -> V_42 = 1 ;
V_9 -> V_26 = & V_27 ;
V_9 -> V_32 = V_43 ;
V_9 -> V_30 = V_44 ;
V_9 -> V_28 = V_45 ;
V_9 -> V_34 = V_46 ;
F_8 ( V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 )
F_8 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_4 * V_2 ,
const struct V_47 * V_48 )
{
return F_12 ( V_2 , & V_49 , V_48 -> V_50 ) ;
}
