static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_2 ( V_4 , & V_8 -> V_9 , V_6 ,
V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_4 ( V_4 , & V_8 -> V_9 ,
V_10 ,
V_11 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_6 ( V_4 , & V_8 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_8 ( V_4 , & V_8 -> V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_10 ( V_4 , & V_8 -> V_9 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_12 ( V_4 , & V_8 -> V_9 ,
V_10 ,
V_11 , V_6 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 -> V_12 )
V_8 -> V_12 ( V_4 ) ;
F_14 ( V_4 , V_8 -> V_13 [ V_6 -> V_14 ] ,
V_10 , 0 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_16 ( V_4 , V_8 -> V_13 [ V_6 -> V_14 ] ) ;
if ( V_8 -> V_15 )
V_8 -> V_15 ( V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_16 = V_8 -> V_13 [ V_8 -> V_17 ] ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_11 ;
F_14 ( V_4 , V_8 -> V_16 , V_10 , 0 , V_11 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_16 ( V_4 , V_8 -> V_16 ) ;
V_8 -> V_16 = 0 ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_20 * V_21 = V_8 -> V_22 ;
V_4 -> V_23 = 1 ;
V_4 -> V_24 = V_21 ;
V_21 -> V_25 = L_1 ;
V_21 -> V_26 [ V_27 ] = V_28 ;
V_21 -> V_26 [ V_27 ] . V_29 =
V_8 -> V_9 . V_30 ;
V_21 -> V_26 [ V_27 ] . V_31 =
V_8 -> V_9 . V_32 [ 0 ] ;
if ( V_8 -> V_33 )
V_21 -> V_26 [ V_34 ] = * V_8 -> V_33 ;
else {
if ( V_4 -> V_35 == 0x14f15051 )
V_21 -> V_26 [ V_34 ] =
V_36 ;
else {
V_21 -> V_26 [ V_34 ] =
V_37 ;
V_21 -> V_26 [ V_34 ] . V_38 =
V_8 -> V_39 ;
}
}
V_21 -> V_26 [ V_34 ] . V_31 = V_8 -> V_13 [ 0 ] ;
if ( V_8 -> V_9 . V_40 ) {
V_21 ++ ;
V_4 -> V_23 ++ ;
V_21 -> V_25 = L_2 ;
V_21 -> V_41 = V_42 ;
V_21 -> V_26 [ V_27 ] =
V_43 ;
V_21 -> V_26 [ V_27 ] . V_31 =
V_8 -> V_9 . V_40 ;
if ( V_8 -> V_44 ) {
V_21 -> V_26 [ V_34 ] =
V_45 ;
V_21 -> V_26 [ V_34 ] . V_31 =
V_8 -> V_44 ;
}
if ( V_8 -> V_46 [ 0 ] )
V_4 -> V_46 = V_8 -> V_46 ;
}
return 0 ;
}
static int F_20 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_22 ( V_8 -> V_51 , V_50 ) ;
}
static int F_23 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_54 = F_24 ( V_48 , & V_53 -> V_55 ) ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_59 [ V_54 ] ;
return 0 ;
}
static int F_25 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_54 = F_24 ( V_48 , & V_53 -> V_55 ) ;
return F_26 ( V_4 , V_8 -> V_51 , V_53 ,
V_8 -> V_60 [ V_54 ] ,
& V_8 -> V_59 [ V_54 ] ) ;
}
static void F_27 ( struct V_3 * V_4 , T_1 V_61 ,
unsigned int V_62 )
{
if ( V_62 == V_63 )
F_28 ( 100 ) ;
F_29 ( V_4 , V_61 , 0 , V_64 ,
V_62 ) ;
if ( V_62 == V_65 )
F_28 ( 10 ) ;
F_30 ( V_4 , V_61 , V_62 , true ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_67 ; V_66 ++ )
F_32 ( V_4 , V_8 -> V_68 [ V_66 ] ) ;
return 0 ;
}
static void F_33 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_34 ( & V_8 -> V_69 ) ;
F_35 ( V_4 ) ;
F_36 ( V_8 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_66 ;
int V_70 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_71 ; V_66 ++ ) {
V_70 = F_38 ( V_4 , V_8 -> V_72 [ V_66 ] ) ;
if ( V_70 < 0 )
return V_70 ;
}
if ( V_8 -> V_9 . V_40 ) {
V_70 = F_39 ( V_4 ,
V_8 -> V_9 . V_40 ,
V_8 -> V_9 . V_40 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_40 ( V_4 ,
& V_8 -> V_9 ) ;
if ( V_70 < 0 )
return V_70 ;
V_8 -> V_9 . V_73 = 1 ;
}
if ( V_8 -> V_44 ) {
V_70 = F_41 ( V_4 , V_8 -> V_44 ) ;
if ( V_70 < 0 )
return V_70 ;
}
if ( V_8 -> V_74 &&
! F_42 ( V_4 , L_3 ) ) {
unsigned int V_75 [ 4 ] ;
F_43 ( V_4 , V_8 -> V_74 ,
V_76 , V_75 ) ;
V_70 = F_44 ( V_4 , L_3 ,
V_75 , V_77 ,
L_4 ) ;
if ( V_70 < 0 )
return V_70 ;
}
if ( V_8 -> V_74 &&
! F_42 ( V_4 , L_5 ) ) {
V_70 = F_45 ( V_4 , L_5 ,
NULL , V_77 ,
L_6 , true ,
& V_8 -> V_78 . V_79 ) ;
if ( V_70 < 0 )
return V_70 ;
}
if ( V_8 -> V_51 ) {
V_70 = F_38 ( V_4 , V_80 ) ;
if ( V_70 < 0 )
return V_70 ;
}
#ifdef F_46
if ( V_8 -> V_81 ) {
const struct V_82 * V_83 ;
for ( V_83 = V_84 ; V_83 -> V_25 ; V_83 ++ ) {
struct V_47 * V_85 ;
V_85 = F_47 ( V_83 , V_4 ) ;
if ( ! V_85 )
return - V_86 ;
V_85 -> V_87 = V_8 -> V_81 ;
V_70 = F_48 ( V_4 , 0 , V_85 ) ;
if ( V_70 < 0 )
return V_70 ;
}
}
#endif
return 0 ;
}
static int F_49 ( struct V_3 * V_4 )
{
F_50 ( V_4 ) ;
return 0 ;
}
static int F_51 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_88 = ( V_48 -> V_87 >> 8 ) & 1 ;
if ( V_88 )
V_53 -> V_56 . integer . V_56 [ 0 ] = ! V_8 -> V_89 ;
else
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_89 ;
return 0 ;
}
static int F_52 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_88 = ( V_48 -> V_87 >> 8 ) & 1 ;
T_1 V_31 = V_48 -> V_87 & 0xff ;
unsigned int V_90 ;
V_90 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_88 )
V_90 = ! V_90 ;
if ( V_90 == V_8 -> V_89 )
return 0 ;
V_8 -> V_89 = V_90 ;
F_53 ( V_4 , V_31 ,
0 , V_91 ,
V_90 ? 0x02 : 0x00 ) ;
return 1 ;
}
static int F_54 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_55 ( V_4 , V_50 , V_8 -> V_92 ,
V_8 -> V_93 ) ;
}
static int F_56 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_57 ( V_4 , V_53 , V_8 -> V_92 ,
V_8 -> V_93 ,
V_8 -> V_9 . V_30 ) ;
}
static int F_58 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_70 = F_59 ( V_4 , V_53 , V_8 -> V_92 ,
V_8 -> V_93 ,
& V_8 -> V_9 . V_30 ) ;
if ( V_70 >= 0 && V_8 -> V_94 )
V_8 -> V_9 . V_95 = V_8 -> V_9 . V_30 / 2 ;
return V_70 ;
}
static int F_60 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_96 ;
if ( ! F_52 ( V_48 , V_53 ) )
return 0 ;
V_96 = ( ! V_8 -> V_97 && V_8 -> V_89 ) ? 0 : V_98 ;
F_61 ( V_4 , 0x10 , V_76 , 0 ,
V_98 , V_96 ) ;
V_96 = V_8 -> V_89 ? 0 : V_98 ;
F_61 ( V_4 , 0x11 , V_76 , 0 ,
V_98 , V_96 ) ;
return 1 ;
}
static void F_62 ( struct V_3 * V_4 )
{
static const struct V_99 V_100 [] = {
{ 0x14 , V_101 , 0xb080 } ,
{ 0x12 , V_101 , 0xb000 } ,
{}
} ;
static const struct V_99 V_102 [] = {
{ 0x12 , V_101 , 0xb080 } ,
{ 0x14 , V_101 , 0xb000 } ,
{}
} ;
unsigned int V_103 ;
V_103 = F_63 ( V_4 , 0x12 ) ;
if ( V_103 )
F_32 ( V_4 , V_100 ) ;
else
F_32 ( V_4 , V_102 ) ;
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_96 ;
V_8 -> V_97 = F_63 ( V_4 , 0x11 ) ;
V_96 = ( V_8 -> V_97 || ! V_8 -> V_89 ) ? V_98 : 0 ;
F_61 ( V_4 , 0x10 , V_76 , 0 ,
V_98 , V_96 ) ;
}
static void F_65 ( struct V_3 * V_4 ,
unsigned int V_104 )
{
V_104 >>= 26 ;
switch ( V_104 ) {
case V_105 :
F_64 ( V_4 ) ;
break;
case V_106 :
F_62 ( V_4 ) ;
break;
}
}
static int F_66 ( struct V_3 * V_4 )
{
F_31 ( V_4 ) ;
F_64 ( V_4 ) ;
return 0 ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_107 ;
V_107 = F_68 ( V_4 , V_108 ,
V_109 ,
V_110 ) ;
if ( V_107 < 0 )
V_107 = V_111 ;
if ( V_107 == V_111 )
return F_69 ( V_4 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_113 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_95 = F_71 ( V_114 ) ;
V_8 -> V_9 . V_32 = V_114 ;
V_8 -> V_9 . V_40 = V_115 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_116 ;
V_8 -> V_60 = V_117 ;
V_8 -> V_51 = & V_118 ;
V_8 -> V_71 = 1 ;
V_8 -> V_72 [ 0 ] = V_119 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_120 ;
V_8 -> V_121 = 0 ;
V_8 -> V_93 = F_71 ( V_122 ) ;
V_8 -> V_92 = V_122 ;
F_72 ( V_8 , 0x16 , 0 , 1 ) ;
V_4 -> V_123 = V_124 ;
switch ( V_107 ) {
case V_125 :
V_4 -> V_123 . V_126 = F_65 ;
V_8 -> V_51 = & V_118 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_127 ;
V_8 -> V_72 [ 0 ] = V_119 ;
V_4 -> V_123 . V_128 = F_66 ;
break;
case V_129 :
V_4 -> V_123 . V_126 = F_65 ;
V_8 -> V_51 = & V_118 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_130 ;
V_8 -> V_72 [ 0 ] = V_119 ;
V_4 -> V_123 . V_128 = F_66 ;
break;
default:
case V_131 :
V_4 -> V_123 . V_126 = F_65 ;
V_8 -> V_51 = & V_118 ;
V_8 -> V_67 = 3 ;
V_8 -> V_68 [ 1 ] = V_127 ;
V_8 -> V_68 [ 2 ] = V_130 ;
V_8 -> V_72 [ 0 ] = V_119 ;
V_4 -> V_123 . V_128 = F_66 ;
break;
case V_132 :
V_4 -> V_123 . V_126 = F_65 ;
V_8 -> V_51 = & V_133 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_134 ;
V_8 -> V_72 [ 0 ] = V_119 ;
V_8 -> V_72 [ 1 ] = V_135 ;
V_8 -> V_71 = 2 ;
V_4 -> V_123 . V_128 = F_66 ;
break;
case V_136 :
V_4 -> V_123 . V_126 = F_65 ;
V_8 -> V_51 = & V_137 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_127 ;
V_8 -> V_72 [ 0 ] = V_138 ;
V_4 -> V_123 . V_128 = F_66 ;
break;
#ifdef F_73
case V_139 :
V_8 -> V_51 = & V_140 ;
V_8 -> V_72 [ 0 ] = V_141 ;
V_8 -> V_68 [ 0 ] = V_142 ;
break;
#endif
}
switch ( V_4 -> V_143 >> 16 ) {
case 0x103c :
case 0x1631 :
case 0x1734 :
case 0x17aa :
F_74 ( V_4 , 0x17 , V_144 ,
( 0x14 << V_145 ) |
( 0x14 << V_146 ) |
( 0x05 << V_147 ) |
( 1 << V_148 ) ) ;
break;
}
if ( V_8 -> V_81 )
F_75 ( V_4 , V_8 -> V_81 ) ;
return 0 ;
}
static int F_76 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_96 ;
if ( ! F_52 ( V_48 , V_53 ) )
return 0 ;
V_96 = ( ! V_8 -> V_97 && V_8 -> V_89 ) ? 0 : V_98 ;
F_61 ( V_4 , 0x1d , V_76 , 0x01 ,
V_98 , V_96 ) ;
V_96 = V_8 -> V_89 ? 0 : V_98 ;
F_61 ( V_4 , 0x13 , V_76 , 0 ,
V_98 , V_96 ) ;
return 1 ;
}
static void F_77 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_96 ;
V_8 -> V_97 = F_63 ( V_4 , 0x13 ) ;
V_96 = ( V_8 -> V_97 || ! V_8 -> V_89 ) ? V_98 : 0 ;
F_61 ( V_4 , 0x1d , V_76 , 0x01 ,
V_98 , V_96 ) ;
}
static void F_78 ( struct V_3 * V_4 )
{
static const struct V_99 V_100 [] = {
{ 0x15 , V_101 , V_149 } ,
{ 0x17 , V_101 , V_150 } ,
{}
} ;
static const struct V_99 V_102 [] = {
{ 0x17 , V_101 , V_149 } ,
{ 0x15 , V_101 , V_150 } ,
{}
} ;
unsigned int V_103 ;
V_103 = F_63 ( V_4 , 0x15 ) ;
if ( V_103 )
F_32 ( V_4 , V_100 ) ;
else
F_32 ( V_4 , V_102 ) ;
}
static void F_79 ( struct V_3 * V_4 ,
unsigned int V_104 )
{
switch ( V_104 >> 26 ) {
case V_105 :
F_77 ( V_4 ) ;
break;
case V_106 :
F_78 ( V_4 ) ;
break;
}
}
static int F_80 ( struct V_3 * V_4 )
{
F_31 ( V_4 ) ;
F_77 ( V_4 ) ;
return 0 ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_107 ;
V_107 = F_68 ( V_4 , V_151 ,
V_152 ,
V_153 ) ;
if ( V_107 < 0 )
V_107 = V_154 ;
if ( V_107 == V_154 )
return F_69 ( V_4 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_155 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_95 = F_71 ( V_156 ) ;
V_8 -> V_9 . V_32 = V_156 ;
V_8 -> V_9 . V_40 = V_157 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_158 ;
V_8 -> V_60 = V_159 ;
V_8 -> V_71 = 1 ;
V_8 -> V_72 [ 0 ] = V_160 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_161 ;
V_8 -> V_121 = 0 ;
V_8 -> V_93 = F_71 ( V_162 ) ,
V_8 -> V_92 = V_162 ,
V_4 -> V_123 = V_124 ;
switch ( V_107 ) {
case V_163 :
V_8 -> V_71 = 2 ;
V_8 -> V_72 [ 1 ] = V_164 ;
V_4 -> V_123 . V_126 = F_79 ;
break;
case V_165 :
V_8 -> V_71 = 2 ;
V_8 -> V_72 [ 1 ] = V_166 ;
V_4 -> V_123 . V_126 = F_79 ;
V_4 -> V_123 . V_128 = F_80 ;
break;
case V_167 :
V_8 -> V_51 = & V_168 ;
V_8 -> V_71 = 2 ;
V_8 -> V_72 [ 1 ] = V_164 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_169 ;
V_4 -> V_123 . V_126 = F_79 ;
break;
#ifdef F_73
case V_170 :
V_8 -> V_51 = & V_171 ;
V_8 -> V_72 [ 0 ] = V_172 ;
V_8 -> V_68 [ 0 ] = V_173 ;
V_4 -> V_123 . V_126 = F_79 ;
#endif
}
V_8 -> V_74 = 0x13 ;
switch ( V_4 -> V_143 >> 16 ) {
case 0x103c :
F_74 ( V_4 , 0x10 , V_144 ,
( 0x17 << V_145 ) |
( 0x17 << V_146 ) |
( 0x05 << V_147 ) |
( 1 << V_148 ) ) ;
break;
}
return 0 ;
}
static void F_82 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_174 ;
V_174 = ( V_8 -> V_97 && V_8 -> V_89 ) ? V_175 : 0 ;
F_83 ( V_4 , 0x16 , V_174 ) ;
V_174 = ( ! V_8 -> V_97 && V_8 -> V_89 ) ? V_176 : 0 ;
F_83 ( V_4 , 0x1a , V_174 ) ;
if ( V_8 -> V_177 )
F_83 ( V_4 , 0x1b , V_174 ) ;
}
static int F_84 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
if ( ! F_52 ( V_48 , V_53 ) )
return 0 ;
F_82 ( V_4 ) ;
return 1 ;
}
static void F_85 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_103 ;
if ( ! ( V_8 -> V_178 & V_179 ) )
return;
V_103 = F_63 ( V_4 , 0x17 ) ;
F_86 ( V_4 , 0x14 , 0 ,
V_180 ,
V_103 ? 0x01 : 0x00 ) ;
}
static void F_87 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_103 ;
T_1 V_181 ;
if ( ! ( V_8 -> V_178 & V_182 ) )
return;
V_103 = F_63 ( V_4 , 0x18 ) ;
if ( V_103 )
V_8 -> V_17 = 1 ;
else
V_8 -> V_17 = 0 ;
V_181 = V_8 -> V_13 [ V_8 -> V_17 ] ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_181 ) {
F_88 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_181 ;
F_14 ( V_4 , V_181 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
}
static void F_89 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_97 = F_63 ( V_4 , 0x16 ) ;
F_82 ( V_4 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
unsigned int V_104 )
{
switch ( V_104 >> 26 ) {
case V_105 :
F_89 ( V_4 ) ;
break;
case V_183 :
F_85 ( V_4 ) ;
break;
case V_184 :
F_87 ( V_4 ) ;
break;
}
}
static void F_91 ( struct V_3 * V_4 , T_1 V_31 ,
unsigned int V_185 )
{
F_86 ( V_4 , V_31 , 0 ,
V_186 ,
V_187 | V_185 ) ;
}
static int F_92 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_31 ( V_4 ) ;
if ( V_8 -> V_178 & V_179 )
F_91 ( V_4 , 0x17 , V_183 ) ;
if ( V_8 -> V_178 & V_182 )
F_91 ( V_4 , 0x18 , V_184 ) ;
if ( V_4 -> V_123 . V_126 ) {
F_89 ( V_4 ) ;
F_85 ( V_4 ) ;
F_87 ( V_4 ) ;
}
return 0 ;
}
static int F_93 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_107 ;
V_107 = F_68 ( V_4 , V_188 ,
V_189 ,
V_190 ) ;
if ( V_107 < 0 )
V_107 = V_191 ;
if ( V_107 == V_191 )
return F_69 ( V_4 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_155 = 1 ;
V_4 -> V_123 = V_124 ;
V_4 -> V_123 . V_128 = F_92 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_95 = F_71 ( V_192 ) ;
V_8 -> V_9 . V_32 = V_192 ;
V_8 -> V_9 . V_40 = V_193 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_194 ;
V_8 -> V_71 = 2 ;
V_8 -> V_72 [ 0 ] = V_195 ;
V_8 -> V_72 [ 1 ] = V_196 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_197 ;
V_8 -> V_121 = 0 ;
V_8 -> V_93 = F_71 ( V_198 ) ;
V_8 -> V_92 = V_198 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_72 ( V_8 , 0x13 , 0 , V_76 ) ;
V_4 -> V_123 . V_126 = F_90 ;
V_8 -> V_178 = V_179 | V_182 ;
switch ( V_107 ) {
case V_199 :
V_8 -> V_72 [ 0 ] = V_200 ;
break;
case V_201 :
V_8 -> V_68 [ 0 ] = V_202 ;
V_8 -> V_72 [ 0 ] = V_203 ;
V_8 -> V_178 = 0 ;
break;
case V_204 :
V_8 -> V_68 [ 0 ] = V_205 ;
V_8 -> V_72 [ 0 ] = V_206 ;
V_8 -> V_178 = 0 ;
break;
case V_207 :
V_8 -> V_72 [ 0 ] = V_208 ;
V_8 -> V_178 = V_179 ;
break;
case V_209 :
V_8 -> V_68 [ V_8 -> V_67 ++ ] =
V_210 ;
V_8 -> V_177 = 1 ;
break;
}
if ( V_8 -> V_81 )
F_75 ( V_4 , V_8 -> V_81 ) ;
return 0 ;
}
static void F_94 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_174 ;
F_95 ( L_7 ,
V_8 -> V_97 , V_8 -> V_89 ) ;
V_174 = ( F_96 ( V_8 ) && V_8 -> V_89 ) ? V_175 : 0 ;
F_83 ( V_4 , 0x19 , V_174 ) ;
V_174 = V_8 -> V_89 ? V_8 -> V_211 : 0 ;
if ( V_8 -> V_212 || V_8 -> V_213 ) {
if ( F_96 ( V_8 ) )
V_174 = 0 ;
} else {
if ( ! F_97 ( V_8 ) )
V_174 = 0 ;
}
F_83 ( V_4 , 0x1c , V_174 ) ;
V_174 = ( ! V_8 -> V_97 && V_8 -> V_89 ) ? V_176 : 0 ;
F_83 ( V_4 , 0x1f , V_174 ) ;
}
static int F_98 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
if ( ! F_52 ( V_48 , V_53 ) )
return 0 ;
F_94 ( V_4 ) ;
return 1 ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_100 ( V_4 , 0x1a ,
V_214 . V_215 [ V_8 -> V_216 ] . V_217 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_218 )
return;
if ( V_8 -> V_219 ) {
const struct V_99 V_220 [] = {
{ 0x1b , V_221 , 0 } ,
{ 0x1e , V_221 , V_222 } ,
{} ,
} ;
F_32 ( V_4 , V_220 ) ;
F_99 ( V_4 ) ;
return;
}
F_83 ( V_4 , 0x1e , 0 ) ;
F_83 ( V_4 , 0x1a ,
V_8 -> V_223 ? V_224 : 0 ) ;
F_83 ( V_4 , 0x1b ,
V_8 -> V_223 ? 0 : V_225 ) ;
}
static void F_102 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_103 ;
if ( V_8 -> V_219 )
return;
V_103 = F_29 ( V_4 , 0x1a , 0 ,
V_226 , 0 ) & 0x80000000 ;
if ( V_103 )
F_95 ( L_8 ) ;
else
F_95 ( L_9 ) ;
F_86 ( V_4 , 0x17 , 0 , V_180 ,
V_103 ? 0 : 1 ) ;
V_8 -> V_223 = ! ! V_103 ;
F_101 ( V_4 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
unsigned int V_103 ;
struct V_99 V_223 [] = {
{ 0x1a , V_221 , V_225 } ,
{ 0x17 , V_180 , 0 } ,
{ 0x14 , V_180 , 0 } ,
{ 0x23 , V_221 , 0 } ,
{}
} ;
static const struct V_99 V_227 [] = {
{ 0x23 , V_221 , V_222 } ,
{ 0x14 , V_180 , 2 } ,
{ 0x1a , V_221 , 0 } ,
{}
} ;
V_103 = F_63 ( V_4 , 0x1a ) ;
if ( V_103 ) {
F_95 ( L_8 ) ;
F_32 ( V_4 , V_223 ) ;
} else {
F_95 ( L_9 ) ;
F_32 ( V_4 , V_227 ) ;
}
}
static void F_104 ( struct V_3 * V_4 )
{
unsigned int V_103 ;
struct V_99 V_223 [] = {
{ 0x14 , V_180 , 0 } ,
{ 0x1b , V_221 , V_225 } ,
{ 0x23 , V_221 , 0 } ,
{}
} ;
static const struct V_99 V_227 [] = {
{ 0x14 , V_180 , 2 } ,
{ 0x23 , V_221 , V_222 } ,
{ 0x1b , V_221 , 0 } ,
{}
} ;
V_103 = F_63 ( V_4 , 0x1b ) ;
if ( V_103 ) {
F_95 ( L_8 ) ;
F_32 ( V_4 , V_223 ) ;
} else {
F_95 ( L_9 ) ;
F_32 ( V_4 , V_227 ) ;
}
}
static void F_105 ( struct V_3 * V_4 )
{
unsigned int V_103 ;
V_103 = F_63 ( V_4 , 0x1b ) ;
F_95 ( L_10 , V_103 ) ;
F_86 ( V_4 , 0x17 , 0 , V_180 ,
V_103 ? 1 : 0 ) ;
}
static void F_106 ( struct V_3 * V_4 )
{
unsigned int V_103 ;
V_103 = F_63 ( V_4 , 0x1b ) ;
F_95 ( L_10 , V_103 ) ;
F_86 ( V_4 , 0x17 , 0 , V_180 ,
V_103 ? 1 : 3 ) ;
}
static void F_107 ( struct V_3 * V_4 )
{
unsigned int V_228 , V_229 ;
static const struct V_99 V_223 [] = {
{ 0x14 , V_180 , 0 } ,
{ 0x17 , V_180 , 1 } ,
{ 0x1b , V_221 , V_225 } ,
{ 0x23 , V_221 , 0 } ,
{ 0x1a , V_221 , 0 } ,
{}
} ;
static const struct V_99 V_230 [] = {
{ 0x14 , V_180 , 0 } ,
{ 0x17 , V_180 , 0 } ,
{ 0x1a , V_221 , V_225 } ,
{ 0x23 , V_221 , 0 } ,
{ 0x1b , V_221 , 0 } ,
{}
} ;
static const struct V_99 V_227 [] = {
{ 0x14 , V_180 , 2 } ,
{ 0x23 , V_221 , V_222 } ,
{ 0x1b , V_221 , 0 } ,
{ 0x1a , V_221 , 0 } ,
{}
} ;
V_228 = F_63 ( V_4 , 0x1b ) ;
V_229 = F_63 ( V_4 , 0x1a ) ;
if ( V_228 ) {
F_95 ( L_8 ) ;
F_32 ( V_4 , V_223 ) ;
} else if ( V_229 ) {
F_95 ( L_11 ) ;
F_32 ( V_4 , V_230 ) ;
} else {
F_95 ( L_9 ) ;
F_32 ( V_4 , V_227 ) ;
}
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_231 , V_232 ;
V_231 = F_63 ( V_4 , 0x19 ) ;
V_232 = F_63 ( V_4 , 0x1c ) ;
V_8 -> V_97 = V_231 ? V_233 : 0 ;
V_8 -> V_97 |= V_232 ? V_234 : 0 ;
F_95 ( L_12 ,
V_231 , V_232 , V_8 -> V_97 ) ;
F_94 ( V_4 ) ;
}
static void F_109 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 -> V_235 )
F_103 ( V_4 ) ;
else if ( V_8 -> V_177 )
F_104 ( V_4 ) ;
else if ( V_8 -> V_213 )
F_107 ( V_4 ) ;
else if ( V_8 -> V_236 )
F_106 ( V_4 ) ;
else if ( V_8 -> V_237 )
F_105 ( V_4 ) ;
}
static void F_110 ( struct V_3 * V_4 , unsigned int V_104 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_95 ( L_13 , V_104 , V_104 >> 26 ) ;
switch ( V_104 >> 26 ) {
case V_105 :
F_108 ( V_4 ) ;
break;
case V_106 :
if ( ! V_8 -> V_219 )
F_102 ( V_4 ) ;
break;
}
}
static void F_111 ( struct V_3 * V_4 , unsigned int V_104 )
{
F_95 ( L_13 , V_104 , V_104 >> 26 ) ;
switch ( V_104 >> 26 ) {
case V_105 :
F_108 ( V_4 ) ;
break;
case V_106 :
F_109 ( V_4 ) ;
break;
}
}
static void F_112 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_53 ( V_4 , 0x17 , 0 ,
V_101 ,
V_238 | V_239 | V_240 |
V_241 . V_215 [ V_8 -> V_242 ] . V_217 ) ;
if ( V_8 -> V_177 || V_8 -> V_213 ) {
F_53 ( V_4 , 0x23 , 0 ,
V_101 ,
V_238 | V_239 | V_243 |
V_241 .
V_215 [ V_8 -> V_242 ] . V_217 ) ;
}
}
static int F_113 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_241 , V_50 ) ;
}
static int F_114 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_242 ;
return 0 ;
}
static int F_115 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_244 * V_245 = & V_241 ;
unsigned int V_246 ;
V_246 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_246 >= V_245 -> V_247 )
V_246 = V_245 -> V_247 - 1 ;
V_8 -> V_242 = V_246 ;
if ( ! V_8 -> V_219 )
F_112 ( V_4 ) ;
return 1 ;
}
static void F_116 ( struct V_3 * V_4 )
{
const struct V_99 V_220 [] = {
{ 0x17 , V_101 , V_150 } ,
{ 0x17 , V_180 , 3 } ,
{}
} ;
F_32 ( V_4 , V_220 ) ;
F_101 ( V_4 ) ;
}
static void F_117 ( struct V_3 * V_4 )
{
F_112 ( V_4 ) ;
F_102 ( V_4 ) ;
}
static int F_118 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_219 ;
return 0 ;
}
static int F_119 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_219 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_219 == V_8 -> V_219 )
return 0 ;
V_8 -> V_219 = V_219 ;
if ( V_219 )
F_116 ( V_4 ) ;
else
F_117 ( V_4 ) ;
return 1 ;
}
static int F_120 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_214 , V_50 ) ;
}
static int F_121 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_216 ;
return 0 ;
}
static int F_122 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_244 * V_245 = & V_241 ;
unsigned int V_246 ;
V_246 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_246 >= V_245 -> V_247 )
V_246 = V_245 -> V_247 - 1 ;
V_8 -> V_216 = V_246 ;
if ( V_8 -> V_219 )
F_99 ( V_4 ) ;
return 1 ;
}
static void F_123 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_218 = 1 ;
F_101 ( V_4 ) ;
}
static void F_124 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_99 V_248 [] = {
{ 0x1a , V_221 , 0 } ,
{ 0x1b , V_221 , 0 } ,
{ 0x1e , V_221 , 0 } ,
{} ,
} ;
F_32 ( V_4 , V_248 ) ;
V_8 -> V_218 = 0 ;
}
static void F_125 ( struct V_3 * V_4 ,
const T_1 * V_249 ,
int V_250 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 * V_251 = & V_8 -> V_9 . V_40 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_250 ; V_66 ++ , V_249 ++ ) {
unsigned int V_252 = F_126 ( V_4 , * V_249 ) ;
if ( F_127 ( V_252 ) == V_253 )
continue;
if ( F_128 ( V_4 , * V_249 , V_251 , 1 ) != 1 )
continue;
if ( V_8 -> V_46 [ 0 ] )
V_251 ++ ;
else
V_251 = V_8 -> V_46 ;
}
}
static int F_129 ( struct V_3 * V_4 )
{
F_95 ( L_14 ) ;
F_31 ( V_4 ) ;
if ( V_4 -> V_123 . V_126 ) {
F_108 ( V_4 ) ;
F_109 ( V_4 ) ;
}
F_112 ( V_4 ) ;
return 0 ;
}
static int F_130 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_95 ( L_14 ) ;
F_31 ( V_4 ) ;
F_108 ( V_4 ) ;
if ( ! V_8 -> V_219 ) {
F_112 ( V_4 ) ;
F_102 ( V_4 ) ;
} else {
F_116 ( V_4 ) ;
}
return 0 ;
}
static int F_131 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_107 ;
V_107 = F_68 ( V_4 , V_254 ,
V_255 , V_256 ) ;
if ( V_107 < 0 )
V_107 = V_257 ;
if ( V_107 == V_257 )
return F_69 ( V_4 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_123 = V_124 ;
V_4 -> V_123 . V_128 = F_31 ;
V_8 -> V_212 = 0 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_95 = F_71 ( V_258 ) ;
V_8 -> V_9 . V_32 = V_258 ;
F_125 ( V_4 , V_259 ,
F_71 ( V_259 ) ) ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_260 ;
V_8 -> V_60 = V_261 ;
V_8 -> V_51 = & V_262 ;
V_8 -> V_211 = V_175 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_263 ;
V_8 -> V_93 = F_71 ( V_264 ) ;
V_8 -> V_92 = V_264 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_72 ( V_8 , 0x13 , 0 , V_76 ) ;
switch ( V_107 ) {
default:
case V_265 :
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_266 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
break;
case V_268 :
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_266 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_211 = V_176 ;
V_8 -> V_68 [ V_8 -> V_67 ] = V_269 ;
V_8 -> V_67 ++ ;
V_8 -> V_212 = 1 ;
break;
case V_270 :
case V_271 :
V_4 -> V_123 . V_128 = F_129 ;
V_4 -> V_123 . V_126 = F_111 ;
V_8 -> V_68 [ V_8 -> V_67 ] =
V_272 ;
V_8 -> V_67 ++ ;
V_8 -> V_236 = V_107 == V_271 ;
V_8 -> V_237 = V_107 == V_270 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_266 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
if ( V_107 == V_271 )
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_211 = 0 ;
V_8 -> V_242 = 3 ;
break;
case V_273 :
V_4 -> V_123 . V_128 = F_130 ;
V_4 -> V_123 . V_126 = F_110 ;
V_8 -> V_68 [ 0 ] = V_274 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_275 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_276 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_211 = 0 ;
V_8 -> V_242 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_12 = F_123 ;
V_8 -> V_15 = F_124 ;
break;
case V_277 :
V_4 -> V_123 . V_128 = F_129 ;
V_4 -> V_123 . V_126 = F_111 ;
V_8 -> V_68 [ 0 ] = V_278 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_275 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_279 ;
V_8 -> V_211 = 0 ;
V_8 -> V_235 = 1 ;
V_8 -> V_242 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_280 :
V_4 -> V_123 . V_128 = F_129 ;
V_4 -> V_123 . V_126 = F_111 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_266 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_68 [ 0 ] = V_281 ;
V_8 -> V_211 = 0 ;
V_8 -> V_177 = 1 ;
V_8 -> V_242 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_282 :
V_4 -> V_123 . V_128 = F_129 ;
V_4 -> V_123 . V_126 = F_111 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_266 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_68 [ 0 ] = V_283 ;
V_8 -> V_213 = 1 ;
V_8 -> V_211 = V_176 ;
V_8 -> V_242 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
}
if ( V_8 -> V_81 )
F_75 ( V_4 , V_8 -> V_81 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_284 = V_8 -> V_285 [ V_8 -> V_59 [ 0 ] ] . V_284 ;
if ( V_8 -> V_286 ) {
V_8 -> V_16 = V_284 ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_11 ;
}
F_14 ( V_4 , V_284 , V_10 , 0 , V_11 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_16 ( V_4 , V_8 -> V_16 ) ;
V_8 -> V_16 = 0 ;
return 0 ;
}
static T_1 F_134 ( struct V_3 * V_4 , T_1 V_287 ,
T_1 * V_288 , int * V_95 )
{
int V_66 , V_289 = * V_95 ;
T_1 V_290 = 0 ;
for ( V_66 = 0 ; V_66 < V_289 ; V_66 ++ ) {
if ( F_135 ( V_4 , V_287 , V_288 [ V_66 ] ) >= 0 ) {
V_290 = V_288 [ V_66 ] ;
break;
}
}
if ( ! V_290 )
return 0 ;
if ( -- V_289 > 0 )
memmove ( V_288 , V_288 + 1 , V_289 * sizeof( T_1 ) ) ;
* V_95 = V_289 ;
return V_290 ;
}
static int F_136 ( struct V_3 * V_4 , T_1 * V_288 )
{
T_1 V_31 , V_291 ;
int V_289 = 0 ;
V_291 = V_4 -> V_292 + V_4 -> V_293 ;
for ( V_31 = V_4 -> V_292 ; V_31 < V_291 ; V_31 ++ ) {
unsigned int V_294 = F_137 ( V_4 , V_31 ) ;
unsigned int type = F_138 ( V_294 ) ;
if ( type == V_295 && ! ( V_294 & V_296 ) ) {
V_288 [ V_289 ++ ] = V_31 ;
if ( V_289 >= V_297 )
break;
}
}
return V_289 ;
}
static int F_139 ( struct V_3 * V_4 , T_1 * V_298 ,
int V_250 , T_1 * V_288 , int * V_299 ,
struct V_300 * V_301 , int V_289 ,
int type )
{
int V_66 , V_302 = V_289 ;
for ( V_66 = 0 ; V_66 < V_250 ; V_66 ++ , V_289 ++ ) {
V_301 [ V_289 ] . V_287 = V_298 [ V_66 ] ;
V_301 [ V_289 ] . type = type ;
V_301 [ V_289 ] . V_303 = F_134 ( V_4 , V_298 [ V_66 ] , V_288 , V_299 ) ;
if ( V_301 [ V_289 ] . V_303 )
continue;
if ( V_301 [ V_302 ] . V_303 && F_135 ( V_4 , V_298 [ V_66 ] , V_301 [ V_302 ] . V_303 ) >= 0 ) {
V_301 [ V_289 ] . V_303 = V_301 [ V_302 ] . V_303 | V_304 ;
continue;
}
if ( V_301 [ 0 ] . V_303 && F_135 ( V_4 , V_298 [ V_66 ] , V_301 [ 0 ] . V_303 ) >= 0 ) {
V_301 [ V_289 ] . V_303 = V_301 [ 0 ] . V_303 | V_304 ;
continue;
}
F_95 ( L_15 , V_298 [ V_66 ] ) ;
}
return V_289 ;
}
static void F_140 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
T_1 V_288 [ V_297 ] ;
int V_66 , V_307 , V_289 , V_299 ;
V_299 = F_136 ( V_4 , V_288 ) ;
V_289 = F_139 ( V_4 , V_252 -> V_308 , V_252 -> V_309 ,
V_288 , & V_299 , V_8 -> V_310 , 0 ,
V_311 ) ;
V_289 = F_139 ( V_4 , V_252 -> V_312 , V_252 -> V_313 ,
V_288 , & V_299 , V_8 -> V_310 , V_289 ,
V_314 ) ;
V_289 = F_139 ( V_4 , V_252 -> V_315 , V_252 -> V_316 ,
V_288 , & V_299 , V_8 -> V_310 , V_289 ,
V_317 ) ;
V_8 -> V_318 = V_289 ;
for ( V_66 = 0 ; V_66 < V_289 ; V_66 ++ ) {
T_1 V_303 = V_8 -> V_310 [ V_66 ] . V_303 ;
if ( ! V_303 || ( V_303 & V_304 ) )
continue;
switch ( V_8 -> V_310 [ V_66 ] . type ) {
case V_311 :
V_8 -> V_319 [ V_8 -> V_9 . V_95 ] = V_303 ;
V_8 -> V_9 . V_95 ++ ;
break;
case V_314 :
case V_317 :
if ( ! V_8 -> V_9 . V_320 ) {
V_8 -> V_9 . V_320 = V_303 ;
break;
}
for ( V_307 = 0 ; V_307 < F_71 ( V_8 -> V_9 . V_321 ) ; V_307 ++ )
if ( ! V_8 -> V_9 . V_321 [ V_307 ] ) {
V_8 -> V_9 . V_321 [ V_307 ] = V_303 ;
break;
}
break;
}
}
V_8 -> V_9 . V_32 = V_8 -> V_319 ;
V_8 -> V_9 . V_30 = V_8 -> V_9 . V_95 * 2 ;
for ( V_66 = 0 ; V_66 < V_252 -> V_313 ; V_66 ++ ) {
if ( F_141 ( V_4 , V_252 -> V_312 [ V_66 ] ) ) {
V_8 -> V_322 = 1 ;
break;
}
}
if ( V_8 -> V_322 &&
V_252 -> V_308 [ 0 ] &&
V_252 -> V_323 != V_317 &&
V_252 -> V_308 [ 0 ] != V_252 -> V_312 [ 0 ] &&
V_252 -> V_308 [ 0 ] != V_252 -> V_315 [ 0 ] ) {
for ( V_66 = 0 ; V_66 < V_252 -> V_309 ; V_66 ++ ) {
if ( F_141 ( V_4 , V_252 -> V_308 [ V_66 ] ) ) {
V_8 -> V_324 = 1 ;
break;
}
}
V_8 -> V_325 = V_8 -> V_324 ;
}
V_8 -> V_74 = V_8 -> V_319 [ 0 ] ;
}
static void F_142 ( struct V_3 * V_4 , int V_250 ,
T_1 * V_298 , bool V_326 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_250 ; V_66 ++ )
F_83 ( V_4 , V_298 [ V_66 ] , V_326 ? V_176 : 0 ) ;
if ( V_8 -> V_327 )
F_143 ( V_4 , V_250 , V_298 , V_326 ) ;
}
static int F_144 ( struct V_3 * V_4 , int V_250 , T_1 * V_298 )
{
int V_66 , V_103 = 0 ;
for ( V_66 = 0 ; V_66 < V_250 ; V_66 ++ ) {
T_1 V_31 = V_298 [ V_66 ] ;
if ( ! V_31 || ! F_141 ( V_4 , V_31 ) )
break;
V_103 |= F_63 ( V_4 , V_31 ) ;
}
return V_103 ;
}
static void F_145 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
int V_326 = 1 ;
if ( V_8 -> V_327 ) {
if ( V_8 -> V_322 )
V_326 = V_8 -> V_97 ;
F_143 ( V_4 , V_252 -> V_313 , V_252 -> V_312 , V_326 ) ;
}
if ( V_8 -> V_322 )
V_326 = ! ( V_8 -> V_97 ||
( V_8 -> V_324 && V_8 -> V_328 ) ) ;
F_142 ( V_4 , V_252 -> V_316 , V_252 -> V_315 , V_326 ) ;
if ( V_252 -> V_308 [ 0 ] == V_252 -> V_312 [ 0 ] ||
V_252 -> V_308 [ 0 ] == V_252 -> V_315 [ 0 ] )
return;
if ( V_8 -> V_322 ) {
if ( V_252 -> V_323 == V_317 ||
V_8 -> V_325 )
V_326 = ! V_8 -> V_97 ;
else
V_326 = 1 ;
}
F_142 ( V_4 , V_252 -> V_309 , V_252 -> V_308 , V_326 ) ;
}
static void F_146 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
if ( ! V_8 -> V_322 )
return;
V_8 -> V_97 = F_144 ( V_4 , V_252 -> V_313 , V_252 -> V_312 ) ;
F_145 ( V_4 ) ;
}
static void F_147 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
if ( ! V_8 -> V_322 || ! V_8 -> V_324 )
return;
V_8 -> V_328 = F_144 ( V_4 , V_252 -> V_309 ,
V_252 -> V_308 ) ;
F_145 ( V_4 ) ;
}
static int F_148 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
static const char * const V_329 [] = {
L_16 , L_17
} ;
static const char * const V_330 [] = {
L_16 , L_18 , L_19
} ;
const char * const * V_331 ;
V_50 -> type = V_332 ;
V_50 -> V_333 = 1 ;
if ( V_8 -> V_334 ) {
V_50 -> V_56 . V_57 . V_215 = 3 ;
V_331 = V_330 ;
} else {
V_50 -> V_56 . V_57 . V_215 = 2 ;
V_331 = V_329 ;
}
if ( V_50 -> V_56 . V_57 . V_58 >= V_50 -> V_56 . V_57 . V_215 )
V_50 -> V_56 . V_57 . V_58 = V_50 -> V_56 . V_57 . V_215 - 1 ;
strcpy ( V_50 -> V_56 . V_57 . V_25 ,
V_331 [ V_50 -> V_56 . V_57 . V_58 ] ) ;
return 0 ;
}
static int F_149 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_335 ;
if ( ! V_8 -> V_322 )
V_335 = 0 ;
else if ( ! V_8 -> V_325 )
V_335 = 1 ;
else
V_335 = 2 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_335 ;
return 0 ;
}
static int F_150 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
switch ( V_53 -> V_56 . V_57 . V_58 [ 0 ] ) {
case 0 :
if ( ! V_8 -> V_322 )
return 0 ;
V_8 -> V_322 = 0 ;
break;
case 1 :
if ( V_8 -> V_322 && ! V_8 -> V_325 )
return 0 ;
V_8 -> V_322 = 1 ;
V_8 -> V_325 = 0 ;
break;
case 2 :
if ( ! V_8 -> V_334 )
return - V_336 ;
if ( V_8 -> V_322 && V_8 -> V_325 )
return 0 ;
V_8 -> V_322 = 1 ;
V_8 -> V_325 = 1 ;
break;
default:
return - V_336 ;
}
F_145 ( V_4 ) ;
return 1 ;
}
static int F_151 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_22 ( & V_8 -> V_337 , V_50 ) ;
}
static int F_152 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_59 [ 0 ] ;
return 0 ;
}
static int F_153 ( struct V_3 * V_4 , T_1 V_338 ,
T_1 V_287 , T_1 * V_339 ,
bool V_340 , int V_341 )
{
T_1 V_342 [ V_343 ] ;
int V_66 , V_289 ;
switch ( F_138 ( F_137 ( V_4 , V_338 ) ) ) {
case V_344 :
case V_345 :
case V_346 :
break;
default:
return - 1 ;
}
V_289 = F_128 ( V_4 , V_338 , V_342 , F_71 ( V_342 ) ) ;
for ( V_66 = 0 ; V_66 < V_289 ; V_66 ++ )
if ( V_342 [ V_66 ] == V_287 ) {
if ( V_340 )
F_86 ( V_4 , V_338 , 0 ,
V_180 , V_66 ) ;
if ( V_339 )
* V_339 = V_338 ;
return V_66 ;
}
V_341 ++ ;
if ( V_341 == 2 )
return - 1 ;
for ( V_66 = 0 ; V_66 < V_289 ; V_66 ++ ) {
int V_290 = F_153 ( V_4 , V_342 [ V_66 ] , V_287 , V_339 ,
V_340 , V_341 ) ;
if ( V_290 >= 0 ) {
if ( V_340 )
F_86 ( V_4 , V_338 , 0 ,
V_180 , V_66 ) ;
return V_66 ;
}
}
return - 1 ;
}
static void F_154 ( struct V_3 * V_4 , T_1 V_338 ,
T_1 V_287 )
{
F_153 ( V_4 , V_338 , V_287 , NULL , true , 0 ) ;
}
static int F_155 ( struct V_3 * V_4 , T_1 V_338 ,
T_1 V_287 )
{
return F_153 ( V_4 , V_338 , V_287 , NULL , false , 0 ) ;
}
static int F_156 ( struct V_3 * V_4 ,
const struct V_244 * V_245 ,
unsigned int V_246 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_284 ;
int V_347 = 1 ;
if ( ! V_245 -> V_247 )
return 0 ;
if ( V_246 >= V_245 -> V_247 )
V_246 = V_245 -> V_247 - 1 ;
if ( V_8 -> V_59 [ 0 ] == V_246 )
V_347 = 0 ;
V_284 = V_8 -> V_285 [ V_246 ] . V_284 ;
F_154 ( V_4 , V_8 -> V_285 [ V_246 ] . V_284 ,
V_8 -> V_285 [ V_246 ] . V_287 ) ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_284 ) {
F_88 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_284 ;
F_14 ( V_4 , V_284 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
V_8 -> V_59 [ 0 ] = V_246 ;
return V_347 ;
}
static int F_157 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_156 ( V_4 , & V_8 -> V_337 ,
V_53 -> V_56 . V_57 . V_58 [ 0 ] ) ;
}
static bool F_158 ( struct V_3 * V_4 , int V_246 , bool V_348 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_246 < 0 )
return false ;
if ( V_348 && ! F_63 ( V_4 , V_8 -> V_285 [ V_246 ] . V_287 ) )
return false ;
F_156 ( V_4 , & V_8 -> V_337 , V_246 ) ;
return true ;
}
static void F_159 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_178 )
return;
if ( ! F_158 ( V_4 , V_8 -> V_349 , true ) )
if ( ! F_158 ( V_4 , V_8 -> V_350 , true ) )
F_158 ( V_4 , V_8 -> V_351 , false ) ;
}
static void F_160 ( struct V_3 * V_4 , unsigned int V_104 )
{
switch ( F_161 ( V_4 , V_104 >> 26 ) ) {
case V_105 :
F_146 ( V_4 ) ;
break;
case V_352 :
F_147 ( V_4 ) ;
break;
case V_106 :
F_159 ( V_4 ) ;
break;
}
F_162 ( V_4 ) ;
}
static void F_163 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_353 [ V_354 + 1 ] ;
int V_66 ;
for ( V_66 = 0 ; V_66 < F_71 ( V_353 ) ; V_66 ++ )
V_353 [ V_66 ] = - 1 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_337 . V_247 ; V_66 ++ ) {
T_1 V_287 = V_8 -> V_285 [ V_66 ] . V_287 ;
unsigned int V_355 = F_126 ( V_4 , V_287 ) ;
int type , V_356 ;
V_356 = F_164 ( V_355 ) ;
if ( V_356 == V_357 )
return;
if ( V_356 > V_354 )
V_356 = V_354 ;
if ( V_356 != V_358 &&
! F_141 ( V_4 , V_287 ) )
return;
type = F_165 ( V_355 ) ;
if ( type != V_359 &&
( V_356 != V_360 || type != V_361 ) )
return;
if ( V_353 [ V_356 ] >= 0 )
return;
V_353 [ V_356 ] = V_66 ;
}
if ( V_353 [ V_358 ] < 0 ||
( V_353 [ V_354 ] < 0 && V_353 [ V_360 ] ) )
return;
V_8 -> V_178 = 1 ;
V_8 -> V_349 = V_353 [ V_354 ] ;
V_8 -> V_350 = V_353 [ V_360 ] ;
V_8 -> V_351 = V_353 [ V_358 ] ;
}
static void F_166 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
struct V_244 * V_245 ;
int V_66 , V_307 ;
V_245 = & V_8 -> V_337 ;
for ( V_66 = 0 ; V_66 < V_252 -> V_362 ; V_66 ++ ) {
for ( V_307 = 0 ; V_307 < V_8 -> V_39 ; V_307 ++ ) {
T_1 V_284 = V_8 -> V_13 [ V_307 ] ;
int V_246 = F_155 ( V_4 , V_284 ,
V_252 -> V_363 [ V_66 ] . V_287 ) ;
if ( V_246 >= 0 ) {
const char * V_364 ;
V_364 = F_167 ( V_4 , V_252 , V_66 ) ;
V_8 -> V_285 [ V_245 -> V_247 ] . V_217 = V_66 ;
V_8 -> V_285 [ V_245 -> V_247 ] . V_365 = 0 ;
V_8 -> V_285 [ V_245 -> V_247 ] . V_284 = V_284 ;
V_8 -> V_285 [ V_245 -> V_247 ] . V_287 =
V_252 -> V_363 [ V_66 ] . V_287 ;
F_168 ( V_245 , V_364 , V_246 , NULL ) ;
break;
}
}
}
if ( V_245 -> V_247 >= 2 && V_252 -> V_362 == V_245 -> V_247 )
F_163 ( V_4 ) ;
if ( V_245 -> V_247 > 1 ) {
for ( V_66 = 1 ; V_66 < V_245 -> V_247 ; V_66 ++ ) {
if ( V_8 -> V_285 [ V_66 ] . V_284 != V_8 -> V_285 [ 0 ] . V_284 ) {
V_8 -> V_286 = 1 ;
break;
}
}
}
}
static T_1 F_169 ( struct V_3 * V_4 , T_1 V_287 )
{
T_1 V_31 , V_291 ;
V_291 = V_4 -> V_292 + V_4 -> V_293 ;
for ( V_31 = V_4 -> V_292 ; V_31 < V_291 ; V_31 ++ ) {
unsigned int V_294 = F_137 ( V_4 , V_31 ) ;
unsigned int type = F_138 ( V_294 ) ;
if ( type == V_344 && ( V_294 & V_296 ) ) {
if ( F_135 ( V_4 , V_31 , V_287 ) >= 0 )
return V_31 ;
}
}
return 0 ;
}
static void F_170 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
T_1 V_31 ;
if ( V_252 -> V_366 &&
F_128 ( V_4 , V_252 -> V_367 [ 0 ] , & V_31 , 1 ) == 1 )
V_8 -> V_9 . V_40 = V_31 ;
if ( V_252 -> V_368 )
V_8 -> V_44 = F_169 ( V_4 , V_252 -> V_368 ) ;
}
static void F_171 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_291 ;
V_291 = V_4 -> V_292 + V_4 -> V_293 ;
for ( V_31 = V_4 -> V_292 ; V_31 < V_291 ; V_31 ++ )
if ( F_138 ( F_137 ( V_4 , V_31 ) ) == V_369 ) {
F_72 ( V_8 , V_31 , 0 , V_76 ) ;
break;
}
}
static void F_172 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_291 ;
V_291 = V_4 -> V_292 + V_4 -> V_293 ;
for ( V_31 = V_4 -> V_292 ; V_31 < V_291 ; V_31 ++ ) {
if ( F_138 ( F_137 ( V_4 , V_31 ) ) != V_370 )
continue;
if ( ! ( F_173 ( V_4 , V_31 ) & V_371 ) )
continue;
V_8 -> V_372 [ V_8 -> V_373 ++ ] = V_31 ;
if ( V_8 -> V_373 >= F_71 ( V_8 -> V_372 ) )
break;
}
V_8 -> V_327 = V_8 -> V_373 > 2 ;
}
static int F_174 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_70 ;
V_70 = F_175 ( V_4 , & V_8 -> V_306 , NULL ) ;
if ( V_70 < 0 )
return V_70 ;
F_140 ( V_4 ) ;
F_166 ( V_4 ) ;
F_170 ( V_4 ) ;
F_171 ( V_4 ) ;
F_172 ( V_4 ) ;
return 0 ;
}
static void F_143 ( struct V_3 * V_4 , int V_250 ,
T_1 * V_298 , bool V_326 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_250 ; V_66 ++ ) {
if ( F_173 ( V_4 , V_298 [ V_66 ] ) & V_371 )
F_86 ( V_4 , V_298 [ V_66 ] , 0 ,
V_91 ,
V_326 ? 0x02 : 0 ) ;
}
}
static void F_176 ( struct V_3 * V_4 , T_1 V_287 ,
T_1 V_374 )
{
int V_246 = F_135 ( V_4 , V_287 , V_374 ) ;
if ( V_246 >= 0 )
F_86 ( V_4 , V_287 , 0 ,
V_180 , V_246 ) ;
}
static void F_177 ( struct V_3 * V_4 , int V_375 ,
const T_1 * V_376 )
{
int V_66 , V_335 ;
for ( V_66 = 0 ; V_66 < V_375 ; V_66 ++ ) {
T_1 V_31 = V_376 [ V_66 ] ;
if ( ! ( F_137 ( V_4 , V_31 ) & V_377 ) )
continue;
if ( F_178 ( V_4 , V_31 , V_76 ) & V_378 )
V_335 = V_149 ;
else
V_335 = V_379 ;
F_86 ( V_4 , V_31 , 0 ,
V_101 , V_335 ) ;
}
}
static void F_179 ( struct V_3 * V_4 , int V_250 ,
T_1 * V_298 , unsigned int V_380 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_250 ; V_66 ++ )
F_180 ( V_4 , V_298 [ V_66 ] , V_380 ) ;
}
static bool F_181 ( T_1 V_31 , const T_1 * V_381 , int V_289 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_289 ; V_66 ++ )
if ( V_381 [ V_66 ] == V_31 )
return true ;
return false ;
}
static bool F_182 ( struct V_305 * V_252 , T_1 V_31 )
{
int V_66 ;
if ( F_181 ( V_31 , V_252 -> V_308 , V_252 -> V_309 ) ||
F_181 ( V_31 , V_252 -> V_312 , V_252 -> V_313 ) ||
F_181 ( V_31 , V_252 -> V_315 , V_252 -> V_316 ) ||
F_181 ( V_31 , V_252 -> V_367 , V_252 -> V_366 ) )
return true ;
for ( V_66 = 0 ; V_66 < V_252 -> V_362 ; V_66 ++ )
if ( V_252 -> V_363 [ V_66 ] . V_287 == V_31 )
return true ;
if ( V_252 -> V_368 == V_31 )
return true ;
return false ;
}
static void F_183 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_4 -> V_382 . V_383 ; V_66 ++ ) {
struct V_384 * V_287 = F_184 ( & V_4 -> V_382 , V_66 ) ;
if ( ! F_182 ( V_252 , V_287 -> V_31 ) )
F_86 ( V_4 , V_287 -> V_31 , 0 ,
V_186 , 0 ) ;
}
}
static void F_185 ( void * V_385 , int V_386 )
{
struct V_3 * V_4 = V_385 ;
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_386 && V_8 -> V_327 ) {
F_145 ( V_4 ) ;
return;
}
F_143 ( V_4 , V_8 -> V_373 , V_8 -> V_372 , V_386 ) ;
}
static void F_186 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
T_1 V_31 ;
int V_66 ;
F_177 ( V_4 , V_8 -> V_9 . V_95 , V_8 -> V_9 . V_32 ) ;
for ( V_66 = 0 ; V_66 < V_252 -> V_313 ; V_66 ++ ) {
unsigned int V_335 = V_176 ;
if ( F_173 ( V_4 , V_252 -> V_312 [ V_66 ] ) &
V_387 )
V_335 |= V_388 ;
F_83 ( V_4 , V_252 -> V_312 [ V_66 ] , V_335 ) ;
}
F_177 ( V_4 , V_252 -> V_313 , V_252 -> V_312 ) ;
F_177 ( V_4 , V_252 -> V_309 , V_252 -> V_308 ) ;
F_177 ( V_4 , V_252 -> V_316 , V_252 -> V_315 ) ;
for ( V_66 = 0 ; V_66 < V_8 -> V_318 ; V_66 ++ ) {
V_31 = V_8 -> V_310 [ V_66 ] . V_303 ;
if ( ! V_31 )
V_31 = V_8 -> V_9 . V_32 [ 0 ] ;
else if ( V_31 & V_304 )
V_31 &= ~ V_304 ;
F_176 ( V_4 , V_8 -> V_310 [ V_66 ] . V_287 , V_31 ) ;
}
if ( V_8 -> V_322 ) {
F_179 ( V_4 , V_252 -> V_313 , V_252 -> V_312 ,
V_105 ) ;
V_8 -> V_97 = F_144 ( V_4 , V_252 -> V_313 ,
V_252 -> V_312 ) ;
if ( V_8 -> V_324 ) {
F_179 ( V_4 , V_252 -> V_309 ,
V_252 -> V_308 ,
V_352 ) ;
V_8 -> V_328 =
F_144 ( V_4 , V_252 -> V_309 ,
V_252 -> V_308 ) ;
}
}
F_145 ( V_4 ) ;
if ( ! V_8 -> V_327 )
F_143 ( V_4 , V_8 -> V_373 , V_8 -> V_372 , true ) ;
F_183 ( V_4 ) ;
}
static void F_187 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
int V_66 , V_335 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_39 ; V_66 ++ ) {
T_1 V_31 = V_8 -> V_13 [ V_66 ] ;
if ( ! ( F_137 ( V_4 , V_31 ) & V_389 ) )
continue;
if ( F_178 ( V_4 , V_31 , V_144 ) & V_378 )
V_335 = F_188 ( 0 ) ;
else
V_335 = F_189 ( 0 ) ;
F_86 ( V_4 , V_31 , 0 , V_101 ,
V_335 ) ;
}
for ( V_66 = 0 ; V_66 < V_252 -> V_362 ; V_66 ++ ) {
T_1 V_287 = V_252 -> V_363 [ V_66 ] . V_287 ;
unsigned int type = V_222 ;
if ( V_252 -> V_363 [ V_66 ] . type == V_390 )
type |= F_190 ( V_4 , V_287 ) ;
F_83 ( V_4 , V_287 , type ) ;
}
if ( V_8 -> V_178 ) {
if ( V_8 -> V_349 >= 0 ) {
F_180 ( V_4 ,
V_252 -> V_363 [ V_8 -> V_349 ] . V_287 ,
V_106 ) ;
}
if ( V_8 -> V_350 >= 0 ) {
F_180 ( V_4 ,
V_252 -> V_363 [ V_8 -> V_350 ] . V_287 ,
V_106 ) ;
}
F_159 ( V_4 ) ;
} else {
F_154 ( V_4 , V_8 -> V_285 [ 0 ] . V_284 ,
V_8 -> V_285 [ 0 ] . V_287 ) ;
}
}
static void F_191 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_305 * V_252 = & V_8 -> V_306 ;
if ( V_8 -> V_9 . V_40 )
F_83 ( V_4 , V_252 -> V_367 [ 0 ] , V_176 ) ;
if ( V_8 -> V_44 )
F_83 ( V_4 , V_252 -> V_368 , V_222 ) ;
}
static int F_192 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_193 ( V_4 ) ;
F_186 ( V_4 ) ;
F_187 ( V_4 ) ;
F_191 ( V_4 ) ;
F_162 ( V_4 ) ;
F_194 ( & V_8 -> V_78 ) ;
return 0 ;
}
static int F_195 ( struct V_3 * V_4 , const char * V_391 ,
const char * V_392 , int V_393 ,
T_1 V_31 , int V_394 , int V_395 , int V_396 )
{
static char V_25 [ 44 ] ;
static struct V_82 V_83 [] = {
F_196 ( V_25 , 0 , 0 , 0 ) ,
F_197 ( V_25 , 0 , 0 , 0 ) ,
} ;
static const char * const V_397 [ 2 ] = { L_20 , L_21 } ;
int V_66 , V_70 ;
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
struct V_47 * V_85 ;
V_83 [ V_66 ] . V_87 = F_198 ( V_31 , V_396 , V_395 ,
V_394 ) ;
V_83 [ V_66 ] . V_398 = V_399 ;
V_83 [ V_66 ] . V_217 = V_393 ;
snprintf ( V_25 , sizeof( V_25 ) , L_22 , V_391 , V_392 , V_397 [ V_66 ] ) ;
V_85 = F_47 ( & V_83 [ V_66 ] , V_4 ) ;
if ( ! V_85 )
return - V_86 ;
V_70 = F_48 ( V_4 , V_31 , V_85 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( ! ( F_178 ( V_4 , V_31 , V_394 ) &
( V_378 | V_400 ) ) )
break;
}
return 0 ;
}
static int F_199 ( struct V_3 * V_4 , T_1 V_303 ,
T_1 V_287 , const char * V_25 , int V_246 )
{
unsigned int V_401 ;
if ( V_303 && ! ( V_303 & V_304 ) ) {
V_401 = F_178 ( V_4 , V_303 , V_76 ) ;
if ( V_401 & V_402 )
return F_200 ( V_4 , V_303 , V_25 , V_246 ) ;
}
V_401 = F_178 ( V_4 , V_287 , V_76 ) ;
if ( V_401 & V_402 )
return F_200 ( V_4 , V_287 , V_25 , V_246 ) ;
return 0 ;
}
static int F_201 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 , V_70 ;
int V_403 = 0 , V_404 = 0 , V_405 = 0 ;
static const char * const V_331 [ 3 ] = { L_23 , L_24 , L_25 } ;
if ( V_8 -> V_318 == 1 )
return F_199 ( V_4 , V_8 -> V_310 [ 0 ] . V_303 ,
V_8 -> V_310 [ 0 ] . V_287 ,
L_26 , 0 ) ;
for ( V_66 = 0 ; V_66 < V_8 -> V_318 ; V_66 ++ ) {
const char * V_364 ;
int V_246 , type ;
T_1 V_303 = V_8 -> V_310 [ V_66 ] . V_303 ;
type = V_8 -> V_310 [ V_66 ] . type ;
if ( type == V_311 )
type = V_8 -> V_306 . V_323 ;
switch ( type ) {
case V_311 :
default:
V_364 = V_331 [ V_403 ++ ] ;
V_246 = 0 ;
break;
case V_314 :
V_364 = L_27 ;
V_246 = V_404 ++ ;
break;
case V_317 :
V_364 = L_28 ;
V_246 = V_405 ++ ;
break;
}
V_70 = F_199 ( V_4 , V_303 ,
V_8 -> V_310 [ V_66 ] . V_287 ,
V_364 , V_246 ) ;
if ( V_70 < 0 )
return V_70 ;
}
if ( V_8 -> V_322 ) {
V_70 = F_38 ( V_4 , V_406 ) ;
if ( V_70 < 0 )
return V_70 ;
}
return 0 ;
}
static int F_202 ( struct V_3 * V_4 , const char * V_364 ,
char * V_407 , int V_31 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
if ( ! V_8 -> V_408 )
return 0 ;
for ( V_66 = 0 ; V_66 < V_409 ; V_66 ++ ) {
int V_355 ;
if ( V_8 -> V_306 . V_363 [ V_66 ] . V_287 != V_31 )
continue;
if ( V_8 -> V_306 . V_363 [ V_66 ] . type != V_390 )
return 0 ;
V_355 = F_126 ( V_4 , V_31 ) ;
if ( F_164 ( V_355 ) != V_358 )
return 0 ;
snprintf ( V_407 , 44 , L_29 , V_364 ) ;
return 1 ;
}
return 0 ;
}
static int F_203 ( struct V_3 * V_4 , T_1 V_31 ,
const char * V_364 , const char * V_410 ,
int V_393 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_39 ; V_66 ++ ) {
char V_411 [ 44 ] ;
T_1 V_412 = V_8 -> V_13 [ V_66 ] ;
int V_246 = F_155 ( V_4 , V_412 , V_31 ) ;
if ( V_246 < 0 )
continue;
if ( V_4 -> V_113 )
V_246 = 0 ;
if ( F_202 ( V_4 , V_364 , V_411 , V_31 ) ) {
int V_70 = F_195 ( V_4 , V_364 , V_410 ,
V_393 , V_412 , V_144 , V_246 , 1 ) ;
if ( V_70 < 0 )
return V_70 ;
return F_195 ( V_4 , V_411 , V_410 ,
V_393 , V_412 , V_144 , V_246 , 2 ) ;
}
return F_195 ( V_4 , V_364 , V_410 ,
V_393 , V_412 , V_144 , V_246 , 3 ) ;
}
return 0 ;
}
static int F_204 ( struct V_3 * V_4 , int V_246 ,
const char * V_364 , int V_393 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_338 , V_31 ;
int V_66 , V_413 ;
V_31 = V_8 -> V_285 [ V_246 ] . V_287 ;
if ( F_137 ( V_4 , V_31 ) & V_389 ) {
char V_411 [ 44 ] ;
if ( F_202 ( V_4 , V_364 , V_411 , V_31 ) ) {
int V_70 = F_195 ( V_4 , V_364 , L_30 ,
V_393 , V_31 , V_144 , 0 , 1 ) ;
if ( V_70 < 0 )
return V_70 ;
return F_195 ( V_4 , V_411 , L_30 ,
V_393 , V_31 , V_144 , 0 , 2 ) ;
}
return F_205 ( V_4 , V_364 , L_30 , V_393 ,
V_31 , V_144 ) ;
}
V_413 = F_153 ( V_4 , V_8 -> V_285 [ V_246 ] . V_284 , V_31 ,
& V_338 , false , 0 ) ;
if ( V_413 < 0 )
return 0 ;
for ( V_66 = 0 ; V_66 < V_246 ; V_66 ++ ) {
if ( V_8 -> V_285 [ V_66 ] . V_365 == V_338 )
return 0 ;
}
if ( F_137 ( V_4 , V_338 ) & V_377 ) {
V_8 -> V_285 [ V_246 ] . V_365 = V_338 ;
return F_205 ( V_4 , V_364 , L_30 , 0 ,
V_338 , V_76 ) ;
}
return 0 ;
}
static int F_206 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_244 * V_245 = & V_8 -> V_337 ;
const char * V_414 ;
int V_415 [ V_343 ] ;
int V_66 , V_307 , V_70 , V_393 ;
int V_416 ;
if ( ! V_245 -> V_247 )
return 0 ;
V_416 = 0 ;
for ( V_66 = 0 ; V_66 < V_245 -> V_247 ; V_66 ++ ) {
V_393 = F_155 ( V_4 , V_8 -> V_285 [ V_66 ] . V_284 ,
V_8 -> V_285 [ V_66 ] . V_287 ) ;
if ( V_393 < 0 )
continue;
V_415 [ V_66 ] = V_8 -> V_285 [ V_66 ] . V_284 ;
if ( ! V_4 -> V_113 )
V_415 [ V_66 ] |= V_393 << 8 ;
if ( V_66 > 0 && V_415 [ V_66 ] != V_415 [ 0 ] )
V_416 = 1 ;
}
V_414 = NULL ;
V_393 = 0 ;
for ( V_66 = 0 ; V_66 < V_245 -> V_247 ; V_66 ++ ) {
T_1 V_31 = V_8 -> V_285 [ V_66 ] . V_287 ;
const char * V_364 ;
V_364 = F_167 ( V_4 , & V_8 -> V_306 ,
V_8 -> V_285 [ V_66 ] . V_217 ) ;
if ( V_364 == V_414 )
V_393 ++ ;
else
V_393 = 0 ;
V_414 = V_364 ;
V_70 = F_204 ( V_4 , V_66 , V_364 , V_393 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( ! V_416 ) {
if ( V_66 > 0 )
continue;
V_70 = F_203 ( V_4 , V_31 ,
L_31 , L_32 , V_393 ) ;
} else {
bool V_417 = false ;
for ( V_307 = 0 ; V_307 < V_66 ; V_307 ++ ) {
if ( V_415 [ V_307 ] == V_415 [ V_66 ] ) {
V_417 = true ;
break;
}
}
if ( V_417 )
continue;
V_70 = F_203 ( V_4 , V_31 ,
V_364 , L_33 , V_393 ) ;
}
if ( V_70 < 0 )
return V_70 ;
}
if ( V_8 -> V_337 . V_247 > 1 && ! V_8 -> V_178 ) {
V_70 = F_38 ( V_4 , V_418 ) ;
if ( V_70 < 0 )
return V_70 ;
}
return 0 ;
}
static int F_207 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_70 ;
V_70 = F_201 ( V_4 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_206 ( V_4 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_37 ( V_4 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_208 ( V_4 , & V_8 -> V_306 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_8 -> V_78 . V_79 ) {
V_8 -> V_78 . V_419 = F_185 ;
V_70 = F_209 ( V_4 , & V_8 -> V_78 ,
V_8 -> V_420 ) ;
if ( V_70 < 0 )
return V_70 ;
}
return 0 ;
}
static int F_210 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_291 ;
V_291 = V_4 -> V_292 + V_4 -> V_293 ;
for ( V_31 = V_4 -> V_292 ; V_31 < V_291 ; V_31 ++ ) {
unsigned int V_401 = F_137 ( V_4 , V_31 ) ;
if ( F_138 ( V_401 ) != V_344 )
continue;
if ( V_401 & V_296 )
continue;
if ( F_211 ( V_8 -> V_39 >=
F_71 ( V_8 -> V_421 ) ) )
break;
V_8 -> V_421 [ V_8 -> V_39 ++ ] = V_31 ;
}
V_8 -> V_13 = V_8 -> V_421 ;
return 0 ;
}
static void F_212 ( struct V_3 * V_4 ,
const struct V_422 * V_423 , int V_380 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_408 = 1 ;
}
static void F_213 ( struct V_3 * V_4 )
{
static T_1 V_424 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_425 ;
for ( V_425 = V_424 ; * V_425 ; V_425 ++ )
F_74 ( V_4 , * V_425 , V_76 ,
V_400 |
F_178 ( V_4 , * V_425 , V_76 ) ) ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_70 ;
F_214 ( V_426 L_34 ,
V_4 -> V_427 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
F_215 ( & V_8 -> V_69 ) ;
switch ( V_4 -> V_35 ) {
case 0x14f15045 :
V_4 -> V_113 = 1 ;
break;
case 0x14f15051 :
F_213 ( V_4 ) ;
V_4 -> V_155 = 1 ;
F_216 ( V_4 , NULL , V_428 , V_429 ) ;
break;
default:
V_4 -> V_155 = 1 ;
F_216 ( V_4 , NULL , V_430 , V_429 ) ;
break;
}
F_217 ( V_4 , V_431 ) ;
switch ( V_4 -> V_143 >> 16 ) {
case 0x103c :
V_8 -> V_420 = 1 ;
break;
}
V_70 = F_210 ( V_4 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_174 ( V_4 ) ;
if ( V_70 < 0 ) {
F_36 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
return V_70 ;
}
V_8 -> V_33 = & V_432 ;
V_4 -> V_123 = V_433 ;
if ( V_8 -> V_81 )
F_75 ( V_4 , V_8 -> V_81 ) ;
if ( ! V_4 -> V_434 -> V_435 ) {
F_218 ( L_35
L_36 ) ;
V_4 -> V_434 -> V_435 = 1 ;
V_4 -> V_434 -> V_436 = 1 ;
}
return 0 ;
}
static int T_2 F_219 ( void )
{
return F_220 ( & V_437 ) ;
}
static void T_3 F_221 ( void )
{
F_222 ( & V_437 ) ;
}
