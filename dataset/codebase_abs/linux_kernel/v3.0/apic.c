static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static inline void F_2 ( void )
{
F_3 ( 0x70 , 0x22 ) ;
F_3 ( 0x01 , 0x23 ) ;
}
static inline void F_4 ( void )
{
F_3 ( 0x70 , 0x22 ) ;
F_3 ( 0x00 , 0x23 ) ;
}
static T_1 int F_5 ( char * V_3 )
{
V_4 = 1 ;
F_6 ( NULL ) ;
return 0 ;
}
static T_1 int F_7 ( char * V_5 )
{
if ( F_8 () ) {
F_9 ( L_1
L_2 ) ;
return 0 ;
}
F_10 ( V_6 ) ;
return 0 ;
}
static inline int F_11 ( void )
{
return F_12 ( F_13 ( V_7 ) ) ;
}
static inline int F_14 ( void )
{
#ifdef F_15
return 1 ;
#else
return F_16 ( F_11 () ) ;
#endif
}
static int F_17 ( void )
{
if ( V_8 . V_9 == V_10 &&
V_8 . V_11 >= 0xf )
return 1 ;
return F_11 () >= 0x14 ;
}
static void T_1 F_18 ( void )
{
F_19 ( L_3 ) ;
V_12 = & V_13 ;
}
void F_20 ( void )
{
while ( F_13 ( V_14 ) & V_15 )
F_21 () ;
}
T_2 F_22 ( void )
{
T_2 V_16 ;
int V_17 ;
V_17 = 0 ;
do {
V_16 = F_13 ( V_14 ) & V_15 ;
if ( ! V_16 )
break;
F_23 ( 100 ) ;
} while ( V_17 ++ < 1000 );
return V_16 ;
}
void F_24 ( T_2 V_18 , T_2 V_19 )
{
F_25 ( V_20 , F_26 ( V_19 ) ) ;
F_25 ( V_14 , V_18 ) ;
}
T_3 F_27 ( void )
{
T_2 V_21 , V_22 ;
V_22 = F_13 ( V_20 ) ;
V_21 = F_13 ( V_14 ) ;
return V_21 | ( ( T_3 ) V_22 << 32 ) ;
}
int F_28 ( void )
{
return F_17 () ? 0xff : 0xf ;
}
int F_29 ( void )
{
unsigned int V_23 ;
V_23 = F_13 ( V_7 ) ;
return F_16 ( F_12 ( V_23 ) ) ? F_30 ( V_23 ) : 2 ;
}
static void F_31 ( unsigned int V_24 , int V_25 , int V_26 )
{
unsigned int V_27 , V_28 ;
V_27 = V_29 ;
if ( ! V_25 )
V_27 |= V_30 ;
if ( ! F_14 () )
V_27 |= F_32 ( V_31 ) ;
if ( ! V_26 )
V_27 |= V_32 ;
F_25 ( V_33 , V_27 ) ;
V_28 = F_13 ( V_34 ) ;
F_25 ( V_34 ,
( V_28 & ~ ( V_35 | V_36 ) ) |
V_37 ) ;
if ( ! V_25 )
F_25 ( V_38 , V_24 / V_39 ) ;
}
static inline int F_33 ( unsigned int V_40 , unsigned int V_41 )
{
return ( V_40 & V_42 )
|| ( V_41 == V_42 )
|| ( ( V_41 & ~ V_42 ) == V_40 ) ;
}
static unsigned int F_34 ( int V_43 , unsigned int V_41 )
{
unsigned int V_44 ;
if ( V_43 >= V_45 )
return ~ 0 ;
V_44 = F_35 ( & V_46 [ V_43 ] ) & ~ V_42 ;
do {
if ( V_44 &&
! F_33 ( V_44 , V_41 ) )
return V_44 ;
V_44 = F_36 ( & V_46 [ V_43 ] , V_44 , V_41 ) ;
} while ( V_44 != V_41 );
return V_41 ;
}
int F_37 ( T_4 V_43 , T_4 V_47 , T_4 V_48 , T_4 V_49 )
{
unsigned long V_50 = F_38 ( V_43 ) ;
unsigned int V_41 , V_40 , V_51 ;
V_41 = ( V_49 << 16 ) | ( V_48 << 8 ) | V_47 ;
V_40 = F_13 ( V_50 ) ;
V_51 = F_34 ( V_43 , V_41 ) ;
if ( V_51 != V_41 ) {
F_39 ( V_52 L_4
L_5
L_6 ,
F_40 () , V_50 , V_43 , V_41 , V_51 ) ;
return - V_53 ;
}
if ( ! F_33 ( V_40 , V_41 ) ) {
F_39 ( V_52 L_4
L_5
L_7 ,
F_40 () , V_50 , V_43 , V_41 , V_40 ) ;
return - V_54 ;
}
F_25 ( V_50 , V_41 ) ;
return 0 ;
}
static int F_41 ( unsigned long V_55 ,
struct V_56 * V_57 )
{
F_25 ( V_38 , V_55 ) ;
return 0 ;
}
static void F_42 ( enum V_58 V_59 ,
struct V_56 * V_57 )
{
unsigned long V_60 ;
unsigned int V_23 ;
if ( V_57 -> V_61 & V_62 )
return;
F_43 ( V_60 ) ;
switch ( V_59 ) {
case V_63 :
case V_64 :
F_31 ( V_65 ,
V_59 != V_63 , 1 ) ;
break;
case V_66 :
case V_67 :
V_23 = F_13 ( V_33 ) ;
V_23 |= ( V_32 | V_29 ) ;
F_25 ( V_33 , V_23 ) ;
F_25 ( V_38 , 0 ) ;
break;
case V_68 :
break;
}
F_44 ( V_60 ) ;
}
static void F_45 ( const struct V_69 * V_49 )
{
#ifdef F_46
V_12 -> V_70 ( V_49 , V_29 ) ;
#endif
}
static void T_5 F_47 ( void )
{
struct V_56 * V_71 = & F_48 ( V_72 ) ;
if ( F_49 ( V_73 ) ) {
V_74 . V_61 &= ~ V_75 ;
V_74 . V_76 = 150 ;
}
memcpy ( V_71 , & V_74 , sizeof( * V_71 ) ) ;
V_71 -> V_69 = F_50 ( F_40 () ) ;
F_51 ( V_71 ) ;
}
static void T_1 F_52 ( struct V_56 * V_77 )
{
unsigned long long V_78 = 0 ;
long V_79 = F_13 ( V_80 ) ;
unsigned long V_81 = F_53 () ;
if ( V_82 )
F_54 ( V_78 ) ;
switch ( V_83 ++ ) {
case 0 :
V_84 = V_79 ;
V_85 = V_78 ;
V_86 = V_81 ;
V_87 = V_88 ;
break;
case V_89 :
V_90 = V_79 ;
V_91 = V_78 ;
if ( V_81 < V_86 )
V_81 += V_92 ;
V_93 = V_81 ;
V_94 = V_88 ;
break;
}
}
static int T_1
F_55 ( long V_95 , long * V_55 , long * V_96 )
{
const long V_97 = V_98 / 10 ;
const long V_99 = V_97 / 100 ;
unsigned long V_100 ;
T_3 V_101 ;
#ifndef F_56
return - 1 ;
#endif
F_57 ( V_102 , L_8 , V_95 ) ;
if ( ! V_95 )
return - 1 ;
V_100 = F_58 ( V_98 , 22 ) ;
if ( V_95 > ( V_97 - V_99 ) &&
V_95 < ( V_97 + V_99 ) ) {
F_57 ( V_102 , L_9 ) ;
return 0 ;
}
V_101 = ( ( ( T_3 ) V_95 ) * V_100 ) >> 22 ;
F_59 ( V_101 , 1000000 ) ;
F_9 ( L_10
L_11 , ( long ) V_101 ) ;
V_101 = ( ( ( T_3 ) ( * V_55 ) ) * V_97 ) ;
F_59 ( V_101 , V_95 ) ;
F_19 ( L_12
L_13 , ( unsigned long ) V_101 , * V_55 ) ;
* V_55 = ( long ) V_101 ;
if ( V_82 ) {
V_101 = ( ( ( T_3 ) ( * V_96 ) ) * V_97 ) ;
F_59 ( V_101 , V_95 ) ;
F_57 ( V_102 , L_14
L_15 ,
( unsigned long ) V_101 , * V_96 ) ;
* V_96 = ( long ) V_101 ;
}
return 0 ;
}
static int T_1 F_60 ( void )
{
struct V_56 * V_71 = & F_48 ( V_72 ) ;
void (* F_61)( struct V_56 * V_77 );
unsigned long V_103 ;
long V_55 , V_96 ;
int V_104 = 0 ;
F_62 () ;
F_61 = V_105 -> V_106 ;
V_105 -> V_106 = F_52 ;
F_31 ( 0xffffffff , 0 , 0 ) ;
F_63 () ;
while ( V_83 <= V_89 )
F_21 () ;
F_62 () ;
V_105 -> V_106 = F_61 ;
V_55 = V_84 - V_90 ;
F_57 ( V_102 , L_16 , V_55 ) ;
V_96 = ( long ) ( V_91 - V_85 ) ;
V_104 = ! F_55 ( V_93 - V_86 ,
& V_55 , & V_96 ) ;
V_74 . V_100 = F_64 ( V_55 , V_107 * V_89 ,
V_74 . V_108 ) ;
V_74 . V_109 =
F_65 ( 0x7FFFFFFF , & V_74 ) ;
V_74 . V_110 =
F_65 ( 0xF , & V_74 ) ;
V_65 = ( V_55 * V_39 ) / V_89 ;
F_57 ( V_102 , L_17 , V_55 ) ;
F_57 ( V_102 , L_18 , V_74 . V_100 ) ;
F_57 ( V_102 , L_19 ,
V_65 ) ;
if ( V_82 ) {
F_57 ( V_102 , L_20
L_21 ,
( V_96 / V_89 ) / ( 1000000 / V_111 ) ,
( V_96 / V_89 ) % ( 1000000 / V_111 ) ) ;
}
F_57 ( V_102 , L_22
L_23 ,
V_65 / ( 1000000 / V_111 ) ,
V_65 % ( 1000000 / V_111 ) ) ;
if ( V_65 < ( 1000000 / V_111 ) ) {
F_63 () ;
F_9 ( L_24 ) ;
return - 1 ;
}
V_71 -> V_61 &= ~ V_62 ;
if ( ! V_104 ) {
F_57 ( V_102 , L_25 ) ;
V_71 -> V_106 = F_52 ;
F_42 ( V_63 , V_71 ) ;
V_83 = - 1 ;
F_63 () ;
while ( V_83 <= V_89 )
F_21 () ;
F_42 ( V_67 , V_71 ) ;
V_103 = V_94 - V_87 ;
F_57 ( V_102 , L_26 , V_103 ) ;
if ( V_103 >= V_89 - 2 && V_103 <= V_89 + 2 )
F_57 ( V_102 , L_27 ) ;
else
V_71 -> V_61 |= V_62 ;
} else
F_63 () ;
if ( V_71 -> V_61 & V_62 ) {
F_9 ( L_28 ) ;
return - 1 ;
}
return 0 ;
}
void T_1 F_66 ( void )
{
if ( V_112 ) {
F_19 ( L_29 ) ;
if ( F_67 () > 1 ) {
V_74 . V_100 = 1 ;
F_47 () ;
}
return;
}
F_57 ( V_102 , L_30
L_31 ) ;
if ( F_60 () ) {
if ( F_67 () > 1 )
F_47 () ;
return;
}
V_74 . V_61 &= ~ V_62 ;
F_47 () ;
}
void T_5 F_68 ( void )
{
F_47 () ;
}
static void F_69 ( void )
{
int V_113 = F_40 () ;
struct V_56 * V_57 = & F_70 ( V_72 , V_113 ) ;
if ( ! V_57 -> V_106 ) {
F_9 ( L_32 , V_113 ) ;
F_42 ( V_67 , V_57 ) ;
return;
}
F_71 ( V_114 ) ;
V_57 -> V_106 ( V_57 ) ;
}
void T_6 F_72 ( struct V_115 * V_116 )
{
struct V_115 * V_117 = F_73 ( V_116 ) ;
F_74 () ;
F_75 () ;
F_76 () ;
F_69 () ;
F_77 () ;
F_73 ( V_117 ) ;
}
int F_78 ( unsigned int V_118 )
{
return - V_53 ;
}
void F_79 ( void )
{
int V_119 ;
T_2 V_23 ;
if ( ! V_120 && ! V_121 )
return;
V_119 = F_29 () ;
if ( V_119 >= 3 ) {
V_23 = V_122 ;
F_25 ( V_123 , V_23 | V_32 ) ;
}
V_23 = F_13 ( V_33 ) ;
F_25 ( V_33 , V_23 | V_32 ) ;
V_23 = F_13 ( V_124 ) ;
F_25 ( V_124 , V_23 | V_32 ) ;
V_23 = F_13 ( V_125 ) ;
F_25 ( V_125 , V_23 | V_32 ) ;
if ( V_119 >= 4 ) {
V_23 = F_13 ( V_126 ) ;
F_25 ( V_126 , V_23 | V_32 ) ;
}
#ifdef F_80
if ( V_119 >= 5 ) {
V_23 = F_13 ( V_127 ) ;
F_25 ( V_127 , V_23 | V_32 ) ;
}
#endif
#ifdef F_81
if ( V_119 >= 6 ) {
V_23 = F_13 ( V_128 ) ;
if ( ! ( V_23 & V_32 ) )
F_25 ( V_128 , V_23 | V_32 ) ;
}
#endif
F_25 ( V_33 , V_32 ) ;
F_25 ( V_124 , V_32 ) ;
F_25 ( V_125 , V_32 ) ;
if ( V_119 >= 3 )
F_25 ( V_123 , V_32 ) ;
if ( V_119 >= 4 )
F_25 ( V_126 , V_32 ) ;
if ( F_14 () ) {
if ( V_119 > 3 )
F_25 ( V_129 , 0 ) ;
F_13 ( V_129 ) ;
}
}
void F_82 ( void )
{
unsigned int V_130 ;
if ( ! V_120 && ! V_121 )
return;
F_79 () ;
V_130 = F_13 ( V_131 ) ;
V_130 &= ~ V_132 ;
F_25 ( V_131 , V_130 ) ;
#ifdef F_83
if ( V_133 ) {
unsigned int V_134 , V_135 ;
F_84 ( V_136 , V_134 , V_135 ) ;
V_134 &= ~ V_137 ;
F_85 ( V_136 , V_134 , V_135 ) ;
}
#endif
}
void F_86 ( void )
{
unsigned long V_60 ;
if ( ! V_138 && ! F_87 () )
return;
F_43 ( V_60 ) ;
#ifdef F_83
if ( ! V_133 )
F_79 () ;
else
#endif
F_82 () ;
F_44 ( V_60 ) ;
}
int T_1 F_88 ( void )
{
unsigned int V_139 , V_140 ;
V_139 = F_13 ( V_7 ) ;
F_57 ( V_141 , L_33 , V_139 ) ;
F_25 ( V_7 , V_139 ^ V_142 ) ;
V_140 = F_13 ( V_7 ) ;
F_57 ( V_141 , L_33 , V_140 ) ;
if ( V_140 != V_139 )
return 0 ;
V_140 = F_12 ( V_139 ) ;
if ( V_140 == 0x00 || V_140 == 0xff )
return 0 ;
V_140 = F_29 () ;
if ( V_140 < 0x02 || V_140 == 0xff )
return 0 ;
V_139 = F_13 ( V_143 ) ;
F_57 ( V_141 , L_34 , V_139 ) ;
F_25 ( V_143 , V_139 ^ V_12 -> V_144 ) ;
V_140 = F_13 ( V_143 ) ;
F_57 ( V_141 , L_34 , V_140 ) ;
F_25 ( V_143 , V_139 ) ;
if ( V_140 != ( V_139 ^ V_12 -> V_144 ) )
return 0 ;
V_139 = F_13 ( V_124 ) ;
F_57 ( V_141 , L_35 , V_139 ) ;
V_140 = F_13 ( V_125 ) ;
F_57 ( V_141 , L_36 , V_140 ) ;
return 1 ;
}
void T_1 F_89 ( void )
{
if ( F_17 () || V_8 . V_9 == V_10 )
return;
F_90 () ;
F_57 ( V_141 , L_37 ) ;
F_25 ( V_14 , V_145 |
V_146 | V_147 ) ;
}
void T_1 F_91 ( void )
{
unsigned int V_130 ;
if ( V_148 || ! V_138 )
return;
F_79 () ;
V_130 = F_13 ( V_131 ) ;
V_130 &= ~ V_149 ;
V_130 |= V_132 ;
#ifdef F_83
if ( ( V_8 . V_9 == V_150 ) &&
( V_8 . V_11 == 15 ) )
V_130 &= ~ V_151 ;
else
#endif
V_130 |= V_151 ;
V_130 |= V_152 ;
F_25 ( V_131 , V_130 ) ;
F_25 ( V_124 , V_153 ) ;
V_130 = V_154 ;
if ( ! F_14 () )
V_130 |= V_155 ;
F_25 ( V_125 , V_130 ) ;
}
static void T_5 F_92 ( void )
{
unsigned int V_156 , V_130 , V_119 ;
if ( ! F_14 () ) {
F_19 ( L_38 ) ;
return;
}
if ( V_12 -> V_157 ) {
F_19 ( L_39 ) ;
return;
}
V_119 = F_29 () ;
if ( V_119 > 3 )
F_25 ( V_129 , 0 ) ;
V_156 = F_13 ( V_129 ) ;
V_130 = V_122 ;
F_25 ( V_123 , V_130 ) ;
if ( V_119 > 3 )
F_25 ( V_129 , 0 ) ;
V_130 = F_13 ( V_129 ) ;
if ( V_130 != V_156 )
F_57 ( V_102 , L_40
L_41 ,
V_156 , V_130 ) ;
}
void T_5 F_93 ( void )
{
int V_113 = F_40 () ;
unsigned int V_130 , V_158 ;
int V_159 , V_160 , V_161 = 0 ;
unsigned long long V_78 = 0 , V_162 ;
long long V_163 = V_164 ;
if ( V_82 )
F_54 ( V_78 ) ;
if ( V_165 ) {
F_94 () ;
return;
}
#ifdef F_83
if ( F_14 () && V_12 -> V_157 ) {
F_25 ( V_129 , 0 ) ;
F_25 ( V_129 , 0 ) ;
F_25 ( V_129 , 0 ) ;
F_25 ( V_129 , 0 ) ;
}
#endif
F_95 () ;
F_96 ( ! V_12 -> V_166 () ) ;
V_12 -> V_167 () ;
#ifdef F_83
V_159 = F_97 ( V_168 , V_113 ) ;
F_98 ( V_159 != V_169 && V_159 != F_99 () ) ;
F_97 ( V_168 , V_113 ) =
F_99 () ;
if ( V_12 -> V_170 )
F_100 ( F_97 ( V_171 , V_113 ) ,
V_12 -> V_170 ( V_113 ) ) ;
#endif
V_130 = F_13 ( V_172 ) ;
V_130 &= ~ V_173 ;
F_25 ( V_172 , V_130 ) ;
do {
V_158 = 0 ;
for ( V_159 = V_174 - 1 ; V_159 >= 0 ; V_159 -- )
V_158 |= F_13 ( V_175 + V_159 * 0x10 ) ;
for ( V_159 = V_174 - 1 ; V_159 >= 0 ; V_159 -- ) {
V_130 = F_13 ( V_176 + V_159 * 0x10 ) ;
for ( V_160 = 31 ; V_160 >= 0 ; V_160 -- ) {
if ( V_130 & ( 1 << V_160 ) ) {
F_74 () ;
V_161 ++ ;
}
}
}
if ( V_161 > 256 ) {
F_101 ( V_177 L_42 ,
V_161 ) ;
break;
}
if ( V_82 ) {
F_54 ( V_162 ) ;
V_163 = ( V_164 << 10 ) - ( V_162 - V_78 ) ;
} else
V_163 -- ;
} while ( V_158 && V_163 > 0 );
F_98 ( V_163 <= 0 ) ;
V_130 = F_13 ( V_131 ) ;
V_130 &= ~ V_149 ;
V_130 |= V_132 ;
#ifdef F_83
V_130 &= ~ V_151 ;
#endif
V_130 |= V_152 ;
F_25 ( V_131 , V_130 ) ;
V_130 = F_13 ( V_124 ) & V_32 ;
if ( ! V_113 && ( V_178 || ! V_130 ) ) {
V_130 = V_153 ;
F_57 ( V_102 , L_43 , V_113 ) ;
} else {
V_130 = V_153 | V_32 ;
F_57 ( V_102 , L_44 , V_113 ) ;
}
F_25 ( V_124 , V_130 ) ;
if ( ! V_113 )
V_130 = V_154 ;
else
V_130 = V_154 | V_32 ;
if ( ! F_14 () )
V_130 |= V_155 ;
F_25 ( V_125 , V_130 ) ;
#ifdef F_81
if ( ! V_113 )
F_102 () ;
#endif
}
void T_5 F_103 ( void )
{
F_92 () ;
#ifdef F_83
{
unsigned int V_130 ;
V_130 = F_13 ( V_33 ) ;
V_130 |= ( V_32 | V_29 ) ;
F_25 ( V_33 , V_130 ) ;
}
#endif
F_104 () ;
}
void T_1 F_105 ( void )
{
F_103 () ;
if ( V_179 )
F_106 () ;
}
void F_107 ( void )
{
if ( F_8 () ) {
F_19 ( L_45 ) ;
V_180 = V_120 = 1 ;
}
}
void F_108 ( void )
{
int V_181 , V_182 ;
if ( ! V_120 )
return;
F_84 ( V_136 , V_181 , V_182 ) ;
if ( ! ( V_181 & V_183 ) ) {
F_109 ( V_184 L_46 ) ;
F_85 ( V_136 , V_181 | V_183 , 0 ) ;
}
}
int T_1 F_110 ( void )
{
#ifdef F_111
if ( ! F_112 () ) {
F_113 ( L_47 ) ;
return 0 ;
}
if ( ! V_180 && V_185 ) {
F_19 ( L_48
L_49 ) ;
return 0 ;
}
if ( F_114 ( F_115 () ) )
return 0 ;
F_19 ( L_50 ) ;
return 1 ;
#endif
return 0 ;
}
void T_1 F_116 ( void )
{
unsigned long V_60 ;
int V_186 , F_8 = 0 ;
int V_187 ;
V_187 = F_117 () ;
if ( V_187 && ! F_115 () )
return;
V_186 = F_118 () ;
if ( V_186 ) {
F_19 ( L_51 , V_186 ) ;
goto V_188;
}
F_43 ( V_60 ) ;
V_189 -> V_190 () ;
F_119 () ;
if ( V_187 )
V_186 = 0 ;
else
V_186 = F_110 () ;
if ( ! V_186 ) {
if ( V_191 > 255 ||
! F_120 () )
goto V_192;
F_121 () ;
}
F_8 = 1 ;
if ( F_115 () && ! V_120 ) {
V_120 = 1 ;
F_108 () ;
F_19 ( L_52 ) ;
}
V_192:
if ( ! V_186 )
F_122 () ;
V_189 -> V_193 () ;
F_44 ( V_60 ) ;
V_188:
if ( F_8 )
return;
if ( V_180 )
F_123 ( L_53 ) ;
else if ( V_194 )
F_19 ( L_54 ) ;
}
static int T_1 F_124 ( void )
{
if ( ! V_138 ) {
F_19 ( L_55 ) ;
return - 1 ;
}
V_195 = V_196 ;
return 0 ;
}
static int T_1 F_125 ( void )
{
T_2 V_61 , V_135 , V_134 ;
V_61 = F_126 ( 1 ) ;
if ( ! ( V_61 & ( 1 << V_197 ) ) ) {
F_9 ( L_56 ) ;
return - 1 ;
}
F_127 ( & V_8 , V_197 ) ;
V_195 = V_196 ;
F_84 ( V_136 , V_134 , V_135 ) ;
if ( V_134 & V_137 )
V_195 = V_134 & V_198 ;
F_19 ( L_57 ) ;
return 0 ;
}
int T_1 F_128 ( unsigned long V_199 )
{
T_2 V_135 , V_134 ;
if ( V_165 )
return - 1 ;
F_84 ( V_136 , V_134 , V_135 ) ;
if ( ! ( V_134 & V_137 ) ) {
F_19 ( L_58 ) ;
V_134 &= ~ V_198 ;
V_134 |= V_137 | V_199 ;
F_85 ( V_136 , V_134 , V_135 ) ;
V_133 = 1 ;
}
return F_125 () ;
}
static int T_1 F_124 ( void )
{
if ( V_165 )
return - 1 ;
switch ( V_8 . V_9 ) {
case V_10 :
if ( ( V_8 . V_11 == 6 && V_8 . V_200 > 1 ) ||
( V_8 . V_11 >= 15 ) )
break;
goto V_201;
case V_150 :
if ( V_8 . V_11 == 6 || V_8 . V_11 == 15 ||
( V_8 . V_11 == 5 && V_138 ) )
break;
goto V_201;
default:
goto V_201;
}
if ( ! V_138 ) {
if ( ! V_2 ) {
F_19 ( L_59
L_60 ) ;
return - 1 ;
}
if ( F_128 ( V_196 ) )
return - 1 ;
} else {
if ( F_125 () )
return - 1 ;
}
F_104 () ;
return 0 ;
V_201:
F_19 ( L_61 ) ;
return - 1 ;
}
void T_1 F_129 ( void )
{
unsigned int V_202 ;
if ( V_120 ) {
V_203 = F_130 () ;
return;
}
if ( ! V_148 && F_124 () ) {
F_19 ( L_62 ) ;
F_18 () ;
} else {
V_121 = V_195 ;
if ( ! V_204 && ! V_148 )
F_131 ( V_121 ) ;
}
V_202 = F_130 () ;
if ( V_203 != V_202 ) {
V_203 = V_202 ;
V_205 [ V_202 ] =
F_12 ( F_13 ( V_7 ) ) ;
}
}
void T_1 F_131 ( unsigned long V_206 )
{
V_195 = V_206 ;
if ( ! V_120 ) {
F_132 ( V_207 , V_206 ) ;
F_57 ( V_102 , L_63 ,
V_208 , V_195 ) ;
}
if ( V_203 == - 1U ) {
V_203 = F_130 () ;
V_205 [ V_203 ] =
F_12 ( F_13 ( V_7 ) ) ;
}
}
int T_1 F_133 ( void )
{
if ( V_165 ) {
F_19 ( L_64 ) ;
return - 1 ;
}
#ifdef F_15
if ( ! V_138 ) {
V_165 = 1 ;
F_19 ( L_65 ) ;
return - 1 ;
}
#else
if ( ! V_148 && ! V_138 )
return - 1 ;
if ( ! V_138 &&
F_16 ( V_205 [ V_203 ] ) ) {
F_39 ( L_66 ,
V_203 ) ;
return - 1 ;
}
#endif
F_134 () ;
F_88 () ;
F_135 () ;
#ifdef F_15
F_25 ( V_143 , F_136 ( V_203 ) ) ;
#else
# ifdef F_137
V_203 = F_130 () ;
# endif
#endif
F_138 ( V_203 , & V_209 ) ;
F_93 () ;
#ifdef F_139
if ( ! V_185 && V_210 )
F_140 () ;
#endif
F_105 () ;
#ifdef F_139
if ( V_148 && ! V_185 && V_210 )
F_141 () ;
else {
V_210 = 0 ;
}
#endif
V_211 . V_212 . V_213 () ;
return 0 ;
}
void F_142 ( struct V_115 * V_116 )
{
T_2 V_23 ;
F_75 () ;
F_76 () ;
V_23 = F_13 ( V_176 + ( ( V_152 & ~ 0x1f ) >> 1 ) ) ;
if ( V_23 & ( 1 << ( V_152 & 0x1f ) ) )
F_74 () ;
F_71 ( V_214 ) ;
F_19 ( L_67
L_68 , F_40 () ) ;
F_77 () ;
}
void F_143 ( struct V_115 * V_116 )
{
T_2 V_215 , V_216 ;
T_2 V_159 = 0 ;
static const char * const V_217 [] = {
L_69 ,
L_70 ,
L_71 ,
L_72 ,
L_73 ,
L_74 ,
L_75 ,
L_76 ,
} ;
F_75 () ;
F_76 () ;
V_215 = F_13 ( V_129 ) ;
F_25 ( V_129 , 0 ) ;
V_216 = F_13 ( V_129 ) ;
F_74 () ;
F_144 ( & V_218 ) ;
F_57 ( V_141 , V_219 L_77 ,
F_40 () , V_215 , V_216 ) ;
V_216 = V_216 & 0xff ;
while ( V_216 ) {
if ( V_216 & 0x1 )
F_57 ( V_141 , V_220 L_78 , V_217 [ V_159 ] ) ;
V_159 ++ ;
V_216 >>= 1 ;
} ;
F_57 ( V_141 , V_220 L_79 ) ;
F_77 () ;
}
void T_1 F_135 ( void )
{
#ifdef F_83
if ( V_178 ) {
F_79 () ;
F_57 ( V_102 , L_80
L_81 ) ;
F_2 () ;
}
#endif
if ( V_12 -> V_221 )
V_12 -> V_221 () ;
}
void F_145 ( int V_222 )
{
unsigned int V_130 ;
#ifdef F_83
if ( V_178 ) {
F_57 ( V_102 , L_82
L_83 ) ;
F_4 () ;
return;
}
#endif
V_130 = F_13 ( V_131 ) ;
V_130 &= ~ V_149 ;
V_130 |= V_132 ;
V_130 |= 0xf ;
F_25 ( V_131 , V_130 ) ;
if ( ! V_222 ) {
V_130 = F_13 ( V_124 ) ;
V_130 &= ~ ( V_223 | V_224 |
V_225 | V_226 |
V_155 | V_32 ) ;
V_130 |= V_226 | V_224 ;
V_130 = F_146 ( V_130 , V_227 ) ;
F_25 ( V_124 , V_130 ) ;
} else {
F_25 ( V_124 , V_32 ) ;
}
V_130 = F_13 ( V_125 ) ;
V_130 &= ~ ( V_223 | V_224 |
V_225 | V_226 |
V_155 | V_32 ) ;
V_130 |= V_226 | V_224 ;
V_130 = F_146 ( V_130 , V_228 ) ;
F_25 ( V_125 , V_130 ) ;
}
void T_5 F_147 ( int V_229 , int V_230 )
{
int V_113 ;
if ( V_231 >= V_232 ) {
int V_233 = V_232 ;
int V_234 = V_233 + V_235 ;
F_9 (
L_84
L_85 , V_233 , V_234 , V_229 ) ;
V_235 ++ ;
return;
}
V_231 ++ ;
if ( V_229 == V_203 ) {
V_113 = 0 ;
} else
V_113 = F_148 ( - 1 , V_236 ) ;
if ( V_230 == 0x0 ) {
F_9 ( L_86 ,
V_113 , V_229 ) ;
V_230 = 0x10 ;
}
V_205 [ V_229 ] = V_230 ;
if ( V_230 != V_205 [ V_203 ] ) {
F_9 ( L_87 ,
V_205 [ V_203 ] , V_113 , V_230 ) ;
}
F_149 ( V_229 , V_209 ) ;
if ( V_229 > V_191 )
V_191 = V_229 ;
#if F_150 ( F_46 ) || F_150 ( F_15 )
F_97 ( V_171 , V_113 ) = V_229 ;
F_97 ( V_237 , V_113 ) = V_229 ;
#endif
#ifdef F_83
F_97 ( V_168 , V_113 ) =
V_12 -> V_238 ( V_113 ) ;
#endif
F_151 ( V_113 , true ) ;
F_152 ( V_113 , true ) ;
}
int F_153 ( void )
{
return F_130 () ;
}
void F_154 ( void )
{
unsigned long V_239 ;
F_25 ( V_240 , V_241 ) ;
V_239 = F_13 ( V_242 ) & ~ V_243 ;
V_239 |= F_155 ( 1UL << F_40 () ) ;
F_25 ( V_242 , V_239 ) ;
}
static int F_156 ( void )
{
unsigned long V_60 ;
int V_119 ;
if ( ! V_244 . V_245 )
return 0 ;
V_119 = F_29 () ;
V_244 . V_246 = F_13 ( V_143 ) ;
V_244 . V_247 = F_13 ( V_172 ) ;
V_244 . V_248 = F_13 ( V_242 ) ;
V_244 . V_249 = F_13 ( V_240 ) ;
V_244 . V_250 = F_13 ( V_131 ) ;
V_244 . V_251 = F_13 ( V_33 ) ;
if ( V_119 >= 4 )
V_244 . V_252 = F_13 ( V_126 ) ;
V_244 . V_253 = F_13 ( V_124 ) ;
V_244 . V_254 = F_13 ( V_125 ) ;
V_244 . V_255 = F_13 ( V_123 ) ;
V_244 . V_256 = F_13 ( V_38 ) ;
V_244 . V_257 = F_13 ( V_34 ) ;
#ifdef F_80
if ( V_119 >= 5 )
V_244 . V_258 = F_13 ( V_127 ) ;
#endif
F_43 ( V_60 ) ;
F_82 () ;
if ( V_179 )
F_157 () ;
F_44 ( V_60 ) ;
return 0 ;
}
static void F_158 ( void )
{
unsigned int V_134 , V_135 ;
unsigned long V_60 ;
int V_119 ;
if ( ! V_244 . V_245 )
return;
F_43 ( V_60 ) ;
if ( V_179 ) {
F_119 () ;
V_189 -> V_190 () ;
}
if ( V_120 )
F_108 () ;
else {
F_84 ( V_136 , V_134 , V_135 ) ;
V_134 &= ~ V_198 ;
V_134 |= V_137 | V_195 ;
F_85 ( V_136 , V_134 , V_135 ) ;
}
V_119 = F_29 () ;
F_25 ( V_123 , V_122 | V_32 ) ;
F_25 ( V_143 , V_244 . V_246 ) ;
F_25 ( V_240 , V_244 . V_249 ) ;
F_25 ( V_242 , V_244 . V_248 ) ;
F_25 ( V_172 , V_244 . V_247 ) ;
F_25 ( V_131 , V_244 . V_250 ) ;
F_25 ( V_124 , V_244 . V_253 ) ;
F_25 ( V_125 , V_244 . V_254 ) ;
#if F_150 ( V_259 ) || F_150 ( F_81 )
if ( V_119 >= 5 )
F_25 ( V_127 , V_244 . V_258 ) ;
#endif
if ( V_119 >= 4 )
F_25 ( V_126 , V_244 . V_252 ) ;
F_25 ( V_33 , V_244 . V_251 ) ;
F_25 ( V_34 , V_244 . V_257 ) ;
F_25 ( V_38 , V_244 . V_256 ) ;
F_25 ( V_129 , 0 ) ;
F_13 ( V_129 ) ;
F_25 ( V_123 , V_244 . V_255 ) ;
F_25 ( V_129 , 0 ) ;
F_13 ( V_129 ) ;
if ( V_179 )
F_159 ( V_120 ) ;
F_44 ( V_60 ) ;
}
static void T_5 F_104 ( void )
{
V_244 . V_245 = 1 ;
}
static int T_1 F_160 ( void )
{
if ( V_138 )
F_161 ( & V_260 ) ;
return 0 ;
}
static void F_104 ( void ) { }
static int T_5 F_162 ( void )
{
int V_159 , V_261 , V_262 ;
unsigned V_19 ;
T_7 * V_263 ;
F_163 ( V_264 , V_265 ) ;
V_263 = F_164 ( V_237 ) ;
F_165 ( V_264 , V_265 ) ;
for ( V_159 = 0 ; V_159 < V_232 ; V_159 ++ ) {
if ( V_263 ) {
V_19 = V_263 [ V_159 ] ;
} else if ( V_159 < V_232 ) {
if ( F_166 ( V_159 ) )
V_19 = F_70 ( V_237 , V_159 ) ;
else
continue;
} else
break;
if ( V_19 != V_169 )
F_167 ( F_168 ( V_19 ) , V_264 ) ;
}
V_261 = 0 ;
V_262 = 0 ;
for ( V_159 = 0 ; V_159 < V_265 ; V_159 ++ ) {
if ( F_169 ( V_159 , V_264 ) ) {
V_261 += 1 + V_262 ;
V_262 = 0 ;
} else
++ V_262 ;
}
return V_261 ;
}
static int T_5 F_170 ( const struct V_266 * V_267 )
{
if ( V_268 )
return 0 ;
F_19 ( L_88 , V_267 -> V_269 ) ;
V_268 = 1 ;
return 0 ;
}
static void T_5 F_171 ( void )
{
if ( V_270 )
return;
F_172 ( V_271 ) ;
V_270 = 1 ;
}
T_5 int F_173 ( void )
{
F_171 () ;
if ( V_268 )
return 1 ;
if ( ! F_174 () )
return 0 ;
if ( F_162 () > 1 )
return 1 ;
return 0 ;
}
static int T_1 F_175 ( char * V_1 )
{
V_165 = 1 ;
F_10 ( V_197 ) ;
return 0 ;
}
static int T_1 F_176 ( char * V_1 )
{
return F_175 ( V_1 ) ;
}
static int T_1 F_177 ( char * V_1 )
{
V_272 = 1 ;
return 0 ;
}
static int T_1 F_178 ( char * V_1 )
{
V_112 = 1 ;
return 0 ;
}
static int T_1 F_179 ( char * V_1 )
{
V_112 = 1 ;
return 0 ;
}
static int T_1 F_180 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_15
V_185 = 0 ;
return 0 ;
#endif
return - V_53 ;
}
if ( strcmp ( L_89 , V_1 ) == 0 )
V_273 = V_141 ;
else if ( strcmp ( L_90 , V_1 ) == 0 )
V_273 = V_102 ;
else {
F_9 ( L_91
L_92 , V_1 ) ;
return - V_53 ;
}
return 0 ;
}
static int T_1 F_181 ( void )
{
if ( ! V_121 )
return - 1 ;
V_274 . V_275 = V_121 ;
V_274 . V_276 = V_274 . V_275 + V_277 - 1 ;
F_182 ( & V_278 , & V_274 ) ;
return 0 ;
}
