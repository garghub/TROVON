static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 , sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 ) {
F_3 ( V_2 -> V_5 , L_1 ) ;
return - V_7 ;
}
V_4 -> V_8 = F_4 ( L_2 ) ;
if ( F_5 ( V_4 -> V_8 ) ) {
F_3 ( V_2 -> V_5 , L_3 ) ;
return F_6 ( V_4 -> V_8 ) ;
}
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( V_2 -> V_9 ) ;
F_9 ( V_4 -> V_8 , V_10 ,
V_4 -> V_11 ) ;
F_10 ( V_2 -> V_9 ) ;
V_2 -> V_12 /= ( V_4 -> V_13 + 1 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 * V_14 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_11 & V_15 )
* V_14 |= V_16 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_17 * V_18 = V_2 -> V_5 -> V_19 ;
T_1 V_20 [ 2 ] ;
T_1 div = 0 ;
int V_21 ;
V_21 = F_13 ( V_18 , L_4 , & div ) ;
if ( V_21 )
F_14 ( V_2 -> V_5 , L_5 ) ;
V_4 -> V_13 = div ;
V_21 = F_15 ( V_18 ,
L_6 , V_20 , 2 ) ;
if ( V_21 )
return V_21 ;
V_4 -> V_11 = F_16 ( V_20 [ 0 ] , V_20 [ 1 ] ) ;
return 0 ;
}
int F_17 ( struct V_22 * V_23 )
{
const struct V_24 * V_25 ;
const struct V_26 * V_27 ;
V_27 = F_18 ( V_28 , V_23 -> V_5 . V_19 ) ;
V_25 = V_27 -> V_29 ;
return F_19 ( V_23 , V_25 ) ;
}
