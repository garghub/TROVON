T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 ,
struct V_6 V_7 [] )
{
struct V_6 V_8 ;
T_1 V_9 ;
T_2 V_10 = 0 ;
T_1 V_11 ;
T_2 V_12 ;
T_2 V_13 = 0 ;
T_2 V_14 = 5000 ;
do {
V_8 = V_7 [ V_10 ] ;
F_2 ( V_15 , V_16 ,
L_1 ,
F_3 ( V_8 ) ,
F_4 ( V_8 ) ,
F_5 ( V_8 ) ,
F_6 ( V_8 ) ,
F_7 ( V_8 ) ,
F_8 ( V_8 ) ,
F_9 ( V_8 ) ,
F_10 ( V_8 ) ) ;
if ( ( F_5 ( V_8 ) & V_4 ) &&
( F_4 ( V_8 ) & V_3 ) &&
( F_6 ( V_8 ) & V_5 ) ) {
switch ( F_8 ( V_8 ) ) {
case V_17 :
F_2 ( V_15 , V_16 ,
L_2 ) ;
break;
case V_18 :
F_2 ( V_15 , V_16 ,
L_3 ) ;
V_12 = F_3 ( V_8 ) ;
V_11 = F_11 ( V_2 , V_12 ) ;
V_11 &= ~ ( F_9 ( V_8 ) ) ;
V_11 |= ( F_10 ( V_8 ) &
F_9 ( V_8 ) ) ;
F_12 ( V_2 , V_12 , V_11 ) ;
break;
case V_19 :
F_2 ( V_15 , V_16 ,
L_4 ) ;
V_9 = false ;
V_12 = F_3 ( V_8 ) ;
do {
V_11 = F_11 ( V_2 ,
V_12 ) ;
V_11 &= F_9 ( V_8 ) ;
if ( V_11 ==
( F_10 ( V_8 ) &
F_9 ( V_8 ) ) )
V_9 = true ;
else
F_13 ( 10 ) ;
if ( V_13 ++ > V_14 ) {
F_14 ( L_5
L_6 ,
V_12 ) ;
return false ;
}
} while ( ! V_9 );
break;
case V_20 :
F_2 ( V_15 , V_16 ,
L_7 ) ;
if ( F_10 ( V_8 ) ==
V_21 )
F_13 ( F_3 ( V_8 ) ) ;
else
F_13 ( F_3 ( V_8 ) *
1000 ) ;
break;
case V_22 :
F_2 ( V_15 , V_16 ,
L_8 ) ;
return true ;
default:
F_2 ( V_15 , V_23 ,
L_9 ) ;
break;
}
}
V_10 ++ ;
} while ( 1 );
return true ;
}
