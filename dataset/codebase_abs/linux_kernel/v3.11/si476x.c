static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 ;
unsigned int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_2 ( V_7 ) ;
if ( ! F_3 ( V_7 ) )
F_4 ( V_7 -> V_9 , true ) ;
V_4 = F_5 ( V_7 -> V_9 , V_3 , & V_5 ) ;
if ( ! F_3 ( V_7 ) )
F_4 ( V_7 -> V_9 , false ) ;
F_6 ( V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_5 )
{
int V_4 ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_2 ( V_7 ) ;
if ( ! F_3 ( V_7 ) )
F_4 ( V_7 -> V_9 , true ) ;
V_4 = F_8 ( V_7 -> V_9 , V_3 , V_5 ) ;
if ( ! F_3 ( V_7 ) )
F_4 ( V_7 -> V_9 , false ) ;
F_6 ( V_7 ) ;
return V_4 ;
}
static int F_9 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
int V_4 ;
T_1 V_13 = 0 ;
if ( ( V_12 & V_14 ) != V_15 )
return - V_16 ;
switch ( V_12 & V_17 ) {
case V_18 :
V_13 |= V_19 ;
break;
case V_20 :
V_13 |= V_21 ;
break;
case V_22 :
V_13 |= V_23 ;
break;
case V_24 :
V_13 |= V_25 ;
break;
case V_26 :
V_13 |= V_27 ;
break;
default:
return - V_16 ;
}
switch ( V_12 & V_17 ) {
case V_18 :
case V_20 :
switch ( V_12 & V_28 ) {
case V_29 :
break;
case V_30 :
V_13 |= V_31 ;
break;
default:
return - V_16 ;
}
break;
case V_22 :
case V_24 :
case V_26 :
switch ( V_12 & V_28 ) {
case V_29 :
break;
case V_32 :
V_13 |= V_31 |
V_33 ;
break;
case V_30 :
V_13 |= V_31 ;
break;
case V_34 :
V_13 |= V_33 ;
break;
default:
return - V_16 ;
}
break;
default:
return - V_16 ;
}
V_4 = F_10 ( V_11 -> V_2 , V_35 ,
V_36 ,
V_13 ) ;
if ( V_4 < 0 ) {
F_11 ( V_11 -> V_2 -> V_37 , L_1 ) ;
return V_4 ;
}
return 0 ;
}
static int F_12 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_10 * V_42 )
{
int V_43 , V_44 , V_4 ;
V_43 = F_13 ( V_41 ) ;
if ( V_43 < 32000 || V_43 > 48000 ) {
F_11 ( V_42 -> V_2 -> V_37 , L_2 , V_43 ) ;
return - V_16 ;
}
switch ( F_14 ( V_41 ) ) {
case V_45 :
V_44 = V_46 ;
break;
case V_47 :
V_44 = V_48 ;
break;
case V_49 :
V_44 = V_50 ;
break;
case V_51 :
V_44 = V_52 ;
break;
default:
return - V_16 ;
}
V_4 = F_15 ( V_42 -> V_2 , V_53 ,
V_43 ) ;
if ( V_4 < 0 ) {
F_11 ( V_42 -> V_2 -> V_37 , L_3 ) ;
return V_4 ;
}
V_4 = F_10 ( V_42 -> V_2 , V_35 ,
V_54 ,
( V_44 << V_55 ) |
( V_44 << V_56 ) ) ;
if ( V_4 < 0 ) {
F_11 ( V_42 -> V_2 -> V_37 , L_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
V_2 -> V_8 = F_17 ( V_2 -> V_37 ) ;
return 0 ;
}
static int F_18 ( struct V_57 * V_58 )
{
return F_19 ( & V_58 -> V_37 , & V_59 ,
& V_60 , 1 ) ;
}
static int F_20 ( struct V_57 * V_58 )
{
F_21 ( & V_58 -> V_37 ) ;
return 0 ;
}
