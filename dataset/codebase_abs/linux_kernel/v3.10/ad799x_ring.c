static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
T_2 V_9 ;
int V_10 ;
T_3 V_11 ;
switch ( V_8 -> V_12 ) {
case V_13 :
case V_14 :
case V_15 :
V_11 = V_8 -> V_16 |
( * V_6 -> V_17 << V_18 ) ;
break;
case V_19 :
case V_20 :
case V_21 :
V_11 = ( * V_6 -> V_17 << V_18 ) |
V_22 ;
break;
case V_23 :
case V_24 :
V_11 = V_25 | V_22 ;
break;
default:
V_11 = 0 ;
}
V_10 = F_3 ( V_8 -> V_26 ,
V_11 , V_8 -> V_27 , V_8 -> V_28 ) ;
if ( V_10 < 0 )
goto V_29;
V_9 = F_4 () ;
if ( V_6 -> V_30 )
memcpy ( V_8 -> V_28 + V_6 -> V_31 - sizeof( T_2 ) ,
& V_9 , sizeof( V_9 ) ) ;
F_5 ( V_6 , V_8 -> V_28 ) ;
V_29:
F_6 ( V_6 -> V_32 ) ;
return V_33 ;
}
int F_7 ( struct V_5 * V_6 )
{
return F_8 ( V_6 , NULL ,
& F_1 , NULL ) ;
}
void F_9 ( struct V_5 * V_6 )
{
F_10 ( V_6 ) ;
}
