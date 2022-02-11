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
V_15 -> V_16 = & V_2 -> V_17 ;
return 0 ;
}
static void F_5 ( struct V_18 * V_19 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
if ( V_19 -> V_20 != V_21 )
return;
F_2 ( 0x0 , V_2 -> V_11 + V_13 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_22 )
{
T_1 V_3 = F_7 ( V_2 -> V_11 + V_12 ) ;
switch ( V_22 ) {
case V_23 :
V_3 |= V_24 ;
break;
case V_25 :
V_3 &= ~ V_24 ;
break;
}
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_26 * V_27 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
T_1 V_22 ;
if ( V_19 -> V_20 != V_21 )
return - V_28 ;
V_22 = F_9 ( V_27 ) ;
V_2 -> V_29 . V_22 = V_22 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 , int V_30 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
T_1 V_3 ;
int V_31 = 0 ;
if ( V_19 -> V_20 != V_21 )
return - V_28 ;
switch ( V_30 ) {
case V_32 :
case V_33 :
case V_34 :
F_11 ( V_2 -> V_35 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_2 -> V_29 . V_22 ) ;
V_3 = F_7 ( V_2 -> V_11 + V_12 ) ;
V_3 |= V_36 | V_37 ;
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0xF , V_2 -> V_11 + V_13 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
V_3 = F_7 ( V_2 -> V_11 + V_12 ) ;
V_3 &= ~ ( V_36 | V_37 ) ;
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0x0 , V_2 -> V_11 + V_13 ) ;
if ( V_2 -> V_41 )
V_2 -> V_41 () ;
F_12 ( V_2 -> V_35 ) ;
break;
default:
V_31 = - V_28 ;
break;
}
return V_31 ;
}
static T_2 F_13 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
T_1 V_44 = F_7 ( V_2 -> V_11 + V_45 ) ;
if ( ! V_44 )
return V_46 ;
if ( V_44 & V_47 )
F_14 ( V_2 -> V_48 , L_1 ) ;
if ( V_44 & V_49 )
F_14 ( V_2 -> V_48 , L_2 ) ;
if ( V_44 & V_50 )
F_14 ( V_2 -> V_48 , L_3 ) ;
if ( V_44 & V_51 )
F_14 ( V_2 -> V_48 , L_4 ) ;
F_2 ( 0 , V_2 -> V_11 + V_45 ) ;
return V_52 ;
}
static int F_15 ( struct V_53 * V_54 )
{
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_57 * V_58 , * V_59 ;
int V_31 ;
V_58 = F_16 ( V_54 , V_60 , 0 ) ;
if ( ! V_58 )
return - V_28 ;
V_59 = F_16 ( V_54 , V_61 , 0 ) ;
if ( ! V_59 )
return - V_28 ;
if ( ! F_17 ( & V_54 -> V_48 , V_58 -> V_62 ,
F_18 ( V_58 ) , V_54 -> V_63 ) ) {
F_19 ( & V_54 -> V_48 , L_5 ) ;
return - V_64 ;
}
V_2 = F_20 ( & V_54 -> V_48 , sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 ) {
F_19 ( & V_54 -> V_48 , L_6 ) ;
return - V_66 ;
}
V_2 -> V_11 = F_21 ( & V_54 -> V_48 , V_58 -> V_62 ,
F_18 ( V_58 ) ) ;
if ( ! V_2 -> V_11 ) {
F_19 ( & V_54 -> V_48 , L_7 ) ;
return - V_66 ;
}
V_2 -> V_42 = F_22 ( V_54 , 0 ) ;
if ( V_2 -> V_42 < 0 )
return - V_28 ;
V_2 -> V_35 = F_23 ( & V_54 -> V_48 , NULL ) ;
if ( F_24 ( V_2 -> V_35 ) )
return F_25 ( V_2 -> V_35 ) ;
V_56 = F_26 ( & V_54 -> V_48 ) ;
if ( ! V_56 )
return - V_28 ;
V_2 -> V_17 . V_67 = V_56 -> V_17 ;
V_2 -> V_17 . V_68 = V_59 -> V_62 ;
V_2 -> V_17 . V_69 = 16 ;
V_2 -> V_17 . V_70 = V_71 ;
V_2 -> V_17 . V_72 = V_56 -> V_72 ;
V_2 -> V_41 = V_56 -> V_41 ;
V_2 -> V_48 = & V_54 -> V_48 ;
F_27 ( & V_54 -> V_48 , V_2 ) ;
V_31 = F_28 ( & V_54 -> V_48 , V_2 -> V_42 , F_13 , 0 ,
L_8 , V_2 ) ;
if ( V_31 ) {
F_19 ( & V_54 -> V_48 , L_9 ) ;
return V_31 ;
}
return F_29 ( & V_54 -> V_48 , & V_73 ,
& V_74 , 1 ) ;
}
