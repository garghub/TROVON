static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_5 == V_2 -> V_6 )
V_3 &= ~ ( V_7 ) ;
else
V_3 |= V_7 ;
V_3 = F_3 ( V_2 , V_4 , V_3 ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_9 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_5 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_8 , V_3 ;
V_8 = F_3 ( V_2 , V_9 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_3 = V_13 ;
break;
case V_14 :
V_3 = V_13 | V_15 ;
break;
default:
return - V_16 ;
}
V_8 = F_3 ( V_2 , V_17 , V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_3 ( V_2 , V_18 , V_19 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_3 ( V_2 , V_9 , V_20 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_8 = F_2 ( V_2 , V_4 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
