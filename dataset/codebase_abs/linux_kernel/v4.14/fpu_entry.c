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
if ( V_19 . V_37 ) {
V_6 . V_29 = V_38 ;
} else {
V_6 . V_29 = V_39 ;
}
V_27 += V_16 = F_8 ( & V_19 ) ;
V_17 = F_9 ( & V_19 ) + 1 ;
V_17 *= F_10 ( & V_19 ) ;
V_17 += V_16 - 1 ;
if ( V_17 < V_16 )
V_17 = 0xffffffff ;
}
V_40 = ! ( V_28 & V_41 ) ;
if ( ! F_11 ( & V_4 , ( T_1 T_4 * * ) & V_27 ,
& V_6 . V_42 ) ) {
V_43 ;
F_4
( L_5
L_6 ,
V_4 ) ;
V_24 ;
F_12 ( V_44 | 0x126 ) ;
F_6 ( V_25 , V_36 ) ;
}
V_45:
V_46 = 0 ;
V_27 ++ ;
if ( V_6 . V_29 ) {
if ( V_27 > V_17 )
F_6 ( V_25 , V_47 ) ;
}
if ( ( V_4 & 0xf8 ) != 0xd8 ) {
if ( V_4 == V_48 ) {
if ( V_49 & V_50 )
goto V_51;
else
goto V_52;
}
#ifdef F_13
F_12 ( V_44 | 0x128 ) ;
F_6 ( V_25 , V_36 ) ;
#endif
}
V_43 ;
F_14 ( 1 ) ;
F_15 ( V_3 , ( T_1 T_4 * ) V_27 ) ;
V_24 ;
V_27 ++ ;
if ( V_49 & V_50 ) {
V_5 = ( V_3 << 8 ) | V_4 ;
if ( ! ( ( ( ( V_5 & 0xf803 ) == 0xe003 ) ||
( ( ( V_5 & 0x3003 ) == 0x3001 ) &&
( ( V_5 & 0xc000 ) != 0xc000 ) ) ) ) ) {
V_51:
V_27 = V_26 ;
V_43 ;
V_21 -> V_22 . V_53 = V_54 ;
V_21 -> V_22 . V_55 = 0 ;
F_16 ( V_56 , V_21 , 1 ) ;
return;
}
}
V_15 . V_57 = V_26 ;
V_15 . V_58 = V_31 ;
V_15 . V_59 = ( V_4 << 8 ) | V_3 ;
V_15 . V_60 = 0 ;
V_61 = V_3 & 7 ;
if ( V_3 < 0300 ) {
if ( ( V_6 . V_29 & V_62 )
^ ( V_6 . V_42 . V_63 == V_64 ) )
V_12 =
F_17 ( V_3 , & V_27 ,
& V_14 , V_6 ) ;
else
V_12 =
F_18 ( V_3 , & V_27 , & V_14 ,
V_6 ) ;
if ( V_6 . V_29 ) {
if ( V_27 - 1 > V_17 )
F_6 ( V_25 , V_47 ) ;
}
if ( ! ( V_4 & 1 ) ) {
unsigned short V_65 = V_49 ;
V_9 = & F_19 ( 0 ) ;
V_11 = F_20 () ;
if ( V_66 ) {
if ( V_6 . V_29 & V_67 ) {
if ( V_68 <
V_69 [ ( V_4 >> 1 ) & 3 ] )
F_6 ( V_25 , V_47 ) ;
}
V_7 = 0 ;
switch ( ( V_4 >> 1 ) & 3 ) {
case 0 :
V_7 =
F_21 ( ( float T_4 * )
V_12 ,
& V_8 ) ;
V_10 = V_7 & 0xff ;
V_7 &= ~ 0xff ;
break;
case 1 :
V_10 =
F_22 ( ( long T_4 * )
V_12 ,
& V_8 ) ;
break;
case 2 :
V_7 =
F_23 ( ( double T_4 * )
V_12 ,
& V_8 ) ;
V_10 = V_7 & 0xff ;
V_7 &= ~ 0xff ;
break;
case 3 :
default:
V_10 =
F_24 ( ( short T_4 * )
V_12 ,
& V_8 ) ;
break;
}
if ( ( ( V_11 == V_70 ) && F_25 ( V_9 ) )
|| ( ( V_10 == V_70 )
&& F_25 ( & V_8 ) ) ) {
V_49 = V_65 ;
if ( ( V_3 & 0x30 ) == 0x10 ) {
F_12 ( V_71 ) ;
F_26 ( V_72 | V_73 | V_74 ) ;
if ( ( V_3 & 0x08 )
&& ( V_75 &
V_76 ) )
F_27 () ;
} else {
if ( V_10 == V_70 )
V_10 =
F_28
( & V_8 ) ;
#ifdef F_29
if ( ( V_3 & 0x28 ) == 0x20 )
F_30
( & V_8 ,
V_10 , 0 ,
& V_8 ) ;
else
#endif
F_30
( & V_8 ,
V_10 , 0 ,
V_9 ) ;
}
goto V_77;
}
if ( V_7 && ! ( ( V_3 & 0x30 ) == 0x10 ) ) {
if ( ( V_3 & 0x38 ) == 0x38 ) {
if ( ( V_11 == V_78 ) &&
( ( V_10 == V_79 )
|| ( V_10 ==
V_70
&&
F_31
( & V_8 ) ) ) ) {
if ( F_32
( 0 ,
F_33
( & V_8 ) )
< 0 ) {
V_49
&=
~ V_80 ;
V_49
|=
V_65 &
V_80 ;
} else
F_34 ( V_9 ,
F_33
( & V_8 ) ) ;
}
}
goto V_77;
}
switch ( ( V_3 >> 3 ) & 7 ) {
case 0 :
F_35 () ;
F_36 ( & V_8 , V_10 , 0 ,
V_75 ) ;
break;
case 1 :
F_35 () ;
F_37 ( & V_8 , V_10 , 0 ,
V_75 ) ;
break;
case 2 :
F_38 ( & V_8 ,
V_10 ) ;
break;
case 3 :
if ( ! F_38
( & V_8 , V_10 )
&& ! V_7 )
F_27 () ;
break;
case 4 :
F_35 () ;
F_39 ( V_81 | V_10 ,
( int ) & V_8 ,
V_75 ) ;
break;
case 5 :
F_35 () ;
F_39 ( V_82 | V_81 | V_10 ,
( int ) & V_8 ,
V_75 ) ;
break;
case 6 :
F_35 () ;
F_40 ( V_81 | V_10 ,
( int ) & V_8 ,
V_75 ) ;
break;
case 7 :
F_35 () ;
if ( V_11 == V_78 )
V_49 = V_65 ;
F_40 ( V_82 | V_81 | V_10 ,
( int ) & V_8 ,
V_75 ) ;
break;
}
} else {
if ( ( V_3 & 0x30 ) == 0x10 ) {
F_12 ( V_83 ) ;
F_26 ( V_72 | V_73 | V_74 ) ;
if ( ( V_3 & 0x08 )
&& ( V_75 & V_76 ) )
F_27 () ;
} else
F_41 () ;
}
V_77:
V_84 = V_14 ;
} else {
if ( ! ( V_46 =
F_42 ( ( ( V_3 & 0x38 ) | ( V_4 & 6 ) )
>> 1 , V_6 , V_12 ) ) ) {
V_84 = V_14 ;
}
}
} else {
T_1 V_85 = ( V_3 & 0x38 ) | ( V_4 & 7 ) ;
#ifdef F_29
V_84 . V_57 = 0 ;
V_84 . V_58 = V_33 ;
#endif
V_9 = & F_19 ( 0 ) ;
V_11 = F_20 () ;
switch ( V_86 [ ( int ) V_85 ] ) {
case V_87 :
break;
case V_88 :
if ( ! V_66 ) {
F_41 () ;
goto V_89;
}
break;
case V_90 :
if ( ! V_66 || ! F_43 ( V_61 ) ) {
F_44 ( V_61 ) ;
goto V_89;
}
break;
case V_91 :
if ( ! V_66 || ! F_43 ( V_61 ) ) {
F_45 ( V_61 ) ;
goto V_89;
}
break;
case V_92 :
if ( ! V_66 || ! F_43 ( V_61 ) ) {
F_41 () ;
goto V_89;
}
break;
case V_93 :
break;
case V_94 :
F_46 () ;
goto V_89;
default:
F_12 ( V_44 | 0x111 ) ;
goto V_89;
}
(* F_47 [ ( int ) V_85 ]) () ;
V_89:
;
}
if ( ! V_46 )
V_95 = V_15 ;
V_52:
#ifdef F_48
V_43 ;
F_49 () ;
V_24 ;
#endif
if ( V_40 && ! F_50 () ) {
V_26 = V_27 - V_16 ;
if ( F_11 ( & V_4 , ( T_1 T_4 * * ) & V_27 ,
& V_6 . V_42 ) )
goto V_45;
}
if ( V_6 . V_29 )
V_27 -= V_16 ;
V_43 ;
}
static int F_11 ( T_1 * V_96 , T_1 T_4 * * V_97 ,
T_5 * V_42 )
{
T_1 V_98 ;
T_1 T_4 * V_99 = * V_97 ;
* V_42 = ( T_5 ) {
0 , 0 , V_100 } ;
V_43 ;
F_14 ( 1 ) ;
F_15 ( V_98 , V_99 ) ;
V_24 ;
while ( 1 ) {
switch ( V_98 ) {
case V_64 :
V_42 -> V_63 = V_64 ;
goto V_101;
case V_102 :
V_42 -> V_103 = V_102 ;
goto V_101;
case V_104 :
V_42 -> V_105 = V_106 ;
goto V_101;
case V_107 :
V_42 -> V_105 = V_108 ;
goto V_101;
case V_109 :
V_42 -> V_105 = V_110 ;
goto V_101;
case V_111 :
V_42 -> V_105 = V_112 ;
goto V_101;
case V_113 :
V_42 -> V_105 = V_114 ;
goto V_101;
case V_115 :
V_42 -> V_105 = V_116 ;
goto V_101;
case V_117 :
case V_118 :
V_101:
V_99 ++ ;
V_43 ;
F_14 ( 1 ) ;
F_15 ( V_98 , V_99 ) ;
V_24 ;
break;
case V_48 :
* V_96 = V_98 ;
return 1 ;
default:
if ( ( V_98 & 0xf8 ) == 0xd8 ) {
* V_96 = V_98 ;
* V_97 = V_99 ;
return 1 ;
} else {
* V_96 = V_98 ;
return 0 ;
}
}
}
}
void F_6 ( struct V_1 * V_2 , unsigned int signal )
{
V_27 = V_26 ;
V_21 -> V_22 . V_53 = V_54 ;
V_21 -> V_22 . V_55 = 0 ;
F_16 ( signal , V_21 , 1 ) ;
V_43 ;
__asm__("movl %0,%%esp ; ret": :"g"(((long)info) - 4));
#ifdef F_13
F_4 ( L_7 ) ;
#endif
}
int F_51 ( struct V_119 * V_120 ,
const struct V_121 * V_122 ,
unsigned int V_123 , unsigned int V_124 ,
const void * V_125 , const void T_4 * V_126 )
{
struct V_127 * V_128 = & V_120 -> V_22 . V_20 . V_129 . V_130 ;
void * V_131 = V_128 -> V_132 ;
int V_133 ;
int V_57 , V_134 , V_135 , V_136 , V_137 , V_138 , V_139 ;
V_43 ;
V_133 = F_52 ( & V_123 , & V_124 , & V_125 , & V_126 , V_128 , 0 ,
F_53 ( struct V_127 , V_132 ) ) ;
V_24 ;
if ( V_133 )
return V_133 ;
V_140 -> V_141 = ( V_140 -> V_142 >> V_143 ) & 7 ;
V_57 = ( V_140 -> V_141 & 7 ) * 10 ;
V_134 = 80 - V_57 ;
V_43 ;
V_133 = F_52 ( & V_123 , & V_124 , & V_125 , & V_126 ,
V_131 + V_57 , 0 , V_134 ) ;
if ( ! V_133 && V_57 )
V_133 = F_52 ( & V_123 , & V_124 , & V_125 , & V_126 ,
V_131 , 0 , V_57 ) ;
V_24 ;
V_136 = V_140 -> V_144 ;
V_139 = V_140 -> V_141 ;
for ( V_135 = 0 ; V_135 < 8 ; V_135 ++ ) {
V_137 = ( V_135 + V_139 ) & 7 ;
if ( ( ( V_136 >> ( ( V_137 & 7 ) * 2 ) ) & 3 ) != V_145 ) {
V_138 =
F_54 ( ( T_3 * ) ( ( T_1 * ) V_140 -> V_132 +
10 * V_137 ) ) ;
V_136 &= ~ ( 3 << ( V_137 * 2 ) ) ;
V_136 |= ( V_138 & 3 ) << ( V_137 * 2 ) ;
}
}
V_140 -> V_144 = V_136 ;
return V_133 ;
}
int F_55 ( struct V_119 * V_120 ,
const struct V_121 * V_122 ,
unsigned int V_123 , unsigned int V_124 ,
void * V_125 , void T_4 * V_126 )
{
struct V_127 * V_128 = & V_120 -> V_22 . V_20 . V_129 . V_130 ;
const void * V_131 = V_128 -> V_132 ;
int V_133 ;
int V_57 = ( V_140 -> V_141 & 7 ) * 10 , V_134 = 80 - V_57 ;
V_43 ;
#ifdef F_29
V_140 -> V_146 &= ~ 0xe080 ;
V_140 -> V_146 |= 0xffff0040 ;
V_140 -> V_142 = F_56 () | 0xffff0000 ;
V_140 -> V_144 |= 0xffff0000 ;
V_140 -> V_147 &= ~ 0xf8000000 ;
V_140 -> V_148 |= 0xffff0000 ;
#endif
V_133 = F_57 ( & V_123 , & V_124 , & V_125 , & V_126 , V_128 , 0 ,
F_53 ( struct V_127 , V_132 ) ) ;
if ( ! V_133 )
V_133 = F_57 ( & V_123 , & V_124 , & V_125 , & V_126 ,
V_131 + V_57 , 0 , V_134 ) ;
if ( ! V_133 )
V_133 = F_57 ( & V_123 , & V_124 , & V_125 , & V_126 ,
V_131 , 0 , V_57 ) ;
V_24 ;
return V_133 ;
}
