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
struct V_15 * V_16 =
(struct V_15 * ) V_2 -> V_17 ;
T_1 V_18 ;
V_18 = F_6 ( V_2 , V_19 , V_20 ) ;
if ( V_16 -> V_21 == V_22 )
V_18 |= V_23 ;
else
V_18 &= ~ V_23 ;
F_7 ( V_2 , V_19 , V_20 , V_18 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_24 * V_25 = & V_2 -> V_26 . V_25 ;
struct V_27 * V_28 = V_25 -> V_28 ;
int V_29 ;
if ( ! V_28 )
return - V_30 ;
V_16 -> V_31 = - V_32 ;
if ( F_9 ( V_28 , L_1 ) )
V_16 -> V_31 = V_33 ;
else if ( F_9 ( V_28 , L_2 ) )
V_16 -> V_31 = V_34 ;
V_16 -> V_35 = F_9 ( V_28 ,
L_3 ) ;
V_29 = F_10 ( V_28 , L_4 ,
& V_16 -> V_36 ) ;
if ( V_29 &&
( V_2 -> V_37 == V_38 ||
V_2 -> V_37 == V_39 ) )
return V_29 ;
V_29 = F_10 ( V_28 , L_5 ,
& V_16 -> V_40 ) ;
if ( V_29 &&
( V_2 -> V_37 == V_38 ||
V_2 -> V_37 == V_41 ) )
return V_29 ;
if ( F_9 ( V_28 , L_6 ) )
V_16 -> V_21 = V_22 ;
if ( F_9 ( V_28 , L_7 ) )
V_16 -> V_21 = V_42 ;
return F_10 ( V_28 , L_8 ,
& V_16 -> V_43 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_29 , V_18 , V_44 ;
T_1 V_45 ;
if ( ! V_2 -> V_17 ) {
V_16 = F_12 ( & V_2 -> V_26 . V_25 , sizeof( * V_16 ) ,
V_46 ) ;
if ( ! V_16 )
return - V_47 ;
V_2 -> V_17 = V_16 ;
V_29 = F_8 ( V_2 ) ;
if ( V_29 )
return V_29 ;
} else {
V_16 = (struct V_15 * ) V_2 -> V_17 ;
}
if ( V_16 -> V_35 ) {
V_18 = F_6 ( V_2 , V_19 , V_20 ) ;
V_18 &= ~ F_13 ( 7 ) ;
F_7 ( V_2 , V_19 , V_20 , V_18 ) ;
}
if ( F_14 ( V_2 ) ) {
V_18 = F_2 ( V_2 , V_48 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 &= ~ V_49 ;
V_18 |= ( V_16 -> V_43 << V_50 ) ;
V_44 = F_6 ( V_2 , V_19 , V_51 ) ;
if ( V_44 & V_52 )
V_18 &= ~ V_53 ;
V_29 = F_4 ( V_2 , V_48 , V_18 ) ;
if ( V_29 )
return V_29 ;
}
if ( ( V_2 -> V_37 >= V_38 ) &&
( V_2 -> V_37 <= V_39 ) ) {
V_18 = F_6 ( V_2 , V_19 , V_54 ) ;
if ( V_2 -> V_37 == V_38 )
V_18 |= ( V_55 | V_56 ) ;
if ( V_2 -> V_37 == V_41 )
V_18 |= V_55 ;
if ( V_2 -> V_37 == V_39 )
V_18 |= V_56 ;
F_7 ( V_2 , V_19 , V_54 , V_18 ) ;
V_45 = ( V_16 -> V_36 |
( V_16 -> V_40 << V_57 ) ) ;
F_7 ( V_2 , V_19 , V_58 ,
V_45 ) ;
if ( V_16 -> V_31 >= 0 ) {
V_18 = F_6 ( V_2 , V_19 ,
V_59 ) ;
V_18 &= ~ V_60 ;
V_18 |= V_16 -> V_31 &
V_60 ;
F_7 ( V_2 , V_19 ,
V_59 , V_18 ) ;
}
}
if ( F_15 ( V_2 ) ) {
V_18 = F_2 ( V_2 , V_61 ) ;
V_18 |= F_13 ( 7 ) ;
F_4 ( V_2 , V_61 , V_18 ) ;
}
if ( V_16 -> V_21 != V_62 )
F_5 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_63 , V_64 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_11 ( V_2 ) ;
}
