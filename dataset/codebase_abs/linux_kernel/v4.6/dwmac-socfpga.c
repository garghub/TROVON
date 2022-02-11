static void F_1 ( void * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 ;
if ( ! V_5 )
return;
V_6 = F_2 ( V_5 + V_7 ) ;
V_6 &= ~ V_8 ;
switch ( V_2 ) {
case 1000 :
V_6 |= V_9 ;
break;
case 100 :
V_6 |= V_10 ;
break;
case 10 :
V_6 |= V_11 ;
break;
default:
return;
}
F_3 ( V_6 , V_5 + V_7 ) ;
}
static int F_4 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_17 * V_18 ;
T_2 V_19 , V_20 ;
int V_21 ;
struct V_14 * V_22 ;
struct V_23 V_24 ;
V_4 -> V_25 = F_5 ( V_15 ) ;
V_18 = F_6 ( V_15 , L_1 ) ;
if ( F_7 ( V_18 ) ) {
F_8 ( V_13 , L_2 ) ;
return F_9 ( V_18 ) ;
}
V_21 = F_10 ( V_15 , L_1 , 1 , & V_19 ) ;
if ( V_21 ) {
F_8 ( V_13 , L_3 ) ;
return - V_26 ;
}
V_21 = F_10 ( V_15 , L_1 , 2 , & V_20 ) ;
if ( V_21 ) {
F_8 ( V_13 , L_4 ) ;
return - V_26 ;
}
V_4 -> V_27 = F_11 ( V_15 , L_5 ) ;
V_22 = F_12 ( V_15 , L_6 , 0 ) ;
if ( V_22 ) {
if ( F_13 ( V_22 , 0 , & V_24 ) ) {
F_8 ( V_13 , L_7 ) ;
return - V_26 ;
}
V_4 -> V_5 = F_14 ( V_13 , & V_24 ) ;
if ( F_7 ( V_4 -> V_5 ) ) {
F_8 ( V_13 , L_8 ) ;
return F_9 ( V_4 -> V_5 ) ;
}
}
V_4 -> V_19 = V_19 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_13 = V_13 ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
int V_28 = V_4 -> V_25 ;
T_2 V_19 = V_4 -> V_19 ;
T_2 V_20 = V_4 -> V_20 ;
T_2 V_29 , V_6 , V_30 ;
switch ( V_28 ) {
case V_31 :
case V_32 :
V_6 = V_33 ;
break;
case V_34 :
case V_35 :
V_6 = V_36 ;
break;
default:
F_16 ( V_4 -> V_13 , L_9 , V_28 ) ;
return - V_26 ;
}
if ( V_4 -> V_5 )
V_6 = V_36 ;
F_17 ( V_18 , V_19 , & V_29 ) ;
V_29 &= ~ ( V_37 << V_20 ) ;
V_29 |= V_6 << V_20 ;
if ( V_4 -> V_27 ) {
V_29 |= V_38 << ( V_20 / 2 ) ;
F_17 ( V_18 , V_39 ,
& V_30 ) ;
V_30 |= ( V_40 << ( V_20 / 2 ) ) ;
F_18 ( V_18 , V_39 ,
V_30 ) ;
} else {
V_29 &= ~ ( V_38 << ( V_20 / 2 ) ) ;
}
F_18 ( V_18 , V_19 , V_29 ) ;
return 0 ;
}
static int F_19 ( struct V_41 * V_42 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_43 * V_44 = F_20 ( V_42 ) ;
struct V_45 * V_46 = NULL ;
int V_21 = 0 ;
if ( ! V_44 )
return - V_26 ;
V_46 = F_21 ( V_44 ) ;
if ( ! V_46 )
return - V_26 ;
if ( V_46 -> V_47 )
F_22 ( V_46 -> V_47 ) ;
V_21 = F_15 ( V_4 ) ;
if ( V_46 -> V_47 )
F_23 ( V_46 -> V_47 ) ;
if ( V_46 -> V_48 )
F_24 ( V_46 -> V_48 ) ;
return V_21 ;
}
static int F_25 ( struct V_41 * V_42 )
{
struct V_49 * V_50 ;
struct V_51 V_52 ;
struct V_12 * V_13 = & V_42 -> V_13 ;
int V_21 ;
struct V_3 * V_4 ;
V_21 = F_26 ( V_42 , & V_52 ) ;
if ( V_21 )
return V_21 ;
V_50 = F_27 ( V_42 , & V_52 . V_53 ) ;
if ( F_7 ( V_50 ) )
return F_9 ( V_50 ) ;
V_4 = F_28 ( V_13 , sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 )
return - V_55 ;
V_21 = F_4 ( V_4 , V_13 ) ;
if ( V_21 ) {
F_16 ( V_13 , L_10 ) ;
return V_21 ;
}
V_21 = F_15 ( V_4 ) ;
if ( V_21 ) {
F_16 ( V_13 , L_11 , V_21 ) ;
return V_21 ;
}
V_50 -> V_56 = V_4 ;
V_50 -> V_57 = F_19 ;
V_50 -> V_58 = F_1 ;
V_21 = F_29 ( & V_42 -> V_13 , V_50 , & V_52 ) ;
if ( ! V_21 )
V_21 = F_19 ( V_42 , V_4 ) ;
return V_21 ;
}
