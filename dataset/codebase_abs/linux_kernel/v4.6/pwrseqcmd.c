T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 V_5 [] )
{
struct V_4 V_6 = { 0 } ;
T_1 V_7 = false ;
T_2 V_8 = 0 ;
T_1 V_9 = 0 ;
T_2 V_10 = 0 ;
T_2 V_11 = 0 ;
T_2 V_12 = 5000 ;
do {
V_6 = V_5 [ V_8 ] ;
F_2 ( V_13 , V_14 ,
( L_1
L_2
L_3 ,
F_3 ( V_6 ) ,
F_4 ( V_6 ) ,
F_5 ( V_6 ) ,
F_6 ( V_6 ) ,
F_7 ( V_6 ) ) ) ;
if ( F_4 ( V_6 ) & V_3 ) {
switch ( F_5 ( V_6 ) ) {
case V_15 :
F_2 ( V_13 , V_14 ,
( L_4 ) ) ;
break;
case V_16 :
F_2 ( V_13 , V_14 ,
( L_5 ) ) ;
V_10 = F_3 ( V_6 ) ;
V_9 = F_8 ( V_2 , V_10 ) ;
V_9 &= ~ ( F_6 ( V_6 ) ) ;
V_9 |= ( F_7 ( V_6 ) &
F_6 ( V_6 ) ) ;
F_9 ( V_2 , V_10 , V_9 ) ;
break;
case V_17 :
F_2 ( V_13 , V_14 ,
( L_6 ) ) ;
V_7 = false ;
V_10 = F_3 ( V_6 ) ;
do {
V_9 = F_8 ( V_2 , V_10 ) ;
V_9 &= F_6 ( V_6 ) ;
if ( V_9 == ( F_7 ( V_6 ) &
F_6 ( V_6 ) ) )
V_7 = true ;
else
F_10 ( 10 ) ;
if ( V_11 ++ > V_12 ) {
F_11 ( L_7 , V_10 ) ;
return false ;
}
} while ( ! V_7 );
break;
case V_18 :
F_2 ( V_13 , V_14 ,
( L_8 ) ) ;
if ( F_7 ( V_6 ) == V_19 )
F_10 ( F_3 ( V_6 ) ) ;
else
F_10 ( F_3 ( V_6 ) * 1000 ) ;
break;
case V_20 :
F_2 ( V_13 , V_14 ,
( L_9 ) ) ;
return true ;
default:
F_2 ( V_13 , V_21 ,
( L_10 ) ) ;
break;
}
}
V_8 ++ ;
} while ( 1 );
return true ;
}
