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
int F_6 ( struct V_1 * V_2 , struct V_15 V_16 ,
unsigned long * V_17 )
{
union V_18 V_19 = (union V_18 ) V_16 . V_19 ;
int V_20 = 0 ;
unsigned int V_21 ;
unsigned int V_22 ;
if ( ! V_23 )
return 0 ;
switch ( V_19 . V_24 . V_13 ) {
case V_25 :
if ( ( V_19 . V_24 . V_26 & V_27 ) ==
V_28 ) {
switch ( V_19 . V_24 . V_26 >>
V_29 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
if ( V_19 . V_24 . V_34 != 0 )
V_2 -> V_2 [ V_19 . V_24 . V_34 ] =
V_2 -> V_5 +
V_16 . V_35 +
V_16 . V_36 ;
* V_17 = V_2 -> V_2 [ V_19 . V_24 . V_37 ] ;
return 1 ;
}
}
break;
case V_38 :
switch ( V_19 . V_24 . V_34 ) {
case V_39 :
case V_40 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_16 . V_35 +
V_16 . V_36 ;
case V_41 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_24 . V_37 ] < 0 )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_24 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
V_16 . V_36 ;
return 1 ;
case V_42 :
case V_43 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_16 . V_35 +
V_16 . V_36 ;
case V_44 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_24 . V_37 ] >= 0 )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_24 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
V_16 . V_36 ;
return 1 ;
case V_45 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_24 . V_37 ] <= 0 )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_24 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
V_16 . V_36 ;
return 1 ;
case V_46 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_24 . V_37 ] <= 0 )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_24 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
V_16 . V_36 ;
return 1 ;
case V_47 :
case V_48 :
V_20 = 1 ;
case V_49 :
case V_50 :
F_7 () ;
if ( F_8 () )
asm volatile("cfc1\t%0,$31" : "=r" (fcr31));
else
V_21 = V_9 -> V_51 . V_52 . V_21 ;
F_9 () ;
if ( V_20 )
V_21 = ~ V_21 ;
V_22 = ( V_19 . V_24 . V_37 >> 2 ) ;
V_22 += ( V_22 != 0 ) ;
V_22 += 23 ;
if ( V_21 & ( 1 << V_22 ) )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_24 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
return 1 ;
}
break;
case V_53 :
switch ( V_19 . V_24 . V_34 ) {
case V_54 :
case V_55 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
case V_56 :
* V_17 = V_2 -> V_2 [ V_19 . V_24 . V_37 ] ;
return 1 ;
}
break;
case V_57 :
if ( ( long ) V_2 -> V_2 [ V_58 [ V_19 . V_59 . V_37 ] ] == 0 )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_59 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
return 1 ;
case V_60 :
if ( ( long ) V_2 -> V_2 [ V_58 [ V_19 . V_59 . V_37 ] ] != 0 )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_59 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
return 1 ;
case V_61 :
* V_17 = V_2 -> V_5 + V_16 . V_35 +
( V_19 . V_62 . V_26 << 1 ) ;
return 1 ;
case V_63 :
if ( V_2 -> V_2 [ V_19 . V_24 . V_37 ] ==
V_2 -> V_2 [ V_19 . V_24 . V_34 ] )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_24 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
V_16 . V_36 ;
return 1 ;
case V_64 :
if ( V_2 -> V_2 [ V_19 . V_24 . V_37 ] !=
V_2 -> V_2 [ V_19 . V_24 . V_34 ] )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_24 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
return 1 ;
case V_65 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
* V_17 = V_2 -> V_5 + V_16 . V_35 ;
* V_17 >>= 28 ;
* V_17 <<= 28 ;
* V_17 |= ( V_19 . V_66 . V_67 << 2 ) ;
return 1 ;
case V_68 :
case V_69 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
case V_70 :
* V_17 = V_2 -> V_5 + V_16 . V_35 ;
* V_17 >>= 27 ;
* V_17 <<= 27 ;
* V_17 |= ( V_19 . V_66 . V_67 << 1 ) ;
F_10 ( * V_17 ) ;
return 1 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
V_6 V_7 * V_71 ;
V_6 V_72 ;
unsigned int V_73 ;
unsigned long V_17 ;
struct V_15 V_74 = { 0 } ;
V_74 . V_75 = 1 ;
V_71 = ( unsigned short V_7 * ) F_3 ( V_2 -> V_5 ) ;
F_2 ( V_72 , V_71 ) ;
V_71 ++ ;
V_17 = V_2 -> V_5 + 2 ;
V_73 = ( ( unsigned int ) V_72 << 16 ) ;
V_74 . V_35 = 2 ;
if ( ! F_5 ( V_72 ) ) {
F_2 ( V_72 , V_71 ) ;
V_71 ++ ;
V_17 = V_2 -> V_5 + 4 ;
V_74 . V_35 = 4 ;
V_73 |= V_72 ;
}
V_74 . V_19 = V_73 ;
if ( F_12 ( V_72 , V_71 ) )
goto V_76;
V_74 . V_36 = 2 ;
V_73 = ( ( unsigned int ) V_72 << 16 ) ;
if ( ! F_5 ( V_72 ) ) {
V_71 ++ ;
if ( F_12 ( V_72 , V_71 ) )
goto V_76;
V_74 . V_36 = 4 ;
V_73 |= V_72 ;
}
V_74 . V_77 = V_73 ;
F_13 ( V_2 , V_74 , & V_17 ) ;
V_2 -> V_5 = V_17 ;
return 0 ;
V_76:
F_4 ( V_8 , V_9 ) ;
return - V_78 ;
}
int F_14 ( struct V_1 * V_2 )
{
V_6 V_7 * V_79 ;
union V_11 V_3 ;
V_6 V_80 ;
T_1 V_81 ;
long V_4 ;
V_4 = V_2 -> V_5 ;
V_79 = ( V_6 V_7 * ) F_3 ( V_4 ) ;
if ( F_2 ( V_3 . V_82 , V_79 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_78 ;
}
switch ( V_3 . V_12 . V_13 ) {
case V_83 :
V_2 -> V_5 += 4 ;
return 0 ;
case V_14 :
V_79 += 1 ;
if ( F_2 ( V_80 , V_79 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_78 ;
}
V_81 = ( ( unsigned ) V_3 . V_82 << 16 ) | V_80 ;
V_2 -> V_2 [ 31 ] = V_4 + 6 ;
V_4 += 4 ;
V_4 >>= 28 ;
V_4 <<= 28 ;
V_4 |=
( ( V_81 & 0xffff ) << 2 ) | ( ( V_81 & 0x3e00000 ) >> 3 ) |
( ( V_81 & 0x1f0000 ) << 7 ) ;
if ( ! V_3 . V_84 . V_85 )
F_10 ( V_4 ) ;
V_2 -> V_5 = V_4 ;
return 0 ;
case V_86 :
if ( V_3 . V_87 . V_88 == V_89 ) {
if ( V_3 . V_87 . V_90 )
V_2 -> V_5 = V_2 -> V_2 [ 31 ] ;
else
V_2 -> V_5 =
V_2 -> V_2 [ V_91 [ V_3 . V_87 . V_92 ] ] ;
if ( V_3 . V_87 . V_93 ) {
if ( V_3 . V_87 . V_94 )
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
int F_15 ( struct V_1 * V_2 ,
union V_18 V_19 )
{
unsigned int V_22 , V_21 , V_95 ;
long V_4 = V_2 -> V_5 ;
int V_96 = 0 ;
switch ( V_19 . V_97 . V_13 ) {
case V_98 :
switch ( V_19 . V_99 . V_88 ) {
case V_100 :
V_2 -> V_2 [ V_19 . V_99 . V_101 ] = V_4 + 8 ;
case V_102 :
V_2 -> V_5 = V_2 -> V_2 [ V_19 . V_99 . V_37 ] ;
break;
}
break;
case V_103 :
switch ( V_19 . V_97 . V_34 ) {
case V_104 :
case V_105 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_97 . V_37 ] < 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_34 == V_105 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_107 :
case V_108 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_97 . V_37 ] >= 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_34 == V_108 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_109 :
case V_110 :
V_2 -> V_2 [ 31 ] = V_4 + 8 ;
if ( ( long ) V_2 -> V_2 [ V_19 . V_97 . V_37 ] < 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_34 == V_110 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_111 :
case V_112 :
V_2 -> V_2 [ 31 ] = V_4 + 8 ;
if ( ( long ) V_2 -> V_2 [ V_19 . V_97 . V_37 ] >= 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_34 == V_112 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_113 :
if ( ! V_114 )
goto V_115;
V_95 = F_16 ( 0x01 ) ;
if ( V_95 >= 32 ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
}
break;
case V_116 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 + 8 ;
case V_117 :
V_4 += 4 ;
V_4 >>= 28 ;
V_4 <<= 28 ;
V_4 |= ( V_19 . V_66 . V_67 << 2 ) ;
V_2 -> V_5 = V_4 ;
if ( V_19 . V_97 . V_13 == V_118 )
F_10 ( V_2 -> V_5 ) ;
break;
case V_119 :
case V_120 :
if ( V_2 -> V_2 [ V_19 . V_97 . V_37 ] ==
V_2 -> V_2 [ V_19 . V_97 . V_34 ] ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_13 == V_120 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_121 :
case V_122 :
if ( V_2 -> V_2 [ V_19 . V_97 . V_37 ] !=
V_2 -> V_2 [ V_19 . V_97 . V_34 ] ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_13 == V_122 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_123 :
case V_124 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_97 . V_37 ] <= 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_13 == V_124 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_125 :
case V_126 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_97 . V_37 ] > 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_13 == V_126 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_127 :
F_7 () ;
if ( F_8 () )
asm volatile(
".set push\n"
"\t.set mips1\n"
"\tcfc1\t%0,$31\n"
"\t.set pop" : "=r" (fcr31));
else
V_21 = V_9 -> V_51 . V_52 . V_21 ;
F_9 () ;
V_22 = ( V_19 . V_97 . V_34 >> 2 ) ;
V_22 += ( V_22 != 0 ) ;
V_22 += 23 ;
switch ( V_19 . V_97 . V_34 & 3 ) {
case 0 :
case 2 :
if ( ~ V_21 & ( 1 << V_22 ) ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_34 == 2 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case 1 :
case 3 :
if ( V_21 & ( 1 << V_22 ) ) {
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
if ( V_19 . V_97 . V_34 == 3 )
V_96 = V_106 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
}
break;
#ifdef F_17
case V_128 :
if ( ( V_2 -> V_2 [ V_19 . V_97 . V_37 ] & ( 1ull << V_19 . V_97 . V_34 ) )
== 0 )
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_129 :
if ( ( V_2 -> V_2 [ V_19 . V_97 . V_37 ] &
( 1ull << ( V_19 . V_97 . V_34 + 32 ) ) ) == 0 )
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_130 :
if ( V_2 -> V_2 [ V_19 . V_97 . V_37 ] & ( 1ull << V_19 . V_97 . V_34 ) )
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_131 :
if ( V_2 -> V_2 [ V_19 . V_97 . V_37 ] &
( 1ull << ( V_19 . V_97 . V_34 + 32 ) ) )
V_4 = V_4 + 4 + ( V_19 . V_97 . V_26 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
#endif
}
return V_96 ;
V_115:
F_18 ( L_1 , V_9 -> V_132 ) ;
F_4 ( V_133 , V_9 ) ;
return - V_78 ;
}
int F_19 ( struct V_1 * V_2 )
{
unsigned int V_7 * V_79 ;
long V_4 ;
union V_18 V_19 ;
V_4 = V_2 -> V_5 ;
if ( V_4 & 3 )
goto V_134;
V_79 = ( unsigned int V_7 * ) V_4 ;
if ( F_2 ( V_19 . V_73 , V_79 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_78 ;
}
return F_15 ( V_2 , V_19 ) ;
V_134:
F_18 ( L_2 , V_9 -> V_132 ) ;
F_4 ( V_133 , V_9 ) ;
return - V_78 ;
}
