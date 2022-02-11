void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
static struct V_3 T_2 * V_4 ;
static T_3 V_5 , V_6 ;
F_2 ( V_2 ) ;
if ( ! ( V_5 & V_7 ) && V_1 != V_8 )
goto V_9;
switch ( V_1 ) {
case V_8 :
if ( ! V_4 )
V_4 = F_3 ( V_10 ,
V_11 ) ;
if ( V_4 ) {
V_5 |= V_7 ;
F_4 ( ~ 0 , & V_4 -> V_12 ) ;
}
break;
case V_13 :
case V_14 :
if ( ! F_5 () ) {
F_6 ( V_15 , 0 ) ;
F_6 ( V_16 , 0 ) ;
}
F_4 ( ~ 0 , & V_4 -> V_12 ) ;
V_5 &= ~ V_7 ;
if ( V_1 == V_14 ) {
F_7 ( V_4 ) ;
V_4 = NULL ;
}
goto V_9;
case V_17 :
V_5 |= V_18 ;
V_6 = 0 ;
break;
case V_19 :
V_5 &= ~ V_18 ;
break;
#ifdef F_8
case V_20 :
V_5 ^= V_21 ;
if ( F_5 () )
V_6 ^= V_22 ;
else {
F_6 ( V_15 , V_5 & V_21 ) ;
goto V_9;
}
break;
#endif
#ifdef F_9
case V_23 :
if ( F_5 () )
V_6 |= V_24 ;
else {
F_6 ( V_16 , 1 ) ;
goto V_9;
}
break;
case V_25 :
if ( F_5 () )
V_6 &= ~ V_24 ;
else {
F_6 ( V_16 , 0 ) ;
goto V_9;
}
break;
#endif
case V_26 :
V_6 |= V_27 ;
break;
case V_28 :
V_6 &= ~ V_27 ;
break;
case V_29 :
V_6 |= V_30 ;
break;
case V_31 :
V_6 &= ~ V_30 ;
break;
case V_32 :
V_6 |= V_33 ;
break;
case V_34 :
V_6 &= ~ V_33 ;
break;
case V_35 :
V_6 |= V_36 ;
break;
case V_37 :
V_6 &= ~ V_36 ;
break;
default:
break;
}
if ( V_5 & V_7 )
F_4 ( ~ V_6 , & V_4 -> V_12 ) ;
V_9:
F_10 ( V_2 ) ;
}
