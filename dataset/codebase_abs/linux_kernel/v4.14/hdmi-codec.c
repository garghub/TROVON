static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_4 -> type = V_9 ;
V_4 -> V_10 = sizeof( V_8 -> V_11 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
memcpy ( V_13 -> V_14 . V_15 . V_16 , V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
return 0 ;
}
static unsigned long F_5 ( int V_17 )
{
int V_18 ;
static const unsigned long V_19 [] = {
[ 0 ] = V_20 | V_21 , [ 1 ] = V_22 , [ 2 ] = V_23 , [ 3 ] = V_24 | V_25 ,
[ 4 ] = V_26 , [ 5 ] = V_27 | V_28 , [ 6 ] = V_29 | V_30 ,
} ;
unsigned long V_31 = 0 ;
for ( V_18 = 0 ; V_18 < F_6 ( V_19 ) ; V_18 ++ ) {
if ( V_17 & ( 1 << V_18 ) )
V_31 |= V_19 [ V_18 ] ;
}
return V_31 ;
}
static void F_7 ( struct V_7 * V_8 )
{
T_1 V_17 ;
unsigned long V_31 ;
V_17 = F_8 ( V_8 -> V_11 ) ;
V_31 = F_5 ( V_17 ) ;
if ( ( V_31 & ~ ( V_20 | V_21 ) ) && V_8 -> V_32 -> V_33 > 2 )
V_8 -> V_32 -> V_34 = V_35 ;
else
V_8 -> V_32 -> V_34 = V_36 ;
}
static int F_9 ( struct V_7 * V_8 ,
unsigned char V_37 )
{
int V_18 ;
T_1 V_17 ;
unsigned long V_31 ;
const struct V_38 * V_39 = V_40 ;
V_17 = F_8 ( V_8 -> V_11 ) ;
V_31 = F_5 ( V_17 ) ;
for ( V_18 = 0 ; V_18 < F_6 ( V_40 ) ; V_18 ++ , V_39 ++ ) {
if ( ! V_17 && V_39 -> V_41 == 0 )
return V_18 ;
if ( V_39 -> V_42 != V_37 )
continue;
if ( ! ( V_39 -> V_43 == ( V_31 & V_39 -> V_43 ) ) )
continue;
return V_18 ;
}
return - V_44 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
unsigned const char * V_45 ;
unsigned int V_18 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_47 -> V_48 ;
V_45 = V_47 -> V_34 [ V_8 -> V_49 ] . V_45 ;
for ( V_18 = 0 ; V_18 < V_47 -> V_33 ; V_18 ++ ) {
if ( V_8 -> V_49 == V_50 )
V_13 -> V_14 . integer . V_14 [ V_18 ] = 0 ;
else
V_13 -> V_14 . integer . V_14 [ V_18 ] = V_45 [ V_18 ] ;
}
return 0 ;
}
static int F_11 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = F_12 ( V_54 ) ;
int V_55 = 0 ;
F_13 ( & V_8 -> V_56 ) ;
if ( ! V_8 -> V_57 ) {
V_8 -> V_57 = V_52 ;
} else if ( V_8 -> V_57 != V_52 ) {
F_14 ( V_54 -> V_58 , L_1 ) ;
V_55 = - V_44 ;
}
F_15 ( & V_8 -> V_56 ) ;
return V_55 ;
}
static int F_16 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = F_12 ( V_54 ) ;
int V_55 = 0 ;
F_17 ( V_54 -> V_58 , L_2 , V_59 ) ;
V_55 = F_11 ( V_52 , V_54 ) ;
if ( V_55 )
return V_55 ;
if ( V_8 -> V_60 . V_61 -> V_62 ) {
V_55 = V_8 -> V_60 . V_61 -> V_62 ( V_54 -> V_58 -> V_63 , V_8 -> V_60 . V_16 ) ;
if ( V_55 ) {
F_13 ( & V_8 -> V_56 ) ;
V_8 -> V_57 = NULL ;
F_15 ( & V_8 -> V_56 ) ;
return V_55 ;
}
}
if ( V_8 -> V_60 . V_61 -> V_64 ) {
V_55 = V_8 -> V_60 . V_61 -> V_64 ( V_54 -> V_58 -> V_63 , V_8 -> V_60 . V_16 ,
V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
if ( ! V_55 ) {
V_55 = F_18 ( V_52 -> V_65 ,
V_8 -> V_11 ) ;
if ( V_55 )
return V_55 ;
}
F_7 ( V_8 ) ;
}
return 0 ;
}
static void F_19 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = F_12 ( V_54 ) ;
F_17 ( V_54 -> V_58 , L_2 , V_59 ) ;
F_20 ( V_8 -> V_57 != V_52 ) ;
V_8 -> V_49 = V_50 ;
V_8 -> V_60 . V_61 -> V_66 ( V_54 -> V_58 -> V_63 , V_8 -> V_60 . V_16 ) ;
F_13 ( & V_8 -> V_56 ) ;
V_8 -> V_57 = NULL ;
F_15 ( & V_8 -> V_56 ) ;
}
static int F_21 ( struct V_51 * V_52 ,
struct V_67 * V_68 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = F_12 ( V_54 ) ;
struct V_69 V_70 = {
. V_71 = {
. V_72 = { 0 } ,
. V_73 = { 0 } ,
. V_74 = 0 ,
. V_75 = { 0 } ,
}
} ;
int V_55 , V_76 ;
F_17 ( V_54 -> V_58 , L_3 , V_59 ,
F_22 ( V_68 ) , F_23 ( V_68 ) ,
F_24 ( V_68 ) ) ;
if ( F_22 ( V_68 ) > 24 )
V_68 -> V_77 = 24 ;
V_55 = F_25 ( V_68 , V_70 . V_71 . V_72 ,
sizeof( V_70 . V_71 . V_72 ) ) ;
if ( V_55 < 0 ) {
F_14 ( V_54 -> V_58 , L_4 ,
V_55 ) ;
return V_55 ;
}
V_55 = F_11 ( V_52 , V_54 ) ;
if ( V_55 )
return V_55 ;
F_26 ( & V_70 . V_78 ) ;
V_70 . V_78 . V_37 = F_24 ( V_68 ) ;
V_70 . V_78 . V_79 = V_80 ;
V_70 . V_78 . V_81 = V_82 ;
V_70 . V_78 . V_83 = V_84 ;
V_76 = F_9 ( V_8 , V_70 . V_78 . V_37 ) ;
if ( V_76 < 0 ) {
F_14 ( V_54 -> V_58 , L_5 ,
V_76 ) ;
V_8 -> V_49 = V_50 ;
return V_76 ;
}
V_70 . V_78 . V_85 = V_40 [ V_76 ] . V_41 ;
V_8 -> V_49 = V_40 [ V_76 ] . V_41 ;
V_70 . V_86 = F_22 ( V_68 ) ;
V_70 . V_87 = F_23 ( V_68 ) ;
V_70 . V_37 = F_24 ( V_68 ) ;
return V_8 -> V_60 . V_61 -> V_88 ( V_54 -> V_58 -> V_63 , V_8 -> V_60 . V_16 ,
& V_8 -> V_89 [ V_54 -> V_90 ] , & V_70 ) ;
}
static int F_27 ( struct V_53 * V_54 ,
unsigned int V_91 )
{
struct V_7 * V_8 = F_12 ( V_54 ) ;
struct V_92 V_93 = { 0 } ;
int V_55 = 0 ;
F_17 ( V_54 -> V_58 , L_2 , V_59 ) ;
if ( V_54 -> V_90 == V_94 ) {
V_93 . V_91 = V_95 ;
} else {
switch ( V_91 & V_96 ) {
case V_97 :
V_93 . V_98 = 1 ;
V_93 . V_99 = 1 ;
break;
case V_100 :
V_93 . V_99 = 1 ;
break;
case V_101 :
V_93 . V_98 = 1 ;
break;
case V_102 :
break;
default:
return - V_44 ;
}
switch ( V_91 & V_103 ) {
case V_104 :
break;
case V_105 :
V_93 . V_106 = 1 ;
break;
case V_107 :
V_93 . V_108 = 1 ;
break;
case V_109 :
V_93 . V_106 = 1 ;
V_93 . V_108 = 1 ;
break;
}
switch ( V_91 & V_110 ) {
case V_111 :
V_93 . V_91 = V_112 ;
break;
case V_113 :
V_93 . V_91 = V_114 ;
break;
case V_115 :
V_93 . V_91 = V_116 ;
break;
case V_117 :
V_93 . V_91 = V_118 ;
break;
case V_119 :
V_93 . V_91 = V_120 ;
break;
case V_121 :
V_93 . V_91 = V_122 ;
break;
default:
F_14 ( V_54 -> V_58 , L_6 ) ;
return - V_44 ;
}
}
V_8 -> V_89 [ V_54 -> V_90 ] = V_93 ;
return V_55 ;
}
static int F_28 ( struct V_53 * V_54 , int V_123 )
{
struct V_7 * V_8 = F_12 ( V_54 ) ;
F_17 ( V_54 -> V_58 , L_2 , V_59 ) ;
if ( V_8 -> V_60 . V_61 -> V_124 )
return V_8 -> V_60 . V_61 -> V_124 ( V_54 -> V_58 -> V_63 ,
V_8 -> V_60 . V_16 , V_123 ) ;
return 0 ;
}
static int F_29 ( struct V_125 * V_126 ,
struct V_53 * V_54 )
{
struct V_127 * V_128 = V_54 -> V_129 ;
struct V_7 * V_8 = F_12 ( V_54 ) ;
struct V_1 * V_130 ;
struct V_131 V_132 = {
. V_133 = V_134 |
V_135 ,
. V_136 = V_137 ,
. V_138 = L_7 ,
. V_47 = F_1 ,
. V_139 = F_4 ,
. V_140 = V_126 -> V_141 -> V_140 ,
} ;
int V_55 ;
F_17 ( V_54 -> V_58 , L_2 , V_59 ) ;
V_55 = F_30 ( V_126 -> V_141 , V_142 ,
NULL , V_128 -> V_143 . V_144 , 0 ,
& V_8 -> V_32 ) ;
if ( V_55 < 0 )
return V_55 ;
V_8 -> V_32 -> V_48 = V_8 ;
V_8 -> V_32 -> V_130 -> V_139 = F_10 ;
V_8 -> V_32 -> V_34 = V_36 ;
V_8 -> V_49 = V_50 ;
V_130 = F_31 ( & V_132 , V_54 -> V_6 ) ;
if ( ! V_130 )
return - V_145 ;
return F_32 ( V_126 -> V_146 -> V_147 , V_130 ) ;
}
static int F_33 ( struct V_5 * V_6 ,
struct V_148 * V_149 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_55 = - V_150 ;
if ( V_8 -> V_60 . V_61 -> V_151 )
V_55 = V_8 -> V_60 . V_61 -> V_151 ( V_6 , V_149 ) ;
return V_55 ;
}
static int F_34 ( struct V_152 * V_153 )
{
struct V_154 * V_60 = V_153 -> V_58 . V_155 ;
struct V_140 * V_58 = & V_153 -> V_58 ;
struct V_7 * V_8 ;
int V_156 , V_18 = 0 ;
int V_55 ;
F_17 ( V_58 , L_2 , V_59 ) ;
if ( ! V_60 ) {
F_14 ( V_58 , L_8 , V_59 ) ;
return - V_44 ;
}
V_156 = V_60 -> V_157 + V_60 -> V_158 ;
if ( V_156 < 1 || ! V_60 -> V_61 || ! V_60 -> V_61 -> V_88 ||
! V_60 -> V_61 -> V_66 ) {
F_14 ( V_58 , L_9 , V_59 ) ;
return - V_44 ;
}
V_8 = F_35 ( V_58 , sizeof( * V_8 ) , V_159 ) ;
if ( ! V_8 )
return - V_145 ;
V_8 -> V_60 = * V_60 ;
F_36 ( & V_8 -> V_56 ) ;
V_8 -> V_160 = F_35 ( V_58 , V_156 * sizeof( * V_8 -> V_160 ) ,
V_159 ) ;
if ( ! V_8 -> V_160 )
return - V_145 ;
if ( V_60 -> V_157 ) {
V_8 -> V_160 [ V_18 ] = V_161 ;
V_8 -> V_160 [ V_18 ] . V_143 . V_144 =
V_60 -> V_162 ;
V_18 ++ ;
}
if ( V_60 -> V_158 )
V_8 -> V_160 [ V_18 ] = V_163 ;
V_55 = F_37 ( V_58 , & V_164 , V_8 -> V_160 ,
V_156 ) ;
if ( V_55 ) {
F_14 ( V_58 , L_10 ,
V_59 , V_55 ) ;
return V_55 ;
}
F_38 ( V_58 , V_8 ) ;
return 0 ;
}
static int F_39 ( struct V_152 * V_153 )
{
struct V_140 * V_58 = & V_153 -> V_58 ;
struct V_7 * V_8 ;
V_8 = F_40 ( V_58 ) ;
F_41 ( V_8 -> V_32 ) ;
F_42 ( V_58 ) ;
return 0 ;
}
