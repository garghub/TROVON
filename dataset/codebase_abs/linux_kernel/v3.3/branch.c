int F_1 ( struct V_1 * V_2 ,
union V_3 V_4 )
{
unsigned int V_5 , V_6 , V_7 ;
long V_8 = V_2 -> V_9 ;
int V_10 = 0 ;
switch ( V_4 . V_11 . V_12 ) {
case V_13 :
switch ( V_4 . V_14 . V_15 ) {
case V_16 :
V_2 -> V_2 [ V_4 . V_14 . V_17 ] = V_8 + 8 ;
case V_18 :
V_2 -> V_9 = V_2 -> V_2 [ V_4 . V_14 . V_19 ] ;
break;
}
break;
case V_20 :
switch ( V_4 . V_11 . V_21 ) {
case V_22 :
case V_23 :
if ( ( long ) V_2 -> V_2 [ V_4 . V_11 . V_19 ] < 0 ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == V_23 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_26 :
case V_27 :
if ( ( long ) V_2 -> V_2 [ V_4 . V_11 . V_19 ] >= 0 ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == V_27 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_28 :
case V_29 :
V_2 -> V_2 [ 31 ] = V_8 + 8 ;
if ( ( long ) V_2 -> V_2 [ V_4 . V_11 . V_19 ] < 0 ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == V_29 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_30 :
case V_31 :
V_2 -> V_2 [ 31 ] = V_8 + 8 ;
if ( ( long ) V_2 -> V_2 [ V_4 . V_11 . V_19 ] >= 0 ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == V_31 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_32 :
if ( ! V_33 )
goto V_34;
V_7 = F_2 ( 0x01 ) ;
if ( V_7 >= 32 ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
}
break;
case V_35 :
V_2 -> V_2 [ 31 ] = V_2 -> V_9 + 8 ;
case V_36 :
V_8 += 4 ;
V_8 >>= 28 ;
V_8 <<= 28 ;
V_8 |= ( V_4 . V_37 . V_38 << 2 ) ;
V_2 -> V_9 = V_8 ;
break;
case V_39 :
case V_40 :
if ( V_2 -> V_2 [ V_4 . V_11 . V_19 ] ==
V_2 -> V_2 [ V_4 . V_11 . V_21 ] ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == V_40 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_41 :
case V_42 :
if ( V_2 -> V_2 [ V_4 . V_11 . V_19 ] !=
V_2 -> V_2 [ V_4 . V_11 . V_21 ] ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == V_42 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_43 :
case V_44 :
if ( ( long ) V_2 -> V_2 [ V_4 . V_11 . V_19 ] <= 0 ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == V_42 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_45 :
case V_46 :
if ( ( long ) V_2 -> V_2 [ V_4 . V_11 . V_19 ] > 0 ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == V_42 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_47 :
F_3 () ;
if ( F_4 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_6 = V_48 -> V_49 . V_50 . V_6 ;
F_5 () ;
V_5 = ( V_4 . V_11 . V_21 >> 2 ) ;
V_5 += ( V_5 != 0 ) ;
V_5 += 23 ;
switch ( V_4 . V_11 . V_21 & 3 ) {
case 0 :
case 2 :
if ( ~ V_6 & ( 1 << V_5 ) ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == 2 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case 1 :
case 3 :
if ( V_6 & ( 1 << V_5 ) ) {
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
if ( V_4 . V_11 . V_21 == 3 )
V_10 = V_25 ;
} else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
}
break;
#ifdef F_6
case V_51 :
if ( ( V_2 -> V_2 [ V_4 . V_11 . V_19 ] & ( 1ull << V_4 . V_11 . V_21 ) )
== 0 )
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_52 :
if ( ( V_2 -> V_2 [ V_4 . V_11 . V_19 ] &
( 1ull << ( V_4 . V_11 . V_21 + 32 ) ) ) == 0 )
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_53 :
if ( V_2 -> V_2 [ V_4 . V_11 . V_19 ] & ( 1ull << V_4 . V_11 . V_21 ) )
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
case V_54 :
if ( V_2 -> V_2 [ V_4 . V_11 . V_19 ] &
( 1ull << ( V_4 . V_11 . V_21 + 32 ) ) )
V_8 = V_8 + 4 + ( V_4 . V_11 . V_24 << 2 ) ;
else
V_8 += 8 ;
V_2 -> V_9 = V_8 ;
break;
#endif
}
return V_10 ;
V_34:
F_7 ( L_1 , V_48 -> V_55 ) ;
F_8 ( V_56 , V_48 ) ;
return - V_57 ;
}
int F_9 ( struct V_1 * V_2 )
{
unsigned int T_1 * V_58 ;
long V_8 ;
union V_3 V_4 ;
V_8 = V_2 -> V_9 ;
if ( V_8 & 3 )
goto V_59;
V_58 = ( unsigned int T_1 * ) V_8 ;
if ( F_10 ( V_4 . V_60 , V_58 ) ) {
F_8 ( V_61 , V_48 ) ;
return - V_57 ;
}
return F_1 ( V_2 , V_4 ) ;
V_59:
F_7 ( L_2 , V_48 -> V_55 ) ;
F_8 ( V_56 , V_48 ) ;
return - V_57 ;
}
