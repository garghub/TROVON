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
if ( ( V_23 >> V_40 ) < V_41 )
V_42 [ V_23 >> V_40 ] = V_26 | 0x80 ;
#endif
}
return V_26 < 0 ? V_26 : 0 ;
}
int F_12 ( unsigned long V_16 , unsigned long V_17 ,
int V_20 , int V_21 )
{
unsigned long V_22 ;
unsigned int V_24 , V_25 ;
V_25 = V_27 [ V_20 ] . V_25 ;
V_24 = 1 << V_25 ;
if ( ! V_37 . V_43 ) {
F_13 ( V_44 L_2
L_3 ) ;
return - V_45 ;
}
for ( V_22 = V_16 ; V_22 < V_17 ; V_22 += V_24 )
V_37 . V_43 ( V_22 , V_20 , V_21 ) ;
return 0 ;
}
static int T_1 F_14 ( unsigned long V_46 ,
const char * V_47 , int V_48 ,
void * V_49 )
{
const char * type = F_15 ( V_46 , L_4 , NULL ) ;
const T_2 * V_50 ;
int V_51 = 0 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_50 = F_15 ( V_46 , L_6 , & V_51 ) ;
if ( V_50 == NULL )
return 0 ;
for (; V_51 >= 4 ; V_51 -= 4 , ++ V_50 ) {
if ( F_16 ( V_50 [ 0 ] ) == 40 ) {
F_3 ( L_7 ) ;
V_52 -> V_53 |= V_54 ;
return 1 ;
}
}
V_52 -> V_53 &= ~ V_55 ;
return 0 ;
}
static void T_1 F_17 ( void )
{
F_18 ( F_14 , NULL ) ;
}
static int T_1 F_19 ( unsigned int V_25 )
{
int V_56 = - 1 ;
switch ( V_25 ) {
case 0xc :
V_56 = V_57 ;
break;
case 0x10 :
V_56 = V_58 ;
break;
case 0x14 :
V_56 = V_59 ;
break;
case 0x18 :
V_56 = V_60 ;
break;
case 0x22 :
V_56 = V_61 ;
break;
}
return V_56 ;
}
static int T_1 F_20 ( unsigned long V_46 ,
const char * V_47 , int V_48 ,
void * V_49 )
{
const char * type = F_15 ( V_46 , L_4 , NULL ) ;
const T_2 * V_50 ;
int V_51 = 0 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_50 = F_15 ( V_46 , L_8 , & V_51 ) ;
if ( ! V_50 )
return 0 ;
F_21 ( L_9 ) ;
V_51 /= 4 ;
V_52 -> V_53 &= ~ ( V_62 ) ;
while( V_51 > 0 ) {
unsigned int V_63 = F_16 ( V_50 [ 0 ] ) ;
unsigned int V_64 = F_16 ( V_50 [ 1 ] ) ;
unsigned int V_65 = F_16 ( V_50 [ 2 ] ) ;
struct V_66 * V_67 ;
int V_56 , V_68 ;
V_51 -= 3 ; V_50 += 3 ;
V_68 = F_19 ( V_63 ) ;
if ( V_68 < 0 ) {
V_50 += V_65 * 2 ; V_51 -= V_65 * 2 ;
continue;
}
V_67 = & V_27 [ V_68 ] ;
if ( V_68 == V_60 )
V_52 -> V_53 |= V_62 ;
V_67 -> V_25 = V_63 ;
if ( V_63 <= 23 )
V_67 -> V_69 = 0 ;
else
V_67 -> V_69 = ( 1 << ( V_63 - 23 ) ) - 1 ;
V_67 -> V_70 = V_64 ;
if ( V_68 == V_57 || V_68 == V_58 )
V_67 -> V_71 = 1 ;
else
V_67 -> V_71 = 0 ;
while ( V_51 > 0 && V_65 ) {
unsigned int V_25 = F_16 ( V_50 [ 0 ] ) ;
int V_72 = F_16 ( V_50 [ 1 ] ) ;
V_50 += 2 ; V_51 -= 2 ;
V_65 -- ;
V_56 = F_19 ( V_25 ) ;
if ( V_56 < 0 )
continue;
if ( V_72 == - 1 )
F_22 ( L_10
L_11 , V_63 , V_25 ) ;
V_67 -> V_72 [ V_56 ] = V_72 ;
F_21 ( L_12
L_13 ,
V_63 , V_25 , V_67 -> V_70 ,
V_67 -> V_69 , V_67 -> V_71 , V_67 -> V_72 [ V_56 ] ) ;
}
}
return 1 ;
}
static int T_1 F_23 ( unsigned long V_46 ,
const char * V_47 , int V_48 ,
void * V_49 ) {
const char * type = F_15 ( V_46 , L_4 , NULL ) ;
const T_3 * V_73 ;
const T_2 * V_74 ;
unsigned int V_75 ;
long unsigned int V_76 ;
long unsigned int V_77 ;
if ( type == NULL || strcmp ( type , L_14 ) != 0 )
return 0 ;
V_74 = F_15 ( V_46 , L_15 , NULL ) ;
if ( V_74 == NULL )
return 0 ;
V_75 = ( 1 << F_16 ( V_74 [ 0 ] ) ) ;
V_73 = F_15 ( V_46 , L_16 , NULL ) ;
if ( V_73 == NULL )
return 0 ;
V_76 = F_24 ( V_73 [ 0 ] ) ;
V_77 = F_24 ( V_73 [ 1 ] ) ;
if ( V_77 != ( 16 * V_78 ) )
return 0 ;
F_13 ( V_79 L_17
L_18 ,
V_76 , V_77 , V_75 ) ;
if ( V_76 + ( 16 * V_78 ) <= F_25 () ) {
F_26 ( V_76 , V_77 * V_75 ) ;
F_27 ( V_76 , V_77 , V_75 ) ;
}
return 0 ;
}
static void F_28 ( void )
{
int V_80 , V_81 ;
for ( V_80 = 0 ; V_80 < V_82 ; V_80 ++ )
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ )
V_27 [ V_80 ] . V_72 [ V_81 ] = - 1 ;
}
static bool F_29 ( void )
{
#ifdef F_30
return ! F_31 ( V_83 ) ;
#else
return false ;
#endif
}
static void T_1 F_32 ( void )
{
int V_84 ;
F_28 () ;
memcpy ( V_27 , V_85 ,
sizeof( V_85 ) ) ;
V_84 = F_18 ( F_20 , NULL ) ;
if ( V_84 != 0 )
goto V_86;
if ( F_33 ( V_62 ) )
memcpy ( V_27 , V_87 ,
sizeof( V_87 ) ) ;
V_86:
#ifndef F_11
if ( V_27 [ V_60 ] . V_25 )
V_88 = V_60 ;
else if ( V_27 [ V_59 ] . V_25 )
V_88 = V_59 ;
#endif
#ifdef F_34
if ( V_27 [ V_58 ] . V_25 ) {
V_89 = V_58 ;
V_90 = V_58 ;
if ( V_88 == V_57 )
V_88 = V_58 ;
if ( F_33 ( V_91 ) ) {
if ( ! F_29 () || ! F_35 ( V_92 ) )
V_93 = V_58 ;
} else
V_94 = 1 ;
}
#endif
#ifdef F_36
if ( V_27 [ V_60 ] . V_25 &&
F_37 () >= 0x40000000 )
V_95 = V_60 ;
else if ( V_27 [ V_58 ] . V_25 )
V_95 = V_58 ;
else
V_95 = V_57 ;
#endif
F_13 ( V_96 L_19
L_20
#ifdef F_36
L_21
#endif
L_22 ,
V_27 [ V_88 ] . V_25 ,
V_27 [ V_89 ] . V_25 ,
V_27 [ V_93 ] . V_25
#ifdef F_36
, V_27 [ V_95 ] . V_25
#endif
) ;
#ifdef F_38
F_18 ( F_23 , NULL ) ;
#endif
}
static int T_1 F_39 ( unsigned long V_46 ,
const char * V_47 , int V_48 ,
void * V_49 )
{
const char * type = F_15 ( V_46 , L_4 , NULL ) ;
const T_2 * V_50 ;
if ( type == NULL || strcmp ( type , L_5 ) != 0 )
return 0 ;
V_50 = F_15 ( V_46 , L_23 , NULL ) ;
if ( V_50 != NULL ) {
V_97 = F_16 ( V_50 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
static unsigned long T_1 F_40 ( void )
{
unsigned long V_98 , V_99 , V_100 , V_20 ;
if ( V_97 == 0 )
F_18 ( F_39 , NULL ) ;
if ( V_97 )
return 1UL << V_97 ;
V_98 = F_37 () ;
V_99 = 1UL << F_41 ( V_98 ) ;
if ( V_99 < V_98 )
V_99 <<= 1 ;
V_20 = V_27 [ V_89 ] . V_25 ;
V_100 = F_42 ( V_99 >> ( V_20 + 1 ) , 1UL << 11 ) ;
return V_100 << 7 ;
}
int F_43 ( unsigned long V_101 , unsigned long V_102 )
{
return F_2 ( V_101 , V_102 , F_44 ( V_101 ) ,
F_45 ( V_103 ) , V_88 ,
V_104 ) ;
}
int F_46 ( unsigned long V_101 , unsigned long V_102 )
{
return F_12 ( V_101 , V_102 , V_88 ,
V_104 ) ;
}
static void T_1 F_47 ( void )
{
unsigned long V_105 ;
unsigned long V_100 ;
unsigned long V_19 ;
unsigned long V_106 = 0 , V_51 = 0 , V_107 ;
struct V_108 * V_109 ;
F_3 ( L_24 ) ;
F_17 () ;
F_32 () ;
if ( F_33 ( V_54 ) ) {
V_104 = V_110 ;
V_111 = V_110 ;
F_13 ( V_79 L_25 ) ;
}
V_112 = F_40 () ;
V_100 = V_112 >> 7 ;
V_35 = V_100 - 1 ;
if ( F_48 ( V_113 ) ) {
V_114 = NULL ;
V_115 = 0 ;
#ifdef F_49
if ( F_50 () && V_37 . V_116 )
V_37 . V_116 () ;
#endif
} else {
if ( F_35 ( V_117 ) )
V_107 = 0x80000000 ;
else
V_107 = V_118 ;
V_105 = F_51 ( V_112 , V_112 , V_107 ) ;
F_3 ( L_26 , V_105 ,
V_112 ) ;
V_114 = F_52 ( V_105 ) ;
V_115 = V_105 + F_41 ( V_100 ) - 11 ;
memset ( ( void * ) V_105 , 0 , V_112 ) ;
F_53 ( V_119 , V_115 ) ;
}
V_19 = F_45 ( V_103 ) ;
#ifdef F_11
V_41 = F_25 () >> V_40 ;
V_42 = F_52 ( F_51 ( V_41 ,
1 , V_120 ) ) ;
memset ( V_42 , 0 , V_41 ) ;
#endif
F_54 (memory, reg) {
V_106 = ( unsigned long ) F_52 ( V_109 -> V_106 ) ;
V_51 = V_109 -> V_51 ;
F_3 ( L_27 ,
V_106 , V_51 , V_19 ) ;
#ifdef F_55
F_3 ( L_28 , V_121 ) ;
if ( V_121 != 0 && V_121 >= V_106
&& V_121 < ( V_106 + V_51 ) ) {
unsigned long V_122 = V_121 + 16 * V_123 ;
if ( V_106 != V_121 )
F_10 ( F_2 ( V_106 , V_121 ,
F_44 ( V_106 ) , V_19 ,
V_88 ,
V_104 ) ) ;
if ( ( V_106 + V_51 ) > V_122 )
F_10 ( F_2 ( V_121 + 16 * V_123 ,
V_106 + V_51 ,
F_44 ( V_122 ) ,
V_19 ,
V_88 ,
V_104 ) ) ;
continue;
}
#endif
F_10 ( F_2 ( V_106 , V_106 + V_51 , F_44 ( V_106 ) ,
V_19 , V_88 , V_104 ) ) ;
}
F_56 ( V_118 ) ;
if ( V_124 ) {
V_124 = ( unsigned long ) F_52 ( V_124 ) ;
V_125 = ( unsigned long ) F_52 ( V_125 ) ;
if ( V_106 + V_51 >= V_124 )
V_124 = V_106 + V_51 + 1 ;
F_10 ( F_2 ( V_124 , V_125 ,
F_44 ( V_124 ) , V_19 ,
V_88 , V_104 ) ) ;
}
F_3 ( L_29 ) ;
}
void T_1 F_57 ( void )
{
F_47 () ;
F_58 () ;
}
void F_59 ( void )
{
if ( ! F_48 ( V_113 ) )
F_53 ( V_119 , V_115 ) ;
F_58 () ;
}
unsigned int F_60 ( unsigned int V_126 , T_4 V_127 , int V_128 )
{
struct V_129 * V_129 ;
if ( ! F_61 ( F_62 ( V_127 ) ) )
return V_126 ;
V_129 = F_63 ( V_127 ) ;
if ( ! F_64 ( V_130 , & V_129 -> V_131 ) && ! F_65 ( V_129 ) ) {
if ( V_128 == 0x400 ) {
F_66 ( V_129 ) ;
F_67 ( V_130 , & V_129 -> V_131 ) ;
} else
V_126 |= V_4 ;
}
return V_126 ;
}
static unsigned int F_68 ( unsigned long V_132 )
{
T_5 V_133 ;
unsigned char * V_134 ;
unsigned long V_135 , V_136 ;
if ( V_132 < V_137 ) {
V_133 = F_69 () -> V_138 ;
V_135 = F_70 ( V_132 ) ;
return ( V_133 >> ( V_135 * 4 ) ) & 0xF ;
}
V_134 = F_69 () -> V_139 ;
V_135 = F_71 ( V_132 ) ;
V_136 = V_135 & 0x1 ;
return ( V_134 [ V_135 >> 1 ] >> ( V_136 * 4 ) ) & 0xF ;
}
unsigned int F_68 ( unsigned long V_132 )
{
return F_69 () -> V_140 ;
}
void F_72 ( struct V_141 * V_142 , unsigned long V_132 )
{
if ( F_73 ( V_142 , V_132 ) == V_57 )
return;
F_74 ( V_142 , V_132 , 1 , V_57 ) ;
F_75 ( V_142 ) ;
if ( ( F_68 ( V_132 ) != V_57 ) && ( V_143 -> V_142 == V_142 ) ) {
F_76 ( & V_142 -> V_144 ) ;
F_77 () ;
}
}
static int F_78 ( struct V_141 * V_142 , unsigned long V_145 )
{
struct V_146 * V_147 = & V_142 -> V_144 . V_147 ;
T_6 V_148 = 0 ;
T_6 * * V_149 , * V_150 ;
if ( V_145 >= V_147 -> V_151 )
return 0 ;
if ( V_145 < 0x100000000UL ) {
V_149 = V_147 -> V_152 ;
} else {
V_149 = V_147 -> V_153 [ V_145 >> V_154 ] ;
if ( ! V_149 )
return 0 ;
}
V_150 = V_149 [ ( V_145 >> V_155 ) & ( V_156 - 1 ) ] ;
if ( ! V_150 )
return 0 ;
V_148 = V_150 [ ( V_145 >> V_40 ) & ( V_157 - 1 ) ] ;
V_148 >>= 30 - 2 * ( ( V_145 >> 12 ) & 0xf ) ;
V_148 = ( ( V_148 & 2 ) ? V_5 : 0 ) | ( ( V_148 & 1 ) ? V_6 : 0 ) ;
return V_148 ;
}
static inline int F_78 ( struct V_141 * V_142 , unsigned long V_145 )
{
return 0 ;
}
void F_79 ( unsigned long V_145 , unsigned long V_158 ,
unsigned long V_30 , unsigned long V_128 ,
int V_21 , int V_20 , int V_159 , unsigned long V_127 )
{
if ( ! F_80 () )
return;
F_21 ( L_30 ,
V_145 , V_158 , V_143 -> V_160 ) ;
F_21 ( L_31 ,
V_128 , V_30 , V_21 , V_20 , V_159 , V_127 ) ;
}
static void F_81 ( unsigned long V_145 , struct V_141 * V_142 ,
int V_20 , bool V_161 )
{
if ( V_161 ) {
if ( V_20 != F_68 ( V_145 ) ) {
F_76 ( & V_142 -> V_144 ) ;
F_77 () ;
}
} else if ( F_69 () -> V_162 !=
V_27 [ V_90 ] . V_70 ) {
F_69 () -> V_162 =
V_27 [ V_90 ] . V_70 ;
F_82 () ;
}
}
int F_83 ( struct V_141 * V_142 , unsigned long V_145 ,
unsigned long V_158 , unsigned long V_128 ,
unsigned long V_131 )
{
bool V_163 ;
enum V_164 V_165 = F_84 () ;
T_7 * V_166 ;
unsigned long V_30 ;
T_4 * V_167 ;
unsigned V_168 ;
const struct V_169 * V_170 ;
int V_84 , V_161 = 0 ;
int V_20 , V_21 ;
F_85 ( L_32 ,
V_145 , V_158 , V_128 ) ;
F_86 ( V_145 , V_158 , V_128 ) ;
switch ( F_87 ( V_145 ) ) {
case V_171 :
V_161 = 1 ;
if ( ! V_142 ) {
F_85 ( L_33 ) ;
V_84 = 1 ;
goto V_172;
}
V_20 = F_73 ( V_142 , V_145 ) ;
V_21 = F_88 ( V_145 ) ;
V_30 = F_89 ( V_142 -> V_144 . V_173 , V_145 , V_21 ) ;
break;
case V_174 :
V_30 = F_4 ( V_145 , V_104 ) ;
if ( V_145 < V_175 )
V_20 = V_90 ;
else
V_20 = V_93 ;
V_21 = V_104 ;
break;
default:
V_84 = 1 ;
goto V_172;
}
F_85 ( L_34 , V_142 , V_142 -> V_176 , V_30 ) ;
if ( ! V_30 ) {
F_85 ( L_35 ) ;
V_84 = 1 ;
goto V_172;
}
V_166 = V_142 -> V_176 ;
if ( V_166 == NULL ) {
V_84 = 1 ;
goto V_172;
}
V_170 = F_90 ( F_91 () ) ;
if ( V_161 && F_92 ( F_93 ( V_142 ) , V_170 ) )
V_131 |= V_177 ;
#ifndef F_34
if ( V_20 != V_57 )
V_145 &= ~ ( ( 1ul << V_27 [ V_20 ] . V_25 ) - 1 ) ;
#endif
V_167 = F_94 ( V_166 , V_145 , & V_163 , & V_168 ) ;
if ( V_167 == NULL || ! F_95 ( * V_167 ) ) {
F_85 ( L_36 ) ;
V_84 = 1 ;
goto V_172;
}
V_158 |= V_178 ;
if ( V_158 & ~ F_96 ( * V_167 ) ) {
F_85 ( L_37 ) ;
V_84 = 1 ;
goto V_172;
}
if ( V_168 ) {
if ( V_163 )
V_84 = F_97 ( V_145 , V_158 , V_30 , ( V_179 * ) V_167 ,
V_128 , V_131 , V_21 , V_20 ) ;
#ifdef F_38
else
V_84 = F_98 ( V_145 , V_158 , V_30 , V_167 , V_128 ,
V_131 , V_21 , V_168 , V_20 ) ;
#else
else {
V_84 = 1 ;
F_99 ( 1 ) ;
}
#endif
if ( V_143 -> V_142 == V_142 )
F_81 ( V_145 , V_142 , V_20 , V_161 ) ;
goto V_172;
}
#ifndef F_34
F_85 ( L_38 , F_96 ( * V_167 ) ) ;
#else
F_85 ( L_39 , F_96 ( * V_167 ) ,
F_96 ( * ( V_167 + V_180 ) ) ) ;
#endif
#ifdef F_34
if ( ( F_96 ( * V_167 ) & V_181 ) && V_20 == V_58 ) {
F_72 ( V_142 , V_145 ) ;
V_20 = V_57 ;
}
if ( V_94 && V_20 == V_58 &&
( F_96 ( * V_167 ) & V_12 ) ) {
if ( V_161 ) {
F_72 ( V_142 , V_145 ) ;
V_20 = V_57 ;
} else if ( V_145 < V_175 ) {
F_13 ( V_182 L_40
L_41
L_42 ) ;
V_20 = V_90 = V_57 ;
F_75 ( V_142 ) ;
}
}
#endif
if ( V_143 -> V_142 == V_142 )
F_81 ( V_145 , V_142 , V_20 , V_161 ) ;
#ifdef F_34
if ( V_20 == V_58 )
V_84 = F_100 ( V_145 , V_158 , V_30 , V_167 , V_128 ,
V_131 , V_21 ) ;
else
#endif
{
int V_148 = F_78 ( V_142 , V_145 ) ;
if ( V_158 & V_148 )
V_84 = - 2 ;
else
V_84 = F_101 ( V_145 , V_158 , V_30 , V_167 , V_128 ,
V_131 , V_21 , V_148 ) ;
}
if ( V_84 == - 1 )
F_79 ( V_145 , V_158 , V_30 , V_128 , V_21 , V_20 ,
V_20 , F_96 ( * V_167 ) ) ;
#ifndef F_34
F_85 ( L_43 , F_96 ( * V_167 ) ) ;
#else
F_85 ( L_44 , F_96 ( * V_167 ) ,
F_96 ( * ( V_167 + V_180 ) ) ) ;
#endif
F_85 ( L_45 , V_84 ) ;
V_172:
F_102 ( V_165 ) ;
return V_84 ;
}
int F_103 ( unsigned long V_145 , unsigned long V_158 , unsigned long V_128 ,
unsigned long V_183 )
{
unsigned long V_131 = 0 ;
struct V_141 * V_142 = V_143 -> V_142 ;
if ( F_87 ( V_145 ) == V_174 )
V_142 = & V_184 ;
if ( V_183 & V_185 )
V_131 |= V_186 ;
return F_83 ( V_142 , V_145 , V_158 , V_128 , V_131 ) ;
}
int F_104 ( unsigned long V_145 , unsigned long V_187 , unsigned long V_128 ,
unsigned long V_183 )
{
unsigned long V_158 = V_178 ;
unsigned long V_131 = 0 ;
struct V_141 * V_142 = V_143 -> V_142 ;
if ( F_87 ( V_145 ) == V_174 )
V_142 = & V_184 ;
if ( V_183 & V_185 )
V_131 |= V_186 ;
if ( V_183 & V_188 )
V_158 |= V_6 ;
if ( ( V_187 & V_189 ) || ( F_87 ( V_145 ) == V_171 ) )
V_158 |= V_5 ;
if ( V_128 == 0x400 )
V_158 |= V_3 ;
return F_83 ( V_142 , V_145 , V_158 , V_128 , V_131 ) ;
}
void F_105 ( struct V_141 * V_142 , unsigned long V_145 ,
unsigned long V_158 , unsigned long V_128 )
{
int V_190 ;
unsigned long V_30 ;
T_7 * V_166 ;
T_4 * V_167 ;
unsigned long V_131 ;
int V_84 , V_21 , V_191 = 0 ;
F_10 ( F_87 ( V_145 ) != V_171 ) ;
#ifdef F_106
if ( F_107 ( F_73 ( V_142 , V_145 ) != V_142 -> V_144 . V_192 ) )
return;
#endif
F_85 ( L_46
L_47 , V_142 , V_142 -> V_176 , V_145 , V_158 , V_128 ) ;
V_166 = V_142 -> V_176 ;
if ( V_166 == NULL )
return;
V_21 = F_88 ( V_145 ) ;
V_30 = F_89 ( V_142 -> V_144 . V_173 , V_145 , V_21 ) ;
if ( ! V_30 )
return;
F_108 ( V_131 ) ;
V_167 = F_109 ( V_166 , V_145 , NULL , & V_190 ) ;
if ( ! V_167 )
goto V_193;
F_99 ( V_190 ) ;
#ifdef F_34
if ( F_96 ( * V_167 ) & ( V_181 | V_12 ) )
goto V_193;
#endif
if ( F_92 ( F_93 ( V_142 ) , F_90 ( F_91 () ) ) )
V_191 |= V_177 ;
#ifdef F_34
if ( V_142 -> V_144 . V_192 == V_58 )
V_84 = F_100 ( V_145 , V_158 , V_30 , V_167 , V_128 ,
V_191 , V_21 ) ;
else
#endif
V_84 = F_101 ( V_145 , V_158 , V_30 , V_167 , V_128 , V_191 ,
V_21 , F_78 ( V_142 , V_145 ) ) ;
if ( V_84 == - 1 )
F_79 ( V_145 , V_158 , V_30 , V_128 , V_21 ,
V_142 -> V_144 . V_192 ,
V_142 -> V_144 . V_192 ,
F_96 ( * V_167 ) ) ;
V_193:
F_110 ( V_131 ) ;
}
void F_111 ( unsigned long V_31 , T_8 V_127 , int V_20 , int V_21 ,
unsigned long V_131 )
{
unsigned long V_28 , V_135 , V_25 , V_194 , V_195 ;
int V_196 = V_131 & V_177 ;
F_85 ( L_48 , V_31 ) ;
F_112 (pte, psize, vpn, index, shift) {
V_28 = F_9 ( V_31 , V_25 , V_21 ) ;
V_194 = F_113 ( V_127 , V_135 ) ;
if ( V_194 & V_197 )
V_28 = ~ V_28 ;
V_195 = ( V_28 & V_35 ) * V_36 ;
V_195 += V_194 & V_198 ;
F_85 ( L_49 , V_135 , V_195 , V_194 ) ;
V_37 . V_199 ( V_195 , V_31 , V_20 , V_20 , V_21 , V_196 ) ;
} F_114 () ;
#ifdef F_115
if ( V_196 && F_31 ( V_200 ) &&
V_143 -> V_201 . V_202 &&
F_116 ( V_143 -> V_201 . V_202 -> V_187 ) ) {
F_117 () ;
F_118 ( V_203 ) ;
}
#endif
}
void F_119 ( unsigned long V_30 , unsigned long V_132 ,
V_179 * V_204 , unsigned int V_20 , int V_21 ,
unsigned long V_131 )
{
int V_205 , V_206 , V_207 ;
unsigned long V_208 ;
unsigned char * V_209 ;
unsigned long V_194 , V_25 , V_31 , V_28 , V_195 ;
int V_196 = V_131 & V_177 ;
V_208 = V_132 & V_210 ;
V_209 = F_120 ( V_204 ) ;
if ( ! V_209 )
return;
if ( V_37 . V_211 ) {
V_37 . V_211 ( V_30 , V_208 , V_209 ,
V_20 , V_21 , V_196 ) ;
goto F_118;
}
V_25 = V_27 [ V_20 ] . V_25 ;
V_206 = V_212 >> V_25 ;
for ( V_205 = 0 ; V_205 < V_206 ; V_205 ++ ) {
V_207 = F_121 ( V_209 , V_205 ) ;
if ( ! V_207 )
continue;
V_194 = F_122 ( V_209 , V_205 ) ;
V_132 = V_208 + ( V_205 * ( 1ul << V_25 ) ) ;
V_31 = F_5 ( V_132 , V_30 , V_21 ) ;
V_28 = F_9 ( V_31 , V_25 , V_21 ) ;
if ( V_194 & V_197 )
V_28 = ~ V_28 ;
V_195 = ( V_28 & V_35 ) * V_36 ;
V_195 += V_194 & V_198 ;
V_37 . V_199 ( V_195 , V_31 , V_20 ,
V_60 , V_21 , V_196 ) ;
}
F_118:
#ifdef F_115
if ( V_196 && F_31 ( V_200 ) &&
V_143 -> V_201 . V_202 &&
F_116 ( V_143 -> V_201 . V_202 -> V_187 ) ) {
F_117 () ;
F_118 ( V_203 ) ;
}
#endif
return;
}
void F_123 ( unsigned long V_213 , int V_196 )
{
if ( V_37 . F_123 )
V_37 . F_123 ( V_213 , V_196 ) ;
else {
int V_205 ;
struct V_214 * V_215 =
F_124 ( & V_214 ) ;
for ( V_205 = 0 ; V_205 < V_213 ; V_205 ++ )
F_111 ( V_215 -> V_31 [ V_205 ] , V_215 -> V_127 [ V_205 ] ,
V_215 -> V_20 , V_215 -> V_21 , V_196 ) ;
}
}
void F_125 ( struct V_216 * V_202 , unsigned long V_217 , int V_84 )
{
enum V_164 V_165 = F_84 () ;
if ( F_126 ( V_202 ) ) {
#ifdef F_127
if ( V_84 == - 2 )
F_128 ( V_218 , V_202 , V_219 , V_217 ) ;
else
#endif
F_128 ( V_220 , V_202 , V_221 , V_217 ) ;
} else
F_129 ( V_202 , V_217 , V_220 ) ;
F_102 ( V_165 ) ;
}
long F_130 ( unsigned long V_28 , unsigned long V_31 ,
unsigned long V_222 , unsigned long V_2 ,
unsigned long V_223 , int V_20 , int V_21 )
{
unsigned long V_224 ;
long V_195 ;
V_225:
V_224 = ( ( V_28 & V_35 ) *
V_36 ) & ~ 0x7UL ;
V_195 = V_37 . V_38 ( V_224 , V_31 , V_222 , V_2 , V_223 ,
V_20 , V_20 , V_21 ) ;
if ( F_107 ( V_195 == - 1 ) ) {
V_224 = ( ( ~ V_28 & V_35 ) *
V_36 ) & ~ 0x7UL ;
V_195 = V_37 . V_38 ( V_224 , V_31 , V_222 , V_2 ,
V_223 | V_226 ,
V_20 , V_20 , V_21 ) ;
if ( V_195 == - 1 ) {
if ( F_131 () & 0x1 )
V_224 = ( ( V_28 & V_35 ) *
V_36 ) & ~ 0x7UL ;
V_37 . V_227 ( V_224 ) ;
goto V_225;
}
}
return V_195 ;
}
static void F_132 ( unsigned long V_22 , unsigned long V_228 )
{
unsigned long V_28 ;
unsigned long V_30 = F_4 ( V_22 , V_104 ) ;
unsigned long V_31 = F_5 ( V_22 , V_30 , V_104 ) ;
unsigned long V_229 = F_1 ( F_45 ( V_103 ) ) ;
long V_26 ;
V_28 = F_9 ( V_31 , V_40 , V_104 ) ;
if ( ! V_30 )
return;
V_26 = F_130 ( V_28 , V_31 , F_44 ( V_22 ) , V_229 ,
V_39 ,
V_88 , V_104 ) ;
F_10 ( V_26 < 0 ) ;
F_133 ( & V_230 ) ;
F_10 ( V_42 [ V_228 ] & 0x80 ) ;
V_42 [ V_228 ] = V_26 | 0x80 ;
F_134 ( & V_230 ) ;
}
static void F_135 ( unsigned long V_22 , unsigned long V_228 )
{
unsigned long V_28 , V_194 , V_195 ;
unsigned long V_30 = F_4 ( V_22 , V_104 ) ;
unsigned long V_31 = F_5 ( V_22 , V_30 , V_104 ) ;
V_28 = F_9 ( V_31 , V_40 , V_104 ) ;
F_133 ( & V_230 ) ;
F_10 ( ! ( V_42 [ V_228 ] & 0x80 ) ) ;
V_194 = V_42 [ V_228 ] & 0x7f ;
V_42 [ V_228 ] = 0 ;
F_134 ( & V_230 ) ;
if ( V_194 & V_197 )
V_28 = ~ V_28 ;
V_195 = ( V_28 & V_35 ) * V_36 ;
V_195 += V_194 & V_198 ;
V_37 . V_199 ( V_195 , V_31 , V_88 , V_88 ,
V_104 , 0 ) ;
}
void F_136 ( struct V_129 * V_129 , int V_231 , int V_232 )
{
unsigned long V_131 , V_22 , V_228 ;
int V_205 ;
F_108 ( V_131 ) ;
for ( V_205 = 0 ; V_205 < V_231 ; V_205 ++ , V_129 ++ ) {
V_22 = ( unsigned long ) F_137 ( V_129 ) ;
V_228 = F_44 ( V_22 ) >> V_40 ;
if ( V_228 >= V_41 )
continue;
if ( V_232 )
F_132 ( V_22 , V_228 ) ;
else
F_135 ( V_22 , V_228 ) ;
}
F_110 ( V_131 ) ;
}
void F_138 ( T_9 V_233 ,
T_9 V_234 )
{
F_10 ( V_233 != 0 ) ;
V_120 = F_139 ( T_5 , V_234 , 0x40000000 ) ;
F_56 ( V_120 ) ;
}
