T_1 F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 ,
T_1 V_5 ,
T_2 V_6 []
)
{
T_2 V_7 = { 0 } ;
T_1 V_8 = false ;
T_3 V_9 = 0 ;
T_1 V_10 = 0 ;
T_3 V_11 = 0 ;
T_3 V_12 = 0 ;
T_3 V_13 = 5000 ;
do {
V_7 = V_6 [ V_9 ] ;
F_2 (
V_14 ,
V_15 ,
(
L_1 ,
F_3 ( V_7 ) ,
F_4 ( V_7 ) ,
F_5 ( V_7 ) ,
F_6 ( V_7 ) ,
F_7 ( V_7 ) ,
F_8 ( V_7 ) ,
F_9 ( V_7 ) ,
F_10 ( V_7 )
)
) ;
if (
( F_5 ( V_7 ) & V_4 ) &&
( F_4 ( V_7 ) & V_3 ) &&
( F_6 ( V_7 ) & V_5 )
) {
switch ( F_8 ( V_7 ) ) {
case V_16 :
F_2 (
V_14 ,
V_15 ,
( L_2 )
) ;
break;
case V_17 :
F_2 (
V_14 ,
V_15 ,
( L_3 )
) ;
V_11 = F_3 ( V_7 ) ;
if ( F_7 ( V_7 ) == V_18 ) {
V_10 = F_11 ( V_2 , V_11 ) ;
V_10 &= ~ ( F_9 ( V_7 ) ) ;
V_10 |= (
F_10 ( V_7 ) &
F_9 ( V_7 )
) ;
F_12 ( V_2 , V_11 , V_10 ) ;
} else {
V_10 = F_13 ( V_2 , V_11 ) ;
V_10 &= ( ~ ( F_9 ( V_7 ) ) ) ;
V_10 |= (
F_10 ( V_7 )
& F_9 ( V_7 )
) ;
F_14 ( V_2 , V_11 , V_10 ) ;
}
break;
case V_19 :
F_2 (
V_14 ,
V_15 ,
( L_4 )
) ;
V_8 = false ;
V_11 = F_3 ( V_7 ) ;
do {
if ( F_7 ( V_7 ) == V_18 )
V_10 = F_11 ( V_2 , V_11 ) ;
else
V_10 = F_13 ( V_2 , V_11 ) ;
V_10 = V_10 & F_9 ( V_7 ) ;
if (
V_10 == ( F_10 ( V_7 ) &
F_9 ( V_7 ) )
)
V_8 = true ;
else
F_15 ( 10 ) ;
if ( V_12 ++ > V_13 ) {
F_16 (
L_5 ,
V_11 ,
V_10
) ;
return false ;
}
} while ( ! V_8 );
break;
case V_20 :
F_2 (
V_14 ,
V_15 ,
( L_6 )
) ;
if ( F_10 ( V_7 ) == V_21 )
F_15 ( F_3 ( V_7 ) ) ;
else
F_15 ( F_3 ( V_7 ) * 1000 ) ;
break;
case V_22 :
F_2 (
V_14 ,
V_15 ,
( L_7 )
) ;
return true ;
default:
F_2 (
V_14 ,
V_23 ,
( L_8 )
) ;
break;
}
}
V_9 ++ ;
} while ( 1 );
return true ;
}
