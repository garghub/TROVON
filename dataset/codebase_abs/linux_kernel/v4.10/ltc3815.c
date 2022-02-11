static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
switch ( V_4 ) {
case V_6 :
V_5 = 0x40 ;
break;
default:
V_5 = - V_7 ;
break;
}
return V_5 ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 ;
switch ( V_4 ) {
case V_8 :
V_5 = F_3 ( V_2 , 0 , V_9 ) ;
if ( V_5 > 0 ) {
F_4 ( V_2 , 0 , V_9 ,
V_5 ) ;
V_5 = 0 ;
}
break;
default:
V_5 = - V_7 ;
break;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
switch ( V_4 ) {
case V_10 :
V_5 = F_3 ( V_2 , V_3 , V_11 ) ;
break;
case V_12 :
V_5 = F_3 ( V_2 , V_3 , V_13 ) ;
break;
case V_14 :
V_5 = F_3 ( V_2 , V_3 , V_15 ) ;
break;
case V_16 :
V_5 = F_3 ( V_2 , V_3 , V_17 ) ;
break;
case V_18 :
V_5 = F_3 ( V_2 , V_3 , V_19 ) ;
break;
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
V_5 = 0 ;
break;
default:
V_5 = - V_7 ;
break;
}
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_2 V_25 )
{
int V_5 ;
switch ( V_4 ) {
case V_24 :
V_5 = F_4 ( V_2 , V_3 ,
V_19 , 0 ) ;
break;
case V_23 :
V_5 = F_4 ( V_2 , V_3 ,
V_17 , 0 ) ;
break;
case V_20 :
V_5 = F_4 ( V_2 , V_3 ,
V_13 , 0 ) ;
break;
case V_21 :
V_5 = F_4 ( V_2 , V_3 ,
V_11 , 0 ) ;
break;
case V_22 :
V_5 = F_4 ( V_2 , V_3 ,
V_15 , 0 ) ;
break;
default:
V_5 = - V_7 ;
break;
}
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_26 * V_27 )
{
int V_28 ;
if ( ! F_8 ( V_2 -> V_29 ,
V_30 ) )
return - V_31 ;
V_28 = F_9 ( V_2 , V_32 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( V_28 & V_33 ) != V_34 )
return - V_31 ;
return F_10 ( V_2 , V_27 , & V_35 ) ;
}
