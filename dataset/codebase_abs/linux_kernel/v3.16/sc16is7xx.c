static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 = 0 ;
F_3 ( V_5 -> V_8 ,
( V_3 << V_9 ) | V_2 -> line , & V_7 ) ;
return V_7 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_5 ( V_5 -> V_8 ,
( V_3 << V_9 ) | V_2 -> line , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_10 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_7 ( V_5 -> V_8 ,
( V_3 << V_9 ) | V_2 -> line ,
V_10 , V_7 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_11 )
{
F_6 ( V_2 , V_12 ,
V_13 ,
V_11 ? 0 : V_13 ) ;
}
static bool F_9 ( struct V_14 * V_6 , unsigned int V_3 )
{
switch ( V_3 >> V_9 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return true ;
default:
break;
}
return false ;
}
static bool F_10 ( struct V_14 * V_6 , unsigned int V_3 )
{
switch ( V_3 >> V_9 ) {
case V_15 :
return true ;
default:
break;
}
return false ;
}
static int F_11 ( struct V_1 * V_2 , int V_22 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 V_23 ;
T_1 V_24 = 0 ;
unsigned long V_25 = V_2 -> V_26 , div = V_25 / 16 / V_22 ;
if ( div > 0xffff ) {
V_24 = V_27 ;
div /= 4 ;
}
V_23 = F_1 ( V_2 , V_28 ) ;
F_4 ( V_2 , V_28 ,
V_29 ) ;
F_12 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_30 ,
V_31 ) ;
F_12 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_28 , V_23 ) ;
F_6 ( V_2 , V_32 ,
V_27 ,
V_24 ) ;
F_4 ( V_2 , V_28 ,
V_33 ) ;
F_12 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_34 , div / 256 ) ;
F_4 ( V_2 , V_35 , div % 256 ) ;
F_12 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_28 , V_23 ) ;
return F_13 ( V_25 / 16 , div ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_36 ,
unsigned int V_37 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_38 = 0 , V_39 , V_40 , V_41 , V_42 ;
bool V_43 = ( V_37 == V_44 ) ? true : false ;
if ( F_15 ( V_36 >= sizeof( V_5 -> V_45 ) ) ) {
F_16 ( V_2 -> V_6 ,
L_1 ,
V_2 -> line , V_36 ) ;
V_2 -> V_46 . V_47 ++ ;
V_36 = sizeof( V_5 -> V_45 ) ;
}
while ( V_36 ) {
if ( V_43 ) {
V_38 = F_1 ( V_2 , V_17 ) ;
if ( ! ( V_38 & V_48 ) )
V_43 = false ;
} else
V_38 = 0 ;
if ( V_43 ) {
V_5 -> V_45 [ 0 ] = F_1 ( V_2 , V_15 ) ;
V_41 = 1 ;
} else {
F_12 ( V_5 -> V_8 , true ) ;
F_17 ( V_5 -> V_8 , V_15 ,
V_5 -> V_45 , V_36 ) ;
F_12 ( V_5 -> V_8 , false ) ;
V_41 = V_36 ;
}
V_38 &= V_49 ;
V_2 -> V_46 . V_50 ++ ;
V_40 = V_51 ;
if ( F_15 ( V_38 ) ) {
if ( V_38 & V_52 ) {
V_2 -> V_46 . V_53 ++ ;
if ( F_18 ( V_2 ) )
continue;
} else if ( V_38 & V_54 )
V_2 -> V_46 . V_55 ++ ;
else if ( V_38 & V_56 )
V_2 -> V_46 . V_57 ++ ;
else if ( V_38 & V_58 )
V_2 -> V_46 . V_59 ++ ;
V_38 &= V_2 -> V_60 ;
if ( V_38 & V_52 )
V_40 = V_61 ;
else if ( V_38 & V_54 )
V_40 = V_62 ;
else if ( V_38 & V_56 )
V_40 = V_63 ;
else if ( V_38 & V_58 )
V_40 = V_64 ;
}
for ( V_42 = 0 ; V_42 < V_41 ; ++ V_42 ) {
V_39 = V_5 -> V_45 [ V_42 ] ;
if ( F_19 ( V_2 , V_39 ) )
continue;
if ( V_38 & V_2 -> V_65 )
continue;
F_20 ( V_2 , V_38 , V_58 , V_39 ,
V_40 ) ;
}
V_36 -= V_41 ;
}
F_21 ( & V_2 -> V_66 -> V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_67 * V_68 = & V_2 -> V_66 -> V_68 ;
unsigned int V_69 , V_70 , V_42 ;
if ( F_15 ( V_2 -> V_71 ) ) {
F_4 ( V_2 , V_72 , V_2 -> V_71 ) ;
V_2 -> V_46 . V_73 ++ ;
V_2 -> V_71 = 0 ;
return;
}
if ( F_23 ( V_68 ) || F_24 ( V_2 ) )
return;
V_70 = F_25 ( V_68 ) ;
if ( F_26 ( V_70 ) ) {
V_69 = F_1 ( V_2 , V_19 ) ;
V_70 = ( V_70 > V_69 ) ? V_69 : V_70 ;
V_2 -> V_46 . V_73 += V_70 ;
for ( V_42 = 0 ; V_42 < V_70 ; ++ V_42 ) {
V_5 -> V_45 [ V_42 ] = V_68 -> V_45 [ V_68 -> V_74 ] ;
V_68 -> V_74 = ( V_68 -> V_74 + 1 ) & ( V_75 - 1 ) ;
}
F_12 ( V_5 -> V_8 , true ) ;
F_27 ( V_5 -> V_8 , V_72 , V_5 -> V_45 , V_70 ) ;
F_12 ( V_5 -> V_8 , false ) ;
}
if ( F_25 ( V_68 ) < V_76 )
F_28 ( V_2 ) ;
}
static void F_29 ( struct V_4 * V_5 , int V_77 )
{
struct V_1 * V_2 = & V_5 -> V_78 [ V_77 ] . V_2 ;
do {
unsigned int V_37 , V_79 , V_36 ;
V_37 = F_1 ( V_2 , V_16 ) ;
if ( V_37 & V_80 )
break;
V_37 &= V_81 ;
switch ( V_37 ) {
case V_82 :
case V_44 :
case V_83 :
case V_84 :
V_36 = F_1 ( V_2 , V_20 ) ;
if ( V_36 )
F_14 ( V_2 , V_36 , V_37 ) ;
break;
case V_85 :
V_79 = F_1 ( V_2 , V_18 ) ;
F_30 ( V_2 ,
! ! ( V_79 & V_86 ) ) ;
break;
case V_87 :
F_31 ( & V_5 -> V_88 ) ;
F_22 ( V_2 ) ;
F_32 ( & V_5 -> V_88 ) ;
break;
default:
F_33 ( V_2 -> V_6 ,
L_2 ,
V_2 -> line , V_37 ) ;
break;
}
} while ( 1 );
}
static T_2 F_34 ( int V_89 , void * V_90 )
{
struct V_4 * V_5 = (struct V_4 * ) V_90 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_91 . V_92 ; ++ V_42 )
F_29 ( V_5 , V_42 ) ;
return V_93 ;
}
static void F_35 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = F_36 ( V_95 , V_98 ) ;
struct V_4 * V_5 = F_2 ( V_97 -> V_2 . V_6 ) ;
F_31 ( & V_5 -> V_88 ) ;
F_22 ( & V_97 -> V_2 ) ;
F_32 ( & V_5 -> V_88 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_36 ( V_2 , V_2 ) ;
struct V_67 * V_68 = & V_97 -> V_2 . V_66 -> V_68 ;
if ( V_97 -> V_99 . V_100 & V_101 ) {
int V_38 = F_1 ( V_2 , V_17 ) ;
if ( ! ( V_38 & V_102 ) )
return;
if ( F_23 ( V_68 ) &&
( V_97 -> V_99 . V_103 > 0 ) )
F_38 ( V_97 -> V_99 . V_103 ) ;
}
F_6 ( V_2 , V_12 ,
V_104 ,
0 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_36 ( V_2 , V_2 ) ;
V_97 -> V_2 . V_60 &= ~ V_105 ;
F_6 ( V_2 , V_12 ,
V_105 ,
0 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_36 ( V_2 , V_2 ) ;
if ( ( V_97 -> V_99 . V_100 & V_101 ) &&
( V_97 -> V_99 . V_106 > 0 ) ) {
F_38 ( V_97 -> V_99 . V_106 ) ;
}
if ( ! F_41 ( & V_97 -> V_98 ) )
F_42 ( & V_97 -> V_98 ) ;
}
static unsigned int F_43 ( struct V_1 * V_2 )
{
unsigned int V_107 , V_38 ;
V_107 = F_1 ( V_2 , V_19 ) ;
V_38 = F_1 ( V_2 , V_17 ) ;
return ( ( V_38 & V_108 ) && ! V_107 ) ? V_109 : 0 ;
}
static unsigned int F_44 ( struct V_1 * V_2 )
{
return V_110 | V_111 ;
}
static void F_45 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = F_36 ( V_95 , V_112 ) ;
F_6 ( & V_97 -> V_2 , V_32 ,
V_113 ,
( V_97 -> V_2 . V_114 & V_115 ) ?
V_113 : 0 ) ;
}
static void F_46 ( struct V_1 * V_2 , unsigned int V_114 )
{
struct V_96 * V_97 = F_36 ( V_2 , V_2 ) ;
F_42 ( & V_97 -> V_112 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_116 )
{
F_6 ( V_2 , V_28 ,
V_117 ,
V_116 ? V_117 : 0 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
struct V_118 * V_120 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_23 , V_121 = 0 ;
int V_22 ;
V_119 -> V_122 &= ~ V_123 ;
switch ( V_119 -> V_122 & V_124 ) {
case V_125 :
V_23 = V_126 ;
break;
case V_127 :
V_23 = V_128 ;
break;
case V_129 :
V_23 = V_130 ;
break;
case V_131 :
V_23 = V_132 ;
break;
default:
V_23 = V_132 ;
V_119 -> V_122 &= ~ V_124 ;
V_119 -> V_122 |= V_131 ;
break;
}
if ( V_119 -> V_122 & V_133 ) {
V_23 |= V_134 ;
if ( ! ( V_119 -> V_122 & V_135 ) )
V_23 |= V_136 ;
}
if ( V_119 -> V_122 & V_137 )
V_23 |= V_138 ;
V_2 -> V_60 = V_58 ;
if ( V_119 -> V_139 & V_140 )
V_2 -> V_60 |= V_54 |
V_56 ;
if ( V_119 -> V_139 & ( V_141 | V_142 ) )
V_2 -> V_60 |= V_52 ;
V_2 -> V_65 = 0 ;
if ( V_119 -> V_139 & V_143 )
V_2 -> V_65 |= V_52 ;
if ( ! ( V_119 -> V_122 & V_144 ) )
V_2 -> V_65 |= V_49 ;
F_4 ( V_2 , V_28 ,
V_29 ) ;
F_12 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_145 , V_119 -> V_146 [ V_147 ] ) ;
F_4 ( V_2 , V_148 , V_119 -> V_146 [ V_149 ] ) ;
if ( V_119 -> V_122 & V_150 )
V_121 |= V_151 |
V_152 ;
if ( V_119 -> V_139 & V_153 )
V_121 |= V_154 ;
if ( V_119 -> V_139 & V_155 )
V_121 |= V_156 ;
F_4 ( V_2 , V_30 , V_121 ) ;
F_12 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_28 , V_23 ) ;
V_22 = F_49 ( V_2 , V_119 , V_120 ,
V_2 -> V_26 / 16 / 4 / 0xffff ,
V_2 -> V_26 / 16 ) ;
V_22 = F_11 ( V_2 , V_22 ) ;
F_50 ( V_2 , V_119 -> V_122 , V_22 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_157 * V_99 )
{
struct V_96 * V_97 = F_36 ( V_2 , V_2 ) ;
V_97 -> V_99 = * V_99 ;
if ( V_97 -> V_99 . V_100 & V_101 ) {
F_6 ( V_2 , V_158 ,
V_159 ,
V_159 ) ;
} else {
F_6 ( V_2 , V_158 ,
V_159 ,
0 ) ;
}
}
static int F_52 ( struct V_1 * V_2 , unsigned int V_160 ,
unsigned long V_161 )
{
#if F_53 ( V_162 ) && F_53 ( V_163 )
struct V_157 V_99 ;
switch ( V_160 ) {
case V_162 :
if ( F_54 ( & V_99 , ( void V_164 * ) V_161 , sizeof( V_99 ) ) )
return - V_165 ;
F_51 ( V_2 , & V_99 ) ;
return 0 ;
case V_163 :
if ( F_55 ( ( void V_164 * ) V_161 ,
& ( F_36 ( V_2 , V_2 ) -> V_99 ) ,
sizeof( V_99 ) ) )
return - V_165 ;
return 0 ;
default:
break;
}
#endif
return - V_166 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 ;
F_8 ( V_2 , 1 ) ;
V_7 = V_167 | V_168 ;
F_4 ( V_2 , V_169 , V_7 ) ;
F_57 ( 5 ) ;
F_4 ( V_2 , V_169 ,
V_170 ) ;
F_4 ( V_2 , V_28 ,
V_29 ) ;
F_12 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_30 ,
V_31 ) ;
F_6 ( V_2 , V_32 ,
V_171 ,
V_171 ) ;
F_4 ( V_2 , V_172 ,
F_58 ( 24 ) |
F_59 ( 48 ) ) ;
F_12 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_28 , V_132 ) ;
F_6 ( V_2 , V_158 ,
V_173 |
V_174 ,
0 ) ;
V_7 = V_175 | V_104 |
V_176 ;
F_4 ( V_2 , V_12 , V_7 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_12 , 0 ) ;
F_4 ( V_2 , V_158 ,
V_173 |
V_174 ) ;
F_8 ( V_2 , 0 ) ;
}
static const char * F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
return ( V_2 -> type == V_177 ) ? V_5 -> V_178 -> V_179 : NULL ;
}
static int F_62 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , int V_100 )
{
if ( V_100 & V_180 )
V_2 -> type = V_177 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_181 * V_5 )
{
if ( ( V_5 -> type != V_182 ) && ( V_5 -> type != V_177 ) )
return - V_183 ;
if ( V_5 -> V_89 != V_2 -> V_89 )
return - V_183 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , unsigned int V_66 ,
unsigned int V_184 )
{
F_8 ( V_2 , ( V_66 == V_185 ) ? 1 : 0 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
}
static int F_67 ( struct V_186 * V_187 , unsigned V_188 )
{
unsigned int V_7 ;
struct V_4 * V_5 = F_68 ( V_187 , struct V_4 ,
V_189 ) ;
struct V_1 * V_2 = & V_5 -> V_78 [ 0 ] . V_2 ;
V_7 = F_1 ( V_2 , V_21 ) ;
return ! ! ( V_7 & F_69 ( V_188 ) ) ;
}
static void F_70 ( struct V_186 * V_187 , unsigned V_188 , int V_7 )
{
struct V_4 * V_5 = F_68 ( V_187 , struct V_4 ,
V_189 ) ;
struct V_1 * V_2 = & V_5 -> V_78 [ 0 ] . V_2 ;
F_6 ( V_2 , V_21 , F_69 ( V_188 ) ,
V_7 ? F_69 ( V_188 ) : 0 ) ;
}
static int F_71 ( struct V_186 * V_187 ,
unsigned V_188 )
{
struct V_4 * V_5 = F_68 ( V_187 , struct V_4 ,
V_189 ) ;
struct V_1 * V_2 = & V_5 -> V_78 [ 0 ] . V_2 ;
F_6 ( V_2 , V_190 , F_69 ( V_188 ) , 0 ) ;
return 0 ;
}
static int F_72 ( struct V_186 * V_187 ,
unsigned V_188 , int V_7 )
{
struct V_4 * V_5 = F_68 ( V_187 , struct V_4 ,
V_189 ) ;
struct V_1 * V_2 = & V_5 -> V_78 [ 0 ] . V_2 ;
F_6 ( V_2 , V_21 , F_69 ( V_188 ) ,
V_7 ? F_69 ( V_188 ) : 0 ) ;
F_6 ( V_2 , V_190 , F_69 ( V_188 ) ,
F_69 ( V_188 ) ) ;
return 0 ;
}
static int F_73 ( struct V_14 * V_6 ,
struct V_191 * V_178 ,
struct V_8 * V_8 , int V_89 , unsigned long V_100 )
{
unsigned long V_192 , * V_193 = F_74 ( V_6 ) ;
struct V_25 * V_25 ;
int V_42 , V_194 ;
struct V_4 * V_5 ;
if ( F_75 ( V_8 ) )
return F_76 ( V_8 ) ;
V_5 = F_77 ( V_6 , sizeof( * V_5 ) +
sizeof( struct V_96 ) * V_178 -> V_195 ,
V_196 ) ;
if ( ! V_5 ) {
F_78 ( V_6 , L_3 ) ;
return - V_197 ;
}
V_25 = F_79 ( V_6 , NULL ) ;
if ( F_75 ( V_25 ) ) {
if ( V_193 )
V_192 = * V_193 ;
else
return F_76 ( V_25 ) ;
} else {
V_192 = F_80 ( V_25 ) ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_178 = V_178 ;
F_81 ( V_6 , V_5 ) ;
V_5 -> V_91 . V_198 = V_199 ;
V_5 -> V_91 . V_200 = L_4 ;
V_5 -> V_91 . V_92 = V_178 -> V_195 ;
V_194 = F_82 ( & V_5 -> V_91 ) ;
if ( V_194 ) {
F_78 ( V_6 , L_5 ) ;
goto V_201;
}
#ifdef F_83
if ( V_178 -> V_202 ) {
V_5 -> V_189 . V_198 = V_199 ;
V_5 -> V_189 . V_6 = V_6 ;
V_5 -> V_189 . V_203 = V_200 ( V_6 ) ;
V_5 -> V_189 . V_204 = F_71 ;
V_5 -> V_189 . V_205 = F_67 ;
V_5 -> V_189 . V_206 = F_72 ;
V_5 -> V_189 . V_207 = F_70 ;
V_5 -> V_189 . V_208 = - 1 ;
V_5 -> V_189 . V_209 = V_178 -> V_202 ;
V_5 -> V_189 . V_210 = 1 ;
V_194 = F_84 ( & V_5 -> V_189 ) ;
if ( V_194 )
goto V_211;
}
#endif
F_85 ( & V_5 -> V_88 ) ;
for ( V_42 = 0 ; V_42 < V_178 -> V_195 ; ++ V_42 ) {
V_5 -> V_78 [ V_42 ] . V_2 . line = V_42 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_6 = V_6 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_89 = V_89 ;
V_5 -> V_78 [ V_42 ] . V_2 . type = V_177 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_212 = V_213 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_100 = V_214 | V_215 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_216 = V_217 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_26 = V_192 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_218 = & V_219 ;
F_4 ( & V_5 -> V_78 [ V_42 ] . V_2 , V_12 , 0 ) ;
F_4 ( & V_5 -> V_78 [ V_42 ] . V_2 , V_158 ,
V_173 |
V_174 ) ;
F_86 ( & V_5 -> V_78 [ V_42 ] . V_98 , F_35 ) ;
F_86 ( & V_5 -> V_78 [ V_42 ] . V_112 , F_45 ) ;
F_87 ( & V_5 -> V_91 , & V_5 -> V_78 [ V_42 ] . V_2 ) ;
F_8 ( & V_5 -> V_78 [ V_42 ] . V_2 , 0 ) ;
}
V_194 = F_88 ( V_6 , V_89 , NULL , F_34 ,
V_220 | V_100 , V_200 ( V_6 ) , V_5 ) ;
if ( ! V_194 )
return 0 ;
F_89 ( & V_5 -> V_88 ) ;
#ifdef F_83
if ( V_178 -> V_202 )
F_90 ( F_91 ( & V_5 -> V_189 ) ) ;
V_211:
#endif
F_92 ( & V_5 -> V_91 ) ;
V_201:
if ( ! F_75 ( V_5 -> V_25 ) )
F_93 ( V_5 -> V_25 ) ;
return V_194 ;
}
static int F_94 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_42 , V_194 = 0 ;
#ifdef F_83
if ( V_5 -> V_178 -> V_202 ) {
V_194 = F_91 ( & V_5 -> V_189 ) ;
if ( V_194 )
return V_194 ;
}
#endif
for ( V_42 = 0 ; V_42 < V_5 -> V_91 . V_92 ; V_42 ++ ) {
F_95 ( & V_5 -> V_78 [ V_42 ] . V_98 ) ;
F_95 ( & V_5 -> V_78 [ V_42 ] . V_112 ) ;
F_96 ( & V_5 -> V_91 , & V_5 -> V_78 [ V_42 ] . V_2 ) ;
F_8 ( & V_5 -> V_78 [ V_42 ] . V_2 , 0 ) ;
}
F_89 ( & V_5 -> V_88 ) ;
F_92 ( & V_5 -> V_91 ) ;
if ( ! F_75 ( V_5 -> V_25 ) )
F_93 ( V_5 -> V_25 ) ;
return V_194 ;
}
static int F_97 ( struct V_221 * V_222 ,
const struct V_223 * V_224 )
{
struct V_191 * V_178 ;
unsigned long V_100 = 0 ;
struct V_8 * V_8 ;
if ( V_222 -> V_6 . V_225 ) {
const struct V_226 * V_227 =
F_98 ( V_228 , & V_222 -> V_6 ) ;
V_178 = (struct V_191 * ) V_227 -> V_229 ;
} else {
V_178 = (struct V_191 * ) V_224 -> V_230 ;
V_100 = V_231 ;
}
V_232 . V_233 = ( 0xf << V_9 ) |
( V_178 -> V_195 - 1 ) ;
V_8 = F_99 ( V_222 , & V_232 ) ;
return F_73 ( & V_222 -> V_6 , V_178 , V_8 , V_222 -> V_89 , V_100 ) ;
}
static int F_100 ( struct V_221 * V_234 )
{
return F_94 ( & V_234 -> V_6 ) ;
}
