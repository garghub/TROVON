static void F_1 ( struct V_1 * V_2 )
{
char V_3 [ 10 ] , * V_4 [] = { V_3 , NULL } ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
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
F_4 ( & V_3 -> V_10 ) ;
F_15 ( V_3 -> V_46 ) ;
if ( ! F_16 ( V_3 -> V_47 ) )
F_15 ( V_3 -> V_47 ) ;
V_45 = V_3 -> V_48 ( V_44 ) ;
F_17 ( V_3 -> V_46 ) ;
F_7 ( & V_3 -> V_10 ) ;
if ( ! F_16 ( V_3 -> V_47 ) )
F_17 ( V_3 -> V_47 ) ;
return V_45 ;
}
static T_3 F_18 ( struct V_1 * V_3 , T_3 V_49 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
if ( V_3 -> V_50 == V_51 ||
V_3 -> V_50 == V_52 )
V_49 |= ( V_53 << V_54 ) ;
V_49 &= ~ ( V_55 << V_56 ) ;
V_49 |= V_18 -> V_57 << V_56 ;
V_49 &= ~ ( V_58 << V_59 ) ;
V_49 |= ( V_18 -> V_60 << V_59 ) ;
if ( V_18 -> V_61 ) {
V_49 &= ~ ( V_62 << V_63 ) ;
V_49 |= ( V_18 -> V_61 << V_63 ) ;
}
return V_49 ;
}
static void F_19 ( struct V_43 * V_44 , bool V_64 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
F_4 ( & V_3 -> V_10 ) ;
F_15 ( V_3 -> V_46 ) ;
V_3 -> V_65 ( V_44 , V_64 ) ;
F_17 ( V_3 -> V_46 ) ;
F_7 ( & V_3 -> V_10 ) ;
}
static int F_20 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
const struct V_36 * const V_37 =
F_12 ( V_6 ) ;
int V_45 = 0 , V_66 , V_9 ;
unsigned long V_67 , V_8 ;
unsigned int V_68 ;
if ( ! V_37 ) {
F_2 ( L_3 ,
V_38 ) ;
V_45 = - V_69 ;
goto V_70;
}
V_68 = F_21 ( V_3 -> V_71 + V_72 ) ;
if ( ! V_68 ) {
V_45 = - V_73 ;
goto V_70;
}
F_10 ( V_3 , F_22 ( V_3 -> V_71 + V_74 ) ) ;
V_67 = V_37 [ 0 ] . V_40 / V_41 ;
V_66 = F_8 ( V_3 , V_67 ) ;
if ( V_66 < 0 ) {
V_45 = V_66 ;
goto V_70;
}
F_23 ( V_66 , V_3 -> V_71 + V_75 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
V_8 = V_37 [ V_9 ] . V_40 / V_41 ;
F_23 ( V_8 - V_67 , V_3 -> V_71 +
V_76 + V_9 * 4 ) ;
}
V_3 -> V_77 ( V_3 ) ;
V_70:
return V_45 ;
}
static int F_24 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
const struct V_36 * const V_37 =
F_12 ( V_3 -> V_7 ) ;
unsigned int V_68 , V_28 , V_49 , V_78 , V_79 ;
int V_45 = 0 , V_66 , V_9 ;
unsigned long V_80 = 0 ;
V_68 = F_21 ( V_3 -> V_71 + V_72 ) ;
if ( ! V_68 ) {
V_45 = - V_73 ;
goto V_70;
}
if ( V_3 -> V_50 == V_52 ||
V_3 -> V_50 == V_51 ||
V_3 -> V_50 == V_81 ) {
if ( V_3 -> V_50 == V_52 ) {
V_78 = F_22 ( V_3 -> V_71 + V_82 ) ;
V_78 |= V_83 ;
F_25 ( V_78 , V_3 -> V_71 + V_82 ) ;
}
V_78 = F_22 ( V_3 -> V_71 + V_84 ) ;
V_78 |= V_83 ;
F_25 ( V_78 , V_3 -> V_71 + V_84 ) ;
}
if ( V_3 -> V_50 == V_85 )
V_28 = F_22 ( V_3 -> V_86 + V_74 ) ;
else
V_28 = F_22 ( V_3 -> V_71 + V_74 ) ;
F_10 ( V_3 , V_28 ) ;
V_79 = F_22 ( V_3 -> V_71 + V_87 ) ;
V_79 = F_11 ( V_3 , V_79 , false ) ;
F_25 ( V_79 , V_3 -> V_71 + V_87 ) ;
F_25 ( F_11 ( V_3 , 0 , true ) , V_3 -> V_71 + V_88 ) ;
V_3 -> V_77 ( V_3 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_3 -> V_7 ) ; V_9 ++ ) {
if ( V_37 [ V_9 ] . type == V_39 ) {
V_80 = V_37 [ V_9 ] . V_40 ;
break;
}
}
if ( V_9 == F_5 ( V_3 -> V_7 ) ) {
F_2 ( L_4 ,
V_38 ) ;
V_45 = - V_89 ;
goto V_70;
}
V_66 = F_8 ( V_3 , V_80 / V_41 ) ;
V_79 &= ~ ( 0xff << 8 * V_9 ) ;
V_79 |= V_66 << 8 * V_9 ;
F_25 ( V_79 , V_3 -> V_71 + V_87 ) ;
V_49 = F_22 ( V_3 -> V_71 + V_90 ) ;
V_49 |= ( 1 << V_91 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_90 ) ;
V_70:
return V_45 ;
}
static int F_26 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_68 , V_28 ;
unsigned int V_79 = 0 , V_92 = 0 ;
unsigned long V_8 , V_93 ;
int V_45 = 0 , V_66 , V_9 , V_94 , V_20 ;
V_68 = F_21 ( V_3 -> V_71 + V_72 ) ;
if ( ! V_68 ) {
V_45 = - V_73 ;
goto V_70;
}
V_28 = F_22 ( V_3 -> V_71 + V_74 ) ;
F_10 ( V_3 , V_28 ) ;
V_94 = ( V_28 & V_95 )
>> V_96 ;
F_27 ( & V_44 -> V_97 , L_5 , V_94 ) ;
F_25 ( V_28 , V_3 -> V_71 + V_74 ) ;
V_20 = ( V_28 & V_98 )
>> V_99 ;
switch ( V_20 ) {
case V_100 :
V_18 -> V_20 = V_26 ;
break;
case V_101 :
V_18 -> V_20 = V_21 ;
break;
default:
V_18 -> V_20 = V_26 ;
break;
} ;
F_27 ( & V_44 -> V_97 , L_6 ,
V_20 ? 2 : 1 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 ) ; V_9 ++ ) {
int V_102 , V_103 ;
int V_104 = 0 ;
switch ( V_9 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_102 = V_105 ;
V_103 = V_106 ;
V_104 = V_9 ;
break;
case 4 :
case 5 :
case 6 :
case 7 :
V_102 = V_107 ;
V_103 = V_108 ;
V_104 = V_9 - 4 ;
break;
default:
continue;
}
V_6 -> V_11 -> V_12 ( V_6 , V_9 , & V_8 ) ;
V_8 /= V_41 ;
V_66 = F_8 ( V_3 , V_8 ) ;
V_79 = F_22 ( V_3 -> V_71 + V_102 ) ;
V_79 |= ( V_66 << V_104 * 8 ) ;
F_25 ( V_79 , V_3 -> V_71 + V_102 ) ;
V_6 -> V_11 -> V_109 ( V_6 , V_9 , & V_93 ) ;
V_93 = V_8 - ( V_93 / V_41 ) ;
V_66 = F_8 ( V_3 , V_93 ) ;
V_92 = F_22 ( V_3 -> V_71 + V_103 ) ;
V_92 &= ~ ( 0xff << V_104 * 8 ) ;
V_92 |= ( V_66 << V_104 * 8 ) ;
F_25 ( V_92 , V_3 -> V_71 + V_103 ) ;
}
V_3 -> V_77 ( V_3 ) ;
V_70:
return V_45 ;
}
static int F_28 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
unsigned int V_28 = 0 , V_49 , V_79 ;
int V_45 = 0 , V_66 ;
unsigned long V_80 = 0 ;
switch ( V_3 -> V_110 ) {
case 0 :
V_28 = F_22 ( V_3 -> V_71 + V_111 +
V_112 ) ;
break;
case 1 :
V_28 = F_22 ( V_3 -> V_71 + V_112 ) ;
break;
case 2 :
V_28 = F_22 ( V_3 -> V_71 - V_111 +
V_112 ) ;
}
F_10 ( V_3 , V_28 ) ;
V_79 = F_22 ( V_3 -> V_71 + V_113 ) ;
V_79 = F_11 ( V_3 , V_79 , false ) ;
F_25 ( V_79 , V_3 -> V_71 + V_113 ) ;
F_25 ( 0 , V_3 -> V_71 + V_114 ) ;
V_3 -> V_77 ( V_3 ) ;
if ( ! V_3 -> V_7 -> V_11 -> V_115 ( V_3 -> V_7 , & V_80 ) ) {
V_66 = F_8 ( V_3 , V_80 / V_41 ) ;
V_79 =
V_66 << V_116 ;
F_25 ( V_79 , V_3 -> V_71 + V_117 ) ;
V_49 = F_22 ( V_3 -> V_71 + V_118 ) ;
V_49 |= ( 1 << V_91 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_118 ) ;
}
if ( ! V_3 -> V_110 )
F_25 ( 0 , V_3 -> V_86 + V_119 ) ;
return V_45 ;
}
static int F_29 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_17 * V_18 = V_3 -> V_18 ;
unsigned int V_68 , V_28 ;
unsigned int V_79 = 0 , V_92 = 0 ;
int V_45 = 0 , V_66 , V_9 ;
unsigned long V_8 , V_93 ;
unsigned int V_120 , V_121 ;
V_68 = F_21 ( V_3 -> V_71 + V_72 ) ;
if ( ! V_68 ) {
V_45 = - V_73 ;
goto V_70;
}
V_28 = F_22 ( V_3 -> V_71 + V_74 ) ;
V_3 -> V_24 = V_28 & V_122 ;
if ( ! V_3 -> V_24 ||
( V_18 -> V_31 > V_3 -> V_24 ) ||
( V_3 -> V_24 > V_18 -> V_32 ) )
V_3 -> V_24 = V_18 -> V_33 & V_29 ;
for ( V_9 = ( F_5 ( V_6 ) - 1 ) ; V_9 >= 0 ; V_9 -- ) {
V_120 = ( ( 7 - V_9 ) / 2 ) * 4 ;
V_121 = ( ( 8 - V_9 ) % 2 ) ;
V_6 -> V_11 -> V_12 ( V_6 , V_9 , & V_8 ) ;
V_8 /= V_41 ;
V_6 -> V_11 -> V_109 ( V_6 , V_9 , & V_93 ) ;
V_93 = V_8 - ( V_93 / V_41 ) ;
V_66 = F_8 ( V_3 , V_8 ) ;
V_79 = F_22 ( V_3 -> V_71 +
V_123 + V_120 ) ;
V_79 &= ~ ( V_122 << ( 16 * V_121 ) ) ;
V_79 |= V_66 << ( 16 * V_121 ) ;
F_25 ( V_79 ,
V_3 -> V_71 + V_123 + V_120 ) ;
V_66 = F_8 ( V_3 , V_93 ) ;
V_92 &= ~ ( V_122 << ( 16 * V_121 ) ) ;
V_92 |= V_66 << ( 16 * V_121 ) ;
F_25 ( V_92 ,
V_3 -> V_71 + V_124 + V_120 ) ;
}
V_3 -> V_77 ( V_3 ) ;
V_70:
return V_45 ;
}
static void F_30 ( struct V_43 * V_44 , bool V_64 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_49 , V_125 ;
V_49 = F_18 ( V_3 , F_22 ( V_3 -> V_71 + V_90 ) ) ;
if ( V_64 ) {
V_49 |= ( 1 << V_126 ) ;
V_125 =
( F_31 ( V_6 , 3 )
<< V_127 ) |
( F_31 ( V_6 , 2 )
<< V_128 ) |
( F_31 ( V_6 , 1 )
<< V_129 ) |
( F_31 ( V_6 , 0 )
<< V_130 ) ;
if ( V_3 -> V_50 != V_131 )
V_125 |=
V_125 << V_132 ;
} else {
V_49 &= ~ ( 1 << V_126 ) ;
V_125 = 0 ;
}
F_25 ( V_125 , V_3 -> V_71 + V_133 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_90 ) ;
}
static void F_32 ( struct V_43 * V_44 , bool V_64 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_49 , V_125 , V_134 ;
V_49 = F_18 ( V_3 , F_22 ( V_3 -> V_71 + V_90 ) ) ;
if ( V_64 ) {
V_49 |= ( 1 << V_126 ) ;
V_125 =
( F_31 ( V_6 , 7 )
<< V_135 ) |
( F_31 ( V_6 , 6 )
<< V_136 ) |
( F_31 ( V_6 , 5 )
<< V_137 ) |
( F_31 ( V_6 , 4 )
<< V_138 ) |
( F_31 ( V_6 , 3 )
<< V_139 ) |
( F_31 ( V_6 , 2 )
<< V_140 ) |
( F_31 ( V_6 , 1 )
<< V_141 ) |
( F_31 ( V_6 , 0 )
<< V_142 ) ;
V_125 |=
V_125 << V_132 ;
} else {
V_49 &= ~ ( 1 << V_126 ) ;
V_125 = 0 ;
}
V_134 = V_64 ? V_143 : 0 ;
F_25 ( V_134 , V_3 -> V_71 + V_144 ) ;
F_25 ( V_125 , V_3 -> V_71 + V_145 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_90 ) ;
}
static void F_33 ( struct V_43 * V_44 , bool V_64 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_49 , V_125 ;
V_49 = F_18 ( V_3 , F_22 ( V_3 -> V_71 + V_118 ) ) ;
if ( V_64 ) {
V_49 |= ( 1 << V_126 ) ;
V_125 =
( F_31 ( V_6 , 3 )
<< V_146 ) |
( F_31 ( V_6 , 2 )
<< V_147 ) |
( F_31 ( V_6 , 1 )
<< V_148 ) |
( F_31 ( V_6 , 0 )
<< V_149 ) ;
V_125 |=
V_125 << V_150 ;
} else {
V_49 &= ~ ( 1 << V_126 ) ;
V_125 = 0 ;
}
F_25 ( V_125 , V_3 -> V_71 + V_151 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_118 ) ;
}
static void F_34 ( struct V_43 * V_44 , bool V_64 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_49 , V_125 ;
V_49 = F_18 ( V_3 , F_22 ( V_3 -> V_71 + V_90 ) ) ;
if ( V_64 ) {
V_49 |= ( 1 << V_126 ) ;
V_49 |= ( 1 << V_152 ) ;
V_125 =
( F_31 ( V_6 , 7 )
<< V_135 ) |
( F_31 ( V_6 , 6 )
<< V_136 ) |
( F_31 ( V_6 , 5 )
<< V_137 ) |
( F_31 ( V_6 , 4 )
<< V_138 ) |
( F_31 ( V_6 , 3 )
<< V_139 ) |
( F_31 ( V_6 , 2 )
<< V_140 ) |
( F_31 ( V_6 , 1 )
<< V_141 ) |
( F_31 ( V_6 , 0 )
<< V_142 ) ;
V_125 |=
V_125 << V_132 ;
} else {
V_49 &= ~ ( 1 << V_126 ) ;
V_49 &= ~ ( 1 << V_152 ) ;
V_125 = 0 ;
}
F_25 ( V_125 , V_3 -> V_71 + V_153 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_90 ) ;
}
static int F_35 ( void * V_2 , long * V_8 )
{
struct V_1 * V_3 = V_2 ;
if ( ! V_3 || ! V_3 -> V_154 )
return - V_89 ;
F_4 ( & V_3 -> V_10 ) ;
F_15 ( V_3 -> V_46 ) ;
* V_8 = F_9 ( V_3 , V_3 -> V_154 ( V_3 ) ) * V_41 ;
F_17 ( V_3 -> V_46 ) ;
F_7 ( & V_3 -> V_10 ) ;
return 0 ;
}
static T_3 F_36 ( struct V_1 * V_3 , unsigned int V_155 ,
unsigned long V_8 )
{
if ( V_8 ) {
V_8 /= V_41 ;
if ( V_3 -> V_50 != V_156 ) {
V_155 &= ~ ( V_157 << V_158 ) ;
V_155 |= ( V_159 << V_158 ) ;
}
if ( V_3 -> V_50 == V_160 ) {
V_155 &= ~ ( V_161 <<
V_162 ) ;
V_155 |= ( F_8 ( V_3 , V_8 ) <<
V_162 ) |
V_163 ;
} else {
V_155 &= ~ ( V_164 <<
V_165 ) ;
V_155 |= ( F_8 ( V_3 , V_8 ) <<
V_165 ) |
V_163 ;
}
} else {
V_155 &= ~ V_163 ;
}
return V_155 ;
}
static void F_37 ( struct V_1 * V_3 ,
unsigned long V_8 )
{
unsigned int V_155 ;
T_3 V_166 ;
if ( V_3 -> V_50 == V_167 )
V_166 = V_168 ;
if ( V_3 -> V_50 == V_169 )
V_166 = V_170 ;
else if ( V_3 -> V_50 == V_160 )
V_166 = V_171 ;
else
V_166 = V_172 ;
V_155 = F_22 ( V_3 -> V_71 + V_166 ) ;
V_155 = F_36 ( V_3 , V_155 , V_8 ) ;
F_25 ( V_155 , V_3 -> V_71 + V_166 ) ;
}
static void F_38 ( struct V_1 * V_3 ,
unsigned long V_8 )
{
unsigned int V_155 ;
V_155 = F_22 ( V_3 -> V_71 + V_173 ) ;
V_155 = F_36 ( V_3 , V_155 , V_8 ) ;
F_25 ( V_155 , V_3 -> V_71 + V_173 ) ;
}
static int F_39 ( void * V_174 , unsigned long V_8 )
{
struct V_1 * V_3 = V_174 ;
int V_45 = - V_89 ;
if ( V_3 -> V_50 == V_131 )
goto V_70;
if ( V_8 && V_8 < V_41 )
goto V_70;
F_4 ( & V_3 -> V_10 ) ;
F_15 ( V_3 -> V_46 ) ;
V_3 -> V_175 ( V_3 , V_8 ) ;
F_17 ( V_3 -> V_46 ) ;
F_7 ( & V_3 -> V_10 ) ;
return 0 ;
V_70:
return V_45 ;
}
static int F_39 ( void * V_174 , unsigned long V_8 )
{ return - V_89 ; }
static int F_40 ( struct V_1 * V_3 )
{
int V_45 = F_21 ( V_3 -> V_71 + V_176 ) ;
return ( V_45 < 75 || V_45 > 175 ) ? - V_177 : V_45 ;
}
static int F_41 ( struct V_1 * V_3 )
{
return F_21 ( V_3 -> V_71 + V_176 ) ;
}
static int F_42 ( struct V_1 * V_3 )
{
return F_21 ( V_3 -> V_71 + V_178 ) ;
}
static int F_43 ( struct V_1 * V_3 )
{
return F_44 ( V_3 -> V_71 + V_176 ) &
V_122 ;
}
static void F_45 ( struct V_179 * V_180 )
{
struct V_1 * V_3 = F_46 ( V_180 ,
struct V_1 , V_181 ) ;
unsigned int V_182 ;
if ( ! F_16 ( V_3 -> V_47 ) )
F_15 ( V_3 -> V_47 ) ;
if ( V_3 -> V_50 == V_156 ) {
V_182 = F_22 ( V_3 -> V_86 + V_183 ) ;
if ( ! ( ( V_182 >> V_3 -> V_110 ) & 0x1 ) )
goto V_70;
}
if ( ! F_16 ( V_3 -> V_47 ) )
F_17 ( V_3 -> V_47 ) ;
F_1 ( V_3 ) ;
F_4 ( & V_3 -> V_10 ) ;
F_15 ( V_3 -> V_46 ) ;
V_3 -> V_77 ( V_3 ) ;
F_17 ( V_3 -> V_46 ) ;
F_7 ( & V_3 -> V_10 ) ;
V_70:
F_47 ( V_3 -> V_184 ) ;
}
static void F_48 ( struct V_1 * V_3 )
{
unsigned int V_185 ;
T_3 V_186 , V_187 ;
if ( V_3 -> V_50 == V_167 ) {
V_186 = V_188 ;
V_187 = V_189 ;
} else if ( V_3 -> V_50 == V_160 ) {
V_186 = V_190 ;
V_187 = V_190 ;
} else if ( V_3 -> V_50 == V_169 ) {
V_186 = V_191 ;
V_187 = V_191 ;
} else {
V_186 = V_192 ;
V_187 = V_193 ;
}
V_185 = F_22 ( V_3 -> V_71 + V_186 ) ;
F_25 ( V_185 , V_3 -> V_71 + V_187 ) ;
}
static void F_49 ( struct V_1 * V_3 )
{
unsigned int V_185 ;
V_185 = F_22 ( V_3 -> V_71 + V_194 ) ;
F_25 ( V_185 , V_3 -> V_71 + V_194 ) ;
}
static T_4 F_50 ( int V_184 , void * V_110 )
{
struct V_1 * V_3 = V_110 ;
F_51 ( V_184 ) ;
F_52 ( & V_3 -> V_181 ) ;
return V_195 ;
}
static int F_53 ( struct V_196 * V_197 )
{
if ( F_54 ( V_197 , L_7 ) )
return V_52 ;
else if ( F_54 ( V_197 , L_8 ) )
return V_131 ;
else if ( F_54 ( V_197 , L_9 ) )
return V_51 ;
else if ( F_54 ( V_197 , L_10 ) )
return V_81 ;
else if ( F_54 ( V_197 , L_11 ) )
return V_167 ;
else if ( F_54 ( V_197 , L_12 ) )
return V_198 ;
else if ( F_54 ( V_197 ,
L_13 ) )
return V_85 ;
else if ( F_54 ( V_197 , L_14 ) )
return V_169 ;
else if ( F_54 ( V_197 , L_15 ) )
return V_156 ;
else if ( F_54 ( V_197 , L_16 ) )
return V_160 ;
return - V_89 ;
}
static int F_55 ( struct V_196 * V_197 ,
struct V_17 * V_18 )
{
T_3 V_199 ;
int V_45 ;
F_56 ( V_197 ) ;
V_45 = F_57 ( V_197 , L_17 , & V_199 ) ;
V_18 -> V_60 = ( T_1 ) V_199 ;
F_57 ( V_197 , L_18 , & V_199 ) ;
V_18 -> V_57 = ( T_1 ) V_199 ;
F_57 ( V_197 , L_19 , & V_199 ) ;
V_18 -> V_61 = ( T_1 ) V_199 ;
F_57 ( V_197 , L_20 ,
& V_18 -> V_33 ) ;
F_57 ( V_197 , L_21 ,
& V_18 -> V_31 ) ;
F_57 ( V_197 , L_22 ,
& V_18 -> V_32 ) ;
F_57 ( V_197 , L_23 , & V_199 ) ;
V_18 -> V_22 = ( T_1 ) V_199 ;
F_57 ( V_197 , L_24 , & V_199 ) ;
V_18 -> V_25 = ( T_1 ) V_199 ;
F_57 ( V_197 , L_25 , & V_199 ) ;
V_18 -> V_27 = ( T_1 ) V_199 ;
F_57 ( V_197 , L_26 , & V_18 -> V_20 ) ;
F_57 ( V_197 , L_27 , & V_18 -> V_200 ) ;
F_58 ( V_197 ) ;
return 0 ;
}
static int F_59 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_17 * V_18 ;
struct V_201 V_202 ;
int V_45 ;
if ( ! V_3 || ! V_44 -> V_97 . V_203 )
return - V_69 ;
V_3 -> V_204 = F_60 ( & V_44 -> V_97 , L_28 ) ;
if ( ! F_16 ( V_3 -> V_204 ) ) {
V_45 = F_61 ( V_3 -> V_204 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_97 , L_29 ) ;
return V_45 ;
}
} else {
F_27 ( & V_44 -> V_97 , L_30 ) ;
}
V_3 -> V_110 = F_63 ( V_44 -> V_97 . V_203 , L_31 ) ;
if ( V_3 -> V_110 < 0 )
V_3 -> V_110 = 0 ;
V_3 -> V_184 = F_64 ( V_44 -> V_97 . V_203 , 0 ) ;
if ( V_3 -> V_184 <= 0 ) {
F_62 ( & V_44 -> V_97 , L_32 ) ;
return - V_69 ;
}
if ( F_65 ( V_44 -> V_97 . V_203 , 0 , & V_202 ) ) {
F_62 ( & V_44 -> V_97 , L_33 ) ;
return - V_69 ;
}
V_3 -> V_71 = F_66 ( & V_44 -> V_97 , V_202 . V_205 , F_67 ( & V_202 ) ) ;
if ( ! V_3 -> V_71 ) {
F_62 ( & V_44 -> V_97 , L_34 ) ;
return - V_206 ;
}
V_18 = F_68 ( & V_44 -> V_97 ,
sizeof( struct V_17 ) ,
V_207 ) ;
if ( ! V_18 )
return - V_208 ;
F_55 ( V_44 -> V_97 . V_203 , V_18 ) ;
V_3 -> V_18 = V_18 ;
V_3 -> V_50 = F_53 ( V_44 -> V_97 . V_203 ) ;
switch ( V_3 -> V_50 ) {
case V_131 :
V_3 -> V_48 = F_20 ;
V_3 -> V_65 = F_30 ;
V_3 -> V_154 = F_40 ;
V_3 -> V_77 = F_48 ;
break;
case V_52 :
case V_51 :
case V_81 :
case V_167 :
case V_198 :
case V_85 :
V_3 -> V_48 = F_24 ;
V_3 -> V_65 = F_30 ;
V_3 -> V_154 = F_41 ;
V_3 -> V_175 = F_37 ;
V_3 -> V_77 = F_48 ;
break;
case V_169 :
V_3 -> V_48 = F_26 ;
V_3 -> V_65 = F_32 ;
V_3 -> V_154 = F_41 ;
V_3 -> V_175 = F_37 ;
V_3 -> V_77 = F_48 ;
break;
case V_156 :
V_3 -> V_48 = F_28 ;
V_3 -> V_65 = F_33 ;
V_3 -> V_154 = F_42 ;
V_3 -> V_175 = F_38 ;
V_3 -> V_77 = F_49 ;
break;
case V_160 :
V_3 -> V_48 = F_29 ;
V_3 -> V_65 = F_34 ;
V_3 -> V_154 = F_43 ;
V_3 -> V_175 = F_37 ;
V_3 -> V_77 = F_48 ;
break;
default:
F_62 ( & V_44 -> V_97 , L_35 ) ;
return - V_89 ;
}
if ( V_3 -> V_50 != V_85 &&
V_3 -> V_50 != V_156 )
return 0 ;
if ( F_65 ( V_44 -> V_97 . V_203 , 1 , & V_202 ) ) {
F_62 ( & V_44 -> V_97 , L_36 ) ;
return - V_69 ;
}
V_3 -> V_86 = F_66 ( & V_44 -> V_97 , V_202 . V_205 ,
F_67 ( & V_202 ) ) ;
if ( ! V_3 -> V_86 ) {
F_62 ( & V_44 -> V_97 , L_34 ) ;
return - V_208 ;
}
return 0 ;
}
static int F_69 ( struct V_43 * V_44 )
{
struct V_1 * V_3 ;
int V_45 ;
V_3 = F_68 ( & V_44 -> V_97 , sizeof( struct V_1 ) ,
V_207 ) ;
if ( ! V_3 )
return - V_208 ;
F_70 ( V_44 , V_3 ) ;
F_71 ( & V_3 -> V_10 ) ;
V_3 -> V_7 = F_72 ( & V_44 -> V_97 , 0 , V_3 ,
& V_209 ) ;
if ( F_16 ( V_3 -> V_7 ) ) {
F_2 ( L_37 , V_3 -> V_7 ) ;
return F_73 ( V_3 -> V_7 ) ;
}
V_45 = F_59 ( V_44 ) ;
if ( V_45 )
goto V_210;
F_74 ( & V_3 -> V_181 , F_45 ) ;
V_3 -> V_46 = F_75 ( & V_44 -> V_97 , L_38 ) ;
if ( F_16 ( V_3 -> V_46 ) ) {
F_62 ( & V_44 -> V_97 , L_39 ) ;
V_45 = F_73 ( V_3 -> V_46 ) ;
goto V_210;
}
V_3 -> V_47 = F_75 ( & V_44 -> V_97 , L_40 ) ;
if ( F_16 ( V_3 -> V_47 ) ) {
if ( V_3 -> V_50 == V_85 ) {
F_62 ( & V_44 -> V_97 , L_41 ) ;
V_45 = F_73 ( V_3 -> V_47 ) ;
goto V_210;
}
} else {
V_45 = F_76 ( V_3 -> V_47 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_97 , L_39 ) ;
goto V_210;
}
}
V_45 = F_76 ( V_3 -> V_46 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_97 , L_39 ) ;
goto V_211;
}
switch ( V_3 -> V_50 ) {
case V_169 :
case V_160 :
V_3 -> V_212 = F_75 ( & V_44 -> V_97 , L_42 ) ;
if ( F_16 ( V_3 -> V_212 ) ) {
F_62 ( & V_44 -> V_97 , L_43 ) ;
goto V_213;
} else {
V_45 = F_77 ( V_3 -> V_212 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_97 , L_44 ) ;
goto V_213;
}
}
break;
default:
break;
} ;
V_45 = F_13 ( V_44 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_97 , L_45 ) ;
goto V_214;
}
V_45 = F_78 ( & V_44 -> V_97 , V_3 -> V_184 , F_50 ,
V_215 | V_216 , F_79 ( & V_44 -> V_97 ) , V_3 ) ;
if ( V_45 ) {
F_62 ( & V_44 -> V_97 , L_46 , V_3 -> V_184 ) ;
goto V_214;
}
F_19 ( V_44 , true ) ;
return 0 ;
V_214:
F_80 ( V_3 -> V_212 ) ;
V_213:
F_81 ( V_3 -> V_46 ) ;
V_211:
if ( ! F_16 ( V_3 -> V_47 ) )
F_81 ( V_3 -> V_47 ) ;
V_210:
if ( ! F_82 ( V_3 -> V_204 ) )
F_83 ( V_3 -> V_204 ) ;
F_84 ( & V_44 -> V_97 , V_3 -> V_7 ) ;
return V_45 ;
}
static int F_85 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_7 = V_3 -> V_7 ;
F_84 ( & V_44 -> V_97 , V_7 ) ;
F_19 ( V_44 , false ) ;
F_80 ( V_3 -> V_212 ) ;
F_81 ( V_3 -> V_46 ) ;
if ( ! F_16 ( V_3 -> V_47 ) )
F_81 ( V_3 -> V_47 ) ;
if ( ! F_16 ( V_3 -> V_204 ) )
F_83 ( V_3 -> V_204 ) ;
return 0 ;
}
static int F_86 ( struct V_14 * V_97 )
{
F_19 ( F_87 ( V_97 ) , false ) ;
return 0 ;
}
static int F_88 ( struct V_14 * V_97 )
{
struct V_43 * V_44 = F_87 ( V_97 ) ;
F_13 ( V_44 ) ;
F_19 ( V_44 , true ) ;
return 0 ;
}
