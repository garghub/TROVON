int F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 ;
long V_4 = V_2 -> V_5 ;
if ( F_2 ( V_3 , ( V_6 V_7 * ) F_3 ( V_4 ) ) ) {
F_4 ( V_8 , V_9 ) ;
return V_4 ;
}
if ( V_10 ) {
if ( ( (union V_11 ) V_3 ) . V_12 . V_13
== V_14 )
V_4 += 4 ;
else
V_4 += 2 ;
} else if ( F_5 ( V_3 ) )
V_4 += 2 ;
else
V_4 += 4 ;
return V_4 ;
}
int F_6 ( struct V_1 * V_2 )
{
V_6 V_7 * V_15 ;
V_6 V_16 ;
unsigned int V_17 ;
unsigned long V_18 ;
struct V_19 V_20 = { 0 } ;
V_20 . V_21 = 1 ;
V_15 = ( unsigned short V_7 * ) F_3 ( V_2 -> V_5 ) ;
F_2 ( V_16 , V_15 ) ;
V_15 ++ ;
V_18 = V_2 -> V_5 + 2 ;
V_17 = ( ( unsigned int ) V_16 << 16 ) ;
V_20 . V_22 = 2 ;
if ( ! F_5 ( V_16 ) ) {
F_2 ( V_16 , V_15 ) ;
V_15 ++ ;
V_18 = V_2 -> V_5 + 4 ;
V_20 . V_22 = 4 ;
V_17 |= V_16 ;
}
V_20 . V_23 = V_17 ;
if ( F_7 ( V_16 , V_15 ) )
goto V_24;
V_20 . V_25 = 2 ;
V_17 = ( ( unsigned int ) V_16 << 16 ) ;
if ( ! F_5 ( V_16 ) ) {
V_15 ++ ;
if ( F_7 ( V_16 , V_15 ) )
goto V_24;
V_20 . V_25 = 4 ;
V_17 |= V_16 ;
}
V_20 . V_26 = V_17 ;
F_8 ( V_2 , V_20 , & V_18 ) ;
V_2 -> V_5 = V_18 ;
return 0 ;
V_24:
F_4 ( V_8 , V_9 ) ;
return - V_27 ;
}
int F_9 ( struct V_1 * V_2 )
{
V_6 V_7 * V_28 ;
union V_11 V_3 ;
V_6 V_29 ;
T_1 V_30 ;
long V_4 ;
V_4 = V_2 -> V_5 ;
V_28 = ( V_6 V_7 * ) F_3 ( V_4 ) ;
if ( F_2 ( V_3 . V_31 , V_28 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_27 ;
}
switch ( V_3 . V_12 . V_13 ) {
case V_32 :
V_2 -> V_5 += 4 ;
return 0 ;
case V_14 :
V_28 += 1 ;
if ( F_2 ( V_29 , V_28 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_27 ;
}
V_30 = ( ( unsigned ) V_3 . V_31 << 16 ) | V_29 ;
V_2 -> V_2 [ 31 ] = V_4 + 6 ;
V_4 += 4 ;
V_4 >>= 28 ;
V_4 <<= 28 ;
V_4 |=
( ( V_30 & 0xffff ) << 2 ) | ( ( V_30 & 0x3e00000 ) >> 3 ) |
( ( V_30 & 0x1f0000 ) << 7 ) ;
if ( ! V_3 . V_33 . V_34 )
F_10 ( V_4 ) ;
V_2 -> V_5 = V_4 ;
return 0 ;
case V_35 :
if ( V_3 . V_36 . V_37 == V_38 ) {
if ( V_3 . V_36 . V_39 )
V_2 -> V_5 = V_2 -> V_2 [ 31 ] ;
else
V_2 -> V_5 =
V_2 -> V_2 [ V_40 [ V_3 . V_36 . V_41 ] ] ;
if ( V_3 . V_36 . V_42 ) {
if ( V_3 . V_36 . V_43 )
V_2 -> V_2 [ 31 ] = V_4 + 2 ;
else
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
}
return 0 ;
}
break;
}
V_2 -> V_5 += 2 ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
union V_44 V_23 )
{
unsigned int V_45 , V_46 , V_47 ;
long V_4 = V_2 -> V_5 ;
int V_48 = 0 ;
switch ( V_23 . V_49 . V_13 ) {
case V_50 :
switch ( V_23 . V_51 . V_37 ) {
case V_52 :
V_2 -> V_2 [ V_23 . V_51 . V_53 ] = V_4 + 8 ;
case V_54 :
V_2 -> V_5 = V_2 -> V_2 [ V_23 . V_51 . V_55 ] ;
break;
}
break;
case V_56 :
switch ( V_23 . V_49 . V_57 ) {
case V_58 :
case V_59 :
if ( ( long ) V_2 -> V_2 [ V_23 . V_49 . V_55 ] < 0 ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_57 == V_59 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_62 :
case V_63 :
if ( ( long ) V_2 -> V_2 [ V_23 . V_49 . V_55 ] >= 0 ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_57 == V_63 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_64 :
case V_65 :
V_2 -> V_2 [ 31 ] = V_4 + 8 ;
if ( ( long ) V_2 -> V_2 [ V_23 . V_49 . V_55 ] < 0 ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_57 == V_65 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_66 :
case V_67 :
V_2 -> V_2 [ 31 ] = V_4 + 8 ;
if ( ( long ) V_2 -> V_2 [ V_23 . V_49 . V_55 ] >= 0 ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_57 == V_67 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_68 :
if ( ! V_69 )
goto V_70;
V_47 = F_12 ( 0x01 ) ;
if ( V_47 >= 32 ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
}
break;
case V_71 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 + 8 ;
case V_72 :
V_4 += 4 ;
V_4 >>= 28 ;
V_4 <<= 28 ;
V_4 |= ( V_23 . V_73 . V_74 << 2 ) ;
V_2 -> V_5 = V_4 ;
if ( V_23 . V_49 . V_13 == V_75 )
F_10 ( V_2 -> V_5 ) ;
break;
case V_76 :
case V_77 :
if ( V_2 -> V_2 [ V_23 . V_49 . V_55 ] ==
V_2 -> V_2 [ V_23 . V_49 . V_57 ] ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_13 == V_77 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_78 :
case V_79 :
if ( V_2 -> V_2 [ V_23 . V_49 . V_55 ] !=
V_2 -> V_2 [ V_23 . V_49 . V_57 ] ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_13 == V_79 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_80 :
case V_81 :
if ( ( long ) V_2 -> V_2 [ V_23 . V_49 . V_55 ] <= 0 ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_13 == V_81 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_82 :
case V_83 :
if ( ( long ) V_2 -> V_2 [ V_23 . V_49 . V_55 ] > 0 ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_13 == V_83 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_84 :
F_13 () ;
if ( F_14 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_46 = V_9 -> V_85 . V_86 . V_46 ;
F_15 () ;
V_45 = ( V_23 . V_49 . V_57 >> 2 ) ;
V_45 += ( V_45 != 0 ) ;
V_45 += 23 ;
switch ( V_23 . V_49 . V_57 & 3 ) {
case 0 :
case 2 :
if ( ~ V_46 & ( 1 << V_45 ) ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_57 == 2 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case 1 :
case 3 :
if ( V_46 & ( 1 << V_45 ) ) {
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
if ( V_23 . V_49 . V_57 == 3 )
V_48 = V_61 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
}
break;
#ifdef F_16
case V_87 :
if ( ( V_2 -> V_2 [ V_23 . V_49 . V_55 ] & ( 1ull << V_23 . V_49 . V_57 ) )
== 0 )
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_88 :
if ( ( V_2 -> V_2 [ V_23 . V_49 . V_55 ] &
( 1ull << ( V_23 . V_49 . V_57 + 32 ) ) ) == 0 )
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_89 :
if ( V_2 -> V_2 [ V_23 . V_49 . V_55 ] & ( 1ull << V_23 . V_49 . V_57 ) )
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_90 :
if ( V_2 -> V_2 [ V_23 . V_49 . V_55 ] &
( 1ull << ( V_23 . V_49 . V_57 + 32 ) ) )
V_4 = V_4 + 4 + ( V_23 . V_49 . V_60 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
#endif
}
return V_48 ;
V_70:
F_17 ( L_1 , V_9 -> V_91 ) ;
F_4 ( V_92 , V_9 ) ;
return - V_27 ;
}
int F_18 ( struct V_1 * V_2 )
{
unsigned int V_7 * V_28 ;
long V_4 ;
union V_44 V_23 ;
V_4 = V_2 -> V_5 ;
if ( V_4 & 3 )
goto V_93;
V_28 = ( unsigned int V_7 * ) V_4 ;
if ( F_2 ( V_23 . V_17 , V_28 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_27 ;
}
return F_11 ( V_2 , V_23 ) ;
V_93:
F_17 ( L_2 , V_9 -> V_91 ) ;
F_4 ( V_92 , V_9 ) ;
return - V_27 ;
}
