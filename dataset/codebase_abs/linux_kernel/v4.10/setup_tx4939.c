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
return V_94 . V_95 . V_96 ;
}
static int F_49 ( struct V_97 * V_98 ,
unsigned long V_99 ,
void * V_100 )
{
struct V_91 * V_92 = F_50 ( V_100 ) ;
if ( V_99 == V_101 && F_51 ( V_92 ) ) {
T_3 V_102 = 0 ;
if ( V_92 -> V_103 == V_82 + F_52 ( 0 ) )
V_102 = V_104 ;
else if ( V_92 -> V_103 == V_82 + F_52 ( 1 ) )
V_102 = V_105 ;
if ( V_102 ) {
if ( F_47 ( V_92 ) == 100 )
F_38 ( & V_1 -> V_24 , V_102 ) ;
else
F_34 ( & V_1 -> V_24 , V_102 ) ;
}
}
return V_106 ;
}
void T_1 F_53 ( unsigned char * V_107 , unsigned char * V_108 )
{
T_2 V_24 = F_43 ( & V_1 -> V_24 ) ;
if ( V_107 && ( V_24 & V_71 ) )
F_54 ( V_82 + F_52 ( 0 ) , V_107 ) ;
if ( V_108 && ( V_24 & V_72 ) )
F_54 ( V_82 + F_52 ( 1 ) , V_108 ) ;
F_55 ( & V_109 ) ;
}
void T_1 F_53 ( unsigned char * V_107 , unsigned char * V_108 )
{
}
void T_1 F_56 ( int V_110 )
{
struct V_111 V_112 = {
. V_113 = F_57 ( V_110 ) / 8 ,
} ;
unsigned long V_16 = V_29 [ V_110 ] . V_16 ;
unsigned long V_17 = V_29 [ V_110 ] . V_30 - V_16 + 1 ;
if ( ! ( F_30 ( V_110 ) & 0x8 ) )
return;
F_58 ( V_110 , V_16 , V_17 , & V_112 ) ;
}
void T_1 F_59 ( void )
{
static struct V_114 V_115 [] = {
{
. V_16 = F_60 ( 0 ) ,
. V_30 = F_60 ( 0 ) + 0x1000 - 1 ,
. V_62 = V_63 ,
} , {
. V_16 = V_82 + F_61 ( 0 ) ,
. V_62 = V_116 ,
} ,
} ;
static struct V_114 V_117 [] = {
{
. V_16 = F_60 ( 1 ) ,
. V_30 = F_60 ( 1 ) + 0x1000 - 1 ,
. V_62 = V_63 ,
} , {
. V_16 = V_82 + F_61 ( 1 ) ,
. V_62 = V_116 ,
} ,
} ;
static struct V_118 V_119 = {
. V_61 = L_18 ,
. V_120 = 0 ,
. V_121 = F_62 ( V_115 ) ,
. V_114 = V_115 ,
} ;
static struct V_118 V_122 = {
. V_61 = L_18 ,
. V_120 = 1 ,
. V_121 = F_62 ( V_117 ) ,
. V_114 = V_117 ,
} ;
T_3 V_24 = F_43 ( & V_1 -> V_24 ) ;
if ( V_24 & V_123 )
F_63 ( & V_119 ) ;
if ( ( V_24 & ( V_124 |
V_72 |
V_71 ) ) == V_124 )
F_63 ( & V_122 ) ;
}
void T_1 F_64 ( void )
{
static struct V_114 V_125 [] = {
{
. V_16 = V_126 & 0xfffffffffULL ,
. V_30 = ( V_126 & 0xfffffffffULL ) + 0x100 - 1 ,
. V_62 = V_63 ,
} , {
. V_16 = V_82 + V_127 ,
. V_62 = V_116 ,
} ,
} ;
static struct V_118 V_128 = {
. V_61 = L_19 ,
. V_120 = - 1 ,
. V_121 = F_62 ( V_125 ) ,
. V_114 = V_125 ,
} ;
F_63 ( & V_128 ) ;
}
void T_1 F_65 ( unsigned int V_129 , unsigned int V_130 ,
unsigned char V_86 , unsigned char V_131 )
{
struct V_132 V_133 = {
. V_134 = 1 ,
. V_135 = V_44 ,
. V_129 = V_129 ,
. V_130 = V_130 ,
. V_62 = V_136 | V_137 |
V_138 ,
. V_86 = V_86 ,
. V_131 = V_131 ,
} ;
F_66 ( V_139 & 0xfffffffffULL , & V_133 ) ;
}
void T_1 F_67 ( int V_140 , int V_141 )
{
struct V_142 V_133 = {
. V_143 = true ,
} ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
V_133 . V_144 = V_15 ? V_141 : V_140 ;
F_68 ( V_15 , F_69 ( V_15 ) & 0xfffffffffULL ,
V_82 + F_70 ( V_15 , 0 ) ,
& V_133 ) ;
}
}
void T_1 F_71 ( void )
{
T_2 V_24 = F_43 ( & V_1 -> V_24 ) ;
if ( ( V_24 & V_145 ) == V_146 )
F_72 ( V_147 & 0xfffffffffULL ,
V_82 + V_148 , 1 , 0 , 1 ) ;
}
void T_1 F_73 ( void )
{
if ( V_67 . V_16 )
F_74 ( & V_67 ) ;
}
void T_1 F_75 ( void )
{
static struct V_114 V_125 = {
. V_16 = V_149 & 0xfffffffffULL ,
. V_30 = ( V_149 & 0xfffffffffULL ) + 0x30 - 1 ,
. V_62 = V_63 ,
} ;
static struct V_118 V_150 = {
. V_61 = L_20 ,
. V_120 = - 1 ,
. V_121 = 1 ,
. V_114 = & V_125 ,
} ;
F_63 ( & V_150 ) ;
}
static void T_1 F_76 ( void )
{
T_3 V_24 , V_151 = 0 , V_152 = 0 ;
char V_153 [ 128 ] ;
V_153 [ 0 ] = '\0' ;
F_10 () ;
V_24 = F_2 ( & V_1 -> V_24 ) ;
if ( ( V_24 & V_145 ) !=
V_146 ) {
V_151 |= V_154 ;
V_152 |= V_155 ;
strcat ( V_153 , L_21 ) ;
}
if ( ( V_24 & V_145 ) !=
V_156 &&
( V_24 & V_145 ) !=
V_157 ) {
V_151 |= V_158 ;
V_152 |= V_159 ;
strcat ( V_153 , L_22 ) ;
}
if ( ! ( V_24 & V_123 ) ) {
V_151 |= V_160 ;
V_152 |= V_161 ;
strcat ( V_153 , L_23 ) ;
}
if ( ! ( V_24 & V_124 ) ) {
V_151 |= V_162 ;
V_152 |= V_163 ;
strcat ( V_153 , L_24 ) ;
}
if ( V_24 & V_164 ) {
V_151 |= V_165 ;
V_152 |= V_166 ;
strcat ( V_153 , L_25 ) ;
}
if ( ! ( V_24 & ( V_167 | V_168 ) ) ) {
V_151 |= V_169 ;
V_152 |= V_170 ;
strcat ( V_153 , L_26 ) ;
}
if ( ( V_24 & V_87 ) != V_89 ) {
V_151 |= V_171 ;
V_152 |= V_172 ;
strcat ( V_153 , L_27 ) ;
}
if ( V_24 & V_90 ) {
V_151 |= V_173 ;
V_152 |= V_174 ;
strcat ( V_153 , L_28 ) ;
}
if ( V_151 | V_152 ) {
F_38 ( & V_1 -> V_69 , V_151 ) ;
F_38 ( & V_1 -> V_69 , V_152 ) ;
}
F_77 () ;
if ( V_153 [ 0 ] )
F_35 ( L_29 , V_57 , V_153 ) ;
}
static int T_1 F_78 ( void )
{
if ( V_175 != 0x4939 )
return - V_176 ;
F_76 () ;
return 0 ;
}
