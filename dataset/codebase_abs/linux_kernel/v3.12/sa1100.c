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
unsigned int V_3 , V_30 , V_31 ;
V_3 = F_17 ( F_18 ( V_2 ) ) |
F_12 ( F_19 ( V_2 ) ) ;
while ( V_3 & F_17 ( V_32 ) ) {
V_30 = F_20 ( V_2 ) ;
V_2 -> V_5 . V_10 . V_33 ++ ;
V_31 = V_34 ;
if ( V_3 & F_17 ( V_35 | V_36 | V_37 ) ) {
if ( V_3 & F_17 ( V_35 ) )
V_2 -> V_5 . V_10 . V_38 ++ ;
else if ( V_3 & F_17 ( V_36 ) )
V_2 -> V_5 . V_10 . V_39 ++ ;
if ( V_3 & F_17 ( V_37 ) )
V_2 -> V_5 . V_10 . V_40 ++ ;
V_3 &= V_2 -> V_5 . V_27 ;
if ( V_3 & F_17 ( V_35 ) )
V_31 = V_41 ;
else if ( V_3 & F_17 ( V_36 ) )
V_31 = V_42 ;
#ifdef F_21
V_2 -> V_5 . V_43 = 0 ;
#endif
}
if ( F_22 ( & V_2 -> V_5 , V_30 ) )
goto V_44;
F_23 ( & V_2 -> V_5 , V_3 , F_17 ( V_37 ) , V_30 , V_31 ) ;
V_44:
V_3 = F_17 ( F_18 ( V_2 ) ) |
F_12 ( F_19 ( V_2 ) ) ;
}
F_24 ( & V_2 -> V_5 . V_20 ) ;
F_25 ( & V_2 -> V_5 . V_16 -> V_5 ) ;
F_26 ( & V_2 -> V_5 . V_20 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = & V_2 -> V_5 . V_16 -> V_46 ;
if ( V_2 -> V_5 . V_47 ) {
F_28 ( V_2 , V_2 -> V_5 . V_47 ) ;
V_2 -> V_5 . V_10 . V_48 ++ ;
V_2 -> V_5 . V_47 = 0 ;
return;
}
F_1 ( V_2 ) ;
if ( F_29 ( V_46 ) || F_30 ( & V_2 -> V_5 ) ) {
F_9 ( & V_2 -> V_5 ) ;
return;
}
while ( F_18 ( V_2 ) & V_49 ) {
F_28 ( V_2 , V_46 -> V_50 [ V_46 -> V_51 ] ) ;
V_46 -> V_51 = ( V_46 -> V_51 + 1 ) & ( V_52 - 1 ) ;
V_2 -> V_5 . V_10 . V_48 ++ ;
if ( F_29 ( V_46 ) )
break;
}
if ( F_31 ( V_46 ) < V_53 )
F_32 ( & V_2 -> V_5 ) ;
if ( F_29 ( V_46 ) )
F_9 ( & V_2 -> V_5 ) ;
}
static T_2 F_33 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
unsigned int V_3 , V_56 = 0 ;
F_26 ( & V_2 -> V_5 . V_20 ) ;
V_3 = F_19 ( V_2 ) ;
V_3 &= F_34 ( V_2 -> V_5 . V_27 ) | ~ V_28 ;
do {
if ( V_3 & ( V_57 | V_58 ) ) {
if ( V_3 & V_58 )
F_35 ( V_2 , V_58 ) ;
F_16 ( V_2 ) ;
}
if ( V_3 & ( V_59 | V_60 ) )
F_35 ( V_2 , V_3 & ( V_59 | V_60 ) ) ;
if ( V_3 & V_59 )
V_2 -> V_5 . V_10 . V_61 ++ ;
if ( V_3 & V_60 )
F_36 ( & V_2 -> V_5 ) ;
if ( V_3 & V_28 )
F_27 ( V_2 ) ;
if ( V_56 ++ > V_62 )
break;
V_3 = F_19 ( V_2 ) ;
V_3 &= F_34 ( V_2 -> V_5 . V_27 ) |
~ V_28 ;
} while ( V_3 & ( V_28 | V_57 | V_58 ) );
F_24 ( & V_2 -> V_5 . V_20 ) ;
return V_63 ;
}
static unsigned int F_37 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
return F_18 ( V_2 ) & V_64 ? 0 : V_65 ;
}
static unsigned int F_38 ( struct V_24 * V_5 )
{
return V_15 | V_12 | V_14 ;
}
static void F_39 ( struct V_24 * V_5 , unsigned int V_66 )
{
}
static void F_40 ( struct V_24 * V_5 , int V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_19 ;
unsigned int V_25 ;
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
V_25 = F_10 ( V_2 ) ;
if ( V_67 == - 1 )
V_25 |= V_68 ;
else
V_25 &= ~ V_68 ;
F_11 ( V_2 , V_25 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
}
static int F_41 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
int V_69 ;
V_69 = F_42 ( V_2 -> V_5 . V_54 , F_33 , 0 ,
L_1 , V_2 ) ;
if ( V_69 )
return V_69 ;
F_35 ( V_2 , - 1 ) ;
F_11 ( V_2 , V_70 | V_71 | V_29 ) ;
F_43 ( & V_2 -> V_5 . V_20 ) ;
F_15 ( & V_2 -> V_5 ) ;
F_44 ( & V_2 -> V_5 . V_20 ) ;
return 0 ;
}
static void F_45 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
F_46 ( & V_2 -> V_21 ) ;
F_47 ( V_2 -> V_5 . V_54 , V_2 ) ;
F_11 ( V_2 , 0 ) ;
}
static void
F_48 ( struct V_24 * V_5 , struct V_72 * V_73 ,
struct V_72 * V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
unsigned long V_19 ;
unsigned int V_75 , V_76 , V_77 , V_78 ;
unsigned int V_79 = V_74 ? V_74 -> V_80 & V_81 : V_82 ;
while ( ( V_73 -> V_80 & V_81 ) != V_83 &&
( V_73 -> V_80 & V_81 ) != V_82 ) {
V_73 -> V_80 &= ~ V_81 ;
V_73 -> V_80 |= V_79 ;
V_79 = V_82 ;
}
if ( ( V_73 -> V_80 & V_81 ) == V_82 )
V_75 = V_84 ;
else
V_75 = 0 ;
if ( V_73 -> V_80 & V_85 )
V_75 |= V_86 ;
if ( V_73 -> V_80 & V_87 ) {
V_75 |= V_88 ;
if ( ! ( V_73 -> V_80 & V_89 ) )
V_75 |= V_90 ;
}
V_77 = F_49 ( V_5 , V_73 , V_74 , 0 , V_5 -> V_91 / 16 ) ;
V_78 = F_50 ( V_5 , V_77 ) ;
F_6 ( & V_2 -> V_5 . V_20 , V_19 ) ;
V_2 -> V_5 . V_27 &= F_12 ( V_28 ) ;
V_2 -> V_5 . V_27 |= F_17 ( V_37 ) ;
if ( V_73 -> V_92 & V_93 )
V_2 -> V_5 . V_27 |=
F_17 ( V_36 | V_35 ) ;
if ( V_73 -> V_92 & ( V_94 | V_95 ) )
V_2 -> V_5 . V_27 |=
F_12 ( V_59 | V_60 ) ;
V_2 -> V_5 . V_96 = 0 ;
if ( V_73 -> V_92 & V_97 )
V_2 -> V_5 . V_96 |=
F_17 ( V_36 | V_35 ) ;
if ( V_73 -> V_92 & V_98 ) {
V_2 -> V_5 . V_96 |=
F_12 ( V_59 | V_60 ) ;
if ( V_73 -> V_92 & V_97 )
V_2 -> V_5 . V_96 |=
F_17 ( V_37 ) ;
}
F_46 ( & V_2 -> V_21 ) ;
F_51 ( V_5 , V_73 -> V_80 , V_77 ) ;
V_76 = F_10 ( V_2 ) ;
F_11 ( V_2 , V_76 & ~ ( V_29 | V_26 ) ) ;
while ( F_18 ( V_2 ) & V_64 )
F_52 () ;
F_11 ( V_2 , 0 ) ;
F_53 ( V_2 , V_75 ) ;
V_78 -= 1 ;
F_54 ( V_2 , ( ( V_78 & 0xf00 ) >> 8 ) ) ;
F_55 ( V_2 , ( V_78 & 0xff ) ) ;
F_35 ( V_2 , - 1 ) ;
F_11 ( V_2 , V_76 ) ;
if ( F_56 ( & V_2 -> V_5 , V_73 -> V_80 ) )
F_15 ( & V_2 -> V_5 ) ;
F_7 ( & V_2 -> V_5 . V_20 , V_19 ) ;
}
static const char * F_57 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
return V_2 -> V_5 . type == V_99 ? L_2 : NULL ;
}
static void F_58 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
F_59 ( V_2 -> V_5 . V_100 , V_101 ) ;
}
static int F_60 ( struct V_24 * V_5 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
return F_61 ( V_2 -> V_5 . V_100 , V_101 ,
L_1 ) != NULL ? 0 : - V_102 ;
}
static void F_62 ( struct V_24 * V_5 , int V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
if ( V_19 & V_103 &&
F_60 ( & V_2 -> V_5 ) == 0 )
V_2 -> V_5 . type = V_99 ;
}
static int
F_63 ( struct V_24 * V_5 , struct V_104 * V_105 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
int V_106 = 0 ;
if ( V_105 -> type != V_107 && V_105 -> type != V_99 )
V_106 = - V_108 ;
if ( V_2 -> V_5 . V_54 != V_105 -> V_54 )
V_106 = - V_108 ;
if ( V_105 -> V_109 != V_110 )
V_106 = - V_108 ;
if ( V_2 -> V_5 . V_91 / 16 != V_105 -> V_111 )
V_106 = - V_108 ;
if ( ( void * ) V_2 -> V_5 . V_100 != V_105 -> V_112 )
V_106 = - V_108 ;
if ( V_2 -> V_5 . V_113 != V_105 -> V_5 )
V_106 = - V_108 ;
if ( V_105 -> V_114 != 0 )
V_106 = - V_108 ;
return V_106 ;
}
static void T_3 F_64 ( void )
{
static int V_115 = 1 ;
int V_116 ;
if ( ! V_115 )
return;
V_115 = 0 ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
V_118 [ V_116 ] . V_5 . V_91 = 3686400 ;
V_118 [ V_116 ] . V_5 . V_6 = & V_119 ;
V_118 [ V_116 ] . V_5 . V_120 = 8 ;
V_118 [ V_116 ] . V_5 . line = V_116 ;
V_118 [ V_116 ] . V_5 . V_121 = V_122 ;
F_65 ( & V_118 [ V_116 ] . V_21 ) ;
V_118 [ V_116 ] . V_21 . V_123 = F_5 ;
V_118 [ V_116 ] . V_21 . V_18 = ( unsigned long ) & V_118 [ V_116 ] ;
}
V_124 |= V_125 | V_126 ;
V_127 |= V_125 | V_126 ;
}
void F_66 ( struct V_128 * V_129 )
{
if ( V_129 -> V_7 )
V_119 . V_7 = V_129 -> V_7 ;
if ( V_129 -> V_130 )
V_119 . V_130 = V_129 -> V_130 ;
V_119 . V_131 = V_129 -> V_131 ;
V_119 . V_132 = V_129 -> V_132 ;
}
void T_3 F_67 ( int V_133 , int V_5 )
{
if ( V_133 >= V_117 ) {
F_68 ( V_134 L_3 , V_135 , V_133 ) ;
return;
}
switch ( V_5 ) {
case 1 :
V_118 [ V_133 ] . V_5 . V_136 = ( void V_137 * ) & V_138 ;
V_118 [ V_133 ] . V_5 . V_100 = V_139 ;
V_118 [ V_133 ] . V_5 . V_54 = V_140 ;
V_118 [ V_133 ] . V_5 . V_19 = V_141 ;
break;
case 2 :
V_118 [ V_133 ] . V_5 . V_136 = ( void V_137 * ) & V_142 ;
V_118 [ V_133 ] . V_5 . V_100 = V_143 ;
V_118 [ V_133 ] . V_5 . V_54 = V_144 ;
V_118 [ V_133 ] . V_5 . V_19 = V_141 ;
break;
case 3 :
V_118 [ V_133 ] . V_5 . V_136 = ( void V_137 * ) & V_145 ;
V_118 [ V_133 ] . V_5 . V_100 = V_146 ;
V_118 [ V_133 ] . V_5 . V_54 = V_147 ;
V_118 [ V_133 ] . V_5 . V_19 = V_141 ;
break;
default:
F_68 ( V_134 L_4 , V_135 , V_5 ) ;
}
}
static void F_69 ( struct V_24 * V_5 , int V_30 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 ;
while ( ! ( F_18 ( V_2 ) & V_49 ) )
F_52 () ;
F_28 ( V_2 , V_30 ) ;
}
static void
F_70 ( struct V_148 * V_149 , const char * V_150 , unsigned int V_151 )
{
struct V_1 * V_2 = & V_118 [ V_149 -> V_152 ] ;
unsigned int V_76 , V_3 ;
V_76 = F_10 ( V_2 ) ;
F_11 ( V_2 , ( V_76 & ~ ( V_29 | V_26 ) ) |
V_71 ) ;
F_71 ( & V_2 -> V_5 , V_150 , V_151 , F_69 ) ;
do {
V_3 = F_18 ( V_2 ) ;
} while ( V_3 & V_64 );
F_11 ( V_2 , V_76 ) ;
}
static void T_3
F_72 ( struct V_1 * V_2 , int * V_77 ,
int * V_38 , int * V_153 )
{
unsigned int V_25 ;
V_25 = F_10 ( V_2 ) & ( V_70 | V_71 ) ;
if ( V_25 == ( V_70 | V_71 ) ) {
unsigned int V_75 , V_78 ;
V_75 = F_73 ( V_2 ) ;
* V_38 = 'n' ;
if ( V_75 & V_88 ) {
if ( V_75 & V_90 )
* V_38 = 'e' ;
else
* V_38 = 'o' ;
}
if ( V_75 & V_84 )
* V_153 = 8 ;
else
* V_153 = 7 ;
V_78 = F_74 ( V_2 ) | F_75 ( V_2 ) << 8 ;
V_78 &= 0xfff ;
* V_77 = V_2 -> V_5 . V_91 / ( 16 * ( V_78 + 1 ) ) ;
}
}
static int T_3
F_76 ( struct V_148 * V_149 , char * V_154 )
{
struct V_1 * V_2 ;
int V_77 = 9600 ;
int V_153 = 8 ;
int V_38 = 'n' ;
int V_155 = 'n' ;
if ( V_149 -> V_152 == - 1 || V_149 -> V_152 >= V_117 )
V_149 -> V_152 = 0 ;
V_2 = & V_118 [ V_149 -> V_152 ] ;
if ( V_154 )
F_77 ( V_154 , & V_77 , & V_38 , & V_153 , & V_155 ) ;
else
F_72 ( V_2 , & V_77 , & V_38 , & V_153 ) ;
return F_78 ( & V_2 -> V_5 , V_149 , V_77 , V_38 , V_153 , V_155 ) ;
}
static int T_3 F_79 ( void )
{
F_64 () ;
F_80 ( & V_156 ) ;
return 0 ;
}
static int F_81 ( struct V_157 * V_158 , T_4 V_16 )
{
struct V_1 * V_2 = F_82 ( V_158 ) ;
if ( V_2 )
F_83 ( & V_159 , & V_2 -> V_5 ) ;
return 0 ;
}
static int F_84 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_82 ( V_158 ) ;
if ( V_2 )
F_85 ( & V_159 , & V_2 -> V_5 ) ;
return 0 ;
}
static int F_86 ( struct V_157 * V_158 )
{
struct V_160 * V_161 = V_158 -> V_160 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < V_158 -> V_162 ; V_116 ++ , V_161 ++ )
if ( V_161 -> V_19 & V_163 )
break;
if ( V_116 < V_158 -> V_162 ) {
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
if ( V_118 [ V_116 ] . V_5 . V_100 != V_161 -> V_164 )
continue;
V_118 [ V_116 ] . V_5 . V_158 = & V_158 -> V_158 ;
F_87 ( & V_159 , & V_118 [ V_116 ] . V_5 ) ;
F_88 ( V_158 , & V_118 [ V_116 ] ) ;
break;
}
}
return 0 ;
}
static int F_89 ( struct V_157 * V_165 )
{
struct V_1 * V_2 = F_82 ( V_165 ) ;
if ( V_2 )
F_90 ( & V_159 , & V_2 -> V_5 ) ;
return 0 ;
}
static int T_3 F_91 ( void )
{
int V_106 ;
F_68 ( V_166 L_5 ) ;
F_64 () ;
V_106 = F_92 ( & V_159 ) ;
if ( V_106 == 0 ) {
V_106 = F_93 ( & V_167 ) ;
if ( V_106 )
F_94 ( & V_159 ) ;
}
return V_106 ;
}
static void T_5 F_95 ( void )
{
F_96 ( & V_167 ) ;
F_94 ( & V_159 ) ;
}
