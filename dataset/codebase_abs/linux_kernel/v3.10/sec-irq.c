int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int type = V_2 -> V_4 ;
if ( ! V_2 -> V_5 ) {
F_2 ( V_2 -> V_6 ,
L_1 ) ;
V_2 -> V_7 = 0 ;
return 0 ;
}
switch ( type ) {
case V_8 :
V_3 = F_3 ( V_2 -> V_9 , V_2 -> V_5 ,
V_10 | V_11 ,
V_2 -> V_7 , & V_12 ,
& V_2 -> V_13 ) ;
break;
case V_14 :
V_3 = F_3 ( V_2 -> V_9 , V_2 -> V_5 ,
V_10 | V_11 ,
V_2 -> V_7 , & V_15 ,
& V_2 -> V_13 ) ;
break;
case V_16 :
V_3 = F_3 ( V_2 -> V_9 , V_2 -> V_5 ,
V_10 | V_11 ,
V_2 -> V_7 , & V_17 ,
& V_2 -> V_13 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_2 ,
V_2 -> V_4 ) ;
return - V_18 ;
}
if ( V_3 != 0 ) {
F_4 ( V_2 -> V_6 , L_3 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_5 , V_2 -> V_13 ) ;
}
