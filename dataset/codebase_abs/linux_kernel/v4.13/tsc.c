void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
F_2 () ;
do {
V_3 = F_3 ( V_5 . V_3 . V_6 ) ;
V_4 = V_3 & 1 ;
V_2 -> V_7 = F_3 ( V_5 . V_2 [ V_4 ] . V_7 ) ;
V_2 -> V_8 = F_3 ( V_5 . V_2 [ V_4 ] . V_8 ) ;
V_2 -> V_9 = F_3 ( V_5 . V_2 [ V_4 ] . V_9 ) ;
} while ( F_4 ( V_3 != F_3 ( V_5 . V_3 . V_6 ) ) );
}
void F_5 ( void )
{
F_6 () ;
}
static void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_7 = 0 ;
}
static void F_8 ( int V_10 )
{
struct V_5 * V_11 = & F_9 ( V_5 , V_10 ) ;
F_7 ( & V_11 -> V_2 [ 0 ] ) ;
F_7 ( & V_11 -> V_2 [ 1 ] ) ;
F_10 ( & V_11 -> V_3 ) ;
}
static inline unsigned long long F_11 ( unsigned long long V_12 )
{
struct V_1 V_2 ;
unsigned long long V_13 ;
F_1 ( & V_2 ) ;
V_13 = V_2 . V_7 ;
V_13 += F_12 ( V_12 , V_2 . V_8 , V_2 . V_9 ) ;
F_5 () ;
return V_13 ;
}
static void F_13 ( unsigned long V_14 , int V_10 , unsigned long long V_15 )
{
unsigned long long V_16 ;
struct V_1 V_2 ;
struct V_5 * V_11 ;
unsigned long V_17 ;
F_14 ( V_17 ) ;
F_15 () ;
if ( ! V_14 )
goto V_18;
V_16 = F_11 ( V_15 ) ;
F_16 ( & V_2 . V_8 , & V_2 . V_9 , V_14 ,
V_19 , 0 ) ;
if ( V_2 . V_9 == 32 ) {
V_2 . V_9 = 31 ;
V_2 . V_8 >>= 1 ;
}
V_2 . V_7 = V_16 -
F_12 ( V_15 , V_2 . V_8 , V_2 . V_9 ) ;
V_11 = F_17 ( & V_5 , V_10 ) ;
F_18 ( & V_11 -> V_3 ) ;
V_11 -> V_2 [ 0 ] = V_2 ;
F_18 ( & V_11 -> V_3 ) ;
V_11 -> V_2 [ 1 ] = V_2 ;
V_18:
F_19 () ;
F_20 ( V_17 ) ;
}
T_1 F_21 ( void )
{
if ( F_22 ( & V_20 ) ) {
T_1 V_15 = F_23 () ;
return F_11 ( V_15 ) ;
}
return ( V_21 - V_22 ) * ( 1000000000 / V_23 ) ;
}
T_1 F_24 ( T_1 V_24 )
{
return F_11 ( V_24 ) ;
}
unsigned long long F_25 ( void )
{
return F_26 () ;
}
bool F_27 ( void )
{
return V_25 . F_25 == F_21 ;
}
bool F_27 ( void ) { return true ; }
int F_28 ( void )
{
return V_26 ;
}
int T_2 F_29 ( char * V_27 )
{
F_30 ( L_1 ) ;
V_28 = 1 ;
return 1 ;
}
int T_2 F_29 ( char * V_27 )
{
F_31 ( V_29 ) ;
return 1 ;
}
static int T_2 F_32 ( char * V_27 )
{
if ( ! strcmp ( V_27 , L_2 ) )
V_30 = 1 ;
if ( ! strncmp ( V_27 , L_3 , 9 ) )
V_31 = 1 ;
if ( ! strcmp ( V_27 , L_4 ) )
F_33 ( L_5 ) ;
return 1 ;
}
static T_1 F_34 ( T_1 * V_32 , int V_33 )
{
T_1 V_34 , V_35 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_34 = F_35 () ;
if ( V_33 )
* V_32 = F_36 ( V_38 ) & 0xFFFFFFFF ;
else
* V_32 = F_37 () ;
V_35 = F_35 () ;
if ( ( V_35 - V_34 ) < V_39 )
return V_35 ;
}
return V_40 ;
}
static unsigned long F_38 ( T_1 V_41 , T_1 V_42 , T_1 V_43 )
{
T_1 V_44 ;
if ( V_43 < V_42 )
V_43 += 0x100000000ULL ;
V_43 -= V_42 ;
V_44 = ( ( T_1 ) V_43 * F_36 ( V_45 ) ) ;
F_39 ( V_44 , 1000000 ) ;
F_39 ( V_41 , V_44 ) ;
return ( unsigned long ) V_41 ;
}
static unsigned long F_40 ( T_1 V_41 , T_1 V_46 , T_1 V_47 )
{
T_1 V_44 ;
if ( ! V_46 && ! V_47 )
return V_48 ;
if ( V_47 < V_46 )
V_47 += ( T_1 ) V_49 ;
V_47 -= V_46 ;
V_44 = V_47 * 1000000000LL ;
F_39 ( V_44 , V_50 ) ;
F_39 ( V_41 , V_44 ) ;
return ( unsigned long ) V_41 ;
}
static unsigned long F_41 ( T_3 V_51 , unsigned long V_52 , int V_53 )
{
T_1 V_24 , V_34 , V_35 , V_54 ;
unsigned long V_55 , V_56 ;
int V_57 ;
F_42 ( ( F_43 ( 0x61 ) & ~ 0x02 ) | 0x01 , 0x61 ) ;
F_42 ( 0xb0 , 0x43 ) ;
F_42 ( V_51 & 0xff , 0x42 ) ;
F_42 ( V_51 >> 8 , 0x42 ) ;
V_24 = V_34 = V_35 = F_35 () ;
V_57 = 0 ;
V_56 = 0 ;
V_55 = V_48 ;
while ( ( F_43 ( 0x61 ) & 0x20 ) == 0 ) {
V_35 = F_35 () ;
V_54 = V_35 - V_24 ;
V_24 = V_35 ;
if ( ( unsigned long ) V_54 < V_55 )
V_55 = ( unsigned int ) V_54 ;
if ( ( unsigned long ) V_54 > V_56 )
V_56 = ( unsigned int ) V_54 ;
V_57 ++ ;
}
if ( V_57 < V_53 || V_56 > 10 * V_55 )
return V_48 ;
V_54 = V_35 - V_34 ;
F_39 ( V_54 , V_52 ) ;
return V_54 ;
}
static inline int F_44 ( unsigned char V_58 )
{
F_43 ( 0x42 ) ;
return F_43 ( 0x42 ) == V_58 ;
}
static inline int F_45 ( unsigned char V_58 , T_1 * V_59 , unsigned long * V_60 )
{
int V_61 ;
T_1 V_24 = 0 , V_62 = 0 ;
for ( V_61 = 0 ; V_61 < 50000 ; V_61 ++ ) {
if ( ! F_44 ( V_58 ) )
break;
V_62 = V_24 ;
V_24 = F_35 () ;
}
* V_60 = F_35 () - V_62 ;
* V_59 = V_24 ;
return V_61 > 5 ;
}
static unsigned long F_46 ( void )
{
int V_36 ;
T_1 V_24 , V_54 ;
unsigned long V_63 , V_64 ;
F_42 ( ( F_43 ( 0x61 ) & ~ 0x02 ) | 0x01 , 0x61 ) ;
F_42 ( 0xb0 , 0x43 ) ;
F_42 ( 0xff , 0x42 ) ;
F_42 ( 0xff , 0x42 ) ;
F_44 ( 0 ) ;
if ( F_45 ( 0xff , & V_24 , & V_63 ) ) {
for ( V_36 = 1 ; V_36 <= V_65 ; V_36 ++ ) {
if ( ! F_45 ( 0xff - V_36 , & V_54 , & V_64 ) )
break;
V_54 -= V_24 ;
if ( V_36 == 1 &&
V_63 + V_64 >= ( V_54 * V_65 ) >> 11 )
return 0 ;
if ( V_63 + V_64 >= V_54 >> 11 )
continue;
if ( ! F_44 ( 0xfe - V_36 ) )
break;
goto V_66;
}
}
F_47 ( L_6 ) ;
return 0 ;
V_66:
V_54 *= V_67 ;
F_39 ( V_54 , V_36 * 256 * 1000 ) ;
F_47 ( L_7 ) ;
return V_54 ;
}
unsigned long F_48 ( void )
{
unsigned int V_68 , V_69 , V_70 , V_71 ;
unsigned int V_72 ;
if ( V_73 . V_74 != V_75 )
return 0 ;
if ( V_73 . V_76 < 0x15 )
return 0 ;
V_68 = V_69 = V_70 = V_71 = 0 ;
F_49 ( 0x15 , & V_68 , & V_69 , & V_70 , & V_71 ) ;
if ( V_69 == 0 || V_68 == 0 )
return 0 ;
V_72 = V_70 / 1000 ;
if ( V_72 == 0 ) {
switch ( V_73 . V_77 ) {
case V_78 :
case V_79 :
case V_80 :
case V_81 :
V_72 = 24000 ;
break;
case V_82 :
case V_83 :
V_72 = 25000 ;
break;
case V_84 :
V_72 = 19200 ;
break;
}
}
F_50 ( V_85 ) ;
if ( V_73 . V_77 == V_84 )
F_50 ( V_86 ) ;
return V_72 * V_69 / V_68 ;
}
static unsigned long F_51 ( void )
{
unsigned int V_87 , V_88 , V_89 , V_71 ;
if ( V_73 . V_74 != V_75 )
return 0 ;
if ( V_73 . V_76 < 0x16 )
return 0 ;
V_87 = V_88 = V_89 = V_71 = 0 ;
F_49 ( 0x16 , & V_87 , & V_88 , & V_89 , & V_71 ) ;
return V_87 * 1000 ;
}
unsigned long F_52 ( void )
{
T_1 V_90 , V_91 , V_54 , V_92 , V_93 ;
unsigned long V_94 = V_48 , V_95 = V_48 ;
unsigned long V_17 , V_51 , V_52 , V_96 ;
int V_33 = F_53 () , V_36 , V_53 ;
V_96 = F_51 () ;
if ( V_96 )
return V_96 ;
V_96 = F_54 () ;
if ( V_96 )
return V_96 ;
F_14 ( V_17 ) ;
V_96 = F_46 () ;
F_20 ( V_17 ) ;
if ( V_96 )
return V_96 ;
V_51 = V_97 ;
V_52 = V_98 ;
V_53 = V_99 ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ ) {
unsigned long V_100 ;
F_14 ( V_17 ) ;
V_90 = F_34 ( & V_92 , V_33 ) ;
V_100 = F_41 ( V_51 , V_52 , V_53 ) ;
V_91 = F_34 ( & V_93 , V_33 ) ;
F_20 ( V_17 ) ;
V_94 = F_55 ( V_94 , V_100 ) ;
if ( V_92 == V_93 )
continue;
if ( V_90 == V_40 || V_91 == V_40 )
continue;
V_91 = ( V_91 - V_90 ) * 1000000LL ;
if ( V_33 )
V_91 = F_38 ( V_91 , V_92 , V_93 ) ;
else
V_91 = F_40 ( V_91 , V_92 , V_93 ) ;
V_95 = F_55 ( V_95 , ( unsigned long ) V_91 ) ;
V_54 = ( ( T_1 ) V_94 ) * 100 ;
F_39 ( V_54 , V_95 ) ;
if ( V_54 >= 90 && V_54 <= 110 ) {
F_47 ( L_8 ,
V_33 ? L_9 : L_10 , V_36 + 1 ) ;
return V_95 ;
}
if ( V_36 == 1 && V_94 == V_48 ) {
V_51 = V_101 ;
V_52 = V_102 ;
V_53 = V_103 ;
}
}
if ( V_94 == V_48 ) {
F_30 ( L_11 ) ;
if ( ! V_33 && ! V_92 && ! V_93 ) {
F_56 ( L_12 ) ;
return 0 ;
}
if ( V_95 == V_48 ) {
F_30 ( L_13 ) ;
return 0 ;
}
F_47 ( L_14 ,
V_33 ? L_9 : L_10 ) ;
return V_95 ;
}
if ( ! V_33 && ! V_92 && ! V_93 ) {
F_47 ( L_15 ) ;
return V_94 ;
}
if ( V_95 == V_48 ) {
F_30 ( L_16 ) ;
return V_94 ;
}
F_30 ( L_17 ,
V_33 ? L_9 : L_10 , V_94 , V_95 ) ;
F_47 ( L_15 ) ;
return V_94 ;
}
int F_57 ( void )
{
#ifndef F_58
unsigned long V_104 = V_105 ;
if ( ! F_59 ( V_29 ) )
return - V_106 ;
V_105 = V_107 . V_108 () ;
V_109 = V_107 . V_110 () ;
if ( V_109 == 0 )
V_109 = V_105 ;
else if ( abs ( V_105 - V_109 ) * 10 > V_109 )
V_105 = V_109 ;
F_60 ( 0 ) . V_111 = F_61 ( F_60 ( 0 ) . V_111 ,
V_104 , V_105 ) ;
return 0 ;
#else
return - V_106 ;
#endif
}
void F_62 ( void )
{
if ( ! F_63 () )
return;
V_112 = F_25 () ;
}
void F_64 ( void )
{
unsigned long long V_113 ;
unsigned long V_17 ;
int V_10 ;
if ( ! F_63 () )
return;
F_14 ( V_17 ) ;
F_65 ( V_5 . V_2 [ 0 ] . V_7 , 0 ) ;
F_65 ( V_5 . V_2 [ 1 ] . V_7 , 0 ) ;
V_113 = V_112 - F_25 () ;
F_66 (cpu) {
F_9 ( V_5 . V_2 [ 0 ] . V_7 , V_10 ) = V_113 ;
F_9 ( V_5 . V_2 [ 1 ] . V_7 , V_10 ) = V_113 ;
}
F_20 ( V_17 ) ;
}
static int F_67 ( struct V_114 * V_115 , unsigned long V_58 ,
void * V_2 )
{
struct V_116 * V_117 = V_2 ;
unsigned long * V_118 ;
V_118 = & V_73 . V_111 ;
#ifdef F_58
if ( ! ( V_117 -> V_17 & V_119 ) )
V_118 = & F_60 ( V_117 -> V_10 ) . V_111 ;
#endif
if ( ! V_120 ) {
V_120 = V_117 -> V_121 ;
V_122 = * V_118 ;
V_123 = V_109 ;
}
if ( ( V_58 == V_124 && V_117 -> V_121 < V_117 -> V_125 ) ||
( V_58 == V_126 && V_117 -> V_121 > V_117 -> V_125 ) ) {
* V_118 = F_61 ( V_122 , V_120 , V_117 -> V_125 ) ;
V_109 = F_61 ( V_123 , V_120 , V_117 -> V_125 ) ;
if ( ! ( V_117 -> V_17 & V_119 ) )
F_33 ( L_18 ) ;
F_13 ( V_109 , V_117 -> V_10 , F_23 () ) ;
}
return 0 ;
}
static int T_2 F_68 ( void )
{
if ( ! F_59 ( V_29 ) )
return 0 ;
if ( F_59 ( V_127 ) )
return 0 ;
F_69 ( & V_128 ,
V_129 ) ;
return 0 ;
}
static void F_70 ( void )
{
unsigned int V_130 [ 2 ] ;
if ( V_73 . V_76 < V_131 )
return;
if ( F_59 ( V_132 ) ||
! F_59 ( V_133 ) ||
! F_59 ( V_134 ) )
return;
F_49 ( V_131 , & V_135 ,
& V_136 , V_130 , V_130 + 1 ) ;
if ( V_135 < V_137 )
return;
F_71 ( V_138 , V_139 ) ;
F_50 ( V_140 ) ;
}
static void F_72 ( struct V_141 * V_142 )
{
F_73 ( true ) ;
}
static T_1 F_74 ( struct V_141 * V_142 )
{
return ( T_1 ) F_75 () ;
}
static void F_76 ( struct V_141 * V_142 )
{
if ( V_26 )
return;
V_26 = 1 ;
if ( F_27 () )
F_77 () ;
F_78 () ;
F_47 ( L_19 ) ;
}
static void F_79 ( struct V_141 * V_142 )
{
if ( V_26 )
return;
if ( F_27 () )
F_80 () ;
}
void F_33 ( char * V_143 )
{
if ( V_26 )
return;
V_26 = 1 ;
if ( F_27 () )
F_77 () ;
F_78 () ;
F_47 ( L_20 , V_143 ) ;
if ( V_144 . V_145 ) {
F_81 ( & V_144 ) ;
} else {
V_144 . V_17 |= V_146 ;
V_144 . V_147 = 0 ;
}
}
static void T_2 F_82 ( void )
{
#if F_83 ( V_148 ) || F_83 ( V_149 ) || F_83 ( V_150 )
if ( F_84 () ) {
#define F_85 0x100
unsigned long V_151 , V_152 ;
F_86 ( V_153 , & V_151 , & V_152 ) ;
if ( V_151 & F_85 )
V_30 = 1 ;
}
#endif
if ( F_59 ( V_86 ) )
V_30 = 1 ;
}
int F_87 ( void )
{
if ( ! F_59 ( V_29 ) || V_26 )
return 1 ;
#ifdef F_58
if ( F_88 () )
return 1 ;
#endif
if ( F_59 ( V_127 ) )
return 0 ;
if ( V_30 )
return 0 ;
if ( V_73 . V_74 != V_75 ) {
if ( F_89 () > 1 )
return 1 ;
}
return 0 ;
}
struct V_154 F_90 ( T_1 V_155 )
{
T_1 V_44 , V_156 , V_157 ;
V_157 = F_39 ( V_155 , V_135 ) ;
V_156 = V_155 * V_136 ;
V_44 = V_157 * V_136 ;
F_39 ( V_44 , V_135 ) ;
V_156 += V_44 + V_139 ;
return (struct V_154 ) { . V_142 = V_158 ,
. V_159 = V_156 } ;
}
static void F_91 ( struct V_160 * V_161 )
{
static T_1 V_162 = - 1 , V_163 ;
static int V_33 ;
T_1 V_164 , V_165 , V_54 ;
unsigned long V_117 ;
int V_10 ;
if ( F_28 () )
goto V_166;
if ( V_162 == - 1 ) {
V_33 = F_53 () ;
F_92 ( & V_167 , V_23 ) ;
V_162 = F_34 ( & V_163 , V_33 ) ;
return;
}
V_164 = F_34 ( & V_165 , V_33 ) ;
if ( V_163 == V_165 )
goto V_166;
if ( V_162 == V_40 || V_164 == V_40 )
goto V_166;
V_54 = V_164 - V_162 ;
V_54 *= 1000000LL ;
if ( V_33 )
V_117 = F_38 ( V_54 , V_163 , V_165 ) ;
else
V_117 = F_40 ( V_54 , V_163 , V_165 ) ;
if ( abs ( V_109 - V_117 ) > V_109 / 100 )
goto V_166;
V_109 = V_117 ;
F_47 ( L_21 ,
( unsigned long ) V_109 / 1000 ,
( unsigned long ) V_109 % 1000 ) ;
F_93 () ;
F_66 (cpu)
F_13 ( V_109 , V_10 , V_164 ) ;
V_166:
if ( F_59 ( V_140 ) )
V_158 = & V_144 ;
F_94 ( & V_144 , V_109 ) ;
}
static int T_2 F_95 ( void )
{
if ( ! F_59 ( V_29 ) || V_28 > 0 || ! V_109 )
return 0 ;
if ( V_30 )
V_144 . V_17 &= ~ V_168 ;
if ( F_28 () ) {
V_144 . V_147 = 0 ;
V_144 . V_17 &= ~ V_169 ;
}
if ( F_59 ( V_170 ) )
V_144 . V_17 |= V_171 ;
if ( F_59 ( V_85 ) ) {
if ( F_59 ( V_140 ) )
V_158 = & V_144 ;
F_94 ( & V_144 , V_109 ) ;
return 0 ;
}
F_92 ( & V_167 , 0 ) ;
return 0 ;
}
void T_2 F_96 ( void )
{
T_1 V_118 , V_12 ;
int V_10 ;
if ( ! F_59 ( V_29 ) ) {
F_31 ( V_172 ) ;
return;
}
V_105 = V_107 . V_108 () ;
V_109 = V_107 . V_110 () ;
if ( V_109 == 0 )
V_109 = V_105 ;
else if ( abs ( V_105 - V_109 ) * 10 > V_109 )
V_105 = V_109 ;
if ( ! V_109 ) {
F_33 ( L_22 ) ;
F_31 ( V_172 ) ;
return;
}
F_47 ( L_23 ,
( unsigned long ) V_105 / 1000 ,
( unsigned long ) V_105 % 1000 ) ;
F_97 ( true ) ;
V_12 = F_23 () ;
F_66 (cpu) {
F_8 ( V_10 ) ;
F_13 ( V_109 , V_10 , V_12 ) ;
}
if ( V_28 > 0 )
return;
V_28 = 0 ;
F_98 ( & V_20 ) ;
if ( ! V_31 )
F_99 () ;
V_118 = ( ( T_1 ) V_109 * 1000 ) ;
F_39 ( V_118 , V_23 ) ;
V_173 = V_118 ;
F_100 () ;
F_82 () ;
if ( F_87 () )
F_33 ( L_24 ) ;
F_70 () ;
}
unsigned long F_101 ( void )
{
int V_174 , V_10 = F_102 () ;
struct V_175 * V_176 = F_103 ( V_10 ) ;
if ( ! V_28 && ! F_104 ( & F_60 ( V_10 ) , V_127 ) )
return 0 ;
if ( ! V_176 )
return 0 ;
V_174 = F_105 ( V_176 , V_10 ) ;
if ( V_174 < V_177 )
return F_60 ( V_174 ) . V_111 ;
return 0 ;
}
