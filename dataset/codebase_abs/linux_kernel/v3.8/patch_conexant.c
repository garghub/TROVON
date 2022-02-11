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
if ( F_20 ( V_8 ) )
V_21 -> V_26 [ V_27 ] . V_33 =
V_34 ;
if ( V_8 -> V_35 )
V_21 -> V_26 [ V_36 ] = * V_8 -> V_35 ;
else {
if ( V_4 -> V_37 == 0x14f15051 )
V_21 -> V_26 [ V_36 ] =
V_38 ;
else {
V_21 -> V_26 [ V_36 ] =
V_39 ;
V_21 -> V_26 [ V_36 ] . V_40 =
V_8 -> V_41 ;
}
}
V_21 -> V_26 [ V_36 ] . V_31 = V_8 -> V_13 [ 0 ] ;
if ( V_8 -> V_9 . V_42 ) {
V_21 ++ ;
V_4 -> V_23 ++ ;
V_21 -> V_25 = L_2 ;
V_21 -> V_43 = V_44 ;
V_21 -> V_26 [ V_27 ] =
V_45 ;
V_21 -> V_26 [ V_27 ] . V_31 =
V_8 -> V_9 . V_42 ;
if ( V_8 -> V_46 ) {
V_21 -> V_26 [ V_36 ] =
V_47 ;
V_21 -> V_26 [ V_36 ] . V_31 =
V_8 -> V_46 ;
}
if ( V_8 -> V_48 [ 0 ] )
V_4 -> V_48 = V_8 -> V_48 ;
}
return 0 ;
}
static int F_21 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_23 ( V_8 -> V_53 , V_52 ) ;
}
static int F_24 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_56 = F_25 ( V_50 , & V_55 -> V_57 ) ;
V_55 -> V_58 . V_59 . V_60 [ 0 ] = V_8 -> V_61 [ V_56 ] ;
return 0 ;
}
static int F_26 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_56 = F_25 ( V_50 , & V_55 -> V_57 ) ;
return F_27 ( V_4 , V_8 -> V_53 , V_55 ,
V_8 -> V_62 [ V_56 ] ,
& V_8 -> V_61 [ V_56 ] ) ;
}
static void F_28 ( struct V_3 * V_4 , T_1 V_63 ,
unsigned int V_64 )
{
if ( V_64 == V_65 )
F_29 ( 100 ) ;
F_30 ( V_4 , V_63 , 0 , V_66 ,
V_64 ) ;
if ( V_64 == V_67 )
F_29 ( 10 ) ;
F_31 ( V_4 , V_63 , V_64 , true ) ;
}
static int F_32 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_8 -> V_69 ; V_68 ++ )
F_33 ( V_4 , V_8 -> V_70 [ V_68 ] ) ;
return 0 ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_35 ( & V_8 -> V_71 ) ;
F_36 ( V_4 ) ;
F_37 ( V_8 ) ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_68 ;
int V_72 ;
for ( V_68 = 0 ; V_68 < V_8 -> V_73 ; V_68 ++ ) {
V_72 = F_39 ( V_4 , V_8 -> V_74 [ V_68 ] ) ;
if ( V_72 < 0 )
return V_72 ;
}
if ( V_8 -> V_9 . V_42 ) {
V_72 = F_40 ( V_4 ,
V_8 -> V_9 . V_42 ,
V_8 -> V_9 . V_42 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 = F_41 ( V_4 ,
& V_8 -> V_9 ) ;
if ( V_72 < 0 )
return V_72 ;
V_8 -> V_9 . V_75 = 1 ;
}
if ( V_8 -> V_46 ) {
V_72 = F_42 ( V_4 , V_8 -> V_46 ) ;
if ( V_72 < 0 )
return V_72 ;
}
if ( V_8 -> V_76 &&
! F_43 ( V_4 , L_3 ) ) {
unsigned int V_77 [ 4 ] ;
F_44 ( V_4 , V_8 -> V_76 ,
V_78 , V_77 ) ;
V_72 = F_45 ( V_4 , L_3 ,
V_77 , V_79 ,
L_4 ) ;
if ( V_72 < 0 )
return V_72 ;
}
if ( V_8 -> V_76 &&
! F_43 ( V_4 , L_5 ) ) {
V_72 = F_46 ( V_4 , L_5 ,
NULL , V_79 ,
L_6 , true ,
& V_8 -> V_80 . V_81 ) ;
if ( V_72 < 0 )
return V_72 ;
}
if ( V_8 -> V_53 ) {
V_72 = F_39 ( V_4 , V_82 ) ;
if ( V_72 < 0 )
return V_72 ;
}
#ifdef F_47
if ( V_8 -> V_83 ) {
const struct V_84 * V_85 ;
for ( V_85 = V_86 ; V_85 -> V_25 ; V_85 ++ ) {
struct V_49 * V_87 ;
V_87 = F_48 ( V_85 , V_4 ) ;
if ( ! V_87 )
return - V_88 ;
V_87 -> V_89 = V_8 -> V_83 ;
V_72 = F_49 ( V_4 , 0 , V_87 ) ;
if ( V_72 < 0 )
return V_72 ;
}
}
#endif
return 0 ;
}
static int F_50 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_90 = ( V_50 -> V_89 >> 8 ) & 1 ;
if ( V_90 )
V_55 -> V_58 . integer . V_58 [ 0 ] = ! V_8 -> V_91 ;
else
V_55 -> V_58 . integer . V_58 [ 0 ] = V_8 -> V_91 ;
return 0 ;
}
static int F_51 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_90 = ( V_50 -> V_89 >> 8 ) & 1 ;
T_1 V_31 = V_50 -> V_89 & 0xff ;
unsigned int V_92 ;
V_92 = ! ! V_55 -> V_58 . integer . V_58 [ 0 ] ;
if ( V_90 )
V_92 = ! V_92 ;
if ( V_92 == V_8 -> V_91 )
return 0 ;
V_8 -> V_91 = V_92 ;
F_52 ( V_4 , V_31 ,
0 , V_93 ,
V_92 ? 0x02 : 0x00 ) ;
return 1 ;
}
static int F_53 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_54 ( V_4 , V_52 , V_8 -> V_94 ,
V_8 -> V_95 ) ;
}
static int F_55 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_56 ( V_4 , V_55 , V_8 -> V_94 ,
V_8 -> V_95 ,
V_8 -> V_9 . V_30 ) ;
}
static int F_57 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_72 = F_58 ( V_4 , V_55 , V_8 -> V_94 ,
V_8 -> V_95 ,
& V_8 -> V_9 . V_30 ) ;
if ( V_72 >= 0 && V_8 -> V_96 )
V_8 -> V_9 . V_97 = V_8 -> V_9 . V_30 / 2 ;
return V_72 ;
}
static int F_59 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_98 ;
if ( ! F_51 ( V_50 , V_55 ) )
return 0 ;
V_98 = ( ! V_8 -> V_99 && V_8 -> V_91 ) ? 0 : V_100 ;
F_60 ( V_4 , 0x10 , V_78 , 0 ,
V_100 , V_98 ) ;
V_98 = V_8 -> V_91 ? 0 : V_100 ;
F_60 ( V_4 , 0x11 , V_78 , 0 ,
V_100 , V_98 ) ;
return 1 ;
}
static void F_61 ( struct V_3 * V_4 )
{
static const struct V_101 V_102 [] = {
{ 0x14 , V_103 , 0xb080 } ,
{ 0x12 , V_103 , 0xb000 } ,
{}
} ;
static const struct V_101 V_104 [] = {
{ 0x12 , V_103 , 0xb080 } ,
{ 0x14 , V_103 , 0xb000 } ,
{}
} ;
unsigned int V_105 ;
V_105 = F_62 ( V_4 , 0x12 ) ;
if ( V_105 )
F_33 ( V_4 , V_102 ) ;
else
F_33 ( V_4 , V_104 ) ;
}
static void F_63 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_98 ;
V_8 -> V_99 = F_62 ( V_4 , 0x11 ) ;
V_98 = ( V_8 -> V_99 || ! V_8 -> V_91 ) ? V_100 : 0 ;
F_60 ( V_4 , 0x10 , V_78 , 0 ,
V_100 , V_98 ) ;
}
static void F_64 ( struct V_3 * V_4 ,
unsigned int V_106 )
{
V_106 >>= 26 ;
switch ( V_106 ) {
case V_107 :
F_63 ( V_4 ) ;
break;
case V_108 :
F_61 ( V_4 ) ;
break;
}
}
static int F_65 ( struct V_3 * V_4 )
{
F_32 ( V_4 ) ;
F_63 ( V_4 ) ;
return 0 ;
}
static int F_66 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_109 ;
V_109 = F_67 ( V_4 , V_110 ,
V_111 ,
V_112 ) ;
if ( V_109 < 0 )
V_109 = V_113 ;
if ( V_109 == V_113 )
return F_68 ( V_4 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_114 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_115 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_97 = F_70 ( V_116 ) ;
V_8 -> V_9 . V_32 = V_116 ;
V_8 -> V_9 . V_42 = V_117 ;
V_8 -> V_41 = 1 ;
V_8 -> V_13 = V_118 ;
V_8 -> V_62 = V_119 ;
V_8 -> V_53 = & V_120 ;
V_8 -> V_73 = 1 ;
V_8 -> V_74 [ 0 ] = V_121 ;
V_8 -> V_69 = 1 ;
V_8 -> V_70 [ 0 ] = V_122 ;
V_8 -> V_123 = 0 ;
V_8 -> V_95 = F_70 ( V_124 ) ;
V_8 -> V_94 = V_124 ;
F_71 ( V_8 , 0x16 , 0 , 1 ) ;
V_4 -> V_125 = V_126 ;
switch ( V_109 ) {
case V_127 :
V_4 -> V_125 . V_128 = F_64 ;
V_8 -> V_53 = & V_120 ;
V_8 -> V_69 = 2 ;
V_8 -> V_70 [ 1 ] = V_129 ;
V_8 -> V_74 [ 0 ] = V_121 ;
V_4 -> V_125 . V_130 = F_65 ;
break;
case V_131 :
V_4 -> V_125 . V_128 = F_64 ;
V_8 -> V_53 = & V_120 ;
V_8 -> V_69 = 2 ;
V_8 -> V_70 [ 1 ] = V_132 ;
V_8 -> V_74 [ 0 ] = V_121 ;
V_4 -> V_125 . V_130 = F_65 ;
break;
default:
case V_133 :
V_4 -> V_125 . V_128 = F_64 ;
V_8 -> V_53 = & V_120 ;
V_8 -> V_69 = 3 ;
V_8 -> V_70 [ 1 ] = V_129 ;
V_8 -> V_70 [ 2 ] = V_132 ;
V_8 -> V_74 [ 0 ] = V_121 ;
V_4 -> V_125 . V_130 = F_65 ;
break;
case V_134 :
V_4 -> V_125 . V_128 = F_64 ;
V_8 -> V_53 = & V_135 ;
V_8 -> V_69 = 1 ;
V_8 -> V_70 [ 0 ] = V_136 ;
V_8 -> V_74 [ 0 ] = V_121 ;
V_8 -> V_74 [ 1 ] = V_137 ;
V_8 -> V_73 = 2 ;
V_4 -> V_125 . V_130 = F_65 ;
break;
case V_138 :
V_4 -> V_125 . V_128 = F_64 ;
V_8 -> V_53 = & V_139 ;
V_8 -> V_69 = 2 ;
V_8 -> V_70 [ 1 ] = V_129 ;
V_8 -> V_74 [ 0 ] = V_140 ;
V_4 -> V_125 . V_130 = F_65 ;
break;
#ifdef F_72
case V_141 :
V_8 -> V_53 = & V_142 ;
V_8 -> V_74 [ 0 ] = V_143 ;
V_8 -> V_70 [ 0 ] = V_144 ;
break;
#endif
}
switch ( V_4 -> V_145 >> 16 ) {
case 0x103c :
case 0x1631 :
case 0x1734 :
case 0x17aa :
F_73 ( V_4 , 0x17 , V_146 ,
( 0x14 << V_147 ) |
( 0x14 << V_148 ) |
( 0x05 << V_149 ) |
( 1 << V_150 ) ) ;
break;
}
if ( V_8 -> V_83 )
F_74 ( V_4 , V_8 -> V_83 ) ;
return 0 ;
}
static int F_75 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_98 ;
if ( ! F_51 ( V_50 , V_55 ) )
return 0 ;
V_98 = ( ! V_8 -> V_99 && V_8 -> V_91 ) ? 0 : V_100 ;
F_60 ( V_4 , 0x1d , V_78 , 0x01 ,
V_100 , V_98 ) ;
V_98 = V_8 -> V_91 ? 0 : V_100 ;
F_60 ( V_4 , 0x13 , V_78 , 0 ,
V_100 , V_98 ) ;
return 1 ;
}
static void F_76 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_98 ;
V_8 -> V_99 = F_62 ( V_4 , 0x13 ) ;
V_98 = ( V_8 -> V_99 || ! V_8 -> V_91 ) ? V_100 : 0 ;
F_60 ( V_4 , 0x1d , V_78 , 0x01 ,
V_100 , V_98 ) ;
}
static void F_77 ( struct V_3 * V_4 )
{
static const struct V_101 V_102 [] = {
{ 0x15 , V_103 , V_151 } ,
{ 0x17 , V_103 , V_152 } ,
{}
} ;
static const struct V_101 V_104 [] = {
{ 0x17 , V_103 , V_151 } ,
{ 0x15 , V_103 , V_152 } ,
{}
} ;
unsigned int V_105 ;
V_105 = F_62 ( V_4 , 0x15 ) ;
if ( V_105 )
F_33 ( V_4 , V_102 ) ;
else
F_33 ( V_4 , V_104 ) ;
}
static void F_78 ( struct V_3 * V_4 ,
unsigned int V_106 )
{
switch ( V_106 >> 26 ) {
case V_107 :
F_76 ( V_4 ) ;
break;
case V_108 :
F_77 ( V_4 ) ;
break;
}
}
static int F_79 ( struct V_3 * V_4 )
{
F_32 ( V_4 ) ;
F_76 ( V_4 ) ;
return 0 ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_109 ;
V_109 = F_67 ( V_4 , V_153 ,
V_154 ,
V_155 ) ;
if ( V_109 < 0 )
V_109 = V_156 ;
if ( V_109 == V_156 )
return F_68 ( V_4 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_114 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_157 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_97 = F_70 ( V_158 ) ;
V_8 -> V_9 . V_32 = V_158 ;
V_8 -> V_9 . V_42 = V_159 ;
V_8 -> V_41 = 1 ;
V_8 -> V_13 = V_160 ;
V_8 -> V_62 = V_161 ;
V_8 -> V_73 = 1 ;
V_8 -> V_74 [ 0 ] = V_162 ;
V_8 -> V_69 = 1 ;
V_8 -> V_70 [ 0 ] = V_163 ;
V_8 -> V_123 = 0 ;
V_8 -> V_95 = F_70 ( V_164 ) ,
V_8 -> V_94 = V_164 ,
V_4 -> V_125 = V_126 ;
switch ( V_109 ) {
case V_165 :
V_8 -> V_73 = 2 ;
V_8 -> V_74 [ 1 ] = V_166 ;
V_4 -> V_125 . V_128 = F_78 ;
break;
case V_167 :
V_8 -> V_73 = 2 ;
V_8 -> V_74 [ 1 ] = V_168 ;
V_4 -> V_125 . V_128 = F_78 ;
V_4 -> V_125 . V_130 = F_79 ;
break;
case V_169 :
V_8 -> V_53 = & V_170 ;
V_8 -> V_73 = 2 ;
V_8 -> V_74 [ 1 ] = V_166 ;
V_8 -> V_69 = 2 ;
V_8 -> V_70 [ 1 ] = V_171 ;
V_4 -> V_125 . V_128 = F_78 ;
break;
#ifdef F_72
case V_172 :
V_8 -> V_53 = & V_173 ;
V_8 -> V_74 [ 0 ] = V_174 ;
V_8 -> V_70 [ 0 ] = V_175 ;
V_4 -> V_125 . V_128 = F_78 ;
#endif
}
V_8 -> V_76 = 0x13 ;
switch ( V_4 -> V_145 >> 16 ) {
case 0x103c :
F_73 ( V_4 , 0x10 , V_146 ,
( 0x17 << V_147 ) |
( 0x17 << V_148 ) |
( 0x05 << V_149 ) |
( 1 << V_150 ) ) ;
break;
}
return 0 ;
}
static void F_81 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_176 ;
V_176 = ( V_8 -> V_99 && V_8 -> V_91 ) ? V_177 : 0 ;
F_82 ( V_4 , 0x16 , V_176 ) ;
V_176 = ( ! V_8 -> V_99 && V_8 -> V_91 ) ? V_178 : 0 ;
F_82 ( V_4 , 0x1a , V_176 ) ;
if ( V_8 -> V_179 )
F_82 ( V_4 , 0x1b , V_176 ) ;
}
static int F_83 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
if ( ! F_51 ( V_50 , V_55 ) )
return 0 ;
F_81 ( V_4 ) ;
return 1 ;
}
static void F_84 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_105 ;
if ( ! ( V_8 -> V_180 & V_181 ) )
return;
V_105 = F_62 ( V_4 , 0x17 ) ;
F_85 ( V_4 , 0x14 , 0 ,
V_182 ,
V_105 ? 0x01 : 0x00 ) ;
}
static void F_86 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_105 ;
T_1 V_183 ;
if ( ! ( V_8 -> V_180 & V_184 ) )
return;
V_105 = F_62 ( V_4 , 0x18 ) ;
if ( V_105 )
V_8 -> V_17 = 1 ;
else
V_8 -> V_17 = 0 ;
V_183 = V_8 -> V_13 [ V_8 -> V_17 ] ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_183 ) {
F_87 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_183 ;
F_14 ( V_4 , V_183 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
}
static void F_88 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_99 = F_62 ( V_4 , 0x16 ) ;
F_81 ( V_4 ) ;
}
static void F_89 ( struct V_3 * V_4 ,
unsigned int V_106 )
{
switch ( V_106 >> 26 ) {
case V_107 :
F_88 ( V_4 ) ;
break;
case V_185 :
F_84 ( V_4 ) ;
break;
case V_186 :
F_86 ( V_4 ) ;
break;
}
}
static void F_90 ( struct V_3 * V_4 , T_1 V_31 ,
unsigned int V_187 )
{
F_85 ( V_4 , V_31 , 0 ,
V_188 ,
V_189 | V_187 ) ;
}
static int F_91 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_32 ( V_4 ) ;
if ( V_8 -> V_180 & V_181 )
F_90 ( V_4 , 0x17 , V_185 ) ;
if ( V_8 -> V_180 & V_184 )
F_90 ( V_4 , 0x18 , V_186 ) ;
if ( V_4 -> V_125 . V_128 ) {
F_88 ( V_4 ) ;
F_84 ( V_4 ) ;
F_86 ( V_4 ) ;
}
return 0 ;
}
static int F_92 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_109 ;
V_109 = F_67 ( V_4 , V_190 ,
V_191 ,
V_192 ) ;
if ( V_109 < 0 )
V_109 = V_193 ;
if ( V_109 == V_193 )
return F_68 ( V_4 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_114 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_157 = 1 ;
V_4 -> V_125 = V_126 ;
V_4 -> V_125 . V_130 = F_91 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_97 = F_70 ( V_194 ) ;
V_8 -> V_9 . V_32 = V_194 ;
V_8 -> V_9 . V_42 = V_195 ;
V_8 -> V_41 = 1 ;
V_8 -> V_13 = V_196 ;
V_8 -> V_73 = 2 ;
V_8 -> V_74 [ 0 ] = V_197 ;
V_8 -> V_74 [ 1 ] = V_198 ;
V_8 -> V_69 = 1 ;
V_8 -> V_70 [ 0 ] = V_199 ;
V_8 -> V_123 = 0 ;
V_8 -> V_95 = F_70 ( V_200 ) ;
V_8 -> V_94 = V_200 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_71 ( V_8 , 0x13 , 0 , V_78 ) ;
V_4 -> V_125 . V_128 = F_89 ;
V_8 -> V_180 = V_181 | V_184 ;
switch ( V_109 ) {
case V_201 :
V_8 -> V_74 [ 0 ] = V_202 ;
break;
case V_203 :
V_8 -> V_70 [ 0 ] = V_204 ;
V_8 -> V_74 [ 0 ] = V_205 ;
V_8 -> V_180 = 0 ;
break;
case V_206 :
V_8 -> V_70 [ 0 ] = V_207 ;
V_8 -> V_74 [ 0 ] = V_208 ;
V_8 -> V_180 = 0 ;
break;
case V_209 :
V_8 -> V_74 [ 0 ] = V_210 ;
V_8 -> V_180 = V_181 ;
break;
case V_211 :
V_8 -> V_70 [ V_8 -> V_69 ++ ] =
V_212 ;
V_8 -> V_179 = 1 ;
break;
}
if ( V_8 -> V_83 )
F_74 ( V_4 , V_8 -> V_83 ) ;
return 0 ;
}
static void F_93 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_176 ;
F_94 ( L_7 ,
V_8 -> V_99 , V_8 -> V_91 ) ;
V_176 = ( F_95 ( V_8 ) && V_8 -> V_91 ) ? V_177 : 0 ;
F_82 ( V_4 , 0x19 , V_176 ) ;
V_176 = V_8 -> V_91 ? V_8 -> V_213 : 0 ;
if ( V_8 -> V_214 || V_8 -> V_215 ) {
if ( F_95 ( V_8 ) )
V_176 = 0 ;
} else {
if ( ! F_96 ( V_8 ) )
V_176 = 0 ;
}
F_82 ( V_4 , 0x1c , V_176 ) ;
V_176 = ( ! V_8 -> V_99 && V_8 -> V_91 ) ? V_178 : 0 ;
F_82 ( V_4 , 0x1f , V_176 ) ;
}
static int F_97 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
if ( ! F_51 ( V_50 , V_55 ) )
return 0 ;
F_93 ( V_4 ) ;
return 1 ;
}
static int F_98 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_99 ( V_4 , 0x1a ,
V_216 . V_217 [ V_8 -> V_218 ] . V_219 ) ;
}
static void F_100 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_220 )
return;
if ( V_8 -> V_221 ) {
const struct V_101 V_222 [] = {
{ 0x1b , V_223 , 0 } ,
{ 0x1e , V_223 , V_224 } ,
{} ,
} ;
F_33 ( V_4 , V_222 ) ;
F_98 ( V_4 ) ;
return;
}
F_82 ( V_4 , 0x1e , 0 ) ;
F_82 ( V_4 , 0x1a ,
V_8 -> V_225 ? V_226 : 0 ) ;
F_82 ( V_4 , 0x1b ,
V_8 -> V_225 ? 0 : V_227 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_105 ;
if ( V_8 -> V_221 )
return;
V_105 = F_30 ( V_4 , 0x1a , 0 ,
V_228 , 0 ) & 0x80000000 ;
if ( V_105 )
F_94 ( L_8 ) ;
else
F_94 ( L_9 ) ;
F_85 ( V_4 , 0x17 , 0 , V_182 ,
V_105 ? 0 : 1 ) ;
V_8 -> V_225 = ! ! V_105 ;
F_100 ( V_4 ) ;
}
static void F_102 ( struct V_3 * V_4 )
{
unsigned int V_105 ;
struct V_101 V_225 [] = {
{ 0x1a , V_223 , V_227 } ,
{ 0x17 , V_182 , 0 } ,
{ 0x14 , V_182 , 0 } ,
{ 0x23 , V_223 , 0 } ,
{}
} ;
static const struct V_101 V_229 [] = {
{ 0x23 , V_223 , V_224 } ,
{ 0x14 , V_182 , 2 } ,
{ 0x1a , V_223 , 0 } ,
{}
} ;
V_105 = F_62 ( V_4 , 0x1a ) ;
if ( V_105 ) {
F_94 ( L_8 ) ;
F_33 ( V_4 , V_225 ) ;
} else {
F_94 ( L_9 ) ;
F_33 ( V_4 , V_229 ) ;
}
}
static void F_103 ( struct V_3 * V_4 )
{
unsigned int V_105 ;
struct V_101 V_225 [] = {
{ 0x14 , V_182 , 0 } ,
{ 0x1b , V_223 , V_227 } ,
{ 0x23 , V_223 , 0 } ,
{}
} ;
static const struct V_101 V_229 [] = {
{ 0x14 , V_182 , 2 } ,
{ 0x23 , V_223 , V_224 } ,
{ 0x1b , V_223 , 0 } ,
{}
} ;
V_105 = F_62 ( V_4 , 0x1b ) ;
if ( V_105 ) {
F_94 ( L_8 ) ;
F_33 ( V_4 , V_225 ) ;
} else {
F_94 ( L_9 ) ;
F_33 ( V_4 , V_229 ) ;
}
}
static void F_104 ( struct V_3 * V_4 )
{
unsigned int V_105 ;
V_105 = F_62 ( V_4 , 0x1b ) ;
F_94 ( L_10 , V_105 ) ;
F_85 ( V_4 , 0x17 , 0 , V_182 ,
V_105 ? 1 : 0 ) ;
}
static void F_105 ( struct V_3 * V_4 )
{
unsigned int V_105 ;
V_105 = F_62 ( V_4 , 0x1b ) ;
F_94 ( L_10 , V_105 ) ;
F_85 ( V_4 , 0x17 , 0 , V_182 ,
V_105 ? 1 : 3 ) ;
}
static void F_106 ( struct V_3 * V_4 )
{
unsigned int V_230 , V_231 ;
static const struct V_101 V_225 [] = {
{ 0x14 , V_182 , 0 } ,
{ 0x17 , V_182 , 1 } ,
{ 0x1b , V_223 , V_227 } ,
{ 0x23 , V_223 , 0 } ,
{ 0x1a , V_223 , 0 } ,
{}
} ;
static const struct V_101 V_232 [] = {
{ 0x14 , V_182 , 0 } ,
{ 0x17 , V_182 , 0 } ,
{ 0x1a , V_223 , V_227 } ,
{ 0x23 , V_223 , 0 } ,
{ 0x1b , V_223 , 0 } ,
{}
} ;
static const struct V_101 V_229 [] = {
{ 0x14 , V_182 , 2 } ,
{ 0x23 , V_223 , V_224 } ,
{ 0x1b , V_223 , 0 } ,
{ 0x1a , V_223 , 0 } ,
{}
} ;
V_230 = F_62 ( V_4 , 0x1b ) ;
V_231 = F_62 ( V_4 , 0x1a ) ;
if ( V_230 ) {
F_94 ( L_8 ) ;
F_33 ( V_4 , V_225 ) ;
} else if ( V_231 ) {
F_94 ( L_11 ) ;
F_33 ( V_4 , V_232 ) ;
} else {
F_94 ( L_9 ) ;
F_33 ( V_4 , V_229 ) ;
}
}
static void F_107 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_233 , V_234 ;
V_233 = F_62 ( V_4 , 0x19 ) ;
V_234 = F_62 ( V_4 , 0x1c ) ;
V_8 -> V_99 = V_233 ? V_235 : 0 ;
V_8 -> V_99 |= V_234 ? V_236 : 0 ;
F_94 ( L_12 ,
V_233 , V_234 , V_8 -> V_99 ) ;
F_93 ( V_4 ) ;
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 -> V_237 )
F_102 ( V_4 ) ;
else if ( V_8 -> V_179 )
F_103 ( V_4 ) ;
else if ( V_8 -> V_215 )
F_106 ( V_4 ) ;
else if ( V_8 -> V_238 )
F_105 ( V_4 ) ;
else if ( V_8 -> V_239 )
F_104 ( V_4 ) ;
}
static void F_109 ( struct V_3 * V_4 , unsigned int V_106 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_94 ( L_13 , V_106 , V_106 >> 26 ) ;
switch ( V_106 >> 26 ) {
case V_107 :
F_107 ( V_4 ) ;
break;
case V_108 :
if ( ! V_8 -> V_221 )
F_101 ( V_4 ) ;
break;
}
}
static void F_110 ( struct V_3 * V_4 , unsigned int V_106 )
{
F_94 ( L_13 , V_106 , V_106 >> 26 ) ;
switch ( V_106 >> 26 ) {
case V_107 :
F_107 ( V_4 ) ;
break;
case V_108 :
F_108 ( V_4 ) ;
break;
}
}
static void F_111 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_52 ( V_4 , 0x17 , 0 ,
V_103 ,
V_240 | V_241 | V_242 |
V_243 . V_217 [ V_8 -> V_244 ] . V_219 ) ;
if ( V_8 -> V_179 || V_8 -> V_215 ) {
F_52 ( V_4 , 0x23 , 0 ,
V_103 ,
V_240 | V_241 | V_245 |
V_243 .
V_217 [ V_8 -> V_244 ] . V_219 ) ;
}
}
static int F_112 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
return F_23 ( & V_243 , V_52 ) ;
}
static int F_113 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_55 -> V_58 . V_59 . V_60 [ 0 ] = V_8 -> V_244 ;
return 0 ;
}
static int F_114 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_246 * V_247 = & V_243 ;
unsigned int V_248 ;
V_248 = V_55 -> V_58 . V_59 . V_60 [ 0 ] ;
if ( V_248 >= V_247 -> V_249 )
V_248 = V_247 -> V_249 - 1 ;
V_8 -> V_244 = V_248 ;
if ( ! V_8 -> V_221 )
F_111 ( V_4 ) ;
return 1 ;
}
static void F_115 ( struct V_3 * V_4 )
{
const struct V_101 V_222 [] = {
{ 0x17 , V_103 , V_152 } ,
{ 0x17 , V_182 , 3 } ,
{}
} ;
F_33 ( V_4 , V_222 ) ;
F_100 ( V_4 ) ;
}
static void F_116 ( struct V_3 * V_4 )
{
F_111 ( V_4 ) ;
F_101 ( V_4 ) ;
}
static int F_117 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_55 -> V_58 . integer . V_58 [ 0 ] = V_8 -> V_221 ;
return 0 ;
}
static int F_118 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_221 = ! ! V_55 -> V_58 . integer . V_58 [ 0 ] ;
if ( V_221 == V_8 -> V_221 )
return 0 ;
V_8 -> V_221 = V_221 ;
if ( V_221 )
F_115 ( V_4 ) ;
else
F_116 ( V_4 ) ;
return 1 ;
}
static int F_119 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
return F_23 ( & V_216 , V_52 ) ;
}
static int F_120 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_55 -> V_58 . V_59 . V_60 [ 0 ] = V_8 -> V_218 ;
return 0 ;
}
static int F_121 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_246 * V_247 = & V_243 ;
unsigned int V_248 ;
V_248 = V_55 -> V_58 . V_59 . V_60 [ 0 ] ;
if ( V_248 >= V_247 -> V_249 )
V_248 = V_247 -> V_249 - 1 ;
V_8 -> V_218 = V_248 ;
if ( V_8 -> V_221 )
F_98 ( V_4 ) ;
return 1 ;
}
static void F_122 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_220 = 1 ;
F_100 ( V_4 ) ;
}
static void F_123 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_101 V_250 [] = {
{ 0x1a , V_223 , 0 } ,
{ 0x1b , V_223 , 0 } ,
{ 0x1e , V_223 , 0 } ,
{} ,
} ;
F_33 ( V_4 , V_250 ) ;
V_8 -> V_220 = 0 ;
}
static void F_124 ( struct V_3 * V_4 ,
const T_1 * V_251 ,
int V_252 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 * V_253 = & V_8 -> V_9 . V_42 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_252 ; V_68 ++ , V_251 ++ ) {
unsigned int V_254 = F_125 ( V_4 , * V_251 ) ;
if ( F_126 ( V_254 ) == V_255 )
continue;
if ( F_127 ( V_4 , * V_251 , V_253 , 1 ) != 1 )
continue;
if ( V_8 -> V_48 [ 0 ] )
V_253 ++ ;
else
V_253 = V_8 -> V_48 ;
}
}
static int F_128 ( struct V_3 * V_4 )
{
F_94 ( L_14 ) ;
F_32 ( V_4 ) ;
if ( V_4 -> V_125 . V_128 ) {
F_107 ( V_4 ) ;
F_108 ( V_4 ) ;
}
F_111 ( V_4 ) ;
return 0 ;
}
static int F_129 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_94 ( L_14 ) ;
F_32 ( V_4 ) ;
F_107 ( V_4 ) ;
if ( ! V_8 -> V_221 ) {
F_111 ( V_4 ) ;
F_101 ( V_4 ) ;
} else {
F_115 ( V_4 ) ;
}
return 0 ;
}
static int F_130 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_109 ;
V_109 = F_67 ( V_4 , V_256 ,
V_257 , V_258 ) ;
if ( V_109 < 0 )
V_109 = V_259 ;
if ( V_109 == V_259 )
return F_68 ( V_4 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_114 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_125 = V_126 ;
V_4 -> V_125 . V_130 = F_32 ;
V_8 -> V_214 = 0 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_97 = F_70 ( V_260 ) ;
V_8 -> V_9 . V_32 = V_260 ;
F_124 ( V_4 , V_261 ,
F_70 ( V_261 ) ) ;
V_8 -> V_41 = 1 ;
V_8 -> V_13 = V_262 ;
V_8 -> V_62 = V_263 ;
V_8 -> V_53 = & V_264 ;
V_8 -> V_213 = V_177 ;
V_8 -> V_69 = 1 ;
V_8 -> V_70 [ 0 ] = V_265 ;
V_8 -> V_95 = F_70 ( V_266 ) ;
V_8 -> V_94 = V_266 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_71 ( V_8 , 0x13 , 0 , V_78 ) ;
switch ( V_109 ) {
default:
case V_267 :
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_268 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_269 ;
break;
case V_270 :
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_268 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_269 ;
V_8 -> V_213 = V_178 ;
V_8 -> V_70 [ V_8 -> V_69 ] = V_271 ;
V_8 -> V_69 ++ ;
V_8 -> V_214 = 1 ;
break;
case V_272 :
case V_273 :
V_4 -> V_125 . V_130 = F_128 ;
V_4 -> V_125 . V_128 = F_110 ;
V_8 -> V_70 [ V_8 -> V_69 ] =
V_274 ;
V_8 -> V_69 ++ ;
V_8 -> V_238 = V_109 == V_273 ;
V_8 -> V_239 = V_109 == V_272 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_268 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_269 ;
if ( V_109 == V_273 )
V_8 -> V_9 . V_42 = 0 ;
V_8 -> V_53 = NULL ;
V_8 -> V_213 = 0 ;
V_8 -> V_244 = 3 ;
break;
case V_275 :
V_4 -> V_125 . V_130 = F_129 ;
V_4 -> V_125 . V_128 = F_109 ;
V_8 -> V_70 [ 0 ] = V_276 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_277 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_278 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_269 ;
V_8 -> V_213 = 0 ;
V_8 -> V_244 = 3 ;
V_8 -> V_9 . V_42 = 0 ;
V_8 -> V_53 = NULL ;
V_8 -> V_12 = F_122 ;
V_8 -> V_15 = F_123 ;
break;
case V_279 :
V_4 -> V_125 . V_130 = F_128 ;
V_4 -> V_125 . V_128 = F_110 ;
V_8 -> V_70 [ 0 ] = V_280 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_277 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_269 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_281 ;
V_8 -> V_213 = 0 ;
V_8 -> V_237 = 1 ;
V_8 -> V_244 = 3 ;
V_8 -> V_9 . V_42 = 0 ;
V_8 -> V_53 = NULL ;
break;
case V_282 :
V_4 -> V_125 . V_130 = F_128 ;
V_4 -> V_125 . V_128 = F_110 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_268 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_269 ;
V_8 -> V_70 [ 0 ] = V_283 ;
V_8 -> V_213 = 0 ;
V_8 -> V_179 = 1 ;
V_8 -> V_244 = 2 ;
V_8 -> V_9 . V_42 = 0 ;
V_8 -> V_53 = NULL ;
break;
case V_284 :
V_4 -> V_125 . V_130 = F_128 ;
V_4 -> V_125 . V_128 = F_110 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_268 ;
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_269 ;
V_8 -> V_70 [ 0 ] = V_285 ;
V_8 -> V_215 = 1 ;
V_8 -> V_213 = V_178 ;
V_8 -> V_244 = 2 ;
V_8 -> V_9 . V_42 = 0 ;
V_8 -> V_53 = NULL ;
break;
}
if ( V_8 -> V_83 )
F_74 ( V_4 , V_8 -> V_83 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_286 = V_8 -> V_287 [ V_8 -> V_61 [ 0 ] ] . V_286 ;
if ( V_8 -> V_288 ) {
V_8 -> V_16 = V_286 ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_11 ;
}
F_14 ( V_4 , V_286 , V_10 , 0 , V_11 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_16 ( V_4 , V_8 -> V_16 ) ;
V_8 -> V_16 = 0 ;
return 0 ;
}
static T_1 F_133 ( struct V_3 * V_4 , T_1 V_289 ,
T_1 * V_290 , int * V_97 )
{
int V_68 , V_291 = * V_97 ;
T_1 V_292 = 0 ;
for ( V_68 = 0 ; V_68 < V_291 ; V_68 ++ ) {
if ( F_134 ( V_4 , V_289 , V_290 [ V_68 ] ) >= 0 ) {
V_292 = V_290 [ V_68 ] ;
break;
}
}
if ( ! V_292 )
return 0 ;
if ( -- V_291 > 0 )
memmove ( V_290 , V_290 + 1 , V_291 * sizeof( T_1 ) ) ;
* V_97 = V_291 ;
return V_292 ;
}
static int F_135 ( struct V_3 * V_4 , T_1 * V_290 )
{
T_1 V_31 , V_293 ;
int V_291 = 0 ;
V_293 = V_4 -> V_294 + V_4 -> V_295 ;
for ( V_31 = V_4 -> V_294 ; V_31 < V_293 ; V_31 ++ ) {
unsigned int V_296 = F_136 ( V_4 , V_31 ) ;
unsigned int type = F_137 ( V_296 ) ;
if ( type == V_297 && ! ( V_296 & V_298 ) ) {
V_290 [ V_291 ++ ] = V_31 ;
if ( V_291 >= V_299 )
break;
}
}
return V_291 ;
}
static int F_138 ( struct V_3 * V_4 , T_1 * V_300 ,
int V_252 , T_1 * V_290 , int * V_301 ,
struct V_302 * V_303 , int V_291 ,
int type )
{
int V_68 , V_304 = V_291 ;
for ( V_68 = 0 ; V_68 < V_252 ; V_68 ++ , V_291 ++ ) {
V_303 [ V_291 ] . V_289 = V_300 [ V_68 ] ;
V_303 [ V_291 ] . type = type ;
V_303 [ V_291 ] . V_305 = F_133 ( V_4 , V_300 [ V_68 ] , V_290 , V_301 ) ;
if ( V_303 [ V_291 ] . V_305 )
continue;
if ( V_303 [ V_304 ] . V_305 && F_134 ( V_4 , V_300 [ V_68 ] , V_303 [ V_304 ] . V_305 ) >= 0 ) {
V_303 [ V_291 ] . V_305 = V_303 [ V_304 ] . V_305 | V_306 ;
continue;
}
if ( V_303 [ 0 ] . V_305 && F_134 ( V_4 , V_300 [ V_68 ] , V_303 [ 0 ] . V_305 ) >= 0 ) {
V_303 [ V_291 ] . V_305 = V_303 [ 0 ] . V_305 | V_306 ;
continue;
}
F_94 ( L_15 , V_300 [ V_68 ] ) ;
}
return V_291 ;
}
static void F_139 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
T_1 V_290 [ V_299 ] ;
int V_68 , V_309 , V_291 , V_301 ;
V_301 = F_135 ( V_4 , V_290 ) ;
V_291 = F_138 ( V_4 , V_254 -> V_310 , V_254 -> V_311 ,
V_290 , & V_301 , V_8 -> V_312 , 0 ,
V_313 ) ;
V_291 = F_138 ( V_4 , V_254 -> V_314 , V_254 -> V_315 ,
V_290 , & V_301 , V_8 -> V_312 , V_291 ,
V_316 ) ;
V_291 = F_138 ( V_4 , V_254 -> V_317 , V_254 -> V_318 ,
V_290 , & V_301 , V_8 -> V_312 , V_291 ,
V_319 ) ;
V_8 -> V_320 = V_291 ;
for ( V_68 = 0 ; V_68 < V_291 ; V_68 ++ ) {
T_1 V_305 = V_8 -> V_312 [ V_68 ] . V_305 ;
if ( ! V_305 || ( V_305 & V_306 ) )
continue;
switch ( V_8 -> V_312 [ V_68 ] . type ) {
case V_313 :
V_8 -> V_321 [ V_8 -> V_9 . V_97 ] = V_305 ;
V_8 -> V_9 . V_97 ++ ;
break;
case V_316 :
case V_319 :
if ( ! V_8 -> V_9 . V_322 ) {
V_8 -> V_9 . V_322 = V_305 ;
break;
}
for ( V_309 = 0 ; V_309 < F_70 ( V_8 -> V_9 . V_323 ) ; V_309 ++ )
if ( ! V_8 -> V_9 . V_323 [ V_309 ] ) {
V_8 -> V_9 . V_323 [ V_309 ] = V_305 ;
break;
}
break;
}
}
V_8 -> V_9 . V_32 = V_8 -> V_321 ;
V_8 -> V_9 . V_30 = V_8 -> V_9 . V_97 * 2 ;
for ( V_68 = 0 ; V_68 < V_254 -> V_315 ; V_68 ++ ) {
if ( F_140 ( V_4 , V_254 -> V_314 [ V_68 ] ) ) {
V_8 -> V_324 = 1 ;
break;
}
}
if ( V_8 -> V_324 &&
V_254 -> V_310 [ 0 ] &&
V_254 -> V_325 != V_319 &&
V_254 -> V_310 [ 0 ] != V_254 -> V_314 [ 0 ] &&
V_254 -> V_310 [ 0 ] != V_254 -> V_317 [ 0 ] ) {
for ( V_68 = 0 ; V_68 < V_254 -> V_311 ; V_68 ++ ) {
if ( F_140 ( V_4 , V_254 -> V_310 [ V_68 ] ) ) {
V_8 -> V_326 = 1 ;
break;
}
}
V_8 -> V_327 = V_8 -> V_326 ;
}
V_8 -> V_76 = V_8 -> V_321 [ 0 ] ;
}
static void F_141 ( struct V_3 * V_4 , int V_252 ,
T_1 * V_300 , bool V_328 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_252 ; V_68 ++ )
F_82 ( V_4 , V_300 [ V_68 ] , V_328 ? V_178 : 0 ) ;
if ( V_8 -> V_329 )
F_142 ( V_4 , V_252 , V_300 , V_328 ) ;
}
static int F_143 ( struct V_3 * V_4 , int V_252 , T_1 * V_300 )
{
int V_68 , V_105 = 0 ;
for ( V_68 = 0 ; V_68 < V_252 ; V_68 ++ ) {
T_1 V_31 = V_300 [ V_68 ] ;
if ( ! V_31 || ! F_140 ( V_4 , V_31 ) )
break;
V_105 |= F_62 ( V_4 , V_31 ) ;
}
return V_105 ;
}
static void F_144 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
int V_328 = 1 ;
if ( V_8 -> V_329 ) {
if ( V_8 -> V_324 )
V_328 = V_8 -> V_99 ;
F_142 ( V_4 , V_254 -> V_315 , V_254 -> V_314 , V_328 ) ;
}
if ( V_8 -> V_324 )
V_328 = ! ( V_8 -> V_99 ||
( V_8 -> V_326 && V_8 -> V_330 ) ) ;
F_141 ( V_4 , V_254 -> V_318 , V_254 -> V_317 , V_328 ) ;
if ( V_254 -> V_310 [ 0 ] == V_254 -> V_314 [ 0 ] ||
V_254 -> V_310 [ 0 ] == V_254 -> V_317 [ 0 ] )
return;
if ( V_8 -> V_324 ) {
if ( V_254 -> V_325 == V_319 ||
V_8 -> V_327 )
V_328 = ! V_8 -> V_99 ;
else
V_328 = 1 ;
}
F_141 ( V_4 , V_254 -> V_311 , V_254 -> V_310 , V_328 ) ;
}
static void F_145 ( struct V_3 * V_4 , struct V_331 * V_332 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
if ( ! V_8 -> V_324 )
return;
V_8 -> V_99 = F_143 ( V_4 , V_254 -> V_315 , V_254 -> V_314 ) ;
F_144 ( V_4 ) ;
}
static void F_146 ( struct V_3 * V_4 , struct V_331 * V_332 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
if ( ! V_8 -> V_324 || ! V_8 -> V_326 )
return;
V_8 -> V_330 = F_143 ( V_4 , V_254 -> V_311 ,
V_254 -> V_310 ) ;
F_144 ( V_4 ) ;
}
static int F_147 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
static const char * const V_333 [] = {
L_16 , L_17 , L_18
} ;
if ( V_8 -> V_334 )
return F_148 ( V_50 , V_52 , 3 , V_333 ) ;
return F_149 ( V_50 , V_52 ) ;
}
static int F_150 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_335 ;
if ( ! V_8 -> V_324 )
V_335 = 0 ;
else if ( ! V_8 -> V_327 )
V_335 = 1 ;
else
V_335 = 2 ;
V_55 -> V_58 . V_59 . V_60 [ 0 ] = V_335 ;
return 0 ;
}
static int F_151 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
switch ( V_55 -> V_58 . V_59 . V_60 [ 0 ] ) {
case 0 :
if ( ! V_8 -> V_324 )
return 0 ;
V_8 -> V_324 = 0 ;
break;
case 1 :
if ( V_8 -> V_324 && ! V_8 -> V_327 )
return 0 ;
V_8 -> V_324 = 1 ;
V_8 -> V_327 = 0 ;
break;
case 2 :
if ( ! V_8 -> V_334 )
return - V_336 ;
if ( V_8 -> V_324 && V_8 -> V_327 )
return 0 ;
V_8 -> V_324 = 1 ;
V_8 -> V_327 = 1 ;
break;
default:
return - V_336 ;
}
F_144 ( V_4 ) ;
return 1 ;
}
static int F_152 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_23 ( & V_8 -> V_337 , V_52 ) ;
}
static int F_153 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_55 -> V_58 . V_59 . V_60 [ 0 ] = V_8 -> V_61 [ 0 ] ;
return 0 ;
}
static int F_154 ( struct V_3 * V_4 , T_1 V_338 ,
T_1 V_289 , T_1 * V_339 ,
bool V_340 , int V_341 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_342 [ V_343 ] ;
int V_344 , V_68 , V_291 ;
switch ( F_137 ( F_136 ( V_4 , V_338 ) ) ) {
case V_345 :
case V_346 :
case V_347 :
break;
default:
return - 1 ;
}
V_291 = F_127 ( V_4 , V_338 , V_342 , F_70 ( V_342 ) ) ;
for ( V_68 = 0 ; V_68 < V_291 ; V_68 ++ )
if ( V_342 [ V_68 ] == V_289 ) {
if ( V_340 )
F_85 ( V_4 , V_338 , 0 ,
V_182 , V_68 ) ;
if ( V_339 )
* V_339 = V_338 ;
return V_68 ;
}
V_341 ++ ;
if ( V_341 == 2 )
return - 1 ;
V_344 = 0 ;
for ( V_68 = 0 ; V_68 < V_8 -> V_337 . V_249 ; V_68 ++ )
if ( V_8 -> V_287 [ V_68 ] . V_289 == V_289 ) {
V_344 = V_68 ;
break;
}
for ( V_68 = 0 ; V_68 < V_291 ; V_68 ++ ) {
int V_309 = ( V_68 + V_344 ) % V_291 ;
int V_292 = F_154 ( V_4 , V_342 [ V_309 ] , V_289 , V_339 ,
V_340 , V_341 ) ;
if ( V_292 >= 0 ) {
if ( V_340 )
F_85 ( V_4 , V_338 , 0 ,
V_182 , V_309 ) ;
return V_309 ;
}
}
return - 1 ;
}
static void F_155 ( struct V_3 * V_4 , T_1 V_338 ,
T_1 V_289 )
{
F_154 ( V_4 , V_338 , V_289 , NULL , true , 0 ) ;
}
static int F_156 ( struct V_3 * V_4 , T_1 V_338 ,
T_1 V_289 )
{
return F_154 ( V_4 , V_338 , V_289 , NULL , false , 0 ) ;
}
static int F_157 ( struct V_3 * V_4 ,
const struct V_246 * V_247 ,
unsigned int V_248 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_286 ;
int V_348 = 1 ;
if ( ! V_247 -> V_249 )
return 0 ;
if ( V_248 >= V_247 -> V_249 )
V_248 = V_247 -> V_249 - 1 ;
if ( V_8 -> V_61 [ 0 ] == V_248 )
V_348 = 0 ;
V_286 = V_8 -> V_287 [ V_248 ] . V_286 ;
F_155 ( V_4 , V_8 -> V_287 [ V_248 ] . V_286 ,
V_8 -> V_287 [ V_248 ] . V_289 ) ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_286 ) {
F_87 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_286 ;
F_14 ( V_4 , V_286 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
V_8 -> V_61 [ 0 ] = V_248 ;
return V_348 ;
}
static int F_158 ( struct V_49 * V_50 ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_22 ( V_50 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_157 ( V_4 , & V_8 -> V_337 ,
V_55 -> V_58 . V_59 . V_60 [ 0 ] ) ;
}
static bool F_159 ( struct V_3 * V_4 , int V_248 , bool V_349 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_248 < 0 )
return false ;
if ( V_349 && ! F_62 ( V_4 , V_8 -> V_287 [ V_248 ] . V_289 ) )
return false ;
F_157 ( V_4 , & V_8 -> V_337 , V_248 ) ;
return true ;
}
static void F_160 ( struct V_3 * V_4 , struct V_331 * V_332 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_180 )
return;
if ( ! F_159 ( V_4 , V_8 -> V_350 , true ) )
if ( ! F_159 ( V_4 , V_8 -> V_351 , true ) )
F_159 ( V_4 , V_8 -> V_352 , false ) ;
}
static void F_161 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_353 [ V_354 + 1 ] ;
int V_68 ;
for ( V_68 = 0 ; V_68 < F_70 ( V_353 ) ; V_68 ++ )
V_353 [ V_68 ] = - 1 ;
for ( V_68 = 0 ; V_68 < V_8 -> V_337 . V_249 ; V_68 ++ ) {
T_1 V_289 = V_8 -> V_287 [ V_68 ] . V_289 ;
unsigned int V_355 = F_125 ( V_4 , V_289 ) ;
int type , V_356 ;
V_356 = F_162 ( V_355 ) ;
if ( V_356 == V_357 )
return;
if ( V_356 > V_354 )
V_356 = V_354 ;
if ( V_356 != V_358 &&
! F_140 ( V_4 , V_289 ) )
return;
type = F_163 ( V_355 ) ;
if ( type != V_359 &&
( V_356 != V_360 || type != V_361 ) )
return;
if ( V_353 [ V_356 ] >= 0 )
return;
V_353 [ V_356 ] = V_68 ;
}
if ( V_353 [ V_358 ] < 0 ||
( V_353 [ V_354 ] < 0 && V_353 [ V_360 ] ) )
return;
V_8 -> V_180 = 1 ;
V_8 -> V_350 = V_353 [ V_354 ] ;
V_8 -> V_351 = V_353 [ V_360 ] ;
V_8 -> V_352 = V_353 [ V_358 ] ;
}
static void F_164 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
struct V_246 * V_247 ;
int V_68 , V_309 ;
V_247 = & V_8 -> V_337 ;
for ( V_68 = 0 ; V_68 < V_254 -> V_362 ; V_68 ++ ) {
for ( V_309 = 0 ; V_309 < V_8 -> V_41 ; V_309 ++ ) {
T_1 V_286 = V_8 -> V_13 [ V_309 ] ;
int V_248 = F_156 ( V_4 , V_286 ,
V_254 -> V_363 [ V_68 ] . V_289 ) ;
if ( V_248 >= 0 ) {
const char * V_364 ;
V_364 = F_165 ( V_4 , V_254 , V_68 ) ;
V_8 -> V_287 [ V_247 -> V_249 ] . V_219 = V_68 ;
V_8 -> V_287 [ V_247 -> V_249 ] . V_365 = 0 ;
V_8 -> V_287 [ V_247 -> V_249 ] . V_286 = V_286 ;
V_8 -> V_287 [ V_247 -> V_249 ] . V_289 =
V_254 -> V_363 [ V_68 ] . V_289 ;
F_166 ( V_247 , V_364 , V_248 , NULL ) ;
break;
}
}
}
if ( V_247 -> V_249 >= 2 && V_254 -> V_362 == V_247 -> V_249 )
F_161 ( V_4 ) ;
if ( V_247 -> V_249 > 1 ) {
for ( V_68 = 1 ; V_68 < V_247 -> V_249 ; V_68 ++ ) {
if ( V_8 -> V_287 [ V_68 ] . V_286 != V_8 -> V_287 [ 0 ] . V_286 ) {
V_8 -> V_288 = 1 ;
break;
}
}
}
}
static T_1 F_167 ( struct V_3 * V_4 , T_1 V_289 )
{
T_1 V_31 , V_293 ;
V_293 = V_4 -> V_294 + V_4 -> V_295 ;
for ( V_31 = V_4 -> V_294 ; V_31 < V_293 ; V_31 ++ ) {
unsigned int V_296 = F_136 ( V_4 , V_31 ) ;
unsigned int type = F_137 ( V_296 ) ;
if ( type == V_345 && ( V_296 & V_298 ) ) {
if ( F_134 ( V_4 , V_31 , V_289 ) >= 0 )
return V_31 ;
}
}
return 0 ;
}
static void F_168 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
T_1 V_31 ;
if ( V_254 -> V_366 &&
F_127 ( V_4 , V_254 -> V_367 [ 0 ] , & V_31 , 1 ) == 1 )
V_8 -> V_9 . V_42 = V_31 ;
if ( V_254 -> V_368 )
V_8 -> V_46 = F_167 ( V_4 , V_254 -> V_368 ) ;
}
static void F_169 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_293 ;
V_293 = V_4 -> V_294 + V_4 -> V_295 ;
for ( V_31 = V_4 -> V_294 ; V_31 < V_293 ; V_31 ++ )
if ( F_137 ( F_136 ( V_4 , V_31 ) ) == V_369 ) {
F_71 ( V_8 , V_31 , 0 , V_78 ) ;
break;
}
}
static void F_170 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_293 ;
V_293 = V_4 -> V_294 + V_4 -> V_295 ;
for ( V_31 = V_4 -> V_294 ; V_31 < V_293 ; V_31 ++ ) {
if ( F_137 ( F_136 ( V_4 , V_31 ) ) != V_370 )
continue;
if ( ! ( F_171 ( V_4 , V_31 ) & V_371 ) )
continue;
V_8 -> V_372 [ V_8 -> V_373 ++ ] = V_31 ;
if ( V_8 -> V_373 >= F_70 ( V_8 -> V_372 ) )
break;
}
V_8 -> V_329 = V_8 -> V_373 > 2 ;
}
static int F_172 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_72 ;
V_72 = F_173 ( V_4 , & V_8 -> V_308 , NULL ) ;
if ( V_72 < 0 )
return V_72 ;
F_139 ( V_4 ) ;
F_164 ( V_4 ) ;
F_168 ( V_4 ) ;
F_169 ( V_4 ) ;
F_170 ( V_4 ) ;
return 0 ;
}
static void F_142 ( struct V_3 * V_4 , int V_252 ,
T_1 * V_300 , bool V_328 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_252 ; V_68 ++ ) {
if ( F_171 ( V_4 , V_300 [ V_68 ] ) & V_371 )
F_85 ( V_4 , V_300 [ V_68 ] , 0 ,
V_93 ,
V_328 ? 0x02 : 0 ) ;
}
}
static void F_174 ( struct V_3 * V_4 , T_1 V_289 ,
T_1 V_374 )
{
int V_248 = F_134 ( V_4 , V_289 , V_374 ) ;
if ( V_248 >= 0 )
F_85 ( V_4 , V_289 , 0 ,
V_182 , V_248 ) ;
}
static void F_175 ( struct V_3 * V_4 , int V_375 ,
const T_1 * V_376 )
{
int V_68 , V_335 ;
for ( V_68 = 0 ; V_68 < V_375 ; V_68 ++ ) {
T_1 V_31 = V_376 [ V_68 ] ;
if ( ! ( F_136 ( V_4 , V_31 ) & V_377 ) )
continue;
if ( F_176 ( V_4 , V_31 , V_78 ) & V_378 )
V_335 = V_151 ;
else
V_335 = V_379 ;
F_85 ( V_4 , V_31 , 0 ,
V_103 , V_335 ) ;
}
}
static void F_177 ( struct V_3 * V_4 , int V_252 ,
T_1 * V_300 , unsigned int V_380 ,
T_2 V_381 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_252 ; V_68 ++ )
F_178 ( V_4 , V_300 [ V_68 ] , V_380 , V_381 ) ;
}
static bool F_179 ( T_1 V_31 , const T_1 * V_382 , int V_291 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_291 ; V_68 ++ )
if ( V_382 [ V_68 ] == V_31 )
return true ;
return false ;
}
static bool F_180 ( struct V_307 * V_254 , T_1 V_31 )
{
int V_68 ;
if ( F_179 ( V_31 , V_254 -> V_310 , V_254 -> V_311 ) ||
F_179 ( V_31 , V_254 -> V_314 , V_254 -> V_315 ) ||
F_179 ( V_31 , V_254 -> V_317 , V_254 -> V_318 ) ||
F_179 ( V_31 , V_254 -> V_367 , V_254 -> V_366 ) )
return true ;
for ( V_68 = 0 ; V_68 < V_254 -> V_362 ; V_68 ++ )
if ( V_254 -> V_363 [ V_68 ] . V_289 == V_31 )
return true ;
if ( V_254 -> V_368 == V_31 )
return true ;
return false ;
}
static void F_181 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_4 -> V_383 . V_384 ; V_68 ++ ) {
struct V_385 * V_289 = F_182 ( & V_4 -> V_383 , V_68 ) ;
if ( ! F_180 ( V_254 , V_289 -> V_31 ) )
F_85 ( V_4 , V_289 -> V_31 , 0 ,
V_188 , 0 ) ;
}
}
static void F_183 ( void * V_386 , int V_387 )
{
struct V_3 * V_4 = V_386 ;
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_387 && V_8 -> V_329 ) {
F_144 ( V_4 ) ;
return;
}
F_142 ( V_4 , V_8 -> V_373 , V_8 -> V_372 , V_387 ) ;
}
static void F_184 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
T_1 V_31 ;
int V_68 ;
F_175 ( V_4 , V_8 -> V_9 . V_97 , V_8 -> V_9 . V_32 ) ;
for ( V_68 = 0 ; V_68 < V_254 -> V_315 ; V_68 ++ ) {
unsigned int V_335 = V_178 ;
if ( F_171 ( V_4 , V_254 -> V_314 [ V_68 ] ) &
V_388 )
V_335 |= V_389 ;
F_82 ( V_4 , V_254 -> V_314 [ V_68 ] , V_335 ) ;
}
F_175 ( V_4 , V_254 -> V_315 , V_254 -> V_314 ) ;
F_175 ( V_4 , V_254 -> V_311 , V_254 -> V_310 ) ;
F_175 ( V_4 , V_254 -> V_318 , V_254 -> V_317 ) ;
for ( V_68 = 0 ; V_68 < V_8 -> V_320 ; V_68 ++ ) {
V_31 = V_8 -> V_312 [ V_68 ] . V_305 ;
if ( ! V_31 )
V_31 = V_8 -> V_9 . V_32 [ 0 ] ;
else if ( V_31 & V_306 )
V_31 &= ~ V_306 ;
F_174 ( V_4 , V_8 -> V_312 [ V_68 ] . V_289 , V_31 ) ;
}
if ( V_8 -> V_324 ) {
F_177 ( V_4 , V_254 -> V_315 , V_254 -> V_314 ,
V_107 , F_145 ) ;
V_8 -> V_99 = F_143 ( V_4 , V_254 -> V_315 ,
V_254 -> V_314 ) ;
if ( V_8 -> V_326 ) {
F_177 ( V_4 , V_254 -> V_311 ,
V_254 -> V_310 ,
V_390 ,
F_146 ) ;
V_8 -> V_330 =
F_143 ( V_4 , V_254 -> V_311 ,
V_254 -> V_310 ) ;
}
}
F_144 ( V_4 ) ;
if ( ! V_8 -> V_329 )
F_142 ( V_4 , V_8 -> V_373 , V_8 -> V_372 , true ) ;
F_181 ( V_4 ) ;
}
static void F_185 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
int V_68 , V_335 ;
for ( V_68 = 0 ; V_68 < V_8 -> V_41 ; V_68 ++ ) {
T_1 V_31 = V_8 -> V_13 [ V_68 ] ;
if ( ! ( F_136 ( V_4 , V_31 ) & V_391 ) )
continue;
if ( F_176 ( V_4 , V_31 , V_146 ) & V_378 )
V_335 = F_186 ( 0 ) ;
else
V_335 = F_187 ( 0 ) ;
F_85 ( V_4 , V_31 , 0 , V_103 ,
V_335 ) ;
}
for ( V_68 = 0 ; V_68 < V_254 -> V_362 ; V_68 ++ ) {
T_1 V_289 = V_254 -> V_363 [ V_68 ] . V_289 ;
unsigned int type = V_224 ;
if ( V_254 -> V_363 [ V_68 ] . type == V_392 )
type |= F_188 ( V_4 , V_289 ) ;
F_82 ( V_4 , V_289 , type ) ;
}
if ( V_8 -> V_180 ) {
if ( V_8 -> V_350 >= 0 ) {
F_178 ( V_4 ,
V_254 -> V_363 [ V_8 -> V_350 ] . V_289 ,
V_108 , F_160 ) ;
}
if ( V_8 -> V_351 >= 0 ) {
F_178 ( V_4 ,
V_254 -> V_363 [ V_8 -> V_351 ] . V_289 ,
V_108 , F_160 ) ;
}
F_160 ( V_4 , NULL ) ;
} else {
F_155 ( V_4 , V_8 -> V_287 [ 0 ] . V_286 ,
V_8 -> V_287 [ 0 ] . V_289 ) ;
}
}
static void F_189 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_307 * V_254 = & V_8 -> V_308 ;
if ( V_8 -> V_9 . V_42 )
F_82 ( V_4 , V_254 -> V_367 [ 0 ] , V_178 ) ;
if ( V_8 -> V_46 )
F_82 ( V_4 , V_254 -> V_368 , V_224 ) ;
}
static int F_190 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_191 ( V_4 ) ;
F_184 ( V_4 ) ;
F_185 ( V_4 ) ;
F_189 ( V_4 ) ;
F_192 ( & V_8 -> V_80 ) ;
return 0 ;
}
static int F_193 ( struct V_3 * V_4 , const char * V_393 ,
const char * V_394 , int V_395 ,
T_1 V_31 , int V_396 , int V_397 , int V_398 )
{
static char V_25 [ 44 ] ;
static struct V_84 V_85 [] = {
F_194 ( V_25 , 0 , 0 , 0 ) ,
F_195 ( V_25 , 0 , 0 , 0 ) ,
} ;
static const char * const V_399 [ 2 ] = { L_19 , L_20 } ;
int V_68 , V_72 ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
struct V_49 * V_87 ;
V_85 [ V_68 ] . V_89 = F_196 ( V_31 , V_398 , V_397 ,
V_396 ) ;
V_85 [ V_68 ] . V_400 = V_401 ;
V_85 [ V_68 ] . V_219 = V_395 ;
snprintf ( V_25 , sizeof( V_25 ) , L_21 , V_393 , V_394 , V_399 [ V_68 ] ) ;
V_87 = F_48 ( & V_85 [ V_68 ] , V_4 ) ;
if ( ! V_87 )
return - V_88 ;
V_72 = F_49 ( V_4 , V_31 , V_87 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( ! ( F_176 ( V_4 , V_31 , V_396 ) &
( V_378 | V_402 ) ) )
break;
}
return 0 ;
}
static int F_197 ( struct V_3 * V_4 , T_1 V_305 ,
T_1 V_289 , const char * V_25 , int V_248 )
{
unsigned int V_403 ;
if ( V_305 && ! ( V_305 & V_306 ) ) {
V_403 = F_176 ( V_4 , V_305 , V_78 ) ;
if ( V_403 & V_404 )
return F_198 ( V_4 , V_305 , V_25 , V_248 ) ;
}
V_403 = F_176 ( V_4 , V_289 , V_78 ) ;
if ( V_403 & V_404 )
return F_198 ( V_4 , V_289 , V_25 , V_248 ) ;
return 0 ;
}
static bool F_20 ( struct V_7 * V_8 )
{
int V_68 , type , V_405 = 0 ;
for ( V_68 = 0 ; V_68 < V_8 -> V_320 ; V_68 ++ ) {
type = V_8 -> V_312 [ V_68 ] . type ;
if ( type == V_313 )
type = V_8 -> V_308 . V_325 ;
if ( type == V_319 )
V_405 ++ ;
}
return ( V_405 == 2 && V_8 -> V_308 . V_325 != V_313 ) ;
}
static int F_199 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_68 , V_72 ;
int V_406 = 0 , V_407 = 0 , V_405 = 0 ;
bool V_408 ;
static const char * const V_409 [ 3 ] = { L_22 , L_23 , L_24 } ;
if ( V_8 -> V_320 == 1 )
return F_197 ( V_4 , V_8 -> V_312 [ 0 ] . V_305 ,
V_8 -> V_312 [ 0 ] . V_289 ,
L_25 , 0 ) ;
V_408 = F_20 ( V_8 ) ;
for ( V_68 = 0 ; V_68 < V_8 -> V_320 ; V_68 ++ ) {
const char * V_364 ;
int V_248 , type ;
T_1 V_305 = V_8 -> V_312 [ V_68 ] . V_305 ;
type = V_8 -> V_312 [ V_68 ] . type ;
if ( type == V_313 )
type = V_8 -> V_308 . V_325 ;
switch ( type ) {
case V_313 :
default:
V_364 = V_409 [ V_406 ++ ] ;
V_248 = 0 ;
break;
case V_316 :
V_364 = L_26 ;
V_248 = V_407 ++ ;
break;
case V_319 :
if ( V_408 ) {
V_364 = V_405 ++ ? L_27 : L_28 ;
V_248 = 0 ;
} else {
V_364 = L_28 ;
V_248 = V_405 ++ ;
}
break;
}
V_72 = F_197 ( V_4 , V_305 ,
V_8 -> V_312 [ V_68 ] . V_289 ,
V_364 , V_248 ) ;
if ( V_72 < 0 )
return V_72 ;
}
if ( V_8 -> V_324 ) {
V_72 = F_39 ( V_4 , V_410 ) ;
if ( V_72 < 0 )
return V_72 ;
}
return 0 ;
}
static int F_200 ( struct V_3 * V_4 , const char * V_364 ,
char * V_411 , int V_31 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_68 ;
if ( ! V_8 -> V_412 )
return 0 ;
for ( V_68 = 0 ; V_68 < V_413 ; V_68 ++ ) {
int V_355 ;
if ( V_8 -> V_308 . V_363 [ V_68 ] . V_289 != V_31 )
continue;
if ( V_8 -> V_308 . V_363 [ V_68 ] . type != V_392 )
return 0 ;
V_355 = F_125 ( V_4 , V_31 ) ;
if ( F_162 ( V_355 ) != V_358 )
return 0 ;
snprintf ( V_411 , 44 , L_29 , V_364 ) ;
return 1 ;
}
return 0 ;
}
static int F_201 ( struct V_3 * V_4 , T_1 V_31 ,
const char * V_364 , const char * V_414 ,
int V_395 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_8 -> V_41 ; V_68 ++ ) {
char V_415 [ 44 ] ;
T_1 V_416 = V_8 -> V_13 [ V_68 ] ;
int V_248 = F_156 ( V_4 , V_416 , V_31 ) ;
if ( V_248 < 0 )
continue;
if ( V_4 -> V_115 )
V_248 = 0 ;
if ( F_200 ( V_4 , V_364 , V_415 , V_31 ) ) {
int V_72 = F_193 ( V_4 , V_364 , V_414 ,
V_395 , V_416 , V_146 , V_248 , 1 ) ;
if ( V_72 < 0 )
return V_72 ;
return F_193 ( V_4 , V_415 , V_414 ,
V_395 , V_416 , V_146 , V_248 , 2 ) ;
}
return F_193 ( V_4 , V_364 , V_414 ,
V_395 , V_416 , V_146 , V_248 , 3 ) ;
}
return 0 ;
}
static int F_202 ( struct V_3 * V_4 , int V_248 ,
const char * V_364 , int V_395 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_338 , V_31 ;
int V_68 , V_417 ;
V_31 = V_8 -> V_287 [ V_248 ] . V_289 ;
if ( F_136 ( V_4 , V_31 ) & V_391 ) {
char V_415 [ 44 ] ;
if ( F_200 ( V_4 , V_364 , V_415 , V_31 ) ) {
int V_72 = F_193 ( V_4 , V_364 , L_30 ,
V_395 , V_31 , V_146 , 0 , 1 ) ;
if ( V_72 < 0 )
return V_72 ;
return F_193 ( V_4 , V_415 , L_30 ,
V_395 , V_31 , V_146 , 0 , 2 ) ;
}
return F_203 ( V_4 , V_364 , L_30 , V_395 ,
V_31 , V_146 ) ;
}
V_417 = F_154 ( V_4 , V_8 -> V_287 [ V_248 ] . V_286 , V_31 ,
& V_338 , false , 0 ) ;
if ( V_417 < 0 )
return 0 ;
for ( V_68 = 0 ; V_68 < V_248 ; V_68 ++ ) {
if ( V_8 -> V_287 [ V_68 ] . V_365 == V_338 )
return 0 ;
}
if ( F_136 ( V_4 , V_338 ) & V_377 ) {
V_8 -> V_287 [ V_248 ] . V_365 = V_338 ;
return F_203 ( V_4 , V_364 , L_30 , V_395 ,
V_338 , V_78 ) ;
}
return 0 ;
}
static int F_204 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_246 * V_247 = & V_8 -> V_337 ;
const char * V_418 ;
int V_419 [ V_343 ] ;
int V_68 , V_309 , V_72 , V_395 ;
int V_420 ;
if ( ! V_247 -> V_249 )
return 0 ;
V_420 = 0 ;
for ( V_68 = 0 ; V_68 < V_247 -> V_249 ; V_68 ++ ) {
V_395 = F_156 ( V_4 , V_8 -> V_287 [ V_68 ] . V_286 ,
V_8 -> V_287 [ V_68 ] . V_289 ) ;
if ( V_395 < 0 )
continue;
V_419 [ V_68 ] = V_8 -> V_287 [ V_68 ] . V_286 ;
if ( ! V_4 -> V_115 )
V_419 [ V_68 ] |= V_395 << 8 ;
if ( V_68 > 0 && V_419 [ V_68 ] != V_419 [ 0 ] )
V_420 = 1 ;
}
V_418 = NULL ;
V_395 = 0 ;
for ( V_68 = 0 ; V_68 < V_247 -> V_249 ; V_68 ++ ) {
T_1 V_31 = V_8 -> V_287 [ V_68 ] . V_289 ;
const char * V_364 ;
V_364 = F_165 ( V_4 , & V_8 -> V_308 ,
V_8 -> V_287 [ V_68 ] . V_219 ) ;
if ( V_364 == V_418 )
V_395 ++ ;
else
V_395 = 0 ;
V_418 = V_364 ;
V_72 = F_202 ( V_4 , V_68 , V_364 , V_395 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( ! V_420 ) {
if ( V_68 > 0 )
continue;
V_72 = F_201 ( V_4 , V_31 ,
L_31 , L_32 , V_395 ) ;
} else {
bool V_421 = false ;
for ( V_309 = 0 ; V_309 < V_68 ; V_309 ++ ) {
if ( V_419 [ V_309 ] == V_419 [ V_68 ] ) {
V_421 = true ;
break;
}
}
if ( V_421 )
continue;
V_72 = F_201 ( V_4 , V_31 ,
V_364 , L_33 , V_395 ) ;
}
if ( V_72 < 0 )
return V_72 ;
}
if ( V_8 -> V_337 . V_249 > 1 && ! V_8 -> V_180 ) {
V_72 = F_39 ( V_4 , V_422 ) ;
if ( V_72 < 0 )
return V_72 ;
}
return 0 ;
}
static int F_205 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_72 ;
V_72 = F_199 ( V_4 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 = F_204 ( V_4 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 = F_38 ( V_4 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 = F_206 ( V_4 , & V_8 -> V_308 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_8 -> V_80 . V_81 ) {
V_8 -> V_80 . V_423 = F_183 ;
V_72 = F_207 ( V_4 , & V_8 -> V_80 ,
V_8 -> V_424 ) ;
if ( V_72 < 0 )
return V_72 ;
}
return 0 ;
}
static int F_208 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_293 ;
V_293 = V_4 -> V_294 + V_4 -> V_295 ;
for ( V_31 = V_4 -> V_294 ; V_31 < V_293 ; V_31 ++ ) {
unsigned int V_403 = F_136 ( V_4 , V_31 ) ;
if ( F_137 ( V_403 ) != V_345 )
continue;
if ( V_403 & V_298 )
continue;
if ( F_209 ( V_8 -> V_41 >=
F_70 ( V_8 -> V_425 ) ) )
break;
V_8 -> V_425 [ V_8 -> V_41 ++ ] = V_31 ;
}
V_8 -> V_13 = V_8 -> V_425 ;
return 0 ;
}
static void F_210 ( struct V_3 * V_4 ,
const struct V_426 * V_427 , int V_380 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_412 = 1 ;
}
static void F_211 ( struct V_3 * V_4 ,
const struct V_426 * V_427 , int V_380 )
{
if ( V_380 != V_428 )
return;
F_73 ( V_4 , 0x17 , V_78 ,
( 0x3 << V_147 ) |
( 0x4 << V_148 ) |
( 0x27 << V_149 ) |
( 0 << V_150 ) ) ;
}
static void F_212 ( struct V_3 * V_4 )
{
static T_1 V_429 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_430 ;
for ( V_430 = V_429 ; * V_430 ; V_430 ++ )
F_73 ( V_4 , * V_430 , V_78 ,
V_402 |
F_176 ( V_4 , * V_430 , V_78 ) ) ;
}
static int F_68 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_72 ;
F_213 ( V_431 L_34 ,
V_4 -> V_432 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_114 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
F_214 ( & V_8 -> V_71 ) ;
switch ( V_4 -> V_37 ) {
case 0x14f15045 :
V_4 -> V_115 = 1 ;
break;
case 0x14f15051 :
F_212 ( V_4 ) ;
V_4 -> V_157 = 1 ;
F_215 ( V_4 , NULL , V_433 , V_434 ) ;
break;
default:
V_4 -> V_157 = 1 ;
F_215 ( V_4 , NULL , V_435 , V_434 ) ;
break;
}
F_216 ( V_4 , V_428 ) ;
switch ( V_4 -> V_145 >> 16 ) {
case 0x103c :
V_8 -> V_424 = 1 ;
break;
}
V_72 = F_208 ( V_4 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 = F_172 ( V_4 ) ;
if ( V_72 < 0 ) {
F_37 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
return V_72 ;
}
V_8 -> V_35 = & V_436 ;
V_4 -> V_125 = V_437 ;
if ( V_8 -> V_83 )
F_74 ( V_4 , V_8 -> V_83 ) ;
if ( ! V_4 -> V_438 -> V_439 ) {
F_217 ( L_35
L_36 ) ;
V_4 -> V_438 -> V_439 = 1 ;
V_4 -> V_438 -> V_440 = 1 ;
}
return 0 ;
}
static int T_3 F_218 ( void )
{
return F_219 ( & V_441 ) ;
}
static void T_4 F_220 ( void )
{
F_221 ( & V_441 ) ;
}
