static void F_1 ( void )
{
if ( F_2 ( L_1 ) ) {
V_1 = V_2 ;
return;
}
if ( F_2 ( L_2 ) ) {
V_1 = V_3 ;
return;
}
if ( F_2 ( L_3 ) ) {
V_1 = V_4 ;
return;
}
}
static bool F_3 ( void )
{
if ( V_1 == V_2 )
return true ;
return false ;
}
static bool F_4 ( void )
{
if ( V_1 == V_4 )
return false ;
return true ;
}
static bool F_5 ( void )
{
if ( V_1 == V_4 )
return false ;
return true ;
}
static bool F_6 ( void )
{
if ( V_1 == V_4 )
return false ;
return true ;
}
static bool F_7 ( void )
{
if ( V_1 == V_4 )
return false ;
return true ;
}
static bool F_8 ( void )
{
if ( V_1 == V_4 )
return false ;
return true ;
}
static bool F_9 ( void )
{
if ( V_1 == V_4 )
return false ;
return true ;
}
static bool F_10 ( void )
{
if ( V_1 == V_4 )
return true ;
return false ;
}
static int F_11 ( void )
{
if ( V_1 == V_4 )
return 10 ;
return 12 ;
}
static bool F_12 ( void )
{
if ( V_1 == V_4 )
return true ;
return false ;
}
static bool F_13 ( void )
{
if ( V_1 == V_4 )
return true ;
return false ;
}
static bool F_14 ( void )
{
if ( V_1 == V_4 )
return true ;
return false ;
}
static bool F_15 ( void )
{
if ( V_1 == V_4 )
return true ;
return false ;
}
static bool F_16 ( void )
{
if ( V_1 == V_4 )
return true ;
return false ;
}
static inline struct V_5 * F_17 ( const char * V_6 , int V_7 )
{
return F_18 ( NULL , V_6 , NULL , V_8 , V_7 ) ;
}
static inline struct V_5 * F_19 (
const char * V_6 , const char * V_9 ,
int V_10 , int div )
{
int V_11 ;
V_11 = V_12 ;
return F_20 ( NULL , V_6 , V_9 , V_11 ,
V_10 , div ) ;
}
static inline struct V_5 * F_21 (
const char * V_6 , const char * V_9 , T_1 V_11 ,
T_2 T_3 * V_13 , T_1 V_14 , T_1 V_15 , int V_16 )
{
return F_22 ( NULL , V_6 , V_9 , V_11 ,
V_13 , V_14 , V_15 , V_16 , & V_17 ) ;
}
static inline struct V_5 * F_23 (
const char * V_6 , const char * V_9 ,
T_2 T_3 * V_13 , T_1 V_14 , T_1 V_15 ,
const struct V_18 * V_19 )
{
T_1 V_16 ;
V_16 = 0 ;
return F_24 ( NULL , V_6 , V_9 , 0 ,
V_13 , V_14 , V_15 , V_16 ,
V_19 , & V_17 ) ;
}
static inline struct V_5 * F_25 (
const char * V_6 , const char * V_9 ,
T_2 T_3 * V_13 , T_1 V_14 )
{
int V_11 ;
V_11 = V_12 ;
return F_26 ( NULL , V_6 , V_9 , V_11 ,
V_13 , V_14 , 0 , & V_17 ) ;
}
static inline struct V_5 * F_27 ( const char * V_6 ,
const char * * V_20 , int V_21 ,
T_2 T_3 * V_13 , T_1 V_14 , T_1 V_15 )
{
int V_11 ;
T_1 V_22 ;
V_11 = V_12 ;
V_22 = 0 ;
return F_28 ( NULL , V_6 ,
V_20 , V_21 , V_11 ,
V_13 , V_14 , V_15 , V_22 , & V_17 ) ;
}
static inline int F_29 ( T_4 T_3 * V_13 , T_5 V_14 , T_5 V_15 )
{
T_4 V_23 ;
V_23 = F_30 ( V_13 ) ;
V_23 >>= V_14 ;
V_23 &= ( 1 << V_15 ) - 1 ;
return V_23 ;
}
static int F_31 ( void )
{
static int V_24 [] = {
68 , 1 , 12 , 16 , 20 , 24 , 28 , 32 ,
36 , 40 , 44 , 48 , 52 , 56 , 60 , 64 ,
} ;
int V_25 ;
V_25 = F_29 ( & V_26 -> V_27 , 24 , 4 ) ;
return V_24 [ V_25 ] ;
}
static int F_32 ( void )
{
static int V_28 [] = {
4 , 5 , 6 , 7 , 8 , 9 , 10 , 14 ,
12 , 16 , 18 , 22 , 20 , 24 , 26 , 30 ,
28 , 32 , 34 , 38 , 36 , 40 , 42 , 46 ,
44 , 48 , 50 , 54 , 52 , 56 , 58 , 62 ,
60 , 64 , 66 ,
} ;
int V_29 ;
V_29 = F_29 ( & V_26 -> V_30 , 26 , 6 ) ;
return V_28 [ V_29 ] ;
}
static int F_33 ( void )
{
static int V_31 [] = {
72 , 2 , 2 , 3 , 4 , 5 , 6 , 7 ,
} ;
static int V_32 [] = {
2 , 2 , 2 , 3 , 4 , 5 , 6 , 7 ,
} ;
int * V_33 ;
int V_34 ;
V_34 = F_29 ( & V_26 -> V_27 , 16 , 4 ) ;
if ( F_15 () )
V_33 = V_32 ;
else
V_33 = V_31 ;
return V_33 [ V_34 ] ;
}
static int F_34 ( char * V_35 )
{
struct V_36 * V_37 ;
const unsigned int * V_38 ;
int V_23 ;
V_23 = 0 ;
V_37 = F_35 ( NULL , NULL , L_4 ) ;
if ( V_37 ) {
V_38 = F_36 ( V_37 , V_35 , NULL ) ;
if ( V_38 )
V_23 = * V_38 ;
F_37 ( V_37 ) ;
}
return V_23 ;
}
static void F_38 ( void )
{
T_6 V_39 ;
for ( V_39 = 0 ; V_39 < F_39 ( V_40 ) ; V_39 ++ )
V_40 [ V_39 ] = F_40 ( - V_41 ) ;
}
static void F_41 ( struct V_36 * V_37 , int V_42 ,
int * V_43 , int * V_44 ,
int * V_45 )
{
struct V_5 * V_46 ;
int V_47 ;
* V_43 = F_31 () ;
* V_43 *= 2 ;
* V_44 = F_32 () ;
* V_45 = F_29 ( & V_26 -> V_48 , 23 , 3 ) ;
V_46 = F_42 ( V_37 , L_5 ) ;
if ( ! F_43 ( V_46 ) ) {
V_40 [ V_49 ] = F_19 ( L_6 , L_5 , 1 , 1 ) ;
V_47 = F_44 ( V_40 [ V_49 ] ) ;
V_47 *= * V_43 ;
V_47 /= * V_44 ;
V_47 /= 2 ;
V_47 /= * V_45 ;
if ( V_42 && V_47 != V_42 )
F_45 ( L_7 ,
V_47 , V_42 ) ;
} else {
V_47 = V_42 ;
V_47 *= * V_45 ;
V_47 *= 2 ;
V_47 *= * V_44 ;
V_47 /= * V_43 ;
V_40 [ V_49 ] = F_17 ( L_6 , V_47 ) ;
}
}
static void F_46 ( struct V_50 * V_51 , T_6 V_52 )
{
T_6 V_53 , V_54 ;
T_2 T_3 * V_55 ;
int div ;
switch ( V_51 -> type ) {
case V_56 :
V_53 = V_57 + V_52 ;
V_54 = V_58
+ ( V_52 ) * V_59 ;
V_55 = & V_26 -> V_60 [ V_52 ] ;
break;
case V_61 :
V_53 = V_62 + V_52 ;
V_54 = V_58
+ ( V_63 + V_52 ) * V_59 ;
V_55 = & V_26 -> V_64 [ V_52 ] ;
break;
case V_65 :
V_53 = V_66 ;
V_54 = V_58
+ ( V_63 + V_67 ) * V_59 ;
V_55 = & V_26 -> V_68 ;
break;
case V_69 :
V_53 = V_70 + V_52 ;
V_54 = V_58
+ ( V_63 + V_67 + V_71 + V_52 )
* V_59 ;
V_55 = & V_26 -> V_72 [ V_52 ] ;
break;
default:
return;
}
div = F_44 ( V_40 [ V_73 ] ) ;
div /= F_44 ( V_40 [ V_74 ] ) ;
F_47 ( V_55 , ( 0 << 16 ) ) ;
F_47 ( V_55 , ( 0 << 16 ) | ( ( div - 1 ) << 17 ) ) ;
F_47 ( V_55 , ( 1 << 16 ) | ( ( div - 1 ) << 17 ) ) ;
V_40 [ V_54 + V_75 ] = F_27 (
V_51 -> V_76 ,
F_16 ()
? & V_77 [ 0 ]
: & V_78 [ 0 ] ,
F_39 ( V_78 ) ,
V_55 , 14 , 2 ) ;
V_40 [ V_54 + V_79 ] = F_25 (
V_51 -> V_80 , V_51 -> V_76 ,
V_55 , 16 ) ;
V_40 [ V_54 + V_81 ] = F_21 (
V_51 -> V_82 ,
V_51 -> V_80 , V_83 ,
V_55 , 17 , 15 , 0 ) ;
if ( V_51 -> V_84 ) {
V_40 [ V_53 ] = F_27 (
V_51 -> V_85 ,
& V_51 -> V_86 [ 0 ] ,
F_39 ( V_51 -> V_86 ) ,
V_55 , 7 , 1 ) ;
} else {
V_40 [ V_53 ] = F_19 (
V_51 -> V_85 ,
V_51 -> V_86 [ 0 ] ,
1 , 1 ) ;
}
}
static void F_48 ( struct V_36 * V_37 , int V_87 )
{
int V_43 , V_44 , V_45 ;
int V_10 , div ;
T_6 V_88 ;
int V_89 ;
F_41 ( V_37 , V_87 , & V_43 , & V_44 , & V_45 ) ;
V_40 [ V_73 ] = F_19 ( L_8 , L_6 ,
V_43 , V_44 ) ;
V_40 [ V_90 ] = F_19 ( L_9 , L_8 , 1 , 2 ) ;
V_40 [ V_74 ] = F_23 ( L_10 , L_9 ,
& V_26 -> V_48 , 23 , 3 ,
V_91 ) ;
V_40 [ V_92 ] = F_19 ( L_11 , L_8 , 1 , 2 ) ;
V_40 [ V_93 ] = F_19 ( L_12 , L_9 , 2 , 1 ) ;
V_40 [ V_94 ] = F_21 ( L_13 , L_12 , 0 ,
& V_26 -> V_30 , 1 , 7 ,
V_95 ) ;
if ( F_12 () ) {
V_40 [ V_96 ] = F_21 (
L_14 , L_12 , 0 , & V_26 -> V_30 ,
9 , 7 , V_95 ) ;
}
V_40 [ V_97 ] = F_19 ( L_15 , L_9 , 4 , 1 ) ;
V_40 [ V_98 ] = F_21 ( L_16 , L_15 , 0 ,
& V_26 -> V_48 , 0 , 8 ,
V_95 ) ;
V_10 = F_33 () ;
div = 2 ;
V_40 [ V_99 ] = F_19 ( L_17 , L_9 , V_10 , div ) ;
if ( F_3 () ) {
V_40 [ V_100 ] = F_19 (
L_18 , L_9 , 1 , 2 ) ;
V_40 [ V_101 ] = F_23 (
L_19 , L_18 , & V_26 -> V_48 ,
14 , 3 , V_102 ) ;
V_40 [ V_103 ] = F_19 (
L_20 , L_19 , 1 , 1 ) ;
}
if ( F_9 () ) {
V_40 [ V_104 ] = F_23 (
L_21 , L_9 , & V_26 -> V_48 ,
20 , 3 , V_91 ) ;
}
if ( F_13 () ) {
V_40 [ V_105 ] = F_40 ( - V_106 ) ;
} else {
V_40 [ V_105 ] = F_23 (
L_22 , L_10 , & V_26 -> V_48 ,
8 , 3 , V_102 ) ;
}
V_40 [ V_107 ] = F_23 ( L_23 , L_10 ,
& V_26 -> V_48 , 11 , 3 ,
V_102 ) ;
V_40 [ V_108 ] = F_25 ( L_24 , L_23 ,
& V_26 -> V_109 , 30 ) ;
V_40 [ V_110 ] = F_25 ( L_25 , L_22 ,
& V_26 -> V_109 , 29 ) ;
if ( F_7 () ) {
V_40 [ V_111 ] = F_25 (
L_26 , L_10 , & V_26 -> V_109 , 28 ) ;
}
for ( V_88 = 0 ; V_88 < F_11 () ; V_88 ++ ) {
char V_6 [ 12 ] ;
snprintf ( V_6 , sizeof( V_6 ) , L_27 , V_88 ) ;
V_40 [ V_112 + V_88 ] = F_25 (
V_6 , L_10 , & V_26 -> V_109 , 27 - V_88 ) ;
F_46 ( & V_113 [ V_88 ] , V_88 ) ;
}
V_40 [ V_114 ] = F_25 ( L_28 , L_10 ,
& V_26 -> V_109 , 15 ) ;
if ( F_8 () ) {
V_40 [ V_115 ] = F_25 (
L_29 , L_10 , & V_26 -> V_109 , 14 ) ;
}
V_40 [ V_116 ] = F_25 ( L_30 , L_10 ,
& V_26 -> V_109 , 13 ) ;
if ( F_9 () ) {
V_40 [ V_117 ] = F_25 (
L_31 , L_21 , & V_26 -> V_109 , 11 ) ;
}
V_40 [ V_118 ] = F_25 ( L_32 , L_11 ,
& V_26 -> V_109 , 10 ) ;
if ( F_10 () ) {
V_40 [ V_119 ] = F_25 (
L_33 , L_10 , & V_26 -> V_109 , 9 ) ;
}
V_40 [ V_120 ] = F_25 ( L_34 , L_16 ,
& V_26 -> V_121 , 31 ) ;
if ( F_4 () ) {
V_40 [ V_122 ] = F_25 (
L_35 , L_9 , & V_26 -> V_121 , 30 ) ;
}
V_40 [ V_123 ] = F_25 ( L_36 , L_10 ,
& V_26 -> V_121 , 29 ) ;
V_40 [ V_124 ] = F_25 ( L_37 , L_9 ,
& V_26 -> V_121 , 28 ) ;
V_40 [ V_125 ] = F_25 ( L_38 , L_9 ,
& V_26 -> V_121 , 27 ) ;
V_40 [ V_126 ] = F_25 ( L_39 , L_10 ,
& V_26 -> V_121 , 26 ) ;
V_40 [ V_127 ] = F_25 ( L_40 , L_10 ,
& V_26 -> V_121 , 25 ) ;
for ( V_88 = 0 ; V_88 < F_39 ( V_128 ) ; V_88 ++ )
F_46 ( & V_128 [ V_88 ] , V_88 ) ;
V_40 [ V_129 ] = F_25 ( L_41 , L_13 ,
& V_26 -> V_121 , 24 ) ;
if ( F_6 () ) {
V_40 [ V_130 ] = F_25 (
L_42 , L_10 , & V_26 -> V_121 , 23 ) ;
F_46 ( & V_131 [ 0 ] , 0 ) ;
}
if ( F_3 () ) {
V_40 [ V_132 ] = F_25 (
L_43 , L_18 , & V_26 -> V_121 , 22 ) ;
V_40 [ V_133 ] = F_25 (
L_44 , L_19 , & V_26 -> V_121 , 21 ) ;
V_40 [ V_134 ] = F_25 (
L_45 , L_20 , & V_26 -> V_121 , 20 ) ;
}
V_40 [ V_135 ] = F_25 ( L_46 , L_9 ,
& V_26 -> V_121 , 19 ) ;
if ( F_5 () ) {
V_40 [ V_136 ] = F_25 (
L_47 , L_9 , & V_26 -> V_121 , 18 ) ;
}
if ( F_12 () ) {
V_40 [ V_137 ] = F_25 (
L_48 , L_14 , & V_26 -> V_121 , 17 ) ;
}
if ( F_14 () ) {
T_6 V_52 ;
for ( V_52 = 0 ; V_52 < F_39 ( V_138 ) ; V_52 ++ )
F_46 ( & V_138 [ V_52 ] , V_52 ) ;
}
V_89 = F_34 ( L_49 ) ;
if ( ! V_89 )
V_89 = 25000000 ;
V_40 [ V_139 ] = F_17 ( L_49 , V_89 ) ;
if ( F_16 () ) {
V_89 = F_34 ( L_50 ) ;
V_40 [ V_140 ] = F_17 (
L_50 , V_89 ) ;
} else {
V_89 = F_34 ( L_51 ) ;
V_40 [ V_141 ] = F_17 (
L_51 , V_89 ) ;
V_89 = F_34 ( L_52 ) ;
V_40 [ V_141 ] = F_17 (
L_52 , V_89 ) ;
}
V_40 [ V_142 ] = F_17 ( L_53 , 24567000 ) ;
F_49 ( V_40 [ V_143 ] ) ;
F_49 ( V_40 [ V_99 ] ) ;
F_49 ( V_40 [ V_118 ] ) ;
F_49 ( V_40 [ V_123 ] ) ;
F_49 ( V_40 [ V_74 ] ) ;
F_49 ( V_40 [ V_108 ] ) ;
}
static void F_50 ( struct V_36 * V_37 )
{
V_144 . V_40 = V_40 ;
V_144 . V_145 = V_146 + 1 ;
F_51 ( V_37 , V_147 , & V_144 ) ;
}
static void F_52 ( void )
{
F_49 ( V_40 [ V_148 ] ) ;
if ( F_35 ( NULL , L_31 , L_54 ) )
F_49 ( V_40 [ V_117 ] ) ;
}
static void F_53 ( void )
{
enum T_7 {
V_149 = F_54 ( 0 ) ,
V_150 = F_54 ( 1 ) ,
V_151 = F_54 ( 2 ) ,
V_152 = F_54 ( 3 ) ,
V_153 = F_54 ( 4 ) ,
V_154 = F_54 ( 5 ) ,
V_155 = F_54 ( 6 ) ,
V_156 = F_54 ( 7 ) ,
V_157 = F_54 ( 8 ) ,
V_158 = F_54 ( 9 ) ,
};
int V_159 ;
struct V_36 * V_37 ;
struct V_160 V_161 ;
int V_52 ;
char V_162 [ 32 ] ;
V_159 = 0 ;
F_55 (mpc512x_select_psc_compat()) {
V_163 ;
V_52 = ( V_161 . V_164 >> 8 ) & 0xf ;
F_56 ( L_55 , V_40 [ V_112 + V_52 ] , 0 , V_165 ) ;
F_56 ( L_56 , V_40 [ V_57 + V_52 ] , 0 , V_165 ) ;
}
F_55 ( L_57 ) {
V_163 ;
F_56 ( L_55 , V_40 [ V_114 ] , 1 , V_166 ) ;
}
F_55 ( L_58 ) {
V_163 ;
F_56 ( L_55 , V_40 [ V_110 ] , 0 , V_167 ) ;
}
F_55 ( L_59 ) {
V_163 ;
V_52 = 0 ;
V_52 += ( V_161 . V_164 & 0x2000 ) ? 2 : 0 ;
V_52 += ( V_161 . V_164 & 0x0080 ) ? 1 : 0 ;
F_56 ( L_55 , V_40 [ V_127 ] , 0 , V_168 ) ;
F_56 ( L_56 , V_40 [ V_62 + V_52 ] , 0 , V_168 ) ;
}
if ( V_159 & V_152 ) {
F_57 ( V_40 [ V_74 ] , L_10 , NULL ) ;
F_57 ( V_40 [ V_73 ] , L_8 , NULL ) ;
F_57 ( V_40 [ V_49 ] , L_6 , NULL ) ;
}
F_55 ( L_60 ) {
V_163 ;
F_56 ( L_55 , V_40 [ V_126 ] , 0 , V_169 ) ;
}
if ( V_159 & V_153 )
F_49 ( V_40 [ V_126 ] ) ;
F_55 ( L_61 ) {
V_163 ;
F_56 ( L_55 , V_40 [ V_120 ] , 1 , V_170 ) ;
}
F_55 ( L_62 ) {
V_163 ;
F_56 ( L_55 , V_40 [ V_136 ] , 0 , V_171 ) ;
}
F_55 ( L_63 ) {
V_163 ;
F_56 ( L_64 , V_40 [ V_116 ] , 0 , V_172 ) ;
}
F_55 ( L_65 ) {
V_163 ;
F_56 ( L_64 , V_40 [ V_116 ] , 0 , V_172 ) ;
}
F_55 ( L_66 ) {
V_163 ;
if ( V_161 . V_164 & 0x4000 )
V_52 = V_119 ;
else
V_52 = V_116 ;
F_56 ( L_64 , V_40 [ V_52 ] , 0 , V_172 ) ;
}
F_55 ( L_67 ) {
V_163 ;
V_52 = ( V_161 . V_164 & 0x4000 ) ? 1 : 0 ;
F_56 ( L_55 , V_40 [ V_124 + V_52 ] , 0 , V_173 ) ;
}
F_55 ( L_68 ) {
V_163 ;
F_56 ( L_55 , V_40 [ V_111 ] , 0 , V_174 ) ;
}
if ( V_159 ) {
F_58 ( L_69 ,
V_159 ,
( V_159 & V_149 ) ? L_70 : L_71 ,
( V_159 & V_150 ) ? L_72 : L_71 ,
( V_159 & V_151 ) ? L_73 : L_71 ,
( V_159 & V_152 ) ? L_74 : L_71 ,
( V_159 & V_153 ) ? L_75 : L_71 ,
( V_159 & V_154 ) ? L_76 : L_71 ,
( V_159 & V_155 ) ? L_77 : L_71 ,
( V_159 & V_156 ) ? L_78 : L_71 ,
( V_159 & V_157 ) ? L_79 : L_71 ,
( V_159 & V_158 ) ? L_80 : L_71 ) ;
} else {
F_59 ( L_81 ) ;
}
}
int T_8 F_60 ( void )
{
struct V_36 * V_175 ;
int V_87 ;
V_175 = F_35 ( NULL , NULL , L_82 ) ;
if ( ! V_175 )
return - V_41 ;
V_26 = F_61 ( V_175 , 0 ) ;
F_62 ( ! V_26 ) ;
F_1 () ;
F_38 () ;
F_63 ( NULL ) ;
V_40 [ V_143 ] = F_17 ( L_83 , 0 ) ;
V_87 = F_34 ( L_84 ) ;
F_48 ( V_175 , V_87 ) ;
F_50 ( V_175 ) ;
F_52 () ;
F_53 () ;
return 0 ;
}
