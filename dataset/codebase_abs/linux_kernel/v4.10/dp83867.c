static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_6 == V_7 ) {
V_5 = F_2 ( V_2 , V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 |=
( V_9 |
V_10 |
V_11 |
V_12 |
V_13 |
V_14 ) ;
return F_4 ( V_2 , V_8 , V_5 ) ;
}
V_5 = 0x0 ;
return F_4 ( V_2 , V_8 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 = & V_2 -> V_20 . V_19 ;
struct V_21 * V_22 = V_19 -> V_22 ;
int V_23 ;
if ( ! V_22 )
return - V_24 ;
V_16 -> V_25 = - V_26 ;
if ( F_6 ( V_22 , L_1 ) )
V_16 -> V_25 = V_27 ;
else if ( F_6 ( V_22 , L_2 ) )
V_16 -> V_25 = V_28 ;
V_23 = F_7 ( V_22 , L_3 ,
& V_16 -> V_29 ) ;
if ( V_23 &&
( V_2 -> V_30 == V_31 ||
V_2 -> V_30 == V_32 ) )
return V_23 ;
V_23 = F_7 ( V_22 , L_4 ,
& V_16 -> V_33 ) ;
if ( V_23 &&
( V_2 -> V_30 == V_31 ||
V_2 -> V_30 == V_34 ) )
return V_23 ;
return F_7 ( V_22 , L_5 ,
& V_16 -> V_35 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_23 , V_36 ;
T_1 V_37 ;
if ( ! V_2 -> V_17 ) {
V_16 = F_9 ( & V_2 -> V_20 . V_19 , sizeof( * V_16 ) ,
V_38 ) ;
if ( ! V_16 )
return - V_39 ;
V_2 -> V_17 = V_16 ;
V_23 = F_5 ( V_2 ) ;
if ( V_23 )
return V_23 ;
} else {
V_16 = (struct V_15 * ) V_2 -> V_17 ;
}
if ( F_10 ( V_2 ) ) {
V_36 = F_2 ( V_2 , V_40 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 &= ~ V_41 ;
V_36 |= ( V_16 -> V_35 << V_42 ) ;
V_23 = F_4 ( V_2 , V_40 , V_36 ) ;
if ( V_23 )
return V_23 ;
}
if ( ( V_2 -> V_30 >= V_31 ) &&
( V_2 -> V_30 <= V_32 ) ) {
V_36 = F_11 ( V_2 , V_43 ,
V_44 ) ;
if ( V_2 -> V_30 == V_31 )
V_36 |= ( V_45 | V_46 ) ;
if ( V_2 -> V_30 == V_34 )
V_36 |= V_45 ;
if ( V_2 -> V_30 == V_32 )
V_36 |= V_46 ;
F_12 ( V_2 , V_43 ,
V_44 , V_36 ) ;
V_37 = ( V_16 -> V_29 |
( V_16 -> V_33 << V_47 ) ) ;
F_12 ( V_2 , V_48 ,
V_44 , V_37 ) ;
if ( V_16 -> V_25 >= 0 ) {
V_36 = F_11 ( V_2 , V_49 ,
V_44 ) ;
V_36 &= ~ V_50 ;
V_36 |= V_16 -> V_25 &
V_50 ;
F_12 ( V_2 , V_49 ,
V_44 , V_36 ) ;
}
}
if ( F_13 ( V_2 ) ) {
V_36 = F_2 ( V_2 , V_51 ) ;
V_36 |= F_14 ( 7 ) ;
F_4 ( V_2 , V_51 , V_36 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_52 , V_53 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_8 ( V_2 ) ;
}
