static unsigned int F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 + V_4 ) & V_5 ) ?
V_6 : 0 ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned int V_9 ;
V_9 = ( F_2 ( V_2 -> V_3 + V_10 ) & V_11 ) ?
0 : V_12 ;
V_9 |= ( V_8 -> V_9 & V_13 ) ;
V_9 |= ( F_5 ( V_2 -> line ) ? V_14 : 0 ) ;
V_9 |= ( F_6 ( V_2 -> line ) ? V_15 : 0 ) ;
return V_9 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_9 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
V_8 -> V_9 = V_9 ;
F_8 ( V_2 -> line , ( V_9 & V_15 ) ) ;
if ( V_9 & V_13 )
F_9 ( V_16 , V_2 -> V_3 + V_17 ) ;
else
F_9 ( V_16 , V_2 -> V_3 + V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
if ( V_2 -> V_19 . V_20 & V_21 ) {
F_9 ( V_22 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_16 , V_2 -> V_3 + V_17 ) ;
}
V_8 -> V_24 |= V_25 ;
F_9 ( V_8 -> V_24 , V_2 -> V_3 + V_26 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
V_8 -> V_24 &= ~ V_25 ;
F_9 ( V_8 -> V_24 , V_2 -> V_3 + V_26 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
V_8 -> V_24 &= ~ V_27 ;
F_9 ( V_8 -> V_24 , V_2 -> V_3 + V_26 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_28 )
{
unsigned long V_20 ;
F_14 ( & V_2 -> V_29 , V_20 ) ;
if ( V_28 == - 1 )
F_9 ( V_30 , V_2 -> V_3 + V_23 ) ;
else
F_9 ( V_31 , V_2 -> V_3 + V_23 ) ;
F_15 ( & V_2 -> V_29 , V_20 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned long V_20 ;
F_14 ( & V_2 -> V_29 , V_20 ) ;
F_9 ( V_32 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_33 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_34 | V_22 ,
V_2 -> V_3 + V_23 ) ;
V_8 -> V_24 = V_27 ;
F_9 ( V_8 -> V_24 , V_2 -> V_3 + V_26 ) ;
F_15 ( & V_2 -> V_29 , V_20 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned long V_20 ;
F_14 ( & V_2 -> V_29 , V_20 ) ;
V_8 -> V_24 = 0 ;
F_9 ( V_8 -> V_24 , V_2 -> V_3 + V_26 ) ;
F_9 ( V_32 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_33 , V_2 -> V_3 + V_23 ) ;
F_15 ( & V_2 -> V_29 , V_20 ) ;
}
static void F_18 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_35 * V_37 )
{
unsigned long V_20 ;
unsigned int V_38 , V_39 ;
#if F_19 ( V_40 )
unsigned int V_41 ;
#endif
unsigned char V_42 , V_43 ;
V_38 = F_20 ( V_2 , V_36 , V_37 , 0 , 230400 ) ;
#if F_19 ( V_40 )
V_39 = ( V_44 / V_38 ) / 32 ;
V_41 = ( ( ( V_44 / V_38 ) + 1 ) / 2 ) % 16 ;
#else
V_39 = ( ( V_44 / V_38 ) + 16 ) / 32 ;
#endif
V_42 = V_45 | V_46 ;
V_43 = 0 ;
switch ( V_36 -> V_47 & V_48 ) {
case V_49 : V_42 |= V_50 ; break;
case V_51 : V_42 |= V_52 ; break;
case V_53 : V_42 |= V_54 ; break;
case V_55 :
default: V_42 |= V_56 ; break;
}
if ( V_36 -> V_47 & V_57 ) {
if ( V_36 -> V_47 & V_58 ) {
if ( V_36 -> V_47 & V_59 )
V_42 |= V_60 ;
else
V_42 |= V_61 ;
} else {
if ( V_36 -> V_47 & V_59 )
V_42 |= V_62 ;
else
V_42 |= V_63 ;
}
} else {
V_42 |= V_64 ;
}
if ( V_36 -> V_47 & V_65 )
V_43 |= V_66 ;
else
V_43 |= V_67 ;
if ( V_36 -> V_47 & V_68 ) {
V_42 |= V_69 ;
V_43 |= V_70 ;
}
F_14 ( & V_2 -> V_29 , V_20 ) ;
if ( V_2 -> V_19 . V_20 & V_21 ) {
F_21 ( V_2 -> V_71 , L_1 ) ;
V_43 |= V_72 ;
}
F_22 ( V_2 , V_36 -> V_47 , V_38 ) ;
F_9 ( V_32 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_33 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_73 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_42 , V_2 -> V_3 + V_74 ) ;
F_9 ( V_43 , V_2 -> V_3 + V_74 ) ;
F_9 ( ( V_39 & 0xff00 ) >> 8 , V_2 -> V_3 + V_75 ) ;
F_9 ( ( V_39 & 0xff ) , V_2 -> V_3 + V_76 ) ;
#if F_19 ( V_40 )
F_9 ( ( V_41 & 0x0f ) , V_2 -> V_3 + V_77 ) ;
#endif
F_9 ( V_78 | V_79 ,
V_2 -> V_3 + V_80 ) ;
F_9 ( V_34 | V_22 ,
V_2 -> V_3 + V_23 ) ;
F_15 ( & V_2 -> V_29 , V_20 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
unsigned char V_81 , V_82 , V_83 ;
while ( ( V_81 = F_2 ( V_2 -> V_3 + V_4 ) ) & V_84 ) {
V_82 = F_2 ( V_2 -> V_3 + V_85 ) ;
V_83 = V_86 ;
V_2 -> V_87 . V_88 ++ ;
if ( V_81 & V_89 ) {
F_9 ( V_90 ,
V_2 -> V_3 + V_23 ) ;
if ( V_81 & V_91 ) {
V_2 -> V_87 . V_92 ++ ;
if ( F_24 ( V_2 ) )
continue;
} else if ( V_81 & V_93 ) {
V_2 -> V_87 . V_94 ++ ;
} else if ( V_81 & V_95 ) {
V_2 -> V_87 . V_96 ++ ;
} else if ( V_81 & V_97 ) {
V_2 -> V_87 . V_98 ++ ;
}
V_81 &= V_2 -> V_99 ;
if ( V_81 & V_91 )
V_83 = V_100 ;
else if ( V_81 & V_93 )
V_83 = V_101 ;
else if ( V_81 & V_97 )
V_83 = V_102 ;
}
if ( F_25 ( V_2 , V_82 ) )
continue;
F_26 ( V_2 , V_81 , V_95 , V_82 , V_83 ) ;
}
F_27 ( & V_2 -> V_29 ) ;
F_28 ( & V_2 -> V_103 -> V_2 ) ;
F_29 ( & V_2 -> V_29 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_104 * V_105 = & V_2 -> V_103 -> V_105 ;
if ( V_2 -> V_106 ) {
F_9 ( V_2 -> V_106 , V_2 -> V_3 + V_107 ) ;
V_2 -> V_106 = 0 ;
V_2 -> V_87 . V_108 ++ ;
return;
}
while ( F_2 ( V_2 -> V_3 + V_4 ) & V_109 ) {
if ( V_105 -> V_110 == V_105 -> V_111 )
break;
F_9 ( V_105 -> V_112 [ V_105 -> V_111 ] , V_2 -> V_3 + V_107 ) ;
V_105 -> V_111 = ( V_105 -> V_111 + 1 ) & ( V_113 - 1 ) ;
V_2 -> V_87 . V_108 ++ ;
}
if ( F_31 ( V_105 ) < V_114 )
F_32 ( V_2 ) ;
if ( V_105 -> V_110 == V_105 -> V_111 ) {
V_8 -> V_24 &= ~ V_25 ;
F_9 ( V_8 -> V_24 , V_2 -> V_3 + V_26 ) ;
if ( V_2 -> V_19 . V_20 & V_21 )
F_9 ( V_115 ,
V_2 -> V_3 + V_23 ) ;
}
}
static T_1 F_33 ( int V_116 , void * V_117 )
{
struct V_1 * V_2 = V_117 ;
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned int V_118 ;
T_1 V_119 = V_120 ;
V_118 = F_2 ( V_2 -> V_3 + V_121 ) & V_8 -> V_24 ;
F_29 ( & V_2 -> V_29 ) ;
if ( V_118 & V_27 ) {
F_23 ( V_8 ) ;
V_119 = V_122 ;
}
if ( V_118 & V_25 ) {
F_30 ( V_8 ) ;
V_119 = V_122 ;
}
F_27 ( & V_2 -> V_29 ) ;
return V_119 ;
}
static void F_34 ( struct V_1 * V_2 , int V_20 )
{
V_2 -> type = V_123 ;
V_2 -> V_124 = V_125 ;
F_9 ( 0 , V_2 -> V_3 + V_26 ) ;
if ( F_35 ( V_2 -> V_116 , F_33 , 0 , L_2 , V_2 ) )
F_36 ( V_126 L_3
L_4 , V_2 -> line , V_2 -> V_116 ) ;
}
static const char * F_37 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_123 ) ? L_5 : NULL ;
}
static int F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
}
static int F_40 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
if ( ( V_128 -> type != V_129 ) && ( V_128 -> type != V_123 ) )
return - V_130 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_131 * V_19 )
{
unsigned char V_42 , V_43 ;
V_42 = F_2 ( V_2 -> V_3 + V_74 ) ;
V_43 = F_2 ( V_2 -> V_3 + V_74 ) ;
if ( V_19 -> V_20 & V_21 ) {
F_21 ( V_2 -> V_71 , L_1 ) ;
V_43 |= V_72 ;
} else {
F_21 ( V_2 -> V_71 , L_6 ) ;
V_43 &= ~ V_72 ;
}
F_9 ( V_42 , V_2 -> V_3 + V_74 ) ;
F_9 ( V_43 , V_2 -> V_3 + V_74 ) ;
V_2 -> V_19 = * V_19 ;
return 0 ;
}
int T_2 F_42 ( struct V_132 * V_133 )
{
struct V_1 * V_2 ;
int V_134 ;
for ( V_134 = 0 ; ( ( V_134 < V_135 ) && ( V_133 [ V_134 ] . V_136 ) ) ; V_134 ++ ) {
V_2 = & V_137 [ V_134 ] . V_2 ;
V_2 -> line = V_134 ;
V_2 -> type = V_123 ;
V_2 -> V_136 = V_133 [ V_134 ] . V_136 ;
V_2 -> V_3 = ( V_133 [ V_134 ] . V_3 ) ? V_133 [ V_134 ] . V_3 :
( unsigned char V_138 * ) V_2 -> V_136 ;
V_2 -> V_139 = V_140 ;
V_2 -> V_116 = V_133 [ V_134 ] . V_116 ;
V_2 -> V_141 = V_44 ;
V_2 -> V_20 = V_142 ;
V_2 -> V_143 = F_41 ;
V_2 -> V_144 = & V_145 ;
}
return 0 ;
}
static void F_43 ( struct V_146 * V_147 , const char V_148 )
{
struct V_1 * V_2 = & ( V_137 + V_147 -> V_149 ) -> V_2 ;
int V_134 ;
for ( V_134 = 0 ; ( V_134 < 0x10000 ) ; V_134 ++ ) {
if ( F_2 ( V_2 -> V_3 + V_4 ) & V_109 )
break;
}
F_9 ( V_148 , V_2 -> V_3 + V_107 ) ;
for ( V_134 = 0 ; ( V_134 < 0x10000 ) ; V_134 ++ ) {
if ( F_2 ( V_2 -> V_3 + V_4 ) & V_109 )
break;
}
}
static void F_44 ( struct V_146 * V_147 , const char * V_150 , unsigned int V_151 )
{
for (; ( V_151 ) ; V_151 -- , V_150 ++ ) {
F_43 ( V_147 , * V_150 ) ;
if ( * V_150 == '\n' )
F_43 ( V_147 , '\r' ) ;
}
}
static int T_2 F_45 ( struct V_146 * V_147 , char * V_152 )
{
struct V_1 * V_2 ;
int V_38 = V_153 ;
int V_154 = 8 ;
int V_94 = 'n' ;
int V_155 = 'n' ;
if ( ( V_147 -> V_149 < 0 ) || ( V_147 -> V_149 >= V_135 ) )
V_147 -> V_149 = 0 ;
V_2 = & V_137 [ V_147 -> V_149 ] . V_2 ;
if ( V_2 -> V_3 == 0 )
return - V_156 ;
if ( V_152 )
F_46 ( V_152 , & V_38 , & V_94 , & V_154 , & V_155 ) ;
return F_47 ( V_2 , V_147 , V_38 , V_94 , V_154 , V_155 ) ;
}
static int T_2 F_48 ( void )
{
F_49 ( & V_157 ) ;
return 0 ;
}
static int F_50 ( struct V_158 * V_159 )
{
struct V_132 * V_133 = F_51 ( & V_159 -> V_71 ) ;
struct V_1 * V_2 ;
int V_134 ;
for ( V_134 = 0 ; ( ( V_134 < V_135 ) && ( V_133 [ V_134 ] . V_136 ) ) ; V_134 ++ ) {
V_2 = & V_137 [ V_134 ] . V_2 ;
V_2 -> line = V_134 ;
V_2 -> type = V_123 ;
V_2 -> V_136 = V_133 [ V_134 ] . V_136 ;
V_2 -> V_3 = ( V_133 [ V_134 ] . V_3 ) ? V_133 [ V_134 ] . V_3 :
( unsigned char V_138 * ) V_133 [ V_134 ] . V_136 ;
V_2 -> V_71 = & V_159 -> V_71 ;
V_2 -> V_139 = V_140 ;
V_2 -> V_116 = V_133 [ V_134 ] . V_116 ;
V_2 -> V_141 = V_44 ;
V_2 -> V_144 = & V_145 ;
V_2 -> V_20 = V_142 ;
V_2 -> V_143 = F_41 ;
F_52 ( & V_160 , V_2 ) ;
}
return 0 ;
}
static int F_53 ( struct V_158 * V_159 )
{
struct V_1 * V_2 ;
int V_134 ;
for ( V_134 = 0 ; ( V_134 < V_135 ) ; V_134 ++ ) {
V_2 = & V_137 [ V_134 ] . V_2 ;
if ( V_2 )
F_54 ( & V_160 , V_2 ) ;
}
return 0 ;
}
static int T_2 F_55 ( void )
{
int V_161 ;
F_36 ( L_7 ) ;
V_161 = F_56 ( & V_160 ) ;
if ( V_161 )
return V_161 ;
V_161 = F_57 ( & V_162 ) ;
if ( V_161 ) {
F_58 ( & V_160 ) ;
return V_161 ;
}
return 0 ;
}
static void T_3 F_59 ( void )
{
F_60 ( & V_162 ) ;
F_58 ( & V_160 ) ;
}
