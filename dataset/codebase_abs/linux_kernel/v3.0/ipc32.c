T_1 long F_1 ( T_2 V_1 , int V_2 , int V_3 , int V_4 ,
T_3 V_5 , T_2 V_6 )
{
int V_7 ;
V_7 = V_1 >> 16 ;
V_1 &= 0xffff ;
switch ( V_1 ) {
case V_8 :
return F_2 ( V_2 , F_3 ( V_5 ) , V_3 , NULL ) ;
case V_9 :
return F_4 ( V_2 , F_3 ( V_5 ) , V_3 ,
F_3 ( V_6 ) ) ;
case V_10 :
return F_5 ( V_2 , V_3 , V_4 ) ;
case V_11 :
return F_6 ( V_2 , V_3 , V_4 , F_3 ( V_5 ) ) ;
case V_12 :
return F_7 ( V_2 , V_3 , V_4 , F_3 ( V_5 ) ) ;
case V_13 :
return F_8 ( V_2 , V_3 , V_6 , V_4 ,
V_7 , F_3 ( V_5 ) ) ;
case V_14 :
return F_9 ( ( V_15 ) V_2 , V_3 ) ;
case V_16 :
return F_10 ( V_2 , V_3 , F_3 ( V_5 ) ) ;
case V_17 :
return F_11 ( V_2 , V_3 , V_4 , V_7 ,
F_3 ( V_5 ) ) ;
case V_18 :
return F_12 ( F_3 ( V_5 ) ) ;
case V_19 :
return F_13 ( V_2 , ( unsigned ) V_3 , V_4 ) ;
case V_20 :
return F_14 ( V_2 , V_3 , F_3 ( V_5 ) ) ;
}
return - V_21 ;
}
