static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
int V_5 , V_6 ;
switch ( V_4 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 = F_2 ( V_2 , V_3 ,
V_11 ) ;
if ( V_6 < 0 )
return V_5 ;
if ( V_4 == V_10 ) {
if ( V_6 & V_12 )
V_5 |= V_13 ;
} else if ( V_4 == V_9 ) {
if ( V_6 & V_14 )
V_5 |= V_15 ;
} else if ( V_4 == V_7 ) {
if ( V_6 & ( V_16 | V_17 ) )
V_5 |= V_18 ;
if ( V_6 & V_19 )
V_5 |= V_20 ;
} else if ( V_4 == V_8 ) {
if ( V_6 & V_21 )
V_5 |= V_22 ;
if ( V_6 & V_23 )
V_5 |= V_24 ;
}
break;
default:
V_5 = - V_25 ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
int V_5 , V_6 ;
switch ( V_4 ) {
case V_26 :
V_5 = F_4 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 = F_2 ( V_2 , V_3 ,
V_11 ) ;
if ( V_6 < 0 )
return V_5 ;
if ( V_6 & V_27 )
V_5 |= V_28 ;
break;
default:
V_5 = - V_25 ;
break;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
return F_6 ( V_2 , V_30 , & V_31 ) ;
}
