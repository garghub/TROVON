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
static T_1 int F_9 ( char * V_7 )
{
if ( F_10 () ) {
int V_8 = F_11 ( V_9 ) ;
if ( V_8 >= 255 ) {
F_12 ( L_2 ,
V_8 ) ;
return 0 ;
}
F_12 ( L_3 ) ;
} else
F_6 ( V_10 ) ;
V_11 = 1 ;
return 0 ;
}
static inline int F_13 ( void )
{
return F_14 ( F_15 ( V_12 ) ) ;
}
static inline int F_16 ( void )
{
#ifdef F_17
return 1 ;
#else
return F_18 ( F_13 () ) ;
#endif
}
static int F_19 ( void )
{
if ( V_13 . V_14 == V_15 &&
V_13 . V_16 >= 0xf )
return 1 ;
return F_13 () >= 0x14 ;
}
static void T_1 F_20 ( void )
{
F_21 ( L_4 ) ;
V_17 = & V_18 ;
}
void F_22 ( void )
{
while ( F_15 ( V_19 ) & V_20 )
F_23 () ;
}
T_2 F_24 ( void )
{
T_2 V_21 ;
int V_22 ;
V_22 = 0 ;
do {
V_21 = F_15 ( V_19 ) & V_20 ;
if ( ! V_21 )
break;
F_25 ( V_23 ) ;
F_26 ( 100 ) ;
} while ( V_22 ++ < 1000 );
return V_21 ;
}
void F_27 ( T_2 V_24 , T_2 V_25 )
{
F_28 ( V_26 , F_29 ( V_25 ) ) ;
F_28 ( V_19 , V_24 ) ;
}
T_3 F_30 ( void )
{
T_2 V_27 , V_28 ;
V_28 = F_15 ( V_26 ) ;
V_27 = F_15 ( V_19 ) ;
return V_27 | ( ( T_3 ) V_28 << 32 ) ;
}
int F_31 ( void )
{
return F_19 () ? 0xff : 0xf ;
}
int F_32 ( void )
{
unsigned int V_29 ;
V_29 = F_15 ( V_12 ) ;
return F_18 ( F_14 ( V_29 ) ) ? F_33 ( V_29 ) : 2 ;
}
static void F_34 ( unsigned int V_30 , int V_31 , int V_32 )
{
unsigned int V_33 , V_34 ;
V_33 = V_35 ;
if ( ! V_31 )
V_33 |= V_36 ;
else if ( F_35 ( V_4 ) )
V_33 |= V_37 ;
if ( ! F_16 () )
V_33 |= F_36 ( V_38 ) ;
if ( ! V_32 )
V_33 |= V_39 ;
F_28 ( V_40 , V_33 ) ;
if ( V_33 & V_37 ) {
F_37 ( V_41 L_5 ) ;
return;
}
V_34 = F_15 ( V_42 ) ;
F_28 ( V_42 ,
( V_34 & ~ ( V_43 | V_44 ) ) |
V_45 ) ;
if ( ! V_31 )
F_28 ( V_46 , V_30 / V_47 ) ;
}
static inline int F_38 ( unsigned int V_48 , unsigned int V_49 )
{
return ( V_48 & V_50 )
|| ( V_49 == V_50 )
|| ( ( V_49 & ~ V_50 ) == V_48 ) ;
}
static unsigned int F_39 ( int V_51 , unsigned int V_49 )
{
unsigned int V_52 , V_53 ;
if ( V_51 >= V_54 )
return ~ 0 ;
V_52 = F_40 ( & V_55 [ V_51 ] ) ;
do {
V_53 = V_52 & ~ V_50 ;
if ( V_53 && ! F_38 ( V_53 , V_49 ) )
return V_52 ;
V_52 = F_41 ( & V_55 [ V_51 ] , V_52 , V_49 ) ;
} while ( V_52 != V_49 );
V_52 &= ~ V_50 ;
if ( V_52 && V_52 != V_53 )
F_21 ( L_6 ,
V_51 , V_52 ) ;
return V_49 ;
}
int F_42 ( T_4 V_51 , T_4 V_53 , T_4 V_56 , T_4 V_57 )
{
unsigned long V_58 = F_43 ( V_51 ) ;
unsigned int V_49 , V_48 , V_59 ;
V_49 = ( V_57 << 16 ) | ( V_56 << 8 ) | V_53 ;
V_48 = F_15 ( V_58 ) ;
V_59 = F_39 ( V_51 , V_49 ) ;
if ( V_59 != V_49 ) {
F_44 ( V_60 L_7
L_8
L_9 ,
F_45 () , V_58 , V_51 , V_49 , V_59 ) ;
return - V_61 ;
}
if ( ! F_38 ( V_48 , V_49 ) ) {
F_44 ( V_60 L_7
L_8
L_10 ,
F_45 () , V_58 , V_51 , V_49 , V_48 ) ;
return - V_62 ;
}
F_28 ( V_58 , V_49 ) ;
return 0 ;
}
static int F_46 ( unsigned long V_63 ,
struct V_64 * V_65 )
{
F_28 ( V_46 , V_63 ) ;
return 0 ;
}
static int F_47 ( unsigned long V_63 ,
struct V_64 * V_65 )
{
T_3 V_66 ;
F_48 ( V_66 ) ;
F_49 ( V_67 , V_66 + ( ( ( T_3 ) V_63 ) * V_68 ) ) ;
return 0 ;
}
static void F_50 ( enum V_69 V_70 ,
struct V_64 * V_65 )
{
unsigned long V_71 ;
unsigned int V_29 ;
if ( V_65 -> V_72 & V_73 )
return;
F_51 ( V_71 ) ;
switch ( V_70 ) {
case V_74 :
case V_75 :
F_34 ( V_76 ,
V_70 != V_74 , 1 ) ;
break;
case V_77 :
case V_78 :
V_29 = F_15 ( V_40 ) ;
V_29 |= ( V_39 | V_35 ) ;
F_28 ( V_40 , V_29 ) ;
F_28 ( V_46 , 0 ) ;
break;
case V_79 :
break;
}
F_52 ( V_71 ) ;
}
static void F_53 ( const struct V_80 * V_57 )
{
#ifdef F_54
V_17 -> V_81 ( V_57 , V_35 ) ;
#endif
}
static void T_5 F_55 ( void )
{
struct V_64 * V_82 = & F_56 ( V_83 ) ;
if ( F_57 ( V_84 ) ) {
V_85 . V_72 &= ~ V_86 ;
V_85 . V_87 = 150 ;
}
memcpy ( V_82 , & V_85 , sizeof( * V_82 ) ) ;
V_82 -> V_80 = F_58 ( F_45 () ) ;
if ( F_57 ( V_4 ) ) {
V_82 -> V_72 &= ~ ( V_88 |
V_73 ) ;
V_82 -> V_89 = F_47 ;
F_59 ( V_82 ,
( V_90 / V_68 ) * 1000 ,
0xF , ~ 0UL ) ;
} else
F_60 ( V_82 ) ;
}
static void T_1 F_61 ( struct V_64 * V_91 )
{
unsigned long long V_66 = 0 ;
long V_92 = F_15 ( V_93 ) ;
unsigned long V_94 = F_62 () ;
if ( V_95 )
F_48 ( V_66 ) ;
switch ( V_96 ++ ) {
case 0 :
V_97 = V_92 ;
V_98 = V_66 ;
V_99 = V_94 ;
V_100 = V_101 ;
break;
case V_102 :
V_103 = V_92 ;
V_104 = V_66 ;
if ( V_94 < V_99 )
V_94 += V_105 ;
V_106 = V_94 ;
V_107 = V_101 ;
break;
}
}
static int T_1
F_63 ( long V_108 , long * V_63 , long * V_109 )
{
const long V_110 = V_111 / 10 ;
const long V_112 = V_110 / 100 ;
unsigned long V_113 ;
T_3 V_114 ;
#ifndef F_64
return - 1 ;
#endif
F_65 ( V_115 , L_11 , V_108 ) ;
if ( ! V_108 )
return - 1 ;
V_113 = F_66 ( V_111 , 22 ) ;
if ( V_108 > ( V_110 - V_112 ) &&
V_108 < ( V_110 + V_112 ) ) {
F_65 ( V_115 , L_12 ) ;
return 0 ;
}
V_114 = ( ( ( T_3 ) V_108 ) * V_113 ) >> 22 ;
F_67 ( V_114 , 1000000 ) ;
F_12 ( L_13
L_14 , ( long ) V_114 ) ;
V_114 = ( ( ( T_3 ) ( * V_63 ) ) * V_110 ) ;
F_67 ( V_114 , V_108 ) ;
F_21 ( L_15
L_16 , ( unsigned long ) V_114 , * V_63 ) ;
* V_63 = ( long ) V_114 ;
if ( V_95 ) {
V_114 = ( ( ( T_3 ) ( * V_109 ) ) * V_110 ) ;
F_67 ( V_114 , V_108 ) ;
F_65 ( V_115 , L_17
L_18 ,
( unsigned long ) V_114 , * V_109 ) ;
* V_109 = ( long ) V_114 ;
}
return 0 ;
}
static int T_1 F_68 ( void )
{
struct V_64 * V_82 = & F_56 ( V_83 ) ;
void (* F_69)( struct V_64 * V_91 );
unsigned long V_116 ;
long V_63 , V_109 ;
int V_117 = 0 ;
if ( F_35 ( V_4 ) ) {
return 0 ;
} else if ( V_76 ) {
F_65 ( V_115 , L_19 ,
V_76 ) ;
V_85 . V_113 = F_70 ( V_76 / V_47 ,
V_118 , V_85 . V_119 ) ;
V_85 . V_120 =
F_71 ( 0x7FFFFF , & V_85 ) ;
V_85 . V_121 =
F_71 ( 0xF , & V_85 ) ;
V_85 . V_72 &= ~ V_73 ;
return 0 ;
}
F_65 ( V_115 , L_20
L_21 ) ;
F_72 () ;
F_69 = V_122 -> V_123 ;
V_122 -> V_123 = F_61 ;
F_34 ( 0xffffffff , 0 , 0 ) ;
F_73 () ;
while ( V_96 <= V_102 )
F_23 () ;
F_72 () ;
V_122 -> V_123 = F_69 ;
V_63 = V_97 - V_103 ;
F_65 ( V_115 , L_22 , V_63 ) ;
V_109 = ( long ) ( V_104 - V_98 ) ;
V_117 = ! F_63 ( V_106 - V_99 ,
& V_63 , & V_109 ) ;
V_85 . V_113 = F_70 ( V_63 , V_118 * V_102 ,
V_85 . V_119 ) ;
V_85 . V_120 =
F_71 ( 0x7FFFFFFF , & V_85 ) ;
V_85 . V_121 =
F_71 ( 0xF , & V_85 ) ;
V_76 = ( V_63 * V_47 ) / V_102 ;
F_65 ( V_115 , L_23 , V_63 ) ;
F_65 ( V_115 , L_24 , V_85 . V_113 ) ;
F_65 ( V_115 , L_25 ,
V_76 ) ;
if ( V_95 ) {
F_65 ( V_115 , L_26
L_27 ,
( V_109 / V_102 ) / ( 1000000 / V_124 ) ,
( V_109 / V_102 ) % ( 1000000 / V_124 ) ) ;
}
F_65 ( V_115 , L_28
L_29 ,
V_76 / ( 1000000 / V_124 ) ,
V_76 % ( 1000000 / V_124 ) ) ;
if ( V_76 < ( 1000000 / V_124 ) ) {
F_73 () ;
F_12 ( L_30 ) ;
return - 1 ;
}
V_82 -> V_72 &= ~ V_73 ;
if ( ! V_117 ) {
F_65 ( V_115 , L_31 ) ;
V_82 -> V_123 = F_61 ;
F_50 ( V_74 , V_82 ) ;
V_96 = - 1 ;
F_73 () ;
while ( V_96 <= V_102 )
F_23 () ;
F_50 ( V_78 , V_82 ) ;
V_116 = V_107 - V_100 ;
F_65 ( V_115 , L_32 , V_116 ) ;
if ( V_116 >= V_102 - 2 && V_116 <= V_102 + 2 )
F_65 ( V_115 , L_33 ) ;
else
V_82 -> V_72 |= V_73 ;
} else
F_73 () ;
if ( V_82 -> V_72 & V_73 ) {
F_12 ( L_34 ) ;
return - 1 ;
}
return 0 ;
}
void T_1 F_74 ( void )
{
if ( V_125 ) {
F_21 ( L_35 ) ;
if ( F_75 () > 1 ) {
V_85 . V_113 = 1 ;
F_55 () ;
}
return;
}
if ( F_68 () ) {
if ( F_75 () > 1 )
F_55 () ;
return;
}
V_85 . V_72 &= ~ V_73 ;
F_55 () ;
}
void T_5 F_76 ( void )
{
F_55 () ;
}
static void F_77 ( void )
{
int V_126 = F_45 () ;
struct V_64 * V_65 = & F_78 ( V_83 , V_126 ) ;
if ( ! V_65 -> V_123 ) {
F_12 ( L_36 , V_126 ) ;
F_50 ( V_78 , V_65 ) ;
return;
}
F_25 ( V_127 ) ;
V_65 -> V_123 ( V_65 ) ;
}
void T_6 F_79 ( struct V_128 * V_129 )
{
struct V_128 * V_130 = F_80 ( V_129 ) ;
F_81 () ;
F_82 () ;
F_83 () ;
F_77 () ;
F_84 () ;
F_80 ( V_130 ) ;
}
int F_85 ( unsigned int V_131 )
{
return - V_61 ;
}
void F_86 ( void )
{
int V_132 ;
T_2 V_29 ;
if ( ! V_133 && ! V_134 )
return;
V_132 = F_32 () ;
if ( V_132 >= 3 ) {
V_29 = V_135 ;
F_28 ( V_136 , V_29 | V_39 ) ;
}
V_29 = F_15 ( V_40 ) ;
F_28 ( V_40 , V_29 | V_39 ) ;
V_29 = F_15 ( V_137 ) ;
F_28 ( V_137 , V_29 | V_39 ) ;
V_29 = F_15 ( V_138 ) ;
F_28 ( V_138 , V_29 | V_39 ) ;
if ( V_132 >= 4 ) {
V_29 = F_15 ( V_139 ) ;
F_28 ( V_139 , V_29 | V_39 ) ;
}
#ifdef F_87
if ( V_132 >= 5 ) {
V_29 = F_15 ( V_140 ) ;
F_28 ( V_140 , V_29 | V_39 ) ;
}
#endif
#ifdef F_88
if ( V_132 >= 6 ) {
V_29 = F_15 ( V_141 ) ;
if ( ! ( V_29 & V_39 ) )
F_28 ( V_141 , V_29 | V_39 ) ;
}
#endif
F_28 ( V_40 , V_39 ) ;
F_28 ( V_137 , V_39 ) ;
F_28 ( V_138 , V_39 ) ;
if ( V_132 >= 3 )
F_28 ( V_136 , V_39 ) ;
if ( V_132 >= 4 )
F_28 ( V_139 , V_39 ) ;
if ( F_16 () ) {
if ( V_132 > 3 )
F_28 ( V_142 , 0 ) ;
F_15 ( V_142 ) ;
}
}
void F_89 ( void )
{
unsigned int V_143 ;
if ( ! V_133 && ! V_134 )
return;
F_86 () ;
V_143 = F_15 ( V_144 ) ;
V_143 &= ~ V_145 ;
F_28 ( V_144 , V_143 ) ;
#ifdef V_2
if ( V_146 ) {
unsigned int V_147 , V_148 ;
F_90 ( V_149 , V_147 , V_148 ) ;
V_147 &= ~ V_150 ;
F_91 ( V_149 , V_147 , V_148 ) ;
}
#endif
}
void F_92 ( void )
{
unsigned long V_71 ;
if ( ! V_151 && ! F_93 () )
return;
F_51 ( V_71 ) ;
#ifdef V_2
if ( ! V_146 )
F_86 () ;
else
#endif
F_89 () ;
F_52 ( V_71 ) ;
}
int T_1 F_94 ( void )
{
unsigned int V_152 , V_153 ;
V_152 = F_15 ( V_12 ) ;
F_65 ( V_154 , L_37 , V_152 ) ;
F_28 ( V_12 , V_152 ^ V_155 ) ;
V_153 = F_15 ( V_12 ) ;
F_65 ( V_154 , L_37 , V_153 ) ;
if ( V_153 != V_152 )
return 0 ;
V_153 = F_14 ( V_152 ) ;
if ( V_153 == 0x00 || V_153 == 0xff )
return 0 ;
V_153 = F_32 () ;
if ( V_153 < 0x02 || V_153 == 0xff )
return 0 ;
V_152 = F_15 ( V_9 ) ;
F_65 ( V_154 , L_38 , V_152 ) ;
F_28 ( V_9 , V_152 ^ V_17 -> V_156 ) ;
V_153 = F_15 ( V_9 ) ;
F_65 ( V_154 , L_38 , V_153 ) ;
F_28 ( V_9 , V_152 ) ;
if ( V_153 != ( V_152 ^ V_17 -> V_156 ) )
return 0 ;
V_152 = F_15 ( V_137 ) ;
F_65 ( V_154 , L_39 , V_152 ) ;
V_153 = F_15 ( V_138 ) ;
F_65 ( V_154 , L_40 , V_153 ) ;
return 1 ;
}
void T_1 F_95 ( void )
{
if ( F_19 () || V_13 . V_14 == V_15 )
return;
F_96 () ;
F_65 ( V_154 , L_41 ) ;
F_28 ( V_19 , V_157 |
V_158 | V_159 ) ;
}
void T_1 F_97 ( void )
{
unsigned int V_143 ;
if ( V_160 || ! V_151 )
return;
F_86 () ;
V_143 = F_15 ( V_144 ) ;
V_143 &= ~ V_161 ;
V_143 |= V_145 ;
#ifdef V_2
if ( ( V_13 . V_14 == V_162 ) &&
( V_13 . V_16 == 15 ) )
V_143 &= ~ V_163 ;
else
#endif
V_143 |= V_163 ;
V_143 |= V_164 ;
F_28 ( V_144 , V_143 ) ;
F_28 ( V_137 , V_165 ) ;
V_143 = V_166 ;
if ( ! F_16 () )
V_143 |= V_167 ;
F_28 ( V_138 , V_143 ) ;
}
static void T_5 F_98 ( void )
{
unsigned int V_168 , V_143 , V_132 ;
if ( ! F_16 () ) {
F_21 ( L_42 ) ;
return;
}
if ( V_17 -> V_169 ) {
F_21 ( L_43 ) ;
return;
}
V_132 = F_32 () ;
if ( V_132 > 3 )
F_28 ( V_142 , 0 ) ;
V_168 = F_15 ( V_142 ) ;
V_143 = V_135 ;
F_28 ( V_136 , V_143 ) ;
if ( V_132 > 3 )
F_28 ( V_142 , 0 ) ;
V_143 = F_15 ( V_142 ) ;
if ( V_143 != V_168 )
F_65 ( V_115 , L_44
L_45 ,
V_168 , V_143 ) ;
}
void T_5 F_99 ( void )
{
int V_126 = F_45 () ;
unsigned int V_143 , V_170 ;
int V_171 , V_172 , V_173 = 0 ;
unsigned long long V_66 = 0 , V_174 ;
long long V_175 = V_176 ;
if ( V_95 )
F_48 ( V_66 ) ;
if ( V_177 ) {
F_100 () ;
return;
}
#ifdef V_2
if ( F_16 () && V_17 -> V_169 ) {
F_28 ( V_142 , 0 ) ;
F_28 ( V_142 , 0 ) ;
F_28 ( V_142 , 0 ) ;
F_28 ( V_142 , 0 ) ;
}
#endif
F_101 () ;
F_102 ( ! V_17 -> V_178 () ) ;
V_17 -> V_179 () ;
#ifdef V_2
V_171 = F_103 ( V_180 , V_126 ) ;
F_104 ( V_171 != V_181 && V_171 != F_105 () ) ;
F_103 ( V_180 , V_126 ) =
F_105 () ;
if ( V_17 -> V_182 )
F_106 ( F_103 ( V_183 , V_126 ) ,
V_17 -> V_182 ( V_126 ) ) ;
#endif
V_143 = F_15 ( V_184 ) ;
V_143 &= ~ V_185 ;
F_28 ( V_184 , V_143 ) ;
do {
V_170 = 0 ;
for ( V_171 = V_186 - 1 ; V_171 >= 0 ; V_171 -- )
V_170 |= F_15 ( V_187 + V_171 * 0x10 ) ;
for ( V_171 = V_186 - 1 ; V_171 >= 0 ; V_171 -- ) {
V_143 = F_15 ( V_188 + V_171 * 0x10 ) ;
for ( V_172 = 31 ; V_172 >= 0 ; V_172 -- ) {
if ( V_143 & ( 1 << V_172 ) ) {
F_81 () ;
V_173 ++ ;
}
}
}
if ( V_173 > 256 ) {
F_107 ( V_189 L_46 ,
V_173 ) ;
break;
}
if ( V_170 ) {
if ( V_95 ) {
F_48 ( V_174 ) ;
V_175 = ( V_176 << 10 ) - ( V_174 - V_66 ) ;
} else
V_175 -- ;
}
} while ( V_170 && V_175 > 0 );
F_104 ( V_175 <= 0 ) ;
V_143 = F_15 ( V_144 ) ;
V_143 &= ~ V_161 ;
V_143 |= V_145 ;
#ifdef V_2
V_143 &= ~ V_163 ;
#endif
V_143 |= V_164 ;
F_28 ( V_144 , V_143 ) ;
V_143 = F_15 ( V_137 ) & V_39 ;
if ( ! V_126 && ( V_190 || ! V_143 ) ) {
V_143 = V_165 ;
F_65 ( V_115 , L_47 , V_126 ) ;
} else {
V_143 = V_165 | V_39 ;
F_65 ( V_115 , L_48 , V_126 ) ;
}
F_28 ( V_137 , V_143 ) ;
if ( ! V_126 )
V_143 = V_166 ;
else
V_143 = V_166 | V_39 ;
if ( ! F_16 () )
V_143 |= V_167 ;
F_28 ( V_138 , V_143 ) ;
#ifdef F_88
if ( ! V_126 )
F_108 () ;
#endif
}
void T_5 F_109 ( void )
{
F_98 () ;
#ifdef V_2
{
unsigned int V_143 ;
V_143 = F_15 ( V_40 ) ;
V_143 |= ( V_39 | V_35 ) ;
F_28 ( V_40 , V_143 ) ;
}
#endif
F_110 () ;
}
void T_1 F_111 ( void )
{
F_109 () ;
F_112 () ;
}
static inline void F_113 ( T_3 V_191 )
{
F_49 ( V_149 ,
V_191 & ~ ( V_192 | V_193 ) ) ;
F_49 ( V_149 , V_191 & ~ V_192 ) ;
}
static T_1 void F_114 ( void )
{
T_3 V_191 ;
if ( ! V_194 )
return;
F_115 ( V_149 , V_191 ) ;
if ( V_191 & V_192 ) {
T_2 V_195 = F_116 () ;
if ( V_195 >= 255 )
F_117 ( L_49 , V_195 ) ;
F_21 ( L_50 ) ;
F_113 ( V_191 ) ;
if ( V_11 ) {
F_118 ( & F_119 ( 0 ) , V_10 ) ;
F_6 ( V_10 ) ;
}
V_196 = 1 ;
V_133 = 0 ;
F_120 ( V_197 ) ;
}
}
void F_121 ( void )
{
if ( F_10 () ) {
F_21 ( L_51 ) ;
V_198 = V_133 = 1 ;
}
}
void F_122 ( void )
{
T_3 V_191 ;
F_115 ( V_149 , V_191 ) ;
if ( V_196 ) {
F_113 ( V_191 ) ;
return;
}
if ( ! V_133 )
return;
if ( ! ( V_191 & V_192 ) ) {
F_37 ( V_199 L_52 ) ;
F_49 ( V_149 , V_191 | V_192 ) ;
}
}
int T_1 F_123 ( void )
{
#ifdef F_124
if ( ! F_125 () ) {
F_126 ( L_53 ) ;
return - 1 ;
}
if ( ! V_198 && V_200 ) {
F_21 ( L_54
L_55 ) ;
return - 1 ;
}
return F_127 () ;
#endif
return - 1 ;
}
void T_1 F_128 ( void )
{
unsigned long V_71 ;
int V_201 , F_10 = 0 ;
int V_202 ;
F_129 () ;
V_202 = F_130 () ;
if ( V_202 && ! F_131 () )
return;
V_201 = F_132 () ;
if ( V_201 ) {
F_21 ( L_56 , V_201 ) ;
return;
}
F_51 ( V_71 ) ;
V_203 -> V_204 () ;
F_133 () ;
if ( V_198 && V_11 )
F_114 () ;
if ( V_202 )
V_201 = - 1 ;
else
V_201 = F_123 () ;
if ( ! F_131 () )
goto V_205;
if ( V_201 < 0 ) {
if ( V_206 > 255 ||
! F_134 () ) {
if ( V_198 )
F_114 () ;
goto V_205;
}
F_135 () ;
}
if ( V_201 == V_207 ) {
F_21 ( L_57 ) ;
goto V_205;
}
F_10 = 1 ;
if ( F_131 () && ! V_133 ) {
V_133 = 1 ;
F_122 () ;
F_21 ( L_58 ) ;
}
V_205:
if ( V_201 < 0 )
F_136 () ;
V_203 -> V_208 () ;
F_52 ( V_71 ) ;
}
static int T_1 F_137 ( void )
{
if ( ! V_151 ) {
F_21 ( L_59 ) ;
return - 1 ;
}
V_197 = V_209 ;
return 0 ;
}
static int T_1 F_138 ( void )
{
T_2 V_72 , V_148 , V_147 ;
V_72 = F_139 ( 1 ) ;
if ( ! ( V_72 & ( 1 << V_210 ) ) ) {
F_12 ( L_60 ) ;
return - 1 ;
}
F_140 ( & V_13 , V_210 ) ;
V_197 = V_209 ;
if ( V_13 . V_16 >= 6 ) {
F_90 ( V_149 , V_147 , V_148 ) ;
if ( V_147 & V_150 )
V_197 = V_147 & V_211 ;
}
F_21 ( L_61 ) ;
return 0 ;
}
int T_1 F_141 ( unsigned long V_212 )
{
T_2 V_148 , V_147 ;
if ( V_177 )
return - 1 ;
if ( V_13 . V_16 >= 6 ) {
F_90 ( V_149 , V_147 , V_148 ) ;
if ( ! ( V_147 & V_150 ) ) {
F_21 ( L_62 ) ;
V_147 &= ~ V_211 ;
V_147 |= V_150 | V_212 ;
F_91 ( V_149 , V_147 , V_148 ) ;
V_146 = 1 ;
}
}
return F_138 () ;
}
static int T_1 F_137 ( void )
{
if ( V_177 )
return - 1 ;
switch ( V_13 . V_14 ) {
case V_15 :
if ( ( V_13 . V_16 == 6 && V_13 . V_213 > 1 ) ||
( V_13 . V_16 >= 15 ) )
break;
goto V_214;
case V_162 :
if ( V_13 . V_16 == 6 || V_13 . V_16 == 15 ||
( V_13 . V_16 == 5 && V_151 ) )
break;
goto V_214;
default:
goto V_214;
}
if ( ! V_151 ) {
if ( ! V_3 ) {
F_21 ( L_63
L_64 ) ;
return - 1 ;
}
if ( F_141 ( V_209 ) )
return - 1 ;
} else {
if ( F_138 () )
return - 1 ;
}
F_110 () ;
return 0 ;
V_214:
F_21 ( L_65 ) ;
return - 1 ;
}
void T_1 F_142 ( void )
{
unsigned int V_215 ;
if ( V_133 ) {
V_216 = F_116 () ;
return;
}
if ( ! V_160 && F_137 () ) {
F_21 ( L_66 ) ;
F_20 () ;
} else {
V_134 = V_197 ;
if ( ! V_217 && ! V_160 )
F_120 ( V_134 ) ;
}
V_215 = F_116 () ;
if ( V_216 != V_215 ) {
V_216 = V_215 ;
V_218 [ V_215 ] =
F_14 ( F_15 ( V_12 ) ) ;
}
}
void T_1 F_120 ( unsigned long V_219 )
{
V_197 = V_219 ;
if ( ! V_133 ) {
F_143 ( V_220 , V_219 ) ;
F_65 ( V_115 , L_67 ,
V_221 , V_197 ) ;
}
if ( V_216 == - 1U ) {
V_216 = F_116 () ;
V_218 [ V_216 ] =
F_14 ( F_15 ( V_12 ) ) ;
}
}
int T_1 F_144 ( void )
{
if ( V_177 ) {
F_21 ( L_68 ) ;
return - 1 ;
}
#ifdef F_17
if ( ! V_151 ) {
V_177 = 1 ;
F_21 ( L_69 ) ;
return - 1 ;
}
#else
if ( ! V_160 && ! V_151 )
return - 1 ;
if ( ! V_151 &&
F_18 ( V_218 [ V_216 ] ) ) {
F_44 ( L_70 ,
V_216 ) ;
return - 1 ;
}
#endif
F_145 () ;
F_94 () ;
F_146 () ;
#ifdef F_17
F_28 ( V_9 , F_147 ( V_216 ) ) ;
#else
# ifdef F_148
V_216 = F_116 () ;
# endif
#endif
F_149 ( V_216 , & V_222 ) ;
F_99 () ;
#ifdef F_150
if ( ! V_200 && V_223 )
F_151 () ;
#endif
F_111 () ;
#ifdef F_150
if ( V_160 && ! V_200 && V_223 )
F_152 () ;
else {
V_223 = 0 ;
}
#endif
V_224 . V_225 . V_226 () ;
return 0 ;
}
void F_153 ( struct V_128 * V_129 )
{
T_2 V_29 ;
F_82 () ;
F_83 () ;
V_29 = F_15 ( V_188 + ( ( V_164 & ~ 0x1f ) >> 1 ) ) ;
if ( V_29 & ( 1 << ( V_164 & 0x1f ) ) )
F_81 () ;
F_25 ( V_227 ) ;
F_21 ( L_71
L_72 , F_45 () ) ;
F_84 () ;
}
void F_154 ( struct V_128 * V_129 )
{
T_2 V_228 , V_229 ;
T_2 V_171 = 0 ;
static const char * const V_230 [] = {
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80 ,
} ;
F_82 () ;
F_83 () ;
V_228 = F_15 ( V_142 ) ;
F_28 ( V_142 , 0 ) ;
V_229 = F_15 ( V_142 ) ;
F_81 () ;
F_155 ( & V_231 ) ;
F_65 ( V_154 , V_41 L_81 ,
F_45 () , V_228 , V_229 ) ;
V_229 = V_229 & 0xff ;
while ( V_229 ) {
if ( V_229 & 0x1 )
F_65 ( V_154 , V_232 L_82 , V_230 [ V_171 ] ) ;
V_171 ++ ;
V_229 >>= 1 ;
}
F_65 ( V_154 , V_232 L_83 ) ;
F_84 () ;
}
void T_1 F_146 ( void )
{
#ifdef V_2
if ( V_190 ) {
F_86 () ;
F_65 ( V_115 , L_84
L_85 ) ;
F_1 () ;
}
#endif
if ( V_17 -> V_233 )
V_17 -> V_233 () ;
}
void F_156 ( int V_234 )
{
unsigned int V_143 ;
#ifdef V_2
if ( V_190 ) {
F_65 ( V_115 , L_86
L_87 ) ;
F_3 () ;
return;
}
#endif
V_143 = F_15 ( V_144 ) ;
V_143 &= ~ V_161 ;
V_143 |= V_145 ;
V_143 |= 0xf ;
F_28 ( V_144 , V_143 ) ;
if ( ! V_234 ) {
V_143 = F_15 ( V_137 ) ;
V_143 &= ~ ( V_235 | V_236 |
V_237 | V_238 |
V_167 | V_39 ) ;
V_143 |= V_238 | V_236 ;
V_143 = F_157 ( V_143 , V_239 ) ;
F_28 ( V_137 , V_143 ) ;
} else {
F_28 ( V_137 , V_39 ) ;
}
V_143 = F_15 ( V_138 ) ;
V_143 &= ~ ( V_235 | V_236 |
V_237 | V_238 |
V_167 | V_39 ) ;
V_143 |= V_238 | V_236 ;
V_143 = F_157 ( V_143 , V_240 ) ;
F_28 ( V_138 , V_143 ) ;
}
void T_5 F_158 ( int V_8 , int V_241 )
{
int V_126 , V_242 = V_243 ;
bool V_244 = F_159 ( V_216 ,
V_222 ) ;
if ( ! V_244 && V_245 >= V_243 - 1 &&
V_8 != V_216 ) {
int V_246 = V_242 + V_247 - 1 ;
F_12 (
L_88
L_89
L_90 , V_242 , V_246 , V_8 ) ;
V_247 ++ ;
return;
}
if ( V_245 >= V_243 ) {
int V_246 = V_242 + V_247 ;
F_12 (
L_91
L_90 , V_242 , V_246 , V_8 ) ;
V_247 ++ ;
return;
}
V_245 ++ ;
if ( V_8 == V_216 ) {
V_126 = 0 ;
} else
V_126 = F_160 ( - 1 , V_248 ) ;
if ( V_241 == 0x0 ) {
F_12 ( L_92 ,
V_126 , V_8 ) ;
V_241 = 0x10 ;
}
V_218 [ V_8 ] = V_241 ;
if ( V_241 != V_218 [ V_216 ] ) {
F_12 ( L_93 ,
V_218 [ V_216 ] , V_126 , V_241 ) ;
}
F_161 ( V_8 , V_222 ) ;
if ( V_8 > V_206 )
V_206 = V_8 ;
#if F_162 ( F_54 ) || F_162 ( F_17 )
F_103 ( V_183 , V_126 ) = V_8 ;
F_103 ( V_249 , V_126 ) = V_8 ;
#endif
#ifdef V_2
F_103 ( V_180 , V_126 ) =
V_17 -> V_250 ( V_126 ) ;
#endif
F_163 ( V_126 , true ) ;
F_164 ( V_126 , true ) ;
}
int F_165 ( void )
{
return F_116 () ;
}
void F_166 ( void )
{
unsigned long V_251 ;
F_28 ( V_252 , V_253 ) ;
V_251 = F_15 ( V_254 ) & ~ V_255 ;
V_251 |= F_167 ( 1UL << F_45 () ) ;
F_28 ( V_254 , V_251 ) ;
}
int F_168 ( const struct V_80 * V_80 ,
const struct V_80 * V_256 ,
unsigned int * V_8 )
{
unsigned int V_126 ;
F_169 (cpu, cpumask, andmask) {
if ( F_170 ( V_126 , V_257 ) )
break;
}
if ( F_171 ( V_126 < V_243 ) ) {
* V_8 = F_78 ( V_183 , V_126 ) ;
return 0 ;
}
return - V_61 ;
}
void T_1 F_172 ( void (* F_173)( T_2 V_58 , T_2 V_29 ) )
{
struct V_17 * * V_258 ;
for ( V_258 = V_259 ; V_258 < V_260 ; V_258 ++ ) {
F_104 ( ( * V_258 ) -> F_173 == F_173 ) ;
( * V_258 ) -> F_173 = F_173 ;
}
}
static int F_174 ( void )
{
unsigned long V_71 ;
int V_132 ;
if ( ! V_261 . V_262 )
return 0 ;
V_132 = F_32 () ;
V_261 . V_263 = F_15 ( V_9 ) ;
V_261 . V_264 = F_15 ( V_184 ) ;
V_261 . V_265 = F_15 ( V_254 ) ;
V_261 . V_266 = F_15 ( V_252 ) ;
V_261 . V_267 = F_15 ( V_144 ) ;
V_261 . V_268 = F_15 ( V_40 ) ;
if ( V_132 >= 4 )
V_261 . V_269 = F_15 ( V_139 ) ;
V_261 . V_270 = F_15 ( V_137 ) ;
V_261 . V_271 = F_15 ( V_138 ) ;
V_261 . V_272 = F_15 ( V_136 ) ;
V_261 . V_273 = F_15 ( V_46 ) ;
V_261 . V_274 = F_15 ( V_42 ) ;
#ifdef F_87
if ( V_132 >= 5 )
V_261 . V_275 = F_15 ( V_140 ) ;
#endif
F_51 ( V_71 ) ;
F_89 () ;
F_175 () ;
F_52 ( V_71 ) ;
return 0 ;
}
static void F_176 ( void )
{
unsigned int V_147 , V_148 ;
unsigned long V_71 ;
int V_132 ;
if ( ! V_261 . V_262 )
return;
F_51 ( V_71 ) ;
F_133 () ;
V_203 -> V_204 () ;
if ( V_133 )
F_122 () ;
else {
if ( V_13 . V_16 >= 6 ) {
F_90 ( V_149 , V_147 , V_148 ) ;
V_147 &= ~ V_211 ;
V_147 |= V_150 | V_197 ;
F_91 ( V_149 , V_147 , V_148 ) ;
}
}
V_132 = F_32 () ;
F_28 ( V_136 , V_135 | V_39 ) ;
F_28 ( V_9 , V_261 . V_263 ) ;
F_28 ( V_252 , V_261 . V_266 ) ;
F_28 ( V_254 , V_261 . V_265 ) ;
F_28 ( V_184 , V_261 . V_264 ) ;
F_28 ( V_144 , V_261 . V_267 ) ;
F_28 ( V_137 , V_261 . V_270 ) ;
F_28 ( V_138 , V_261 . V_271 ) ;
#if F_162 ( V_276 ) || F_162 ( F_88 )
if ( V_132 >= 5 )
F_28 ( V_140 , V_261 . V_275 ) ;
#endif
if ( V_132 >= 4 )
F_28 ( V_139 , V_261 . V_269 ) ;
F_28 ( V_40 , V_261 . V_268 ) ;
F_28 ( V_42 , V_261 . V_274 ) ;
F_28 ( V_46 , V_261 . V_273 ) ;
F_28 ( V_142 , 0 ) ;
F_15 ( V_142 ) ;
F_28 ( V_136 , V_261 . V_272 ) ;
F_28 ( V_142 , 0 ) ;
F_15 ( V_142 ) ;
F_177 ( V_133 ) ;
F_52 ( V_71 ) ;
}
static void T_5 F_110 ( void )
{
V_261 . V_262 = 1 ;
}
static int T_1 F_178 ( void )
{
if ( V_151 )
F_179 ( & V_277 ) ;
return 0 ;
}
static void F_110 ( void ) { }
static int T_5 F_180 ( void )
{
int V_171 , V_278 , V_279 ;
unsigned V_25 ;
T_7 * V_280 ;
F_181 ( V_281 , V_282 ) ;
V_280 = F_182 ( V_249 ) ;
F_183 ( V_281 , V_282 ) ;
for ( V_171 = 0 ; V_171 < V_243 ; V_171 ++ ) {
if ( V_280 ) {
V_25 = V_280 [ V_171 ] ;
} else if ( V_171 < V_243 ) {
if ( F_184 ( V_171 ) )
V_25 = F_78 ( V_249 , V_171 ) ;
else
continue;
} else
break;
if ( V_25 != V_181 )
F_185 ( F_186 ( V_25 ) , V_281 ) ;
}
V_278 = 0 ;
V_279 = 0 ;
for ( V_171 = 0 ; V_171 < V_282 ; V_171 ++ ) {
if ( F_187 ( V_171 , V_281 ) ) {
V_278 += 1 + V_279 ;
V_279 = 0 ;
} else
++ V_279 ;
}
return V_278 ;
}
static int T_5 F_188 ( const struct V_283 * V_284 )
{
if ( V_285 )
return 0 ;
F_21 ( L_94 , V_284 -> V_286 ) ;
V_285 = 1 ;
return 0 ;
}
static void T_5 F_189 ( void )
{
if ( V_287 )
return;
F_190 ( V_288 ) ;
V_287 = 1 ;
}
T_5 int F_191 ( void )
{
F_189 () ;
if ( V_285 )
return 1 ;
if ( ! F_192 () )
return 0 ;
if ( F_180 () > 1 )
return 1 ;
return 0 ;
}
static int T_1 F_193 ( char * V_1 )
{
V_177 = 1 ;
F_6 ( V_210 ) ;
return 0 ;
}
static int T_1 F_194 ( char * V_1 )
{
return F_193 ( V_1 ) ;
}
static int T_1 F_195 ( char * V_1 )
{
V_289 = 1 ;
return 0 ;
}
static int T_1 F_196 ( char * V_1 )
{
V_125 = 1 ;
return 0 ;
}
static int T_1 F_197 ( char * V_1 )
{
V_125 = 1 ;
return 0 ;
}
static int T_1 F_198 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_17
V_200 = 0 ;
return 0 ;
#endif
return - V_61 ;
}
if ( strcmp ( L_95 , V_1 ) == 0 )
V_290 = V_154 ;
else if ( strcmp ( L_96 , V_1 ) == 0 )
V_290 = V_115 ;
else {
F_12 ( L_97
L_98 , V_1 ) ;
return - V_61 ;
}
return 0 ;
}
static int T_1 F_199 ( void )
{
if ( ! V_134 )
return - 1 ;
V_291 . V_292 = V_134 ;
V_291 . V_293 = V_291 . V_292 + V_294 - 1 ;
F_200 ( & V_295 , & V_291 ) ;
return 0 ;
}
