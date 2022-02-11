int F_1 ( enum V_1 V_2 )
{
T_1 V_3 , V_4 ;
T_1 V_5 ;
int V_6 ;
switch ( V_2 ) {
case V_7 :
V_3 = F_2 ( 0 ) ;
V_4 = F_3 ( 0 ) ;
V_5 = F_4 ( 2 ) ;
break;
case V_8 :
V_3 = F_5 ( 0 ) ;
V_4 = F_6 ( 0 ) ;
V_5 = F_4 ( 3 ) ;
break;
default:
F_7 ( 1 , L_1 , V_2 ) ;
return - V_9 ;
}
V_6 = F_8 ( V_3 , 8 , V_5 , V_10 ) ;
if ( V_6 )
return V_6 ;
return F_8 ( V_4 , 5 , V_5 , V_10 ) ;
}
