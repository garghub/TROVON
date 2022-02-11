static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
if ( V_3 )
return - V_6 ;
switch ( V_4 ) {
case V_7 :
V_5 = F_2 ( V_2 , 0 , V_8 ) ;
break;
case V_9 :
V_5 = F_2 ( V_2 , 0 , V_10 ) ;
break;
case V_11 :
V_5 = F_2 ( V_2 , 0 ,
V_12 ) ;
break;
case V_13 :
case V_14 :
case V_15 :
V_5 = 0 ;
break;
default:
V_5 = - V_16 ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_17 )
{
int V_5 ;
switch ( V_4 ) {
case V_13 :
V_5 = F_4 ( V_2 , 0 , V_8 ,
0 ) ;
break;
case V_14 :
V_5 = F_4 ( V_2 , 0 , V_10 ,
0 ) ;
break;
case V_15 :
V_5 = F_4 ( V_2 , 0 ,
V_12 ,
0xffff ) ;
break;
default:
V_5 = - V_16 ;
break;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 = 0 ;
int V_18 ;
if ( V_3 )
return - V_6 ;
switch ( V_4 ) {
case V_19 :
V_18 = F_2 ( V_2 , 0 ,
V_20 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 & V_21 )
V_5 |= V_22 ;
if ( V_18 & V_23 )
V_5 |= V_24 ;
if ( V_18 & V_25 )
V_5 |= V_26 ;
if ( V_18 & V_27 )
V_5 |= V_28 ;
break;
case V_29 :
V_18 = F_2 ( V_2 , 0 ,
V_20 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 & V_30 )
V_5 |= V_31 ;
if ( V_18 & V_32 )
V_5 |= V_33 ;
if ( V_18 & V_34 )
V_5 |= V_35 ;
break;
case V_36 :
V_18 = F_2 ( V_2 , 0 ,
V_20 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 & V_37 )
V_5 |= V_38 ;
if ( V_18 & V_39 )
V_5 |= V_40 ;
break;
default:
V_5 = - V_16 ;
break;
}
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
return F_7 ( V_2 , V_42 , & V_43 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_44 ) ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_44 ) ;
}
