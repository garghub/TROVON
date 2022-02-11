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
bool V_43 = false ;
V_42 = V_44 |
F_12 ( V_45 * 2 - 1 ) |
F_13 ( V_45 - 1 ) ;
V_2 -> V_41 = V_41 ;
switch ( V_41 & V_46 ) {
case V_47 :
V_11 = V_26 |
V_27 |
V_28 |
V_29 ;
break;
case V_48 :
V_11 = V_27 | V_26 ;
switch ( V_2 -> V_49 ) {
case V_50 :
V_11 |= V_28 |
V_29 ;
break;
case V_51 :
V_11 |= V_52 ;
break;
default:
F_14 ( V_2 -> V_2 , L_3 ) ;
return - V_53 ;
}
break;
case V_54 :
V_11 = 0 ;
break;
default:
F_7 ( V_55 L_4 , V_56 ) ;
return - V_53 ;
}
switch ( V_41 & V_57 ) {
case V_58 :
V_43 = true ;
case V_59 :
V_2 -> V_60 = V_61 ;
break;
case V_62 :
V_2 -> V_60 = V_63 ;
break;
default:
F_7 ( V_55 L_5 , V_56 ) ;
return - V_53 ;
}
switch ( V_41 & V_64 ) {
case V_65 :
V_11 |= ( V_8 | V_9 ) ;
break;
case V_66 :
V_11 |= ( V_67 | V_68 ) ;
break;
case V_69 :
V_11 |= ( V_8 | V_9 |
V_67 | V_68 ) ;
break;
case V_70 :
break;
default:
return - V_53 ;
}
if ( V_43 == true )
V_11 ^= ( V_67 | V_68 ) ;
F_1 ( V_2 , V_71 , V_42 ) ;
V_2 -> V_11 = V_11 ;
F_1 ( V_2 , V_10 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 ,
int V_72 , int div )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
if ( V_72 != V_73 )
return - V_74 ;
V_2 -> V_75 = div ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_76 * V_77 ,
struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
struct V_79 * V_80 =
& V_2 -> V_80 [ V_13 -> V_19 ] ;
struct V_81 * V_82 = NULL ;
int V_83 , V_84 ;
unsigned int V_85 , V_86 , V_42 , V_75 , V_87 , V_88 ;
T_1 V_21 ;
T_2 V_41 ;
unsigned V_89 = 1 ;
V_21 = F_3 ( V_2 , V_25 ) ;
if ( V_13 -> V_19 == V_90 ) {
V_21 |= F_17 ( 3 ) | V_91 ;
F_1 ( V_2 , V_25 , V_21 ) ;
} else {
V_21 |= F_18 ( 3 ) | V_91 ;
F_1 ( V_2 , V_25 , V_21 ) ;
}
V_84 = V_2 -> V_41 & V_46 ;
V_41 = F_19 ( V_77 ) ;
V_83 = V_92 [ V_41 ] ;
switch ( V_84 ) {
case V_47 :
V_87 = F_20 ( V_2 -> V_93 ) ;
V_42 = V_44 |
V_94 ;
V_42 |= F_13 ( V_83 *
8 - 1 ) ;
if ( V_2 -> V_95 ) {
V_75 = 256 ;
do {
V_88 = ( V_87 / ( -- V_75 ) ) /
V_77 -> V_96 *
V_77 -> V_97 ;
} while ( ( ( V_88 < 33 ) || ( V_88 > 4095 ) ) &&
( V_75 ) );
V_75 -- ;
V_42 |= F_12 ( V_88 - 1 ) ;
} else {
V_75 = V_87 / ( V_83 * 16 ) /
V_77 -> V_96 * V_77 -> V_97 ;
V_42 |= F_12 ( V_83 *
16 - 1 ) ;
}
V_75 &= 0xFF ;
V_42 |= V_75 ;
break;
case V_48 :
V_42 = V_44 ;
V_75 = V_2 -> V_75 - 1 ;
V_42 |= F_13 ( V_83 * 8 - 1 ) ;
V_42 |= F_12 ( V_83 * 16 - 1 ) ;
V_75 &= 0xFF ;
V_42 |= V_75 ;
break;
case V_54 :
V_82 = F_21 ( V_77 , V_98 ) ;
V_42 = V_44 ;
V_42 |= F_13 ( F_22 ( V_82 ) - 1 ) ;
F_23 ( L_6 ,
V_56 , __LINE__ , F_22 ( V_82 ) - 1 ) ;
V_82 = F_21 ( V_77 , V_99 ) ;
V_42 |= F_12 ( F_22 ( V_82 ) - 1 ) ;
break;
default:
return - V_53 ;
}
F_1 ( V_2 , V_71 , V_42 ) ;
V_85 = V_100 ;
V_86 = V_101 ;
if ( V_2 -> V_60 == V_63 ) {
V_85 |= F_24 ( 0 ) ;
V_86 |= F_25 ( 0 ) ;
} else {
V_85 |= F_24 ( 1 ) ;
V_86 |= F_25 ( 1 ) ;
}
V_41 = F_19 ( V_77 ) ;
if ( ( V_41 > V_102 ) || ! V_103 [ V_41 ] ) {
F_7 ( V_104 L_7 ) ;
return - V_53 ;
}
if ( F_26 ( V_77 ) == 2 ) {
V_89 = 2 ;
if ( V_105 [ V_41 ] && V_2 -> V_106 ) {
V_89 = 1 ;
V_41 = V_105 [ V_41 ] ;
}
switch ( V_84 ) {
case V_47 :
case V_107 :
V_85 |= F_27 ( 0 ) ;
V_86 |= F_28 ( 0 ) ;
V_85 |= V_108 ;
V_86 |= V_109 ;
break;
case V_54 :
case V_48 :
V_85 |= F_27 ( V_89 - 1 ) ;
V_86 |= F_28 ( V_89 - 1 ) ;
break;
default:
return - V_53 ;
}
}
V_80 -> V_110 = V_80 -> V_103 = V_103 [ V_41 ] ;
V_80 -> V_111 = 0 ;
V_83 = V_92 [ V_41 ] ;
switch ( V_84 ) {
case V_47 :
case V_107 :
V_85 |= F_29 ( 0 ) ;
V_86 |= F_30 ( 0 ) ;
break;
case V_54 :
case V_48 :
V_85 |= F_29 ( V_89 - 1 ) ;
V_86 |= F_30 ( V_89 - 1 ) ;
break;
default:
return - V_53 ;
}
V_85 |= F_31 ( V_83 ) |
F_32 ( V_83 ) ;
V_86 |= F_33 ( V_83 ) |
F_34 ( V_83 ) ;
if ( V_13 -> V_19 == V_20 )
F_1 ( V_2 , V_112 , V_86 ) ;
else
F_1 ( V_2 , V_113 , V_85 ) ;
F_23 ( L_8 , V_56 , __LINE__ , V_42 ) ;
F_23 ( L_9 , V_56 , __LINE__ , V_86 ) ;
F_23 ( L_10 , V_56 , __LINE__ , V_85 ) ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 ,
struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
F_9 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_36 ( struct V_12 * V_13 , int V_114 ,
struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
int V_34 = 0 ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
switch ( V_114 ) {
case V_37 :
case V_115 :
case V_116 :
F_6 ( V_2 , V_13 ) ;
break;
case V_35 :
case V_117 :
case V_118 :
F_9 ( V_2 , V_6 ) ;
break;
default:
V_34 = - V_53 ;
}
return V_34 ;
}
static int F_37 ( struct V_12 * V_13 ,
struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
F_38 ( V_78 , V_13 , V_2 -> V_80 ) ;
return 0 ;
}
static void F_39 ( struct V_12 * V_13 ,
struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
F_9 ( V_2 , V_6 ) ;
}
static int F_40 ( struct V_119 * V_120 )
{
struct V_121 * V_122 = V_120 -> V_2 . V_123 ;
struct V_1 * V_2 ;
struct V_124 * V_125 , * V_126 , * V_127 ;
enum V_128 V_129 = V_130 ;
enum V_128 V_131 = V_132 ;
int V_34 ;
V_125 = F_41 ( V_120 , V_133 , 0 ) ;
if ( ! V_125 ) {
F_14 ( & V_120 -> V_2 , L_11 ) ;
return - V_74 ;
}
V_126 = F_42 ( & V_120 -> V_2 , V_125 -> V_134 ,
F_43 ( V_125 ) ,
V_120 -> V_135 ) ;
if ( ! V_126 ) {
F_14 ( & V_120 -> V_2 , L_12 ) ;
return - V_136 ;
}
V_2 = F_44 ( & V_120 -> V_2 , sizeof( struct V_1 ) ,
V_137 ) ;
if ( ! V_2 )
return - V_138 ;
if ( V_122 ) {
V_2 -> V_106 = V_122 -> V_106 ;
V_2 -> V_80 [ V_20 ] . V_139 =
V_122 -> V_140 ;
V_2 -> V_80 [ V_90 ] . V_139 =
V_122 -> V_141 ;
V_2 -> V_49 = V_122 -> V_49 ;
V_2 -> V_95 = V_122 -> V_95 ;
V_129 = V_122 -> V_129 ;
V_131 = V_122 -> V_131 ;
}
V_2 -> V_80 [ V_20 ] . V_129 = V_129 ;
V_2 -> V_80 [ V_20 ] . V_131 = V_131 ;
V_2 -> V_80 [ V_90 ] . V_129 = V_129 ;
V_2 -> V_80 [ V_90 ] . V_131 = V_131 ;
V_2 -> V_93 = F_45 ( & V_120 -> V_2 , NULL ) ;
if ( F_46 ( V_2 -> V_93 ) )
return - V_74 ;
F_47 ( V_2 -> V_93 ) ;
V_2 -> V_5 = F_48 ( & V_120 -> V_2 , V_125 -> V_134 , F_43 ( V_125 ) ) ;
if ( ! V_2 -> V_5 ) {
F_14 ( & V_120 -> V_2 , L_13 ) ;
V_34 = - V_138 ;
goto V_142;
}
V_2 -> V_80 [ V_20 ] . V_143 =
( V_144 ) ( V_125 -> V_134 + V_145 ) ;
V_2 -> V_80 [ V_90 ] . V_143 =
( V_144 ) ( V_125 -> V_134 + V_146 ) ;
V_127 = F_41 ( V_120 , V_147 , 0 ) ;
if ( ! V_127 ) {
F_14 ( & V_120 -> V_2 , L_14 ) ;
V_34 = - V_148 ;
goto V_142;
}
V_2 -> V_80 [ V_20 ] . V_149 = V_127 -> V_134 ;
V_127 = F_41 ( V_120 , V_147 , 1 ) ;
if ( ! V_127 ) {
F_14 ( & V_120 -> V_2 , L_14 ) ;
V_34 = - V_148 ;
goto V_142;
}
V_2 -> V_80 [ V_90 ] . V_149 = V_127 -> V_134 ;
V_2 -> V_2 = & V_120 -> V_2 ;
F_49 ( & V_120 -> V_2 , V_2 ) ;
V_34 = F_50 ( & V_120 -> V_2 , & V_150 ) ;
if ( V_34 != 0 )
goto V_142;
return 0 ;
V_142:
F_51 ( V_2 -> V_93 ) ;
F_52 ( V_2 -> V_93 ) ;
return V_34 ;
}
static int F_53 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_54 ( & V_120 -> V_2 ) ;
F_55 ( & V_120 -> V_2 ) ;
F_51 ( V_2 -> V_93 ) ;
F_52 ( V_2 -> V_93 ) ;
V_2 -> V_93 = NULL ;
return 0 ;
}
