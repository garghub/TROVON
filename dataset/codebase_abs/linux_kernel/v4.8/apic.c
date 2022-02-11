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
V_73 . V_110 =
F_75 ( 0xF , & V_73 ) ;
V_73 . V_65 &= ~ V_66 ;
return 0 ;
}
F_68 ( V_104 , L_18
L_19 ) ;
F_76 () ;
F_73 = V_111 -> V_112 ;
V_111 -> V_112 = F_64 ;
F_32 ( 0xffffffff , 0 , 0 ) ;
F_77 () ;
while ( V_85 <= V_91 )
F_19 () ;
F_76 () ;
V_111 -> V_112 = F_73 ;
V_59 = V_86 - V_92 ;
F_68 ( V_104 , L_20 , V_59 ) ;
V_98 = ( long ) ( V_93 - V_87 ) ;
V_106 = ! F_66 ( V_95 - V_88 ,
& V_59 , & V_98 ) ;
V_73 . V_102 = F_74 ( V_59 , V_107 * V_91 ,
V_73 . V_108 ) ;
V_73 . V_109 =
F_75 ( 0x7FFFFFFF , & V_73 ) ;
V_73 . V_110 =
F_75 ( 0xF , & V_73 ) ;
V_67 = ( V_59 * V_43 ) / V_91 ;
F_68 ( V_104 , L_21 , V_59 ) ;
F_68 ( V_104 , L_22 , V_73 . V_102 ) ;
F_68 ( V_104 , L_23 ,
V_67 ) ;
if ( F_33 ( V_84 ) ) {
F_68 ( V_104 , L_24
L_25 ,
( V_98 / V_91 ) / ( 1000000 / V_113 ) ,
( V_98 / V_91 ) % ( 1000000 / V_113 ) ) ;
}
F_68 ( V_104 , L_26
L_27 ,
V_67 / ( 1000000 / V_113 ) ,
V_67 % ( 1000000 / V_113 ) ) ;
if ( V_67 < ( 1000000 / V_113 ) ) {
F_77 () ;
F_71 ( L_28 ) ;
return - 1 ;
}
V_70 -> V_65 &= ~ V_66 ;
if ( ! V_106 ) {
F_68 ( V_104 , L_29 ) ;
V_70 -> V_112 = F_64 ;
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
if ( V_114 ) {
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
}
void F_80 ( void )
{
F_54 () ;
}
static void F_81 ( void )
{
int V_115 = F_43 () ;
struct V_60 * V_61 = & F_82 ( V_71 , V_115 ) ;
if ( ! V_61 -> V_112 ) {
F_71 ( L_34 , V_115 ) ;
F_48 ( V_61 ) ;
return;
}
F_21 ( V_116 ) ;
V_61 -> V_112 ( V_61 ) ;
}
T_5 void T_6 F_83 ( struct V_117 * V_118 )
{
struct V_117 * V_119 = F_84 ( V_118 ) ;
F_85 () ;
F_81 () ;
F_86 () ;
F_84 ( V_119 ) ;
}
T_5 void T_6 F_87 ( struct V_117 * V_118 )
{
struct V_117 * V_119 = F_84 ( V_118 ) ;
F_85 () ;
F_88 ( V_31 ) ;
F_81 () ;
F_89 ( V_31 ) ;
F_86 () ;
F_84 ( V_119 ) ;
}
int F_90 ( unsigned int V_120 )
{
return - V_57 ;
}
void F_91 ( void )
{
int V_121 ;
T_2 V_25 ;
if ( ! V_122 && ! V_123 )
return;
V_121 = F_30 () ;
if ( V_121 >= 3 ) {
V_25 = V_124 ;
F_25 ( V_125 , V_25 | V_35 ) ;
}
V_25 = F_11 ( V_36 ) ;
F_25 ( V_36 , V_25 | V_35 ) ;
V_25 = F_11 ( V_126 ) ;
F_25 ( V_126 , V_25 | V_35 ) ;
V_25 = F_11 ( V_127 ) ;
F_25 ( V_127 , V_25 | V_35 ) ;
if ( V_121 >= 4 ) {
V_25 = F_11 ( V_128 ) ;
F_25 ( V_128 , V_25 | V_35 ) ;
}
#ifdef F_92
if ( V_121 >= 5 ) {
V_25 = F_11 ( V_129 ) ;
F_25 ( V_129 , V_25 | V_35 ) ;
}
#endif
#ifdef F_93
if ( V_121 >= 6 ) {
V_25 = F_11 ( V_130 ) ;
if ( ! ( V_25 & V_35 ) )
F_25 ( V_130 , V_25 | V_35 ) ;
}
#endif
F_25 ( V_36 , V_35 ) ;
F_25 ( V_126 , V_35 ) ;
F_25 ( V_127 , V_35 ) ;
if ( V_121 >= 3 )
F_25 ( V_125 , V_35 ) ;
if ( V_121 >= 4 )
F_25 ( V_128 , V_35 ) ;
if ( F_12 () ) {
if ( V_121 > 3 )
F_25 ( V_131 , 0 ) ;
F_11 ( V_131 ) ;
}
}
void F_94 ( void )
{
unsigned int V_132 ;
if ( ! V_122 && ! V_123 )
return;
F_91 () ;
V_132 = F_11 ( V_133 ) ;
V_132 &= ~ V_134 ;
F_25 ( V_133 , V_132 ) ;
#ifdef V_2
if ( V_135 ) {
unsigned int V_136 , V_137 ;
F_95 ( V_138 , V_136 , V_137 ) ;
V_136 &= ~ V_139 ;
F_96 ( V_138 , V_136 , V_137 ) ;
}
#endif
}
void F_97 ( void )
{
unsigned long V_21 ;
if ( ! F_33 ( V_140 ) && ! F_98 () )
return;
F_24 ( V_21 ) ;
#ifdef V_2
if ( ! V_135 )
F_91 () ;
else
#endif
F_94 () ;
F_27 ( V_21 ) ;
}
void T_1 F_99 ( void )
{
if ( F_15 () || V_8 . V_9 == V_10 )
return;
F_100 () ;
F_68 ( V_141 , L_35 ) ;
F_25 ( V_14 , V_142 |
V_143 | V_144 ) ;
}
void T_1 F_101 ( void )
{
unsigned int V_132 ;
if ( V_145 || ! F_33 ( V_140 ) )
return;
F_91 () ;
V_132 = F_11 ( V_133 ) ;
V_132 &= ~ V_146 ;
V_132 |= V_134 ;
#ifdef V_2
if ( ( V_8 . V_9 == V_147 ) &&
( V_8 . V_11 == 15 ) )
V_132 &= ~ V_148 ;
else
#endif
V_132 |= V_148 ;
V_132 |= V_149 ;
F_25 ( V_133 , V_132 ) ;
F_25 ( V_126 , V_150 ) ;
V_132 = V_151 ;
if ( ! F_12 () )
V_132 |= V_152 ;
if ( V_153 == V_154 )
V_132 |= V_35 ;
F_25 ( V_127 , V_132 ) ;
}
static void F_102 ( void )
{
unsigned int V_155 , V_132 , V_121 ;
if ( ! F_12 () ) {
F_17 ( L_36 ) ;
return;
}
if ( V_12 -> V_156 ) {
F_17 ( L_37 ) ;
return;
}
V_121 = F_30 () ;
if ( V_121 > 3 )
F_25 ( V_131 , 0 ) ;
V_155 = F_11 ( V_131 ) ;
V_132 = V_124 ;
F_25 ( V_125 , V_132 ) ;
if ( V_121 > 3 )
F_25 ( V_131 , 0 ) ;
V_132 = F_11 ( V_131 ) ;
if ( V_132 != V_155 )
F_68 ( V_104 , L_38
L_39 ,
V_155 , V_132 ) ;
}
void F_103 ( void )
{
int V_115 = F_43 () ;
unsigned int V_132 , V_157 ;
int V_158 , V_159 , V_160 = 0 ;
unsigned long long V_62 = 0 , V_161 ;
long long V_162 = V_163 ? V_163 : 1000000 ;
if ( F_33 ( V_84 ) )
V_62 = F_46 () ;
if ( V_164 ) {
F_104 () ;
return;
}
#ifdef V_2
if ( F_12 () && V_12 -> V_156 ) {
F_25 ( V_131 , 0 ) ;
F_25 ( V_131 , 0 ) ;
F_25 ( V_131 , 0 ) ;
F_25 ( V_131 , 0 ) ;
}
#endif
F_105 () ;
F_106 ( ! V_12 -> V_165 () ) ;
V_12 -> V_166 () ;
#ifdef V_2
V_158 = F_107 ( V_167 , V_115 ) ;
F_108 ( V_158 != V_168 && V_158 != F_109 () ) ;
F_107 ( V_167 , V_115 ) =
F_109 () ;
#endif
V_132 = F_11 ( V_169 ) ;
V_132 &= ~ V_170 ;
F_25 ( V_169 , V_132 ) ;
do {
V_157 = 0 ;
for ( V_158 = V_171 - 1 ; V_158 >= 0 ; V_158 -- )
V_157 |= F_11 ( V_172 + V_158 * 0x10 ) ;
for ( V_158 = V_171 - 1 ; V_158 >= 0 ; V_158 -- ) {
V_132 = F_11 ( V_173 + V_158 * 0x10 ) ;
for ( V_159 = 31 ; V_159 >= 0 ; V_159 -- ) {
if ( V_132 & ( 1 << V_159 ) ) {
F_110 () ;
V_160 ++ ;
}
}
}
if ( V_160 > 256 ) {
F_111 ( V_174 L_40 ,
V_160 ) ;
break;
}
if ( V_157 ) {
if ( F_33 ( V_84 ) && V_163 ) {
V_161 = F_46 () ;
V_162 = ( V_163 << 10 ) - ( V_161 - V_62 ) ;
} else
V_162 -- ;
}
} while ( V_157 && V_162 > 0 );
F_108 ( V_162 <= 0 ) ;
V_132 = F_11 ( V_133 ) ;
V_132 &= ~ V_146 ;
V_132 |= V_134 ;
#ifdef V_2
V_132 &= ~ V_148 ;
#endif
V_132 |= V_149 ;
F_25 ( V_133 , V_132 ) ;
V_132 = F_11 ( V_126 ) & V_35 ;
if ( ! V_115 && ( V_175 || ! V_132 ) ) {
V_132 = V_150 ;
F_68 ( V_104 , L_41 , V_115 ) ;
} else {
V_132 = V_150 | V_35 ;
F_68 ( V_104 , L_42 , V_115 ) ;
}
F_25 ( V_126 , V_132 ) ;
if ( ( ! V_115 && V_153 != V_154 ) ||
V_153 == V_176 )
V_132 = V_151 ;
else
V_132 = V_151 | V_35 ;
if ( ! F_12 () )
V_132 |= V_152 ;
F_25 ( V_127 , V_132 ) ;
#ifdef F_93
if ( ! V_115 )
F_112 () ;
#endif
}
static void F_113 ( void )
{
F_102 () ;
#ifdef V_2
{
unsigned int V_132 ;
V_132 = F_11 ( V_36 ) ;
V_132 |= ( V_35 | V_31 ) ;
F_25 ( V_36 , V_132 ) ;
}
#endif
F_114 () ;
}
void F_115 ( void )
{
F_103 () ;
F_113 () ;
}
static void F_116 ( void )
{
T_3 V_177 ;
if ( ! F_33 ( V_140 ) )
return;
F_117 ( V_138 , V_177 ) ;
if ( ! ( V_177 & V_178 ) )
return;
F_47 ( V_138 , V_177 & ~ ( V_178 | V_179 ) ) ;
F_47 ( V_138 , V_177 & ~ V_178 ) ;
F_35 ( V_180 L_43 ) ;
}
static void F_118 ( void )
{
T_3 V_177 ;
F_117 ( V_138 , V_177 ) ;
if ( V_177 & V_178 )
return;
F_47 ( V_138 , V_177 | V_178 ) ;
F_35 ( V_180 L_44 ) ;
}
static int T_1 F_119 ( char * V_181 )
{
if ( F_120 () ) {
int V_182 = F_121 ( V_183 ) ;
if ( V_182 >= 255 ) {
F_71 ( L_45 ,
V_182 ) ;
return 0 ;
}
F_71 ( L_46 ) ;
F_116 () ;
}
F_6 ( V_184 ) ;
V_185 = V_186 ;
V_122 = 0 ;
return 0 ;
}
void F_122 ( void )
{
if ( V_185 != V_187 ) {
F_116 () ;
return;
}
F_118 () ;
}
static T_1 void F_123 ( void )
{
T_2 V_188 , V_189 = V_185 ;
V_122 = 0 ;
V_185 = V_186 ;
if ( V_189 != V_187 )
return;
V_188 = F_124 () ;
if ( V_188 >= 255 )
F_125 ( L_47 , V_188 ) ;
F_116 () ;
F_126 ( V_190 ) ;
}
static T_1 void F_127 ( void )
{
if ( V_185 != V_191 )
return;
V_122 = 1 ;
V_185 = V_187 ;
F_118 () ;
}
static T_1 void F_128 ( int V_192 )
{
if ( V_185 == V_186 )
return;
if ( V_192 != V_193 ) {
if ( V_194 > 255 ||
! F_129 () ) {
F_17 ( L_48 ) ;
F_123 () ;
return;
}
V_195 = 1 ;
}
F_127 () ;
}
void T_1 F_130 ( void )
{
if ( F_120 () ) {
F_17 ( L_49 ) ;
V_122 = 1 ;
V_185 = V_187 ;
} else if ( ! F_33 ( V_184 ) ) {
V_185 = V_186 ;
}
}
static int T_1 F_131 ( void )
{
if ( ! F_132 () )
return 0 ;
F_125 ( L_50 ) ;
}
static inline void F_128 ( int V_192 ) { }
static inline void F_118 ( void ) { }
static int T_1 F_133 ( void )
{
#ifdef F_134
if ( ! F_120 () && V_196 ) {
F_17 ( L_51 ) ;
return - 1 ;
}
#endif
return F_135 () ;
}
void T_1 F_136 ( void )
{
unsigned long V_21 ;
int V_197 , V_198 ;
if ( V_196 )
return;
V_198 = F_137 () ;
if ( V_198 < 0 && ! F_138 () )
return;
V_197 = F_139 () ;
if ( V_197 ) {
F_17 ( L_52 , V_197 ) ;
return;
}
F_24 ( V_21 ) ;
V_199 -> V_200 () ;
F_140 () ;
if ( V_198 >= 0 )
V_198 = F_133 () ;
F_128 ( V_198 ) ;
if ( V_198 < 0 )
F_141 () ;
V_199 -> V_201 () ;
F_27 ( V_21 ) ;
}
static int T_1 F_142 ( void )
{
if ( ! F_33 ( V_140 ) ) {
F_17 ( L_53 ) ;
return - 1 ;
}
V_190 = V_202 ;
return 0 ;
}
static int T_1 F_143 ( void )
{
T_2 V_65 , V_137 , V_136 ;
V_65 = F_144 ( 1 ) ;
if ( ! ( V_65 & ( 1 << V_140 ) ) ) {
F_71 ( L_54 ) ;
return - 1 ;
}
F_145 ( & V_8 , V_140 ) ;
V_190 = V_202 ;
if ( V_8 . V_11 >= 6 ) {
F_95 ( V_138 , V_136 , V_137 ) ;
if ( V_136 & V_139 )
V_190 = V_136 & V_203 ;
}
F_17 ( L_55 ) ;
return 0 ;
}
int T_1 F_146 ( unsigned long V_204 )
{
T_2 V_137 , V_136 ;
if ( V_164 )
return - 1 ;
if ( V_8 . V_11 >= 6 ) {
F_95 ( V_138 , V_136 , V_137 ) ;
if ( ! ( V_136 & V_139 ) ) {
F_17 ( L_56 ) ;
V_136 &= ~ V_203 ;
V_136 |= V_139 | V_204 ;
F_96 ( V_138 , V_136 , V_137 ) ;
V_135 = 1 ;
}
}
return F_143 () ;
}
static int T_1 F_142 ( void )
{
if ( V_164 )
return - 1 ;
switch ( V_8 . V_9 ) {
case V_10 :
if ( ( V_8 . V_11 == 6 && V_8 . V_205 > 1 ) ||
( V_8 . V_11 >= 15 ) )
break;
goto V_206;
case V_147 :
if ( V_8 . V_11 == 6 || V_8 . V_11 == 15 ||
( V_8 . V_11 == 5 && F_33 ( V_140 ) ) )
break;
goto V_206;
default:
goto V_206;
}
if ( ! F_33 ( V_140 ) ) {
if ( ! V_3 ) {
F_17 ( L_57
L_58 ) ;
return - 1 ;
}
if ( F_146 ( V_202 ) )
return - 1 ;
} else {
if ( F_143 () )
return - 1 ;
}
F_114 () ;
return 0 ;
V_206:
F_17 ( L_59 ) ;
return - 1 ;
}
void T_1 F_147 ( void )
{
unsigned int V_207 ;
if ( V_122 ) {
V_208 = F_124 () ;
return;
}
if ( ! V_145 && F_142 () ) {
F_17 ( L_60 ) ;
F_16 () ;
} else {
V_123 = V_190 ;
if ( ! V_209 && ! V_145 )
F_126 ( V_123 ) ;
}
V_207 = F_124 () ;
if ( V_208 != V_207 ) {
V_208 = V_207 ;
V_210 [ V_207 ] =
F_10 ( F_11 ( V_7 ) ) ;
}
}
void T_1 F_126 ( unsigned long V_211 )
{
V_190 = V_211 ;
if ( ! V_122 ) {
F_148 ( V_212 , V_211 ) ;
F_68 ( V_104 , L_61 ,
V_213 , V_190 ) ;
}
if ( V_208 == - 1U ) {
V_208 = F_124 () ;
V_210 [ V_208 ] =
F_10 ( F_11 ( V_7 ) ) ;
}
}
static void F_149 ( T_4 V_49 )
{
T_2 V_25 ;
V_25 = F_11 ( V_173 + ( ( V_49 & ~ 0x1f ) >> 1 ) ) ;
if ( V_25 & ( 1 << ( V_49 & 0x1f ) ) )
F_110 () ;
F_21 ( V_214 ) ;
F_17 ( L_62
L_63 , V_49 , F_43 () ) ;
}
T_5 void F_150 ( struct V_117 * V_118 )
{
F_151 () ;
F_149 ( ~ V_118 -> V_215 ) ;
F_86 () ;
}
T_5 void F_152 ( struct V_117 * V_118 )
{
T_4 V_49 = ~ V_118 -> V_215 ;
F_151 () ;
F_153 ( V_49 ) ;
F_149 ( V_49 ) ;
F_154 ( V_49 ) ;
F_86 () ;
}
static void F_155 ( struct V_117 * V_118 )
{
T_2 V_25 ;
T_2 V_158 = 0 ;
static const char * const V_216 [] = {
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
F_25 ( V_131 , 0 ) ;
V_25 = F_11 ( V_131 ) ;
F_110 () ;
F_156 ( & V_217 ) ;
F_68 ( V_141 , V_37 L_72 ,
F_43 () , V_25 ) ;
V_25 &= 0xff ;
while ( V_25 ) {
if ( V_25 & 0x1 )
F_68 ( V_141 , V_218 L_73 , V_216 [ V_158 ] ) ;
V_158 ++ ;
V_25 >>= 1 ;
}
F_68 ( V_141 , V_218 L_74 ) ;
}
T_5 void F_157 ( struct V_117 * V_118 )
{
F_151 () ;
F_155 ( V_118 ) ;
F_86 () ;
}
T_5 void F_158 ( struct V_117 * V_118 )
{
F_151 () ;
F_159 ( V_124 ) ;
F_155 ( V_118 ) ;
F_160 ( V_124 ) ;
F_86 () ;
}
static void T_1 F_161 ( void )
{
#ifdef V_2
if ( V_175 ) {
F_91 () ;
F_68 ( V_104 , L_75
L_76 ) ;
F_1 () ;
}
#endif
}
void F_162 ( int V_219 )
{
unsigned int V_132 ;
#ifdef V_2
if ( V_175 ) {
F_68 ( V_104 , L_77
L_78 ) ;
F_3 () ;
return;
}
#endif
V_132 = F_11 ( V_133 ) ;
V_132 &= ~ V_146 ;
V_132 |= V_134 ;
V_132 |= 0xf ;
F_25 ( V_133 , V_132 ) ;
if ( ! V_219 ) {
V_132 = F_11 ( V_126 ) ;
V_132 &= ~ ( V_220 | V_221 |
V_222 | V_223 |
V_152 | V_35 ) ;
V_132 |= V_223 | V_221 ;
V_132 = F_163 ( V_132 , V_224 ) ;
F_25 ( V_126 , V_132 ) ;
} else {
F_25 ( V_126 , V_35 ) ;
}
V_132 = F_11 ( V_127 ) ;
V_132 &= ~ ( V_220 | V_221 |
V_222 | V_223 |
V_152 | V_35 ) ;
V_132 |= V_223 | V_221 ;
V_132 = F_163 ( V_132 , V_225 ) ;
F_25 ( V_127 , V_132 ) ;
}
int F_164 ( int V_182 , int V_226 )
{
int V_115 , V_227 = V_228 ;
bool V_229 = F_165 ( V_208 ,
V_230 ) ;
if ( V_231 != V_168 &&
V_231 != F_124 () &&
V_231 == V_182 ) {
int V_232 = V_233 + V_234 ;
F_71 ( L_79
L_80 ,
V_232 , V_182 ) ;
V_234 ++ ;
return - V_235 ;
}
if ( ! V_229 && V_233 >= V_228 - 1 &&
V_182 != V_208 ) {
int V_232 = V_227 + V_234 - 1 ;
F_71 (
L_81
L_82
L_83 , V_227 , V_232 , V_182 ) ;
V_234 ++ ;
return - V_235 ;
}
if ( V_233 >= V_228 ) {
int V_232 = V_227 + V_234 ;
F_71 (
L_84
L_83 , V_227 , V_232 , V_182 ) ;
V_234 ++ ;
return - V_57 ;
}
if ( V_182 == V_208 ) {
V_115 = 0 ;
} else
V_115 = F_166 ( - 1 , V_236 ) ;
if ( F_167 ( V_182 , V_115 ) < 0 ) {
int V_232 = V_227 + V_234 ;
F_71 ( L_85 ,
V_232 , V_182 ) ;
V_234 ++ ;
return - V_237 ;
}
V_233 ++ ;
if ( V_226 == 0x0 ) {
F_71 ( L_86 ,
V_115 , V_182 ) ;
V_226 = 0x10 ;
}
V_210 [ V_182 ] = V_226 ;
if ( V_226 != V_210 [ V_208 ] ) {
F_71 ( L_87 ,
V_210 [ V_208 ] , V_115 , V_226 ) ;
}
F_168 ( V_182 , V_230 ) ;
if ( V_182 > V_194 )
V_194 = V_182 ;
#if F_169 ( F_53 ) || F_169 ( F_13 )
F_107 ( V_238 , V_115 ) = V_182 ;
F_107 ( V_239 , V_115 ) = V_182 ;
#endif
#ifdef V_2
F_107 ( V_167 , V_115 ) =
V_12 -> V_240 ( V_115 ) ;
#endif
F_170 ( V_115 , true ) ;
F_171 ( V_115 , true ) ;
return V_115 ;
}
int F_172 ( void )
{
return F_124 () ;
}
void F_173 ( void )
{
unsigned long V_241 ;
F_25 ( V_242 , V_243 ) ;
V_241 = F_11 ( V_244 ) & ~ V_245 ;
V_241 |= F_174 ( 1UL << F_43 () ) ;
F_25 ( V_244 , V_241 ) ;
}
int F_175 ( const struct V_68 * V_68 ,
const struct V_68 * V_246 ,
unsigned int * V_182 )
{
unsigned int V_115 ;
F_176 (cpu, cpumask, andmask) {
if ( F_177 ( V_115 , V_247 ) )
break;
}
if ( F_178 ( V_115 < V_228 ) ) {
* V_182 = F_82 ( V_238 , V_115 ) ;
return 0 ;
}
return - V_57 ;
}
void T_1 F_179 ( void (* F_180)( T_2 V_54 , T_2 V_25 ) )
{
struct V_12 * * V_248 ;
for ( V_248 = V_249 ; V_248 < V_250 ; V_248 ++ ) {
F_108 ( ( * V_248 ) -> F_180 == F_180 ) ;
( * V_248 ) -> F_180 = F_180 ;
}
}
static void T_1 F_181 ( void )
{
#ifdef F_13
F_25 ( V_183 , F_182 ( V_208 ) ) ;
#else
# ifdef F_183
V_208 = F_124 () ;
# endif
#endif
F_184 ( V_208 , & V_230 ) ;
}
int T_1 F_185 ( bool V_251 )
{
int V_20 ;
F_161 () ;
if ( V_251 )
F_181 () ;
F_103 () ;
if ( V_122 )
V_20 = F_11 ( V_244 ) ;
else
V_20 = F_186 ( F_11 ( V_244 ) ) ;
F_187 () ;
F_113 () ;
F_188 () ;
F_189 () ;
V_252 . V_253 . V_254 () ;
return V_20 ;
}
int T_1 F_190 ( void )
{
if ( V_164 ) {
F_17 ( L_88 ) ;
return - 1 ;
}
#ifdef F_13
if ( ! F_33 ( V_140 ) ) {
V_164 = 1 ;
F_17 ( L_89 ) ;
return - 1 ;
}
#else
if ( ! V_145 && ! F_33 ( V_140 ) )
return - 1 ;
if ( ! F_33 ( V_140 ) &&
F_14 ( V_210 [ V_208 ] ) ) {
F_42 ( L_90 ,
V_208 ) ;
return - 1 ;
}
#endif
if ( ! V_145 )
F_104 () ;
F_191 () ;
F_185 ( true ) ;
return 0 ;
}
void T_1 F_192 ( void )
{
F_190 () ;
}
static int F_193 ( void )
{
unsigned long V_21 ;
int V_121 ;
if ( ! V_255 . V_256 )
return 0 ;
V_121 = F_30 () ;
V_255 . V_257 = F_11 ( V_183 ) ;
V_255 . V_258 = F_11 ( V_169 ) ;
V_255 . V_259 = F_11 ( V_244 ) ;
V_255 . V_260 = F_11 ( V_242 ) ;
V_255 . V_261 = F_11 ( V_133 ) ;
V_255 . V_262 = F_11 ( V_36 ) ;
if ( V_121 >= 4 )
V_255 . V_263 = F_11 ( V_128 ) ;
V_255 . V_264 = F_11 ( V_126 ) ;
V_255 . V_265 = F_11 ( V_127 ) ;
V_255 . V_266 = F_11 ( V_125 ) ;
V_255 . V_267 = F_11 ( V_42 ) ;
V_255 . V_268 = F_11 ( V_38 ) ;
#ifdef F_92
if ( V_121 >= 5 )
V_255 . V_269 = F_11 ( V_129 ) ;
#endif
#ifdef F_93
if ( V_121 >= 6 )
V_255 . V_270 = F_11 ( V_130 ) ;
#endif
F_24 ( V_21 ) ;
F_94 () ;
F_194 () ;
F_27 ( V_21 ) ;
return 0 ;
}
static void F_195 ( void )
{
unsigned int V_136 , V_137 ;
unsigned long V_21 ;
int V_121 ;
if ( ! V_255 . V_256 )
return;
F_24 ( V_21 ) ;
F_140 () ;
V_199 -> V_200 () ;
if ( V_122 ) {
F_118 () ;
} else {
if ( V_8 . V_11 >= 6 ) {
F_95 ( V_138 , V_136 , V_137 ) ;
V_136 &= ~ V_203 ;
V_136 |= V_139 | V_190 ;
F_96 ( V_138 , V_136 , V_137 ) ;
}
}
V_121 = F_30 () ;
F_25 ( V_125 , V_124 | V_35 ) ;
F_25 ( V_183 , V_255 . V_257 ) ;
F_25 ( V_242 , V_255 . V_260 ) ;
F_25 ( V_244 , V_255 . V_259 ) ;
F_25 ( V_169 , V_255 . V_258 ) ;
F_25 ( V_133 , V_255 . V_261 ) ;
F_25 ( V_126 , V_255 . V_264 ) ;
F_25 ( V_127 , V_255 . V_265 ) ;
#ifdef F_92
if ( V_121 >= 5 )
F_25 ( V_129 , V_255 . V_269 ) ;
#endif
#ifdef F_93
if ( V_121 >= 6 )
F_25 ( V_130 , V_255 . V_270 ) ;
#endif
if ( V_121 >= 4 )
F_25 ( V_128 , V_255 . V_263 ) ;
F_25 ( V_36 , V_255 . V_262 ) ;
F_25 ( V_38 , V_255 . V_268 ) ;
F_25 ( V_42 , V_255 . V_267 ) ;
F_25 ( V_131 , 0 ) ;
F_11 ( V_131 ) ;
F_25 ( V_125 , V_255 . V_266 ) ;
F_25 ( V_131 , 0 ) ;
F_11 ( V_131 ) ;
F_196 ( V_122 ) ;
F_27 ( V_21 ) ;
}
static void F_114 ( void )
{
V_255 . V_256 = 1 ;
}
static int T_1 F_197 ( void )
{
if ( F_33 ( V_140 ) )
F_198 ( & V_271 ) ;
return 0 ;
}
static void F_114 ( void ) { }
static int F_199 ( const struct V_272 * V_273 )
{
if ( V_274 )
return 0 ;
F_17 ( L_91 , V_273 -> V_275 ) ;
V_274 = 1 ;
return 0 ;
}
static void F_200 ( void )
{
if ( V_276 )
return;
F_201 ( V_277 ) ;
V_276 = 1 ;
}
int F_202 ( void )
{
F_200 () ;
return V_274 ;
}
static int T_1 F_203 ( char * V_1 )
{
V_164 = 1 ;
F_6 ( V_140 ) ;
return 0 ;
}
static int T_1 F_204 ( char * V_1 )
{
return F_203 ( V_1 ) ;
}
static int T_1 F_205 ( char * V_1 )
{
V_278 = 1 ;
return 0 ;
}
static int T_1 F_206 ( char * V_1 )
{
V_114 = 1 ;
return 0 ;
}
static int T_1 F_207 ( char * V_1 )
{
V_114 = 1 ;
return 0 ;
}
static int T_1 F_208 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_13
V_196 = 0 ;
return 0 ;
#endif
return - V_57 ;
}
if ( strcmp ( L_92 , V_1 ) == 0 )
V_279 = V_141 ;
else if ( strcmp ( L_93 , V_1 ) == 0 )
V_279 = V_104 ;
else {
F_71 ( L_94
L_95 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_1 F_209 ( void )
{
if ( ! V_123 )
return - 1 ;
V_280 . V_281 = V_123 ;
V_280 . V_282 = V_280 . V_281 + V_283 - 1 ;
F_210 ( & V_284 , & V_280 ) ;
return 0 ;
}
static int T_1 F_211 ( char * V_1 )
{
if ( ! V_1 || ! F_212 ( & V_1 , & V_231 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_213 ( char * V_1 )
{
if ( ! V_1 )
return - V_57 ;
if ( ! strncmp ( L_96 , V_1 , 3 ) )
V_153 = V_176 ;
else if ( ! strncmp ( L_97 , V_1 , 4 ) )
V_153 = V_154 ;
else if ( ! strncmp ( L_98 , V_1 , 3 ) )
V_153 = V_285 ;
else {
F_214 ( L_99 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
