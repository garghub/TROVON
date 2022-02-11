static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_3 ;
int V_6 = V_7 ;
T_1 V_8 ;
F_2 ( V_4 , V_9 , & V_8 ) ;
if ( ( V_8 & V_10 ) == 0 )
goto V_11;
F_2 ( V_4 , V_12 , & V_8 ) ;
if ( V_8 & V_13 ) {
if ( V_8 & V_14 )
V_6 = V_15 ;
else
V_6 = V_16 ;
goto V_11;
}
V_11:
V_2 -> V_17 = V_6 ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) == V_16 )
return V_18 ;
return V_19 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_3 ;
T_1 V_8 ;
F_2 ( V_4 , V_20 , & V_8 ) ;
V_8 = ( ( V_8 & V_21 ) >> V_22 ) ;
switch ( V_8 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
return 1 ;
case V_28 :
case V_29 :
case V_30 :
default:
return 0 ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_3 ;
int V_6 = V_31 ;
T_1 V_8 ;
F_2 ( V_4 , V_20 , & V_8 ) ;
V_8 = ( ( V_8 & V_21 ) >> V_22 ) ;
if ( V_8 == V_27 ) {
V_6 = V_32 ;
goto V_11;
}
F_2 ( V_4 , V_12 , & V_8 ) ;
if ( V_8 & V_33 ) {
V_6 = V_34 ;
goto V_11;
}
V_11:
V_2 -> V_35 = V_6 ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_3 ;
T_1 V_8 ;
V_8 = 0x1 << V_36 ;
F_8 ( V_4 , V_37 ,
V_38 | V_39 ,
V_8 ) ;
V_8 = 0x3 << V_40 ;
F_9 ( V_4 , V_41 , V_8 ) ;
V_8 = 0x1 << V_42 ;
V_8 |= 0x1 << V_43 ;
F_9 ( V_4 , V_44 , V_8 ) ;
V_8 = 0xf << V_45 ;
F_9 ( V_4 , V_46 , V_8 ) ;
V_8 = 0x1 << V_47 ;
V_8 |= 0x5 << V_48 ;
F_9 ( V_4 , V_49 , V_8 ) ;
V_8 = 0x0 << V_50 ;
F_9 ( V_4 , V_51 , V_8 ) ;
V_8 = 0x0 << V_52 ;
F_9 ( V_4 , V_53 , V_8 ) ;
V_8 = 0x2 << V_54 ;
F_9 ( V_4 , V_55 , V_8 ) ;
}
static int F_10 ( struct V_56 * V_57 ,
enum V_58 V_59 ,
union V_60 * V_61 )
{
struct V_1 * V_2 = F_11 ( V_57 ,
struct V_1 ,
V_62 ) ;
int V_63 = 0 ;
switch ( V_59 ) {
case V_64 :
V_61 -> V_65 = F_1 ( V_2 ) ;
break;
case V_66 :
V_61 -> V_65 = F_3 ( V_2 ) ;
break;
case V_67 :
V_61 -> V_65 = F_5 ( V_2 ) ;
break;
case V_68 :
V_61 -> V_65 = F_6 ( V_2 ) ;
break;
case V_69 :
V_61 -> V_65 = F_4 ( V_2 ) ;
break;
case V_70 :
V_61 -> V_71 = V_72 ;
break;
case V_73 :
V_61 -> V_71 = V_74 ;
break;
default:
return - V_75 ;
}
return V_63 ;
}
static int F_12 ( struct V_76 * V_77 )
{
struct V_1 * V_2 ;
struct V_5 * V_5 = F_13 ( V_77 -> V_78 . V_79 ) ;
int V_63 ;
V_2 = F_14 ( & V_77 -> V_78 , sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 )
return - V_81 ;
F_15 ( V_77 , V_2 ) ;
V_2 -> V_78 = & V_77 -> V_78 ;
V_2 -> V_5 = V_5 ;
F_7 ( V_2 ) ;
V_2 -> V_62 . V_82 = L_1 ,
V_2 -> V_62 . type = V_83 ,
V_2 -> V_62 . V_84 = V_85 ,
V_2 -> V_62 . V_86 = F_16 ( V_85 ) ,
V_2 -> V_62 . V_87 = F_10 ,
V_63 = F_17 ( & V_77 -> V_78 , & V_2 -> V_62 ) ;
if ( V_63 ) {
F_18 ( & V_77 -> V_78 , L_2 ) ;
return V_63 ;
}
return 0 ;
}
static int F_19 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_20 ( V_77 ) ;
F_21 ( & V_2 -> V_62 ) ;
return 0 ;
}
