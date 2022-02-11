static inline int F_1 ( enum V_1 V_2 , unsigned long * V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline void F_3 ( enum V_1 V_2 , unsigned long * V_3 )
{
F_4 ( V_2 , V_3 ) ;
}
static inline void F_5 ( enum V_1 V_2 , unsigned long * V_3 )
{
F_6 ( V_2 , V_3 ) ;
}
static void F_7 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
F_8 ( V_7 , V_5 -> V_8 + V_6 ) ;
}
static T_1 F_9 ( struct V_4 * V_5 , T_1 V_6 )
{
return F_10 ( V_5 -> V_8 + V_6 ) ;
}
static void F_11 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
F_8 ( V_7 , V_5 -> V_9 + V_6 ) ;
}
static T_1 F_12 ( struct V_4 * V_5 , T_1 V_6 )
{
return F_10 ( V_5 -> V_9 + V_6 ) ;
}
static void F_13 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
unsigned long V_10 ;
F_14 ( & V_5 -> V_11 , V_10 ) ;
F_15 ( V_5 -> V_12 , V_13 , V_6 ) ;
F_15 ( V_5 -> V_12 , V_14 , V_7 ) ;
F_16 ( & V_5 -> V_11 , V_10 ) ;
}
static void F_17 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
F_8 ( V_7 , V_5 -> V_8 + V_6 ) ;
F_10 ( V_5 -> V_8 + V_6 ) ;
}
static T_1 F_18 ( struct V_4 * V_5 , T_1 V_6 )
{
unsigned long V_10 ;
T_1 V_7 ;
F_14 ( & V_5 -> V_11 , V_10 ) ;
F_15 ( V_5 -> V_12 , V_13 , V_6 ) ;
F_19 ( V_5 -> V_12 , V_14 , & V_7 ) ;
F_16 ( & V_5 -> V_11 , V_10 ) ;
return V_7 ;
}
static void F_20 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
unsigned long V_10 ;
if ( V_6 == ( V_15 + V_16 ) ) {
F_15 ( V_5 -> V_12 , V_17 +
V_16 , V_7 ) ;
return;
}
if ( V_6 == V_18 ) {
F_15 ( V_5 -> V_12 , V_19 +
V_16 , V_7 ) ;
return;
}
F_14 ( & V_5 -> V_11 , V_10 ) ;
F_15 ( V_5 -> V_12 , V_13 , V_6 + 0x5600 ) ;
F_15 ( V_5 -> V_12 , V_14 , V_7 ) ;
F_16 ( & V_5 -> V_11 , V_10 ) ;
if ( ( V_6 == ( V_20 + V_16 ) ) &&
( V_7 == 0x1 ) ) {
F_15 ( V_5 -> V_12 , V_21 ,
V_5 -> V_22 | V_23 ) ;
}
}
static T_1 F_21 ( struct V_4 * V_5 , T_1 V_6 )
{
unsigned long V_10 ;
T_1 V_7 ;
F_14 ( & V_5 -> V_11 , V_10 ) ;
F_15 ( V_5 -> V_12 , V_13 , V_6 + 0x5600 ) ;
F_19 ( V_5 -> V_12 , V_14 , & V_7 ) ;
F_16 ( & V_5 -> V_11 , V_10 ) ;
return V_7 ;
}
static void F_22 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 , T_1 V_24 )
{
if ( F_23 ( V_5 , V_25 ) || F_23 ( V_5 , V_26 ) )
V_5 -> V_27 ( V_5 , V_6 , V_7 ) ;
else {
F_7 ( V_5 , V_6 , V_7 ) ;
if ( V_24 )
F_24 ( V_24 ) ;
V_5 -> V_28 ( V_5 , V_6 ) ;
}
if ( V_24 )
F_24 ( V_24 ) ;
}
static inline void F_25 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
V_5 -> V_29 ( V_5 , V_6 , V_7 ) ;
if ( F_23 ( V_5 , V_30 ) ||
( ! F_23 ( V_5 , V_31 ) &&
! F_23 ( V_5 , V_26 ) ) )
V_5 -> V_32 ( V_5 , V_6 ) ;
}
static void F_26 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
void T_2 * V_33 = V_5 -> V_8 + V_6 ;
F_8 ( V_7 , V_33 ) ;
if ( F_23 ( V_5 , V_34 ) )
F_8 ( V_7 , V_33 ) ;
if ( F_23 ( V_5 , V_31 ) ||
F_23 ( V_5 , V_30 ) )
F_10 ( V_33 ) ;
}
static T_1 F_27 ( struct V_4 * V_5 , T_1 V_6 )
{
return F_10 ( V_5 -> V_8 + V_6 + V_35 ) ;
}
static void F_28 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
F_8 ( V_7 , V_5 -> V_8 + V_6 + V_35 ) ;
}
static void F_29 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
unsigned long V_10 ;
if ( F_30 ( V_5 ) == V_36 &&
( V_6 >= V_37 ) && ( V_6 < V_38 ) )
return;
F_14 ( & V_5 -> V_11 , V_10 ) ;
if ( F_23 ( V_5 , V_39 ) ) {
F_15 ( V_5 -> V_12 , V_40 , V_6 ) ;
F_15 ( V_5 -> V_12 , V_41 , V_7 ) ;
F_15 ( V_5 -> V_12 , V_40 , 0 ) ;
} else {
F_31 ( V_40 , V_6 ) ;
F_31 ( V_41 , V_7 ) ;
F_31 ( V_40 , 0 ) ;
}
F_16 ( & V_5 -> V_11 , V_10 ) ;
}
static void F_32 ( struct V_4 * V_5 , T_1 V_6 , T_1 * V_7 )
{
unsigned long V_10 ;
if ( F_30 ( V_5 ) == V_36 &&
( V_6 >= V_37 ) && ( V_6 < V_38 ) ) {
* V_7 = 0 ;
return;
}
F_14 ( & V_5 -> V_11 , V_10 ) ;
if ( F_23 ( V_5 , V_39 ) ) {
F_15 ( V_5 -> V_12 , V_40 , V_6 ) ;
F_19 ( V_5 -> V_12 , V_41 , V_7 ) ;
F_15 ( V_5 -> V_12 , V_40 , 0 ) ;
} else {
F_31 ( V_40 , V_6 ) ;
* V_7 = F_33 ( V_41 ) ;
F_31 ( V_40 , 0 ) ;
}
F_16 ( & V_5 -> V_11 , V_10 ) ;
}
static void F_34 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_43 , V_44 ;
if ( F_30 ( V_5 ) == V_45 )
V_43 = V_46 ;
else
V_43 = V_47 ;
for ( V_42 = V_48 ; V_42 <= V_49 ; V_42 ++ ) {
switch ( V_42 ) {
case V_48 :
case V_50 :
case V_51 :
case V_52 :
V_44 = V_53 ;
break;
default:
if ( ! V_5 -> V_54 )
V_44 = V_53 ;
else
V_44 = 1 << V_5 -> V_54 ;
}
F_11 ( V_5 , V_43 + 4 * V_42 , V_44 ) ;
}
}
static int F_35 ( struct V_4 * V_5 , int V_55 )
{
int V_42 , V_6 ;
int V_56 = 0 ;
T_1 V_57 , V_58 , V_59 , V_44 ;
if ( ! F_23 ( V_5 , V_60 ) )
return 0 ;
switch ( V_55 ) {
case V_49 :
if ( F_30 ( V_5 ) == V_45 )
return 0 ;
case V_61 :
case V_62 :
if ( ! V_5 -> V_54 )
V_44 = V_63 ;
else
V_44 = 1 << V_5 -> V_54 ;
break;
case V_48 :
case V_50 :
case V_51 :
case V_52 :
V_44 = V_63 ;
break;
default:
return - V_64 ;
}
if ( F_30 ( V_5 ) == V_45 ) {
V_58 = V_65 ;
V_59 = V_46 ;
} else {
V_58 = V_66 ;
V_59 = V_47 ;
}
V_6 = 4 * V_55 ;
F_11 ( V_5 , V_58 + V_6 , V_44 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_57 = F_12 ( V_5 , V_59 + V_6 ) ;
if ( V_57 == V_44 )
break;
if ( F_36 ( V_5 -> V_12 ) )
break;
F_24 ( 10 ) ;
}
if ( V_57 != V_44 ) {
F_11 ( V_5 , V_59 + V_6 , V_44 ) ;
V_56 = - V_67 ;
}
return V_56 ;
}
static void F_37 ( struct V_4 * V_5 , int V_55 )
{
T_1 V_59 , V_44 ;
if ( ! F_23 ( V_5 , V_60 ) )
return;
switch ( V_55 ) {
case V_49 :
if ( F_30 ( V_5 ) == V_45 )
return;
case V_61 :
case V_62 :
if ( ! V_5 -> V_54 )
V_44 = V_53 ;
else
V_44 = 1 << V_5 -> V_54 ;
break;
case V_48 :
case V_50 :
case V_51 :
case V_52 :
V_44 = V_53 ;
break;
default:
return;
}
if ( F_30 ( V_5 ) == V_45 )
V_59 = V_46 ;
else
V_59 = V_47 ;
F_11 ( V_5 , V_59 + 4 * V_55 , V_44 ) ;
}
static int F_38 ( struct V_4 * V_5 , T_1 V_68 )
{
T_1 V_69 ;
while ( V_68 ) {
if ( F_35 ( V_5 , V_62 ) )
return - V_67 ;
V_69 = F_12 ( V_5 , V_70 ) ;
if ( ! ( V_69 & V_71 ) )
break;
F_37 ( V_5 , V_62 ) ;
F_24 ( 10 ) ;
V_68 -= ( V_68 > 10 ) ? 10 : V_68 ;
}
return V_68 ? 0 : - V_67 ;
}
static int F_39 ( struct V_4 * V_5 , T_1 V_68 )
{
T_1 V_42 , V_69 ;
for ( V_42 = 0 ; V_42 < V_68 / 10 ; V_42 ++ ) {
V_69 = F_12 ( V_5 , V_70 ) ;
if ( ! ( V_69 & V_71 ) )
break;
F_24 ( 10 ) ;
}
return V_42 == V_68 / 10 ;
}
static int F_40 ( struct V_4 * V_5 , T_1 * V_72 , T_1 V_73 ,
T_1 V_74 )
{
int V_75 ;
T_1 V_42 , V_76 , V_77 , V_78 , V_69 ;
if ( ! F_23 ( V_5 , V_79 ) )
return 0 ;
V_69 = F_12 ( V_5 , V_80 ) ;
if ( V_69 != V_81 )
return - V_82 ;
V_69 = F_12 ( V_5 , V_83 ) ;
if ( ! ( V_69 & V_84 ) )
return - V_85 ;
V_76 = F_12 ( V_5 , V_86 ) +
V_87 ;
V_77 = V_76 + 2 * sizeof( T_1 ) ;
V_78 = F_12 ( V_5 , V_88 ) ;
while ( V_74 ) {
T_1 V_89 ;
V_89 = ( V_74 > V_78 ) ? V_78 : V_74 ;
V_74 -= V_89 ;
V_69 = F_12 ( V_5 , V_83 ) ;
if ( ! ( V_69 & V_84 ) )
return - V_85 ;
V_75 = F_38 ( V_5 , 1000 ) ;
if ( V_75 )
return V_75 ;
V_69 = V_90 |
V_91 |
V_71 ;
F_11 ( V_5 , V_70 , V_69 ) ;
F_11 ( V_5 , V_76 , V_73 ) ;
F_11 ( V_5 , V_76 + sizeof( T_1 ) , V_89 ) ;
F_37 ( V_5 , V_62 ) ;
F_11 ( V_5 , V_92 , V_93 ) ;
V_73 += V_89 ;
if ( F_39 ( V_5 , 30000 ) )
return - V_85 ;
for ( V_42 = 0 ; V_89 ; V_42 += 4 , V_89 -= 4 ) {
T_1 V_7 = F_12 ( V_5 , V_77 + V_42 ) ;
memcpy ( V_72 , & V_7 , sizeof( T_1 ) ) ;
V_72 ++ ;
}
}
return 0 ;
}
static int F_41 ( struct V_4 * V_5 , T_1 V_94 )
{
int V_75 ;
T_1 V_69 ;
V_69 = F_12 ( V_5 , V_80 ) ;
if ( V_69 != V_81 )
return - V_85 ;
V_69 = F_12 ( V_5 , V_83 ) ;
if ( ! ( V_69 & V_84 ) )
return - V_85 ;
V_75 = F_38 ( V_5 , 1000 ) ;
if ( V_75 )
return V_75 ;
F_11 ( V_5 , V_70 ,
V_94 | V_71 ) ;
F_37 ( V_5 , V_62 ) ;
F_11 ( V_5 , V_92 , V_93 ) ;
return 0 ;
}
static void F_42 ( struct V_4 * V_5 , int V_95 )
{
T_1 V_94 ;
T_1 V_69 ;
if ( ! F_23 ( V_5 , V_60 ) )
return;
switch ( V_95 ) {
case V_96 :
F_11 ( V_5 , V_97 ,
V_98 ) ;
F_11 ( V_5 , V_99 ,
V_100 ) ;
V_69 = F_12 ( V_5 , V_101 ) ;
F_11 ( V_5 , V_101 , ++ V_69 ) ;
F_11 ( V_5 , V_102 ,
F_43 ( V_103 , V_104 ) ) ;
F_11 ( V_5 , V_105 ,
V_106 ) ;
F_11 ( V_5 , V_107 ,
V_108 ) ;
V_94 = V_109 ;
break;
case V_110 :
F_11 ( V_5 , V_97 , 0x0 ) ;
if ( F_44 ( & V_5 -> V_12 -> V_111 ) &&
F_23 ( V_5 , V_112 ) ) {
F_11 ( V_5 , V_113 ,
V_114 ) ;
V_69 = V_115 ;
} else
V_69 = V_116 ;
F_11 ( V_5 , V_107 , V_69 ) ;
V_94 = V_117 ;
break;
default:
return;
}
V_94 |= V_90 | V_118 ;
F_41 ( V_5 , V_94 ) ;
}
static void F_45 ( struct V_4 * V_5 )
{
int V_42 ;
F_46 ( V_119 ,
( V_5 -> V_120 | V_121 ) ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
F_47 ( V_5 -> V_123 [ V_42 ] . V_124 , 0x00000001 ) ;
}
static void F_48 ( struct V_4 * V_5 )
{
int V_42 ;
V_5 -> V_125 = 0 ;
F_49 () ;
F_46 ( V_119 ,
( V_5 -> V_120 & ~ V_121 ) ) ;
V_5 -> V_126 = V_5 -> V_127 | V_128 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_47 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
if ( F_23 ( V_5 , 1SHOT_MSI ) )
F_47 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
V_5 -> V_126 |= V_131 -> V_126 ;
}
if ( ! F_23 ( V_5 , V_133 ) &&
( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & V_135 ) )
F_46 ( V_136 , V_5 -> V_22 | V_137 ) ;
else
F_46 ( V_138 , V_5 -> V_126 ) ;
V_5 -> V_126 &= ~ ( V_5 -> V_123 [ 0 ] . V_126 | V_5 -> V_123 [ 1 ] . V_126 ) ;
}
static inline unsigned int F_50 ( struct V_130 * V_131 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_141 = 0 ;
if ( ! ( F_23 ( V_5 , V_142 ) || F_23 ( V_5 , V_143 ) ) ) {
if ( V_140 -> V_57 & V_144 )
V_141 = 1 ;
}
if ( V_140 -> V_145 [ 0 ] . V_146 != V_131 -> V_147 )
V_141 = 1 ;
if ( V_131 -> V_148 &&
* ( V_131 -> V_148 ) != V_131 -> V_149 )
V_141 = 1 ;
return V_141 ;
}
static void F_51 ( struct V_130 * V_131 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
F_52 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
F_53 () ;
if ( ! F_23 ( V_5 , V_133 ) && F_50 ( V_131 ) )
F_46 ( V_138 , V_5 -> V_127 |
V_128 | V_131 -> V_126 ) ;
}
static void F_54 ( struct V_4 * V_5 )
{
T_1 V_150 ;
T_1 V_151 ;
if ( F_23 ( V_5 , V_152 ) || F_23 ( V_5 , 5780_CLASS ) )
return;
V_150 = F_33 ( V_153 ) ;
V_151 = V_150 ;
V_150 &= ( V_154 |
V_155 |
0x1f ) ;
V_5 -> V_156 = V_150 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
if ( V_151 & V_157 ) {
F_55 ( V_153 ,
V_150 | V_157 , 40 ) ;
}
} else if ( ( V_151 & V_158 ) != 0 ) {
F_55 ( V_153 ,
V_150 |
( V_158 | V_159 ) ,
40 ) ;
F_55 ( V_153 ,
V_150 | ( V_159 ) ,
40 ) ;
}
F_55 ( V_153 , V_150 , 40 ) ;
}
static int F_56 ( struct V_4 * V_5 , unsigned int V_160 , int V_161 ,
T_1 * V_7 )
{
T_1 V_162 ;
unsigned int V_163 ;
int V_56 ;
if ( ( V_5 -> V_164 & V_165 ) != 0 ) {
F_31 ( V_166 ,
( V_5 -> V_164 & ~ V_165 ) ) ;
F_24 ( 80 ) ;
}
F_35 ( V_5 , V_5 -> V_167 ) ;
* V_7 = 0x0 ;
V_162 = ( ( V_160 << V_168 ) &
V_169 ) ;
V_162 |= ( ( V_161 << V_170 ) &
V_171 ) ;
V_162 |= ( V_172 | V_173 ) ;
F_31 ( V_174 , V_162 ) ;
V_163 = V_175 ;
while ( V_163 != 0 ) {
F_24 ( 10 ) ;
V_162 = F_33 ( V_174 ) ;
if ( ( V_162 & V_176 ) == 0 ) {
F_24 ( 5 ) ;
V_162 = F_33 ( V_174 ) ;
break;
}
V_163 -= 1 ;
}
V_56 = - V_67 ;
if ( V_163 != 0 ) {
* V_7 = V_162 & V_177 ;
V_56 = 0 ;
}
if ( ( V_5 -> V_164 & V_165 ) != 0 ) {
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
}
F_37 ( V_5 , V_5 -> V_167 ) ;
return V_56 ;
}
static int F_57 ( struct V_4 * V_5 , int V_161 , T_1 * V_7 )
{
return F_56 ( V_5 , V_5 -> V_160 , V_161 , V_7 ) ;
}
static int F_58 ( struct V_4 * V_5 , unsigned int V_160 , int V_161 ,
T_1 V_7 )
{
T_1 V_162 ;
unsigned int V_163 ;
int V_56 ;
if ( ( V_5 -> V_178 & V_179 ) &&
( V_161 == V_180 || V_161 == V_181 ) )
return 0 ;
if ( ( V_5 -> V_164 & V_165 ) != 0 ) {
F_31 ( V_166 ,
( V_5 -> V_164 & ~ V_165 ) ) ;
F_24 ( 80 ) ;
}
F_35 ( V_5 , V_5 -> V_167 ) ;
V_162 = ( ( V_160 << V_168 ) &
V_169 ) ;
V_162 |= ( ( V_161 << V_170 ) &
V_171 ) ;
V_162 |= ( V_7 & V_177 ) ;
V_162 |= ( V_182 | V_173 ) ;
F_31 ( V_174 , V_162 ) ;
V_163 = V_175 ;
while ( V_163 != 0 ) {
F_24 ( 10 ) ;
V_162 = F_33 ( V_174 ) ;
if ( ( V_162 & V_176 ) == 0 ) {
F_24 ( 5 ) ;
V_162 = F_33 ( V_174 ) ;
break;
}
V_163 -= 1 ;
}
V_56 = - V_67 ;
if ( V_163 != 0 )
V_56 = 0 ;
if ( ( V_5 -> V_164 & V_165 ) != 0 ) {
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
}
F_37 ( V_5 , V_5 -> V_167 ) ;
return V_56 ;
}
static int F_59 ( struct V_4 * V_5 , int V_161 , T_1 V_7 )
{
return F_58 ( V_5 , V_5 -> V_160 , V_161 , V_7 ) ;
}
static int F_60 ( struct V_4 * V_5 , T_1 V_183 , T_1 V_184 , T_1 V_7 )
{
int V_75 ;
V_75 = F_59 ( V_5 , V_185 , V_183 ) ;
if ( V_75 )
goto V_186;
V_75 = F_59 ( V_5 , V_187 , V_184 ) ;
if ( V_75 )
goto V_186;
V_75 = F_59 ( V_5 , V_185 ,
V_188 | V_183 ) ;
if ( V_75 )
goto V_186;
V_75 = F_59 ( V_5 , V_187 , V_7 ) ;
V_186:
return V_75 ;
}
static int F_61 ( struct V_4 * V_5 , T_1 V_183 , T_1 V_184 , T_1 * V_7 )
{
int V_75 ;
V_75 = F_59 ( V_5 , V_185 , V_183 ) ;
if ( V_75 )
goto V_186;
V_75 = F_59 ( V_5 , V_187 , V_184 ) ;
if ( V_75 )
goto V_186;
V_75 = F_59 ( V_5 , V_185 ,
V_188 | V_183 ) ;
if ( V_75 )
goto V_186;
V_75 = F_57 ( V_5 , V_187 , V_7 ) ;
V_186:
return V_75 ;
}
static int F_62 ( struct V_4 * V_5 , T_1 V_161 , T_1 * V_7 )
{
int V_75 ;
V_75 = F_59 ( V_5 , V_189 , V_161 ) ;
if ( ! V_75 )
V_75 = F_57 ( V_5 , V_190 , V_7 ) ;
return V_75 ;
}
static int F_63 ( struct V_4 * V_5 , T_1 V_161 , T_1 V_7 )
{
int V_75 ;
V_75 = F_59 ( V_5 , V_189 , V_161 ) ;
if ( ! V_75 )
V_75 = F_59 ( V_5 , V_190 , V_7 ) ;
return V_75 ;
}
static int F_64 ( struct V_4 * V_5 , int V_161 , T_1 * V_7 )
{
int V_75 ;
V_75 = F_59 ( V_5 , V_181 ,
( V_161 << V_191 ) |
V_192 ) ;
if ( ! V_75 )
V_75 = F_57 ( V_5 , V_181 , V_7 ) ;
return V_75 ;
}
static int F_65 ( struct V_4 * V_5 , int V_161 , T_1 V_193 )
{
if ( V_161 == V_192 )
V_193 |= V_194 ;
return F_59 ( V_5 , V_181 , V_193 | V_161 ) ;
}
static int F_66 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_7 ;
int V_75 ;
V_75 = F_64 ( V_5 , V_196 , & V_7 ) ;
if ( V_75 )
return V_75 ;
if ( V_195 )
V_7 |= V_197 ;
else
V_7 &= ~ V_197 ;
V_75 = F_65 ( ( V_5 ) , V_196 ,
V_7 | V_198 ) ;
return V_75 ;
}
static int F_67 ( struct V_4 * V_5 )
{
T_1 V_199 ;
int V_200 , V_75 ;
V_199 = V_201 ;
V_75 = F_59 ( V_5 , V_202 , V_199 ) ;
if ( V_75 != 0 )
return - V_67 ;
V_200 = 5000 ;
while ( V_200 -- ) {
V_75 = F_57 ( V_5 , V_202 , & V_199 ) ;
if ( V_75 != 0 )
return - V_67 ;
if ( ( V_199 & V_201 ) == 0 ) {
F_24 ( 40 ) ;
break;
}
F_24 ( 10 ) ;
}
if ( V_200 < 0 )
return - V_67 ;
return 0 ;
}
static int F_68 ( struct V_203 * V_204 , int V_205 , int V_161 )
{
struct V_4 * V_5 = V_204 -> V_206 ;
T_1 V_7 ;
F_69 ( & V_5 -> V_207 ) ;
if ( F_57 ( V_5 , V_161 , & V_7 ) )
V_7 = - V_208 ;
F_70 ( & V_5 -> V_207 ) ;
return V_7 ;
}
static int F_71 ( struct V_203 * V_204 , int V_205 , int V_161 , T_3 V_7 )
{
struct V_4 * V_5 = V_204 -> V_206 ;
T_1 V_56 = 0 ;
F_69 ( & V_5 -> V_207 ) ;
if ( F_59 ( V_5 , V_161 , V_7 ) )
V_56 = - V_208 ;
F_70 ( & V_5 -> V_207 ) ;
return V_56 ;
}
static int F_72 ( struct V_203 * V_204 )
{
return 0 ;
}
static void F_73 ( struct V_4 * V_5 )
{
T_1 V_7 ;
struct V_209 * V_210 ;
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
switch ( V_210 -> V_214 -> V_215 & V_210 -> V_214 -> V_216 ) {
case V_217 :
case V_218 :
V_7 = V_219 ;
break;
case V_220 :
V_7 = V_221 ;
break;
case V_222 :
V_7 = V_223 ;
break;
case V_224 :
V_7 = V_225 ;
break;
default:
return;
}
if ( V_210 -> V_226 != V_227 ) {
F_46 ( V_228 , V_7 ) ;
V_7 = F_33 ( V_229 ) ;
V_7 &= ~ ( V_230 |
V_231 | V_232 ) ;
V_7 |= V_233 | V_234 ;
F_46 ( V_229 , V_7 ) ;
return;
}
if ( ! F_23 ( V_5 , V_235 ) )
V_7 |= V_236 |
V_237 |
V_238 |
V_239 |
V_240 |
V_241 ;
F_46 ( V_228 , V_7 ) ;
V_7 = F_33 ( V_229 ) ;
V_7 &= ~ ( V_231 | V_232 |
V_242 | V_243 ) ;
if ( ! F_23 ( V_5 , V_235 ) ) {
if ( F_23 ( V_5 , V_244 ) )
V_7 |= V_242 ;
if ( F_23 ( V_5 , V_245 ) )
V_7 |= V_243 ;
}
V_7 |= V_233 | V_234 |
V_230 | V_246 ;
F_46 ( V_229 , V_7 ) ;
V_7 = F_33 ( V_247 ) ;
V_7 &= ~ ( V_248 |
V_249 |
V_250 |
V_251 |
V_252 |
V_253 |
V_254 ) ;
if ( ! F_23 ( V_5 , V_235 ) ) {
if ( F_23 ( V_5 , V_244 ) )
V_7 |= V_248 |
V_249 |
V_250 |
V_251 ;
if ( F_23 ( V_5 , V_245 ) )
V_7 |= V_252 |
V_253 |
V_254 ;
}
F_46 ( V_247 , V_7 ) ;
}
static void F_74 ( struct V_4 * V_5 )
{
V_5 -> V_164 &= ~ V_165 ;
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
if ( F_23 ( V_5 , V_255 ) &&
F_30 ( V_5 ) == V_256 )
F_73 ( V_5 ) ;
}
static int F_75 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_161 ;
struct V_209 * V_210 ;
if ( F_23 ( V_5 , 5717_PLUS ) ) {
T_1 V_257 ;
V_5 -> V_160 = V_5 -> V_54 + 1 ;
if ( F_76 ( V_5 ) != V_258 )
V_257 = F_33 ( V_259 ) & V_260 ;
else
V_257 = F_33 ( V_261 ) &
V_262 ;
if ( V_257 )
V_5 -> V_160 += 7 ;
} else
V_5 -> V_160 = V_213 ;
F_74 ( V_5 ) ;
if ( ! F_23 ( V_5 , V_263 ) || F_23 ( V_5 , V_255 ) )
return 0 ;
V_5 -> V_211 = F_77 () ;
if ( V_5 -> V_211 == NULL )
return - V_264 ;
V_5 -> V_211 -> V_265 = L_1 ;
snprintf ( V_5 -> V_211 -> V_266 , V_267 , L_2 ,
( V_5 -> V_12 -> V_268 -> V_269 << 8 ) | V_5 -> V_12 -> V_270 ) ;
V_5 -> V_211 -> V_206 = V_5 ;
V_5 -> V_211 -> V_271 = & V_5 -> V_12 -> V_111 ;
V_5 -> V_211 -> V_272 = & F_68 ;
V_5 -> V_211 -> V_273 = & F_71 ;
V_5 -> V_211 -> V_274 = & F_72 ;
V_5 -> V_211 -> V_275 = ~ ( 1 << V_213 ) ;
V_5 -> V_211 -> V_276 = & V_5 -> V_277 [ 0 ] ;
for ( V_42 = 0 ; V_42 < V_278 ; V_42 ++ )
V_5 -> V_211 -> V_276 [ V_42 ] = V_279 ;
if ( F_57 ( V_5 , V_202 , & V_161 ) || ( V_161 & V_280 ) )
F_67 ( V_5 ) ;
V_42 = F_78 ( V_5 -> V_211 ) ;
if ( V_42 ) {
F_79 ( & V_5 -> V_12 -> V_111 , L_3 , V_42 ) ;
F_80 ( V_5 -> V_211 ) ;
return V_42 ;
}
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
if ( ! V_210 || ! V_210 -> V_214 ) {
F_79 ( & V_5 -> V_12 -> V_111 , L_4 ) ;
F_81 ( V_5 -> V_211 ) ;
F_80 ( V_5 -> V_211 ) ;
return - V_82 ;
}
switch ( V_210 -> V_214 -> V_215 & V_210 -> V_214 -> V_216 ) {
case V_281 :
V_210 -> V_226 = V_282 ;
V_210 -> V_283 |= V_284 ;
break;
case V_217 :
case V_218 :
V_210 -> V_283 |= V_285 |
V_286 |
V_287 |
V_284 ;
if ( F_23 ( V_5 , V_235 ) )
V_210 -> V_283 |= V_288 ;
if ( F_23 ( V_5 , V_244 ) )
V_210 -> V_283 |= V_289 ;
if ( F_23 ( V_5 , V_245 ) )
V_210 -> V_283 |= V_290 ;
case V_222 :
V_210 -> V_226 = V_227 ;
break;
case V_224 :
case V_220 :
V_210 -> V_226 = V_291 ;
V_210 -> V_283 |= V_284 ;
V_5 -> V_178 |= V_179 ;
break;
}
F_82 ( V_5 , V_255 ) ;
if ( F_30 ( V_5 ) == V_256 )
F_73 ( V_5 ) ;
return 0 ;
}
static void F_83 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_255 ) ) {
F_84 ( V_5 , V_255 ) ;
F_81 ( V_5 -> V_211 ) ;
F_80 ( V_5 -> V_211 ) ;
}
}
static inline void F_85 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_7 = F_33 ( V_292 ) ;
V_7 |= V_293 ;
F_31 ( V_292 , V_7 ) ;
V_5 -> V_294 = V_295 ;
}
static void F_86 ( struct V_4 * V_5 )
{
int V_42 ;
unsigned int V_296 ;
long V_297 ;
V_297 = ( long ) ( V_5 -> V_294 + 1 +
F_87 ( V_298 ) ) -
( long ) V_295 ;
if ( V_297 < 0 )
return;
V_296 = F_88 ( V_297 ) ;
if ( V_296 > V_298 )
V_296 = V_298 ;
V_296 = ( V_296 >> 3 ) + 1 ;
for ( V_42 = 0 ; V_42 < V_296 ; V_42 ++ ) {
if ( ! ( F_33 ( V_292 ) & V_293 ) )
break;
if ( F_36 ( V_5 -> V_12 ) )
break;
F_24 ( 8 ) ;
}
}
static void F_89 ( struct V_4 * V_5 , T_1 * V_72 )
{
T_1 V_161 , V_7 ;
V_7 = 0 ;
if ( ! F_57 ( V_5 , V_202 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_299 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
* V_72 ++ = V_7 ;
V_7 = 0 ;
if ( ! F_57 ( V_5 , V_300 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_301 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
* V_72 ++ = V_7 ;
V_7 = 0 ;
if ( ! ( V_5 -> V_178 & V_302 ) ) {
if ( ! F_57 ( V_5 , V_180 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_303 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
}
* V_72 ++ = V_7 ;
if ( ! F_57 ( V_5 , V_304 , & V_161 ) )
V_7 = V_161 << 16 ;
else
V_7 = 0 ;
* V_72 ++ = V_7 ;
}
static void F_90 ( struct V_4 * V_5 )
{
T_1 V_72 [ 4 ] ;
if ( ! F_23 ( V_5 , 5780_CLASS ) || ! F_23 ( V_5 , V_305 ) )
return;
F_89 ( V_5 , V_72 ) ;
F_86 ( V_5 ) ;
F_29 ( V_5 , V_306 , V_307 ) ;
F_29 ( V_5 , V_308 , 14 ) ;
F_29 ( V_5 , V_309 + 0x0 , V_72 [ 0 ] ) ;
F_29 ( V_5 , V_309 + 0x4 , V_72 [ 1 ] ) ;
F_29 ( V_5 , V_309 + 0x8 , V_72 [ 2 ] ) ;
F_29 ( V_5 , V_309 + 0xc , V_72 [ 3 ] ) ;
F_85 ( V_5 ) ;
}
static void F_91 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_305 ) && ! F_23 ( V_5 , V_60 ) ) {
F_86 ( V_5 ) ;
F_29 ( V_5 , V_306 , V_310 ) ;
F_85 ( V_5 ) ;
F_86 ( V_5 ) ;
}
}
static void F_92 ( struct V_4 * V_5 , int V_95 )
{
F_29 ( V_5 , V_311 ,
V_312 ) ;
if ( F_23 ( V_5 , V_313 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_314 ,
V_315 ) ;
break;
case V_110 :
F_29 ( V_5 , V_314 ,
V_316 ) ;
break;
case V_317 :
F_29 ( V_5 , V_314 ,
V_318 ) ;
break;
default:
break;
}
}
}
static void F_93 ( struct V_4 * V_5 , int V_95 )
{
if ( F_23 ( V_5 , V_313 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_314 ,
V_319 ) ;
break;
case V_110 :
F_29 ( V_5 , V_314 ,
V_320 ) ;
break;
default:
break;
}
}
}
static void F_94 ( struct V_4 * V_5 , int V_95 )
{
if ( F_23 ( V_5 , V_305 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_314 ,
V_315 ) ;
break;
case V_110 :
F_29 ( V_5 , V_314 ,
V_316 ) ;
break;
case V_317 :
F_29 ( V_5 , V_314 ,
V_318 ) ;
break;
default:
break;
}
}
}
static int F_95 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_7 ;
if ( F_23 ( V_5 , V_321 ) )
return 0 ;
if ( F_23 ( V_5 , V_322 ) ) {
return 0 ;
}
if ( F_30 ( V_5 ) == V_36 ) {
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
if ( F_33 ( V_323 ) & V_324 )
return 0 ;
if ( F_36 ( V_5 -> V_12 ) )
return - V_82 ;
F_24 ( 100 ) ;
}
return - V_82 ;
}
for ( V_42 = 0 ; V_42 < 100000 ; V_42 ++ ) {
F_32 ( V_5 , V_311 , & V_7 ) ;
if ( V_7 == ~ V_312 )
break;
if ( F_36 ( V_5 -> V_12 ) ) {
if ( ! F_23 ( V_5 , V_321 ) ) {
F_82 ( V_5 , V_321 ) ;
F_96 ( V_5 -> V_111 , L_5 ) ;
}
break;
}
F_24 ( 10 ) ;
}
if ( V_42 >= 100000 && ! F_23 ( V_5 , V_321 ) ) {
F_82 ( V_5 , V_321 ) ;
F_96 ( V_5 -> V_111 , L_5 ) ;
}
if ( F_76 ( V_5 ) == V_325 ) {
F_97 ( 10 ) ;
}
return 0 ;
}
static void F_98 ( struct V_4 * V_5 )
{
if ( ! F_99 ( V_5 -> V_111 ) ) {
F_100 ( V_5 , V_326 , V_5 -> V_111 , L_6 ) ;
F_90 ( V_5 ) ;
} else if ( F_101 ( V_5 ) ) {
F_96 ( V_5 -> V_111 , L_7 ,
( V_5 -> V_327 . V_328 == V_329 ?
1000 :
( V_5 -> V_327 . V_328 == V_330 ?
100 : 10 ) ) ,
( V_5 -> V_327 . V_331 == V_332 ?
L_8 : L_9 ) ) ;
F_96 ( V_5 -> V_111 , L_10 ,
( V_5 -> V_327 . V_333 & V_334 ) ?
L_11 : L_12 ,
( V_5 -> V_327 . V_333 & V_335 ) ?
L_11 : L_12 ) ;
if ( V_5 -> V_178 & V_336 )
F_96 ( V_5 -> V_111 , L_13 ,
V_5 -> V_337 ? L_14 : L_15 ) ;
F_90 ( V_5 ) ;
}
V_5 -> V_338 = F_99 ( V_5 -> V_111 ) ;
}
static T_1 F_102 ( T_1 V_339 )
{
T_1 V_340 = 0 ;
if ( V_339 & V_341 ) {
V_340 |= V_335 ;
if ( ! ( V_339 & V_342 ) )
V_340 |= V_334 ;
} else if ( V_339 & V_342 )
V_340 |= V_334 ;
return V_340 ;
}
static T_3 F_103 ( T_4 V_343 )
{
T_3 V_344 ;
if ( ( V_343 & V_334 ) && ( V_343 & V_335 ) )
V_344 = V_345 ;
else if ( V_343 & V_334 )
V_344 = V_346 ;
else if ( V_343 & V_335 )
V_344 = V_345 | V_346 ;
else
V_344 = 0 ;
return V_344 ;
}
static T_1 F_104 ( T_1 V_339 )
{
T_1 V_340 = 0 ;
if ( V_339 & V_345 ) {
V_340 |= V_335 ;
if ( ! ( V_339 & V_346 ) )
V_340 |= V_334 ;
} else if ( V_339 & V_346 )
V_340 |= V_334 ;
return V_340 ;
}
static T_4 F_105 ( T_3 V_347 , T_3 V_348 )
{
T_4 V_349 = 0 ;
if ( V_347 & V_348 & V_345 ) {
V_349 = V_334 | V_335 ;
} else if ( V_347 & V_348 & V_346 ) {
if ( V_347 & V_345 )
V_349 = V_335 ;
if ( V_348 & V_345 )
V_349 = V_334 ;
}
return V_349 ;
}
static void F_106 ( struct V_4 * V_5 , T_1 V_347 , T_1 V_348 )
{
T_4 V_350 ;
T_4 V_340 = 0 ;
T_1 V_351 = V_5 -> V_352 ;
T_1 V_353 = V_5 -> V_354 ;
if ( F_23 ( V_5 , V_263 ) )
V_350 = V_5 -> V_211 -> V_212 [ V_213 ] -> V_350 ;
else
V_350 = V_5 -> V_327 . V_350 ;
if ( V_350 == V_355 && F_23 ( V_5 , V_356 ) ) {
if ( V_5 -> V_178 & V_357 )
V_340 = F_105 ( V_347 , V_348 ) ;
else
V_340 = F_107 ( V_347 , V_348 ) ;
} else
V_340 = V_5 -> V_327 . V_340 ;
V_5 -> V_327 . V_333 = V_340 ;
if ( V_340 & V_335 )
V_5 -> V_352 |= V_358 ;
else
V_5 -> V_352 &= ~ V_358 ;
if ( V_351 != V_5 -> V_352 )
F_31 ( V_359 , V_5 -> V_352 ) ;
if ( V_340 & V_334 )
V_5 -> V_354 |= V_360 ;
else
V_5 -> V_354 &= ~ V_360 ;
if ( V_353 != V_5 -> V_354 )
F_31 ( V_361 , V_5 -> V_354 ) ;
}
static void F_108 ( struct V_362 * V_111 )
{
T_4 V_363 , V_364 = 0 ;
T_1 V_365 , V_366 , V_367 ;
struct V_4 * V_5 = F_109 ( V_111 ) ;
struct V_209 * V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
F_69 ( & V_5 -> V_207 ) ;
V_365 = V_5 -> V_365 & ~ ( V_368 |
V_369 ) ;
V_363 = V_5 -> V_327 . V_333 ;
if ( V_210 -> V_326 ) {
V_366 = 0 ;
V_367 = 0 ;
if ( V_210 -> V_370 == V_330 || V_210 -> V_370 == V_371 )
V_365 |= V_372 ;
else if ( V_210 -> V_370 == V_329 ||
F_30 ( V_5 ) != V_256 )
V_365 |= V_373 ;
else
V_365 |= V_372 ;
if ( V_210 -> V_374 == V_375 )
V_365 |= V_369 ;
else {
V_366 = F_110 (
V_5 -> V_327 . V_340 ) ;
if ( V_210 -> V_376 )
V_367 = V_377 ;
if ( V_210 -> V_378 )
V_367 |= V_379 ;
}
F_106 ( V_5 , V_366 , V_367 ) ;
} else
V_365 |= V_373 ;
if ( V_365 != V_5 -> V_365 ) {
V_5 -> V_365 = V_365 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
}
if ( F_30 ( V_5 ) == V_256 ) {
if ( V_210 -> V_370 == V_371 )
F_46 ( V_381 ,
V_382 |
V_383 ) ;
else
F_46 ( V_381 , V_383 ) ;
}
if ( V_210 -> V_370 == V_329 && V_210 -> V_374 == V_375 )
F_46 ( V_384 ,
( ( 2 << V_385 ) |
( 6 << V_386 ) |
( 0xff << V_387 ) ) ) ;
else
F_46 ( V_384 ,
( ( 2 << V_385 ) |
( 6 << V_386 ) |
( 32 << V_387 ) ) ) ;
if ( V_210 -> V_326 != V_5 -> V_388 ||
V_210 -> V_370 != V_5 -> V_327 . V_328 ||
V_210 -> V_374 != V_5 -> V_327 . V_331 ||
V_363 != V_5 -> V_327 . V_333 )
V_364 = 1 ;
V_5 -> V_388 = V_210 -> V_326 ;
V_5 -> V_327 . V_328 = V_210 -> V_370 ;
V_5 -> V_327 . V_331 = V_210 -> V_374 ;
F_70 ( & V_5 -> V_207 ) ;
if ( V_364 )
F_98 ( V_5 ) ;
}
static int F_111 ( struct V_4 * V_5 )
{
struct V_209 * V_210 ;
if ( V_5 -> V_178 & V_389 )
return 0 ;
F_67 ( V_5 ) ;
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
V_210 = F_112 ( V_5 -> V_111 , F_113 ( & V_210 -> V_111 ) ,
F_108 , V_210 -> V_226 ) ;
if ( F_114 ( V_210 ) ) {
F_115 ( & V_5 -> V_12 -> V_111 , L_16 ) ;
return F_116 ( V_210 ) ;
}
switch ( V_210 -> V_226 ) {
case V_282 :
case V_227 :
if ( ! ( V_5 -> V_178 & V_390 ) ) {
V_210 -> V_391 &= ( V_392 |
V_393 |
V_394 ) ;
break;
}
case V_291 :
V_210 -> V_391 &= ( V_395 |
V_393 |
V_394 ) ;
break;
default:
F_117 ( V_5 -> V_211 -> V_212 [ V_213 ] ) ;
return - V_64 ;
}
V_5 -> V_178 |= V_389 ;
V_210 -> V_396 = V_210 -> V_391 ;
return 0 ;
}
static void F_118 ( struct V_4 * V_5 )
{
struct V_209 * V_210 ;
if ( ! ( V_5 -> V_178 & V_389 ) )
return;
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
if ( V_5 -> V_178 & V_397 ) {
V_5 -> V_178 &= ~ V_397 ;
V_210 -> V_370 = V_5 -> V_327 . V_370 ;
V_210 -> V_374 = V_5 -> V_327 . V_374 ;
V_210 -> V_350 = V_5 -> V_327 . V_350 ;
V_210 -> V_396 = V_5 -> V_327 . V_396 ;
}
F_119 ( V_210 ) ;
F_120 ( V_210 ) ;
}
static void F_121 ( struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_178 & V_389 ) )
return;
F_122 ( V_5 -> V_211 -> V_212 [ V_213 ] ) ;
}
static void F_123 ( struct V_4 * V_5 )
{
if ( V_5 -> V_178 & V_389 ) {
F_117 ( V_5 -> V_211 -> V_212 [ V_213 ] ) ;
V_5 -> V_178 &= ~ V_389 ;
}
}
static int F_124 ( struct V_4 * V_5 )
{
int V_75 ;
T_1 V_7 ;
if ( V_5 -> V_178 & V_179 )
return 0 ;
if ( ( V_5 -> V_215 & V_398 ) == V_399 ) {
V_75 = F_65 ( V_5 ,
V_196 ,
V_400 |
0x4c20 ) ;
goto V_186;
}
V_75 = F_64 ( V_5 ,
V_196 , & V_7 ) ;
if ( V_75 )
return V_75 ;
V_7 |= V_400 ;
V_75 = F_65 ( V_5 ,
V_196 , V_7 ) ;
V_186:
return V_75 ;
}
static void F_125 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_401 ;
if ( ! F_57 ( V_5 , V_402 , & V_401 ) ) {
T_1 V_403 ;
F_59 ( V_5 , V_402 ,
V_401 | V_404 ) ;
if ( ! F_57 ( V_5 , V_405 , & V_403 ) ) {
if ( V_195 )
V_403 |= V_406 ;
else
V_403 &= ~ V_406 ;
F_59 ( V_5 , V_405 , V_403 ) ;
}
F_59 ( V_5 , V_402 , V_401 ) ;
}
}
static void F_126 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_161 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
( F_23 ( V_5 , 5717_PLUS ) &&
( V_5 -> V_178 & V_302 ) ) )
return;
if ( V_5 -> V_178 & V_179 ) {
F_125 ( V_5 , V_195 ) ;
return;
}
V_161 = V_407 |
V_408 |
V_409 |
V_410 |
V_411 |
V_412 ;
if ( F_30 ( V_5 ) != V_413 || ! V_195 )
V_161 |= V_414 ;
F_59 ( V_5 , V_415 , V_161 ) ;
V_161 = V_407 |
V_416 |
V_417 ;
if ( V_195 )
V_161 |= V_418 ;
F_59 ( V_5 , V_415 , V_161 ) ;
}
static void F_127 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_403 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
( V_5 -> V_178 & V_357 ) )
return;
if ( V_5 -> V_178 & V_179 ) {
T_1 V_419 ;
if ( ! F_57 ( V_5 , V_402 , & V_419 ) ) {
T_1 V_161 = V_420 ;
F_59 ( V_5 , V_402 ,
V_419 | V_404 ) ;
if ( ! F_57 ( V_5 , V_161 , & V_403 ) ) {
if ( V_195 )
V_403 |= V_421 ;
else
V_403 &= ~ V_421 ;
F_59 ( V_5 , V_161 , V_403 ) ;
}
F_59 ( V_5 , V_402 , V_419 ) ;
}
} else {
int V_56 ;
V_56 = F_64 ( V_5 ,
V_192 , & V_403 ) ;
if ( ! V_56 ) {
if ( V_195 )
V_403 |= V_422 ;
else
V_403 &= ~ V_422 ;
F_65 ( V_5 ,
V_192 , V_403 ) ;
}
}
}
static void F_128 ( struct V_4 * V_5 )
{
int V_56 ;
T_1 V_7 ;
if ( V_5 -> V_178 & V_423 )
return;
V_56 = F_64 ( V_5 , V_192 , & V_7 ) ;
if ( ! V_56 )
F_65 ( V_5 , V_192 ,
V_7 | V_424 ) ;
}
static void F_129 ( struct V_4 * V_5 )
{
T_1 V_425 , V_403 ;
if ( ! V_5 -> V_426 )
return;
V_425 = V_5 -> V_426 ;
if ( F_66 ( V_5 , true ) )
return;
V_403 = ( ( V_425 & V_427 ) >> V_428 ) ;
V_403 |= V_429 ;
F_63 ( V_5 , V_430 , V_403 ) ;
V_403 = ( ( V_425 & V_431 ) >> V_432 ) |
( ( V_425 & V_433 ) >> V_434 ) ;
F_63 ( V_5 , V_435 , V_403 ) ;
V_403 = ( ( V_425 & V_436 ) >> V_437 ) ;
V_403 |= V_438 ;
F_63 ( V_5 , V_439 , V_403 ) ;
V_403 = ( ( V_425 & V_440 ) >> V_441 ) ;
F_63 ( V_5 , V_442 , V_403 ) ;
V_403 = ( ( V_425 & V_443 ) >> V_444 ) ;
F_63 ( V_5 , V_445 , V_403 ) ;
V_403 = ( ( V_425 & V_446 ) >> V_447 ) |
( ( V_425 & V_448 ) >> V_449 ) ;
F_63 ( V_5 , V_450 , V_403 ) ;
F_66 ( V_5 , false ) ;
}
static void F_130 ( struct V_4 * V_5 , struct V_451 * V_452 )
{
T_1 V_7 ;
struct V_451 * V_453 = & V_5 -> V_452 ;
if ( ! ( V_5 -> V_178 & V_336 ) )
return;
if ( V_452 )
V_453 = V_452 ;
if ( F_61 ( V_5 , V_454 , V_455 , & V_7 ) )
return;
if ( V_7 == V_456 ||
V_7 == V_457 ) {
V_453 -> V_458 = 1 ;
} else
V_453 -> V_458 = 0 ;
if ( F_61 ( V_5 , V_454 , V_459 , & V_7 ) )
return;
V_453 -> V_460 = F_131 ( V_7 ) ;
if ( F_61 ( V_5 , V_454 , V_461 , & V_7 ) )
return;
V_453 -> V_462 = ! ! V_7 ;
V_453 -> V_463 = F_131 ( V_7 ) ;
V_7 = F_33 ( V_464 ) ;
V_453 -> V_465 = ! ! ( V_7 & V_466 ) ;
V_453 -> V_467 = F_33 ( V_468 ) & 0xffff ;
}
static void F_132 ( struct V_4 * V_5 , bool V_469 )
{
T_1 V_7 ;
if ( ! ( V_5 -> V_178 & V_336 ) )
return;
V_5 -> V_337 = 0 ;
if ( V_5 -> V_327 . V_350 == V_355 &&
V_469 &&
V_5 -> V_327 . V_331 == V_332 &&
( V_5 -> V_327 . V_328 == V_330 ||
V_5 -> V_327 . V_328 == V_329 ) ) {
T_1 V_470 ;
if ( V_5 -> V_327 . V_328 == V_329 )
V_470 = V_471 ;
else
V_470 = V_472 ;
F_46 ( V_473 , V_470 ) ;
F_130 ( V_5 , NULL ) ;
if ( V_5 -> V_452 . V_458 )
V_5 -> V_337 = 2 ;
}
if ( ! V_5 -> V_337 ) {
if ( V_469 &&
! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , V_474 , 0x0000 ) ;
F_66 ( V_5 , false ) ;
}
V_7 = F_33 ( V_464 ) ;
F_46 ( V_464 , V_7 & ~ V_475 ) ;
}
}
static void F_133 ( struct V_4 * V_5 )
{
T_1 V_7 ;
if ( V_5 -> V_327 . V_328 == V_329 &&
( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_23 ( V_5 , 57765_CLASS ) ) &&
! F_66 ( V_5 , true ) ) {
V_7 = V_478 |
V_479 ;
F_63 ( V_5 , V_474 , V_7 ) ;
F_66 ( V_5 , false ) ;
}
V_7 = F_33 ( V_464 ) ;
F_46 ( V_464 , V_7 | V_475 ) ;
}
static int F_134 ( struct V_4 * V_5 )
{
int V_200 = 100 ;
while ( V_200 -- ) {
T_1 V_480 ;
if ( ! F_57 ( V_5 , V_481 , & V_480 ) ) {
if ( ( V_480 & 0x1000 ) == 0 )
break;
}
}
if ( V_200 < 0 )
return - V_67 ;
return 0 ;
}
static int F_135 ( struct V_4 * V_5 , int * V_482 )
{
static const T_1 V_483 [ 4 ] [ 6 ] = {
{ 0x00005555 , 0x00000005 , 0x00002aaa , 0x0000000a , 0x00003456 , 0x00000003 } ,
{ 0x00002aaa , 0x0000000a , 0x00003333 , 0x00000003 , 0x0000789a , 0x00000005 } ,
{ 0x00005a5a , 0x00000005 , 0x00002a6a , 0x0000000a , 0x00001bcd , 0x00000003 } ,
{ 0x00002a5a , 0x0000000a , 0x000033c3 , 0x00000003 , 0x00002ef1 , 0x00000005 }
} ;
int V_484 ;
for ( V_484 = 0 ; V_484 < 4 ; V_484 ++ ) {
int V_42 ;
F_59 ( V_5 , V_189 ,
( V_484 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_481 , 0x0002 ) ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ )
F_59 ( V_5 , V_190 ,
V_483 [ V_484 ] [ V_42 ] ) ;
F_59 ( V_5 , V_481 , 0x0202 ) ;
if ( F_134 ( V_5 ) ) {
* V_482 = 1 ;
return - V_67 ;
}
F_59 ( V_5 , V_189 ,
( V_484 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_481 , 0x0082 ) ;
if ( F_134 ( V_5 ) ) {
* V_482 = 1 ;
return - V_67 ;
}
F_59 ( V_5 , V_481 , 0x0802 ) ;
if ( F_134 ( V_5 ) ) {
* V_482 = 1 ;
return - V_67 ;
}
for ( V_42 = 0 ; V_42 < 6 ; V_42 += 2 ) {
T_1 V_485 , V_486 ;
if ( F_57 ( V_5 , V_190 , & V_485 ) ||
F_57 ( V_5 , V_190 , & V_486 ) ||
F_134 ( V_5 ) ) {
* V_482 = 1 ;
return - V_67 ;
}
V_485 &= 0x7fff ;
V_486 &= 0x000f ;
if ( V_485 != V_483 [ V_484 ] [ V_42 ] ||
V_486 != V_483 [ V_484 ] [ V_42 + 1 ] ) {
F_59 ( V_5 , V_189 , 0x000b ) ;
F_59 ( V_5 , V_190 , 0x4001 ) ;
F_59 ( V_5 , V_190 , 0x4005 ) ;
return - V_67 ;
}
}
}
return 0 ;
}
static int F_136 ( struct V_4 * V_5 )
{
int V_484 ;
for ( V_484 = 0 ; V_484 < 4 ; V_484 ++ ) {
int V_42 ;
F_59 ( V_5 , V_189 ,
( V_484 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_481 , 0x0002 ) ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ )
F_59 ( V_5 , V_190 , 0x000 ) ;
F_59 ( V_5 , V_481 , 0x0202 ) ;
if ( F_134 ( V_5 ) )
return - V_67 ;
}
return 0 ;
}
static int F_137 ( struct V_4 * V_5 )
{
T_1 V_487 , V_488 ;
int V_489 , V_490 , V_75 ;
V_489 = 10 ;
V_490 = 1 ;
do {
if ( V_490 ) {
V_75 = F_67 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_490 = 0 ;
}
if ( F_57 ( V_5 , V_491 , & V_487 ) )
continue;
V_487 |= 0x3000 ;
F_59 ( V_5 , V_491 , V_487 ) ;
F_59 ( V_5 , V_202 ,
V_492 | V_493 ) ;
if ( F_57 ( V_5 , V_180 , & V_488 ) )
continue;
F_59 ( V_5 , V_180 ,
V_494 | V_495 ) ;
V_75 = F_66 ( V_5 , true ) ;
if ( V_75 )
return V_75 ;
F_63 ( V_5 , 0x8005 , 0x0800 ) ;
V_75 = F_135 ( V_5 , & V_490 ) ;
if ( ! V_75 )
break;
} while ( -- V_489 );
V_75 = F_136 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_63 ( V_5 , 0x8005 , 0x0000 ) ;
F_59 ( V_5 , V_189 , 0x8200 ) ;
F_59 ( V_5 , V_481 , 0x0000 ) ;
F_66 ( V_5 , false ) ;
F_59 ( V_5 , V_180 , V_488 ) ;
if ( ! F_57 ( V_5 , V_491 , & V_487 ) ) {
V_487 &= ~ 0x3000 ;
F_59 ( V_5 , V_491 , V_487 ) ;
} else if ( ! V_75 )
V_75 = - V_67 ;
return V_75 ;
}
static void F_138 ( struct V_4 * V_5 )
{
F_139 ( V_5 -> V_111 ) ;
V_5 -> V_338 = false ;
}
static void F_140 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_305 ) )
F_141 ( V_5 -> V_111 ,
L_17 ) ;
}
static int F_142 ( struct V_4 * V_5 )
{
T_1 V_7 , V_496 ;
int V_75 ;
if ( F_30 ( V_5 ) == V_36 ) {
V_7 = F_33 ( V_497 ) ;
F_31 ( V_497 , V_7 & ~ V_498 ) ;
F_24 ( 40 ) ;
}
V_75 = F_57 ( V_5 , V_299 , & V_7 ) ;
V_75 |= F_57 ( V_5 , V_299 , & V_7 ) ;
if ( V_75 != 0 )
return - V_67 ;
if ( F_143 ( V_5 -> V_111 ) && V_5 -> V_338 ) {
F_139 ( V_5 -> V_111 ) ;
F_98 ( V_5 ) ;
}
if ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ) {
V_75 = F_137 ( V_5 ) ;
if ( V_75 )
return V_75 ;
goto V_502;
}
V_496 = 0 ;
if ( F_30 ( V_5 ) == V_413 &&
F_144 ( V_5 ) != V_503 ) {
V_496 = F_33 ( V_504 ) ;
if ( V_496 & V_505 )
F_46 ( V_504 ,
V_496 & ~ V_505 ) ;
}
V_75 = F_67 ( V_5 ) ;
if ( V_75 )
return V_75 ;
if ( V_496 & V_505 ) {
V_7 = V_506 | V_507 ;
F_63 ( V_5 , V_508 , V_7 ) ;
F_46 ( V_504 , V_496 ) ;
}
if ( F_144 ( V_5 ) == V_503 ||
F_144 ( V_5 ) == V_509 ) {
V_7 = F_33 ( V_510 ) ;
if ( ( V_7 & V_511 ) ==
V_512 ) {
V_7 &= ~ V_511 ;
F_24 ( 40 ) ;
F_31 ( V_510 , V_7 ) ;
}
}
if ( F_23 ( V_5 , 5717_PLUS ) &&
( V_5 -> V_178 & V_302 ) )
return 0 ;
F_129 ( V_5 ) ;
if ( V_5 -> V_178 & V_513 )
F_126 ( V_5 , true ) ;
else
F_126 ( V_5 , false ) ;
V_502:
if ( ( V_5 -> V_178 & V_514 ) &&
! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , 0x201f , 0x2aaa ) ;
F_63 ( V_5 , 0x000a , 0x0323 ) ;
F_66 ( V_5 , false ) ;
}
if ( V_5 -> V_178 & V_515 ) {
F_59 ( V_5 , V_415 , 0x8d68 ) ;
F_59 ( V_5 , V_415 , 0x8d68 ) ;
}
if ( V_5 -> V_178 & V_516 ) {
if ( ! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , 0x000a , 0x310b ) ;
F_63 ( V_5 , 0x201f , 0x9506 ) ;
F_63 ( V_5 , 0x401f , 0x14e2 ) ;
F_66 ( V_5 , false ) ;
}
} else if ( V_5 -> V_178 & V_517 ) {
if ( ! F_66 ( V_5 , true ) ) {
F_59 ( V_5 , V_189 , 0x000a ) ;
if ( V_5 -> V_178 & V_518 ) {
F_59 ( V_5 , V_190 , 0x110b ) ;
F_59 ( V_5 , V_519 ,
V_520 | 0x4 ) ;
} else
F_59 ( V_5 , V_190 , 0x010b ) ;
F_66 ( V_5 , false ) ;
}
}
if ( ( V_5 -> V_215 & V_398 ) == V_399 ) {
F_65 ( V_5 , V_196 , 0x4c20 ) ;
} else if ( F_23 ( V_5 , V_521 ) ) {
V_75 = F_64 ( V_5 ,
V_196 , & V_7 ) ;
if ( ! V_75 )
F_65 ( V_5 , V_196 ,
V_7 | V_522 ) ;
}
if ( F_23 ( V_5 , V_521 ) ) {
if ( ! F_57 ( V_5 , V_491 , & V_7 ) )
F_59 ( V_5 , V_491 ,
V_7 | V_523 ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
F_59 ( V_5 , V_524 , 0x12 ) ;
}
if ( F_76 ( V_5 ) == V_525 )
F_63 ( V_5 , 0xffb , 0x4000 ) ;
F_127 ( V_5 , true ) ;
F_128 ( V_5 ) ;
return 0 ;
}
static inline T_1 F_145 ( struct V_4 * V_5 , T_1 V_526 )
{
T_1 V_57 , V_527 ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 )
V_57 = F_12 ( V_5 , V_528 ) ;
else
V_57 = F_33 ( V_529 ) ;
V_527 = V_530 + 4 * V_5 -> V_54 ;
V_57 &= ~ ( V_531 << V_527 ) ;
V_57 |= ( V_526 << V_527 ) ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 )
F_11 ( V_5 , V_528 , V_57 ) ;
else
F_46 ( V_529 , V_57 ) ;
return V_57 >> V_530 ;
}
static inline int F_146 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_532 ) )
return 0 ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) {
if ( F_35 ( V_5 , V_49 ) )
return - V_208 ;
F_145 ( V_5 , V_534 ) ;
F_55 ( V_136 , V_5 -> V_22 ,
V_535 ) ;
F_37 ( V_5 , V_49 ) ;
} else {
F_55 ( V_136 , V_5 -> V_22 ,
V_535 ) ;
}
return 0 ;
}
static void F_147 ( struct V_4 * V_5 )
{
T_1 V_22 ;
if ( ! F_23 ( V_5 , V_532 ) ||
F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 )
return;
V_22 = V_5 -> V_22 | V_538 ;
F_55 ( V_136 ,
V_22 | V_539 ,
V_535 ) ;
F_55 ( V_136 ,
V_22 ,
V_535 ) ;
F_55 ( V_136 ,
V_22 | V_539 ,
V_535 ) ;
}
static void F_148 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_532 ) )
return;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) {
F_55 ( V_136 , V_5 -> V_22 |
( V_540 |
V_538 |
V_541 |
V_542 |
V_539 ) ,
V_535 ) ;
} else if ( V_5 -> V_12 -> V_543 == V_544 ||
V_5 -> V_12 -> V_543 == V_545 ) {
T_1 V_22 = V_540 |
V_538 |
V_541 |
V_542 |
V_539 |
V_5 -> V_22 ;
F_55 ( V_136 , V_22 ,
V_535 ) ;
V_22 |= V_546 ;
F_55 ( V_136 , V_22 ,
V_535 ) ;
V_22 &= ~ V_542 ;
F_55 ( V_136 , V_22 ,
V_535 ) ;
} else {
T_1 V_547 ;
T_1 V_22 = 0 ;
if ( F_30 ( V_5 ) == V_548 ) {
V_22 |= V_549 ;
F_55 ( V_136 , V_5 -> V_22 |
V_22 ,
V_535 ) ;
}
V_547 = V_5 -> V_550 &
V_551 ;
V_22 |= V_540 |
V_538 |
V_541 |
V_539 |
V_546 ;
if ( V_547 ) {
V_22 &= ~ ( V_541 |
V_546 ) ;
}
F_55 ( V_136 ,
V_5 -> V_22 | V_22 ,
V_535 ) ;
V_22 |= V_542 ;
F_55 ( V_136 ,
V_5 -> V_22 | V_22 ,
V_535 ) ;
if ( ! V_547 ) {
V_22 &= ~ V_546 ;
F_55 ( V_136 ,
V_5 -> V_22 | V_22 ,
V_535 ) ;
}
}
}
static void F_149 ( struct V_4 * V_5 , bool V_552 )
{
T_1 V_553 = 0 ;
if ( F_35 ( V_5 , V_49 ) )
return;
if ( F_23 ( V_5 , V_305 ) || F_23 ( V_5 , V_60 ) || V_552 )
V_553 = V_554 ;
V_553 = F_145 ( V_5 , V_553 ) ;
if ( V_553 & V_555 )
goto V_186;
if ( V_553 & V_556 )
F_148 ( V_5 ) ;
else
F_147 ( V_5 ) ;
V_186:
F_37 ( V_5 , V_49 ) ;
}
static void F_150 ( struct V_4 * V_5 , bool V_557 )
{
bool V_558 = false ;
if ( ! F_23 ( V_5 , V_532 ) || F_23 ( V_5 , 57765_CLASS ) )
return;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) {
F_149 ( V_5 , V_557 ?
F_23 ( V_5 , V_112 ) != 0 : 0 ) ;
return;
}
if ( V_5 -> V_559 && V_5 -> V_559 != V_5 -> V_12 ) {
struct V_362 * V_560 ;
V_560 = F_151 ( V_5 -> V_559 ) ;
if ( V_560 ) {
struct V_4 * V_561 = F_109 ( V_560 ) ;
if ( F_23 ( V_561 , V_562 ) )
return;
if ( ( V_557 && F_23 ( V_561 , V_112 ) ) ||
F_23 ( V_561 , V_305 ) )
V_558 = true ;
}
}
if ( ( V_557 && F_23 ( V_5 , V_112 ) ) ||
F_23 ( V_5 , V_305 ) )
V_558 = true ;
if ( V_558 )
F_148 ( V_5 ) ;
else
F_147 ( V_5 ) ;
}
static int F_152 ( struct V_4 * V_5 , T_1 V_370 )
{
if ( V_5 -> V_563 == V_564 )
return 1 ;
else if ( ( V_5 -> V_215 & V_398 ) == V_565 ) {
if ( V_370 != V_371 )
return 1 ;
} else if ( V_370 == V_371 )
return 1 ;
return 0 ;
}
static bool F_153 ( struct V_4 * V_5 )
{
switch ( F_30 ( V_5 ) ) {
case V_536 :
case V_500 :
return true ;
case V_566 :
if ( V_5 -> V_178 & V_302 )
return true ;
return false ;
case V_476 :
if ( ! V_5 -> V_54 )
return true ;
return false ;
case V_477 :
case V_533 :
if ( ( V_5 -> V_178 & V_567 ) &&
! V_5 -> V_54 )
return true ;
return false ;
}
return false ;
}
static bool F_154 ( struct V_4 * V_5 )
{
switch ( F_30 ( V_5 ) ) {
case V_477 :
case V_533 :
if ( ( V_5 -> V_178 & V_302 ) &&
! V_5 -> V_54 )
return true ;
return false ;
}
return false ;
}
static void F_155 ( struct V_4 * V_5 , bool V_568 )
{
T_1 V_7 ;
if ( V_5 -> V_178 & V_569 )
return;
if ( V_5 -> V_178 & V_567 ) {
if ( F_30 ( V_5 ) == V_500 ) {
T_1 V_570 = F_33 ( V_571 ) ;
T_1 V_572 = F_33 ( V_573 ) ;
V_570 |=
V_574 | V_575 ;
F_46 ( V_571 , V_570 ) ;
F_46 ( V_573 , V_572 | ( 1 << 15 ) ) ;
}
return;
}
if ( F_30 ( V_5 ) == V_36 ) {
F_67 ( V_5 ) ;
V_7 = F_33 ( V_497 ) ;
F_31 ( V_497 , V_7 | V_498 ) ;
F_24 ( 40 ) ;
return;
} else if ( V_5 -> V_178 & V_179 ) {
T_1 V_401 ;
if ( ! F_57 ( V_5 , V_402 , & V_401 ) ) {
T_1 V_403 ;
F_59 ( V_5 , V_300 , 0 ) ;
F_59 ( V_5 , V_202 ,
V_576 | V_577 ) ;
F_59 ( V_5 , V_402 ,
V_401 | V_404 ) ;
if ( ! F_57 ( V_5 , V_578 , & V_403 ) ) {
V_403 |= V_579 ;
F_59 ( V_5 ,
V_578 ,
V_403 ) ;
}
F_59 ( V_5 , V_402 , V_401 ) ;
}
return;
} else if ( V_568 ) {
if ( ! F_154 ( V_5 ) )
F_59 ( V_5 , V_491 ,
V_580 ) ;
V_7 = V_581 |
V_582 |
V_583 ;
F_65 ( V_5 , V_584 , V_7 ) ;
}
if ( F_153 ( V_5 ) )
return;
if ( F_144 ( V_5 ) == V_503 ||
F_144 ( V_5 ) == V_509 ) {
V_7 = F_33 ( V_510 ) ;
V_7 &= ~ V_511 ;
V_7 |= V_512 ;
F_31 ( V_510 , V_7 ) ;
}
F_59 ( V_5 , V_202 , V_280 ) ;
}
static int F_156 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_585 ) ) {
int V_42 ;
if ( V_5 -> V_586 == 0 ) {
F_46 ( V_587 , V_588 ) ;
for ( V_42 = 0 ; V_42 < 8000 ; V_42 ++ ) {
if ( F_33 ( V_587 ) & V_589 )
break;
F_24 ( 20 ) ;
}
if ( V_42 == 8000 ) {
F_46 ( V_587 , V_590 ) ;
return - V_82 ;
}
}
V_5 -> V_586 ++ ;
}
return 0 ;
}
static void F_157 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_585 ) ) {
if ( V_5 -> V_586 > 0 )
V_5 -> V_586 -- ;
if ( V_5 -> V_586 == 0 )
F_31 ( V_587 , V_590 ) ;
}
}
static void F_158 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_591 ) ) {
T_1 V_592 = F_33 ( V_593 ) ;
F_46 ( V_593 , V_592 | V_594 ) ;
}
}
static void F_159 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_591 ) ) {
T_1 V_592 = F_33 ( V_593 ) ;
F_46 ( V_593 , V_592 & ~ V_594 ) ;
}
}
static int F_160 ( struct V_4 * V_5 ,
T_1 V_595 , T_1 * V_7 )
{
T_1 V_596 ;
int V_42 ;
if ( V_595 > V_597 || ( V_595 % 4 ) != 0 )
return - V_64 ;
V_596 = F_33 ( V_598 ) & ~ ( V_597 |
V_599 |
V_600 ) ;
F_46 ( V_598 ,
V_596 |
( 0 << V_601 ) |
( ( V_595 << V_602 ) &
V_597 ) |
V_600 | V_603 ) ;
for ( V_42 = 0 ; V_42 < 1000 ; V_42 ++ ) {
V_596 = F_33 ( V_598 ) ;
if ( V_596 & V_604 )
break;
F_161 ( 1 ) ;
}
if ( ! ( V_596 & V_604 ) )
return - V_67 ;
V_596 = F_33 ( V_605 ) ;
* V_7 = F_162 ( V_596 ) ;
return 0 ;
}
static int F_163 ( struct V_4 * V_5 , T_1 V_606 )
{
int V_42 ;
F_46 ( V_607 , V_606 ) ;
for ( V_42 = 0 ; V_42 < V_608 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( F_33 ( V_607 ) & V_609 ) {
F_24 ( 10 ) ;
break;
}
}
if ( V_42 == V_608 )
return - V_67 ;
return 0 ;
}
static T_1 F_164 ( struct V_4 * V_5 , T_1 V_184 )
{
if ( F_23 ( V_5 , V_585 ) &&
F_23 ( V_5 , V_610 ) &&
F_23 ( V_5 , V_611 ) &&
! F_23 ( V_5 , V_612 ) &&
( V_5 -> V_613 == V_614 ) )
V_184 = ( ( V_184 / V_5 -> V_615 ) <<
V_616 ) +
( V_184 % V_5 -> V_615 ) ;
return V_184 ;
}
static T_1 F_165 ( struct V_4 * V_5 , T_1 V_184 )
{
if ( F_23 ( V_5 , V_585 ) &&
F_23 ( V_5 , V_610 ) &&
F_23 ( V_5 , V_611 ) &&
! F_23 ( V_5 , V_612 ) &&
( V_5 -> V_613 == V_614 ) )
V_184 = ( ( V_184 >> V_616 ) *
V_5 -> V_615 ) +
( V_184 & ( ( 1 << V_616 ) - 1 ) ) ;
return V_184 ;
}
static int F_166 ( struct V_4 * V_5 , T_1 V_595 , T_1 * V_7 )
{
int V_56 ;
if ( ! F_23 ( V_5 , V_585 ) )
return F_160 ( V_5 , V_595 , V_7 ) ;
V_595 = F_164 ( V_5 , V_595 ) ;
if ( V_595 > V_617 )
return - V_64 ;
V_56 = F_156 ( V_5 ) ;
if ( V_56 )
return V_56 ;
F_158 ( V_5 ) ;
F_46 ( V_618 , V_595 ) ;
V_56 = F_163 ( V_5 , V_619 | V_620 |
V_621 | V_622 | V_609 ) ;
if ( V_56 == 0 )
* V_7 = F_33 ( V_623 ) ;
F_159 ( V_5 ) ;
F_157 ( V_5 ) ;
return V_56 ;
}
static int F_167 ( struct V_4 * V_5 , T_1 V_595 , T_5 * V_7 )
{
T_1 V_624 ;
int V_625 = F_166 ( V_5 , V_595 , & V_624 ) ;
if ( ! V_625 )
* V_7 = F_168 ( V_624 ) ;
return V_625 ;
}
static int F_169 ( struct V_4 * V_5 ,
T_1 V_595 , T_1 V_74 , T_4 * V_626 )
{
int V_42 , V_627 , V_628 = 0 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 ) {
T_1 V_184 ;
T_5 V_72 ;
V_184 = V_595 + V_42 ;
memcpy ( & V_72 , V_626 + V_42 , 4 ) ;
F_46 ( V_605 , F_162 ( F_170 ( V_72 ) ) ) ;
V_7 = F_33 ( V_598 ) ;
F_46 ( V_598 , V_7 | V_604 ) ;
V_7 &= ~ ( V_597 | V_599 |
V_600 ) ;
F_46 ( V_598 , V_7 |
( 0 << V_601 ) |
( V_184 & V_597 ) |
V_603 |
V_629 ) ;
for ( V_627 = 0 ; V_627 < 1000 ; V_627 ++ ) {
V_7 = F_33 ( V_598 ) ;
if ( V_7 & V_604 )
break;
F_161 ( 1 ) ;
}
if ( ! ( V_7 & V_604 ) ) {
V_628 = - V_67 ;
break;
}
}
return V_628 ;
}
static int F_171 ( struct V_4 * V_5 , T_1 V_595 , T_1 V_74 ,
T_4 * V_626 )
{
int V_56 = 0 ;
T_1 V_630 = V_5 -> V_615 ;
T_1 V_631 = V_630 - 1 ;
T_1 V_606 ;
T_4 * V_596 ;
V_596 = F_172 ( V_630 , V_632 ) ;
if ( V_596 == NULL )
return - V_264 ;
while ( V_74 ) {
int V_627 ;
T_1 V_160 , V_633 , V_634 ;
V_160 = V_595 & ~ V_631 ;
for ( V_627 = 0 ; V_627 < V_630 ; V_627 += 4 ) {
V_56 = F_167 ( V_5 , V_160 + V_627 ,
( T_5 * ) ( V_596 + V_627 ) ) ;
if ( V_56 )
break;
}
if ( V_56 )
break;
V_633 = V_595 & V_631 ;
V_634 = V_630 ;
if ( V_74 < V_634 )
V_634 = V_74 ;
V_74 -= V_634 ;
memcpy ( V_596 + V_633 , V_626 , V_634 ) ;
V_595 = V_595 + ( V_630 - V_633 ) ;
F_158 ( V_5 ) ;
V_606 = V_635 | V_620 | V_609 ;
if ( F_163 ( V_5 , V_606 ) )
break;
F_46 ( V_618 , V_160 ) ;
V_606 = V_620 | V_609 | V_636 |
V_621 | V_622 | V_637 ;
if ( F_163 ( V_5 , V_606 ) )
break;
V_606 = V_635 | V_620 | V_609 ;
if ( F_163 ( V_5 , V_606 ) )
break;
for ( V_627 = 0 ; V_627 < V_630 ; V_627 += 4 ) {
T_5 V_72 ;
V_72 = * ( ( T_5 * ) ( V_596 + V_627 ) ) ;
F_46 ( V_638 , F_170 ( V_72 ) ) ;
F_46 ( V_618 , V_160 + V_627 ) ;
V_606 = V_620 | V_609 |
V_636 ;
if ( V_627 == 0 )
V_606 |= V_621 ;
else if ( V_627 == ( V_630 - 4 ) )
V_606 |= V_622 ;
V_56 = F_163 ( V_5 , V_606 ) ;
if ( V_56 )
break;
}
if ( V_56 )
break;
}
V_606 = V_639 | V_620 | V_609 ;
F_163 ( V_5 , V_606 ) ;
F_173 ( V_596 ) ;
return V_56 ;
}
static int F_174 ( struct V_4 * V_5 , T_1 V_595 , T_1 V_74 ,
T_4 * V_626 )
{
int V_42 , V_56 = 0 ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 , V_595 += 4 ) {
T_1 V_633 , V_160 , V_606 ;
T_5 V_72 ;
memcpy ( & V_72 , V_626 + V_42 , 4 ) ;
F_46 ( V_638 , F_170 ( V_72 ) ) ;
V_633 = V_595 % V_5 -> V_615 ;
V_160 = F_164 ( V_5 , V_595 ) ;
V_606 = V_620 | V_609 | V_636 ;
if ( V_633 == 0 || V_42 == 0 )
V_606 |= V_621 ;
if ( V_633 == ( V_5 -> V_615 - 4 ) )
V_606 |= V_622 ;
if ( V_42 == ( V_74 - 4 ) )
V_606 |= V_622 ;
if ( ( V_606 & V_621 ) ||
! F_23 ( V_5 , V_611 ) ||
! F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_618 , V_160 ) ;
if ( F_30 ( V_5 ) != V_640 &&
! F_23 ( V_5 , 5755_PLUS ) &&
( V_5 -> V_613 == V_641 ) &&
( V_606 & V_621 ) ) {
T_1 V_642 ;
V_642 = V_635 | V_620 | V_609 ;
V_56 = F_163 ( V_5 , V_642 ) ;
if ( V_56 )
break;
}
if ( ! F_23 ( V_5 , V_611 ) ) {
V_606 |= ( V_621 | V_622 ) ;
}
V_56 = F_163 ( V_5 , V_606 ) ;
if ( V_56 )
break;
}
return V_56 ;
}
static int F_175 ( struct V_4 * V_5 , T_1 V_595 , T_1 V_74 , T_4 * V_626 )
{
int V_56 ;
if ( F_23 ( V_5 , V_643 ) ) {
F_31 ( V_136 , V_5 -> V_22 &
~ V_539 ) ;
F_24 ( 40 ) ;
}
if ( ! F_23 ( V_5 , V_585 ) ) {
V_56 = F_169 ( V_5 , V_595 , V_74 , V_626 ) ;
} else {
T_1 V_644 ;
V_56 = F_156 ( V_5 ) ;
if ( V_56 )
return V_56 ;
F_158 ( V_5 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_591 ) )
F_46 ( V_645 , 0x406 ) ;
V_644 = F_33 ( V_646 ) ;
F_46 ( V_646 , V_644 | V_647 ) ;
if ( F_23 ( V_5 , V_610 ) || ! F_23 ( V_5 , V_611 ) ) {
V_56 = F_174 ( V_5 , V_595 , V_74 ,
V_626 ) ;
} else {
V_56 = F_171 ( V_5 , V_595 , V_74 ,
V_626 ) ;
}
V_644 = F_33 ( V_646 ) ;
F_46 ( V_646 , V_644 & ~ V_647 ) ;
F_159 ( V_5 ) ;
F_157 ( V_5 ) ;
}
if ( F_23 ( V_5 , V_643 ) ) {
F_31 ( V_136 , V_5 -> V_22 ) ;
F_24 ( 40 ) ;
}
return V_56 ;
}
static int F_176 ( struct V_4 * V_5 , T_1 V_648 )
{
int V_42 ;
const int V_649 = 10000 ;
for ( V_42 = 0 ; V_42 < V_649 ; V_42 ++ ) {
F_46 ( V_648 + V_650 , 0xffffffff ) ;
F_46 ( V_648 + V_651 , V_652 ) ;
if ( F_33 ( V_648 + V_651 ) & V_652 )
break;
if ( F_36 ( V_5 -> V_12 ) )
return - V_67 ;
}
return ( V_42 == V_649 ) ? - V_67 : 0 ;
}
static int F_177 ( struct V_4 * V_5 )
{
int V_628 = F_176 ( V_5 , V_653 ) ;
F_46 ( V_653 + V_650 , 0xffffffff ) ;
F_31 ( V_653 + V_651 , V_652 ) ;
F_24 ( 10 ) ;
return V_628 ;
}
static int F_178 ( struct V_4 * V_5 )
{
return F_176 ( V_5 , V_654 ) ;
}
static void F_179 ( struct V_4 * V_5 , T_1 V_648 )
{
F_46 ( V_648 + V_650 , 0xffffffff ) ;
F_31 ( V_648 + V_651 , 0x00000000 ) ;
}
static void F_180 ( struct V_4 * V_5 )
{
F_179 ( V_5 , V_653 ) ;
}
static int F_181 ( struct V_4 * V_5 , T_1 V_648 )
{
int V_628 ;
F_182 ( V_648 == V_654 && F_23 ( V_5 , 5705_PLUS ) ) ;
if ( F_30 ( V_5 ) == V_36 ) {
T_1 V_7 = F_33 ( V_655 ) ;
F_46 ( V_655 , V_7 | V_656 ) ;
return 0 ;
}
if ( V_648 == V_653 ) {
V_628 = F_177 ( V_5 ) ;
} else {
if ( F_23 ( V_5 , V_322 ) )
return 0 ;
V_628 = F_178 ( V_5 ) ;
}
if ( V_628 ) {
F_183 ( V_5 -> V_111 , L_18 ,
V_657 , V_648 == V_653 ? L_19 : L_20 ) ;
return - V_82 ;
}
if ( F_23 ( V_5 , V_585 ) )
F_46 ( V_587 , V_658 ) ;
return 0 ;
}
static int F_184 ( struct V_4 * V_5 ,
const struct V_659 * V_660 )
{
int V_661 ;
if ( V_5 -> V_661 == 0xffffffff )
V_661 = F_170 ( V_660 -> V_74 ) ;
else
V_661 = V_5 -> V_662 -> V_634 ;
return ( V_661 - V_663 ) / sizeof( T_1 ) ;
}
static int F_185 ( struct V_4 * V_5 , T_1 V_648 ,
T_1 V_664 , int V_665 ,
const struct V_659 * V_660 )
{
int V_75 , V_42 ;
void (* F_186)( struct V_4 * , T_1 , T_1 );
int V_666 = V_5 -> V_662 -> V_634 ;
if ( V_648 == V_654 && F_23 ( V_5 , 5705_PLUS ) ) {
F_183 ( V_5 -> V_111 ,
L_21 ,
V_657 ) ;
return - V_64 ;
}
if ( F_23 ( V_5 , 5705_PLUS ) && F_30 ( V_5 ) != V_667 )
F_186 = F_29 ;
else
F_186 = F_13 ;
if ( F_30 ( V_5 ) != V_667 ) {
int V_668 = F_156 ( V_5 ) ;
V_75 = F_181 ( V_5 , V_648 ) ;
if ( ! V_668 )
F_157 ( V_5 ) ;
if ( V_75 )
goto V_502;
for ( V_42 = 0 ; V_42 < V_665 ; V_42 += sizeof( T_1 ) )
F_186 ( V_5 , V_664 + V_42 , 0 ) ;
F_46 ( V_648 + V_650 , 0xffffffff ) ;
F_46 ( V_648 + V_651 ,
F_33 ( V_648 + V_651 ) | V_652 ) ;
} else {
V_666 -= V_663 ;
V_660 ++ ;
}
do {
T_1 * V_669 = ( T_1 * ) ( V_660 + 1 ) ;
for ( V_42 = 0 ; V_42 < F_184 ( V_5 , V_660 ) ; V_42 ++ )
F_186 ( V_5 , V_664 +
( F_170 ( V_660 -> V_670 ) & 0xffff ) +
( V_42 * sizeof( T_1 ) ) ,
F_170 ( V_669 [ V_42 ] ) ) ;
V_666 -= F_170 ( V_660 -> V_74 ) ;
V_660 = (struct V_659 * )
( ( void * ) V_660 + F_170 ( V_660 -> V_74 ) ) ;
} while ( V_666 > 0 );
V_75 = 0 ;
V_502:
return V_75 ;
}
static int F_187 ( struct V_4 * V_5 , T_1 V_648 , T_1 V_671 )
{
int V_42 ;
const int V_649 = 5 ;
F_46 ( V_648 + V_650 , 0xffffffff ) ;
F_31 ( V_648 + V_672 , V_671 ) ;
for ( V_42 = 0 ; V_42 < V_649 ; V_42 ++ ) {
if ( F_33 ( V_648 + V_672 ) == V_671 )
break;
F_46 ( V_648 + V_650 , 0xffffffff ) ;
F_46 ( V_648 + V_651 , V_652 ) ;
F_31 ( V_648 + V_672 , V_671 ) ;
F_24 ( 1000 ) ;
}
return ( V_42 == V_649 ) ? - V_67 : 0 ;
}
static int F_188 ( struct V_4 * V_5 )
{
const struct V_659 * V_660 ;
int V_75 ;
V_660 = (struct V_659 * ) V_5 -> V_662 -> V_72 ;
V_75 = F_185 ( V_5 , V_653 ,
V_673 , V_674 ,
V_660 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_185 ( V_5 , V_654 ,
V_675 , V_676 ,
V_660 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_187 ( V_5 , V_653 ,
F_170 ( V_660 -> V_670 ) ) ;
if ( V_75 ) {
F_183 ( V_5 -> V_111 , L_22
L_23 , V_657 ,
F_33 ( V_653 + V_672 ) ,
F_170 ( V_660 -> V_670 ) ) ;
return - V_82 ;
}
F_180 ( V_5 ) ;
return 0 ;
}
static int F_189 ( struct V_4 * V_5 )
{
const int V_649 = 1000 ;
int V_42 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < V_649 ; V_42 ++ ) {
if ( F_33 ( V_677 ) == V_678 )
break;
F_24 ( 10 ) ;
}
if ( V_42 == V_649 ) {
F_183 ( V_5 -> V_111 , L_24 ) ;
return - V_67 ;
}
V_7 = F_18 ( V_5 , V_679 ) ;
if ( V_7 & 0xff ) {
F_141 ( V_5 -> V_111 ,
L_25 ) ;
return - V_680 ;
}
return 0 ;
}
static void F_190 ( struct V_4 * V_5 )
{
struct V_659 * V_660 ;
if ( ! F_23 ( V_5 , V_681 ) )
return;
if ( F_189 ( V_5 ) )
return;
if ( ! V_5 -> V_662 )
return;
V_660 = (struct V_659 * ) V_5 -> V_662 -> V_72 ;
if ( F_170 ( V_660 -> V_670 ) != V_682 )
return;
if ( F_177 ( V_5 ) )
return;
F_185 ( V_5 , 0 , V_682 , 0 , V_660 ) ;
F_180 ( V_5 ) ;
}
static int F_191 ( struct V_4 * V_5 )
{
const struct V_659 * V_660 ;
unsigned long V_648 , V_664 , V_665 ;
int V_75 ;
if ( ! F_23 ( V_5 , V_683 ) )
return 0 ;
V_660 = (struct V_659 * ) V_5 -> V_662 -> V_72 ;
V_665 = V_5 -> V_661 ;
if ( F_30 ( V_5 ) == V_501 ) {
V_648 = V_653 ;
V_664 = V_684 ;
} else {
V_648 = V_654 ;
V_664 = V_675 ;
V_665 = V_676 ;
}
V_75 = F_185 ( V_5 , V_648 ,
V_664 , V_665 ,
V_660 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_187 ( V_5 , V_648 ,
F_170 ( V_660 -> V_670 ) ) ;
if ( V_75 ) {
F_183 ( V_5 -> V_111 ,
L_26 ,
V_657 , F_33 ( V_648 + V_672 ) ,
F_170 ( V_660 -> V_670 ) ) ;
return - V_82 ;
}
F_179 ( V_5 , V_648 ) ;
return 0 ;
}
static void F_192 ( struct V_4 * V_5 , bool V_685 )
{
T_1 V_686 , V_687 ;
int V_42 ;
V_686 = ( ( V_5 -> V_111 -> V_688 [ 0 ] << 8 ) |
V_5 -> V_111 -> V_688 [ 1 ] ) ;
V_687 = ( ( V_5 -> V_111 -> V_688 [ 2 ] << 24 ) |
( V_5 -> V_111 -> V_688 [ 3 ] << 16 ) |
( V_5 -> V_111 -> V_688 [ 4 ] << 8 ) |
( V_5 -> V_111 -> V_688 [ 5 ] << 0 ) ) ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
if ( V_42 == 1 && V_685 )
continue;
F_46 ( V_689 + ( V_42 * 8 ) , V_686 ) ;
F_46 ( V_690 + ( V_42 * 8 ) , V_687 ) ;
}
if ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 ) {
for ( V_42 = 0 ; V_42 < 12 ; V_42 ++ ) {
F_46 ( V_691 + ( V_42 * 8 ) , V_686 ) ;
F_46 ( V_692 + ( V_42 * 8 ) , V_687 ) ;
}
}
V_686 = ( V_5 -> V_111 -> V_688 [ 0 ] +
V_5 -> V_111 -> V_688 [ 1 ] +
V_5 -> V_111 -> V_688 [ 2 ] +
V_5 -> V_111 -> V_688 [ 3 ] +
V_5 -> V_111 -> V_688 [ 4 ] +
V_5 -> V_111 -> V_688 [ 5 ] ) &
V_693 ;
F_46 ( V_694 , V_686 ) ;
}
static void F_193 ( struct V_4 * V_5 )
{
F_15 ( V_5 -> V_12 ,
V_119 , V_5 -> V_120 ) ;
}
static int F_194 ( struct V_4 * V_5 )
{
int V_75 ;
F_193 ( V_5 ) ;
V_75 = F_195 ( V_5 -> V_12 , V_695 ) ;
if ( ! V_75 ) {
F_146 ( V_5 ) ;
} else {
F_183 ( V_5 -> V_111 , L_27 ) ;
}
return V_75 ;
}
static int F_196 ( struct V_4 * V_5 )
{
T_1 V_120 ;
bool V_696 , V_568 ;
F_193 ( V_5 ) ;
if ( F_23 ( V_5 , V_697 ) )
F_197 ( V_5 -> V_12 , V_698 ,
V_699 ) ;
V_120 = F_33 ( V_119 ) ;
F_46 ( V_119 ,
V_120 | V_121 ) ;
V_696 = F_44 ( & V_5 -> V_12 -> V_111 ) &&
F_23 ( V_5 , V_112 ) ;
if ( F_23 ( V_5 , V_263 ) ) {
V_568 = false ;
if ( ( V_5 -> V_178 & V_389 ) &&
! ( V_5 -> V_178 & V_397 ) ) {
struct V_209 * V_210 ;
T_1 V_700 , V_396 ;
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
V_5 -> V_178 |= V_397 ;
V_5 -> V_327 . V_370 = V_210 -> V_370 ;
V_5 -> V_327 . V_374 = V_210 -> V_374 ;
V_5 -> V_327 . V_350 = V_210 -> V_350 ;
V_5 -> V_327 . V_396 = V_210 -> V_396 ;
V_396 = V_701 |
V_702 |
V_703 |
V_704 ;
if ( F_23 ( V_5 , V_305 ) || V_696 ) {
if ( F_23 ( V_5 , V_705 ) )
V_396 |=
V_706 |
V_707 |
V_708 ;
else
V_396 |= V_708 ;
}
V_210 -> V_396 = V_396 ;
F_120 ( V_210 ) ;
V_700 = V_210 -> V_214 -> V_215 & V_210 -> V_214 -> V_216 ;
if ( V_700 != V_220 ) {
V_700 &= V_709 ;
if ( V_700 == V_710 ||
V_700 == V_711 ||
V_700 == V_712 )
V_568 = true ;
}
}
} else {
V_568 = true ;
if ( ! ( V_5 -> V_178 & V_397 ) )
V_5 -> V_178 |= V_397 ;
if ( ! ( V_5 -> V_178 & V_357 ) )
F_198 ( V_5 , false ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
T_1 V_7 ;
V_7 = F_33 ( V_655 ) ;
F_46 ( V_655 , V_7 | V_713 ) ;
} else if ( ! F_23 ( V_5 , V_305 ) ) {
int V_42 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_32 ( V_5 , V_714 , & V_7 ) ;
if ( V_7 == ~ V_312 )
break;
F_161 ( 1 ) ;
}
}
if ( F_23 ( V_5 , V_715 ) )
F_29 ( V_5 , V_716 , V_717 |
V_718 |
V_719 |
V_720 ) ;
if ( V_696 ) {
T_1 V_365 ;
if ( ! ( V_5 -> V_178 & V_567 ) ) {
if ( V_568 &&
! ( V_5 -> V_178 & V_179 ) ) {
F_65 ( V_5 ,
V_584 ,
V_721 |
V_581 |
V_722 ) ;
F_24 ( 40 ) ;
}
if ( V_5 -> V_178 & V_302 )
V_365 = V_373 ;
else if ( V_5 -> V_178 &
V_569 ) {
if ( V_5 -> V_327 . V_328 == V_329 )
V_365 = V_373 ;
else
V_365 = V_372 ;
} else
V_365 = V_372 ;
V_365 |= V_5 -> V_365 & V_723 ;
if ( F_30 ( V_5 ) == V_536 ) {
T_1 V_370 = F_23 ( V_5 , V_705 ) ?
V_330 : V_371 ;
if ( F_152 ( V_5 , V_370 ) )
V_365 |= V_723 ;
else
V_365 &= ~ V_723 ;
}
} else {
V_365 = V_724 ;
}
if ( ! F_23 ( V_5 , 5750_PLUS ) )
F_46 ( V_725 , V_5 -> V_563 ) ;
V_365 |= V_726 ;
if ( ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) ) &&
( F_23 ( V_5 , V_305 ) || F_23 ( V_5 , V_60 ) ) )
V_365 |= V_727 ;
if ( F_23 ( V_5 , V_60 ) )
V_365 |= V_728 |
V_729 |
V_730 ;
F_31 ( V_380 , V_365 ) ;
F_24 ( 100 ) ;
F_31 ( V_359 , V_731 ) ;
F_24 ( 10 ) ;
}
if ( ! F_23 ( V_5 , V_705 ) &&
( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) ) {
T_1 V_732 ;
V_732 = V_5 -> V_156 ;
V_732 |= ( V_733 |
V_734 ) ;
F_55 ( V_153 , V_732 | V_159 |
V_735 , 40 ) ;
} else if ( F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_152 ) ||
F_30 ( V_5 ) == V_36 ) {
} else if ( ! ( F_23 ( V_5 , 5750_PLUS ) && F_23 ( V_5 , V_305 ) ) ) {
T_1 V_736 , V_737 ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) {
V_736 = ( V_733 |
V_734 |
V_159 ) ;
V_737 = V_736 | V_158 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_736 = V_157 ;
V_737 = V_736 | V_159 ;
} else {
V_736 = V_159 ;
V_737 = V_736 | V_158 ;
}
F_55 ( V_153 , V_5 -> V_156 | V_736 ,
40 ) ;
F_55 ( V_153 , V_5 -> V_156 | V_737 ,
40 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_738 ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) {
V_738 = ( V_733 |
V_734 |
V_158 ) ;
} else {
V_738 = V_158 ;
}
F_55 ( V_153 ,
V_5 -> V_156 | V_738 , 40 ) ;
}
}
if ( ! ( V_696 ) && ! F_23 ( V_5 , V_305 ) )
F_155 ( V_5 , V_568 ) ;
F_150 ( V_5 , true ) ;
if ( ( ! F_23 ( V_5 , V_322 ) ) &&
( ( F_144 ( V_5 ) == V_739 ) ||
( F_144 ( V_5 ) == V_740 ) ) ) {
T_1 V_7 = F_33 ( 0x7d00 ) ;
V_7 &= ~ ( ( 1 << 16 ) | ( 1 << 4 ) | ( 1 << 2 ) | ( 1 << 1 ) | 1 ) ;
F_46 ( 0x7d00 , V_7 ) ;
if ( ! F_23 ( V_5 , V_305 ) ) {
int V_75 ;
V_75 = F_156 ( V_5 ) ;
F_181 ( V_5 , V_653 ) ;
if ( ! V_75 )
F_157 ( V_5 ) ;
}
}
F_93 ( V_5 , V_110 ) ;
F_42 ( V_5 , V_110 ) ;
return 0 ;
}
static void F_199 ( struct V_4 * V_5 )
{
F_200 ( V_5 -> V_12 , F_23 ( V_5 , V_112 ) ) ;
F_195 ( V_5 -> V_12 , V_741 ) ;
}
static void F_201 ( struct V_4 * V_5 , T_1 V_7 , T_3 * V_370 , T_4 * V_374 )
{
switch ( V_7 & V_742 ) {
case V_743 :
* V_370 = V_371 ;
* V_374 = V_375 ;
break;
case V_744 :
* V_370 = V_371 ;
* V_374 = V_332 ;
break;
case V_745 :
* V_370 = V_330 ;
* V_374 = V_375 ;
break;
case V_746 :
* V_370 = V_330 ;
* V_374 = V_332 ;
break;
case V_747 :
* V_370 = V_329 ;
* V_374 = V_375 ;
break;
case V_748 :
* V_370 = V_329 ;
* V_374 = V_332 ;
break;
default:
if ( V_5 -> V_178 & V_179 ) {
* V_370 = ( V_7 & V_749 ) ? V_330 :
V_371 ;
* V_374 = ( V_7 & V_750 ) ? V_332 :
V_375 ;
break;
}
* V_370 = V_751 ;
* V_374 = V_752 ;
break;
}
}
static int F_202 ( struct V_4 * V_5 , T_1 V_753 , T_1 V_340 )
{
int V_75 = 0 ;
T_1 V_7 , V_754 ;
V_754 = V_755 ;
V_754 |= F_203 ( V_753 ) & V_756 ;
V_754 |= F_110 ( V_340 ) ;
V_75 = F_59 ( V_5 , V_300 , V_754 ) ;
if ( V_75 )
goto V_186;
if ( ! ( V_5 -> V_178 & V_390 ) ) {
V_754 = F_204 ( V_753 ) ;
if ( F_76 ( V_5 ) == V_757 ||
F_76 ( V_5 ) == V_758 )
V_754 |= V_494 | V_495 ;
V_75 = F_59 ( V_5 , V_180 , V_754 ) ;
if ( V_75 )
goto V_186;
}
if ( ! ( V_5 -> V_178 & V_336 ) )
goto V_186;
F_46 ( V_464 ,
F_33 ( V_464 ) & ~ V_475 ) ;
V_75 = F_66 ( V_5 , true ) ;
if ( ! V_75 ) {
T_1 V_759 ;
V_7 = 0 ;
if ( V_753 & V_707 )
V_7 |= V_760 ;
if ( V_753 & V_761 )
V_7 |= V_762 ;
if ( ! V_5 -> V_452 . V_462 ) {
V_7 = 0 ;
V_5 -> V_452 . V_463 = 0 ;
} else {
V_5 -> V_452 . V_463 = V_753 &
( V_707 |
V_761 ) ;
}
V_75 = F_60 ( V_5 , V_454 , V_461 , V_7 ) ;
if ( V_75 )
V_7 = 0 ;
switch ( F_30 ( V_5 ) ) {
case V_476 :
case V_763 :
case V_667 :
case V_477 :
if ( V_7 )
V_7 = V_478 |
V_479 |
V_764 ;
F_63 ( V_5 , V_474 , V_7 ) ;
case V_533 :
case V_765 :
if ( ! F_62 ( V_5 , V_766 , & V_7 ) )
F_63 ( V_5 , V_766 , V_7 |
V_767 ) ;
}
V_759 = F_66 ( V_5 , false ) ;
if ( ! V_75 )
V_75 = V_759 ;
}
V_186:
return V_75 ;
}
static void F_205 ( struct V_4 * V_5 )
{
if ( V_5 -> V_327 . V_350 == V_355 ||
( V_5 -> V_178 & V_397 ) ) {
T_1 V_339 , V_768 ;
if ( ( V_5 -> V_178 & V_397 ) &&
! ( V_5 -> V_178 & V_569 ) ) {
V_339 = V_704 |
V_708 ;
if ( F_23 ( V_5 , V_705 ) )
V_339 |= V_706 |
V_707 ;
if ( V_5 -> V_178 & V_769 )
V_339 |= V_770 |
V_761 ;
V_768 = V_334 | V_335 ;
} else {
V_339 = V_5 -> V_327 . V_396 ;
if ( V_5 -> V_178 & V_390 )
V_339 &= ~ ( V_770 |
V_761 ) ;
V_768 = V_5 -> V_327 . V_340 ;
}
F_202 ( V_5 , V_339 , V_768 ) ;
if ( ( V_5 -> V_178 & V_397 ) &&
( V_5 -> V_178 & V_569 ) ) {
return;
}
F_59 ( V_5 , V_202 ,
V_576 | V_577 ) ;
} else {
int V_42 ;
T_1 V_771 , V_772 ;
V_5 -> V_327 . V_328 = V_5 -> V_327 . V_370 ;
V_5 -> V_327 . V_331 = V_5 -> V_327 . V_374 ;
if ( F_30 ( V_5 ) == V_548 ) {
F_59 ( V_5 , V_300 , V_756 ) ;
}
V_771 = 0 ;
switch ( V_5 -> V_327 . V_370 ) {
default:
case V_371 :
break;
case V_330 :
V_771 |= V_773 ;
break;
case V_329 :
V_771 |= V_493 ;
break;
}
if ( V_5 -> V_327 . V_374 == V_332 )
V_771 |= V_492 ;
if ( ! F_57 ( V_5 , V_202 , & V_772 ) &&
( V_771 != V_772 ) ) {
F_59 ( V_5 , V_202 , V_774 ) ;
for ( V_42 = 0 ; V_42 < 1500 ; V_42 ++ ) {
T_1 V_596 ;
F_24 ( 10 ) ;
if ( F_57 ( V_5 , V_299 , & V_596 ) ||
F_57 ( V_5 , V_299 , & V_596 ) )
continue;
if ( ! ( V_596 & V_775 ) ) {
F_24 ( 40 ) ;
break;
}
}
F_59 ( V_5 , V_202 , V_771 ) ;
F_24 ( 40 ) ;
}
}
}
static int F_206 ( struct V_4 * V_5 )
{
int V_75 ;
T_1 V_7 ;
V_75 = F_57 ( V_5 , V_202 , & V_7 ) ;
if ( V_75 )
goto V_186;
if ( ! ( V_7 & V_576 ) ) {
V_5 -> V_327 . V_350 = V_776 ;
V_5 -> V_327 . V_396 = 0 ;
F_84 ( V_5 , V_356 ) ;
V_75 = - V_208 ;
switch ( V_7 & ( V_493 | V_773 ) ) {
case 0 :
if ( V_5 -> V_178 & V_357 )
goto V_186;
V_5 -> V_327 . V_370 = V_371 ;
break;
case V_773 :
if ( V_5 -> V_178 & V_357 )
goto V_186;
V_5 -> V_327 . V_370 = V_330 ;
break;
case V_493 :
if ( ! ( V_5 -> V_178 & V_390 ) ) {
V_5 -> V_327 . V_370 = V_329 ;
break;
}
default:
goto V_186;
}
if ( V_7 & V_492 )
V_5 -> V_327 . V_374 = V_332 ;
else
V_5 -> V_327 . V_374 = V_375 ;
V_5 -> V_327 . V_340 = V_335 | V_334 ;
V_75 = 0 ;
goto V_186;
}
V_5 -> V_327 . V_350 = V_355 ;
V_5 -> V_327 . V_396 = V_703 ;
F_82 ( V_5 , V_356 ) ;
if ( ! ( V_5 -> V_178 & V_357 ) ) {
T_1 V_339 ;
V_75 = F_57 ( V_5 , V_300 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_339 = F_207 ( V_7 & V_756 ) ;
V_5 -> V_327 . V_396 |= V_339 | V_701 ;
V_5 -> V_327 . V_340 = F_102 ( V_7 ) ;
} else {
V_5 -> V_327 . V_396 |= V_777 ;
}
if ( ! ( V_5 -> V_178 & V_390 ) ) {
T_1 V_339 ;
if ( ! ( V_5 -> V_178 & V_357 ) ) {
V_75 = F_57 ( V_5 , V_180 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_339 = F_208 ( V_7 ) ;
} else {
V_75 = F_57 ( V_5 , V_300 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_339 = F_104 ( V_7 ) ;
V_5 -> V_327 . V_340 = V_339 ;
V_7 &= ( V_778 | V_779 ) ;
V_339 = F_209 ( V_7 ) ;
}
V_5 -> V_327 . V_396 |= V_339 ;
}
V_186:
return V_75 ;
}
static int F_210 ( struct V_4 * V_5 )
{
int V_75 ;
V_75 = F_65 ( V_5 , V_196 , 0x4c20 ) ;
V_75 |= F_63 ( V_5 , 0x0012 , 0x1804 ) ;
V_75 |= F_63 ( V_5 , 0x0013 , 0x1204 ) ;
V_75 |= F_63 ( V_5 , 0x8006 , 0x0132 ) ;
V_75 |= F_63 ( V_5 , 0x8006 , 0x0232 ) ;
V_75 |= F_63 ( V_5 , 0x201f , 0x0a20 ) ;
F_24 ( 40 ) ;
return V_75 ;
}
static bool F_211 ( struct V_4 * V_5 )
{
struct V_451 V_452 ;
if ( ! ( V_5 -> V_178 & V_336 ) )
return true ;
F_130 ( V_5 , & V_452 ) ;
if ( V_5 -> V_452 . V_462 ) {
if ( V_5 -> V_452 . V_463 != V_452 . V_463 ||
V_5 -> V_452 . V_467 != V_452 . V_467 ||
V_5 -> V_452 . V_465 != V_452 . V_465 )
return false ;
} else {
if ( V_452 . V_463 )
return false ;
}
return true ;
}
static bool F_212 ( struct V_4 * V_5 , T_1 * V_347 )
{
T_1 V_780 , V_781 , V_396 ;
V_396 = V_5 -> V_327 . V_396 ;
V_781 = F_203 ( V_396 ) & V_756 ;
V_780 = V_756 ;
if ( V_5 -> V_327 . V_331 == V_332 ) {
V_781 |= F_110 ( V_5 -> V_327 . V_340 ) ;
V_780 |= V_341 | V_342 ;
}
if ( F_57 ( V_5 , V_300 , V_347 ) )
return false ;
if ( ( * V_347 & V_780 ) != V_781 )
return false ;
if ( ! ( V_5 -> V_178 & V_390 ) ) {
T_1 V_782 ;
V_781 = F_204 ( V_396 ) ;
if ( F_57 ( V_5 , V_180 , & V_782 ) )
return false ;
if ( V_781 &&
( F_76 ( V_5 ) == V_757 ||
F_76 ( V_5 ) == V_758 ) ) {
V_781 |= V_494 | V_495 ;
V_782 &= ( V_783 | V_784 |
V_494 | V_495 ) ;
} else {
V_782 &= ( V_783 | V_784 ) ;
}
if ( V_782 != V_781 )
return false ;
}
return true ;
}
static bool F_213 ( struct V_4 * V_5 , T_1 * V_348 )
{
T_1 V_785 = 0 ;
if ( ! ( V_5 -> V_178 & V_390 ) ) {
T_1 V_7 ;
if ( F_57 ( V_5 , V_303 , & V_7 ) )
return false ;
V_785 = F_214 ( V_7 ) ;
}
if ( F_57 ( V_5 , V_301 , V_348 ) )
return false ;
V_785 |= F_215 ( * V_348 ) ;
V_5 -> V_327 . V_367 = V_785 ;
return true ;
}
static bool F_216 ( struct V_4 * V_5 , bool V_786 )
{
if ( V_786 != V_5 -> V_338 ) {
if ( V_786 ) {
F_217 ( V_5 -> V_111 ) ;
} else {
F_139 ( V_5 -> V_111 ) ;
if ( V_5 -> V_178 & V_302 )
V_5 -> V_178 &= ~ V_787 ;
}
F_98 ( V_5 ) ;
return true ;
}
return false ;
}
static void F_218 ( struct V_4 * V_5 )
{
F_46 ( V_788 , 0 ) ;
F_31 ( V_789 ,
V_790 |
V_791 |
V_792 |
V_793 ) ;
F_24 ( 40 ) ;
}
static void F_219 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_7 = V_794 |
V_795 ;
if ( F_76 ( V_5 ) == V_325 )
V_7 |= V_796 ;
F_31 ( V_797 , V_7 ) ;
F_31 ( V_473 ,
V_798 ) ;
V_7 = V_799 |
( V_5 -> V_452 . V_465 ? V_466 : 0 ) |
V_800 |
V_801 ;
if ( F_30 ( V_5 ) != V_476 )
V_7 |= V_802 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_803 ;
F_31 ( V_464 , V_5 -> V_452 . V_462 ? V_7 : 0 ) ;
F_31 ( V_468 ,
V_804 |
( V_5 -> V_452 . V_467 & 0xffff ) ) ;
F_31 ( V_805 ,
V_806 |
V_807 ) ;
}
static int F_220 ( struct V_4 * V_5 , bool V_808 )
{
bool V_469 ;
T_1 V_809 , V_7 ;
T_1 V_366 , V_367 ;
T_3 V_810 ;
T_4 V_811 ;
int V_42 , V_75 ;
F_218 ( V_5 ) ;
if ( ( V_5 -> V_164 & V_165 ) != 0 ) {
F_31 ( V_166 ,
( V_5 -> V_164 & ~ V_165 ) ) ;
F_24 ( 80 ) ;
}
F_65 ( V_5 , V_584 , 0 ) ;
if ( ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ) &&
V_5 -> V_338 ) {
F_57 ( V_5 , V_299 , & V_809 ) ;
if ( ! F_57 ( V_5 , V_299 , & V_809 ) &&
! ( V_809 & V_775 ) )
V_808 = true ;
}
if ( V_808 )
F_142 ( V_5 ) ;
if ( ( V_5 -> V_215 & V_398 ) == V_399 ) {
F_57 ( V_5 , V_299 , & V_809 ) ;
if ( F_57 ( V_5 , V_299 , & V_809 ) ||
! F_23 ( V_5 , V_562 ) )
V_809 = 0 ;
if ( ! ( V_809 & V_775 ) ) {
V_75 = F_210 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_57 ( V_5 , V_299 , & V_809 ) ;
for ( V_42 = 0 ; V_42 < 1000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_299 , & V_809 ) &&
( V_809 & V_775 ) ) {
F_24 ( 40 ) ;
break;
}
}
if ( ( V_5 -> V_215 & V_812 ) ==
V_813 &&
! ( V_809 & V_775 ) &&
V_5 -> V_327 . V_328 == V_329 ) {
V_75 = F_142 ( V_5 ) ;
if ( ! V_75 )
V_75 = F_210 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
}
} else if ( F_76 ( V_5 ) == V_757 ||
F_76 ( V_5 ) == V_758 ) {
F_59 ( V_5 , 0x15 , 0x0a75 ) ;
F_59 ( V_5 , V_415 , 0x8c68 ) ;
F_59 ( V_5 , V_415 , 0x8d68 ) ;
F_59 ( V_5 , V_415 , 0x8c68 ) ;
}
F_57 ( V_5 , V_814 , & V_7 ) ;
F_57 ( V_5 , V_814 , & V_7 ) ;
if ( V_5 -> V_178 & V_815 )
F_59 ( V_5 , V_816 , ~ V_817 ) ;
else if ( ! ( V_5 -> V_178 & V_179 ) )
F_59 ( V_5 , V_816 , ~ 0 ) ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) {
if ( V_5 -> V_563 == V_818 )
F_59 ( V_5 , V_491 ,
V_819 ) ;
else
F_59 ( V_5 , V_491 , 0 ) ;
}
V_469 = false ;
V_810 = V_751 ;
V_811 = V_752 ;
V_5 -> V_178 &= ~ V_820 ;
V_5 -> V_327 . V_367 = 0 ;
if ( V_5 -> V_178 & V_821 ) {
V_75 = F_64 ( V_5 ,
V_822 ,
& V_7 ) ;
if ( ! V_75 && ! ( V_7 & ( 1 << 10 ) ) ) {
F_65 ( V_5 ,
V_822 ,
V_7 | ( 1 << 10 ) ) ;
goto V_823;
}
}
V_809 = 0 ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_57 ( V_5 , V_299 , & V_809 ) ;
if ( ! F_57 ( V_5 , V_299 , & V_809 ) &&
( V_809 & V_775 ) )
break;
F_24 ( 40 ) ;
}
if ( V_809 & V_775 ) {
T_1 V_824 , V_771 ;
F_57 ( V_5 , V_825 , & V_824 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_825 , & V_824 ) &&
V_824 )
break;
}
F_201 ( V_5 , V_824 ,
& V_810 ,
& V_811 ) ;
V_771 = 0 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_57 ( V_5 , V_202 , & V_771 ) ;
if ( F_57 ( V_5 , V_202 , & V_771 ) )
continue;
if ( V_771 && V_771 != 0x7fff )
break;
F_24 ( 10 ) ;
}
V_366 = 0 ;
V_367 = 0 ;
V_5 -> V_327 . V_328 = V_810 ;
V_5 -> V_327 . V_331 = V_811 ;
if ( V_5 -> V_327 . V_350 == V_355 ) {
bool V_826 = F_211 ( V_5 ) ;
if ( ( V_771 & V_576 ) &&
V_826 &&
F_212 ( V_5 , & V_366 ) &&
F_213 ( V_5 , & V_367 ) )
V_469 = true ;
if ( ! V_826 &&
( V_5 -> V_178 & V_569 ) &&
! V_808 ) {
F_219 ( V_5 ) ;
F_142 ( V_5 ) ;
}
} else {
if ( ! ( V_771 & V_576 ) &&
V_5 -> V_327 . V_370 == V_810 &&
V_5 -> V_327 . V_374 == V_811 ) {
V_469 = true ;
}
}
if ( V_469 &&
V_5 -> V_327 . V_331 == V_332 ) {
T_1 V_161 , V_44 ;
if ( V_5 -> V_178 & V_179 ) {
V_161 = V_827 ;
V_44 = V_828 ;
} else {
V_161 = V_829 ;
V_44 = V_830 ;
}
if ( ! F_57 ( V_5 , V_161 , & V_7 ) && ( V_7 & V_44 ) )
V_5 -> V_178 |= V_820 ;
F_106 ( V_5 , V_366 , V_367 ) ;
}
}
V_823:
if ( ! V_469 || ( V_5 -> V_178 & V_397 ) ) {
F_205 ( V_5 ) ;
if ( F_23 ( V_5 , V_831 ) ) {
V_469 = true ;
V_810 = V_329 ;
V_811 = V_332 ;
V_5 -> V_327 . V_328 = V_810 ;
V_5 -> V_327 . V_331 = V_811 ;
}
F_57 ( V_5 , V_299 , & V_809 ) ;
if ( ( ! F_57 ( V_5 , V_299 , & V_809 ) && ( V_809 & V_775 ) ) ||
( V_5 -> V_365 & V_832 ) )
V_469 = true ;
}
V_5 -> V_365 &= ~ V_368 ;
if ( V_469 ) {
if ( V_5 -> V_327 . V_328 == V_330 ||
V_5 -> V_327 . V_328 == V_371 )
V_5 -> V_365 |= V_372 ;
else
V_5 -> V_365 |= V_373 ;
} else if ( V_5 -> V_178 & V_179 )
V_5 -> V_365 |= V_372 ;
else
V_5 -> V_365 |= V_373 ;
if ( F_23 ( V_5 , V_833 ) ) {
T_1 V_563 = F_33 ( V_725 ) ;
V_563 &= ~ ( V_834 | V_835 ) ;
if ( V_5 -> V_327 . V_328 == V_371 )
V_563 |= V_836 ;
else if ( V_5 -> V_327 . V_328 == V_330 )
V_563 |= ( V_836 |
V_835 ) ;
else if ( V_5 -> V_327 . V_328 == V_329 )
V_563 |= ( V_836 |
V_834 ) ;
F_46 ( V_725 , V_563 ) ;
F_24 ( 40 ) ;
}
V_5 -> V_365 &= ~ V_369 ;
if ( V_5 -> V_327 . V_331 == V_375 )
V_5 -> V_365 |= V_369 ;
if ( F_30 ( V_5 ) == V_536 ) {
if ( V_469 &&
F_152 ( V_5 , V_5 -> V_327 . V_328 ) )
V_5 -> V_365 |= V_723 ;
else
V_5 -> V_365 &= ~ V_723 ;
}
if ( ( V_5 -> V_215 & V_398 ) == V_565 &&
F_76 ( V_5 ) == V_837 ) {
V_5 -> V_164 |= V_165 ;
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
}
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
F_132 ( V_5 , V_469 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
F_31 ( V_788 , 0 ) ;
} else {
F_31 ( V_788 , V_838 ) ;
}
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_536 &&
V_469 &&
V_5 -> V_327 . V_328 == V_329 &&
( F_23 ( V_5 , V_839 ) || F_23 ( V_5 , V_840 ) ) ) {
F_24 ( 120 ) ;
F_31 ( V_789 ,
( V_790 |
V_791 ) ) ;
F_24 ( 40 ) ;
F_29 ( V_5 ,
V_311 ,
V_841 ) ;
}
if ( F_23 ( V_5 , V_697 ) ) {
if ( V_5 -> V_327 . V_328 == V_330 ||
V_5 -> V_327 . V_328 == V_371 )
F_221 ( V_5 -> V_12 , V_698 ,
V_699 ) ;
else
F_197 ( V_5 -> V_12 , V_698 ,
V_699 ) ;
}
F_216 ( V_5 , V_469 ) ;
return 0 ;
}
static int F_222 ( struct V_4 * V_5 ,
struct V_842 * V_843 )
{
T_3 V_340 ;
unsigned long V_844 ;
T_1 V_845 ;
int V_56 ;
if ( V_843 -> V_846 == V_847 ) {
V_843 -> V_848 = 0 ;
V_843 -> V_849 = 0 ;
V_843 -> V_850 = 0 ;
V_843 -> V_851 = 0 ;
V_843 -> V_852 = 0 ;
V_843 -> V_853 = 0 ;
V_843 -> V_854 = 0 ;
V_843 -> V_855 = 0 ;
}
V_843 -> V_850 ++ ;
if ( F_33 ( V_789 ) & V_856 ) {
V_845 = F_33 ( V_857 ) ;
if ( V_845 != V_843 -> V_851 ) {
V_843 -> V_851 = V_845 ;
V_843 -> V_853 = 0 ;
V_843 -> V_852 = 0 ;
} else {
if ( ++ V_843 -> V_852 > 1 ) {
V_843 -> V_853 = 1 ;
V_843 -> V_851 = V_845 ;
}
}
if ( V_845 & V_858 )
V_843 -> V_855 = 1 ;
else
V_843 -> V_855 = 0 ;
V_843 -> V_854 = 0 ;
} else {
V_843 -> V_854 = 1 ;
V_843 -> V_851 = 0 ;
V_843 -> V_852 = 0 ;
V_843 -> V_853 = 0 ;
V_843 -> V_855 = 0 ;
V_845 = 0 ;
}
V_843 -> V_848 = V_845 ;
V_56 = V_859 ;
switch ( V_843 -> V_846 ) {
case V_847 :
if ( V_843 -> V_10 & ( V_860 | V_861 ) )
V_843 -> V_846 = V_862 ;
case V_862 :
V_843 -> V_10 &= ~ ( V_863 | V_864 ) ;
if ( V_843 -> V_10 & V_860 ) {
V_843 -> V_849 = 0 ;
V_843 -> V_850 = 0 ;
V_843 -> V_851 = 0 ;
V_843 -> V_852 = 0 ;
V_843 -> V_853 = 0 ;
V_843 -> V_854 = 0 ;
V_843 -> V_855 = 0 ;
V_843 -> V_846 = V_865 ;
} else {
V_843 -> V_846 = V_866 ;
}
break;
case V_865 :
V_843 -> V_849 = V_843 -> V_850 ;
V_843 -> V_10 &= ~ ( V_867 ) ;
V_843 -> V_868 = 0 ;
F_46 ( V_869 , 0 ) ;
V_5 -> V_365 |= V_870 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
V_56 = V_871 ;
V_843 -> V_846 = V_872 ;
case V_872 :
V_844 = V_843 -> V_850 - V_843 -> V_849 ;
if ( V_844 > V_873 )
V_843 -> V_846 = V_874 ;
else
V_56 = V_871 ;
break;
case V_866 :
V_56 = V_875 ;
break;
case V_874 :
V_843 -> V_10 &= ~ ( V_876 ) ;
V_843 -> V_868 = V_877 ;
V_340 = F_103 ( V_5 -> V_327 . V_340 ) ;
if ( V_340 & V_345 )
V_843 -> V_868 |= V_878 ;
if ( V_340 & V_346 )
V_843 -> V_868 |= V_879 ;
F_46 ( V_869 , V_843 -> V_868 ) ;
V_5 -> V_365 |= V_870 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
V_843 -> V_846 = V_880 ;
break;
case V_880 :
if ( V_843 -> V_853 != 0 && V_843 -> V_848 != 0 )
V_843 -> V_846 = V_881 ;
break;
case V_881 :
V_843 -> V_868 |= V_858 ;
F_46 ( V_869 , V_843 -> V_868 ) ;
V_5 -> V_365 |= V_870 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
V_843 -> V_846 = V_882 ;
case V_882 :
if ( V_843 -> V_855 != 0 ) {
if ( ( V_843 -> V_848 & ~ V_858 ) ==
( V_843 -> V_851 & ~ V_858 ) ) {
V_843 -> V_846 = V_883 ;
} else {
V_843 -> V_846 = V_862 ;
}
} else if ( V_843 -> V_853 != 0 &&
V_843 -> V_848 == 0 ) {
V_843 -> V_846 = V_862 ;
}
break;
case V_883 :
if ( V_843 -> V_848 & V_884 ) {
V_56 = V_885 ;
break;
}
V_843 -> V_10 &= ~ ( V_886 |
V_887 |
V_888 |
V_889 |
V_890 |
V_891 |
V_892 |
V_893 |
V_894 ) ;
if ( V_843 -> V_848 & V_877 )
V_843 -> V_10 |= V_886 ;
if ( V_843 -> V_848 & V_895 )
V_843 -> V_10 |= V_887 ;
if ( V_843 -> V_848 & V_878 )
V_843 -> V_10 |= V_888 ;
if ( V_843 -> V_848 & V_879 )
V_843 -> V_10 |= V_889 ;
if ( V_843 -> V_848 & V_896 )
V_843 -> V_10 |= V_890 ;
if ( V_843 -> V_848 & V_897 )
V_843 -> V_10 |= V_891 ;
if ( V_843 -> V_848 & V_898 )
V_843 -> V_10 |= V_892 ;
V_843 -> V_849 = V_843 -> V_850 ;
V_843 -> V_10 ^= ( V_876 ) ;
if ( V_843 -> V_848 & 0x0008 )
V_843 -> V_10 |= V_893 ;
if ( V_843 -> V_848 & V_898 )
V_843 -> V_10 |= V_894 ;
V_843 -> V_10 |= V_864 ;
V_843 -> V_846 = V_899 ;
V_56 = V_871 ;
break;
case V_899 :
if ( V_843 -> V_853 != 0 &&
V_843 -> V_848 == 0 ) {
V_843 -> V_846 = V_862 ;
break;
}
V_844 = V_843 -> V_850 - V_843 -> V_849 ;
if ( V_844 > V_873 ) {
if ( ! ( V_843 -> V_10 & ( V_892 ) ) ) {
V_843 -> V_846 = V_900 ;
} else {
if ( ( V_843 -> V_868 & V_898 ) == 0 &&
! ( V_843 -> V_10 & V_894 ) ) {
V_843 -> V_846 = V_900 ;
} else {
V_56 = V_885 ;
}
}
}
break;
case V_900 :
V_843 -> V_849 = V_843 -> V_850 ;
V_5 -> V_365 &= ~ V_870 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
V_843 -> V_846 = V_901 ;
V_56 = V_871 ;
break;
case V_901 :
if ( V_843 -> V_853 != 0 &&
V_843 -> V_848 == 0 ) {
V_843 -> V_846 = V_862 ;
break;
}
V_844 = V_843 -> V_850 - V_843 -> V_849 ;
if ( V_844 > V_873 ) {
V_843 -> V_846 = V_902 ;
}
break;
case V_902 :
V_843 -> V_10 |= ( V_863 | V_903 ) ;
V_56 = V_875 ;
break;
case V_904 :
break;
case V_905 :
break;
default:
V_56 = V_885 ;
break;
}
return V_56 ;
}
static int F_223 ( struct V_4 * V_5 , T_1 * V_906 , T_1 * V_907 )
{
int V_625 = 0 ;
struct V_842 V_908 ;
int V_57 = V_885 ;
unsigned int V_909 ;
T_1 V_596 ;
F_31 ( V_869 , 0 ) ;
V_596 = V_5 -> V_365 & ~ V_368 ;
F_31 ( V_380 , V_596 | V_373 ) ;
F_24 ( 40 ) ;
F_31 ( V_380 , V_5 -> V_365 | V_870 ) ;
F_24 ( 40 ) ;
memset ( & V_908 , 0 , sizeof( V_908 ) ) ;
V_908 . V_10 |= V_860 ;
V_908 . V_846 = V_847 ;
V_908 . V_850 = 0 ;
V_909 = 0 ;
while ( ++ V_909 < 195000 ) {
V_57 = F_222 ( V_5 , & V_908 ) ;
if ( V_57 == V_875 || V_57 == V_885 )
break;
F_24 ( 1 ) ;
}
V_5 -> V_365 &= ~ V_870 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
* V_906 = V_908 . V_868 ;
* V_907 = V_908 . V_10 ;
if ( V_57 == V_875 &&
( V_908 . V_10 & ( V_863 | V_903 |
V_886 ) ) )
V_625 = 1 ;
return V_625 ;
}
static void F_224 ( struct V_4 * V_5 )
{
T_1 V_910 = F_33 ( V_789 ) ;
int V_42 ;
if ( F_23 ( V_5 , V_562 ) &&
! ( V_910 & V_911 ) )
return;
F_59 ( V_5 , 0x16 , 0x8007 ) ;
F_59 ( V_5 , V_202 , V_201 ) ;
for ( V_42 = 0 ; V_42 < 500 ; V_42 ++ )
F_24 ( 10 ) ;
F_59 ( V_5 , 0x10 , 0x8411 ) ;
F_59 ( V_5 , 0x11 , 0x0a10 ) ;
F_59 ( V_5 , 0x18 , 0x00a0 ) ;
F_59 ( V_5 , 0x16 , 0x41ff ) ;
F_59 ( V_5 , 0x13 , 0x0400 ) ;
F_24 ( 40 ) ;
F_59 ( V_5 , 0x13 , 0x0000 ) ;
F_59 ( V_5 , 0x11 , 0x0a50 ) ;
F_24 ( 40 ) ;
F_59 ( V_5 , 0x11 , 0x0a10 ) ;
for ( V_42 = 0 ; V_42 < 15000 ; V_42 ++ )
F_24 ( 10 ) ;
F_59 ( V_5 , 0x10 , 0x8011 ) ;
}
static bool F_225 ( struct V_4 * V_5 , T_1 V_910 )
{
T_3 V_340 ;
bool V_469 ;
T_1 V_570 , V_912 ;
T_1 V_572 , V_913 ;
int V_914 , V_915 ;
V_572 = 0 ;
V_913 = 0 ;
V_914 = 0 ;
V_915 = 1 ;
V_469 = false ;
if ( F_76 ( V_5 ) != V_916 &&
F_76 ( V_5 ) != V_917 ) {
V_914 = 1 ;
if ( F_33 ( V_918 ) & V_919 )
V_915 = 0 ;
V_572 = F_33 ( V_573 ) & 0x00f06fff ;
}
V_570 = F_33 ( V_571 ) ;
if ( V_5 -> V_327 . V_350 != V_355 ) {
if ( V_570 & V_574 ) {
if ( V_914 ) {
T_1 V_7 = V_572 ;
if ( V_915 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_573 , V_7 ) ;
}
F_31 ( V_571 , V_920 ) ;
}
if ( V_910 & V_911 ) {
F_106 ( V_5 , 0 , 0 ) ;
V_469 = true ;
}
goto V_502;
}
V_913 = V_574 | V_920 ;
V_340 = F_103 ( V_5 -> V_327 . V_340 ) ;
if ( V_340 & V_345 )
V_913 |= V_921 ;
if ( V_340 & V_346 )
V_913 |= V_922 ;
if ( V_570 != V_913 ) {
if ( ( V_5 -> V_178 & V_787 ) &&
V_5 -> V_923 &&
( ( V_910 & ( V_911 |
V_856 ) ) ==
V_911 ) ) {
V_5 -> V_923 -- ;
V_469 = true ;
goto V_502;
}
V_924:
if ( V_914 )
F_31 ( V_573 , V_572 | 0xc011000 ) ;
F_31 ( V_571 , V_913 | V_575 ) ;
F_24 ( 5 ) ;
F_31 ( V_571 , V_913 ) ;
V_5 -> V_923 = V_925 ;
V_5 -> V_178 &= ~ V_787 ;
} else if ( V_910 & ( V_911 |
V_926 ) ) {
V_912 = F_33 ( V_259 ) ;
V_910 = F_33 ( V_789 ) ;
if ( ( V_912 & V_927 ) &&
( V_910 & V_911 ) ) {
T_1 V_928 = 0 , V_929 = 0 ;
if ( V_570 & V_921 )
V_928 |= V_345 ;
if ( V_570 & V_922 )
V_928 |= V_346 ;
if ( V_912 & V_930 )
V_929 |= V_931 ;
if ( V_912 & V_932 )
V_929 |= V_933 ;
V_5 -> V_327 . V_367 =
F_209 ( V_929 ) ;
F_106 ( V_5 , V_928 , V_929 ) ;
V_469 = true ;
V_5 -> V_923 = 0 ;
V_5 -> V_178 &= ~ V_787 ;
} else if ( ! ( V_912 & V_927 ) ) {
if ( V_5 -> V_923 )
V_5 -> V_923 -- ;
else {
if ( V_914 ) {
T_1 V_7 = V_572 ;
if ( V_915 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_573 , V_7 ) ;
}
F_31 ( V_571 , V_920 ) ;
F_24 ( 40 ) ;
V_910 = F_33 ( V_789 ) ;
if ( ( V_910 & V_911 ) &&
! ( V_910 & V_856 ) ) {
F_106 ( V_5 , 0 , 0 ) ;
V_469 = true ;
V_5 -> V_178 |=
V_787 ;
V_5 -> V_923 =
V_934 ;
} else
goto V_924;
}
}
} else {
V_5 -> V_923 = V_925 ;
V_5 -> V_178 &= ~ V_787 ;
}
V_502:
return V_469 ;
}
static bool F_226 ( struct V_4 * V_5 , T_1 V_910 )
{
bool V_469 = false ;
if ( ! ( V_910 & V_911 ) )
goto V_502;
if ( V_5 -> V_327 . V_350 == V_355 ) {
T_1 V_906 , V_907 ;
int V_42 ;
if ( F_223 ( V_5 , & V_906 , & V_907 ) ) {
T_1 V_928 = 0 , V_929 = 0 ;
if ( V_906 & V_878 )
V_928 |= V_345 ;
if ( V_906 & V_879 )
V_928 |= V_346 ;
if ( V_907 & V_888 )
V_929 |= V_931 ;
if ( V_907 & V_889 )
V_929 |= V_933 ;
V_5 -> V_327 . V_367 =
F_209 ( V_929 ) ;
F_106 ( V_5 , V_928 , V_929 ) ;
V_469 = true ;
}
for ( V_42 = 0 ; V_42 < 30 ; V_42 ++ ) {
F_24 ( 20 ) ;
F_31 ( V_789 ,
( V_790 |
V_791 ) ) ;
F_24 ( 40 ) ;
if ( ( F_33 ( V_789 ) &
( V_790 |
V_791 ) ) == 0 )
break;
}
V_910 = F_33 ( V_789 ) ;
if ( ! V_469 &&
( V_910 & V_911 ) &&
! ( V_910 & V_856 ) )
V_469 = true ;
} else {
F_106 ( V_5 , 0 , 0 ) ;
V_469 = true ;
F_31 ( V_380 , ( V_5 -> V_365 | V_870 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
}
V_502:
return V_469 ;
}
static int F_227 ( struct V_4 * V_5 , bool V_808 )
{
T_1 V_935 ;
T_3 V_936 ;
T_4 V_937 ;
T_1 V_910 ;
bool V_469 ;
int V_42 ;
V_935 = V_5 -> V_327 . V_333 ;
V_936 = V_5 -> V_327 . V_328 ;
V_937 = V_5 -> V_327 . V_331 ;
if ( ! F_23 ( V_5 , V_938 ) &&
V_5 -> V_338 &&
F_23 ( V_5 , V_562 ) ) {
V_910 = F_33 ( V_789 ) ;
V_910 &= ( V_911 |
V_926 |
V_791 |
V_856 ) ;
if ( V_910 == ( V_911 |
V_926 ) ) {
F_31 ( V_789 , ( V_790 |
V_791 ) ) ;
return 0 ;
}
}
F_31 ( V_869 , 0 ) ;
V_5 -> V_365 &= ~ ( V_368 | V_369 ) ;
V_5 -> V_365 |= V_724 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
if ( V_5 -> V_215 == V_939 )
F_224 ( V_5 ) ;
F_31 ( V_788 , V_838 ) ;
F_24 ( 40 ) ;
V_469 = false ;
V_5 -> V_327 . V_367 = 0 ;
V_910 = F_33 ( V_789 ) ;
if ( F_23 ( V_5 , V_938 ) )
V_469 = F_225 ( V_5 , V_910 ) ;
else
V_469 = F_226 ( V_5 , V_910 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 =
( V_135 |
( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & ~ V_144 ) ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_31 ( V_789 , ( V_790 |
V_791 ) ) ;
F_24 ( 5 ) ;
if ( ( F_33 ( V_789 ) & ( V_790 |
V_791 |
V_793 ) ) == 0 )
break;
}
V_910 = F_33 ( V_789 ) ;
if ( ( V_910 & V_911 ) == 0 ) {
V_469 = false ;
if ( V_5 -> V_327 . V_350 == V_355 &&
V_5 -> V_923 == 0 ) {
F_31 ( V_380 , ( V_5 -> V_365 |
V_870 ) ) ;
F_24 ( 1 ) ;
F_31 ( V_380 , V_5 -> V_365 ) ;
}
}
if ( V_469 ) {
V_5 -> V_327 . V_328 = V_329 ;
V_5 -> V_327 . V_331 = V_332 ;
F_46 ( V_725 , ( V_5 -> V_563 |
V_836 |
V_834 ) ) ;
} else {
V_5 -> V_327 . V_328 = V_751 ;
V_5 -> V_327 . V_331 = V_752 ;
F_46 ( V_725 , ( V_5 -> V_563 |
V_836 |
V_940 ) ) ;
}
if ( ! F_216 ( V_5 , V_469 ) ) {
T_1 V_941 = V_5 -> V_327 . V_333 ;
if ( V_935 != V_941 ||
V_936 != V_5 -> V_327 . V_328 ||
V_937 != V_5 -> V_327 . V_331 )
F_98 ( V_5 ) ;
}
return 0 ;
}
static int F_228 ( struct V_4 * V_5 , bool V_808 )
{
int V_75 = 0 ;
T_1 V_809 , V_771 ;
T_3 V_810 = V_751 ;
T_4 V_811 = V_752 ;
bool V_469 = false ;
T_1 V_928 , V_929 , V_942 ;
if ( ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) &&
! F_57 ( V_5 , V_943 , & V_942 ) &&
( V_942 & V_944 ) ) {
if ( V_808 )
F_142 ( V_5 ) ;
V_5 -> V_365 &= ~ V_368 ;
if ( ! ( V_942 & V_945 ) ) {
V_5 -> V_365 |= V_373 ;
} else {
V_469 = true ;
if ( V_942 & V_946 ) {
V_810 = V_329 ;
V_5 -> V_365 |= V_373 ;
} else if ( V_942 & V_947 ) {
V_810 = V_330 ;
V_5 -> V_365 |= V_372 ;
} else {
V_810 = V_371 ;
V_5 -> V_365 |= V_372 ;
}
if ( V_942 & V_948 )
V_811 = V_332 ;
else
V_811 = V_375 ;
}
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
F_218 ( V_5 ) ;
goto V_949;
}
V_5 -> V_365 |= V_373 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
F_218 ( V_5 ) ;
if ( V_808 )
F_142 ( V_5 ) ;
V_5 -> V_327 . V_367 = 0 ;
V_75 |= F_57 ( V_5 , V_299 , & V_809 ) ;
V_75 |= F_57 ( V_5 , V_299 , & V_809 ) ;
if ( F_30 ( V_5 ) == V_548 ) {
if ( F_33 ( V_950 ) & V_951 )
V_809 |= V_775 ;
else
V_809 &= ~ V_775 ;
}
V_75 |= F_57 ( V_5 , V_202 , & V_771 ) ;
if ( ( V_5 -> V_327 . V_350 == V_355 ) && ! V_808 &&
( V_5 -> V_178 & V_787 ) ) {
} else if ( V_5 -> V_327 . V_350 == V_355 ) {
T_1 V_339 , V_952 ;
V_75 |= F_57 ( V_5 , V_300 , & V_339 ) ;
V_952 = V_339 & ~ ( V_779 | V_778 |
V_345 |
V_346 |
V_953 ) ;
V_952 |= F_103 ( V_5 -> V_327 . V_340 ) ;
V_952 |= F_229 ( V_5 -> V_327 . V_396 ) ;
if ( ( V_952 != V_339 ) || ! ( V_771 & V_576 ) ) {
F_59 ( V_5 , V_300 , V_952 ) ;
V_771 |= V_576 | V_577 ;
F_59 ( V_5 , V_202 , V_771 ) ;
F_31 ( V_788 , V_838 ) ;
V_5 -> V_923 = V_954 ;
V_5 -> V_178 &= ~ V_787 ;
return V_75 ;
}
} else {
T_1 V_955 ;
V_771 &= ~ V_493 ;
V_955 = V_771 & ~ ( V_576 | V_492 ) ;
if ( V_5 -> V_327 . V_374 == V_332 )
V_955 |= V_492 ;
if ( V_955 != V_771 ) {
V_955 |= V_493 ;
if ( V_5 -> V_338 ) {
T_1 V_339 ;
V_75 |= F_57 ( V_5 , V_300 , & V_339 ) ;
V_339 &= ~ ( V_779 |
V_778 |
V_953 ) ;
F_59 ( V_5 , V_300 , V_339 ) ;
F_59 ( V_5 , V_202 , V_771 |
V_577 |
V_576 ) ;
F_24 ( 10 ) ;
F_138 ( V_5 ) ;
}
F_59 ( V_5 , V_202 , V_955 ) ;
V_771 = V_955 ;
V_75 |= F_57 ( V_5 , V_299 , & V_809 ) ;
V_75 |= F_57 ( V_5 , V_299 , & V_809 ) ;
if ( F_30 ( V_5 ) == V_548 ) {
if ( F_33 ( V_950 ) & V_951 )
V_809 |= V_775 ;
else
V_809 &= ~ V_775 ;
}
V_5 -> V_178 &= ~ V_787 ;
}
}
if ( V_809 & V_775 ) {
V_810 = V_329 ;
V_469 = true ;
if ( V_771 & V_492 )
V_811 = V_332 ;
else
V_811 = V_375 ;
V_928 = 0 ;
V_929 = 0 ;
if ( V_771 & V_576 ) {
T_1 V_956 ;
V_75 |= F_57 ( V_5 , V_300 , & V_928 ) ;
V_75 |= F_57 ( V_5 , V_301 , & V_929 ) ;
V_956 = V_928 & V_929 ;
if ( V_956 & ( V_778 |
V_779 ) ) {
if ( V_956 & V_779 )
V_811 = V_332 ;
else
V_811 = V_375 ;
V_5 -> V_327 . V_367 =
F_209 ( V_929 ) ;
} else if ( ! F_23 ( V_5 , 5780_CLASS ) ) {
} else {
V_469 = false ;
}
}
}
V_949:
if ( V_469 && V_811 == V_332 )
F_106 ( V_5 , V_928 , V_929 ) ;
V_5 -> V_365 &= ~ V_369 ;
if ( V_5 -> V_327 . V_331 == V_375 )
V_5 -> V_365 |= V_369 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
F_31 ( V_788 , V_838 ) ;
V_5 -> V_327 . V_328 = V_810 ;
V_5 -> V_327 . V_331 = V_811 ;
F_216 ( V_5 , V_469 ) ;
return V_75 ;
}
static void F_230 ( struct V_4 * V_5 )
{
if ( V_5 -> V_923 ) {
V_5 -> V_923 -- ;
return;
}
if ( ! V_5 -> V_338 &&
( V_5 -> V_327 . V_350 == V_355 ) ) {
T_1 V_771 ;
F_57 ( V_5 , V_202 , & V_771 ) ;
if ( V_771 & V_576 ) {
T_1 V_957 , V_958 ;
F_59 ( V_5 , V_415 , 0x7c00 ) ;
F_57 ( V_5 , V_415 , & V_957 ) ;
F_59 ( V_5 , V_189 ,
V_959 ) ;
F_57 ( V_5 , V_190 , & V_958 ) ;
F_57 ( V_5 , V_190 , & V_958 ) ;
if ( ( V_957 & 0x10 ) && ! ( V_958 & 0x20 ) ) {
V_771 &= ~ V_576 ;
V_771 |= V_493 | V_492 ;
F_59 ( V_5 , V_202 , V_771 ) ;
V_5 -> V_178 |= V_787 ;
}
}
} else if ( V_5 -> V_338 &&
( V_5 -> V_327 . V_350 == V_355 ) &&
( V_5 -> V_178 & V_787 ) ) {
T_1 V_958 ;
F_59 ( V_5 , V_189 ,
V_959 ) ;
F_57 ( V_5 , V_190 , & V_958 ) ;
if ( V_958 & 0x20 ) {
T_1 V_771 ;
F_57 ( V_5 , V_202 , & V_771 ) ;
F_59 ( V_5 , V_202 , V_771 | V_576 ) ;
V_5 -> V_178 &= ~ V_787 ;
}
}
}
static int F_198 ( struct V_4 * V_5 , bool V_808 )
{
T_1 V_7 ;
int V_75 ;
if ( V_5 -> V_178 & V_567 )
V_75 = F_227 ( V_5 , V_808 ) ;
else if ( V_5 -> V_178 & V_302 )
V_75 = F_228 ( V_5 , V_808 ) ;
else
V_75 = F_220 ( V_5 , V_808 ) ;
if ( F_144 ( V_5 ) == V_503 ) {
T_1 V_960 ;
V_7 = F_33 ( V_961 ) & V_962 ;
if ( V_7 == V_963 )
V_960 = 65 ;
else if ( V_7 == V_964 )
V_960 = 6 ;
else
V_960 = 12 ;
V_7 = F_33 ( V_497 ) & ~ V_965 ;
V_7 |= ( V_960 << V_966 ) ;
F_46 ( V_497 , V_7 ) ;
}
V_7 = ( 2 << V_385 ) |
( 6 << V_386 ) ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_765 )
V_7 |= F_33 ( V_384 ) &
( V_967 |
V_968 ) ;
if ( V_5 -> V_327 . V_328 == V_329 &&
V_5 -> V_327 . V_331 == V_375 )
F_46 ( V_384 , V_7 |
( 0xff << V_387 ) ) ;
else
F_46 ( V_384 , V_7 |
( 32 << V_387 ) ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
if ( V_5 -> V_338 ) {
F_46 ( V_969 ,
V_5 -> V_970 . V_971 ) ;
} else {
F_46 ( V_969 , 0 ) ;
}
}
if ( F_23 ( V_5 , V_972 ) ) {
V_7 = F_33 ( V_973 ) ;
if ( ! V_5 -> V_338 )
V_7 = ( V_7 & ~ V_974 ) |
V_5 -> V_975 ;
else
V_7 |= V_974 ;
F_46 ( V_973 , V_7 ) ;
}
return V_75 ;
}
static T_6 F_231 ( struct V_4 * V_5 )
{
T_6 V_976 = F_33 ( V_977 ) ;
return V_976 | ( T_6 ) F_33 ( V_978 ) << 32 ;
}
static void F_232 ( struct V_4 * V_5 , T_6 V_979 )
{
T_1 V_980 = F_33 ( V_981 ) ;
F_46 ( V_981 , V_980 | V_982 ) ;
F_46 ( V_977 , V_979 & 0xffffffff ) ;
F_46 ( V_978 , V_979 >> 32 ) ;
F_31 ( V_981 , V_980 | V_983 ) ;
}
static int F_233 ( struct V_362 * V_111 , struct V_984 * V_985 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
V_985 -> V_986 = V_987 |
V_988 |
V_989 ;
if ( F_23 ( V_5 , V_990 ) ) {
V_985 -> V_986 |= V_991 |
V_992 |
V_993 ;
}
if ( V_5 -> V_994 )
V_985 -> V_995 = F_234 ( V_5 -> V_994 ) ;
else
V_985 -> V_995 = - 1 ;
V_985 -> V_996 = ( 1 << V_997 ) | ( 1 << V_998 ) ;
V_985 -> V_999 = ( 1 << V_1000 ) |
( 1 << V_1001 ) |
( 1 << V_1002 ) |
( 1 << V_1003 ) ;
return 0 ;
}
static int F_235 ( struct V_1004 * V_1005 , T_7 V_1006 )
{
struct V_4 * V_5 = F_236 ( V_1005 , struct V_4 , V_1007 ) ;
bool V_1008 = false ;
T_1 V_1009 = 0 ;
if ( V_1006 < 0 ) {
V_1008 = true ;
V_1006 = - V_1006 ;
}
V_1009 = F_237 ( ( T_6 ) V_1006 * ( 1 << 24 ) , 1000000000ULL ) &
V_1010 ;
F_238 ( V_5 , 0 ) ;
if ( V_1009 )
F_46 ( V_1011 ,
V_1012 |
( V_1008 ? V_1013 : 0 ) | V_1009 ) ;
else
F_46 ( V_1011 , 0 ) ;
F_239 ( V_5 ) ;
return 0 ;
}
static int F_240 ( struct V_1004 * V_1005 , T_8 V_844 )
{
struct V_4 * V_5 = F_236 ( V_1005 , struct V_4 , V_1007 ) ;
F_238 ( V_5 , 0 ) ;
V_5 -> V_1014 += V_844 ;
F_239 ( V_5 ) ;
return 0 ;
}
static int F_241 ( struct V_1004 * V_1005 , struct V_1015 * V_1016 )
{
T_6 V_1017 ;
T_1 V_1018 ;
struct V_4 * V_5 = F_236 ( V_1005 , struct V_4 , V_1007 ) ;
F_238 ( V_5 , 0 ) ;
V_1017 = F_231 ( V_5 ) ;
V_1017 += V_5 -> V_1014 ;
F_239 ( V_5 ) ;
V_1016 -> V_1019 = F_242 ( V_1017 , 1000000000 , & V_1018 ) ;
V_1016 -> V_1020 = V_1018 ;
return 0 ;
}
static int F_243 ( struct V_1004 * V_1005 ,
const struct V_1015 * V_1016 )
{
T_6 V_1017 ;
struct V_4 * V_5 = F_236 ( V_1005 , struct V_4 , V_1007 ) ;
V_1017 = F_244 ( V_1016 ) ;
F_238 ( V_5 , 0 ) ;
F_232 ( V_5 , V_1017 ) ;
V_5 -> V_1014 = 0 ;
F_239 ( V_5 ) ;
return 0 ;
}
static int F_245 ( struct V_1004 * V_1005 ,
struct V_1021 * V_1022 , int V_1023 )
{
struct V_4 * V_5 = F_236 ( V_1005 , struct V_4 , V_1007 ) ;
T_1 V_980 ;
int V_1024 = 0 ;
switch ( V_1022 -> type ) {
case V_1025 :
if ( V_1022 -> V_1026 . V_1027 != 0 )
return - V_64 ;
F_238 ( V_5 , 0 ) ;
V_980 = F_33 ( V_981 ) ;
V_980 &= ~ V_1028 ;
if ( V_1023 ) {
T_6 V_1029 ;
V_1029 = V_1022 -> V_1026 . V_1030 . V_1031 * 1000000000ULL +
V_1022 -> V_1026 . V_1030 . V_1029 ;
if ( V_1022 -> V_1026 . V_1032 . V_1031 || V_1022 -> V_1026 . V_1032 . V_1029 ) {
F_141 ( V_5 -> V_111 ,
L_28 ) ;
V_1024 = - V_64 ;
goto V_1033;
}
if ( V_1029 & ( 1ULL << 63 ) ) {
F_141 ( V_5 -> V_111 ,
L_29 ) ;
V_1024 = - V_64 ;
goto V_1033;
}
F_46 ( V_1034 , ( V_1029 & 0xffffffff ) ) ;
F_46 ( V_1035 ,
V_1036 |
( ( V_1029 >> 32 ) & V_1037 ) ) ;
F_46 ( V_981 ,
V_980 | V_1038 ) ;
} else {
F_46 ( V_1035 , 0 ) ;
F_46 ( V_981 , V_980 ) ;
}
V_1033:
F_239 ( V_5 ) ;
return V_1024 ;
default:
break;
}
return - V_1039 ;
}
static void F_246 ( struct V_4 * V_5 , T_6 V_1040 ,
struct V_1041 * V_1042 )
{
memset ( V_1042 , 0 , sizeof( struct V_1041 ) ) ;
V_1042 -> V_1043 = F_247 ( ( V_1040 & V_1044 ) +
V_5 -> V_1014 ) ;
}
static void F_248 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_990 ) )
return;
F_232 ( V_5 , F_249 ( F_250 () ) ) ;
V_5 -> V_1014 = 0 ;
V_5 -> V_1007 = V_1045 ;
}
static void F_251 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_990 ) )
return;
F_232 ( V_5 , F_249 ( F_250 () ) + V_5 -> V_1014 ) ;
V_5 -> V_1014 = 0 ;
}
static void F_252 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_990 ) || ! V_5 -> V_994 )
return;
F_253 ( V_5 -> V_994 ) ;
V_5 -> V_994 = NULL ;
V_5 -> V_1014 = 0 ;
}
static inline int F_254 ( struct V_4 * V_5 )
{
return V_5 -> V_125 ;
}
static inline void F_255 ( struct V_4 * V_5 , T_1 * V_1046 , T_1 V_6 , T_1 V_74 )
{
int V_42 ;
V_1046 = ( T_1 * ) ( ( T_4 * ) V_1046 + V_6 ) ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += sizeof( T_1 ) )
* V_1046 ++ = F_33 ( V_6 + V_42 ) ;
}
static void F_256 ( struct V_4 * V_5 , T_1 * V_8 )
{
F_255 ( V_5 , V_8 , V_1047 , 0xb0 ) ;
F_255 ( V_5 , V_8 , V_20 , 0x200 ) ;
F_255 ( V_5 , V_8 , V_380 , 0x4f0 ) ;
F_255 ( V_5 , V_8 , V_1048 , 0xe0 ) ;
F_255 ( V_5 , V_8 , V_1049 , 0x04 ) ;
F_255 ( V_5 , V_8 , V_1050 , 0x80 ) ;
F_255 ( V_5 , V_8 , V_1051 , 0x48 ) ;
F_255 ( V_5 , V_8 , V_1052 , 0x04 ) ;
F_255 ( V_5 , V_8 , V_1053 , 0x20 ) ;
F_255 ( V_5 , V_8 , V_1054 , 0x15c ) ;
F_255 ( V_5 , V_8 , V_1055 , 0x0c ) ;
F_255 ( V_5 , V_8 , V_1056 , 0x3c ) ;
F_255 ( V_5 , V_8 , V_1057 , 0x44 ) ;
F_255 ( V_5 , V_8 , V_1058 , 0x04 ) ;
F_255 ( V_5 , V_8 , V_1059 , 0x20 ) ;
F_255 ( V_5 , V_8 , V_1060 , 0x14 ) ;
F_255 ( V_5 , V_8 , V_1061 , 0x08 ) ;
F_255 ( V_5 , V_8 , V_1062 , 0x08 ) ;
F_255 ( V_5 , V_8 , V_138 , 0x100 ) ;
if ( F_23 ( V_5 , V_1063 ) )
F_255 ( V_5 , V_8 , V_1064 , 0x180 ) ;
F_255 ( V_5 , V_8 , V_1065 , 0x10 ) ;
F_255 ( V_5 , V_8 , V_1066 , 0x58 ) ;
F_255 ( V_5 , V_8 , V_1067 , 0x08 ) ;
F_255 ( V_5 , V_8 , V_1068 , 0x08 ) ;
F_255 ( V_5 , V_8 , V_1069 , 0x04 ) ;
F_255 ( V_5 , V_8 , V_1070 , 0x04 ) ;
F_255 ( V_5 , V_8 , V_1071 , 0x04 ) ;
F_255 ( V_5 , V_8 , V_677 , 0x04 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_255 ( V_5 , V_8 , V_1072 , 0x04 ) ;
F_255 ( V_5 , V_8 , V_1073 , 0x04 ) ;
F_255 ( V_5 , V_8 , V_1074 , 0x04 ) ;
}
F_255 ( V_5 , V_8 , V_1075 , 0x110 ) ;
F_255 ( V_5 , V_8 , V_1076 , 0x120 ) ;
F_255 ( V_5 , V_8 , V_1077 , 0x0c ) ;
F_255 ( V_5 , V_8 , V_1078 , 0x04 ) ;
F_255 ( V_5 , V_8 , V_646 , 0x4c ) ;
if ( F_23 ( V_5 , V_585 ) )
F_255 ( V_5 , V_8 , V_607 , 0x24 ) ;
}
static void F_257 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 * V_8 ;
V_8 = F_258 ( V_1079 , V_1080 ) ;
if ( ! V_8 )
return;
if ( F_23 ( V_5 , V_1081 ) ) {
for ( V_42 = 0 ; V_42 < V_1082 ; V_42 += sizeof( T_1 ) )
V_8 [ V_42 / sizeof( T_1 ) ] = F_33 ( V_42 ) ;
} else
F_256 ( V_5 , V_8 ) ;
for ( V_42 = 0 ; V_42 < V_1079 / sizeof( T_1 ) ; V_42 += 4 ) {
if ( ! V_8 [ V_42 + 0 ] && ! V_8 [ V_42 + 1 ] &&
! V_8 [ V_42 + 2 ] && ! V_8 [ V_42 + 3 ] )
continue;
F_183 ( V_5 -> V_111 , L_30 ,
V_42 * 4 ,
V_8 [ V_42 + 0 ] , V_8 [ V_42 + 1 ] , V_8 [ V_42 + 2 ] , V_8 [ V_42 + 3 ] ) ;
}
F_173 ( V_8 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_183 ( V_5 -> V_111 ,
L_31 ,
V_42 ,
V_131 -> V_134 -> V_57 ,
V_131 -> V_134 -> V_1083 ,
V_131 -> V_134 -> V_1084 ,
V_131 -> V_134 -> V_1085 ,
V_131 -> V_134 -> V_1086 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_1087 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_146 ) ;
F_183 ( V_5 -> V_111 ,
L_32 ,
V_42 ,
V_131 -> V_132 , V_131 -> V_1088 ,
V_131 -> V_1089 , V_131 -> V_147 , V_131 -> V_1090 ,
V_131 -> V_149 ,
V_131 -> V_1091 . V_1092 ,
V_131 -> V_1091 . V_1093 ,
V_131 -> V_1091 . V_1094 ,
V_131 -> V_1091 . V_1095 ) ;
}
}
static void F_259 ( struct V_4 * V_5 )
{
F_182 ( F_23 ( V_5 , V_31 ) ||
V_5 -> V_1096 == F_20 ) ;
F_141 ( V_5 -> V_111 ,
L_33
L_34
L_35
L_36 ) ;
F_82 ( V_5 , V_1097 ) ;
}
static inline T_1 F_260 ( struct V_130 * V_131 )
{
F_261 () ;
return V_131 -> V_1090 -
( ( V_131 -> V_1089 - V_131 -> V_147 ) & ( V_1098 - 1 ) ) ;
}
static void F_262 ( struct V_130 * V_131 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1099 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
T_1 V_1100 = V_131 -> V_147 ;
struct V_1101 * V_1102 ;
int V_1027 = V_131 - V_5 -> V_123 ;
unsigned int V_1103 = 0 , V_1104 = 0 ;
if ( F_23 ( V_5 , V_1105 ) )
V_1027 -- ;
V_1102 = F_263 ( V_5 -> V_111 , V_1027 ) ;
while ( V_1100 != V_1099 ) {
struct V_1106 * V_1107 = & V_131 -> V_1108 [ V_1100 ] ;
struct V_1109 * V_1110 = V_1107 -> V_1110 ;
int V_42 , V_1111 = 0 ;
if ( F_264 ( V_1110 == NULL ) ) {
F_259 ( V_5 ) ;
return;
}
if ( V_131 -> V_1112 [ V_1100 ] . V_1113 & V_1114 ) {
struct V_1041 V_1042 ;
T_6 V_1040 = F_33 ( V_1115 ) ;
V_1040 |= ( T_6 ) F_33 ( V_1116 ) << 32 ;
F_246 ( V_5 , V_1040 , & V_1042 ) ;
F_265 ( V_1110 , & V_1042 ) ;
}
F_266 ( V_5 -> V_12 ,
F_267 ( V_1107 , V_1117 ) ,
F_268 ( V_1110 ) ,
V_1118 ) ;
V_1107 -> V_1110 = NULL ;
while ( V_1107 -> V_1119 ) {
V_1107 -> V_1119 = false ;
V_1100 = F_269 ( V_1100 ) ;
V_1107 = & V_131 -> V_1108 [ V_1100 ] ;
}
V_1100 = F_269 ( V_1100 ) ;
for ( V_42 = 0 ; V_42 < F_270 ( V_1110 ) -> V_1120 ; V_42 ++ ) {
V_1107 = & V_131 -> V_1108 [ V_1100 ] ;
if ( F_264 ( V_1107 -> V_1110 != NULL || V_1100 == V_1099 ) )
V_1111 = 1 ;
F_271 ( V_5 -> V_12 ,
F_267 ( V_1107 , V_1117 ) ,
F_272 ( & F_270 ( V_1110 ) -> V_1121 [ V_42 ] ) ,
V_1118 ) ;
while ( V_1107 -> V_1119 ) {
V_1107 -> V_1119 = false ;
V_1100 = F_269 ( V_1100 ) ;
V_1107 = & V_131 -> V_1108 [ V_1100 ] ;
}
V_1100 = F_269 ( V_1100 ) ;
}
V_1103 ++ ;
V_1104 += V_1110 -> V_74 ;
F_273 ( V_1110 ) ;
if ( F_264 ( V_1111 ) ) {
F_259 ( V_5 ) ;
return;
}
}
F_274 ( V_1102 , V_1103 , V_1104 ) ;
V_131 -> V_147 = V_1100 ;
F_275 () ;
if ( F_264 ( F_276 ( V_1102 ) &&
( F_260 ( V_131 ) > F_277 ( V_131 ) ) ) ) {
F_278 ( V_1102 , F_279 () ) ;
if ( F_276 ( V_1102 ) &&
( F_260 ( V_131 ) > F_277 ( V_131 ) ) )
F_280 ( V_1102 ) ;
F_281 ( V_1102 ) ;
}
}
static void F_282 ( bool V_1122 , void * V_72 )
{
if ( V_1122 )
F_283 ( F_284 ( V_72 ) ) ;
else
F_173 ( V_72 ) ;
}
static void F_285 ( struct V_4 * V_5 , struct V_1123 * V_1107 , T_1 V_1124 )
{
unsigned int V_1125 = F_286 ( V_1124 + F_287 ( V_5 ) ) +
F_286 ( sizeof( struct V_1126 ) ) ;
if ( ! V_1107 -> V_72 )
return;
F_266 ( V_5 -> V_12 , F_267 ( V_1107 , V_1117 ) ,
V_1124 , V_1127 ) ;
F_282 ( V_1125 <= V_1128 , V_1107 -> V_72 ) ;
V_1107 -> V_72 = NULL ;
}
static int F_288 ( struct V_4 * V_5 , struct V_1129 * V_1130 ,
T_1 V_1131 , T_1 V_1132 ,
unsigned int * V_1133 )
{
struct V_1134 * V_1135 ;
struct V_1123 * V_1136 ;
T_4 * V_72 ;
T_9 V_1117 ;
int V_1125 , V_1137 , V_1138 ;
switch ( V_1131 ) {
case V_1139 :
V_1138 = V_1132 & V_5 -> V_1140 ;
V_1135 = & V_1130 -> V_1141 [ V_1138 ] ;
V_1136 = & V_1130 -> V_1142 [ V_1138 ] ;
V_1137 = V_5 -> V_1143 ;
break;
case V_1144 :
V_1138 = V_1132 & V_5 -> V_1145 ;
V_1135 = & V_1130 -> V_1146 [ V_1138 ] . V_1147 ;
V_1136 = & V_1130 -> V_1148 [ V_1138 ] ;
V_1137 = V_1149 ;
break;
default:
return - V_64 ;
}
V_1125 = F_286 ( V_1137 + F_287 ( V_5 ) ) +
F_286 ( sizeof( struct V_1126 ) ) ;
if ( V_1125 <= V_1128 ) {
V_72 = F_289 ( V_1125 ) ;
* V_1133 = V_1125 ;
} else {
V_72 = F_172 ( V_1125 , V_1080 ) ;
* V_1133 = 0 ;
}
if ( ! V_72 )
return - V_264 ;
V_1117 = F_290 ( V_5 -> V_12 ,
V_72 + F_287 ( V_5 ) ,
V_1137 ,
V_1127 ) ;
if ( F_264 ( F_291 ( V_5 -> V_12 , V_1117 ) ) ) {
F_282 ( V_1125 <= V_1128 , V_72 ) ;
return - V_208 ;
}
V_1136 -> V_72 = V_72 ;
F_292 ( V_1136 , V_1117 , V_1117 ) ;
V_1135 -> V_1150 = ( ( T_6 ) V_1117 >> 32 ) ;
V_1135 -> V_1151 = ( ( T_6 ) V_1117 & 0xffffffff ) ;
return V_1137 ;
}
static void F_293 ( struct V_130 * V_131 ,
struct V_1129 * V_1152 ,
T_1 V_1131 , int V_1153 ,
T_1 V_1132 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_1134 * V_1154 , * V_1155 ;
struct V_1123 * V_1156 , * V_1157 ;
struct V_1129 * V_1158 = & V_5 -> V_123 [ 0 ] . V_1091 ;
int V_1138 ;
switch ( V_1131 ) {
case V_1139 :
V_1138 = V_1132 & V_5 -> V_1140 ;
V_1155 = & V_1152 -> V_1141 [ V_1138 ] ;
V_1157 = & V_1152 -> V_1142 [ V_1138 ] ;
V_1154 = & V_1158 -> V_1141 [ V_1153 ] ;
V_1156 = & V_1158 -> V_1142 [ V_1153 ] ;
break;
case V_1144 :
V_1138 = V_1132 & V_5 -> V_1145 ;
V_1155 = & V_1152 -> V_1146 [ V_1138 ] . V_1147 ;
V_1157 = & V_1152 -> V_1148 [ V_1138 ] ;
V_1154 = & V_1158 -> V_1146 [ V_1153 ] . V_1147 ;
V_1156 = & V_1158 -> V_1148 [ V_1153 ] ;
break;
default:
return;
}
V_1157 -> V_72 = V_1156 -> V_72 ;
F_292 ( V_1157 , V_1117 ,
F_267 ( V_1156 , V_1117 ) ) ;
V_1155 -> V_1150 = V_1154 -> V_1150 ;
V_1155 -> V_1151 = V_1154 -> V_1151 ;
F_294 () ;
V_1156 -> V_72 = NULL ;
}
static int F_295 ( struct V_130 * V_131 , int V_1159 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1160 , V_1161 = 0 ;
T_1 V_1162 , V_1163 ;
T_1 V_1100 = V_131 -> V_149 ;
T_3 V_1099 ;
int V_1164 ;
struct V_1129 * V_1130 = & V_131 -> V_1091 ;
V_1099 = * ( V_131 -> V_148 ) ;
F_296 () ;
V_1160 = 0 ;
V_1164 = 0 ;
V_1162 = V_1130 -> V_1092 ;
V_1163 = V_1130 -> V_1094 ;
while ( V_1100 != V_1099 && V_1159 > 0 ) {
struct V_1123 * V_1107 ;
struct V_1134 * V_1135 = & V_131 -> V_1165 [ V_1100 ] ;
unsigned int V_74 ;
struct V_1109 * V_1110 ;
T_9 V_1166 ;
T_1 V_1131 , V_1167 , * V_1168 ;
T_4 * V_72 ;
T_6 V_1169 = 0 ;
V_1167 = V_1135 -> V_1170 & V_1171 ;
V_1131 = V_1135 -> V_1170 & V_1172 ;
if ( V_1131 == V_1139 ) {
V_1107 = & V_5 -> V_123 [ 0 ] . V_1091 . V_1142 [ V_1167 ] ;
V_1166 = F_267 ( V_1107 , V_1117 ) ;
V_72 = V_1107 -> V_72 ;
V_1168 = & V_1162 ;
V_1161 ++ ;
} else if ( V_1131 == V_1144 ) {
V_1107 = & V_5 -> V_123 [ 0 ] . V_1091 . V_1148 [ V_1167 ] ;
V_1166 = F_267 ( V_1107 , V_1117 ) ;
V_72 = V_1107 -> V_72 ;
V_1168 = & V_1163 ;
} else
goto V_1173;
V_1160 |= V_1131 ;
if ( ( V_1135 -> V_1174 & V_1175 ) != 0 &&
( V_1135 -> V_1174 != V_1176 ) ) {
V_1177:
F_293 ( V_131 , V_1130 , V_1131 ,
V_1167 , * V_1168 ) ;
V_1178:
V_5 -> V_1179 ++ ;
goto V_1180;
}
F_297 ( V_72 + F_287 ( V_5 ) ) ;
V_74 = ( ( V_1135 -> V_1181 & V_1182 ) >> V_1183 ) -
V_1184 ;
if ( ( V_1135 -> V_1185 & V_1186 ) ==
V_1187 ||
( V_1135 -> V_1185 & V_1186 ) ==
V_1188 ) {
V_1169 = F_33 ( V_1189 ) ;
V_1169 |= ( T_6 ) F_33 ( V_1190 ) << 32 ;
}
if ( V_74 > F_298 ( V_5 ) ) {
int V_1125 ;
unsigned int V_1133 ;
V_1125 = F_288 ( V_5 , V_1130 , V_1131 ,
* V_1168 , & V_1133 ) ;
if ( V_1125 < 0 )
goto V_1177;
F_266 ( V_5 -> V_12 , V_1166 , V_1125 ,
V_1127 ) ;
V_1110 = F_299 ( V_72 , V_1133 ) ;
if ( ! V_1110 ) {
F_282 ( V_1133 != 0 , V_72 ) ;
goto V_1178;
}
F_300 ( V_1110 , F_287 ( V_5 ) ) ;
F_294 () ;
V_1107 -> V_72 = NULL ;
} else {
F_293 ( V_131 , V_1130 , V_1131 ,
V_1167 , * V_1168 ) ;
V_1110 = F_301 ( V_5 -> V_111 ,
V_74 + V_1191 ) ;
if ( V_1110 == NULL )
goto V_1178;
F_300 ( V_1110 , V_1191 ) ;
F_302 ( V_5 -> V_12 , V_1166 , V_74 , V_1127 ) ;
memcpy ( V_1110 -> V_72 ,
V_72 + F_287 ( V_5 ) ,
V_74 ) ;
F_303 ( V_5 -> V_12 , V_1166 , V_74 , V_1127 ) ;
}
F_304 ( V_1110 , V_74 ) ;
if ( V_1169 )
F_246 ( V_5 , V_1169 ,
F_305 ( V_1110 ) ) ;
if ( ( V_5 -> V_111 -> V_1192 & V_1193 ) &&
( V_1135 -> V_1185 & V_1194 ) &&
( ( ( V_1135 -> V_1195 & V_1196 )
>> V_1197 ) == 0xffff ) )
V_1110 -> V_1198 = V_1199 ;
else
F_306 ( V_1110 ) ;
V_1110 -> V_1200 = F_307 ( V_1110 , V_5 -> V_111 ) ;
if ( V_74 > ( V_5 -> V_111 -> V_1201 + V_1202 ) &&
V_1110 -> V_1200 != F_308 ( V_1203 ) ) {
F_273 ( V_1110 ) ;
goto V_1178;
}
if ( V_1135 -> V_1185 & V_1204 &&
! ( V_5 -> V_352 & V_1205 ) )
F_309 ( V_1110 , F_308 ( V_1203 ) ,
V_1135 -> V_1174 & V_1206 ) ;
F_310 ( & V_131 -> V_123 , V_1110 ) ;
V_1164 ++ ;
V_1159 -- ;
V_1180:
( * V_1168 ) ++ ;
if ( F_264 ( V_1161 >= V_5 -> V_1207 ) ) {
V_1130 -> V_1092 = V_1162 &
V_5 -> V_1140 ;
F_311 ( V_18 ,
V_1130 -> V_1092 ) ;
V_1160 &= ~ V_1139 ;
V_1161 = 0 ;
}
V_1173:
V_1100 ++ ;
V_1100 &= V_5 -> V_1208 ;
if ( V_1100 == V_1099 ) {
V_1099 = * ( V_131 -> V_148 ) ;
F_296 () ;
}
}
V_131 -> V_149 = V_1100 ;
F_311 ( V_131 -> V_1209 , V_1100 ) ;
if ( ! F_23 ( V_5 , V_1210 ) ) {
F_49 () ;
if ( V_1160 & V_1139 ) {
V_1130 -> V_1092 = V_1162 &
V_5 -> V_1140 ;
F_311 ( V_18 ,
V_1130 -> V_1092 ) ;
}
if ( V_1160 & V_1144 ) {
V_1130 -> V_1094 = V_1163 &
V_5 -> V_1145 ;
F_311 ( V_1211 ,
V_1130 -> V_1094 ) ;
}
F_53 () ;
} else if ( V_1160 ) {
F_294 () ;
V_1130 -> V_1092 = V_1162 & V_5 -> V_1140 ;
V_1130 -> V_1094 = V_1163 & V_5 -> V_1145 ;
if ( V_131 != & V_5 -> V_123 [ 1 ] ) {
V_5 -> V_1212 = true ;
F_312 ( & V_5 -> V_123 [ 1 ] . V_123 ) ;
}
}
return V_1164 ;
}
static void F_313 ( struct V_4 * V_5 )
{
if ( ! ( F_23 ( V_5 , V_142 ) || F_23 ( V_5 , V_143 ) ) ) {
struct V_139 * V_140 = V_5 -> V_123 [ 0 ] . V_134 ;
if ( V_140 -> V_57 & V_144 ) {
V_140 -> V_57 = V_135 |
( V_140 -> V_57 & ~ V_144 ) ;
F_314 ( & V_5 -> V_207 ) ;
if ( F_23 ( V_5 , V_263 ) ) {
F_31 ( V_789 ,
( V_790 |
V_791 |
V_792 |
V_793 ) ) ;
F_24 ( 40 ) ;
} else
F_198 ( V_5 , false ) ;
F_315 ( & V_5 -> V_207 ) ;
}
}
}
static int F_316 ( struct V_4 * V_5 ,
struct V_1129 * V_1152 ,
struct V_1129 * V_1158 )
{
T_1 V_1213 , V_1214 , V_1215 , V_1216 ;
int V_42 , V_75 = 0 ;
while ( 1 ) {
V_1216 = V_1158 -> V_1092 ;
F_317 () ;
if ( V_1158 -> V_1093 == V_1216 )
break;
if ( V_1158 -> V_1093 < V_1216 )
V_1215 = V_1216 - V_1158 -> V_1093 ;
else
V_1215 = V_5 -> V_1140 + 1 -
V_1158 -> V_1093 ;
V_1215 = F_318 ( V_1215 ,
V_5 -> V_1140 + 1 - V_1152 -> V_1092 ) ;
V_1213 = V_1158 -> V_1093 ;
V_1214 = V_1152 -> V_1092 ;
for ( V_42 = V_1214 ; V_42 < V_1214 + V_1215 ; V_42 ++ ) {
if ( V_1152 -> V_1142 [ V_42 ] . V_72 ) {
V_1215 = V_42 - V_1214 ;
V_75 = - V_1217 ;
break;
}
}
if ( ! V_1215 )
break;
F_317 () ;
memcpy ( & V_1152 -> V_1142 [ V_1214 ] ,
& V_1158 -> V_1142 [ V_1213 ] ,
V_1215 * sizeof( struct V_1123 ) ) ;
for ( V_42 = 0 ; V_42 < V_1215 ; V_42 ++ , V_1214 ++ , V_1213 ++ ) {
struct V_1134 * V_1218 , * V_1219 ;
V_1218 = & V_1158 -> V_1141 [ V_1213 ] ;
V_1219 = & V_1152 -> V_1141 [ V_1214 ] ;
V_1219 -> V_1150 = V_1218 -> V_1150 ;
V_1219 -> V_1151 = V_1218 -> V_1151 ;
}
V_1158 -> V_1093 = ( V_1158 -> V_1093 + V_1215 ) &
V_5 -> V_1140 ;
V_1152 -> V_1092 = ( V_1152 -> V_1092 + V_1215 ) &
V_5 -> V_1140 ;
}
while ( 1 ) {
V_1216 = V_1158 -> V_1094 ;
F_317 () ;
if ( V_1158 -> V_1095 == V_1216 )
break;
if ( V_1158 -> V_1095 < V_1216 )
V_1215 = V_1216 - V_1158 -> V_1095 ;
else
V_1215 = V_5 -> V_1145 + 1 -
V_1158 -> V_1095 ;
V_1215 = F_318 ( V_1215 ,
V_5 -> V_1145 + 1 - V_1152 -> V_1094 ) ;
V_1213 = V_1158 -> V_1095 ;
V_1214 = V_1152 -> V_1094 ;
for ( V_42 = V_1214 ; V_42 < V_1214 + V_1215 ; V_42 ++ ) {
if ( V_1152 -> V_1148 [ V_42 ] . V_72 ) {
V_1215 = V_42 - V_1214 ;
V_75 = - V_1217 ;
break;
}
}
if ( ! V_1215 )
break;
F_317 () ;
memcpy ( & V_1152 -> V_1148 [ V_1214 ] ,
& V_1158 -> V_1148 [ V_1213 ] ,
V_1215 * sizeof( struct V_1123 ) ) ;
for ( V_42 = 0 ; V_42 < V_1215 ; V_42 ++ , V_1214 ++ , V_1213 ++ ) {
struct V_1134 * V_1218 , * V_1219 ;
V_1218 = & V_1158 -> V_1146 [ V_1213 ] . V_1147 ;
V_1219 = & V_1152 -> V_1146 [ V_1214 ] . V_1147 ;
V_1219 -> V_1150 = V_1218 -> V_1150 ;
V_1219 -> V_1151 = V_1218 -> V_1151 ;
}
V_1158 -> V_1095 = ( V_1158 -> V_1095 + V_1215 ) &
V_5 -> V_1145 ;
V_1152 -> V_1094 = ( V_1152 -> V_1094 + V_1215 ) &
V_5 -> V_1145 ;
}
return V_75 ;
}
static int F_319 ( struct V_130 * V_131 , int V_1220 , int V_1159 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
if ( V_131 -> V_134 -> V_145 [ 0 ] . V_146 != V_131 -> V_147 ) {
F_262 ( V_131 ) ;
if ( F_264 ( F_23 ( V_5 , V_1097 ) ) )
return V_1220 ;
}
if ( ! V_131 -> V_148 )
return V_1220 ;
if ( * ( V_131 -> V_148 ) != V_131 -> V_149 )
V_1220 += F_295 ( V_131 , V_1159 - V_1220 ) ;
if ( F_23 ( V_5 , V_1210 ) && V_131 == & V_5 -> V_123 [ 1 ] ) {
struct V_1129 * V_1152 = & V_5 -> V_123 [ 0 ] . V_1091 ;
int V_42 , V_75 = 0 ;
T_1 V_1162 = V_1152 -> V_1092 ;
T_1 V_1163 = V_1152 -> V_1094 ;
V_5 -> V_1212 = false ;
for ( V_42 = 1 ; V_42 <= V_5 -> V_1221 ; V_42 ++ )
V_75 |= F_316 ( V_5 , V_1152 ,
& V_5 -> V_123 [ V_42 ] . V_1091 ) ;
F_49 () ;
if ( V_1162 != V_1152 -> V_1092 )
F_311 ( V_18 ,
V_1152 -> V_1092 ) ;
if ( V_1163 != V_1152 -> V_1094 )
F_311 ( V_1211 ,
V_1152 -> V_1094 ) ;
F_53 () ;
if ( V_75 )
F_31 ( V_138 , V_5 -> V_126 ) ;
}
return V_1220 ;
}
static inline void F_320 ( struct V_4 * V_5 )
{
if ( ! F_321 ( V_1222 , V_5 -> V_1223 ) )
F_322 ( & V_5 -> V_1224 ) ;
}
static inline void F_323 ( struct V_4 * V_5 )
{
F_324 ( & V_5 -> V_1224 ) ;
F_84 ( V_5 , V_1225 ) ;
F_84 ( V_5 , V_1097 ) ;
}
static int F_325 ( struct V_1226 * V_123 , int V_1159 )
{
struct V_130 * V_131 = F_236 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1220 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
V_1220 = F_319 ( V_131 , V_1220 , V_1159 ) ;
if ( F_264 ( F_23 ( V_5 , V_1097 ) ) )
goto V_1227;
if ( F_264 ( V_1220 >= V_1159 ) )
break;
V_131 -> V_132 = V_140 -> V_1083 ;
V_131 -> V_1088 = V_131 -> V_132 ;
F_296 () ;
if ( F_326 ( V_140 -> V_145 [ 0 ] . V_146 == V_131 -> V_147 &&
* ( V_131 -> V_148 ) == V_131 -> V_149 ) ) {
if ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1212 )
continue;
F_327 ( V_123 ) ;
F_52 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
if ( F_264 ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1212 ) ) {
F_46 ( V_138 , V_5 -> V_127 |
V_128 |
V_131 -> V_126 ) ;
}
F_53 () ;
break;
}
}
return V_1220 ;
V_1227:
F_327 ( V_123 ) ;
F_320 ( V_5 ) ;
return V_1220 ;
}
static void F_328 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_1228 = false ;
if ( F_23 ( V_5 , V_1229 ) )
return;
V_7 = F_33 ( V_1230 ) ;
if ( V_7 & ~ V_1231 ) {
F_183 ( V_5 -> V_111 , L_37 ) ;
V_1228 = true ;
}
if ( F_33 ( V_1232 ) & ~ V_1233 ) {
F_183 ( V_5 -> V_111 , L_38 ) ;
V_1228 = true ;
}
if ( F_33 ( V_1234 ) || F_33 ( V_1235 ) ) {
F_183 ( V_5 -> V_111 , L_39 ) ;
V_1228 = true ;
}
if ( ! V_1228 )
return;
F_257 ( V_5 ) ;
F_82 ( V_5 , V_1229 ) ;
F_320 ( V_5 ) ;
}
static int F_329 ( struct V_1226 * V_123 , int V_1159 )
{
struct V_130 * V_131 = F_236 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1220 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
if ( V_140 -> V_57 & V_1236 )
F_328 ( V_5 ) ;
F_313 ( V_5 ) ;
V_1220 = F_319 ( V_131 , V_1220 , V_1159 ) ;
if ( F_264 ( F_23 ( V_5 , V_1097 ) ) )
goto V_1227;
if ( F_264 ( V_1220 >= V_1159 ) )
break;
if ( F_23 ( V_5 , V_133 ) ) {
V_131 -> V_132 = V_140 -> V_1083 ;
V_131 -> V_1088 = V_131 -> V_132 ;
F_296 () ;
} else
V_140 -> V_57 &= ~ V_135 ;
if ( F_326 ( ! F_50 ( V_131 ) ) ) {
F_327 ( V_123 ) ;
F_51 ( V_131 ) ;
break;
}
}
return V_1220 ;
V_1227:
F_327 ( V_123 ) ;
F_320 ( V_5 ) ;
return V_1220 ;
}
static void F_330 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- )
F_331 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static void F_332 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_333 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static void F_334 ( struct V_4 * V_5 )
{
int V_42 ;
F_335 ( V_5 -> V_111 , & V_5 -> V_123 [ 0 ] . V_123 , F_329 , 64 ) ;
for ( V_42 = 1 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_335 ( V_5 -> V_111 , & V_5 -> V_123 [ V_42 ] . V_123 , F_325 , 64 ) ;
}
static void F_336 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_337 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static inline void F_338 ( struct V_4 * V_5 )
{
V_5 -> V_111 -> V_1237 = V_295 ;
F_330 ( V_5 ) ;
F_139 ( V_5 -> V_111 ) ;
F_339 ( V_5 -> V_111 ) ;
}
static inline void F_340 ( struct V_4 * V_5 )
{
F_251 ( V_5 ) ;
F_341 ( V_5 -> V_111 ) ;
if ( V_5 -> V_338 )
F_217 ( V_5 -> V_111 ) ;
F_332 ( V_5 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 |= V_135 ;
F_48 ( V_5 ) ;
}
static void F_342 ( struct V_4 * V_5 )
{
int V_42 ;
F_182 ( V_5 -> V_125 ) ;
V_5 -> V_125 = 1 ;
F_275 () ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_343 ( V_5 -> V_123 [ V_42 ] . V_1238 ) ;
}
static inline void F_238 ( struct V_4 * V_5 , int V_125 )
{
F_69 ( & V_5 -> V_207 ) ;
if ( V_125 )
F_342 ( V_5 ) ;
}
static inline void F_239 ( struct V_4 * V_5 )
{
F_70 ( & V_5 -> V_207 ) ;
}
static T_10 F_344 ( int V_276 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_297 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1165 )
F_297 ( & V_131 -> V_1165 [ V_131 -> V_149 ] ) ;
if ( F_326 ( ! F_254 ( V_5 ) ) )
F_312 ( & V_131 -> V_123 ) ;
return V_1240 ;
}
static T_10 F_345 ( int V_276 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_297 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1165 )
F_297 ( & V_131 -> V_1165 [ V_131 -> V_149 ] ) ;
F_52 ( V_131 -> V_124 , 0x00000001 ) ;
if ( F_326 ( ! F_254 ( V_5 ) ) )
F_312 ( & V_131 -> V_123 ) ;
return F_346 ( 1 ) ;
}
static T_10 F_347 ( int V_276 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1241 = 1 ;
if ( F_264 ( ! ( V_140 -> V_57 & V_135 ) ) ) {
if ( F_23 ( V_5 , V_1242 ) ||
( F_33 ( V_1243 ) & V_1244 ) ) {
V_1241 = 0 ;
goto V_502;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
if ( F_254 ( V_5 ) )
goto V_502;
V_140 -> V_57 &= ~ V_135 ;
if ( F_326 ( F_50 ( V_131 ) ) ) {
F_297 ( & V_131 -> V_1165 [ V_131 -> V_149 ] ) ;
F_312 ( & V_131 -> V_123 ) ;
} else {
F_47 ( V_20 + V_16 ,
0x00000000 ) ;
}
V_502:
return F_346 ( V_1241 ) ;
}
static T_10 F_348 ( int V_276 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1241 = 1 ;
if ( F_264 ( V_140 -> V_1083 == V_131 -> V_1088 ) ) {
if ( F_23 ( V_5 , V_1242 ) ||
( F_33 ( V_1243 ) & V_1244 ) ) {
V_1241 = 0 ;
goto V_502;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
V_131 -> V_1088 = V_140 -> V_1083 ;
if ( F_254 ( V_5 ) )
goto V_502;
F_297 ( & V_131 -> V_1165 [ V_131 -> V_149 ] ) ;
F_312 ( & V_131 -> V_123 ) ;
V_502:
return F_346 ( V_1241 ) ;
}
static T_10 F_349 ( int V_276 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
if ( ( V_140 -> V_57 & V_135 ) ||
! ( F_33 ( V_1243 ) & V_1244 ) ) {
F_45 ( V_5 ) ;
return F_346 ( 1 ) ;
}
return F_346 ( 0 ) ;
}
static void F_350 ( struct V_362 * V_111 )
{
int V_42 ;
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( F_254 ( V_5 ) )
return;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_347 ( V_5 -> V_123 [ V_42 ] . V_1238 , & V_5 -> V_123 [ V_42 ] ) ;
}
static void F_351 ( struct V_362 * V_111 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( F_352 ( V_5 ) ) {
F_183 ( V_111 , L_40 ) ;
F_257 ( V_5 ) ;
}
F_320 ( V_5 ) ;
}
static inline int F_353 ( T_9 V_1117 , int V_74 )
{
T_1 V_1245 = ( T_1 ) V_1117 & 0xffffffff ;
return ( V_1245 > 0xffffdcc0 ) && ( V_1245 + V_74 + 8 < V_1245 ) ;
}
static inline int F_354 ( struct V_4 * V_5 , T_9 V_1117 ,
T_1 V_74 , T_1 V_1246 )
{
if ( F_30 ( V_5 ) == V_765 && V_1246 ) {
T_1 V_1245 = ( T_1 ) V_1117 & 0xffffffff ;
return ( ( V_1245 + V_74 + ( V_1246 & 0x3fff ) ) < V_1245 ) ;
}
return 0 ;
}
static inline int F_355 ( struct V_4 * V_5 , T_9 V_1117 ,
int V_74 )
{
#if F_356 ( V_1247 ) && ( V_1248 == 64 )
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) )
return ( ( T_6 ) V_1117 + V_74 ) > F_357 ( 40 ) ;
return 0 ;
#else
return 0 ;
#endif
}
static inline void F_358 ( struct V_1249 * V_1250 ,
T_9 V_1117 , T_1 V_74 , T_1 V_10 ,
T_1 V_1246 , T_1 V_1251 )
{
V_1250 -> V_1150 = ( ( T_6 ) V_1117 >> 32 ) ;
V_1250 -> V_1151 = ( ( T_6 ) V_1117 & 0xffffffff ) ;
V_1250 -> V_1113 = ( V_74 << V_1252 ) | ( V_10 & 0x0000ffff ) ;
V_1250 -> V_1253 = ( V_1246 << V_1254 ) | ( V_1251 << V_1255 ) ;
}
static bool F_359 ( struct V_130 * V_131 , T_1 * V_1256 , T_1 * V_1159 ,
T_9 V_1136 , T_1 V_74 , T_1 V_10 ,
T_1 V_1246 , T_1 V_1251 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
bool V_1257 = false ;
if ( F_23 ( V_5 , V_1258 ) && V_74 <= 8 )
V_1257 = true ;
if ( F_353 ( V_1136 , V_74 ) )
V_1257 = true ;
if ( F_354 ( V_5 , V_1136 , V_74 , V_1246 ) )
V_1257 = true ;
if ( F_355 ( V_5 , V_1136 , V_74 ) )
V_1257 = true ;
if ( V_5 -> V_1259 ) {
T_1 V_1260 = * V_1256 ;
T_1 V_1261 = V_10 & ~ V_1262 ;
while ( V_74 > V_5 -> V_1259 && * V_1159 ) {
T_1 V_1263 = V_5 -> V_1259 ;
V_74 -= V_5 -> V_1259 ;
if ( V_74 <= 8 ) {
V_74 += V_5 -> V_1259 / 2 ;
V_1263 = V_5 -> V_1259 / 2 ;
}
V_131 -> V_1108 [ * V_1256 ] . V_1119 = true ;
F_358 ( & V_131 -> V_1112 [ * V_1256 ] , V_1136 ,
V_1263 , V_1261 , V_1246 , V_1251 ) ;
* V_1159 -= 1 ;
V_1260 = * V_1256 ;
* V_1256 = F_269 ( * V_1256 ) ;
V_1136 += V_1263 ;
}
if ( V_74 ) {
if ( * V_1159 ) {
F_358 ( & V_131 -> V_1112 [ * V_1256 ] , V_1136 ,
V_74 , V_10 , V_1246 , V_1251 ) ;
* V_1159 -= 1 ;
* V_1256 = F_269 ( * V_1256 ) ;
} else {
V_1257 = true ;
V_131 -> V_1108 [ V_1260 ] . V_1119 = false ;
}
}
} else {
F_358 ( & V_131 -> V_1112 [ * V_1256 ] , V_1136 ,
V_74 , V_10 , V_1246 , V_1251 ) ;
* V_1256 = F_269 ( * V_1256 ) ;
}
return V_1257 ;
}
static void F_360 ( struct V_130 * V_131 , T_1 V_1256 , int V_1264 )
{
int V_42 ;
struct V_1109 * V_1110 ;
struct V_1106 * V_1265 = & V_131 -> V_1108 [ V_1256 ] ;
V_1110 = V_1265 -> V_1110 ;
V_1265 -> V_1110 = NULL ;
F_266 ( V_131 -> V_5 -> V_12 ,
F_267 ( V_1265 , V_1117 ) ,
F_268 ( V_1110 ) ,
V_1118 ) ;
while ( V_1265 -> V_1119 ) {
V_1265 -> V_1119 = false ;
V_1256 = F_269 ( V_1256 ) ;
V_1265 = & V_131 -> V_1108 [ V_1256 ] ;
}
for ( V_42 = 0 ; V_42 <= V_1264 ; V_42 ++ ) {
const T_11 * V_1266 = & F_270 ( V_1110 ) -> V_1121 [ V_42 ] ;
V_1256 = F_269 ( V_1256 ) ;
V_1265 = & V_131 -> V_1108 [ V_1256 ] ;
F_271 ( V_131 -> V_5 -> V_12 ,
F_267 ( V_1265 , V_1117 ) ,
F_272 ( V_1266 ) , V_1118 ) ;
while ( V_1265 -> V_1119 ) {
V_1265 -> V_1119 = false ;
V_1256 = F_269 ( V_1256 ) ;
V_1265 = & V_131 -> V_1108 [ V_1256 ] ;
}
}
}
static int F_361 ( struct V_130 * V_131 ,
struct V_1109 * * V_1267 ,
T_1 * V_1256 , T_1 * V_1159 ,
T_1 V_1268 , T_1 V_1246 , T_1 V_1251 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_1109 * V_1269 , * V_1110 = * V_1267 ;
T_9 V_1270 = 0 ;
int V_56 = 0 ;
if ( F_30 ( V_5 ) != V_537 )
V_1269 = F_362 ( V_1110 , V_1080 ) ;
else {
int V_1271 = 4 - ( ( unsigned long ) V_1110 -> V_72 & 3 ) ;
V_1269 = F_363 ( V_1110 ,
F_364 ( V_1110 ) + V_1271 ,
F_365 ( V_1110 ) , V_1080 ) ;
}
if ( ! V_1269 ) {
V_56 = - 1 ;
} else {
V_1270 = F_290 ( V_5 -> V_12 , V_1269 -> V_72 , V_1269 -> V_74 ,
V_1118 ) ;
if ( F_291 ( V_5 -> V_12 , V_1270 ) ) {
F_273 ( V_1269 ) ;
V_56 = - 1 ;
} else {
T_1 V_1272 = * V_1256 ;
V_1268 |= V_1262 ;
V_131 -> V_1108 [ * V_1256 ] . V_1110 = V_1269 ;
F_292 ( & V_131 -> V_1108 [ * V_1256 ] ,
V_1117 , V_1270 ) ;
if ( F_359 ( V_131 , V_1256 , V_1159 , V_1270 ,
V_1269 -> V_74 , V_1268 ,
V_1246 , V_1251 ) ) {
F_360 ( V_131 , V_1272 , - 1 ) ;
F_273 ( V_1269 ) ;
V_56 = - 1 ;
}
}
}
F_273 ( V_1110 ) ;
* V_1267 = V_1269 ;
return V_56 ;
}
static int F_366 ( struct V_4 * V_5 , struct V_1109 * V_1110 )
{
struct V_1109 * V_1273 , * V_1274 ;
T_1 V_1275 = F_270 ( V_1110 ) -> V_1276 * 3 ;
if ( F_264 ( F_260 ( & V_5 -> V_123 [ 0 ] ) <= V_1275 ) ) {
F_367 ( V_5 -> V_111 ) ;
F_275 () ;
if ( F_260 ( & V_5 -> V_123 [ 0 ] ) <= V_1275 )
return V_1277 ;
F_368 ( V_5 -> V_111 ) ;
}
V_1273 = F_369 ( V_1110 , V_5 -> V_111 -> V_1192 & ~ V_1278 ) ;
if ( F_114 ( V_1273 ) )
goto V_1279;
do {
V_1274 = V_1273 ;
V_1273 = V_1273 -> V_1280 ;
V_1274 -> V_1280 = NULL ;
F_370 ( V_1274 , V_5 -> V_111 ) ;
} while ( V_1273 );
V_1279:
F_273 ( V_1110 ) ;
return V_1281 ;
}
static T_12 F_370 ( struct V_1109 * V_1110 , struct V_362 * V_111 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
T_1 V_74 , V_1256 , V_1268 , V_1246 , V_1251 = 0 ;
T_1 V_1159 ;
int V_42 = - 1 , V_1282 ;
T_9 V_1117 ;
struct V_130 * V_131 ;
struct V_1101 * V_1102 ;
unsigned int V_1264 ;
V_1102 = F_263 ( V_111 , F_371 ( V_1110 ) ) ;
V_131 = & V_5 -> V_123 [ F_371 ( V_1110 ) ] ;
if ( F_23 ( V_5 , V_1105 ) )
V_131 ++ ;
V_1159 = F_260 ( V_131 ) ;
if ( F_264 ( V_1159 <= ( F_270 ( V_1110 ) -> V_1120 + 1 ) ) ) {
if ( ! F_276 ( V_1102 ) ) {
F_372 ( V_1102 ) ;
F_183 ( V_111 ,
L_41 ) ;
}
return V_1277 ;
}
V_1256 = V_131 -> V_1089 ;
V_1268 = 0 ;
if ( V_1110 -> V_1198 == V_1283 )
V_1268 |= V_1284 ;
V_1246 = F_270 ( V_1110 ) -> V_1285 ;
if ( V_1246 ) {
struct V_1286 * V_1287 ;
T_1 V_1288 , V_1289 ;
if ( F_373 ( V_1110 ) &&
F_374 ( V_1110 , 0 , 0 , V_1080 ) )
goto V_1290;
V_1287 = F_375 ( V_1110 ) ;
V_1288 = F_376 ( V_1110 ) ;
V_1289 = F_377 ( V_1110 ) + F_378 ( V_1110 ) - V_1202 ;
if ( ! F_379 ( V_1110 ) ) {
V_1287 -> V_1291 = 0 ;
V_1287 -> V_1292 = F_308 ( V_1246 + V_1289 ) ;
}
if ( F_264 ( ( V_1202 + V_1289 ) > 80 ) &&
F_23 ( V_5 , V_1293 ) )
return F_366 ( V_5 , V_1110 ) ;
V_1268 |= ( V_1294 |
V_1295 ) ;
if ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ) {
F_380 ( V_1110 ) -> V_1291 = 0 ;
V_1268 &= ~ V_1284 ;
} else
F_380 ( V_1110 ) -> V_1291 = ~ F_381 ( V_1287 -> V_1299 ,
V_1287 -> V_1300 , 0 ,
V_1301 ,
0 ) ;
if ( F_23 ( V_5 , V_1298 ) ) {
V_1246 |= ( V_1289 & 0xc ) << 12 ;
if ( V_1289 & 0x10 )
V_1268 |= 0x00000010 ;
V_1268 |= ( V_1289 & 0x3e0 ) << 5 ;
} else if ( F_23 ( V_5 , V_1297 ) )
V_1246 |= V_1289 << 9 ;
else if ( F_23 ( V_5 , V_1296 ) ||
F_30 ( V_5 ) == V_501 ) {
if ( V_1288 || V_1287 -> V_1302 > 5 ) {
int V_1303 ;
V_1303 = ( V_1287 -> V_1302 - 5 ) + ( V_1288 >> 2 ) ;
V_1246 |= ( V_1303 << 11 ) ;
}
} else {
if ( V_1288 || V_1287 -> V_1302 > 5 ) {
int V_1303 ;
V_1303 = ( V_1287 -> V_1302 - 5 ) + ( V_1288 >> 2 ) ;
V_1268 |= V_1303 << 12 ;
}
}
}
if ( F_23 ( V_5 , V_1304 ) &&
! V_1246 && V_1110 -> V_74 > V_1305 )
V_1268 |= V_1306 ;
if ( F_382 ( V_1110 ) ) {
V_1268 |= V_1307 ;
V_1251 = F_383 ( V_1110 ) ;
}
if ( ( F_264 ( F_270 ( V_1110 ) -> V_1308 & V_1309 ) ) &&
F_23 ( V_5 , V_1310 ) ) {
F_270 ( V_1110 ) -> V_1308 |= V_1311 ;
V_1268 |= V_1114 ;
}
V_74 = F_268 ( V_1110 ) ;
V_1117 = F_290 ( V_5 -> V_12 , V_1110 -> V_72 , V_74 , V_1118 ) ;
if ( F_291 ( V_5 -> V_12 , V_1117 ) )
goto V_1290;
V_131 -> V_1108 [ V_1256 ] . V_1110 = V_1110 ;
F_292 ( & V_131 -> V_1108 [ V_1256 ] , V_1117 , V_1117 ) ;
V_1282 = 0 ;
if ( F_23 ( V_5 , 5701_DMA_BUG ) )
V_1282 = 1 ;
if ( F_359 ( V_131 , & V_1256 , & V_1159 , V_1117 , V_74 , V_1268 |
( ( F_270 ( V_1110 ) -> V_1120 == 0 ) ? V_1262 : 0 ) ,
V_1246 , V_1251 ) ) {
V_1282 = 1 ;
} else if ( F_270 ( V_1110 ) -> V_1120 > 0 ) {
T_1 V_1312 = V_1246 ;
if ( ! F_23 ( V_5 , V_1296 ) &&
! F_23 ( V_5 , V_1297 ) &&
! F_23 ( V_5 , V_1298 ) )
V_1312 = 0 ;
V_1264 = F_270 ( V_1110 ) -> V_1120 - 1 ;
for ( V_42 = 0 ; V_42 <= V_1264 ; V_42 ++ ) {
T_11 * V_1266 = & F_270 ( V_1110 ) -> V_1121 [ V_42 ] ;
V_74 = F_272 ( V_1266 ) ;
V_1117 = F_384 ( & V_5 -> V_12 -> V_111 , V_1266 , 0 ,
V_74 , V_1313 ) ;
V_131 -> V_1108 [ V_1256 ] . V_1110 = NULL ;
F_292 ( & V_131 -> V_1108 [ V_1256 ] , V_1117 ,
V_1117 ) ;
if ( F_385 ( & V_5 -> V_12 -> V_111 , V_1117 ) )
goto V_1314;
if ( ! V_1159 ||
F_359 ( V_131 , & V_1256 , & V_1159 , V_1117 ,
V_74 , V_1268 |
( ( V_42 == V_1264 ) ? V_1262 : 0 ) ,
V_1312 , V_1251 ) ) {
V_1282 = 1 ;
break;
}
}
}
if ( V_1282 ) {
F_360 ( V_131 , V_131 -> V_1089 , V_42 ) ;
V_1256 = V_131 -> V_1089 ;
V_1159 = F_260 ( V_131 ) ;
if ( F_361 ( V_131 , & V_1110 , & V_1256 , & V_1159 ,
V_1268 , V_1246 , V_1251 ) )
goto V_1315;
}
F_386 ( V_1110 ) ;
F_387 ( V_1102 , V_1110 -> V_74 ) ;
F_49 () ;
F_388 ( V_131 -> V_1316 , V_1256 ) ;
V_131 -> V_1089 = V_1256 ;
if ( F_264 ( F_260 ( V_131 ) <= ( V_1317 + 1 ) ) ) {
F_372 ( V_1102 ) ;
F_275 () ;
if ( F_260 ( V_131 ) > F_277 ( V_131 ) )
F_280 ( V_1102 ) ;
}
F_53 () ;
return V_1281 ;
V_1314:
F_360 ( V_131 , V_131 -> V_1089 , -- V_42 ) ;
V_131 -> V_1108 [ V_131 -> V_1089 ] . V_1110 = NULL ;
V_1290:
F_273 ( V_1110 ) ;
V_1315:
V_5 -> V_1318 ++ ;
return V_1281 ;
}
static void F_389 ( struct V_4 * V_5 , bool V_195 )
{
if ( V_195 ) {
V_5 -> V_365 &= ~ ( V_369 |
V_368 ) ;
V_5 -> V_365 |= V_832 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_365 |= V_723 ;
if ( V_5 -> V_178 & V_390 )
V_5 -> V_365 |= V_372 ;
else
V_5 -> V_365 |= V_373 ;
} else {
V_5 -> V_365 &= ~ V_832 ;
if ( F_23 ( V_5 , 5705_PLUS ) ||
( V_5 -> V_178 & V_567 ) ||
F_30 ( V_5 ) == V_536 )
V_5 -> V_365 &= ~ V_723 ;
}
F_46 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
}
static int F_390 ( struct V_4 * V_5 , T_1 V_370 , bool V_1319 )
{
T_1 V_7 , V_771 , V_365 , V_1320 = 0 ;
F_126 ( V_5 , false ) ;
F_127 ( V_5 , false ) ;
if ( V_1319 && F_124 ( V_5 ) )
return - V_208 ;
V_771 = V_492 ;
switch ( V_370 ) {
case V_371 :
break;
case V_330 :
V_771 |= V_773 ;
break;
case V_329 :
default:
if ( V_5 -> V_178 & V_179 ) {
V_370 = V_330 ;
V_771 |= V_773 ;
} else {
V_370 = V_329 ;
V_771 |= V_493 ;
}
}
if ( V_1319 ) {
if ( ! ( V_5 -> V_178 & V_179 ) ) {
F_57 ( V_5 , V_180 , & V_7 ) ;
V_7 |= V_494 |
V_495 ;
F_59 ( V_5 , V_180 , V_7 ) ;
} else {
V_1320 = V_1321 |
V_1322 ;
F_59 ( V_5 , V_524 , V_1320 ) ;
}
} else
V_771 |= V_774 ;
F_59 ( V_5 , V_202 , V_771 ) ;
if ( V_5 -> V_178 & V_179 )
F_57 ( V_5 , V_202 , & V_771 ) ;
F_24 ( 40 ) ;
if ( ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) == V_256 ) {
F_59 ( V_5 , V_524 , V_1320 |
V_1323 |
V_1324 ) ;
F_57 ( V_5 , V_524 , & V_7 ) ;
}
if ( ( V_5 -> V_178 & V_302 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_31 ( V_359 , V_1325 ) ;
F_24 ( 10 ) ;
F_31 ( V_359 , V_5 -> V_352 ) ;
}
V_365 = V_5 -> V_365 &
~ ( V_368 | V_369 ) ;
if ( V_370 == V_329 )
V_365 |= V_373 ;
else
V_365 |= V_372 ;
if ( F_30 ( V_5 ) == V_536 ) {
T_1 V_1326 = V_5 -> V_215 & V_398 ;
if ( V_1326 == V_399 )
V_365 &= ~ V_723 ;
else if ( V_1326 == V_565 )
V_365 |= V_723 ;
F_59 ( V_5 , V_491 ,
V_819 ) ;
}
F_46 ( V_380 , V_365 ) ;
F_24 ( 40 ) ;
return 0 ;
}
static void F_391 ( struct V_362 * V_111 , T_13 V_1192 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( V_1192 & V_1327 ) {
if ( V_5 -> V_365 & V_832 )
return;
F_69 ( & V_5 -> V_207 ) ;
F_389 ( V_5 , true ) ;
F_217 ( V_5 -> V_111 ) ;
F_70 ( & V_5 -> V_207 ) ;
F_96 ( V_111 , L_42 ) ;
} else {
if ( ! ( V_5 -> V_365 & V_832 ) )
return;
F_69 ( & V_5 -> V_207 ) ;
F_389 ( V_5 , false ) ;
F_198 ( V_5 , true ) ;
F_70 ( & V_5 -> V_207 ) ;
F_96 ( V_111 , L_43 ) ;
}
}
static T_13 F_392 ( struct V_362 * V_111 ,
T_13 V_1192 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( V_111 -> V_1201 > V_1328 && F_23 ( V_5 , 5780_CLASS ) )
V_1192 &= ~ V_1329 ;
return V_1192 ;
}
static int F_393 ( struct V_362 * V_111 , T_13 V_1192 )
{
T_13 V_1330 = V_111 -> V_1192 ^ V_1192 ;
if ( ( V_1330 & V_1327 ) && F_143 ( V_111 ) )
F_391 ( V_111 , V_1192 ) ;
return 0 ;
}
static void F_394 ( struct V_4 * V_5 ,
struct V_1129 * V_1130 )
{
int V_42 ;
if ( V_1130 != & V_5 -> V_123 [ 0 ] . V_1091 ) {
for ( V_42 = V_1130 -> V_1093 ; V_42 != V_1130 -> V_1092 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1140 )
F_285 ( V_5 , & V_1130 -> V_1142 [ V_42 ] ,
V_5 -> V_1143 ) ;
if ( F_23 ( V_5 , V_521 ) ) {
for ( V_42 = V_1130 -> V_1095 ;
V_42 != V_1130 -> V_1094 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1145 ) {
F_285 ( V_5 , & V_1130 -> V_1148 [ V_42 ] ,
V_1149 ) ;
}
}
return;
}
for ( V_42 = 0 ; V_42 <= V_5 -> V_1140 ; V_42 ++ )
F_285 ( V_5 , & V_1130 -> V_1142 [ V_42 ] ,
V_5 -> V_1143 ) ;
if ( F_23 ( V_5 , V_521 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
for ( V_42 = 0 ; V_42 <= V_5 -> V_1145 ; V_42 ++ )
F_285 ( V_5 , & V_1130 -> V_1148 [ V_42 ] ,
V_1149 ) ;
}
}
static int F_395 ( struct V_4 * V_5 ,
struct V_1129 * V_1130 )
{
T_1 V_42 , V_1331 ;
V_1130 -> V_1093 = 0 ;
V_1130 -> V_1092 = 0 ;
V_1130 -> V_1095 = 0 ;
V_1130 -> V_1094 = 0 ;
if ( V_1130 != & V_5 -> V_123 [ 0 ] . V_1091 ) {
memset ( & V_1130 -> V_1142 [ 0 ] , 0 ,
F_396 ( V_5 ) ) ;
if ( V_1130 -> V_1148 )
memset ( & V_1130 -> V_1148 [ 0 ] , 0 ,
F_397 ( V_5 ) ) ;
goto V_186;
}
memset ( V_1130 -> V_1141 , 0 , F_398 ( V_5 ) ) ;
V_1331 = V_1332 ;
if ( F_23 ( V_5 , 5780_CLASS ) &&
V_5 -> V_111 -> V_1201 > V_1328 )
V_1331 = V_1333 ;
V_5 -> V_1143 = F_399 ( V_1331 ) ;
for ( V_42 = 0 ; V_42 <= V_5 -> V_1140 ; V_42 ++ ) {
struct V_1134 * V_1334 ;
V_1334 = & V_1130 -> V_1141 [ V_42 ] ;
V_1334 -> V_1181 = V_1331 << V_1183 ;
V_1334 -> V_1185 = ( V_1335 << V_1336 ) ;
V_1334 -> V_1170 = ( V_1139 |
( V_42 << V_1337 ) ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_1338 ; V_42 ++ ) {
unsigned int V_1133 ;
if ( F_288 ( V_5 , V_1130 , V_1139 , V_42 ,
& V_1133 ) < 0 ) {
F_141 ( V_5 -> V_111 ,
L_44
L_45
L_46 , V_42 , V_5 -> V_1338 ) ;
if ( V_42 == 0 )
goto V_1339;
V_5 -> V_1338 = V_42 ;
break;
}
}
if ( ! F_23 ( V_5 , V_521 ) || F_23 ( V_5 , 5780_CLASS ) )
goto V_186;
memset ( V_1130 -> V_1146 , 0 , F_400 ( V_5 ) ) ;
if ( ! F_23 ( V_5 , V_1340 ) )
goto V_186;
for ( V_42 = 0 ; V_42 <= V_5 -> V_1145 ; V_42 ++ ) {
struct V_1134 * V_1334 ;
V_1334 = & V_1130 -> V_1146 [ V_42 ] . V_1147 ;
V_1334 -> V_1181 = V_1333 << V_1183 ;
V_1334 -> V_1185 = ( V_1335 << V_1336 ) |
V_1341 ;
V_1334 -> V_1170 = ( V_1144 |
( V_42 << V_1337 ) ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_1342 ; V_42 ++ ) {
unsigned int V_1133 ;
if ( F_288 ( V_5 , V_1130 , V_1144 , V_42 ,
& V_1133 ) < 0 ) {
F_141 ( V_5 -> V_111 ,
L_47
L_48
L_46 , V_42 , V_5 -> V_1342 ) ;
if ( V_42 == 0 )
goto V_1339;
V_5 -> V_1342 = V_42 ;
break;
}
}
V_186:
return 0 ;
V_1339:
F_394 ( V_5 , V_1130 ) ;
return - V_264 ;
}
static void F_401 ( struct V_4 * V_5 ,
struct V_1129 * V_1130 )
{
F_173 ( V_1130 -> V_1142 ) ;
V_1130 -> V_1142 = NULL ;
F_173 ( V_1130 -> V_1148 ) ;
V_1130 -> V_1148 = NULL ;
if ( V_1130 -> V_1141 ) {
F_402 ( & V_5 -> V_12 -> V_111 , F_398 ( V_5 ) ,
V_1130 -> V_1141 , V_1130 -> V_1343 ) ;
V_1130 -> V_1141 = NULL ;
}
if ( V_1130 -> V_1146 ) {
F_402 ( & V_5 -> V_12 -> V_111 , F_400 ( V_5 ) ,
V_1130 -> V_1146 , V_1130 -> V_1344 ) ;
V_1130 -> V_1146 = NULL ;
}
}
static int F_403 ( struct V_4 * V_5 ,
struct V_1129 * V_1130 )
{
V_1130 -> V_1142 = F_258 ( F_396 ( V_5 ) ,
V_632 ) ;
if ( ! V_1130 -> V_1142 )
return - V_264 ;
V_1130 -> V_1141 = F_404 ( & V_5 -> V_12 -> V_111 ,
F_398 ( V_5 ) ,
& V_1130 -> V_1343 ,
V_632 ) ;
if ( ! V_1130 -> V_1141 )
goto V_1033;
if ( F_23 ( V_5 , V_521 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
V_1130 -> V_1148 = F_258 ( F_397 ( V_5 ) ,
V_632 ) ;
if ( ! V_1130 -> V_1148 )
goto V_1033;
V_1130 -> V_1146 = F_404 ( & V_5 -> V_12 -> V_111 ,
F_400 ( V_5 ) ,
& V_1130 -> V_1344 ,
V_632 ) ;
if ( ! V_1130 -> V_1146 )
goto V_1033;
}
return 0 ;
V_1033:
F_401 ( V_5 , V_1130 ) ;
return - V_264 ;
}
static void F_405 ( struct V_4 * V_5 )
{
int V_42 , V_627 ;
for ( V_627 = 0 ; V_627 < V_5 -> V_129 ; V_627 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_627 ] ;
F_394 ( V_5 , & V_131 -> V_1091 ) ;
if ( ! V_131 -> V_1108 )
continue;
for ( V_42 = 0 ; V_42 < V_1098 ; V_42 ++ ) {
struct V_1109 * V_1110 = V_131 -> V_1108 [ V_42 ] . V_1110 ;
if ( ! V_1110 )
continue;
F_360 ( V_131 , V_42 ,
F_270 ( V_1110 ) -> V_1120 - 1 ) ;
F_406 ( V_1110 ) ;
}
F_407 ( F_263 ( V_5 -> V_111 , V_627 ) ) ;
}
}
static int F_408 ( struct V_4 * V_5 )
{
int V_42 ;
F_405 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_131 -> V_132 = 0 ;
V_131 -> V_1088 = 0 ;
V_131 -> V_134 -> V_57 = 0 ;
V_131 -> V_134 -> V_1083 = 0 ;
memset ( V_131 -> V_134 , 0 , V_1345 ) ;
V_131 -> V_1089 = 0 ;
V_131 -> V_147 = 0 ;
if ( V_131 -> V_1112 )
memset ( V_131 -> V_1112 , 0 , V_1346 ) ;
V_131 -> V_149 = 0 ;
if ( V_131 -> V_1165 )
memset ( V_131 -> V_1165 , 0 , F_409 ( V_5 ) ) ;
if ( F_395 ( V_5 , & V_131 -> V_1091 ) ) {
F_405 ( V_5 ) ;
return - V_264 ;
}
}
return 0 ;
}
static void F_410 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_1112 ) {
F_402 ( & V_5 -> V_12 -> V_111 , V_1346 ,
V_131 -> V_1112 , V_131 -> V_1347 ) ;
V_131 -> V_1112 = NULL ;
}
F_173 ( V_131 -> V_1108 ) ;
V_131 -> V_1108 = NULL ;
}
}
static int F_411 ( struct V_4 * V_5 )
{
int V_42 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
if ( F_23 ( V_5 , V_1105 ) )
V_131 ++ ;
for ( V_42 = 0 ; V_42 < V_5 -> V_1348 ; V_42 ++ , V_131 ++ ) {
V_131 -> V_1108 = F_258 ( sizeof( struct V_1106 ) *
V_1098 , V_632 ) ;
if ( ! V_131 -> V_1108 )
goto V_1033;
V_131 -> V_1112 = F_404 ( & V_5 -> V_12 -> V_111 ,
V_1346 ,
& V_131 -> V_1347 ,
V_632 ) ;
if ( ! V_131 -> V_1112 )
goto V_1033;
}
return 0 ;
V_1033:
F_410 ( V_5 ) ;
return - V_264 ;
}
static void F_412 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_401 ( V_5 , & V_131 -> V_1091 ) ;
if ( ! V_131 -> V_1165 )
continue;
F_402 ( & V_5 -> V_12 -> V_111 ,
F_409 ( V_5 ) ,
V_131 -> V_1165 ,
V_131 -> V_1349 ) ;
V_131 -> V_1165 = NULL ;
}
}
static int F_413 ( struct V_4 * V_5 )
{
unsigned int V_42 , V_200 ;
V_200 = V_5 -> V_1221 ;
if ( F_23 ( V_5 , V_1210 ) )
V_200 ++ ;
for ( V_42 = 0 ; V_42 < V_200 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( F_403 ( V_5 , & V_131 -> V_1091 ) )
goto V_1033;
if ( ! V_42 && F_23 ( V_5 , V_1210 ) )
continue;
V_131 -> V_1165 = F_414 ( & V_5 -> V_12 -> V_111 ,
F_409 ( V_5 ) ,
& V_131 -> V_1349 ,
V_632 ) ;
if ( ! V_131 -> V_1165 )
goto V_1033;
}
return 0 ;
V_1033:
F_412 ( V_5 ) ;
return - V_264 ;
}
static void F_415 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
F_402 ( & V_5 -> V_12 -> V_111 , V_1345 ,
V_131 -> V_134 ,
V_131 -> V_1350 ) ;
V_131 -> V_134 = NULL ;
}
}
F_412 ( V_5 ) ;
F_410 ( V_5 ) ;
if ( V_5 -> V_1351 ) {
F_402 ( & V_5 -> V_12 -> V_111 , sizeof( struct V_1352 ) ,
V_5 -> V_1351 , V_5 -> V_1353 ) ;
V_5 -> V_1351 = NULL ;
}
}
static int F_416 ( struct V_4 * V_5 )
{
int V_42 ;
V_5 -> V_1351 = F_414 ( & V_5 -> V_12 -> V_111 ,
sizeof( struct V_1352 ) ,
& V_5 -> V_1353 , V_632 ) ;
if ( ! V_5 -> V_1351 )
goto V_1033;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
struct V_139 * V_140 ;
V_131 -> V_134 = F_414 ( & V_5 -> V_12 -> V_111 ,
V_1345 ,
& V_131 -> V_1350 ,
V_632 ) ;
if ( ! V_131 -> V_134 )
goto V_1033;
V_140 = V_131 -> V_134 ;
if ( F_23 ( V_5 , V_1210 ) ) {
T_3 * V_1354 = NULL ;
switch ( V_42 ) {
case 1 :
V_1354 = & V_140 -> V_145 [ 0 ] . V_1087 ;
break;
case 2 :
V_1354 = & V_140 -> V_1084 ;
break;
case 3 :
V_1354 = & V_140 -> V_1355 ;
break;
case 4 :
V_1354 = & V_140 -> V_1086 ;
break;
}
V_131 -> V_148 = V_1354 ;
} else {
V_131 -> V_148 = & V_140 -> V_145 [ 0 ] . V_1087 ;
}
}
if ( F_411 ( V_5 ) || F_413 ( V_5 ) )
goto V_1033;
return 0 ;
V_1033:
F_415 ( V_5 ) ;
return - V_264 ;
}
static int F_417 ( struct V_4 * V_5 , unsigned long V_1356 , T_1 V_1357 , bool V_1358 )
{
unsigned int V_42 ;
T_1 V_7 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
switch ( V_1356 ) {
case V_1061 :
case V_1078 :
case V_1062 :
case V_1066 :
case V_1065 :
return 0 ;
default:
break;
}
}
V_7 = F_33 ( V_1356 ) ;
V_7 &= ~ V_1357 ;
F_31 ( V_1356 , V_7 ) ;
for ( V_42 = 0 ; V_42 < V_1359 ; V_42 ++ ) {
if ( F_36 ( V_5 -> V_12 ) ) {
F_115 ( & V_5 -> V_12 -> V_111 ,
L_49
L_50 ,
V_1356 , V_1357 ) ;
return - V_82 ;
}
F_24 ( 100 ) ;
V_7 = F_33 ( V_1356 ) ;
if ( ( V_7 & V_1357 ) == 0 )
break;
}
if ( V_42 == V_1359 && ! V_1358 ) {
F_115 ( & V_5 -> V_12 -> V_111 ,
L_51 ,
V_1356 , V_1357 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_418 ( struct V_4 * V_5 , bool V_1358 )
{
int V_42 , V_75 ;
F_45 ( V_5 ) ;
if ( F_36 ( V_5 -> V_12 ) ) {
V_5 -> V_352 &= ~ ( V_731 | V_1360 ) ;
V_5 -> V_365 &= ~ V_730 ;
V_75 = - V_82 ;
goto V_1361;
}
V_5 -> V_352 &= ~ V_731 ;
F_31 ( V_359 , V_5 -> V_352 ) ;
F_24 ( 10 ) ;
V_75 = F_417 ( V_5 , V_1059 , V_1362 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1053 , V_1363 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1061 , V_1364 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1055 , V_1365 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1058 , V_1366 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1060 , V_1367 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1050 , V_1368 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1051 , V_1369 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1048 , V_1370 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1067 , V_1371 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1049 , V_1372 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1078 , V_1373 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1052 , V_1374 , V_1358 ) ;
V_5 -> V_365 &= ~ V_730 ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
V_5 -> V_354 &= ~ V_1360 ;
F_31 ( V_361 , V_5 -> V_354 ) ;
for ( V_42 = 0 ; V_42 < V_1359 ; V_42 ++ ) {
F_24 ( 100 ) ;
if ( ! ( F_33 ( V_361 ) & V_1360 ) )
break;
}
if ( V_42 >= V_1359 ) {
F_115 ( & V_5 -> V_12 -> V_111 ,
L_52
L_53 , V_657 , F_33 ( V_361 ) ) ;
V_75 |= - V_82 ;
}
V_75 |= F_417 ( V_5 , V_138 , V_128 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1068 , V_1375 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1062 , V_1376 , V_1358 ) ;
F_46 ( V_1076 , 0xffffffff ) ;
F_46 ( V_1076 , 0x00000000 ) ;
V_75 |= F_417 ( V_5 , V_1066 , V_1377 , V_1358 ) ;
V_75 |= F_417 ( V_5 , V_1065 , V_1378 , V_1358 ) ;
V_1361:
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 )
memset ( V_131 -> V_134 , 0 , V_1345 ) ;
}
return V_75 ;
}
static void F_419 ( struct V_4 * V_5 )
{
F_420 ( V_5 -> V_12 , V_1379 , & V_5 -> V_1380 ) ;
}
static void F_421 ( struct V_4 * V_5 )
{
T_1 V_7 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
V_7 = ( V_1381 | V_1382 ) ;
if ( F_76 ( V_5 ) == V_916 &&
F_23 ( V_5 , V_839 ) )
V_7 |= V_1383 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_1384 |
V_1385 |
V_1386 ;
F_15 ( V_5 -> V_12 , V_1243 , V_7 ) ;
F_422 ( V_5 -> V_12 , V_1379 , V_5 -> V_1380 ) ;
if ( ! F_23 ( V_5 , V_1081 ) ) {
F_423 ( V_5 -> V_12 , V_1387 ,
V_5 -> V_1388 ) ;
F_423 ( V_5 -> V_12 , V_1389 ,
V_5 -> V_1390 ) ;
}
if ( F_23 ( V_5 , V_839 ) ) {
T_3 V_1391 ;
F_420 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
& V_1391 ) ;
V_1391 &= ~ V_1394 ;
F_422 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
V_1391 ) ;
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_1395 ) ) {
T_3 V_1396 ;
F_420 ( V_5 -> V_12 ,
V_5 -> V_1397 + V_1398 ,
& V_1396 ) ;
F_422 ( V_5 -> V_12 ,
V_5 -> V_1397 + V_1398 ,
V_1396 | V_1399 ) ;
V_7 = F_33 ( V_1077 ) ;
F_46 ( V_1077 , V_7 | V_1400 ) ;
}
}
}
static int F_424 ( struct V_4 * V_5 )
{
T_1 V_7 ;
void (* F_186)( struct V_4 * , T_1 , T_1 );
int V_42 , V_75 ;
F_156 ( V_5 ) ;
F_35 ( V_5 , V_61 ) ;
V_5 -> V_586 = 0 ;
F_419 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_640 ||
F_23 ( V_5 , 5755_PLUS ) )
F_46 ( V_1401 , 0 ) ;
F_186 = V_5 -> V_27 ;
if ( F_186 == F_17 )
V_5 -> V_27 = F_7 ;
F_82 ( V_5 , V_1242 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
V_131 -> V_134 -> V_57 = 0 ;
V_131 -> V_134 -> V_1083 = 0 ;
}
V_131 -> V_132 = 0 ;
V_131 -> V_1088 = 0 ;
}
F_275 () ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_343 ( V_5 -> V_123 [ V_42 ] . V_1238 ) ;
if ( F_30 ( V_5 ) == V_1402 ) {
V_7 = F_33 ( V_1403 ) & ~ V_1404 ;
F_46 ( V_1403 , V_7 | V_1405 ) ;
}
V_7 = V_1406 ;
if ( F_23 ( V_5 , V_1081 ) ) {
if ( F_30 ( V_5 ) != V_256 &&
! F_23 ( V_5 , 57765_PLUS ) &&
F_33 ( V_1407 ) ==
( V_1408 | V_1409 ) )
F_46 ( V_1407 , V_1409 ) ;
if ( F_76 ( V_5 ) != V_1410 ) {
F_46 ( V_497 , ( 1 << 29 ) ) ;
V_7 |= ( 1 << 29 ) ;
}
}
if ( F_30 ( V_5 ) == V_36 ) {
F_46 ( V_323 , F_33 ( V_323 ) | V_1411 ) ;
F_46 ( V_655 ,
F_33 ( V_655 ) & ~ V_656 ) ;
}
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , V_152 ) )
V_7 |= V_1412 ;
F_46 ( V_497 , V_7 ) ;
V_5 -> V_27 = F_186 ;
F_24 ( 120 ) ;
F_19 ( V_5 -> V_12 , V_1379 , & V_7 ) ;
F_24 ( 120 ) ;
if ( F_23 ( V_5 , V_1081 ) && F_425 ( V_5 -> V_12 ) ) {
T_3 V_1413 ;
if ( F_76 ( V_5 ) == V_1410 ) {
int V_627 ;
T_1 V_1414 ;
for ( V_627 = 0 ; V_627 < 5000 ; V_627 ++ )
F_24 ( 100 ) ;
F_19 ( V_5 -> V_12 , 0xc4 , & V_1414 ) ;
F_15 ( V_5 -> V_12 , 0xc4 ,
V_1414 | ( 1 << 15 ) ) ;
}
V_1413 = V_1415 | V_1416 ;
if ( ! F_23 ( V_5 , V_152 ) )
V_1413 |= V_1417 ;
F_221 ( V_5 -> V_12 , V_1418 , V_1413 ) ;
F_426 ( V_5 -> V_12 , V_1419 ,
V_1420 |
V_1421 |
V_1422 |
V_1423 ) ;
}
F_421 ( V_5 ) ;
F_84 ( V_5 , V_1242 ) ;
F_84 ( V_5 , V_1229 ) ;
V_7 = 0 ;
if ( F_23 ( V_5 , 5780_CLASS ) )
V_7 = F_33 ( V_1065 ) ;
F_46 ( V_1065 , V_7 | V_1378 ) ;
if ( F_76 ( V_5 ) == V_1424 ) {
F_91 ( V_5 ) ;
F_46 ( 0x5000 , 0x400 ) ;
}
if ( F_23 ( V_5 , V_322 ) ) {
F_91 ( V_5 ) ;
F_181 ( V_5 , V_653 ) ;
}
V_75 = F_95 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_46 ( V_646 , V_5 -> V_644 ) ;
if ( F_76 ( V_5 ) == V_1425 ) {
V_7 = F_33 ( 0xc4 ) ;
F_46 ( 0xc4 , V_7 | ( 1 << 15 ) ) ;
}
if ( ( V_5 -> V_550 & V_1426 ) != 0 &&
F_30 ( V_5 ) == V_501 ) {
V_5 -> V_156 |= V_155 ;
if ( F_76 ( V_5 ) == V_1425 )
V_5 -> V_156 |= V_154 ;
F_46 ( V_153 , V_5 -> V_156 ) ;
}
if ( V_5 -> V_178 & V_567 ) {
V_5 -> V_365 = V_724 ;
V_7 = V_5 -> V_365 ;
} else if ( V_5 -> V_178 & V_302 ) {
V_5 -> V_365 = V_373 ;
V_7 = V_5 -> V_365 ;
} else
V_7 = 0 ;
F_31 ( V_380 , V_7 ) ;
F_24 ( 40 ) ;
F_37 ( V_5 , V_61 ) ;
F_74 ( V_5 ) ;
if ( F_23 ( V_5 , V_1081 ) &&
F_76 ( V_5 ) != V_1410 &&
F_30 ( V_5 ) != V_256 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( 0x7c00 ) ;
F_46 ( 0x7c00 , V_7 | ( 1 << 25 ) ) ;
}
if ( F_30 ( V_5 ) == V_533 ) {
V_7 = F_33 ( V_1427 ) ;
F_46 ( V_1427 , V_7 & ~ V_1428 ) ;
}
F_84 ( V_5 , V_305 ) ;
V_5 -> V_178 &= ~ ( V_769 |
V_569 ) ;
F_84 ( V_5 , V_313 ) ;
F_32 ( V_5 , V_1429 , & V_7 ) ;
if ( V_7 == V_1430 ) {
T_1 V_1431 ;
F_32 ( V_5 , V_1432 , & V_1431 ) ;
if ( V_1431 & V_1433 ) {
F_82 ( V_5 , V_305 ) ;
V_5 -> V_294 = V_295 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_82 ( V_5 , V_313 ) ;
F_32 ( V_5 , V_1434 , & V_1431 ) ;
if ( V_1431 & V_1435 )
V_5 -> V_178 |= V_769 ;
if ( V_1431 & V_1436 )
V_5 -> V_178 |= V_569 ;
}
}
return 0 ;
}
static int F_427 ( struct V_4 * V_5 , int V_95 , bool V_1358 )
{
int V_75 ;
F_91 ( V_5 ) ;
F_92 ( V_5 , V_95 ) ;
F_418 ( V_5 , V_1358 ) ;
V_75 = F_424 ( V_5 ) ;
F_192 ( V_5 , false ) ;
F_94 ( V_5 , V_95 ) ;
F_93 ( V_5 , V_95 ) ;
if ( V_5 -> V_1351 ) {
F_428 ( V_5 , & V_5 -> V_1437 ) ;
F_429 ( V_5 , & V_5 -> V_1438 ) ;
memset ( V_5 -> V_1351 , 0 , sizeof( struct V_1352 ) ) ;
}
if ( V_75 )
return V_75 ;
return 0 ;
}
static int F_430 ( struct V_362 * V_111 , void * V_1439 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
struct V_1440 * V_184 = V_1439 ;
int V_75 = 0 ;
bool V_685 = false ;
if ( ! F_431 ( V_184 -> V_1441 ) )
return - V_1442 ;
memcpy ( V_111 -> V_688 , V_184 -> V_1441 , V_111 -> V_1443 ) ;
if ( ! F_143 ( V_111 ) )
return 0 ;
if ( F_23 ( V_5 , V_305 ) ) {
T_1 V_1444 , V_1445 , V_1446 , V_1447 ;
V_1444 = F_33 ( V_689 ) ;
V_1445 = F_33 ( V_690 ) ;
V_1446 = F_33 ( V_1448 ) ;
V_1447 = F_33 ( V_1449 ) ;
if ( ( V_1444 != V_1446 || V_1445 != V_1447 ) &&
! ( V_1446 == 0 && V_1447 == 0 ) )
V_685 = true ;
}
F_69 ( & V_5 -> V_207 ) ;
F_192 ( V_5 , V_685 ) ;
F_70 ( & V_5 -> V_207 ) ;
return V_75 ;
}
static void F_432 ( struct V_4 * V_5 , T_1 V_1450 ,
T_9 V_1117 , T_1 V_1451 ,
T_1 V_1452 )
{
F_29 ( V_5 ,
( V_1450 + V_1453 + V_1454 ) ,
( ( T_6 ) V_1117 >> 32 ) ) ;
F_29 ( V_5 ,
( V_1450 + V_1453 + V_16 ) ,
( ( T_6 ) V_1117 & 0xffffffff ) ) ;
F_29 ( V_5 ,
( V_1450 + V_1455 ) ,
V_1451 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_29 ( V_5 ,
( V_1450 + V_1456 ) ,
V_1452 ) ;
}
static void F_433 ( struct V_4 * V_5 , struct V_1457 * V_1458 )
{
int V_42 = 0 ;
if ( ! F_23 ( V_5 , V_1105 ) ) {
F_46 ( V_1459 , V_1458 -> V_1460 ) ;
F_46 ( V_1461 , V_1458 -> V_1462 ) ;
F_46 ( V_1463 , V_1458 -> V_1464 ) ;
} else {
F_46 ( V_1459 , 0 ) ;
F_46 ( V_1461 , 0 ) ;
F_46 ( V_1463 , 0 ) ;
for (; V_42 < V_5 -> V_1348 ; V_42 ++ ) {
T_1 V_161 ;
V_161 = V_1465 + V_42 * 0x18 ;
F_46 ( V_161 , V_1458 -> V_1460 ) ;
V_161 = V_1466 + V_42 * 0x18 ;
F_46 ( V_161 , V_1458 -> V_1462 ) ;
V_161 = V_1467 + V_42 * 0x18 ;
F_46 ( V_161 , V_1458 -> V_1464 ) ;
}
}
for (; V_42 < V_5 -> V_122 - 1 ; V_42 ++ ) {
F_46 ( V_1465 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1466 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1467 + V_42 * 0x18 , 0 ) ;
}
}
static void F_434 ( struct V_4 * V_5 , struct V_1457 * V_1458 )
{
int V_42 = 0 ;
T_1 V_200 = V_5 -> V_1221 ;
if ( ! F_23 ( V_5 , V_1210 ) ) {
F_46 ( V_1468 , V_1458 -> V_1469 ) ;
F_46 ( V_1470 , V_1458 -> V_1471 ) ;
F_46 ( V_1472 , V_1458 -> V_1473 ) ;
V_200 -- ;
} else {
F_46 ( V_1468 , 0 ) ;
F_46 ( V_1470 , 0 ) ;
F_46 ( V_1472 , 0 ) ;
}
for (; V_42 < V_200 ; V_42 ++ ) {
T_1 V_161 ;
V_161 = V_1064 + V_42 * 0x18 ;
F_46 ( V_161 , V_1458 -> V_1469 ) ;
V_161 = V_1474 + V_42 * 0x18 ;
F_46 ( V_161 , V_1458 -> V_1471 ) ;
V_161 = V_1475 + V_42 * 0x18 ;
F_46 ( V_161 , V_1458 -> V_1473 ) ;
}
for (; V_42 < V_5 -> V_122 - 1 ; V_42 ++ ) {
F_46 ( V_1064 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1474 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1475 + V_42 * 0x18 , 0 ) ;
}
}
static void F_435 ( struct V_4 * V_5 , struct V_1457 * V_1458 )
{
F_433 ( V_5 , V_1458 ) ;
F_434 ( V_5 , V_1458 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_7 = V_1458 -> V_971 ;
F_46 ( V_1476 , V_1458 -> V_1477 ) ;
F_46 ( V_1478 , V_1458 -> V_1479 ) ;
if ( ! V_5 -> V_338 )
V_7 = 0 ;
F_46 ( V_969 , V_7 ) ;
}
}
static void F_436 ( struct V_4 * V_5 )
{
T_1 V_1480 , V_200 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_200 = V_1481 + V_1482 * 16 ;
else if ( F_23 ( V_5 , 5717_PLUS ) )
V_200 = V_1481 + V_1482 * 4 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_765 )
V_200 = V_1481 + V_1482 * 2 ;
else
V_200 = V_1481 + V_1482 ;
for ( V_1480 = V_1481 + V_1482 ;
V_1480 < V_200 ; V_1480 += V_1482 )
F_29 ( V_5 , V_1480 + V_1455 ,
V_1483 ) ;
}
static void F_437 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1480 = V_1481 ;
if ( F_23 ( V_5 , V_1105 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1480 += V_1482 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1112 )
continue;
F_432 ( V_5 , V_1480 , V_131 -> V_1347 ,
( V_1098 << V_1484 ) ,
V_38 ) ;
}
}
static void F_438 ( struct V_4 * V_5 )
{
T_1 V_1485 , V_200 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_200 = V_1486 + V_1482 * 17 ;
else if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_200 = V_1486 + V_1482 * 16 ;
else if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_765 ||
F_23 ( V_5 , 57765_CLASS ) )
V_200 = V_1486 + V_1482 * 4 ;
else
V_200 = V_1486 + V_1482 ;
for ( V_1485 = V_1486 + V_1482 ;
V_1485 < V_200 ; V_1485 += V_1482 )
F_29 ( V_5 , V_1485 + V_1455 ,
V_1483 ) ;
}
static void F_439 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1485 = V_1486 ;
if ( F_23 ( V_5 , V_1210 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1485 += V_1482 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1165 )
continue;
F_432 ( V_5 , V_1485 , V_131 -> V_1349 ,
( V_5 -> V_1208 + 1 ) <<
V_1484 , 0 ) ;
}
}
static void F_440 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_1488 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
F_436 ( V_5 ) ;
F_438 ( V_5 ) ;
F_47 ( V_5 -> V_123 [ 0 ] . V_124 , 1 ) ;
V_5 -> V_123 [ 0 ] . V_1489 = 0 ;
V_5 -> V_123 [ 0 ] . V_1490 = 0 ;
V_5 -> V_123 [ 0 ] . V_1491 = 0 ;
if ( F_23 ( V_5 , V_1063 ) ) {
for ( V_42 = 1 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
V_5 -> V_123 [ V_42 ] . V_1089 = 0 ;
V_5 -> V_123 [ V_42 ] . V_147 = 0 ;
if ( F_23 ( V_5 , V_1105 ) )
F_52 ( V_5 -> V_123 [ V_42 ] . V_1316 , 0 ) ;
F_311 ( V_5 -> V_123 [ V_42 ] . V_1209 , 0 ) ;
F_47 ( V_5 -> V_123 [ V_42 ] . V_124 , 1 ) ;
V_5 -> V_123 [ V_42 ] . V_1489 = 0 ;
V_5 -> V_123 [ V_42 ] . V_1490 = 0 ;
V_5 -> V_123 [ V_42 ] . V_1491 = 0 ;
}
if ( ! F_23 ( V_5 , V_1105 ) )
F_52 ( V_5 -> V_123 [ 0 ] . V_1316 , 0 ) ;
} else {
V_5 -> V_123 [ 0 ] . V_1089 = 0 ;
V_5 -> V_123 [ 0 ] . V_147 = 0 ;
F_52 ( V_5 -> V_123 [ 0 ] . V_1316 , 0 ) ;
F_311 ( V_5 -> V_123 [ 0 ] . V_1209 , 0 ) ;
}
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_33 = V_1492 + V_16 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
F_388 ( V_33 + V_42 * 8 , 0 ) ;
}
memset ( V_131 -> V_134 , 0 , V_1345 ) ;
F_46 ( V_1493 + V_1454 ,
( ( T_6 ) V_131 -> V_1350 >> 32 ) ) ;
F_46 ( V_1493 + V_16 ,
( ( T_6 ) V_131 -> V_1350 & 0xffffffff ) ) ;
V_1488 = V_1494 ;
for ( V_42 = 1 , V_131 ++ ; V_42 < V_5 -> V_129 ; V_42 ++ , V_131 ++ ) {
T_6 V_1117 = ( T_6 ) V_131 -> V_1350 ;
F_46 ( V_1488 + V_1454 , V_1117 >> 32 ) ;
F_46 ( V_1488 + V_16 , V_1117 & 0xffffffff ) ;
V_1488 += 8 ;
memset ( V_131 -> V_134 , 0 , V_1345 ) ;
}
F_437 ( V_5 ) ;
F_439 ( V_5 ) ;
}
static void F_441 ( struct V_4 * V_5 )
{
T_1 V_7 , V_1495 , V_1496 , V_1497 ;
if ( ! F_23 ( V_5 , 5750_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_30 ( V_5 ) == V_1498 ||
F_30 ( V_5 ) == V_640 ||
F_23 ( V_5 , 57765_PLUS ) )
V_1495 = V_1499 ;
else if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_1500 )
V_1495 = V_1501 ;
else
V_1495 = V_1502 ;
V_1497 = F_318 ( V_1495 / 2 , V_5 -> V_1207 ) ;
V_1496 = F_442 ( T_1 , V_5 -> V_1338 / 8 , 1 ) ;
V_7 = F_318 ( V_1497 , V_1496 ) ;
F_46 ( V_1503 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1504 , V_1495 ) ;
if ( ! F_23 ( V_5 , V_521 ) || F_23 ( V_5 , 5780_CLASS ) )
return;
V_1495 = V_1505 ;
V_1496 = F_442 ( T_1 , V_5 -> V_1342 / 8 , 1 ) ;
V_7 = F_318 ( V_1495 / 2 , V_1496 ) ;
F_46 ( V_1506 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1507 , V_1495 ) ;
}
static inline T_1 F_443 ( unsigned char * V_626 , int V_74 )
{
T_1 V_161 ;
T_1 V_596 ;
int V_627 , V_1508 ;
V_161 = 0xffffffff ;
for ( V_627 = 0 ; V_627 < V_74 ; V_627 ++ ) {
V_161 ^= V_626 [ V_627 ] ;
for ( V_1508 = 0 ; V_1508 < 8 ; V_1508 ++ ) {
V_596 = V_161 & 0x01 ;
V_161 >>= 1 ;
if ( V_596 )
V_161 ^= 0xedb88320 ;
}
}
return ~ V_161 ;
}
static void F_444 ( struct V_4 * V_5 , unsigned int V_1509 )
{
F_46 ( V_1510 , V_1509 ? 0xffffffff : 0 ) ;
F_46 ( V_1511 , V_1509 ? 0xffffffff : 0 ) ;
F_46 ( V_1512 , V_1509 ? 0xffffffff : 0 ) ;
F_46 ( V_1513 , V_1509 ? 0xffffffff : 0 ) ;
}
static void F_445 ( struct V_362 * V_111 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
T_1 V_352 ;
V_352 = V_5 -> V_352 & ~ ( V_1514 |
V_1205 ) ;
#if ! F_356 ( V_1515 ) && ! F_356 ( V_1516 )
if ( ! F_23 ( V_5 , V_305 ) )
V_352 |= V_1205 ;
#endif
if ( V_111 -> V_10 & V_1517 ) {
V_352 |= V_1514 ;
} else if ( V_111 -> V_10 & V_1518 ) {
F_444 ( V_5 , 1 ) ;
} else if ( F_446 ( V_111 ) ) {
F_444 ( V_5 , 0 ) ;
} else {
struct V_1519 * V_1520 ;
T_1 V_1521 [ 4 ] = { 0 , } ;
T_1 V_1522 ;
T_1 V_44 ;
T_1 V_1523 ;
F_447 (ha, dev) {
V_1523 = F_443 ( V_1520 -> V_184 , V_1524 ) ;
V_44 = ~ V_1523 & 0x7f ;
V_1522 = ( V_44 & 0x60 ) >> 5 ;
V_44 &= 0x1f ;
V_1521 [ V_1522 ] |= ( 1 << V_44 ) ;
}
F_46 ( V_1510 , V_1521 [ 0 ] ) ;
F_46 ( V_1511 , V_1521 [ 1 ] ) ;
F_46 ( V_1512 , V_1521 [ 2 ] ) ;
F_46 ( V_1513 , V_1521 [ 3 ] ) ;
}
if ( V_352 != V_5 -> V_352 ) {
V_5 -> V_352 = V_352 ;
F_31 ( V_359 , V_352 ) ;
F_24 ( 10 ) ;
}
}
static void F_448 ( struct V_4 * V_5 , T_1 V_1525 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1526 ; V_42 ++ )
V_5 -> V_1527 [ V_42 ] = F_449 ( V_42 , V_1525 ) ;
}
static void F_450 ( struct V_4 * V_5 )
{
int V_42 ;
if ( ! F_23 ( V_5 , V_1063 ) )
return;
if ( V_5 -> V_1221 == 1 ) {
memset ( & V_5 -> V_1527 [ 0 ] , 0 , sizeof( V_5 -> V_1527 ) ) ;
return;
}
for ( V_42 = 0 ; V_42 < V_1526 ; V_42 ++ ) {
if ( V_5 -> V_1527 [ V_42 ] >= V_5 -> V_1221 )
break;
}
if ( V_42 != V_1526 )
F_448 ( V_5 , V_5 -> V_1221 ) ;
}
static void F_451 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_161 = V_1528 ;
while ( V_42 < V_1526 ) {
T_1 V_7 = V_5 -> V_1527 [ V_42 ] ;
V_42 ++ ;
for (; V_42 % 8 ; V_42 ++ ) {
V_7 <<= 4 ;
V_7 |= V_5 -> V_1527 [ V_42 ] ;
}
F_46 ( V_161 , V_7 ) ;
V_161 += 4 ;
}
}
static inline T_1 F_452 ( struct V_4 * V_5 )
{
if ( F_30 ( V_5 ) == V_477 )
return V_1529 ;
else
return V_1530 ;
}
static int F_453 ( struct V_4 * V_5 , bool V_1531 )
{
T_1 V_7 , V_1532 ;
int V_42 , V_75 , V_200 ;
struct V_1129 * V_1130 = & V_5 -> V_123 [ 0 ] . V_1091 ;
F_45 ( V_5 ) ;
F_91 ( V_5 ) ;
F_92 ( V_5 , V_96 ) ;
if ( F_23 ( V_5 , V_562 ) )
F_418 ( V_5 , 1 ) ;
if ( ( V_5 -> V_178 & V_569 ) &&
! ( V_5 -> V_178 & V_1533 ) ) {
F_206 ( V_5 ) ;
F_130 ( V_5 , NULL ) ;
V_5 -> V_178 |= V_1533 ;
}
if ( V_5 -> V_178 & V_336 )
F_219 ( V_5 ) ;
if ( V_1531 )
F_142 ( V_5 ) ;
V_75 = F_424 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_94 ( V_5 , V_96 ) ;
if ( F_144 ( V_5 ) == V_503 ) {
V_7 = F_33 ( V_504 ) ;
V_7 &= ~ ( V_1534 | V_1535 ) ;
F_46 ( V_504 , V_7 ) ;
V_7 = F_33 ( V_1536 ) ;
V_7 &= ~ V_1537 ;
V_7 |= V_1538 ;
F_46 ( V_1536 , V_7 ) ;
V_7 = F_33 ( V_1539 ) ;
V_7 &= ~ V_1540 ;
V_7 |= V_1541 ;
F_46 ( V_1539 , V_7 ) ;
V_7 = F_33 ( V_1542 ) ;
V_7 &= ~ V_1543 ;
V_7 |= V_1544 ;
F_46 ( V_1542 , V_7 ) ;
}
if ( F_30 ( V_5 ) == V_1402 ) {
V_7 = F_33 ( V_973 ) & ~ V_974 ;
V_7 |= V_1545 |
V_1546 ;
F_46 ( V_973 , V_7 ) ;
V_7 = F_33 ( V_1547 ) & ~ V_1548 ;
F_46 ( V_1547 , V_7 | V_1549 ) ;
F_46 ( V_1550 , V_1551 ) ;
V_7 = F_33 ( V_1403 ) & ~ V_1404 ;
F_46 ( V_1403 , V_7 | V_1405 ) ;
}
if ( F_23 ( V_5 , V_1552 ) ) {
T_1 V_644 = F_33 ( V_646 ) ;
V_7 = V_644 & ~ V_1553 ;
F_46 ( V_646 , V_7 | V_1554 ) ;
V_7 = F_33 ( V_1082 + V_1555 ) ;
F_46 ( V_1082 + V_1555 ,
V_7 | V_1556 ) ;
F_46 ( V_646 , V_644 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) ) {
if ( F_76 ( V_5 ) == V_325 ) {
T_1 V_644 = F_33 ( V_646 ) ;
V_7 = V_644 & ~ V_1553 ;
F_46 ( V_646 , V_7 | V_1554 ) ;
V_7 = F_33 ( V_1082 +
V_1557 ) ;
F_46 ( V_1082 + V_1557 ,
V_7 | V_1558 ) ;
F_46 ( V_646 , V_644 ) ;
}
if ( F_144 ( V_5 ) != V_1559 ) {
T_1 V_644 ;
V_7 = F_33 ( V_1560 ) ;
V_7 |= V_1561 ;
F_46 ( V_1560 , V_7 ) ;
V_644 = F_33 ( V_646 ) ;
V_7 = V_644 & ~ V_1553 ;
F_46 ( V_646 , V_7 | V_1562 ) ;
V_7 = F_33 ( V_1082 +
V_1563 ) ;
V_7 &= ~ V_1564 ;
F_46 ( V_1082 + V_1563 ,
V_7 | V_1565 ) ;
F_46 ( V_646 , V_644 ) ;
}
V_7 = F_33 ( V_1536 ) ;
V_7 &= ~ V_1537 ;
V_7 |= V_1538 ;
F_46 ( V_1536 , V_7 ) ;
}
if ( ! F_23 ( V_5 , V_152 ) ) {
if ( ! F_23 ( V_5 , V_1081 ) )
V_5 -> V_156 |= V_1566 ;
F_31 ( V_153 , V_5 -> V_156 ) ;
}
if ( F_76 ( V_5 ) == V_916 &&
F_23 ( V_5 , V_839 ) ) {
V_7 = F_33 ( V_1243 ) ;
V_7 |= V_1383 ;
F_46 ( V_1243 , V_7 ) ;
}
if ( F_23 ( V_5 , V_60 ) ) {
V_7 = F_33 ( V_1243 ) ;
V_7 |= V_1384 |
V_1385 |
V_1386 ;
F_46 ( V_1243 , V_7 ) ;
}
if ( F_144 ( V_5 ) == V_1567 ) {
V_7 = F_33 ( V_1568 ) ;
V_7 |= ( 1 << 26 ) | ( 1 << 28 ) | ( 1 << 29 ) ;
F_46 ( V_1568 , V_7 ) ;
}
V_75 = F_408 ( V_5 ) ;
if ( V_75 )
return V_75 ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1569 ) &
~ V_1570 ;
if ( F_76 ( V_5 ) == V_325 )
V_7 &= ~ V_1571 ;
if ( ! F_23 ( V_5 , 57765_CLASS ) &&
F_30 ( V_5 ) != V_476 &&
F_30 ( V_5 ) != V_765 )
V_7 |= V_1572 ;
F_46 ( V_1569 , V_7 | V_5 -> V_1573 ) ;
} else if ( F_30 ( V_5 ) != V_413 &&
F_30 ( V_5 ) != V_45 ) {
F_46 ( V_1569 , V_5 -> V_1573 ) ;
}
V_5 -> V_644 &= ~ ( V_1574 |
V_1575 |
V_1576 |
V_1577 ) ;
V_5 -> V_644 |= V_1574 ;
V_5 -> V_644 |= V_1576 ;
V_7 = V_1578 | V_1579 ;
if ( V_5 -> V_1580 )
F_46 ( V_1581 ,
V_5 -> V_1580 | V_1582 ) ;
if ( F_23 ( V_5 , V_990 ) )
V_7 |= V_1583 ;
F_46 ( V_646 , V_5 -> V_644 | V_7 ) ;
V_7 = F_33 ( V_497 ) ;
V_7 &= ~ 0xff ;
V_7 |= ( 65 << V_966 ) ;
F_46 ( V_497 , V_7 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
} else if ( F_30 ( V_5 ) != V_501 ) {
F_46 ( V_1584 , V_1585 ) ;
if ( F_30 ( V_5 ) == V_500 )
F_46 ( V_1586 , V_1587 ) ;
else
F_46 ( V_1586 , V_1588 ) ;
F_46 ( V_1589 , V_1590 ) ;
F_46 ( V_1591 , V_1592 ) ;
} else if ( F_23 ( V_5 , V_1593 ) ) {
int V_661 ;
V_661 = V_5 -> V_661 ;
V_661 = ( V_661 + ( 0x80 - 1 ) ) & ~ ( 0x80 - 1 ) ;
F_46 ( V_1584 ,
V_684 + V_661 ) ;
F_46 ( V_1586 ,
V_1594 - V_661 - 0xa00 ) ;
}
if ( V_5 -> V_111 -> V_1201 <= V_1328 ) {
F_46 ( V_1595 ,
V_5 -> V_1596 . V_1597 ) ;
F_46 ( V_1598 ,
V_5 -> V_1596 . V_1599 ) ;
F_46 ( V_1600 ,
V_5 -> V_1596 . V_1601 ) ;
} else {
F_46 ( V_1595 ,
V_5 -> V_1596 . V_1602 ) ;
F_46 ( V_1598 ,
V_5 -> V_1596 . V_1603 ) ;
F_46 ( V_1600 ,
V_5 -> V_1596 . V_1604 ) ;
}
F_46 ( V_1605 ,
V_5 -> V_1596 . V_1606 ) ;
F_46 ( V_1607 ,
V_5 -> V_1596 . V_1608 ) ;
V_7 = V_1377 | V_1609 ;
if ( F_30 ( V_5 ) == V_477 )
V_7 |= V_1610 ;
if ( F_30 ( V_5 ) == V_476 ||
F_76 ( V_5 ) == V_1611 ||
F_76 ( V_5 ) == V_1612 )
V_7 |= V_1613 ;
F_46 ( V_1066 , V_7 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
if ( F_33 ( V_1066 ) & V_1377 )
break;
F_24 ( 10 ) ;
}
if ( V_42 >= 2000 ) {
F_183 ( V_5 -> V_111 , L_54 , V_657 ) ;
return - V_82 ;
}
if ( F_76 ( V_5 ) == V_1614 )
F_46 ( V_1615 , ( F_33 ( V_1615 ) & ~ 0x3 ) | 0x2 ) ;
F_441 ( V_5 ) ;
F_46 ( V_1616 + V_1453 + V_1454 ,
( ( T_6 ) V_1130 -> V_1343 >> 32 ) ) ;
F_46 ( V_1616 + V_1453 + V_16 ,
( ( T_6 ) V_1130 -> V_1343 & 0xffffffff ) ) ;
if ( ! F_23 ( V_5 , 5717_PLUS ) )
F_46 ( V_1616 + V_1456 ,
V_1617 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1618 + V_1455 ,
V_1483 ) ;
if ( F_76 ( V_5 ) == V_1611 ||
( F_23 ( V_5 , V_521 ) && ! F_23 ( V_5 , 5780_CLASS ) ) ) {
if ( F_23 ( V_5 , V_1340 ) ) {
F_46 ( V_1056 + V_1453 + V_1454 ,
( ( T_6 ) V_1130 -> V_1344 >> 32 ) ) ;
F_46 ( V_1056 + V_1453 + V_16 ,
( ( T_6 ) V_1130 -> V_1344 & 0xffffffff ) ) ;
V_7 = F_454 ( V_5 ) <<
V_1484 ;
F_46 ( V_1056 + V_1455 ,
V_7 | V_1619 ) ;
if ( ! F_23 ( V_5 , V_1304 ) ||
F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_765 )
F_46 ( V_1056 + V_1456 ,
V_1620 ) ;
} else {
F_46 ( V_1056 + V_1455 ,
V_1483 ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_455 ( V_5 ) ;
V_7 <<= V_1484 ;
V_7 |= ( V_1332 << 2 ) ;
} else
V_7 = V_1332 << V_1484 ;
} else
V_7 = V_1621 << V_1484 ;
F_46 ( V_1616 + V_1455 , V_7 ) ;
V_1130 -> V_1092 = V_5 -> V_1338 ;
F_311 ( V_18 , V_1130 -> V_1092 ) ;
V_1130 -> V_1094 =
F_23 ( V_5 , V_1340 ) ? V_5 -> V_1342 : 0 ;
F_311 ( V_1211 , V_1130 -> V_1094 ) ;
F_440 ( V_5 ) ;
F_192 ( V_5 , false ) ;
F_46 ( V_1622 ,
V_5 -> V_111 -> V_1201 + V_1202 + V_1184 + V_1623 ) ;
V_7 = ( 2 << V_385 ) |
( 6 << V_386 ) |
( 32 << V_387 ) ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_765 )
V_7 |= F_33 ( V_384 ) &
( V_967 |
V_968 ) ;
F_46 ( V_384 , V_7 ) ;
F_46 ( V_1624 , V_1625 ) ;
F_46 ( V_1626 , 0x0181 ) ;
V_1532 = ( V_1371 | V_1627 |
V_1628 | V_1629 |
V_1630 | V_1631 |
V_1632 | V_1633 |
V_1634 ) ;
if ( F_30 ( V_5 ) == V_476 )
V_1532 |= V_1635 ;
if ( F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1402 )
V_1532 |= V_1636 |
V_1637 |
V_1638 ;
if ( F_30 ( V_5 ) == V_501 &&
F_76 ( V_5 ) != V_1425 ) {
if ( F_23 ( V_5 , V_1593 ) &&
F_30 ( V_5 ) == V_501 ) {
V_1532 |= V_1639 ;
} else if ( ! ( F_33 ( V_1243 ) & V_1640 ) &&
! F_23 ( V_5 , V_1641 ) ) {
V_1532 |= V_1642 ;
}
}
if ( F_23 ( V_5 , V_1081 ) )
V_1532 |= V_1642 ;
if ( F_30 ( V_5 ) == V_667 ) {
V_5 -> V_1259 = 0 ;
if ( V_5 -> V_111 -> V_1201 <= V_1328 ) {
V_1532 |= V_1643 ;
V_5 -> V_1259 = V_1644 ;
}
}
if ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) )
V_1532 |= V_1645 ;
if ( F_23 ( V_5 , 57765_PLUS ) ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1402 )
V_1532 |= V_1646 ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_765 )
V_1532 |= F_33 ( V_1067 ) & V_1647 ;
if ( F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1402 ||
F_23 ( V_5 , 57765_PLUS ) ) {
T_1 V_1648 ;
if ( F_30 ( V_5 ) == V_765 )
V_1648 = V_1649 ;
else
V_1648 = V_1650 ;
V_7 = F_33 ( V_1648 ) ;
if ( F_76 ( V_5 ) == V_1611 ||
F_30 ( V_5 ) == V_765 ) {
V_7 &= ~ ( V_1651 |
V_1652 |
V_1653 ) ;
V_7 |= V_1654 |
V_1655 |
V_1656 ;
}
F_46 ( V_1648 , V_7 | V_1657 ) ;
}
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_765 ) {
T_1 V_1648 ;
if ( F_30 ( V_5 ) == V_765 )
V_1648 = V_1658 ;
else
V_1648 = V_1659 ;
V_7 = F_33 ( V_1648 ) ;
F_46 ( V_1648 , V_7 |
V_1660 |
V_1661 ) ;
}
if ( F_23 ( V_5 , 5750_PLUS ) ) {
V_7 = F_33 ( V_1662 ) ;
V_7 &= ~ V_1663 ;
F_46 ( V_1662 , V_7 ) ;
} else if ( ( V_1532 & V_1639 ) &&
F_23 ( V_5 , V_1593 ) ) {
V_7 = F_33 ( V_1662 ) ;
V_7 &= ~ V_1664 ;
F_46 ( V_1662 , V_7 ) ;
} else {
F_46 ( V_1662 , 0xffffff ) ;
}
F_46 ( V_1665 , V_1666 ) ;
F_46 ( V_1667 , 0xffffff ) ;
F_46 ( V_1668 ,
( V_1669 |
V_1670 ) ) ;
F_46 ( V_138 , 0 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
if ( ! ( F_33 ( V_138 ) & V_128 ) )
break;
F_24 ( 10 ) ;
}
F_435 ( V_5 , & V_5 -> V_970 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_46 ( V_1671 + V_1454 ,
( ( T_6 ) V_5 -> V_1353 >> 32 ) ) ;
F_46 ( V_1671 + V_16 ,
( ( T_6 ) V_5 -> V_1353 & 0xffffffff ) ) ;
F_46 ( V_1672 , V_37 ) ;
F_46 ( V_1673 , V_1674 ) ;
for ( V_42 = V_37 ;
V_42 < V_1674 + V_1345 ;
V_42 += sizeof( T_1 ) ) {
F_29 ( V_5 , V_42 , 0 ) ;
F_24 ( 40 ) ;
}
}
F_46 ( V_138 , V_128 | V_5 -> V_127 ) ;
F_46 ( V_1060 , V_1367 | V_1675 ) ;
F_46 ( V_1053 , V_1363 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1061 , V_1364 | V_1676 ) ;
if ( V_5 -> V_178 & V_302 ) {
V_5 -> V_178 &= ~ V_787 ;
F_31 ( V_359 , V_1325 ) ;
F_24 ( 10 ) ;
}
V_5 -> V_365 |= V_1677 | V_1678 |
V_730 | V_1679 |
V_1680 ;
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_365 |= V_728 | V_729 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_567 ) &&
F_30 ( V_5 ) != V_536 )
V_5 -> V_365 |= V_723 ;
F_31 ( V_380 , V_5 -> V_365 | V_1681 | V_1682 ) ;
F_24 ( 40 ) ;
if ( ! F_23 ( V_5 , V_532 ) ) {
T_1 V_1683 ;
V_1683 = V_540 | V_538 |
V_541 | V_542 |
V_539 | V_546 ;
if ( F_30 ( V_5 ) == V_640 )
V_1683 |= V_549 |
V_1684 ;
if ( F_30 ( V_5 ) == V_1487 )
V_1683 |= V_1685 ;
V_5 -> V_22 &= ~ V_1683 ;
V_5 -> V_22 |= F_33 ( V_136 ) & V_1683 ;
if ( F_23 ( V_5 , V_643 ) )
V_5 -> V_22 |= ( V_538 |
V_539 ) ;
}
F_31 ( V_136 , V_5 -> V_22 ) ;
F_24 ( 100 ) ;
if ( F_23 ( V_5 , V_1686 ) ) {
V_7 = F_33 ( V_1077 ) ;
V_7 |= V_1400 ;
if ( V_5 -> V_129 > 1 )
V_7 |= V_1687 ;
if ( ! F_23 ( V_5 , 1SHOT_MSI ) )
V_7 |= V_1688 ;
F_46 ( V_1077 , V_7 ) ;
}
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_31 ( V_1078 , V_1373 ) ;
F_24 ( 40 ) ;
}
V_7 = ( V_1375 | V_1689 |
V_1690 | V_1691 |
V_1692 | V_1693 |
V_1694 | V_1695 |
V_1696 ) ;
if ( F_30 ( V_5 ) == V_501 &&
F_76 ( V_5 ) != V_1425 ) {
if ( F_23 ( V_5 , V_1593 ) &&
( F_76 ( V_5 ) == V_1697 ||
F_76 ( V_5 ) == V_1698 ) ) {
} else if ( ! ( F_33 ( V_1243 ) & V_1640 ) &&
! F_23 ( V_5 , V_1641 ) ) {
V_7 |= V_1699 ;
}
}
if ( F_23 ( V_5 , 5755_PLUS ) )
V_7 |= V_1700 ;
if ( F_30 ( V_5 ) == V_256 )
V_7 |= V_1701 ;
F_31 ( V_1068 , V_7 ) ;
F_24 ( 40 ) ;
if ( F_23 ( V_5 , V_839 ) ) {
T_3 V_1391 ;
F_420 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
& V_1391 ) ;
if ( F_30 ( V_5 ) == V_499 ) {
V_1391 &= ~ V_1702 ;
V_1391 |= V_1703 ;
} else if ( F_30 ( V_5 ) == V_500 ) {
V_1391 &= ~ ( V_1704 | V_1702 ) ;
V_1391 |= V_1703 ;
}
F_422 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
V_1391 ) ;
}
F_31 ( V_1067 , V_1532 ) ;
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) {
for ( V_42 = 0 ; V_42 < V_1705 ; V_42 ++ ) {
if ( F_33 ( V_1706 + ( V_42 << 2 ) ) > F_456 ( V_5 ) )
break;
}
if ( V_42 < V_1705 ) {
V_7 = F_33 ( V_1659 ) ;
V_7 |= F_452 ( V_5 ) ;
F_46 ( V_1659 , V_7 ) ;
F_82 ( V_5 , 5719_5720_RDMA_BUG ) ;
}
}
F_46 ( V_1058 , V_1366 | V_1707 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1062 , V_1376 ) ;
if ( F_30 ( V_5 ) == V_45 )
F_46 ( V_1049 ,
V_1372 | V_1708 ) ;
else
F_46 ( V_1049 , V_1372 ) ;
F_46 ( V_1052 , V_1374 | V_1709 ) ;
F_46 ( V_1059 , V_1362 | V_1710 ) ;
V_7 = V_1365 | V_1711 ;
if ( F_23 ( V_5 , V_1712 ) )
V_7 |= V_1713 ;
F_46 ( V_1055 , V_7 ) ;
F_46 ( V_1048 , V_1370 ) ;
if ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) )
F_46 ( V_1048 , V_1370 | 0x8 ) ;
V_7 = V_1369 | V_1714 ;
if ( F_23 ( V_5 , V_1105 ) )
V_7 |= V_1715 ;
F_46 ( V_1051 , V_7 ) ;
F_46 ( V_1050 , V_1368 | V_1716 ) ;
if ( F_76 ( V_5 ) == V_757 ) {
V_75 = F_188 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
if ( F_30 ( V_5 ) == V_667 ) {
F_190 ( V_5 ) ;
}
if ( F_23 ( V_5 , V_1593 ) ) {
V_75 = F_191 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
V_5 -> V_354 = V_1360 ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
V_5 -> V_354 |= V_1717 ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_765 ) {
V_7 = V_1718 | V_1719 ;
V_5 -> V_354 &= ~ V_7 ;
V_5 -> V_354 |= F_33 ( V_361 ) & V_7 ;
}
F_31 ( V_361 , V_5 -> V_354 ) ;
F_24 ( 100 ) ;
if ( F_23 ( V_5 , V_1210 ) ) {
F_451 ( V_5 ) ;
F_46 ( V_1720 , 0x5f865437 ) ;
F_46 ( V_1721 , 0xe4ac62cc ) ;
F_46 ( V_1722 , 0x50103a45 ) ;
F_46 ( V_1723 , 0x36621985 ) ;
F_46 ( V_1724 , 0xbf14c0e8 ) ;
F_46 ( V_1725 , 0x1bc27a1e ) ;
F_46 ( V_1726 , 0x84f4b556 ) ;
F_46 ( V_1727 , 0x094ea6fe ) ;
F_46 ( V_1728 , 0x7dda01e7 ) ;
F_46 ( V_1729 , 0xc04d7481 ) ;
}
V_5 -> V_352 = V_731 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_5 -> V_352 |= V_1730 ;
if ( F_30 ( V_5 ) == V_765 )
V_5 -> V_352 |= V_1731 ;
if ( F_23 ( V_5 , V_1210 ) )
V_5 -> V_352 |= V_1732 |
V_1733 |
V_1734 |
V_1735 |
V_1736 |
V_1737 ;
F_31 ( V_359 , V_5 -> V_352 ) ;
F_24 ( 10 ) ;
F_46 ( V_725 , V_5 -> V_563 ) ;
F_46 ( V_381 , V_383 ) ;
if ( V_5 -> V_178 & V_567 ) {
F_31 ( V_359 , V_1325 ) ;
F_24 ( 10 ) ;
}
F_31 ( V_359 , V_5 -> V_352 ) ;
F_24 ( 10 ) ;
if ( V_5 -> V_178 & V_567 ) {
if ( ( F_30 ( V_5 ) == V_500 ) &&
! ( V_5 -> V_178 & V_1738 ) ) {
V_7 = F_33 ( V_573 ) ;
V_7 &= 0xfffff000 ;
V_7 |= 0x880 ;
F_46 ( V_573 , V_7 ) ;
}
if ( F_76 ( V_5 ) == V_1739 )
F_46 ( V_573 , 0x616000 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) )
V_7 = 1 ;
else
V_7 = 2 ;
F_31 ( V_1740 , V_7 ) ;
if ( F_30 ( V_5 ) == V_500 &&
( V_5 -> V_178 & V_567 ) ) {
F_82 ( V_5 , V_938 ) ;
}
if ( ( V_5 -> V_178 & V_302 ) &&
F_30 ( V_5 ) == V_548 ) {
T_1 V_596 ;
V_596 = F_33 ( V_1741 ) ;
F_46 ( V_1741 , V_596 | V_1742 ) ;
V_5 -> V_22 &= ~ V_1743 ;
V_5 -> V_22 |= V_1744 ;
F_46 ( V_136 , V_5 -> V_22 ) ;
}
if ( ! F_23 ( V_5 , V_263 ) ) {
if ( V_5 -> V_178 & V_397 )
V_5 -> V_178 &= ~ V_397 ;
V_75 = F_198 ( V_5 , false ) ;
if ( V_75 )
return V_75 ;
if ( ! ( V_5 -> V_178 & V_567 ) &&
! ( V_5 -> V_178 & V_179 ) ) {
T_1 V_596 ;
if ( ! F_57 ( V_5 , V_519 , & V_596 ) ) {
F_59 ( V_5 , V_519 ,
V_596 | V_1745 ) ;
F_57 ( V_5 , V_1746 , & V_596 ) ;
}
}
}
F_445 ( V_5 -> V_111 ) ;
F_46 ( V_1747 , 0xc2000000 & V_1748 ) ;
F_46 ( V_1749 , 0xffffffff & V_1748 ) ;
F_46 ( V_1750 , 0x86000004 & V_1748 ) ;
F_46 ( V_1751 , 0xffffffff & V_1748 ) ;
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) )
V_200 = 8 ;
else
V_200 = 16 ;
if ( F_23 ( V_5 , V_305 ) )
V_200 -= 4 ;
switch ( V_200 ) {
case 16 :
F_46 ( V_1752 , 0 ) ; F_46 ( V_1753 , 0 ) ;
case 15 :
F_46 ( V_1754 , 0 ) ; F_46 ( V_1755 , 0 ) ;
case 14 :
F_46 ( V_1756 , 0 ) ; F_46 ( V_1757 , 0 ) ;
case 13 :
F_46 ( V_1758 , 0 ) ; F_46 ( V_1759 , 0 ) ;
case 12 :
F_46 ( V_1760 , 0 ) ; F_46 ( V_1761 , 0 ) ;
case 11 :
F_46 ( V_1762 , 0 ) ; F_46 ( V_1763 , 0 ) ;
case 10 :
F_46 ( V_1764 , 0 ) ; F_46 ( V_1765 , 0 ) ;
case 9 :
F_46 ( V_1766 , 0 ) ; F_46 ( V_1767 , 0 ) ;
case 8 :
F_46 ( V_1768 , 0 ) ; F_46 ( V_1769 , 0 ) ;
case 7 :
F_46 ( V_1770 , 0 ) ; F_46 ( V_1771 , 0 ) ;
case 6 :
F_46 ( V_1772 , 0 ) ; F_46 ( V_1773 , 0 ) ;
case 5 :
F_46 ( V_1774 , 0 ) ; F_46 ( V_1775 , 0 ) ;
case 4 :
case 3 :
case 2 :
case 1 :
default:
break;
}
if ( F_23 ( V_5 , V_60 ) )
F_11 ( V_5 , V_1776 ,
V_1777 ) ;
F_93 ( V_5 , V_96 ) ;
return 0 ;
}
static int F_457 ( struct V_4 * V_5 , bool V_1531 )
{
F_193 ( V_5 ) ;
F_95 ( V_5 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
return F_453 ( V_5 , V_1531 ) ;
}
static void F_458 ( struct V_4 * V_5 , struct V_1778 * V_1779 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1780 ; V_42 ++ , V_1779 ++ ) {
T_1 V_6 = V_42 * V_1781 , V_74 = V_1781 ;
F_40 ( V_5 , ( T_1 * ) V_1779 , V_6 , V_74 ) ;
V_6 += V_74 ;
if ( V_1779 -> V_1782 != V_1783 ||
! ( V_1779 -> V_1784 & V_1785 ) )
memset ( V_1779 , 0 , V_1781 ) ;
}
}
static T_14 F_459 ( struct V_543 * V_111 ,
struct V_1786 * V_1787 , char * V_626 )
{
struct V_1788 * V_12 = F_460 ( V_111 ) ;
struct V_362 * V_1789 = F_151 ( V_12 ) ;
struct V_4 * V_5 = F_109 ( V_1789 ) ;
struct V_1790 * V_1791 = F_461 ( V_1787 ) ;
T_1 V_1792 ;
F_69 ( & V_5 -> V_207 ) ;
F_40 ( V_5 , & V_1792 , V_1791 -> V_1027 ,
sizeof( V_1792 ) ) ;
F_70 ( & V_5 -> V_207 ) ;
return sprintf ( V_626 , L_55 , V_1792 ) ;
}
static void F_462 ( struct V_4 * V_5 )
{
if ( V_5 -> V_1793 ) {
F_463 ( V_5 -> V_1793 ) ;
V_5 -> V_1793 = NULL ;
F_464 ( & V_5 -> V_12 -> V_111 . V_1794 , & V_1795 ) ;
}
}
static void F_465 ( struct V_4 * V_5 )
{
int V_42 , V_75 ;
T_1 V_634 = 0 ;
struct V_1788 * V_12 = V_5 -> V_12 ;
struct V_1778 V_1796 [ V_1780 ] ;
F_458 ( V_5 , V_1796 ) ;
for ( V_42 = 0 ; V_42 < V_1780 ; V_42 ++ ) {
if ( ! V_1796 [ V_42 ] . V_1797 )
continue;
V_634 += V_1796 [ V_42 ] . V_1798 ;
V_634 += V_1796 [ V_42 ] . V_1797 ;
}
if ( ! V_634 )
return;
V_75 = F_466 ( & V_12 -> V_111 . V_1794 , & V_1795 ) ;
if ( V_75 ) {
F_115 ( & V_12 -> V_111 , L_56 ) ;
return;
}
V_5 -> V_1793 = F_467 ( & V_12 -> V_111 ) ;
if ( F_114 ( V_5 -> V_1793 ) ) {
V_5 -> V_1793 = NULL ;
F_115 ( & V_12 -> V_111 , L_57 ) ;
F_464 ( & V_12 -> V_111 . V_1794 , & V_1795 ) ;
}
}
static void F_468 ( struct V_4 * V_5 )
{
struct V_1352 * V_1799 = V_5 -> V_1351 ;
if ( ! V_5 -> V_338 )
return;
F_469 ( & V_1799 -> V_1800 , V_1801 ) ;
F_469 ( & V_1799 -> V_1802 , V_1803 ) ;
F_469 ( & V_1799 -> V_1804 , V_1805 ) ;
F_469 ( & V_1799 -> V_1806 , V_1807 ) ;
F_469 ( & V_1799 -> V_1808 , V_1809 ) ;
F_469 ( & V_1799 -> V_1810 , V_1811 ) ;
F_469 ( & V_1799 -> V_1812 , V_1813 ) ;
F_469 ( & V_1799 -> V_1814 , V_1815 ) ;
F_469 ( & V_1799 -> V_1816 , V_1817 ) ;
F_469 ( & V_1799 -> V_1818 , V_1819 ) ;
F_469 ( & V_1799 -> V_1820 , V_1821 ) ;
F_469 ( & V_1799 -> V_1822 , V_1823 ) ;
F_469 ( & V_1799 -> V_1824 , V_1825 ) ;
if ( F_264 ( F_23 ( V_5 , 5719_5720_RDMA_BUG ) &&
( V_1799 -> V_1820 . V_485 + V_1799 -> V_1822 . V_485 +
V_1799 -> V_1824 . V_485 ) > V_1705 ) ) {
T_1 V_7 ;
V_7 = F_33 ( V_1659 ) ;
V_7 &= ~ F_452 ( V_5 ) ;
F_46 ( V_1659 , V_7 ) ;
F_84 ( V_5 , 5719_5720_RDMA_BUG ) ;
}
F_469 ( & V_1799 -> V_1826 , V_1827 ) ;
F_469 ( & V_1799 -> V_1828 , V_1829 ) ;
F_469 ( & V_1799 -> V_1830 , V_1831 ) ;
F_469 ( & V_1799 -> V_1832 , V_1833 ) ;
F_469 ( & V_1799 -> V_1834 , V_1835 ) ;
F_469 ( & V_1799 -> V_1836 , V_1837 ) ;
F_469 ( & V_1799 -> V_1838 , V_1839 ) ;
F_469 ( & V_1799 -> V_1840 , V_1841 ) ;
F_469 ( & V_1799 -> V_1842 , V_1843 ) ;
F_469 ( & V_1799 -> V_1844 , V_1845 ) ;
F_469 ( & V_1799 -> V_1846 , V_1847 ) ;
F_469 ( & V_1799 -> V_1848 , V_1849 ) ;
F_469 ( & V_1799 -> V_1850 , V_1851 ) ;
F_469 ( & V_1799 -> V_1852 , V_1853 ) ;
F_469 ( & V_1799 -> V_1854 , V_1855 ) ;
if ( F_30 ( V_5 ) != V_476 &&
F_76 ( V_5 ) != V_1611 &&
F_76 ( V_5 ) != V_1612 ) {
F_469 ( & V_1799 -> V_1856 , V_1857 ) ;
} else {
T_1 V_7 = F_33 ( V_1230 ) ;
V_7 = ( V_7 & V_1231 ) ? 1 : 0 ;
if ( V_7 ) {
F_46 ( V_1230 , V_1231 ) ;
V_1799 -> V_1856 . V_485 += V_7 ;
if ( V_1799 -> V_1856 . V_485 < V_7 )
V_1799 -> V_1856 . V_486 += 1 ;
}
V_1799 -> V_1858 = V_1799 -> V_1856 ;
}
F_469 ( & V_1799 -> V_1859 , V_1860 ) ;
}
static void F_470 ( struct V_4 * V_5 )
{
T_1 V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( F_50 ( V_131 ) ) {
if ( V_131 -> V_1490 == V_131 -> V_149 &&
V_131 -> V_1491 == V_131 -> V_147 ) {
if ( V_131 -> V_1489 < 1 ) {
V_131 -> V_1489 ++ ;
return;
}
F_345 ( 0 , V_131 ) ;
}
}
V_131 -> V_1489 = 0 ;
V_131 -> V_1490 = V_131 -> V_149 ;
V_131 -> V_1491 = V_131 -> V_147 ;
}
}
static void F_471 ( unsigned long V_1861 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1861 ;
if ( V_5 -> V_125 || F_23 ( V_5 , V_1225 ) )
goto V_1862;
F_314 ( & V_5 -> V_207 ) ;
if ( F_30 ( V_5 ) == V_476 ||
F_23 ( V_5 , 57765_CLASS ) )
F_470 ( V_5 ) ;
if ( F_23 ( V_5 , V_30 ) ) {
F_33 ( V_138 ) ;
}
if ( ! F_23 ( V_5 , V_133 ) ) {
if ( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & V_135 ) {
F_46 ( V_136 ,
V_5 -> V_22 | V_137 ) ;
} else {
F_46 ( V_138 , V_5 -> V_127 |
V_128 | V_1863 ) ;
}
if ( ! ( F_33 ( V_1068 ) & V_1375 ) ) {
F_315 ( & V_5 -> V_207 ) ;
F_320 ( V_5 ) ;
goto V_1862;
}
}
if ( ! -- V_5 -> V_1864 ) {
if ( F_23 ( V_5 , 5705_PLUS ) )
F_468 ( V_5 ) ;
if ( V_5 -> V_337 && ! -- V_5 -> V_337 )
F_133 ( V_5 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
T_1 V_1865 ;
int V_1866 ;
V_1865 = F_33 ( V_789 ) ;
V_1866 = 0 ;
if ( V_5 -> V_178 & V_815 ) {
if ( V_1865 & V_1867 )
V_1866 = 1 ;
} else if ( V_1865 & V_793 )
V_1866 = 1 ;
if ( V_1866 )
F_198 ( V_5 , false ) ;
} else if ( F_23 ( V_5 , V_143 ) ) {
T_1 V_1865 = F_33 ( V_789 ) ;
int V_1868 = 0 ;
if ( V_5 -> V_338 &&
( V_1865 & V_793 ) ) {
V_1868 = 1 ;
}
if ( ! V_5 -> V_338 &&
( V_1865 & ( V_911 |
V_926 ) ) ) {
V_1868 = 1 ;
}
if ( V_1868 ) {
if ( ! V_5 -> V_923 ) {
F_31 ( V_380 ,
( V_5 -> V_365 &
~ V_368 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_380 , V_5 -> V_365 ) ;
F_24 ( 40 ) ;
}
F_198 ( V_5 , false ) ;
}
} else if ( ( V_5 -> V_178 & V_302 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_230 ( V_5 ) ;
}
V_5 -> V_1864 = V_5 -> V_1869 ;
}
if ( ! -- V_5 -> V_1870 ) {
if ( F_23 ( V_5 , V_305 ) && ! F_23 ( V_5 , V_60 ) ) {
F_86 ( V_5 ) ;
F_29 ( V_5 , V_306 ,
V_1871 ) ;
F_29 ( V_5 , V_308 , 4 ) ;
F_29 ( V_5 , V_309 ,
V_1872 ) ;
F_85 ( V_5 ) ;
}
V_5 -> V_1870 = V_5 -> V_1873 ;
}
F_315 ( & V_5 -> V_207 ) ;
V_1862:
V_5 -> V_1874 . V_1875 = V_295 + V_5 -> V_1876 ;
F_472 ( & V_5 -> V_1874 ) ;
}
static void F_473 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_133 ) &&
F_30 ( V_5 ) != V_476 &&
! F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_1876 = V_1877 ;
else
V_5 -> V_1876 = V_1877 / 10 ;
F_182 ( V_5 -> V_1876 > V_1877 ) ;
V_5 -> V_1869 = ( V_1877 / V_5 -> V_1876 ) ;
V_5 -> V_1873 = ( V_1877 / V_5 -> V_1876 ) *
V_1878 ;
F_474 ( & V_5 -> V_1874 ) ;
V_5 -> V_1874 . V_72 = ( unsigned long ) V_5 ;
V_5 -> V_1874 . V_1879 = F_471 ;
}
static void F_475 ( struct V_4 * V_5 )
{
V_5 -> V_1870 = V_5 -> V_1873 ;
V_5 -> V_1864 = V_5 -> V_1869 ;
V_5 -> V_1874 . V_1875 = V_295 + V_5 -> V_1876 ;
F_472 ( & V_5 -> V_1874 ) ;
}
static void F_476 ( struct V_4 * V_5 )
{
F_477 ( & V_5 -> V_1874 ) ;
}
static int F_478 ( struct V_4 * V_5 , bool V_1531 )
__releases( V_5 -> V_207 )
__acquires( V_5 -> V_207 )
{
int V_75 ;
V_75 = F_457 ( V_5 , V_1531 ) ;
if ( V_75 ) {
F_183 ( V_5 -> V_111 ,
L_58 ) ;
F_427 ( V_5 , V_110 , 1 ) ;
F_239 ( V_5 ) ;
F_476 ( V_5 ) ;
V_5 -> V_125 = 0 ;
F_332 ( V_5 ) ;
F_479 ( V_5 -> V_111 ) ;
F_238 ( V_5 , 0 ) ;
}
return V_75 ;
}
static void F_480 ( struct V_1880 * V_1881 )
{
struct V_4 * V_5 = F_236 ( V_1881 , struct V_4 , V_1224 ) ;
int V_75 ;
F_238 ( V_5 , 0 ) ;
if ( ! F_143 ( V_5 -> V_111 ) ) {
F_84 ( V_5 , V_1225 ) ;
F_239 ( V_5 ) ;
return;
}
F_239 ( V_5 ) ;
F_121 ( V_5 ) ;
F_338 ( V_5 ) ;
F_238 ( V_5 , 1 ) ;
if ( F_23 ( V_5 , V_1097 ) ) {
V_5 -> V_1096 = F_26 ;
V_5 -> V_1882 = F_17 ;
F_82 ( V_5 , V_31 ) ;
F_84 ( V_5 , V_1097 ) ;
}
F_427 ( V_5 , V_110 , 0 ) ;
V_75 = F_457 ( V_5 , true ) ;
if ( V_75 )
goto V_502;
F_340 ( V_5 ) ;
V_502:
F_239 ( V_5 ) ;
if ( ! V_75 )
F_118 ( V_5 ) ;
F_84 ( V_5 , V_1225 ) ;
}
static int F_481 ( struct V_4 * V_5 , int V_1883 )
{
T_15 V_1884 ;
unsigned long V_10 ;
char * V_265 ;
struct V_130 * V_131 = & V_5 -> V_123 [ V_1883 ] ;
if ( V_5 -> V_129 == 1 )
V_265 = V_5 -> V_111 -> V_265 ;
else {
V_265 = & V_131 -> V_1885 [ 0 ] ;
snprintf ( V_265 , V_1886 , L_59 , V_5 -> V_111 -> V_265 , V_1883 ) ;
V_265 [ V_1886 - 1 ] = 0 ;
}
if ( F_23 ( V_5 , V_1395 ) || F_23 ( V_5 , V_1686 ) ) {
V_1884 = F_345 ;
if ( F_23 ( V_5 , 1SHOT_MSI ) )
V_1884 = F_344 ;
V_10 = 0 ;
} else {
V_1884 = F_347 ;
if ( F_23 ( V_5 , V_133 ) )
V_1884 = F_348 ;
V_10 = V_1887 ;
}
return F_482 ( V_131 -> V_1238 , V_1884 , V_10 , V_265 , V_131 ) ;
}
static int F_483 ( struct V_4 * V_5 )
{
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
struct V_362 * V_111 = V_5 -> V_111 ;
int V_75 , V_42 , V_1888 = 0 ;
T_1 V_7 ;
if ( ! F_143 ( V_111 ) )
return - V_82 ;
F_45 ( V_5 ) ;
F_484 ( V_131 -> V_1238 , V_131 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1077 ) | V_1688 ;
F_46 ( V_1077 , V_7 ) ;
}
V_75 = F_482 ( V_131 -> V_1238 , F_349 ,
V_1887 , V_111 -> V_265 , V_131 ) ;
if ( V_75 )
return V_75 ;
V_131 -> V_134 -> V_57 &= ~ V_135 ;
F_48 ( V_5 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_131 -> V_126 ) ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ ) {
T_1 V_124 , V_120 ;
V_124 = F_485 ( V_131 -> V_124 ) ;
V_120 = F_33 ( V_119 ) ;
if ( ( V_124 != 0 ) ||
( V_120 & V_121 ) ) {
V_1888 = 1 ;
break;
}
if ( F_23 ( V_5 , 57765_PLUS ) &&
V_131 -> V_134 -> V_1083 != V_131 -> V_132 )
F_47 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
F_161 ( 10 ) ;
}
F_45 ( V_5 ) ;
F_484 ( V_131 -> V_1238 , V_131 ) ;
V_75 = F_481 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
if ( V_1888 ) {
if ( F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , 1SHOT_MSI ) ) {
V_7 = F_33 ( V_1077 ) & ~ V_1688 ;
F_46 ( V_1077 , V_7 ) ;
}
return 0 ;
}
return - V_208 ;
}
static int F_486 ( struct V_4 * V_5 )
{
int V_75 ;
T_3 V_1380 ;
if ( ! F_23 ( V_5 , V_1395 ) )
return 0 ;
F_420 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
F_422 ( V_5 -> V_12 , V_1379 ,
V_1380 & ~ V_1889 ) ;
V_75 = F_483 ( V_5 ) ;
F_422 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
if ( ! V_75 )
return 0 ;
if ( V_75 != - V_208 )
return V_75 ;
F_141 ( V_5 -> V_111 , L_60
L_61
L_62 ) ;
F_484 ( V_5 -> V_123 [ 0 ] . V_1238 , & V_5 -> V_123 [ 0 ] ) ;
F_487 ( V_5 -> V_12 ) ;
F_84 ( V_5 , V_1395 ) ;
V_5 -> V_123 [ 0 ] . V_1238 = V_5 -> V_12 -> V_276 ;
V_75 = F_481 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
F_238 ( V_5 , 1 ) ;
F_427 ( V_5 , V_110 , 1 ) ;
V_75 = F_457 ( V_5 , true ) ;
F_239 ( V_5 ) ;
if ( V_75 )
F_484 ( V_5 -> V_123 [ 0 ] . V_1238 , & V_5 -> V_123 [ 0 ] ) ;
return V_75 ;
}
static int F_488 ( struct V_4 * V_5 )
{
const struct V_659 * V_660 ;
if ( F_489 ( & V_5 -> V_662 , V_5 -> V_1890 , & V_5 -> V_12 -> V_111 ) ) {
F_183 ( V_5 -> V_111 , L_63 ,
V_5 -> V_1890 ) ;
return - V_1891 ;
}
V_660 = (struct V_659 * ) V_5 -> V_662 -> V_72 ;
V_5 -> V_661 = F_170 ( V_660 -> V_74 ) ;
if ( V_5 -> V_661 < ( V_5 -> V_662 -> V_634 - V_663 ) ) {
F_183 ( V_5 -> V_111 , L_64 ,
V_5 -> V_661 , V_5 -> V_1890 ) ;
F_490 ( V_5 -> V_662 ) ;
V_5 -> V_662 = NULL ;
return - V_64 ;
}
V_5 -> V_1890 = NULL ;
return 0 ;
}
static T_1 F_491 ( struct V_4 * V_5 )
{
T_1 V_129 = F_492 ( V_5 -> V_1221 , V_5 -> V_1348 ) ;
if ( V_129 > 1 ) {
V_129 = F_493 ( unsigned , V_129 + 1 , V_5 -> V_122 ) ;
}
return V_129 ;
}
static bool F_494 ( struct V_4 * V_5 )
{
int V_42 , V_628 ;
struct V_1892 V_1893 [ V_1894 ] ;
V_5 -> V_1348 = V_5 -> V_1895 ;
V_5 -> V_1221 = V_5 -> V_1896 ;
if ( ! V_5 -> V_1221 )
V_5 -> V_1221 = F_495 () ;
if ( V_5 -> V_1221 > V_5 -> V_1897 )
V_5 -> V_1221 = V_5 -> V_1897 ;
if ( ! V_5 -> V_1895 )
V_5 -> V_1348 = 1 ;
V_5 -> V_129 = F_491 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
V_1893 [ V_42 ] . V_1256 = V_42 ;
V_1893 [ V_42 ] . V_1898 = 0 ;
}
V_628 = F_496 ( V_5 -> V_12 , V_1893 , V_5 -> V_129 ) ;
if ( V_628 < 0 ) {
return false ;
} else if ( V_628 != 0 ) {
if ( F_496 ( V_5 -> V_12 , V_1893 , V_628 ) )
return false ;
F_497 ( V_5 -> V_111 , L_65 ,
V_5 -> V_129 , V_628 ) ;
V_5 -> V_129 = V_628 ;
V_5 -> V_1221 = F_492 ( V_628 - 1 , 1 ) ;
if ( V_5 -> V_1348 )
V_5 -> V_1348 = F_318 ( V_5 -> V_1221 , V_5 -> V_1899 ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1238 = V_1893 [ V_42 ] . V_1898 ;
if ( F_498 ( V_5 -> V_111 , V_5 -> V_1221 ) ) {
F_499 ( V_5 -> V_12 ) ;
return false ;
}
if ( V_5 -> V_129 == 1 )
return true ;
F_82 ( V_5 , V_1210 ) ;
if ( V_5 -> V_1348 > 1 )
F_82 ( V_5 , V_1105 ) ;
F_500 ( V_5 -> V_111 , V_5 -> V_1348 ) ;
return true ;
}
static void F_501 ( struct V_4 * V_5 )
{
if ( ( F_23 ( V_5 , V_1900 ) || F_23 ( V_5 , V_1063 ) ) &&
! F_23 ( V_5 , V_133 ) ) {
F_141 ( V_5 -> V_111 ,
L_66 ) ;
goto V_1901;
}
if ( F_23 ( V_5 , V_1063 ) && F_494 ( V_5 ) )
F_82 ( V_5 , V_1686 ) ;
else if ( F_23 ( V_5 , V_1900 ) && F_502 ( V_5 -> V_12 ) == 0 )
F_82 ( V_5 , V_1395 ) ;
if ( F_23 ( V_5 , V_1395 ) || F_23 ( V_5 , V_1686 ) ) {
T_1 V_1902 = F_33 ( V_1077 ) ;
if ( F_23 ( V_5 , V_1686 ) && V_5 -> V_129 > 1 )
V_1902 |= V_1687 ;
if ( ! F_23 ( V_5 , 1SHOT_MSI ) )
V_1902 |= V_1688 ;
F_46 ( V_1077 , V_1902 | V_1400 ) ;
}
V_1901:
if ( ! F_23 ( V_5 , V_1686 ) ) {
V_5 -> V_129 = 1 ;
V_5 -> V_123 [ 0 ] . V_1238 = V_5 -> V_12 -> V_276 ;
}
if ( V_5 -> V_129 == 1 ) {
V_5 -> V_1348 = 1 ;
V_5 -> V_1221 = 1 ;
F_500 ( V_5 -> V_111 , 1 ) ;
F_498 ( V_5 -> V_111 , 1 ) ;
}
}
static void F_503 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1686 ) )
F_499 ( V_5 -> V_12 ) ;
else if ( F_23 ( V_5 , V_1395 ) )
F_487 ( V_5 -> V_12 ) ;
F_84 ( V_5 , V_1395 ) ;
F_84 ( V_5 , V_1686 ) ;
F_84 ( V_5 , V_1210 ) ;
F_84 ( V_5 , V_1105 ) ;
}
static int F_504 ( struct V_4 * V_5 , bool V_1531 , bool V_1903 ,
bool V_1904 )
{
struct V_362 * V_111 = V_5 -> V_111 ;
int V_42 , V_75 ;
F_501 ( V_5 ) ;
F_450 ( V_5 ) ;
V_75 = F_416 ( V_5 ) ;
if ( V_75 )
goto V_1905;
F_334 ( V_5 ) ;
F_332 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_75 = F_481 ( V_5 , V_42 ) ;
if ( V_75 ) {
for ( V_42 -- ; V_42 >= 0 ; V_42 -- ) {
V_131 = & V_5 -> V_123 [ V_42 ] ;
F_484 ( V_131 -> V_1238 , V_131 ) ;
}
goto V_1906;
}
}
F_238 ( V_5 , 0 ) ;
if ( V_1904 )
F_42 ( V_5 , V_96 ) ;
V_75 = F_457 ( V_5 , V_1531 ) ;
if ( V_75 ) {
F_427 ( V_5 , V_110 , 1 ) ;
F_405 ( V_5 ) ;
}
F_239 ( V_5 ) ;
if ( V_75 )
goto V_1907;
if ( V_1903 && F_23 ( V_5 , V_1395 ) ) {
V_75 = F_486 ( V_5 ) ;
if ( V_75 ) {
F_238 ( V_5 , 0 ) ;
F_427 ( V_5 , V_110 , 1 ) ;
F_405 ( V_5 ) ;
F_239 ( V_5 ) ;
goto V_1906;
}
if ( ! F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , V_1395 ) ) {
T_1 V_7 = F_33 ( V_1908 ) ;
F_46 ( V_1908 ,
V_7 | V_1909 ) ;
}
}
F_118 ( V_5 ) ;
F_465 ( V_5 ) ;
F_238 ( V_5 , 0 ) ;
F_475 ( V_5 ) ;
F_82 ( V_5 , V_562 ) ;
F_48 ( V_5 ) ;
if ( V_1904 )
F_248 ( V_5 ) ;
else
F_251 ( V_5 ) ;
F_239 ( V_5 ) ;
F_505 ( V_111 ) ;
if ( V_111 -> V_1192 & V_1327 )
F_391 ( V_111 , V_111 -> V_1192 ) ;
return 0 ;
V_1907:
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_484 ( V_131 -> V_1238 , V_131 ) ;
}
V_1906:
F_330 ( V_5 ) ;
F_336 ( V_5 ) ;
F_415 ( V_5 ) ;
V_1905:
F_503 ( V_5 ) ;
return V_75 ;
}
static void F_506 ( struct V_4 * V_5 )
{
int V_42 ;
F_323 ( V_5 ) ;
F_338 ( V_5 ) ;
F_476 ( V_5 ) ;
F_462 ( V_5 ) ;
F_121 ( V_5 ) ;
F_238 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_427 ( V_5 , V_110 , 1 ) ;
F_405 ( V_5 ) ;
F_84 ( V_5 , V_562 ) ;
F_239 ( V_5 ) ;
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_484 ( V_131 -> V_1238 , V_131 ) ;
}
F_503 ( V_5 ) ;
F_336 ( V_5 ) ;
F_415 ( V_5 ) ;
}
static int F_507 ( struct V_362 * V_111 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_75 ;
if ( V_5 -> V_1890 ) {
V_75 = F_488 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_667 ) {
if ( V_75 ) {
F_141 ( V_5 -> V_111 , L_67 ) ;
V_5 -> V_178 &= ~ V_336 ;
} else if ( ! ( V_5 -> V_178 & V_336 ) ) {
F_141 ( V_5 -> V_111 , L_68 ) ;
V_5 -> V_178 |= V_336 ;
}
} else if ( F_76 ( V_5 ) == V_757 ) {
if ( V_75 )
return V_75 ;
} else if ( V_75 ) {
F_141 ( V_5 -> V_111 , L_69 ) ;
F_84 ( V_5 , V_1593 ) ;
} else if ( ! F_23 ( V_5 , V_1593 ) ) {
F_497 ( V_5 -> V_111 , L_70 ) ;
F_82 ( V_5 , V_1593 ) ;
}
}
F_138 ( V_5 ) ;
V_75 = F_194 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_238 ( V_5 , 0 ) ;
F_45 ( V_5 ) ;
F_84 ( V_5 , V_562 ) ;
F_239 ( V_5 ) ;
V_75 = F_504 ( V_5 ,
! ( V_5 -> V_178 & V_569 ) ,
true , true ) ;
if ( V_75 ) {
F_150 ( V_5 , false ) ;
F_195 ( V_5 -> V_12 , V_741 ) ;
}
if ( F_23 ( V_5 , V_990 ) ) {
V_5 -> V_994 = F_508 ( & V_5 -> V_1007 ,
& V_5 -> V_12 -> V_111 ) ;
if ( F_114 ( V_5 -> V_994 ) )
V_5 -> V_994 = NULL ;
}
return V_75 ;
}
static int F_509 ( struct V_362 * V_111 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
F_252 ( V_5 ) ;
F_506 ( V_5 ) ;
memset ( & V_5 -> V_1437 , 0 , sizeof( V_5 -> V_1437 ) ) ;
memset ( & V_5 -> V_1438 , 0 , sizeof( V_5 -> V_1438 ) ) ;
F_196 ( V_5 ) ;
F_138 ( V_5 ) ;
return 0 ;
}
static inline T_6 F_510 ( T_16 * V_7 )
{
return ( ( T_6 ) V_7 -> V_486 << 32 ) | ( ( T_6 ) V_7 -> V_485 ) ;
}
static T_6 F_511 ( struct V_4 * V_5 )
{
struct V_1352 * V_1351 = V_5 -> V_1351 ;
if ( ! ( V_5 -> V_178 & V_567 ) &&
( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) ) {
T_1 V_7 ;
if ( ! F_57 ( V_5 , V_519 , & V_7 ) ) {
F_59 ( V_5 , V_519 ,
V_7 | V_1745 ) ;
F_57 ( V_5 , V_1746 , & V_7 ) ;
} else
V_7 = 0 ;
V_5 -> V_1910 += V_7 ;
return V_5 -> V_1910 ;
}
return F_510 ( & V_1351 -> V_1836 ) ;
}
static void F_429 ( struct V_4 * V_5 , struct V_1911 * V_1912 )
{
struct V_1911 * V_1913 = & V_5 -> V_1438 ;
struct V_1352 * V_1351 = V_5 -> V_1351 ;
F_512 ( V_1826 ) ;
F_512 ( V_1828 ) ;
F_512 ( V_1830 ) ;
F_512 ( V_1832 ) ;
F_512 ( V_1834 ) ;
F_512 ( V_1836 ) ;
F_512 ( V_1838 ) ;
F_512 ( V_1840 ) ;
F_512 ( V_1842 ) ;
F_512 ( V_1844 ) ;
F_512 ( V_1846 ) ;
F_512 ( V_1848 ) ;
F_512 ( V_1850 ) ;
F_512 ( V_1852 ) ;
F_512 ( V_1914 ) ;
F_512 ( V_1915 ) ;
F_512 ( V_1916 ) ;
F_512 ( V_1917 ) ;
F_512 ( V_1918 ) ;
F_512 ( V_1919 ) ;
F_512 ( V_1920 ) ;
F_512 ( V_1921 ) ;
F_512 ( V_1922 ) ;
F_512 ( V_1923 ) ;
F_512 ( V_1924 ) ;
F_512 ( V_1925 ) ;
F_512 ( V_1800 ) ;
F_512 ( V_1802 ) ;
F_512 ( V_1804 ) ;
F_512 ( V_1806 ) ;
F_512 ( V_1926 ) ;
F_512 ( V_1808 ) ;
F_512 ( V_1810 ) ;
F_512 ( V_1812 ) ;
F_512 ( V_1814 ) ;
F_512 ( V_1816 ) ;
F_512 ( V_1818 ) ;
F_512 ( V_1927 ) ;
F_512 ( V_1928 ) ;
F_512 ( V_1929 ) ;
F_512 ( V_1930 ) ;
F_512 ( V_1931 ) ;
F_512 ( V_1932 ) ;
F_512 ( V_1933 ) ;
F_512 ( V_1934 ) ;
F_512 ( V_1935 ) ;
F_512 ( V_1936 ) ;
F_512 ( V_1937 ) ;
F_512 ( V_1938 ) ;
F_512 ( V_1939 ) ;
F_512 ( V_1940 ) ;
F_512 ( V_1820 ) ;
F_512 ( V_1822 ) ;
F_512 ( V_1824 ) ;
F_512 ( V_1941 ) ;
F_512 ( V_1942 ) ;
F_512 ( V_1943 ) ;
F_512 ( V_1944 ) ;
F_512 ( V_1945 ) ;
F_512 ( V_1854 ) ;
F_512 ( V_1856 ) ;
F_512 ( V_1859 ) ;
F_512 ( V_1946 ) ;
F_512 ( V_1947 ) ;
F_512 ( V_1948 ) ;
F_512 ( V_1949 ) ;
F_512 ( V_1950 ) ;
F_512 ( V_1951 ) ;
F_512 ( V_1952 ) ;
F_512 ( V_1953 ) ;
F_512 ( V_1954 ) ;
F_512 ( V_1858 ) ;
}
static void F_428 ( struct V_4 * V_5 , struct V_1955 * V_1956 )
{
struct V_1955 * V_1957 = & V_5 -> V_1437 ;
struct V_1352 * V_1351 = V_5 -> V_1351 ;
V_1956 -> V_1958 = V_1957 -> V_1958 +
F_510 ( & V_1351 -> V_1830 ) +
F_510 ( & V_1351 -> V_1832 ) +
F_510 ( & V_1351 -> V_1834 ) ;
V_1956 -> V_1959 = V_1957 -> V_1959 +
F_510 ( & V_1351 -> V_1820 ) +
F_510 ( & V_1351 -> V_1822 ) +
F_510 ( & V_1351 -> V_1824 ) ;
V_1956 -> V_1960 = V_1957 -> V_1960 +
F_510 ( & V_1351 -> V_1826 ) ;
V_1956 -> V_1961 = V_1957 -> V_1961 +
F_510 ( & V_1351 -> V_1800 ) ;
V_1956 -> V_1859 = V_1957 -> V_1859 +
F_510 ( & V_1351 -> V_1859 ) ;
V_1956 -> V_1943 = V_1957 -> V_1943 +
F_510 ( & V_1351 -> V_1943 ) +
F_510 ( & V_1351 -> V_1808 ) +
F_510 ( & V_1351 -> V_1941 ) +
F_510 ( & V_1351 -> V_1942 ) ;
V_1956 -> V_1962 = V_1957 -> V_1962 +
F_510 ( & V_1351 -> V_1832 ) ;
V_1956 -> V_1963 = V_1957 -> V_1963 +
F_510 ( & V_1351 -> V_1802 ) ;
V_1956 -> V_1964 = V_1957 -> V_1964 +
F_510 ( & V_1351 -> V_1848 ) +
F_510 ( & V_1351 -> V_1852 ) ;
V_1956 -> V_1965 = V_1957 -> V_1965 +
F_510 ( & V_1351 -> V_1854 ) ;
V_1956 -> V_1966 = V_1957 -> V_1966 +
F_510 ( & V_1351 -> V_1838 ) ;
V_1956 -> V_1967 = V_1957 -> V_1967 +
F_510 ( & V_1351 -> V_1942 ) ;
V_1956 -> V_1968 = V_1957 -> V_1968 +
F_510 ( & V_1351 -> V_1941 ) ;
V_1956 -> V_1969 = V_1957 -> V_1969 +
F_511 ( V_5 ) ;
V_1956 -> V_1970 = V_1957 -> V_1970 +
F_510 ( & V_1351 -> V_1856 ) ;
V_1956 -> V_1179 = V_5 -> V_1179 ;
V_1956 -> V_1318 = V_5 -> V_1318 ;
}
static int F_513 ( struct V_362 * V_111 )
{
return V_1079 ;
}
static void F_514 ( struct V_362 * V_111 ,
struct V_1971 * V_8 , void * V_1972 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
V_8 -> V_1973 = 0 ;
memset ( V_1972 , 0 , V_1079 ) ;
if ( V_5 -> V_178 & V_397 )
return;
F_238 ( V_5 , 0 ) ;
F_256 ( V_5 , ( T_1 * ) V_1972 ) ;
F_239 ( V_5 ) ;
}
static int F_515 ( struct V_362 * V_111 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
return V_5 -> V_1974 ;
}
static int F_516 ( struct V_362 * V_111 , struct V_1975 * V_1976 , T_4 * V_72 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_56 ;
T_4 * V_1977 ;
T_1 V_42 , V_595 , V_74 , V_1978 , V_1979 ;
T_5 V_7 ;
if ( F_23 ( V_5 , V_681 ) )
return - V_64 ;
V_595 = V_1976 -> V_595 ;
V_74 = V_1976 -> V_74 ;
V_1976 -> V_74 = 0 ;
V_1976 -> V_1980 = V_1981 ;
if ( V_595 & 3 ) {
V_1978 = V_595 & 3 ;
V_1979 = 4 - V_1978 ;
if ( V_1979 > V_74 ) {
V_1979 = V_74 ;
}
V_56 = F_167 ( V_5 , V_595 - V_1978 , & V_7 ) ;
if ( V_56 )
return V_56 ;
memcpy ( V_72 , ( ( char * ) & V_7 ) + V_1978 , V_1979 ) ;
V_74 -= V_1979 ;
V_595 += V_1979 ;
V_1976 -> V_74 += V_1979 ;
}
V_1977 = & V_72 [ V_1976 -> V_74 ] ;
for ( V_42 = 0 ; V_42 < ( V_74 - ( V_74 & 3 ) ) ; V_42 += 4 ) {
V_56 = F_167 ( V_5 , V_595 + V_42 , & V_7 ) ;
if ( V_56 ) {
V_1976 -> V_74 += V_42 ;
return V_56 ;
}
memcpy ( V_1977 + V_42 , & V_7 , 4 ) ;
}
V_1976 -> V_74 += V_42 ;
if ( V_74 & 3 ) {
V_1977 = & V_72 [ V_1976 -> V_74 ] ;
V_1979 = V_74 & 3 ;
V_1978 = V_595 + V_74 - V_1979 ;
V_56 = F_167 ( V_5 , V_1978 , & V_7 ) ;
if ( V_56 )
return V_56 ;
memcpy ( V_1977 , & V_7 , V_1979 ) ;
V_1976 -> V_74 += V_1979 ;
}
return 0 ;
}
static int F_517 ( struct V_362 * V_111 , struct V_1975 * V_1976 , T_4 * V_72 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_56 ;
T_1 V_595 , V_74 , V_1978 , V_1982 ;
T_4 * V_626 ;
T_5 V_1030 , V_1983 ;
if ( F_23 ( V_5 , V_681 ) ||
V_1976 -> V_1980 != V_1981 )
return - V_64 ;
V_595 = V_1976 -> V_595 ;
V_74 = V_1976 -> V_74 ;
if ( ( V_1978 = ( V_595 & 3 ) ) ) {
V_56 = F_167 ( V_5 , V_595 - V_1978 , & V_1030 ) ;
if ( V_56 )
return V_56 ;
V_74 += V_1978 ;
V_595 &= ~ 3 ;
if ( V_74 < 4 )
V_74 = 4 ;
}
V_1982 = 0 ;
if ( V_74 & 3 ) {
V_1982 = 1 ;
V_74 = ( V_74 + 3 ) & ~ 3 ;
V_56 = F_167 ( V_5 , V_595 + V_74 - 4 , & V_1983 ) ;
if ( V_56 )
return V_56 ;
}
V_626 = V_72 ;
if ( V_1978 || V_1982 ) {
V_626 = F_172 ( V_74 , V_632 ) ;
if ( ! V_626 )
return - V_264 ;
if ( V_1978 )
memcpy ( V_626 , & V_1030 , 4 ) ;
if ( V_1982 )
memcpy ( V_626 + V_74 - 4 , & V_1983 , 4 ) ;
memcpy ( V_626 + V_1978 , V_72 , V_1976 -> V_74 ) ;
}
V_56 = F_175 ( V_5 , V_595 , V_74 , V_626 ) ;
if ( V_626 != V_72 )
F_173 ( V_626 ) ;
return V_56 ;
}
static int F_518 ( struct V_362 * V_111 , struct V_1984 * V_642 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( F_23 ( V_5 , V_263 ) ) {
struct V_209 * V_210 ;
if ( ! ( V_5 -> V_178 & V_389 ) )
return - V_85 ;
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
return F_519 ( V_210 , V_642 ) ;
}
V_642 -> V_391 = ( V_1985 ) ;
if ( ! ( V_5 -> V_178 & V_390 ) )
V_642 -> V_391 |= ( V_1986 |
V_1987 ) ;
if ( ! ( V_5 -> V_178 & V_357 ) ) {
V_642 -> V_391 |= ( V_1988 |
V_1989 |
V_1990 |
V_1991 |
V_1992 ) ;
V_642 -> V_1993 = V_1994 ;
} else {
V_642 -> V_391 |= V_1995 ;
V_642 -> V_1993 = V_1996 ;
}
V_642 -> V_396 = V_5 -> V_327 . V_396 ;
if ( F_23 ( V_5 , V_356 ) ) {
if ( V_5 -> V_327 . V_340 & V_335 ) {
if ( V_5 -> V_327 . V_340 & V_334 ) {
V_642 -> V_396 |= V_702 ;
} else {
V_642 -> V_396 |= V_702 |
V_1997 ;
}
} else if ( V_5 -> V_327 . V_340 & V_334 ) {
V_642 -> V_396 |= V_1997 ;
}
}
if ( F_143 ( V_111 ) && V_5 -> V_338 ) {
F_520 ( V_642 , V_5 -> V_327 . V_328 ) ;
V_642 -> V_374 = V_5 -> V_327 . V_331 ;
V_642 -> V_1998 = V_5 -> V_327 . V_367 ;
if ( ! ( V_5 -> V_178 & V_357 ) ) {
if ( V_5 -> V_178 & V_820 )
V_642 -> V_1999 = V_2000 ;
else
V_642 -> V_1999 = V_2001 ;
}
} else {
F_520 ( V_642 , V_751 ) ;
V_642 -> V_374 = V_752 ;
V_642 -> V_1999 = V_2002 ;
}
V_642 -> V_2003 = V_5 -> V_160 ;
V_642 -> V_2004 = V_2005 ;
V_642 -> V_350 = V_5 -> V_327 . V_350 ;
V_642 -> V_2006 = 0 ;
V_642 -> V_2007 = 0 ;
return 0 ;
}
static int F_521 ( struct V_362 * V_111 , struct V_1984 * V_642 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
T_1 V_370 = F_522 ( V_642 ) ;
if ( F_23 ( V_5 , V_263 ) ) {
struct V_209 * V_210 ;
if ( ! ( V_5 -> V_178 & V_389 ) )
return - V_85 ;
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
return F_523 ( V_210 , V_642 ) ;
}
if ( V_642 -> V_350 != V_355 &&
V_642 -> V_350 != V_776 )
return - V_64 ;
if ( V_642 -> V_350 == V_776 &&
V_642 -> V_374 != V_332 &&
V_642 -> V_374 != V_375 )
return - V_64 ;
if ( V_642 -> V_350 == V_355 ) {
T_1 V_2008 = V_703 |
V_702 |
V_1997 ;
if ( ! ( V_5 -> V_178 & V_390 ) )
V_2008 |= V_770 |
V_761 ;
if ( ! ( V_5 -> V_178 & V_357 ) )
V_2008 |= V_706 |
V_707 |
V_704 |
V_708 |
V_701 ;
else
V_2008 |= V_777 ;
if ( V_642 -> V_396 & ~ V_2008 )
return - V_64 ;
V_2008 &= ( V_770 |
V_761 |
V_706 |
V_707 |
V_704 |
V_708 ) ;
V_642 -> V_396 &= V_2008 ;
} else {
if ( V_5 -> V_178 & V_357 ) {
if ( V_370 != V_329 )
return - V_64 ;
if ( V_642 -> V_374 != V_332 )
return - V_64 ;
} else {
if ( V_370 != V_330 &&
V_370 != V_371 )
return - V_64 ;
}
}
F_238 ( V_5 , 0 ) ;
V_5 -> V_327 . V_350 = V_642 -> V_350 ;
if ( V_642 -> V_350 == V_355 ) {
V_5 -> V_327 . V_396 = ( V_642 -> V_396 |
V_703 ) ;
V_5 -> V_327 . V_370 = V_751 ;
V_5 -> V_327 . V_374 = V_752 ;
} else {
V_5 -> V_327 . V_396 = 0 ;
V_5 -> V_327 . V_370 = V_370 ;
V_5 -> V_327 . V_374 = V_642 -> V_374 ;
}
V_5 -> V_178 |= V_1533 ;
F_140 ( V_5 ) ;
if ( F_143 ( V_111 ) )
F_198 ( V_5 , true ) ;
F_239 ( V_5 ) ;
return 0 ;
}
static void F_524 ( struct V_362 * V_111 , struct V_2009 * V_985 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
F_525 ( V_985 -> V_2010 , V_2011 , sizeof( V_985 -> V_2010 ) ) ;
F_525 ( V_985 -> V_1973 , V_2012 , sizeof( V_985 -> V_1973 ) ) ;
F_525 ( V_985 -> V_2013 , V_5 -> V_2014 , sizeof( V_985 -> V_2013 ) ) ;
F_525 ( V_985 -> V_2015 , F_526 ( V_5 -> V_12 ) , sizeof( V_985 -> V_2015 ) ) ;
}
static void F_527 ( struct V_362 * V_111 , struct V_2016 * V_2017 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( F_23 ( V_5 , V_715 ) && F_528 ( & V_5 -> V_12 -> V_111 ) )
V_2017 -> V_391 = V_2018 ;
else
V_2017 -> V_391 = 0 ;
V_2017 -> V_2019 = 0 ;
if ( F_23 ( V_5 , V_112 ) && F_528 ( & V_5 -> V_12 -> V_111 ) )
V_2017 -> V_2019 = V_2018 ;
memset ( & V_2017 -> V_2020 , 0 , sizeof( V_2017 -> V_2020 ) ) ;
}
static int F_529 ( struct V_362 * V_111 , struct V_2016 * V_2017 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
struct V_543 * V_2021 = & V_5 -> V_12 -> V_111 ;
if ( V_2017 -> V_2019 & ~ V_2018 )
return - V_64 ;
if ( ( V_2017 -> V_2019 & V_2018 ) &&
! ( F_23 ( V_5 , V_715 ) && F_528 ( V_2021 ) ) )
return - V_64 ;
F_530 ( V_2021 , V_2017 -> V_2019 & V_2018 ) ;
F_69 ( & V_5 -> V_207 ) ;
if ( F_44 ( V_2021 ) )
F_82 ( V_5 , V_112 ) ;
else
F_84 ( V_5 , V_112 ) ;
F_70 ( & V_5 -> V_207 ) ;
return 0 ;
}
static T_1 F_531 ( struct V_362 * V_111 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
return V_5 -> V_2022 ;
}
static void F_532 ( struct V_362 * V_111 , T_1 V_2023 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
V_5 -> V_2022 = V_2023 ;
}
static int F_533 ( struct V_362 * V_111 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_2024 ;
if ( ! F_143 ( V_111 ) )
return - V_85 ;
if ( V_5 -> V_178 & V_567 )
return - V_64 ;
F_140 ( V_5 ) ;
if ( F_23 ( V_5 , V_263 ) ) {
if ( ! ( V_5 -> V_178 & V_389 ) )
return - V_85 ;
V_2024 = F_120 ( V_5 -> V_211 -> V_212 [ V_213 ] ) ;
} else {
T_1 V_771 ;
F_69 ( & V_5 -> V_207 ) ;
V_2024 = - V_64 ;
F_57 ( V_5 , V_202 , & V_771 ) ;
if ( ! F_57 ( V_5 , V_202 , & V_771 ) &&
( ( V_771 & V_576 ) ||
( V_5 -> V_178 & V_787 ) ) ) {
F_59 ( V_5 , V_202 , V_771 | V_577 |
V_576 ) ;
V_2024 = 0 ;
}
F_70 ( & V_5 -> V_207 ) ;
}
return V_2024 ;
}
static void F_534 ( struct V_362 * V_111 , struct V_2025 * V_2026 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
V_2026 -> V_2027 = V_5 -> V_1140 ;
if ( F_23 ( V_5 , V_1340 ) )
V_2026 -> V_2028 = V_5 -> V_1145 ;
else
V_2026 -> V_2028 = 0 ;
V_2026 -> V_2029 = V_1098 - 1 ;
V_2026 -> V_1338 = V_5 -> V_1338 ;
if ( F_23 ( V_5 , V_1340 ) )
V_2026 -> V_1342 = V_5 -> V_1342 ;
else
V_2026 -> V_1342 = 0 ;
V_2026 -> V_1090 = V_5 -> V_123 [ 0 ] . V_1090 ;
}
static int F_535 ( struct V_362 * V_111 , struct V_2025 * V_2026 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_42 , V_125 = 0 , V_75 = 0 ;
if ( ( V_2026 -> V_1338 > V_5 -> V_1140 ) ||
( V_2026 -> V_1342 > V_5 -> V_1145 ) ||
( V_2026 -> V_1090 > V_1098 - 1 ) ||
( V_2026 -> V_1090 <= V_1317 ) ||
( F_23 ( V_5 , V_1293 ) &&
( V_2026 -> V_1090 <= ( V_1317 * 3 ) ) ) )
return - V_64 ;
if ( F_143 ( V_111 ) ) {
F_121 ( V_5 ) ;
F_338 ( V_5 ) ;
V_125 = 1 ;
}
F_238 ( V_5 , V_125 ) ;
V_5 -> V_1338 = V_2026 -> V_1338 ;
if ( F_23 ( V_5 , V_2030 ) &&
V_5 -> V_1338 > 63 )
V_5 -> V_1338 = 63 ;
V_5 -> V_1342 = V_2026 -> V_1342 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1090 = V_2026 -> V_1090 ;
if ( F_143 ( V_111 ) ) {
F_427 ( V_5 , V_110 , 1 ) ;
V_75 = F_478 ( V_5 , false ) ;
if ( ! V_75 )
F_340 ( V_5 ) ;
}
F_239 ( V_5 ) ;
if ( V_125 && ! V_75 )
F_118 ( V_5 ) ;
return V_75 ;
}
static void F_536 ( struct V_362 * V_111 , struct V_2031 * V_2032 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
V_2032 -> V_350 = ! ! F_23 ( V_5 , V_356 ) ;
if ( V_5 -> V_327 . V_340 & V_335 )
V_2032 -> V_2033 = 1 ;
else
V_2032 -> V_2033 = 0 ;
if ( V_5 -> V_327 . V_340 & V_334 )
V_2032 -> V_2034 = 1 ;
else
V_2032 -> V_2034 = 0 ;
}
static int F_537 ( struct V_362 * V_111 , struct V_2031 * V_2032 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_75 = 0 ;
if ( V_5 -> V_327 . V_350 == V_355 )
F_140 ( V_5 ) ;
if ( F_23 ( V_5 , V_263 ) ) {
T_1 V_952 ;
struct V_209 * V_210 ;
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
if ( ! ( V_210 -> V_391 & V_393 ) ||
( ! ( V_210 -> V_391 & V_394 ) &&
( V_2032 -> V_2033 != V_2032 -> V_2034 ) ) )
return - V_64 ;
V_5 -> V_327 . V_340 = 0 ;
if ( V_2032 -> V_2033 ) {
V_5 -> V_327 . V_340 |= V_335 ;
if ( V_2032 -> V_2034 ) {
V_5 -> V_327 . V_340 |= V_334 ;
V_952 = V_702 ;
} else
V_952 = V_702 |
V_1997 ;
} else if ( V_2032 -> V_2034 ) {
V_5 -> V_327 . V_340 |= V_334 ;
V_952 = V_1997 ;
} else
V_952 = 0 ;
if ( V_2032 -> V_350 )
F_82 ( V_5 , V_356 ) ;
else
F_84 ( V_5 , V_356 ) ;
if ( V_5 -> V_178 & V_389 ) {
T_1 V_2035 = V_210 -> V_396 &
( V_702 | V_1997 ) ;
if ( V_2035 != V_952 ) {
V_210 -> V_396 &=
~ ( V_702 |
V_1997 ) ;
V_210 -> V_396 |= V_952 ;
if ( V_210 -> V_350 ) {
return F_120 ( V_210 ) ;
}
}
if ( ! V_2032 -> V_350 )
F_106 ( V_5 , 0 , 0 ) ;
} else {
V_5 -> V_327 . V_396 &=
~ ( V_702 |
V_1997 ) ;
V_5 -> V_327 . V_396 |= V_952 ;
}
} else {
int V_125 = 0 ;
if ( F_143 ( V_111 ) ) {
F_338 ( V_5 ) ;
V_125 = 1 ;
}
F_238 ( V_5 , V_125 ) ;
if ( V_2032 -> V_350 )
F_82 ( V_5 , V_356 ) ;
else
F_84 ( V_5 , V_356 ) ;
if ( V_2032 -> V_2033 )
V_5 -> V_327 . V_340 |= V_335 ;
else
V_5 -> V_327 . V_340 &= ~ V_335 ;
if ( V_2032 -> V_2034 )
V_5 -> V_327 . V_340 |= V_334 ;
else
V_5 -> V_327 . V_340 &= ~ V_334 ;
if ( F_143 ( V_111 ) ) {
F_427 ( V_5 , V_110 , 1 ) ;
V_75 = F_478 ( V_5 , false ) ;
if ( ! V_75 )
F_340 ( V_5 ) ;
}
F_239 ( V_5 ) ;
}
V_5 -> V_178 |= V_1533 ;
return V_75 ;
}
static int F_538 ( struct V_362 * V_111 , int V_2036 )
{
switch ( V_2036 ) {
case V_2037 :
return V_2038 ;
case V_2039 :
return V_2040 ;
default:
return - V_1039 ;
}
}
static int F_539 ( struct V_362 * V_111 , struct V_2041 * V_985 ,
T_1 * T_17 V_2042 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1063 ) )
return - V_1039 ;
switch ( V_985 -> V_642 ) {
case V_2043 :
if ( F_143 ( V_5 -> V_111 ) )
V_985 -> V_72 = V_5 -> V_1221 ;
else {
V_985 -> V_72 = F_540 () ;
if ( V_985 -> V_72 > V_2044 )
V_985 -> V_72 = V_2044 ;
}
V_985 -> V_72 -= 1 ;
return 0 ;
default:
return - V_1039 ;
}
}
static T_1 F_541 ( struct V_362 * V_111 )
{
T_1 V_634 = 0 ;
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( F_23 ( V_5 , V_1063 ) )
V_634 = V_1526 ;
return V_634 ;
}
static int F_542 ( struct V_362 * V_111 , T_1 * V_2045 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1526 ; V_42 ++ )
V_2045 [ V_42 ] = V_5 -> V_1527 [ V_42 ] ;
return 0 ;
}
static int F_543 ( struct V_362 * V_111 , const T_1 * V_2045 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
T_18 V_42 ;
for ( V_42 = 0 ; V_42 < V_1526 ; V_42 ++ )
V_5 -> V_1527 [ V_42 ] = V_2045 [ V_42 ] ;
if ( ! F_143 ( V_111 ) || ! F_23 ( V_5 , V_1210 ) )
return 0 ;
F_238 ( V_5 , 0 ) ;
F_451 ( V_5 ) ;
F_239 ( V_5 ) ;
return 0 ;
}
static void F_544 ( struct V_362 * V_111 ,
struct V_2046 * V_2047 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
T_1 V_2048 = F_495 () ;
V_2047 -> V_2049 = V_5 -> V_1897 ;
V_2047 -> V_2050 = V_5 -> V_1899 ;
if ( F_143 ( V_111 ) ) {
V_2047 -> V_2051 = V_5 -> V_1221 ;
V_2047 -> V_2052 = V_5 -> V_1348 ;
} else {
if ( V_5 -> V_1896 )
V_2047 -> V_2051 = V_5 -> V_1896 ;
else
V_2047 -> V_2051 = F_318 ( V_2048 , V_5 -> V_1897 ) ;
if ( V_5 -> V_1895 )
V_2047 -> V_2052 = V_5 -> V_1895 ;
else
V_2047 -> V_2052 = F_318 ( V_2048 , V_5 -> V_1899 ) ;
}
}
static int F_545 ( struct V_362 * V_111 ,
struct V_2046 * V_2047 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1063 ) )
return - V_1039 ;
if ( V_2047 -> V_2051 > V_5 -> V_1897 ||
V_2047 -> V_2052 > V_5 -> V_1899 )
return - V_64 ;
V_5 -> V_1896 = V_2047 -> V_2051 ;
V_5 -> V_1895 = V_2047 -> V_2052 ;
if ( ! F_143 ( V_111 ) )
return 0 ;
F_506 ( V_5 ) ;
F_138 ( V_5 ) ;
F_504 ( V_5 , true , false , false ) ;
return 0 ;
}
static void F_546 ( struct V_362 * V_111 , T_1 V_2053 , T_4 * V_626 )
{
switch ( V_2053 ) {
case V_2039 :
memcpy ( V_626 , & V_2054 , sizeof( V_2054 ) ) ;
break;
case V_2037 :
memcpy ( V_626 , & V_2055 , sizeof( V_2055 ) ) ;
break;
default:
F_547 ( 1 ) ;
break;
}
}
static int F_548 ( struct V_362 * V_111 ,
enum V_2056 V_846 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( ! F_143 ( V_5 -> V_111 ) )
return - V_85 ;
switch ( V_846 ) {
case V_2057 :
return 1 ;
case V_2058 :
F_46 ( V_725 , V_836 |
V_834 |
V_835 |
V_2059 |
V_940 |
V_2060 |
V_2061 ) ;
break;
case V_2062 :
F_46 ( V_725 , V_836 |
V_940 ) ;
break;
case V_2063 :
F_46 ( V_725 , V_5 -> V_563 ) ;
break;
}
return 0 ;
}
static void F_549 ( struct V_362 * V_111 ,
struct V_2064 * V_1912 , T_6 * V_2065 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( V_5 -> V_1351 )
F_429 ( V_5 , (struct V_1911 * ) V_2065 ) ;
else
memset ( V_2065 , 0 , sizeof( struct V_1911 ) ) ;
}
static T_5 * F_550 ( struct V_4 * V_5 , T_1 * V_2066 )
{
int V_42 ;
T_5 * V_626 ;
T_1 V_595 = 0 , V_74 = 0 ;
T_1 V_1980 , V_7 ;
if ( F_23 ( V_5 , V_681 ) || F_166 ( V_5 , 0 , & V_1980 ) )
return NULL ;
if ( V_1980 == V_1981 ) {
for ( V_595 = V_2067 ;
V_595 < V_2068 ;
V_595 += V_2069 ) {
if ( F_166 ( V_5 , V_595 , & V_7 ) )
return NULL ;
if ( ( V_7 >> V_2070 ) ==
V_2071 )
break;
}
if ( V_595 != V_2068 ) {
V_74 = ( V_7 & V_2072 ) * 4 ;
if ( F_166 ( V_5 , V_595 + 4 , & V_595 ) )
return NULL ;
V_595 = F_165 ( V_5 , V_595 ) ;
}
}
if ( ! V_595 || ! V_74 ) {
V_595 = V_2073 ;
V_74 = V_2074 ;
}
V_626 = F_172 ( V_74 , V_632 ) ;
if ( V_626 == NULL )
return NULL ;
if ( V_1980 == V_1981 ) {
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 ) {
if ( F_167 ( V_5 , V_595 + V_42 , & V_626 [ V_42 / 4 ] ) )
goto error;
}
} else {
T_4 * V_2075 ;
T_14 V_2076 ;
unsigned int V_2077 = 0 ;
V_2075 = ( T_4 * ) & V_626 [ 0 ] ;
for ( V_42 = 0 ; V_2077 < V_74 && V_42 < 3 ; V_42 ++ , V_2077 += V_2076 , V_2075 += V_2076 ) {
V_2076 = F_551 ( V_5 -> V_12 , V_2077 ,
V_74 - V_2077 , V_2075 ) ;
if ( V_2076 == - V_2078 || V_2076 == - V_2079 )
V_2076 = 0 ;
else if ( V_2076 < 0 )
goto error;
}
if ( V_2077 != V_74 )
goto error;
}
* V_2066 = V_74 ;
return V_626 ;
error:
F_173 ( V_626 ) ;
return NULL ;
}
static int F_552 ( struct V_4 * V_5 )
{
T_1 V_2080 , V_1980 , V_74 ;
T_5 * V_626 ;
int V_42 , V_627 , V_1508 , V_75 = 0 , V_634 ;
if ( F_23 ( V_5 , V_681 ) )
return 0 ;
if ( F_166 ( V_5 , 0 , & V_1980 ) != 0 )
return - V_208 ;
if ( V_1980 == V_1981 )
V_634 = V_2081 ;
else if ( ( V_1980 & V_2082 ) == V_2083 ) {
if ( ( V_1980 & V_2084 ) ==
V_2085 ) {
switch ( V_1980 & V_2086 ) {
case V_2087 :
V_634 = V_2088 ;
break;
case V_2089 :
V_634 = V_2090 ;
break;
case V_2091 :
V_634 = V_2092 ;
break;
case V_2093 :
V_634 = V_2094 ;
break;
case V_2095 :
V_634 = V_2096 ;
break;
case V_2097 :
V_634 = V_2098 ;
break;
default:
return - V_208 ;
}
} else
return 0 ;
} else if ( ( V_1980 & V_2099 ) == V_2100 )
V_634 = V_2101 ;
else
return - V_208 ;
V_626 = F_172 ( V_634 , V_632 ) ;
if ( V_626 == NULL )
return - V_264 ;
V_75 = - V_208 ;
for ( V_42 = 0 , V_627 = 0 ; V_42 < V_634 ; V_42 += 4 , V_627 ++ ) {
V_75 = F_167 ( V_5 , V_42 , & V_626 [ V_627 ] ) ;
if ( V_75 )
break;
}
if ( V_42 < V_634 )
goto V_502;
V_1980 = F_170 ( V_626 [ 0 ] ) ;
if ( ( V_1980 & V_2082 ) ==
V_2083 ) {
T_4 * V_2102 = ( T_4 * ) V_626 , V_2103 = 0 ;
if ( ( V_1980 & V_2086 ) ==
V_2089 ) {
for ( V_42 = 0 ; V_42 < V_2104 ; V_42 ++ )
V_2103 += V_2102 [ V_42 ] ;
for ( V_42 = V_2104 + 4 ; V_42 < V_634 ; V_42 ++ )
V_2103 += V_2102 [ V_42 ] ;
} else {
for ( V_42 = 0 ; V_42 < V_634 ; V_42 ++ )
V_2103 += V_2102 [ V_42 ] ;
}
if ( V_2103 == 0 ) {
V_75 = 0 ;
goto V_502;
}
V_75 = - V_208 ;
goto V_502;
}
if ( ( V_1980 & V_2099 ) ==
V_2100 ) {
T_4 V_72 [ V_2105 ] ;
T_4 V_2106 [ V_2105 ] ;
T_4 * V_2102 = ( T_4 * ) V_626 ;
for ( V_42 = 0 , V_627 = 0 , V_1508 = 0 ; V_42 < V_2101 ; V_42 ++ ) {
if ( ( V_42 == 0 ) || ( V_42 == 8 ) ) {
int V_2107 ;
T_4 V_2108 ;
for ( V_2107 = 0 , V_2108 = 0x80 ; V_2107 < 7 ; V_2107 ++ , V_2108 >>= 1 )
V_2106 [ V_1508 ++ ] = V_2102 [ V_42 ] & V_2108 ;
V_42 ++ ;
} else if ( V_42 == 16 ) {
int V_2107 ;
T_4 V_2108 ;
for ( V_2107 = 0 , V_2108 = 0x20 ; V_2107 < 6 ; V_2107 ++ , V_2108 >>= 1 )
V_2106 [ V_1508 ++ ] = V_2102 [ V_42 ] & V_2108 ;
V_42 ++ ;
for ( V_2107 = 0 , V_2108 = 0x80 ; V_2107 < 8 ; V_2107 ++ , V_2108 >>= 1 )
V_2106 [ V_1508 ++ ] = V_2102 [ V_42 ] & V_2108 ;
V_42 ++ ;
}
V_72 [ V_627 ++ ] = V_2102 [ V_42 ] ;
}
V_75 = - V_208 ;
for ( V_42 = 0 ; V_42 < V_2105 ; V_42 ++ ) {
T_4 V_2109 = F_553 ( V_72 [ V_42 ] ) ;
if ( ( V_2109 & 0x1 ) && V_2106 [ V_42 ] )
goto V_502;
else if ( ! ( V_2109 & 0x1 ) && ! V_2106 [ V_42 ] )
goto V_502;
}
V_75 = 0 ;
goto V_502;
}
V_75 = - V_208 ;
V_2080 = F_443 ( ( unsigned char * ) V_626 , 0x10 ) ;
if ( V_2080 != F_554 ( V_626 [ 0x10 / 4 ] ) )
goto V_502;
V_2080 = F_443 ( ( unsigned char * ) & V_626 [ 0x74 / 4 ] , 0x88 ) ;
if ( V_2080 != F_554 ( V_626 [ 0xfc / 4 ] ) )
goto V_502;
F_173 ( V_626 ) ;
V_626 = F_550 ( V_5 , & V_74 ) ;
if ( ! V_626 )
return - V_264 ;
V_42 = F_555 ( ( T_4 * ) V_626 , 0 , V_74 , V_2110 ) ;
if ( V_42 > 0 ) {
V_627 = F_556 ( & ( ( T_4 * ) V_626 ) [ V_42 ] ) ;
if ( V_627 < 0 )
goto V_502;
if ( V_42 + V_2111 + V_627 > V_74 )
goto V_502;
V_42 += V_2111 ;
V_627 = F_557 ( ( T_4 * ) V_626 , V_42 , V_627 ,
V_2112 ) ;
if ( V_627 > 0 ) {
T_4 V_2103 = 0 ;
V_627 += V_2113 ;
for ( V_42 = 0 ; V_42 <= V_627 ; V_42 ++ )
V_2103 += ( ( T_4 * ) V_626 ) [ V_42 ] ;
if ( V_2103 )
goto V_502;
}
}
V_75 = 0 ;
V_502:
F_173 ( V_626 ) ;
return V_75 ;
}
static int F_558 ( struct V_4 * V_5 )
{
int V_42 , F_492 ;
if ( ! F_143 ( V_5 -> V_111 ) )
return - V_82 ;
if ( V_5 -> V_178 & V_357 )
F_492 = V_2114 ;
else
F_492 = V_2115 ;
for ( V_42 = 0 ; V_42 < F_492 ; V_42 ++ ) {
if ( V_5 -> V_338 )
return 0 ;
if ( F_559 ( 1000 ) )
break;
}
return - V_208 ;
}
static int F_560 ( struct V_4 * V_5 )
{
int V_42 , V_2116 , V_2117 ;
T_1 V_595 , V_2118 , V_2119 , V_7 , V_2120 , V_2121 ;
static struct {
T_3 V_595 ;
T_3 V_10 ;
#define F_561 0x1
#define F_562 0x2
#define F_563 0x4
#define F_564 0x8
T_1 V_2118 ;
T_1 V_2119 ;
} V_2122 [] = {
{ V_380 , F_562 ,
0x00000000 , 0x00ef6f8c } ,
{ V_380 , F_561 ,
0x00000000 , 0x01ef6b8c } ,
{ V_789 , F_562 ,
0x03800107 , 0x00000000 } ,
{ V_789 , F_561 ,
0x03800100 , 0x00000000 } ,
{ V_689 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_690 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1622 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_361 , 0x0000 ,
0x00000000 , 0x00000070 } ,
{ V_384 , 0x0000 ,
0x00000000 , 0x00003fff } ,
{ V_359 , F_562 ,
0x00000000 , 0x000007fc } ,
{ V_359 , F_561 ,
0x00000000 , 0x000007dc } ,
{ V_1510 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1511 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1512 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1513 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1056 + 0 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1056 + 4 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1056 + 8 , F_562 ,
0x00000000 , 0x00000003 } ,
{ V_1056 + 0xc , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1616 + 0 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1616 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1616 + 8 , 0x0000 ,
0x00000000 , 0xffff0002 } ,
{ V_1616 + 0xc , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1503 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1503 , F_561 ,
0x00000000 , 0x000003ff } ,
{ V_1506 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_138 , F_562 ,
0x00000000 , 0x00000004 } ,
{ V_138 , F_561 ,
0x00000000 , 0x000000f6 } ,
{ V_1468 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1468 , F_561 ,
0x00000000 , 0x000003ff } ,
{ V_1459 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1459 , F_561 ,
0x00000000 , 0x000003ff } ,
{ V_1470 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1470 , F_561 | F_563 ,
0x00000000 , 0x000000ff } ,
{ V_1461 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1461 , F_561 | F_563 ,
0x00000000 , 0x000000ff } ,
{ V_1476 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1478 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1472 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1472 , F_561 | F_563 ,
0x00000000 , 0x000000ff } ,
{ V_1463 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1463 , F_561 | F_563 ,
0x00000000 , 0x000000ff } ,
{ V_969 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1671 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1671 + 4 , F_562 ,
0x00000000 , 0xffffffff } ,
{ V_1493 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1493 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1672 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1673 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1584 , F_564 ,
0x00000000 , 0x007fff80 } ,
{ V_1586 , F_564 ,
0x00000000 , 0x007fffff } ,
{ V_1595 , 0x0000 ,
0x00000000 , 0x0000003f } ,
{ V_1598 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1600 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1589 , F_562 ,
0xffffffff , 0x00000000 } ,
{ V_1591 , F_562 ,
0xffffffff , 0x00000000 } ,
{ V_2123 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_2124 + 4 , F_562 ,
0x00000000 , 0x000001ff } ,
{ V_2125 + 4 , 0x0000 ,
0x00000000 , 0x000007ff } ,
{ V_2126 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ 0xffff , 0x0000 , 0x00000000 , 0x00000000 } ,
} ;
V_2116 = V_2117 = 0 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_2116 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2117 = 1 ;
}
for ( V_42 = 0 ; V_2122 [ V_42 ] . V_595 != 0xffff ; V_42 ++ ) {
if ( V_2116 && ( V_2122 [ V_42 ] . V_10 & F_562 ) )
continue;
if ( ! V_2116 && ( V_2122 [ V_42 ] . V_10 & F_561 ) )
continue;
if ( F_23 ( V_5 , V_1641 ) &&
( V_2122 [ V_42 ] . V_10 & F_563 ) )
continue;
if ( V_2117 && ( V_2122 [ V_42 ] . V_10 & F_564 ) )
continue;
V_595 = ( T_1 ) V_2122 [ V_42 ] . V_595 ;
V_2118 = V_2122 [ V_42 ] . V_2118 ;
V_2119 = V_2122 [ V_42 ] . V_2119 ;
V_2120 = F_33 ( V_595 ) ;
V_2121 = V_2120 & V_2118 ;
F_46 ( V_595 , 0 ) ;
V_7 = F_33 ( V_595 ) ;
if ( ( ( V_7 & V_2118 ) != V_2121 ) || ( V_7 & V_2119 ) )
goto V_502;
F_46 ( V_595 , V_2118 | V_2119 ) ;
V_7 = F_33 ( V_595 ) ;
if ( ( V_7 & V_2118 ) != V_2121 )
goto V_502;
if ( ( V_7 & V_2119 ) != V_2119 )
goto V_502;
F_46 ( V_595 , V_2120 ) ;
}
return 0 ;
V_502:
if ( F_565 ( V_5 ) )
F_183 ( V_5 -> V_111 ,
L_71 , V_595 ) ;
F_46 ( V_595 , V_2120 ) ;
return - V_208 ;
}
static int F_566 ( struct V_4 * V_5 , T_1 V_595 , T_1 V_74 )
{
static const T_1 V_2127 [] = { 0x00000000 , 0xffffffff , 0xaa55a55a } ;
int V_42 ;
T_1 V_627 ;
for ( V_42 = 0 ; V_42 < F_567 ( V_2127 ) ; V_42 ++ ) {
for ( V_627 = 0 ; V_627 < V_74 ; V_627 += 4 ) {
T_1 V_7 ;
F_29 ( V_5 , V_595 + V_627 , V_2127 [ V_42 ] ) ;
F_32 ( V_5 , V_595 + V_627 , & V_7 ) ;
if ( V_7 != V_2127 [ V_42 ] )
return - V_208 ;
}
}
return 0 ;
}
static int F_568 ( struct V_4 * V_5 )
{
static struct V_2128 {
T_1 V_595 ;
T_1 V_74 ;
} V_2129 [] = {
{ 0x00000000 , 0x00b50 } ,
{ 0x00002000 , 0x1c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2130 [] = {
{ 0x00000100 , 0x0000c } ,
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x01000 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0e000 } ,
{ 0xffffffff , 0x00000 }
} , V_2131 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x00800 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2132 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00400 } ,
{ 0x00006000 , 0x00400 } ,
{ 0x00008000 , 0x01000 } ,
{ 0x00010000 , 0x01000 } ,
{ 0xffffffff , 0x00000 }
} , V_2133 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0x00020000 , 0x13c00 } ,
{ 0xffffffff , 0x00000 }
} , V_2134 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x09800 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0xffffffff , 0x00000 }
} ;
struct V_2128 * V_2135 ;
int V_75 = 0 ;
int V_42 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_2135 = V_2133 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_765 )
V_2135 = V_2134 ;
else if ( F_23 ( V_5 , 5755_PLUS ) )
V_2135 = V_2131 ;
else if ( F_30 ( V_5 ) == V_36 )
V_2135 = V_2132 ;
else if ( F_23 ( V_5 , 5705_PLUS ) )
V_2135 = V_2130 ;
else
V_2135 = V_2129 ;
for ( V_42 = 0 ; V_2135 [ V_42 ] . V_595 != 0xffffffff ; V_42 ++ ) {
V_75 = F_566 ( V_5 , V_2135 [ V_42 ] . V_595 , V_2135 [ V_42 ] . V_74 ) ;
if ( V_75 )
break;
}
return V_75 ;
}
static int F_569 ( struct V_4 * V_5 , T_1 V_2136 , bool V_2137 )
{
T_1 V_2138 , V_2139 , V_2140 , V_1131 ;
T_1 V_1268 = 0 , V_1246 = 0 , V_1167 , V_126 , V_2141 , V_7 ;
T_1 V_1159 ;
struct V_1109 * V_1110 ;
T_4 * V_2142 , * V_2143 ;
T_9 V_1136 ;
int V_2144 , V_2145 , V_2146 , V_42 , V_75 ;
struct V_1134 * V_1135 ;
struct V_130 * V_131 , * V_2147 ;
struct V_1129 * V_1130 = & V_5 -> V_123 [ 0 ] . V_1091 ;
V_131 = & V_5 -> V_123 [ 0 ] ;
V_2147 = & V_5 -> V_123 [ 0 ] ;
if ( V_5 -> V_129 > 1 ) {
if ( F_23 ( V_5 , V_1210 ) )
V_2147 = & V_5 -> V_123 [ 1 ] ;
if ( F_23 ( V_5 , V_1105 ) )
V_131 = & V_5 -> V_123 [ 1 ] ;
}
V_126 = V_131 -> V_126 | V_2147 -> V_126 ;
V_75 = - V_208 ;
V_2145 = V_2136 ;
V_1110 = F_301 ( V_5 -> V_111 , V_2145 ) ;
if ( ! V_1110 )
return - V_264 ;
V_2142 = F_304 ( V_1110 , V_2145 ) ;
memcpy ( V_2142 , V_5 -> V_111 -> V_688 , 6 ) ;
memset ( V_2142 + 6 , 0x0 , 8 ) ;
F_46 ( V_1622 , V_2145 + V_1184 ) ;
if ( V_2137 ) {
struct V_1286 * V_1287 = (struct V_1286 * ) & V_2142 [ V_1202 ] ;
T_1 V_1289 = V_2148 + V_2149 +
V_2150 ;
memcpy ( V_2142 + V_1524 * 2 , V_2151 ,
sizeof( V_2151 ) ) ;
V_1246 = V_2152 ;
V_7 = V_2145 - V_1524 * 2 - sizeof( V_2151 ) ;
V_2144 = F_570 ( V_7 , V_2152 ) ;
V_1287 -> V_1292 = F_308 ( ( T_3 ) ( V_1246 + V_1289 ) ) ;
V_1268 = ( V_1294 |
V_1295 ) ;
if ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ) {
struct V_2153 * V_2154 ;
V_7 = V_1202 + V_2148 ;
V_2154 = (struct V_2153 * ) & V_2142 [ V_7 ] ;
V_2154 -> V_1291 = 0 ;
} else
V_1268 |= V_1284 ;
if ( F_23 ( V_5 , V_1298 ) ) {
V_1246 |= ( V_1289 & 0xc ) << 12 ;
if ( V_1289 & 0x10 )
V_1268 |= 0x00000010 ;
V_1268 |= ( V_1289 & 0x3e0 ) << 5 ;
} else if ( F_23 ( V_5 , V_1297 ) )
V_1246 |= V_1289 << 9 ;
else if ( F_23 ( V_5 , V_1296 ) ||
F_30 ( V_5 ) == V_501 ) {
V_1246 |= ( V_2150 << 9 ) ;
} else {
V_1268 |= ( V_2150 << 10 ) ;
}
V_2141 = V_1524 * 2 + sizeof( V_2151 ) ;
} else {
V_2144 = 1 ;
V_2141 = V_1202 ;
if ( F_23 ( V_5 , V_1304 ) &&
V_2145 > V_1305 )
V_1268 |= V_1306 ;
}
for ( V_42 = V_2141 ; V_42 < V_2145 ; V_42 ++ )
V_2142 [ V_42 ] = ( T_4 ) ( V_42 & 0xff ) ;
V_1136 = F_290 ( V_5 -> V_12 , V_1110 -> V_72 , V_2145 , V_1118 ) ;
if ( F_291 ( V_5 -> V_12 , V_1136 ) ) {
F_273 ( V_1110 ) ;
return - V_208 ;
}
V_7 = V_131 -> V_1089 ;
V_131 -> V_1108 [ V_7 ] . V_1110 = V_1110 ;
F_292 ( & V_131 -> V_1108 [ V_7 ] , V_1117 , V_1136 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_2147 -> V_126 ) ;
F_24 ( 10 ) ;
V_2138 = V_2147 -> V_134 -> V_145 [ 0 ] . V_1087 ;
V_1159 = F_260 ( V_131 ) ;
if ( F_359 ( V_131 , & V_7 , & V_1159 , V_1136 , V_2145 ,
V_1268 | V_1262 , V_1246 , 0 ) ) {
V_131 -> V_1108 [ V_7 ] . V_1110 = NULL ;
F_273 ( V_1110 ) ;
return - V_208 ;
}
V_131 -> V_1089 ++ ;
F_49 () ;
F_388 ( V_131 -> V_1316 , V_131 -> V_1089 ) ;
F_485 ( V_131 -> V_1316 ) ;
F_24 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 35 ; V_42 ++ ) {
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_126 ) ;
F_24 ( 10 ) ;
V_2140 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
V_2139 = V_2147 -> V_134 -> V_145 [ 0 ] . V_1087 ;
if ( ( V_2140 == V_131 -> V_1089 ) &&
( V_2139 == ( V_2138 + V_2144 ) ) )
break;
}
F_360 ( V_131 , V_131 -> V_1089 - 1 , - 1 ) ;
F_273 ( V_1110 ) ;
if ( V_2140 != V_131 -> V_1089 )
goto V_502;
if ( V_2139 != V_2138 + V_2144 )
goto V_502;
V_7 = V_2141 ;
while ( V_2139 != V_2138 ) {
V_1135 = & V_2147 -> V_1165 [ V_2138 ++ ] ;
V_1167 = V_1135 -> V_1170 & V_1171 ;
V_1131 = V_1135 -> V_1170 & V_1172 ;
if ( ( V_1135 -> V_1174 & V_1175 ) != 0 &&
( V_1135 -> V_1174 != V_1176 ) )
goto V_502;
V_2146 = ( ( V_1135 -> V_1181 & V_1182 ) >> V_1183 )
- V_1184 ;
if ( ! V_2137 ) {
if ( V_2146 != V_2145 )
goto V_502;
if ( V_2136 <= V_1332 - V_1184 ) {
if ( V_1131 != V_1139 )
goto V_502;
} else {
if ( V_1131 != V_1144 )
goto V_502;
}
} else if ( ( V_1135 -> V_1185 & V_1194 ) &&
( V_1135 -> V_1195 & V_1196 )
>> V_1197 != 0xffff ) {
goto V_502;
}
if ( V_1131 == V_1139 ) {
V_2143 = V_1130 -> V_1142 [ V_1167 ] . V_72 ;
V_1136 = F_267 ( & V_1130 -> V_1142 [ V_1167 ] ,
V_1117 ) ;
} else if ( V_1131 == V_1144 ) {
V_2143 = V_1130 -> V_1148 [ V_1167 ] . V_72 ;
V_1136 = F_267 ( & V_1130 -> V_1148 [ V_1167 ] ,
V_1117 ) ;
} else
goto V_502;
F_302 ( V_5 -> V_12 , V_1136 , V_2146 ,
V_1127 ) ;
V_2143 += F_287 ( V_5 ) ;
for ( V_42 = V_2141 ; V_42 < V_2146 ; V_42 ++ , V_7 ++ ) {
if ( * ( V_2143 + V_42 ) != ( T_4 ) ( V_7 & 0xff ) )
goto V_502;
}
}
V_75 = 0 ;
V_502:
return V_75 ;
}
static int F_571 ( struct V_4 * V_5 , T_6 * V_72 , bool V_2155 )
{
int V_75 = - V_208 ;
T_1 V_2156 ;
T_1 V_2157 = 9000 ;
if ( V_5 -> V_1259 )
V_2157 = V_5 -> V_1259 - V_1202 ;
V_2156 = V_5 -> V_178 & V_336 ;
V_5 -> V_178 &= ~ V_336 ;
if ( ! F_143 ( V_5 -> V_111 ) ) {
V_72 [ V_2158 ] = V_2159 ;
V_72 [ V_2160 ] = V_2159 ;
if ( V_2155 )
V_72 [ V_2161 ] = V_2159 ;
goto V_186;
}
V_75 = F_453 ( V_5 , true ) ;
if ( V_75 ) {
V_72 [ V_2158 ] = V_2159 ;
V_72 [ V_2160 ] = V_2159 ;
if ( V_2155 )
V_72 [ V_2161 ] = V_2159 ;
goto V_186;
}
if ( F_23 ( V_5 , V_1210 ) ) {
int V_42 ;
for ( V_42 = V_1528 ;
V_42 < V_1528 + V_1526 ; V_42 += 4 )
F_46 ( V_42 , 0x0 ) ;
}
if ( F_30 ( V_5 ) != V_566 &&
! F_23 ( V_5 , V_152 ) ) {
F_389 ( V_5 , true ) ;
if ( F_569 ( V_5 , V_2162 , false ) )
V_72 [ V_2158 ] |= V_2163 ;
if ( F_23 ( V_5 , V_1340 ) &&
F_569 ( V_5 , V_2157 + V_1202 , false ) )
V_72 [ V_2158 ] |= V_2164 ;
F_389 ( V_5 , false ) ;
}
if ( ! ( V_5 -> V_178 & V_567 ) &&
! F_23 ( V_5 , V_263 ) ) {
int V_42 ;
F_390 ( V_5 , 0 , false ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
if ( F_33 ( V_950 ) & V_951 )
break;
F_97 ( 1 ) ;
}
if ( F_569 ( V_5 , V_2162 , false ) )
V_72 [ V_2160 ] |= V_2163 ;
if ( F_23 ( V_5 , V_1593 ) &&
F_569 ( V_5 , V_2162 , true ) )
V_72 [ V_2160 ] |= V_2165 ;
if ( F_23 ( V_5 , V_1340 ) &&
F_569 ( V_5 , V_2157 + V_1202 , false ) )
V_72 [ V_2160 ] |= V_2164 ;
if ( V_2155 ) {
F_390 ( V_5 , 0 , true ) ;
F_97 ( 40 ) ;
if ( F_569 ( V_5 , V_2162 , false ) )
V_72 [ V_2161 ] |=
V_2163 ;
if ( F_23 ( V_5 , V_1593 ) &&
F_569 ( V_5 , V_2162 , true ) )
V_72 [ V_2161 ] |=
V_2165 ;
if ( F_23 ( V_5 , V_1340 ) &&
F_569 ( V_5 , V_2157 + V_1202 , false ) )
V_72 [ V_2161 ] |=
V_2164 ;
}
if ( V_5 -> V_178 & V_513 )
F_126 ( V_5 , true ) ;
}
V_75 = ( V_72 [ V_2158 ] | V_72 [ V_2160 ] |
V_72 [ V_2161 ] ) ? - V_208 : 0 ;
V_186:
V_5 -> V_178 |= V_2156 ;
return V_75 ;
}
static void F_572 ( struct V_362 * V_111 , struct V_2166 * V_2167 ,
T_6 * V_72 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
bool V_2168 = V_2167 -> V_10 & V_2169 ;
if ( V_5 -> V_178 & V_397 ) {
if ( F_194 ( V_5 ) ) {
V_2167 -> V_10 |= V_2170 ;
memset ( V_72 , 1 , sizeof( T_6 ) * V_2038 ) ;
return;
}
F_42 ( V_5 , V_96 ) ;
}
memset ( V_72 , 0 , sizeof( T_6 ) * V_2038 ) ;
if ( F_552 ( V_5 ) != 0 ) {
V_2167 -> V_10 |= V_2170 ;
V_72 [ V_2171 ] = 1 ;
}
if ( ! V_2168 && F_558 ( V_5 ) ) {
V_2167 -> V_10 |= V_2170 ;
V_72 [ V_2172 ] = 1 ;
}
if ( V_2167 -> V_10 & V_2173 ) {
int V_75 , V_759 = 0 , V_125 = 0 ;
if ( F_143 ( V_111 ) ) {
F_121 ( V_5 ) ;
F_338 ( V_5 ) ;
V_125 = 1 ;
}
F_238 ( V_5 , V_125 ) ;
F_427 ( V_5 , V_317 , 1 ) ;
V_75 = F_156 ( V_5 ) ;
F_181 ( V_5 , V_653 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_181 ( V_5 , V_654 ) ;
if ( ! V_75 )
F_157 ( V_5 ) ;
if ( V_5 -> V_178 & V_302 )
F_142 ( V_5 ) ;
if ( F_560 ( V_5 ) != 0 ) {
V_2167 -> V_10 |= V_2170 ;
V_72 [ V_2174 ] = 1 ;
}
if ( F_568 ( V_5 ) != 0 ) {
V_2167 -> V_10 |= V_2170 ;
V_72 [ V_2175 ] = 1 ;
}
if ( V_2168 )
V_2167 -> V_10 |= V_2176 ;
if ( F_571 ( V_5 , V_72 , V_2168 ) )
V_2167 -> V_10 |= V_2170 ;
F_239 ( V_5 ) ;
if ( F_483 ( V_5 ) != 0 ) {
V_2167 -> V_10 |= V_2170 ;
V_72 [ V_2177 ] = 1 ;
}
F_238 ( V_5 , 0 ) ;
F_427 ( V_5 , V_110 , 1 ) ;
if ( F_143 ( V_111 ) ) {
F_82 ( V_5 , V_562 ) ;
V_759 = F_478 ( V_5 , true ) ;
if ( ! V_759 )
F_340 ( V_5 ) ;
}
F_239 ( V_5 ) ;
if ( V_125 && ! V_759 )
F_118 ( V_5 ) ;
}
if ( V_5 -> V_178 & V_397 )
F_196 ( V_5 ) ;
}
static int F_573 ( struct V_362 * V_111 ,
struct V_2178 * V_2179 , int V_642 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
struct V_2180 V_2181 ;
if ( ! F_23 ( V_5 , V_990 ) )
return - V_64 ;
if ( F_574 ( & V_2181 , V_2179 -> V_2182 , sizeof( V_2181 ) ) )
return - V_2183 ;
if ( V_2181 . V_10 )
return - V_64 ;
switch ( V_2181 . V_2184 ) {
case V_998 :
F_82 ( V_5 , V_1310 ) ;
break;
case V_997 :
F_84 ( V_5 , V_1310 ) ;
break;
default:
return - V_2185 ;
}
switch ( V_2181 . V_2186 ) {
case V_1000 :
V_5 -> V_1580 = 0 ;
break;
case V_1001 :
V_5 -> V_1580 = V_2187 |
V_2188 ;
break;
case V_2189 :
V_5 -> V_1580 = V_2187 |
V_2190 ;
break;
case V_2191 :
V_5 -> V_1580 = V_2187 |
V_2192 ;
break;
case V_2193 :
V_5 -> V_1580 = V_2194 |
V_2195 ;
break;
case V_1002 :
V_5 -> V_1580 = V_2196 |
V_2195 ;
break;
case V_1003 :
V_5 -> V_1580 = V_2197 |
V_2195 ;
break;
case V_2198 :
V_5 -> V_1580 = V_2194 |
V_2190 ;
break;
case V_2199 :
V_5 -> V_1580 = V_2196 |
V_2190 ;
break;
case V_2200 :
V_5 -> V_1580 = V_2197 |
V_2190 ;
break;
case V_2201 :
V_5 -> V_1580 = V_2194 |
V_2192 ;
break;
case V_2202 :
V_5 -> V_1580 = V_2196 |
V_2192 ;
break;
case V_2203 :
V_5 -> V_1580 = V_2197 |
V_2192 ;
break;
default:
return - V_2185 ;
}
if ( F_143 ( V_111 ) && V_5 -> V_1580 )
F_46 ( V_1581 ,
V_5 -> V_1580 | V_1582 ) ;
return F_575 ( V_2179 -> V_2182 , & V_2181 , sizeof( V_2181 ) ) ?
- V_2183 : 0 ;
}
static int F_576 ( struct V_362 * V_111 , struct V_2178 * V_2179 , int V_642 )
{
struct V_2204 * V_72 = F_577 ( V_2179 ) ;
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_75 ;
if ( F_23 ( V_5 , V_263 ) ) {
struct V_209 * V_210 ;
if ( ! ( V_5 -> V_178 & V_389 ) )
return - V_85 ;
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
return F_578 ( V_210 , V_2179 , V_642 ) ;
}
switch ( V_642 ) {
case V_2205 :
V_72 -> V_215 = V_5 -> V_160 ;
case V_2206 : {
T_1 V_2207 ;
if ( V_5 -> V_178 & V_567 )
break;
if ( ! F_143 ( V_111 ) )
return - V_85 ;
F_69 ( & V_5 -> V_207 ) ;
V_75 = F_56 ( V_5 , V_72 -> V_215 & 0x1f ,
V_72 -> V_2208 & 0x1f , & V_2207 ) ;
F_70 ( & V_5 -> V_207 ) ;
V_72 -> V_2209 = V_2207 ;
return V_75 ;
}
case V_2210 :
if ( V_5 -> V_178 & V_567 )
break;
if ( ! F_143 ( V_111 ) )
return - V_85 ;
F_69 ( & V_5 -> V_207 ) ;
V_75 = F_58 ( V_5 , V_72 -> V_215 & 0x1f ,
V_72 -> V_2208 & 0x1f , V_72 -> V_2211 ) ;
F_70 ( & V_5 -> V_207 ) ;
return V_75 ;
case V_2212 :
return F_573 ( V_111 , V_2179 , V_642 ) ;
default:
break;
}
return - V_1039 ;
}
static int F_579 ( struct V_362 * V_111 , struct V_1457 * V_1458 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
memcpy ( V_1458 , & V_5 -> V_970 , sizeof( * V_1458 ) ) ;
return 0 ;
}
static int F_580 ( struct V_362 * V_111 , struct V_1457 * V_1458 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
T_1 V_2213 = 0 , V_2214 = 0 ;
T_1 V_2215 = 0 , V_2216 = 0 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
V_2213 = V_2217 ;
V_2214 = V_2218 ;
V_2215 = V_2219 ;
V_2216 = V_2220 ;
}
if ( ( V_1458 -> V_1469 > V_2221 ) ||
( V_1458 -> V_1460 > V_2222 ) ||
( V_1458 -> V_1471 > V_2223 ) ||
( V_1458 -> V_1462 > V_2224 ) ||
( V_1458 -> V_1477 > V_2213 ) ||
( V_1458 -> V_1479 > V_2214 ) ||
( V_1458 -> V_1473 > V_2225 ) ||
( V_1458 -> V_1464 > V_2226 ) ||
( V_1458 -> V_971 > V_2215 ) ||
( V_1458 -> V_971 < V_2216 ) )
return - V_64 ;
if ( ( V_1458 -> V_1469 == 0 ) &&
( V_1458 -> V_1471 == 0 ) )
return - V_64 ;
if ( ( V_1458 -> V_1460 == 0 ) &&
( V_1458 -> V_1462 == 0 ) )
return - V_64 ;
V_5 -> V_970 . V_1469 = V_1458 -> V_1469 ;
V_5 -> V_970 . V_1460 = V_1458 -> V_1460 ;
V_5 -> V_970 . V_1471 = V_1458 -> V_1471 ;
V_5 -> V_970 . V_1462 = V_1458 -> V_1462 ;
V_5 -> V_970 . V_1477 = V_1458 -> V_1477 ;
V_5 -> V_970 . V_1479 = V_1458 -> V_1479 ;
V_5 -> V_970 . V_1473 = V_1458 -> V_1473 ;
V_5 -> V_970 . V_1464 = V_1458 -> V_1464 ;
V_5 -> V_970 . V_971 = V_1458 -> V_971 ;
if ( F_143 ( V_111 ) ) {
F_238 ( V_5 , 0 ) ;
F_435 ( V_5 , & V_5 -> V_970 ) ;
F_239 ( V_5 ) ;
}
return 0 ;
}
static int F_581 ( struct V_362 * V_111 , struct V_451 * V_2227 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_336 ) ) {
F_141 ( V_5 -> V_111 , L_72 ) ;
return - V_1039 ;
}
if ( V_2227 -> V_463 != V_5 -> V_452 . V_463 ) {
F_141 ( V_5 -> V_111 ,
L_73 ) ;
return - V_64 ;
}
if ( V_2227 -> V_467 > V_2228 ) {
F_141 ( V_5 -> V_111 ,
L_74 ,
V_2228 ) ;
return - V_64 ;
}
V_5 -> V_452 = * V_2227 ;
V_5 -> V_178 |= V_1533 ;
F_140 ( V_5 ) ;
if ( F_143 ( V_5 -> V_111 ) ) {
F_238 ( V_5 , 0 ) ;
F_219 ( V_5 ) ;
F_142 ( V_5 ) ;
F_239 ( V_5 ) ;
}
return 0 ;
}
static int F_582 ( struct V_362 * V_111 , struct V_451 * V_2227 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_336 ) ) {
F_141 ( V_5 -> V_111 ,
L_72 ) ;
return - V_1039 ;
}
* V_2227 = V_5 -> V_452 ;
return 0 ;
}
static struct V_1955 * F_583 ( struct V_362 * V_111 ,
struct V_1955 * V_1956 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
F_69 ( & V_5 -> V_207 ) ;
if ( ! V_5 -> V_1351 ) {
F_70 ( & V_5 -> V_207 ) ;
return & V_5 -> V_1437 ;
}
F_428 ( V_5 , V_1956 ) ;
F_70 ( & V_5 -> V_207 ) ;
return V_1956 ;
}
static void F_584 ( struct V_362 * V_111 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
if ( ! F_143 ( V_111 ) )
return;
F_238 ( V_5 , 0 ) ;
F_445 ( V_111 ) ;
F_239 ( V_5 ) ;
}
static inline void F_585 ( struct V_362 * V_111 , struct V_4 * V_5 ,
int V_2229 )
{
V_111 -> V_1201 = V_2229 ;
if ( V_2229 > V_1328 ) {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_586 ( V_111 ) ;
F_84 ( V_5 , V_1593 ) ;
} else {
F_82 ( V_5 , V_1340 ) ;
}
} else {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_82 ( V_5 , V_1593 ) ;
F_586 ( V_111 ) ;
}
F_84 ( V_5 , V_1340 ) ;
}
}
static int F_587 ( struct V_362 * V_111 , int V_2229 )
{
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_75 ;
bool V_1531 = false ;
if ( V_2229 < V_2230 || V_2229 > F_456 ( V_5 ) )
return - V_64 ;
if ( ! F_143 ( V_111 ) ) {
F_585 ( V_111 , V_5 , V_2229 ) ;
return 0 ;
}
F_121 ( V_5 ) ;
F_338 ( V_5 ) ;
F_238 ( V_5 , 1 ) ;
F_427 ( V_5 , V_110 , 1 ) ;
F_585 ( V_111 , V_5 , V_2229 ) ;
if ( F_30 ( V_5 ) == V_667 )
V_1531 = true ;
V_75 = F_478 ( V_5 , V_1531 ) ;
if ( ! V_75 )
F_340 ( V_5 ) ;
F_239 ( V_5 ) ;
if ( ! V_75 )
F_118 ( V_5 ) ;
return V_75 ;
}
static void F_588 ( struct V_4 * V_5 )
{
T_1 V_2231 , V_7 , V_1980 ;
V_5 -> V_1974 = V_2232 ;
if ( F_166 ( V_5 , 0 , & V_1980 ) != 0 )
return;
if ( ( V_1980 != V_1981 ) &&
( ( V_1980 & V_2082 ) != V_2083 ) &&
( ( V_1980 & V_2099 ) != V_2100 ) )
return;
V_2231 = 0x10 ;
while ( V_2231 < V_5 -> V_1974 ) {
if ( F_166 ( V_5 , V_2231 , & V_7 ) != 0 )
return;
if ( V_7 == V_1980 )
break;
V_2231 <<= 1 ;
}
V_5 -> V_1974 = V_2231 ;
}
static void F_589 ( struct V_4 * V_5 )
{
T_1 V_7 ;
if ( F_23 ( V_5 , V_681 ) || F_166 ( V_5 , 0 , & V_7 ) != 0 )
return;
if ( V_7 != V_1981 ) {
F_588 ( V_5 ) ;
return;
}
if ( F_166 ( V_5 , 0xf0 , & V_7 ) == 0 ) {
if ( V_7 != 0 ) {
V_5 -> V_1974 = F_590 ( ( T_3 ) ( V_7 & 0x0000ffff ) ) * 1024 ;
return;
}
}
V_5 -> V_1974 = V_2233 ;
}
static void F_591 ( struct V_4 * V_5 )
{
T_1 V_2234 ;
V_2234 = F_33 ( V_2235 ) ;
if ( V_2234 & V_2236 ) {
F_82 ( V_5 , V_611 ) ;
} else {
V_2234 &= ~ V_2237 ;
F_46 ( V_2235 , V_2234 ) ;
}
if ( F_30 ( V_5 ) == V_1498 ||
F_23 ( V_5 , 5780_CLASS ) ) {
switch ( V_2234 & V_2238 ) {
case V_2239 :
V_5 -> V_613 = V_614 ;
V_5 -> V_615 = V_2240 ;
F_82 ( V_5 , V_610 ) ;
break;
case V_2241 :
V_5 -> V_613 = V_614 ;
V_5 -> V_615 = V_2242 ;
break;
case V_2243 :
V_5 -> V_613 = V_614 ;
V_5 -> V_615 = V_2244 ;
F_82 ( V_5 , V_610 ) ;
break;
case V_2245 :
V_5 -> V_613 = V_641 ;
V_5 -> V_615 = V_2246 ;
F_82 ( V_5 , V_610 ) ;
break;
case V_2247 :
V_5 -> V_613 = V_2248 ;
V_5 -> V_615 = V_2249 ;
break;
case V_2250 :
case V_2251 :
V_5 -> V_613 = V_2252 ;
V_5 -> V_615 = V_2253 ;
break;
}
} else {
V_5 -> V_613 = V_614 ;
V_5 -> V_615 = V_2240 ;
F_82 ( V_5 , V_610 ) ;
}
}
static void F_592 ( struct V_4 * V_5 , T_1 V_2254 )
{
switch ( V_2254 & V_2255 ) {
case V_2256 :
V_5 -> V_615 = 256 ;
break;
case V_2257 :
V_5 -> V_615 = 512 ;
break;
case V_2258 :
V_5 -> V_615 = 1024 ;
break;
case V_2259 :
V_5 -> V_615 = 2048 ;
break;
case V_2260 :
V_5 -> V_615 = 4096 ;
break;
case V_2261 :
V_5 -> V_615 = 264 ;
break;
case V_2262 :
V_5 -> V_615 = 528 ;
break;
}
}
static void F_593 ( struct V_4 * V_5 )
{
T_1 V_2234 ;
V_2234 = F_33 ( V_2235 ) ;
if ( V_2234 & ( 1 << 27 ) )
F_82 ( V_5 , V_591 ) ;
switch ( V_2234 & V_2263 ) {
case V_2264 :
case V_2265 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
break;
case V_2266 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
break;
case V_2267 :
case V_2268 :
case V_2269 :
V_5 -> V_613 = V_641 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
break;
}
if ( F_23 ( V_5 , V_611 ) ) {
F_592 ( V_5 , V_2234 ) ;
} else {
V_5 -> V_615 = V_2244 ;
V_2234 &= ~ V_2237 ;
F_46 ( V_2235 , V_2234 ) ;
}
}
static void F_594 ( struct V_4 * V_5 )
{
T_1 V_2234 , V_2270 = 0 ;
V_2234 = F_33 ( V_2235 ) ;
if ( V_2234 & ( 1 << 27 ) ) {
F_82 ( V_5 , V_591 ) ;
V_2270 = 1 ;
}
V_2234 &= V_2263 ;
switch ( V_2234 ) {
case V_2271 :
case V_2272 :
case V_2273 :
case V_2274 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
V_5 -> V_615 = 264 ;
if ( V_2234 == V_2271 ||
V_2234 == V_2274 )
V_5 -> V_1974 = ( V_2270 ? 0x3e200 :
V_2233 ) ;
else if ( V_2234 == V_2272 )
V_5 -> V_1974 = ( V_2270 ? 0x1f200 :
V_2275 ) ;
else
V_5 -> V_1974 = ( V_2270 ? 0x1f200 :
V_2276 ) ;
break;
case V_2267 :
case V_2268 :
case V_2269 :
V_5 -> V_613 = V_641 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
V_5 -> V_615 = 256 ;
if ( V_2234 == V_2267 )
V_5 -> V_1974 = ( V_2270 ?
V_2277 :
V_2276 ) ;
else if ( V_2234 == V_2268 )
V_5 -> V_1974 = ( V_2270 ?
V_2277 :
V_2275 ) ;
else
V_5 -> V_1974 = ( V_2270 ?
V_2276 :
V_2233 ) ;
break;
}
}
static void F_595 ( struct V_4 * V_5 )
{
T_1 V_2234 ;
V_2234 = F_33 ( V_2235 ) ;
switch ( V_2234 & V_2263 ) {
case V_2278 :
case V_2279 :
case V_2280 :
case V_2281 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
V_5 -> V_615 = V_2244 ;
V_2234 &= ~ V_2237 ;
F_46 ( V_2235 , V_2234 ) ;
break;
case V_2266 :
case V_2271 :
case V_2272 :
case V_2273 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
V_5 -> V_615 = 264 ;
break;
case V_2267 :
case V_2268 :
case V_2269 :
V_5 -> V_613 = V_641 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
V_5 -> V_615 = 256 ;
break;
}
}
static void F_596 ( struct V_4 * V_5 )
{
T_1 V_2234 , V_2270 = 0 ;
V_2234 = F_33 ( V_2235 ) ;
if ( V_2234 & ( 1 << 27 ) ) {
F_82 ( V_5 , V_591 ) ;
V_2270 = 1 ;
}
V_2234 &= V_2263 ;
switch ( V_2234 ) {
case V_2282 :
case V_2283 :
case V_2284 :
case V_2285 :
case V_2286 :
case V_2287 :
case V_2288 :
case V_2289 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
F_82 ( V_5 , V_612 ) ;
V_5 -> V_615 = 256 ;
break;
case V_2290 :
case V_2291 :
case V_2292 :
case V_2293 :
case V_2294 :
case V_2295 :
case V_2296 :
case V_2297 :
V_5 -> V_613 = V_641 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
V_5 -> V_615 = 256 ;
break;
}
if ( V_2270 ) {
V_5 -> V_1974 = F_33 ( V_2298 ) ;
} else {
switch ( V_2234 ) {
case V_2285 :
case V_2289 :
case V_2293 :
case V_2297 :
V_5 -> V_1974 = V_2299 ;
break;
case V_2284 :
case V_2288 :
case V_2292 :
case V_2296 :
V_5 -> V_1974 = V_2300 ;
break;
case V_2283 :
case V_2287 :
case V_2291 :
case V_2295 :
V_5 -> V_1974 = V_2233 ;
break;
case V_2282 :
case V_2286 :
case V_2290 :
case V_2294 :
V_5 -> V_1974 = V_2275 ;
break;
}
}
}
static void F_597 ( struct V_4 * V_5 )
{
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
V_5 -> V_615 = V_2244 ;
}
static void F_598 ( struct V_4 * V_5 )
{
T_1 V_2234 ;
V_2234 = F_33 ( V_2235 ) ;
switch ( V_2234 & V_2263 ) {
case V_2279 :
case V_2281 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
V_5 -> V_615 = V_2244 ;
V_2234 &= ~ V_2237 ;
F_46 ( V_2235 , V_2234 ) ;
return;
case V_2266 :
case V_2301 :
case V_2302 :
case V_2303 :
case V_2304 :
case V_2305 :
case V_2306 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
switch ( V_2234 & V_2263 ) {
case V_2266 :
case V_2301 :
case V_2302 :
V_5 -> V_1974 = V_2276 ;
break;
case V_2303 :
case V_2304 :
V_5 -> V_1974 = V_2275 ;
break;
case V_2305 :
case V_2306 :
V_5 -> V_1974 = V_2233 ;
break;
}
break;
case V_2267 :
case V_2268 :
case V_2269 :
V_5 -> V_613 = V_641 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
switch ( V_2234 & V_2263 ) {
case V_2267 :
V_5 -> V_1974 = V_2276 ;
break;
case V_2268 :
V_5 -> V_1974 = V_2275 ;
break;
case V_2269 :
V_5 -> V_1974 = V_2233 ;
break;
}
break;
default:
F_82 ( V_5 , V_681 ) ;
return;
}
F_592 ( V_5 , V_2234 ) ;
if ( V_5 -> V_615 != 264 && V_5 -> V_615 != 528 )
F_82 ( V_5 , V_612 ) ;
}
static void F_599 ( struct V_4 * V_5 )
{
T_1 V_2234 ;
V_2234 = F_33 ( V_2235 ) ;
switch ( V_2234 & V_2263 ) {
case V_2307 :
case V_2308 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
V_5 -> V_615 = V_2244 ;
V_2234 &= ~ V_2237 ;
F_46 ( V_2235 , V_2234 ) ;
return;
case V_2309 :
case V_2310 :
case V_2311 :
case V_2312 :
case V_2313 :
case V_2314 :
case V_2315 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
switch ( V_2234 & V_2263 ) {
case V_2312 :
break;
case V_2313 :
case V_2314 :
V_5 -> V_1974 = V_2275 ;
break;
default:
V_5 -> V_1974 = V_2276 ;
break;
}
break;
case V_2316 :
case V_2317 :
case V_2318 :
case V_2319 :
case V_2320 :
case V_2321 :
case V_2322 :
case V_2323 :
case V_2324 :
case V_2325 :
V_5 -> V_613 = V_641 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
switch ( V_2234 & V_2263 ) {
case V_2320 :
case V_2322 :
break;
case V_2321 :
case V_2323 :
V_5 -> V_1974 = V_2275 ;
break;
default:
V_5 -> V_1974 = V_2276 ;
break;
}
break;
default:
F_82 ( V_5 , V_681 ) ;
return;
}
F_592 ( V_5 , V_2234 ) ;
if ( V_5 -> V_615 != 264 && V_5 -> V_615 != 528 )
F_82 ( V_5 , V_612 ) ;
}
static void F_600 ( struct V_4 * V_5 )
{
T_1 V_2234 , V_2326 ;
V_2234 = F_33 ( V_2235 ) ;
V_2326 = V_2234 & V_2263 ;
if ( F_30 ( V_5 ) == V_765 ) {
if ( ! ( V_2234 & V_2327 ) ) {
F_82 ( V_5 , V_681 ) ;
return;
}
switch ( V_2326 ) {
case V_2328 :
V_2326 = V_2329 ;
break;
case V_2330 :
V_2326 = V_2331 ;
break;
case V_2332 :
V_2326 = V_2333 ;
break;
}
}
switch ( V_2326 ) {
case V_2329 :
case V_2331 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
V_2234 &= ~ V_2237 ;
F_46 ( V_2235 , V_2234 ) ;
if ( V_2326 == V_2329 )
V_5 -> V_615 = V_2244 ;
else
V_5 -> V_615 = V_2334 ;
return;
case V_2335 :
case V_2336 :
case V_2337 :
case V_2338 :
case V_2339 :
case V_2340 :
case V_2341 :
case V_2342 :
case V_2343 :
case V_2344 :
case V_2345 :
case V_2346 :
V_5 -> V_613 = V_614 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
switch ( V_2326 ) {
case V_2338 :
case V_2339 :
case V_2340 :
V_5 -> V_1974 = V_2275 ;
break;
case V_2341 :
case V_2342 :
case V_2343 :
V_5 -> V_1974 = V_2233 ;
break;
case V_2344 :
case V_2345 :
V_5 -> V_1974 = V_2300 ;
break;
default:
if ( F_30 ( V_5 ) != V_765 )
V_5 -> V_1974 = V_2276 ;
break;
}
break;
case V_2347 :
case V_2348 :
case V_2349 :
case V_2350 :
case V_2351 :
case V_2332 :
case V_2352 :
case V_2353 :
case V_2354 :
case V_2355 :
case V_2356 :
case V_2357 :
case V_2358 :
case V_2359 :
case V_2360 :
case V_2361 :
case V_2362 :
case V_2333 :
V_5 -> V_613 = V_641 ;
F_82 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_611 ) ;
switch ( V_2326 ) {
case V_2351 :
case V_2332 :
case V_2352 :
case V_2353 :
V_5 -> V_1974 = V_2275 ;
break;
case V_2354 :
case V_2355 :
case V_2356 :
case V_2357 :
V_5 -> V_1974 = V_2233 ;
break;
case V_2358 :
case V_2359 :
case V_2360 :
case V_2361 :
V_5 -> V_1974 = V_2300 ;
break;
default:
if ( F_30 ( V_5 ) != V_765 )
V_5 -> V_1974 = V_2276 ;
break;
}
break;
default:
F_82 ( V_5 , V_681 ) ;
return;
}
F_592 ( V_5 , V_2234 ) ;
if ( V_5 -> V_615 != 264 && V_5 -> V_615 != 528 )
F_82 ( V_5 , V_612 ) ;
if ( F_30 ( V_5 ) == V_765 ) {
T_1 V_7 ;
if ( F_166 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 != V_1981 &&
( V_7 & V_2082 ) != V_2083 )
F_82 ( V_5 , V_681 ) ;
}
}
static void F_601 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_322 ) ) {
F_84 ( V_5 , V_585 ) ;
F_84 ( V_5 , V_610 ) ;
F_82 ( V_5 , V_681 ) ;
return;
}
F_31 ( V_598 ,
( V_2363 |
( V_2364 <<
V_2365 ) ) ) ;
F_161 ( 1 ) ;
F_31 ( V_136 ,
F_33 ( V_136 ) | V_2366 ) ;
F_24 ( 100 ) ;
if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 ) {
F_82 ( V_5 , V_585 ) ;
if ( F_156 ( V_5 ) ) {
F_141 ( V_5 -> V_111 ,
L_75 ,
V_657 ) ;
return;
}
F_158 ( V_5 ) ;
V_5 -> V_1974 = 0 ;
if ( F_30 ( V_5 ) == V_640 )
F_593 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1487 )
F_594 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1500 ||
F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_256 )
F_595 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_45 )
F_596 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_36 )
F_597 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1402 ||
F_23 ( V_5 , 57765_CLASS ) )
F_598 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 )
F_599 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_765 )
F_600 ( V_5 ) ;
else
F_591 ( V_5 ) ;
if ( V_5 -> V_1974 == 0 )
F_589 ( V_5 ) ;
F_159 ( V_5 ) ;
F_157 ( V_5 ) ;
} else {
F_84 ( V_5 , V_585 ) ;
F_84 ( V_5 , V_610 ) ;
F_588 ( V_5 ) ;
}
}
static struct V_2367 * F_602 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_567 ( V_2368 ) ; V_42 ++ ) {
if ( ( V_2368 [ V_42 ] . V_2369 ==
V_5 -> V_12 -> V_2370 ) &&
( V_2368 [ V_42 ] . V_2371 ==
V_5 -> V_12 -> V_2372 ) )
return & V_2368 [ V_42 ] ;
}
return NULL ;
}
static void F_603 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_5 -> V_215 = V_2373 ;
V_5 -> V_563 = V_818 ;
F_82 ( V_5 , V_643 ) ;
F_82 ( V_5 , V_715 ) ;
if ( F_30 ( V_5 ) == V_36 ) {
if ( ! ( F_33 ( V_1908 ) & V_2374 ) ) {
F_84 ( V_5 , V_643 ) ;
F_82 ( V_5 , V_532 ) ;
}
V_7 = F_33 ( V_2375 ) ;
if ( V_7 & V_2376 )
F_82 ( V_5 , V_972 ) ;
if ( ( V_7 & V_2377 ) &&
( V_7 & V_2378 ) ) {
F_82 ( V_5 , V_112 ) ;
F_530 ( & V_5 -> V_12 -> V_111 , true ) ;
}
goto V_186;
}
F_32 ( V_5 , V_1429 , & V_7 ) ;
if ( V_7 == V_1430 ) {
T_1 V_1431 , V_2379 ;
T_1 V_2380 , V_2381 , V_2382 = 0 , V_2383 = 0 , V_2384 ;
int V_2385 = 0 ;
F_32 ( V_5 , V_1432 , & V_1431 ) ;
V_5 -> V_550 = V_1431 ;
F_32 ( V_5 , V_2386 , & V_2381 ) ;
V_2381 >>= V_2387 ;
if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_499 &&
( V_2381 > 0 ) && ( V_2381 < 0x100 ) )
F_32 ( V_5 , V_2388 , & V_2382 ) ;
if ( F_30 ( V_5 ) == V_256 )
F_32 ( V_5 , V_2389 , & V_2383 ) ;
if ( ( V_1431 & V_2390 ) ==
V_2391 )
V_2385 = 1 ;
F_32 ( V_5 , V_2392 , & V_2380 ) ;
if ( V_2380 != 0 ) {
T_1 V_2393 = V_2380 & V_2394 ;
T_1 V_2395 = V_2380 & V_2396 ;
V_2384 = ( V_2393 >> 16 ) << 10 ;
V_2384 |= ( V_2395 & 0xfc00 ) << 16 ;
V_2384 |= ( V_2395 & 0x03ff ) << 0 ;
} else
V_2384 = 0 ;
V_5 -> V_215 = V_2384 ;
if ( V_2385 ) {
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_178 |= V_567 ;
else
V_5 -> V_178 |= V_302 ;
}
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2379 = V_2382 & ( V_2397 |
V_2398 ) ;
else
V_2379 = V_1431 & V_2397 ;
switch ( V_2379 ) {
default:
case V_2399 :
V_5 -> V_563 = V_818 ;
break;
case V_2400 :
V_5 -> V_563 = V_564 ;
break;
case V_2401 :
V_5 -> V_563 = V_2402 ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 )
V_5 -> V_563 = V_818 ;
break;
case V_2403 :
V_5 -> V_563 = V_2404 ;
if ( F_76 ( V_5 ) != V_1410 &&
F_76 ( V_5 ) != V_2405 )
V_5 -> V_563 |= ( V_818 |
V_564 ) ;
break;
case V_2406 :
V_5 -> V_563 = V_2407 ;
break;
case V_2408 :
V_5 -> V_563 = V_2409 ;
if ( F_76 ( V_5 ) != V_1410 )
V_5 -> V_563 |= ( V_818 |
V_564 ) ;
break;
}
if ( ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) &&
V_5 -> V_12 -> V_2370 == V_2410 )
V_5 -> V_563 = V_564 ;
if ( F_144 ( V_5 ) == V_503 )
V_5 -> V_563 = V_818 ;
if ( V_1431 & V_2411 ) {
F_82 ( V_5 , V_643 ) ;
if ( ( V_5 -> V_12 -> V_2370 ==
V_2412 ) &&
( V_5 -> V_12 -> V_2372 == 0x205a ||
V_5 -> V_12 -> V_2372 == 0x2063 ) )
F_84 ( V_5 , V_643 ) ;
} else {
F_84 ( V_5 , V_643 ) ;
F_82 ( V_5 , V_532 ) ;
}
if ( V_1431 & V_1433 ) {
F_82 ( V_5 , V_305 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_82 ( V_5 , V_313 ) ;
}
if ( ( V_1431 & V_2413 ) &&
F_23 ( V_5 , 5750_PLUS ) )
F_82 ( V_5 , V_60 ) ;
if ( V_5 -> V_178 & V_357 &&
! ( V_1431 & V_2414 ) )
F_84 ( V_5 , V_715 ) ;
if ( F_23 ( V_5 , V_715 ) &&
( V_1431 & V_2415 ) ) {
F_82 ( V_5 , V_112 ) ;
F_530 ( & V_5 -> V_12 -> V_111 , true ) ;
}
if ( V_2382 & ( 1 << 17 ) )
V_5 -> V_178 |= V_821 ;
if ( V_2382 & ( 1 << 18 ) )
V_5 -> V_178 |= V_1738 ;
if ( ( F_23 ( V_5 , 57765_PLUS ) ||
( F_30 ( V_5 ) == V_413 &&
F_144 ( V_5 ) != V_503 ) ) &&
( V_2382 & V_2416 ) )
V_5 -> V_178 |= V_513 ;
if ( F_23 ( V_5 , V_1081 ) ) {
T_1 V_2417 ;
F_32 ( V_5 , V_1434 , & V_2417 ) ;
if ( F_30 ( V_5 ) != V_256 &&
! F_23 ( V_5 , 57765_PLUS ) &&
( V_2417 & V_2418 ) )
F_82 ( V_5 , V_972 ) ;
if ( V_2417 & V_1436 )
V_5 -> V_178 |= V_569 ;
if ( V_2417 & V_1435 )
V_5 -> V_178 |= V_769 ;
}
if ( V_2383 & V_2419 )
F_82 ( V_5 , V_235 ) ;
if ( V_2383 & V_2420 )
F_82 ( V_5 , V_244 ) ;
if ( V_2383 & V_2421 )
F_82 ( V_5 , V_245 ) ;
}
V_186:
if ( F_23 ( V_5 , V_715 ) )
F_530 ( & V_5 -> V_12 -> V_111 ,
F_23 ( V_5 , V_112 ) ) ;
else
F_604 ( & V_5 -> V_12 -> V_111 , false ) ;
}
static int F_605 ( struct V_4 * V_5 , T_1 V_595 , T_1 * V_7 )
{
int V_42 , V_75 ;
T_1 V_2422 , V_6 = V_595 * 8 ;
V_75 = F_156 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_11 ( V_5 , V_2423 , V_6 | V_2424 ) ;
F_11 ( V_5 , V_2425 , V_2426 |
V_2427 | V_2428 ) ;
F_12 ( V_5 , V_2425 ) ;
F_24 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_2422 = F_12 ( V_5 , V_2429 ) ;
if ( V_2422 & V_2430 ) {
* V_7 = F_12 ( V_5 , V_2431 ) ;
break;
}
F_24 ( 10 ) ;
}
F_11 ( V_5 , V_2425 , 0 ) ;
F_157 ( V_5 ) ;
if ( V_2422 & V_2430 )
return 0 ;
return - V_67 ;
}
static int F_606 ( struct V_4 * V_5 , T_1 V_642 )
{
int V_42 ;
T_1 V_7 ;
F_46 ( V_2432 , V_642 | V_2433 ) ;
F_46 ( V_2432 , V_642 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_7 = F_33 ( V_2434 ) ;
if ( V_7 & V_2435 )
break;
F_24 ( 10 ) ;
}
return ( V_7 & V_2435 ) ? 0 : - V_67 ;
}
static T_1 F_607 ( struct V_4 * V_5 )
{
T_1 V_2436 , V_2437 ;
F_46 ( V_2438 , V_2439 ) ;
if ( F_606 ( V_5 , V_2440 ) )
return 0 ;
F_46 ( V_2441 , V_2442 ) ;
if ( F_606 ( V_5 , V_2443 ) )
return 0 ;
V_2437 = F_33 ( V_2444 ) ;
F_46 ( V_2441 , V_2445 ) ;
if ( F_606 ( V_5 , V_2443 ) )
return 0 ;
V_2436 = F_33 ( V_2444 ) ;
return ( ( V_2437 & 0x0000ffff ) << 16 ) | ( V_2436 >> 16 ) ;
}
static void F_608 ( struct V_4 * V_5 )
{
T_1 V_339 = V_703 ;
if ( ! ( V_5 -> V_178 & V_390 ) )
V_339 |= V_770 |
V_761 ;
if ( ! ( V_5 -> V_178 & V_357 ) )
V_339 |= V_706 |
V_707 |
V_704 |
V_708 |
V_701 ;
else
V_339 |= V_777 ;
V_5 -> V_327 . V_396 = V_339 ;
V_5 -> V_327 . V_370 = V_751 ;
V_5 -> V_327 . V_374 = V_752 ;
V_5 -> V_327 . V_350 = V_355 ;
V_5 -> V_327 . V_328 = V_751 ;
V_5 -> V_327 . V_331 = V_752 ;
V_5 -> V_388 = - 1 ;
}
static int F_609 ( struct V_4 * V_5 )
{
T_1 V_2446 , V_2447 ;
T_1 V_2448 , V_2449 ;
int V_75 ;
F_82 ( V_5 , V_356 ) ;
V_5 -> V_327 . V_340 = V_334 | V_335 ;
if ( F_23 ( V_5 , V_60 ) ) {
switch ( V_5 -> V_54 ) {
case 0 :
V_5 -> V_167 = V_48 ;
break;
case 1 :
V_5 -> V_167 = V_50 ;
break;
case 2 :
V_5 -> V_167 = V_51 ;
break;
case 3 :
V_5 -> V_167 = V_52 ;
break;
}
}
if ( ! F_23 ( V_5 , V_305 ) &&
! ( V_5 -> V_178 & V_357 ) &&
! ( V_5 -> V_178 & V_390 ) )
V_5 -> V_178 &= ~ ( V_769 |
V_569 ) ;
if ( F_23 ( V_5 , V_263 ) )
return F_111 ( V_5 ) ;
V_75 = 0 ;
if ( F_23 ( V_5 , V_305 ) || F_23 ( V_5 , V_60 ) ) {
V_2448 = V_2449 = V_2373 ;
} else {
V_75 |= F_57 ( V_5 , V_2450 , & V_2446 ) ;
V_75 |= F_57 ( V_5 , V_2451 , & V_2447 ) ;
V_2448 = ( V_2446 & 0xffff ) << 10 ;
V_2448 |= ( V_2447 & 0xfc00 ) << 16 ;
V_2448 |= ( V_2447 & 0x03ff ) << 0 ;
V_2449 = V_2448 & V_398 ;
}
if ( ! V_75 && F_610 ( V_2449 ) ) {
V_5 -> V_215 = V_2448 ;
if ( V_2449 == V_939 )
V_5 -> V_178 |= V_567 ;
else
V_5 -> V_178 &= ~ V_567 ;
} else {
if ( V_5 -> V_215 != V_2373 ) {
} else {
struct V_2367 * V_1439 ;
V_1439 = F_602 ( V_5 ) ;
if ( V_1439 ) {
V_5 -> V_215 = V_1439 -> V_215 ;
} else if ( ! F_23 ( V_5 , V_322 ) ) {
return - V_82 ;
}
if ( ! V_5 -> V_215 ||
V_5 -> V_215 == V_939 )
V_5 -> V_178 |= V_567 ;
}
}
if ( ! ( V_5 -> V_178 & V_357 ) &&
( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_667 ||
F_30 ( V_5 ) == V_765 ||
( F_30 ( V_5 ) == V_476 &&
F_76 ( V_5 ) != V_258 ) ||
( F_30 ( V_5 ) == V_763 &&
F_76 ( V_5 ) != V_325 ) ) ) {
V_5 -> V_178 |= V_336 ;
V_5 -> V_452 . V_391 = V_1989 |
V_1987 ;
V_5 -> V_452 . V_463 = V_707 |
V_761 ;
V_5 -> V_452 . V_462 = 1 ;
V_5 -> V_452 . V_465 = 1 ;
V_5 -> V_452 . V_467 = V_2452 ;
}
F_608 ( V_5 ) ;
if ( ! ( V_5 -> V_178 & V_569 ) &&
! ( V_5 -> V_178 & V_357 ) &&
! F_23 ( V_5 , V_60 ) &&
! F_23 ( V_5 , V_305 ) ) {
T_1 V_809 , V_2453 ;
F_57 ( V_5 , V_299 , & V_809 ) ;
if ( ! F_57 ( V_5 , V_299 , & V_809 ) &&
( V_809 & V_775 ) )
goto V_2454;
V_75 = F_142 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_128 ( V_5 ) ;
if ( ! F_212 ( V_5 , & V_2453 ) ) {
F_202 ( V_5 , V_5 -> V_327 . V_396 ,
V_5 -> V_327 . V_340 ) ;
F_59 ( V_5 , V_202 ,
V_576 | V_577 ) ;
}
}
V_2454:
if ( ( V_5 -> V_215 & V_398 ) == V_399 ) {
V_75 = F_210 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_210 ( V_5 ) ;
}
return V_75 ;
}
static void F_611 ( struct V_4 * V_5 )
{
T_4 * V_2455 ;
unsigned int V_2456 , V_2457 , V_74 ;
T_1 V_2066 ;
int V_627 , V_42 = 0 ;
V_2455 = ( T_4 * ) F_550 ( V_5 , & V_2066 ) ;
if ( ! V_2455 )
goto V_2458;
V_42 = F_555 ( V_2455 , 0 , V_2066 , V_2110 ) ;
if ( V_42 < 0 )
goto V_2459;
V_2457 = F_556 ( & V_2455 [ V_42 ] ) ;
V_2456 = V_42 + V_2111 + V_2457 ;
V_42 += V_2111 ;
if ( V_2456 > V_2066 )
goto V_2459;
V_627 = F_557 ( V_2455 , V_42 , V_2457 ,
V_2460 ) ;
if ( V_627 > 0 ) {
V_74 = F_612 ( & V_2455 [ V_627 ] ) ;
V_627 += V_2113 ;
if ( V_627 + V_74 > V_2456 || V_74 != 4 ||
memcmp ( & V_2455 [ V_627 ] , L_76 , 4 ) )
goto V_2461;
V_627 = F_557 ( V_2455 , V_42 , V_2457 ,
V_2462 ) ;
if ( V_627 < 0 )
goto V_2461;
V_74 = F_612 ( & V_2455 [ V_627 ] ) ;
V_627 += V_2113 ;
if ( V_627 + V_74 > V_2456 )
goto V_2461;
if ( V_74 >= sizeof( V_5 -> V_2014 ) )
V_74 = sizeof( V_5 -> V_2014 ) - 1 ;
memset ( V_5 -> V_2014 , 0 , sizeof( V_5 -> V_2014 ) ) ;
snprintf ( V_5 -> V_2014 , sizeof( V_5 -> V_2014 ) , L_77 , V_74 ,
& V_2455 [ V_627 ] ) ;
}
V_2461:
V_42 = F_557 ( V_2455 , V_42 , V_2457 ,
V_2463 ) ;
if ( V_42 < 0 )
goto V_2459;
V_74 = F_612 ( & V_2455 [ V_42 ] ) ;
V_42 += V_2113 ;
if ( V_74 > V_2464 ||
( V_74 + V_42 ) > V_2066 )
goto V_2459;
memcpy ( V_5 -> V_2465 , & V_2455 [ V_42 ] , V_74 ) ;
V_2459:
F_173 ( V_2455 ) ;
if ( V_5 -> V_2465 [ 0 ] )
return;
V_2458:
if ( F_30 ( V_5 ) == V_476 ) {
if ( V_5 -> V_12 -> V_543 == V_2466 ||
V_5 -> V_12 -> V_543 == V_2467 )
strcpy ( V_5 -> V_2465 , L_78 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2468 )
strcpy ( V_5 -> V_2465 , L_79 ) ;
else
goto V_2469;
} else if ( F_30 ( V_5 ) == V_1402 ) {
if ( V_5 -> V_12 -> V_543 == V_2470 )
strcpy ( V_5 -> V_2465 , L_80 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2471 )
strcpy ( V_5 -> V_2465 , L_81 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2472 )
strcpy ( V_5 -> V_2465 , L_82 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2473 )
strcpy ( V_5 -> V_2465 , L_83 ) ;
else
goto V_2469;
} else if ( F_30 ( V_5 ) == V_763 ) {
if ( V_5 -> V_12 -> V_543 == V_2474 )
strcpy ( V_5 -> V_2465 , L_84 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2475 )
strcpy ( V_5 -> V_2465 , L_85 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2476 )
strcpy ( V_5 -> V_2465 , L_86 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2477 )
strcpy ( V_5 -> V_2465 , L_87 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2478 )
strcpy ( V_5 -> V_2465 , L_88 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2479 )
strcpy ( V_5 -> V_2465 , L_89 ) ;
else
goto V_2469;
} else if ( F_30 ( V_5 ) == V_667 ) {
if ( V_5 -> V_12 -> V_543 == V_2480 )
strcpy ( V_5 -> V_2465 , L_90 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2481 )
strcpy ( V_5 -> V_2465 , L_91 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2482 )
strcpy ( V_5 -> V_2465 , L_92 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2483 )
strcpy ( V_5 -> V_2465 , L_93 ) ;
else
goto V_2469;
} else if ( F_30 ( V_5 ) == V_36 ) {
strcpy ( V_5 -> V_2465 , L_94 ) ;
} else {
V_2469:
strcpy ( V_5 -> V_2465 , L_95 ) ;
}
}
static int F_613 ( struct V_4 * V_5 , T_1 V_595 )
{
T_1 V_7 ;
if ( F_166 ( V_5 , V_595 , & V_7 ) ||
( V_7 & 0xfc000000 ) != 0x0c000000 ||
F_166 ( V_5 , V_595 + 4 , & V_7 ) ||
V_7 != 0 )
return 0 ;
return 1 ;
}
static void F_614 ( struct V_4 * V_5 )
{
T_1 V_7 , V_595 , V_1030 , V_2484 ;
int V_42 , V_2485 ;
bool V_2486 = false ;
if ( F_166 ( V_5 , 0xc , & V_595 ) ||
F_166 ( V_5 , 0x4 , & V_1030 ) )
return;
V_595 = F_165 ( V_5 , V_595 ) ;
if ( F_166 ( V_5 , V_595 , & V_7 ) )
return;
if ( ( V_7 & 0xfc000000 ) == 0x0c000000 ) {
if ( F_166 ( V_5 , V_595 + 4 , & V_7 ) )
return;
if ( V_7 == 0 )
V_2486 = true ;
}
V_2485 = strlen ( V_5 -> V_2014 ) ;
if ( V_2486 ) {
if ( V_2487 - V_2485 < 16 ||
F_166 ( V_5 , V_595 + 8 , & V_2484 ) )
return;
V_595 = V_595 + V_2484 - V_1030 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 += 4 ) {
T_5 V_624 ;
if ( F_167 ( V_5 , V_595 + V_42 , & V_624 ) )
return;
memcpy ( V_5 -> V_2014 + V_2485 + V_42 , & V_624 , sizeof( V_624 ) ) ;
}
} else {
T_1 V_2488 , V_2489 ;
if ( F_166 ( V_5 , V_2490 , & V_2484 ) )
return;
V_2488 = ( V_2484 & V_2491 ) >>
V_2492 ;
V_2489 = V_2484 & V_2493 ;
snprintf ( & V_5 -> V_2014 [ V_2485 ] , V_2487 - V_2485 ,
L_96 , V_2488 , V_2489 ) ;
}
}
static void F_615 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2488 , V_2489 ;
if ( F_166 ( V_5 , V_2494 , & V_7 ) )
return;
V_2488 = ( V_7 & V_2495 ) >>
V_2496 ;
V_2489 = ( V_7 & V_2497 ) >>
V_2498 ;
snprintf ( & V_5 -> V_2014 [ 0 ] , 32 , L_97 , V_2488 , V_2489 ) ;
}
static void F_616 ( struct V_4 * V_5 , T_1 V_7 )
{
T_1 V_595 , V_2488 , V_2489 , V_2499 ;
strncat ( V_5 -> V_2014 , L_98 , V_2487 - strlen ( V_5 -> V_2014 ) - 1 ) ;
if ( ( V_7 & V_2084 ) != V_2085 )
return;
switch ( V_7 & V_2086 ) {
case V_2087 :
V_595 = V_2500 ;
break;
case V_2089 :
V_595 = V_2501 ;
break;
case V_2091 :
V_595 = V_2502 ;
break;
case V_2093 :
V_595 = V_2503 ;
break;
case V_2095 :
V_595 = V_2504 ;
break;
case V_2097 :
V_595 = V_2505 ;
break;
default:
return;
}
if ( F_166 ( V_5 , V_595 , & V_7 ) )
return;
V_2499 = ( V_7 & V_2506 ) >>
V_2507 ;
V_2488 = ( V_7 & V_2508 ) >>
V_2509 ;
V_2489 = V_7 & V_2510 ;
if ( V_2489 > 99 || V_2499 > 26 )
return;
V_595 = strlen ( V_5 -> V_2014 ) ;
snprintf ( & V_5 -> V_2014 [ V_595 ] , V_2487 - V_595 ,
L_99 , V_2488 , V_2489 ) ;
if ( V_2499 > 0 ) {
V_595 = strlen ( V_5 -> V_2014 ) ;
if ( V_595 < V_2487 - 1 )
V_5 -> V_2014 [ V_595 ] = 'a' + V_2499 - 1 ;
}
}
static void F_617 ( struct V_4 * V_5 )
{
T_1 V_7 , V_595 , V_1030 ;
int V_42 , V_2511 ;
for ( V_595 = V_2067 ;
V_595 < V_2068 ;
V_595 += V_2069 ) {
if ( F_166 ( V_5 , V_595 , & V_7 ) )
return;
if ( ( V_7 >> V_2070 ) == V_2512 )
break;
}
if ( V_595 == V_2068 )
return;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_1030 = 0x08000000 ;
else if ( F_166 ( V_5 , V_595 - 4 , & V_1030 ) )
return;
if ( F_166 ( V_5 , V_595 + 4 , & V_595 ) ||
! F_613 ( V_5 , V_595 ) ||
F_166 ( V_5 , V_595 + 8 , & V_7 ) )
return;
V_595 += V_7 - V_1030 ;
V_2511 = strlen ( V_5 -> V_2014 ) ;
V_5 -> V_2014 [ V_2511 ++ ] = ',' ;
V_5 -> V_2014 [ V_2511 ++ ] = ' ' ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
T_5 V_624 ;
if ( F_167 ( V_5 , V_595 , & V_624 ) )
return;
V_595 += sizeof( V_624 ) ;
if ( V_2511 > V_2487 - sizeof( V_624 ) ) {
memcpy ( & V_5 -> V_2014 [ V_2511 ] , & V_624 , V_2487 - V_2511 ) ;
break;
}
memcpy ( & V_5 -> V_2014 [ V_2511 ] , & V_624 , sizeof( V_624 ) ) ;
V_2511 += sizeof( V_624 ) ;
}
}
static void F_618 ( struct V_4 * V_5 )
{
T_1 V_69 ;
V_69 = F_12 ( V_5 , V_80 ) ;
if ( V_69 != V_81 )
return;
V_69 = F_12 ( V_5 , V_83 ) ;
if ( ! ( V_69 & V_84 ) )
return;
if ( F_12 ( V_5 , V_2513 ) & V_2514 )
F_82 ( V_5 , V_79 ) ;
}
static void F_619 ( struct V_4 * V_5 )
{
int V_2511 ;
T_1 V_69 ;
char * V_2515 ;
V_69 = F_12 ( V_5 , V_2516 ) ;
if ( F_23 ( V_5 , V_79 ) )
V_2515 = L_100 ;
else if ( V_5 -> V_12 -> V_543 == V_2517 )
V_2515 = L_101 ;
else
V_2515 = L_102 ;
V_2511 = strlen ( V_5 -> V_2014 ) ;
snprintf ( & V_5 -> V_2014 [ V_2511 ] , V_2487 - V_2511 , L_103 ,
V_2515 ,
( V_69 & V_2518 ) >> V_2519 ,
( V_69 & V_2520 ) >> V_2521 ,
( V_69 & V_2522 ) >> V_2523 ,
( V_69 & V_2524 ) ) ;
}
static void F_620 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2422 ;
if ( F_30 ( V_5 ) != V_765 )
return;
if ( ! F_605 ( V_5 , V_2525 , & V_7 ) &&
! F_605 ( V_5 , V_2525 + 4 , & V_2422 ) &&
F_621 ( V_7 ) ) {
T_6 V_2526 = ( T_6 ) V_7 << 32 | V_2422 ;
T_1 V_2381 = 0 ;
int V_42 , V_2511 ;
for ( V_42 = 0 ; V_42 < 7 ; V_42 ++ ) {
if ( ( V_2526 & 0xff ) == 0 )
break;
V_2381 = V_2526 & 0xff ;
V_2526 >>= 8 ;
}
V_2511 = strlen ( V_5 -> V_2014 ) ;
snprintf ( & V_5 -> V_2014 [ V_2511 ] , V_2487 - V_2511 , L_104 , V_2381 ) ;
}
}
static void F_622 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_2527 = false ;
if ( V_5 -> V_2014 [ 0 ] != 0 )
V_2527 = true ;
if ( F_23 ( V_5 , V_681 ) ) {
strcat ( V_5 -> V_2014 , L_98 ) ;
F_620 ( V_5 ) ;
return;
}
if ( F_166 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 == V_1981 )
F_614 ( V_5 ) ;
else if ( ( V_7 & V_2082 ) == V_2083 )
F_616 ( V_5 , V_7 ) ;
else if ( ( V_7 & V_2099 ) == V_2100 )
F_615 ( V_5 ) ;
if ( F_23 ( V_5 , V_305 ) ) {
if ( F_23 ( V_5 , V_60 ) ) {
F_618 ( V_5 ) ;
if ( ! V_2527 )
F_619 ( V_5 ) ;
} else if ( ! V_2527 ) {
F_617 ( V_5 ) ;
}
}
V_5 -> V_2014 [ V_2487 - 1 ] = 0 ;
}
static inline T_1 F_623 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1712 ) )
return V_2528 ;
else if ( F_23 ( V_5 , V_521 ) && ! F_23 ( V_5 , 5780_CLASS ) )
return V_2529 ;
else
return V_2530 ;
}
static struct V_1788 * F_624 ( struct V_4 * V_5 )
{
struct V_1788 * V_2531 ;
unsigned int V_2532 , V_2533 = V_5 -> V_12 -> V_270 & ~ 7 ;
for ( V_2532 = 0 ; V_2532 < 8 ; V_2532 ++ ) {
V_2531 = F_625 ( V_5 -> V_12 -> V_268 , V_2533 | V_2532 ) ;
if ( V_2531 && V_2531 != V_5 -> V_12 )
break;
F_626 ( V_2531 ) ;
}
if ( ! V_2531 ) {
V_2531 = V_5 -> V_12 ;
return V_2531 ;
}
F_626 ( V_2531 ) ;
return V_2531 ;
}
static void F_627 ( struct V_4 * V_5 , T_1 V_2534 )
{
V_5 -> V_2535 = V_2534 >> V_2536 ;
if ( F_30 ( V_5 ) == V_2537 ) {
T_1 V_161 ;
F_82 ( V_5 , V_152 ) ;
if ( V_5 -> V_12 -> V_543 == V_2466 ||
V_5 -> V_12 -> V_543 == V_2467 ||
V_5 -> V_12 -> V_543 == V_2468 ||
V_5 -> V_12 -> V_543 == V_2538 ||
V_5 -> V_12 -> V_543 == V_2539 ||
V_5 -> V_12 -> V_543 == V_2540 ||
V_5 -> V_12 -> V_543 == V_2517 ||
V_5 -> V_12 -> V_543 == V_2541 )
V_161 = V_2542 ;
else if ( V_5 -> V_12 -> V_543 == V_2476 ||
V_5 -> V_12 -> V_543 == V_2477 ||
V_5 -> V_12 -> V_543 == V_2474 ||
V_5 -> V_12 -> V_543 == V_2475 ||
V_5 -> V_12 -> V_543 == V_2478 ||
V_5 -> V_12 -> V_543 == V_2479 ||
V_5 -> V_12 -> V_543 == V_2480 ||
V_5 -> V_12 -> V_543 == V_2481 ||
V_5 -> V_12 -> V_543 == V_2482 ||
V_5 -> V_12 -> V_543 == V_2483 )
V_161 = V_2543 ;
else
V_161 = V_2544 ;
F_19 ( V_5 -> V_12 , V_161 , & V_5 -> V_2535 ) ;
}
if ( F_76 ( V_5 ) == V_2545 )
V_5 -> V_2535 = V_2546 ;
if ( F_76 ( V_5 ) == V_2547 )
V_5 -> V_2535 = V_1612 ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 )
F_82 ( V_5 , 5717_PLUS ) ;
if ( F_30 ( V_5 ) == V_763 ||
F_30 ( V_5 ) == V_667 )
F_82 ( V_5 , 57765_CLASS ) ;
if ( F_23 ( V_5 , 57765_CLASS ) || F_23 ( V_5 , 5717_PLUS ) ||
F_30 ( V_5 ) == V_765 )
F_82 ( V_5 , 57765_PLUS ) ;
if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_1500 ||
F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1402 ||
F_23 ( V_5 , 57765_PLUS ) )
F_82 ( V_5 , 5755_PLUS ) ;
if ( F_30 ( V_5 ) == V_566 ||
F_30 ( V_5 ) == V_548 )
F_82 ( V_5 , 5780_CLASS ) ;
if ( F_30 ( V_5 ) == V_1498 ||
F_30 ( V_5 ) == V_640 ||
F_30 ( V_5 ) == V_36 ||
F_23 ( V_5 , 5755_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) )
F_82 ( V_5 , 5750_PLUS ) ;
if ( F_30 ( V_5 ) == V_501 ||
F_23 ( V_5 , 5750_PLUS ) )
F_82 ( V_5 , 5705_PLUS ) ;
}
static bool F_628 ( struct V_4 * V_5 ,
const struct V_2548 * V_2549 )
{
T_1 V_2550 = F_33 ( V_497 ) & V_2551 ;
if ( ( F_30 ( V_5 ) == V_499 &&
( V_2550 == 0x8000 || V_2550 == 0x4000 ) ) ||
( V_5 -> V_178 & V_179 ) )
return true ;
if ( V_2549 -> V_2552 & V_2553 ) {
if ( F_30 ( V_5 ) == V_501 ) {
if ( V_2549 -> V_2552 & V_2554 )
return true ;
} else {
return true ;
}
}
return false ;
}
static int F_629 ( struct V_4 * V_5 , const struct V_2548 * V_2549 )
{
T_1 V_2534 ;
T_1 V_2555 , V_2550 ;
T_1 V_7 ;
T_3 V_1380 ;
int V_75 ;
F_420 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
V_1380 &= ~ V_2556 ;
F_422 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
F_19 ( V_5 -> V_12 , V_119 ,
& V_2534 ) ;
V_5 -> V_120 |= ( V_2534 &
V_2557 ) ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
F_627 ( V_5 , V_2534 ) ;
if ( ( F_76 ( V_5 ) == V_1739 ) ||
( F_76 ( V_5 ) == V_2558 ) ) {
static struct V_2559 {
T_1 V_2560 ;
T_1 V_543 ;
T_1 V_2561 ;
} V_2562 [] = {
{ V_2563 , V_2564 ,
V_2565 } ,
{ V_2563 , V_2566 ,
V_2565 } ,
{ V_2563 , V_2567 ,
0xa } ,
{ V_2563 , V_2568 ,
V_2565 } ,
{ } ,
} ;
struct V_2559 * V_2569 = & V_2562 [ 0 ] ;
struct V_1788 * V_2570 = NULL ;
while ( V_2569 -> V_2560 != 0 ) {
V_2570 = F_630 ( V_2569 -> V_2560 , V_2569 -> V_543 ,
V_2570 ) ;
if ( ! V_2570 ) {
V_2569 ++ ;
continue;
}
if ( V_2569 -> V_2561 != V_2565 ) {
if ( V_2570 -> V_2571 > V_2569 -> V_2561 )
continue;
}
if ( V_2570 -> V_2572 &&
( V_2570 -> V_2572 -> V_269 ==
V_5 -> V_12 -> V_268 -> V_269 ) ) {
F_82 ( V_5 , V_26 ) ;
F_626 ( V_2570 ) ;
break;
}
}
}
if ( F_30 ( V_5 ) == V_537 ) {
static struct V_2559 {
T_1 V_2560 ;
T_1 V_543 ;
} V_2573 [] = {
{ V_2563 , V_2574 } ,
{ V_2563 , V_2575 } ,
{ } ,
} ;
struct V_2559 * V_2569 = & V_2573 [ 0 ] ;
struct V_1788 * V_2570 = NULL ;
while ( V_2569 -> V_2560 != 0 ) {
V_2570 = F_630 ( V_2569 -> V_2560 ,
V_2569 -> V_543 ,
V_2570 ) ;
if ( ! V_2570 ) {
V_2569 ++ ;
continue;
}
if ( V_2570 -> V_2572 &&
( V_2570 -> V_2572 -> V_269 <=
V_5 -> V_12 -> V_268 -> V_269 ) &&
( V_2570 -> V_2572 -> V_2576 . V_1983 >=
V_5 -> V_12 -> V_268 -> V_269 ) ) {
F_82 ( V_5 , 5701_DMA_BUG ) ;
F_626 ( V_2570 ) ;
break;
}
}
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_82 ( V_5 , 40BIT_DMA_BUG ) ;
V_5 -> V_1397 = V_5 -> V_12 -> V_1397 ;
} else {
struct V_1788 * V_2570 = NULL ;
do {
V_2570 = F_630 ( V_2577 ,
V_2578 ,
V_2570 ) ;
if ( V_2570 && V_2570 -> V_2572 &&
( V_2570 -> V_2572 -> V_269 <=
V_5 -> V_12 -> V_268 -> V_269 ) &&
( V_2570 -> V_2572 -> V_2576 . V_1983 >=
V_5 -> V_12 -> V_268 -> V_269 ) ) {
F_82 ( V_5 , 40BIT_DMA_BUG ) ;
F_626 ( V_2570 ) ;
break;
}
} while ( V_2570 );
}
if ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_548 )
V_5 -> V_559 = F_624 ( V_5 ) ;
if ( F_76 ( V_5 ) == V_1611 )
;
else if ( F_23 ( V_5 , 57765_PLUS ) )
F_82 ( V_5 , V_1298 ) ;
else if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_82 ( V_5 , V_1297 ) ;
else if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_82 ( V_5 , V_1296 ) ;
F_82 ( V_5 , V_1293 ) ;
if ( F_30 ( V_5 ) == V_1498 &&
F_76 ( V_5 ) >= V_2579 )
F_84 ( V_5 , V_1293 ) ;
} else if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 &&
F_76 ( V_5 ) != V_1425 ) {
F_82 ( V_5 , V_683 ) ;
F_82 ( V_5 , V_1293 ) ;
if ( F_30 ( V_5 ) == V_501 )
V_5 -> V_1890 = V_2580 ;
else
V_5 -> V_1890 = V_2581 ;
}
if ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_683 ) ) {
F_82 ( V_5 , V_1593 ) ;
} else {
F_84 ( V_5 , V_1593 ) ;
F_84 ( V_5 , V_1293 ) ;
V_5 -> V_1890 = NULL ;
}
if ( F_76 ( V_5 ) == V_757 )
V_5 -> V_1890 = V_2582 ;
if ( F_30 ( V_5 ) == V_667 )
V_5 -> V_1890 = V_2583 ;
V_5 -> V_122 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_82 ( V_5 , V_1900 ) ;
if ( F_144 ( V_5 ) == V_739 ||
F_144 ( V_5 ) == V_740 ||
( F_30 ( V_5 ) == V_548 &&
F_76 ( V_5 ) <= V_2584 &&
V_5 -> V_559 == V_5 -> V_12 ) )
F_84 ( V_5 , V_1900 ) ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 ) {
F_82 ( V_5 , 1SHOT_MSI ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
F_82 ( V_5 , V_1063 ) ;
V_5 -> V_122 = V_1894 ;
}
}
V_5 -> V_1899 = 1 ;
V_5 -> V_1897 = 1 ;
if ( V_5 -> V_122 > 1 ) {
V_5 -> V_1897 = V_2044 ;
F_448 ( V_5 , V_2044 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 )
V_5 -> V_1899 = V_5 -> V_122 - 1 ;
}
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_82 ( V_5 , V_1258 ) ;
if ( F_30 ( V_5 ) == V_477 )
V_5 -> V_1259 = V_2585 ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_765 )
F_82 ( V_5 , V_1712 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) &&
F_76 ( V_5 ) != V_1611 )
F_82 ( V_5 , V_1304 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_1304 ) )
F_82 ( V_5 , V_521 ) ;
F_19 ( V_5 -> V_12 , V_1243 ,
& V_2555 ) ;
if ( F_425 ( V_5 -> V_12 ) ) {
T_3 V_2586 ;
F_82 ( V_5 , V_1081 ) ;
F_631 ( V_5 -> V_12 , V_698 , & V_2586 ) ;
if ( V_2586 & V_699 ) {
if ( F_30 ( V_5 ) == V_36 ) {
F_84 ( V_5 , V_1297 ) ;
F_84 ( V_5 , V_1593 ) ;
}
if ( F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_45 ||
F_76 ( V_5 ) == V_2587 ||
F_76 ( V_5 ) == V_2588 )
F_82 ( V_5 , V_697 ) ;
} else if ( F_76 ( V_5 ) == V_258 ) {
F_82 ( V_5 , V_1552 ) ;
}
} else if ( F_30 ( V_5 ) == V_256 ) {
F_82 ( V_5 , V_1081 ) ;
} else if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ) {
V_5 -> V_1392 = F_632 ( V_5 -> V_12 , V_2589 ) ;
if ( ! V_5 -> V_1392 ) {
F_115 ( & V_5 -> V_12 -> V_111 ,
L_105 ) ;
return - V_208 ;
}
if ( ! ( V_2555 & V_2590 ) )
F_82 ( V_5 , V_839 ) ;
}
if ( F_633 ( V_2591 ) &&
! F_23 ( V_5 , V_1081 ) )
F_82 ( V_5 , V_31 ) ;
F_634 ( V_5 -> V_12 , V_1387 ,
& V_5 -> V_1388 ) ;
F_634 ( V_5 -> V_12 , V_1389 ,
& V_5 -> V_1390 ) ;
if ( F_30 ( V_5 ) == V_499 &&
V_5 -> V_1390 < 64 ) {
V_5 -> V_1390 = 64 ;
F_423 ( V_5 -> V_12 , V_1389 ,
V_5 -> V_1390 ) ;
}
if ( F_144 ( V_5 ) == V_2592 ) {
F_82 ( V_5 , V_34 ) ;
if ( F_23 ( V_5 , V_839 ) ) {
T_1 V_2593 ;
F_82 ( V_5 , V_25 ) ;
F_19 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2594 + V_2595 ,
& V_2593 ) ;
V_2593 &= ~ V_2596 ;
V_2593 |= V_2597 | 0 ;
F_15 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2594 + V_2595 ,
V_2593 ) ;
F_420 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
V_1380 |= V_2598 | V_1889 ;
F_422 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
}
}
if ( ( V_2555 & V_1640 ) != 0 )
F_82 ( V_5 , V_840 ) ;
if ( ( V_2555 & V_2599 ) != 0 )
F_82 ( V_5 , V_2600 ) ;
if ( ( F_76 ( V_5 ) == V_916 ) &&
( ! ( V_2555 & V_1383 ) ) ) {
V_2555 |= V_1383 ;
F_15 ( V_5 -> V_12 , V_1243 , V_2555 ) ;
}
V_5 -> V_28 = F_9 ;
V_5 -> V_27 = F_7 ;
V_5 -> V_32 = F_9 ;
V_5 -> V_29 = F_7 ;
V_5 -> V_1096 = F_7 ;
V_5 -> V_1882 = F_7 ;
if ( F_23 ( V_5 , V_25 ) )
V_5 -> V_27 = F_13 ;
else if ( F_30 ( V_5 ) == V_537 ||
( F_23 ( V_5 , V_1081 ) &&
F_76 ( V_5 ) == V_1410 ) ) {
V_5 -> V_27 = F_17 ;
}
if ( F_23 ( V_5 , V_34 ) || F_23 ( V_5 , V_31 ) ) {
V_5 -> V_1096 = F_26 ;
if ( F_23 ( V_5 , V_31 ) )
V_5 -> V_1882 = F_17 ;
}
if ( F_23 ( V_5 , V_26 ) ) {
V_5 -> V_28 = F_18 ;
V_5 -> V_27 = F_13 ;
V_5 -> V_32 = F_21 ;
V_5 -> V_29 = F_20 ;
V_5 -> V_1096 = F_20 ;
V_5 -> V_1882 = F_20 ;
F_635 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
F_420 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
V_1380 &= ~ V_2601 ;
F_422 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_32 = F_27 ;
V_5 -> V_29 = F_28 ;
V_5 -> V_1096 = F_28 ;
V_5 -> V_1882 = F_28 ;
}
if ( V_5 -> V_27 == F_13 ||
( F_23 ( V_5 , V_839 ) &&
( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) ) )
F_82 ( V_5 , V_39 ) ;
V_7 = F_33 ( V_1065 ) ;
F_46 ( V_1065 , V_7 | V_1378 ) ;
V_5 -> V_54 = F_636 ( V_5 -> V_12 -> V_270 ) & 3 ;
if ( F_30 ( V_5 ) == V_500 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_839 ) ) {
F_19 ( V_5 -> V_12 ,
V_5 -> V_1392 + V_2602 ,
& V_7 ) ;
V_5 -> V_54 = V_7 & 0x7 ;
}
} else if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) {
F_32 ( V_5 , V_2603 , & V_7 ) ;
if ( ( V_7 & V_2604 ) != V_2605 )
V_7 = F_33 ( V_2606 ) ;
if ( F_30 ( V_5 ) == V_476 )
V_5 -> V_54 = ( V_7 & V_2607 ) ? 1 : 0 ;
else
V_5 -> V_54 = ( V_7 & V_2608 ) >>
V_2609 ;
}
if ( F_23 ( V_5 , V_30 ) ) {
V_5 -> V_1096 = F_17 ;
V_5 -> V_1882 = F_17 ;
}
F_603 ( V_5 ) ;
if ( F_23 ( V_5 , V_683 ) && F_23 ( V_5 , V_305 ) ) {
F_84 ( V_5 , V_1593 ) ;
F_84 ( V_5 , V_1293 ) ;
V_5 -> V_1890 = NULL ;
}
if ( F_23 ( V_5 , V_60 ) ) {
V_2555 |= V_1384 |
V_1385 |
V_1386 ;
F_15 ( V_5 -> V_12 , V_1243 ,
V_2555 ) ;
F_34 ( V_5 ) ;
}
V_5 -> V_22 = V_2610 | V_2366 ;
if ( F_30 ( V_5 ) == V_536 ||
F_23 ( V_5 , V_643 ) )
V_5 -> V_22 |= ( V_538 |
V_539 ) ;
else if ( F_30 ( V_5 ) == V_640 )
V_5 -> V_22 |= V_549 ;
if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_1402 ||
F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_22 |= V_1685 ;
if ( V_5 -> V_12 -> V_543 == V_544 ||
V_5 -> V_12 -> V_543 == V_545 ) {
V_5 -> V_22 |= V_1685 ;
if ( F_23 ( V_5 , V_532 ) )
V_5 -> V_22 |= V_540 |
V_542 ;
}
if ( F_30 ( V_5 ) == V_765 )
V_5 -> V_22 |=
F_33 ( V_136 ) & V_1685 ;
F_146 ( V_5 ) ;
if ( V_5 -> V_111 -> V_1201 > V_1328 && ! F_23 ( V_5 , 5780_CLASS ) )
F_82 ( V_5 , V_1340 ) ;
if ( F_30 ( V_5 ) == V_536 ||
F_76 ( V_5 ) == V_757 ||
F_76 ( V_5 ) == V_758 ||
F_76 ( V_5 ) == V_2611 ) {
F_84 ( V_5 , V_705 ) ;
} else {
F_82 ( V_5 , V_705 ) ;
}
if ( F_30 ( V_5 ) == V_36 )
V_5 -> V_178 |= V_179 ;
if ( F_30 ( V_5 ) == V_536 ||
( F_30 ( V_5 ) == V_501 &&
( F_76 ( V_5 ) != V_1425 ) &&
( F_76 ( V_5 ) != V_1697 ) ) ||
( V_5 -> V_178 & V_179 ) ||
( V_5 -> V_178 & V_357 ) )
V_5 -> V_178 |= V_423 ;
if ( F_144 ( V_5 ) == V_2612 ||
F_144 ( V_5 ) == V_2613 )
V_5 -> V_178 |= V_514 ;
if ( F_76 ( V_5 ) == V_916 )
V_5 -> V_178 |= V_515 ;
if ( F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) != V_256 &&
F_30 ( V_5 ) != V_1402 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_1500 ||
F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_45 ) {
if ( V_5 -> V_12 -> V_543 != V_2614 &&
V_5 -> V_12 -> V_543 != V_2615 )
V_5 -> V_178 |= V_517 ;
if ( V_5 -> V_12 -> V_543 == V_2616 )
V_5 -> V_178 |= V_518 ;
} else
V_5 -> V_178 |= V_516 ;
}
if ( F_30 ( V_5 ) == V_413 &&
F_144 ( V_5 ) != V_503 ) {
V_5 -> V_426 = F_607 ( V_5 ) ;
if ( V_5 -> V_426 == 0 )
V_5 -> V_426 = V_2617 ;
}
if ( F_23 ( V_5 , V_152 ) )
V_5 -> V_164 = V_2618 ;
else
V_5 -> V_164 = V_2619 ;
V_5 -> V_127 = 0 ;
if ( F_144 ( V_5 ) != V_2620 &&
F_144 ( V_5 ) != V_2592 )
V_5 -> V_127 |= V_2621 ;
if ( F_30 ( V_5 ) == V_476 ||
F_76 ( V_5 ) == V_1611 ||
F_76 ( V_5 ) == V_1612 ) {
V_5 -> V_127 |= V_2622 ;
V_5 -> V_644 |= V_2623 ;
}
if ( F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1402 )
F_82 ( V_5 , V_263 ) ;
V_75 = F_75 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_7 = F_33 ( V_646 ) ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_765 )
V_7 &= ( V_2624 |
V_2625 |
V_2626 |
V_2627 |
V_1579 ) ;
else
V_7 &= V_1579 ;
F_46 ( V_646 , V_7 | V_5 -> V_644 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
F_19 ( V_5 -> V_12 , V_1243 ,
& V_2555 ) ;
if ( ( V_2555 & V_2590 ) == 0 &&
! F_23 ( V_5 , V_25 ) ) {
if ( F_76 ( V_5 ) == V_757 ||
F_76 ( V_5 ) == V_758 ||
F_76 ( V_5 ) == V_2611 ||
F_76 ( V_5 ) == V_2628 ) {
void T_2 * V_2629 ;
V_2629 = V_5 -> V_8 + V_2630 + V_37 ;
F_8 ( 0x00000000 , V_2629 ) ;
F_8 ( 0x00000000 , V_2629 + 4 ) ;
F_8 ( 0xffffffff , V_2629 + 4 ) ;
if ( F_10 ( V_2629 ) != 0x00000000 )
F_82 ( V_5 , V_25 ) ;
}
}
F_24 ( 50 ) ;
F_601 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_667 &&
! F_23 ( V_5 , V_681 ) )
V_5 -> V_1890 = NULL ;
V_2550 = F_33 ( V_497 ) ;
V_2550 &= V_2551 ;
if ( F_30 ( V_5 ) == V_501 &&
( V_2550 == V_2631 ||
V_2550 == V_2632 ) )
F_82 ( V_5 , V_1641 ) ;
if ( ! F_23 ( V_5 , V_1641 ) &&
F_30 ( V_5 ) != V_536 )
F_82 ( V_5 , V_133 ) ;
if ( F_23 ( V_5 , V_133 ) ) {
V_5 -> V_127 |= ( V_2633 |
V_2634 ) ;
V_5 -> V_120 |= V_2635 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
}
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_365 = V_728 | V_729 ;
else
V_5 -> V_365 = 0 ;
if ( F_628 ( V_5 , V_2549 ) )
V_5 -> V_178 |= V_390 ;
V_75 = F_609 ( V_5 ) ;
if ( V_75 ) {
F_115 ( & V_5 -> V_12 -> V_111 , L_106 , V_75 ) ;
F_83 ( V_5 ) ;
}
F_611 ( V_5 ) ;
F_622 ( V_5 ) ;
if ( V_5 -> V_178 & V_567 ) {
V_5 -> V_178 &= ~ V_815 ;
} else {
if ( F_30 ( V_5 ) == V_536 )
V_5 -> V_178 |= V_815 ;
else
V_5 -> V_178 &= ~ V_815 ;
}
if ( F_30 ( V_5 ) == V_536 )
F_82 ( V_5 , V_142 ) ;
else
F_84 ( V_5 , V_142 ) ;
if ( V_5 -> V_12 -> V_2370 == V_2410 &&
F_30 ( V_5 ) == V_537 &&
! ( V_5 -> V_178 & V_567 ) ) {
V_5 -> V_178 |= V_815 ;
F_82 ( V_5 , V_142 ) ;
}
if ( V_5 -> V_178 & V_567 )
F_82 ( V_5 , V_143 ) ;
else
F_84 ( V_5 , V_143 ) ;
V_5 -> V_2636 = V_2637 + V_2638 ;
V_5 -> V_2639 = V_2640 ;
if ( F_30 ( V_5 ) == V_537 &&
F_23 ( V_5 , V_839 ) ) {
V_5 -> V_2636 = V_2637 ;
#ifndef F_637
V_5 -> V_2639 = ~ ( T_3 ) 0 ;
#endif
}
V_5 -> V_1140 = F_455 ( V_5 ) - 1 ;
V_5 -> V_1145 = F_454 ( V_5 ) - 1 ;
V_5 -> V_1208 = F_623 ( V_5 ) - 1 ;
V_5 -> V_1207 = V_5 -> V_1140 + 1 ;
if ( F_30 ( V_5 ) == V_1498 ||
F_30 ( V_5 ) == V_640 ||
F_30 ( V_5 ) == V_1487 )
V_5 -> V_1207 = 8 ;
if ( F_23 ( V_5 , V_972 ) )
V_5 -> V_975 = F_33 ( V_973 ) &
V_974 ;
return V_75 ;
}
static int F_638 ( struct V_4 * V_5 )
{
struct V_362 * V_111 = V_5 -> V_111 ;
struct V_1788 * V_12 = V_5 -> V_12 ;
struct V_2641 * V_2021 = F_639 ( V_12 ) ;
const unsigned char * V_184 ;
int V_74 ;
V_184 = F_640 ( V_2021 , L_107 , & V_74 ) ;
if ( V_184 && V_74 == 6 ) {
memcpy ( V_111 -> V_688 , V_184 , 6 ) ;
return 0 ;
}
return - V_82 ;
}
static int F_641 ( struct V_4 * V_5 )
{
struct V_362 * V_111 = V_5 -> V_111 ;
memcpy ( V_111 -> V_688 , V_2642 -> V_2643 , 6 ) ;
return 0 ;
}
static int F_642 ( struct V_4 * V_5 )
{
struct V_362 * V_111 = V_5 -> V_111 ;
T_1 V_2644 , V_2645 , V_2646 ;
int V_2647 = 0 ;
int V_75 ;
#ifdef F_643
if ( ! F_638 ( V_5 ) )
return 0 ;
#endif
if ( F_23 ( V_5 , V_322 ) ) {
V_75 = F_644 ( V_5 -> V_12 , & V_111 -> V_688 [ 0 ] ) ;
if ( ! V_75 && F_431 ( & V_111 -> V_688 [ 0 ] ) )
return 0 ;
}
V_2646 = 0x7c ;
if ( F_30 ( V_5 ) == V_500 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_33 ( V_918 ) & V_919 )
V_2646 = 0xcc ;
if ( F_156 ( V_5 ) )
F_31 ( V_607 , V_2648 ) ;
else
F_157 ( V_5 ) ;
} else if ( F_23 ( V_5 , 5717_PLUS ) ) {
if ( V_5 -> V_54 & 1 )
V_2646 = 0xcc ;
if ( V_5 -> V_54 > 1 )
V_2646 += 0x18c ;
} else if ( F_30 ( V_5 ) == V_36 )
V_2646 = 0x10 ;
F_32 ( V_5 , V_2649 , & V_2644 ) ;
if ( ( V_2644 >> 16 ) == 0x484b ) {
V_111 -> V_688 [ 0 ] = ( V_2644 >> 8 ) & 0xff ;
V_111 -> V_688 [ 1 ] = ( V_2644 >> 0 ) & 0xff ;
F_32 ( V_5 , V_2650 , & V_2645 ) ;
V_111 -> V_688 [ 2 ] = ( V_2645 >> 24 ) & 0xff ;
V_111 -> V_688 [ 3 ] = ( V_2645 >> 16 ) & 0xff ;
V_111 -> V_688 [ 4 ] = ( V_2645 >> 8 ) & 0xff ;
V_111 -> V_688 [ 5 ] = ( V_2645 >> 0 ) & 0xff ;
V_2647 = F_431 ( & V_111 -> V_688 [ 0 ] ) ;
}
if ( ! V_2647 ) {
if ( ! F_23 ( V_5 , V_681 ) &&
! F_167 ( V_5 , V_2646 + 0 , & V_2644 ) &&
! F_167 ( V_5 , V_2646 + 4 , & V_2645 ) ) {
memcpy ( & V_111 -> V_688 [ 0 ] , ( ( char * ) & V_2644 ) + 2 , 2 ) ;
memcpy ( & V_111 -> V_688 [ 2 ] , ( char * ) & V_2645 , sizeof( V_2645 ) ) ;
}
else {
V_2644 = F_33 ( V_689 ) ;
V_2645 = F_33 ( V_690 ) ;
V_111 -> V_688 [ 5 ] = V_2645 & 0xff ;
V_111 -> V_688 [ 4 ] = ( V_2645 >> 8 ) & 0xff ;
V_111 -> V_688 [ 3 ] = ( V_2645 >> 16 ) & 0xff ;
V_111 -> V_688 [ 2 ] = ( V_2645 >> 24 ) & 0xff ;
V_111 -> V_688 [ 1 ] = V_2644 & 0xff ;
V_111 -> V_688 [ 0 ] = ( V_2644 >> 8 ) & 0xff ;
}
}
if ( ! F_431 ( & V_111 -> V_688 [ 0 ] ) ) {
#ifdef F_643
if ( ! F_641 ( V_5 ) )
return 0 ;
#endif
return - V_64 ;
}
return 0 ;
}
static T_1 F_645 ( struct V_4 * V_5 , T_1 V_7 )
{
int V_2651 ;
T_4 V_2652 ;
int V_2653 ;
F_634 ( V_5 -> V_12 , V_1387 , & V_2652 ) ;
if ( V_2652 == 0 )
V_2651 = 1024 ;
else
V_2651 = ( int ) V_2652 * 4 ;
if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 &&
! F_23 ( V_5 , V_1081 ) )
goto V_502;
#if F_356 ( V_2654 ) || F_356 ( V_2655 ) || F_356 ( V_2656 )
V_2653 = V_2657 ;
#else
#if F_356 ( V_2658 ) || F_356 ( V_2659 )
V_2653 = V_2660 ;
#else
V_2653 = 0 ;
#endif
#endif
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = V_2653 ? 0 : V_1570 ;
goto V_502;
}
if ( ! V_2653 )
goto V_502;
if ( F_23 ( V_5 , V_839 ) && ! F_23 ( V_5 , V_1081 ) ) {
switch ( V_2651 ) {
case 16 :
case 32 :
case 64 :
case 128 :
if ( V_2653 == V_2660 ) {
V_7 |= ( V_2661 |
V_2662 ) ;
} else {
V_7 |= ( V_2663 |
V_2664 ) ;
}
break;
case 256 :
V_7 |= ( V_2665 |
V_2666 ) ;
break;
default:
V_7 |= ( V_2663 |
V_2664 ) ;
break;
}
} else if ( F_23 ( V_5 , V_1081 ) ) {
switch ( V_2651 ) {
case 16 :
case 32 :
case 64 :
if ( V_2653 == V_2660 ) {
V_7 &= ~ V_2667 ;
V_7 |= V_2668 ;
break;
}
case 128 :
default:
V_7 &= ~ V_2667 ;
V_7 |= V_2669 ;
break;
}
} else {
switch ( V_2651 ) {
case 16 :
if ( V_2653 == V_2660 ) {
V_7 |= ( V_2670 |
V_2671 ) ;
break;
}
case 32 :
if ( V_2653 == V_2660 ) {
V_7 |= ( V_2672 |
V_2673 ) ;
break;
}
case 64 :
if ( V_2653 == V_2660 ) {
V_7 |= ( V_2674 |
V_2675 ) ;
break;
}
case 128 :
if ( V_2653 == V_2660 ) {
V_7 |= ( V_2676 |
V_2677 ) ;
break;
}
case 256 :
V_7 |= ( V_2678 |
V_2679 ) ;
break;
case 512 :
V_7 |= ( V_2680 |
V_2681 ) ;
break;
case 1024 :
default:
V_7 |= ( V_2682 |
V_2683 ) ;
break;
}
}
V_502:
return V_7 ;
}
static int F_646 ( struct V_4 * V_5 , T_1 * V_626 , T_9 V_2684 ,
int V_634 , bool V_2685 )
{
struct V_2686 V_2687 ;
T_1 V_2688 ;
int V_42 , V_56 ;
V_2688 = V_1590 ;
F_46 ( V_2689 , 0 ) ;
F_46 ( V_2690 , 0 ) ;
F_46 ( V_1234 , 0 ) ;
F_46 ( V_1235 , 0 ) ;
F_46 ( V_1066 , 0 ) ;
F_46 ( V_1076 , 0 ) ;
V_2687 . V_1150 = ( ( T_6 ) V_2684 ) >> 32 ;
V_2687 . V_1151 = V_2684 & 0xffffffff ;
V_2687 . V_2691 = 0x00002100 ;
V_2687 . V_74 = V_634 ;
if ( V_2685 ) {
V_2687 . V_2692 = ( 13 << 8 ) | 2 ;
F_31 ( V_1067 , V_1371 ) ;
F_24 ( 40 ) ;
} else {
V_2687 . V_2692 = ( 16 << 8 ) | 7 ;
F_31 ( V_1068 , V_1375 ) ;
F_24 ( 40 ) ;
}
V_2687 . V_10 = 0x00000005 ;
for ( V_42 = 0 ; V_42 < ( sizeof( V_2687 ) / sizeof( T_1 ) ) ; V_42 ++ ) {
T_1 V_7 ;
V_7 = * ( ( ( T_1 * ) & V_2687 ) + V_42 ) ;
F_15 ( V_5 -> V_12 , V_40 ,
V_2688 + ( V_42 * sizeof( T_1 ) ) ) ;
F_15 ( V_5 -> V_12 , V_41 , V_7 ) ;
}
F_15 ( V_5 -> V_12 , V_40 , 0 ) ;
if ( V_2685 )
F_46 ( V_2693 , V_2688 ) ;
else
F_46 ( V_2694 , V_2688 ) ;
V_56 = - V_82 ;
for ( V_42 = 0 ; V_42 < 40 ; V_42 ++ ) {
T_1 V_7 ;
if ( V_2685 )
V_7 = F_33 ( V_2689 ) ;
else
V_7 = F_33 ( V_2690 ) ;
if ( ( V_7 & 0xffff ) == V_2688 ) {
V_56 = 0 ;
break;
}
F_24 ( 100 ) ;
}
return V_56 ;
}
static int F_647 ( struct V_4 * V_5 )
{
T_9 V_2684 ;
T_1 * V_626 , V_2695 ;
int V_56 = 0 ;
V_626 = F_404 ( & V_5 -> V_12 -> V_111 , V_2696 ,
& V_2684 , V_632 ) ;
if ( ! V_626 ) {
V_56 = - V_264 ;
goto V_2697;
}
V_5 -> V_1573 = ( ( 0x7 << V_2698 ) |
( 0x6 << V_2699 ) ) ;
V_5 -> V_1573 = F_645 ( V_5 , V_5 -> V_1573 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
goto V_502;
if ( F_23 ( V_5 , V_1081 ) ) {
V_5 -> V_1573 |= 0x00180000 ;
} else if ( ! F_23 ( V_5 , V_839 ) ) {
if ( F_30 ( V_5 ) == V_501 ||
F_30 ( V_5 ) == V_1498 )
V_5 -> V_1573 |= 0x003f0000 ;
else
V_5 -> V_1573 |= 0x003f000f ;
} else {
if ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 ) {
T_1 V_2700 = ( F_33 ( V_153 ) & 0x1f ) ;
T_1 V_2701 = 0x7 ;
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) &&
F_30 ( V_5 ) == V_500 )
V_5 -> V_1573 |= 0x8000 ;
else if ( V_2700 == 0x6 || V_2700 == 0x7 )
V_5 -> V_1573 |= V_2702 ;
if ( F_30 ( V_5 ) == V_499 )
V_2701 = 4 ;
V_5 -> V_1573 |=
( V_2701 << V_2703 ) |
( 0x3 << V_2704 ) |
( 1 << 23 ) ;
} else if ( F_30 ( V_5 ) == V_566 ) {
V_5 -> V_1573 |= 0x00144000 ;
} else if ( F_30 ( V_5 ) == V_548 ) {
V_5 -> V_1573 |= 0x00148000 ;
} else {
V_5 -> V_1573 |= 0x001b000f ;
}
}
if ( F_23 ( V_5 , V_2705 ) )
V_5 -> V_1573 |= V_2702 ;
if ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 )
V_5 -> V_1573 &= 0xfffffff0 ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) {
V_5 -> V_1573 |= V_2706 ;
V_5 -> V_1573 |= V_2707 ;
}
F_46 ( V_1569 , V_5 -> V_1573 ) ;
#if 0
tg3_switch_clocks(tp);
#endif
if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 )
goto V_502;
V_2695 = V_5 -> V_1573 ;
V_5 -> V_1573 &= ~ V_2708 ;
F_46 ( V_1569 , V_5 -> V_1573 ) ;
while ( 1 ) {
T_1 * V_1439 = V_626 , V_42 ;
for ( V_42 = 0 ; V_42 < V_2696 / sizeof( T_1 ) ; V_42 ++ )
V_1439 [ V_42 ] = V_42 ;
V_56 = F_646 ( V_5 , V_626 , V_2684 , V_2696 , true ) ;
if ( V_56 ) {
F_115 ( & V_5 -> V_12 -> V_111 ,
L_108 ,
V_657 , V_56 ) ;
break;
}
#if 0
for (i = 0; i < TEST_BUFFER_SIZE / sizeof(u32); i++) {
u32 val;
tg3_read_mem(tp, 0x2100 + (i*4), &val);
if (le32_to_cpu(val) != p[i]) {
dev_err(&tp->pdev->dev,
"%s: Buffer corrupted on device! "
"(%d != %d)\n", __func__, val, i);
}
p[i] = 0;
}
#endif
V_56 = F_646 ( V_5 , V_626 , V_2684 , V_2696 , false ) ;
if ( V_56 ) {
F_115 ( & V_5 -> V_12 -> V_111 , L_109
L_110 , V_657 , V_56 ) ;
break;
}
for ( V_42 = 0 ; V_42 < V_2696 / sizeof( T_1 ) ; V_42 ++ ) {
if ( V_1439 [ V_42 ] == V_42 )
continue;
if ( ( V_5 -> V_1573 & V_2708 ) !=
V_2671 ) {
V_5 -> V_1573 &= ~ V_2708 ;
V_5 -> V_1573 |= V_2671 ;
F_46 ( V_1569 , V_5 -> V_1573 ) ;
break;
} else {
F_115 ( & V_5 -> V_12 -> V_111 ,
L_111
L_112 , V_657 , V_1439 [ V_42 ] , V_42 ) ;
V_56 = - V_82 ;
goto V_502;
}
}
if ( V_42 == ( V_2696 / sizeof( T_1 ) ) ) {
V_56 = 0 ;
break;
}
}
if ( ( V_5 -> V_1573 & V_2708 ) !=
V_2671 ) {
if ( F_633 ( V_2709 ) ) {
V_5 -> V_1573 &= ~ V_2708 ;
V_5 -> V_1573 |= V_2671 ;
} else {
V_5 -> V_1573 = V_2695 ;
}
F_46 ( V_1569 , V_5 -> V_1573 ) ;
}
V_502:
F_402 ( & V_5 -> V_12 -> V_111 , V_2696 , V_626 , V_2684 ) ;
V_2697:
return V_56 ;
}
static void F_648 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_5 -> V_1596 . V_1597 =
V_2710 ;
V_5 -> V_1596 . V_1599 =
V_2711 ;
V_5 -> V_1596 . V_1601 =
V_2712 ;
V_5 -> V_1596 . V_1602 =
V_2710 ;
V_5 -> V_1596 . V_1603 =
V_2713 ;
V_5 -> V_1596 . V_1604 =
V_2714 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_5 -> V_1596 . V_1597 =
V_2710 ;
V_5 -> V_1596 . V_1599 =
V_2715 ;
V_5 -> V_1596 . V_1601 =
V_2716 ;
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_1596 . V_1599 =
V_2717 ;
V_5 -> V_1596 . V_1601 =
V_2718 ;
}
V_5 -> V_1596 . V_1602 =
V_2719 ;
V_5 -> V_1596 . V_1603 =
V_2720 ;
V_5 -> V_1596 . V_1604 =
V_2721 ;
} else {
V_5 -> V_1596 . V_1597 =
V_2722 ;
V_5 -> V_1596 . V_1599 =
V_2723 ;
V_5 -> V_1596 . V_1601 =
V_2724 ;
V_5 -> V_1596 . V_1602 =
V_2725 ;
V_5 -> V_1596 . V_1603 =
V_2726 ;
V_5 -> V_1596 . V_1604 =
V_2727 ;
}
V_5 -> V_1596 . V_1606 = V_2728 ;
V_5 -> V_1596 . V_1608 = V_2729 ;
}
static char * F_649 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_215 & V_398 ) {
case V_2730 : return L_113 ;
case V_399 : return L_114 ;
case V_565 : return L_115 ;
case V_2731 : return L_116 ;
case V_2732 : return L_117 ;
case V_2733 : return L_118 ;
case V_2734 : return L_119 ;
case V_2735 : return L_120 ;
case V_2736 : return L_121 ;
case V_2737 : return L_122 ;
case V_2738 : return L_123 ;
case V_2739 : return L_124 ;
case V_2740 : return L_125 ;
case V_2741 : return L_126 ;
case V_2742 : return L_127 ;
case V_2743 : return L_128 ;
case V_2744 : return L_129 ;
case V_2745 : return L_130 ;
case V_2746 : return L_131 ;
case V_2747 : return L_132 ;
case V_2748 : return L_133 ;
case V_2749 : return L_134 ;
case V_2750 : return L_135 ;
case V_939 : return L_136 ;
case 0 : return L_137 ;
default: return L_138 ;
}
}
static char * F_650 ( struct V_4 * V_5 , char * V_2751 )
{
if ( F_23 ( V_5 , V_1081 ) ) {
strcpy ( V_2751 , L_139 ) ;
return V_2751 ;
} else if ( F_23 ( V_5 , V_839 ) ) {
T_1 V_150 = F_33 ( V_153 ) & 0x1f ;
strcpy ( V_2751 , L_140 ) ;
if ( ( V_150 == 7 ) ||
( ( F_33 ( V_497 ) & V_2551 ) ==
V_2752 ) )
strcat ( V_2751 , L_141 ) ;
else if ( V_150 == 0 )
strcat ( V_2751 , L_142 ) ;
else if ( V_150 == 2 )
strcat ( V_2751 , L_143 ) ;
else if ( V_150 == 4 )
strcat ( V_2751 , L_144 ) ;
else if ( V_150 == 6 )
strcat ( V_2751 , L_145 ) ;
} else {
strcpy ( V_2751 , L_146 ) ;
if ( F_23 ( V_5 , V_840 ) )
strcat ( V_2751 , L_144 ) ;
else
strcat ( V_2751 , L_142 ) ;
}
if ( F_23 ( V_5 , V_2600 ) )
strcat ( V_2751 , L_147 ) ;
else
strcat ( V_2751 , L_148 ) ;
return V_2751 ;
}
static void F_651 ( struct V_4 * V_5 )
{
struct V_1457 * V_1458 = & V_5 -> V_970 ;
memset ( V_1458 , 0 , sizeof( * V_1458 ) ) ;
V_1458 -> V_642 = V_2753 ;
V_1458 -> V_1469 = V_2754 ;
V_1458 -> V_1460 = V_2755 ;
V_1458 -> V_1471 = V_2756 ;
V_1458 -> V_1462 = V_2757 ;
V_1458 -> V_1477 = V_2758 ;
V_1458 -> V_1479 = V_2759 ;
V_1458 -> V_1473 = V_2760 ;
V_1458 -> V_1464 = V_2761 ;
V_1458 -> V_971 = V_2762 ;
if ( V_5 -> V_127 & ( V_2633 |
V_2634 ) ) {
V_1458 -> V_1469 = V_2763 ;
V_1458 -> V_1477 = V_2764 ;
V_1458 -> V_1460 = V_2765 ;
V_1458 -> V_1479 = V_2766 ;
}
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_1458 -> V_1477 = 0 ;
V_1458 -> V_1479 = 0 ;
V_1458 -> V_971 = 0 ;
}
}
static int F_652 ( struct V_1788 * V_12 ,
const struct V_2548 * V_2549 )
{
struct V_362 * V_111 ;
struct V_4 * V_5 ;
int V_42 , V_75 ;
T_1 V_2767 , V_2768 , V_2769 ;
char V_2751 [ 40 ] ;
T_6 V_2770 , V_2771 ;
T_13 V_1192 = 0 ;
F_653 ( V_2772 L_149 , V_1973 ) ;
V_75 = F_654 ( V_12 ) ;
if ( V_75 ) {
F_115 ( & V_12 -> V_111 , L_150 ) ;
return V_75 ;
}
V_75 = F_655 ( V_12 , V_2011 ) ;
if ( V_75 ) {
F_115 ( & V_12 -> V_111 , L_151 ) ;
goto V_2773;
}
F_656 ( V_12 ) ;
V_111 = F_657 ( sizeof( * V_5 ) , V_1894 ) ;
if ( ! V_111 ) {
V_75 = - V_264 ;
goto V_2774;
}
F_658 ( V_111 , & V_12 -> V_111 ) ;
V_5 = F_109 ( V_111 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_111 = V_111 ;
V_5 -> V_352 = V_2775 ;
V_5 -> V_354 = V_2776 ;
V_5 -> V_125 = 1 ;
if ( V_2777 > 0 )
V_5 -> V_2022 = V_2777 ;
else
V_5 -> V_2022 = V_2778 ;
if ( F_659 ( V_12 ) ) {
F_82 ( V_5 , V_322 ) ;
if ( F_660 ( V_12 ) )
F_82 ( V_5 , V_30 ) ;
if ( F_661 ( V_12 ) )
F_82 ( V_5 , V_2705 ) ;
if ( F_662 ( V_12 ) )
F_82 ( V_5 , V_831 ) ;
if ( F_663 ( V_12 ) )
F_82 ( V_5 , V_833 ) ;
}
V_5 -> V_120 =
V_121 |
V_2779 |
V_2780 |
V_2781 ;
V_5 -> V_644 = ( V_2782 | V_2783 |
V_2784 ) ;
#ifdef F_664
V_5 -> V_644 |= V_2785 ;
#endif
F_665 ( & V_5 -> V_207 ) ;
F_665 ( & V_5 -> V_11 ) ;
F_666 ( & V_5 -> V_1224 , F_480 ) ;
V_5 -> V_8 = F_667 ( V_12 , V_2786 ) ;
if ( ! V_5 -> V_8 ) {
F_115 ( & V_12 -> V_111 , L_152 ) ;
V_75 = - V_264 ;
goto V_2787;
}
if ( V_5 -> V_12 -> V_543 == V_544 ||
V_5 -> V_12 -> V_543 == V_2788 ||
V_5 -> V_12 -> V_543 == V_545 ||
V_5 -> V_12 -> V_543 == V_2789 ||
V_5 -> V_12 -> V_543 == V_2466 ||
V_5 -> V_12 -> V_543 == V_2467 ||
V_5 -> V_12 -> V_543 == V_2468 ||
V_5 -> V_12 -> V_543 == V_2538 ||
V_5 -> V_12 -> V_543 == V_2539 ||
V_5 -> V_12 -> V_543 == V_2540 ||
V_5 -> V_12 -> V_543 == V_2517 ||
V_5 -> V_12 -> V_543 == V_2541 ) {
F_82 ( V_5 , V_60 ) ;
V_5 -> V_9 = F_667 ( V_12 , V_2790 ) ;
if ( ! V_5 -> V_9 ) {
F_115 ( & V_12 -> V_111 ,
L_153 ) ;
V_75 = - V_264 ;
goto V_2791;
}
}
V_5 -> V_1338 = V_2792 ;
V_5 -> V_1342 = V_2793 ;
V_111 -> V_2794 = & V_2795 ;
V_111 -> V_2796 = V_2797 ;
V_111 -> V_2798 = & V_2799 ;
V_111 -> V_276 = V_12 -> V_276 ;
V_75 = F_629 ( V_5 , V_2549 ) ;
if ( V_75 ) {
F_115 ( & V_12 -> V_111 ,
L_154 ) ;
goto V_2800;
}
if ( F_23 ( V_5 , V_1641 ) )
V_2771 = V_2770 = F_357 ( 32 ) ;
else if ( F_23 ( V_5 , 40BIT_DMA_BUG ) ) {
V_2771 = V_2770 = F_357 ( 40 ) ;
#ifdef V_1247
V_2770 = F_357 ( 64 ) ;
#endif
} else
V_2771 = V_2770 = F_357 ( 64 ) ;
if ( V_2770 > F_357 ( 32 ) ) {
V_75 = F_668 ( V_12 , V_2770 ) ;
if ( ! V_75 ) {
V_1192 |= V_2801 ;
V_75 = F_669 ( V_12 ,
V_2771 ) ;
if ( V_75 < 0 ) {
F_115 ( & V_12 -> V_111 , L_155
L_156 ) ;
goto V_2800;
}
}
}
if ( V_75 || V_2770 == F_357 ( 32 ) ) {
V_75 = F_668 ( V_12 , F_357 ( 32 ) ) ;
if ( V_75 ) {
F_115 ( & V_12 -> V_111 ,
L_157 ) ;
goto V_2800;
}
}
F_648 ( V_5 ) ;
V_1192 |= V_2802 | V_2803 ;
if ( F_76 ( V_5 ) != V_2804 ) {
V_1192 |= V_2805 | V_2806 | V_1193 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_1192 |= V_2807 ;
}
if ( ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ) &&
( V_1192 & V_2806 ) )
V_1192 |= V_1278 ;
if ( F_23 ( V_5 , V_1297 ) || F_23 ( V_5 , V_1298 ) ) {
if ( V_1192 & V_2807 )
V_1192 |= V_2808 ;
if ( F_23 ( V_5 , V_1298 ) ||
F_30 ( V_5 ) == V_45 ||
( F_30 ( V_5 ) == V_413 &&
F_144 ( V_5 ) != V_503 ) ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1402 )
V_1192 |= V_2809 ;
}
V_111 -> V_1192 |= V_1192 ;
V_111 -> V_2810 |= V_1192 ;
if ( F_30 ( V_5 ) != V_566 &&
! F_23 ( V_5 , V_152 ) )
V_1192 |= V_1327 ;
V_111 -> V_2811 |= V_1192 ;
if ( F_76 ( V_5 ) == V_1697 &&
! F_23 ( V_5 , V_1593 ) &&
! ( F_33 ( V_1243 ) & V_1640 ) ) {
F_82 ( V_5 , V_2030 ) ;
V_5 -> V_1338 = 63 ;
}
V_75 = F_642 ( V_5 ) ;
if ( V_75 ) {
F_115 ( & V_12 -> V_111 ,
L_158 ) ;
goto V_2800;
}
if ( ( F_33 ( V_138 ) & V_128 ) ||
( F_33 ( V_1068 ) & V_1375 ) ) {
F_46 ( V_1065 , V_1378 ) ;
F_427 ( V_5 , V_110 , 1 ) ;
}
V_75 = F_647 ( V_5 ) ;
if ( V_75 ) {
F_115 ( & V_12 -> V_111 , L_159 ) ;
goto V_2800;
}
V_2769 = V_20 + V_16 ;
V_2768 = V_15 + V_16 ;
V_2767 = V_2812 + V_16 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_131 -> V_5 = V_5 ;
V_131 -> V_1090 = V_2813 ;
V_131 -> V_124 = V_2769 ;
if ( V_42 <= 4 )
V_2769 += 0x8 ;
else
V_2769 += 0x4 ;
V_131 -> V_1209 = V_2768 ;
V_131 -> V_1316 = V_2767 ;
if ( V_42 )
V_131 -> V_126 = V_2814 << ( V_42 - 1 ) ;
else
V_131 -> V_126 = V_1863 ;
if ( ! F_23 ( V_5 , V_1063 ) )
break;
if ( ! V_42 )
continue;
V_2768 += 0x8 ;
if ( V_2767 & 0x4 )
V_2767 -= 0x4 ;
else
V_2767 += 0xc ;
}
F_651 ( V_5 ) ;
F_670 ( V_12 , V_111 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_765 )
F_82 ( V_5 , V_990 ) ;
F_473 ( V_5 ) ;
F_138 ( V_5 ) ;
V_75 = F_671 ( V_111 ) ;
if ( V_75 ) {
F_115 ( & V_12 -> V_111 , L_160 ) ;
goto V_2800;
}
F_96 ( V_111 , L_161 ,
V_5 -> V_2465 ,
F_76 ( V_5 ) ,
F_650 ( V_5 , V_2751 ) ,
V_111 -> V_688 ) ;
if ( V_5 -> V_178 & V_389 ) {
struct V_209 * V_210 ;
V_210 = V_5 -> V_211 -> V_212 [ V_213 ] ;
F_96 ( V_111 ,
L_162 ,
V_210 -> V_214 -> V_265 , F_113 ( & V_210 -> V_111 ) ) ;
} else {
char * V_2815 ;
if ( V_5 -> V_178 & V_390 )
V_2815 = L_163 ;
else if ( V_5 -> V_178 & V_357 )
V_2815 = L_164 ;
else
V_2815 = L_165 ;
F_96 ( V_111 , L_166
L_167 ,
F_649 ( V_5 ) , V_2815 ,
( V_5 -> V_178 & V_423 ) == 0 ,
( V_5 -> V_178 & V_336 ) != 0 ) ;
}
F_96 ( V_111 , L_168 ,
( V_111 -> V_1192 & V_1193 ) != 0 ,
F_23 ( V_5 , V_142 ) != 0 ,
( V_5 -> V_178 & V_815 ) != 0 ,
F_23 ( V_5 , V_305 ) != 0 ,
F_23 ( V_5 , V_1593 ) != 0 ) ;
F_96 ( V_111 , L_169 ,
V_5 -> V_1573 ,
V_12 -> V_2770 == F_357 ( 32 ) ? 32 :
( ( T_6 ) V_12 -> V_2770 ) == F_357 ( 40 ) ? 40 : 64 ) ;
F_672 ( V_12 ) ;
return 0 ;
V_2800:
if ( V_5 -> V_9 ) {
F_635 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
V_2791:
if ( V_5 -> V_8 ) {
F_635 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
V_2787:
F_673 ( V_111 ) ;
V_2774:
F_674 ( V_12 ) ;
V_2773:
if ( F_675 ( V_12 ) )
F_676 ( V_12 ) ;
F_670 ( V_12 , NULL ) ;
return V_75 ;
}
static void F_677 ( struct V_1788 * V_12 )
{
struct V_362 * V_111 = F_151 ( V_12 ) ;
if ( V_111 ) {
struct V_4 * V_5 = F_109 ( V_111 ) ;
F_490 ( V_5 -> V_662 ) ;
F_323 ( V_5 ) ;
if ( F_23 ( V_5 , V_263 ) ) {
F_123 ( V_5 ) ;
F_83 ( V_5 ) ;
}
F_678 ( V_111 ) ;
if ( V_5 -> V_9 ) {
F_635 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
if ( V_5 -> V_8 ) {
F_635 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
F_673 ( V_111 ) ;
F_674 ( V_12 ) ;
F_676 ( V_12 ) ;
F_670 ( V_12 , NULL ) ;
}
}
static int F_679 ( struct V_543 * V_543 )
{
struct V_1788 * V_12 = F_460 ( V_543 ) ;
struct V_362 * V_111 = F_151 ( V_12 ) ;
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_75 ;
if ( ! F_143 ( V_111 ) )
return 0 ;
F_323 ( V_5 ) ;
F_121 ( V_5 ) ;
F_338 ( V_5 ) ;
F_476 ( V_5 ) ;
F_238 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_239 ( V_5 ) ;
F_680 ( V_111 ) ;
F_238 ( V_5 , 0 ) ;
F_427 ( V_5 , V_110 , 1 ) ;
F_84 ( V_5 , V_562 ) ;
F_239 ( V_5 ) ;
V_75 = F_196 ( V_5 ) ;
if ( V_75 ) {
int V_759 ;
F_238 ( V_5 , 0 ) ;
F_82 ( V_5 , V_562 ) ;
V_759 = F_478 ( V_5 , true ) ;
if ( V_759 )
goto V_502;
F_475 ( V_5 ) ;
F_681 ( V_111 ) ;
F_340 ( V_5 ) ;
V_502:
F_239 ( V_5 ) ;
if ( ! V_759 )
F_118 ( V_5 ) ;
}
return V_75 ;
}
static int F_682 ( struct V_543 * V_543 )
{
struct V_1788 * V_12 = F_460 ( V_543 ) ;
struct V_362 * V_111 = F_151 ( V_12 ) ;
struct V_4 * V_5 = F_109 ( V_111 ) ;
int V_75 ;
if ( ! F_143 ( V_111 ) )
return 0 ;
F_681 ( V_111 ) ;
F_238 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_82 ( V_5 , V_562 ) ;
V_75 = F_478 ( V_5 ,
! ( V_5 -> V_178 & V_569 ) ) ;
if ( V_75 )
goto V_502;
F_475 ( V_5 ) ;
F_340 ( V_5 ) ;
V_502:
F_239 ( V_5 ) ;
if ( ! V_75 )
F_118 ( V_5 ) ;
return V_75 ;
}
static void F_683 ( struct V_1788 * V_12 )
{
struct V_362 * V_111 = F_151 ( V_12 ) ;
struct V_4 * V_5 = F_109 ( V_111 ) ;
F_684 () ;
F_680 ( V_111 ) ;
if ( F_143 ( V_111 ) )
F_479 ( V_111 ) ;
if ( V_2816 == V_2817 )
F_199 ( V_5 ) ;
F_685 () ;
}
static T_19 F_686 ( struct V_1788 * V_12 ,
T_20 V_846 )
{
struct V_362 * V_1789 = F_151 ( V_12 ) ;
struct V_4 * V_5 = F_109 ( V_1789 ) ;
T_19 V_75 = V_2818 ;
F_96 ( V_1789 , L_170 ) ;
F_684 () ;
if ( ! V_1789 || ! F_143 ( V_1789 ) )
goto V_186;
F_121 ( V_5 ) ;
F_338 ( V_5 ) ;
F_476 ( V_5 ) ;
F_323 ( V_5 ) ;
F_680 ( V_1789 ) ;
F_238 ( V_5 , 0 ) ;
F_427 ( V_5 , V_110 , 0 ) ;
F_239 ( V_5 ) ;
V_186:
if ( V_846 == V_2819 ) {
if ( V_1789 ) {
F_332 ( V_5 ) ;
F_479 ( V_1789 ) ;
}
V_75 = V_2820 ;
} else {
F_676 ( V_12 ) ;
}
F_685 () ;
return V_75 ;
}
static T_19 F_687 ( struct V_1788 * V_12 )
{
struct V_362 * V_1789 = F_151 ( V_12 ) ;
struct V_4 * V_5 = F_109 ( V_1789 ) ;
T_19 V_628 = V_2820 ;
int V_75 ;
F_684 () ;
if ( F_654 ( V_12 ) ) {
F_115 ( & V_12 -> V_111 ,
L_171 ) ;
goto V_186;
}
F_656 ( V_12 ) ;
F_688 ( V_12 ) ;
F_672 ( V_12 ) ;
if ( ! V_1789 || ! F_143 ( V_1789 ) ) {
V_628 = V_2821 ;
goto V_186;
}
V_75 = F_194 ( V_5 ) ;
if ( V_75 )
goto V_186;
V_628 = V_2821 ;
V_186:
if ( V_628 != V_2821 && V_1789 && F_143 ( V_1789 ) ) {
F_332 ( V_5 ) ;
F_479 ( V_1789 ) ;
}
F_685 () ;
return V_628 ;
}
static void F_689 ( struct V_1788 * V_12 )
{
struct V_362 * V_1789 = F_151 ( V_12 ) ;
struct V_4 * V_5 = F_109 ( V_1789 ) ;
int V_75 ;
F_684 () ;
if ( ! F_143 ( V_1789 ) )
goto V_186;
F_238 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_82 ( V_5 , V_562 ) ;
V_75 = F_478 ( V_5 , true ) ;
if ( V_75 ) {
F_239 ( V_5 ) ;
F_183 ( V_1789 , L_172 ) ;
goto V_186;
}
F_681 ( V_1789 ) ;
F_475 ( V_5 ) ;
F_340 ( V_5 ) ;
F_239 ( V_5 ) ;
F_118 ( V_5 ) ;
V_186:
F_685 () ;
}
