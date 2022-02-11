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
V_8 -> V_80 [ 0 ] = V_210 ;
V_8 -> V_183 = 0 ;
break;
case V_211 :
V_8 -> V_80 [ 0 ] = V_212 ;
V_8 -> V_183 = V_184 ;
break;
case V_213 :
V_8 -> V_65 [ V_8 -> V_62 ++ ] =
V_214 ;
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
V_178 = V_8 -> V_97 ? V_8 -> V_215 : 0 ;
if ( V_8 -> V_216 || V_8 -> V_217 ) {
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
V_218 . V_219 [ V_8 -> V_220 ] . V_221 ) ;
}
static void F_102 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_222 )
return;
if ( V_8 -> V_223 ) {
const struct V_63 V_224 [] = {
{ 0x1b , V_180 , 0 } ,
{ 0x1e , V_180 , V_225 } ,
{} ,
} ;
F_36 ( V_4 , V_224 ) ;
F_101 ( V_4 ) ;
return;
}
F_86 ( V_4 , 0x1e , 0 , V_180 , 0 ) ;
F_86 ( V_4 , 0x1a , 0 , V_180 ,
V_8 -> V_226 ? V_227 : 0 ) ;
F_86 ( V_4 , 0x1b , 0 , V_180 ,
V_8 -> V_226 ? 0 : V_228 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_110 ;
if ( V_8 -> V_223 )
return;
V_110 = F_33 ( V_4 , 0x1a , 0 ,
V_229 , 0 ) & 0x80000000 ;
if ( V_110 )
F_97 ( L_6 ) ;
else
F_97 ( L_7 ) ;
F_86 ( V_4 , 0x17 , 0 , V_185 ,
V_110 ? 0 : 1 ) ;
V_8 -> V_226 = ! ! V_110 ;
F_102 ( V_4 ) ;
}
static void F_104 ( struct V_3 * V_4 )
{
unsigned int V_110 ;
struct V_63 V_226 [] = {
{ 0x1a , V_180 , V_228 } ,
{ 0x17 , V_185 , 0 } ,
{ 0x14 , V_185 , 0 } ,
{ 0x23 , V_180 , 0 } ,
{}
} ;
static const struct V_63 V_230 [] = {
{ 0x23 , V_180 , V_225 } ,
{ 0x14 , V_185 , 2 } ,
{ 0x1a , V_180 , 0 } ,
{}
} ;
V_110 = F_66 ( V_4 , 0x1a ) ;
if ( V_110 ) {
F_97 ( L_6 ) ;
F_36 ( V_4 , V_226 ) ;
} else {
F_97 ( L_7 ) ;
F_36 ( V_4 , V_230 ) ;
}
}
static void F_105 ( struct V_3 * V_4 )
{
unsigned int V_110 ;
struct V_63 V_226 [] = {
{ 0x14 , V_185 , 0 } ,
{ 0x1b , V_180 , V_228 } ,
{ 0x23 , V_180 , 0 } ,
{}
} ;
static const struct V_63 V_230 [] = {
{ 0x14 , V_185 , 2 } ,
{ 0x23 , V_180 , V_225 } ,
{ 0x1b , V_180 , 0 } ,
{}
} ;
V_110 = F_66 ( V_4 , 0x1b ) ;
if ( V_110 ) {
F_97 ( L_6 ) ;
F_36 ( V_4 , V_226 ) ;
} else {
F_97 ( L_7 ) ;
F_36 ( V_4 , V_230 ) ;
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
unsigned int V_231 , V_232 ;
static const struct V_63 V_226 [] = {
{ 0x14 , V_185 , 0 } ,
{ 0x17 , V_185 , 1 } ,
{ 0x1b , V_180 , V_228 } ,
{ 0x23 , V_180 , 0 } ,
{ 0x1a , V_180 , 0 } ,
{}
} ;
static const struct V_63 V_233 [] = {
{ 0x14 , V_185 , 0 } ,
{ 0x17 , V_185 , 0 } ,
{ 0x1a , V_180 , V_228 } ,
{ 0x23 , V_180 , 0 } ,
{ 0x1b , V_180 , 0 } ,
{}
} ;
static const struct V_63 V_230 [] = {
{ 0x14 , V_185 , 2 } ,
{ 0x23 , V_180 , V_225 } ,
{ 0x1b , V_180 , 0 } ,
{ 0x1a , V_180 , 0 } ,
{}
} ;
V_231 = F_66 ( V_4 , 0x1b ) ;
V_232 = F_66 ( V_4 , 0x1a ) ;
if ( V_231 ) {
F_97 ( L_6 ) ;
F_36 ( V_4 , V_226 ) ;
} else if ( V_232 ) {
F_97 ( L_9 ) ;
F_36 ( V_4 , V_233 ) ;
} else {
F_97 ( L_7 ) ;
F_36 ( V_4 , V_230 ) ;
}
}
static void F_109 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_234 , V_235 ;
V_234 = F_66 ( V_4 , 0x19 ) ;
V_235 = F_66 ( V_4 , 0x1c ) ;
V_8 -> V_105 = V_234 ? V_236 : 0 ;
V_8 -> V_105 |= V_235 ? V_237 : 0 ;
F_97 ( L_10 ,
V_234 , V_235 , V_8 -> V_105 ) ;
F_96 ( V_4 ) ;
}
static void F_110 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 -> V_238 )
F_104 ( V_4 ) ;
else if ( V_8 -> V_182 )
F_105 ( V_4 ) ;
else if ( V_8 -> V_217 )
F_108 ( V_4 ) ;
else if ( V_8 -> V_239 )
F_107 ( V_4 ) ;
else if ( V_8 -> V_240 )
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
if ( ! V_8 -> V_223 )
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
V_241 | V_242 | V_243 |
V_244 . V_219 [ V_8 -> V_245 ] . V_221 ) ;
if ( V_8 -> V_182 || V_8 -> V_217 ) {
F_56 ( V_4 , 0x23 , 0 ,
V_108 ,
V_241 | V_242 | V_246 |
V_244 .
V_219 [ V_8 -> V_245 ] . V_221 ) ;
}
}
static int F_114 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_244 , V_50 ) ;
}
static int F_115 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_245 ;
return 0 ;
}
static int F_116 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_247 * V_248 = & V_244 ;
unsigned int V_249 ;
V_249 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_249 >= V_248 -> V_250 )
V_249 = V_248 -> V_250 - 1 ;
V_8 -> V_245 = V_249 ;
if ( ! V_8 -> V_223 )
F_113 ( V_4 ) ;
return 1 ;
}
static void F_117 ( struct V_3 * V_4 )
{
const struct V_63 V_224 [] = {
{ 0x17 , V_108 , V_155 } ,
{ 0x17 , V_185 , 3 } ,
{}
} ;
F_36 ( V_4 , V_224 ) ;
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
V_53 -> V_56 . integer . V_56 [ 0 ] = V_8 -> V_223 ;
return 0 ;
}
static int F_120 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_223 = ! ! V_53 -> V_56 . integer . V_56 [ 0 ] ;
if ( V_223 == V_8 -> V_223 )
return 0 ;
V_8 -> V_223 = V_223 ;
if ( V_223 )
F_117 ( V_4 ) ;
else
F_118 ( V_4 ) ;
return 1 ;
}
static int F_121 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
return F_22 ( & V_218 , V_50 ) ;
}
static int F_122 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_220 ;
return 0 ;
}
static int F_123 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_247 * V_248 = & V_244 ;
unsigned int V_249 ;
V_249 = V_53 -> V_56 . V_57 . V_58 [ 0 ] ;
if ( V_249 >= V_248 -> V_250 )
V_249 = V_248 -> V_250 - 1 ;
V_8 -> V_220 = V_249 ;
if ( V_8 -> V_223 )
F_101 ( V_4 ) ;
return 1 ;
}
static void F_124 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_222 = 1 ;
F_102 ( V_4 ) ;
}
static void F_125 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
const struct V_63 V_251 [] = {
{ 0x1a , V_180 , 0 } ,
{ 0x1b , V_180 , 0 } ,
{ 0x1e , V_180 , 0 } ,
{} ,
} ;
F_36 ( V_4 , V_251 ) ;
V_8 -> V_222 = 0 ;
}
static void F_126 ( struct V_3 * V_4 ,
const T_1 * V_252 ,
int V_253 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 * V_254 = & V_8 -> V_9 . V_40 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_253 ; V_61 ++ , V_252 ++ ) {
unsigned int V_255 = F_127 ( V_4 , * V_252 ) ;
if ( F_128 ( V_255 ) == V_256 )
continue;
if ( F_129 ( V_4 , * V_252 , V_254 , 1 ) != 1 )
continue;
if ( V_8 -> V_46 [ 0 ] )
V_254 ++ ;
else
V_254 = V_8 -> V_46 ;
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
if ( ! V_8 -> V_223 ) {
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
V_112 = F_71 ( V_4 , V_257 ,
V_258 , V_259 ) ;
if ( V_112 < 0 )
V_112 = V_260 ;
if ( V_112 == V_260 )
return F_72 ( V_4 ) ;
V_8 = F_73 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 )
return - V_93 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_128 = V_129 ;
V_4 -> V_128 . V_133 = F_35 ;
V_8 -> V_216 = 0 ;
V_8 -> V_9 . V_30 = 2 ;
V_8 -> V_9 . V_103 = F_74 ( V_261 ) ;
V_8 -> V_9 . V_32 = V_261 ;
F_126 ( V_4 , V_262 ,
F_74 ( V_262 ) ) ;
V_8 -> V_39 = 1 ;
V_8 -> V_13 = V_263 ;
V_8 -> V_60 = V_264 ;
V_8 -> V_51 = & V_265 ;
V_8 -> V_215 = V_179 ;
V_8 -> V_62 = 1 ;
V_8 -> V_65 [ 0 ] = V_266 ;
V_8 -> V_101 = F_74 ( V_267 ) ;
V_8 -> V_100 = V_267 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
F_75 ( V_8 , 0x13 , 0 , V_84 ) ;
switch ( V_112 ) {
default:
case V_268 :
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_269 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_270 ;
break;
case V_271 :
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_269 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_270 ;
V_8 -> V_215 = V_181 ;
V_8 -> V_65 [ V_8 -> V_62 ] = V_272 ;
V_8 -> V_62 ++ ;
V_8 -> V_216 = 1 ;
break;
case V_273 :
case V_274 :
V_4 -> V_128 . V_133 = F_130 ;
V_4 -> V_128 . V_131 = F_112 ;
V_8 -> V_65 [ V_8 -> V_62 ] =
V_275 ;
V_8 -> V_62 ++ ;
V_8 -> V_239 = V_112 == V_274 ;
V_8 -> V_240 = V_112 == V_273 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_269 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_270 ;
if ( V_112 == V_274 )
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_215 = 0 ;
V_8 -> V_245 = 3 ;
break;
case V_276 :
V_4 -> V_128 . V_133 = F_131 ;
V_4 -> V_128 . V_131 = F_111 ;
V_8 -> V_65 [ 0 ] = V_277 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_278 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_279 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_270 ;
V_8 -> V_215 = 0 ;
V_8 -> V_245 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
V_8 -> V_12 = F_124 ;
V_8 -> V_15 = F_125 ;
break;
case V_280 :
V_4 -> V_128 . V_133 = F_130 ;
V_4 -> V_128 . V_131 = F_112 ;
V_8 -> V_65 [ 0 ] = V_281 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_278 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_270 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_282 ;
V_8 -> V_215 = 0 ;
V_8 -> V_238 = 1 ;
V_8 -> V_245 = 3 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_283 :
V_4 -> V_128 . V_133 = F_130 ;
V_4 -> V_128 . V_131 = F_112 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_269 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_270 ;
V_8 -> V_65 [ 0 ] = V_284 ;
V_8 -> V_215 = 0 ;
V_8 -> V_182 = 1 ;
V_8 -> V_245 = 2 ;
V_8 -> V_9 . V_40 = 0 ;
V_8 -> V_51 = NULL ;
break;
case V_285 :
V_4 -> V_128 . V_133 = F_130 ;
V_4 -> V_128 . V_131 = F_112 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_269 ;
V_8 -> V_80 [ V_8 -> V_79 ++ ] = V_270 ;
V_8 -> V_65 [ 0 ] = V_286 ;
V_8 -> V_217 = 1 ;
V_8 -> V_215 = V_181 ;
V_8 -> V_245 = 2 ;
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
T_1 V_287 = V_8 -> V_288 [ V_8 -> V_59 [ 0 ] ] . V_287 ;
if ( V_8 -> V_289 ) {
V_8 -> V_16 = V_287 ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_11 ;
}
F_14 ( V_4 , V_287 , V_10 , 0 , V_11 ) ;
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
static T_1 F_135 ( struct V_3 * V_4 , T_1 V_290 ,
T_1 * V_291 , int * V_103 )
{
int V_61 , V_292 = * V_103 ;
T_1 V_293 = 0 ;
for ( V_61 = 0 ; V_61 < V_292 ; V_61 ++ ) {
if ( F_136 ( V_4 , V_290 , V_291 [ V_61 ] ) >= 0 ) {
V_293 = V_291 [ V_61 ] ;
break;
}
}
if ( ! V_293 )
return 0 ;
if ( -- V_292 > 0 )
memmove ( V_291 , V_291 + 1 , V_292 * sizeof( T_1 ) ) ;
* V_103 = V_292 ;
return V_293 ;
}
static int F_137 ( struct V_3 * V_4 , T_1 * V_291 )
{
T_1 V_31 , V_294 ;
int V_292 = 0 ;
V_294 = V_4 -> V_295 + V_4 -> V_296 ;
for ( V_31 = V_4 -> V_295 ; V_31 < V_294 ; V_31 ++ ) {
unsigned int V_297 = F_138 ( V_4 , V_31 ) ;
unsigned int type = F_139 ( V_297 ) ;
if ( type == V_298 && ! ( V_297 & V_299 ) ) {
V_291 [ V_292 ++ ] = V_31 ;
if ( V_292 >= V_300 )
break;
}
}
return V_292 ;
}
static int F_140 ( struct V_3 * V_4 , T_1 * V_301 ,
int V_253 , T_1 * V_291 , int * V_302 ,
struct V_303 * V_304 , int V_292 ,
int type )
{
int V_61 , V_305 = V_292 ;
for ( V_61 = 0 ; V_61 < V_253 ; V_61 ++ , V_292 ++ ) {
V_304 [ V_292 ] . V_290 = V_301 [ V_61 ] ;
V_304 [ V_292 ] . type = type ;
V_304 [ V_292 ] . V_306 = F_135 ( V_4 , V_301 [ V_61 ] , V_291 , V_302 ) ;
if ( V_304 [ V_292 ] . V_306 )
continue;
if ( V_304 [ V_305 ] . V_306 && F_136 ( V_4 , V_301 [ V_61 ] , V_304 [ V_305 ] . V_306 ) >= 0 ) {
V_304 [ V_292 ] . V_306 = V_304 [ V_305 ] . V_306 | V_307 ;
continue;
}
if ( V_304 [ 0 ] . V_306 && F_136 ( V_4 , V_301 [ V_61 ] , V_304 [ 0 ] . V_306 ) >= 0 ) {
V_304 [ V_292 ] . V_306 = V_304 [ 0 ] . V_306 | V_307 ;
continue;
}
F_97 ( L_13 , V_301 [ V_61 ] ) ;
}
return V_292 ;
}
static void F_141 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_308 * V_255 = & V_8 -> V_309 ;
T_1 V_291 [ V_300 ] ;
int V_61 , V_310 , V_292 , V_302 ;
V_302 = F_137 ( V_4 , V_291 ) ;
V_292 = F_140 ( V_4 , V_255 -> V_311 , V_255 -> V_312 ,
V_291 , & V_302 , V_8 -> V_313 , 0 ,
V_314 ) ;
V_292 = F_140 ( V_4 , V_255 -> V_315 , V_255 -> V_316 ,
V_291 , & V_302 , V_8 -> V_313 , V_292 ,
V_317 ) ;
V_292 = F_140 ( V_4 , V_255 -> V_318 , V_255 -> V_319 ,
V_291 , & V_302 , V_8 -> V_313 , V_292 ,
V_320 ) ;
V_8 -> V_321 = V_292 ;
for ( V_61 = 0 ; V_61 < V_292 ; V_61 ++ ) {
T_1 V_306 = V_8 -> V_313 [ V_61 ] . V_306 ;
if ( ! V_306 || ( V_306 & V_307 ) )
continue;
switch ( V_8 -> V_313 [ V_61 ] . type ) {
case V_314 :
V_8 -> V_322 [ V_8 -> V_9 . V_103 ] = V_306 ;
V_8 -> V_9 . V_103 ++ ;
break;
case V_317 :
case V_320 :
if ( ! V_8 -> V_9 . V_323 ) {
V_8 -> V_9 . V_323 = V_306 ;
break;
}
for ( V_310 = 0 ; V_310 < F_74 ( V_8 -> V_9 . V_324 ) ; V_310 ++ )
if ( ! V_8 -> V_9 . V_324 [ V_310 ] ) {
V_8 -> V_9 . V_324 [ V_310 ] = V_306 ;
break;
}
break;
}
}
V_8 -> V_9 . V_32 = V_8 -> V_322 ;
V_8 -> V_9 . V_30 = V_8 -> V_9 . V_103 * 2 ;
for ( V_61 = 0 ; V_61 < V_255 -> V_316 ; V_61 ++ ) {
if ( F_142 ( V_4 , V_255 -> V_315 [ V_61 ] ) ) {
V_8 -> V_325 = 1 ;
break;
}
}
if ( V_8 -> V_325 &&
V_255 -> V_311 [ 0 ] &&
V_255 -> V_326 != V_320 &&
V_255 -> V_311 [ 0 ] != V_255 -> V_315 [ 0 ] &&
V_255 -> V_311 [ 0 ] != V_255 -> V_318 [ 0 ] ) {
for ( V_61 = 0 ; V_61 < V_255 -> V_312 ; V_61 ++ ) {
if ( F_142 ( V_4 , V_255 -> V_311 [ V_61 ] ) ) {
V_8 -> V_327 = 1 ;
break;
}
}
V_8 -> V_328 = V_8 -> V_327 ;
}
V_8 -> V_82 = V_8 -> V_322 [ 0 ] ;
}
static void F_143 ( struct V_3 * V_4 , int V_253 ,
T_1 * V_301 , bool V_329 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_253 ; V_61 ++ )
F_86 ( V_4 , V_301 [ V_61 ] , 0 ,
V_180 ,
V_329 ? V_181 : 0 ) ;
if ( V_8 -> V_330 )
F_144 ( V_4 , V_253 , V_301 , V_329 ) ;
}
static int F_145 ( struct V_3 * V_4 , int V_253 , T_1 * V_301 )
{
int V_61 , V_110 = 0 ;
for ( V_61 = 0 ; V_61 < V_253 ; V_61 ++ ) {
T_1 V_31 = V_301 [ V_61 ] ;
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
struct V_308 * V_255 = & V_8 -> V_309 ;
int V_329 = 1 ;
if ( V_8 -> V_330 ) {
if ( V_8 -> V_325 )
V_329 = V_8 -> V_105 ;
F_144 ( V_4 , V_255 -> V_316 , V_255 -> V_315 , V_329 ) ;
}
if ( V_8 -> V_325 )
V_329 = ! ( V_8 -> V_105 ||
( V_8 -> V_327 && V_8 -> V_331 ) ) ;
F_143 ( V_4 , V_255 -> V_319 , V_255 -> V_318 , V_329 ) ;
if ( V_255 -> V_311 [ 0 ] == V_255 -> V_315 [ 0 ] ||
V_255 -> V_311 [ 0 ] == V_255 -> V_318 [ 0 ] )
return;
if ( V_8 -> V_325 ) {
if ( V_255 -> V_326 == V_320 ||
V_8 -> V_328 )
V_329 = ! V_8 -> V_105 ;
else
V_329 = 1 ;
}
F_143 ( V_4 , V_255 -> V_312 , V_255 -> V_311 , V_329 ) ;
}
static void F_147 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_308 * V_255 = & V_8 -> V_309 ;
if ( ! V_8 -> V_325 )
return;
V_8 -> V_105 = F_145 ( V_4 , V_255 -> V_316 , V_255 -> V_315 ) ;
F_146 ( V_4 ) ;
}
static void F_148 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_308 * V_255 = & V_8 -> V_309 ;
if ( ! V_8 -> V_325 || ! V_8 -> V_327 )
return;
V_8 -> V_331 = F_145 ( V_4 , V_255 -> V_312 ,
V_255 -> V_311 ) ;
F_146 ( V_4 ) ;
}
static int F_149 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
static const char * const V_332 [] = {
L_14 , L_15
} ;
static const char * const V_333 [] = {
L_14 , L_16 , L_17
} ;
const char * const * V_334 ;
V_50 -> type = V_335 ;
V_50 -> V_336 = 1 ;
if ( V_8 -> V_337 ) {
V_50 -> V_56 . V_57 . V_219 = 3 ;
V_334 = V_333 ;
} else {
V_50 -> V_56 . V_57 . V_219 = 2 ;
V_334 = V_332 ;
}
if ( V_50 -> V_56 . V_57 . V_58 >= V_50 -> V_56 . V_57 . V_219 )
V_50 -> V_56 . V_57 . V_58 = V_50 -> V_56 . V_57 . V_219 - 1 ;
strcpy ( V_50 -> V_56 . V_57 . V_25 ,
V_334 [ V_50 -> V_56 . V_57 . V_58 ] ) ;
return 0 ;
}
static int F_150 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_338 ;
if ( ! V_8 -> V_325 )
V_338 = 0 ;
else if ( ! V_8 -> V_328 )
V_338 = 1 ;
else
V_338 = 2 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_338 ;
return 0 ;
}
static int F_151 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
switch ( V_53 -> V_56 . V_57 . V_58 [ 0 ] ) {
case 0 :
if ( ! V_8 -> V_325 )
return 0 ;
V_8 -> V_325 = 0 ;
break;
case 1 :
if ( V_8 -> V_325 && ! V_8 -> V_328 )
return 0 ;
V_8 -> V_325 = 1 ;
V_8 -> V_328 = 0 ;
break;
case 2 :
if ( ! V_8 -> V_337 )
return - V_339 ;
if ( V_8 -> V_325 && V_8 -> V_328 )
return 0 ;
V_8 -> V_325 = 1 ;
V_8 -> V_328 = 1 ;
break;
default:
return - V_339 ;
}
F_146 ( V_4 ) ;
return 1 ;
}
static int F_152 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_22 ( & V_8 -> V_340 , V_50 ) ;
}
static int F_153 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_53 -> V_56 . V_57 . V_58 [ 0 ] = V_8 -> V_59 [ 0 ] ;
return 0 ;
}
static int F_154 ( struct V_3 * V_4 , T_1 V_341 ,
T_1 V_290 , T_1 * V_342 ,
bool V_343 , int V_344 )
{
T_1 V_345 [ V_346 ] ;
int V_61 , V_292 ;
switch ( F_139 ( F_138 ( V_4 , V_341 ) ) ) {
case V_347 :
case V_348 :
case V_349 :
break;
default:
return - 1 ;
}
V_292 = F_129 ( V_4 , V_341 , V_345 , F_74 ( V_345 ) ) ;
for ( V_61 = 0 ; V_61 < V_292 ; V_61 ++ )
if ( V_345 [ V_61 ] == V_290 ) {
if ( V_343 )
F_86 ( V_4 , V_341 , 0 ,
V_185 , V_61 ) ;
if ( V_342 )
* V_342 = V_341 ;
return V_61 ;
}
V_344 ++ ;
if ( V_344 == 2 )
return - 1 ;
for ( V_61 = 0 ; V_61 < V_292 ; V_61 ++ ) {
int V_293 = F_154 ( V_4 , V_345 [ V_61 ] , V_290 , V_342 ,
V_343 , V_344 ) ;
if ( V_293 >= 0 ) {
if ( V_343 )
F_86 ( V_4 , V_341 , 0 ,
V_185 , V_61 ) ;
return V_61 ;
}
}
return - 1 ;
}
static void F_155 ( struct V_3 * V_4 , T_1 V_341 ,
T_1 V_290 )
{
F_154 ( V_4 , V_341 , V_290 , NULL , true , 0 ) ;
}
static int F_156 ( struct V_3 * V_4 , T_1 V_341 ,
T_1 V_290 )
{
return F_154 ( V_4 , V_341 , V_290 , NULL , false , 0 ) ;
}
static int F_157 ( struct V_3 * V_4 ,
const struct V_247 * V_248 ,
unsigned int V_249 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_287 ;
int V_350 = 1 ;
if ( ! V_248 -> V_250 )
return 0 ;
if ( V_249 >= V_248 -> V_250 )
V_249 = V_248 -> V_250 - 1 ;
if ( V_8 -> V_59 [ 0 ] == V_249 )
V_350 = 0 ;
V_287 = V_8 -> V_288 [ V_249 ] . V_287 ;
F_155 ( V_4 , V_8 -> V_288 [ V_249 ] . V_287 ,
V_8 -> V_288 [ V_249 ] . V_290 ) ;
if ( V_8 -> V_16 && V_8 -> V_16 != V_287 ) {
F_90 ( V_4 , V_8 -> V_16 , 1 ) ;
V_8 -> V_16 = V_287 ;
F_14 ( V_4 , V_287 ,
V_8 -> V_18 , 0 ,
V_8 -> V_19 ) ;
}
V_8 -> V_59 [ 0 ] = V_249 ;
return V_350 ;
}
static int F_158 ( struct V_47 * V_48 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = F_21 ( V_48 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
return F_157 ( V_4 , & V_8 -> V_340 ,
V_53 -> V_56 . V_57 . V_58 [ 0 ] ) ;
}
static bool F_159 ( struct V_3 * V_4 , int V_249 , bool V_351 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_249 < 0 )
return false ;
if ( V_351 && ! F_66 ( V_4 , V_8 -> V_288 [ V_249 ] . V_290 ) )
return false ;
F_157 ( V_4 , & V_8 -> V_340 , V_249 ) ;
return true ;
}
static void F_160 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
if ( ! V_8 -> V_183 )
return;
if ( ! F_159 ( V_4 , V_8 -> V_352 , true ) )
if ( ! F_159 ( V_4 , V_8 -> V_353 , true ) )
F_159 ( V_4 , V_8 -> V_354 , false ) ;
}
static void F_161 ( struct V_3 * V_4 , unsigned int V_111 )
{
int V_31 = ( V_111 & V_188 ) >> 20 ;
switch ( V_111 >> 26 ) {
case V_69 :
F_147 ( V_4 ) ;
break;
case V_355 :
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
int V_356 [ V_357 + 1 ] ;
int V_61 ;
for ( V_61 = 0 ; V_61 < F_74 ( V_356 ) ; V_61 ++ )
V_356 [ V_61 ] = - 1 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_340 . V_250 ; V_61 ++ ) {
T_1 V_290 = V_8 -> V_288 [ V_61 ] . V_290 ;
unsigned int V_358 = F_127 ( V_4 , V_290 ) ;
int type , V_359 ;
V_359 = F_163 ( V_358 ) ;
if ( V_359 == V_360 )
return;
if ( V_359 > V_357 )
V_359 = V_357 ;
if ( V_359 != V_361 &&
! F_142 ( V_4 , V_290 ) )
return;
type = F_164 ( V_358 ) ;
if ( type != V_362 &&
( V_359 != V_363 || type != V_364 ) )
return;
if ( V_356 [ V_359 ] >= 0 )
return;
V_356 [ V_359 ] = V_61 ;
}
if ( V_356 [ V_361 ] < 0 ||
( V_356 [ V_357 ] < 0 && V_356 [ V_363 ] ) )
return;
V_8 -> V_183 = 1 ;
V_8 -> V_352 = V_356 [ V_357 ] ;
V_8 -> V_353 = V_356 [ V_363 ] ;
V_8 -> V_354 = V_356 [ V_361 ] ;
}
static void F_165 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_308 * V_255 = & V_8 -> V_309 ;
struct V_247 * V_248 ;
int V_61 , V_310 ;
V_248 = & V_8 -> V_340 ;
for ( V_61 = 0 ; V_61 < V_255 -> V_365 ; V_61 ++ ) {
for ( V_310 = 0 ; V_310 < V_8 -> V_39 ; V_310 ++ ) {
T_1 V_287 = V_8 -> V_13 [ V_310 ] ;
int V_249 = F_156 ( V_4 , V_287 ,
V_255 -> V_366 [ V_61 ] . V_290 ) ;
if ( V_249 >= 0 ) {
const char * V_367 ;
V_367 = F_166 ( V_4 , V_255 , V_61 ) ;
V_8 -> V_288 [ V_248 -> V_250 ] . V_221 = V_61 ;
V_8 -> V_288 [ V_248 -> V_250 ] . V_368 = 0 ;
V_8 -> V_288 [ V_248 -> V_250 ] . V_287 = V_287 ;
V_8 -> V_288 [ V_248 -> V_250 ] . V_290 =
V_255 -> V_366 [ V_61 ] . V_290 ;
F_167 ( V_248 , V_367 , V_249 , NULL ) ;
break;
}
}
}
if ( V_248 -> V_250 >= 2 && V_255 -> V_365 == V_248 -> V_250 )
F_162 ( V_4 ) ;
if ( V_248 -> V_250 > 1 ) {
for ( V_61 = 1 ; V_61 < V_248 -> V_250 ; V_61 ++ ) {
if ( V_8 -> V_288 [ V_61 ] . V_287 != V_8 -> V_288 [ 0 ] . V_287 ) {
V_8 -> V_289 = 1 ;
break;
}
}
}
}
static T_1 F_168 ( struct V_3 * V_4 , T_1 V_290 )
{
T_1 V_31 , V_294 ;
V_294 = V_4 -> V_295 + V_4 -> V_296 ;
for ( V_31 = V_4 -> V_295 ; V_31 < V_294 ; V_31 ++ ) {
unsigned int V_297 = F_138 ( V_4 , V_31 ) ;
unsigned int type = F_139 ( V_297 ) ;
if ( type == V_347 && ( V_297 & V_299 ) ) {
if ( F_136 ( V_4 , V_31 , V_290 ) >= 0 )
return V_31 ;
}
}
return 0 ;
}
static void F_169 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_308 * V_255 = & V_8 -> V_309 ;
T_1 V_31 ;
if ( V_255 -> V_369 &&
F_129 ( V_4 , V_255 -> V_370 [ 0 ] , & V_31 , 1 ) == 1 )
V_8 -> V_9 . V_40 = V_31 ;
if ( V_255 -> V_371 )
V_8 -> V_44 = F_168 ( V_4 , V_255 -> V_371 ) ;
}
static void F_170 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_294 ;
V_294 = V_4 -> V_295 + V_4 -> V_296 ;
for ( V_31 = V_4 -> V_295 ; V_31 < V_294 ; V_31 ++ )
if ( F_139 ( F_138 ( V_4 , V_31 ) ) == V_372 ) {
F_75 ( V_8 , V_31 , 0 , V_84 ) ;
break;
}
}
static void F_171 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_294 ;
V_294 = V_4 -> V_295 + V_4 -> V_296 ;
for ( V_31 = V_4 -> V_295 ; V_31 < V_294 ; V_31 ++ ) {
if ( F_139 ( F_138 ( V_4 , V_31 ) ) != V_373 )
continue;
if ( ! ( F_172 ( V_4 , V_31 ) & V_374 ) )
continue;
V_8 -> V_375 [ V_8 -> V_376 ++ ] = V_31 ;
if ( V_8 -> V_376 >= F_74 ( V_8 -> V_375 ) )
break;
}
V_8 -> V_330 = V_8 -> V_376 > 2 ;
}
static int F_173 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_66 ;
V_66 = F_174 ( V_4 , & V_8 -> V_309 , NULL ) ;
if ( V_66 < 0 )
return V_66 ;
F_141 ( V_4 ) ;
F_165 ( V_4 ) ;
F_169 ( V_4 ) ;
F_170 ( V_4 ) ;
F_171 ( V_4 ) ;
return 0 ;
}
static void F_144 ( struct V_3 * V_4 , int V_253 ,
T_1 * V_301 , bool V_329 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_253 ; V_61 ++ ) {
if ( F_172 ( V_4 , V_301 [ V_61 ] ) & V_374 )
F_86 ( V_4 , V_301 [ V_61 ] , 0 ,
V_99 ,
V_329 ? 0x02 : 0 ) ;
}
}
static void F_175 ( struct V_3 * V_4 , T_1 V_290 ,
T_1 V_377 )
{
int V_249 = F_136 ( V_4 , V_290 , V_377 ) ;
if ( V_249 >= 0 )
F_86 ( V_4 , V_290 , 0 ,
V_185 , V_249 ) ;
}
static void F_176 ( struct V_3 * V_4 , int V_378 ,
const T_1 * V_379 )
{
int V_61 , V_338 ;
for ( V_61 = 0 ; V_61 < V_378 ; V_61 ++ ) {
T_1 V_31 = V_379 [ V_61 ] ;
if ( ! ( F_138 ( V_4 , V_31 ) & V_380 ) )
continue;
if ( F_177 ( V_4 , V_31 , V_84 ) & V_381 )
V_338 = V_154 ;
else
V_338 = V_382 ;
F_86 ( V_4 , V_31 , 0 ,
V_108 , V_338 ) ;
}
}
static void F_178 ( struct V_3 * V_4 , int V_253 ,
T_1 * V_301 , unsigned int V_383 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_253 ; V_61 ++ )
F_86 ( V_4 , V_301 [ V_61 ] , 0 ,
V_191 ,
V_68 | V_383 ) ;
}
static void F_179 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_308 * V_255 = & V_8 -> V_309 ;
T_1 V_31 ;
int V_61 ;
F_176 ( V_4 , V_8 -> V_9 . V_103 , V_8 -> V_9 . V_32 ) ;
for ( V_61 = 0 ; V_61 < V_255 -> V_316 ; V_61 ++ )
F_86 ( V_4 , V_255 -> V_315 [ V_61 ] , 0 ,
V_180 , V_179 ) ;
F_176 ( V_4 , V_255 -> V_316 , V_255 -> V_315 ) ;
F_176 ( V_4 , V_255 -> V_312 , V_255 -> V_311 ) ;
F_176 ( V_4 , V_255 -> V_319 , V_255 -> V_318 ) ;
for ( V_61 = 0 ; V_61 < V_8 -> V_321 ; V_61 ++ ) {
V_31 = V_8 -> V_313 [ V_61 ] . V_306 ;
if ( ! V_31 )
V_31 = V_8 -> V_9 . V_32 [ 0 ] ;
else if ( V_31 & V_307 )
V_31 &= ~ V_307 ;
F_175 ( V_4 , V_8 -> V_313 [ V_61 ] . V_290 , V_31 ) ;
}
if ( V_8 -> V_325 ) {
F_178 ( V_4 , V_255 -> V_316 , V_255 -> V_315 ,
V_69 ) ;
V_8 -> V_105 = F_145 ( V_4 , V_255 -> V_316 ,
V_255 -> V_315 ) ;
if ( V_8 -> V_327 ) {
F_178 ( V_4 , V_255 -> V_312 ,
V_255 -> V_311 ,
V_355 ) ;
V_8 -> V_331 =
F_145 ( V_4 , V_255 -> V_312 ,
V_255 -> V_311 ) ;
}
}
F_146 ( V_4 ) ;
if ( ! V_8 -> V_330 )
F_144 ( V_4 , V_8 -> V_376 , V_8 -> V_375 , true ) ;
}
static void F_180 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_308 * V_255 = & V_8 -> V_309 ;
int V_61 , V_338 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_39 ; V_61 ++ ) {
T_1 V_31 = V_8 -> V_13 [ V_61 ] ;
if ( ! ( F_138 ( V_4 , V_31 ) & V_384 ) )
continue;
if ( F_177 ( V_4 , V_31 , V_149 ) & V_381 )
V_338 = F_181 ( 0 ) ;
else
V_338 = F_182 ( 0 ) ;
F_86 ( V_4 , V_31 , 0 , V_108 ,
V_338 ) ;
}
for ( V_61 = 0 ; V_61 < V_255 -> V_365 ; V_61 ++ ) {
unsigned int type ;
if ( V_255 -> V_366 [ V_61 ] . type == V_385 )
type = V_228 ;
else
type = V_225 ;
F_86 ( V_4 , V_255 -> V_366 [ V_61 ] . V_290 , 0 ,
V_180 , type ) ;
}
if ( V_8 -> V_183 ) {
if ( V_8 -> V_352 >= 0 ) {
F_86 ( V_4 ,
V_255 -> V_366 [ V_8 -> V_352 ] . V_290 , 0 ,
V_191 ,
V_68 | V_72 ) ;
}
if ( V_8 -> V_353 >= 0 ) {
F_86 ( V_4 ,
V_255 -> V_366 [ V_8 -> V_353 ] . V_290 , 0 ,
V_191 ,
V_68 | V_72 ) ;
}
F_160 ( V_4 ) ;
} else {
F_155 ( V_4 , V_8 -> V_288 [ 0 ] . V_287 ,
V_8 -> V_288 [ 0 ] . V_290 ) ;
}
}
static void F_183 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_308 * V_255 = & V_8 -> V_309 ;
if ( V_8 -> V_9 . V_40 )
F_86 ( V_4 , V_255 -> V_370 [ 0 ] , 0 ,
V_180 , V_181 ) ;
if ( V_8 -> V_44 )
F_86 ( V_4 , V_255 -> V_371 , 0 ,
V_180 , V_225 ) ;
}
static int F_184 ( struct V_3 * V_4 )
{
F_179 ( V_4 ) ;
F_180 ( V_4 ) ;
F_183 ( V_4 ) ;
return 0 ;
}
static int F_185 ( struct V_3 * V_4 , const char * V_386 ,
const char * V_387 , int V_388 ,
T_1 V_31 , int V_389 , int V_390 )
{
static char V_25 [ 32 ] ;
static struct V_89 V_90 [] = {
F_186 ( V_25 , 0 , 0 , 0 ) ,
F_187 ( V_25 , 0 , 0 , 0 ) ,
} ;
static const char * const V_391 [ 2 ] = { L_18 , L_19 } ;
int V_61 , V_66 ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
struct V_47 * V_92 ;
V_90 [ V_61 ] . V_94 = F_188 ( V_31 , 3 , V_390 ,
V_389 ) ;
V_90 [ V_61 ] . V_392 = V_393 ;
V_90 [ V_61 ] . V_221 = V_388 ;
snprintf ( V_25 , sizeof( V_25 ) , L_20 , V_386 , V_387 , V_391 [ V_61 ] ) ;
V_92 = F_50 ( & V_90 [ V_61 ] , V_4 ) ;
if ( ! V_92 )
return - V_93 ;
V_66 = F_51 ( V_4 , V_31 , V_92 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( ! ( F_177 ( V_4 , V_31 , V_389 ) & V_381 ) )
break;
}
return 0 ;
}
static int F_189 ( struct V_3 * V_4 , T_1 V_306 ,
T_1 V_290 , const char * V_25 , int V_249 )
{
unsigned int V_394 ;
if ( V_306 && ! ( V_306 & V_307 ) ) {
V_394 = F_177 ( V_4 , V_306 , V_84 ) ;
if ( V_394 & V_395 )
return F_190 ( V_4 , V_306 , V_25 , V_249 ) ;
}
V_394 = F_177 ( V_4 , V_290 , V_84 ) ;
if ( V_394 & V_395 )
return F_190 ( V_4 , V_290 , V_25 , V_249 ) ;
return 0 ;
}
static int F_191 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 , V_66 ;
int V_396 = 0 , V_397 = 0 , V_398 = 0 ;
static const char * const V_334 [ 3 ] = { L_21 , L_22 , L_23 } ;
if ( V_8 -> V_321 == 1 )
return F_189 ( V_4 , V_8 -> V_313 [ 0 ] . V_306 ,
V_8 -> V_313 [ 0 ] . V_290 ,
L_24 , 0 ) ;
for ( V_61 = 0 ; V_61 < V_8 -> V_321 ; V_61 ++ ) {
const char * V_367 ;
int V_249 , type ;
T_1 V_306 = V_8 -> V_313 [ V_61 ] . V_306 ;
type = V_8 -> V_313 [ V_61 ] . type ;
if ( type == V_314 )
type = V_8 -> V_309 . V_326 ;
switch ( type ) {
case V_314 :
default:
V_367 = V_334 [ V_396 ++ ] ;
V_249 = 0 ;
break;
case V_317 :
V_367 = L_25 ;
V_249 = V_397 ++ ;
break;
case V_320 :
V_367 = L_26 ;
V_249 = V_398 ++ ;
break;
}
V_66 = F_189 ( V_4 , V_306 ,
V_8 -> V_313 [ V_61 ] . V_290 ,
V_367 , V_249 ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_325 ) {
V_66 = F_42 ( V_4 , V_399 ) ;
if ( V_66 < 0 )
return V_66 ;
}
return 0 ;
}
static int F_192 ( struct V_3 * V_4 , T_1 V_31 ,
const char * V_367 , const char * V_400 ,
int V_388 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_39 ; V_61 ++ ) {
T_1 V_401 = V_8 -> V_13 [ V_61 ] ;
int V_249 = F_156 ( V_4 , V_401 , V_31 ) ;
if ( V_249 < 0 )
continue;
if ( V_8 -> V_402 )
V_249 = 0 ;
return F_185 ( V_4 , V_367 , V_400 ,
V_388 , V_401 , V_149 , V_249 ) ;
}
return 0 ;
}
static int F_193 ( struct V_3 * V_4 , int V_249 ,
const char * V_367 , int V_388 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_341 , V_31 ;
int V_61 , V_403 ;
V_31 = V_8 -> V_288 [ V_249 ] . V_290 ;
if ( F_138 ( V_4 , V_31 ) & V_384 )
return F_194 ( V_4 , V_367 , L_27 , V_388 ,
V_31 , V_149 ) ;
V_403 = F_154 ( V_4 , V_8 -> V_288 [ V_249 ] . V_287 , V_31 ,
& V_341 , false , 0 ) ;
if ( V_403 < 0 )
return 0 ;
for ( V_61 = 0 ; V_61 < V_249 ; V_61 ++ ) {
if ( V_8 -> V_288 [ V_61 ] . V_368 == V_341 )
return 0 ;
}
if ( F_138 ( V_4 , V_341 ) & V_380 ) {
V_8 -> V_288 [ V_249 ] . V_368 = V_341 ;
return F_194 ( V_4 , V_367 , L_27 , 0 ,
V_341 , V_84 ) ;
}
return 0 ;
}
static int F_195 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_247 * V_248 = & V_8 -> V_340 ;
const char * V_404 ;
int V_405 [ V_346 ] ;
int V_61 , V_310 , V_66 , V_388 ;
int V_406 ;
if ( ! V_248 -> V_250 )
return 0 ;
V_406 = 0 ;
for ( V_61 = 0 ; V_61 < V_248 -> V_250 ; V_61 ++ ) {
V_388 = F_156 ( V_4 , V_8 -> V_288 [ V_61 ] . V_287 ,
V_8 -> V_288 [ V_61 ] . V_290 ) ;
if ( V_388 < 0 )
continue;
V_405 [ V_61 ] = V_8 -> V_288 [ V_61 ] . V_287 ;
if ( ! V_8 -> V_402 )
V_405 [ V_61 ] |= V_388 << 8 ;
if ( V_61 > 0 && V_405 [ V_61 ] != V_405 [ 0 ] )
V_406 = 1 ;
}
V_404 = NULL ;
V_388 = 0 ;
for ( V_61 = 0 ; V_61 < V_248 -> V_250 ; V_61 ++ ) {
T_1 V_31 = V_8 -> V_288 [ V_61 ] . V_290 ;
const char * V_367 ;
V_367 = F_166 ( V_4 , & V_8 -> V_309 ,
V_8 -> V_288 [ V_61 ] . V_221 ) ;
if ( V_367 == V_404 )
V_388 ++ ;
else
V_388 = 0 ;
V_404 = V_367 ;
V_66 = F_193 ( V_4 , V_61 , V_367 , V_388 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( ! V_406 ) {
if ( V_61 > 0 )
continue;
V_66 = F_192 ( V_4 , V_31 ,
L_28 , L_29 , V_388 ) ;
} else {
bool V_407 = false ;
for ( V_310 = 0 ; V_310 < V_61 ; V_310 ++ ) {
if ( V_405 [ V_310 ] == V_405 [ V_61 ] ) {
V_407 = true ;
break;
}
}
if ( V_407 )
continue;
V_66 = F_192 ( V_4 , V_31 ,
V_367 , L_30 , V_388 ) ;
}
if ( V_66 < 0 )
return V_66 ;
}
if ( V_8 -> V_340 . V_250 > 1 && ! V_8 -> V_183 ) {
V_66 = F_42 ( V_4 , V_408 ) ;
if ( V_66 < 0 )
return V_66 ;
}
return 0 ;
}
static int F_196 ( struct V_3 * V_4 )
{
int V_66 ;
V_66 = F_191 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_195 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
return F_41 ( V_4 ) ;
}
static int F_197 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_31 , V_294 ;
V_294 = V_4 -> V_295 + V_4 -> V_296 ;
for ( V_31 = V_4 -> V_295 ; V_31 < V_294 ; V_31 ++ ) {
unsigned int V_394 = F_138 ( V_4 , V_31 ) ;
if ( F_139 ( V_394 ) != V_347 )
continue;
if ( V_394 & V_299 )
continue;
if ( F_198 ( V_8 -> V_39 >=
F_74 ( V_8 -> V_409 ) ) )
break;
V_8 -> V_409 [ V_8 -> V_39 ++ ] = V_31 ;
}
V_8 -> V_13 = V_8 -> V_409 ;
return 0 ;
}
static void F_199 ( struct V_3 * V_4 , const struct V_410 * V_255 )
{
for (; V_255 -> V_31 ; V_255 ++ )
F_200 ( V_4 , V_255 -> V_31 , V_255 -> V_338 ) ;
}
static void F_201 ( struct V_3 * V_4 ,
const struct V_411 * V_412 ,
const struct V_410 * * V_413 )
{
V_412 = F_202 ( V_4 -> V_414 -> V_415 , V_412 ) ;
if ( V_412 ) {
F_97 ( V_416 L_31 ,
V_412 -> V_25 ) ;
F_199 ( V_4 , V_413 [ V_412 -> V_56 ] ) ;
}
}
static int F_72 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_66 ;
F_203 ( V_416 L_32 ,
V_4 -> V_417 ) ;
V_8 = F_73 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 )
return - V_93 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_118 = 1 ;
switch ( V_4 -> V_35 ) {
case 0x14f15045 :
V_8 -> V_402 = 1 ;
break;
}
F_201 ( V_4 , V_418 , V_419 ) ;
V_66 = F_197 ( V_4 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_173 ( V_4 ) ;
if ( V_66 < 0 ) {
F_40 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
return V_66 ;
}
V_8 -> V_33 = & V_420 ;
V_4 -> V_128 = V_421 ;
if ( V_8 -> V_88 )
F_78 ( V_4 , V_8 -> V_88 ) ;
return 0 ;
}
static int T_3 F_204 ( void )
{
return F_205 ( & V_422 ) ;
}
static void T_4 F_206 ( void )
{
F_207 ( & V_422 ) ;
}
