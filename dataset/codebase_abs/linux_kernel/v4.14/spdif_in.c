static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 | V_5 | V_6 |
V_7 | V_8 ;
V_3 |= V_9 | V_10 ;
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0xF , V_2 -> V_11 + V_13 ) ;
}
static int F_3 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
V_2 -> V_16 . V_17 = & V_2 -> V_18 ;
V_15 -> V_19 = & V_2 -> V_16 ;
return 0 ;
}
static void F_5 ( struct V_20 * V_21 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
if ( V_21 -> V_22 != V_23 )
return;
F_2 ( 0x0 , V_2 -> V_11 + V_13 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_24 )
{
T_1 V_3 = F_7 ( V_2 -> V_11 + V_12 ) ;
switch ( V_24 ) {
case V_25 :
V_3 |= V_26 ;
break;
case V_27 :
V_3 &= ~ V_26 ;
break;
}
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
}
static int F_8 ( struct V_20 * V_21 ,
struct V_28 * V_29 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
T_1 V_24 ;
if ( V_21 -> V_22 != V_23 )
return - V_30 ;
V_24 = F_9 ( V_29 ) ;
V_2 -> V_31 . V_24 = V_24 ;
return 0 ;
}
static int F_10 ( struct V_20 * V_21 , int V_32 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
T_1 V_3 ;
int V_33 = 0 ;
if ( V_21 -> V_22 != V_23 )
return - V_30 ;
switch ( V_32 ) {
case V_34 :
case V_35 :
case V_36 :
F_11 ( V_2 -> V_37 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_2 -> V_31 . V_24 ) ;
V_3 = F_7 ( V_2 -> V_11 + V_12 ) ;
V_3 |= V_38 | V_39 ;
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0xF , V_2 -> V_11 + V_13 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
V_3 = F_7 ( V_2 -> V_11 + V_12 ) ;
V_3 &= ~ ( V_38 | V_39 ) ;
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0x0 , V_2 -> V_11 + V_13 ) ;
if ( V_2 -> V_43 )
V_2 -> V_43 () ;
F_12 ( V_2 -> V_37 ) ;
break;
default:
V_33 = - V_30 ;
break;
}
return V_33 ;
}
static T_2 F_13 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
T_1 V_46 = F_7 ( V_2 -> V_11 + V_47 ) ;
if ( ! V_46 )
return V_48 ;
if ( V_46 & V_49 )
F_14 ( V_2 -> V_50 , L_1 ) ;
if ( V_46 & V_51 )
F_14 ( V_2 -> V_50 , L_2 ) ;
if ( V_46 & V_52 )
F_14 ( V_2 -> V_50 , L_3 ) ;
if ( V_46 & V_53 )
F_14 ( V_2 -> V_50 , L_4 ) ;
F_2 ( 0 , V_2 -> V_11 + V_47 ) ;
return V_54 ;
}
static int F_15 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_57 * V_58 ;
struct V_59 * V_60 , * V_61 ;
void T_3 * V_11 ;
int V_33 ;
V_60 = F_16 ( V_56 , V_62 , 0 ) ;
V_11 = F_17 ( & V_56 -> V_50 , V_60 ) ;
if ( F_18 ( V_11 ) )
return F_19 ( V_11 ) ;
V_61 = F_16 ( V_56 , V_63 , 0 ) ;
if ( ! V_61 )
return - V_30 ;
V_2 = F_20 ( & V_56 -> V_50 , sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 )
return - V_65 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_44 = F_21 ( V_56 , 0 ) ;
if ( V_2 -> V_44 < 0 ) {
F_22 ( & V_56 -> V_50 , L_5 , V_2 -> V_44 ) ;
return V_2 -> V_44 ;
}
V_2 -> V_37 = F_23 ( & V_56 -> V_50 , NULL ) ;
if ( F_18 ( V_2 -> V_37 ) )
return F_19 ( V_2 -> V_37 ) ;
V_58 = F_24 ( & V_56 -> V_50 ) ;
if ( ! V_58 )
return - V_30 ;
V_2 -> V_18 . V_66 = V_58 -> V_18 ;
V_2 -> V_18 . V_67 = V_61 -> V_68 ;
V_2 -> V_18 . V_69 = 16 ;
V_2 -> V_18 . V_70 = V_71 ;
V_2 -> V_43 = V_58 -> V_43 ;
V_2 -> V_50 = & V_56 -> V_50 ;
F_25 ( & V_56 -> V_50 , V_2 ) ;
V_33 = F_26 ( & V_56 -> V_50 , V_2 -> V_44 , F_13 , 0 ,
L_6 , V_2 ) ;
if ( V_33 ) {
F_22 ( & V_56 -> V_50 , L_7 ) ;
return V_33 ;
}
V_33 = F_27 ( & V_56 -> V_50 , & V_72 ,
& V_73 , 1 ) ;
if ( V_33 )
return V_33 ;
return F_28 ( & V_56 -> V_50 , & V_2 -> V_74 ,
V_58 -> V_75 ) ;
}
