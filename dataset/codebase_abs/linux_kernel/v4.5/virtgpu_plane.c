static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_12 = F_5 ( V_2 -> V_13 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_1 V_18 ;
if ( V_2 -> V_19 ) {
V_15 = F_6 ( V_2 -> V_19 ) ;
V_17 = F_7 ( V_15 -> V_20 ) ;
V_18 = V_17 -> V_21 ;
} else {
V_18 = 0 ;
}
F_8 ( L_1 , V_18 ,
V_2 -> V_4 -> V_22 , V_2 -> V_4 -> V_23 ,
V_2 -> V_4 -> V_24 , V_2 -> V_4 -> V_25 ) ;
F_9 ( V_9 , V_12 -> V_26 , V_18 ,
V_2 -> V_4 -> V_22 ,
V_2 -> V_4 -> V_23 ,
V_2 -> V_4 -> V_24 ,
V_2 -> V_4 -> V_25 ) ;
}
struct V_1 * F_10 ( struct V_8 * V_9 ,
int V_26 )
{
struct V_6 * V_7 = V_9 -> V_27 ;
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return F_12 ( - V_30 ) ;
V_28 = F_13 ( V_7 , V_2 , 1 << V_26 ,
& V_31 ,
V_32 ,
F_14 ( V_32 ) ,
V_33 , NULL ) ;
if ( V_28 )
goto V_34;
F_15 ( V_2 , & V_35 ) ;
return V_2 ;
V_34:
F_2 ( V_2 ) ;
return F_12 ( V_28 ) ;
}
