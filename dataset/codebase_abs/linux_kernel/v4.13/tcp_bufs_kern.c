int F_1 ( struct V_1 * V_2 )
{
int V_3 = 1500000 ;
int V_4 = 40 ;
int V_5 = 0 ;
int V_6 ;
if ( F_2 ( V_2 -> V_7 ) != 55601 &&
V_2 -> V_8 != 55601 )
return - 1 ;
V_6 = ( int ) V_2 -> V_6 ;
#ifdef F_3
F_4 ( L_1 , V_5 ) ;
#endif
switch ( V_6 ) {
case V_9 :
V_5 = V_4 ;
break;
case V_10 :
V_5 = F_5 ( V_2 , V_11 , V_12 , & V_3 ,
sizeof( V_3 ) ) ;
V_5 = V_5 * 100 + F_5 ( V_2 , V_11 , V_13 ,
& V_3 , sizeof( V_3 ) ) ;
break;
case V_14 :
break;
case V_15 :
V_5 = F_5 ( V_2 , V_11 , V_12 , & V_3 ,
sizeof( V_3 ) ) ;
V_5 = V_5 * 100 + F_5 ( V_2 , V_11 , V_13 ,
& V_3 , sizeof( V_3 ) ) ;
break;
default:
V_5 = - 1 ;
}
#ifdef F_3
F_4 ( L_1 , V_5 ) ;
#endif
V_2 -> V_16 = V_5 ;
return 1 ;
}
