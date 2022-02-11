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
V_8 -> V_19 |= V_20 ;
F_9 ( V_8 -> V_19 , V_2 -> V_3 + V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
V_8 -> V_19 &= ~ V_20 ;
F_9 ( V_8 -> V_19 , V_2 -> V_3 + V_21 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
V_8 -> V_19 &= ~ V_22 ;
F_9 ( V_8 -> V_19 , V_2 -> V_3 + V_21 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_23 )
{
unsigned long V_24 ;
F_14 ( & V_2 -> V_25 , V_24 ) ;
if ( V_23 == - 1 )
F_9 ( V_26 , V_2 -> V_3 + V_27 ) ;
else
F_9 ( V_28 , V_2 -> V_3 + V_27 ) ;
F_15 ( & V_2 -> V_25 , V_24 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned long V_24 ;
F_14 ( & V_2 -> V_25 , V_24 ) ;
F_9 ( V_29 , V_2 -> V_3 + V_27 ) ;
F_9 ( V_30 , V_2 -> V_3 + V_27 ) ;
F_9 ( V_31 | V_32 ,
V_2 -> V_3 + V_27 ) ;
V_8 -> V_19 = V_22 ;
F_9 ( V_8 -> V_19 , V_2 -> V_3 + V_21 ) ;
F_15 ( & V_2 -> V_25 , V_24 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned long V_24 ;
F_14 ( & V_2 -> V_25 , V_24 ) ;
V_8 -> V_19 = 0 ;
F_9 ( V_8 -> V_19 , V_2 -> V_3 + V_21 ) ;
F_9 ( V_29 , V_2 -> V_3 + V_27 ) ;
F_9 ( V_30 , V_2 -> V_3 + V_27 ) ;
F_15 ( & V_2 -> V_25 , V_24 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_33 * V_35 )
{
unsigned long V_24 ;
unsigned int V_36 , V_37 ;
#if F_20 ( V_38 )
unsigned int V_39 ;
#endif
unsigned char V_40 , V_41 ;
V_36 = F_21 ( V_2 , V_34 , V_35 , 0 , 230400 ) ;
#if F_20 ( V_38 )
V_37 = ( V_42 / V_36 ) / 32 ;
V_39 = ( ( ( V_42 / V_36 ) + 1 ) / 2 ) % 16 ;
#else
V_37 = ( ( V_42 / V_36 ) + 16 ) / 32 ;
#endif
V_40 = V_43 | V_44 ;
V_41 = 0 ;
switch ( V_34 -> V_45 & V_46 ) {
case V_47 : V_40 |= V_48 ; break;
case V_49 : V_40 |= V_50 ; break;
case V_51 : V_40 |= V_52 ; break;
case V_53 :
default: V_40 |= V_54 ; break;
}
if ( V_34 -> V_45 & V_55 ) {
if ( V_34 -> V_45 & V_56 ) {
if ( V_34 -> V_45 & V_57 )
V_40 |= V_58 ;
else
V_40 |= V_59 ;
} else {
if ( V_34 -> V_45 & V_57 )
V_40 |= V_60 ;
else
V_40 |= V_61 ;
}
} else {
V_40 |= V_62 ;
}
if ( V_34 -> V_45 & V_63 )
V_41 |= V_64 ;
else
V_41 |= V_65 ;
if ( V_34 -> V_45 & V_66 ) {
V_40 |= V_67 ;
V_41 |= V_68 ;
}
F_14 ( & V_2 -> V_25 , V_24 ) ;
F_22 ( V_2 , V_34 -> V_45 , V_36 ) ;
F_9 ( V_29 , V_2 -> V_3 + V_27 ) ;
F_9 ( V_30 , V_2 -> V_3 + V_27 ) ;
F_9 ( V_69 , V_2 -> V_3 + V_27 ) ;
F_9 ( V_40 , V_2 -> V_3 + V_70 ) ;
F_9 ( V_41 , V_2 -> V_3 + V_70 ) ;
F_9 ( ( V_37 & 0xff00 ) >> 8 , V_2 -> V_3 + V_71 ) ;
F_9 ( ( V_37 & 0xff ) , V_2 -> V_3 + V_72 ) ;
#if F_20 ( V_38 )
F_9 ( ( V_39 & 0x0f ) , V_2 -> V_3 + V_73 ) ;
#endif
F_9 ( V_74 | V_75 ,
V_2 -> V_3 + V_76 ) ;
F_9 ( V_31 | V_32 ,
V_2 -> V_3 + V_27 ) ;
F_15 ( & V_2 -> V_25 , V_24 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
unsigned char V_77 , V_78 , V_79 ;
while ( ( V_77 = F_2 ( V_2 -> V_3 + V_4 ) ) & V_80 ) {
V_78 = F_2 ( V_2 -> V_3 + V_81 ) ;
V_79 = V_82 ;
V_2 -> V_83 . V_84 ++ ;
if ( V_77 & V_85 ) {
F_9 ( V_86 ,
V_2 -> V_3 + V_27 ) ;
if ( V_77 & V_87 ) {
V_2 -> V_83 . V_88 ++ ;
if ( F_24 ( V_2 ) )
continue;
} else if ( V_77 & V_89 ) {
V_2 -> V_83 . V_90 ++ ;
} else if ( V_77 & V_91 ) {
V_2 -> V_83 . V_92 ++ ;
} else if ( V_77 & V_93 ) {
V_2 -> V_83 . V_94 ++ ;
}
V_77 &= V_2 -> V_95 ;
if ( V_77 & V_87 )
V_79 = V_96 ;
else if ( V_77 & V_89 )
V_79 = V_97 ;
else if ( V_77 & V_93 )
V_79 = V_98 ;
}
if ( F_25 ( V_2 , V_78 ) )
continue;
F_26 ( V_2 , V_77 , V_91 , V_78 , V_79 ) ;
}
F_27 ( V_2 -> V_99 -> V_2 . V_100 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_101 * V_102 = & V_2 -> V_99 -> V_102 ;
if ( V_2 -> V_103 ) {
F_9 ( V_2 -> V_103 , V_2 -> V_3 + V_104 ) ;
V_2 -> V_103 = 0 ;
V_2 -> V_83 . V_105 ++ ;
return;
}
while ( F_2 ( V_2 -> V_3 + V_4 ) & V_106 ) {
if ( V_102 -> V_107 == V_102 -> V_108 )
break;
F_9 ( V_102 -> V_109 [ V_102 -> V_108 ] , V_2 -> V_3 + V_104 ) ;
V_102 -> V_108 = ( V_102 -> V_108 + 1 ) & ( V_110 - 1 ) ;
V_2 -> V_83 . V_105 ++ ;
}
if ( F_29 ( V_102 ) < V_111 )
F_30 ( V_2 ) ;
if ( V_102 -> V_107 == V_102 -> V_108 ) {
V_8 -> V_19 &= ~ V_20 ;
F_9 ( V_8 -> V_19 , V_2 -> V_3 + V_21 ) ;
}
}
static T_1 F_31 ( int V_112 , void * V_113 )
{
struct V_1 * V_2 = V_113 ;
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned int V_114 ;
T_1 V_115 = V_116 ;
V_114 = F_2 ( V_2 -> V_3 + V_117 ) & V_8 -> V_19 ;
F_32 ( & V_2 -> V_25 ) ;
if ( V_114 & V_22 ) {
F_23 ( V_8 ) ;
V_115 = V_118 ;
}
if ( V_114 & V_20 ) {
F_28 ( V_8 ) ;
V_115 = V_118 ;
}
F_33 ( & V_2 -> V_25 ) ;
return V_115 ;
}
static void F_34 ( struct V_1 * V_2 , int V_24 )
{
V_2 -> type = V_119 ;
V_2 -> V_120 = V_121 ;
F_9 ( 0 , V_2 -> V_3 + V_21 ) ;
if ( F_35 ( V_2 -> V_112 , F_31 , 0 , L_1 , V_2 ) )
F_36 ( V_122 L_2
L_3 , V_2 -> line , V_2 -> V_112 ) ;
}
static const char * F_37 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_119 ) ? L_4 : NULL ;
}
static int F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
}
static int F_40 ( struct V_1 * V_2 , struct V_123 * V_124 )
{
if ( ( V_124 -> type != V_125 ) && ( V_124 -> type != V_119 ) )
return - V_126 ;
return 0 ;
}
int T_2 F_41 ( struct V_127 * V_128 )
{
struct V_1 * V_2 ;
int V_129 ;
for ( V_129 = 0 ; ( ( V_129 < V_130 ) && ( V_128 [ V_129 ] . V_131 ) ) ; V_129 ++ ) {
V_2 = & V_132 [ V_129 ] . V_2 ;
V_2 -> line = V_129 ;
V_2 -> type = V_119 ;
V_2 -> V_131 = V_128 [ V_129 ] . V_131 ;
V_2 -> V_3 = ( V_128 [ V_129 ] . V_3 ) ? V_128 [ V_129 ] . V_3 :
( unsigned char V_133 * ) V_2 -> V_131 ;
V_2 -> V_134 = V_135 ;
V_2 -> V_112 = V_128 [ V_129 ] . V_112 ;
V_2 -> V_136 = V_42 ;
V_2 -> V_24 = V_137 ;
V_2 -> V_138 = & V_139 ;
}
return 0 ;
}
static void F_42 ( struct V_140 * V_141 , const char V_142 )
{
struct V_1 * V_2 = & ( V_132 + V_141 -> V_143 ) -> V_2 ;
int V_129 ;
for ( V_129 = 0 ; ( V_129 < 0x10000 ) ; V_129 ++ ) {
if ( F_2 ( V_2 -> V_3 + V_4 ) & V_106 )
break;
}
F_9 ( V_142 , V_2 -> V_3 + V_104 ) ;
for ( V_129 = 0 ; ( V_129 < 0x10000 ) ; V_129 ++ ) {
if ( F_2 ( V_2 -> V_3 + V_4 ) & V_106 )
break;
}
}
static void F_43 ( struct V_140 * V_141 , const char * V_144 , unsigned int V_145 )
{
for (; ( V_145 ) ; V_145 -- , V_144 ++ ) {
F_42 ( V_141 , * V_144 ) ;
if ( * V_144 == '\n' )
F_42 ( V_141 , '\r' ) ;
}
}
static int T_2 F_44 ( struct V_140 * V_141 , char * V_146 )
{
struct V_1 * V_2 ;
int V_36 = V_147 ;
int V_148 = 8 ;
int V_90 = 'n' ;
int V_149 = 'n' ;
if ( ( V_141 -> V_143 < 0 ) || ( V_141 -> V_143 >= V_130 ) )
V_141 -> V_143 = 0 ;
V_2 = & V_132 [ V_141 -> V_143 ] . V_2 ;
if ( V_2 -> V_3 == 0 )
return - V_150 ;
if ( V_146 )
F_45 ( V_146 , & V_36 , & V_90 , & V_148 , & V_149 ) ;
return F_46 ( V_2 , V_141 , V_36 , V_90 , V_148 , V_149 ) ;
}
static int T_2 F_47 ( void )
{
F_48 ( & V_151 ) ;
return 0 ;
}
static int T_3 F_49 ( struct V_152 * V_153 )
{
struct V_127 * V_128 = V_153 -> V_154 . V_155 ;
struct V_1 * V_2 ;
int V_129 ;
for ( V_129 = 0 ; ( ( V_129 < V_130 ) && ( V_128 [ V_129 ] . V_131 ) ) ; V_129 ++ ) {
V_2 = & V_132 [ V_129 ] . V_2 ;
V_2 -> line = V_129 ;
V_2 -> type = V_119 ;
V_2 -> V_131 = V_128 [ V_129 ] . V_131 ;
V_2 -> V_3 = ( V_128 [ V_129 ] . V_3 ) ? V_128 [ V_129 ] . V_3 :
( unsigned char V_133 * ) V_128 [ V_129 ] . V_131 ;
V_2 -> V_134 = V_135 ;
V_2 -> V_112 = V_128 [ V_129 ] . V_112 ;
V_2 -> V_136 = V_42 ;
V_2 -> V_138 = & V_139 ;
V_2 -> V_24 = V_137 ;
F_50 ( & V_156 , V_2 ) ;
}
return 0 ;
}
static int T_4 F_51 ( struct V_152 * V_153 )
{
struct V_1 * V_2 ;
int V_129 ;
for ( V_129 = 0 ; ( V_129 < V_130 ) ; V_129 ++ ) {
V_2 = & V_132 [ V_129 ] . V_2 ;
if ( V_2 )
F_52 ( & V_156 , V_2 ) ;
}
return 0 ;
}
static int T_2 F_53 ( void )
{
int V_157 ;
F_36 ( L_5 ) ;
V_157 = F_54 ( & V_156 ) ;
if ( V_157 )
return V_157 ;
V_157 = F_55 ( & V_158 ) ;
if ( V_157 )
return V_157 ;
return 0 ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_158 ) ;
F_58 ( & V_156 ) ;
}
