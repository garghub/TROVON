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
static int F_49 ( struct V_3 * V_4 , T_2 V_88 )
{
F_50 ( V_4 ) ;
return 0 ;
}
static int F_51 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_89 = ( V_48 -> V_87 >> 8 ) & 1 ;
if ( V_89 )
V_53 -> V_56 . integer . V_56 [ 0 ] = ! V_8 -> V_90 ;
else
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_90 ;
return 0 ;
}
static int F_52 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_89 = ( V_48 -> V_87 >> 8 ) & 1 ;
T_1 V_31 = V_48 -> V_87 & 0xff ;
unsigned int V_91 ;
V_91 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_89 )
V_91 = ! V_91 ;
if ( V_91 == V_8 -> V_90 )
return 0 ;
V_8 -> V_90 = V_91 ;
F_53 ( V_4 , V_31 ,
0 , V_92 ,
V_91 ? 0x02 : 0x00 ) ;
return 1 ;
}
static int F_54 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_55 ( V_4 , V_50 , V_8 -> V_93 ,
V_8 -> V_94 ) ;
}
static int F_56 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_57 ( V_4 , V_53 , V_8 -> V_93 ,
V_8 -> V_94 ,
V_8 -> V_9 . V_30 ) ;
}
static int F_58 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_70 = F_59 ( V_4 , V_53 , V_8 -> V_93 ,
V_8 -> V_94 ,
& V_8 -> V_9 . V_30 ) ;
if ( V_70 >= 0 && V_8 -> V_95 )
V_8 -> V_9 . V_96 = V_8 -> V_9 . V_30 / 2 ;
return V_70 ;
}
static int F_60 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_97 ;
if ( ! F_52 ( V_48 , V_53 ) )
return 0 ;
V_97 = ( ! V_8 -> V_98 && V_8 -> V_90 ) ? 0 : V_99 ;
F_61 ( V_4 , 0x10 , V_76 , 0 ,
V_99 , V_97 ) ;
V_97 = V_8 -> V_90 ? 0 : V_99 ;
F_61 ( V_4 , 0x11 , V_76 , 0 ,
V_99 , V_97 ) ;
return 1 ;
}
static void F_62 ( struct V_3 * V_4 )
{
static const struct V_100 V_101 [] = {
{ 0x14 , V_102 , 0xb080 } ,
{ 0x12 , V_102 , 0xb000 } ,
{}
} ;
static const struct V_100 V_103 [] = {
{ 0x12 , V_102 , 0xb080 } ,
{ 0x14 , V_102 , 0xb000 } ,
{}
} ;
unsigned int V_104 ;
V_104 = F_63 ( V_4 , 0x12 ) ;
if ( V_104 )
F_32 ( V_4 , V_101 ) ;
else
F_32 ( V_4 , V_103 ) ;
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_97 ;
V_8 -> V_98 = F_63 ( V_4 , 0x11 ) ;
V_97 = ( V_8 -> V_98 || ! V_8 -> V_90 ) ? V_99 : 0 ;
F_61 ( V_4 , 0x10 , V_76 , 0 ,
V_99 , V_97 ) ;
}
static void F_65 ( struct V_3 * V_4 ,
unsigned int V_105 )
{
V_105 >>= 26 ;
switch ( V_105 ) {
case V_106 :
F_64 ( V_4 ) ;
break;
case V_107 :
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
int V_108 ;
V_108 = F_68 ( V_4 , V_109 ,
V_110 ,
V_111 ) ;
if ( V_108 < 0 )
V_108 = V_112 ;
if ( V_108 == V_112 )
return F_69 ( V_4 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_113 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_114 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_96 = F_71 ( V_115 ) ;
V_8 -> V_9 . V_32 = V_115 ;
V_8 -> V_9 . V_40 = V_116 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_117 ;
V_8 -> V_60 = V_118 ;
V_8 -> V_51 = & V_119 ;
V_8 -> V_71 = 1 ;
V_8 -> V_72 [ 0 ] = V_120 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_121 ;
V_8 -> V_122 = 0 ;
V_8 -> V_94 = F_71 ( V_123 ) ;
V_8 -> V_93 = V_123 ;
F_72 ( V_8 , 0x16 , 0 , 1 ) ;
V_4 -> V_124 = V_125 ;
switch ( V_108 ) {
case V_126 :
V_4 -> V_124 . V_127 = F_65 ;
V_8 -> V_51 = & V_119 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_128 ;
V_8 -> V_72 [ 0 ] = V_120 ;
V_4 -> V_124 . V_129 = F_66 ;
break;
case V_130 :
V_4 -> V_124 . V_127 = F_65 ;
V_8 -> V_51 = & V_119 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_131 ;
V_8 -> V_72 [ 0 ] = V_120 ;
V_4 -> V_124 . V_129 = F_66 ;
break;
default:
case V_132 :
V_4 -> V_124 . V_127 = F_65 ;
V_8 -> V_51 = & V_119 ;
V_8 -> V_67 = 3 ;
V_8 -> V_68 [ 1 ] = V_128 ;
V_8 -> V_68 [ 2 ] = V_131 ;
V_8 -> V_72 [ 0 ] = V_120 ;
V_4 -> V_124 . V_129 = F_66 ;
break;
case V_133 :
V_4 -> V_124 . V_127 = F_65 ;
V_8 -> V_51 = & V_134 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_135 ;
V_8 -> V_72 [ 0 ] = V_120 ;
V_8 -> V_72 [ 1 ] = V_136 ;
V_8 -> V_71 = 2 ;
V_4 -> V_124 . V_129 = F_66 ;
break;
case V_137 :
V_4 -> V_124 . V_127 = F_65 ;
V_8 -> V_51 = & V_138 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_128 ;
V_8 -> V_72 [ 0 ] = V_139 ;
V_4 -> V_124 . V_129 = F_66 ;
break;
#ifdef F_73
case V_140 :
V_8 -> V_51 = & V_141 ;
V_8 -> V_72 [ 0 ] = V_142 ;
V_8 -> V_68 [ 0 ] = V_143 ;
break;
#endif
}
switch ( V_4 -> V_144 >> 16 ) {
case 0x103c :
case 0x1631 :
case 0x1734 :
case 0x17aa :
F_74 ( V_4 , 0x17 , V_145 ,
( 0x14 << V_146 ) |
( 0x14 << V_147 ) |
( 0x05 << V_148 ) |
( 1 << V_149 ) ) ;
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
unsigned int V_97 ;
if ( ! F_52 ( V_48 , V_53 ) )
return 0 ;
V_97 = ( ! V_8 -> V_98 && V_8 -> V_90 ) ? 0 : V_99 ;
F_61 ( V_4 , 0x1d , V_76 , 0x01 ,
V_99 , V_97 ) ;
V_97 = V_8 -> V_90 ? 0 : V_99 ;
F_61 ( V_4 , 0x13 , V_76 , 0 ,
V_99 , V_97 ) ;
return 1 ;
}
static void F_77 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_97 ;
V_8 -> V_98 = F_63 ( V_4 , 0x13 ) ;
V_97 = ( V_8 -> V_98 || ! V_8 -> V_90 ) ? V_99 : 0 ;
F_61 ( V_4 , 0x1d , V_76 , 0x01 ,
V_99 , V_97 ) ;
}
static void F_78 ( struct V_3 * V_4 )
{
static const struct V_100 V_101 [] = {
{ 0x15 , V_102 , V_150 } ,
{ 0x17 , V_102 , V_151 } ,
{}
} ;
static const struct V_100 V_103 [] = {
{ 0x17 , V_102 , V_150 } ,
{ 0x15 , V_102 , V_151 } ,
{}
} ;
unsigned int V_104 ;
V_104 = F_63 ( V_4 , 0x15 ) ;
if ( V_104 )
F_32 ( V_4 , V_101 ) ;
else
F_32 ( V_4 , V_103 ) ;
}
static void F_79 ( struct V_3 * V_4 ,
unsigned int V_105 )
{
switch ( V_105 >> 26 ) {
case V_106 :
F_77 ( V_4 ) ;
break;
case V_107 :
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
int V_108 ;
V_108 = F_68 ( V_4 , V_152 ,
V_153 ,
V_154 ) ;
if ( V_108 < 0 )
V_108 = V_155 ;
if ( V_108 == V_155 )
return F_69 ( V_4 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_113 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_156 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_96 = F_71 ( V_157 ) ;
V_8 -> V_9 . V_32 = V_157 ;
V_8 -> V_9 . V_40 = V_158 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_159 ;
V_8 -> V_60 = V_160 ;
V_8 -> V_71 = 1 ;
V_8 -> V_72 [ 0 ] = V_161 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_162 ;
V_8 -> V_122 = 0 ;
V_8 -> V_94 = F_71 ( V_163 ) ,
V_8 -> V_93 = V_163 ,
V_4 -> V_124 = V_125 ;
switch ( V_108 ) {
case V_164 :
V_8 -> V_71 = 2 ;
V_8 -> V_72 [ 1 ] = V_165 ;
V_4 -> V_124 . V_127 = F_79 ;
break;
case V_166 :
V_8 -> V_71 = 2 ;
V_8 -> V_72 [ 1 ] = V_167 ;
V_4 -> V_124 . V_127 = F_79 ;
V_4 -> V_124 . V_129 = F_80 ;
break;
case V_168 :
V_8 -> V_51 = & V_169 ;
V_8 -> V_71 = 2 ;
V_8 -> V_72 [ 1 ] = V_165 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_170 ;
V_4 -> V_124 . V_127 = F_79 ;
break;
#ifdef F_73
case V_171 :
V_8 -> V_51 = & V_172 ;
V_8 -> V_72 [ 0 ] = V_173 ;
V_8 -> V_68 [ 0 ] = V_174 ;
V_4 -> V_124 . V_127 = F_79 ;
#endif
}
V_8 -> V_74 = 0x13 ;
switch ( V_4 -> V_144 >> 16 ) {
case 0x103c :
F_74 ( V_4 , 0x10 , V_145 ,
( 0x17 << V_146 ) |
( 0x17 << V_147 ) |
( 0x05 << V_148 ) |
( 1 << V_149 ) ) ;
break;
}
return 0 ;
}
static void F_82 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_175 ;
V_175 = ( V_8 -> V_98 && V_8 -> V_90 ) ? V_176 : 0 ;
F_83 ( V_4 , 0x16 , V_175 ) ;
V_175 = ( ! V_8 -> V_98 && V_8 -> V_90 ) ? V_177 : 0 ;
F_83 ( V_4 , 0x1a , V_175 ) ;
if ( V_8 -> V_178 )
F_83 ( V_4 , 0x1b , V_175 ) ;
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
unsigned int V_104 ;
if ( ! ( V_8 -> V_179 & V_180 ) )
return;
V_104 = F_63 ( V_4 , 0x17 ) ;
F_86 ( V_4 , 0x14 , 0 ,
V_181 ,
V_104 ? 0x01 : 0x00 ) ;
}
static void F_87 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_104 ;
T_1 V_182 ;
if ( ! ( V_8 -> V_179 & V_183 ) )
return;
V_104 = F_63 ( V_4 , 0x18 ) ;
if ( V_104 )
V_8 -> V_17 = 1 ;
else
V_8 -> V_17 = 0 ;
V_182 = V_8 -> V_13 [ V_8 -> V_17 ] ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_182 ) {
F_88 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_182 ;
F_14 ( V_4 , V_182 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
}
static void F_89 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_98 = F_63 ( V_4 , 0x16 ) ;
F_82 ( V_4 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
unsigned int V_105 )
{
switch ( V_105 >> 26 ) {
case V_106 :
F_89 ( V_4 ) ;
break;
case V_184 :
F_85 ( V_4 ) ;
break;
case V_185 :
F_87 ( V_4 ) ;
break;
}
}
static void F_91 ( struct V_3 * V_4 , T_1 V_31 ,
unsigned int V_186 )
{
F_86 ( V_4 , V_31 , 0 ,
V_187 ,
V_188 | V_186 ) ;
}
static int F_92 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_31 ( V_4 ) ;
if ( V_8 -> V_179 & V_180 )
F_91 ( V_4 , 0x17 , V_184 ) ;
if ( V_8 -> V_179 & V_183 )
F_91 ( V_4 , 0x18 , V_185 ) ;
if ( V_4 -> V_124 . V_127 ) {
F_89 ( V_4 ) ;
F_85 ( V_4 ) ;
F_87 ( V_4 ) ;
}
return 0 ;
}
static int F_93 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_108 ;
V_108 = F_68 ( V_4 , V_189 ,
V_190 ,
V_191 ) ;
if ( V_108 < 0 )
V_108 = V_192 ;
if ( V_108 == V_192 )
return F_69 ( V_4 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_113 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_156 = 1 ;
V_4 -> V_124 = V_125 ;
V_4 -> V_124 . V_129 = F_92 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_96 = F_71 ( V_193 ) ;
V_8 -> V_9 . V_32 = V_193 ;
V_8 -> V_9 . V_40 = V_194 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_195 ;
V_8 -> V_71 = 2 ;
V_8 -> V_72 [ 0 ] = V_196 ;
V_8 -> V_72 [ 1 ] = V_197 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_198 ;
V_8 -> V_122 = 0 ;
V_8 -> V_94 = F_71 ( V_199 ) ;
V_8 -> V_93 = V_199 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_72 ( V_8 , 0x13 , 0 , V_76 ) ;
V_4 -> V_124 . V_127 = F_90 ;
V_8 -> V_179 = V_180 | V_183 ;
switch ( V_108 ) {
case V_200 :
V_8 -> V_72 [ 0 ] = V_201 ;
break;
case V_202 :
V_8 -> V_68 [ 0 ] = V_203 ;
V_8 -> V_72 [ 0 ] = V_204 ;
V_8 -> V_179 = 0 ;
break;
case V_205 :
V_8 -> V_68 [ 0 ] = V_206 ;
V_8 -> V_72 [ 0 ] = V_207 ;
V_8 -> V_179 = 0 ;
break;
case V_208 :
V_8 -> V_72 [ 0 ] = V_209 ;
V_8 -> V_179 = V_180 ;
break;
case V_210 :
V_8 -> V_68 [ V_8 -> V_67 ++ ] =
V_211 ;
V_8 -> V_178 = 1 ;
break;
}
if ( V_8 -> V_81 )
F_75 ( V_4 , V_8 -> V_81 ) ;
return 0 ;
}
static void F_94 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_175 ;
F_95 ( L_7 ,
V_8 -> V_98 , V_8 -> V_90 ) ;
V_175 = ( F_96 ( V_8 ) && V_8 -> V_90 ) ? V_176 : 0 ;
F_83 ( V_4 , 0x19 , V_175 ) ;
V_175 = V_8 -> V_90 ? V_8 -> V_212 : 0 ;
if ( V_8 -> V_213 || V_8 -> V_214 ) {
if ( F_96 ( V_8 ) )
V_175 = 0 ;
} else {
if ( ! F_97 ( V_8 ) )
V_175 = 0 ;
}
F_83 ( V_4 , 0x1c , V_175 ) ;
V_175 = ( ! V_8 -> V_98 && V_8 -> V_90 ) ? V_177 : 0 ;
F_83 ( V_4 , 0x1f , V_175 ) ;
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
V_215 . V_216 [ V_8 -> V_217 ] . V_218 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_219 )
return;
if ( V_8 -> V_220 ) {
const struct V_100 V_221 [] = {
{ 0x1b , V_222 , 0 } ,
{ 0x1e , V_222 , V_223 } ,
{} ,
} ;
F_32 ( V_4 , V_221 ) ;
F_99 ( V_4 ) ;
return;
}
F_83 ( V_4 , 0x1e , 0 ) ;
F_83 ( V_4 , 0x1a ,
V_8 -> V_224 ? V_225 : 0 ) ;
F_83 ( V_4 , 0x1b ,
V_8 -> V_224 ? 0 : V_226 ) ;
}
static void F_102 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_104 ;
if ( V_8 -> V_220 )
return;
V_104 = F_29 ( V_4 , 0x1a , 0 ,
V_227 , 0 ) & 0x80000000 ;
if ( V_104 )
F_95 ( L_8 ) ;
else
F_95 ( L_9 ) ;
F_86 ( V_4 , 0x17 , 0 , V_181 ,
V_104 ? 0 : 1 ) ;
V_8 -> V_224 = ! ! V_104 ;
F_101 ( V_4 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
unsigned int V_104 ;
struct V_100 V_224 [] = {
{ 0x1a , V_222 , V_226 } ,
{ 0x17 , V_181 , 0 } ,
{ 0x14 , V_181 , 0 } ,
{ 0x23 , V_222 , 0 } ,
{}
} ;
static const struct V_100 V_228 [] = {
{ 0x23 , V_222 , V_223 } ,
{ 0x14 , V_181 , 2 } ,
{ 0x1a , V_222 , 0 } ,
{}
} ;
V_104 = F_63 ( V_4 , 0x1a ) ;
if ( V_104 ) {
F_95 ( L_8 ) ;
F_32 ( V_4 , V_224 ) ;
} else {
F_95 ( L_9 ) ;
F_32 ( V_4 , V_228 ) ;
}
}
static void F_104 ( struct V_3 * V_4 )
{
unsigned int V_104 ;
struct V_100 V_224 [] = {
{ 0x14 , V_181 , 0 } ,
{ 0x1b , V_222 , V_226 } ,
{ 0x23 , V_222 , 0 } ,
{}
} ;
static const struct V_100 V_228 [] = {
{ 0x14 , V_181 , 2 } ,
{ 0x23 , V_222 , V_223 } ,
{ 0x1b , V_222 , 0 } ,
{}
} ;
V_104 = F_63 ( V_4 , 0x1b ) ;
if ( V_104 ) {
F_95 ( L_8 ) ;
F_32 ( V_4 , V_224 ) ;
} else {
F_95 ( L_9 ) ;
F_32 ( V_4 , V_228 ) ;
}
}
static void F_105 ( struct V_3 * V_4 )
{
unsigned int V_104 ;
V_104 = F_63 ( V_4 , 0x1b ) ;
F_95 ( L_10 , V_104 ) ;
F_86 ( V_4 , 0x17 , 0 , V_181 ,
V_104 ? 1 : 0 ) ;
}
static void F_106 ( struct V_3 * V_4 )
{
unsigned int V_104 ;
V_104 = F_63 ( V_4 , 0x1b ) ;
F_95 ( L_10 , V_104 ) ;
F_86 ( V_4 , 0x17 , 0 , V_181 ,
V_104 ? 1 : 3 ) ;
}
static void F_107 ( struct V_3 * V_4 )
{
unsigned int V_229 , V_230 ;
static const struct V_100 V_224 [] = {
{ 0x14 , V_181 , 0 } ,
{ 0x17 , V_181 , 1 } ,
{ 0x1b , V_222 , V_226 } ,
{ 0x23 , V_222 , 0 } ,
{ 0x1a , V_222 , 0 } ,
{}
} ;
static const struct V_100 V_231 [] = {
{ 0x14 , V_181 , 0 } ,
{ 0x17 , V_181 , 0 } ,
{ 0x1a , V_222 , V_226 } ,
{ 0x23 , V_222 , 0 } ,
{ 0x1b , V_222 , 0 } ,
{}
} ;
static const struct V_100 V_228 [] = {
{ 0x14 , V_181 , 2 } ,
{ 0x23 , V_222 , V_223 } ,
{ 0x1b , V_222 , 0 } ,
{ 0x1a , V_222 , 0 } ,
{}
} ;
V_229 = F_63 ( V_4 , 0x1b ) ;
V_230 = F_63 ( V_4 , 0x1a ) ;
if ( V_229 ) {
F_95 ( L_8 ) ;
F_32 ( V_4 , V_224 ) ;
} else if ( V_230 ) {
F_95 ( L_11 ) ;
F_32 ( V_4 , V_231 ) ;
} else {
F_95 ( L_9 ) ;
F_32 ( V_4 , V_228 ) ;
}
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_232 , V_233 ;
V_232 = F_63 ( V_4 , 0x19 ) ;
V_233 = F_63 ( V_4 , 0x1c ) ;
V_8 -> V_98 = V_232 ? V_234 : 0 ;
V_8 -> V_98 |= V_233 ? V_235 : 0 ;
F_95 ( L_12 ,
V_232 , V_233 , V_8 -> V_98 ) ;
F_94 ( V_4 ) ;
}
static void F_109 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 -> V_236 )
F_103 ( V_4 ) ;
else if ( V_8 -> V_178 )
F_104 ( V_4 ) ;
else if ( V_8 -> V_214 )
F_107 ( V_4 ) ;
else if ( V_8 -> V_237 )
F_106 ( V_4 ) ;
else if ( V_8 -> V_238 )
F_105 ( V_4 ) ;
}
static void F_110 ( struct V_3 * V_4 , unsigned int V_105 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_95 ( L_13 , V_105 , V_105 >> 26 ) ;
switch ( V_105 >> 26 ) {
case V_106 :
F_108 ( V_4 ) ;
break;
case V_107 :
if ( ! V_8 -> V_220 )
F_102 ( V_4 ) ;
break;
}
}
static void F_111 ( struct V_3 * V_4 , unsigned int V_105 )
{
F_95 ( L_13 , V_105 , V_105 >> 26 ) ;
switch ( V_105 >> 26 ) {
case V_106 :
F_108 ( V_4 ) ;
break;
case V_107 :
F_109 ( V_4 ) ;
break;
}
}
static void F_112 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_53 ( V_4 , 0x17 , 0 ,
V_102 ,
V_239 | V_240 | V_241 |
V_242 . V_216 [ V_8 -> V_243 ] . V_218 ) ;
if ( V_8 -> V_178 || V_8 -> V_214 ) {
F_53 ( V_4 , 0x23 , 0 ,
V_102 ,
V_239 | V_240 | V_244 |
V_242 .
V_216 [ V_8 -> V_243 ] . V_218 ) ;
}
}
static int F_113 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_242 , V_50 ) ;
}
static int F_114 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_243 ;
return 0 ;
}
static int F_115 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_245 * V_246 = & V_242 ;
unsigned int V_247 ;
V_247 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_247 >= V_246 -> V_248 )
V_247 = V_246 -> V_248 - 1 ;
V_8 -> V_243 = V_247 ;
if ( ! V_8 -> V_220 )
F_112 ( V_4 ) ;
return 1 ;
}
static void F_116 ( struct V_3 * V_4 )
{
const struct V_100 V_221 [] = {
{ 0x17 , V_102 , V_151 } ,
{ 0x17 , V_181 , 3 } ,
{}
} ;
F_32 ( V_4 , V_221 ) ;
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
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_220 ;
return 0 ;
}
static int F_119 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_220 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_220 == V_8 -> V_220 )
return 0 ;
V_8 -> V_220 = V_220 ;
if ( V_220 )
F_116 ( V_4 ) ;
else
F_117 ( V_4 ) ;
return 1 ;
}
static int F_120 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_215 , V_50 ) ;
}
static int F_121 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_217 ;
return 0 ;
}
static int F_122 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_245 * V_246 = & V_242 ;
unsigned int V_247 ;
V_247 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_247 >= V_246 -> V_248 )
V_247 = V_246 -> V_248 - 1 ;
V_8 -> V_217 = V_247 ;
if ( V_8 -> V_220 )
F_99 ( V_4 ) ;
return 1 ;
}
static void F_123 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_219 = 1 ;
F_101 ( V_4 ) ;
}
static void F_124 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_100 V_249 [] = {
{ 0x1a , V_222 , 0 } ,
{ 0x1b , V_222 , 0 } ,
{ 0x1e , V_222 , 0 } ,
{} ,
} ;
F_32 ( V_4 , V_249 ) ;
V_8 -> V_219 = 0 ;
}
static void F_125 ( struct V_3 * V_4 ,
const T_1 * V_250 ,
int V_251 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 * V_252 = & V_8 -> V_9 . V_40 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_251 ; V_66 ++ , V_250 ++ ) {
unsigned int V_253 = F_126 ( V_4 , * V_250 ) ;
if ( F_127 ( V_253 ) == V_254 )
continue;
if ( F_128 ( V_4 , * V_250 , V_252 , 1 ) != 1 )
continue;
if ( V_8 -> V_46 [ 0 ] )
V_252 ++ ;
else
V_252 = V_8 -> V_46 ;
}
}
static int F_129 ( struct V_3 * V_4 )
{
F_95 ( L_14 ) ;
F_31 ( V_4 ) ;
if ( V_4 -> V_124 . V_127 ) {
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
if ( ! V_8 -> V_220 ) {
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
int V_108 ;
V_108 = F_68 ( V_4 , V_255 ,
V_256 , V_257 ) ;
if ( V_108 < 0 )
V_108 = V_258 ;
if ( V_108 == V_258 )
return F_69 ( V_4 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_113 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_124 = V_125 ;
V_4 -> V_124 . V_129 = F_31 ;
V_8 -> V_213 = 0 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_96 = F_71 ( V_259 ) ;
V_8 -> V_9 . V_32 = V_259 ;
F_125 ( V_4 , V_260 ,
F_71 ( V_260 ) ) ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_261 ;
V_8 -> V_60 = V_262 ;
V_8 -> V_51 = & V_263 ;
V_8 -> V_212 = V_176 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_264 ;
V_8 -> V_94 = F_71 ( V_265 ) ;
V_8 -> V_93 = V_265 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_72 ( V_8 , 0x13 , 0 , V_76 ) ;
switch ( V_108 ) {
default:
case V_266 :
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_268 ;
break;
case V_269 :
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_268 ;
V_8 -> V_212 = V_177 ;
V_8 -> V_68 [ V_8 -> V_67 ] = V_270 ;
V_8 -> V_67 ++ ;
V_8 -> V_213 = 1 ;
break;
case V_271 :
case V_272 :
V_4 -> V_124 . V_129 = F_129 ;
V_4 -> V_124 . V_127 = F_111 ;
V_8 -> V_68 [ V_8 -> V_67 ] =
V_273 ;
V_8 -> V_67 ++ ;
V_8 -> V_237 = V_108 == V_272 ;
V_8 -> V_238 = V_108 == V_271 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_268 ;
if ( V_108 == V_272 )
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_212 = 0 ;
V_8 -> V_243 = 3 ;
break;
case V_274 :
V_4 -> V_124 . V_129 = F_130 ;
V_4 -> V_124 . V_127 = F_110 ;
V_8 -> V_68 [ 0 ] = V_275 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_276 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_277 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_268 ;
V_8 -> V_212 = 0 ;
V_8 -> V_243 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_12 = F_123 ;
V_8 -> V_15 = F_124 ;
break;
case V_278 :
V_4 -> V_124 . V_129 = F_129 ;
V_4 -> V_124 . V_127 = F_111 ;
V_8 -> V_68 [ 0 ] = V_279 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_276 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_268 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_280 ;
V_8 -> V_212 = 0 ;
V_8 -> V_236 = 1 ;
V_8 -> V_243 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_281 :
V_4 -> V_124 . V_129 = F_129 ;
V_4 -> V_124 . V_127 = F_111 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_268 ;
V_8 -> V_68 [ 0 ] = V_282 ;
V_8 -> V_212 = 0 ;
V_8 -> V_178 = 1 ;
V_8 -> V_243 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_283 :
V_4 -> V_124 . V_129 = F_129 ;
V_4 -> V_124 . V_127 = F_111 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_267 ;
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_268 ;
V_8 -> V_68 [ 0 ] = V_284 ;
V_8 -> V_214 = 1 ;
V_8 -> V_212 = V_177 ;
V_8 -> V_243 = 2 ;
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
T_1 V_285 = V_8 -> V_286 [ V_8 -> V_59 [ 0 ] ] . V_285 ;
if ( V_8 -> V_287 ) {
V_8 -> V_16 = V_285 ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_11 ;
}
F_14 ( V_4 , V_285 , V_10 , 0 , V_11 ) ;
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
static T_1 F_134 ( struct V_3 * V_4 , T_1 V_288 ,
T_1 * V_289 , int * V_96 )
{
int V_66 , V_290 = * V_96 ;
T_1 V_291 = 0 ;
for ( V_66 = 0 ; V_66 < V_290 ; V_66 ++ ) {
if ( F_135 ( V_4 , V_288 , V_289 [ V_66 ] ) >= 0 ) {
V_291 = V_289 [ V_66 ] ;
break;
}
}
if ( ! V_291 )
return 0 ;
if ( -- V_290 > 0 )
memmove ( V_289 , V_289 + 1 , V_290 * sizeof( T_1 ) ) ;
* V_96 = V_290 ;
return V_291 ;
}
static int F_136 ( struct V_3 * V_4 , T_1 * V_289 )
{
T_1 V_31 , V_292 ;
int V_290 = 0 ;
V_292 = V_4 -> V_293 + V_4 -> V_294 ;
for ( V_31 = V_4 -> V_293 ; V_31 < V_292 ; V_31 ++ ) {
unsigned int V_295 = F_137 ( V_4 , V_31 ) ;
unsigned int type = F_138 ( V_295 ) ;
if ( type == V_296 && ! ( V_295 & V_297 ) ) {
V_289 [ V_290 ++ ] = V_31 ;
if ( V_290 >= V_298 )
break;
}
}
return V_290 ;
}
static int F_139 ( struct V_3 * V_4 , T_1 * V_299 ,
int V_251 , T_1 * V_289 , int * V_300 ,
struct V_301 * V_302 , int V_290 ,
int type )
{
int V_66 , V_303 = V_290 ;
for ( V_66 = 0 ; V_66 < V_251 ; V_66 ++ , V_290 ++ ) {
V_302 [ V_290 ] . V_288 = V_299 [ V_66 ] ;
V_302 [ V_290 ] . type = type ;
V_302 [ V_290 ] . V_304 = F_134 ( V_4 , V_299 [ V_66 ] , V_289 , V_300 ) ;
if ( V_302 [ V_290 ] . V_304 )
continue;
if ( V_302 [ V_303 ] . V_304 && F_135 ( V_4 , V_299 [ V_66 ] , V_302 [ V_303 ] . V_304 ) >= 0 ) {
V_302 [ V_290 ] . V_304 = V_302 [ V_303 ] . V_304 | V_305 ;
continue;
}
if ( V_302 [ 0 ] . V_304 && F_135 ( V_4 , V_299 [ V_66 ] , V_302 [ 0 ] . V_304 ) >= 0 ) {
V_302 [ V_290 ] . V_304 = V_302 [ 0 ] . V_304 | V_305 ;
continue;
}
F_95 ( L_15 , V_299 [ V_66 ] ) ;
}
return V_290 ;
}
static void F_140 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
T_1 V_289 [ V_298 ] ;
int V_66 , V_308 , V_290 , V_300 ;
V_300 = F_136 ( V_4 , V_289 ) ;
V_290 = F_139 ( V_4 , V_253 -> V_309 , V_253 -> V_310 ,
V_289 , & V_300 , V_8 -> V_311 , 0 ,
V_312 ) ;
V_290 = F_139 ( V_4 , V_253 -> V_313 , V_253 -> V_314 ,
V_289 , & V_300 , V_8 -> V_311 , V_290 ,
V_315 ) ;
V_290 = F_139 ( V_4 , V_253 -> V_316 , V_253 -> V_317 ,
V_289 , & V_300 , V_8 -> V_311 , V_290 ,
V_318 ) ;
V_8 -> V_319 = V_290 ;
for ( V_66 = 0 ; V_66 < V_290 ; V_66 ++ ) {
T_1 V_304 = V_8 -> V_311 [ V_66 ] . V_304 ;
if ( ! V_304 || ( V_304 & V_305 ) )
continue;
switch ( V_8 -> V_311 [ V_66 ] . type ) {
case V_312 :
V_8 -> V_320 [ V_8 -> V_9 . V_96 ] = V_304 ;
V_8 -> V_9 . V_96 ++ ;
break;
case V_315 :
case V_318 :
if ( ! V_8 -> V_9 . V_321 ) {
V_8 -> V_9 . V_321 = V_304 ;
break;
}
for ( V_308 = 0 ; V_308 < F_71 ( V_8 -> V_9 . V_322 ) ; V_308 ++ )
if ( ! V_8 -> V_9 . V_322 [ V_308 ] ) {
V_8 -> V_9 . V_322 [ V_308 ] = V_304 ;
break;
}
break;
}
}
V_8 -> V_9 . V_32 = V_8 -> V_320 ;
V_8 -> V_9 . V_30 = V_8 -> V_9 . V_96 * 2 ;
for ( V_66 = 0 ; V_66 < V_253 -> V_314 ; V_66 ++ ) {
if ( F_141 ( V_4 , V_253 -> V_313 [ V_66 ] ) ) {
V_8 -> V_323 = 1 ;
break;
}
}
if ( V_8 -> V_323 &&
V_253 -> V_309 [ 0 ] &&
V_253 -> V_324 != V_318 &&
V_253 -> V_309 [ 0 ] != V_253 -> V_313 [ 0 ] &&
V_253 -> V_309 [ 0 ] != V_253 -> V_316 [ 0 ] ) {
for ( V_66 = 0 ; V_66 < V_253 -> V_310 ; V_66 ++ ) {
if ( F_141 ( V_4 , V_253 -> V_309 [ V_66 ] ) ) {
V_8 -> V_325 = 1 ;
break;
}
}
V_8 -> V_326 = V_8 -> V_325 ;
}
V_8 -> V_74 = V_8 -> V_320 [ 0 ] ;
}
static void F_142 ( struct V_3 * V_4 , int V_251 ,
T_1 * V_299 , bool V_327 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_251 ; V_66 ++ )
F_83 ( V_4 , V_299 [ V_66 ] , V_327 ? V_177 : 0 ) ;
if ( V_8 -> V_328 )
F_143 ( V_4 , V_251 , V_299 , V_327 ) ;
}
static int F_144 ( struct V_3 * V_4 , int V_251 , T_1 * V_299 )
{
int V_66 , V_104 = 0 ;
for ( V_66 = 0 ; V_66 < V_251 ; V_66 ++ ) {
T_1 V_31 = V_299 [ V_66 ] ;
if ( ! V_31 || ! F_141 ( V_4 , V_31 ) )
break;
V_104 |= F_63 ( V_4 , V_31 ) ;
}
return V_104 ;
}
static void F_145 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
int V_327 = 1 ;
if ( V_8 -> V_328 ) {
if ( V_8 -> V_323 )
V_327 = V_8 -> V_98 ;
F_143 ( V_4 , V_253 -> V_314 , V_253 -> V_313 , V_327 ) ;
}
if ( V_8 -> V_323 )
V_327 = ! ( V_8 -> V_98 ||
( V_8 -> V_325 && V_8 -> V_329 ) ) ;
F_142 ( V_4 , V_253 -> V_317 , V_253 -> V_316 , V_327 ) ;
if ( V_253 -> V_309 [ 0 ] == V_253 -> V_313 [ 0 ] ||
V_253 -> V_309 [ 0 ] == V_253 -> V_316 [ 0 ] )
return;
if ( V_8 -> V_323 ) {
if ( V_253 -> V_324 == V_318 ||
V_8 -> V_326 )
V_327 = ! V_8 -> V_98 ;
else
V_327 = 1 ;
}
F_142 ( V_4 , V_253 -> V_310 , V_253 -> V_309 , V_327 ) ;
}
static void F_146 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
if ( ! V_8 -> V_323 )
return;
V_8 -> V_98 = F_144 ( V_4 , V_253 -> V_314 , V_253 -> V_313 ) ;
F_145 ( V_4 ) ;
}
static void F_147 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
if ( ! V_8 -> V_323 || ! V_8 -> V_325 )
return;
V_8 -> V_329 = F_144 ( V_4 , V_253 -> V_310 ,
V_253 -> V_309 ) ;
F_145 ( V_4 ) ;
}
static int F_148 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
static const char * const V_330 [] = {
L_16 , L_17
} ;
static const char * const V_331 [] = {
L_16 , L_18 , L_19
} ;
const char * const * V_332 ;
V_50 -> type = V_333 ;
V_50 -> V_334 = 1 ;
if ( V_8 -> V_335 ) {
V_50 -> V_56 . V_57 . V_216 = 3 ;
V_332 = V_331 ;
} else {
V_50 -> V_56 . V_57 . V_216 = 2 ;
V_332 = V_330 ;
}
if ( V_50 -> V_56 . V_57 . V_58 >= V_50 -> V_56 . V_57 . V_216 )
V_50 -> V_56 . V_57 . V_58 = V_50 -> V_56 . V_57 . V_216 - 1 ;
strcpy ( V_50 -> V_56 . V_57 . V_25 ,
V_332 [ V_50 -> V_56 . V_57 . V_58 ] ) ;
return 0 ;
}
static int F_149 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_336 ;
if ( ! V_8 -> V_323 )
V_336 = 0 ;
else if ( ! V_8 -> V_326 )
V_336 = 1 ;
else
V_336 = 2 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_336 ;
return 0 ;
}
static int F_150 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
switch ( V_53 -> V_56 . V_57 . V_58 [ 0 ] ) {
case 0 :
if ( ! V_8 -> V_323 )
return 0 ;
V_8 -> V_323 = 0 ;
break;
case 1 :
if ( V_8 -> V_323 && ! V_8 -> V_326 )
return 0 ;
V_8 -> V_323 = 1 ;
V_8 -> V_326 = 0 ;
break;
case 2 :
if ( ! V_8 -> V_335 )
return - V_337 ;
if ( V_8 -> V_323 && V_8 -> V_326 )
return 0 ;
V_8 -> V_323 = 1 ;
V_8 -> V_326 = 1 ;
break;
default:
return - V_337 ;
}
F_145 ( V_4 ) ;
return 1 ;
}
static int F_151 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_22 ( & V_8 -> V_338 , V_50 ) ;
}
static int F_152 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_59 [ 0 ] ;
return 0 ;
}
static int F_153 ( struct V_3 * V_4 , T_1 V_339 ,
T_1 V_288 , T_1 * V_340 ,
bool V_341 , int V_342 )
{
T_1 V_343 [ V_344 ] ;
int V_66 , V_290 ;
switch ( F_138 ( F_137 ( V_4 , V_339 ) ) ) {
case V_345 :
case V_346 :
case V_347 :
break;
default:
return - 1 ;
}
V_290 = F_128 ( V_4 , V_339 , V_343 , F_71 ( V_343 ) ) ;
for ( V_66 = 0 ; V_66 < V_290 ; V_66 ++ )
if ( V_343 [ V_66 ] == V_288 ) {
if ( V_341 )
F_86 ( V_4 , V_339 , 0 ,
V_181 , V_66 ) ;
if ( V_340 )
* V_340 = V_339 ;
return V_66 ;
}
V_342 ++ ;
if ( V_342 == 2 )
return - 1 ;
for ( V_66 = 0 ; V_66 < V_290 ; V_66 ++ ) {
int V_291 = F_153 ( V_4 , V_343 [ V_66 ] , V_288 , V_340 ,
V_341 , V_342 ) ;
if ( V_291 >= 0 ) {
if ( V_341 )
F_86 ( V_4 , V_339 , 0 ,
V_181 , V_66 ) ;
return V_66 ;
}
}
return - 1 ;
}
static void F_154 ( struct V_3 * V_4 , T_1 V_339 ,
T_1 V_288 )
{
F_153 ( V_4 , V_339 , V_288 , NULL , true , 0 ) ;
}
static int F_155 ( struct V_3 * V_4 , T_1 V_339 ,
T_1 V_288 )
{
return F_153 ( V_4 , V_339 , V_288 , NULL , false , 0 ) ;
}
static int F_156 ( struct V_3 * V_4 ,
const struct V_245 * V_246 ,
unsigned int V_247 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_285 ;
int V_348 = 1 ;
if ( ! V_246 -> V_248 )
return 0 ;
if ( V_247 >= V_246 -> V_248 )
V_247 = V_246 -> V_248 - 1 ;
if ( V_8 -> V_59 [ 0 ] == V_247 )
V_348 = 0 ;
V_285 = V_8 -> V_286 [ V_247 ] . V_285 ;
F_154 ( V_4 , V_8 -> V_286 [ V_247 ] . V_285 ,
V_8 -> V_286 [ V_247 ] . V_288 ) ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_285 ) {
F_88 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_285 ;
F_14 ( V_4 , V_285 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
V_8 -> V_59 [ 0 ] = V_247 ;
return V_348 ;
}
static int F_157 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_156 ( V_4 , & V_8 -> V_338 ,
V_53 -> V_56 . V_57 . V_58 [ 0 ] ) ;
}
static bool F_158 ( struct V_3 * V_4 , int V_247 , bool V_349 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_247 < 0 )
return false ;
if ( V_349 && ! F_63 ( V_4 , V_8 -> V_286 [ V_247 ] . V_288 ) )
return false ;
F_156 ( V_4 , & V_8 -> V_338 , V_247 ) ;
return true ;
}
static void F_159 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_179 )
return;
if ( ! F_158 ( V_4 , V_8 -> V_350 , true ) )
if ( ! F_158 ( V_4 , V_8 -> V_351 , true ) )
F_158 ( V_4 , V_8 -> V_352 , false ) ;
}
static void F_160 ( struct V_3 * V_4 , unsigned int V_105 )
{
switch ( F_161 ( V_4 , V_105 >> 26 ) ) {
case V_106 :
F_146 ( V_4 ) ;
break;
case V_353 :
F_147 ( V_4 ) ;
break;
case V_107 :
F_159 ( V_4 ) ;
break;
}
F_162 ( V_4 ) ;
}
static void F_163 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_354 [ V_355 + 1 ] ;
int V_66 ;
for ( V_66 = 0 ; V_66 < F_71 ( V_354 ) ; V_66 ++ )
V_354 [ V_66 ] = - 1 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_338 . V_248 ; V_66 ++ ) {
T_1 V_288 = V_8 -> V_286 [ V_66 ] . V_288 ;
unsigned int V_356 = F_126 ( V_4 , V_288 ) ;
int type , V_357 ;
V_357 = F_164 ( V_356 ) ;
if ( V_357 == V_358 )
return;
if ( V_357 > V_355 )
V_357 = V_355 ;
if ( V_357 != V_359 &&
! F_141 ( V_4 , V_288 ) )
return;
type = F_165 ( V_356 ) ;
if ( type != V_360 &&
( V_357 != V_361 || type != V_362 ) )
return;
if ( V_354 [ V_357 ] >= 0 )
return;
V_354 [ V_357 ] = V_66 ;
}
if ( V_354 [ V_359 ] < 0 ||
( V_354 [ V_355 ] < 0 && V_354 [ V_361 ] ) )
return;
V_8 -> V_179 = 1 ;
V_8 -> V_350 = V_354 [ V_355 ] ;
V_8 -> V_351 = V_354 [ V_361 ] ;
V_8 -> V_352 = V_354 [ V_359 ] ;
}
static void F_166 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
struct V_245 * V_246 ;
int V_66 , V_308 ;
V_246 = & V_8 -> V_338 ;
for ( V_66 = 0 ; V_66 < V_253 -> V_363 ; V_66 ++ ) {
for ( V_308 = 0 ; V_308 < V_8 -> V_39 ; V_308 ++ ) {
T_1 V_285 = V_8 -> V_13 [ V_308 ] ;
int V_247 = F_155 ( V_4 , V_285 ,
V_253 -> V_364 [ V_66 ] . V_288 ) ;
if ( V_247 >= 0 ) {
const char * V_365 ;
V_365 = F_167 ( V_4 , V_253 , V_66 ) ;
V_8 -> V_286 [ V_246 -> V_248 ] . V_218 = V_66 ;
V_8 -> V_286 [ V_246 -> V_248 ] . V_366 = 0 ;
V_8 -> V_286 [ V_246 -> V_248 ] . V_285 = V_285 ;
V_8 -> V_286 [ V_246 -> V_248 ] . V_288 =
V_253 -> V_364 [ V_66 ] . V_288 ;
F_168 ( V_246 , V_365 , V_247 , NULL ) ;
break;
}
}
}
if ( V_246 -> V_248 >= 2 && V_253 -> V_363 == V_246 -> V_248 )
F_163 ( V_4 ) ;
if ( V_246 -> V_248 > 1 ) {
for ( V_66 = 1 ; V_66 < V_246 -> V_248 ; V_66 ++ ) {
if ( V_8 -> V_286 [ V_66 ] . V_285 != V_8 -> V_286 [ 0 ] . V_285 ) {
V_8 -> V_287 = 1 ;
break;
}
}
}
}
static T_1 F_169 ( struct V_3 * V_4 , T_1 V_288 )
{
T_1 V_31 , V_292 ;
V_292 = V_4 -> V_293 + V_4 -> V_294 ;
for ( V_31 = V_4 -> V_293 ; V_31 < V_292 ; V_31 ++ ) {
unsigned int V_295 = F_137 ( V_4 , V_31 ) ;
unsigned int type = F_138 ( V_295 ) ;
if ( type == V_345 && ( V_295 & V_297 ) ) {
if ( F_135 ( V_4 , V_31 , V_288 ) >= 0 )
return V_31 ;
}
}
return 0 ;
}
static void F_170 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
T_1 V_31 ;
if ( V_253 -> V_367 &&
F_128 ( V_4 , V_253 -> V_368 [ 0 ] , & V_31 , 1 ) == 1 )
V_8 -> V_9 . V_40 = V_31 ;
if ( V_253 -> V_369 )
V_8 -> V_44 = F_169 ( V_4 , V_253 -> V_369 ) ;
}
static void F_171 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_292 ;
V_292 = V_4 -> V_293 + V_4 -> V_294 ;
for ( V_31 = V_4 -> V_293 ; V_31 < V_292 ; V_31 ++ )
if ( F_138 ( F_137 ( V_4 , V_31 ) ) == V_370 ) {
F_72 ( V_8 , V_31 , 0 , V_76 ) ;
break;
}
}
static void F_172 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_292 ;
V_292 = V_4 -> V_293 + V_4 -> V_294 ;
for ( V_31 = V_4 -> V_293 ; V_31 < V_292 ; V_31 ++ ) {
if ( F_138 ( F_137 ( V_4 , V_31 ) ) != V_371 )
continue;
if ( ! ( F_173 ( V_4 , V_31 ) & V_372 ) )
continue;
V_8 -> V_373 [ V_8 -> V_374 ++ ] = V_31 ;
if ( V_8 -> V_374 >= F_71 ( V_8 -> V_373 ) )
break;
}
V_8 -> V_328 = V_8 -> V_374 > 2 ;
}
static int F_174 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_70 ;
V_70 = F_175 ( V_4 , & V_8 -> V_307 , NULL ) ;
if ( V_70 < 0 )
return V_70 ;
F_140 ( V_4 ) ;
F_166 ( V_4 ) ;
F_170 ( V_4 ) ;
F_171 ( V_4 ) ;
F_172 ( V_4 ) ;
return 0 ;
}
static void F_143 ( struct V_3 * V_4 , int V_251 ,
T_1 * V_299 , bool V_327 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_251 ; V_66 ++ ) {
if ( F_173 ( V_4 , V_299 [ V_66 ] ) & V_372 )
F_86 ( V_4 , V_299 [ V_66 ] , 0 ,
V_92 ,
V_327 ? 0x02 : 0 ) ;
}
}
static void F_176 ( struct V_3 * V_4 , T_1 V_288 ,
T_1 V_375 )
{
int V_247 = F_135 ( V_4 , V_288 , V_375 ) ;
if ( V_247 >= 0 )
F_86 ( V_4 , V_288 , 0 ,
V_181 , V_247 ) ;
}
static void F_177 ( struct V_3 * V_4 , int V_376 ,
const T_1 * V_377 )
{
int V_66 , V_336 ;
for ( V_66 = 0 ; V_66 < V_376 ; V_66 ++ ) {
T_1 V_31 = V_377 [ V_66 ] ;
if ( ! ( F_137 ( V_4 , V_31 ) & V_378 ) )
continue;
if ( F_178 ( V_4 , V_31 , V_76 ) & V_379 )
V_336 = V_150 ;
else
V_336 = V_380 ;
F_86 ( V_4 , V_31 , 0 ,
V_102 , V_336 ) ;
}
}
static void F_179 ( struct V_3 * V_4 , int V_251 ,
T_1 * V_299 , unsigned int V_381 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_251 ; V_66 ++ )
F_180 ( V_4 , V_299 [ V_66 ] , V_381 ) ;
}
static bool F_181 ( T_1 V_31 , const T_1 * V_382 , int V_290 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_290 ; V_66 ++ )
if ( V_382 [ V_66 ] == V_31 )
return true ;
return false ;
}
static bool F_182 ( struct V_306 * V_253 , T_1 V_31 )
{
int V_66 ;
if ( F_181 ( V_31 , V_253 -> V_309 , V_253 -> V_310 ) ||
F_181 ( V_31 , V_253 -> V_313 , V_253 -> V_314 ) ||
F_181 ( V_31 , V_253 -> V_316 , V_253 -> V_317 ) ||
F_181 ( V_31 , V_253 -> V_368 , V_253 -> V_367 ) )
return true ;
for ( V_66 = 0 ; V_66 < V_253 -> V_363 ; V_66 ++ )
if ( V_253 -> V_364 [ V_66 ] . V_288 == V_31 )
return true ;
if ( V_253 -> V_369 == V_31 )
return true ;
return false ;
}
static void F_183 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_4 -> V_383 . V_384 ; V_66 ++ ) {
struct V_385 * V_288 = F_184 ( & V_4 -> V_383 , V_66 ) ;
if ( ! F_182 ( V_253 , V_288 -> V_31 ) )
F_86 ( V_4 , V_288 -> V_31 , 0 ,
V_187 , 0 ) ;
}
}
static void F_185 ( void * V_386 , int V_387 )
{
struct V_3 * V_4 = V_386 ;
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_387 && V_8 -> V_328 ) {
F_145 ( V_4 ) ;
return;
}
F_143 ( V_4 , V_8 -> V_374 , V_8 -> V_373 , V_387 ) ;
}
static void F_186 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
T_1 V_31 ;
int V_66 ;
F_177 ( V_4 , V_8 -> V_9 . V_96 , V_8 -> V_9 . V_32 ) ;
for ( V_66 = 0 ; V_66 < V_253 -> V_314 ; V_66 ++ ) {
unsigned int V_336 = V_177 ;
if ( F_173 ( V_4 , V_253 -> V_313 [ V_66 ] ) &
V_388 )
V_336 |= V_389 ;
F_83 ( V_4 , V_253 -> V_313 [ V_66 ] , V_336 ) ;
}
F_177 ( V_4 , V_253 -> V_314 , V_253 -> V_313 ) ;
F_177 ( V_4 , V_253 -> V_310 , V_253 -> V_309 ) ;
F_177 ( V_4 , V_253 -> V_317 , V_253 -> V_316 ) ;
for ( V_66 = 0 ; V_66 < V_8 -> V_319 ; V_66 ++ ) {
V_31 = V_8 -> V_311 [ V_66 ] . V_304 ;
if ( ! V_31 )
V_31 = V_8 -> V_9 . V_32 [ 0 ] ;
else if ( V_31 & V_305 )
V_31 &= ~ V_305 ;
F_176 ( V_4 , V_8 -> V_311 [ V_66 ] . V_288 , V_31 ) ;
}
if ( V_8 -> V_323 ) {
F_179 ( V_4 , V_253 -> V_314 , V_253 -> V_313 ,
V_106 ) ;
V_8 -> V_98 = F_144 ( V_4 , V_253 -> V_314 ,
V_253 -> V_313 ) ;
if ( V_8 -> V_325 ) {
F_179 ( V_4 , V_253 -> V_310 ,
V_253 -> V_309 ,
V_353 ) ;
V_8 -> V_329 =
F_144 ( V_4 , V_253 -> V_310 ,
V_253 -> V_309 ) ;
}
}
F_145 ( V_4 ) ;
if ( ! V_8 -> V_328 )
F_143 ( V_4 , V_8 -> V_374 , V_8 -> V_373 , true ) ;
F_183 ( V_4 ) ;
}
static void F_187 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
int V_66 , V_336 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_39 ; V_66 ++ ) {
T_1 V_31 = V_8 -> V_13 [ V_66 ] ;
if ( ! ( F_137 ( V_4 , V_31 ) & V_390 ) )
continue;
if ( F_178 ( V_4 , V_31 , V_145 ) & V_379 )
V_336 = F_188 ( 0 ) ;
else
V_336 = F_189 ( 0 ) ;
F_86 ( V_4 , V_31 , 0 , V_102 ,
V_336 ) ;
}
for ( V_66 = 0 ; V_66 < V_253 -> V_363 ; V_66 ++ ) {
T_1 V_288 = V_253 -> V_364 [ V_66 ] . V_288 ;
unsigned int type = V_223 ;
if ( V_253 -> V_364 [ V_66 ] . type == V_391 )
type |= F_190 ( V_4 , V_288 ) ;
F_83 ( V_4 , V_288 , type ) ;
}
if ( V_8 -> V_179 ) {
if ( V_8 -> V_350 >= 0 ) {
F_180 ( V_4 ,
V_253 -> V_364 [ V_8 -> V_350 ] . V_288 ,
V_107 ) ;
}
if ( V_8 -> V_351 >= 0 ) {
F_180 ( V_4 ,
V_253 -> V_364 [ V_8 -> V_351 ] . V_288 ,
V_107 ) ;
}
F_159 ( V_4 ) ;
} else {
F_154 ( V_4 , V_8 -> V_286 [ 0 ] . V_285 ,
V_8 -> V_286 [ 0 ] . V_288 ) ;
}
}
static void F_191 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_253 = & V_8 -> V_307 ;
if ( V_8 -> V_9 . V_40 )
F_83 ( V_4 , V_253 -> V_368 [ 0 ] , V_177 ) ;
if ( V_8 -> V_44 )
F_83 ( V_4 , V_253 -> V_369 , V_223 ) ;
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
static int F_195 ( struct V_3 * V_4 , const char * V_392 ,
const char * V_393 , int V_394 ,
T_1 V_31 , int V_395 , int V_396 , int V_397 )
{
static char V_25 [ 44 ] ;
static struct V_82 V_83 [] = {
F_196 ( V_25 , 0 , 0 , 0 ) ,
F_197 ( V_25 , 0 , 0 , 0 ) ,
} ;
static const char * const V_398 [ 2 ] = { L_20 , L_21 } ;
int V_66 , V_70 ;
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
struct V_47 * V_85 ;
V_83 [ V_66 ] . V_87 = F_198 ( V_31 , V_397 , V_396 ,
V_395 ) ;
V_83 [ V_66 ] . V_399 = V_400 ;
V_83 [ V_66 ] . V_218 = V_394 ;
snprintf ( V_25 , sizeof( V_25 ) , L_22 , V_392 , V_393 , V_398 [ V_66 ] ) ;
V_85 = F_47 ( & V_83 [ V_66 ] , V_4 ) ;
if ( ! V_85 )
return - V_86 ;
V_70 = F_48 ( V_4 , V_31 , V_85 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( ! ( F_178 ( V_4 , V_31 , V_395 ) &
( V_379 | V_401 ) ) )
break;
}
return 0 ;
}
static int F_199 ( struct V_3 * V_4 , T_1 V_304 ,
T_1 V_288 , const char * V_25 , int V_247 )
{
unsigned int V_402 ;
if ( V_304 && ! ( V_304 & V_305 ) ) {
V_402 = F_178 ( V_4 , V_304 , V_76 ) ;
if ( V_402 & V_403 )
return F_200 ( V_4 , V_304 , V_25 , V_247 ) ;
}
V_402 = F_178 ( V_4 , V_288 , V_76 ) ;
if ( V_402 & V_403 )
return F_200 ( V_4 , V_288 , V_25 , V_247 ) ;
return 0 ;
}
static int F_201 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 , V_70 ;
int V_404 = 0 , V_405 = 0 , V_406 = 0 ;
static const char * const V_332 [ 3 ] = { L_23 , L_24 , L_25 } ;
if ( V_8 -> V_319 == 1 )
return F_199 ( V_4 , V_8 -> V_311 [ 0 ] . V_304 ,
V_8 -> V_311 [ 0 ] . V_288 ,
L_26 , 0 ) ;
for ( V_66 = 0 ; V_66 < V_8 -> V_319 ; V_66 ++ ) {
const char * V_365 ;
int V_247 , type ;
T_1 V_304 = V_8 -> V_311 [ V_66 ] . V_304 ;
type = V_8 -> V_311 [ V_66 ] . type ;
if ( type == V_312 )
type = V_8 -> V_307 . V_324 ;
switch ( type ) {
case V_312 :
default:
V_365 = V_332 [ V_404 ++ ] ;
V_247 = 0 ;
break;
case V_315 :
V_365 = L_27 ;
V_247 = V_405 ++ ;
break;
case V_318 :
V_365 = L_28 ;
V_247 = V_406 ++ ;
break;
}
V_70 = F_199 ( V_4 , V_304 ,
V_8 -> V_311 [ V_66 ] . V_288 ,
V_365 , V_247 ) ;
if ( V_70 < 0 )
return V_70 ;
}
if ( V_8 -> V_323 ) {
V_70 = F_38 ( V_4 , V_407 ) ;
if ( V_70 < 0 )
return V_70 ;
}
return 0 ;
}
static int F_202 ( struct V_3 * V_4 , const char * V_365 ,
char * V_408 , int V_31 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
if ( ! V_8 -> V_409 )
return 0 ;
for ( V_66 = 0 ; V_66 < V_410 ; V_66 ++ ) {
int V_356 ;
if ( V_8 -> V_307 . V_364 [ V_66 ] . V_288 != V_31 )
continue;
if ( V_8 -> V_307 . V_364 [ V_66 ] . type != V_391 )
return 0 ;
V_356 = F_126 ( V_4 , V_31 ) ;
if ( F_164 ( V_356 ) != V_359 )
return 0 ;
snprintf ( V_408 , 44 , L_29 , V_365 ) ;
return 1 ;
}
return 0 ;
}
static int F_203 ( struct V_3 * V_4 , T_1 V_31 ,
const char * V_365 , const char * V_411 ,
int V_394 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_39 ; V_66 ++ ) {
char V_412 [ 44 ] ;
T_1 V_413 = V_8 -> V_13 [ V_66 ] ;
int V_247 = F_155 ( V_4 , V_413 , V_31 ) ;
if ( V_247 < 0 )
continue;
if ( V_4 -> V_114 )
V_247 = 0 ;
if ( F_202 ( V_4 , V_365 , V_412 , V_31 ) ) {
int V_70 = F_195 ( V_4 , V_365 , V_411 ,
V_394 , V_413 , V_145 , V_247 , 1 ) ;
if ( V_70 < 0 )
return V_70 ;
return F_195 ( V_4 , V_412 , V_411 ,
V_394 , V_413 , V_145 , V_247 , 2 ) ;
}
return F_195 ( V_4 , V_365 , V_411 ,
V_394 , V_413 , V_145 , V_247 , 3 ) ;
}
return 0 ;
}
static int F_204 ( struct V_3 * V_4 , int V_247 ,
const char * V_365 , int V_394 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_339 , V_31 ;
int V_66 , V_414 ;
V_31 = V_8 -> V_286 [ V_247 ] . V_288 ;
if ( F_137 ( V_4 , V_31 ) & V_390 ) {
char V_412 [ 44 ] ;
if ( F_202 ( V_4 , V_365 , V_412 , V_31 ) ) {
int V_70 = F_195 ( V_4 , V_365 , L_30 ,
V_394 , V_31 , V_145 , 0 , 1 ) ;
if ( V_70 < 0 )
return V_70 ;
return F_195 ( V_4 , V_412 , L_30 ,
V_394 , V_31 , V_145 , 0 , 2 ) ;
}
return F_205 ( V_4 , V_365 , L_30 , V_394 ,
V_31 , V_145 ) ;
}
V_414 = F_153 ( V_4 , V_8 -> V_286 [ V_247 ] . V_285 , V_31 ,
& V_339 , false , 0 ) ;
if ( V_414 < 0 )
return 0 ;
for ( V_66 = 0 ; V_66 < V_247 ; V_66 ++ ) {
if ( V_8 -> V_286 [ V_66 ] . V_366 == V_339 )
return 0 ;
}
if ( F_137 ( V_4 , V_339 ) & V_378 ) {
V_8 -> V_286 [ V_247 ] . V_366 = V_339 ;
return F_205 ( V_4 , V_365 , L_30 , 0 ,
V_339 , V_76 ) ;
}
return 0 ;
}
static int F_206 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_245 * V_246 = & V_8 -> V_338 ;
const char * V_415 ;
int V_416 [ V_344 ] ;
int V_66 , V_308 , V_70 , V_394 ;
int V_417 ;
if ( ! V_246 -> V_248 )
return 0 ;
V_417 = 0 ;
for ( V_66 = 0 ; V_66 < V_246 -> V_248 ; V_66 ++ ) {
V_394 = F_155 ( V_4 , V_8 -> V_286 [ V_66 ] . V_285 ,
V_8 -> V_286 [ V_66 ] . V_288 ) ;
if ( V_394 < 0 )
continue;
V_416 [ V_66 ] = V_8 -> V_286 [ V_66 ] . V_285 ;
if ( ! V_4 -> V_114 )
V_416 [ V_66 ] |= V_394 << 8 ;
if ( V_66 > 0 && V_416 [ V_66 ] != V_416 [ 0 ] )
V_417 = 1 ;
}
V_415 = NULL ;
V_394 = 0 ;
for ( V_66 = 0 ; V_66 < V_246 -> V_248 ; V_66 ++ ) {
T_1 V_31 = V_8 -> V_286 [ V_66 ] . V_288 ;
const char * V_365 ;
V_365 = F_167 ( V_4 , & V_8 -> V_307 ,
V_8 -> V_286 [ V_66 ] . V_218 ) ;
if ( V_365 == V_415 )
V_394 ++ ;
else
V_394 = 0 ;
V_415 = V_365 ;
V_70 = F_204 ( V_4 , V_66 , V_365 , V_394 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( ! V_417 ) {
if ( V_66 > 0 )
continue;
V_70 = F_203 ( V_4 , V_31 ,
L_31 , L_32 , V_394 ) ;
} else {
bool V_418 = false ;
for ( V_308 = 0 ; V_308 < V_66 ; V_308 ++ ) {
if ( V_416 [ V_308 ] == V_416 [ V_66 ] ) {
V_418 = true ;
break;
}
}
if ( V_418 )
continue;
V_70 = F_203 ( V_4 , V_31 ,
V_365 , L_33 , V_394 ) ;
}
if ( V_70 < 0 )
return V_70 ;
}
if ( V_8 -> V_338 . V_248 > 1 && ! V_8 -> V_179 ) {
V_70 = F_38 ( V_4 , V_419 ) ;
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
V_70 = F_208 ( V_4 , & V_8 -> V_307 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_8 -> V_78 . V_79 ) {
V_8 -> V_78 . V_420 = F_185 ;
V_70 = F_209 ( V_4 , & V_8 -> V_78 ,
V_8 -> V_421 ) ;
if ( V_70 < 0 )
return V_70 ;
}
return 0 ;
}
static int F_210 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_292 ;
V_292 = V_4 -> V_293 + V_4 -> V_294 ;
for ( V_31 = V_4 -> V_293 ; V_31 < V_292 ; V_31 ++ ) {
unsigned int V_402 = F_137 ( V_4 , V_31 ) ;
if ( F_138 ( V_402 ) != V_345 )
continue;
if ( V_402 & V_297 )
continue;
if ( F_211 ( V_8 -> V_39 >=
F_71 ( V_8 -> V_422 ) ) )
break;
V_8 -> V_422 [ V_8 -> V_39 ++ ] = V_31 ;
}
V_8 -> V_13 = V_8 -> V_422 ;
return 0 ;
}
static void F_212 ( struct V_3 * V_4 ,
const struct V_423 * V_424 , int V_381 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_409 = 1 ;
}
static void F_213 ( struct V_3 * V_4 )
{
static T_1 V_425 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_426 ;
for ( V_426 = V_425 ; * V_426 ; V_426 ++ )
F_74 ( V_4 , * V_426 , V_76 ,
V_401 |
F_178 ( V_4 , * V_426 , V_76 ) ) ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_70 ;
F_214 ( V_427 L_34 ,
V_4 -> V_428 ) ;
V_8 = F_70 ( sizeof( * V_8 ) , V_113 ) ;
if ( ! V_8 )
return - V_86 ;
V_4 -> V_8 = V_8 ;
F_215 ( & V_8 -> V_69 ) ;
switch ( V_4 -> V_35 ) {
case 0x14f15045 :
V_4 -> V_114 = 1 ;
break;
case 0x14f15051 :
F_213 ( V_4 ) ;
V_4 -> V_156 = 1 ;
F_216 ( V_4 , NULL , V_429 , V_430 ) ;
break;
default:
V_4 -> V_156 = 1 ;
F_216 ( V_4 , NULL , V_431 , V_430 ) ;
break;
}
F_217 ( V_4 , V_432 ) ;
switch ( V_4 -> V_144 >> 16 ) {
case 0x103c :
V_8 -> V_421 = 1 ;
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
V_8 -> V_33 = & V_433 ;
V_4 -> V_124 = V_434 ;
if ( V_8 -> V_81 )
F_75 ( V_4 , V_8 -> V_81 ) ;
if ( ! V_4 -> V_435 -> V_436 ) {
F_218 ( L_35
L_36 ) ;
V_4 -> V_435 -> V_436 = 1 ;
V_4 -> V_435 -> V_437 = 1 ;
}
return 0 ;
}
static int T_3 F_219 ( void )
{
return F_220 ( & V_438 ) ;
}
static void T_4 F_221 ( void )
{
F_222 ( & V_438 ) ;
}
