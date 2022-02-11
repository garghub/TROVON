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
static T_2 F_56 ( void )
{
switch ( V_8 . V_70 ) {
case 0x03 : return 0x01000136 ;
case 0x04 : return 0x02000014 ;
}
return ~ 0U ;
}
static void F_57 ( void )
{
const struct V_71 * V_72 ;
T_2 V_73 ;
if ( ! F_33 ( V_4 ) ||
F_33 ( V_74 ) )
return;
V_72 = F_58 ( V_75 ) ;
if ( ! V_72 )
return;
if ( ( long ) V_72 -> V_76 < 0 )
V_73 = ( ( T_2 ( * ) ( void ) ) ( V_72 -> V_76 ) ) ( ) ;
else
V_73 = ( T_2 ) V_72 -> V_76 ;
if ( V_8 . V_77 >= V_73 )
return;
F_6 ( V_4 ) ;
F_42 ( V_56 L_9
L_10 , V_73 ) ;
}
static void F_59 ( void )
{
struct V_60 * V_78 = F_60 ( & V_79 ) ;
if ( F_61 ( V_80 ) ) {
V_81 . V_65 &= ~ V_82 ;
V_81 . V_83 = 150 ;
}
memcpy ( V_78 , & V_81 , sizeof( * V_78 ) ) ;
V_78 -> V_68 = F_62 ( F_43 () ) ;
if ( F_61 ( V_4 ) ) {
V_78 -> V_84 = L_11 ;
V_78 -> V_65 &= ~ ( V_85 |
V_66 ) ;
V_78 -> V_86 = F_45 ;
F_63 ( V_78 ,
V_87 * ( 1000 / V_64 ) ,
0xF , ~ 0UL ) ;
} else
F_64 ( V_78 ) ;
}
static void F_65 ( void * V_88 )
{
struct V_60 * V_78 = F_60 ( & V_79 ) ;
if ( ! F_61 ( V_4 ) )
return;
F_66 ( V_78 , V_87 * ( 1000 / V_64 ) ) ;
}
void F_67 ( void )
{
F_68 ( F_65 , NULL , 0 ) ;
}
static void T_1 F_69 ( struct V_60 * V_89 )
{
unsigned long long V_62 = 0 ;
long V_90 = F_11 ( V_91 ) ;
unsigned long V_92 = F_70 () ;
if ( F_33 ( V_93 ) )
V_62 = F_46 () ;
switch ( V_94 ++ ) {
case 0 :
V_95 = V_90 ;
V_96 = V_62 ;
V_97 = V_92 ;
V_98 = V_99 ;
break;
case V_100 :
V_101 = V_90 ;
V_102 = V_62 ;
if ( V_92 < V_97 )
V_92 += V_103 ;
V_104 = V_92 ;
V_105 = V_99 ;
break;
}
}
static int T_1
F_71 ( long V_106 , long * V_59 , long * V_107 )
{
const long V_108 = V_109 / 10 ;
const long V_110 = V_108 / 100 ;
unsigned long V_111 ;
T_3 V_112 ;
#ifndef F_72
return - 1 ;
#endif
F_73 ( V_113 , L_12 , V_106 ) ;
if ( ! V_106 )
return - 1 ;
V_111 = F_74 ( V_109 , 22 ) ;
if ( V_106 > ( V_108 - V_110 ) &&
V_106 < ( V_108 + V_110 ) ) {
F_73 ( V_113 , L_13 ) ;
return 0 ;
}
V_112 = ( ( ( T_3 ) V_106 ) * V_111 ) >> 22 ;
F_75 ( V_112 , 1000000 ) ;
F_76 ( L_14
L_15 , ( long ) V_112 ) ;
V_112 = ( ( ( T_3 ) ( * V_59 ) ) * V_108 ) ;
F_75 ( V_112 , V_106 ) ;
F_17 ( L_16
L_17 , ( unsigned long ) V_112 , * V_59 ) ;
* V_59 = ( long ) V_112 ;
if ( F_33 ( V_93 ) ) {
V_112 = ( ( ( T_3 ) ( * V_107 ) ) * V_108 ) ;
F_75 ( V_112 , V_106 ) ;
F_73 ( V_113 , L_18
L_19 ,
( unsigned long ) V_112 , * V_107 ) ;
* V_107 = ( long ) V_112 ;
}
return 0 ;
}
static int T_1 F_77 ( void )
{
struct V_60 * V_78 = F_60 ( & V_79 ) ;
void (* F_78)( struct V_60 * V_89 );
unsigned long V_114 ;
long V_59 , V_107 ;
int V_115 = 0 ;
if ( F_33 ( V_4 ) ) {
return 0 ;
} else if ( V_67 ) {
F_73 ( V_113 , L_20 ,
V_67 ) ;
V_81 . V_111 = F_79 ( V_67 / V_43 ,
V_116 , V_81 . V_117 ) ;
V_81 . V_118 =
F_80 ( 0x7FFFFF , & V_81 ) ;
V_81 . V_119 = 0x7FFFFF ;
V_81 . V_120 =
F_80 ( 0xF , & V_81 ) ;
V_81 . V_121 = 0xF ;
V_81 . V_65 &= ~ V_66 ;
return 0 ;
}
F_73 ( V_113 , L_21
L_22 ) ;
F_81 () ;
F_78 = V_122 -> V_123 ;
V_122 -> V_123 = F_69 ;
F_32 ( 0xffffffff , 0 , 0 ) ;
F_82 () ;
while ( V_94 <= V_100 )
F_19 () ;
F_81 () ;
V_122 -> V_123 = F_78 ;
V_59 = V_95 - V_101 ;
F_73 ( V_113 , L_23 , V_59 ) ;
V_107 = ( long ) ( V_102 - V_96 ) ;
V_115 = ! F_71 ( V_104 - V_97 ,
& V_59 , & V_107 ) ;
V_81 . V_111 = F_79 ( V_59 , V_116 * V_100 ,
V_81 . V_117 ) ;
V_81 . V_118 =
F_80 ( 0x7FFFFFFF , & V_81 ) ;
V_81 . V_119 = 0x7FFFFFFF ;
V_81 . V_120 =
F_80 ( 0xF , & V_81 ) ;
V_81 . V_121 = 0xF ;
V_67 = ( V_59 * V_43 ) / V_100 ;
F_73 ( V_113 , L_24 , V_59 ) ;
F_73 ( V_113 , L_25 , V_81 . V_111 ) ;
F_73 ( V_113 , L_26 ,
V_67 ) ;
if ( F_33 ( V_93 ) ) {
F_73 ( V_113 , L_27
L_28 ,
( V_107 / V_100 ) / ( 1000000 / V_124 ) ,
( V_107 / V_100 ) % ( 1000000 / V_124 ) ) ;
}
F_73 ( V_113 , L_29
L_30 ,
V_67 / ( 1000000 / V_124 ) ,
V_67 % ( 1000000 / V_124 ) ) ;
if ( V_67 < ( 1000000 / V_124 ) ) {
F_82 () ;
F_76 ( L_31 ) ;
return - 1 ;
}
V_78 -> V_65 &= ~ V_66 ;
if ( ! V_115 ) {
F_73 ( V_113 , L_32 ) ;
V_78 -> V_123 = F_69 ;
F_50 ( V_78 ) ;
V_94 = - 1 ;
F_82 () ;
while ( V_94 <= V_100 )
F_19 () ;
F_81 () ;
F_48 ( V_78 ) ;
V_114 = V_105 - V_98 ;
F_73 ( V_113 , L_33 , V_114 ) ;
if ( V_114 >= V_100 - 2 && V_114 <= V_100 + 2 )
F_73 ( V_113 , L_34 ) ;
else
V_78 -> V_65 |= V_66 ;
}
F_82 () ;
if ( V_78 -> V_65 & V_66 ) {
F_76 ( L_35 ) ;
return - 1 ;
}
return 0 ;
}
void T_1 F_83 ( void )
{
if ( V_125 ) {
F_17 ( L_36 ) ;
if ( F_84 () > 1 ) {
V_81 . V_111 = 1 ;
F_59 () ;
}
return;
}
if ( F_77 () ) {
if ( F_84 () > 1 )
F_59 () ;
return;
}
V_81 . V_65 &= ~ V_66 ;
F_59 () ;
F_85 () ;
}
void F_86 ( void )
{
F_59 () ;
F_85 () ;
}
static void F_87 ( void )
{
struct V_60 * V_61 = F_60 ( & V_79 ) ;
if ( ! V_61 -> V_123 ) {
F_76 ( L_37 ,
F_43 () ) ;
F_48 ( V_61 ) ;
return;
}
F_21 ( V_126 ) ;
V_61 -> V_123 ( V_61 ) ;
}
T_5 void T_6 F_88 ( struct V_127 * V_128 )
{
struct V_127 * V_129 = F_89 ( V_128 ) ;
F_90 () ;
F_91 ( V_31 ) ;
F_87 () ;
F_92 ( V_31 ) ;
F_93 () ;
F_89 ( V_129 ) ;
}
int F_94 ( unsigned int V_130 )
{
return - V_57 ;
}
void F_95 ( void )
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
#ifdef F_96
if ( V_131 >= 5 ) {
V_25 = F_11 ( V_139 ) ;
F_25 ( V_139 , V_25 | V_35 ) ;
}
#endif
#ifdef F_97
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
void F_98 ( void )
{
unsigned int V_142 ;
if ( ! V_132 && ! V_133 )
return;
F_95 () ;
V_142 = F_11 ( V_143 ) ;
V_142 &= ~ V_144 ;
F_25 ( V_143 , V_142 ) ;
#ifdef V_2
if ( V_145 ) {
unsigned int V_146 , V_147 ;
F_99 ( V_148 , V_146 , V_147 ) ;
V_146 &= ~ V_149 ;
F_100 ( V_148 , V_146 , V_147 ) ;
}
#endif
}
void F_101 ( void )
{
unsigned long V_21 ;
if ( ! F_33 ( V_150 ) && ! F_102 () )
return;
F_24 ( V_21 ) ;
#ifdef V_2
if ( ! V_145 )
F_95 () ;
else
#endif
F_98 () ;
F_27 ( V_21 ) ;
}
void T_1 F_103 ( void )
{
if ( F_15 () || V_8 . V_9 == V_10 )
return;
F_104 () ;
F_73 ( V_151 , L_38 ) ;
F_25 ( V_14 , V_152 |
V_153 | V_154 ) ;
}
void T_1 F_105 ( void )
{
unsigned int V_142 ;
if ( V_155 || ! F_33 ( V_150 ) )
return;
F_95 () ;
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
static void F_106 ( void )
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
F_73 ( V_113 , L_41
L_42 ,
V_165 , V_142 ) ;
}
void F_107 ( void )
{
int V_167 = F_43 () ;
unsigned int V_142 , V_168 ;
int V_169 , V_170 , V_171 = 0 ;
unsigned long long V_62 = 0 , V_172 ;
long long V_173 = V_174 ? V_174 : 1000000 ;
if ( F_33 ( V_93 ) )
V_62 = F_46 () ;
if ( V_175 ) {
F_108 () ;
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
F_109 () ;
F_110 ( ! V_12 -> V_176 () ) ;
V_12 -> V_177 () ;
#ifdef V_2
V_169 = F_111 ( V_178 , V_167 ) ;
F_112 ( V_169 != V_179 && V_169 != F_113 () ) ;
F_111 ( V_178 , V_167 ) =
F_113 () ;
#endif
V_142 = F_11 ( V_180 ) ;
V_142 &= ~ V_181 ;
F_25 ( V_180 , V_142 ) ;
do {
V_168 = 0 ;
for ( V_169 = V_182 - 1 ; V_169 >= 0 ; V_169 -- )
V_168 |= F_11 ( V_183 + V_169 * 0x10 ) ;
for ( V_169 = V_182 - 1 ; V_169 >= 0 ; V_169 -- ) {
V_142 = F_11 ( V_184 + V_169 * 0x10 ) ;
for ( V_170 = 31 ; V_170 >= 0 ; V_170 -- ) {
if ( V_142 & ( 1 << V_170 ) ) {
F_114 () ;
V_171 ++ ;
}
}
}
if ( V_171 > 256 ) {
F_115 ( V_185 L_43 ,
V_171 ) ;
break;
}
if ( V_168 ) {
if ( F_33 ( V_93 ) && V_174 ) {
V_172 = F_46 () ;
V_173 = ( V_174 << 10 ) - ( V_172 - V_62 ) ;
} else
V_173 -- ;
}
} while ( V_168 && V_173 > 0 );
F_112 ( V_173 <= 0 ) ;
V_142 = F_11 ( V_143 ) ;
V_142 &= ~ V_156 ;
V_142 |= V_144 ;
#ifdef V_2
V_142 &= ~ V_158 ;
#endif
V_142 |= V_159 ;
F_25 ( V_143 , V_142 ) ;
V_142 = F_11 ( V_136 ) & V_35 ;
if ( ! V_167 && ( V_186 || ! V_142 ) ) {
V_142 = V_160 ;
F_73 ( V_113 , L_44 , V_167 ) ;
} else {
V_142 = V_160 | V_35 ;
F_73 ( V_113 , L_45 , V_167 ) ;
}
F_25 ( V_136 , V_142 ) ;
if ( ( ! V_167 && V_163 != V_164 ) ||
V_163 == V_187 )
V_142 = V_161 ;
else
V_142 = V_161 | V_35 ;
if ( ! F_12 () )
V_142 |= V_162 ;
F_25 ( V_137 , V_142 ) ;
#ifdef F_97
if ( ! V_167 )
F_116 () ;
#endif
}
static void F_117 ( void )
{
F_106 () ;
#ifdef V_2
{
unsigned int V_142 ;
V_142 = F_11 ( V_36 ) ;
V_142 |= ( V_35 | V_31 ) ;
F_25 ( V_36 , V_142 ) ;
}
#endif
F_118 () ;
}
void F_119 ( void )
{
F_107 () ;
F_117 () ;
}
static void F_120 ( void )
{
T_3 V_188 ;
if ( ! F_33 ( V_150 ) )
return;
F_121 ( V_148 , V_188 ) ;
if ( ! ( V_188 & V_189 ) )
return;
F_47 ( V_148 , V_188 & ~ ( V_189 | V_190 ) ) ;
F_47 ( V_148 , V_188 & ~ V_189 ) ;
F_35 ( V_191 L_46 ) ;
}
static void F_122 ( void )
{
T_3 V_188 ;
F_121 ( V_148 , V_188 ) ;
if ( V_188 & V_189 )
return;
F_47 ( V_148 , V_188 | V_189 ) ;
F_35 ( V_191 L_47 ) ;
}
static int T_1 F_123 ( char * V_192 )
{
if ( F_124 () ) {
int V_193 = F_125 ( V_194 ) ;
if ( V_193 >= 255 ) {
F_76 ( L_48 ,
V_193 ) ;
return 0 ;
}
F_76 ( L_49 ) ;
F_120 () ;
}
F_6 ( V_195 ) ;
V_196 = V_197 ;
V_132 = 0 ;
return 0 ;
}
void F_126 ( void )
{
if ( V_196 != V_198 ) {
F_120 () ;
return;
}
F_122 () ;
}
static T_1 void F_127 ( void )
{
T_2 V_199 , V_200 = V_196 ;
V_132 = 0 ;
V_196 = V_197 ;
if ( V_200 != V_198 )
return;
V_199 = F_128 () ;
if ( V_199 >= 255 )
F_129 ( L_50 , V_199 ) ;
F_120 () ;
F_130 ( V_201 ) ;
}
static T_1 void F_131 ( void )
{
if ( V_196 != V_202 )
return;
V_132 = 1 ;
V_196 = V_198 ;
F_122 () ;
}
static T_1 void F_132 ( int V_203 )
{
if ( V_196 == V_197 )
return;
if ( V_203 != V_204 ) {
if ( V_205 > 255 ||
! F_133 () ) {
F_17 ( L_51 ) ;
F_127 () ;
return;
}
V_206 = 1 ;
}
F_131 () ;
}
void T_1 F_134 ( void )
{
if ( F_124 () ) {
F_17 ( L_52 ) ;
V_132 = 1 ;
V_196 = V_198 ;
} else if ( ! F_33 ( V_195 ) ) {
V_196 = V_197 ;
}
}
static int T_1 F_135 ( void )
{
if ( ! F_136 () )
return 0 ;
F_129 ( L_53 ) ;
}
static inline void F_132 ( int V_203 ) { }
static inline void F_122 ( void ) { }
void T_1 F_137 ( void )
{
unsigned long V_21 ;
int V_207 , V_208 ;
if ( V_209 ) {
F_17 ( L_54 ) ;
return;
}
V_208 = F_138 () ;
if ( V_208 < 0 && ! F_139 () )
return;
V_207 = F_140 () ;
if ( V_207 ) {
F_17 ( L_55 , V_207 ) ;
return;
}
F_24 ( V_21 ) ;
V_210 -> V_211 () ;
F_141 () ;
if ( V_208 >= 0 )
V_208 = F_142 () ;
F_132 ( V_208 ) ;
if ( V_208 < 0 )
F_143 () ;
V_210 -> V_212 () ;
F_27 ( V_21 ) ;
}
static int T_1 F_144 ( void )
{
if ( ! F_33 ( V_150 ) ) {
F_17 ( L_56 ) ;
return - 1 ;
}
V_201 = V_213 ;
return 0 ;
}
static int T_1 F_145 ( void )
{
T_2 V_65 , V_147 , V_146 ;
V_65 = F_146 ( 1 ) ;
if ( ! ( V_65 & ( 1 << V_150 ) ) ) {
F_76 ( L_57 ) ;
return - 1 ;
}
F_147 ( & V_8 , V_150 ) ;
V_201 = V_213 ;
if ( V_8 . V_11 >= 6 ) {
F_99 ( V_148 , V_146 , V_147 ) ;
if ( V_146 & V_149 )
V_201 = V_146 & V_214 ;
}
F_17 ( L_58 ) ;
return 0 ;
}
int T_1 F_148 ( unsigned long V_215 )
{
T_2 V_147 , V_146 ;
if ( V_175 )
return - 1 ;
if ( V_8 . V_11 >= 6 ) {
F_99 ( V_148 , V_146 , V_147 ) ;
if ( ! ( V_146 & V_149 ) ) {
F_17 ( L_59 ) ;
V_146 &= ~ V_214 ;
V_146 |= V_149 | V_215 ;
F_100 ( V_148 , V_146 , V_147 ) ;
V_145 = 1 ;
}
}
return F_145 () ;
}
static int T_1 F_144 ( void )
{
if ( V_175 )
return - 1 ;
switch ( V_8 . V_9 ) {
case V_10 :
if ( ( V_8 . V_11 == 6 && V_8 . V_216 > 1 ) ||
( V_8 . V_11 >= 15 ) )
break;
goto V_217;
case V_157 :
if ( V_8 . V_11 == 6 || V_8 . V_11 == 15 ||
( V_8 . V_11 == 5 && F_33 ( V_150 ) ) )
break;
goto V_217;
default:
goto V_217;
}
if ( ! F_33 ( V_150 ) ) {
if ( ! V_3 ) {
F_17 ( L_60
L_61 ) ;
return - 1 ;
}
if ( F_148 ( V_213 ) )
return - 1 ;
} else {
if ( F_145 () )
return - 1 ;
}
F_118 () ;
return 0 ;
V_217:
F_17 ( L_62 ) ;
return - 1 ;
}
void T_1 F_149 ( void )
{
unsigned int V_218 ;
F_57 () ;
if ( V_132 ) {
V_219 = F_128 () ;
return;
}
if ( ! V_155 && F_144 () ) {
F_17 ( L_63 ) ;
F_16 () ;
} else {
V_133 = V_201 ;
if ( ! V_220 && ! V_155 )
F_130 ( V_133 ) ;
}
V_218 = F_128 () ;
if ( V_219 != V_218 ) {
V_219 = V_218 ;
V_221 = F_10 ( F_11 ( V_7 ) ) ;
}
}
void T_1 F_130 ( unsigned long V_222 )
{
V_201 = V_222 ;
if ( ! V_132 ) {
F_150 ( V_223 , V_222 ) ;
F_73 ( V_113 , L_64 ,
V_224 , V_222 ) ;
}
if ( V_219 == - 1U ) {
V_219 = F_128 () ;
V_221 = F_10 ( F_11 ( V_7 ) ) ;
}
}
T_5 void T_6 F_151 ( struct V_127 * V_128 )
{
T_4 V_49 = ~ V_128 -> V_225 ;
T_2 V_25 ;
F_152 () ;
F_153 ( V_49 ) ;
V_25 = F_11 ( V_184 + ( ( V_49 & ~ 0x1f ) >> 1 ) ) ;
if ( V_25 & ( 1 << ( V_49 & 0x1f ) ) )
F_114 () ;
F_21 ( V_226 ) ;
F_17 ( L_65
L_66 , V_49 , F_43 () ) ;
F_154 ( V_49 ) ;
F_93 () ;
}
T_5 void T_6 F_155 ( struct V_127 * V_128 )
{
static const char * const V_227 [] = {
L_67 ,
L_68 ,
L_69 ,
L_70 ,
L_71 ,
L_72 ,
L_73 ,
L_74 ,
} ;
T_2 V_25 , V_169 = 0 ;
F_152 () ;
F_156 ( V_134 ) ;
if ( F_30 () > 3 )
F_25 ( V_141 , 0 ) ;
V_25 = F_11 ( V_141 ) ;
F_114 () ;
F_157 ( & V_228 ) ;
F_73 ( V_151 , V_37 L_75 ,
F_43 () , V_25 ) ;
V_25 &= 0xff ;
while ( V_25 ) {
if ( V_25 & 0x1 )
F_73 ( V_151 , V_229 L_76 , V_227 [ V_169 ] ) ;
V_169 ++ ;
V_25 >>= 1 ;
}
F_73 ( V_151 , V_229 L_77 ) ;
F_158 ( V_134 ) ;
F_93 () ;
}
static void T_1 F_159 ( void )
{
#ifdef V_2
if ( V_186 ) {
F_95 () ;
F_73 ( V_113 , L_78
L_79 ) ;
F_1 () ;
}
#endif
}
void F_160 ( int V_230 )
{
unsigned int V_142 ;
#ifdef V_2
if ( V_186 ) {
F_73 ( V_113 , L_80
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
if ( ! V_230 ) {
V_142 = F_11 ( V_136 ) ;
V_142 &= ~ ( V_231 | V_232 |
V_233 | V_234 |
V_162 | V_35 ) ;
V_142 |= V_234 | V_232 ;
V_142 = F_161 ( V_142 , V_235 ) ;
F_25 ( V_136 , V_142 ) ;
} else {
F_25 ( V_136 , V_35 ) ;
}
V_142 = F_11 ( V_137 ) ;
V_142 &= ~ ( V_231 | V_232 |
V_233 | V_234 |
V_162 | V_35 ) ;
V_142 |= V_234 | V_232 ;
V_142 = F_161 ( V_142 , V_236 ) ;
F_25 ( V_137 , V_142 ) ;
}
static int F_162 ( int V_193 )
{
int V_169 ;
for ( V_169 = 0 ; V_169 < V_237 ; V_169 ++ ) {
if ( V_238 [ V_169 ] == V_193 )
return V_169 ;
}
if ( V_237 >= V_239 ) {
F_163 ( 1 , L_82
L_83 ,
V_239 , V_237 , V_193 ) ;
return - V_57 ;
}
V_238 [ V_237 ] = V_193 ;
return V_237 ++ ;
}
int F_164 ( int V_193 , int V_240 )
{
int V_167 , V_241 = V_239 ;
bool V_242 = F_165 ( V_219 ,
V_243 ) ;
if ( V_244 != V_179 &&
V_244 != F_128 () &&
V_244 == V_193 ) {
int V_245 = V_246 + V_247 ;
F_76 ( L_84
L_85 ,
V_245 , V_193 ) ;
V_247 ++ ;
return - V_248 ;
}
if ( ! V_242 && V_246 >= V_239 - 1 &&
V_193 != V_219 ) {
int V_245 = V_241 + V_247 - 1 ;
F_76 (
L_86
L_87
L_88 , V_241 , V_245 , V_193 ) ;
V_247 ++ ;
return - V_248 ;
}
if ( V_246 >= V_239 ) {
int V_245 = V_241 + V_247 ;
F_76 ( L_89
L_90 ,
V_241 , V_245 , V_193 ) ;
V_247 ++ ;
return - V_57 ;
}
if ( V_193 == V_219 ) {
V_167 = 0 ;
V_238 [ 0 ] = V_193 ;
} else {
V_167 = F_162 ( V_193 ) ;
if ( V_167 < 0 ) {
V_247 ++ ;
return - V_57 ;
}
}
if ( V_240 == 0x0 ) {
F_76 ( L_91 ,
V_167 , V_193 ) ;
V_240 = 0x10 ;
}
if ( V_240 != V_221 ) {
F_76 ( L_92 ,
V_221 , V_167 , V_240 ) ;
}
if ( V_193 > V_205 )
V_205 = V_193 ;
#if F_166 ( F_53 ) || F_166 ( F_13 )
F_111 ( V_249 , V_167 ) = V_193 ;
F_111 ( V_250 , V_167 ) = V_193 ;
#endif
#ifdef V_2
F_111 ( V_178 , V_167 ) =
V_12 -> V_251 ( V_167 ) ;
#endif
F_167 ( V_167 , true ) ;
F_168 ( V_193 , V_243 ) ;
F_169 ( V_167 , true ) ;
V_246 ++ ;
return V_167 ;
}
int F_170 ( void )
{
return F_128 () ;
}
void F_171 ( void )
{
unsigned long V_252 ;
F_25 ( V_253 , V_254 ) ;
V_252 = F_11 ( V_255 ) & ~ V_256 ;
V_252 |= F_172 ( 1UL << F_43 () ) ;
F_25 ( V_255 , V_252 ) ;
}
int F_173 ( const struct V_68 * V_53 ,
struct V_257 * V_258 ,
unsigned int * V_193 )
{
unsigned int V_167 = F_174 ( V_53 ) ;
if ( V_167 >= V_239 )
return - V_57 ;
* V_193 = F_175 ( V_249 , V_167 ) ;
F_176 ( V_258 , F_62 ( V_167 ) ) ;
return 0 ;
}
int F_177 ( const struct V_68 * V_53 ,
struct V_257 * V_258 ,
unsigned int * V_193 )
{
struct V_68 * V_259 = F_178 ( V_258 ) ;
unsigned long V_260 = F_179 ( V_53 ) [ 0 ] & V_261 ;
if ( ! V_260 )
return - V_57 ;
* V_193 = ( unsigned int ) V_260 ;
F_179 ( V_259 ) [ 0 ] = V_260 ;
return 0 ;
}
void T_1 F_180 ( void (* F_181)( T_2 V_54 , T_2 V_25 ) )
{
struct V_12 * * V_262 ;
for ( V_262 = V_263 ; V_262 < V_264 ; V_262 ++ ) {
F_112 ( ( * V_262 ) -> F_181 == F_181 ) ;
( * V_262 ) -> V_265 = ( * V_262 ) -> F_181 ;
( * V_262 ) -> F_181 = F_181 ;
}
}
static void T_1 F_182 ( void )
{
#ifdef F_13
F_25 ( V_194 , V_12 -> V_266 ( V_219 ) ) ;
#else
# ifdef F_183
V_219 = F_128 () ;
# endif
#endif
F_184 ( V_219 , & V_243 ) ;
}
int T_1 F_185 ( bool V_267 )
{
int V_20 ;
F_159 () ;
if ( V_267 )
F_182 () ;
F_107 () ;
if ( V_132 )
V_20 = F_11 ( V_255 ) ;
else
V_20 = F_186 ( F_11 ( V_255 ) ) ;
F_187 () ;
F_117 () ;
F_188 () ;
F_189 () ;
V_268 . V_269 . V_270 () ;
return V_20 ;
}
int T_1 F_190 ( void )
{
if ( V_175 ) {
F_17 ( L_93 ) ;
return - 1 ;
}
#ifdef F_13
if ( ! F_33 ( V_150 ) ) {
V_175 = 1 ;
F_17 ( L_94 ) ;
return - 1 ;
}
#else
if ( ! V_155 && ! F_33 ( V_150 ) )
return - 1 ;
if ( ! F_33 ( V_150 ) &&
F_14 ( V_221 ) ) {
F_42 ( L_95 ,
V_219 ) ;
return - 1 ;
}
#endif
if ( ! V_155 )
F_108 () ;
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
int V_131 ;
if ( ! V_271 . V_272 )
return 0 ;
V_131 = F_30 () ;
V_271 . V_273 = F_11 ( V_194 ) ;
V_271 . V_274 = F_11 ( V_180 ) ;
V_271 . V_275 = F_11 ( V_255 ) ;
V_271 . V_276 = F_11 ( V_253 ) ;
V_271 . V_277 = F_11 ( V_143 ) ;
V_271 . V_278 = F_11 ( V_36 ) ;
if ( V_131 >= 4 )
V_271 . V_279 = F_11 ( V_138 ) ;
V_271 . V_280 = F_11 ( V_136 ) ;
V_271 . V_281 = F_11 ( V_137 ) ;
V_271 . V_282 = F_11 ( V_135 ) ;
V_271 . V_283 = F_11 ( V_42 ) ;
V_271 . V_284 = F_11 ( V_38 ) ;
#ifdef F_96
if ( V_131 >= 5 )
V_271 . V_285 = F_11 ( V_139 ) ;
#endif
#ifdef F_97
if ( V_131 >= 6 )
V_271 . V_286 = F_11 ( V_140 ) ;
#endif
F_24 ( V_21 ) ;
F_98 () ;
F_194 () ;
F_27 ( V_21 ) ;
return 0 ;
}
static void F_195 ( void )
{
unsigned int V_146 , V_147 ;
unsigned long V_21 ;
int V_131 ;
if ( ! V_271 . V_272 )
return;
F_24 ( V_21 ) ;
F_141 () ;
V_210 -> V_211 () ;
if ( V_132 ) {
F_122 () ;
} else {
if ( V_8 . V_11 >= 6 ) {
F_99 ( V_148 , V_146 , V_147 ) ;
V_146 &= ~ V_214 ;
V_146 |= V_149 | V_201 ;
F_100 ( V_148 , V_146 , V_147 ) ;
}
}
V_131 = F_30 () ;
F_25 ( V_135 , V_134 | V_35 ) ;
F_25 ( V_194 , V_271 . V_273 ) ;
F_25 ( V_253 , V_271 . V_276 ) ;
F_25 ( V_255 , V_271 . V_275 ) ;
F_25 ( V_180 , V_271 . V_274 ) ;
F_25 ( V_143 , V_271 . V_277 ) ;
F_25 ( V_136 , V_271 . V_280 ) ;
F_25 ( V_137 , V_271 . V_281 ) ;
#ifdef F_96
if ( V_131 >= 5 )
F_25 ( V_139 , V_271 . V_285 ) ;
#endif
#ifdef F_97
if ( V_131 >= 6 )
F_25 ( V_140 , V_271 . V_286 ) ;
#endif
if ( V_131 >= 4 )
F_25 ( V_138 , V_271 . V_279 ) ;
F_25 ( V_36 , V_271 . V_278 ) ;
F_25 ( V_38 , V_271 . V_284 ) ;
F_25 ( V_42 , V_271 . V_283 ) ;
F_25 ( V_141 , 0 ) ;
F_11 ( V_141 ) ;
F_25 ( V_135 , V_271 . V_282 ) ;
F_25 ( V_141 , 0 ) ;
F_11 ( V_141 ) ;
F_196 ( V_132 ) ;
F_27 ( V_21 ) ;
}
static void F_118 ( void )
{
V_271 . V_272 = 1 ;
}
static int T_1 F_197 ( void )
{
if ( F_33 ( V_150 ) )
F_198 ( & V_287 ) ;
return 0 ;
}
static void F_118 ( void ) { }
static int F_199 ( const struct V_288 * V_289 )
{
if ( V_290 )
return 0 ;
F_17 ( L_96 , V_289 -> V_291 ) ;
V_290 = 1 ;
return 0 ;
}
static void F_200 ( void )
{
if ( V_292 )
return;
F_201 ( V_293 ) ;
V_292 = 1 ;
}
int F_202 ( void )
{
F_200 () ;
return V_290 ;
}
static int T_1 F_203 ( char * V_1 )
{
V_175 = 1 ;
F_6 ( V_150 ) ;
return 0 ;
}
static int T_1 F_204 ( char * V_1 )
{
return F_203 ( V_1 ) ;
}
static int T_1 F_205 ( char * V_1 )
{
V_294 = 1 ;
return 0 ;
}
static int T_1 F_206 ( char * V_1 )
{
V_125 = 1 ;
return 0 ;
}
static int T_1 F_207 ( char * V_1 )
{
V_125 = 1 ;
return 0 ;
}
static int T_1 F_208 ( char * V_1 )
{
if ( ! V_1 ) {
#ifdef F_13
V_209 = 0 ;
return 0 ;
#endif
return - V_57 ;
}
if ( strcmp ( L_97 , V_1 ) == 0 )
V_295 = V_151 ;
else if ( strcmp ( L_98 , V_1 ) == 0 )
V_295 = V_113 ;
else {
F_76 ( L_99
L_100 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_1 F_209 ( void )
{
if ( ! V_133 )
return - 1 ;
V_296 . V_297 = V_133 ;
V_296 . V_298 = V_296 . V_297 + V_299 - 1 ;
F_210 ( & V_300 , & V_296 ) ;
return 0 ;
}
static int T_1 F_211 ( char * V_1 )
{
if ( ! V_1 || ! F_212 ( & V_1 , & V_244 ) )
return - V_57 ;
return 0 ;
}
static int T_1 F_213 ( char * V_1 )
{
if ( ! V_1 )
return - V_57 ;
if ( ! strncmp ( L_101 , V_1 , 3 ) )
V_163 = V_187 ;
else if ( ! strncmp ( L_102 , V_1 , 4 ) )
V_163 = V_164 ;
else if ( ! strncmp ( L_103 , V_1 , 3 ) )
V_163 = V_301 ;
else {
F_214 ( L_104 , V_1 ) ;
return - V_57 ;
}
return 0 ;
}
