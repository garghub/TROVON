int F_1 ( struct V_1 * V_2 )
{
int V_3 = 1500000 ;
int V_4 = 40 ;
int V_5 = 40 ;
int V_6 = 0 ;
int V_7 ;
if ( F_2 ( V_2 -> V_8 ) != 55601 &&
V_2 -> V_9 != 55601 )
return - 1 ;
V_7 = ( int ) V_2 -> V_7 ;
#ifdef F_3
F_4 ( L_1 , V_7 ) ;
#endif
switch ( V_7 ) {
case V_10 :
V_6 = V_4 ;
break;
case V_11 :
V_6 = F_5 ( V_2 , V_12 , V_13 , & V_3 ,
sizeof( V_3 ) ) ;
V_6 = V_6 * 100 + F_5 ( V_2 , V_12 , V_14 ,
& V_3 , sizeof( V_3 ) ) ;
break;
case V_15 :
V_6 = F_5 ( V_2 , V_16 , V_17 , & V_5 ,
sizeof( V_5 ) ) ;
break;
case V_18 :
V_6 = F_5 ( V_2 , V_12 , V_13 , & V_3 ,
sizeof( V_3 ) ) ;
V_6 = V_6 * 100 + F_5 ( V_2 , V_12 , V_14 ,
& V_3 , sizeof( V_3 ) ) ;
break;
default:
V_6 = - 1 ;
}
#ifdef F_3
F_4 ( L_2 , V_6 ) ;
#endif
V_2 -> V_19 = V_6 ;
return 1 ;
}
