void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
unsigned short V_5 ;
T_2 V_6 ;
int V_7 ;
T_3 V_8 ;
T_3 * V_9 ;
T_1 V_10 , V_11 ;
void T_4 * V_12 ;
struct V_13 V_14 ;
struct V_13 V_15 ;
unsigned long V_16 = 0 ;
unsigned long V_17 = 0 ;
struct V_18 V_19 ;
if ( ! F_2 () ) {
if ( F_3 ( V_20 ) ) {
F_4 ( V_21 ) ;
return;
}
}
#ifdef F_5
if ( V_22 ) {
F_6 ( L_1 ) ;
}
V_23 ;
#endif
V_24 = V_2 ;
V_25 = V_26 ;
if ( ( V_27 & 0x00020000 ) != 0 ) {
V_6 . V_28 = V_29 ;
V_26 += V_16 = V_30 << 4 ;
V_17 = V_16 + 0xffff ;
} else if ( V_30 == V_31 && V_32 == V_33 ) {
V_6 . V_28 = 0 ;
} else if ( V_30 == V_34 ) {
F_6 ( L_2 , V_30 , V_26 ) ;
F_7 ( L_3 ) ;
} else {
if ( ( V_30 & 4 ) != 4 ) {
F_6 ( L_4 ) ;
F_8 ( V_24 , V_35 ) ;
}
V_19 = F_9 ( V_30 ) ;
if ( F_10 ( V_19 ) ) {
V_6 . V_28 = V_36 ;
} else {
V_6 . V_28 = V_37 ;
}
V_26 += V_16 = F_11 ( V_19 ) ;
V_17 = V_16
+ ( F_12 ( V_19 ) +
1 ) * F_13 ( V_19 )
- 1 ;
if ( V_17 < V_16 )
V_17 = 0xffffffff ;
}
V_38 = ! ( V_27 & V_39 ) ;
if ( ! F_14 ( & V_4 , ( T_1 T_4 * * ) & V_26 ,
& V_6 . V_40 ) ) {
V_41 ;
F_6
( L_5
L_6 ,
V_4 ) ;
V_23 ;
F_15 ( V_42 | 0x126 ) ;
F_8 ( V_24 , V_35 ) ;
}
V_43:
V_44 = 0 ;
V_26 ++ ;
if ( V_6 . V_28 ) {
if ( V_26 > V_17 )
F_8 ( V_24 , V_45 ) ;
}
if ( ( V_4 & 0xf8 ) != 0xd8 ) {
if ( V_4 == V_46 ) {
if ( V_47 & V_48 )
goto V_49;
else
goto V_50;
}
#ifdef F_16
F_15 ( V_42 | 0x128 ) ;
F_8 ( V_24 , V_35 ) ;
#endif
}
V_41 ;
F_17 ( 1 ) ;
F_18 ( V_3 , ( T_1 T_4 * ) V_26 ) ;
V_23 ;
V_26 ++ ;
if ( V_47 & V_48 ) {
V_5 = ( V_3 << 8 ) | V_4 ;
if ( ! ( ( ( ( V_5 & 0xf803 ) == 0xe003 ) ||
( ( ( V_5 & 0x3003 ) == 0x3001 ) &&
( ( V_5 & 0xc000 ) != 0xc000 ) ) ) ) ) {
V_49:
V_26 = V_25 ;
V_41 ;
V_20 -> V_51 . V_52 = V_53 ;
V_20 -> V_51 . V_54 = 0 ;
F_19 ( V_55 , V_20 , 1 ) ;
return;
}
}
V_15 . V_56 = V_25 ;
V_15 . V_57 = V_30 ;
V_15 . V_58 = ( V_4 << 8 ) | V_3 ;
V_15 . V_59 = 0 ;
V_60 = V_3 & 7 ;
if ( V_3 < 0300 ) {
if ( ( V_6 . V_28 & V_61 )
^ ( V_6 . V_40 . V_62 == V_63 ) )
V_12 =
F_20 ( V_3 , & V_26 ,
& V_14 , V_6 ) ;
else
V_12 =
F_21 ( V_3 , & V_26 , & V_14 ,
V_6 ) ;
if ( V_6 . V_28 ) {
if ( V_26 - 1 > V_17 )
F_8 ( V_24 , V_45 ) ;
}
if ( ! ( V_4 & 1 ) ) {
unsigned short V_64 = V_47 ;
V_9 = & F_22 ( 0 ) ;
V_11 = F_23 () ;
if ( V_65 ) {
if ( V_6 . V_28 & V_66 ) {
if ( V_67 <
V_68 [ ( V_4 >> 1 ) & 3 ] )
F_8 ( V_24 , V_45 ) ;
}
V_7 = 0 ;
switch ( ( V_4 >> 1 ) & 3 ) {
case 0 :
V_7 =
F_24 ( ( float T_4 * )
V_12 ,
& V_8 ) ;
V_10 = V_7 & 0xff ;
V_7 &= ~ 0xff ;
break;
case 1 :
V_10 =
F_25 ( ( long T_4 * )
V_12 ,
& V_8 ) ;
break;
case 2 :
V_7 =
F_26 ( ( double T_4 * )
V_12 ,
& V_8 ) ;
V_10 = V_7 & 0xff ;
V_7 &= ~ 0xff ;
break;
case 3 :
default:
V_10 =
F_27 ( ( short T_4 * )
V_12 ,
& V_8 ) ;
break;
}
if ( ( ( V_11 == V_69 ) && F_28 ( V_9 ) )
|| ( ( V_10 == V_69 )
&& F_28 ( & V_8 ) ) ) {
V_47 = V_64 ;
if ( ( V_3 & 0x30 ) == 0x10 ) {
F_15 ( V_70 ) ;
F_29 ( V_71 | V_72 | V_73 ) ;
if ( ( V_3 & 0x08 )
&& ( V_74 &
V_75 ) )
F_30 () ;
} else {
if ( V_10 == V_69 )
V_10 =
F_31
( & V_8 ) ;
#ifdef F_32
if ( ( V_3 & 0x28 ) == 0x20 )
F_33
( & V_8 ,
V_10 , 0 ,
& V_8 ) ;
else
#endif
F_33
( & V_8 ,
V_10 , 0 ,
V_9 ) ;
}
goto V_76;
}
if ( V_7 && ! ( ( V_3 & 0x30 ) == 0x10 ) ) {
if ( ( V_3 & 0x38 ) == 0x38 ) {
if ( ( V_11 == V_77 ) &&
( ( V_10 == V_78 )
|| ( V_10 ==
V_69
&&
F_34
( & V_8 ) ) ) ) {
if ( F_35
( 0 ,
F_36
( & V_8 ) )
< 0 ) {
V_47
&=
~ V_79 ;
V_47
|=
V_64 &
V_79 ;
} else
F_37 ( V_9 ,
F_36
( & V_8 ) ) ;
}
}
goto V_76;
}
switch ( ( V_3 >> 3 ) & 7 ) {
case 0 :
F_38 () ;
F_39 ( & V_8 , V_10 , 0 ,
V_74 ) ;
break;
case 1 :
F_38 () ;
F_40 ( & V_8 , V_10 , 0 ,
V_74 ) ;
break;
case 2 :
F_41 ( & V_8 ,
V_10 ) ;
break;
case 3 :
if ( ! F_41
( & V_8 , V_10 )
&& ! V_7 )
F_30 () ;
break;
case 4 :
F_38 () ;
F_42 ( V_80 | V_10 ,
( int ) & V_8 ,
V_74 ) ;
break;
case 5 :
F_38 () ;
F_42 ( V_81 | V_80 | V_10 ,
( int ) & V_8 ,
V_74 ) ;
break;
case 6 :
F_38 () ;
F_43 ( V_80 | V_10 ,
( int ) & V_8 ,
V_74 ) ;
break;
case 7 :
F_38 () ;
if ( V_11 == V_77 )
V_47 = V_64 ;
F_43 ( V_81 | V_80 | V_10 ,
( int ) & V_8 ,
V_74 ) ;
break;
}
} else {
if ( ( V_3 & 0x30 ) == 0x10 ) {
F_15 ( V_82 ) ;
F_29 ( V_71 | V_72 | V_73 ) ;
if ( ( V_3 & 0x08 )
&& ( V_74 & V_75 ) )
F_30 () ;
} else
F_44 () ;
}
V_76:
V_83 = V_14 ;
} else {
if ( ! ( V_44 =
F_45 ( ( ( V_3 & 0x38 ) | ( V_4 & 6 ) )
>> 1 , V_6 , V_12 ) ) ) {
V_83 = V_14 ;
}
}
} else {
T_1 V_84 = ( V_3 & 0x38 ) | ( V_4 & 7 ) ;
#ifdef F_32
V_83 . V_56 = 0 ;
V_83 . V_57 = V_32 ;
#endif
V_9 = & F_22 ( 0 ) ;
V_11 = F_23 () ;
switch ( V_85 [ ( int ) V_84 ] ) {
case V_86 :
break;
case V_87 :
if ( ! V_65 ) {
F_44 () ;
goto V_88;
}
break;
case V_89 :
if ( ! V_65 || ! F_46 ( V_60 ) ) {
F_47 ( V_60 ) ;
goto V_88;
}
break;
case V_90 :
if ( ! V_65 || ! F_46 ( V_60 ) ) {
F_48 ( V_60 ) ;
goto V_88;
}
break;
case V_91 :
if ( ! V_65 || ! F_46 ( V_60 ) ) {
F_44 () ;
goto V_88;
}
break;
case V_92 :
break;
case V_93 :
F_49 () ;
goto V_88;
default:
F_15 ( V_42 | 0x111 ) ;
goto V_88;
}
(* F_50 [ ( int ) V_84 ]) () ;
V_88:
;
}
if ( ! V_44 )
V_94 = V_15 ;
V_50:
#ifdef F_51
V_41 ;
F_52 () ;
V_23 ;
#endif
if ( V_38 && ! F_53 () ) {
V_25 = V_26 - V_16 ;
if ( F_14 ( & V_4 , ( T_1 T_4 * * ) & V_26 ,
& V_6 . V_40 ) )
goto V_43;
}
if ( V_6 . V_28 )
V_26 -= V_16 ;
V_41 ;
}
static int F_14 ( T_1 * V_95 , T_1 T_4 * * V_96 ,
T_5 * V_40 )
{
T_1 V_97 ;
T_1 T_4 * V_98 = * V_96 ;
* V_40 = ( T_5 ) {
0 , 0 , V_99 } ;
V_41 ;
F_17 ( 1 ) ;
F_18 ( V_97 , V_98 ) ;
V_23 ;
while ( 1 ) {
switch ( V_97 ) {
case V_63 :
V_40 -> V_62 = V_63 ;
goto V_100;
case V_101 :
V_40 -> V_102 = V_101 ;
goto V_100;
case V_103 :
V_40 -> V_104 = V_105 ;
goto V_100;
case V_106 :
V_40 -> V_104 = V_107 ;
goto V_100;
case V_108 :
V_40 -> V_104 = V_109 ;
goto V_100;
case V_110 :
V_40 -> V_104 = V_111 ;
goto V_100;
case V_112 :
V_40 -> V_104 = V_113 ;
goto V_100;
case V_114 :
V_40 -> V_104 = V_115 ;
goto V_100;
case V_116 :
case V_117 :
V_100:
V_98 ++ ;
V_41 ;
F_17 ( 1 ) ;
F_18 ( V_97 , V_98 ) ;
V_23 ;
break;
case V_46 :
* V_95 = V_97 ;
return 1 ;
default:
if ( ( V_97 & 0xf8 ) == 0xd8 ) {
* V_95 = V_97 ;
* V_96 = V_98 ;
return 1 ;
} else {
* V_95 = V_97 ;
return 0 ;
}
}
}
}
void F_8 ( struct V_1 * V_2 , unsigned int signal )
{
V_26 = V_25 ;
V_20 -> V_51 . V_52 = V_53 ;
V_20 -> V_51 . V_54 = 0 ;
F_19 ( signal , V_20 , 1 ) ;
V_41 ;
__asm__("movl %0,%%esp ; ret": :"g"(((long)info) - 4));
#ifdef F_16
F_6 ( L_7 ) ;
#endif
}
int F_54 ( struct V_118 * V_119 ,
const struct V_120 * V_121 ,
unsigned int V_122 , unsigned int V_123 ,
const void * V_124 , const void T_4 * V_125 )
{
struct V_126 * V_127 = & V_119 -> V_51 . V_128 . V_129 -> V_130 ;
void * V_131 = V_127 -> V_132 ;
int V_133 ;
int V_56 , V_134 , V_135 , V_136 , V_137 , V_138 , V_139 ;
V_41 ;
V_133 = F_55 ( & V_122 , & V_123 , & V_124 , & V_125 , V_127 , 0 ,
F_56 ( struct V_126 , V_132 ) ) ;
V_23 ;
if ( V_133 )
return V_133 ;
V_140 -> V_141 = ( V_140 -> V_142 >> V_143 ) & 7 ;
V_56 = ( V_140 -> V_141 & 7 ) * 10 ;
V_134 = 80 - V_56 ;
V_41 ;
V_133 = F_55 ( & V_122 , & V_123 , & V_124 , & V_125 ,
V_131 + V_56 , 0 , V_134 ) ;
if ( ! V_133 && V_56 )
V_133 = F_55 ( & V_122 , & V_123 , & V_124 , & V_125 ,
V_131 , 0 , V_56 ) ;
V_23 ;
V_136 = V_140 -> V_144 ;
V_139 = V_140 -> V_141 ;
for ( V_135 = 0 ; V_135 < 8 ; V_135 ++ ) {
V_137 = ( V_135 + V_139 ) & 7 ;
if ( ( ( V_136 >> ( ( V_137 & 7 ) * 2 ) ) & 3 ) != V_145 ) {
V_138 =
F_57 ( ( T_3 * ) ( ( T_1 * ) V_140 -> V_132 +
10 * V_137 ) ) ;
V_136 &= ~ ( 3 << ( V_137 * 2 ) ) ;
V_136 |= ( V_138 & 3 ) << ( V_137 * 2 ) ;
}
}
V_140 -> V_144 = V_136 ;
return V_133 ;
}
int F_58 ( struct V_118 * V_119 ,
const struct V_120 * V_121 ,
unsigned int V_122 , unsigned int V_123 ,
void * V_124 , void T_4 * V_125 )
{
struct V_126 * V_127 = & V_119 -> V_51 . V_128 . V_129 -> V_130 ;
const void * V_131 = V_127 -> V_132 ;
int V_133 ;
int V_56 = ( V_140 -> V_141 & 7 ) * 10 , V_134 = 80 - V_56 ;
V_41 ;
#ifdef F_32
V_140 -> V_146 &= ~ 0xe080 ;
V_140 -> V_146 |= 0xffff0040 ;
V_140 -> V_142 = F_59 () | 0xffff0000 ;
V_140 -> V_144 |= 0xffff0000 ;
V_140 -> V_147 &= ~ 0xf8000000 ;
V_140 -> V_148 |= 0xffff0000 ;
#endif
V_133 = F_60 ( & V_122 , & V_123 , & V_124 , & V_125 , V_127 , 0 ,
F_56 ( struct V_126 , V_132 ) ) ;
if ( ! V_133 )
V_133 = F_60 ( & V_122 , & V_123 , & V_124 , & V_125 ,
V_131 + V_56 , 0 , V_134 ) ;
if ( ! V_133 )
V_133 = F_60 ( & V_122 , & V_123 , & V_124 , & V_125 ,
V_131 , 0 , V_56 ) ;
V_23 ;
return V_133 ;
}
