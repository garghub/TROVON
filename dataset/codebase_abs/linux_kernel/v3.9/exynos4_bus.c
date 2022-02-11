static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
unsigned int V_6 ;
for ( V_5 = V_7 ; V_5 < V_8 ; V_5 ++ )
if ( V_4 -> V_9 == V_10 [ V_5 ] . V_11 )
break;
if ( V_5 == V_8 )
return - V_12 ;
V_6 = V_2 -> V_13 [ V_5 ] ;
F_2 ( V_6 , V_14 ) ;
do {
V_6 = F_3 ( V_15 ) ;
} while ( V_6 & 0x11111111 );
V_6 = V_2 -> V_16 [ V_5 ] ;
F_2 ( V_6 , V_17 ) ;
do {
V_6 = F_3 ( V_18 ) ;
} while ( V_6 & 0x11111 );
V_6 = F_3 ( V_19 ) ;
V_6 &= ~ ( V_20 | V_21 ) ;
V_6 |= ( ( V_22 [ V_5 ] [ 0 ] <<
V_23 ) |
( V_22 [ V_5 ] [ 1 ] <<
V_24 ) ) ;
F_2 ( V_6 , V_19 ) ;
do {
V_6 = F_3 ( V_25 ) ;
} while ( V_6 & 0x11 );
V_6 = F_3 ( V_26 ) ;
V_6 &= ~ ( V_20 | V_21 ) ;
V_6 |= ( ( V_22 [ V_5 ] [ 0 ] <<
V_23 ) |
( V_22 [ V_5 ] [ 1 ] <<
V_24 ) ) ;
F_2 ( V_6 , V_26 ) ;
do {
V_6 = F_3 ( V_27 ) ;
} while ( V_6 & 0x11 );
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
unsigned int V_6 ;
for ( V_5 = V_7 ; V_5 < V_28 ; V_5 ++ )
if ( V_4 -> V_9 == V_29 [ V_5 ] . V_11 )
break;
if ( V_5 == V_28 )
return - V_12 ;
V_6 = V_2 -> V_13 [ V_5 ] ;
F_2 ( V_6 , V_14 ) ;
do {
V_6 = F_3 ( V_15 ) ;
} while ( V_6 & 0x11111111 );
V_6 = F_3 ( V_30 ) ;
V_6 &= ~ ( V_31 |
V_32 |
V_33 ) ;
V_6 |= ( ( V_34 [ V_5 ] [ 0 ] <<
V_35 ) |
( V_34 [ V_5 ] [ 1 ] <<
V_36 ) |
( V_34 [ V_5 ] [ 2 ] <<
V_37 ) ) ;
F_2 ( V_6 , V_30 ) ;
do {
V_6 = F_3 ( V_38 ) ;
} while ( V_6 & 0x111111 );
V_6 = F_3 ( V_17 ) ;
V_6 &= ~ ( V_39 |
V_40 |
V_41 |
V_42 |
V_43 ) ;
V_6 |= ( ( V_44 [ V_5 ] [ 0 ] <<
V_45 ) |
( V_44 [ V_5 ] [ 1 ] <<
V_46 ) |
( V_44 [ V_5 ] [ 2 ] <<
V_47 ) |
( V_44 [ V_5 ] [ 3 ] <<
V_48 ) |
( V_44 [ V_5 ] [ 4 ] <<
V_49 ) ) ;
F_2 ( V_6 , V_17 ) ;
do {
V_6 = F_3 ( V_18 ) ;
} while ( V_6 & 0x11111 );
V_6 = F_3 ( V_19 ) ;
V_6 &= ~ ( V_20 | V_21 ) ;
V_6 |= ( ( V_50 [ V_5 ] [ 0 ] <<
V_23 ) |
( V_50 [ V_5 ] [ 1 ] <<
V_24 ) ) ;
F_2 ( V_6 , V_19 ) ;
do {
V_6 = F_3 ( V_25 ) ;
} while ( V_6 & 0x11 );
V_6 = F_3 ( V_26 ) ;
V_6 &= ~ ( V_20 | V_21 ) ;
V_6 |= ( ( V_50 [ V_5 ] [ 0 ] <<
V_23 ) |
( V_50 [ V_5 ] [ 1 ] <<
V_24 ) ) ;
F_2 ( V_6 , V_26 ) ;
do {
V_6 = F_3 ( V_27 ) ;
} while ( V_6 & 0x11 );
V_6 = F_3 ( V_51 ) ;
V_6 &= ~ ( V_52 ) ;
V_6 |= ( ( V_53 [ V_5 ] [ 0 ] <<
V_54 ) ) ;
F_2 ( V_6 , V_51 ) ;
do {
V_6 = F_3 ( V_55 ) ;
} while ( V_6 & 0x1 );
V_6 = F_3 ( V_56 ) ;
V_6 &= ~ ( V_57 ) ;
V_6 |= ( ( V_53 [ V_5 ] [ 1 ] <<
V_58 ) ) ;
F_2 ( V_6 , V_56 ) ;
do {
V_6 = F_3 ( V_59 ) ;
} while ( V_6 & 0x1 );
V_6 = F_3 ( V_60 ) ;
V_6 &= ~ ( V_61 | V_62 |
V_63 | V_64 ) ;
V_6 |= ( ( V_53 [ V_5 ] [ 2 ] <<
V_65 ) |
( V_53 [ V_5 ] [ 2 ] <<
V_66 ) |
( V_53 [ V_5 ] [ 2 ] <<
V_67 ) |
( V_53 [ V_5 ] [ 2 ] <<
V_68 ) ) ;
F_2 ( V_6 , V_60 ) ;
do {
V_6 = F_3 ( V_59 ) ;
} while ( V_6 & 0x1111 );
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 < 2 ; V_69 ++ ) {
void T_1 * V_70 = V_2 -> V_71 [ V_69 ] . V_72 ;
F_2 ( 0x8000000f , V_70 + 0xf010 ) ;
F_2 ( 0x8000000f , V_70 + 0xf050 ) ;
F_2 ( 0x6 , V_70 + 0xf000 ) ;
F_2 ( 0x0 , V_70 + 0xf100 ) ;
V_2 -> V_71 [ V_69 ] . V_73 = 0x6 ;
F_2 ( ( ( V_2 -> V_71 [ V_69 ] . V_73 << 12 ) | 0x1 ) ,
V_70 + 0xfc ) ;
F_2 ( 0x1 , V_70 + 0xf000 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
int V_69 , V_74 ;
for ( V_69 = 0 ; V_69 < 2 ; V_69 ++ ) {
void T_1 * V_70 = V_2 -> V_71 [ V_69 ] . V_72 ;
T_2 V_75 ;
F_2 ( 0x0 , V_70 + 0xf000 ) ;
V_75 = F_3 ( V_70 + 0xf050 ) ;
V_2 -> V_71 [ V_69 ] . V_76 = F_3 ( V_70 + 0xf100 ) ;
V_2 -> V_71 [ V_69 ] . V_77 = V_75 & ( 1 << 31 ) ;
for ( V_74 = 0 ; V_74 < V_78 ; V_74 ++ ) {
V_2 -> V_71 [ V_69 ] . V_79 [ V_74 ] = F_3 (
V_70 + ( 0xf110 + ( 0x10 * V_74 ) ) ) ;
V_2 -> V_71 [ V_69 ] . V_80 [ V_74 ] = V_75 & ( 1 << V_74 ) ;
}
}
F_5 ( V_2 ) ;
}
static int F_7 ( unsigned long V_81 )
{
int V_69 = 0 ;
while ( V_82 [ V_69 ] . V_11 ) {
if ( V_82 [ V_69 ] . V_11 <= V_81 )
return V_69 ;
V_69 ++ ;
}
return - V_12 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_83 )
{
int V_84 = 0 , V_6 ;
unsigned long V_85 = V_4 -> V_85 ;
switch ( V_2 -> type ) {
case V_86 :
V_84 = F_9 ( V_2 -> V_87 , V_85 ,
V_88 ) ;
break;
case V_89 :
V_84 = F_9 ( V_2 -> V_90 , V_85 ,
V_88 ) ;
if ( V_84 )
break;
V_6 = F_7 ( V_4 -> V_9 ) ;
if ( V_6 < 0 ) {
V_84 = V_6 ;
F_9 ( V_2 -> V_90 ,
V_83 -> V_85 ,
V_88 ) ;
break;
}
V_84 = F_9 ( V_2 -> V_87 ,
V_82 [ V_6 ] . V_85 ,
V_88 ) ;
if ( V_84 )
F_9 ( V_2 -> V_90 ,
V_83 -> V_85 ,
V_88 ) ;
break;
default:
V_84 = - V_12 ;
}
return V_84 ;
}
static int F_10 ( struct V_91 * V_92 , unsigned long * V_93 ,
T_2 V_94 )
{
int V_84 = 0 ;
struct V_95 * V_96 = F_11 ( V_92 , struct V_95 ,
V_92 ) ;
struct V_1 * V_2 = F_12 ( V_96 ) ;
struct V_97 * V_97 ;
unsigned long V_98 ;
unsigned long V_99 = V_2 -> V_100 . V_9 ;
struct V_3 V_101 ;
F_13 () ;
V_97 = F_14 ( V_92 , V_93 , V_94 ) ;
if ( F_15 ( V_97 ) ) {
F_16 () ;
return F_17 ( V_97 ) ;
}
V_101 . V_9 = F_18 ( V_97 ) ;
V_101 . V_85 = F_19 ( V_97 ) ;
F_16 () ;
V_98 = V_101 . V_9 ;
if ( V_99 == V_98 )
return 0 ;
F_20 ( V_92 , L_1 , V_98 , V_101 . V_85 ) ;
F_21 ( & V_2 -> V_102 ) ;
if ( V_2 -> V_103 )
goto V_104;
if ( V_99 < V_98 )
V_84 = F_8 ( V_2 , & V_101 ,
& V_2 -> V_100 ) ;
if ( V_84 )
goto V_104;
if ( V_99 != V_98 ) {
switch ( V_2 -> type ) {
case V_86 :
V_84 = F_1 ( V_2 , & V_101 ) ;
break;
case V_89 :
V_84 = F_4 ( V_2 , & V_101 ) ;
break;
default:
V_84 = - V_12 ;
}
}
if ( V_84 )
goto V_104;
if ( V_99 > V_98 )
V_84 = F_8 ( V_2 , & V_101 ,
& V_2 -> V_100 ) ;
if ( V_84 )
goto V_104;
V_2 -> V_100 = V_101 ;
V_104:
F_22 ( & V_2 -> V_102 ) ;
return V_84 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_3 V_105 = V_2 -> V_71 [ 0 ] . V_79 [ 0 ] ;
T_3 V_106 = V_2 -> V_71 [ 1 ] . V_79 [ 0 ] ;
V_105 *= V_2 -> V_71 [ 1 ] . V_76 ;
V_106 *= V_2 -> V_71 [ 0 ] . V_76 ;
if ( V_2 -> V_71 [ 1 ] . V_76 == 0 )
return 0 ;
if ( V_105 > V_106 )
return 0 ;
return 1 ;
}
static int F_24 ( struct V_91 * V_92 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = F_25 ( V_92 ) ;
int V_109 ;
int V_110 = 2 ;
void T_1 * V_111 ;
T_2 V_112 ;
T_2 V_113 ;
F_6 ( V_2 ) ;
V_109 = F_23 ( V_2 ) ;
V_108 -> V_114 = V_2 -> V_100 . V_9 ;
if ( V_109 )
V_111 = V_115 ;
else
V_111 = V_116 ;
V_113 = F_3 ( V_111 + 0x04 ) ;
V_112 = F_3 ( V_111 + 0x38 ) ;
switch ( ( V_113 >> 8 ) & 0xf ) {
case 0x4 :
V_110 = ( ( V_112 >> 16 ) & 0xf ) * 2 ;
break;
case 0x5 :
case 0x6 :
V_110 = ( ( V_112 >> 8 ) & 0xf ) + ( ( V_112 >> 0 ) & 0xf ) ;
break;
default:
F_26 ( L_2 , V_117 ,
( V_113 >> 8 ) & 0xf ) ;
return - V_12 ;
}
V_108 -> V_118 = V_2 -> V_71 [ V_109 ] . V_79 [ 0 ] / 2 * ( V_110 + 2 ) ;
V_108 -> V_118 *= 100 / V_119 ;
V_108 -> V_120 = V_2 -> V_71 [ V_109 ] . V_76 ;
if ( V_2 -> V_71 [ V_109 ] . V_77 ||
V_2 -> V_71 [ V_109 ] . V_80 [ 0 ] )
return - V_121 ;
return 0 ;
}
static void F_27 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_25 ( V_92 ) ;
F_28 ( V_92 , V_2 -> V_122 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_2 V_6 ;
int V_123 ;
int V_69 , V_84 = 0 ;
V_6 = F_3 ( V_14 ) ;
for ( V_69 = V_7 ; V_69 < V_8 ; V_69 ++ ) {
V_6 &= ~ ( V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 ) ;
V_6 |= ( ( V_132 [ V_69 ] [ 0 ] <<
V_133 ) |
( V_132 [ V_69 ] [ 1 ] <<
V_134 ) |
( V_132 [ V_69 ] [ 2 ] <<
V_135 ) |
( V_132 [ V_69 ] [ 3 ] <<
V_136 ) |
( V_132 [ V_69 ] [ 4 ] <<
V_137 ) |
( V_132 [ V_69 ] [ 5 ] <<
V_138 ) |
( V_132 [ V_69 ] [ 6 ] <<
V_139 ) |
( V_132 [ V_69 ] [ 7 ] <<
V_140 ) ) ;
V_2 -> V_13 [ V_69 ] = V_6 ;
}
V_6 = F_3 ( V_17 ) ;
for ( V_69 = V_7 ; V_69 < V_8 ; V_69 ++ ) {
V_6 &= ~ ( V_141 |
V_40 |
V_41 |
V_42 |
V_43 ) ;
V_6 |= ( ( V_142 [ V_69 ] [ 0 ] <<
V_143 ) |
( V_142 [ V_69 ] [ 1 ] <<
V_46 ) |
( V_142 [ V_69 ] [ 2 ] <<
V_47 ) |
( V_142 [ V_69 ] [ 3 ] <<
V_48 ) |
( V_142 [ V_69 ] [ 4 ] <<
V_49 ) ) ;
V_2 -> V_16 [ V_69 ] = V_6 ;
}
#ifdef F_30
V_6 = V_144 ;
#else
V_6 = 0 ;
#endif
F_31 ( L_3 , V_6 ) ;
switch ( V_6 ) {
case 0 :
V_123 = 0 ;
break;
case 1 :
case 2 :
V_123 = 1 ;
break;
case 3 :
case 4 :
V_123 = 2 ;
break;
case 5 :
case 6 :
V_123 = 3 ;
break;
case 7 :
V_123 = 4 ;
break;
default:
F_32 ( L_4 ) ;
V_123 = 0 ;
}
for ( V_69 = V_7 ; V_69 < V_8 ; V_69 ++ )
V_10 [ V_69 ] . V_85 = V_145 [ V_123 ] [ V_69 ] ;
for ( V_69 = V_7 ; V_69 < V_8 ; V_69 ++ ) {
V_84 = F_33 ( V_2 -> V_92 , V_10 [ V_69 ] . V_11 ,
V_10 [ V_69 ] . V_85 ) ;
if ( V_84 ) {
F_34 ( V_2 -> V_92 , L_5 ) ;
return V_84 ;
}
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned int V_69 ;
unsigned int V_6 ;
int V_146 ;
V_6 = F_3 ( V_147 ) ;
V_6 |= V_148 ;
F_2 ( V_6 , V_147 ) ;
V_6 = F_3 ( V_14 ) ;
for ( V_69 = 0 ; V_69 < V_28 ; V_69 ++ ) {
V_6 &= ~ ( V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 ) ;
V_6 |= ( ( V_149 [ V_69 ] [ 0 ] <<
V_133 ) |
( V_149 [ V_69 ] [ 1 ] <<
V_134 ) |
( V_149 [ V_69 ] [ 2 ] <<
V_135 ) |
( V_149 [ V_69 ] [ 3 ] <<
V_136 ) |
( V_149 [ V_69 ] [ 4 ] <<
V_137 ) |
( V_149 [ V_69 ] [ 5 ] <<
V_138 ) ) ;
V_2 -> V_13 [ V_69 ] = V_6 ;
}
#ifdef F_30
V_6 = V_144 ;
#else
V_6 = 0 ;
#endif
if ( V_6 > 8 )
V_6 = 0 ;
F_31 ( L_6 , V_6 ) ;
for ( V_69 = 0 ; V_69 < V_28 ; V_69 ++ ) {
V_29 [ V_69 ] . V_85 =
V_150 [ V_6 ] [ V_69 ] ;
V_82 [ V_69 ] . V_85 =
V_151 [ V_6 ] [ V_69 ] ;
}
for ( V_69 = 0 ; V_69 < V_28 ; V_69 ++ ) {
V_146 = F_33 ( V_2 -> V_92 , V_29 [ V_69 ] . V_11 ,
V_29 [ V_69 ] . V_85 ) ;
if ( V_146 ) {
F_34 ( V_2 -> V_92 , L_7 ) ;
return V_146 ;
}
}
return 0 ;
}
static int F_36 ( struct V_152 * V_153 ,
unsigned long V_73 , void * V_154 )
{
struct V_1 * V_2 = F_11 ( V_153 , struct V_1 ,
V_155 ) ;
struct V_97 * V_97 ;
struct V_3 V_101 ;
unsigned long V_156 = V_157 ;
int V_84 = 0 ;
switch ( V_73 ) {
case V_158 :
F_21 ( & V_2 -> V_102 ) ;
V_2 -> V_103 = true ;
F_13 () ;
V_97 = F_37 ( V_2 -> V_92 , & V_156 ) ;
if ( F_15 ( V_97 ) ) {
F_16 () ;
F_34 ( V_2 -> V_92 , L_8 ,
V_117 ) ;
return F_17 ( V_97 ) ;
}
V_101 . V_9 = F_18 ( V_97 ) ;
V_101 . V_85 = F_19 ( V_97 ) ;
F_16 () ;
V_84 = F_8 ( V_2 , & V_101 ,
& V_2 -> V_100 ) ;
if ( V_84 )
goto V_159;
switch ( V_2 -> type ) {
case V_86 :
V_84 = F_1 ( V_2 , & V_101 ) ;
break;
case V_89 :
V_84 = F_4 ( V_2 , & V_101 ) ;
break;
default:
V_84 = - V_12 ;
}
if ( V_84 )
goto V_159;
V_2 -> V_100 = V_101 ;
V_159:
F_22 ( & V_2 -> V_102 ) ;
if ( V_84 )
return V_84 ;
return V_160 ;
case V_161 :
case V_162 :
F_21 ( & V_2 -> V_102 ) ;
V_2 -> V_103 = false ;
F_22 ( & V_2 -> V_102 ) ;
return V_160 ;
}
return V_163 ;
}
static int F_38 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
struct V_97 * V_97 ;
struct V_91 * V_92 = & V_96 -> V_92 ;
int V_84 = 0 ;
V_2 = F_39 ( & V_96 -> V_92 , sizeof( struct V_1 ) , V_164 ) ;
if ( V_2 == NULL ) {
F_34 ( V_92 , L_9 ) ;
return - V_165 ;
}
V_2 -> type = V_96 -> V_166 -> V_167 ;
V_2 -> V_71 [ 0 ] . V_72 = V_116 ;
V_2 -> V_71 [ 1 ] . V_72 = V_115 ;
V_2 -> V_155 . V_168 = F_36 ;
V_2 -> V_92 = V_92 ;
F_40 ( & V_2 -> V_102 ) ;
switch ( V_2 -> type ) {
case V_86 :
V_84 = F_29 ( V_2 ) ;
break;
case V_89 :
V_84 = F_35 ( V_2 ) ;
break;
default:
F_34 ( V_92 , L_10 , V_2 -> type ) ;
V_84 = - V_12 ;
}
if ( V_84 )
return V_84 ;
V_2 -> V_87 = F_41 ( V_92 , L_11 ) ;
if ( F_15 ( V_2 -> V_87 ) ) {
F_34 ( V_92 , L_12 ) ;
return F_17 ( V_2 -> V_87 ) ;
}
if ( V_2 -> type == V_89 ) {
V_2 -> V_90 = F_41 ( V_92 , L_13 ) ;
if ( F_15 ( V_2 -> V_90 ) ) {
F_34 ( V_92 , L_14 ) ;
return F_17 ( V_2 -> V_90 ) ;
}
}
F_13 () ;
V_97 = F_37 ( V_92 , & V_169 . V_170 ) ;
if ( F_15 ( V_97 ) ) {
F_16 () ;
F_34 ( V_92 , L_15 ,
V_169 . V_170 ) ;
return F_17 ( V_97 ) ;
}
V_2 -> V_100 . V_9 = F_18 ( V_97 ) ;
V_2 -> V_100 . V_85 = F_19 ( V_97 ) ;
F_16 () ;
F_42 ( V_96 , V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_122 = F_43 ( V_92 , & V_169 ,
L_16 , NULL ) ;
if ( F_15 ( V_2 -> V_122 ) )
return F_17 ( V_2 -> V_122 ) ;
F_44 ( V_92 , V_2 -> V_122 ) ;
V_84 = F_45 ( & V_2 -> V_155 ) ;
if ( V_84 ) {
F_34 ( V_92 , L_17 ) ;
F_46 ( V_2 -> V_122 ) ;
return V_84 ;
}
return 0 ;
}
static int F_47 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_12 ( V_96 ) ;
F_48 ( & V_2 -> V_155 ) ;
F_46 ( V_2 -> V_122 ) ;
return 0 ;
}
static int F_49 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_25 ( V_92 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
return F_51 ( & V_171 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_171 ) ;
}
