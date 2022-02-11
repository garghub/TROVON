int T_1 F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_5 * V_7 = V_8 ;
struct V_9 * V_10 ;
struct V_9 * V_11 = NULL ;
int V_12 ;
switch ( V_4 & V_13 ) {
case V_14 :
F_2 ( L_1 , V_15 ) ;
V_6 = V_16 ;
V_10 = V_17 ;
break;
case V_18 :
F_2 ( L_2 , V_15 ) ;
V_6 = V_19 ;
V_10 = V_17 ;
V_11 = V_20 ;
break;
default:
F_3 ( L_3 , V_15 ) ;
return - V_21 ;
}
V_12 = F_4 ( L_4 ,
V_22 ,
V_23 ,
V_24 ,
V_10 , V_11 , V_2 ,
V_6 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( L_5 ,
V_22 ,
V_25 ,
V_26 ,
V_27 , NULL , V_3 ,
V_7 ) ;
return V_12 ;
}
