static T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 ;
V_7 = F_1 ( V_2 , V_3 ) ;
V_7 &= ~ V_5 ;
V_7 |= ( V_6 & V_5 ) ;
F_4 ( V_7 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_8 * V_8 )
{
struct V_1 * V_9 = F_6 ( V_8 ) ;
int V_10 ;
if ( ! F_7 ( V_9 -> V_11 ) ) {
V_10 = F_8 ( V_9 -> V_11 ) ;
if ( V_10 ) {
F_9 ( & V_8 -> V_12 , L_1 ) ;
return V_10 ;
}
}
V_10 = F_10 ( V_9 -> V_13 ) ;
if ( V_10 ) {
F_9 ( & V_8 -> V_12 , L_2 ) ;
return V_10 ;
}
V_10 = F_10 ( V_9 -> V_14 ) ;
if ( V_10 ) {
F_9 ( & V_8 -> V_12 , L_3 ) ;
F_11 ( V_9 -> V_13 ) ;
return V_10 ;
}
F_3 ( V_9 , V_15 , V_16 ,
V_16 ) ;
F_3 ( V_9 , V_17 , V_18 ,
0x2 << V_19 ) ;
F_3 ( V_9 , V_17 , V_20 ,
0x5 << V_21 ) ;
F_3 ( V_9 , V_17 , V_22 ,
V_22 ) ;
F_12 ( V_23 ) ;
F_3 ( V_9 , V_17 , V_22 , 0 ) ;
F_12 ( V_23 ) ;
F_3 ( V_9 , V_17 , V_24 ,
V_24 ) ;
if ( V_9 -> V_25 == V_26 ) {
F_3 ( V_9 , V_27 ,
V_28 ,
V_28 ) ;
F_12 ( V_29 ) ;
if ( F_1 ( V_9 , V_27 ) &
V_30 ) {
F_13 ( & V_8 -> V_12 , L_4 ) ;
F_11 ( V_9 -> V_14 ) ;
F_11 ( V_9 -> V_13 ) ;
return - V_31 ;
}
}
return 0 ;
}
static int F_14 ( struct V_8 * V_8 )
{
struct V_1 * V_9 = F_6 ( V_8 ) ;
F_11 ( V_9 -> V_14 ) ;
F_11 ( V_9 -> V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_32 * V_33 )
{
struct V_1 * V_9 ;
struct V_34 * V_35 ;
struct V_8 * V_8 ;
struct V_36 * V_36 ;
V_9 = F_16 ( & V_33 -> V_12 , sizeof( * V_9 ) , V_37 ) ;
if ( ! V_9 )
return - V_38 ;
V_35 = F_17 ( V_33 , V_39 , 0 ) ;
V_9 -> V_4 = F_18 ( & V_33 -> V_12 , V_35 ) ;
if ( F_19 ( V_9 -> V_4 ) )
return F_20 ( V_9 -> V_4 ) ;
V_9 -> V_13 = F_21 ( & V_33 -> V_12 , L_5 ) ;
if ( F_19 ( V_9 -> V_13 ) )
return F_20 ( V_9 -> V_13 ) ;
V_9 -> V_14 = F_21 ( & V_33 -> V_12 , L_6 ) ;
if ( F_19 ( V_9 -> V_14 ) )
return F_20 ( V_9 -> V_14 ) ;
V_9 -> V_11 = F_22 ( & V_33 -> V_12 , NULL ) ;
if ( F_20 ( V_9 -> V_11 ) == - V_40 )
return F_20 ( V_9 -> V_11 ) ;
V_9 -> V_25 = F_23 ( V_33 -> V_12 . V_41 , - 1 ) ;
if ( V_9 -> V_25 == V_42 ) {
F_9 ( & V_33 -> V_12 ,
L_7 ) ;
return - V_31 ;
}
V_8 = F_24 ( & V_33 -> V_12 , NULL , & V_43 ) ;
if ( F_19 ( V_8 ) ) {
F_9 ( & V_33 -> V_12 , L_8 ) ;
return F_20 ( V_8 ) ;
}
F_25 ( V_8 , V_9 ) ;
V_36 =
F_26 ( & V_33 -> V_12 , V_44 ) ;
return F_27 ( V_36 ) ;
}
