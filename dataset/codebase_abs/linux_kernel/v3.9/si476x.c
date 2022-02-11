static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_6 ) ;
V_4 = F_3 ( V_6 , V_3 ) ;
F_4 ( V_6 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_6 ) ;
V_4 = F_6 ( V_6 , V_3 , V_8 ) ;
F_4 ( V_6 ) ;
return V_4 ;
}
static int F_7 ( struct V_9 * V_10 ,
unsigned int V_11 )
{
int V_4 ;
T_1 V_12 = 0 ;
if ( ( V_11 & V_13 ) != V_14 )
return - V_15 ;
switch ( V_11 & V_16 ) {
case V_17 :
V_12 |= V_18 ;
break;
case V_19 :
V_12 |= V_20 ;
break;
case V_21 :
V_12 |= V_22 ;
break;
case V_23 :
V_12 |= V_24 ;
break;
case V_25 :
V_12 |= V_26 ;
break;
default:
return - V_15 ;
}
switch ( V_11 & V_16 ) {
case V_17 :
case V_19 :
switch ( V_11 & V_27 ) {
case V_28 :
break;
case V_29 :
V_12 |= V_30 ;
break;
default:
return - V_15 ;
}
break;
case V_21 :
case V_23 :
case V_25 :
switch ( V_11 & V_27 ) {
case V_28 :
break;
case V_31 :
V_12 |= V_30 |
V_32 ;
break;
case V_29 :
V_12 |= V_30 ;
break;
case V_33 :
V_12 |= V_32 ;
break;
default:
return - V_15 ;
}
break;
default:
return - V_15 ;
}
V_4 = F_8 ( V_10 -> V_2 , V_34 ,
V_35 ,
V_12 ) ;
if ( V_4 < 0 ) {
F_9 ( V_10 -> V_2 -> V_36 , L_1 ) ;
return V_4 ;
}
return 0 ;
}
static int F_10 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_9 * V_41 )
{
int V_42 , V_43 , V_4 ;
V_42 = F_11 ( V_40 ) ;
if ( V_42 < 32000 || V_42 > 48000 ) {
F_9 ( V_41 -> V_2 -> V_36 , L_2 , V_42 ) ;
return - V_15 ;
}
switch ( F_12 ( V_40 ) ) {
case V_44 :
V_43 = V_45 ;
break;
case V_46 :
V_43 = V_47 ;
break;
case V_48 :
V_43 = V_49 ;
break;
case V_50 :
V_43 = V_51 ;
break;
default:
return - V_15 ;
}
V_4 = F_13 ( V_41 -> V_2 , V_52 ,
V_42 ) ;
if ( V_4 < 0 ) {
F_9 ( V_41 -> V_2 -> V_36 , L_3 ) ;
return V_4 ;
}
V_4 = F_8 ( V_41 -> V_2 , V_34 ,
V_53 ,
( V_43 << V_54 ) |
( V_43 << V_55 ) ) ;
if ( V_4 < 0 ) {
F_9 ( V_41 -> V_2 -> V_36 , L_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
V_2 -> V_7 = F_15 ( V_2 -> V_36 ) ;
return 0 ;
}
static int F_16 ( struct V_56 * V_57 )
{
return F_17 ( & V_57 -> V_36 , & V_58 ,
& V_59 , 1 ) ;
}
static int F_18 ( struct V_56 * V_57 )
{
F_19 ( & V_57 -> V_36 ) ;
return 0 ;
}
