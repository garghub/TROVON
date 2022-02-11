static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 ) {
F_2 ( V_5 -> V_7 ) ;
F_3 ( V_5 ) ;
F_4 ( V_5 ) ;
F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
} else {
F_9 ( V_5 ) ;
F_10 ( V_5 ) ;
F_11 ( V_5 -> V_7 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_13 ( V_5 , V_8 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_9 ,
T_2 V_10 , struct V_11 * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_15 ( V_5 , V_12 -> V_12 , V_12 -> V_13 , F_16 ( 1 , V_9 - 1 ) ) ;
return 0 ;
}
static T_3 F_17 ( int V_14 , void * V_6 )
{
struct V_4 * V_5 = V_6 ;
T_2 V_15 = 0 ;
V_15 = F_18 ( V_5 ) ;
F_19 ( V_5 -> V_7 , L_1 ) ;
if ( V_15 & V_16 ) {
if ( V_15 & V_17 ) {
F_19 ( V_5 -> V_7 , L_2 ) ;
V_5 -> V_18 = V_19 ;
} else {
F_19 ( V_5 -> V_7 , L_3 ) ;
V_5 -> V_18 = V_20 ;
}
F_20 ( V_5 ) ;
}
if ( V_15 & V_21 ) {
if ( V_15 & V_22 ) {
F_19 ( V_5 -> V_7 , L_4 ) ;
F_21 ( V_5 ) ;
F_8 ( V_5 ) ;
} else {
F_19 ( V_5 -> V_7 , L_5 ) ;
if ( V_5 -> V_23 != V_24 )
F_19 ( V_5 -> V_7 , L_6 ) ;
V_5 -> V_23 = V_25 ;
V_5 -> V_12 . V_13 = V_15 >> 24 ;
V_5 -> V_12 . V_26 = V_27 ;
F_22 ( V_5 , V_5 -> V_12 . V_13 ,
V_5 -> V_12 . V_12 ) ;
V_5 -> V_23 = V_20 ;
F_8 ( V_5 ) ;
}
F_23 ( V_5 ) ;
}
return V_28 ;
}
static T_3 F_24 ( int V_14 , void * V_6 )
{
struct V_4 * V_5 = V_6 ;
F_19 ( V_5 -> V_7 , L_7 ) ;
switch ( V_5 -> V_18 ) {
case V_20 :
F_25 ( V_5 -> V_2 , V_29 , 0 , 0 , 0 , 0 ) ;
V_5 -> V_18 = V_24 ;
break;
case V_19 :
F_25 ( V_5 -> V_2 ,
V_30 | V_31 ,
0 , 0 , 0 , 1 ) ;
V_5 -> V_18 = V_24 ;
break;
case V_25 :
F_26 ( V_5 -> V_7 , L_8 ) ;
break;
default:
break;
}
switch ( V_5 -> V_23 ) {
case V_20 :
F_27 ( V_5 -> V_2 , & V_5 -> V_12 ) ;
V_5 -> V_23 = V_24 ;
break;
default:
break;
}
return V_32 ;
}
static int F_28 ( struct V_33 * V_34 )
{
struct V_35 * V_7 = & V_34 -> V_7 ;
struct V_36 * V_37 ;
struct V_4 * V_5 ;
int V_38 ;
V_5 = F_29 ( & V_34 -> V_7 , sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 )
return - V_40 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_14 = F_30 ( V_34 , 0 ) ;
if ( V_5 -> V_14 < 0 )
return V_5 -> V_14 ;
V_38 = F_31 ( V_7 , V_5 -> V_14 , F_17 ,
F_24 , 0 , V_34 -> V_41 , V_5 ) ;
if ( V_38 )
return V_38 ;
V_5 -> V_42 = F_32 ( V_7 , L_9 ) ;
if ( F_33 ( V_5 -> V_42 ) )
return F_34 ( V_5 -> V_42 ) ;
V_5 -> V_43 = F_35 ( V_7 -> V_44 ,
L_10 ) ;
if ( F_33 ( V_5 -> V_43 ) )
return - V_45 ;
V_37 = F_36 ( V_34 , V_46 , 0 ) ;
V_5 -> V_47 = F_37 ( V_7 , V_37 ) ;
if ( F_33 ( V_5 -> V_47 ) )
return F_34 ( V_5 -> V_47 ) ;
V_5 -> V_2 = F_38 ( & V_48 , V_5 ,
V_49 ,
V_50 | V_51 | V_52 |
V_53 | V_54 , 1 ) ;
V_38 = F_39 ( V_5 -> V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_40 ( V_5 -> V_2 , & V_34 -> V_7 ) ;
if ( V_38 ) {
F_41 ( V_5 -> V_2 ) ;
return V_38 ;
}
F_42 ( V_34 , V_5 ) ;
F_43 ( V_7 ) ;
F_19 ( V_7 , L_11 ) ;
return 0 ;
}
static int F_44 ( struct V_33 * V_34 )
{
struct V_4 * V_5 = F_45 ( V_34 ) ;
F_46 ( V_5 -> V_2 ) ;
F_11 ( & V_34 -> V_7 ) ;
return 0 ;
}
static int T_4 F_47 ( struct V_35 * V_7 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
F_49 ( V_5 -> V_42 ) ;
return 0 ;
}
static int T_4 F_50 ( struct V_35 * V_7 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
int V_38 ;
V_38 = F_51 ( V_5 -> V_42 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
