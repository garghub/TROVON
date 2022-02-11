static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 ) {
F_1 ( V_2 , V_7 , 0 ) ;
F_1 ( V_2 , V_7 , 0 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , enum V_8 V_9 )
{
V_2 -> V_9 = V_9 ;
V_2 -> V_10 = V_11 [ V_9 ] ;
V_2 -> V_12 = 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_13 = 0 ;
F_1 ( V_2 , V_14 ,
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
( ( V_2 -> V_20 & V_21 ) << V_22 ) |
( V_2 -> V_23 << V_24 ) ) ;
}
static const char * F_8 ( unsigned int V_25 )
{
if ( F_9 ( V_25 >= F_10 ( V_26 ) ) )
return L_1 ;
return V_26 [ V_25 ] ;
}
static void F_11 ( struct V_1 * V_2 , int V_25 , T_2 V_27 )
{
V_2 -> V_20 = V_25 ;
V_2 -> V_23 = V_27 ;
if ( V_25 == V_28 && V_2 -> V_9 == V_29 ) {
T_1 V_12 = F_3 ( V_2 , V_30 ) ;
if ( V_12 & V_31 && ! ( V_27 & 0x80 ) ) {
F_6 ( V_2 , V_32 ) ;
F_7 ( V_2 ) ;
return;
}
}
F_12 ( V_2 -> V_33 . V_34 . V_35 ,
L_2 ,
F_8 ( V_25 ) , V_25 , V_27 ) ;
V_2 -> V_36 = ( V_25 == V_37 || V_25 == V_38 ) ;
V_2 -> V_39 = false ;
V_2 -> V_12 = 0 ;
F_1 ( V_2 , V_14 ,
( ( V_25 & V_21 ) << V_22 ) |
V_17 |
V_19 |
( V_27 << V_24 ) ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_29 ) ;
F_1 ( V_2 , V_40 , V_2 -> V_10 ) ;
F_11 ( V_2 , V_41 , 0x00 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_42 = false ;
F_1 ( V_2 , V_43 , 0 ) ;
F_1 ( V_2 , V_43 ,
V_44 | V_45 ) ;
}
static void F_15 ( struct V_1 * V_2 , bool V_42 )
{
T_1 V_46 ;
if ( V_2 -> V_42 == V_42 )
return;
V_2 -> V_42 = V_42 ;
V_46 = F_3 ( V_2 , V_43 ) ;
if ( V_42 )
V_46 |= V_47 ;
else
V_46 &= ~ V_47 ;
F_1 ( V_2 , V_43 , V_46 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
while ( V_2 -> V_48 . V_49 ) {
T_1 V_50 ;
T_2 V_27 ;
V_50 = F_3 ( V_2 , V_51 ) ;
if ( V_50 & V_52 )
break;
V_27 = F_3 ( V_2 , V_53 ) ;
* V_2 -> V_48 . V_54 = V_27 ;
F_1 ( V_2 , V_55 , 0xff ) ;
F_5 ( V_2 ) ;
V_2 -> V_48 . V_49 -- ;
V_2 -> V_48 . V_54 ++ ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
while ( V_2 -> V_48 . V_49 ) {
T_1 V_50 ;
V_50 = F_3 ( V_2 , V_51 ) ;
if ( V_50 & V_56 )
break;
F_1 ( V_2 , V_57 , * V_2 -> V_48 . V_54 ) ;
F_5 ( V_2 ) ;
V_2 -> V_48 . V_49 -- ;
V_2 -> V_48 . V_54 ++ ;
}
if ( ! V_2 -> V_48 . V_49 )
V_2 -> V_10 &= ~ V_58 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_59 ) ;
if ( ! V_2 -> V_60 )
V_2 -> V_10 |= V_61 ;
F_1 ( V_2 , V_40 , V_2 -> V_10 ) ;
F_1 ( V_2 , V_62 , V_2 -> V_48 . V_63 ) ;
F_1 ( V_2 , V_64 , V_2 -> V_48 . V_49 ) ;
F_15 ( V_2 , false ) ;
F_19 ( & V_2 -> V_65 , V_66 + F_20 ( 1 ) ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_59 ) ;
if ( ! V_2 -> V_60 )
V_2 -> V_10 |= V_61 ;
F_1 ( V_2 , V_67 , V_2 -> V_48 . V_63 ) ;
F_1 ( V_2 , V_68 , V_2 -> V_48 . V_49 ) ;
F_15 ( V_2 , false ) ;
F_19 ( & V_2 -> V_65 , V_66 + F_20 ( 1 ) ) ;
F_17 ( V_2 ) ;
F_1 ( V_2 , V_40 , V_2 -> V_10 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_69 )
{
F_6 ( V_2 , V_70 ) ;
if ( V_69 ) {
V_2 -> V_71 = V_69 ;
F_15 ( V_2 , false ) ;
}
F_23 ( & V_2 -> V_72 ) ;
}
static unsigned int F_24 ( struct V_1 * V_2 ,
T_1 V_73 , T_1 V_12 )
{
F_11 ( V_2 , V_2 -> V_20 , V_2 -> V_23 ) ;
F_6 ( V_2 , V_29 ) ;
return 0 ;
}
static unsigned int F_25 ( struct V_1 * V_2 , T_1 V_73 ,
T_1 V_12 )
{
if ( V_73 & V_74 ) {
if ( V_2 -> V_13 == 0 )
return F_24 ( V_2 ,
V_73 , V_12 ) ;
-- V_2 -> V_13 ;
}
return 0 ;
}
static unsigned int F_26 ( struct V_1 * V_2 , T_1 V_73 )
{
static const unsigned int V_75 [] = {
[ V_41 ] = V_76 ,
[ V_28 ] = V_77 ,
[ V_38 ] = V_78 | V_79 ,
[ V_37 ] = V_77 ,
[ V_80 ] = V_81 ,
} ;
int V_82 = - 1 ;
T_2 V_83 = 0x00 ;
if ( V_73 & V_61 )
V_2 -> V_39 = true ;
if ( V_73 & V_84 )
V_2 -> V_36 = true ;
if ( ! V_2 -> V_39 || ! V_2 -> V_36 )
return 0 ;
if ( V_2 -> V_20 >= 0 &&
V_2 -> V_20 < F_10 ( V_75 ) ) {
unsigned int V_85 = V_75 [ V_2 -> V_20 ] ;
if ( V_85 ) {
V_85 |= V_86 ;
if ( ! ( V_2 -> V_12 & V_85 ) )
return 0 ;
}
}
V_82 = * V_2 -> V_87 ;
if ( ! V_82 ) {
F_1 ( V_2 , V_14 , 0 ) ;
return F_27 ( 0 ) ;
}
if ( V_82 == V_28 ) {
++ V_2 -> V_87 ;
V_83 = * V_2 -> V_87 ;
}
++ V_2 -> V_87 ;
F_11 ( V_2 , V_82 , V_83 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_88 ) ;
F_1 ( V_2 , V_40 , V_2 -> V_10 ) ;
V_2 -> V_87 = V_89 ;
V_2 -> V_39 = true ;
V_2 -> V_36 = true ;
V_2 -> V_20 = - 1 ;
F_26 ( V_2 , 0 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_88 ) ;
F_1 ( V_2 , V_40 , V_2 -> V_10 ) ;
V_2 -> V_87 = V_90 ;
V_2 -> V_39 = true ;
V_2 -> V_36 = true ;
V_2 -> V_20 = - 1 ;
F_26 ( V_2 , 0 ) ;
}
static unsigned int F_30 ( struct V_1 * V_2 ,
T_1 V_73 ,
T_1 V_12 )
{
int V_82 = - 1 ;
T_2 V_83 = 0x00 ;
if ( V_73 & V_61 )
V_2 -> V_39 = true ;
if ( V_73 & V_84 )
V_2 -> V_36 = true ;
if ( ! V_2 -> V_39 || ! V_2 -> V_36 )
goto V_91;
if ( V_2 -> V_12 & V_86 ) {
F_12 ( V_2 -> V_33 . V_34 . V_35 , L_3 ) ;
V_82 = V_80 ;
V_2 -> V_71 = - V_92 ;
goto V_91;
}
switch ( V_2 -> V_20 ) {
case V_41 :
V_82 = V_28 ;
V_83 = ( V_2 -> V_48 . V_63 << 1 ) ;
if ( V_2 -> V_48 . V_93 & V_94 )
V_83 |= 0x1 ;
break;
case V_28 :
if ( V_2 -> V_12 & V_77 )
V_82 = V_38 ;
break;
case V_38 :
if ( V_2 -> V_12 & V_78 ) {
if ( V_2 -> V_48 . V_49 == 0 ) {
V_82 = V_80 ;
} else if ( V_2 -> V_48 . V_93 & V_94 ) {
V_82 = V_37 ;
} else {
V_82 = V_28 ;
V_83 = * V_2 -> V_48 . V_54 ;
-- V_2 -> V_48 . V_49 ;
++ V_2 -> V_48 . V_54 ;
}
} else if ( V_2 -> V_12 & V_79 ) {
V_2 -> V_71 = - V_92 ;
V_82 = V_80 ;
}
break;
case V_37 :
if ( V_2 -> V_12 & V_77 ) {
* V_2 -> V_48 . V_54 = ( V_2 -> V_12 &
V_95 )
>> V_96 ;
-- V_2 -> V_48 . V_49 ;
++ V_2 -> V_48 . V_54 ;
if ( V_2 -> V_48 . V_49 )
V_82 = V_97 ;
else
V_82 = V_98 ;
}
break;
case V_97 :
if ( V_2 -> V_12 & V_78 ) {
V_82 = V_37 ;
} else {
V_2 -> V_71 = - V_92 ;
V_82 = V_80 ;
}
break;
case V_98 :
V_82 = V_80 ;
break;
case V_80 :
F_1 ( V_2 , V_14 , 0 ) ;
return F_27 ( 0 ) ;
default:
F_31 ( V_2 -> V_33 . V_34 . V_35 , L_4 ,
V_2 -> V_20 ) ;
V_2 -> V_71 = - V_92 ;
V_82 = V_80 ;
break;
}
V_91:
if ( V_82 != - 1 ) {
if ( V_82 == V_80 && ! V_2 -> V_71 &&
! V_2 -> V_60 )
return F_27 ( 0 ) ;
F_11 ( V_2 , V_82 , V_83 ) ;
}
return 0 ;
}
static void F_32 ( unsigned long V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
unsigned long V_93 ;
unsigned int V_12 ;
F_33 ( & V_2 -> V_100 , V_93 ) ;
V_12 = F_3 ( V_2 , V_30 ) ;
if ( V_12 & V_86 ) {
F_12 ( V_2 -> V_33 . V_34 . V_35 ,
L_5 ) ;
F_1 ( V_2 , V_40 ,
V_2 -> V_10 | V_61 ) ;
}
F_34 ( & V_2 -> V_100 , V_93 ) ;
}
static unsigned int F_35 ( struct V_1 * V_2 ,
unsigned int V_73 ,
unsigned int V_12 )
{
if ( V_73 & ( V_101 | V_102 ) )
return F_27 ( V_92 ) ;
if ( V_12 & V_86 ) {
F_12 ( V_2 -> V_33 . V_34 . V_35 , L_3 ) ;
if ( ( V_2 -> V_48 . V_93 & V_94 ) &&
( V_73 & V_103 ) )
F_16 ( V_2 ) ;
V_2 -> V_71 = - V_92 ;
F_29 ( V_2 ) ;
return 0 ;
}
if ( ! V_2 -> V_60 && V_2 -> V_12 & V_76 ) {
F_15 ( V_2 , true ) ;
V_2 -> V_10 &= ~ V_61 ;
}
F_19 ( & V_2 -> V_65 , V_66 + F_20 ( 1 ) ) ;
if ( V_2 -> V_48 . V_93 & V_94 ) {
if ( V_73 & V_103 ) {
F_16 ( V_2 ) ;
if ( V_2 -> V_48 . V_49 == 0 )
return V_104 ;
}
} else {
if ( V_73 & V_105 ) {
if ( ( V_73 & V_106 ) &&
V_2 -> V_48 . V_49 == 0 )
return V_104 ;
F_17 ( V_2 ) ;
}
}
return 0 ;
}
static T_3 F_36 ( int V_107 , void * V_108 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
T_1 V_73 , V_12 ;
unsigned int V_109 ;
V_73 = F_3 ( V_2 , V_110 ) ;
F_1 ( V_2 , V_111 , V_73 ) ;
V_12 = F_3 ( V_2 , V_30 ) ;
if ( V_12 & V_112 ) {
F_1 ( V_2 , V_113 ,
( V_12 & V_112 )
>> V_114 ) ;
F_5 ( V_2 ) ;
}
F_37 ( & V_2 -> V_100 ) ;
V_2 -> V_12 &= ~ V_95 ;
V_2 -> V_12 |= V_12 ;
if ( ( V_73 & V_115 ) &&
! ( V_73 & ( V_61 |
V_106 |
V_116 ) ) ) {
F_38 ( V_2 -> V_33 . V_34 . V_35 ,
L_6 ,
( V_2 -> V_48 . V_93 & V_94 ) ? L_7 : L_8 ,
V_2 -> V_48 . V_63 ) ;
V_109 = F_39 ( V_92 ) ;
goto V_117;
}
if ( V_2 -> V_9 == V_29 )
V_109 = F_30 ( V_2 , V_73 , V_12 ) ;
else if ( V_2 -> V_9 == V_59 )
V_109 = F_35 ( V_2 , V_73 , V_12 ) ;
else if ( V_2 -> V_9 == V_88 )
V_109 = F_26 ( V_2 , V_73 ) ;
else if ( V_2 -> V_9 == V_118 && ( V_73 & V_61 ) &&
( V_12 & V_81 ) )
V_109 = F_27 ( 0 ) ;
else if ( V_2 -> V_9 == V_32 )
V_109 = F_25 ( V_2 , V_73 , V_12 ) ;
else
V_109 = 0 ;
F_1 ( V_2 , V_111 , V_73 & V_119 ) ;
V_117:
if ( V_109 & V_104 ) {
if ( ! V_2 -> V_60 || V_2 -> V_12 & V_81 )
V_109 = F_27 ( 0 ) ;
else
F_6 ( V_2 , V_118 ) ;
}
if ( V_109 & V_120 ) {
int V_69 = - ( V_109 & V_121 ) ;
F_22 ( V_2 , V_69 ) ;
if ( V_109 & V_122 )
F_6 ( V_2 , V_123 ) ;
}
F_1 ( V_2 , V_40 , V_2 -> V_10 ) ;
F_40 ( & V_2 -> V_100 ) ;
return V_124 ;
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned long V_93 ;
int V_125 ;
F_33 ( & V_2 -> V_100 , V_93 ) ;
F_42 ( & V_2 -> V_72 ) ;
F_28 ( V_2 ) ;
F_34 ( & V_2 -> V_100 , V_93 ) ;
V_125 = F_43 ( & V_2 -> V_72 , V_126 ) ;
if ( V_125 == 0 )
return - V_127 ;
return 0 ;
}
static int F_44 ( struct V_128 * V_33 , struct V_129 * V_130 ,
int V_131 )
{
struct V_1 * V_2 = F_45 ( V_33 ) ;
bool V_132 = false ;
int V_133 , V_125 ;
if ( V_2 -> V_9 == V_134 ) {
F_46 ( 1 , L_9 ) ;
return - V_92 ;
}
if ( V_2 -> V_9 == V_123 )
return - V_92 ;
for ( V_133 = 0 ; V_133 < V_131 ; V_133 ++ ) {
if ( F_47 ( V_130 [ V_133 ] . V_49 ) )
continue;
if ( F_9 ( V_130 [ V_133 ] . V_93 & V_94 ) )
return - V_92 ;
V_132 = true ;
}
V_125 = F_48 ( V_2 -> V_135 ) ;
if ( V_125 )
return V_125 ;
for ( V_133 = 0 ; V_133 < V_131 ; V_133 ++ ) {
struct V_129 * V_48 = & V_130 [ V_133 ] ;
unsigned long V_93 ;
F_33 ( & V_2 -> V_100 , V_93 ) ;
V_2 -> V_48 = * V_48 ;
V_2 -> V_71 = 0 ;
V_2 -> V_60 = ( V_133 == V_131 - 1 ) ;
F_42 ( & V_2 -> V_72 ) ;
if ( V_132 )
F_13 ( V_2 ) ;
else if ( V_48 -> V_93 & V_94 )
F_18 ( V_2 ) ;
else
F_21 ( V_2 ) ;
F_34 ( & V_2 -> V_100 , V_93 ) ;
V_125 = F_43 ( & V_2 -> V_72 ,
V_126 ) ;
F_49 ( & V_2 -> V_65 ) ;
if ( V_125 == 0 ) {
F_31 ( V_33 -> V_34 . V_35 , L_10 ) ;
V_2 -> V_71 = - V_127 ;
break;
}
if ( V_2 -> V_71 )
break;
}
F_50 ( V_2 -> V_135 ) ;
return V_2 -> V_71 ? V_2 -> V_71 : V_131 ;
}
static T_1 F_51 ( struct V_128 * V_33 )
{
return V_136 | V_137 ;
}
static int F_52 ( struct V_1 * V_2 )
{
unsigned int V_138 , V_139 , V_140 , V_141 , V_142 , V_143 ;
unsigned int V_133 , V_125 , V_27 , V_144 , V_145 , V_146 , V_147 ;
struct V_148 V_149 ;
T_1 V_150 ;
V_125 = F_48 ( V_2 -> V_135 ) ;
if ( V_125 )
return V_125 ;
V_150 = F_3 ( V_2 , V_7 ) ;
if ( ( V_150 & 0x00ffffff ) < 0x00020200 ) {
F_53 ( V_2 -> V_33 . V_34 . V_35 ,
L_11 ,
( V_150 >> 24 ) & 0xff , ( V_150 >> 16 ) & 0xff ,
( V_150 >> 8 ) & 0xff , V_150 & 0xff ) ;
F_50 ( V_2 -> V_135 ) ;
return - V_151 ;
}
if ( V_150 == V_152 ) {
V_2 -> V_6 = true ;
F_53 ( V_2 -> V_33 . V_34 . V_35 , L_12 ) ;
}
V_139 = V_2 -> V_153 / 1000 ;
V_138 = F_54 ( V_2 -> V_135 ) / 1000 ;
V_149 = V_154 [ 0 ] ;
for ( V_133 = 0 ; V_133 < F_10 ( V_154 ) ; V_133 ++ ) {
if ( V_2 -> V_153 <= V_154 [ V_133 ] . V_155 ) {
V_149 = V_154 [ V_133 ] ;
break;
}
}
V_144 = V_156 * V_138 / ( 256 * 16 * V_139 ) ;
V_144 = F_55 (unsigned int, prescale, 1 , 8 ) ;
V_138 /= V_144 ;
V_145 = ( 256 * 16 * V_139 ) / V_138 ;
if ( V_138 < 20000 ) {
V_147 = V_157 ;
} else if ( V_138 < 40000 ) {
V_147 = V_158 ;
} else {
V_147 = ( 64000 / ( ( V_138 / 1000 ) * V_159 ) ) ;
if ( 64000 % ( ( V_138 / 1000 ) * V_159 ) )
V_145 ++ ;
if ( V_147 > V_160 )
V_147 = V_160 ;
V_147 = ( V_147 & V_160 ) << V_161 ;
}
V_27 = V_147 | ( ( V_145 & V_162 ) << V_163 ) | ( V_144 - 1 ) ;
F_1 ( V_2 , V_164 , V_27 ) ;
V_140 = ( 256 * 1000000 ) / ( V_138 * V_145 ) ;
V_146 = 1000000 / ( V_139 * V_140 ) ;
if ( ( 1000000 % ( V_139 * V_140 ) ) >=
( ( V_139 * V_140 ) / 2 ) )
V_146 ++ ;
V_141 = V_149 . V_141 / V_140 ;
if ( V_149 . V_141 % V_140 )
V_141 ++ ;
if ( V_141 > 0 )
V_27 = V_141 - 1 ;
else
V_27 = 0 ;
F_1 ( V_2 , V_165 , V_27 ) ;
V_142 = V_146 - V_141 ;
if ( V_142 > 0 )
V_27 = V_142 - 1 ;
else
V_27 = 0 ;
F_1 ( V_2 , V_166 , V_27 ) ;
V_143 = V_149 . V_143 / V_140 ;
if ( V_149 . V_143 % V_140 )
V_143 ++ ;
if ( V_143 > 1 )
V_27 = V_143 - 1 ;
else
V_27 = 0x01 ;
F_1 ( V_2 , V_167 , V_27 ) ;
V_143 = V_27 ;
V_27 = V_149 . V_168 / V_140 ;
if ( V_27 > 0 )
-- V_27 ;
F_1 ( V_2 , V_169 , V_27 ) ;
V_27 = V_149 . V_170 / V_140 ;
if ( V_27 > 0 )
-- V_27 ;
F_1 ( V_2 , V_171 , V_27 ) ;
F_1 ( V_2 , V_172 , V_27 + V_143 + 2 ) ;
V_27 = V_149 . V_173 / V_140 ;
if ( V_27 > 0 )
-- V_27 ;
F_1 ( V_2 , V_174 , V_27 ) ;
F_1 ( V_2 , V_175 , V_176 ) ;
F_1 ( V_2 , V_177 , V_178 ) ;
F_1 ( V_2 , V_179 , V_180 ) ;
F_14 ( V_2 ) ;
F_1 ( V_2 , V_40 , 0 ) ;
F_1 ( V_2 , V_111 , ~ 0 ) ;
F_1 ( V_2 , V_113 , ~ 0 ) ;
F_1 ( V_2 , V_40 , V_2 -> V_10 ) ;
V_125 = F_41 ( V_2 ) ;
F_50 ( V_2 -> V_135 ) ;
return V_125 ;
}
static int F_56 ( struct V_181 * V_182 )
{
struct V_183 * V_184 = V_182 -> V_34 . V_185 ;
struct V_1 * V_2 ;
struct V_186 * V_187 ;
int V_107 , V_125 ;
T_1 V_46 ;
V_2 = F_57 ( & V_182 -> V_34 , sizeof( struct V_1 ) , V_188 ) ;
if ( ! V_2 )
return - V_189 ;
V_187 = F_58 ( V_182 , V_190 , 0 ) ;
V_2 -> V_5 = F_59 ( & V_182 -> V_34 , V_187 ) ;
if ( F_60 ( V_2 -> V_5 ) )
return F_61 ( V_2 -> V_5 ) ;
V_107 = F_62 ( V_182 , 0 ) ;
if ( V_107 < 0 ) {
F_31 ( & V_182 -> V_34 , L_13 ) ;
return V_107 ;
}
V_2 -> V_191 = F_63 ( & V_182 -> V_34 , L_14 ) ;
if ( F_60 ( V_2 -> V_191 ) ) {
F_31 ( & V_182 -> V_34 , L_15 ) ;
return F_61 ( V_2 -> V_191 ) ;
}
V_2 -> V_135 = F_63 ( & V_182 -> V_34 , L_16 ) ;
if ( F_60 ( V_2 -> V_135 ) ) {
F_31 ( & V_182 -> V_34 , L_17 ) ;
return F_61 ( V_2 -> V_135 ) ;
}
V_125 = F_64 ( & V_182 -> V_34 , V_107 , F_36 , 0 ,
V_182 -> V_192 , V_2 ) ;
if ( V_125 ) {
F_31 ( & V_182 -> V_34 , L_18 , V_107 ) ;
return V_125 ;
}
F_65 ( & V_2 -> V_65 ) ;
V_2 -> V_65 . V_193 = F_32 ;
V_2 -> V_65 . V_27 = ( unsigned long ) V_2 ;
V_2 -> V_153 = V_154 [ 0 ] . V_155 ;
if ( ! F_66 ( V_184 , L_19 , & V_46 ) )
V_2 -> V_153 = V_46 ;
F_67 ( & V_2 -> V_33 , V_2 ) ;
V_2 -> V_33 . V_34 . V_35 = & V_182 -> V_34 ;
V_2 -> V_33 . V_34 . V_185 = V_184 ;
V_2 -> V_33 . V_194 = V_195 ;
V_2 -> V_33 . V_196 = & V_197 ;
V_2 -> V_33 . V_198 = 5 ;
V_2 -> V_33 . V_199 = V_182 -> V_200 ;
snprintf ( V_2 -> V_33 . V_192 , sizeof( V_2 -> V_33 . V_192 ) , L_20 ) ;
F_6 ( V_2 , V_70 ) ;
F_68 ( & V_2 -> V_100 ) ;
F_69 ( & V_2 -> V_72 ) ;
F_70 ( V_182 , V_2 ) ;
V_125 = F_48 ( V_2 -> V_191 ) ;
if ( V_125 )
return V_125 ;
V_125 = F_52 ( V_2 ) ;
if ( V_125 )
goto V_201;
V_125 = F_71 ( & V_2 -> V_33 ) ;
if ( V_125 < 0 ) {
F_31 ( & V_182 -> V_34 , L_21 ) ;
goto V_201;
}
return 0 ;
V_201:
F_50 ( V_2 -> V_191 ) ;
return V_125 ;
}
static int F_72 ( struct V_181 * V_34 )
{
struct V_1 * V_2 = F_73 ( V_34 ) ;
F_74 ( & V_2 -> V_33 ) ;
F_50 ( V_2 -> V_191 ) ;
return 0 ;
}
static int F_75 ( struct V_202 * V_34 )
{
struct V_1 * V_2 = F_76 ( V_34 ) ;
F_6 ( V_2 , V_134 ) ;
F_50 ( V_2 -> V_191 ) ;
return 0 ;
}
static int F_77 ( struct V_202 * V_34 )
{
struct V_1 * V_2 = F_76 ( V_34 ) ;
int V_125 ;
V_125 = F_48 ( V_2 -> V_191 ) ;
if ( V_125 )
return V_125 ;
F_52 ( V_2 ) ;
return 0 ;
}
