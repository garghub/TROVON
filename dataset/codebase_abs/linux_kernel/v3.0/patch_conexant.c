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
static int F_27 ( struct V_3 * V_4 )
{
#ifdef F_28
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_62 ; V_61 ++ ) {
const struct V_63 * V_64 ;
V_64 = V_8 -> V_65 [ V_61 ] ;
while ( V_64 -> V_31 ) {
int V_66 = 0 ;
switch ( V_64 -> V_67 ^ V_68 ) {
case V_69 :
V_66 = F_29 ( V_4 , V_64 -> V_31 ,
V_70 , NULL ) ;
F_30 ( V_4 , V_64 -> V_31 ) ;
break;
case V_71 :
case V_72 :
V_66 = F_29 ( V_4 , V_64 -> V_31 ,
V_73 , NULL ) ;
F_30 ( V_4 , V_64 -> V_31 ) ;
break;
}
if ( V_66 < 0 )
return V_66 ;
++ V_64 ;
}
}
#endif
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_62 ; V_61 ++ )
F_32 ( V_4 , V_8 -> V_65 [ V_61 ] ) ;
return 0 ;
}
static void F_33 ( struct V_3 * V_4 )
{
F_34 ( V_4 ) ;
F_35 ( V_4 ) ;
F_36 ( V_4 -> V_8 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_61 ;
int V_66 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_74 ; V_61 ++ ) {
V_66 = F_38 ( V_4 , V_8 -> V_75 [ V_61 ] ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_9 . V_40 ) {
V_66 = F_39 ( V_4 ,
V_8 -> V_9 . V_40 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_40 ( V_4 ,
& V_8 -> V_9 ) ;
if ( V_66 < 0 )
return V_66 ;
V_8 -> V_9 . V_76 = 1 ;
}
if ( V_8 -> V_44 ) {
V_66 = F_41 ( V_4 , V_8 -> V_44 ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_77 &&
! F_42 ( V_4 , L_3 ) ) {
unsigned int V_78 [ 4 ] ;
F_43 ( V_4 , V_8 -> V_77 ,
V_79 , V_78 ) ;
V_66 = F_44 ( V_4 , L_3 ,
V_78 , V_80 ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_77 &&
! F_42 ( V_4 , L_4 ) ) {
V_66 = F_44 ( V_4 , L_4 ,
NULL , V_81 ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_51 ) {
V_66 = F_38 ( V_4 , V_82 ) ;
if ( V_66 < 0 )
return V_66 ;
}
#ifdef F_45
if ( V_8 -> V_83 ) {
const struct V_84 * V_85 ;
for ( V_85 = V_86 ; V_85 -> V_25 ; V_85 ++ ) {
struct V_47 * V_87 ;
V_87 = F_46 ( V_85 , V_4 ) ;
if ( ! V_87 )
return - V_88 ;
V_87 -> V_89 = V_8 -> V_83 ;
V_66 = F_47 ( V_4 , 0 , V_87 ) ;
if ( V_66 < 0 )
return V_66 ;
}
}
#endif
return 0 ;
}
static int F_48 ( struct V_3 * V_4 , T_1 V_90 )
{
F_49 ( V_4 ) ;
return 0 ;
}
static int F_50 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_91 = ( V_48 -> V_89 >> 8 ) & 1 ;
if ( V_91 )
V_53 -> V_56 . integer . V_56 [ 0 ] = ! V_8 -> V_92 ;
else
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_92 ;
return 0 ;
}
static int F_51 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_91 = ( V_48 -> V_89 >> 8 ) & 1 ;
T_2 V_31 = V_48 -> V_89 & 0xff ;
unsigned int V_93 ;
V_93 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_91 )
V_93 = ! V_93 ;
if ( V_93 == V_8 -> V_92 )
return 0 ;
V_8 -> V_92 = V_93 ;
F_52 ( V_4 , V_31 ,
0 , V_94 ,
V_93 ? 0x02 : 0x00 ) ;
return 1 ;
}
static int F_53 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_54 ( V_4 , V_50 , V_8 -> V_95 ,
V_8 -> V_96 ) ;
}
static int F_55 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_56 ( V_4 , V_53 , V_8 -> V_95 ,
V_8 -> V_96 ,
V_8 -> V_9 . V_30 ) ;
}
static int F_57 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 = F_58 ( V_4 , V_53 , V_8 -> V_95 ,
V_8 -> V_96 ,
& V_8 -> V_9 . V_30 ) ;
if ( V_66 >= 0 && V_8 -> V_97 )
V_8 -> V_9 . V_98 = V_8 -> V_9 . V_30 / 2 ;
return V_66 ;
}
static int F_59 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_99 ;
if ( ! F_51 ( V_48 , V_53 ) )
return 0 ;
V_99 = ( ! V_8 -> V_100 && V_8 -> V_92 ) ? 0 : V_101 ;
F_60 ( V_4 , 0x10 , V_79 , 0 ,
V_101 , V_99 ) ;
V_99 = V_8 -> V_92 ? 0 : V_101 ;
F_60 ( V_4 , 0x11 , V_79 , 0 ,
V_101 , V_99 ) ;
return 1 ;
}
static void F_61 ( struct V_3 * V_4 )
{
static const struct V_63 V_102 [] = {
{ 0x14 , V_103 , 0xb080 } ,
{ 0x12 , V_103 , 0xb000 } ,
{}
} ;
static const struct V_63 V_104 [] = {
{ 0x12 , V_103 , 0xb080 } ,
{ 0x14 , V_103 , 0xb000 } ,
{}
} ;
unsigned int V_105 ;
V_105 = F_62 ( V_4 , 0x12 ) ;
if ( V_105 )
F_32 ( V_4 , V_102 ) ;
else
F_32 ( V_4 , V_104 ) ;
}
static void F_63 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_99 ;
V_8 -> V_100 = F_62 ( V_4 , 0x11 ) ;
V_99 = ( V_8 -> V_100 || ! V_8 -> V_92 ) ? V_101 : 0 ;
F_60 ( V_4 , 0x10 , V_79 , 0 ,
V_101 , V_99 ) ;
}
static void F_64 ( struct V_3 * V_4 ,
unsigned int V_106 )
{
V_106 >>= 26 ;
switch ( V_106 ) {
case V_69 :
F_63 ( V_4 ) ;
break;
case V_72 :
F_61 ( V_4 ) ;
break;
}
}
static int F_65 ( struct V_3 * V_4 )
{
F_31 ( V_4 ) ;
F_63 ( V_4 ) ;
return 0 ;
}
static int F_66 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_107 ;
V_107 = F_67 ( V_4 , V_108 ,
V_109 ,
V_110 ) ;
#if 0
if (board_config < 0)
board_config = CXT5045_AUTO;
#endif
if ( V_107 == V_111 )
return F_68 ( V_4 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_113 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_98 = F_70 ( V_114 ) ;
V_8 -> V_9 . V_32 = V_114 ;
V_8 -> V_9 . V_40 = V_115 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_116 ;
V_8 -> V_60 = V_117 ;
V_8 -> V_51 = & V_118 ;
V_8 -> V_74 = 1 ;
V_8 -> V_75 [ 0 ] = V_119 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_120 ;
V_8 -> V_121 = 0 ;
V_8 -> V_96 = F_70 ( V_122 ) ;
V_8 -> V_95 = V_122 ;
F_71 ( V_8 , 0x16 , 0 , 1 ) ;
V_4 -> V_123 = V_124 ;
switch ( V_107 ) {
case V_125 :
V_4 -> V_123 . V_126 = F_64 ;
V_8 -> V_51 = & V_118 ;
V_8 -> V_62 = 2 ;
V_8 -> V_65 [ 1 ] = V_127 ;
V_8 -> V_75 [ 0 ] = V_119 ;
V_4 -> V_123 . V_128 = F_65 ;
break;
case V_129 :
V_4 -> V_123 . V_126 = F_64 ;
V_8 -> V_51 = & V_118 ;
V_8 -> V_62 = 2 ;
V_8 -> V_65 [ 1 ] = V_130 ;
V_8 -> V_75 [ 0 ] = V_119 ;
V_4 -> V_123 . V_128 = F_65 ;
break;
default:
case V_131 :
V_4 -> V_123 . V_126 = F_64 ;
V_8 -> V_51 = & V_118 ;
V_8 -> V_62 = 3 ;
V_8 -> V_65 [ 1 ] = V_127 ;
V_8 -> V_65 [ 2 ] = V_130 ;
V_8 -> V_75 [ 0 ] = V_119 ;
V_4 -> V_123 . V_128 = F_65 ;
break;
case V_132 :
V_4 -> V_123 . V_126 = F_64 ;
V_8 -> V_51 = & V_133 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_134 ;
V_8 -> V_75 [ 0 ] = V_119 ;
V_8 -> V_75 [ 1 ] = V_135 ;
V_8 -> V_74 = 2 ;
V_4 -> V_123 . V_128 = F_65 ;
break;
case V_136 :
V_4 -> V_123 . V_126 = F_64 ;
V_8 -> V_51 = & V_137 ;
V_8 -> V_62 = 2 ;
V_8 -> V_65 [ 1 ] = V_127 ;
V_8 -> V_75 [ 0 ] = V_138 ;
V_4 -> V_123 . V_128 = F_65 ;
break;
#ifdef F_72
case V_139 :
V_8 -> V_51 = & V_140 ;
V_8 -> V_75 [ 0 ] = V_141 ;
V_8 -> V_65 [ 0 ] = V_142 ;
break;
#endif
}
switch ( V_4 -> V_143 >> 16 ) {
case 0x103c :
case 0x1631 :
case 0x1734 :
case 0x17aa :
F_73 ( V_4 , 0x17 , V_144 ,
( 0x14 << V_145 ) |
( 0x14 << V_146 ) |
( 0x05 << V_147 ) |
( 1 << V_148 ) ) ;
break;
}
if ( V_8 -> V_83 )
F_74 ( V_4 , V_8 -> V_83 ) ;
return 0 ;
}
static int F_75 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_99 ;
if ( ! F_51 ( V_48 , V_53 ) )
return 0 ;
V_99 = ( ! V_8 -> V_100 && V_8 -> V_92 ) ? 0 : V_101 ;
F_60 ( V_4 , 0x1d , V_79 , 0x01 ,
V_101 , V_99 ) ;
V_99 = V_8 -> V_92 ? 0 : V_101 ;
F_60 ( V_4 , 0x13 , V_79 , 0 ,
V_101 , V_99 ) ;
return 1 ;
}
static void F_76 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_99 ;
V_8 -> V_100 = F_62 ( V_4 , 0x13 ) ;
V_99 = ( V_8 -> V_100 || ! V_8 -> V_92 ) ? V_101 : 0 ;
F_60 ( V_4 , 0x1d , V_79 , 0x01 ,
V_101 , V_99 ) ;
}
static void F_77 ( struct V_3 * V_4 )
{
static const struct V_63 V_102 [] = {
{ 0x15 , V_103 , V_149 } ,
{ 0x17 , V_103 , V_150 } ,
{}
} ;
static const struct V_63 V_104 [] = {
{ 0x17 , V_103 , V_149 } ,
{ 0x15 , V_103 , V_150 } ,
{}
} ;
unsigned int V_105 ;
V_105 = F_62 ( V_4 , 0x15 ) ;
if ( V_105 )
F_32 ( V_4 , V_102 ) ;
else
F_32 ( V_4 , V_104 ) ;
}
static void F_78 ( struct V_3 * V_4 ,
unsigned int V_106 )
{
switch ( V_106 >> 26 ) {
case V_69 :
F_76 ( V_4 ) ;
break;
case V_72 :
F_77 ( V_4 ) ;
break;
}
}
static int F_79 ( struct V_3 * V_4 )
{
F_31 ( V_4 ) ;
F_76 ( V_4 ) ;
return 0 ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_107 ;
V_107 = F_67 ( V_4 , V_151 ,
V_152 ,
V_153 ) ;
#if 0
if (board_config < 0)
board_config = CXT5047_AUTO;
#endif
if ( V_107 == V_154 )
return F_68 ( V_4 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_113 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_98 = F_70 ( V_155 ) ;
V_8 -> V_9 . V_32 = V_155 ;
V_8 -> V_9 . V_40 = V_156 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_157 ;
V_8 -> V_60 = V_158 ;
V_8 -> V_74 = 1 ;
V_8 -> V_75 [ 0 ] = V_159 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_160 ;
V_8 -> V_121 = 0 ;
V_8 -> V_96 = F_70 ( V_161 ) ,
V_8 -> V_95 = V_161 ,
V_4 -> V_123 = V_124 ;
switch ( V_107 ) {
case V_162 :
V_8 -> V_74 = 2 ;
V_8 -> V_75 [ 1 ] = V_163 ;
V_4 -> V_123 . V_126 = F_78 ;
break;
case V_164 :
V_8 -> V_74 = 2 ;
V_8 -> V_75 [ 1 ] = V_165 ;
V_4 -> V_123 . V_126 = F_78 ;
V_4 -> V_123 . V_128 = F_79 ;
break;
case V_166 :
V_8 -> V_51 = & V_167 ;
V_8 -> V_74 = 2 ;
V_8 -> V_75 [ 1 ] = V_163 ;
V_8 -> V_62 = 2 ;
V_8 -> V_65 [ 1 ] = V_168 ;
V_4 -> V_123 . V_126 = F_78 ;
break;
#ifdef F_72
case V_169 :
V_8 -> V_51 = & V_170 ;
V_8 -> V_75 [ 0 ] = V_171 ;
V_8 -> V_65 [ 0 ] = V_172 ;
V_4 -> V_123 . V_126 = F_78 ;
#endif
}
V_8 -> V_77 = 0x13 ;
switch ( V_4 -> V_143 >> 16 ) {
case 0x103c :
F_73 ( V_4 , 0x10 , V_144 ,
( 0x17 << V_145 ) |
( 0x17 << V_146 ) |
( 0x05 << V_147 ) |
( 1 << V_148 ) ) ;
break;
}
return 0 ;
}
static void F_81 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_173 ;
V_173 = ( V_8 -> V_100 && V_8 -> V_92 ) ? V_174 : 0 ;
F_82 ( V_4 , 0x16 , 0 , V_175 ,
V_173 ) ;
V_173 = ( ! V_8 -> V_100 && V_8 -> V_92 ) ? V_176 : 0 ;
F_82 ( V_4 , 0x1a , 0 , V_175 ,
V_173 ) ;
if ( V_8 -> V_177 )
F_82 ( V_4 , 0x1b , 0 ,
V_175 ,
V_173 ) ;
}
static int F_83 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
if ( ! F_51 ( V_48 , V_53 ) )
return 0 ;
F_81 ( V_4 ) ;
return 1 ;
}
static void F_84 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_105 ;
if ( ! ( V_8 -> V_178 & V_179 ) )
return;
V_105 = F_62 ( V_4 , 0x17 ) ;
F_82 ( V_4 , 0x14 , 0 ,
V_180 ,
V_105 ? 0x01 : 0x00 ) ;
}
static void F_85 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_105 ;
T_2 V_181 ;
if ( ! ( V_8 -> V_178 & V_182 ) )
return;
V_105 = F_62 ( V_4 , 0x18 ) ;
if ( V_105 )
V_8 -> V_17 = 1 ;
else
V_8 -> V_17 = 0 ;
V_181 = V_8 -> V_13 [ V_8 -> V_17 ] ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_181 ) {
F_86 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_181 ;
F_14 ( V_4 , V_181 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
}
static void F_87 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_100 = F_62 ( V_4 , 0x16 ) ;
F_81 ( V_4 ) ;
}
static void F_88 ( struct V_3 * V_4 ,
unsigned int V_106 )
{
int V_31 = ( V_106 & V_183 ) >> 20 ;
switch ( V_106 >> 26 ) {
case V_69 :
F_87 ( V_4 ) ;
break;
case V_184 :
F_84 ( V_4 ) ;
break;
case V_71 :
F_85 ( V_4 ) ;
break;
}
F_30 ( V_4 , V_31 ) ;
}
static void F_89 ( struct V_3 * V_4 , T_2 V_31 ,
unsigned int V_185 )
{
F_82 ( V_4 , V_31 , 0 ,
V_186 ,
V_68 | V_185 ) ;
F_29 ( V_4 , V_31 , V_73 , NULL ) ;
F_30 ( V_4 , V_31 ) ;
}
static int F_90 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_31 ( V_4 ) ;
F_27 ( V_4 ) ;
if ( V_8 -> V_178 & V_179 )
F_89 ( V_4 , 0x17 , V_184 ) ;
if ( V_8 -> V_178 & V_182 )
F_89 ( V_4 , 0x18 , V_71 ) ;
if ( V_4 -> V_123 . V_126 ) {
F_87 ( V_4 ) ;
F_84 ( V_4 ) ;
F_85 ( V_4 ) ;
}
return 0 ;
}
static int F_91 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_107 ;
V_107 = F_67 ( V_4 , V_187 ,
V_188 ,
V_189 ) ;
#if 0
if (board_config < 0)
board_config = CXT5051_AUTO;
#endif
if ( V_107 == V_190 )
return F_68 ( V_4 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_113 = 1 ;
V_4 -> V_123 = V_124 ;
V_4 -> V_123 . V_128 = F_90 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_98 = F_70 ( V_191 ) ;
V_8 -> V_9 . V_32 = V_191 ;
V_8 -> V_9 . V_40 = V_192 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_193 ;
V_8 -> V_74 = 2 ;
V_8 -> V_75 [ 0 ] = V_194 ;
V_8 -> V_75 [ 1 ] = V_195 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_196 ;
V_8 -> V_121 = 0 ;
V_8 -> V_96 = F_70 ( V_197 ) ;
V_8 -> V_95 = V_197 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_71 ( V_8 , 0x13 , 0 , V_79 ) ;
V_4 -> V_123 . V_126 = F_88 ;
V_8 -> V_178 = V_179 | V_182 ;
switch ( V_107 ) {
case V_198 :
V_8 -> V_75 [ 0 ] = V_199 ;
break;
case V_200 :
V_8 -> V_65 [ 0 ] = V_201 ;
V_8 -> V_75 [ 0 ] = V_202 ;
V_8 -> V_178 = 0 ;
break;
case V_203 :
V_8 -> V_65 [ 0 ] = V_204 ;
if ( V_4 -> V_143 == 0x17aa211f )
V_8 -> V_9 . V_40 = 0 ;
break;
case V_205 :
V_8 -> V_65 [ 0 ] = V_206 ;
V_8 -> V_75 [ 0 ] = V_207 ;
V_8 -> V_178 = 0 ;
break;
case V_208 :
V_8 -> V_75 [ 0 ] = V_209 ;
V_8 -> V_178 = V_179 ;
break;
case V_210 :
V_8 -> V_65 [ V_8 -> V_62 ++ ] =
V_211 ;
V_8 -> V_177 = 1 ;
break;
}
if ( V_8 -> V_83 )
F_74 ( V_4 , V_8 -> V_83 ) ;
return 0 ;
}
static void F_92 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_173 ;
F_93 ( L_5 ,
V_8 -> V_100 , V_8 -> V_92 ) ;
V_173 = ( F_94 ( V_8 ) && V_8 -> V_92 ) ? V_174 : 0 ;
F_82 ( V_4 , 0x19 , 0 , V_175 ,
V_173 ) ;
V_173 = V_8 -> V_92 ? V_8 -> V_212 : 0 ;
if ( V_8 -> V_213 || V_8 -> V_214 ) {
if ( F_94 ( V_8 ) )
V_173 = 0 ;
} else {
if ( ! F_95 ( V_8 ) )
V_173 = 0 ;
}
F_82 ( V_4 , 0x1c , 0 , V_175 ,
V_173 ) ;
V_173 = ( ! V_8 -> V_100 && V_8 -> V_92 ) ? V_176 : 0 ;
F_82 ( V_4 , 0x1f , 0 , V_175 ,
V_173 ) ;
}
static int F_96 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
if ( ! F_51 ( V_48 , V_53 ) )
return 0 ;
F_92 ( V_4 ) ;
return 1 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_52 ( V_4 , 0x1a , 0 ,
V_175 ,
V_215 . V_216 [ V_8 -> V_217 ] . V_218 ) ;
}
static void F_98 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_219 )
return;
if ( V_8 -> V_220 ) {
const struct V_63 V_221 [] = {
{ 0x1b , V_175 , 0 } ,
{ 0x1e , V_175 , V_222 } ,
{} ,
} ;
F_32 ( V_4 , V_221 ) ;
F_97 ( V_4 ) ;
return;
}
F_82 ( V_4 , 0x1e , 0 , V_175 , 0 ) ;
F_82 ( V_4 , 0x1a , 0 , V_175 ,
V_8 -> V_223 ? V_224 : 0 ) ;
F_82 ( V_4 , 0x1b , 0 , V_175 ,
V_8 -> V_223 ? 0 : V_225 ) ;
}
static void F_99 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_105 ;
if ( V_8 -> V_220 )
return;
V_105 = F_100 ( V_4 , 0x1a , 0 ,
V_226 , 0 ) & 0x80000000 ;
if ( V_105 )
F_93 ( L_6 ) ;
else
F_93 ( L_7 ) ;
F_82 ( V_4 , 0x17 , 0 , V_180 ,
V_105 ? 0 : 1 ) ;
V_8 -> V_223 = ! ! V_105 ;
F_98 ( V_4 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
unsigned int V_105 ;
struct V_63 V_223 [] = {
{ 0x1a , V_175 , V_225 } ,
{ 0x17 , V_180 , 0 } ,
{ 0x14 , V_180 , 0 } ,
{ 0x23 , V_175 , 0 } ,
{}
} ;
static const struct V_63 V_227 [] = {
{ 0x23 , V_175 , V_222 } ,
{ 0x14 , V_180 , 2 } ,
{ 0x1a , V_175 , 0 } ,
{}
} ;
V_105 = F_62 ( V_4 , 0x1a ) ;
if ( V_105 ) {
F_93 ( L_6 ) ;
F_32 ( V_4 , V_223 ) ;
} else {
F_93 ( L_7 ) ;
F_32 ( V_4 , V_227 ) ;
}
}
static void F_102 ( struct V_3 * V_4 )
{
unsigned int V_105 ;
struct V_63 V_223 [] = {
{ 0x14 , V_180 , 0 } ,
{ 0x1b , V_175 , V_225 } ,
{ 0x23 , V_175 , 0 } ,
{}
} ;
static const struct V_63 V_227 [] = {
{ 0x14 , V_180 , 2 } ,
{ 0x23 , V_175 , V_222 } ,
{ 0x1b , V_175 , 0 } ,
{}
} ;
V_105 = F_62 ( V_4 , 0x1b ) ;
if ( V_105 ) {
F_93 ( L_6 ) ;
F_32 ( V_4 , V_223 ) ;
} else {
F_93 ( L_7 ) ;
F_32 ( V_4 , V_227 ) ;
}
}
static void F_103 ( struct V_3 * V_4 )
{
unsigned int V_105 ;
V_105 = F_62 ( V_4 , 0x1b ) ;
F_93 ( L_8 , V_105 ) ;
F_82 ( V_4 , 0x17 , 0 , V_180 ,
V_105 ? 1 : 0 ) ;
}
static void F_104 ( struct V_3 * V_4 )
{
unsigned int V_105 ;
V_105 = F_62 ( V_4 , 0x1b ) ;
F_93 ( L_8 , V_105 ) ;
F_82 ( V_4 , 0x17 , 0 , V_180 ,
V_105 ? 1 : 3 ) ;
}
static void F_105 ( struct V_3 * V_4 )
{
unsigned int V_228 , V_229 ;
static const struct V_63 V_223 [] = {
{ 0x14 , V_180 , 0 } ,
{ 0x17 , V_180 , 1 } ,
{ 0x1b , V_175 , V_225 } ,
{ 0x23 , V_175 , 0 } ,
{ 0x1a , V_175 , 0 } ,
{}
} ;
static const struct V_63 V_230 [] = {
{ 0x14 , V_180 , 0 } ,
{ 0x17 , V_180 , 0 } ,
{ 0x1a , V_175 , V_225 } ,
{ 0x23 , V_175 , 0 } ,
{ 0x1b , V_175 , 0 } ,
{}
} ;
static const struct V_63 V_227 [] = {
{ 0x14 , V_180 , 2 } ,
{ 0x23 , V_175 , V_222 } ,
{ 0x1b , V_175 , 0 } ,
{ 0x1a , V_175 , 0 } ,
{}
} ;
V_228 = F_62 ( V_4 , 0x1b ) ;
V_229 = F_62 ( V_4 , 0x1a ) ;
if ( V_228 ) {
F_93 ( L_6 ) ;
F_32 ( V_4 , V_223 ) ;
} else if ( V_229 ) {
F_93 ( L_9 ) ;
F_32 ( V_4 , V_230 ) ;
} else {
F_93 ( L_7 ) ;
F_32 ( V_4 , V_227 ) ;
}
}
static void F_106 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_231 , V_232 ;
V_231 = F_62 ( V_4 , 0x19 ) ;
V_232 = F_62 ( V_4 , 0x1c ) ;
V_8 -> V_100 = V_231 ? V_233 : 0 ;
V_8 -> V_100 |= V_232 ? V_234 : 0 ;
F_93 ( L_10 ,
V_231 , V_232 , V_8 -> V_100 ) ;
F_92 ( V_4 ) ;
}
static void F_107 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 -> V_235 )
F_101 ( V_4 ) ;
else if ( V_8 -> V_177 )
F_102 ( V_4 ) ;
else if ( V_8 -> V_214 )
F_105 ( V_4 ) ;
else if ( V_8 -> V_236 )
F_104 ( V_4 ) ;
else if ( V_8 -> V_237 )
F_103 ( V_4 ) ;
}
static void F_108 ( struct V_3 * V_4 , unsigned int V_106 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_93 ( L_11 , V_106 , V_106 >> 26 ) ;
switch ( V_106 >> 26 ) {
case V_69 :
F_106 ( V_4 ) ;
break;
case V_72 :
if ( ! V_8 -> V_220 )
F_99 ( V_4 ) ;
break;
}
}
static void F_109 ( struct V_3 * V_4 , unsigned int V_106 )
{
F_93 ( L_11 , V_106 , V_106 >> 26 ) ;
switch ( V_106 >> 26 ) {
case V_69 :
F_106 ( V_4 ) ;
break;
case V_72 :
F_107 ( V_4 ) ;
break;
}
}
static void F_110 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_52 ( V_4 , 0x17 , 0 ,
V_103 ,
V_238 | V_239 | V_240 |
V_241 . V_216 [ V_8 -> V_242 ] . V_218 ) ;
if ( V_8 -> V_177 || V_8 -> V_214 ) {
F_52 ( V_4 , 0x23 , 0 ,
V_103 ,
V_238 | V_239 | V_243 |
V_241 .
V_216 [ V_8 -> V_242 ] . V_218 ) ;
}
}
static int F_111 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_241 , V_50 ) ;
}
static int F_112 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_242 ;
return 0 ;
}
static int F_113 ( struct V_47 * V_48 ,
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
if ( ! V_8 -> V_220 )
F_110 ( V_4 ) ;
return 1 ;
}
static void F_114 ( struct V_3 * V_4 )
{
const struct V_63 V_221 [] = {
{ 0x17 , V_103 , V_150 } ,
{ 0x17 , V_180 , 3 } ,
{}
} ;
F_32 ( V_4 , V_221 ) ;
F_98 ( V_4 ) ;
}
static void F_115 ( struct V_3 * V_4 )
{
F_110 ( V_4 ) ;
F_99 ( V_4 ) ;
}
static int F_116 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_220 ;
return 0 ;
}
static int F_117 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_220 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_220 == V_8 -> V_220 )
return 0 ;
V_8 -> V_220 = V_220 ;
if ( V_220 )
F_114 ( V_4 ) ;
else
F_115 ( V_4 ) ;
return 1 ;
}
static int F_118 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_215 , V_50 ) ;
}
static int F_119 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_217 ;
return 0 ;
}
static int F_120 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_244 * V_245 = & V_241 ;
unsigned int V_246 ;
V_246 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_246 >= V_245 -> V_247 )
V_246 = V_245 -> V_247 - 1 ;
V_8 -> V_217 = V_246 ;
if ( V_8 -> V_220 )
F_97 ( V_4 ) ;
return 1 ;
}
static void F_121 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_219 = 1 ;
F_98 ( V_4 ) ;
}
static void F_122 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_63 V_248 [] = {
{ 0x1a , V_175 , 0 } ,
{ 0x1b , V_175 , 0 } ,
{ 0x1e , V_175 , 0 } ,
{} ,
} ;
F_32 ( V_4 , V_248 ) ;
V_8 -> V_219 = 0 ;
}
static void F_123 ( struct V_3 * V_4 ,
const T_2 * V_249 ,
int V_250 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_2 * V_251 = & V_8 -> V_9 . V_40 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_250 ; V_61 ++ , V_249 ++ ) {
unsigned int V_252 = F_124 ( V_4 , * V_249 ) ;
if ( F_125 ( V_252 ) == V_253 )
continue;
if ( F_126 ( V_4 , * V_249 , V_251 , 1 ) != 1 )
continue;
if ( V_8 -> V_46 [ 0 ] )
V_251 ++ ;
else
V_251 = V_8 -> V_46 ;
}
}
static int F_127 ( struct V_3 * V_4 )
{
F_93 ( L_12 ) ;
F_31 ( V_4 ) ;
if ( V_4 -> V_123 . V_126 ) {
F_106 ( V_4 ) ;
F_107 ( V_4 ) ;
}
F_110 ( V_4 ) ;
return 0 ;
}
static int F_128 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_93 ( L_12 ) ;
F_31 ( V_4 ) ;
F_106 ( V_4 ) ;
if ( ! V_8 -> V_220 ) {
F_110 ( V_4 ) ;
F_99 ( V_4 ) ;
} else {
F_114 ( V_4 ) ;
}
return 0 ;
}
static int F_129 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_107 ;
V_107 = F_67 ( V_4 , V_254 ,
V_255 , V_256 ) ;
#if 0
if (board_config < 0)
board_config = CXT5066_AUTO;
#endif
if ( V_107 == V_257 )
return F_68 ( V_4 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_123 = V_124 ;
V_4 -> V_123 . V_128 = F_31 ;
V_8 -> V_213 = 0 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_98 = F_70 ( V_258 ) ;
V_8 -> V_9 . V_32 = V_258 ;
F_123 ( V_4 , V_259 ,
F_70 ( V_259 ) ) ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_260 ;
V_8 -> V_60 = V_261 ;
V_8 -> V_51 = & V_262 ;
V_8 -> V_212 = V_174 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_263 ;
V_8 -> V_96 = F_70 ( V_264 ) ;
V_8 -> V_95 = V_264 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_71 ( V_8 , 0x13 , 0 , V_79 ) ;
switch ( V_107 ) {
default:
case V_265 :
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_266 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_267 ;
break;
case V_268 :
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_266 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_267 ;
V_8 -> V_212 = V_176 ;
V_8 -> V_65 [ V_8 -> V_62 ] = V_269 ;
V_8 -> V_62 ++ ;
V_8 -> V_213 = 1 ;
break;
case V_270 :
case V_271 :
V_4 -> V_123 . V_128 = F_127 ;
V_4 -> V_123 . V_126 = F_109 ;
V_8 -> V_65 [ V_8 -> V_62 ] =
V_272 ;
V_8 -> V_62 ++ ;
V_8 -> V_236 = V_107 == V_271 ;
V_8 -> V_237 = V_107 == V_270 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_266 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_267 ;
if ( V_107 == V_271 )
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_212 = 0 ;
V_8 -> V_242 = 3 ;
break;
case V_273 :
V_4 -> V_123 . V_128 = F_128 ;
V_4 -> V_123 . V_126 = F_108 ;
V_8 -> V_65 [ 0 ] = V_274 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_275 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_276 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_267 ;
V_8 -> V_212 = 0 ;
V_8 -> V_242 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_12 = F_121 ;
V_8 -> V_15 = F_122 ;
break;
case V_277 :
V_4 -> V_123 . V_128 = F_127 ;
V_4 -> V_123 . V_126 = F_109 ;
V_8 -> V_65 [ 0 ] = V_278 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_275 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_267 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_279 ;
V_8 -> V_212 = 0 ;
V_8 -> V_235 = 1 ;
V_8 -> V_242 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_280 :
V_4 -> V_123 . V_128 = F_127 ;
V_4 -> V_123 . V_126 = F_109 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_266 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_267 ;
V_8 -> V_65 [ 0 ] = V_281 ;
V_8 -> V_212 = 0 ;
V_8 -> V_177 = 1 ;
V_8 -> V_242 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_282 :
V_4 -> V_123 . V_128 = F_127 ;
V_4 -> V_123 . V_126 = F_109 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_266 ;
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_267 ;
V_8 -> V_65 [ 0 ] = V_283 ;
V_8 -> V_214 = 1 ;
V_8 -> V_212 = V_176 ;
V_8 -> V_242 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
}
if ( V_8 -> V_83 )
F_74 ( V_4 , V_8 -> V_83 ) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_2 V_284 = V_8 -> V_285 [ V_8 -> V_59 [ 0 ] ] . V_284 ;
if ( V_8 -> V_286 ) {
V_8 -> V_16 = V_284 ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_11 ;
}
F_14 ( V_4 , V_284 , V_10 , 0 , V_11 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_16 ( V_4 , V_8 -> V_16 ) ;
V_8 -> V_16 = 0 ;
return 0 ;
}
static int F_132 ( struct V_3 * V_4 , T_2 V_287 ,
T_2 V_31 )
{
T_2 V_288 [ V_289 ] ;
int V_61 , V_290 ;
V_290 = F_126 ( V_4 , V_287 , V_288 , F_70 ( V_288 ) ) ;
for ( V_61 = 0 ; V_61 < V_290 ; V_61 ++ )
if ( V_288 [ V_61 ] == V_31 )
return V_61 ;
return - 1 ;
}
static T_2 F_133 ( struct V_3 * V_4 , T_2 V_291 ,
T_2 * V_292 , int * V_98 )
{
int V_61 , V_290 = * V_98 ;
T_2 V_293 = 0 ;
for ( V_61 = 0 ; V_61 < V_290 ; V_61 ++ ) {
if ( F_132 ( V_4 , V_291 , V_292 [ V_61 ] ) >= 0 ) {
V_293 = V_292 [ V_61 ] ;
break;
}
}
if ( ! V_293 )
return 0 ;
if ( -- V_290 > 0 )
memmove ( V_292 , V_292 + 1 , V_290 * sizeof( T_2 ) ) ;
* V_98 = V_290 ;
return V_293 ;
}
static int F_134 ( struct V_3 * V_4 , T_2 * V_292 )
{
T_2 V_31 , V_294 ;
int V_290 = 0 ;
V_294 = V_4 -> V_295 + V_4 -> V_296 ;
for ( V_31 = V_4 -> V_295 ; V_31 < V_294 ; V_31 ++ ) {
unsigned int V_297 = F_135 ( V_4 , V_31 ) ;
unsigned int type = F_136 ( V_297 ) ;
if ( type == V_298 && ! ( V_297 & V_299 ) ) {
V_292 [ V_290 ++ ] = V_31 ;
if ( V_290 >= V_300 )
break;
}
}
return V_290 ;
}
static int F_137 ( struct V_3 * V_4 , T_2 * V_301 ,
int V_250 , T_2 * V_292 , int * V_302 ,
struct V_303 * V_304 , int type )
{
int V_61 , V_290 ;
V_290 = 0 ;
for ( V_61 = 0 ; V_61 < V_250 ; V_61 ++ ) {
V_304 [ V_290 ] . V_291 = V_301 [ V_61 ] ;
V_304 [ V_290 ] . type = type ;
V_304 [ V_290 ] . V_305 = F_133 ( V_4 , V_301 [ V_61 ] , V_292 , V_302 ) ;
V_290 ++ ;
}
return V_290 ;
}
static void F_138 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_252 = & V_8 -> V_307 ;
T_2 V_292 [ V_300 ] ;
int V_61 , V_308 , V_290 , V_302 ;
V_302 = F_134 ( V_4 , V_292 ) ;
V_290 = F_137 ( V_4 , V_252 -> V_309 , V_252 -> V_310 ,
V_292 , & V_302 , V_8 -> V_311 ,
V_312 ) ;
V_290 += F_137 ( V_4 , V_252 -> V_313 , V_252 -> V_314 ,
V_292 , & V_302 , V_8 -> V_311 + V_290 ,
V_315 ) ;
V_290 += F_137 ( V_4 , V_252 -> V_316 , V_252 -> V_317 ,
V_292 , & V_302 , V_8 -> V_311 + V_290 ,
V_318 ) ;
V_8 -> V_319 = V_290 ;
for ( V_61 = 0 ; V_61 < V_290 ; V_61 ++ ) {
T_2 V_305 = V_8 -> V_311 [ V_61 ] . V_305 ;
if ( ! V_305 )
continue;
switch ( V_8 -> V_311 [ V_61 ] . type ) {
case V_312 :
V_8 -> V_320 [ V_8 -> V_9 . V_98 ] = V_305 ;
V_8 -> V_9 . V_98 ++ ;
break;
case V_315 :
case V_318 :
if ( ! V_8 -> V_9 . V_321 ) {
V_8 -> V_9 . V_321 = V_305 ;
break;
}
for ( V_308 = 0 ; V_308 < F_70 ( V_8 -> V_9 . V_322 ) ; V_308 ++ )
if ( ! V_8 -> V_9 . V_322 [ V_308 ] ) {
V_8 -> V_9 . V_322 [ V_308 ] = V_305 ;
break;
}
break;
}
}
V_8 -> V_9 . V_32 = V_8 -> V_320 ;
V_8 -> V_9 . V_30 = V_8 -> V_9 . V_98 * 2 ;
for ( V_61 = 0 ; V_61 < V_252 -> V_314 ; V_61 ++ ) {
if ( F_139 ( V_4 , V_252 -> V_313 [ V_61 ] ) ) {
V_8 -> V_323 = 1 ;
break;
}
}
if ( V_8 -> V_323 &&
V_252 -> V_309 [ 0 ] &&
V_252 -> V_324 != V_318 &&
V_252 -> V_309 [ 0 ] != V_252 -> V_313 [ 0 ] &&
V_252 -> V_309 [ 0 ] != V_252 -> V_316 [ 0 ] ) {
for ( V_61 = 0 ; V_61 < V_252 -> V_310 ; V_61 ++ ) {
if ( F_139 ( V_4 , V_252 -> V_309 [ V_61 ] ) ) {
V_8 -> V_325 = 1 ;
break;
}
}
V_8 -> V_326 = V_8 -> V_325 ;
}
V_8 -> V_77 = V_8 -> V_320 [ 0 ] ;
}
static void F_140 ( struct V_3 * V_4 , int V_250 ,
T_2 * V_301 , bool V_327 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_250 ; V_61 ++ )
F_82 ( V_4 , V_301 [ V_61 ] , 0 ,
V_175 ,
V_327 ? V_176 : 0 ) ;
F_141 ( V_4 , V_250 , V_301 , V_327 ) ;
}
static int F_142 ( struct V_3 * V_4 , int V_250 , T_2 * V_301 )
{
int V_61 , V_105 = 0 ;
for ( V_61 = 0 ; V_61 < V_250 ; V_61 ++ ) {
T_2 V_31 = V_301 [ V_61 ] ;
if ( ! V_31 || ! F_139 ( V_4 , V_31 ) )
break;
F_30 ( V_4 , V_31 ) ;
V_105 |= F_62 ( V_4 , V_31 ) ;
}
return V_105 ;
}
static void F_143 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_252 = & V_8 -> V_307 ;
int V_327 = 1 ;
if ( V_8 -> V_323 )
V_327 = V_8 -> V_100 ;
F_141 ( V_4 , V_252 -> V_314 , V_252 -> V_313 , V_327 ) ;
if ( V_8 -> V_323 )
V_327 = ! ( V_8 -> V_100 ||
( V_8 -> V_325 && V_8 -> V_328 ) ) ;
F_140 ( V_4 , V_252 -> V_317 , V_252 -> V_316 , V_327 ) ;
if ( V_252 -> V_309 [ 0 ] == V_252 -> V_313 [ 0 ] ||
V_252 -> V_309 [ 0 ] == V_252 -> V_316 [ 0 ] )
return;
if ( V_8 -> V_323 ) {
if ( V_252 -> V_324 == V_318 ||
V_8 -> V_326 )
V_327 = ! V_8 -> V_100 ;
else
V_327 = 1 ;
}
F_140 ( V_4 , V_252 -> V_310 , V_252 -> V_309 , V_327 ) ;
}
static void F_144 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_252 = & V_8 -> V_307 ;
if ( ! V_8 -> V_323 )
return;
V_8 -> V_100 = F_142 ( V_4 , V_252 -> V_314 , V_252 -> V_313 ) ;
F_143 ( V_4 ) ;
}
static void F_145 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_252 = & V_8 -> V_307 ;
if ( ! V_8 -> V_323 || ! V_8 -> V_325 )
return;
V_8 -> V_328 = F_142 ( V_4 , V_252 -> V_310 ,
V_252 -> V_309 ) ;
F_143 ( V_4 ) ;
}
static int F_146 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
static const char * const V_329 [] = {
L_13 , L_14
} ;
static const char * const V_330 [] = {
L_13 , L_15 , L_16
} ;
const char * const * V_331 ;
V_50 -> type = V_332 ;
V_50 -> V_333 = 1 ;
if ( V_8 -> V_334 ) {
V_50 -> V_56 . V_57 . V_216 = 3 ;
V_331 = V_330 ;
} else {
V_50 -> V_56 . V_57 . V_216 = 2 ;
V_331 = V_329 ;
}
if ( V_50 -> V_56 . V_57 . V_58 >= V_50 -> V_56 . V_57 . V_216 )
V_50 -> V_56 . V_57 . V_58 = V_50 -> V_56 . V_57 . V_216 - 1 ;
strcpy ( V_50 -> V_56 . V_57 . V_25 ,
V_331 [ V_50 -> V_56 . V_57 . V_58 ] ) ;
return 0 ;
}
static int F_147 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_335 ;
if ( ! V_8 -> V_323 )
V_335 = 0 ;
else if ( ! V_8 -> V_326 )
V_335 = 1 ;
else
V_335 = 2 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_335 ;
return 0 ;
}
static int F_148 ( struct V_47 * V_48 ,
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
if ( ! V_8 -> V_334 )
return - V_336 ;
if ( V_8 -> V_323 && V_8 -> V_326 )
return 0 ;
V_8 -> V_323 = 1 ;
V_8 -> V_326 = 1 ;
break;
default:
return - V_336 ;
}
F_143 ( V_4 ) ;
return 1 ;
}
static int F_149 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_22 ( & V_8 -> V_337 , V_50 ) ;
}
static int F_150 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_59 [ 0 ] ;
return 0 ;
}
static int F_151 ( struct V_3 * V_4 , T_2 V_287 ,
T_2 V_291 , T_2 * V_338 ,
bool V_339 , int V_340 )
{
T_2 V_288 [ V_289 ] ;
int V_61 , V_290 ;
switch ( F_136 ( F_135 ( V_4 , V_287 ) ) ) {
case V_341 :
case V_342 :
case V_343 :
break;
default:
return - 1 ;
}
V_290 = F_126 ( V_4 , V_287 , V_288 , F_70 ( V_288 ) ) ;
for ( V_61 = 0 ; V_61 < V_290 ; V_61 ++ )
if ( V_288 [ V_61 ] == V_291 ) {
if ( V_339 )
F_82 ( V_4 , V_287 , 0 ,
V_180 , V_61 ) ;
if ( V_338 )
* V_338 = V_287 ;
return V_61 ;
}
V_340 ++ ;
if ( V_340 == 2 )
return - 1 ;
for ( V_61 = 0 ; V_61 < V_290 ; V_61 ++ ) {
int V_293 = F_151 ( V_4 , V_288 [ V_61 ] , V_291 , V_338 ,
V_339 , V_340 ) ;
if ( V_293 >= 0 ) {
if ( V_339 )
F_82 ( V_4 , V_287 , 0 ,
V_180 , V_61 ) ;
return V_61 ;
}
}
return - 1 ;
}
static void F_152 ( struct V_3 * V_4 , T_2 V_287 ,
T_2 V_291 )
{
F_151 ( V_4 , V_287 , V_291 , NULL , true , 0 ) ;
}
static int F_153 ( struct V_3 * V_4 , T_2 V_287 ,
T_2 V_291 )
{
return F_151 ( V_4 , V_287 , V_291 , NULL , false , 0 ) ;
}
static int F_154 ( struct V_3 * V_4 ,
const struct V_244 * V_245 ,
unsigned int V_246 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_2 V_284 ;
int V_344 = 1 ;
if ( ! V_245 -> V_247 )
return 0 ;
if ( V_246 >= V_245 -> V_247 )
V_246 = V_245 -> V_247 - 1 ;
if ( V_8 -> V_59 [ 0 ] == V_246 )
V_344 = 0 ;
V_284 = V_8 -> V_285 [ V_246 ] . V_284 ;
F_152 ( V_4 , V_8 -> V_285 [ V_246 ] . V_284 ,
V_8 -> V_285 [ V_246 ] . V_291 ) ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_284 ) {
F_86 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_284 ;
F_14 ( V_4 , V_284 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
V_8 -> V_59 [ 0 ] = V_246 ;
return V_344 ;
}
static int F_155 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_154 ( V_4 , & V_8 -> V_337 ,
V_53 -> V_56 . V_57 . V_58 [ 0 ] ) ;
}
static bool F_156 ( struct V_3 * V_4 , int V_246 , bool V_345 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_246 < 0 )
return false ;
if ( V_345 && ! F_62 ( V_4 , V_8 -> V_285 [ V_246 ] . V_291 ) )
return false ;
F_154 ( V_4 , & V_8 -> V_337 , V_246 ) ;
return true ;
}
static void F_157 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_178 )
return;
if ( ! F_156 ( V_4 , V_8 -> V_346 , true ) )
if ( ! F_156 ( V_4 , V_8 -> V_347 , true ) )
F_156 ( V_4 , V_8 -> V_348 , false ) ;
}
static void F_158 ( struct V_3 * V_4 , unsigned int V_106 )
{
int V_31 = ( V_106 & V_183 ) >> 20 ;
switch ( V_106 >> 26 ) {
case V_69 :
F_144 ( V_4 ) ;
break;
case V_349 :
F_145 ( V_4 ) ;
break;
case V_72 :
F_157 ( V_4 ) ;
F_30 ( V_4 , V_31 ) ;
break;
}
}
static void F_159 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_350 [ V_351 + 1 ] ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_70 ( V_350 ) ; V_61 ++ )
V_350 [ V_61 ] = - 1 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_337 . V_247 ; V_61 ++ ) {
T_2 V_291 = V_8 -> V_285 [ V_61 ] . V_291 ;
unsigned int V_352 = F_124 ( V_4 , V_291 ) ;
int type , V_353 ;
V_353 = F_160 ( V_352 ) ;
if ( V_353 == V_354 )
return;
if ( V_353 > V_351 )
V_353 = V_351 ;
if ( V_353 != V_355 &&
! F_139 ( V_4 , V_291 ) )
return;
type = F_161 ( V_352 ) ;
if ( type != V_356 &&
( V_353 != V_357 || type != V_358 ) )
return;
if ( V_350 [ V_353 ] >= 0 )
return;
V_350 [ V_353 ] = V_61 ;
}
if ( V_350 [ V_355 ] < 0 ||
( V_350 [ V_351 ] < 0 && V_350 [ V_357 ] ) )
return;
V_8 -> V_178 = 1 ;
V_8 -> V_346 = V_350 [ V_351 ] ;
V_8 -> V_347 = V_350 [ V_357 ] ;
V_8 -> V_348 = V_350 [ V_355 ] ;
}
static void F_162 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_252 = & V_8 -> V_307 ;
struct V_244 * V_245 ;
int V_61 , V_308 ;
V_245 = & V_8 -> V_337 ;
for ( V_61 = 0 ; V_61 < V_252 -> V_359 ; V_61 ++ ) {
for ( V_308 = 0 ; V_308 < V_8 -> V_39 ; V_308 ++ ) {
T_2 V_284 = V_8 -> V_13 [ V_308 ] ;
int V_246 = F_153 ( V_4 , V_284 ,
V_252 -> V_360 [ V_61 ] . V_291 ) ;
if ( V_246 >= 0 ) {
const char * V_361 ;
V_361 = F_163 ( V_4 , V_252 , V_61 ) ;
V_8 -> V_285 [ V_245 -> V_247 ] . V_218 = V_61 ;
V_8 -> V_285 [ V_245 -> V_247 ] . V_362 = 0 ;
V_8 -> V_285 [ V_245 -> V_247 ] . V_284 = V_284 ;
V_8 -> V_285 [ V_245 -> V_247 ] . V_291 =
V_252 -> V_360 [ V_61 ] . V_291 ;
F_164 ( V_245 , V_361 , V_246 , NULL ) ;
break;
}
}
}
if ( V_245 -> V_247 >= 2 && V_252 -> V_359 == V_245 -> V_247 )
F_159 ( V_4 ) ;
if ( V_245 -> V_247 > 1 && ! V_8 -> V_178 ) {
for ( V_61 = 1 ; V_61 < V_245 -> V_247 ; V_61 ++ ) {
if ( V_8 -> V_285 [ V_61 ] . V_284 != V_8 -> V_285 [ 0 ] . V_284 ) {
V_8 -> V_286 = 1 ;
break;
}
}
}
}
static T_2 F_165 ( struct V_3 * V_4 , T_2 V_291 )
{
T_2 V_31 , V_294 ;
V_294 = V_4 -> V_295 + V_4 -> V_296 ;
for ( V_31 = V_4 -> V_295 ; V_31 < V_294 ; V_31 ++ ) {
unsigned int V_297 = F_135 ( V_4 , V_31 ) ;
unsigned int type = F_136 ( V_297 ) ;
if ( type == V_341 && ( V_297 & V_299 ) ) {
if ( F_132 ( V_4 , V_31 , V_291 ) >= 0 )
return V_31 ;
}
}
return 0 ;
}
static void F_166 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_252 = & V_8 -> V_307 ;
T_2 V_31 ;
if ( V_252 -> V_363 &&
F_126 ( V_4 , V_252 -> V_364 [ 0 ] , & V_31 , 1 ) == 1 )
V_8 -> V_9 . V_40 = V_31 ;
if ( V_252 -> V_365 )
V_8 -> V_44 = F_165 ( V_4 , V_252 -> V_365 ) ;
}
static void F_167 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_2 V_31 , V_294 ;
V_294 = V_4 -> V_295 + V_4 -> V_296 ;
for ( V_31 = V_4 -> V_295 ; V_31 < V_294 ; V_31 ++ )
if ( F_136 ( F_135 ( V_4 , V_31 ) ) == V_366 ) {
F_71 ( V_8 , V_31 , 0 , V_79 ) ;
break;
}
}
static int F_168 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
V_66 = F_169 ( V_4 , & V_8 -> V_307 , NULL ) ;
if ( V_66 < 0 )
return V_66 ;
F_138 ( V_4 ) ;
F_162 ( V_4 ) ;
F_166 ( V_4 ) ;
F_167 ( V_4 ) ;
return 0 ;
}
static void F_141 ( struct V_3 * V_4 , int V_250 ,
T_2 * V_301 , bool V_327 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_250 ; V_61 ++ ) {
if ( F_170 ( V_4 , V_301 [ V_61 ] ) & V_367 )
F_82 ( V_4 , V_301 [ V_61 ] , 0 ,
V_94 ,
V_327 ? 0x02 : 0 ) ;
}
}
static void F_171 ( struct V_3 * V_4 , T_2 V_291 ,
T_2 V_368 )
{
int V_246 = F_132 ( V_4 , V_291 , V_368 ) ;
if ( V_246 >= 0 )
F_82 ( V_4 , V_291 , 0 ,
V_180 , V_246 ) ;
}
static void F_172 ( struct V_3 * V_4 , int V_369 ,
const T_2 * V_370 )
{
int V_61 , V_335 ;
for ( V_61 = 0 ; V_61 < V_369 ; V_61 ++ ) {
T_2 V_31 = V_370 [ V_61 ] ;
if ( ! ( F_135 ( V_4 , V_31 ) & V_371 ) )
continue;
if ( F_173 ( V_4 , V_31 , V_79 ) & V_372 )
V_335 = V_149 ;
else
V_335 = V_373 ;
F_82 ( V_4 , V_31 , 0 ,
V_103 , V_335 ) ;
}
}
static void F_174 ( struct V_3 * V_4 , int V_250 ,
T_2 * V_301 , unsigned int V_374 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_250 ; V_61 ++ )
F_82 ( V_4 , V_301 [ V_61 ] , 0 ,
V_186 ,
V_68 | V_374 ) ;
}
static void F_175 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_252 = & V_8 -> V_307 ;
T_2 V_31 ;
int V_61 ;
F_172 ( V_4 , V_8 -> V_9 . V_98 , V_8 -> V_9 . V_32 ) ;
for ( V_61 = 0 ; V_61 < V_252 -> V_314 ; V_61 ++ )
F_82 ( V_4 , V_252 -> V_313 [ V_61 ] , 0 ,
V_175 , V_174 ) ;
F_172 ( V_4 , V_252 -> V_314 , V_252 -> V_313 ) ;
F_172 ( V_4 , V_252 -> V_310 , V_252 -> V_309 ) ;
F_172 ( V_4 , V_252 -> V_317 , V_252 -> V_316 ) ;
for ( V_61 = 0 ; V_61 < V_8 -> V_319 ; V_61 ++ ) {
V_31 = V_8 -> V_311 [ V_61 ] . V_305 ;
if ( ! V_31 )
V_31 = V_8 -> V_9 . V_32 [ 0 ] ;
F_171 ( V_4 , V_8 -> V_311 [ V_61 ] . V_291 , V_31 ) ;
}
if ( V_8 -> V_323 ) {
F_174 ( V_4 , V_252 -> V_314 , V_252 -> V_313 ,
V_69 ) ;
V_8 -> V_100 = F_142 ( V_4 , V_252 -> V_314 ,
V_252 -> V_313 ) ;
if ( V_8 -> V_325 ) {
F_174 ( V_4 , V_252 -> V_310 ,
V_252 -> V_309 ,
V_349 ) ;
V_8 -> V_328 =
F_142 ( V_4 , V_252 -> V_310 ,
V_252 -> V_309 ) ;
}
}
F_143 ( V_4 ) ;
}
static void F_176 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_252 = & V_8 -> V_307 ;
int V_61 , V_335 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_39 ; V_61 ++ ) {
T_2 V_31 = V_8 -> V_13 [ V_61 ] ;
if ( ! ( F_135 ( V_4 , V_31 ) & V_375 ) )
continue;
if ( F_173 ( V_4 , V_31 , V_144 ) & V_372 )
V_335 = F_177 ( 0 ) ;
else
V_335 = F_178 ( 0 ) ;
F_82 ( V_4 , V_31 , 0 , V_103 ,
V_335 ) ;
}
for ( V_61 = 0 ; V_61 < V_252 -> V_359 ; V_61 ++ ) {
unsigned int type ;
if ( V_252 -> V_360 [ V_61 ] . type == V_376 )
type = V_225 ;
else
type = V_222 ;
F_82 ( V_4 , V_252 -> V_360 [ V_61 ] . V_291 , 0 ,
V_175 , type ) ;
}
if ( V_8 -> V_178 ) {
if ( V_8 -> V_346 >= 0 ) {
F_82 ( V_4 ,
V_252 -> V_360 [ V_8 -> V_346 ] . V_291 , 0 ,
V_186 ,
V_68 | V_72 ) ;
}
if ( V_8 -> V_347 >= 0 ) {
F_82 ( V_4 ,
V_252 -> V_360 [ V_8 -> V_347 ] . V_291 , 0 ,
V_186 ,
V_68 | V_72 ) ;
}
F_157 ( V_4 ) ;
} else {
F_152 ( V_4 , V_8 -> V_285 [ 0 ] . V_284 ,
V_8 -> V_285 [ 0 ] . V_291 ) ;
}
}
static void F_179 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_306 * V_252 = & V_8 -> V_307 ;
if ( V_8 -> V_9 . V_40 )
F_82 ( V_4 , V_252 -> V_364 [ 0 ] , 0 ,
V_175 , V_176 ) ;
if ( V_8 -> V_44 )
F_82 ( V_4 , V_252 -> V_365 , 0 ,
V_175 , V_222 ) ;
}
static int F_180 ( struct V_3 * V_4 )
{
F_175 ( V_4 ) ;
F_176 ( V_4 ) ;
F_179 ( V_4 ) ;
return 0 ;
}
static int F_181 ( struct V_3 * V_4 , const char * V_377 ,
const char * V_378 , int V_379 ,
T_2 V_31 , int V_380 , int V_381 )
{
static char V_25 [ 32 ] ;
static struct V_84 V_85 [] = {
F_182 ( V_25 , 0 , 0 , 0 ) ,
F_183 ( V_25 , 0 , 0 , 0 ) ,
} ;
static const char * const V_382 [ 2 ] = { L_17 , L_18 } ;
int V_61 , V_66 ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
struct V_47 * V_87 ;
V_85 [ V_61 ] . V_89 = F_184 ( V_31 , 3 , V_381 ,
V_380 ) ;
V_85 [ V_61 ] . V_383 = V_384 ;
V_85 [ V_61 ] . V_218 = V_379 ;
snprintf ( V_25 , sizeof( V_25 ) , L_19 , V_377 , V_378 , V_382 [ V_61 ] ) ;
V_87 = F_46 ( & V_85 [ V_61 ] , V_4 ) ;
if ( ! V_87 )
return - V_88 ;
V_66 = F_47 ( V_4 , V_31 , V_87 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( ! ( F_173 ( V_4 , V_31 , V_380 ) & V_372 ) )
break;
}
return 0 ;
}
static int F_185 ( struct V_3 * V_4 , T_2 V_305 ,
T_2 V_291 , const char * V_25 , int V_246 )
{
unsigned int V_385 ;
V_385 = F_173 ( V_4 , V_305 , V_79 ) ;
if ( V_385 & V_386 )
return F_186 ( V_4 , V_305 , V_25 , V_246 ) ;
V_385 = F_173 ( V_4 , V_291 , V_79 ) ;
if ( V_385 & V_386 )
return F_186 ( V_4 , V_291 , V_25 , V_246 ) ;
return 0 ;
}
static int F_187 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 , V_66 ;
int V_387 = 0 , V_388 = 0 , V_389 = 0 ;
static const char * const V_331 [ 3 ] = { L_20 , L_21 , L_22 } ;
if ( V_8 -> V_319 == 1 )
return F_185 ( V_4 , V_8 -> V_311 [ 0 ] . V_305 ,
V_8 -> V_311 [ 0 ] . V_291 ,
L_23 , 0 ) ;
for ( V_61 = 0 ; V_61 < V_8 -> V_319 ; V_61 ++ ) {
const char * V_361 ;
int V_246 , type ;
if ( ! V_8 -> V_311 [ V_61 ] . V_305 )
continue;
type = V_8 -> V_311 [ V_61 ] . type ;
if ( type == V_312 )
type = V_8 -> V_307 . V_324 ;
switch ( type ) {
case V_312 :
default:
V_361 = V_331 [ V_387 ++ ] ;
V_246 = 0 ;
break;
case V_315 :
V_361 = L_24 ;
V_246 = V_388 ++ ;
break;
case V_318 :
V_361 = L_25 ;
V_246 = V_389 ++ ;
break;
}
V_66 = F_185 ( V_4 , V_8 -> V_311 [ V_61 ] . V_305 ,
V_8 -> V_311 [ V_61 ] . V_291 ,
V_361 , V_246 ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_323 ) {
V_66 = F_38 ( V_4 , V_390 ) ;
if ( V_66 < 0 )
return V_66 ;
}
return 0 ;
}
static int F_188 ( struct V_3 * V_4 , T_2 V_31 ,
const char * V_361 , const char * V_391 ,
int V_379 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_39 ; V_61 ++ ) {
T_2 V_392 = V_8 -> V_13 [ V_61 ] ;
int V_246 = F_153 ( V_4 , V_392 , V_31 ) ;
if ( V_246 < 0 )
continue;
return F_181 ( V_4 , V_361 , V_391 ,
V_379 , V_392 , V_144 , V_246 ) ;
}
return 0 ;
}
static int F_189 ( struct V_3 * V_4 , int V_246 ,
const char * V_361 , int V_379 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_2 V_287 , V_31 ;
int V_61 , V_393 ;
V_31 = V_8 -> V_285 [ V_246 ] . V_291 ;
if ( F_135 ( V_4 , V_31 ) & V_375 )
return F_190 ( V_4 , V_361 , L_26 , V_379 ,
V_31 , V_144 ) ;
V_393 = F_151 ( V_4 , V_8 -> V_285 [ V_246 ] . V_284 , V_31 ,
& V_287 , false , 0 ) ;
if ( V_393 < 0 )
return 0 ;
for ( V_61 = 0 ; V_61 < V_246 ; V_61 ++ ) {
if ( V_8 -> V_285 [ V_61 ] . V_362 == V_287 )
return 0 ;
}
if ( F_135 ( V_4 , V_287 ) & V_371 ) {
V_8 -> V_285 [ V_246 ] . V_362 = V_287 ;
return F_190 ( V_4 , V_361 , L_26 , 0 ,
V_287 , V_79 ) ;
}
return 0 ;
}
static int F_191 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_244 * V_245 = & V_8 -> V_337 ;
const char * V_394 ;
int V_395 [ V_289 ] ;
int V_61 , V_66 , V_379 ;
int V_396 ;
V_396 = 0 ;
for ( V_61 = 0 ; V_61 < V_245 -> V_247 ; V_61 ++ ) {
V_379 = F_153 ( V_4 , V_8 -> V_285 [ V_61 ] . V_284 ,
V_8 -> V_285 [ V_61 ] . V_291 ) ;
V_395 [ V_61 ] = ( V_8 -> V_285 [ V_61 ] . V_284 << 8 ) | V_379 ;
if ( V_61 > 0 && V_395 [ V_61 ] != V_395 [ 0 ] )
V_396 = 1 ;
}
V_394 = NULL ;
V_379 = 0 ;
for ( V_61 = 0 ; V_61 < V_245 -> V_247 ; V_61 ++ ) {
T_2 V_31 = V_8 -> V_285 [ V_61 ] . V_291 ;
const char * V_361 ;
V_361 = F_163 ( V_4 , & V_8 -> V_307 ,
V_8 -> V_285 [ V_61 ] . V_218 ) ;
if ( V_361 == V_394 )
V_379 ++ ;
else
V_379 = 0 ;
V_394 = V_361 ;
V_66 = F_189 ( V_4 , V_61 , V_361 , V_379 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( ! V_396 ) {
if ( V_61 > 0 )
continue;
V_66 = F_188 ( V_4 , V_31 ,
L_27 , L_28 , V_379 ) ;
} else {
V_66 = F_188 ( V_4 , V_31 ,
V_361 , L_29 , V_379 ) ;
}
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_337 . V_247 > 1 && ! V_8 -> V_178 ) {
V_66 = F_38 ( V_4 , V_397 ) ;
if ( V_66 < 0 )
return V_66 ;
}
return 0 ;
}
static int F_192 ( struct V_3 * V_4 )
{
int V_66 ;
V_66 = F_187 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_191 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
return F_37 ( V_4 ) ;
}
static int F_193 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_2 V_31 , V_294 ;
V_294 = V_4 -> V_295 + V_4 -> V_296 ;
for ( V_31 = V_4 -> V_295 ; V_31 < V_294 ; V_31 ++ ) {
unsigned int V_385 = F_135 ( V_4 , V_31 ) ;
if ( F_136 ( V_385 ) != V_341 )
continue;
if ( V_385 & V_299 )
continue;
if ( F_194 ( V_8 -> V_39 >=
F_70 ( V_8 -> V_398 ) ) )
break;
V_8 -> V_398 [ V_8 -> V_39 ++ ] = V_31 ;
}
V_8 -> V_13 = V_8 -> V_398 ;
return 0 ;
}
static int F_68 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_66 ;
F_195 ( V_399 L_30 ,
V_4 -> V_400 ) ;
V_8 = F_69 ( sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_88 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_113 = 1 ;
V_66 = F_193 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_168 ( V_4 ) ;
if ( V_66 < 0 ) {
F_36 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
return V_66 ;
}
V_8 -> V_33 = & V_401 ;
V_4 -> V_123 = V_402 ;
if ( V_8 -> V_83 )
F_74 ( V_4 , V_8 -> V_83 ) ;
return 0 ;
}
static int T_3 F_196 ( void )
{
return F_197 ( & V_403 ) ;
}
static void T_4 F_198 ( void )
{
F_199 ( & V_403 ) ;
}
