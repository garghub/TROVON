static void T_1 F_1 ( void )
{
if ( F_2 ( & V_1 -> V_2 ) & V_3 )
F_3 ( L_1 ,
F_4 () ) ;
F_5 ( V_3 ) ;
F_5 ( V_4 ) ;
}
void T_1 F_6 ( void )
{
F_7 ( F_8 ( 2 ) & 0xfffffffffULL ) ;
}
static void F_9 ( char * V_5 )
{
F_10 () ;
F_11 ( L_2 ,
( F_2 ( & V_1 -> V_2 ) & V_6 ) ?
L_3 : L_4 ) ;
F_5 ( V_3 ) ;
F_12 ( F_8 ( 2 ) & 0xfffffffffULL ) ;
while ( ! ( F_2 ( & V_1 -> V_2 ) & V_3 ) )
;
F_13 ( 10 ) ;
if ( F_2 ( & V_1 -> V_2 ) & V_6 ) {
F_11 ( L_5 ) ;
F_14 ( V_6 ) ;
}
(* F_15)() ;
}
static int F_16 ( struct V_7 * V_8 , int V_9 )
{
int V_10 = V_8 -> V_11 & 4 ;
F_17 () ;
F_18 ( L_6 ,
V_10 ? 'D' : 'I' , V_8 -> V_12 ) ;
F_18 ( L_7 ,
( unsigned long long ) F_2 ( & V_1 -> V_2 ) ,
( unsigned long long ) F_2 ( & V_1 -> V_13 ) ) ;
#ifdef F_19
F_20 () ;
#endif
F_21 ( V_8 ) ;
F_22 ( L_8 ) ;
}
static void T_1 F_23 ( void )
{
V_14 = F_16 ;
}
void T_1 F_24 ( void )
{
int V_15 ;
unsigned long V_16 , V_17 ;
T_2 V_18 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
if ( ! ( ( V_19 ) F_2 ( & V_20 -> V_21 ) & ( 1 << V_15 ) ) )
continue;
V_18 = F_2 ( & V_20 -> V_18 [ V_15 ] ) ;
V_16 = ( unsigned long ) ( V_18 >> 48 ) ;
V_17 = ( ( ( unsigned long ) ( V_18 >> 32 ) & 0xffff ) + 1 ) - V_16 ;
F_25 ( V_16 << 20 , V_17 << 20 , V_22 ) ;
}
}
void T_1 F_26 ( void )
{
int V_15 ;
V_19 V_23 ;
T_3 V_24 ;
unsigned int V_25 = 0 ;
F_27 ( F_28 () , V_26 ,
V_27 ) ;
F_29 ( V_28 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
if ( ! ( F_30 ( V_15 ) & 0x8 ) )
continue;
V_29 [ V_15 ] . V_16 = ( unsigned long ) F_31 ( V_15 ) ;
V_29 [ V_15 ] . V_30 =
V_29 [ V_15 ] . V_16 + F_32 ( V_15 ) - 1 ;
F_33 ( & V_31 , & V_29 [ V_15 ] ) ;
}
if ( V_32 ) {
V_23 = ( V_19 ) F_2 ( & V_1 -> V_2 ) &
V_33 ;
V_25 = V_32 * 20 / 2 ;
switch ( V_23 ) {
case V_34 :
V_25 = V_25 / 3 * 4 ; break;
case V_35 :
V_25 = V_25 / 2 * 3 ; break;
case V_36 :
V_25 = V_25 / 3 * 5 ; break;
case V_37 :
V_25 = V_25 / 6 * 11 ; break;
case V_38 :
V_25 = V_25 * 2 ; break;
case V_39 :
V_25 = V_25 / 6 * 13 ; break;
case V_40 :
V_25 = V_25 / 3 * 7 ; break;
case V_41 :
V_25 = V_25 / 2 * 5 ; break;
}
V_42 = V_25 ;
} else {
if ( V_42 == 0 )
V_42 = 400000000 ;
V_25 = V_42 ;
V_23 = ( V_19 ) F_2 ( & V_1 -> V_2 ) &
V_33 ;
switch ( V_23 ) {
case V_34 :
V_32 = V_25 * 6 / 8 ; break;
case V_35 :
V_32 = V_25 * 6 / 9 ; break;
case V_36 :
V_32 = V_25 * 6 / 10 ; break;
case V_37 :
V_32 = V_25 * 6 / 11 ; break;
case V_38 :
V_32 = V_25 * 6 / 12 ; break;
case V_39 :
V_32 = V_25 * 6 / 13 ; break;
case V_40 :
V_32 = V_25 * 6 / 14 ; break;
case V_41 :
V_32 = V_25 * 6 / 15 ; break;
}
V_32 /= 10 ;
}
V_23 = ( V_19 ) F_2 ( & V_1 -> V_2 ) &
V_43 ;
V_44 = V_42 ;
switch ( V_23 ) {
case V_45 :
V_44 /= 2 ; break;
case V_46 :
V_44 /= 3 ; break;
case V_47 :
V_44 /= 5 ; break;
case V_48 :
V_44 /= 6 ; break;
}
V_49 = V_42 / V_50 / 2 ;
F_1 () ;
F_5 ( V_3 | V_51 ) ;
if ( V_52 )
F_5 ( V_53 ) ;
F_34 ( & V_1 -> V_24 , V_54 ) ;
if ( ! ( F_2 ( & V_1 -> V_2 ) & V_55 ) )
F_34 ( & V_1 -> V_24 , V_56 ) ;
F_35 ( L_9 ,
V_57 ,
( V_25 + 500000 ) / 1000000 ,
( V_32 + 500000 ) / 1000000 ,
( V_44 + 500000 ) / 1000000 ,
( V_19 ) F_2 ( & V_1 -> V_58 ) ,
( unsigned long long ) F_2 ( & V_1 -> V_2 ) ,
( unsigned long long ) F_2 ( & V_1 -> V_24 ) ) ;
F_35 ( L_10 , V_57 ,
( V_19 ) F_2 ( & V_20 -> V_21 ) ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
T_3 V_18 = F_2 ( & V_20 -> V_18 [ V_15 ] ) ;
if ( ! ( ( V_19 ) F_2 ( & V_20 -> V_21 ) & ( 1 << V_15 ) ) )
continue;
F_36 ( V_59 L_11 , V_15 , ( unsigned long long ) V_18 ) ;
V_60 [ V_15 ] . V_61 = L_12 ;
V_60 [ V_15 ] . V_16 =
( unsigned long ) ( V_18 >> 48 ) << 20 ;
V_60 [ V_15 ] . V_30 =
( ( ( ( unsigned long ) ( V_18 >> 32 ) & 0xffff ) + 1 ) <<
20 ) - 1 ;
V_60 [ V_15 ] . V_62 = V_63 ;
F_33 ( & V_31 , & V_60 [ V_15 ] ) ;
}
F_36 ( V_59 L_13 ) ;
if ( F_2 ( & V_64 -> V_65 ) & 1 ) {
unsigned int V_17 = V_66 ;
V_67 . V_61 = L_14 ;
V_67 . V_16 =
( F_2 ( & V_64 -> V_65 ) >> ( 39 - 11 ) )
& ~ ( V_17 - 1 ) ;
V_67 . V_30 =
V_67 . V_16 + V_66 - 1 ;
V_67 . V_62 = V_63 ;
F_33 ( & V_31 , & V_67 ) ;
}
for ( V_15 = 0 ; V_15 < V_68 ; V_15 ++ )
F_37 ( F_8 ( V_15 ) & 0xfffffffffULL ) ;
F_38 ( & V_1 -> V_69 , V_70 ) ;
V_24 = F_2 ( & V_1 -> V_24 ) ;
if ( V_24 & ( V_71 | V_72 ) ) {
F_13 ( 1 ) ;
F_34 ( & V_1 -> V_69 , V_70 ) ;
} else {
F_35 ( L_15 , V_57 ) ;
F_38 ( & V_1 -> V_69 , V_73 ) ;
}
if ( ! ( V_24 & V_71 ) ) {
F_35 ( L_16 , V_57 ) ;
F_38 ( & V_1 -> V_69 , V_74 ) ;
F_38 ( & V_1 -> V_69 , V_75 ) ;
}
if ( ! ( V_24 & V_72 ) ) {
F_35 ( L_17 , V_57 ) ;
F_38 ( & V_1 -> V_69 , V_76 ) ;
F_38 ( & V_1 -> V_69 , V_77 ) ;
}
V_78 = F_9 ;
V_79 = F_23 ;
}
void T_1 F_39 ( unsigned int V_80 )
{
if ( F_2 ( & V_1 -> V_2 ) & V_81 )
F_40 ( F_8 ( V_80 ) & 0xfffffffffULL ,
V_82 + F_41 ( V_80 ) ,
V_83 ) ;
}
void T_1 F_42 ( unsigned int V_84 , unsigned int V_85 )
{
int V_15 ;
unsigned int V_86 = 0 ;
T_3 V_24 = F_43 ( & V_1 -> V_24 ) ;
V_85 |= ~ 1 ;
if ( ( V_24 & V_87 ) != V_88 )
V_85 |= 1 << 0 ;
if ( ( V_24 & V_87 ) != V_89 )
V_86 |= 1 << 2 ;
if ( V_24 & V_90 )
V_86 |= 1 << 3 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
if ( ( 1 << V_15 ) & V_86 )
continue;
F_44 ( F_45 ( V_15 ) & 0xfffffffffULL ,
V_82 + F_46 ( V_15 ) ,
V_15 , V_84 , ( 1 << V_15 ) & V_85 ) ;
}
}
static T_4 F_47 ( struct V_91 * V_92 )
{
struct V_93 V_94 ;
if ( F_48 ( V_92 , & V_94 ) )
return 100 ;
return F_49 ( & V_94 ) ;
}
static int F_50 ( struct V_95 * V_96 ,
unsigned long V_97 ,
void * V_98 )
{
struct V_91 * V_92 = F_51 ( V_98 ) ;
if ( V_97 == V_99 && F_52 ( V_92 ) ) {
T_3 V_100 = 0 ;
if ( V_92 -> V_101 == V_82 + F_53 ( 0 ) )
V_100 = V_102 ;
else if ( V_92 -> V_101 == V_82 + F_53 ( 1 ) )
V_100 = V_103 ;
if ( V_100 ) {
if ( F_47 ( V_92 ) == 100 )
F_38 ( & V_1 -> V_24 , V_100 ) ;
else
F_34 ( & V_1 -> V_24 , V_100 ) ;
}
}
return V_104 ;
}
void T_1 F_54 ( unsigned char * V_105 , unsigned char * V_106 )
{
T_2 V_24 = F_43 ( & V_1 -> V_24 ) ;
if ( V_105 && ( V_24 & V_71 ) )
F_55 ( V_82 + F_53 ( 0 ) , V_105 ) ;
if ( V_106 && ( V_24 & V_72 ) )
F_55 ( V_82 + F_53 ( 1 ) , V_106 ) ;
F_56 ( & V_107 ) ;
}
void T_1 F_54 ( unsigned char * V_105 , unsigned char * V_106 )
{
}
void T_1 F_57 ( int V_108 )
{
struct V_109 V_110 = {
. V_111 = F_58 ( V_108 ) / 8 ,
} ;
unsigned long V_16 = V_29 [ V_108 ] . V_16 ;
unsigned long V_17 = V_29 [ V_108 ] . V_30 - V_16 + 1 ;
if ( ! ( F_30 ( V_108 ) & 0x8 ) )
return;
F_59 ( V_108 , V_16 , V_17 , & V_110 ) ;
}
void T_1 F_60 ( void )
{
static struct V_112 V_113 [] = {
{
. V_16 = F_61 ( 0 ) ,
. V_30 = F_61 ( 0 ) + 0x1000 - 1 ,
. V_62 = V_63 ,
} , {
. V_16 = V_82 + F_62 ( 0 ) ,
. V_62 = V_114 ,
} ,
} ;
static struct V_112 V_115 [] = {
{
. V_16 = F_61 ( 1 ) ,
. V_30 = F_61 ( 1 ) + 0x1000 - 1 ,
. V_62 = V_63 ,
} , {
. V_16 = V_82 + F_62 ( 1 ) ,
. V_62 = V_114 ,
} ,
} ;
static struct V_116 V_117 = {
. V_61 = L_18 ,
. V_118 = 0 ,
. V_119 = F_63 ( V_113 ) ,
. V_112 = V_113 ,
} ;
static struct V_116 V_120 = {
. V_61 = L_18 ,
. V_118 = 1 ,
. V_119 = F_63 ( V_115 ) ,
. V_112 = V_115 ,
} ;
T_3 V_24 = F_43 ( & V_1 -> V_24 ) ;
if ( V_24 & V_121 )
F_64 ( & V_117 ) ;
if ( ( V_24 & ( V_122 |
V_72 |
V_71 ) ) == V_122 )
F_64 ( & V_120 ) ;
}
void T_1 F_65 ( void )
{
static struct V_112 V_123 [] = {
{
. V_16 = V_124 & 0xfffffffffULL ,
. V_30 = ( V_124 & 0xfffffffffULL ) + 0x100 - 1 ,
. V_62 = V_63 ,
} , {
. V_16 = V_82 + V_125 ,
. V_62 = V_114 ,
} ,
} ;
static struct V_116 V_126 = {
. V_61 = L_19 ,
. V_118 = - 1 ,
. V_119 = F_63 ( V_123 ) ,
. V_112 = V_123 ,
} ;
F_64 ( & V_126 ) ;
}
void T_1 F_66 ( unsigned int V_127 , unsigned int V_128 ,
unsigned char V_86 , unsigned char V_129 )
{
struct V_130 V_131 = {
. V_132 = 1 ,
. V_133 = V_44 ,
. V_127 = V_127 ,
. V_128 = V_128 ,
. V_62 = V_134 | V_135 |
V_136 ,
. V_86 = V_86 ,
. V_129 = V_129 ,
} ;
F_67 ( V_137 & 0xfffffffffULL , & V_131 ) ;
}
void T_1 F_68 ( int V_138 , int V_139 )
{
struct V_140 V_131 = {
. V_141 = true ,
} ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
V_131 . V_142 = V_15 ? V_139 : V_138 ;
F_69 ( V_15 , F_70 ( V_15 ) & 0xfffffffffULL ,
V_82 + F_71 ( V_15 , 0 ) ,
& V_131 ) ;
}
}
void T_1 F_72 ( void )
{
T_2 V_24 = F_43 ( & V_1 -> V_24 ) ;
if ( ( V_24 & V_143 ) == V_144 )
F_73 ( V_145 & 0xfffffffffULL ,
V_82 + V_146 , 1 , 0 , 1 ) ;
}
void T_1 F_74 ( void )
{
if ( V_67 . V_16 )
F_75 ( & V_67 ) ;
}
void T_1 F_76 ( void )
{
static struct V_112 V_123 = {
. V_16 = V_147 & 0xfffffffffULL ,
. V_30 = ( V_147 & 0xfffffffffULL ) + 0x30 - 1 ,
. V_62 = V_63 ,
} ;
static struct V_116 V_148 = {
. V_61 = L_20 ,
. V_118 = - 1 ,
. V_119 = 1 ,
. V_112 = & V_123 ,
} ;
F_64 ( & V_148 ) ;
}
static void T_1 F_77 ( void )
{
T_3 V_24 , V_149 = 0 , V_150 = 0 ;
char V_151 [ 128 ] ;
V_151 [ 0 ] = '\0' ;
F_10 () ;
V_24 = F_2 ( & V_1 -> V_24 ) ;
if ( ( V_24 & V_143 ) !=
V_144 ) {
V_149 |= V_152 ;
V_150 |= V_153 ;
strcat ( V_151 , L_21 ) ;
}
if ( ( V_24 & V_143 ) !=
V_154 &&
( V_24 & V_143 ) !=
V_155 ) {
V_149 |= V_156 ;
V_150 |= V_157 ;
strcat ( V_151 , L_22 ) ;
}
if ( ! ( V_24 & V_121 ) ) {
V_149 |= V_158 ;
V_150 |= V_159 ;
strcat ( V_151 , L_23 ) ;
}
if ( ! ( V_24 & V_122 ) ) {
V_149 |= V_160 ;
V_150 |= V_161 ;
strcat ( V_151 , L_24 ) ;
}
if ( V_24 & V_162 ) {
V_149 |= V_163 ;
V_150 |= V_164 ;
strcat ( V_151 , L_25 ) ;
}
if ( ! ( V_24 & ( V_165 | V_166 ) ) ) {
V_149 |= V_167 ;
V_150 |= V_168 ;
strcat ( V_151 , L_26 ) ;
}
if ( ( V_24 & V_87 ) != V_89 ) {
V_149 |= V_169 ;
V_150 |= V_170 ;
strcat ( V_151 , L_27 ) ;
}
if ( V_24 & V_90 ) {
V_149 |= V_171 ;
V_150 |= V_172 ;
strcat ( V_151 , L_28 ) ;
}
if ( V_149 | V_150 ) {
F_38 ( & V_1 -> V_69 , V_149 ) ;
F_38 ( & V_1 -> V_69 , V_150 ) ;
}
F_78 () ;
if ( V_151 [ 0 ] )
F_35 ( L_29 , V_57 , V_151 ) ;
}
static int T_1 F_79 ( void )
{
if ( V_173 != 0x4939 )
return - V_174 ;
F_77 () ;
return 0 ;
}
