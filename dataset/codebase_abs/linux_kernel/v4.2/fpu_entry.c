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
struct V_20 * V_20 = & V_21 -> V_22 . V_20 ;
F_2 ( V_20 ) ;
#ifdef F_3
if ( V_23 ) {
F_4 ( L_1 ) ;
}
V_24 ;
#endif
V_25 = V_2 ;
V_26 = V_27 ;
if ( ( V_28 & 0x00020000 ) != 0 ) {
V_6 . V_29 = V_30 ;
V_27 += V_16 = V_31 << 4 ;
V_17 = V_16 + 0xffff ;
} else if ( V_31 == V_32 && V_33 == V_34 ) {
V_6 . V_29 = 0 ;
} else if ( V_31 == V_35 ) {
F_4 ( L_2 , V_31 , V_27 ) ;
F_5 ( L_3 ) ;
} else {
if ( ( V_31 & 4 ) != 4 ) {
F_4 ( L_4 ) ;
F_6 ( V_25 , V_36 ) ;
}
V_19 = F_7 ( V_31 ) ;
if ( F_8 ( V_19 ) ) {
V_6 . V_29 = V_37 ;
} else {
V_6 . V_29 = V_38 ;
}
V_27 += V_16 = F_9 ( V_19 ) ;
V_17 = V_16
+ ( F_10 ( V_19 ) +
1 ) * F_11 ( V_19 )
- 1 ;
if ( V_17 < V_16 )
V_17 = 0xffffffff ;
}
V_39 = ! ( V_28 & V_40 ) ;
if ( ! F_12 ( & V_4 , ( T_1 T_4 * * ) & V_27 ,
& V_6 . V_41 ) ) {
V_42 ;
F_4
( L_5
L_6 ,
V_4 ) ;
V_24 ;
F_13 ( V_43 | 0x126 ) ;
F_6 ( V_25 , V_36 ) ;
}
V_44:
V_45 = 0 ;
V_27 ++ ;
if ( V_6 . V_29 ) {
if ( V_27 > V_17 )
F_6 ( V_25 , V_46 ) ;
}
if ( ( V_4 & 0xf8 ) != 0xd8 ) {
if ( V_4 == V_47 ) {
if ( V_48 & V_49 )
goto V_50;
else
goto V_51;
}
#ifdef F_14
F_13 ( V_43 | 0x128 ) ;
F_6 ( V_25 , V_36 ) ;
#endif
}
V_42 ;
F_15 ( 1 ) ;
F_16 ( V_3 , ( T_1 T_4 * ) V_27 ) ;
V_24 ;
V_27 ++ ;
if ( V_48 & V_49 ) {
V_5 = ( V_3 << 8 ) | V_4 ;
if ( ! ( ( ( ( V_5 & 0xf803 ) == 0xe003 ) ||
( ( ( V_5 & 0x3003 ) == 0x3001 ) &&
( ( V_5 & 0xc000 ) != 0xc000 ) ) ) ) ) {
V_50:
V_27 = V_26 ;
V_42 ;
V_21 -> V_22 . V_52 = V_53 ;
V_21 -> V_22 . V_54 = 0 ;
F_17 ( V_55 , V_21 , 1 ) ;
return;
}
}
V_15 . V_56 = V_26 ;
V_15 . V_57 = V_31 ;
V_15 . V_58 = ( V_4 << 8 ) | V_3 ;
V_15 . V_59 = 0 ;
V_60 = V_3 & 7 ;
if ( V_3 < 0300 ) {
if ( ( V_6 . V_29 & V_61 )
^ ( V_6 . V_41 . V_62 == V_63 ) )
V_12 =
F_18 ( V_3 , & V_27 ,
& V_14 , V_6 ) ;
else
V_12 =
F_19 ( V_3 , & V_27 , & V_14 ,
V_6 ) ;
if ( V_6 . V_29 ) {
if ( V_27 - 1 > V_17 )
F_6 ( V_25 , V_46 ) ;
}
if ( ! ( V_4 & 1 ) ) {
unsigned short V_64 = V_48 ;
V_9 = & F_20 ( 0 ) ;
V_11 = F_21 () ;
if ( V_65 ) {
if ( V_6 . V_29 & V_66 ) {
if ( V_67 <
V_68 [ ( V_4 >> 1 ) & 3 ] )
F_6 ( V_25 , V_46 ) ;
}
V_7 = 0 ;
switch ( ( V_4 >> 1 ) & 3 ) {
case 0 :
V_7 =
F_22 ( ( float T_4 * )
V_12 ,
& V_8 ) ;
V_10 = V_7 & 0xff ;
V_7 &= ~ 0xff ;
break;
case 1 :
V_10 =
F_23 ( ( long T_4 * )
V_12 ,
& V_8 ) ;
break;
case 2 :
V_7 =
F_24 ( ( double T_4 * )
V_12 ,
& V_8 ) ;
V_10 = V_7 & 0xff ;
V_7 &= ~ 0xff ;
break;
case 3 :
default:
V_10 =
F_25 ( ( short T_4 * )
V_12 ,
& V_8 ) ;
break;
}
if ( ( ( V_11 == V_69 ) && F_26 ( V_9 ) )
|| ( ( V_10 == V_69 )
&& F_26 ( & V_8 ) ) ) {
V_48 = V_64 ;
if ( ( V_3 & 0x30 ) == 0x10 ) {
F_13 ( V_70 ) ;
F_27 ( V_71 | V_72 | V_73 ) ;
if ( ( V_3 & 0x08 )
&& ( V_74 &
V_75 ) )
F_28 () ;
} else {
if ( V_10 == V_69 )
V_10 =
F_29
( & V_8 ) ;
#ifdef F_30
if ( ( V_3 & 0x28 ) == 0x20 )
F_31
( & V_8 ,
V_10 , 0 ,
& V_8 ) ;
else
#endif
F_31
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
F_32
( & V_8 ) ) ) ) {
if ( F_33
( 0 ,
F_34
( & V_8 ) )
< 0 ) {
V_48
&=
~ V_79 ;
V_48
|=
V_64 &
V_79 ;
} else
F_35 ( V_9 ,
F_34
( & V_8 ) ) ;
}
}
goto V_76;
}
switch ( ( V_3 >> 3 ) & 7 ) {
case 0 :
F_36 () ;
F_37 ( & V_8 , V_10 , 0 ,
V_74 ) ;
break;
case 1 :
F_36 () ;
F_38 ( & V_8 , V_10 , 0 ,
V_74 ) ;
break;
case 2 :
F_39 ( & V_8 ,
V_10 ) ;
break;
case 3 :
if ( ! F_39
( & V_8 , V_10 )
&& ! V_7 )
F_28 () ;
break;
case 4 :
F_36 () ;
F_40 ( V_80 | V_10 ,
( int ) & V_8 ,
V_74 ) ;
break;
case 5 :
F_36 () ;
F_40 ( V_81 | V_80 | V_10 ,
( int ) & V_8 ,
V_74 ) ;
break;
case 6 :
F_36 () ;
F_41 ( V_80 | V_10 ,
( int ) & V_8 ,
V_74 ) ;
break;
case 7 :
F_36 () ;
if ( V_11 == V_77 )
V_48 = V_64 ;
F_41 ( V_81 | V_80 | V_10 ,
( int ) & V_8 ,
V_74 ) ;
break;
}
} else {
if ( ( V_3 & 0x30 ) == 0x10 ) {
F_13 ( V_82 ) ;
F_27 ( V_71 | V_72 | V_73 ) ;
if ( ( V_3 & 0x08 )
&& ( V_74 & V_75 ) )
F_28 () ;
} else
F_42 () ;
}
V_76:
V_83 = V_14 ;
} else {
if ( ! ( V_45 =
F_43 ( ( ( V_3 & 0x38 ) | ( V_4 & 6 ) )
>> 1 , V_6 , V_12 ) ) ) {
V_83 = V_14 ;
}
}
} else {
T_1 V_84 = ( V_3 & 0x38 ) | ( V_4 & 7 ) ;
#ifdef F_30
V_83 . V_56 = 0 ;
V_83 . V_57 = V_33 ;
#endif
V_9 = & F_20 ( 0 ) ;
V_11 = F_21 () ;
switch ( V_85 [ ( int ) V_84 ] ) {
case V_86 :
break;
case V_87 :
if ( ! V_65 ) {
F_42 () ;
goto V_88;
}
break;
case V_89 :
if ( ! V_65 || ! F_44 ( V_60 ) ) {
F_45 ( V_60 ) ;
goto V_88;
}
break;
case V_90 :
if ( ! V_65 || ! F_44 ( V_60 ) ) {
F_46 ( V_60 ) ;
goto V_88;
}
break;
case V_91 :
if ( ! V_65 || ! F_44 ( V_60 ) ) {
F_42 () ;
goto V_88;
}
break;
case V_92 :
break;
case V_93 :
F_47 () ;
goto V_88;
default:
F_13 ( V_43 | 0x111 ) ;
goto V_88;
}
(* F_48 [ ( int ) V_84 ]) () ;
V_88:
;
}
if ( ! V_45 )
V_94 = V_15 ;
V_51:
#ifdef F_49
V_42 ;
F_50 () ;
V_24 ;
#endif
if ( V_39 && ! F_51 () ) {
V_26 = V_27 - V_16 ;
if ( F_12 ( & V_4 , ( T_1 T_4 * * ) & V_27 ,
& V_6 . V_41 ) )
goto V_44;
}
if ( V_6 . V_29 )
V_27 -= V_16 ;
V_42 ;
}
static int F_12 ( T_1 * V_95 , T_1 T_4 * * V_96 ,
T_5 * V_41 )
{
T_1 V_97 ;
T_1 T_4 * V_98 = * V_96 ;
* V_41 = ( T_5 ) {
0 , 0 , V_99 } ;
V_42 ;
F_15 ( 1 ) ;
F_16 ( V_97 , V_98 ) ;
V_24 ;
while ( 1 ) {
switch ( V_97 ) {
case V_63 :
V_41 -> V_62 = V_63 ;
goto V_100;
case V_101 :
V_41 -> V_102 = V_101 ;
goto V_100;
case V_103 :
V_41 -> V_104 = V_105 ;
goto V_100;
case V_106 :
V_41 -> V_104 = V_107 ;
goto V_100;
case V_108 :
V_41 -> V_104 = V_109 ;
goto V_100;
case V_110 :
V_41 -> V_104 = V_111 ;
goto V_100;
case V_112 :
V_41 -> V_104 = V_113 ;
goto V_100;
case V_114 :
V_41 -> V_104 = V_115 ;
goto V_100;
case V_116 :
case V_117 :
V_100:
V_98 ++ ;
V_42 ;
F_15 ( 1 ) ;
F_16 ( V_97 , V_98 ) ;
V_24 ;
break;
case V_47 :
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
void F_6 ( struct V_1 * V_2 , unsigned int signal )
{
V_27 = V_26 ;
V_21 -> V_22 . V_52 = V_53 ;
V_21 -> V_22 . V_54 = 0 ;
F_17 ( signal , V_21 , 1 ) ;
V_42 ;
__asm__("movl %0,%%esp ; ret": :"g"(((long)info) - 4));
#ifdef F_14
F_4 ( L_7 ) ;
#endif
}
int F_52 ( struct V_118 * V_119 ,
const struct V_120 * V_121 ,
unsigned int V_122 , unsigned int V_123 ,
const void * V_124 , const void T_4 * V_125 )
{
struct V_126 * V_127 = & V_119 -> V_22 . V_20 . V_128 . V_129 ;
void * V_130 = V_127 -> V_131 ;
int V_132 ;
int V_56 , V_133 , V_134 , V_135 , V_136 , V_137 , V_138 ;
V_42 ;
V_132 = F_53 ( & V_122 , & V_123 , & V_124 , & V_125 , V_127 , 0 ,
F_54 ( struct V_126 , V_131 ) ) ;
V_24 ;
if ( V_132 )
return V_132 ;
V_139 -> V_140 = ( V_139 -> V_141 >> V_142 ) & 7 ;
V_56 = ( V_139 -> V_140 & 7 ) * 10 ;
V_133 = 80 - V_56 ;
V_42 ;
V_132 = F_53 ( & V_122 , & V_123 , & V_124 , & V_125 ,
V_130 + V_56 , 0 , V_133 ) ;
if ( ! V_132 && V_56 )
V_132 = F_53 ( & V_122 , & V_123 , & V_124 , & V_125 ,
V_130 , 0 , V_56 ) ;
V_24 ;
V_135 = V_139 -> V_143 ;
V_138 = V_139 -> V_140 ;
for ( V_134 = 0 ; V_134 < 8 ; V_134 ++ ) {
V_136 = ( V_134 + V_138 ) & 7 ;
if ( ( ( V_135 >> ( ( V_136 & 7 ) * 2 ) ) & 3 ) != V_144 ) {
V_137 =
F_55 ( ( T_3 * ) ( ( T_1 * ) V_139 -> V_131 +
10 * V_136 ) ) ;
V_135 &= ~ ( 3 << ( V_136 * 2 ) ) ;
V_135 |= ( V_137 & 3 ) << ( V_136 * 2 ) ;
}
}
V_139 -> V_143 = V_135 ;
return V_132 ;
}
int F_56 ( struct V_118 * V_119 ,
const struct V_120 * V_121 ,
unsigned int V_122 , unsigned int V_123 ,
void * V_124 , void T_4 * V_125 )
{
struct V_126 * V_127 = & V_119 -> V_22 . V_20 . V_128 . V_129 ;
const void * V_130 = V_127 -> V_131 ;
int V_132 ;
int V_56 = ( V_139 -> V_140 & 7 ) * 10 , V_133 = 80 - V_56 ;
V_42 ;
#ifdef F_30
V_139 -> V_145 &= ~ 0xe080 ;
V_139 -> V_145 |= 0xffff0040 ;
V_139 -> V_141 = F_57 () | 0xffff0000 ;
V_139 -> V_143 |= 0xffff0000 ;
V_139 -> V_146 &= ~ 0xf8000000 ;
V_139 -> V_147 |= 0xffff0000 ;
#endif
V_132 = F_58 ( & V_122 , & V_123 , & V_124 , & V_125 , V_127 , 0 ,
F_54 ( struct V_126 , V_131 ) ) ;
if ( ! V_132 )
V_132 = F_58 ( & V_122 , & V_123 , & V_124 , & V_125 ,
V_130 + V_56 , 0 , V_133 ) ;
if ( ! V_132 )
V_132 = F_58 ( & V_122 , & V_123 , & V_124 , & V_125 ,
V_130 , 0 , V_56 ) ;
V_24 ;
return V_132 ;
}
