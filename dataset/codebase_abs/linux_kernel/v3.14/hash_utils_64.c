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
if ( ( V_27 > V_28 ) &&
F_7 ( V_16 , V_16 + V_18 ) )
V_26 &= ~ V_4 ;
V_22 = F_8 ( V_25 , V_19 , V_15 ) ;
V_23 = ( ( V_22 & V_29 ) * V_30 ) ;
F_9 ( ! V_31 . V_32 ) ;
V_20 = V_31 . V_32 ( V_23 , V_25 , V_17 , V_26 ,
V_33 , V_14 , V_14 , V_15 ) ;
if ( V_20 < 0 )
break;
#ifdef F_10
if ( ( V_17 >> V_34 ) < V_35 )
V_36 [ V_17 >> V_34 ] = V_20 | 0x80 ;
#endif
}
return V_20 < 0 ? V_20 : 0 ;
}
static int F_11 ( unsigned long V_10 , unsigned long V_11 ,
int V_14 , int V_15 )
{
unsigned long V_16 ;
unsigned int V_18 , V_19 ;
V_19 = V_21 [ V_14 ] . V_19 ;
V_18 = 1 << V_19 ;
if ( ! V_31 . V_37 ) {
F_12 ( V_38 L_2
L_3 ) ;
return - V_39 ;
}
for ( V_16 = V_10 ; V_16 < V_11 ; V_16 += V_18 )
V_31 . V_37 ( V_16 , V_14 , V_15 ) ;
return 0 ;
}
static int T_1 F_13 ( unsigned long V_40 ,
const char * V_41 , int V_42 ,
void * V_43 )
{
char * type = F_14 ( V_40 , L_4 , NULL ) ;
T_2 * V_44 ;
unsigned long V_45 = 0 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_44 = F_14 ( V_40 , L_6 , & V_45 ) ;
if ( V_44 == NULL )
return 0 ;
for (; V_45 >= 4 ; V_45 -= 4 , ++ V_44 ) {
if ( F_15 ( V_44 [ 0 ] ) == 40 ) {
F_3 ( L_7 ) ;
V_46 -> V_47 |= V_48 ;
return 1 ;
}
}
V_46 -> V_47 &= ~ V_49 ;
return 0 ;
}
static void T_1 F_16 ( void )
{
F_17 ( F_13 , NULL ) ;
}
static int T_1 F_18 ( unsigned int V_19 )
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
static int T_1 F_19 ( unsigned long V_40 ,
const char * V_41 , int V_42 ,
void * V_43 )
{
char * type = F_14 ( V_40 , L_4 , NULL ) ;
T_2 * V_44 ;
unsigned long V_45 = 0 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_44 = F_14 ( V_40 , L_8 , & V_45 ) ;
if ( V_44 != NULL ) {
F_20 ( L_9 ) ;
V_45 /= 4 ;
V_46 -> V_47 &= ~ ( V_56 ) ;
while( V_45 > 0 ) {
unsigned int V_57 = F_15 ( V_44 [ 0 ] ) ;
unsigned int V_58 = F_15 ( V_44 [ 1 ] ) ;
unsigned int V_59 = F_15 ( V_44 [ 2 ] ) ;
struct V_60 * V_61 ;
int V_50 , V_62 ;
V_45 -= 3 ; V_44 += 3 ;
V_62 = F_18 ( V_57 ) ;
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
unsigned int V_19 = F_15 ( V_44 [ 0 ] ) ;
int V_66 = F_15 ( V_44 [ 1 ] ) ;
V_44 += 2 ; V_45 -= 2 ;
V_59 -- ;
V_50 = F_18 ( V_19 ) ;
if ( V_50 < 0 )
continue;
if ( V_66 == - 1 )
F_21 ( L_10
L_11 , V_57 , V_19 ) ;
V_61 -> V_66 [ V_50 ] = V_66 ;
F_20 ( L_12
L_13 ,
V_57 , V_19 , V_61 -> V_64 ,
V_61 -> V_63 , V_61 -> V_65 , V_61 -> V_66 [ V_50 ] ) ;
}
}
return 1 ;
}
return 0 ;
}
static int T_1 F_22 ( unsigned long V_40 ,
const char * V_41 , int V_42 ,
void * V_43 ) {
char * type = F_14 ( V_40 , L_4 , NULL ) ;
T_3 * V_67 ;
T_2 * V_68 ;
unsigned int V_69 ;
long unsigned int V_70 ;
long unsigned int V_71 ;
if ( type == NULL || strcmp ( type , L_14 ) != 0 )
return 0 ;
V_68 = F_14 ( V_40 , L_15 , NULL ) ;
if ( V_68 == NULL )
return 0 ;
V_69 = ( 1 << F_15 ( V_68 [ 0 ] ) ) ;
V_67 = F_14 ( V_40 , L_16 , NULL ) ;
if ( V_67 == NULL )
return 0 ;
V_70 = F_23 ( V_67 [ 0 ] ) ;
V_71 = F_23 ( V_67 [ 1 ] ) ;
if ( V_71 != ( 16 * V_72 ) )
return 0 ;
F_12 ( V_73 L_17
L_18 ,
V_70 , V_71 , V_69 ) ;
if ( V_70 + ( 16 * V_72 ) <= F_24 () ) {
F_25 ( V_70 , V_71 * V_69 ) ;
F_26 ( V_70 , V_71 , V_69 ) ;
}
return 0 ;
}
static void F_27 ( void )
{
int V_74 , V_75 ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ )
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ )
V_21 [ V_74 ] . V_66 [ V_75 ] = - 1 ;
}
static void T_1 F_28 ( void )
{
int V_77 ;
F_27 () ;
memcpy ( V_21 , V_78 ,
sizeof( V_78 ) ) ;
V_77 = F_17 ( F_19 , NULL ) ;
if ( V_77 != 0 )
goto V_79;
if ( F_29 ( V_56 ) )
memcpy ( V_21 , V_80 ,
sizeof( V_80 ) ) ;
V_79:
#ifndef F_10
if ( V_21 [ V_54 ] . V_19 )
V_81 = V_54 ;
else if ( V_21 [ V_53 ] . V_19 )
V_81 = V_53 ;
#endif
#ifdef F_30
if ( V_21 [ V_52 ] . V_19 ) {
V_82 = V_52 ;
V_83 = V_52 ;
if ( V_81 == V_51 )
V_81 = V_52 ;
if ( F_29 ( V_84 ) ) {
if ( ! F_31 ( V_85 ) )
V_86 = V_52 ;
} else
V_87 = 1 ;
}
#endif
#ifdef F_32
if ( V_21 [ V_54 ] . V_19 &&
F_33 () >= 0x40000000 )
V_88 = V_54 ;
else if ( V_21 [ V_52 ] . V_19 )
V_88 = V_52 ;
else
V_88 = V_51 ;
#endif
F_12 ( V_89 L_19
L_20
#ifdef F_32
L_21
#endif
L_22 ,
V_21 [ V_81 ] . V_19 ,
V_21 [ V_82 ] . V_19 ,
V_21 [ V_86 ] . V_19
#ifdef F_32
, V_21 [ V_88 ] . V_19
#endif
) ;
#ifdef F_34
F_17 ( F_22 , NULL ) ;
#endif
}
static int T_1 F_35 ( unsigned long V_40 ,
const char * V_41 , int V_42 ,
void * V_43 )
{
char * type = F_14 ( V_40 , L_4 , NULL ) ;
T_2 * V_44 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_44 = F_14 ( V_40 , L_23 , NULL ) ;
if ( V_44 != NULL ) {
V_90 = F_15 ( V_44 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
static unsigned long T_1 F_36 ( void )
{
unsigned long V_91 , V_92 , V_93 , V_14 ;
if ( V_90 == 0 )
F_17 ( F_35 , NULL ) ;
if ( V_90 )
return 1UL << V_90 ;
V_91 = F_33 () ;
V_92 = 1UL << F_37 ( V_91 ) ;
if ( V_92 < V_91 )
V_92 <<= 1 ;
V_14 = V_21 [ V_82 ] . V_19 ;
V_93 = F_38 ( V_92 >> ( V_14 + 1 ) , 1UL << 11 ) ;
return V_93 << 7 ;
}
int F_39 ( unsigned long V_94 , unsigned long V_95 )
{
return F_2 ( V_94 , V_95 , F_40 ( V_94 ) ,
F_41 ( V_96 ) , V_81 ,
V_97 ) ;
}
int F_42 ( unsigned long V_94 , unsigned long V_95 )
{
return F_11 ( V_94 , V_95 , V_81 ,
V_97 ) ;
}
static void T_1 F_43 ( void )
{
extern unsigned int * V_98 ;
extern unsigned int * V_99 ;
extern unsigned int * V_100 ;
extern unsigned int * V_101 ;
#ifdef F_44
extern unsigned int * V_102 ;
extern unsigned int * V_103 ;
extern unsigned int * V_104 ;
extern unsigned int * V_105 ;
F_45 ( V_102 ,
F_46 ( V_31 . V_32 ) ,
V_106 ) ;
F_45 ( V_103 ,
F_46 ( V_31 . V_32 ) ,
V_106 ) ;
F_45 ( V_104 ,
F_46 ( V_31 . V_107 ) ,
V_106 ) ;
F_45 ( V_105 ,
F_46 ( V_31 . V_108 ) ,
V_106 ) ;
#endif
F_45 ( V_98 ,
F_46 ( V_31 . V_32 ) ,
V_106 ) ;
F_45 ( V_99 ,
F_46 ( V_31 . V_32 ) ,
V_106 ) ;
F_45 ( V_100 ,
F_46 ( V_31 . V_107 ) ,
V_106 ) ;
F_45 ( V_101 ,
F_46 ( V_31 . V_108 ) ,
V_106 ) ;
}
static void T_1 F_47 ( void )
{
unsigned long V_109 ;
unsigned long V_93 ;
unsigned long V_13 ;
unsigned long V_110 = 0 , V_45 = 0 , V_111 ;
struct V_112 * V_113 ;
F_3 ( L_24 ) ;
F_16 () ;
F_28 () ;
if ( F_29 ( V_48 ) ) {
V_97 = V_114 ;
V_115 = V_114 ;
F_12 ( V_73 L_25 ) ;
}
V_116 = F_36 () ;
V_93 = V_116 >> 7 ;
V_29 = V_93 - 1 ;
if ( F_48 ( V_117 ) ) {
V_118 = NULL ;
V_119 = 0 ;
#ifdef F_49
if ( F_50 () && V_31 . V_120 )
V_31 . V_120 () ;
#endif
} else {
if ( F_31 ( V_121 ) )
V_111 = 0x80000000 ;
else
V_111 = V_122 ;
V_109 = F_51 ( V_116 , V_116 , V_111 ) ;
F_3 ( L_26 , V_109 ,
V_116 ) ;
V_118 = F_52 ( V_109 ) ;
V_119 = V_109 + F_37 ( V_93 ) - 11 ;
memset ( ( void * ) V_109 , 0 , V_116 ) ;
F_53 ( V_123 , V_119 ) ;
}
V_13 = F_41 ( V_96 ) ;
#ifdef F_10
V_35 = F_24 () >> V_34 ;
V_36 = F_52 ( F_51 ( V_35 ,
1 , V_124 ) ) ;
memset ( V_36 , 0 , V_35 ) ;
#endif
F_54 (memory, reg) {
V_110 = ( unsigned long ) F_52 ( V_113 -> V_110 ) ;
V_45 = V_113 -> V_45 ;
F_3 ( L_27 ,
V_110 , V_45 , V_13 ) ;
#ifdef F_55
F_3 ( L_28 , V_125 ) ;
if ( V_125 != 0 && V_125 >= V_110
&& V_125 < ( V_110 + V_45 ) ) {
unsigned long V_126 = V_125 + 16 * V_127 ;
if ( V_110 != V_125 )
F_9 ( F_2 ( V_110 , V_125 ,
F_40 ( V_110 ) , V_13 ,
V_81 ,
V_97 ) ) ;
if ( ( V_110 + V_45 ) > V_126 )
F_9 ( F_2 ( V_125 + 16 * V_127 ,
V_110 + V_45 ,
F_40 ( V_126 ) ,
V_13 ,
V_81 ,
V_97 ) ) ;
continue;
}
#endif
F_9 ( F_2 ( V_110 , V_110 + V_45 , F_40 ( V_110 ) ,
V_13 , V_81 , V_97 ) ) ;
}
F_56 ( V_122 ) ;
if ( V_128 ) {
V_128 = ( unsigned long ) F_52 ( V_128 ) ;
V_129 = ( unsigned long ) F_52 ( V_129 ) ;
if ( V_110 + V_45 >= V_128 )
V_128 = V_110 + V_45 + 1 ;
F_9 ( F_2 ( V_128 , V_129 ,
F_40 ( V_128 ) , V_13 ,
V_81 , V_97 ) ) ;
}
F_43 () ;
F_3 ( L_29 ) ;
}
void T_1 F_57 ( void )
{
F_58 () -> V_130 = F_40 ( ( V_131 ) & V_132 ) ;
F_58 () -> V_133 = ( V_131 ) & V_132 ;
F_47 () ;
if ( F_29 ( V_134 ) )
F_59 () ;
else
F_60 ( F_58 () -> V_130 ) ;
}
void F_61 ( void )
{
if ( ! F_48 ( V_117 ) )
F_53 ( V_123 , V_119 ) ;
if ( F_29 ( V_134 ) )
F_59 () ;
else
F_60 ( F_58 () -> V_133 ) ;
}
unsigned int F_62 ( unsigned int V_135 , T_4 V_136 , int V_137 )
{
struct V_138 * V_138 ;
if ( ! F_63 ( F_64 ( V_136 ) ) )
return V_135 ;
V_138 = F_65 ( V_136 ) ;
if ( ! F_66 ( V_139 , & V_138 -> V_140 ) && ! F_67 ( V_138 ) ) {
if ( V_137 == 0x400 ) {
F_68 ( V_138 ) ;
F_69 ( V_139 , & V_138 -> V_140 ) ;
} else
V_135 |= V_4 ;
}
return V_135 ;
}
unsigned int F_70 ( unsigned long V_141 )
{
V_131 V_142 ;
unsigned char * V_143 ;
unsigned long V_144 , V_145 ;
if ( V_141 < V_146 ) {
V_142 = F_58 () -> V_147 . V_148 ;
V_144 = F_71 ( V_141 ) ;
return ( V_142 >> ( V_144 * 4 ) ) & 0xF ;
}
V_143 = F_58 () -> V_147 . V_149 ;
V_144 = F_72 ( V_141 ) ;
V_145 = V_144 & 0x1 ;
return ( V_143 [ V_144 >> 1 ] >> ( V_145 * 4 ) ) & 0xF ;
}
unsigned int F_70 ( unsigned long V_141 )
{
return F_58 () -> V_147 . V_150 ;
}
void F_73 ( struct V_151 * V_152 , unsigned long V_141 )
{
if ( F_74 ( V_152 , V_141 ) == V_51 )
return;
F_75 ( V_152 , V_141 , 1 , V_51 ) ;
#ifdef F_76
F_77 ( V_152 ) ;
#endif
if ( F_70 ( V_141 ) != V_51 ) {
F_58 () -> V_147 = V_152 -> V_147 ;
F_78 () ;
}
}
static int F_79 ( struct V_151 * V_152 , unsigned long V_153 )
{
struct V_154 * V_155 = & V_152 -> V_147 . V_155 ;
T_5 V_156 = 0 ;
T_5 * * V_157 , * V_158 ;
if ( V_153 >= V_155 -> V_159 )
return 0 ;
if ( V_153 < 0x100000000UL ) {
V_157 = V_155 -> V_160 ;
} else {
V_157 = V_155 -> V_161 [ V_153 >> V_162 ] ;
if ( ! V_157 )
return 0 ;
}
V_158 = V_157 [ ( V_153 >> V_163 ) & ( V_164 - 1 ) ] ;
if ( ! V_158 )
return 0 ;
V_156 = V_158 [ ( V_153 >> V_34 ) & ( V_165 - 1 ) ] ;
V_156 >>= 30 - 2 * ( ( V_153 >> 12 ) & 0xf ) ;
V_156 = ( ( V_156 & 2 ) ? V_5 : 0 ) | ( ( V_156 & 1 ) ? V_6 : 0 ) ;
return V_156 ;
}
static inline int F_79 ( struct V_151 * V_152 , unsigned long V_153 )
{
return 0 ;
}
void F_80 ( unsigned long V_153 , unsigned long V_166 ,
unsigned long V_24 , unsigned long V_137 ,
int V_15 , int V_14 , int V_167 , unsigned long V_136 )
{
if ( ! F_81 () )
return;
F_20 ( L_30 ,
V_153 , V_166 , V_168 -> V_169 ) ;
F_20 ( L_31 ,
V_137 , V_24 , V_15 , V_14 , V_167 , V_136 ) ;
}
int F_82 ( unsigned long V_153 , unsigned long V_166 , unsigned long V_137 )
{
enum V_170 V_171 = F_83 () ;
T_6 * V_172 ;
unsigned long V_24 ;
struct V_151 * V_152 ;
T_4 * V_173 ;
unsigned V_174 ;
const struct V_175 * V_176 ;
int V_77 , V_177 = 0 , V_178 = 0 ;
int V_14 , V_15 ;
F_84 ( L_32 ,
V_153 , V_166 , V_137 ) ;
switch ( F_85 ( V_153 ) ) {
case V_179 :
V_177 = 1 ;
V_152 = V_168 -> V_152 ;
if ( ! V_152 ) {
F_84 ( L_33 ) ;
V_77 = 1 ;
goto V_180;
}
V_14 = F_74 ( V_152 , V_153 ) ;
V_15 = F_86 ( V_153 ) ;
V_24 = F_87 ( V_152 -> V_147 . V_181 , V_153 , V_15 ) ;
break;
case V_182 :
V_152 = & V_183 ;
V_24 = F_4 ( V_153 , V_97 ) ;
if ( V_153 < V_184 )
V_14 = V_83 ;
else
V_14 = V_86 ;
V_15 = V_97 ;
break;
default:
V_77 = 1 ;
goto V_180;
}
F_84 ( L_34 , V_152 , V_152 -> V_185 , V_24 ) ;
if ( ! V_24 ) {
F_84 ( L_35 ) ;
V_77 = 1 ;
goto V_180;
}
V_172 = V_152 -> V_185 ;
if ( V_172 == NULL ) {
V_77 = 1 ;
goto V_180;
}
V_176 = F_88 ( F_89 () ) ;
if ( V_177 && F_90 ( F_91 ( V_152 ) , V_176 ) )
V_178 = 1 ;
#ifndef F_30
if ( V_14 != V_51 )
V_153 &= ~ ( ( 1ul << V_21 [ V_14 ] . V_19 ) - 1 ) ;
#endif
V_173 = F_92 ( V_172 , V_153 , & V_174 ) ;
if ( V_173 == NULL || ! F_93 ( * V_173 ) ) {
F_84 ( L_36 ) ;
V_77 = 1 ;
goto V_180;
}
V_166 |= V_186 ;
if ( V_166 & ~ F_94 ( * V_173 ) ) {
F_84 ( L_37 ) ;
V_77 = 1 ;
goto V_180;
}
if ( V_174 ) {
if ( F_95 ( * ( V_187 * ) V_173 ) )
V_77 = F_96 ( V_153 , V_166 , V_24 , ( V_187 * ) V_173 ,
V_137 , V_178 , V_15 , V_14 ) ;
#ifdef F_34
else
V_77 = F_97 ( V_153 , V_166 , V_24 , V_173 , V_137 ,
V_178 , V_15 , V_174 , V_14 ) ;
#else
else {
V_77 = 1 ;
F_98 ( 1 ) ;
}
#endif
goto V_180;
}
#ifndef F_30
F_84 ( L_38 , F_94 ( * V_173 ) ) ;
#else
F_84 ( L_39 , F_94 ( * V_173 ) ,
F_94 ( * ( V_173 + V_188 ) ) ) ;
#endif
#ifdef F_30
if ( ( F_94 ( * V_173 ) & V_189 ) && V_14 == V_52 ) {
F_73 ( V_152 , V_153 ) ;
V_14 = V_51 ;
}
if ( V_87 && V_14 == V_52 &&
( F_94 ( * V_173 ) & V_190 ) ) {
if ( V_177 ) {
F_73 ( V_152 , V_153 ) ;
V_14 = V_51 ;
} else if ( V_153 < V_184 ) {
F_12 ( V_191 L_40
L_41
L_42 ) ;
V_14 = V_83 = V_51 ;
#ifdef F_76
F_77 ( V_152 ) ;
#endif
}
}
if ( V_177 ) {
if ( V_14 != F_70 ( V_153 ) ) {
F_58 () -> V_147 = V_152 -> V_147 ;
F_78 () ;
}
} else if ( F_58 () -> V_192 !=
V_21 [ V_83 ] . V_64 ) {
F_58 () -> V_192 =
V_21 [ V_83 ] . V_64 ;
F_99 () ;
}
#endif
#ifdef F_44
if ( V_14 == V_52 )
V_77 = F_100 ( V_153 , V_166 , V_24 , V_173 , V_137 , V_178 , V_15 ) ;
else
#endif
{
int V_156 = F_79 ( V_152 , V_153 ) ;
if ( V_166 & V_156 )
V_77 = - 2 ;
else
V_77 = F_101 ( V_153 , V_166 , V_24 , V_173 , V_137 ,
V_178 , V_15 , V_156 ) ;
}
if ( V_77 == - 1 )
F_80 ( V_153 , V_166 , V_24 , V_137 , V_15 , V_14 ,
V_14 , F_94 ( * V_173 ) ) ;
#ifndef F_30
F_84 ( L_43 , F_94 ( * V_173 ) ) ;
#else
F_84 ( L_44 , F_94 ( * V_173 ) ,
F_94 ( * ( V_173 + V_188 ) ) ) ;
#endif
F_84 ( L_45 , V_77 ) ;
V_180:
F_102 ( V_171 ) ;
return V_77 ;
}
void F_103 ( struct V_151 * V_152 , unsigned long V_153 ,
unsigned long V_166 , unsigned long V_137 )
{
int V_193 ;
unsigned long V_24 ;
T_6 * V_172 ;
T_4 * V_173 ;
unsigned long V_140 ;
int V_77 , V_15 , V_178 = 0 ;
F_9 ( F_85 ( V_153 ) != V_179 ) ;
#ifdef F_104
if ( F_105 ( F_74 ( V_152 , V_153 ) != V_152 -> V_147 . V_150 ) )
return;
#endif
F_84 ( L_46
L_47 , V_152 , V_152 -> V_185 , V_153 , V_166 , V_137 ) ;
V_172 = V_152 -> V_185 ;
if ( V_172 == NULL )
return;
V_15 = F_86 ( V_153 ) ;
V_24 = F_87 ( V_152 -> V_147 . V_181 , V_153 , V_15 ) ;
if ( ! V_24 )
return;
F_106 ( V_140 ) ;
V_173 = F_92 ( V_172 , V_153 , & V_193 ) ;
if ( ! V_173 )
goto V_194;
F_98 ( V_193 ) ;
#ifdef F_30
if ( F_94 ( * V_173 ) & ( V_189 | V_190 ) )
goto V_194;
#endif
if ( F_90 ( F_91 ( V_152 ) , F_88 ( F_89 () ) ) )
V_178 = 1 ;
#ifdef F_44
if ( V_152 -> V_147 . V_150 == V_52 )
V_77 = F_100 ( V_153 , V_166 , V_24 , V_173 , V_137 , V_178 , V_15 ) ;
else
#endif
V_77 = F_101 ( V_153 , V_166 , V_24 , V_173 , V_137 , V_178 , V_15 ,
F_79 ( V_152 , V_153 ) ) ;
if ( V_77 == - 1 )
F_80 ( V_153 , V_166 , V_24 , V_137 , V_15 ,
V_152 -> V_147 . V_150 ,
V_152 -> V_147 . V_150 ,
F_94 ( * V_173 ) ) ;
V_194:
F_107 ( V_140 ) ;
}
void F_108 ( unsigned long V_25 , T_7 V_136 , int V_14 , int V_15 ,
int V_178 )
{
unsigned long V_22 , V_144 , V_19 , V_195 , V_196 ;
F_84 ( L_48 , V_25 ) ;
F_109 (pte, psize, vpn, index, shift) {
V_22 = F_8 ( V_25 , V_19 , V_15 ) ;
V_195 = F_110 ( V_136 , V_144 ) ;
if ( V_195 & V_197 )
V_22 = ~ V_22 ;
V_196 = ( V_22 & V_29 ) * V_30 ;
V_196 += V_195 & V_198 ;
F_84 ( L_49 , V_144 , V_196 , V_195 ) ;
V_31 . V_199 ( V_196 , V_25 , V_14 , V_14 , V_15 , V_178 ) ;
} F_111 () ;
#ifdef F_112
if ( V_178 && F_113 ( V_200 ) &&
V_168 -> V_201 . V_202 &&
F_114 ( V_168 -> V_201 . V_202 -> V_203 ) ) {
F_115 () ;
F_116 ( V_204 ) ;
}
#endif
}
void F_117 ( unsigned long V_205 , int V_178 )
{
if ( V_31 . F_117 )
V_31 . F_117 ( V_205 , V_178 ) ;
else {
int V_206 ;
struct V_207 * V_208 =
& F_118 ( V_207 ) ;
for ( V_206 = 0 ; V_206 < V_205 ; V_206 ++ )
F_108 ( V_208 -> V_25 [ V_206 ] , V_208 -> V_136 [ V_206 ] ,
V_208 -> V_14 , V_208 -> V_15 , V_178 ) ;
}
}
void F_119 ( struct V_209 * V_202 , unsigned long V_210 , int V_77 )
{
enum V_170 V_171 = F_83 () ;
if ( F_120 ( V_202 ) ) {
#ifdef F_121
if ( V_77 == - 2 )
F_122 ( V_211 , V_202 , V_212 , V_210 ) ;
else
#endif
F_122 ( V_213 , V_202 , V_214 , V_210 ) ;
} else
F_123 ( V_202 , V_210 , V_213 ) ;
F_102 ( V_171 ) ;
}
long F_124 ( unsigned long V_22 , unsigned long V_25 ,
unsigned long V_215 , unsigned long V_2 ,
unsigned long V_216 , int V_14 , int V_15 )
{
unsigned long V_217 ;
long V_196 ;
V_218:
V_217 = ( ( V_22 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_196 = V_31 . V_32 ( V_217 , V_25 , V_215 , V_2 , V_216 ,
V_14 , V_14 , V_15 ) ;
if ( F_105 ( V_196 == - 1 ) ) {
V_217 = ( ( ~ V_22 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_196 = V_31 . V_32 ( V_217 , V_25 , V_215 , V_2 ,
V_216 | V_219 ,
V_14 , V_14 , V_15 ) ;
if ( V_196 == - 1 ) {
if ( F_125 () & 0x1 )
V_217 = ( ( V_22 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_31 . V_107 ( V_217 ) ;
goto V_218;
}
}
return V_196 ;
}
static void F_126 ( unsigned long V_16 , unsigned long V_220 )
{
unsigned long V_22 ;
unsigned long V_24 = F_4 ( V_16 , V_97 ) ;
unsigned long V_25 = F_5 ( V_16 , V_24 , V_97 ) ;
unsigned long V_221 = F_1 ( V_96 ) ;
long V_20 ;
V_22 = F_8 ( V_25 , V_34 , V_97 ) ;
if ( ! V_24 )
return;
V_20 = F_124 ( V_22 , V_25 , F_40 ( V_16 ) , V_221 ,
V_33 ,
V_81 , V_97 ) ;
F_9 ( V_20 < 0 ) ;
F_127 ( & V_222 ) ;
F_9 ( V_36 [ V_220 ] & 0x80 ) ;
V_36 [ V_220 ] = V_20 | 0x80 ;
F_128 ( & V_222 ) ;
}
static void F_129 ( unsigned long V_16 , unsigned long V_220 )
{
unsigned long V_22 , V_195 , V_196 ;
unsigned long V_24 = F_4 ( V_16 , V_97 ) ;
unsigned long V_25 = F_5 ( V_16 , V_24 , V_97 ) ;
V_22 = F_8 ( V_25 , V_34 , V_97 ) ;
F_127 ( & V_222 ) ;
F_9 ( ! ( V_36 [ V_220 ] & 0x80 ) ) ;
V_195 = V_36 [ V_220 ] & 0x7f ;
V_36 [ V_220 ] = 0 ;
F_128 ( & V_222 ) ;
if ( V_195 & V_197 )
V_22 = ~ V_22 ;
V_196 = ( V_22 & V_29 ) * V_30 ;
V_196 += V_195 & V_198 ;
V_31 . V_199 ( V_196 , V_25 , V_81 , V_81 ,
V_97 , 0 ) ;
}
void F_130 ( struct V_138 * V_138 , int V_223 , int V_224 )
{
unsigned long V_140 , V_16 , V_220 ;
int V_206 ;
F_106 ( V_140 ) ;
for ( V_206 = 0 ; V_206 < V_223 ; V_206 ++ , V_138 ++ ) {
V_16 = ( unsigned long ) F_131 ( V_138 ) ;
V_220 = F_40 ( V_16 ) >> V_34 ;
if ( V_220 >= V_35 )
continue;
if ( V_224 )
F_126 ( V_16 , V_220 ) ;
else
F_129 ( V_16 , V_220 ) ;
}
F_107 ( V_140 ) ;
}
void F_132 ( T_8 V_225 ,
T_8 V_226 )
{
F_9 ( V_225 != 0 ) ;
V_124 = F_133 ( V_131 , V_226 , 0x40000000 ) ;
F_56 ( V_124 ) ;
}
