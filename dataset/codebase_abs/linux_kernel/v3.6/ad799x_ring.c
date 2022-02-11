static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_11 ;
T_2 V_12 ;
T_3 * V_13 ;
int V_14 ;
T_4 V_15 ;
V_13 = F_3 ( V_6 -> V_16 , V_17 ) ;
if ( V_13 == NULL )
goto V_18;
switch ( V_8 -> V_19 ) {
case V_20 :
case V_21 :
case V_22 :
V_15 = V_8 -> V_23 |
( * V_6 -> V_24 << V_25 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
V_15 = ( * V_6 -> V_24 << V_25 ) |
V_29 ;
break;
case V_30 :
case V_31 :
V_15 = V_32 | V_29 ;
break;
default:
V_15 = 0 ;
}
V_14 = F_4 ( V_8 -> V_33 ,
V_15 , F_5 ( V_6 -> V_24 ,
V_6 -> V_34 ) * 2 , V_13 ) ;
if ( V_14 < 0 )
goto V_35;
V_12 = F_6 () ;
if ( V_6 -> V_36 )
memcpy ( V_13 + V_6 -> V_16 - sizeof( T_2 ) ,
& V_12 , sizeof( V_12 ) ) ;
V_10 -> V_37 -> V_38 ( V_6 -> V_11 , V_13 , V_12 ) ;
V_35:
F_7 ( V_13 ) ;
V_18:
F_8 ( V_6 -> V_39 ) ;
return V_40 ;
}
int F_9 ( struct V_5 * V_6 )
{
return F_10 ( V_6 , NULL ,
& F_1 , NULL ) ;
}
void F_11 ( struct V_5 * V_6 )
{
F_12 ( V_6 ) ;
}
