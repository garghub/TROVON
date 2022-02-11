static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 = V_6 ? V_8 : V_9 ;
F_1 ( V_2 , V_10 , V_2 -> V_11 ^ V_7 ) ;
F_1 ( V_2 , V_10 , V_2 -> V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
T_1 V_21 ;
T_1 V_22 = V_6 ? V_23 : V_24 ;
V_21 = F_3 ( V_2 , V_25 ) ;
if ( V_21 & V_22 ) {
F_1 ( V_2 , V_25 ,
V_21 & ~ V_22 ) ;
F_5 ( V_2 , V_6 ) ;
}
if ( V_2 -> V_11 & ( V_26 | V_27 |
V_28 | V_29 ) ) {
V_21 |= V_30 ;
F_1 ( V_2 , V_25 , V_21 ) ;
}
if ( V_6 ) {
if ( V_18 -> V_31 -> V_32 -> V_33 ) {
int V_34 = V_18 -> V_31 -> V_32 -> V_33 ( V_13 ,
V_35 ) ;
if ( V_34 < 0 )
F_7 ( V_36 L_1 ) ;
}
V_21 = F_3 ( V_2 , V_25 ) ;
V_21 |= V_23 ;
F_1 ( V_2 , V_25 , V_21 ) ;
F_8 ( 100 ) ;
V_21 = F_3 ( V_2 , V_25 ) ;
V_21 &= ~ V_23 ;
F_1 ( V_2 , V_25 , V_21 ) ;
F_5 ( V_2 , V_6 ) ;
if ( V_18 -> V_31 -> V_32 -> V_33 ) {
int V_34 = V_18 -> V_31 -> V_32 -> V_33 ( V_13 ,
V_37 ) ;
if ( V_34 < 0 )
F_7 ( V_36 L_2 ) ;
}
}
V_21 = F_3 ( V_2 , V_25 ) ;
V_21 |= V_22 ;
if ( V_2 -> V_11 & ( V_26 | V_27 ) ) {
V_21 |= V_38 ;
}
F_1 ( V_2 , V_25 , V_21 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_21 ;
V_21 = F_3 ( V_2 , V_25 ) ;
V_21 &= ~ ( V_30 | V_38 ) ;
V_21 &= V_6 ? ~ V_23 : ~ V_24 ;
F_1 ( V_2 , V_25 , V_21 ) ;
F_5 ( V_2 , V_6 ) ;
}
static int F_10 ( struct V_39 * V_40 ,
unsigned int V_41 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
unsigned int V_11 ;
unsigned int V_42 ;
V_42 = V_43 |
F_12 ( V_44 * 2 - 1 ) |
F_13 ( V_44 - 1 ) ;
V_2 -> V_41 = V_41 ;
switch ( V_41 & V_45 ) {
case V_46 :
V_11 = V_26 |
V_27 |
V_28 |
V_29 ;
break;
case V_47 :
V_11 = V_27 | V_26 ;
switch ( V_2 -> V_48 ) {
case V_49 :
V_11 |= V_28 |
V_29 ;
break;
case V_50 :
V_11 |= V_51 ;
break;
default:
F_14 ( V_2 -> V_2 , L_3 ) ;
return - V_52 ;
}
break;
case V_53 :
V_11 = 0 ;
break;
default:
F_7 ( V_54 L_4 , V_55 ) ;
return - V_52 ;
}
switch ( V_41 & V_56 ) {
case V_57 :
V_41 ^= V_58 ;
case V_59 :
V_2 -> V_60 = V_61 ;
break;
case V_62 :
V_2 -> V_60 = V_63 ;
break;
default:
F_7 ( V_54 L_5 , V_55 ) ;
return - V_52 ;
}
switch ( V_41 & V_64 ) {
case V_65 :
V_11 |= ( V_8 | V_9 ) ;
break;
case V_66 :
V_11 |= ( V_67 | V_68 ) ;
break;
case V_58 :
V_11 |= ( V_8 | V_9 |
V_67 | V_68 ) ;
break;
case V_69 :
break;
default:
return - V_52 ;
}
F_1 ( V_2 , V_70 , V_42 ) ;
V_2 -> V_11 = V_11 ;
F_1 ( V_2 , V_10 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 ,
int V_71 , int div )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
if ( V_71 != V_72 )
return - V_73 ;
V_2 -> V_74 = div ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_75 * V_76 ,
struct V_39 * V_77 )
{
struct V_1 * V_2 = F_11 ( V_77 ) ;
struct V_78 * V_79 =
& V_2 -> V_79 [ V_13 -> V_19 ] ;
struct V_80 * V_81 = NULL ;
int V_82 , V_83 ;
unsigned int V_84 , V_85 , V_42 , V_74 , V_86 , V_87 ;
T_1 V_21 ;
T_2 V_41 ;
unsigned V_88 = 1 ;
V_21 = F_3 ( V_2 , V_25 ) ;
if ( V_13 -> V_19 == V_89 ) {
V_21 |= F_17 ( 3 ) | V_90 ;
F_1 ( V_2 , V_25 , V_21 ) ;
} else {
V_21 |= F_18 ( 3 ) | V_90 ;
F_1 ( V_2 , V_25 , V_21 ) ;
}
V_83 = V_2 -> V_41 & V_45 ;
V_41 = F_19 ( V_76 ) ;
V_82 = V_91 [ V_41 ] ;
switch ( V_83 ) {
case V_46 :
V_86 = F_20 ( V_2 -> V_92 ) ;
V_42 = V_43 |
V_93 ;
V_42 |= F_13 ( V_82 *
8 - 1 ) ;
if ( V_2 -> V_94 ) {
V_74 = 256 ;
do {
V_87 = ( V_86 / ( -- V_74 ) ) /
V_76 -> V_95 *
V_76 -> V_96 ;
} while ( ( ( V_87 < 33 ) || ( V_87 > 4095 ) ) &&
( V_74 ) );
V_74 -- ;
V_42 |= F_12 ( V_87 - 1 ) ;
} else {
V_74 = V_86 / ( V_82 * 16 ) /
V_76 -> V_95 * V_76 -> V_96 ;
V_42 |= F_12 ( V_82 *
16 - 1 ) ;
}
V_74 &= 0xFF ;
V_42 |= V_74 ;
break;
case V_47 :
V_42 = V_43 ;
V_74 = V_2 -> V_74 - 1 ;
V_42 |= F_13 ( V_82 * 8 - 1 ) ;
V_42 |= F_12 ( V_82 * 16 - 1 ) ;
V_74 &= 0xFF ;
V_42 |= V_74 ;
break;
case V_53 :
V_81 = F_21 ( V_76 , V_97 ) ;
V_42 = V_43 ;
V_42 |= F_13 ( F_22 ( V_81 ) - 1 ) ;
F_23 ( L_6 ,
V_55 , __LINE__ , F_22 ( V_81 ) - 1 ) ;
V_81 = F_21 ( V_76 , V_98 ) ;
V_42 |= F_12 ( F_22 ( V_81 ) - 1 ) ;
break;
default:
return - V_52 ;
}
F_1 ( V_2 , V_70 , V_42 ) ;
V_84 = V_99 ;
V_85 = V_100 ;
if ( V_2 -> V_60 == V_63 ) {
V_84 |= F_24 ( 0 ) ;
V_85 |= F_25 ( 0 ) ;
} else {
V_84 |= F_24 ( 1 ) ;
V_85 |= F_25 ( 1 ) ;
}
V_41 = F_19 ( V_76 ) ;
if ( ( V_41 > V_101 ) || ! V_102 [ V_41 ] ) {
F_7 ( V_103 L_7 ) ;
return - V_52 ;
}
if ( F_26 ( V_76 ) == 2 ) {
V_88 = 2 ;
if ( V_104 [ V_41 ] && V_2 -> V_105 ) {
V_88 = 1 ;
V_41 = V_104 [ V_41 ] ;
}
switch ( V_83 ) {
case V_46 :
case V_106 :
V_84 |= F_27 ( 0 ) ;
V_85 |= F_28 ( 0 ) ;
V_84 |= V_107 ;
V_85 |= V_108 ;
break;
case V_53 :
case V_47 :
V_84 |= F_27 ( V_88 - 1 ) ;
V_85 |= F_28 ( V_88 - 1 ) ;
break;
default:
return - V_52 ;
}
}
V_79 -> V_109 = V_79 -> V_102 = V_102 [ V_41 ] ;
V_79 -> V_110 = 0 ;
V_82 = V_91 [ V_41 ] ;
switch ( V_83 ) {
case V_46 :
case V_106 :
V_84 |= F_29 ( 0 ) ;
V_85 |= F_30 ( 0 ) ;
break;
case V_53 :
case V_47 :
V_84 |= F_29 ( V_88 - 1 ) ;
V_85 |= F_30 ( V_88 - 1 ) ;
break;
default:
return - V_52 ;
}
V_84 |= F_31 ( V_82 ) |
F_32 ( V_82 ) ;
V_85 |= F_33 ( V_82 ) |
F_34 ( V_82 ) ;
if ( V_13 -> V_19 == V_20 )
F_1 ( V_2 , V_111 , V_85 ) ;
else
F_1 ( V_2 , V_112 , V_84 ) ;
F_23 ( L_8 , V_55 , __LINE__ , V_42 ) ;
F_23 ( L_9 , V_55 , __LINE__ , V_85 ) ;
F_23 ( L_10 , V_55 , __LINE__ , V_84 ) ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 ,
struct V_39 * V_77 )
{
struct V_1 * V_2 = F_11 ( V_77 ) ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
F_9 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_36 ( struct V_12 * V_13 , int V_113 ,
struct V_39 * V_77 )
{
struct V_1 * V_2 = F_11 ( V_77 ) ;
int V_34 = 0 ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
switch ( V_113 ) {
case V_37 :
case V_114 :
case V_115 :
F_6 ( V_2 , V_13 ) ;
break;
case V_35 :
case V_116 :
case V_117 :
F_9 ( V_2 , V_6 ) ;
break;
default:
V_34 = - V_52 ;
}
return V_34 ;
}
static int F_37 ( struct V_12 * V_13 ,
struct V_39 * V_77 )
{
struct V_1 * V_2 = F_11 ( V_77 ) ;
F_38 ( V_77 , V_13 , V_2 -> V_79 ) ;
return 0 ;
}
static void F_39 ( struct V_12 * V_13 ,
struct V_39 * V_77 )
{
struct V_1 * V_2 = F_11 ( V_77 ) ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
F_9 ( V_2 , V_6 ) ;
}
static int F_40 ( struct V_118 * V_119 )
{
struct V_120 * V_121 = V_119 -> V_2 . V_122 ;
struct V_1 * V_2 ;
struct V_123 * V_124 , * V_125 , * V_126 ;
enum V_127 V_128 = V_129 ;
enum V_127 V_130 = V_131 ;
int V_34 ;
V_124 = F_41 ( V_119 , V_132 , 0 ) ;
if ( ! V_124 ) {
F_14 ( & V_119 -> V_2 , L_11 ) ;
return - V_73 ;
}
V_125 = F_42 ( V_124 -> V_133 , F_43 ( V_124 ) ,
V_119 -> V_134 ) ;
if ( ! V_125 ) {
F_14 ( & V_119 -> V_2 , L_12 ) ;
return - V_135 ;
}
V_2 = F_44 ( sizeof( struct V_1 ) , V_136 ) ;
if ( ! V_2 ) {
V_34 = - V_137 ;
goto V_138;
}
if ( V_121 ) {
V_2 -> V_105 = V_121 -> V_105 ;
V_2 -> V_79 [ V_20 ] . V_139 =
V_121 -> V_140 ;
V_2 -> V_79 [ V_89 ] . V_139 =
V_121 -> V_141 ;
V_2 -> V_48 = V_121 -> V_48 ;
V_2 -> V_94 = V_121 -> V_94 ;
V_128 = V_121 -> V_128 ;
V_130 = V_121 -> V_130 ;
}
V_2 -> V_79 [ V_20 ] . V_128 = V_128 ;
V_2 -> V_79 [ V_20 ] . V_130 = V_130 ;
V_2 -> V_79 [ V_89 ] . V_128 = V_128 ;
V_2 -> V_79 [ V_89 ] . V_130 = V_130 ;
V_2 -> V_92 = F_45 ( & V_119 -> V_2 , NULL ) ;
if ( F_46 ( V_2 -> V_92 ) ) {
V_34 = - V_73 ;
goto V_142;
}
F_47 ( V_2 -> V_92 ) ;
V_2 -> V_5 = F_48 ( V_124 -> V_133 , F_43 ( V_124 ) ) ;
if ( ! V_2 -> V_5 ) {
F_14 ( & V_119 -> V_2 , L_13 ) ;
V_34 = - V_137 ;
goto V_143;
}
V_2 -> V_79 [ V_20 ] . V_144 =
( V_145 ) ( V_124 -> V_133 + V_146 ) ;
V_2 -> V_79 [ V_89 ] . V_144 =
( V_145 ) ( V_124 -> V_133 + V_147 ) ;
V_126 = F_41 ( V_119 , V_148 , 0 ) ;
if ( ! V_126 ) {
F_14 ( & V_119 -> V_2 , L_14 ) ;
V_34 = - V_149 ;
goto V_150;
}
V_2 -> V_79 [ V_20 ] . V_151 = V_126 -> V_133 ;
V_126 = F_41 ( V_119 , V_148 , 1 ) ;
if ( ! V_126 ) {
F_14 ( & V_119 -> V_2 , L_14 ) ;
V_34 = - V_149 ;
goto V_150;
}
V_2 -> V_79 [ V_89 ] . V_151 = V_126 -> V_133 ;
V_2 -> V_2 = & V_119 -> V_2 ;
F_49 ( & V_119 -> V_2 , V_2 ) ;
V_34 = F_50 ( & V_119 -> V_2 , & V_152 ) ;
if ( V_34 != 0 )
goto V_150;
return 0 ;
V_150:
F_51 ( V_2 -> V_5 ) ;
V_143:
F_52 ( V_2 -> V_92 ) ;
F_53 ( V_2 -> V_92 ) ;
V_142:
F_54 ( V_2 ) ;
V_138:
F_55 ( V_124 -> V_133 , F_43 ( V_124 ) ) ;
return V_34 ;
}
static int F_56 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_57 ( & V_119 -> V_2 ) ;
struct V_123 * V_124 ;
F_58 ( & V_119 -> V_2 ) ;
F_52 ( V_2 -> V_92 ) ;
F_53 ( V_2 -> V_92 ) ;
V_2 -> V_92 = NULL ;
F_54 ( V_2 ) ;
V_124 = F_41 ( V_119 , V_132 , 0 ) ;
F_55 ( V_124 -> V_133 , F_43 ( V_124 ) ) ;
return 0 ;
}
static int T_3 F_59 ( void )
{
return F_60 ( & V_153 ) ;
}
static void T_4 F_61 ( void )
{
F_62 ( & V_153 ) ;
}
