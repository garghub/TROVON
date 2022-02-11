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
static void F_31 ( struct V_3 * V_4 , T_1 V_74 ,
unsigned int V_75 )
{
if ( V_75 == V_76 )
F_32 ( 100 ) ;
F_33 ( V_4 , V_74 , 0 , V_77 ,
V_75 ) ;
if ( V_75 == V_78 )
F_32 ( 10 ) ;
F_34 ( V_4 , V_74 , V_75 , true ) ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_62 ; V_61 ++ )
F_36 ( V_4 , V_8 -> V_65 [ V_61 ] ) ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 )
{
F_38 ( V_4 ) ;
F_39 ( V_4 ) ;
F_40 ( V_4 -> V_8 ) ;
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_61 ;
int V_66 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_79 ; V_61 ++ ) {
V_66 = F_42 ( V_4 , V_8 -> V_80 [ V_61 ] ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_9 . V_40 ) {
V_66 = F_43 ( V_4 ,
V_8 -> V_9 . V_40 ,
V_8 -> V_9 . V_40 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_44 ( V_4 ,
& V_8 -> V_9 ) ;
if ( V_66 < 0 )
return V_66 ;
V_8 -> V_9 . V_81 = 1 ;
}
if ( V_8 -> V_44 ) {
V_66 = F_45 ( V_4 , V_8 -> V_44 ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_82 &&
! F_46 ( V_4 , L_3 ) ) {
unsigned int V_83 [ 4 ] ;
F_47 ( V_4 , V_8 -> V_82 ,
V_84 , V_83 ) ;
V_66 = F_48 ( V_4 , L_3 ,
V_83 , V_85 ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_82 &&
! F_46 ( V_4 , L_4 ) ) {
V_66 = F_48 ( V_4 , L_4 ,
NULL , V_86 ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_51 ) {
V_66 = F_42 ( V_4 , V_87 ) ;
if ( V_66 < 0 )
return V_66 ;
}
#ifdef F_49
if ( V_8 -> V_88 ) {
const struct V_89 * V_90 ;
for ( V_90 = V_91 ; V_90 -> V_25 ; V_90 ++ ) {
struct V_47 * V_92 ;
V_92 = F_50 ( V_90 , V_4 ) ;
if ( ! V_92 )
return - V_93 ;
V_92 -> V_94 = V_8 -> V_88 ;
V_66 = F_51 ( V_4 , 0 , V_92 ) ;
if ( V_66 < 0 )
return V_66 ;
}
}
#endif
return 0 ;
}
static int F_52 ( struct V_3 * V_4 , T_2 V_95 )
{
F_53 ( V_4 ) ;
return 0 ;
}
static int F_54 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_96 = ( V_48 -> V_94 >> 8 ) & 1 ;
if ( V_96 )
V_53 -> V_56 . integer . V_56 [ 0 ] = ! V_8 -> V_97 ;
else
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_97 ;
return 0 ;
}
static int F_55 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_96 = ( V_48 -> V_94 >> 8 ) & 1 ;
T_1 V_31 = V_48 -> V_94 & 0xff ;
unsigned int V_98 ;
V_98 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_96 )
V_98 = ! V_98 ;
if ( V_98 == V_8 -> V_97 )
return 0 ;
V_8 -> V_97 = V_98 ;
F_56 ( V_4 , V_31 ,
0 , V_99 ,
V_98 ? 0x02 : 0x00 ) ;
return 1 ;
}
static int F_57 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_58 ( V_4 , V_50 , V_8 -> V_100 ,
V_8 -> V_101 ) ;
}
static int F_59 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_60 ( V_4 , V_53 , V_8 -> V_100 ,
V_8 -> V_101 ,
V_8 -> V_9 . V_30 ) ;
}
static int F_61 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 = F_62 ( V_4 , V_53 , V_8 -> V_100 ,
V_8 -> V_101 ,
& V_8 -> V_9 . V_30 ) ;
if ( V_66 >= 0 && V_8 -> V_102 )
V_8 -> V_9 . V_103 = V_8 -> V_9 . V_30 / 2 ;
return V_66 ;
}
static int F_63 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_104 ;
if ( ! F_55 ( V_48 , V_53 ) )
return 0 ;
V_104 = ( ! V_8 -> V_105 && V_8 -> V_97 ) ? 0 : V_106 ;
F_64 ( V_4 , 0x10 , V_84 , 0 ,
V_106 , V_104 ) ;
V_104 = V_8 -> V_97 ? 0 : V_106 ;
F_64 ( V_4 , 0x11 , V_84 , 0 ,
V_106 , V_104 ) ;
return 1 ;
}
static void F_65 ( struct V_3 * V_4 )
{
static const struct V_63 V_107 [] = {
{ 0x14 , V_108 , 0xb080 } ,
{ 0x12 , V_108 , 0xb000 } ,
{}
} ;
static const struct V_63 V_109 [] = {
{ 0x12 , V_108 , 0xb080 } ,
{ 0x14 , V_108 , 0xb000 } ,
{}
} ;
unsigned int V_110 ;
V_110 = F_66 ( V_4 , 0x12 ) ;
if ( V_110 )
F_36 ( V_4 , V_107 ) ;
else
F_36 ( V_4 , V_109 ) ;
}
static void F_67 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_104 ;
V_8 -> V_105 = F_66 ( V_4 , 0x11 ) ;
V_104 = ( V_8 -> V_105 || ! V_8 -> V_97 ) ? V_106 : 0 ;
F_64 ( V_4 , 0x10 , V_84 , 0 ,
V_106 , V_104 ) ;
}
static void F_68 ( struct V_3 * V_4 ,
unsigned int V_111 )
{
V_111 >>= 26 ;
switch ( V_111 ) {
case V_69 :
F_67 ( V_4 ) ;
break;
case V_72 :
F_65 ( V_4 ) ;
break;
}
}
static int F_69 ( struct V_3 * V_4 )
{
F_35 ( V_4 ) ;
F_67 ( V_4 ) ;
return 0 ;
}
static int F_70 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_112 ;
V_112 = F_71 ( V_4 , V_113 ,
V_114 ,
V_115 ) ;
if ( V_112 < 0 )
V_112 = V_116 ;
if ( V_112 == V_116 )
return F_72 ( V_4 ) ;
V_8 = F_73 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 )
return - V_93 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_118 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_103 = F_74 ( V_119 ) ;
V_8 -> V_9 . V_32 = V_119 ;
V_8 -> V_9 . V_40 = V_120 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_121 ;
V_8 -> V_60 = V_122 ;
V_8 -> V_51 = & V_123 ;
V_8 -> V_79 = 1 ;
V_8 -> V_80 [ 0 ] = V_124 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_125 ;
V_8 -> V_126 = 0 ;
V_8 -> V_101 = F_74 ( V_127 ) ;
V_8 -> V_100 = V_127 ;
F_75 ( V_8 , 0x16 , 0 , 1 ) ;
V_4 -> V_128 = V_129 ;
switch ( V_112 ) {
case V_130 :
V_4 -> V_128 . V_131 = F_68 ;
V_8 -> V_51 = & V_123 ;
V_8 -> V_62 = 2 ;
V_8 -> V_65 [ 1 ] = V_132 ;
V_8 -> V_80 [ 0 ] = V_124 ;
V_4 -> V_128 . V_133 = F_69 ;
break;
case V_134 :
V_4 -> V_128 . V_131 = F_68 ;
V_8 -> V_51 = & V_123 ;
V_8 -> V_62 = 2 ;
V_8 -> V_65 [ 1 ] = V_135 ;
V_8 -> V_80 [ 0 ] = V_124 ;
V_4 -> V_128 . V_133 = F_69 ;
break;
default:
case V_136 :
V_4 -> V_128 . V_131 = F_68 ;
V_8 -> V_51 = & V_123 ;
V_8 -> V_62 = 3 ;
V_8 -> V_65 [ 1 ] = V_132 ;
V_8 -> V_65 [ 2 ] = V_135 ;
V_8 -> V_80 [ 0 ] = V_124 ;
V_4 -> V_128 . V_133 = F_69 ;
break;
case V_137 :
V_4 -> V_128 . V_131 = F_68 ;
V_8 -> V_51 = & V_138 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_139 ;
V_8 -> V_80 [ 0 ] = V_124 ;
V_8 -> V_80 [ 1 ] = V_140 ;
V_8 -> V_79 = 2 ;
V_4 -> V_128 . V_133 = F_69 ;
break;
case V_141 :
V_4 -> V_128 . V_131 = F_68 ;
V_8 -> V_51 = & V_142 ;
V_8 -> V_62 = 2 ;
V_8 -> V_65 [ 1 ] = V_132 ;
V_8 -> V_80 [ 0 ] = V_143 ;
V_4 -> V_128 . V_133 = F_69 ;
break;
#ifdef F_76
case V_144 :
V_8 -> V_51 = & V_145 ;
V_8 -> V_80 [ 0 ] = V_146 ;
V_8 -> V_65 [ 0 ] = V_147 ;
break;
#endif
}
switch ( V_4 -> V_148 >> 16 ) {
case 0x103c :
case 0x1631 :
case 0x1734 :
case 0x17aa :
F_77 ( V_4 , 0x17 , V_149 ,
( 0x14 << V_150 ) |
( 0x14 << V_151 ) |
( 0x05 << V_152 ) |
( 1 << V_153 ) ) ;
break;
}
if ( V_8 -> V_88 )
F_78 ( V_4 , V_8 -> V_88 ) ;
return 0 ;
}
static int F_79 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_104 ;
if ( ! F_55 ( V_48 , V_53 ) )
return 0 ;
V_104 = ( ! V_8 -> V_105 && V_8 -> V_97 ) ? 0 : V_106 ;
F_64 ( V_4 , 0x1d , V_84 , 0x01 ,
V_106 , V_104 ) ;
V_104 = V_8 -> V_97 ? 0 : V_106 ;
F_64 ( V_4 , 0x13 , V_84 , 0 ,
V_106 , V_104 ) ;
return 1 ;
}
static void F_80 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_104 ;
V_8 -> V_105 = F_66 ( V_4 , 0x13 ) ;
V_104 = ( V_8 -> V_105 || ! V_8 -> V_97 ) ? V_106 : 0 ;
F_64 ( V_4 , 0x1d , V_84 , 0x01 ,
V_106 , V_104 ) ;
}
static void F_81 ( struct V_3 * V_4 )
{
static const struct V_63 V_107 [] = {
{ 0x15 , V_108 , V_154 } ,
{ 0x17 , V_108 , V_155 } ,
{}
} ;
static const struct V_63 V_109 [] = {
{ 0x17 , V_108 , V_154 } ,
{ 0x15 , V_108 , V_155 } ,
{}
} ;
unsigned int V_110 ;
V_110 = F_66 ( V_4 , 0x15 ) ;
if ( V_110 )
F_36 ( V_4 , V_107 ) ;
else
F_36 ( V_4 , V_109 ) ;
}
static void F_82 ( struct V_3 * V_4 ,
unsigned int V_111 )
{
switch ( V_111 >> 26 ) {
case V_69 :
F_80 ( V_4 ) ;
break;
case V_72 :
F_81 ( V_4 ) ;
break;
}
}
static int F_83 ( struct V_3 * V_4 )
{
F_35 ( V_4 ) ;
F_80 ( V_4 ) ;
return 0 ;
}
static int F_84 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_112 ;
V_112 = F_71 ( V_4 , V_156 ,
V_157 ,
V_158 ) ;
if ( V_112 < 0 )
V_112 = V_159 ;
if ( V_112 == V_159 )
return F_72 ( V_4 ) ;
V_8 = F_73 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 )
return - V_93 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_118 = 1 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_103 = F_74 ( V_160 ) ;
V_8 -> V_9 . V_32 = V_160 ;
V_8 -> V_9 . V_40 = V_161 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_162 ;
V_8 -> V_60 = V_163 ;
V_8 -> V_79 = 1 ;
V_8 -> V_80 [ 0 ] = V_164 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_165 ;
V_8 -> V_126 = 0 ;
V_8 -> V_101 = F_74 ( V_166 ) ,
V_8 -> V_100 = V_166 ,
V_4 -> V_128 = V_129 ;
switch ( V_112 ) {
case V_167 :
V_8 -> V_79 = 2 ;
V_8 -> V_80 [ 1 ] = V_168 ;
V_4 -> V_128 . V_131 = F_82 ;
break;
case V_169 :
V_8 -> V_79 = 2 ;
V_8 -> V_80 [ 1 ] = V_170 ;
V_4 -> V_128 . V_131 = F_82 ;
V_4 -> V_128 . V_133 = F_83 ;
break;
case V_171 :
V_8 -> V_51 = & V_172 ;
V_8 -> V_79 = 2 ;
V_8 -> V_80 [ 1 ] = V_168 ;
V_8 -> V_62 = 2 ;
V_8 -> V_65 [ 1 ] = V_173 ;
V_4 -> V_128 . V_131 = F_82 ;
break;
#ifdef F_76
case V_174 :
V_8 -> V_51 = & V_175 ;
V_8 -> V_80 [ 0 ] = V_176 ;
V_8 -> V_65 [ 0 ] = V_177 ;
V_4 -> V_128 . V_131 = F_82 ;
#endif
}
V_8 -> V_82 = 0x13 ;
switch ( V_4 -> V_148 >> 16 ) {
case 0x103c :
F_77 ( V_4 , 0x10 , V_149 ,
( 0x17 << V_150 ) |
( 0x17 << V_151 ) |
( 0x05 << V_152 ) |
( 1 << V_153 ) ) ;
break;
}
return 0 ;
}
static void F_85 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_178 ;
V_178 = ( V_8 -> V_105 && V_8 -> V_97 ) ? V_179 : 0 ;
F_86 ( V_4 , 0x16 , 0 , V_180 ,
V_178 ) ;
V_178 = ( ! V_8 -> V_105 && V_8 -> V_97 ) ? V_181 : 0 ;
F_86 ( V_4 , 0x1a , 0 , V_180 ,
V_178 ) ;
if ( V_8 -> V_182 )
F_86 ( V_4 , 0x1b , 0 ,
V_180 ,
V_178 ) ;
}
static int F_87 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
if ( ! F_55 ( V_48 , V_53 ) )
return 0 ;
F_85 ( V_4 ) ;
return 1 ;
}
static void F_88 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_110 ;
if ( ! ( V_8 -> V_183 & V_184 ) )
return;
V_110 = F_66 ( V_4 , 0x17 ) ;
F_86 ( V_4 , 0x14 , 0 ,
V_185 ,
V_110 ? 0x01 : 0x00 ) ;
}
static void F_89 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_110 ;
T_1 V_186 ;
if ( ! ( V_8 -> V_183 & V_187 ) )
return;
V_110 = F_66 ( V_4 , 0x18 ) ;
if ( V_110 )
V_8 -> V_17 = 1 ;
else
V_8 -> V_17 = 0 ;
V_186 = V_8 -> V_13 [ V_8 -> V_17 ] ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_186 ) {
F_90 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_186 ;
F_14 ( V_4 , V_186 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
}
static void F_91 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_105 = F_66 ( V_4 , 0x16 ) ;
F_85 ( V_4 ) ;
}
static void F_92 ( struct V_3 * V_4 ,
unsigned int V_111 )
{
int V_31 = ( V_111 & V_188 ) >> 20 ;
switch ( V_111 >> 26 ) {
case V_69 :
F_91 ( V_4 ) ;
break;
case V_189 :
F_88 ( V_4 ) ;
break;
case V_71 :
F_89 ( V_4 ) ;
break;
}
F_30 ( V_4 , V_31 ) ;
}
static void F_93 ( struct V_3 * V_4 , T_1 V_31 ,
unsigned int V_190 )
{
F_86 ( V_4 , V_31 , 0 ,
V_191 ,
V_68 | V_190 ) ;
F_29 ( V_4 , V_31 , V_73 , NULL ) ;
F_30 ( V_4 , V_31 ) ;
}
static int F_94 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_35 ( V_4 ) ;
F_27 ( V_4 ) ;
if ( V_8 -> V_183 & V_184 )
F_93 ( V_4 , 0x17 , V_189 ) ;
if ( V_8 -> V_183 & V_187 )
F_93 ( V_4 , 0x18 , V_71 ) ;
if ( V_4 -> V_128 . V_131 ) {
F_91 ( V_4 ) ;
F_88 ( V_4 ) ;
F_89 ( V_4 ) ;
}
return 0 ;
}
static int F_95 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_112 ;
V_112 = F_71 ( V_4 , V_192 ,
V_193 ,
V_194 ) ;
if ( V_112 < 0 )
V_112 = V_195 ;
if ( V_112 == V_195 )
return F_72 ( V_4 ) ;
V_8 = F_73 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 )
return - V_93 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_118 = 1 ;
V_4 -> V_128 = V_129 ;
V_4 -> V_128 . V_133 = F_94 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_103 = F_74 ( V_196 ) ;
V_8 -> V_9 . V_32 = V_196 ;
V_8 -> V_9 . V_40 = V_197 ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_198 ;
V_8 -> V_79 = 2 ;
V_8 -> V_80 [ 0 ] = V_199 ;
V_8 -> V_80 [ 1 ] = V_200 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_201 ;
V_8 -> V_126 = 0 ;
V_8 -> V_101 = F_74 ( V_202 ) ;
V_8 -> V_100 = V_202 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_75 ( V_8 , 0x13 , 0 , V_84 ) ;
V_4 -> V_128 . V_131 = F_92 ;
V_8 -> V_183 = V_184 | V_187 ;
switch ( V_112 ) {
case V_203 :
V_8 -> V_80 [ 0 ] = V_204 ;
break;
case V_205 :
V_8 -> V_65 [ 0 ] = V_206 ;
V_8 -> V_80 [ 0 ] = V_207 ;
V_8 -> V_183 = 0 ;
break;
case V_208 :
V_8 -> V_65 [ 0 ] = V_209 ;
if ( V_4 -> V_148 == 0x17aa211f )
V_8 -> V_9 . V_40 = 0 ;
break;
case V_210 :
V_8 -> V_65 [ 0 ] = V_211 ;
V_8 -> V_80 [ 0 ] = V_212 ;
V_8 -> V_183 = 0 ;
break;
case V_213 :
V_8 -> V_80 [ 0 ] = V_214 ;
V_8 -> V_183 = V_184 ;
break;
case V_215 :
V_8 -> V_65 [ V_8 -> V_62 ++ ] =
V_216 ;
V_8 -> V_182 = 1 ;
break;
}
if ( V_8 -> V_88 )
F_78 ( V_4 , V_8 -> V_88 ) ;
return 0 ;
}
static void F_96 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_178 ;
F_97 ( L_5 ,
V_8 -> V_105 , V_8 -> V_97 ) ;
V_178 = ( F_98 ( V_8 ) && V_8 -> V_97 ) ? V_179 : 0 ;
F_86 ( V_4 , 0x19 , 0 , V_180 ,
V_178 ) ;
V_178 = V_8 -> V_97 ? V_8 -> V_217 : 0 ;
if ( V_8 -> V_218 || V_8 -> V_219 ) {
if ( F_98 ( V_8 ) )
V_178 = 0 ;
} else {
if ( ! F_99 ( V_8 ) )
V_178 = 0 ;
}
F_86 ( V_4 , 0x1c , 0 , V_180 ,
V_178 ) ;
V_178 = ( ! V_8 -> V_105 && V_8 -> V_97 ) ? V_181 : 0 ;
F_86 ( V_4 , 0x1f , 0 , V_180 ,
V_178 ) ;
}
static int F_100 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
if ( ! F_55 ( V_48 , V_53 ) )
return 0 ;
F_96 ( V_4 ) ;
return 1 ;
}
static int F_101 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
return F_56 ( V_4 , 0x1a , 0 ,
V_180 ,
V_220 . V_221 [ V_8 -> V_222 ] . V_223 ) ;
}
static void F_102 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_224 )
return;
if ( V_8 -> V_225 ) {
const struct V_63 V_226 [] = {
{ 0x1b , V_180 , 0 } ,
{ 0x1e , V_180 , V_227 } ,
{} ,
} ;
F_36 ( V_4 , V_226 ) ;
F_101 ( V_4 ) ;
return;
}
F_86 ( V_4 , 0x1e , 0 , V_180 , 0 ) ;
F_86 ( V_4 , 0x1a , 0 , V_180 ,
V_8 -> V_228 ? V_229 : 0 ) ;
F_86 ( V_4 , 0x1b , 0 , V_180 ,
V_8 -> V_228 ? 0 : V_230 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_110 ;
if ( V_8 -> V_225 )
return;
V_110 = F_33 ( V_4 , 0x1a , 0 ,
V_231 , 0 ) & 0x80000000 ;
if ( V_110 )
F_97 ( L_6 ) ;
else
F_97 ( L_7 ) ;
F_86 ( V_4 , 0x17 , 0 , V_185 ,
V_110 ? 0 : 1 ) ;
V_8 -> V_228 = ! ! V_110 ;
F_102 ( V_4 ) ;
}
static void F_104 ( struct V_3 * V_4 )
{
unsigned int V_110 ;
struct V_63 V_228 [] = {
{ 0x1a , V_180 , V_230 } ,
{ 0x17 , V_185 , 0 } ,
{ 0x14 , V_185 , 0 } ,
{ 0x23 , V_180 , 0 } ,
{}
} ;
static const struct V_63 V_232 [] = {
{ 0x23 , V_180 , V_227 } ,
{ 0x14 , V_185 , 2 } ,
{ 0x1a , V_180 , 0 } ,
{}
} ;
V_110 = F_66 ( V_4 , 0x1a ) ;
if ( V_110 ) {
F_97 ( L_6 ) ;
F_36 ( V_4 , V_228 ) ;
} else {
F_97 ( L_7 ) ;
F_36 ( V_4 , V_232 ) ;
}
}
static void F_105 ( struct V_3 * V_4 )
{
unsigned int V_110 ;
struct V_63 V_228 [] = {
{ 0x14 , V_185 , 0 } ,
{ 0x1b , V_180 , V_230 } ,
{ 0x23 , V_180 , 0 } ,
{}
} ;
static const struct V_63 V_232 [] = {
{ 0x14 , V_185 , 2 } ,
{ 0x23 , V_180 , V_227 } ,
{ 0x1b , V_180 , 0 } ,
{}
} ;
V_110 = F_66 ( V_4 , 0x1b ) ;
if ( V_110 ) {
F_97 ( L_6 ) ;
F_36 ( V_4 , V_228 ) ;
} else {
F_97 ( L_7 ) ;
F_36 ( V_4 , V_232 ) ;
}
}
static void F_106 ( struct V_3 * V_4 )
{
unsigned int V_110 ;
V_110 = F_66 ( V_4 , 0x1b ) ;
F_97 ( L_8 , V_110 ) ;
F_86 ( V_4 , 0x17 , 0 , V_185 ,
V_110 ? 1 : 0 ) ;
}
static void F_107 ( struct V_3 * V_4 )
{
unsigned int V_110 ;
V_110 = F_66 ( V_4 , 0x1b ) ;
F_97 ( L_8 , V_110 ) ;
F_86 ( V_4 , 0x17 , 0 , V_185 ,
V_110 ? 1 : 3 ) ;
}
static void F_108 ( struct V_3 * V_4 )
{
unsigned int V_233 , V_234 ;
static const struct V_63 V_228 [] = {
{ 0x14 , V_185 , 0 } ,
{ 0x17 , V_185 , 1 } ,
{ 0x1b , V_180 , V_230 } ,
{ 0x23 , V_180 , 0 } ,
{ 0x1a , V_180 , 0 } ,
{}
} ;
static const struct V_63 V_235 [] = {
{ 0x14 , V_185 , 0 } ,
{ 0x17 , V_185 , 0 } ,
{ 0x1a , V_180 , V_230 } ,
{ 0x23 , V_180 , 0 } ,
{ 0x1b , V_180 , 0 } ,
{}
} ;
static const struct V_63 V_232 [] = {
{ 0x14 , V_185 , 2 } ,
{ 0x23 , V_180 , V_227 } ,
{ 0x1b , V_180 , 0 } ,
{ 0x1a , V_180 , 0 } ,
{}
} ;
V_233 = F_66 ( V_4 , 0x1b ) ;
V_234 = F_66 ( V_4 , 0x1a ) ;
if ( V_233 ) {
F_97 ( L_6 ) ;
F_36 ( V_4 , V_228 ) ;
} else if ( V_234 ) {
F_97 ( L_9 ) ;
F_36 ( V_4 , V_235 ) ;
} else {
F_97 ( L_7 ) ;
F_36 ( V_4 , V_232 ) ;
}
}
static void F_109 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_236 , V_237 ;
V_236 = F_66 ( V_4 , 0x19 ) ;
V_237 = F_66 ( V_4 , 0x1c ) ;
V_8 -> V_105 = V_236 ? V_238 : 0 ;
V_8 -> V_105 |= V_237 ? V_239 : 0 ;
F_97 ( L_10 ,
V_236 , V_237 , V_8 -> V_105 ) ;
F_96 ( V_4 ) ;
}
static void F_110 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 -> V_240 )
F_104 ( V_4 ) ;
else if ( V_8 -> V_182 )
F_105 ( V_4 ) ;
else if ( V_8 -> V_219 )
F_108 ( V_4 ) ;
else if ( V_8 -> V_241 )
F_107 ( V_4 ) ;
else if ( V_8 -> V_242 )
F_106 ( V_4 ) ;
}
static void F_111 ( struct V_3 * V_4 , unsigned int V_111 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_97 ( L_11 , V_111 , V_111 >> 26 ) ;
switch ( V_111 >> 26 ) {
case V_69 :
F_109 ( V_4 ) ;
break;
case V_72 :
if ( ! V_8 -> V_225 )
F_103 ( V_4 ) ;
break;
}
}
static void F_112 ( struct V_3 * V_4 , unsigned int V_111 )
{
F_97 ( L_11 , V_111 , V_111 >> 26 ) ;
switch ( V_111 >> 26 ) {
case V_69 :
F_109 ( V_4 ) ;
break;
case V_72 :
F_110 ( V_4 ) ;
break;
}
}
static void F_113 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_56 ( V_4 , 0x17 , 0 ,
V_108 ,
V_243 | V_244 | V_245 |
V_246 . V_221 [ V_8 -> V_247 ] . V_223 ) ;
if ( V_8 -> V_182 || V_8 -> V_219 ) {
F_56 ( V_4 , 0x23 , 0 ,
V_108 ,
V_243 | V_244 | V_248 |
V_246 .
V_221 [ V_8 -> V_247 ] . V_223 ) ;
}
}
static int F_114 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_246 , V_50 ) ;
}
static int F_115 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_247 ;
return 0 ;
}
static int F_116 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_249 * V_250 = & V_246 ;
unsigned int V_251 ;
V_251 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_251 >= V_250 -> V_252 )
V_251 = V_250 -> V_252 - 1 ;
V_8 -> V_247 = V_251 ;
if ( ! V_8 -> V_225 )
F_113 ( V_4 ) ;
return 1 ;
}
static void F_117 ( struct V_3 * V_4 )
{
const struct V_63 V_226 [] = {
{ 0x17 , V_108 , V_155 } ,
{ 0x17 , V_185 , 3 } ,
{}
} ;
F_36 ( V_4 , V_226 ) ;
F_102 ( V_4 ) ;
}
static void F_118 ( struct V_3 * V_4 )
{
F_113 ( V_4 ) ;
F_103 ( V_4 ) ;
}
static int F_119 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_225 ;
return 0 ;
}
static int F_120 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_225 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_225 == V_8 -> V_225 )
return 0 ;
V_8 -> V_225 = V_225 ;
if ( V_225 )
F_117 ( V_4 ) ;
else
F_118 ( V_4 ) ;
return 1 ;
}
static int F_121 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_220 , V_50 ) ;
}
static int F_122 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_222 ;
return 0 ;
}
static int F_123 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_249 * V_250 = & V_246 ;
unsigned int V_251 ;
V_251 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_251 >= V_250 -> V_252 )
V_251 = V_250 -> V_252 - 1 ;
V_8 -> V_222 = V_251 ;
if ( V_8 -> V_225 )
F_101 ( V_4 ) ;
return 1 ;
}
static void F_124 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_224 = 1 ;
F_102 ( V_4 ) ;
}
static void F_125 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_63 V_253 [] = {
{ 0x1a , V_180 , 0 } ,
{ 0x1b , V_180 , 0 } ,
{ 0x1e , V_180 , 0 } ,
{} ,
} ;
F_36 ( V_4 , V_253 ) ;
V_8 -> V_224 = 0 ;
}
static void F_126 ( struct V_3 * V_4 ,
const T_1 * V_254 ,
int V_255 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 * V_256 = & V_8 -> V_9 . V_40 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_255 ; V_61 ++ , V_254 ++ ) {
unsigned int V_257 = F_127 ( V_4 , * V_254 ) ;
if ( F_128 ( V_257 ) == V_258 )
continue;
if ( F_129 ( V_4 , * V_254 , V_256 , 1 ) != 1 )
continue;
if ( V_8 -> V_46 [ 0 ] )
V_256 ++ ;
else
V_256 = V_8 -> V_46 ;
}
}
static int F_130 ( struct V_3 * V_4 )
{
F_97 ( L_12 ) ;
F_35 ( V_4 ) ;
if ( V_4 -> V_128 . V_131 ) {
F_109 ( V_4 ) ;
F_110 ( V_4 ) ;
}
F_113 ( V_4 ) ;
return 0 ;
}
static int F_131 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_97 ( L_12 ) ;
F_35 ( V_4 ) ;
F_109 ( V_4 ) ;
if ( ! V_8 -> V_225 ) {
F_113 ( V_4 ) ;
F_103 ( V_4 ) ;
} else {
F_117 ( V_4 ) ;
}
return 0 ;
}
static int F_132 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_112 ;
V_112 = F_71 ( V_4 , V_259 ,
V_260 , V_261 ) ;
if ( V_112 < 0 )
V_112 = V_262 ;
if ( V_112 == V_262 )
return F_72 ( V_4 ) ;
V_8 = F_73 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 )
return - V_93 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_128 = V_129 ;
V_4 -> V_128 . V_133 = F_35 ;
V_8 -> V_218 = 0 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_103 = F_74 ( V_263 ) ;
V_8 -> V_9 . V_32 = V_263 ;
F_126 ( V_4 , V_264 ,
F_74 ( V_264 ) ) ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_265 ;
V_8 -> V_60 = V_266 ;
V_8 -> V_51 = & V_267 ;
V_8 -> V_217 = V_179 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_268 ;
V_8 -> V_101 = F_74 ( V_269 ) ;
V_8 -> V_100 = V_269 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_75 ( V_8 , 0x13 , 0 , V_84 ) ;
switch ( V_112 ) {
default:
case V_270 :
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_271 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_272 ;
break;
case V_273 :
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_271 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_272 ;
V_8 -> V_217 = V_181 ;
V_8 -> V_65 [ V_8 -> V_62 ] = V_274 ;
V_8 -> V_62 ++ ;
V_8 -> V_218 = 1 ;
break;
case V_275 :
case V_276 :
V_4 -> V_128 . V_133 = F_130 ;
V_4 -> V_128 . V_131 = F_112 ;
V_8 -> V_65 [ V_8 -> V_62 ] =
V_277 ;
V_8 -> V_62 ++ ;
V_8 -> V_241 = V_112 == V_276 ;
V_8 -> V_242 = V_112 == V_275 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_271 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_272 ;
if ( V_112 == V_276 )
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_217 = 0 ;
V_8 -> V_247 = 3 ;
break;
case V_278 :
V_4 -> V_128 . V_133 = F_131 ;
V_4 -> V_128 . V_131 = F_111 ;
V_8 -> V_65 [ 0 ] = V_279 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_280 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_281 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_272 ;
V_8 -> V_217 = 0 ;
V_8 -> V_247 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_12 = F_124 ;
V_8 -> V_15 = F_125 ;
break;
case V_282 :
V_4 -> V_128 . V_133 = F_130 ;
V_4 -> V_128 . V_131 = F_112 ;
V_8 -> V_65 [ 0 ] = V_283 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_280 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_272 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_284 ;
V_8 -> V_217 = 0 ;
V_8 -> V_240 = 1 ;
V_8 -> V_247 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_285 :
V_4 -> V_128 . V_133 = F_130 ;
V_4 -> V_128 . V_131 = F_112 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_271 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_272 ;
V_8 -> V_65 [ 0 ] = V_286 ;
V_8 -> V_217 = 0 ;
V_8 -> V_182 = 1 ;
V_8 -> V_247 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_287 :
V_4 -> V_128 . V_133 = F_130 ;
V_4 -> V_128 . V_131 = F_112 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_271 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_272 ;
V_8 -> V_65 [ 0 ] = V_288 ;
V_8 -> V_219 = 1 ;
V_8 -> V_217 = V_181 ;
V_8 -> V_247 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
}
if ( V_8 -> V_88 )
F_78 ( V_4 , V_8 -> V_88 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
unsigned int V_11 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_289 = V_8 -> V_290 [ V_8 -> V_59 [ 0 ] ] . V_289 ;
if ( V_8 -> V_291 ) {
V_8 -> V_16 = V_289 ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_11 ;
}
F_14 ( V_4 , V_289 , V_10 , 0 , V_11 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_16 ( V_4 , V_8 -> V_16 ) ;
V_8 -> V_16 = 0 ;
return 0 ;
}
static T_1 F_135 ( struct V_3 * V_4 , T_1 V_292 ,
T_1 * V_293 , int * V_103 )
{
int V_61 , V_294 = * V_103 ;
T_1 V_295 = 0 ;
for ( V_61 = 0 ; V_61 < V_294 ; V_61 ++ ) {
if ( F_136 ( V_4 , V_292 , V_293 [ V_61 ] ) >= 0 ) {
V_295 = V_293 [ V_61 ] ;
break;
}
}
if ( ! V_295 )
return 0 ;
if ( -- V_294 > 0 )
memmove ( V_293 , V_293 + 1 , V_294 * sizeof( T_1 ) ) ;
* V_103 = V_294 ;
return V_295 ;
}
static int F_137 ( struct V_3 * V_4 , T_1 * V_293 )
{
T_1 V_31 , V_296 ;
int V_294 = 0 ;
V_296 = V_4 -> V_297 + V_4 -> V_298 ;
for ( V_31 = V_4 -> V_297 ; V_31 < V_296 ; V_31 ++ ) {
unsigned int V_299 = F_138 ( V_4 , V_31 ) ;
unsigned int type = F_139 ( V_299 ) ;
if ( type == V_300 && ! ( V_299 & V_301 ) ) {
V_293 [ V_294 ++ ] = V_31 ;
if ( V_294 >= V_302 )
break;
}
}
return V_294 ;
}
static int F_140 ( struct V_3 * V_4 , T_1 * V_303 ,
int V_255 , T_1 * V_293 , int * V_304 ,
struct V_305 * V_306 , int V_294 ,
int type )
{
int V_61 , V_307 = V_294 ;
for ( V_61 = 0 ; V_61 < V_255 ; V_61 ++ , V_294 ++ ) {
V_306 [ V_294 ] . V_292 = V_303 [ V_61 ] ;
V_306 [ V_294 ] . type = type ;
V_306 [ V_294 ] . V_308 = F_135 ( V_4 , V_303 [ V_61 ] , V_293 , V_304 ) ;
if ( V_306 [ V_294 ] . V_308 )
continue;
if ( V_306 [ V_307 ] . V_308 && F_136 ( V_4 , V_303 [ V_61 ] , V_306 [ V_307 ] . V_308 ) >= 0 ) {
V_306 [ V_294 ] . V_308 = V_306 [ V_307 ] . V_308 | V_309 ;
continue;
}
if ( V_306 [ 0 ] . V_308 && F_136 ( V_4 , V_303 [ V_61 ] , V_306 [ 0 ] . V_308 ) >= 0 ) {
V_306 [ V_294 ] . V_308 = V_306 [ 0 ] . V_308 | V_309 ;
continue;
}
F_97 ( L_13 , V_303 [ V_61 ] ) ;
}
return V_294 ;
}
static void F_141 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
T_1 V_293 [ V_302 ] ;
int V_61 , V_312 , V_294 , V_304 ;
V_304 = F_137 ( V_4 , V_293 ) ;
V_294 = F_140 ( V_4 , V_257 -> V_313 , V_257 -> V_314 ,
V_293 , & V_304 , V_8 -> V_315 , 0 ,
V_316 ) ;
V_294 = F_140 ( V_4 , V_257 -> V_317 , V_257 -> V_318 ,
V_293 , & V_304 , V_8 -> V_315 , V_294 ,
V_319 ) ;
V_294 = F_140 ( V_4 , V_257 -> V_320 , V_257 -> V_321 ,
V_293 , & V_304 , V_8 -> V_315 , V_294 ,
V_322 ) ;
V_8 -> V_323 = V_294 ;
for ( V_61 = 0 ; V_61 < V_294 ; V_61 ++ ) {
T_1 V_308 = V_8 -> V_315 [ V_61 ] . V_308 ;
if ( ! V_308 || ( V_308 & V_309 ) )
continue;
switch ( V_8 -> V_315 [ V_61 ] . type ) {
case V_316 :
V_8 -> V_324 [ V_8 -> V_9 . V_103 ] = V_308 ;
V_8 -> V_9 . V_103 ++ ;
break;
case V_319 :
case V_322 :
if ( ! V_8 -> V_9 . V_325 ) {
V_8 -> V_9 . V_325 = V_308 ;
break;
}
for ( V_312 = 0 ; V_312 < F_74 ( V_8 -> V_9 . V_326 ) ; V_312 ++ )
if ( ! V_8 -> V_9 . V_326 [ V_312 ] ) {
V_8 -> V_9 . V_326 [ V_312 ] = V_308 ;
break;
}
break;
}
}
V_8 -> V_9 . V_32 = V_8 -> V_324 ;
V_8 -> V_9 . V_30 = V_8 -> V_9 . V_103 * 2 ;
for ( V_61 = 0 ; V_61 < V_257 -> V_318 ; V_61 ++ ) {
if ( F_142 ( V_4 , V_257 -> V_317 [ V_61 ] ) ) {
V_8 -> V_327 = 1 ;
break;
}
}
if ( V_8 -> V_327 &&
V_257 -> V_313 [ 0 ] &&
V_257 -> V_328 != V_322 &&
V_257 -> V_313 [ 0 ] != V_257 -> V_317 [ 0 ] &&
V_257 -> V_313 [ 0 ] != V_257 -> V_320 [ 0 ] ) {
for ( V_61 = 0 ; V_61 < V_257 -> V_314 ; V_61 ++ ) {
if ( F_142 ( V_4 , V_257 -> V_313 [ V_61 ] ) ) {
V_8 -> V_329 = 1 ;
break;
}
}
V_8 -> V_330 = V_8 -> V_329 ;
}
V_8 -> V_82 = V_8 -> V_324 [ 0 ] ;
}
static void F_143 ( struct V_3 * V_4 , int V_255 ,
T_1 * V_303 , bool V_331 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_255 ; V_61 ++ )
F_86 ( V_4 , V_303 [ V_61 ] , 0 ,
V_180 ,
V_331 ? V_181 : 0 ) ;
F_144 ( V_4 , V_255 , V_303 , V_331 ) ;
}
static int F_145 ( struct V_3 * V_4 , int V_255 , T_1 * V_303 )
{
int V_61 , V_110 = 0 ;
for ( V_61 = 0 ; V_61 < V_255 ; V_61 ++ ) {
T_1 V_31 = V_303 [ V_61 ] ;
if ( ! V_31 || ! F_142 ( V_4 , V_31 ) )
break;
F_30 ( V_4 , V_31 ) ;
V_110 |= F_66 ( V_4 , V_31 ) ;
}
return V_110 ;
}
static void F_146 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
int V_331 = 1 ;
if ( V_8 -> V_327 )
V_331 = V_8 -> V_105 ;
F_144 ( V_4 , V_257 -> V_318 , V_257 -> V_317 , V_331 ) ;
if ( V_8 -> V_327 )
V_331 = ! ( V_8 -> V_105 ||
( V_8 -> V_329 && V_8 -> V_332 ) ) ;
F_143 ( V_4 , V_257 -> V_321 , V_257 -> V_320 , V_331 ) ;
if ( V_257 -> V_313 [ 0 ] == V_257 -> V_317 [ 0 ] ||
V_257 -> V_313 [ 0 ] == V_257 -> V_320 [ 0 ] )
return;
if ( V_8 -> V_327 ) {
if ( V_257 -> V_328 == V_322 ||
V_8 -> V_330 )
V_331 = ! V_8 -> V_105 ;
else
V_331 = 1 ;
}
F_143 ( V_4 , V_257 -> V_314 , V_257 -> V_313 , V_331 ) ;
}
static void F_147 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
if ( ! V_8 -> V_327 )
return;
V_8 -> V_105 = F_145 ( V_4 , V_257 -> V_318 , V_257 -> V_317 ) ;
F_146 ( V_4 ) ;
}
static void F_148 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
if ( ! V_8 -> V_327 || ! V_8 -> V_329 )
return;
V_8 -> V_332 = F_145 ( V_4 , V_257 -> V_314 ,
V_257 -> V_313 ) ;
F_146 ( V_4 ) ;
}
static int F_149 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
static const char * const V_333 [] = {
L_14 , L_15
} ;
static const char * const V_334 [] = {
L_14 , L_16 , L_17
} ;
const char * const * V_335 ;
V_50 -> type = V_336 ;
V_50 -> V_337 = 1 ;
if ( V_8 -> V_338 ) {
V_50 -> V_56 . V_57 . V_221 = 3 ;
V_335 = V_334 ;
} else {
V_50 -> V_56 . V_57 . V_221 = 2 ;
V_335 = V_333 ;
}
if ( V_50 -> V_56 . V_57 . V_58 >= V_50 -> V_56 . V_57 . V_221 )
V_50 -> V_56 . V_57 . V_58 = V_50 -> V_56 . V_57 . V_221 - 1 ;
strcpy ( V_50 -> V_56 . V_57 . V_25 ,
V_335 [ V_50 -> V_56 . V_57 . V_58 ] ) ;
return 0 ;
}
static int F_150 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_339 ;
if ( ! V_8 -> V_327 )
V_339 = 0 ;
else if ( ! V_8 -> V_330 )
V_339 = 1 ;
else
V_339 = 2 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_339 ;
return 0 ;
}
static int F_151 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
switch ( V_53 -> V_56 . V_57 . V_58 [ 0 ] ) {
case 0 :
if ( ! V_8 -> V_327 )
return 0 ;
V_8 -> V_327 = 0 ;
break;
case 1 :
if ( V_8 -> V_327 && ! V_8 -> V_330 )
return 0 ;
V_8 -> V_327 = 1 ;
V_8 -> V_330 = 0 ;
break;
case 2 :
if ( ! V_8 -> V_338 )
return - V_340 ;
if ( V_8 -> V_327 && V_8 -> V_330 )
return 0 ;
V_8 -> V_327 = 1 ;
V_8 -> V_330 = 1 ;
break;
default:
return - V_340 ;
}
F_146 ( V_4 ) ;
return 1 ;
}
static int F_152 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_22 ( & V_8 -> V_341 , V_50 ) ;
}
static int F_153 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_59 [ 0 ] ;
return 0 ;
}
static int F_154 ( struct V_3 * V_4 , T_1 V_342 ,
T_1 V_292 , T_1 * V_343 ,
bool V_344 , int V_345 )
{
T_1 V_346 [ V_347 ] ;
int V_61 , V_294 ;
switch ( F_139 ( F_138 ( V_4 , V_342 ) ) ) {
case V_348 :
case V_349 :
case V_350 :
break;
default:
return - 1 ;
}
V_294 = F_129 ( V_4 , V_342 , V_346 , F_74 ( V_346 ) ) ;
for ( V_61 = 0 ; V_61 < V_294 ; V_61 ++ )
if ( V_346 [ V_61 ] == V_292 ) {
if ( V_344 )
F_86 ( V_4 , V_342 , 0 ,
V_185 , V_61 ) ;
if ( V_343 )
* V_343 = V_342 ;
return V_61 ;
}
V_345 ++ ;
if ( V_345 == 2 )
return - 1 ;
for ( V_61 = 0 ; V_61 < V_294 ; V_61 ++ ) {
int V_295 = F_154 ( V_4 , V_346 [ V_61 ] , V_292 , V_343 ,
V_344 , V_345 ) ;
if ( V_295 >= 0 ) {
if ( V_344 )
F_86 ( V_4 , V_342 , 0 ,
V_185 , V_61 ) ;
return V_61 ;
}
}
return - 1 ;
}
static void F_155 ( struct V_3 * V_4 , T_1 V_342 ,
T_1 V_292 )
{
F_154 ( V_4 , V_342 , V_292 , NULL , true , 0 ) ;
}
static int F_156 ( struct V_3 * V_4 , T_1 V_342 ,
T_1 V_292 )
{
return F_154 ( V_4 , V_342 , V_292 , NULL , false , 0 ) ;
}
static int F_157 ( struct V_3 * V_4 ,
const struct V_249 * V_250 ,
unsigned int V_251 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_289 ;
int V_351 = 1 ;
if ( ! V_250 -> V_252 )
return 0 ;
if ( V_251 >= V_250 -> V_252 )
V_251 = V_250 -> V_252 - 1 ;
if ( V_8 -> V_59 [ 0 ] == V_251 )
V_351 = 0 ;
V_289 = V_8 -> V_290 [ V_251 ] . V_289 ;
F_155 ( V_4 , V_8 -> V_290 [ V_251 ] . V_289 ,
V_8 -> V_290 [ V_251 ] . V_292 ) ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_289 ) {
F_90 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_289 ;
F_14 ( V_4 , V_289 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
V_8 -> V_59 [ 0 ] = V_251 ;
return V_351 ;
}
static int F_158 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_157 ( V_4 , & V_8 -> V_341 ,
V_53 -> V_56 . V_57 . V_58 [ 0 ] ) ;
}
static bool F_159 ( struct V_3 * V_4 , int V_251 , bool V_352 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_251 < 0 )
return false ;
if ( V_352 && ! F_66 ( V_4 , V_8 -> V_290 [ V_251 ] . V_292 ) )
return false ;
F_157 ( V_4 , & V_8 -> V_341 , V_251 ) ;
return true ;
}
static void F_160 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_183 )
return;
if ( ! F_159 ( V_4 , V_8 -> V_353 , true ) )
if ( ! F_159 ( V_4 , V_8 -> V_354 , true ) )
F_159 ( V_4 , V_8 -> V_355 , false ) ;
}
static void F_161 ( struct V_3 * V_4 , unsigned int V_111 )
{
int V_31 = ( V_111 & V_188 ) >> 20 ;
switch ( V_111 >> 26 ) {
case V_69 :
F_147 ( V_4 ) ;
break;
case V_356 :
F_148 ( V_4 ) ;
break;
case V_72 :
F_160 ( V_4 ) ;
F_30 ( V_4 , V_31 ) ;
break;
}
}
static void F_162 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_357 [ V_358 + 1 ] ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_74 ( V_357 ) ; V_61 ++ )
V_357 [ V_61 ] = - 1 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_341 . V_252 ; V_61 ++ ) {
T_1 V_292 = V_8 -> V_290 [ V_61 ] . V_292 ;
unsigned int V_359 = F_127 ( V_4 , V_292 ) ;
int type , V_360 ;
V_360 = F_163 ( V_359 ) ;
if ( V_360 == V_361 )
return;
if ( V_360 > V_358 )
V_360 = V_358 ;
if ( V_360 != V_362 &&
! F_142 ( V_4 , V_292 ) )
return;
type = F_164 ( V_359 ) ;
if ( type != V_363 &&
( V_360 != V_364 || type != V_365 ) )
return;
if ( V_357 [ V_360 ] >= 0 )
return;
V_357 [ V_360 ] = V_61 ;
}
if ( V_357 [ V_362 ] < 0 ||
( V_357 [ V_358 ] < 0 && V_357 [ V_364 ] ) )
return;
V_8 -> V_183 = 1 ;
V_8 -> V_353 = V_357 [ V_358 ] ;
V_8 -> V_354 = V_357 [ V_364 ] ;
V_8 -> V_355 = V_357 [ V_362 ] ;
}
static void F_165 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
struct V_249 * V_250 ;
int V_61 , V_312 ;
V_250 = & V_8 -> V_341 ;
for ( V_61 = 0 ; V_61 < V_257 -> V_366 ; V_61 ++ ) {
for ( V_312 = 0 ; V_312 < V_8 -> V_39 ; V_312 ++ ) {
T_1 V_289 = V_8 -> V_13 [ V_312 ] ;
int V_251 = F_156 ( V_4 , V_289 ,
V_257 -> V_367 [ V_61 ] . V_292 ) ;
if ( V_251 >= 0 ) {
const char * V_368 ;
V_368 = F_166 ( V_4 , V_257 , V_61 ) ;
V_8 -> V_290 [ V_250 -> V_252 ] . V_223 = V_61 ;
V_8 -> V_290 [ V_250 -> V_252 ] . V_369 = 0 ;
V_8 -> V_290 [ V_250 -> V_252 ] . V_289 = V_289 ;
V_8 -> V_290 [ V_250 -> V_252 ] . V_292 =
V_257 -> V_367 [ V_61 ] . V_292 ;
F_167 ( V_250 , V_368 , V_251 , NULL ) ;
break;
}
}
}
if ( V_250 -> V_252 >= 2 && V_257 -> V_366 == V_250 -> V_252 )
F_162 ( V_4 ) ;
if ( V_250 -> V_252 > 1 ) {
for ( V_61 = 1 ; V_61 < V_250 -> V_252 ; V_61 ++ ) {
if ( V_8 -> V_290 [ V_61 ] . V_289 != V_8 -> V_290 [ 0 ] . V_289 ) {
V_8 -> V_291 = 1 ;
break;
}
}
}
}
static T_1 F_168 ( struct V_3 * V_4 , T_1 V_292 )
{
T_1 V_31 , V_296 ;
V_296 = V_4 -> V_297 + V_4 -> V_298 ;
for ( V_31 = V_4 -> V_297 ; V_31 < V_296 ; V_31 ++ ) {
unsigned int V_299 = F_138 ( V_4 , V_31 ) ;
unsigned int type = F_139 ( V_299 ) ;
if ( type == V_348 && ( V_299 & V_301 ) ) {
if ( F_136 ( V_4 , V_31 , V_292 ) >= 0 )
return V_31 ;
}
}
return 0 ;
}
static void F_169 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
T_1 V_31 ;
if ( V_257 -> V_370 &&
F_129 ( V_4 , V_257 -> V_371 [ 0 ] , & V_31 , 1 ) == 1 )
V_8 -> V_9 . V_40 = V_31 ;
if ( V_257 -> V_372 )
V_8 -> V_44 = F_168 ( V_4 , V_257 -> V_372 ) ;
}
static void F_170 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_296 ;
V_296 = V_4 -> V_297 + V_4 -> V_298 ;
for ( V_31 = V_4 -> V_297 ; V_31 < V_296 ; V_31 ++ )
if ( F_139 ( F_138 ( V_4 , V_31 ) ) == V_373 ) {
F_75 ( V_8 , V_31 , 0 , V_84 ) ;
break;
}
}
static bool F_171 ( T_1 V_31 , const T_1 * V_374 , int V_294 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_294 ; V_61 ++ )
if ( V_374 [ V_61 ] == V_31 )
return true ;
return false ;
}
static void F_172 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
T_1 V_31 , V_296 ;
V_296 = V_4 -> V_297 + V_4 -> V_298 ;
for ( V_31 = V_4 -> V_297 ; V_31 < V_296 ; V_31 ++ ) {
if ( F_139 ( F_138 ( V_4 , V_31 ) ) != V_375 )
continue;
if ( ! ( F_173 ( V_4 , V_31 ) & V_376 ) )
continue;
if ( F_171 ( V_31 , V_257 -> V_313 , V_257 -> V_314 ) ||
F_171 ( V_31 , V_257 -> V_317 , V_257 -> V_318 ) ||
F_171 ( V_31 , V_257 -> V_320 , V_257 -> V_321 ) )
continue;
V_8 -> V_377 [ V_8 -> V_378 ++ ] = V_31 ;
if ( V_8 -> V_378 >= F_74 ( V_8 -> V_377 ) )
break;
}
}
static int F_174 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
V_66 = F_175 ( V_4 , & V_8 -> V_311 , NULL ) ;
if ( V_66 < 0 )
return V_66 ;
F_141 ( V_4 ) ;
F_165 ( V_4 ) ;
F_169 ( V_4 ) ;
F_170 ( V_4 ) ;
F_172 ( V_4 ) ;
return 0 ;
}
static void F_144 ( struct V_3 * V_4 , int V_255 ,
T_1 * V_303 , bool V_331 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_255 ; V_61 ++ ) {
if ( F_173 ( V_4 , V_303 [ V_61 ] ) & V_376 )
F_86 ( V_4 , V_303 [ V_61 ] , 0 ,
V_99 ,
V_331 ? 0x02 : 0 ) ;
}
}
static void F_176 ( struct V_3 * V_4 , T_1 V_292 ,
T_1 V_379 )
{
int V_251 = F_136 ( V_4 , V_292 , V_379 ) ;
if ( V_251 >= 0 )
F_86 ( V_4 , V_292 , 0 ,
V_185 , V_251 ) ;
}
static void F_177 ( struct V_3 * V_4 , int V_380 ,
const T_1 * V_381 )
{
int V_61 , V_339 ;
for ( V_61 = 0 ; V_61 < V_380 ; V_61 ++ ) {
T_1 V_31 = V_381 [ V_61 ] ;
if ( ! ( F_138 ( V_4 , V_31 ) & V_382 ) )
continue;
if ( F_178 ( V_4 , V_31 , V_84 ) & V_383 )
V_339 = V_154 ;
else
V_339 = V_384 ;
F_86 ( V_4 , V_31 , 0 ,
V_108 , V_339 ) ;
}
}
static void F_179 ( struct V_3 * V_4 , int V_255 ,
T_1 * V_303 , unsigned int V_385 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_255 ; V_61 ++ )
F_86 ( V_4 , V_303 [ V_61 ] , 0 ,
V_191 ,
V_68 | V_385 ) ;
}
static void F_180 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
T_1 V_31 ;
int V_61 ;
F_177 ( V_4 , V_8 -> V_9 . V_103 , V_8 -> V_9 . V_32 ) ;
for ( V_61 = 0 ; V_61 < V_257 -> V_318 ; V_61 ++ )
F_86 ( V_4 , V_257 -> V_317 [ V_61 ] , 0 ,
V_180 , V_179 ) ;
F_177 ( V_4 , V_257 -> V_318 , V_257 -> V_317 ) ;
F_177 ( V_4 , V_257 -> V_314 , V_257 -> V_313 ) ;
F_177 ( V_4 , V_257 -> V_321 , V_257 -> V_320 ) ;
for ( V_61 = 0 ; V_61 < V_8 -> V_323 ; V_61 ++ ) {
V_31 = V_8 -> V_315 [ V_61 ] . V_308 ;
if ( ! V_31 )
V_31 = V_8 -> V_9 . V_32 [ 0 ] ;
else if ( V_31 & V_309 )
V_31 &= ~ V_309 ;
F_176 ( V_4 , V_8 -> V_315 [ V_61 ] . V_292 , V_31 ) ;
}
if ( V_8 -> V_327 ) {
F_179 ( V_4 , V_257 -> V_318 , V_257 -> V_317 ,
V_69 ) ;
V_8 -> V_105 = F_145 ( V_4 , V_257 -> V_318 ,
V_257 -> V_317 ) ;
if ( V_8 -> V_329 ) {
F_179 ( V_4 , V_257 -> V_314 ,
V_257 -> V_313 ,
V_356 ) ;
V_8 -> V_332 =
F_145 ( V_4 , V_257 -> V_314 ,
V_257 -> V_313 ) ;
}
}
F_146 ( V_4 ) ;
F_144 ( V_4 , V_8 -> V_378 , V_8 -> V_377 , true ) ;
}
static void F_181 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
int V_61 , V_339 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_39 ; V_61 ++ ) {
T_1 V_31 = V_8 -> V_13 [ V_61 ] ;
if ( ! ( F_138 ( V_4 , V_31 ) & V_386 ) )
continue;
if ( F_178 ( V_4 , V_31 , V_149 ) & V_383 )
V_339 = F_182 ( 0 ) ;
else
V_339 = F_183 ( 0 ) ;
F_86 ( V_4 , V_31 , 0 , V_108 ,
V_339 ) ;
}
for ( V_61 = 0 ; V_61 < V_257 -> V_366 ; V_61 ++ ) {
unsigned int type ;
if ( V_257 -> V_367 [ V_61 ] . type == V_387 )
type = V_230 ;
else
type = V_227 ;
F_86 ( V_4 , V_257 -> V_367 [ V_61 ] . V_292 , 0 ,
V_180 , type ) ;
}
if ( V_8 -> V_183 ) {
if ( V_8 -> V_353 >= 0 ) {
F_86 ( V_4 ,
V_257 -> V_367 [ V_8 -> V_353 ] . V_292 , 0 ,
V_191 ,
V_68 | V_72 ) ;
}
if ( V_8 -> V_354 >= 0 ) {
F_86 ( V_4 ,
V_257 -> V_367 [ V_8 -> V_354 ] . V_292 , 0 ,
V_191 ,
V_68 | V_72 ) ;
}
F_160 ( V_4 ) ;
} else {
F_155 ( V_4 , V_8 -> V_290 [ 0 ] . V_289 ,
V_8 -> V_290 [ 0 ] . V_292 ) ;
}
}
static void F_184 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_310 * V_257 = & V_8 -> V_311 ;
if ( V_8 -> V_9 . V_40 )
F_86 ( V_4 , V_257 -> V_371 [ 0 ] , 0 ,
V_180 , V_181 ) ;
if ( V_8 -> V_44 )
F_86 ( V_4 , V_257 -> V_372 , 0 ,
V_180 , V_227 ) ;
}
static int F_185 ( struct V_3 * V_4 )
{
F_180 ( V_4 ) ;
F_181 ( V_4 ) ;
F_184 ( V_4 ) ;
return 0 ;
}
static int F_186 ( struct V_3 * V_4 , const char * V_388 ,
const char * V_389 , int V_390 ,
T_1 V_31 , int V_391 , int V_392 )
{
static char V_25 [ 32 ] ;
static struct V_89 V_90 [] = {
F_187 ( V_25 , 0 , 0 , 0 ) ,
F_188 ( V_25 , 0 , 0 , 0 ) ,
} ;
static const char * const V_393 [ 2 ] = { L_18 , L_19 } ;
int V_61 , V_66 ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
struct V_47 * V_92 ;
V_90 [ V_61 ] . V_94 = F_189 ( V_31 , 3 , V_392 ,
V_391 ) ;
V_90 [ V_61 ] . V_394 = V_395 ;
V_90 [ V_61 ] . V_223 = V_390 ;
snprintf ( V_25 , sizeof( V_25 ) , L_20 , V_388 , V_389 , V_393 [ V_61 ] ) ;
V_92 = F_50 ( & V_90 [ V_61 ] , V_4 ) ;
if ( ! V_92 )
return - V_93 ;
V_66 = F_51 ( V_4 , V_31 , V_92 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( ! ( F_178 ( V_4 , V_31 , V_391 ) & V_383 ) )
break;
}
return 0 ;
}
static int F_190 ( struct V_3 * V_4 , T_1 V_308 ,
T_1 V_292 , const char * V_25 , int V_251 )
{
unsigned int V_396 ;
if ( V_308 && ! ( V_308 & V_309 ) ) {
V_396 = F_178 ( V_4 , V_308 , V_84 ) ;
if ( V_396 & V_397 )
return F_191 ( V_4 , V_308 , V_25 , V_251 ) ;
}
V_396 = F_178 ( V_4 , V_292 , V_84 ) ;
if ( V_396 & V_397 )
return F_191 ( V_4 , V_292 , V_25 , V_251 ) ;
return 0 ;
}
static int F_192 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 , V_66 ;
int V_398 = 0 , V_399 = 0 , V_400 = 0 ;
static const char * const V_335 [ 3 ] = { L_21 , L_22 , L_23 } ;
if ( V_8 -> V_323 == 1 )
return F_190 ( V_4 , V_8 -> V_315 [ 0 ] . V_308 ,
V_8 -> V_315 [ 0 ] . V_292 ,
L_24 , 0 ) ;
for ( V_61 = 0 ; V_61 < V_8 -> V_323 ; V_61 ++ ) {
const char * V_368 ;
int V_251 , type ;
T_1 V_308 = V_8 -> V_315 [ V_61 ] . V_308 ;
type = V_8 -> V_315 [ V_61 ] . type ;
if ( type == V_316 )
type = V_8 -> V_311 . V_328 ;
switch ( type ) {
case V_316 :
default:
V_368 = V_335 [ V_398 ++ ] ;
V_251 = 0 ;
break;
case V_319 :
V_368 = L_25 ;
V_251 = V_399 ++ ;
break;
case V_322 :
V_368 = L_26 ;
V_251 = V_400 ++ ;
break;
}
V_66 = F_190 ( V_4 , V_308 ,
V_8 -> V_315 [ V_61 ] . V_292 ,
V_368 , V_251 ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_327 ) {
V_66 = F_42 ( V_4 , V_401 ) ;
if ( V_66 < 0 )
return V_66 ;
}
return 0 ;
}
static int F_193 ( struct V_3 * V_4 , T_1 V_31 ,
const char * V_368 , const char * V_402 ,
int V_390 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_39 ; V_61 ++ ) {
T_1 V_403 = V_8 -> V_13 [ V_61 ] ;
int V_251 = F_156 ( V_4 , V_403 , V_31 ) ;
if ( V_251 < 0 )
continue;
return F_186 ( V_4 , V_368 , V_402 ,
V_390 , V_403 , V_149 , V_251 ) ;
}
return 0 ;
}
static int F_194 ( struct V_3 * V_4 , int V_251 ,
const char * V_368 , int V_390 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_342 , V_31 ;
int V_61 , V_404 ;
V_31 = V_8 -> V_290 [ V_251 ] . V_292 ;
if ( F_138 ( V_4 , V_31 ) & V_386 )
return F_195 ( V_4 , V_368 , L_27 , V_390 ,
V_31 , V_149 ) ;
V_404 = F_154 ( V_4 , V_8 -> V_290 [ V_251 ] . V_289 , V_31 ,
& V_342 , false , 0 ) ;
if ( V_404 < 0 )
return 0 ;
for ( V_61 = 0 ; V_61 < V_251 ; V_61 ++ ) {
if ( V_8 -> V_290 [ V_61 ] . V_369 == V_342 )
return 0 ;
}
if ( F_138 ( V_4 , V_342 ) & V_382 ) {
V_8 -> V_290 [ V_251 ] . V_369 = V_342 ;
return F_195 ( V_4 , V_368 , L_27 , 0 ,
V_342 , V_84 ) ;
}
return 0 ;
}
static int F_196 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_249 * V_250 = & V_8 -> V_341 ;
const char * V_405 ;
int V_406 [ V_347 ] ;
int V_61 , V_66 , V_390 ;
int V_407 ;
V_407 = 0 ;
for ( V_61 = 0 ; V_61 < V_250 -> V_252 ; V_61 ++ ) {
V_390 = F_156 ( V_4 , V_8 -> V_290 [ V_61 ] . V_289 ,
V_8 -> V_290 [ V_61 ] . V_292 ) ;
V_406 [ V_61 ] = ( V_8 -> V_290 [ V_61 ] . V_289 << 8 ) | V_390 ;
if ( V_61 > 0 && V_406 [ V_61 ] != V_406 [ 0 ] )
V_407 = 1 ;
}
V_405 = NULL ;
V_390 = 0 ;
for ( V_61 = 0 ; V_61 < V_250 -> V_252 ; V_61 ++ ) {
T_1 V_31 = V_8 -> V_290 [ V_61 ] . V_292 ;
const char * V_368 ;
V_368 = F_166 ( V_4 , & V_8 -> V_311 ,
V_8 -> V_290 [ V_61 ] . V_223 ) ;
if ( V_368 == V_405 )
V_390 ++ ;
else
V_390 = 0 ;
V_405 = V_368 ;
V_66 = F_194 ( V_4 , V_61 , V_368 , V_390 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( ! V_407 ) {
if ( V_61 > 0 )
continue;
V_66 = F_193 ( V_4 , V_31 ,
L_28 , L_29 , V_390 ) ;
} else {
V_66 = F_193 ( V_4 , V_31 ,
V_368 , L_30 , V_390 ) ;
}
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_341 . V_252 > 1 && ! V_8 -> V_183 ) {
V_66 = F_42 ( V_4 , V_408 ) ;
if ( V_66 < 0 )
return V_66 ;
}
return 0 ;
}
static int F_197 ( struct V_3 * V_4 )
{
int V_66 ;
V_66 = F_192 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_196 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
return F_41 ( V_4 ) ;
}
static int F_198 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_296 ;
V_296 = V_4 -> V_297 + V_4 -> V_298 ;
for ( V_31 = V_4 -> V_297 ; V_31 < V_296 ; V_31 ++ ) {
unsigned int V_396 = F_138 ( V_4 , V_31 ) ;
if ( F_139 ( V_396 ) != V_348 )
continue;
if ( V_396 & V_301 )
continue;
if ( F_199 ( V_8 -> V_39 >=
F_74 ( V_8 -> V_409 ) ) )
break;
V_8 -> V_409 [ V_8 -> V_39 ++ ] = V_31 ;
}
V_8 -> V_13 = V_8 -> V_409 ;
return 0 ;
}
static int F_72 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_66 ;
F_200 ( V_410 L_31 ,
V_4 -> V_411 ) ;
V_8 = F_73 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 )
return - V_93 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_118 = 1 ;
V_66 = F_198 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_174 ( V_4 ) ;
if ( V_66 < 0 ) {
F_40 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
return V_66 ;
}
V_8 -> V_33 = & V_412 ;
V_4 -> V_128 = V_413 ;
if ( V_8 -> V_88 )
F_78 ( V_4 , V_8 -> V_88 ) ;
return 0 ;
}
static int T_3 F_201 ( void )
{
return F_202 ( & V_414 ) ;
}
static void T_4 F_203 ( void )
{
F_204 ( & V_414 ) ;
}
