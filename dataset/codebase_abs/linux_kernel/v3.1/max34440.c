static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
switch ( V_4 ) {
case V_6 :
V_5 = F_2 ( V_2 , V_3 ,
V_7 ) ;
break;
case V_8 :
V_5 = F_2 ( V_2 , V_3 ,
V_9 ) ;
break;
case V_10 :
V_5 = F_2 ( V_2 , V_3 ,
V_11 ) ;
break;
case V_12 :
case V_13 :
case V_14 :
V_5 = 0 ;
break;
default:
V_5 = - V_15 ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 V_16 )
{
int V_5 ;
switch ( V_4 ) {
case V_12 :
V_5 = F_4 ( V_2 , V_3 ,
V_7 , 0 ) ;
break;
case V_13 :
V_5 = F_4 ( V_2 , V_3 ,
V_9 , 0 ) ;
break;
case V_14 :
V_5 = F_4 ( V_2 , V_3 ,
V_11 ,
0xffff ) ;
break;
default:
V_5 = - V_15 ;
break;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
int V_17 ;
V_5 = F_6 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( V_4 ) {
case V_18 :
V_17 = F_2 ( V_2 , 0 ,
V_19 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_17 & V_20 )
V_5 |= V_21 ;
if ( V_17 & V_22 )
V_5 |= V_23 ;
break;
case V_24 :
V_17 = F_2 ( V_2 , 0 ,
V_19 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_17 & V_25 )
V_5 |= V_26 ;
if ( V_17 & V_27 )
V_5 |= V_28 ;
break;
default:
V_5 = - V_15 ;
break;
}
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
return F_8 ( V_2 , V_30 , & V_31 [ V_30 -> V_32 ] ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_33 ) ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_33 ) ;
}
