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
return F_18 ( NULL , V_6 , NULL , 0 , V_7 ) ;
}
static inline struct V_5 * F_19 (
const char * V_6 , const char * V_8 ,
int V_9 , int div )
{
int V_10 ;
V_10 = V_11 ;
return F_20 ( NULL , V_6 , V_8 , V_10 ,
V_9 , div ) ;
}
static inline struct V_5 * F_21 (
const char * V_6 , const char * V_8 , T_1 V_10 ,
T_2 T_3 * V_12 , T_1 V_13 , T_1 V_14 , int V_15 )
{
return F_22 ( NULL , V_6 , V_8 , V_10 ,
V_12 , V_13 , V_14 , V_15 , & V_16 ) ;
}
static inline struct V_5 * F_23 (
const char * V_6 , const char * V_8 ,
T_2 T_3 * V_12 , T_1 V_13 , T_1 V_14 ,
const struct V_17 * V_18 )
{
T_1 V_15 ;
V_15 = 0 ;
return F_24 ( NULL , V_6 , V_8 , 0 ,
V_12 , V_13 , V_14 , V_15 ,
V_18 , & V_16 ) ;
}
static inline struct V_5 * F_25 (
const char * V_6 , const char * V_8 ,
T_2 T_3 * V_12 , T_1 V_13 )
{
int V_10 ;
V_10 = V_11 ;
return F_26 ( NULL , V_6 , V_8 , V_10 ,
V_12 , V_13 , 0 , & V_16 ) ;
}
static inline struct V_5 * F_27 ( const char * V_6 ,
const char * * V_19 , int V_20 ,
T_2 T_3 * V_12 , T_1 V_13 , T_1 V_14 )
{
int V_10 ;
T_1 V_21 ;
V_10 = V_11 ;
V_21 = 0 ;
return F_28 ( NULL , V_6 ,
V_19 , V_20 , V_10 ,
V_12 , V_13 , V_14 , V_21 , & V_16 ) ;
}
static inline int F_29 ( T_4 T_3 * V_12 , T_5 V_13 , T_5 V_14 )
{
T_4 V_22 ;
V_22 = F_30 ( V_12 ) ;
V_22 >>= V_13 ;
V_22 &= ( 1 << V_14 ) - 1 ;
return V_22 ;
}
static int F_31 ( void )
{
static int V_23 [] = {
68 , 1 , 12 , 16 , 20 , 24 , 28 , 32 ,
36 , 40 , 44 , 48 , 52 , 56 , 60 , 64 ,
} ;
int V_24 ;
V_24 = F_29 ( & V_25 -> V_26 , 24 , 4 ) ;
return V_23 [ V_24 ] ;
}
static int F_32 ( void )
{
static int V_27 [] = {
4 , 5 , 6 , 7 , 8 , 9 , 10 , 14 ,
12 , 16 , 18 , 22 , 20 , 24 , 26 , 30 ,
28 , 32 , 34 , 38 , 36 , 40 , 42 , 46 ,
44 , 48 , 50 , 54 , 52 , 56 , 58 , 62 ,
60 , 64 , 66 ,
} ;
int V_28 ;
V_28 = F_29 ( & V_25 -> V_29 , 26 , 6 ) ;
return V_27 [ V_28 ] ;
}
static int F_33 ( void )
{
static int V_30 [] = {
72 , 2 , 2 , 3 , 4 , 5 , 6 , 7 ,
} ;
static int V_31 [] = {
2 , 2 , 2 , 3 , 4 , 5 , 6 , 7 ,
} ;
int * V_32 ;
int V_33 ;
V_33 = F_29 ( & V_25 -> V_26 , 16 , 4 ) ;
if ( F_15 () )
V_32 = V_31 ;
else
V_32 = V_30 ;
return V_32 [ V_33 ] ;
}
static int F_34 ( char * V_34 )
{
struct V_35 * V_36 ;
const unsigned int * V_37 ;
int V_22 ;
V_22 = 0 ;
V_36 = F_35 ( NULL , NULL , L_4 ) ;
if ( V_36 ) {
V_37 = F_36 ( V_36 , V_34 , NULL ) ;
if ( V_37 )
V_22 = * V_37 ;
F_37 ( V_36 ) ;
}
return V_22 ;
}
static void F_38 ( void )
{
T_6 V_38 ;
for ( V_38 = 0 ; V_38 < F_39 ( V_39 ) ; V_38 ++ )
V_39 [ V_38 ] = F_40 ( - V_40 ) ;
}
static void F_41 ( struct V_35 * V_36 , int V_41 ,
int * V_42 , int * V_43 ,
int * V_44 )
{
struct V_5 * V_45 ;
int V_46 ;
* V_42 = F_31 () ;
* V_42 *= 2 ;
* V_43 = F_32 () ;
* V_44 = F_29 ( & V_25 -> V_47 , 23 , 3 ) ;
V_45 = F_42 ( V_36 , L_5 ) ;
if ( ! F_43 ( V_45 ) ) {
V_39 [ V_48 ] = F_19 ( L_6 , L_5 , 1 , 1 ) ;
V_46 = F_44 ( V_39 [ V_48 ] ) ;
V_46 *= * V_42 ;
V_46 /= * V_43 ;
V_46 /= 2 ;
V_46 /= * V_44 ;
if ( V_41 && V_46 != V_41 )
F_45 ( L_7 ,
V_46 , V_41 ) ;
} else {
V_46 = V_41 ;
V_46 *= * V_44 ;
V_46 *= 2 ;
V_46 *= * V_43 ;
V_46 /= * V_42 ;
V_39 [ V_48 ] = F_17 ( L_6 , V_46 ) ;
}
}
static void F_46 ( struct V_49 * V_50 , T_6 V_51 )
{
T_6 V_52 , V_53 ;
T_2 T_3 * V_54 ;
int div ;
switch ( V_50 -> type ) {
case V_55 :
V_52 = V_56 + V_51 ;
V_53 = V_57
+ ( V_51 ) * V_58 ;
V_54 = & V_25 -> V_59 [ V_51 ] ;
break;
case V_60 :
V_52 = V_61 + V_51 ;
V_53 = V_57
+ ( V_62 + V_51 ) * V_58 ;
V_54 = & V_25 -> V_63 [ V_51 ] ;
break;
case V_64 :
V_52 = V_65 ;
V_53 = V_57
+ ( V_62 + V_66 ) * V_58 ;
V_54 = & V_25 -> V_67 ;
break;
case V_68 :
V_52 = V_69 + V_51 ;
V_53 = V_57
+ ( V_62 + V_66 + V_70 + V_51 )
* V_58 ;
V_54 = & V_25 -> V_71 [ V_51 ] ;
break;
default:
return;
}
div = F_44 ( V_39 [ V_72 ] ) ;
div /= F_44 ( V_39 [ V_73 ] ) ;
F_47 ( V_54 , ( 0 << 16 ) ) ;
F_47 ( V_54 , ( 0 << 16 ) | ( ( div - 1 ) << 17 ) ) ;
F_47 ( V_54 , ( 1 << 16 ) | ( ( div - 1 ) << 17 ) ) ;
V_39 [ V_53 + V_74 ] = F_27 (
V_50 -> V_75 ,
F_16 ()
? & V_76 [ 0 ]
: & V_77 [ 0 ] ,
F_39 ( V_77 ) ,
V_54 , 14 , 2 ) ;
V_39 [ V_53 + V_78 ] = F_25 (
V_50 -> V_79 , V_50 -> V_75 ,
V_54 , 16 ) ;
V_39 [ V_53 + V_80 ] = F_21 (
V_50 -> V_81 ,
V_50 -> V_79 , V_82 ,
V_54 , 17 , 15 , 0 ) ;
if ( V_50 -> V_83 ) {
V_39 [ V_52 ] = F_27 (
V_50 -> V_84 ,
& V_50 -> V_85 [ 0 ] ,
F_39 ( V_50 -> V_85 ) ,
V_54 , 7 , 1 ) ;
} else {
V_39 [ V_52 ] = F_19 (
V_50 -> V_84 ,
V_50 -> V_85 [ 0 ] ,
1 , 1 ) ;
}
}
static void F_48 ( struct V_35 * V_36 , int V_86 )
{
int V_42 , V_43 , V_44 ;
int V_9 , div ;
T_6 V_87 ;
int V_88 ;
F_41 ( V_36 , V_86 , & V_42 , & V_43 , & V_44 ) ;
V_39 [ V_72 ] = F_19 ( L_8 , L_6 ,
V_42 , V_43 ) ;
V_39 [ V_89 ] = F_19 ( L_9 , L_8 , 1 , 2 ) ;
V_39 [ V_73 ] = F_23 ( L_10 , L_9 ,
& V_25 -> V_47 , 23 , 3 ,
V_90 ) ;
V_39 [ V_91 ] = F_19 ( L_11 , L_8 , 1 , 2 ) ;
V_39 [ V_92 ] = F_19 ( L_12 , L_9 , 2 , 1 ) ;
V_39 [ V_93 ] = F_21 ( L_13 , L_12 , 0 ,
& V_25 -> V_29 , 1 , 7 ,
V_94 ) ;
if ( F_12 () ) {
V_39 [ V_95 ] = F_21 (
L_14 , L_12 , 0 , & V_25 -> V_29 ,
9 , 7 , V_94 ) ;
}
V_39 [ V_96 ] = F_19 ( L_15 , L_9 , 4 , 1 ) ;
V_39 [ V_97 ] = F_21 ( L_16 , L_15 , 0 ,
& V_25 -> V_47 , 0 , 8 ,
V_94 ) ;
V_9 = F_33 () ;
div = 2 ;
V_39 [ V_98 ] = F_19 ( L_17 , L_9 , V_9 , div ) ;
if ( F_3 () ) {
V_39 [ V_99 ] = F_19 (
L_18 , L_9 , 1 , 2 ) ;
V_39 [ V_100 ] = F_23 (
L_19 , L_18 , & V_25 -> V_47 ,
14 , 3 , V_101 ) ;
V_39 [ V_102 ] = F_19 (
L_20 , L_19 , 1 , 1 ) ;
}
if ( F_9 () ) {
V_39 [ V_103 ] = F_23 (
L_21 , L_9 , & V_25 -> V_47 ,
20 , 3 , V_90 ) ;
}
if ( F_13 () ) {
V_39 [ V_104 ] = F_40 ( - V_105 ) ;
} else {
V_39 [ V_104 ] = F_23 (
L_22 , L_10 , & V_25 -> V_47 ,
8 , 3 , V_101 ) ;
}
V_39 [ V_106 ] = F_23 ( L_23 , L_10 ,
& V_25 -> V_47 , 11 , 3 ,
V_101 ) ;
V_39 [ V_107 ] = F_25 ( L_24 , L_23 ,
& V_25 -> V_108 , 30 ) ;
V_39 [ V_109 ] = F_25 ( L_25 , L_22 ,
& V_25 -> V_108 , 29 ) ;
if ( F_7 () ) {
V_39 [ V_110 ] = F_25 (
L_26 , L_10 , & V_25 -> V_108 , 28 ) ;
}
for ( V_87 = 0 ; V_87 < F_11 () ; V_87 ++ ) {
char V_6 [ 12 ] ;
snprintf ( V_6 , sizeof( V_6 ) , L_27 , V_87 ) ;
V_39 [ V_111 + V_87 ] = F_25 (
V_6 , L_10 , & V_25 -> V_108 , 27 - V_87 ) ;
F_46 ( & V_112 [ V_87 ] , V_87 ) ;
}
V_39 [ V_113 ] = F_25 ( L_28 , L_10 ,
& V_25 -> V_108 , 15 ) ;
if ( F_8 () ) {
V_39 [ V_114 ] = F_25 (
L_29 , L_10 , & V_25 -> V_108 , 14 ) ;
}
V_39 [ V_115 ] = F_25 ( L_30 , L_10 ,
& V_25 -> V_108 , 13 ) ;
if ( F_9 () ) {
V_39 [ V_116 ] = F_25 (
L_31 , L_21 , & V_25 -> V_108 , 11 ) ;
}
V_39 [ V_117 ] = F_25 ( L_32 , L_11 ,
& V_25 -> V_108 , 10 ) ;
if ( F_10 () ) {
V_39 [ V_118 ] = F_25 (
L_33 , L_10 , & V_25 -> V_108 , 9 ) ;
}
V_39 [ V_119 ] = F_25 ( L_34 , L_16 ,
& V_25 -> V_120 , 31 ) ;
if ( F_4 () ) {
V_39 [ V_121 ] = F_25 (
L_35 , L_9 , & V_25 -> V_120 , 30 ) ;
}
V_39 [ V_122 ] = F_25 ( L_36 , L_10 ,
& V_25 -> V_120 , 29 ) ;
V_39 [ V_123 ] = F_25 ( L_37 , L_9 ,
& V_25 -> V_120 , 28 ) ;
V_39 [ V_124 ] = F_25 ( L_38 , L_9 ,
& V_25 -> V_120 , 27 ) ;
V_39 [ V_125 ] = F_25 ( L_39 , L_10 ,
& V_25 -> V_120 , 26 ) ;
V_39 [ V_126 ] = F_25 ( L_40 , L_10 ,
& V_25 -> V_120 , 25 ) ;
for ( V_87 = 0 ; V_87 < F_39 ( V_127 ) ; V_87 ++ )
F_46 ( & V_127 [ V_87 ] , V_87 ) ;
V_39 [ V_128 ] = F_25 ( L_41 , L_13 ,
& V_25 -> V_120 , 24 ) ;
if ( F_6 () ) {
V_39 [ V_129 ] = F_25 (
L_42 , L_10 , & V_25 -> V_120 , 23 ) ;
F_46 ( & V_130 [ 0 ] , 0 ) ;
}
if ( F_3 () ) {
V_39 [ V_131 ] = F_25 (
L_43 , L_18 , & V_25 -> V_120 , 22 ) ;
V_39 [ V_132 ] = F_25 (
L_44 , L_19 , & V_25 -> V_120 , 21 ) ;
V_39 [ V_133 ] = F_25 (
L_45 , L_20 , & V_25 -> V_120 , 20 ) ;
}
V_39 [ V_134 ] = F_25 ( L_46 , L_9 ,
& V_25 -> V_120 , 19 ) ;
if ( F_5 () ) {
V_39 [ V_135 ] = F_25 (
L_47 , L_9 , & V_25 -> V_120 , 18 ) ;
}
if ( F_12 () ) {
V_39 [ V_136 ] = F_25 (
L_48 , L_14 , & V_25 -> V_120 , 17 ) ;
}
if ( F_14 () ) {
T_6 V_51 ;
for ( V_51 = 0 ; V_51 < F_39 ( V_137 ) ; V_51 ++ )
F_46 ( & V_137 [ V_51 ] , V_51 ) ;
}
V_88 = F_34 ( L_49 ) ;
if ( ! V_88 )
V_88 = 25000000 ;
V_39 [ V_138 ] = F_17 ( L_49 , V_88 ) ;
if ( F_16 () ) {
V_88 = F_34 ( L_50 ) ;
V_39 [ V_139 ] = F_17 (
L_50 , V_88 ) ;
} else {
V_88 = F_34 ( L_51 ) ;
V_39 [ V_140 ] = F_17 (
L_51 , V_88 ) ;
V_88 = F_34 ( L_52 ) ;
V_39 [ V_140 ] = F_17 (
L_52 , V_88 ) ;
}
V_39 [ V_141 ] = F_17 ( L_53 , 24567000 ) ;
F_49 ( V_39 [ V_142 ] ) ;
F_49 ( V_39 [ V_98 ] ) ;
F_49 ( V_39 [ V_117 ] ) ;
F_49 ( V_39 [ V_122 ] ) ;
F_49 ( V_39 [ V_73 ] ) ;
F_49 ( V_39 [ V_107 ] ) ;
}
static void F_50 ( struct V_35 * V_36 )
{
V_143 . V_39 = V_39 ;
V_143 . V_144 = V_145 + 1 ;
F_51 ( V_36 , V_146 , & V_143 ) ;
}
static void F_52 ( void )
{
F_49 ( V_39 [ V_147 ] ) ;
if ( F_35 ( NULL , L_31 , L_54 ) )
F_49 ( V_39 [ V_116 ] ) ;
}
static void F_53 ( void )
{
enum T_7 {
V_148 = F_54 ( 0 ) ,
V_149 = F_54 ( 1 ) ,
V_150 = F_54 ( 2 ) ,
V_151 = F_54 ( 3 ) ,
V_152 = F_54 ( 4 ) ,
V_153 = F_54 ( 5 ) ,
V_154 = F_54 ( 6 ) ,
V_155 = F_54 ( 7 ) ,
V_156 = F_54 ( 8 ) ,
V_157 = F_54 ( 9 ) ,
};
int V_158 ;
struct V_35 * V_36 ;
struct V_159 V_160 ;
int V_51 ;
char V_161 [ 32 ] ;
V_158 = 0 ;
F_55 (mpc512x_select_psc_compat()) {
V_162 ;
V_51 = ( V_160 . V_163 >> 8 ) & 0xf ;
F_56 ( L_55 , V_39 [ V_111 + V_51 ] , 0 , V_164 ) ;
F_56 ( L_56 , V_39 [ V_56 + V_51 ] , 0 , V_164 ) ;
}
F_55 ( L_57 ) {
V_162 ;
F_56 ( L_55 , V_39 [ V_113 ] , 1 , V_165 ) ;
}
F_55 ( L_58 ) {
V_162 ;
F_56 ( L_55 , V_39 [ V_109 ] , 0 , V_166 ) ;
}
F_55 ( L_59 ) {
V_162 ;
V_51 = 0 ;
V_51 += ( V_160 . V_163 & 0x2000 ) ? 2 : 0 ;
V_51 += ( V_160 . V_163 & 0x0080 ) ? 1 : 0 ;
F_56 ( L_55 , V_39 [ V_126 ] , 0 , V_167 ) ;
F_56 ( L_56 , V_39 [ V_61 + V_51 ] , 0 , V_167 ) ;
}
if ( V_158 & V_151 ) {
F_57 ( V_39 [ V_73 ] , L_10 , NULL ) ;
F_57 ( V_39 [ V_72 ] , L_8 , NULL ) ;
F_57 ( V_39 [ V_48 ] , L_6 , NULL ) ;
}
F_55 ( L_60 ) {
V_162 ;
F_56 ( L_55 , V_39 [ V_125 ] , 0 , V_168 ) ;
}
if ( V_158 & V_152 )
F_49 ( V_39 [ V_125 ] ) ;
F_55 ( L_61 ) {
V_162 ;
F_56 ( L_55 , V_39 [ V_119 ] , 1 , V_169 ) ;
}
F_55 ( L_62 ) {
V_162 ;
F_56 ( L_55 , V_39 [ V_135 ] , 0 , V_170 ) ;
}
F_55 ( L_63 ) {
V_162 ;
F_56 ( L_64 , V_39 [ V_115 ] , 0 , V_171 ) ;
}
F_55 ( L_65 ) {
V_162 ;
F_56 ( L_64 , V_39 [ V_115 ] , 0 , V_171 ) ;
}
F_55 ( L_66 ) {
V_162 ;
if ( V_160 . V_163 & 0x4000 )
V_51 = V_118 ;
else
V_51 = V_115 ;
F_56 ( L_64 , V_39 [ V_51 ] , 0 , V_171 ) ;
}
F_55 ( L_67 ) {
V_162 ;
V_51 = ( V_160 . V_163 & 0x4000 ) ? 1 : 0 ;
F_56 ( L_55 , V_39 [ V_123 + V_51 ] , 0 , V_172 ) ;
}
F_55 ( L_68 ) {
V_162 ;
F_56 ( L_55 , V_39 [ V_110 ] , 0 , V_173 ) ;
}
if ( V_158 ) {
F_58 ( L_69 ,
V_158 ,
( V_158 & V_148 ) ? L_70 : L_71 ,
( V_158 & V_149 ) ? L_72 : L_71 ,
( V_158 & V_150 ) ? L_73 : L_71 ,
( V_158 & V_151 ) ? L_74 : L_71 ,
( V_158 & V_152 ) ? L_75 : L_71 ,
( V_158 & V_153 ) ? L_76 : L_71 ,
( V_158 & V_154 ) ? L_77 : L_71 ,
( V_158 & V_155 ) ? L_78 : L_71 ,
( V_158 & V_156 ) ? L_79 : L_71 ,
( V_158 & V_157 ) ? L_80 : L_71 ) ;
} else {
F_59 ( L_81 ) ;
}
}
int T_8 F_60 ( void )
{
struct V_35 * V_174 ;
int V_86 ;
V_174 = F_35 ( NULL , NULL , L_82 ) ;
if ( ! V_174 )
return - V_40 ;
V_25 = F_61 ( V_174 , 0 ) ;
F_62 ( ! V_25 ) ;
F_1 () ;
F_38 () ;
V_39 [ V_142 ] = F_17 ( L_83 , 0 ) ;
V_86 = F_34 ( L_84 ) ;
F_48 ( V_174 , V_86 ) ;
F_50 ( V_174 ) ;
F_52 () ;
F_53 () ;
return 0 ;
}
