static int T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
static int T_2 F_3 ( struct V_4 * V_3 , struct V_5 * V_5 )
{
struct V_6 * V_7 ;
int V_8 , V_9 , V_10 , V_11 , V_12 , V_13 = 0 ;
T_3 V_14 ;
T_4 V_15 ;
T_4 V_16 ;
V_15 = V_3 -> V_17 ;
V_18 ;
V_14 = F_4 ( V_19 ) ;
V_14 = ( ( V_14 & ~ V_20 & ~ V_21 & ~ V_22 ) | V_23 ) ;
F_5 ( V_14 , V_19 ) ;
if ( F_6 ( V_24 ) != V_25 ) {
return - V_26 ;
}
V_7 = F_7 ( V_3 ) ;
V_16 = V_7 -> V_16 ;
if ( ! V_16 || V_7 -> V_27 < V_28 || V_7 -> V_27 >= V_29 )
return - V_26 ;
F_8 ( L_1 ,
F_9 ( V_5 ) , V_30 [ V_7 -> V_27 ] , V_15 ) ;
switch ( V_7 -> V_31 ) {
#ifdef F_10
case V_32 :
F_8 ( L_2 , F_11 ( V_5 ) -> V_33 + 1 ) ;
break;
#endif
#ifdef F_12
case V_34 :
F_8 ( L_3 , F_13 ( V_5 ) -> V_33 ) ;
break;
#endif
case V_35 :
break;
default:
F_8 ( L_4 , V_7 -> V_31 ) ;
return - V_26 ;
}
F_8 ( L_5 ) ;
V_13 = F_14 ( V_3 ) ;
F_8 ( L_6 , V_3 -> V_36 ) ;
if ( V_13 != 0 ) {
F_8 ( L_7 ) ;
return - V_26 ;
}
V_11 = ( ( V_7 -> V_27 != V_28 ) ? 64 : 48 ) ;
if ( ( V_14 & V_37 ) && ( V_7 -> V_27 == V_38 ) )
V_11 = 128 ;
if ( V_14 & V_39 ) {
V_14 &= ~ V_40 ;
V_11 -= 32 ;
if ( V_7 -> V_31 != V_32 )
V_16 += 0x8000 ;
}
if ( ( V_12 = ( V_41 * ( sizeof( struct V_42 ) + V_43 ) + V_44 * ( sizeof( struct V_45 ) + V_46 ) + sizeof( struct V_47 ) ) )
> ( V_11 << 10 ) ) {
F_8 ( L_8 , ( V_12 >> 10 ) , V_11 ) ;
return - V_26 ;
}
F_8 ( L_9 , V_11 , V_16 ) ;
if ( V_7 -> V_27 != V_28 ) {
V_14 |= V_20 ;
F_5 ( V_14 , V_19 ) ;
}
F_15 ( & V_7 -> V_48 ) ;
sprintf ( V_7 -> V_49 , L_10 ,
V_30 [ V_7 -> V_27 ] , F_9 ( V_5 ) ) ;
V_13 = - V_50 ;
if ( ! F_16 ( V_16 , V_12 , V_7 -> V_49 ) ) {
F_8 ( V_51 L_11 ) ;
goto V_52;
}
V_13 = - V_53 ;
V_7 -> V_54 = F_17 ( V_16 , V_12 ) ;
if ( V_7 -> V_54 == NULL ) {
F_8 ( V_51 L_12 ) ;
goto V_55;
}
V_7 -> V_16 = V_16 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_56 = V_16 & V_57 ;
V_10 = 0 ;
V_10 += sizeof( struct V_47 ) ;
V_10 = ( V_10 + V_58 ) & ~ V_58 ;
V_7 -> V_59 = V_7 -> V_54 + V_10 ;
V_7 -> V_60 = V_10 ;
V_10 += ( sizeof( struct V_42 ) * V_41 ) ;
V_7 -> V_61 = V_7 -> V_54 + V_10 ;
V_7 -> V_62 = V_10 ;
V_10 += ( sizeof( struct V_45 ) * V_44 ) ;
V_7 -> V_63 = V_10 ;
V_7 -> V_64 = V_41 - 1 ;
V_7 -> V_65 = V_44 - 1 ;
for ( V_8 = 0 , V_9 = V_7 -> V_64 ; V_9 > 0 ; V_8 ++ ) {
V_9 >>= 1 ;
}
V_7 -> V_66 = ( V_67 ) ( V_8 << 29 ) ;
for ( V_8 = 0 , V_9 = V_7 -> V_65 ; V_9 > 0 ; V_8 ++ ) {
V_9 >>= 1 ;
}
V_7 -> V_68 = ( V_67 ) ( V_8 << 29 ) ;
F_18 ( V_3 ) ;
F_19 ( V_3 ) ;
V_14 = ( ( V_14 & ~ V_23 ) | V_22 ) ;
F_5 ( V_14 , V_19 ) ;
if ( V_3 -> V_69 < 2 ) {
unsigned char V_70 ;
unsigned long V_71 , V_72 ;
V_71 = F_20 () ;
switch ( V_7 -> V_27 ) {
case V_28 :
case V_73 :
case V_74 :
V_75 = V_76 ;
break;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
V_75 = V_82 ;
break;
case V_38 :
V_75 = V_83 ;
break;
default:
break;
}
F_21 ( V_84 | V_85 , V_24 ) ;
V_72 = V_86 + V_87 / 50 ;
while ( F_22 ( V_86 , V_72 ) )
F_23 () ;
V_70 = F_24 ( V_71 ) ;
V_13 = - V_26 ;
if ( ! V_70 ) {
F_8 ( L_13 ) ;
goto V_88;
} else {
for ( V_3 -> V_69 = 0 , V_8 = 0 ; ( V_75 [ V_8 ] ) && ( ! V_3 -> V_69 ) ; V_8 ++ )
if ( V_70 == V_75 [ V_8 ] ) {
V_3 -> V_69 = V_70 ;
F_8 ( L_14 , V_3 -> V_69 ) ;
}
if ( ! V_3 -> V_69 ) {
F_8 ( L_15 ) ;
goto V_88;
}
}
} else {
F_8 ( L_16 , V_3 -> V_69 ) ;
}
if ( V_89 > 1 ) {
F_8 ( V_90 ) ;
}
V_3 -> V_91 = & V_92 ;
V_3 -> V_93 = V_94 ;
V_3 -> V_16 = 0 ;
F_25 ( V_5 , V_3 ) ;
F_26 ( V_3 , V_5 ) ;
V_13 = F_27 ( V_3 ) ;
if ( V_13 == 0 )
return 0 ;
V_88:
F_28 ( V_7 -> V_54 ) ;
V_55:
F_29 ( V_16 , V_12 ) ;
V_52:
return V_13 ;
}
static int F_30 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
T_4 V_15 = V_3 -> V_17 ;
T_3 V_14 ;
int V_13 = 0 ;
V_18 ;
V_14 = F_4 ( V_19 ) ;
if ( V_7 -> V_27 != V_28 ) {
V_14 |= V_20 ;
F_5 ( V_14 , V_19 ) ;
}
F_18 ( V_3 ) ;
F_19 ( V_3 ) ;
F_31 ( V_3 ) ;
if ( F_32 ( V_3 -> V_69 , V_95 , 0 , V_7 -> V_49 , V_3 ) ) {
F_8 ( L_17 , V_3 -> V_69 ) ;
V_13 = - V_96 ;
} else {
V_14 = ( ( V_14 & ~ V_23 & ~ V_97 ) | V_22 ) ;
F_5 ( V_14 , V_19 ) ;
F_21 ( V_98 , V_99 ) ;
F_33 ( V_3 ) ;
V_13 = F_34 ( V_3 ) ;
if ( V_89 > 1 ) {
F_8 ( L_18 , F_6 ( V_24 ) ) ;
F_8 ( L_19 , F_4 ( V_19 ) ) ;
}
}
return V_13 ;
}
static void F_18 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
T_5 V_8 ;
T_4 V_10 ;
F_35 ( V_3 ) ;
V_7 -> V_100 = V_7 -> V_101 = 0 ;
V_7 -> V_102 = V_7 -> V_103 = 0 ;
for ( V_8 = 0 ; V_8 <= V_7 -> V_64 ; V_8 ++ ) {
V_10 = V_7 -> V_63 + V_8 * V_43 ;
F_36 ( ( V_7 -> V_56 + V_10 ) | V_104 , & V_7 -> V_59 [ V_8 ] . V_105 ) ;
F_37 ( - V_43 , & V_7 -> V_59 [ V_8 ] . V_106 ) ;
V_7 -> V_107 [ V_8 ] = V_7 -> V_54 + V_10 ;
}
for ( V_8 = 0 ; V_8 <= V_7 -> V_65 ; V_8 ++ ) {
V_10 = V_7 -> V_63 + ( V_8 + V_7 -> V_64 + 1 ) * V_46 ;
F_36 ( ( V_7 -> V_56 + V_10 ) & 0x00ffffff , & V_7 -> V_61 [ V_8 ] . V_105 ) ;
V_7 -> V_108 [ V_8 ] = V_7 -> V_54 + V_10 ;
}
V_7 -> V_109 . V_59 = ( V_7 -> V_56 + V_7 -> V_60 ) | V_7 -> V_66 ;
V_7 -> V_109 . V_61 = ( V_7 -> V_56 + V_7 -> V_62 ) | V_7 -> V_68 ;
F_38 ( V_3 ) ;
for ( V_8 = 0 ; V_8 < V_110 ; V_8 ++ ) {
V_7 -> V_109 . V_111 [ V_8 ] = V_3 -> V_36 [ V_8 ] ;
}
V_7 -> V_109 . V_112 = 0x0000 ;
}
static void F_39 ( struct V_4 * V_3 )
{
T_4 V_15 = V_3 -> V_17 ;
F_8 ( L_20 , V_3 -> V_113 , F_6 ( V_24 ) ) ;
V_18 ;
F_18 ( V_3 ) ;
F_19 ( V_3 ) ;
V_3 -> V_114 = V_86 ;
F_40 ( V_3 ) ;
F_34 ( V_3 ) ;
}
static T_6 F_41 ( struct V_115 * V_116 ,
struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
T_4 V_15 = V_3 -> V_17 ;
int V_13 = 0 ;
if ( V_116 -> V_117 < 1 )
goto V_118;
if ( F_42 ( V_116 , V_119 ) )
goto V_118;
F_35 ( V_3 ) ;
if ( V_120 ) {
V_13 = F_43 ( V_3 , V_116 ) ;
if ( ! V_13 ) {
F_21 ( V_98 , V_99 ) ;
F_21 ( V_84 | V_121 , V_24 ) ;
F_44 ( V_116 ) ;
}
if ( V_120 )
F_33 ( V_3 ) ;
} else
V_13 = V_122 ;
V_118:
return V_13 ;
}
static T_7 V_95 ( int V_69 , void * V_123 )
{
struct V_4 * V_3 = V_123 ;
struct V_6 * V_7 ;
T_3 V_124 , V_14 ;
T_4 V_15 ;
if ( V_3 == NULL ) {
F_8 ( L_21 , V_69 ) ;
return V_125 ;
}
V_7 = F_7 ( V_3 ) ;
V_15 = V_3 -> V_17 ;
F_45 ( & V_7 -> V_48 ) ;
V_14 = F_4 ( V_19 ) ;
V_14 |= ( V_23 | V_97 ) ;
F_5 ( V_14 , V_19 ) ;
F_21 ( V_98 , V_99 ) ;
V_124 = F_6 ( V_24 ) ;
F_21 ( V_124 & V_126 , V_24 ) ;
if ( V_124 & V_127 )
F_46 ( V_3 ) ;
if ( V_124 & V_128 )
F_47 ( V_3 ) ;
if ( ( V_120 >= 0 ) && F_48 ( V_3 ) ) {
F_40 ( V_3 ) ;
}
V_14 = ( V_14 & ~ V_23 & ~ V_97 ) ;
F_5 ( V_14 , V_19 ) ;
F_49 ( & V_7 -> V_48 ) ;
return V_129 ;
}
static int F_46 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
int V_8 , V_130 ;
V_67 V_13 ;
for ( V_130 = V_7 -> V_100 ; ! ( F_50 ( & V_7 -> V_59 [ V_130 ] . V_105 ) & V_104 ) ; V_130 = V_7 -> V_100 ) {
V_13 = F_50 ( & V_7 -> V_59 [ V_130 ] . V_105 ) >> 16 ;
if ( V_13 & V_131 ) {
V_7 -> V_102 = V_130 ;
}
if ( V_13 & V_132 ) {
if ( V_13 & V_133 ) {
V_3 -> V_134 . V_135 ++ ;
if ( V_13 & V_136 )
V_3 -> V_134 . V_137 ++ ;
if ( V_13 & V_138 )
V_3 -> V_134 . V_139 ++ ;
if ( V_13 & V_140 )
V_3 -> V_134 . V_141 ++ ;
if ( V_13 & V_142 )
V_3 -> V_134 . V_143 ++ ;
} else {
short V_117 , V_144 = F_51 ( & V_7 -> V_59 [ V_130 ] . V_145 ) - 4 ;
struct V_115 * V_116 ;
V_116 = F_52 ( V_3 , V_144 + 2 ) ;
if ( V_116 != NULL ) {
unsigned char * V_146 ;
F_53 ( V_116 , 2 ) ;
V_146 = F_54 ( V_116 , V_144 ) ;
if ( V_130 < V_7 -> V_102 ) {
V_117 = ( V_7 -> V_64 - V_7 -> V_102 + 1 ) * V_43 ;
F_55 ( V_146 , V_7 -> V_107 [ V_7 -> V_102 ] , V_117 ) ;
F_55 ( V_146 + V_117 , V_7 -> V_107 [ 0 ] , V_144 - V_117 ) ;
} else {
F_55 ( V_146 , V_7 -> V_107 [ V_7 -> V_102 ] , V_144 ) ;
}
V_116 -> V_147 = F_56 ( V_116 , V_3 ) ;
F_57 ( V_116 ) ;
V_3 -> V_134 . V_148 ++ ;
V_3 -> V_134 . V_149 += V_144 ;
for ( V_8 = 1 ; V_8 < V_150 - 1 ; V_8 ++ ) {
if ( V_144 < ( V_8 * V_151 ) ) {
V_7 -> V_152 . V_153 [ V_8 ] ++ ;
V_8 = V_150 ;
}
}
if ( F_58 ( V_146 ) ) {
if ( F_59 ( V_146 ) ) {
V_7 -> V_152 . V_154 ++ ;
} else {
V_7 -> V_152 . V_155 ++ ;
}
} else if ( F_60 ( V_146 , V_3 -> V_36 ) == 0 ) {
V_7 -> V_152 . V_156 ++ ;
}
V_7 -> V_152 . V_153 [ 0 ] ++ ;
if ( V_7 -> V_152 . V_153 [ 0 ] == 0 ) {
memset ( ( char * ) & V_7 -> V_152 , 0 , sizeof( V_7 -> V_152 ) ) ;
}
} else {
F_8 ( L_22 , V_3 -> V_113 ) ;
V_3 -> V_134 . V_157 ++ ;
break;
}
}
for (; V_7 -> V_102 != V_130 ; V_7 -> V_102 = ( V_7 -> V_102 + 1 ) & V_7 -> V_64 ) {
F_36 ( F_50 ( & V_7 -> V_59 [ V_7 -> V_102 ] . V_105 ) | V_104 , & V_7 -> V_59 [ V_7 -> V_102 ] . V_105 ) ;
}
F_36 ( F_50 ( & V_7 -> V_59 [ V_130 ] . V_105 ) | V_104 , & V_7 -> V_59 [ V_130 ] . V_105 ) ;
}
V_7 -> V_100 = ( V_7 -> V_100 + 1 ) & V_7 -> V_64 ;
}
return 0 ;
}
static int F_47 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
int V_130 ;
V_67 V_13 ;
T_4 V_15 = V_3 -> V_17 ;
for ( V_130 = V_7 -> V_103 ; V_130 != V_7 -> V_101 ; V_130 = V_7 -> V_103 ) {
V_13 = F_50 ( & V_7 -> V_61 [ V_130 ] . V_105 ) >> 16 ;
if ( V_13 < 0 ) {
break;
} else if ( V_13 & V_158 ) {
V_13 = F_50 ( & V_7 -> V_61 [ V_130 ] . V_159 ) ;
V_3 -> V_134 . V_160 ++ ;
if ( V_13 & V_161 )
V_3 -> V_134 . V_162 ++ ;
if ( V_13 & V_163 )
V_3 -> V_134 . V_164 ++ ;
if ( V_13 & V_165 )
V_3 -> V_134 . V_166 ++ ;
if ( V_13 & V_167 )
V_3 -> V_134 . V_168 ++ ;
if ( V_13 & ( V_169 | V_167 ) ) {
F_21 ( V_98 , V_99 ) ;
F_21 ( V_84 | V_121 , V_24 ) ;
}
} else if ( V_13 & ( V_170 | V_171 ) ) {
V_3 -> V_134 . V_172 ++ ;
} else {
V_3 -> V_134 . V_173 ++ ;
}
V_7 -> V_103 = ( V_7 -> V_103 + 1 ) & V_7 -> V_65 ;
}
return 0 ;
}
static int F_61 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
T_3 V_14 ;
T_4 V_15 = V_3 -> V_17 ;
F_35 ( V_3 ) ;
F_21 ( V_98 , V_99 ) ;
if ( V_89 > 1 ) {
F_8 ( L_23 , V_3 -> V_113 , F_6 ( V_24 ) ) ;
}
F_21 ( V_25 , V_24 ) ;
if ( V_7 -> V_27 != V_28 ) {
V_14 = F_4 ( V_19 ) ;
V_14 &= ~ V_20 ;
F_5 ( V_14 , V_19 ) ;
}
F_62 ( V_3 -> V_69 , V_3 ) ;
return 0 ;
}
static void F_19 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
T_4 V_15 = V_3 -> V_17 ;
F_21 ( V_174 , V_99 ) ;
F_21 ( ( V_175 ) V_7 -> V_56 , V_24 ) ;
F_21 ( V_176 , V_99 ) ;
F_21 ( ( V_175 ) ( V_7 -> V_56 >> 16 ) , V_24 ) ;
F_21 ( V_177 , V_99 ) ;
F_21 ( V_178 , V_24 ) ;
F_21 ( V_98 , V_99 ) ;
}
static int F_34 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
T_4 V_15 = V_3 -> V_17 ;
int V_8 , V_13 = 0 ;
F_63 ( V_7 -> V_54 , & V_7 -> V_109 , sizeof( struct V_47 ) ) ;
F_21 ( V_98 , V_99 ) ;
F_21 ( V_85 , V_24 ) ;
for ( V_8 = 0 ; ( V_8 < 100 ) && ! ( F_6 ( V_24 ) & V_179 ) ; V_8 ++ ) ;
if ( V_8 != 100 ) {
F_21 ( V_179 | V_84 | V_180 , V_24 ) ;
if ( V_89 > 2 ) {
F_8 ( L_24 , V_3 -> V_113 , V_8 , V_7 -> V_16 , F_6 ( V_24 ) ) ;
}
} else {
F_8 ( L_25 , V_3 -> V_113 , V_8 , V_7 -> V_16 , F_6 ( V_24 ) ) ;
V_13 = - 1 ;
}
return V_13 ;
}
static void F_64 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
T_4 V_15 = V_3 -> V_17 ;
F_35 ( V_3 ) ;
while ( V_7 -> V_103 != V_7 -> V_101 ) ;
V_18 ;
F_18 ( V_3 ) ;
if ( V_3 -> V_181 & V_182 ) {
V_7 -> V_109 . V_112 |= V_183 ;
} else {
F_38 ( V_3 ) ;
V_7 -> V_109 . V_112 &= ~ V_183 ;
}
F_19 ( V_3 ) ;
F_34 ( V_3 ) ;
F_33 ( V_3 ) ;
}
static void F_38 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
struct V_184 * V_185 ;
int V_8 , V_9 , V_186 , V_187 ;
V_175 V_188 ;
T_8 V_189 ;
if ( V_3 -> V_181 & V_190 ) {
for ( V_8 = 0 ; V_8 < ( V_191 >> 3 ) ; V_8 ++ ) {
V_7 -> V_109 . V_192 [ V_8 ] = ( char ) 0xff ;
}
} else {
for ( V_8 = 0 ; V_8 < ( V_191 >> 3 ) ; V_8 ++ ) {
V_7 -> V_109 . V_192 [ V_8 ] = 0 ;
}
F_65 (ha, dev) {
V_189 = F_66 ( V_110 , V_185 -> V_193 ) ;
V_188 = ( V_189 & 1 ) ;
for ( V_9 = 0 ; V_9 < 5 ; V_9 ++ ) {
V_188 = ( V_188 << 1 ) | ( ( V_189 >>= 1 ) & 1 ) ;
}
V_187 = V_188 >> 3 ;
V_186 = 1 << ( V_188 & 0x07 ) ;
V_7 -> V_109 . V_192 [ V_187 ] |= V_186 ;
}
}
}
static int T_2 F_67 ( T_4 V_15 , struct V_4 * * V_194 )
{
int V_13 = 0 ;
if ( ! F_68 ( V_15 , V_195 , V_196 ) ) {
V_13 = - V_50 ;
goto V_118;
}
if ( F_69 ( V_15 ) ) {
V_13 = - V_197 ;
goto V_198;
}
if ( ! ( * V_194 = F_70 ( sizeof ( struct V_6 ) ) ) ) {
V_13 = - V_199 ;
goto V_198;
}
return 0 ;
V_198:
F_71 ( V_15 , V_195 ) ;
V_118:
return V_13 ;
}
static int T_2 F_72 ( struct V_5 * V_5 )
{
unsigned char V_200 [ 2 ] ;
unsigned char V_201 ;
unsigned long V_202 , V_16 ;
int V_69 , V_203 ;
struct V_204 * V_205 = F_11 ( V_5 ) ;
struct V_4 * V_3 ;
struct V_6 * V_7 ;
V_200 [ 0 ] = F_73 ( V_205 , 2 ) ;
V_200 [ 1 ] = F_73 ( V_205 , 3 ) ;
V_201 = ( V_200 [ 0 ] & 6 ) >> 1 ;
V_202 = 0x2c00 + ( 0x10 * V_201 ) ;
V_201 = V_200 [ 1 ] & 0x0f ;
switch ( V_201 ) {
case 1 :
V_69 = 9 ;
break;
case 2 :
V_69 = 5 ;
break;
case 4 :
V_69 = 10 ;
break;
case 8 :
V_69 = 11 ;
break;
default:
F_8 ( L_26 , V_205 -> V_113 , V_201 ) ;
return - V_206 ;
}
V_201 = ( V_200 [ 0 ] & 0x18 ) >> 3 ;
V_16 = 0xc0000 + ( V_201 * 0x10000 ) ;
if ( V_200 [ 0 ] & 0x20 ) {
V_16 += 0x8000 ;
}
strncpy ( V_205 -> V_113 , V_207 [ V_205 -> V_208 ] ,
sizeof( V_205 -> V_113 ) ) ;
F_74 ( V_205 , 1 ) ;
V_69 = F_75 ( V_205 , V_69 ) ;
V_202 = F_76 ( V_205 , V_202 ) ;
if ( ( V_203 = F_67 ( V_202 , & V_3 ) ) )
goto V_209;
V_3 -> V_69 = V_69 ;
V_3 -> V_17 = V_202 ;
V_7 = F_7 ( V_3 ) ;
V_7 -> V_31 = V_32 ;
V_7 -> V_27 = V_210 [ V_205 -> V_208 ] ;
V_7 -> V_16 = V_16 ;
if ( ( V_203 = F_3 ( V_3 , V_5 ) ) )
goto V_211;
return 0 ;
V_211:
F_77 ( V_3 ) ;
F_71 ( V_202 , V_195 ) ;
V_209:
F_74 ( V_205 , 0 ) ;
return V_203 ;
}
static void T_2 F_78 ( void )
{
int V_8 ;
struct V_1 * V_212 ;
for ( V_8 = 0 ; V_213 [ V_8 ] . V_202 ; V_8 ++ ) {
V_213 [ V_8 ] . V_5 = NULL ;
if ( V_214 && V_214 != V_213 [ V_8 ] . V_202 )
continue;
V_212 = F_79 ( V_196 , V_8 ) ;
if ( ! V_212 )
continue;
V_212 -> V_3 . V_215 = ( void * ) V_213 [ V_8 ] . V_202 ;
V_213 [ V_8 ] . V_5 = V_212 ;
if ( F_80 ( V_212 ) ) {
V_213 [ V_8 ] . V_5 = NULL ;
V_212 -> V_3 . V_215 = NULL ;
F_81 ( V_212 ) ;
continue;
}
if ( ! V_212 -> V_3 . V_216 ) {
V_213 [ V_8 ] . V_5 = NULL ;
V_212 -> V_3 . V_215 = NULL ;
F_82 ( V_212 ) ;
}
}
}
static enum V_217 T_2 F_83 ( T_9 * V_16 )
{
T_4 V_218 [] = V_219 ;
enum V_217 V_27 = V_29 ;
int V_8 ;
for ( V_8 = 0 ; V_218 [ V_8 ] ; V_8 ++ ) {
* V_16 = V_220 ? V_220 : V_218 [ V_8 ] ;
V_27 = F_84 ( V_49 , * V_16 ) ;
if ( V_27 != V_29 )
break;
}
return V_27 ;
}
static int T_10 F_85 ( struct V_1 * V_5 )
{
struct V_4 * V_3 ;
struct V_6 * V_7 ;
T_4 V_15 , V_16 = 0 ;
enum V_217 V_27 = V_29 ;
int V_13 = 0 ;
V_15 = ( T_4 ) V_5 -> V_3 . V_215 ;
if ( ( V_13 = F_67 ( V_15 , & V_3 ) ) )
goto V_118;
V_27 = F_83 ( & V_16 ) ;
if ( V_27 == V_29 ) {
V_13 = - V_197 ;
goto V_211;
}
V_3 -> V_17 = V_15 ;
V_3 -> V_69 = V_69 ;
V_7 = F_7 ( V_3 ) ;
V_7 -> V_31 = V_35 ;
V_7 -> V_27 = V_27 ;
V_7 -> V_16 = V_16 ;
if ( ( V_13 = F_3 ( V_3 , & V_5 -> V_3 ) ) )
goto V_211;
return 0 ;
V_211:
F_77 ( V_3 ) ;
F_71 ( V_15 , V_195 ) ;
V_118:
return V_13 ;
}
static int T_2 F_86 ( struct V_5 * V_5 )
{
enum V_217 V_27 = V_29 ;
struct V_221 * V_222 ;
struct V_4 * V_3 ;
struct V_6 * V_7 ;
T_4 V_15 , V_16 ;
int V_13 = 0 ;
V_222 = F_13 ( V_5 ) ;
V_15 = V_222 -> V_17 + V_223 ;
if ( ( V_13 = F_67 ( V_15 , & V_3 ) ) )
goto V_118;
V_27 = F_83 ( & V_16 ) ;
if ( V_27 == V_29 ) {
V_13 = - V_197 ;
goto V_211;
}
V_3 -> V_17 = V_15 ;
V_3 -> V_69 = V_69 ;
V_7 = F_7 ( V_3 ) ;
V_7 -> V_31 = V_34 ;
V_7 -> V_27 = V_222 -> V_224 . V_225 ;
V_7 -> V_16 = V_16 ;
if ( ( V_13 = F_3 ( V_3 , V_5 ) ) )
goto V_211;
return 0 ;
V_211:
F_77 ( V_3 ) ;
F_71 ( V_15 , V_195 ) ;
V_118:
return V_13 ;
}
static int T_1 F_2 ( struct V_5 * V_5 )
{
struct V_4 * V_3 ;
struct V_6 * V_7 ;
int V_226 ;
V_3 = F_87 ( V_5 ) ;
V_7 = F_7 ( V_3 ) ;
F_88 ( V_3 ) ;
F_28 ( V_7 -> V_54 ) ;
F_29 ( V_7 -> V_16 , V_7 -> V_12 ) ;
F_71 ( V_3 -> V_17 , V_195 ) ;
V_226 = V_7 -> V_31 ;
F_77 ( V_3 ) ;
return 0 ;
}
static int T_2 F_84 ( char * V_113 , T_4 V_17 )
{
T_5 V_8 , V_9 , V_227 ;
void T_11 * V_228 ;
char V_229 [ 16 ] ;
T_4 V_230 = V_17 + 0xc000 ;
T_4 V_231 = V_17 + 0x8000 ;
if ( ! F_16 ( V_231 , 16 , V_196 ) )
return V_29 ;
V_228 = F_17 ( V_230 , 16 ) ;
if ( V_228 == NULL ) {
F_8 ( V_51 L_27 , V_230 ) ;
return V_29 ;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
V_229 [ V_8 ] = F_89 ( V_228 + V_8 ) ;
}
F_28 ( V_228 ) ;
F_29 ( V_231 , 16 ) ;
for ( V_8 = 0 ; * V_30 [ V_8 ] != '\0' ; V_8 ++ ) {
for ( V_9 = 0 , V_227 = 0 ; V_9 < 16 && V_227 < strlen ( V_30 [ V_8 ] ) ; V_9 ++ ) {
if ( V_30 [ V_8 ] [ V_227 ] == V_229 [ V_9 ] ) {
V_227 ++ ;
} else {
V_227 = 0 ;
}
}
if ( V_227 == strlen ( V_30 [ V_8 ] ) )
break;
}
if ( V_113 && * V_113 && ( V_8 == V_29 ) ) {
for ( V_8 = 0 ; * V_30 [ V_8 ] != '\0' ; V_8 ++ ) {
if ( strcmp ( V_113 , V_30 [ V_8 ] ) == 0 )
break;
}
}
return V_8 ;
}
static int T_2 F_69 ( T_4 V_15 )
{
union {
struct {
T_8 V_232 ;
T_8 V_233 ;
} V_234 ;
char V_235 [ sizeof( T_8 ) << 1 ] ;
}
V_3 ;
short V_236 = 0 ;
T_12 V_237 ;
T_3 V_14 ;
int V_8 , V_9 , V_13 = 0 ;
V_237 = F_4 ( V_238 ) ;
V_237 = F_4 ( V_238 ) ;
if ( V_237 == 0x08 ) {
V_14 = F_4 ( V_19 ) ;
V_14 |= V_239 ;
F_5 ( V_14 , V_19 ) ;
}
V_3 . V_234 . V_232 = V_240 ;
V_3 . V_234 . V_233 = V_240 ;
V_236 = sizeof( T_8 ) << 1 ;
for ( V_8 = 0 , V_9 = 0 ; V_9 < V_236 && V_8 < V_241 + V_236 - 1 ; V_8 ++ ) {
V_237 = F_4 ( V_238 ) ;
if ( V_3 . V_235 [ V_9 ] == V_237 ) {
V_9 ++ ;
} else {
if ( V_237 == V_3 . V_235 [ 0 ] ) {
V_9 = 1 ;
} else {
V_9 = 0 ;
}
}
}
if ( V_9 != V_236 ) {
V_13 = - V_197 ;
}
return V_13 ;
}
static int T_2 F_14 ( struct V_4 * V_3 )
{
T_4 V_15 = V_3 -> V_17 ;
struct V_6 * V_7 = F_7 ( V_3 ) ;
int V_8 , V_227 , V_242 , V_13 = 0 ;
T_13 V_9 , V_243 , V_244 ;
V_243 = ( ( ( V_7 -> V_27 == V_73 ) || ( V_7 -> V_27 == V_74 ) ) ? 1 : 0 ) ;
for ( V_8 = 0 , V_227 = 0 , V_9 = 0 ; V_9 < 3 ; V_9 ++ ) {
V_227 <<= 1 ;
if ( V_227 > 0xffff )
V_227 -= 0xffff ;
V_227 += ( V_245 ) ( V_242 = F_4 ( V_238 + V_243 ) ) ;
V_3 -> V_36 [ V_8 ++ ] = ( V_245 ) V_242 ;
V_227 += ( T_13 ) ( ( V_242 = F_4 ( V_238 + V_243 ) ) << 8 ) ;
V_3 -> V_36 [ V_8 ++ ] = ( V_245 ) V_242 ;
if ( V_227 > 0xffff )
V_227 -= 0xffff ;
}
if ( V_227 == 0xffff )
V_227 = 0 ;
V_244 = ( V_245 ) F_4 ( V_238 + V_243 ) ;
V_244 |= ( T_13 ) ( F_4 ( V_238 + V_243 ) << 8 ) ;
if ( V_227 != V_244 )
V_13 = - 1 ;
return V_13 ;
}
static int F_43 ( struct V_4 * V_3 , struct V_115 * V_116 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
int V_8 , V_130 , V_246 , V_117 , V_13 = V_247 ;
V_130 = V_7 -> V_101 ;
V_246 = ( V_130 + ( V_116 -> V_117 - 1 ) / V_46 ) & V_7 -> V_65 ;
if ( ! ( F_50 ( & V_7 -> V_61 [ V_246 ] . V_105 ) & V_248 ) ) {
if ( V_246 < V_130 ) {
V_117 = ( V_7 -> V_65 - V_130 + 1 ) * V_46 ;
F_63 ( V_7 -> V_108 [ V_130 ] , V_116 -> V_237 , V_117 ) ;
F_63 ( V_7 -> V_108 [ 0 ] , V_116 -> V_237 + V_117 , V_116 -> V_117 - V_117 ) ;
} else {
F_63 ( V_7 -> V_108 [ V_130 ] , V_116 -> V_237 , V_116 -> V_117 ) ;
}
V_117 = ( V_116 -> V_117 < V_119 ) ? V_119 : V_116 -> V_117 ;
for ( V_8 = V_130 ; V_8 != V_246 ; V_8 = ( V_8 + 1 ) & V_7 -> V_65 ) {
F_36 ( F_50 ( & V_7 -> V_61 [ V_8 ] . V_105 ) & ~ V_249 , & V_7 -> V_61 [ V_8 ] . V_105 ) ;
F_37 ( 0x0000 , & V_7 -> V_61 [ V_8 ] . V_159 ) ;
F_37 ( - V_46 , & V_7 -> V_61 [ V_8 ] . V_250 ) ;
V_117 -= V_46 ;
}
F_36 ( F_50 ( & V_7 -> V_61 [ V_246 ] . V_105 ) & ~ V_249 , & V_7 -> V_61 [ V_246 ] . V_105 ) ;
F_37 ( 0x0000 , & V_7 -> V_61 [ V_246 ] . V_159 ) ;
F_37 ( - V_117 , & V_7 -> V_61 [ V_246 ] . V_250 ) ;
F_36 ( F_50 ( & V_7 -> V_61 [ V_130 ] . V_105 ) | V_251 , & V_7 -> V_61 [ V_130 ] . V_105 ) ;
F_36 ( F_50 ( & V_7 -> V_61 [ V_246 ] . V_105 ) | V_252 , & V_7 -> V_61 [ V_246 ] . V_105 ) ;
for ( V_8 = V_246 ; V_8 != V_130 ; -- V_8 ) {
F_36 ( F_50 ( & V_7 -> V_61 [ V_8 ] . V_105 ) | V_248 , & V_7 -> V_61 [ V_8 ] . V_105 ) ;
if ( V_8 == 0 )
V_8 = V_7 -> V_65 + 1 ;
}
F_36 ( F_50 ( & V_7 -> V_61 [ V_130 ] . V_105 ) | V_248 , & V_7 -> V_61 [ V_130 ] . V_105 ) ;
V_7 -> V_101 = ( ++ V_246 ) & V_7 -> V_65 ;
} else {
V_13 = V_122 ;
}
return V_13 ;
}
static void F_31 ( struct V_4 * V_3 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
T_4 V_15 = V_3 -> V_17 ;
struct V_47 * V_253 = & V_7 -> V_109 ;
int V_8 ;
if ( V_89 > 1 ) {
F_8 ( L_28 , V_3 -> V_113 , V_3 -> V_69 ) ;
F_8 ( L_29 ) ;
F_8 ( L_30 , ( T_4 ) V_7 -> V_59 , ( T_4 ) V_7 -> V_61 ) ;
F_8 ( L_31 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_64 ; V_8 ++ ) {
if ( V_8 < 3 ) {
F_8 ( L_32 , & V_7 -> V_59 [ V_8 ] . V_105 ) ;
}
}
F_8 ( L_33 , & V_7 -> V_59 [ V_8 ] . V_105 ) ;
F_8 ( L_34 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_65 ; V_8 ++ ) {
if ( V_8 < 3 ) {
F_8 ( L_32 , & V_7 -> V_61 [ V_8 ] . V_105 ) ;
}
}
F_8 ( L_33 , & V_7 -> V_61 [ V_8 ] . V_105 ) ;
F_8 ( L_35 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_64 ; V_8 ++ ) {
if ( V_8 < 3 ) {
F_8 ( L_36 , F_50 ( & V_7 -> V_59 [ V_8 ] . V_105 ) ) ;
}
}
F_8 ( L_37 , F_50 ( & V_7 -> V_59 [ V_8 ] . V_105 ) ) ;
F_8 ( L_34 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_65 ; V_8 ++ ) {
if ( V_8 < 3 ) {
F_8 ( L_36 , F_50 ( & V_7 -> V_61 [ V_8 ] . V_105 ) ) ;
}
}
F_8 ( L_37 , F_50 ( & V_7 -> V_61 [ V_8 ] . V_105 ) ) ;
F_8 ( L_38 , V_7 -> V_16 ) ;
F_8 ( L_39 , V_253 -> V_112 ) ;
F_8 ( L_40 , V_253 -> V_111 ) ;
F_8 ( L_41 ) ;
for ( V_8 = 0 ; V_8 < ( V_191 >> 3 ) - 1 ; V_8 ++ ) {
F_8 ( L_42 , V_253 -> V_192 [ V_8 ] ) ;
}
F_8 ( L_43 , V_253 -> V_192 [ V_8 ] ) ;
F_8 ( L_44 , V_253 -> V_59 ) ;
F_8 ( L_45 , V_253 -> V_61 ) ;
F_8 ( L_46 , V_7 -> V_16 + V_7 -> V_63 ) ;
F_8 ( L_47 , ( int ) V_7 -> V_64 + 1 , V_7 -> V_66 ) ;
F_8 ( L_48 , ( int ) V_7 -> V_65 + 1 , V_7 -> V_68 ) ;
F_21 ( V_176 , V_99 ) ;
F_8 ( L_49 , F_6 ( V_24 ) ) ;
F_21 ( V_174 , V_99 ) ;
F_8 ( L_50 , F_6 ( V_24 ) ) ;
F_21 ( V_177 , V_99 ) ;
F_8 ( L_51 , F_6 ( V_24 ) ) ;
}
}
static int F_90 ( struct V_4 * V_3 , struct V_254 * V_255 , int V_256 )
{
struct V_6 * V_7 = F_7 ( V_3 ) ;
struct F_90 * V_257 = (struct F_90 * ) & V_255 -> V_258 ;
int V_8 , V_13 = 0 ;
T_4 V_15 = V_3 -> V_17 ;
union {
T_14 V_193 [ ( V_191 * V_110 ) ] ;
V_175 V_259 [ ( V_191 * V_110 ) >> 1 ] ;
T_8 V_260 [ ( V_191 * V_110 ) >> 2 ] ;
} V_242 ;
unsigned long V_181 ;
void * V_146 ;
switch ( V_257 -> V_256 ) {
case V_261 :
for ( V_8 = 0 ; V_8 < V_110 ; V_8 ++ ) {
V_242 . V_193 [ V_8 ] = V_3 -> V_36 [ V_8 ] ;
}
V_257 -> V_117 = V_110 ;
if ( F_91 ( V_257 -> V_237 , V_242 . V_193 , V_257 -> V_117 ) )
return - V_262 ;
break;
case V_263 :
if ( ! F_92 ( V_264 ) )
return - V_265 ;
if ( F_93 ( V_242 . V_193 , V_257 -> V_237 , V_110 ) )
return - V_262 ;
for ( V_8 = 0 ; V_8 < V_110 ; V_8 ++ ) {
V_3 -> V_36 [ V_8 ] = V_242 . V_193 [ V_8 ] ;
}
F_35 ( V_3 ) ;
while ( V_7 -> V_103 != V_7 -> V_101 )
F_94 () ;
V_18 ;
F_18 ( V_3 ) ;
F_19 ( V_3 ) ;
F_34 ( V_3 ) ;
F_33 ( V_3 ) ;
break;
case V_266 :
if ( ! F_92 ( V_264 ) )
return - V_265 ;
F_35 ( V_3 ) ;
while ( V_7 -> V_103 != V_7 -> V_101 )
F_94 () ;
V_18 ;
F_18 ( V_3 ) ;
V_7 -> V_109 . V_112 |= V_183 ;
F_19 ( V_3 ) ;
F_34 ( V_3 ) ;
F_33 ( V_3 ) ;
break;
case V_267 :
if ( ! F_92 ( V_264 ) )
return - V_265 ;
F_35 ( V_3 ) ;
while ( V_7 -> V_103 != V_7 -> V_101 )
F_94 () ;
V_18 ;
F_18 ( V_3 ) ;
V_7 -> V_109 . V_112 &= ~ V_183 ;
F_19 ( V_3 ) ;
F_34 ( V_3 ) ;
F_33 ( V_3 ) ;
break;
case V_268 :
if( ! F_92 ( V_264 ) )
return - V_265 ;
F_8 ( L_52 , V_3 -> V_113 ) ;
break;
case V_269 :
V_257 -> V_117 = ( V_191 >> 3 ) ;
if ( F_91 ( V_257 -> V_237 , V_7 -> V_109 . V_192 , V_257 -> V_117 ) )
return - V_262 ;
break;
case V_270 :
if ( ! F_92 ( V_264 ) )
return - V_265 ;
if ( V_257 -> V_117 >= V_191 )
return - V_206 ;
if ( F_93 ( V_242 . V_193 , V_257 -> V_237 , V_110 * V_257 -> V_117 ) )
return - V_262 ;
F_64 ( V_3 ) ;
break;
case V_271 :
if ( ! F_92 ( V_264 ) )
return - V_265 ;
F_64 ( V_3 ) ;
break;
case V_272 :
if ( ! F_92 ( V_264 ) )
return - V_265 ;
F_64 ( V_3 ) ;
break;
case V_273 :
V_257 -> V_117 = sizeof( V_7 -> V_152 ) ;
V_146 = F_95 ( V_257 -> V_117 , V_274 ) ;
if( ! V_146 )
return - V_199 ;
F_96 ( & V_7 -> V_48 , V_181 ) ;
memcpy ( V_146 , & V_7 -> V_152 , V_257 -> V_117 ) ;
F_97 ( & V_7 -> V_48 , V_181 ) ;
if ( F_91 ( V_257 -> V_237 , V_146 , V_257 -> V_117 ) )
V_13 = - V_262 ;
F_98 ( V_146 ) ;
break;
case V_275 :
if ( ! F_92 ( V_264 ) )
return - V_265 ;
F_96 ( & V_7 -> V_48 , V_181 ) ;
memset ( & V_7 -> V_152 , 0 , sizeof( V_7 -> V_152 ) ) ;
F_97 ( & V_7 -> V_48 , V_181 ) ;
break;
case V_276 :
V_8 = 0 ;
V_242 . V_259 [ V_8 ++ ] = F_6 ( V_19 ) ;
F_21 ( V_98 , V_99 ) ;
V_242 . V_259 [ V_8 ++ ] = F_6 ( V_24 ) ;
memcpy ( & V_242 . V_259 [ V_8 ] , & V_7 -> V_109 , sizeof( struct V_47 ) ) ;
V_257 -> V_117 = V_8 + sizeof( struct V_47 ) ;
if ( F_91 ( V_257 -> V_237 , V_242 . V_193 , V_257 -> V_117 ) )
return - V_262 ;
break;
default:
return - V_277 ;
}
return V_13 ;
}
static int T_2 F_99 ( void )
{
int V_203 = 0 ;
#ifdef F_10
V_203 = F_100 ( & V_278 ) ;
if ( V_203 )
goto V_203;
#endif
#ifdef F_12
V_203 = F_101 ( & V_279 ) ;
if ( V_203 )
goto V_280;
#endif
V_203 = F_102 ( & V_281 ) ;
if ( V_203 )
goto V_282;
F_78 () ;
return 0 ;
V_282:
#ifdef F_12
F_103 ( & V_279 ) ;
V_280:
#endif
#ifdef F_10
F_104 ( & V_278 ) ;
V_203:
#endif
return V_203 ;
}
static void T_15 F_105 ( void )
{
int V_8 ;
#ifdef F_10
F_104 ( & V_278 ) ;
#endif
#ifdef F_12
F_103 ( & V_279 ) ;
#endif
F_106 ( & V_281 ) ;
for ( V_8 = 0 ; V_213 [ V_8 ] . V_202 ; V_8 ++ ) {
if ( V_213 [ V_8 ] . V_5 ) {
V_213 [ V_8 ] . V_5 -> V_3 . V_215 = NULL ;
F_82 ( V_213 [ V_8 ] . V_5 ) ;
V_213 [ V_8 ] . V_5 = NULL ;
}
}
}
