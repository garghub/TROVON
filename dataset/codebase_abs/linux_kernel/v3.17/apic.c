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
static int T_1 F_9 ( char * V_7 )
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
V_11 = true ;
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
unsigned long V_26 ;
F_28 ( V_26 ) ;
F_29 ( V_27 , F_30 ( V_25 ) ) ;
F_29 ( V_19 , V_24 ) ;
F_31 ( V_26 ) ;
}
T_3 F_32 ( void )
{
T_2 V_28 , V_29 ;
V_29 = F_15 ( V_27 ) ;
V_28 = F_15 ( V_19 ) ;
return V_28 | ( ( T_3 ) V_29 << 32 ) ;
}
int F_33 ( void )
{
return F_19 () ? 0xff : 0xf ;
}
int F_34 ( void )
{
unsigned int V_30 ;
V_30 = F_15 ( V_12 ) ;
return F_18 ( F_14 ( V_30 ) ) ? F_35 ( V_30 ) : 2 ;
}
static void F_36 ( unsigned int V_31 , int V_32 , int V_33 )
{
unsigned int V_34 , V_35 ;
V_34 = V_36 ;
if ( ! V_32 )
V_34 |= V_37 ;
else if ( F_37 ( V_4 ) )
V_34 |= V_38 ;
if ( ! F_16 () )
V_34 |= F_38 ( V_39 ) ;
if ( ! V_33 )
V_34 |= V_40 ;
F_29 ( V_41 , V_34 ) ;
if ( V_34 & V_38 ) {
F_39 ( V_42 L_5 ) ;
return;
}
V_35 = F_15 ( V_43 ) ;
F_29 ( V_43 ,
( V_35 & ~ ( V_44 | V_45 ) ) |
V_46 ) ;
if ( ! V_32 )
F_29 ( V_47 , V_31 / V_48 ) ;
}
static inline int F_40 ( unsigned int V_49 , unsigned int V_50 )
{
return ( V_49 & V_51 )
|| ( V_50 == V_51 )
|| ( ( V_50 & ~ V_51 ) == V_49 ) ;
}
static unsigned int F_41 ( int V_52 , unsigned int V_50 )
{
unsigned int V_53 , V_54 ;
if ( V_52 >= V_55 )
return ~ 0 ;
V_53 = F_42 ( & V_56 [ V_52 ] ) ;
do {
V_54 = V_53 & ~ V_51 ;
if ( V_54 && ! F_40 ( V_54 , V_50 ) )
return V_53 ;
V_53 = F_43 ( & V_56 [ V_52 ] , V_53 , V_50 ) ;
} while ( V_53 != V_50 );
V_53 &= ~ V_51 ;
if ( V_53 && V_53 != V_54 )
F_21 ( L_6 ,
V_52 , V_53 ) ;
return V_50 ;
}
int F_44 ( T_4 V_52 , T_4 V_54 , T_4 V_57 , T_4 V_58 )
{
unsigned long V_59 = F_45 ( V_52 ) ;
unsigned int V_50 , V_49 , V_60 ;
V_50 = ( V_58 << 16 ) | ( V_57 << 8 ) | V_54 ;
V_49 = F_15 ( V_59 ) ;
V_60 = F_41 ( V_52 , V_50 ) ;
if ( V_60 != V_50 ) {
F_46 ( V_61 L_7
L_8
L_9 ,
F_47 () , V_59 , V_52 , V_50 , V_60 ) ;
return - V_62 ;
}
if ( ! F_40 ( V_49 , V_50 ) ) {
F_46 ( V_61 L_7
L_8
L_10 ,
F_47 () , V_59 , V_52 , V_50 , V_49 ) ;
return - V_63 ;
}
F_29 ( V_59 , V_50 ) ;
return 0 ;
}
static int F_48 ( unsigned long V_64 ,
struct V_65 * V_66 )
{
F_29 ( V_47 , V_64 ) ;
return 0 ;
}
static int F_49 ( unsigned long V_64 ,
struct V_65 * V_66 )
{
T_3 V_67 ;
F_50 ( V_67 ) ;
F_51 ( V_68 , V_67 + ( ( ( T_3 ) V_64 ) * V_69 ) ) ;
return 0 ;
}
static void F_52 ( enum V_70 V_71 ,
struct V_65 * V_66 )
{
unsigned long V_26 ;
unsigned int V_30 ;
if ( V_66 -> V_72 & V_73 )
return;
F_28 ( V_26 ) ;
switch ( V_71 ) {
case V_74 :
case V_75 :
F_36 ( V_76 ,
V_71 != V_74 , 1 ) ;
break;
case V_77 :
case V_78 :
V_30 = F_15 ( V_41 ) ;
V_30 |= ( V_40 | V_36 ) ;
F_29 ( V_41 , V_30 ) ;
F_29 ( V_47 , 0 ) ;
break;
case V_79 :
break;
}
F_31 ( V_26 ) ;
}
static void F_53 ( const struct V_80 * V_58 )
{
#ifdef F_54
V_17 -> V_81 ( V_58 , V_36 ) ;
#endif
}
static void F_55 ( void )
{
struct V_65 * V_82 = & F_56 ( V_83 ) ;
if ( F_57 ( V_84 ) ) {
V_85 . V_72 &= ~ V_86 ;
V_85 . V_87 = 150 ;
}
memcpy ( V_82 , & V_85 , sizeof( * V_82 ) ) ;
V_82 -> V_80 = F_58 ( F_47 () ) ;
if ( F_57 ( V_4 ) ) {
V_82 -> V_72 &= ~ ( V_88 |
V_73 ) ;
V_82 -> V_89 = F_49 ;
F_59 ( V_82 ,
( V_90 / V_69 ) * 1000 ,
0xF , ~ 0UL ) ;
} else
F_60 ( V_82 ) ;
}
static void T_1 F_61 ( struct V_65 * V_91 )
{
unsigned long long V_67 = 0 ;
long V_92 = F_15 ( V_93 ) ;
unsigned long V_94 = F_62 () ;
if ( V_95 )
F_50 ( V_67 ) ;
switch ( V_96 ++ ) {
case 0 :
V_97 = V_92 ;
V_98 = V_67 ;
V_99 = V_94 ;
V_100 = V_101 ;
break;
case V_102 :
V_103 = V_92 ;
V_104 = V_67 ;
if ( V_94 < V_99 )
V_94 += V_105 ;
V_106 = V_94 ;
V_107 = V_101 ;
break;
}
}
static int T_1
F_63 ( long V_108 , long * V_64 , long * V_109 )
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
V_114 = ( ( ( T_3 ) ( * V_64 ) ) * V_110 ) ;
F_67 ( V_114 , V_108 ) ;
F_21 ( L_15
L_16 , ( unsigned long ) V_114 , * V_64 ) ;
* V_64 = ( long ) V_114 ;
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
struct V_65 * V_82 = & F_56 ( V_83 ) ;
void (* F_69)( struct V_65 * V_91 );
unsigned long V_116 ;
long V_64 , V_109 ;
int V_117 = 0 ;
if ( F_37 ( V_4 ) ) {
return 0 ;
} else if ( V_76 ) {
F_65 ( V_115 , L_19 ,
V_76 ) ;
V_85 . V_113 = F_70 ( V_76 / V_48 ,
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
F_36 ( 0xffffffff , 0 , 0 ) ;
F_73 () ;
while ( V_96 <= V_102 )
F_23 () ;
F_72 () ;
V_122 -> V_123 = F_69 ;
V_64 = V_97 - V_103 ;
F_65 ( V_115 , L_22 , V_64 ) ;
V_109 = ( long ) ( V_104 - V_98 ) ;
V_117 = ! F_63 ( V_106 - V_99 ,
& V_64 , & V_109 ) ;
V_85 . V_113 = F_70 ( V_64 , V_118 * V_102 ,
V_85 . V_119 ) ;
V_85 . V_120 =
F_71 ( 0x7FFFFFFF , & V_85 ) ;
V_85 . V_121 =
F_71 ( 0xF , & V_85 ) ;
V_76 = ( V_64 * V_48 ) / V_102 ;
F_65 ( V_115 , L_23 , V_64 ) ;
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
F_52 ( V_74 , V_82 ) ;
V_96 = - 1 ;
F_73 () ;
while ( V_96 <= V_102 )
F_23 () ;
F_52 ( V_78 , V_82 ) ;
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
void F_76 ( void )
{
F_55 () ;
}
static void F_77 ( void )
{
int V_126 = F_47 () ;
struct V_65 * V_66 = & F_78 ( V_83 , V_126 ) ;
if ( ! V_66 -> V_123 ) {
F_12 ( L_36 , V_126 ) ;
F_52 ( V_78 , V_66 ) ;
return;
}
F_25 ( V_127 ) ;
V_66 -> V_123 ( V_66 ) ;
}
T_5 void T_6 F_79 ( struct V_128 * V_129 )
{
struct V_128 * V_130 = F_80 ( V_129 ) ;
F_81 () ;
F_77 () ;
F_82 () ;
F_80 ( V_130 ) ;
}
T_5 void T_6 F_83 ( struct V_128 * V_129 )
{
struct V_128 * V_130 = F_80 ( V_129 ) ;
F_81 () ;
F_84 ( V_36 ) ;
F_77 () ;
F_85 ( V_36 ) ;
F_82 () ;
F_80 ( V_130 ) ;
}
int F_86 ( unsigned int V_131 )
{
return - V_62 ;
}
void F_87 ( void )
{
int V_132 ;
T_2 V_30 ;
if ( ! V_133 && ! V_134 )
return;
V_132 = F_34 () ;
if ( V_132 >= 3 ) {
V_30 = V_135 ;
F_29 ( V_136 , V_30 | V_40 ) ;
}
V_30 = F_15 ( V_41 ) ;
F_29 ( V_41 , V_30 | V_40 ) ;
V_30 = F_15 ( V_137 ) ;
F_29 ( V_137 , V_30 | V_40 ) ;
V_30 = F_15 ( V_138 ) ;
F_29 ( V_138 , V_30 | V_40 ) ;
if ( V_132 >= 4 ) {
V_30 = F_15 ( V_139 ) ;
F_29 ( V_139 , V_30 | V_40 ) ;
}
#ifdef F_88
if ( V_132 >= 5 ) {
V_30 = F_15 ( V_140 ) ;
F_29 ( V_140 , V_30 | V_40 ) ;
}
#endif
#ifdef F_89
if ( V_132 >= 6 ) {
V_30 = F_15 ( V_141 ) ;
if ( ! ( V_30 & V_40 ) )
F_29 ( V_141 , V_30 | V_40 ) ;
}
#endif
F_29 ( V_41 , V_40 ) ;
F_29 ( V_137 , V_40 ) ;
F_29 ( V_138 , V_40 ) ;
if ( V_132 >= 3 )
F_29 ( V_136 , V_40 ) ;
if ( V_132 >= 4 )
F_29 ( V_139 , V_40 ) ;
if ( F_16 () ) {
if ( V_132 > 3 )
F_29 ( V_142 , 0 ) ;
F_15 ( V_142 ) ;
}
}
void F_90 ( void )
{
unsigned int V_143 ;
if ( ! V_133 && ! V_134 )
return;
F_87 () ;
V_143 = F_15 ( V_144 ) ;
V_143 &= ~ V_145 ;
F_29 ( V_144 , V_143 ) ;
#ifdef V_2
if ( V_146 ) {
unsigned int V_147 , V_148 ;
F_91 ( V_149 , V_147 , V_148 ) ;
V_147 &= ~ V_150 ;
F_92 ( V_149 , V_147 , V_148 ) ;
}
#endif
}
void F_93 ( void )
{
unsigned long V_26 ;
if ( ! V_151 && ! F_94 () )
return;
F_28 ( V_26 ) ;
#ifdef V_2
if ( ! V_146 )
F_87 () ;
else
#endif
F_90 () ;
F_31 ( V_26 ) ;
}
int T_1 F_95 ( void )
{
unsigned int V_152 , V_153 ;
V_152 = F_15 ( V_12 ) ;
F_65 ( V_154 , L_37 , V_152 ) ;
F_29 ( V_12 , V_152 ^ V_155 ) ;
V_153 = F_15 ( V_12 ) ;
F_65 ( V_154 , L_37 , V_153 ) ;
if ( V_153 != V_152 )
return 0 ;
V_153 = F_14 ( V_152 ) ;
if ( V_153 == 0x00 || V_153 == 0xff )
return 0 ;
V_153 = F_34 () ;
if ( V_153 < 0x02 || V_153 == 0xff )
return 0 ;
V_152 = F_15 ( V_9 ) ;
F_65 ( V_154 , L_38 , V_152 ) ;
F_29 ( V_9 , V_152 ^ V_17 -> V_156 ) ;
V_153 = F_15 ( V_9 ) ;
F_65 ( V_154 , L_38 , V_153 ) ;
F_29 ( V_9 , V_152 ) ;
if ( V_153 != ( V_152 ^ V_17 -> V_156 ) )
return 0 ;
V_152 = F_15 ( V_137 ) ;
F_65 ( V_154 , L_39 , V_152 ) ;
V_153 = F_15 ( V_138 ) ;
F_65 ( V_154 , L_40 , V_153 ) ;
return 1 ;
}
void T_1 F_96 ( void )
{
if ( F_19 () || V_13 . V_14 == V_15 )
return;
F_97 () ;
F_65 ( V_154 , L_41 ) ;
F_29 ( V_19 , V_157 |
V_158 | V_159 ) ;
}
void T_1 F_98 ( void )
{
unsigned int V_143 ;
if ( V_160 || ! V_151 )
return;
F_87 () ;
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
F_29 ( V_144 , V_143 ) ;
F_29 ( V_137 , V_165 ) ;
V_143 = V_166 ;
if ( ! F_16 () )
V_143 |= V_167 ;
F_29 ( V_138 , V_143 ) ;
}
static void F_99 ( void )
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
V_132 = F_34 () ;
if ( V_132 > 3 )
F_29 ( V_142 , 0 ) ;
V_168 = F_15 ( V_142 ) ;
V_143 = V_135 ;
F_29 ( V_136 , V_143 ) ;
if ( V_132 > 3 )
F_29 ( V_142 , 0 ) ;
V_143 = F_15 ( V_142 ) ;
if ( V_143 != V_168 )
F_65 ( V_115 , L_44
L_45 ,
V_168 , V_143 ) ;
}
void F_100 ( void )
{
int V_126 = F_47 () ;
unsigned int V_143 , V_170 ;
int V_171 , V_172 , V_173 = 0 ;
unsigned long long V_67 = 0 , V_174 ;
long long V_175 = V_176 ;
if ( V_95 )
F_50 ( V_67 ) ;
if ( V_177 ) {
F_101 () ;
return;
}
#ifdef V_2
if ( F_16 () && V_17 -> V_169 ) {
F_29 ( V_142 , 0 ) ;
F_29 ( V_142 , 0 ) ;
F_29 ( V_142 , 0 ) ;
F_29 ( V_142 , 0 ) ;
}
#endif
F_102 () ;
F_103 ( ! V_17 -> V_178 () ) ;
V_17 -> V_179 () ;
#ifdef V_2
V_171 = F_104 ( V_180 , V_126 ) ;
F_105 ( V_171 != V_181 && V_171 != F_106 () ) ;
F_104 ( V_180 , V_126 ) =
F_106 () ;
#endif
V_143 = F_15 ( V_182 ) ;
V_143 &= ~ V_183 ;
F_29 ( V_182 , V_143 ) ;
do {
V_170 = 0 ;
for ( V_171 = V_184 - 1 ; V_171 >= 0 ; V_171 -- )
V_170 |= F_15 ( V_185 + V_171 * 0x10 ) ;
for ( V_171 = V_184 - 1 ; V_171 >= 0 ; V_171 -- ) {
V_143 = F_15 ( V_186 + V_171 * 0x10 ) ;
for ( V_172 = 31 ; V_172 >= 0 ; V_172 -- ) {
if ( V_143 & ( 1 << V_172 ) ) {
F_107 () ;
V_173 ++ ;
}
}
}
if ( V_173 > 256 ) {
F_108 ( V_187 L_46 ,
V_173 ) ;
break;
}
if ( V_170 ) {
if ( V_95 ) {
F_50 ( V_174 ) ;
V_175 = ( V_176 << 10 ) - ( V_174 - V_67 ) ;
} else
V_175 -- ;
}
} while ( V_170 && V_175 > 0 );
F_105 ( V_175 <= 0 ) ;
V_143 = F_15 ( V_144 ) ;
V_143 &= ~ V_161 ;
V_143 |= V_145 ;
#ifdef V_2
V_143 &= ~ V_163 ;
#endif
V_143 |= V_164 ;
F_29 ( V_144 , V_143 ) ;
V_143 = F_15 ( V_137 ) & V_40 ;
if ( ! V_126 && ( V_188 || ! V_143 ) ) {
V_143 = V_165 ;
F_65 ( V_115 , L_47 , V_126 ) ;
} else {
V_143 = V_165 | V_40 ;
F_65 ( V_115 , L_48 , V_126 ) ;
}
F_29 ( V_137 , V_143 ) ;
if ( ! V_126 )
V_143 = V_166 ;
else
V_143 = V_166 | V_40 ;
if ( ! F_16 () )
V_143 |= V_167 ;
F_29 ( V_138 , V_143 ) ;
#ifdef F_89
if ( ! V_126 )
F_109 () ;
#endif
}
void F_110 ( void )
{
F_99 () ;
#ifdef V_2
{
unsigned int V_143 ;
V_143 = F_15 ( V_41 ) ;
V_143 |= ( V_40 | V_36 ) ;
F_29 ( V_41 , V_143 ) ;
}
#endif
F_111 () ;
}
void T_1 F_112 ( void )
{
F_110 () ;
F_113 () ;
}
static inline void F_114 ( T_3 V_189 )
{
F_51 ( V_149 ,
V_189 & ~ ( V_190 | V_191 ) ) ;
F_51 ( V_149 , V_189 & ~ V_190 ) ;
}
static T_1 void F_115 ( void )
{
T_3 V_189 ;
if ( ! V_192 )
return;
F_116 ( V_149 , V_189 ) ;
if ( V_189 & V_190 ) {
T_2 V_193 = F_117 () ;
if ( V_193 >= 255 )
F_118 ( L_49 , V_193 ) ;
F_21 ( L_50 ) ;
F_114 ( V_189 ) ;
if ( V_11 ) {
F_119 ( & F_120 ( 0 ) , V_10 ) ;
F_6 ( V_10 ) ;
}
V_194 = 1 ;
V_133 = 0 ;
F_121 ( V_195 ) ;
}
}
void F_122 ( void )
{
if ( F_10 () ) {
F_21 ( L_51 ) ;
V_196 = V_133 = 1 ;
}
}
void F_123 ( void )
{
T_3 V_189 ;
F_116 ( V_149 , V_189 ) ;
if ( V_194 ) {
F_114 ( V_189 ) ;
return;
}
if ( ! V_133 )
return;
if ( ! ( V_189 & V_190 ) ) {
F_39 ( V_197 L_52 ) ;
F_51 ( V_149 , V_189 | V_190 ) ;
}
}
int T_1 F_124 ( void )
{
#ifdef F_125
if ( ! F_126 () ) {
F_127 ( L_53 ) ;
return - 1 ;
}
if ( ! V_196 && V_198 ) {
F_21 ( L_54
L_55 ) ;
return - 1 ;
}
return F_128 () ;
#endif
return - 1 ;
}
void T_1 F_129 ( void )
{
unsigned long V_26 ;
int V_199 , F_10 = 0 ;
int V_200 ;
F_130 () ;
V_200 = F_131 () ;
if ( V_200 && ! F_132 () )
return;
V_199 = F_133 () ;
if ( V_199 ) {
F_21 ( L_56 , V_199 ) ;
return;
}
F_28 ( V_26 ) ;
V_201 -> V_202 () ;
F_134 () ;
if ( V_196 && V_11 )
F_115 () ;
if ( V_200 )
V_199 = - 1 ;
else
V_199 = F_124 () ;
if ( ! F_132 () )
goto V_203;
if ( V_199 < 0 ) {
if ( V_204 > 255 ||
! F_135 () ) {
if ( V_196 )
F_115 () ;
goto V_203;
}
F_136 () ;
}
if ( V_199 == V_205 ) {
F_21 ( L_57 ) ;
goto V_203;
}
F_10 = 1 ;
if ( F_132 () && ! V_133 ) {
V_133 = 1 ;
F_123 () ;
F_21 ( L_58 ) ;
}
V_203:
if ( V_199 < 0 )
F_137 () ;
V_201 -> V_206 () ;
F_31 ( V_26 ) ;
}
static int T_1 F_138 ( void )
{
if ( ! V_151 ) {
F_21 ( L_59 ) ;
return - 1 ;
}
V_195 = V_207 ;
return 0 ;
}
static int T_1 F_139 ( void )
{
T_2 V_72 , V_148 , V_147 ;
V_72 = F_140 ( 1 ) ;
if ( ! ( V_72 & ( 1 << V_208 ) ) ) {
F_12 ( L_60 ) ;
return - 1 ;
}
F_141 ( & V_13 , V_208 ) ;
V_195 = V_207 ;
if ( V_13 . V_16 >= 6 ) {
F_91 ( V_149 , V_147 , V_148 ) ;
if ( V_147 & V_150 )
V_195 = V_147 & V_209 ;
}
F_21 ( L_61 ) ;
return 0 ;
}
int T_1 F_142 ( unsigned long V_210 )
{
T_2 V_148 , V_147 ;
if ( V_177 )
return - 1 ;
if ( V_13 . V_16 >= 6 ) {
F_91 ( V_149 , V_147 , V_148 ) ;
if ( ! ( V_147 & V_150 ) ) {
F_21 ( L_62 ) ;
V_147 &= ~ V_209 ;
V_147 |= V_150 | V_210 ;
F_92 ( V_149 , V_147 , V_148 ) ;
V_146 = 1 ;
}
}
return F_139 () ;
}
static int T_1 F_138 ( void )
{
if ( V_177 )
return - 1 ;
switch ( V_13 . V_14 ) {
case V_15 :
if ( ( V_13 . V_16 == 6 && V_13 . V_211 > 1 ) ||
( V_13 . V_16 >= 15 ) )
break;
goto V_212;
case V_162 :
if ( V_13 . V_16 == 6 || V_13 . V_16 == 15 ||
( V_13 . V_16 == 5 && V_151 ) )
break;
goto V_212;
default:
goto V_212;
}
if ( ! V_151 ) {
if ( ! V_3 ) {
F_21 ( L_63
L_64 ) ;
return - 1 ;
}
if ( F_142 ( V_207 ) )
return - 1 ;
} else {
if ( F_139 () )
return - 1 ;
}
F_111 () ;
return 0 ;
V_212:
F_21 ( L_65 ) ;
return - 1 ;
}
void T_1 F_143 ( void )
{
unsigned int V_213 ;
if ( V_133 ) {
V_214 = F_117 () ;
return;
}
if ( ! V_160 && F_138 () ) {
F_21 ( L_66 ) ;
F_20 () ;
} else {
V_134 = V_195 ;
if ( ! V_215 && ! V_160 )
F_121 ( V_134 ) ;
}
V_213 = F_117 () ;
if ( V_214 != V_213 ) {
V_214 = V_213 ;
V_216 [ V_213 ] =
F_14 ( F_15 ( V_12 ) ) ;
}
}
void T_1 F_121 ( unsigned long V_217 )
{
V_195 = V_217 ;
if ( ! V_133 ) {
F_144 ( V_218 , V_217 ) ;
F_65 ( V_115 , L_67 ,
V_219 , V_195 ) ;
}
if ( V_214 == - 1U ) {
V_214 = F_117 () ;
V_216 [ V_214 ] =
F_14 ( F_15 ( V_12 ) ) ;
}
}
int T_1 F_145 ( void )
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
F_18 ( V_216 [ V_214 ] ) ) {
F_46 ( L_70 ,
V_214 ) ;
return - 1 ;
}
#endif
F_146 () ;
F_95 () ;
F_147 () ;
#ifdef F_17
F_29 ( V_9 , F_148 ( V_214 ) ) ;
#else
# ifdef F_149
V_214 = F_117 () ;
# endif
#endif
F_150 ( V_214 , & V_220 ) ;
F_100 () ;
#ifdef F_151
if ( ! V_198 && V_221 )
F_152 () ;
#endif
F_112 () ;
#ifdef F_151
if ( V_160 && ! V_198 && V_221 )
F_153 () ;
else {
V_221 = 0 ;
}
#endif
V_222 . V_223 . V_224 () ;
return 0 ;
}
static inline void F_154 ( void )
{
T_2 V_30 ;
V_30 = F_15 ( V_186 + ( ( V_164 & ~ 0x1f ) >> 1 ) ) ;
if ( V_30 & ( 1 << ( V_164 & 0x1f ) ) )
F_107 () ;
F_25 ( V_225 ) ;
F_21 ( L_71
L_72 , F_47 () ) ;
}
T_5 void F_155 ( struct V_128 * V_129 )
{
F_156 () ;
F_154 () ;
F_82 () ;
}
T_5 void F_157 ( struct V_128 * V_129 )
{
F_156 () ;
F_158 ( V_164 ) ;
F_154 () ;
F_159 ( V_164 ) ;
F_82 () ;
}
static inline void F_160 ( struct V_128 * V_129 )
{
T_2 V_30 ;
T_2 V_171 = 0 ;
static const char * const V_226 [] = {
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80 ,
} ;
if ( F_34 () > 3 )
F_29 ( V_142 , 0 ) ;
V_30 = F_15 ( V_142 ) ;
F_107 () ;
F_161 ( & V_227 ) ;
F_65 ( V_154 , V_42 L_81 ,
F_47 () , V_30 ) ;
V_30 &= 0xff ;
while ( V_30 ) {
if ( V_30 & 0x1 )
F_65 ( V_154 , V_228 L_82 , V_226 [ V_171 ] ) ;
V_171 ++ ;
V_30 >>= 1 ;
}
F_65 ( V_154 , V_228 L_83 ) ;
}
T_5 void F_162 ( struct V_128 * V_129 )
{
F_156 () ;
F_160 ( V_129 ) ;
F_82 () ;
}
T_5 void F_163 ( struct V_128 * V_129 )
{
F_156 () ;
F_164 ( V_135 ) ;
F_160 ( V_129 ) ;
F_165 ( V_135 ) ;
F_82 () ;
}
void T_1 F_147 ( void )
{
#ifdef V_2
if ( V_188 ) {
F_87 () ;
F_65 ( V_115 , L_84
L_85 ) ;
F_1 () ;
}
#endif
}
void F_166 ( int V_229 )
{
unsigned int V_143 ;
#ifdef V_2
if ( V_188 ) {
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
F_29 ( V_144 , V_143 ) ;
if ( ! V_229 ) {
V_143 = F_15 ( V_137 ) ;
V_143 &= ~ ( V_230 | V_231 |
V_232 | V_233 |
V_167 | V_40 ) ;
V_143 |= V_233 | V_231 ;
V_143 = F_167 ( V_143 , V_234 ) ;
F_29 ( V_137 , V_143 ) ;
} else {
F_29 ( V_137 , V_40 ) ;
}
V_143 = F_15 ( V_138 ) ;
V_143 &= ~ ( V_230 | V_231 |
V_232 | V_233 |
V_167 | V_40 ) ;
V_143 |= V_233 | V_231 ;
V_143 = F_167 ( V_143 , V_235 ) ;
F_29 ( V_138 , V_143 ) ;
}
int F_168 ( int V_8 , int V_236 )
{
int V_126 , V_237 = V_238 ;
bool V_239 = F_169 ( V_214 ,
V_220 ) ;
if ( V_240 != V_181 &&
V_240 != F_117 () &&
V_240 == V_8 ) {
int V_241 = V_242 + V_243 ;
F_12 ( L_88
L_89 ,
V_241 , V_8 ) ;
V_243 ++ ;
return - V_244 ;
}
if ( ! V_239 && V_242 >= V_238 - 1 &&
V_8 != V_214 ) {
int V_241 = V_237 + V_243 - 1 ;
F_12 (
L_90
L_91
L_92 , V_237 , V_241 , V_8 ) ;
V_243 ++ ;
return - V_244 ;
}
if ( V_242 >= V_238 ) {
int V_241 = V_237 + V_243 ;
F_12 (
L_93
L_92 , V_237 , V_241 , V_8 ) ;
V_243 ++ ;
return - V_62 ;
}
V_242 ++ ;
if ( V_8 == V_214 ) {
V_126 = 0 ;
} else
V_126 = F_170 ( - 1 , V_245 ) ;
if ( V_236 == 0x0 ) {
F_12 ( L_94 ,
V_126 , V_8 ) ;
V_236 = 0x10 ;
}
V_216 [ V_8 ] = V_236 ;
if ( V_236 != V_216 [ V_214 ] ) {
F_12 ( L_95 ,
V_216 [ V_214 ] , V_126 , V_236 ) ;
}
F_171 ( V_8 , V_220 ) ;
if ( V_8 > V_204 )
V_204 = V_8 ;
#if F_172 ( F_54 ) || F_172 ( F_17 )
F_104 ( V_246 , V_126 ) = V_8 ;
F_104 ( V_247 , V_126 ) = V_8 ;
#endif
#ifdef V_2
F_104 ( V_180 , V_126 ) =
V_17 -> V_248 ( V_126 ) ;
#endif
F_173 ( V_126 , true ) ;
F_174 ( V_126 , true ) ;
return V_126 ;
}
int F_175 ( void )
{
return F_117 () ;
}
void F_176 ( void )
{
unsigned long V_249 ;
F_29 ( V_250 , V_251 ) ;
V_249 = F_15 ( V_252 ) & ~ V_253 ;
V_249 |= F_177 ( 1UL << F_47 () ) ;
F_29 ( V_252 , V_249 ) ;
}
int F_178 ( const struct V_80 * V_80 ,
const struct V_80 * V_254 ,
unsigned int * V_8 )
{
unsigned int V_126 ;
F_179 (cpu, cpumask, andmask) {
if ( F_180 ( V_126 , V_255 ) )
break;
}
if ( F_181 ( V_126 < V_238 ) ) {
* V_8 = F_78 ( V_246 , V_126 ) ;
return 0 ;
}
return - V_62 ;
}
void T_1 F_182 ( void (* F_183)( T_2 V_59 , T_2 V_30 ) )
{
struct V_17 * * V_256 ;
for ( V_256 = V_257 ; V_256 < V_258 ; V_256 ++ ) {
F_105 ( ( * V_256 ) -> F_183 == F_183 ) ;
( * V_256 ) -> F_183 = F_183 ;
}
}
static int F_184 ( void )
{
unsigned long V_26 ;
int V_132 ;
if ( ! V_259 . V_260 )
return 0 ;
V_132 = F_34 () ;
V_259 . V_261 = F_15 ( V_9 ) ;
V_259 . V_262 = F_15 ( V_182 ) ;
V_259 . V_263 = F_15 ( V_252 ) ;
V_259 . V_264 = F_15 ( V_250 ) ;
V_259 . V_265 = F_15 ( V_144 ) ;
V_259 . V_266 = F_15 ( V_41 ) ;
if ( V_132 >= 4 )
V_259 . V_267 = F_15 ( V_139 ) ;
V_259 . V_268 = F_15 ( V_137 ) ;
V_259 . V_269 = F_15 ( V_138 ) ;
V_259 . V_270 = F_15 ( V_136 ) ;
V_259 . V_271 = F_15 ( V_47 ) ;
V_259 . V_272 = F_15 ( V_43 ) ;
#ifdef F_88
if ( V_132 >= 5 )
V_259 . V_273 = F_15 ( V_140 ) ;
#endif
F_28 ( V_26 ) ;
F_90 () ;
F_185 () ;
F_31 ( V_26 ) ;
return 0 ;
}
static void F_186 ( void )
{
unsigned int V_147 , V_148 ;
unsigned long V_26 ;
int V_132 ;
if ( ! V_259 . V_260 )
return;
F_28 ( V_26 ) ;
F_134 () ;
V_201 -> V_202 () ;
if ( V_133 )
F_123 () ;
else {
if ( V_13 . V_16 >= 6 ) {
F_91 ( V_149 , V_147 , V_148 ) ;
V_147 &= ~ V_209 ;
V_147 |= V_150 | V_195 ;
F_92 ( V_149 , V_147 , V_148 ) ;
}
}
V_132 = F_34 () ;
F_29 ( V_136 , V_135 | V_40 ) ;
F_29 ( V_9 , V_259 . V_261 ) ;
F_29 ( V_250 , V_259 . V_264 ) ;
F_29 ( V_252 , V_259 . V_263 ) ;
F_29 ( V_182 , V_259 . V_262 ) ;
F_29 ( V_144 , V_259 . V_265 ) ;
F_29 ( V_137 , V_259 . V_268 ) ;
F_29 ( V_138 , V_259 . V_269 ) ;
#if F_172 ( F_89 )
if ( V_132 >= 5 )
F_29 ( V_140 , V_259 . V_273 ) ;
#endif
if ( V_132 >= 4 )
F_29 ( V_139 , V_259 . V_267 ) ;
F_29 ( V_41 , V_259 . V_266 ) ;
F_29 ( V_43 , V_259 . V_272 ) ;
F_29 ( V_47 , V_259 . V_271 ) ;
F_29 ( V_142 , 0 ) ;
F_15 ( V_142 ) ;
F_29 ( V_136 , V_259 . V_270 ) ;
F_29 ( V_142 , 0 ) ;
F_15 ( V_142 ) ;
F_187 ( V_133 ) ;
F_31 ( V_26 ) ;
}
static void F_111 ( void )
{
V_259 . V_260 = 1 ;
}
static int T_1 F_188 ( void )
{
if ( V_151 )
F_189 ( & V_274 ) ;
return 0 ;
}
static void F_111 ( void ) { }
static int F_190 ( const struct V_275 * V_276 )
{
if ( V_277 )
return 0 ;
F_21 ( L_96 , V_276 -> V_278 ) ;
V_277 = 1 ;
return 0 ;
}
static void F_191 ( void )
{
if ( V_279 )
return;
F_192 ( V_280 ) ;
V_279 = 1 ;
}
int F_193 ( void )
{
F_191 () ;
return V_277 ;
}
static int T_1 F_194 ( char * V_1 )
{
V_177 = 1 ;
F_6 ( V_208 ) ;
return 0 ;
}
static int T_1 F_195 ( char * V_1 )
{
return F_194 ( V_1 ) ;
}
static int T_1 F_196 ( char * V_1 )
{
V_281 = 1 ;
return 0 ;
}
static int T_1 F_197 ( char * V_1 )
{
V_125 = 1 ;
return 0 ;
}
static int T_1 F_198 ( char * V_1 )
{
V_125 = 1 ;
return 0 ;
}
static int T_1 F_199 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_17
V_198 = 0 ;
return 0 ;
#endif
return - V_62 ;
}
if ( strcmp ( L_97 , V_1 ) == 0 )
V_282 = V_154 ;
else if ( strcmp ( L_98 , V_1 ) == 0 )
V_282 = V_115 ;
else {
F_12 ( L_99
L_100 , V_1 ) ;
return - V_62 ;
}
return 0 ;
}
static int T_1 F_200 ( void )
{
if ( ! V_134 )
return - 1 ;
V_283 . V_284 = V_134 ;
V_283 . V_285 = V_283 . V_284 + V_286 - 1 ;
F_201 ( & V_287 , & V_283 ) ;
return 0 ;
}
static int T_1 F_202 ( char * V_1 )
{
if ( ! V_1 || ! F_203 ( & V_1 , & V_240 ) )
return - V_62 ;
return 0 ;
}
