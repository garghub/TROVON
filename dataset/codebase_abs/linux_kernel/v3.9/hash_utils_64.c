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
V_33 = F_45 ( F_44 ( V_32 ,
1 , V_117 ) ) ;
memset ( V_33 , 0 , V_32 ) ;
#endif
F_47 (memory, reg) {
V_103 = ( unsigned long ) F_45 ( V_106 -> V_103 ) ;
V_42 = V_106 -> V_42 ;
F_3 ( L_25 ,
V_103 , V_42 , V_12 ) ;
#ifdef F_48
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
F_49 ( V_115 ) ;
if ( V_121 ) {
V_121 = ( unsigned long ) F_45 ( V_121 ) ;
V_122 = ( unsigned long ) F_45 ( V_122 ) ;
if ( V_103 + V_42 >= V_121 )
V_121 = V_103 + V_42 + 1 ;
F_8 ( F_2 ( V_121 , V_122 ,
F_33 ( V_121 ) , V_12 ,
V_74 , V_90 ) ) ;
}
F_36 () ;
F_3 ( L_27 ) ;
}
void T_1 F_50 ( void )
{
F_51 () -> V_123 = F_33 ( ( V_124 ) & V_125 ) ;
F_51 () -> V_126 = ( V_124 ) & V_125 ;
F_40 () ;
if ( F_22 ( V_127 ) )
F_52 () ;
else
F_53 ( F_51 () -> V_123 ) ;
}
void T_3 F_54 ( void )
{
if ( ! F_41 ( V_110 ) )
F_46 ( V_116 , V_112 ) ;
if ( F_22 ( V_127 ) )
F_52 () ;
else
F_53 ( F_51 () -> V_126 ) ;
}
unsigned int F_55 ( unsigned int V_128 , T_4 V_129 , int V_130 )
{
struct V_131 * V_131 ;
if ( ! F_56 ( F_57 ( V_129 ) ) )
return V_128 ;
V_131 = F_58 ( V_129 ) ;
if ( ! F_59 ( V_132 , & V_131 -> V_133 ) && ! F_60 ( V_131 ) ) {
if ( V_130 == 0x400 ) {
F_61 ( V_131 ) ;
F_62 ( V_132 , & V_131 -> V_133 ) ;
} else
V_128 |= V_4 ;
}
return V_128 ;
}
unsigned int F_63 ( unsigned long V_134 )
{
V_124 V_135 ;
unsigned char * V_136 ;
unsigned long V_137 , V_138 ;
if ( V_134 < V_139 ) {
V_135 = F_51 () -> V_140 . V_141 ;
V_137 = F_64 ( V_134 ) ;
return ( V_135 >> ( V_137 * 4 ) ) & 0xF ;
}
V_136 = F_51 () -> V_140 . V_142 ;
V_137 = F_65 ( V_134 ) ;
V_138 = V_137 & 0x1 ;
return ( V_136 [ V_137 >> 1 ] >> ( V_138 * 4 ) ) & 0xF ;
}
unsigned int F_63 ( unsigned long V_134 )
{
return F_51 () -> V_140 . V_143 ;
}
void F_66 ( struct V_144 * V_145 , unsigned long V_134 )
{
if ( F_67 ( V_145 , V_134 ) == V_54 )
return;
F_68 ( V_145 , V_134 , 1 , V_54 ) ;
#ifdef F_69
F_70 ( V_145 ) ;
#endif
if ( F_63 ( V_134 ) != V_54 ) {
F_51 () -> V_140 = V_145 -> V_140 ;
F_71 () ;
}
}
static int F_72 ( struct V_144 * V_145 , unsigned long V_146 )
{
struct V_147 * V_148 = & V_145 -> V_140 . V_148 ;
T_2 V_149 = 0 ;
T_2 * * V_150 , * V_151 ;
if ( V_146 >= V_148 -> V_152 )
return 0 ;
if ( V_146 < 0x100000000 ) {
V_150 = V_148 -> V_153 ;
} else {
V_150 = V_148 -> V_154 [ V_146 >> V_155 ] ;
if ( ! V_150 )
return 0 ;
}
V_151 = V_150 [ ( V_146 >> V_156 ) & ( V_157 - 1 ) ] ;
if ( ! V_151 )
return 0 ;
V_149 = V_151 [ ( V_146 >> V_31 ) & ( V_158 - 1 ) ] ;
V_149 >>= 30 - 2 * ( ( V_146 >> 12 ) & 0xf ) ;
V_149 = ( ( V_149 & 2 ) ? V_5 : 0 ) | ( ( V_149 & 1 ) ? V_6 : 0 ) ;
return V_149 ;
}
static inline int F_72 ( struct V_144 * V_145 , unsigned long V_146 )
{
return 0 ;
}
void F_73 ( unsigned long V_146 , unsigned long V_159 ,
unsigned long V_23 , unsigned long V_130 ,
int V_14 , int V_13 , unsigned long V_129 )
{
if ( ! F_74 () )
return;
F_75 ( L_28 ,
V_146 , V_159 , V_160 -> V_161 ) ;
F_75 ( L_29 ,
V_130 , V_23 , V_14 , V_13 , V_129 ) ;
}
int F_76 ( unsigned long V_146 , unsigned long V_159 , unsigned long V_130 )
{
T_5 * V_162 ;
unsigned long V_23 ;
struct V_144 * V_145 ;
T_4 * V_163 ;
unsigned V_164 ;
const struct V_165 * V_166 ;
int V_70 , V_167 = 0 , V_168 = 0 ;
int V_13 , V_14 ;
F_77 ( L_30 ,
V_146 , V_159 , V_130 ) ;
switch ( F_78 ( V_146 ) ) {
case V_169 :
V_167 = 1 ;
V_145 = V_160 -> V_145 ;
if ( ! V_145 ) {
F_77 ( L_31 ) ;
return 1 ;
}
V_13 = F_67 ( V_145 , V_146 ) ;
V_14 = F_79 ( V_146 ) ;
V_23 = F_80 ( V_145 -> V_140 . V_170 , V_146 , V_14 ) ;
break;
case V_171 :
V_145 = & V_172 ;
V_23 = F_4 ( V_146 , V_90 ) ;
if ( V_146 < V_173 )
V_13 = V_76 ;
else
V_13 = V_79 ;
V_14 = V_90 ;
break;
default:
return 1 ;
}
F_77 ( L_32 , V_145 , V_145 -> V_174 , V_23 ) ;
if ( ! V_23 ) {
F_77 ( L_33 ) ;
return 1 ;
}
V_162 = V_145 -> V_174 ;
if ( V_162 == NULL )
return 1 ;
V_166 = F_81 ( F_82 () ) ;
if ( V_167 && F_83 ( F_84 ( V_145 ) , V_166 ) )
V_168 = 1 ;
#ifndef F_23
if ( V_13 != V_54 )
V_146 &= ~ ( ( 1ul << V_20 [ V_13 ] . V_18 ) - 1 ) ;
#endif
V_163 = F_85 ( V_162 , V_146 , & V_164 ) ;
if ( V_163 == NULL || ! F_86 ( * V_163 ) ) {
F_77 ( L_34 ) ;
return 1 ;
}
V_159 |= V_175 ;
if ( V_159 & ~ F_87 ( * V_163 ) ) {
F_77 ( L_35 ) ;
return 1 ;
}
#ifdef F_27
if ( V_164 )
return F_88 ( V_146 , V_159 , V_23 , V_163 , V_130 , V_168 ,
V_14 , V_164 , V_13 ) ;
#endif
#ifndef F_23
F_77 ( L_36 , F_87 ( * V_163 ) ) ;
#else
F_77 ( L_37 , F_87 ( * V_163 ) ,
F_87 ( * ( V_163 + V_176 ) ) ) ;
#endif
#ifdef F_23
if ( ( F_87 ( * V_163 ) & V_177 ) && V_13 == V_55 ) {
F_66 ( V_145 , V_146 ) ;
V_13 = V_54 ;
}
if ( V_80 && V_13 == V_55 &&
( F_87 ( * V_163 ) & V_178 ) ) {
if ( V_167 ) {
F_66 ( V_145 , V_146 ) ;
V_13 = V_54 ;
} else if ( V_146 < V_173 ) {
F_11 ( V_179 L_38
L_39
L_40 ) ;
V_13 = V_76 = V_54 ;
#ifdef F_69
F_70 ( V_145 ) ;
#endif
}
}
if ( V_167 ) {
if ( V_13 != F_63 ( V_146 ) ) {
F_51 () -> V_140 = V_145 -> V_140 ;
F_71 () ;
}
} else if ( F_51 () -> V_180 !=
V_20 [ V_76 ] . V_60 ) {
F_51 () -> V_180 =
V_20 [ V_76 ] . V_60 ;
F_89 () ;
}
#endif
#ifdef F_37
if ( V_13 == V_55 )
V_70 = F_90 ( V_146 , V_159 , V_23 , V_163 , V_130 , V_168 , V_14 ) ;
else
#endif
{
int V_149 = F_72 ( V_145 , V_146 ) ;
if ( V_159 & V_149 )
V_70 = - 2 ;
else
V_70 = F_91 ( V_146 , V_159 , V_23 , V_163 , V_130 ,
V_168 , V_14 , V_149 ) ;
}
if ( V_70 == - 1 )
F_73 ( V_146 , V_159 , V_23 , V_130 , V_14 , V_13 ,
F_87 ( * V_163 ) ) ;
#ifndef F_23
F_77 ( L_41 , F_87 ( * V_163 ) ) ;
#else
F_77 ( L_42 , F_87 ( * V_163 ) ,
F_87 ( * ( V_163 + V_176 ) ) ) ;
#endif
F_77 ( L_43 , V_70 ) ;
return V_70 ;
}
void F_92 ( struct V_144 * V_145 , unsigned long V_146 ,
unsigned long V_159 , unsigned long V_130 )
{
unsigned long V_23 ;
T_5 * V_162 ;
T_4 * V_163 ;
unsigned long V_133 ;
int V_70 , V_14 , V_168 = 0 ;
F_8 ( F_78 ( V_146 ) != V_169 ) ;
#ifdef F_93
if ( F_94 ( F_67 ( V_145 , V_146 ) != V_145 -> V_140 . V_143 ) )
return;
#endif
F_77 ( L_44
L_45 , V_145 , V_145 -> V_174 , V_146 , V_159 , V_130 ) ;
V_162 = V_145 -> V_174 ;
if ( V_162 == NULL )
return;
V_163 = F_95 ( V_162 , V_146 ) ;
if ( ! V_163 )
return;
#ifdef F_23
if ( F_87 ( * V_163 ) & ( V_177 | V_178 ) )
return;
#endif
V_14 = F_79 ( V_146 ) ;
V_23 = F_80 ( V_145 -> V_140 . V_170 , V_146 , V_14 ) ;
if ( ! V_23 )
return;
F_96 ( V_133 ) ;
if ( F_83 ( F_84 ( V_145 ) , F_81 ( F_82 () ) ) )
V_168 = 1 ;
#ifdef F_37
if ( V_145 -> V_140 . V_143 == V_55 )
V_70 = F_90 ( V_146 , V_159 , V_23 , V_163 , V_130 , V_168 , V_14 ) ;
else
#endif
V_70 = F_91 ( V_146 , V_159 , V_23 , V_163 , V_130 , V_168 , V_14 ,
F_72 ( V_145 , V_146 ) ) ;
if ( V_70 == - 1 )
F_73 ( V_146 , V_159 , V_23 , V_130 , V_14 ,
V_145 -> V_140 . V_143 , F_87 ( * V_163 ) ) ;
F_97 ( V_133 ) ;
}
void F_98 ( unsigned long V_24 , T_6 V_129 , int V_13 , int V_14 ,
int V_168 )
{
unsigned long V_21 , V_137 , V_18 , V_181 , V_182 ;
F_77 ( L_46 , V_24 ) ;
F_99 (pte, psize, vpn, index, shift) {
V_21 = F_7 ( V_24 , V_18 , V_14 ) ;
V_181 = F_100 ( V_129 , V_137 ) ;
if ( V_181 & V_183 )
V_21 = ~ V_21 ;
V_182 = ( V_21 & V_26 ) * V_27 ;
V_182 += V_181 & V_184 ;
F_77 ( L_47 , V_137 , V_182 , V_181 ) ;
V_28 . V_185 ( V_182 , V_24 , V_13 , V_14 , V_168 ) ;
} F_101 () ;
#ifdef F_102
if ( V_168 && F_103 ( V_186 ) &&
F_104 ( V_160 -> V_187 . V_188 -> V_189 ) ) {
F_105 () ;
F_106 ( V_190 ) ;
}
#endif
}
void F_107 ( unsigned long V_191 , int V_168 )
{
if ( V_28 . F_107 )
V_28 . F_107 ( V_191 , V_168 ) ;
else {
int V_192 ;
struct V_193 * V_194 =
& F_108 ( V_193 ) ;
for ( V_192 = 0 ; V_192 < V_191 ; V_192 ++ )
F_98 ( V_194 -> V_24 [ V_192 ] , V_194 -> V_129 [ V_192 ] ,
V_194 -> V_13 , V_194 -> V_14 , V_168 ) ;
}
}
void F_109 ( struct V_195 * V_188 , unsigned long V_196 , int V_70 )
{
if ( F_110 ( V_188 ) ) {
#ifdef F_111
if ( V_70 == - 2 )
F_112 ( V_197 , V_188 , V_198 , V_196 ) ;
else
#endif
F_112 ( V_199 , V_188 , V_200 , V_196 ) ;
} else
F_113 ( V_188 , V_196 , V_199 ) ;
}
static void F_114 ( unsigned long V_15 , unsigned long V_201 )
{
unsigned long V_21 , V_22 ;
unsigned long V_23 = F_4 ( V_15 , V_90 ) ;
unsigned long V_24 = F_5 ( V_15 , V_23 , V_90 ) ;
unsigned long V_202 = F_1 ( V_89 ) ;
int V_19 ;
V_21 = F_7 ( V_24 , V_31 , V_90 ) ;
V_22 = ( ( V_21 & V_26 ) * V_27 ) ;
if ( ! V_23 )
return;
V_19 = V_28 . V_29 ( V_22 , V_24 , F_33 ( V_15 ) ,
V_202 , V_30 ,
V_74 , V_90 ) ;
F_8 ( V_19 < 0 ) ;
F_115 ( & V_203 ) ;
F_8 ( V_33 [ V_201 ] & 0x80 ) ;
V_33 [ V_201 ] = V_19 | 0x80 ;
F_116 ( & V_203 ) ;
}
static void F_117 ( unsigned long V_15 , unsigned long V_201 )
{
unsigned long V_21 , V_181 , V_182 ;
unsigned long V_23 = F_4 ( V_15 , V_90 ) ;
unsigned long V_24 = F_5 ( V_15 , V_23 , V_90 ) ;
V_21 = F_7 ( V_24 , V_31 , V_90 ) ;
F_115 ( & V_203 ) ;
F_8 ( ! ( V_33 [ V_201 ] & 0x80 ) ) ;
V_181 = V_33 [ V_201 ] & 0x7f ;
V_33 [ V_201 ] = 0 ;
F_116 ( & V_203 ) ;
if ( V_181 & V_183 )
V_21 = ~ V_21 ;
V_182 = ( V_21 & V_26 ) * V_27 ;
V_182 += V_181 & V_184 ;
V_28 . V_185 ( V_182 , V_24 , V_74 , V_90 , 0 ) ;
}
void F_118 ( struct V_131 * V_131 , int V_204 , int V_205 )
{
unsigned long V_133 , V_15 , V_201 ;
int V_192 ;
F_96 ( V_133 ) ;
for ( V_192 = 0 ; V_192 < V_204 ; V_192 ++ , V_131 ++ ) {
V_15 = ( unsigned long ) F_119 ( V_131 ) ;
V_201 = F_33 ( V_15 ) >> V_31 ;
if ( V_201 >= V_32 )
continue;
if ( V_205 )
F_114 ( V_15 , V_201 ) ;
else
F_117 ( V_15 , V_201 ) ;
}
F_97 ( V_133 ) ;
}
void F_120 ( T_7 V_206 ,
T_7 V_207 )
{
F_8 ( V_206 != 0 ) ;
V_117 = F_121 ( V_124 , V_207 , 0x40000000 ) ;
F_49 ( V_117 ) ;
}
