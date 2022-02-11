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
} else {
F_20 ( V_5 -> V_6 , L_3 ) ;
V_5 -> V_18 = V_20 ;
}
F_21 ( V_5 ) ;
}
if ( V_15 & V_21 ) {
if ( V_15 & V_22 ) {
F_20 ( V_5 -> V_6 , L_4 ) ;
F_22 ( V_5 ) ;
F_9 ( V_5 ) ;
} else {
F_20 ( V_5 -> V_6 , L_5 ) ;
if ( V_5 -> V_23 != V_24 )
F_20 ( V_5 -> V_6 , L_6 ) ;
V_5 -> V_23 = V_25 ;
V_5 -> V_11 . V_12 = V_15 >> 24 ;
V_5 -> V_11 . V_26 = V_27 ;
F_23 ( V_5 , V_5 -> V_11 . V_12 ,
V_5 -> V_11 . V_11 ) ;
V_5 -> V_23 = V_20 ;
F_9 ( V_5 ) ;
}
F_24 ( V_5 ) ;
}
return V_28 ;
}
static T_3 F_25 ( int V_13 , void * V_14 )
{
struct V_4 * V_5 = V_14 ;
F_20 ( V_5 -> V_6 , L_7 ) ;
switch ( V_5 -> V_18 ) {
case V_20 :
F_26 ( V_5 -> V_2 , V_29 , 0 , 0 , 0 , 0 ) ;
V_5 -> V_18 = V_24 ;
break;
case V_19 :
F_26 ( V_5 -> V_2 ,
V_30 | V_31 ,
0 , 0 , 0 , 1 ) ;
V_5 -> V_18 = V_24 ;
break;
case V_25 :
F_27 ( V_5 -> V_6 , L_8 ) ;
break;
default:
break;
}
switch ( V_5 -> V_23 ) {
case V_20 :
F_28 ( V_5 -> V_2 , & V_5 -> V_11 ) ;
V_5 -> V_23 = V_24 ;
break;
default:
break;
}
return V_32 ;
}
static int F_29 ( struct V_33 * V_34 )
{
struct V_35 * V_6 = & V_34 -> V_6 ;
struct V_36 * V_37 ;
struct V_33 * V_38 ;
struct V_39 * V_40 ;
struct V_4 * V_5 ;
int V_41 ;
V_37 = F_30 ( V_34 -> V_6 . V_42 , L_9 , 0 ) ;
if ( ! V_37 ) {
F_27 ( & V_34 -> V_6 , L_10 ) ;
return - V_43 ;
}
V_38 = F_31 ( V_37 ) ;
if ( V_38 == NULL )
return - V_44 ;
V_5 = F_32 ( & V_34 -> V_6 , sizeof( * V_5 ) , V_45 ) ;
if ( ! V_5 )
return - V_46 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_13 = F_33 ( V_34 , 0 ) ;
if ( V_5 -> V_13 < 0 )
return V_5 -> V_13 ;
V_41 = F_34 ( V_6 , V_5 -> V_13 , F_18 ,
F_25 , 0 , V_34 -> V_47 , V_5 ) ;
if ( V_41 )
return V_41 ;
V_5 -> V_48 = F_35 ( V_6 , L_11 ) ;
if ( F_36 ( V_5 -> V_48 ) )
return F_37 ( V_5 -> V_48 ) ;
V_5 -> V_49 = F_38 ( V_6 -> V_42 ,
L_12 ) ;
if ( F_36 ( V_5 -> V_49 ) )
return - V_44 ;
V_40 = F_39 ( V_34 , V_50 , 0 ) ;
V_5 -> V_51 = F_40 ( V_6 , V_40 ) ;
if ( F_36 ( V_5 -> V_51 ) )
return F_37 ( V_5 -> V_51 ) ;
V_5 -> V_52 = F_41 ( & V_38 -> V_6 ) ;
if ( V_5 -> V_52 == NULL )
return - V_46 ;
V_5 -> V_2 = F_42 ( & V_53 , V_5 ,
V_54 ,
V_55 | V_56 |
V_57 | V_58 , 1 ) ;
V_41 = F_43 ( V_5 -> V_2 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_44 ( V_5 -> V_2 , & V_34 -> V_6 ) ;
if ( V_41 )
goto V_59;
F_45 ( V_5 -> V_2 , V_5 -> V_52 ) ;
F_46 ( V_34 , V_5 ) ;
F_47 ( V_6 ) ;
F_20 ( V_6 , L_13 ) ;
return 0 ;
V_59:
F_48 ( V_5 -> V_2 ) ;
return V_41 ;
}
static int F_49 ( struct V_33 * V_34 )
{
struct V_4 * V_5 = F_50 ( V_34 ) ;
F_51 ( V_5 -> V_2 ) ;
F_52 ( V_5 -> V_52 ) ;
F_12 ( & V_34 -> V_6 ) ;
return 0 ;
}
static int T_4 F_53 ( struct V_35 * V_6 )
{
struct V_4 * V_5 = F_54 ( V_6 ) ;
F_55 ( V_5 -> V_48 ) ;
return 0 ;
}
static int T_4 F_56 ( struct V_35 * V_6 )
{
struct V_4 * V_5 = F_54 ( V_6 ) ;
int V_41 ;
V_41 = F_57 ( V_5 -> V_48 ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
