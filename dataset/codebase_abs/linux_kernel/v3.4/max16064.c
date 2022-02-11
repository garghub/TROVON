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
case V_11 :
V_5 = 0 ;
break;
default:
V_5 = - V_12 ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 V_13 )
{
int V_5 ;
switch ( V_4 ) {
case V_10 :
V_5 = F_4 ( V_2 , V_3 ,
V_7 , 0 ) ;
break;
case V_11 :
V_5 = F_4 ( V_2 , V_3 ,
V_9 ,
0xffff ) ;
break;
default:
V_5 = - V_12 ;
break;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
return F_6 ( V_2 , V_15 , & V_16 ) ;
}
