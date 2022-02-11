static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_1 T_2 * V_5 = V_4 -> V_6 ;
int V_7 = 0 ;
while ( 1 ) {
if ( F_2 ( & V_5 -> V_8 ) & V_9 )
break;
if ( F_2 ( & V_5 -> V_8 ) & V_10 ) {
V_7 = V_11 ;
break;
}
V_5 ++ ;
}
F_3 ( L_1 , V_2 -> line , V_7 ) ;
return V_7 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_4 -> V_13 [ V_14 ] >= 0 )
F_5 ( V_4 -> V_13 [ V_14 ] , ! ( V_12 & V_15 ) ) ;
if ( V_4 -> V_13 [ V_16 ] >= 0 )
F_5 ( V_4 -> V_13 [ V_16 ] , ! ( V_12 & V_17 ) ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_12 = V_18 | V_19 | V_20 ;
if ( V_4 -> V_13 [ V_21 ] >= 0 ) {
if ( F_7 ( V_4 -> V_13 [ V_21 ] ) )
V_12 &= ~ V_18 ;
}
if ( V_4 -> V_13 [ V_22 ] >= 0 ) {
if ( F_7 ( V_4 -> V_13 [ V_22 ] ) )
V_12 &= ~ V_19 ;
}
if ( V_4 -> V_13 [ V_23 ] >= 0 ) {
if ( F_7 ( V_4 -> V_13 [ V_23 ] ) )
V_12 &= ~ V_20 ;
}
if ( V_4 -> V_13 [ V_24 ] >= 0 ) {
if ( ! F_7 ( V_4 -> V_13 [ V_24 ] ) )
V_12 |= V_25 ;
}
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 T_2 * V_26 = V_4 -> V_26 ;
T_4 T_2 * V_27 = V_4 -> V_27 ;
F_3 ( L_2 , V_2 -> line ) ;
if ( F_9 ( V_4 ) )
F_10 ( & V_26 -> V_28 , V_29 ) ;
else
F_11 ( & V_27 -> V_30 , V_31 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 T_2 * V_26 = V_4 -> V_26 ;
T_4 T_2 * V_27 = V_4 -> V_27 ;
F_3 ( L_3 , V_2 -> line ) ;
if ( F_9 ( V_4 ) ) {
if ( F_13 ( & V_26 -> V_28 ) & V_29 )
return;
} else {
if ( F_2 ( & V_27 -> V_30 ) & V_31 )
return;
}
if ( F_14 ( V_2 ) != 0 ) {
if ( F_9 ( V_4 ) ) {
F_15 ( & V_26 -> V_28 , V_29 ) ;
} else {
F_16 ( & V_27 -> V_30 , V_31 ) ;
}
}
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 T_2 * V_26 = V_4 -> V_26 ;
T_4 T_2 * V_27 = V_4 -> V_27 ;
F_3 ( L_4 , V_2 -> line ) ;
if ( F_9 ( V_4 ) )
F_10 ( & V_26 -> V_28 , V_32 ) ;
else
F_11 ( & V_27 -> V_30 , V_33 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_3 ( L_5 , V_2 -> line ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_34 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_3 ( L_6 , V_2 -> line ,
V_34 ) ;
if ( V_34 )
F_20 ( V_4 , V_35 ) ;
else
F_20 ( V_4 , V_36 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> line ) ;
F_14 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned char V_38 ;
T_5 * V_39 ;
struct V_40 * V_41 = V_2 -> V_42 -> V_2 . V_41 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_1 T_2 * V_5 ;
T_6 V_43 ;
unsigned int V_44 ;
F_3 ( L_8 , V_2 -> line ) ;
V_5 = V_4 -> V_45 ;
for (; ; ) {
#ifdef F_23
if ( F_24 ( V_46 ) ) {
V_46 = 0 ;
return;
}
#endif
V_43 = F_2 ( & V_5 -> V_8 ) ;
if ( V_43 & V_47 )
break;
V_37 = F_2 ( & V_5 -> V_48 ) ;
if( F_25 ( V_41 , V_37 ) < V_37 ) {
F_26 ( V_49 L_9 ) ;
return;
}
V_39 = F_27 ( F_28 ( & V_5 -> V_50 ) , V_4 ) ;
while ( V_37 -- > 0 ) {
V_38 = * V_39 ++ ;
V_2 -> V_51 . V_52 ++ ;
V_44 = V_53 ;
if ( V_43 &
( V_54 | V_55 | V_56 | V_57 ) )
goto V_58;
if ( F_29 ( V_2 , V_38 ) )
continue;
#ifdef F_23
if ( F_24 ( V_46 ) ) {
V_46 = 0 ;
return;
}
#endif
V_59:
F_30 ( V_41 , V_38 , V_44 ) ;
}
F_11 ( & V_5 -> V_8 , V_54 | V_55 | V_56 |
V_57 | V_60 ) ;
F_16 ( & V_5 -> V_8 , V_47 ) ;
if ( F_2 ( & V_5 -> V_8 ) & V_10 )
V_5 = V_4 -> V_61 ;
else
V_5 ++ ;
}
V_4 -> V_45 = V_5 ;
F_31 ( V_41 ) ;
return;
V_58:
if ( V_43 & V_54 )
V_2 -> V_51 . V_62 ++ ;
if ( V_43 & V_56 )
V_2 -> V_51 . V_63 ++ ;
if ( V_43 & V_55 )
V_2 -> V_51 . V_64 ++ ;
if ( V_43 & V_57 )
V_2 -> V_51 . V_65 ++ ;
V_43 &= V_2 -> V_66 ;
if ( V_43 & V_54 )
V_44 = V_67 ;
else if ( V_43 & V_56 )
V_44 = V_68 ;
else if ( V_43 & V_55 )
V_44 = V_69 ;
if ( V_43 & V_57 ) {
V_38 = 0 ;
V_44 = V_70 ;
V_37 = 0 ;
}
#ifdef F_32
V_2 -> V_71 = 0 ;
#endif
goto V_59;
}
static T_7 F_33 ( int V_72 , void * V_73 )
{
T_5 V_74 ;
struct V_1 * V_2 = V_73 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 T_2 * V_26 = V_4 -> V_26 ;
T_4 T_2 * V_27 = V_4 -> V_27 ;
F_3 ( L_10 , V_2 -> line ) ;
if ( F_9 ( V_4 ) ) {
V_74 = F_13 ( & V_26 -> V_75 ) ;
F_34 ( & V_26 -> V_75 , V_74 ) ;
if ( V_74 & V_76 )
F_35 ( V_2 ) ;
if ( V_74 & V_32 )
F_22 ( V_2 ) ;
if ( V_74 & V_29 )
F_21 ( V_2 ) ;
} else {
V_74 = F_2 ( & V_27 -> V_77 ) ;
F_36 ( & V_27 -> V_77 , V_74 ) ;
if ( V_74 & V_78 )
F_35 ( V_2 ) ;
if ( V_74 & V_33 )
F_22 ( V_2 ) ;
if ( V_74 & V_31 )
F_21 ( V_2 ) ;
}
return ( V_74 ) ? V_79 : V_80 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_81 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_3 ( L_11 , V_2 -> line ) ;
if ( ! ( V_4 -> V_82 & V_83 ) ) {
if ( F_9 ( V_4 ) ) {
F_11 ( & V_4 -> V_26 -> V_84 , V_85 ) ;
F_10 ( & V_4 -> V_26 -> V_28 , V_32 ) ;
} else {
F_38 ( & V_4 -> V_27 -> V_86 , V_87 ) ;
F_11 ( & V_4 -> V_27 -> V_30 , V_33 ) ;
}
F_20 ( V_4 , V_88 ) ;
}
V_81 = F_39 ( V_2 -> V_72 , F_33 , 0 , L_12 , V_2 ) ;
if ( V_81 )
return V_81 ;
if ( F_9 ( V_4 ) ) {
F_15 ( & V_4 -> V_26 -> V_28 , V_32 ) ;
F_16 ( & V_4 -> V_26 -> V_84 , ( V_85 | V_89 ) ) ;
} else {
F_16 ( & V_4 -> V_27 -> V_30 , V_33 ) ;
F_40 ( & V_4 -> V_27 -> V_86 , ( V_87 | V_90 ) ) ;
}
return 0 ;
}
inline void F_41 ( struct V_3 * V_4 )
{
F_42 ( V_91 ) ;
F_43 ( V_4 -> V_92 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_3 ( L_13 , V_2 -> line ) ;
F_45 ( V_2 -> V_72 , V_2 ) ;
if ( ! ( V_4 -> V_82 & V_83 ) ) {
while( ! F_1 ( V_2 ) ) {
F_42 ( V_91 ) ;
F_43 ( 2 ) ;
}
if ( V_4 -> V_92 )
F_41 ( V_4 ) ;
if ( F_9 ( V_4 ) ) {
T_3 T_2 * V_26 = V_4 -> V_26 ;
F_11 ( & V_26 -> V_84 , V_85 | V_89 ) ;
F_10 ( & V_26 -> V_28 , V_32 | V_29 ) ;
} else {
T_4 T_2 * V_27 = V_4 -> V_27 ;
F_38 ( & V_27 -> V_86 , V_87 | V_90 ) ;
F_11 ( & V_27 -> V_30 , V_31 | V_33 ) ;
}
if ( F_9 ( V_4 ) ) {
F_36 ( & V_4 -> V_93 -> V_94 , 0 ) ;
F_20 ( V_4 , V_35 ) ;
} else {
F_36 ( & V_4 -> V_95 -> V_96 , 0 ) ;
F_20 ( V_4 , V_97 ) ;
}
F_46 ( V_4 ) ;
}
}
static void F_47 ( struct V_1 * V_2 ,
struct V_98 * V_99 ,
struct V_98 * V_100 )
{
int V_101 ;
unsigned long V_82 ;
T_6 V_102 , V_103 , V_104 ;
int V_105 , V_106 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 T_2 * V_26 = V_4 -> V_26 ;
T_4 T_2 * V_27 = V_4 -> V_27 ;
F_3 ( L_14 , V_2 -> line ) ;
V_101 = F_48 ( V_2 , V_99 , V_100 , 0 , V_2 -> V_107 / 16 ) ;
if ( V_101 <= V_108 ||
( V_4 -> V_2 . V_42 && V_4 -> V_2 . V_42 -> V_2 . V_41 -> V_109 ) )
V_4 -> V_110 = 1 ;
else
V_4 -> V_110 = V_111 ;
V_102 = 0 ;
V_103 = 0 ;
switch ( V_99 -> V_112 & V_113 ) {
case V_114 :
V_105 = 5 ;
break;
case V_115 :
V_105 = 6 ;
break;
case V_116 :
V_105 = 7 ;
break;
case V_117 :
V_105 = 8 ;
break;
default:
V_105 = 8 ;
break;
}
V_106 = V_105 - 5 ;
if ( V_99 -> V_112 & V_118 ) {
V_102 |= V_119 ;
V_103 |= V_120 ;
V_105 ++ ;
}
if ( V_99 -> V_112 & V_121 ) {
V_102 |= V_122 ;
V_103 |= V_123 ;
V_105 ++ ;
if ( ! ( V_99 -> V_112 & V_124 ) ) {
V_102 |= V_125 ;
V_103 |= ( V_126 | V_127 ) ;
}
}
F_49 ( V_2 , V_99 -> V_112 , V_101 ) ;
#define F_50 ( T_8 ) (iflag & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK))
V_2 -> V_66 = ( V_47 | V_57 ) ;
if ( V_99 -> V_128 & V_129 )
V_2 -> V_66 |= V_55 | V_56 ;
if ( ( V_99 -> V_128 & V_130 ) || ( V_99 -> V_128 & V_131 ) )
V_2 -> V_66 |= V_54 ;
V_2 -> V_132 = 0 ;
if ( V_99 -> V_128 & V_133 )
V_2 -> V_132 |= V_56 | V_55 ;
if ( V_99 -> V_128 & V_134 ) {
V_2 -> V_132 |= V_54 ;
if ( V_99 -> V_128 & V_133 )
V_2 -> V_132 |= V_57 ;
}
if ( ( V_99 -> V_112 & V_135 ) == 0 )
V_2 -> V_66 &= ~ V_47 ;
F_51 ( & V_2 -> V_136 , V_82 ) ;
V_105 ++ ;
if ( F_9 ( V_4 ) ) {
F_36 ( & V_4 -> V_93 -> V_137 , V_4 -> V_110 ) ;
V_104 = F_2 ( & V_26 -> V_84 ) & ( V_85 | V_89 ) ;
F_36 ( & V_26 -> V_84 , F_52 ( V_105 ) | V_102 |
V_138 | V_104 ) ;
} else {
F_36 ( & V_4 -> V_95 -> V_139 . V_140 , V_4 -> V_110 ) ;
F_36 ( & V_27 -> V_141 , ( V_106 << 12 ) | V_103 ) ;
}
if ( V_4 -> V_142 )
F_53 ( V_4 -> V_142 , V_101 ) ;
else
F_54 ( V_4 -> V_143 - 1 , V_101 ) ;
F_55 ( & V_2 -> V_136 , V_82 ) ;
}
static const char * F_56 ( struct V_1 * V_2 )
{
F_3 ( L_15 , V_2 -> line ) ;
return V_2 -> type == V_144 ? L_16 : NULL ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
int V_7 = 0 ;
F_3 ( L_17 , V_2 -> line ) ;
if ( V_146 -> type != V_147 && V_146 -> type != V_144 )
V_7 = - V_148 ;
if ( V_146 -> V_72 < 0 || V_146 -> V_72 >= V_149 )
V_7 = - V_148 ;
if ( V_146 -> V_150 < 9600 )
V_7 = - V_148 ;
return V_7 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 T_2 * V_5 ;
T_5 * V_151 ;
int V_152 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_153 * V_154 = & V_2 -> V_42 -> V_154 ;
if ( V_2 -> V_155 ) {
V_5 = V_4 -> V_156 ;
V_151 = F_27 ( F_28 ( & V_5 -> V_50 ) , V_4 ) ;
* V_151 ++ = V_2 -> V_155 ;
F_36 ( & V_5 -> V_48 , 1 ) ;
F_16 ( & V_5 -> V_8 , V_9 ) ;
if ( F_2 ( & V_5 -> V_8 ) & V_10 )
V_5 = V_4 -> V_6 ;
else
V_5 ++ ;
V_4 -> V_156 = V_5 ;
V_2 -> V_51 . V_157 ++ ;
V_2 -> V_155 = 0 ;
return 1 ;
}
if ( F_58 ( V_154 ) || F_59 ( V_2 ) ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_5 = V_4 -> V_156 ;
while ( ! ( F_2 ( & V_5 -> V_8 ) & V_9 ) &&
V_154 -> V_158 != V_154 -> V_159 ) {
V_152 = 0 ;
V_151 = F_27 ( F_28 ( & V_5 -> V_50 ) , V_4 ) ;
while ( V_152 < V_4 -> V_160 ) {
* V_151 ++ = V_154 -> V_161 [ V_154 -> V_158 ] ;
V_154 -> V_158 = ( V_154 -> V_158 + 1 ) & ( V_162 - 1 ) ;
V_2 -> V_51 . V_157 ++ ;
V_152 ++ ;
if ( V_154 -> V_159 == V_154 -> V_158 )
break;
}
F_36 ( & V_5 -> V_48 , V_152 ) ;
F_16 ( & V_5 -> V_8 , V_9 ) ;
if ( F_2 ( & V_5 -> V_8 ) & V_10 )
V_5 = V_4 -> V_6 ;
else
V_5 ++ ;
}
V_4 -> V_156 = V_5 ;
if ( F_60 ( V_154 ) < V_163 )
F_61 ( V_2 ) ;
if ( F_58 ( V_154 ) ) {
F_8 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
static void F_46 ( struct V_3 * V_4 )
{
int V_37 ;
T_5 * V_164 ;
T_1 T_2 * V_5 ;
F_3 ( L_18 , V_4 -> V_2 . line ) ;
V_164 = V_4 -> V_164 ;
V_5 = V_4 -> V_45 = V_4 -> V_61 ;
for ( V_37 = 0 ; V_37 < ( V_4 -> V_165 - 1 ) ; V_37 ++ , V_5 ++ ) {
F_62 ( & V_5 -> V_50 , F_63 ( V_164 , V_4 ) ) ;
F_36 ( & V_5 -> V_8 , V_47 | V_166 ) ;
V_164 += V_4 -> V_110 ;
}
F_62 ( & V_5 -> V_50 , F_63 ( V_164 , V_4 ) ) ;
F_36 ( & V_5 -> V_8 , V_10 | V_47 | V_166 ) ;
V_164 = V_4 -> V_164 + F_64 ( V_4 -> V_165 * V_4 -> V_110 ) ;
V_5 = V_4 -> V_156 = V_4 -> V_6 ;
for ( V_37 = 0 ; V_37 < ( V_4 -> V_167 - 1 ) ; V_37 ++ , V_5 ++ ) {
F_62 ( & V_5 -> V_50 , F_63 ( V_164 , V_4 ) ) ;
F_36 ( & V_5 -> V_8 , V_166 ) ;
V_164 += V_4 -> V_160 ;
}
F_62 ( & V_5 -> V_50 , F_63 ( V_164 , V_4 ) ) ;
F_36 ( & V_5 -> V_8 , V_10 | V_166 ) ;
}
static void F_65 ( struct V_3 * V_4 )
{
T_4 T_2 * V_168 ;
T_9 T_2 * V_169 ;
F_3 ( L_19 , V_4 -> V_2 . line ) ;
V_168 = V_4 -> V_27 ;
V_169 = V_4 -> V_95 ;
F_36 ( & V_4 -> V_95 -> V_139 . V_170 ,
( T_5 T_2 * ) V_4 -> V_61 - V_171 ) ;
F_36 ( & V_4 -> V_95 -> V_139 . V_172 ,
( T_5 T_2 * ) V_4 -> V_6 - V_171 ) ;
F_66 ( V_169 ) ;
F_36 ( & V_169 -> V_139 . V_140 , V_4 -> V_110 ) ;
F_36 ( & V_169 -> V_173 , V_4 -> V_110 ) ;
F_36 ( & V_169 -> V_96 , 1 ) ;
F_36 ( & V_169 -> V_174 , 0 ) ;
F_36 ( & V_169 -> V_175 , 0 ) ;
F_36 ( & V_169 -> V_176 , 0 ) ;
F_36 ( & V_169 -> V_177 , 0 ) ;
F_36 ( & V_169 -> V_178 , 0 ) ;
F_36 ( & V_169 -> V_179 , 0 ) ;
F_36 ( & V_169 -> V_180 , 0 ) ;
F_36 ( & V_169 -> V_181 , 0x8000 ) ;
F_36 ( & V_169 -> V_182 , 0x8000 ) ;
F_36 ( & V_169 -> V_183 , 0x8000 ) ;
F_36 ( & V_169 -> V_184 , 0x8000 ) ;
F_36 ( & V_169 -> V_185 , 0x8000 ) ;
F_36 ( & V_169 -> V_186 , 0x8000 ) ;
F_36 ( & V_169 -> V_187 , 0x8000 ) ;
F_36 ( & V_169 -> V_188 , 0x8000 ) ;
F_36 ( & V_169 -> V_189 , 0xc0ff ) ;
F_20 ( V_4 , V_88 ) ;
F_62 ( & V_168 -> V_190 , 0 ) ;
F_62 ( & V_168 -> V_86 ,
V_191 | V_192 | V_193 ) ;
F_36 ( & V_168 -> V_30 , 0 ) ;
F_36 ( & V_168 -> V_77 , 0xffff ) ;
F_36 ( & V_168 -> V_194 , 0x7e7e ) ;
F_36 ( & V_168 -> V_141 , 0x3000 ) ;
F_40 ( & V_168 -> V_86 , V_87 | V_90 ) ;
}
static void F_67 ( struct V_3 * V_4 )
{
T_3 T_2 * V_195 ;
T_10 T_2 * V_196 ;
F_3 ( L_20 , V_4 -> V_2 . line ) ;
V_195 = V_4 -> V_26 ;
V_196 = V_4 -> V_93 ;
F_36 ( & V_4 -> V_93 -> V_197 ,
( T_5 T_2 * ) V_4 -> V_61 - V_171 ) ;
F_36 ( & V_4 -> V_93 -> V_198 ,
( T_5 T_2 * ) V_4 -> V_6 - V_171 ) ;
#if F_68 ( V_199 )
F_36 ( & V_196 -> V_200 , F_2 ( & V_4 -> V_93 -> V_197 ) ) ;
F_36 ( & V_196 -> V_201 , F_2 ( & V_4 -> V_93 -> V_198 ) ) ;
F_62 ( & V_196 -> V_202 , 0 ) ;
F_62 ( & V_196 -> V_203 , 0 ) ;
F_36 ( & V_196 -> V_94 , 1 ) ;
F_36 ( & V_196 -> V_204 , 0 ) ;
#endif
F_69 ( V_196 ) ;
F_36 ( & V_196 -> V_137 , V_4 -> V_110 ) ;
F_36 ( & V_196 -> V_205 , V_4 -> V_110 ) ;
F_36 ( & V_196 -> V_206 , 0 ) ;
F_36 ( & V_196 -> V_204 , 0 ) ;
F_36 ( & V_196 -> V_94 , 1 ) ;
F_20 ( V_4 , V_88 ) ;
F_36 ( & V_195 -> V_84 , F_52 ( 9 ) | V_138 ) ;
F_34 ( & V_195 -> V_28 , 0 ) ;
F_34 ( & V_195 -> V_75 , 0xff ) ;
F_16 ( & V_195 -> V_84 , V_85 | V_89 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
int V_7 ;
F_3 ( L_21 , V_2 -> line ) ;
if ( V_4 -> V_82 & V_83 )
return 0 ;
if ( F_9 ( V_4 ) ) {
F_10 ( & V_4 -> V_26 -> V_28 , V_32 | V_29 ) ;
F_11 ( & V_4 -> V_26 -> V_84 , V_85 | V_89 ) ;
} else {
F_11 ( & V_4 -> V_27 -> V_30 , V_31 | V_33 ) ;
F_38 ( & V_4 -> V_27 -> V_86 , V_87 | V_90 ) ;
}
V_7 = F_71 ( V_4 , 0 ) ;
if ( V_7 )
return V_7 ;
F_46 ( V_4 ) ;
if ( F_9 ( V_4 ) )
F_67 ( V_4 ) ;
else
F_65 ( V_4 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( ! ( V_4 -> V_82 & V_83 ) )
F_73 ( V_4 ) ;
}
static void F_74 ( struct V_1 * V_2 , int V_82 )
{
F_3 ( L_22 , V_2 -> line ) ;
if ( V_82 & V_207 ) {
V_2 -> type = V_144 ;
F_70 ( V_2 ) ;
}
}
static void F_75 ( struct V_3 * V_4 ,
const char * string , T_11 V_152 )
{
unsigned int V_37 ;
T_1 T_2 * V_5 , * V_208 ;
unsigned char * V_209 ;
V_5 = V_4 -> V_156 ;
V_208 = V_4 -> V_6 ;
for ( V_37 = 0 ; V_37 < V_152 ; V_37 ++ , string ++ ) {
while ( ( F_2 ( & V_5 -> V_8 ) & V_9 ) != 0 )
;
V_209 = F_27 ( F_28 ( & V_5 -> V_50 ) ,
V_4 ) ;
* V_209 = * string ;
F_36 ( & V_5 -> V_48 , 1 ) ;
F_16 ( & V_5 -> V_8 , V_9 ) ;
if ( F_2 ( & V_5 -> V_8 ) & V_10 )
V_5 = V_208 ;
else
V_5 ++ ;
if ( * string == 10 ) {
while ( ( F_2 ( & V_5 -> V_8 ) & V_9 ) != 0 )
;
V_209 = F_27 ( F_28 ( & V_5 -> V_50 ) ,
V_4 ) ;
* V_209 = 13 ;
F_36 ( & V_5 -> V_48 , 1 ) ;
F_16 ( & V_5 -> V_8 , V_9 ) ;
if ( F_2 ( & V_5 -> V_8 ) & V_10 )
V_5 = V_208 ;
else
V_5 ++ ;
}
}
while ( ( F_2 ( & V_5 -> V_8 ) & V_9 ) != 0 )
;
V_4 -> V_156 = V_5 ;
}
static int F_76 ( char * V_210 , struct V_3 * V_4 )
{
T_12 V_211 , * V_39 ;
volatile T_1 * V_5 ;
int V_37 ;
V_5 = V_4 -> V_45 ;
while ( V_5 -> V_8 & V_47 )
;
V_39 = F_27 ( V_5 -> V_50 , V_4 ) ;
if ( V_210 ) {
V_37 = V_211 = V_5 -> V_48 ;
while ( V_37 -- > 0 )
* V_210 ++ = * V_39 ++ ;
} else
V_211 = * V_39 ;
V_5 -> V_8 &= ~ ( V_54 | V_55 | V_56 | V_57 | V_60 ) ;
V_5 -> V_8 |= V_47 ;
if ( V_5 -> V_8 & V_10 )
V_5 = V_4 -> V_61 ;
else
V_5 ++ ;
V_4 -> V_45 = ( T_1 * ) V_5 ;
return ( int ) V_211 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( ! V_46 ) {
V_46 = 1 ;
V_212 = 0 ;
}
if ( V_212 <= 0 ) {
V_212 = F_76 ( V_213 , V_4 ) ;
V_214 = V_213 ;
}
V_212 -- ;
return * V_214 ++ ;
}
static void F_78 ( struct V_1 * V_2 ,
unsigned char V_211 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
static char V_38 [ 2 ] ;
V_38 [ 0 ] = ( char ) V_211 ;
F_75 ( V_4 , V_38 , 1 ) ;
}
static int F_79 ( struct V_215 * V_216 ,
struct V_3 * V_4 )
{
const T_13 * V_73 ;
void T_2 * V_217 , * V_218 ;
int V_219 ;
int V_7 ;
int V_37 ;
V_73 = F_80 ( V_216 , L_23 , NULL ) ;
if ( V_73 ) {
struct V_142 * V_142 = F_81 ( NULL , ( const char * ) V_73 ) ;
if ( ! F_82 ( V_142 ) )
V_4 -> V_142 = V_142 ;
}
if ( ! V_4 -> V_142 ) {
V_73 = F_80 ( V_216 , L_24 , & V_219 ) ;
if ( ! V_73 || V_219 != 4 ) {
F_26 ( V_220 L_25
L_26 , V_216 -> V_221 ) ;
return - V_148 ;
}
V_4 -> V_143 = * V_73 ;
}
V_73 = F_80 ( V_216 , L_27 , & V_219 ) ;
if ( ! V_73 || V_219 != 4 ) {
F_26 ( V_220 L_25
L_28 , V_216 -> V_221 ) ;
return - V_148 ;
}
V_4 -> V_222 = * V_73 ;
V_217 = F_83 ( V_216 , 0 ) ;
if ( ! V_217 )
return - V_223 ;
if ( F_84 ( V_216 , L_29 ) ||
F_84 ( V_216 , L_30 ) ) {
V_4 -> V_27 = V_217 ;
V_4 -> V_95 = V_218 = F_85 ( V_4 , V_216 ) ;
} else if ( F_84 ( V_216 , L_31 ) ||
F_84 ( V_216 , L_32 ) ) {
V_4 -> V_82 |= V_224 ;
V_4 -> V_26 = V_217 ;
V_4 -> V_93 = V_218 = F_85 ( V_4 , V_216 ) ;
} else {
V_7 = - V_225 ;
goto V_226;
}
if ( ! V_218 ) {
V_7 = - V_223 ;
goto V_226;
}
V_4 -> V_167 = V_227 ;
V_4 -> V_160 = V_228 ;
V_4 -> V_165 = V_229 ;
V_4 -> V_110 = V_111 ;
V_4 -> V_2 . V_107 = V_230 ;
V_4 -> V_2 . V_231 = ( unsigned long ) V_217 ;
V_4 -> V_2 . type = V_144 ;
V_4 -> V_2 . V_232 = & V_233 ,
V_4 -> V_2 . V_234 = V_235 ;
V_4 -> V_2 . V_236 = V_4 -> V_167 * V_4 -> V_160 ;
F_86 ( & V_4 -> V_2 . V_136 ) ;
V_4 -> V_2 . V_72 = F_87 ( V_216 , 0 , NULL ) ;
if ( V_4 -> V_2 . V_72 == V_237 ) {
V_7 = - V_148 ;
goto V_238;
}
for ( V_37 = 0 ; V_37 < V_239 ; V_37 ++ )
V_4 -> V_13 [ V_37 ] = F_88 ( V_216 , V_37 ) ;
#ifdef F_89
V_240 = NULL ;
#endif
return F_70 ( & V_4 -> V_2 ) ;
V_238:
F_90 ( V_4 , V_218 ) ;
V_226:
F_91 ( V_217 ) ;
return V_7 ;
}
static void F_92 ( struct V_241 * V_242 , const char * V_243 ,
T_11 V_152 )
{
struct V_3 * V_4 = & V_244 [ V_242 -> V_245 ] ;
unsigned long V_82 ;
int V_246 = V_247 ;
if ( F_24 ( V_246 ) ) {
F_93 ( V_82 ) ;
} else {
F_51 ( & V_4 -> V_2 . V_136 , V_82 ) ;
}
F_75 ( V_4 , V_243 , V_152 ) ;
if ( F_24 ( V_246 ) ) {
F_94 ( V_82 ) ;
} else {
F_55 ( & V_4 -> V_2 . V_136 , V_82 ) ;
}
}
static int T_14 F_95 ( struct V_241 * V_242 , char * V_248 )
{
int V_101 = 38400 ;
int V_105 = 8 ;
int V_63 = 'n' ;
int V_249 = 'n' ;
int V_7 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_215 * V_216 = NULL ;
int V_37 = 0 ;
if ( V_242 -> V_245 >= V_250 ) {
F_26 ( V_220 L_33 ,
V_242 -> V_245 ) ;
return - V_225 ;
}
do {
V_216 = F_96 ( V_216 , L_34 ) ;
if ( ! V_216 )
return - V_225 ;
if ( ! F_84 ( V_216 , L_31 ) &&
! F_84 ( V_216 , L_29 ) &&
! F_84 ( V_216 , L_32 ) &&
! F_84 ( V_216 , L_30 ) )
V_37 -- ;
} while ( V_37 ++ != V_242 -> V_245 );
V_4 = & V_244 [ V_242 -> V_245 ] ;
V_4 -> V_82 |= V_83 ;
V_2 = & V_4 -> V_2 ;
V_7 = F_79 ( V_216 , V_4 ) ;
F_97 ( V_216 ) ;
if ( V_7 )
return V_7 ;
if ( V_248 ) {
F_98 ( V_248 , & V_101 , & V_63 , & V_105 , & V_249 ) ;
} else {
if ( ( V_101 = F_99 () ) == - 1 )
V_101 = 9600 ;
}
if ( F_9 ( V_4 ) ) {
F_36 ( & V_4 -> V_93 -> V_94 , 0 ) ;
F_20 ( V_4 , V_35 ) ;
F_10 ( & V_4 -> V_26 -> V_28 , V_32 | V_29 ) ;
F_11 ( & V_4 -> V_26 -> V_84 , V_85 | V_89 ) ;
} else {
F_36 ( & V_4 -> V_95 -> V_96 , 0 ) ;
F_20 ( V_4 , V_97 ) ;
F_11 ( & V_4 -> V_27 -> V_30 , V_31 | V_33 ) ;
F_38 ( & V_4 -> V_27 -> V_86 , V_87 | V_90 ) ;
}
V_7 = F_71 ( V_4 , 1 ) ;
if ( V_7 )
return V_7 ;
F_46 ( V_4 ) ;
if ( F_9 ( V_4 ) )
F_67 ( V_4 ) ;
else
F_65 ( V_4 ) ;
F_100 ( V_2 , V_242 , V_101 , V_63 , V_105 , V_249 ) ;
F_20 ( V_4 , V_36 ) ;
return 0 ;
}
static int T_14 F_101 ( void )
{
F_102 ( & V_251 ) ;
return 0 ;
}
static int T_15 F_103 ( struct V_252 * V_253 )
{
int V_245 = V_254 ++ ;
struct V_3 * V_4 = & V_244 [ V_245 ] ;
int V_7 ;
V_4 -> V_2 . line = V_245 ;
if ( V_245 >= V_250 )
return - V_225 ;
F_104 ( & V_253 -> V_255 , V_4 ) ;
V_4 -> V_2 . V_255 = & V_253 -> V_255 ;
V_7 = F_79 ( V_253 -> V_255 . V_256 , V_4 ) ;
if ( V_7 )
return V_7 ;
return F_105 ( & V_257 , & V_4 -> V_2 ) ;
}
static int T_16 F_106 ( struct V_252 * V_253 )
{
struct V_3 * V_4 = F_107 ( & V_253 -> V_255 ) ;
return F_108 ( & V_257 , & V_4 -> V_2 ) ;
}
static int T_14 F_109 ( void )
{
int V_7 = F_110 ( & V_257 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_111 ( & V_258 ) ;
if ( V_7 )
F_112 ( & V_257 ) ;
return V_7 ;
}
static void T_17 F_113 ( void )
{
F_114 ( & V_258 ) ;
F_112 ( & V_257 ) ;
}
