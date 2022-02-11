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
int V_80 , T_1 V_28 ,
void T_4 * V_81 , T_1 V_82 )
{
return 0 ;
}
static int F_70 ( struct V_19 * V_20 ,
int V_80 , T_1 V_28 ,
T_1 V_82 )
{
return 0 ;
}
static struct V_83 * F_71 ( struct V_19 * V_20 ,
unsigned long V_84 )
{
return F_72 ( V_79 [ V_20 -> V_74 ] ) ;
}
static int F_73 ( struct V_56 * V_57 , int V_68 ,
int V_85 )
{
struct V_86 * V_67 ;
struct V_87 * V_61 ;
int V_3 ;
V_3 = F_74 ( V_57 -> V_88 , L_1 , V_68 ,
V_85 , V_85 , & V_67 ) ;
if ( V_3 < 0 )
return V_3 ;
V_57 -> V_67 = V_67 ;
if ( V_54 )
V_61 = & V_89 ;
else
V_61 = & V_90 ;
F_75 ( V_67 , V_75 , V_61 ) ;
F_75 ( V_67 , V_91 , V_61 ) ;
V_67 -> V_21 = V_57 ;
V_67 -> V_92 = 0 ;
strcpy ( V_67 -> V_93 , L_1 ) ;
if ( ! V_54 ) {
F_76 ( V_67 ,
V_94 ,
F_77 ( V_29 ) ,
0 , 64 * 1024 ) ;
}
return 0 ;
}
static int F_78 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
V_98 -> type = V_99 ;
V_98 -> V_82 = 2 ;
V_98 -> V_100 . integer . V_101 = - 50 ;
V_98 -> V_100 . integer . V_102 = 100 ;
return 0 ;
}
static int F_79 ( struct V_95 * V_96 ,
struct V_103 * V_104 )
{
struct V_56 * V_57 = F_80 ( V_96 ) ;
int V_105 = V_96 -> V_106 ;
F_81 ( & V_57 -> V_107 ) ;
V_104 -> V_100 . integer . V_100 [ 0 ] = V_57 -> V_108 [ V_105 ] [ 0 ] ;
V_104 -> V_100 . integer . V_100 [ 1 ] = V_57 -> V_108 [ V_105 ] [ 1 ] ;
F_82 ( & V_57 -> V_107 ) ;
return 0 ;
}
static int F_83 ( struct V_95 * V_96 ,
struct V_103 * V_104 )
{
struct V_56 * V_57 = F_80 ( V_96 ) ;
int V_109 , V_105 = V_96 -> V_106 ;
int V_110 , V_111 ;
V_110 = V_104 -> V_100 . integer . V_100 [ 0 ] ;
if ( V_110 < - 50 )
V_110 = - 50 ;
if ( V_110 > 100 )
V_110 = 100 ;
V_111 = V_104 -> V_100 . integer . V_100 [ 1 ] ;
if ( V_111 < - 50 )
V_111 = - 50 ;
if ( V_111 > 100 )
V_111 = 100 ;
F_81 ( & V_57 -> V_107 ) ;
V_109 = V_57 -> V_108 [ V_105 ] [ 0 ] != V_110 ||
V_57 -> V_108 [ V_105 ] [ 1 ] != V_111 ;
V_57 -> V_108 [ V_105 ] [ 0 ] = V_110 ;
V_57 -> V_108 [ V_105 ] [ 1 ] = V_111 ;
F_82 ( & V_57 -> V_107 ) ;
return V_109 ;
}
static int F_84 ( struct V_95 * V_96 ,
struct V_103 * V_104 )
{
struct V_56 * V_57 = F_80 ( V_96 ) ;
int V_105 = V_96 -> V_106 ;
F_81 ( & V_57 -> V_107 ) ;
V_104 -> V_100 . integer . V_100 [ 0 ] = V_57 -> V_112 [ V_105 ] [ 0 ] ;
V_104 -> V_100 . integer . V_100 [ 1 ] = V_57 -> V_112 [ V_105 ] [ 1 ] ;
F_82 ( & V_57 -> V_107 ) ;
return 0 ;
}
static int F_85 ( struct V_95 * V_96 , struct V_103 * V_104 )
{
struct V_56 * V_57 = F_80 ( V_96 ) ;
int V_109 , V_105 = V_96 -> V_106 ;
int V_110 , V_111 ;
V_110 = V_104 -> V_100 . integer . V_100 [ 0 ] & 1 ;
V_111 = V_104 -> V_100 . integer . V_100 [ 1 ] & 1 ;
F_81 ( & V_57 -> V_107 ) ;
V_109 = V_57 -> V_112 [ V_105 ] [ 0 ] != V_110 &&
V_57 -> V_112 [ V_105 ] [ 1 ] != V_111 ;
V_57 -> V_112 [ V_105 ] [ 0 ] = V_110 ;
V_57 -> V_112 [ V_105 ] [ 1 ] = V_111 ;
F_82 ( & V_57 -> V_107 ) ;
return V_109 ;
}
static int F_86 ( struct V_95 * V_96 ,
struct V_97 * V_69 )
{
const char * const V_113 [] = { L_2 , L_3 } ;
return F_87 ( V_69 , 1 , 2 , V_113 ) ;
}
static int F_88 ( struct V_95 * V_96 ,
struct V_103 * V_100 )
{
struct V_56 * V_57 = F_80 ( V_96 ) ;
V_100 -> V_100 . V_114 . V_115 [ 0 ] = V_57 -> V_116 ;
return 0 ;
}
static int F_89 ( struct V_95 * V_96 ,
struct V_103 * V_100 )
{
struct V_56 * V_57 = F_80 ( V_96 ) ;
int V_117 ;
if ( V_100 -> V_100 . V_114 . V_115 [ 0 ] > 1 )
return - V_51 ;
V_117 = V_100 -> V_100 . V_114 . V_115 [ 0 ] != V_57 -> V_116 ;
if ( V_117 ) {
V_57 -> V_116 = V_100 -> V_100 . V_114 . V_115 [ 0 ] ;
if ( V_57 -> V_116 ) {
V_57 -> V_118 -> V_119 [ 0 ] . V_120 &=
~ V_121 ;
V_57 -> V_122 -> V_119 [ 0 ] . V_120 &=
~ V_121 ;
} else {
V_57 -> V_118 -> V_119 [ 0 ] . V_120 |=
V_121 ;
V_57 -> V_122 -> V_119 [ 0 ] . V_120 |=
V_121 ;
}
F_90 ( V_57 -> V_88 , V_123 ,
& V_57 -> V_118 -> V_124 ) ;
F_90 ( V_57 -> V_88 , V_123 ,
& V_57 -> V_122 -> V_124 ) ;
}
return V_117 ;
}
static int F_91 ( struct V_56 * V_57 )
{
struct V_125 * V_88 = V_57 -> V_88 ;
struct V_95 * V_96 ;
unsigned int V_126 ;
int V_3 ;
F_21 ( & V_57 -> V_107 ) ;
strcpy ( V_88 -> V_127 , L_4 ) ;
V_57 -> V_116 = 1 ;
for ( V_126 = 0 ; V_126 < F_92 ( V_128 ) ; V_126 ++ ) {
V_96 = F_93 ( & V_128 [ V_126 ] , V_57 ) ;
V_3 = F_94 ( V_88 , V_96 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! strcmp ( V_96 -> V_124 . V_93 , L_5 ) )
V_57 -> V_118 = V_96 ;
else if ( ! strcmp ( V_96 -> V_124 . V_93 , L_6 ) )
V_57 -> V_122 = V_96 ;
}
return 0 ;
}
static void F_95 ( struct V_56 * V_57 ,
struct V_129 * V_130 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_131 ; V_78 ++ ) {
if ( V_57 -> V_66 . V_132 & ( 1ULL << V_78 ) )
F_96 ( V_130 , L_7 , F_97 ( V_78 ) ) ;
}
}
static void F_98 ( struct V_56 * V_57 ,
struct V_129 * V_130 )
{
static int V_133 [] = {
5512 , 8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 ,
64000 , 88200 , 96000 , 176400 , 192000 ,
} ;
int V_78 ;
if ( V_57 -> V_66 . V_133 & V_134 )
F_96 ( V_130 , L_8 ) ;
if ( V_57 -> V_66 . V_133 & V_135 )
F_96 ( V_130 , L_9 ) ;
for ( V_78 = 0 ; V_78 < F_92 ( V_133 ) ; V_78 ++ )
if ( V_57 -> V_66 . V_133 & ( 1 << V_78 ) )
F_96 ( V_130 , L_10 , V_133 [ V_78 ] ) ;
}
static void F_99 ( struct V_136 * V_137 ,
struct V_129 * V_130 )
{
struct V_56 * V_57 = V_137 -> V_21 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < F_92 ( V_138 ) ; V_78 ++ ) {
F_96 ( V_130 , L_11 , V_138 [ V_78 ] . V_93 ) ;
if ( V_138 [ V_78 ] . V_139 == sizeof( int ) )
F_96 ( V_130 , V_138 [ V_78 ] . V_140 ,
* F_100 ( V_57 , V_138 [ V_78 ] . V_84 ) ) ;
else
F_96 ( V_130 , V_138 [ V_78 ] . V_140 ,
* F_101 ( V_57 , V_138 [ V_78 ] . V_84 ) ) ;
if ( ! strcmp ( V_138 [ V_78 ] . V_93 , L_12 ) )
F_95 ( V_57 , V_130 ) ;
else if ( ! strcmp ( V_138 [ V_78 ] . V_93 , L_13 ) )
F_98 ( V_57 , V_130 ) ;
F_96 ( V_130 , L_14 ) ;
}
}
static void F_102 ( struct V_136 * V_137 ,
struct V_129 * V_130 )
{
struct V_56 * V_57 = V_137 -> V_21 ;
char line [ 64 ] ;
while ( ! F_103 ( V_130 , line , sizeof( line ) ) ) {
char V_115 [ 20 ] ;
const char * V_141 ;
unsigned long long V_142 ;
int V_78 ;
V_141 = F_104 ( V_115 , line , sizeof( V_115 ) ) ;
for ( V_78 = 0 ; V_78 < F_92 ( V_138 ) ; V_78 ++ ) {
if ( ! strcmp ( V_115 , V_138 [ V_78 ] . V_93 ) )
break;
}
if ( V_78 >= F_92 ( V_138 ) )
continue;
F_104 ( V_115 , V_141 , sizeof( V_115 ) ) ;
if ( F_105 ( V_115 , 0 , & V_142 ) )
continue;
if ( V_138 [ V_78 ] . V_139 == sizeof( int ) )
* F_100 ( V_57 , V_138 [ V_78 ] . V_84 ) = V_142 ;
else
* F_101 ( V_57 , V_138 [ V_78 ] . V_84 ) = V_142 ;
}
}
static void F_106 ( struct V_56 * V_143 )
{
struct V_136 * V_137 ;
if ( ! F_107 ( V_143 -> V_88 , L_15 , & V_137 ) ) {
F_108 ( V_137 , V_143 , F_99 ) ;
V_137 -> V_144 . V_145 . V_146 = F_102 ;
V_137 -> V_147 |= V_148 ;
V_137 -> V_21 = V_143 ;
}
}
static int F_109 ( struct V_149 * V_150 )
{
struct V_125 * V_88 ;
struct V_56 * V_57 ;
struct V_58 * V_151 = NULL , * * V_152 ;
int V_126 , V_3 ;
int V_153 = V_150 -> V_124 ;
V_3 = F_110 ( & V_150 -> V_153 , V_154 [ V_153 ] , V_124 [ V_153 ] , V_155 ,
sizeof( struct V_56 ) , & V_88 ) ;
if ( V_3 < 0 )
return V_3 ;
V_57 = V_88 -> V_21 ;
V_57 -> V_88 = V_88 ;
for ( V_152 = V_156 ; * V_152 && V_59 [ V_153 ] ; V_152 ++ ) {
if ( strcmp ( V_59 [ V_153 ] , ( * V_152 ) -> V_93 ) == 0 ) {
F_111 ( V_157
L_16 ,
( * V_152 ) -> V_93 , V_88 -> V_158 ) ;
V_151 = V_57 -> V_59 = * V_152 ;
break;
}
}
for ( V_126 = 0 ; V_126 < V_159 && V_126 < V_160 [ V_153 ] ; V_126 ++ ) {
if ( V_161 [ V_153 ] < 1 )
V_161 [ V_153 ] = 1 ;
if ( V_161 [ V_153 ] > V_162 )
V_161 [ V_153 ] = V_162 ;
V_3 = F_73 ( V_57 , V_126 , V_161 [ V_153 ] ) ;
if ( V_3 < 0 )
goto V_163;
}
V_57 -> V_66 = V_164 ;
if ( V_151 ) {
if ( V_151 -> V_132 )
V_57 -> V_66 . V_132 = V_151 -> V_132 ;
if ( V_151 -> V_165 )
V_57 -> V_66 . V_165 = V_151 -> V_165 ;
if ( V_151 -> V_166 )
V_57 -> V_66 . V_166 = V_151 -> V_166 ;
if ( V_151 -> V_167 )
V_57 -> V_66 . V_167 = V_151 -> V_167 ;
if ( V_151 -> V_168 )
V_57 -> V_66 . V_168 = V_151 -> V_168 ;
if ( V_151 -> V_169 )
V_57 -> V_66 . V_169 = V_151 -> V_169 ;
if ( V_151 -> V_133 )
V_57 -> V_66 . V_133 = V_151 -> V_133 ;
if ( V_151 -> V_170 )
V_57 -> V_66 . V_170 = V_151 -> V_170 ;
if ( V_151 -> V_171 )
V_57 -> V_66 . V_171 = V_151 -> V_171 ;
if ( V_151 -> V_172 )
V_57 -> V_66 . V_172 = V_151 -> V_172 ;
if ( V_151 -> V_173 )
V_57 -> V_66 . V_173 = V_151 -> V_173 ;
}
V_3 = F_91 ( V_57 ) ;
if ( V_3 < 0 )
goto V_163;
strcpy ( V_88 -> V_174 , L_17 ) ;
strcpy ( V_88 -> V_175 , L_17 ) ;
sprintf ( V_88 -> V_176 , L_18 , V_153 + 1 ) ;
F_106 ( V_57 ) ;
V_3 = F_112 ( V_88 ) ;
if ( V_3 == 0 ) {
F_113 ( V_150 , V_88 ) ;
return 0 ;
}
V_163:
F_114 ( V_88 ) ;
return V_3 ;
}
static int F_115 ( struct V_149 * V_150 )
{
F_114 ( F_116 ( V_150 ) ) ;
return 0 ;
}
static int F_117 ( struct V_68 * V_177 )
{
struct V_125 * V_88 = F_118 ( V_177 ) ;
struct V_56 * V_57 = V_88 -> V_21 ;
F_119 ( V_88 , V_178 ) ;
F_120 ( V_57 -> V_67 ) ;
return 0 ;
}
static int F_121 ( struct V_68 * V_177 )
{
struct V_125 * V_88 = F_118 ( V_177 ) ;
F_119 ( V_88 , V_179 ) ;
return 0 ;
}
static void F_122 ( void )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < F_92 ( V_180 ) ; ++ V_78 )
F_123 ( V_180 [ V_78 ] ) ;
F_124 ( & V_181 ) ;
F_65 () ;
}
static int T_5 F_125 ( void )
{
int V_78 , V_182 , V_3 ;
V_3 = F_126 ( & V_181 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_67 () ;
if ( V_3 < 0 ) {
F_124 ( & V_181 ) ;
return V_3 ;
}
V_182 = 0 ;
for ( V_78 = 0 ; V_78 < V_183 ; V_78 ++ ) {
struct V_149 * V_68 ;
if ( ! V_184 [ V_78 ] )
continue;
V_68 = F_127 ( V_185 ,
V_78 , NULL , 0 ) ;
if ( F_128 ( V_68 ) )
continue;
if ( ! F_116 ( V_68 ) ) {
F_123 ( V_68 ) ;
continue;
}
V_180 [ V_78 ] = V_68 ;
V_182 ++ ;
}
if ( ! V_182 ) {
#ifdef F_129
F_111 ( V_186 L_19 ) ;
#endif
F_122 () ;
return - V_187 ;
}
return 0 ;
}
static void T_6 F_130 ( void )
{
F_122 () ;
}
