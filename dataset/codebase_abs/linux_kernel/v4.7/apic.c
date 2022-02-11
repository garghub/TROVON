static inline void F_1 ( void )
{
F_2 ( 0x70 , 0x22 ) ;
F_2 ( 0x01 , 0x23 ) ;
}
static inline void F_3 ( void )
{
F_2 ( 0x70 , 0x22 ) ;
F_2 ( 0x00 , 0x23 ) ;
}
static int T_1 F_4 ( char * V_1 )
{
if ( F_5 ( V_2 ) && ! V_1 )
V_3 = 1 ;
else if ( V_1 && ! strncmp ( V_1 , L_1 , 13 ) )
F_6 ( V_4 ) ;
return 0 ;
}
static T_1 int F_7 ( char * V_5 )
{
V_6 = 1 ;
F_8 ( NULL ) ;
return 0 ;
}
static inline int F_9 ( void )
{
return F_10 ( F_11 ( V_7 ) ) ;
}
static inline int F_12 ( void )
{
#ifdef F_13
return 1 ;
#else
return F_14 ( F_9 () ) ;
#endif
}
static int F_15 ( void )
{
if ( V_8 . V_9 == V_10 &&
V_8 . V_11 >= 0xf )
return 1 ;
return F_9 () >= 0x14 ;
}
static void T_1 F_16 ( void )
{
F_17 ( L_2 ) ;
V_12 = & V_13 ;
}
void F_18 ( void )
{
while ( F_11 ( V_14 ) & V_15 )
F_19 () ;
}
T_2 F_20 ( void )
{
T_2 V_16 ;
int V_17 ;
V_17 = 0 ;
do {
V_16 = F_11 ( V_14 ) & V_15 ;
if ( ! V_16 )
break;
F_21 ( V_18 ) ;
F_22 ( 100 ) ;
} while ( V_17 ++ < 1000 );
return V_16 ;
}
void F_23 ( T_2 V_19 , T_2 V_20 )
{
unsigned long V_21 ;
F_24 ( V_21 ) ;
F_25 ( V_22 , F_26 ( V_20 ) ) ;
F_25 ( V_14 , V_19 ) ;
F_27 ( V_21 ) ;
}
T_3 F_28 ( void )
{
T_2 V_23 , V_24 ;
V_24 = F_11 ( V_22 ) ;
V_23 = F_11 ( V_14 ) ;
return V_23 | ( ( T_3 ) V_24 << 32 ) ;
}
int F_29 ( void )
{
return F_15 () ? 0xff : 0xf ;
}
int F_30 ( void )
{
unsigned int V_25 ;
V_25 = F_11 ( V_7 ) ;
return F_14 ( F_10 ( V_25 ) ) ? F_31 ( V_25 ) : 2 ;
}
static void F_32 ( unsigned int V_26 , int V_27 , int V_28 )
{
unsigned int V_29 , V_30 ;
V_29 = V_31 ;
if ( ! V_27 )
V_29 |= V_32 ;
else if ( F_33 ( V_4 ) )
V_29 |= V_33 ;
if ( ! F_12 () )
V_29 |= F_34 ( V_34 ) ;
if ( ! V_28 )
V_29 |= V_35 ;
F_25 ( V_36 , V_29 ) ;
if ( V_29 & V_33 ) {
asm volatile("mfence" : : : "memory");
F_35 ( V_37 L_3 ) ;
return;
}
V_30 = F_11 ( V_38 ) ;
F_25 ( V_38 ,
( V_30 & ~ ( V_39 | V_40 ) ) |
V_41 ) ;
if ( ! V_27 )
F_25 ( V_42 , V_26 / V_43 ) ;
}
static inline int F_36 ( unsigned int V_44 , unsigned int V_45 )
{
return ( V_44 & V_46 )
|| ( V_45 == V_46 )
|| ( ( V_45 & ~ V_46 ) == V_44 ) ;
}
static unsigned int F_37 ( int V_47 , unsigned int V_45 )
{
unsigned int V_48 , V_49 ;
if ( V_47 >= V_50 )
return ~ 0 ;
V_48 = F_38 ( & V_51 [ V_47 ] ) ;
do {
V_49 = V_48 & ~ V_46 ;
if ( V_49 && ! F_36 ( V_49 , V_45 ) )
return V_48 ;
V_48 = F_39 ( & V_51 [ V_47 ] , V_48 , V_45 ) ;
} while ( V_48 != V_45 );
V_48 &= ~ V_46 ;
if ( V_48 && V_48 != V_49 )
F_17 ( L_4 ,
V_47 , V_48 ) ;
return V_45 ;
}
int F_40 ( T_4 V_47 , T_4 V_49 , T_4 V_52 , T_4 V_53 )
{
unsigned long V_54 = F_41 ( V_47 ) ;
unsigned int V_45 , V_44 , V_55 ;
V_45 = ( V_53 << 16 ) | ( V_52 << 8 ) | V_49 ;
V_44 = F_11 ( V_54 ) ;
V_55 = F_37 ( V_47 , V_45 ) ;
if ( V_55 != V_45 ) {
F_42 ( V_56 L_5
L_6
L_7 ,
F_43 () , V_54 , V_47 , V_45 , V_55 ) ;
return - V_57 ;
}
if ( ! F_36 ( V_44 , V_45 ) ) {
F_42 ( V_56 L_5
L_6
L_8 ,
F_43 () , V_54 , V_47 , V_45 , V_44 ) ;
return - V_58 ;
}
F_25 ( V_54 , V_45 ) ;
return 0 ;
}
static int F_44 ( unsigned long V_59 ,
struct V_60 * V_61 )
{
F_25 ( V_42 , V_59 ) ;
return 0 ;
}
static int F_45 ( unsigned long V_59 ,
struct V_60 * V_61 )
{
T_3 V_62 ;
V_62 = F_46 () ;
F_47 ( V_63 , V_62 + ( ( ( T_3 ) V_59 ) * V_64 ) ) ;
return 0 ;
}
static int F_48 ( struct V_60 * V_61 )
{
unsigned int V_25 ;
if ( V_61 -> V_65 & V_66 )
return 0 ;
V_25 = F_11 ( V_36 ) ;
V_25 |= ( V_35 | V_31 ) ;
F_25 ( V_36 , V_25 ) ;
F_25 ( V_42 , 0 ) ;
return 0 ;
}
static inline int
F_49 ( struct V_60 * V_61 , bool V_27 )
{
if ( V_61 -> V_65 & V_66 )
return 0 ;
F_32 ( V_67 , V_27 , 1 ) ;
return 0 ;
}
static int F_50 ( struct V_60 * V_61 )
{
return F_49 ( V_61 , false ) ;
}
static int F_51 ( struct V_60 * V_61 )
{
return F_49 ( V_61 , true ) ;
}
static void F_52 ( const struct V_68 * V_53 )
{
#ifdef F_53
V_12 -> V_69 ( V_53 , V_31 ) ;
#endif
}
static void F_54 ( void )
{
struct V_60 * V_70 = F_55 ( & V_71 ) ;
if ( F_56 ( V_72 ) ) {
V_73 . V_65 &= ~ V_74 ;
V_73 . V_75 = 150 ;
}
memcpy ( V_70 , & V_73 , sizeof( * V_70 ) ) ;
V_70 -> V_68 = F_57 ( F_43 () ) ;
if ( F_56 ( V_4 ) ) {
V_70 -> V_65 &= ~ ( V_76 |
V_66 ) ;
V_70 -> V_77 = F_45 ;
F_58 ( V_70 ,
( V_78 / V_64 ) * 1000 ,
0xF , ~ 0UL ) ;
} else
F_59 ( V_70 ) ;
}
static void T_1 F_60 ( struct V_60 * V_79 )
{
unsigned long long V_62 = 0 ;
long V_80 = F_11 ( V_81 ) ;
unsigned long V_82 = F_61 () ;
if ( F_33 ( V_83 ) )
V_62 = F_46 () ;
switch ( V_84 ++ ) {
case 0 :
V_85 = V_80 ;
V_86 = V_62 ;
V_87 = V_82 ;
V_88 = V_89 ;
break;
case V_90 :
V_91 = V_80 ;
V_92 = V_62 ;
if ( V_82 < V_87 )
V_82 += V_93 ;
V_94 = V_82 ;
V_95 = V_89 ;
break;
}
}
static int T_1
F_62 ( long V_96 , long * V_59 , long * V_97 )
{
const long V_98 = V_99 / 10 ;
const long V_100 = V_98 / 100 ;
unsigned long V_101 ;
T_3 V_102 ;
#ifndef F_63
return - 1 ;
#endif
F_64 ( V_103 , L_9 , V_96 ) ;
if ( ! V_96 )
return - 1 ;
V_101 = F_65 ( V_99 , 22 ) ;
if ( V_96 > ( V_98 - V_100 ) &&
V_96 < ( V_98 + V_100 ) ) {
F_64 ( V_103 , L_10 ) ;
return 0 ;
}
V_102 = ( ( ( T_3 ) V_96 ) * V_101 ) >> 22 ;
F_66 ( V_102 , 1000000 ) ;
F_67 ( L_11
L_12 , ( long ) V_102 ) ;
V_102 = ( ( ( T_3 ) ( * V_59 ) ) * V_98 ) ;
F_66 ( V_102 , V_96 ) ;
F_17 ( L_13
L_14 , ( unsigned long ) V_102 , * V_59 ) ;
* V_59 = ( long ) V_102 ;
if ( F_33 ( V_83 ) ) {
V_102 = ( ( ( T_3 ) ( * V_97 ) ) * V_98 ) ;
F_66 ( V_102 , V_96 ) ;
F_64 ( V_103 , L_15
L_16 ,
( unsigned long ) V_102 , * V_97 ) ;
* V_97 = ( long ) V_102 ;
}
return 0 ;
}
static int T_1 F_68 ( void )
{
struct V_60 * V_70 = F_55 ( & V_71 ) ;
void (* F_69)( struct V_60 * V_79 );
unsigned long V_104 ;
long V_59 , V_97 ;
int V_105 = 0 ;
if ( F_33 ( V_4 ) ) {
return 0 ;
} else if ( V_67 ) {
F_64 ( V_103 , L_17 ,
V_67 ) ;
V_73 . V_101 = F_70 ( V_67 / V_43 ,
V_106 , V_73 . V_107 ) ;
V_73 . V_108 =
F_71 ( 0x7FFFFF , & V_73 ) ;
V_73 . V_109 =
F_71 ( 0xF , & V_73 ) ;
V_73 . V_65 &= ~ V_66 ;
return 0 ;
}
F_64 ( V_103 , L_18
L_19 ) ;
F_72 () ;
F_69 = V_110 -> V_111 ;
V_110 -> V_111 = F_60 ;
F_32 ( 0xffffffff , 0 , 0 ) ;
F_73 () ;
while ( V_84 <= V_90 )
F_19 () ;
F_72 () ;
V_110 -> V_111 = F_69 ;
V_59 = V_85 - V_91 ;
F_64 ( V_103 , L_20 , V_59 ) ;
V_97 = ( long ) ( V_92 - V_86 ) ;
V_105 = ! F_62 ( V_94 - V_87 ,
& V_59 , & V_97 ) ;
V_73 . V_101 = F_70 ( V_59 , V_106 * V_90 ,
V_73 . V_107 ) ;
V_73 . V_108 =
F_71 ( 0x7FFFFFFF , & V_73 ) ;
V_73 . V_109 =
F_71 ( 0xF , & V_73 ) ;
V_67 = ( V_59 * V_43 ) / V_90 ;
F_64 ( V_103 , L_21 , V_59 ) ;
F_64 ( V_103 , L_22 , V_73 . V_101 ) ;
F_64 ( V_103 , L_23 ,
V_67 ) ;
if ( F_33 ( V_83 ) ) {
F_64 ( V_103 , L_24
L_25 ,
( V_97 / V_90 ) / ( 1000000 / V_112 ) ,
( V_97 / V_90 ) % ( 1000000 / V_112 ) ) ;
}
F_64 ( V_103 , L_26
L_27 ,
V_67 / ( 1000000 / V_112 ) ,
V_67 % ( 1000000 / V_112 ) ) ;
if ( V_67 < ( 1000000 / V_112 ) ) {
F_73 () ;
F_67 ( L_28 ) ;
return - 1 ;
}
V_70 -> V_65 &= ~ V_66 ;
if ( ! V_105 ) {
F_64 ( V_103 , L_29 ) ;
V_70 -> V_111 = F_60 ;
F_50 ( V_70 ) ;
V_84 = - 1 ;
F_73 () ;
while ( V_84 <= V_90 )
F_19 () ;
F_72 () ;
F_48 ( V_70 ) ;
V_104 = V_95 - V_88 ;
F_64 ( V_103 , L_30 , V_104 ) ;
if ( V_104 >= V_90 - 2 && V_104 <= V_90 + 2 )
F_64 ( V_103 , L_31 ) ;
else
V_70 -> V_65 |= V_66 ;
}
F_73 () ;
if ( V_70 -> V_65 & V_66 ) {
F_67 ( L_32 ) ;
return - 1 ;
}
return 0 ;
}
void T_1 F_74 ( void )
{
if ( V_113 ) {
F_17 ( L_33 ) ;
if ( F_75 () > 1 ) {
V_73 . V_101 = 1 ;
F_54 () ;
}
return;
}
if ( F_68 () ) {
if ( F_75 () > 1 )
F_54 () ;
return;
}
V_73 . V_65 &= ~ V_66 ;
F_54 () ;
}
void F_76 ( void )
{
F_54 () ;
}
static void F_77 ( void )
{
int V_114 = F_43 () ;
struct V_60 * V_61 = & F_78 ( V_71 , V_114 ) ;
if ( ! V_61 -> V_111 ) {
F_67 ( L_34 , V_114 ) ;
F_48 ( V_61 ) ;
return;
}
F_21 ( V_115 ) ;
V_61 -> V_111 ( V_61 ) ;
}
T_5 void T_6 F_79 ( struct V_116 * V_117 )
{
struct V_116 * V_118 = F_80 ( V_117 ) ;
F_81 () ;
F_77 () ;
F_82 () ;
F_80 ( V_118 ) ;
}
T_5 void T_6 F_83 ( struct V_116 * V_117 )
{
struct V_116 * V_118 = F_80 ( V_117 ) ;
F_81 () ;
F_84 ( V_31 ) ;
F_77 () ;
F_85 ( V_31 ) ;
F_82 () ;
F_80 ( V_118 ) ;
}
int F_86 ( unsigned int V_119 )
{
return - V_57 ;
}
void F_87 ( void )
{
int V_120 ;
T_2 V_25 ;
if ( ! V_121 && ! V_122 )
return;
V_120 = F_30 () ;
if ( V_120 >= 3 ) {
V_25 = V_123 ;
F_25 ( V_124 , V_25 | V_35 ) ;
}
V_25 = F_11 ( V_36 ) ;
F_25 ( V_36 , V_25 | V_35 ) ;
V_25 = F_11 ( V_125 ) ;
F_25 ( V_125 , V_25 | V_35 ) ;
V_25 = F_11 ( V_126 ) ;
F_25 ( V_126 , V_25 | V_35 ) ;
if ( V_120 >= 4 ) {
V_25 = F_11 ( V_127 ) ;
F_25 ( V_127 , V_25 | V_35 ) ;
}
#ifdef F_88
if ( V_120 >= 5 ) {
V_25 = F_11 ( V_128 ) ;
F_25 ( V_128 , V_25 | V_35 ) ;
}
#endif
#ifdef F_89
if ( V_120 >= 6 ) {
V_25 = F_11 ( V_129 ) ;
if ( ! ( V_25 & V_35 ) )
F_25 ( V_129 , V_25 | V_35 ) ;
}
#endif
F_25 ( V_36 , V_35 ) ;
F_25 ( V_125 , V_35 ) ;
F_25 ( V_126 , V_35 ) ;
if ( V_120 >= 3 )
F_25 ( V_124 , V_35 ) ;
if ( V_120 >= 4 )
F_25 ( V_127 , V_35 ) ;
if ( F_12 () ) {
if ( V_120 > 3 )
F_25 ( V_130 , 0 ) ;
F_11 ( V_130 ) ;
}
}
void F_90 ( void )
{
unsigned int V_131 ;
if ( ! V_121 && ! V_122 )
return;
F_87 () ;
V_131 = F_11 ( V_132 ) ;
V_131 &= ~ V_133 ;
F_25 ( V_132 , V_131 ) ;
#ifdef V_2
if ( V_134 ) {
unsigned int V_135 , V_136 ;
F_91 ( V_137 , V_135 , V_136 ) ;
V_135 &= ~ V_138 ;
F_92 ( V_137 , V_135 , V_136 ) ;
}
#endif
}
void F_93 ( void )
{
unsigned long V_21 ;
if ( ! F_33 ( V_139 ) && ! F_94 () )
return;
F_24 ( V_21 ) ;
#ifdef V_2
if ( ! V_134 )
F_87 () ;
else
#endif
F_90 () ;
F_27 ( V_21 ) ;
}
void T_1 F_95 ( void )
{
if ( F_15 () || V_8 . V_9 == V_10 )
return;
F_96 () ;
F_64 ( V_140 , L_35 ) ;
F_25 ( V_14 , V_141 |
V_142 | V_143 ) ;
}
void T_1 F_97 ( void )
{
unsigned int V_131 ;
if ( V_144 || ! F_33 ( V_139 ) )
return;
F_87 () ;
V_131 = F_11 ( V_132 ) ;
V_131 &= ~ V_145 ;
V_131 |= V_133 ;
#ifdef V_2
if ( ( V_8 . V_9 == V_146 ) &&
( V_8 . V_11 == 15 ) )
V_131 &= ~ V_147 ;
else
#endif
V_131 |= V_147 ;
V_131 |= V_148 ;
F_25 ( V_132 , V_131 ) ;
F_25 ( V_125 , V_149 ) ;
V_131 = V_150 ;
if ( ! F_12 () )
V_131 |= V_151 ;
if ( V_152 == V_153 )
V_131 |= V_35 ;
F_25 ( V_126 , V_131 ) ;
}
static void F_98 ( void )
{
unsigned int V_154 , V_131 , V_120 ;
if ( ! F_12 () ) {
F_17 ( L_36 ) ;
return;
}
if ( V_12 -> V_155 ) {
F_17 ( L_37 ) ;
return;
}
V_120 = F_30 () ;
if ( V_120 > 3 )
F_25 ( V_130 , 0 ) ;
V_154 = F_11 ( V_130 ) ;
V_131 = V_123 ;
F_25 ( V_124 , V_131 ) ;
if ( V_120 > 3 )
F_25 ( V_130 , 0 ) ;
V_131 = F_11 ( V_130 ) ;
if ( V_131 != V_154 )
F_64 ( V_103 , L_38
L_39 ,
V_154 , V_131 ) ;
}
void F_99 ( void )
{
int V_114 = F_43 () ;
unsigned int V_131 , V_156 ;
int V_157 , V_158 , V_159 = 0 ;
unsigned long long V_62 = 0 , V_160 ;
long long V_161 = V_162 ? V_162 : 1000000 ;
if ( F_33 ( V_83 ) )
V_62 = F_46 () ;
if ( V_163 ) {
F_100 () ;
return;
}
#ifdef V_2
if ( F_12 () && V_12 -> V_155 ) {
F_25 ( V_130 , 0 ) ;
F_25 ( V_130 , 0 ) ;
F_25 ( V_130 , 0 ) ;
F_25 ( V_130 , 0 ) ;
}
#endif
F_101 () ;
F_102 ( ! V_12 -> V_164 () ) ;
V_12 -> V_165 () ;
#ifdef V_2
V_157 = F_103 ( V_166 , V_114 ) ;
F_104 ( V_157 != V_167 && V_157 != F_105 () ) ;
F_103 ( V_166 , V_114 ) =
F_105 () ;
#endif
V_131 = F_11 ( V_168 ) ;
V_131 &= ~ V_169 ;
F_25 ( V_168 , V_131 ) ;
do {
V_156 = 0 ;
for ( V_157 = V_170 - 1 ; V_157 >= 0 ; V_157 -- )
V_156 |= F_11 ( V_171 + V_157 * 0x10 ) ;
for ( V_157 = V_170 - 1 ; V_157 >= 0 ; V_157 -- ) {
V_131 = F_11 ( V_172 + V_157 * 0x10 ) ;
for ( V_158 = 31 ; V_158 >= 0 ; V_158 -- ) {
if ( V_131 & ( 1 << V_158 ) ) {
F_106 () ;
V_159 ++ ;
}
}
}
if ( V_159 > 256 ) {
F_107 ( V_173 L_40 ,
V_159 ) ;
break;
}
if ( V_156 ) {
if ( F_33 ( V_83 ) && V_162 ) {
V_160 = F_46 () ;
V_161 = ( V_162 << 10 ) - ( V_160 - V_62 ) ;
} else
V_161 -- ;
}
} while ( V_156 && V_161 > 0 );
F_104 ( V_161 <= 0 ) ;
V_131 = F_11 ( V_132 ) ;
V_131 &= ~ V_145 ;
V_131 |= V_133 ;
#ifdef V_2
V_131 &= ~ V_147 ;
#endif
V_131 |= V_148 ;
F_25 ( V_132 , V_131 ) ;
V_131 = F_11 ( V_125 ) & V_35 ;
if ( ! V_114 && ( V_174 || ! V_131 ) ) {
V_131 = V_149 ;
F_64 ( V_103 , L_41 , V_114 ) ;
} else {
V_131 = V_149 | V_35 ;
F_64 ( V_103 , L_42 , V_114 ) ;
}
F_25 ( V_125 , V_131 ) ;
if ( ( ! V_114 && V_152 != V_153 ) ||
V_152 == V_175 )
V_131 = V_150 ;
else
V_131 = V_150 | V_35 ;
if ( ! F_12 () )
V_131 |= V_151 ;
F_25 ( V_126 , V_131 ) ;
#ifdef F_89
if ( ! V_114 )
F_108 () ;
#endif
}
static void F_109 ( void )
{
F_98 () ;
#ifdef V_2
{
unsigned int V_131 ;
V_131 = F_11 ( V_36 ) ;
V_131 |= ( V_35 | V_31 ) ;
F_25 ( V_36 , V_131 ) ;
}
#endif
F_110 () ;
}
void F_111 ( void )
{
F_99 () ;
F_109 () ;
}
static void F_112 ( void )
{
T_3 V_176 ;
if ( ! F_33 ( V_139 ) )
return;
F_113 ( V_137 , V_176 ) ;
if ( ! ( V_176 & V_177 ) )
return;
F_47 ( V_137 , V_176 & ~ ( V_177 | V_178 ) ) ;
F_47 ( V_137 , V_176 & ~ V_177 ) ;
F_35 ( V_179 L_43 ) ;
}
static void F_114 ( void )
{
T_3 V_176 ;
F_113 ( V_137 , V_176 ) ;
if ( V_176 & V_177 )
return;
F_47 ( V_137 , V_176 | V_177 ) ;
F_35 ( V_179 L_44 ) ;
}
static int T_1 F_115 ( char * V_180 )
{
if ( F_116 () ) {
int V_181 = F_117 ( V_182 ) ;
if ( V_181 >= 255 ) {
F_67 ( L_45 ,
V_181 ) ;
return 0 ;
}
F_67 ( L_46 ) ;
F_112 () ;
}
F_6 ( V_183 ) ;
V_184 = V_185 ;
V_121 = 0 ;
return 0 ;
}
void F_118 ( void )
{
if ( V_184 != V_186 ) {
F_112 () ;
return;
}
F_114 () ;
}
static T_1 void F_119 ( void )
{
T_2 V_187 , V_188 = V_184 ;
V_121 = 0 ;
V_184 = V_185 ;
if ( V_188 != V_186 )
return;
V_187 = F_120 () ;
if ( V_187 >= 255 )
F_121 ( L_47 , V_187 ) ;
F_112 () ;
F_122 ( V_189 ) ;
}
static T_1 void F_123 ( void )
{
if ( V_184 != V_190 )
return;
V_121 = 1 ;
V_184 = V_186 ;
F_114 () ;
}
static T_1 void F_124 ( int V_191 )
{
if ( V_184 == V_185 )
return;
if ( V_191 != V_192 ) {
if ( V_193 > 255 ||
! F_125 () ) {
F_17 ( L_48 ) ;
F_119 () ;
return;
}
V_194 = 1 ;
}
F_123 () ;
}
void T_1 F_126 ( void )
{
if ( F_116 () ) {
F_17 ( L_49 ) ;
V_121 = 1 ;
V_184 = V_186 ;
} else if ( ! F_33 ( V_183 ) ) {
V_184 = V_185 ;
}
}
static int T_1 F_127 ( void )
{
if ( ! F_128 () )
return 0 ;
F_121 ( L_50 ) ;
}
static inline void F_124 ( int V_191 ) { }
static inline void F_114 ( void ) { }
static int T_1 F_129 ( void )
{
#ifdef F_130
if ( ! F_116 () && V_195 ) {
F_17 ( L_51 ) ;
return - 1 ;
}
#endif
return F_131 () ;
}
void T_1 F_132 ( void )
{
unsigned long V_21 ;
int V_196 , V_197 ;
V_197 = F_133 () ;
if ( V_197 < 0 && ! F_134 () )
return;
V_196 = F_135 () ;
if ( V_196 ) {
F_17 ( L_52 , V_196 ) ;
return;
}
F_24 ( V_21 ) ;
V_198 -> V_199 () ;
F_136 () ;
if ( V_197 >= 0 )
V_197 = F_129 () ;
F_124 ( V_197 ) ;
if ( V_197 < 0 )
F_137 () ;
V_198 -> V_200 () ;
F_27 ( V_21 ) ;
}
static int T_1 F_138 ( void )
{
if ( ! F_33 ( V_139 ) ) {
F_17 ( L_53 ) ;
return - 1 ;
}
V_189 = V_201 ;
return 0 ;
}
static int T_1 F_139 ( void )
{
T_2 V_65 , V_136 , V_135 ;
V_65 = F_140 ( 1 ) ;
if ( ! ( V_65 & ( 1 << V_139 ) ) ) {
F_67 ( L_54 ) ;
return - 1 ;
}
F_141 ( & V_8 , V_139 ) ;
V_189 = V_201 ;
if ( V_8 . V_11 >= 6 ) {
F_91 ( V_137 , V_135 , V_136 ) ;
if ( V_135 & V_138 )
V_189 = V_135 & V_202 ;
}
F_17 ( L_55 ) ;
return 0 ;
}
int T_1 F_142 ( unsigned long V_203 )
{
T_2 V_136 , V_135 ;
if ( V_163 )
return - 1 ;
if ( V_8 . V_11 >= 6 ) {
F_91 ( V_137 , V_135 , V_136 ) ;
if ( ! ( V_135 & V_138 ) ) {
F_17 ( L_56 ) ;
V_135 &= ~ V_202 ;
V_135 |= V_138 | V_203 ;
F_92 ( V_137 , V_135 , V_136 ) ;
V_134 = 1 ;
}
}
return F_139 () ;
}
static int T_1 F_138 ( void )
{
if ( V_163 )
return - 1 ;
switch ( V_8 . V_9 ) {
case V_10 :
if ( ( V_8 . V_11 == 6 && V_8 . V_204 > 1 ) ||
( V_8 . V_11 >= 15 ) )
break;
goto V_205;
case V_146 :
if ( V_8 . V_11 == 6 || V_8 . V_11 == 15 ||
( V_8 . V_11 == 5 && F_33 ( V_139 ) ) )
break;
goto V_205;
default:
goto V_205;
}
if ( ! F_33 ( V_139 ) ) {
if ( ! V_3 ) {
F_17 ( L_57
L_58 ) ;
return - 1 ;
}
if ( F_142 ( V_201 ) )
return - 1 ;
} else {
if ( F_139 () )
return - 1 ;
}
F_110 () ;
return 0 ;
V_205:
F_17 ( L_59 ) ;
return - 1 ;
}
void T_1 F_143 ( void )
{
unsigned int V_206 ;
if ( V_121 ) {
V_207 = F_120 () ;
return;
}
if ( ! V_144 && F_138 () ) {
F_17 ( L_60 ) ;
F_16 () ;
} else {
V_122 = V_189 ;
if ( ! V_208 && ! V_144 )
F_122 ( V_122 ) ;
}
V_206 = F_120 () ;
if ( V_207 != V_206 ) {
V_207 = V_206 ;
V_209 [ V_206 ] =
F_10 ( F_11 ( V_7 ) ) ;
}
}
void T_1 F_122 ( unsigned long V_210 )
{
V_189 = V_210 ;
if ( ! V_121 ) {
F_144 ( V_211 , V_210 ) ;
F_64 ( V_103 , L_61 ,
V_212 , V_189 ) ;
}
if ( V_207 == - 1U ) {
V_207 = F_120 () ;
V_209 [ V_207 ] =
F_10 ( F_11 ( V_7 ) ) ;
}
}
static void F_145 ( T_4 V_49 )
{
T_2 V_25 ;
V_25 = F_11 ( V_172 + ( ( V_49 & ~ 0x1f ) >> 1 ) ) ;
if ( V_25 & ( 1 << ( V_49 & 0x1f ) ) )
F_106 () ;
F_21 ( V_213 ) ;
F_17 ( L_62
L_63 , V_49 , F_43 () ) ;
}
T_5 void F_146 ( struct V_116 * V_117 )
{
F_147 () ;
F_145 ( ~ V_117 -> V_214 ) ;
F_82 () ;
}
T_5 void F_148 ( struct V_116 * V_117 )
{
T_4 V_49 = ~ V_117 -> V_214 ;
F_147 () ;
F_149 ( V_49 ) ;
F_145 ( V_49 ) ;
F_150 ( V_49 ) ;
F_82 () ;
}
static void F_151 ( struct V_116 * V_117 )
{
T_2 V_25 ;
T_2 V_157 = 0 ;
static const char * const V_215 [] = {
L_64 ,
L_65 ,
L_66 ,
L_67 ,
L_68 ,
L_69 ,
L_70 ,
L_71 ,
} ;
if ( F_30 () > 3 )
F_25 ( V_130 , 0 ) ;
V_25 = F_11 ( V_130 ) ;
F_106 () ;
F_152 ( & V_216 ) ;
F_64 ( V_140 , V_37 L_72 ,
F_43 () , V_25 ) ;
V_25 &= 0xff ;
while ( V_25 ) {
if ( V_25 & 0x1 )
F_64 ( V_140 , V_217 L_73 , V_215 [ V_157 ] ) ;
V_157 ++ ;
V_25 >>= 1 ;
}
F_64 ( V_140 , V_217 L_74 ) ;
}
T_5 void F_153 ( struct V_116 * V_117 )
{
F_147 () ;
F_151 ( V_117 ) ;
F_82 () ;
}
T_5 void F_154 ( struct V_116 * V_117 )
{
F_147 () ;
F_155 ( V_123 ) ;
F_151 ( V_117 ) ;
F_156 ( V_123 ) ;
F_82 () ;
}
static void T_1 F_157 ( void )
{
#ifdef V_2
if ( V_174 ) {
F_87 () ;
F_64 ( V_103 , L_75
L_76 ) ;
F_1 () ;
}
#endif
}
void F_158 ( int V_218 )
{
unsigned int V_131 ;
#ifdef V_2
if ( V_174 ) {
F_64 ( V_103 , L_77
L_78 ) ;
F_3 () ;
return;
}
#endif
V_131 = F_11 ( V_132 ) ;
V_131 &= ~ V_145 ;
V_131 |= V_133 ;
V_131 |= 0xf ;
F_25 ( V_132 , V_131 ) ;
if ( ! V_218 ) {
V_131 = F_11 ( V_125 ) ;
V_131 &= ~ ( V_219 | V_220 |
V_221 | V_222 |
V_151 | V_35 ) ;
V_131 |= V_222 | V_220 ;
V_131 = F_159 ( V_131 , V_223 ) ;
F_25 ( V_125 , V_131 ) ;
} else {
F_25 ( V_125 , V_35 ) ;
}
V_131 = F_11 ( V_126 ) ;
V_131 &= ~ ( V_219 | V_220 |
V_221 | V_222 |
V_151 | V_35 ) ;
V_131 |= V_222 | V_220 ;
V_131 = F_159 ( V_131 , V_224 ) ;
F_25 ( V_126 , V_131 ) ;
}
int F_160 ( int V_181 , int V_225 )
{
int V_114 , V_226 = V_227 ;
bool V_228 = F_161 ( V_207 ,
V_229 ) ;
if ( V_230 != V_167 &&
V_230 != F_120 () &&
V_230 == V_181 ) {
int V_231 = V_232 + V_233 ;
F_67 ( L_79
L_80 ,
V_231 , V_181 ) ;
V_233 ++ ;
return - V_234 ;
}
if ( ! V_228 && V_232 >= V_227 - 1 &&
V_181 != V_207 ) {
int V_231 = V_226 + V_233 - 1 ;
F_67 (
L_81
L_82
L_83 , V_226 , V_231 , V_181 ) ;
V_233 ++ ;
return - V_234 ;
}
if ( V_232 >= V_227 ) {
int V_231 = V_226 + V_233 ;
F_67 (
L_84
L_83 , V_226 , V_231 , V_181 ) ;
V_233 ++ ;
return - V_57 ;
}
V_232 ++ ;
if ( V_181 == V_207 ) {
V_114 = 0 ;
} else
V_114 = F_162 ( - 1 , V_235 ) ;
if ( F_163 ( V_181 , V_114 ) < 0 ) {
int V_231 = V_226 + V_233 ;
F_67 ( L_85 ,
V_231 , V_181 ) ;
V_233 ++ ;
return - V_236 ;
}
if ( V_225 == 0x0 ) {
F_67 ( L_86 ,
V_114 , V_181 ) ;
V_225 = 0x10 ;
}
V_209 [ V_181 ] = V_225 ;
if ( V_225 != V_209 [ V_207 ] ) {
F_67 ( L_87 ,
V_209 [ V_207 ] , V_114 , V_225 ) ;
}
F_164 ( V_181 , V_229 ) ;
if ( V_181 > V_193 )
V_193 = V_181 ;
#if F_165 ( F_53 ) || F_165 ( F_13 )
F_103 ( V_237 , V_114 ) = V_181 ;
F_103 ( V_238 , V_114 ) = V_181 ;
#endif
#ifdef V_2
F_103 ( V_166 , V_114 ) =
V_12 -> V_239 ( V_114 ) ;
#endif
F_166 ( V_114 , true ) ;
F_167 ( V_114 , true ) ;
return V_114 ;
}
int F_168 ( void )
{
return F_120 () ;
}
void F_169 ( void )
{
unsigned long V_240 ;
F_25 ( V_241 , V_242 ) ;
V_240 = F_11 ( V_243 ) & ~ V_244 ;
V_240 |= F_170 ( 1UL << F_43 () ) ;
F_25 ( V_243 , V_240 ) ;
}
int F_171 ( const struct V_68 * V_68 ,
const struct V_68 * V_245 ,
unsigned int * V_181 )
{
unsigned int V_114 ;
F_172 (cpu, cpumask, andmask) {
if ( F_173 ( V_114 , V_246 ) )
break;
}
if ( F_174 ( V_114 < V_227 ) ) {
* V_181 = F_78 ( V_237 , V_114 ) ;
return 0 ;
}
return - V_57 ;
}
void T_1 F_175 ( void (* F_176)( T_2 V_54 , T_2 V_25 ) )
{
struct V_12 * * V_247 ;
for ( V_247 = V_248 ; V_247 < V_249 ; V_247 ++ ) {
F_104 ( ( * V_247 ) -> F_176 == F_176 ) ;
( * V_247 ) -> F_176 = F_176 ;
}
}
static void T_1 F_177 ( void )
{
#ifdef F_13
F_25 ( V_182 , F_178 ( V_207 ) ) ;
#else
# ifdef F_179
V_207 = F_120 () ;
# endif
#endif
F_180 ( V_207 , & V_229 ) ;
}
int T_1 F_181 ( bool V_250 )
{
int V_20 ;
F_157 () ;
if ( V_250 )
F_177 () ;
F_99 () ;
if ( V_121 )
V_20 = F_11 ( V_243 ) ;
else
V_20 = F_182 ( F_11 ( V_243 ) ) ;
F_183 () ;
F_109 () ;
F_184 () ;
F_185 () ;
V_251 . V_252 . V_253 () ;
return V_20 ;
}
int T_1 F_186 ( void )
{
if ( V_163 ) {
F_17 ( L_88 ) ;
return - 1 ;
}
#ifdef F_13
if ( ! F_33 ( V_139 ) ) {
V_163 = 1 ;
F_17 ( L_89 ) ;
return - 1 ;
}
#else
if ( ! V_144 && ! F_33 ( V_139 ) )
return - 1 ;
if ( ! F_33 ( V_139 ) &&
F_14 ( V_209 [ V_207 ] ) ) {
F_42 ( L_90 ,
V_207 ) ;
return - 1 ;
}
#endif
if ( ! V_144 )
F_100 () ;
F_187 () ;
F_181 ( true ) ;
return 0 ;
}
void T_1 F_188 ( void )
{
F_186 () ;
}
static int F_189 ( void )
{
unsigned long V_21 ;
int V_120 ;
if ( ! V_254 . V_255 )
return 0 ;
V_120 = F_30 () ;
V_254 . V_256 = F_11 ( V_182 ) ;
V_254 . V_257 = F_11 ( V_168 ) ;
V_254 . V_258 = F_11 ( V_243 ) ;
V_254 . V_259 = F_11 ( V_241 ) ;
V_254 . V_260 = F_11 ( V_132 ) ;
V_254 . V_261 = F_11 ( V_36 ) ;
if ( V_120 >= 4 )
V_254 . V_262 = F_11 ( V_127 ) ;
V_254 . V_263 = F_11 ( V_125 ) ;
V_254 . V_264 = F_11 ( V_126 ) ;
V_254 . V_265 = F_11 ( V_124 ) ;
V_254 . V_266 = F_11 ( V_42 ) ;
V_254 . V_267 = F_11 ( V_38 ) ;
#ifdef F_88
if ( V_120 >= 5 )
V_254 . V_268 = F_11 ( V_128 ) ;
#endif
#ifdef F_89
if ( V_120 >= 6 )
V_254 . V_269 = F_11 ( V_129 ) ;
#endif
F_24 ( V_21 ) ;
F_90 () ;
F_190 () ;
F_27 ( V_21 ) ;
return 0 ;
}
static void F_191 ( void )
{
unsigned int V_135 , V_136 ;
unsigned long V_21 ;
int V_120 ;
if ( ! V_254 . V_255 )
return;
F_24 ( V_21 ) ;
F_136 () ;
V_198 -> V_199 () ;
if ( V_121 ) {
F_114 () ;
} else {
if ( V_8 . V_11 >= 6 ) {
F_91 ( V_137 , V_135 , V_136 ) ;
V_135 &= ~ V_202 ;
V_135 |= V_138 | V_189 ;
F_92 ( V_137 , V_135 , V_136 ) ;
}
}
V_120 = F_30 () ;
F_25 ( V_124 , V_123 | V_35 ) ;
F_25 ( V_182 , V_254 . V_256 ) ;
F_25 ( V_241 , V_254 . V_259 ) ;
F_25 ( V_243 , V_254 . V_258 ) ;
F_25 ( V_168 , V_254 . V_257 ) ;
F_25 ( V_132 , V_254 . V_260 ) ;
F_25 ( V_125 , V_254 . V_263 ) ;
F_25 ( V_126 , V_254 . V_264 ) ;
#ifdef F_88
if ( V_120 >= 5 )
F_25 ( V_128 , V_254 . V_268 ) ;
#endif
#ifdef F_89
if ( V_120 >= 6 )
F_25 ( V_129 , V_254 . V_269 ) ;
#endif
if ( V_120 >= 4 )
F_25 ( V_127 , V_254 . V_262 ) ;
F_25 ( V_36 , V_254 . V_261 ) ;
F_25 ( V_38 , V_254 . V_267 ) ;
F_25 ( V_42 , V_254 . V_266 ) ;
F_25 ( V_130 , 0 ) ;
F_11 ( V_130 ) ;
F_25 ( V_124 , V_254 . V_265 ) ;
F_25 ( V_130 , 0 ) ;
F_11 ( V_130 ) ;
F_192 ( V_121 ) ;
F_27 ( V_21 ) ;
}
static void F_110 ( void )
{
V_254 . V_255 = 1 ;
}
static int T_1 F_193 ( void )
{
if ( F_33 ( V_139 ) )
F_194 ( & V_270 ) ;
return 0 ;
}
static void F_110 ( void ) { }
static int F_195 ( const struct V_271 * V_272 )
{
if ( V_273 )
return 0 ;
F_17 ( L_91 , V_272 -> V_274 ) ;
V_273 = 1 ;
return 0 ;
}
static void F_196 ( void )
{
if ( V_275 )
return;
F_197 ( V_276 ) ;
V_275 = 1 ;
}
int F_198 ( void )
{
F_196 () ;
return V_273 ;
}
static int T_1 F_199 ( char * V_1 )
{
V_163 = 1 ;
F_6 ( V_139 ) ;
return 0 ;
}
static int T_1 F_200 ( char * V_1 )
{
return F_199 ( V_1 ) ;
}
static int T_1 F_201 ( char * V_1 )
{
V_277 = 1 ;
return 0 ;
}
static int T_1 F_202 ( char * V_1 )
{
V_113 = 1 ;
return 0 ;
}
static int T_1 F_203 ( char * V_1 )
{
V_113 = 1 ;
return 0 ;
}
static int T_1 F_204 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_13
V_195 = 0 ;
return 0 ;
#endif
return - V_57 ;
}
if ( strcmp ( L_92 , V_1 ) == 0 )
V_278 = V_140 ;
else if ( strcmp ( L_93 , V_1 ) == 0 )
V_278 = V_103 ;
else {
F_67 ( L_94
L_95 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_1 F_205 ( void )
{
if ( ! V_122 )
return - 1 ;
V_279 . V_280 = V_122 ;
V_279 . V_281 = V_279 . V_280 + V_282 - 1 ;
F_206 ( & V_283 , & V_279 ) ;
return 0 ;
}
static int T_1 F_207 ( char * V_1 )
{
if ( ! V_1 || ! F_208 ( & V_1 , & V_230 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_209 ( char * V_1 )
{
if ( ! V_1 )
return - V_57 ;
if ( ! strncmp ( L_96 , V_1 , 3 ) )
V_152 = V_175 ;
else if ( ! strncmp ( L_97 , V_1 , 4 ) )
V_152 = V_153 ;
else if ( ! strncmp ( L_98 , V_1 , 3 ) )
V_152 = V_284 ;
else {
F_210 ( L_99 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
