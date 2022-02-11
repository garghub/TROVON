static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_2 -> V_5 ) ;
F_4 ( V_4 -> V_6 , V_7 ,
V_4 -> V_8 ) ;
F_5 ( V_2 -> V_5 ) ;
V_2 -> V_9 /= ( V_4 -> V_10 + 1 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_8 & V_12 )
* V_11 |= V_13 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_14 * V_15 = V_2 -> V_16 -> V_17 ;
T_1 V_18 [ 2 ] ;
T_1 div = 0 ;
int V_19 ;
V_4 = F_8 ( V_2 -> V_16 , sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 ) {
F_9 ( V_2 -> V_16 , L_1 ) ;
return - V_21 ;
}
V_4 -> V_6 = F_10 ( L_2 ) ;
if ( F_11 ( V_4 -> V_6 ) ) {
F_9 ( V_2 -> V_16 , L_3 ) ;
return F_12 ( V_4 -> V_6 ) ;
}
V_19 = F_13 ( V_15 , L_4 , & div ) ;
if ( V_19 )
F_14 ( V_2 -> V_16 , L_5 ) ;
V_4 -> V_10 = div ;
V_19 = F_15 ( V_15 ,
L_6 , V_18 , 2 ) ;
if ( V_19 )
return V_19 ;
V_4 -> V_8 = F_16 ( V_18 [ 0 ] , V_18 [ 1 ] ) ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 )
{
const struct V_24 * V_25 ;
const struct V_26 * V_27 ;
V_27 = F_18 ( V_28 , V_23 -> V_16 . V_17 ) ;
V_25 = V_27 -> V_29 ;
return F_19 ( V_23 , V_25 ) ;
}
