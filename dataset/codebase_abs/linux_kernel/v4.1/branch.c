int F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 ;
long V_4 = V_2 -> V_5 ;
if ( F_2 ( V_3 , ( V_6 V_7 * ) F_3 ( V_4 ) ) ) {
F_4 ( V_8 , V_9 ) ;
return V_4 ;
}
if ( V_10 ) {
union V_11 V_12 ;
V_12 . V_13 = V_3 ;
if ( V_12 . V_14 . V_15 == V_16 )
V_4 += 4 ;
else
V_4 += 2 ;
} else if ( F_5 ( V_3 ) )
V_4 += 2 ;
else
V_4 += 4 ;
return V_4 ;
}
int F_6 ( struct V_1 * V_2 , struct V_17 V_18 ,
unsigned long * V_19 )
{
union V_20 V_21 = (union V_20 ) V_18 . V_21 ;
int V_22 = 0 ;
unsigned int V_23 ;
unsigned int V_24 ;
if ( ! V_25 )
return 0 ;
switch ( V_21 . V_26 . V_15 ) {
case V_27 :
if ( ( V_21 . V_26 . V_28 & V_29 ) ==
V_30 ) {
switch ( V_21 . V_26 . V_28 >>
V_31 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
if ( V_21 . V_26 . V_36 != 0 )
V_2 -> V_2 [ V_21 . V_26 . V_36 ] =
V_2 -> V_5 +
V_18 . V_37 +
V_18 . V_38 ;
* V_19 = V_2 -> V_2 [ V_21 . V_26 . V_39 ] ;
return 1 ;
}
}
break;
case V_40 :
switch ( V_21 . V_26 . V_36 ) {
case V_41 :
case V_42 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_18 . V_37 +
V_18 . V_38 ;
case V_43 :
if ( ( long ) V_2 -> V_2 [ V_21 . V_26 . V_39 ] < 0 )
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
( V_21 . V_26 . V_28 << 1 ) ;
else
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
V_18 . V_38 ;
return 1 ;
case V_44 :
case V_45 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_18 . V_37 +
V_18 . V_38 ;
case V_46 :
if ( ( long ) V_2 -> V_2 [ V_21 . V_26 . V_39 ] >= 0 )
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
( V_21 . V_26 . V_28 << 1 ) ;
else
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
V_18 . V_38 ;
return 1 ;
case V_47 :
if ( ( long ) V_2 -> V_2 [ V_21 . V_26 . V_39 ] <= 0 )
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
( V_21 . V_26 . V_28 << 1 ) ;
else
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
V_18 . V_38 ;
return 1 ;
case V_48 :
if ( ( long ) V_2 -> V_2 [ V_21 . V_26 . V_39 ] <= 0 )
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
( V_21 . V_26 . V_28 << 1 ) ;
else
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
V_18 . V_38 ;
return 1 ;
case V_49 :
case V_50 :
V_22 = 1 ;
case V_51 :
case V_52 :
F_7 () ;
if ( F_8 () )
V_23 = F_9 ( V_53 ) ;
else
V_23 = V_9 -> V_54 . V_55 . V_23 ;
F_10 () ;
if ( V_22 )
V_23 = ~ V_23 ;
V_24 = ( V_21 . V_26 . V_39 >> 2 ) ;
V_24 += ( V_24 != 0 ) ;
V_24 += 23 ;
if ( V_23 & ( 1 << V_24 ) )
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
( V_21 . V_26 . V_28 << 1 ) ;
else
* V_19 = V_2 -> V_5 +
V_18 . V_37 + V_18 . V_38 ;
return 1 ;
}
break;
case V_56 :
switch ( V_21 . V_26 . V_36 ) {
case V_57 :
case V_58 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_18 . V_37 + V_18 . V_38 ;
case V_59 :
* V_19 = V_2 -> V_2 [ V_21 . V_26 . V_39 ] ;
return 1 ;
}
break;
case V_60 :
if ( ( long ) V_2 -> V_2 [ V_61 [ V_21 . V_62 . V_39 ] ] == 0 )
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
( V_21 . V_62 . V_28 << 1 ) ;
else
* V_19 = V_2 -> V_5 +
V_18 . V_37 + V_18 . V_38 ;
return 1 ;
case V_63 :
if ( ( long ) V_2 -> V_2 [ V_61 [ V_21 . V_62 . V_39 ] ] != 0 )
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
( V_21 . V_62 . V_28 << 1 ) ;
else
* V_19 = V_2 -> V_5 +
V_18 . V_37 + V_18 . V_38 ;
return 1 ;
case V_64 :
* V_19 = V_2 -> V_5 + V_18 . V_37 +
( V_21 . V_65 . V_28 << 1 ) ;
return 1 ;
case V_66 :
if ( V_2 -> V_2 [ V_21 . V_26 . V_39 ] ==
V_2 -> V_2 [ V_21 . V_26 . V_36 ] )
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
( V_21 . V_26 . V_28 << 1 ) ;
else
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
V_18 . V_38 ;
return 1 ;
case V_67 :
if ( V_2 -> V_2 [ V_21 . V_26 . V_39 ] !=
V_2 -> V_2 [ V_21 . V_26 . V_36 ] )
* V_19 = V_2 -> V_5 +
V_18 . V_37 +
( V_21 . V_26 . V_28 << 1 ) ;
else
* V_19 = V_2 -> V_5 +
V_18 . V_37 + V_18 . V_38 ;
return 1 ;
case V_68 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_18 . V_37 + V_18 . V_38 ;
* V_19 = V_2 -> V_5 + V_18 . V_37 ;
* V_19 >>= 28 ;
* V_19 <<= 28 ;
* V_19 |= ( V_21 . V_69 . V_70 << 2 ) ;
return 1 ;
case V_71 :
case V_72 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 +
V_18 . V_37 + V_18 . V_38 ;
case V_73 :
* V_19 = V_2 -> V_5 + V_18 . V_37 ;
* V_19 >>= 27 ;
* V_19 <<= 27 ;
* V_19 |= ( V_21 . V_69 . V_70 << 1 ) ;
F_11 ( * V_19 ) ;
return 1 ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
V_6 V_7 * V_74 ;
V_6 V_75 ;
unsigned int V_76 ;
unsigned long V_19 ;
struct V_17 V_77 = { 0 } ;
V_77 . V_78 = 1 ;
V_74 = ( unsigned short V_7 * ) F_3 ( V_2 -> V_5 ) ;
F_2 ( V_75 , V_74 ) ;
V_74 ++ ;
V_19 = V_2 -> V_5 + 2 ;
V_76 = ( ( unsigned int ) V_75 << 16 ) ;
V_77 . V_37 = 2 ;
if ( ! F_5 ( V_75 ) ) {
F_2 ( V_75 , V_74 ) ;
V_74 ++ ;
V_19 = V_2 -> V_5 + 4 ;
V_77 . V_37 = 4 ;
V_76 |= V_75 ;
}
V_77 . V_21 = V_76 ;
if ( F_13 ( V_75 , V_74 ) )
goto V_79;
V_77 . V_38 = 2 ;
V_76 = ( ( unsigned int ) V_75 << 16 ) ;
if ( ! F_5 ( V_75 ) ) {
V_74 ++ ;
if ( F_13 ( V_75 , V_74 ) )
goto V_79;
V_77 . V_38 = 4 ;
V_76 |= V_75 ;
}
V_77 . V_80 = V_76 ;
F_14 ( V_2 , V_77 , & V_19 ) ;
V_2 -> V_5 = V_19 ;
return 0 ;
V_79:
F_4 ( V_8 , V_9 ) ;
return - V_81 ;
}
int F_15 ( struct V_1 * V_2 )
{
V_6 V_7 * V_82 ;
union V_11 V_3 ;
V_6 V_83 ;
T_1 V_84 ;
long V_4 ;
V_4 = V_2 -> V_5 ;
V_82 = ( V_6 V_7 * ) F_3 ( V_4 ) ;
if ( F_2 ( V_3 . V_13 , V_82 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_81 ;
}
switch ( V_3 . V_14 . V_15 ) {
case V_85 :
V_2 -> V_5 += 4 ;
return 0 ;
case V_16 :
V_82 += 1 ;
if ( F_2 ( V_83 , V_82 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_81 ;
}
V_84 = ( ( unsigned ) V_3 . V_13 << 16 ) | V_83 ;
V_2 -> V_2 [ 31 ] = V_4 + 6 ;
V_4 += 4 ;
V_4 >>= 28 ;
V_4 <<= 28 ;
V_4 |=
( ( V_84 & 0xffff ) << 2 ) | ( ( V_84 & 0x3e00000 ) >> 3 ) |
( ( V_84 & 0x1f0000 ) << 7 ) ;
if ( ! V_3 . V_86 . V_87 )
F_11 ( V_4 ) ;
V_2 -> V_5 = V_4 ;
return 0 ;
case V_88 :
if ( V_3 . V_89 . V_90 == V_91 ) {
if ( V_3 . V_89 . V_92 )
V_2 -> V_5 = V_2 -> V_2 [ 31 ] ;
else
V_2 -> V_5 =
V_2 -> V_2 [ V_93 [ V_3 . V_89 . V_94 ] ] ;
if ( V_3 . V_89 . V_95 ) {
if ( V_3 . V_89 . V_96 )
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
union V_20 V_21 )
{
unsigned int V_24 , V_23 , V_97 , V_98 ;
long V_4 = V_2 -> V_5 ;
int V_99 = 0 ;
switch ( V_21 . V_100 . V_15 ) {
case V_101 :
switch ( V_21 . V_102 . V_90 ) {
case V_103 :
V_2 -> V_2 [ V_21 . V_102 . V_104 ] = V_4 + 8 ;
case V_105 :
if ( V_106 && V_21 . V_102 . V_90 == V_105 )
goto V_107;
V_2 -> V_5 = V_2 -> V_2 [ V_21 . V_102 . V_39 ] ;
break;
}
break;
case V_108 :
switch ( V_21 . V_100 . V_36 ) {
case V_109 :
if ( V_106 )
goto V_107;
case V_110 :
if ( ( long ) V_2 -> V_2 [ V_21 . V_100 . V_39 ] < 0 ) {
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_36 == V_109 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_112 :
if ( V_106 )
goto V_107;
case V_113 :
if ( ( long ) V_2 -> V_2 [ V_21 . V_100 . V_39 ] >= 0 ) {
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_36 == V_112 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_114 :
case V_115 :
if ( V_106 && ( V_21 . V_100 . V_39 ||
V_21 . V_100 . V_36 == V_115 ) ) {
V_99 = - V_116 ;
break;
}
V_2 -> V_2 [ 31 ] = V_4 + 8 ;
if ( ! V_21 . V_100 . V_39 ) {
V_2 -> V_5 += 4 +
( V_21 . V_100 . V_28 << 2 ) ;
break;
}
if ( ( long ) V_2 -> V_2 [ V_21 . V_100 . V_39 ] < 0 ) {
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_36 == V_115 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_117 :
case V_118 :
if ( V_106 && ( V_21 . V_100 . V_39 ||
V_21 . V_100 . V_36 == V_118 ) ) {
V_99 = - V_116 ;
break;
}
V_2 -> V_2 [ 31 ] = V_4 + 8 ;
if ( ! V_21 . V_100 . V_39 ) {
V_2 -> V_5 += 4 +
( V_21 . V_100 . V_28 << 2 ) ;
break;
}
if ( ( long ) V_2 -> V_2 [ V_21 . V_100 . V_39 ] >= 0 ) {
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_36 == V_118 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_119 :
if ( ! V_120 )
goto V_121;
V_97 = F_17 ( 0x01 ) ;
if ( V_97 >= 32 ) {
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
}
break;
case V_122 :
V_2 -> V_2 [ 31 ] = V_2 -> V_5 + 8 ;
case V_123 :
V_4 += 4 ;
V_4 >>= 28 ;
V_4 <<= 28 ;
V_4 |= ( V_21 . V_69 . V_70 << 2 ) ;
V_2 -> V_5 = V_4 ;
if ( V_21 . V_100 . V_15 == V_124 )
F_11 ( V_2 -> V_5 ) ;
break;
case V_125 :
if ( V_106 )
goto V_107;
case V_126 :
if ( V_2 -> V_2 [ V_21 . V_100 . V_39 ] ==
V_2 -> V_2 [ V_21 . V_100 . V_36 ] ) {
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_15 == V_125 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_127 :
if ( V_106 )
goto V_107;
case V_128 :
if ( V_2 -> V_2 [ V_21 . V_100 . V_39 ] !=
V_2 -> V_2 [ V_21 . V_100 . V_36 ] ) {
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_15 == V_127 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_129 :
if ( V_106 )
goto V_107;
case V_130 :
if ( V_131 && V_21 . V_100 . V_36 ) {
if ( ( V_21 . V_100 . V_15 == V_130 ) &&
( ( ! V_21 . V_100 . V_39 && V_21 . V_100 . V_36 ) ||
( V_21 . V_100 . V_39 == V_21 . V_100 . V_36 ) ) )
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_2 -> V_5 += 8 ;
break;
}
if ( ( long ) V_2 -> V_2 [ V_21 . V_100 . V_39 ] <= 0 ) {
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_15 == V_129 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_132 :
if ( V_106 )
goto V_107;
case V_133 :
if ( V_131 && V_21 . V_100 . V_36 ) {
if ( ( V_21 . V_100 . V_15 == V_130 ) &&
( ( ! V_21 . V_100 . V_39 && V_21 . V_100 . V_36 ) ||
( V_21 . V_100 . V_39 == V_21 . V_100 . V_36 ) ) )
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_2 -> V_5 += 8 ;
break;
}
if ( ( long ) V_2 -> V_2 [ V_21 . V_100 . V_39 ] > 0 ) {
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_15 == V_132 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_134 :
if ( V_131 &&
( ( V_21 . V_100 . V_39 == V_135 ) ||
( V_21 . V_100 . V_39 == V_136 ) ) ) {
if ( ! F_18 () ) {
V_99 = F_19 () ;
if ( V_99 && V_106 ) {
V_99 = - V_99 ;
break;
}
V_99 = 0 ;
F_20 () ;
}
F_21 ( 1 ) ;
V_98 = V_21 . V_100 . V_36 ;
V_24 = 0 ;
switch ( V_21 . V_100 . V_39 ) {
case V_135 :
if ( F_22 ( & V_9 -> V_54 . V_55 . V_137 [ V_98 ] , 0 )
& 0x1 )
V_24 = 1 ;
break;
case V_136 :
if ( ! ( F_22 ( & V_9 -> V_54 . V_55 . V_137 [ V_98 ] , 0 )
& 0x1 ) )
V_24 = 1 ;
break;
}
F_23 ( 1 ) ;
if ( V_24 )
V_4 = V_4 + 4 +
( V_21 . V_100 . V_28 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
} else {
F_7 () ;
if ( F_8 () )
V_23 = F_9 ( V_53 ) ;
else
V_23 = V_9 -> V_54 . V_55 . V_23 ;
F_10 () ;
V_24 = ( V_21 . V_100 . V_36 >> 2 ) ;
V_24 += ( V_24 != 0 ) ;
V_24 += 23 ;
switch ( V_21 . V_100 . V_36 & 3 ) {
case 0 :
case 2 :
if ( ~ V_23 & ( 1 << V_24 ) ) {
V_4 = V_4 + 4 +
( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_36 == 2 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case 1 :
case 3 :
if ( V_23 & ( 1 << V_24 ) ) {
V_4 = V_4 + 4 +
( V_21 . V_100 . V_28 << 2 ) ;
if ( V_21 . V_100 . V_36 == 3 )
V_99 = V_111 ;
} else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
}
break;
}
#ifdef F_24
case V_138 :
if ( ( V_2 -> V_2 [ V_21 . V_100 . V_39 ] & ( 1ull << V_21 . V_100 . V_36 ) )
== 0 )
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_139 :
if ( ( V_2 -> V_2 [ V_21 . V_100 . V_39 ] &
( 1ull << ( V_21 . V_100 . V_36 + 32 ) ) ) == 0 )
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_140 :
if ( V_2 -> V_2 [ V_21 . V_100 . V_39 ] & ( 1ull << V_21 . V_100 . V_36 ) )
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
case V_141 :
if ( V_2 -> V_2 [ V_21 . V_100 . V_39 ] &
( 1ull << ( V_21 . V_100 . V_36 + 32 ) ) )
V_4 = V_4 + 4 + ( V_21 . V_100 . V_28 << 2 ) ;
else
V_4 += 8 ;
V_2 -> V_5 = V_4 ;
break;
#else
case V_142 :
if ( ! V_131 ) {
V_99 = - V_116 ;
break;
}
V_2 -> V_5 += 8 ;
break;
case V_143 :
if ( ! V_131 ) {
V_99 = - V_116 ;
break;
}
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_4 += 4 + ( V_21 . V_100 . V_28 << 2 ) ;
V_2 -> V_5 = V_4 ;
break;
case V_144 :
if ( ! V_131 ) {
V_99 = - V_116 ;
break;
}
V_2 -> V_5 += 8 ;
break;
case V_145 :
if ( ! V_131 ) {
V_99 = - V_116 ;
break;
}
if ( V_21 . V_100 . V_39 )
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_2 -> V_5 += 8 ;
break;
#endif
case V_146 :
case V_147 :
if ( ! V_131 ) {
V_99 = - V_116 ;
break;
}
if ( V_21 . V_100 . V_36 && ! V_21 . V_100 . V_39 )
V_2 -> V_2 [ 31 ] = V_4 + 4 ;
V_2 -> V_5 += 8 ;
break;
}
return V_99 ;
V_121:
F_25 ( L_1 , V_9 -> V_148 ) ;
F_4 ( V_149 , V_9 ) ;
return - V_81 ;
V_107:
F_26 ( L_2 ,
V_9 -> V_148 ) ;
F_4 ( V_116 , V_9 ) ;
return - V_81 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned int V_7 * V_82 ;
long V_4 ;
union V_20 V_21 ;
V_4 = V_2 -> V_5 ;
if ( V_4 & 3 )
goto V_150;
V_82 = ( unsigned int V_7 * ) V_4 ;
if ( F_2 ( V_21 . V_76 , V_82 ) ) {
F_4 ( V_8 , V_9 ) ;
return - V_81 ;
}
return F_16 ( V_2 , V_21 ) ;
V_150:
F_25 ( L_3 , V_9 -> V_148 ) ;
F_4 ( V_149 , V_9 ) ;
return - V_81 ;
}
