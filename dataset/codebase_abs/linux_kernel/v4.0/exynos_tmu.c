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
unsigned int V_28 = 0 , V_49 , V_79 ;
int V_45 = 0 , V_66 ;
unsigned long V_80 = 0 ;
switch ( V_3 -> V_92 ) {
case 0 :
V_28 = F_22 ( V_3 -> V_71 + V_93 +
V_94 ) ;
break;
case 1 :
V_28 = F_22 ( V_3 -> V_71 + V_94 ) ;
break;
case 2 :
V_28 = F_22 ( V_3 -> V_71 - V_93 +
V_94 ) ;
}
F_10 ( V_3 , V_28 ) ;
V_79 = F_22 ( V_3 -> V_71 + V_95 ) ;
V_79 = F_11 ( V_3 , V_79 , false ) ;
F_25 ( V_79 , V_3 -> V_71 + V_95 ) ;
F_25 ( 0 , V_3 -> V_71 + V_96 ) ;
V_3 -> V_77 ( V_3 ) ;
if ( ! V_3 -> V_7 -> V_11 -> V_97 ( V_3 -> V_7 , & V_80 ) ) {
V_66 = F_8 ( V_3 , V_80 / V_41 ) ;
V_79 =
V_66 << V_98 ;
F_25 ( V_79 , V_3 -> V_71 + V_99 ) ;
V_49 = F_22 ( V_3 -> V_71 + V_100 ) ;
V_49 |= ( 1 << V_91 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_100 ) ;
}
if ( ! V_3 -> V_92 )
F_25 ( 0 , V_3 -> V_86 + V_101 ) ;
return V_45 ;
}
static int F_27 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_17 * V_18 = V_3 -> V_18 ;
unsigned int V_68 , V_28 ;
unsigned int V_79 = 0 , V_102 = 0 ;
int V_45 = 0 , V_66 , V_9 ;
unsigned long V_8 , V_103 ;
unsigned int V_104 , V_105 ;
V_68 = F_21 ( V_3 -> V_71 + V_72 ) ;
if ( ! V_68 ) {
V_45 = - V_73 ;
goto V_70;
}
V_28 = F_22 ( V_3 -> V_71 + V_74 ) ;
V_3 -> V_24 = V_28 & V_106 ;
if ( ! V_3 -> V_24 ||
( V_18 -> V_31 > V_3 -> V_24 ) ||
( V_3 -> V_24 > V_18 -> V_32 ) )
V_3 -> V_24 = V_18 -> V_33 & V_29 ;
for ( V_9 = ( F_5 ( V_6 ) - 1 ) ; V_9 >= 0 ; V_9 -- ) {
V_104 = ( ( 7 - V_9 ) / 2 ) * 4 ;
V_105 = ( ( 8 - V_9 ) % 2 ) ;
V_6 -> V_11 -> V_12 ( V_6 , V_9 , & V_8 ) ;
V_8 /= V_41 ;
V_6 -> V_11 -> V_107 ( V_6 , V_9 , & V_103 ) ;
V_103 = V_8 - ( V_103 / V_41 ) ;
V_66 = F_8 ( V_3 , V_8 ) ;
V_79 = F_22 ( V_3 -> V_71 +
V_108 + V_104 ) ;
V_79 &= ~ ( V_106 << ( 16 * V_105 ) ) ;
V_79 |= V_66 << ( 16 * V_105 ) ;
F_25 ( V_79 ,
V_3 -> V_71 + V_108 + V_104 ) ;
V_66 = F_8 ( V_3 , V_103 ) ;
V_102 &= ~ ( V_106 << ( 16 * V_105 ) ) ;
V_102 |= V_66 << ( 16 * V_105 ) ;
F_25 ( V_102 ,
V_3 -> V_71 + V_109 + V_104 ) ;
}
V_3 -> V_77 ( V_3 ) ;
V_70:
return V_45 ;
}
static void F_28 ( struct V_43 * V_44 , bool V_64 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_49 , V_110 ;
V_49 = F_18 ( V_3 , F_22 ( V_3 -> V_71 + V_90 ) ) ;
if ( V_64 ) {
V_49 |= ( 1 << V_111 ) ;
V_110 =
( F_29 ( V_6 , 3 )
<< V_112 ) |
( F_29 ( V_6 , 2 )
<< V_113 ) |
( F_29 ( V_6 , 1 )
<< V_114 ) |
( F_29 ( V_6 , 0 )
<< V_115 ) ;
if ( V_3 -> V_50 != V_116 )
V_110 |=
V_110 << V_117 ;
} else {
V_49 &= ~ ( 1 << V_111 ) ;
V_110 = 0 ;
}
F_25 ( V_110 , V_3 -> V_71 + V_118 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_90 ) ;
}
static void F_30 ( struct V_43 * V_44 , bool V_64 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_49 , V_110 ;
V_49 = F_18 ( V_3 , F_22 ( V_3 -> V_71 + V_100 ) ) ;
if ( V_64 ) {
V_49 |= ( 1 << V_111 ) ;
V_110 =
( F_29 ( V_6 , 3 )
<< V_119 ) |
( F_29 ( V_6 , 2 )
<< V_120 ) |
( F_29 ( V_6 , 1 )
<< V_121 ) |
( F_29 ( V_6 , 0 )
<< V_122 ) ;
V_110 |=
V_110 << V_123 ;
} else {
V_49 &= ~ ( 1 << V_111 ) ;
V_110 = 0 ;
}
F_25 ( V_110 , V_3 -> V_71 + V_124 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_100 ) ;
}
static void F_31 ( struct V_43 * V_44 , bool V_64 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_6 = V_3 -> V_7 ;
unsigned int V_49 , V_110 ;
V_49 = F_18 ( V_3 , F_22 ( V_3 -> V_71 + V_90 ) ) ;
if ( V_64 ) {
V_49 |= ( 1 << V_111 ) ;
V_49 |= ( 1 << V_125 ) ;
V_110 =
( F_29 ( V_6 , 7 )
<< V_126 ) |
( F_29 ( V_6 , 6 )
<< V_127 ) |
( F_29 ( V_6 , 5 )
<< V_128 ) |
( F_29 ( V_6 , 4 )
<< V_129 ) |
( F_29 ( V_6 , 3 )
<< V_130 ) |
( F_29 ( V_6 , 2 )
<< V_131 ) |
( F_29 ( V_6 , 1 )
<< V_132 ) |
( F_29 ( V_6 , 0 )
<< V_133 ) ;
V_110 |=
V_110 << V_117 ;
} else {
V_49 &= ~ ( 1 << V_111 ) ;
V_49 &= ~ ( 1 << V_125 ) ;
V_110 = 0 ;
}
F_25 ( V_110 , V_3 -> V_71 + V_134 ) ;
F_25 ( V_49 , V_3 -> V_71 + V_90 ) ;
}
static int F_32 ( void * V_2 , long * V_8 )
{
struct V_1 * V_3 = V_2 ;
if ( ! V_3 || ! V_3 -> V_135 )
return - V_89 ;
F_4 ( & V_3 -> V_10 ) ;
F_15 ( V_3 -> V_46 ) ;
* V_8 = F_9 ( V_3 , V_3 -> V_135 ( V_3 ) ) * V_41 ;
F_17 ( V_3 -> V_46 ) ;
F_7 ( & V_3 -> V_10 ) ;
return 0 ;
}
static T_3 F_33 ( struct V_1 * V_3 , unsigned int V_136 ,
unsigned long V_8 )
{
if ( V_8 ) {
V_8 /= V_41 ;
if ( V_3 -> V_50 != V_137 ) {
V_136 &= ~ ( V_138 << V_139 ) ;
V_136 |= ( V_140 << V_139 ) ;
}
if ( V_3 -> V_50 == V_141 ) {
V_136 &= ~ ( V_142 <<
V_143 ) ;
V_136 |= ( F_8 ( V_3 , V_8 ) <<
V_143 ) |
V_144 ;
} else {
V_136 &= ~ ( V_145 <<
V_146 ) ;
V_136 |= ( F_8 ( V_3 , V_8 ) <<
V_146 ) |
V_144 ;
}
} else {
V_136 &= ~ V_144 ;
}
return V_136 ;
}
static void F_34 ( struct V_1 * V_3 ,
unsigned long V_8 )
{
unsigned int V_136 ;
T_3 V_147 ;
if ( V_3 -> V_50 == V_148 )
V_147 = V_149 ;
else if ( V_3 -> V_50 == V_141 )
V_147 = V_150 ;
else
V_147 = V_151 ;
V_136 = F_22 ( V_3 -> V_71 + V_147 ) ;
V_136 = F_33 ( V_3 , V_136 , V_8 ) ;
F_25 ( V_136 , V_3 -> V_71 + V_147 ) ;
}
static void F_35 ( struct V_1 * V_3 ,
unsigned long V_8 )
{
unsigned int V_136 ;
V_136 = F_22 ( V_3 -> V_71 + V_152 ) ;
V_136 = F_33 ( V_3 , V_136 , V_8 ) ;
F_25 ( V_136 , V_3 -> V_71 + V_152 ) ;
}
static int F_36 ( void * V_153 , unsigned long V_8 )
{
struct V_1 * V_3 = V_153 ;
int V_45 = - V_89 ;
if ( V_3 -> V_50 == V_116 )
goto V_70;
if ( V_8 && V_8 < V_41 )
goto V_70;
F_4 ( & V_3 -> V_10 ) ;
F_15 ( V_3 -> V_46 ) ;
V_3 -> V_154 ( V_3 , V_8 ) ;
F_17 ( V_3 -> V_46 ) ;
F_7 ( & V_3 -> V_10 ) ;
return 0 ;
V_70:
return V_45 ;
}
static int F_36 ( void * V_153 , unsigned long V_8 )
{ return - V_89 ; }
static int F_37 ( struct V_1 * V_3 )
{
int V_45 = F_21 ( V_3 -> V_71 + V_155 ) ;
return ( V_45 < 75 || V_45 > 175 ) ? - V_156 : V_45 ;
}
static int F_38 ( struct V_1 * V_3 )
{
return F_21 ( V_3 -> V_71 + V_155 ) ;
}
static int F_39 ( struct V_1 * V_3 )
{
return F_21 ( V_3 -> V_71 + V_157 ) ;
}
static int F_40 ( struct V_1 * V_3 )
{
return F_41 ( V_3 -> V_71 + V_155 ) &
V_106 ;
}
static void F_42 ( struct V_158 * V_159 )
{
struct V_1 * V_3 = F_43 ( V_159 ,
struct V_1 , V_160 ) ;
unsigned int V_161 ;
if ( ! F_16 ( V_3 -> V_47 ) )
F_15 ( V_3 -> V_47 ) ;
if ( V_3 -> V_50 == V_137 ) {
V_161 = F_22 ( V_3 -> V_86 + V_162 ) ;
if ( ! ( ( V_161 >> V_3 -> V_92 ) & 0x1 ) )
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
F_44 ( V_3 -> V_163 ) ;
}
static void F_45 ( struct V_1 * V_3 )
{
unsigned int V_164 ;
T_3 V_165 , V_166 ;
if ( V_3 -> V_50 == V_148 ) {
V_165 = V_167 ;
V_166 = V_168 ;
} else if ( V_3 -> V_50 == V_141 ) {
V_165 = V_169 ;
V_166 = V_169 ;
} else {
V_165 = V_170 ;
V_166 = V_171 ;
}
V_164 = F_22 ( V_3 -> V_71 + V_165 ) ;
F_25 ( V_164 , V_3 -> V_71 + V_166 ) ;
}
static void F_46 ( struct V_1 * V_3 )
{
unsigned int V_164 ;
V_164 = F_22 ( V_3 -> V_71 + V_172 ) ;
F_25 ( V_164 , V_3 -> V_71 + V_172 ) ;
}
static T_4 F_47 ( int V_163 , void * V_92 )
{
struct V_1 * V_3 = V_92 ;
F_48 ( V_163 ) ;
F_49 ( & V_3 -> V_160 ) ;
return V_173 ;
}
static int F_50 ( struct V_174 * V_175 )
{
if ( F_51 ( V_175 , L_5 ) )
return V_52 ;
else if ( F_51 ( V_175 , L_6 ) )
return V_116 ;
else if ( F_51 ( V_175 , L_7 ) )
return V_51 ;
else if ( F_51 ( V_175 , L_8 ) )
return V_81 ;
else if ( F_51 ( V_175 , L_9 ) )
return V_148 ;
else if ( F_51 ( V_175 , L_10 ) )
return V_176 ;
else if ( F_51 ( V_175 ,
L_11 ) )
return V_85 ;
else if ( F_51 ( V_175 , L_12 ) )
return V_137 ;
else if ( F_51 ( V_175 , L_13 ) )
return V_141 ;
return - V_89 ;
}
static int F_52 ( struct V_174 * V_175 ,
struct V_17 * V_18 )
{
T_3 V_177 ;
int V_45 ;
F_53 ( V_175 ) ;
V_45 = F_54 ( V_175 , L_14 , & V_177 ) ;
V_18 -> V_60 = ( T_1 ) V_177 ;
F_54 ( V_175 , L_15 , & V_177 ) ;
V_18 -> V_57 = ( T_1 ) V_177 ;
F_54 ( V_175 , L_16 , & V_177 ) ;
V_18 -> V_61 = ( T_1 ) V_177 ;
F_54 ( V_175 , L_17 ,
& V_18 -> V_33 ) ;
F_54 ( V_175 , L_18 ,
& V_18 -> V_31 ) ;
F_54 ( V_175 , L_19 ,
& V_18 -> V_32 ) ;
F_54 ( V_175 , L_20 , & V_177 ) ;
V_18 -> V_22 = ( T_1 ) V_177 ;
F_54 ( V_175 , L_21 , & V_177 ) ;
V_18 -> V_25 = ( T_1 ) V_177 ;
F_54 ( V_175 , L_22 , & V_177 ) ;
V_18 -> V_27 = ( T_1 ) V_177 ;
F_54 ( V_175 , L_23 , & V_18 -> V_20 ) ;
F_54 ( V_175 , L_24 , & V_18 -> V_178 ) ;
F_55 ( V_175 ) ;
return 0 ;
}
static int F_56 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_17 * V_18 ;
struct V_179 V_180 ;
int V_45 ;
if ( ! V_3 || ! V_44 -> V_181 . V_182 )
return - V_69 ;
V_3 -> V_183 = F_57 ( & V_44 -> V_181 , L_25 ) ;
if ( ! F_16 ( V_3 -> V_183 ) ) {
V_45 = F_58 ( V_3 -> V_183 ) ;
if ( V_45 ) {
F_59 ( & V_44 -> V_181 , L_26 ) ;
return V_45 ;
}
} else {
F_60 ( & V_44 -> V_181 , L_27 ) ;
}
V_3 -> V_92 = F_61 ( V_44 -> V_181 . V_182 , L_28 ) ;
if ( V_3 -> V_92 < 0 )
V_3 -> V_92 = 0 ;
V_3 -> V_163 = F_62 ( V_44 -> V_181 . V_182 , 0 ) ;
if ( V_3 -> V_163 <= 0 ) {
F_59 ( & V_44 -> V_181 , L_29 ) ;
return - V_69 ;
}
if ( F_63 ( V_44 -> V_181 . V_182 , 0 , & V_180 ) ) {
F_59 ( & V_44 -> V_181 , L_30 ) ;
return - V_69 ;
}
V_3 -> V_71 = F_64 ( & V_44 -> V_181 , V_180 . V_184 , F_65 ( & V_180 ) ) ;
if ( ! V_3 -> V_71 ) {
F_59 ( & V_44 -> V_181 , L_31 ) ;
return - V_185 ;
}
V_18 = F_66 ( & V_44 -> V_181 ,
sizeof( struct V_17 ) ,
V_186 ) ;
if ( ! V_18 )
return - V_187 ;
F_52 ( V_44 -> V_181 . V_182 , V_18 ) ;
V_3 -> V_18 = V_18 ;
V_3 -> V_50 = F_50 ( V_44 -> V_181 . V_182 ) ;
switch ( V_3 -> V_50 ) {
case V_116 :
V_3 -> V_48 = F_20 ;
V_3 -> V_65 = F_28 ;
V_3 -> V_135 = F_37 ;
V_3 -> V_77 = F_45 ;
break;
case V_52 :
case V_51 :
case V_81 :
case V_148 :
case V_176 :
case V_85 :
V_3 -> V_48 = F_24 ;
V_3 -> V_65 = F_28 ;
V_3 -> V_135 = F_38 ;
V_3 -> V_154 = F_34 ;
V_3 -> V_77 = F_45 ;
break;
case V_137 :
V_3 -> V_48 = F_26 ;
V_3 -> V_65 = F_30 ;
V_3 -> V_135 = F_39 ;
V_3 -> V_154 = F_35 ;
V_3 -> V_77 = F_46 ;
break;
case V_141 :
V_3 -> V_48 = F_27 ;
V_3 -> V_65 = F_31 ;
V_3 -> V_135 = F_40 ;
V_3 -> V_154 = F_34 ;
V_3 -> V_77 = F_45 ;
break;
default:
F_59 ( & V_44 -> V_181 , L_32 ) ;
return - V_89 ;
}
if ( V_3 -> V_50 != V_85 &&
V_3 -> V_50 != V_137 )
return 0 ;
if ( F_63 ( V_44 -> V_181 . V_182 , 1 , & V_180 ) ) {
F_59 ( & V_44 -> V_181 , L_33 ) ;
return - V_69 ;
}
V_3 -> V_86 = F_64 ( & V_44 -> V_181 , V_180 . V_184 ,
F_65 ( & V_180 ) ) ;
if ( ! V_3 -> V_86 ) {
F_59 ( & V_44 -> V_181 , L_31 ) ;
return - V_187 ;
}
return 0 ;
}
static int F_67 ( struct V_43 * V_44 )
{
struct V_17 * V_18 ;
struct V_1 * V_3 ;
int V_45 ;
V_3 = F_66 ( & V_44 -> V_181 , sizeof( struct V_1 ) ,
V_186 ) ;
if ( ! V_3 )
return - V_187 ;
F_68 ( V_44 , V_3 ) ;
F_69 ( & V_3 -> V_10 ) ;
V_3 -> V_7 = F_70 ( & V_44 -> V_181 , 0 , V_3 ,
& V_188 ) ;
if ( F_16 ( V_3 -> V_7 ) ) {
F_2 ( L_34 , V_3 -> V_7 ) ;
return F_71 ( V_3 -> V_7 ) ;
}
V_45 = F_56 ( V_44 ) ;
if ( V_45 )
goto V_189;
V_18 = V_3 -> V_18 ;
F_72 ( & V_3 -> V_160 , F_42 ) ;
V_3 -> V_46 = F_73 ( & V_44 -> V_181 , L_35 ) ;
if ( F_16 ( V_3 -> V_46 ) ) {
F_59 ( & V_44 -> V_181 , L_36 ) ;
V_45 = F_71 ( V_3 -> V_46 ) ;
goto V_189;
}
V_3 -> V_47 = F_73 ( & V_44 -> V_181 , L_37 ) ;
if ( F_16 ( V_3 -> V_47 ) ) {
if ( V_3 -> V_50 == V_85 ) {
F_59 ( & V_44 -> V_181 , L_38 ) ;
V_45 = F_71 ( V_3 -> V_47 ) ;
goto V_189;
}
} else {
V_45 = F_74 ( V_3 -> V_47 ) ;
if ( V_45 ) {
F_59 ( & V_44 -> V_181 , L_36 ) ;
goto V_189;
}
}
V_45 = F_74 ( V_3 -> V_46 ) ;
if ( V_45 ) {
F_59 ( & V_44 -> V_181 , L_36 ) ;
goto V_190;
}
if ( V_3 -> V_50 == V_141 ) {
V_3 -> V_191 = F_73 ( & V_44 -> V_181 , L_39 ) ;
if ( F_16 ( V_3 -> V_191 ) ) {
F_59 ( & V_44 -> V_181 , L_40 ) ;
goto V_192;
} else {
V_45 = F_75 ( V_3 -> V_191 ) ;
if ( V_45 ) {
F_59 ( & V_44 -> V_181 , L_41 ) ;
goto V_192;
}
}
}
V_45 = F_13 ( V_44 ) ;
if ( V_45 ) {
F_59 ( & V_44 -> V_181 , L_42 ) ;
goto V_193;
}
V_45 = F_76 ( & V_44 -> V_181 , V_3 -> V_163 , F_47 ,
V_194 | V_195 , F_77 ( & V_44 -> V_181 ) , V_3 ) ;
if ( V_45 ) {
F_59 ( & V_44 -> V_181 , L_43 , V_3 -> V_163 ) ;
goto V_193;
}
F_19 ( V_44 , true ) ;
return 0 ;
V_193:
F_78 ( V_3 -> V_191 ) ;
V_192:
F_79 ( V_3 -> V_46 ) ;
V_190:
if ( ! F_16 ( V_3 -> V_47 ) )
F_79 ( V_3 -> V_47 ) ;
V_189:
F_80 ( & V_44 -> V_181 , V_3 -> V_7 ) ;
return V_45 ;
}
static int F_81 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_14 ( V_44 ) ;
struct V_5 * V_7 = V_3 -> V_7 ;
F_80 ( & V_44 -> V_181 , V_7 ) ;
F_19 ( V_44 , false ) ;
F_78 ( V_3 -> V_191 ) ;
F_79 ( V_3 -> V_46 ) ;
if ( ! F_16 ( V_3 -> V_47 ) )
F_79 ( V_3 -> V_47 ) ;
if ( ! F_16 ( V_3 -> V_183 ) )
F_82 ( V_3 -> V_183 ) ;
return 0 ;
}
static int F_83 ( struct V_14 * V_181 )
{
F_19 ( F_84 ( V_181 ) , false ) ;
return 0 ;
}
static int F_85 ( struct V_14 * V_181 )
{
struct V_43 * V_44 = F_84 ( V_181 ) ;
F_13 ( V_44 ) ;
F_19 ( V_44 , true ) ;
return 0 ;
}
