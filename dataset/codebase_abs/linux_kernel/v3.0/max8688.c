static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 = 0 ;
int V_6 ;
if ( V_3 )
return - V_7 ;
switch ( V_4 ) {
case V_8 :
V_6 = F_2 ( V_2 , 0 ,
V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 & V_10 )
V_5 |= V_11 ;
if ( V_6 & V_12 )
V_5 |= V_13 ;
if ( V_6 & V_14 )
V_5 |= V_15 ;
if ( V_6 & V_16 )
V_5 |= V_17 ;
break;
case V_18 :
V_6 = F_2 ( V_2 , 0 ,
V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 & V_19 )
V_5 |= V_20 ;
if ( V_6 & V_21 )
V_5 |= V_22 ;
if ( V_6 & V_23 )
V_5 |= V_24 ;
break;
case V_25 :
V_6 = F_2 ( V_2 , 0 ,
V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 & V_26 )
V_5 |= V_27 ;
if ( V_6 & V_28 )
V_5 |= V_29 ;
break;
default:
V_5 = - V_30 ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
return F_4 ( V_2 , V_32 , & V_33 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 ) ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_34 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_34 ) ;
}
