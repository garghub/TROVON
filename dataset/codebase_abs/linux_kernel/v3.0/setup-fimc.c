int F_1 ( enum V_1 V_2 )
{
T_1 V_3 , V_4 ;
int V_5 ;
switch ( V_2 ) {
case V_6 :
V_3 = F_2 ( 0 ) ;
V_4 = F_3 ( 0 ) ;
break;
case V_7 :
V_3 = F_4 ( 0 ) ;
V_4 = F_5 ( 0 ) ;
break;
default:
F_6 ( 1 , L_1 , V_2 ) ;
return - V_8 ;
}
V_5 = F_7 ( V_3 , 8 , F_8 ( 2 ) ,
V_9 ) ;
if ( V_5 )
return V_5 ;
return F_7 ( V_4 , 5 , F_8 ( 2 ) ,
V_9 ) ;
}
