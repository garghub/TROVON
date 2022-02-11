static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
unsigned int V_4 ;
unsigned int V_5 ;
for ( V_4 = V_6 ; V_4 < V_7 ; V_4 ++ )
if ( F_2 ( V_3 ) == V_8 [ V_4 ] . V_9 )
break;
if ( V_4 == V_7 )
return - V_10 ;
V_5 = V_2 -> V_11 [ V_4 ] ;
F_3 ( V_5 , V_12 ) ;
do {
V_5 = F_4 ( V_13 ) ;
} while ( V_5 & 0x11111111 );
V_5 = V_2 -> V_14 [ V_4 ] ;
F_3 ( V_5 , V_15 ) ;
do {
V_5 = F_4 ( V_16 ) ;
} while ( V_5 & 0x11111 );
V_5 = F_4 ( V_17 ) ;
V_5 &= ~ ( V_18 | V_19 ) ;
V_5 |= ( ( V_20 [ V_4 ] [ 0 ] <<
V_21 ) |
( V_20 [ V_4 ] [ 1 ] <<
V_22 ) ) ;
F_3 ( V_5 , V_17 ) ;
do {
V_5 = F_4 ( V_23 ) ;
} while ( V_5 & 0x11 );
V_5 = F_4 ( V_24 ) ;
V_5 &= ~ ( V_18 | V_19 ) ;
V_5 |= ( ( V_20 [ V_4 ] [ 0 ] <<
V_21 ) |
( V_20 [ V_4 ] [ 1 ] <<
V_22 ) ) ;
F_3 ( V_5 , V_24 ) ;
do {
V_5 = F_4 ( V_25 ) ;
} while ( V_5 & 0x11 );
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
unsigned int V_4 ;
unsigned int V_5 ;
for ( V_4 = V_6 ; V_4 < V_26 ; V_4 ++ )
if ( F_2 ( V_3 ) == V_27 [ V_4 ] . V_9 )
break;
if ( V_4 == V_26 )
return - V_10 ;
V_5 = V_2 -> V_11 [ V_4 ] ;
F_3 ( V_5 , V_12 ) ;
do {
V_5 = F_4 ( V_13 ) ;
} while ( V_5 & 0x11111111 );
V_5 = F_4 ( V_28 ) ;
V_5 &= ~ ( V_29 |
V_30 |
V_31 ) ;
V_5 |= ( ( V_32 [ V_4 ] [ 0 ] <<
V_33 ) |
( V_32 [ V_4 ] [ 1 ] <<
V_34 ) |
( V_32 [ V_4 ] [ 2 ] <<
V_35 ) ) ;
F_3 ( V_5 , V_28 ) ;
do {
V_5 = F_4 ( V_36 ) ;
} while ( V_5 & 0x111111 );
V_5 = F_4 ( V_15 ) ;
V_5 &= ~ ( V_37 |
V_38 |
V_39 |
V_40 |
V_41 ) ;
V_5 |= ( ( V_42 [ V_4 ] [ 0 ] <<
V_43 ) |
( V_42 [ V_4 ] [ 1 ] <<
V_44 ) |
( V_42 [ V_4 ] [ 2 ] <<
V_45 ) |
( V_42 [ V_4 ] [ 3 ] <<
V_46 ) |
( V_42 [ V_4 ] [ 4 ] <<
V_47 ) ) ;
F_3 ( V_5 , V_15 ) ;
do {
V_5 = F_4 ( V_16 ) ;
} while ( V_5 & 0x11111 );
V_5 = F_4 ( V_17 ) ;
V_5 &= ~ ( V_18 | V_19 ) ;
V_5 |= ( ( V_48 [ V_4 ] [ 0 ] <<
V_21 ) |
( V_48 [ V_4 ] [ 1 ] <<
V_22 ) ) ;
F_3 ( V_5 , V_17 ) ;
do {
V_5 = F_4 ( V_23 ) ;
} while ( V_5 & 0x11 );
V_5 = F_4 ( V_24 ) ;
V_5 &= ~ ( V_18 | V_19 ) ;
V_5 |= ( ( V_48 [ V_4 ] [ 0 ] <<
V_21 ) |
( V_48 [ V_4 ] [ 1 ] <<
V_22 ) ) ;
F_3 ( V_5 , V_24 ) ;
do {
V_5 = F_4 ( V_25 ) ;
} while ( V_5 & 0x11 );
V_5 = F_4 ( V_49 ) ;
V_5 &= ~ ( V_50 ) ;
V_5 |= ( ( V_51 [ V_4 ] [ 0 ] <<
V_52 ) ) ;
F_3 ( V_5 , V_49 ) ;
do {
V_5 = F_4 ( V_53 ) ;
} while ( V_5 & 0x1 );
V_5 = F_4 ( V_54 ) ;
V_5 &= ~ ( V_55 ) ;
V_5 |= ( ( V_51 [ V_4 ] [ 1 ] <<
V_56 ) ) ;
F_3 ( V_5 , V_54 ) ;
do {
V_5 = F_4 ( V_57 ) ;
} while ( V_5 & 0x1 );
V_5 = F_4 ( V_58 ) ;
V_5 &= ~ ( V_59 | V_60 |
V_61 | V_62 ) ;
V_5 |= ( ( V_51 [ V_4 ] [ 2 ] <<
V_63 ) |
( V_51 [ V_4 ] [ 2 ] <<
V_64 ) |
( V_51 [ V_4 ] [ 2 ] <<
V_65 ) |
( V_51 [ V_4 ] [ 2 ] <<
V_66 ) ) ;
F_3 ( V_5 , V_58 ) ;
do {
V_5 = F_4 ( V_57 ) ;
} while ( V_5 & 0x1111 );
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
void T_1 * V_68 = V_2 -> V_69 [ V_67 ] . V_70 ;
F_3 ( 0x8000000f , V_68 + 0xf010 ) ;
F_3 ( 0x8000000f , V_68 + 0xf050 ) ;
F_3 ( 0x6 , V_68 + 0xf000 ) ;
F_3 ( 0x0 , V_68 + 0xf100 ) ;
V_2 -> V_69 [ V_67 ] . V_71 = 0x6 ;
F_3 ( ( ( V_2 -> V_69 [ V_67 ] . V_71 << 12 ) | 0x1 ) ,
V_68 + 0xfc ) ;
F_3 ( 0x1 , V_68 + 0xf000 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
int V_67 , V_72 ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
void T_1 * V_68 = V_2 -> V_69 [ V_67 ] . V_70 ;
T_2 V_73 ;
F_3 ( 0x0 , V_68 + 0xf000 ) ;
V_73 = F_4 ( V_68 + 0xf050 ) ;
V_2 -> V_69 [ V_67 ] . V_74 = F_4 ( V_68 + 0xf100 ) ;
V_2 -> V_69 [ V_67 ] . V_75 = V_73 & ( 1 << 31 ) ;
for ( V_72 = 0 ; V_72 < V_76 ; V_72 ++ ) {
V_2 -> V_69 [ V_67 ] . V_77 [ V_72 ] = F_4 (
V_68 + ( 0xf110 + ( 0x10 * V_72 ) ) ) ;
V_2 -> V_69 [ V_67 ] . V_78 [ V_72 ] = V_73 & ( 1 << V_72 ) ;
}
}
F_6 ( V_2 ) ;
}
static int F_8 ( unsigned long V_79 )
{
int V_67 = 0 ;
while ( V_80 [ V_67 ] . V_9 ) {
if ( V_80 [ V_67 ] . V_9 <= V_79 )
return V_67 ;
V_67 ++ ;
}
return - V_10 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_3 * V_81 )
{
int V_82 = 0 , V_5 ;
unsigned long V_83 = F_10 ( V_3 ) ;
switch ( V_2 -> type ) {
case V_84 :
V_82 = F_11 ( V_2 -> V_85 , V_83 ,
V_86 ) ;
break;
case V_87 :
V_82 = F_11 ( V_2 -> V_88 , V_83 ,
V_86 ) ;
if ( V_82 )
break;
V_5 = F_8 ( F_2 ( V_3 ) ) ;
if ( V_5 < 0 ) {
V_82 = V_5 ;
F_11 ( V_2 -> V_88 ,
F_10 ( V_81 ) ,
V_86 ) ;
break;
}
V_82 = F_11 ( V_2 -> V_85 ,
V_80 [ V_5 ] . V_83 ,
V_86 ) ;
if ( V_82 )
F_11 ( V_2 -> V_88 ,
F_10 ( V_81 ) ,
V_86 ) ;
break;
default:
V_82 = - V_10 ;
}
return V_82 ;
}
static int F_12 ( struct V_89 * V_90 , unsigned long * V_91 )
{
int V_82 = 0 ;
struct V_92 * V_93 = F_13 ( V_90 , struct V_92 ,
V_90 ) ;
struct V_1 * V_2 = F_14 ( V_93 ) ;
struct V_3 * V_3 = F_15 ( V_90 , V_91 ) ;
unsigned long V_94 = F_2 ( V_2 -> V_95 ) ;
unsigned long V_96 = F_2 ( V_3 ) ;
if ( V_94 == V_96 )
return 0 ;
F_16 ( V_90 , L_1 , V_96 , F_10 ( V_3 ) ) ;
F_17 ( & V_2 -> V_97 ) ;
if ( V_2 -> V_98 )
goto V_99;
if ( V_94 < V_96 )
V_82 = F_9 ( V_2 , V_3 , V_2 -> V_95 ) ;
if ( V_82 )
goto V_99;
if ( V_94 != V_96 ) {
switch ( V_2 -> type ) {
case V_84 :
V_82 = F_1 ( V_2 , V_3 ) ;
break;
case V_87 :
V_82 = F_5 ( V_2 , V_3 ) ;
break;
default:
V_82 = - V_10 ;
}
}
if ( V_82 )
goto V_99;
if ( V_94 > V_96 )
V_82 = F_9 ( V_2 , V_3 , V_2 -> V_95 ) ;
if ( V_82 )
goto V_99;
V_2 -> V_95 = V_3 ;
V_99:
F_18 ( & V_2 -> V_97 ) ;
return V_82 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_3 V_100 = V_2 -> V_69 [ 0 ] . V_77 [ 0 ] ;
T_3 V_101 = V_2 -> V_69 [ 1 ] . V_77 [ 0 ] ;
V_100 *= V_2 -> V_69 [ 1 ] . V_74 ;
V_101 *= V_2 -> V_69 [ 0 ] . V_74 ;
if ( V_2 -> V_69 [ 1 ] . V_74 == 0 )
return 0 ;
if ( V_100 > V_101 )
return 0 ;
return 1 ;
}
static int F_20 ( struct V_89 * V_90 ,
struct V_102 * V_103 )
{
struct V_92 * V_93 = F_13 ( V_90 , struct V_92 ,
V_90 ) ;
struct V_1 * V_2 = F_14 ( V_93 ) ;
int V_104 ;
int V_105 = 2 ;
void T_1 * V_106 ;
T_2 V_107 ;
T_2 V_108 ;
F_7 ( V_2 ) ;
V_104 = F_19 ( V_2 ) ;
V_103 -> V_109 = F_2 ( V_2 -> V_95 ) ;
if ( V_104 )
V_106 = V_110 ;
else
V_106 = V_111 ;
V_108 = F_4 ( V_106 + 0x04 ) ;
V_107 = F_4 ( V_106 + 0x38 ) ;
switch ( ( V_108 >> 8 ) & 0xf ) {
case 0x4 :
V_105 = ( ( V_107 >> 16 ) & 0xf ) * 2 ;
break;
case 0x5 :
case 0x6 :
V_105 = ( ( V_107 >> 8 ) & 0xf ) + ( ( V_107 >> 0 ) & 0xf ) ;
break;
default:
F_21 ( L_2 , V_112 ,
( V_108 >> 8 ) & 0xf ) ;
return - V_10 ;
}
V_103 -> V_113 = V_2 -> V_69 [ V_104 ] . V_77 [ 0 ] / 2 * ( V_105 + 2 ) ;
V_103 -> V_113 *= 100 / V_114 ;
V_103 -> V_115 = V_2 -> V_69 [ V_104 ] . V_74 ;
if ( V_2 -> V_69 [ V_104 ] . V_75 ||
V_2 -> V_69 [ V_104 ] . V_78 [ 0 ] )
return - V_116 ;
return 0 ;
}
static void F_22 ( struct V_89 * V_90 )
{
struct V_92 * V_93 = F_13 ( V_90 , struct V_92 ,
V_90 ) ;
struct V_1 * V_2 = F_14 ( V_93 ) ;
F_23 ( V_90 , V_2 -> V_117 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_2 V_5 ;
int V_118 ;
int V_67 , V_82 = 0 ;
V_5 = F_4 ( V_12 ) ;
for ( V_67 = V_6 ; V_67 < V_7 ; V_67 ++ ) {
V_5 &= ~ ( V_119 |
V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 ) ;
V_5 |= ( ( V_127 [ V_67 ] [ 0 ] <<
V_128 ) |
( V_127 [ V_67 ] [ 1 ] <<
V_129 ) |
( V_127 [ V_67 ] [ 2 ] <<
V_130 ) |
( V_127 [ V_67 ] [ 3 ] <<
V_131 ) |
( V_127 [ V_67 ] [ 4 ] <<
V_132 ) |
( V_127 [ V_67 ] [ 5 ] <<
V_133 ) |
( V_127 [ V_67 ] [ 6 ] <<
V_134 ) |
( V_127 [ V_67 ] [ 7 ] <<
V_135 ) ) ;
V_2 -> V_11 [ V_67 ] = V_5 ;
}
V_5 = F_4 ( V_15 ) ;
for ( V_67 = V_6 ; V_67 < V_7 ; V_67 ++ ) {
V_5 &= ~ ( V_136 |
V_38 |
V_39 |
V_40 |
V_41 ) ;
V_5 |= ( ( V_137 [ V_67 ] [ 0 ] <<
V_138 ) |
( V_137 [ V_67 ] [ 1 ] <<
V_44 ) |
( V_137 [ V_67 ] [ 2 ] <<
V_45 ) |
( V_137 [ V_67 ] [ 3 ] <<
V_46 ) |
( V_137 [ V_67 ] [ 4 ] <<
V_47 ) ) ;
V_2 -> V_14 [ V_67 ] = V_5 ;
}
#ifdef F_25
V_5 = V_139 ;
#else
V_5 = 0 ;
#endif
F_26 ( L_3 , V_5 ) ;
switch ( V_5 ) {
case 0 :
V_118 = 0 ;
break;
case 1 :
case 2 :
V_118 = 1 ;
break;
case 3 :
case 4 :
V_118 = 2 ;
break;
case 5 :
case 6 :
V_118 = 3 ;
break;
case 7 :
V_118 = 4 ;
break;
default:
F_27 ( L_4 ) ;
V_118 = 0 ;
}
for ( V_67 = V_6 ; V_67 < V_7 ; V_67 ++ )
V_8 [ V_67 ] . V_83 = V_140 [ V_118 ] [ V_67 ] ;
for ( V_67 = V_6 ; V_67 < V_7 ; V_67 ++ ) {
V_82 = F_28 ( V_2 -> V_90 , V_8 [ V_67 ] . V_9 ,
V_8 [ V_67 ] . V_83 ) ;
if ( V_82 ) {
F_29 ( V_2 -> V_90 , L_5 ) ;
return V_82 ;
}
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned int V_67 ;
unsigned int V_5 ;
int V_141 ;
V_5 = F_4 ( V_142 ) ;
V_5 |= V_143 ;
F_3 ( V_5 , V_142 ) ;
V_5 = F_4 ( V_12 ) ;
for ( V_67 = 0 ; V_67 < V_26 ; V_67 ++ ) {
V_5 &= ~ ( V_119 |
V_120 |
V_121 |
V_122 |
V_123 |
V_124 ) ;
V_5 |= ( ( V_144 [ V_67 ] [ 0 ] <<
V_128 ) |
( V_144 [ V_67 ] [ 1 ] <<
V_129 ) |
( V_144 [ V_67 ] [ 2 ] <<
V_130 ) |
( V_144 [ V_67 ] [ 3 ] <<
V_131 ) |
( V_144 [ V_67 ] [ 4 ] <<
V_132 ) |
( V_144 [ V_67 ] [ 5 ] <<
V_133 ) ) ;
V_2 -> V_11 [ V_67 ] = V_5 ;
}
#ifdef F_25
V_5 = V_139 ;
#else
V_5 = 0 ;
#endif
if ( V_5 > 8 )
V_5 = 0 ;
F_26 ( L_6 , V_5 ) ;
for ( V_67 = 0 ; V_67 < V_26 ; V_67 ++ ) {
V_27 [ V_67 ] . V_83 =
V_145 [ V_5 ] [ V_67 ] ;
V_80 [ V_67 ] . V_83 =
V_146 [ V_5 ] [ V_67 ] ;
}
for ( V_67 = 0 ; V_67 < V_26 ; V_67 ++ ) {
V_141 = F_28 ( V_2 -> V_90 , V_27 [ V_67 ] . V_9 ,
V_27 [ V_67 ] . V_83 ) ;
if ( V_141 ) {
F_29 ( V_2 -> V_90 , L_7 ) ;
return V_141 ;
}
}
return 0 ;
}
static int F_31 ( struct V_147 * V_148 ,
unsigned long V_71 , void * V_149 )
{
struct V_1 * V_2 = F_13 ( V_148 , struct V_1 ,
V_150 ) ;
struct V_3 * V_3 ;
unsigned long V_151 = V_152 ;
int V_82 = 0 ;
switch ( V_71 ) {
case V_153 :
F_17 ( & V_2 -> V_97 ) ;
V_2 -> V_98 = true ;
V_3 = F_32 ( V_2 -> V_90 , & V_151 ) ;
V_82 = F_9 ( V_2 , V_3 , V_2 -> V_95 ) ;
if ( V_82 )
goto V_154;
switch ( V_2 -> type ) {
case V_84 :
V_82 = F_1 ( V_2 , V_3 ) ;
break;
case V_87 :
V_82 = F_5 ( V_2 , V_3 ) ;
break;
default:
V_82 = - V_10 ;
}
if ( V_82 )
goto V_154;
V_2 -> V_95 = V_3 ;
V_154:
F_18 ( & V_2 -> V_97 ) ;
if ( V_82 )
return V_82 ;
return V_155 ;
case V_156 :
case V_157 :
F_17 ( & V_2 -> V_97 ) ;
V_2 -> V_98 = false ;
F_18 ( & V_2 -> V_97 ) ;
return V_155 ;
}
return V_158 ;
}
static T_4 int F_33 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
struct V_3 * V_3 ;
struct V_89 * V_90 = & V_93 -> V_90 ;
int V_82 = 0 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_159 ) ;
if ( V_2 == NULL ) {
F_29 ( V_90 , L_8 ) ;
return - V_160 ;
}
V_2 -> type = V_93 -> V_161 -> V_162 ;
V_2 -> V_69 [ 0 ] . V_70 = V_111 ;
V_2 -> V_69 [ 1 ] . V_70 = V_110 ;
V_2 -> V_150 . V_163 = F_31 ;
V_2 -> V_90 = V_90 ;
F_35 ( & V_2 -> V_97 ) ;
switch ( V_2 -> type ) {
case V_84 :
V_82 = F_24 ( V_2 ) ;
break;
case V_87 :
V_82 = F_30 ( V_2 ) ;
break;
default:
F_29 ( V_90 , L_9 , V_2 -> type ) ;
V_82 = - V_10 ;
}
if ( V_82 )
goto V_164;
V_2 -> V_85 = F_36 ( V_90 , L_10 ) ;
if ( F_37 ( V_2 -> V_85 ) ) {
F_29 ( V_90 , L_11 ) ;
V_82 = F_38 ( V_2 -> V_85 ) ;
goto V_164;
}
if ( V_2 -> type == V_87 ) {
V_2 -> V_88 = F_36 ( V_90 , L_12 ) ;
if ( F_37 ( V_2 -> V_88 ) ) {
F_29 ( V_90 , L_13 ) ;
V_82 = F_38 ( V_2 -> V_88 ) ;
F_39 ( V_2 -> V_85 ) ;
goto V_164;
}
}
V_3 = F_32 ( V_90 , & V_165 . V_166 ) ;
if ( F_37 ( V_3 ) ) {
F_29 ( V_90 , L_14 ,
V_165 . V_166 ) ;
V_82 = F_38 ( V_3 ) ;
goto V_167;
}
V_2 -> V_95 = V_3 ;
F_40 ( V_93 , V_2 ) ;
F_6 ( V_2 ) ;
V_2 -> V_117 = F_41 ( V_90 , & V_165 ,
& V_168 , NULL ) ;
if ( F_37 ( V_2 -> V_117 ) ) {
V_82 = F_38 ( V_2 -> V_117 ) ;
goto V_167;
}
F_42 ( V_90 , V_2 -> V_117 ) ;
V_82 = F_43 ( & V_2 -> V_150 ) ;
if ( V_82 ) {
F_29 ( V_90 , L_15 ) ;
goto V_169;
}
return 0 ;
V_169:
F_44 ( V_2 -> V_117 ) ;
V_167:
if ( V_2 -> V_88 )
F_39 ( V_2 -> V_88 ) ;
F_39 ( V_2 -> V_85 ) ;
V_164:
F_45 ( V_2 ) ;
return V_82 ;
}
static T_5 int F_46 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_14 ( V_93 ) ;
F_47 ( & V_2 -> V_150 ) ;
F_44 ( V_2 -> V_117 ) ;
F_39 ( V_2 -> V_85 ) ;
if ( V_2 -> V_88 )
F_39 ( V_2 -> V_88 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_89 * V_90 )
{
struct V_92 * V_93 = F_13 ( V_90 , struct V_92 ,
V_90 ) ;
struct V_1 * V_2 = F_14 ( V_93 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int T_6 F_49 ( void )
{
return F_50 ( & V_170 ) ;
}
static void T_7 F_51 ( void )
{
F_52 ( & V_170 ) ;
}
