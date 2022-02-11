static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , int V_5 )
{
V_2 -> V_6 . V_7 = V_3 ;
V_2 -> V_8 = F_2 ( V_3 , 1 , V_4 , V_5 ) ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 ;
if ( V_2 -> V_8 ) {
const struct V_12 * V_13 ;
for ( V_13 = V_14 ; V_13 -> V_15 ; V_13 ++ ) {
struct V_16 * V_17 ;
V_17 = F_4 ( V_13 , V_10 ) ;
if ( ! V_17 )
return - V_18 ;
V_17 -> V_19 = V_2 -> V_8 ;
V_11 = F_5 ( V_10 , 0 , V_17 ) ;
if ( V_11 < 0 )
return V_11 ;
}
}
return 0 ;
}
static int F_6 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
return F_7 ( V_10 , & V_2 -> V_24 , V_23 ,
V_21 ) ;
}
static int F_8 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
unsigned int V_25 ,
unsigned int V_26 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
return F_9 ( V_10 , & V_2 -> V_24 ,
V_25 ,
V_26 , V_23 ) ;
}
static int F_10 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
return F_11 ( V_10 , & V_2 -> V_24 ) ;
}
static int F_12 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
return F_13 ( V_10 , & V_2 -> V_24 ) ;
}
static int F_14 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
return F_15 ( V_10 , & V_2 -> V_24 ) ;
}
static int F_16 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
unsigned int V_25 ,
unsigned int V_26 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
return F_17 ( V_10 , & V_2 -> V_24 ,
V_25 ,
V_26 , V_23 ) ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
unsigned int V_25 ,
unsigned int V_26 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_19 ( V_10 , V_2 -> V_27 [ V_23 -> V_28 ] ,
V_25 , 0 , V_26 ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( V_10 , V_2 -> V_27 [ V_23 -> V_28 ] ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
unsigned int V_25 ,
unsigned int V_26 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_29 = V_2 -> V_27 [ V_2 -> V_30 ] ;
V_2 -> V_31 = V_25 ;
V_2 -> V_32 = V_26 ;
F_19 ( V_10 , V_2 -> V_29 , V_25 , 0 , V_26 ) ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( V_10 , V_2 -> V_29 ) ;
V_2 -> V_29 = 0 ;
return 0 ;
}
static int F_24 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_33 * V_34 = V_2 -> V_35 ;
V_10 -> V_36 = 1 ;
V_10 -> V_37 = V_34 ;
V_34 -> V_15 = L_1 ;
V_34 -> V_38 [ V_39 ] = V_40 ;
V_34 -> V_38 [ V_39 ] . V_41 =
V_2 -> V_24 . V_42 ;
V_34 -> V_38 [ V_39 ] . V_3 =
V_2 -> V_24 . V_43 [ 0 ] ;
if ( V_2 -> V_44 )
V_34 -> V_38 [ V_45 ] = * V_2 -> V_44 ;
else {
if ( V_10 -> V_46 == 0x14f15051 )
V_34 -> V_38 [ V_45 ] =
V_47 ;
else {
V_34 -> V_38 [ V_45 ] =
V_48 ;
V_34 -> V_38 [ V_45 ] . V_49 =
V_2 -> V_50 ;
}
}
V_34 -> V_38 [ V_45 ] . V_3 = V_2 -> V_27 [ 0 ] ;
if ( V_2 -> V_24 . V_51 ) {
V_34 ++ ;
V_10 -> V_36 ++ ;
V_34 -> V_15 = L_2 ;
V_34 -> V_52 = V_53 ;
V_34 -> V_38 [ V_39 ] =
V_54 ;
V_34 -> V_38 [ V_39 ] . V_3 =
V_2 -> V_24 . V_51 ;
if ( V_2 -> V_55 ) {
V_34 -> V_38 [ V_45 ] =
V_56 ;
V_34 -> V_38 [ V_45 ] . V_3 =
V_2 -> V_55 ;
}
}
return 0 ;
}
static int F_25 ( struct V_16 * V_57 ,
struct V_58 * V_59 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
return F_27 ( V_2 -> V_60 , V_59 ) ;
}
static int F_28 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_63 = F_29 ( V_57 , & V_62 -> V_64 ) ;
V_62 -> V_65 . V_66 . V_67 [ 0 ] = V_2 -> V_68 [ V_63 ] ;
return 0 ;
}
static int F_30 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_63 = F_29 ( V_57 , & V_62 -> V_64 ) ;
return F_31 ( V_10 , V_2 -> V_60 , V_62 ,
V_2 -> V_69 [ V_63 ] ,
& V_2 -> V_68 [ V_63 ] ) ;
}
static void F_32 ( struct V_9 * V_10 , T_1 V_70 ,
unsigned int V_71 )
{
if ( V_71 == V_72 )
F_33 ( 100 ) ;
F_34 ( V_10 , V_70 , 0 , V_73 ,
V_71 ) ;
if ( V_71 == V_74 )
F_33 ( 10 ) ;
F_35 ( V_10 , V_70 , V_71 ) ;
}
static int F_36 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_76 ; V_75 ++ )
F_37 ( V_10 , V_2 -> V_77 [ V_75 ] ) ;
return 0 ;
}
static void F_38 ( struct V_9 * V_10 )
{
F_39 ( V_10 -> V_2 ) ;
}
static int F_40 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_75 ;
int V_11 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_78 ; V_75 ++ ) {
V_11 = F_41 ( V_10 , V_2 -> V_79 [ V_75 ] ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_2 -> V_24 . V_51 ) {
V_11 = F_42 ( V_10 ,
V_2 -> V_24 . V_51 ,
V_2 -> V_24 . V_51 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_43 ( V_10 ,
& V_2 -> V_24 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_24 . V_80 = 1 ;
}
if ( V_2 -> V_55 ) {
V_11 = F_44 ( V_10 , V_2 -> V_55 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_2 -> V_81 &&
! F_45 ( V_10 , L_3 ) ) {
unsigned int V_82 [ 4 ] ;
F_46 ( V_10 , V_2 -> V_81 ,
V_83 , V_82 ) ;
V_11 = F_47 ( V_10 , L_3 ,
V_82 , V_84 ,
L_4 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_2 -> V_81 &&
! F_45 ( V_10 , L_5 ) ) {
V_11 = F_47 ( V_10 , L_5 ,
NULL , V_84 ,
L_6 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_2 -> V_60 ) {
V_11 = F_41 ( V_10 , V_85 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_11 = F_3 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_48 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_86 = ( V_57 -> V_19 >> 8 ) & 1 ;
if ( V_86 )
V_62 -> V_65 . integer . V_65 [ 0 ] = ! V_2 -> V_87 ;
else
V_62 -> V_65 . integer . V_65 [ 0 ] = V_2 -> V_87 ;
return 0 ;
}
static int F_49 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_86 = ( V_57 -> V_19 >> 8 ) & 1 ;
T_1 V_3 = V_57 -> V_19 & 0xff ;
unsigned int V_88 ;
V_88 = ! ! V_62 -> V_65 . integer . V_65 [ 0 ] ;
if ( V_86 )
V_88 = ! V_88 ;
if ( V_88 == V_2 -> V_87 )
return 0 ;
V_2 -> V_87 = V_88 ;
F_50 ( V_10 , V_3 ,
0 , V_89 ,
V_88 ? 0x02 : 0x00 ) ;
return 1 ;
}
static int F_51 ( struct V_16 * V_57 ,
struct V_58 * V_59 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
return F_52 ( V_10 , V_59 , V_2 -> V_90 ,
V_2 -> V_91 ) ;
}
static int F_53 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
return F_54 ( V_10 , V_62 , V_2 -> V_90 ,
V_2 -> V_91 ,
V_2 -> V_24 . V_42 ) ;
}
static int F_55 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 = F_56 ( V_10 , V_62 , V_2 -> V_90 ,
V_2 -> V_91 ,
& V_2 -> V_24 . V_42 ) ;
return V_11 ;
}
static int F_57 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_92 ;
if ( ! F_49 ( V_57 , V_62 ) )
return 0 ;
V_92 = ( ! V_2 -> V_93 && V_2 -> V_87 ) ? 0 : V_94 ;
F_58 ( V_10 , 0x10 , V_83 , 0 ,
V_94 , V_92 ) ;
V_92 = V_2 -> V_87 ? 0 : V_94 ;
F_58 ( V_10 , 0x11 , V_83 , 0 ,
V_94 , V_92 ) ;
return 1 ;
}
static void F_59 ( struct V_9 * V_10 )
{
static const struct V_95 V_96 [] = {
{ 0x14 , V_97 , 0xb080 } ,
{ 0x12 , V_97 , 0xb000 } ,
{}
} ;
static const struct V_95 V_98 [] = {
{ 0x12 , V_97 , 0xb080 } ,
{ 0x14 , V_97 , 0xb000 } ,
{}
} ;
unsigned int V_99 ;
V_99 = F_60 ( V_10 , 0x12 ) ;
if ( V_99 )
F_37 ( V_10 , V_96 ) ;
else
F_37 ( V_10 , V_98 ) ;
}
static void F_61 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_92 ;
V_2 -> V_93 = F_60 ( V_10 , 0x11 ) ;
V_92 = ( V_2 -> V_93 || ! V_2 -> V_87 ) ? V_94 : 0 ;
F_58 ( V_10 , 0x10 , V_83 , 0 ,
V_94 , V_92 ) ;
}
static void F_62 ( struct V_9 * V_10 ,
unsigned int V_100 )
{
V_100 >>= 26 ;
switch ( V_100 ) {
case V_101 :
F_61 ( V_10 ) ;
break;
case V_102 :
F_59 ( V_10 ) ;
break;
}
}
static int F_63 ( struct V_9 * V_10 )
{
F_36 ( V_10 ) ;
F_61 ( V_10 ) ;
return 0 ;
}
static int F_64 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_103 ;
V_103 = F_65 ( V_10 , V_104 ,
V_105 ,
V_106 ) ;
if ( V_103 < 0 )
V_103 = V_107 ;
if ( V_103 == V_107 )
return F_66 ( V_10 ) ;
V_2 = F_67 ( sizeof( * V_2 ) , V_108 ) ;
if ( ! V_2 )
return - V_18 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_109 = 1 ;
V_2 -> V_24 . V_42 = 2 ;
V_2 -> V_24 . V_110 = F_68 ( V_111 ) ;
V_2 -> V_24 . V_43 = V_111 ;
V_2 -> V_24 . V_51 = V_112 ;
V_2 -> V_50 = 1 ;
V_2 -> V_27 = V_113 ;
V_2 -> V_69 = V_114 ;
V_2 -> V_60 = & V_115 ;
V_2 -> V_78 = 1 ;
V_2 -> V_79 [ 0 ] = V_116 ;
V_2 -> V_76 = 1 ;
V_2 -> V_77 [ 0 ] = V_117 ;
V_2 -> V_118 = 0 ;
V_2 -> V_91 = F_68 ( V_119 ) ;
V_2 -> V_90 = V_119 ;
F_1 ( V_2 , 0x16 , 0 , 1 ) ;
V_10 -> V_120 = V_121 ;
switch ( V_103 ) {
case V_122 :
V_10 -> V_120 . V_123 = F_62 ;
V_2 -> V_60 = & V_115 ;
V_2 -> V_76 = 2 ;
V_2 -> V_77 [ 1 ] = V_124 ;
V_2 -> V_79 [ 0 ] = V_116 ;
V_10 -> V_120 . V_125 = F_63 ;
break;
case V_126 :
V_10 -> V_120 . V_123 = F_62 ;
V_2 -> V_60 = & V_115 ;
V_2 -> V_76 = 2 ;
V_2 -> V_77 [ 1 ] = V_127 ;
V_2 -> V_79 [ 0 ] = V_116 ;
V_10 -> V_120 . V_125 = F_63 ;
break;
default:
case V_128 :
V_10 -> V_120 . V_123 = F_62 ;
V_2 -> V_60 = & V_115 ;
V_2 -> V_76 = 3 ;
V_2 -> V_77 [ 1 ] = V_124 ;
V_2 -> V_77 [ 2 ] = V_127 ;
V_2 -> V_79 [ 0 ] = V_116 ;
V_10 -> V_120 . V_125 = F_63 ;
break;
case V_129 :
V_10 -> V_120 . V_123 = F_62 ;
V_2 -> V_60 = & V_130 ;
V_2 -> V_76 = 1 ;
V_2 -> V_77 [ 0 ] = V_131 ;
V_2 -> V_79 [ 0 ] = V_116 ;
V_2 -> V_79 [ 1 ] = V_132 ;
V_2 -> V_78 = 2 ;
V_10 -> V_120 . V_125 = F_63 ;
break;
#ifdef F_69
case V_133 :
V_2 -> V_60 = & V_134 ;
V_2 -> V_79 [ 0 ] = V_135 ;
V_2 -> V_77 [ 0 ] = V_136 ;
break;
#endif
}
switch ( V_10 -> V_137 >> 16 ) {
case 0x103c :
case 0x1631 :
case 0x1734 :
case 0x17aa :
F_70 ( V_10 , 0x17 , V_138 ,
( 0x14 << V_139 ) |
( 0x14 << V_140 ) |
( 0x05 << V_141 ) |
( 1 << V_142 ) ) ;
break;
}
if ( V_2 -> V_8 )
F_71 ( V_10 , F_72 ( V_2 -> V_8 ) ) ;
return 0 ;
}
static int F_73 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_92 ;
if ( ! F_49 ( V_57 , V_62 ) )
return 0 ;
V_92 = ( ! V_2 -> V_93 && V_2 -> V_87 ) ? 0 : V_94 ;
F_58 ( V_10 , 0x1d , V_83 , 0x01 ,
V_94 , V_92 ) ;
V_92 = V_2 -> V_87 ? 0 : V_94 ;
F_58 ( V_10 , 0x13 , V_83 , 0 ,
V_94 , V_92 ) ;
return 1 ;
}
static void F_74 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_92 ;
V_2 -> V_93 = F_60 ( V_10 , 0x13 ) ;
V_92 = ( V_2 -> V_93 || ! V_2 -> V_87 ) ? V_94 : 0 ;
F_58 ( V_10 , 0x1d , V_83 , 0x01 ,
V_94 , V_92 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
static const struct V_95 V_96 [] = {
{ 0x15 , V_97 , V_143 } ,
{ 0x17 , V_97 , V_144 } ,
{}
} ;
static const struct V_95 V_98 [] = {
{ 0x17 , V_97 , V_143 } ,
{ 0x15 , V_97 , V_144 } ,
{}
} ;
unsigned int V_99 ;
V_99 = F_60 ( V_10 , 0x15 ) ;
if ( V_99 )
F_37 ( V_10 , V_96 ) ;
else
F_37 ( V_10 , V_98 ) ;
}
static void F_76 ( struct V_9 * V_10 ,
unsigned int V_100 )
{
switch ( V_100 >> 26 ) {
case V_101 :
F_74 ( V_10 ) ;
break;
case V_102 :
F_75 ( V_10 ) ;
break;
}
}
static int F_77 ( struct V_9 * V_10 )
{
F_36 ( V_10 ) ;
F_74 ( V_10 ) ;
return 0 ;
}
static int F_78 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_103 ;
V_103 = F_65 ( V_10 , V_145 ,
V_146 ,
V_147 ) ;
if ( V_103 < 0 )
V_103 = V_148 ;
if ( V_103 == V_148 )
return F_66 ( V_10 ) ;
V_2 = F_67 ( sizeof( * V_2 ) , V_108 ) ;
if ( ! V_2 )
return - V_18 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_149 = 1 ;
V_2 -> V_24 . V_42 = 2 ;
V_2 -> V_24 . V_110 = F_68 ( V_150 ) ;
V_2 -> V_24 . V_43 = V_150 ;
V_2 -> V_24 . V_51 = V_151 ;
V_2 -> V_50 = 1 ;
V_2 -> V_27 = V_152 ;
V_2 -> V_69 = V_153 ;
V_2 -> V_78 = 1 ;
V_2 -> V_79 [ 0 ] = V_154 ;
V_2 -> V_76 = 1 ;
V_2 -> V_77 [ 0 ] = V_155 ;
V_2 -> V_118 = 0 ;
V_2 -> V_91 = F_68 ( V_156 ) ,
V_2 -> V_90 = V_156 ,
V_10 -> V_120 = V_121 ;
switch ( V_103 ) {
case V_157 :
V_2 -> V_78 = 2 ;
V_2 -> V_79 [ 1 ] = V_158 ;
V_10 -> V_120 . V_123 = F_76 ;
break;
case V_159 :
V_2 -> V_78 = 2 ;
V_2 -> V_79 [ 1 ] = V_160 ;
V_10 -> V_120 . V_123 = F_76 ;
V_10 -> V_120 . V_125 = F_77 ;
break;
case V_161 :
V_2 -> V_60 = & V_162 ;
V_2 -> V_78 = 2 ;
V_2 -> V_79 [ 1 ] = V_158 ;
V_2 -> V_76 = 2 ;
V_2 -> V_77 [ 1 ] = V_163 ;
V_10 -> V_120 . V_123 = F_76 ;
break;
#ifdef F_69
case V_164 :
V_2 -> V_60 = & V_165 ;
V_2 -> V_79 [ 0 ] = V_166 ;
V_2 -> V_77 [ 0 ] = V_167 ;
V_10 -> V_120 . V_123 = F_76 ;
#endif
}
V_2 -> V_81 = 0x13 ;
switch ( V_10 -> V_137 >> 16 ) {
case 0x103c :
F_70 ( V_10 , 0x10 , V_138 ,
( 0x17 << V_139 ) |
( 0x17 << V_140 ) |
( 0x05 << V_141 ) |
( 1 << V_142 ) ) ;
break;
}
return 0 ;
}
static void F_79 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_168 ;
V_168 = ( V_2 -> V_93 && V_2 -> V_87 ) ? V_169 : 0 ;
F_80 ( V_10 , 0x16 , V_168 ) ;
V_168 = ( ! V_2 -> V_93 && V_2 -> V_87 ) ? V_170 : 0 ;
F_80 ( V_10 , 0x1a , V_168 ) ;
if ( V_2 -> V_171 )
F_80 ( V_10 , 0x1b , V_168 ) ;
}
static int F_81 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
if ( ! F_49 ( V_57 , V_62 ) )
return 0 ;
F_79 ( V_10 ) ;
return 1 ;
}
static void F_82 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_99 ;
if ( ! ( V_2 -> V_172 & V_173 ) )
return;
V_99 = F_60 ( V_10 , 0x17 ) ;
F_83 ( V_10 , 0x14 , 0 ,
V_174 ,
V_99 ? 0x01 : 0x00 ) ;
}
static void F_84 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_99 ;
T_1 V_175 ;
if ( ! ( V_2 -> V_172 & V_176 ) )
return;
V_99 = F_60 ( V_10 , 0x18 ) ;
if ( V_99 )
V_2 -> V_30 = 1 ;
else
V_2 -> V_30 = 0 ;
V_175 = V_2 -> V_27 [ V_2 -> V_30 ] ;
if ( V_2 -> V_29 && V_2 -> V_29 != V_175 ) {
F_85 ( V_10 , V_2 -> V_29 , 1 ) ;
V_2 -> V_29 = V_175 ;
F_19 ( V_10 , V_175 ,
V_2 -> V_31 , 0 ,
V_2 -> V_32 ) ;
}
}
static void F_86 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_93 = F_60 ( V_10 , 0x16 ) ;
F_79 ( V_10 ) ;
}
static void F_87 ( struct V_9 * V_10 ,
unsigned int V_100 )
{
switch ( V_100 >> 26 ) {
case V_101 :
F_86 ( V_10 ) ;
break;
case V_177 :
F_82 ( V_10 ) ;
break;
case V_178 :
F_84 ( V_10 ) ;
break;
}
}
static void F_88 ( struct V_9 * V_10 , T_1 V_3 ,
unsigned int V_179 )
{
F_83 ( V_10 , V_3 , 0 ,
V_180 ,
V_181 | V_179 ) ;
}
static int F_89 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_36 ( V_10 ) ;
if ( V_2 -> V_172 & V_173 )
F_88 ( V_10 , 0x17 , V_177 ) ;
if ( V_2 -> V_172 & V_176 )
F_88 ( V_10 , 0x18 , V_178 ) ;
if ( V_10 -> V_120 . V_123 ) {
F_86 ( V_10 ) ;
F_82 ( V_10 ) ;
F_84 ( V_10 ) ;
}
return 0 ;
}
static int F_90 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_103 ;
V_103 = F_65 ( V_10 , V_182 ,
V_183 ,
V_184 ) ;
if ( V_103 < 0 )
V_103 = V_185 ;
if ( V_103 == V_185 )
return F_66 ( V_10 ) ;
V_2 = F_67 ( sizeof( * V_2 ) , V_108 ) ;
if ( ! V_2 )
return - V_18 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_149 = 1 ;
V_10 -> V_120 = V_121 ;
V_10 -> V_120 . V_125 = F_89 ;
V_2 -> V_24 . V_42 = 2 ;
V_2 -> V_24 . V_110 = F_68 ( V_186 ) ;
V_2 -> V_24 . V_43 = V_186 ;
V_2 -> V_24 . V_51 = V_187 ;
V_2 -> V_50 = 1 ;
V_2 -> V_27 = V_188 ;
V_2 -> V_78 = 2 ;
V_2 -> V_79 [ 0 ] = V_189 ;
V_2 -> V_79 [ 1 ] = V_190 ;
V_2 -> V_76 = 1 ;
V_2 -> V_77 [ 0 ] = V_191 ;
V_2 -> V_118 = 0 ;
V_2 -> V_91 = F_68 ( V_192 ) ;
V_2 -> V_90 = V_192 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
F_1 ( V_2 , 0x13 , 0 , V_83 ) ;
V_10 -> V_120 . V_123 = F_87 ;
V_2 -> V_172 = V_173 | V_176 ;
switch ( V_103 ) {
case V_193 :
V_2 -> V_79 [ 0 ] = V_194 ;
break;
case V_195 :
V_2 -> V_77 [ 0 ] = V_196 ;
V_2 -> V_79 [ 0 ] = V_197 ;
V_2 -> V_172 = 0 ;
break;
case V_198 :
V_2 -> V_77 [ 0 ] = V_199 ;
V_2 -> V_79 [ 0 ] = V_200 ;
V_2 -> V_172 = 0 ;
break;
case V_201 :
V_2 -> V_79 [ 0 ] = V_202 ;
V_2 -> V_172 = V_173 ;
break;
case V_203 :
V_2 -> V_77 [ V_2 -> V_76 ++ ] =
V_204 ;
V_2 -> V_171 = 1 ;
break;
}
if ( V_2 -> V_8 )
F_71 ( V_10 , F_72 ( V_2 -> V_8 ) ) ;
return 0 ;
}
static void F_91 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_168 ;
F_92 ( V_10 ,
L_7 ,
V_2 -> V_93 , V_2 -> V_87 ) ;
V_168 = ( F_93 ( V_2 ) && V_2 -> V_87 ) ? V_169 : 0 ;
F_80 ( V_10 , 0x19 , V_168 ) ;
V_168 = V_2 -> V_87 ? V_2 -> V_205 : 0 ;
if ( V_2 -> V_206 || V_2 -> V_207 ) {
if ( F_93 ( V_2 ) )
V_168 = 0 ;
} else {
if ( ! F_94 ( V_2 ) )
V_168 = 0 ;
}
F_80 ( V_10 , 0x1c , V_168 ) ;
V_168 = ( ! V_2 -> V_93 && V_2 -> V_87 ) ? V_170 : 0 ;
F_80 ( V_10 , 0x1f , V_168 ) ;
}
static int F_95 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
if ( ! F_49 ( V_57 , V_62 ) )
return 0 ;
F_91 ( V_10 ) ;
return 1 ;
}
static void F_96 ( struct V_9 * V_10 )
{
unsigned int V_99 ;
struct V_95 V_208 [] = {
{ 0x1a , V_209 , V_210 } ,
{ 0x17 , V_174 , 0 } ,
{ 0x14 , V_174 , 0 } ,
{ 0x23 , V_209 , 0 } ,
{}
} ;
static const struct V_95 V_211 [] = {
{ 0x23 , V_209 , V_212 } ,
{ 0x14 , V_174 , 2 } ,
{ 0x1a , V_209 , 0 } ,
{}
} ;
V_99 = F_60 ( V_10 , 0x1a ) ;
if ( V_99 ) {
F_92 ( V_10 , L_8 ) ;
F_37 ( V_10 , V_208 ) ;
} else {
F_92 ( V_10 , L_9 ) ;
F_37 ( V_10 , V_211 ) ;
}
}
static void F_97 ( struct V_9 * V_10 )
{
unsigned int V_99 ;
struct V_95 V_208 [] = {
{ 0x14 , V_174 , 0 } ,
{ 0x1b , V_209 , V_210 } ,
{ 0x23 , V_209 , 0 } ,
{}
} ;
static const struct V_95 V_211 [] = {
{ 0x14 , V_174 , 2 } ,
{ 0x23 , V_209 , V_212 } ,
{ 0x1b , V_209 , 0 } ,
{}
} ;
V_99 = F_60 ( V_10 , 0x1b ) ;
if ( V_99 ) {
F_92 ( V_10 , L_8 ) ;
F_37 ( V_10 , V_208 ) ;
} else {
F_92 ( V_10 , L_9 ) ;
F_37 ( V_10 , V_211 ) ;
}
}
static void F_98 ( struct V_9 * V_10 )
{
unsigned int V_99 ;
V_99 = F_60 ( V_10 , 0x1b ) ;
F_92 ( V_10 , L_10 , V_99 ) ;
F_83 ( V_10 , 0x17 , 0 , V_174 ,
V_99 ? 1 : 0 ) ;
}
static void F_99 ( struct V_9 * V_10 )
{
unsigned int V_99 ;
V_99 = F_60 ( V_10 , 0x1b ) ;
F_92 ( V_10 , L_10 , V_99 ) ;
F_83 ( V_10 , 0x17 , 0 , V_174 ,
V_99 ? 1 : 3 ) ;
}
static void F_100 ( struct V_9 * V_10 )
{
unsigned int V_213 , V_214 ;
static const struct V_95 V_208 [] = {
{ 0x14 , V_174 , 0 } ,
{ 0x17 , V_174 , 1 } ,
{ 0x1b , V_209 , V_210 } ,
{ 0x23 , V_209 , 0 } ,
{ 0x1a , V_209 , 0 } ,
{}
} ;
static const struct V_95 V_215 [] = {
{ 0x14 , V_174 , 0 } ,
{ 0x17 , V_174 , 0 } ,
{ 0x1a , V_209 , V_210 } ,
{ 0x23 , V_209 , 0 } ,
{ 0x1b , V_209 , 0 } ,
{}
} ;
static const struct V_95 V_211 [] = {
{ 0x14 , V_174 , 2 } ,
{ 0x23 , V_209 , V_212 } ,
{ 0x1b , V_209 , 0 } ,
{ 0x1a , V_209 , 0 } ,
{}
} ;
V_213 = F_60 ( V_10 , 0x1b ) ;
V_214 = F_60 ( V_10 , 0x1a ) ;
if ( V_213 ) {
F_92 ( V_10 , L_8 ) ;
F_37 ( V_10 , V_208 ) ;
} else if ( V_214 ) {
F_92 ( V_10 , L_11 ) ;
F_37 ( V_10 , V_215 ) ;
} else {
F_92 ( V_10 , L_9 ) ;
F_37 ( V_10 , V_211 ) ;
}
}
static void F_101 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_216 , V_217 ;
V_216 = F_60 ( V_10 , 0x19 ) ;
V_217 = F_60 ( V_10 , 0x1c ) ;
V_2 -> V_93 = V_216 ? V_218 : 0 ;
V_2 -> V_93 |= V_217 ? V_219 : 0 ;
F_92 ( V_10 , L_12 ,
V_216 , V_217 , V_2 -> V_93 ) ;
F_91 ( V_10 ) ;
}
static void F_102 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_2 -> V_220 )
F_96 ( V_10 ) ;
else if ( V_2 -> V_171 )
F_97 ( V_10 ) ;
else if ( V_2 -> V_207 )
F_100 ( V_10 ) ;
else if ( V_2 -> V_221 )
F_99 ( V_10 ) ;
else if ( V_2 -> V_222 )
F_98 ( V_10 ) ;
}
static void F_103 ( struct V_9 * V_10 , unsigned int V_100 )
{
F_92 ( V_10 , L_13 , V_100 , V_100 >> 26 ) ;
switch ( V_100 >> 26 ) {
case V_101 :
F_101 ( V_10 ) ;
break;
case V_102 :
F_102 ( V_10 ) ;
break;
}
}
static void F_104 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_50 ( V_10 , 0x17 , 0 ,
V_97 ,
V_223 | V_224 | V_225 |
V_226 . V_227 [ V_2 -> V_228 ] . V_229 ) ;
if ( V_2 -> V_171 || V_2 -> V_207 ) {
F_50 ( V_10 , 0x23 , 0 ,
V_97 ,
V_223 | V_224 | V_230 |
V_226 .
V_227 [ V_2 -> V_228 ] . V_229 ) ;
}
}
static int F_105 ( struct V_16 * V_57 ,
struct V_58 * V_59 )
{
return F_27 ( & V_226 , V_59 ) ;
}
static int F_106 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_62 -> V_65 . V_66 . V_67 [ 0 ] = V_2 -> V_228 ;
return 0 ;
}
static int F_107 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_231 * V_232 = & V_226 ;
unsigned int V_4 ;
V_4 = V_62 -> V_65 . V_66 . V_67 [ 0 ] ;
if ( V_4 >= V_232 -> V_233 )
V_4 = V_232 -> V_233 - 1 ;
V_2 -> V_228 = V_4 ;
F_104 ( V_10 ) ;
return 1 ;
}
static void F_108 ( struct V_9 * V_10 ,
const T_1 * V_234 ,
int V_235 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 * V_236 = & V_2 -> V_24 . V_51 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_235 ; V_75 ++ , V_234 ++ ) {
unsigned int V_237 = F_109 ( V_10 , * V_234 ) ;
if ( F_110 ( V_237 ) == V_238 )
continue;
if ( F_111 ( V_10 , * V_234 , V_236 , 1 ) != 1 )
continue;
}
}
static int F_112 ( struct V_9 * V_10 )
{
F_92 ( V_10 , L_14 ) ;
F_36 ( V_10 ) ;
if ( V_10 -> V_120 . V_123 ) {
F_101 ( V_10 ) ;
F_102 ( V_10 ) ;
}
F_104 ( V_10 ) ;
return 0 ;
}
static int F_113 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_103 ;
V_103 = F_65 ( V_10 , V_239 ,
V_240 , V_241 ) ;
if ( V_103 < 0 )
V_103 = V_242 ;
if ( V_103 == V_242 )
return F_66 ( V_10 ) ;
V_2 = F_67 ( sizeof( * V_2 ) , V_108 ) ;
if ( ! V_2 )
return - V_18 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_120 = V_121 ;
V_10 -> V_120 . V_125 = F_36 ;
V_2 -> V_206 = 0 ;
V_2 -> V_24 . V_42 = 2 ;
V_2 -> V_24 . V_110 = F_68 ( V_243 ) ;
V_2 -> V_24 . V_43 = V_243 ;
F_108 ( V_10 , V_244 ,
F_68 ( V_244 ) ) ;
V_2 -> V_50 = 1 ;
V_2 -> V_27 = V_245 ;
V_2 -> V_69 = V_246 ;
V_2 -> V_60 = & V_247 ;
V_2 -> V_205 = V_169 ;
V_2 -> V_76 = 1 ;
V_2 -> V_77 [ 0 ] = V_248 ;
V_2 -> V_91 = F_68 ( V_249 ) ;
V_2 -> V_90 = V_249 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
F_1 ( V_2 , 0x13 , 0 , V_83 ) ;
switch ( V_103 ) {
default:
case V_250 :
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_251 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_252 ;
break;
case V_253 :
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_251 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_252 ;
V_2 -> V_205 = V_170 ;
V_2 -> V_77 [ V_2 -> V_76 ] = V_254 ;
V_2 -> V_76 ++ ;
V_2 -> V_206 = 1 ;
break;
case V_255 :
case V_256 :
V_10 -> V_120 . V_125 = F_112 ;
V_10 -> V_120 . V_123 = F_103 ;
V_2 -> V_77 [ V_2 -> V_76 ] =
V_257 ;
V_2 -> V_76 ++ ;
V_2 -> V_221 = V_103 == V_256 ;
V_2 -> V_222 = V_103 == V_255 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_251 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_252 ;
if ( V_103 == V_256 )
V_2 -> V_24 . V_51 = 0 ;
V_2 -> V_60 = NULL ;
V_2 -> V_205 = 0 ;
V_2 -> V_228 = 3 ;
break;
case V_258 :
V_10 -> V_120 . V_125 = F_112 ;
V_10 -> V_120 . V_123 = F_103 ;
V_2 -> V_77 [ 0 ] = V_259 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_251 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_252 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_260 ;
V_2 -> V_205 = 0 ;
V_2 -> V_220 = 1 ;
V_2 -> V_228 = 3 ;
V_2 -> V_24 . V_51 = 0 ;
V_2 -> V_60 = NULL ;
break;
case V_261 :
V_10 -> V_120 . V_125 = F_112 ;
V_10 -> V_120 . V_123 = F_103 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_251 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_252 ;
V_2 -> V_77 [ 0 ] = V_262 ;
V_2 -> V_205 = 0 ;
V_2 -> V_171 = 1 ;
V_2 -> V_228 = 2 ;
V_2 -> V_24 . V_51 = 0 ;
V_2 -> V_60 = NULL ;
break;
case V_263 :
V_10 -> V_120 . V_125 = F_112 ;
V_10 -> V_120 . V_123 = F_103 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_251 ;
V_2 -> V_79 [ V_2 -> V_78 ++ ] = V_252 ;
V_2 -> V_77 [ 0 ] = V_264 ;
V_2 -> V_207 = 1 ;
V_2 -> V_205 = V_170 ;
V_2 -> V_228 = 2 ;
V_2 -> V_24 . V_51 = 0 ;
V_2 -> V_60 = NULL ;
break;
}
if ( V_2 -> V_8 )
F_71 ( V_10 , F_72 ( V_2 -> V_8 ) ) ;
return 0 ;
}
static void F_114 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_3 , V_265 ;
V_265 = V_10 -> V_266 + V_10 -> V_267 ;
for ( V_3 = V_10 -> V_266 ; V_3 < V_265 ; V_3 ++ )
if ( F_115 ( F_116 ( V_10 , V_3 ) ) == V_268 ) {
F_1 ( V_2 , V_3 , 0 , V_83 ) ;
break;
}
}
static void F_117 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_3 , V_265 ;
V_265 = V_10 -> V_266 + V_10 -> V_267 ;
for ( V_3 = V_10 -> V_266 ; V_3 < V_265 ; V_3 ++ ) {
if ( F_115 ( F_116 ( V_10 , V_3 ) ) != V_269 )
continue;
if ( ! ( F_118 ( V_10 , V_3 ) & V_270 ) )
continue;
V_2 -> V_271 [ V_2 -> V_272 ++ ] = V_3 ;
if ( V_2 -> V_272 >= F_68 ( V_2 -> V_271 ) )
break;
}
if ( V_2 -> V_272 > 2 )
V_2 -> V_273 = 1 ;
}
static void F_119 ( struct V_9 * V_10 , int V_235 ,
T_1 * V_274 , bool V_275 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_235 ; V_75 ++ ) {
if ( F_118 ( V_10 , V_274 [ V_75 ] ) & V_270 )
F_83 ( V_10 , V_274 [ V_75 ] , 0 ,
V_89 ,
V_275 ? 0x02 : 0 ) ;
}
}
static void F_120 ( void * V_276 , int V_277 )
{
struct V_9 * V_10 = V_276 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_119 ( V_10 , V_2 -> V_272 , V_2 -> V_271 , V_277 ) ;
}
static int F_121 ( struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_122 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_123 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_124 ( V_10 ) ;
if ( ! V_2 -> V_273 )
F_119 ( V_10 , V_2 -> V_272 , V_2 -> V_271 , true ) ;
F_125 ( V_10 , V_278 ) ;
return 0 ;
}
static void F_126 ( struct V_9 * V_10 ,
const struct V_279 * V_280 , int V_281 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_6 . V_282 = 1 ;
}
static void F_127 ( struct V_9 * V_10 ,
const struct V_279 * V_280 , int V_281 )
{
if ( V_281 != V_283 )
return;
F_70 ( V_10 , 0x17 , V_83 ,
( 0x3 << V_139 ) |
( 0x4 << V_140 ) |
( 0x27 << V_141 ) |
( 0 << V_142 ) ) ;
}
static void F_128 ( struct V_9 * V_10 )
{
int V_75 ;
bool V_284 = false ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_285 * V_237 = & V_2 -> V_6 . V_286 ;
T_1 V_287 = V_2 -> V_6 . V_288 [ V_2 -> V_6 . V_68 [ 0 ] ] ;
for ( V_75 = 0 ; V_75 < V_237 -> V_289 ; V_75 ++ )
if ( V_237 -> V_290 [ V_75 ] . V_291 == V_287 ) {
V_284 = ! ! V_237 -> V_290 [ V_75 ] . V_292 ;
break;
}
if ( V_284 ) {
F_50 ( V_10 , 0x1c , 0 , 0x410 , 0x7c ) ;
V_2 -> V_6 . V_293 = false ;
} else {
F_50 ( V_10 , 0x1c , 0 , 0x410 , 0x54 ) ;
V_2 -> V_6 . V_293 = F_60 ( V_10 , V_2 -> V_6 . V_286 . V_294 [ 0 ] ) ;
}
F_129 ( V_10 ) ;
}
static void F_130 ( struct V_9 * V_10 ,
struct V_16 * V_57 ,
struct V_61 * V_62 )
{
F_128 ( V_10 ) ;
}
static void F_131 ( struct V_9 * V_10 ,
const struct V_279 * V_280 , int V_281 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_281 ) {
case V_283 :
V_2 -> V_295 |= V_296 ;
break;
case V_297 :
V_2 -> V_6 . V_298 = F_130 ;
V_2 -> V_6 . V_299 = F_128 ;
break;
case V_278 :
F_128 ( V_10 ) ;
break;
}
}
static void F_132 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_300 , V_301 ;
for ( V_300 = 0 ; V_300 < 2 ; V_300 ++ ) {
V_301 = V_225 |
( V_300 ? V_223 : V_224 ) ;
if ( ! V_2 -> V_302 )
V_301 |= F_133 ( V_10 , 0x17 , V_300 , V_83 , 0 ) ;
F_83 ( V_10 , 0x17 , 0 ,
V_97 , V_301 ) ;
}
}
static void F_134 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_303 , V_301 ;
struct V_304 * V_305 ;
V_303 = V_2 -> V_6 . V_306 [ 0 ] [ V_2 -> V_6 . V_68 [ 0 ] ] ;
if ( ! V_2 -> V_302 ) {
F_135 ( V_10 , 0x1e , 0 ) ;
F_136 ( V_10 , V_2 -> V_307 , false , false ) ;
F_135 ( V_10 , 0x1a , V_2 -> V_308 ?
F_137 ( V_10 , 0x1a ) : 0 ) ;
F_135 ( V_10 , 0x1b , V_2 -> V_308 ?
F_137 ( V_10 , 0x1b ) : 0 ) ;
V_305 = F_138 ( V_10 , V_303 ) ;
if ( V_305 )
F_136 ( V_10 , V_305 , true , false ) ;
} else {
V_305 = F_138 ( V_10 , V_303 ) ;
if ( V_305 )
F_136 ( V_10 , V_305 , false , false ) ;
if ( V_2 -> V_308 )
V_301 = V_309 . V_227 [ V_2 -> V_310 ] . V_229 ;
else
V_301 = 0 ;
F_135 ( V_10 , 0x1a , V_301 ) ;
F_135 ( V_10 , 0x1b , 0 ) ;
F_135 ( V_10 , 0x1e , V_2 -> V_308 ? V_212 : 0 ) ;
F_136 ( V_10 , V_2 -> V_307 , true , false ) ;
}
}
static void F_139 ( struct V_9 * V_10 , struct V_311 * V_312 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_313 = V_10 -> V_314 ;
V_10 -> V_314 = 1 ;
if ( ! V_2 -> V_302 )
F_140 ( V_10 , V_312 ) ;
F_134 ( V_10 ) ;
F_141 ( V_10 ) ;
V_10 -> V_314 = V_313 ;
if ( V_2 -> V_302 )
F_132 ( V_10 ) ;
}
static void F_142 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
struct V_22 * V_23 ,
int V_281 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_281 ) {
case V_315 :
V_2 -> V_308 = 1 ;
F_134 ( V_10 ) ;
break;
case V_316 :
V_2 -> V_308 = 0 ;
F_134 ( V_10 ) ;
break;
}
}
static int F_143 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_62 -> V_65 . integer . V_65 [ 0 ] = V_2 -> V_302 ;
return 0 ;
}
static int F_144 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_302 = ! ! V_62 -> V_65 . integer . V_65 [ 0 ] ;
if ( V_302 == V_2 -> V_302 )
return 0 ;
V_2 -> V_302 = V_302 ;
F_134 ( V_10 ) ;
F_132 ( V_10 ) ;
return 1 ;
}
static int F_145 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_62 -> V_65 . V_66 . V_67 [ 0 ] = V_2 -> V_310 ;
return 0 ;
}
static int F_146 ( struct V_16 * V_57 ,
struct V_58 * V_59 )
{
return F_27 ( & V_309 , V_59 ) ;
}
static int F_147 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_231 * V_232 = & V_309 ;
unsigned int V_4 ;
V_4 = V_62 -> V_65 . V_66 . V_67 [ 0 ] ;
if ( V_4 >= V_232 -> V_233 )
V_4 = V_232 -> V_233 - 1 ;
if ( V_2 -> V_310 == V_4 )
return 0 ;
V_2 -> V_310 = V_4 ;
if ( V_2 -> V_302 )
F_134 ( V_10 ) ;
return 1 ;
}
static int F_148 ( struct V_16 * V_57 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_26 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_317 = F_149 ( V_57 , V_62 ) ;
if ( V_317 > 0 && V_2 -> V_302 )
F_132 ( V_10 ) ;
return V_317 ;
}
static void F_150 ( struct V_9 * V_10 ,
const struct V_279 * V_280 , int V_281 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_75 ;
if ( V_281 != V_297 )
return;
V_2 -> V_6 . V_318 = F_139 ;
V_2 -> V_6 . V_319 = F_142 ;
V_2 -> V_307 = F_151 ( V_10 , 0x1e , 0x14 , 0 ) ;
F_41 ( V_10 , V_320 ) ;
F_152 ( V_10 , 0x1a , V_321 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_6 . V_322 . V_323 ; V_75 ++ ) {
struct V_12 * V_17 =
F_153 ( & V_2 -> V_6 . V_322 , V_75 ) ;
if ( ! strcmp ( V_17 -> V_15 , L_15 ) ) {
V_17 -> V_324 = F_148 ;
break;
}
}
}
static void F_154 ( struct V_9 * V_10 ,
const struct V_279 * V_280 , int V_281 )
{
F_70 ( V_10 , 0x17 , V_138 ,
( 0x14 << V_139 ) |
( 0x14 << V_140 ) |
( 0x05 << V_141 ) |
( 1 << V_142 ) ) ;
}
static void F_155 ( struct V_9 * V_10 ,
const struct V_279 * V_280 , int V_281 )
{
F_70 ( V_10 , 0x10 , V_138 ,
( 0x17 << V_139 ) |
( 0x17 << V_140 ) |
( 0x05 << V_141 ) |
( 1 << V_142 ) ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
static T_1 V_325 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_326 ;
for ( V_326 = V_325 ; * V_326 ; V_326 ++ )
F_70 ( V_10 , * V_326 , V_83 ,
V_327 |
F_157 ( V_10 , * V_326 , V_83 ) ) ;
}
static int F_66 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
F_158 ( V_10 , L_16 , V_10 -> V_328 ) ;
V_2 = F_67 ( sizeof( * V_2 ) , V_108 ) ;
if ( ! V_2 )
return - V_18 ;
F_159 ( & V_2 -> V_6 ) ;
V_10 -> V_2 = V_2 ;
F_114 ( V_10 ) ;
F_117 ( V_10 ) ;
V_2 -> V_6 . V_329 = 1 ;
if ( V_2 -> V_273 )
V_2 -> V_6 . V_330 . V_331 = F_120 ;
switch ( V_10 -> V_46 ) {
case 0x14f15045 :
V_10 -> V_109 = 1 ;
V_2 -> V_6 . V_332 = 0x17 ;
V_2 -> V_6 . V_333 = 1 ;
F_160 ( V_10 , V_334 ,
V_335 , V_336 ) ;
break;
case 0x14f15047 :
V_10 -> V_149 = 1 ;
V_2 -> V_6 . V_332 = 0x19 ;
V_2 -> V_6 . V_333 = 1 ;
F_160 ( V_10 , V_337 ,
V_338 , V_336 ) ;
break;
case 0x14f15051 :
F_156 ( V_10 ) ;
V_10 -> V_149 = 1 ;
F_160 ( V_10 , V_339 ,
V_340 , V_336 ) ;
break;
default:
V_10 -> V_149 = 1 ;
F_160 ( V_10 , V_341 ,
V_342 , V_336 ) ;
break;
}
switch ( V_10 -> V_137 >> 16 ) {
case 0x103c :
V_2 -> V_6 . V_343 = 1 ;
break;
}
F_125 ( V_10 , V_283 ) ;
V_11 = F_161 ( V_10 , & V_2 -> V_6 . V_286 , NULL ,
V_2 -> V_295 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_162 ( V_10 , & V_2 -> V_6 . V_286 ) ;
if ( V_11 < 0 )
goto error;
V_10 -> V_120 = V_344 ;
if ( ! V_10 -> V_345 -> V_346 ) {
F_158 ( V_10 ,
L_17 ) ;
V_10 -> V_345 -> V_346 = 1 ;
V_10 -> V_345 -> V_347 = 1 ;
}
F_125 ( V_10 , V_297 ) ;
return 0 ;
error:
F_163 ( V_10 ) ;
return V_11 ;
}
static int T_2 F_164 ( void )
{
return F_165 ( & V_348 ) ;
}
static void T_3 F_166 ( void )
{
F_167 ( & V_348 ) ;
}
