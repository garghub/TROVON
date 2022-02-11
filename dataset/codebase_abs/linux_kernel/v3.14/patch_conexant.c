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
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_10 ) ;
F_19 ( V_10 , V_2 -> V_28 [ V_23 -> V_29 ] ,
V_25 , 0 , V_26 ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( V_10 , V_2 -> V_28 [ V_23 -> V_29 ] ) ;
if ( V_2 -> V_30 )
V_2 -> V_30 ( V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
unsigned int V_25 ,
unsigned int V_26 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_31 = V_2 -> V_28 [ V_2 -> V_32 ] ;
V_2 -> V_33 = V_25 ;
V_2 -> V_34 = V_26 ;
F_19 ( V_10 , V_2 -> V_31 , V_25 , 0 , V_26 ) ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 ,
struct V_9 * V_10 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( V_10 , V_2 -> V_31 ) ;
V_2 -> V_31 = 0 ;
return 0 ;
}
static int F_24 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_2 -> V_37 ;
V_10 -> V_38 = 1 ;
V_10 -> V_39 = V_36 ;
V_36 -> V_15 = L_1 ;
V_36 -> V_40 [ V_41 ] = V_42 ;
V_36 -> V_40 [ V_41 ] . V_43 =
V_2 -> V_24 . V_44 ;
V_36 -> V_40 [ V_41 ] . V_3 =
V_2 -> V_24 . V_45 [ 0 ] ;
if ( V_2 -> V_46 )
V_36 -> V_40 [ V_47 ] = * V_2 -> V_46 ;
else {
if ( V_10 -> V_48 == 0x14f15051 )
V_36 -> V_40 [ V_47 ] =
V_49 ;
else {
V_36 -> V_40 [ V_47 ] =
V_50 ;
V_36 -> V_40 [ V_47 ] . V_51 =
V_2 -> V_52 ;
}
}
V_36 -> V_40 [ V_47 ] . V_3 = V_2 -> V_28 [ 0 ] ;
if ( V_2 -> V_24 . V_53 ) {
V_36 ++ ;
V_10 -> V_38 ++ ;
V_36 -> V_15 = L_2 ;
V_36 -> V_54 = V_55 ;
V_36 -> V_40 [ V_41 ] =
V_56 ;
V_36 -> V_40 [ V_41 ] . V_3 =
V_2 -> V_24 . V_53 ;
if ( V_2 -> V_57 ) {
V_36 -> V_40 [ V_47 ] =
V_58 ;
V_36 -> V_40 [ V_47 ] . V_3 =
V_2 -> V_57 ;
}
}
return 0 ;
}
static int F_25 ( struct V_16 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
return F_27 ( V_2 -> V_62 , V_61 ) ;
}
static int F_28 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_65 = F_29 ( V_59 , & V_64 -> V_66 ) ;
V_64 -> V_67 . V_68 . V_69 [ 0 ] = V_2 -> V_70 [ V_65 ] ;
return 0 ;
}
static int F_30 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_65 = F_29 ( V_59 , & V_64 -> V_66 ) ;
return F_31 ( V_10 , V_2 -> V_62 , V_64 ,
V_2 -> V_71 [ V_65 ] ,
& V_2 -> V_70 [ V_65 ] ) ;
}
static void F_32 ( struct V_9 * V_10 , T_1 V_72 ,
unsigned int V_73 )
{
if ( V_73 == V_74 )
F_33 ( 100 ) ;
F_34 ( V_10 , V_72 , 0 , V_75 ,
V_73 ) ;
if ( V_73 == V_76 )
F_33 ( 10 ) ;
F_35 ( V_10 , V_72 , V_73 ) ;
}
static int F_36 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_2 -> V_78 ; V_77 ++ )
F_37 ( V_10 , V_2 -> V_79 [ V_77 ] ) ;
return 0 ;
}
static void F_38 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_39 ( V_10 ) ;
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_77 ;
int V_11 ;
for ( V_77 = 0 ; V_77 < V_2 -> V_80 ; V_77 ++ ) {
V_11 = F_42 ( V_10 , V_2 -> V_81 [ V_77 ] ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_2 -> V_24 . V_53 ) {
V_11 = F_43 ( V_10 ,
V_2 -> V_24 . V_53 ,
V_2 -> V_24 . V_53 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_44 ( V_10 ,
& V_2 -> V_24 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_24 . V_82 = 1 ;
}
if ( V_2 -> V_57 ) {
V_11 = F_45 ( V_10 , V_2 -> V_57 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_2 -> V_83 &&
! F_46 ( V_10 , L_3 ) ) {
unsigned int V_84 [ 4 ] ;
F_47 ( V_10 , V_2 -> V_83 ,
V_85 , V_84 ) ;
V_11 = F_48 ( V_10 , L_3 ,
V_84 , V_86 ,
L_4 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_2 -> V_83 &&
! F_46 ( V_10 , L_5 ) ) {
V_11 = F_48 ( V_10 , L_5 ,
NULL , V_86 ,
L_6 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_2 -> V_62 ) {
V_11 = F_42 ( V_10 , V_87 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_11 = F_3 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_49 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_88 = ( V_59 -> V_19 >> 8 ) & 1 ;
if ( V_88 )
V_64 -> V_67 . integer . V_67 [ 0 ] = ! V_2 -> V_89 ;
else
V_64 -> V_67 . integer . V_67 [ 0 ] = V_2 -> V_89 ;
return 0 ;
}
static int F_50 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_88 = ( V_59 -> V_19 >> 8 ) & 1 ;
T_1 V_3 = V_59 -> V_19 & 0xff ;
unsigned int V_90 ;
V_90 = ! ! V_64 -> V_67 . integer . V_67 [ 0 ] ;
if ( V_88 )
V_90 = ! V_90 ;
if ( V_90 == V_2 -> V_89 )
return 0 ;
V_2 -> V_89 = V_90 ;
F_51 ( V_10 , V_3 ,
0 , V_91 ,
V_90 ? 0x02 : 0x00 ) ;
return 1 ;
}
static int F_52 ( struct V_16 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
return F_53 ( V_10 , V_61 , V_2 -> V_92 ,
V_2 -> V_93 ) ;
}
static int F_54 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
return F_55 ( V_10 , V_64 , V_2 -> V_92 ,
V_2 -> V_93 ,
V_2 -> V_24 . V_44 ) ;
}
static int F_56 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 = F_57 ( V_10 , V_64 , V_2 -> V_92 ,
V_2 -> V_93 ,
& V_2 -> V_24 . V_44 ) ;
return V_11 ;
}
static int F_58 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_94 ;
if ( ! F_50 ( V_59 , V_64 ) )
return 0 ;
V_94 = ( ! V_2 -> V_95 && V_2 -> V_89 ) ? 0 : V_96 ;
F_59 ( V_10 , 0x10 , V_85 , 0 ,
V_96 , V_94 ) ;
V_94 = V_2 -> V_89 ? 0 : V_96 ;
F_59 ( V_10 , 0x11 , V_85 , 0 ,
V_96 , V_94 ) ;
return 1 ;
}
static void F_60 ( struct V_9 * V_10 )
{
static const struct V_97 V_98 [] = {
{ 0x14 , V_99 , 0xb080 } ,
{ 0x12 , V_99 , 0xb000 } ,
{}
} ;
static const struct V_97 V_100 [] = {
{ 0x12 , V_99 , 0xb080 } ,
{ 0x14 , V_99 , 0xb000 } ,
{}
} ;
unsigned int V_101 ;
V_101 = F_61 ( V_10 , 0x12 ) ;
if ( V_101 )
F_37 ( V_10 , V_98 ) ;
else
F_37 ( V_10 , V_100 ) ;
}
static void F_62 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_94 ;
V_2 -> V_95 = F_61 ( V_10 , 0x11 ) ;
V_94 = ( V_2 -> V_95 || ! V_2 -> V_89 ) ? V_96 : 0 ;
F_59 ( V_10 , 0x10 , V_85 , 0 ,
V_96 , V_94 ) ;
}
static void F_63 ( struct V_9 * V_10 ,
unsigned int V_102 )
{
V_102 >>= 26 ;
switch ( V_102 ) {
case V_103 :
F_62 ( V_10 ) ;
break;
case V_104 :
F_60 ( V_10 ) ;
break;
}
}
static int F_64 ( struct V_9 * V_10 )
{
F_36 ( V_10 ) ;
F_62 ( V_10 ) ;
return 0 ;
}
static int F_65 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_105 ;
V_105 = F_66 ( V_10 , V_106 ,
V_107 ,
V_108 ) ;
if ( V_105 < 0 )
V_105 = V_109 ;
if ( V_105 == V_109 )
return F_67 ( V_10 ) ;
V_2 = F_68 ( sizeof( * V_2 ) , V_110 ) ;
if ( ! V_2 )
return - V_18 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_111 = 1 ;
V_2 -> V_24 . V_44 = 2 ;
V_2 -> V_24 . V_112 = F_69 ( V_113 ) ;
V_2 -> V_24 . V_45 = V_113 ;
V_2 -> V_24 . V_53 = V_114 ;
V_2 -> V_52 = 1 ;
V_2 -> V_28 = V_115 ;
V_2 -> V_71 = V_116 ;
V_2 -> V_62 = & V_117 ;
V_2 -> V_80 = 1 ;
V_2 -> V_81 [ 0 ] = V_118 ;
V_2 -> V_78 = 1 ;
V_2 -> V_79 [ 0 ] = V_119 ;
V_2 -> V_120 = 0 ;
V_2 -> V_93 = F_69 ( V_121 ) ;
V_2 -> V_92 = V_121 ;
F_1 ( V_2 , 0x16 , 0 , 1 ) ;
V_10 -> V_122 = V_123 ;
switch ( V_105 ) {
case V_124 :
V_10 -> V_122 . V_125 = F_63 ;
V_2 -> V_62 = & V_117 ;
V_2 -> V_78 = 2 ;
V_2 -> V_79 [ 1 ] = V_126 ;
V_2 -> V_81 [ 0 ] = V_118 ;
V_10 -> V_122 . V_127 = F_64 ;
break;
case V_128 :
V_10 -> V_122 . V_125 = F_63 ;
V_2 -> V_62 = & V_117 ;
V_2 -> V_78 = 2 ;
V_2 -> V_79 [ 1 ] = V_129 ;
V_2 -> V_81 [ 0 ] = V_118 ;
V_10 -> V_122 . V_127 = F_64 ;
break;
default:
case V_130 :
V_10 -> V_122 . V_125 = F_63 ;
V_2 -> V_62 = & V_117 ;
V_2 -> V_78 = 3 ;
V_2 -> V_79 [ 1 ] = V_126 ;
V_2 -> V_79 [ 2 ] = V_129 ;
V_2 -> V_81 [ 0 ] = V_118 ;
V_10 -> V_122 . V_127 = F_64 ;
break;
case V_131 :
V_10 -> V_122 . V_125 = F_63 ;
V_2 -> V_62 = & V_132 ;
V_2 -> V_78 = 1 ;
V_2 -> V_79 [ 0 ] = V_133 ;
V_2 -> V_81 [ 0 ] = V_118 ;
V_2 -> V_81 [ 1 ] = V_134 ;
V_2 -> V_80 = 2 ;
V_10 -> V_122 . V_127 = F_64 ;
break;
case V_135 :
V_10 -> V_122 . V_125 = F_63 ;
V_2 -> V_62 = & V_136 ;
V_2 -> V_78 = 2 ;
V_2 -> V_79 [ 1 ] = V_126 ;
V_2 -> V_81 [ 0 ] = V_137 ;
V_10 -> V_122 . V_127 = F_64 ;
break;
#ifdef F_70
case V_138 :
V_2 -> V_62 = & V_139 ;
V_2 -> V_81 [ 0 ] = V_140 ;
V_2 -> V_79 [ 0 ] = V_141 ;
break;
#endif
}
switch ( V_10 -> V_142 >> 16 ) {
case 0x103c :
case 0x1631 :
case 0x1734 :
case 0x17aa :
F_71 ( V_10 , 0x17 , V_143 ,
( 0x14 << V_144 ) |
( 0x14 << V_145 ) |
( 0x05 << V_146 ) |
( 1 << V_147 ) ) ;
break;
}
if ( V_2 -> V_8 )
F_72 ( V_10 , F_73 ( V_2 -> V_8 ) ) ;
return 0 ;
}
static int F_74 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_94 ;
if ( ! F_50 ( V_59 , V_64 ) )
return 0 ;
V_94 = ( ! V_2 -> V_95 && V_2 -> V_89 ) ? 0 : V_96 ;
F_59 ( V_10 , 0x1d , V_85 , 0x01 ,
V_96 , V_94 ) ;
V_94 = V_2 -> V_89 ? 0 : V_96 ;
F_59 ( V_10 , 0x13 , V_85 , 0 ,
V_96 , V_94 ) ;
return 1 ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_94 ;
V_2 -> V_95 = F_61 ( V_10 , 0x13 ) ;
V_94 = ( V_2 -> V_95 || ! V_2 -> V_89 ) ? V_96 : 0 ;
F_59 ( V_10 , 0x1d , V_85 , 0x01 ,
V_96 , V_94 ) ;
}
static void F_76 ( struct V_9 * V_10 )
{
static const struct V_97 V_98 [] = {
{ 0x15 , V_99 , V_148 } ,
{ 0x17 , V_99 , V_149 } ,
{}
} ;
static const struct V_97 V_100 [] = {
{ 0x17 , V_99 , V_148 } ,
{ 0x15 , V_99 , V_149 } ,
{}
} ;
unsigned int V_101 ;
V_101 = F_61 ( V_10 , 0x15 ) ;
if ( V_101 )
F_37 ( V_10 , V_98 ) ;
else
F_37 ( V_10 , V_100 ) ;
}
static void F_77 ( struct V_9 * V_10 ,
unsigned int V_102 )
{
switch ( V_102 >> 26 ) {
case V_103 :
F_75 ( V_10 ) ;
break;
case V_104 :
F_76 ( V_10 ) ;
break;
}
}
static int F_78 ( struct V_9 * V_10 )
{
F_36 ( V_10 ) ;
F_75 ( V_10 ) ;
return 0 ;
}
static int F_79 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_105 ;
V_105 = F_66 ( V_10 , V_150 ,
V_151 ,
V_152 ) ;
if ( V_105 < 0 )
V_105 = V_153 ;
if ( V_105 == V_153 )
return F_67 ( V_10 ) ;
V_2 = F_68 ( sizeof( * V_2 ) , V_110 ) ;
if ( ! V_2 )
return - V_18 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_154 = 1 ;
V_2 -> V_24 . V_44 = 2 ;
V_2 -> V_24 . V_112 = F_69 ( V_155 ) ;
V_2 -> V_24 . V_45 = V_155 ;
V_2 -> V_24 . V_53 = V_156 ;
V_2 -> V_52 = 1 ;
V_2 -> V_28 = V_157 ;
V_2 -> V_71 = V_158 ;
V_2 -> V_80 = 1 ;
V_2 -> V_81 [ 0 ] = V_159 ;
V_2 -> V_78 = 1 ;
V_2 -> V_79 [ 0 ] = V_160 ;
V_2 -> V_120 = 0 ;
V_2 -> V_93 = F_69 ( V_161 ) ,
V_2 -> V_92 = V_161 ,
V_10 -> V_122 = V_123 ;
switch ( V_105 ) {
case V_162 :
V_2 -> V_80 = 2 ;
V_2 -> V_81 [ 1 ] = V_163 ;
V_10 -> V_122 . V_125 = F_77 ;
break;
case V_164 :
V_2 -> V_80 = 2 ;
V_2 -> V_81 [ 1 ] = V_165 ;
V_10 -> V_122 . V_125 = F_77 ;
V_10 -> V_122 . V_127 = F_78 ;
break;
case V_166 :
V_2 -> V_62 = & V_167 ;
V_2 -> V_80 = 2 ;
V_2 -> V_81 [ 1 ] = V_163 ;
V_2 -> V_78 = 2 ;
V_2 -> V_79 [ 1 ] = V_168 ;
V_10 -> V_122 . V_125 = F_77 ;
break;
#ifdef F_70
case V_169 :
V_2 -> V_62 = & V_170 ;
V_2 -> V_81 [ 0 ] = V_171 ;
V_2 -> V_79 [ 0 ] = V_172 ;
V_10 -> V_122 . V_125 = F_77 ;
#endif
}
V_2 -> V_83 = 0x13 ;
switch ( V_10 -> V_142 >> 16 ) {
case 0x103c :
F_71 ( V_10 , 0x10 , V_143 ,
( 0x17 << V_144 ) |
( 0x17 << V_145 ) |
( 0x05 << V_146 ) |
( 1 << V_147 ) ) ;
break;
}
return 0 ;
}
static void F_80 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_173 ;
V_173 = ( V_2 -> V_95 && V_2 -> V_89 ) ? V_174 : 0 ;
F_81 ( V_10 , 0x16 , V_173 ) ;
V_173 = ( ! V_2 -> V_95 && V_2 -> V_89 ) ? V_175 : 0 ;
F_81 ( V_10 , 0x1a , V_173 ) ;
if ( V_2 -> V_176 )
F_81 ( V_10 , 0x1b , V_173 ) ;
}
static int F_82 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
if ( ! F_50 ( V_59 , V_64 ) )
return 0 ;
F_80 ( V_10 ) ;
return 1 ;
}
static void F_83 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_101 ;
if ( ! ( V_2 -> V_177 & V_178 ) )
return;
V_101 = F_61 ( V_10 , 0x17 ) ;
F_84 ( V_10 , 0x14 , 0 ,
V_179 ,
V_101 ? 0x01 : 0x00 ) ;
}
static void F_85 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_101 ;
T_1 V_180 ;
if ( ! ( V_2 -> V_177 & V_181 ) )
return;
V_101 = F_61 ( V_10 , 0x18 ) ;
if ( V_101 )
V_2 -> V_32 = 1 ;
else
V_2 -> V_32 = 0 ;
V_180 = V_2 -> V_28 [ V_2 -> V_32 ] ;
if ( V_2 -> V_31 && V_2 -> V_31 != V_180 ) {
F_86 ( V_10 , V_2 -> V_31 , 1 ) ;
V_2 -> V_31 = V_180 ;
F_19 ( V_10 , V_180 ,
V_2 -> V_33 , 0 ,
V_2 -> V_34 ) ;
}
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_95 = F_61 ( V_10 , 0x16 ) ;
F_80 ( V_10 ) ;
}
static void F_88 ( struct V_9 * V_10 ,
unsigned int V_102 )
{
switch ( V_102 >> 26 ) {
case V_103 :
F_87 ( V_10 ) ;
break;
case V_182 :
F_83 ( V_10 ) ;
break;
case V_183 :
F_85 ( V_10 ) ;
break;
}
}
static void F_89 ( struct V_9 * V_10 , T_1 V_3 ,
unsigned int V_184 )
{
F_84 ( V_10 , V_3 , 0 ,
V_185 ,
V_186 | V_184 ) ;
}
static int F_90 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_36 ( V_10 ) ;
if ( V_2 -> V_177 & V_178 )
F_89 ( V_10 , 0x17 , V_182 ) ;
if ( V_2 -> V_177 & V_181 )
F_89 ( V_10 , 0x18 , V_183 ) ;
if ( V_10 -> V_122 . V_125 ) {
F_87 ( V_10 ) ;
F_83 ( V_10 ) ;
F_85 ( V_10 ) ;
}
return 0 ;
}
static int F_91 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_105 ;
V_105 = F_66 ( V_10 , V_187 ,
V_188 ,
V_189 ) ;
if ( V_105 < 0 )
V_105 = V_190 ;
if ( V_105 == V_190 )
return F_67 ( V_10 ) ;
V_2 = F_68 ( sizeof( * V_2 ) , V_110 ) ;
if ( ! V_2 )
return - V_18 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_154 = 1 ;
V_10 -> V_122 = V_123 ;
V_10 -> V_122 . V_127 = F_90 ;
V_2 -> V_24 . V_44 = 2 ;
V_2 -> V_24 . V_112 = F_69 ( V_191 ) ;
V_2 -> V_24 . V_45 = V_191 ;
V_2 -> V_24 . V_53 = V_192 ;
V_2 -> V_52 = 1 ;
V_2 -> V_28 = V_193 ;
V_2 -> V_80 = 2 ;
V_2 -> V_81 [ 0 ] = V_194 ;
V_2 -> V_81 [ 1 ] = V_195 ;
V_2 -> V_78 = 1 ;
V_2 -> V_79 [ 0 ] = V_196 ;
V_2 -> V_120 = 0 ;
V_2 -> V_93 = F_69 ( V_197 ) ;
V_2 -> V_92 = V_197 ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = 0 ;
F_1 ( V_2 , 0x13 , 0 , V_85 ) ;
V_10 -> V_122 . V_125 = F_88 ;
V_2 -> V_177 = V_178 | V_181 ;
switch ( V_105 ) {
case V_198 :
V_2 -> V_81 [ 0 ] = V_199 ;
break;
case V_200 :
V_2 -> V_79 [ 0 ] = V_201 ;
V_2 -> V_81 [ 0 ] = V_202 ;
V_2 -> V_177 = 0 ;
break;
case V_203 :
V_2 -> V_79 [ 0 ] = V_204 ;
V_2 -> V_81 [ 0 ] = V_205 ;
V_2 -> V_177 = 0 ;
break;
case V_206 :
V_2 -> V_81 [ 0 ] = V_207 ;
V_2 -> V_177 = V_178 ;
break;
case V_208 :
V_2 -> V_79 [ V_2 -> V_78 ++ ] =
V_209 ;
V_2 -> V_176 = 1 ;
break;
}
if ( V_2 -> V_8 )
F_72 ( V_10 , F_73 ( V_2 -> V_8 ) ) ;
return 0 ;
}
static void F_92 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_173 ;
F_93 ( L_7 ,
V_2 -> V_95 , V_2 -> V_89 ) ;
V_173 = ( F_94 ( V_2 ) && V_2 -> V_89 ) ? V_174 : 0 ;
F_81 ( V_10 , 0x19 , V_173 ) ;
V_173 = V_2 -> V_89 ? V_2 -> V_210 : 0 ;
if ( V_2 -> V_211 || V_2 -> V_212 ) {
if ( F_94 ( V_2 ) )
V_173 = 0 ;
} else {
if ( ! F_95 ( V_2 ) )
V_173 = 0 ;
}
F_81 ( V_10 , 0x1c , V_173 ) ;
V_173 = ( ! V_2 -> V_95 && V_2 -> V_89 ) ? V_175 : 0 ;
F_81 ( V_10 , 0x1f , V_173 ) ;
}
static int F_96 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
if ( ! F_50 ( V_59 , V_64 ) )
return 0 ;
F_92 ( V_10 ) ;
return 1 ;
}
static int F_97 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
return F_98 ( V_10 , 0x1a ,
V_213 . V_214 [ V_2 -> V_215 ] . V_216 ) ;
}
static void F_99 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( ! V_2 -> V_217 )
return;
if ( V_2 -> V_218 ) {
const struct V_97 V_219 [] = {
{ 0x1b , V_220 , 0 } ,
{ 0x1e , V_220 , V_221 } ,
{} ,
} ;
F_37 ( V_10 , V_219 ) ;
F_97 ( V_10 ) ;
return;
}
F_81 ( V_10 , 0x1e , 0 ) ;
F_81 ( V_10 , 0x1a ,
V_2 -> V_222 ? V_223 : 0 ) ;
F_81 ( V_10 , 0x1b ,
V_2 -> V_222 ? 0 : V_224 ) ;
}
static void F_100 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_101 ;
if ( V_2 -> V_218 )
return;
V_101 = F_34 ( V_10 , 0x1a , 0 ,
V_225 , 0 ) & 0x80000000 ;
if ( V_101 )
F_93 ( L_8 ) ;
else
F_93 ( L_9 ) ;
F_84 ( V_10 , 0x17 , 0 , V_179 ,
V_101 ? 0 : 1 ) ;
V_2 -> V_222 = ! ! V_101 ;
F_99 ( V_10 ) ;
}
static void F_101 ( struct V_9 * V_10 )
{
unsigned int V_101 ;
struct V_97 V_222 [] = {
{ 0x1a , V_220 , V_224 } ,
{ 0x17 , V_179 , 0 } ,
{ 0x14 , V_179 , 0 } ,
{ 0x23 , V_220 , 0 } ,
{}
} ;
static const struct V_97 V_226 [] = {
{ 0x23 , V_220 , V_221 } ,
{ 0x14 , V_179 , 2 } ,
{ 0x1a , V_220 , 0 } ,
{}
} ;
V_101 = F_61 ( V_10 , 0x1a ) ;
if ( V_101 ) {
F_93 ( L_8 ) ;
F_37 ( V_10 , V_222 ) ;
} else {
F_93 ( L_9 ) ;
F_37 ( V_10 , V_226 ) ;
}
}
static void F_102 ( struct V_9 * V_10 )
{
unsigned int V_101 ;
struct V_97 V_222 [] = {
{ 0x14 , V_179 , 0 } ,
{ 0x1b , V_220 , V_224 } ,
{ 0x23 , V_220 , 0 } ,
{}
} ;
static const struct V_97 V_226 [] = {
{ 0x14 , V_179 , 2 } ,
{ 0x23 , V_220 , V_221 } ,
{ 0x1b , V_220 , 0 } ,
{}
} ;
V_101 = F_61 ( V_10 , 0x1b ) ;
if ( V_101 ) {
F_93 ( L_8 ) ;
F_37 ( V_10 , V_222 ) ;
} else {
F_93 ( L_9 ) ;
F_37 ( V_10 , V_226 ) ;
}
}
static void F_103 ( struct V_9 * V_10 )
{
unsigned int V_101 ;
V_101 = F_61 ( V_10 , 0x1b ) ;
F_93 ( L_10 , V_101 ) ;
F_84 ( V_10 , 0x17 , 0 , V_179 ,
V_101 ? 1 : 0 ) ;
}
static void F_104 ( struct V_9 * V_10 )
{
unsigned int V_101 ;
V_101 = F_61 ( V_10 , 0x1b ) ;
F_93 ( L_10 , V_101 ) ;
F_84 ( V_10 , 0x17 , 0 , V_179 ,
V_101 ? 1 : 3 ) ;
}
static void F_105 ( struct V_9 * V_10 )
{
unsigned int V_227 , V_228 ;
static const struct V_97 V_222 [] = {
{ 0x14 , V_179 , 0 } ,
{ 0x17 , V_179 , 1 } ,
{ 0x1b , V_220 , V_224 } ,
{ 0x23 , V_220 , 0 } ,
{ 0x1a , V_220 , 0 } ,
{}
} ;
static const struct V_97 V_229 [] = {
{ 0x14 , V_179 , 0 } ,
{ 0x17 , V_179 , 0 } ,
{ 0x1a , V_220 , V_224 } ,
{ 0x23 , V_220 , 0 } ,
{ 0x1b , V_220 , 0 } ,
{}
} ;
static const struct V_97 V_226 [] = {
{ 0x14 , V_179 , 2 } ,
{ 0x23 , V_220 , V_221 } ,
{ 0x1b , V_220 , 0 } ,
{ 0x1a , V_220 , 0 } ,
{}
} ;
V_227 = F_61 ( V_10 , 0x1b ) ;
V_228 = F_61 ( V_10 , 0x1a ) ;
if ( V_227 ) {
F_93 ( L_8 ) ;
F_37 ( V_10 , V_222 ) ;
} else if ( V_228 ) {
F_93 ( L_11 ) ;
F_37 ( V_10 , V_229 ) ;
} else {
F_93 ( L_9 ) ;
F_37 ( V_10 , V_226 ) ;
}
}
static void F_106 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_230 , V_231 ;
V_230 = F_61 ( V_10 , 0x19 ) ;
V_231 = F_61 ( V_10 , 0x1c ) ;
V_2 -> V_95 = V_230 ? V_232 : 0 ;
V_2 -> V_95 |= V_231 ? V_233 : 0 ;
F_93 ( L_12 ,
V_230 , V_231 , V_2 -> V_95 ) ;
F_92 ( V_10 ) ;
}
static void F_107 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_2 -> V_234 )
F_101 ( V_10 ) ;
else if ( V_2 -> V_176 )
F_102 ( V_10 ) ;
else if ( V_2 -> V_212 )
F_105 ( V_10 ) ;
else if ( V_2 -> V_235 )
F_104 ( V_10 ) ;
else if ( V_2 -> V_236 )
F_103 ( V_10 ) ;
}
static void F_108 ( struct V_9 * V_10 , unsigned int V_102 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_93 ( L_13 , V_102 , V_102 >> 26 ) ;
switch ( V_102 >> 26 ) {
case V_103 :
F_106 ( V_10 ) ;
break;
case V_104 :
if ( ! V_2 -> V_218 )
F_100 ( V_10 ) ;
break;
}
}
static void F_109 ( struct V_9 * V_10 , unsigned int V_102 )
{
F_93 ( L_13 , V_102 , V_102 >> 26 ) ;
switch ( V_102 >> 26 ) {
case V_103 :
F_106 ( V_10 ) ;
break;
case V_104 :
F_107 ( V_10 ) ;
break;
}
}
static void F_110 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_51 ( V_10 , 0x17 , 0 ,
V_99 ,
V_237 | V_238 | V_239 |
V_240 . V_214 [ V_2 -> V_241 ] . V_216 ) ;
if ( V_2 -> V_176 || V_2 -> V_212 ) {
F_51 ( V_10 , 0x23 , 0 ,
V_99 ,
V_237 | V_238 | V_242 |
V_240 .
V_214 [ V_2 -> V_241 ] . V_216 ) ;
}
}
static int F_111 ( struct V_16 * V_59 ,
struct V_60 * V_61 )
{
return F_27 ( & V_240 , V_61 ) ;
}
static int F_112 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_64 -> V_67 . V_68 . V_69 [ 0 ] = V_2 -> V_241 ;
return 0 ;
}
static int F_113 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_243 * V_244 = & V_240 ;
unsigned int V_4 ;
V_4 = V_64 -> V_67 . V_68 . V_69 [ 0 ] ;
if ( V_4 >= V_244 -> V_245 )
V_4 = V_244 -> V_245 - 1 ;
V_2 -> V_241 = V_4 ;
if ( ! V_2 -> V_218 )
F_110 ( V_10 ) ;
return 1 ;
}
static void F_114 ( struct V_9 * V_10 )
{
const struct V_97 V_219 [] = {
{ 0x17 , V_99 , V_149 } ,
{ 0x17 , V_179 , 3 } ,
{}
} ;
F_37 ( V_10 , V_219 ) ;
F_99 ( V_10 ) ;
}
static void F_115 ( struct V_9 * V_10 )
{
F_110 ( V_10 ) ;
F_100 ( V_10 ) ;
}
static int F_116 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_64 -> V_67 . integer . V_67 [ 0 ] = V_2 -> V_218 ;
return 0 ;
}
static int F_117 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_218 = ! ! V_64 -> V_67 . integer . V_67 [ 0 ] ;
if ( V_218 == V_2 -> V_218 )
return 0 ;
V_2 -> V_218 = V_218 ;
if ( V_218 )
F_114 ( V_10 ) ;
else
F_115 ( V_10 ) ;
return 1 ;
}
static int F_118 ( struct V_16 * V_59 ,
struct V_60 * V_61 )
{
return F_27 ( & V_213 , V_61 ) ;
}
static int F_119 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_64 -> V_67 . V_68 . V_69 [ 0 ] = V_2 -> V_215 ;
return 0 ;
}
static int F_120 ( struct V_16 * V_59 ,
struct V_63 * V_64 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_243 * V_244 = & V_240 ;
unsigned int V_4 ;
V_4 = V_64 -> V_67 . V_68 . V_69 [ 0 ] ;
if ( V_4 >= V_244 -> V_245 )
V_4 = V_244 -> V_245 - 1 ;
V_2 -> V_215 = V_4 ;
if ( V_2 -> V_218 )
F_97 ( V_10 ) ;
return 1 ;
}
static void F_121 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_217 = 1 ;
F_99 ( V_10 ) ;
}
static void F_122 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_97 V_246 [] = {
{ 0x1a , V_220 , 0 } ,
{ 0x1b , V_220 , 0 } ,
{ 0x1e , V_220 , 0 } ,
{} ,
} ;
F_37 ( V_10 , V_246 ) ;
V_2 -> V_217 = 0 ;
}
static void F_123 ( struct V_9 * V_10 ,
const T_1 * V_247 ,
int V_248 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 * V_249 = & V_2 -> V_24 . V_53 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_248 ; V_77 ++ , V_247 ++ ) {
unsigned int V_250 = F_124 ( V_10 , * V_247 ) ;
if ( F_125 ( V_250 ) == V_251 )
continue;
if ( F_126 ( V_10 , * V_247 , V_249 , 1 ) != 1 )
continue;
}
}
static int F_127 ( struct V_9 * V_10 )
{
F_93 ( L_14 ) ;
F_36 ( V_10 ) ;
if ( V_10 -> V_122 . V_125 ) {
F_106 ( V_10 ) ;
F_107 ( V_10 ) ;
}
F_110 ( V_10 ) ;
return 0 ;
}
static int F_128 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_93 ( L_14 ) ;
F_36 ( V_10 ) ;
F_106 ( V_10 ) ;
if ( ! V_2 -> V_218 ) {
F_110 ( V_10 ) ;
F_100 ( V_10 ) ;
} else {
F_114 ( V_10 ) ;
}
return 0 ;
}
static int F_129 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_105 ;
V_105 = F_66 ( V_10 , V_252 ,
V_253 , V_254 ) ;
if ( V_105 < 0 )
V_105 = V_255 ;
if ( V_105 == V_255 )
return F_67 ( V_10 ) ;
V_2 = F_68 ( sizeof( * V_2 ) , V_110 ) ;
if ( ! V_2 )
return - V_18 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_122 = V_123 ;
V_10 -> V_122 . V_127 = F_36 ;
V_2 -> V_211 = 0 ;
V_2 -> V_24 . V_44 = 2 ;
V_2 -> V_24 . V_112 = F_69 ( V_256 ) ;
V_2 -> V_24 . V_45 = V_256 ;
F_123 ( V_10 , V_257 ,
F_69 ( V_257 ) ) ;
V_2 -> V_52 = 1 ;
V_2 -> V_28 = V_258 ;
V_2 -> V_71 = V_259 ;
V_2 -> V_62 = & V_260 ;
V_2 -> V_210 = V_174 ;
V_2 -> V_78 = 1 ;
V_2 -> V_79 [ 0 ] = V_261 ;
V_2 -> V_93 = F_69 ( V_262 ) ;
V_2 -> V_92 = V_262 ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = 0 ;
F_1 ( V_2 , 0x13 , 0 , V_85 ) ;
switch ( V_105 ) {
default:
case V_263 :
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_264 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_265 ;
break;
case V_266 :
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_264 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_265 ;
V_2 -> V_210 = V_175 ;
V_2 -> V_79 [ V_2 -> V_78 ] = V_267 ;
V_2 -> V_78 ++ ;
V_2 -> V_211 = 1 ;
break;
case V_268 :
case V_269 :
V_10 -> V_122 . V_127 = F_127 ;
V_10 -> V_122 . V_125 = F_109 ;
V_2 -> V_79 [ V_2 -> V_78 ] =
V_270 ;
V_2 -> V_78 ++ ;
V_2 -> V_235 = V_105 == V_269 ;
V_2 -> V_236 = V_105 == V_268 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_264 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_265 ;
if ( V_105 == V_269 )
V_2 -> V_24 . V_53 = 0 ;
V_2 -> V_62 = NULL ;
V_2 -> V_210 = 0 ;
V_2 -> V_241 = 3 ;
break;
case V_271 :
V_10 -> V_122 . V_127 = F_128 ;
V_10 -> V_122 . V_125 = F_108 ;
V_2 -> V_79 [ 0 ] = V_272 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_273 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_274 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_265 ;
V_2 -> V_210 = 0 ;
V_2 -> V_241 = 3 ;
V_2 -> V_24 . V_53 = 0 ;
V_2 -> V_62 = NULL ;
V_2 -> V_27 = F_121 ;
V_2 -> V_30 = F_122 ;
break;
case V_275 :
V_10 -> V_122 . V_127 = F_127 ;
V_10 -> V_122 . V_125 = F_109 ;
V_2 -> V_79 [ 0 ] = V_276 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_273 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_265 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_277 ;
V_2 -> V_210 = 0 ;
V_2 -> V_234 = 1 ;
V_2 -> V_241 = 3 ;
V_2 -> V_24 . V_53 = 0 ;
V_2 -> V_62 = NULL ;
break;
case V_278 :
V_10 -> V_122 . V_127 = F_127 ;
V_10 -> V_122 . V_125 = F_109 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_264 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_265 ;
V_2 -> V_79 [ 0 ] = V_279 ;
V_2 -> V_210 = 0 ;
V_2 -> V_176 = 1 ;
V_2 -> V_241 = 2 ;
V_2 -> V_24 . V_53 = 0 ;
V_2 -> V_62 = NULL ;
break;
case V_280 :
V_10 -> V_122 . V_127 = F_127 ;
V_10 -> V_122 . V_125 = F_109 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_264 ;
V_2 -> V_81 [ V_2 -> V_80 ++ ] = V_265 ;
V_2 -> V_79 [ 0 ] = V_281 ;
V_2 -> V_212 = 1 ;
V_2 -> V_210 = V_175 ;
V_2 -> V_241 = 2 ;
V_2 -> V_24 . V_53 = 0 ;
V_2 -> V_62 = NULL ;
break;
}
if ( V_2 -> V_8 )
F_72 ( V_10 , F_73 ( V_2 -> V_8 ) ) ;
return 0 ;
}
static void F_130 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_3 , V_282 ;
V_282 = V_10 -> V_283 + V_10 -> V_284 ;
for ( V_3 = V_10 -> V_283 ; V_3 < V_282 ; V_3 ++ )
if ( F_131 ( F_132 ( V_10 , V_3 ) ) == V_285 ) {
F_1 ( V_2 , V_3 , 0 , V_85 ) ;
break;
}
}
static void F_133 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_3 , V_282 ;
V_282 = V_10 -> V_283 + V_10 -> V_284 ;
for ( V_3 = V_10 -> V_283 ; V_3 < V_282 ; V_3 ++ ) {
if ( F_131 ( F_132 ( V_10 , V_3 ) ) != V_286 )
continue;
if ( ! ( F_134 ( V_10 , V_3 ) & V_287 ) )
continue;
V_2 -> V_288 [ V_2 -> V_289 ++ ] = V_3 ;
if ( V_2 -> V_289 >= F_69 ( V_2 -> V_288 ) )
break;
}
if ( V_2 -> V_289 > 2 )
V_2 -> V_290 = 1 ;
}
static void F_135 ( struct V_9 * V_10 , int V_248 ,
T_1 * V_291 , bool V_292 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_248 ; V_77 ++ ) {
if ( F_134 ( V_10 , V_291 [ V_77 ] ) & V_287 )
F_84 ( V_10 , V_291 [ V_77 ] , 0 ,
V_91 ,
V_292 ? 0x02 : 0 ) ;
}
}
static void F_136 ( void * V_293 , int V_294 )
{
struct V_9 * V_10 = V_293 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_135 ( V_10 , V_2 -> V_289 , V_2 -> V_288 , V_294 ) ;
}
static int F_137 ( struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_138 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_139 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_140 ( V_10 ) ;
if ( ! V_2 -> V_290 )
F_135 ( V_10 , V_2 -> V_289 , V_2 -> V_288 , true ) ;
F_141 ( V_10 , V_295 ) ;
return 0 ;
}
static void F_142 ( struct V_9 * V_10 )
{
F_141 ( V_10 , V_296 ) ;
F_143 ( V_10 ) ;
}
static void F_144 ( struct V_9 * V_10 ,
const struct V_297 * V_298 , int V_299 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_6 . V_300 = 1 ;
}
static void F_145 ( struct V_9 * V_10 ,
const struct V_297 * V_298 , int V_299 )
{
if ( V_299 != V_301 )
return;
F_71 ( V_10 , 0x17 , V_85 ,
( 0x3 << V_144 ) |
( 0x4 << V_145 ) |
( 0x27 << V_146 ) |
( 0 << V_147 ) ) ;
}
static void F_146 ( struct V_9 * V_10 )
{
int V_77 ;
bool V_302 = false ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_303 * V_250 = & V_2 -> V_6 . V_304 ;
T_1 V_305 = V_2 -> V_6 . V_306 [ V_2 -> V_6 . V_70 [ 0 ] ] ;
for ( V_77 = 0 ; V_77 < V_250 -> V_307 ; V_77 ++ )
if ( V_250 -> V_308 [ V_77 ] . V_309 == V_305 ) {
V_302 = ! ! V_250 -> V_308 [ V_77 ] . V_310 ;
break;
}
if ( V_302 ) {
F_51 ( V_10 , 0x1c , 0 , 0x410 , 0x7c ) ;
V_2 -> V_6 . V_311 = false ;
} else {
F_51 ( V_10 , 0x1c , 0 , 0x410 , 0x54 ) ;
V_2 -> V_6 . V_311 = F_61 ( V_10 , V_2 -> V_6 . V_304 . V_312 [ 0 ] ) ;
}
F_147 ( V_10 ) ;
}
static void F_148 ( struct V_9 * V_10 ,
struct V_16 * V_59 ,
struct V_63 * V_64 )
{
F_146 ( V_10 ) ;
}
static void F_149 ( struct V_9 * V_10 ,
const struct V_297 * V_298 , int V_299 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_299 ) {
case V_301 :
V_2 -> V_313 |= V_314 ;
break;
case V_315 :
V_2 -> V_6 . V_316 = F_148 ;
V_2 -> V_6 . V_317 = F_146 ;
break;
case V_295 :
F_146 ( V_10 ) ;
break;
}
}
static void F_150 ( struct V_9 * V_10 )
{
static T_1 V_318 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_319 ;
for ( V_319 = V_318 ; * V_319 ; V_319 ++ )
F_71 ( V_10 , * V_319 , V_85 ,
V_320 |
F_151 ( V_10 , * V_319 , V_85 ) ) ;
}
static int F_67 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
F_152 ( V_321 L_15 ,
V_10 -> V_322 ) ;
V_2 = F_68 ( sizeof( * V_2 ) , V_110 ) ;
if ( ! V_2 )
return - V_18 ;
F_153 ( & V_2 -> V_6 ) ;
V_10 -> V_2 = V_2 ;
F_130 ( V_10 ) ;
F_133 ( V_10 ) ;
V_2 -> V_6 . V_323 = 1 ;
if ( V_2 -> V_290 )
V_2 -> V_6 . V_324 . V_325 = F_136 ;
switch ( V_10 -> V_48 ) {
case 0x14f15045 :
V_10 -> V_111 = 1 ;
break;
case 0x14f15047 :
V_10 -> V_154 = 1 ;
V_2 -> V_6 . V_326 = 0x19 ;
break;
case 0x14f15051 :
F_150 ( V_10 ) ;
V_10 -> V_154 = 1 ;
F_154 ( V_10 , NULL , V_327 , V_328 ) ;
break;
default:
V_10 -> V_154 = 1 ;
F_154 ( V_10 , NULL , V_329 , V_328 ) ;
break;
}
switch ( V_10 -> V_142 >> 16 ) {
case 0x103c :
V_2 -> V_6 . V_330 = 1 ;
break;
}
F_141 ( V_10 , V_301 ) ;
V_11 = F_155 ( V_10 , & V_2 -> V_6 . V_304 , NULL ,
V_2 -> V_313 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_156 ( V_10 , & V_2 -> V_6 . V_304 ) ;
if ( V_11 < 0 )
goto error;
V_10 -> V_122 = V_331 ;
if ( ! V_10 -> V_332 -> V_333 ) {
F_157 ( L_16
L_17 ) ;
V_10 -> V_332 -> V_333 = 1 ;
V_10 -> V_332 -> V_334 = 1 ;
}
F_141 ( V_10 , V_315 ) ;
return 0 ;
error:
F_142 ( V_10 ) ;
return V_11 ;
}
static int T_2 F_158 ( void )
{
return F_159 ( & V_335 ) ;
}
static void T_3 F_160 ( void )
{
F_161 ( & V_335 ) ;
}
