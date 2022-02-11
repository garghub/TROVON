static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_4 -> clock ) ;
if ( V_5 )
F_3 ( V_2 -> V_7 , L_1 , V_4 -> clock ) ;
V_2 -> V_8 = F_4 ( V_2 -> V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_10 = F_6 ( V_2 -> V_7 , sizeof( * V_10 ) , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
V_10 -> V_13 = F_7 ( V_2 -> V_7 -> V_14 ,
L_2 ) ;
if ( F_8 ( V_10 -> V_13 ) )
V_10 -> V_13 = NULL ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_17 * V_18 = F_10 ( V_16 ) ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
int V_19 , V_20 ;
int V_5 ;
V_2 = V_18 -> V_2 ;
V_10 = V_2 -> V_10 ;
if ( ! V_10 || ! V_10 -> V_13 )
return 0 ;
if ( V_4 -> V_21 == V_22 ) {
V_5 = F_11 ( V_10 -> V_13 , V_23 ,
V_24 , 0 ) ;
V_19 = 3000000 ;
V_20 = 3000000 ;
} else if ( V_4 -> V_21 == V_25 ) {
V_5 = F_11 ( V_10 -> V_13 , V_23 ,
V_24 , V_24 ) ;
V_19 = 1800000 ;
V_20 = 1800000 ;
} else {
F_12 ( V_2 -> V_7 , L_3 ) ;
return - V_26 ;
}
if ( V_5 ) {
F_12 ( V_2 -> V_7 , L_4 ) ;
return V_5 ;
}
if ( F_13 ( V_16 -> V_27 . V_28 ) )
return 0 ;
V_5 = F_14 ( V_16 -> V_27 . V_28 , V_19 , V_20 ) ;
if ( V_5 ) {
F_12 ( V_2 -> V_7 , L_5 ,
V_5 , V_19 , V_20 ) ;
return V_5 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
unsigned int clock ;
clock = ( V_4 -> clock <= 25000000 ) ? 25000000 : V_4 -> clock ;
V_5 = F_2 ( V_2 -> V_29 , clock ) ;
if ( V_5 )
F_3 ( V_2 -> V_7 , L_1 , clock ) ;
V_2 -> V_8 = F_4 ( V_2 -> V_29 ) ;
}
static int F_16 ( struct V_17 * V_18 , T_1 V_30 )
{
return 0 ;
}
static int F_17 ( struct V_31 * V_32 )
{
const struct V_33 * V_34 ;
const struct V_35 * V_36 ;
V_36 = F_18 ( V_37 , V_32 -> V_7 . V_14 ) ;
V_34 = V_36 -> V_38 ;
return F_19 ( V_32 , V_34 ) ;
}
