static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 )
{
int V_4 = 0 ;
unsigned int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
V_7 -> V_9 =
F_3 ( L_1 ) ;
if ( F_4 ( V_7 -> V_9 ) ) {
F_5 ( V_2 , L_2 ) ;
return F_6 ( V_7 -> V_9 ) ;
}
V_4 = F_7 ( V_7 -> V_10 ) ;
if ( V_4 < 0 ) {
F_5 ( V_2 , L_3 , V_4 ) ;
return V_4 ;
}
F_8 ( V_7 -> V_9 , 0x34 , V_11
| V_12
| V_13
| V_14
| V_15
| V_16
| V_17
| V_18
| V_19
, V_20
| V_21
| V_22
| V_23
| V_15
| V_24
| V_25
| V_26 ) ;
F_8 ( V_7 -> V_9 , 0x34 , V_27 ,
V_27 ) ;
F_9 ( 100 , 200 ) ;
V_5 = F_10 ( V_3 + V_28 ) ;
if ( ! ( V_5 & V_29 ) ) {
V_5 |= V_29 ;
F_11 ( V_5 , V_3 + V_28 ) ;
}
V_5 = F_10 ( V_3 + V_30 ) ;
if ( ! ( V_5 & 0x1 ) ) {
V_5 |= 0x1 ;
F_11 ( V_5 , V_3 + V_30 ) ;
}
V_5 = F_12 ( V_7 -> V_31 ) / 1000 ;
F_11 ( V_5 , V_3 + V_32 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
F_8 ( V_7 -> V_9 , 0x34 , V_27 ,
! V_27 ) ;
F_14 ( V_7 -> V_10 ) ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = & V_34 -> V_2 ;
struct V_35 * V_36 , * V_37 , V_38 [ 2 ] ;
const struct V_39 * V_40 ;
const struct V_41 * V_42 = NULL ;
struct V_6 * V_7 ;
struct V_1 * V_43 ;
struct V_33 * V_44 ;
int V_4 ;
V_7 = F_16 ( V_2 , sizeof( * V_7 ) , V_45 ) ;
if ( ! V_7 ) {
F_5 ( V_2 , L_4 ) ;
return - V_46 ;
}
V_44 = F_17 ( L_5 , - 1 ) ;
if ( ! V_44 )
return - V_47 ;
V_43 = & V_44 -> V_2 ;
V_43 -> V_8 = V_2 ;
V_7 -> V_31 = F_18 ( V_2 , L_6 ) ;
if ( F_4 ( V_7 -> V_31 ) ) {
F_5 ( V_2 , L_7 ) ;
V_4 = F_6 ( V_7 -> V_31 ) ;
goto V_48;
}
V_7 -> V_10 = F_18 ( V_2 , L_8 ) ;
if ( F_4 ( V_7 -> V_10 ) ) {
F_5 ( V_2 , L_9 ) ;
V_4 = F_6 ( V_7 -> V_10 ) ;
goto V_48;
}
V_7 -> V_44 = V_44 ;
F_19 ( V_34 , V_7 ) ;
V_40 = F_20 ( V_49 , V_2 ) ;
if ( V_40 ) {
V_42 = V_40 -> V_50 ;
} else {
V_4 = - V_51 ;
goto V_48;
}
V_36 = F_21 ( V_34 , V_52 , 0 ) ;
V_37 = F_21 ( V_34 , V_53 , 0 ) ;
if ( ! V_36 || ! V_37 ) {
F_5 ( V_2 , L_10 ) ;
V_4 = - V_46 ;
goto V_48;
}
V_38 [ 0 ] = * V_36 ;
V_38 [ 1 ] = * V_37 ;
V_43 -> V_54 = F_22 ( 32 ) ;
V_43 -> V_55 = & V_43 -> V_54 ;
V_43 -> V_56 = V_2 -> V_56 ;
V_4 = F_23 ( V_44 , V_38 , 2 ) ;
if ( V_4 )
goto V_48;
V_4 = F_24 ( V_44 , V_42 , sizeof( * V_42 ) ) ;
if ( V_4 )
goto V_48;
V_4 = F_25 ( V_44 ) ;
if ( V_4 ) {
V_48:
F_26 ( V_44 ) ;
return V_4 ;
}
return 0 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_6 * V_7 = F_28 ( V_34 ) ;
struct V_33 * V_44 = V_7 -> V_44 ;
F_29 ( V_44 ) ;
return 0 ;
}
