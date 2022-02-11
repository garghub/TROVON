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
V_21 = F_9 ( V_51 ) ;
else
V_21 = V_9 -> V_52 . V_53 . V_21 ;
F_10 () ;
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
case V_54 :
switch ( V_19 . V_24 . V_34 ) {
case V_55 :
case V_56 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
case V_57 :
* V_17 = V_2 -> V_2 [ V_19 . V_24 . V_37 ] ;
return 1 ;
}
break;
case V_58 :
if ( ( long ) V_2 -> V_2 [ V_59 [ V_19 . V_60 . V_37 ] ] == 0 )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_60 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
return 1 ;
case V_61 :
if ( ( long ) V_2 -> V_2 [ V_59 [ V_19 . V_60 . V_37 ] ] != 0 )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_60 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
return 1 ;
case V_62 :
* V_17 = V_2 -> V_5 + V_16 . V_35 +
( V_19 . V_63 . V_26 << 1 ) ;
return 1 ;
case V_64 :
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
case V_65 :
if ( V_2 -> V_2 [ V_19 . V_24 . V_37 ] !=
V_2 -> V_2 [ V_19 . V_24 . V_34 ] )
* V_17 = V_2 -> V_5 +
V_16 . V_35 +
( V_19 . V_24 . V_26 << 1 ) ;
else
* V_17 = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
return 1 ;
case V_66 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
* V_17 = V_2 -> V_5 + V_16 . V_35 ;
* V_17 >>= 28 ;
* V_17 <<= 28 ;
* V_17 |= ( V_19 . V_67 . V_68 << 2 ) ;
return 1 ;
case V_69 :
case V_70 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_16 . V_35 + V_16 . V_36 ;
case V_71 :
* V_17 = V_2 -> V_5 + V_16 . V_35 ;
* V_17 >>= 27 ;
* V_17 <<= 27 ;
* V_17 |= ( V_19 . V_67 . V_68 << 1 ) ;
F_11 ( * V_17 ) ;
return 1 ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
V_6 V_7 * V_72 ;
V_6 V_73 ;
unsigned int V_74 ;
unsigned long V_17 ;
struct V_15 V_75 = { 0 } ;
V_75 . V_76 = 1 ;
V_72 = ( unsigned short V_7 * ) F_3 ( V_2 -> V_5 ) ;
F_2 ( V_73 , V_72 ) ;
V_72 ++ ;
V_17 = V_2 -> V_5 + 2 ;
V_74 = ( ( unsigned int ) V_73 << 16 ) ;
V_75 . V_35 = 2 ;
if ( ! F_5 ( V_73 ) ) {
F_2 ( V_73 , V_72 ) ;
V_72 ++ ;
V_17 = V_2 -> V_5 + 4 ;
V_75 . V_35 = 4 ;
V_74 |= V_73 ;
}
V_75 . V_19 = V_74 ;
if ( F_13 ( V_73 , V_72 ) )
goto V_77;
V_75 . V_36 = 2 ;
V_74 = ( ( unsigned int ) V_73 << 16 ) ;
if ( ! F_5 ( V_73 ) ) {
V_72 ++ ;
if ( F_13 ( V_73 , V_72 ) )
goto V_77;
V_75 . V_36 = 4 ;
V_74 |= V_73 ;
}
V_75 . V_78 = V_74 ;
F_14 ( V_2 , V_75 , & V_17 ) ;
V_2 -> V_5 = V_17 ;
return 0 ;
V_77:
F_4 ( V_8 , V_9 ) ;
return - V_79 ;
}
int F_15 ( struct V_1 * V_2 )
{
V_6 V_7 * V_80 ;
union V_11 V_3 ;
V_6 V_81 ;
T_1 V_82 ;
long V_4 ;
V_4 = V_2 -> V_5 ;
V_80 = ( V_6 V_7 * ) F_3 ( V_4 ) ;
if ( F_2 ( V_3 . V_83 , V_80 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_79 ;
}
switch ( V_3 . V_12 . V_13 ) {
case V_84 :
V_2 -> V_5 += 4 ;
return 0 ;
case V_14 :
V_80 += 1 ;
if ( F_2 ( V_81 , V_80 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_79 ;
}
V_82 = ( ( unsigned ) V_3 . V_83 << 16 ) | V_81 ;
V_2 -> V_2 [ 31 ] = V_4 + 6 ;
V_4 += 4 ;
V_4 >>= 28 ;
V_4 <<= 28 ;
V_4 |=
( ( V_82 & 0xffff ) << 2 ) | ( ( V_82 & 0x3e00000 ) >> 3 ) |
( ( V_82 & 0x1f0000 ) << 7 ) ;
if ( ! V_3 . V_85 . V_86 )
F_11 ( V_4 ) ;
V_2 -> V_5 = V_4 ;
return 0 ;
case V_87 :
if ( V_3 . V_88 . V_89 == V_90 ) {
if ( V_3 . V_88 . V_91 )
V_2 -> V_5 = V_2 -> V_2 [ 31 ] ;
else
V_2 -> V_5 =
V_2 -> V_2 [ V_92 [ V_3 . V_88 . V_93 ] ] ;
if ( V_3 . V_88 . V_94 ) {
if ( V_3 . V_88 . V_95 )
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
int F_16 ( struct V_1 * V_2 ,
union V_18 V_19 )
{
unsigned int V_22 , V_21 , V_96 , V_97 ;
long V_4 = V_2 -> V_5 ;
int V_98 = 0 ;
switch ( V_19 . V_99 . V_13 ) {
case V_100 :
switch ( V_19 . V_101 . V_89 ) {
case V_102 :
V_2 -> V_2 [ V_19 . V_101 . V_103 ] = V_4 + 8 ;
case V_104 :
if ( V_105 && V_19 . V_101 . V_89 == V_104 )
goto V_106;
V_2 -> V_5 = V_2 -> V_2 [ V_19 . V_101 . V_37 ] ;
break;
}
break;
case V_107 :
switch ( V_19 . V_99 . V_34 ) {
case V_108 :
if ( V_105 )
goto V_106;
case V_109 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_99 . V_37 ] < 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_34 == V_108 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_111 :
if ( V_105 )
goto V_106;
case V_112 :
if ( ( long ) V_2 -> V_2 [ V_19 . V_99 . V_37 ] >= 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_34 == V_111 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_113 :
case V_114 :
if ( V_105 && ( V_19 . V_99 . V_37 ||
V_19 . V_99 . V_34 == V_114 ) ) {
V_98 = - V_115 ;
break;
}
V_2 -> V_2 [ 31 ] = V_4 + 8 ;
if ( ! V_19 . V_99 . V_37 ) {
V_2 -> V_5 += 4 +
( V_19 . V_99 . V_26 << 2 ) ;
break;
}
if ( ( long ) V_2 -> V_2 [ V_19 . V_99 . V_37 ] < 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_34 == V_114 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_116 :
case V_117 :
if ( V_105 && ( V_19 . V_99 . V_37 ||
V_19 . V_99 . V_34 == V_117 ) ) {
V_98 = - V_115 ;
break;
}
V_2 -> V_2 [ 31 ] = V_4 + 8 ;
if ( ! V_19 . V_99 . V_37 ) {
V_2 -> V_5 += 4 +
( V_19 . V_99 . V_26 << 2 ) ;
break;
}
if ( ( long ) V_2 -> V_2 [ V_19 . V_99 . V_37 ] >= 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_34 == V_117 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_118 :
if ( ! V_119 )
goto V_120;
V_96 = F_17 ( 0x01 ) ;
if ( V_96 >= 32 ) {
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
}
break;
case V_121 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 + 8 ;
case V_122 :
V_4 += 4 ;
V_4 >>= 28 ;
V_4 <<= 28 ;
V_4 |= ( V_19 . V_67 . V_68 << 2 ) ;
V_2 -> V_5 = V_4 ;
if ( V_19 . V_99 . V_13 == V_123 )
F_11 ( V_2 -> V_5 ) ;
break;
case V_124 :
if ( V_105 )
goto V_106;
case V_125 :
if ( V_2 -> V_2 [ V_19 . V_99 . V_37 ] ==
V_2 -> V_2 [ V_19 . V_99 . V_34 ] ) {
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_13 == V_124 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_126 :
if ( V_105 )
goto V_106;
case V_127 :
if ( V_2 -> V_2 [ V_19 . V_99 . V_37 ] !=
V_2 -> V_2 [ V_19 . V_99 . V_34 ] ) {
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_13 == V_126 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_128 :
if ( V_105 )
goto V_106;
case V_129 :
if ( V_130 && V_19 . V_99 . V_34 ) {
if ( ( V_19 . V_99 . V_13 == V_129 ) &&
( ( ! V_19 . V_99 . V_37 && V_19 . V_99 . V_34 ) ||
( V_19 . V_99 . V_37 == V_19 . V_99 . V_34 ) ) )
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_2 -> V_5 += 8 ;
break;
}
if ( ( long ) V_2 -> V_2 [ V_19 . V_99 . V_37 ] <= 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_13 == V_128 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_131 :
if ( V_105 )
goto V_106;
case V_132 :
if ( V_130 && V_19 . V_99 . V_34 ) {
if ( ( V_19 . V_99 . V_13 == V_129 ) &&
( ( ! V_19 . V_99 . V_37 && V_19 . V_99 . V_34 ) ||
( V_19 . V_99 . V_37 == V_19 . V_99 . V_34 ) ) )
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_2 -> V_5 += 8 ;
break;
}
if ( ( long ) V_2 -> V_2 [ V_19 . V_99 . V_37 ] > 0 ) {
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_13 == V_131 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_133 :
if ( V_130 &&
( ( V_19 . V_99 . V_37 == V_134 ) ||
( V_19 . V_99 . V_37 == V_135 ) ) ) {
if ( ! F_18 () ) {
V_98 = F_19 () ;
if ( V_98 && V_105 ) {
V_98 = - V_98 ;
break;
}
V_98 = 0 ;
F_20 () ;
}
F_21 ( 1 ) ;
V_97 = V_19 . V_99 . V_34 ;
V_22 = 0 ;
switch ( V_19 . V_99 . V_37 ) {
case V_134 :
if ( F_22 ( & V_9 -> V_52 . V_53 . V_136 [ V_97 ] , 0 )
& 0x1 )
V_22 = 1 ;
break;
case V_135 :
if ( ! ( F_22 ( & V_9 -> V_52 . V_53 . V_136 [ V_97 ] , 0 )
& 0x1 ) )
V_22 = 1 ;
break;
}
F_23 ( 1 ) ;
if ( V_22 )
V_4 = V_4 + 4 +
( V_19 . V_99 . V_26 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
} else {
F_7 () ;
if ( F_8 () )
V_21 = F_9 ( V_51 ) ;
else
V_21 = V_9 -> V_52 . V_53 . V_21 ;
F_10 () ;
V_22 = ( V_19 . V_99 . V_34 >> 2 ) ;
V_22 += ( V_22 != 0 ) ;
V_22 += 23 ;
switch ( V_19 . V_99 . V_34 & 3 ) {
case 0 :
case 2 :
if ( ~ V_21 & ( 1 << V_22 ) ) {
V_4 = V_4 + 4 +
( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_34 == 2 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case 1 :
case 3 :
if ( V_21 & ( 1 << V_22 ) ) {
V_4 = V_4 + 4 +
( V_19 . V_99 . V_26 << 2 ) ;
if ( V_19 . V_99 . V_34 == 3 )
V_98 = V_110 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
}
break;
}
#ifdef F_24
case V_137 :
if ( ( V_2 -> V_2 [ V_19 . V_99 . V_37 ] & ( 1ull << V_19 . V_99 . V_34 ) )
== 0 )
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_138 :
if ( ( V_2 -> V_2 [ V_19 . V_99 . V_37 ] &
( 1ull << ( V_19 . V_99 . V_34 + 32 ) ) ) == 0 )
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_139 :
if ( V_2 -> V_2 [ V_19 . V_99 . V_37 ] & ( 1ull << V_19 . V_99 . V_34 ) )
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_140 :
if ( V_2 -> V_2 [ V_19 . V_99 . V_37 ] &
( 1ull << ( V_19 . V_99 . V_34 + 32 ) ) )
V_4 = V_4 + 4 + ( V_19 . V_99 . V_26 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
#else
case V_141 :
if ( ! V_130 ) {
V_98 = - V_115 ;
break;
}
V_2 -> V_5 += 8 ;
break;
case V_142 :
if ( ! V_130 ) {
V_98 = - V_115 ;
break;
}
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_4 += 4 + ( V_19 . V_99 . V_26 << 2 ) ;
V_2 -> V_5 = V_4 ;
break;
case V_143 :
if ( ! V_130 ) {
V_98 = - V_115 ;
break;
}
V_2 -> V_5 += 8 ;
break;
case V_144 :
if ( ! V_130 ) {
V_98 = - V_115 ;
break;
}
if ( V_19 . V_99 . V_37 )
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_2 -> V_5 += 8 ;
break;
#endif
case V_145 :
case V_146 :
if ( ! V_130 ) {
V_98 = - V_115 ;
break;
}
if ( V_19 . V_99 . V_34 && ! V_19 . V_99 . V_37 )
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_2 -> V_5 += 8 ;
break;
}
return V_98 ;
V_120:
F_25 ( L_1 , V_9 -> V_147 ) ;
F_4 ( V_148 , V_9 ) ;
return - V_79 ;
V_106:
F_26 ( L_2 ,
V_9 -> V_147 ) ;
F_4 ( V_115 , V_9 ) ;
return - V_79 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned int V_7 * V_80 ;
long V_4 ;
union V_18 V_19 ;
V_4 = V_2 -> V_5 ;
if ( V_4 & 3 )
goto V_149;
V_80 = ( unsigned int V_7 * ) V_4 ;
if ( F_2 ( V_19 . V_74 , V_80 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_79 ;
}
return F_16 ( V_2 , V_19 ) ;
V_149:
F_25 ( L_3 , V_9 -> V_147 ) ;
F_4 ( V_148 , V_9 ) ;
return - V_79 ;
}
