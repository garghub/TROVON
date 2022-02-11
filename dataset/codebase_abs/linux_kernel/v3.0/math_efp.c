static unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 = V_3 ;
switch ( V_1 & 0x7ff ) {
case V_4 : V_2 = V_5 ; break;
case V_6 : V_2 = V_7 ; break;
case V_8 : V_2 = V_9 ; break;
case V_10 : V_2 = V_11 ; break;
case V_12 : V_2 = V_11 ; break;
case V_13 : V_2 = V_11 ; break;
case V_14 : V_2 = V_9 ; break;
case V_15 : V_2 = V_9 ; break;
case V_16 : V_2 = V_9 ; break;
case V_17 : V_2 = V_9 ; break;
case V_18 : V_2 = V_9 ; break;
case V_19 : V_2 = V_9 ; break;
case V_20 : V_2 = V_7 ; break;
case V_21 : V_2 = V_7 ; break;
case V_22 : V_2 = V_5 ; break;
case V_23 : V_2 = V_5 ; break;
case V_24 : V_2 = V_7 ; break;
case V_25 : V_2 = V_9 ; break;
case V_26 : V_2 = V_5 ; break;
case V_27 : V_2 = V_7 ; break;
case V_28 : V_2 = V_11 ; break;
case V_29 : V_2 = V_11 ; break;
case V_30 : V_2 = V_11 ; break;
case V_31 : V_2 = V_9 ; break;
case V_32 : V_2 = V_9 ; break;
case V_33 : V_2 = V_9 ; break;
case V_34 : V_2 = V_9 ; break;
case V_35 : V_2 = V_9 ; break;
case V_36 : V_2 = V_9 ; break;
case V_37 : V_2 = V_7 ; break;
case V_38 : V_2 = V_7 ; break;
case V_39 : V_2 = V_5 ; break;
case V_40 : V_2 = V_5 ; break;
case V_41 : V_2 = V_7 ; break;
case V_42 : V_2 = V_5 ; break;
case V_43 : V_2 = V_7 ; break;
case V_44 : V_2 = V_9 ; break;
case V_45 : V_2 = V_11 ; break;
case V_46 : V_2 = V_11 ; break;
case V_47 : V_2 = V_11 ; break;
case V_48 : V_2 = V_9 ; break;
case V_49 : V_2 = V_9 ; break;
case V_50 : V_2 = V_9 ; break;
case V_51 : V_2 = V_9 ; break;
case V_52 : V_2 = V_9 ; break;
case V_53 : V_2 = V_9 ; break;
case V_54 : V_2 = V_9 ; break;
case V_55 : V_2 = V_9 ; break;
case V_56 : V_2 = V_7 ; break;
case V_57 : V_2 = V_7 ; break;
case V_58 : V_2 = V_5 ; break;
case V_59 : V_2 = V_5 ; break;
case V_60 : V_2 = V_7 ; break;
default:
F_2 ( V_61 L_1 ) ;
F_2 ( V_61 L_2 , V_1 ) ;
}
return V_2 ;
}
int F_3 ( struct V_62 * V_63 )
{
V_64 ;
int V_65 , V_66 ;
unsigned long type , V_67 , V_68 , V_69 , V_70 , V_71 , V_1 ;
union V_72 V_73 , V_74 , V_75 ;
if ( F_4 ( V_1 , ( unsigned int V_76 * ) V_63 -> V_77 ) )
return - V_78 ;
if ( ( V_1 >> 26 ) != V_79 )
return - V_80 ;
type = F_1 ( V_1 ) ;
if ( type == V_3 )
return - V_81 ;
V_67 = V_1 & 0x7ff ;
V_68 = ( V_1 >> 21 ) & 0x1f ;
V_69 = ( V_1 >> 16 ) & 0x1f ;
V_70 = ( V_1 >> 11 ) & 0x1f ;
V_71 = ( V_1 >> 5 ) & 0x7 ;
V_73 . V_82 [ 0 ] = V_83 -> V_84 . V_85 [ V_68 ] ;
V_73 . V_82 [ 1 ] = V_63 -> V_86 [ V_68 ] ;
V_74 . V_82 [ 0 ] = V_83 -> V_84 . V_85 [ V_69 ] ;
V_74 . V_82 [ 1 ] = V_63 -> V_86 [ V_69 ] ;
V_75 . V_82 [ 0 ] = V_83 -> V_84 . V_85 [ V_70 ] ;
V_75 . V_82 [ 1 ] = V_63 -> V_86 [ V_70 ] ;
V_87 = F_5 ( V_88 ) ;
#ifdef F_6
F_2 ( L_3 , V_1 , V_87 ) ;
F_2 ( L_4 , V_73 . V_82 [ 0 ] , V_73 . V_82 [ 1 ] ) ;
F_2 ( L_5 , V_74 . V_82 [ 0 ] , V_74 . V_82 [ 1 ] ) ;
F_2 ( L_6 , V_75 . V_82 [ 0 ] , V_75 . V_82 [ 1 ] ) ;
#endif
switch ( V_71 ) {
case V_89 : {
F_7 ( V_90 ) ; F_7 ( V_91 ) ; F_7 ( V_92 ) ;
switch ( type ) {
case V_7 :
case V_11 :
F_8 ( V_90 , V_74 . V_82 + 1 ) ;
case V_9 :
F_8 ( V_91 , V_75 . V_82 + 1 ) ;
break;
case V_5 :
F_8 ( V_90 , V_74 . V_82 + 1 ) ;
break;
}
#ifdef F_6
F_2 ( L_7 , V_93 , V_94 , V_95 , V_96 ) ;
F_2 ( L_8 , V_97 , V_98 , V_99 , V_100 ) ;
#endif
switch ( V_67 ) {
case V_4 :
V_73 . V_82 [ 1 ] = V_74 . V_82 [ 1 ] & ~ V_101 ;
goto V_102;
case V_22 :
V_73 . V_82 [ 1 ] = V_74 . V_82 [ 1 ] | V_101 ;
goto V_102;
case V_23 :
V_73 . V_82 [ 1 ] = V_74 . V_82 [ 1 ] ^ V_101 ;
goto V_102;
case V_6 :
F_9 ( V_92 , V_90 , V_91 ) ;
goto V_103;
case V_24 :
F_10 ( V_92 , V_90 , V_91 ) ;
goto V_103;
case V_21 :
F_11 ( V_92 , V_90 , V_91 ) ;
goto V_103;
case V_20 :
F_12 ( V_92 , V_90 , V_91 ) ;
goto V_103;
case V_10 :
V_66 = 0 ;
goto V_104;
case V_12 :
V_66 = 1 ;
goto V_104;
case V_13 :
V_66 = - 1 ;
goto V_104;
case V_14 :
case V_17 :
if ( ! ( ( V_75 . V_82 [ 1 ] >> 23 ) == 0xff && ( ( V_75 . V_82 [ 1 ] & 0x7fffff ) > 0 ) ) ) {
if ( ( ( V_75 . V_82 [ 1 ] >> 23 ) & 0xff ) == 0 ) {
V_73 . V_82 [ 1 ] = 0x0 ;
} else if ( ( V_75 . V_82 [ 1 ] >> 31 ) == 0 ) {
V_73 . V_82 [ 1 ] = ( V_67 == V_14 ) ?
0x7fffffff : 0xffffffff ;
} else {
V_73 . V_82 [ 1 ] = ( V_67 == V_14 ) ?
0x80000000 : 0x0 ;
}
} else {
V_73 . V_82 [ 1 ] = 0x0 ;
}
goto V_102;
case V_8 : {
F_13 ( V_105 ) ;
V_106 ;
F_14 ( V_105 , V_75 . V_107 ) ;
#ifdef F_6
F_2 ( L_9 ,
V_108 , V_109 , V_110 , V_111 , V_112 ) ;
#endif
F_15 ( V_113 , V_114 , 1 , 2 , V_92 , V_105 ) ;
goto V_103;
}
case V_15 :
case V_16 :
case V_18 :
case V_19 :
if ( V_67 & 0x4 ) {
F_16 ( 1 , V_91 ) ;
} else {
F_17 ( 1 , V_91 ) ;
}
F_18 ( V_73 . V_82 [ 1 ] , V_91 , 32 ,
( ( ( V_67 & 0x3 ) != 0 ) || V_97 ) ) ;
goto V_102;
default:
goto V_115;
}
break;
V_103:
#ifdef F_6
F_2 ( L_10 , V_116 , V_117 , V_118 , V_119 ) ;
#endif
F_19 ( V_73 . V_82 + 1 , V_92 ) ;
goto V_102;
V_104:
F_20 ( V_65 , V_90 , V_91 , 3 ) ;
if ( V_65 == 3 && ( F_21 ( V_90 ) || F_21 ( V_91 ) ) )
F_22 ( V_120 ) ;
if ( V_65 == V_66 ) {
V_65 = 0x4 ;
} else {
V_65 = 0 ;
}
goto V_121;
}
case V_122 : {
F_13 ( V_123 ) ; F_13 ( V_105 ) ; F_13 ( V_124 ) ;
switch ( type ) {
case V_7 :
case V_11 :
F_14 ( V_123 , V_74 . V_107 ) ;
case V_9 :
F_14 ( V_105 , V_75 . V_107 ) ;
break;
case V_5 :
F_14 ( V_123 , V_74 . V_107 ) ;
break;
}
#ifdef F_6
F_2 ( L_11 ,
V_125 , V_126 , V_127 , V_128 , V_129 ) ;
F_2 ( L_9 ,
V_108 , V_109 , V_110 , V_111 , V_112 ) ;
#endif
switch ( V_67 ) {
case V_42 :
V_73 . V_107 [ 0 ] = V_74 . V_107 [ 0 ] & ~ V_130 ;
goto V_102;
case V_58 :
V_73 . V_107 [ 0 ] = V_74 . V_107 [ 0 ] | V_130 ;
goto V_102;
case V_59 :
V_73 . V_107 [ 0 ] = V_74 . V_107 [ 0 ] ^ V_130 ;
goto V_102;
case V_43 :
F_23 ( V_124 , V_123 , V_105 ) ;
goto V_131;
case V_60 :
F_24 ( V_124 , V_123 , V_105 ) ;
goto V_131;
case V_57 :
F_25 ( V_124 , V_123 , V_105 ) ;
goto V_131;
case V_56 :
F_26 ( V_124 , V_123 , V_105 ) ;
goto V_131;
case V_45 :
V_66 = 0 ;
goto V_132;
case V_46 :
V_66 = 1 ;
goto V_132;
case V_47 :
V_66 = - 1 ;
goto V_132;
case V_48 :
case V_52 :
if ( ! ( ( V_75 . V_82 [ 0 ] >> 20 ) == 0x7ff &&
( ( V_75 . V_82 [ 0 ] & 0xfffff ) > 0 || ( V_75 . V_82 [ 1 ] > 0 ) ) ) ) {
if ( ( ( V_75 . V_82 [ 0 ] >> 20 ) & 0x7ff ) == 0 ) {
V_73 . V_82 [ 1 ] = 0x0 ;
} else if ( ( V_75 . V_82 [ 0 ] >> 31 ) == 0 ) {
V_73 . V_82 [ 1 ] = ( V_67 == V_48 ) ?
0x7fffffff : 0xffffffff ;
} else {
V_73 . V_82 [ 1 ] = ( V_67 == V_48 ) ?
0x80000000 : 0x0 ;
}
} else {
V_73 . V_82 [ 1 ] = 0x0 ;
}
goto V_102;
case V_44 : {
F_7 ( V_91 ) ;
V_106 ;
F_8 ( V_91 , V_75 . V_82 + 1 ) ;
#ifdef F_6
F_2 ( L_8 ,
V_97 , V_98 , V_99 , V_100 ) ;
#endif
F_15 ( V_114 , V_113 , 2 , 1 , V_124 , V_91 ) ;
goto V_131;
}
case V_54 :
case V_50 :
F_17 ( 2 , V_105 ) ;
F_27 ( V_73 . V_107 [ 0 ] , V_105 , 64 , ( ( V_67 & 0x1 ) == 0 ) ) ;
goto V_102;
case V_53 :
case V_49 :
case V_55 :
case V_51 :
if ( V_67 & 0x4 ) {
F_16 ( 2 , V_105 ) ;
} else {
F_17 ( 2 , V_105 ) ;
}
F_27 ( V_73 . V_82 [ 1 ] , V_105 , 32 ,
( ( ( V_67 & 0x3 ) != 0 ) || V_108 ) ) ;
goto V_102;
default:
goto V_115;
}
break;
V_131:
#ifdef F_6
F_2 ( L_12 ,
V_133 , V_134 , V_135 , V_136 , V_137 ) ;
#endif
F_28 ( V_73 . V_107 , V_124 ) ;
goto V_102;
V_132:
F_29 ( V_65 , V_123 , V_105 , 3 ) ;
if ( V_65 == 3 && ( F_30 ( V_123 ) || F_30 ( V_105 ) ) )
F_22 ( V_120 ) ;
if ( V_65 == V_66 ) {
V_65 = 0x4 ;
} else {
V_65 = 0 ;
}
goto V_121;
}
case V_138 : {
F_7 ( V_139 ) ; F_7 ( V_140 ) ; F_7 ( V_141 ) ;
F_7 ( V_142 ) ; F_7 ( V_143 ) ; F_7 ( V_144 ) ;
int V_145 , V_146 ;
switch ( type ) {
case V_7 :
case V_11 :
F_8 ( V_139 , V_74 . V_82 ) ;
F_8 ( V_142 , V_74 . V_82 + 1 ) ;
case V_9 :
F_8 ( V_140 , V_75 . V_82 ) ;
F_8 ( V_143 , V_75 . V_82 + 1 ) ;
break;
case V_5 :
F_8 ( V_139 , V_74 . V_82 ) ;
F_8 ( V_142 , V_74 . V_82 + 1 ) ;
break;
}
#ifdef F_6
F_2 ( L_13 , V_147 , V_148 , V_149 , V_150 ) ;
F_2 ( L_14 , V_151 , V_152 , V_153 , V_154 ) ;
F_2 ( L_15 , V_155 , V_156 , V_157 , V_158 ) ;
F_2 ( L_16 , V_159 , V_160 , V_161 , V_162 ) ;
#endif
switch ( V_67 ) {
case V_26 :
V_73 . V_82 [ 0 ] = V_74 . V_82 [ 0 ] & ~ V_101 ;
V_73 . V_82 [ 1 ] = V_74 . V_82 [ 1 ] & ~ V_101 ;
goto V_102;
case V_39 :
V_73 . V_82 [ 0 ] = V_74 . V_82 [ 0 ] | V_101 ;
V_73 . V_82 [ 1 ] = V_74 . V_82 [ 1 ] | V_101 ;
goto V_102;
case V_40 :
V_73 . V_82 [ 0 ] = V_74 . V_82 [ 0 ] ^ V_101 ;
V_73 . V_82 [ 1 ] = V_74 . V_82 [ 1 ] ^ V_101 ;
goto V_102;
case V_27 :
F_9 ( V_141 , V_139 , V_140 ) ;
F_9 ( V_144 , V_142 , V_143 ) ;
goto V_163;
case V_41 :
F_10 ( V_141 , V_139 , V_140 ) ;
F_10 ( V_144 , V_142 , V_143 ) ;
goto V_163;
case V_38 :
F_11 ( V_141 , V_139 , V_140 ) ;
F_11 ( V_144 , V_142 , V_143 ) ;
goto V_163;
case V_37 :
F_12 ( V_141 , V_139 , V_140 ) ;
F_12 ( V_144 , V_142 , V_143 ) ;
goto V_163;
case V_28 :
V_66 = 0 ;
goto V_164;
case V_29 :
V_66 = 1 ;
goto V_164;
case V_30 :
V_66 = - 1 ;
goto V_164;
case V_31 :
__asm__ __volatile__ ("mtspr 512, %4\n"
"efsctsf %0, %2\n"
"efsctsf %1, %3\n"
: "=r" (vc.wp[0]), "=r" (vc.wp[1])
: "r" (vb.wp[0]), "r" (vb.wp[1]), "r" (0));
goto V_102;
case V_34 :
__asm__ __volatile__ ("mtspr 512, %4\n"
"efsctuf %0, %2\n"
"efsctuf %1, %3\n"
: "=r" (vc.wp[0]), "=r" (vc.wp[1])
: "r" (vb.wp[0]), "r" (vb.wp[1]), "r" (0));
goto V_102;
case V_35 :
case V_32 :
case V_36 :
case V_33 :
if ( V_67 & 0x4 ) {
F_16 ( 1 , V_140 ) ;
F_16 ( 1 , V_143 ) ;
} else {
F_17 ( 1 , V_140 ) ;
F_17 ( 1 , V_143 ) ;
}
F_18 ( V_73 . V_82 [ 0 ] , V_140 , 32 ,
( ( ( V_67 & 0x3 ) != 0 ) || V_155 ) ) ;
F_18 ( V_73 . V_82 [ 1 ] , V_143 , 32 ,
( ( ( V_67 & 0x3 ) != 0 ) || V_159 ) ) ;
goto V_102;
default:
goto V_115;
}
break;
V_163:
#ifdef F_6
F_2 ( L_17 , V_165 , V_166 , V_167 , V_168 ) ;
F_2 ( L_18 , V_169 , V_170 , V_171 , V_172 ) ;
#endif
F_19 ( V_73 . V_82 , V_141 ) ;
F_19 ( V_73 . V_82 + 1 , V_144 ) ;
goto V_102;
V_164:
{
int V_173 , V_174 ;
F_20 ( V_145 , V_139 , V_140 , 3 ) ;
F_20 ( V_146 , V_142 , V_143 , 3 ) ;
if ( V_145 == 3 && ( F_21 ( V_139 ) || F_21 ( V_140 ) ) )
F_22 ( V_120 ) ;
if ( V_146 == 3 && ( F_21 ( V_142 ) || F_21 ( V_143 ) ) )
F_22 ( V_120 ) ;
V_173 = ( V_145 == V_66 ) ? 1 : 0 ;
V_174 = ( V_146 == V_66 ) ? 1 : 0 ;
V_65 = ( V_173 << 3 ) | ( V_174 << 2 ) | ( ( V_173 | V_174 ) << 1 ) |
( ( V_173 & V_174 ) << 0 ) ;
goto V_121;
}
}
default:
return - V_80 ;
}
V_121:
V_63 -> V_175 &= ~ ( 15 << ( ( 7 - ( ( V_1 >> 23 ) & 0x7 ) ) << 2 ) ) ;
V_63 -> V_175 |= ( V_65 << ( ( 7 - ( ( V_1 >> 23 ) & 0x7 ) ) << 2 ) ) ;
V_102:
V_87 &= ~ V_176 ;
V_87 |= ( V_177 & V_176 ) ;
F_31 ( V_88 , V_87 ) ;
V_83 -> V_84 . V_85 [ V_68 ] = V_73 . V_82 [ 0 ] ;
V_63 -> V_86 [ V_68 ] = V_73 . V_82 [ 1 ] ;
#ifdef F_6
F_2 ( L_19 , V_63 -> V_175 ) ;
F_2 ( L_20 ,
V_177 , V_87 ) ;
F_2 ( L_4 , V_73 . V_82 [ 0 ] , V_73 . V_82 [ 1 ] ) ;
F_2 ( L_5 , V_74 . V_82 [ 0 ] , V_74 . V_82 [ 1 ] ) ;
F_2 ( L_6 , V_75 . V_82 [ 0 ] , V_75 . V_82 [ 1 ] ) ;
#endif
return 0 ;
V_115:
if ( V_178 ) {
V_63 -> V_77 -= 4 ;
#ifdef F_6
F_2 ( V_179 L_21 , V_1 ) ;
#endif
return 0 ;
}
F_2 ( V_61 L_22 , V_1 ) ;
return - V_81 ;
}
int F_32 ( struct V_62 * V_63 )
{
union V_72 V_180 ;
int V_181 , V_182 ;
unsigned long V_1 , type , V_68 ;
if ( F_4 ( V_1 , ( unsigned int V_76 * ) V_63 -> V_77 ) )
return - V_78 ;
if ( ( V_1 >> 26 ) != 4 )
return - V_80 ;
type = F_1 ( V_1 & 0x7ff ) ;
if ( type == V_11 ) return - V_81 ;
V_68 = ( V_1 >> 21 ) & 0x1f ;
V_181 = V_63 -> V_86 [ V_68 ] & V_101 ;
V_182 = V_83 -> V_84 . V_85 [ V_68 ] & V_101 ;
V_180 . V_82 [ 0 ] = V_83 -> V_84 . V_85 [ V_68 ] ;
V_180 . V_82 [ 1 ] = V_63 -> V_86 [ V_68 ] ;
V_87 = F_5 ( V_88 ) ;
switch ( ( V_1 >> 5 ) & 0x7 ) {
case V_89 :
if ( ( V_183 ) == V_184 ) {
if ( ! V_181 ) V_180 . V_82 [ 1 ] ++ ;
} else {
if ( V_181 ) V_180 . V_82 [ 1 ] ++ ;
}
break;
case V_122 :
if ( V_183 == V_184 ) {
if ( ! V_182 ) V_180 . V_107 [ 0 ] ++ ;
} else {
if ( V_182 ) V_180 . V_107 [ 0 ] ++ ;
}
break;
case V_138 :
if ( V_183 == V_184 ) {
if ( ! V_181 ) V_180 . V_82 [ 1 ] ++ ;
if ( ! V_182 ) V_180 . V_82 [ 0 ] ++ ;
} else {
if ( V_181 ) V_180 . V_82 [ 1 ] ++ ;
if ( V_182 ) V_180 . V_82 [ 0 ] ++ ;
}
break;
default:
return - V_80 ;
}
V_83 -> V_84 . V_85 [ V_68 ] = V_180 . V_82 [ 0 ] ;
V_63 -> V_86 [ V_68 ] = V_180 . V_82 [ 1 ] ;
return 0 ;
}
int T_1 F_33 ( void )
{
T_2 V_185 , V_186 , V_187 ;
V_185 = F_5 ( V_188 ) ;
if ( ( F_34 ( V_185 ) == V_189 ) ||
( F_34 ( V_185 ) == V_190 ) ) {
V_186 = F_35 ( V_185 ) ;
V_187 = F_36 ( V_185 ) ;
switch ( V_186 ) {
case 1 :
if ( V_187 < 1 )
V_178 = 1 ;
break;
case 2 :
if ( V_187 < 3 )
V_178 = 1 ;
break;
case 3 :
case 4 :
case 5 :
if ( V_187 < 1 )
V_178 = 1 ;
break;
default:
break;
}
}
return 0 ;
}
