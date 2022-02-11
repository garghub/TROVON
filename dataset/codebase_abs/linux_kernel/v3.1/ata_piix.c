static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
struct V_7 * V_8 = V_2 -> V_5 -> V_9 ;
const struct V_10 * V_11 = & V_10 [ 0 ] ;
T_1 V_12 ;
while ( V_11 -> V_13 ) {
if ( V_11 -> V_13 == V_4 -> V_13 &&
V_11 -> V_14 == V_4 -> V_15 &&
V_11 -> V_16 == V_4 -> V_17 )
return V_18 ;
V_11 ++ ;
}
V_12 = V_2 -> V_19 == 0 ? V_20 : V_21 ;
if ( ( V_8 -> V_22 & V_12 ) == 0 )
return V_23 ;
return V_24 ;
}
static int F_3 ( struct V_25 * V_26 , unsigned long V_27 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( ! F_4 ( V_4 , & V_28 [ V_2 -> V_19 ] ) )
return - V_29 ;
return F_5 ( V_26 , V_27 ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_3 * V_6 = F_2 ( V_2 -> V_5 -> V_6 ) ;
unsigned long V_32 ;
unsigned int V_33 = V_31 -> V_34 - V_35 ;
unsigned int V_36 = ( V_31 -> V_37 != 0 ) ;
unsigned int V_38 = V_2 -> V_19 ? 0x42 : 0x40 ;
unsigned int V_39 = 0x44 ;
T_2 V_40 ;
T_1 V_41 ;
T_1 V_42 ;
int V_43 = 0 ;
static const
T_1 V_44 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
if ( V_33 >= 2 )
V_43 |= 1 ;
if ( F_7 ( V_31 ) )
V_43 |= 2 ;
if ( V_31 -> V_45 == V_46 )
V_43 |= 4 ;
F_8 ( & V_47 , V_32 ) ;
F_9 ( V_6 , V_38 , & V_40 ) ;
if ( V_36 ) {
V_40 &= 0xff0f ;
V_40 |= 0x4000 ;
V_40 |= ( V_43 << 4 ) ;
F_10 ( V_6 , V_39 , & V_41 ) ;
V_41 &= ( V_2 -> V_19 ? 0x0f : 0xf0 ) ;
V_41 |= ( ( V_44 [ V_33 ] [ 0 ] << 2 ) | V_44 [ V_33 ] [ 1 ] )
<< ( V_2 -> V_19 ? 4 : 0 ) ;
} else {
V_40 &= 0xccf0 ;
V_40 |= V_43 ;
V_40 |=
( V_44 [ V_33 ] [ 0 ] << 12 ) |
( V_44 [ V_33 ] [ 1 ] << 8 ) ;
}
F_11 ( V_6 , V_38 , V_40 ) ;
if ( V_36 )
F_12 ( V_6 , V_39 , V_41 ) ;
if ( V_2 -> V_48 ) {
F_10 ( V_6 , 0x48 , & V_42 ) ;
V_42 &= ~ ( 1 << ( 2 * V_2 -> V_19 + V_31 -> V_37 ) ) ;
F_12 ( V_6 , 0x48 , V_42 ) ;
}
F_13 ( & V_47 , V_32 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_30 * V_31 , int V_49 )
{
struct V_3 * V_6 = F_2 ( V_2 -> V_5 -> V_6 ) ;
unsigned long V_32 ;
T_1 V_38 = V_2 -> V_19 ? 0x42 : 0x40 ;
T_2 V_40 ;
T_1 V_50 = V_31 -> V_51 ;
int V_52 = V_31 -> V_37 + 2 * V_2 -> V_19 ;
T_1 V_42 = 0 ;
static const
T_1 V_44 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 0 } ,
{ 2 , 1 } ,
{ 2 , 3 } , } ;
F_8 ( & V_47 , V_32 ) ;
F_9 ( V_6 , V_38 , & V_40 ) ;
if ( V_2 -> V_48 )
F_10 ( V_6 , 0x48 , & V_42 ) ;
if ( V_50 >= V_53 ) {
unsigned int V_54 = V_31 -> V_51 - V_53 ;
T_2 V_55 ;
T_2 V_56 ;
int V_57 , V_58 ;
V_58 = F_15 ( 2 - ( V_54 & 1 ) , V_54 ) ;
if ( V_54 == 5 )
V_57 = 0x1000 ;
else if ( V_54 > 2 )
V_57 = 1 ;
else
V_57 = 0 ;
V_42 |= ( 1 << V_52 ) ;
F_9 ( V_6 , 0x4A , & V_55 ) ;
V_55 &= ~ ( 3 << ( 4 * V_52 ) ) ;
V_55 |= V_58 << ( 4 * V_52 ) ;
F_11 ( V_6 , 0x4A , V_55 ) ;
if ( V_49 ) {
F_9 ( V_6 , 0x54 , & V_56 ) ;
V_56 &= ~ ( 0x1001 << V_52 ) ;
V_56 |= V_57 << V_52 ;
F_11 ( V_6 , 0x54 , V_56 ) ;
}
} else {
unsigned int V_59 = V_31 -> V_51 - V_60 ;
unsigned int V_43 ;
T_1 V_41 ;
const unsigned int V_61 [ 3 ] = {
V_35 , V_62 , V_63
} ;
int V_33 = V_61 [ V_59 ] - V_35 ;
V_43 = 3 ;
if ( V_31 -> V_34 < V_61 [ V_59 ] )
V_43 |= 8 ;
if ( V_31 -> V_37 ) {
V_40 &= 0xFF4F ;
V_40 |= V_43 << 4 ;
F_10 ( V_6 , 0x44 , & V_41 ) ;
V_41 &= ( V_2 -> V_19 ? 0x0f : 0xf0 ) ;
V_41 |= ( ( V_44 [ V_33 ] [ 0 ] << 2 ) | V_44 [ V_33 ] [ 1 ] ) << ( V_2 -> V_19 ? 4 : 0 ) ;
F_12 ( V_6 , 0x44 , V_41 ) ;
} else {
V_40 &= 0xCCF4 ;
V_40 |= V_43 ;
V_40 |=
( V_44 [ V_33 ] [ 0 ] << 12 ) |
( V_44 [ V_33 ] [ 1 ] << 8 ) ;
}
if ( V_2 -> V_48 )
V_42 &= ~ ( 1 << V_52 ) ;
F_11 ( V_6 , V_38 , V_40 ) ;
}
if ( V_2 -> V_48 )
F_12 ( V_6 , 0x48 , V_42 ) ;
F_13 ( & V_47 , V_32 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
F_14 ( V_2 , V_31 , 0 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
F_14 ( V_2 , V_31 , 1 ) ;
}
static void F_18 ( struct V_25 * V_26 , unsigned int V_64 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_7 * V_8 = V_2 -> V_5 -> V_9 ;
F_19 ( ( ( V_2 -> V_19 * 2 + V_26 -> V_65 ) << 8 ) | V_66 [ V_64 ] ,
V_8 -> V_67 + V_68 ) ;
}
static int F_20 ( struct V_25 * V_26 ,
unsigned int V_64 , T_3 * V_69 )
{
struct V_7 * V_8 = V_26 -> V_2 -> V_5 -> V_9 ;
if ( V_64 >= F_21 ( V_66 ) )
return - V_70 ;
F_18 ( V_26 , V_64 ) ;
* V_69 = F_22 ( V_8 -> V_67 + V_71 ) ;
return 0 ;
}
static int F_23 ( struct V_25 * V_26 ,
unsigned int V_64 , T_3 V_69 )
{
struct V_7 * V_8 = V_26 -> V_2 -> V_5 -> V_9 ;
if ( V_64 >= F_21 ( V_66 ) )
return - V_70 ;
F_18 ( V_26 , V_64 ) ;
F_19 ( V_69 , V_8 -> V_67 + V_71 ) ;
return 0 ;
}
static int F_24 ( struct V_25 * V_26 , enum V_72 V_73 ,
unsigned V_74 )
{
return F_25 ( V_26 , V_73 , false ) ;
}
static bool F_26 ( struct V_1 * V_2 )
{
if ( F_27 ( ! V_2 -> V_75 . V_76 ) )
return false ;
return V_2 -> V_77 -> V_78 ( V_2 ) & V_79 ;
}
static int F_28 ( void )
{
static const struct V_80 V_81 [] = {
{
. V_82 = L_1 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_1 ) ,
} ,
} ,
{
. V_82 = L_1 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_3 ) ,
} ,
} ,
{
. V_82 = L_4 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_5 ) ,
} ,
} ,
{
. V_82 = L_4 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_4 ) ,
} ,
} ,
{
. V_82 = L_6 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_6 ) ,
} ,
} ,
{
. V_82 = L_7 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_7 ) ,
} ,
} ,
{
. V_82 = L_8 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_8 ) ,
} ,
} ,
{
. V_82 = L_9 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_9 ) ,
} ,
} ,
{
. V_82 = L_10 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_10 ) ,
} ,
} ,
{
. V_82 = L_11 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_11 ) ,
} ,
} ,
{
. V_82 = L_12 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_12 ) ,
} ,
} ,
{
. V_82 = L_12 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_13 ) ,
} ,
} ,
{
. V_82 = L_14 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_15 ) ,
} ,
} ,
{
. V_82 = L_16 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_16 ) ,
} ,
} ,
{
. V_82 = L_17 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_17 ) ,
} ,
} ,
{
. V_82 = L_18 ,
. V_83 = {
F_29 ( V_84 , L_2 ) ,
F_29 ( V_85 , L_19 ) ,
} ,
} ,
{
. V_82 = L_20 ,
. V_83 = {
F_29 ( V_84 , L_21 ) ,
F_29 ( V_85 , L_20 ) ,
} ,
} ,
{ }
} ;
static const char * V_86 [] = {
L_22 ,
} ;
int V_87 ;
if ( F_30 ( V_81 ) )
return 1 ;
for ( V_87 = 0 ; V_87 < F_21 ( V_86 ) ; V_87 ++ )
if ( F_31 ( V_88 , V_86 [ V_87 ] , NULL ) )
return 1 ;
if ( F_32 ( V_84 , L_2 ) &&
F_32 ( V_85 , L_23 ) &&
F_32 ( V_89 , L_23 ) &&
F_32 ( V_90 , L_23 ) &&
F_32 ( V_91 , L_2 ) &&
F_32 ( V_92 , L_24 ) &&
F_32 ( V_93 , L_25 ) )
return 1 ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 , T_4 V_94 )
{
struct V_95 * V_5 = F_34 ( & V_4 -> V_6 ) ;
unsigned long V_32 ;
int V_96 = 0 ;
V_96 = F_35 ( V_5 , V_94 ) ;
if ( V_96 )
return V_96 ;
if ( F_28 () && ( V_94 . V_97 & V_98 ) ) {
F_36 ( V_4 ) ;
if ( V_4 -> V_99 == V_100 )
V_4 -> V_99 = V_101 ;
F_8 ( & V_5 -> V_102 , V_32 ) ;
V_5 -> V_32 |= V_103 ;
F_13 ( & V_5 -> V_102 , V_32 ) ;
} else
F_37 ( V_4 , V_94 ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_95 * V_5 = F_34 ( & V_4 -> V_6 ) ;
unsigned long V_32 ;
int V_96 ;
if ( V_5 -> V_32 & V_103 ) {
F_8 ( & V_5 -> V_102 , V_32 ) ;
V_5 -> V_32 &= ~ V_103 ;
F_13 ( & V_5 -> V_102 , V_32 ) ;
F_39 ( V_4 , V_100 ) ;
F_40 ( V_4 ) ;
V_96 = F_41 ( V_4 ) ;
if ( V_96 )
F_42 ( & V_4 -> V_6 ,
L_26 ,
V_96 ) ;
} else
V_96 = F_43 ( V_4 ) ;
if ( V_96 == 0 )
F_44 ( V_5 ) ;
return V_96 ;
}
static T_1 F_45 ( struct V_1 * V_2 )
{
return F_46 ( V_2 ) & ~ V_104 ;
}
static int F_47 ( struct V_3 * V_4 )
{
void T_5 * V_105 ;
T_3 V_106 ;
int V_96 = 0 ;
if ( ! F_48 ( V_4 , V_107 ) ||
! F_49 ( V_4 , V_107 ) )
return 0 ;
V_105 = F_50 ( V_4 , V_107 , 64 ) ;
if ( ! V_105 )
return - V_108 ;
V_106 = F_22 ( V_105 + V_109 ) ;
if ( V_106 & V_110 ) {
V_106 &= ~ V_110 ;
F_19 ( V_106 , V_105 + V_109 ) ;
V_106 = F_22 ( V_105 + V_109 ) ;
if ( V_106 & V_110 )
V_96 = - V_111 ;
}
F_51 ( V_4 , V_105 ) ;
return V_96 ;
}
static int T_6 F_52 ( struct V_3 * V_112 )
{
struct V_3 * V_4 = NULL ;
T_2 V_113 ;
int V_114 = 0 ;
while ( ( V_4 = F_53 ( V_115 , V_116 , V_4 ) ) != NULL ) {
F_9 ( V_4 , 0x41 , & V_113 ) ;
if ( V_4 -> V_117 == 0x00 )
V_114 = 1 ;
else if ( V_113 & ( 1 << 14 ) && V_4 -> V_117 < 5 )
V_114 = 2 ;
}
if ( V_114 )
F_54 ( & V_112 -> V_6 ,
L_27 ,
V_114 == 2 ? L_28
: L_29 ) ;
return V_114 ;
}
static void T_6 F_55 ( struct V_95 * V_5 ,
const struct V_118 * V_119 )
{
struct V_3 * V_4 = F_2 ( V_5 -> V_6 ) ;
T_2 V_120 , V_121 ;
F_9 ( V_4 , V_122 , & V_120 ) ;
V_121 = V_120 | V_119 -> V_123 ;
if ( V_121 != V_120 ) {
F_56 ( L_30 , V_120 , V_121 ) ;
F_11 ( V_4 , V_122 , V_121 ) ;
F_57 ( 150 ) ;
}
}
static const int * T_6 F_58 ( struct V_3 * V_4 ,
struct V_124 * V_125 ,
const struct V_118 * V_119 )
{
const int * V_126 ;
int V_87 , V_127 = 0 ;
T_1 V_128 ;
F_10 ( V_4 , V_129 , & V_128 ) ;
V_126 = V_119 -> V_126 [ V_128 & V_119 -> V_12 ] ;
F_59 ( & V_4 -> V_6 , L_31 ) ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ ) {
switch ( V_126 [ V_87 ] ) {
case V_130 :
V_127 = 1 ;
F_60 ( L_32 ) ;
break;
case V_131 :
F_60 ( L_33 ) ;
break;
case V_132 :
F_61 ( ( V_87 & 1 ) || V_126 [ V_87 + 1 ] != V_132 ) ;
V_125 [ V_87 / 2 ] = V_133 [ V_134 ] ;
V_87 ++ ;
F_60 ( L_34 ) ;
break;
default:
F_60 ( L_35 , V_126 [ V_87 ] ) ;
if ( V_87 & 1 )
V_125 [ V_87 / 2 ] . V_32 |= V_135 ;
break;
}
}
F_60 ( L_36 ) ;
if ( V_127 )
F_42 ( & V_4 -> V_6 , L_37 , V_128 ) ;
return V_126 ;
}
static bool F_62 ( struct V_95 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 -> V_6 ) ;
if ( V_4 -> V_136 == V_115 && V_4 -> V_13 == 0x2920 &&
V_4 -> V_15 == V_137 &&
V_4 -> V_17 == 0xb049 ) {
F_54 ( V_5 -> V_6 ,
L_38 ) ;
return true ;
}
return false ;
}
static int T_6 F_63 ( struct V_95 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 -> V_6 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_25 * V_138 = & V_5 -> V_139 [ 0 ] -> V_26 ;
T_3 V_140 ;
int V_87 , V_96 ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ )
if ( V_8 -> V_126 [ V_87 ] == V_132 )
return 0 ;
if ( F_62 ( V_5 ) )
return 0 ;
if ( ! ( V_5 -> V_139 [ 0 ] -> V_32 & V_141 ) )
return 0 ;
if ( F_48 ( V_4 , V_142 ) == 0 ||
F_49 ( V_4 , V_142 ) != V_143 )
return 0 ;
if ( F_64 ( V_4 , 1 << V_142 , V_144 ) )
return 0 ;
V_8 -> V_67 = F_65 ( V_4 ) [ V_142 ] ;
F_20 ( V_138 , V_145 , & V_140 ) ;
if ( ( V_140 & 0xf00 ) != 0x300 ) {
V_140 |= 0x300 ;
F_23 ( V_138 , V_145 , V_140 ) ;
F_20 ( V_138 , V_145 , & V_140 ) ;
if ( ( V_140 & 0xf00 ) != 0x300 ) {
F_59 ( V_5 -> V_6 ,
L_39 ) ;
return 0 ;
}
}
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
struct V_1 * V_2 = V_5 -> V_139 [ V_87 ] ;
V_2 -> V_77 = & V_146 ;
if ( V_2 -> V_32 & V_135 ) {
V_96 = F_66 ( V_2 ) ;
if ( V_96 )
return V_96 ;
}
}
return 0 ;
}
static void F_67 ( struct V_95 * V_5 )
{
static const struct V_80 V_81 [] = {
{
. V_82 = L_40 ,
. V_83 = {
F_29 ( V_84 , L_41 ) ,
F_29 ( V_85 , L_40 ) ,
} ,
} ,
{ }
} ;
struct V_3 * V_4 = F_2 ( V_5 -> V_6 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
if ( ! F_30 ( V_81 ) )
return;
if ( V_8 -> V_22 & ( 1 << 18 ) ) {
F_59 ( & V_4 -> V_6 , L_42 ) ;
F_68 ( V_4 , V_147 ,
V_8 -> V_22 & ~ ( 1 << 18 ) ) ;
}
}
static bool F_69 ( struct V_3 * V_4 )
{
static const struct V_80 V_148 [] = {
{
. V_82 = L_43 ,
. V_83 = {
F_29 ( V_84 , L_44 ) ,
F_29 ( V_85 , L_43 ) ,
} ,
. V_149 = ( void * ) 0x1FUL ,
} ,
{
. V_82 = L_45 ,
. V_83 = {
F_29 ( V_84 , L_44 ) ,
F_29 ( V_85 , L_45 ) ,
} ,
. V_149 = ( void * ) 0x1FUL ,
} ,
{ }
} ;
const struct V_80 * V_150 = F_70 ( V_148 ) ;
if ( V_150 ) {
unsigned long V_151 = ( unsigned long ) V_150 -> V_149 ;
return V_151 == F_71 ( V_4 -> V_152 ) ;
}
return false ;
}
static int T_6 F_72 ( struct V_3 * V_4 ,
const struct V_153 * V_154 )
{
struct V_13 * V_6 = & V_4 -> V_6 ;
struct V_124 V_155 [ 2 ] ;
const struct V_124 * V_156 [] = { & V_155 [ 0 ] , & V_155 [ 1 ] } ;
struct V_157 * V_158 = & V_159 ;
unsigned long V_160 ;
struct V_95 * V_5 ;
struct V_7 * V_8 ;
int V_96 ;
F_73 ( & V_4 -> V_6 , V_161 ) ;
if ( ! V_162 && V_154 -> V_149 >= V_163 )
return - V_164 ;
if ( F_69 ( V_4 ) ) {
V_133 [ V_154 -> V_149 ] . V_32 |=
V_165 |
V_166 ;
F_59 ( & V_4 -> V_6 , L_46
L_47 ) ;
}
V_155 [ 0 ] = V_133 [ V_154 -> V_149 ] ;
V_155 [ 1 ] = V_133 [ V_154 -> V_149 ] ;
V_160 = V_155 [ 0 ] . V_32 ;
V_96 = F_74 ( V_4 ) ;
if ( V_96 )
return V_96 ;
V_8 = F_75 ( V_6 , sizeof( * V_8 ) , V_167 ) ;
if ( ! V_8 )
return - V_108 ;
F_76 ( V_4 , V_147 , & V_8 -> V_22 ) ;
if ( V_4 -> V_136 == V_115 && V_4 -> V_13 == 0x2652 ) {
V_96 = F_47 ( V_4 ) ;
if ( V_96 )
return V_96 ;
}
if ( V_160 & V_168 )
V_8 -> V_126 = F_58 ( V_4 , V_155 ,
V_169 [ V_154 -> V_149 ] ) ;
V_96 = F_77 ( V_4 , V_156 , & V_5 ) ;
if ( V_96 )
return V_96 ;
V_5 -> V_9 = V_8 ;
if ( V_160 & V_168 ) {
F_55 ( V_5 , V_169 [ V_154 -> V_149 ] ) ;
V_96 = F_63 ( V_5 ) ;
if ( V_96 )
return V_96 ;
if ( V_5 -> V_139 [ 0 ] -> V_77 == & V_146 )
V_158 = & V_170 ;
}
F_67 ( V_5 ) ;
if ( V_160 & V_171 )
F_78 ( V_4 , 1 ) ;
if ( F_52 ( V_4 ) ) {
V_5 -> V_139 [ 0 ] -> V_172 = 0 ;
V_5 -> V_139 [ 0 ] -> V_48 = 0 ;
V_5 -> V_139 [ 1 ] -> V_172 = 0 ;
V_5 -> V_139 [ 1 ] -> V_48 = 0 ;
}
V_5 -> V_32 |= V_173 ;
F_79 ( V_4 ) ;
return F_80 ( V_5 , V_174 , V_158 ) ;
}
static void F_81 ( struct V_3 * V_4 )
{
struct V_95 * V_5 = F_34 ( & V_4 -> V_6 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_68 ( V_4 , V_147 , V_8 -> V_22 ) ;
F_82 ( V_4 ) ;
}
static int T_7 F_83 ( void )
{
int V_96 ;
F_56 ( L_48 ) ;
V_96 = F_84 ( & V_175 ) ;
if ( V_96 )
return V_96 ;
V_162 = 0 ;
F_56 ( L_49 ) ;
return 0 ;
}
static void T_8 F_85 ( void )
{
F_86 ( & V_175 ) ;
}
