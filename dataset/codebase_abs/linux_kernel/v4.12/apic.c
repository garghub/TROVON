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
V_78 * ( 1000 / V_64 ) ,
0xF , ~ 0UL ) ;
} else
F_59 ( V_70 ) ;
}
static void F_60 ( void * V_79 )
{
struct V_60 * V_70 = F_55 ( & V_71 ) ;
if ( ! F_56 ( V_4 ) )
return;
F_61 ( V_70 , V_78 * ( 1000 / V_64 ) ) ;
}
void F_62 ( void )
{
F_63 ( F_60 , NULL , 0 ) ;
}
static void T_1 F_64 ( struct V_60 * V_80 )
{
unsigned long long V_62 = 0 ;
long V_81 = F_11 ( V_82 ) ;
unsigned long V_83 = F_65 () ;
if ( F_33 ( V_84 ) )
V_62 = F_46 () ;
switch ( V_85 ++ ) {
case 0 :
V_86 = V_81 ;
V_87 = V_62 ;
V_88 = V_83 ;
V_89 = V_90 ;
break;
case V_91 :
V_92 = V_81 ;
V_93 = V_62 ;
if ( V_83 < V_88 )
V_83 += V_94 ;
V_95 = V_83 ;
V_96 = V_90 ;
break;
}
}
static int T_1
F_66 ( long V_97 , long * V_59 , long * V_98 )
{
const long V_99 = V_100 / 10 ;
const long V_101 = V_99 / 100 ;
unsigned long V_102 ;
T_3 V_103 ;
#ifndef F_67
return - 1 ;
#endif
F_68 ( V_104 , L_9 , V_97 ) ;
if ( ! V_97 )
return - 1 ;
V_102 = F_69 ( V_100 , 22 ) ;
if ( V_97 > ( V_99 - V_101 ) &&
V_97 < ( V_99 + V_101 ) ) {
F_68 ( V_104 , L_10 ) ;
return 0 ;
}
V_103 = ( ( ( T_3 ) V_97 ) * V_102 ) >> 22 ;
F_70 ( V_103 , 1000000 ) ;
F_71 ( L_11
L_12 , ( long ) V_103 ) ;
V_103 = ( ( ( T_3 ) ( * V_59 ) ) * V_99 ) ;
F_70 ( V_103 , V_97 ) ;
F_17 ( L_13
L_14 , ( unsigned long ) V_103 , * V_59 ) ;
* V_59 = ( long ) V_103 ;
if ( F_33 ( V_84 ) ) {
V_103 = ( ( ( T_3 ) ( * V_98 ) ) * V_99 ) ;
F_70 ( V_103 , V_97 ) ;
F_68 ( V_104 , L_15
L_16 ,
( unsigned long ) V_103 , * V_98 ) ;
* V_98 = ( long ) V_103 ;
}
return 0 ;
}
static int T_1 F_72 ( void )
{
struct V_60 * V_70 = F_55 ( & V_71 ) ;
void (* F_73)( struct V_60 * V_80 );
unsigned long V_105 ;
long V_59 , V_98 ;
int V_106 = 0 ;
if ( F_33 ( V_4 ) ) {
return 0 ;
} else if ( V_67 ) {
F_68 ( V_104 , L_17 ,
V_67 ) ;
V_73 . V_102 = F_74 ( V_67 / V_43 ,
V_107 , V_73 . V_108 ) ;
V_73 . V_109 =
F_75 ( 0x7FFFFF , & V_73 ) ;
V_73 . V_110 = 0x7FFFFF ;
V_73 . V_111 =
F_75 ( 0xF , & V_73 ) ;
V_73 . V_112 = 0xF ;
V_73 . V_65 &= ~ V_66 ;
return 0 ;
}
F_68 ( V_104 , L_18
L_19 ) ;
F_76 () ;
F_73 = V_113 -> V_114 ;
V_113 -> V_114 = F_64 ;
F_32 ( 0xffffffff , 0 , 0 ) ;
F_77 () ;
while ( V_85 <= V_91 )
F_19 () ;
F_76 () ;
V_113 -> V_114 = F_73 ;
V_59 = V_86 - V_92 ;
F_68 ( V_104 , L_20 , V_59 ) ;
V_98 = ( long ) ( V_93 - V_87 ) ;
V_106 = ! F_66 ( V_95 - V_88 ,
& V_59 , & V_98 ) ;
V_73 . V_102 = F_74 ( V_59 , V_107 * V_91 ,
V_73 . V_108 ) ;
V_73 . V_109 =
F_75 ( 0x7FFFFFFF , & V_73 ) ;
V_73 . V_110 = 0x7FFFFFFF ;
V_73 . V_111 =
F_75 ( 0xF , & V_73 ) ;
V_73 . V_112 = 0xF ;
V_67 = ( V_59 * V_43 ) / V_91 ;
F_68 ( V_104 , L_21 , V_59 ) ;
F_68 ( V_104 , L_22 , V_73 . V_102 ) ;
F_68 ( V_104 , L_23 ,
V_67 ) ;
if ( F_33 ( V_84 ) ) {
F_68 ( V_104 , L_24
L_25 ,
( V_98 / V_91 ) / ( 1000000 / V_115 ) ,
( V_98 / V_91 ) % ( 1000000 / V_115 ) ) ;
}
F_68 ( V_104 , L_26
L_27 ,
V_67 / ( 1000000 / V_115 ) ,
V_67 % ( 1000000 / V_115 ) ) ;
if ( V_67 < ( 1000000 / V_115 ) ) {
F_77 () ;
F_71 ( L_28 ) ;
return - 1 ;
}
V_70 -> V_65 &= ~ V_66 ;
if ( ! V_106 ) {
F_68 ( V_104 , L_29 ) ;
V_70 -> V_114 = F_64 ;
F_50 ( V_70 ) ;
V_85 = - 1 ;
F_77 () ;
while ( V_85 <= V_91 )
F_19 () ;
F_76 () ;
F_48 ( V_70 ) ;
V_105 = V_96 - V_89 ;
F_68 ( V_104 , L_30 , V_105 ) ;
if ( V_105 >= V_91 - 2 && V_105 <= V_91 + 2 )
F_68 ( V_104 , L_31 ) ;
else
V_70 -> V_65 |= V_66 ;
}
F_77 () ;
if ( V_70 -> V_65 & V_66 ) {
F_71 ( L_32 ) ;
return - 1 ;
}
return 0 ;
}
void T_1 F_78 ( void )
{
if ( V_116 ) {
F_17 ( L_33 ) ;
if ( F_79 () > 1 ) {
V_73 . V_102 = 1 ;
F_54 () ;
}
return;
}
if ( F_72 () ) {
if ( F_79 () > 1 )
F_54 () ;
return;
}
V_73 . V_65 &= ~ V_66 ;
F_54 () ;
F_80 () ;
}
void F_81 ( void )
{
F_54 () ;
F_80 () ;
}
static void F_82 ( void )
{
int V_117 = F_43 () ;
struct V_60 * V_61 = & F_83 ( V_71 , V_117 ) ;
if ( ! V_61 -> V_114 ) {
F_71 ( L_34 , V_117 ) ;
F_48 ( V_61 ) ;
return;
}
F_21 ( V_118 ) ;
V_61 -> V_114 ( V_61 ) ;
}
T_5 void T_6 F_84 ( struct V_119 * V_120 )
{
struct V_119 * V_121 = F_85 ( V_120 ) ;
F_86 () ;
F_82 () ;
F_87 () ;
F_85 ( V_121 ) ;
}
T_5 void T_6 F_88 ( struct V_119 * V_120 )
{
struct V_119 * V_121 = F_85 ( V_120 ) ;
F_86 () ;
F_89 ( V_31 ) ;
F_82 () ;
F_90 ( V_31 ) ;
F_87 () ;
F_85 ( V_121 ) ;
}
int F_91 ( unsigned int V_122 )
{
return - V_57 ;
}
void F_92 ( void )
{
int V_123 ;
T_2 V_25 ;
if ( ! V_124 && ! V_125 )
return;
V_123 = F_30 () ;
if ( V_123 >= 3 ) {
V_25 = V_126 ;
F_25 ( V_127 , V_25 | V_35 ) ;
}
V_25 = F_11 ( V_36 ) ;
F_25 ( V_36 , V_25 | V_35 ) ;
V_25 = F_11 ( V_128 ) ;
F_25 ( V_128 , V_25 | V_35 ) ;
V_25 = F_11 ( V_129 ) ;
F_25 ( V_129 , V_25 | V_35 ) ;
if ( V_123 >= 4 ) {
V_25 = F_11 ( V_130 ) ;
F_25 ( V_130 , V_25 | V_35 ) ;
}
#ifdef F_93
if ( V_123 >= 5 ) {
V_25 = F_11 ( V_131 ) ;
F_25 ( V_131 , V_25 | V_35 ) ;
}
#endif
#ifdef F_94
if ( V_123 >= 6 ) {
V_25 = F_11 ( V_132 ) ;
if ( ! ( V_25 & V_35 ) )
F_25 ( V_132 , V_25 | V_35 ) ;
}
#endif
F_25 ( V_36 , V_35 ) ;
F_25 ( V_128 , V_35 ) ;
F_25 ( V_129 , V_35 ) ;
if ( V_123 >= 3 )
F_25 ( V_127 , V_35 ) ;
if ( V_123 >= 4 )
F_25 ( V_130 , V_35 ) ;
if ( F_12 () ) {
if ( V_123 > 3 )
F_25 ( V_133 , 0 ) ;
F_11 ( V_133 ) ;
}
}
void F_95 ( void )
{
unsigned int V_134 ;
if ( ! V_124 && ! V_125 )
return;
F_92 () ;
V_134 = F_11 ( V_135 ) ;
V_134 &= ~ V_136 ;
F_25 ( V_135 , V_134 ) ;
#ifdef V_2
if ( V_137 ) {
unsigned int V_138 , V_139 ;
F_96 ( V_140 , V_138 , V_139 ) ;
V_138 &= ~ V_141 ;
F_97 ( V_140 , V_138 , V_139 ) ;
}
#endif
}
void F_98 ( void )
{
unsigned long V_21 ;
if ( ! F_33 ( V_142 ) && ! F_99 () )
return;
F_24 ( V_21 ) ;
#ifdef V_2
if ( ! V_137 )
F_92 () ;
else
#endif
F_95 () ;
F_27 ( V_21 ) ;
}
void T_1 F_100 ( void )
{
if ( F_15 () || V_8 . V_9 == V_10 )
return;
F_101 () ;
F_68 ( V_143 , L_35 ) ;
F_25 ( V_14 , V_144 |
V_145 | V_146 ) ;
}
void T_1 F_102 ( void )
{
unsigned int V_134 ;
if ( V_147 || ! F_33 ( V_142 ) )
return;
F_92 () ;
V_134 = F_11 ( V_135 ) ;
V_134 &= ~ V_148 ;
V_134 |= V_136 ;
#ifdef V_2
if ( ( V_8 . V_9 == V_149 ) &&
( V_8 . V_11 == 15 ) )
V_134 &= ~ V_150 ;
else
#endif
V_134 |= V_150 ;
V_134 |= V_151 ;
F_25 ( V_135 , V_134 ) ;
F_25 ( V_128 , V_152 ) ;
V_134 = V_153 ;
if ( ! F_12 () )
V_134 |= V_154 ;
if ( V_155 == V_156 )
V_134 |= V_35 ;
F_25 ( V_129 , V_134 ) ;
}
static void F_103 ( void )
{
unsigned int V_157 , V_134 , V_123 ;
if ( ! F_12 () ) {
F_17 ( L_36 ) ;
return;
}
if ( V_12 -> V_158 ) {
F_17 ( L_37 ) ;
return;
}
V_123 = F_30 () ;
if ( V_123 > 3 )
F_25 ( V_133 , 0 ) ;
V_157 = F_11 ( V_133 ) ;
V_134 = V_126 ;
F_25 ( V_127 , V_134 ) ;
if ( V_123 > 3 )
F_25 ( V_133 , 0 ) ;
V_134 = F_11 ( V_133 ) ;
if ( V_134 != V_157 )
F_68 ( V_104 , L_38
L_39 ,
V_157 , V_134 ) ;
}
void F_104 ( void )
{
int V_117 = F_43 () ;
unsigned int V_134 , V_159 ;
int V_160 , V_161 , V_162 = 0 ;
unsigned long long V_62 = 0 , V_163 ;
long long V_164 = V_165 ? V_165 : 1000000 ;
if ( F_33 ( V_84 ) )
V_62 = F_46 () ;
if ( V_166 ) {
F_105 () ;
return;
}
#ifdef V_2
if ( F_12 () && V_12 -> V_158 ) {
F_25 ( V_133 , 0 ) ;
F_25 ( V_133 , 0 ) ;
F_25 ( V_133 , 0 ) ;
F_25 ( V_133 , 0 ) ;
}
#endif
F_106 () ;
F_107 ( ! V_12 -> V_167 () ) ;
V_12 -> V_168 () ;
#ifdef V_2
V_160 = F_108 ( V_169 , V_117 ) ;
F_109 ( V_160 != V_170 && V_160 != F_110 () ) ;
F_108 ( V_169 , V_117 ) =
F_110 () ;
#endif
V_134 = F_11 ( V_171 ) ;
V_134 &= ~ V_172 ;
F_25 ( V_171 , V_134 ) ;
do {
V_159 = 0 ;
for ( V_160 = V_173 - 1 ; V_160 >= 0 ; V_160 -- )
V_159 |= F_11 ( V_174 + V_160 * 0x10 ) ;
for ( V_160 = V_173 - 1 ; V_160 >= 0 ; V_160 -- ) {
V_134 = F_11 ( V_175 + V_160 * 0x10 ) ;
for ( V_161 = 31 ; V_161 >= 0 ; V_161 -- ) {
if ( V_134 & ( 1 << V_161 ) ) {
F_111 () ;
V_162 ++ ;
}
}
}
if ( V_162 > 256 ) {
F_112 ( V_176 L_40 ,
V_162 ) ;
break;
}
if ( V_159 ) {
if ( F_33 ( V_84 ) && V_165 ) {
V_163 = F_46 () ;
V_164 = ( V_165 << 10 ) - ( V_163 - V_62 ) ;
} else
V_164 -- ;
}
} while ( V_159 && V_164 > 0 );
F_109 ( V_164 <= 0 ) ;
V_134 = F_11 ( V_135 ) ;
V_134 &= ~ V_148 ;
V_134 |= V_136 ;
#ifdef V_2
V_134 &= ~ V_150 ;
#endif
V_134 |= V_151 ;
F_25 ( V_135 , V_134 ) ;
V_134 = F_11 ( V_128 ) & V_35 ;
if ( ! V_117 && ( V_177 || ! V_134 ) ) {
V_134 = V_152 ;
F_68 ( V_104 , L_41 , V_117 ) ;
} else {
V_134 = V_152 | V_35 ;
F_68 ( V_104 , L_42 , V_117 ) ;
}
F_25 ( V_128 , V_134 ) ;
if ( ( ! V_117 && V_155 != V_156 ) ||
V_155 == V_178 )
V_134 = V_153 ;
else
V_134 = V_153 | V_35 ;
if ( ! F_12 () )
V_134 |= V_154 ;
F_25 ( V_129 , V_134 ) ;
#ifdef F_94
if ( ! V_117 )
F_113 () ;
#endif
}
static void F_114 ( void )
{
F_103 () ;
#ifdef V_2
{
unsigned int V_134 ;
V_134 = F_11 ( V_36 ) ;
V_134 |= ( V_35 | V_31 ) ;
F_25 ( V_36 , V_134 ) ;
}
#endif
F_115 () ;
}
void F_116 ( void )
{
F_104 () ;
F_114 () ;
}
static void F_117 ( void )
{
T_3 V_179 ;
if ( ! F_33 ( V_142 ) )
return;
F_118 ( V_140 , V_179 ) ;
if ( ! ( V_179 & V_180 ) )
return;
F_47 ( V_140 , V_179 & ~ ( V_180 | V_181 ) ) ;
F_47 ( V_140 , V_179 & ~ V_180 ) ;
F_35 ( V_182 L_43 ) ;
}
static void F_119 ( void )
{
T_3 V_179 ;
F_118 ( V_140 , V_179 ) ;
if ( V_179 & V_180 )
return;
F_47 ( V_140 , V_179 | V_180 ) ;
F_35 ( V_182 L_44 ) ;
}
static int T_1 F_120 ( char * V_183 )
{
if ( F_121 () ) {
int V_184 = F_122 ( V_185 ) ;
if ( V_184 >= 255 ) {
F_71 ( L_45 ,
V_184 ) ;
return 0 ;
}
F_71 ( L_46 ) ;
F_117 () ;
}
F_6 ( V_186 ) ;
V_187 = V_188 ;
V_124 = 0 ;
return 0 ;
}
void F_123 ( void )
{
if ( V_187 != V_189 ) {
F_117 () ;
return;
}
F_119 () ;
}
static T_1 void F_124 ( void )
{
T_2 V_190 , V_191 = V_187 ;
V_124 = 0 ;
V_187 = V_188 ;
if ( V_191 != V_189 )
return;
V_190 = F_125 () ;
if ( V_190 >= 255 )
F_126 ( L_47 , V_190 ) ;
F_117 () ;
F_127 ( V_192 ) ;
}
static T_1 void F_128 ( void )
{
if ( V_187 != V_193 )
return;
V_124 = 1 ;
V_187 = V_189 ;
F_119 () ;
}
static T_1 void F_129 ( int V_194 )
{
if ( V_187 == V_188 )
return;
if ( V_194 != V_195 ) {
if ( V_196 > 255 ||
! F_130 () ) {
F_17 ( L_48 ) ;
F_124 () ;
return;
}
V_197 = 1 ;
}
F_128 () ;
}
void T_1 F_131 ( void )
{
if ( F_121 () ) {
F_17 ( L_49 ) ;
V_124 = 1 ;
V_187 = V_189 ;
} else if ( ! F_33 ( V_186 ) ) {
V_187 = V_188 ;
}
}
static int T_1 F_132 ( void )
{
if ( ! F_133 () )
return 0 ;
F_126 ( L_50 ) ;
}
static inline void F_129 ( int V_194 ) { }
static inline void F_119 ( void ) { }
void T_1 F_134 ( void )
{
unsigned long V_21 ;
int V_198 , V_199 ;
if ( V_200 ) {
F_17 ( L_51 ) ;
return;
}
V_199 = F_135 () ;
if ( V_199 < 0 && ! F_136 () )
return;
V_198 = F_137 () ;
if ( V_198 ) {
F_17 ( L_52 , V_198 ) ;
return;
}
F_24 ( V_21 ) ;
V_201 -> V_202 () ;
F_138 () ;
if ( V_199 >= 0 )
V_199 = F_139 () ;
F_129 ( V_199 ) ;
if ( V_199 < 0 )
F_140 () ;
V_201 -> V_203 () ;
F_27 ( V_21 ) ;
}
static int T_1 F_141 ( void )
{
if ( ! F_33 ( V_142 ) ) {
F_17 ( L_53 ) ;
return - 1 ;
}
V_192 = V_204 ;
return 0 ;
}
static int T_1 F_142 ( void )
{
T_2 V_65 , V_139 , V_138 ;
V_65 = F_143 ( 1 ) ;
if ( ! ( V_65 & ( 1 << V_142 ) ) ) {
F_71 ( L_54 ) ;
return - 1 ;
}
F_144 ( & V_8 , V_142 ) ;
V_192 = V_204 ;
if ( V_8 . V_11 >= 6 ) {
F_96 ( V_140 , V_138 , V_139 ) ;
if ( V_138 & V_141 )
V_192 = V_138 & V_205 ;
}
F_17 ( L_55 ) ;
return 0 ;
}
int T_1 F_145 ( unsigned long V_206 )
{
T_2 V_139 , V_138 ;
if ( V_166 )
return - 1 ;
if ( V_8 . V_11 >= 6 ) {
F_96 ( V_140 , V_138 , V_139 ) ;
if ( ! ( V_138 & V_141 ) ) {
F_17 ( L_56 ) ;
V_138 &= ~ V_205 ;
V_138 |= V_141 | V_206 ;
F_97 ( V_140 , V_138 , V_139 ) ;
V_137 = 1 ;
}
}
return F_142 () ;
}
static int T_1 F_141 ( void )
{
if ( V_166 )
return - 1 ;
switch ( V_8 . V_9 ) {
case V_10 :
if ( ( V_8 . V_11 == 6 && V_8 . V_207 > 1 ) ||
( V_8 . V_11 >= 15 ) )
break;
goto V_208;
case V_149 :
if ( V_8 . V_11 == 6 || V_8 . V_11 == 15 ||
( V_8 . V_11 == 5 && F_33 ( V_142 ) ) )
break;
goto V_208;
default:
goto V_208;
}
if ( ! F_33 ( V_142 ) ) {
if ( ! V_3 ) {
F_17 ( L_57
L_58 ) ;
return - 1 ;
}
if ( F_145 ( V_204 ) )
return - 1 ;
} else {
if ( F_142 () )
return - 1 ;
}
F_115 () ;
return 0 ;
V_208:
F_17 ( L_59 ) ;
return - 1 ;
}
void T_1 F_146 ( void )
{
unsigned int V_209 ;
if ( V_124 ) {
V_210 = F_125 () ;
return;
}
if ( ! V_147 && F_141 () ) {
F_17 ( L_60 ) ;
F_16 () ;
} else {
V_125 = V_192 ;
if ( ! V_211 && ! V_147 )
F_127 ( V_125 ) ;
}
V_209 = F_125 () ;
if ( V_210 != V_209 ) {
V_210 = V_209 ;
V_212 = F_10 ( F_11 ( V_7 ) ) ;
}
}
void T_1 F_127 ( unsigned long V_213 )
{
V_192 = V_213 ;
if ( ! V_124 ) {
F_147 ( V_214 , V_213 ) ;
F_68 ( V_104 , L_61 ,
V_215 , V_213 ) ;
}
if ( V_210 == - 1U ) {
V_210 = F_125 () ;
V_212 = F_10 ( F_11 ( V_7 ) ) ;
}
}
static void F_148 ( T_4 V_49 )
{
T_2 V_25 ;
V_25 = F_11 ( V_175 + ( ( V_49 & ~ 0x1f ) >> 1 ) ) ;
if ( V_25 & ( 1 << ( V_49 & 0x1f ) ) )
F_111 () ;
F_21 ( V_216 ) ;
F_17 ( L_62
L_63 , V_49 , F_43 () ) ;
}
T_5 void T_6 F_149 ( struct V_119 * V_120 )
{
F_150 () ;
F_148 ( ~ V_120 -> V_217 ) ;
F_87 () ;
}
T_5 void T_6 F_151 ( struct V_119 * V_120 )
{
T_4 V_49 = ~ V_120 -> V_217 ;
F_150 () ;
F_152 ( V_49 ) ;
F_148 ( V_49 ) ;
F_153 ( V_49 ) ;
F_87 () ;
}
static void F_154 ( struct V_119 * V_120 )
{
T_2 V_25 ;
T_2 V_160 = 0 ;
static const char * const V_218 [] = {
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
F_25 ( V_133 , 0 ) ;
V_25 = F_11 ( V_133 ) ;
F_111 () ;
F_155 ( & V_219 ) ;
F_68 ( V_143 , V_37 L_72 ,
F_43 () , V_25 ) ;
V_25 &= 0xff ;
while ( V_25 ) {
if ( V_25 & 0x1 )
F_68 ( V_143 , V_220 L_73 , V_218 [ V_160 ] ) ;
V_160 ++ ;
V_25 >>= 1 ;
}
F_68 ( V_143 , V_220 L_74 ) ;
}
T_5 void T_6 F_156 ( struct V_119 * V_120 )
{
F_150 () ;
F_154 ( V_120 ) ;
F_87 () ;
}
T_5 void T_6 F_157 ( struct V_119 * V_120 )
{
F_150 () ;
F_158 ( V_126 ) ;
F_154 ( V_120 ) ;
F_159 ( V_126 ) ;
F_87 () ;
}
static void T_1 F_160 ( void )
{
#ifdef V_2
if ( V_177 ) {
F_92 () ;
F_68 ( V_104 , L_75
L_76 ) ;
F_1 () ;
}
#endif
}
void F_161 ( int V_221 )
{
unsigned int V_134 ;
#ifdef V_2
if ( V_177 ) {
F_68 ( V_104 , L_77
L_78 ) ;
F_3 () ;
return;
}
#endif
V_134 = F_11 ( V_135 ) ;
V_134 &= ~ V_148 ;
V_134 |= V_136 ;
V_134 |= 0xf ;
F_25 ( V_135 , V_134 ) ;
if ( ! V_221 ) {
V_134 = F_11 ( V_128 ) ;
V_134 &= ~ ( V_222 | V_223 |
V_224 | V_225 |
V_154 | V_35 ) ;
V_134 |= V_225 | V_223 ;
V_134 = F_162 ( V_134 , V_226 ) ;
F_25 ( V_128 , V_134 ) ;
} else {
F_25 ( V_128 , V_35 ) ;
}
V_134 = F_11 ( V_129 ) ;
V_134 &= ~ ( V_222 | V_223 |
V_224 | V_225 |
V_154 | V_35 ) ;
V_134 |= V_225 | V_223 ;
V_134 = F_162 ( V_134 , V_227 ) ;
F_25 ( V_129 , V_134 ) ;
}
static int F_163 ( int V_184 )
{
int V_160 ;
for ( V_160 = 0 ; V_160 < V_228 ; V_160 ++ ) {
if ( V_229 [ V_160 ] == V_184 )
return V_160 ;
}
if ( V_228 >= V_230 ) {
F_164 ( 1 , L_79
L_80 ,
V_230 , V_228 , V_184 ) ;
return - V_57 ;
}
V_229 [ V_228 ] = V_184 ;
return V_228 ++ ;
}
int F_165 ( int V_184 , int V_231 )
{
int V_117 , V_232 = V_230 ;
bool V_233 = F_166 ( V_210 ,
V_234 ) ;
if ( V_235 != V_170 &&
V_235 != F_125 () &&
V_235 == V_184 ) {
int V_236 = V_237 + V_238 ;
F_71 ( L_81
L_82 ,
V_236 , V_184 ) ;
V_238 ++ ;
return - V_239 ;
}
if ( ! V_233 && V_237 >= V_230 - 1 &&
V_184 != V_210 ) {
int V_236 = V_232 + V_238 - 1 ;
F_71 (
L_83
L_84
L_85 , V_232 , V_236 , V_184 ) ;
V_238 ++ ;
return - V_239 ;
}
if ( V_237 >= V_230 ) {
int V_236 = V_232 + V_238 ;
F_71 ( L_86
L_87 ,
V_232 , V_236 , V_184 ) ;
V_238 ++ ;
return - V_57 ;
}
if ( V_184 == V_210 ) {
V_117 = 0 ;
V_229 [ 0 ] = V_184 ;
} else {
V_117 = F_163 ( V_184 ) ;
if ( V_117 < 0 ) {
V_238 ++ ;
return - V_57 ;
}
}
if ( V_231 == 0x0 ) {
F_71 ( L_88 ,
V_117 , V_184 ) ;
V_231 = 0x10 ;
}
if ( V_231 != V_212 ) {
F_71 ( L_89 ,
V_212 , V_117 , V_231 ) ;
}
if ( V_184 > V_196 )
V_196 = V_184 ;
#if F_167 ( F_53 ) || F_167 ( F_13 )
F_108 ( V_240 , V_117 ) = V_184 ;
F_108 ( V_241 , V_117 ) = V_184 ;
#endif
#ifdef V_2
F_108 ( V_169 , V_117 ) =
V_12 -> V_242 ( V_117 ) ;
#endif
F_168 ( V_117 , true ) ;
F_169 ( V_184 , V_234 ) ;
F_170 ( V_117 , true ) ;
V_237 ++ ;
return V_117 ;
}
int F_171 ( void )
{
return F_125 () ;
}
void F_172 ( void )
{
unsigned long V_243 ;
F_25 ( V_244 , V_245 ) ;
V_243 = F_11 ( V_246 ) & ~ V_247 ;
V_243 |= F_173 ( 1UL << F_43 () ) ;
F_25 ( V_246 , V_243 ) ;
}
int F_174 ( const struct V_68 * V_68 ,
const struct V_68 * V_248 ,
unsigned int * V_184 )
{
unsigned int V_117 ;
F_175 (cpu, cpumask, andmask) {
if ( F_176 ( V_117 , V_249 ) )
break;
}
if ( F_177 ( V_117 < V_230 ) ) {
* V_184 = F_83 ( V_240 , V_117 ) ;
return 0 ;
}
return - V_57 ;
}
void T_1 F_178 ( void (* F_179)( T_2 V_54 , T_2 V_25 ) )
{
struct V_12 * * V_250 ;
for ( V_250 = V_251 ; V_250 < V_252 ; V_250 ++ ) {
F_109 ( ( * V_250 ) -> F_179 == F_179 ) ;
( * V_250 ) -> V_253 = ( * V_250 ) -> F_179 ;
( * V_250 ) -> F_179 = F_179 ;
}
}
static void T_1 F_180 ( void )
{
#ifdef F_13
F_25 ( V_185 , V_12 -> V_254 ( V_210 ) ) ;
#else
# ifdef F_181
V_210 = F_125 () ;
# endif
#endif
F_182 ( V_210 , & V_234 ) ;
}
int T_1 F_183 ( bool V_255 )
{
int V_20 ;
F_160 () ;
if ( V_255 )
F_180 () ;
F_104 () ;
if ( V_124 )
V_20 = F_11 ( V_246 ) ;
else
V_20 = F_184 ( F_11 ( V_246 ) ) ;
F_185 () ;
F_114 () ;
F_186 () ;
F_187 () ;
V_256 . V_257 . V_258 () ;
return V_20 ;
}
int T_1 F_188 ( void )
{
if ( V_166 ) {
F_17 ( L_90 ) ;
return - 1 ;
}
#ifdef F_13
if ( ! F_33 ( V_142 ) ) {
V_166 = 1 ;
F_17 ( L_91 ) ;
return - 1 ;
}
#else
if ( ! V_147 && ! F_33 ( V_142 ) )
return - 1 ;
if ( ! F_33 ( V_142 ) &&
F_14 ( V_212 ) ) {
F_42 ( L_92 ,
V_210 ) ;
return - 1 ;
}
#endif
if ( ! V_147 )
F_105 () ;
F_189 () ;
F_183 ( true ) ;
return 0 ;
}
void T_1 F_190 ( void )
{
F_188 () ;
}
static int F_191 ( void )
{
unsigned long V_21 ;
int V_123 ;
if ( ! V_259 . V_260 )
return 0 ;
V_123 = F_30 () ;
V_259 . V_261 = F_11 ( V_185 ) ;
V_259 . V_262 = F_11 ( V_171 ) ;
V_259 . V_263 = F_11 ( V_246 ) ;
V_259 . V_264 = F_11 ( V_244 ) ;
V_259 . V_265 = F_11 ( V_135 ) ;
V_259 . V_266 = F_11 ( V_36 ) ;
if ( V_123 >= 4 )
V_259 . V_267 = F_11 ( V_130 ) ;
V_259 . V_268 = F_11 ( V_128 ) ;
V_259 . V_269 = F_11 ( V_129 ) ;
V_259 . V_270 = F_11 ( V_127 ) ;
V_259 . V_271 = F_11 ( V_42 ) ;
V_259 . V_272 = F_11 ( V_38 ) ;
#ifdef F_93
if ( V_123 >= 5 )
V_259 . V_273 = F_11 ( V_131 ) ;
#endif
#ifdef F_94
if ( V_123 >= 6 )
V_259 . V_274 = F_11 ( V_132 ) ;
#endif
F_24 ( V_21 ) ;
F_95 () ;
F_192 () ;
F_27 ( V_21 ) ;
return 0 ;
}
static void F_193 ( void )
{
unsigned int V_138 , V_139 ;
unsigned long V_21 ;
int V_123 ;
if ( ! V_259 . V_260 )
return;
F_24 ( V_21 ) ;
F_138 () ;
V_201 -> V_202 () ;
if ( V_124 ) {
F_119 () ;
} else {
if ( V_8 . V_11 >= 6 ) {
F_96 ( V_140 , V_138 , V_139 ) ;
V_138 &= ~ V_205 ;
V_138 |= V_141 | V_192 ;
F_97 ( V_140 , V_138 , V_139 ) ;
}
}
V_123 = F_30 () ;
F_25 ( V_127 , V_126 | V_35 ) ;
F_25 ( V_185 , V_259 . V_261 ) ;
F_25 ( V_244 , V_259 . V_264 ) ;
F_25 ( V_246 , V_259 . V_263 ) ;
F_25 ( V_171 , V_259 . V_262 ) ;
F_25 ( V_135 , V_259 . V_265 ) ;
F_25 ( V_128 , V_259 . V_268 ) ;
F_25 ( V_129 , V_259 . V_269 ) ;
#ifdef F_93
if ( V_123 >= 5 )
F_25 ( V_131 , V_259 . V_273 ) ;
#endif
#ifdef F_94
if ( V_123 >= 6 )
F_25 ( V_132 , V_259 . V_274 ) ;
#endif
if ( V_123 >= 4 )
F_25 ( V_130 , V_259 . V_267 ) ;
F_25 ( V_36 , V_259 . V_266 ) ;
F_25 ( V_38 , V_259 . V_272 ) ;
F_25 ( V_42 , V_259 . V_271 ) ;
F_25 ( V_133 , 0 ) ;
F_11 ( V_133 ) ;
F_25 ( V_127 , V_259 . V_270 ) ;
F_25 ( V_133 , 0 ) ;
F_11 ( V_133 ) ;
F_194 ( V_124 ) ;
F_27 ( V_21 ) ;
}
static void F_115 ( void )
{
V_259 . V_260 = 1 ;
}
static int T_1 F_195 ( void )
{
if ( F_33 ( V_142 ) )
F_196 ( & V_275 ) ;
return 0 ;
}
static void F_115 ( void ) { }
static int F_197 ( const struct V_276 * V_277 )
{
if ( V_278 )
return 0 ;
F_17 ( L_93 , V_277 -> V_279 ) ;
V_278 = 1 ;
return 0 ;
}
static void F_198 ( void )
{
if ( V_280 )
return;
F_199 ( V_281 ) ;
V_280 = 1 ;
}
int F_200 ( void )
{
F_198 () ;
return V_278 ;
}
static int T_1 F_201 ( char * V_1 )
{
V_166 = 1 ;
F_6 ( V_142 ) ;
return 0 ;
}
static int T_1 F_202 ( char * V_1 )
{
return F_201 ( V_1 ) ;
}
static int T_1 F_203 ( char * V_1 )
{
V_282 = 1 ;
return 0 ;
}
static int T_1 F_204 ( char * V_1 )
{
V_116 = 1 ;
return 0 ;
}
static int T_1 F_205 ( char * V_1 )
{
V_116 = 1 ;
return 0 ;
}
static int T_1 F_206 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_13
V_200 = 0 ;
return 0 ;
#endif
return - V_57 ;
}
if ( strcmp ( L_94 , V_1 ) == 0 )
V_283 = V_143 ;
else if ( strcmp ( L_95 , V_1 ) == 0 )
V_283 = V_104 ;
else {
F_71 ( L_96
L_97 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_1 F_207 ( void )
{
if ( ! V_125 )
return - 1 ;
V_284 . V_285 = V_125 ;
V_284 . V_286 = V_284 . V_285 + V_287 - 1 ;
F_208 ( & V_288 , & V_284 ) ;
return 0 ;
}
static int T_1 F_209 ( char * V_1 )
{
if ( ! V_1 || ! F_210 ( & V_1 , & V_235 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_211 ( char * V_1 )
{
if ( ! V_1 )
return - V_57 ;
if ( ! strncmp ( L_98 , V_1 , 3 ) )
V_155 = V_178 ;
else if ( ! strncmp ( L_99 , V_1 , 4 ) )
V_155 = V_156 ;
else if ( ! strncmp ( L_100 , V_1 , 3 ) )
V_155 = V_289 ;
else {
F_212 ( L_101 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
