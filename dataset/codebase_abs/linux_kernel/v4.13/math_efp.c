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
if ( V_99 == V_104 ) {
V_72 . V_81 [ 1 ] = 0 ;
F_12 ( V_105 ) ;
} else {
V_98 += ( V_66 == V_14 ? 31 : 32 ) ;
F_13 ( V_72 . V_81 [ 1 ] , V_90 , 32 ,
( V_66 == V_14 ) ) ;
}
goto V_101;
case V_8 : {
F_14 ( V_106 ) ;
V_107 ;
F_15 ( V_106 , V_74 . V_108 ) ;
F_5 ( L_7 ,
V_109 , V_110 , V_111 , V_112 , V_113 ) ;
F_16 ( V_114 , V_115 , 1 , 2 , V_91 , V_106 ) ;
goto V_102;
}
case V_15 :
case V_18 :
if ( V_99 == V_104 ) {
V_72 . V_81 [ 1 ] = 0 ;
F_12 ( V_105 ) ;
} else {
F_13 ( V_72 . V_81 [ 1 ] , V_90 , 32 ,
( ( V_66 & 0x3 ) != 0 ) ) ;
}
goto V_101;
case V_16 :
case V_19 :
if ( V_99 == V_104 ) {
V_72 . V_81 [ 1 ] = 0 ;
F_12 ( V_105 ) ;
} else {
F_17 ( V_72 . V_81 [ 1 ] , V_90 , 32 ,
( ( V_66 & 0x3 ) != 0 ) ) ;
}
goto V_101;
default:
goto V_80;
}
break;
V_102:
F_5 ( L_8 , V_116 , V_117 , V_118 , V_119 ) ;
F_18 ( V_72 . V_81 + 1 , V_91 ) ;
goto V_101;
V_103:
F_19 ( V_64 , V_89 , V_90 , 3 ) ;
if ( V_64 == 3 && ( F_20 ( V_89 ) || F_20 ( V_90 ) ) )
F_12 ( V_105 ) ;
if ( V_64 == V_65 ) {
V_64 = 0x4 ;
} else {
V_64 = 0 ;
}
goto V_120;
}
case V_121 : {
F_14 ( V_122 ) ; F_14 ( V_106 ) ; F_14 ( V_123 ) ;
switch ( type ) {
case V_7 :
case V_11 :
F_15 ( V_122 , V_73 . V_108 ) ;
case V_9 :
F_15 ( V_106 , V_74 . V_108 ) ;
break;
case V_5 :
F_15 ( V_122 , V_73 . V_108 ) ;
break;
}
F_5 ( L_9 ,
V_124 , V_125 , V_126 , V_127 , V_128 ) ;
F_5 ( L_7 ,
V_109 , V_110 , V_111 , V_112 , V_113 ) ;
switch ( V_66 ) {
case V_42 :
V_72 . V_108 [ 0 ] = V_73 . V_108 [ 0 ] & ~ V_129 ;
goto V_101;
case V_58 :
V_72 . V_108 [ 0 ] = V_73 . V_108 [ 0 ] | V_129 ;
goto V_101;
case V_59 :
V_72 . V_108 [ 0 ] = V_73 . V_108 [ 0 ] ^ V_129 ;
goto V_101;
case V_43 :
F_21 ( V_123 , V_122 , V_106 ) ;
goto V_130;
case V_60 :
F_22 ( V_123 , V_122 , V_106 ) ;
goto V_130;
case V_57 :
F_23 ( V_123 , V_122 , V_106 ) ;
goto V_130;
case V_56 :
F_24 ( V_123 , V_122 , V_106 ) ;
goto V_130;
case V_45 :
V_65 = 0 ;
goto V_131;
case V_46 :
V_65 = 1 ;
goto V_131;
case V_47 :
V_65 = - 1 ;
goto V_131;
case V_48 :
case V_52 :
if ( V_113 == V_104 ) {
V_72 . V_81 [ 1 ] = 0 ;
F_12 ( V_105 ) ;
} else {
V_112 += ( V_66 == V_48 ? 31 : 32 ) ;
F_25 ( V_72 . V_81 [ 1 ] , V_106 , 32 ,
( V_66 == V_48 ) ) ;
}
goto V_101;
case V_44 : {
F_6 ( V_90 ) ;
V_107 ;
F_7 ( V_90 , V_74 . V_81 + 1 ) ;
F_5 ( L_6 ,
V_96 , V_97 , V_98 , V_99 ) ;
F_16 ( V_115 , V_114 , 2 , 1 , V_123 , V_90 ) ;
goto V_130;
}
case V_54 :
case V_50 :
if ( V_113 == V_104 ) {
V_72 . V_108 [ 0 ] = 0 ;
F_12 ( V_105 ) ;
} else {
F_26 ( V_72 . V_108 [ 0 ] , V_106 , 64 ,
( ( V_66 & 0x1 ) == 0 ) ) ;
}
goto V_101;
case V_53 :
case V_49 :
if ( V_113 == V_104 ) {
V_72 . V_81 [ 1 ] = 0 ;
F_12 ( V_105 ) ;
} else {
F_25 ( V_72 . V_81 [ 1 ] , V_106 , 32 ,
( ( V_66 & 0x3 ) != 0 ) ) ;
}
goto V_101;
case V_55 :
case V_51 :
if ( V_113 == V_104 ) {
V_72 . V_81 [ 1 ] = 0 ;
F_12 ( V_105 ) ;
} else {
F_26 ( V_72 . V_81 [ 1 ] , V_106 , 32 ,
( ( V_66 & 0x3 ) != 0 ) ) ;
}
goto V_101;
default:
goto V_80;
}
break;
V_130:
F_5 ( L_10 ,
V_132 , V_133 , V_134 , V_135 , V_136 ) ;
F_27 ( V_72 . V_108 , V_123 ) ;
goto V_101;
V_131:
F_28 ( V_64 , V_122 , V_106 , 3 ) ;
if ( V_64 == 3 && ( F_29 ( V_122 ) || F_29 ( V_106 ) ) )
F_12 ( V_105 ) ;
if ( V_64 == V_65 ) {
V_64 = 0x4 ;
} else {
V_64 = 0 ;
}
goto V_120;
}
case V_137 : {
F_6 ( V_138 ) ; F_6 ( V_139 ) ; F_6 ( V_140 ) ;
F_6 ( V_141 ) ; F_6 ( V_142 ) ; F_6 ( V_143 ) ;
int V_144 , V_145 ;
switch ( type ) {
case V_7 :
case V_11 :
F_7 ( V_138 , V_73 . V_81 ) ;
F_7 ( V_141 , V_73 . V_81 + 1 ) ;
case V_9 :
F_7 ( V_139 , V_74 . V_81 ) ;
F_7 ( V_142 , V_74 . V_81 + 1 ) ;
break;
case V_5 :
F_7 ( V_138 , V_73 . V_81 ) ;
F_7 ( V_141 , V_73 . V_81 + 1 ) ;
break;
}
F_5 ( L_11 ,
V_146 , V_147 , V_148 , V_149 ) ;
F_5 ( L_12 ,
V_150 , V_151 , V_152 , V_153 ) ;
F_5 ( L_13 ,
V_154 , V_155 , V_156 , V_157 ) ;
F_5 ( L_14 ,
V_158 , V_159 , V_160 , V_161 ) ;
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
F_8 ( V_140 , V_138 , V_139 ) ;
F_8 ( V_143 , V_141 , V_142 ) ;
goto V_162;
case V_41 :
F_9 ( V_140 , V_138 , V_139 ) ;
F_9 ( V_143 , V_141 , V_142 ) ;
goto V_162;
case V_38 :
F_10 ( V_140 , V_138 , V_139 ) ;
F_10 ( V_143 , V_141 , V_142 ) ;
goto V_162;
case V_37 :
F_11 ( V_140 , V_138 , V_139 ) ;
F_11 ( V_143 , V_141 , V_142 ) ;
goto V_162;
case V_28 :
V_65 = 0 ;
goto V_163;
case V_29 :
V_65 = 1 ;
goto V_163;
case V_30 :
V_65 = - 1 ;
goto V_163;
case V_34 :
case V_31 :
if ( V_157 == V_104 ) {
V_72 . V_81 [ 0 ] = 0 ;
F_12 ( V_105 ) ;
} else {
V_156 += ( V_66 == V_31 ? 31 : 32 ) ;
F_13 ( V_72 . V_81 [ 0 ] , V_139 , 32 ,
( V_66 == V_31 ) ) ;
}
if ( V_161 == V_104 ) {
V_72 . V_81 [ 1 ] = 0 ;
F_12 ( V_105 ) ;
} else {
V_160 += ( V_66 == V_31 ? 31 : 32 ) ;
F_13 ( V_72 . V_81 [ 1 ] , V_142 , 32 ,
( V_66 == V_31 ) ) ;
}
goto V_101;
case V_35 :
case V_32 :
if ( V_157 == V_104 ) {
V_72 . V_81 [ 0 ] = 0 ;
F_12 ( V_105 ) ;
} else {
F_13 ( V_72 . V_81 [ 0 ] , V_139 , 32 ,
( ( V_66 & 0x3 ) != 0 ) ) ;
}
if ( V_161 == V_104 ) {
V_72 . V_81 [ 1 ] = 0 ;
F_12 ( V_105 ) ;
} else {
F_13 ( V_72 . V_81 [ 1 ] , V_142 , 32 ,
( ( V_66 & 0x3 ) != 0 ) ) ;
}
goto V_101;
case V_36 :
case V_33 :
if ( V_157 == V_104 ) {
V_72 . V_81 [ 0 ] = 0 ;
F_12 ( V_105 ) ;
} else {
F_17 ( V_72 . V_81 [ 0 ] , V_139 , 32 ,
( ( V_66 & 0x3 ) != 0 ) ) ;
}
if ( V_161 == V_104 ) {
V_72 . V_81 [ 1 ] = 0 ;
F_12 ( V_105 ) ;
} else {
F_17 ( V_72 . V_81 [ 1 ] , V_142 , 32 ,
( ( V_66 & 0x3 ) != 0 ) ) ;
}
goto V_101;
default:
goto V_80;
}
break;
V_162:
F_5 ( L_15 ,
V_164 , V_165 , V_166 , V_167 ) ;
F_5 ( L_16 ,
V_168 , V_169 , V_170 , V_171 ) ;
F_18 ( V_72 . V_81 , V_140 ) ;
F_18 ( V_72 . V_81 + 1 , V_143 ) ;
goto V_101;
V_163:
{
int V_172 , V_173 ;
F_19 ( V_144 , V_138 , V_139 , 3 ) ;
F_19 ( V_145 , V_141 , V_142 , 3 ) ;
if ( V_144 == 3 && ( F_20 ( V_138 ) || F_20 ( V_139 ) ) )
F_12 ( V_105 ) ;
if ( V_145 == 3 && ( F_20 ( V_141 ) || F_20 ( V_142 ) ) )
F_12 ( V_105 ) ;
V_172 = ( V_144 == V_65 ) ? 1 : 0 ;
V_173 = ( V_145 == V_65 ) ? 1 : 0 ;
V_64 = ( V_172 << 3 ) | ( V_173 << 2 ) | ( ( V_172 | V_173 ) << 1 ) |
( ( V_172 & V_173 ) << 0 ) ;
goto V_120;
}
}
default:
return - V_79 ;
}
V_120:
V_62 -> V_174 &= ~ ( 15 << ( ( 7 - ( ( V_1 >> 23 ) & 0x7 ) ) << 2 ) ) ;
V_62 -> V_174 |= ( V_64 << ( ( 7 - ( ( V_1 >> 23 ) & 0x7 ) ) << 2 ) ) ;
V_101:
V_86
&= ~ ( V_105 | V_175 ) | V_82 -> V_83 . V_176 ;
V_86 |= ( V_177 & V_178 ) ;
F_30 ( V_87 , V_86 ) ;
V_82 -> V_83 . V_176 = V_86 ;
V_82 -> V_83 . V_84 [ V_67 ] = V_72 . V_81 [ 0 ] ;
V_62 -> V_85 [ V_67 ] = V_72 . V_81 [ 1 ] ;
F_5 ( L_17 , V_62 -> V_174 ) ;
F_5 ( L_18 ,
V_177 , V_86 ) ;
F_5 ( L_2 , V_72 . V_81 [ 0 ] , V_72 . V_81 [ 1 ] ) ;
F_5 ( L_3 , V_73 . V_81 [ 0 ] , V_73 . V_81 [ 1 ] ) ;
F_5 ( L_4 , V_74 . V_81 [ 0 ] , V_74 . V_81 [ 1 ] ) ;
if ( V_82 -> V_83 . V_179 & V_180 ) {
if ( ( V_177 & V_181 )
&& ( V_82 -> V_83 . V_179 & V_182 ) )
return 1 ;
if ( ( V_177 & V_183 )
&& ( V_82 -> V_83 . V_179 & V_184 ) )
return 1 ;
if ( ( V_177 & V_175 )
&& ( V_82 -> V_83 . V_179 & V_185 ) )
return 1 ;
if ( ( V_177 & V_186 )
&& ( V_82 -> V_83 . V_179 & V_187 ) )
return 1 ;
if ( ( V_177 & V_105 )
&& ( V_82 -> V_83 . V_179 & V_188 ) )
return 1 ;
}
return 0 ;
V_80:
if ( V_189 ) {
V_62 -> V_76 -= 4 ;
F_5 ( L_19 , V_1 ) ;
return 0 ;
}
F_31 ( V_190 L_20 , V_1 ) ;
return - V_191 ;
}
int F_32 ( struct V_61 * V_62 )
{
union V_71 V_192 ;
int V_193 , V_194 ;
int V_195 , V_196 ;
int V_197 ;
unsigned long V_1 , type , V_69 , V_67 , V_198 , V_66 ;
if ( F_3 ( V_1 , ( unsigned int V_75 * ) V_62 -> V_76 ) )
return - V_77 ;
if ( ( V_1 >> 26 ) != 4 )
return - V_79 ;
V_66 = V_1 & 0x7ff ;
type = F_1 ( V_66 ) ;
if ( type == V_11 ) return - V_191 ;
V_86 = F_4 ( V_87 ) ;
F_5 ( L_1 , V_1 , V_86 ) ;
V_198 = ( V_1 >> 5 ) & 0x7 ;
V_195 = V_86 & ( V_199 | V_200 ) ;
V_196 = V_86 & ( V_201 | V_202 ) ;
if ( ! ( V_195 || ( V_196 && V_198 == V_137 ) ) )
return 0 ;
V_67 = ( V_1 >> 21 ) & 0x1f ;
V_193 = V_62 -> V_85 [ V_67 ] & V_100 ;
V_194 = V_82 -> V_83 . V_84 [ V_67 ] & V_100 ;
V_192 . V_81 [ 0 ] = V_82 -> V_83 . V_84 [ V_67 ] ;
V_192 . V_81 [ 1 ] = V_62 -> V_85 [ V_67 ] ;
V_69 = ( V_1 >> 11 ) & 0x1f ;
switch ( V_66 ) {
case V_19 :
case V_16 :
case V_36 :
case V_33 :
case V_54 :
case V_50 :
case V_55 :
case V_51 :
return 0 ;
case V_18 :
case V_17 :
case V_35 :
case V_34 :
case V_53 :
case V_52 :
V_197 = 0 ;
V_193 = 0 ;
V_194 = 0 ;
break;
case V_15 :
case V_14 :
V_197 = 0 ;
if ( V_192 . V_81 [ 1 ] == 0 )
V_193 = V_62 -> V_85 [ V_69 ] & V_100 ;
break;
case V_32 :
case V_31 :
V_197 = 0 ;
if ( V_192 . V_81 [ 1 ] == 0 )
V_193 = V_62 -> V_85 [ V_69 ] & V_100 ;
if ( V_192 . V_81 [ 0 ] == 0 )
V_194 = V_82 -> V_83 . V_84 [ V_69 ] & V_100 ;
break;
case V_49 :
case V_48 :
V_197 = 0 ;
V_194 = V_193 ;
if ( V_192 . V_81 [ 1 ] == 0 )
V_194 = V_82 -> V_83 . V_84 [ V_69 ] & V_100 ;
break;
default:
V_197 = 1 ;
break;
}
F_5 ( L_21 , V_192 . V_81 [ 0 ] , V_192 . V_81 [ 1 ] ) ;
switch ( V_198 ) {
case V_88 :
if ( ( V_203 ) == V_204 ) {
if ( ! V_193 ) V_192 . V_81 [ 1 ] ++ ;
} else {
if ( V_193 ) {
if ( V_197 )
V_192 . V_81 [ 1 ] ++ ;
else
V_192 . V_81 [ 1 ] -- ;
}
}
break;
case V_121 :
if ( V_203 == V_204 ) {
if ( ! V_194 ) {
if ( V_197 )
V_192 . V_108 [ 0 ] ++ ;
else
V_192 . V_81 [ 1 ] ++ ;
}
} else {
if ( V_194 ) {
if ( V_197 )
V_192 . V_108 [ 0 ] ++ ;
else
V_192 . V_81 [ 1 ] -- ;
}
}
break;
case V_137 :
if ( V_203 == V_204 ) {
if ( V_195 && ! V_193 )
V_192 . V_81 [ 1 ] ++ ;
if ( V_196 && ! V_194 )
V_192 . V_81 [ 0 ] ++ ;
} else {
if ( V_195 && V_193 ) {
if ( V_197 )
V_192 . V_81 [ 1 ] ++ ;
else
V_192 . V_81 [ 1 ] -- ;
}
if ( V_196 && V_194 ) {
if ( V_197 )
V_192 . V_81 [ 0 ] ++ ;
else
V_192 . V_81 [ 0 ] -- ;
}
}
break;
default:
return - V_79 ;
}
V_82 -> V_83 . V_84 [ V_67 ] = V_192 . V_81 [ 0 ] ;
V_62 -> V_85 [ V_67 ] = V_192 . V_81 [ 1 ] ;
F_5 ( L_22 , V_192 . V_81 [ 0 ] , V_192 . V_81 [ 1 ] ) ;
if ( V_82 -> V_83 . V_179 & V_180 )
return ( V_82 -> V_83 . V_179 & V_187 ) ? 1 : 0 ;
return 0 ;
}
int T_1 F_33 ( void )
{
T_2 V_205 , V_206 , V_207 ;
V_205 = F_4 ( V_208 ) ;
if ( ( F_34 ( V_205 ) == V_209 ) ||
( F_34 ( V_205 ) == V_210 ) ) {
V_206 = F_35 ( V_205 ) ;
V_207 = F_36 ( V_205 ) ;
switch ( V_206 ) {
case 1 :
if ( V_207 < 1 )
V_189 = 1 ;
break;
case 2 :
if ( V_207 < 3 )
V_189 = 1 ;
break;
case 3 :
case 4 :
case 5 :
if ( V_207 < 1 )
V_189 = 1 ;
break;
default:
break;
}
}
return 0 ;
}
