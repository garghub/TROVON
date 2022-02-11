static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
T_1 V_8 = 0 ;
if ( ( V_3 & V_9 ) != V_10 )
return - V_11 ;
switch ( V_3 & V_12 ) {
case V_13 :
V_8 |= V_14 ;
break;
case V_15 :
V_8 |= V_16 ;
break;
case V_17 :
V_8 |= V_18 ;
break;
case V_19 :
V_8 |= V_20 ;
break;
case V_21 :
V_8 |= V_22 ;
break;
default:
return - V_11 ;
}
switch ( V_3 & V_12 ) {
case V_13 :
case V_15 :
switch ( V_3 & V_23 ) {
case V_24 :
break;
case V_25 :
V_8 |= V_26 ;
break;
default:
return - V_11 ;
}
break;
case V_17 :
case V_19 :
case V_21 :
switch ( V_3 & V_23 ) {
case V_24 :
break;
case V_27 :
V_8 |= V_26 |
V_28 ;
break;
case V_25 :
V_8 |= V_26 ;
break;
case V_29 :
V_8 |= V_28 ;
break;
default:
return - V_11 ;
}
break;
default:
return - V_11 ;
}
F_3 ( V_5 ) ;
V_7 = F_4 ( V_2 -> V_30 , V_31 ,
V_32 ,
V_8 ) ;
F_5 ( V_5 ) ;
if ( V_7 < 0 ) {
F_6 ( V_2 -> V_30 -> V_6 , L_1 ) ;
return V_7 ;
}
return 0 ;
}
static int F_7 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_4 * V_5 = F_2 ( V_37 -> V_6 ) ;
int V_38 , V_39 , V_7 ;
V_38 = F_8 ( V_36 ) ;
if ( V_38 < 32000 || V_38 > 48000 ) {
F_6 ( V_37 -> V_30 -> V_6 , L_2 , V_38 ) ;
return - V_11 ;
}
switch ( F_9 ( V_36 ) ) {
case V_40 :
V_39 = V_41 ;
break;
case V_42 :
V_39 = V_43 ;
break;
case V_44 :
V_39 = V_45 ;
break;
case V_46 :
V_39 = V_47 ;
break;
default:
return - V_11 ;
}
F_3 ( V_5 ) ;
V_7 = F_10 ( V_37 -> V_30 , V_48 ,
V_38 ) ;
if ( V_7 < 0 ) {
F_6 ( V_37 -> V_30 -> V_6 , L_3 ) ;
goto V_49;
}
V_7 = F_4 ( V_37 -> V_30 , V_31 ,
V_50 ,
( V_39 << V_51 ) |
( V_39 << V_52 ) ) ;
if ( V_7 < 0 ) {
F_6 ( V_37 -> V_30 -> V_6 , L_4 ) ;
goto V_49;
}
V_49:
F_5 ( V_5 ) ;
return V_7 ;
}
static int F_11 ( struct V_53 * V_30 )
{
V_30 -> V_54 = F_12 ( V_30 -> V_6 -> V_55 , NULL ) ;
return 0 ;
}
static int F_13 ( struct V_56 * V_57 )
{
return F_14 ( & V_57 -> V_6 , & V_58 ,
& V_59 , 1 ) ;
}
static int F_15 ( struct V_56 * V_57 )
{
F_16 ( & V_57 -> V_6 ) ;
return 0 ;
}
