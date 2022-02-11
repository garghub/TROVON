static void F_1 ( struct V_1 * V_2 )
{
char V_3 [ 10 ] , * V_4 [] = { V_3 , NULL } ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
unsigned int V_9 ;
if ( ! V_6 ) {
F_2 ( L_1 ) ;
return;
}
F_3 ( V_6 , V_10 ) ;
F_4 ( & V_6 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
V_6 -> V_12 -> V_13 ( V_6 , V_9 , & V_8 ) ;
if ( V_6 -> V_14 < V_8 )
break;
}
snprintf ( V_3 , sizeof( V_3 ) , L_2 , V_9 ) ;
F_6 ( & V_6 -> V_15 . V_16 , V_17 , V_4 ) ;
F_7 ( & V_6 -> V_11 ) ;
}
static int F_8 ( struct V_1 * V_3 , T_1 V_8 )
{
struct V_18 * V_19 = V_3 -> V_19 ;
int V_20 ;
switch ( V_19 -> V_21 ) {
case V_22 :
V_20 = ( V_8 - V_19 -> V_23 ) *
( V_3 -> V_24 - V_3 -> V_25 ) /
( V_19 -> V_26 - V_19 -> V_23 ) +
V_3 -> V_25 ;
break;
case V_27 :
V_20 = V_8 + V_3 -> V_25 - V_19 -> V_23 ;
break;
default:
V_20 = V_8 + V_19 -> V_28 ;
break;
}
return V_20 ;
}
static int F_9 ( struct V_1 * V_3 , T_2 V_20 )
{
struct V_18 * V_19 = V_3 -> V_19 ;
int V_8 ;
switch ( V_19 -> V_21 ) {
case V_22 :
V_8 = ( V_20 - V_3 -> V_25 ) *
( V_19 -> V_26 - V_19 -> V_23 ) /
( V_3 -> V_24 - V_3 -> V_25 ) +
V_19 -> V_23 ;
break;
case V_27 :
V_8 = V_20 - V_3 -> V_25 + V_19 -> V_23 ;
break;
default:
V_8 = V_20 - V_19 -> V_28 ;
break;
}
return V_8 ;
}
static void F_10 ( struct V_1 * V_3 , T_3 V_29 )
{
struct V_18 * V_19 = V_3 -> V_19 ;
V_3 -> V_25 = V_29 & V_30 ;
V_3 -> V_24 = ( ( V_29 >> V_31 ) &
V_30 ) ;
if ( ! V_3 -> V_25 ||
( V_19 -> V_32 > V_3 -> V_25 ) ||
( V_3 -> V_25 > V_19 -> V_33 ) )
V_3 -> V_25 = V_19 -> V_34 & V_30 ;
if ( ! V_3 -> V_24 )
V_3 -> V_24 =
( V_19 -> V_34 >> V_31 ) &
V_30 ;
}
static T_3 F_11 ( struct V_1 * V_3 , T_3 V_35 , bool V_36 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
const struct V_37 * const V_38 =
F_12 ( V_6 ) ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_38 ) {
F_2 ( L_3 ,
V_39 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
if ( V_38 [ V_9 ] . type == V_40 )
continue;
V_8 = V_38 [ V_9 ] . V_41 / V_42 ;
if ( V_36 )
V_8 -= ( V_38 [ V_9 ] . V_43 / V_42 ) ;
else
V_35 &= ~ ( 0xff << 8 * V_9 ) ;
V_35 |= F_8 ( V_3 , V_8 ) << 8 * V_9 ;
}
return V_35 ;
}
static int F_13 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
int V_46 ;
if ( F_5 ( V_3 -> V_7 ) > V_3 -> V_47 ) {
F_15 ( & V_45 -> V_48 ,
L_4 ) ;
F_15 ( & V_45 -> V_48 ,
L_5 ,
( F_5 ( V_3 -> V_7 ) - V_3 -> V_47 ) ) ;
}
F_4 ( & V_3 -> V_11 ) ;
F_16 ( V_3 -> V_49 ) ;
if ( ! F_17 ( V_3 -> V_50 ) )
F_16 ( V_3 -> V_50 ) ;
V_46 = V_3 -> V_51 ( V_45 ) ;
F_18 ( V_3 -> V_49 ) ;
F_7 ( & V_3 -> V_11 ) ;
if ( ! F_17 ( V_3 -> V_50 ) )
F_18 ( V_3 -> V_50 ) ;
return V_46 ;
}
static T_3 F_19 ( struct V_1 * V_3 , T_3 V_52 )
{
struct V_18 * V_19 = V_3 -> V_19 ;
if ( V_3 -> V_53 == V_54 ||
V_3 -> V_53 == V_55 )
V_52 |= ( V_56 << V_57 ) ;
V_52 &= ~ ( V_58 << V_59 ) ;
V_52 |= V_19 -> V_60 << V_59 ;
V_52 &= ~ ( V_61 << V_62 ) ;
V_52 |= ( V_19 -> V_63 << V_62 ) ;
if ( V_19 -> V_64 ) {
V_52 &= ~ ( V_65 << V_66 ) ;
V_52 |= ( V_19 -> V_64 << V_66 ) ;
}
return V_52 ;
}
static void F_20 ( struct V_44 * V_45 , bool V_67 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
F_4 ( & V_3 -> V_11 ) ;
F_16 ( V_3 -> V_49 ) ;
V_3 -> V_68 ( V_45 , V_67 ) ;
F_18 ( V_3 -> V_49 ) ;
F_7 ( & V_3 -> V_11 ) ;
}
static int F_21 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
const struct V_37 * const V_38 =
F_12 ( V_6 ) ;
int V_46 = 0 , V_69 , V_9 ;
unsigned long V_70 , V_8 ;
unsigned int V_71 ;
if ( ! V_38 ) {
F_2 ( L_3 ,
V_39 ) ;
V_46 = - V_72 ;
goto V_73;
}
V_71 = F_22 ( V_3 -> V_74 + V_75 ) ;
if ( ! V_71 ) {
V_46 = - V_76 ;
goto V_73;
}
F_10 ( V_3 , F_23 ( V_3 -> V_74 + V_77 ) ) ;
V_70 = V_38 [ 0 ] . V_41 / V_42 ;
V_69 = F_8 ( V_3 , V_70 ) ;
if ( V_69 < 0 ) {
V_46 = V_69 ;
goto V_73;
}
F_24 ( V_69 , V_3 -> V_74 + V_78 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
V_8 = V_38 [ V_9 ] . V_41 / V_42 ;
F_24 ( V_8 - V_70 , V_3 -> V_74 +
V_79 + V_9 * 4 ) ;
}
V_3 -> V_80 ( V_3 ) ;
V_73:
return V_46 ;
}
static int F_25 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
const struct V_37 * const V_38 =
F_12 ( V_3 -> V_7 ) ;
unsigned int V_71 , V_29 , V_52 , V_81 , V_82 ;
int V_46 = 0 , V_69 , V_9 ;
unsigned long V_83 = 0 ;
V_71 = F_22 ( V_3 -> V_74 + V_75 ) ;
if ( ! V_71 ) {
V_46 = - V_76 ;
goto V_73;
}
if ( V_3 -> V_53 == V_55 ||
V_3 -> V_53 == V_54 ||
V_3 -> V_53 == V_84 ) {
if ( V_3 -> V_53 == V_55 ) {
V_81 = F_23 ( V_3 -> V_74 + V_85 ) ;
V_81 |= V_86 ;
F_26 ( V_81 , V_3 -> V_74 + V_85 ) ;
}
V_81 = F_23 ( V_3 -> V_74 + V_87 ) ;
V_81 |= V_86 ;
F_26 ( V_81 , V_3 -> V_74 + V_87 ) ;
}
if ( V_3 -> V_53 == V_88 )
V_29 = F_23 ( V_3 -> V_89 + V_77 ) ;
else
V_29 = F_23 ( V_3 -> V_74 + V_77 ) ;
F_10 ( V_3 , V_29 ) ;
V_82 = F_23 ( V_3 -> V_74 + V_90 ) ;
V_82 = F_11 ( V_3 , V_82 , false ) ;
F_26 ( V_82 , V_3 -> V_74 + V_90 ) ;
F_26 ( F_11 ( V_3 , 0 , true ) , V_3 -> V_74 + V_91 ) ;
V_3 -> V_80 ( V_3 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_3 -> V_7 ) ; V_9 ++ ) {
if ( V_38 [ V_9 ] . type == V_40 ) {
V_83 = V_38 [ V_9 ] . V_41 ;
break;
}
}
if ( V_9 == F_5 ( V_3 -> V_7 ) ) {
F_2 ( L_6 ,
V_39 ) ;
V_46 = - V_92 ;
goto V_73;
}
V_69 = F_8 ( V_3 , V_83 / V_42 ) ;
V_82 &= ~ ( 0xff << 8 * V_9 ) ;
V_82 |= V_69 << 8 * V_9 ;
F_26 ( V_82 , V_3 -> V_74 + V_90 ) ;
V_52 = F_23 ( V_3 -> V_74 + V_93 ) ;
V_52 |= ( 1 << V_94 ) ;
F_26 ( V_52 , V_3 -> V_74 + V_93 ) ;
V_73:
return V_46 ;
}
static int F_27 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_71 , V_29 ;
unsigned int V_82 = 0 , V_95 = 0 ;
int V_8 , V_96 ;
int V_46 = 0 , V_69 , V_9 , V_97 , V_21 ;
V_71 = F_22 ( V_3 -> V_74 + V_75 ) ;
if ( ! V_71 ) {
V_46 = - V_76 ;
goto V_73;
}
V_29 = F_23 ( V_3 -> V_74 + V_77 ) ;
F_10 ( V_3 , V_29 ) ;
V_97 = ( V_29 & V_98 )
>> V_99 ;
F_15 ( & V_45 -> V_48 , L_7 , V_97 ) ;
F_26 ( V_29 , V_3 -> V_74 + V_77 ) ;
V_21 = ( V_29 & V_100 )
>> V_101 ;
switch ( V_21 ) {
case V_102 :
V_19 -> V_21 = V_27 ;
break;
case V_103 :
V_19 -> V_21 = V_22 ;
break;
default:
V_19 -> V_21 = V_27 ;
break;
}
F_15 ( & V_45 -> V_48 , L_8 ,
V_21 ? 2 : 1 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
int V_104 , V_105 ;
int V_106 = 0 ;
switch ( V_9 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_104 = V_107 ;
V_105 = V_108 ;
V_106 = V_9 ;
break;
case 4 :
case 5 :
case 6 :
case 7 :
V_104 = V_109 ;
V_105 = V_110 ;
V_106 = V_9 - 4 ;
break;
default:
continue;
}
V_6 -> V_12 -> V_13 ( V_6 , V_9 , & V_8 ) ;
V_8 /= V_42 ;
V_69 = F_8 ( V_3 , V_8 ) ;
V_82 = F_23 ( V_3 -> V_74 + V_104 ) ;
V_82 |= ( V_69 << V_106 * 8 ) ;
F_26 ( V_82 , V_3 -> V_74 + V_104 ) ;
V_6 -> V_12 -> V_111 ( V_6 , V_9 , & V_96 ) ;
V_96 = V_8 - ( V_96 / V_42 ) ;
V_69 = F_8 ( V_3 , V_96 ) ;
V_95 = F_23 ( V_3 -> V_74 + V_105 ) ;
V_95 &= ~ ( 0xff << V_106 * 8 ) ;
V_95 |= ( V_69 << V_106 * 8 ) ;
F_26 ( V_95 , V_3 -> V_74 + V_105 ) ;
}
V_3 -> V_80 ( V_3 ) ;
V_73:
return V_46 ;
}
static int F_28 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
unsigned int V_29 = 0 , V_52 , V_82 ;
int V_69 ;
int V_83 = 0 ;
switch ( V_3 -> V_112 ) {
case 0 :
V_29 = F_23 ( V_3 -> V_74 + V_113 +
V_114 ) ;
break;
case 1 :
V_29 = F_23 ( V_3 -> V_74 + V_114 ) ;
break;
case 2 :
V_29 = F_23 ( V_3 -> V_74 - V_113 +
V_114 ) ;
}
F_10 ( V_3 , V_29 ) ;
V_82 = F_23 ( V_3 -> V_74 + V_115 ) ;
V_82 = F_11 ( V_3 , V_82 , false ) ;
F_26 ( V_82 , V_3 -> V_74 + V_115 ) ;
F_26 ( 0 , V_3 -> V_74 + V_116 ) ;
V_3 -> V_80 ( V_3 ) ;
if ( ! V_3 -> V_7 -> V_12 -> V_117 ( V_3 -> V_7 , & V_83 ) ) {
V_69 = F_8 ( V_3 , V_83 / V_42 ) ;
V_82 =
V_69 << V_118 ;
F_26 ( V_82 , V_3 -> V_74 + V_119 ) ;
V_52 = F_23 ( V_3 -> V_74 + V_120 ) ;
V_52 |= ( 1 << V_94 ) ;
F_26 ( V_52 , V_3 -> V_74 + V_120 ) ;
}
if ( ! V_3 -> V_112 )
F_26 ( 0 , V_3 -> V_89 + V_121 ) ;
return 0 ;
}
static int F_29 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_18 * V_19 = V_3 -> V_19 ;
unsigned int V_71 , V_29 ;
unsigned int V_82 = 0 , V_95 = 0 ;
int V_46 = 0 , V_69 , V_9 ;
int V_8 , V_96 ;
unsigned int V_122 , V_123 ;
V_71 = F_22 ( V_3 -> V_74 + V_75 ) ;
if ( ! V_71 ) {
V_46 = - V_76 ;
goto V_73;
}
V_29 = F_23 ( V_3 -> V_74 + V_77 ) ;
V_3 -> V_25 = V_29 & V_124 ;
if ( ! V_3 -> V_25 ||
( V_19 -> V_32 > V_3 -> V_25 ) ||
( V_3 -> V_25 > V_19 -> V_33 ) )
V_3 -> V_25 = V_19 -> V_34 & V_30 ;
for ( V_9 = ( F_5 ( V_6 ) - 1 ) ; V_9 >= 0 ; V_9 -- ) {
V_122 = ( ( 7 - V_9 ) / 2 ) * 4 ;
V_123 = ( ( 8 - V_9 ) % 2 ) ;
V_6 -> V_12 -> V_13 ( V_6 , V_9 , & V_8 ) ;
V_8 /= V_42 ;
V_6 -> V_12 -> V_111 ( V_6 , V_9 , & V_96 ) ;
V_96 = V_8 - ( V_96 / V_42 ) ;
V_69 = F_8 ( V_3 , V_8 ) ;
V_82 = F_23 ( V_3 -> V_74 +
V_125 + V_122 ) ;
V_82 &= ~ ( V_124 << ( 16 * V_123 ) ) ;
V_82 |= V_69 << ( 16 * V_123 ) ;
F_26 ( V_82 ,
V_3 -> V_74 + V_125 + V_122 ) ;
V_69 = F_8 ( V_3 , V_96 ) ;
V_95 &= ~ ( V_124 << ( 16 * V_123 ) ) ;
V_95 |= V_69 << ( 16 * V_123 ) ;
F_26 ( V_95 ,
V_3 -> V_74 + V_126 + V_122 ) ;
}
V_3 -> V_80 ( V_3 ) ;
V_73:
return V_46 ;
}
static void F_30 ( struct V_44 * V_45 , bool V_67 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_52 , V_127 ;
V_52 = F_19 ( V_3 , F_23 ( V_3 -> V_74 + V_93 ) ) ;
if ( V_67 ) {
V_52 |= ( 1 << V_128 ) ;
V_127 =
( F_31 ( V_6 , 3 )
<< V_129 ) |
( F_31 ( V_6 , 2 )
<< V_130 ) |
( F_31 ( V_6 , 1 )
<< V_131 ) |
( F_31 ( V_6 , 0 )
<< V_132 ) ;
if ( V_3 -> V_53 != V_133 )
V_127 |=
V_127 << V_134 ;
} else {
V_52 &= ~ ( 1 << V_128 ) ;
V_127 = 0 ;
}
F_26 ( V_127 , V_3 -> V_74 + V_135 ) ;
F_26 ( V_52 , V_3 -> V_74 + V_93 ) ;
}
static void F_32 ( struct V_44 * V_45 , bool V_67 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_52 , V_127 , V_136 ;
V_52 = F_19 ( V_3 , F_23 ( V_3 -> V_74 + V_93 ) ) ;
if ( V_67 ) {
V_52 |= ( 1 << V_128 ) ;
V_127 =
( F_31 ( V_6 , 7 )
<< V_137 ) |
( F_31 ( V_6 , 6 )
<< V_138 ) |
( F_31 ( V_6 , 5 )
<< V_139 ) |
( F_31 ( V_6 , 4 )
<< V_140 ) |
( F_31 ( V_6 , 3 )
<< V_141 ) |
( F_31 ( V_6 , 2 )
<< V_142 ) |
( F_31 ( V_6 , 1 )
<< V_143 ) |
( F_31 ( V_6 , 0 )
<< V_144 ) ;
V_127 |=
V_127 << V_134 ;
} else {
V_52 &= ~ ( 1 << V_128 ) ;
V_127 = 0 ;
}
V_136 = V_67 ? V_145 : 0 ;
F_26 ( V_136 , V_3 -> V_74 + V_146 ) ;
F_26 ( V_127 , V_3 -> V_74 + V_147 ) ;
F_26 ( V_52 , V_3 -> V_74 + V_93 ) ;
}
static void F_33 ( struct V_44 * V_45 , bool V_67 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_52 , V_127 ;
V_52 = F_19 ( V_3 , F_23 ( V_3 -> V_74 + V_120 ) ) ;
if ( V_67 ) {
V_52 |= ( 1 << V_128 ) ;
V_127 =
( F_31 ( V_6 , 3 )
<< V_148 ) |
( F_31 ( V_6 , 2 )
<< V_149 ) |
( F_31 ( V_6 , 1 )
<< V_150 ) |
( F_31 ( V_6 , 0 )
<< V_151 ) ;
V_127 |=
V_127 << V_152 ;
} else {
V_52 &= ~ ( 1 << V_128 ) ;
V_127 = 0 ;
}
F_26 ( V_127 , V_3 -> V_74 + V_153 ) ;
F_26 ( V_52 , V_3 -> V_74 + V_120 ) ;
}
static void F_34 ( struct V_44 * V_45 , bool V_67 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_52 , V_127 ;
V_52 = F_19 ( V_3 , F_23 ( V_3 -> V_74 + V_93 ) ) ;
if ( V_67 ) {
V_52 |= ( 1 << V_128 ) ;
V_52 |= ( 1 << V_154 ) ;
V_127 =
( F_31 ( V_6 , 7 )
<< V_137 ) |
( F_31 ( V_6 , 6 )
<< V_138 ) |
( F_31 ( V_6 , 5 )
<< V_139 ) |
( F_31 ( V_6 , 4 )
<< V_140 ) |
( F_31 ( V_6 , 3 )
<< V_141 ) |
( F_31 ( V_6 , 2 )
<< V_142 ) |
( F_31 ( V_6 , 1 )
<< V_143 ) |
( F_31 ( V_6 , 0 )
<< V_144 ) ;
V_127 |=
V_127 << V_134 ;
} else {
V_52 &= ~ ( 1 << V_128 ) ;
V_52 &= ~ ( 1 << V_154 ) ;
V_127 = 0 ;
}
F_26 ( V_127 , V_3 -> V_74 + V_155 ) ;
F_26 ( V_52 , V_3 -> V_74 + V_93 ) ;
}
static int F_35 ( void * V_2 , int * V_8 )
{
struct V_1 * V_3 = V_2 ;
if ( ! V_3 || ! V_3 -> V_156 )
return - V_92 ;
F_4 ( & V_3 -> V_11 ) ;
F_16 ( V_3 -> V_49 ) ;
* V_8 = F_9 ( V_3 , V_3 -> V_156 ( V_3 ) ) * V_42 ;
F_18 ( V_3 -> V_49 ) ;
F_7 ( & V_3 -> V_11 ) ;
return 0 ;
}
static T_3 F_36 ( struct V_1 * V_3 , unsigned int V_157 ,
int V_8 )
{
if ( V_8 ) {
V_8 /= V_42 ;
if ( V_3 -> V_53 != V_158 ) {
V_157 &= ~ ( V_159 << V_160 ) ;
V_157 |= ( V_161 << V_160 ) ;
}
if ( V_3 -> V_53 == V_162 ) {
V_157 &= ~ ( V_163 <<
V_164 ) ;
V_157 |= ( F_8 ( V_3 , V_8 ) <<
V_164 ) |
V_165 ;
} else {
V_157 &= ~ ( V_166 <<
V_167 ) ;
V_157 |= ( F_8 ( V_3 , V_8 ) <<
V_167 ) |
V_165 ;
}
} else {
V_157 &= ~ V_165 ;
}
return V_157 ;
}
static void F_37 ( struct V_1 * V_3 ,
int V_8 )
{
unsigned int V_157 ;
T_3 V_168 ;
if ( V_3 -> V_53 == V_169 )
V_168 = V_170 ;
else if ( V_3 -> V_53 == V_171 )
V_168 = V_172 ;
else if ( V_3 -> V_53 == V_162 )
V_168 = V_173 ;
else
V_168 = V_174 ;
V_157 = F_23 ( V_3 -> V_74 + V_168 ) ;
V_157 = F_36 ( V_3 , V_157 , V_8 ) ;
F_26 ( V_157 , V_3 -> V_74 + V_168 ) ;
}
static void F_38 ( struct V_1 * V_3 ,
int V_8 )
{
unsigned int V_157 ;
V_157 = F_23 ( V_3 -> V_74 + V_175 ) ;
V_157 = F_36 ( V_3 , V_157 , V_8 ) ;
F_26 ( V_157 , V_3 -> V_74 + V_175 ) ;
}
static int F_39 ( void * V_176 , int V_8 )
{
struct V_1 * V_3 = V_176 ;
int V_46 = - V_92 ;
if ( V_3 -> V_53 == V_133 )
goto V_73;
if ( V_8 && V_8 < V_42 )
goto V_73;
F_4 ( & V_3 -> V_11 ) ;
F_16 ( V_3 -> V_49 ) ;
V_3 -> V_177 ( V_3 , V_8 ) ;
F_18 ( V_3 -> V_49 ) ;
F_7 ( & V_3 -> V_11 ) ;
return 0 ;
V_73:
return V_46 ;
}
static int F_39 ( void * V_176 , int V_8 )
{ return - V_92 ; }
static int F_40 ( struct V_1 * V_3 )
{
int V_46 = F_22 ( V_3 -> V_74 + V_178 ) ;
return ( V_46 < 75 || V_46 > 175 ) ? - V_179 : V_46 ;
}
static int F_41 ( struct V_1 * V_3 )
{
return F_22 ( V_3 -> V_74 + V_178 ) ;
}
static int F_42 ( struct V_1 * V_3 )
{
return F_22 ( V_3 -> V_74 + V_180 ) ;
}
static int F_43 ( struct V_1 * V_3 )
{
return F_44 ( V_3 -> V_74 + V_178 ) &
V_124 ;
}
static void F_45 ( struct V_181 * V_182 )
{
struct V_1 * V_3 = F_46 ( V_182 ,
struct V_1 , V_183 ) ;
unsigned int V_184 ;
if ( ! F_17 ( V_3 -> V_50 ) )
F_16 ( V_3 -> V_50 ) ;
if ( V_3 -> V_53 == V_158 ) {
V_184 = F_23 ( V_3 -> V_89 + V_185 ) ;
if ( ! ( ( V_184 >> V_3 -> V_112 ) & 0x1 ) )
goto V_73;
}
if ( ! F_17 ( V_3 -> V_50 ) )
F_18 ( V_3 -> V_50 ) ;
F_1 ( V_3 ) ;
F_4 ( & V_3 -> V_11 ) ;
F_16 ( V_3 -> V_49 ) ;
V_3 -> V_80 ( V_3 ) ;
F_18 ( V_3 -> V_49 ) ;
F_7 ( & V_3 -> V_11 ) ;
V_73:
F_47 ( V_3 -> V_186 ) ;
}
static void F_48 ( struct V_1 * V_3 )
{
unsigned int V_187 ;
T_3 V_188 , V_189 ;
if ( V_3 -> V_53 == V_169 ) {
V_188 = V_190 ;
V_189 = V_191 ;
} else if ( V_3 -> V_53 == V_162 ) {
V_188 = V_192 ;
V_189 = V_192 ;
} else if ( V_3 -> V_53 == V_171 ) {
V_188 = V_193 ;
V_189 = V_193 ;
} else {
V_188 = V_194 ;
V_189 = V_195 ;
}
V_187 = F_23 ( V_3 -> V_74 + V_188 ) ;
F_26 ( V_187 , V_3 -> V_74 + V_189 ) ;
}
static void F_49 ( struct V_1 * V_3 )
{
unsigned int V_187 ;
V_187 = F_23 ( V_3 -> V_74 + V_196 ) ;
F_26 ( V_187 , V_3 -> V_74 + V_196 ) ;
}
static T_4 F_50 ( int V_186 , void * V_112 )
{
struct V_1 * V_3 = V_112 ;
F_51 ( V_186 ) ;
F_52 ( & V_3 -> V_183 ) ;
return V_197 ;
}
static int F_53 ( struct V_198 * V_199 )
{
if ( F_54 ( V_199 , L_9 ) )
return V_55 ;
else if ( F_54 ( V_199 , L_10 ) )
return V_133 ;
else if ( F_54 ( V_199 , L_11 ) )
return V_54 ;
else if ( F_54 ( V_199 , L_12 ) )
return V_84 ;
else if ( F_54 ( V_199 , L_13 ) )
return V_169 ;
else if ( F_54 ( V_199 , L_14 ) )
return V_200 ;
else if ( F_54 ( V_199 ,
L_15 ) )
return V_88 ;
else if ( F_54 ( V_199 , L_16 ) )
return V_171 ;
else if ( F_54 ( V_199 , L_17 ) )
return V_158 ;
else if ( F_54 ( V_199 , L_18 ) )
return V_162 ;
return - V_92 ;
}
static int F_55 ( struct V_198 * V_199 ,
struct V_18 * V_19 )
{
T_3 V_201 ;
int V_46 ;
F_56 ( V_199 ) ;
V_46 = F_57 ( V_199 , L_19 , & V_201 ) ;
V_19 -> V_63 = ( T_1 ) V_201 ;
F_57 ( V_199 , L_20 , & V_201 ) ;
V_19 -> V_60 = ( T_1 ) V_201 ;
F_57 ( V_199 , L_21 , & V_201 ) ;
V_19 -> V_64 = ( T_1 ) V_201 ;
F_57 ( V_199 , L_22 ,
& V_19 -> V_34 ) ;
F_57 ( V_199 , L_23 ,
& V_19 -> V_32 ) ;
F_57 ( V_199 , L_24 ,
& V_19 -> V_33 ) ;
F_57 ( V_199 , L_25 , & V_201 ) ;
V_19 -> V_23 = ( T_1 ) V_201 ;
F_57 ( V_199 , L_26 , & V_201 ) ;
V_19 -> V_26 = ( T_1 ) V_201 ;
F_57 ( V_199 , L_27 , & V_201 ) ;
V_19 -> V_28 = ( T_1 ) V_201 ;
F_57 ( V_199 , L_28 , & V_19 -> V_21 ) ;
F_57 ( V_199 , L_29 , & V_19 -> V_202 ) ;
F_58 ( V_199 ) ;
return 0 ;
}
static int F_59 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
struct V_18 * V_19 ;
struct V_203 V_204 ;
if ( ! V_3 || ! V_45 -> V_48 . V_205 )
return - V_72 ;
V_3 -> V_112 = F_60 ( V_45 -> V_48 . V_205 , L_30 ) ;
if ( V_3 -> V_112 < 0 )
V_3 -> V_112 = 0 ;
V_3 -> V_186 = F_61 ( V_45 -> V_48 . V_205 , 0 ) ;
if ( V_3 -> V_186 <= 0 ) {
F_62 ( & V_45 -> V_48 , L_31 ) ;
return - V_72 ;
}
if ( F_63 ( V_45 -> V_48 . V_205 , 0 , & V_204 ) ) {
F_62 ( & V_45 -> V_48 , L_32 ) ;
return - V_72 ;
}
V_3 -> V_74 = F_64 ( & V_45 -> V_48 , V_204 . V_206 , F_65 ( & V_204 ) ) ;
if ( ! V_3 -> V_74 ) {
F_62 ( & V_45 -> V_48 , L_33 ) ;
return - V_207 ;
}
V_19 = F_66 ( & V_45 -> V_48 ,
sizeof( struct V_18 ) ,
V_208 ) ;
if ( ! V_19 )
return - V_209 ;
F_55 ( V_45 -> V_48 . V_205 , V_19 ) ;
V_3 -> V_19 = V_19 ;
V_3 -> V_53 = F_53 ( V_45 -> V_48 . V_205 ) ;
switch ( V_3 -> V_53 ) {
case V_133 :
V_3 -> V_51 = F_21 ;
V_3 -> V_68 = F_30 ;
V_3 -> V_156 = F_40 ;
V_3 -> V_80 = F_48 ;
V_3 -> V_47 = 4 ;
break;
case V_55 :
case V_54 :
case V_84 :
case V_169 :
case V_200 :
case V_88 :
V_3 -> V_51 = F_25 ;
V_3 -> V_68 = F_30 ;
V_3 -> V_156 = F_41 ;
V_3 -> V_177 = F_37 ;
V_3 -> V_80 = F_48 ;
V_3 -> V_47 = 4 ;
break;
case V_171 :
V_3 -> V_51 = F_27 ;
V_3 -> V_68 = F_32 ;
V_3 -> V_156 = F_41 ;
V_3 -> V_177 = F_37 ;
V_3 -> V_80 = F_48 ;
V_3 -> V_47 = 8 ;
break;
case V_158 :
V_3 -> V_51 = F_28 ;
V_3 -> V_68 = F_33 ;
V_3 -> V_156 = F_42 ;
V_3 -> V_177 = F_38 ;
V_3 -> V_80 = F_49 ;
V_3 -> V_47 = 4 ;
break;
case V_162 :
V_3 -> V_51 = F_29 ;
V_3 -> V_68 = F_34 ;
V_3 -> V_156 = F_43 ;
V_3 -> V_177 = F_37 ;
V_3 -> V_80 = F_48 ;
V_3 -> V_47 = 8 ;
break;
default:
F_62 ( & V_45 -> V_48 , L_34 ) ;
return - V_92 ;
}
if ( V_3 -> V_53 != V_88 &&
V_3 -> V_53 != V_158 )
return 0 ;
if ( F_63 ( V_45 -> V_48 . V_205 , 1 , & V_204 ) ) {
F_62 ( & V_45 -> V_48 , L_35 ) ;
return - V_72 ;
}
V_3 -> V_89 = F_64 ( & V_45 -> V_48 , V_204 . V_206 ,
F_65 ( & V_204 ) ) ;
if ( ! V_3 -> V_89 ) {
F_62 ( & V_45 -> V_48 , L_33 ) ;
return - V_209 ;
}
return 0 ;
}
static int F_67 ( struct V_44 * V_45 )
{
struct V_1 * V_3 ;
int V_46 ;
V_3 = F_66 ( & V_45 -> V_48 , sizeof( struct V_1 ) ,
V_208 ) ;
if ( ! V_3 )
return - V_209 ;
F_68 ( V_45 , V_3 ) ;
F_69 ( & V_3 -> V_11 ) ;
V_3 -> V_210 = F_70 ( & V_45 -> V_48 , L_36 ) ;
if ( ! F_17 ( V_3 -> V_210 ) ) {
V_46 = F_71 ( V_3 -> V_210 ) ;
if ( V_46 ) {
F_62 ( & V_45 -> V_48 , L_37 ) ;
return V_46 ;
}
} else {
if ( F_72 ( V_3 -> V_210 ) == - V_211 )
return - V_211 ;
F_15 ( & V_45 -> V_48 , L_38 ) ;
}
V_46 = F_59 ( V_45 ) ;
if ( V_46 )
goto V_212;
F_73 ( & V_3 -> V_183 , F_45 ) ;
V_3 -> V_49 = F_74 ( & V_45 -> V_48 , L_39 ) ;
if ( F_17 ( V_3 -> V_49 ) ) {
F_62 ( & V_45 -> V_48 , L_40 ) ;
V_46 = F_72 ( V_3 -> V_49 ) ;
goto V_212;
}
V_3 -> V_50 = F_74 ( & V_45 -> V_48 , L_41 ) ;
if ( F_17 ( V_3 -> V_50 ) ) {
if ( V_3 -> V_53 == V_88 ) {
F_62 ( & V_45 -> V_48 , L_42 ) ;
V_46 = F_72 ( V_3 -> V_50 ) ;
goto V_212;
}
} else {
V_46 = F_75 ( V_3 -> V_50 ) ;
if ( V_46 ) {
F_62 ( & V_45 -> V_48 , L_40 ) ;
goto V_212;
}
}
V_46 = F_75 ( V_3 -> V_49 ) ;
if ( V_46 ) {
F_62 ( & V_45 -> V_48 , L_40 ) ;
goto V_213;
}
switch ( V_3 -> V_53 ) {
case V_171 :
case V_162 :
V_3 -> V_214 = F_74 ( & V_45 -> V_48 , L_43 ) ;
if ( F_17 ( V_3 -> V_214 ) ) {
F_62 ( & V_45 -> V_48 , L_44 ) ;
goto V_215;
} else {
V_46 = F_76 ( V_3 -> V_214 ) ;
if ( V_46 ) {
F_62 ( & V_45 -> V_48 , L_45 ) ;
goto V_215;
}
}
break;
default:
break;
}
V_3 -> V_7 = F_77 ( & V_45 -> V_48 , 0 , V_3 ,
& V_216 ) ;
if ( F_17 ( V_3 -> V_7 ) ) {
V_46 = F_72 ( V_3 -> V_7 ) ;
F_62 ( & V_45 -> V_48 , L_46 , V_46 ) ;
goto V_217;
}
V_46 = F_13 ( V_45 ) ;
if ( V_46 ) {
F_62 ( & V_45 -> V_48 , L_47 ) ;
goto V_218;
}
V_46 = F_78 ( & V_45 -> V_48 , V_3 -> V_186 , F_50 ,
V_219 | V_220 , F_79 ( & V_45 -> V_48 ) , V_3 ) ;
if ( V_46 ) {
F_62 ( & V_45 -> V_48 , L_48 , V_3 -> V_186 ) ;
goto V_218;
}
F_20 ( V_45 , true ) ;
return 0 ;
V_218:
F_80 ( & V_45 -> V_48 , V_3 -> V_7 ) ;
V_217:
F_81 ( V_3 -> V_214 ) ;
V_215:
F_82 ( V_3 -> V_49 ) ;
V_213:
if ( ! F_17 ( V_3 -> V_50 ) )
F_82 ( V_3 -> V_50 ) ;
V_212:
if ( ! F_17 ( V_3 -> V_210 ) )
F_83 ( V_3 -> V_210 ) ;
return V_46 ;
}
static int F_84 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_14 ( V_45 ) ;
struct V_5 * V_7 = V_3 -> V_7 ;
F_80 ( & V_45 -> V_48 , V_7 ) ;
F_20 ( V_45 , false ) ;
F_81 ( V_3 -> V_214 ) ;
F_82 ( V_3 -> V_49 ) ;
if ( ! F_17 ( V_3 -> V_50 ) )
F_82 ( V_3 -> V_50 ) ;
if ( ! F_17 ( V_3 -> V_210 ) )
F_83 ( V_3 -> V_210 ) ;
return 0 ;
}
static int F_85 ( struct V_15 * V_48 )
{
F_20 ( F_86 ( V_48 ) , false ) ;
return 0 ;
}
static int F_87 ( struct V_15 * V_48 )
{
struct V_44 * V_45 = F_86 ( V_48 ) ;
F_13 ( V_45 ) ;
F_20 ( V_45 , true ) ;
return 0 ;
}
