long F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
int V_6 = V_4 ;
int V_7 = V_5 ;
int V_8 ;
switch ( V_3 ) {
case V_9 :
case V_10 : {
T_3 V_11 ;
int V_12 ;
T_3 T_4 * V_13 ;
V_8 = - V_14 ;
if ( F_2 ( V_13 , ( T_3 T_4 * T_4 * ) ( unsigned long ) V_6 ) != 0 )
break;
V_12 = F_3 ( V_2 , ( V_15 ) V_13 , & V_11 ,
sizeof( V_11 ) , 0 ) ;
if ( V_12 != sizeof( V_11 ) )
break;
V_8 = F_4 ( V_11 , ( T_3 T_4 * ) ( unsigned long ) V_7 ) ;
break;
}
case V_16 : {
struct V_17 * V_18 ;
T_5 * V_19 ;
unsigned int V_11 ;
V_18 = F_5 ( V_2 ) ;
V_8 = 0 ;
switch ( V_6 ) {
case 0 ... 31 :
V_11 = V_18 -> V_18 [ V_6 ] ;
break;
case V_20 ... V_20 + 31 :
if ( ! F_6 ( V_2 ) ) {
V_11 = - 1 ;
break;
}
V_19 = F_7 ( V_2 ) ;
if ( F_8 ( V_21 ) ) {
if ( V_6 & 1 )
V_11 = V_19 [ ( V_6 & ~ 1 ) - 32 ] >> 32 ;
else
V_11 = V_19 [ V_6 - 32 ] ;
break;
}
V_11 = V_19 [ V_6 - V_20 ] ;
break;
case V_22 :
V_11 = V_18 -> V_23 ;
break;
case V_24 :
V_11 = V_18 -> V_25 ;
break;
case V_26 :
V_11 = V_18 -> V_27 ;
break;
case V_28 :
V_11 = V_18 -> V_29 ;
break;
case V_30 :
V_11 = V_18 -> V_31 ;
break;
case V_32 :
V_11 = V_2 -> V_33 . V_34 . V_35 ;
break;
case V_36 : {
unsigned int V_37 ;
#ifdef F_9
unsigned int V_38 ;
unsigned int V_39 ;
#endif
F_10 () ;
if ( ! V_40 ) {
F_11 () ;
V_11 = 0 ;
break;
}
#ifdef F_9
F_12 ( V_38 ) ;
V_39 = F_13 () ;
#endif
if ( V_41 ) {
unsigned int V_42 = F_14 () ;
V_37 = F_15 () ;
F_16 ( V_43 ) ;
__asm__ __volatile__("cfc1\t%0,$0": "=r" (tmp));
F_17 ( V_37 ) ;
F_18 ( V_42 ) ;
} else {
V_37 = F_15 () ;
F_16 ( V_43 ) ;
__asm__ __volatile__("cfc1\t%0,$0": "=r" (tmp));
F_17 ( V_37 ) ;
}
#ifdef F_9
F_19 ( V_39 ) ;
F_20 ( V_38 ) ;
#endif
F_11 () ;
break;
}
case V_44 ... V_44 + 5 : {
T_6 * V_45 ;
if ( ! V_46 ) {
V_11 = 0 ;
V_8 = - V_14 ;
goto V_47;
}
V_45 = F_21 ( V_2 ) ;
V_11 = ( unsigned long ) ( V_45 [ V_6 - V_44 ] ) ;
break;
}
case V_48 :
if ( ! V_46 ) {
V_11 = 0 ;
V_8 = - V_14 ;
goto V_47;
}
V_11 = V_2 -> V_33 . V_49 . V_50 ;
break;
default:
V_11 = 0 ;
V_8 = - V_14 ;
goto V_47;
}
V_8 = F_4 ( V_11 , ( unsigned T_4 * ) ( unsigned long ) V_7 ) ;
break;
}
case V_51 :
case V_52 : {
T_3 T_4 * V_13 ;
V_8 = - V_14 ;
if ( F_2 ( V_13 , ( T_3 T_4 * T_4 * ) ( unsigned long ) V_6 ) != 0 )
break;
V_8 = 0 ;
if ( F_3 ( V_2 , ( V_15 ) V_13 , & V_7 ,
sizeof( V_7 ) , 1 ) == sizeof( V_7 ) )
break;
V_8 = - V_14 ;
break;
}
case V_53 : {
struct V_17 * V_18 ;
V_8 = 0 ;
V_18 = F_5 ( V_2 ) ;
switch ( V_6 ) {
case 0 ... 31 :
V_18 -> V_18 [ V_6 ] = V_7 ;
break;
case V_20 ... V_20 + 31 : {
T_5 * V_19 = F_7 ( V_2 ) ;
if ( ! F_6 ( V_2 ) ) {
memset ( & V_2 -> V_33 . V_34 , ~ 0 ,
sizeof( V_2 -> V_33 . V_34 ) ) ;
V_2 -> V_33 . V_34 . V_35 = 0 ;
}
if ( F_8 ( V_21 ) ) {
if ( V_6 & 1 ) {
V_19 [ ( V_6 & ~ 1 ) - V_20 ] &=
0xffffffff ;
V_19 [ ( V_6 & ~ 1 ) - V_20 ] |=
( ( V_15 ) V_7 ) << 32 ;
} else {
V_19 [ V_6 - V_20 ] &= ~ 0xffffffffLL ;
V_19 [ V_6 - V_20 ] |= V_7 ;
}
break;
}
V_19 [ V_6 - V_20 ] = V_7 ;
break;
}
case V_22 :
V_18 -> V_23 = V_7 ;
break;
case V_28 :
V_18 -> V_29 = V_7 ;
break;
case V_30 :
V_18 -> V_31 = V_7 ;
break;
case V_32 :
V_2 -> V_33 . V_34 . V_35 = V_7 ;
break;
case V_44 ... V_44 + 5 : {
T_6 * V_45 ;
if ( ! V_46 ) {
V_8 = - V_14 ;
break;
}
V_45 = F_21 ( V_2 ) ;
V_45 [ V_6 - V_44 ] = V_7 ;
break;
}
case V_48 :
if ( ! V_46 ) {
V_8 = - V_14 ;
break;
}
V_2 -> V_33 . V_49 . V_50 = V_7 ;
break;
default:
V_8 = - V_14 ;
break;
}
break;
}
case V_54 :
V_8 = F_22 ( V_2 , ( V_55 T_4 * ) ( V_56 ) V_7 ) ;
break;
case V_57 :
V_8 = F_23 ( V_2 , ( V_55 T_4 * ) ( V_56 ) V_7 ) ;
break;
case V_58 :
V_8 = F_24 ( V_2 , ( V_59 T_4 * ) ( V_56 ) V_7 ) ;
break;
case V_60 :
V_8 = F_25 ( V_2 , ( V_59 T_4 * ) ( V_56 ) V_7 ) ;
break;
case V_61 :
V_8 = F_4 ( F_26 ( V_2 ) -> V_62 ,
( unsigned int T_4 * ) ( unsigned long ) V_7 ) ;
break;
case V_63 :
V_8 = F_4 ( F_26 ( V_2 ) -> V_62 ,
( unsigned long T_4 * ) ( unsigned long ) V_7 ) ;
break;
case V_64 :
V_8 = F_27 ( V_2 ,
(struct V_65 T_4 * ) ( unsigned long ) V_6 ) ;
break;
case V_66 :
V_8 = F_28 ( V_2 ,
(struct V_65 T_4 * ) ( unsigned long ) V_6 ) ;
break;
default:
V_8 = F_29 ( V_2 , V_3 , V_6 , V_7 ) ;
break;
}
V_47:
return V_8 ;
}
