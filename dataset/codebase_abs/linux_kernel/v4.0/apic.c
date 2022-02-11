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
F_46 ( V_62 ) ;
F_47 ( V_63 , V_62 + ( ( ( T_3 ) V_59 ) * V_64 ) ) ;
return 0 ;
}
static void F_48 ( enum V_65 V_66 ,
struct V_60 * V_61 )
{
unsigned long V_21 ;
unsigned int V_25 ;
if ( V_61 -> V_67 & V_68 )
return;
F_24 ( V_21 ) ;
switch ( V_66 ) {
case V_69 :
case V_70 :
F_32 ( V_71 ,
V_66 != V_69 , 1 ) ;
break;
case V_72 :
case V_73 :
V_25 = F_11 ( V_36 ) ;
V_25 |= ( V_35 | V_31 ) ;
F_25 ( V_36 , V_25 ) ;
F_25 ( V_42 , 0 ) ;
break;
case V_74 :
break;
}
F_27 ( V_21 ) ;
}
static void F_49 ( const struct V_75 * V_53 )
{
#ifdef F_50
V_12 -> V_76 ( V_53 , V_31 ) ;
#endif
}
static void F_51 ( void )
{
struct V_60 * V_77 = F_52 ( & V_78 ) ;
if ( F_53 ( V_79 ) ) {
V_80 . V_67 &= ~ V_81 ;
V_80 . V_82 = 150 ;
}
memcpy ( V_77 , & V_80 , sizeof( * V_77 ) ) ;
V_77 -> V_75 = F_54 ( F_43 () ) ;
if ( F_53 ( V_4 ) ) {
V_77 -> V_67 &= ~ ( V_83 |
V_68 ) ;
V_77 -> V_84 = F_45 ;
F_55 ( V_77 ,
( V_85 / V_64 ) * 1000 ,
0xF , ~ 0UL ) ;
} else
F_56 ( V_77 ) ;
}
static void T_1 F_57 ( struct V_60 * V_86 )
{
unsigned long long V_62 = 0 ;
long V_87 = F_11 ( V_88 ) ;
unsigned long V_89 = F_58 () ;
if ( V_90 )
F_46 ( V_62 ) ;
switch ( V_91 ++ ) {
case 0 :
V_92 = V_87 ;
V_93 = V_62 ;
V_94 = V_89 ;
V_95 = V_96 ;
break;
case V_97 :
V_98 = V_87 ;
V_99 = V_62 ;
if ( V_89 < V_94 )
V_89 += V_100 ;
V_101 = V_89 ;
V_102 = V_96 ;
break;
}
}
static int T_1
F_59 ( long V_103 , long * V_59 , long * V_104 )
{
const long V_105 = V_106 / 10 ;
const long V_107 = V_105 / 100 ;
unsigned long V_108 ;
T_3 V_109 ;
#ifndef F_60
return - 1 ;
#endif
F_61 ( V_110 , L_9 , V_103 ) ;
if ( ! V_103 )
return - 1 ;
V_108 = F_62 ( V_106 , 22 ) ;
if ( V_103 > ( V_105 - V_107 ) &&
V_103 < ( V_105 + V_107 ) ) {
F_61 ( V_110 , L_10 ) ;
return 0 ;
}
V_109 = ( ( ( T_3 ) V_103 ) * V_108 ) >> 22 ;
F_63 ( V_109 , 1000000 ) ;
F_64 ( L_11
L_12 , ( long ) V_109 ) ;
V_109 = ( ( ( T_3 ) ( * V_59 ) ) * V_105 ) ;
F_63 ( V_109 , V_103 ) ;
F_17 ( L_13
L_14 , ( unsigned long ) V_109 , * V_59 ) ;
* V_59 = ( long ) V_109 ;
if ( V_90 ) {
V_109 = ( ( ( T_3 ) ( * V_104 ) ) * V_105 ) ;
F_63 ( V_109 , V_103 ) ;
F_61 ( V_110 , L_15
L_16 ,
( unsigned long ) V_109 , * V_104 ) ;
* V_104 = ( long ) V_109 ;
}
return 0 ;
}
static int T_1 F_65 ( void )
{
struct V_60 * V_77 = F_52 ( & V_78 ) ;
void (* F_66)( struct V_60 * V_86 );
unsigned long V_111 ;
long V_59 , V_104 ;
int V_112 = 0 ;
if ( F_33 ( V_4 ) ) {
return 0 ;
} else if ( V_71 ) {
F_61 ( V_110 , L_17 ,
V_71 ) ;
V_80 . V_108 = F_67 ( V_71 / V_43 ,
V_113 , V_80 . V_114 ) ;
V_80 . V_115 =
F_68 ( 0x7FFFFF , & V_80 ) ;
V_80 . V_116 =
F_68 ( 0xF , & V_80 ) ;
V_80 . V_67 &= ~ V_68 ;
return 0 ;
}
F_61 ( V_110 , L_18
L_19 ) ;
F_69 () ;
F_66 = V_117 -> V_118 ;
V_117 -> V_118 = F_57 ;
F_32 ( 0xffffffff , 0 , 0 ) ;
F_70 () ;
while ( V_91 <= V_97 )
F_19 () ;
F_69 () ;
V_117 -> V_118 = F_66 ;
V_59 = V_92 - V_98 ;
F_61 ( V_110 , L_20 , V_59 ) ;
V_104 = ( long ) ( V_99 - V_93 ) ;
V_112 = ! F_59 ( V_101 - V_94 ,
& V_59 , & V_104 ) ;
V_80 . V_108 = F_67 ( V_59 , V_113 * V_97 ,
V_80 . V_114 ) ;
V_80 . V_115 =
F_68 ( 0x7FFFFFFF , & V_80 ) ;
V_80 . V_116 =
F_68 ( 0xF , & V_80 ) ;
V_71 = ( V_59 * V_43 ) / V_97 ;
F_61 ( V_110 , L_21 , V_59 ) ;
F_61 ( V_110 , L_22 , V_80 . V_108 ) ;
F_61 ( V_110 , L_23 ,
V_71 ) ;
if ( V_90 ) {
F_61 ( V_110 , L_24
L_25 ,
( V_104 / V_97 ) / ( 1000000 / V_119 ) ,
( V_104 / V_97 ) % ( 1000000 / V_119 ) ) ;
}
F_61 ( V_110 , L_26
L_27 ,
V_71 / ( 1000000 / V_119 ) ,
V_71 % ( 1000000 / V_119 ) ) ;
if ( V_71 < ( 1000000 / V_119 ) ) {
F_70 () ;
F_64 ( L_28 ) ;
return - 1 ;
}
V_77 -> V_67 &= ~ V_68 ;
if ( ! V_112 ) {
F_61 ( V_110 , L_29 ) ;
V_77 -> V_118 = F_57 ;
F_48 ( V_69 , V_77 ) ;
V_91 = - 1 ;
F_70 () ;
while ( V_91 <= V_97 )
F_19 () ;
F_48 ( V_73 , V_77 ) ;
V_111 = V_102 - V_95 ;
F_61 ( V_110 , L_30 , V_111 ) ;
if ( V_111 >= V_97 - 2 && V_111 <= V_97 + 2 )
F_61 ( V_110 , L_31 ) ;
else
V_77 -> V_67 |= V_68 ;
} else
F_70 () ;
if ( V_77 -> V_67 & V_68 ) {
F_64 ( L_32 ) ;
return - 1 ;
}
return 0 ;
}
void T_1 F_71 ( void )
{
if ( V_120 ) {
F_17 ( L_33 ) ;
if ( F_72 () > 1 ) {
V_80 . V_108 = 1 ;
F_51 () ;
}
return;
}
if ( F_65 () ) {
if ( F_72 () > 1 )
F_51 () ;
return;
}
V_80 . V_67 &= ~ V_68 ;
F_51 () ;
}
void F_73 ( void )
{
F_51 () ;
}
static void F_74 ( void )
{
int V_121 = F_43 () ;
struct V_60 * V_61 = & F_75 ( V_78 , V_121 ) ;
if ( ! V_61 -> V_118 ) {
F_64 ( L_34 , V_121 ) ;
F_48 ( V_73 , V_61 ) ;
return;
}
F_21 ( V_122 ) ;
V_61 -> V_118 ( V_61 ) ;
}
T_5 void T_6 F_76 ( struct V_123 * V_124 )
{
struct V_123 * V_125 = F_77 ( V_124 ) ;
F_78 () ;
F_74 () ;
F_79 () ;
F_77 ( V_125 ) ;
}
T_5 void T_6 F_80 ( struct V_123 * V_124 )
{
struct V_123 * V_125 = F_77 ( V_124 ) ;
F_78 () ;
F_81 ( V_31 ) ;
F_74 () ;
F_82 ( V_31 ) ;
F_79 () ;
F_77 ( V_125 ) ;
}
int F_83 ( unsigned int V_126 )
{
return - V_57 ;
}
void F_84 ( void )
{
int V_127 ;
T_2 V_25 ;
if ( ! V_128 && ! V_129 )
return;
V_127 = F_30 () ;
if ( V_127 >= 3 ) {
V_25 = V_130 ;
F_25 ( V_131 , V_25 | V_35 ) ;
}
V_25 = F_11 ( V_36 ) ;
F_25 ( V_36 , V_25 | V_35 ) ;
V_25 = F_11 ( V_132 ) ;
F_25 ( V_132 , V_25 | V_35 ) ;
V_25 = F_11 ( V_133 ) ;
F_25 ( V_133 , V_25 | V_35 ) ;
if ( V_127 >= 4 ) {
V_25 = F_11 ( V_134 ) ;
F_25 ( V_134 , V_25 | V_35 ) ;
}
#ifdef F_85
if ( V_127 >= 5 ) {
V_25 = F_11 ( V_135 ) ;
F_25 ( V_135 , V_25 | V_35 ) ;
}
#endif
#ifdef F_86
if ( V_127 >= 6 ) {
V_25 = F_11 ( V_136 ) ;
if ( ! ( V_25 & V_35 ) )
F_25 ( V_136 , V_25 | V_35 ) ;
}
#endif
F_25 ( V_36 , V_35 ) ;
F_25 ( V_132 , V_35 ) ;
F_25 ( V_133 , V_35 ) ;
if ( V_127 >= 3 )
F_25 ( V_131 , V_35 ) ;
if ( V_127 >= 4 )
F_25 ( V_134 , V_35 ) ;
if ( F_12 () ) {
if ( V_127 > 3 )
F_25 ( V_137 , 0 ) ;
F_11 ( V_137 ) ;
}
}
void F_87 ( void )
{
unsigned int V_138 ;
if ( ! V_128 && ! V_129 )
return;
F_84 () ;
V_138 = F_11 ( V_139 ) ;
V_138 &= ~ V_140 ;
F_25 ( V_139 , V_138 ) ;
#ifdef V_2
if ( V_141 ) {
unsigned int V_142 , V_143 ;
F_88 ( V_144 , V_142 , V_143 ) ;
V_142 &= ~ V_145 ;
F_89 ( V_144 , V_142 , V_143 ) ;
}
#endif
}
void F_90 ( void )
{
unsigned long V_21 ;
if ( ! V_146 && ! F_91 () )
return;
F_24 ( V_21 ) ;
#ifdef V_2
if ( ! V_141 )
F_84 () ;
else
#endif
F_87 () ;
F_27 ( V_21 ) ;
}
int T_1 F_92 ( void )
{
unsigned int V_147 , V_148 ;
V_147 = F_11 ( V_7 ) ;
F_61 ( V_149 , L_35 , V_147 ) ;
F_25 ( V_7 , V_147 ^ V_150 ) ;
V_148 = F_11 ( V_7 ) ;
F_61 ( V_149 , L_35 , V_148 ) ;
if ( V_148 != V_147 )
return 0 ;
V_148 = F_10 ( V_147 ) ;
if ( V_148 == 0x00 || V_148 == 0xff )
return 0 ;
V_148 = F_30 () ;
if ( V_148 < 0x02 || V_148 == 0xff )
return 0 ;
V_147 = F_11 ( V_151 ) ;
F_61 ( V_149 , L_36 , V_147 ) ;
F_25 ( V_151 , V_147 ^ V_12 -> V_152 ) ;
V_148 = F_11 ( V_151 ) ;
F_61 ( V_149 , L_36 , V_148 ) ;
F_25 ( V_151 , V_147 ) ;
if ( V_148 != ( V_147 ^ V_12 -> V_152 ) )
return 0 ;
V_147 = F_11 ( V_132 ) ;
F_61 ( V_149 , L_37 , V_147 ) ;
V_148 = F_11 ( V_133 ) ;
F_61 ( V_149 , L_38 , V_148 ) ;
return 1 ;
}
void T_1 F_93 ( void )
{
if ( F_15 () || V_8 . V_9 == V_10 )
return;
F_94 () ;
F_61 ( V_149 , L_39 ) ;
F_25 ( V_14 , V_153 |
V_154 | V_155 ) ;
}
void T_1 F_95 ( void )
{
unsigned int V_138 ;
if ( V_156 || ! V_146 )
return;
F_84 () ;
V_138 = F_11 ( V_139 ) ;
V_138 &= ~ V_157 ;
V_138 |= V_140 ;
#ifdef V_2
if ( ( V_8 . V_9 == V_158 ) &&
( V_8 . V_11 == 15 ) )
V_138 &= ~ V_159 ;
else
#endif
V_138 |= V_159 ;
V_138 |= V_160 ;
F_25 ( V_139 , V_138 ) ;
F_25 ( V_132 , V_161 ) ;
V_138 = V_162 ;
if ( ! F_12 () )
V_138 |= V_163 ;
F_25 ( V_133 , V_138 ) ;
}
static void F_96 ( void )
{
unsigned int V_164 , V_138 , V_127 ;
if ( ! F_12 () ) {
F_17 ( L_40 ) ;
return;
}
if ( V_12 -> V_165 ) {
F_17 ( L_41 ) ;
return;
}
V_127 = F_30 () ;
if ( V_127 > 3 )
F_25 ( V_137 , 0 ) ;
V_164 = F_11 ( V_137 ) ;
V_138 = V_130 ;
F_25 ( V_131 , V_138 ) ;
if ( V_127 > 3 )
F_25 ( V_137 , 0 ) ;
V_138 = F_11 ( V_137 ) ;
if ( V_138 != V_164 )
F_61 ( V_110 , L_42
L_43 ,
V_164 , V_138 ) ;
}
void F_97 ( void )
{
int V_121 = F_43 () ;
unsigned int V_138 , V_166 ;
int V_167 , V_168 , V_169 = 0 ;
unsigned long long V_62 = 0 , V_170 ;
long long V_171 = V_172 ? V_172 : 1000000 ;
if ( V_90 )
F_46 ( V_62 ) ;
if ( V_173 ) {
F_98 () ;
return;
}
#ifdef V_2
if ( F_12 () && V_12 -> V_165 ) {
F_25 ( V_137 , 0 ) ;
F_25 ( V_137 , 0 ) ;
F_25 ( V_137 , 0 ) ;
F_25 ( V_137 , 0 ) ;
}
#endif
F_99 () ;
F_100 ( ! V_12 -> V_174 () ) ;
V_12 -> V_175 () ;
#ifdef V_2
V_167 = F_101 ( V_176 , V_121 ) ;
F_102 ( V_167 != V_177 && V_167 != F_103 () ) ;
F_101 ( V_176 , V_121 ) =
F_103 () ;
#endif
V_138 = F_11 ( V_178 ) ;
V_138 &= ~ V_179 ;
F_25 ( V_178 , V_138 ) ;
do {
V_166 = 0 ;
for ( V_167 = V_180 - 1 ; V_167 >= 0 ; V_167 -- )
V_166 |= F_11 ( V_181 + V_167 * 0x10 ) ;
for ( V_167 = V_180 - 1 ; V_167 >= 0 ; V_167 -- ) {
V_138 = F_11 ( V_182 + V_167 * 0x10 ) ;
for ( V_168 = 31 ; V_168 >= 0 ; V_168 -- ) {
if ( V_138 & ( 1 << V_168 ) ) {
F_104 () ;
V_169 ++ ;
}
}
}
if ( V_169 > 256 ) {
F_105 ( V_183 L_44 ,
V_169 ) ;
break;
}
if ( V_166 ) {
if ( V_90 && V_172 ) {
F_46 ( V_170 ) ;
V_171 = ( V_172 << 10 ) - ( V_170 - V_62 ) ;
} else
V_171 -- ;
}
} while ( V_166 && V_171 > 0 );
F_102 ( V_171 <= 0 ) ;
V_138 = F_11 ( V_139 ) ;
V_138 &= ~ V_157 ;
V_138 |= V_140 ;
#ifdef V_2
V_138 &= ~ V_159 ;
#endif
V_138 |= V_160 ;
F_25 ( V_139 , V_138 ) ;
V_138 = F_11 ( V_132 ) & V_35 ;
if ( ! V_121 && ( V_184 || ! V_138 ) ) {
V_138 = V_161 ;
F_61 ( V_110 , L_45 , V_121 ) ;
} else {
V_138 = V_161 | V_35 ;
F_61 ( V_110 , L_46 , V_121 ) ;
}
F_25 ( V_132 , V_138 ) ;
if ( ! V_121 )
V_138 = V_162 ;
else
V_138 = V_162 | V_35 ;
if ( ! F_12 () )
V_138 |= V_163 ;
F_25 ( V_133 , V_138 ) ;
#ifdef F_86
if ( ! V_121 )
F_106 () ;
#endif
}
static void F_107 ( void )
{
F_96 () ;
#ifdef V_2
{
unsigned int V_138 ;
V_138 = F_11 ( V_36 ) ;
V_138 |= ( V_35 | V_31 ) ;
F_25 ( V_36 , V_138 ) ;
}
#endif
F_108 () ;
}
void F_109 ( void )
{
F_97 () ;
F_107 () ;
}
static inline void F_110 ( void )
{
T_3 V_185 ;
if ( V_146 )
return;
F_111 ( V_144 , V_185 ) ;
if ( ! ( V_185 & V_186 ) )
return;
F_47 ( V_144 , V_185 & ~ ( V_186 | V_187 ) ) ;
F_47 ( V_144 , V_185 & ~ V_186 ) ;
F_35 ( V_188 L_47 ) ;
}
static inline void F_112 ( void )
{
T_3 V_185 ;
F_111 ( V_144 , V_185 ) ;
if ( V_185 & V_186 )
return;
F_47 ( V_144 , V_185 | V_186 ) ;
F_35 ( V_188 L_48 ) ;
}
static int T_1 F_113 ( char * V_189 )
{
if ( F_114 () ) {
int V_190 = F_115 ( V_151 ) ;
if ( V_190 >= 255 ) {
F_64 ( L_49 ,
V_190 ) ;
return 0 ;
}
F_64 ( L_50 ) ;
F_110 () ;
}
F_6 ( V_191 ) ;
V_192 = V_193 ;
V_128 = 0 ;
return 0 ;
}
void F_116 ( void )
{
if ( V_192 != V_194 ) {
F_110 () ;
return;
}
F_112 () ;
}
static T_1 void F_117 ( void )
{
T_2 V_195 ;
if ( V_192 != V_194 )
goto V_196;
V_195 = F_118 () ;
if ( V_195 >= 255 )
F_119 ( L_51 , V_195 ) ;
F_110 () ;
F_120 ( V_197 ) ;
V_196:
V_192 = V_193 ;
V_128 = 0 ;
}
static T_1 void F_121 ( void )
{
if ( V_192 != V_198 )
return;
V_128 = 1 ;
V_192 = V_194 ;
F_112 () ;
}
static T_1 void F_122 ( int V_199 )
{
if ( V_192 == V_193 )
return;
if ( V_199 != V_200 ) {
if ( V_201 > 255 ||
! F_123 () ) {
F_17 ( L_52 ) ;
F_117 () ;
return;
}
V_202 = 1 ;
}
F_121 () ;
}
void T_1 F_124 ( void )
{
if ( F_114 () ) {
F_17 ( L_53 ) ;
V_128 = 1 ;
V_192 = V_194 ;
} else if ( ! V_203 ) {
V_192 = V_193 ;
}
}
static int T_1 F_125 ( void )
{
if ( ! F_126 () )
return 0 ;
F_119 ( L_54 ) ;
}
static inline void F_122 ( int V_199 ) { }
static inline void F_112 ( void ) { }
static int T_1 F_127 ( void )
{
#ifdef F_128
if ( ! F_114 () && V_204 ) {
F_17 ( L_55 ) ;
return - 1 ;
}
#endif
return F_129 () ;
}
void T_1 F_130 ( void )
{
unsigned long V_21 ;
int V_205 , V_206 ;
V_206 = F_131 () ;
if ( V_206 < 0 && ! F_132 () )
return;
V_205 = F_133 () ;
if ( V_205 ) {
F_17 ( L_56 , V_205 ) ;
return;
}
F_24 ( V_21 ) ;
V_207 -> V_208 () ;
F_134 () ;
if ( V_206 >= 0 )
V_206 = F_127 () ;
F_122 ( V_206 ) ;
if ( V_206 < 0 )
F_135 () ;
V_207 -> V_209 () ;
F_27 ( V_21 ) ;
}
static int T_1 F_136 ( void )
{
if ( ! V_146 ) {
F_17 ( L_57 ) ;
return - 1 ;
}
V_197 = V_210 ;
return 0 ;
}
static int T_1 F_137 ( void )
{
T_2 V_67 , V_143 , V_142 ;
V_67 = F_138 ( 1 ) ;
if ( ! ( V_67 & ( 1 << V_211 ) ) ) {
F_64 ( L_58 ) ;
return - 1 ;
}
F_139 ( & V_8 , V_211 ) ;
V_197 = V_210 ;
if ( V_8 . V_11 >= 6 ) {
F_88 ( V_144 , V_142 , V_143 ) ;
if ( V_142 & V_145 )
V_197 = V_142 & V_212 ;
}
F_17 ( L_59 ) ;
return 0 ;
}
int T_1 F_140 ( unsigned long V_213 )
{
T_2 V_143 , V_142 ;
if ( V_173 )
return - 1 ;
if ( V_8 . V_11 >= 6 ) {
F_88 ( V_144 , V_142 , V_143 ) ;
if ( ! ( V_142 & V_145 ) ) {
F_17 ( L_60 ) ;
V_142 &= ~ V_212 ;
V_142 |= V_145 | V_213 ;
F_89 ( V_144 , V_142 , V_143 ) ;
V_141 = 1 ;
}
}
return F_137 () ;
}
static int T_1 F_136 ( void )
{
if ( V_173 )
return - 1 ;
switch ( V_8 . V_9 ) {
case V_10 :
if ( ( V_8 . V_11 == 6 && V_8 . V_214 > 1 ) ||
( V_8 . V_11 >= 15 ) )
break;
goto V_215;
case V_158 :
if ( V_8 . V_11 == 6 || V_8 . V_11 == 15 ||
( V_8 . V_11 == 5 && V_146 ) )
break;
goto V_215;
default:
goto V_215;
}
if ( ! V_146 ) {
if ( ! V_3 ) {
F_17 ( L_61
L_62 ) ;
return - 1 ;
}
if ( F_140 ( V_210 ) )
return - 1 ;
} else {
if ( F_137 () )
return - 1 ;
}
F_108 () ;
return 0 ;
V_215:
F_17 ( L_63 ) ;
return - 1 ;
}
void T_1 F_141 ( void )
{
unsigned int V_216 ;
if ( V_128 ) {
V_217 = F_118 () ;
return;
}
if ( ! V_156 && F_136 () ) {
F_17 ( L_64 ) ;
F_16 () ;
} else {
V_129 = V_197 ;
if ( ! V_218 && ! V_156 )
F_120 ( V_129 ) ;
}
V_216 = F_118 () ;
if ( V_217 != V_216 ) {
V_217 = V_216 ;
V_219 [ V_216 ] =
F_10 ( F_11 ( V_7 ) ) ;
}
}
void T_1 F_120 ( unsigned long V_220 )
{
V_197 = V_220 ;
if ( ! V_128 ) {
F_142 ( V_221 , V_220 ) ;
F_61 ( V_110 , L_65 ,
V_222 , V_197 ) ;
}
if ( V_217 == - 1U ) {
V_217 = F_118 () ;
V_219 [ V_217 ] =
F_10 ( F_11 ( V_7 ) ) ;
}
}
static inline void F_143 ( T_4 V_49 )
{
T_2 V_25 ;
V_25 = F_11 ( V_182 + ( ( V_49 & ~ 0x1f ) >> 1 ) ) ;
if ( V_25 & ( 1 << ( V_49 & 0x1f ) ) )
F_104 () ;
F_21 ( V_223 ) ;
F_17 ( L_66
L_67 , V_49 , F_43 () ) ;
}
T_5 void F_144 ( struct V_123 * V_124 )
{
F_145 () ;
F_143 ( ~ V_124 -> V_224 ) ;
F_79 () ;
}
T_5 void F_146 ( struct V_123 * V_124 )
{
T_4 V_49 = ~ V_124 -> V_224 ;
F_145 () ;
F_147 ( V_49 ) ;
F_143 ( V_49 ) ;
F_148 ( V_49 ) ;
F_79 () ;
}
static inline void F_149 ( struct V_123 * V_124 )
{
T_2 V_25 ;
T_2 V_167 = 0 ;
static const char * const V_225 [] = {
L_68 ,
L_69 ,
L_70 ,
L_71 ,
L_72 ,
L_73 ,
L_74 ,
L_75 ,
} ;
if ( F_30 () > 3 )
F_25 ( V_137 , 0 ) ;
V_25 = F_11 ( V_137 ) ;
F_104 () ;
F_150 ( & V_226 ) ;
F_61 ( V_149 , V_37 L_76 ,
F_43 () , V_25 ) ;
V_25 &= 0xff ;
while ( V_25 ) {
if ( V_25 & 0x1 )
F_61 ( V_149 , V_227 L_77 , V_225 [ V_167 ] ) ;
V_167 ++ ;
V_25 >>= 1 ;
}
F_61 ( V_149 , V_227 L_78 ) ;
}
T_5 void F_151 ( struct V_123 * V_124 )
{
F_145 () ;
F_149 ( V_124 ) ;
F_79 () ;
}
T_5 void F_152 ( struct V_123 * V_124 )
{
F_145 () ;
F_153 ( V_130 ) ;
F_149 ( V_124 ) ;
F_154 ( V_130 ) ;
F_79 () ;
}
static void T_1 F_155 ( void )
{
#ifdef V_2
if ( V_184 ) {
F_84 () ;
F_61 ( V_110 , L_79
L_80 ) ;
F_1 () ;
}
#endif
}
void F_156 ( int V_228 )
{
unsigned int V_138 ;
#ifdef V_2
if ( V_184 ) {
F_61 ( V_110 , L_81
L_82 ) ;
F_3 () ;
return;
}
#endif
V_138 = F_11 ( V_139 ) ;
V_138 &= ~ V_157 ;
V_138 |= V_140 ;
V_138 |= 0xf ;
F_25 ( V_139 , V_138 ) ;
if ( ! V_228 ) {
V_138 = F_11 ( V_132 ) ;
V_138 &= ~ ( V_229 | V_230 |
V_231 | V_232 |
V_163 | V_35 ) ;
V_138 |= V_232 | V_230 ;
V_138 = F_157 ( V_138 , V_233 ) ;
F_25 ( V_132 , V_138 ) ;
} else {
F_25 ( V_132 , V_35 ) ;
}
V_138 = F_11 ( V_133 ) ;
V_138 &= ~ ( V_229 | V_230 |
V_231 | V_232 |
V_163 | V_35 ) ;
V_138 |= V_232 | V_230 ;
V_138 = F_157 ( V_138 , V_234 ) ;
F_25 ( V_133 , V_138 ) ;
}
int F_158 ( int V_190 , int V_235 )
{
int V_121 , V_236 = V_237 ;
bool V_238 = F_159 ( V_217 ,
V_239 ) ;
if ( V_240 != V_177 &&
V_240 != F_118 () &&
V_240 == V_190 ) {
int V_241 = V_242 + V_243 ;
F_64 ( L_83
L_84 ,
V_241 , V_190 ) ;
V_243 ++ ;
return - V_244 ;
}
if ( ! V_238 && V_242 >= V_237 - 1 &&
V_190 != V_217 ) {
int V_241 = V_236 + V_243 - 1 ;
F_64 (
L_85
L_86
L_87 , V_236 , V_241 , V_190 ) ;
V_243 ++ ;
return - V_244 ;
}
if ( V_242 >= V_237 ) {
int V_241 = V_236 + V_243 ;
F_64 (
L_88
L_87 , V_236 , V_241 , V_190 ) ;
V_243 ++ ;
return - V_57 ;
}
V_242 ++ ;
if ( V_190 == V_217 ) {
V_121 = 0 ;
} else
V_121 = F_160 ( - 1 , V_245 ) ;
if ( V_235 == 0x0 ) {
F_64 ( L_89 ,
V_121 , V_190 ) ;
V_235 = 0x10 ;
}
V_219 [ V_190 ] = V_235 ;
if ( V_235 != V_219 [ V_217 ] ) {
F_64 ( L_90 ,
V_219 [ V_217 ] , V_121 , V_235 ) ;
}
F_161 ( V_190 , V_239 ) ;
if ( V_190 > V_201 )
V_201 = V_190 ;
#if F_162 ( F_50 ) || F_162 ( F_13 )
F_101 ( V_246 , V_121 ) = V_190 ;
F_101 ( V_247 , V_121 ) = V_190 ;
#endif
#ifdef V_2
F_101 ( V_176 , V_121 ) =
V_12 -> V_248 ( V_121 ) ;
#endif
F_163 ( V_121 , true ) ;
F_164 ( V_121 , true ) ;
return V_121 ;
}
int F_165 ( void )
{
return F_118 () ;
}
void F_166 ( void )
{
unsigned long V_249 ;
F_25 ( V_250 , V_251 ) ;
V_249 = F_11 ( V_252 ) & ~ V_253 ;
V_249 |= F_167 ( 1UL << F_43 () ) ;
F_25 ( V_252 , V_249 ) ;
}
int F_168 ( const struct V_75 * V_75 ,
const struct V_75 * V_254 ,
unsigned int * V_190 )
{
unsigned int V_121 ;
F_169 (cpu, cpumask, andmask) {
if ( F_170 ( V_121 , V_255 ) )
break;
}
if ( F_171 ( V_121 < V_237 ) ) {
* V_190 = F_75 ( V_246 , V_121 ) ;
return 0 ;
}
return - V_57 ;
}
void T_1 F_172 ( void (* F_173)( T_2 V_54 , T_2 V_25 ) )
{
struct V_12 * * V_256 ;
for ( V_256 = V_257 ; V_256 < V_258 ; V_256 ++ ) {
F_102 ( ( * V_256 ) -> F_173 == F_173 ) ;
( * V_256 ) -> F_173 = F_173 ;
}
}
static void T_1 F_174 ( void )
{
#ifdef F_13
F_25 ( V_151 , F_175 ( V_217 ) ) ;
#else
# ifdef F_176
V_217 = F_118 () ;
# endif
#endif
F_177 ( V_217 , & V_239 ) ;
}
int T_1 F_178 ( bool V_259 )
{
int V_20 ;
F_155 () ;
if ( V_259 )
F_174 () ;
F_97 () ;
if ( V_128 )
V_20 = F_11 ( V_252 ) ;
else
V_20 = F_179 ( F_11 ( V_252 ) ) ;
F_180 () ;
F_107 () ;
F_181 () ;
F_182 () ;
V_260 . V_261 . V_262 () ;
return V_20 ;
}
int T_1 F_183 ( void )
{
if ( V_173 ) {
F_17 ( L_91 ) ;
return - 1 ;
}
#ifdef F_13
if ( ! V_146 ) {
V_173 = 1 ;
F_17 ( L_92 ) ;
return - 1 ;
}
#else
if ( ! V_156 && ! V_146 )
return - 1 ;
if ( ! V_146 &&
F_14 ( V_219 [ V_217 ] ) ) {
F_42 ( L_93 ,
V_217 ) ;
return - 1 ;
}
#endif
if ( ! V_156 )
F_98 () ;
F_184 () ;
F_92 () ;
F_178 ( true ) ;
return 0 ;
}
void T_1 F_185 ( void )
{
F_183 () ;
}
static int F_186 ( void )
{
unsigned long V_21 ;
int V_127 ;
if ( ! V_263 . V_264 )
return 0 ;
V_127 = F_30 () ;
V_263 . V_265 = F_11 ( V_151 ) ;
V_263 . V_266 = F_11 ( V_178 ) ;
V_263 . V_267 = F_11 ( V_252 ) ;
V_263 . V_268 = F_11 ( V_250 ) ;
V_263 . V_269 = F_11 ( V_139 ) ;
V_263 . V_270 = F_11 ( V_36 ) ;
if ( V_127 >= 4 )
V_263 . V_271 = F_11 ( V_134 ) ;
V_263 . V_272 = F_11 ( V_132 ) ;
V_263 . V_273 = F_11 ( V_133 ) ;
V_263 . V_274 = F_11 ( V_131 ) ;
V_263 . V_275 = F_11 ( V_42 ) ;
V_263 . V_276 = F_11 ( V_38 ) ;
#ifdef F_85
if ( V_127 >= 5 )
V_263 . V_277 = F_11 ( V_135 ) ;
#endif
F_24 ( V_21 ) ;
F_87 () ;
F_187 () ;
F_27 ( V_21 ) ;
return 0 ;
}
static void F_188 ( void )
{
unsigned int V_142 , V_143 ;
unsigned long V_21 ;
int V_127 ;
if ( ! V_263 . V_264 )
return;
F_24 ( V_21 ) ;
F_134 () ;
V_207 -> V_208 () ;
if ( V_128 ) {
F_112 () ;
} else {
if ( V_8 . V_11 >= 6 ) {
F_88 ( V_144 , V_142 , V_143 ) ;
V_142 &= ~ V_212 ;
V_142 |= V_145 | V_197 ;
F_89 ( V_144 , V_142 , V_143 ) ;
}
}
V_127 = F_30 () ;
F_25 ( V_131 , V_130 | V_35 ) ;
F_25 ( V_151 , V_263 . V_265 ) ;
F_25 ( V_250 , V_263 . V_268 ) ;
F_25 ( V_252 , V_263 . V_267 ) ;
F_25 ( V_178 , V_263 . V_266 ) ;
F_25 ( V_139 , V_263 . V_269 ) ;
F_25 ( V_132 , V_263 . V_272 ) ;
F_25 ( V_133 , V_263 . V_273 ) ;
#if F_162 ( F_86 )
if ( V_127 >= 5 )
F_25 ( V_135 , V_263 . V_277 ) ;
#endif
if ( V_127 >= 4 )
F_25 ( V_134 , V_263 . V_271 ) ;
F_25 ( V_36 , V_263 . V_270 ) ;
F_25 ( V_38 , V_263 . V_276 ) ;
F_25 ( V_42 , V_263 . V_275 ) ;
F_25 ( V_137 , 0 ) ;
F_11 ( V_137 ) ;
F_25 ( V_131 , V_263 . V_274 ) ;
F_25 ( V_137 , 0 ) ;
F_11 ( V_137 ) ;
F_189 ( V_128 ) ;
F_27 ( V_21 ) ;
}
static void F_108 ( void )
{
V_263 . V_264 = 1 ;
}
static int T_1 F_190 ( void )
{
if ( V_146 )
F_191 ( & V_278 ) ;
return 0 ;
}
static void F_108 ( void ) { }
static int F_192 ( const struct V_279 * V_280 )
{
if ( V_281 )
return 0 ;
F_17 ( L_94 , V_280 -> V_282 ) ;
V_281 = 1 ;
return 0 ;
}
static void F_193 ( void )
{
if ( V_283 )
return;
F_194 ( V_284 ) ;
V_283 = 1 ;
}
int F_195 ( void )
{
F_193 () ;
return V_281 ;
}
static int T_1 F_196 ( char * V_1 )
{
V_173 = 1 ;
F_6 ( V_211 ) ;
return 0 ;
}
static int T_1 F_197 ( char * V_1 )
{
return F_196 ( V_1 ) ;
}
static int T_1 F_198 ( char * V_1 )
{
V_285 = 1 ;
return 0 ;
}
static int T_1 F_199 ( char * V_1 )
{
V_120 = 1 ;
return 0 ;
}
static int T_1 F_200 ( char * V_1 )
{
V_120 = 1 ;
return 0 ;
}
static int T_1 F_201 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_13
V_204 = 0 ;
return 0 ;
#endif
return - V_57 ;
}
if ( strcmp ( L_95 , V_1 ) == 0 )
V_286 = V_149 ;
else if ( strcmp ( L_96 , V_1 ) == 0 )
V_286 = V_110 ;
else {
F_64 ( L_97
L_98 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_1 F_202 ( void )
{
if ( ! V_129 )
return - 1 ;
V_287 . V_288 = V_129 ;
V_287 . V_289 = V_287 . V_288 + V_290 - 1 ;
F_203 ( & V_291 , & V_287 ) ;
return 0 ;
}
static int T_1 F_204 ( char * V_1 )
{
if ( ! V_1 || ! F_205 ( & V_1 , & V_240 ) )
return - V_57 ;
return 0 ;
}
