static unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 = V_1 & 0x1fa ;
if ( ( V_1 & V_3 ) == 0 )
V_2 |= V_4 ;
if ( ( V_1 & V_5 ) && ! ( ( V_1 & V_6 ) &&
( V_1 & V_7 ) ) )
V_2 |= 1 ;
return V_2 | V_8 ;
}
int F_2 ( unsigned long V_9 , unsigned long V_10 ,
unsigned long V_11 , unsigned long V_12 ,
int V_13 , int V_14 )
{
unsigned long V_15 , V_16 ;
unsigned int V_17 , V_18 ;
int V_19 = 0 ;
V_18 = V_20 [ V_13 ] . V_18 ;
V_17 = 1 << V_18 ;
V_12 = F_1 ( V_12 ) ;
F_3 ( L_1 ,
V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ) ;
for ( V_15 = V_9 , V_16 = V_11 ; V_15 < V_10 ;
V_15 += V_17 , V_16 += V_17 ) {
unsigned long V_21 , V_22 ;
unsigned long V_23 = F_4 ( V_15 , V_14 ) ;
unsigned long V_24 = F_5 ( V_15 , V_23 , V_14 ) ;
unsigned long V_25 = V_12 ;
if ( ! V_23 )
return - 1 ;
if ( F_6 ( V_15 , V_15 + V_17 ) )
V_25 &= ~ V_4 ;
V_21 = F_7 ( V_24 , V_18 , V_14 ) ;
V_22 = ( ( V_21 & V_26 ) * V_27 ) ;
F_8 ( ! V_28 . V_29 ) ;
V_19 = V_28 . V_29 ( V_22 , V_24 , V_16 , V_25 ,
V_30 , V_13 , V_13 , V_14 ) ;
if ( V_19 < 0 )
break;
#ifdef F_9
if ( ( V_16 >> V_31 ) < V_32 )
V_33 [ V_16 >> V_31 ] = V_19 | 0x80 ;
#endif
}
return V_19 < 0 ? V_19 : 0 ;
}
static int F_10 ( unsigned long V_9 , unsigned long V_10 ,
int V_13 , int V_14 )
{
unsigned long V_15 ;
unsigned int V_17 , V_18 ;
V_18 = V_20 [ V_13 ] . V_18 ;
V_17 = 1 << V_18 ;
if ( ! V_28 . V_34 ) {
F_11 ( V_35 L_2
L_3 ) ;
return - V_36 ;
}
for ( V_15 = V_9 ; V_15 < V_10 ; V_15 += V_17 )
V_28 . V_34 ( V_15 , V_13 , V_14 ) ;
return 0 ;
}
static int T_1 F_12 ( unsigned long V_37 ,
const char * V_38 , int V_39 ,
void * V_40 )
{
char * type = F_13 ( V_37 , L_4 , NULL ) ;
T_2 * V_41 ;
unsigned long V_42 = 0 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_41 = ( T_2 * ) F_13 ( V_37 , L_6 ,
& V_42 ) ;
if ( V_41 == NULL )
return 0 ;
for (; V_42 >= 4 ; V_42 -= 4 , ++ V_41 ) {
if ( V_41 [ 0 ] == 40 ) {
F_3 ( L_7 ) ;
V_43 -> V_44 |= V_45 ;
return 1 ;
}
}
V_43 -> V_44 &= ~ V_46 ;
return 0 ;
}
static void T_1 F_14 ( void )
{
F_15 ( F_12 , NULL ) ;
}
static int T_1 F_16 ( unsigned int V_18 )
{
int V_47 = - 1 ;
switch ( V_18 ) {
case 0xc :
V_47 = V_48 ;
break;
case 0x10 :
V_47 = V_49 ;
break;
case 0x14 :
V_47 = V_50 ;
break;
case 0x18 :
V_47 = V_51 ;
break;
case 0x22 :
V_47 = V_52 ;
break;
}
return V_47 ;
}
static int T_1 F_17 ( unsigned long V_37 ,
const char * V_38 , int V_39 ,
void * V_40 )
{
char * type = F_13 ( V_37 , L_4 , NULL ) ;
T_2 * V_41 ;
unsigned long V_42 = 0 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_41 = ( T_2 * ) F_13 ( V_37 ,
L_8 , & V_42 ) ;
if ( V_41 != NULL ) {
F_18 ( L_9 ) ;
V_42 /= 4 ;
V_43 -> V_44 &= ~ ( V_53 ) ;
while( V_42 > 0 ) {
unsigned int V_54 = V_41 [ 0 ] ;
unsigned int V_55 = V_41 [ 1 ] ;
unsigned int V_56 = V_41 [ 2 ] ;
struct V_57 * V_58 ;
int V_47 , V_59 ;
V_42 -= 3 ; V_41 += 3 ;
V_59 = F_16 ( V_54 ) ;
if ( V_59 < 0 ) {
V_41 += V_56 * 2 ; V_42 -= V_56 * 2 ;
continue;
}
V_58 = & V_20 [ V_59 ] ;
if ( V_59 == V_51 )
V_43 -> V_44 |= V_53 ;
V_58 -> V_18 = V_54 ;
if ( V_54 <= 23 )
V_58 -> V_60 = 0 ;
else
V_58 -> V_60 = ( 1 << ( V_54 - 23 ) ) - 1 ;
V_58 -> V_61 = V_55 ;
if ( V_59 == V_48 || V_59 == V_49 )
V_58 -> V_62 = 1 ;
else
V_58 -> V_62 = 0 ;
while ( V_42 > 0 && V_56 ) {
unsigned int V_18 = V_41 [ 0 ] ;
int V_63 = V_41 [ 1 ] ;
V_41 += 2 ; V_42 -= 2 ;
V_56 -- ;
V_47 = F_16 ( V_18 ) ;
if ( V_47 < 0 )
continue;
if ( V_63 == - 1 )
F_19 ( L_10
L_11 , V_54 , V_18 ) ;
V_58 -> V_63 [ V_47 ] = V_63 ;
F_18 ( L_12
L_13 ,
V_54 , V_18 , V_58 -> V_61 ,
V_58 -> V_60 , V_58 -> V_62 , V_58 -> V_63 [ V_47 ] ) ;
}
}
return 1 ;
}
return 0 ;
}
static int T_1 F_20 ( unsigned long V_37 ,
const char * V_38 , int V_39 ,
void * V_40 ) {
char * type = F_13 ( V_37 , L_4 , NULL ) ;
unsigned long * V_64 ;
T_2 * V_65 ;
unsigned int V_66 ;
long unsigned int V_67 ;
long unsigned int V_68 ;
if ( type == NULL || strcmp ( type , L_14 ) != 0 )
return 0 ;
V_65 = F_13 ( V_37 , L_15 , NULL ) ;
if ( V_65 == NULL )
return 0 ;
V_66 = ( 1 << V_65 [ 0 ] ) ;
V_64 = F_13 ( V_37 , L_16 , NULL ) ;
if ( V_64 == NULL )
return 0 ;
V_67 = V_64 [ 0 ] ;
V_68 = V_64 [ 1 ] ;
if ( V_68 != ( 16 * V_69 ) )
return 0 ;
F_11 ( V_70 L_17
L_18 ,
V_67 , V_68 , V_66 ) ;
if ( V_67 + ( 16 * V_69 ) <= F_21 () ) {
F_22 ( V_67 , V_68 * V_66 ) ;
F_23 ( V_67 , V_68 , V_66 ) ;
}
return 0 ;
}
static void F_24 ( void )
{
int V_71 , V_72 ;
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ )
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ )
V_20 [ V_71 ] . V_63 [ V_72 ] = - 1 ;
}
static void T_1 F_25 ( void )
{
int V_74 ;
F_24 () ;
memcpy ( V_20 , V_75 ,
sizeof( V_75 ) ) ;
V_74 = F_15 ( F_17 , NULL ) ;
if ( V_74 != 0 )
goto V_76;
if ( F_26 ( V_53 ) )
memcpy ( V_20 , V_77 ,
sizeof( V_77 ) ) ;
V_76:
#ifndef F_9
if ( V_20 [ V_51 ] . V_18 )
V_78 = V_51 ;
else if ( V_20 [ V_50 ] . V_18 )
V_78 = V_50 ;
#endif
#ifdef F_27
if ( V_20 [ V_49 ] . V_18 ) {
V_79 = V_49 ;
V_80 = V_49 ;
if ( V_78 == V_48 )
V_78 = V_49 ;
if ( F_26 ( V_81 ) ) {
if ( ! F_28 ( V_82 ) )
V_83 = V_49 ;
} else
V_84 = 1 ;
}
#endif
#ifdef F_29
if ( V_20 [ V_51 ] . V_18 &&
F_30 () >= 0x40000000 )
V_85 = V_51 ;
else if ( V_20 [ V_49 ] . V_18 )
V_85 = V_49 ;
else
V_85 = V_48 ;
#endif
F_11 ( V_86 L_19
L_20
#ifdef F_29
L_21
#endif
L_22 ,
V_20 [ V_78 ] . V_18 ,
V_20 [ V_79 ] . V_18 ,
V_20 [ V_83 ] . V_18
#ifdef F_29
, V_20 [ V_85 ] . V_18
#endif
) ;
#ifdef F_31
F_15 ( F_20 , NULL ) ;
#endif
}
static int T_1 F_32 ( unsigned long V_37 ,
const char * V_38 , int V_39 ,
void * V_40 )
{
char * type = F_13 ( V_37 , L_4 , NULL ) ;
T_2 * V_41 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_41 = ( T_2 * ) F_13 ( V_37 , L_23 , NULL ) ;
if ( V_41 != NULL ) {
V_87 = V_41 [ 1 ] ;
return 1 ;
}
return 0 ;
}
static unsigned long T_1 F_33 ( void )
{
unsigned long V_88 , V_89 , V_90 , V_13 ;
if ( V_87 == 0 )
F_15 ( F_32 , NULL ) ;
if ( V_87 )
return 1UL << V_87 ;
V_88 = F_30 () ;
V_89 = 1UL << F_34 ( V_88 ) ;
if ( V_89 < V_88 )
V_89 <<= 1 ;
V_13 = V_20 [ V_79 ] . V_18 ;
V_90 = F_35 ( V_89 >> ( V_13 + 1 ) , 1UL << 11 ) ;
return V_90 << 7 ;
}
int F_36 ( unsigned long V_91 , unsigned long V_92 )
{
return F_2 ( V_91 , V_92 , F_37 ( V_91 ) ,
F_38 ( V_93 ) , V_78 ,
V_94 ) ;
}
int F_39 ( unsigned long V_91 , unsigned long V_92 )
{
return F_10 ( V_91 , V_92 , V_78 ,
V_94 ) ;
}
static void T_1 F_40 ( void )
{
extern unsigned int * V_95 ;
extern unsigned int * V_96 ;
extern unsigned int * V_97 ;
extern unsigned int * V_98 ;
#ifdef F_41
extern unsigned int * V_99 ;
extern unsigned int * V_100 ;
extern unsigned int * V_101 ;
extern unsigned int * V_102 ;
F_42 ( V_99 ,
F_43 ( V_28 . V_29 ) ,
V_103 ) ;
F_42 ( V_100 ,
F_43 ( V_28 . V_29 ) ,
V_103 ) ;
F_42 ( V_101 ,
F_43 ( V_28 . V_104 ) ,
V_103 ) ;
F_42 ( V_102 ,
F_43 ( V_28 . V_105 ) ,
V_103 ) ;
#endif
F_42 ( V_95 ,
F_43 ( V_28 . V_29 ) ,
V_103 ) ;
F_42 ( V_96 ,
F_43 ( V_28 . V_29 ) ,
V_103 ) ;
F_42 ( V_97 ,
F_43 ( V_28 . V_104 ) ,
V_103 ) ;
F_42 ( V_98 ,
F_43 ( V_28 . V_105 ) ,
V_103 ) ;
}
static void T_1 F_44 ( void )
{
unsigned long V_106 ;
unsigned long V_90 ;
unsigned long V_12 ;
unsigned long V_107 = 0 , V_42 = 0 , V_108 ;
struct V_109 * V_110 ;
F_3 ( L_24 ) ;
F_14 () ;
F_25 () ;
if ( F_26 ( V_45 ) ) {
V_94 = V_111 ;
V_112 = V_111 ;
F_11 ( V_70 L_25 ) ;
}
V_113 = F_33 () ;
V_90 = V_113 >> 7 ;
V_26 = V_90 - 1 ;
if ( F_45 ( V_114 ) ) {
V_115 = NULL ;
V_116 = 0 ;
#ifdef F_46
if ( F_47 () && V_28 . V_117 )
V_28 . V_117 () ;
#endif
} else {
if ( F_28 ( V_118 ) )
V_108 = 0x80000000 ;
else
V_108 = V_119 ;
V_106 = F_48 ( V_113 , V_113 , V_108 ) ;
F_3 ( L_26 , V_106 ,
V_113 ) ;
V_115 = F_49 ( V_106 ) ;
V_116 = V_106 + F_34 ( V_90 ) - 11 ;
memset ( ( void * ) V_106 , 0 , V_113 ) ;
F_50 ( V_120 , V_116 ) ;
}
V_12 = F_38 ( V_93 ) ;
#ifdef F_9
V_32 = F_21 () >> V_31 ;
V_33 = F_49 ( F_48 ( V_32 ,
1 , V_121 ) ) ;
memset ( V_33 , 0 , V_32 ) ;
#endif
F_51 (memory, reg) {
V_107 = ( unsigned long ) F_49 ( V_110 -> V_107 ) ;
V_42 = V_110 -> V_42 ;
F_3 ( L_27 ,
V_107 , V_42 , V_12 ) ;
#ifdef F_52
F_3 ( L_28 , V_122 ) ;
if ( V_122 != 0 && V_122 >= V_107
&& V_122 < ( V_107 + V_42 ) ) {
unsigned long V_123 = V_122 + 16 * V_124 ;
if ( V_107 != V_122 )
F_8 ( F_2 ( V_107 , V_122 ,
F_37 ( V_107 ) , V_12 ,
V_78 ,
V_94 ) ) ;
if ( ( V_107 + V_42 ) > V_123 )
F_8 ( F_2 ( V_122 + 16 * V_124 ,
V_107 + V_42 ,
F_37 ( V_123 ) ,
V_12 ,
V_78 ,
V_94 ) ) ;
continue;
}
#endif
F_8 ( F_2 ( V_107 , V_107 + V_42 , F_37 ( V_107 ) ,
V_12 , V_78 , V_94 ) ) ;
}
F_53 ( V_119 ) ;
if ( V_125 ) {
V_125 = ( unsigned long ) F_49 ( V_125 ) ;
V_126 = ( unsigned long ) F_49 ( V_126 ) ;
if ( V_107 + V_42 >= V_125 )
V_125 = V_107 + V_42 + 1 ;
F_8 ( F_2 ( V_125 , V_126 ,
F_37 ( V_125 ) , V_12 ,
V_78 , V_94 ) ) ;
}
F_40 () ;
F_3 ( L_29 ) ;
}
void T_1 F_54 ( void )
{
F_55 () -> V_127 = F_37 ( ( V_128 ) & V_129 ) ;
F_55 () -> V_130 = ( V_128 ) & V_129 ;
F_44 () ;
if ( F_26 ( V_131 ) )
F_56 () ;
else
F_57 ( F_55 () -> V_127 ) ;
}
void F_58 ( void )
{
if ( ! F_45 ( V_114 ) )
F_50 ( V_120 , V_116 ) ;
if ( F_26 ( V_131 ) )
F_56 () ;
else
F_57 ( F_55 () -> V_130 ) ;
}
unsigned int F_59 ( unsigned int V_132 , T_3 V_133 , int V_134 )
{
struct V_135 * V_135 ;
if ( ! F_60 ( F_61 ( V_133 ) ) )
return V_132 ;
V_135 = F_62 ( V_133 ) ;
if ( ! F_63 ( V_136 , & V_135 -> V_137 ) && ! F_64 ( V_135 ) ) {
if ( V_134 == 0x400 ) {
F_65 ( V_135 ) ;
F_66 ( V_136 , & V_135 -> V_137 ) ;
} else
V_132 |= V_4 ;
}
return V_132 ;
}
unsigned int F_67 ( unsigned long V_138 )
{
V_128 V_139 ;
unsigned char * V_140 ;
unsigned long V_141 , V_142 ;
if ( V_138 < V_143 ) {
V_139 = F_55 () -> V_144 . V_145 ;
V_141 = F_68 ( V_138 ) ;
return ( V_139 >> ( V_141 * 4 ) ) & 0xF ;
}
V_140 = F_55 () -> V_144 . V_146 ;
V_141 = F_69 ( V_138 ) ;
V_142 = V_141 & 0x1 ;
return ( V_140 [ V_141 >> 1 ] >> ( V_142 * 4 ) ) & 0xF ;
}
unsigned int F_67 ( unsigned long V_138 )
{
return F_55 () -> V_144 . V_147 ;
}
void F_70 ( struct V_148 * V_149 , unsigned long V_138 )
{
if ( F_71 ( V_149 , V_138 ) == V_48 )
return;
F_72 ( V_149 , V_138 , 1 , V_48 ) ;
#ifdef F_73
F_74 ( V_149 ) ;
#endif
if ( F_67 ( V_138 ) != V_48 ) {
F_55 () -> V_144 = V_149 -> V_144 ;
F_75 () ;
}
}
static int F_76 ( struct V_148 * V_149 , unsigned long V_150 )
{
struct V_151 * V_152 = & V_149 -> V_144 . V_152 ;
T_2 V_153 = 0 ;
T_2 * * V_154 , * V_155 ;
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
V_153 = V_155 [ ( V_150 >> V_31 ) & ( V_162 - 1 ) ] ;
V_153 >>= 30 - 2 * ( ( V_150 >> 12 ) & 0xf ) ;
V_153 = ( ( V_153 & 2 ) ? V_5 : 0 ) | ( ( V_153 & 1 ) ? V_6 : 0 ) ;
return V_153 ;
}
static inline int F_76 ( struct V_148 * V_149 , unsigned long V_150 )
{
return 0 ;
}
void F_77 ( unsigned long V_150 , unsigned long V_163 ,
unsigned long V_23 , unsigned long V_134 ,
int V_14 , int V_13 , int V_164 , unsigned long V_133 )
{
if ( ! F_78 () )
return;
F_18 ( L_30 ,
V_150 , V_163 , V_165 -> V_166 ) ;
F_18 ( L_31 ,
V_134 , V_23 , V_14 , V_13 , V_164 , V_133 ) ;
}
int F_79 ( unsigned long V_150 , unsigned long V_163 , unsigned long V_134 )
{
enum V_167 V_168 = F_80 () ;
T_4 * V_169 ;
unsigned long V_23 ;
struct V_148 * V_149 ;
T_3 * V_170 ;
unsigned V_171 ;
const struct V_172 * V_173 ;
int V_74 , V_174 = 0 , V_175 = 0 ;
int V_13 , V_14 ;
F_81 ( L_32 ,
V_150 , V_163 , V_134 ) ;
switch ( F_82 ( V_150 ) ) {
case V_176 :
V_174 = 1 ;
V_149 = V_165 -> V_149 ;
if ( ! V_149 ) {
F_81 ( L_33 ) ;
V_74 = 1 ;
goto V_177;
}
V_13 = F_71 ( V_149 , V_150 ) ;
V_14 = F_83 ( V_150 ) ;
V_23 = F_84 ( V_149 -> V_144 . V_178 , V_150 , V_14 ) ;
break;
case V_179 :
V_149 = & V_180 ;
V_23 = F_4 ( V_150 , V_94 ) ;
if ( V_150 < V_181 )
V_13 = V_80 ;
else
V_13 = V_83 ;
V_14 = V_94 ;
break;
default:
V_74 = 1 ;
goto V_177;
}
F_81 ( L_34 , V_149 , V_149 -> V_182 , V_23 ) ;
if ( ! V_23 ) {
F_81 ( L_35 ) ;
V_74 = 1 ;
goto V_177;
}
V_169 = V_149 -> V_182 ;
if ( V_169 == NULL ) {
V_74 = 1 ;
goto V_177;
}
V_173 = F_85 ( F_86 () ) ;
if ( V_174 && F_87 ( F_88 ( V_149 ) , V_173 ) )
V_175 = 1 ;
#ifndef F_27
if ( V_13 != V_48 )
V_150 &= ~ ( ( 1ul << V_20 [ V_13 ] . V_18 ) - 1 ) ;
#endif
V_170 = F_89 ( V_169 , V_150 , & V_171 ) ;
if ( V_170 == NULL || ! F_90 ( * V_170 ) ) {
F_81 ( L_36 ) ;
V_74 = 1 ;
goto V_177;
}
V_163 |= V_183 ;
if ( V_163 & ~ F_91 ( * V_170 ) ) {
F_81 ( L_37 ) ;
V_74 = 1 ;
goto V_177;
}
if ( V_171 ) {
if ( F_92 ( * ( V_184 * ) V_170 ) )
V_74 = F_93 ( V_150 , V_163 , V_23 , ( V_184 * ) V_170 ,
V_134 , V_175 , V_14 , V_13 ) ;
#ifdef F_31
else
V_74 = F_94 ( V_150 , V_163 , V_23 , V_170 , V_134 ,
V_175 , V_14 , V_171 , V_13 ) ;
#else
else {
V_74 = 1 ;
F_95 ( 1 ) ;
}
#endif
goto V_177;
}
#ifndef F_27
F_81 ( L_38 , F_91 ( * V_170 ) ) ;
#else
F_81 ( L_39 , F_91 ( * V_170 ) ,
F_91 ( * ( V_170 + V_185 ) ) ) ;
#endif
#ifdef F_27
if ( ( F_91 ( * V_170 ) & V_186 ) && V_13 == V_49 ) {
F_70 ( V_149 , V_150 ) ;
V_13 = V_48 ;
}
if ( V_84 && V_13 == V_49 &&
( F_91 ( * V_170 ) & V_187 ) ) {
if ( V_174 ) {
F_70 ( V_149 , V_150 ) ;
V_13 = V_48 ;
} else if ( V_150 < V_181 ) {
F_11 ( V_188 L_40
L_41
L_42 ) ;
V_13 = V_80 = V_48 ;
#ifdef F_73
F_74 ( V_149 ) ;
#endif
}
}
if ( V_174 ) {
if ( V_13 != F_67 ( V_150 ) ) {
F_55 () -> V_144 = V_149 -> V_144 ;
F_75 () ;
}
} else if ( F_55 () -> V_189 !=
V_20 [ V_80 ] . V_61 ) {
F_55 () -> V_189 =
V_20 [ V_80 ] . V_61 ;
F_96 () ;
}
#endif
#ifdef F_41
if ( V_13 == V_49 )
V_74 = F_97 ( V_150 , V_163 , V_23 , V_170 , V_134 , V_175 , V_14 ) ;
else
#endif
{
int V_153 = F_76 ( V_149 , V_150 ) ;
if ( V_163 & V_153 )
V_74 = - 2 ;
else
V_74 = F_98 ( V_150 , V_163 , V_23 , V_170 , V_134 ,
V_175 , V_14 , V_153 ) ;
}
if ( V_74 == - 1 )
F_77 ( V_150 , V_163 , V_23 , V_134 , V_14 , V_13 ,
V_13 , F_91 ( * V_170 ) ) ;
#ifndef F_27
F_81 ( L_43 , F_91 ( * V_170 ) ) ;
#else
F_81 ( L_44 , F_91 ( * V_170 ) ,
F_91 ( * ( V_170 + V_185 ) ) ) ;
#endif
F_81 ( L_45 , V_74 ) ;
V_177:
F_99 ( V_168 ) ;
return V_74 ;
}
void F_100 ( struct V_148 * V_149 , unsigned long V_150 ,
unsigned long V_163 , unsigned long V_134 )
{
int V_190 ;
unsigned long V_23 ;
T_4 * V_169 ;
T_3 * V_170 ;
unsigned long V_137 ;
int V_74 , V_14 , V_175 = 0 ;
F_8 ( F_82 ( V_150 ) != V_176 ) ;
#ifdef F_101
if ( F_102 ( F_71 ( V_149 , V_150 ) != V_149 -> V_144 . V_147 ) )
return;
#endif
F_81 ( L_46
L_47 , V_149 , V_149 -> V_182 , V_150 , V_163 , V_134 ) ;
V_169 = V_149 -> V_182 ;
if ( V_169 == NULL )
return;
V_14 = F_83 ( V_150 ) ;
V_23 = F_84 ( V_149 -> V_144 . V_178 , V_150 , V_14 ) ;
if ( ! V_23 )
return;
F_103 ( V_137 ) ;
V_170 = F_89 ( V_169 , V_150 , & V_190 ) ;
if ( ! V_170 )
goto V_191;
F_95 ( V_190 ) ;
#ifdef F_27
if ( F_91 ( * V_170 ) & ( V_186 | V_187 ) )
goto V_191;
#endif
if ( F_87 ( F_88 ( V_149 ) , F_85 ( F_86 () ) ) )
V_175 = 1 ;
#ifdef F_41
if ( V_149 -> V_144 . V_147 == V_49 )
V_74 = F_97 ( V_150 , V_163 , V_23 , V_170 , V_134 , V_175 , V_14 ) ;
else
#endif
V_74 = F_98 ( V_150 , V_163 , V_23 , V_170 , V_134 , V_175 , V_14 ,
F_76 ( V_149 , V_150 ) ) ;
if ( V_74 == - 1 )
F_77 ( V_150 , V_163 , V_23 , V_134 , V_14 ,
V_149 -> V_144 . V_147 ,
V_149 -> V_144 . V_147 ,
F_91 ( * V_170 ) ) ;
V_191:
F_104 ( V_137 ) ;
}
void F_105 ( unsigned long V_24 , T_5 V_133 , int V_13 , int V_14 ,
int V_175 )
{
unsigned long V_21 , V_141 , V_18 , V_192 , V_193 ;
F_81 ( L_48 , V_24 ) ;
F_106 (pte, psize, vpn, index, shift) {
V_21 = F_7 ( V_24 , V_18 , V_14 ) ;
V_192 = F_107 ( V_133 , V_141 ) ;
if ( V_192 & V_194 )
V_21 = ~ V_21 ;
V_193 = ( V_21 & V_26 ) * V_27 ;
V_193 += V_192 & V_195 ;
F_81 ( L_49 , V_141 , V_193 , V_192 ) ;
V_28 . V_196 ( V_193 , V_24 , V_13 , V_13 , V_14 , V_175 ) ;
} F_108 () ;
#ifdef F_109
if ( V_175 && F_110 ( V_197 ) &&
V_165 -> V_198 . V_199 &&
F_111 ( V_165 -> V_198 . V_199 -> V_200 ) ) {
F_112 () ;
F_113 ( V_201 ) ;
}
#endif
}
void F_114 ( unsigned long V_202 , int V_175 )
{
if ( V_28 . F_114 )
V_28 . F_114 ( V_202 , V_175 ) ;
else {
int V_203 ;
struct V_204 * V_205 =
& F_115 ( V_204 ) ;
for ( V_203 = 0 ; V_203 < V_202 ; V_203 ++ )
F_105 ( V_205 -> V_24 [ V_203 ] , V_205 -> V_133 [ V_203 ] ,
V_205 -> V_13 , V_205 -> V_14 , V_175 ) ;
}
}
void F_116 ( struct V_206 * V_199 , unsigned long V_207 , int V_74 )
{
enum V_167 V_168 = F_80 () ;
if ( F_117 ( V_199 ) ) {
#ifdef F_118
if ( V_74 == - 2 )
F_119 ( V_208 , V_199 , V_209 , V_207 ) ;
else
#endif
F_119 ( V_210 , V_199 , V_211 , V_207 ) ;
} else
F_120 ( V_199 , V_207 , V_210 ) ;
F_99 ( V_168 ) ;
}
long F_121 ( unsigned long V_21 , unsigned long V_24 ,
unsigned long V_212 , unsigned long V_2 ,
unsigned long V_213 , int V_13 , int V_14 )
{
unsigned long V_214 ;
long V_193 ;
V_215:
V_214 = ( ( V_21 & V_26 ) *
V_27 ) & ~ 0x7UL ;
V_193 = V_28 . V_29 ( V_214 , V_24 , V_212 , V_2 , V_213 ,
V_13 , V_13 , V_14 ) ;
if ( F_102 ( V_193 == - 1 ) ) {
V_214 = ( ( ~ V_21 & V_26 ) *
V_27 ) & ~ 0x7UL ;
V_193 = V_28 . V_29 ( V_214 , V_24 , V_212 , V_2 ,
V_213 | V_216 ,
V_13 , V_13 , V_14 ) ;
if ( V_193 == - 1 ) {
if ( F_122 () & 0x1 )
V_214 = ( ( V_21 & V_26 ) *
V_27 ) & ~ 0x7UL ;
V_28 . V_104 ( V_214 ) ;
goto V_215;
}
}
return V_193 ;
}
static void F_123 ( unsigned long V_15 , unsigned long V_217 )
{
unsigned long V_21 ;
unsigned long V_23 = F_4 ( V_15 , V_94 ) ;
unsigned long V_24 = F_5 ( V_15 , V_23 , V_94 ) ;
unsigned long V_218 = F_1 ( V_93 ) ;
long V_19 ;
V_21 = F_7 ( V_24 , V_31 , V_94 ) ;
if ( ! V_23 )
return;
V_19 = F_121 ( V_21 , V_24 , F_37 ( V_15 ) , V_218 ,
V_30 ,
V_78 , V_94 ) ;
F_8 ( V_19 < 0 ) ;
F_124 ( & V_219 ) ;
F_8 ( V_33 [ V_217 ] & 0x80 ) ;
V_33 [ V_217 ] = V_19 | 0x80 ;
F_125 ( & V_219 ) ;
}
static void F_126 ( unsigned long V_15 , unsigned long V_217 )
{
unsigned long V_21 , V_192 , V_193 ;
unsigned long V_23 = F_4 ( V_15 , V_94 ) ;
unsigned long V_24 = F_5 ( V_15 , V_23 , V_94 ) ;
V_21 = F_7 ( V_24 , V_31 , V_94 ) ;
F_124 ( & V_219 ) ;
F_8 ( ! ( V_33 [ V_217 ] & 0x80 ) ) ;
V_192 = V_33 [ V_217 ] & 0x7f ;
V_33 [ V_217 ] = 0 ;
F_125 ( & V_219 ) ;
if ( V_192 & V_194 )
V_21 = ~ V_21 ;
V_193 = ( V_21 & V_26 ) * V_27 ;
V_193 += V_192 & V_195 ;
V_28 . V_196 ( V_193 , V_24 , V_78 , V_78 ,
V_94 , 0 ) ;
}
void F_127 ( struct V_135 * V_135 , int V_220 , int V_221 )
{
unsigned long V_137 , V_15 , V_217 ;
int V_203 ;
F_103 ( V_137 ) ;
for ( V_203 = 0 ; V_203 < V_220 ; V_203 ++ , V_135 ++ ) {
V_15 = ( unsigned long ) F_128 ( V_135 ) ;
V_217 = F_37 ( V_15 ) >> V_31 ;
if ( V_217 >= V_32 )
continue;
if ( V_221 )
F_123 ( V_15 , V_217 ) ;
else
F_126 ( V_15 , V_217 ) ;
}
F_104 ( V_137 ) ;
}
void F_129 ( T_6 V_222 ,
T_6 V_223 )
{
F_8 ( V_222 != 0 ) ;
V_121 = F_130 ( V_128 , V_223 , 0x40000000 ) ;
F_53 ( V_121 ) ;
}
