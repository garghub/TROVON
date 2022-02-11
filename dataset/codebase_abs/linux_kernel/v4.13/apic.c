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
static T_2 F_54 ( void )
{
switch ( V_8 . V_70 ) {
case 0x02 : return 0x3a ;
case 0x04 : return 0x0f ;
}
return ~ 0U ;
}
static T_2 F_55 ( void )
{
switch ( V_8 . V_70 ) {
case 0x02 : return 0x00000011 ;
case 0x03 : return 0x0700000e ;
case 0x04 : return 0x0f00000c ;
case 0x05 : return 0x0e000003 ;
}
return ~ 0U ;
}
static void F_56 ( void )
{
const struct V_71 * V_72 = F_57 ( V_73 ) ;
T_2 V_74 ;
if ( ! V_72 )
return;
if ( ( long ) V_72 -> V_75 < 0 )
V_74 = ( ( T_2 ( * ) ( void ) ) ( V_72 -> V_75 ) ) ( ) ;
else
V_74 = ( T_2 ) V_72 -> V_75 ;
if ( V_8 . V_76 >= V_74 )
return;
F_6 ( V_4 ) ;
F_42 ( V_56 L_9
L_10 , V_74 ) ;
}
static void F_58 ( void )
{
struct V_60 * V_77 = F_59 ( & V_78 ) ;
if ( F_60 ( V_79 ) ) {
V_80 . V_65 &= ~ V_81 ;
V_80 . V_82 = 150 ;
}
memcpy ( V_77 , & V_80 , sizeof( * V_77 ) ) ;
V_77 -> V_68 = F_61 ( F_43 () ) ;
if ( F_60 ( V_4 ) ) {
V_77 -> V_83 = L_11 ;
V_77 -> V_65 &= ~ ( V_84 |
V_66 ) ;
V_77 -> V_85 = F_45 ;
F_62 ( V_77 ,
V_86 * ( 1000 / V_64 ) ,
0xF , ~ 0UL ) ;
} else
F_63 ( V_77 ) ;
}
static void F_64 ( void * V_87 )
{
struct V_60 * V_77 = F_59 ( & V_78 ) ;
if ( ! F_60 ( V_4 ) )
return;
F_65 ( V_77 , V_86 * ( 1000 / V_64 ) ) ;
}
void F_66 ( void )
{
F_67 ( F_64 , NULL , 0 ) ;
}
static void T_1 F_68 ( struct V_60 * V_88 )
{
unsigned long long V_62 = 0 ;
long V_89 = F_11 ( V_90 ) ;
unsigned long V_91 = F_69 () ;
if ( F_33 ( V_92 ) )
V_62 = F_46 () ;
switch ( V_93 ++ ) {
case 0 :
V_94 = V_89 ;
V_95 = V_62 ;
V_96 = V_91 ;
V_97 = V_98 ;
break;
case V_99 :
V_100 = V_89 ;
V_101 = V_62 ;
if ( V_91 < V_96 )
V_91 += V_102 ;
V_103 = V_91 ;
V_104 = V_98 ;
break;
}
}
static int T_1
F_70 ( long V_105 , long * V_59 , long * V_106 )
{
const long V_107 = V_108 / 10 ;
const long V_109 = V_107 / 100 ;
unsigned long V_110 ;
T_3 V_111 ;
#ifndef F_71
return - 1 ;
#endif
F_72 ( V_112 , L_12 , V_105 ) ;
if ( ! V_105 )
return - 1 ;
V_110 = F_73 ( V_108 , 22 ) ;
if ( V_105 > ( V_107 - V_109 ) &&
V_105 < ( V_107 + V_109 ) ) {
F_72 ( V_112 , L_13 ) ;
return 0 ;
}
V_111 = ( ( ( T_3 ) V_105 ) * V_110 ) >> 22 ;
F_74 ( V_111 , 1000000 ) ;
F_75 ( L_14
L_15 , ( long ) V_111 ) ;
V_111 = ( ( ( T_3 ) ( * V_59 ) ) * V_107 ) ;
F_74 ( V_111 , V_105 ) ;
F_17 ( L_16
L_17 , ( unsigned long ) V_111 , * V_59 ) ;
* V_59 = ( long ) V_111 ;
if ( F_33 ( V_92 ) ) {
V_111 = ( ( ( T_3 ) ( * V_106 ) ) * V_107 ) ;
F_74 ( V_111 , V_105 ) ;
F_72 ( V_112 , L_18
L_19 ,
( unsigned long ) V_111 , * V_106 ) ;
* V_106 = ( long ) V_111 ;
}
return 0 ;
}
static int T_1 F_76 ( void )
{
struct V_60 * V_77 = F_59 ( & V_78 ) ;
void (* F_77)( struct V_60 * V_88 );
unsigned long V_113 ;
long V_59 , V_106 ;
int V_114 = 0 ;
if ( F_33 ( V_4 ) ) {
return 0 ;
} else if ( V_67 ) {
F_72 ( V_112 , L_20 ,
V_67 ) ;
V_80 . V_110 = F_78 ( V_67 / V_43 ,
V_115 , V_80 . V_116 ) ;
V_80 . V_117 =
F_79 ( 0x7FFFFF , & V_80 ) ;
V_80 . V_118 = 0x7FFFFF ;
V_80 . V_119 =
F_79 ( 0xF , & V_80 ) ;
V_80 . V_120 = 0xF ;
V_80 . V_65 &= ~ V_66 ;
return 0 ;
}
F_72 ( V_112 , L_21
L_22 ) ;
F_80 () ;
F_77 = V_121 -> V_122 ;
V_121 -> V_122 = F_68 ;
F_32 ( 0xffffffff , 0 , 0 ) ;
F_81 () ;
while ( V_93 <= V_99 )
F_19 () ;
F_80 () ;
V_121 -> V_122 = F_77 ;
V_59 = V_94 - V_100 ;
F_72 ( V_112 , L_23 , V_59 ) ;
V_106 = ( long ) ( V_101 - V_95 ) ;
V_114 = ! F_70 ( V_103 - V_96 ,
& V_59 , & V_106 ) ;
V_80 . V_110 = F_78 ( V_59 , V_115 * V_99 ,
V_80 . V_116 ) ;
V_80 . V_117 =
F_79 ( 0x7FFFFFFF , & V_80 ) ;
V_80 . V_118 = 0x7FFFFFFF ;
V_80 . V_119 =
F_79 ( 0xF , & V_80 ) ;
V_80 . V_120 = 0xF ;
V_67 = ( V_59 * V_43 ) / V_99 ;
F_72 ( V_112 , L_24 , V_59 ) ;
F_72 ( V_112 , L_25 , V_80 . V_110 ) ;
F_72 ( V_112 , L_26 ,
V_67 ) ;
if ( F_33 ( V_92 ) ) {
F_72 ( V_112 , L_27
L_28 ,
( V_106 / V_99 ) / ( 1000000 / V_123 ) ,
( V_106 / V_99 ) % ( 1000000 / V_123 ) ) ;
}
F_72 ( V_112 , L_29
L_30 ,
V_67 / ( 1000000 / V_123 ) ,
V_67 % ( 1000000 / V_123 ) ) ;
if ( V_67 < ( 1000000 / V_123 ) ) {
F_81 () ;
F_75 ( L_31 ) ;
return - 1 ;
}
V_77 -> V_65 &= ~ V_66 ;
if ( ! V_114 ) {
F_72 ( V_112 , L_32 ) ;
V_77 -> V_122 = F_68 ;
F_50 ( V_77 ) ;
V_93 = - 1 ;
F_81 () ;
while ( V_93 <= V_99 )
F_19 () ;
F_80 () ;
F_48 ( V_77 ) ;
V_113 = V_104 - V_97 ;
F_72 ( V_112 , L_33 , V_113 ) ;
if ( V_113 >= V_99 - 2 && V_113 <= V_99 + 2 )
F_72 ( V_112 , L_34 ) ;
else
V_77 -> V_65 |= V_66 ;
}
F_81 () ;
if ( V_77 -> V_65 & V_66 ) {
F_75 ( L_35 ) ;
return - 1 ;
}
return 0 ;
}
void T_1 F_82 ( void )
{
if ( V_124 ) {
F_17 ( L_36 ) ;
if ( F_83 () > 1 ) {
V_80 . V_110 = 1 ;
F_58 () ;
}
return;
}
if ( F_76 () ) {
if ( F_83 () > 1 )
F_58 () ;
return;
}
V_80 . V_65 &= ~ V_66 ;
F_58 () ;
F_84 () ;
}
void F_85 ( void )
{
F_58 () ;
F_84 () ;
}
static void F_86 ( void )
{
int V_125 = F_43 () ;
struct V_60 * V_61 = & F_87 ( V_78 , V_125 ) ;
if ( ! V_61 -> V_122 ) {
F_75 ( L_37 , V_125 ) ;
F_48 ( V_61 ) ;
return;
}
F_21 ( V_126 ) ;
V_61 -> V_122 ( V_61 ) ;
}
T_5 void T_6 F_88 ( struct V_127 * V_128 )
{
struct V_127 * V_129 = F_89 ( V_128 ) ;
F_90 () ;
F_86 () ;
F_91 () ;
F_89 ( V_129 ) ;
}
T_5 void T_6 F_92 ( struct V_127 * V_128 )
{
struct V_127 * V_129 = F_89 ( V_128 ) ;
F_90 () ;
F_93 ( V_31 ) ;
F_86 () ;
F_94 ( V_31 ) ;
F_91 () ;
F_89 ( V_129 ) ;
}
int F_95 ( unsigned int V_130 )
{
return - V_57 ;
}
void F_96 ( void )
{
int V_131 ;
T_2 V_25 ;
if ( ! V_132 && ! V_133 )
return;
V_131 = F_30 () ;
if ( V_131 >= 3 ) {
V_25 = V_134 ;
F_25 ( V_135 , V_25 | V_35 ) ;
}
V_25 = F_11 ( V_36 ) ;
F_25 ( V_36 , V_25 | V_35 ) ;
V_25 = F_11 ( V_136 ) ;
F_25 ( V_136 , V_25 | V_35 ) ;
V_25 = F_11 ( V_137 ) ;
F_25 ( V_137 , V_25 | V_35 ) ;
if ( V_131 >= 4 ) {
V_25 = F_11 ( V_138 ) ;
F_25 ( V_138 , V_25 | V_35 ) ;
}
#ifdef F_97
if ( V_131 >= 5 ) {
V_25 = F_11 ( V_139 ) ;
F_25 ( V_139 , V_25 | V_35 ) ;
}
#endif
#ifdef F_98
if ( V_131 >= 6 ) {
V_25 = F_11 ( V_140 ) ;
if ( ! ( V_25 & V_35 ) )
F_25 ( V_140 , V_25 | V_35 ) ;
}
#endif
F_25 ( V_36 , V_35 ) ;
F_25 ( V_136 , V_35 ) ;
F_25 ( V_137 , V_35 ) ;
if ( V_131 >= 3 )
F_25 ( V_135 , V_35 ) ;
if ( V_131 >= 4 )
F_25 ( V_138 , V_35 ) ;
if ( F_12 () ) {
if ( V_131 > 3 )
F_25 ( V_141 , 0 ) ;
F_11 ( V_141 ) ;
}
}
void F_99 ( void )
{
unsigned int V_142 ;
if ( ! V_132 && ! V_133 )
return;
F_96 () ;
V_142 = F_11 ( V_143 ) ;
V_142 &= ~ V_144 ;
F_25 ( V_143 , V_142 ) ;
#ifdef V_2
if ( V_145 ) {
unsigned int V_146 , V_147 ;
F_100 ( V_148 , V_146 , V_147 ) ;
V_146 &= ~ V_149 ;
F_101 ( V_148 , V_146 , V_147 ) ;
}
#endif
}
void F_102 ( void )
{
unsigned long V_21 ;
if ( ! F_33 ( V_150 ) && ! F_103 () )
return;
F_24 ( V_21 ) ;
#ifdef V_2
if ( ! V_145 )
F_96 () ;
else
#endif
F_99 () ;
F_27 ( V_21 ) ;
}
void T_1 F_104 ( void )
{
if ( F_15 () || V_8 . V_9 == V_10 )
return;
F_105 () ;
F_72 ( V_151 , L_38 ) ;
F_25 ( V_14 , V_152 |
V_153 | V_154 ) ;
}
void T_1 F_106 ( void )
{
unsigned int V_142 ;
if ( V_155 || ! F_33 ( V_150 ) )
return;
F_96 () ;
V_142 = F_11 ( V_143 ) ;
V_142 &= ~ V_156 ;
V_142 |= V_144 ;
#ifdef V_2
if ( ( V_8 . V_9 == V_157 ) &&
( V_8 . V_11 == 15 ) )
V_142 &= ~ V_158 ;
else
#endif
V_142 |= V_158 ;
V_142 |= V_159 ;
F_25 ( V_143 , V_142 ) ;
F_25 ( V_136 , V_160 ) ;
V_142 = V_161 ;
if ( ! F_12 () )
V_142 |= V_162 ;
if ( V_163 == V_164 )
V_142 |= V_35 ;
F_25 ( V_137 , V_142 ) ;
}
static void F_107 ( void )
{
unsigned int V_165 , V_142 , V_131 ;
if ( ! F_12 () ) {
F_17 ( L_39 ) ;
return;
}
if ( V_12 -> V_166 ) {
F_17 ( L_40 ) ;
return;
}
V_131 = F_30 () ;
if ( V_131 > 3 )
F_25 ( V_141 , 0 ) ;
V_165 = F_11 ( V_141 ) ;
V_142 = V_134 ;
F_25 ( V_135 , V_142 ) ;
if ( V_131 > 3 )
F_25 ( V_141 , 0 ) ;
V_142 = F_11 ( V_141 ) ;
if ( V_142 != V_165 )
F_72 ( V_112 , L_41
L_42 ,
V_165 , V_142 ) ;
}
void F_108 ( void )
{
int V_125 = F_43 () ;
unsigned int V_142 , V_167 ;
int V_168 , V_169 , V_170 = 0 ;
unsigned long long V_62 = 0 , V_171 ;
long long V_172 = V_173 ? V_173 : 1000000 ;
if ( F_33 ( V_92 ) )
V_62 = F_46 () ;
if ( V_174 ) {
F_109 () ;
return;
}
#ifdef V_2
if ( F_12 () && V_12 -> V_166 ) {
F_25 ( V_141 , 0 ) ;
F_25 ( V_141 , 0 ) ;
F_25 ( V_141 , 0 ) ;
F_25 ( V_141 , 0 ) ;
}
#endif
F_110 () ;
F_111 ( ! V_12 -> V_175 () ) ;
V_12 -> V_176 () ;
#ifdef V_2
V_168 = F_112 ( V_177 , V_125 ) ;
F_113 ( V_168 != V_178 && V_168 != F_114 () ) ;
F_112 ( V_177 , V_125 ) =
F_114 () ;
#endif
V_142 = F_11 ( V_179 ) ;
V_142 &= ~ V_180 ;
F_25 ( V_179 , V_142 ) ;
do {
V_167 = 0 ;
for ( V_168 = V_181 - 1 ; V_168 >= 0 ; V_168 -- )
V_167 |= F_11 ( V_182 + V_168 * 0x10 ) ;
for ( V_168 = V_181 - 1 ; V_168 >= 0 ; V_168 -- ) {
V_142 = F_11 ( V_183 + V_168 * 0x10 ) ;
for ( V_169 = 31 ; V_169 >= 0 ; V_169 -- ) {
if ( V_142 & ( 1 << V_169 ) ) {
F_115 () ;
V_170 ++ ;
}
}
}
if ( V_170 > 256 ) {
F_116 ( V_184 L_43 ,
V_170 ) ;
break;
}
if ( V_167 ) {
if ( F_33 ( V_92 ) && V_173 ) {
V_171 = F_46 () ;
V_172 = ( V_173 << 10 ) - ( V_171 - V_62 ) ;
} else
V_172 -- ;
}
} while ( V_167 && V_172 > 0 );
F_113 ( V_172 <= 0 ) ;
V_142 = F_11 ( V_143 ) ;
V_142 &= ~ V_156 ;
V_142 |= V_144 ;
#ifdef V_2
V_142 &= ~ V_158 ;
#endif
V_142 |= V_159 ;
F_25 ( V_143 , V_142 ) ;
V_142 = F_11 ( V_136 ) & V_35 ;
if ( ! V_125 && ( V_185 || ! V_142 ) ) {
V_142 = V_160 ;
F_72 ( V_112 , L_44 , V_125 ) ;
} else {
V_142 = V_160 | V_35 ;
F_72 ( V_112 , L_45 , V_125 ) ;
}
F_25 ( V_136 , V_142 ) ;
if ( ( ! V_125 && V_163 != V_164 ) ||
V_163 == V_186 )
V_142 = V_161 ;
else
V_142 = V_161 | V_35 ;
if ( ! F_12 () )
V_142 |= V_162 ;
F_25 ( V_137 , V_142 ) ;
#ifdef F_98
if ( ! V_125 )
F_117 () ;
#endif
}
static void F_118 ( void )
{
F_107 () ;
#ifdef V_2
{
unsigned int V_142 ;
V_142 = F_11 ( V_36 ) ;
V_142 |= ( V_35 | V_31 ) ;
F_25 ( V_36 , V_142 ) ;
}
#endif
F_119 () ;
}
void F_120 ( void )
{
F_108 () ;
F_118 () ;
}
static void F_121 ( void )
{
T_3 V_187 ;
if ( ! F_33 ( V_150 ) )
return;
F_122 ( V_148 , V_187 ) ;
if ( ! ( V_187 & V_188 ) )
return;
F_47 ( V_148 , V_187 & ~ ( V_188 | V_189 ) ) ;
F_47 ( V_148 , V_187 & ~ V_188 ) ;
F_35 ( V_190 L_46 ) ;
}
static void F_123 ( void )
{
T_3 V_187 ;
F_122 ( V_148 , V_187 ) ;
if ( V_187 & V_188 )
return;
F_47 ( V_148 , V_187 | V_188 ) ;
F_35 ( V_190 L_47 ) ;
}
static int T_1 F_124 ( char * V_191 )
{
if ( F_125 () ) {
int V_192 = F_126 ( V_193 ) ;
if ( V_192 >= 255 ) {
F_75 ( L_48 ,
V_192 ) ;
return 0 ;
}
F_75 ( L_49 ) ;
F_121 () ;
}
F_6 ( V_194 ) ;
V_195 = V_196 ;
V_132 = 0 ;
return 0 ;
}
void F_127 ( void )
{
if ( V_195 != V_197 ) {
F_121 () ;
return;
}
F_123 () ;
}
static T_1 void F_128 ( void )
{
T_2 V_198 , V_199 = V_195 ;
V_132 = 0 ;
V_195 = V_196 ;
if ( V_199 != V_197 )
return;
V_198 = F_129 () ;
if ( V_198 >= 255 )
F_130 ( L_50 , V_198 ) ;
F_121 () ;
F_131 ( V_200 ) ;
}
static T_1 void F_132 ( void )
{
if ( V_195 != V_201 )
return;
V_132 = 1 ;
V_195 = V_197 ;
F_123 () ;
}
static T_1 void F_133 ( int V_202 )
{
if ( V_195 == V_196 )
return;
if ( V_202 != V_203 ) {
if ( V_204 > 255 ||
! F_134 () ) {
F_17 ( L_51 ) ;
F_128 () ;
return;
}
V_205 = 1 ;
}
F_132 () ;
}
void T_1 F_135 ( void )
{
if ( F_125 () ) {
F_17 ( L_52 ) ;
V_132 = 1 ;
V_195 = V_197 ;
} else if ( ! F_33 ( V_194 ) ) {
V_195 = V_196 ;
}
}
static int T_1 F_136 ( void )
{
if ( ! F_137 () )
return 0 ;
F_130 ( L_53 ) ;
}
static inline void F_133 ( int V_202 ) { }
static inline void F_123 ( void ) { }
void T_1 F_138 ( void )
{
unsigned long V_21 ;
int V_206 , V_207 ;
if ( V_208 ) {
F_17 ( L_54 ) ;
return;
}
V_207 = F_139 () ;
if ( V_207 < 0 && ! F_140 () )
return;
V_206 = F_141 () ;
if ( V_206 ) {
F_17 ( L_55 , V_206 ) ;
return;
}
F_24 ( V_21 ) ;
V_209 -> V_210 () ;
F_142 () ;
if ( V_207 >= 0 )
V_207 = F_143 () ;
F_133 ( V_207 ) ;
if ( V_207 < 0 )
F_144 () ;
V_209 -> V_211 () ;
F_27 ( V_21 ) ;
}
static int T_1 F_145 ( void )
{
if ( ! F_33 ( V_150 ) ) {
F_17 ( L_56 ) ;
return - 1 ;
}
V_200 = V_212 ;
return 0 ;
}
static int T_1 F_146 ( void )
{
T_2 V_65 , V_147 , V_146 ;
V_65 = F_147 ( 1 ) ;
if ( ! ( V_65 & ( 1 << V_150 ) ) ) {
F_75 ( L_57 ) ;
return - 1 ;
}
F_148 ( & V_8 , V_150 ) ;
V_200 = V_212 ;
if ( V_8 . V_11 >= 6 ) {
F_100 ( V_148 , V_146 , V_147 ) ;
if ( V_146 & V_149 )
V_200 = V_146 & V_213 ;
}
F_17 ( L_58 ) ;
return 0 ;
}
int T_1 F_149 ( unsigned long V_214 )
{
T_2 V_147 , V_146 ;
if ( V_174 )
return - 1 ;
if ( V_8 . V_11 >= 6 ) {
F_100 ( V_148 , V_146 , V_147 ) ;
if ( ! ( V_146 & V_149 ) ) {
F_17 ( L_59 ) ;
V_146 &= ~ V_213 ;
V_146 |= V_149 | V_214 ;
F_101 ( V_148 , V_146 , V_147 ) ;
V_145 = 1 ;
}
}
return F_146 () ;
}
static int T_1 F_145 ( void )
{
if ( V_174 )
return - 1 ;
switch ( V_8 . V_9 ) {
case V_10 :
if ( ( V_8 . V_11 == 6 && V_8 . V_215 > 1 ) ||
( V_8 . V_11 >= 15 ) )
break;
goto V_216;
case V_157 :
if ( V_8 . V_11 == 6 || V_8 . V_11 == 15 ||
( V_8 . V_11 == 5 && F_33 ( V_150 ) ) )
break;
goto V_216;
default:
goto V_216;
}
if ( ! F_33 ( V_150 ) ) {
if ( ! V_3 ) {
F_17 ( L_60
L_61 ) ;
return - 1 ;
}
if ( F_149 ( V_212 ) )
return - 1 ;
} else {
if ( F_146 () )
return - 1 ;
}
F_119 () ;
return 0 ;
V_216:
F_17 ( L_62 ) ;
return - 1 ;
}
void T_1 F_150 ( void )
{
unsigned int V_217 ;
F_56 () ;
if ( V_132 ) {
V_218 = F_129 () ;
return;
}
if ( ! V_155 && F_145 () ) {
F_17 ( L_63 ) ;
F_16 () ;
} else {
V_133 = V_200 ;
if ( ! V_219 && ! V_155 )
F_131 ( V_133 ) ;
}
V_217 = F_129 () ;
if ( V_218 != V_217 ) {
V_218 = V_217 ;
V_220 = F_10 ( F_11 ( V_7 ) ) ;
}
}
void T_1 F_131 ( unsigned long V_221 )
{
V_200 = V_221 ;
if ( ! V_132 ) {
F_151 ( V_222 , V_221 ) ;
F_72 ( V_112 , L_64 ,
V_223 , V_221 ) ;
}
if ( V_218 == - 1U ) {
V_218 = F_129 () ;
V_220 = F_10 ( F_11 ( V_7 ) ) ;
}
}
static void F_152 ( T_4 V_49 )
{
T_2 V_25 ;
V_25 = F_11 ( V_183 + ( ( V_49 & ~ 0x1f ) >> 1 ) ) ;
if ( V_25 & ( 1 << ( V_49 & 0x1f ) ) )
F_115 () ;
F_21 ( V_224 ) ;
F_17 ( L_65
L_66 , V_49 , F_43 () ) ;
}
T_5 void T_6 F_153 ( struct V_127 * V_128 )
{
F_154 () ;
F_152 ( ~ V_128 -> V_225 ) ;
F_91 () ;
}
T_5 void T_6 F_155 ( struct V_127 * V_128 )
{
T_4 V_49 = ~ V_128 -> V_225 ;
F_154 () ;
F_156 ( V_49 ) ;
F_152 ( V_49 ) ;
F_157 ( V_49 ) ;
F_91 () ;
}
static void F_158 ( struct V_127 * V_128 )
{
T_2 V_25 ;
T_2 V_168 = 0 ;
static const char * const V_226 [] = {
L_67 ,
L_68 ,
L_69 ,
L_70 ,
L_71 ,
L_72 ,
L_73 ,
L_74 ,
} ;
if ( F_30 () > 3 )
F_25 ( V_141 , 0 ) ;
V_25 = F_11 ( V_141 ) ;
F_115 () ;
F_159 ( & V_227 ) ;
F_72 ( V_151 , V_37 L_75 ,
F_43 () , V_25 ) ;
V_25 &= 0xff ;
while ( V_25 ) {
if ( V_25 & 0x1 )
F_72 ( V_151 , V_228 L_76 , V_226 [ V_168 ] ) ;
V_168 ++ ;
V_25 >>= 1 ;
}
F_72 ( V_151 , V_228 L_77 ) ;
}
T_5 void T_6 F_160 ( struct V_127 * V_128 )
{
F_154 () ;
F_158 ( V_128 ) ;
F_91 () ;
}
T_5 void T_6 F_161 ( struct V_127 * V_128 )
{
F_154 () ;
F_162 ( V_134 ) ;
F_158 ( V_128 ) ;
F_163 ( V_134 ) ;
F_91 () ;
}
static void T_1 F_164 ( void )
{
#ifdef V_2
if ( V_185 ) {
F_96 () ;
F_72 ( V_112 , L_78
L_79 ) ;
F_1 () ;
}
#endif
}
void F_165 ( int V_229 )
{
unsigned int V_142 ;
#ifdef V_2
if ( V_185 ) {
F_72 ( V_112 , L_80
L_81 ) ;
F_3 () ;
return;
}
#endif
V_142 = F_11 ( V_143 ) ;
V_142 &= ~ V_156 ;
V_142 |= V_144 ;
V_142 |= 0xf ;
F_25 ( V_143 , V_142 ) ;
if ( ! V_229 ) {
V_142 = F_11 ( V_136 ) ;
V_142 &= ~ ( V_230 | V_231 |
V_232 | V_233 |
V_162 | V_35 ) ;
V_142 |= V_233 | V_231 ;
V_142 = F_166 ( V_142 , V_234 ) ;
F_25 ( V_136 , V_142 ) ;
} else {
F_25 ( V_136 , V_35 ) ;
}
V_142 = F_11 ( V_137 ) ;
V_142 &= ~ ( V_230 | V_231 |
V_232 | V_233 |
V_162 | V_35 ) ;
V_142 |= V_233 | V_231 ;
V_142 = F_166 ( V_142 , V_235 ) ;
F_25 ( V_137 , V_142 ) ;
}
static int F_167 ( int V_192 )
{
int V_168 ;
for ( V_168 = 0 ; V_168 < V_236 ; V_168 ++ ) {
if ( V_237 [ V_168 ] == V_192 )
return V_168 ;
}
if ( V_236 >= V_238 ) {
F_168 ( 1 , L_82
L_83 ,
V_238 , V_236 , V_192 ) ;
return - V_57 ;
}
V_237 [ V_236 ] = V_192 ;
return V_236 ++ ;
}
int F_169 ( int V_192 , int V_239 )
{
int V_125 , V_240 = V_238 ;
bool V_241 = F_170 ( V_218 ,
V_242 ) ;
if ( V_243 != V_178 &&
V_243 != F_129 () &&
V_243 == V_192 ) {
int V_244 = V_245 + V_246 ;
F_75 ( L_84
L_85 ,
V_244 , V_192 ) ;
V_246 ++ ;
return - V_247 ;
}
if ( ! V_241 && V_245 >= V_238 - 1 &&
V_192 != V_218 ) {
int V_244 = V_240 + V_246 - 1 ;
F_75 (
L_86
L_87
L_88 , V_240 , V_244 , V_192 ) ;
V_246 ++ ;
return - V_247 ;
}
if ( V_245 >= V_238 ) {
int V_244 = V_240 + V_246 ;
F_75 ( L_89
L_90 ,
V_240 , V_244 , V_192 ) ;
V_246 ++ ;
return - V_57 ;
}
if ( V_192 == V_218 ) {
V_125 = 0 ;
V_237 [ 0 ] = V_192 ;
} else {
V_125 = F_167 ( V_192 ) ;
if ( V_125 < 0 ) {
V_246 ++ ;
return - V_57 ;
}
}
if ( V_239 == 0x0 ) {
F_75 ( L_91 ,
V_125 , V_192 ) ;
V_239 = 0x10 ;
}
if ( V_239 != V_220 ) {
F_75 ( L_92 ,
V_220 , V_125 , V_239 ) ;
}
if ( V_192 > V_204 )
V_204 = V_192 ;
#if F_171 ( F_53 ) || F_171 ( F_13 )
F_112 ( V_248 , V_125 ) = V_192 ;
F_112 ( V_249 , V_125 ) = V_192 ;
#endif
#ifdef V_2
F_112 ( V_177 , V_125 ) =
V_12 -> V_250 ( V_125 ) ;
#endif
F_172 ( V_125 , true ) ;
F_173 ( V_192 , V_242 ) ;
F_174 ( V_125 , true ) ;
V_245 ++ ;
return V_125 ;
}
int F_175 ( void )
{
return F_129 () ;
}
void F_176 ( void )
{
unsigned long V_251 ;
F_25 ( V_252 , V_253 ) ;
V_251 = F_11 ( V_254 ) & ~ V_255 ;
V_251 |= F_177 ( 1UL << F_43 () ) ;
F_25 ( V_254 , V_251 ) ;
}
int F_178 ( const struct V_68 * V_53 ,
struct V_256 * V_257 ,
unsigned int * V_192 )
{
unsigned int V_125 = F_179 ( V_53 ) ;
if ( V_125 >= V_238 )
return - V_57 ;
* V_192 = F_87 ( V_248 , V_125 ) ;
F_180 ( V_257 , F_61 ( V_125 ) ) ;
return 0 ;
}
int F_181 ( const struct V_68 * V_53 ,
struct V_256 * V_257 ,
unsigned int * V_192 )
{
struct V_68 * V_258 = F_182 ( V_257 ) ;
unsigned long V_259 = F_183 ( V_53 ) [ 0 ] & V_260 ;
if ( ! V_259 )
return - V_57 ;
* V_192 = ( unsigned int ) V_259 ;
F_183 ( V_258 ) [ 0 ] = V_259 ;
return 0 ;
}
void T_1 F_184 ( void (* F_185)( T_2 V_54 , T_2 V_25 ) )
{
struct V_12 * * V_261 ;
for ( V_261 = V_262 ; V_261 < V_263 ; V_261 ++ ) {
F_113 ( ( * V_261 ) -> F_185 == F_185 ) ;
( * V_261 ) -> V_264 = ( * V_261 ) -> F_185 ;
( * V_261 ) -> F_185 = F_185 ;
}
}
static void T_1 F_186 ( void )
{
#ifdef F_13
F_25 ( V_193 , V_12 -> V_265 ( V_218 ) ) ;
#else
# ifdef F_187
V_218 = F_129 () ;
# endif
#endif
F_188 ( V_218 , & V_242 ) ;
}
int T_1 F_189 ( bool V_266 )
{
int V_20 ;
F_164 () ;
if ( V_266 )
F_186 () ;
F_108 () ;
if ( V_132 )
V_20 = F_11 ( V_254 ) ;
else
V_20 = F_190 ( F_11 ( V_254 ) ) ;
F_191 () ;
F_118 () ;
F_192 () ;
F_193 () ;
V_267 . V_268 . V_269 () ;
return V_20 ;
}
int T_1 F_194 ( void )
{
if ( V_174 ) {
F_17 ( L_93 ) ;
return - 1 ;
}
#ifdef F_13
if ( ! F_33 ( V_150 ) ) {
V_174 = 1 ;
F_17 ( L_94 ) ;
return - 1 ;
}
#else
if ( ! V_155 && ! F_33 ( V_150 ) )
return - 1 ;
if ( ! F_33 ( V_150 ) &&
F_14 ( V_220 ) ) {
F_42 ( L_95 ,
V_218 ) ;
return - 1 ;
}
#endif
if ( ! V_155 )
F_109 () ;
F_195 () ;
F_189 ( true ) ;
return 0 ;
}
void T_1 F_196 ( void )
{
F_194 () ;
}
static int F_197 ( void )
{
unsigned long V_21 ;
int V_131 ;
if ( ! V_270 . V_271 )
return 0 ;
V_131 = F_30 () ;
V_270 . V_272 = F_11 ( V_193 ) ;
V_270 . V_273 = F_11 ( V_179 ) ;
V_270 . V_274 = F_11 ( V_254 ) ;
V_270 . V_275 = F_11 ( V_252 ) ;
V_270 . V_276 = F_11 ( V_143 ) ;
V_270 . V_277 = F_11 ( V_36 ) ;
if ( V_131 >= 4 )
V_270 . V_278 = F_11 ( V_138 ) ;
V_270 . V_279 = F_11 ( V_136 ) ;
V_270 . V_280 = F_11 ( V_137 ) ;
V_270 . V_281 = F_11 ( V_135 ) ;
V_270 . V_282 = F_11 ( V_42 ) ;
V_270 . V_283 = F_11 ( V_38 ) ;
#ifdef F_97
if ( V_131 >= 5 )
V_270 . V_284 = F_11 ( V_139 ) ;
#endif
#ifdef F_98
if ( V_131 >= 6 )
V_270 . V_285 = F_11 ( V_140 ) ;
#endif
F_24 ( V_21 ) ;
F_99 () ;
F_198 () ;
F_27 ( V_21 ) ;
return 0 ;
}
static void F_199 ( void )
{
unsigned int V_146 , V_147 ;
unsigned long V_21 ;
int V_131 ;
if ( ! V_270 . V_271 )
return;
F_24 ( V_21 ) ;
F_142 () ;
V_209 -> V_210 () ;
if ( V_132 ) {
F_123 () ;
} else {
if ( V_8 . V_11 >= 6 ) {
F_100 ( V_148 , V_146 , V_147 ) ;
V_146 &= ~ V_213 ;
V_146 |= V_149 | V_200 ;
F_101 ( V_148 , V_146 , V_147 ) ;
}
}
V_131 = F_30 () ;
F_25 ( V_135 , V_134 | V_35 ) ;
F_25 ( V_193 , V_270 . V_272 ) ;
F_25 ( V_252 , V_270 . V_275 ) ;
F_25 ( V_254 , V_270 . V_274 ) ;
F_25 ( V_179 , V_270 . V_273 ) ;
F_25 ( V_143 , V_270 . V_276 ) ;
F_25 ( V_136 , V_270 . V_279 ) ;
F_25 ( V_137 , V_270 . V_280 ) ;
#ifdef F_97
if ( V_131 >= 5 )
F_25 ( V_139 , V_270 . V_284 ) ;
#endif
#ifdef F_98
if ( V_131 >= 6 )
F_25 ( V_140 , V_270 . V_285 ) ;
#endif
if ( V_131 >= 4 )
F_25 ( V_138 , V_270 . V_278 ) ;
F_25 ( V_36 , V_270 . V_277 ) ;
F_25 ( V_38 , V_270 . V_283 ) ;
F_25 ( V_42 , V_270 . V_282 ) ;
F_25 ( V_141 , 0 ) ;
F_11 ( V_141 ) ;
F_25 ( V_135 , V_270 . V_281 ) ;
F_25 ( V_141 , 0 ) ;
F_11 ( V_141 ) ;
F_200 ( V_132 ) ;
F_27 ( V_21 ) ;
}
static void F_119 ( void )
{
V_270 . V_271 = 1 ;
}
static int T_1 F_201 ( void )
{
if ( F_33 ( V_150 ) )
F_202 ( & V_286 ) ;
return 0 ;
}
static void F_119 ( void ) { }
static int F_203 ( const struct V_287 * V_288 )
{
if ( V_289 )
return 0 ;
F_17 ( L_96 , V_288 -> V_290 ) ;
V_289 = 1 ;
return 0 ;
}
static void F_204 ( void )
{
if ( V_291 )
return;
F_205 ( V_292 ) ;
V_291 = 1 ;
}
int F_206 ( void )
{
F_204 () ;
return V_289 ;
}
static int T_1 F_207 ( char * V_1 )
{
V_174 = 1 ;
F_6 ( V_150 ) ;
return 0 ;
}
static int T_1 F_208 ( char * V_1 )
{
return F_207 ( V_1 ) ;
}
static int T_1 F_209 ( char * V_1 )
{
V_293 = 1 ;
return 0 ;
}
static int T_1 F_210 ( char * V_1 )
{
V_124 = 1 ;
return 0 ;
}
static int T_1 F_211 ( char * V_1 )
{
V_124 = 1 ;
return 0 ;
}
static int T_1 F_212 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_13
V_208 = 0 ;
return 0 ;
#endif
return - V_57 ;
}
if ( strcmp ( L_97 , V_1 ) == 0 )
V_294 = V_151 ;
else if ( strcmp ( L_98 , V_1 ) == 0 )
V_294 = V_112 ;
else {
F_75 ( L_99
L_100 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_1 F_213 ( void )
{
if ( ! V_133 )
return - 1 ;
V_295 . V_296 = V_133 ;
V_295 . V_297 = V_295 . V_296 + V_298 - 1 ;
F_214 ( & V_299 , & V_295 ) ;
return 0 ;
}
static int T_1 F_215 ( char * V_1 )
{
if ( ! V_1 || ! F_216 ( & V_1 , & V_243 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_217 ( char * V_1 )
{
if ( ! V_1 )
return - V_57 ;
if ( ! strncmp ( L_101 , V_1 , 3 ) )
V_163 = V_186 ;
else if ( ! strncmp ( L_102 , V_1 , 4 ) )
V_163 = V_164 ;
else if ( ! strncmp ( L_103 , V_1 , 3 ) )
V_163 = V_300 ;
else {
F_218 ( L_104 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
