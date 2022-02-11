static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 | V_5 | V_6 |
V_7 | V_8 ;
V_3 |= V_9 | V_10 ;
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0xF , V_2 -> V_11 + V_13 ) ;
}
static int F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
if ( V_15 -> V_18 != V_19 )
return - V_20 ;
F_5 ( V_17 , V_15 , ( void * ) & V_2 -> V_21 ) ;
return 0 ;
}
static void F_6 ( struct V_14 * V_15 ,
struct V_16 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
if ( V_15 -> V_18 != V_19 )
return;
F_2 ( 0x0 , V_2 -> V_11 + V_13 ) ;
F_5 ( V_22 , V_15 , NULL ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_23 )
{
T_1 V_3 = F_8 ( V_2 -> V_11 + V_12 ) ;
switch ( V_23 ) {
case V_24 :
V_3 |= V_25 ;
break;
case V_26 :
V_3 &= ~ V_25 ;
break;
}
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
}
static int F_9 ( struct V_14 * V_15 ,
struct V_27 * V_28 ,
struct V_16 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
T_1 V_23 ;
if ( V_15 -> V_18 != V_19 )
return - V_20 ;
V_23 = F_10 ( V_28 ) ;
V_2 -> V_29 . V_23 = V_23 ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 , int V_30 ,
struct V_16 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
T_1 V_3 ;
int V_31 = 0 ;
if ( V_15 -> V_18 != V_19 )
return - V_20 ;
switch ( V_30 ) {
case V_32 :
case V_33 :
case V_34 :
F_12 ( V_2 -> V_35 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 , V_2 -> V_29 . V_23 ) ;
V_3 = F_8 ( V_2 -> V_11 + V_12 ) ;
V_3 |= V_36 | V_37 ;
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0xF , V_2 -> V_11 + V_13 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
V_3 = F_8 ( V_2 -> V_11 + V_12 ) ;
V_3 &= ~ ( V_36 | V_37 ) ;
F_2 ( V_3 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0x0 , V_2 -> V_11 + V_13 ) ;
if ( V_2 -> V_41 )
V_2 -> V_41 () ;
F_13 ( V_2 -> V_35 ) ;
break;
default:
V_31 = - V_20 ;
break;
}
return V_31 ;
}
static T_2 F_14 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
T_1 V_44 = F_8 ( V_2 -> V_11 + V_45 ) ;
if ( ! V_44 )
return V_46 ;
if ( V_44 & V_47 )
F_15 ( V_2 -> V_48 , L_1 ) ;
if ( V_44 & V_49 )
F_15 ( V_2 -> V_48 , L_2 ) ;
if ( V_44 & V_50 )
F_15 ( V_2 -> V_48 , L_3 ) ;
if ( V_44 & V_51 )
F_15 ( V_2 -> V_48 , L_4 ) ;
F_2 ( 0 , V_2 -> V_11 + V_45 ) ;
return V_52 ;
}
static int F_16 ( struct V_53 * V_54 )
{
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_57 * V_58 , * V_59 ;
int V_31 ;
V_58 = F_17 ( V_54 , V_60 , 0 ) ;
if ( ! V_58 )
return - V_20 ;
V_59 = F_17 ( V_54 , V_61 , 0 ) ;
if ( ! V_59 )
return - V_20 ;
if ( ! F_18 ( & V_54 -> V_48 , V_58 -> V_62 ,
F_19 ( V_58 ) , V_54 -> V_63 ) ) {
F_20 ( & V_54 -> V_48 , L_5 ) ;
return - V_64 ;
}
V_2 = F_21 ( & V_54 -> V_48 , sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 ) {
F_20 ( & V_54 -> V_48 , L_6 ) ;
return - V_66 ;
}
V_2 -> V_11 = F_22 ( & V_54 -> V_48 , V_58 -> V_62 ,
F_19 ( V_58 ) ) ;
if ( ! V_2 -> V_11 ) {
F_20 ( & V_54 -> V_48 , L_7 ) ;
return - V_66 ;
}
V_2 -> V_42 = F_23 ( V_54 , 0 ) ;
if ( V_2 -> V_42 < 0 )
return - V_20 ;
V_2 -> V_35 = F_24 ( & V_54 -> V_48 , NULL ) ;
if ( F_25 ( V_2 -> V_35 ) )
return F_26 ( V_2 -> V_35 ) ;
V_56 = F_27 ( & V_54 -> V_48 ) ;
if ( ! V_56 )
return - V_20 ;
V_2 -> V_21 . V_67 = V_56 -> V_21 ;
V_2 -> V_21 . V_68 = V_59 -> V_62 ;
V_2 -> V_21 . V_69 = 16 ;
V_2 -> V_21 . V_70 = V_71 ;
V_2 -> V_21 . V_72 = V_56 -> V_72 ;
V_2 -> V_41 = V_56 -> V_41 ;
V_2 -> V_48 = & V_54 -> V_48 ;
F_28 ( & V_54 -> V_48 , V_2 ) ;
V_31 = F_29 ( & V_54 -> V_48 , V_2 -> V_42 , F_14 , 0 ,
L_8 , V_2 ) ;
if ( V_31 ) {
F_30 ( V_2 -> V_35 ) ;
F_20 ( & V_54 -> V_48 , L_9 ) ;
return V_31 ;
}
V_31 = F_31 ( & V_54 -> V_48 , & V_73 ) ;
if ( V_31 != 0 ) {
F_30 ( V_2 -> V_35 ) ;
return V_31 ;
}
return 0 ;
}
static int F_32 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_33 ( & V_54 -> V_48 ) ;
F_34 ( & V_54 -> V_48 ) ;
F_28 ( & V_54 -> V_48 , NULL ) ;
F_30 ( V_2 -> V_35 ) ;
return 0 ;
}
