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
V_12 ) ;
return F_4 ( V_2 , V_8 , V_5 ) ;
}
V_5 = 0x0 ;
return F_4 ( V_2 , V_8 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_19 ;
int V_20 ;
if ( ! V_19 && V_17 -> V_21 -> V_19 )
V_19 = V_17 -> V_21 -> V_19 ;
if ( ! V_2 -> V_17 . V_19 )
return - V_22 ;
V_20 = F_6 ( V_19 , L_1 ,
& V_14 -> V_23 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_6 ( V_19 , L_2 ,
& V_14 -> V_24 ) ;
if ( V_20 )
return V_20 ;
return F_6 ( V_19 , L_3 ,
& V_14 -> V_25 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_20 ;
T_1 V_26 , V_27 ;
if ( ! V_2 -> V_15 ) {
V_14 = F_8 ( & V_2 -> V_17 , sizeof( * V_14 ) ,
V_28 ) ;
if ( ! V_14 )
return - V_29 ;
V_2 -> V_15 = V_14 ;
V_20 = F_5 ( V_2 ) ;
if ( V_20 )
return V_20 ;
} else {
V_14 = (struct V_13 * ) V_2 -> V_15 ;
}
if ( F_9 ( V_2 ) ) {
V_20 = F_4 ( V_2 , V_30 ,
( V_14 -> V_25 << V_31 ) ) ;
if ( V_20 )
return V_20 ;
}
if ( ( V_2 -> V_32 >= V_33 ) &&
( V_2 -> V_32 <= V_34 ) ) {
V_26 = F_10 ( V_2 , V_35 ,
V_36 , V_2 -> V_37 ) ;
if ( V_2 -> V_32 == V_33 )
V_26 |= ( V_38 | V_39 ) ;
if ( V_2 -> V_32 == V_40 )
V_26 |= V_38 ;
if ( V_2 -> V_32 == V_34 )
V_26 |= V_39 ;
F_11 ( V_2 , V_35 ,
V_36 , V_2 -> V_37 , V_26 ) ;
V_27 = ( V_14 -> V_23 |
( V_14 -> V_24 << V_41 ) ) ;
F_11 ( V_2 , V_42 ,
V_36 , V_2 -> V_37 , V_27 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_43 , V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_7 ( V_2 ) ;
}
