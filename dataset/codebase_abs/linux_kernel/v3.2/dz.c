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
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 ;
int V_22 [ V_23 ] = { [ 0 ... V_23 - 1 ] = 0 } ;
unsigned char V_24 , V_25 ;
T_1 V_26 ;
int V_27 ;
while ( ( V_26 = F_3 ( V_5 , V_28 ) ) & V_29 ) {
V_5 = & V_17 -> V_5 [ LINE ( V_26 ) ] ;
V_3 = & V_5 -> V_4 ;
V_19 = V_3 -> V_30 -> V_4 . V_19 ;
V_24 = F_12 ( V_26 ) ;
V_25 = V_31 ;
V_21 = & V_3 -> V_21 ;
V_21 -> V_32 ++ ;
if ( F_13 ( V_26 & ( V_33 | V_34 | V_35 ) ) ) {
if ( ! V_24 ) {
V_26 |= ( V_26 & V_34 ) >>
( F_14 ( V_34 ) - F_14 ( V_36 ) ) ;
V_26 &= ~ V_34 ;
}
if ( V_26 & V_36 ) {
V_21 -> V_37 ++ ;
if ( F_15 ( V_3 ) )
continue;
} else if ( V_26 & V_34 )
V_21 -> V_38 ++ ;
else if ( V_26 & V_35 )
V_21 -> V_39 ++ ;
if ( V_26 & V_33 )
V_21 -> V_40 ++ ;
V_26 &= V_3 -> V_41 ;
if ( V_26 & V_36 )
V_25 = V_42 ;
else if ( V_26 & V_34 )
V_25 = V_43 ;
else if ( V_26 & V_35 )
V_25 = V_44 ;
}
if ( F_16 ( V_3 , V_24 ) )
continue;
F_17 ( V_3 , V_26 , V_33 , V_24 , V_25 ) ;
V_22 [ LINE ( V_26 ) ] = 1 ;
}
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ )
if ( V_22 [ V_27 ] )
F_18 ( V_17 -> V_5 [ V_27 ] . V_4 . V_30 -> V_4 . V_19 ) ;
}
static inline void F_19 ( struct V_16 * V_17 )
{
struct V_1 * V_5 = & V_17 -> V_5 [ 0 ] ;
struct V_45 * V_46 ;
unsigned char V_10 ;
T_1 V_26 ;
V_26 = F_3 ( V_5 , V_47 ) ;
V_5 = & V_17 -> V_5 [ LINE ( V_26 ) ] ;
V_46 = & V_5 -> V_4 . V_30 -> V_46 ;
if ( V_5 -> V_4 . V_48 ) {
F_5 ( V_5 , V_49 , V_5 -> V_4 . V_48 ) ;
V_5 -> V_4 . V_21 . V_50 ++ ;
V_5 -> V_4 . V_48 = 0 ;
return;
}
if ( F_20 ( V_46 ) || F_21 ( & V_5 -> V_4 ) ) {
F_22 ( & V_5 -> V_4 . V_51 ) ;
F_7 ( & V_5 -> V_4 ) ;
F_23 ( & V_5 -> V_4 . V_51 ) ;
return;
}
V_10 = V_46 -> V_52 [ V_46 -> V_53 ] ;
V_46 -> V_53 = ( V_46 -> V_53 + 1 ) & ( V_54 - 1 ) ;
F_5 ( V_5 , V_49 , V_10 ) ;
V_5 -> V_4 . V_21 . V_50 ++ ;
if ( F_24 ( V_46 ) < V_55 )
F_25 ( & V_5 -> V_4 ) ;
if ( F_20 ( V_46 ) ) {
F_22 ( & V_5 -> V_4 . V_51 ) ;
F_7 ( & V_5 -> V_4 ) ;
F_23 ( & V_5 -> V_4 . V_51 ) ;
}
}
static inline void F_26 ( struct V_1 * V_5 )
{
T_1 V_26 ;
if ( V_5 -> V_4 . line != V_56 )
return;
V_26 = F_3 ( V_5 , V_57 ) ;
if ( V_26 )
V_5 -> V_4 . V_21 . V_58 ++ ;
}
static T_3 F_27 ( int V_59 , void * V_60 )
{
struct V_16 * V_17 = V_60 ;
struct V_1 * V_5 = & V_17 -> V_5 [ 0 ] ;
T_1 V_26 ;
V_26 = F_3 ( V_5 , V_47 ) ;
if ( ( V_26 & ( V_61 | V_62 ) ) == ( V_61 | V_62 ) )
F_11 ( V_17 ) ;
if ( ( V_26 & ( V_63 | V_64 ) ) == ( V_63 | V_64 ) )
F_19 ( V_17 ) ;
return V_65 ;
}
static unsigned int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_66 = V_67 | V_68 | V_69 ;
if ( V_5 -> V_4 . line == V_56 ) {
if ( F_3 ( V_5 , V_57 ) & V_70 )
V_66 &= ~ V_68 ;
}
return V_66 ;
}
static void F_29 ( struct V_2 * V_3 , unsigned int V_66 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_10 ;
if ( V_5 -> V_4 . line == V_56 ) {
V_10 = F_3 ( V_5 , V_12 ) ;
if ( V_66 & V_71 )
V_10 &= ~ V_72 ;
else
V_10 |= V_72 ;
F_5 ( V_5 , V_12 , V_10 ) ;
}
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_5 -> V_17 ;
unsigned long V_73 ;
int V_74 ;
int V_75 ;
T_1 V_10 ;
V_74 = F_31 ( 1 , & V_17 -> V_74 ) ;
if ( V_74 != 1 )
return 0 ;
V_75 = F_32 ( V_5 -> V_4 . V_59 , F_27 ,
V_76 , L_1 , V_17 ) ;
if ( V_75 ) {
F_33 ( - 1 , & V_17 -> V_74 ) ;
F_34 ( V_77 L_2 , V_5 -> V_4 . V_59 ) ;
return V_75 ;
}
F_35 ( & V_5 -> V_4 . V_51 , V_73 ) ;
V_10 = F_3 ( V_5 , V_47 ) ;
V_10 |= V_62 | V_64 ;
F_5 ( V_5 , V_47 , V_10 ) ;
F_36 ( & V_5 -> V_4 . V_51 , V_73 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_5 -> V_17 ;
unsigned long V_73 ;
int V_74 ;
T_1 V_10 ;
F_35 ( & V_5 -> V_4 . V_51 , V_73 ) ;
F_7 ( & V_5 -> V_4 ) ;
F_36 ( & V_5 -> V_4 . V_51 , V_73 ) ;
V_74 = F_31 ( - 1 , & V_17 -> V_74 ) ;
if ( ! V_74 ) {
V_10 = F_3 ( V_5 , V_47 ) ;
V_10 &= ~ ( V_62 | V_64 ) ;
F_5 ( V_5 , V_47 , V_10 ) ;
F_38 ( V_5 -> V_4 . V_59 , V_17 ) ;
}
}
static unsigned int F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned short V_10 , V_11 = 1 << V_5 -> V_4 . line ;
V_10 = F_3 ( V_5 , V_12 ) ;
V_10 &= V_11 ;
return V_10 ? 0 : V_78 ;
}
static void F_40 ( struct V_2 * V_3 , int V_79 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_73 ;
unsigned short V_10 , V_11 = 1 << V_5 -> V_4 . line ;
F_35 ( & V_3 -> V_51 , V_73 ) ;
V_10 = F_3 ( V_5 , V_12 ) ;
if ( V_79 )
V_10 |= V_11 ;
else
V_10 &= ~ V_11 ;
F_5 ( V_5 , V_12 , V_10 ) ;
F_36 ( & V_3 -> V_51 , V_73 ) ;
}
static int F_41 ( unsigned int V_80 )
{
switch ( V_80 ) {
case 50 :
return V_81 ;
case 75 :
return V_82 ;
case 110 :
return V_83 ;
case 134 :
return V_84 ;
case 150 :
return V_85 ;
case 300 :
return V_86 ;
case 600 :
return V_87 ;
case 1200 :
return V_88 ;
case 1800 :
return V_89 ;
case 2000 :
return V_90 ;
case 2400 :
return V_91 ;
case 3600 :
return V_92 ;
case 4800 :
return V_93 ;
case 7200 :
return V_94 ;
case 9600 :
return V_95 ;
default:
return - 1 ;
}
}
static void F_42 ( struct V_1 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_17 ;
if ( V_17 -> V_96 )
return;
F_5 ( V_5 , V_47 , V_97 ) ;
while ( F_3 ( V_5 , V_47 ) & V_97 ) ;
F_43 () ;
F_5 ( V_5 , V_47 , V_98 ) ;
V_17 -> V_96 = 1 ;
}
static void F_44 ( struct V_2 * V_3 , struct V_99 * V_100 ,
struct V_99 * V_101 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_73 ;
unsigned int V_13 , V_80 ;
int V_102 ;
V_13 = V_5 -> V_4 . line ;
switch ( V_100 -> V_103 & V_104 ) {
case V_105 :
V_13 |= V_106 ;
break;
case V_107 :
V_13 |= V_108 ;
break;
case V_109 :
V_13 |= V_110 ;
break;
case V_111 :
default:
V_13 |= V_112 ;
}
if ( V_100 -> V_103 & V_113 )
V_13 |= V_114 ;
if ( V_100 -> V_103 & V_115 )
V_13 |= V_116 ;
if ( V_100 -> V_103 & V_117 )
V_13 |= V_118 ;
V_80 = F_45 ( V_3 , V_100 , V_101 , 50 , 9600 ) ;
V_102 = F_41 ( V_80 ) ;
if ( V_102 < 0 ) {
V_80 = F_45 ( V_3 , V_101 , NULL , 50 , 9600 ) ;
V_102 = F_41 ( V_80 ) ;
if ( V_102 < 0 ) {
V_80 = 9600 ;
V_102 = V_95 ;
}
F_46 ( V_100 , V_80 , V_80 ) ;
}
V_13 |= V_102 ;
if ( V_100 -> V_103 & V_119 )
V_13 |= V_14 ;
F_35 ( & V_5 -> V_4 . V_51 , V_73 ) ;
F_47 ( V_3 , V_100 -> V_103 , V_80 ) ;
F_5 ( V_5 , V_15 , V_13 ) ;
V_5 -> V_13 = V_13 ;
V_5 -> V_4 . V_41 = V_33 ;
if ( V_100 -> V_120 & V_121 )
V_5 -> V_4 . V_41 |= V_34 | V_35 ;
if ( V_100 -> V_120 & ( V_122 | V_123 ) )
V_5 -> V_4 . V_41 |= V_36 ;
V_3 -> V_124 = 0 ;
if ( ( V_100 -> V_120 & ( V_125 | V_126 ) ) == ( V_125 | V_126 ) )
V_5 -> V_4 . V_124 |= V_33 ;
if ( V_100 -> V_120 & V_125 )
V_5 -> V_4 . V_124 |= V_34 | V_35 ;
if ( V_100 -> V_120 & V_126 )
V_5 -> V_4 . V_124 |= V_36 ;
F_36 ( & V_5 -> V_4 . V_51 , V_73 ) ;
}
static void F_48 ( struct V_2 * V_3 , unsigned int V_30 ,
unsigned int V_127 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_73 ;
F_35 ( & V_5 -> V_4 . V_51 , V_73 ) ;
if ( V_30 < 3 )
F_8 ( & V_5 -> V_4 ) ;
else
F_7 ( & V_5 -> V_4 ) ;
F_36 ( & V_5 -> V_4 . V_51 , V_73 ) ;
}
static const char * F_49 ( struct V_2 * V_3 )
{
return L_3 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_1 ( V_3 ) -> V_17 ;
int V_128 ;
F_51 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
V_128 = F_31 ( - 1 , & V_17 -> V_128 ) ;
if ( ! V_128 )
F_52 ( V_3 -> V_129 , V_130 ) ;
}
static int F_53 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 )
V_3 -> V_8 = F_54 ( V_3 -> V_129 ,
V_130 ) ;
if ( ! V_3 -> V_8 ) {
F_34 ( V_77 L_4 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_16 * V_17 = F_1 ( V_3 ) -> V_17 ;
int V_128 ;
int V_75 ;
V_128 = F_31 ( 1 , & V_17 -> V_128 ) ;
if ( V_128 == 1 ) {
if ( ! F_56 ( V_3 -> V_129 , V_130 ,
L_1 ) ) {
F_33 ( - 1 , & V_17 -> V_128 ) ;
F_34 ( V_77
L_5 ) ;
return - V_132 ;
}
}
V_75 = F_53 ( V_3 ) ;
if ( V_75 ) {
V_128 = F_31 ( - 1 , & V_17 -> V_128 ) ;
if ( ! V_128 )
F_52 ( V_3 -> V_129 , V_130 ) ;
return V_75 ;
}
return 0 ;
}
static void F_57 ( struct V_2 * V_3 , int V_73 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_73 & V_133 ) {
if ( F_55 ( V_3 ) )
return;
V_3 -> type = V_134 ;
F_42 ( V_5 ) ;
}
}
static int F_58 ( struct V_2 * V_3 , struct V_135 * V_136 )
{
int V_75 = 0 ;
if ( V_136 -> type != V_137 && V_136 -> type != V_134 )
V_75 = - V_138 ;
if ( V_136 -> V_59 != V_3 -> V_59 )
V_75 = - V_138 ;
return V_75 ;
}
static void T_4 F_59 ( void )
{
static int V_139 = 1 ;
unsigned long V_140 ;
int line ;
if ( ! V_139 )
return;
V_139 = 0 ;
if ( V_141 == V_142 || V_141 == V_143 )
V_140 = V_144 + V_145 ;
else
V_140 = V_144 + V_146 ;
for ( line = 0 ; line < V_23 ; line ++ ) {
struct V_1 * V_5 = & V_16 . V_5 [ line ] ;
struct V_2 * V_3 = & V_5 -> V_4 ;
V_5 -> V_17 = & V_16 ;
V_3 -> V_59 = V_147 [ V_148 ] ;
V_3 -> V_149 = 1 ;
V_3 -> V_150 = V_151 ;
V_3 -> V_73 = V_152 ;
V_3 -> V_153 = & V_154 ;
V_3 -> line = line ;
V_3 -> V_129 = V_140 ;
}
}
static void F_60 ( struct V_2 * V_3 , int V_24 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_73 ;
unsigned short V_155 , V_156 , V_157 , V_11 ;
int V_158 = 10000 ;
F_35 ( & V_5 -> V_4 . V_51 , V_73 ) ;
V_155 = F_3 ( V_5 , V_47 ) ;
F_5 ( V_5 , V_47 , V_155 & ~ V_64 ) ;
V_156 = F_3 ( V_5 , V_12 ) ;
V_156 |= 1 << V_5 -> V_4 . line ;
V_11 = V_156 ;
F_5 ( V_5 , V_12 , V_11 ) ;
F_43 () ;
F_36 ( & V_5 -> V_4 . V_51 , V_73 ) ;
do {
V_157 = F_3 ( V_5 , V_47 ) ;
if ( ! ( V_157 & V_63 ) )
continue;
V_157 = ( V_157 & V_159 ) >> 8 ;
if ( V_157 == V_5 -> V_4 . line )
break;
V_11 &= ~ ( 1 << V_157 ) ;
F_5 ( V_5 , V_12 , V_11 ) ;
F_43 () ;
F_61 ( 2 ) ;
} while ( -- V_158 );
if ( V_158 )
F_5 ( V_5 , V_49 , V_24 ) ;
F_5 ( V_5 , V_12 , V_156 ) ;
F_5 ( V_5 , V_47 , V_155 ) ;
}
static void F_62 ( struct V_160 * V_161 ,
const char * V_162 ,
unsigned int V_163 )
{
struct V_1 * V_5 = & V_16 . V_5 [ V_161 -> V_164 ] ;
#ifdef F_63
F_64 ( ( char * ) V_162 ) ;
#endif
F_65 ( & V_5 -> V_4 , V_162 , V_163 , F_60 ) ;
}
static int T_4 F_66 ( struct V_160 * V_161 , char * V_165 )
{
struct V_1 * V_5 = & V_16 . V_5 [ V_161 -> V_164 ] ;
struct V_2 * V_3 = & V_5 -> V_4 ;
int V_80 = 9600 ;
int V_166 = 8 ;
int V_39 = 'n' ;
int V_167 = 'n' ;
int V_75 ;
V_75 = F_53 ( V_3 ) ;
if ( V_75 )
return V_75 ;
F_67 ( & V_5 -> V_4 . V_51 ) ;
F_42 ( V_5 ) ;
F_48 ( V_3 , 0 , - 1 ) ;
if ( V_165 )
F_68 ( V_165 , & V_80 , & V_39 , & V_166 , & V_167 ) ;
return F_69 ( & V_5 -> V_4 , V_161 , V_80 , V_39 , V_166 , V_167 ) ;
}
static int T_4 F_70 ( void )
{
if ( ! V_168 ) {
F_59 () ;
F_71 ( & V_169 ) ;
return 0 ;
} else
return - V_170 ;
}
static int T_4 F_72 ( void )
{
int V_75 , V_27 ;
if ( V_168 )
return - V_170 ;
F_34 ( L_6 , V_171 , V_172 ) ;
F_59 () ;
V_75 = F_73 ( & V_173 ) ;
if ( V_75 )
return V_75 ;
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ )
F_74 ( & V_173 , & V_16 . V_5 [ V_27 ] . V_4 ) ;
return 0 ;
}
