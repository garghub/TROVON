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
V_20 -> V_51 . V_52 = 16 ;
V_20 -> V_51 . V_53 = 0 ;
F_19 ( V_54 , V_20 , 1 ) ;
return;
}
}
V_15 . V_55 = V_25 ;
V_15 . V_56 = V_30 ;
V_15 . V_57 = ( V_4 << 8 ) | V_3 ;
V_15 . V_58 = 0 ;
V_59 = V_3 & 7 ;
if ( V_3 < 0300 ) {
if ( ( V_6 . V_28 & V_60 )
^ ( V_6 . V_40 . V_61 == V_62 ) )
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
unsigned short V_63 = V_47 ;
V_9 = & F_22 ( 0 ) ;
V_11 = F_23 () ;
if ( V_64 ) {
if ( V_6 . V_28 & V_65 ) {
if ( V_66 <
V_67 [ ( V_4 >> 1 ) & 3 ] )
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
if ( ( ( V_11 == V_68 ) && F_28 ( V_9 ) )
|| ( ( V_10 == V_68 )
&& F_28 ( & V_8 ) ) ) {
V_47 = V_63 ;
if ( ( V_3 & 0x30 ) == 0x10 ) {
F_15 ( V_69 ) ;
F_29 ( V_70 | V_71 | V_72 ) ;
if ( ( V_3 & 0x08 )
&& ( V_73 &
V_74 ) )
F_30 () ;
} else {
if ( V_10 == V_68 )
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
goto V_75;
}
if ( V_7 && ! ( ( V_3 & 0x30 ) == 0x10 ) ) {
if ( ( V_3 & 0x38 ) == 0x38 ) {
if ( ( V_11 == V_76 ) &&
( ( V_10 == V_77 )
|| ( V_10 ==
V_68
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
~ V_78 ;
V_47
|=
V_63 &
V_78 ;
} else
F_37 ( V_9 ,
F_36
( & V_8 ) ) ;
}
}
goto V_75;
}
switch ( ( V_3 >> 3 ) & 7 ) {
case 0 :
F_38 () ;
F_39 ( & V_8 , V_10 , 0 ,
V_73 ) ;
break;
case 1 :
F_38 () ;
F_40 ( & V_8 , V_10 , 0 ,
V_73 ) ;
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
F_42 ( V_79 | V_10 ,
( int ) & V_8 ,
V_73 ) ;
break;
case 5 :
F_38 () ;
F_42 ( V_80 | V_79 | V_10 ,
( int ) & V_8 ,
V_73 ) ;
break;
case 6 :
F_38 () ;
F_43 ( V_79 | V_10 ,
( int ) & V_8 ,
V_73 ) ;
break;
case 7 :
F_38 () ;
if ( V_11 == V_76 )
V_47 = V_63 ;
F_43 ( V_80 | V_79 | V_10 ,
( int ) & V_8 ,
V_73 ) ;
break;
}
} else {
if ( ( V_3 & 0x30 ) == 0x10 ) {
F_15 ( V_81 ) ;
F_29 ( V_70 | V_71 | V_72 ) ;
if ( ( V_3 & 0x08 )
&& ( V_73 & V_74 ) )
F_30 () ;
} else
F_44 () ;
}
V_75:
V_82 = V_14 ;
} else {
if ( ! ( V_44 =
F_45 ( ( ( V_3 & 0x38 ) | ( V_4 & 6 ) )
>> 1 , V_6 , V_12 ) ) ) {
V_82 = V_14 ;
}
}
} else {
T_1 V_83 = ( V_3 & 0x38 ) | ( V_4 & 7 ) ;
#ifdef F_32
V_82 . V_55 = 0 ;
V_82 . V_56 = V_32 ;
#endif
V_9 = & F_22 ( 0 ) ;
V_11 = F_23 () ;
switch ( V_84 [ ( int ) V_83 ] ) {
case V_85 :
break;
case V_86 :
if ( ! V_64 ) {
F_44 () ;
goto V_87;
}
break;
case V_88 :
if ( ! V_64 || ! F_46 ( V_59 ) ) {
F_47 ( V_59 ) ;
goto V_87;
}
break;
case V_89 :
if ( ! V_64 || ! F_46 ( V_59 ) ) {
F_48 ( V_59 ) ;
goto V_87;
}
break;
case V_90 :
if ( ! V_64 || ! F_46 ( V_59 ) ) {
F_44 () ;
goto V_87;
}
break;
case V_91 :
break;
case V_92 :
F_49 () ;
goto V_87;
default:
F_15 ( V_42 | 0x111 ) ;
goto V_87;
}
(* F_50 [ ( int ) V_83 ]) () ;
V_87:
;
}
if ( ! V_44 )
V_93 = V_15 ;
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
static int F_14 ( T_1 * V_94 , T_1 T_4 * * V_95 ,
T_5 * V_40 )
{
T_1 V_96 ;
T_1 T_4 * V_97 = * V_95 ;
* V_40 = ( T_5 ) {
0 , 0 , V_98 } ;
V_41 ;
F_17 ( 1 ) ;
F_18 ( V_96 , V_97 ) ;
V_23 ;
while ( 1 ) {
switch ( V_96 ) {
case V_62 :
V_40 -> V_61 = V_62 ;
goto V_99;
case V_100 :
V_40 -> V_101 = V_100 ;
goto V_99;
case V_102 :
V_40 -> V_103 = V_104 ;
goto V_99;
case V_105 :
V_40 -> V_103 = V_106 ;
goto V_99;
case V_107 :
V_40 -> V_103 = V_108 ;
goto V_99;
case V_109 :
V_40 -> V_103 = V_110 ;
goto V_99;
case V_111 :
V_40 -> V_103 = V_112 ;
goto V_99;
case V_113 :
V_40 -> V_103 = V_114 ;
goto V_99;
case V_115 :
case V_116 :
V_99:
V_97 ++ ;
V_41 ;
F_17 ( 1 ) ;
F_18 ( V_96 , V_97 ) ;
V_23 ;
break;
case V_46 :
* V_94 = V_96 ;
return 1 ;
default:
if ( ( V_96 & 0xf8 ) == 0xd8 ) {
* V_94 = V_96 ;
* V_95 = V_97 ;
return 1 ;
} else {
* V_94 = V_96 ;
return 0 ;
}
}
}
}
void F_8 ( struct V_1 * V_2 , unsigned int signal )
{
V_26 = V_25 ;
V_20 -> V_51 . V_52 = 16 ;
V_20 -> V_51 . V_53 = 0 ;
F_19 ( signal , V_20 , 1 ) ;
V_41 ;
__asm__("movl %0,%%esp ; ret": :"g"(((long)info) - 4));
#ifdef F_16
F_6 ( L_7 ) ;
#endif
}
int F_54 ( struct V_117 * V_118 ,
const struct V_119 * V_120 ,
unsigned int V_121 , unsigned int V_122 ,
const void * V_123 , const void T_4 * V_124 )
{
struct V_125 * V_126 = & V_118 -> V_51 . V_127 . V_128 -> V_129 ;
void * V_130 = V_126 -> V_131 ;
int V_132 ;
int V_55 , V_133 , V_134 , V_135 , V_136 , V_137 , V_138 ;
V_41 ;
V_132 = F_55 ( & V_121 , & V_122 , & V_123 , & V_124 , V_126 , 0 ,
F_56 ( struct V_125 , V_131 ) ) ;
V_23 ;
if ( V_132 )
return V_132 ;
V_139 -> V_140 = ( V_139 -> V_141 >> V_142 ) & 7 ;
V_55 = ( V_139 -> V_140 & 7 ) * 10 ;
V_133 = 80 - V_55 ;
V_41 ;
V_132 = F_55 ( & V_121 , & V_122 , & V_123 , & V_124 ,
V_130 + V_55 , 0 , V_133 ) ;
if ( ! V_132 && V_55 )
V_132 = F_55 ( & V_121 , & V_122 , & V_123 , & V_124 ,
V_130 , 0 , V_55 ) ;
V_23 ;
V_135 = V_139 -> V_143 ;
V_138 = V_139 -> V_140 ;
for ( V_134 = 0 ; V_134 < 8 ; V_134 ++ ) {
V_136 = ( V_134 + V_138 ) & 7 ;
if ( ( ( V_135 >> ( ( V_136 & 7 ) * 2 ) ) & 3 ) != V_144 ) {
V_137 =
F_57 ( ( T_3 * ) ( ( T_1 * ) V_139 -> V_131 +
10 * V_136 ) ) ;
V_135 &= ~ ( 3 << ( V_136 * 2 ) ) ;
V_135 |= ( V_137 & 3 ) << ( V_136 * 2 ) ;
}
}
V_139 -> V_143 = V_135 ;
return V_132 ;
}
int F_58 ( struct V_117 * V_118 ,
const struct V_119 * V_120 ,
unsigned int V_121 , unsigned int V_122 ,
void * V_123 , void T_4 * V_124 )
{
struct V_125 * V_126 = & V_118 -> V_51 . V_127 . V_128 -> V_129 ;
const void * V_130 = V_126 -> V_131 ;
int V_132 ;
int V_55 = ( V_139 -> V_140 & 7 ) * 10 , V_133 = 80 - V_55 ;
V_41 ;
#ifdef F_32
V_139 -> V_145 &= ~ 0xe080 ;
V_139 -> V_145 |= 0xffff0040 ;
V_139 -> V_141 = F_59 () | 0xffff0000 ;
V_139 -> V_143 |= 0xffff0000 ;
V_139 -> V_146 &= ~ 0xf8000000 ;
V_139 -> V_147 |= 0xffff0000 ;
#endif
V_132 = F_60 ( & V_121 , & V_122 , & V_123 , & V_124 , V_126 , 0 ,
F_56 ( struct V_125 , V_131 ) ) ;
if ( ! V_132 )
V_132 = F_60 ( & V_121 , & V_122 , & V_123 , & V_124 ,
V_130 + V_55 , 0 , V_133 ) ;
if ( ! V_132 )
V_132 = F_60 ( & V_121 , & V_122 , & V_123 , & V_124 ,
V_130 , 0 , V_55 ) ;
V_23 ;
return V_132 ;
}
