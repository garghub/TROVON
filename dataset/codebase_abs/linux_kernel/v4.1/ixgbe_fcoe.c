static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 1 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = 0UL ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
}
int F_2 ( struct V_9 * V_10 , T_1 V_11 )
{
int V_3 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
T_2 V_18 ;
if ( ! V_10 )
return 0 ;
if ( V_11 >= V_19 )
return 0 ;
V_15 = F_3 ( V_10 ) ;
V_13 = & V_15 -> V_13 ;
V_2 = & V_13 -> V_2 [ V_11 ] ;
if ( ! V_2 -> V_5 )
return 0 ;
V_17 = & V_15 -> V_17 ;
V_3 = V_2 -> V_3 ;
if ( ! V_2 -> V_4 )
goto V_20;
if ( V_17 -> V_21 . type == V_22 ) {
F_4 ( V_17 , F_5 ( 0 , V_11 ) , 0 ) ;
F_4 ( V_17 , F_5 ( 3 , V_11 ) ,
( V_11 | V_23 ) ) ;
F_4 ( V_17 , F_6 ( 2 , V_11 ) , 0 ) ;
F_4 ( V_17 , F_6 ( 3 , V_11 ) ,
( V_11 | V_24 ) ) ;
F_4 ( V_17 , F_6 ( 3 , V_11 ) ,
( V_11 | V_25 ) ) ;
V_18 = F_7 ( V_17 , F_6 ( 2 , V_11 ) ) ;
} else {
F_8 ( & V_13 -> V_26 ) ;
F_4 ( V_17 , V_27 , 0 ) ;
F_4 ( V_17 , V_28 ,
( V_11 | V_23 ) ) ;
F_4 ( V_17 , V_29 , 0 ) ;
F_4 ( V_17 , V_30 ,
( V_11 | V_24 ) ) ;
F_4 ( V_17 , V_30 ,
( V_11 | V_25 ) ) ;
V_18 = F_7 ( V_17 , V_29 ) ;
F_9 ( & V_13 -> V_26 ) ;
}
if ( V_18 & V_31 )
F_10 ( 100 , 150 ) ;
V_20:
if ( V_2 -> V_7 )
F_11 ( & V_15 -> V_32 -> V_33 , V_2 -> V_7 , V_2 -> V_8 ,
V_34 ) ;
if ( V_2 -> V_35 ) {
F_12 ( V_2 -> V_35 , V_2 -> V_5 , V_2 -> V_6 ) ;
V_2 -> V_35 = NULL ;
}
F_1 ( V_2 ) ;
return V_3 ;
}
static int F_13 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_36 * V_7 , unsigned int V_8 ,
int V_37 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_38 * V_39 ;
struct V_36 * V_40 ;
unsigned int V_41 , V_42 , V_43 ;
unsigned int V_3 ;
static const unsigned int V_44 = V_45 ;
unsigned int V_46 = 0 ;
unsigned int V_47 ;
unsigned int V_48 = 0 ;
unsigned int V_49 = 0 ;
T_2 V_18 , V_50 , V_51 , V_52 ;
T_3 V_53 = 0 ;
if ( ! V_10 || ! V_7 )
return 0 ;
V_15 = F_3 ( V_10 ) ;
if ( V_11 >= V_19 ) {
F_14 ( V_54 , L_1 , V_11 ) ;
return 0 ;
}
if ( F_15 ( V_55 , & V_15 -> V_56 ) ||
F_15 ( V_57 , & V_15 -> V_56 ) )
return 0 ;
V_13 = & V_15 -> V_13 ;
V_2 = & V_13 -> V_2 [ V_11 ] ;
if ( V_2 -> V_7 ) {
F_16 ( V_54 , L_2 ,
V_11 , V_2 -> V_7 , V_2 -> V_8 ) ;
return 0 ;
}
F_1 ( V_2 ) ;
if ( ! V_13 -> V_39 ) {
F_14 ( V_54 , L_3 ) ;
return 0 ;
}
V_39 = F_17 ( V_13 -> V_39 , F_18 () ) ;
if ( ! V_39 -> V_35 ) {
F_14 ( V_54 , L_4 , V_11 ) ;
goto V_58;
}
V_43 = F_19 ( & V_15 -> V_32 -> V_33 , V_7 , V_8 , V_34 ) ;
if ( V_43 == 0 ) {
F_16 ( V_54 , L_5 , V_11 ) ;
goto V_58;
}
V_2 -> V_5 = F_20 ( V_39 -> V_35 , V_59 , & V_2 -> V_6 ) ;
if ( ! V_2 -> V_5 ) {
F_16 ( V_54 , L_6 ) ;
goto V_60;
}
V_2 -> V_35 = V_39 -> V_35 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
V_42 = 0 ;
F_21 (sgl, sg, dmacount, i) {
V_53 = F_22 ( V_40 ) ;
V_3 = F_23 ( V_40 ) ;
while ( V_3 ) {
if ( V_42 >= V_61 ) {
V_39 -> V_62 ++ ;
goto V_63;
}
V_48 = V_53 & ( ( T_3 ) V_44 - 1 ) ;
V_49 = F_24 ( ( V_44 - V_48 ) , V_3 ) ;
if ( ( V_42 != 0 ) && ( V_48 ) )
goto V_63;
if ( ( ( V_41 != ( V_43 - 1 ) ) || ( V_49 != V_3 ) )
&& ( ( V_49 + V_48 ) != V_44 ) )
goto V_63;
V_2 -> V_5 [ V_42 ] = ( V_64 ) ( V_53 - V_48 ) ;
if ( V_42 == 0 )
V_46 = V_48 ;
V_3 -= V_49 ;
V_53 += V_49 ;
V_42 ++ ;
}
}
V_47 = V_48 + V_49 ;
if ( V_47 == V_44 ) {
if ( V_42 >= V_61 ) {
V_39 -> V_65 ++ ;
goto V_63;
}
V_2 -> V_5 [ V_42 ] = ( V_64 ) ( V_13 -> V_66 ) ;
V_42 ++ ;
V_47 = 1 ;
}
F_25 () ;
V_18 = ( V_67 << V_68 ) ;
V_18 |= ( ( V_42 & 0xff ) << V_69 ) ;
V_18 |= ( V_46 << V_70 ) ;
if ( V_37 )
V_18 |= ( V_71 ) ;
V_18 |= ( V_31 ) ;
V_50 = V_11 ;
V_50 |= V_24 ;
V_50 |= ( V_47 << V_72 ) ;
V_51 = V_11 ;
V_51 |= V_23 ;
V_17 = & V_15 -> V_17 ;
if ( V_37 && ! F_15 ( V_73 , & V_13 -> V_74 ) ) {
F_26 ( V_73 , & V_13 -> V_74 ) ;
V_52 = F_7 ( V_17 , V_75 ) ;
V_52 |= V_76 ;
F_4 ( V_17 , V_75 , V_52 ) ;
}
if ( V_17 -> V_21 . type == V_22 ) {
F_4 ( V_17 , F_6 ( 0 , V_11 ) ,
V_2 -> V_6 & F_27 ( 32 ) ) ;
F_4 ( V_17 , F_6 ( 1 , V_11 ) , ( V_64 ) V_2 -> V_6 >> 32 ) ;
F_4 ( V_17 , F_6 ( 2 , V_11 ) , V_18 ) ;
F_4 ( V_17 , F_6 ( 3 , V_11 ) , V_50 ) ;
F_4 ( V_17 , F_5 ( 0 , V_11 ) , V_77 ) ;
F_4 ( V_17 , F_5 ( 1 , V_11 ) , 0 ) ;
F_4 ( V_17 , F_5 ( 3 , V_11 ) , V_51 ) ;
} else {
F_8 ( & V_13 -> V_26 ) ;
F_4 ( V_17 , V_78 , V_2 -> V_6 & F_27 ( 32 ) ) ;
F_4 ( V_17 , V_79 , ( V_64 ) V_2 -> V_6 >> 32 ) ;
F_4 ( V_17 , V_29 , V_18 ) ;
F_4 ( V_17 , V_30 , V_50 ) ;
F_4 ( V_17 , V_80 , 0 ) ;
F_4 ( V_17 , V_27 , V_77 ) ;
F_4 ( V_17 , V_28 , V_51 ) ;
F_9 ( & V_13 -> V_26 ) ;
}
return 1 ;
V_63:
F_12 ( V_2 -> V_35 , V_2 -> V_5 , V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
V_60:
F_11 ( & V_15 -> V_32 -> V_33 , V_7 , V_8 , V_34 ) ;
V_58:
F_25 () ;
return 0 ;
}
int F_28 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_36 * V_7 , unsigned int V_8 )
{
return F_13 ( V_10 , V_11 , V_7 , V_8 , 0 ) ;
}
int F_29 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_36 * V_7 , unsigned int V_8 )
{
return F_13 ( V_10 , V_11 , V_7 , V_8 , 1 ) ;
}
int V_1 ( struct V_14 * V_15 ,
union V_81 * V_82 ,
struct V_83 * V_84 )
{
int V_85 = - V_86 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
T_4 V_91 = F_30 ( V_82 , V_92 ) ;
T_4 V_93 ;
int V_94 ;
T_2 V_95 ;
T_1 V_11 ;
if ( V_91 == F_31 ( V_96 ) )
V_84 -> V_97 = V_98 ;
else
V_84 -> V_97 = V_99 ;
if ( F_32 ( V_84 ) -> V_100 == F_33 ( V_101 ) )
V_88 = (struct V_87 * ) ( V_84 -> V_102 +
sizeof( struct V_103 ) + sizeof( struct V_104 ) ) ;
else
V_88 = (struct V_87 * ) ( V_84 -> V_102 +
sizeof( struct V_104 ) ) ;
V_95 = F_34 ( V_88 -> V_105 ) ;
if ( V_95 & V_106 )
V_11 = F_35 ( V_88 -> V_107 ) ;
else
V_11 = F_35 ( V_88 -> V_108 ) ;
V_94 = V_19 ;
if ( V_15 -> V_17 . V_21 . type == V_22 )
V_94 = V_109 ;
if ( V_11 >= V_94 )
return - V_86 ;
V_13 = & V_15 -> V_13 ;
V_2 = & V_13 -> V_2 [ V_11 ] ;
if ( ! V_2 -> V_5 )
return - V_86 ;
V_93 = F_30 ( V_82 , V_110 |
V_92 ) ;
if ( V_93 )
return - V_86 ;
switch ( F_30 ( V_82 , V_111 ) ) {
case F_31 ( V_112 ) :
V_2 -> V_3 = F_36 ( V_82 -> V_113 . V_114 . V_115 . V_116 ) ;
V_85 = 0 ;
break;
case F_31 ( V_117 ) :
F_11 ( & V_15 -> V_32 -> V_33 , V_2 -> V_7 ,
V_2 -> V_8 , V_34 ) ;
V_2 -> V_4 = V_93 ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
case F_31 ( V_118 ) :
V_2 -> V_3 = F_36 ( V_82 -> V_113 . V_114 . V_115 . V_116 ) ;
if ( V_2 -> V_3 )
V_85 = V_2 -> V_3 ;
break;
case F_31 ( V_119 ) :
default:
break;
}
if ( ( V_88 -> V_120 == V_121 ) &&
( V_95 & V_122 ) ) {
F_37 ( V_84 ) ;
V_90 = (struct V_89 * ) F_38 ( V_84 , sizeof( * V_90 ) ) ;
V_90 -> V_123 = V_124 ;
}
return V_85 ;
}
int F_39 ( struct V_125 * V_126 ,
struct V_127 * V_128 ,
T_5 * V_129 )
{
struct V_83 * V_84 = V_128 -> V_84 ;
struct V_87 * V_88 ;
T_2 V_130 ;
T_2 V_131 = 0 ;
T_2 V_132 ;
T_5 V_133 , V_134 ;
if ( F_40 ( V_84 ) && ( F_41 ( V_84 ) -> V_135 != V_136 ) ) {
F_42 ( V_126 -> V_33 , L_7 ,
F_41 ( V_84 ) -> V_135 ) ;
return - V_86 ;
}
F_43 ( V_84 , V_84 -> V_137 ) ;
F_44 ( V_84 , V_84 -> V_137 +
sizeof( struct V_104 ) ) ;
V_133 = ( (struct V_104 * ) F_45 ( V_84 ) ) -> V_138 ;
switch ( V_133 ) {
case V_139 :
V_131 = V_140 ;
break;
case V_141 :
V_131 = V_142 |
V_140 ;
break;
case V_143 :
break;
case V_144 :
V_131 = V_142 ;
break;
default:
F_46 ( V_126 -> V_33 , L_8 , V_133 ) ;
return - V_86 ;
}
F_47 ( V_84 , V_84 -> V_3 - 4 , & V_134 , 1 ) ;
switch ( V_134 ) {
case V_145 :
V_131 |= V_146 ;
break;
case V_124 :
if ( F_40 ( V_84 ) )
V_131 |= V_146 |
V_147 ;
else
V_131 |= V_148 ;
break;
case V_149 :
V_131 |= V_150 ;
break;
case V_151 :
V_131 |= V_152 ;
break;
default:
F_46 ( V_126 -> V_33 , L_9 , V_134 ) ;
return - V_86 ;
}
V_88 = (struct V_87 * ) F_48 ( V_84 ) ;
if ( V_88 -> V_105 [ 2 ] & V_153 )
V_131 |= V_154 ;
* V_129 = sizeof( struct V_89 ) ;
if ( F_40 ( V_84 ) ) {
* V_129 += F_49 ( V_84 ) +
sizeof( struct V_87 ) ;
V_128 -> V_155 = F_50 ( V_84 -> V_3 - * V_129 ,
F_41 ( V_84 ) -> V_156 ) ;
V_128 -> V_157 += ( V_128 -> V_155 - 1 ) * * V_129 ;
V_128 -> V_158 |= V_159 ;
}
V_128 -> V_158 |= V_160 | V_161 ;
V_132 = F_41 ( V_84 ) -> V_156 << V_162 ;
V_130 = F_49 ( V_84 ) +
sizeof( struct V_87 ) ;
V_130 |= ( F_49 ( V_84 ) - 4 )
<< V_163 ;
V_130 |= V_128 -> V_158 & V_164 ;
F_51 ( V_126 , V_130 , V_131 ,
V_165 , V_132 ) ;
return 0 ;
}
static void F_52 ( struct V_12 * V_13 , unsigned int V_166 )
{
struct V_38 * V_39 ;
V_39 = F_17 ( V_13 -> V_39 , V_166 ) ;
if ( V_39 -> V_35 )
F_53 ( V_39 -> V_35 ) ;
V_39 -> V_35 = NULL ;
}
static int F_54 ( struct V_12 * V_13 ,
struct V_167 * V_33 ,
unsigned int V_166 )
{
struct V_38 * V_39 ;
struct V_168 * V_35 ;
char V_169 [ 32 ] ;
snprintf ( V_169 , 32 , L_10 , V_166 ) ;
V_35 = F_55 ( V_169 , V_33 , V_170 ,
V_171 , V_172 ) ;
if ( ! V_35 )
return - V_173 ;
V_39 = F_17 ( V_13 -> V_39 , V_166 ) ;
V_39 -> V_35 = V_35 ;
V_39 -> V_62 = 0 ;
V_39 -> V_65 = 0 ;
return 0 ;
}
void F_56 ( struct V_14 * V_15 )
{
struct V_174 * V_13 = & V_15 -> V_175 [ V_176 ] ;
struct V_16 * V_17 = & V_15 -> V_17 ;
int V_41 , V_177 , V_178 , V_179 = 0 ;
int V_180 ;
T_2 V_181 ;
if ( ! ( V_15 -> V_10 -> V_182 & V_183 ) )
return;
V_181 = V_184 | V_185 | V_186 ;
if ( V_15 -> V_187 & V_188 ) {
V_181 |= V_189 ;
V_181 |= F_57 ( 0 ) << V_190 ;
}
F_4 ( V_17 , F_58 ( V_191 ) , V_181 ) ;
F_4 ( V_17 , F_59 ( V_191 ) , 0 ) ;
if ( ! ( V_15 -> V_187 & V_192 ) )
return;
V_180 = V_193 ;
if ( V_15 -> V_17 . V_21 . type == V_22 )
V_180 = V_194 ;
for ( V_41 = 0 ; V_41 < V_180 ; V_41 ++ ) {
if ( V_15 -> V_17 . V_21 . type == V_22 ) {
int V_195 = V_13 -> V_196 + ( ( V_41 + V_180 ) %
V_13 -> V_197 ) ;
V_179 = V_15 -> V_198 [ V_195 ] -> V_199 ;
V_179 = ( V_179 << V_200 ) &
V_201 ;
}
V_178 = V_13 -> V_196 + ( V_41 % V_13 -> V_197 ) ;
V_178 &= V_202 ;
V_177 = V_15 -> V_198 [ V_178 ] -> V_199 ;
V_177 |= V_179 ;
F_4 ( V_17 , F_60 ( V_41 ) , V_177 ) ;
}
F_4 ( V_17 , V_203 , V_204 ) ;
V_181 = V_205 | V_186 ;
if ( V_15 -> V_187 & V_188 ) {
V_181 |= V_189 ;
V_181 |= F_57 ( 0 ) << V_190 ;
}
F_4 ( V_17 , F_58 ( V_206 ) , V_181 ) ;
V_177 = V_15 -> V_198 [ V_13 -> V_196 ] -> V_199 ;
F_4 ( V_17 , F_59 ( V_206 ) ,
V_207 |
( V_177 << V_208 ) ) ;
F_4 ( V_17 , V_75 ,
V_209 |
( V_210 << V_211 ) ) ;
}
void F_61 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
int V_166 , V_41 , V_94 ;
if ( ! V_13 -> V_39 )
return;
V_94 = V_19 ;
if ( V_15 -> V_17 . V_21 . type == V_22 )
V_94 = V_109 ;
for ( V_41 = 0 ; V_41 < V_94 ; V_41 ++ )
F_2 ( V_15 -> V_10 , V_41 ) ;
F_62 (cpu)
F_52 ( V_13 , V_166 ) ;
F_63 ( & V_15 -> V_32 -> V_33 ,
V_13 -> V_66 ,
V_45 ,
V_34 ) ;
F_64 ( V_13 -> V_212 ) ;
V_13 -> V_212 = NULL ;
V_13 -> V_66 = 0 ;
}
int F_65 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
struct V_167 * V_33 = & V_15 -> V_32 -> V_33 ;
void * V_213 ;
T_3 V_214 ;
unsigned int V_166 ;
if ( ! V_13 -> V_39 )
return 0 ;
V_213 = F_66 ( V_45 , V_59 ) ;
if ( ! V_213 )
return - V_173 ;
V_214 = F_67 ( V_33 , V_213 , V_45 , V_34 ) ;
if ( F_68 ( V_33 , V_214 ) ) {
F_16 ( V_54 , L_11 ) ;
F_64 ( V_213 ) ;
return - V_173 ;
}
V_13 -> V_212 = V_213 ;
V_13 -> V_66 = V_214 ;
F_62 (cpu) {
int V_4 = F_54 ( V_13 , V_33 , V_166 ) ;
if ( ! V_4 )
continue;
F_16 ( V_54 , L_12 , V_166 ) ;
F_61 ( V_15 ) ;
return - V_173 ;
}
return 0 ;
}
static int F_69 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
if ( ! ( V_15 -> V_187 & V_215 ) )
return - V_86 ;
V_13 -> V_39 = F_70 ( struct V_38 ) ;
if ( ! V_13 -> V_39 ) {
F_16 ( V_54 , L_13 ) ;
return - V_173 ;
}
V_15 -> V_10 -> V_216 = V_19 - 1 ;
if ( V_15 -> V_17 . V_21 . type == V_22 )
V_15 -> V_10 -> V_216 = V_109 - 1 ;
return 0 ;
}
static void F_71 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
V_15 -> V_10 -> V_216 = 0 ;
if ( ! V_13 -> V_39 )
return;
F_72 ( V_13 -> V_39 ) ;
V_13 -> V_39 = NULL ;
}
int F_73 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
struct V_12 * V_13 = & V_15 -> V_13 ;
F_74 ( & V_13 -> V_217 ) ;
if ( ! ( V_15 -> V_187 & V_215 ) )
return - V_86 ;
if ( V_15 -> V_187 & V_192 )
return - V_86 ;
F_75 ( V_54 , L_14 ) ;
if ( V_15 -> V_187 & V_188 )
F_14 ( V_218 , L_15 ) ;
if ( F_76 ( V_10 ) )
V_10 -> V_219 -> V_220 ( V_10 ) ;
F_69 ( V_15 ) ;
V_15 -> V_187 |= V_192 ;
V_10 -> V_182 |= V_221 ;
F_77 ( V_10 ) ;
F_78 ( V_15 ) ;
F_79 ( V_15 ) ;
if ( F_76 ( V_10 ) )
V_10 -> V_219 -> V_222 ( V_10 ) ;
return 0 ;
}
int F_80 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
if ( ! F_81 ( & V_15 -> V_13 . V_217 ) )
return - V_86 ;
if ( ! ( V_15 -> V_187 & V_192 ) )
return - V_86 ;
F_75 ( V_54 , L_16 ) ;
if ( F_76 ( V_10 ) )
V_10 -> V_219 -> V_220 ( V_10 ) ;
F_71 ( V_15 ) ;
V_15 -> V_187 &= ~ V_192 ;
V_10 -> V_182 &= ~ V_221 ;
F_77 ( V_10 ) ;
F_78 ( V_15 ) ;
F_79 ( V_15 ) ;
if ( F_76 ( V_10 ) )
V_10 -> V_219 -> V_222 ( V_10 ) ;
return 0 ;
}
int F_82 ( struct V_9 * V_10 , V_64 * V_223 , int type )
{
T_1 V_224 = 0xffff ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
struct V_225 * V_21 = & V_15 -> V_17 . V_21 ;
switch ( type ) {
case V_226 :
V_224 = V_21 -> V_227 ;
break;
case V_228 :
V_224 = V_21 -> V_229 ;
break;
default:
break;
}
if ( ( V_224 != 0xffff ) &&
F_83 ( V_21 -> V_230 ) ) {
* V_223 = ( ( V_64 ) V_224 << 48 ) |
( ( V_64 ) V_21 -> V_230 [ 0 ] << 40 ) |
( ( V_64 ) V_21 -> V_230 [ 1 ] << 32 ) |
( ( V_64 ) V_21 -> V_230 [ 2 ] << 24 ) |
( ( V_64 ) V_21 -> V_230 [ 3 ] << 16 ) |
( ( V_64 ) V_21 -> V_230 [ 4 ] << 8 ) |
( ( V_64 ) V_21 -> V_230 [ 5 ] ) ;
return 0 ;
}
return - V_86 ;
}
int F_84 ( struct V_9 * V_10 ,
struct V_231 * V_232 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
int V_41 , V_233 ;
T_5 V_234 [ 8 ] ;
if ( ! V_232 )
return - V_86 ;
if ( V_17 -> V_21 . type != V_235 &&
V_17 -> V_21 . type != V_236 )
return - V_86 ;
snprintf ( V_232 -> V_237 , sizeof( V_232 -> V_237 ) ,
L_17 ) ;
V_233 = F_85 ( V_15 -> V_32 , V_238 ) ;
if ( V_233 ) {
V_233 += 4 ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ )
F_86 ( V_15 -> V_32 , V_233 + V_41 , & V_234 [ V_41 ] ) ;
snprintf ( V_232 -> V_239 , sizeof( V_232 -> V_239 ) ,
L_18 ,
V_234 [ 7 ] , V_234 [ 6 ] , V_234 [ 5 ] , V_234 [ 4 ] ,
V_234 [ 3 ] , V_234 [ 2 ] , V_234 [ 1 ] , V_234 [ 0 ] ) ;
} else
snprintf ( V_232 -> V_239 , sizeof( V_232 -> V_239 ) ,
L_19 ) ;
snprintf ( V_232 -> V_240 ,
sizeof( V_232 -> V_240 ) ,
L_20 , V_17 -> V_241 ) ;
snprintf ( V_232 -> V_242 ,
sizeof( V_232 -> V_242 ) ,
L_21 ,
V_243 ,
V_244 ) ;
snprintf ( V_232 -> V_245 ,
sizeof( V_232 -> V_245 ) ,
L_22 ,
( V_15 -> V_246 << 16 ) |
V_15 -> V_247 ) ;
if ( V_17 -> V_21 . type == V_235 ) {
snprintf ( V_232 -> V_248 ,
sizeof( V_232 -> V_248 ) ,
L_23 ) ;
} else {
snprintf ( V_232 -> V_248 ,
sizeof( V_232 -> V_248 ) ,
L_24 ) ;
}
snprintf ( V_232 -> V_249 ,
sizeof( V_232 -> V_249 ) ,
L_25 ,
V_250 ) ;
return 0 ;
}
T_5 F_87 ( struct V_14 * V_15 )
{
#ifdef F_88
return F_89 ( V_15 -> V_10 , V_15 -> V_13 . V_251 ) ;
#else
return 0 ;
#endif
}
