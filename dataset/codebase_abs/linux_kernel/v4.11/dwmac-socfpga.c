static void F_1 ( void * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
void T_1 * V_5 = V_4 -> V_5 ;
void T_1 * V_6 = V_4 -> V_7 . V_6 ;
void T_1 * V_8 = V_4 -> V_7 . V_8 ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_13 * V_14 = V_12 -> V_15 ;
T_2 V_16 ;
if ( ( V_6 ) && ( V_8 ) )
F_3 ( V_17 ,
V_8 + V_18 ) ;
if ( V_5 ) {
V_16 = F_4 ( V_5 + V_19 ) ;
V_16 &= ~ V_20 ;
switch ( V_2 ) {
case 1000 :
V_16 |= V_21 ;
break;
case 100 :
V_16 |= V_22 ;
break;
case 10 :
V_16 |= V_23 ;
break;
default:
return;
}
F_5 ( V_16 , V_5 + V_19 ) ;
}
if ( V_6 && V_8 )
F_6 ( & V_4 -> V_7 , V_14 , V_2 ) ;
}
static int F_7 ( struct V_3 * V_4 , struct V_9 * V_10 )
{
struct V_24 * V_25 = V_10 -> V_26 ;
struct V_27 * V_28 ;
T_2 V_29 , V_30 ;
int V_31 , V_32 ;
struct V_24 * V_33 = NULL ;
struct V_24 * V_34 = NULL ;
struct V_35 V_36 ;
struct V_35 V_37 ;
struct V_35 V_38 ;
V_4 -> V_39 = F_8 ( V_25 ) ;
V_28 = F_9 ( V_25 , L_1 ) ;
if ( F_10 ( V_28 ) ) {
F_11 ( V_10 , L_2 ) ;
return F_12 ( V_28 ) ;
}
V_31 = F_13 ( V_25 , L_1 , 1 , & V_29 ) ;
if ( V_31 ) {
F_11 ( V_10 , L_3 ) ;
return - V_40 ;
}
V_31 = F_13 ( V_25 , L_1 , 2 , & V_30 ) ;
if ( V_31 ) {
F_11 ( V_10 , L_4 ) ;
return - V_40 ;
}
V_4 -> V_41 = F_14 ( V_25 , L_5 ) ;
V_33 = F_15 ( V_25 , L_6 , 0 ) ;
if ( V_33 ) {
V_31 = F_16 ( V_33 , 0 , & V_36 ) ;
F_17 ( V_33 ) ;
if ( V_31 ) {
F_11 ( V_10 , L_7 ) ;
return - V_40 ;
}
V_4 -> V_5 = F_18 ( V_10 , & V_36 ) ;
if ( F_10 ( V_4 -> V_5 ) ) {
F_11 ( V_10 , L_8 ) ;
return F_12 ( V_4 -> V_5 ) ;
}
}
V_34 = F_15 ( V_25 ,
L_9 , 0 ) ;
if ( V_34 ) {
V_32 = F_19 ( V_34 , L_10 ,
L_11 ) ;
if ( V_32 >= 0 ) {
if ( F_16 ( V_34 , V_32 ,
& V_36 ) ) {
F_20 ( V_10 ,
L_12 ,
V_42 ) ;
V_31 = - V_40 ;
goto V_43;
}
V_4 -> V_5 =
F_18 ( V_10 , & V_36 ) ;
if ( F_10 ( V_4 -> V_5 ) ) {
V_31 = F_12 ( V_4 -> V_5 ) ;
goto V_43;
}
}
V_32 = F_19 ( V_34 , L_10 ,
L_13 ) ;
if ( V_32 >= 0 ) {
if ( F_16 ( V_34 , V_32 ,
& V_38 ) ) {
F_20 ( V_10 ,
L_14 ,
V_42 ) ;
V_31 = - V_40 ;
goto V_43;
}
V_4 -> V_7 . V_8 =
F_18 ( V_10 , & V_38 ) ;
if ( F_10 ( V_4 -> V_7 . V_8 ) ) {
V_31 = F_12 ( V_4 -> V_7 . V_8 ) ;
goto V_43;
}
}
V_32 = F_19 ( V_34 , L_10 ,
L_15 ) ;
if ( V_32 >= 0 ) {
if ( F_16 ( V_34 , V_32 ,
& V_37 ) ) {
F_20 ( V_10 ,
L_16 ,
V_42 ) ;
V_31 = - V_40 ;
goto V_43;
}
V_4 -> V_7 . V_6 =
F_18 ( V_10 , & V_37 ) ;
if ( F_10 ( V_4 -> V_7 . V_6 ) ) {
V_31 = F_12 ( V_4 -> V_7 . V_6 ) ;
goto V_43;
}
}
}
V_4 -> V_29 = V_29 ;
V_4 -> V_30 = V_30 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_10 = V_10 ;
F_17 ( V_34 ) ;
return 0 ;
V_43:
F_17 ( V_34 ) ;
return V_31 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
int V_44 = V_4 -> V_39 ;
T_2 V_29 = V_4 -> V_29 ;
T_2 V_30 = V_4 -> V_30 ;
T_2 V_45 , V_16 , V_46 ;
switch ( V_44 ) {
case V_47 :
case V_48 :
V_16 = V_49 ;
break;
case V_50 :
case V_51 :
case V_52 :
V_16 = V_53 ;
break;
default:
F_20 ( V_4 -> V_10 , L_17 , V_44 ) ;
return - V_40 ;
}
if ( V_4 -> V_5 )
V_16 = V_53 ;
if ( V_4 -> V_54 )
F_22 ( V_4 -> V_54 ) ;
F_23 ( V_28 , V_29 , & V_45 ) ;
V_45 &= ~ ( V_55 << V_30 ) ;
V_45 |= V_16 << V_30 ;
if ( V_4 -> V_41 ) {
V_45 |= V_56 << ( V_30 / 2 ) ;
F_23 ( V_28 , V_57 ,
& V_46 ) ;
V_46 |= ( V_58 << ( V_30 / 2 ) ) ;
F_24 ( V_28 , V_57 ,
V_46 ) ;
} else {
V_45 &= ~ ( V_56 << ( V_30 / 2 ) ) ;
}
F_24 ( V_28 , V_29 , V_45 ) ;
if ( V_4 -> V_54 )
F_25 ( V_4 -> V_54 ) ;
if ( V_44 == V_52 ) {
if ( F_26 ( V_4 -> V_7 . V_6 , & V_4 -> V_7 ) != 0 ) {
F_20 ( V_4 -> V_10 , L_18 ) ;
return - V_40 ;
}
}
return 0 ;
}
static int F_27 ( struct V_59 * V_60 )
{
struct V_61 * V_62 ;
struct V_63 V_64 ;
struct V_9 * V_10 = & V_60 -> V_10 ;
int V_31 ;
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_65 * V_66 ;
V_31 = F_28 ( V_60 , & V_64 ) ;
if ( V_31 )
return V_31 ;
V_62 = F_29 ( V_60 , & V_64 . V_67 ) ;
if ( F_10 ( V_62 ) )
return F_12 ( V_62 ) ;
V_4 = F_30 ( V_10 , sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 ) {
V_31 = - V_69 ;
goto V_70;
}
V_31 = F_7 ( V_4 , V_10 ) ;
if ( V_31 ) {
F_20 ( V_10 , L_19 ) ;
goto V_70;
}
V_62 -> V_71 = V_4 ;
V_62 -> V_72 = F_1 ;
V_31 = F_31 ( & V_60 -> V_10 , V_62 , & V_64 ) ;
if ( V_31 )
goto V_70;
V_12 = F_32 ( V_60 ) ;
V_66 = F_33 ( V_12 ) ;
V_4 -> V_54 = V_66 -> V_73 -> V_54 ;
V_31 = F_21 ( V_4 ) ;
if ( V_31 )
goto V_74;
return 0 ;
V_74:
F_34 ( & V_60 -> V_10 ) ;
V_70:
F_35 ( V_60 , V_62 ) ;
return V_31 ;
}
static int F_36 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_2 ( V_10 ) ;
struct V_65 * V_1 = F_33 ( V_12 ) ;
F_21 ( V_1 -> V_73 -> V_71 ) ;
if ( V_12 -> V_15 )
F_37 ( V_12 -> V_15 ) ;
return F_38 ( V_10 ) ;
}
