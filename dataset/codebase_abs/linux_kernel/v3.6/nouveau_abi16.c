int
F_1 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 ;
struct V_5 * V_6 = V_7 ;
switch ( V_6 -> V_8 ) {
case V_9 :
V_6 -> V_10 = V_2 -> V_11 ;
break;
case V_12 :
V_6 -> V_10 = V_3 -> V_13 ;
break;
case V_14 :
V_6 -> V_10 = V_3 -> V_15 ;
break;
case V_16 :
if ( F_2 ( V_3 ) )
V_6 -> V_10 = 0 ;
else
if ( ! F_3 ( V_3 -> V_17 ) )
V_6 -> V_10 = 1 ;
else
V_6 -> V_10 = 2 ;
break;
case V_18 :
V_6 -> V_10 = V_2 -> V_19 ;
break;
case V_20 :
V_6 -> V_10 = V_2 -> V_21 . V_22 ;
break;
case V_23 :
V_6 -> V_10 = 0 ;
break;
case V_24 :
V_6 -> V_10 = V_2 -> V_25 . V_26 . V_27 ( V_3 ) ;
break;
case V_28 :
V_6 -> V_10 = 1 ;
break;
case V_29 :
V_6 -> V_10 = 1 ;
break;
case V_30 :
if ( V_2 -> V_11 >= 0x40 ) {
V_6 -> V_10 = F_4 ( V_3 , V_31 ) ;
break;
}
default:
F_5 ( V_3 , L_1 , V_6 -> V_8 ) ;
return - V_32 ;
}
return 0 ;
}
int
F_6 ( T_1 )
{
return - V_32 ;
}
int
F_7 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 ;
struct V_33 * V_34 = V_7 ;
struct V_35 * V_36 ;
int V_37 ;
if ( ! V_2 -> V_38 [ V_39 ] )
return - V_40 ;
if ( V_34 -> V_41 == ~ 0 || V_34 -> V_42 == ~ 0 )
return - V_32 ;
V_37 = F_8 ( V_3 , & V_36 , V_43 ,
V_34 -> V_41 ,
V_34 -> V_42 ) ;
if ( V_37 )
return V_37 ;
V_34 -> V_44 = V_36 -> V_45 ;
if ( V_46 == 0 ) {
if ( V_36 -> V_47 . V_48 )
V_34 -> V_49 = V_50 |
V_51 ;
else if ( V_36 -> V_52 -> V_53 . V_54 . V_55 == V_56 )
V_34 -> V_49 = V_50 ;
else
V_34 -> V_49 = V_51 ;
} else {
V_34 -> V_49 = V_50 ;
}
if ( V_2 -> V_57 < V_58 ) {
V_34 -> V_59 [ 0 ] . V_60 = 0x00000000 ;
V_34 -> V_59 [ 0 ] . V_61 = 0x0000 ;
V_34 -> V_59 [ 1 ] . V_60 = V_62 ;
V_34 -> V_59 [ 1 ] . V_61 = V_63 ;
V_34 -> V_64 = 2 ;
}
V_37 = F_9 ( V_43 , V_36 -> V_65 -> V_66 ,
& V_34 -> V_67 ) ;
if ( V_37 == 0 )
F_10 ( & V_36 -> V_68 ) ;
F_11 ( & V_36 ) ;
return V_37 ;
}
int
F_12 ( T_1 )
{
struct V_69 * V_70 = V_7 ;
struct V_35 * V_36 ;
V_36 = F_13 ( V_43 , V_70 -> V_44 ) ;
if ( F_14 ( V_36 ) )
return F_15 ( V_36 ) ;
F_16 ( & V_36 -> V_71 ) ;
F_17 ( & V_36 -> V_68 ) ;
F_11 ( & V_36 ) ;
return 0 ;
}
int
F_18 ( T_1 )
{
struct V_72 * V_34 = V_7 ;
struct V_35 * V_36 ;
int V_37 ;
if ( V_34 -> V_60 == ~ 0 )
return - V_32 ;
if ( V_34 -> V_73 == 0x506e ) {
V_34 -> V_73 = F_19 ( V_3 ) ;
if ( V_34 -> V_73 == 0x906e )
return 0 ;
} else
if ( V_34 -> V_73 == 0x906e ) {
F_5 ( V_3 , L_2 ) ;
return - V_32 ;
}
V_36 = F_13 ( V_43 , V_34 -> V_44 ) ;
if ( F_14 ( V_36 ) )
return F_15 ( V_36 ) ;
if ( F_20 ( V_36 , V_34 -> V_60 ) ) {
V_37 = - V_74 ;
goto V_75;
}
V_37 = F_21 ( V_36 , V_34 -> V_60 , V_34 -> V_73 ) ;
if ( V_37 ) {
F_22 ( V_3 , L_3 ,
V_37 , V_34 -> V_44 , V_34 -> V_60 ) ;
}
V_75:
F_11 ( & V_36 ) ;
return V_37 ;
}
int
F_23 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 ;
struct V_76 * V_77 = V_7 ;
struct V_35 * V_36 ;
int V_37 ;
if ( F_24 ( V_2 -> V_57 >= V_58 ) )
return - V_32 ;
V_36 = F_13 ( V_43 , V_77 -> V_44 ) ;
if ( F_14 ( V_36 ) )
return F_15 ( V_36 ) ;
V_37 = F_25 ( V_36 , V_77 -> V_60 , V_77 -> V_78 , 0 , 0x1000 ,
& V_77 -> V_79 ) ;
F_11 ( & V_36 ) ;
return V_37 ;
}
int
F_26 ( T_1 )
{
struct V_80 * V_81 = V_7 ;
struct V_35 * V_36 ;
int V_37 ;
V_36 = F_13 ( V_43 , V_81 -> V_44 ) ;
if ( F_14 ( V_36 ) )
return F_15 ( V_36 ) ;
F_27 ( V_36 ) ;
V_37 = F_28 ( V_36 , V_81 -> V_60 ) ;
F_11 ( & V_36 ) ;
return V_37 ;
}
