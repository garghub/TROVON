static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
T_1 V_6 ;
int V_7 ;
V_7 = F_6 ( V_5 -> V_8 , V_5 -> V_9 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_6 &= V_10 ;
switch ( V_5 -> V_11 ) {
case V_12 :
V_6 &= ~ ( V_13
| V_14 | F_7 ( 0x3 )
| V_15 | V_16
| V_17 | V_18 ) ;
V_6 |= V_19 | V_20 ;
break;
case V_21 :
V_6 &= ~ ( V_19 | V_20
| V_14 | F_7 ( 0x3 )
| V_15 | V_16
| V_17 | V_18 ) ;
V_6 |= V_13 ;
break;
default:
F_8 ( V_5 -> V_22 , L_1 ,
V_5 -> V_11 ) ;
return - V_23 ;
}
return F_9 ( V_5 -> V_8 , V_5 -> V_9 , V_6 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
T_1 V_24 = F_1 ( V_5 -> V_25 , V_26 ) ;
V_24 |= V_27 | V_28 | V_29 ;
V_24 &= ~ V_30 ;
F_3 ( V_5 -> V_25 , V_26 , V_24 ) ;
V_24 = F_1 ( V_5 -> V_25 , V_31 ) ;
V_24 |= F_11 ( V_32 ) |
F_12 ( V_32 ) |
F_13 ( V_32 ) ;
F_3 ( V_5 -> V_25 , V_31 , V_24 ) ;
V_24 = F_1 ( V_5 -> V_25 , V_26 ) ;
V_24 |= V_30 ;
F_3 ( V_5 -> V_25 , V_26 , V_24 ) ;
}
static int F_14 ( struct V_33 * V_34 )
{
struct V_4 * V_5 ;
struct V_35 * V_36 ;
struct V_37 * V_22 = & V_34 -> V_22 ;
struct V_38 * V_39 = V_22 -> V_40 , * V_41 ;
struct V_33 * V_42 ;
struct V_8 * V_8 ;
int V_43 ;
V_5 = F_15 ( V_22 , sizeof( * V_5 ) , V_44 ) ;
if ( ! V_5 )
return - V_45 ;
V_36 = F_16 ( V_34 , V_46 , L_2 ) ;
V_5 -> V_25 = F_17 ( V_22 , V_36 ) ;
if ( F_18 ( V_5 -> V_25 ) )
return F_19 ( V_5 -> V_25 ) ;
V_8 = F_20 ( V_39 , L_3 ) ;
if ( F_18 ( V_8 ) )
return F_19 ( V_8 ) ;
V_5 -> V_22 = V_22 ;
V_5 -> V_8 = V_8 ;
V_36 = F_16 ( V_34 , V_46 , L_4 ) ;
if ( ! V_36 ) {
V_43 = - V_47 ;
goto V_48;
}
V_5 -> V_9 = V_36 -> V_49 ;
F_21 ( & V_34 -> V_22 , L_5 ,
V_5 -> V_25 , V_5 -> V_9 ) ;
V_5 -> V_50 =
F_22 ( V_22 , L_6 ) ;
if ( F_18 ( V_5 -> V_50 ) ) {
F_8 ( & V_34 -> V_22 , L_7 ) ;
V_43 = F_19 ( V_5 -> V_50 ) ;
goto V_48;
}
F_23 ( V_5 -> V_50 ) ;
V_5 -> V_51 =
F_24 ( V_22 , L_8 ) ;
if ( F_18 ( V_5 -> V_51 ) ) {
F_8 ( & V_34 -> V_22 , L_9 ) ;
V_43 = F_19 ( V_5 -> V_51 ) ;
goto V_52;
}
F_23 ( V_5 -> V_51 ) ;
V_41 = F_25 ( V_39 , L_10 ) ;
if ( ! V_41 ) {
F_8 ( & V_34 -> V_22 , L_11 ) ;
V_43 = - V_53 ;
goto V_54;
}
V_43 = F_26 ( V_39 , NULL , NULL , V_22 ) ;
if ( V_43 ) {
F_8 ( V_22 , L_12 ) ;
goto V_54;
}
V_42 = F_27 ( V_41 ) ;
if ( ! V_42 ) {
F_8 ( V_22 , L_13 ) ;
V_43 = - V_53 ;
goto V_54;
}
V_5 -> V_11 = F_28 ( & V_42 -> V_22 ) ;
V_43 = F_5 ( V_5 ) ;
if ( V_43 ) {
F_8 ( V_22 , L_14 ) ;
goto V_54;
}
F_10 ( V_5 ) ;
F_29 ( V_34 , V_5 ) ;
return 0 ;
V_54:
F_30 ( V_5 -> V_51 ) ;
V_52:
F_30 ( V_5 -> V_50 ) ;
V_48:
F_31 ( V_34 ) ;
return V_43 ;
}
static int F_32 ( struct V_33 * V_34 )
{
struct V_4 * V_5 = F_33 ( V_34 ) ;
F_34 ( & V_34 -> V_22 ) ;
F_30 ( V_5 -> V_50 ) ;
F_30 ( V_5 -> V_51 ) ;
return 0 ;
}
static int F_35 ( struct V_37 * V_22 )
{
struct V_4 * V_5 = F_36 ( V_22 ) ;
F_30 ( V_5 -> V_50 ) ;
F_30 ( V_5 -> V_51 ) ;
F_37 ( V_22 ) ;
return 0 ;
}
static int F_38 ( struct V_37 * V_22 )
{
struct V_4 * V_5 = F_36 ( V_22 ) ;
int V_43 ;
F_39 ( V_22 ) ;
F_23 ( V_5 -> V_50 ) ;
F_23 ( V_5 -> V_51 ) ;
V_43 = F_5 ( V_5 ) ;
if ( V_43 ) {
F_8 ( V_22 , L_14 ) ;
return V_43 ;
}
F_10 ( V_5 ) ;
return 0 ;
}
