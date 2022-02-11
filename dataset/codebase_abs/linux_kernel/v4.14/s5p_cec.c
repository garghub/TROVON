static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 ) {
F_3 ( V_5 -> V_6 ) ;
F_4 ( V_5 ) ;
F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
F_9 ( V_5 ) ;
} else {
F_10 ( V_5 ) ;
F_11 ( V_5 ) ;
F_12 ( V_5 -> V_6 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_14 ( V_5 , V_7 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_8 ,
T_2 V_9 , struct V_10 * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_16 ( V_5 , V_11 -> V_11 , V_11 -> V_12 , F_17 ( 1 , V_8 - 1 ) ) ;
return 0 ;
}
static T_3 F_18 ( int V_13 , void * V_14 )
{
struct V_4 * V_5 = V_14 ;
T_2 V_15 = 0 ;
V_15 = F_19 ( V_5 ) ;
F_20 ( V_5 -> V_6 , L_1 ) ;
if ( V_15 & V_16 ) {
if ( V_15 & V_17 ) {
F_20 ( V_5 -> V_6 , L_2 ) ;
V_5 -> V_18 = V_19 ;
} else if ( V_15 & V_20 ) {
F_20 ( V_5 -> V_6 , L_3 ) ;
V_5 -> V_18 = V_21 ;
} else {
F_20 ( V_5 -> V_6 , L_4 ) ;
V_5 -> V_18 = V_22 ;
}
F_21 ( V_5 ) ;
}
if ( V_15 & V_23 ) {
if ( V_15 & V_24 ) {
F_20 ( V_5 -> V_6 , L_5 ) ;
F_22 ( V_5 ) ;
F_9 ( V_5 ) ;
} else {
F_20 ( V_5 -> V_6 , L_6 ) ;
if ( V_5 -> V_25 != V_26 )
F_20 ( V_5 -> V_6 , L_7 ) ;
V_5 -> V_25 = V_27 ;
V_5 -> V_11 . V_12 = V_15 >> 24 ;
V_5 -> V_11 . V_28 = V_29 ;
F_23 ( V_5 , V_5 -> V_11 . V_12 ,
V_5 -> V_11 . V_11 ) ;
V_5 -> V_25 = V_22 ;
F_9 ( V_5 ) ;
}
F_24 ( V_5 ) ;
}
return V_30 ;
}
static T_3 F_25 ( int V_13 , void * V_14 )
{
struct V_4 * V_5 = V_14 ;
F_20 ( V_5 -> V_6 , L_8 ) ;
switch ( V_5 -> V_18 ) {
case V_22 :
F_26 ( V_5 -> V_2 , V_31 , 0 , 0 , 0 , 0 ) ;
V_5 -> V_18 = V_26 ;
break;
case V_19 :
F_26 ( V_5 -> V_2 ,
V_32 | V_33 ,
0 , 1 , 0 , 0 ) ;
V_5 -> V_18 = V_26 ;
break;
case V_21 :
F_26 ( V_5 -> V_2 ,
V_32 | V_34 ,
0 , 0 , 0 , 1 ) ;
V_5 -> V_18 = V_26 ;
break;
case V_27 :
F_27 ( V_5 -> V_6 , L_9 ) ;
break;
default:
break;
}
switch ( V_5 -> V_25 ) {
case V_22 :
F_28 ( V_5 -> V_2 , & V_5 -> V_11 ) ;
V_5 -> V_25 = V_26 ;
break;
default:
break;
}
return V_35 ;
}
static int F_29 ( struct V_36 * V_37 )
{
struct V_38 * V_6 = & V_37 -> V_6 ;
struct V_39 * V_40 ;
struct V_36 * V_41 ;
struct V_42 * V_43 ;
struct V_4 * V_5 ;
bool V_44 = F_30 ( V_37 -> V_6 . V_45 , L_10 ) ;
int V_46 ;
V_40 = F_31 ( V_37 -> V_6 . V_45 , L_11 , 0 ) ;
if ( ! V_40 ) {
F_27 ( & V_37 -> V_6 , L_12 ) ;
return - V_47 ;
}
V_41 = F_32 ( V_40 ) ;
if ( V_41 == NULL )
return - V_48 ;
V_5 = F_33 ( & V_37 -> V_6 , sizeof( * V_5 ) , V_49 ) ;
if ( ! V_5 )
return - V_50 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_13 = F_34 ( V_37 , 0 ) ;
if ( V_5 -> V_13 < 0 )
return V_5 -> V_13 ;
V_46 = F_35 ( V_6 , V_5 -> V_13 , F_18 ,
F_25 , 0 , V_37 -> V_51 , V_5 ) ;
if ( V_46 )
return V_46 ;
V_5 -> V_52 = F_36 ( V_6 , L_13 ) ;
if ( F_37 ( V_5 -> V_52 ) )
return F_38 ( V_5 -> V_52 ) ;
V_5 -> V_53 = F_39 ( V_6 -> V_45 ,
L_14 ) ;
if ( F_37 ( V_5 -> V_53 ) )
return - V_48 ;
V_43 = F_40 ( V_37 , V_54 , 0 ) ;
V_5 -> V_55 = F_41 ( V_6 , V_43 ) ;
if ( F_37 ( V_5 -> V_55 ) )
return F_38 ( V_5 -> V_55 ) ;
V_5 -> V_56 = F_42 ( & V_41 -> V_6 ) ;
if ( V_5 -> V_56 == NULL )
return - V_50 ;
V_5 -> V_2 = F_43 ( & V_57 , V_5 , V_58 ,
V_59 | ( V_44 ? V_60 : 0 ) , 1 ) ;
V_46 = F_44 ( V_5 -> V_2 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_45 ( V_5 -> V_2 , & V_37 -> V_6 ) ;
if ( V_46 )
goto V_61;
F_46 ( V_5 -> V_2 , V_5 -> V_56 ) ;
F_47 ( V_37 , V_5 ) ;
F_48 ( V_6 ) ;
F_20 ( V_6 , L_15 ) ;
return 0 ;
V_61:
F_49 ( V_5 -> V_2 ) ;
return V_46 ;
}
static int F_50 ( struct V_36 * V_37 )
{
struct V_4 * V_5 = F_51 ( V_37 ) ;
F_52 ( V_5 -> V_2 ) ;
F_53 ( V_5 -> V_56 ) ;
F_12 ( & V_37 -> V_6 ) ;
return 0 ;
}
static int T_4 F_54 ( struct V_38 * V_6 )
{
struct V_4 * V_5 = F_55 ( V_6 ) ;
F_56 ( V_5 -> V_52 ) ;
return 0 ;
}
static int T_4 F_57 ( struct V_38 * V_6 )
{
struct V_4 * V_5 = F_55 ( V_6 ) ;
int V_46 ;
V_46 = F_58 ( V_5 -> V_52 ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
