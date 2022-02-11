unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 = 0 ;
if ( ( V_1 & V_3 ) == 0 )
V_2 |= V_4 ;
if ( V_1 & V_5 ) {
V_2 |= 0x2 ;
if ( ! ( ( V_1 & V_6 ) && ( V_1 & V_7 ) ) )
V_2 |= 0x1 ;
}
V_2 |= V_8 | V_9 ;
if ( V_1 & V_10 )
V_2 |= V_11 ;
if ( V_1 & V_12 )
V_2 |= V_13 ;
if ( V_1 & V_14 )
V_2 |= V_15 ;
return V_2 ;
}
int F_2 ( unsigned long V_16 , unsigned long V_17 ,
unsigned long V_18 , unsigned long V_19 ,
int V_20 , int V_21 )
{
unsigned long V_22 , V_23 ;
unsigned int V_24 , V_25 ;
int V_26 = 0 ;
V_25 = V_27 [ V_20 ] . V_25 ;
V_24 = 1 << V_25 ;
V_19 = F_1 ( V_19 ) ;
F_3 ( L_1 ,
V_16 , V_17 , V_18 , V_19 , V_20 , V_21 ) ;
for ( V_22 = V_16 , V_23 = V_18 ; V_22 < V_17 ;
V_22 += V_24 , V_23 += V_24 ) {
unsigned long V_28 , V_29 ;
unsigned long V_30 = F_4 ( V_22 , V_21 ) ;
unsigned long V_31 = F_5 ( V_22 , V_30 , V_21 ) ;
unsigned long V_32 = V_19 ;
if ( ! V_30 )
return - 1 ;
if ( F_6 ( V_22 , V_22 + V_24 ) )
V_32 &= ~ V_4 ;
if ( F_7 ( V_22 , V_22 + V_24 ) )
V_32 &= ~ V_4 ;
if ( ( V_33 > V_34 ) &&
F_8 ( V_22 , V_22 + V_24 ) )
V_32 &= ~ V_4 ;
V_28 = F_9 ( V_31 , V_25 , V_21 ) ;
V_29 = ( ( V_28 & V_35 ) * V_36 ) ;
F_10 ( ! V_37 . V_38 ) ;
V_26 = V_37 . V_38 ( V_29 , V_31 , V_23 , V_32 ,
V_39 , V_20 , V_20 , V_21 ) ;
if ( V_26 < 0 )
break;
#ifdef F_11
if ( F_12 () &&
( V_23 >> V_40 ) < V_41 )
V_42 [ V_23 >> V_40 ] = V_26 | 0x80 ;
#endif
}
return V_26 < 0 ? V_26 : 0 ;
}
int F_13 ( unsigned long V_16 , unsigned long V_17 ,
int V_20 , int V_21 )
{
unsigned long V_22 ;
unsigned int V_24 , V_25 ;
int V_43 ;
int V_26 = 0 ;
V_25 = V_27 [ V_20 ] . V_25 ;
V_24 = 1 << V_25 ;
if ( ! V_37 . V_44 )
return - V_45 ;
for ( V_22 = V_16 ; V_22 < V_17 ; V_22 += V_24 ) {
V_43 = V_37 . V_44 ( V_22 , V_20 , V_21 ) ;
if ( V_43 == - V_46 ) {
V_26 = - V_46 ;
continue;
}
if ( V_43 < 0 )
return V_43 ;
}
return V_26 ;
}
static int T_1 F_14 ( unsigned long V_47 ,
const char * V_48 , int V_49 ,
void * V_50 )
{
const char * type = F_15 ( V_47 , L_2 , NULL ) ;
const T_2 * V_51 ;
int V_52 = 0 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_51 = F_15 ( V_47 , L_4 , & V_52 ) ;
if ( V_51 == NULL )
return 0 ;
for (; V_52 >= 4 ; V_52 -= 4 , ++ V_51 ) {
if ( F_16 ( V_51 [ 0 ] ) == 40 ) {
F_3 ( L_5 ) ;
V_53 -> V_54 |= V_55 ;
return 1 ;
}
}
V_53 -> V_54 &= ~ V_56 ;
return 0 ;
}
static void T_1 F_17 ( void )
{
F_18 ( F_14 , NULL ) ;
}
static int T_1 F_19 ( unsigned int V_25 )
{
int V_57 = - 1 ;
switch ( V_25 ) {
case 0xc :
V_57 = V_58 ;
break;
case 0x10 :
V_57 = V_59 ;
break;
case 0x14 :
V_57 = V_60 ;
break;
case 0x18 :
V_57 = V_61 ;
break;
case 0x22 :
V_57 = V_62 ;
break;
}
return V_57 ;
}
static int T_1 F_20 ( unsigned long V_47 ,
const char * V_48 , int V_49 ,
void * V_50 )
{
const char * type = F_15 ( V_47 , L_2 , NULL ) ;
const T_2 * V_51 ;
int V_52 = 0 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_51 = F_15 ( V_47 , L_6 , & V_52 ) ;
if ( ! V_51 )
return 0 ;
F_21 ( L_7 ) ;
V_52 /= 4 ;
V_53 -> V_54 &= ~ ( V_63 ) ;
while( V_52 > 0 ) {
unsigned int V_64 = F_16 ( V_51 [ 0 ] ) ;
unsigned int V_65 = F_16 ( V_51 [ 1 ] ) ;
unsigned int V_66 = F_16 ( V_51 [ 2 ] ) ;
struct V_67 * V_68 ;
int V_57 , V_69 ;
V_52 -= 3 ; V_51 += 3 ;
V_69 = F_19 ( V_64 ) ;
if ( V_69 < 0 ) {
V_51 += V_66 * 2 ; V_52 -= V_66 * 2 ;
continue;
}
V_68 = & V_27 [ V_69 ] ;
if ( V_69 == V_61 )
V_53 -> V_54 |= V_63 ;
V_68 -> V_25 = V_64 ;
if ( V_64 <= 23 )
V_68 -> V_70 = 0 ;
else
V_68 -> V_70 = ( 1 << ( V_64 - 23 ) ) - 1 ;
V_68 -> V_71 = V_65 ;
if ( V_69 == V_58 || V_69 == V_59 )
V_68 -> V_72 = 1 ;
else
V_68 -> V_72 = 0 ;
while ( V_52 > 0 && V_66 ) {
unsigned int V_25 = F_16 ( V_51 [ 0 ] ) ;
int V_73 = F_16 ( V_51 [ 1 ] ) ;
V_51 += 2 ; V_52 -= 2 ;
V_66 -- ;
V_57 = F_19 ( V_25 ) ;
if ( V_57 < 0 )
continue;
if ( V_73 == - 1 )
F_22 ( L_8
L_9 , V_64 , V_25 ) ;
V_68 -> V_73 [ V_57 ] = V_73 ;
F_21 ( L_10
L_11 ,
V_64 , V_25 , V_68 -> V_71 ,
V_68 -> V_70 , V_68 -> V_72 , V_68 -> V_73 [ V_57 ] ) ;
}
}
return 1 ;
}
static int T_1 F_23 ( unsigned long V_47 ,
const char * V_48 , int V_49 ,
void * V_50 ) {
const char * type = F_15 ( V_47 , L_2 , NULL ) ;
const T_3 * V_74 ;
const T_2 * V_75 ;
unsigned int V_76 ;
long unsigned int V_77 ;
long unsigned int V_78 ;
if ( type == NULL || strcmp ( type , L_12 ) != 0 )
return 0 ;
V_75 = F_15 ( V_47 , L_13 , NULL ) ;
if ( V_75 == NULL )
return 0 ;
V_76 = ( 1 << F_16 ( V_75 [ 0 ] ) ) ;
V_74 = F_15 ( V_47 , L_14 , NULL ) ;
if ( V_74 == NULL )
return 0 ;
V_77 = F_24 ( V_74 [ 0 ] ) ;
V_78 = F_24 ( V_74 [ 1 ] ) ;
if ( V_78 != ( 16 * V_79 ) )
return 0 ;
F_25 ( V_80 L_15
L_16 ,
V_77 , V_78 , V_76 ) ;
if ( V_77 + ( 16 * V_79 ) <= F_26 () ) {
F_27 ( V_77 , V_78 * V_76 ) ;
F_28 ( V_77 , V_78 , V_76 ) ;
}
return 0 ;
}
static void F_29 ( void )
{
int V_81 , V_82 ;
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ )
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ )
V_27 [ V_81 ] . V_73 [ V_82 ] = - 1 ;
}
static bool F_30 ( void )
{
#ifdef F_31
return ! F_32 ( V_84 ) ;
#else
return false ;
#endif
}
static void T_1 F_33 ( void )
{
int V_43 ;
F_29 () ;
memcpy ( V_27 , V_85 ,
sizeof( V_85 ) ) ;
V_43 = F_18 ( F_20 , NULL ) ;
if ( V_43 != 0 )
goto V_86;
if ( F_34 ( V_63 ) )
memcpy ( V_27 , V_87 ,
sizeof( V_87 ) ) ;
V_86:
if ( ! F_12 () ) {
if ( V_27 [ V_61 ] . V_25 )
V_88 = V_61 ;
else if ( V_27 [ V_60 ] . V_25 )
V_88 = V_60 ;
}
#ifdef F_35
if ( V_27 [ V_59 ] . V_25 ) {
V_89 = V_59 ;
V_90 = V_59 ;
if ( V_88 == V_58 )
V_88 = V_59 ;
if ( F_34 ( V_91 ) ) {
if ( ! F_30 () || ! F_36 ( V_92 ) )
V_93 = V_59 ;
} else
V_94 = 1 ;
}
#endif
#ifdef F_37
if ( V_27 [ V_61 ] . V_25 &&
F_38 () >= 0x40000000 )
V_95 = V_61 ;
else if ( V_27 [ V_59 ] . V_25 )
V_95 = V_59 ;
else
V_95 = V_58 ;
#endif
F_25 ( V_96 L_17
L_18
#ifdef F_37
L_19
#endif
L_20 ,
V_27 [ V_88 ] . V_25 ,
V_27 [ V_89 ] . V_25 ,
V_27 [ V_93 ] . V_25
#ifdef F_37
, V_27 [ V_95 ] . V_25
#endif
) ;
#ifdef F_39
F_18 ( F_23 , NULL ) ;
#endif
}
static int T_1 F_40 ( unsigned long V_47 ,
const char * V_48 , int V_49 ,
void * V_50 )
{
const char * type = F_15 ( V_47 , L_2 , NULL ) ;
const T_2 * V_51 ;
if ( type == NULL || strcmp ( type , L_3 ) != 0 )
return 0 ;
V_51 = F_15 ( V_47 , L_21 , NULL ) ;
if ( V_51 != NULL ) {
V_97 = F_16 ( V_51 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
unsigned F_41 ( unsigned long V_98 )
{
unsigned V_99 = F_42 ( V_98 ) ;
unsigned V_100 = V_27 [ V_89 ] . V_25 ;
unsigned V_101 ;
if ( ( 1UL << V_99 ) < V_98 )
V_99 += 1 ;
V_101 = V_99 - ( V_100 + 1 ) ;
return F_43 ( V_101 + 7 , 18U ) ;
}
static unsigned long T_1 F_44 ( void )
{
if ( V_97 == 0 )
F_18 ( F_40 , NULL ) ;
if ( V_97 )
return 1UL << V_97 ;
return 1UL << F_41 ( F_38 () ) ;
}
int F_45 ( unsigned long V_102 , unsigned long V_103 )
{
int V_43 = F_2 ( V_102 , V_103 , F_46 ( V_102 ) ,
F_47 ( V_104 ) , V_88 ,
V_105 ) ;
if ( V_43 < 0 ) {
int V_106 = F_13 ( V_102 , V_103 , V_88 ,
V_105 ) ;
F_10 ( V_106 && ( V_106 != - V_46 ) ) ;
}
return V_43 ;
}
int F_48 ( unsigned long V_102 , unsigned long V_103 )
{
int V_43 = F_13 ( V_102 , V_103 , V_88 ,
V_105 ) ;
F_49 ( V_43 < 0 ) ;
return V_43 ;
}
static void T_1 F_50 ( void )
{
unsigned long V_107 ;
unsigned long V_108 ;
unsigned long V_19 ;
unsigned long V_109 = 0 , V_52 = 0 , V_110 ;
struct V_111 * V_112 ;
F_3 ( L_22 ) ;
F_17 () ;
F_33 () ;
if ( F_34 ( V_55 ) ) {
V_105 = V_113 ;
V_114 = V_113 ;
F_25 ( V_80 L_23 ) ;
}
V_115 = F_44 () ;
V_108 = V_115 >> 7 ;
V_35 = V_108 - 1 ;
if ( F_51 ( V_116 ) ) {
V_117 = NULL ;
V_118 = 0 ;
#ifdef F_52
if ( F_53 () && V_37 . V_119 )
V_37 . V_119 () ;
#endif
} else {
if ( F_36 ( V_120 ) )
V_110 = 0x80000000 ;
else
V_110 = V_121 ;
V_107 = F_54 ( V_115 , V_115 , V_110 ) ;
F_3 ( L_24 , V_107 ,
V_115 ) ;
V_117 = F_55 ( V_107 ) ;
V_118 = V_107 + F_42 ( V_108 ) - 11 ;
memset ( ( void * ) V_107 , 0 , V_115 ) ;
F_56 ( V_122 , V_118 ) ;
}
V_19 = F_47 ( V_104 ) ;
#ifdef F_11
if ( F_12 () ) {
V_41 = F_26 () >> V_40 ;
V_42 = F_55 ( F_54 (
V_41 , 1 , V_123 ) ) ;
memset ( V_42 , 0 , V_41 ) ;
}
#endif
F_57 (memory, reg) {
V_109 = ( unsigned long ) F_55 ( V_112 -> V_109 ) ;
V_52 = V_112 -> V_52 ;
F_3 ( L_25 ,
V_109 , V_52 , V_19 ) ;
#ifdef F_58
F_3 ( L_26 , V_124 ) ;
if ( V_124 != 0 && V_124 >= V_109
&& V_124 < ( V_109 + V_52 ) ) {
unsigned long V_125 = V_124 + 16 * V_126 ;
if ( V_109 != V_124 )
F_10 ( F_2 ( V_109 , V_124 ,
F_46 ( V_109 ) , V_19 ,
V_88 ,
V_105 ) ) ;
if ( ( V_109 + V_52 ) > V_125 )
F_10 ( F_2 ( V_124 + 16 * V_126 ,
V_109 + V_52 ,
F_46 ( V_125 ) ,
V_19 ,
V_88 ,
V_105 ) ) ;
continue;
}
#endif
F_10 ( F_2 ( V_109 , V_109 + V_52 , F_46 ( V_109 ) ,
V_19 , V_88 , V_105 ) ) ;
}
F_59 ( V_121 ) ;
if ( V_127 ) {
V_127 = ( unsigned long ) F_55 ( V_127 ) ;
V_128 = ( unsigned long ) F_55 ( V_128 ) ;
if ( V_109 + V_52 >= V_127 )
V_127 = V_109 + V_52 + 1 ;
F_10 ( F_2 ( V_127 , V_128 ,
F_46 ( V_127 ) , V_19 ,
V_88 , V_105 ) ) ;
}
F_3 ( L_27 ) ;
}
void T_1 F_60 ( void )
{
F_50 () ;
F_61 () ;
}
void F_62 ( void )
{
if ( ! F_51 ( V_116 ) )
F_56 ( V_122 , V_118 ) ;
F_61 () ;
}
unsigned int F_63 ( unsigned int V_129 , T_4 V_130 , int V_131 )
{
struct V_132 * V_132 ;
if ( ! F_64 ( F_65 ( V_130 ) ) )
return V_129 ;
V_132 = F_66 ( V_130 ) ;
if ( ! F_67 ( V_133 , & V_132 -> V_134 ) && ! F_68 ( V_132 ) ) {
if ( V_131 == 0x400 ) {
F_69 ( V_132 ) ;
F_70 ( V_133 , & V_132 -> V_134 ) ;
} else
V_129 |= V_4 ;
}
return V_129 ;
}
static unsigned int F_71 ( unsigned long V_135 )
{
T_5 V_136 ;
unsigned char * V_137 ;
unsigned long V_138 , V_139 ;
if ( V_135 < V_140 ) {
V_136 = F_72 () -> V_141 ;
V_138 = F_73 ( V_135 ) ;
return ( V_136 >> ( V_138 * 4 ) ) & 0xF ;
}
V_137 = F_72 () -> V_142 ;
V_138 = F_74 ( V_135 ) ;
V_139 = V_138 & 0x1 ;
return ( V_137 [ V_138 >> 1 ] >> ( V_139 * 4 ) ) & 0xF ;
}
unsigned int F_71 ( unsigned long V_135 )
{
return F_72 () -> V_143 ;
}
void F_75 ( struct V_144 * V_145 , unsigned long V_135 )
{
if ( F_76 ( V_145 , V_135 ) == V_58 )
return;
F_77 ( V_145 , V_135 , 1 , V_58 ) ;
F_78 ( V_145 ) ;
if ( ( F_71 ( V_135 ) != V_58 ) && ( V_146 -> V_145 == V_145 ) ) {
F_79 ( & V_145 -> V_147 ) ;
F_80 () ;
}
}
static int F_81 ( struct V_144 * V_145 , unsigned long V_148 )
{
struct V_149 * V_150 = & V_145 -> V_147 . V_150 ;
T_6 V_151 = 0 ;
T_6 * * V_152 , * V_153 ;
if ( V_148 >= V_150 -> V_154 )
return 0 ;
if ( V_148 < 0x100000000UL ) {
V_152 = V_150 -> V_155 ;
} else {
V_152 = V_150 -> V_156 [ V_148 >> V_157 ] ;
if ( ! V_152 )
return 0 ;
}
V_153 = V_152 [ ( V_148 >> V_158 ) & ( V_159 - 1 ) ] ;
if ( ! V_153 )
return 0 ;
V_151 = V_153 [ ( V_148 >> V_40 ) & ( V_160 - 1 ) ] ;
V_151 >>= 30 - 2 * ( ( V_148 >> 12 ) & 0xf ) ;
V_151 = ( ( V_151 & 2 ) ? V_5 : 0 ) | ( ( V_151 & 1 ) ? V_6 : 0 ) ;
return V_151 ;
}
static inline int F_81 ( struct V_144 * V_145 , unsigned long V_148 )
{
return 0 ;
}
void F_82 ( unsigned long V_148 , unsigned long V_161 ,
unsigned long V_30 , unsigned long V_131 ,
int V_21 , int V_20 , int V_162 , unsigned long V_130 )
{
if ( ! F_83 () )
return;
F_21 ( L_28 ,
V_148 , V_161 , V_146 -> V_163 ) ;
F_21 ( L_29 ,
V_131 , V_30 , V_21 , V_20 , V_162 , V_130 ) ;
}
static void F_84 ( unsigned long V_148 , struct V_144 * V_145 ,
int V_20 , bool V_164 )
{
if ( V_164 ) {
if ( V_20 != F_71 ( V_148 ) ) {
F_79 ( & V_145 -> V_147 ) ;
F_80 () ;
}
} else if ( F_72 () -> V_165 !=
V_27 [ V_90 ] . V_71 ) {
F_72 () -> V_165 =
V_27 [ V_90 ] . V_71 ;
F_85 () ;
}
}
int F_86 ( struct V_144 * V_145 , unsigned long V_148 ,
unsigned long V_161 , unsigned long V_131 ,
unsigned long V_134 )
{
bool V_166 ;
enum V_167 V_168 = F_87 () ;
T_7 * V_169 ;
unsigned long V_30 ;
T_4 * V_170 ;
unsigned V_171 ;
const struct V_172 * V_173 ;
int V_43 , V_164 = 0 ;
int V_20 , V_21 ;
F_88 ( L_30 ,
V_148 , V_161 , V_131 ) ;
F_89 ( V_148 , V_161 , V_131 ) ;
switch ( F_90 ( V_148 ) ) {
case V_174 :
V_164 = 1 ;
if ( ! V_145 ) {
F_88 ( L_31 ) ;
V_43 = 1 ;
goto V_175;
}
V_20 = F_76 ( V_145 , V_148 ) ;
V_21 = F_91 ( V_148 ) ;
V_30 = F_92 ( V_145 -> V_147 . V_176 , V_148 , V_21 ) ;
break;
case V_177 :
V_30 = F_4 ( V_148 , V_105 ) ;
if ( V_148 < V_178 )
V_20 = V_90 ;
else
V_20 = V_93 ;
V_21 = V_105 ;
break;
default:
V_43 = 1 ;
goto V_175;
}
F_88 ( L_32 , V_145 , V_145 -> V_179 , V_30 ) ;
if ( ! V_30 ) {
F_88 ( L_33 ) ;
V_43 = 1 ;
goto V_175;
}
V_169 = V_145 -> V_179 ;
if ( V_169 == NULL ) {
V_43 = 1 ;
goto V_175;
}
V_173 = F_93 ( F_94 () ) ;
if ( V_164 && F_95 ( F_96 ( V_145 ) , V_173 ) )
V_134 |= V_180 ;
#ifndef F_35
if ( V_20 != V_58 )
V_148 &= ~ ( ( 1ul << V_27 [ V_20 ] . V_25 ) - 1 ) ;
#endif
V_170 = F_97 ( V_169 , V_148 , & V_166 , & V_171 ) ;
if ( V_170 == NULL || ! F_98 ( * V_170 ) ) {
F_88 ( L_34 ) ;
V_43 = 1 ;
goto V_175;
}
V_161 |= V_181 ;
if ( V_161 & ~ F_99 ( * V_170 ) ) {
F_88 ( L_35 ) ;
V_43 = 1 ;
goto V_175;
}
if ( V_171 ) {
if ( V_166 )
V_43 = F_100 ( V_148 , V_161 , V_30 , ( V_182 * ) V_170 ,
V_131 , V_134 , V_21 , V_20 ) ;
#ifdef F_39
else
V_43 = F_101 ( V_148 , V_161 , V_30 , V_170 , V_131 ,
V_134 , V_21 , V_171 , V_20 ) ;
#else
else {
V_43 = 1 ;
F_49 ( 1 ) ;
}
#endif
if ( V_146 -> V_145 == V_145 )
F_84 ( V_148 , V_145 , V_20 , V_164 ) ;
goto V_175;
}
#ifndef F_35
F_88 ( L_36 , F_99 ( * V_170 ) ) ;
#else
F_88 ( L_37 , F_99 ( * V_170 ) ,
F_99 ( * ( V_170 + V_183 ) ) ) ;
#endif
#ifdef F_35
if ( ( F_99 ( * V_170 ) & V_184 ) && V_20 == V_59 ) {
F_75 ( V_145 , V_148 ) ;
V_20 = V_58 ;
}
if ( V_94 && V_20 == V_59 &&
( F_99 ( * V_170 ) & V_12 ) ) {
if ( V_164 ) {
F_75 ( V_145 , V_148 ) ;
V_20 = V_58 ;
} else if ( V_148 < V_178 ) {
F_25 ( V_185 L_38
L_39
L_40 ) ;
V_20 = V_90 = V_58 ;
F_78 ( V_145 ) ;
}
}
#endif
if ( V_146 -> V_145 == V_145 )
F_84 ( V_148 , V_145 , V_20 , V_164 ) ;
#ifdef F_35
if ( V_20 == V_59 )
V_43 = F_102 ( V_148 , V_161 , V_30 , V_170 , V_131 ,
V_134 , V_21 ) ;
else
#endif
{
int V_151 = F_81 ( V_145 , V_148 ) ;
if ( V_161 & V_151 )
V_43 = - 2 ;
else
V_43 = F_103 ( V_148 , V_161 , V_30 , V_170 , V_131 ,
V_134 , V_21 , V_151 ) ;
}
if ( V_43 == - 1 )
F_82 ( V_148 , V_161 , V_30 , V_131 , V_21 , V_20 ,
V_20 , F_99 ( * V_170 ) ) ;
#ifndef F_35
F_88 ( L_41 , F_99 ( * V_170 ) ) ;
#else
F_88 ( L_42 , F_99 ( * V_170 ) ,
F_99 ( * ( V_170 + V_183 ) ) ) ;
#endif
F_88 ( L_43 , V_43 ) ;
V_175:
F_104 ( V_168 ) ;
return V_43 ;
}
int F_105 ( unsigned long V_148 , unsigned long V_161 , unsigned long V_131 ,
unsigned long V_186 )
{
unsigned long V_134 = 0 ;
struct V_144 * V_145 = V_146 -> V_145 ;
if ( F_90 ( V_148 ) == V_177 )
V_145 = & V_187 ;
if ( V_186 & V_188 )
V_134 |= V_189 ;
return F_86 ( V_145 , V_148 , V_161 , V_131 , V_134 ) ;
}
int F_106 ( unsigned long V_148 , unsigned long V_190 , unsigned long V_131 ,
unsigned long V_186 )
{
unsigned long V_161 = V_181 ;
unsigned long V_134 = 0 ;
struct V_144 * V_145 = V_146 -> V_145 ;
if ( F_90 ( V_148 ) == V_177 )
V_145 = & V_187 ;
if ( V_186 & V_188 )
V_134 |= V_189 ;
if ( V_186 & V_191 )
V_161 |= V_6 ;
if ( ( V_190 & V_192 ) || ( F_90 ( V_148 ) == V_174 ) )
V_161 |= V_5 ;
if ( V_131 == 0x400 )
V_161 |= V_3 ;
return F_86 ( V_145 , V_148 , V_161 , V_131 , V_134 ) ;
}
void F_107 ( struct V_144 * V_145 , unsigned long V_148 ,
unsigned long V_161 , unsigned long V_131 )
{
int V_193 ;
unsigned long V_30 ;
T_7 * V_169 ;
T_4 * V_170 ;
unsigned long V_134 ;
int V_43 , V_21 , V_194 = 0 ;
F_10 ( F_90 ( V_148 ) != V_174 ) ;
#ifdef F_108
if ( F_109 ( F_76 ( V_145 , V_148 ) != V_145 -> V_147 . V_195 ) )
return;
#endif
F_88 ( L_44
L_45 , V_145 , V_145 -> V_179 , V_148 , V_161 , V_131 ) ;
V_169 = V_145 -> V_179 ;
if ( V_169 == NULL )
return;
V_21 = F_91 ( V_148 ) ;
V_30 = F_92 ( V_145 -> V_147 . V_176 , V_148 , V_21 ) ;
if ( ! V_30 )
return;
F_110 ( V_134 ) ;
V_170 = F_111 ( V_169 , V_148 , NULL , & V_193 ) ;
if ( ! V_170 )
goto V_196;
F_49 ( V_193 ) ;
#ifdef F_35
if ( F_99 ( * V_170 ) & ( V_184 | V_12 ) )
goto V_196;
#endif
if ( F_95 ( F_96 ( V_145 ) , F_93 ( F_94 () ) ) )
V_194 |= V_180 ;
#ifdef F_35
if ( V_145 -> V_147 . V_195 == V_59 )
V_43 = F_102 ( V_148 , V_161 , V_30 , V_170 , V_131 ,
V_194 , V_21 ) ;
else
#endif
V_43 = F_103 ( V_148 , V_161 , V_30 , V_170 , V_131 , V_194 ,
V_21 , F_81 ( V_145 , V_148 ) ) ;
if ( V_43 == - 1 )
F_82 ( V_148 , V_161 , V_30 , V_131 , V_21 ,
V_145 -> V_147 . V_195 ,
V_145 -> V_147 . V_195 ,
F_99 ( * V_170 ) ) ;
V_196:
F_112 ( V_134 ) ;
}
void F_113 ( unsigned long V_31 , T_8 V_130 , int V_20 , int V_21 ,
unsigned long V_134 )
{
unsigned long V_28 , V_138 , V_25 , V_197 , V_198 ;
int V_199 = V_134 & V_180 ;
F_88 ( L_46 , V_31 ) ;
F_114 (pte, psize, vpn, index, shift) {
V_28 = F_9 ( V_31 , V_25 , V_21 ) ;
V_197 = F_115 ( V_130 , V_138 ) ;
if ( V_197 & V_200 )
V_28 = ~ V_28 ;
V_198 = ( V_28 & V_35 ) * V_36 ;
V_198 += V_197 & V_201 ;
F_88 ( L_47 , V_138 , V_198 , V_197 ) ;
V_37 . V_202 ( V_198 , V_31 , V_20 , V_20 , V_21 , V_199 ) ;
} F_116 () ;
#ifdef F_117
if ( V_199 && F_32 ( V_203 ) &&
V_146 -> V_204 . V_205 &&
F_118 ( V_146 -> V_204 . V_205 -> V_190 ) ) {
F_119 () ;
F_120 ( V_206 ) ;
}
#endif
}
void F_121 ( unsigned long V_30 , unsigned long V_135 ,
V_182 * V_207 , unsigned int V_20 , int V_21 ,
unsigned long V_134 )
{
int V_208 , V_209 , V_210 ;
unsigned long V_211 ;
unsigned char * V_212 ;
unsigned long V_197 , V_25 , V_31 , V_28 , V_198 ;
int V_199 = V_134 & V_180 ;
V_211 = V_135 & V_213 ;
V_212 = F_122 ( V_207 ) ;
if ( ! V_212 )
return;
if ( V_37 . V_214 ) {
V_37 . V_214 ( V_30 , V_211 , V_212 ,
V_20 , V_21 , V_199 ) ;
goto F_120;
}
V_25 = V_27 [ V_20 ] . V_25 ;
V_209 = V_215 >> V_25 ;
for ( V_208 = 0 ; V_208 < V_209 ; V_208 ++ ) {
V_210 = F_123 ( V_212 , V_208 ) ;
if ( ! V_210 )
continue;
V_197 = F_124 ( V_212 , V_208 ) ;
V_135 = V_211 + ( V_208 * ( 1ul << V_25 ) ) ;
V_31 = F_5 ( V_135 , V_30 , V_21 ) ;
V_28 = F_9 ( V_31 , V_25 , V_21 ) ;
if ( V_197 & V_200 )
V_28 = ~ V_28 ;
V_198 = ( V_28 & V_35 ) * V_36 ;
V_198 += V_197 & V_201 ;
V_37 . V_202 ( V_198 , V_31 , V_20 ,
V_61 , V_21 , V_199 ) ;
}
F_120:
#ifdef F_117
if ( V_199 && F_32 ( V_203 ) &&
V_146 -> V_204 . V_205 &&
F_118 ( V_146 -> V_204 . V_205 -> V_190 ) ) {
F_119 () ;
F_120 ( V_206 ) ;
}
#endif
return;
}
void F_125 ( unsigned long V_216 , int V_199 )
{
if ( V_37 . F_125 )
V_37 . F_125 ( V_216 , V_199 ) ;
else {
int V_208 ;
struct V_217 * V_218 =
F_126 ( & V_217 ) ;
for ( V_208 = 0 ; V_208 < V_216 ; V_208 ++ )
F_113 ( V_218 -> V_31 [ V_208 ] , V_218 -> V_130 [ V_208 ] ,
V_218 -> V_20 , V_218 -> V_21 , V_199 ) ;
}
}
void F_127 ( struct V_219 * V_205 , unsigned long V_220 , int V_43 )
{
enum V_167 V_168 = F_87 () ;
if ( F_128 ( V_205 ) ) {
#ifdef F_129
if ( V_43 == - 2 )
F_130 ( V_221 , V_205 , V_222 , V_220 ) ;
else
#endif
F_130 ( V_223 , V_205 , V_224 , V_220 ) ;
} else
F_131 ( V_205 , V_220 , V_223 ) ;
F_104 ( V_168 ) ;
}
long F_132 ( unsigned long V_28 , unsigned long V_31 ,
unsigned long V_225 , unsigned long V_2 ,
unsigned long V_226 , int V_20 , int V_21 )
{
unsigned long V_227 ;
long V_198 ;
V_228:
V_227 = ( ( V_28 & V_35 ) *
V_36 ) & ~ 0x7UL ;
V_198 = V_37 . V_38 ( V_227 , V_31 , V_225 , V_2 , V_226 ,
V_20 , V_20 , V_21 ) ;
if ( F_109 ( V_198 == - 1 ) ) {
V_227 = ( ( ~ V_28 & V_35 ) *
V_36 ) & ~ 0x7UL ;
V_198 = V_37 . V_38 ( V_227 , V_31 , V_225 , V_2 ,
V_226 | V_229 ,
V_20 , V_20 , V_21 ) ;
if ( V_198 == - 1 ) {
if ( F_133 () & 0x1 )
V_227 = ( ( V_28 & V_35 ) *
V_36 ) & ~ 0x7UL ;
V_37 . V_230 ( V_227 ) ;
goto V_228;
}
}
return V_198 ;
}
static void F_134 ( unsigned long V_22 , unsigned long V_231 )
{
unsigned long V_28 ;
unsigned long V_30 = F_4 ( V_22 , V_105 ) ;
unsigned long V_31 = F_5 ( V_22 , V_30 , V_105 ) ;
unsigned long V_232 = F_1 ( F_47 ( V_104 ) ) ;
long V_26 ;
V_28 = F_9 ( V_31 , V_40 , V_105 ) ;
if ( ! V_30 )
return;
V_26 = F_132 ( V_28 , V_31 , F_46 ( V_22 ) , V_232 ,
V_39 ,
V_88 , V_105 ) ;
F_10 ( V_26 < 0 ) ;
F_135 ( & V_233 ) ;
F_10 ( V_42 [ V_231 ] & 0x80 ) ;
V_42 [ V_231 ] = V_26 | 0x80 ;
F_136 ( & V_233 ) ;
}
static void F_137 ( unsigned long V_22 , unsigned long V_231 )
{
unsigned long V_28 , V_197 , V_198 ;
unsigned long V_30 = F_4 ( V_22 , V_105 ) ;
unsigned long V_31 = F_5 ( V_22 , V_30 , V_105 ) ;
V_28 = F_9 ( V_31 , V_40 , V_105 ) ;
F_135 ( & V_233 ) ;
F_10 ( ! ( V_42 [ V_231 ] & 0x80 ) ) ;
V_197 = V_42 [ V_231 ] & 0x7f ;
V_42 [ V_231 ] = 0 ;
F_136 ( & V_233 ) ;
if ( V_197 & V_200 )
V_28 = ~ V_28 ;
V_198 = ( V_28 & V_35 ) * V_36 ;
V_198 += V_197 & V_201 ;
V_37 . V_202 ( V_198 , V_31 , V_88 , V_88 ,
V_105 , 0 ) ;
}
void F_138 ( struct V_132 * V_132 , int V_234 , int V_235 )
{
unsigned long V_134 , V_22 , V_231 ;
int V_208 ;
F_110 ( V_134 ) ;
for ( V_208 = 0 ; V_208 < V_234 ; V_208 ++ , V_132 ++ ) {
V_22 = ( unsigned long ) F_139 ( V_132 ) ;
V_231 = F_46 ( V_22 ) >> V_40 ;
if ( V_231 >= V_41 )
continue;
if ( V_235 )
F_134 ( V_22 , V_231 ) ;
else
F_137 ( V_22 , V_231 ) ;
}
F_112 ( V_134 ) ;
}
void F_140 ( T_9 V_236 ,
T_9 V_237 )
{
F_10 ( V_236 != 0 ) ;
V_123 = F_141 ( T_5 , V_237 , 0x40000000 ) ;
F_59 ( V_123 ) ;
}
