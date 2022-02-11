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
unsigned int V_11 ;
V_18 = F_5 ( V_2 ) ;
V_8 = 0 ;
switch ( V_6 ) {
case 0 ... 31 :
V_11 = V_18 -> V_18 [ V_6 ] ;
break;
case V_19 ... V_19 + 31 :
if ( F_6 ( V_2 ) ) {
T_5 * V_20 = F_7 ( V_2 ) ;
if ( V_6 & 1 )
V_11 = ( unsigned long ) ( V_20 [ ( ( V_6 & ~ 1 ) - 32 ) ] >> 32 ) ;
else
V_11 = ( unsigned long ) ( V_20 [ ( V_6 - 32 ) ] & 0xffffffff ) ;
} else {
V_11 = - 1 ;
}
break;
case V_21 :
V_11 = V_18 -> V_22 ;
break;
case V_23 :
V_11 = V_18 -> V_24 ;
break;
case V_25 :
V_11 = V_18 -> V_26 ;
break;
case V_27 :
V_11 = V_18 -> V_28 ;
break;
case V_29 :
V_11 = V_18 -> V_30 ;
break;
case V_31 :
V_11 = V_2 -> V_32 . V_33 . V_34 ;
break;
case V_35 : {
unsigned int V_36 ;
#ifdef F_8
unsigned int V_37 ;
unsigned int V_38 ;
#endif
F_9 () ;
if ( ! V_39 ) {
F_10 () ;
V_11 = 0 ;
break;
}
#ifdef F_8
F_11 ( V_37 ) ;
V_38 = F_12 () ;
#endif
if ( V_40 ) {
unsigned int V_41 = F_13 () ;
V_36 = F_14 () ;
F_15 () ;
__asm__ __volatile__("cfc1\t%0,$0": "=r" (tmp));
F_16 ( V_36 ) ;
F_17 ( V_41 ) ;
} else {
V_36 = F_14 () ;
F_15 () ;
__asm__ __volatile__("cfc1\t%0,$0": "=r" (tmp));
F_16 ( V_36 ) ;
}
#ifdef F_8
F_18 ( V_38 ) ;
F_19 ( V_37 ) ;
#endif
F_10 () ;
break;
}
case V_42 ... V_42 + 5 : {
T_6 * V_43 ;
if ( ! V_44 ) {
V_11 = 0 ;
V_8 = - V_14 ;
goto V_45;
}
V_43 = F_20 ( V_2 ) ;
V_11 = ( unsigned long ) ( V_43 [ V_6 - V_42 ] ) ;
break;
}
case V_46 :
if ( ! V_44 ) {
V_11 = 0 ;
V_8 = - V_14 ;
goto V_45;
}
V_11 = V_2 -> V_32 . V_47 . V_48 ;
break;
default:
V_11 = 0 ;
V_8 = - V_14 ;
goto V_45;
}
V_8 = F_4 ( V_11 , ( unsigned T_4 * ) ( unsigned long ) V_7 ) ;
break;
}
case V_49 :
case V_50 : {
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
case V_51 : {
struct V_17 * V_18 ;
V_8 = 0 ;
V_18 = F_5 ( V_2 ) ;
switch ( V_6 ) {
case 0 ... 31 :
V_18 -> V_18 [ V_6 ] = V_7 ;
break;
case V_19 ... V_19 + 31 : {
T_5 * V_20 = F_7 ( V_2 ) ;
if ( ! F_6 ( V_2 ) ) {
memset ( & V_2 -> V_32 . V_33 , ~ 0 ,
sizeof( V_2 -> V_32 . V_33 ) ) ;
V_2 -> V_32 . V_33 . V_34 = 0 ;
}
if ( V_6 & 1 ) {
V_20 [ ( V_6 & ~ 1 ) - V_19 ] &= 0xffffffff ;
V_20 [ ( V_6 & ~ 1 ) - V_19 ] |= ( ( unsigned long long ) V_7 ) << 32 ;
} else {
V_20 [ V_6 - V_19 ] &= ~ 0xffffffffLL ;
V_20 [ V_6 - V_19 ] |= ( unsigned int ) V_7 ;
}
break;
}
case V_21 :
V_18 -> V_22 = V_7 ;
break;
case V_27 :
V_18 -> V_28 = V_7 ;
break;
case V_29 :
V_18 -> V_30 = V_7 ;
break;
case V_31 :
V_2 -> V_32 . V_33 . V_34 = V_7 ;
break;
case V_42 ... V_42 + 5 : {
T_6 * V_43 ;
if ( ! V_44 ) {
V_8 = - V_14 ;
break;
}
V_43 = F_20 ( V_2 ) ;
V_43 [ V_6 - V_42 ] = V_7 ;
break;
}
case V_46 :
if ( ! V_44 ) {
V_8 = - V_14 ;
break;
}
V_2 -> V_32 . V_47 . V_48 = V_7 ;
break;
default:
V_8 = - V_14 ;
break;
}
break;
}
case V_52 :
V_8 = F_21 ( V_2 , ( V_53 T_4 * ) ( V_54 ) V_7 ) ;
break;
case V_55 :
V_8 = F_22 ( V_2 , ( V_53 T_4 * ) ( V_54 ) V_7 ) ;
break;
case V_56 :
V_8 = F_23 ( V_2 , ( V_57 T_4 * ) ( V_54 ) V_7 ) ;
break;
case V_58 :
V_8 = F_24 ( V_2 , ( V_57 T_4 * ) ( V_54 ) V_7 ) ;
break;
case V_59 :
V_8 = F_4 ( F_25 ( V_2 ) -> V_60 ,
( unsigned int T_4 * ) ( unsigned long ) V_7 ) ;
break;
case V_61 :
V_8 = F_4 ( F_25 ( V_2 ) -> V_60 ,
( unsigned long T_4 * ) ( unsigned long ) V_7 ) ;
break;
case V_62 :
V_8 = F_26 ( V_2 ,
(struct V_63 T_4 * ) ( unsigned long ) V_6 ) ;
break;
case V_64 :
V_8 = F_27 ( V_2 ,
(struct V_63 T_4 * ) ( unsigned long ) V_6 ) ;
break;
default:
V_8 = F_28 ( V_2 , V_3 , V_6 , V_7 ) ;
break;
}
V_45:
return V_8 ;
}
