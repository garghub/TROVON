int F_1 ( struct V_1 * V_2 )
{
unsigned int T_1 * V_3 ;
unsigned int V_4 , V_5 , V_6 ;
long V_7 ;
union V_8 V_9 ;
V_7 = V_2 -> V_10 ;
if ( V_7 & 3 )
goto V_11;
V_3 = ( unsigned int T_1 * ) V_7 ;
if ( F_2 ( V_9 . V_12 , V_3 ) ) {
F_3 ( V_13 , V_14 ) ;
return - V_15 ;
}
switch ( V_9 . V_16 . V_17 ) {
case V_18 :
switch ( V_9 . V_19 . V_20 ) {
case V_21 :
V_2 -> V_2 [ V_9 . V_19 . V_22 ] = V_7 + 8 ;
case V_23 :
V_2 -> V_10 = V_2 -> V_2 [ V_9 . V_19 . V_24 ] ;
break;
}
break;
case V_25 :
switch ( V_9 . V_16 . V_26 ) {
case V_27 :
case V_28 :
if ( ( long ) V_2 -> V_2 [ V_9 . V_16 . V_24 ] < 0 )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_30 :
case V_31 :
if ( ( long ) V_2 -> V_2 [ V_9 . V_16 . V_24 ] >= 0 )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_32 :
case V_33 :
V_2 -> V_2 [ 31 ] = V_7 + 8 ;
if ( ( long ) V_2 -> V_2 [ V_9 . V_16 . V_24 ] < 0 )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_34 :
case V_35 :
V_2 -> V_2 [ 31 ] = V_7 + 8 ;
if ( ( long ) V_2 -> V_2 [ V_9 . V_16 . V_24 ] >= 0 )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_36 :
if ( ! V_37 )
goto V_38;
V_6 = F_4 ( 0x01 ) ;
if ( V_6 >= 32 ) {
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
} else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
}
break;
case V_39 :
V_2 -> V_2 [ 31 ] = V_2 -> V_10 + 8 ;
case V_40 :
V_7 += 4 ;
V_7 >>= 28 ;
V_7 <<= 28 ;
V_7 |= ( V_9 . V_41 . V_42 << 2 ) ;
V_2 -> V_10 = V_7 ;
break;
case V_43 :
case V_44 :
if ( V_2 -> V_2 [ V_9 . V_16 . V_24 ] ==
V_2 -> V_2 [ V_9 . V_16 . V_26 ] )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_45 :
case V_46 :
if ( V_2 -> V_2 [ V_9 . V_16 . V_24 ] !=
V_2 -> V_2 [ V_9 . V_16 . V_26 ] )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_47 :
case V_48 :
if ( ( long ) V_2 -> V_2 [ V_9 . V_16 . V_24 ] <= 0 )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_49 :
case V_50 :
if ( ( long ) V_2 -> V_2 [ V_9 . V_16 . V_24 ] > 0 )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_51 :
F_5 () ;
if ( F_6 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_5 = V_14 -> V_52 . V_53 . V_5 ;
F_7 () ;
V_4 = ( V_9 . V_16 . V_26 >> 2 ) ;
V_4 += ( V_4 != 0 ) ;
V_4 += 23 ;
switch ( V_9 . V_16 . V_26 & 3 ) {
case 0 :
case 2 :
if ( ~ V_5 & ( 1 << V_4 ) )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case 1 :
case 3 :
if ( V_5 & ( 1 << V_4 ) )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
}
break;
#ifdef F_8
case V_54 :
if ( ( V_2 -> V_2 [ V_9 . V_16 . V_24 ] & ( 1ull << V_9 . V_16 . V_26 ) )
== 0 )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_55 :
if ( ( V_2 -> V_2 [ V_9 . V_16 . V_24 ] &
( 1ull << ( V_9 . V_16 . V_26 + 32 ) ) ) == 0 )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_56 :
if ( V_2 -> V_2 [ V_9 . V_16 . V_24 ] & ( 1ull << V_9 . V_16 . V_26 ) )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
case V_57 :
if ( V_2 -> V_2 [ V_9 . V_16 . V_24 ] &
( 1ull << ( V_9 . V_16 . V_26 + 32 ) ) )
V_7 = V_7 + 4 + ( V_9 . V_16 . V_29 << 2 ) ;
else
V_7 += 8 ;
V_2 -> V_10 = V_7 ;
break;
#endif
}
return 0 ;
V_11:
F_9 ( L_1 , V_14 -> V_58 ) ;
F_3 ( V_59 , V_14 ) ;
return - V_15 ;
V_38:
F_9 ( L_2 , V_14 -> V_58 ) ;
F_3 ( V_59 , V_14 ) ;
return - V_15 ;
}
