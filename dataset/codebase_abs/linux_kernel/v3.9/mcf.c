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
if ( V_8 -> V_19 . V_20 & V_21 ) {
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
static void F_16 ( struct V_1 * V_2 )
{
}
static int F_17 ( struct V_1 * V_2 )
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
static void F_18 ( struct V_1 * V_2 )
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
static void F_19 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_35 * V_37 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned long V_20 ;
unsigned int V_38 , V_39 ;
#if F_20 ( V_40 )
unsigned int V_41 ;
#endif
unsigned char V_42 , V_43 ;
V_38 = F_21 ( V_2 , V_36 , V_37 , 0 , 230400 ) ;
#if F_20 ( V_40 )
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
if ( V_8 -> V_19 . V_20 & V_21 ) {
F_22 ( V_2 -> V_71 , L_1 ) ;
V_43 |= V_72 ;
}
F_14 ( & V_2 -> V_29 , V_20 ) ;
F_23 ( V_2 , V_36 -> V_47 , V_38 ) ;
F_9 ( V_32 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_33 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_73 , V_2 -> V_3 + V_23 ) ;
F_9 ( V_42 , V_2 -> V_3 + V_74 ) ;
F_9 ( V_43 , V_2 -> V_3 + V_74 ) ;
F_9 ( ( V_39 & 0xff00 ) >> 8 , V_2 -> V_3 + V_75 ) ;
F_9 ( ( V_39 & 0xff ) , V_2 -> V_3 + V_76 ) ;
#if F_20 ( V_40 )
F_9 ( ( V_41 & 0x0f ) , V_2 -> V_3 + V_77 ) ;
#endif
F_9 ( V_78 | V_79 ,
V_2 -> V_3 + V_80 ) ;
F_9 ( V_34 | V_22 ,
V_2 -> V_3 + V_23 ) ;
F_15 ( & V_2 -> V_29 , V_20 ) ;
}
static void F_24 ( struct V_7 * V_8 )
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
if ( F_25 ( V_2 ) )
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
if ( F_26 ( V_2 , V_82 ) )
continue;
F_27 ( V_2 , V_81 , V_95 , V_82 , V_83 ) ;
}
F_28 ( & V_2 -> V_103 -> V_2 ) ;
}
static void F_29 ( struct V_7 * V_8 )
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
if ( F_30 ( V_105 ) < V_114 )
F_31 ( V_2 ) ;
if ( V_105 -> V_110 == V_105 -> V_111 ) {
V_8 -> V_24 &= ~ V_25 ;
F_9 ( V_8 -> V_24 , V_2 -> V_3 + V_26 ) ;
if ( V_8 -> V_19 . V_20 & V_21 )
F_9 ( V_115 ,
V_2 -> V_3 + V_23 ) ;
}
}
static T_1 F_32 ( int V_116 , void * V_117 )
{
struct V_1 * V_2 = V_117 ;
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned int V_118 ;
T_1 V_119 = V_120 ;
V_118 = F_2 ( V_2 -> V_3 + V_121 ) & V_8 -> V_24 ;
F_33 ( & V_2 -> V_29 ) ;
if ( V_118 & V_27 ) {
F_24 ( V_8 ) ;
V_119 = V_122 ;
}
if ( V_118 & V_25 ) {
F_29 ( V_8 ) ;
V_119 = V_122 ;
}
F_34 ( & V_2 -> V_29 ) ;
return V_119 ;
}
static void F_35 ( struct V_1 * V_2 , int V_20 )
{
V_2 -> type = V_123 ;
V_2 -> V_124 = V_125 ;
F_9 ( 0 , V_2 -> V_3 + V_26 ) ;
if ( F_36 ( V_2 -> V_116 , F_32 , 0 , L_2 , V_2 ) )
F_37 ( V_126 L_3
L_4 , V_2 -> line , V_2 -> V_116 ) ;
}
static const char * F_38 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_123 ) ? L_5 : NULL ;
}
static int F_39 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
}
static int F_41 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
if ( ( V_128 -> type != V_129 ) && ( V_128 -> type != V_123 ) )
return - V_130 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_131 * V_19 )
{
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
unsigned long V_20 ;
unsigned char V_42 , V_43 ;
F_14 ( & V_2 -> V_29 , V_20 ) ;
V_42 = F_2 ( V_2 -> V_3 + V_74 ) ;
V_43 = F_2 ( V_2 -> V_3 + V_74 ) ;
if ( V_19 -> V_20 & V_21 ) {
F_22 ( V_2 -> V_71 , L_1 ) ;
V_43 |= V_72 ;
} else {
F_22 ( V_2 -> V_71 , L_6 ) ;
V_43 &= ~ V_72 ;
}
F_9 ( V_42 , V_2 -> V_3 + V_74 ) ;
F_9 ( V_43 , V_2 -> V_3 + V_74 ) ;
V_8 -> V_19 = * V_19 ;
F_15 ( & V_2 -> V_29 , V_20 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned int V_132 ,
unsigned long V_133 )
{
switch ( V_132 ) {
case V_134 : {
struct V_131 V_19 ;
if ( F_44 ( & V_19 , (struct V_131 * ) V_133 ,
sizeof( struct V_131 ) ) )
return - V_135 ;
F_42 ( V_2 , & V_19 ) ;
break;
}
case V_136 : {
struct V_7 * V_8 = F_4 ( V_2 , struct V_7 , V_2 ) ;
if ( F_45 ( (struct V_131 * ) V_133 , & V_8 -> V_19 ,
sizeof( struct V_131 ) ) )
return - V_135 ;
break;
}
default:
return - V_137 ;
}
return 0 ;
}
int T_2 F_46 ( struct V_138 * V_139 )
{
struct V_1 * V_2 ;
int V_140 ;
for ( V_140 = 0 ; ( ( V_140 < V_141 ) && ( V_139 [ V_140 ] . V_142 ) ) ; V_140 ++ ) {
V_2 = & V_143 [ V_140 ] . V_2 ;
V_2 -> line = V_140 ;
V_2 -> type = V_123 ;
V_2 -> V_142 = V_139 [ V_140 ] . V_142 ;
V_2 -> V_3 = ( V_139 [ V_140 ] . V_3 ) ? V_139 [ V_140 ] . V_3 :
( unsigned char V_144 * ) V_2 -> V_142 ;
V_2 -> V_145 = V_146 ;
V_2 -> V_116 = V_139 [ V_140 ] . V_116 ;
V_2 -> V_147 = V_44 ;
V_2 -> V_20 = V_148 ;
V_2 -> V_149 = & V_150 ;
}
return 0 ;
}
static void F_47 ( struct V_151 * V_152 , const char V_153 )
{
struct V_1 * V_2 = & ( V_143 + V_152 -> V_154 ) -> V_2 ;
int V_140 ;
for ( V_140 = 0 ; ( V_140 < 0x10000 ) ; V_140 ++ ) {
if ( F_2 ( V_2 -> V_3 + V_4 ) & V_109 )
break;
}
F_9 ( V_153 , V_2 -> V_3 + V_107 ) ;
for ( V_140 = 0 ; ( V_140 < 0x10000 ) ; V_140 ++ ) {
if ( F_2 ( V_2 -> V_3 + V_4 ) & V_109 )
break;
}
}
static void F_48 ( struct V_151 * V_152 , const char * V_155 , unsigned int V_156 )
{
for (; ( V_156 ) ; V_156 -- , V_155 ++ ) {
F_47 ( V_152 , * V_155 ) ;
if ( * V_155 == '\n' )
F_47 ( V_152 , '\r' ) ;
}
}
static int T_2 F_49 ( struct V_151 * V_152 , char * V_157 )
{
struct V_1 * V_2 ;
int V_38 = V_158 ;
int V_159 = 8 ;
int V_94 = 'n' ;
int V_160 = 'n' ;
if ( ( V_152 -> V_154 < 0 ) || ( V_152 -> V_154 >= V_141 ) )
V_152 -> V_154 = 0 ;
V_2 = & V_143 [ V_152 -> V_154 ] . V_2 ;
if ( V_2 -> V_3 == 0 )
return - V_161 ;
if ( V_157 )
F_50 ( V_157 , & V_38 , & V_94 , & V_159 , & V_160 ) ;
return F_51 ( V_2 , V_152 , V_38 , V_94 , V_159 , V_160 ) ;
}
static int T_2 F_52 ( void )
{
F_53 ( & V_162 ) ;
return 0 ;
}
static int F_54 ( struct V_163 * V_164 )
{
struct V_138 * V_139 = V_164 -> V_71 . V_165 ;
struct V_1 * V_2 ;
int V_140 ;
for ( V_140 = 0 ; ( ( V_140 < V_141 ) && ( V_139 [ V_140 ] . V_142 ) ) ; V_140 ++ ) {
V_2 = & V_143 [ V_140 ] . V_2 ;
V_2 -> line = V_140 ;
V_2 -> type = V_123 ;
V_2 -> V_142 = V_139 [ V_140 ] . V_142 ;
V_2 -> V_3 = ( V_139 [ V_140 ] . V_3 ) ? V_139 [ V_140 ] . V_3 :
( unsigned char V_144 * ) V_139 [ V_140 ] . V_142 ;
V_2 -> V_145 = V_146 ;
V_2 -> V_116 = V_139 [ V_140 ] . V_116 ;
V_2 -> V_147 = V_44 ;
V_2 -> V_149 = & V_150 ;
V_2 -> V_20 = V_148 ;
F_55 ( & V_166 , V_2 ) ;
}
return 0 ;
}
static int F_56 ( struct V_163 * V_164 )
{
struct V_1 * V_2 ;
int V_140 ;
for ( V_140 = 0 ; ( V_140 < V_141 ) ; V_140 ++ ) {
V_2 = & V_143 [ V_140 ] . V_2 ;
if ( V_2 )
F_57 ( & V_166 , V_2 ) ;
}
return 0 ;
}
static int T_2 F_58 ( void )
{
int V_167 ;
F_37 ( L_7 ) ;
V_167 = F_59 ( & V_166 ) ;
if ( V_167 )
return V_167 ;
V_167 = F_60 ( & V_168 ) ;
if ( V_167 )
return V_167 ;
return 0 ;
}
static void T_3 F_61 ( void )
{
F_62 ( & V_168 ) ;
F_63 ( & V_166 ) ;
}
