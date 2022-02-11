static void F_1 ( T_1 * V_1 , unsigned char V_2 , unsigned short V_3 )
{
if ( V_2 == V_4 ) {
V_1 -> V_5 |= V_3 ;
F_2 ( V_1 , V_4 + V_6 , V_1 -> V_5 ) ;
} else {
V_1 -> V_7 |= V_3 ;
F_2 ( V_1 , V_8 + V_6 , V_1 -> V_7 ) ;
}
}
static void F_3 ( T_1 * V_1 , unsigned char V_2 , unsigned short V_3 )
{
if ( V_2 == V_4 ) {
V_1 -> V_5 &= ~ V_3 ;
F_2 ( V_1 , V_4 + V_6 , V_1 -> V_5 ) ;
} else {
V_1 -> V_7 &= ~ V_3 ;
F_2 ( V_1 , V_8 + V_6 , V_1 -> V_7 ) ;
}
}
static void * F_4 ( void )
{
return F_4 ;
}
static void F_5 ( struct V_9 * V_10 ,
const T_2 * V_11 , char * V_12 , int V_13 )
{
struct V_14 * V_15 ;
if ( ! V_10 )
return;
V_15 = F_6 ( V_10 ) ;
if ( V_15 ) {
if ( V_15 -> V_16 -> V_17 )
V_15 -> V_16 -> V_17 ( V_10 , V_11 , V_12 , V_13 ) ;
F_7 ( V_15 ) ;
}
}
static int F_8 ( struct V_18 * V_19 )
{
T_1 * V_1 ;
int V_20 ;
if ( V_21 >= V_22 )
F_9 ( L_1 ) ;
V_1 = F_10 ( sizeof( T_1 ) , V_23 ) ;
if ( ! V_1 ) {
F_9 ( L_2 ) ;
return - V_24 ;
}
V_1 -> V_25 = V_26 ;
F_11 ( & V_1 -> V_27 ) ;
V_1 -> V_27 . V_16 = & V_28 ;
F_12 ( & V_1 -> V_29 , V_30 ) ;
V_1 -> V_31 = 4096 ;
V_1 -> V_27 . V_32 = 5 * V_33 / 10 ;
V_1 -> V_27 . V_34 = 30 * V_33 ;
F_13 ( & V_1 -> V_35 ) ;
F_13 ( & V_1 -> V_36 ) ;
F_14 ( & V_1 -> V_37 ) ;
F_14 ( & V_1 -> V_38 ) ;
memcpy ( & V_1 -> V_39 , & V_40 , sizeof( V_41 ) ) ;
V_1 -> V_42 = V_43 ;
V_1 -> V_5 = 0xffff ;
V_1 -> V_7 = 0xffff ;
V_1 -> V_44 = 0xff ;
V_1 -> V_45 = V_19 ;
V_19 -> V_46 = V_1 ;
V_20 = F_15 ( V_19 ) ;
if ( V_20 )
return V_20 ;
F_16 ( V_1 ) ;
return 0 ;
}
static int F_17 ( struct V_18 * V_45 , void * V_47 )
{
return F_18 ( V_45 ) ;
}
static int F_15 ( struct V_18 * V_19 )
{
T_1 * V_1 = V_19 -> V_46 ;
int V_20 ;
if ( V_21 >= V_22 )
F_9 ( L_3 , V_19 ) ;
V_19 -> V_48 |= V_49 | V_50 ;
V_20 = F_19 ( V_19 , F_17 , NULL ) ;
if ( V_20 != 0 )
goto V_51;
V_19 -> V_52 = 8 ;
V_19 -> V_53 = V_54 ;
V_20 = F_20 ( V_19 , V_55 ) ;
if ( V_20 )
goto V_51;
V_20 = F_21 ( V_19 ) ;
if ( V_20 )
goto V_51;
V_1 -> V_56 = V_19 -> V_57 [ 0 ] -> V_58 ;
V_1 -> V_59 = V_19 -> V_60 ;
return 0 ;
V_51:
F_22 ( ( V_61 ) V_19 ) ;
return - V_62 ;
}
static void F_22 ( V_61 V_63 )
{
struct V_18 * V_19 = (struct V_18 * ) V_63 ;
if ( V_21 >= V_22 )
F_9 ( L_4 , V_19 ) ;
F_23 ( V_19 ) ;
}
static void F_24 ( struct V_18 * V_19 )
{
if ( V_21 >= V_22 )
F_9 ( L_5 , V_19 ) ;
( ( T_1 * ) V_19 -> V_46 ) -> V_64 = 1 ;
F_22 ( ( V_61 ) V_19 ) ;
F_25 ( ( T_1 * ) V_19 -> V_46 ) ;
}
static int F_26 ( struct V_18 * V_19 )
{
T_1 * V_1 = V_19 -> V_46 ;
V_1 -> V_64 = 1 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 )
{
T_1 * V_1 = V_19 -> V_46 ;
V_1 -> V_64 = 0 ;
return 0 ;
}
static inline bool F_28 ( T_1 * V_1 ,
char * V_65 , const char * V_66 )
{
#ifdef F_29
static const char * V_67 =
L_6 ;
static const char * V_68 =
L_7 ;
if ( ! V_1 ) {
F_9 ( V_68 , V_65 , V_66 ) ;
return true ;
}
if ( V_1 -> V_25 != V_26 ) {
F_9 ( V_67 , V_65 , V_66 ) ;
return true ;
}
#else
if ( ! V_1 )
return true ;
#endif
return false ;
}
static bool F_30 ( T_1 * V_1 , unsigned char V_2 )
{
int V_69 = 0 ;
while ( F_31 ( V_1 , ( unsigned char ) ( V_2 + V_70 ) ) & V_71 ) {
F_32 ( 1 ) ;
if ( V_69 ++ == 1000 )
return false ;
}
return true ;
}
static void F_33 ( T_1 * V_1 , unsigned char V_2 , unsigned char V_72 )
{
F_30 ( V_1 , V_2 ) ;
F_34 ( V_1 , ( unsigned char ) ( V_2 + V_73 ) , V_72 ) ;
}
static void F_35 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_8 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_9 , V_1 -> V_75 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_76 )
F_37 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
static void F_39 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_10 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_11 , V_1 -> V_75 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_76 )
F_40 ( V_1 , V_10 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
static int F_41 ( T_1 * V_1 )
{
unsigned long V_12 ;
int V_77 = 0 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_78 & V_79 ) {
V_1 -> V_78 &= ~ V_79 ;
V_77 = V_79 ;
} else if ( V_1 -> V_78 & V_80 ) {
V_1 -> V_78 &= ~ V_80 ;
V_77 = V_80 ;
} else if ( V_1 -> V_78 & V_81 ) {
V_1 -> V_78 &= ~ V_81 ;
V_77 = V_81 ;
}
if ( ! V_77 ) {
V_1 -> V_82 = false ;
V_1 -> V_83 = false ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
return V_77 ;
}
static void V_30 ( struct V_84 * V_85 )
{
T_1 * V_1 = F_42 ( V_85 , T_1 , V_29 ) ;
struct V_9 * V_10 ;
int V_86 ;
if ( ! V_1 )
return;
if ( V_21 >= V_87 )
F_9 ( L_12 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
V_1 -> V_82 = true ;
V_10 = F_43 ( & V_1 -> V_27 ) ;
while( ( V_86 = F_41 ( V_1 ) ) != 0 ) {
if ( V_21 >= V_87 )
F_9 ( L_13 ,
__FILE__ , __LINE__ , V_86 ) ;
switch ( V_86 ) {
case V_79 :
while( F_44 ( V_1 , V_10 ) ) ;
break;
case V_80 :
F_45 ( V_1 , V_10 ) ;
break;
case V_81 :
F_46 ( V_1 ) ;
break;
default:
F_9 ( L_14 , V_86 ) ;
break;
}
}
F_47 ( V_10 ) ;
if ( V_21 >= V_87 )
F_9 ( L_15 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
}
static void F_45 ( T_1 * V_1 , struct V_9 * V_10 )
{
if ( V_21 >= V_87 )
F_9 ( L_16 , V_1 -> V_75 ) ;
if ( V_10 )
F_48 ( V_10 ) ;
}
static void F_46 ( T_1 * V_1 )
{
V_1 -> V_88 = 0 ;
V_1 -> V_89 = 0 ;
V_1 -> V_90 = 0 ;
V_1 -> V_91 = 0 ;
}
static void F_49 ( T_1 * V_1 , int V_92 )
{
unsigned char V_11 [ 2 ] ;
unsigned char V_93 , V_94 , V_69 ;
T_3 * V_95 = ( T_3 * ) ( V_1 -> V_96 + ( V_1 -> V_97 * V_1 -> V_98 ) ) ;
if ( V_21 >= V_99 )
F_9 ( L_17 , __FILE__ , __LINE__ , V_92 ) ;
if ( ! V_1 -> V_100 )
return;
if ( V_1 -> V_101 >= V_1 -> V_102 ) {
F_33 ( V_1 , V_4 , V_103 ) ;
V_1 -> V_78 |= V_79 ;
V_1 -> V_104 = true ;
V_1 -> V_105 . V_106 ++ ;
return;
}
if ( V_92 ) {
if ( ! ( V_93 = ( unsigned char ) ( F_31 ( V_1 , V_4 + V_107 ) & 0x1f ) ) )
V_93 = 32 ;
} else
V_93 = 32 ;
do {
if ( V_93 == 1 ) {
V_94 = 1 ;
V_11 [ 0 ] = F_31 ( V_1 , V_4 + V_108 ) ;
} else {
V_94 = 2 ;
* ( ( unsigned short * ) V_11 ) = F_50 ( V_1 , V_4 + V_108 ) ;
}
V_93 -= V_94 ;
if ( ! V_93 && V_92 )
V_95 -> V_109 = V_11 [ -- V_94 ] ;
for ( V_69 = 0 ; V_69 < V_94 ; V_69 ++ ) {
if ( V_95 -> V_13 >= V_1 -> V_31 ) {
F_33 ( V_1 , V_4 , V_103 ) ;
V_95 -> V_13 = 0 ;
return;
}
* ( V_95 -> V_11 + V_95 -> V_13 ) = V_11 [ V_69 ] ;
V_95 -> V_13 ++ ;
}
} while ( V_93 );
if ( V_92 ) {
V_1 -> V_78 |= V_79 ;
V_1 -> V_101 ++ ;
V_1 -> V_97 ++ ;
if ( V_1 -> V_97 >= V_1 -> V_102 )
V_1 -> V_97 = 0 ;
}
F_33 ( V_1 , V_4 , V_110 ) ;
}
static void F_51 ( T_1 * V_1 , int V_111 , struct V_9 * V_10 )
{
unsigned char V_11 , V_109 , V_112 ;
int V_93 ;
int V_85 = 0 ;
struct V_113 * V_105 = & V_1 -> V_105 ;
if ( ! V_10 ) {
F_33 ( V_1 , V_4 , V_103 ) ;
if ( V_21 >= V_99 )
F_9 ( L_18 , __FILE__ , __LINE__ ) ;
return;
}
if ( V_111 ) {
V_93 = ( unsigned char ) ( F_31 ( V_1 , V_4 + V_107 ) & 0x1f ) ;
if ( ! V_93 && ( F_31 ( V_1 , V_4 + V_70 ) & V_114 ) )
V_93 = 32 ;
} else
V_93 = 32 ;
F_52 ( V_10 , V_93 ) ;
while ( V_93 ) {
V_11 = F_31 ( V_1 , V_4 + V_108 ) ;
V_109 = F_31 ( V_1 , V_4 + V_108 ) ;
V_93 -= 2 ;
V_105 -> V_115 ++ ;
V_112 = V_116 ;
if ( V_109 & ( V_117 + V_118 ) ) {
if ( V_109 & V_117 )
V_105 -> V_119 ++ ;
else
V_105 -> V_120 ++ ;
if ( V_109 & V_1 -> V_121 )
continue;
V_109 &= V_1 -> V_122 ;
if ( V_109 & V_117 )
V_112 = V_123 ;
else if ( V_109 & V_118 )
V_112 = V_124 ;
}
V_85 += F_53 ( V_10 , V_11 , V_112 ) ;
}
F_33 ( V_1 , V_4 , V_110 ) ;
if ( V_21 >= V_99 ) {
F_9 ( L_19 ,
__FILE__ , __LINE__ ) ;
F_9 ( L_20 ,
__FILE__ , __LINE__ , V_105 -> V_115 , V_105 -> V_125 ,
V_105 -> V_119 , V_105 -> V_120 , V_105 -> V_126 ) ;
}
if ( V_85 )
F_54 ( V_10 ) ;
}
static void F_55 ( T_1 * V_1 , struct V_9 * V_10 )
{
if ( ! V_1 -> V_127 )
return;
V_1 -> V_127 = false ;
V_1 -> V_128 = false ;
if ( V_1 -> V_39 . V_129 == V_130 )
return;
V_1 -> V_131 = V_1 -> V_132 = V_1 -> V_133 = 0 ;
F_56 ( & V_1 -> V_134 ) ;
if ( V_1 -> V_135 ) {
F_57 ( V_1 ) ;
if ( V_1 -> V_136 & V_137 ) {
V_1 -> V_136 &= ~ V_137 ;
F_58 ( V_1 ) ;
}
V_1 -> V_135 = false ;
}
#if V_138
if ( V_1 -> V_139 )
F_59 ( V_1 ) ;
else
#endif
{
if ( V_10 && ( V_10 -> V_140 || V_10 -> V_141 ) ) {
F_37 ( V_1 ) ;
return;
}
V_1 -> V_78 |= V_80 ;
}
}
static void F_60 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned char V_93 = 32 ;
int V_142 ;
if ( V_21 >= V_99 )
F_9 ( L_21 , __FILE__ , __LINE__ , V_1 -> V_75 ) ;
if ( V_1 -> V_39 . V_129 == V_143 ) {
if ( ! V_1 -> V_127 )
return;
} else {
if ( V_10 && ( V_10 -> V_140 || V_10 -> V_141 ) ) {
F_37 ( V_1 ) ;
return;
}
if ( ! V_1 -> V_131 )
V_1 -> V_127 = false ;
}
if ( ! V_1 -> V_131 )
return;
while ( V_1 -> V_131 && V_93 ) {
V_142 = F_61 ( 2 , F_62 ( int , V_93 , F_61 ( V_1 -> V_131 , V_144 - V_1 -> V_133 ) ) ) ;
if ( V_142 == 1 ) {
F_34 ( V_1 , V_4 + V_145 , * ( V_1 -> V_146 + V_1 -> V_133 ) ) ;
} else {
F_2 ( V_1 , V_4 + V_145 ,
* ( ( unsigned short * ) ( V_1 -> V_146 + V_1 -> V_133 ) ) ) ;
}
V_1 -> V_131 -= V_142 ;
V_1 -> V_133 = ( V_1 -> V_133 + V_142 ) & ( V_144 - 1 ) ;
V_93 -= V_142 ;
}
if ( V_1 -> V_39 . V_129 == V_130 ) {
if ( V_1 -> V_131 < V_147 )
V_1 -> V_78 |= V_80 ;
F_33 ( V_1 , V_4 , V_148 ) ;
} else {
if ( V_1 -> V_131 )
F_33 ( V_1 , V_4 , V_148 ) ;
else
F_33 ( V_1 , V_4 , V_148 + V_149 ) ;
}
}
static void F_63 ( T_1 * V_1 , struct V_9 * V_10 )
{
F_57 ( V_1 ) ;
if ( ( V_1 -> V_91 ) ++ >= V_150 )
F_1 ( V_1 , V_8 , V_151 ) ;
V_1 -> V_105 . V_152 ++ ;
if ( V_1 -> V_136 & V_153 )
V_1 -> V_154 . V_155 ++ ;
else
V_1 -> V_154 . V_156 ++ ;
F_64 ( & V_1 -> V_35 ) ;
F_64 ( & V_1 -> V_36 ) ;
if ( V_10 && F_65 ( & V_1 -> V_27 ) ) {
if ( V_10 -> V_141 ) {
if ( V_1 -> V_136 & V_153 ) {
if ( V_21 >= V_99 )
F_9 ( L_22 ) ;
V_10 -> V_141 = 0 ;
F_40 ( V_1 , V_10 ) ;
V_1 -> V_78 |= V_80 ;
return;
}
} else {
if ( ! ( V_1 -> V_136 & V_153 ) ) {
if ( V_21 >= V_99 )
F_9 ( L_23 ) ;
V_10 -> V_141 = 1 ;
F_37 ( V_1 ) ;
}
}
}
V_1 -> V_78 |= V_81 ;
}
static void F_66 ( T_1 * V_1 , struct V_9 * V_10 )
{
F_57 ( V_1 ) ;
if ( ( V_1 -> V_90 ) ++ >= V_150 )
F_1 ( V_1 , V_8 , V_157 ) ;
V_1 -> V_105 . V_158 ++ ;
if ( V_1 -> V_136 & V_159 ) {
V_1 -> V_154 . V_160 ++ ;
}
else
V_1 -> V_154 . V_161 ++ ;
#if V_138
if ( V_1 -> V_139 ) {
if ( V_1 -> V_136 & V_159 )
F_67 ( V_1 -> V_162 ) ;
else
F_68 ( V_1 -> V_162 ) ;
}
#endif
F_64 ( & V_1 -> V_35 ) ;
F_64 ( & V_1 -> V_36 ) ;
if ( V_1 -> V_27 . V_12 & V_163 ) {
if ( V_21 >= V_99 )
F_9 ( L_24 , V_1 -> V_75 ,
( V_1 -> V_136 & V_159 ) ? L_25 : L_26 ) ;
if ( V_1 -> V_136 & V_159 )
F_64 ( & V_1 -> V_27 . V_164 ) ;
else {
if ( V_21 >= V_99 )
F_9 ( L_27 ) ;
if ( V_10 )
F_69 ( V_10 ) ;
}
}
V_1 -> V_78 |= V_81 ;
}
static void F_70 ( T_1 * V_1 )
{
F_57 ( V_1 ) ;
if ( ( V_1 -> V_89 ) ++ >= V_150 )
F_71 ( V_1 , V_165 ) ;
V_1 -> V_105 . V_166 ++ ;
if ( V_1 -> V_136 & V_167 )
V_1 -> V_154 . V_168 ++ ;
else
V_1 -> V_154 . V_169 ++ ;
F_64 ( & V_1 -> V_35 ) ;
F_64 ( & V_1 -> V_36 ) ;
V_1 -> V_78 |= V_81 ;
}
static void F_72 ( T_1 * V_1 )
{
F_57 ( V_1 ) ;
if ( ( V_1 -> V_88 ) ++ >= V_150 )
F_71 ( V_1 , V_170 ) ;
V_1 -> V_105 . V_171 ++ ;
if ( V_1 -> V_136 & V_172 )
V_1 -> V_154 . V_173 ++ ;
else
V_1 -> V_154 . V_174 ++ ;
F_64 ( & V_1 -> V_35 ) ;
F_64 ( & V_1 -> V_36 ) ;
V_1 -> V_78 |= V_81 ;
}
static T_4 V_55 ( int V_175 , void * V_176 )
{
T_1 * V_1 = V_176 ;
struct V_9 * V_10 ;
unsigned short V_177 ;
unsigned char V_178 , V_179 ;
int V_13 = 0 ;
if ( V_21 >= V_99 )
F_9 ( L_28 , V_1 -> V_59 ) ;
if ( ! ( V_1 -> V_45 -> V_180 ) )
return V_181 ;
V_10 = F_43 ( & V_1 -> V_27 ) ;
F_73 ( & V_1 -> V_37 ) ;
while ( ( V_178 = F_31 ( V_1 , V_4 + V_182 ) ) ) {
if ( V_21 >= V_99 )
F_9 ( L_29 , V_1 -> V_75 , V_178 ) ;
if ( ( V_178 & 0x70 ) || V_13 > 1000 ) {
F_9 ( L_30 ) ;
break;
}
V_13 ++ ;
if ( V_178 & ( V_183 + V_184 ) ) {
V_177 = F_50 ( V_1 , V_8 + V_185 ) ;
if ( V_177 & V_157 )
F_66 ( V_1 , V_10 ) ;
if ( V_177 & V_151 )
F_63 ( V_1 , V_10 ) ;
}
if ( V_178 & ( V_186 + V_71 ) )
{
V_177 = F_50 ( V_1 , V_4 + V_185 ) ;
if ( V_177 & V_187 ) {
V_1 -> V_188 = true ;
F_1 ( V_1 , V_4 , V_187 ) ;
}
if ( V_177 & V_189 ) {
V_1 -> V_105 . V_190 ++ ;
F_64 ( & V_1 -> V_36 ) ;
}
if ( V_177 & V_191 ) {
V_1 -> V_105 . V_125 ++ ;
if ( V_1 -> V_27 . V_12 & V_192 )
F_74 ( V_10 ) ;
}
if ( V_177 & V_193 ) {
F_33 ( V_1 , V_4 , V_194 ) ;
}
if ( V_177 & ( V_195 + V_196 ) ) {
if ( V_1 -> V_39 . V_129 == V_143 )
F_49 ( V_1 , V_177 & V_195 ) ;
else
F_51 ( V_1 , V_177 & V_195 , V_10 ) ;
}
if ( V_177 & V_197 ) {
if ( V_1 -> V_128 )
V_1 -> V_105 . V_198 ++ ;
else
V_1 -> V_105 . V_199 ++ ;
F_55 ( V_1 , V_10 ) ;
}
else if ( V_177 & V_200 ) {
V_1 -> V_105 . V_201 ++ ;
F_55 ( V_1 , V_10 ) ;
}
else if ( V_177 & V_202 )
F_60 ( V_1 , V_10 ) ;
}
if ( V_178 & V_117 ) {
V_179 = F_31 ( V_1 , V_4 + V_203 ) ;
if ( V_179 & V_183 )
F_70 ( V_1 ) ;
if ( V_179 & V_71 )
F_72 ( V_1 ) ;
}
}
if ( V_1 -> V_78 && ! V_1 -> V_82 && ! V_1 -> V_83 ) {
if ( V_21 >= V_99 )
F_9 ( L_31 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
F_75 ( & V_1 -> V_29 ) ;
V_1 -> V_83 = true ;
}
F_76 ( & V_1 -> V_37 ) ;
F_47 ( V_10 ) ;
if ( V_21 >= V_99 )
F_9 ( L_32 ,
__FILE__ , __LINE__ , V_1 -> V_59 ) ;
return V_181 ;
}
static int F_77 ( T_1 * V_1 , struct V_9 * V_10 )
{
int V_204 = 0 ;
if ( V_21 >= V_22 )
F_9 ( L_33 , __FILE__ , __LINE__ , V_1 -> V_75 ) ;
if ( V_1 -> V_27 . V_12 & V_205 )
return 0 ;
if ( ! V_1 -> V_146 ) {
V_1 -> V_146 = ( unsigned char * ) F_78 ( V_23 ) ;
if ( ! V_1 -> V_146 ) {
F_9 ( V_206 L_34 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
return - V_24 ;
}
}
V_1 -> V_78 = 0 ;
memset ( & V_1 -> V_105 , 0 , sizeof( V_1 -> V_105 ) ) ;
F_79 ( & V_1 -> V_134 , V_207 , ( unsigned long ) V_1 ) ;
V_204 = F_80 ( V_1 ) ;
if ( ! V_204 )
V_204 = F_81 ( V_1 ) ;
if ( V_204 ) {
if ( F_82 ( V_208 ) && V_10 )
F_83 ( V_209 , & V_10 -> V_12 ) ;
F_84 ( V_1 ) ;
return V_204 ;
}
F_85 ( V_1 , V_10 ) ;
if ( V_10 )
F_86 ( V_209 , & V_10 -> V_12 ) ;
V_1 -> V_27 . V_12 |= V_205 ;
return 0 ;
}
static void F_87 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned long V_12 ;
if ( ! ( V_1 -> V_27 . V_12 & V_205 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_35 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
F_64 ( & V_1 -> V_35 ) ;
F_64 ( & V_1 -> V_36 ) ;
F_88 ( & V_1 -> V_134 ) ;
if ( V_1 -> V_146 ) {
F_89 ( ( unsigned long ) V_1 -> V_146 ) ;
V_1 -> V_146 = NULL ;
}
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_90 ( V_1 ) ;
F_37 ( V_1 ) ;
F_91 ( V_1 ) ;
if ( ! V_10 || V_10 -> V_210 . V_211 & V_212 ) {
V_1 -> V_136 &= ~ ( V_213 + V_137 ) ;
F_58 ( V_1 ) ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_84 ( V_1 ) ;
if ( V_10 )
F_83 ( V_209 , & V_10 -> V_12 ) ;
V_1 -> V_27 . V_12 &= ~ V_205 ;
}
static void F_92 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned long V_12 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_90 ( V_1 ) ;
F_37 ( V_1 ) ;
V_1 -> V_131 = V_1 -> V_132 = V_1 -> V_133 = 0 ;
if ( V_1 -> V_39 . V_129 == V_143 || V_1 -> V_139 )
F_93 ( V_1 ) ;
else
F_94 ( V_1 ) ;
F_58 ( V_1 ) ;
V_1 -> V_90 = 0 ;
V_1 -> V_91 = 0 ;
V_1 -> V_88 = 0 ;
V_1 -> V_89 = 0 ;
F_3 ( V_1 , V_8 , V_157 | V_151 ) ;
F_95 ( V_1 , ( unsigned char ) V_165 | V_170 ) ;
F_57 ( V_1 ) ;
if ( V_1 -> V_139 || ( V_10 && ( V_10 -> V_210 . V_211 & V_214 ) ) )
F_96 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
static void F_85 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned V_215 ;
int V_216 ;
if ( ! V_10 )
return;
if ( V_21 >= V_22 )
F_9 ( L_36 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
V_215 = V_10 -> V_210 . V_211 ;
if ( V_215 & V_217 )
V_1 -> V_136 |= V_137 + V_213 ;
else
V_1 -> V_136 &= ~ ( V_137 + V_213 ) ;
switch ( V_215 & V_218 ) {
case V_219 : V_1 -> V_39 . V_220 = 5 ; break;
case V_221 : V_1 -> V_39 . V_220 = 6 ; break;
case V_222 : V_1 -> V_39 . V_220 = 7 ; break;
case V_223 : V_1 -> V_39 . V_220 = 8 ; break;
default: V_1 -> V_39 . V_220 = 7 ; break;
}
if ( V_215 & V_224 )
V_1 -> V_39 . V_225 = 2 ;
else
V_1 -> V_39 . V_225 = 1 ;
V_1 -> V_39 . V_119 = V_226 ;
if ( V_215 & V_227 ) {
if ( V_215 & V_228 )
V_1 -> V_39 . V_119 = V_229 ;
else
V_1 -> V_39 . V_119 = V_230 ;
#ifdef F_97
if ( V_215 & F_97 )
V_1 -> V_39 . V_119 = V_231 ;
#endif
}
V_216 = V_1 -> V_39 . V_220 +
V_1 -> V_39 . V_225 + 1 ;
if ( V_1 -> V_39 . V_232 <= 460800 ) {
V_1 -> V_39 . V_232 = F_98 ( V_10 ) ;
}
if ( V_1 -> V_39 . V_232 ) {
V_1 -> V_233 = ( 32 * V_33 * V_216 ) /
V_1 -> V_39 . V_232 ;
}
V_1 -> V_233 += V_33 / 50 ;
if ( V_215 & V_234 )
V_1 -> V_27 . V_12 |= V_235 ;
else
V_1 -> V_27 . V_12 &= ~ V_235 ;
if ( V_215 & V_236 )
V_1 -> V_27 . V_12 &= ~ V_163 ;
else
V_1 -> V_27 . V_12 |= V_163 ;
V_1 -> V_122 = 0 ;
if ( F_99 ( V_10 ) )
V_1 -> V_122 |= V_117 | V_118 ;
if ( F_100 ( V_10 ) )
V_1 -> V_121 |= V_117 | V_118 ;
F_92 ( V_1 , V_10 ) ;
}
static int F_101 ( struct V_9 * V_10 , unsigned char V_237 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 ) {
F_9 ( L_37 ,
__FILE__ , __LINE__ , V_237 , V_1 -> V_75 ) ;
}
if ( F_28 ( V_1 , V_10 -> V_65 , L_38 ) )
return 0 ;
if ( ! V_1 -> V_146 )
return 0 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_39 . V_129 == V_130 || ! V_1 -> V_127 ) {
if ( V_1 -> V_131 < V_144 - 1 ) {
V_1 -> V_146 [ V_1 -> V_132 ++ ] = V_237 ;
V_1 -> V_132 &= V_144 - 1 ;
V_1 -> V_131 ++ ;
}
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
return 1 ;
}
static void F_102 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_39 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_1 -> V_131 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_40 ) )
return;
if ( V_1 -> V_131 <= 0 || V_10 -> V_140 ||
V_10 -> V_141 || ! V_1 -> V_146 )
return;
if ( V_21 >= V_22 )
F_9 ( L_41 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_127 )
F_40 ( V_1 , V_10 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
static int F_103 ( struct V_9 * V_10 ,
const unsigned char * V_95 , int V_13 )
{
int V_142 , V_20 = 0 ;
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_42 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_13 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_43 ) ||
! V_1 -> V_146 )
goto V_238;
if ( V_1 -> V_39 . V_129 == V_143 ) {
if ( V_13 > V_144 ) {
V_20 = - V_239 ;
goto V_238;
}
if ( V_1 -> V_127 )
goto V_238;
else if ( V_1 -> V_131 )
goto V_58;
}
for (; ; ) {
V_142 = F_61 ( V_13 ,
F_61 ( V_144 - V_1 -> V_131 - 1 ,
V_144 - V_1 -> V_132 ) ) ;
if ( V_142 <= 0 )
break;
memcpy ( V_1 -> V_146 + V_1 -> V_132 , V_95 , V_142 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_132 = ( V_1 -> V_132 + V_142 ) & ( V_144 - 1 ) ;
V_1 -> V_131 += V_142 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_95 += V_142 ;
V_13 -= V_142 ;
V_20 += V_142 ;
}
V_58:
if ( V_1 -> V_131 && ! V_10 -> V_140 && ! V_10 -> V_141 ) {
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_127 )
F_40 ( V_1 , V_10 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
V_238:
if ( V_21 >= V_22 )
F_9 ( L_44 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_20 ) ;
return V_20 ;
}
static int F_104 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
int V_20 ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_45 ) )
return 0 ;
if ( V_1 -> V_39 . V_129 == V_143 ) {
if ( V_1 -> V_127 )
return 0 ;
else
return V_240 ;
} else {
V_20 = V_144 - V_1 -> V_131 - 1 ;
if ( V_20 < 0 )
V_20 = 0 ;
}
if ( V_21 >= V_22 )
F_9 ( L_46 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_20 ) ;
return V_20 ;
}
static int F_105 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
int V_77 ;
if ( V_21 >= V_22 )
F_9 ( L_47 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_48 ) )
return 0 ;
if ( V_1 -> V_39 . V_129 == V_143 )
V_77 = V_1 -> V_127 ? V_1 -> V_31 : 0 ;
else
V_77 = V_1 -> V_131 ;
if ( V_21 >= V_22 )
F_9 ( L_49 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_77 ) ;
return V_77 ;
}
static void F_106 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_50 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_51 ) )
return;
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_131 = V_1 -> V_132 = V_1 -> V_133 = 0 ;
F_56 ( & V_1 -> V_134 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_64 ( & V_10 -> V_241 ) ;
F_48 ( V_10 ) ;
}
static void F_107 ( struct V_9 * V_10 , char V_237 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_52 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_237 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_53 ) )
return;
V_1 -> V_242 = V_237 ;
if ( V_237 ) {
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_76 )
F_40 ( V_1 , V_10 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
}
static void F_108 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_54 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_55 ) )
return;
if ( F_109 ( V_10 ) )
F_107 ( V_10 , F_110 ( V_10 ) ) ;
if ( V_10 -> V_210 . V_211 & V_234 ) {
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_136 &= ~ V_137 ;
F_58 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
}
static void F_111 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_56 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_57 ) )
return;
if ( F_109 ( V_10 ) ) {
if ( V_1 -> V_242 )
V_1 -> V_242 = 0 ;
else
F_107 ( V_10 , F_112 ( V_10 ) ) ;
}
if ( V_10 -> V_210 . V_211 & V_234 ) {
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_136 |= V_137 ;
F_58 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
}
static int F_113 ( T_1 * V_1 , struct V_113 T_5 * V_243 )
{
int V_244 ;
if ( V_21 >= V_22 )
F_9 ( L_58 , V_1 -> V_75 ) ;
if ( ! V_243 ) {
memset ( & V_1 -> V_105 , 0 , sizeof( V_1 -> V_105 ) ) ;
} else {
F_114 ( V_244 , V_243 , & V_1 -> V_105 , sizeof( struct V_113 ) ) ;
if ( V_244 )
return - V_245 ;
}
return 0 ;
}
static int F_115 ( T_1 * V_1 , V_41 T_5 * V_246 )
{
int V_244 ;
if ( V_21 >= V_22 )
F_9 ( L_58 , V_1 -> V_75 ) ;
F_114 ( V_244 , V_246 , & V_1 -> V_39 , sizeof( V_41 ) ) ;
if ( V_244 )
return - V_245 ;
return 0 ;
}
static int F_116 ( T_1 * V_1 , V_41 T_5 * V_247 , struct V_9 * V_10 )
{
unsigned long V_12 ;
V_41 V_248 ;
int V_244 ;
if ( V_21 >= V_22 )
F_9 ( L_59 , __FILE__ , __LINE__ ,
V_1 -> V_75 ) ;
F_117 ( V_244 , & V_248 , V_247 , sizeof( V_41 ) ) ;
if ( V_244 ) {
if ( V_21 >= V_22 )
F_9 ( L_60 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
return - V_245 ;
}
F_36 ( & V_1 -> V_37 , V_12 ) ;
memcpy ( & V_1 -> V_39 , & V_248 , sizeof( V_41 ) ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_85 ( V_1 , V_10 ) ;
return 0 ;
}
static int F_118 ( T_1 * V_1 , int T_5 * V_42 )
{
int V_244 ;
if ( V_21 >= V_22 )
F_9 ( L_61 , V_1 -> V_75 , V_1 -> V_42 ) ;
F_114 ( V_244 , V_42 , & V_1 -> V_42 , sizeof( int ) ) ;
if ( V_244 )
return - V_245 ;
return 0 ;
}
static int F_119 ( T_1 * V_1 , int V_42 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_62 , V_1 -> V_75 , V_42 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_42 = V_42 ;
F_120 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_121 ( T_1 * V_1 , int T_5 * V_249 )
{
int V_244 ;
if ( V_21 >= V_22 )
F_9 ( L_63 , V_1 -> V_75 , V_1 -> V_249 ) ;
F_114 ( V_244 , V_249 , & V_1 -> V_249 , sizeof( int ) ) ;
if ( V_244 )
return - V_245 ;
return 0 ;
}
static int F_122 ( T_1 * V_1 , int V_249 )
{
unsigned long V_12 ;
unsigned char V_250 ;
if ( V_21 >= V_22 )
F_9 ( L_64 , V_1 -> V_75 , V_249 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_249 = V_249 ;
V_250 = F_31 ( V_1 , V_251 ) & 0x0f ;
switch ( V_1 -> V_249 )
{
case V_252 : V_250 |= V_253 ; break;
case V_254 : V_250 |= V_255 ; break;
case V_256 : V_250 |= V_257 ; break;
}
F_34 ( V_1 , V_251 , V_250 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_123 ( T_1 * V_1 , int V_258 , struct V_9 * V_10 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_65 , V_1 -> V_75 , V_258 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( V_258 ) {
if ( ! V_1 -> V_76 )
F_40 ( V_1 , V_10 ) ;
} else {
if ( V_1 -> V_76 )
F_37 ( V_1 ) ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_124 ( T_1 * V_1 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_66 , V_1 -> V_75 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_127 && V_1 -> V_131 &&
V_1 -> V_39 . V_129 == V_143 ) {
V_1 -> V_131 = V_1 -> V_132 = V_1 -> V_133 = 0 ;
V_1 -> V_128 = true ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_125 ( T_1 * V_1 , int V_258 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_67 , V_1 -> V_75 , V_258 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( V_258 ) {
if ( ! V_1 -> V_100 )
F_96 ( V_1 ) ;
} else {
if ( V_1 -> V_100 )
F_90 ( V_1 ) ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_126 ( T_1 * V_1 , int T_5 * V_259 )
{
unsigned long V_12 ;
int V_260 ;
int V_77 = 0 ;
struct V_113 V_261 , V_262 ;
int V_263 ;
int V_3 ;
struct V_264 V_265 , V_266 ;
F_127 ( V_267 , V_268 ) ;
F_117 ( V_77 , & V_3 , V_259 , sizeof( int ) ) ;
if ( V_77 )
return - V_245 ;
if ( V_21 >= V_22 )
F_9 ( L_68 , V_1 -> V_75 , V_3 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_57 ( V_1 ) ;
V_260 = V_1 -> V_136 ;
V_263 = V_3 &
( ( ( V_260 & V_167 ) ? V_269 : V_270 ) +
( ( V_260 & V_159 ) ? V_271 : V_272 ) +
( ( V_260 & V_153 ) ? V_273 : V_274 ) +
( ( V_260 & V_172 ) ? V_275 : V_276 ) ) ;
if ( V_263 ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
goto exit;
}
V_261 = V_1 -> V_105 ;
V_265 = V_1 -> V_154 ;
if ( ( V_1 -> V_39 . V_129 == V_143 ) &&
( V_3 & V_277 ) )
F_3 ( V_1 , V_4 , V_189 ) ;
F_128 ( V_278 ) ;
F_129 ( & V_1 -> V_36 , & V_267 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
for(; ; ) {
F_130 () ;
if ( F_131 ( V_268 ) ) {
V_77 = - V_279 ;
break;
}
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_262 = V_1 -> V_105 ;
V_266 = V_1 -> V_154 ;
F_128 ( V_278 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_266 . V_168 == V_265 . V_168 &&
V_266 . V_169 == V_265 . V_169 &&
V_266 . V_160 == V_265 . V_160 &&
V_266 . V_161 == V_265 . V_161 &&
V_266 . V_155 == V_265 . V_155 &&
V_266 . V_156 == V_265 . V_156 &&
V_266 . V_173 == V_265 . V_173 &&
V_266 . V_174 == V_265 . V_174 &&
V_262 . V_190 == V_261 . V_190 &&
V_262 . V_280 == V_261 . V_280 ) {
V_77 = - V_239 ;
break;
}
V_263 = V_3 &
( ( V_266 . V_168 != V_265 . V_168 ? V_269 : 0 ) +
( V_266 . V_169 != V_265 . V_169 ? V_270 : 0 ) +
( V_266 . V_160 != V_265 . V_160 ? V_271 : 0 ) +
( V_266 . V_161 != V_265 . V_161 ? V_272 : 0 ) +
( V_266 . V_155 != V_265 . V_155 ? V_273 : 0 ) +
( V_266 . V_156 != V_265 . V_156 ? V_274 : 0 ) +
( V_266 . V_173 != V_265 . V_173 ? V_275 : 0 ) +
( V_266 . V_174 != V_265 . V_174 ? V_276 : 0 ) +
( V_262 . V_190 != V_261 . V_190 ? V_277 : 0 ) +
( V_262 . V_280 != V_261 . V_280 ? V_281 : 0 ) ) ;
if ( V_263 )
break;
V_261 = V_262 ;
V_265 = V_266 ;
}
F_132 ( & V_1 -> V_36 , & V_267 ) ;
F_128 ( V_282 ) ;
if ( V_3 & V_277 ) {
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( ! F_133 ( & V_1 -> V_36 ) )
F_1 ( V_1 , V_4 , V_189 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
exit:
if ( V_77 == 0 )
F_134 ( V_77 , V_263 , V_259 ) ;
return V_77 ;
}
static int F_135 ( T_1 * V_1 , int V_63 )
{
unsigned long V_12 ;
int V_77 ;
struct V_113 V_261 , V_262 ;
F_127 ( V_267 , V_268 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_261 = V_1 -> V_105 ;
F_129 ( & V_1 -> V_35 , & V_267 ) ;
F_128 ( V_278 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
for(; ; ) {
F_130 () ;
if ( F_131 ( V_268 ) ) {
V_77 = - V_279 ;
break;
}
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_262 = V_1 -> V_105 ;
F_128 ( V_278 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_262 . V_171 == V_261 . V_171 && V_262 . V_166 == V_261 . V_166 &&
V_262 . V_158 == V_261 . V_158 && V_262 . V_152 == V_261 . V_152 ) {
V_77 = - V_239 ;
break;
}
if ( ( V_63 & V_283 && V_262 . V_171 != V_261 . V_171 ) ||
( V_63 & V_284 && V_262 . V_166 != V_261 . V_166 ) ||
( V_63 & V_285 && V_262 . V_158 != V_261 . V_158 ) ||
( V_63 & V_286 && V_262 . V_152 != V_261 . V_152 ) ) {
V_77 = 0 ;
break;
}
V_261 = V_262 ;
}
F_132 ( & V_1 -> V_35 , & V_267 ) ;
F_128 ( V_282 ) ;
return V_77 ;
}
static int F_136 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned int V_287 ;
unsigned long V_12 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_57 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_287 = ( ( V_1 -> V_136 & V_137 ) ? V_288 : 0 ) +
( ( V_1 -> V_136 & V_213 ) ? V_289 : 0 ) +
( ( V_1 -> V_136 & V_159 ) ? V_290 : 0 ) +
( ( V_1 -> V_136 & V_172 ) ? V_283 : 0 ) +
( ( V_1 -> V_136 & V_167 ) ? V_284 : 0 ) +
( ( V_1 -> V_136 & V_153 ) ? V_286 : 0 ) ;
if ( V_21 >= V_22 )
F_9 ( L_69 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_287 ) ;
return V_287 ;
}
static int F_137 ( struct V_9 * V_10 ,
unsigned int V_291 , unsigned int V_292 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_70 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_291 , V_292 ) ;
if ( V_291 & V_288 )
V_1 -> V_136 |= V_137 ;
if ( V_291 & V_289 )
V_1 -> V_136 |= V_213 ;
if ( V_292 & V_288 )
V_1 -> V_136 &= ~ V_137 ;
if ( V_292 & V_289 )
V_1 -> V_136 &= ~ V_213 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_58 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_138 ( struct V_9 * V_10 , int V_293 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_71 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_293 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_72 ) )
return - V_294 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( V_293 == - 1 )
F_139 ( V_1 , V_4 + V_295 , V_118 ) ;
else
F_140 ( V_1 , V_4 + V_295 , V_118 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_141 ( struct V_9 * V_10 ,
struct V_296 * V_105 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
struct V_113 V_262 ;
unsigned long V_12 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_262 = V_1 -> V_105 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_105 -> V_152 = V_262 . V_152 ;
V_105 -> V_166 = V_262 . V_166 ;
V_105 -> V_171 = V_262 . V_171 ;
V_105 -> V_158 = V_262 . V_158 ;
V_105 -> V_115 = V_262 . V_115 ;
V_105 -> V_297 = V_262 . V_297 ;
V_105 -> V_120 = V_262 . V_120 ;
V_105 -> V_126 = V_262 . V_126 ;
V_105 -> V_119 = V_262 . V_119 ;
V_105 -> V_125 = V_262 . V_125 ;
V_105 -> V_106 = V_262 . V_106 ;
return 0 ;
}
static int F_142 ( struct V_9 * V_10 ,
unsigned int V_72 , unsigned long V_63 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
void T_5 * V_298 = ( void T_5 * ) V_63 ;
if ( V_21 >= V_22 )
F_9 ( L_73 , __FILE__ , __LINE__ ,
V_1 -> V_75 , V_72 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_74 ) )
return - V_62 ;
if ( ( V_72 != V_299 ) && ( V_72 != V_300 ) &&
( V_72 != V_301 ) ) {
if ( V_10 -> V_12 & ( 1 << V_209 ) )
return - V_239 ;
}
switch ( V_72 ) {
case V_302 :
return F_115 ( V_1 , V_298 ) ;
case V_303 :
return F_116 ( V_1 , V_298 , V_10 ) ;
case V_304 :
return F_118 ( V_1 , V_298 ) ;
case V_305 :
return F_119 ( V_1 , ( int ) V_63 ) ;
case V_306 :
return F_121 ( V_1 , V_298 ) ;
case V_307 :
return F_122 ( V_1 , ( int ) V_63 ) ;
case V_308 :
return F_123 ( V_1 , ( int ) V_63 , V_10 ) ;
case V_309 :
return F_125 ( V_1 , ( int ) V_63 ) ;
case V_310 :
return F_124 ( V_1 ) ;
case V_311 :
return F_113 ( V_1 , V_298 ) ;
case V_312 :
return F_126 ( V_1 , V_298 ) ;
case V_301 :
return F_135 ( V_1 , ( int ) V_63 ) ;
default:
return - V_313 ;
}
return 0 ;
}
static void F_143 ( struct V_9 * V_10 , struct V_314 * V_315 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_75 , __FILE__ , __LINE__ ,
V_10 -> V_316 -> V_65 ) ;
if ( ( V_10 -> V_210 . V_211 == V_315 -> V_211 )
&& ( F_144 ( V_10 -> V_210 . V_317 )
== F_144 ( V_315 -> V_317 ) ) )
return;
F_85 ( V_1 , V_10 ) ;
if ( V_315 -> V_211 & V_217 &&
! ( V_10 -> V_210 . V_211 & V_217 ) ) {
V_1 -> V_136 &= ~ ( V_137 + V_213 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_58 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
if ( ! ( V_315 -> V_211 & V_217 ) &&
V_10 -> V_210 . V_211 & V_217 ) {
V_1 -> V_136 |= V_213 ;
if ( ! ( V_10 -> V_210 . V_211 & V_234 ) ||
! F_145 ( V_318 , & V_10 -> V_12 ) ) {
V_1 -> V_136 |= V_137 ;
}
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_58 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
if ( V_315 -> V_211 & V_234 &&
! ( V_10 -> V_210 . V_211 & V_234 ) ) {
V_10 -> V_141 = 0 ;
F_39 ( V_10 ) ;
}
}
static void F_146 ( struct V_9 * V_10 , struct V_319 * V_320 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
struct V_321 * V_27 = & V_1 -> V_27 ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_76 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_77 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_27 -> V_13 ) ;
F_147 ( ! V_27 -> V_13 ) ;
if ( F_148 ( V_27 , V_10 , V_320 ) == 0 )
goto V_238;
if ( V_27 -> V_12 & V_205 )
F_149 ( V_10 , V_1 -> V_233 ) ;
F_106 ( V_10 ) ;
F_150 ( V_10 ) ;
F_87 ( V_1 , V_10 ) ;
F_151 ( V_27 , V_10 ) ;
F_152 ( V_27 , NULL ) ;
V_238:
if ( V_21 >= V_22 )
F_9 ( L_78 , __FILE__ , __LINE__ ,
V_10 -> V_316 -> V_65 , V_27 -> V_13 ) ;
}
static void F_149 ( struct V_9 * V_10 , int V_233 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
unsigned long V_322 , V_323 ;
if ( ! V_1 )
return;
if ( V_21 >= V_22 )
F_9 ( L_79 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_80 ) )
return;
if ( ! ( V_1 -> V_27 . V_12 & V_205 ) )
goto exit;
V_322 = V_324 ;
if ( V_1 -> V_39 . V_232 ) {
V_323 = V_1 -> V_233 / ( 32 * 5 ) ;
if ( ! V_323 )
V_323 ++ ;
} else
V_323 = 1 ;
if ( V_233 )
V_323 = F_62 (unsigned long, char_time, timeout) ;
if ( V_1 -> V_39 . V_129 == V_143 ) {
while ( V_1 -> V_127 ) {
F_153 ( F_154 ( V_323 ) ) ;
if ( F_131 ( V_268 ) )
break;
if ( V_233 && F_155 ( V_324 , V_322 + V_233 ) )
break;
}
} else {
while ( ( V_1 -> V_131 || V_1 -> V_127 ) &&
V_1 -> V_76 ) {
F_153 ( F_154 ( V_323 ) ) ;
if ( F_131 ( V_268 ) )
break;
if ( V_233 && F_155 ( V_324 , V_322 + V_233 ) )
break;
}
}
exit:
if ( V_21 >= V_22 )
F_9 ( L_81 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_74 ;
if ( V_21 >= V_22 )
F_9 ( L_82 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_83 ) )
return;
F_106 ( V_10 ) ;
F_87 ( V_1 , V_10 ) ;
F_157 ( & V_1 -> V_27 ) ;
}
static int F_158 ( struct V_321 * V_27 )
{
T_1 * V_1 = F_42 ( V_27 , T_1 , V_27 ) ;
unsigned long V_12 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_57 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_136 & V_159 )
return 1 ;
return 0 ;
}
static void F_159 ( struct V_321 * V_27 , int V_325 )
{
T_1 * V_1 = F_42 ( V_27 , T_1 , V_27 ) ;
unsigned long V_12 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( V_325 )
V_1 -> V_136 |= V_137 + V_213 ;
else
V_1 -> V_136 &= ~ V_137 + V_213 ;
F_58 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
}
static int F_160 ( struct V_9 * V_10 , struct V_319 * V_320 )
{
T_1 * V_1 ;
struct V_321 * V_27 ;
int V_204 , line ;
unsigned long V_12 ;
line = V_10 -> V_326 ;
if ( line >= V_327 ) {
F_9 ( L_84 ,
__FILE__ , __LINE__ , line ) ;
return - V_62 ;
}
V_1 = V_328 ;
while( V_1 && V_1 -> line != line )
V_1 = V_1 -> V_329 ;
if ( F_28 ( V_1 , V_10 -> V_65 , L_85 ) )
return - V_62 ;
V_27 = & V_1 -> V_27 ;
V_10 -> V_74 = V_1 ;
F_152 ( V_27 , V_10 ) ;
if ( V_21 >= V_22 )
F_9 ( L_86 ,
__FILE__ , __LINE__ , V_10 -> V_316 -> V_65 , V_27 -> V_13 ) ;
if ( F_161 ( V_320 ) || V_27 -> V_12 & V_330 ) {
if ( V_27 -> V_12 & V_330 )
F_162 ( & V_27 -> V_331 ) ;
V_204 = ( ( V_27 -> V_12 & V_332 ) ?
- V_333 : - V_279 ) ;
goto V_238;
}
V_10 -> V_334 = ( V_27 -> V_12 & V_335 ) ? 1 : 0 ;
F_36 ( & V_1 -> V_38 , V_12 ) ;
if ( V_1 -> V_139 ) {
V_204 = - V_336 ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
goto V_238;
}
F_73 ( & V_27 -> V_37 ) ;
V_27 -> V_13 ++ ;
F_76 ( & V_27 -> V_37 ) ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
if ( V_27 -> V_13 == 1 ) {
V_204 = F_77 ( V_1 , V_10 ) ;
if ( V_204 < 0 )
goto V_238;
}
V_204 = F_163 ( & V_1 -> V_27 , V_10 , V_320 ) ;
if ( V_204 ) {
if ( V_21 >= V_22 )
F_9 ( L_87 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_204 ) ;
goto V_238;
}
if ( V_21 >= V_22 )
F_9 ( L_88 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
V_204 = 0 ;
V_238:
return V_204 ;
}
static inline void F_164 ( struct V_337 * V_338 , T_1 * V_1 )
{
char V_339 [ 30 ] ;
unsigned long V_12 ;
F_165 ( V_338 , L_89 ,
V_1 -> V_75 , V_1 -> V_56 , V_1 -> V_59 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_57 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_339 [ 0 ] = 0 ;
V_339 [ 1 ] = 0 ;
if ( V_1 -> V_136 & V_137 )
strcat ( V_339 , L_90 ) ;
if ( V_1 -> V_136 & V_153 )
strcat ( V_339 , L_91 ) ;
if ( V_1 -> V_136 & V_213 )
strcat ( V_339 , L_92 ) ;
if ( V_1 -> V_136 & V_167 )
strcat ( V_339 , L_93 ) ;
if ( V_1 -> V_136 & V_159 )
strcat ( V_339 , L_94 ) ;
if ( V_1 -> V_136 & V_172 )
strcat ( V_339 , L_95 ) ;
if ( V_1 -> V_39 . V_129 == V_143 ) {
F_165 ( V_338 , L_96 ,
V_1 -> V_105 . V_201 , V_1 -> V_105 . V_340 ) ;
if ( V_1 -> V_105 . V_199 )
F_165 ( V_338 , L_97 , V_1 -> V_105 . V_199 ) ;
if ( V_1 -> V_105 . V_198 )
F_165 ( V_338 , L_98 , V_1 -> V_105 . V_198 ) ;
if ( V_1 -> V_105 . V_341 )
F_165 ( V_338 , L_99 , V_1 -> V_105 . V_341 ) ;
if ( V_1 -> V_105 . V_342 )
F_165 ( V_338 , L_100 , V_1 -> V_105 . V_342 ) ;
if ( V_1 -> V_105 . V_343 )
F_165 ( V_338 , L_101 , V_1 -> V_105 . V_343 ) ;
if ( V_1 -> V_105 . V_344 )
F_165 ( V_338 , L_102 , V_1 -> V_105 . V_344 ) ;
} else {
F_165 ( V_338 , L_103 ,
V_1 -> V_105 . V_297 , V_1 -> V_105 . V_115 ) ;
if ( V_1 -> V_105 . V_120 )
F_165 ( V_338 , L_104 , V_1 -> V_105 . V_120 ) ;
if ( V_1 -> V_105 . V_119 )
F_165 ( V_338 , L_105 , V_1 -> V_105 . V_119 ) ;
if ( V_1 -> V_105 . V_125 )
F_165 ( V_338 , L_106 , V_1 -> V_105 . V_125 ) ;
if ( V_1 -> V_105 . V_126 )
F_165 ( V_338 , L_107 , V_1 -> V_105 . V_126 ) ;
}
F_165 ( V_338 , L_108 , V_339 + 1 ) ;
F_165 ( V_338 , L_109 ,
V_1 -> V_127 , V_1 -> V_83 , V_1 -> V_82 ,
V_1 -> V_78 ) ;
}
static int F_166 ( struct V_337 * V_338 , void * V_345 )
{
T_1 * V_1 ;
F_165 ( V_338 , L_110 , V_346 ) ;
V_1 = V_328 ;
while( V_1 ) {
F_164 ( V_338 , V_1 ) ;
V_1 = V_1 -> V_329 ;
}
return 0 ;
}
static int F_167 ( struct V_347 * V_347 , struct V_319 * V_319 )
{
return F_168 ( V_319 , F_166 , NULL ) ;
}
static int F_169 ( T_1 * V_1 )
{
V_1 -> V_98 = sizeof( T_3 ) + V_1 -> V_31 ;
V_1 -> V_348 = V_1 -> V_98 * 8 ;
if ( V_1 -> V_348 > 0x10000 )
V_1 -> V_348 = 0x10000 ;
V_1 -> V_102 = V_1 -> V_348 / V_1 -> V_98 ;
V_1 -> V_96 = F_170 ( V_1 -> V_348 , V_23 ) ;
if ( V_1 -> V_96 == NULL )
return - V_24 ;
F_171 ( V_1 ) ;
return 0 ;
}
static void F_172 ( T_1 * V_1 )
{
F_173 ( V_1 -> V_96 ) ;
V_1 -> V_96 = NULL ;
}
static int F_80 ( T_1 * V_1 )
{
if ( F_169 ( V_1 ) < 0 ) {
F_9 ( L_111 , V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
return - V_62 ;
}
return 0 ;
}
static void F_84 ( T_1 * V_1 )
{
if ( V_21 >= V_22 )
F_9 ( L_112 , V_1 -> V_75 ) ;
F_172 ( V_1 ) ;
}
static void F_16 ( T_1 * V_1 )
{
V_1 -> V_329 = NULL ;
V_1 -> line = V_327 ;
sprintf ( V_1 -> V_75 , L_113 , V_1 -> line ) ;
if ( V_1 -> line < V_349 ) {
if ( V_350 [ V_1 -> line ] )
V_1 -> V_31 = V_350 [ V_1 -> line ] ;
}
V_327 ++ ;
if ( ! V_328 )
V_328 = V_1 ;
else {
T_1 * V_351 = V_328 ;
while( V_351 -> V_329 )
V_351 = V_351 -> V_329 ;
V_351 -> V_329 = V_1 ;
}
if ( V_1 -> V_31 < 4096 )
V_1 -> V_31 = 4096 ;
else if ( V_1 -> V_31 > 65535 )
V_1 -> V_31 = 65535 ;
F_9 ( L_114 ,
V_1 -> V_75 , V_1 -> V_56 , V_1 -> V_59 ) ;
#if V_138
F_174 ( V_1 ) ;
#endif
F_175 ( & V_1 -> V_27 , V_352 , V_1 -> line ,
& V_1 -> V_45 -> V_353 ) ;
}
static void F_25 ( T_1 * V_354 )
{
T_1 * V_1 = V_328 ;
T_1 * V_355 = NULL ;
while( V_1 ) {
if ( V_1 == V_354 ) {
if ( V_355 )
V_355 -> V_329 = V_1 -> V_329 ;
else
V_328 = V_1 -> V_329 ;
F_176 ( V_352 , V_1 -> line ) ;
#if V_138
F_177 ( V_1 ) ;
#endif
F_84 ( V_1 ) ;
F_173 ( V_1 ) ;
V_327 -- ;
return;
}
V_355 = V_1 ;
V_1 = V_1 -> V_329 ;
}
}
static int T_6 F_178 ( void )
{
int V_77 ;
if ( V_356 ) {
F_4 () ;
F_179 () ;
}
V_352 = F_180 ( V_349 ,
V_357 |
V_358 ) ;
if ( F_181 ( V_352 ) ) {
V_77 = F_182 ( V_352 ) ;
goto V_244;
}
V_352 -> V_359 = L_115 ;
V_352 -> V_65 = L_116 ;
V_352 -> V_360 = V_361 ;
V_352 -> V_362 = 64 ;
V_352 -> type = V_363 ;
V_352 -> V_364 = V_365 ;
V_352 -> V_366 = V_367 ;
V_352 -> V_366 . V_211 =
V_368 | V_223 | V_214 | V_212 | V_236 ;
F_183 ( V_352 , & V_369 ) ;
V_77 = F_184 ( V_352 ) ;
if ( V_77 < 0 ) {
F_9 ( V_206 L_117 ,
__FILE__ , __LINE__ ) ;
goto V_370;
}
V_77 = F_185 ( & V_371 ) ;
if ( V_77 < 0 )
goto V_372;
F_9 ( V_373 L_118 , V_359 , V_346 ,
V_352 -> V_360 ) ;
return 0 ;
V_372:
F_186 ( V_352 ) ;
V_370:
F_187 ( V_352 ) ;
V_244:
return V_77 ;
}
static void T_7 F_188 ( void )
{
F_189 ( & V_371 ) ;
F_186 ( V_352 ) ;
F_187 ( V_352 ) ;
}
static void F_190 ( T_1 * V_1 , unsigned char V_2 , unsigned int V_374 )
{
unsigned int V_375 , V_376 ;
unsigned char V_250 ;
if ( V_374 ) {
V_376 = 3686400 / V_374 ;
if ( ! V_376 )
V_376 = 1 ;
V_376 >>= 1 ;
for ( V_375 = 1 ; V_376 > 64 && V_375 < 16 ; V_375 ++ )
V_376 >>= 1 ;
V_376 -- ;
F_34 ( V_1 , ( unsigned char ) ( V_2 + V_377 ) ,
( unsigned char ) ( ( V_375 << 6 ) + V_376 ) ) ;
V_250 = F_31 ( V_1 , ( unsigned char ) ( V_2 + V_378 ) ) & 0x3f ;
V_250 |= ( ( V_375 << 4 ) & 0xc0 ) ;
F_34 ( V_1 , ( unsigned char ) ( V_2 + V_378 ) , V_250 ) ;
}
}
static void F_191 ( T_1 * V_1 )
{
unsigned char V_250 ;
V_250 = 0x82 ;
if ( V_1 -> V_39 . V_129 == V_143 && V_1 -> V_39 . V_379 )
V_250 |= V_71 ;
F_34 ( V_1 , V_8 + V_380 , V_250 ) ;
F_34 ( V_1 , V_8 + V_381 , 0xc0 ) ;
F_34 ( V_1 , V_8 + V_382 , 0x17 ) ;
if ( V_1 -> V_39 . V_129 == V_143 && V_1 -> V_39 . V_379 )
F_34 ( V_1 , V_8 + V_378 , 0x38 ) ;
else
F_34 ( V_1 , V_8 + V_378 , 0x30 ) ;
F_34 ( V_1 , V_8 + V_383 , 0x50 ) ;
if ( V_1 -> V_39 . V_129 == V_143 && V_1 -> V_39 . V_379 )
F_190 ( V_1 , V_8 , V_1 -> V_39 . V_379 ) ;
else
F_190 ( V_1 , V_8 , 921600 ) ;
}
static void F_192 ( T_1 * V_1 )
{
unsigned char V_250 ;
V_250 = F_31 ( V_1 , V_4 + V_382 ) | ( V_71 + V_183 + V_184 ) ;
F_34 ( V_1 , V_4 + V_382 , V_250 ) ;
V_250 = F_31 ( V_1 , V_4 + V_378 ) | ( V_384 + V_114 ) ;
F_34 ( V_1 , V_4 + V_378 , V_250 ) ;
if ( V_1 -> V_39 . V_379 )
F_190 ( V_1 , V_4 , V_1 -> V_39 . V_379 ) ;
else
F_190 ( V_1 , V_4 , 1843200 ) ;
V_250 = F_31 ( V_1 , V_4 + V_380 ) | V_184 ;
F_34 ( V_1 , V_4 + V_380 , V_250 ) ;
}
static void F_93 ( T_1 * V_1 )
{
unsigned char V_250 ;
unsigned char V_385 , V_386 ;
F_1 ( V_1 , V_4 , 0xffff ) ;
F_1 ( V_1 , V_8 , 0xffff ) ;
F_71 ( V_1 , 0xff ) ;
V_385 = V_386 = 0 ;
if ( V_1 -> V_39 . V_12 & V_387
&& V_1 -> V_39 . V_12 & V_388 ) {
V_385 = 7 ;
} else if ( V_1 -> V_39 . V_12 & V_389
&& V_1 -> V_39 . V_12 & V_390 ) {
V_385 = 7 ;
V_386 = 1 ;
} else if ( V_1 -> V_39 . V_12 & V_387 ) {
if ( V_1 -> V_39 . V_12 & V_390 ) {
V_385 = 6 ;
V_386 = 1 ;
} else {
V_385 = 6 ;
}
} else if ( V_1 -> V_39 . V_12 & V_390 ) {
V_386 = 1 ;
}
V_250 = 0x82 ;
if ( V_1 -> V_39 . V_391 )
V_250 |= V_184 ;
if ( V_1 -> V_136 & V_137 )
V_250 |= V_71 ;
F_34 ( V_1 , V_4 + V_380 , V_250 ) ;
V_250 = 0xc0 ;
switch ( V_1 -> V_39 . V_392 )
{
case V_393 :
V_250 |= V_186 ;
break;
case V_394 :
V_250 |= V_384 ;
break;
case V_395 :
V_250 |= V_384 + V_71 ;
break;
case V_396 :
V_250 |= V_384 + V_186 ;
break;
}
F_34 ( V_1 , V_4 + V_381 , V_250 ) ;
V_250 = 0x10 + V_385 ;
F_34 ( V_1 , V_4 + V_382 , V_250 ) ;
V_250 = 0x00 ;
if ( V_385 == 2 || V_385 == 3 || V_385 == 6
|| V_385 == 7 || ( V_385 == 0 && V_386 == 1 ) )
V_250 |= V_114 ;
if ( V_386 )
V_250 |= V_384 ;
if ( V_1 -> V_39 . V_397 == V_398 )
V_250 |= V_183 ;
if ( V_1 -> V_39 . V_392 == V_399 )
V_250 |= V_184 ;
F_34 ( V_1 , V_4 + V_378 , V_250 ) ;
V_250 = 0x00 ;
if ( V_1 -> V_39 . V_397 == V_400 )
V_250 |= V_71 + V_183 ;
if ( V_1 -> V_39 . V_401 != V_402 )
V_250 |= V_114 ;
switch ( V_1 -> V_39 . V_403 )
{
case V_404 :
V_250 |= V_118 ;
break;
case V_405 :
V_250 |= V_118 ;
break;
case V_406 :
V_250 |= V_117 + V_118 ;
break;
}
F_34 ( V_1 , V_4 + V_407 , V_250 ) ;
V_250 = 0 ;
switch ( V_1 -> V_39 . V_401 )
{
case V_408 : V_250 = 0x7e ; break;
case V_409 : V_250 = 0xaa ; break;
case V_410 : V_250 = 0x55 ; break;
case V_411 : V_250 = 0xff ; break;
}
F_34 ( V_1 , V_4 + V_412 , V_250 ) ;
V_250 = 0x50 ;
F_34 ( V_1 , V_4 + V_383 , V_250 ) ;
if ( V_1 -> V_39 . V_12 & V_387 )
F_190 ( V_1 , V_4 , V_1 -> V_39 . V_379 * 16 ) ;
else
F_190 ( V_1 , V_4 , V_1 -> V_39 . V_379 ) ;
F_34 ( V_1 , V_4 + V_413 , 0 ) ;
V_250 = 0x00 ;
if ( V_1 -> V_39 . V_12 & V_414 )
V_250 |= V_114 ;
F_34 ( V_1 , V_4 + V_415 , V_250 ) ;
F_191 ( V_1 ) ;
if ( V_1 -> V_39 . V_391 || V_1 -> V_416 )
F_192 ( V_1 ) ;
if ( V_1 -> V_39 . V_12 & V_417 )
{
F_3 ( V_1 , V_8 , V_151 ) ;
F_139 ( V_1 , V_4 + V_251 , V_186 ) ;
} else
F_140 ( V_1 , V_4 + V_251 , V_186 ) ;
F_3 ( V_1 , V_4 ,
V_195 + V_196 + V_200 +
V_197 + V_202 ) ;
F_33 ( V_1 , V_4 , V_418 + V_103 ) ;
F_30 ( V_1 , V_4 ) ;
F_50 ( V_1 , V_4 + V_185 ) ;
if ( ! V_1 -> V_416 )
F_140 ( V_1 , V_4 + V_381 , V_118 ) ;
F_120 ( V_1 ) ;
F_37 ( V_1 ) ;
F_90 ( V_1 ) ;
}
static void F_90 ( T_1 * V_1 )
{
if ( V_21 >= V_99 )
F_9 ( L_119 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
F_140 ( V_1 , V_4 + V_380 , V_186 ) ;
V_1 -> V_100 = false ;
V_1 -> V_104 = false ;
}
static void F_96 ( T_1 * V_1 )
{
if ( V_21 >= V_99 )
F_9 ( L_120 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
F_171 ( V_1 ) ;
V_1 -> V_100 = false ;
V_1 -> V_104 = false ;
F_139 ( V_1 , V_4 + V_380 , V_186 ) ;
V_1 -> V_100 = true ;
}
static void F_40 ( T_1 * V_1 , struct V_9 * V_10 )
{
if ( V_21 >= V_99 )
F_9 ( L_121 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
if ( V_1 -> V_131 ) {
V_1 -> V_135 = false ;
if ( V_1 -> V_39 . V_12 & V_419 ) {
F_57 ( V_1 ) ;
if ( ! ( V_1 -> V_136 & V_137 ) ) {
V_1 -> V_136 |= V_137 ;
F_58 ( V_1 ) ;
V_1 -> V_135 = true ;
}
}
if ( V_1 -> V_39 . V_129 == V_130 ) {
if ( ! V_1 -> V_127 ) {
V_1 -> V_127 = true ;
F_60 ( V_1 , V_10 ) ;
}
} else {
V_1 -> V_127 = true ;
F_60 ( V_1 , V_10 ) ;
F_193 ( & V_1 -> V_134 , V_324 +
F_194 ( 5000 ) ) ;
}
}
if ( ! V_1 -> V_76 )
V_1 -> V_76 = true ;
}
static void F_37 ( T_1 * V_1 )
{
if ( V_21 >= V_99 )
F_9 ( L_122 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
F_56 ( & V_1 -> V_134 ) ;
V_1 -> V_76 = false ;
V_1 -> V_127 = false ;
}
static void F_91 ( T_1 * V_1 )
{
F_34 ( V_1 , V_4 + V_381 , 0x80 ) ;
F_34 ( V_1 , V_8 + V_381 , 0x80 ) ;
F_34 ( V_1 , V_4 + V_380 , 0 ) ;
F_34 ( V_1 , V_8 + V_380 , 0 ) ;
F_1 ( V_1 , V_4 , 0xffff ) ;
F_1 ( V_1 , V_8 , 0xffff ) ;
F_71 ( V_1 , 0xff ) ;
F_34 ( V_1 , V_420 , 0x06 ) ;
F_34 ( V_1 , V_421 , 0x05 ) ;
}
static void F_94 ( T_1 * V_1 )
{
unsigned char V_250 ;
F_1 ( V_1 , V_4 , 0xffff ) ;
F_1 ( V_1 , V_8 , 0xffff ) ;
F_71 ( V_1 , 0xff ) ;
V_250 = 0x06 ;
if ( V_1 -> V_39 . V_391 )
V_250 |= V_184 ;
if ( ! ( V_1 -> V_136 & V_137 ) )
V_250 |= V_118 ;
F_34 ( V_1 , V_4 + V_380 , V_250 ) ;
F_34 ( V_1 , V_4 + V_381 , 0x83 ) ;
F_34 ( V_1 , V_4 + V_382 , 0x1f ) ;
F_34 ( V_1 , V_4 + V_378 , 0x10 ) ;
F_34 ( V_1 , V_4 + V_407 , 0 ) ;
F_34 ( V_1 , V_4 + V_383 , 0x50 ) ;
F_190 ( V_1 , V_4 , V_1 -> V_39 . V_232 * 16 ) ;
V_250 = 0x00 ;
if ( V_1 -> V_39 . V_220 != 8 )
V_250 |= V_184 ;
if ( V_1 -> V_39 . V_225 != 1 )
V_250 |= V_114 ;
if ( V_1 -> V_39 . V_119 != V_226 )
{
V_250 |= V_71 ;
if ( V_1 -> V_39 . V_119 == V_229 )
V_250 |= V_186 ;
else
V_250 |= V_384 ;
}
F_34 ( V_1 , V_4 + V_295 , V_250 ) ;
F_34 ( V_1 , V_4 + V_422 , 0x5c ) ;
F_34 ( V_1 , V_4 + V_413 , 0 ) ;
V_250 = 0x00 ;
if ( V_1 -> V_39 . V_12 & V_414 )
V_250 |= V_114 ;
F_34 ( V_1 , V_4 + V_415 , V_250 ) ;
if ( V_1 -> V_39 . V_12 & V_417 )
F_3 ( V_1 , V_4 , V_151 ) ;
F_139 ( V_1 , V_4 + V_380 , V_186 ) ;
F_191 ( V_1 ) ;
if ( V_1 -> V_39 . V_12 & V_417 ) {
F_3 ( V_1 , V_8 , V_151 ) ;
F_139 ( V_1 , V_4 + V_251 , V_186 ) ;
} else
F_140 ( V_1 , V_4 + V_251 , V_186 ) ;
F_3 ( V_1 , V_4 ,
V_195 + V_196 + V_191 + V_193 +
V_200 + V_202 ) ;
F_33 ( V_1 , V_4 , V_418 + V_103 ) ;
F_30 ( V_1 , V_4 ) ;
F_50 ( V_1 , V_4 + V_185 ) ;
}
static void F_120 ( T_1 * V_1 )
{
if ( V_1 -> V_42 == V_43 )
F_139 ( V_1 , V_4 + V_382 , V_186 ) ;
else
F_140 ( V_1 , V_4 + V_382 , V_186 ) ;
}
static void F_57 ( T_1 * V_1 )
{
unsigned char V_109 = 0 ;
V_1 -> V_136 &= V_213 + V_137 ;
if ( F_31 ( V_1 , V_8 + V_423 ) & V_117 )
V_1 -> V_136 |= V_159 ;
if ( F_31 ( V_1 , V_8 + V_70 ) & V_183 )
V_1 -> V_136 |= V_153 ;
V_109 = F_31 ( V_1 , V_4 + V_251 ) ;
if ( ! ( V_109 & V_170 ) )
V_1 -> V_136 |= V_172 ;
if ( ! ( V_109 & V_165 ) )
V_1 -> V_136 |= V_167 ;
}
static void F_58 ( T_1 * V_1 )
{
unsigned char V_250 ;
V_250 = F_31 ( V_1 , V_4 + V_380 ) ;
if ( V_1 -> V_39 . V_129 == V_130 ) {
if ( V_1 -> V_136 & V_137 )
V_250 &= ~ V_118 ;
else
V_250 |= V_118 ;
} else {
if ( V_1 -> V_136 & V_137 )
V_250 |= V_71 ;
else
V_250 &= ~ V_71 ;
}
F_34 ( V_1 , V_4 + V_380 , V_250 ) ;
if ( V_1 -> V_136 & V_213 )
F_140 ( V_1 , V_4 + V_251 , V_424 ) ;
else
F_139 ( V_1 , V_4 + V_251 , V_424 ) ;
}
static void F_171 ( T_1 * V_1 )
{
T_3 * V_95 ;
int V_69 ;
V_1 -> V_97 = 0 ;
V_1 -> V_425 = 0 ;
V_1 -> V_101 = 0 ;
for ( V_69 = 0 ; V_69 < V_1 -> V_102 ; V_69 ++ ) {
V_95 = ( T_3 * ) ( V_1 -> V_96 + ( V_69 * V_1 -> V_98 ) ) ;
V_95 -> V_109 = V_95 -> V_13 = 0 ;
}
}
static bool F_44 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned short V_109 ;
T_3 * V_95 ;
unsigned int V_426 = 0 ;
unsigned long V_12 ;
bool V_427 = false ;
if ( V_1 -> V_101 == 0 )
return false ;
V_95 = ( T_3 * ) ( V_1 -> V_96 + ( V_1 -> V_425 * V_1 -> V_98 ) ) ;
V_109 = V_95 -> V_109 ;
if ( ( V_109 & 0xf0 ) != 0xA0 ) {
if ( ! ( V_109 & V_117 ) || ( V_109 & V_384 ) )
V_1 -> V_105 . V_428 ++ ;
else if ( V_109 & V_118 )
V_1 -> V_105 . V_343 ++ ;
else if ( ! ( V_109 & V_114 ) ) {
V_1 -> V_105 . V_344 ++ ;
if ( V_1 -> V_39 . V_397 & V_429 )
V_427 = true ;
}
V_426 = 0 ;
#if V_138
{
V_1 -> V_162 -> V_430 . V_431 ++ ;
V_1 -> V_162 -> V_430 . V_432 ++ ;
}
#endif
} else
V_427 = true ;
if ( V_427 )
V_426 = V_95 -> V_13 ;
if ( V_21 >= V_87 )
F_9 ( L_123 ,
__FILE__ , __LINE__ , V_1 -> V_75 , V_109 , V_426 ) ;
if ( V_21 >= V_433 )
F_195 ( V_1 , V_95 -> V_11 , V_426 , 0 ) ;
if ( V_426 ) {
if ( ( V_1 -> V_39 . V_397 & V_429 &&
V_426 + 1 > V_1 -> V_31 ) ||
V_426 > V_1 -> V_31 )
V_1 -> V_105 . V_342 ++ ;
else {
if ( V_109 & V_114 )
V_1 -> V_105 . V_340 ++ ;
if ( V_1 -> V_39 . V_397 & V_429 ) {
* ( V_95 -> V_11 + V_426 ) = V_109 & V_114 ? V_434 : V_435 ;
++ V_426 ;
}
#if V_138
if ( V_1 -> V_139 )
F_196 ( V_1 , V_95 -> V_11 , V_426 ) ;
else
#endif
F_5 ( V_10 , V_95 -> V_11 , V_1 -> V_436 , V_426 ) ;
}
}
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_95 -> V_109 = V_95 -> V_13 = 0 ;
V_1 -> V_101 -- ;
V_1 -> V_425 ++ ;
if ( V_1 -> V_425 >= V_1 -> V_102 )
V_1 -> V_425 = 0 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
return true ;
}
static bool F_197 ( T_1 * V_1 )
{
static unsigned char V_437 [] =
{ 0x00 , 0xff , 0xaa , 0x55 , 0x69 , 0x96 , 0x0f } ;
static unsigned int V_13 = F_198 ( V_437 ) ;
unsigned int V_69 ;
bool V_77 = true ;
unsigned long V_12 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_91 ( V_1 ) ;
for ( V_69 = 0 ; V_69 < V_13 ; V_69 ++ ) {
F_34 ( V_1 , V_438 , V_437 [ V_69 ] ) ;
F_34 ( V_1 , V_439 , V_437 [ ( V_69 + 1 ) % V_13 ] ) ;
if ( ( F_31 ( V_1 , V_438 ) != V_437 [ V_69 ] ) ||
( F_31 ( V_1 , V_439 ) != V_437 [ ( V_69 + 1 ) % V_13 ] ) ) {
V_77 = false ;
break;
}
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
return V_77 ;
}
static bool F_199 ( T_1 * V_1 )
{
unsigned long V_440 ;
unsigned long V_12 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_91 ( V_1 ) ;
V_1 -> V_416 = true ;
F_93 ( V_1 ) ;
V_1 -> V_188 = false ;
F_3 ( V_1 , V_4 , V_187 ) ;
F_34 ( V_1 , V_4 + V_441 , 0 ) ;
F_33 ( V_1 , V_4 , V_442 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_440 = 100 ;
while( V_440 -- && ! V_1 -> V_188 ) {
F_153 ( 10 ) ;
}
V_1 -> V_416 = false ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_91 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
return V_1 -> V_188 ;
}
static int F_81 ( T_1 * V_1 )
{
if ( ! F_197 ( V_1 ) ) {
V_1 -> V_443 = V_444 ;
F_9 ( L_124 ,
__FILE__ , __LINE__ , V_1 -> V_75 , ( unsigned short ) ( V_1 -> V_56 ) ) ;
return - V_62 ;
}
if ( ! F_199 ( V_1 ) ) {
V_1 -> V_443 = V_445 ;
F_9 ( L_125 ,
__FILE__ , __LINE__ , V_1 -> V_75 , ( unsigned short ) ( V_1 -> V_59 ) ) ;
return - V_62 ;
}
if ( V_21 >= V_22 )
F_9 ( L_126 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
return 0 ;
}
static void F_195 ( T_1 * V_1 , const char * V_11 , int V_13 , int V_446 )
{
int V_69 ;
int V_447 ;
if ( V_446 )
F_9 ( L_127 , V_1 -> V_75 ) ;
else
F_9 ( L_128 , V_1 -> V_75 ) ;
while( V_13 ) {
if ( V_13 > 16 )
V_447 = 16 ;
else
V_447 = V_13 ;
for( V_69 = 0 ; V_69 < V_447 ; V_69 ++ )
F_9 ( L_129 , ( unsigned char ) V_11 [ V_69 ] ) ;
for(; V_69 < 17 ; V_69 ++ )
F_9 ( L_130 ) ;
for( V_69 = 0 ; V_69 < V_447 ; V_69 ++ ) {
if ( V_11 [ V_69 ] >= 040 && V_11 [ V_69 ] <= 0176 )
F_9 ( L_131 , V_11 [ V_69 ] ) ;
else
F_9 ( L_132 ) ;
}
F_9 ( L_133 ) ;
V_11 += V_447 ;
V_13 -= V_447 ;
}
}
static void V_207 ( unsigned long V_448 )
{
T_1 * V_1 = ( T_1 * ) V_448 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_134 ,
__FILE__ , __LINE__ , V_1 -> V_75 ) ;
if( V_1 -> V_127 &&
V_1 -> V_39 . V_129 == V_143 ) {
V_1 -> V_105 . V_449 ++ ;
}
F_36 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_127 = false ;
V_1 -> V_131 = V_1 -> V_132 = V_1 -> V_133 = 0 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
#if V_138
if ( V_1 -> V_139 )
F_59 ( V_1 ) ;
else
#endif
{
struct V_9 * V_10 = F_43 ( & V_1 -> V_27 ) ;
F_45 ( V_1 , V_10 ) ;
F_47 ( V_10 ) ;
}
}
static int F_200 ( struct V_450 * V_353 , unsigned short V_392 ,
unsigned short V_119 )
{
T_1 * V_1 = F_201 ( V_353 ) ;
struct V_9 * V_10 ;
unsigned char V_451 ;
unsigned short V_452 ;
if ( V_1 -> V_27 . V_13 )
return - V_336 ;
switch ( V_392 )
{
case V_453 : V_451 = V_454 ; break;
case V_455 : V_451 = V_456 ; break;
case V_457 : V_451 = V_395 ; break;
case V_458 : V_451 = V_394 ; break;
case V_459 : V_451 = V_396 ; break;
default: return - V_294 ;
}
switch ( V_119 )
{
case V_460 : V_452 = V_400 ; break;
case V_461 : V_452 = V_462 ; break;
case V_463 : V_452 = V_398 ; break;
default: return - V_294 ;
}
V_1 -> V_39 . V_392 = V_451 ;
V_1 -> V_39 . V_397 = V_452 ;
if ( V_1 -> V_139 ) {
V_10 = F_43 ( & V_1 -> V_27 ) ;
F_92 ( V_1 , V_10 ) ;
F_47 ( V_10 ) ;
}
return 0 ;
}
static T_8 F_202 ( struct V_464 * V_465 ,
struct V_450 * V_353 )
{
T_1 * V_1 = F_201 ( V_353 ) ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( V_373 L_135 , __FILE__ , V_353 -> V_65 ) ;
F_203 ( V_353 ) ;
F_204 ( V_465 , V_1 -> V_146 , V_465 -> V_466 ) ;
V_1 -> V_133 = 0 ;
V_1 -> V_132 = V_1 -> V_131 = V_465 -> V_466 ;
V_353 -> V_430 . V_467 ++ ;
V_353 -> V_430 . V_468 += V_465 -> V_466 ;
F_205 ( V_465 ) ;
V_353 -> V_469 = V_324 ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_127 ) {
struct V_9 * V_10 = F_43 ( & V_1 -> V_27 ) ;
F_40 ( V_1 , V_10 ) ;
F_47 ( V_10 ) ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
return V_470 ;
}
static int F_206 ( struct V_450 * V_353 )
{
T_1 * V_1 = F_201 ( V_353 ) ;
struct V_9 * V_10 ;
int V_77 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_136 , __FILE__ , V_353 -> V_65 ) ;
if ( ( V_77 = F_207 ( V_353 ) ) )
return V_77 ;
F_36 ( & V_1 -> V_38 , V_12 ) ;
if ( V_1 -> V_27 . V_13 != 0 || V_1 -> V_139 != 0 ) {
F_9 ( V_471 L_137 , V_353 -> V_65 ) ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
return - V_336 ;
}
V_1 -> V_139 = 1 ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
V_10 = F_43 ( & V_1 -> V_27 ) ;
if ( ( V_77 = F_77 ( V_1 , V_10 ) ) != 0 ) {
F_47 ( V_10 ) ;
F_36 ( & V_1 -> V_38 , V_12 ) ;
V_1 -> V_139 = 0 ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
return V_77 ;
}
V_1 -> V_136 |= V_137 + V_213 ;
F_92 ( V_1 , V_10 ) ;
F_47 ( V_10 ) ;
V_353 -> V_469 = V_324 ;
F_208 ( V_353 ) ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_57 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_136 & V_159 )
F_67 ( V_353 ) ;
else
F_68 ( V_353 ) ;
return 0 ;
}
static int F_209 ( struct V_450 * V_353 )
{
T_1 * V_1 = F_201 ( V_353 ) ;
struct V_9 * V_10 = F_43 ( & V_1 -> V_27 ) ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_138 , __FILE__ , V_353 -> V_65 ) ;
F_203 ( V_353 ) ;
F_87 ( V_1 , V_10 ) ;
F_47 ( V_10 ) ;
F_210 ( V_353 ) ;
F_36 ( & V_1 -> V_38 , V_12 ) ;
V_1 -> V_139 = 0 ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_211 ( struct V_450 * V_353 , struct V_472 * V_473 , int V_72 )
{
const T_9 V_474 = sizeof( V_475 ) ;
V_475 V_476 ;
V_475 T_5 * line = V_473 -> V_477 . V_478 . V_479 ;
T_1 * V_1 = F_201 ( V_353 ) ;
unsigned int V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_139 , __FILE__ , V_353 -> V_65 ) ;
if ( V_1 -> V_27 . V_13 )
return - V_336 ;
if ( V_72 != V_480 )
return F_212 ( V_353 , V_473 , V_72 ) ;
memset ( & V_476 , 0 , V_474 ) ;
switch( V_473 -> V_477 . type ) {
case V_481 :
V_473 -> V_477 . type = V_482 ;
if ( V_473 -> V_477 . V_474 < V_474 ) {
V_473 -> V_477 . V_474 = V_474 ;
return - V_483 ;
}
V_12 = V_1 -> V_39 . V_12 & ( V_484 | V_387 |
V_389 | V_485 |
V_486 | V_388 |
V_390 | V_487 ) ;
switch ( V_12 ) {
case ( V_484 | V_486 ) : V_476 . V_488 = V_489 ; break;
case ( V_389 | V_390 ) : V_476 . V_488 = V_490 ; break;
case ( V_484 | V_390 ) : V_476 . V_488 = V_491 ; break;
case ( V_484 | V_487 ) : V_476 . V_488 = V_492 ; break;
default: V_476 . V_488 = V_493 ;
}
V_476 . V_494 = V_1 -> V_39 . V_379 ;
V_476 . V_391 = V_1 -> V_39 . V_391 ? 1 : 0 ;
if ( F_213 ( line , & V_476 , V_474 ) )
return - V_245 ;
return 0 ;
case V_482 :
if( ! F_82 ( V_495 ) )
return - V_496 ;
if ( F_214 ( & V_476 , line , V_474 ) )
return - V_245 ;
switch ( V_476 . V_488 )
{
case V_489 : V_12 = V_484 | V_486 ; break;
case V_492 : V_12 = V_484 | V_487 ; break;
case V_490 : V_12 = V_389 | V_390 ; break;
case V_491 : V_12 = V_484 | V_390 ; break;
case V_493 : V_12 = V_1 -> V_39 . V_12 &
( V_484 | V_387 |
V_389 | V_485 |
V_486 | V_388 |
V_390 | V_487 ) ; break;
default: return - V_294 ;
}
if ( V_476 . V_391 != 0 && V_476 . V_391 != 1 )
return - V_294 ;
V_1 -> V_39 . V_12 &= ~ ( V_484 | V_387 |
V_389 | V_485 |
V_486 | V_388 |
V_390 | V_487 ) ;
V_1 -> V_39 . V_12 |= V_12 ;
V_1 -> V_39 . V_391 = V_476 . V_391 ;
if ( V_12 & ( V_389 | V_390 ) )
V_1 -> V_39 . V_379 = V_476 . V_494 ;
else
V_1 -> V_39 . V_379 = 0 ;
if ( V_1 -> V_139 ) {
struct V_9 * V_10 = F_43 ( & V_1 -> V_27 ) ;
F_92 ( V_1 , V_10 ) ;
F_47 ( V_10 ) ;
}
return 0 ;
default:
return F_212 ( V_353 , V_473 , V_72 ) ;
}
}
static void F_215 ( struct V_450 * V_353 )
{
T_1 * V_1 = F_201 ( V_353 ) ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_140 , V_353 -> V_65 ) ;
V_353 -> V_430 . V_497 ++ ;
V_353 -> V_430 . V_498 ++ ;
F_36 ( & V_1 -> V_37 , V_12 ) ;
F_37 ( V_1 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_216 ( V_353 ) ;
}
static void F_59 ( T_1 * V_1 )
{
if ( F_217 ( V_1 -> V_162 ) )
F_216 ( V_1 -> V_162 ) ;
}
static void F_196 ( T_1 * V_1 , char * V_95 , int V_474 )
{
struct V_464 * V_465 = F_218 ( V_474 ) ;
struct V_450 * V_353 = V_1 -> V_162 ;
if ( V_21 >= V_22 )
F_9 ( L_141 , V_353 -> V_65 ) ;
if ( V_465 == NULL ) {
F_9 ( V_499 L_142 , V_353 -> V_65 ) ;
V_353 -> V_430 . V_500 ++ ;
return;
}
memcpy ( F_219 ( V_465 , V_474 ) , V_95 , V_474 ) ;
V_465 -> V_501 = F_220 ( V_465 , V_353 ) ;
V_353 -> V_430 . V_502 ++ ;
V_353 -> V_430 . V_503 += V_474 ;
F_221 ( V_465 ) ;
}
static int F_174 ( T_1 * V_1 )
{
int V_77 ;
struct V_450 * V_353 ;
T_10 * V_504 ;
if ( ! ( V_353 = F_222 ( V_1 ) ) ) {
F_9 ( V_206 L_143 , __FILE__ ) ;
return - V_24 ;
}
V_353 -> V_505 = V_1 -> V_56 ;
V_353 -> V_60 = V_1 -> V_59 ;
V_353 -> V_506 = & V_507 ;
V_353 -> V_508 = 10 * V_33 ;
V_353 -> V_509 = 50 ;
V_504 = F_223 ( V_353 ) ;
V_504 -> V_510 = F_200 ;
V_504 -> V_446 = F_202 ;
if ( ( V_77 = F_224 ( V_353 ) ) ) {
F_9 ( V_471 L_144 , __FILE__ ) ;
F_225 ( V_353 ) ;
return V_77 ;
}
V_1 -> V_162 = V_353 ;
return 0 ;
}
static void F_177 ( T_1 * V_1 )
{
F_226 ( V_1 -> V_162 ) ;
F_225 ( V_1 -> V_162 ) ;
V_1 -> V_162 = NULL ;
}
