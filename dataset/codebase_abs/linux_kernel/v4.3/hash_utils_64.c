static unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 = V_1 & 0x1fa ;
if ( ( V_1 & V_3 ) == 0 )
V_2 |= V_4 ;
if ( ( V_1 & V_5 ) && ! ( ( V_1 & V_6 ) &&
( V_1 & V_7 ) ) )
V_2 |= 1 ;
return V_2 | V_8 | V_9 ;
}
int F_2 ( unsigned long V_10 , unsigned long V_11 ,
unsigned long V_12 , unsigned long V_13 ,
int V_14 , int V_15 )
{
unsigned long V_16 , V_17 ;
unsigned int V_18 , V_19 ;
int V_20 = 0 ;
V_19 = V_21 [ V_14 ] . V_19 ;
V_18 = 1 << V_19 ;
V_13 = F_1 ( V_13 ) ;
F_3 ( L_1 ,
V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
for ( V_16 = V_10 , V_17 = V_12 ; V_16 < V_11 ;
V_16 += V_18 , V_17 += V_18 ) {
unsigned long V_22 , V_23 ;
unsigned long V_24 = F_4 ( V_16 , V_15 ) ;
unsigned long V_25 = F_5 ( V_16 , V_24 , V_15 ) ;
unsigned long V_26 = V_13 ;
if ( ! V_24 )
return - 1 ;
if ( F_6 ( V_16 , V_16 + V_18 ) )
V_26 &= ~ V_4 ;
if ( F_7 ( V_16 , V_16 + V_18 ) )
V_26 &= ~ V_4 ;
if ( ( V_27 > V_28 ) &&
F_8 ( V_16 , V_16 + V_18 ) )
V_26 &= ~ V_4 ;
V_22 = F_9 ( V_25 , V_19 , V_15 ) ;
V_23 = ( ( V_22 & V_29 ) * V_30 ) ;
F_10 ( ! V_31 . V_32 ) ;
V_20 = V_31 . V_32 ( V_23 , V_25 , V_17 , V_26 ,
V_33 , V_14 , V_14 , V_15 ) ;
if ( V_20 < 0 )
break;
#ifdef F_11
if ( ( V_17 >> V_34 ) < V_35 )
V_36 [ V_17 >> V_34 ] = V_20 | 0x80 ;
#endif
}
return V_20 < 0 ? V_20 : 0 ;
}
int F_12 ( unsigned long V_10 , unsigned long V_11 ,
int V_14 , int V_15 )
{
unsigned long V_16 ;
unsigned int V_18 , V_19 ;
V_19 = V_21 [ V_14 ] . V_19 ;
V_18 = 1 << V_19 ;
if ( ! V_31 . V_37 ) {
F_13 ( V_38 L_2
L_3 ) ;
return - V_39 ;
}
for ( V_16 = V_10 ; V_16 < V_11 ; V_16 += V_18 )
V_31 . V_37 ( V_16 , V_14 , V_15 ) ;
return 0 ;
}
static int T_1 F_14 ( unsigned long V_40 ,
const char * V_41 , int V_42 ,
void * V_43 )
{
const char * type = F_15 ( V_40 , L_4 , NULL ) ;
const T_2 * V_44 ;
int V_45 = 0 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_44 = F_15 ( V_40 , L_6 , & V_45 ) ;
if ( V_44 == NULL )
return 0 ;
for (; V_45 >= 4 ; V_45 -= 4 , ++ V_44 ) {
if ( F_16 ( V_44 [ 0 ] ) == 40 ) {
F_3 ( L_7 ) ;
V_46 -> V_47 |= V_48 ;
return 1 ;
}
}
V_46 -> V_47 &= ~ V_49 ;
return 0 ;
}
static void T_1 F_17 ( void )
{
F_18 ( F_14 , NULL ) ;
}
static int T_1 F_19 ( unsigned int V_19 )
{
int V_50 = - 1 ;
switch ( V_19 ) {
case 0xc :
V_50 = V_51 ;
break;
case 0x10 :
V_50 = V_52 ;
break;
case 0x14 :
V_50 = V_53 ;
break;
case 0x18 :
V_50 = V_54 ;
break;
case 0x22 :
V_50 = V_55 ;
break;
}
return V_50 ;
}
static int T_1 F_20 ( unsigned long V_40 ,
const char * V_41 , int V_42 ,
void * V_43 )
{
const char * type = F_15 ( V_40 , L_4 , NULL ) ;
const T_2 * V_44 ;
int V_45 = 0 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_44 = F_15 ( V_40 , L_8 , & V_45 ) ;
if ( ! V_44 )
return 0 ;
F_21 ( L_9 ) ;
V_45 /= 4 ;
V_46 -> V_47 &= ~ ( V_56 ) ;
while( V_45 > 0 ) {
unsigned int V_57 = F_16 ( V_44 [ 0 ] ) ;
unsigned int V_58 = F_16 ( V_44 [ 1 ] ) ;
unsigned int V_59 = F_16 ( V_44 [ 2 ] ) ;
struct V_60 * V_61 ;
int V_50 , V_62 ;
V_45 -= 3 ; V_44 += 3 ;
V_62 = F_19 ( V_57 ) ;
if ( V_62 < 0 ) {
V_44 += V_59 * 2 ; V_45 -= V_59 * 2 ;
continue;
}
V_61 = & V_21 [ V_62 ] ;
if ( V_62 == V_54 )
V_46 -> V_47 |= V_56 ;
V_61 -> V_19 = V_57 ;
if ( V_57 <= 23 )
V_61 -> V_63 = 0 ;
else
V_61 -> V_63 = ( 1 << ( V_57 - 23 ) ) - 1 ;
V_61 -> V_64 = V_58 ;
if ( V_62 == V_51 || V_62 == V_52 )
V_61 -> V_65 = 1 ;
else
V_61 -> V_65 = 0 ;
while ( V_45 > 0 && V_59 ) {
unsigned int V_19 = F_16 ( V_44 [ 0 ] ) ;
int V_66 = F_16 ( V_44 [ 1 ] ) ;
V_44 += 2 ; V_45 -= 2 ;
V_59 -- ;
V_50 = F_19 ( V_19 ) ;
if ( V_50 < 0 )
continue;
if ( V_66 == - 1 )
F_22 ( L_10
L_11 , V_57 , V_19 ) ;
V_61 -> V_66 [ V_50 ] = V_66 ;
F_21 ( L_12
L_13 ,
V_57 , V_19 , V_61 -> V_64 ,
V_61 -> V_63 , V_61 -> V_65 , V_61 -> V_66 [ V_50 ] ) ;
}
}
return 1 ;
}
static int T_1 F_23 ( unsigned long V_40 ,
const char * V_41 , int V_42 ,
void * V_43 ) {
const char * type = F_15 ( V_40 , L_4 , NULL ) ;
const T_3 * V_67 ;
const T_2 * V_68 ;
unsigned int V_69 ;
long unsigned int V_70 ;
long unsigned int V_71 ;
if ( type == NULL || strcmp ( type , L_14 ) != 0 )
return 0 ;
V_68 = F_15 ( V_40 , L_15 , NULL ) ;
if ( V_68 == NULL )
return 0 ;
V_69 = ( 1 << F_16 ( V_68 [ 0 ] ) ) ;
V_67 = F_15 ( V_40 , L_16 , NULL ) ;
if ( V_67 == NULL )
return 0 ;
V_70 = F_24 ( V_67 [ 0 ] ) ;
V_71 = F_24 ( V_67 [ 1 ] ) ;
if ( V_71 != ( 16 * V_72 ) )
return 0 ;
F_13 ( V_73 L_17
L_18 ,
V_70 , V_71 , V_69 ) ;
if ( V_70 + ( 16 * V_72 ) <= F_25 () ) {
F_26 ( V_70 , V_71 * V_69 ) ;
F_27 ( V_70 , V_71 , V_69 ) ;
}
return 0 ;
}
static void F_28 ( void )
{
int V_74 , V_75 ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ )
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ )
V_21 [ V_74 ] . V_66 [ V_75 ] = - 1 ;
}
static bool F_29 ( void )
{
#ifdef F_30
return ! F_31 ( V_77 ) ;
#else
return false ;
#endif
}
static void T_1 F_32 ( void )
{
int V_78 ;
F_28 () ;
memcpy ( V_21 , V_79 ,
sizeof( V_79 ) ) ;
V_78 = F_18 ( F_20 , NULL ) ;
if ( V_78 != 0 )
goto V_80;
if ( F_33 ( V_56 ) )
memcpy ( V_21 , V_81 ,
sizeof( V_81 ) ) ;
V_80:
#ifndef F_11
if ( V_21 [ V_54 ] . V_19 )
V_82 = V_54 ;
else if ( V_21 [ V_53 ] . V_19 )
V_82 = V_53 ;
#endif
#ifdef F_34
if ( V_21 [ V_52 ] . V_19 ) {
V_83 = V_52 ;
V_84 = V_52 ;
if ( V_82 == V_51 )
V_82 = V_52 ;
if ( F_33 ( V_85 ) ) {
if ( ! F_29 () || ! F_35 ( V_86 ) )
V_87 = V_52 ;
} else
V_88 = 1 ;
}
#endif
#ifdef F_36
if ( V_21 [ V_54 ] . V_19 &&
F_37 () >= 0x40000000 )
V_89 = V_54 ;
else if ( V_21 [ V_52 ] . V_19 )
V_89 = V_52 ;
else
V_89 = V_51 ;
#endif
F_13 ( V_90 L_19
L_20
#ifdef F_36
L_21
#endif
L_22 ,
V_21 [ V_82 ] . V_19 ,
V_21 [ V_83 ] . V_19 ,
V_21 [ V_87 ] . V_19
#ifdef F_36
, V_21 [ V_89 ] . V_19
#endif
) ;
#ifdef F_38
F_18 ( F_23 , NULL ) ;
#endif
}
static int T_1 F_39 ( unsigned long V_40 ,
const char * V_41 , int V_42 ,
void * V_43 )
{
const char * type = F_15 ( V_40 , L_4 , NULL ) ;
const T_2 * V_44 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_44 = F_15 ( V_40 , L_23 , NULL ) ;
if ( V_44 != NULL ) {
V_91 = F_16 ( V_44 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
static unsigned long T_1 F_40 ( void )
{
unsigned long V_92 , V_93 , V_94 , V_14 ;
if ( V_91 == 0 )
F_18 ( F_39 , NULL ) ;
if ( V_91 )
return 1UL << V_91 ;
V_92 = F_37 () ;
V_93 = 1UL << F_41 ( V_92 ) ;
if ( V_93 < V_92 )
V_93 <<= 1 ;
V_14 = V_21 [ V_83 ] . V_19 ;
V_94 = F_42 ( V_93 >> ( V_14 + 1 ) , 1UL << 11 ) ;
return V_94 << 7 ;
}
int F_43 ( unsigned long V_95 , unsigned long V_96 )
{
return F_2 ( V_95 , V_96 , F_44 ( V_95 ) ,
F_45 ( V_97 ) , V_82 ,
V_98 ) ;
}
int F_46 ( unsigned long V_95 , unsigned long V_96 )
{
return F_12 ( V_95 , V_96 , V_82 ,
V_98 ) ;
}
static void T_1 F_47 ( void )
{
#ifdef F_34
F_48 ( V_99 ,
F_49 ( V_31 . V_32 ) ,
V_100 ) ;
F_48 ( V_101 ,
F_49 ( V_31 . V_32 ) ,
V_100 ) ;
F_48 ( V_102 ,
F_49 ( V_31 . V_103 ) ,
V_100 ) ;
F_48 ( V_104 ,
F_49 ( V_31 . V_105 ) ,
V_100 ) ;
#endif
F_48 ( V_106 ,
F_49 ( V_31 . V_32 ) ,
V_100 ) ;
F_48 ( V_107 ,
F_49 ( V_31 . V_32 ) ,
V_100 ) ;
F_48 ( V_108 ,
F_49 ( V_31 . V_103 ) ,
V_100 ) ;
F_48 ( V_109 ,
F_49 ( V_31 . V_105 ) ,
V_100 ) ;
}
static void T_1 F_50 ( void )
{
unsigned long V_110 ;
unsigned long V_94 ;
unsigned long V_13 ;
unsigned long V_111 = 0 , V_45 = 0 , V_112 ;
struct V_113 * V_114 ;
F_3 ( L_24 ) ;
F_17 () ;
F_32 () ;
if ( F_33 ( V_48 ) ) {
V_98 = V_115 ;
V_116 = V_115 ;
F_13 ( V_73 L_25 ) ;
}
V_117 = F_40 () ;
V_94 = V_117 >> 7 ;
V_29 = V_94 - 1 ;
if ( F_51 ( V_118 ) ) {
V_119 = NULL ;
V_120 = 0 ;
#ifdef F_52
if ( F_53 () && V_31 . V_121 )
V_31 . V_121 () ;
#endif
} else {
if ( F_35 ( V_122 ) )
V_112 = 0x80000000 ;
else
V_112 = V_123 ;
V_110 = F_54 ( V_117 , V_117 , V_112 ) ;
F_3 ( L_26 , V_110 ,
V_117 ) ;
V_119 = F_55 ( V_110 ) ;
V_120 = V_110 + F_41 ( V_94 ) - 11 ;
memset ( ( void * ) V_110 , 0 , V_117 ) ;
F_56 ( V_124 , V_120 ) ;
}
V_13 = F_45 ( V_97 ) ;
#ifdef F_11
V_35 = F_25 () >> V_34 ;
V_36 = F_55 ( F_54 ( V_35 ,
1 , V_125 ) ) ;
memset ( V_36 , 0 , V_35 ) ;
#endif
F_57 (memory, reg) {
V_111 = ( unsigned long ) F_55 ( V_114 -> V_111 ) ;
V_45 = V_114 -> V_45 ;
F_3 ( L_27 ,
V_111 , V_45 , V_13 ) ;
#ifdef F_58
F_3 ( L_28 , V_126 ) ;
if ( V_126 != 0 && V_126 >= V_111
&& V_126 < ( V_111 + V_45 ) ) {
unsigned long V_127 = V_126 + 16 * V_128 ;
if ( V_111 != V_126 )
F_10 ( F_2 ( V_111 , V_126 ,
F_44 ( V_111 ) , V_13 ,
V_82 ,
V_98 ) ) ;
if ( ( V_111 + V_45 ) > V_127 )
F_10 ( F_2 ( V_126 + 16 * V_128 ,
V_111 + V_45 ,
F_44 ( V_127 ) ,
V_13 ,
V_82 ,
V_98 ) ) ;
continue;
}
#endif
F_10 ( F_2 ( V_111 , V_111 + V_45 , F_44 ( V_111 ) ,
V_13 , V_82 , V_98 ) ) ;
}
F_59 ( V_123 ) ;
if ( V_129 ) {
V_129 = ( unsigned long ) F_55 ( V_129 ) ;
V_130 = ( unsigned long ) F_55 ( V_130 ) ;
if ( V_111 + V_45 >= V_129 )
V_129 = V_111 + V_45 + 1 ;
F_10 ( F_2 ( V_129 , V_130 ,
F_44 ( V_129 ) , V_13 ,
V_82 , V_98 ) ) ;
}
F_47 () ;
F_3 ( L_29 ) ;
}
void T_1 F_60 ( void )
{
F_50 () ;
F_61 () ;
}
void F_62 ( void )
{
if ( ! F_51 ( V_118 ) )
F_56 ( V_124 , V_120 ) ;
F_61 () ;
}
unsigned int F_63 ( unsigned int V_131 , T_4 V_132 , int V_133 )
{
struct V_134 * V_134 ;
if ( ! F_64 ( F_65 ( V_132 ) ) )
return V_131 ;
V_134 = F_66 ( V_132 ) ;
if ( ! F_67 ( V_135 , & V_134 -> V_136 ) && ! F_68 ( V_134 ) ) {
if ( V_133 == 0x400 ) {
F_69 ( V_134 ) ;
F_70 ( V_135 , & V_134 -> V_136 ) ;
} else
V_131 |= V_4 ;
}
return V_131 ;
}
static unsigned int F_71 ( unsigned long V_137 )
{
T_5 V_138 ;
unsigned char * V_139 ;
unsigned long V_140 , V_141 ;
if ( V_137 < V_142 ) {
V_138 = F_72 () -> V_143 . V_144 ;
V_140 = F_73 ( V_137 ) ;
return ( V_138 >> ( V_140 * 4 ) ) & 0xF ;
}
V_139 = F_72 () -> V_143 . V_145 ;
V_140 = F_74 ( V_137 ) ;
V_141 = V_140 & 0x1 ;
return ( V_139 [ V_140 >> 1 ] >> ( V_141 * 4 ) ) & 0xF ;
}
unsigned int F_71 ( unsigned long V_137 )
{
return F_72 () -> V_143 . V_146 ;
}
void F_75 ( struct V_147 * V_148 , unsigned long V_137 )
{
if ( F_76 ( V_148 , V_137 ) == V_51 )
return;
F_77 ( V_148 , V_137 , 1 , V_51 ) ;
F_78 ( V_148 ) ;
if ( ( F_71 ( V_137 ) != V_51 ) && ( V_149 -> V_148 == V_148 ) ) {
F_72 () -> V_143 = V_148 -> V_143 ;
F_79 () ;
}
}
static int F_80 ( struct V_147 * V_148 , unsigned long V_150 )
{
struct V_151 * V_152 = & V_148 -> V_143 . V_152 ;
T_6 V_153 = 0 ;
T_6 * * V_154 , * V_155 ;
if ( V_150 >= V_152 -> V_156 )
return 0 ;
if ( V_150 < 0x100000000UL ) {
V_154 = V_152 -> V_157 ;
} else {
V_154 = V_152 -> V_158 [ V_150 >> V_159 ] ;
if ( ! V_154 )
return 0 ;
}
V_155 = V_154 [ ( V_150 >> V_160 ) & ( V_161 - 1 ) ] ;
if ( ! V_155 )
return 0 ;
V_153 = V_155 [ ( V_150 >> V_34 ) & ( V_162 - 1 ) ] ;
V_153 >>= 30 - 2 * ( ( V_150 >> 12 ) & 0xf ) ;
V_153 = ( ( V_153 & 2 ) ? V_5 : 0 ) | ( ( V_153 & 1 ) ? V_6 : 0 ) ;
return V_153 ;
}
static inline int F_80 ( struct V_147 * V_148 , unsigned long V_150 )
{
return 0 ;
}
void F_81 ( unsigned long V_150 , unsigned long V_163 ,
unsigned long V_24 , unsigned long V_133 ,
int V_15 , int V_14 , int V_164 , unsigned long V_132 )
{
if ( ! F_82 () )
return;
F_21 ( L_30 ,
V_150 , V_163 , V_149 -> V_165 ) ;
F_21 ( L_31 ,
V_133 , V_24 , V_15 , V_14 , V_164 , V_132 ) ;
}
static void F_83 ( unsigned long V_150 , struct V_147 * V_148 ,
int V_14 , bool V_166 )
{
if ( V_166 ) {
if ( V_14 != F_71 ( V_150 ) ) {
F_72 () -> V_143 = V_148 -> V_143 ;
F_79 () ;
}
} else if ( F_72 () -> V_167 !=
V_21 [ V_84 ] . V_64 ) {
F_72 () -> V_167 =
V_21 [ V_84 ] . V_64 ;
F_84 () ;
}
}
int F_85 ( struct V_147 * V_148 , unsigned long V_150 ,
unsigned long V_163 , unsigned long V_133 ,
unsigned long V_136 )
{
enum V_168 V_169 = F_86 () ;
T_7 * V_170 ;
unsigned long V_24 ;
T_4 * V_171 ;
unsigned V_172 ;
const struct V_173 * V_174 ;
int V_78 , V_166 = 0 ;
int V_14 , V_15 ;
F_87 ( L_32 ,
V_150 , V_163 , V_133 ) ;
F_88 ( V_150 , V_163 , V_133 ) ;
switch ( F_89 ( V_150 ) ) {
case V_175 :
V_166 = 1 ;
if ( ! V_148 ) {
F_87 ( L_33 ) ;
V_78 = 1 ;
goto V_176;
}
V_14 = F_76 ( V_148 , V_150 ) ;
V_15 = F_90 ( V_150 ) ;
V_24 = F_91 ( V_148 -> V_143 . V_177 , V_150 , V_15 ) ;
break;
case V_178 :
V_24 = F_4 ( V_150 , V_98 ) ;
if ( V_150 < V_179 )
V_14 = V_84 ;
else
V_14 = V_87 ;
V_15 = V_98 ;
break;
default:
V_78 = 1 ;
goto V_176;
}
F_87 ( L_34 , V_148 , V_148 -> V_180 , V_24 ) ;
if ( ! V_24 ) {
F_87 ( L_35 ) ;
V_78 = 1 ;
goto V_176;
}
V_170 = V_148 -> V_180 ;
if ( V_170 == NULL ) {
V_78 = 1 ;
goto V_176;
}
V_174 = F_92 ( F_93 () ) ;
if ( V_166 && F_94 ( F_95 ( V_148 ) , V_174 ) )
V_136 |= V_181 ;
#ifndef F_34
if ( V_14 != V_51 )
V_150 &= ~ ( ( 1ul << V_21 [ V_14 ] . V_19 ) - 1 ) ;
#endif
V_171 = F_96 ( V_170 , V_150 , & V_172 ) ;
if ( V_171 == NULL || ! F_97 ( * V_171 ) ) {
F_87 ( L_36 ) ;
V_78 = 1 ;
goto V_176;
}
V_163 |= V_182 ;
if ( V_163 & ~ F_98 ( * V_171 ) ) {
F_87 ( L_37 ) ;
V_78 = 1 ;
goto V_176;
}
if ( V_172 ) {
if ( F_99 ( * ( V_183 * ) V_171 ) )
V_78 = F_100 ( V_150 , V_163 , V_24 , ( V_183 * ) V_171 ,
V_133 , V_136 , V_15 , V_14 ) ;
#ifdef F_38
else
V_78 = F_101 ( V_150 , V_163 , V_24 , V_171 , V_133 ,
V_136 , V_15 , V_172 , V_14 ) ;
#else
else {
V_78 = 1 ;
F_102 ( 1 ) ;
}
#endif
if ( V_149 -> V_148 == V_148 )
F_83 ( V_150 , V_148 , V_14 , V_166 ) ;
goto V_176;
}
#ifndef F_34
F_87 ( L_38 , F_98 ( * V_171 ) ) ;
#else
F_87 ( L_39 , F_98 ( * V_171 ) ,
F_98 ( * ( V_171 + V_184 ) ) ) ;
#endif
#ifdef F_34
if ( ( F_98 ( * V_171 ) & V_185 ) && V_14 == V_52 ) {
F_75 ( V_148 , V_150 ) ;
V_14 = V_51 ;
}
if ( V_88 && V_14 == V_52 &&
( F_98 ( * V_171 ) & V_186 ) ) {
if ( V_166 ) {
F_75 ( V_148 , V_150 ) ;
V_14 = V_51 ;
} else if ( V_150 < V_179 ) {
F_13 ( V_187 L_40
L_41
L_42 ) ;
V_14 = V_84 = V_51 ;
F_78 ( V_148 ) ;
}
}
if ( V_149 -> V_148 == V_148 )
F_83 ( V_150 , V_148 , V_14 , V_166 ) ;
#endif
#ifdef F_34
if ( V_14 == V_52 )
V_78 = F_103 ( V_150 , V_163 , V_24 , V_171 , V_133 ,
V_136 , V_15 ) ;
else
#endif
{
int V_153 = F_80 ( V_148 , V_150 ) ;
if ( V_163 & V_153 )
V_78 = - 2 ;
else
V_78 = F_104 ( V_150 , V_163 , V_24 , V_171 , V_133 ,
V_136 , V_15 , V_153 ) ;
}
if ( V_78 == - 1 )
F_81 ( V_150 , V_163 , V_24 , V_133 , V_15 , V_14 ,
V_14 , F_98 ( * V_171 ) ) ;
#ifndef F_34
F_87 ( L_43 , F_98 ( * V_171 ) ) ;
#else
F_87 ( L_44 , F_98 ( * V_171 ) ,
F_98 ( * ( V_171 + V_184 ) ) ) ;
#endif
F_87 ( L_45 , V_78 ) ;
V_176:
F_105 ( V_169 ) ;
return V_78 ;
}
int F_106 ( unsigned long V_150 , unsigned long V_163 , unsigned long V_133 ,
unsigned long V_188 )
{
unsigned long V_136 = 0 ;
struct V_147 * V_148 = V_149 -> V_148 ;
if ( F_89 ( V_150 ) == V_178 )
V_148 = & V_189 ;
if ( V_188 & V_190 )
V_136 |= V_191 ;
return F_85 ( V_148 , V_150 , V_163 , V_133 , V_136 ) ;
}
void F_107 ( struct V_147 * V_148 , unsigned long V_150 ,
unsigned long V_163 , unsigned long V_133 )
{
int V_192 ;
unsigned long V_24 ;
T_7 * V_170 ;
T_4 * V_171 ;
unsigned long V_136 ;
int V_78 , V_15 , V_193 = 0 ;
F_10 ( F_89 ( V_150 ) != V_175 ) ;
#ifdef F_108
if ( F_109 ( F_76 ( V_148 , V_150 ) != V_148 -> V_143 . V_146 ) )
return;
#endif
F_87 ( L_46
L_47 , V_148 , V_148 -> V_180 , V_150 , V_163 , V_133 ) ;
V_170 = V_148 -> V_180 ;
if ( V_170 == NULL )
return;
V_15 = F_90 ( V_150 ) ;
V_24 = F_91 ( V_148 -> V_143 . V_177 , V_150 , V_15 ) ;
if ( ! V_24 )
return;
F_110 ( V_136 ) ;
V_171 = F_111 ( V_170 , V_150 , & V_192 ) ;
if ( ! V_171 )
goto V_194;
F_102 ( V_192 ) ;
#ifdef F_34
if ( F_98 ( * V_171 ) & ( V_185 | V_186 ) )
goto V_194;
#endif
if ( F_94 ( F_95 ( V_148 ) , F_92 ( F_93 () ) ) )
V_193 |= V_181 ;
#ifdef F_34
if ( V_148 -> V_143 . V_146 == V_52 )
V_78 = F_103 ( V_150 , V_163 , V_24 , V_171 , V_133 ,
V_193 , V_15 ) ;
else
#endif
V_78 = F_104 ( V_150 , V_163 , V_24 , V_171 , V_133 , V_193 ,
V_15 , F_80 ( V_148 , V_150 ) ) ;
if ( V_78 == - 1 )
F_81 ( V_150 , V_163 , V_24 , V_133 , V_15 ,
V_148 -> V_143 . V_146 ,
V_148 -> V_143 . V_146 ,
F_98 ( * V_171 ) ) ;
V_194:
F_112 ( V_136 ) ;
}
void F_113 ( unsigned long V_25 , T_8 V_132 , int V_14 , int V_15 ,
unsigned long V_136 )
{
unsigned long V_22 , V_140 , V_19 , V_195 , V_196 ;
int V_197 = V_136 & V_181 ;
F_87 ( L_48 , V_25 ) ;
F_114 (pte, psize, vpn, index, shift) {
V_22 = F_9 ( V_25 , V_19 , V_15 ) ;
V_195 = F_115 ( V_132 , V_140 ) ;
if ( V_195 & V_198 )
V_22 = ~ V_22 ;
V_196 = ( V_22 & V_29 ) * V_30 ;
V_196 += V_195 & V_199 ;
F_87 ( L_49 , V_140 , V_196 , V_195 ) ;
V_31 . V_200 ( V_196 , V_25 , V_14 , V_14 , V_15 , V_197 ) ;
} F_116 () ;
#ifdef F_117
if ( V_197 && F_31 ( V_201 ) &&
V_149 -> V_202 . V_203 &&
F_118 ( V_149 -> V_202 . V_203 -> V_204 ) ) {
F_119 () ;
F_120 ( V_205 ) ;
}
#endif
}
void F_121 ( unsigned long V_24 , unsigned long V_137 ,
V_183 * V_206 , unsigned int V_14 , int V_15 ,
unsigned long V_136 )
{
int V_207 , V_208 , V_209 ;
unsigned long V_210 ;
unsigned char * V_211 ;
unsigned long V_195 , V_19 , V_25 , V_22 , V_196 ;
int V_197 = V_136 & V_181 ;
V_210 = V_137 & V_212 ;
V_211 = F_122 ( V_206 ) ;
if ( ! V_211 )
return;
if ( V_31 . V_213 ) {
V_31 . V_213 ( V_24 , V_210 , V_211 ,
V_14 , V_15 , V_197 ) ;
goto F_120;
}
V_19 = V_21 [ V_14 ] . V_19 ;
V_208 = V_214 >> V_19 ;
for ( V_207 = 0 ; V_207 < V_208 ; V_207 ++ ) {
V_209 = F_123 ( V_211 , V_207 ) ;
if ( ! V_209 )
continue;
V_195 = F_124 ( V_211 , V_207 ) ;
V_137 = V_210 + ( V_207 * ( 1ul << V_19 ) ) ;
V_25 = F_5 ( V_137 , V_24 , V_15 ) ;
V_22 = F_9 ( V_25 , V_19 , V_15 ) ;
if ( V_195 & V_198 )
V_22 = ~ V_22 ;
V_196 = ( V_22 & V_29 ) * V_30 ;
V_196 += V_195 & V_199 ;
V_31 . V_200 ( V_196 , V_25 , V_14 ,
V_54 , V_15 , V_197 ) ;
}
F_120:
#ifdef F_117
if ( V_197 && F_31 ( V_201 ) &&
V_149 -> V_202 . V_203 &&
F_118 ( V_149 -> V_202 . V_203 -> V_204 ) ) {
F_119 () ;
F_120 ( V_205 ) ;
}
#endif
return;
}
void F_125 ( unsigned long V_215 , int V_197 )
{
if ( V_31 . F_125 )
V_31 . F_125 ( V_215 , V_197 ) ;
else {
int V_207 ;
struct V_216 * V_217 =
F_126 ( & V_216 ) ;
for ( V_207 = 0 ; V_207 < V_215 ; V_207 ++ )
F_113 ( V_217 -> V_25 [ V_207 ] , V_217 -> V_132 [ V_207 ] ,
V_217 -> V_14 , V_217 -> V_15 , V_197 ) ;
}
}
void F_127 ( struct V_218 * V_203 , unsigned long V_219 , int V_78 )
{
enum V_168 V_169 = F_86 () ;
if ( F_128 ( V_203 ) ) {
#ifdef F_129
if ( V_78 == - 2 )
F_130 ( V_220 , V_203 , V_221 , V_219 ) ;
else
#endif
F_130 ( V_222 , V_203 , V_223 , V_219 ) ;
} else
F_131 ( V_203 , V_219 , V_222 ) ;
F_105 ( V_169 ) ;
}
long F_132 ( unsigned long V_22 , unsigned long V_25 ,
unsigned long V_224 , unsigned long V_2 ,
unsigned long V_225 , int V_14 , int V_15 )
{
unsigned long V_226 ;
long V_196 ;
V_227:
V_226 = ( ( V_22 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_196 = V_31 . V_32 ( V_226 , V_25 , V_224 , V_2 , V_225 ,
V_14 , V_14 , V_15 ) ;
if ( F_109 ( V_196 == - 1 ) ) {
V_226 = ( ( ~ V_22 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_196 = V_31 . V_32 ( V_226 , V_25 , V_224 , V_2 ,
V_225 | V_228 ,
V_14 , V_14 , V_15 ) ;
if ( V_196 == - 1 ) {
if ( F_133 () & 0x1 )
V_226 = ( ( V_22 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_31 . V_103 ( V_226 ) ;
goto V_227;
}
}
return V_196 ;
}
static void F_134 ( unsigned long V_16 , unsigned long V_229 )
{
unsigned long V_22 ;
unsigned long V_24 = F_4 ( V_16 , V_98 ) ;
unsigned long V_25 = F_5 ( V_16 , V_24 , V_98 ) ;
unsigned long V_230 = F_1 ( F_45 ( V_97 ) ) ;
long V_20 ;
V_22 = F_9 ( V_25 , V_34 , V_98 ) ;
if ( ! V_24 )
return;
V_20 = F_132 ( V_22 , V_25 , F_44 ( V_16 ) , V_230 ,
V_33 ,
V_82 , V_98 ) ;
F_10 ( V_20 < 0 ) ;
F_135 ( & V_231 ) ;
F_10 ( V_36 [ V_229 ] & 0x80 ) ;
V_36 [ V_229 ] = V_20 | 0x80 ;
F_136 ( & V_231 ) ;
}
static void F_137 ( unsigned long V_16 , unsigned long V_229 )
{
unsigned long V_22 , V_195 , V_196 ;
unsigned long V_24 = F_4 ( V_16 , V_98 ) ;
unsigned long V_25 = F_5 ( V_16 , V_24 , V_98 ) ;
V_22 = F_9 ( V_25 , V_34 , V_98 ) ;
F_135 ( & V_231 ) ;
F_10 ( ! ( V_36 [ V_229 ] & 0x80 ) ) ;
V_195 = V_36 [ V_229 ] & 0x7f ;
V_36 [ V_229 ] = 0 ;
F_136 ( & V_231 ) ;
if ( V_195 & V_198 )
V_22 = ~ V_22 ;
V_196 = ( V_22 & V_29 ) * V_30 ;
V_196 += V_195 & V_199 ;
V_31 . V_200 ( V_196 , V_25 , V_82 , V_82 ,
V_98 , 0 ) ;
}
void F_138 ( struct V_134 * V_134 , int V_232 , int V_233 )
{
unsigned long V_136 , V_16 , V_229 ;
int V_207 ;
F_110 ( V_136 ) ;
for ( V_207 = 0 ; V_207 < V_232 ; V_207 ++ , V_134 ++ ) {
V_16 = ( unsigned long ) F_139 ( V_134 ) ;
V_229 = F_44 ( V_16 ) >> V_34 ;
if ( V_229 >= V_35 )
continue;
if ( V_233 )
F_134 ( V_16 , V_229 ) ;
else
F_137 ( V_16 , V_229 ) ;
}
F_112 ( V_136 ) ;
}
void F_140 ( T_9 V_234 ,
T_9 V_235 )
{
F_10 ( V_234 != 0 ) ;
V_125 = F_141 ( T_5 , V_235 , 0x40000000 ) ;
F_59 ( V_125 ) ;
}
