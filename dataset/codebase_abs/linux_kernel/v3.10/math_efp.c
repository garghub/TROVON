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
}
return V_2 ;
}
int F_2 ( struct V_61 * V_62 )
{
V_63 ;
int V_64 , V_65 ;
unsigned long type , V_66 , V_67 , V_68 , V_69 , V_70 , V_1 ;
union V_71 V_72 , V_73 , V_74 ;
if ( F_3 ( V_1 , ( unsigned int V_75 * ) V_62 -> V_76 ) )
return - V_77 ;
if ( ( V_1 >> 26 ) != V_78 )
return - V_79 ;
type = F_1 ( V_1 ) ;
if ( type == V_3 )
goto V_80;
V_66 = V_1 & 0x7ff ;
V_67 = ( V_1 >> 21 ) & 0x1f ;
V_68 = ( V_1 >> 16 ) & 0x1f ;
V_69 = ( V_1 >> 11 ) & 0x1f ;
V_70 = ( V_1 >> 5 ) & 0x7 ;
V_72 . V_81 [ 0 ] = V_82 -> V_83 . V_84 [ V_67 ] ;
V_72 . V_81 [ 1 ] = V_62 -> V_85 [ V_67 ] ;
V_73 . V_81 [ 0 ] = V_82 -> V_83 . V_84 [ V_68 ] ;
V_73 . V_81 [ 1 ] = V_62 -> V_85 [ V_68 ] ;
V_74 . V_81 [ 0 ] = V_82 -> V_83 . V_84 [ V_69 ] ;
V_74 . V_81 [ 1 ] = V_62 -> V_85 [ V_69 ] ;
V_86 = F_4 ( V_87 ) ;
F_5 ( L_1 , V_1 , V_86 ) ;
F_5 ( L_2 , V_72 . V_81 [ 0 ] , V_72 . V_81 [ 1 ] ) ;
F_5 ( L_3 , V_73 . V_81 [ 0 ] , V_73 . V_81 [ 1 ] ) ;
F_5 ( L_4 , V_74 . V_81 [ 0 ] , V_74 . V_81 [ 1 ] ) ;
switch ( V_70 ) {
case V_88 : {
F_6 ( V_89 ) ; F_6 ( V_90 ) ; F_6 ( V_91 ) ;
switch ( type ) {
case V_7 :
case V_11 :
F_7 ( V_89 , V_73 . V_81 + 1 ) ;
case V_9 :
F_7 ( V_90 , V_74 . V_81 + 1 ) ;
break;
case V_5 :
F_7 ( V_89 , V_73 . V_81 + 1 ) ;
break;
}
F_5 ( L_5 , V_92 , V_93 , V_94 , V_95 ) ;
F_5 ( L_6 , V_96 , V_97 , V_98 , V_99 ) ;
switch ( V_66 ) {
case V_4 :
V_72 . V_81 [ 1 ] = V_73 . V_81 [ 1 ] & ~ V_100 ;
goto V_101;
case V_22 :
V_72 . V_81 [ 1 ] = V_73 . V_81 [ 1 ] | V_100 ;
goto V_101;
case V_23 :
V_72 . V_81 [ 1 ] = V_73 . V_81 [ 1 ] ^ V_100 ;
goto V_101;
case V_6 :
F_8 ( V_91 , V_89 , V_90 ) ;
goto V_102;
case V_24 :
F_9 ( V_91 , V_89 , V_90 ) ;
goto V_102;
case V_21 :
F_10 ( V_91 , V_89 , V_90 ) ;
goto V_102;
case V_20 :
F_11 ( V_91 , V_89 , V_90 ) ;
goto V_102;
case V_10 :
V_65 = 0 ;
goto V_103;
case V_12 :
V_65 = 1 ;
goto V_103;
case V_13 :
V_65 = - 1 ;
goto V_103;
case V_14 :
case V_17 :
if ( ! ( ( V_74 . V_81 [ 1 ] >> 23 ) == 0xff && ( ( V_74 . V_81 [ 1 ] & 0x7fffff ) > 0 ) ) ) {
if ( ( ( V_74 . V_81 [ 1 ] >> 23 ) & 0xff ) == 0 ) {
V_72 . V_81 [ 1 ] = 0x0 ;
} else if ( ( V_74 . V_81 [ 1 ] >> 31 ) == 0 ) {
V_72 . V_81 [ 1 ] = ( V_66 == V_14 ) ?
0x7fffffff : 0xffffffff ;
} else {
V_72 . V_81 [ 1 ] = ( V_66 == V_14 ) ?
0x80000000 : 0x0 ;
}
} else {
V_72 . V_81 [ 1 ] = 0x0 ;
}
goto V_101;
case V_8 : {
F_12 ( V_104 ) ;
V_105 ;
F_13 ( V_104 , V_74 . V_106 ) ;
F_5 ( L_7 ,
V_107 , V_108 , V_109 , V_110 , V_111 ) ;
F_14 ( V_112 , V_113 , 1 , 2 , V_91 , V_104 ) ;
goto V_102;
}
case V_15 :
case V_16 :
case V_18 :
case V_19 :
if ( V_66 & 0x4 ) {
F_15 ( 1 , V_90 ) ;
} else {
F_16 ( 1 , V_90 ) ;
}
F_17 ( V_72 . V_81 [ 1 ] , V_90 , 32 ,
( ( ( V_66 & 0x3 ) != 0 ) || V_96 ) ) ;
goto V_101;
default:
goto V_80;
}
break;
V_102:
F_5 ( L_8 , V_114 , V_115 , V_116 , V_117 ) ;
F_18 ( V_72 . V_81 + 1 , V_91 ) ;
goto V_101;
V_103:
F_19 ( V_64 , V_89 , V_90 , 3 ) ;
if ( V_64 == 3 && ( F_20 ( V_89 ) || F_20 ( V_90 ) ) )
F_21 ( V_118 ) ;
if ( V_64 == V_65 ) {
V_64 = 0x4 ;
} else {
V_64 = 0 ;
}
goto V_119;
}
case V_120 : {
F_12 ( V_121 ) ; F_12 ( V_104 ) ; F_12 ( V_122 ) ;
switch ( type ) {
case V_7 :
case V_11 :
F_13 ( V_121 , V_73 . V_106 ) ;
case V_9 :
F_13 ( V_104 , V_74 . V_106 ) ;
break;
case V_5 :
F_13 ( V_121 , V_73 . V_106 ) ;
break;
}
F_5 ( L_9 ,
V_123 , V_124 , V_125 , V_126 , V_127 ) ;
F_5 ( L_7 ,
V_107 , V_108 , V_109 , V_110 , V_111 ) ;
switch ( V_66 ) {
case V_42 :
V_72 . V_106 [ 0 ] = V_73 . V_106 [ 0 ] & ~ V_128 ;
goto V_101;
case V_58 :
V_72 . V_106 [ 0 ] = V_73 . V_106 [ 0 ] | V_128 ;
goto V_101;
case V_59 :
V_72 . V_106 [ 0 ] = V_73 . V_106 [ 0 ] ^ V_128 ;
goto V_101;
case V_43 :
F_22 ( V_122 , V_121 , V_104 ) ;
goto V_129;
case V_60 :
F_23 ( V_122 , V_121 , V_104 ) ;
goto V_129;
case V_57 :
F_24 ( V_122 , V_121 , V_104 ) ;
goto V_129;
case V_56 :
F_25 ( V_122 , V_121 , V_104 ) ;
goto V_129;
case V_45 :
V_65 = 0 ;
goto V_130;
case V_46 :
V_65 = 1 ;
goto V_130;
case V_47 :
V_65 = - 1 ;
goto V_130;
case V_48 :
case V_52 :
if ( ! ( ( V_74 . V_81 [ 0 ] >> 20 ) == 0x7ff &&
( ( V_74 . V_81 [ 0 ] & 0xfffff ) > 0 || ( V_74 . V_81 [ 1 ] > 0 ) ) ) ) {
if ( ( ( V_74 . V_81 [ 0 ] >> 20 ) & 0x7ff ) == 0 ) {
V_72 . V_81 [ 1 ] = 0x0 ;
} else if ( ( V_74 . V_81 [ 0 ] >> 31 ) == 0 ) {
V_72 . V_81 [ 1 ] = ( V_66 == V_48 ) ?
0x7fffffff : 0xffffffff ;
} else {
V_72 . V_81 [ 1 ] = ( V_66 == V_48 ) ?
0x80000000 : 0x0 ;
}
} else {
V_72 . V_81 [ 1 ] = 0x0 ;
}
goto V_101;
case V_44 : {
F_6 ( V_90 ) ;
V_105 ;
F_7 ( V_90 , V_74 . V_81 + 1 ) ;
F_5 ( L_6 ,
V_96 , V_97 , V_98 , V_99 ) ;
F_14 ( V_113 , V_112 , 2 , 1 , V_122 , V_90 ) ;
goto V_129;
}
case V_54 :
case V_50 :
F_16 ( 2 , V_104 ) ;
F_26 ( V_72 . V_106 [ 0 ] , V_104 , 64 , ( ( V_66 & 0x1 ) == 0 ) ) ;
goto V_101;
case V_53 :
case V_49 :
case V_55 :
case V_51 :
if ( V_66 & 0x4 ) {
F_15 ( 2 , V_104 ) ;
} else {
F_16 ( 2 , V_104 ) ;
}
F_26 ( V_72 . V_81 [ 1 ] , V_104 , 32 ,
( ( ( V_66 & 0x3 ) != 0 ) || V_107 ) ) ;
goto V_101;
default:
goto V_80;
}
break;
V_129:
F_5 ( L_10 ,
V_131 , V_132 , V_133 , V_134 , V_135 ) ;
F_27 ( V_72 . V_106 , V_122 ) ;
goto V_101;
V_130:
F_28 ( V_64 , V_121 , V_104 , 3 ) ;
if ( V_64 == 3 && ( F_29 ( V_121 ) || F_29 ( V_104 ) ) )
F_21 ( V_118 ) ;
if ( V_64 == V_65 ) {
V_64 = 0x4 ;
} else {
V_64 = 0 ;
}
goto V_119;
}
case V_136 : {
F_6 ( V_137 ) ; F_6 ( V_138 ) ; F_6 ( V_139 ) ;
F_6 ( V_140 ) ; F_6 ( V_141 ) ; F_6 ( V_142 ) ;
int V_143 , V_144 ;
switch ( type ) {
case V_7 :
case V_11 :
F_7 ( V_137 , V_73 . V_81 ) ;
F_7 ( V_140 , V_73 . V_81 + 1 ) ;
case V_9 :
F_7 ( V_138 , V_74 . V_81 ) ;
F_7 ( V_141 , V_74 . V_81 + 1 ) ;
break;
case V_5 :
F_7 ( V_137 , V_73 . V_81 ) ;
F_7 ( V_140 , V_73 . V_81 + 1 ) ;
break;
}
F_5 ( L_11 ,
V_145 , V_146 , V_147 , V_148 ) ;
F_5 ( L_12 ,
V_149 , V_150 , V_151 , V_152 ) ;
F_5 ( L_13 ,
V_153 , V_154 , V_155 , V_156 ) ;
F_5 ( L_14 ,
V_157 , V_158 , V_159 , V_160 ) ;
switch ( V_66 ) {
case V_26 :
V_72 . V_81 [ 0 ] = V_73 . V_81 [ 0 ] & ~ V_100 ;
V_72 . V_81 [ 1 ] = V_73 . V_81 [ 1 ] & ~ V_100 ;
goto V_101;
case V_39 :
V_72 . V_81 [ 0 ] = V_73 . V_81 [ 0 ] | V_100 ;
V_72 . V_81 [ 1 ] = V_73 . V_81 [ 1 ] | V_100 ;
goto V_101;
case V_40 :
V_72 . V_81 [ 0 ] = V_73 . V_81 [ 0 ] ^ V_100 ;
V_72 . V_81 [ 1 ] = V_73 . V_81 [ 1 ] ^ V_100 ;
goto V_101;
case V_27 :
F_8 ( V_139 , V_137 , V_138 ) ;
F_8 ( V_142 , V_140 , V_141 ) ;
goto V_161;
case V_41 :
F_9 ( V_139 , V_137 , V_138 ) ;
F_9 ( V_142 , V_140 , V_141 ) ;
goto V_161;
case V_38 :
F_10 ( V_139 , V_137 , V_138 ) ;
F_10 ( V_142 , V_140 , V_141 ) ;
goto V_161;
case V_37 :
F_11 ( V_139 , V_137 , V_138 ) ;
F_11 ( V_142 , V_140 , V_141 ) ;
goto V_161;
case V_28 :
V_65 = 0 ;
goto V_162;
case V_29 :
V_65 = 1 ;
goto V_162;
case V_30 :
V_65 = - 1 ;
goto V_162;
case V_31 :
__asm__ __volatile__ ("mtspr 512, %4\n"
"efsctsf %0, %2\n"
"efsctsf %1, %3\n"
: "=r" (vc.wp[0]), "=r" (vc.wp[1])
: "r" (vb.wp[0]), "r" (vb.wp[1]), "r" (0));
goto V_101;
case V_34 :
__asm__ __volatile__ ("mtspr 512, %4\n"
"efsctuf %0, %2\n"
"efsctuf %1, %3\n"
: "=r" (vc.wp[0]), "=r" (vc.wp[1])
: "r" (vb.wp[0]), "r" (vb.wp[1]), "r" (0));
goto V_101;
case V_35 :
case V_32 :
case V_36 :
case V_33 :
if ( V_66 & 0x4 ) {
F_15 ( 1 , V_138 ) ;
F_15 ( 1 , V_141 ) ;
} else {
F_16 ( 1 , V_138 ) ;
F_16 ( 1 , V_141 ) ;
}
F_17 ( V_72 . V_81 [ 0 ] , V_138 , 32 ,
( ( ( V_66 & 0x3 ) != 0 ) || V_153 ) ) ;
F_17 ( V_72 . V_81 [ 1 ] , V_141 , 32 ,
( ( ( V_66 & 0x3 ) != 0 ) || V_157 ) ) ;
goto V_101;
default:
goto V_80;
}
break;
V_161:
F_5 ( L_15 ,
V_163 , V_164 , V_165 , V_166 ) ;
F_5 ( L_16 ,
V_167 , V_168 , V_169 , V_170 ) ;
F_18 ( V_72 . V_81 , V_139 ) ;
F_18 ( V_72 . V_81 + 1 , V_142 ) ;
goto V_101;
V_162:
{
int V_171 , V_172 ;
F_19 ( V_143 , V_137 , V_138 , 3 ) ;
F_19 ( V_144 , V_140 , V_141 , 3 ) ;
if ( V_143 == 3 && ( F_20 ( V_137 ) || F_20 ( V_138 ) ) )
F_21 ( V_118 ) ;
if ( V_144 == 3 && ( F_20 ( V_140 ) || F_20 ( V_141 ) ) )
F_21 ( V_118 ) ;
V_171 = ( V_143 == V_65 ) ? 1 : 0 ;
V_172 = ( V_144 == V_65 ) ? 1 : 0 ;
V_64 = ( V_171 << 3 ) | ( V_172 << 2 ) | ( ( V_171 | V_172 ) << 1 ) |
( ( V_171 & V_172 ) << 0 ) ;
goto V_119;
}
}
default:
return - V_79 ;
}
V_119:
V_62 -> V_173 &= ~ ( 15 << ( ( 7 - ( ( V_1 >> 23 ) & 0x7 ) ) << 2 ) ) ;
V_62 -> V_173 |= ( V_64 << ( ( 7 - ( ( V_1 >> 23 ) & 0x7 ) ) << 2 ) ) ;
V_101:
V_86 &= ~ V_174 ;
V_86 |= ( V_175 & V_174 ) ;
F_30 ( V_87 , V_86 ) ;
V_82 -> V_83 . V_84 [ V_67 ] = V_72 . V_81 [ 0 ] ;
V_62 -> V_85 [ V_67 ] = V_72 . V_81 [ 1 ] ;
F_5 ( L_17 , V_62 -> V_173 ) ;
F_5 ( L_18 ,
V_175 , V_86 ) ;
F_5 ( L_2 , V_72 . V_81 [ 0 ] , V_72 . V_81 [ 1 ] ) ;
F_5 ( L_3 , V_73 . V_81 [ 0 ] , V_73 . V_81 [ 1 ] ) ;
F_5 ( L_4 , V_74 . V_81 [ 0 ] , V_74 . V_81 [ 1 ] ) ;
return 0 ;
V_80:
if ( V_176 ) {
V_62 -> V_76 -= 4 ;
F_5 ( L_19 , V_1 ) ;
return 0 ;
}
F_31 ( V_177 L_20 , V_1 ) ;
return - V_178 ;
}
int F_32 ( struct V_61 * V_62 )
{
union V_71 V_179 ;
int V_180 , V_181 ;
unsigned long V_1 , type , V_67 ;
if ( F_3 ( V_1 , ( unsigned int V_75 * ) V_62 -> V_76 ) )
return - V_77 ;
if ( ( V_1 >> 26 ) != 4 )
return - V_79 ;
type = F_1 ( V_1 & 0x7ff ) ;
if ( type == V_11 ) return - V_178 ;
V_86 = F_4 ( V_87 ) ;
F_5 ( L_1 , V_1 , V_86 ) ;
if ( ! ( V_86 & V_182 ) )
return 0 ;
V_67 = ( V_1 >> 21 ) & 0x1f ;
V_180 = V_62 -> V_85 [ V_67 ] & V_100 ;
V_181 = V_82 -> V_83 . V_84 [ V_67 ] & V_100 ;
V_179 . V_81 [ 0 ] = V_82 -> V_83 . V_84 [ V_67 ] ;
V_179 . V_81 [ 1 ] = V_62 -> V_85 [ V_67 ] ;
F_5 ( L_21 , V_179 . V_81 [ 0 ] , V_179 . V_81 [ 1 ] ) ;
switch ( ( V_1 >> 5 ) & 0x7 ) {
case V_88 :
if ( ( V_183 ) == V_184 ) {
if ( ! V_180 ) V_179 . V_81 [ 1 ] ++ ;
} else {
if ( V_180 ) V_179 . V_81 [ 1 ] ++ ;
}
break;
case V_120 :
if ( V_183 == V_184 ) {
if ( ! V_181 ) V_179 . V_106 [ 0 ] ++ ;
} else {
if ( V_181 ) V_179 . V_106 [ 0 ] ++ ;
}
break;
case V_136 :
if ( V_183 == V_184 ) {
if ( ! V_180 ) V_179 . V_81 [ 1 ] ++ ;
if ( ! V_181 ) V_179 . V_81 [ 0 ] ++ ;
} else {
if ( V_180 ) V_179 . V_81 [ 1 ] ++ ;
if ( V_181 ) V_179 . V_81 [ 0 ] ++ ;
}
break;
default:
return - V_79 ;
}
V_82 -> V_83 . V_84 [ V_67 ] = V_179 . V_81 [ 0 ] ;
V_62 -> V_85 [ V_67 ] = V_179 . V_81 [ 1 ] ;
F_5 ( L_22 , V_179 . V_81 [ 0 ] , V_179 . V_81 [ 1 ] ) ;
return 0 ;
}
int T_1 F_33 ( void )
{
T_2 V_185 , V_186 , V_187 ;
V_185 = F_4 ( V_188 ) ;
if ( ( F_34 ( V_185 ) == V_189 ) ||
( F_34 ( V_185 ) == V_190 ) ) {
V_186 = F_35 ( V_185 ) ;
V_187 = F_36 ( V_185 ) ;
switch ( V_186 ) {
case 1 :
if ( V_187 < 1 )
V_176 = 1 ;
break;
case 2 :
if ( V_187 < 3 )
V_176 = 1 ;
break;
case 3 :
case 4 :
case 5 :
if ( V_187 < 1 )
V_176 = 1 ;
break;
default:
break;
}
}
return 0 ;
}
