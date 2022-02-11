static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( V_4 ) {
case V_7 :
V_6 = F_3 ( V_2 , 0 ,
V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 & V_9 )
V_5 |= V_10 ;
if ( V_6 & V_11 )
V_5 |= V_12 ;
break;
case V_13 :
V_6 = F_3 ( V_2 , 0 ,
V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 & V_14 )
V_5 |= V_15 ;
if ( V_6 & V_16 )
V_5 |= V_17 ;
break;
default:
V_5 = - V_18 ;
break;
}
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
return F_5 ( V_2 , V_20 , & V_21 [ V_20 -> V_22 ] ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_23 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_23 ) ;
}
