static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_5 , unsigned V_6 )
{
void T_2 * V_7 = V_5 -> V_4 . V_8 + V_6 ;
return F_4 ( V_7 ) ;
}
static void F_5 ( struct V_1 * V_5 , unsigned V_6 , T_1 V_9 )
{
void T_2 * V_7 = V_5 -> V_4 . V_8 + V_6 ;
F_6 ( V_9 , V_7 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_10 , V_11 = 1 << V_5 -> V_4 . line ;
V_10 = F_3 ( V_5 , V_12 ) ;
V_10 &= ~ V_11 ;
F_5 ( V_5 , V_12 , V_10 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_10 , V_11 = 1 << V_5 -> V_4 . line ;
V_10 = F_3 ( V_5 , V_12 ) ;
V_10 |= V_11 ;
F_5 ( V_5 , V_12 , V_10 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_13 &= ~ V_14 ;
F_5 ( V_5 , V_15 , V_5 -> V_13 ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
}
static inline void F_11 ( struct V_16 * V_17 )
{
struct V_2 * V_3 ;
struct V_1 * V_5 = & V_17 -> V_5 [ 0 ] ;
struct V_18 * V_19 ;
int V_20 [ V_21 ] = { [ 0 ... V_21 - 1 ] = 0 } ;
unsigned char V_22 , V_23 ;
T_1 V_24 ;
int V_25 ;
while ( ( V_24 = F_3 ( V_5 , V_26 ) ) & V_27 ) {
V_5 = & V_17 -> V_5 [ LINE ( V_24 ) ] ;
V_3 = & V_5 -> V_4 ;
V_22 = F_12 ( V_24 ) ;
V_23 = V_28 ;
V_19 = & V_3 -> V_19 ;
V_19 -> V_29 ++ ;
if ( F_13 ( V_24 & ( V_30 | V_31 | V_32 ) ) ) {
if ( ! V_22 ) {
V_24 |= ( V_24 & V_31 ) >>
( F_14 ( V_31 ) - F_14 ( V_33 ) ) ;
V_24 &= ~ V_31 ;
}
if ( V_24 & V_33 ) {
V_19 -> V_34 ++ ;
if ( F_15 ( V_3 ) )
continue;
} else if ( V_24 & V_31 )
V_19 -> V_35 ++ ;
else if ( V_24 & V_32 )
V_19 -> V_36 ++ ;
if ( V_24 & V_30 )
V_19 -> V_37 ++ ;
V_24 &= V_3 -> V_38 ;
if ( V_24 & V_33 )
V_23 = V_39 ;
else if ( V_24 & V_31 )
V_23 = V_40 ;
else if ( V_24 & V_32 )
V_23 = V_41 ;
}
if ( F_16 ( V_3 , V_22 ) )
continue;
F_17 ( V_3 , V_24 , V_30 , V_22 , V_23 ) ;
V_20 [ LINE ( V_24 ) ] = 1 ;
}
for ( V_25 = 0 ; V_25 < V_21 ; V_25 ++ )
if ( V_20 [ V_25 ] )
F_18 ( & V_17 -> V_5 [ V_25 ] . V_4 . V_42 -> V_4 ) ;
}
static inline void F_19 ( struct V_16 * V_17 )
{
struct V_1 * V_5 = & V_17 -> V_5 [ 0 ] ;
struct V_43 * V_44 ;
unsigned char V_10 ;
T_1 V_24 ;
V_24 = F_3 ( V_5 , V_45 ) ;
V_5 = & V_17 -> V_5 [ LINE ( V_24 ) ] ;
V_44 = & V_5 -> V_4 . V_42 -> V_44 ;
if ( V_5 -> V_4 . V_46 ) {
F_5 ( V_5 , V_47 , V_5 -> V_4 . V_46 ) ;
V_5 -> V_4 . V_19 . V_48 ++ ;
V_5 -> V_4 . V_46 = 0 ;
return;
}
if ( F_20 ( V_44 ) || F_21 ( & V_5 -> V_4 ) ) {
F_22 ( & V_5 -> V_4 . V_49 ) ;
F_7 ( & V_5 -> V_4 ) ;
F_23 ( & V_5 -> V_4 . V_49 ) ;
return;
}
V_10 = V_44 -> V_50 [ V_44 -> V_51 ] ;
V_44 -> V_51 = ( V_44 -> V_51 + 1 ) & ( V_52 - 1 ) ;
F_5 ( V_5 , V_47 , V_10 ) ;
V_5 -> V_4 . V_19 . V_48 ++ ;
if ( F_24 ( V_44 ) < V_53 )
F_25 ( & V_5 -> V_4 ) ;
if ( F_20 ( V_44 ) ) {
F_22 ( & V_5 -> V_4 . V_49 ) ;
F_7 ( & V_5 -> V_4 ) ;
F_23 ( & V_5 -> V_4 . V_49 ) ;
}
}
static inline void F_26 ( struct V_1 * V_5 )
{
T_1 V_24 ;
if ( V_5 -> V_4 . line != V_54 )
return;
V_24 = F_3 ( V_5 , V_55 ) ;
if ( V_24 )
V_5 -> V_4 . V_19 . V_56 ++ ;
}
static T_3 F_27 ( int V_57 , void * V_58 )
{
struct V_16 * V_17 = V_58 ;
struct V_1 * V_5 = & V_17 -> V_5 [ 0 ] ;
T_1 V_24 ;
V_24 = F_3 ( V_5 , V_45 ) ;
if ( ( V_24 & ( V_59 | V_60 ) ) == ( V_59 | V_60 ) )
F_11 ( V_17 ) ;
if ( ( V_24 & ( V_61 | V_62 ) ) == ( V_61 | V_62 ) )
F_19 ( V_17 ) ;
return V_63 ;
}
static unsigned int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_64 = V_65 | V_66 | V_67 ;
if ( V_5 -> V_4 . line == V_54 ) {
if ( F_3 ( V_5 , V_55 ) & V_68 )
V_64 &= ~ V_66 ;
}
return V_64 ;
}
static void F_29 ( struct V_2 * V_3 , unsigned int V_64 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_10 ;
if ( V_5 -> V_4 . line == V_54 ) {
V_10 = F_3 ( V_5 , V_12 ) ;
if ( V_64 & V_69 )
V_10 &= ~ V_70 ;
else
V_10 |= V_70 ;
F_5 ( V_5 , V_12 , V_10 ) ;
}
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_5 -> V_17 ;
unsigned long V_71 ;
int V_72 ;
int V_73 ;
T_1 V_10 ;
V_72 = F_31 ( 1 , & V_17 -> V_72 ) ;
if ( V_72 != 1 )
return 0 ;
V_73 = F_32 ( V_5 -> V_4 . V_57 , F_27 ,
V_74 , L_1 , V_17 ) ;
if ( V_73 ) {
F_33 ( - 1 , & V_17 -> V_72 ) ;
F_34 ( V_75 L_2 , V_5 -> V_4 . V_57 ) ;
return V_73 ;
}
F_35 ( & V_5 -> V_4 . V_49 , V_71 ) ;
V_10 = F_3 ( V_5 , V_45 ) ;
V_10 |= V_60 | V_62 ;
F_5 ( V_5 , V_45 , V_10 ) ;
F_36 ( & V_5 -> V_4 . V_49 , V_71 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_5 -> V_17 ;
unsigned long V_71 ;
int V_72 ;
T_1 V_10 ;
F_35 ( & V_5 -> V_4 . V_49 , V_71 ) ;
F_7 ( & V_5 -> V_4 ) ;
F_36 ( & V_5 -> V_4 . V_49 , V_71 ) ;
V_72 = F_31 ( - 1 , & V_17 -> V_72 ) ;
if ( ! V_72 ) {
V_10 = F_3 ( V_5 , V_45 ) ;
V_10 &= ~ ( V_60 | V_62 ) ;
F_5 ( V_5 , V_45 , V_10 ) ;
F_38 ( V_5 -> V_4 . V_57 , V_17 ) ;
}
}
static unsigned int F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned short V_10 , V_11 = 1 << V_5 -> V_4 . line ;
V_10 = F_3 ( V_5 , V_12 ) ;
V_10 &= V_11 ;
return V_10 ? 0 : V_76 ;
}
static void F_40 ( struct V_2 * V_3 , int V_77 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_71 ;
unsigned short V_10 , V_11 = 1 << V_5 -> V_4 . line ;
F_35 ( & V_3 -> V_49 , V_71 ) ;
V_10 = F_3 ( V_5 , V_12 ) ;
if ( V_77 )
V_10 |= V_11 ;
else
V_10 &= ~ V_11 ;
F_5 ( V_5 , V_12 , V_10 ) ;
F_36 ( & V_3 -> V_49 , V_71 ) ;
}
static int F_41 ( unsigned int V_78 )
{
switch ( V_78 ) {
case 50 :
return V_79 ;
case 75 :
return V_80 ;
case 110 :
return V_81 ;
case 134 :
return V_82 ;
case 150 :
return V_83 ;
case 300 :
return V_84 ;
case 600 :
return V_85 ;
case 1200 :
return V_86 ;
case 1800 :
return V_87 ;
case 2000 :
return V_88 ;
case 2400 :
return V_89 ;
case 3600 :
return V_90 ;
case 4800 :
return V_91 ;
case 7200 :
return V_92 ;
case 9600 :
return V_93 ;
default:
return - 1 ;
}
}
static void F_42 ( struct V_1 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_17 ;
if ( V_17 -> V_94 )
return;
F_5 ( V_5 , V_45 , V_95 ) ;
while ( F_3 ( V_5 , V_45 ) & V_95 ) ;
F_43 () ;
F_5 ( V_5 , V_45 , V_96 ) ;
V_17 -> V_94 = 1 ;
}
static void F_44 ( struct V_2 * V_3 , struct V_97 * V_98 ,
struct V_97 * V_99 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_71 ;
unsigned int V_13 , V_78 ;
int V_100 ;
V_13 = V_5 -> V_4 . line ;
switch ( V_98 -> V_101 & V_102 ) {
case V_103 :
V_13 |= V_104 ;
break;
case V_105 :
V_13 |= V_106 ;
break;
case V_107 :
V_13 |= V_108 ;
break;
case V_109 :
default:
V_13 |= V_110 ;
}
if ( V_98 -> V_101 & V_111 )
V_13 |= V_112 ;
if ( V_98 -> V_101 & V_113 )
V_13 |= V_114 ;
if ( V_98 -> V_101 & V_115 )
V_13 |= V_116 ;
V_78 = F_45 ( V_3 , V_98 , V_99 , 50 , 9600 ) ;
V_100 = F_41 ( V_78 ) ;
if ( V_100 < 0 ) {
V_78 = F_45 ( V_3 , V_99 , NULL , 50 , 9600 ) ;
V_100 = F_41 ( V_78 ) ;
if ( V_100 < 0 ) {
V_78 = 9600 ;
V_100 = V_93 ;
}
F_46 ( V_98 , V_78 , V_78 ) ;
}
V_13 |= V_100 ;
if ( V_98 -> V_101 & V_117 )
V_13 |= V_14 ;
F_35 ( & V_5 -> V_4 . V_49 , V_71 ) ;
F_47 ( V_3 , V_98 -> V_101 , V_78 ) ;
F_5 ( V_5 , V_15 , V_13 ) ;
V_5 -> V_13 = V_13 ;
V_5 -> V_4 . V_38 = V_30 ;
if ( V_98 -> V_118 & V_119 )
V_5 -> V_4 . V_38 |= V_31 | V_32 ;
if ( V_98 -> V_118 & ( V_120 | V_121 | V_122 ) )
V_5 -> V_4 . V_38 |= V_33 ;
V_3 -> V_123 = 0 ;
if ( ( V_98 -> V_118 & ( V_124 | V_120 ) ) == ( V_124 | V_120 ) )
V_5 -> V_4 . V_123 |= V_30 ;
if ( V_98 -> V_118 & V_124 )
V_5 -> V_4 . V_123 |= V_31 | V_32 ;
if ( V_98 -> V_118 & V_120 )
V_5 -> V_4 . V_123 |= V_33 ;
F_36 ( & V_5 -> V_4 . V_49 , V_71 ) ;
}
static void F_48 ( struct V_2 * V_3 , unsigned int V_42 ,
unsigned int V_125 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_71 ;
F_35 ( & V_5 -> V_4 . V_49 , V_71 ) ;
if ( V_42 < 3 )
F_8 ( & V_5 -> V_4 ) ;
else
F_7 ( & V_5 -> V_4 ) ;
F_36 ( & V_5 -> V_4 . V_49 , V_71 ) ;
}
static const char * F_49 ( struct V_2 * V_3 )
{
return L_3 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_1 ( V_3 ) -> V_17 ;
int V_126 ;
F_51 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
V_126 = F_31 ( - 1 , & V_17 -> V_126 ) ;
if ( ! V_126 )
F_52 ( V_3 -> V_127 , V_128 ) ;
}
static int F_53 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 )
V_3 -> V_8 = F_54 ( V_3 -> V_127 ,
V_128 ) ;
if ( ! V_3 -> V_8 ) {
F_34 ( V_75 L_4 ) ;
return - V_129 ;
}
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_1 ( V_3 ) -> V_17 ;
int V_126 ;
int V_73 ;
V_126 = F_31 ( 1 , & V_17 -> V_126 ) ;
if ( V_126 == 1 ) {
if ( ! F_56 ( V_3 -> V_127 , V_128 ,
L_1 ) ) {
F_33 ( - 1 , & V_17 -> V_126 ) ;
F_34 ( V_75
L_5 ) ;
return - V_130 ;
}
}
V_73 = F_53 ( V_3 ) ;
if ( V_73 ) {
V_126 = F_31 ( - 1 , & V_17 -> V_126 ) ;
if ( ! V_126 )
F_52 ( V_3 -> V_127 , V_128 ) ;
return V_73 ;
}
return 0 ;
}
static void F_57 ( struct V_2 * V_3 , int V_71 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_71 & V_131 ) {
if ( F_55 ( V_3 ) )
return;
V_3 -> type = V_132 ;
F_42 ( V_5 ) ;
}
}
static int F_58 ( struct V_2 * V_3 , struct V_133 * V_134 )
{
int V_73 = 0 ;
if ( V_134 -> type != V_135 && V_134 -> type != V_132 )
V_73 = - V_136 ;
if ( V_134 -> V_57 != V_3 -> V_57 )
V_73 = - V_136 ;
return V_73 ;
}
static void T_4 F_59 ( void )
{
static int V_137 = 1 ;
unsigned long V_138 ;
int line ;
if ( ! V_137 )
return;
V_137 = 0 ;
if ( V_139 == V_140 || V_139 == V_141 )
V_138 = V_142 + V_143 ;
else
V_138 = V_142 + V_144 ;
for ( line = 0 ; line < V_21 ; line ++ ) {
struct V_1 * V_5 = & V_16 . V_5 [ line ] ;
struct V_2 * V_3 = & V_5 -> V_4 ;
V_5 -> V_17 = & V_16 ;
V_3 -> V_57 = V_145 [ V_146 ] ;
V_3 -> V_147 = 1 ;
V_3 -> V_148 = V_149 ;
V_3 -> V_71 = V_150 ;
V_3 -> V_151 = & V_152 ;
V_3 -> line = line ;
V_3 -> V_127 = V_138 ;
}
}
static void F_60 ( struct V_2 * V_3 , int V_22 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_71 ;
unsigned short V_153 , V_154 , V_155 , V_11 ;
int V_156 = 10000 ;
F_35 ( & V_5 -> V_4 . V_49 , V_71 ) ;
V_153 = F_3 ( V_5 , V_45 ) ;
F_5 ( V_5 , V_45 , V_153 & ~ V_62 ) ;
V_154 = F_3 ( V_5 , V_12 ) ;
V_154 |= 1 << V_5 -> V_4 . line ;
V_11 = V_154 ;
F_5 ( V_5 , V_12 , V_11 ) ;
F_43 () ;
F_36 ( & V_5 -> V_4 . V_49 , V_71 ) ;
do {
V_155 = F_3 ( V_5 , V_45 ) ;
if ( ! ( V_155 & V_61 ) )
continue;
V_155 = ( V_155 & V_157 ) >> 8 ;
if ( V_155 == V_5 -> V_4 . line )
break;
V_11 &= ~ ( 1 << V_155 ) ;
F_5 ( V_5 , V_12 , V_11 ) ;
F_43 () ;
F_61 ( 2 ) ;
} while ( -- V_156 );
if ( V_156 )
F_5 ( V_5 , V_47 , V_22 ) ;
F_5 ( V_5 , V_12 , V_154 ) ;
F_5 ( V_5 , V_45 , V_153 ) ;
}
static void F_62 ( struct V_158 * V_159 ,
const char * V_160 ,
unsigned int V_161 )
{
struct V_1 * V_5 = & V_16 . V_5 [ V_159 -> V_162 ] ;
#ifdef F_63
F_64 ( ( char * ) V_160 ) ;
#endif
F_65 ( & V_5 -> V_4 , V_160 , V_161 , F_60 ) ;
}
static int T_4 F_66 ( struct V_158 * V_159 , char * V_163 )
{
struct V_1 * V_5 = & V_16 . V_5 [ V_159 -> V_162 ] ;
struct V_2 * V_3 = & V_5 -> V_4 ;
int V_78 = 9600 ;
int V_164 = 8 ;
int V_36 = 'n' ;
int V_165 = 'n' ;
int V_73 ;
V_73 = F_53 ( V_3 ) ;
if ( V_73 )
return V_73 ;
F_67 ( & V_5 -> V_4 . V_49 ) ;
F_42 ( V_5 ) ;
F_48 ( V_3 , 0 , - 1 ) ;
if ( V_163 )
F_68 ( V_163 , & V_78 , & V_36 , & V_164 , & V_165 ) ;
return F_69 ( & V_5 -> V_4 , V_159 , V_78 , V_36 , V_164 , V_165 ) ;
}
static int T_4 F_70 ( void )
{
if ( ! V_166 ) {
F_59 () ;
F_71 ( & V_167 ) ;
return 0 ;
} else
return - V_168 ;
}
static int T_4 F_72 ( void )
{
int V_73 , V_25 ;
if ( V_166 )
return - V_168 ;
F_34 ( L_6 , V_169 , V_170 ) ;
F_59 () ;
V_73 = F_73 ( & V_171 ) ;
if ( V_73 )
return V_73 ;
for ( V_25 = 0 ; V_25 < V_21 ; V_25 ++ )
F_74 ( & V_171 , & V_16 . V_5 [ V_25 ] . V_4 ) ;
return 0 ;
}
