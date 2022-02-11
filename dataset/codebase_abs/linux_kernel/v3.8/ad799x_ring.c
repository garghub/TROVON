static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
T_2 V_9 ;
T_3 * V_10 ;
int V_11 ;
T_4 V_12 ;
V_10 = F_3 ( V_6 -> V_13 , V_14 ) ;
if ( V_10 == NULL )
goto V_15;
switch ( V_8 -> V_16 ) {
case V_17 :
case V_18 :
case V_19 :
V_12 = V_8 -> V_20 |
( * V_6 -> V_21 << V_22 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
V_12 = ( * V_6 -> V_21 << V_22 ) |
V_26 ;
break;
case V_27 :
case V_28 :
V_12 = V_29 | V_26 ;
break;
default:
V_12 = 0 ;
}
V_11 = F_4 ( V_8 -> V_30 ,
V_12 , F_5 ( V_6 -> V_21 ,
V_6 -> V_31 ) * 2 , V_10 ) ;
if ( V_11 < 0 )
goto V_32;
V_9 = F_6 () ;
if ( V_6 -> V_33 )
memcpy ( V_10 + V_6 -> V_13 - sizeof( T_2 ) ,
& V_9 , sizeof( V_9 ) ) ;
F_7 ( V_6 , V_10 ) ;
V_32:
F_8 ( V_10 ) ;
V_15:
F_9 ( V_6 -> V_34 ) ;
return V_35 ;
}
int F_10 ( struct V_5 * V_6 )
{
return F_11 ( V_6 , NULL ,
& F_1 , NULL ) ;
}
void F_12 ( struct V_5 * V_6 )
{
F_13 ( V_6 ) ;
}
