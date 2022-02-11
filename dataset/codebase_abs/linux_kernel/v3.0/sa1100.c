static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 ;
V_3 = V_2 -> V_5 . V_6 -> V_7 ( & V_2 -> V_5 ) ;
V_4 = V_3 ^ V_2 -> V_8 ;
if ( V_4 == 0 )
return;
V_2 -> V_8 = V_3 ;
if ( V_4 & V_9 )
V_2 -> V_5 . V_10 . V_11 ++ ;
if ( V_4 & V_12 )
V_2 -> V_5 . V_10 . V_13 ++ ;
if ( V_4 & V_14 )
F_2 ( & V_2 -> V_5 , V_3 & V_14 ) ;
if ( V_4 & V_15 )
F_3 ( & V_2 -> V_5 , V_3 & V_15 ) ;
F_4 ( & V_2 -> V_5 . V_16 -> V_5 . V_17 ) ;
}
static void F_5 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
unsigned long V_19 ;
if ( V_2 -> V_5 . V_16 ) {
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
F_8 ( & V_2 -> V_21 , V_22 + V_23 ) ;
}
}
static void F_9 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
T_1 V_25 ;
V_25 = F_10 ( V_2 ) ;
F_11 ( V_2 , V_25 & ~ V_26 ) ;
V_2 -> V_5 . V_27 &= ~ F_12 ( V_28 ) ;
}
static void F_13 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
T_1 V_25 ;
V_25 = F_10 ( V_2 ) ;
V_2 -> V_5 . V_27 |= F_12 ( V_28 ) ;
F_11 ( V_2 , V_25 | V_26 ) ;
}
static void F_14 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
T_1 V_25 ;
V_25 = F_10 ( V_2 ) ;
F_11 ( V_2 , V_25 & ~ V_29 ) ;
}
static void F_15 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
F_8 ( & V_2 -> V_21 , V_22 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_5 . V_16 -> V_5 . V_31 ;
unsigned int V_3 , V_32 , V_33 ;
V_3 = F_17 ( F_18 ( V_2 ) ) |
F_12 ( F_19 ( V_2 ) ) ;
while ( V_3 & F_17 ( V_34 ) ) {
V_32 = F_20 ( V_2 ) ;
V_2 -> V_5 . V_10 . V_35 ++ ;
V_33 = V_36 ;
if ( V_3 & F_17 ( V_37 | V_38 | V_39 ) ) {
if ( V_3 & F_17 ( V_37 ) )
V_2 -> V_5 . V_10 . V_40 ++ ;
else if ( V_3 & F_17 ( V_38 ) )
V_2 -> V_5 . V_10 . V_41 ++ ;
if ( V_3 & F_17 ( V_39 ) )
V_2 -> V_5 . V_10 . V_42 ++ ;
V_3 &= V_2 -> V_5 . V_27 ;
if ( V_3 & F_17 ( V_37 ) )
V_33 = V_43 ;
else if ( V_3 & F_17 ( V_38 ) )
V_33 = V_44 ;
#ifdef F_21
V_2 -> V_5 . V_45 = 0 ;
#endif
}
if ( F_22 ( & V_2 -> V_5 , V_32 ) )
goto V_46;
F_23 ( & V_2 -> V_5 , V_3 , F_17 ( V_39 ) , V_32 , V_33 ) ;
V_46:
V_3 = F_17 ( F_18 ( V_2 ) ) |
F_12 ( F_19 ( V_2 ) ) ;
}
F_24 ( V_31 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = & V_2 -> V_5 . V_16 -> V_48 ;
if ( V_2 -> V_5 . V_49 ) {
F_26 ( V_2 , V_2 -> V_5 . V_49 ) ;
V_2 -> V_5 . V_10 . V_50 ++ ;
V_2 -> V_5 . V_49 = 0 ;
return;
}
F_1 ( V_2 ) ;
if ( F_27 ( V_48 ) || F_28 ( & V_2 -> V_5 ) ) {
F_9 ( & V_2 -> V_5 ) ;
return;
}
while ( F_18 ( V_2 ) & V_51 ) {
F_26 ( V_2 , V_48 -> V_52 [ V_48 -> V_53 ] ) ;
V_48 -> V_53 = ( V_48 -> V_53 + 1 ) & ( V_54 - 1 ) ;
V_2 -> V_5 . V_10 . V_50 ++ ;
if ( F_27 ( V_48 ) )
break;
}
if ( F_29 ( V_48 ) < V_55 )
F_30 ( & V_2 -> V_5 ) ;
if ( F_27 ( V_48 ) )
F_9 ( & V_2 -> V_5 ) ;
}
static T_2 F_31 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
unsigned int V_3 , V_58 = 0 ;
F_32 ( & V_2 -> V_5 . V_20 ) ;
V_3 = F_19 ( V_2 ) ;
V_3 &= F_33 ( V_2 -> V_5 . V_27 ) | ~ V_28 ;
do {
if ( V_3 & ( V_59 | V_60 ) ) {
if ( V_3 & V_60 )
F_34 ( V_2 , V_60 ) ;
F_16 ( V_2 ) ;
}
if ( V_3 & ( V_61 | V_62 ) )
F_34 ( V_2 , V_3 & ( V_61 | V_62 ) ) ;
if ( V_3 & V_61 )
V_2 -> V_5 . V_10 . V_63 ++ ;
if ( V_3 & V_62 )
F_35 ( & V_2 -> V_5 ) ;
if ( V_3 & V_28 )
F_25 ( V_2 ) ;
if ( V_58 ++ > V_64 )
break;
V_3 = F_19 ( V_2 ) ;
V_3 &= F_33 ( V_2 -> V_5 . V_27 ) |
~ V_28 ;
} while ( V_3 & ( V_28 | V_59 | V_60 ) );
F_36 ( & V_2 -> V_5 . V_20 ) ;
return V_65 ;
}
static unsigned int F_37 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
return F_18 ( V_2 ) & V_66 ? 0 : V_67 ;
}
static unsigned int F_38 ( struct V_24 * V_5 )
{
return V_15 | V_12 | V_14 ;
}
static void F_39 ( struct V_24 * V_5 , unsigned int V_68 )
{
}
static void F_40 ( struct V_24 * V_5 , int V_69 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_19 ;
unsigned int V_25 ;
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
V_25 = F_10 ( V_2 ) ;
if ( V_69 == - 1 )
V_25 |= V_70 ;
else
V_25 &= ~ V_70 ;
F_11 ( V_2 , V_25 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
}
static int F_41 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
int V_71 ;
V_71 = F_42 ( V_2 -> V_5 . V_56 , F_31 , 0 ,
L_1 , V_2 ) ;
if ( V_71 )
return V_71 ;
F_34 ( V_2 , - 1 ) ;
F_11 ( V_2 , V_72 | V_73 | V_29 ) ;
F_43 ( & V_2 -> V_5 . V_20 ) ;
F_15 ( & V_2 -> V_5 ) ;
F_44 ( & V_2 -> V_5 . V_20 ) ;
return 0 ;
}
static void F_45 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
F_46 ( & V_2 -> V_21 ) ;
F_47 ( V_2 -> V_5 . V_56 , V_2 ) ;
F_11 ( V_2 , 0 ) ;
}
static void
F_48 ( struct V_24 * V_5 , struct V_74 * V_75 ,
struct V_74 * V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_19 ;
unsigned int V_77 , V_78 , V_79 , V_80 ;
unsigned int V_81 = V_76 ? V_76 -> V_82 & V_83 : V_84 ;
while ( ( V_75 -> V_82 & V_83 ) != V_85 &&
( V_75 -> V_82 & V_83 ) != V_84 ) {
V_75 -> V_82 &= ~ V_83 ;
V_75 -> V_82 |= V_81 ;
V_81 = V_84 ;
}
if ( ( V_75 -> V_82 & V_83 ) == V_84 )
V_77 = V_86 ;
else
V_77 = 0 ;
if ( V_75 -> V_82 & V_87 )
V_77 |= V_88 ;
if ( V_75 -> V_82 & V_89 ) {
V_77 |= V_90 ;
if ( ! ( V_75 -> V_82 & V_91 ) )
V_77 |= V_92 ;
}
V_79 = F_49 ( V_5 , V_75 , V_76 , 0 , V_5 -> V_93 / 16 ) ;
V_80 = F_50 ( V_5 , V_79 ) ;
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
V_2 -> V_5 . V_27 &= F_12 ( V_28 ) ;
V_2 -> V_5 . V_27 |= F_17 ( V_39 ) ;
if ( V_75 -> V_94 & V_95 )
V_2 -> V_5 . V_27 |=
F_17 ( V_38 | V_37 ) ;
if ( V_75 -> V_94 & ( V_96 | V_97 ) )
V_2 -> V_5 . V_27 |=
F_12 ( V_61 | V_62 ) ;
V_2 -> V_5 . V_98 = 0 ;
if ( V_75 -> V_94 & V_99 )
V_2 -> V_5 . V_98 |=
F_17 ( V_38 | V_37 ) ;
if ( V_75 -> V_94 & V_100 ) {
V_2 -> V_5 . V_98 |=
F_12 ( V_61 | V_62 ) ;
if ( V_75 -> V_94 & V_99 )
V_2 -> V_5 . V_98 |=
F_17 ( V_39 ) ;
}
F_46 ( & V_2 -> V_21 ) ;
F_51 ( V_5 , V_75 -> V_82 , V_79 ) ;
V_78 = F_10 ( V_2 ) ;
F_11 ( V_2 , V_78 & ~ ( V_29 | V_26 ) ) ;
while ( F_18 ( V_2 ) & V_66 )
F_52 () ;
F_11 ( V_2 , 0 ) ;
F_53 ( V_2 , V_77 ) ;
V_80 -= 1 ;
F_54 ( V_2 , ( ( V_80 & 0xf00 ) >> 8 ) ) ;
F_55 ( V_2 , ( V_80 & 0xff ) ) ;
F_34 ( V_2 , - 1 ) ;
F_11 ( V_2 , V_78 ) ;
if ( F_56 ( & V_2 -> V_5 , V_75 -> V_82 ) )
F_15 ( & V_2 -> V_5 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
}
static const char * F_57 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
return V_2 -> V_5 . type == V_101 ? L_2 : NULL ;
}
static void F_58 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
F_59 ( V_2 -> V_5 . V_102 , V_103 ) ;
}
static int F_60 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
return F_61 ( V_2 -> V_5 . V_102 , V_103 ,
L_1 ) != NULL ? 0 : - V_104 ;
}
static void F_62 ( struct V_24 * V_5 , int V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
if ( V_19 & V_105 &&
F_60 ( & V_2 -> V_5 ) == 0 )
V_2 -> V_5 . type = V_101 ;
}
static int
F_63 ( struct V_24 * V_5 , struct V_106 * V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
int V_108 = 0 ;
if ( V_107 -> type != V_109 && V_107 -> type != V_101 )
V_108 = - V_110 ;
if ( V_2 -> V_5 . V_56 != V_107 -> V_56 )
V_108 = - V_110 ;
if ( V_107 -> V_111 != V_112 )
V_108 = - V_110 ;
if ( V_2 -> V_5 . V_93 / 16 != V_107 -> V_113 )
V_108 = - V_110 ;
if ( ( void * ) V_2 -> V_5 . V_102 != V_107 -> V_114 )
V_108 = - V_110 ;
if ( V_2 -> V_5 . V_115 != V_107 -> V_5 )
V_108 = - V_110 ;
if ( V_107 -> V_116 != 0 )
V_108 = - V_110 ;
return V_108 ;
}
static void T_3 F_64 ( void )
{
static int V_117 = 1 ;
int V_118 ;
if ( ! V_117 )
return;
V_117 = 0 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
V_120 [ V_118 ] . V_5 . V_93 = 3686400 ;
V_120 [ V_118 ] . V_5 . V_6 = & V_121 ;
V_120 [ V_118 ] . V_5 . V_122 = 8 ;
V_120 [ V_118 ] . V_5 . line = V_118 ;
V_120 [ V_118 ] . V_5 . V_123 = V_124 ;
F_65 ( & V_120 [ V_118 ] . V_21 ) ;
V_120 [ V_118 ] . V_21 . V_125 = F_5 ;
V_120 [ V_118 ] . V_21 . V_18 = ( unsigned long ) & V_120 [ V_118 ] ;
}
V_126 |= V_127 | V_128 ;
V_129 |= V_127 | V_128 ;
}
void T_4 F_66 ( struct V_130 * V_131 )
{
if ( V_131 -> V_7 )
V_121 . V_7 = V_131 -> V_7 ;
if ( V_131 -> V_132 )
V_121 . V_132 = V_131 -> V_132 ;
V_121 . V_133 = V_131 -> V_133 ;
V_121 . V_134 = V_131 -> V_134 ;
}
void T_3 F_67 ( int V_135 , int V_5 )
{
if ( V_135 >= V_119 ) {
F_68 ( V_136 L_3 , V_137 , V_135 ) ;
return;
}
switch ( V_5 ) {
case 1 :
V_120 [ V_135 ] . V_5 . V_138 = ( void V_139 * ) & V_140 ;
V_120 [ V_135 ] . V_5 . V_102 = V_141 ;
V_120 [ V_135 ] . V_5 . V_56 = V_142 ;
V_120 [ V_135 ] . V_5 . V_19 = V_143 ;
break;
case 2 :
V_120 [ V_135 ] . V_5 . V_138 = ( void V_139 * ) & V_144 ;
V_120 [ V_135 ] . V_5 . V_102 = V_145 ;
V_120 [ V_135 ] . V_5 . V_56 = V_146 ;
V_120 [ V_135 ] . V_5 . V_19 = V_143 ;
break;
case 3 :
V_120 [ V_135 ] . V_5 . V_138 = ( void V_139 * ) & V_147 ;
V_120 [ V_135 ] . V_5 . V_102 = V_148 ;
V_120 [ V_135 ] . V_5 . V_56 = V_149 ;
V_120 [ V_135 ] . V_5 . V_19 = V_143 ;
break;
default:
F_68 ( V_136 L_4 , V_137 , V_5 ) ;
}
}
static void F_69 ( struct V_24 * V_5 , int V_32 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
while ( ! ( F_18 ( V_2 ) & V_51 ) )
F_52 () ;
F_26 ( V_2 , V_32 ) ;
}
static void
F_70 ( struct V_150 * V_151 , const char * V_152 , unsigned int V_153 )
{
struct V_1 * V_2 = & V_120 [ V_151 -> V_154 ] ;
unsigned int V_78 , V_3 ;
V_78 = F_10 ( V_2 ) ;
F_11 ( V_2 , ( V_78 & ~ ( V_29 | V_26 ) ) |
V_73 ) ;
F_71 ( & V_2 -> V_5 , V_152 , V_153 , F_69 ) ;
do {
V_3 = F_18 ( V_2 ) ;
} while ( V_3 & V_66 );
F_11 ( V_2 , V_78 ) ;
}
static void T_3
F_72 ( struct V_1 * V_2 , int * V_79 ,
int * V_40 , int * V_155 )
{
unsigned int V_25 ;
V_25 = F_10 ( V_2 ) & ( V_72 | V_73 ) ;
if ( V_25 == ( V_72 | V_73 ) ) {
unsigned int V_77 , V_80 ;
V_77 = F_73 ( V_2 ) ;
* V_40 = 'n' ;
if ( V_77 & V_90 ) {
if ( V_77 & V_92 )
* V_40 = 'e' ;
else
* V_40 = 'o' ;
}
if ( V_77 & V_86 )
* V_155 = 8 ;
else
* V_155 = 7 ;
V_80 = F_74 ( V_2 ) | F_75 ( V_2 ) << 8 ;
V_80 &= 0xfff ;
* V_79 = V_2 -> V_5 . V_93 / ( 16 * ( V_80 + 1 ) ) ;
}
}
static int T_3
F_76 ( struct V_150 * V_151 , char * V_156 )
{
struct V_1 * V_2 ;
int V_79 = 9600 ;
int V_155 = 8 ;
int V_40 = 'n' ;
int V_157 = 'n' ;
if ( V_151 -> V_154 == - 1 || V_151 -> V_154 >= V_119 )
V_151 -> V_154 = 0 ;
V_2 = & V_120 [ V_151 -> V_154 ] ;
if ( V_156 )
F_77 ( V_156 , & V_79 , & V_40 , & V_155 , & V_157 ) ;
else
F_72 ( V_2 , & V_79 , & V_40 , & V_155 ) ;
return F_78 ( & V_2 -> V_5 , V_151 , V_79 , V_40 , V_155 , V_157 ) ;
}
static int T_3 F_79 ( void )
{
F_64 () ;
F_80 ( & V_158 ) ;
return 0 ;
}
static int F_81 ( struct V_159 * V_160 , T_5 V_16 )
{
struct V_1 * V_2 = F_82 ( V_160 ) ;
if ( V_2 )
F_83 ( & V_161 , & V_2 -> V_5 ) ;
return 0 ;
}
static int F_84 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = F_82 ( V_160 ) ;
if ( V_2 )
F_85 ( & V_161 , & V_2 -> V_5 ) ;
return 0 ;
}
static int F_86 ( struct V_159 * V_160 )
{
struct V_162 * V_163 = V_160 -> V_162 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_160 -> V_164 ; V_118 ++ , V_163 ++ )
if ( V_163 -> V_19 & V_165 )
break;
if ( V_118 < V_160 -> V_164 ) {
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
if ( V_120 [ V_118 ] . V_5 . V_102 != V_163 -> V_166 )
continue;
V_120 [ V_118 ] . V_5 . V_160 = & V_160 -> V_160 ;
F_87 ( & V_161 , & V_120 [ V_118 ] . V_5 ) ;
F_88 ( V_160 , & V_120 [ V_118 ] ) ;
break;
}
}
return 0 ;
}
static int F_89 ( struct V_159 * V_167 )
{
struct V_1 * V_2 = F_82 ( V_167 ) ;
F_88 ( V_167 , NULL ) ;
if ( V_2 )
F_90 ( & V_161 , & V_2 -> V_5 ) ;
return 0 ;
}
static int T_3 F_91 ( void )
{
int V_108 ;
F_68 ( V_168 L_5 ) ;
F_64 () ;
V_108 = F_92 ( & V_161 ) ;
if ( V_108 == 0 ) {
V_108 = F_93 ( & V_169 ) ;
if ( V_108 )
F_94 ( & V_161 ) ;
}
return V_108 ;
}
static void T_6 F_95 ( void )
{
F_96 ( & V_169 ) ;
F_94 ( & V_161 ) ;
}
