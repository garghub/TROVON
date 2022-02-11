int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
int F_2 ( struct V_1 * V_2 )
{
T_1 V_4 = V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 ;
int V_8 = 0 ;
if ( V_4 == 10000 )
V_8 = 10 ;
else
V_8 = 1 ;
F_3 ( L_1 , V_4 , F_4 ( V_6 ) , V_8 ) ;
return F_5 ( V_2 , & V_9 , V_8 , 0 ) ;
}
int F_6 ( struct V_10 * V_11 )
{
T_1 V_4 , V_6 ;
int V_12 , V_13 = 0 , V_14 , V_15 , V_8 ;
V_12 = ( int ) V_11 -> V_12 ;
switch ( V_12 ) {
case V_16 :
V_4 = V_11 -> V_5 ;
V_6 = V_11 -> V_7 ;
if ( V_4 == 10000 ) {
V_8 = 1 ;
V_13 = F_7 ( V_11 , & V_9 , & V_8 ,
V_17 ) ;
F_3 ( L_2 ,
V_4 , F_4 ( V_6 ) , V_13 ) ;
}
break;
case V_18 :
V_4 = V_11 -> V_5 ;
V_6 = V_11 -> V_7 ;
if ( F_4 ( V_6 ) == 10001 ) {
V_8 = 10 ;
V_13 = F_7 ( V_11 , & V_9 , & V_8 ,
V_17 ) ;
F_3 ( L_3 ,
V_4 , F_4 ( V_6 ) , V_13 ) ;
}
break;
default:
break;
}
return 0 ;
}
