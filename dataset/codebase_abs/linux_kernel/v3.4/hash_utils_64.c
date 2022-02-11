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
if ( F_6 ( V_15 , V_15 + V_17 ) )
V_25 &= ~ V_4 ;
V_21 = F_7 ( V_24 , V_18 , V_14 ) ;
V_22 = ( ( V_21 & V_26 ) * V_27 ) ;
F_8 ( ! V_28 . V_29 ) ;
V_19 = V_28 . V_29 ( V_22 , V_24 , V_16 , V_25 ,
V_30 , V_13 , V_14 ) ;
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
static int T_1 F_16 ( unsigned long V_37 ,
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
F_3 ( L_9 ) ;
V_42 /= 4 ;
V_43 -> V_44 &= ~ ( V_47 ) ;
while( V_42 > 0 ) {
unsigned int V_18 = V_41 [ 0 ] ;
unsigned int V_48 = V_41 [ 1 ] ;
unsigned int V_49 = V_41 [ 2 ] ;
unsigned int V_50 = 0 ;
struct V_51 * V_52 ;
int V_53 = - 1 ;
V_42 -= 3 ; V_41 += 3 ;
while( V_42 > 0 && V_49 ) {
if ( V_41 [ 0 ] == V_18 )
V_50 = V_41 [ 1 ] ;
V_41 += 2 ; V_42 -= 2 ;
V_49 -- ;
}
switch( V_18 ) {
case 0xc :
V_53 = V_54 ;
break;
case 0x10 :
V_53 = V_55 ;
break;
case 0x14 :
V_53 = V_56 ;
break;
case 0x18 :
V_53 = V_57 ;
V_43 -> V_44 |= V_47 ;
break;
case 0x22 :
V_53 = V_58 ;
break;
}
if ( V_53 < 0 )
continue;
V_52 = & V_20 [ V_53 ] ;
V_52 -> V_18 = V_18 ;
if ( V_18 <= 23 )
V_52 -> V_59 = 0 ;
else
V_52 -> V_59 = ( 1 << ( V_18 - 23 ) ) - 1 ;
V_52 -> V_60 = V_48 ;
V_52 -> V_61 = V_50 ;
if ( V_53 == V_54 || V_53 == V_55 )
V_52 -> V_62 = 1 ;
else
V_52 -> V_62 = 0 ;
F_3 ( L_10
L_11 ,
V_53 , V_18 , V_52 -> V_60 , V_52 -> V_59 , V_52 -> V_62 ,
V_52 -> V_61 ) ;
}
return 1 ;
}
return 0 ;
}
static int T_1 F_17 ( unsigned long V_37 ,
const char * V_38 , int V_39 ,
void * V_40 ) {
char * type = F_13 ( V_37 , L_4 , NULL ) ;
unsigned long * V_63 ;
T_2 * V_64 ;
unsigned int V_65 ;
long unsigned int V_66 ;
long unsigned int V_67 ;
if ( type == NULL || strcmp ( type , L_12 ) != 0 )
return 0 ;
V_64 = F_13 ( V_37 , L_13 , NULL ) ;
if ( V_64 == NULL )
return 0 ;
V_65 = ( 1 << V_64 [ 0 ] ) ;
V_63 = F_13 ( V_37 , L_14 , NULL ) ;
if ( V_63 == NULL )
return 0 ;
V_66 = V_63 [ 0 ] ;
V_67 = V_63 [ 1 ] ;
if ( V_67 != ( 16 * V_68 ) )
return 0 ;
F_11 ( V_69 L_15
L_16 ,
V_66 , V_67 , V_65 ) ;
if ( V_66 + ( 16 * V_68 ) <= F_18 () ) {
F_19 ( V_66 , V_67 * V_65 ) ;
F_20 ( V_66 , V_67 , V_65 ) ;
}
return 0 ;
}
static void T_1 F_21 ( void )
{
int V_70 ;
memcpy ( V_20 , V_71 ,
sizeof( V_71 ) ) ;
V_70 = F_15 ( F_16 , NULL ) ;
if ( V_70 != 0 )
goto V_72;
if ( F_22 ( V_47 ) )
memcpy ( V_20 , V_73 ,
sizeof( V_73 ) ) ;
V_72:
#ifndef F_9
if ( V_20 [ V_57 ] . V_18 )
V_74 = V_57 ;
else if ( V_20 [ V_56 ] . V_18 )
V_74 = V_56 ;
#endif
#ifdef F_23
if ( V_20 [ V_55 ] . V_18 ) {
V_75 = V_55 ;
V_76 = V_55 ;
if ( V_74 == V_54 )
V_74 = V_55 ;
if ( F_22 ( V_77 ) ) {
if ( ! F_24 ( V_78 ) )
V_79 = V_55 ;
} else
V_80 = 1 ;
}
#endif
#ifdef F_25
if ( V_20 [ V_57 ] . V_18 &&
F_26 () >= 0x40000000 )
V_81 = V_57 ;
else if ( V_20 [ V_55 ] . V_18 )
V_81 = V_55 ;
else
V_81 = V_54 ;
#endif
F_11 ( V_82 L_17
L_18
#ifdef F_25
L_19
#endif
L_20 ,
V_20 [ V_74 ] . V_18 ,
V_20 [ V_75 ] . V_18 ,
V_20 [ V_79 ] . V_18
#ifdef F_25
, V_20 [ V_81 ] . V_18
#endif
) ;
#ifdef F_27
F_15 ( F_17 , NULL ) ;
#endif
}
static int T_1 F_28 ( unsigned long V_37 ,
const char * V_38 , int V_39 ,
void * V_40 )
{
char * type = F_13 ( V_37 , L_4 , NULL ) ;
T_2 * V_41 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_41 = ( T_2 * ) F_13 ( V_37 , L_21 , NULL ) ;
if ( V_41 != NULL ) {
V_83 = V_41 [ 1 ] ;
return 1 ;
}
return 0 ;
}
static unsigned long T_1 F_29 ( void )
{
unsigned long V_84 , V_85 , V_86 , V_13 ;
if ( V_83 == 0 )
F_15 ( F_28 , NULL ) ;
if ( V_83 )
return 1UL << V_83 ;
V_84 = F_26 () ;
V_85 = 1UL << F_30 ( V_84 ) ;
if ( V_85 < V_84 )
V_85 <<= 1 ;
V_13 = V_20 [ V_75 ] . V_18 ;
V_86 = F_31 ( V_85 >> ( V_13 + 1 ) , 1UL << 11 ) ;
return V_86 << 7 ;
}
int F_32 ( unsigned long V_87 , unsigned long V_88 )
{
return F_2 ( V_87 , V_88 , F_33 ( V_87 ) ,
F_34 ( V_89 ) , V_74 ,
V_90 ) ;
}
int F_35 ( unsigned long V_87 , unsigned long V_88 )
{
return F_10 ( V_87 , V_88 , V_74 ,
V_90 ) ;
}
static void T_1 F_36 ( void )
{
extern unsigned int * V_91 ;
extern unsigned int * V_92 ;
extern unsigned int * V_93 ;
extern unsigned int * V_94 ;
#ifdef F_37
extern unsigned int * V_95 ;
extern unsigned int * V_96 ;
extern unsigned int * V_97 ;
extern unsigned int * V_98 ;
F_38 ( V_95 ,
F_39 ( V_28 . V_29 ) ,
V_99 ) ;
F_38 ( V_96 ,
F_39 ( V_28 . V_29 ) ,
V_99 ) ;
F_38 ( V_97 ,
F_39 ( V_28 . V_100 ) ,
V_99 ) ;
F_38 ( V_98 ,
F_39 ( V_28 . V_101 ) ,
V_99 ) ;
#endif
F_38 ( V_91 ,
F_39 ( V_28 . V_29 ) ,
V_99 ) ;
F_38 ( V_92 ,
F_39 ( V_28 . V_29 ) ,
V_99 ) ;
F_38 ( V_93 ,
F_39 ( V_28 . V_100 ) ,
V_99 ) ;
F_38 ( V_94 ,
F_39 ( V_28 . V_101 ) ,
V_99 ) ;
}
static void T_1 F_40 ( void )
{
unsigned long V_102 ;
unsigned long V_86 ;
unsigned long V_12 ;
unsigned long V_103 = 0 , V_42 = 0 , V_104 ;
struct V_105 * V_106 ;
F_3 ( L_22 ) ;
F_14 () ;
F_21 () ;
if ( F_22 ( V_45 ) ) {
V_90 = V_107 ;
V_108 = V_107 ;
F_11 ( V_69 L_23 ) ;
}
V_109 = F_29 () ;
V_86 = V_109 >> 7 ;
V_26 = V_86 - 1 ;
if ( F_41 ( V_110 ) ) {
V_111 = NULL ;
V_112 = 0 ;
#ifdef F_42
if ( F_43 () && V_28 . V_113 )
V_28 . V_113 () ;
#endif
} else {
if ( F_24 ( V_114 ) )
V_104 = 0x80000000 ;
else
V_104 = V_115 ;
V_102 = F_44 ( V_109 , V_109 , V_104 ) ;
F_3 ( L_24 , V_102 ,
V_109 ) ;
V_111 = F_45 ( V_102 ) ;
V_112 = V_102 + F_30 ( V_86 ) - 11 ;
memset ( ( void * ) V_102 , 0 , V_109 ) ;
F_46 ( V_116 , V_112 ) ;
}
V_12 = F_34 ( V_89 ) ;
#ifdef F_9
V_32 = F_18 () >> V_31 ;
V_33 = F_47 ( F_44 ( V_32 ,
1 , V_117 ) ) ;
memset ( V_33 , 0 , V_32 ) ;
#endif
F_48 (memory, reg) {
V_103 = ( unsigned long ) F_47 ( V_106 -> V_103 ) ;
V_42 = V_106 -> V_42 ;
F_3 ( L_25 ,
V_103 , V_42 , V_12 ) ;
#ifdef F_49
F_3 ( L_26 , V_118 ) ;
if ( V_118 != 0 && V_118 >= V_103
&& V_118 < ( V_103 + V_42 ) ) {
unsigned long V_119 = V_118 + 16 * V_120 ;
if ( V_103 != V_118 )
F_8 ( F_2 ( V_103 , V_118 ,
F_33 ( V_103 ) , V_12 ,
V_74 ,
V_90 ) ) ;
if ( ( V_103 + V_42 ) > V_119 )
F_8 ( F_2 ( V_118 + 16 * V_120 ,
V_103 + V_42 ,
F_33 ( V_119 ) ,
V_12 ,
V_74 ,
V_90 ) ) ;
continue;
}
#endif
F_8 ( F_2 ( V_103 , V_103 + V_42 , F_33 ( V_103 ) ,
V_12 , V_74 , V_90 ) ) ;
}
F_50 ( V_115 ) ;
if ( V_121 ) {
V_121 = ( unsigned long ) F_47 ( V_121 ) ;
V_122 = ( unsigned long ) F_47 ( V_122 ) ;
if ( V_103 + V_42 >= V_121 )
V_121 = V_103 + V_42 + 1 ;
F_8 ( F_2 ( V_121 , V_122 ,
F_33 ( V_121 ) , V_12 ,
V_74 , V_90 ) ) ;
}
F_36 () ;
F_3 ( L_27 ) ;
}
void T_1 F_51 ( void )
{
F_52 () -> V_123 = F_33 ( ( V_124 ) & V_125 ) ;
F_52 () -> V_126 = ( V_124 ) & V_125 ;
F_40 () ;
if ( F_22 ( V_127 ) )
F_53 () ;
}
void T_3 F_54 ( void )
{
if ( ! F_41 ( V_110 ) )
F_46 ( V_116 , V_112 ) ;
if ( F_22 ( V_127 ) )
F_53 () ;
else
F_55 ( F_52 () -> V_126 ) ;
}
unsigned int F_56 ( unsigned int V_128 , T_4 V_129 , int V_130 )
{
struct V_131 * V_131 ;
if ( ! F_57 ( F_58 ( V_129 ) ) )
return V_128 ;
V_131 = F_59 ( V_129 ) ;
if ( ! F_60 ( V_132 , & V_131 -> V_133 ) && ! F_61 ( V_131 ) ) {
if ( V_130 == 0x400 ) {
F_62 ( V_131 ) ;
F_63 ( V_132 , & V_131 -> V_133 ) ;
} else
V_128 |= V_4 ;
}
return V_128 ;
}
unsigned int F_64 ( unsigned long V_134 )
{
unsigned long V_135 , V_136 ;
if ( V_134 < V_137 ) {
V_136 = F_52 () -> V_138 . V_139 ;
V_135 = F_65 ( V_134 ) ;
} else {
V_136 = F_52 () -> V_138 . V_140 ;
V_135 = F_66 ( V_134 ) ;
}
return ( V_136 >> ( V_135 * 4 ) ) & 0xF ;
}
unsigned int F_64 ( unsigned long V_134 )
{
return F_52 () -> V_138 . V_141 ;
}
void F_67 ( struct V_142 * V_143 , unsigned long V_134 )
{
if ( F_68 ( V_143 , V_134 ) == V_54 )
return;
F_69 ( V_143 , V_134 , 1 , V_54 ) ;
#ifdef F_70
F_71 ( V_143 ) ;
#endif
if ( F_64 ( V_134 ) != V_54 ) {
F_52 () -> V_138 = V_143 -> V_138 ;
F_72 () ;
}
}
static int F_73 ( struct V_142 * V_143 , unsigned long V_144 )
{
struct V_145 * V_146 = & V_143 -> V_138 . V_146 ;
T_2 V_147 = 0 ;
T_2 * * V_148 , * V_149 ;
if ( V_144 >= V_146 -> V_150 )
return 0 ;
if ( V_144 < 0x100000000 ) {
V_148 = V_146 -> V_151 ;
} else {
V_148 = V_146 -> V_152 [ V_144 >> V_153 ] ;
if ( ! V_148 )
return 0 ;
}
V_149 = V_148 [ ( V_144 >> V_154 ) & ( V_155 - 1 ) ] ;
if ( ! V_149 )
return 0 ;
V_147 = V_149 [ ( V_144 >> V_31 ) & ( V_156 - 1 ) ] ;
V_147 >>= 30 - 2 * ( ( V_144 >> 12 ) & 0xf ) ;
V_147 = ( ( V_147 & 2 ) ? V_5 : 0 ) | ( ( V_147 & 1 ) ? V_6 : 0 ) ;
return V_147 ;
}
static inline int F_73 ( struct V_142 * V_143 , unsigned long V_144 )
{
return 0 ;
}
void F_74 ( unsigned long V_144 , unsigned long V_157 ,
unsigned long V_23 , unsigned long V_130 ,
int V_14 , int V_13 , unsigned long V_129 )
{
if ( ! F_75 () )
return;
F_76 ( L_28 ,
V_144 , V_157 , V_158 -> V_159 ) ;
F_76 ( L_29 ,
V_130 , V_23 , V_14 , V_13 , V_129 ) ;
}
int F_77 ( unsigned long V_144 , unsigned long V_157 , unsigned long V_130 )
{
T_5 * V_160 ;
unsigned long V_23 ;
struct V_142 * V_143 ;
T_4 * V_161 ;
unsigned V_162 ;
const struct V_163 * V_164 ;
int V_70 , V_165 = 0 , V_166 = 0 ;
int V_13 , V_14 ;
F_78 ( L_30 ,
V_144 , V_157 , V_130 ) ;
if ( ( V_144 & ~ V_167 ) >= V_168 ) {
F_78 ( L_31 ) ;
return 1 ;
}
switch ( F_79 ( V_144 ) ) {
case V_169 :
V_165 = 1 ;
V_143 = V_158 -> V_143 ;
if ( ! V_143 ) {
F_78 ( L_32 ) ;
return 1 ;
}
V_13 = F_68 ( V_143 , V_144 ) ;
V_14 = F_80 ( V_144 ) ;
V_23 = F_81 ( V_143 -> V_138 . V_170 , V_144 , V_14 ) ;
break;
case V_171 :
V_143 = & V_172 ;
V_23 = F_4 ( V_144 , V_90 ) ;
if ( V_144 < V_173 )
V_13 = V_76 ;
else
V_13 = V_79 ;
V_14 = V_90 ;
break;
default:
return 1 ;
}
F_78 ( L_33 , V_143 , V_143 -> V_174 , V_23 ) ;
V_160 = V_143 -> V_174 ;
if ( V_160 == NULL )
return 1 ;
V_164 = F_82 ( F_83 () ) ;
if ( V_165 && F_84 ( F_85 ( V_143 ) , V_164 ) )
V_166 = 1 ;
#ifndef F_23
if ( V_13 != V_54 )
V_144 &= ~ ( ( 1ul << V_20 [ V_13 ] . V_18 ) - 1 ) ;
#endif
V_161 = F_86 ( V_160 , V_144 , & V_162 ) ;
if ( V_161 == NULL || ! F_87 ( * V_161 ) ) {
F_78 ( L_34 ) ;
return 1 ;
}
V_157 |= V_175 ;
if ( V_157 & ~ F_88 ( * V_161 ) ) {
F_78 ( L_35 ) ;
return 1 ;
}
#ifdef F_27
if ( V_162 )
return F_89 ( V_144 , V_157 , V_23 , V_161 , V_130 , V_166 ,
V_14 , V_162 , V_13 ) ;
#endif
#ifndef F_23
F_78 ( L_36 , F_88 ( * V_161 ) ) ;
#else
F_78 ( L_37 , F_88 ( * V_161 ) ,
F_88 ( * ( V_161 + V_176 ) ) ) ;
#endif
#ifdef F_23
if ( ( F_88 ( * V_161 ) & V_177 ) && V_13 == V_55 ) {
F_67 ( V_143 , V_144 ) ;
V_13 = V_54 ;
}
if ( V_80 && V_13 == V_55 &&
( F_88 ( * V_161 ) & V_178 ) ) {
if ( V_165 ) {
F_67 ( V_143 , V_144 ) ;
V_13 = V_54 ;
} else if ( V_144 < V_173 ) {
F_11 ( V_179 L_38
L_39
L_40 ) ;
V_13 = V_76 = V_54 ;
#ifdef F_70
F_71 ( V_143 ) ;
#endif
}
}
if ( V_165 ) {
if ( V_13 != F_64 ( V_144 ) ) {
F_52 () -> V_138 = V_143 -> V_138 ;
F_72 () ;
}
} else if ( F_52 () -> V_180 !=
V_20 [ V_76 ] . V_60 ) {
F_52 () -> V_180 =
V_20 [ V_76 ] . V_60 ;
F_90 () ;
}
#endif
#ifdef F_37
if ( V_13 == V_55 )
V_70 = F_91 ( V_144 , V_157 , V_23 , V_161 , V_130 , V_166 , V_14 ) ;
else
#endif
{
int V_147 = F_73 ( V_143 , V_144 ) ;
if ( V_157 & V_147 )
V_70 = - 2 ;
else
V_70 = F_92 ( V_144 , V_157 , V_23 , V_161 , V_130 ,
V_166 , V_14 , V_147 ) ;
}
if ( V_70 == - 1 )
F_74 ( V_144 , V_157 , V_23 , V_130 , V_14 , V_13 ,
F_88 ( * V_161 ) ) ;
#ifndef F_23
F_78 ( L_41 , F_88 ( * V_161 ) ) ;
#else
F_78 ( L_42 , F_88 ( * V_161 ) ,
F_88 ( * ( V_161 + V_176 ) ) ) ;
#endif
F_78 ( L_43 , V_70 ) ;
return V_70 ;
}
void F_93 ( struct V_142 * V_143 , unsigned long V_144 ,
unsigned long V_157 , unsigned long V_130 )
{
unsigned long V_23 ;
T_5 * V_160 ;
T_4 * V_161 ;
unsigned long V_133 ;
int V_70 , V_14 , V_166 = 0 ;
F_8 ( F_79 ( V_144 ) != V_169 ) ;
#ifdef F_94
if ( F_95 ( F_68 ( V_143 , V_144 ) != V_143 -> V_138 . V_141 ) )
return;
#endif
F_78 ( L_44
L_45 , V_143 , V_143 -> V_174 , V_144 , V_157 , V_130 ) ;
V_160 = V_143 -> V_174 ;
if ( V_160 == NULL )
return;
V_161 = F_96 ( V_160 , V_144 ) ;
if ( ! V_161 )
return;
#ifdef F_23
if ( F_88 ( * V_161 ) & ( V_177 | V_178 ) )
return;
#endif
V_14 = F_80 ( V_144 ) ;
V_23 = F_81 ( V_143 -> V_138 . V_170 , V_144 , V_14 ) ;
F_97 ( V_133 ) ;
if ( F_84 ( F_85 ( V_143 ) , F_82 ( F_83 () ) ) )
V_166 = 1 ;
#ifdef F_37
if ( V_143 -> V_138 . V_141 == V_55 )
V_70 = F_91 ( V_144 , V_157 , V_23 , V_161 , V_130 , V_166 , V_14 ) ;
else
#endif
V_70 = F_92 ( V_144 , V_157 , V_23 , V_161 , V_130 , V_166 , V_14 ,
F_73 ( V_143 , V_144 ) ) ;
if ( V_70 == - 1 )
F_74 ( V_144 , V_157 , V_23 , V_130 , V_14 ,
V_143 -> V_138 . V_141 , F_88 ( * V_161 ) ) ;
F_98 ( V_133 ) ;
}
void F_99 ( unsigned long V_24 , T_6 V_129 , int V_13 , int V_14 ,
int V_166 )
{
unsigned long V_21 , V_135 , V_18 , V_181 , V_182 ;
F_78 ( L_46 , V_24 ) ;
F_100 (pte, psize, va, index, shift) {
V_21 = F_7 ( V_24 , V_18 , V_14 ) ;
V_181 = F_101 ( V_129 , V_135 ) ;
if ( V_181 & V_183 )
V_21 = ~ V_21 ;
V_182 = ( V_21 & V_26 ) * V_27 ;
V_182 += V_181 & V_184 ;
F_78 ( L_47 , V_135 , V_182 , V_181 ) ;
V_28 . V_185 ( V_182 , V_24 , V_13 , V_14 , V_166 ) ;
} F_102 () ;
}
void F_103 ( unsigned long V_186 , int V_166 )
{
if ( V_28 . F_103 )
V_28 . F_103 ( V_186 , V_166 ) ;
else {
int V_187 ;
struct V_188 * V_189 =
& F_104 ( V_188 ) ;
for ( V_187 = 0 ; V_187 < V_186 ; V_187 ++ )
F_99 ( V_189 -> V_15 [ V_187 ] , V_189 -> V_129 [ V_187 ] ,
V_189 -> V_13 , V_189 -> V_14 , V_166 ) ;
}
}
void F_105 ( struct V_190 * V_191 , unsigned long V_192 , int V_70 )
{
if ( F_106 ( V_191 ) ) {
#ifdef F_107
if ( V_70 == - 2 )
F_108 ( V_193 , V_191 , V_194 , V_192 ) ;
else
#endif
F_108 ( V_195 , V_191 , V_196 , V_192 ) ;
} else
F_109 ( V_191 , V_192 , V_195 ) ;
}
static void F_110 ( unsigned long V_15 , unsigned long V_197 )
{
unsigned long V_21 , V_22 ;
unsigned long V_23 = F_4 ( V_15 , V_90 ) ;
unsigned long V_24 = F_5 ( V_15 , V_23 , V_90 ) ;
unsigned long V_198 = F_1 ( V_89 ) ;
int V_19 ;
V_21 = F_7 ( V_24 , V_31 , V_90 ) ;
V_22 = ( ( V_21 & V_26 ) * V_27 ) ;
V_19 = V_28 . V_29 ( V_22 , V_24 , F_33 ( V_15 ) ,
V_198 , V_30 ,
V_74 , V_90 ) ;
F_8 ( V_19 < 0 ) ;
F_111 ( & V_199 ) ;
F_8 ( V_33 [ V_197 ] & 0x80 ) ;
V_33 [ V_197 ] = V_19 | 0x80 ;
F_112 ( & V_199 ) ;
}
static void F_113 ( unsigned long V_15 , unsigned long V_197 )
{
unsigned long V_21 , V_181 , V_182 ;
unsigned long V_23 = F_4 ( V_15 , V_90 ) ;
unsigned long V_24 = F_5 ( V_15 , V_23 , V_90 ) ;
V_21 = F_7 ( V_24 , V_31 , V_90 ) ;
F_111 ( & V_199 ) ;
F_8 ( ! ( V_33 [ V_197 ] & 0x80 ) ) ;
V_181 = V_33 [ V_197 ] & 0x7f ;
V_33 [ V_197 ] = 0 ;
F_112 ( & V_199 ) ;
if ( V_181 & V_183 )
V_21 = ~ V_21 ;
V_182 = ( V_21 & V_26 ) * V_27 ;
V_182 += V_181 & V_184 ;
V_28 . V_185 ( V_182 , V_24 , V_74 , V_90 , 0 ) ;
}
void F_114 ( struct V_131 * V_131 , int V_200 , int V_201 )
{
unsigned long V_133 , V_15 , V_197 ;
int V_187 ;
F_97 ( V_133 ) ;
for ( V_187 = 0 ; V_187 < V_200 ; V_187 ++ , V_131 ++ ) {
V_15 = ( unsigned long ) F_115 ( V_131 ) ;
V_197 = F_33 ( V_15 ) >> V_31 ;
if ( V_197 >= V_32 )
continue;
if ( V_201 )
F_110 ( V_15 , V_197 ) ;
else
F_113 ( V_15 , V_197 ) ;
}
F_98 ( V_133 ) ;
}
void F_116 ( T_7 V_202 ,
T_7 V_203 )
{
F_8 ( V_202 != 0 ) ;
V_117 = F_117 ( V_124 , V_203 , 0x40000000 ) ;
F_50 ( V_117 ) ;
}
