static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 )
{
T_2 V_8 = F_5 ( V_3 , V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 &= ~ V_6 ;
V_8 |= V_7 & V_6 ;
return F_6 ( V_3 , V_5 , V_8 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
const struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_6 ( V_3 , V_12 ,
( V_10 -> V_13 & 0x0F00 ) >> 4 |
( V_10 -> V_14 & 0x0F00 ) >> 8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_3 , V_15 ,
V_10 -> V_14 & 0x00FF ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_3 , V_16 ,
V_10 -> V_13 & 0x00FF ) ;
return V_11 ;
}
static int F_8 ( struct V_2 * V_3 ,
const struct V_17 * V_18 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
int V_11 ;
V_11 = F_6 ( V_3 , V_20 ,
( V_18 -> V_21 & 0x07F8 ) >> 3 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_3 , V_22 ,
( V_18 -> V_23 & 0x07F8 ) >> 3 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( 1 == V_19 -> V_24 )
V_11 = F_4 ( V_3 , V_25 , 0x77 ,
( V_18 -> V_21 & 0x0007 ) << 4 |
( V_18 -> V_23 & 0x0007 ) ) ;
return V_11 ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_4 ( V_3 , V_26 , V_27 , V_27 ) ;
F_10 ( 1 ) ;
}
static int F_11 ( struct V_2 * V_3 , int V_28 )
{
int V_11 ;
T_1 V_29 ;
T_1 V_30 ;
if ( V_28 ) {
V_29 = 0 ;
V_30 = 0 ;
} else {
V_29 = V_31 | V_32 | V_33 ;
V_30 = V_34 ;
}
V_11 = F_4 ( V_3 , V_26 , V_35 , V_29 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_4 ( V_3 , V_36 , V_37 , V_30 ) ;
}
static const struct V_9 *
F_12 ( struct V_38 * V_39 , T_3 V_40 , T_3 V_41 )
{
const struct V_9 * V_10 ;
const struct V_9 * V_11 = NULL ;
T_4 V_42 = V_39 -> V_43 -> V_44 ;
T_5 V_45 = 0xffffffff , V_46 ;
int V_47 , V_48 ;
if ( V_42 & V_49 ) {
V_10 = V_50 ;
V_47 = F_13 ( V_50 ) ;
} else if ( V_42 & V_51 ) {
V_10 = V_52 ;
V_47 = F_13 ( V_52 ) ;
} else {
return NULL ;
}
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
V_46 = abs ( V_40 - V_10 [ V_48 ] . V_40 ) +
abs ( V_41 - V_10 [ V_48 ] . V_41 ) ;
if ( V_46 < V_45 ) {
V_45 = V_46 ;
V_11 = V_10 + V_48 ;
}
}
return V_11 ;
}
static int F_14 ( struct V_53 * V_54 , int V_28 )
{
struct V_2 * V_3 = F_15 ( V_54 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_8 ;
int V_11 ;
if ( ! V_28 ) {
switch ( V_19 -> V_24 ) {
case 0 :
V_8 = V_55 ;
break;
case 1 :
V_8 = V_56 ;
break;
default:
F_16 ( & V_3 -> V_57 , L_1 ) ;
return - V_58 ;
}
} else {
V_8 = V_59 ;
if ( ! V_19 -> V_10 ) {
F_16 ( & V_3 -> V_57 , L_2 ) ;
return - V_60 ;
}
F_17 ( & V_3 -> V_57 , L_3 ,
V_19 -> V_10 -> V_61 ,
V_19 -> V_10 -> V_40 ,
V_19 -> V_10 -> V_41 ) ;
}
V_11 = F_4 ( V_3 , V_62 , V_63 , V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_11 ( V_3 , V_28 ) ;
}
static int F_18 ( struct V_38 * V_39 ,
unsigned long V_64 )
{
struct V_53 * V_54 = F_19 ( V_39 ) ;
struct V_2 * V_3 = F_15 ( V_54 ) ;
T_1 V_8 = V_65 | V_66 ;
if ( V_64 & V_67 )
V_8 |= V_68 ;
if ( V_64 & V_69 )
V_8 |= V_70 ;
return F_6 ( V_3 , V_71 , V_8 ) ;
}
static unsigned long F_20 ( struct V_38 * V_39 )
{
struct V_2 * V_3 = F_21 ( F_22 ( V_39 ) ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_72 * V_73 = F_23 ( V_39 ) ;
unsigned long V_64 = V_74 | V_75 |
V_76 | V_77 |
V_69 | V_67 |
V_78 | V_19 -> V_79 -> V_80 ;
return F_24 ( V_73 , V_64 ) ;
}
static int F_25 ( struct V_53 * V_54 , T_4 V_42 )
{
int V_11 = - V_58 ;
if ( V_42 & ( V_49 | V_51 ) )
V_11 = 0 ;
return V_11 ;
}
static int F_26 ( struct V_38 * V_39 ,
struct V_81 * V_82 )
{
V_82 -> type = V_83 ;
V_82 -> V_84 = V_85 ;
strcpy ( V_82 -> V_61 , L_4 ) ;
return 0 ;
}
static int F_27 ( struct V_53 * V_54 ,
struct V_86 * V_87 )
{
struct V_2 * V_3 = F_15 ( V_54 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
V_87 -> V_88 = V_89 ;
V_87 -> V_24 = V_19 -> V_24 ;
return 0 ;
}
static int F_28 ( struct V_53 * V_54 ,
struct V_90 * V_91 )
{
struct V_2 * V_3 = F_15 ( V_54 ) ;
int V_11 ;
if ( V_91 -> V_91 > 0xff )
return - V_58 ;
V_11 = F_5 ( V_3 , V_91 -> V_91 ) ;
if ( V_11 < 0 )
return V_11 ;
V_91 -> V_8 = ( V_92 ) V_11 ;
return 0 ;
}
static int F_29 ( struct V_53 * V_54 ,
struct V_90 * V_91 )
{
struct V_2 * V_3 = F_15 ( V_54 ) ;
if ( V_91 -> V_91 > 0xff ||
V_91 -> V_8 > 0xff )
return - V_58 ;
return F_6 ( V_3 , V_91 -> V_91 , V_91 -> V_8 ) ;
}
static int F_30 ( struct V_53 * V_54 , struct V_93 * V_94 )
{
struct V_95 * V_96 = & V_94 -> V_97 ;
struct V_2 * V_3 = F_15 ( V_54 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_38 * V_39 = V_3 -> V_57 . V_98 ;
int V_11 = - V_58 ;
T_1 V_8 ;
V_19 -> V_10 = F_12 ( V_39 , V_96 -> V_40 , V_96 -> V_41 ) ;
if ( ! V_19 -> V_10 )
goto V_99;
F_9 ( V_3 ) ;
V_8 = 0x00 ;
if ( V_100 == V_19 -> V_79 -> V_80 )
V_8 = V_101 ;
V_11 = F_4 ( V_3 , V_62 , V_101 , V_8 ) ;
if ( V_11 < 0 )
goto V_99;
switch ( V_19 -> V_79 -> V_102 ) {
case V_103 :
V_8 = V_104 ; break;
case V_105 :
V_8 = V_106 ; break;
case V_107 :
V_8 = V_108 ; break;
case V_109 :
V_8 = V_110 ; break;
case V_111 :
V_8 = V_112 ; break;
case V_113 :
V_8 = V_114 ; break;
case V_115 :
V_8 = V_116 ; break;
case V_117 :
V_8 = V_118 ; break;
default:
V_8 = 0 ;
}
V_11 = F_4 ( V_3 , V_119 , V_120 , V_8 ) ;
if ( V_11 < 0 )
goto V_99;
V_11 = F_7 ( V_3 , V_19 -> V_10 ) ;
if ( V_11 < 0 )
goto V_99;
V_11 = F_8 ( V_3 , & V_17 ) ;
if ( V_11 < 0 )
goto V_99;
V_96 -> V_40 = V_19 -> V_10 -> V_40 ;
V_96 -> V_41 = V_19 -> V_10 -> V_41 ;
V_96 -> V_121 = 0 ;
V_96 -> V_122 = 0 ;
return V_11 ;
V_99:
F_9 ( V_3 ) ;
V_19 -> V_10 = NULL ;
return V_11 ;
}
static int F_31 ( struct V_53 * V_54 , struct V_93 * V_94 )
{
struct V_2 * V_3 = F_15 ( V_54 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
if ( ! V_19 -> V_10 ) {
int V_11 ;
struct V_93 V_123 = {
. V_97 = {
. V_121 = 0 ,
. V_122 = 0 ,
. V_40 = 640 ,
. V_41 = 480 ,
} ,
} ;
V_11 = F_30 ( V_54 , & V_123 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_94 -> V_97 . V_121 = 0 ;
V_94 -> V_97 . V_122 = 0 ;
V_94 -> V_97 . V_40 = V_19 -> V_10 -> V_40 ;
V_94 -> V_97 . V_41 = V_19 -> V_10 -> V_41 ;
V_94 -> type = V_124 ;
return 0 ;
}
static int F_32 ( struct V_53 * V_54 , struct V_125 * V_94 )
{
V_94 -> V_126 . V_121 = 0 ;
V_94 -> V_126 . V_122 = 0 ;
V_94 -> V_126 . V_40 = 768 ;
V_94 -> V_126 . V_41 = 576 ;
V_94 -> V_127 . V_121 = 0 ;
V_94 -> V_127 . V_122 = 0 ;
V_94 -> V_127 . V_40 = 640 ;
V_94 -> V_127 . V_41 = 480 ;
V_94 -> type = V_124 ;
V_94 -> V_128 . V_129 = 1 ;
V_94 -> V_128 . V_130 = 1 ;
return 0 ;
}
static int F_33 ( struct V_53 * V_54 ,
struct V_131 * V_132 )
{
struct V_2 * V_3 = F_15 ( V_54 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
if ( ! V_19 -> V_10 ) {
int V_11 ;
struct V_93 V_123 = {
. V_97 = {
. V_121 = 0 ,
. V_122 = 0 ,
. V_40 = 640 ,
. V_41 = 480 ,
} ,
} ;
V_11 = F_30 ( V_54 , & V_123 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_132 -> V_40 = V_19 -> V_10 -> V_40 ;
V_132 -> V_41 = V_19 -> V_10 -> V_41 ;
V_132 -> V_133 = V_134 ;
V_132 -> V_135 = V_136 ;
V_132 -> V_137 = V_138 ;
return 0 ;
}
static int F_34 ( struct V_53 * V_54 ,
struct V_131 * V_132 )
{
struct V_2 * V_3 = F_15 ( V_54 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_93 V_94 = {
. V_97 = {
. V_121 = 0 ,
. V_122 = 0 ,
. V_40 = V_132 -> V_40 ,
. V_41 = V_132 -> V_41 ,
} ,
} ;
int V_11 ;
F_35 ( V_132 -> V_137 != V_139 &&
V_132 -> V_137 != V_138 ) ;
if ( V_132 -> V_133 != V_134 )
return - V_58 ;
V_132 -> V_135 = V_136 ;
V_11 = F_30 ( V_54 , & V_94 ) ;
if ( ! V_11 ) {
V_132 -> V_40 = V_19 -> V_10 -> V_40 ;
V_132 -> V_41 = V_19 -> V_10 -> V_41 ;
}
return V_11 ;
}
static int F_36 ( struct V_53 * V_54 ,
struct V_131 * V_132 )
{
struct V_2 * V_3 = F_15 ( V_54 ) ;
struct V_38 * V_39 = V_3 -> V_57 . V_98 ;
const struct V_9 * V_10 ;
if ( V_139 == V_132 -> V_137 ) {
V_132 -> V_137 = V_138 ;
} else if ( V_138 != V_132 -> V_137 ) {
F_16 ( & V_3 -> V_57 , L_5 , V_132 -> V_137 ) ;
return - V_58 ;
}
V_132 -> V_133 = V_134 ;
V_132 -> V_135 = V_136 ;
V_10 = F_12 ( V_39 , V_132 -> V_40 , V_132 -> V_41 ) ;
if ( ! V_10 )
return - V_58 ;
V_132 -> V_40 = V_10 -> V_40 ;
V_132 -> V_41 = V_10 -> V_41 ;
return 0 ;
}
static int F_37 ( struct V_38 * V_39 ,
struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_2 V_87 ;
if ( ! V_39 -> V_57 . V_140 ||
F_38 ( V_39 -> V_57 . V_140 ) -> V_141 != V_39 -> V_142 )
return - V_143 ;
if ( V_100 != V_19 -> V_79 -> V_80 &&
V_144 != V_19 -> V_79 -> V_80 ) {
F_16 ( & V_3 -> V_57 , L_6 ) ;
return - V_143 ;
}
V_87 = F_5 ( V_3 , V_145 ) ;
V_19 -> V_24 = F_39 ( V_87 ) ;
V_87 = F_40 ( V_87 ) ;
if ( 0x0B != V_87 ||
0x01 < V_19 -> V_24 ) {
F_16 ( & V_3 -> V_57 ,
L_7 ,
V_87 , V_19 -> V_24 ) ;
return - V_143 ;
}
F_41 ( & V_3 -> V_57 ,
L_8 , V_87 , V_19 -> V_24 ) ;
V_39 -> V_43 -> V_146 = V_49 | V_51 ;
V_39 -> V_43 -> V_44 = V_49 ;
return 0 ;
}
static int F_42 ( struct V_53 * V_54 , unsigned int V_147 ,
enum V_148 * V_133 )
{
if ( V_147 )
return - V_58 ;
* V_133 = V_134 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 ,
const struct V_149 * V_150 )
{
struct V_1 * V_19 ;
struct V_151 * V_79 ;
struct V_38 * V_39 = V_3 -> V_57 . V_98 ;
struct V_152 * V_153 =
F_44 ( V_3 -> V_57 . V_140 ) ;
struct V_72 * V_73 ;
int V_11 ;
if ( ! V_39 ) {
F_16 ( & V_3 -> V_57 , L_9 ) ;
return - V_58 ;
}
V_73 = F_23 ( V_39 ) ;
if ( ! V_73 || ! V_73 -> V_19 )
return - V_58 ;
V_79 = V_73 -> V_19 ;
if ( ! F_45 ( V_153 , V_154 ) ) {
F_16 ( & V_3 -> V_57 ,
L_10
L_11 ) ;
return - V_155 ;
}
V_19 = F_46 ( sizeof( * V_19 ) , V_156 ) ;
if ( ! V_19 )
return - V_157 ;
V_19 -> V_79 = V_79 ;
F_47 ( & V_19 -> V_4 , V_3 , & V_158 ) ;
V_39 -> V_159 = & V_160 ;
V_39 -> V_142 = V_73 -> V_161 ;
V_11 = F_37 ( V_39 , V_3 ) ;
if ( V_11 ) {
V_39 -> V_159 = NULL ;
F_48 ( V_19 ) ;
}
return V_11 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_38 * V_39 = V_3 -> V_57 . V_98 ;
V_39 -> V_159 = NULL ;
F_48 ( V_19 ) ;
return 0 ;
}
static int T_6 F_50 ( void )
{
return F_51 ( & V_162 ) ;
}
static void T_7 F_52 ( void )
{
F_53 ( & V_162 ) ;
}
