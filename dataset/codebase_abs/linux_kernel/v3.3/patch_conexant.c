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
F_34 ( V_4 ) ;
F_35 ( V_4 -> V_8 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_66 ;
int V_69 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_70 ; V_66 ++ ) {
V_69 = F_37 ( V_4 , V_8 -> V_71 [ V_66 ] ) ;
if ( V_69 < 0 )
return V_69 ;
}
if ( V_8 -> V_9 . V_40 ) {
V_69 = F_38 ( V_4 ,
V_8 -> V_9 . V_40 ,
V_8 -> V_9 . V_40 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_39 ( V_4 ,
& V_8 -> V_9 ) ;
if ( V_69 < 0 )
return V_69 ;
V_8 -> V_9 . V_72 = 1 ;
}
if ( V_8 -> V_44 ) {
V_69 = F_40 ( V_4 , V_8 -> V_44 ) ;
if ( V_69 < 0 )
return V_69 ;
}
if ( V_8 -> V_73 &&
! F_41 ( V_4 , L_3 ) ) {
unsigned int V_74 [ 4 ] ;
F_42 ( V_4 , V_8 -> V_73 ,
V_75 , V_74 ) ;
V_69 = F_43 ( V_4 , L_3 ,
V_74 , V_76 ) ;
if ( V_69 < 0 )
return V_69 ;
}
if ( V_8 -> V_73 &&
! F_41 ( V_4 , L_4 ) ) {
V_69 = F_43 ( V_4 , L_4 ,
NULL , V_77 ) ;
if ( V_69 < 0 )
return V_69 ;
}
if ( V_8 -> V_51 ) {
V_69 = F_37 ( V_4 , V_78 ) ;
if ( V_69 < 0 )
return V_69 ;
}
#ifdef F_44
if ( V_8 -> V_79 ) {
const struct V_80 * V_81 ;
for ( V_81 = V_82 ; V_81 -> V_25 ; V_81 ++ ) {
struct V_47 * V_83 ;
V_83 = F_45 ( V_81 , V_4 ) ;
if ( ! V_83 )
return - V_84 ;
V_83 -> V_85 = V_8 -> V_79 ;
V_69 = F_46 ( V_4 , 0 , V_83 ) ;
if ( V_69 < 0 )
return V_69 ;
}
}
#endif
return 0 ;
}
static int F_47 ( struct V_3 * V_4 , T_2 V_86 )
{
F_48 ( V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_87 = ( V_48 -> V_85 >> 8 ) & 1 ;
if ( V_87 )
V_53 -> V_56 . integer . V_56 [ 0 ] = ! V_8 -> V_88 ;
else
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_88 ;
return 0 ;
}
static int F_50 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_87 = ( V_48 -> V_85 >> 8 ) & 1 ;
T_1 V_31 = V_48 -> V_85 & 0xff ;
unsigned int V_89 ;
V_89 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_87 )
V_89 = ! V_89 ;
if ( V_89 == V_8 -> V_88 )
return 0 ;
V_8 -> V_88 = V_89 ;
F_51 ( V_4 , V_31 ,
0 , V_90 ,
V_89 ? 0x02 : 0x00 ) ;
return 1 ;
}
static int F_52 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_53 ( V_4 , V_50 , V_8 -> V_91 ,
V_8 -> V_92 ) ;
}
static int F_54 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_55 ( V_4 , V_53 , V_8 -> V_91 ,
V_8 -> V_92 ,
V_8 -> V_9 . V_30 ) ;
}
static int F_56 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_69 = F_57 ( V_4 , V_53 , V_8 -> V_91 ,
V_8 -> V_92 ,
& V_8 -> V_9 . V_30 ) ;
if ( V_69 >= 0 && V_8 -> V_93 )
V_8 -> V_9 . V_94 = V_8 -> V_9 . V_30 / 2 ;
return V_69 ;
}
static int F_58 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_95 ;
if ( ! F_50 ( V_48 , V_53 ) )
return 0 ;
V_95 = ( ! V_8 -> V_96 && V_8 -> V_88 ) ? 0 : V_97 ;
F_59 ( V_4 , 0x10 , V_75 , 0 ,
V_97 , V_95 ) ;
V_95 = V_8 -> V_88 ? 0 : V_97 ;
F_59 ( V_4 , 0x11 , V_75 , 0 ,
V_97 , V_95 ) ;
return 1 ;
}
static void F_60 ( struct V_3 * V_4 )
{
static const struct V_98 V_99 [] = {
{ 0x14 , V_100 , 0xb080 } ,
{ 0x12 , V_100 , 0xb000 } ,
{}
} ;
static const struct V_98 V_101 [] = {
{ 0x12 , V_100 , 0xb080 } ,
{ 0x14 , V_100 , 0xb000 } ,
{}
} ;
unsigned int V_102 ;
V_102 = F_61 ( V_4 , 0x12 ) ;
if ( V_102 )
F_32 ( V_4 , V_99 ) ;
else
F_32 ( V_4 , V_101 ) ;
}
static void F_62 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_95 ;
V_8 -> V_96 = F_61 ( V_4 , 0x11 ) ;
V_95 = ( V_8 -> V_96 || ! V_8 -> V_88 ) ? V_97 : 0 ;
F_59 ( V_4 , 0x10 , V_75 , 0 ,
V_97 , V_95 ) ;
}
static void F_63 ( struct V_3 * V_4 ,
unsigned int V_103 )
{
V_103 >>= 26 ;
switch ( V_103 ) {
case V_104 :
F_62 ( V_4 ) ;
break;
case V_105 :
F_60 ( V_4 ) ;
break;
}
}
static int F_64 ( struct V_3 * V_4 )
{
F_31 ( V_4 ) ;
F_62 ( V_4 ) ;
return 0 ;
}
static int F_65 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_106 ;
V_106 = F_66 ( V_4 , V_107 ,
V_108 ,
V_109 ) ;
if ( V_106 < 0 )
V_106 = V_110 ;
if ( V_106 == V_110 )
return F_67 ( V_4 ) ;
V_8 = F_68 ( sizeof( * V_8 ) , V_111 ) ;
if ( ! V_8 )
return - V_84 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_112 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_94 = F_69 ( V_113 ) ;
V_8 -> V_9 . V_32 = V_113 ;
V_8 -> V_9 . V_40 = V_114 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_115 ;
V_8 -> V_60 = V_116 ;
V_8 -> V_51 = & V_117 ;
V_8 -> V_70 = 1 ;
V_8 -> V_71 [ 0 ] = V_118 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_119 ;
V_8 -> V_120 = 0 ;
V_8 -> V_92 = F_69 ( V_121 ) ;
V_8 -> V_91 = V_121 ;
F_70 ( V_8 , 0x16 , 0 , 1 ) ;
V_4 -> V_122 = V_123 ;
switch ( V_106 ) {
case V_124 :
V_4 -> V_122 . V_125 = F_63 ;
V_8 -> V_51 = & V_117 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_126 ;
V_8 -> V_71 [ 0 ] = V_118 ;
V_4 -> V_122 . V_127 = F_64 ;
break;
case V_128 :
V_4 -> V_122 . V_125 = F_63 ;
V_8 -> V_51 = & V_117 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_129 ;
V_8 -> V_71 [ 0 ] = V_118 ;
V_4 -> V_122 . V_127 = F_64 ;
break;
default:
case V_130 :
V_4 -> V_122 . V_125 = F_63 ;
V_8 -> V_51 = & V_117 ;
V_8 -> V_67 = 3 ;
V_8 -> V_68 [ 1 ] = V_126 ;
V_8 -> V_68 [ 2 ] = V_129 ;
V_8 -> V_71 [ 0 ] = V_118 ;
V_4 -> V_122 . V_127 = F_64 ;
break;
case V_131 :
V_4 -> V_122 . V_125 = F_63 ;
V_8 -> V_51 = & V_132 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_133 ;
V_8 -> V_71 [ 0 ] = V_118 ;
V_8 -> V_71 [ 1 ] = V_134 ;
V_8 -> V_70 = 2 ;
V_4 -> V_122 . V_127 = F_64 ;
break;
case V_135 :
V_4 -> V_122 . V_125 = F_63 ;
V_8 -> V_51 = & V_136 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_126 ;
V_8 -> V_71 [ 0 ] = V_137 ;
V_4 -> V_122 . V_127 = F_64 ;
break;
#ifdef F_71
case V_138 :
V_8 -> V_51 = & V_139 ;
V_8 -> V_71 [ 0 ] = V_140 ;
V_8 -> V_68 [ 0 ] = V_141 ;
break;
#endif
}
switch ( V_4 -> V_142 >> 16 ) {
case 0x103c :
case 0x1631 :
case 0x1734 :
case 0x17aa :
F_72 ( V_4 , 0x17 , V_143 ,
( 0x14 << V_144 ) |
( 0x14 << V_145 ) |
( 0x05 << V_146 ) |
( 1 << V_147 ) ) ;
break;
}
if ( V_8 -> V_79 )
F_73 ( V_4 , V_8 -> V_79 ) ;
return 0 ;
}
static int F_74 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_95 ;
if ( ! F_50 ( V_48 , V_53 ) )
return 0 ;
V_95 = ( ! V_8 -> V_96 && V_8 -> V_88 ) ? 0 : V_97 ;
F_59 ( V_4 , 0x1d , V_75 , 0x01 ,
V_97 , V_95 ) ;
V_95 = V_8 -> V_88 ? 0 : V_97 ;
F_59 ( V_4 , 0x13 , V_75 , 0 ,
V_97 , V_95 ) ;
return 1 ;
}
static void F_75 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_95 ;
V_8 -> V_96 = F_61 ( V_4 , 0x13 ) ;
V_95 = ( V_8 -> V_96 || ! V_8 -> V_88 ) ? V_97 : 0 ;
F_59 ( V_4 , 0x1d , V_75 , 0x01 ,
V_97 , V_95 ) ;
}
static void F_76 ( struct V_3 * V_4 )
{
static const struct V_98 V_99 [] = {
{ 0x15 , V_100 , V_148 } ,
{ 0x17 , V_100 , V_149 } ,
{}
} ;
static const struct V_98 V_101 [] = {
{ 0x17 , V_100 , V_148 } ,
{ 0x15 , V_100 , V_149 } ,
{}
} ;
unsigned int V_102 ;
V_102 = F_61 ( V_4 , 0x15 ) ;
if ( V_102 )
F_32 ( V_4 , V_99 ) ;
else
F_32 ( V_4 , V_101 ) ;
}
static void F_77 ( struct V_3 * V_4 ,
unsigned int V_103 )
{
switch ( V_103 >> 26 ) {
case V_104 :
F_75 ( V_4 ) ;
break;
case V_105 :
F_76 ( V_4 ) ;
break;
}
}
static int F_78 ( struct V_3 * V_4 )
{
F_31 ( V_4 ) ;
F_75 ( V_4 ) ;
return 0 ;
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_106 ;
V_106 = F_66 ( V_4 , V_150 ,
V_151 ,
V_152 ) ;
if ( V_106 < 0 )
V_106 = V_153 ;
if ( V_106 == V_153 )
return F_67 ( V_4 ) ;
V_8 = F_68 ( sizeof( * V_8 ) , V_111 ) ;
if ( ! V_8 )
return - V_84 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_112 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_94 = F_69 ( V_154 ) ;
V_8 -> V_9 . V_32 = V_154 ;
V_8 -> V_9 . V_40 = V_155 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_156 ;
V_8 -> V_60 = V_157 ;
V_8 -> V_70 = 1 ;
V_8 -> V_71 [ 0 ] = V_158 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_159 ;
V_8 -> V_120 = 0 ;
V_8 -> V_92 = F_69 ( V_160 ) ,
V_8 -> V_91 = V_160 ,
V_4 -> V_122 = V_123 ;
switch ( V_106 ) {
case V_161 :
V_8 -> V_70 = 2 ;
V_8 -> V_71 [ 1 ] = V_162 ;
V_4 -> V_122 . V_125 = F_77 ;
break;
case V_163 :
V_8 -> V_70 = 2 ;
V_8 -> V_71 [ 1 ] = V_164 ;
V_4 -> V_122 . V_125 = F_77 ;
V_4 -> V_122 . V_127 = F_78 ;
break;
case V_165 :
V_8 -> V_51 = & V_166 ;
V_8 -> V_70 = 2 ;
V_8 -> V_71 [ 1 ] = V_162 ;
V_8 -> V_67 = 2 ;
V_8 -> V_68 [ 1 ] = V_167 ;
V_4 -> V_122 . V_125 = F_77 ;
break;
#ifdef F_71
case V_168 :
V_8 -> V_51 = & V_169 ;
V_8 -> V_71 [ 0 ] = V_170 ;
V_8 -> V_68 [ 0 ] = V_171 ;
V_4 -> V_122 . V_125 = F_77 ;
#endif
}
V_8 -> V_73 = 0x13 ;
switch ( V_4 -> V_142 >> 16 ) {
case 0x103c :
F_72 ( V_4 , 0x10 , V_143 ,
( 0x17 << V_144 ) |
( 0x17 << V_145 ) |
( 0x05 << V_146 ) |
( 1 << V_147 ) ) ;
break;
}
return 0 ;
}
static void F_80 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_172 ;
V_172 = ( V_8 -> V_96 && V_8 -> V_88 ) ? V_173 : 0 ;
F_81 ( V_4 , 0x16 , 0 , V_174 ,
V_172 ) ;
V_172 = ( ! V_8 -> V_96 && V_8 -> V_88 ) ? V_175 : 0 ;
F_81 ( V_4 , 0x1a , 0 , V_174 ,
V_172 ) ;
if ( V_8 -> V_176 )
F_81 ( V_4 , 0x1b , 0 ,
V_174 ,
V_172 ) ;
}
static int F_82 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
if ( ! F_50 ( V_48 , V_53 ) )
return 0 ;
F_80 ( V_4 ) ;
return 1 ;
}
static void F_83 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_102 ;
if ( ! ( V_8 -> V_177 & V_178 ) )
return;
V_102 = F_61 ( V_4 , 0x17 ) ;
F_81 ( V_4 , 0x14 , 0 ,
V_179 ,
V_102 ? 0x01 : 0x00 ) ;
}
static void F_84 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_102 ;
T_1 V_180 ;
if ( ! ( V_8 -> V_177 & V_181 ) )
return;
V_102 = F_61 ( V_4 , 0x18 ) ;
if ( V_102 )
V_8 -> V_17 = 1 ;
else
V_8 -> V_17 = 0 ;
V_180 = V_8 -> V_13 [ V_8 -> V_17 ] ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_180 ) {
F_85 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_180 ;
F_14 ( V_4 , V_180 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
}
static void F_86 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_96 = F_61 ( V_4 , 0x16 ) ;
F_80 ( V_4 ) ;
}
static void F_87 ( struct V_3 * V_4 ,
unsigned int V_103 )
{
switch ( V_103 >> 26 ) {
case V_104 :
F_86 ( V_4 ) ;
break;
case V_182 :
F_83 ( V_4 ) ;
break;
case V_183 :
F_84 ( V_4 ) ;
break;
}
}
static void F_88 ( struct V_3 * V_4 , T_1 V_31 ,
unsigned int V_184 )
{
F_81 ( V_4 , V_31 , 0 ,
V_185 ,
V_186 | V_184 ) ;
}
static int F_89 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_31 ( V_4 ) ;
if ( V_8 -> V_177 & V_178 )
F_88 ( V_4 , 0x17 , V_182 ) ;
if ( V_8 -> V_177 & V_181 )
F_88 ( V_4 , 0x18 , V_183 ) ;
if ( V_4 -> V_122 . V_125 ) {
F_86 ( V_4 ) ;
F_83 ( V_4 ) ;
F_84 ( V_4 ) ;
}
return 0 ;
}
static int F_90 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_106 ;
V_106 = F_66 ( V_4 , V_187 ,
V_188 ,
V_189 ) ;
if ( V_106 < 0 )
V_106 = V_190 ;
if ( V_106 == V_190 )
return F_67 ( V_4 ) ;
V_8 = F_68 ( sizeof( * V_8 ) , V_111 ) ;
if ( ! V_8 )
return - V_84 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_112 = 1 ;
V_4 -> V_122 = V_123 ;
V_4 -> V_122 . V_127 = F_89 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_94 = F_69 ( V_191 ) ;
V_8 -> V_9 . V_32 = V_191 ;
V_8 -> V_9 . V_40 = V_192 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_193 ;
V_8 -> V_70 = 2 ;
V_8 -> V_71 [ 0 ] = V_194 ;
V_8 -> V_71 [ 1 ] = V_195 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_196 ;
V_8 -> V_120 = 0 ;
V_8 -> V_92 = F_69 ( V_197 ) ;
V_8 -> V_91 = V_197 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_70 ( V_8 , 0x13 , 0 , V_75 ) ;
V_4 -> V_122 . V_125 = F_87 ;
V_8 -> V_177 = V_178 | V_181 ;
switch ( V_106 ) {
case V_198 :
V_8 -> V_71 [ 0 ] = V_199 ;
break;
case V_200 :
V_8 -> V_68 [ 0 ] = V_201 ;
V_8 -> V_71 [ 0 ] = V_202 ;
V_8 -> V_177 = 0 ;
break;
case V_203 :
V_8 -> V_68 [ 0 ] = V_204 ;
V_8 -> V_71 [ 0 ] = V_205 ;
V_8 -> V_177 = 0 ;
break;
case V_206 :
V_8 -> V_71 [ 0 ] = V_207 ;
V_8 -> V_177 = V_178 ;
break;
case V_208 :
V_8 -> V_68 [ V_8 -> V_67 ++ ] =
V_209 ;
V_8 -> V_176 = 1 ;
break;
}
if ( V_8 -> V_79 )
F_73 ( V_4 , V_8 -> V_79 ) ;
return 0 ;
}
static void F_91 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_172 ;
F_92 ( L_5 ,
V_8 -> V_96 , V_8 -> V_88 ) ;
V_172 = ( F_93 ( V_8 ) && V_8 -> V_88 ) ? V_173 : 0 ;
F_81 ( V_4 , 0x19 , 0 , V_174 ,
V_172 ) ;
V_172 = V_8 -> V_88 ? V_8 -> V_210 : 0 ;
if ( V_8 -> V_211 || V_8 -> V_212 ) {
if ( F_93 ( V_8 ) )
V_172 = 0 ;
} else {
if ( ! F_94 ( V_8 ) )
V_172 = 0 ;
}
F_81 ( V_4 , 0x1c , 0 , V_174 ,
V_172 ) ;
V_172 = ( ! V_8 -> V_96 && V_8 -> V_88 ) ? V_175 : 0 ;
F_81 ( V_4 , 0x1f , 0 , V_174 ,
V_172 ) ;
}
static int F_95 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
if ( ! F_50 ( V_48 , V_53 ) )
return 0 ;
F_91 ( V_4 ) ;
return 1 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_51 ( V_4 , 0x1a , 0 ,
V_174 ,
V_213 . V_214 [ V_8 -> V_215 ] . V_216 ) ;
}
static void F_97 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_217 )
return;
if ( V_8 -> V_218 ) {
const struct V_98 V_219 [] = {
{ 0x1b , V_174 , 0 } ,
{ 0x1e , V_174 , V_220 } ,
{} ,
} ;
F_32 ( V_4 , V_219 ) ;
F_96 ( V_4 ) ;
return;
}
F_81 ( V_4 , 0x1e , 0 , V_174 , 0 ) ;
F_81 ( V_4 , 0x1a , 0 , V_174 ,
V_8 -> V_221 ? V_222 : 0 ) ;
F_81 ( V_4 , 0x1b , 0 , V_174 ,
V_8 -> V_221 ? 0 : V_223 ) ;
}
static void F_98 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_102 ;
if ( V_8 -> V_218 )
return;
V_102 = F_29 ( V_4 , 0x1a , 0 ,
V_224 , 0 ) & 0x80000000 ;
if ( V_102 )
F_92 ( L_6 ) ;
else
F_92 ( L_7 ) ;
F_81 ( V_4 , 0x17 , 0 , V_179 ,
V_102 ? 0 : 1 ) ;
V_8 -> V_221 = ! ! V_102 ;
F_97 ( V_4 ) ;
}
static void F_99 ( struct V_3 * V_4 )
{
unsigned int V_102 ;
struct V_98 V_221 [] = {
{ 0x1a , V_174 , V_223 } ,
{ 0x17 , V_179 , 0 } ,
{ 0x14 , V_179 , 0 } ,
{ 0x23 , V_174 , 0 } ,
{}
} ;
static const struct V_98 V_225 [] = {
{ 0x23 , V_174 , V_220 } ,
{ 0x14 , V_179 , 2 } ,
{ 0x1a , V_174 , 0 } ,
{}
} ;
V_102 = F_61 ( V_4 , 0x1a ) ;
if ( V_102 ) {
F_92 ( L_6 ) ;
F_32 ( V_4 , V_221 ) ;
} else {
F_92 ( L_7 ) ;
F_32 ( V_4 , V_225 ) ;
}
}
static void F_100 ( struct V_3 * V_4 )
{
unsigned int V_102 ;
struct V_98 V_221 [] = {
{ 0x14 , V_179 , 0 } ,
{ 0x1b , V_174 , V_223 } ,
{ 0x23 , V_174 , 0 } ,
{}
} ;
static const struct V_98 V_225 [] = {
{ 0x14 , V_179 , 2 } ,
{ 0x23 , V_174 , V_220 } ,
{ 0x1b , V_174 , 0 } ,
{}
} ;
V_102 = F_61 ( V_4 , 0x1b ) ;
if ( V_102 ) {
F_92 ( L_6 ) ;
F_32 ( V_4 , V_221 ) ;
} else {
F_92 ( L_7 ) ;
F_32 ( V_4 , V_225 ) ;
}
}
static void F_101 ( struct V_3 * V_4 )
{
unsigned int V_102 ;
V_102 = F_61 ( V_4 , 0x1b ) ;
F_92 ( L_8 , V_102 ) ;
F_81 ( V_4 , 0x17 , 0 , V_179 ,
V_102 ? 1 : 0 ) ;
}
static void F_102 ( struct V_3 * V_4 )
{
unsigned int V_102 ;
V_102 = F_61 ( V_4 , 0x1b ) ;
F_92 ( L_8 , V_102 ) ;
F_81 ( V_4 , 0x17 , 0 , V_179 ,
V_102 ? 1 : 3 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
unsigned int V_226 , V_227 ;
static const struct V_98 V_221 [] = {
{ 0x14 , V_179 , 0 } ,
{ 0x17 , V_179 , 1 } ,
{ 0x1b , V_174 , V_223 } ,
{ 0x23 , V_174 , 0 } ,
{ 0x1a , V_174 , 0 } ,
{}
} ;
static const struct V_98 V_228 [] = {
{ 0x14 , V_179 , 0 } ,
{ 0x17 , V_179 , 0 } ,
{ 0x1a , V_174 , V_223 } ,
{ 0x23 , V_174 , 0 } ,
{ 0x1b , V_174 , 0 } ,
{}
} ;
static const struct V_98 V_225 [] = {
{ 0x14 , V_179 , 2 } ,
{ 0x23 , V_174 , V_220 } ,
{ 0x1b , V_174 , 0 } ,
{ 0x1a , V_174 , 0 } ,
{}
} ;
V_226 = F_61 ( V_4 , 0x1b ) ;
V_227 = F_61 ( V_4 , 0x1a ) ;
if ( V_226 ) {
F_92 ( L_6 ) ;
F_32 ( V_4 , V_221 ) ;
} else if ( V_227 ) {
F_92 ( L_9 ) ;
F_32 ( V_4 , V_228 ) ;
} else {
F_92 ( L_7 ) ;
F_32 ( V_4 , V_225 ) ;
}
}
static void F_104 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_229 , V_230 ;
V_229 = F_61 ( V_4 , 0x19 ) ;
V_230 = F_61 ( V_4 , 0x1c ) ;
V_8 -> V_96 = V_229 ? V_231 : 0 ;
V_8 -> V_96 |= V_230 ? V_232 : 0 ;
F_92 ( L_10 ,
V_229 , V_230 , V_8 -> V_96 ) ;
F_91 ( V_4 ) ;
}
static void F_105 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 -> V_233 )
F_99 ( V_4 ) ;
else if ( V_8 -> V_176 )
F_100 ( V_4 ) ;
else if ( V_8 -> V_212 )
F_103 ( V_4 ) ;
else if ( V_8 -> V_234 )
F_102 ( V_4 ) ;
else if ( V_8 -> V_235 )
F_101 ( V_4 ) ;
}
static void F_106 ( struct V_3 * V_4 , unsigned int V_103 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_92 ( L_11 , V_103 , V_103 >> 26 ) ;
switch ( V_103 >> 26 ) {
case V_104 :
F_104 ( V_4 ) ;
break;
case V_105 :
if ( ! V_8 -> V_218 )
F_98 ( V_4 ) ;
break;
}
}
static void F_107 ( struct V_3 * V_4 , unsigned int V_103 )
{
F_92 ( L_11 , V_103 , V_103 >> 26 ) ;
switch ( V_103 >> 26 ) {
case V_104 :
F_104 ( V_4 ) ;
break;
case V_105 :
F_105 ( V_4 ) ;
break;
}
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_51 ( V_4 , 0x17 , 0 ,
V_100 ,
V_236 | V_237 | V_238 |
V_239 . V_214 [ V_8 -> V_240 ] . V_216 ) ;
if ( V_8 -> V_176 || V_8 -> V_212 ) {
F_51 ( V_4 , 0x23 , 0 ,
V_100 ,
V_236 | V_237 | V_241 |
V_239 .
V_214 [ V_8 -> V_240 ] . V_216 ) ;
}
}
static int F_109 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_239 , V_50 ) ;
}
static int F_110 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_240 ;
return 0 ;
}
static int F_111 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_242 * V_243 = & V_239 ;
unsigned int V_244 ;
V_244 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_244 >= V_243 -> V_245 )
V_244 = V_243 -> V_245 - 1 ;
V_8 -> V_240 = V_244 ;
if ( ! V_8 -> V_218 )
F_108 ( V_4 ) ;
return 1 ;
}
static void F_112 ( struct V_3 * V_4 )
{
const struct V_98 V_219 [] = {
{ 0x17 , V_100 , V_149 } ,
{ 0x17 , V_179 , 3 } ,
{}
} ;
F_32 ( V_4 , V_219 ) ;
F_97 ( V_4 ) ;
}
static void F_113 ( struct V_3 * V_4 )
{
F_108 ( V_4 ) ;
F_98 ( V_4 ) ;
}
static int F_114 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_218 ;
return 0 ;
}
static int F_115 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_218 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_218 == V_8 -> V_218 )
return 0 ;
V_8 -> V_218 = V_218 ;
if ( V_218 )
F_112 ( V_4 ) ;
else
F_113 ( V_4 ) ;
return 1 ;
}
static int F_116 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_213 , V_50 ) ;
}
static int F_117 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_215 ;
return 0 ;
}
static int F_118 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_242 * V_243 = & V_239 ;
unsigned int V_244 ;
V_244 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_244 >= V_243 -> V_245 )
V_244 = V_243 -> V_245 - 1 ;
V_8 -> V_215 = V_244 ;
if ( V_8 -> V_218 )
F_96 ( V_4 ) ;
return 1 ;
}
static void F_119 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_217 = 1 ;
F_97 ( V_4 ) ;
}
static void F_120 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_98 V_246 [] = {
{ 0x1a , V_174 , 0 } ,
{ 0x1b , V_174 , 0 } ,
{ 0x1e , V_174 , 0 } ,
{} ,
} ;
F_32 ( V_4 , V_246 ) ;
V_8 -> V_217 = 0 ;
}
static void F_121 ( struct V_3 * V_4 ,
const T_1 * V_247 ,
int V_248 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 * V_249 = & V_8 -> V_9 . V_40 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_248 ; V_66 ++ , V_247 ++ ) {
unsigned int V_250 = F_122 ( V_4 , * V_247 ) ;
if ( F_123 ( V_250 ) == V_251 )
continue;
if ( F_124 ( V_4 , * V_247 , V_249 , 1 ) != 1 )
continue;
if ( V_8 -> V_46 [ 0 ] )
V_249 ++ ;
else
V_249 = V_8 -> V_46 ;
}
}
static int F_125 ( struct V_3 * V_4 )
{
F_92 ( L_12 ) ;
F_31 ( V_4 ) ;
if ( V_4 -> V_122 . V_125 ) {
F_104 ( V_4 ) ;
F_105 ( V_4 ) ;
}
F_108 ( V_4 ) ;
return 0 ;
}
static int F_126 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_92 ( L_12 ) ;
F_31 ( V_4 ) ;
F_104 ( V_4 ) ;
if ( ! V_8 -> V_218 ) {
F_108 ( V_4 ) ;
F_98 ( V_4 ) ;
} else {
F_112 ( V_4 ) ;
}
return 0 ;
}
static int F_127 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_106 ;
V_106 = F_66 ( V_4 , V_252 ,
V_253 , V_254 ) ;
if ( V_106 < 0 )
V_106 = V_255 ;
if ( V_106 == V_255 )
return F_67 ( V_4 ) ;
V_8 = F_68 ( sizeof( * V_8 ) , V_111 ) ;
if ( ! V_8 )
return - V_84 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_122 = V_123 ;
V_4 -> V_122 . V_127 = F_31 ;
V_8 -> V_211 = 0 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_94 = F_69 ( V_256 ) ;
V_8 -> V_9 . V_32 = V_256 ;
F_121 ( V_4 , V_257 ,
F_69 ( V_257 ) ) ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_258 ;
V_8 -> V_60 = V_259 ;
V_8 -> V_51 = & V_260 ;
V_8 -> V_210 = V_173 ;
V_8 -> V_67 = 1 ;
V_8 -> V_68 [ 0 ] = V_261 ;
V_8 -> V_92 = F_69 ( V_262 ) ;
V_8 -> V_91 = V_262 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_70 ( V_8 , 0x13 , 0 , V_75 ) ;
switch ( V_106 ) {
default:
case V_263 :
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_264 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_265 ;
break;
case V_266 :
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_264 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_265 ;
V_8 -> V_210 = V_175 ;
V_8 -> V_68 [ V_8 -> V_67 ] = V_267 ;
V_8 -> V_67 ++ ;
V_8 -> V_211 = 1 ;
break;
case V_268 :
case V_269 :
V_4 -> V_122 . V_127 = F_125 ;
V_4 -> V_122 . V_125 = F_107 ;
V_8 -> V_68 [ V_8 -> V_67 ] =
V_270 ;
V_8 -> V_67 ++ ;
V_8 -> V_234 = V_106 == V_269 ;
V_8 -> V_235 = V_106 == V_268 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_264 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_265 ;
if ( V_106 == V_269 )
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_210 = 0 ;
V_8 -> V_240 = 3 ;
break;
case V_271 :
V_4 -> V_122 . V_127 = F_126 ;
V_4 -> V_122 . V_125 = F_106 ;
V_8 -> V_68 [ 0 ] = V_272 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_273 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_274 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_265 ;
V_8 -> V_210 = 0 ;
V_8 -> V_240 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_12 = F_119 ;
V_8 -> V_15 = F_120 ;
break;
case V_275 :
V_4 -> V_122 . V_127 = F_125 ;
V_4 -> V_122 . V_125 = F_107 ;
V_8 -> V_68 [ 0 ] = V_276 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_273 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_265 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_277 ;
V_8 -> V_210 = 0 ;
V_8 -> V_233 = 1 ;
V_8 -> V_240 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_278 :
V_4 -> V_122 . V_127 = F_125 ;
V_4 -> V_122 . V_125 = F_107 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_264 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_265 ;
V_8 -> V_68 [ 0 ] = V_279 ;
V_8 -> V_210 = 0 ;
V_8 -> V_176 = 1 ;
V_8 -> V_240 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_280 :
V_4 -> V_122 . V_127 = F_125 ;
V_4 -> V_122 . V_125 = F_107 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_264 ;
V_8 -> V_71 [ V_8 -> V_70 ++ ] = V_265 ;
V_8 -> V_68 [ 0 ] = V_281 ;
V_8 -> V_212 = 1 ;
V_8 -> V_210 = V_175 ;
V_8 -> V_240 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
}
if ( V_8 -> V_79 )
F_73 ( V_4 , V_8 -> V_79 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_282 = V_8 -> V_283 [ V_8 -> V_59 [ 0 ] ] . V_282 ;
if ( V_8 -> V_284 ) {
V_8 -> V_16 = V_282 ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_11 ;
}
F_14 ( V_4 , V_282 , V_10 , 0 , V_11 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_16 ( V_4 , V_8 -> V_16 ) ;
V_8 -> V_16 = 0 ;
return 0 ;
}
static T_1 F_130 ( struct V_3 * V_4 , T_1 V_285 ,
T_1 * V_286 , int * V_94 )
{
int V_66 , V_287 = * V_94 ;
T_1 V_288 = 0 ;
for ( V_66 = 0 ; V_66 < V_287 ; V_66 ++ ) {
if ( F_131 ( V_4 , V_285 , V_286 [ V_66 ] ) >= 0 ) {
V_288 = V_286 [ V_66 ] ;
break;
}
}
if ( ! V_288 )
return 0 ;
if ( -- V_287 > 0 )
memmove ( V_286 , V_286 + 1 , V_287 * sizeof( T_1 ) ) ;
* V_94 = V_287 ;
return V_288 ;
}
static int F_132 ( struct V_3 * V_4 , T_1 * V_286 )
{
T_1 V_31 , V_289 ;
int V_287 = 0 ;
V_289 = V_4 -> V_290 + V_4 -> V_291 ;
for ( V_31 = V_4 -> V_290 ; V_31 < V_289 ; V_31 ++ ) {
unsigned int V_292 = F_133 ( V_4 , V_31 ) ;
unsigned int type = F_134 ( V_292 ) ;
if ( type == V_293 && ! ( V_292 & V_294 ) ) {
V_286 [ V_287 ++ ] = V_31 ;
if ( V_287 >= V_295 )
break;
}
}
return V_287 ;
}
static int F_135 ( struct V_3 * V_4 , T_1 * V_296 ,
int V_248 , T_1 * V_286 , int * V_297 ,
struct V_298 * V_299 , int V_287 ,
int type )
{
int V_66 , V_300 = V_287 ;
for ( V_66 = 0 ; V_66 < V_248 ; V_66 ++ , V_287 ++ ) {
V_299 [ V_287 ] . V_285 = V_296 [ V_66 ] ;
V_299 [ V_287 ] . type = type ;
V_299 [ V_287 ] . V_301 = F_130 ( V_4 , V_296 [ V_66 ] , V_286 , V_297 ) ;
if ( V_299 [ V_287 ] . V_301 )
continue;
if ( V_299 [ V_300 ] . V_301 && F_131 ( V_4 , V_296 [ V_66 ] , V_299 [ V_300 ] . V_301 ) >= 0 ) {
V_299 [ V_287 ] . V_301 = V_299 [ V_300 ] . V_301 | V_302 ;
continue;
}
if ( V_299 [ 0 ] . V_301 && F_131 ( V_4 , V_296 [ V_66 ] , V_299 [ 0 ] . V_301 ) >= 0 ) {
V_299 [ V_287 ] . V_301 = V_299 [ 0 ] . V_301 | V_302 ;
continue;
}
F_92 ( L_13 , V_296 [ V_66 ] ) ;
}
return V_287 ;
}
static void F_136 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_303 * V_250 = & V_8 -> V_304 ;
T_1 V_286 [ V_295 ] ;
int V_66 , V_305 , V_287 , V_297 ;
V_297 = F_132 ( V_4 , V_286 ) ;
V_287 = F_135 ( V_4 , V_250 -> V_306 , V_250 -> V_307 ,
V_286 , & V_297 , V_8 -> V_308 , 0 ,
V_309 ) ;
V_287 = F_135 ( V_4 , V_250 -> V_310 , V_250 -> V_311 ,
V_286 , & V_297 , V_8 -> V_308 , V_287 ,
V_312 ) ;
V_287 = F_135 ( V_4 , V_250 -> V_313 , V_250 -> V_314 ,
V_286 , & V_297 , V_8 -> V_308 , V_287 ,
V_315 ) ;
V_8 -> V_316 = V_287 ;
for ( V_66 = 0 ; V_66 < V_287 ; V_66 ++ ) {
T_1 V_301 = V_8 -> V_308 [ V_66 ] . V_301 ;
if ( ! V_301 || ( V_301 & V_302 ) )
continue;
switch ( V_8 -> V_308 [ V_66 ] . type ) {
case V_309 :
V_8 -> V_317 [ V_8 -> V_9 . V_94 ] = V_301 ;
V_8 -> V_9 . V_94 ++ ;
break;
case V_312 :
case V_315 :
if ( ! V_8 -> V_9 . V_318 ) {
V_8 -> V_9 . V_318 = V_301 ;
break;
}
for ( V_305 = 0 ; V_305 < F_69 ( V_8 -> V_9 . V_319 ) ; V_305 ++ )
if ( ! V_8 -> V_9 . V_319 [ V_305 ] ) {
V_8 -> V_9 . V_319 [ V_305 ] = V_301 ;
break;
}
break;
}
}
V_8 -> V_9 . V_32 = V_8 -> V_317 ;
V_8 -> V_9 . V_30 = V_8 -> V_9 . V_94 * 2 ;
for ( V_66 = 0 ; V_66 < V_250 -> V_311 ; V_66 ++ ) {
if ( F_137 ( V_4 , V_250 -> V_310 [ V_66 ] ) ) {
V_8 -> V_320 = 1 ;
break;
}
}
if ( V_8 -> V_320 &&
V_250 -> V_306 [ 0 ] &&
V_250 -> V_321 != V_315 &&
V_250 -> V_306 [ 0 ] != V_250 -> V_310 [ 0 ] &&
V_250 -> V_306 [ 0 ] != V_250 -> V_313 [ 0 ] ) {
for ( V_66 = 0 ; V_66 < V_250 -> V_307 ; V_66 ++ ) {
if ( F_137 ( V_4 , V_250 -> V_306 [ V_66 ] ) ) {
V_8 -> V_322 = 1 ;
break;
}
}
V_8 -> V_323 = V_8 -> V_322 ;
}
V_8 -> V_73 = V_8 -> V_317 [ 0 ] ;
}
static void F_138 ( struct V_3 * V_4 , int V_248 ,
T_1 * V_296 , bool V_324 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_248 ; V_66 ++ )
F_81 ( V_4 , V_296 [ V_66 ] , 0 ,
V_174 ,
V_324 ? V_175 : 0 ) ;
if ( V_8 -> V_325 )
F_139 ( V_4 , V_248 , V_296 , V_324 ) ;
}
static int F_140 ( struct V_3 * V_4 , int V_248 , T_1 * V_296 )
{
int V_66 , V_102 = 0 ;
for ( V_66 = 0 ; V_66 < V_248 ; V_66 ++ ) {
T_1 V_31 = V_296 [ V_66 ] ;
if ( ! V_31 || ! F_137 ( V_4 , V_31 ) )
break;
V_102 |= F_61 ( V_4 , V_31 ) ;
}
return V_102 ;
}
static void F_141 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_303 * V_250 = & V_8 -> V_304 ;
int V_324 = 1 ;
if ( V_8 -> V_325 ) {
if ( V_8 -> V_320 )
V_324 = V_8 -> V_96 ;
F_139 ( V_4 , V_250 -> V_311 , V_250 -> V_310 , V_324 ) ;
}
if ( V_8 -> V_320 )
V_324 = ! ( V_8 -> V_96 ||
( V_8 -> V_322 && V_8 -> V_326 ) ) ;
F_138 ( V_4 , V_250 -> V_314 , V_250 -> V_313 , V_324 ) ;
if ( V_250 -> V_306 [ 0 ] == V_250 -> V_310 [ 0 ] ||
V_250 -> V_306 [ 0 ] == V_250 -> V_313 [ 0 ] )
return;
if ( V_8 -> V_320 ) {
if ( V_250 -> V_321 == V_315 ||
V_8 -> V_323 )
V_324 = ! V_8 -> V_96 ;
else
V_324 = 1 ;
}
F_138 ( V_4 , V_250 -> V_307 , V_250 -> V_306 , V_324 ) ;
}
static void F_142 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_303 * V_250 = & V_8 -> V_304 ;
if ( ! V_8 -> V_320 )
return;
V_8 -> V_96 = F_140 ( V_4 , V_250 -> V_311 , V_250 -> V_310 ) ;
F_141 ( V_4 ) ;
}
static void F_143 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_303 * V_250 = & V_8 -> V_304 ;
if ( ! V_8 -> V_320 || ! V_8 -> V_322 )
return;
V_8 -> V_326 = F_140 ( V_4 , V_250 -> V_307 ,
V_250 -> V_306 ) ;
F_141 ( V_4 ) ;
}
static int F_144 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
static const char * const V_327 [] = {
L_14 , L_15
} ;
static const char * const V_328 [] = {
L_14 , L_16 , L_17
} ;
const char * const * V_329 ;
V_50 -> type = V_330 ;
V_50 -> V_331 = 1 ;
if ( V_8 -> V_332 ) {
V_50 -> V_56 . V_57 . V_214 = 3 ;
V_329 = V_328 ;
} else {
V_50 -> V_56 . V_57 . V_214 = 2 ;
V_329 = V_327 ;
}
if ( V_50 -> V_56 . V_57 . V_58 >= V_50 -> V_56 . V_57 . V_214 )
V_50 -> V_56 . V_57 . V_58 = V_50 -> V_56 . V_57 . V_214 - 1 ;
strcpy ( V_50 -> V_56 . V_57 . V_25 ,
V_329 [ V_50 -> V_56 . V_57 . V_58 ] ) ;
return 0 ;
}
static int F_145 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_333 ;
if ( ! V_8 -> V_320 )
V_333 = 0 ;
else if ( ! V_8 -> V_323 )
V_333 = 1 ;
else
V_333 = 2 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_333 ;
return 0 ;
}
static int F_146 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
switch ( V_53 -> V_56 . V_57 . V_58 [ 0 ] ) {
case 0 :
if ( ! V_8 -> V_320 )
return 0 ;
V_8 -> V_320 = 0 ;
break;
case 1 :
if ( V_8 -> V_320 && ! V_8 -> V_323 )
return 0 ;
V_8 -> V_320 = 1 ;
V_8 -> V_323 = 0 ;
break;
case 2 :
if ( ! V_8 -> V_332 )
return - V_334 ;
if ( V_8 -> V_320 && V_8 -> V_323 )
return 0 ;
V_8 -> V_320 = 1 ;
V_8 -> V_323 = 1 ;
break;
default:
return - V_334 ;
}
F_141 ( V_4 ) ;
return 1 ;
}
static int F_147 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_22 ( & V_8 -> V_335 , V_50 ) ;
}
static int F_148 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_59 [ 0 ] ;
return 0 ;
}
static int F_149 ( struct V_3 * V_4 , T_1 V_336 ,
T_1 V_285 , T_1 * V_337 ,
bool V_338 , int V_339 )
{
T_1 V_340 [ V_341 ] ;
int V_66 , V_287 ;
switch ( F_134 ( F_133 ( V_4 , V_336 ) ) ) {
case V_342 :
case V_343 :
case V_344 :
break;
default:
return - 1 ;
}
V_287 = F_124 ( V_4 , V_336 , V_340 , F_69 ( V_340 ) ) ;
for ( V_66 = 0 ; V_66 < V_287 ; V_66 ++ )
if ( V_340 [ V_66 ] == V_285 ) {
if ( V_338 )
F_81 ( V_4 , V_336 , 0 ,
V_179 , V_66 ) ;
if ( V_337 )
* V_337 = V_336 ;
return V_66 ;
}
V_339 ++ ;
if ( V_339 == 2 )
return - 1 ;
for ( V_66 = 0 ; V_66 < V_287 ; V_66 ++ ) {
int V_288 = F_149 ( V_4 , V_340 [ V_66 ] , V_285 , V_337 ,
V_338 , V_339 ) ;
if ( V_288 >= 0 ) {
if ( V_338 )
F_81 ( V_4 , V_336 , 0 ,
V_179 , V_66 ) ;
return V_66 ;
}
}
return - 1 ;
}
static void F_150 ( struct V_3 * V_4 , T_1 V_336 ,
T_1 V_285 )
{
F_149 ( V_4 , V_336 , V_285 , NULL , true , 0 ) ;
}
static int F_151 ( struct V_3 * V_4 , T_1 V_336 ,
T_1 V_285 )
{
return F_149 ( V_4 , V_336 , V_285 , NULL , false , 0 ) ;
}
static int F_152 ( struct V_3 * V_4 ,
const struct V_242 * V_243 ,
unsigned int V_244 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_282 ;
int V_345 = 1 ;
if ( ! V_243 -> V_245 )
return 0 ;
if ( V_244 >= V_243 -> V_245 )
V_244 = V_243 -> V_245 - 1 ;
if ( V_8 -> V_59 [ 0 ] == V_244 )
V_345 = 0 ;
V_282 = V_8 -> V_283 [ V_244 ] . V_282 ;
F_150 ( V_4 , V_8 -> V_283 [ V_244 ] . V_282 ,
V_8 -> V_283 [ V_244 ] . V_285 ) ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_282 ) {
F_85 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_282 ;
F_14 ( V_4 , V_282 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
V_8 -> V_59 [ 0 ] = V_244 ;
return V_345 ;
}
static int F_153 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_152 ( V_4 , & V_8 -> V_335 ,
V_53 -> V_56 . V_57 . V_58 [ 0 ] ) ;
}
static bool F_154 ( struct V_3 * V_4 , int V_244 , bool V_346 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_244 < 0 )
return false ;
if ( V_346 && ! F_61 ( V_4 , V_8 -> V_283 [ V_244 ] . V_285 ) )
return false ;
F_152 ( V_4 , & V_8 -> V_335 , V_244 ) ;
return true ;
}
static void F_155 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_177 )
return;
if ( ! F_154 ( V_4 , V_8 -> V_347 , true ) )
if ( ! F_154 ( V_4 , V_8 -> V_348 , true ) )
F_154 ( V_4 , V_8 -> V_349 , false ) ;
}
static void F_156 ( struct V_3 * V_4 , unsigned int V_103 )
{
switch ( F_157 ( V_4 , V_103 >> 26 ) ) {
case V_104 :
F_142 ( V_4 ) ;
break;
case V_350 :
F_143 ( V_4 ) ;
break;
case V_105 :
F_155 ( V_4 ) ;
break;
}
F_158 ( V_4 ) ;
}
static void F_159 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_351 [ V_352 + 1 ] ;
int V_66 ;
for ( V_66 = 0 ; V_66 < F_69 ( V_351 ) ; V_66 ++ )
V_351 [ V_66 ] = - 1 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_335 . V_245 ; V_66 ++ ) {
T_1 V_285 = V_8 -> V_283 [ V_66 ] . V_285 ;
unsigned int V_353 = F_122 ( V_4 , V_285 ) ;
int type , V_354 ;
V_354 = F_160 ( V_353 ) ;
if ( V_354 == V_355 )
return;
if ( V_354 > V_352 )
V_354 = V_352 ;
if ( V_354 != V_356 &&
! F_137 ( V_4 , V_285 ) )
return;
type = F_161 ( V_353 ) ;
if ( type != V_357 &&
( V_354 != V_358 || type != V_359 ) )
return;
if ( V_351 [ V_354 ] >= 0 )
return;
V_351 [ V_354 ] = V_66 ;
}
if ( V_351 [ V_356 ] < 0 ||
( V_351 [ V_352 ] < 0 && V_351 [ V_358 ] ) )
return;
V_8 -> V_177 = 1 ;
V_8 -> V_347 = V_351 [ V_352 ] ;
V_8 -> V_348 = V_351 [ V_358 ] ;
V_8 -> V_349 = V_351 [ V_356 ] ;
}
static void F_162 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_303 * V_250 = & V_8 -> V_304 ;
struct V_242 * V_243 ;
int V_66 , V_305 ;
V_243 = & V_8 -> V_335 ;
for ( V_66 = 0 ; V_66 < V_250 -> V_360 ; V_66 ++ ) {
for ( V_305 = 0 ; V_305 < V_8 -> V_39 ; V_305 ++ ) {
T_1 V_282 = V_8 -> V_13 [ V_305 ] ;
int V_244 = F_151 ( V_4 , V_282 ,
V_250 -> V_361 [ V_66 ] . V_285 ) ;
if ( V_244 >= 0 ) {
const char * V_362 ;
V_362 = F_163 ( V_4 , V_250 , V_66 ) ;
V_8 -> V_283 [ V_243 -> V_245 ] . V_216 = V_66 ;
V_8 -> V_283 [ V_243 -> V_245 ] . V_363 = 0 ;
V_8 -> V_283 [ V_243 -> V_245 ] . V_282 = V_282 ;
V_8 -> V_283 [ V_243 -> V_245 ] . V_285 =
V_250 -> V_361 [ V_66 ] . V_285 ;
F_164 ( V_243 , V_362 , V_244 , NULL ) ;
break;
}
}
}
if ( V_243 -> V_245 >= 2 && V_250 -> V_360 == V_243 -> V_245 )
F_159 ( V_4 ) ;
if ( V_243 -> V_245 > 1 ) {
for ( V_66 = 1 ; V_66 < V_243 -> V_245 ; V_66 ++ ) {
if ( V_8 -> V_283 [ V_66 ] . V_282 != V_8 -> V_283 [ 0 ] . V_282 ) {
V_8 -> V_284 = 1 ;
break;
}
}
}
}
static T_1 F_165 ( struct V_3 * V_4 , T_1 V_285 )
{
T_1 V_31 , V_289 ;
V_289 = V_4 -> V_290 + V_4 -> V_291 ;
for ( V_31 = V_4 -> V_290 ; V_31 < V_289 ; V_31 ++ ) {
unsigned int V_292 = F_133 ( V_4 , V_31 ) ;
unsigned int type = F_134 ( V_292 ) ;
if ( type == V_342 && ( V_292 & V_294 ) ) {
if ( F_131 ( V_4 , V_31 , V_285 ) >= 0 )
return V_31 ;
}
}
return 0 ;
}
static void F_166 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_303 * V_250 = & V_8 -> V_304 ;
T_1 V_31 ;
if ( V_250 -> V_364 &&
F_124 ( V_4 , V_250 -> V_365 [ 0 ] , & V_31 , 1 ) == 1 )
V_8 -> V_9 . V_40 = V_31 ;
if ( V_250 -> V_366 )
V_8 -> V_44 = F_165 ( V_4 , V_250 -> V_366 ) ;
}
static void F_167 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_289 ;
V_289 = V_4 -> V_290 + V_4 -> V_291 ;
for ( V_31 = V_4 -> V_290 ; V_31 < V_289 ; V_31 ++ )
if ( F_134 ( F_133 ( V_4 , V_31 ) ) == V_367 ) {
F_70 ( V_8 , V_31 , 0 , V_75 ) ;
break;
}
}
static void F_168 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_289 ;
V_289 = V_4 -> V_290 + V_4 -> V_291 ;
for ( V_31 = V_4 -> V_290 ; V_31 < V_289 ; V_31 ++ ) {
if ( F_134 ( F_133 ( V_4 , V_31 ) ) != V_368 )
continue;
if ( ! ( F_169 ( V_4 , V_31 ) & V_369 ) )
continue;
V_8 -> V_370 [ V_8 -> V_371 ++ ] = V_31 ;
if ( V_8 -> V_371 >= F_69 ( V_8 -> V_370 ) )
break;
}
V_8 -> V_325 = V_8 -> V_371 > 2 ;
}
static int F_170 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_69 ;
V_69 = F_171 ( V_4 , & V_8 -> V_304 , NULL ) ;
if ( V_69 < 0 )
return V_69 ;
F_136 ( V_4 ) ;
F_162 ( V_4 ) ;
F_166 ( V_4 ) ;
F_167 ( V_4 ) ;
F_168 ( V_4 ) ;
return 0 ;
}
static void F_139 ( struct V_3 * V_4 , int V_248 ,
T_1 * V_296 , bool V_324 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_248 ; V_66 ++ ) {
if ( F_169 ( V_4 , V_296 [ V_66 ] ) & V_369 )
F_81 ( V_4 , V_296 [ V_66 ] , 0 ,
V_90 ,
V_324 ? 0x02 : 0 ) ;
}
}
static void F_172 ( struct V_3 * V_4 , T_1 V_285 ,
T_1 V_372 )
{
int V_244 = F_131 ( V_4 , V_285 , V_372 ) ;
if ( V_244 >= 0 )
F_81 ( V_4 , V_285 , 0 ,
V_179 , V_244 ) ;
}
static void F_173 ( struct V_3 * V_4 , int V_373 ,
const T_1 * V_374 )
{
int V_66 , V_333 ;
for ( V_66 = 0 ; V_66 < V_373 ; V_66 ++ ) {
T_1 V_31 = V_374 [ V_66 ] ;
if ( ! ( F_133 ( V_4 , V_31 ) & V_375 ) )
continue;
if ( F_174 ( V_4 , V_31 , V_75 ) & V_376 )
V_333 = V_148 ;
else
V_333 = V_377 ;
F_81 ( V_4 , V_31 , 0 ,
V_100 , V_333 ) ;
}
}
static void F_175 ( struct V_3 * V_4 , int V_248 ,
T_1 * V_296 , unsigned int V_378 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_248 ; V_66 ++ )
F_176 ( V_4 , V_296 [ V_66 ] , V_378 ) ;
}
static void F_177 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_303 * V_250 = & V_8 -> V_304 ;
T_1 V_31 ;
int V_66 ;
F_173 ( V_4 , V_8 -> V_9 . V_94 , V_8 -> V_9 . V_32 ) ;
for ( V_66 = 0 ; V_66 < V_250 -> V_311 ; V_66 ++ )
F_81 ( V_4 , V_250 -> V_310 [ V_66 ] , 0 ,
V_174 , V_173 ) ;
F_173 ( V_4 , V_250 -> V_311 , V_250 -> V_310 ) ;
F_173 ( V_4 , V_250 -> V_307 , V_250 -> V_306 ) ;
F_173 ( V_4 , V_250 -> V_314 , V_250 -> V_313 ) ;
for ( V_66 = 0 ; V_66 < V_8 -> V_316 ; V_66 ++ ) {
V_31 = V_8 -> V_308 [ V_66 ] . V_301 ;
if ( ! V_31 )
V_31 = V_8 -> V_9 . V_32 [ 0 ] ;
else if ( V_31 & V_302 )
V_31 &= ~ V_302 ;
F_172 ( V_4 , V_8 -> V_308 [ V_66 ] . V_285 , V_31 ) ;
}
if ( V_8 -> V_320 ) {
F_175 ( V_4 , V_250 -> V_311 , V_250 -> V_310 ,
V_104 ) ;
V_8 -> V_96 = F_140 ( V_4 , V_250 -> V_311 ,
V_250 -> V_310 ) ;
if ( V_8 -> V_322 ) {
F_175 ( V_4 , V_250 -> V_307 ,
V_250 -> V_306 ,
V_350 ) ;
V_8 -> V_326 =
F_140 ( V_4 , V_250 -> V_307 ,
V_250 -> V_306 ) ;
}
}
F_141 ( V_4 ) ;
if ( ! V_8 -> V_325 )
F_139 ( V_4 , V_8 -> V_371 , V_8 -> V_370 , true ) ;
}
static void F_178 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_303 * V_250 = & V_8 -> V_304 ;
int V_66 , V_333 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_39 ; V_66 ++ ) {
T_1 V_31 = V_8 -> V_13 [ V_66 ] ;
if ( ! ( F_133 ( V_4 , V_31 ) & V_379 ) )
continue;
if ( F_174 ( V_4 , V_31 , V_143 ) & V_376 )
V_333 = F_179 ( 0 ) ;
else
V_333 = F_180 ( 0 ) ;
F_81 ( V_4 , V_31 , 0 , V_100 ,
V_333 ) ;
}
for ( V_66 = 0 ; V_66 < V_250 -> V_360 ; V_66 ++ ) {
unsigned int type ;
if ( V_250 -> V_361 [ V_66 ] . type == V_380 )
type = V_223 ;
else
type = V_220 ;
F_81 ( V_4 , V_250 -> V_361 [ V_66 ] . V_285 , 0 ,
V_174 , type ) ;
}
if ( V_8 -> V_177 ) {
if ( V_8 -> V_347 >= 0 ) {
F_176 ( V_4 ,
V_250 -> V_361 [ V_8 -> V_347 ] . V_285 ,
V_105 ) ;
}
if ( V_8 -> V_348 >= 0 ) {
F_176 ( V_4 ,
V_250 -> V_361 [ V_8 -> V_348 ] . V_285 ,
V_105 ) ;
}
F_155 ( V_4 ) ;
} else {
F_150 ( V_4 , V_8 -> V_283 [ 0 ] . V_282 ,
V_8 -> V_283 [ 0 ] . V_285 ) ;
}
}
static void F_181 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_303 * V_250 = & V_8 -> V_304 ;
if ( V_8 -> V_9 . V_40 )
F_81 ( V_4 , V_250 -> V_365 [ 0 ] , 0 ,
V_174 , V_175 ) ;
if ( V_8 -> V_44 )
F_81 ( V_4 , V_250 -> V_366 , 0 ,
V_174 , V_220 ) ;
}
static int F_182 ( struct V_3 * V_4 )
{
F_177 ( V_4 ) ;
F_178 ( V_4 ) ;
F_181 ( V_4 ) ;
F_158 ( V_4 ) ;
return 0 ;
}
static int F_183 ( struct V_3 * V_4 , const char * V_381 ,
const char * V_382 , int V_383 ,
T_1 V_31 , int V_384 , int V_385 )
{
static char V_25 [ 32 ] ;
static struct V_80 V_81 [] = {
F_184 ( V_25 , 0 , 0 , 0 ) ,
F_185 ( V_25 , 0 , 0 , 0 ) ,
} ;
static const char * const V_386 [ 2 ] = { L_18 , L_19 } ;
int V_66 , V_69 ;
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
struct V_47 * V_83 ;
V_81 [ V_66 ] . V_85 = F_186 ( V_31 , 3 , V_385 ,
V_384 ) ;
V_81 [ V_66 ] . V_387 = V_388 ;
V_81 [ V_66 ] . V_216 = V_383 ;
snprintf ( V_25 , sizeof( V_25 ) , L_20 , V_381 , V_382 , V_386 [ V_66 ] ) ;
V_83 = F_45 ( & V_81 [ V_66 ] , V_4 ) ;
if ( ! V_83 )
return - V_84 ;
V_69 = F_46 ( V_4 , V_31 , V_83 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( ! ( F_174 ( V_4 , V_31 , V_384 ) &
( V_376 | V_389 ) ) )
break;
}
return 0 ;
}
static int F_187 ( struct V_3 * V_4 , T_1 V_301 ,
T_1 V_285 , const char * V_25 , int V_244 )
{
unsigned int V_390 ;
if ( V_301 && ! ( V_301 & V_302 ) ) {
V_390 = F_174 ( V_4 , V_301 , V_75 ) ;
if ( V_390 & V_391 )
return F_188 ( V_4 , V_301 , V_25 , V_244 ) ;
}
V_390 = F_174 ( V_4 , V_285 , V_75 ) ;
if ( V_390 & V_391 )
return F_188 ( V_4 , V_285 , V_25 , V_244 ) ;
return 0 ;
}
static int F_189 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 , V_69 ;
int V_392 = 0 , V_393 = 0 , V_394 = 0 ;
static const char * const V_329 [ 3 ] = { L_21 , L_22 , L_23 } ;
if ( V_8 -> V_316 == 1 )
return F_187 ( V_4 , V_8 -> V_308 [ 0 ] . V_301 ,
V_8 -> V_308 [ 0 ] . V_285 ,
L_24 , 0 ) ;
for ( V_66 = 0 ; V_66 < V_8 -> V_316 ; V_66 ++ ) {
const char * V_362 ;
int V_244 , type ;
T_1 V_301 = V_8 -> V_308 [ V_66 ] . V_301 ;
type = V_8 -> V_308 [ V_66 ] . type ;
if ( type == V_309 )
type = V_8 -> V_304 . V_321 ;
switch ( type ) {
case V_309 :
default:
V_362 = V_329 [ V_392 ++ ] ;
V_244 = 0 ;
break;
case V_312 :
V_362 = L_25 ;
V_244 = V_393 ++ ;
break;
case V_315 :
V_362 = L_26 ;
V_244 = V_394 ++ ;
break;
}
V_69 = F_187 ( V_4 , V_301 ,
V_8 -> V_308 [ V_66 ] . V_285 ,
V_362 , V_244 ) ;
if ( V_69 < 0 )
return V_69 ;
}
if ( V_8 -> V_320 ) {
V_69 = F_37 ( V_4 , V_395 ) ;
if ( V_69 < 0 )
return V_69 ;
}
return 0 ;
}
static int F_190 ( struct V_3 * V_4 , T_1 V_31 ,
const char * V_362 , const char * V_396 ,
int V_383 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_39 ; V_66 ++ ) {
T_1 V_397 = V_8 -> V_13 [ V_66 ] ;
int V_244 = F_151 ( V_4 , V_397 , V_31 ) ;
if ( V_244 < 0 )
continue;
if ( V_8 -> V_398 )
V_244 = 0 ;
return F_183 ( V_4 , V_362 , V_396 ,
V_383 , V_397 , V_143 , V_244 ) ;
}
return 0 ;
}
static int F_191 ( struct V_3 * V_4 , int V_244 ,
const char * V_362 , int V_383 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_336 , V_31 ;
int V_66 , V_399 ;
V_31 = V_8 -> V_283 [ V_244 ] . V_285 ;
if ( F_133 ( V_4 , V_31 ) & V_379 )
return F_192 ( V_4 , V_362 , L_27 , V_383 ,
V_31 , V_143 ) ;
V_399 = F_149 ( V_4 , V_8 -> V_283 [ V_244 ] . V_282 , V_31 ,
& V_336 , false , 0 ) ;
if ( V_399 < 0 )
return 0 ;
for ( V_66 = 0 ; V_66 < V_244 ; V_66 ++ ) {
if ( V_8 -> V_283 [ V_66 ] . V_363 == V_336 )
return 0 ;
}
if ( F_133 ( V_4 , V_336 ) & V_375 ) {
V_8 -> V_283 [ V_244 ] . V_363 = V_336 ;
return F_192 ( V_4 , V_362 , L_27 , 0 ,
V_336 , V_75 ) ;
}
return 0 ;
}
static int F_193 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_242 * V_243 = & V_8 -> V_335 ;
const char * V_400 ;
int V_401 [ V_341 ] ;
int V_66 , V_305 , V_69 , V_383 ;
int V_402 ;
if ( ! V_243 -> V_245 )
return 0 ;
V_402 = 0 ;
for ( V_66 = 0 ; V_66 < V_243 -> V_245 ; V_66 ++ ) {
V_383 = F_151 ( V_4 , V_8 -> V_283 [ V_66 ] . V_282 ,
V_8 -> V_283 [ V_66 ] . V_285 ) ;
if ( V_383 < 0 )
continue;
V_401 [ V_66 ] = V_8 -> V_283 [ V_66 ] . V_282 ;
if ( ! V_8 -> V_398 )
V_401 [ V_66 ] |= V_383 << 8 ;
if ( V_66 > 0 && V_401 [ V_66 ] != V_401 [ 0 ] )
V_402 = 1 ;
}
V_400 = NULL ;
V_383 = 0 ;
for ( V_66 = 0 ; V_66 < V_243 -> V_245 ; V_66 ++ ) {
T_1 V_31 = V_8 -> V_283 [ V_66 ] . V_285 ;
const char * V_362 ;
V_362 = F_163 ( V_4 , & V_8 -> V_304 ,
V_8 -> V_283 [ V_66 ] . V_216 ) ;
if ( V_362 == V_400 )
V_383 ++ ;
else
V_383 = 0 ;
V_400 = V_362 ;
V_69 = F_191 ( V_4 , V_66 , V_362 , V_383 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( ! V_402 ) {
if ( V_66 > 0 )
continue;
V_69 = F_190 ( V_4 , V_31 ,
L_28 , L_29 , V_383 ) ;
} else {
bool V_403 = false ;
for ( V_305 = 0 ; V_305 < V_66 ; V_305 ++ ) {
if ( V_401 [ V_305 ] == V_401 [ V_66 ] ) {
V_403 = true ;
break;
}
}
if ( V_403 )
continue;
V_69 = F_190 ( V_4 , V_31 ,
V_362 , L_30 , V_383 ) ;
}
if ( V_69 < 0 )
return V_69 ;
}
if ( V_8 -> V_335 . V_245 > 1 && ! V_8 -> V_177 ) {
V_69 = F_37 ( V_4 , V_404 ) ;
if ( V_69 < 0 )
return V_69 ;
}
return 0 ;
}
static int F_194 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_69 ;
V_69 = F_189 ( V_4 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_193 ( V_4 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_36 ( V_4 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_195 ( V_4 , & V_8 -> V_304 ) ;
if ( V_69 < 0 )
return V_69 ;
return 0 ;
}
static int F_196 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_289 ;
V_289 = V_4 -> V_290 + V_4 -> V_291 ;
for ( V_31 = V_4 -> V_290 ; V_31 < V_289 ; V_31 ++ ) {
unsigned int V_390 = F_133 ( V_4 , V_31 ) ;
if ( F_134 ( V_390 ) != V_342 )
continue;
if ( V_390 & V_294 )
continue;
if ( F_197 ( V_8 -> V_39 >=
F_69 ( V_8 -> V_405 ) ) )
break;
V_8 -> V_405 [ V_8 -> V_39 ++ ] = V_31 ;
}
V_8 -> V_13 = V_8 -> V_405 ;
return 0 ;
}
static void F_198 ( struct V_3 * V_4 , const struct V_406 * V_250 )
{
for (; V_250 -> V_31 ; V_250 ++ )
F_199 ( V_4 , V_250 -> V_31 , V_250 -> V_333 ) ;
}
static void F_200 ( struct V_3 * V_4 ,
const struct V_407 * V_408 ,
const struct V_406 * * V_409 )
{
V_408 = F_201 ( V_4 -> V_410 -> V_411 , V_408 ) ;
if ( V_408 ) {
F_92 ( V_412 L_31 ,
V_408 -> V_25 ) ;
F_198 ( V_4 , V_409 [ V_408 -> V_56 ] ) ;
}
}
static void F_202 ( struct V_3 * V_4 )
{
static T_1 V_413 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_414 ;
for ( V_414 = V_413 ; * V_414 ; V_414 ++ )
F_72 ( V_4 , * V_414 , V_75 ,
V_389 |
F_174 ( V_4 , * V_414 , V_75 ) ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_69 ;
F_203 ( V_412 L_32 ,
V_4 -> V_415 ) ;
V_8 = F_68 ( sizeof( * V_8 ) , V_111 ) ;
if ( ! V_8 )
return - V_84 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_112 = 1 ;
switch ( V_4 -> V_35 ) {
case 0x14f15045 :
V_8 -> V_398 = 1 ;
break;
case 0x14f15051 :
F_202 ( V_4 ) ;
break;
}
F_200 ( V_4 , V_416 , V_417 ) ;
V_69 = F_196 ( V_4 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_170 ( V_4 ) ;
if ( V_69 < 0 ) {
F_35 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
return V_69 ;
}
V_8 -> V_33 = & V_418 ;
V_4 -> V_122 = V_419 ;
if ( V_8 -> V_79 )
F_73 ( V_4 , V_8 -> V_79 ) ;
return 0 ;
}
static int T_3 F_204 ( void )
{
return F_205 ( & V_420 ) ;
}
static void T_4 F_206 ( void )
{
F_207 ( & V_420 ) ;
}
