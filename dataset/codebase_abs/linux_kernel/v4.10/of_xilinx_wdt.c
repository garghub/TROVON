static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_5 -> V_6 ) ;
V_3 = F_4 ( V_5 -> V_7 + V_8 ) ;
V_3 |= ( V_9 | V_10 ) ;
F_5 ( ( V_3 | V_11 ) ,
V_5 -> V_7 + V_8 ) ;
F_5 ( V_12 , V_5 -> V_7 + V_13 ) ;
F_6 ( & V_5 -> V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_5 -> V_6 ) ;
V_3 = F_4 ( V_5 -> V_7 + V_8 ) ;
F_5 ( ( V_3 & ~ V_11 ) ,
V_5 -> V_7 + V_8 ) ;
F_5 ( 0 , V_5 -> V_7 + V_13 ) ;
F_6 ( & V_5 -> V_6 ) ;
F_8 ( L_1 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_5 -> V_6 ) ;
V_3 = F_4 ( V_5 -> V_7 + V_8 ) ;
V_3 |= ( V_9 | V_10 ) ;
F_5 ( V_3 , V_5 -> V_7 + V_8 ) ;
F_6 ( & V_5 -> V_6 ) ;
return 0 ;
}
static T_1 F_10 ( struct V_4 * V_5 )
{
int V_14 ;
T_1 V_15 ;
T_1 V_16 ;
F_3 ( & V_5 -> V_6 ) ;
V_15 = F_4 ( V_5 -> V_7 + V_17 ) ;
V_16 = F_4 ( V_5 -> V_7 + V_17 ) ;
for ( V_14 = 0 ;
( ( V_14 <= V_18 ) &&
( V_16 == V_15 ) ) ; V_14 ++ ) {
V_16 = F_4 ( V_5 -> V_7 + V_17 ) ;
}
F_6 ( & V_5 -> V_6 ) ;
if ( V_16 != V_15 )
return ~ V_19 ;
else
return V_19 ;
}
static int F_11 ( struct V_20 * V_21 )
{
int V_22 ;
T_1 V_23 = 0 , V_24 = 0 ;
struct V_25 * V_26 ;
struct V_4 * V_5 ;
struct V_1 * V_27 ;
V_5 = F_12 ( & V_21 -> V_28 , sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 )
return - V_30 ;
V_27 = & V_5 -> V_27 ;
V_27 -> V_31 = & V_32 ;
V_27 -> V_33 = & V_34 ;
V_27 -> V_35 = & V_21 -> V_28 ;
V_26 = F_13 ( V_21 , V_36 , 0 ) ;
V_5 -> V_7 = F_14 ( & V_21 -> V_28 , V_26 ) ;
if ( F_15 ( V_5 -> V_7 ) )
return F_16 ( V_5 -> V_7 ) ;
V_22 = F_17 ( V_21 -> V_28 . V_37 , L_2 , & V_23 ) ;
if ( V_22 )
F_18 ( & V_21 -> V_28 ,
L_3 ) ;
V_22 = F_17 ( V_21 -> V_28 . V_37 , L_4 ,
& V_5 -> V_38 ) ;
if ( V_22 )
F_18 ( & V_21 -> V_28 ,
L_5 ) ;
V_22 = F_17 ( V_21 -> V_28 . V_37 , L_6 ,
& V_24 ) ;
if ( V_22 )
F_18 ( & V_21 -> V_28 ,
L_7 ) ;
F_19 ( V_27 , V_24 ) ;
if ( V_23 && V_5 -> V_38 )
V_27 -> V_39 = 2 * ( ( 1 << V_5 -> V_38 ) /
V_23 ) ;
F_20 ( & V_5 -> V_6 ) ;
F_21 ( V_27 , V_5 ) ;
V_5 -> V_40 = F_22 ( & V_21 -> V_28 , NULL ) ;
if ( F_15 ( V_5 -> V_40 ) ) {
if ( F_16 ( V_5 -> V_40 ) == - V_41 )
V_5 -> V_40 = NULL ;
else
return F_16 ( V_5 -> V_40 ) ;
}
V_22 = F_23 ( V_5 -> V_40 ) ;
if ( V_22 ) {
F_24 ( & V_21 -> V_28 , L_8 ) ;
return V_22 ;
}
V_22 = F_10 ( V_5 ) ;
if ( V_22 == V_19 ) {
F_24 ( & V_21 -> V_28 , L_9 ) ;
goto V_42;
}
V_22 = F_25 ( V_27 ) ;
if ( V_22 ) {
F_24 ( & V_21 -> V_28 , L_10 , V_22 ) ;
goto V_42;
}
F_26 ( & V_21 -> V_28 , L_11 ,
V_5 -> V_7 , V_27 -> V_39 ) ;
F_27 ( V_21 , V_5 ) ;
return 0 ;
V_42:
F_28 ( V_5 -> V_40 ) ;
return V_22 ;
}
static int F_29 ( struct V_20 * V_21 )
{
struct V_4 * V_5 = F_30 ( V_21 ) ;
F_31 ( & V_5 -> V_27 ) ;
F_28 ( V_5 -> V_40 ) ;
return 0 ;
}
