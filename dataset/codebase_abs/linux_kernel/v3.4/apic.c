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
int V_6 = F_9 ( V_7 ) ;
if ( V_6 >= 255 ) {
F_10 ( L_1 ,
V_6 ) ;
return 0 ;
}
F_10 ( L_2 ) ;
} else
F_11 ( V_8 ) ;
V_9 = 1 ;
return 0 ;
}
static inline int F_12 ( void )
{
return F_13 ( F_14 ( V_10 ) ) ;
}
static inline int F_15 ( void )
{
#ifdef F_16
return 1 ;
#else
return F_17 ( F_12 () ) ;
#endif
}
static int F_18 ( void )
{
if ( V_11 . V_12 == V_13 &&
V_11 . V_14 >= 0xf )
return 1 ;
return F_12 () >= 0x14 ;
}
static void T_1 F_19 ( void )
{
F_20 ( L_3 ) ;
V_15 = & V_16 ;
}
void F_21 ( void )
{
while ( F_14 ( V_17 ) & V_18 )
F_22 () ;
}
T_2 F_23 ( void )
{
T_2 V_19 ;
int V_20 ;
V_20 = 0 ;
do {
V_19 = F_14 ( V_17 ) & V_18 ;
if ( ! V_19 )
break;
F_24 ( V_21 ) ;
F_25 ( 100 ) ;
} while ( V_20 ++ < 1000 );
return V_19 ;
}
void F_26 ( T_2 V_22 , T_2 V_23 )
{
F_27 ( V_24 , F_28 ( V_23 ) ) ;
F_27 ( V_17 , V_22 ) ;
}
T_3 F_29 ( void )
{
T_2 V_25 , V_26 ;
V_26 = F_14 ( V_24 ) ;
V_25 = F_14 ( V_17 ) ;
return V_25 | ( ( T_3 ) V_26 << 32 ) ;
}
int F_30 ( void )
{
return F_18 () ? 0xff : 0xf ;
}
int F_31 ( void )
{
unsigned int V_27 ;
V_27 = F_14 ( V_10 ) ;
return F_17 ( F_13 ( V_27 ) ) ? F_32 ( V_27 ) : 2 ;
}
static void F_33 ( unsigned int V_28 , int V_29 , int V_30 )
{
unsigned int V_31 , V_32 ;
V_31 = V_33 ;
if ( ! V_29 )
V_31 |= V_34 ;
if ( ! F_15 () )
V_31 |= F_34 ( V_35 ) ;
if ( ! V_30 )
V_31 |= V_36 ;
F_27 ( V_37 , V_31 ) ;
V_32 = F_14 ( V_38 ) ;
F_27 ( V_38 ,
( V_32 & ~ ( V_39 | V_40 ) ) |
V_41 ) ;
if ( ! V_29 )
F_27 ( V_42 , V_28 / V_43 ) ;
}
static inline int F_35 ( unsigned int V_44 , unsigned int V_45 )
{
return ( V_44 & V_46 )
|| ( V_45 == V_46 )
|| ( ( V_45 & ~ V_46 ) == V_44 ) ;
}
static unsigned int F_36 ( int V_47 , unsigned int V_45 )
{
unsigned int V_48 , V_49 ;
if ( V_47 >= V_50 )
return ~ 0 ;
V_48 = F_37 ( & V_51 [ V_47 ] ) ;
do {
V_49 = V_48 & ~ V_46 ;
if ( V_49 && ! F_35 ( V_49 , V_45 ) )
return V_48 ;
V_48 = F_38 ( & V_51 [ V_47 ] , V_48 , V_45 ) ;
} while ( V_48 != V_45 );
V_48 &= ~ V_46 ;
if ( V_48 && V_48 != V_49 )
F_20 ( L_4 ,
V_47 , V_48 ) ;
return V_45 ;
}
int F_39 ( T_4 V_47 , T_4 V_49 , T_4 V_52 , T_4 V_53 )
{
unsigned long V_54 = F_40 ( V_47 ) ;
unsigned int V_45 , V_44 , V_55 ;
V_45 = ( V_53 << 16 ) | ( V_52 << 8 ) | V_49 ;
V_44 = F_14 ( V_54 ) ;
V_55 = F_36 ( V_47 , V_45 ) ;
if ( V_55 != V_45 ) {
F_41 ( V_56 L_5
L_6
L_7 ,
F_42 () , V_54 , V_47 , V_45 , V_55 ) ;
return - V_57 ;
}
if ( ! F_35 ( V_44 , V_45 ) ) {
F_41 ( V_56 L_5
L_6
L_8 ,
F_42 () , V_54 , V_47 , V_45 , V_44 ) ;
return - V_58 ;
}
F_27 ( V_54 , V_45 ) ;
return 0 ;
}
static int F_43 ( unsigned long V_59 ,
struct V_60 * V_61 )
{
F_27 ( V_42 , V_59 ) ;
return 0 ;
}
static void F_44 ( enum V_62 V_63 ,
struct V_60 * V_61 )
{
unsigned long V_64 ;
unsigned int V_27 ;
if ( V_61 -> V_65 & V_66 )
return;
F_45 ( V_64 ) ;
switch ( V_63 ) {
case V_67 :
case V_68 :
F_33 ( V_69 ,
V_63 != V_67 , 1 ) ;
break;
case V_70 :
case V_71 :
V_27 = F_14 ( V_37 ) ;
V_27 |= ( V_36 | V_33 ) ;
F_27 ( V_37 , V_27 ) ;
F_27 ( V_42 , 0 ) ;
break;
case V_72 :
break;
}
F_46 ( V_64 ) ;
}
static void F_47 ( const struct V_73 * V_53 )
{
#ifdef F_48
V_15 -> V_74 ( V_53 , V_33 ) ;
#endif
}
static void T_5 F_49 ( void )
{
struct V_60 * V_75 = & F_50 ( V_76 ) ;
if ( F_51 ( V_77 ) ) {
V_78 . V_65 &= ~ V_79 ;
V_78 . V_80 = 150 ;
}
memcpy ( V_75 , & V_78 , sizeof( * V_75 ) ) ;
V_75 -> V_73 = F_52 ( F_42 () ) ;
F_53 ( V_75 ) ;
}
static void T_1 F_54 ( struct V_60 * V_81 )
{
unsigned long long V_82 = 0 ;
long V_83 = F_14 ( V_84 ) ;
unsigned long V_85 = F_55 () ;
if ( V_86 )
F_56 ( V_82 ) ;
switch ( V_87 ++ ) {
case 0 :
V_88 = V_83 ;
V_89 = V_82 ;
V_90 = V_85 ;
V_91 = V_92 ;
break;
case V_93 :
V_94 = V_83 ;
V_95 = V_82 ;
if ( V_85 < V_90 )
V_85 += V_96 ;
V_97 = V_85 ;
V_98 = V_92 ;
break;
}
}
static int T_1
F_57 ( long V_99 , long * V_59 , long * V_100 )
{
const long V_101 = V_102 / 10 ;
const long V_103 = V_101 / 100 ;
unsigned long V_104 ;
T_3 V_105 ;
#ifndef F_58
return - 1 ;
#endif
F_59 ( V_106 , L_9 , V_99 ) ;
if ( ! V_99 )
return - 1 ;
V_104 = F_60 ( V_102 , 22 ) ;
if ( V_99 > ( V_101 - V_103 ) &&
V_99 < ( V_101 + V_103 ) ) {
F_59 ( V_106 , L_10 ) ;
return 0 ;
}
V_105 = ( ( ( T_3 ) V_99 ) * V_104 ) >> 22 ;
F_61 ( V_105 , 1000000 ) ;
F_10 ( L_11
L_12 , ( long ) V_105 ) ;
V_105 = ( ( ( T_3 ) ( * V_59 ) ) * V_101 ) ;
F_61 ( V_105 , V_99 ) ;
F_20 ( L_13
L_14 , ( unsigned long ) V_105 , * V_59 ) ;
* V_59 = ( long ) V_105 ;
if ( V_86 ) {
V_105 = ( ( ( T_3 ) ( * V_100 ) ) * V_101 ) ;
F_61 ( V_105 , V_99 ) ;
F_59 ( V_106 , L_15
L_16 ,
( unsigned long ) V_105 , * V_100 ) ;
* V_100 = ( long ) V_105 ;
}
return 0 ;
}
static int T_1 F_62 ( void )
{
struct V_60 * V_75 = & F_50 ( V_76 ) ;
void (* F_63)( struct V_60 * V_81 );
unsigned long V_107 ;
long V_59 , V_100 ;
int V_108 = 0 ;
if ( V_69 ) {
F_59 ( V_106 , L_17 ,
V_69 ) ;
V_78 . V_104 = F_64 ( V_69 / V_43 ,
V_109 , V_78 . V_110 ) ;
V_78 . V_111 =
F_65 ( 0x7FFFFF , & V_78 ) ;
V_78 . V_112 =
F_65 ( 0xF , & V_78 ) ;
V_78 . V_65 &= ~ V_66 ;
return 0 ;
}
F_66 () ;
F_63 = V_113 -> V_114 ;
V_113 -> V_114 = F_54 ;
F_33 ( 0xffffffff , 0 , 0 ) ;
F_67 () ;
while ( V_87 <= V_93 )
F_22 () ;
F_66 () ;
V_113 -> V_114 = F_63 ;
V_59 = V_88 - V_94 ;
F_59 ( V_106 , L_18 , V_59 ) ;
V_100 = ( long ) ( V_95 - V_89 ) ;
V_108 = ! F_57 ( V_97 - V_90 ,
& V_59 , & V_100 ) ;
V_78 . V_104 = F_64 ( V_59 , V_109 * V_93 ,
V_78 . V_110 ) ;
V_78 . V_111 =
F_65 ( 0x7FFFFFFF , & V_78 ) ;
V_78 . V_112 =
F_65 ( 0xF , & V_78 ) ;
V_69 = ( V_59 * V_43 ) / V_93 ;
F_59 ( V_106 , L_19 , V_59 ) ;
F_59 ( V_106 , L_20 , V_78 . V_104 ) ;
F_59 ( V_106 , L_21 ,
V_69 ) ;
if ( V_86 ) {
F_59 ( V_106 , L_22
L_23 ,
( V_100 / V_93 ) / ( 1000000 / V_115 ) ,
( V_100 / V_93 ) % ( 1000000 / V_115 ) ) ;
}
F_59 ( V_106 , L_24
L_25 ,
V_69 / ( 1000000 / V_115 ) ,
V_69 % ( 1000000 / V_115 ) ) ;
if ( V_69 < ( 1000000 / V_115 ) ) {
F_67 () ;
F_10 ( L_26 ) ;
return - 1 ;
}
V_75 -> V_65 &= ~ V_66 ;
if ( ! V_108 ) {
F_59 ( V_106 , L_27 ) ;
V_75 -> V_114 = F_54 ;
F_44 ( V_67 , V_75 ) ;
V_87 = - 1 ;
F_67 () ;
while ( V_87 <= V_93 )
F_22 () ;
F_44 ( V_71 , V_75 ) ;
V_107 = V_98 - V_91 ;
F_59 ( V_106 , L_28 , V_107 ) ;
if ( V_107 >= V_93 - 2 && V_107 <= V_93 + 2 )
F_59 ( V_106 , L_29 ) ;
else
V_75 -> V_65 |= V_66 ;
} else
F_67 () ;
if ( V_75 -> V_65 & V_66 ) {
F_10 ( L_30 ) ;
return - 1 ;
}
return 0 ;
}
void T_1 F_68 ( void )
{
if ( V_116 ) {
F_20 ( L_31 ) ;
if ( F_69 () > 1 ) {
V_78 . V_104 = 1 ;
F_49 () ;
}
return;
}
F_59 ( V_106 , L_32
L_33 ) ;
if ( F_62 () ) {
if ( F_69 () > 1 )
F_49 () ;
return;
}
V_78 . V_65 &= ~ V_66 ;
F_49 () ;
}
void T_5 F_70 ( void )
{
F_49 () ;
}
static void F_71 ( void )
{
int V_117 = F_42 () ;
struct V_60 * V_61 = & F_72 ( V_76 , V_117 ) ;
if ( ! V_61 -> V_114 ) {
F_10 ( L_34 , V_117 ) ;
F_44 ( V_71 , V_61 ) ;
return;
}
F_24 ( V_118 ) ;
V_61 -> V_114 ( V_61 ) ;
}
void T_6 F_73 ( struct V_119 * V_120 )
{
struct V_119 * V_121 = F_74 ( V_120 ) ;
F_75 () ;
F_76 () ;
F_77 () ;
F_71 () ;
F_78 () ;
F_74 ( V_121 ) ;
}
int F_79 ( unsigned int V_122 )
{
return - V_57 ;
}
void F_80 ( void )
{
int V_123 ;
T_2 V_27 ;
if ( ! V_124 && ! V_125 )
return;
V_123 = F_31 () ;
if ( V_123 >= 3 ) {
V_27 = V_126 ;
F_27 ( V_127 , V_27 | V_36 ) ;
}
V_27 = F_14 ( V_37 ) ;
F_27 ( V_37 , V_27 | V_36 ) ;
V_27 = F_14 ( V_128 ) ;
F_27 ( V_128 , V_27 | V_36 ) ;
V_27 = F_14 ( V_129 ) ;
F_27 ( V_129 , V_27 | V_36 ) ;
if ( V_123 >= 4 ) {
V_27 = F_14 ( V_130 ) ;
F_27 ( V_130 , V_27 | V_36 ) ;
}
#ifdef F_81
if ( V_123 >= 5 ) {
V_27 = F_14 ( V_131 ) ;
F_27 ( V_131 , V_27 | V_36 ) ;
}
#endif
#ifdef F_82
if ( V_123 >= 6 ) {
V_27 = F_14 ( V_132 ) ;
if ( ! ( V_27 & V_36 ) )
F_27 ( V_132 , V_27 | V_36 ) ;
}
#endif
F_27 ( V_37 , V_36 ) ;
F_27 ( V_128 , V_36 ) ;
F_27 ( V_129 , V_36 ) ;
if ( V_123 >= 3 )
F_27 ( V_127 , V_36 ) ;
if ( V_123 >= 4 )
F_27 ( V_130 , V_36 ) ;
if ( F_15 () ) {
if ( V_123 > 3 )
F_27 ( V_133 , 0 ) ;
F_14 ( V_133 ) ;
}
}
void F_83 ( void )
{
unsigned int V_134 ;
if ( ! V_124 && ! V_125 )
return;
F_80 () ;
V_134 = F_14 ( V_135 ) ;
V_134 &= ~ V_136 ;
F_27 ( V_135 , V_134 ) ;
#ifdef F_84
if ( V_137 ) {
unsigned int V_138 , V_139 ;
F_85 ( V_140 , V_138 , V_139 ) ;
V_138 &= ~ V_141 ;
F_86 ( V_140 , V_138 , V_139 ) ;
}
#endif
}
void F_87 ( void )
{
unsigned long V_64 ;
if ( ! V_142 && ! F_88 () )
return;
F_45 ( V_64 ) ;
#ifdef F_84
if ( ! V_137 )
F_80 () ;
else
#endif
F_83 () ;
F_46 ( V_64 ) ;
}
int T_1 F_89 ( void )
{
unsigned int V_143 , V_144 ;
V_143 = F_14 ( V_10 ) ;
F_59 ( V_145 , L_35 , V_143 ) ;
F_27 ( V_10 , V_143 ^ V_146 ) ;
V_144 = F_14 ( V_10 ) ;
F_59 ( V_145 , L_35 , V_144 ) ;
if ( V_144 != V_143 )
return 0 ;
V_144 = F_13 ( V_143 ) ;
if ( V_144 == 0x00 || V_144 == 0xff )
return 0 ;
V_144 = F_31 () ;
if ( V_144 < 0x02 || V_144 == 0xff )
return 0 ;
V_143 = F_14 ( V_7 ) ;
F_59 ( V_145 , L_36 , V_143 ) ;
F_27 ( V_7 , V_143 ^ V_15 -> V_147 ) ;
V_144 = F_14 ( V_7 ) ;
F_59 ( V_145 , L_36 , V_144 ) ;
F_27 ( V_7 , V_143 ) ;
if ( V_144 != ( V_143 ^ V_15 -> V_147 ) )
return 0 ;
V_143 = F_14 ( V_128 ) ;
F_59 ( V_145 , L_37 , V_143 ) ;
V_144 = F_14 ( V_129 ) ;
F_59 ( V_145 , L_38 , V_144 ) ;
return 1 ;
}
void T_1 F_90 ( void )
{
if ( F_18 () || V_11 . V_12 == V_13 )
return;
F_91 () ;
F_59 ( V_145 , L_39 ) ;
F_27 ( V_17 , V_148 |
V_149 | V_150 ) ;
}
void T_1 F_92 ( void )
{
unsigned int V_134 ;
if ( V_151 || ! V_142 )
return;
F_80 () ;
V_134 = F_14 ( V_135 ) ;
V_134 &= ~ V_152 ;
V_134 |= V_136 ;
#ifdef F_84
if ( ( V_11 . V_12 == V_153 ) &&
( V_11 . V_14 == 15 ) )
V_134 &= ~ V_154 ;
else
#endif
V_134 |= V_154 ;
V_134 |= V_155 ;
F_27 ( V_135 , V_134 ) ;
F_27 ( V_128 , V_156 ) ;
V_134 = V_157 ;
if ( ! F_15 () )
V_134 |= V_158 ;
F_27 ( V_129 , V_134 ) ;
}
static void T_5 F_93 ( void )
{
unsigned int V_159 , V_134 , V_123 ;
if ( ! F_15 () ) {
F_20 ( L_40 ) ;
return;
}
if ( V_15 -> V_160 ) {
F_20 ( L_41 ) ;
return;
}
V_123 = F_31 () ;
if ( V_123 > 3 )
F_27 ( V_133 , 0 ) ;
V_159 = F_14 ( V_133 ) ;
V_134 = V_126 ;
F_27 ( V_127 , V_134 ) ;
if ( V_123 > 3 )
F_27 ( V_133 , 0 ) ;
V_134 = F_14 ( V_133 ) ;
if ( V_134 != V_159 )
F_59 ( V_106 , L_42
L_43 ,
V_159 , V_134 ) ;
}
void T_5 F_94 ( void )
{
int V_117 = F_42 () ;
unsigned int V_134 , V_161 ;
int V_162 , V_163 , V_164 = 0 ;
unsigned long long V_82 = 0 , V_165 ;
long long V_166 = V_167 ;
if ( V_86 )
F_56 ( V_82 ) ;
if ( V_168 ) {
F_95 () ;
return;
}
#ifdef F_84
if ( F_15 () && V_15 -> V_160 ) {
F_27 ( V_133 , 0 ) ;
F_27 ( V_133 , 0 ) ;
F_27 ( V_133 , 0 ) ;
F_27 ( V_133 , 0 ) ;
}
#endif
F_96 () ;
F_97 ( ! V_15 -> V_169 () ) ;
V_15 -> V_170 () ;
#ifdef F_84
V_162 = F_98 ( V_171 , V_117 ) ;
F_99 ( V_162 != V_172 && V_162 != F_100 () ) ;
F_98 ( V_171 , V_117 ) =
F_100 () ;
if ( V_15 -> V_173 )
F_101 ( F_98 ( V_174 , V_117 ) ,
V_15 -> V_173 ( V_117 ) ) ;
#endif
V_134 = F_14 ( V_175 ) ;
V_134 &= ~ V_176 ;
F_27 ( V_175 , V_134 ) ;
do {
V_161 = 0 ;
for ( V_162 = V_177 - 1 ; V_162 >= 0 ; V_162 -- )
V_161 |= F_14 ( V_178 + V_162 * 0x10 ) ;
for ( V_162 = V_177 - 1 ; V_162 >= 0 ; V_162 -- ) {
V_134 = F_14 ( V_179 + V_162 * 0x10 ) ;
for ( V_163 = 31 ; V_163 >= 0 ; V_163 -- ) {
if ( V_134 & ( 1 << V_163 ) ) {
F_75 () ;
V_164 ++ ;
}
}
}
if ( V_164 > 256 ) {
F_102 ( V_180 L_44 ,
V_164 ) ;
break;
}
if ( V_86 ) {
F_56 ( V_165 ) ;
V_166 = ( V_167 << 10 ) - ( V_165 - V_82 ) ;
} else
V_166 -- ;
} while ( V_161 && V_166 > 0 );
F_99 ( V_166 <= 0 ) ;
V_134 = F_14 ( V_135 ) ;
V_134 &= ~ V_152 ;
V_134 |= V_136 ;
#ifdef F_84
V_134 &= ~ V_154 ;
#endif
V_134 |= V_155 ;
F_27 ( V_135 , V_134 ) ;
V_134 = F_14 ( V_128 ) & V_36 ;
if ( ! V_117 && ( V_181 || ! V_134 ) ) {
V_134 = V_156 ;
F_59 ( V_106 , L_45 , V_117 ) ;
} else {
V_134 = V_156 | V_36 ;
F_59 ( V_106 , L_46 , V_117 ) ;
}
F_27 ( V_128 , V_134 ) ;
if ( ! V_117 )
V_134 = V_157 ;
else
V_134 = V_157 | V_36 ;
if ( ! F_15 () )
V_134 |= V_158 ;
F_27 ( V_129 , V_134 ) ;
#ifdef F_82
if ( ! V_117 )
F_103 () ;
#endif
}
void T_5 F_104 ( void )
{
F_93 () ;
#ifdef F_84
{
unsigned int V_134 ;
V_134 = F_14 ( V_37 ) ;
V_134 |= ( V_36 | V_33 ) ;
F_27 ( V_37 , V_134 ) ;
}
#endif
F_105 () ;
}
void T_1 F_106 ( void )
{
F_104 () ;
if ( V_182 )
F_107 () ;
}
static inline void F_108 ( T_3 V_183 )
{
F_109 ( V_140 ,
V_183 & ~ ( V_184 | V_185 ) ) ;
F_109 ( V_140 , V_183 & ~ V_184 ) ;
}
static T_1 void F_110 ( void )
{
T_3 V_183 ;
if ( ! V_186 )
return;
F_111 ( V_140 , V_183 ) ;
if ( V_183 & V_184 ) {
T_2 V_187 = F_112 () ;
if ( V_187 >= 255 )
F_113 ( L_47 , V_187 ) ;
F_20 ( L_48 ) ;
F_108 ( V_183 ) ;
if ( V_9 ) {
F_114 ( & F_115 ( 0 ) , V_8 ) ;
F_11 ( V_8 ) ;
}
V_188 = 1 ;
V_124 = 0 ;
F_116 ( V_189 ) ;
}
}
void F_117 ( void )
{
if ( F_8 () ) {
F_20 ( L_49 ) ;
V_190 = V_124 = 1 ;
}
}
void F_118 ( void )
{
T_3 V_183 ;
F_111 ( V_140 , V_183 ) ;
if ( V_188 ) {
F_108 ( V_183 ) ;
return;
}
if ( ! V_124 )
return;
if ( ! ( V_183 & V_184 ) ) {
F_119 ( V_191 L_50 ) ;
F_109 ( V_140 , V_183 | V_184 ) ;
}
}
int T_1 F_120 ( void )
{
#ifdef F_121
if ( ! F_122 () ) {
F_123 ( L_51 ) ;
return - 1 ;
}
if ( ! V_190 && V_192 ) {
F_20 ( L_52
L_53 ) ;
return - 1 ;
}
return F_124 () ;
#endif
return - 1 ;
}
void T_1 F_125 ( void )
{
unsigned long V_64 ;
int V_193 , F_8 = 0 ;
int V_194 ;
V_194 = F_126 () ;
if ( V_194 && ! F_127 () )
return;
V_193 = F_128 () ;
if ( V_193 ) {
F_20 ( L_54 , V_193 ) ;
return;
}
F_45 ( V_64 ) ;
V_195 -> V_196 () ;
F_129 () ;
if ( V_190 && V_9 )
F_110 () ;
if ( V_194 )
V_193 = - 1 ;
else
V_193 = F_120 () ;
if ( ! F_127 () )
goto V_197;
if ( V_193 < 0 ) {
if ( V_198 > 255 ||
! F_130 () ) {
if ( V_190 )
F_110 () ;
goto V_197;
}
F_131 () ;
}
if ( V_193 == V_199 ) {
F_20 ( L_55 ) ;
goto V_197;
}
F_8 = 1 ;
if ( F_127 () && ! V_124 ) {
V_124 = 1 ;
F_118 () ;
F_20 ( L_56 ) ;
}
V_197:
if ( V_193 < 0 )
F_132 () ;
V_195 -> V_200 () ;
F_46 ( V_64 ) ;
}
static int T_1 F_133 ( void )
{
if ( ! V_142 ) {
F_20 ( L_57 ) ;
return - 1 ;
}
V_189 = V_201 ;
return 0 ;
}
static int T_1 F_134 ( void )
{
T_2 V_65 , V_139 , V_138 ;
V_65 = F_135 ( 1 ) ;
if ( ! ( V_65 & ( 1 << V_202 ) ) ) {
F_10 ( L_58 ) ;
return - 1 ;
}
F_136 ( & V_11 , V_202 ) ;
V_189 = V_201 ;
if ( V_11 . V_14 >= 6 ) {
F_85 ( V_140 , V_138 , V_139 ) ;
if ( V_138 & V_141 )
V_189 = V_138 & V_203 ;
}
F_20 ( L_59 ) ;
return 0 ;
}
int T_1 F_137 ( unsigned long V_204 )
{
T_2 V_139 , V_138 ;
if ( V_168 )
return - 1 ;
if ( V_11 . V_14 >= 6 ) {
F_85 ( V_140 , V_138 , V_139 ) ;
if ( ! ( V_138 & V_141 ) ) {
F_20 ( L_60 ) ;
V_138 &= ~ V_203 ;
V_138 |= V_141 | V_204 ;
F_86 ( V_140 , V_138 , V_139 ) ;
V_137 = 1 ;
}
}
return F_134 () ;
}
static int T_1 F_133 ( void )
{
if ( V_168 )
return - 1 ;
switch ( V_11 . V_12 ) {
case V_13 :
if ( ( V_11 . V_14 == 6 && V_11 . V_205 > 1 ) ||
( V_11 . V_14 >= 15 ) )
break;
goto V_206;
case V_153 :
if ( V_11 . V_14 == 6 || V_11 . V_14 == 15 ||
( V_11 . V_14 == 5 && V_142 ) )
break;
goto V_206;
default:
goto V_206;
}
if ( ! V_142 ) {
if ( ! V_2 ) {
F_20 ( L_61
L_62 ) ;
return - 1 ;
}
if ( F_137 ( V_201 ) )
return - 1 ;
} else {
if ( F_134 () )
return - 1 ;
}
F_105 () ;
return 0 ;
V_206:
F_20 ( L_63 ) ;
return - 1 ;
}
void T_1 F_138 ( void )
{
unsigned int V_207 ;
if ( V_124 ) {
V_208 = F_112 () ;
return;
}
if ( ! V_151 && F_133 () ) {
F_20 ( L_64 ) ;
F_19 () ;
} else {
V_125 = V_189 ;
if ( ! V_209 && ! V_151 )
F_116 ( V_125 ) ;
}
V_207 = F_112 () ;
if ( V_208 != V_207 ) {
V_208 = V_207 ;
V_210 [ V_207 ] =
F_13 ( F_14 ( V_10 ) ) ;
}
}
void T_1 F_116 ( unsigned long V_211 )
{
V_189 = V_211 ;
if ( ! V_124 ) {
F_139 ( V_212 , V_211 ) ;
F_59 ( V_106 , L_65 ,
V_213 , V_189 ) ;
}
if ( V_208 == - 1U ) {
V_208 = F_112 () ;
V_210 [ V_208 ] =
F_13 ( F_14 ( V_10 ) ) ;
}
}
int T_1 F_140 ( void )
{
if ( V_168 ) {
F_20 ( L_66 ) ;
return - 1 ;
}
#ifdef F_16
if ( ! V_142 ) {
V_168 = 1 ;
F_20 ( L_67 ) ;
return - 1 ;
}
#else
if ( ! V_151 && ! V_142 )
return - 1 ;
if ( ! V_142 &&
F_17 ( V_210 [ V_208 ] ) ) {
F_41 ( L_68 ,
V_208 ) ;
return - 1 ;
}
#endif
F_141 () ;
F_89 () ;
F_142 () ;
#ifdef F_16
F_27 ( V_7 , F_143 ( V_208 ) ) ;
#else
# ifdef F_144
V_208 = F_112 () ;
# endif
#endif
F_145 ( V_208 , & V_214 ) ;
F_94 () ;
#ifdef F_146
if ( ! V_192 && V_215 )
F_147 () ;
#endif
F_106 () ;
#ifdef F_146
if ( V_151 && ! V_192 && V_215 )
F_148 () ;
else {
V_215 = 0 ;
}
#endif
V_216 . V_217 . V_218 () ;
return 0 ;
}
void F_149 ( struct V_119 * V_120 )
{
T_2 V_27 ;
F_76 () ;
F_77 () ;
V_27 = F_14 ( V_179 + ( ( V_155 & ~ 0x1f ) >> 1 ) ) ;
if ( V_27 & ( 1 << ( V_155 & 0x1f ) ) )
F_75 () ;
F_24 ( V_219 ) ;
F_20 ( L_69
L_70 , F_42 () ) ;
F_78 () ;
}
void F_150 ( struct V_119 * V_120 )
{
T_2 V_220 , V_221 ;
T_2 V_162 = 0 ;
static const char * const V_222 [] = {
L_71 ,
L_72 ,
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
L_78 ,
} ;
F_76 () ;
F_77 () ;
V_220 = F_14 ( V_133 ) ;
F_27 ( V_133 , 0 ) ;
V_221 = F_14 ( V_133 ) ;
F_75 () ;
F_151 ( & V_223 ) ;
F_59 ( V_145 , V_224 L_79 ,
F_42 () , V_220 , V_221 ) ;
V_221 = V_221 & 0xff ;
while ( V_221 ) {
if ( V_221 & 0x1 )
F_59 ( V_145 , V_225 L_80 , V_222 [ V_162 ] ) ;
V_162 ++ ;
V_221 >>= 1 ;
} ;
F_59 ( V_145 , V_225 L_81 ) ;
F_78 () ;
}
void T_1 F_142 ( void )
{
#ifdef F_84
if ( V_181 ) {
F_80 () ;
F_59 ( V_106 , L_82
L_83 ) ;
F_2 () ;
}
#endif
if ( V_15 -> V_226 )
V_15 -> V_226 () ;
}
void F_152 ( int V_227 )
{
unsigned int V_134 ;
#ifdef F_84
if ( V_181 ) {
F_59 ( V_106 , L_84
L_85 ) ;
F_4 () ;
return;
}
#endif
V_134 = F_14 ( V_135 ) ;
V_134 &= ~ V_152 ;
V_134 |= V_136 ;
V_134 |= 0xf ;
F_27 ( V_135 , V_134 ) ;
if ( ! V_227 ) {
V_134 = F_14 ( V_128 ) ;
V_134 &= ~ ( V_228 | V_229 |
V_230 | V_231 |
V_158 | V_36 ) ;
V_134 |= V_231 | V_229 ;
V_134 = F_153 ( V_134 , V_232 ) ;
F_27 ( V_128 , V_134 ) ;
} else {
F_27 ( V_128 , V_36 ) ;
}
V_134 = F_14 ( V_129 ) ;
V_134 &= ~ ( V_228 | V_229 |
V_230 | V_231 |
V_158 | V_36 ) ;
V_134 |= V_231 | V_229 ;
V_134 = F_153 ( V_134 , V_233 ) ;
F_27 ( V_129 , V_134 ) ;
}
void T_5 F_154 ( int V_6 , int V_234 )
{
int V_117 , V_235 = V_236 ;
bool V_237 = F_155 ( V_208 ,
V_214 ) ;
if ( ! V_237 && V_238 >= V_236 - 1 &&
V_6 != V_208 ) {
int V_239 = V_235 + V_240 - 1 ;
F_10 (
L_86
L_87
L_88 , V_235 , V_239 , V_6 ) ;
V_240 ++ ;
return;
}
if ( V_238 >= V_236 ) {
int V_239 = V_235 + V_240 ;
F_10 (
L_89
L_88 , V_235 , V_239 , V_6 ) ;
V_240 ++ ;
return;
}
V_238 ++ ;
if ( V_6 == V_208 ) {
V_117 = 0 ;
} else
V_117 = F_156 ( - 1 , V_241 ) ;
if ( V_234 == 0x0 ) {
F_10 ( L_90 ,
V_117 , V_6 ) ;
V_234 = 0x10 ;
}
V_210 [ V_6 ] = V_234 ;
if ( V_234 != V_210 [ V_208 ] ) {
F_10 ( L_91 ,
V_210 [ V_208 ] , V_117 , V_234 ) ;
}
F_157 ( V_6 , V_214 ) ;
if ( V_6 > V_198 )
V_198 = V_6 ;
#if F_158 ( F_48 ) || F_158 ( F_16 )
F_98 ( V_174 , V_117 ) = V_6 ;
F_98 ( V_242 , V_117 ) = V_6 ;
#endif
#ifdef F_84
F_98 ( V_171 , V_117 ) =
V_15 -> V_243 ( V_117 ) ;
#endif
F_159 ( V_117 , true ) ;
F_160 ( V_117 , true ) ;
}
int F_161 ( void )
{
return F_112 () ;
}
void F_162 ( void )
{
unsigned long V_244 ;
F_27 ( V_245 , V_246 ) ;
V_244 = F_14 ( V_247 ) & ~ V_248 ;
V_244 |= F_163 ( 1UL << F_42 () ) ;
F_27 ( V_247 , V_244 ) ;
}
static int F_164 ( void )
{
unsigned long V_64 ;
int V_123 ;
if ( ! V_249 . V_250 )
return 0 ;
V_123 = F_31 () ;
V_249 . V_251 = F_14 ( V_7 ) ;
V_249 . V_252 = F_14 ( V_175 ) ;
V_249 . V_253 = F_14 ( V_247 ) ;
V_249 . V_254 = F_14 ( V_245 ) ;
V_249 . V_255 = F_14 ( V_135 ) ;
V_249 . V_256 = F_14 ( V_37 ) ;
if ( V_123 >= 4 )
V_249 . V_257 = F_14 ( V_130 ) ;
V_249 . V_258 = F_14 ( V_128 ) ;
V_249 . V_259 = F_14 ( V_129 ) ;
V_249 . V_260 = F_14 ( V_127 ) ;
V_249 . V_261 = F_14 ( V_42 ) ;
V_249 . V_262 = F_14 ( V_38 ) ;
#ifdef F_81
if ( V_123 >= 5 )
V_249 . V_263 = F_14 ( V_131 ) ;
#endif
F_45 ( V_64 ) ;
F_83 () ;
if ( V_182 )
F_165 () ;
F_46 ( V_64 ) ;
return 0 ;
}
static void F_166 ( void )
{
unsigned int V_138 , V_139 ;
unsigned long V_64 ;
int V_123 ;
if ( ! V_249 . V_250 )
return;
F_45 ( V_64 ) ;
if ( V_182 ) {
F_129 () ;
V_195 -> V_196 () ;
}
if ( V_124 )
F_118 () ;
else {
if ( V_11 . V_14 >= 6 ) {
F_85 ( V_140 , V_138 , V_139 ) ;
V_138 &= ~ V_203 ;
V_138 |= V_141 | V_189 ;
F_86 ( V_140 , V_138 , V_139 ) ;
}
}
V_123 = F_31 () ;
F_27 ( V_127 , V_126 | V_36 ) ;
F_27 ( V_7 , V_249 . V_251 ) ;
F_27 ( V_245 , V_249 . V_254 ) ;
F_27 ( V_247 , V_249 . V_253 ) ;
F_27 ( V_175 , V_249 . V_252 ) ;
F_27 ( V_135 , V_249 . V_255 ) ;
F_27 ( V_128 , V_249 . V_258 ) ;
F_27 ( V_129 , V_249 . V_259 ) ;
#if F_158 ( V_264 ) || F_158 ( F_82 )
if ( V_123 >= 5 )
F_27 ( V_131 , V_249 . V_263 ) ;
#endif
if ( V_123 >= 4 )
F_27 ( V_130 , V_249 . V_257 ) ;
F_27 ( V_37 , V_249 . V_256 ) ;
F_27 ( V_38 , V_249 . V_262 ) ;
F_27 ( V_42 , V_249 . V_261 ) ;
F_27 ( V_133 , 0 ) ;
F_14 ( V_133 ) ;
F_27 ( V_127 , V_249 . V_260 ) ;
F_27 ( V_133 , 0 ) ;
F_14 ( V_133 ) ;
if ( V_182 )
F_167 ( V_124 ) ;
F_46 ( V_64 ) ;
}
static void T_5 F_105 ( void )
{
V_249 . V_250 = 1 ;
}
static int T_1 F_168 ( void )
{
if ( V_142 )
F_169 ( & V_265 ) ;
return 0 ;
}
static void F_105 ( void ) { }
static int T_5 F_170 ( void )
{
int V_162 , V_266 , V_267 ;
unsigned V_23 ;
T_7 * V_268 ;
F_171 ( V_269 , V_270 ) ;
V_268 = F_172 ( V_242 ) ;
F_173 ( V_269 , V_270 ) ;
for ( V_162 = 0 ; V_162 < V_236 ; V_162 ++ ) {
if ( V_268 ) {
V_23 = V_268 [ V_162 ] ;
} else if ( V_162 < V_236 ) {
if ( F_174 ( V_162 ) )
V_23 = F_72 ( V_242 , V_162 ) ;
else
continue;
} else
break;
if ( V_23 != V_172 )
F_175 ( F_176 ( V_23 ) , V_269 ) ;
}
V_266 = 0 ;
V_267 = 0 ;
for ( V_162 = 0 ; V_162 < V_270 ; V_162 ++ ) {
if ( F_177 ( V_162 , V_269 ) ) {
V_266 += 1 + V_267 ;
V_267 = 0 ;
} else
++ V_267 ;
}
return V_266 ;
}
static int T_5 F_178 ( const struct V_271 * V_272 )
{
if ( V_273 )
return 0 ;
F_20 ( L_92 , V_272 -> V_274 ) ;
V_273 = 1 ;
return 0 ;
}
static void T_5 F_179 ( void )
{
if ( V_275 )
return;
F_180 ( V_276 ) ;
V_275 = 1 ;
}
T_5 int F_181 ( void )
{
F_179 () ;
if ( V_273 )
return 1 ;
if ( ! F_182 () )
return 0 ;
if ( F_170 () > 1 )
return 1 ;
return 0 ;
}
static int T_1 F_183 ( char * V_1 )
{
V_168 = 1 ;
F_11 ( V_202 ) ;
return 0 ;
}
static int T_1 F_184 ( char * V_1 )
{
return F_183 ( V_1 ) ;
}
static int T_1 F_185 ( char * V_1 )
{
V_277 = 1 ;
return 0 ;
}
static int T_1 F_186 ( char * V_1 )
{
V_116 = 1 ;
return 0 ;
}
static int T_1 F_187 ( char * V_1 )
{
V_116 = 1 ;
return 0 ;
}
static int T_1 F_188 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_16
V_192 = 0 ;
return 0 ;
#endif
return - V_57 ;
}
if ( strcmp ( L_93 , V_1 ) == 0 )
V_278 = V_145 ;
else if ( strcmp ( L_94 , V_1 ) == 0 )
V_278 = V_106 ;
else {
F_10 ( L_95
L_96 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_1 F_189 ( void )
{
if ( ! V_125 )
return - 1 ;
V_279 . V_280 = V_125 ;
V_279 . V_281 = V_279 . V_280 + V_282 - 1 ;
F_190 ( & V_283 , & V_279 ) ;
return 0 ;
}
