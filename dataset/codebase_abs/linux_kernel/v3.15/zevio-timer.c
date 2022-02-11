static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 ,
V_6 ) ;
F_3 ( V_1 , V_5 -> V_7 + V_8 ) ;
F_3 ( V_9 | V_10 | F_4 ( V_11 ) ,
V_5 -> V_7 + V_12 ) ;
return 0 ;
}
static void F_5 ( enum V_13 V_14 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 ,
V_6 ) ;
switch ( V_14 ) {
case V_15 :
case V_16 :
F_3 ( V_17 , V_5 -> V_18 + V_19 ) ;
F_3 ( V_20 , V_5 -> V_18 + V_21 ) ;
break;
case V_22 :
case V_23 :
F_3 ( 0 , V_5 -> V_18 + V_19 ) ;
F_3 ( V_20 , V_5 -> V_18 + V_21 ) ;
F_3 ( V_24 , V_5 -> V_7 + V_12 ) ;
break;
case V_25 :
default:
break;
}
}
static T_1 F_6 ( int V_26 , void * V_27 )
{
struct V_4 * V_5 = V_27 ;
T_2 V_28 ;
V_28 = F_7 ( V_5 -> V_18 + V_21 ) ;
if ( ! ( V_28 & V_17 ) )
return V_29 ;
F_3 ( V_17 , V_5 -> V_18 + V_21 ) ;
F_3 ( V_24 , V_5 -> V_7 + V_12 ) ;
if ( V_5 -> V_6 . V_30 )
V_5 -> V_6 . V_30 ( & V_5 -> V_6 ) ;
return V_31 ;
}
static int T_3 F_8 ( struct V_32 * V_33 )
{
struct V_4 * V_5 ;
struct V_34 V_35 ;
int V_36 , V_37 ;
V_5 = F_9 ( sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 )
return - V_39 ;
V_5 -> V_40 = F_10 ( V_33 , 0 ) ;
if ( ! V_5 -> V_40 ) {
V_37 = - V_41 ;
goto V_42;
}
V_5 -> V_7 = V_5 -> V_40 + V_43 ;
V_5 -> V_44 = V_5 -> V_40 + V_45 ;
V_5 -> V_46 = F_11 ( V_33 , 0 ) ;
if ( F_12 ( V_5 -> V_46 ) ) {
V_37 = F_13 ( V_5 -> V_46 ) ;
F_14 ( L_1 , V_37 ) ;
goto V_47;
}
V_5 -> V_18 = F_10 ( V_33 , 1 ) ;
V_36 = F_15 ( V_33 , 0 ) ;
F_16 ( V_33 , 0 , & V_35 ) ;
F_17 ( V_5 -> V_48 , sizeof( V_5 -> V_48 ) ,
L_2 ,
( unsigned long long ) V_35 . V_49 , V_33 -> V_50 ) ;
F_17 ( V_5 -> V_51 , sizeof( V_5 -> V_51 ) ,
L_3 ,
( unsigned long long ) V_35 . V_49 , V_33 -> V_50 ) ;
if ( V_5 -> V_18 && V_36 ) {
V_5 -> V_6 . V_50 = V_5 -> V_51 ;
V_5 -> V_6 . V_52 = F_1 ;
V_5 -> V_6 . V_53 = F_5 ;
V_5 -> V_6 . V_54 = 200 ;
V_5 -> V_6 . V_55 = V_56 ;
V_5 -> V_6 . V_57 = V_58 ;
V_5 -> V_6 . V_26 = V_36 ;
F_3 ( V_24 , V_5 -> V_7 + V_12 ) ;
F_3 ( 0 , V_5 -> V_7 + V_59 ) ;
F_3 ( 0 , V_5 -> V_18 + V_19 ) ;
F_3 ( V_20 , V_5 -> V_18 + V_21 ) ;
F_3 ( 0 , V_5 -> V_40 + F_18 ( V_11 ) ) ;
V_5 -> V_60 . V_50 = V_5 -> V_51 ;
V_5 -> V_60 . V_61 = F_6 ;
V_5 -> V_60 . V_27 = V_5 ;
V_5 -> V_60 . V_62 = V_63 | V_64 ;
F_19 ( V_36 , & V_5 -> V_60 ) ;
F_20 ( & V_5 -> V_6 ,
F_21 ( V_5 -> V_46 ) , 0x0001 , 0xffff ) ;
F_22 ( L_4 , V_5 -> V_51 ) ;
}
F_3 ( V_24 , V_5 -> V_44 + V_12 ) ;
F_3 ( 0 , V_5 -> V_44 + V_8 ) ;
F_3 ( 0 , V_5 -> V_44 + V_59 ) ;
F_3 ( V_9 | V_65 | V_66 ,
V_5 -> V_44 + V_12 ) ;
F_23 ( V_5 -> V_44 + V_8 ,
V_5 -> V_48 ,
F_21 ( V_5 -> V_46 ) ,
200 , 16 ,
V_67 ) ;
F_22 ( L_5 , V_5 -> V_48 ) ;
return 0 ;
V_47:
F_24 ( V_5 -> V_40 ) ;
V_42:
F_25 ( V_5 ) ;
return V_37 ;
}
static void T_3 F_26 ( struct V_32 * V_33 )
{
F_27 ( F_8 ( V_33 ) ) ;
}
