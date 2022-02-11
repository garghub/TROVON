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
F_3 ( V_6 ) ;
F_4 ( & V_6 -> V_10 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
V_6 -> V_11 -> V_12 ( V_6 , V_9 , & V_8 ) ;
if ( V_6 -> V_13 < V_8 )
break;
}
snprintf ( V_3 , sizeof( V_3 ) , L_2 , V_9 ) ;
F_6 ( & V_6 -> V_14 . V_15 , V_16 , V_4 ) ;
F_7 ( & V_6 -> V_10 ) ;
}
static int F_8 ( struct V_1 * V_3 , T_1 V_8 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
int V_19 ;
switch ( V_18 -> V_20 ) {
case V_21 :
V_19 = ( V_8 - V_18 -> V_22 ) *
( V_3 -> V_23 - V_3 -> V_24 ) /
( V_18 -> V_25 - V_18 -> V_22 ) +
V_3 -> V_24 ;
break;
case V_26 :
V_19 = V_8 + V_3 -> V_24 - V_18 -> V_22 ;
break;
default:
V_19 = V_8 + V_18 -> V_27 ;
break;
}
return V_19 ;
}
static int F_9 ( struct V_1 * V_3 , T_2 V_19 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
int V_8 ;
switch ( V_18 -> V_20 ) {
case V_21 :
V_8 = ( V_19 - V_3 -> V_24 ) *
( V_18 -> V_25 - V_18 -> V_22 ) /
( V_3 -> V_23 - V_3 -> V_24 ) +
V_18 -> V_22 ;
break;
case V_26 :
V_8 = V_19 - V_3 -> V_24 + V_18 -> V_22 ;
break;
default:
V_8 = V_19 - V_18 -> V_27 ;
break;
}
return V_8 ;
}
static void F_10 ( struct V_1 * V_3 , T_3 V_28 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
V_3 -> V_24 = V_28 & V_29 ;
V_3 -> V_23 = ( ( V_28 >> V_30 ) &
V_29 ) ;
if ( ! V_3 -> V_24 ||
( V_18 -> V_31 > V_3 -> V_24 ) ||
( V_3 -> V_24 > V_18 -> V_32 ) )
V_3 -> V_24 = V_18 -> V_33 & V_29 ;
if ( ! V_3 -> V_23 )
V_3 -> V_23 =
( V_18 -> V_33 >> V_30 ) &
V_29 ;
}
static T_3 F_11 ( struct V_1 * V_3 , T_3 V_34 , bool V_35 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
const struct V_36 * const V_37 =
F_12 ( V_6 ) ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_37 ) {
F_2 ( L_3 ,
V_38 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
if ( V_37 [ V_9 ] . type == V_39 )
continue;
V_8 = V_37 [ V_9 ] . V_40 / V_41 ;
if ( V_35 )
V_8 -= ( V_37 [ V_9 ] . V_42 / V_41 ) ;
else
V_34 &= ~ ( 0xff << 8 * V_9 ) ;
V_34 |= F_8 ( V_3 , V_8 ) << 8 * V_9 ;
}
return V_34 ;
}
static int F_13 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
int V_45 ;
if ( F_5 ( V_3 -> V_7 ) > V_3 -> V_46 ) {
F_15 ( & V_44 -> V_47 ,
L_4 ) ;
F_15 ( & V_44 -> V_47 ,
L_5 ,
( F_5 ( V_3 -> V_7 ) - V_3 -> V_46 ) ) ;
}
F_4 ( & V_3 -> V_10 ) ;
F_16 ( V_3 -> V_48 ) ;
if ( ! F_17 ( V_3 -> V_49 ) )
F_16 ( V_3 -> V_49 ) ;
V_45 = V_3 -> V_50 ( V_44 ) ;
F_18 ( V_3 -> V_48 ) ;
F_7 ( & V_3 -> V_10 ) ;
if ( ! F_17 ( V_3 -> V_49 ) )
F_18 ( V_3 -> V_49 ) ;
return V_45 ;
}
static T_3 F_19 ( struct V_1 * V_3 , T_3 V_51 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
if ( V_3 -> V_52 == V_53 ||
V_3 -> V_52 == V_54 )
V_51 |= ( V_55 << V_56 ) ;
V_51 &= ~ ( V_57 << V_58 ) ;
V_51 |= V_18 -> V_59 << V_58 ;
V_51 &= ~ ( V_60 << V_61 ) ;
V_51 |= ( V_18 -> V_62 << V_61 ) ;
if ( V_18 -> V_63 ) {
V_51 &= ~ ( V_64 << V_65 ) ;
V_51 |= ( V_18 -> V_63 << V_65 ) ;
}
return V_51 ;
}
static void F_20 ( struct V_43 * V_44 , bool V_66 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
F_4 ( & V_3 -> V_10 ) ;
F_16 ( V_3 -> V_48 ) ;
V_3 -> V_67 ( V_44 , V_66 ) ;
F_18 ( V_3 -> V_48 ) ;
F_7 ( & V_3 -> V_10 ) ;
}
static int F_21 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
const struct V_36 * const V_37 =
F_12 ( V_6 ) ;
int V_45 = 0 , V_68 , V_9 ;
unsigned long V_69 , V_8 ;
unsigned int V_70 ;
if ( ! V_37 ) {
F_2 ( L_3 ,
V_38 ) ;
V_45 = - V_71 ;
goto V_72;
}
V_70 = F_22 ( V_3 -> V_73 + V_74 ) ;
if ( ! V_70 ) {
V_45 = - V_75 ;
goto V_72;
}
F_10 ( V_3 , F_23 ( V_3 -> V_73 + V_76 ) ) ;
V_69 = V_37 [ 0 ] . V_40 / V_41 ;
V_68 = F_8 ( V_3 , V_69 ) ;
if ( V_68 < 0 ) {
V_45 = V_68 ;
goto V_72;
}
F_24 ( V_68 , V_3 -> V_73 + V_77 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
V_8 = V_37 [ V_9 ] . V_40 / V_41 ;
F_24 ( V_8 - V_69 , V_3 -> V_73 +
V_78 + V_9 * 4 ) ;
}
V_3 -> V_79 ( V_3 ) ;
V_72:
return V_45 ;
}
static int F_25 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
const struct V_36 * const V_37 =
F_12 ( V_3 -> V_7 ) ;
unsigned int V_70 , V_28 , V_51 , V_80 , V_81 ;
int V_45 = 0 , V_68 , V_9 ;
unsigned long V_82 = 0 ;
V_70 = F_22 ( V_3 -> V_73 + V_74 ) ;
if ( ! V_70 ) {
V_45 = - V_75 ;
goto V_72;
}
if ( V_3 -> V_52 == V_54 ||
V_3 -> V_52 == V_53 ||
V_3 -> V_52 == V_83 ) {
if ( V_3 -> V_52 == V_54 ) {
V_80 = F_23 ( V_3 -> V_73 + V_84 ) ;
V_80 |= V_85 ;
F_26 ( V_80 , V_3 -> V_73 + V_84 ) ;
}
V_80 = F_23 ( V_3 -> V_73 + V_86 ) ;
V_80 |= V_85 ;
F_26 ( V_80 , V_3 -> V_73 + V_86 ) ;
}
if ( V_3 -> V_52 == V_87 )
V_28 = F_23 ( V_3 -> V_88 + V_76 ) ;
else
V_28 = F_23 ( V_3 -> V_73 + V_76 ) ;
F_10 ( V_3 , V_28 ) ;
V_81 = F_23 ( V_3 -> V_73 + V_89 ) ;
V_81 = F_11 ( V_3 , V_81 , false ) ;
F_26 ( V_81 , V_3 -> V_73 + V_89 ) ;
F_26 ( F_11 ( V_3 , 0 , true ) , V_3 -> V_73 + V_90 ) ;
V_3 -> V_79 ( V_3 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_3 -> V_7 ) ; V_9 ++ ) {
if ( V_37 [ V_9 ] . type == V_39 ) {
V_82 = V_37 [ V_9 ] . V_40 ;
break;
}
}
if ( V_9 == F_5 ( V_3 -> V_7 ) ) {
F_2 ( L_6 ,
V_38 ) ;
V_45 = - V_91 ;
goto V_72;
}
V_68 = F_8 ( V_3 , V_82 / V_41 ) ;
V_81 &= ~ ( 0xff << 8 * V_9 ) ;
V_81 |= V_68 << 8 * V_9 ;
F_26 ( V_81 , V_3 -> V_73 + V_89 ) ;
V_51 = F_23 ( V_3 -> V_73 + V_92 ) ;
V_51 |= ( 1 << V_93 ) ;
F_26 ( V_51 , V_3 -> V_73 + V_92 ) ;
V_72:
return V_45 ;
}
static int F_27 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_70 , V_28 ;
unsigned int V_81 = 0 , V_94 = 0 ;
int V_8 , V_95 ;
int V_45 = 0 , V_68 , V_9 , V_96 , V_20 ;
V_70 = F_22 ( V_3 -> V_73 + V_74 ) ;
if ( ! V_70 ) {
V_45 = - V_75 ;
goto V_72;
}
V_28 = F_23 ( V_3 -> V_73 + V_76 ) ;
F_10 ( V_3 , V_28 ) ;
V_96 = ( V_28 & V_97 )
>> V_98 ;
F_15 ( & V_44 -> V_47 , L_7 , V_96 ) ;
F_26 ( V_28 , V_3 -> V_73 + V_76 ) ;
V_20 = ( V_28 & V_99 )
>> V_100 ;
switch ( V_20 ) {
case V_101 :
V_18 -> V_20 = V_26 ;
break;
case V_102 :
V_18 -> V_20 = V_21 ;
break;
default:
V_18 -> V_20 = V_26 ;
break;
}
F_15 ( & V_44 -> V_47 , L_8 ,
V_20 ? 2 : 1 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
int V_103 , V_104 ;
int V_105 = 0 ;
switch ( V_9 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_103 = V_106 ;
V_104 = V_107 ;
V_105 = V_9 ;
break;
case 4 :
case 5 :
case 6 :
case 7 :
V_103 = V_108 ;
V_104 = V_109 ;
V_105 = V_9 - 4 ;
break;
default:
continue;
}
V_6 -> V_11 -> V_12 ( V_6 , V_9 , & V_8 ) ;
V_8 /= V_41 ;
V_68 = F_8 ( V_3 , V_8 ) ;
V_81 = F_23 ( V_3 -> V_73 + V_103 ) ;
V_81 |= ( V_68 << V_105 * 8 ) ;
F_26 ( V_81 , V_3 -> V_73 + V_103 ) ;
V_6 -> V_11 -> V_110 ( V_6 , V_9 , & V_95 ) ;
V_95 = V_8 - ( V_95 / V_41 ) ;
V_68 = F_8 ( V_3 , V_95 ) ;
V_94 = F_23 ( V_3 -> V_73 + V_104 ) ;
V_94 &= ~ ( 0xff << V_105 * 8 ) ;
V_94 |= ( V_68 << V_105 * 8 ) ;
F_26 ( V_94 , V_3 -> V_73 + V_104 ) ;
}
V_3 -> V_79 ( V_3 ) ;
V_72:
return V_45 ;
}
static int F_28 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
unsigned int V_28 = 0 , V_51 , V_81 ;
int V_68 ;
int V_82 = 0 ;
switch ( V_3 -> V_111 ) {
case 0 :
V_28 = F_23 ( V_3 -> V_73 + V_112 +
V_113 ) ;
break;
case 1 :
V_28 = F_23 ( V_3 -> V_73 + V_113 ) ;
break;
case 2 :
V_28 = F_23 ( V_3 -> V_73 - V_112 +
V_113 ) ;
}
F_10 ( V_3 , V_28 ) ;
V_81 = F_23 ( V_3 -> V_73 + V_114 ) ;
V_81 = F_11 ( V_3 , V_81 , false ) ;
F_26 ( V_81 , V_3 -> V_73 + V_114 ) ;
F_26 ( 0 , V_3 -> V_73 + V_115 ) ;
V_3 -> V_79 ( V_3 ) ;
if ( ! V_3 -> V_7 -> V_11 -> V_116 ( V_3 -> V_7 , & V_82 ) ) {
V_68 = F_8 ( V_3 , V_82 / V_41 ) ;
V_81 =
V_68 << V_117 ;
F_26 ( V_81 , V_3 -> V_73 + V_118 ) ;
V_51 = F_23 ( V_3 -> V_73 + V_119 ) ;
V_51 |= ( 1 << V_93 ) ;
F_26 ( V_51 , V_3 -> V_73 + V_119 ) ;
}
if ( ! V_3 -> V_111 )
F_26 ( 0 , V_3 -> V_88 + V_120 ) ;
return 0 ;
}
static int F_29 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_17 * V_18 = V_3 -> V_18 ;
unsigned int V_70 , V_28 ;
unsigned int V_81 = 0 , V_94 = 0 ;
int V_45 = 0 , V_68 , V_9 ;
int V_8 , V_95 ;
unsigned int V_121 , V_122 ;
V_70 = F_22 ( V_3 -> V_73 + V_74 ) ;
if ( ! V_70 ) {
V_45 = - V_75 ;
goto V_72;
}
V_28 = F_23 ( V_3 -> V_73 + V_76 ) ;
V_3 -> V_24 = V_28 & V_123 ;
if ( ! V_3 -> V_24 ||
( V_18 -> V_31 > V_3 -> V_24 ) ||
( V_3 -> V_24 > V_18 -> V_32 ) )
V_3 -> V_24 = V_18 -> V_33 & V_29 ;
for ( V_9 = ( F_5 ( V_6 ) - 1 ) ; V_9 >= 0 ; V_9 -- ) {
V_121 = ( ( 7 - V_9 ) / 2 ) * 4 ;
V_122 = ( ( 8 - V_9 ) % 2 ) ;
V_6 -> V_11 -> V_12 ( V_6 , V_9 , & V_8 ) ;
V_8 /= V_41 ;
V_6 -> V_11 -> V_110 ( V_6 , V_9 , & V_95 ) ;
V_95 = V_8 - ( V_95 / V_41 ) ;
V_68 = F_8 ( V_3 , V_8 ) ;
V_81 = F_23 ( V_3 -> V_73 +
V_124 + V_121 ) ;
V_81 &= ~ ( V_123 << ( 16 * V_122 ) ) ;
V_81 |= V_68 << ( 16 * V_122 ) ;
F_26 ( V_81 ,
V_3 -> V_73 + V_124 + V_121 ) ;
V_68 = F_8 ( V_3 , V_95 ) ;
V_94 &= ~ ( V_123 << ( 16 * V_122 ) ) ;
V_94 |= V_68 << ( 16 * V_122 ) ;
F_26 ( V_94 ,
V_3 -> V_73 + V_125 + V_121 ) ;
}
V_3 -> V_79 ( V_3 ) ;
V_72:
return V_45 ;
}
static void F_30 ( struct V_43 * V_44 , bool V_66 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_51 , V_126 ;
V_51 = F_19 ( V_3 , F_23 ( V_3 -> V_73 + V_92 ) ) ;
if ( V_66 ) {
V_51 |= ( 1 << V_127 ) ;
V_126 =
( F_31 ( V_6 , 3 )
<< V_128 ) |
( F_31 ( V_6 , 2 )
<< V_129 ) |
( F_31 ( V_6 , 1 )
<< V_130 ) |
( F_31 ( V_6 , 0 )
<< V_131 ) ;
if ( V_3 -> V_52 != V_132 )
V_126 |=
V_126 << V_133 ;
} else {
V_51 &= ~ ( 1 << V_127 ) ;
V_126 = 0 ;
}
F_26 ( V_126 , V_3 -> V_73 + V_134 ) ;
F_26 ( V_51 , V_3 -> V_73 + V_92 ) ;
}
static void F_32 ( struct V_43 * V_44 , bool V_66 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_51 , V_126 , V_135 ;
V_51 = F_19 ( V_3 , F_23 ( V_3 -> V_73 + V_92 ) ) ;
if ( V_66 ) {
V_51 |= ( 1 << V_127 ) ;
V_126 =
( F_31 ( V_6 , 7 )
<< V_136 ) |
( F_31 ( V_6 , 6 )
<< V_137 ) |
( F_31 ( V_6 , 5 )
<< V_138 ) |
( F_31 ( V_6 , 4 )
<< V_139 ) |
( F_31 ( V_6 , 3 )
<< V_140 ) |
( F_31 ( V_6 , 2 )
<< V_141 ) |
( F_31 ( V_6 , 1 )
<< V_142 ) |
( F_31 ( V_6 , 0 )
<< V_143 ) ;
V_126 |=
V_126 << V_133 ;
} else {
V_51 &= ~ ( 1 << V_127 ) ;
V_126 = 0 ;
}
V_135 = V_66 ? V_144 : 0 ;
F_26 ( V_135 , V_3 -> V_73 + V_145 ) ;
F_26 ( V_126 , V_3 -> V_73 + V_146 ) ;
F_26 ( V_51 , V_3 -> V_73 + V_92 ) ;
}
static void F_33 ( struct V_43 * V_44 , bool V_66 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_51 , V_126 ;
V_51 = F_19 ( V_3 , F_23 ( V_3 -> V_73 + V_119 ) ) ;
if ( V_66 ) {
V_51 |= ( 1 << V_127 ) ;
V_126 =
( F_31 ( V_6 , 3 )
<< V_147 ) |
( F_31 ( V_6 , 2 )
<< V_148 ) |
( F_31 ( V_6 , 1 )
<< V_149 ) |
( F_31 ( V_6 , 0 )
<< V_150 ) ;
V_126 |=
V_126 << V_151 ;
} else {
V_51 &= ~ ( 1 << V_127 ) ;
V_126 = 0 ;
}
F_26 ( V_126 , V_3 -> V_73 + V_152 ) ;
F_26 ( V_51 , V_3 -> V_73 + V_119 ) ;
}
static void F_34 ( struct V_43 * V_44 , bool V_66 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_51 , V_126 ;
V_51 = F_19 ( V_3 , F_23 ( V_3 -> V_73 + V_92 ) ) ;
if ( V_66 ) {
V_51 |= ( 1 << V_127 ) ;
V_51 |= ( 1 << V_153 ) ;
V_126 =
( F_31 ( V_6 , 7 )
<< V_136 ) |
( F_31 ( V_6 , 6 )
<< V_137 ) |
( F_31 ( V_6 , 5 )
<< V_138 ) |
( F_31 ( V_6 , 4 )
<< V_139 ) |
( F_31 ( V_6 , 3 )
<< V_140 ) |
( F_31 ( V_6 , 2 )
<< V_141 ) |
( F_31 ( V_6 , 1 )
<< V_142 ) |
( F_31 ( V_6 , 0 )
<< V_143 ) ;
V_126 |=
V_126 << V_133 ;
} else {
V_51 &= ~ ( 1 << V_127 ) ;
V_51 &= ~ ( 1 << V_153 ) ;
V_126 = 0 ;
}
F_26 ( V_126 , V_3 -> V_73 + V_154 ) ;
F_26 ( V_51 , V_3 -> V_73 + V_92 ) ;
}
static int F_35 ( void * V_2 , int * V_8 )
{
struct V_1 * V_3 = V_2 ;
if ( ! V_3 || ! V_3 -> V_155 )
return - V_91 ;
F_4 ( & V_3 -> V_10 ) ;
F_16 ( V_3 -> V_48 ) ;
* V_8 = F_9 ( V_3 , V_3 -> V_155 ( V_3 ) ) * V_41 ;
F_18 ( V_3 -> V_48 ) ;
F_7 ( & V_3 -> V_10 ) ;
return 0 ;
}
static T_3 F_36 ( struct V_1 * V_3 , unsigned int V_156 ,
int V_8 )
{
if ( V_8 ) {
V_8 /= V_41 ;
if ( V_3 -> V_52 != V_157 ) {
V_156 &= ~ ( V_158 << V_159 ) ;
V_156 |= ( V_160 << V_159 ) ;
}
if ( V_3 -> V_52 == V_161 ) {
V_156 &= ~ ( V_162 <<
V_163 ) ;
V_156 |= ( F_8 ( V_3 , V_8 ) <<
V_163 ) |
V_164 ;
} else {
V_156 &= ~ ( V_165 <<
V_166 ) ;
V_156 |= ( F_8 ( V_3 , V_8 ) <<
V_166 ) |
V_164 ;
}
} else {
V_156 &= ~ V_164 ;
}
return V_156 ;
}
static void F_37 ( struct V_1 * V_3 ,
int V_8 )
{
unsigned int V_156 ;
T_3 V_167 ;
if ( V_3 -> V_52 == V_168 )
V_167 = V_169 ;
else if ( V_3 -> V_52 == V_170 )
V_167 = V_171 ;
else if ( V_3 -> V_52 == V_161 )
V_167 = V_172 ;
else
V_167 = V_173 ;
V_156 = F_23 ( V_3 -> V_73 + V_167 ) ;
V_156 = F_36 ( V_3 , V_156 , V_8 ) ;
F_26 ( V_156 , V_3 -> V_73 + V_167 ) ;
}
static void F_38 ( struct V_1 * V_3 ,
int V_8 )
{
unsigned int V_156 ;
V_156 = F_23 ( V_3 -> V_73 + V_174 ) ;
V_156 = F_36 ( V_3 , V_156 , V_8 ) ;
F_26 ( V_156 , V_3 -> V_73 + V_174 ) ;
}
static int F_39 ( void * V_175 , int V_8 )
{
struct V_1 * V_3 = V_175 ;
int V_45 = - V_91 ;
if ( V_3 -> V_52 == V_132 )
goto V_72;
if ( V_8 && V_8 < V_41 )
goto V_72;
F_4 ( & V_3 -> V_10 ) ;
F_16 ( V_3 -> V_48 ) ;
V_3 -> V_176 ( V_3 , V_8 ) ;
F_18 ( V_3 -> V_48 ) ;
F_7 ( & V_3 -> V_10 ) ;
return 0 ;
V_72:
return V_45 ;
}
static int F_39 ( void * V_175 , int V_8 )
{ return - V_91 ; }
static int F_40 ( struct V_1 * V_3 )
{
int V_45 = F_22 ( V_3 -> V_73 + V_177 ) ;
return ( V_45 < 75 || V_45 > 175 ) ? - V_178 : V_45 ;
}
static int F_41 ( struct V_1 * V_3 )
{
return F_22 ( V_3 -> V_73 + V_177 ) ;
}
static int F_42 ( struct V_1 * V_3 )
{
return F_22 ( V_3 -> V_73 + V_179 ) ;
}
static int F_43 ( struct V_1 * V_3 )
{
return F_44 ( V_3 -> V_73 + V_177 ) &
V_123 ;
}
static void F_45 ( struct V_180 * V_181 )
{
struct V_1 * V_3 = F_46 ( V_181 ,
struct V_1 , V_182 ) ;
unsigned int V_183 ;
if ( ! F_17 ( V_3 -> V_49 ) )
F_16 ( V_3 -> V_49 ) ;
if ( V_3 -> V_52 == V_157 ) {
V_183 = F_23 ( V_3 -> V_88 + V_184 ) ;
if ( ! ( ( V_183 >> V_3 -> V_111 ) & 0x1 ) )
goto V_72;
}
if ( ! F_17 ( V_3 -> V_49 ) )
F_18 ( V_3 -> V_49 ) ;
F_1 ( V_3 ) ;
F_4 ( & V_3 -> V_10 ) ;
F_16 ( V_3 -> V_48 ) ;
V_3 -> V_79 ( V_3 ) ;
F_18 ( V_3 -> V_48 ) ;
F_7 ( & V_3 -> V_10 ) ;
V_72:
F_47 ( V_3 -> V_185 ) ;
}
static void F_48 ( struct V_1 * V_3 )
{
unsigned int V_186 ;
T_3 V_187 , V_188 ;
if ( V_3 -> V_52 == V_168 ) {
V_187 = V_189 ;
V_188 = V_190 ;
} else if ( V_3 -> V_52 == V_161 ) {
V_187 = V_191 ;
V_188 = V_191 ;
} else if ( V_3 -> V_52 == V_170 ) {
V_187 = V_192 ;
V_188 = V_192 ;
} else {
V_187 = V_193 ;
V_188 = V_194 ;
}
V_186 = F_23 ( V_3 -> V_73 + V_187 ) ;
F_26 ( V_186 , V_3 -> V_73 + V_188 ) ;
}
static void F_49 ( struct V_1 * V_3 )
{
unsigned int V_186 ;
V_186 = F_23 ( V_3 -> V_73 + V_195 ) ;
F_26 ( V_186 , V_3 -> V_73 + V_195 ) ;
}
static T_4 F_50 ( int V_185 , void * V_111 )
{
struct V_1 * V_3 = V_111 ;
F_51 ( V_185 ) ;
F_52 ( & V_3 -> V_182 ) ;
return V_196 ;
}
static int F_53 ( struct V_197 * V_198 )
{
if ( F_54 ( V_198 , L_9 ) )
return V_54 ;
else if ( F_54 ( V_198 , L_10 ) )
return V_132 ;
else if ( F_54 ( V_198 , L_11 ) )
return V_53 ;
else if ( F_54 ( V_198 , L_12 ) )
return V_83 ;
else if ( F_54 ( V_198 , L_13 ) )
return V_168 ;
else if ( F_54 ( V_198 , L_14 ) )
return V_199 ;
else if ( F_54 ( V_198 ,
L_15 ) )
return V_87 ;
else if ( F_54 ( V_198 , L_16 ) )
return V_170 ;
else if ( F_54 ( V_198 , L_17 ) )
return V_157 ;
else if ( F_54 ( V_198 , L_18 ) )
return V_161 ;
return - V_91 ;
}
static int F_55 ( struct V_197 * V_198 ,
struct V_17 * V_18 )
{
T_3 V_200 ;
int V_45 ;
F_56 ( V_198 ) ;
V_45 = F_57 ( V_198 , L_19 , & V_200 ) ;
V_18 -> V_62 = ( T_1 ) V_200 ;
F_57 ( V_198 , L_20 , & V_200 ) ;
V_18 -> V_59 = ( T_1 ) V_200 ;
F_57 ( V_198 , L_21 , & V_200 ) ;
V_18 -> V_63 = ( T_1 ) V_200 ;
F_57 ( V_198 , L_22 ,
& V_18 -> V_33 ) ;
F_57 ( V_198 , L_23 ,
& V_18 -> V_31 ) ;
F_57 ( V_198 , L_24 ,
& V_18 -> V_32 ) ;
F_57 ( V_198 , L_25 , & V_200 ) ;
V_18 -> V_22 = ( T_1 ) V_200 ;
F_57 ( V_198 , L_26 , & V_200 ) ;
V_18 -> V_25 = ( T_1 ) V_200 ;
F_57 ( V_198 , L_27 , & V_200 ) ;
V_18 -> V_27 = ( T_1 ) V_200 ;
F_57 ( V_198 , L_28 , & V_18 -> V_20 ) ;
F_57 ( V_198 , L_29 , & V_18 -> V_201 ) ;
F_58 ( V_198 ) ;
return 0 ;
}
static int F_59 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_17 * V_18 ;
struct V_202 V_203 ;
if ( ! V_3 || ! V_44 -> V_47 . V_204 )
return - V_71 ;
V_3 -> V_111 = F_60 ( V_44 -> V_47 . V_204 , L_30 ) ;
if ( V_3 -> V_111 < 0 )
V_3 -> V_111 = 0 ;
V_3 -> V_185 = F_61 ( V_44 -> V_47 . V_204 , 0 ) ;
if ( V_3 -> V_185 <= 0 ) {
F_62 ( & V_44 -> V_47 , L_31 ) ;
return - V_71 ;
}
if ( F_63 ( V_44 -> V_47 . V_204 , 0 , & V_203 ) ) {
F_62 ( & V_44 -> V_47 , L_32 ) ;
return - V_71 ;
}
V_3 -> V_73 = F_64 ( & V_44 -> V_47 , V_203 . V_205 , F_65 ( & V_203 ) ) ;
if ( ! V_3 -> V_73 ) {
F_62 ( & V_44 -> V_47 , L_33 ) ;
return - V_206 ;
}
V_18 = F_66 ( & V_44 -> V_47 ,
sizeof( struct V_17 ) ,
V_207 ) ;
if ( ! V_18 )
return - V_208 ;
F_55 ( V_44 -> V_47 . V_204 , V_18 ) ;
V_3 -> V_18 = V_18 ;
V_3 -> V_52 = F_53 ( V_44 -> V_47 . V_204 ) ;
switch ( V_3 -> V_52 ) {
case V_132 :
V_3 -> V_50 = F_21 ;
V_3 -> V_67 = F_30 ;
V_3 -> V_155 = F_40 ;
V_3 -> V_79 = F_48 ;
V_3 -> V_46 = 4 ;
break;
case V_54 :
case V_53 :
case V_83 :
case V_168 :
case V_199 :
case V_87 :
V_3 -> V_50 = F_25 ;
V_3 -> V_67 = F_30 ;
V_3 -> V_155 = F_41 ;
V_3 -> V_176 = F_37 ;
V_3 -> V_79 = F_48 ;
V_3 -> V_46 = 4 ;
break;
case V_170 :
V_3 -> V_50 = F_27 ;
V_3 -> V_67 = F_32 ;
V_3 -> V_155 = F_41 ;
V_3 -> V_176 = F_37 ;
V_3 -> V_79 = F_48 ;
V_3 -> V_46 = 8 ;
break;
case V_157 :
V_3 -> V_50 = F_28 ;
V_3 -> V_67 = F_33 ;
V_3 -> V_155 = F_42 ;
V_3 -> V_176 = F_38 ;
V_3 -> V_79 = F_49 ;
V_3 -> V_46 = 4 ;
break;
case V_161 :
V_3 -> V_50 = F_29 ;
V_3 -> V_67 = F_34 ;
V_3 -> V_155 = F_43 ;
V_3 -> V_176 = F_37 ;
V_3 -> V_79 = F_48 ;
V_3 -> V_46 = 8 ;
break;
default:
F_62 ( & V_44 -> V_47 , L_34 ) ;
return - V_91 ;
}
if ( V_3 -> V_52 != V_87 &&
V_3 -> V_52 != V_157 )
return 0 ;
if ( F_63 ( V_44 -> V_47 . V_204 , 1 , & V_203 ) ) {
F_62 ( & V_44 -> V_47 , L_35 ) ;
return - V_71 ;
}
V_3 -> V_88 = F_64 ( & V_44 -> V_47 , V_203 . V_205 ,
F_65 ( & V_203 ) ) ;
if ( ! V_3 -> V_88 ) {
F_62 ( & V_44 -> V_47 , L_33 ) ;
return - V_208 ;
}
return 0 ;
}
static int F_67 ( struct V_43 * V_44 )
{
struct V_1 * V_3 ;
int V_45 ;
V_3 = F_66 ( & V_44 -> V_47 , sizeof( struct V_1 ) ,
V_207 ) ;
if ( ! V_3 )
return - V_208 ;
F_68 ( V_44 , V_3 ) ;
F_69 ( & V_3 -> V_10 ) ;
V_3 -> V_209 = F_70 ( & V_44 -> V_47 , L_36 ) ;
if ( ! F_17 ( V_3 -> V_209 ) ) {
V_45 = F_71 ( V_3 -> V_209 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_47 , L_37 ) ;
return V_45 ;
}
} else {
if ( F_72 ( V_3 -> V_209 ) == - V_210 )
return - V_210 ;
F_15 ( & V_44 -> V_47 , L_38 ) ;
}
V_45 = F_59 ( V_44 ) ;
if ( V_45 )
goto V_211;
F_73 ( & V_3 -> V_182 , F_45 ) ;
V_3 -> V_48 = F_74 ( & V_44 -> V_47 , L_39 ) ;
if ( F_17 ( V_3 -> V_48 ) ) {
F_62 ( & V_44 -> V_47 , L_40 ) ;
V_45 = F_72 ( V_3 -> V_48 ) ;
goto V_211;
}
V_3 -> V_49 = F_74 ( & V_44 -> V_47 , L_41 ) ;
if ( F_17 ( V_3 -> V_49 ) ) {
if ( V_3 -> V_52 == V_87 ) {
F_62 ( & V_44 -> V_47 , L_42 ) ;
V_45 = F_72 ( V_3 -> V_49 ) ;
goto V_211;
}
} else {
V_45 = F_75 ( V_3 -> V_49 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_47 , L_40 ) ;
goto V_211;
}
}
V_45 = F_75 ( V_3 -> V_48 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_47 , L_40 ) ;
goto V_212;
}
switch ( V_3 -> V_52 ) {
case V_170 :
case V_161 :
V_3 -> V_213 = F_74 ( & V_44 -> V_47 , L_43 ) ;
if ( F_17 ( V_3 -> V_213 ) ) {
F_62 ( & V_44 -> V_47 , L_44 ) ;
goto V_214;
} else {
V_45 = F_76 ( V_3 -> V_213 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_47 , L_45 ) ;
goto V_214;
}
}
break;
default:
break;
}
V_3 -> V_7 = F_77 ( & V_44 -> V_47 , 0 , V_3 ,
& V_215 ) ;
if ( F_17 ( V_3 -> V_7 ) ) {
V_45 = F_72 ( V_3 -> V_7 ) ;
F_62 ( & V_44 -> V_47 , L_46 , V_45 ) ;
goto V_216;
}
V_45 = F_13 ( V_44 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_47 , L_47 ) ;
goto V_217;
}
V_45 = F_78 ( & V_44 -> V_47 , V_3 -> V_185 , F_50 ,
V_218 | V_219 , F_79 ( & V_44 -> V_47 ) , V_3 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_47 , L_48 , V_3 -> V_185 ) ;
goto V_217;
}
F_20 ( V_44 , true ) ;
return 0 ;
V_217:
F_80 ( & V_44 -> V_47 , V_3 -> V_7 ) ;
V_216:
F_81 ( V_3 -> V_213 ) ;
V_214:
F_82 ( V_3 -> V_48 ) ;
V_212:
if ( ! F_17 ( V_3 -> V_49 ) )
F_82 ( V_3 -> V_49 ) ;
V_211:
if ( ! F_17 ( V_3 -> V_209 ) )
F_83 ( V_3 -> V_209 ) ;
return V_45 ;
}
static int F_84 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_7 = V_3 -> V_7 ;
F_80 ( & V_44 -> V_47 , V_7 ) ;
F_20 ( V_44 , false ) ;
F_81 ( V_3 -> V_213 ) ;
F_82 ( V_3 -> V_48 ) ;
if ( ! F_17 ( V_3 -> V_49 ) )
F_82 ( V_3 -> V_49 ) ;
if ( ! F_17 ( V_3 -> V_209 ) )
F_83 ( V_3 -> V_209 ) ;
return 0 ;
}
static int F_85 ( struct V_14 * V_47 )
{
F_20 ( F_86 ( V_47 ) , false ) ;
return 0 ;
}
static int F_87 ( struct V_14 * V_47 )
{
struct V_43 * V_44 = F_86 ( V_47 ) ;
F_13 ( V_44 ) ;
F_20 ( V_44 , true ) ;
return 0 ;
}
