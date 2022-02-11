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
static void F_18 ( struct V_1 * V_2 , int V_34 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_3 ( L_5 , V_2 -> line ,
V_34 ) ;
if ( V_34 )
F_19 ( V_4 , V_35 ) ;
else
F_19 ( V_4 , V_36 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_3 ( L_6 , V_2 -> line ) ;
F_14 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned char V_38 ;
T_5 * V_39 ;
struct V_40 * V_41 = & V_2 -> V_42 -> V_2 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_1 T_2 * V_5 ;
T_6 V_43 ;
unsigned int V_44 ;
F_3 ( L_7 , V_2 -> line ) ;
V_5 = V_4 -> V_45 ;
for (; ; ) {
#ifdef F_22
if ( F_23 ( V_46 ) ) {
V_46 = 0 ;
return;
}
#endif
V_43 = F_2 ( & V_5 -> V_8 ) ;
if ( V_43 & V_47 )
break;
V_37 = F_2 ( & V_5 -> V_48 ) ;
if ( F_24 ( V_41 , V_37 ) < V_37 ) {
F_25 ( V_49 L_8 ) ;
return;
}
V_39 = F_26 ( F_27 ( & V_5 -> V_50 ) , V_4 ) ;
while ( V_37 -- > 0 ) {
V_38 = * V_39 ++ ;
V_2 -> V_51 . V_52 ++ ;
V_44 = V_53 ;
if ( V_43 &
( V_54 | V_55 | V_56 | V_57 ) )
goto V_58;
if ( F_28 ( V_2 , V_38 ) )
continue;
#ifdef F_22
if ( F_23 ( V_46 ) ) {
V_46 = 0 ;
return;
}
#endif
V_59:
F_29 ( V_41 , V_38 , V_44 ) ;
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
F_30 ( V_41 ) ;
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
#ifdef F_31
V_2 -> V_71 = 0 ;
#endif
goto V_59;
}
static T_7 F_32 ( int V_72 , void * V_73 )
{
T_5 V_74 ;
struct V_1 * V_2 = V_73 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 T_2 * V_26 = V_4 -> V_26 ;
T_4 T_2 * V_27 = V_4 -> V_27 ;
F_3 ( L_9 , V_2 -> line ) ;
if ( F_9 ( V_4 ) ) {
V_74 = F_13 ( & V_26 -> V_75 ) ;
F_33 ( & V_26 -> V_75 , V_74 ) ;
if ( V_74 & V_76 )
F_34 ( V_2 ) ;
if ( V_74 & V_32 )
F_21 ( V_2 ) ;
if ( V_74 & V_29 )
F_20 ( V_2 ) ;
} else {
V_74 = F_2 ( & V_27 -> V_77 ) ;
F_35 ( & V_27 -> V_77 , V_74 ) ;
if ( V_74 & V_78 )
F_34 ( V_2 ) ;
if ( V_74 & V_33 )
F_21 ( V_2 ) ;
if ( V_74 & V_31 )
F_20 ( V_2 ) ;
}
return ( V_74 ) ? V_79 : V_80 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_81 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_3 ( L_10 , V_2 -> line ) ;
if ( ! ( V_4 -> V_82 & V_83 ) ) {
if ( F_9 ( V_4 ) ) {
F_11 ( & V_4 -> V_26 -> V_84 , V_85 ) ;
F_10 ( & V_4 -> V_26 -> V_28 , V_32 ) ;
} else {
F_37 ( & V_4 -> V_27 -> V_86 , V_87 ) ;
F_11 ( & V_4 -> V_27 -> V_30 , V_33 ) ;
}
F_38 ( V_4 ) ;
F_19 ( V_4 , V_88 ) ;
}
V_81 = F_39 ( V_2 -> V_72 , F_32 , 0 , L_11 , V_2 ) ;
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
F_3 ( L_12 , V_2 -> line ) ;
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
F_37 ( & V_27 -> V_86 , V_87 | V_90 ) ;
F_11 ( & V_27 -> V_30 , V_31 | V_33 ) ;
}
if ( F_9 ( V_4 ) ) {
F_35 ( & V_4 -> V_93 -> V_94 , 0 ) ;
F_19 ( V_4 , V_35 ) ;
} else {
F_35 ( & V_4 -> V_95 -> V_96 , 0 ) ;
F_19 ( V_4 , V_97 ) ;
}
F_38 ( V_4 ) ;
}
}
static void F_46 ( struct V_1 * V_2 ,
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
int V_107 ;
F_3 ( L_13 , V_2 -> line ) ;
V_101 = F_47 ( V_2 , V_99 , V_100 , 0 , V_2 -> V_108 / 16 ) ;
if ( V_101 < V_109 ||
( V_4 -> V_2 . V_42 && V_4 -> V_2 . V_42 -> V_2 . V_110 ) )
V_4 -> V_111 = 1 ;
else
V_4 -> V_111 = V_112 ;
V_107 = V_101 / 2400 ;
if ( V_107 < 1 )
V_107 = 1 ;
if ( V_107 > 0x10 )
V_107 = 0x10 ;
V_102 = 0 ;
V_103 = 0 ;
switch ( V_99 -> V_113 & V_114 ) {
case V_115 :
V_105 = 5 ;
break;
case V_116 :
V_105 = 6 ;
break;
case V_117 :
V_105 = 7 ;
break;
case V_118 :
V_105 = 8 ;
break;
default:
V_105 = 8 ;
break;
}
V_106 = V_105 - 5 ;
if ( V_99 -> V_113 & V_119 ) {
V_102 |= V_120 ;
V_103 |= V_121 ;
V_105 ++ ;
}
if ( V_99 -> V_113 & V_122 ) {
V_102 |= V_123 ;
V_103 |= V_124 ;
V_105 ++ ;
if ( ! ( V_99 -> V_113 & V_125 ) ) {
V_102 |= V_126 ;
V_103 |= ( V_127 | V_128 ) ;
}
}
F_48 ( V_2 , V_99 -> V_113 , V_101 ) ;
#define F_49 ( T_8 ) (iflag & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK))
V_2 -> V_66 = ( V_47 | V_57 ) ;
if ( V_99 -> V_129 & V_130 )
V_2 -> V_66 |= V_55 | V_56 ;
if ( ( V_99 -> V_129 & V_131 ) || ( V_99 -> V_129 & V_132 ) )
V_2 -> V_66 |= V_54 ;
V_2 -> V_133 = 0 ;
if ( V_99 -> V_129 & V_134 )
V_2 -> V_133 |= V_56 | V_55 ;
if ( V_99 -> V_129 & V_135 ) {
V_2 -> V_133 |= V_54 ;
if ( V_99 -> V_129 & V_134 )
V_2 -> V_133 |= V_57 ;
}
if ( ( V_99 -> V_113 & V_136 ) == 0 )
V_2 -> V_66 &= ~ V_47 ;
F_50 ( & V_2 -> V_137 , V_82 ) ;
V_105 ++ ;
if ( F_9 ( V_4 ) ) {
F_35 ( & V_4 -> V_93 -> V_138 , V_4 -> V_111 ) ;
F_35 ( & V_4 -> V_93 -> V_139 , V_107 ) ;
V_104 = F_2 ( & V_26 -> V_84 ) & ( V_85 | V_89 ) ;
F_35 ( & V_26 -> V_84 , F_51 ( V_105 ) | V_102 |
V_140 | V_104 ) ;
} else {
F_35 ( & V_4 -> V_95 -> V_141 . V_142 , V_4 -> V_111 ) ;
F_35 ( & V_4 -> V_95 -> V_143 , V_107 ) ;
F_35 ( & V_27 -> V_144 , ( V_106 << 12 ) | V_103 ) ;
}
if ( V_4 -> V_145 )
F_52 ( V_4 -> V_145 , V_101 ) ;
else
F_53 ( V_4 -> V_146 - 1 , V_101 ) ;
F_54 ( & V_2 -> V_137 , V_82 ) ;
}
static const char * F_55 ( struct V_1 * V_2 )
{
F_3 ( L_14 , V_2 -> line ) ;
return V_2 -> type == V_147 ? L_15 : NULL ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_7 = 0 ;
F_3 ( L_16 , V_2 -> line ) ;
if ( V_149 -> type != V_150 && V_149 -> type != V_147 )
V_7 = - V_151 ;
if ( V_149 -> V_72 < 0 || V_149 -> V_72 >= V_152 )
V_7 = - V_151 ;
if ( V_149 -> V_153 < 9600 )
V_7 = - V_151 ;
return V_7 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 T_2 * V_5 ;
T_5 * V_154 ;
int V_155 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_156 * V_157 = & V_2 -> V_42 -> V_157 ;
if ( V_2 -> V_158 ) {
V_5 = V_4 -> V_159 ;
V_154 = F_26 ( F_27 ( & V_5 -> V_50 ) , V_4 ) ;
* V_154 ++ = V_2 -> V_158 ;
F_35 ( & V_5 -> V_48 , 1 ) ;
F_16 ( & V_5 -> V_8 , V_9 ) ;
if ( F_2 ( & V_5 -> V_8 ) & V_10 )
V_5 = V_4 -> V_6 ;
else
V_5 ++ ;
V_4 -> V_159 = V_5 ;
V_2 -> V_51 . V_160 ++ ;
V_2 -> V_158 = 0 ;
return 1 ;
}
if ( F_57 ( V_157 ) || F_58 ( V_2 ) ) {
F_8 ( V_2 ) ;
return 0 ;
}
V_5 = V_4 -> V_159 ;
while ( ! ( F_2 ( & V_5 -> V_8 ) & V_9 ) &&
V_157 -> V_161 != V_157 -> V_162 ) {
V_155 = 0 ;
V_154 = F_26 ( F_27 ( & V_5 -> V_50 ) , V_4 ) ;
while ( V_155 < V_4 -> V_163 ) {
* V_154 ++ = V_157 -> V_164 [ V_157 -> V_161 ] ;
V_157 -> V_161 = ( V_157 -> V_161 + 1 ) & ( V_165 - 1 ) ;
V_2 -> V_51 . V_160 ++ ;
V_155 ++ ;
if ( V_157 -> V_162 == V_157 -> V_161 )
break;
}
F_35 ( & V_5 -> V_48 , V_155 ) ;
F_16 ( & V_5 -> V_8 , V_9 ) ;
if ( F_2 ( & V_5 -> V_8 ) & V_10 )
V_5 = V_4 -> V_6 ;
else
V_5 ++ ;
}
V_4 -> V_159 = V_5 ;
if ( F_59 ( V_157 ) < V_166 )
F_60 ( V_2 ) ;
if ( F_57 ( V_157 ) ) {
F_8 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
static void F_38 ( struct V_3 * V_4 )
{
int V_37 ;
T_5 * V_167 ;
T_1 T_2 * V_5 ;
F_3 ( L_17 , V_4 -> V_2 . line ) ;
V_167 = V_4 -> V_167 ;
V_5 = V_4 -> V_45 = V_4 -> V_61 ;
for ( V_37 = 0 ; V_37 < ( V_4 -> V_168 - 1 ) ; V_37 ++ , V_5 ++ ) {
F_61 ( & V_5 -> V_50 , F_62 ( V_167 , V_4 ) ) ;
F_35 ( & V_5 -> V_8 , V_47 | V_169 ) ;
V_167 += V_4 -> V_111 ;
}
F_61 ( & V_5 -> V_50 , F_62 ( V_167 , V_4 ) ) ;
F_35 ( & V_5 -> V_8 , V_10 | V_47 | V_169 ) ;
V_167 = V_4 -> V_167 + F_63 ( V_4 -> V_168 * V_4 -> V_111 ) ;
V_5 = V_4 -> V_159 = V_4 -> V_6 ;
for ( V_37 = 0 ; V_37 < ( V_4 -> V_170 - 1 ) ; V_37 ++ , V_5 ++ ) {
F_61 ( & V_5 -> V_50 , F_62 ( V_167 , V_4 ) ) ;
F_35 ( & V_5 -> V_8 , V_169 ) ;
V_167 += V_4 -> V_163 ;
}
F_61 ( & V_5 -> V_50 , F_62 ( V_167 , V_4 ) ) ;
F_35 ( & V_5 -> V_8 , V_10 | V_169 ) ;
}
static void F_64 ( struct V_3 * V_4 )
{
T_4 T_2 * V_171 ;
T_9 T_2 * V_172 ;
F_3 ( L_18 , V_4 -> V_2 . line ) ;
V_171 = V_4 -> V_27 ;
V_172 = V_4 -> V_95 ;
F_35 ( & V_4 -> V_95 -> V_141 . V_173 ,
( T_5 T_2 * ) V_4 -> V_61 - V_174 ) ;
F_35 ( & V_4 -> V_95 -> V_141 . V_175 ,
( T_5 T_2 * ) V_4 -> V_6 - V_174 ) ;
F_65 ( V_172 ) ;
F_35 ( & V_172 -> V_141 . V_142 , V_4 -> V_111 ) ;
F_35 ( & V_172 -> V_143 , 0x10 ) ;
F_35 ( & V_172 -> V_96 , 1 ) ;
F_35 ( & V_172 -> V_176 , 0 ) ;
F_35 ( & V_172 -> V_177 , 0 ) ;
F_35 ( & V_172 -> V_178 , 0 ) ;
F_35 ( & V_172 -> V_179 , 0 ) ;
F_35 ( & V_172 -> V_180 , 0 ) ;
F_35 ( & V_172 -> V_181 , 0 ) ;
F_35 ( & V_172 -> V_182 , 0 ) ;
F_35 ( & V_172 -> V_183 , 0x8000 ) ;
F_35 ( & V_172 -> V_184 , 0x8000 ) ;
F_35 ( & V_172 -> V_185 , 0x8000 ) ;
F_35 ( & V_172 -> V_186 , 0x8000 ) ;
F_35 ( & V_172 -> V_187 , 0x8000 ) ;
F_35 ( & V_172 -> V_188 , 0x8000 ) ;
F_35 ( & V_172 -> V_189 , 0x8000 ) ;
F_35 ( & V_172 -> V_190 , 0x8000 ) ;
F_35 ( & V_172 -> V_191 , 0xc0ff ) ;
F_19 ( V_4 , V_88 ) ;
F_61 ( & V_171 -> V_192 , 0 ) ;
F_61 ( & V_171 -> V_86 ,
V_193 | V_194 | V_195 ) ;
F_35 ( & V_171 -> V_30 , 0 ) ;
F_35 ( & V_171 -> V_77 , 0xffff ) ;
F_35 ( & V_171 -> V_196 , 0x7e7e ) ;
F_35 ( & V_171 -> V_144 , 0x3000 ) ;
F_40 ( & V_171 -> V_86 , V_87 | V_90 ) ;
}
static void F_66 ( struct V_3 * V_4 )
{
T_3 T_2 * V_197 ;
T_10 T_2 * V_198 ;
F_3 ( L_19 , V_4 -> V_2 . line ) ;
V_197 = V_4 -> V_26 ;
V_198 = V_4 -> V_93 ;
F_35 ( & V_4 -> V_93 -> V_199 ,
( T_5 T_2 * ) V_4 -> V_61 - V_174 ) ;
F_35 ( & V_4 -> V_93 -> V_200 ,
( T_5 T_2 * ) V_4 -> V_6 - V_174 ) ;
#if F_67 ( V_201 )
F_35 ( & V_198 -> V_202 , F_2 ( & V_4 -> V_93 -> V_199 ) ) ;
F_35 ( & V_198 -> V_203 , F_2 ( & V_4 -> V_93 -> V_200 ) ) ;
F_61 ( & V_198 -> V_204 , 0 ) ;
F_61 ( & V_198 -> V_205 , 0 ) ;
F_35 ( & V_198 -> V_94 , 1 ) ;
F_35 ( & V_198 -> V_206 , 0 ) ;
#endif
F_68 ( V_198 ) ;
F_35 ( & V_198 -> V_138 , V_4 -> V_111 ) ;
F_35 ( & V_198 -> V_139 , 0x10 ) ;
F_35 ( & V_198 -> V_207 , 0 ) ;
F_35 ( & V_198 -> V_206 , 0 ) ;
F_35 ( & V_198 -> V_94 , 1 ) ;
F_19 ( V_4 , V_88 ) ;
F_35 ( & V_197 -> V_84 , F_51 ( 9 ) | V_140 ) ;
F_33 ( & V_197 -> V_28 , 0 ) ;
F_33 ( & V_197 -> V_75 , 0xff ) ;
F_16 ( & V_197 -> V_84 , V_85 | V_89 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
int V_7 ;
F_3 ( L_20 , V_2 -> line ) ;
if ( V_4 -> V_82 & V_83 )
return 0 ;
if ( F_9 ( V_4 ) ) {
F_10 ( & V_4 -> V_26 -> V_28 , V_32 | V_29 ) ;
F_11 ( & V_4 -> V_26 -> V_84 , V_85 | V_89 ) ;
} else {
F_11 ( & V_4 -> V_27 -> V_30 , V_31 | V_33 ) ;
F_37 ( & V_4 -> V_27 -> V_86 , V_87 | V_90 ) ;
}
V_7 = F_70 ( V_4 , 0 ) ;
if ( V_7 )
return V_7 ;
F_38 ( V_4 ) ;
if ( F_9 ( V_4 ) )
F_66 ( V_4 ) ;
else
F_64 ( V_4 ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( ! ( V_4 -> V_82 & V_83 ) )
F_72 ( V_4 ) ;
}
static void F_73 ( struct V_1 * V_2 , int V_82 )
{
F_3 ( L_21 , V_2 -> line ) ;
if ( V_82 & V_208 ) {
V_2 -> type = V_147 ;
F_69 ( V_2 ) ;
}
}
static void F_74 ( struct V_3 * V_4 ,
const char * string , T_11 V_155 , bool V_209 )
{
unsigned int V_37 ;
T_1 T_2 * V_5 , * V_210 ;
unsigned char * V_211 ;
V_5 = V_4 -> V_159 ;
V_210 = V_4 -> V_6 ;
for ( V_37 = 0 ; V_37 < V_155 ; V_37 ++ , string ++ ) {
while ( ( F_2 ( & V_5 -> V_8 ) & V_9 ) != 0 )
;
V_211 = F_26 ( F_27 ( & V_5 -> V_50 ) ,
V_4 ) ;
* V_211 = * string ;
F_35 ( & V_5 -> V_48 , 1 ) ;
F_16 ( & V_5 -> V_8 , V_9 ) ;
if ( F_2 ( & V_5 -> V_8 ) & V_10 )
V_5 = V_210 ;
else
V_5 ++ ;
if ( V_209 && * string == 10 ) {
while ( ( F_2 ( & V_5 -> V_8 ) & V_9 ) != 0 )
;
V_211 = F_26 ( F_27 ( & V_5 -> V_50 ) ,
V_4 ) ;
* V_211 = 13 ;
F_35 ( & V_5 -> V_48 , 1 ) ;
F_16 ( & V_5 -> V_8 , V_9 ) ;
if ( F_2 ( & V_5 -> V_8 ) & V_10 )
V_5 = V_210 ;
else
V_5 ++ ;
}
}
while ( ( F_2 ( & V_5 -> V_8 ) & V_9 ) != 0 )
;
V_4 -> V_159 = V_5 ;
}
static int F_75 ( char * V_212 , struct V_3 * V_4 )
{
T_12 V_213 , * V_39 ;
volatile T_1 * V_5 ;
int V_37 ;
V_5 = V_4 -> V_45 ;
while ( V_5 -> V_8 & V_47 )
;
V_39 = F_26 ( V_5 -> V_50 , V_4 ) ;
if ( V_212 ) {
V_37 = V_213 = V_5 -> V_48 ;
while ( V_37 -- > 0 )
* V_212 ++ = * V_39 ++ ;
} else
V_213 = * V_39 ;
V_5 -> V_8 &= ~ ( V_54 | V_55 | V_56 | V_57 | V_60 ) ;
V_5 -> V_8 |= V_47 ;
if ( V_5 -> V_8 & V_10 )
V_5 = V_4 -> V_61 ;
else
V_5 ++ ;
V_4 -> V_45 = ( T_1 * ) V_5 ;
return ( int ) V_213 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( ! V_46 ) {
V_46 = 1 ;
V_214 = 0 ;
}
if ( V_214 <= 0 ) {
V_214 = F_75 ( V_215 , V_4 ) ;
V_216 = V_215 ;
}
V_214 -- ;
return * V_216 ++ ;
}
static void F_77 ( struct V_1 * V_2 ,
unsigned char V_213 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
static char V_38 [ 2 ] ;
V_38 [ 0 ] = ( char ) V_213 ;
F_74 ( V_4 , V_38 , 1 , false ) ;
}
static int F_78 ( struct V_217 * V_218 ,
struct V_3 * V_4 )
{
const T_13 * V_73 ;
void T_2 * V_219 , * V_220 ;
int V_221 ;
int V_7 ;
int V_37 ;
V_73 = F_79 ( V_218 , L_22 , NULL ) ;
if ( V_73 ) {
struct V_145 * V_145 = F_80 ( NULL , ( const char * ) V_73 ) ;
if ( ! F_81 ( V_145 ) )
V_4 -> V_145 = V_145 ;
}
if ( ! V_4 -> V_145 ) {
V_73 = F_79 ( V_218 , L_23 , & V_221 ) ;
if ( ! V_73 || V_221 != 4 ) {
F_25 ( V_222 L_24
L_25 , V_218 -> V_223 ) ;
return - V_151 ;
}
V_4 -> V_146 = * V_73 ;
}
V_73 = F_79 ( V_218 , L_26 , & V_221 ) ;
if ( ! V_73 || V_221 != 4 ) {
F_25 ( V_222 L_24
L_27 , V_218 -> V_223 ) ;
return - V_151 ;
}
V_4 -> V_224 = * V_73 ;
V_219 = F_82 ( V_218 , 0 ) ;
if ( ! V_219 )
return - V_225 ;
if ( F_83 ( V_218 , L_28 ) ||
F_83 ( V_218 , L_29 ) ) {
V_4 -> V_27 = V_219 ;
V_4 -> V_95 = V_220 = F_84 ( V_4 , V_218 ) ;
} else if ( F_83 ( V_218 , L_30 ) ||
F_83 ( V_218 , L_31 ) ) {
V_4 -> V_82 |= V_226 ;
V_4 -> V_26 = V_219 ;
V_4 -> V_93 = V_220 = F_84 ( V_4 , V_218 ) ;
} else {
V_7 = - V_227 ;
goto V_228;
}
if ( ! V_220 ) {
V_7 = - V_225 ;
goto V_228;
}
V_4 -> V_170 = V_229 ;
V_4 -> V_163 = V_230 ;
V_4 -> V_168 = V_231 ;
V_4 -> V_111 = V_112 ;
V_4 -> V_2 . V_108 = V_232 ;
V_4 -> V_2 . V_233 = ( unsigned long ) V_219 ;
V_4 -> V_2 . type = V_147 ;
V_4 -> V_2 . V_234 = & V_235 ,
V_4 -> V_2 . V_236 = V_237 ;
V_4 -> V_2 . V_238 = V_4 -> V_170 * V_4 -> V_163 ;
F_85 ( & V_4 -> V_2 . V_137 ) ;
V_4 -> V_2 . V_72 = F_86 ( V_218 , 0 ) ;
if ( V_4 -> V_2 . V_72 == V_239 ) {
V_7 = - V_151 ;
goto V_240;
}
for ( V_37 = 0 ; V_37 < V_241 ; V_37 ++ ) {
int V_242 ;
V_4 -> V_13 [ V_37 ] = - 1 ;
V_242 = F_87 ( V_218 , V_37 ) ;
if ( F_88 ( V_242 ) ) {
V_7 = F_89 ( V_242 , L_11 ) ;
if ( V_7 ) {
F_90 ( L_32 , V_37 , V_7 ) ;
continue;
}
if ( V_37 == V_14 || V_37 == V_16 )
V_7 = F_91 ( V_242 , 0 ) ;
else
V_7 = F_92 ( V_242 ) ;
if ( V_7 ) {
F_90 ( L_33 ,
V_37 , V_7 ) ;
F_93 ( V_242 ) ;
continue;
}
V_4 -> V_13 [ V_37 ] = V_242 ;
}
}
#ifdef F_94
V_243 = NULL ;
#endif
return F_69 ( & V_4 -> V_2 ) ;
V_240:
F_95 ( V_4 , V_220 ) ;
V_228:
F_96 ( V_219 ) ;
return V_7 ;
}
static void F_97 ( struct V_244 * V_245 , const char * V_246 ,
T_11 V_155 )
{
struct V_3 * V_4 = & V_247 [ V_245 -> V_248 ] ;
unsigned long V_82 ;
int V_249 = V_250 ;
if ( F_23 ( V_249 ) ) {
F_98 ( V_82 ) ;
} else {
F_50 ( & V_4 -> V_2 . V_137 , V_82 ) ;
}
F_74 ( V_4 , V_246 , V_155 , true ) ;
if ( F_23 ( V_249 ) ) {
F_99 ( V_82 ) ;
} else {
F_54 ( & V_4 -> V_2 . V_137 , V_82 ) ;
}
}
static int T_14 F_100 ( struct V_244 * V_245 , char * V_251 )
{
int V_101 = 38400 ;
int V_105 = 8 ;
int V_63 = 'n' ;
int V_252 = 'n' ;
int V_7 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_217 * V_218 = NULL ;
int V_37 = 0 ;
if ( V_245 -> V_248 >= V_253 ) {
F_25 ( V_222 L_34 ,
V_245 -> V_248 ) ;
return - V_227 ;
}
do {
V_218 = F_101 ( V_218 , L_35 ) ;
if ( ! V_218 )
return - V_227 ;
if ( ! F_83 ( V_218 , L_30 ) &&
! F_83 ( V_218 , L_28 ) &&
! F_83 ( V_218 , L_31 ) &&
! F_83 ( V_218 , L_29 ) )
V_37 -- ;
} while ( V_37 ++ != V_245 -> V_248 );
V_4 = & V_247 [ V_245 -> V_248 ] ;
V_4 -> V_82 |= V_83 ;
V_2 = & V_4 -> V_2 ;
V_7 = F_78 ( V_218 , V_4 ) ;
F_102 ( V_218 ) ;
if ( V_7 )
return V_7 ;
if ( V_251 ) {
F_103 ( V_251 , & V_101 , & V_63 , & V_105 , & V_252 ) ;
} else {
if ( ( V_101 = F_104 () ) == - 1 )
V_101 = 9600 ;
}
if ( F_9 ( V_4 ) ) {
F_35 ( & V_4 -> V_93 -> V_94 , 0 ) ;
F_19 ( V_4 , V_35 ) ;
F_10 ( & V_4 -> V_26 -> V_28 , V_32 | V_29 ) ;
F_11 ( & V_4 -> V_26 -> V_84 , V_85 | V_89 ) ;
} else {
F_35 ( & V_4 -> V_95 -> V_96 , 0 ) ;
F_19 ( V_4 , V_97 ) ;
F_11 ( & V_4 -> V_27 -> V_30 , V_31 | V_33 ) ;
F_37 ( & V_4 -> V_27 -> V_86 , V_87 | V_90 ) ;
}
V_7 = F_70 ( V_4 , 1 ) ;
if ( V_7 )
return V_7 ;
F_38 ( V_4 ) ;
if ( F_9 ( V_4 ) )
F_66 ( V_4 ) ;
else
F_64 ( V_4 ) ;
F_105 ( V_2 , V_245 , V_101 , V_63 , V_105 , V_252 ) ;
F_19 ( V_4 , V_36 ) ;
return 0 ;
}
static int T_14 F_106 ( void )
{
F_107 ( & V_254 ) ;
return 0 ;
}
static int F_108 ( struct V_255 * V_256 )
{
int V_248 = V_257 ++ ;
struct V_3 * V_4 = & V_247 [ V_248 ] ;
int V_7 ;
V_4 -> V_2 . line = V_248 ;
if ( V_248 >= V_253 )
return - V_227 ;
F_109 ( V_256 , V_4 ) ;
V_4 -> V_2 . V_258 = & V_256 -> V_258 ;
V_7 = F_78 ( V_256 -> V_258 . V_259 , V_4 ) ;
if ( V_7 )
return V_7 ;
return F_110 ( & V_260 , & V_4 -> V_2 ) ;
}
static int F_111 ( struct V_255 * V_256 )
{
struct V_3 * V_4 = F_112 ( V_256 ) ;
return F_113 ( & V_260 , & V_4 -> V_2 ) ;
}
static int T_14 F_114 ( void )
{
int V_7 = F_115 ( & V_260 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_116 ( & V_261 ) ;
if ( V_7 )
F_117 ( & V_260 ) ;
return V_7 ;
}
static void T_15 F_118 ( void )
{
F_119 ( & V_261 ) ;
F_117 ( & V_260 ) ;
}
