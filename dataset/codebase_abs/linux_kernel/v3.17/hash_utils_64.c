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
if ( V_44 != NULL ) {
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
return 0 ;
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
#ifdef F_48
F_49 ( V_99 ,
F_50 ( V_31 . V_32 ) ,
V_100 ) ;
F_49 ( V_101 ,
F_50 ( V_31 . V_32 ) ,
V_100 ) ;
F_49 ( V_102 ,
F_50 ( V_31 . V_103 ) ,
V_100 ) ;
F_49 ( V_104 ,
F_50 ( V_31 . V_105 ) ,
V_100 ) ;
#endif
F_49 ( V_106 ,
F_50 ( V_31 . V_32 ) ,
V_100 ) ;
F_49 ( V_107 ,
F_50 ( V_31 . V_32 ) ,
V_100 ) ;
F_49 ( V_108 ,
F_50 ( V_31 . V_103 ) ,
V_100 ) ;
F_49 ( V_109 ,
F_50 ( V_31 . V_105 ) ,
V_100 ) ;
}
static void T_1 F_51 ( void )
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
if ( F_52 ( V_118 ) ) {
V_119 = NULL ;
V_120 = 0 ;
#ifdef F_53
if ( F_54 () && V_31 . V_121 )
V_31 . V_121 () ;
#endif
} else {
if ( F_35 ( V_122 ) )
V_112 = 0x80000000 ;
else
V_112 = V_123 ;
V_110 = F_55 ( V_117 , V_117 , V_112 ) ;
F_3 ( L_26 , V_110 ,
V_117 ) ;
V_119 = F_56 ( V_110 ) ;
V_120 = V_110 + F_41 ( V_94 ) - 11 ;
memset ( ( void * ) V_110 , 0 , V_117 ) ;
F_57 ( V_124 , V_120 ) ;
}
V_13 = F_45 ( V_97 ) ;
#ifdef F_11
V_35 = F_25 () >> V_34 ;
V_36 = F_56 ( F_55 ( V_35 ,
1 , V_125 ) ) ;
memset ( V_36 , 0 , V_35 ) ;
#endif
F_58 (memory, reg) {
V_111 = ( unsigned long ) F_56 ( V_114 -> V_111 ) ;
V_45 = V_114 -> V_45 ;
F_3 ( L_27 ,
V_111 , V_45 , V_13 ) ;
#ifdef F_59
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
F_60 ( V_123 ) ;
if ( V_129 ) {
V_129 = ( unsigned long ) F_56 ( V_129 ) ;
V_130 = ( unsigned long ) F_56 ( V_130 ) ;
if ( V_111 + V_45 >= V_129 )
V_129 = V_111 + V_45 + 1 ;
F_10 ( F_2 ( V_129 , V_130 ,
F_44 ( V_129 ) , V_13 ,
V_82 , V_98 ) ) ;
}
F_47 () ;
F_3 ( L_29 ) ;
}
void T_1 F_61 ( void )
{
F_51 () ;
F_62 () ;
}
void F_63 ( void )
{
if ( ! F_52 ( V_118 ) )
F_57 ( V_124 , V_120 ) ;
F_62 () ;
}
unsigned int F_64 ( unsigned int V_131 , T_4 V_132 , int V_133 )
{
struct V_134 * V_134 ;
if ( ! F_65 ( F_66 ( V_132 ) ) )
return V_131 ;
V_134 = F_67 ( V_132 ) ;
if ( ! F_68 ( V_135 , & V_134 -> V_136 ) && ! F_69 ( V_134 ) ) {
if ( V_133 == 0x400 ) {
F_70 ( V_134 ) ;
F_71 ( V_135 , & V_134 -> V_136 ) ;
} else
V_131 |= V_4 ;
}
return V_131 ;
}
unsigned int F_72 ( unsigned long V_137 )
{
T_5 V_138 ;
unsigned char * V_139 ;
unsigned long V_140 , V_141 ;
if ( V_137 < V_142 ) {
V_138 = F_73 () -> V_143 . V_144 ;
V_140 = F_74 ( V_137 ) ;
return ( V_138 >> ( V_140 * 4 ) ) & 0xF ;
}
V_139 = F_73 () -> V_143 . V_145 ;
V_140 = F_75 ( V_137 ) ;
V_141 = V_140 & 0x1 ;
return ( V_139 [ V_140 >> 1 ] >> ( V_141 * 4 ) ) & 0xF ;
}
unsigned int F_72 ( unsigned long V_137 )
{
return F_73 () -> V_143 . V_146 ;
}
void F_76 ( struct V_147 * V_148 , unsigned long V_137 )
{
if ( F_77 ( V_148 , V_137 ) == V_51 )
return;
F_78 ( V_148 , V_137 , 1 , V_51 ) ;
#ifdef F_79
F_80 ( V_148 ) ;
#endif
if ( F_72 ( V_137 ) != V_51 ) {
F_73 () -> V_143 = V_148 -> V_143 ;
F_81 () ;
}
}
static int F_82 ( struct V_147 * V_148 , unsigned long V_149 )
{
struct V_150 * V_151 = & V_148 -> V_143 . V_151 ;
T_6 V_152 = 0 ;
T_6 * * V_153 , * V_154 ;
if ( V_149 >= V_151 -> V_155 )
return 0 ;
if ( V_149 < 0x100000000UL ) {
V_153 = V_151 -> V_156 ;
} else {
V_153 = V_151 -> V_157 [ V_149 >> V_158 ] ;
if ( ! V_153 )
return 0 ;
}
V_154 = V_153 [ ( V_149 >> V_159 ) & ( V_160 - 1 ) ] ;
if ( ! V_154 )
return 0 ;
V_152 = V_154 [ ( V_149 >> V_34 ) & ( V_161 - 1 ) ] ;
V_152 >>= 30 - 2 * ( ( V_149 >> 12 ) & 0xf ) ;
V_152 = ( ( V_152 & 2 ) ? V_5 : 0 ) | ( ( V_152 & 1 ) ? V_6 : 0 ) ;
return V_152 ;
}
static inline int F_82 ( struct V_147 * V_148 , unsigned long V_149 )
{
return 0 ;
}
void F_83 ( unsigned long V_149 , unsigned long V_162 ,
unsigned long V_24 , unsigned long V_133 ,
int V_15 , int V_14 , int V_163 , unsigned long V_132 )
{
if ( ! F_84 () )
return;
F_21 ( L_30 ,
V_149 , V_162 , V_164 -> V_165 ) ;
F_21 ( L_31 ,
V_133 , V_24 , V_15 , V_14 , V_163 , V_132 ) ;
}
static void F_85 ( unsigned long V_149 , struct V_147 * V_148 ,
int V_14 , bool V_166 )
{
if ( V_166 ) {
if ( V_14 != F_72 ( V_149 ) ) {
F_73 () -> V_143 = V_148 -> V_143 ;
F_81 () ;
}
} else if ( F_73 () -> V_167 !=
V_21 [ V_84 ] . V_64 ) {
F_73 () -> V_167 =
V_21 [ V_84 ] . V_64 ;
F_86 () ;
}
}
int F_87 ( unsigned long V_149 , unsigned long V_162 , unsigned long V_133 )
{
enum V_168 V_169 = F_88 () ;
T_7 * V_170 ;
unsigned long V_24 ;
struct V_147 * V_148 ;
T_4 * V_171 ;
unsigned V_172 ;
const struct V_173 * V_174 ;
int V_78 , V_166 = 0 , V_175 = 0 ;
int V_14 , V_15 ;
F_89 ( L_32 ,
V_149 , V_162 , V_133 ) ;
switch ( F_90 ( V_149 ) ) {
case V_176 :
V_166 = 1 ;
V_148 = V_164 -> V_148 ;
if ( ! V_148 ) {
F_89 ( L_33 ) ;
V_78 = 1 ;
goto V_177;
}
V_14 = F_77 ( V_148 , V_149 ) ;
V_15 = F_91 ( V_149 ) ;
V_24 = F_92 ( V_148 -> V_143 . V_178 , V_149 , V_15 ) ;
break;
case V_179 :
V_148 = & V_180 ;
V_24 = F_4 ( V_149 , V_98 ) ;
if ( V_149 < V_181 )
V_14 = V_84 ;
else
V_14 = V_87 ;
V_15 = V_98 ;
break;
default:
V_78 = 1 ;
goto V_177;
}
F_89 ( L_34 , V_148 , V_148 -> V_182 , V_24 ) ;
if ( ! V_24 ) {
F_89 ( L_35 ) ;
V_78 = 1 ;
goto V_177;
}
V_170 = V_148 -> V_182 ;
if ( V_170 == NULL ) {
V_78 = 1 ;
goto V_177;
}
V_174 = F_93 ( F_94 () ) ;
if ( V_166 && F_95 ( F_96 ( V_148 ) , V_174 ) )
V_175 = 1 ;
#ifndef F_34
if ( V_14 != V_51 )
V_149 &= ~ ( ( 1ul << V_21 [ V_14 ] . V_19 ) - 1 ) ;
#endif
V_171 = F_97 ( V_170 , V_149 , & V_172 ) ;
if ( V_171 == NULL || ! F_98 ( * V_171 ) ) {
F_89 ( L_36 ) ;
V_78 = 1 ;
goto V_177;
}
V_162 |= V_183 ;
if ( V_162 & ~ F_99 ( * V_171 ) ) {
F_89 ( L_37 ) ;
V_78 = 1 ;
goto V_177;
}
if ( V_172 ) {
if ( F_100 ( * ( V_184 * ) V_171 ) )
V_78 = F_101 ( V_149 , V_162 , V_24 , ( V_184 * ) V_171 ,
V_133 , V_175 , V_15 , V_14 ) ;
#ifdef F_38
else
V_78 = F_102 ( V_149 , V_162 , V_24 , V_171 , V_133 ,
V_175 , V_15 , V_172 , V_14 ) ;
#else
else {
V_78 = 1 ;
F_103 ( 1 ) ;
}
#endif
F_85 ( V_149 , V_148 , V_14 , V_166 ) ;
goto V_177;
}
#ifndef F_34
F_89 ( L_38 , F_99 ( * V_171 ) ) ;
#else
F_89 ( L_39 , F_99 ( * V_171 ) ,
F_99 ( * ( V_171 + V_185 ) ) ) ;
#endif
#ifdef F_34
if ( ( F_99 ( * V_171 ) & V_186 ) && V_14 == V_52 ) {
F_76 ( V_148 , V_149 ) ;
V_14 = V_51 ;
}
if ( V_88 && V_14 == V_52 &&
( F_99 ( * V_171 ) & V_187 ) ) {
if ( V_166 ) {
F_76 ( V_148 , V_149 ) ;
V_14 = V_51 ;
} else if ( V_149 < V_181 ) {
F_13 ( V_188 L_40
L_41
L_42 ) ;
V_14 = V_84 = V_51 ;
#ifdef F_79
F_80 ( V_148 ) ;
#endif
}
}
F_85 ( V_149 , V_148 , V_14 , V_166 ) ;
#endif
#ifdef F_48
if ( V_14 == V_52 )
V_78 = F_104 ( V_149 , V_162 , V_24 , V_171 , V_133 , V_175 , V_15 ) ;
else
#endif
{
int V_152 = F_82 ( V_148 , V_149 ) ;
if ( V_162 & V_152 )
V_78 = - 2 ;
else
V_78 = F_105 ( V_149 , V_162 , V_24 , V_171 , V_133 ,
V_175 , V_15 , V_152 ) ;
}
if ( V_78 == - 1 )
F_83 ( V_149 , V_162 , V_24 , V_133 , V_15 , V_14 ,
V_14 , F_99 ( * V_171 ) ) ;
#ifndef F_34
F_89 ( L_43 , F_99 ( * V_171 ) ) ;
#else
F_89 ( L_44 , F_99 ( * V_171 ) ,
F_99 ( * ( V_171 + V_185 ) ) ) ;
#endif
F_89 ( L_45 , V_78 ) ;
V_177:
F_106 ( V_169 ) ;
return V_78 ;
}
void F_107 ( struct V_147 * V_148 , unsigned long V_149 ,
unsigned long V_162 , unsigned long V_133 )
{
int V_189 ;
unsigned long V_24 ;
T_7 * V_170 ;
T_4 * V_171 ;
unsigned long V_136 ;
int V_78 , V_15 , V_175 = 0 ;
F_10 ( F_90 ( V_149 ) != V_176 ) ;
#ifdef F_108
if ( F_109 ( F_77 ( V_148 , V_149 ) != V_148 -> V_143 . V_146 ) )
return;
#endif
F_89 ( L_46
L_47 , V_148 , V_148 -> V_182 , V_149 , V_162 , V_133 ) ;
V_170 = V_148 -> V_182 ;
if ( V_170 == NULL )
return;
V_15 = F_91 ( V_149 ) ;
V_24 = F_92 ( V_148 -> V_143 . V_178 , V_149 , V_15 ) ;
if ( ! V_24 )
return;
F_110 ( V_136 ) ;
V_171 = F_97 ( V_170 , V_149 , & V_189 ) ;
if ( ! V_171 )
goto V_190;
F_103 ( V_189 ) ;
#ifdef F_34
if ( F_99 ( * V_171 ) & ( V_186 | V_187 ) )
goto V_190;
#endif
if ( F_95 ( F_96 ( V_148 ) , F_93 ( F_94 () ) ) )
V_175 = 1 ;
#ifdef F_48
if ( V_148 -> V_143 . V_146 == V_52 )
V_78 = F_104 ( V_149 , V_162 , V_24 , V_171 , V_133 , V_175 , V_15 ) ;
else
#endif
V_78 = F_105 ( V_149 , V_162 , V_24 , V_171 , V_133 , V_175 , V_15 ,
F_82 ( V_148 , V_149 ) ) ;
if ( V_78 == - 1 )
F_83 ( V_149 , V_162 , V_24 , V_133 , V_15 ,
V_148 -> V_143 . V_146 ,
V_148 -> V_143 . V_146 ,
F_99 ( * V_171 ) ) ;
V_190:
F_111 ( V_136 ) ;
}
void F_112 ( unsigned long V_25 , T_8 V_132 , int V_14 , int V_15 ,
int V_175 )
{
unsigned long V_22 , V_140 , V_19 , V_191 , V_192 ;
F_89 ( L_48 , V_25 ) ;
F_113 (pte, psize, vpn, index, shift) {
V_22 = F_9 ( V_25 , V_19 , V_15 ) ;
V_191 = F_114 ( V_132 , V_140 ) ;
if ( V_191 & V_193 )
V_22 = ~ V_22 ;
V_192 = ( V_22 & V_29 ) * V_30 ;
V_192 += V_191 & V_194 ;
F_89 ( L_49 , V_140 , V_192 , V_191 ) ;
V_31 . V_195 ( V_192 , V_25 , V_14 , V_14 , V_15 , V_175 ) ;
} F_115 () ;
#ifdef F_116
if ( V_175 && F_31 ( V_196 ) &&
V_164 -> V_197 . V_198 &&
F_117 ( V_164 -> V_197 . V_198 -> V_199 ) ) {
F_118 () ;
F_119 ( V_200 ) ;
}
#endif
}
void F_120 ( unsigned long V_201 , int V_175 )
{
if ( V_31 . F_120 )
V_31 . F_120 ( V_201 , V_175 ) ;
else {
int V_202 ;
struct V_203 * V_204 =
& F_121 ( V_203 ) ;
for ( V_202 = 0 ; V_202 < V_201 ; V_202 ++ )
F_112 ( V_204 -> V_25 [ V_202 ] , V_204 -> V_132 [ V_202 ] ,
V_204 -> V_14 , V_204 -> V_15 , V_175 ) ;
}
}
void F_122 ( struct V_205 * V_198 , unsigned long V_206 , int V_78 )
{
enum V_168 V_169 = F_88 () ;
if ( F_123 ( V_198 ) ) {
#ifdef F_124
if ( V_78 == - 2 )
F_125 ( V_207 , V_198 , V_208 , V_206 ) ;
else
#endif
F_125 ( V_209 , V_198 , V_210 , V_206 ) ;
} else
F_126 ( V_198 , V_206 , V_209 ) ;
F_106 ( V_169 ) ;
}
long F_127 ( unsigned long V_22 , unsigned long V_25 ,
unsigned long V_211 , unsigned long V_2 ,
unsigned long V_212 , int V_14 , int V_15 )
{
unsigned long V_213 ;
long V_192 ;
V_214:
V_213 = ( ( V_22 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_192 = V_31 . V_32 ( V_213 , V_25 , V_211 , V_2 , V_212 ,
V_14 , V_14 , V_15 ) ;
if ( F_109 ( V_192 == - 1 ) ) {
V_213 = ( ( ~ V_22 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_192 = V_31 . V_32 ( V_213 , V_25 , V_211 , V_2 ,
V_212 | V_215 ,
V_14 , V_14 , V_15 ) ;
if ( V_192 == - 1 ) {
if ( F_128 () & 0x1 )
V_213 = ( ( V_22 & V_29 ) *
V_30 ) & ~ 0x7UL ;
V_31 . V_103 ( V_213 ) ;
goto V_214;
}
}
return V_192 ;
}
static void F_129 ( unsigned long V_16 , unsigned long V_216 )
{
unsigned long V_22 ;
unsigned long V_24 = F_4 ( V_16 , V_98 ) ;
unsigned long V_25 = F_5 ( V_16 , V_24 , V_98 ) ;
unsigned long V_217 = F_1 ( V_97 ) ;
long V_20 ;
V_22 = F_9 ( V_25 , V_34 , V_98 ) ;
if ( ! V_24 )
return;
V_20 = F_127 ( V_22 , V_25 , F_44 ( V_16 ) , V_217 ,
V_33 ,
V_82 , V_98 ) ;
F_10 ( V_20 < 0 ) ;
F_130 ( & V_218 ) ;
F_10 ( V_36 [ V_216 ] & 0x80 ) ;
V_36 [ V_216 ] = V_20 | 0x80 ;
F_131 ( & V_218 ) ;
}
static void F_132 ( unsigned long V_16 , unsigned long V_216 )
{
unsigned long V_22 , V_191 , V_192 ;
unsigned long V_24 = F_4 ( V_16 , V_98 ) ;
unsigned long V_25 = F_5 ( V_16 , V_24 , V_98 ) ;
V_22 = F_9 ( V_25 , V_34 , V_98 ) ;
F_130 ( & V_218 ) ;
F_10 ( ! ( V_36 [ V_216 ] & 0x80 ) ) ;
V_191 = V_36 [ V_216 ] & 0x7f ;
V_36 [ V_216 ] = 0 ;
F_131 ( & V_218 ) ;
if ( V_191 & V_193 )
V_22 = ~ V_22 ;
V_192 = ( V_22 & V_29 ) * V_30 ;
V_192 += V_191 & V_194 ;
V_31 . V_195 ( V_192 , V_25 , V_82 , V_82 ,
V_98 , 0 ) ;
}
void F_133 ( struct V_134 * V_134 , int V_219 , int V_220 )
{
unsigned long V_136 , V_16 , V_216 ;
int V_202 ;
F_110 ( V_136 ) ;
for ( V_202 = 0 ; V_202 < V_219 ; V_202 ++ , V_134 ++ ) {
V_16 = ( unsigned long ) F_134 ( V_134 ) ;
V_216 = F_44 ( V_16 ) >> V_34 ;
if ( V_216 >= V_35 )
continue;
if ( V_220 )
F_129 ( V_16 , V_216 ) ;
else
F_132 ( V_16 , V_216 ) ;
}
F_111 ( V_136 ) ;
}
void F_135 ( T_9 V_221 ,
T_9 V_222 )
{
F_10 ( V_221 != 0 ) ;
V_125 = F_136 ( T_5 , V_222 , 0x40000000 ) ;
F_60 ( V_125 ) ;
}
