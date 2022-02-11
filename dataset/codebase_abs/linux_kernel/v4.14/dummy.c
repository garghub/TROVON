static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 , V_5 , 256 , V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static void F_4 ( struct V_7 * V_8 )
{
F_5 ( & V_8 -> V_9 , V_10 +
( V_8 -> V_11 + V_8 -> V_12 - 1 ) / V_8 -> V_12 ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
unsigned long V_13 ;
V_13 = V_10 - V_8 -> V_14 ;
if ( ! V_13 )
return;
V_8 -> V_14 += V_13 ;
V_13 *= V_8 -> V_12 ;
V_8 -> V_15 += V_13 ;
while ( V_8 -> V_15 >= V_8 -> V_16 )
V_8 -> V_15 -= V_8 -> V_16 ;
while ( V_8 -> V_11 <= V_13 ) {
V_8 -> V_17 ++ ;
V_8 -> V_11 += V_8 -> V_18 ;
}
V_8 -> V_11 -= V_13 ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_2 -> V_21 ;
F_8 ( & V_8 -> V_22 ) ;
V_8 -> V_14 = V_10 ;
F_4 ( V_8 ) ;
F_9 ( & V_8 -> V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_2 -> V_21 ;
F_8 ( & V_8 -> V_22 ) ;
F_11 ( & V_8 -> V_9 ) ;
F_9 ( & V_8 -> V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_7 * V_8 = V_2 -> V_21 ;
V_8 -> V_15 = 0 ;
V_8 -> V_12 = V_2 -> V_12 ;
V_8 -> V_16 = V_2 -> V_23 * V_24 ;
V_8 -> V_18 = V_2 -> V_25 * V_24 ;
V_8 -> V_11 = V_8 -> V_18 ;
V_8 -> V_17 = 0 ;
return 0 ;
}
static void F_13 ( unsigned long V_26 )
{
struct V_7 * V_8 = (struct V_7 * ) V_26 ;
unsigned long V_27 ;
int V_17 = 0 ;
F_14 ( & V_8 -> V_22 , V_27 ) ;
F_6 ( V_8 ) ;
F_4 ( V_8 ) ;
V_17 = V_8 -> V_17 ;
V_8 -> V_17 = 0 ;
F_15 ( & V_8 -> V_22 , V_27 ) ;
if ( V_17 )
F_16 ( V_8 -> V_20 ) ;
}
static T_1
F_17 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_2 -> V_21 ;
T_1 V_28 ;
F_8 ( & V_8 -> V_22 ) ;
F_6 ( V_8 ) ;
V_28 = V_8 -> V_15 / V_24 ;
F_9 ( & V_8 -> V_22 ) ;
return V_28 ;
}
static int F_18 ( struct V_19 * V_20 )
{
struct V_7 * V_8 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
V_20 -> V_2 -> V_21 = V_8 ;
F_20 ( & V_8 -> V_9 , F_13 ,
( unsigned long ) V_8 ) ;
F_21 ( & V_8 -> V_22 ) ;
V_8 -> V_20 = V_20 ;
return 0 ;
}
static void F_22 ( struct V_19 * V_20 )
{
F_23 ( V_20 -> V_2 -> V_21 ) ;
}
static void F_24 ( unsigned long V_31 )
{
struct V_32 * V_8 = (struct V_32 * ) V_31 ;
if ( F_25 ( & V_8 -> V_33 ) )
F_16 ( V_8 -> V_20 ) ;
}
static enum V_34 F_26 ( struct V_35 * V_9 )
{
struct V_32 * V_8 ;
V_8 = F_27 ( V_9 , struct V_32 , V_9 ) ;
if ( ! F_25 ( & V_8 -> V_33 ) )
return V_36 ;
F_28 ( & V_8 -> V_37 ) ;
F_29 ( V_9 , V_8 -> V_38 ) ;
return V_39 ;
}
static int F_30 ( struct V_19 * V_20 )
{
struct V_32 * V_8 = V_20 -> V_2 -> V_21 ;
V_8 -> V_14 = F_31 ( & V_8 -> V_9 ) ;
F_32 ( & V_8 -> V_9 , V_8 -> V_38 , V_40 ) ;
F_33 ( & V_8 -> V_33 , 1 ) ;
return 0 ;
}
static int F_34 ( struct V_19 * V_20 )
{
struct V_32 * V_8 = V_20 -> V_2 -> V_21 ;
F_33 ( & V_8 -> V_33 , 0 ) ;
F_35 ( & V_8 -> V_9 ) ;
return 0 ;
}
static inline void F_36 ( struct V_32 * V_8 )
{
F_35 ( & V_8 -> V_9 ) ;
F_37 ( & V_8 -> V_37 ) ;
}
static T_1
F_38 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_32 * V_8 = V_2 -> V_21 ;
T_2 V_13 ;
T_3 V_28 ;
V_13 = F_39 ( F_31 ( & V_8 -> V_9 ) ,
V_8 -> V_14 ) ;
V_13 = F_40 ( V_13 * V_2 -> V_12 + 999999 , 1000000 ) ;
F_41 ( V_13 , V_2 -> V_23 , & V_28 ) ;
return V_28 ;
}
static int F_42 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_32 * V_8 = V_2 -> V_21 ;
unsigned int V_41 , V_12 ;
long V_42 ;
unsigned long V_43 ;
F_36 ( V_8 ) ;
V_41 = V_2 -> V_25 ;
V_12 = V_2 -> V_12 ;
V_42 = V_41 / V_12 ;
V_41 %= V_12 ;
V_43 = F_40 ( ( T_2 ) V_41 * 1000000000UL + V_12 - 1 , V_12 ) ;
V_8 -> V_38 = F_43 ( V_42 , V_43 ) ;
return 0 ;
}
static int F_44 ( struct V_19 * V_20 )
{
struct V_32 * V_8 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
V_20 -> V_2 -> V_21 = V_8 ;
F_45 ( & V_8 -> V_9 , V_44 , V_40 ) ;
V_8 -> V_9 . V_45 = F_26 ;
V_8 -> V_20 = V_20 ;
F_33 ( & V_8 -> V_33 , 0 ) ;
F_46 ( & V_8 -> V_37 , F_24 ,
( unsigned long ) V_8 ) ;
return 0 ;
}
static void F_47 ( struct V_19 * V_20 )
{
struct V_32 * V_8 = V_20 -> V_2 -> V_21 ;
F_36 ( V_8 ) ;
F_23 ( V_8 ) ;
}
static int F_48 ( struct V_19 * V_20 , int V_46 )
{
switch ( V_46 ) {
case V_47 :
case V_48 :
return F_49 ( V_20 ) -> F_50 ( V_20 ) ;
case V_49 :
case V_50 :
return F_49 ( V_20 ) -> F_51 ( V_20 ) ;
}
return - V_51 ;
}
static int F_52 ( struct V_19 * V_20 )
{
return F_49 ( V_20 ) -> F_53 ( V_20 ) ;
}
static T_1 F_54 ( struct V_19 * V_20 )
{
return F_49 ( V_20 ) -> F_55 ( V_20 ) ;
}
static int F_56 ( struct V_19 * V_20 ,
struct V_52 * V_53 )
{
if ( V_54 ) {
V_20 -> V_2 -> V_55 = F_57 ( V_53 ) ;
return 0 ;
}
return F_58 ( V_20 ,
F_57 ( V_53 ) ) ;
}
static int F_59 ( struct V_19 * V_20 )
{
if ( V_54 )
return 0 ;
return F_60 ( V_20 ) ;
}
static int F_61 ( struct V_19 * V_20 )
{
struct V_56 * V_57 = F_62 ( V_20 ) ;
struct V_58 * V_59 = V_57 -> V_59 ;
struct V_1 * V_2 = V_20 -> V_2 ;
const struct V_60 * V_61 ;
int V_3 ;
V_61 = & V_62 ;
#ifdef F_63
if ( V_35 )
V_61 = & V_63 ;
#endif
V_3 = V_61 -> V_64 ( V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
F_49 ( V_20 ) = V_61 ;
V_2 -> V_65 = V_57 -> V_66 ;
if ( V_20 -> V_67 -> V_68 & 1 ) {
V_2 -> V_65 . V_69 &= ~ V_70 ;
V_2 -> V_65 . V_69 |= V_71 ;
}
if ( V_20 -> V_67 -> V_68 & 2 )
V_2 -> V_65 . V_69 &= ~ ( V_72 |
V_73 ) ;
if ( V_59 == NULL )
return 0 ;
if ( V_20 -> V_74 == V_75 ) {
if ( V_59 -> V_76 )
V_3 = V_59 -> V_76 ( V_20 -> V_2 ) ;
} else {
if ( V_59 -> V_77 )
V_3 = V_59 -> V_77 ( V_20 -> V_2 ) ;
}
if ( V_3 < 0 ) {
F_49 ( V_20 ) -> free ( V_20 ) ;
return V_3 ;
}
return 0 ;
}
static int F_64 ( struct V_19 * V_20 )
{
F_49 ( V_20 ) -> free ( V_20 ) ;
return 0 ;
}
static void F_65 ( void )
{
if ( V_54 ) {
int V_78 ;
for ( V_78 = 0 ; V_78 < 2 ; V_78 ++ )
if ( V_79 [ V_78 ] ) {
F_66 ( ( unsigned long ) V_79 [ V_78 ] ) ;
V_79 [ V_78 ] = NULL ;
}
}
}
static int F_67 ( void )
{
int V_78 ;
if ( ! V_54 )
return 0 ;
for ( V_78 = 0 ; V_78 < 2 ; V_78 ++ ) {
V_79 [ V_78 ] = ( void * ) F_68 ( V_29 ) ;
if ( ! V_79 [ V_78 ] ) {
F_65 () ;
return - V_30 ;
}
}
return 0 ;
}
static int F_69 ( struct V_19 * V_20 ,
int V_80 , unsigned long V_28 ,
void T_4 * V_81 , unsigned long V_82 )
{
return 0 ;
}
static int F_70 ( struct V_19 * V_20 ,
int V_80 , unsigned long V_28 ,
void * V_81 , unsigned long V_82 )
{
return 0 ;
}
static int F_71 ( struct V_19 * V_20 ,
int V_80 , unsigned long V_28 ,
unsigned long V_82 )
{
return 0 ;
}
static struct V_83 * F_72 ( struct V_19 * V_20 ,
unsigned long V_84 )
{
return F_73 ( V_79 [ V_20 -> V_74 ] ) ;
}
static int F_74 ( struct V_56 * V_57 , int V_68 ,
int V_85 )
{
struct V_86 * V_67 ;
struct V_87 * V_61 ;
int V_3 ;
V_3 = F_75 ( V_57 -> V_88 , L_1 , V_68 ,
V_85 , V_85 , & V_67 ) ;
if ( V_3 < 0 )
return V_3 ;
V_57 -> V_67 = V_67 ;
if ( V_54 )
V_61 = & V_89 ;
else
V_61 = & V_90 ;
F_76 ( V_67 , V_75 , V_61 ) ;
F_76 ( V_67 , V_91 , V_61 ) ;
V_67 -> V_21 = V_57 ;
V_67 -> V_92 = 0 ;
strcpy ( V_67 -> V_93 , L_1 ) ;
if ( ! V_54 ) {
F_77 ( V_67 ,
V_94 ,
F_78 ( V_29 ) ,
0 , 64 * 1024 ) ;
}
return 0 ;
}
static int F_79 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
V_98 -> type = V_99 ;
V_98 -> V_100 = 2 ;
V_98 -> V_101 . integer . V_102 = - 50 ;
V_98 -> V_101 . integer . V_103 = 100 ;
return 0 ;
}
static int F_80 ( struct V_95 * V_96 ,
struct V_104 * V_105 )
{
struct V_56 * V_57 = F_81 ( V_96 ) ;
int V_106 = V_96 -> V_107 ;
F_82 ( & V_57 -> V_108 ) ;
V_105 -> V_101 . integer . V_101 [ 0 ] = V_57 -> V_109 [ V_106 ] [ 0 ] ;
V_105 -> V_101 . integer . V_101 [ 1 ] = V_57 -> V_109 [ V_106 ] [ 1 ] ;
F_83 ( & V_57 -> V_108 ) ;
return 0 ;
}
static int F_84 ( struct V_95 * V_96 ,
struct V_104 * V_105 )
{
struct V_56 * V_57 = F_81 ( V_96 ) ;
int V_110 , V_106 = V_96 -> V_107 ;
int V_111 , V_112 ;
V_111 = V_105 -> V_101 . integer . V_101 [ 0 ] ;
if ( V_111 < - 50 )
V_111 = - 50 ;
if ( V_111 > 100 )
V_111 = 100 ;
V_112 = V_105 -> V_101 . integer . V_101 [ 1 ] ;
if ( V_112 < - 50 )
V_112 = - 50 ;
if ( V_112 > 100 )
V_112 = 100 ;
F_82 ( & V_57 -> V_108 ) ;
V_110 = V_57 -> V_109 [ V_106 ] [ 0 ] != V_111 ||
V_57 -> V_109 [ V_106 ] [ 1 ] != V_112 ;
V_57 -> V_109 [ V_106 ] [ 0 ] = V_111 ;
V_57 -> V_109 [ V_106 ] [ 1 ] = V_112 ;
F_83 ( & V_57 -> V_108 ) ;
return V_110 ;
}
static int F_85 ( struct V_95 * V_96 ,
struct V_104 * V_105 )
{
struct V_56 * V_57 = F_81 ( V_96 ) ;
int V_106 = V_96 -> V_107 ;
F_82 ( & V_57 -> V_108 ) ;
V_105 -> V_101 . integer . V_101 [ 0 ] = V_57 -> V_113 [ V_106 ] [ 0 ] ;
V_105 -> V_101 . integer . V_101 [ 1 ] = V_57 -> V_113 [ V_106 ] [ 1 ] ;
F_83 ( & V_57 -> V_108 ) ;
return 0 ;
}
static int F_86 ( struct V_95 * V_96 , struct V_104 * V_105 )
{
struct V_56 * V_57 = F_81 ( V_96 ) ;
int V_110 , V_106 = V_96 -> V_107 ;
int V_111 , V_112 ;
V_111 = V_105 -> V_101 . integer . V_101 [ 0 ] & 1 ;
V_112 = V_105 -> V_101 . integer . V_101 [ 1 ] & 1 ;
F_82 ( & V_57 -> V_108 ) ;
V_110 = V_57 -> V_113 [ V_106 ] [ 0 ] != V_111 &&
V_57 -> V_113 [ V_106 ] [ 1 ] != V_112 ;
V_57 -> V_113 [ V_106 ] [ 0 ] = V_111 ;
V_57 -> V_113 [ V_106 ] [ 1 ] = V_112 ;
F_83 ( & V_57 -> V_108 ) ;
return V_110 ;
}
static int F_87 ( struct V_95 * V_96 ,
struct V_97 * V_69 )
{
const char * const V_114 [] = { L_2 , L_3 } ;
return F_88 ( V_69 , 1 , 2 , V_114 ) ;
}
static int F_89 ( struct V_95 * V_96 ,
struct V_104 * V_101 )
{
struct V_56 * V_57 = F_81 ( V_96 ) ;
V_101 -> V_101 . V_115 . V_116 [ 0 ] = V_57 -> V_117 ;
return 0 ;
}
static int F_90 ( struct V_95 * V_96 ,
struct V_104 * V_101 )
{
struct V_56 * V_57 = F_81 ( V_96 ) ;
int V_118 ;
if ( V_101 -> V_101 . V_115 . V_116 [ 0 ] > 1 )
return - V_51 ;
V_118 = V_101 -> V_101 . V_115 . V_116 [ 0 ] != V_57 -> V_117 ;
if ( V_118 ) {
V_57 -> V_117 = V_101 -> V_101 . V_115 . V_116 [ 0 ] ;
if ( V_57 -> V_117 ) {
V_57 -> V_119 -> V_120 [ 0 ] . V_121 &=
~ V_122 ;
V_57 -> V_123 -> V_120 [ 0 ] . V_121 &=
~ V_122 ;
} else {
V_57 -> V_119 -> V_120 [ 0 ] . V_121 |=
V_122 ;
V_57 -> V_123 -> V_120 [ 0 ] . V_121 |=
V_122 ;
}
F_91 ( V_57 -> V_88 , V_124 ,
& V_57 -> V_119 -> V_125 ) ;
F_91 ( V_57 -> V_88 , V_124 ,
& V_57 -> V_123 -> V_125 ) ;
}
return V_118 ;
}
static int F_92 ( struct V_56 * V_57 )
{
struct V_126 * V_88 = V_57 -> V_88 ;
struct V_95 * V_96 ;
unsigned int V_127 ;
int V_3 ;
F_21 ( & V_57 -> V_108 ) ;
strcpy ( V_88 -> V_128 , L_4 ) ;
V_57 -> V_117 = 1 ;
for ( V_127 = 0 ; V_127 < F_93 ( V_129 ) ; V_127 ++ ) {
V_96 = F_94 ( & V_129 [ V_127 ] , V_57 ) ;
V_3 = F_95 ( V_88 , V_96 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! strcmp ( V_96 -> V_125 . V_93 , L_5 ) )
V_57 -> V_119 = V_96 ;
else if ( ! strcmp ( V_96 -> V_125 . V_93 , L_6 ) )
V_57 -> V_123 = V_96 ;
}
return 0 ;
}
static void F_96 ( struct V_56 * V_57 ,
struct V_130 * V_131 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_132 ; V_78 ++ ) {
if ( V_57 -> V_66 . V_133 & ( 1ULL << V_78 ) )
F_97 ( V_131 , L_7 , F_98 ( V_78 ) ) ;
}
}
static void F_99 ( struct V_56 * V_57 ,
struct V_130 * V_131 )
{
static int V_134 [] = {
5512 , 8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 ,
64000 , 88200 , 96000 , 176400 , 192000 ,
} ;
int V_78 ;
if ( V_57 -> V_66 . V_134 & V_135 )
F_97 ( V_131 , L_8 ) ;
if ( V_57 -> V_66 . V_134 & V_136 )
F_97 ( V_131 , L_9 ) ;
for ( V_78 = 0 ; V_78 < F_93 ( V_134 ) ; V_78 ++ )
if ( V_57 -> V_66 . V_134 & ( 1 << V_78 ) )
F_97 ( V_131 , L_10 , V_134 [ V_78 ] ) ;
}
static void F_100 ( struct V_137 * V_138 ,
struct V_130 * V_131 )
{
struct V_56 * V_57 = V_138 -> V_21 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < F_93 ( V_139 ) ; V_78 ++ ) {
F_97 ( V_131 , L_11 , V_139 [ V_78 ] . V_93 ) ;
if ( V_139 [ V_78 ] . V_140 == sizeof( int ) )
F_97 ( V_131 , V_139 [ V_78 ] . V_141 ,
* F_101 ( V_57 , V_139 [ V_78 ] . V_84 ) ) ;
else
F_97 ( V_131 , V_139 [ V_78 ] . V_141 ,
* F_102 ( V_57 , V_139 [ V_78 ] . V_84 ) ) ;
if ( ! strcmp ( V_139 [ V_78 ] . V_93 , L_12 ) )
F_96 ( V_57 , V_131 ) ;
else if ( ! strcmp ( V_139 [ V_78 ] . V_93 , L_13 ) )
F_99 ( V_57 , V_131 ) ;
F_97 ( V_131 , L_14 ) ;
}
}
static void F_103 ( struct V_137 * V_138 ,
struct V_130 * V_131 )
{
struct V_56 * V_57 = V_138 -> V_21 ;
char line [ 64 ] ;
while ( ! F_104 ( V_131 , line , sizeof( line ) ) ) {
char V_116 [ 20 ] ;
const char * V_142 ;
unsigned long long V_143 ;
int V_78 ;
V_142 = F_105 ( V_116 , line , sizeof( V_116 ) ) ;
for ( V_78 = 0 ; V_78 < F_93 ( V_139 ) ; V_78 ++ ) {
if ( ! strcmp ( V_116 , V_139 [ V_78 ] . V_93 ) )
break;
}
if ( V_78 >= F_93 ( V_139 ) )
continue;
F_105 ( V_116 , V_142 , sizeof( V_116 ) ) ;
if ( F_106 ( V_116 , 0 , & V_143 ) )
continue;
if ( V_139 [ V_78 ] . V_140 == sizeof( int ) )
* F_101 ( V_57 , V_139 [ V_78 ] . V_84 ) = V_143 ;
else
* F_102 ( V_57 , V_139 [ V_78 ] . V_84 ) = V_143 ;
}
}
static void F_107 ( struct V_56 * V_144 )
{
struct V_137 * V_138 ;
if ( ! F_108 ( V_144 -> V_88 , L_15 , & V_138 ) ) {
F_109 ( V_138 , V_144 , F_100 ) ;
V_138 -> V_145 . V_146 . V_147 = F_103 ;
V_138 -> V_148 |= V_149 ;
V_138 -> V_21 = V_144 ;
}
}
static int F_110 ( struct V_150 * V_151 )
{
struct V_126 * V_88 ;
struct V_56 * V_57 ;
struct V_58 * V_152 = NULL , * * V_153 ;
int V_127 , V_3 ;
int V_154 = V_151 -> V_125 ;
V_3 = F_111 ( & V_151 -> V_154 , V_155 [ V_154 ] , V_125 [ V_154 ] , V_156 ,
sizeof( struct V_56 ) , & V_88 ) ;
if ( V_3 < 0 )
return V_3 ;
V_57 = V_88 -> V_21 ;
V_57 -> V_88 = V_88 ;
for ( V_153 = V_157 ; * V_153 && V_59 [ V_154 ] ; V_153 ++ ) {
if ( strcmp ( V_59 [ V_154 ] , ( * V_153 ) -> V_93 ) == 0 ) {
F_112 ( V_158
L_16 ,
( * V_153 ) -> V_93 , V_88 -> V_159 ) ;
V_152 = V_57 -> V_59 = * V_153 ;
break;
}
}
for ( V_127 = 0 ; V_127 < V_160 && V_127 < V_161 [ V_154 ] ; V_127 ++ ) {
if ( V_162 [ V_154 ] < 1 )
V_162 [ V_154 ] = 1 ;
if ( V_162 [ V_154 ] > V_163 )
V_162 [ V_154 ] = V_163 ;
V_3 = F_74 ( V_57 , V_127 , V_162 [ V_154 ] ) ;
if ( V_3 < 0 )
goto V_164;
}
V_57 -> V_66 = V_165 ;
if ( V_152 ) {
if ( V_152 -> V_133 )
V_57 -> V_66 . V_133 = V_152 -> V_133 ;
if ( V_152 -> V_166 )
V_57 -> V_66 . V_166 = V_152 -> V_166 ;
if ( V_152 -> V_167 )
V_57 -> V_66 . V_167 = V_152 -> V_167 ;
if ( V_152 -> V_168 )
V_57 -> V_66 . V_168 = V_152 -> V_168 ;
if ( V_152 -> V_169 )
V_57 -> V_66 . V_169 = V_152 -> V_169 ;
if ( V_152 -> V_170 )
V_57 -> V_66 . V_170 = V_152 -> V_170 ;
if ( V_152 -> V_134 )
V_57 -> V_66 . V_134 = V_152 -> V_134 ;
if ( V_152 -> V_171 )
V_57 -> V_66 . V_171 = V_152 -> V_171 ;
if ( V_152 -> V_172 )
V_57 -> V_66 . V_172 = V_152 -> V_172 ;
if ( V_152 -> V_173 )
V_57 -> V_66 . V_173 = V_152 -> V_173 ;
if ( V_152 -> V_174 )
V_57 -> V_66 . V_174 = V_152 -> V_174 ;
}
V_3 = F_92 ( V_57 ) ;
if ( V_3 < 0 )
goto V_164;
strcpy ( V_88 -> V_175 , L_17 ) ;
strcpy ( V_88 -> V_176 , L_17 ) ;
sprintf ( V_88 -> V_177 , L_18 , V_154 + 1 ) ;
F_107 ( V_57 ) ;
V_3 = F_113 ( V_88 ) ;
if ( V_3 == 0 ) {
F_114 ( V_151 , V_88 ) ;
return 0 ;
}
V_164:
F_115 ( V_88 ) ;
return V_3 ;
}
static int F_116 ( struct V_150 * V_151 )
{
F_115 ( F_117 ( V_151 ) ) ;
return 0 ;
}
static int F_118 ( struct V_68 * V_178 )
{
struct V_126 * V_88 = F_119 ( V_178 ) ;
struct V_56 * V_57 = V_88 -> V_21 ;
F_120 ( V_88 , V_179 ) ;
F_121 ( V_57 -> V_67 ) ;
return 0 ;
}
static int F_122 ( struct V_68 * V_178 )
{
struct V_126 * V_88 = F_119 ( V_178 ) ;
F_120 ( V_88 , V_180 ) ;
return 0 ;
}
static void F_123 ( void )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < F_93 ( V_181 ) ; ++ V_78 )
F_124 ( V_181 [ V_78 ] ) ;
F_125 ( & V_182 ) ;
F_65 () ;
}
static int T_5 F_126 ( void )
{
int V_78 , V_183 , V_3 ;
V_3 = F_127 ( & V_182 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_67 () ;
if ( V_3 < 0 ) {
F_125 ( & V_182 ) ;
return V_3 ;
}
V_183 = 0 ;
for ( V_78 = 0 ; V_78 < V_184 ; V_78 ++ ) {
struct V_150 * V_68 ;
if ( ! V_185 [ V_78 ] )
continue;
V_68 = F_128 ( V_186 ,
V_78 , NULL , 0 ) ;
if ( F_129 ( V_68 ) )
continue;
if ( ! F_117 ( V_68 ) ) {
F_124 ( V_68 ) ;
continue;
}
V_181 [ V_78 ] = V_68 ;
V_183 ++ ;
}
if ( ! V_183 ) {
#ifdef F_130
F_112 ( V_187 L_19 ) ;
#endif
F_123 () ;
return - V_188 ;
}
return 0 ;
}
static void T_6 F_131 ( void )
{
F_123 () ;
}
