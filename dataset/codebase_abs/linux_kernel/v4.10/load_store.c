int F_1 ( T_1 type , T_2 V_1 ,
void T_3 * V_2 )
{
T_4 V_3 ;
T_4 * V_4 ;
T_1 V_5 = V_6 ;
T_1 V_7 ;
int V_8 ;
V_4 = NULL ;
if ( V_1 . V_9 & V_10 ) {
if ( V_1 . V_9 == V_11 ) {
if ( V_12 < V_13 [ type ] )
F_2 ( V_14 , V_15 ) ;
} else if ( V_1 . V_9 == V_16 ) {
if ( V_12 < V_17 [ type ] )
F_2 ( V_14 , V_15 ) ;
}
#ifdef F_3
else
F_4 ( V_18 | 0x140 ) ;
#endif
}
switch ( V_19 [ type ] ) {
case V_20 :
break;
case V_21 :
V_4 = & F_5 ( 0 ) ;
V_5 = F_6 () ;
break;
case V_22 :
{
if ( F_7 ( - 1 ) != V_6 ) {
F_8 () ;
return 0 ;
}
V_23 -- ;
V_4 = & F_5 ( 0 ) ;
}
break;
case V_24 :
F_9 () ;
return 0 ;
#ifdef F_3
default:
F_4 ( V_18 | 0x141 ) ;
return 0 ;
#endif
}
switch ( type ) {
case 000 :
F_10 () ;
V_7 =
F_11 ( ( float T_3 * ) V_2 , & V_3 ) ;
if ( ( V_7 == V_25 )
&& F_12 ( & V_3 )
&& ( F_13 ( & V_3 ) < 0 ) ) {
V_23 ++ ;
break;
}
F_14 ( & V_3 , V_7 ) ;
break;
case 001 :
F_10 () ;
V_7 =
F_15 ( ( long T_3 * ) V_2 , & V_3 ) ;
F_14 ( & V_3 , V_7 ) ;
break;
case 002 :
F_10 () ;
V_7 =
F_16 ( ( double T_3 * ) V_2 ,
& V_3 ) ;
if ( ( V_7 == V_25 )
&& F_12 ( & V_3 )
&& ( F_13 ( & V_3 ) < 0 ) ) {
V_23 ++ ;
break;
}
F_14 ( & V_3 , V_7 ) ;
break;
case 003 :
F_10 () ;
V_7 =
F_17 ( ( short T_3 * ) V_2 , & V_3 ) ;
F_14 ( & V_3 , V_7 ) ;
break;
case 005 :
F_10 () ;
V_8 = V_26 ;
V_26 |= V_27 ;
if ( F_18
( V_4 , V_5 , ( long T_3 * ) V_2 ) )
F_19 () ;
V_26 = V_8 ;
break;
case 006 :
F_10 () ;
V_8 = V_26 ;
V_26 |= V_27 ;
if ( F_20
( V_4 , V_5 , ( long long T_3 * ) V_2 ) )
F_19 () ;
V_26 = V_8 ;
break;
case 007 :
F_10 () ;
V_8 = V_26 ;
V_26 |= V_27 ;
if ( F_21
( V_4 , V_5 , ( short T_3 * ) V_2 ) )
F_19 () ;
V_26 = V_8 ;
break;
case 010 :
F_10 () ;
F_22 ( V_4 , V_5 ,
( float T_3 * ) V_2 ) ;
break;
case 011 :
F_10 () ;
F_18 ( V_4 , V_5 , ( long T_3 * ) V_2 ) ;
break;
case 012 :
F_10 () ;
F_23 ( V_4 , V_5 ,
( double T_3 * ) V_2 ) ;
break;
case 013 :
F_10 () ;
F_21 ( V_4 , V_5 , ( short T_3 * ) V_2 ) ;
break;
case 014 :
F_10 () ;
if ( F_22
( V_4 , V_5 , ( float T_3 * ) V_2 ) )
F_19 () ;
break;
case 015 :
F_10 () ;
if ( F_18
( V_4 , V_5 , ( long T_3 * ) V_2 ) )
F_19 () ;
break;
case 016 :
F_10 () ;
if ( F_23
( V_4 , V_5 , ( double T_3 * ) V_2 ) )
F_19 () ;
break;
case 017 :
F_10 () ;
if ( F_21
( V_4 , V_5 , ( short T_3 * ) V_2 ) )
F_19 () ;
break;
case 020 :
F_24 ( V_1 , ( T_1 T_3 * ) V_2 ) ;
return 1 ;
case 022 :
F_25 ( V_1 , ( T_1 T_3 * ) V_2 ) ;
return 1 ;
case 023 :
F_10 () ;
V_7 = F_26 ( ( T_1 T_3 * ) V_2 ) ;
F_27 ( V_7 ) ;
break;
case 024 :
V_28 ;
F_28 ( V_29 , V_2 , 2 ) ;
F_29 ( V_26 ,
( unsigned short T_3 * ) V_2 ) ;
V_30 ;
if ( V_31 & ~ V_26 & V_32 )
V_31 |= ( V_33 | V_34 ) ;
else
V_31 &= ~ ( V_33 | V_34 ) ;
#ifdef F_30
V_26 |= 0x40 ;
#endif
return 1 ;
case 025 :
F_10 () ;
V_7 =
F_31 ( ( long double T_3 * ) V_2 , 0 ) ;
F_27 ( V_7 ) ;
break;
case 027 :
F_10 () ;
V_7 = F_32 ( ( long long T_3 * ) V_2 ) ;
if ( V_7 == V_35 )
return 0 ;
F_27 ( V_7 ) ;
break;
case 030 :
F_33 ( V_1 , ( T_1 T_3 * ) V_2 ) ;
return 1 ;
case 032 :
F_34 ( V_1 , ( T_1 T_3 * ) V_2 ) ;
return 1 ;
case 033 :
F_10 () ;
if ( F_35
( V_4 , V_5 , ( T_1 T_3 * ) V_2 ) )
F_19 () ;
break;
case 034 :
V_28 ;
F_28 ( V_36 , V_2 , 2 ) ;
F_36 ( V_26 ,
( unsigned short T_3 * ) V_2 ) ;
V_30 ;
return 1 ;
case 035 :
F_10 () ;
if ( F_37
( V_4 , V_5 , ( long double T_3 * ) V_2 ) )
F_19 () ;
break;
case 036 :
V_28 ;
F_28 ( V_36 , V_2 , 2 ) ;
F_36 ( F_38 () ,
( unsigned short T_3 * ) V_2 ) ;
V_30 ;
return 1 ;
case 037 :
F_10 () ;
if ( F_20
( V_4 , V_5 , ( long long T_3 * ) V_2 ) )
F_19 () ;
break;
}
return 0 ;
}
