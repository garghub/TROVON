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
static int F_67 ( struct V_4 * V_5 , int V_161 , T_1 V_7 )
{
return F_59 ( V_5 , V_199 ,
V_161 | V_7 | V_200 ) ;
}
static int F_68 ( struct V_4 * V_5 )
{
T_1 V_201 ;
int V_202 , V_75 ;
V_201 = V_203 ;
V_75 = F_59 ( V_5 , V_204 , V_201 ) ;
if ( V_75 != 0 )
return - V_67 ;
V_202 = 5000 ;
while ( V_202 -- ) {
V_75 = F_57 ( V_5 , V_204 , & V_201 ) ;
if ( V_75 != 0 )
return - V_67 ;
if ( ( V_201 & V_203 ) == 0 ) {
F_24 ( 40 ) ;
break;
}
F_24 ( 10 ) ;
}
if ( V_202 < 0 )
return - V_67 ;
return 0 ;
}
static int F_69 ( struct V_205 * V_206 , int V_207 , int V_161 )
{
struct V_4 * V_5 = V_206 -> V_208 ;
T_1 V_7 ;
F_70 ( & V_5 -> V_209 ) ;
if ( F_56 ( V_5 , V_207 , V_161 , & V_7 ) )
V_7 = - V_210 ;
F_71 ( & V_5 -> V_209 ) ;
return V_7 ;
}
static int F_72 ( struct V_205 * V_206 , int V_207 , int V_161 , T_3 V_7 )
{
struct V_4 * V_5 = V_206 -> V_208 ;
T_1 V_56 = 0 ;
F_70 ( & V_5 -> V_209 ) ;
if ( F_58 ( V_5 , V_207 , V_161 , V_7 ) )
V_56 = - V_210 ;
F_71 ( & V_5 -> V_209 ) ;
return V_56 ;
}
static int F_73 ( struct V_205 * V_206 )
{
return 0 ;
}
static void F_74 ( struct V_4 * V_5 )
{
T_1 V_7 ;
struct V_211 * V_212 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
switch ( V_212 -> V_215 -> V_216 & V_212 -> V_215 -> V_217 ) {
case V_218 :
case V_219 :
V_7 = V_220 ;
break;
case V_221 :
V_7 = V_222 ;
break;
case V_223 :
V_7 = V_224 ;
break;
case V_225 :
V_7 = V_226 ;
break;
default:
return;
}
if ( V_212 -> V_227 != V_228 ) {
F_46 ( V_229 , V_7 ) ;
V_7 = F_33 ( V_230 ) ;
V_7 &= ~ ( V_231 |
V_232 | V_233 ) ;
V_7 |= V_234 | V_235 ;
F_46 ( V_230 , V_7 ) ;
return;
}
if ( ! F_23 ( V_5 , V_236 ) )
V_7 |= V_237 |
V_238 |
V_239 |
V_240 |
V_241 |
V_242 ;
F_46 ( V_229 , V_7 ) ;
V_7 = F_33 ( V_230 ) ;
V_7 &= ~ ( V_232 | V_233 |
V_243 | V_244 ) ;
if ( ! F_23 ( V_5 , V_236 ) ) {
if ( F_23 ( V_5 , V_245 ) )
V_7 |= V_243 ;
if ( F_23 ( V_5 , V_246 ) )
V_7 |= V_244 ;
}
V_7 |= V_234 | V_235 |
V_231 | V_247 ;
F_46 ( V_230 , V_7 ) ;
V_7 = F_33 ( V_248 ) ;
V_7 &= ~ ( V_249 |
V_250 |
V_251 |
V_252 |
V_253 |
V_254 |
V_255 ) ;
if ( ! F_23 ( V_5 , V_236 ) ) {
if ( F_23 ( V_5 , V_245 ) )
V_7 |= V_249 |
V_250 |
V_251 |
V_252 ;
if ( F_23 ( V_5 , V_246 ) )
V_7 |= V_253 |
V_254 |
V_255 ;
}
F_46 ( V_248 , V_7 ) ;
}
static void F_75 ( struct V_4 * V_5 )
{
V_5 -> V_164 &= ~ V_165 ;
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
if ( F_23 ( V_5 , V_256 ) &&
F_30 ( V_5 ) == V_257 )
F_74 ( V_5 ) ;
}
static int F_76 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_161 ;
struct V_211 * V_212 ;
if ( F_23 ( V_5 , 5717_PLUS ) ) {
T_1 V_258 ;
V_5 -> V_160 = V_5 -> V_54 + 1 ;
if ( F_77 ( V_5 ) != V_259 )
V_258 = F_33 ( V_260 ) & V_261 ;
else
V_258 = F_33 ( V_262 ) &
V_263 ;
if ( V_258 )
V_5 -> V_160 += 7 ;
} else if ( F_23 ( V_5 , V_264 ) && F_23 ( V_5 , V_265 ) ) {
int V_184 ;
V_184 = F_78 ( V_5 -> V_12 ) ;
if ( V_184 < 0 )
return V_184 ;
V_5 -> V_160 = V_184 ;
} else
V_5 -> V_160 = V_266 ;
F_75 ( V_5 ) ;
if ( ! F_23 ( V_5 , V_267 ) || F_23 ( V_5 , V_256 ) )
return 0 ;
V_5 -> V_213 = F_79 () ;
if ( V_5 -> V_213 == NULL )
return - V_268 ;
V_5 -> V_213 -> V_269 = L_1 ;
snprintf ( V_5 -> V_213 -> V_270 , V_271 , L_2 ,
( V_5 -> V_12 -> V_272 -> V_273 << 8 ) | V_5 -> V_12 -> V_274 ) ;
V_5 -> V_213 -> V_208 = V_5 ;
V_5 -> V_213 -> V_275 = & V_5 -> V_12 -> V_111 ;
V_5 -> V_213 -> V_276 = & F_69 ;
V_5 -> V_213 -> V_277 = & F_72 ;
V_5 -> V_213 -> V_278 = & F_73 ;
V_5 -> V_213 -> V_279 = ~ ( 1 << V_5 -> V_160 ) ;
V_5 -> V_213 -> V_280 = & V_5 -> V_281 [ 0 ] ;
for ( V_42 = 0 ; V_42 < V_282 ; V_42 ++ )
V_5 -> V_213 -> V_280 [ V_42 ] = V_283 ;
if ( F_57 ( V_5 , V_204 , & V_161 ) || ( V_161 & V_284 ) )
F_68 ( V_5 ) ;
V_42 = F_80 ( V_5 -> V_213 ) ;
if ( V_42 ) {
F_81 ( & V_5 -> V_12 -> V_111 , L_3 , V_42 ) ;
F_82 ( V_5 -> V_213 ) ;
return V_42 ;
}
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
if ( ! V_212 || ! V_212 -> V_215 ) {
F_81 ( & V_5 -> V_12 -> V_111 , L_4 ) ;
F_83 ( V_5 -> V_213 ) ;
F_82 ( V_5 -> V_213 ) ;
return - V_82 ;
}
switch ( V_212 -> V_215 -> V_216 & V_212 -> V_215 -> V_217 ) {
case V_285 :
V_212 -> V_227 = V_286 ;
V_212 -> V_287 |= V_288 ;
break;
case V_218 :
case V_219 :
V_212 -> V_287 |= V_289 |
V_290 |
V_291 |
V_288 ;
if ( F_23 ( V_5 , V_236 ) )
V_212 -> V_287 |= V_292 ;
if ( F_23 ( V_5 , V_245 ) )
V_212 -> V_287 |= V_293 ;
if ( F_23 ( V_5 , V_246 ) )
V_212 -> V_287 |= V_294 ;
case V_223 :
V_212 -> V_227 = V_228 ;
break;
case V_225 :
case V_221 :
V_212 -> V_227 = V_295 ;
V_212 -> V_287 |= V_288 ;
V_5 -> V_178 |= V_179 ;
break;
}
F_84 ( V_5 , V_256 ) ;
if ( F_30 ( V_5 ) == V_257 )
F_74 ( V_5 ) ;
return 0 ;
}
static void F_85 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_256 ) ) {
F_86 ( V_5 , V_256 ) ;
F_83 ( V_5 -> V_213 ) ;
F_82 ( V_5 -> V_213 ) ;
}
}
static inline void F_87 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_7 = F_33 ( V_296 ) ;
V_7 |= V_297 ;
F_31 ( V_296 , V_7 ) ;
V_5 -> V_298 = V_299 ;
}
static void F_88 ( struct V_4 * V_5 )
{
int V_42 ;
unsigned int V_300 ;
long V_301 ;
V_301 = ( long ) ( V_5 -> V_298 + 1 +
F_89 ( V_302 ) ) -
( long ) V_299 ;
if ( V_301 < 0 )
return;
V_300 = F_90 ( V_301 ) ;
if ( V_300 > V_302 )
V_300 = V_302 ;
V_300 = ( V_300 >> 3 ) + 1 ;
for ( V_42 = 0 ; V_42 < V_300 ; V_42 ++ ) {
if ( ! ( F_33 ( V_296 ) & V_297 ) )
break;
if ( F_36 ( V_5 -> V_12 ) )
break;
F_24 ( 8 ) ;
}
}
static void F_91 ( struct V_4 * V_5 , T_1 * V_72 )
{
T_1 V_161 , V_7 ;
V_7 = 0 ;
if ( ! F_57 ( V_5 , V_204 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_303 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
* V_72 ++ = V_7 ;
V_7 = 0 ;
if ( ! F_57 ( V_5 , V_304 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_305 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
* V_72 ++ = V_7 ;
V_7 = 0 ;
if ( ! ( V_5 -> V_178 & V_306 ) ) {
if ( ! F_57 ( V_5 , V_180 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_307 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
}
* V_72 ++ = V_7 ;
if ( ! F_57 ( V_5 , V_308 , & V_161 ) )
V_7 = V_161 << 16 ;
else
V_7 = 0 ;
* V_72 ++ = V_7 ;
}
static void F_92 ( struct V_4 * V_5 )
{
T_1 V_72 [ 4 ] ;
if ( ! F_23 ( V_5 , 5780_CLASS ) || ! F_23 ( V_5 , V_309 ) )
return;
F_91 ( V_5 , V_72 ) ;
F_88 ( V_5 ) ;
F_29 ( V_5 , V_310 , V_311 ) ;
F_29 ( V_5 , V_312 , 14 ) ;
F_29 ( V_5 , V_313 + 0x0 , V_72 [ 0 ] ) ;
F_29 ( V_5 , V_313 + 0x4 , V_72 [ 1 ] ) ;
F_29 ( V_5 , V_313 + 0x8 , V_72 [ 2 ] ) ;
F_29 ( V_5 , V_313 + 0xc , V_72 [ 3 ] ) ;
F_87 ( V_5 ) ;
}
static void F_93 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_309 ) && ! F_23 ( V_5 , V_60 ) ) {
F_88 ( V_5 ) ;
F_29 ( V_5 , V_310 , V_314 ) ;
F_87 ( V_5 ) ;
F_88 ( V_5 ) ;
}
}
static void F_94 ( struct V_4 * V_5 , int V_95 )
{
F_29 ( V_5 , V_315 ,
V_316 ) ;
if ( F_23 ( V_5 , V_317 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_318 ,
V_319 ) ;
break;
case V_110 :
F_29 ( V_5 , V_318 ,
V_320 ) ;
break;
case V_321 :
F_29 ( V_5 , V_318 ,
V_322 ) ;
break;
default:
break;
}
}
}
static void F_95 ( struct V_4 * V_5 , int V_95 )
{
if ( F_23 ( V_5 , V_317 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_318 ,
V_323 ) ;
break;
case V_110 :
F_29 ( V_5 , V_318 ,
V_324 ) ;
break;
default:
break;
}
}
}
static void F_96 ( struct V_4 * V_5 , int V_95 )
{
if ( F_23 ( V_5 , V_309 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_318 ,
V_319 ) ;
break;
case V_110 :
F_29 ( V_5 , V_318 ,
V_320 ) ;
break;
case V_321 :
F_29 ( V_5 , V_318 ,
V_322 ) ;
break;
default:
break;
}
}
}
static int F_97 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_7 ;
if ( F_23 ( V_5 , V_325 ) )
return 0 ;
if ( F_23 ( V_5 , V_264 ) ) {
return 0 ;
}
if ( F_30 ( V_5 ) == V_36 ) {
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
if ( F_33 ( V_326 ) & V_327 )
return 0 ;
if ( F_36 ( V_5 -> V_12 ) )
return - V_82 ;
F_24 ( 100 ) ;
}
return - V_82 ;
}
for ( V_42 = 0 ; V_42 < 100000 ; V_42 ++ ) {
F_32 ( V_5 , V_315 , & V_7 ) ;
if ( V_7 == ~ V_316 )
break;
if ( F_36 ( V_5 -> V_12 ) ) {
if ( ! F_23 ( V_5 , V_325 ) ) {
F_84 ( V_5 , V_325 ) ;
F_98 ( V_5 -> V_111 , L_5 ) ;
}
break;
}
F_24 ( 10 ) ;
}
if ( V_42 >= 100000 && ! F_23 ( V_5 , V_325 ) ) {
F_84 ( V_5 , V_325 ) ;
F_98 ( V_5 -> V_111 , L_5 ) ;
}
if ( F_77 ( V_5 ) == V_328 ) {
F_99 ( 10 ) ;
}
return 0 ;
}
static void F_100 ( struct V_4 * V_5 )
{
if ( ! F_101 ( V_5 -> V_111 ) ) {
F_102 ( V_5 , V_329 , V_5 -> V_111 , L_6 ) ;
F_92 ( V_5 ) ;
} else if ( F_103 ( V_5 ) ) {
F_98 ( V_5 -> V_111 , L_7 ,
( V_5 -> V_330 . V_331 == V_332 ?
1000 :
( V_5 -> V_330 . V_331 == V_333 ?
100 : 10 ) ) ,
( V_5 -> V_330 . V_334 == V_335 ?
L_8 : L_9 ) ) ;
F_98 ( V_5 -> V_111 , L_10 ,
( V_5 -> V_330 . V_336 & V_337 ) ?
L_11 : L_12 ,
( V_5 -> V_330 . V_336 & V_338 ) ?
L_11 : L_12 ) ;
if ( V_5 -> V_178 & V_339 )
F_98 ( V_5 -> V_111 , L_13 ,
V_5 -> V_340 ? L_14 : L_15 ) ;
F_92 ( V_5 ) ;
}
V_5 -> V_341 = F_101 ( V_5 -> V_111 ) ;
}
static T_1 F_104 ( T_1 V_342 )
{
T_1 V_343 = 0 ;
if ( V_342 & V_344 ) {
V_343 |= V_338 ;
if ( ! ( V_342 & V_345 ) )
V_343 |= V_337 ;
} else if ( V_342 & V_345 )
V_343 |= V_337 ;
return V_343 ;
}
static T_3 F_105 ( T_4 V_346 )
{
T_3 V_347 ;
if ( ( V_346 & V_337 ) && ( V_346 & V_338 ) )
V_347 = V_348 ;
else if ( V_346 & V_337 )
V_347 = V_349 ;
else if ( V_346 & V_338 )
V_347 = V_348 | V_349 ;
else
V_347 = 0 ;
return V_347 ;
}
static T_1 F_106 ( T_1 V_342 )
{
T_1 V_343 = 0 ;
if ( V_342 & V_348 ) {
V_343 |= V_338 ;
if ( ! ( V_342 & V_349 ) )
V_343 |= V_337 ;
} else if ( V_342 & V_349 )
V_343 |= V_337 ;
return V_343 ;
}
static T_4 F_107 ( T_3 V_350 , T_3 V_351 )
{
T_4 V_352 = 0 ;
if ( V_350 & V_351 & V_348 ) {
V_352 = V_337 | V_338 ;
} else if ( V_350 & V_351 & V_349 ) {
if ( V_350 & V_348 )
V_352 = V_338 ;
if ( V_351 & V_348 )
V_352 = V_337 ;
}
return V_352 ;
}
static void F_108 ( struct V_4 * V_5 , T_1 V_350 , T_1 V_351 )
{
T_4 V_353 ;
T_4 V_343 = 0 ;
T_1 V_354 = V_5 -> V_355 ;
T_1 V_356 = V_5 -> V_357 ;
if ( F_23 ( V_5 , V_267 ) )
V_353 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] -> V_353 ;
else
V_353 = V_5 -> V_330 . V_353 ;
if ( V_353 == V_358 && F_23 ( V_5 , V_359 ) ) {
if ( V_5 -> V_178 & V_360 )
V_343 = F_107 ( V_350 , V_351 ) ;
else
V_343 = F_109 ( V_350 , V_351 ) ;
} else
V_343 = V_5 -> V_330 . V_343 ;
V_5 -> V_330 . V_336 = V_343 ;
if ( V_343 & V_338 )
V_5 -> V_355 |= V_361 ;
else
V_5 -> V_355 &= ~ V_361 ;
if ( V_354 != V_5 -> V_355 )
F_31 ( V_362 , V_5 -> V_355 ) ;
if ( V_343 & V_337 )
V_5 -> V_357 |= V_363 ;
else
V_5 -> V_357 &= ~ V_363 ;
if ( V_356 != V_5 -> V_357 )
F_31 ( V_364 , V_5 -> V_357 ) ;
}
static void F_110 ( struct V_365 * V_111 )
{
T_4 V_366 , V_367 = 0 ;
T_1 V_368 , V_369 , V_370 ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_211 * V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
F_70 ( & V_5 -> V_209 ) ;
V_368 = V_5 -> V_368 & ~ ( V_371 |
V_372 ) ;
V_366 = V_5 -> V_330 . V_336 ;
if ( V_212 -> V_329 ) {
V_369 = 0 ;
V_370 = 0 ;
if ( V_212 -> V_373 == V_333 || V_212 -> V_373 == V_374 )
V_368 |= V_375 ;
else if ( V_212 -> V_373 == V_332 ||
F_30 ( V_5 ) != V_257 )
V_368 |= V_376 ;
else
V_368 |= V_375 ;
if ( V_212 -> V_377 == V_378 )
V_368 |= V_372 ;
else {
V_369 = F_112 (
V_5 -> V_330 . V_343 ) ;
if ( V_212 -> V_379 )
V_370 = V_380 ;
if ( V_212 -> V_381 )
V_370 |= V_382 ;
}
F_108 ( V_5 , V_369 , V_370 ) ;
} else
V_368 |= V_376 ;
if ( V_368 != V_5 -> V_368 ) {
V_5 -> V_368 = V_368 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
}
if ( F_30 ( V_5 ) == V_257 ) {
if ( V_212 -> V_373 == V_374 )
F_46 ( V_384 ,
V_385 |
V_386 ) ;
else
F_46 ( V_384 , V_386 ) ;
}
if ( V_212 -> V_373 == V_332 && V_212 -> V_377 == V_378 )
F_46 ( V_387 ,
( ( 2 << V_388 ) |
( 6 << V_389 ) |
( 0xff << V_390 ) ) ) ;
else
F_46 ( V_387 ,
( ( 2 << V_388 ) |
( 6 << V_389 ) |
( 32 << V_390 ) ) ) ;
if ( V_212 -> V_329 != V_5 -> V_391 ||
V_212 -> V_373 != V_5 -> V_330 . V_331 ||
V_212 -> V_377 != V_5 -> V_330 . V_334 ||
V_366 != V_5 -> V_330 . V_336 )
V_367 = 1 ;
V_5 -> V_391 = V_212 -> V_329 ;
V_5 -> V_330 . V_331 = V_212 -> V_373 ;
V_5 -> V_330 . V_334 = V_212 -> V_377 ;
F_71 ( & V_5 -> V_209 ) ;
if ( V_367 )
F_100 ( V_5 ) ;
}
static int F_113 ( struct V_4 * V_5 )
{
struct V_211 * V_212 ;
if ( V_5 -> V_178 & V_392 )
return 0 ;
F_68 ( V_5 ) ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
V_212 = F_114 ( V_5 -> V_111 , F_115 ( & V_212 -> V_111 ) ,
F_110 , V_212 -> V_227 ) ;
if ( F_116 ( V_212 ) ) {
F_117 ( & V_5 -> V_12 -> V_111 , L_16 ) ;
return F_118 ( V_212 ) ;
}
switch ( V_212 -> V_227 ) {
case V_286 :
case V_228 :
if ( ! ( V_5 -> V_178 & V_393 ) ) {
V_212 -> V_394 &= ( V_395 |
V_396 |
V_397 ) ;
break;
}
case V_295 :
V_212 -> V_394 &= ( V_398 |
V_396 |
V_397 ) ;
break;
default:
F_119 ( V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ) ;
return - V_64 ;
}
V_5 -> V_178 |= V_392 ;
V_212 -> V_399 = V_212 -> V_394 ;
return 0 ;
}
static void F_120 ( struct V_4 * V_5 )
{
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_392 ) )
return;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
if ( V_5 -> V_178 & V_400 ) {
V_5 -> V_178 &= ~ V_400 ;
V_212 -> V_373 = V_5 -> V_330 . V_373 ;
V_212 -> V_377 = V_5 -> V_330 . V_377 ;
V_212 -> V_353 = V_5 -> V_330 . V_353 ;
V_212 -> V_399 = V_5 -> V_330 . V_399 ;
}
F_121 ( V_212 ) ;
F_122 ( V_212 ) ;
}
static void F_123 ( struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_178 & V_392 ) )
return;
F_124 ( V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ) ;
}
static void F_125 ( struct V_4 * V_5 )
{
if ( V_5 -> V_178 & V_392 ) {
F_119 ( V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ) ;
V_5 -> V_178 &= ~ V_392 ;
}
}
static int F_126 ( struct V_4 * V_5 )
{
int V_75 ;
T_1 V_7 ;
if ( V_5 -> V_178 & V_179 )
return 0 ;
if ( ( V_5 -> V_216 & V_401 ) == V_402 ) {
V_75 = F_65 ( V_5 ,
V_196 ,
V_403 |
0x4c20 ) ;
goto V_186;
}
V_75 = F_64 ( V_5 ,
V_196 , & V_7 ) ;
if ( V_75 )
return V_75 ;
V_7 |= V_403 ;
V_75 = F_65 ( V_5 ,
V_196 , V_7 ) ;
V_186:
return V_75 ;
}
static void F_127 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_404 ;
if ( ! F_57 ( V_5 , V_405 , & V_404 ) ) {
T_1 V_406 ;
F_59 ( V_5 , V_405 ,
V_404 | V_407 ) ;
if ( ! F_57 ( V_5 , V_408 , & V_406 ) ) {
if ( V_195 )
V_406 |= V_409 ;
else
V_406 &= ~ V_409 ;
F_59 ( V_5 , V_408 , V_406 ) ;
}
F_59 ( V_5 , V_405 , V_404 ) ;
}
}
static void F_128 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_161 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
( F_23 ( V_5 , 5717_PLUS ) &&
( V_5 -> V_178 & V_306 ) ) )
return;
if ( V_5 -> V_178 & V_179 ) {
F_127 ( V_5 , V_195 ) ;
return;
}
V_161 = V_410 |
V_411 |
V_412 |
V_413 ;
if ( F_30 ( V_5 ) != V_414 || ! V_195 )
V_161 |= V_415 ;
F_67 ( V_5 , V_416 , V_161 ) ;
V_161 = V_417 ;
if ( V_195 )
V_161 |= V_418 ;
F_67 ( V_5 , V_419 , V_161 ) ;
}
static void F_129 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_406 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
( V_5 -> V_178 & V_360 ) )
return;
if ( V_5 -> V_178 & V_179 ) {
T_1 V_420 ;
if ( ! F_57 ( V_5 , V_405 , & V_420 ) ) {
T_1 V_161 = V_421 ;
F_59 ( V_5 , V_405 ,
V_420 | V_407 ) ;
if ( ! F_57 ( V_5 , V_161 , & V_406 ) ) {
if ( V_195 )
V_406 |= V_422 ;
else
V_406 &= ~ V_422 ;
F_59 ( V_5 , V_161 , V_406 ) ;
}
F_59 ( V_5 , V_405 , V_420 ) ;
}
} else {
int V_56 ;
V_56 = F_64 ( V_5 ,
V_192 , & V_406 ) ;
if ( ! V_56 ) {
if ( V_195 )
V_406 |= V_423 ;
else
V_406 &= ~ V_423 ;
F_65 ( V_5 ,
V_192 , V_406 ) ;
}
}
}
static void F_130 ( struct V_4 * V_5 )
{
int V_56 ;
T_1 V_7 ;
if ( V_5 -> V_178 & V_424 )
return;
V_56 = F_64 ( V_5 , V_192 , & V_7 ) ;
if ( ! V_56 )
F_65 ( V_5 , V_192 ,
V_7 | V_425 ) ;
}
static void F_131 ( struct V_4 * V_5 )
{
T_1 V_426 , V_406 ;
if ( ! V_5 -> V_427 )
return;
V_426 = V_5 -> V_427 ;
if ( F_66 ( V_5 , true ) )
return;
V_406 = ( ( V_426 & V_428 ) >> V_429 ) ;
V_406 |= V_430 ;
F_63 ( V_5 , V_431 , V_406 ) ;
V_406 = ( ( V_426 & V_432 ) >> V_433 ) |
( ( V_426 & V_434 ) >> V_435 ) ;
F_63 ( V_5 , V_436 , V_406 ) ;
V_406 = ( ( V_426 & V_437 ) >> V_438 ) ;
V_406 |= V_439 ;
F_63 ( V_5 , V_440 , V_406 ) ;
V_406 = ( ( V_426 & V_441 ) >> V_442 ) ;
F_63 ( V_5 , V_443 , V_406 ) ;
V_406 = ( ( V_426 & V_444 ) >> V_445 ) ;
F_63 ( V_5 , V_446 , V_406 ) ;
V_406 = ( ( V_426 & V_447 ) >> V_448 ) |
( ( V_426 & V_449 ) >> V_450 ) ;
F_63 ( V_5 , V_451 , V_406 ) ;
F_66 ( V_5 , false ) ;
}
static void F_132 ( struct V_4 * V_5 , struct V_452 * V_453 )
{
T_1 V_7 ;
struct V_452 * V_454 = & V_5 -> V_453 ;
if ( ! ( V_5 -> V_178 & V_339 ) )
return;
if ( V_453 )
V_454 = V_453 ;
if ( F_61 ( V_5 , V_455 , V_456 , & V_7 ) )
return;
if ( V_7 == V_457 ||
V_7 == V_458 ) {
V_454 -> V_459 = 1 ;
} else
V_454 -> V_459 = 0 ;
if ( F_61 ( V_5 , V_455 , V_460 , & V_7 ) )
return;
V_454 -> V_461 = F_133 ( V_7 ) ;
if ( F_61 ( V_5 , V_455 , V_462 , & V_7 ) )
return;
V_454 -> V_463 = ! ! V_7 ;
V_454 -> V_464 = F_133 ( V_7 ) ;
V_7 = F_33 ( V_465 ) ;
V_454 -> V_466 = ! ! ( V_7 & V_467 ) ;
V_454 -> V_468 = F_33 ( V_469 ) & 0xffff ;
}
static void F_134 ( struct V_4 * V_5 , bool V_470 )
{
T_1 V_7 ;
if ( ! ( V_5 -> V_178 & V_339 ) )
return;
V_5 -> V_340 = 0 ;
if ( V_5 -> V_330 . V_353 == V_358 &&
V_470 &&
V_5 -> V_330 . V_334 == V_335 &&
( V_5 -> V_330 . V_331 == V_333 ||
V_5 -> V_330 . V_331 == V_332 ) ) {
T_1 V_471 ;
if ( V_5 -> V_330 . V_331 == V_332 )
V_471 = V_472 ;
else
V_471 = V_473 ;
F_46 ( V_474 , V_471 ) ;
F_132 ( V_5 , NULL ) ;
if ( V_5 -> V_453 . V_459 )
V_5 -> V_340 = 2 ;
}
if ( ! V_5 -> V_340 ) {
if ( V_470 &&
! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , V_475 , 0x0000 ) ;
F_66 ( V_5 , false ) ;
}
V_7 = F_33 ( V_465 ) ;
F_46 ( V_465 , V_7 & ~ V_476 ) ;
}
}
static void F_135 ( struct V_4 * V_5 )
{
T_1 V_7 ;
if ( V_5 -> V_330 . V_331 == V_332 &&
( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_23 ( V_5 , 57765_CLASS ) ) &&
! F_66 ( V_5 , true ) ) {
V_7 = V_479 |
V_480 ;
F_63 ( V_5 , V_475 , V_7 ) ;
F_66 ( V_5 , false ) ;
}
V_7 = F_33 ( V_465 ) ;
F_46 ( V_465 , V_7 | V_476 ) ;
}
static int F_136 ( struct V_4 * V_5 )
{
int V_202 = 100 ;
while ( V_202 -- ) {
T_1 V_481 ;
if ( ! F_57 ( V_5 , V_482 , & V_481 ) ) {
if ( ( V_481 & 0x1000 ) == 0 )
break;
}
}
if ( V_202 < 0 )
return - V_67 ;
return 0 ;
}
static int F_137 ( struct V_4 * V_5 , int * V_483 )
{
static const T_1 V_484 [ 4 ] [ 6 ] = {
{ 0x00005555 , 0x00000005 , 0x00002aaa , 0x0000000a , 0x00003456 , 0x00000003 } ,
{ 0x00002aaa , 0x0000000a , 0x00003333 , 0x00000003 , 0x0000789a , 0x00000005 } ,
{ 0x00005a5a , 0x00000005 , 0x00002a6a , 0x0000000a , 0x00001bcd , 0x00000003 } ,
{ 0x00002a5a , 0x0000000a , 0x000033c3 , 0x00000003 , 0x00002ef1 , 0x00000005 }
} ;
int V_485 ;
for ( V_485 = 0 ; V_485 < 4 ; V_485 ++ ) {
int V_42 ;
F_59 ( V_5 , V_189 ,
( V_485 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_482 , 0x0002 ) ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ )
F_59 ( V_5 , V_190 ,
V_484 [ V_485 ] [ V_42 ] ) ;
F_59 ( V_5 , V_482 , 0x0202 ) ;
if ( F_136 ( V_5 ) ) {
* V_483 = 1 ;
return - V_67 ;
}
F_59 ( V_5 , V_189 ,
( V_485 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_482 , 0x0082 ) ;
if ( F_136 ( V_5 ) ) {
* V_483 = 1 ;
return - V_67 ;
}
F_59 ( V_5 , V_482 , 0x0802 ) ;
if ( F_136 ( V_5 ) ) {
* V_483 = 1 ;
return - V_67 ;
}
for ( V_42 = 0 ; V_42 < 6 ; V_42 += 2 ) {
T_1 V_486 , V_487 ;
if ( F_57 ( V_5 , V_190 , & V_486 ) ||
F_57 ( V_5 , V_190 , & V_487 ) ||
F_136 ( V_5 ) ) {
* V_483 = 1 ;
return - V_67 ;
}
V_486 &= 0x7fff ;
V_487 &= 0x000f ;
if ( V_486 != V_484 [ V_485 ] [ V_42 ] ||
V_487 != V_484 [ V_485 ] [ V_42 + 1 ] ) {
F_59 ( V_5 , V_189 , 0x000b ) ;
F_59 ( V_5 , V_190 , 0x4001 ) ;
F_59 ( V_5 , V_190 , 0x4005 ) ;
return - V_67 ;
}
}
}
return 0 ;
}
static int F_138 ( struct V_4 * V_5 )
{
int V_485 ;
for ( V_485 = 0 ; V_485 < 4 ; V_485 ++ ) {
int V_42 ;
F_59 ( V_5 , V_189 ,
( V_485 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_482 , 0x0002 ) ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ )
F_59 ( V_5 , V_190 , 0x000 ) ;
F_59 ( V_5 , V_482 , 0x0202 ) ;
if ( F_136 ( V_5 ) )
return - V_67 ;
}
return 0 ;
}
static int F_139 ( struct V_4 * V_5 )
{
T_1 V_488 , V_489 ;
int V_490 , V_491 , V_75 ;
V_490 = 10 ;
V_491 = 1 ;
do {
if ( V_491 ) {
V_75 = F_68 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_491 = 0 ;
}
if ( F_57 ( V_5 , V_492 , & V_488 ) )
continue;
V_488 |= 0x3000 ;
F_59 ( V_5 , V_492 , V_488 ) ;
F_59 ( V_5 , V_204 ,
V_493 | V_494 ) ;
if ( F_57 ( V_5 , V_180 , & V_489 ) )
continue;
F_59 ( V_5 , V_180 ,
V_495 | V_496 ) ;
V_75 = F_66 ( V_5 , true ) ;
if ( V_75 )
return V_75 ;
F_63 ( V_5 , 0x8005 , 0x0800 ) ;
V_75 = F_137 ( V_5 , & V_491 ) ;
if ( ! V_75 )
break;
} while ( -- V_490 );
V_75 = F_138 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_63 ( V_5 , 0x8005 , 0x0000 ) ;
F_59 ( V_5 , V_189 , 0x8200 ) ;
F_59 ( V_5 , V_482 , 0x0000 ) ;
F_66 ( V_5 , false ) ;
F_59 ( V_5 , V_180 , V_489 ) ;
if ( ! F_57 ( V_5 , V_492 , & V_488 ) ) {
V_488 &= ~ 0x3000 ;
F_59 ( V_5 , V_492 , V_488 ) ;
} else if ( ! V_75 )
V_75 = - V_67 ;
return V_75 ;
}
static void F_140 ( struct V_4 * V_5 )
{
F_141 ( V_5 -> V_111 ) ;
V_5 -> V_341 = false ;
}
static void F_142 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_309 ) )
F_143 ( V_5 -> V_111 ,
L_17 ) ;
}
static int F_144 ( struct V_4 * V_5 )
{
T_1 V_7 , V_497 ;
int V_75 ;
if ( F_30 ( V_5 ) == V_36 ) {
V_7 = F_33 ( V_498 ) ;
F_31 ( V_498 , V_7 & ~ V_499 ) ;
F_24 ( 40 ) ;
}
V_75 = F_57 ( V_5 , V_303 , & V_7 ) ;
V_75 |= F_57 ( V_5 , V_303 , & V_7 ) ;
if ( V_75 != 0 )
return - V_67 ;
if ( F_145 ( V_5 -> V_111 ) && V_5 -> V_341 ) {
F_141 ( V_5 -> V_111 ) ;
F_100 ( V_5 ) ;
}
if ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ||
F_30 ( V_5 ) == V_502 ) {
V_75 = F_139 ( V_5 ) ;
if ( V_75 )
return V_75 ;
goto V_503;
}
V_497 = 0 ;
if ( F_30 ( V_5 ) == V_414 &&
F_146 ( V_5 ) != V_504 ) {
V_497 = F_33 ( V_505 ) ;
if ( V_497 & V_506 )
F_46 ( V_505 ,
V_497 & ~ V_506 ) ;
}
V_75 = F_68 ( V_5 ) ;
if ( V_75 )
return V_75 ;
if ( V_497 & V_506 ) {
V_7 = V_507 | V_508 ;
F_63 ( V_5 , V_509 , V_7 ) ;
F_46 ( V_505 , V_497 ) ;
}
if ( F_146 ( V_5 ) == V_504 ||
F_146 ( V_5 ) == V_510 ) {
V_7 = F_33 ( V_511 ) ;
if ( ( V_7 & V_512 ) ==
V_513 ) {
V_7 &= ~ V_512 ;
F_24 ( 40 ) ;
F_31 ( V_511 , V_7 ) ;
}
}
if ( F_23 ( V_5 , 5717_PLUS ) &&
( V_5 -> V_178 & V_306 ) )
return 0 ;
F_131 ( V_5 ) ;
if ( V_5 -> V_178 & V_514 )
F_128 ( V_5 , true ) ;
else
F_128 ( V_5 , false ) ;
V_503:
if ( ( V_5 -> V_178 & V_515 ) &&
! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , 0x201f , 0x2aaa ) ;
F_63 ( V_5 , 0x000a , 0x0323 ) ;
F_66 ( V_5 , false ) ;
}
if ( V_5 -> V_178 & V_516 ) {
F_59 ( V_5 , V_199 , 0x8d68 ) ;
F_59 ( V_5 , V_199 , 0x8d68 ) ;
}
if ( V_5 -> V_178 & V_517 ) {
if ( ! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , 0x000a , 0x310b ) ;
F_63 ( V_5 , 0x201f , 0x9506 ) ;
F_63 ( V_5 , 0x401f , 0x14e2 ) ;
F_66 ( V_5 , false ) ;
}
} else if ( V_5 -> V_178 & V_518 ) {
if ( ! F_66 ( V_5 , true ) ) {
F_59 ( V_5 , V_189 , 0x000a ) ;
if ( V_5 -> V_178 & V_519 ) {
F_59 ( V_5 , V_190 , 0x110b ) ;
F_59 ( V_5 , V_520 ,
V_521 | 0x4 ) ;
} else
F_59 ( V_5 , V_190 , 0x010b ) ;
F_66 ( V_5 , false ) ;
}
}
if ( ( V_5 -> V_216 & V_401 ) == V_402 ) {
F_65 ( V_5 , V_196 , 0x4c20 ) ;
} else if ( F_23 ( V_5 , V_522 ) ) {
V_75 = F_64 ( V_5 ,
V_196 , & V_7 ) ;
if ( ! V_75 )
F_65 ( V_5 , V_196 ,
V_7 | V_523 ) ;
}
if ( F_23 ( V_5 , V_522 ) ) {
if ( ! F_57 ( V_5 , V_492 , & V_7 ) )
F_59 ( V_5 , V_492 ,
V_7 | V_524 ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
F_59 ( V_5 , V_525 , 0x12 ) ;
}
if ( F_77 ( V_5 ) == V_526 )
F_63 ( V_5 , 0xffb , 0x4000 ) ;
F_129 ( V_5 , true ) ;
F_130 ( V_5 ) ;
return 0 ;
}
static inline T_1 F_147 ( struct V_4 * V_5 , T_1 V_527 )
{
T_1 V_57 , V_528 ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 )
V_57 = F_12 ( V_5 , V_529 ) ;
else
V_57 = F_33 ( V_530 ) ;
V_528 = V_531 + 4 * V_5 -> V_54 ;
V_57 &= ~ ( V_532 << V_528 ) ;
V_57 |= ( V_527 << V_528 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 )
F_11 ( V_5 , V_529 , V_57 ) ;
else
F_46 ( V_530 , V_57 ) ;
return V_57 >> V_531 ;
}
static inline int F_148 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_533 ) )
return 0 ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ) {
if ( F_35 ( V_5 , V_49 ) )
return - V_210 ;
F_147 ( V_5 , V_535 ) ;
F_55 ( V_136 , V_5 -> V_22 ,
V_536 ) ;
F_37 ( V_5 , V_49 ) ;
} else {
F_55 ( V_136 , V_5 -> V_22 ,
V_536 ) ;
}
return 0 ;
}
static void F_149 ( struct V_4 * V_5 )
{
T_1 V_22 ;
if ( ! F_23 ( V_5 , V_533 ) ||
F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 )
return;
V_22 = V_5 -> V_22 | V_539 ;
F_55 ( V_136 ,
V_22 | V_540 ,
V_536 ) ;
F_55 ( V_136 ,
V_22 ,
V_536 ) ;
F_55 ( V_136 ,
V_22 | V_540 ,
V_536 ) ;
}
static void F_150 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_533 ) )
return;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) {
F_55 ( V_136 , V_5 -> V_22 |
( V_541 |
V_539 |
V_542 |
V_543 |
V_540 ) ,
V_536 ) ;
} else if ( V_5 -> V_12 -> V_544 == V_545 ||
V_5 -> V_12 -> V_544 == V_546 ) {
T_1 V_22 = V_541 |
V_539 |
V_542 |
V_543 |
V_540 |
V_5 -> V_22 ;
F_55 ( V_136 , V_22 ,
V_536 ) ;
V_22 |= V_547 ;
F_55 ( V_136 , V_22 ,
V_536 ) ;
V_22 &= ~ V_543 ;
F_55 ( V_136 , V_22 ,
V_536 ) ;
} else {
T_1 V_548 ;
T_1 V_22 = 0 ;
if ( F_30 ( V_5 ) == V_549 ) {
V_22 |= V_550 ;
F_55 ( V_136 , V_5 -> V_22 |
V_22 ,
V_536 ) ;
}
V_548 = V_5 -> V_551 &
V_552 ;
V_22 |= V_541 |
V_539 |
V_542 |
V_540 |
V_547 ;
if ( V_548 ) {
V_22 &= ~ ( V_542 |
V_547 ) ;
}
F_55 ( V_136 ,
V_5 -> V_22 | V_22 ,
V_536 ) ;
V_22 |= V_543 ;
F_55 ( V_136 ,
V_5 -> V_22 | V_22 ,
V_536 ) ;
if ( ! V_548 ) {
V_22 &= ~ V_547 ;
F_55 ( V_136 ,
V_5 -> V_22 | V_22 ,
V_536 ) ;
}
}
}
static void F_151 ( struct V_4 * V_5 , bool V_553 )
{
T_1 V_554 = 0 ;
if ( F_35 ( V_5 , V_49 ) )
return;
if ( F_23 ( V_5 , V_309 ) || F_23 ( V_5 , V_60 ) || V_553 )
V_554 = V_555 ;
V_554 = F_147 ( V_5 , V_554 ) ;
if ( V_554 & V_556 )
goto V_186;
if ( V_554 & V_557 )
F_150 ( V_5 ) ;
else
F_149 ( V_5 ) ;
V_186:
F_37 ( V_5 , V_49 ) ;
}
static void F_152 ( struct V_4 * V_5 , bool V_558 )
{
bool V_559 = false ;
if ( ! F_23 ( V_5 , V_533 ) || F_23 ( V_5 , 57765_CLASS ) )
return;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ) {
F_151 ( V_5 , V_558 ?
F_23 ( V_5 , V_112 ) != 0 : 0 ) ;
return;
}
if ( V_5 -> V_560 && V_5 -> V_560 != V_5 -> V_12 ) {
struct V_365 * V_561 ;
V_561 = F_153 ( V_5 -> V_560 ) ;
if ( V_561 ) {
struct V_4 * V_562 = F_111 ( V_561 ) ;
if ( F_23 ( V_562 , V_563 ) )
return;
if ( ( V_558 && F_23 ( V_562 , V_112 ) ) ||
F_23 ( V_562 , V_309 ) )
V_559 = true ;
}
}
if ( ( V_558 && F_23 ( V_5 , V_112 ) ) ||
F_23 ( V_5 , V_309 ) )
V_559 = true ;
if ( V_559 )
F_150 ( V_5 ) ;
else
F_149 ( V_5 ) ;
}
static int F_154 ( struct V_4 * V_5 , T_1 V_373 )
{
if ( V_5 -> V_564 == V_565 )
return 1 ;
else if ( ( V_5 -> V_216 & V_401 ) == V_566 ) {
if ( V_373 != V_374 )
return 1 ;
} else if ( V_373 == V_374 )
return 1 ;
return 0 ;
}
static bool F_155 ( struct V_4 * V_5 )
{
switch ( F_30 ( V_5 ) ) {
case V_537 :
case V_501 :
return true ;
case V_567 :
if ( V_5 -> V_178 & V_306 )
return true ;
return false ;
case V_477 :
if ( ! V_5 -> V_54 )
return true ;
return false ;
case V_478 :
case V_534 :
if ( ( V_5 -> V_178 & V_568 ) &&
! V_5 -> V_54 )
return true ;
return false ;
}
return false ;
}
static bool F_156 ( struct V_4 * V_5 )
{
switch ( F_30 ( V_5 ) ) {
case V_478 :
case V_534 :
if ( ( V_5 -> V_178 & V_306 ) &&
! V_5 -> V_54 )
return true ;
return false ;
}
return false ;
}
static void F_157 ( struct V_4 * V_5 , bool V_569 )
{
T_1 V_7 ;
if ( V_5 -> V_178 & V_570 )
return;
if ( V_5 -> V_178 & V_568 ) {
if ( F_30 ( V_5 ) == V_501 ) {
T_1 V_571 = F_33 ( V_572 ) ;
T_1 V_573 = F_33 ( V_574 ) ;
V_571 |=
V_575 | V_576 ;
F_46 ( V_572 , V_571 ) ;
F_46 ( V_574 , V_573 | ( 1 << 15 ) ) ;
}
return;
}
if ( F_30 ( V_5 ) == V_36 ) {
F_68 ( V_5 ) ;
V_7 = F_33 ( V_498 ) ;
F_31 ( V_498 , V_7 | V_499 ) ;
F_24 ( 40 ) ;
return;
} else if ( V_5 -> V_178 & V_179 ) {
T_1 V_404 ;
if ( ! F_57 ( V_5 , V_405 , & V_404 ) ) {
T_1 V_406 ;
F_59 ( V_5 , V_304 , 0 ) ;
F_59 ( V_5 , V_204 ,
V_577 | V_578 ) ;
F_59 ( V_5 , V_405 ,
V_404 | V_407 ) ;
if ( ! F_57 ( V_5 , V_579 , & V_406 ) ) {
V_406 |= V_580 ;
F_59 ( V_5 ,
V_579 ,
V_406 ) ;
}
F_59 ( V_5 , V_405 , V_404 ) ;
}
return;
} else if ( V_569 ) {
if ( ! F_156 ( V_5 ) )
F_59 ( V_5 , V_492 ,
V_581 ) ;
V_7 = V_582 |
V_583 |
V_584 ;
F_65 ( V_5 , V_585 , V_7 ) ;
}
if ( F_155 ( V_5 ) )
return;
if ( F_146 ( V_5 ) == V_504 ||
F_146 ( V_5 ) == V_510 ) {
V_7 = F_33 ( V_511 ) ;
V_7 &= ~ V_512 ;
V_7 |= V_513 ;
F_31 ( V_511 , V_7 ) ;
}
F_59 ( V_5 , V_204 , V_284 ) ;
}
static int F_158 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_586 ) ) {
int V_42 ;
if ( V_5 -> V_587 == 0 ) {
F_46 ( V_588 , V_589 ) ;
for ( V_42 = 0 ; V_42 < 8000 ; V_42 ++ ) {
if ( F_33 ( V_588 ) & V_590 )
break;
F_24 ( 20 ) ;
}
if ( V_42 == 8000 ) {
F_46 ( V_588 , V_591 ) ;
return - V_82 ;
}
}
V_5 -> V_587 ++ ;
}
return 0 ;
}
static void F_159 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_586 ) ) {
if ( V_5 -> V_587 > 0 )
V_5 -> V_587 -- ;
if ( V_5 -> V_587 == 0 )
F_31 ( V_588 , V_591 ) ;
}
}
static void F_160 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_592 ) ) {
T_1 V_593 = F_33 ( V_594 ) ;
F_46 ( V_594 , V_593 | V_595 ) ;
}
}
static void F_161 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_592 ) ) {
T_1 V_593 = F_33 ( V_594 ) ;
F_46 ( V_594 , V_593 & ~ V_595 ) ;
}
}
static int F_162 ( struct V_4 * V_5 ,
T_1 V_596 , T_1 * V_7 )
{
T_1 V_597 ;
int V_42 ;
if ( V_596 > V_598 || ( V_596 % 4 ) != 0 )
return - V_64 ;
V_597 = F_33 ( V_599 ) & ~ ( V_598 |
V_600 |
V_601 ) ;
F_46 ( V_599 ,
V_597 |
( 0 << V_602 ) |
( ( V_596 << V_603 ) &
V_598 ) |
V_601 | V_604 ) ;
for ( V_42 = 0 ; V_42 < 1000 ; V_42 ++ ) {
V_597 = F_33 ( V_599 ) ;
if ( V_597 & V_605 )
break;
F_163 ( 1 ) ;
}
if ( ! ( V_597 & V_605 ) )
return - V_67 ;
V_597 = F_33 ( V_606 ) ;
* V_7 = F_164 ( V_597 ) ;
return 0 ;
}
static int F_165 ( struct V_4 * V_5 , T_1 V_607 )
{
int V_42 ;
F_46 ( V_608 , V_607 ) ;
for ( V_42 = 0 ; V_42 < V_609 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( F_33 ( V_608 ) & V_610 ) {
F_24 ( 10 ) ;
break;
}
}
if ( V_42 == V_609 )
return - V_67 ;
return 0 ;
}
static T_1 F_166 ( struct V_4 * V_5 , T_1 V_184 )
{
if ( F_23 ( V_5 , V_586 ) &&
F_23 ( V_5 , V_611 ) &&
F_23 ( V_5 , V_612 ) &&
! F_23 ( V_5 , V_613 ) &&
( V_5 -> V_614 == V_615 ) )
V_184 = ( ( V_184 / V_5 -> V_616 ) <<
V_617 ) +
( V_184 % V_5 -> V_616 ) ;
return V_184 ;
}
static T_1 F_167 ( struct V_4 * V_5 , T_1 V_184 )
{
if ( F_23 ( V_5 , V_586 ) &&
F_23 ( V_5 , V_611 ) &&
F_23 ( V_5 , V_612 ) &&
! F_23 ( V_5 , V_613 ) &&
( V_5 -> V_614 == V_615 ) )
V_184 = ( ( V_184 >> V_617 ) *
V_5 -> V_616 ) +
( V_184 & ( ( 1 << V_617 ) - 1 ) ) ;
return V_184 ;
}
static int F_168 ( struct V_4 * V_5 , T_1 V_596 , T_1 * V_7 )
{
int V_56 ;
if ( ! F_23 ( V_5 , V_586 ) )
return F_162 ( V_5 , V_596 , V_7 ) ;
V_596 = F_166 ( V_5 , V_596 ) ;
if ( V_596 > V_618 )
return - V_64 ;
V_56 = F_158 ( V_5 ) ;
if ( V_56 )
return V_56 ;
F_160 ( V_5 ) ;
F_46 ( V_619 , V_596 ) ;
V_56 = F_165 ( V_5 , V_620 | V_621 |
V_622 | V_623 | V_610 ) ;
if ( V_56 == 0 )
* V_7 = F_33 ( V_624 ) ;
F_161 ( V_5 ) ;
F_159 ( V_5 ) ;
return V_56 ;
}
static int F_169 ( struct V_4 * V_5 , T_1 V_596 , T_5 * V_7 )
{
T_1 V_625 ;
int V_626 = F_168 ( V_5 , V_596 , & V_625 ) ;
if ( ! V_626 )
* V_7 = F_170 ( V_625 ) ;
return V_626 ;
}
static int F_171 ( struct V_4 * V_5 ,
T_1 V_596 , T_1 V_74 , T_4 * V_627 )
{
int V_42 , V_628 , V_629 = 0 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 ) {
T_1 V_184 ;
T_5 V_72 ;
V_184 = V_596 + V_42 ;
memcpy ( & V_72 , V_627 + V_42 , 4 ) ;
F_46 ( V_606 , F_164 ( F_172 ( V_72 ) ) ) ;
V_7 = F_33 ( V_599 ) ;
F_46 ( V_599 , V_7 | V_605 ) ;
V_7 &= ~ ( V_598 | V_600 |
V_601 ) ;
F_46 ( V_599 , V_7 |
( 0 << V_602 ) |
( V_184 & V_598 ) |
V_604 |
V_630 ) ;
for ( V_628 = 0 ; V_628 < 1000 ; V_628 ++ ) {
V_7 = F_33 ( V_599 ) ;
if ( V_7 & V_605 )
break;
F_163 ( 1 ) ;
}
if ( ! ( V_7 & V_605 ) ) {
V_629 = - V_67 ;
break;
}
}
return V_629 ;
}
static int F_173 ( struct V_4 * V_5 , T_1 V_596 , T_1 V_74 ,
T_4 * V_627 )
{
int V_56 = 0 ;
T_1 V_631 = V_5 -> V_616 ;
T_1 V_632 = V_631 - 1 ;
T_1 V_607 ;
T_4 * V_597 ;
V_597 = F_174 ( V_631 , V_633 ) ;
if ( V_597 == NULL )
return - V_268 ;
while ( V_74 ) {
int V_628 ;
T_1 V_160 , V_634 , V_635 ;
V_160 = V_596 & ~ V_632 ;
for ( V_628 = 0 ; V_628 < V_631 ; V_628 += 4 ) {
V_56 = F_169 ( V_5 , V_160 + V_628 ,
( T_5 * ) ( V_597 + V_628 ) ) ;
if ( V_56 )
break;
}
if ( V_56 )
break;
V_634 = V_596 & V_632 ;
V_635 = V_631 ;
if ( V_74 < V_635 )
V_635 = V_74 ;
V_74 -= V_635 ;
memcpy ( V_597 + V_634 , V_627 , V_635 ) ;
V_596 = V_596 + ( V_631 - V_634 ) ;
F_160 ( V_5 ) ;
V_607 = V_636 | V_621 | V_610 ;
if ( F_165 ( V_5 , V_607 ) )
break;
F_46 ( V_619 , V_160 ) ;
V_607 = V_621 | V_610 | V_637 |
V_622 | V_623 | V_638 ;
if ( F_165 ( V_5 , V_607 ) )
break;
V_607 = V_636 | V_621 | V_610 ;
if ( F_165 ( V_5 , V_607 ) )
break;
for ( V_628 = 0 ; V_628 < V_631 ; V_628 += 4 ) {
T_5 V_72 ;
V_72 = * ( ( T_5 * ) ( V_597 + V_628 ) ) ;
F_46 ( V_639 , F_172 ( V_72 ) ) ;
F_46 ( V_619 , V_160 + V_628 ) ;
V_607 = V_621 | V_610 |
V_637 ;
if ( V_628 == 0 )
V_607 |= V_622 ;
else if ( V_628 == ( V_631 - 4 ) )
V_607 |= V_623 ;
V_56 = F_165 ( V_5 , V_607 ) ;
if ( V_56 )
break;
}
if ( V_56 )
break;
}
V_607 = V_640 | V_621 | V_610 ;
F_165 ( V_5 , V_607 ) ;
F_175 ( V_597 ) ;
return V_56 ;
}
static int F_176 ( struct V_4 * V_5 , T_1 V_596 , T_1 V_74 ,
T_4 * V_627 )
{
int V_42 , V_56 = 0 ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 , V_596 += 4 ) {
T_1 V_634 , V_160 , V_607 ;
T_5 V_72 ;
memcpy ( & V_72 , V_627 + V_42 , 4 ) ;
F_46 ( V_639 , F_172 ( V_72 ) ) ;
V_634 = V_596 % V_5 -> V_616 ;
V_160 = F_166 ( V_5 , V_596 ) ;
V_607 = V_621 | V_610 | V_637 ;
if ( V_634 == 0 || V_42 == 0 )
V_607 |= V_622 ;
if ( V_634 == ( V_5 -> V_616 - 4 ) )
V_607 |= V_623 ;
if ( V_42 == ( V_74 - 4 ) )
V_607 |= V_623 ;
if ( ( V_607 & V_622 ) ||
! F_23 ( V_5 , V_612 ) ||
! F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_619 , V_160 ) ;
if ( F_30 ( V_5 ) != V_641 &&
! F_23 ( V_5 , 5755_PLUS ) &&
( V_5 -> V_614 == V_642 ) &&
( V_607 & V_622 ) ) {
T_1 V_643 ;
V_643 = V_636 | V_621 | V_610 ;
V_56 = F_165 ( V_5 , V_643 ) ;
if ( V_56 )
break;
}
if ( ! F_23 ( V_5 , V_612 ) ) {
V_607 |= ( V_622 | V_623 ) ;
}
V_56 = F_165 ( V_5 , V_607 ) ;
if ( V_56 )
break;
}
return V_56 ;
}
static int F_177 ( struct V_4 * V_5 , T_1 V_596 , T_1 V_74 , T_4 * V_627 )
{
int V_56 ;
if ( F_23 ( V_5 , V_644 ) ) {
F_31 ( V_136 , V_5 -> V_22 &
~ V_540 ) ;
F_24 ( 40 ) ;
}
if ( ! F_23 ( V_5 , V_586 ) ) {
V_56 = F_171 ( V_5 , V_596 , V_74 , V_627 ) ;
} else {
T_1 V_645 ;
V_56 = F_158 ( V_5 ) ;
if ( V_56 )
return V_56 ;
F_160 ( V_5 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_592 ) )
F_46 ( V_646 , 0x406 ) ;
V_645 = F_33 ( V_647 ) ;
F_46 ( V_647 , V_645 | V_648 ) ;
if ( F_23 ( V_5 , V_611 ) || ! F_23 ( V_5 , V_612 ) ) {
V_56 = F_176 ( V_5 , V_596 , V_74 ,
V_627 ) ;
} else {
V_56 = F_173 ( V_5 , V_596 , V_74 ,
V_627 ) ;
}
V_645 = F_33 ( V_647 ) ;
F_46 ( V_647 , V_645 & ~ V_648 ) ;
F_161 ( V_5 ) ;
F_159 ( V_5 ) ;
}
if ( F_23 ( V_5 , V_644 ) ) {
F_31 ( V_136 , V_5 -> V_22 ) ;
F_24 ( 40 ) ;
}
return V_56 ;
}
static int F_178 ( struct V_4 * V_5 , T_1 V_649 )
{
int V_42 ;
const int V_650 = 10000 ;
for ( V_42 = 0 ; V_42 < V_650 ; V_42 ++ ) {
F_46 ( V_649 + V_651 , 0xffffffff ) ;
F_46 ( V_649 + V_652 , V_653 ) ;
if ( F_33 ( V_649 + V_652 ) & V_653 )
break;
if ( F_36 ( V_5 -> V_12 ) )
return - V_67 ;
}
return ( V_42 == V_650 ) ? - V_67 : 0 ;
}
static int F_179 ( struct V_4 * V_5 )
{
int V_629 = F_178 ( V_5 , V_654 ) ;
F_46 ( V_654 + V_651 , 0xffffffff ) ;
F_31 ( V_654 + V_652 , V_653 ) ;
F_24 ( 10 ) ;
return V_629 ;
}
static int F_180 ( struct V_4 * V_5 )
{
return F_178 ( V_5 , V_655 ) ;
}
static void F_181 ( struct V_4 * V_5 , T_1 V_649 )
{
F_46 ( V_649 + V_651 , 0xffffffff ) ;
F_31 ( V_649 + V_652 , 0x00000000 ) ;
}
static void F_182 ( struct V_4 * V_5 )
{
F_181 ( V_5 , V_654 ) ;
}
static int F_183 ( struct V_4 * V_5 , T_1 V_649 )
{
int V_629 ;
F_184 ( V_649 == V_655 && F_23 ( V_5 , 5705_PLUS ) ) ;
if ( F_30 ( V_5 ) == V_36 ) {
T_1 V_7 = F_33 ( V_656 ) ;
F_46 ( V_656 , V_7 | V_657 ) ;
return 0 ;
}
if ( V_649 == V_654 ) {
V_629 = F_179 ( V_5 ) ;
} else {
if ( F_23 ( V_5 , V_264 ) )
return 0 ;
V_629 = F_180 ( V_5 ) ;
}
if ( V_629 ) {
F_185 ( V_5 -> V_111 , L_18 ,
V_658 , V_649 == V_654 ? L_19 : L_20 ) ;
return - V_82 ;
}
if ( F_23 ( V_5 , V_586 ) )
F_46 ( V_588 , V_659 ) ;
return 0 ;
}
static int F_186 ( struct V_4 * V_5 ,
const struct V_660 * V_661 )
{
int V_662 ;
if ( V_5 -> V_662 == 0xffffffff )
V_662 = F_172 ( V_661 -> V_74 ) ;
else
V_662 = V_5 -> V_663 -> V_635 ;
return ( V_662 - V_664 ) / sizeof( T_1 ) ;
}
static int F_187 ( struct V_4 * V_5 , T_1 V_649 ,
T_1 V_665 , int V_666 ,
const struct V_660 * V_661 )
{
int V_75 , V_42 ;
void (* F_188)( struct V_4 * , T_1 , T_1 );
int V_667 = V_5 -> V_663 -> V_635 ;
if ( V_649 == V_655 && F_23 ( V_5 , 5705_PLUS ) ) {
F_185 ( V_5 -> V_111 ,
L_21 ,
V_658 ) ;
return - V_64 ;
}
if ( F_23 ( V_5 , 5705_PLUS ) && F_30 ( V_5 ) != V_668 )
F_188 = F_29 ;
else
F_188 = F_13 ;
if ( F_30 ( V_5 ) != V_668 ) {
int V_669 = F_158 ( V_5 ) ;
V_75 = F_183 ( V_5 , V_649 ) ;
if ( ! V_669 )
F_159 ( V_5 ) ;
if ( V_75 )
goto V_503;
for ( V_42 = 0 ; V_42 < V_666 ; V_42 += sizeof( T_1 ) )
F_188 ( V_5 , V_665 + V_42 , 0 ) ;
F_46 ( V_649 + V_651 , 0xffffffff ) ;
F_46 ( V_649 + V_652 ,
F_33 ( V_649 + V_652 ) | V_653 ) ;
} else {
V_667 -= V_664 ;
V_661 ++ ;
}
do {
T_1 * V_670 = ( T_1 * ) ( V_661 + 1 ) ;
for ( V_42 = 0 ; V_42 < F_186 ( V_5 , V_661 ) ; V_42 ++ )
F_188 ( V_5 , V_665 +
( F_172 ( V_661 -> V_671 ) & 0xffff ) +
( V_42 * sizeof( T_1 ) ) ,
F_172 ( V_670 [ V_42 ] ) ) ;
V_667 -= F_172 ( V_661 -> V_74 ) ;
V_661 = (struct V_660 * )
( ( void * ) V_661 + F_172 ( V_661 -> V_74 ) ) ;
} while ( V_667 > 0 );
V_75 = 0 ;
V_503:
return V_75 ;
}
static int F_189 ( struct V_4 * V_5 , T_1 V_649 , T_1 V_672 )
{
int V_42 ;
const int V_650 = 5 ;
F_46 ( V_649 + V_651 , 0xffffffff ) ;
F_31 ( V_649 + V_673 , V_672 ) ;
for ( V_42 = 0 ; V_42 < V_650 ; V_42 ++ ) {
if ( F_33 ( V_649 + V_673 ) == V_672 )
break;
F_46 ( V_649 + V_651 , 0xffffffff ) ;
F_46 ( V_649 + V_652 , V_653 ) ;
F_31 ( V_649 + V_673 , V_672 ) ;
F_24 ( 1000 ) ;
}
return ( V_42 == V_650 ) ? - V_67 : 0 ;
}
static int F_190 ( struct V_4 * V_5 )
{
const struct V_660 * V_661 ;
int V_75 ;
V_661 = (struct V_660 * ) V_5 -> V_663 -> V_72 ;
V_75 = F_187 ( V_5 , V_654 ,
V_674 , V_675 ,
V_661 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_187 ( V_5 , V_655 ,
V_676 , V_677 ,
V_661 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_189 ( V_5 , V_654 ,
F_172 ( V_661 -> V_671 ) ) ;
if ( V_75 ) {
F_185 ( V_5 -> V_111 , L_22
L_23 , V_658 ,
F_33 ( V_654 + V_673 ) ,
F_172 ( V_661 -> V_671 ) ) ;
return - V_82 ;
}
F_182 ( V_5 ) ;
return 0 ;
}
static int F_191 ( struct V_4 * V_5 )
{
const int V_650 = 1000 ;
int V_42 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < V_650 ; V_42 ++ ) {
if ( F_33 ( V_678 ) == V_679 )
break;
F_24 ( 10 ) ;
}
if ( V_42 == V_650 ) {
F_185 ( V_5 -> V_111 , L_24 ) ;
return - V_67 ;
}
V_7 = F_18 ( V_5 , V_680 ) ;
if ( V_7 & 0xff ) {
F_143 ( V_5 -> V_111 ,
L_25 ) ;
return - V_681 ;
}
return 0 ;
}
static void F_192 ( struct V_4 * V_5 )
{
struct V_660 * V_661 ;
if ( ! F_23 ( V_5 , V_682 ) )
return;
if ( F_191 ( V_5 ) )
return;
if ( ! V_5 -> V_663 )
return;
V_661 = (struct V_660 * ) V_5 -> V_663 -> V_72 ;
if ( F_172 ( V_661 -> V_671 ) != V_683 )
return;
if ( F_179 ( V_5 ) )
return;
F_187 ( V_5 , 0 , V_683 , 0 , V_661 ) ;
F_182 ( V_5 ) ;
}
static int F_193 ( struct V_4 * V_5 )
{
const struct V_660 * V_661 ;
unsigned long V_649 , V_665 , V_666 ;
int V_75 ;
if ( ! F_23 ( V_5 , V_684 ) )
return 0 ;
V_661 = (struct V_660 * ) V_5 -> V_663 -> V_72 ;
V_666 = V_5 -> V_662 ;
if ( F_30 ( V_5 ) == V_502 ) {
V_649 = V_654 ;
V_665 = V_685 ;
} else {
V_649 = V_655 ;
V_665 = V_676 ;
V_666 = V_677 ;
}
V_75 = F_187 ( V_5 , V_649 ,
V_665 , V_666 ,
V_661 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_189 ( V_5 , V_649 ,
F_172 ( V_661 -> V_671 ) ) ;
if ( V_75 ) {
F_185 ( V_5 -> V_111 ,
L_26 ,
V_658 , F_33 ( V_649 + V_673 ) ,
F_172 ( V_661 -> V_671 ) ) ;
return - V_82 ;
}
F_181 ( V_5 , V_649 ) ;
return 0 ;
}
static void F_194 ( struct V_4 * V_5 , bool V_686 )
{
T_1 V_687 , V_688 ;
int V_42 ;
V_687 = ( ( V_5 -> V_111 -> V_689 [ 0 ] << 8 ) |
V_5 -> V_111 -> V_689 [ 1 ] ) ;
V_688 = ( ( V_5 -> V_111 -> V_689 [ 2 ] << 24 ) |
( V_5 -> V_111 -> V_689 [ 3 ] << 16 ) |
( V_5 -> V_111 -> V_689 [ 4 ] << 8 ) |
( V_5 -> V_111 -> V_689 [ 5 ] << 0 ) ) ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
if ( V_42 == 1 && V_686 )
continue;
F_46 ( V_690 + ( V_42 * 8 ) , V_687 ) ;
F_46 ( V_691 + ( V_42 * 8 ) , V_688 ) ;
}
if ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ) {
for ( V_42 = 0 ; V_42 < 12 ; V_42 ++ ) {
F_46 ( V_692 + ( V_42 * 8 ) , V_687 ) ;
F_46 ( V_693 + ( V_42 * 8 ) , V_688 ) ;
}
}
V_687 = ( V_5 -> V_111 -> V_689 [ 0 ] +
V_5 -> V_111 -> V_689 [ 1 ] +
V_5 -> V_111 -> V_689 [ 2 ] +
V_5 -> V_111 -> V_689 [ 3 ] +
V_5 -> V_111 -> V_689 [ 4 ] +
V_5 -> V_111 -> V_689 [ 5 ] ) &
V_694 ;
F_46 ( V_695 , V_687 ) ;
}
static void F_195 ( struct V_4 * V_5 )
{
F_15 ( V_5 -> V_12 ,
V_119 , V_5 -> V_120 ) ;
}
static int F_196 ( struct V_4 * V_5 )
{
int V_75 ;
F_195 ( V_5 ) ;
V_75 = F_197 ( V_5 -> V_12 , V_696 ) ;
if ( ! V_75 ) {
F_148 ( V_5 ) ;
} else {
F_185 ( V_5 -> V_111 , L_27 ) ;
}
return V_75 ;
}
static int F_198 ( struct V_4 * V_5 )
{
T_1 V_120 ;
bool V_697 , V_569 ;
F_195 ( V_5 ) ;
if ( F_23 ( V_5 , V_698 ) )
F_199 ( V_5 -> V_12 , V_699 ,
V_700 ) ;
V_120 = F_33 ( V_119 ) ;
F_46 ( V_119 ,
V_120 | V_121 ) ;
V_697 = F_44 ( & V_5 -> V_12 -> V_111 ) &&
F_23 ( V_5 , V_112 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
V_569 = false ;
if ( ( V_5 -> V_178 & V_392 ) &&
! ( V_5 -> V_178 & V_400 ) ) {
struct V_211 * V_212 ;
T_1 V_701 , V_399 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
V_5 -> V_178 |= V_400 ;
V_5 -> V_330 . V_373 = V_212 -> V_373 ;
V_5 -> V_330 . V_377 = V_212 -> V_377 ;
V_5 -> V_330 . V_353 = V_212 -> V_353 ;
V_5 -> V_330 . V_399 = V_212 -> V_399 ;
V_399 = V_702 |
V_703 |
V_704 |
V_705 ;
if ( F_23 ( V_5 , V_309 ) || V_697 ) {
if ( F_23 ( V_5 , V_706 ) )
V_399 |=
V_707 |
V_708 |
V_709 ;
else
V_399 |= V_709 ;
}
V_212 -> V_399 = V_399 ;
F_122 ( V_212 ) ;
V_701 = V_212 -> V_215 -> V_216 & V_212 -> V_215 -> V_217 ;
if ( V_701 != V_221 ) {
V_701 &= V_710 ;
if ( V_701 == V_711 ||
V_701 == V_712 ||
V_701 == V_713 )
V_569 = true ;
}
}
} else {
V_569 = true ;
if ( ! ( V_5 -> V_178 & V_400 ) )
V_5 -> V_178 |= V_400 ;
if ( ! ( V_5 -> V_178 & V_360 ) )
F_200 ( V_5 , false ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
T_1 V_7 ;
V_7 = F_33 ( V_656 ) ;
F_46 ( V_656 , V_7 | V_714 ) ;
} else if ( ! F_23 ( V_5 , V_309 ) ) {
int V_42 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_32 ( V_5 , V_715 , & V_7 ) ;
if ( V_7 == ~ V_316 )
break;
F_163 ( 1 ) ;
}
}
if ( F_23 ( V_5 , V_716 ) )
F_29 ( V_5 , V_717 , V_718 |
V_719 |
V_720 |
V_721 ) ;
if ( V_697 ) {
T_1 V_368 ;
if ( ! ( V_5 -> V_178 & V_568 ) ) {
if ( V_569 &&
! ( V_5 -> V_178 & V_179 ) ) {
F_65 ( V_5 ,
V_585 ,
V_722 |
V_582 |
V_723 ) ;
F_24 ( 40 ) ;
}
if ( V_5 -> V_178 & V_306 )
V_368 = V_376 ;
else if ( V_5 -> V_178 &
V_570 ) {
if ( V_5 -> V_330 . V_331 == V_332 )
V_368 = V_376 ;
else
V_368 = V_375 ;
} else
V_368 = V_375 ;
V_368 |= V_5 -> V_368 & V_724 ;
if ( F_30 ( V_5 ) == V_537 ) {
T_1 V_373 = F_23 ( V_5 , V_706 ) ?
V_333 : V_374 ;
if ( F_154 ( V_5 , V_373 ) )
V_368 |= V_724 ;
else
V_368 &= ~ V_724 ;
}
} else {
V_368 = V_725 ;
}
if ( ! F_23 ( V_5 , 5750_PLUS ) )
F_46 ( V_726 , V_5 -> V_564 ) ;
V_368 |= V_727 ;
if ( ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) ) &&
( F_23 ( V_5 , V_309 ) || F_23 ( V_5 , V_60 ) ) )
V_368 |= V_728 ;
if ( F_23 ( V_5 , V_60 ) )
V_368 |= V_729 |
V_730 |
V_731 ;
F_31 ( V_383 , V_368 ) ;
F_24 ( 100 ) ;
F_31 ( V_362 , V_732 ) ;
F_24 ( 10 ) ;
}
if ( ! F_23 ( V_5 , V_706 ) &&
( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) ) {
T_1 V_733 ;
V_733 = V_5 -> V_156 ;
V_733 |= ( V_734 |
V_735 ) ;
F_55 ( V_153 , V_733 | V_159 |
V_736 , 40 ) ;
} else if ( F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_152 ) ||
F_30 ( V_5 ) == V_36 ) {
} else if ( ! ( F_23 ( V_5 , 5750_PLUS ) && F_23 ( V_5 , V_309 ) ) ) {
T_1 V_737 , V_738 ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) {
V_737 = ( V_734 |
V_735 |
V_159 ) ;
V_738 = V_737 | V_158 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_737 = V_157 ;
V_738 = V_737 | V_159 ;
} else {
V_737 = V_159 ;
V_738 = V_737 | V_158 ;
}
F_55 ( V_153 , V_5 -> V_156 | V_737 ,
40 ) ;
F_55 ( V_153 , V_5 -> V_156 | V_738 ,
40 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_739 ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) {
V_739 = ( V_734 |
V_735 |
V_158 ) ;
} else {
V_739 = V_158 ;
}
F_55 ( V_153 ,
V_5 -> V_156 | V_739 , 40 ) ;
}
}
if ( ! ( V_697 ) && ! F_23 ( V_5 , V_309 ) )
F_157 ( V_5 , V_569 ) ;
F_152 ( V_5 , true ) ;
if ( ( ! F_23 ( V_5 , V_264 ) ) &&
( ( F_146 ( V_5 ) == V_740 ) ||
( F_146 ( V_5 ) == V_741 ) ) ) {
T_1 V_7 = F_33 ( 0x7d00 ) ;
V_7 &= ~ ( ( 1 << 16 ) | ( 1 << 4 ) | ( 1 << 2 ) | ( 1 << 1 ) | 1 ) ;
F_46 ( 0x7d00 , V_7 ) ;
if ( ! F_23 ( V_5 , V_309 ) ) {
int V_75 ;
V_75 = F_158 ( V_5 ) ;
F_183 ( V_5 , V_654 ) ;
if ( ! V_75 )
F_159 ( V_5 ) ;
}
}
F_95 ( V_5 , V_110 ) ;
F_42 ( V_5 , V_110 ) ;
return 0 ;
}
static void F_201 ( struct V_4 * V_5 )
{
F_202 ( V_5 -> V_12 , F_23 ( V_5 , V_112 ) ) ;
F_197 ( V_5 -> V_12 , V_742 ) ;
}
static void F_203 ( struct V_4 * V_5 , T_1 V_7 , T_3 * V_373 , T_4 * V_377 )
{
switch ( V_7 & V_743 ) {
case V_744 :
* V_373 = V_374 ;
* V_377 = V_378 ;
break;
case V_745 :
* V_373 = V_374 ;
* V_377 = V_335 ;
break;
case V_746 :
* V_373 = V_333 ;
* V_377 = V_378 ;
break;
case V_747 :
* V_373 = V_333 ;
* V_377 = V_335 ;
break;
case V_748 :
* V_373 = V_332 ;
* V_377 = V_378 ;
break;
case V_749 :
* V_373 = V_332 ;
* V_377 = V_335 ;
break;
default:
if ( V_5 -> V_178 & V_179 ) {
* V_373 = ( V_7 & V_750 ) ? V_333 :
V_374 ;
* V_377 = ( V_7 & V_751 ) ? V_335 :
V_378 ;
break;
}
* V_373 = V_752 ;
* V_377 = V_753 ;
break;
}
}
static int F_204 ( struct V_4 * V_5 , T_1 V_754 , T_1 V_343 )
{
int V_75 = 0 ;
T_1 V_7 , V_755 ;
V_755 = V_756 ;
V_755 |= F_205 ( V_754 ) & V_757 ;
V_755 |= F_112 ( V_343 ) ;
V_75 = F_59 ( V_5 , V_304 , V_755 ) ;
if ( V_75 )
goto V_186;
if ( ! ( V_5 -> V_178 & V_393 ) ) {
V_755 = F_206 ( V_754 ) ;
if ( F_77 ( V_5 ) == V_758 ||
F_77 ( V_5 ) == V_759 )
V_755 |= V_495 | V_496 ;
V_75 = F_59 ( V_5 , V_180 , V_755 ) ;
if ( V_75 )
goto V_186;
}
if ( ! ( V_5 -> V_178 & V_339 ) )
goto V_186;
F_46 ( V_465 ,
F_33 ( V_465 ) & ~ V_476 ) ;
V_75 = F_66 ( V_5 , true ) ;
if ( ! V_75 ) {
T_1 V_760 ;
V_7 = 0 ;
if ( V_754 & V_708 )
V_7 |= V_761 ;
if ( V_754 & V_762 )
V_7 |= V_763 ;
if ( ! V_5 -> V_453 . V_463 ) {
V_7 = 0 ;
V_5 -> V_453 . V_464 = 0 ;
} else {
V_5 -> V_453 . V_464 = V_754 &
( V_708 |
V_762 ) ;
}
V_75 = F_60 ( V_5 , V_455 , V_462 , V_7 ) ;
if ( V_75 )
V_7 = 0 ;
switch ( F_30 ( V_5 ) ) {
case V_477 :
case V_764 :
case V_668 :
case V_478 :
if ( V_7 )
V_7 = V_479 |
V_480 |
V_765 ;
F_63 ( V_5 , V_475 , V_7 ) ;
case V_534 :
case V_766 :
if ( ! F_62 ( V_5 , V_767 , & V_7 ) )
F_63 ( V_5 , V_767 , V_7 |
V_768 ) ;
}
V_760 = F_66 ( V_5 , false ) ;
if ( ! V_75 )
V_75 = V_760 ;
}
V_186:
return V_75 ;
}
static void F_207 ( struct V_4 * V_5 )
{
if ( V_5 -> V_330 . V_353 == V_358 ||
( V_5 -> V_178 & V_400 ) ) {
T_1 V_342 , V_769 ;
if ( ( V_5 -> V_178 & V_400 ) &&
! ( V_5 -> V_178 & V_570 ) ) {
V_342 = V_705 |
V_709 ;
if ( F_23 ( V_5 , V_706 ) )
V_342 |= V_707 |
V_708 ;
if ( V_5 -> V_178 & V_770 )
V_342 |= V_771 |
V_762 ;
V_769 = V_337 | V_338 ;
} else {
V_342 = V_5 -> V_330 . V_399 ;
if ( V_5 -> V_178 & V_393 )
V_342 &= ~ ( V_771 |
V_762 ) ;
V_769 = V_5 -> V_330 . V_343 ;
}
F_204 ( V_5 , V_342 , V_769 ) ;
if ( ( V_5 -> V_178 & V_400 ) &&
( V_5 -> V_178 & V_570 ) ) {
return;
}
F_59 ( V_5 , V_204 ,
V_577 | V_578 ) ;
} else {
int V_42 ;
T_1 V_772 , V_773 ;
V_5 -> V_330 . V_331 = V_5 -> V_330 . V_373 ;
V_5 -> V_330 . V_334 = V_5 -> V_330 . V_377 ;
if ( F_30 ( V_5 ) == V_549 ) {
F_59 ( V_5 , V_304 , V_757 ) ;
}
V_772 = 0 ;
switch ( V_5 -> V_330 . V_373 ) {
default:
case V_374 :
break;
case V_333 :
V_772 |= V_774 ;
break;
case V_332 :
V_772 |= V_494 ;
break;
}
if ( V_5 -> V_330 . V_377 == V_335 )
V_772 |= V_493 ;
if ( ! F_57 ( V_5 , V_204 , & V_773 ) &&
( V_772 != V_773 ) ) {
F_59 ( V_5 , V_204 , V_775 ) ;
for ( V_42 = 0 ; V_42 < 1500 ; V_42 ++ ) {
T_1 V_597 ;
F_24 ( 10 ) ;
if ( F_57 ( V_5 , V_303 , & V_597 ) ||
F_57 ( V_5 , V_303 , & V_597 ) )
continue;
if ( ! ( V_597 & V_776 ) ) {
F_24 ( 40 ) ;
break;
}
}
F_59 ( V_5 , V_204 , V_772 ) ;
F_24 ( 40 ) ;
}
}
}
static int F_208 ( struct V_4 * V_5 )
{
int V_75 ;
T_1 V_7 ;
V_75 = F_57 ( V_5 , V_204 , & V_7 ) ;
if ( V_75 )
goto V_186;
if ( ! ( V_7 & V_577 ) ) {
V_5 -> V_330 . V_353 = V_777 ;
V_5 -> V_330 . V_399 = 0 ;
F_86 ( V_5 , V_359 ) ;
V_75 = - V_210 ;
switch ( V_7 & ( V_494 | V_774 ) ) {
case 0 :
if ( V_5 -> V_178 & V_360 )
goto V_186;
V_5 -> V_330 . V_373 = V_374 ;
break;
case V_774 :
if ( V_5 -> V_178 & V_360 )
goto V_186;
V_5 -> V_330 . V_373 = V_333 ;
break;
case V_494 :
if ( ! ( V_5 -> V_178 & V_393 ) ) {
V_5 -> V_330 . V_373 = V_332 ;
break;
}
default:
goto V_186;
}
if ( V_7 & V_493 )
V_5 -> V_330 . V_377 = V_335 ;
else
V_5 -> V_330 . V_377 = V_378 ;
V_5 -> V_330 . V_343 = V_338 | V_337 ;
V_75 = 0 ;
goto V_186;
}
V_5 -> V_330 . V_353 = V_358 ;
V_5 -> V_330 . V_399 = V_704 ;
F_84 ( V_5 , V_359 ) ;
if ( ! ( V_5 -> V_178 & V_360 ) ) {
T_1 V_342 ;
V_75 = F_57 ( V_5 , V_304 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_342 = F_209 ( V_7 & V_757 ) ;
V_5 -> V_330 . V_399 |= V_342 | V_702 ;
V_5 -> V_330 . V_343 = F_104 ( V_7 ) ;
} else {
V_5 -> V_330 . V_399 |= V_778 ;
}
if ( ! ( V_5 -> V_178 & V_393 ) ) {
T_1 V_342 ;
if ( ! ( V_5 -> V_178 & V_360 ) ) {
V_75 = F_57 ( V_5 , V_180 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_342 = F_210 ( V_7 ) ;
} else {
V_75 = F_57 ( V_5 , V_304 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_342 = F_106 ( V_7 ) ;
V_5 -> V_330 . V_343 = V_342 ;
V_7 &= ( V_779 | V_780 ) ;
V_342 = F_211 ( V_7 ) ;
}
V_5 -> V_330 . V_399 |= V_342 ;
}
V_186:
return V_75 ;
}
static int F_212 ( struct V_4 * V_5 )
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
static bool F_213 ( struct V_4 * V_5 )
{
struct V_452 V_453 ;
if ( ! ( V_5 -> V_178 & V_339 ) )
return true ;
F_132 ( V_5 , & V_453 ) ;
if ( V_5 -> V_453 . V_463 ) {
if ( V_5 -> V_453 . V_464 != V_453 . V_464 ||
V_5 -> V_453 . V_468 != V_453 . V_468 ||
V_5 -> V_453 . V_466 != V_453 . V_466 )
return false ;
} else {
if ( V_453 . V_464 )
return false ;
}
return true ;
}
static bool F_214 ( struct V_4 * V_5 , T_1 * V_350 )
{
T_1 V_781 , V_782 , V_399 ;
V_399 = V_5 -> V_330 . V_399 ;
V_782 = F_205 ( V_399 ) & V_757 ;
V_781 = V_757 ;
if ( V_5 -> V_330 . V_334 == V_335 ) {
V_782 |= F_112 ( V_5 -> V_330 . V_343 ) ;
V_781 |= V_344 | V_345 ;
}
if ( F_57 ( V_5 , V_304 , V_350 ) )
return false ;
if ( ( * V_350 & V_781 ) != V_782 )
return false ;
if ( ! ( V_5 -> V_178 & V_393 ) ) {
T_1 V_783 ;
V_782 = F_206 ( V_399 ) ;
if ( F_57 ( V_5 , V_180 , & V_783 ) )
return false ;
if ( V_782 &&
( F_77 ( V_5 ) == V_758 ||
F_77 ( V_5 ) == V_759 ) ) {
V_782 |= V_495 | V_496 ;
V_783 &= ( V_784 | V_785 |
V_495 | V_496 ) ;
} else {
V_783 &= ( V_784 | V_785 ) ;
}
if ( V_783 != V_782 )
return false ;
}
return true ;
}
static bool F_215 ( struct V_4 * V_5 , T_1 * V_351 )
{
T_1 V_786 = 0 ;
if ( ! ( V_5 -> V_178 & V_393 ) ) {
T_1 V_7 ;
if ( F_57 ( V_5 , V_307 , & V_7 ) )
return false ;
V_786 = F_216 ( V_7 ) ;
}
if ( F_57 ( V_5 , V_305 , V_351 ) )
return false ;
V_786 |= F_217 ( * V_351 ) ;
V_5 -> V_330 . V_370 = V_786 ;
return true ;
}
static bool F_218 ( struct V_4 * V_5 , bool V_787 )
{
if ( V_787 != V_5 -> V_341 ) {
if ( V_787 ) {
F_219 ( V_5 -> V_111 ) ;
} else {
F_141 ( V_5 -> V_111 ) ;
if ( V_5 -> V_178 & V_306 )
V_5 -> V_178 &= ~ V_788 ;
}
F_100 ( V_5 ) ;
return true ;
}
return false ;
}
static void F_220 ( struct V_4 * V_5 )
{
F_46 ( V_789 , 0 ) ;
F_31 ( V_790 ,
V_791 |
V_792 |
V_793 |
V_794 ) ;
F_24 ( 40 ) ;
}
static void F_221 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_7 = V_795 |
V_796 ;
if ( F_77 ( V_5 ) == V_328 )
V_7 |= V_797 ;
F_31 ( V_798 , V_7 ) ;
F_31 ( V_474 ,
V_799 ) ;
V_7 = V_800 |
( V_5 -> V_453 . V_466 ? V_467 : 0 ) |
V_801 |
V_802 ;
if ( F_30 ( V_5 ) != V_477 )
V_7 |= V_803 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_804 ;
F_31 ( V_465 , V_5 -> V_453 . V_463 ? V_7 : 0 ) ;
F_31 ( V_469 ,
V_805 |
( V_5 -> V_453 . V_468 & 0xffff ) ) ;
F_31 ( V_806 ,
V_807 |
V_808 ) ;
}
static int F_222 ( struct V_4 * V_5 , bool V_809 )
{
bool V_470 ;
T_1 V_810 , V_7 ;
T_1 V_369 , V_370 ;
T_3 V_811 ;
T_4 V_812 ;
int V_42 , V_75 ;
F_220 ( V_5 ) ;
if ( ( V_5 -> V_164 & V_165 ) != 0 ) {
F_31 ( V_166 ,
( V_5 -> V_164 & ~ V_165 ) ) ;
F_24 ( 80 ) ;
}
F_65 ( V_5 , V_585 , 0 ) ;
if ( ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ||
F_30 ( V_5 ) == V_502 ) &&
V_5 -> V_341 ) {
F_57 ( V_5 , V_303 , & V_810 ) ;
if ( ! F_57 ( V_5 , V_303 , & V_810 ) &&
! ( V_810 & V_776 ) )
V_809 = true ;
}
if ( V_809 )
F_144 ( V_5 ) ;
if ( ( V_5 -> V_216 & V_401 ) == V_402 ) {
F_57 ( V_5 , V_303 , & V_810 ) ;
if ( F_57 ( V_5 , V_303 , & V_810 ) ||
! F_23 ( V_5 , V_563 ) )
V_810 = 0 ;
if ( ! ( V_810 & V_776 ) ) {
V_75 = F_212 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_57 ( V_5 , V_303 , & V_810 ) ;
for ( V_42 = 0 ; V_42 < 1000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_303 , & V_810 ) &&
( V_810 & V_776 ) ) {
F_24 ( 40 ) ;
break;
}
}
if ( ( V_5 -> V_216 & V_813 ) ==
V_814 &&
! ( V_810 & V_776 ) &&
V_5 -> V_330 . V_331 == V_332 ) {
V_75 = F_144 ( V_5 ) ;
if ( ! V_75 )
V_75 = F_212 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
}
} else if ( F_77 ( V_5 ) == V_758 ||
F_77 ( V_5 ) == V_759 ) {
F_59 ( V_5 , 0x15 , 0x0a75 ) ;
F_59 ( V_5 , V_199 , 0x8c68 ) ;
F_59 ( V_5 , V_199 , 0x8d68 ) ;
F_59 ( V_5 , V_199 , 0x8c68 ) ;
}
F_57 ( V_5 , V_815 , & V_7 ) ;
F_57 ( V_5 , V_815 , & V_7 ) ;
if ( V_5 -> V_178 & V_816 )
F_59 ( V_5 , V_817 , ~ V_818 ) ;
else if ( ! ( V_5 -> V_178 & V_179 ) )
F_59 ( V_5 , V_817 , ~ 0 ) ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) {
if ( V_5 -> V_564 == V_819 )
F_59 ( V_5 , V_492 ,
V_820 ) ;
else
F_59 ( V_5 , V_492 , 0 ) ;
}
V_470 = false ;
V_811 = V_752 ;
V_812 = V_753 ;
V_5 -> V_178 &= ~ V_821 ;
V_5 -> V_330 . V_370 = 0 ;
if ( V_5 -> V_178 & V_822 ) {
V_75 = F_64 ( V_5 ,
V_823 ,
& V_7 ) ;
if ( ! V_75 && ! ( V_7 & ( 1 << 10 ) ) ) {
F_65 ( V_5 ,
V_823 ,
V_7 | ( 1 << 10 ) ) ;
goto V_824;
}
}
V_810 = 0 ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_57 ( V_5 , V_303 , & V_810 ) ;
if ( ! F_57 ( V_5 , V_303 , & V_810 ) &&
( V_810 & V_776 ) )
break;
F_24 ( 40 ) ;
}
if ( V_810 & V_776 ) {
T_1 V_825 , V_772 ;
F_57 ( V_5 , V_826 , & V_825 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_826 , & V_825 ) &&
V_825 )
break;
}
F_203 ( V_5 , V_825 ,
& V_811 ,
& V_812 ) ;
V_772 = 0 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_57 ( V_5 , V_204 , & V_772 ) ;
if ( F_57 ( V_5 , V_204 , & V_772 ) )
continue;
if ( V_772 && V_772 != 0x7fff )
break;
F_24 ( 10 ) ;
}
V_369 = 0 ;
V_370 = 0 ;
V_5 -> V_330 . V_331 = V_811 ;
V_5 -> V_330 . V_334 = V_812 ;
if ( V_5 -> V_330 . V_353 == V_358 ) {
bool V_827 = F_213 ( V_5 ) ;
if ( ( V_772 & V_577 ) &&
V_827 &&
F_214 ( V_5 , & V_369 ) &&
F_215 ( V_5 , & V_370 ) )
V_470 = true ;
if ( ! V_827 &&
( V_5 -> V_178 & V_570 ) &&
! V_809 ) {
F_221 ( V_5 ) ;
F_144 ( V_5 ) ;
}
} else {
if ( ! ( V_772 & V_577 ) &&
V_5 -> V_330 . V_373 == V_811 &&
V_5 -> V_330 . V_377 == V_812 ) {
V_470 = true ;
}
}
if ( V_470 &&
V_5 -> V_330 . V_334 == V_335 ) {
T_1 V_161 , V_44 ;
if ( V_5 -> V_178 & V_179 ) {
V_161 = V_828 ;
V_44 = V_829 ;
} else {
V_161 = V_830 ;
V_44 = V_831 ;
}
if ( ! F_57 ( V_5 , V_161 , & V_7 ) && ( V_7 & V_44 ) )
V_5 -> V_178 |= V_821 ;
F_108 ( V_5 , V_369 , V_370 ) ;
}
}
V_824:
if ( ! V_470 || ( V_5 -> V_178 & V_400 ) ) {
F_207 ( V_5 ) ;
if ( F_23 ( V_5 , V_265 ) ) {
V_470 = true ;
V_811 = V_332 ;
V_812 = V_335 ;
V_5 -> V_330 . V_331 = V_811 ;
V_5 -> V_330 . V_334 = V_812 ;
}
F_57 ( V_5 , V_303 , & V_810 ) ;
if ( ( ! F_57 ( V_5 , V_303 , & V_810 ) && ( V_810 & V_776 ) ) ||
( V_5 -> V_368 & V_832 ) )
V_470 = true ;
}
V_5 -> V_368 &= ~ V_371 ;
if ( V_470 ) {
if ( V_5 -> V_330 . V_331 == V_333 ||
V_5 -> V_330 . V_331 == V_374 )
V_5 -> V_368 |= V_375 ;
else
V_5 -> V_368 |= V_376 ;
} else if ( V_5 -> V_178 & V_179 )
V_5 -> V_368 |= V_375 ;
else
V_5 -> V_368 |= V_376 ;
if ( F_23 ( V_5 , V_833 ) ) {
T_1 V_564 = F_33 ( V_726 ) ;
V_564 &= ~ ( V_834 | V_835 ) ;
if ( V_5 -> V_330 . V_331 == V_374 )
V_564 |= V_836 ;
else if ( V_5 -> V_330 . V_331 == V_333 )
V_564 |= ( V_836 |
V_835 ) ;
else if ( V_5 -> V_330 . V_331 == V_332 )
V_564 |= ( V_836 |
V_834 ) ;
F_46 ( V_726 , V_564 ) ;
F_24 ( 40 ) ;
}
V_5 -> V_368 &= ~ V_372 ;
if ( V_5 -> V_330 . V_334 == V_378 )
V_5 -> V_368 |= V_372 ;
if ( F_30 ( V_5 ) == V_537 ) {
if ( V_470 &&
F_154 ( V_5 , V_5 -> V_330 . V_331 ) )
V_5 -> V_368 |= V_724 ;
else
V_5 -> V_368 &= ~ V_724 ;
}
if ( ( V_5 -> V_216 & V_401 ) == V_566 &&
F_77 ( V_5 ) == V_837 ) {
V_5 -> V_164 |= V_165 ;
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
}
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
F_134 ( V_5 , V_470 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
F_31 ( V_789 , 0 ) ;
} else {
F_31 ( V_789 , V_838 ) ;
}
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_537 &&
V_470 &&
V_5 -> V_330 . V_331 == V_332 &&
( F_23 ( V_5 , V_839 ) || F_23 ( V_5 , V_840 ) ) ) {
F_24 ( 120 ) ;
F_31 ( V_790 ,
( V_791 |
V_792 ) ) ;
F_24 ( 40 ) ;
F_29 ( V_5 ,
V_315 ,
V_841 ) ;
}
if ( F_23 ( V_5 , V_698 ) ) {
if ( V_5 -> V_330 . V_331 == V_333 ||
V_5 -> V_330 . V_331 == V_374 )
F_223 ( V_5 -> V_12 , V_699 ,
V_700 ) ;
else
F_199 ( V_5 -> V_12 , V_699 ,
V_700 ) ;
}
F_218 ( V_5 , V_470 ) ;
return 0 ;
}
static int F_224 ( struct V_4 * V_5 ,
struct V_842 * V_843 )
{
T_3 V_343 ;
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
if ( F_33 ( V_790 ) & V_856 ) {
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
V_5 -> V_368 |= V_870 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
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
V_343 = F_105 ( V_5 -> V_330 . V_343 ) ;
if ( V_343 & V_348 )
V_843 -> V_868 |= V_878 ;
if ( V_343 & V_349 )
V_843 -> V_868 |= V_879 ;
F_46 ( V_869 , V_843 -> V_868 ) ;
V_5 -> V_368 |= V_870 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
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
V_5 -> V_368 |= V_870 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
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
V_5 -> V_368 &= ~ V_870 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
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
static int F_225 ( struct V_4 * V_5 , T_1 * V_906 , T_1 * V_907 )
{
int V_626 = 0 ;
struct V_842 V_908 ;
int V_57 = V_885 ;
unsigned int V_909 ;
T_1 V_597 ;
F_31 ( V_869 , 0 ) ;
V_597 = V_5 -> V_368 & ~ V_371 ;
F_31 ( V_383 , V_597 | V_376 ) ;
F_24 ( 40 ) ;
F_31 ( V_383 , V_5 -> V_368 | V_870 ) ;
F_24 ( 40 ) ;
memset ( & V_908 , 0 , sizeof( V_908 ) ) ;
V_908 . V_10 |= V_860 ;
V_908 . V_846 = V_847 ;
V_908 . V_850 = 0 ;
V_909 = 0 ;
while ( ++ V_909 < 195000 ) {
V_57 = F_224 ( V_5 , & V_908 ) ;
if ( V_57 == V_875 || V_57 == V_885 )
break;
F_24 ( 1 ) ;
}
V_5 -> V_368 &= ~ V_870 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
* V_906 = V_908 . V_868 ;
* V_907 = V_908 . V_10 ;
if ( V_57 == V_875 &&
( V_908 . V_10 & ( V_863 | V_903 |
V_886 ) ) )
V_626 = 1 ;
return V_626 ;
}
static void F_226 ( struct V_4 * V_5 )
{
T_1 V_910 = F_33 ( V_790 ) ;
int V_42 ;
if ( F_23 ( V_5 , V_563 ) &&
! ( V_910 & V_911 ) )
return;
F_59 ( V_5 , 0x16 , 0x8007 ) ;
F_59 ( V_5 , V_204 , V_203 ) ;
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
static bool F_227 ( struct V_4 * V_5 , T_1 V_910 )
{
T_3 V_343 ;
bool V_470 ;
T_1 V_571 , V_912 ;
T_1 V_573 , V_913 ;
int V_914 , V_915 ;
V_573 = 0 ;
V_913 = 0 ;
V_914 = 0 ;
V_915 = 1 ;
V_470 = false ;
if ( F_77 ( V_5 ) != V_916 &&
F_77 ( V_5 ) != V_917 ) {
V_914 = 1 ;
if ( F_33 ( V_918 ) & V_919 )
V_915 = 0 ;
V_573 = F_33 ( V_574 ) & 0x00f06fff ;
}
V_571 = F_33 ( V_572 ) ;
if ( V_5 -> V_330 . V_353 != V_358 ) {
if ( V_571 & V_575 ) {
if ( V_914 ) {
T_1 V_7 = V_573 ;
if ( V_915 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_574 , V_7 ) ;
}
F_31 ( V_572 , V_920 ) ;
}
if ( V_910 & V_911 ) {
F_108 ( V_5 , 0 , 0 ) ;
V_470 = true ;
}
goto V_503;
}
V_913 = V_575 | V_920 ;
V_343 = F_105 ( V_5 -> V_330 . V_343 ) ;
if ( V_343 & V_348 )
V_913 |= V_921 ;
if ( V_343 & V_349 )
V_913 |= V_922 ;
if ( V_571 != V_913 ) {
if ( ( V_5 -> V_178 & V_788 ) &&
V_5 -> V_923 &&
( ( V_910 & ( V_911 |
V_856 ) ) ==
V_911 ) ) {
V_5 -> V_923 -- ;
V_470 = true ;
goto V_503;
}
V_924:
if ( V_914 )
F_31 ( V_574 , V_573 | 0xc011000 ) ;
F_31 ( V_572 , V_913 | V_576 ) ;
F_24 ( 5 ) ;
F_31 ( V_572 , V_913 ) ;
V_5 -> V_923 = V_925 ;
V_5 -> V_178 &= ~ V_788 ;
} else if ( V_910 & ( V_911 |
V_926 ) ) {
V_912 = F_33 ( V_260 ) ;
V_910 = F_33 ( V_790 ) ;
if ( ( V_912 & V_927 ) &&
( V_910 & V_911 ) ) {
T_1 V_928 = 0 , V_929 = 0 ;
if ( V_571 & V_921 )
V_928 |= V_348 ;
if ( V_571 & V_922 )
V_928 |= V_349 ;
if ( V_912 & V_930 )
V_929 |= V_931 ;
if ( V_912 & V_932 )
V_929 |= V_933 ;
V_5 -> V_330 . V_370 =
F_211 ( V_929 ) ;
F_108 ( V_5 , V_928 , V_929 ) ;
V_470 = true ;
V_5 -> V_923 = 0 ;
V_5 -> V_178 &= ~ V_788 ;
} else if ( ! ( V_912 & V_927 ) ) {
if ( V_5 -> V_923 )
V_5 -> V_923 -- ;
else {
if ( V_914 ) {
T_1 V_7 = V_573 ;
if ( V_915 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_574 , V_7 ) ;
}
F_31 ( V_572 , V_920 ) ;
F_24 ( 40 ) ;
V_910 = F_33 ( V_790 ) ;
if ( ( V_910 & V_911 ) &&
! ( V_910 & V_856 ) ) {
F_108 ( V_5 , 0 , 0 ) ;
V_470 = true ;
V_5 -> V_178 |=
V_788 ;
V_5 -> V_923 =
V_934 ;
} else
goto V_924;
}
}
} else {
V_5 -> V_923 = V_925 ;
V_5 -> V_178 &= ~ V_788 ;
}
V_503:
return V_470 ;
}
static bool F_228 ( struct V_4 * V_5 , T_1 V_910 )
{
bool V_470 = false ;
if ( ! ( V_910 & V_911 ) )
goto V_503;
if ( V_5 -> V_330 . V_353 == V_358 ) {
T_1 V_906 , V_907 ;
int V_42 ;
if ( F_225 ( V_5 , & V_906 , & V_907 ) ) {
T_1 V_928 = 0 , V_929 = 0 ;
if ( V_906 & V_878 )
V_928 |= V_348 ;
if ( V_906 & V_879 )
V_928 |= V_349 ;
if ( V_907 & V_888 )
V_929 |= V_931 ;
if ( V_907 & V_889 )
V_929 |= V_933 ;
V_5 -> V_330 . V_370 =
F_211 ( V_929 ) ;
F_108 ( V_5 , V_928 , V_929 ) ;
V_470 = true ;
}
for ( V_42 = 0 ; V_42 < 30 ; V_42 ++ ) {
F_24 ( 20 ) ;
F_31 ( V_790 ,
( V_791 |
V_792 ) ) ;
F_24 ( 40 ) ;
if ( ( F_33 ( V_790 ) &
( V_791 |
V_792 ) ) == 0 )
break;
}
V_910 = F_33 ( V_790 ) ;
if ( ! V_470 &&
( V_910 & V_911 ) &&
! ( V_910 & V_856 ) )
V_470 = true ;
} else {
F_108 ( V_5 , 0 , 0 ) ;
V_470 = true ;
F_31 ( V_383 , ( V_5 -> V_368 | V_870 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
}
V_503:
return V_470 ;
}
static int F_229 ( struct V_4 * V_5 , bool V_809 )
{
T_1 V_935 ;
T_3 V_936 ;
T_4 V_937 ;
T_1 V_910 ;
bool V_470 ;
int V_42 ;
V_935 = V_5 -> V_330 . V_336 ;
V_936 = V_5 -> V_330 . V_331 ;
V_937 = V_5 -> V_330 . V_334 ;
if ( ! F_23 ( V_5 , V_938 ) &&
V_5 -> V_341 &&
F_23 ( V_5 , V_563 ) ) {
V_910 = F_33 ( V_790 ) ;
V_910 &= ( V_911 |
V_926 |
V_792 |
V_856 ) ;
if ( V_910 == ( V_911 |
V_926 ) ) {
F_31 ( V_790 , ( V_791 |
V_792 ) ) ;
return 0 ;
}
}
F_31 ( V_869 , 0 ) ;
V_5 -> V_368 &= ~ ( V_371 | V_372 ) ;
V_5 -> V_368 |= V_725 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
if ( V_5 -> V_216 == V_939 )
F_226 ( V_5 ) ;
F_31 ( V_789 , V_838 ) ;
F_24 ( 40 ) ;
V_470 = false ;
V_5 -> V_330 . V_370 = 0 ;
V_910 = F_33 ( V_790 ) ;
if ( F_23 ( V_5 , V_938 ) )
V_470 = F_227 ( V_5 , V_910 ) ;
else
V_470 = F_228 ( V_5 , V_910 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 =
( V_135 |
( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & ~ V_144 ) ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_31 ( V_790 , ( V_791 |
V_792 ) ) ;
F_24 ( 5 ) ;
if ( ( F_33 ( V_790 ) & ( V_791 |
V_792 |
V_794 ) ) == 0 )
break;
}
V_910 = F_33 ( V_790 ) ;
if ( ( V_910 & V_911 ) == 0 ) {
V_470 = false ;
if ( V_5 -> V_330 . V_353 == V_358 &&
V_5 -> V_923 == 0 ) {
F_31 ( V_383 , ( V_5 -> V_368 |
V_870 ) ) ;
F_24 ( 1 ) ;
F_31 ( V_383 , V_5 -> V_368 ) ;
}
}
if ( V_470 ) {
V_5 -> V_330 . V_331 = V_332 ;
V_5 -> V_330 . V_334 = V_335 ;
F_46 ( V_726 , ( V_5 -> V_564 |
V_836 |
V_834 ) ) ;
} else {
V_5 -> V_330 . V_331 = V_752 ;
V_5 -> V_330 . V_334 = V_753 ;
F_46 ( V_726 , ( V_5 -> V_564 |
V_836 |
V_940 ) ) ;
}
if ( ! F_218 ( V_5 , V_470 ) ) {
T_1 V_941 = V_5 -> V_330 . V_336 ;
if ( V_935 != V_941 ||
V_936 != V_5 -> V_330 . V_331 ||
V_937 != V_5 -> V_330 . V_334 )
F_100 ( V_5 ) ;
}
return 0 ;
}
static int F_230 ( struct V_4 * V_5 , bool V_809 )
{
int V_75 = 0 ;
T_1 V_810 , V_772 ;
T_3 V_811 = V_752 ;
T_4 V_812 = V_753 ;
bool V_470 = false ;
T_1 V_928 , V_929 , V_942 ;
if ( ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ) &&
! F_57 ( V_5 , V_943 , & V_942 ) &&
( V_942 & V_944 ) ) {
if ( V_809 )
F_144 ( V_5 ) ;
V_5 -> V_368 &= ~ V_371 ;
if ( ! ( V_942 & V_945 ) ) {
V_5 -> V_368 |= V_376 ;
} else {
V_470 = true ;
if ( V_942 & V_946 ) {
V_811 = V_332 ;
V_5 -> V_368 |= V_376 ;
} else if ( V_942 & V_947 ) {
V_811 = V_333 ;
V_5 -> V_368 |= V_375 ;
} else {
V_811 = V_374 ;
V_5 -> V_368 |= V_375 ;
}
if ( V_942 & V_948 )
V_812 = V_335 ;
else
V_812 = V_378 ;
}
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
F_220 ( V_5 ) ;
goto V_949;
}
V_5 -> V_368 |= V_376 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
F_220 ( V_5 ) ;
if ( V_809 )
F_144 ( V_5 ) ;
V_5 -> V_330 . V_370 = 0 ;
V_75 |= F_57 ( V_5 , V_303 , & V_810 ) ;
V_75 |= F_57 ( V_5 , V_303 , & V_810 ) ;
if ( F_30 ( V_5 ) == V_549 ) {
if ( F_33 ( V_950 ) & V_951 )
V_810 |= V_776 ;
else
V_810 &= ~ V_776 ;
}
V_75 |= F_57 ( V_5 , V_204 , & V_772 ) ;
if ( ( V_5 -> V_330 . V_353 == V_358 ) && ! V_809 &&
( V_5 -> V_178 & V_788 ) ) {
} else if ( V_5 -> V_330 . V_353 == V_358 ) {
T_1 V_342 , V_952 ;
V_75 |= F_57 ( V_5 , V_304 , & V_342 ) ;
V_952 = V_342 & ~ ( V_780 | V_779 |
V_348 |
V_349 |
V_953 ) ;
V_952 |= F_105 ( V_5 -> V_330 . V_343 ) ;
V_952 |= F_231 ( V_5 -> V_330 . V_399 ) ;
if ( ( V_952 != V_342 ) || ! ( V_772 & V_577 ) ) {
F_59 ( V_5 , V_304 , V_952 ) ;
V_772 |= V_577 | V_578 ;
F_59 ( V_5 , V_204 , V_772 ) ;
F_31 ( V_789 , V_838 ) ;
V_5 -> V_923 = V_954 ;
V_5 -> V_178 &= ~ V_788 ;
return V_75 ;
}
} else {
T_1 V_955 ;
V_772 &= ~ V_494 ;
V_955 = V_772 & ~ ( V_577 | V_493 ) ;
if ( V_5 -> V_330 . V_377 == V_335 )
V_955 |= V_493 ;
if ( V_955 != V_772 ) {
V_955 |= V_494 ;
if ( V_5 -> V_341 ) {
T_1 V_342 ;
V_75 |= F_57 ( V_5 , V_304 , & V_342 ) ;
V_342 &= ~ ( V_780 |
V_779 |
V_953 ) ;
F_59 ( V_5 , V_304 , V_342 ) ;
F_59 ( V_5 , V_204 , V_772 |
V_578 |
V_577 ) ;
F_24 ( 10 ) ;
F_140 ( V_5 ) ;
}
F_59 ( V_5 , V_204 , V_955 ) ;
V_772 = V_955 ;
V_75 |= F_57 ( V_5 , V_303 , & V_810 ) ;
V_75 |= F_57 ( V_5 , V_303 , & V_810 ) ;
if ( F_30 ( V_5 ) == V_549 ) {
if ( F_33 ( V_950 ) & V_951 )
V_810 |= V_776 ;
else
V_810 &= ~ V_776 ;
}
V_5 -> V_178 &= ~ V_788 ;
}
}
if ( V_810 & V_776 ) {
V_811 = V_332 ;
V_470 = true ;
if ( V_772 & V_493 )
V_812 = V_335 ;
else
V_812 = V_378 ;
V_928 = 0 ;
V_929 = 0 ;
if ( V_772 & V_577 ) {
T_1 V_956 ;
V_75 |= F_57 ( V_5 , V_304 , & V_928 ) ;
V_75 |= F_57 ( V_5 , V_305 , & V_929 ) ;
V_956 = V_928 & V_929 ;
if ( V_956 & ( V_779 |
V_780 ) ) {
if ( V_956 & V_780 )
V_812 = V_335 ;
else
V_812 = V_378 ;
V_5 -> V_330 . V_370 =
F_211 ( V_929 ) ;
} else if ( ! F_23 ( V_5 , 5780_CLASS ) ) {
} else {
V_470 = false ;
}
}
}
V_949:
if ( V_470 && V_812 == V_335 )
F_108 ( V_5 , V_928 , V_929 ) ;
V_5 -> V_368 &= ~ V_372 ;
if ( V_5 -> V_330 . V_334 == V_378 )
V_5 -> V_368 |= V_372 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
F_31 ( V_789 , V_838 ) ;
V_5 -> V_330 . V_331 = V_811 ;
V_5 -> V_330 . V_334 = V_812 ;
F_218 ( V_5 , V_470 ) ;
return V_75 ;
}
static void F_232 ( struct V_4 * V_5 )
{
if ( V_5 -> V_923 ) {
V_5 -> V_923 -- ;
return;
}
if ( ! V_5 -> V_341 &&
( V_5 -> V_330 . V_353 == V_358 ) ) {
T_1 V_772 ;
F_57 ( V_5 , V_204 , & V_772 ) ;
if ( V_772 & V_577 ) {
T_1 V_957 , V_958 ;
F_59 ( V_5 , V_199 , 0x7c00 ) ;
F_57 ( V_5 , V_199 , & V_957 ) ;
F_59 ( V_5 , V_189 ,
V_959 ) ;
F_57 ( V_5 , V_190 , & V_958 ) ;
F_57 ( V_5 , V_190 , & V_958 ) ;
if ( ( V_957 & 0x10 ) && ! ( V_958 & 0x20 ) ) {
V_772 &= ~ V_577 ;
V_772 |= V_494 | V_493 ;
F_59 ( V_5 , V_204 , V_772 ) ;
V_5 -> V_178 |= V_788 ;
}
}
} else if ( V_5 -> V_341 &&
( V_5 -> V_330 . V_353 == V_358 ) &&
( V_5 -> V_178 & V_788 ) ) {
T_1 V_958 ;
F_59 ( V_5 , V_189 ,
V_959 ) ;
F_57 ( V_5 , V_190 , & V_958 ) ;
if ( V_958 & 0x20 ) {
T_1 V_772 ;
F_57 ( V_5 , V_204 , & V_772 ) ;
F_59 ( V_5 , V_204 , V_772 | V_577 ) ;
V_5 -> V_178 &= ~ V_788 ;
}
}
}
static int F_200 ( struct V_4 * V_5 , bool V_809 )
{
T_1 V_7 ;
int V_75 ;
if ( V_5 -> V_178 & V_568 )
V_75 = F_229 ( V_5 , V_809 ) ;
else if ( V_5 -> V_178 & V_306 )
V_75 = F_230 ( V_5 , V_809 ) ;
else
V_75 = F_222 ( V_5 , V_809 ) ;
if ( F_146 ( V_5 ) == V_504 ) {
T_1 V_960 ;
V_7 = F_33 ( V_961 ) & V_962 ;
if ( V_7 == V_963 )
V_960 = 65 ;
else if ( V_7 == V_964 )
V_960 = 6 ;
else
V_960 = 12 ;
V_7 = F_33 ( V_498 ) & ~ V_965 ;
V_7 |= ( V_960 << V_966 ) ;
F_46 ( V_498 , V_7 ) ;
}
V_7 = ( 2 << V_388 ) |
( 6 << V_389 ) ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_766 )
V_7 |= F_33 ( V_387 ) &
( V_967 |
V_968 ) ;
if ( V_5 -> V_330 . V_331 == V_332 &&
V_5 -> V_330 . V_334 == V_378 )
F_46 ( V_387 , V_7 |
( 0xff << V_390 ) ) ;
else
F_46 ( V_387 , V_7 |
( 32 << V_390 ) ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
if ( V_5 -> V_341 ) {
F_46 ( V_969 ,
V_5 -> V_970 . V_971 ) ;
} else {
F_46 ( V_969 , 0 ) ;
}
}
if ( F_23 ( V_5 , V_972 ) ) {
V_7 = F_33 ( V_973 ) ;
if ( ! V_5 -> V_341 )
V_7 = ( V_7 & ~ V_974 ) |
V_5 -> V_975 ;
else
V_7 |= V_974 ;
F_46 ( V_973 , V_7 ) ;
}
return V_75 ;
}
static T_6 F_233 ( struct V_4 * V_5 )
{
T_6 V_976 = F_33 ( V_977 ) ;
return V_976 | ( T_6 ) F_33 ( V_978 ) << 32 ;
}
static void F_234 ( struct V_4 * V_5 , T_6 V_979 )
{
T_1 V_980 = F_33 ( V_981 ) ;
F_46 ( V_981 , V_980 | V_982 ) ;
F_46 ( V_977 , V_979 & 0xffffffff ) ;
F_46 ( V_978 , V_979 >> 32 ) ;
F_31 ( V_981 , V_980 | V_983 ) ;
}
static int F_235 ( struct V_365 * V_111 , struct V_984 * V_985 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_985 -> V_986 = V_987 |
V_988 |
V_989 ;
if ( F_23 ( V_5 , V_990 ) ) {
V_985 -> V_986 |= V_991 |
V_992 |
V_993 ;
}
if ( V_5 -> V_994 )
V_985 -> V_995 = F_236 ( V_5 -> V_994 ) ;
else
V_985 -> V_995 = - 1 ;
V_985 -> V_996 = ( 1 << V_997 ) | ( 1 << V_998 ) ;
V_985 -> V_999 = ( 1 << V_1000 ) |
( 1 << V_1001 ) |
( 1 << V_1002 ) |
( 1 << V_1003 ) ;
return 0 ;
}
static int F_237 ( struct V_1004 * V_1005 , T_7 V_1006 )
{
struct V_4 * V_5 = F_238 ( V_1005 , struct V_4 , V_1007 ) ;
bool V_1008 = false ;
T_1 V_1009 = 0 ;
if ( V_1006 < 0 ) {
V_1008 = true ;
V_1006 = - V_1006 ;
}
V_1009 = F_239 ( ( T_6 ) V_1006 * ( 1 << 24 ) , 1000000000ULL ) &
V_1010 ;
F_240 ( V_5 , 0 ) ;
if ( V_1009 )
F_46 ( V_1011 ,
V_1012 |
( V_1008 ? V_1013 : 0 ) | V_1009 ) ;
else
F_46 ( V_1011 , 0 ) ;
F_241 ( V_5 ) ;
return 0 ;
}
static int F_242 ( struct V_1004 * V_1005 , T_8 V_844 )
{
struct V_4 * V_5 = F_238 ( V_1005 , struct V_4 , V_1007 ) ;
F_240 ( V_5 , 0 ) ;
V_5 -> V_1014 += V_844 ;
F_241 ( V_5 ) ;
return 0 ;
}
static int F_243 ( struct V_1004 * V_1005 , struct V_1015 * V_1016 )
{
T_6 V_1017 ;
T_1 V_1018 ;
struct V_4 * V_5 = F_238 ( V_1005 , struct V_4 , V_1007 ) ;
F_240 ( V_5 , 0 ) ;
V_1017 = F_233 ( V_5 ) ;
V_1017 += V_5 -> V_1014 ;
F_241 ( V_5 ) ;
V_1016 -> V_1019 = F_244 ( V_1017 , 1000000000 , & V_1018 ) ;
V_1016 -> V_1020 = V_1018 ;
return 0 ;
}
static int F_245 ( struct V_1004 * V_1005 ,
const struct V_1015 * V_1016 )
{
T_6 V_1017 ;
struct V_4 * V_5 = F_238 ( V_1005 , struct V_4 , V_1007 ) ;
V_1017 = F_246 ( V_1016 ) ;
F_240 ( V_5 , 0 ) ;
F_234 ( V_5 , V_1017 ) ;
V_5 -> V_1014 = 0 ;
F_241 ( V_5 ) ;
return 0 ;
}
static int F_247 ( struct V_1004 * V_1005 ,
struct V_1021 * V_1022 , int V_1023 )
{
struct V_4 * V_5 = F_238 ( V_1005 , struct V_4 , V_1007 ) ;
T_1 V_980 ;
int V_1024 = 0 ;
switch ( V_1022 -> type ) {
case V_1025 :
if ( V_1022 -> V_1026 . V_1027 != 0 )
return - V_64 ;
F_240 ( V_5 , 0 ) ;
V_980 = F_33 ( V_981 ) ;
V_980 &= ~ V_1028 ;
if ( V_1023 ) {
T_6 V_1029 ;
V_1029 = V_1022 -> V_1026 . V_1030 . V_1031 * 1000000000ULL +
V_1022 -> V_1026 . V_1030 . V_1029 ;
if ( V_1022 -> V_1026 . V_1032 . V_1031 || V_1022 -> V_1026 . V_1032 . V_1029 ) {
F_143 ( V_5 -> V_111 ,
L_28 ) ;
V_1024 = - V_64 ;
goto V_1033;
}
if ( V_1029 & ( 1ULL << 63 ) ) {
F_143 ( V_5 -> V_111 ,
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
F_241 ( V_5 ) ;
return V_1024 ;
default:
break;
}
return - V_1039 ;
}
static void F_248 ( struct V_4 * V_5 , T_6 V_1040 ,
struct V_1041 * V_1042 )
{
memset ( V_1042 , 0 , sizeof( struct V_1041 ) ) ;
V_1042 -> V_1043 = F_249 ( ( V_1040 & V_1044 ) +
V_5 -> V_1014 ) ;
}
static void F_250 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_990 ) )
return;
F_234 ( V_5 , F_251 ( F_252 () ) ) ;
V_5 -> V_1014 = 0 ;
V_5 -> V_1007 = V_1045 ;
}
static void F_253 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_990 ) )
return;
F_234 ( V_5 , F_251 ( F_252 () ) + V_5 -> V_1014 ) ;
V_5 -> V_1014 = 0 ;
}
static void F_254 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_990 ) || ! V_5 -> V_994 )
return;
F_255 ( V_5 -> V_994 ) ;
V_5 -> V_994 = NULL ;
V_5 -> V_1014 = 0 ;
}
static inline int F_256 ( struct V_4 * V_5 )
{
return V_5 -> V_125 ;
}
static inline void F_257 ( struct V_4 * V_5 , T_1 * V_1046 , T_1 V_6 , T_1 V_74 )
{
int V_42 ;
V_1046 = ( T_1 * ) ( ( T_4 * ) V_1046 + V_6 ) ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += sizeof( T_1 ) )
* V_1046 ++ = F_33 ( V_6 + V_42 ) ;
}
static void F_258 ( struct V_4 * V_5 , T_1 * V_8 )
{
F_257 ( V_5 , V_8 , V_1047 , 0xb0 ) ;
F_257 ( V_5 , V_8 , V_20 , 0x200 ) ;
F_257 ( V_5 , V_8 , V_383 , 0x4f0 ) ;
F_257 ( V_5 , V_8 , V_1048 , 0xe0 ) ;
F_257 ( V_5 , V_8 , V_1049 , 0x04 ) ;
F_257 ( V_5 , V_8 , V_1050 , 0x80 ) ;
F_257 ( V_5 , V_8 , V_1051 , 0x48 ) ;
F_257 ( V_5 , V_8 , V_1052 , 0x04 ) ;
F_257 ( V_5 , V_8 , V_1053 , 0x20 ) ;
F_257 ( V_5 , V_8 , V_1054 , 0x15c ) ;
F_257 ( V_5 , V_8 , V_1055 , 0x0c ) ;
F_257 ( V_5 , V_8 , V_1056 , 0x3c ) ;
F_257 ( V_5 , V_8 , V_1057 , 0x44 ) ;
F_257 ( V_5 , V_8 , V_1058 , 0x04 ) ;
F_257 ( V_5 , V_8 , V_1059 , 0x20 ) ;
F_257 ( V_5 , V_8 , V_1060 , 0x14 ) ;
F_257 ( V_5 , V_8 , V_1061 , 0x08 ) ;
F_257 ( V_5 , V_8 , V_1062 , 0x08 ) ;
F_257 ( V_5 , V_8 , V_138 , 0x100 ) ;
if ( F_23 ( V_5 , V_1063 ) )
F_257 ( V_5 , V_8 , V_1064 , 0x180 ) ;
F_257 ( V_5 , V_8 , V_1065 , 0x10 ) ;
F_257 ( V_5 , V_8 , V_1066 , 0x58 ) ;
F_257 ( V_5 , V_8 , V_1067 , 0x08 ) ;
F_257 ( V_5 , V_8 , V_1068 , 0x08 ) ;
F_257 ( V_5 , V_8 , V_1069 , 0x04 ) ;
F_257 ( V_5 , V_8 , V_1070 , 0x04 ) ;
F_257 ( V_5 , V_8 , V_1071 , 0x04 ) ;
F_257 ( V_5 , V_8 , V_678 , 0x04 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_257 ( V_5 , V_8 , V_1072 , 0x04 ) ;
F_257 ( V_5 , V_8 , V_1073 , 0x04 ) ;
F_257 ( V_5 , V_8 , V_1074 , 0x04 ) ;
}
F_257 ( V_5 , V_8 , V_1075 , 0x110 ) ;
F_257 ( V_5 , V_8 , V_1076 , 0x120 ) ;
F_257 ( V_5 , V_8 , V_1077 , 0x0c ) ;
F_257 ( V_5 , V_8 , V_1078 , 0x04 ) ;
F_257 ( V_5 , V_8 , V_647 , 0x4c ) ;
if ( F_23 ( V_5 , V_586 ) )
F_257 ( V_5 , V_8 , V_608 , 0x24 ) ;
}
static void F_259 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 * V_8 ;
V_8 = F_260 ( V_1079 , V_1080 ) ;
if ( ! V_8 )
return;
if ( F_23 ( V_5 , V_1081 ) ) {
for ( V_42 = 0 ; V_42 < V_1082 ; V_42 += sizeof( T_1 ) )
V_8 [ V_42 / sizeof( T_1 ) ] = F_33 ( V_42 ) ;
} else
F_258 ( V_5 , V_8 ) ;
for ( V_42 = 0 ; V_42 < V_1079 / sizeof( T_1 ) ; V_42 += 4 ) {
if ( ! V_8 [ V_42 + 0 ] && ! V_8 [ V_42 + 1 ] &&
! V_8 [ V_42 + 2 ] && ! V_8 [ V_42 + 3 ] )
continue;
F_185 ( V_5 -> V_111 , L_30 ,
V_42 * 4 ,
V_8 [ V_42 + 0 ] , V_8 [ V_42 + 1 ] , V_8 [ V_42 + 2 ] , V_8 [ V_42 + 3 ] ) ;
}
F_175 ( V_8 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_185 ( V_5 -> V_111 ,
L_31 ,
V_42 ,
V_131 -> V_134 -> V_57 ,
V_131 -> V_134 -> V_1083 ,
V_131 -> V_134 -> V_1084 ,
V_131 -> V_134 -> V_1085 ,
V_131 -> V_134 -> V_1086 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_1087 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_146 ) ;
F_185 ( V_5 -> V_111 ,
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
static void F_261 ( struct V_4 * V_5 )
{
F_184 ( F_23 ( V_5 , V_31 ) ||
V_5 -> V_1096 == F_20 ) ;
F_143 ( V_5 -> V_111 ,
L_33
L_34
L_35
L_36 ) ;
F_84 ( V_5 , V_1097 ) ;
}
static inline T_1 F_262 ( struct V_130 * V_131 )
{
F_263 () ;
return V_131 -> V_1090 -
( ( V_131 -> V_1089 - V_131 -> V_147 ) & ( V_1098 - 1 ) ) ;
}
static void F_264 ( struct V_130 * V_131 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1099 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
T_1 V_1100 = V_131 -> V_147 ;
struct V_1101 * V_1102 ;
int V_1027 = V_131 - V_5 -> V_123 ;
unsigned int V_1103 = 0 , V_1104 = 0 ;
if ( F_23 ( V_5 , V_1105 ) )
V_1027 -- ;
V_1102 = F_265 ( V_5 -> V_111 , V_1027 ) ;
while ( V_1100 != V_1099 ) {
struct V_1106 * V_1107 = & V_131 -> V_1108 [ V_1100 ] ;
struct V_1109 * V_1110 = V_1107 -> V_1110 ;
int V_42 , V_1111 = 0 ;
if ( F_266 ( V_1110 == NULL ) ) {
F_261 ( V_5 ) ;
return;
}
if ( V_131 -> V_1112 [ V_1100 ] . V_1113 & V_1114 ) {
struct V_1041 V_1042 ;
T_6 V_1040 = F_33 ( V_1115 ) ;
V_1040 |= ( T_6 ) F_33 ( V_1116 ) << 32 ;
F_248 ( V_5 , V_1040 , & V_1042 ) ;
F_267 ( V_1110 , & V_1042 ) ;
}
F_268 ( V_5 -> V_12 ,
F_269 ( V_1107 , V_1117 ) ,
F_270 ( V_1110 ) ,
V_1118 ) ;
V_1107 -> V_1110 = NULL ;
while ( V_1107 -> V_1119 ) {
V_1107 -> V_1119 = false ;
V_1100 = F_271 ( V_1100 ) ;
V_1107 = & V_131 -> V_1108 [ V_1100 ] ;
}
V_1100 = F_271 ( V_1100 ) ;
for ( V_42 = 0 ; V_42 < F_272 ( V_1110 ) -> V_1120 ; V_42 ++ ) {
V_1107 = & V_131 -> V_1108 [ V_1100 ] ;
if ( F_266 ( V_1107 -> V_1110 != NULL || V_1100 == V_1099 ) )
V_1111 = 1 ;
F_273 ( V_5 -> V_12 ,
F_269 ( V_1107 , V_1117 ) ,
F_274 ( & F_272 ( V_1110 ) -> V_1121 [ V_42 ] ) ,
V_1118 ) ;
while ( V_1107 -> V_1119 ) {
V_1107 -> V_1119 = false ;
V_1100 = F_271 ( V_1100 ) ;
V_1107 = & V_131 -> V_1108 [ V_1100 ] ;
}
V_1100 = F_271 ( V_1100 ) ;
}
V_1103 ++ ;
V_1104 += V_1110 -> V_74 ;
F_275 ( V_1110 ) ;
if ( F_266 ( V_1111 ) ) {
F_261 ( V_5 ) ;
return;
}
}
F_276 ( V_1102 , V_1103 , V_1104 ) ;
V_131 -> V_147 = V_1100 ;
F_277 () ;
if ( F_266 ( F_278 ( V_1102 ) &&
( F_262 ( V_131 ) > F_279 ( V_131 ) ) ) ) {
F_280 ( V_1102 , F_281 () ) ;
if ( F_278 ( V_1102 ) &&
( F_262 ( V_131 ) > F_279 ( V_131 ) ) )
F_282 ( V_1102 ) ;
F_283 ( V_1102 ) ;
}
}
static void F_284 ( bool V_1122 , void * V_72 )
{
if ( V_1122 )
F_285 ( F_286 ( V_72 ) ) ;
else
F_175 ( V_72 ) ;
}
static void F_287 ( struct V_4 * V_5 , struct V_1123 * V_1107 , T_1 V_1124 )
{
unsigned int V_1125 = F_288 ( V_1124 + F_289 ( V_5 ) ) +
F_288 ( sizeof( struct V_1126 ) ) ;
if ( ! V_1107 -> V_72 )
return;
F_268 ( V_5 -> V_12 , F_269 ( V_1107 , V_1117 ) ,
V_1124 , V_1127 ) ;
F_284 ( V_1125 <= V_1128 , V_1107 -> V_72 ) ;
V_1107 -> V_72 = NULL ;
}
static int F_290 ( struct V_4 * V_5 , struct V_1129 * V_1130 ,
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
V_1125 = F_288 ( V_1137 + F_289 ( V_5 ) ) +
F_288 ( sizeof( struct V_1126 ) ) ;
if ( V_1125 <= V_1128 ) {
V_72 = F_291 ( V_1125 ) ;
* V_1133 = V_1125 ;
} else {
V_72 = F_174 ( V_1125 , V_1080 ) ;
* V_1133 = 0 ;
}
if ( ! V_72 )
return - V_268 ;
V_1117 = F_292 ( V_5 -> V_12 ,
V_72 + F_289 ( V_5 ) ,
V_1137 ,
V_1127 ) ;
if ( F_266 ( F_293 ( V_5 -> V_12 , V_1117 ) ) ) {
F_284 ( V_1125 <= V_1128 , V_72 ) ;
return - V_210 ;
}
V_1136 -> V_72 = V_72 ;
F_294 ( V_1136 , V_1117 , V_1117 ) ;
V_1135 -> V_1150 = ( ( T_6 ) V_1117 >> 32 ) ;
V_1135 -> V_1151 = ( ( T_6 ) V_1117 & 0xffffffff ) ;
return V_1137 ;
}
static void F_295 ( struct V_130 * V_131 ,
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
F_294 ( V_1157 , V_1117 ,
F_269 ( V_1156 , V_1117 ) ) ;
V_1155 -> V_1150 = V_1154 -> V_1150 ;
V_1155 -> V_1151 = V_1154 -> V_1151 ;
F_296 () ;
V_1156 -> V_72 = NULL ;
}
static int F_297 ( struct V_130 * V_131 , int V_1159 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1160 , V_1161 = 0 ;
T_1 V_1162 , V_1163 ;
T_1 V_1100 = V_131 -> V_149 ;
T_3 V_1099 ;
int V_1164 ;
struct V_1129 * V_1130 = & V_131 -> V_1091 ;
V_1099 = * ( V_131 -> V_148 ) ;
F_298 () ;
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
V_1166 = F_269 ( V_1107 , V_1117 ) ;
V_72 = V_1107 -> V_72 ;
V_1168 = & V_1162 ;
V_1161 ++ ;
} else if ( V_1131 == V_1144 ) {
V_1107 = & V_5 -> V_123 [ 0 ] . V_1091 . V_1148 [ V_1167 ] ;
V_1166 = F_269 ( V_1107 , V_1117 ) ;
V_72 = V_1107 -> V_72 ;
V_1168 = & V_1163 ;
} else
goto V_1173;
V_1160 |= V_1131 ;
if ( ( V_1135 -> V_1174 & V_1175 ) != 0 &&
( V_1135 -> V_1174 != V_1176 ) ) {
V_1177:
F_295 ( V_131 , V_1130 , V_1131 ,
V_1167 , * V_1168 ) ;
V_1178:
V_5 -> V_1179 ++ ;
goto V_1180;
}
F_299 ( V_72 + F_289 ( V_5 ) ) ;
V_74 = ( ( V_1135 -> V_1181 & V_1182 ) >> V_1183 ) -
V_1184 ;
if ( ( V_1135 -> V_1185 & V_1186 ) ==
V_1187 ||
( V_1135 -> V_1185 & V_1186 ) ==
V_1188 ) {
V_1169 = F_33 ( V_1189 ) ;
V_1169 |= ( T_6 ) F_33 ( V_1190 ) << 32 ;
}
if ( V_74 > F_300 ( V_5 ) ) {
int V_1125 ;
unsigned int V_1133 ;
V_1125 = F_290 ( V_5 , V_1130 , V_1131 ,
* V_1168 , & V_1133 ) ;
if ( V_1125 < 0 )
goto V_1177;
F_268 ( V_5 -> V_12 , V_1166 , V_1125 ,
V_1127 ) ;
F_296 () ;
V_1107 -> V_72 = NULL ;
V_1110 = F_301 ( V_72 , V_1133 ) ;
if ( ! V_1110 ) {
F_284 ( V_1133 != 0 , V_72 ) ;
goto V_1178;
}
F_302 ( V_1110 , F_289 ( V_5 ) ) ;
} else {
F_295 ( V_131 , V_1130 , V_1131 ,
V_1167 , * V_1168 ) ;
V_1110 = F_303 ( V_5 -> V_111 ,
V_74 + V_1191 ) ;
if ( V_1110 == NULL )
goto V_1178;
F_302 ( V_1110 , V_1191 ) ;
F_304 ( V_5 -> V_12 , V_1166 , V_74 , V_1127 ) ;
memcpy ( V_1110 -> V_72 ,
V_72 + F_289 ( V_5 ) ,
V_74 ) ;
F_305 ( V_5 -> V_12 , V_1166 , V_74 , V_1127 ) ;
}
F_306 ( V_1110 , V_74 ) ;
if ( V_1169 )
F_248 ( V_5 , V_1169 ,
F_307 ( V_1110 ) ) ;
if ( ( V_5 -> V_111 -> V_1192 & V_1193 ) &&
( V_1135 -> V_1185 & V_1194 ) &&
( ( ( V_1135 -> V_1195 & V_1196 )
>> V_1197 ) == 0xffff ) )
V_1110 -> V_1198 = V_1199 ;
else
F_308 ( V_1110 ) ;
V_1110 -> V_1200 = F_309 ( V_1110 , V_5 -> V_111 ) ;
if ( V_74 > ( V_5 -> V_111 -> V_1201 + V_1202 ) &&
V_1110 -> V_1200 != F_310 ( V_1203 ) ) {
F_275 ( V_1110 ) ;
goto V_1178;
}
if ( V_1135 -> V_1185 & V_1204 &&
! ( V_5 -> V_355 & V_1205 ) )
F_311 ( V_1110 , F_310 ( V_1203 ) ,
V_1135 -> V_1174 & V_1206 ) ;
F_312 ( & V_131 -> V_123 , V_1110 ) ;
V_1164 ++ ;
V_1159 -- ;
V_1180:
( * V_1168 ) ++ ;
if ( F_266 ( V_1161 >= V_5 -> V_1207 ) ) {
V_1130 -> V_1092 = V_1162 &
V_5 -> V_1140 ;
F_313 ( V_18 ,
V_1130 -> V_1092 ) ;
V_1160 &= ~ V_1139 ;
V_1161 = 0 ;
}
V_1173:
V_1100 ++ ;
V_1100 &= V_5 -> V_1208 ;
if ( V_1100 == V_1099 ) {
V_1099 = * ( V_131 -> V_148 ) ;
F_298 () ;
}
}
V_131 -> V_149 = V_1100 ;
F_313 ( V_131 -> V_1209 , V_1100 ) ;
if ( ! F_23 ( V_5 , V_1210 ) ) {
F_49 () ;
if ( V_1160 & V_1139 ) {
V_1130 -> V_1092 = V_1162 &
V_5 -> V_1140 ;
F_313 ( V_18 ,
V_1130 -> V_1092 ) ;
}
if ( V_1160 & V_1144 ) {
V_1130 -> V_1094 = V_1163 &
V_5 -> V_1145 ;
F_313 ( V_1211 ,
V_1130 -> V_1094 ) ;
}
F_53 () ;
} else if ( V_1160 ) {
F_296 () ;
V_1130 -> V_1092 = V_1162 & V_5 -> V_1140 ;
V_1130 -> V_1094 = V_1163 & V_5 -> V_1145 ;
if ( V_131 != & V_5 -> V_123 [ 1 ] ) {
V_5 -> V_1212 = true ;
F_314 ( & V_5 -> V_123 [ 1 ] . V_123 ) ;
}
}
return V_1164 ;
}
static void F_315 ( struct V_4 * V_5 )
{
if ( ! ( F_23 ( V_5 , V_142 ) || F_23 ( V_5 , V_143 ) ) ) {
struct V_139 * V_140 = V_5 -> V_123 [ 0 ] . V_134 ;
if ( V_140 -> V_57 & V_144 ) {
V_140 -> V_57 = V_135 |
( V_140 -> V_57 & ~ V_144 ) ;
F_316 ( & V_5 -> V_209 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
F_31 ( V_790 ,
( V_791 |
V_792 |
V_793 |
V_794 ) ) ;
F_24 ( 40 ) ;
} else
F_200 ( V_5 , false ) ;
F_317 ( & V_5 -> V_209 ) ;
}
}
}
static int F_318 ( struct V_4 * V_5 ,
struct V_1129 * V_1152 ,
struct V_1129 * V_1158 )
{
T_1 V_1213 , V_1214 , V_1215 , V_1216 ;
int V_42 , V_75 = 0 ;
while ( 1 ) {
V_1216 = V_1158 -> V_1092 ;
F_319 () ;
if ( V_1158 -> V_1093 == V_1216 )
break;
if ( V_1158 -> V_1093 < V_1216 )
V_1215 = V_1216 - V_1158 -> V_1093 ;
else
V_1215 = V_5 -> V_1140 + 1 -
V_1158 -> V_1093 ;
V_1215 = F_320 ( V_1215 ,
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
F_319 () ;
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
F_319 () ;
if ( V_1158 -> V_1095 == V_1216 )
break;
if ( V_1158 -> V_1095 < V_1216 )
V_1215 = V_1216 - V_1158 -> V_1095 ;
else
V_1215 = V_5 -> V_1145 + 1 -
V_1158 -> V_1095 ;
V_1215 = F_320 ( V_1215 ,
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
F_319 () ;
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
static int F_321 ( struct V_130 * V_131 , int V_1220 , int V_1159 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
if ( V_131 -> V_134 -> V_145 [ 0 ] . V_146 != V_131 -> V_147 ) {
F_264 ( V_131 ) ;
if ( F_266 ( F_23 ( V_5 , V_1097 ) ) )
return V_1220 ;
}
if ( ! V_131 -> V_148 )
return V_1220 ;
if ( * ( V_131 -> V_148 ) != V_131 -> V_149 )
V_1220 += F_297 ( V_131 , V_1159 - V_1220 ) ;
if ( F_23 ( V_5 , V_1210 ) && V_131 == & V_5 -> V_123 [ 1 ] ) {
struct V_1129 * V_1152 = & V_5 -> V_123 [ 0 ] . V_1091 ;
int V_42 , V_75 = 0 ;
T_1 V_1162 = V_1152 -> V_1092 ;
T_1 V_1163 = V_1152 -> V_1094 ;
V_5 -> V_1212 = false ;
for ( V_42 = 1 ; V_42 <= V_5 -> V_1221 ; V_42 ++ )
V_75 |= F_318 ( V_5 , V_1152 ,
& V_5 -> V_123 [ V_42 ] . V_1091 ) ;
F_49 () ;
if ( V_1162 != V_1152 -> V_1092 )
F_313 ( V_18 ,
V_1152 -> V_1092 ) ;
if ( V_1163 != V_1152 -> V_1094 )
F_313 ( V_1211 ,
V_1152 -> V_1094 ) ;
F_53 () ;
if ( V_75 )
F_31 ( V_138 , V_5 -> V_126 ) ;
}
return V_1220 ;
}
static inline void F_322 ( struct V_4 * V_5 )
{
if ( ! F_323 ( V_1222 , V_5 -> V_1223 ) )
F_324 ( & V_5 -> V_1224 ) ;
}
static inline void F_325 ( struct V_4 * V_5 )
{
F_326 ( & V_5 -> V_1224 ) ;
F_86 ( V_5 , V_1225 ) ;
F_86 ( V_5 , V_1097 ) ;
}
static int F_327 ( struct V_1226 * V_123 , int V_1159 )
{
struct V_130 * V_131 = F_238 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1220 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
V_1220 = F_321 ( V_131 , V_1220 , V_1159 ) ;
if ( F_266 ( F_23 ( V_5 , V_1097 ) ) )
goto V_1227;
if ( F_266 ( V_1220 >= V_1159 ) )
break;
V_131 -> V_132 = V_140 -> V_1083 ;
V_131 -> V_1088 = V_131 -> V_132 ;
F_298 () ;
if ( F_328 ( V_140 -> V_145 [ 0 ] . V_146 == V_131 -> V_147 &&
* ( V_131 -> V_148 ) == V_131 -> V_149 ) ) {
if ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1212 )
continue;
F_329 ( V_123 ) ;
F_52 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
if ( F_266 ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1212 ) ) {
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
F_329 ( V_123 ) ;
F_322 ( V_5 ) ;
return V_1220 ;
}
static void F_330 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_1228 = false ;
if ( F_23 ( V_5 , V_1229 ) )
return;
V_7 = F_33 ( V_1230 ) ;
if ( V_7 & ~ V_1231 ) {
F_185 ( V_5 -> V_111 , L_37 ) ;
V_1228 = true ;
}
if ( F_33 ( V_1232 ) & ~ V_1233 ) {
F_185 ( V_5 -> V_111 , L_38 ) ;
V_1228 = true ;
}
if ( F_33 ( V_1234 ) || F_33 ( V_1235 ) ) {
F_185 ( V_5 -> V_111 , L_39 ) ;
V_1228 = true ;
}
if ( ! V_1228 )
return;
F_259 ( V_5 ) ;
F_84 ( V_5 , V_1229 ) ;
F_322 ( V_5 ) ;
}
static int F_331 ( struct V_1226 * V_123 , int V_1159 )
{
struct V_130 * V_131 = F_238 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1220 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
if ( V_140 -> V_57 & V_1236 )
F_330 ( V_5 ) ;
F_315 ( V_5 ) ;
V_1220 = F_321 ( V_131 , V_1220 , V_1159 ) ;
if ( F_266 ( F_23 ( V_5 , V_1097 ) ) )
goto V_1227;
if ( F_266 ( V_1220 >= V_1159 ) )
break;
if ( F_23 ( V_5 , V_133 ) ) {
V_131 -> V_132 = V_140 -> V_1083 ;
V_131 -> V_1088 = V_131 -> V_132 ;
F_298 () ;
} else
V_140 -> V_57 &= ~ V_135 ;
if ( F_328 ( ! F_50 ( V_131 ) ) ) {
F_329 ( V_123 ) ;
F_51 ( V_131 ) ;
break;
}
}
return V_1220 ;
V_1227:
F_329 ( V_123 ) ;
F_322 ( V_5 ) ;
return V_1220 ;
}
static void F_332 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- )
F_333 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static void F_334 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_335 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static void F_336 ( struct V_4 * V_5 )
{
int V_42 ;
F_337 ( V_5 -> V_111 , & V_5 -> V_123 [ 0 ] . V_123 , F_331 , 64 ) ;
for ( V_42 = 1 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_337 ( V_5 -> V_111 , & V_5 -> V_123 [ V_42 ] . V_123 , F_327 , 64 ) ;
}
static void F_338 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_339 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static inline void F_340 ( struct V_4 * V_5 )
{
V_5 -> V_111 -> V_1237 = V_299 ;
F_332 ( V_5 ) ;
F_141 ( V_5 -> V_111 ) ;
F_341 ( V_5 -> V_111 ) ;
}
static inline void F_342 ( struct V_4 * V_5 )
{
F_253 ( V_5 ) ;
F_343 ( V_5 -> V_111 ) ;
if ( V_5 -> V_341 )
F_219 ( V_5 -> V_111 ) ;
F_334 ( V_5 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 |= V_135 ;
F_48 ( V_5 ) ;
}
static void F_344 ( struct V_4 * V_5 )
{
int V_42 ;
F_184 ( V_5 -> V_125 ) ;
V_5 -> V_125 = 1 ;
F_277 () ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_345 ( V_5 -> V_123 [ V_42 ] . V_1238 ) ;
}
static inline void F_240 ( struct V_4 * V_5 , int V_125 )
{
F_70 ( & V_5 -> V_209 ) ;
if ( V_125 )
F_344 ( V_5 ) ;
}
static inline void F_241 ( struct V_4 * V_5 )
{
F_71 ( & V_5 -> V_209 ) ;
}
static T_10 F_346 ( int V_280 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_299 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1165 )
F_299 ( & V_131 -> V_1165 [ V_131 -> V_149 ] ) ;
if ( F_328 ( ! F_256 ( V_5 ) ) )
F_314 ( & V_131 -> V_123 ) ;
return V_1240 ;
}
static T_10 F_347 ( int V_280 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_299 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1165 )
F_299 ( & V_131 -> V_1165 [ V_131 -> V_149 ] ) ;
F_52 ( V_131 -> V_124 , 0x00000001 ) ;
if ( F_328 ( ! F_256 ( V_5 ) ) )
F_314 ( & V_131 -> V_123 ) ;
return F_348 ( 1 ) ;
}
static T_10 F_349 ( int V_280 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1241 = 1 ;
if ( F_266 ( ! ( V_140 -> V_57 & V_135 ) ) ) {
if ( F_23 ( V_5 , V_1242 ) ||
( F_33 ( V_1243 ) & V_1244 ) ) {
V_1241 = 0 ;
goto V_503;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
if ( F_256 ( V_5 ) )
goto V_503;
V_140 -> V_57 &= ~ V_135 ;
if ( F_328 ( F_50 ( V_131 ) ) ) {
F_299 ( & V_131 -> V_1165 [ V_131 -> V_149 ] ) ;
F_314 ( & V_131 -> V_123 ) ;
} else {
F_47 ( V_20 + V_16 ,
0x00000000 ) ;
}
V_503:
return F_348 ( V_1241 ) ;
}
static T_10 F_350 ( int V_280 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1241 = 1 ;
if ( F_266 ( V_140 -> V_1083 == V_131 -> V_1088 ) ) {
if ( F_23 ( V_5 , V_1242 ) ||
( F_33 ( V_1243 ) & V_1244 ) ) {
V_1241 = 0 ;
goto V_503;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
V_131 -> V_1088 = V_140 -> V_1083 ;
if ( F_256 ( V_5 ) )
goto V_503;
F_299 ( & V_131 -> V_1165 [ V_131 -> V_149 ] ) ;
F_314 ( & V_131 -> V_123 ) ;
V_503:
return F_348 ( V_1241 ) ;
}
static T_10 F_351 ( int V_280 , void * V_1239 )
{
struct V_130 * V_131 = V_1239 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
if ( ( V_140 -> V_57 & V_135 ) ||
! ( F_33 ( V_1243 ) & V_1244 ) ) {
F_45 ( V_5 ) ;
return F_348 ( 1 ) ;
}
return F_348 ( 0 ) ;
}
static void F_352 ( struct V_365 * V_111 )
{
int V_42 ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_256 ( V_5 ) )
return;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_349 ( V_5 -> V_123 [ V_42 ] . V_1238 , & V_5 -> V_123 [ V_42 ] ) ;
}
static void F_353 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_354 ( V_5 ) ) {
F_185 ( V_111 , L_40 ) ;
F_259 ( V_5 ) ;
}
F_322 ( V_5 ) ;
}
static inline int F_355 ( T_9 V_1117 , int V_74 )
{
T_1 V_1245 = ( T_1 ) V_1117 & 0xffffffff ;
return V_1245 + V_74 + 8 < V_1245 ;
}
static inline int F_356 ( struct V_4 * V_5 , T_9 V_1117 ,
T_1 V_74 , T_1 V_1246 )
{
if ( F_30 ( V_5 ) == V_766 && V_1246 ) {
T_1 V_1245 = ( T_1 ) V_1117 & 0xffffffff ;
return ( ( V_1245 + V_74 + ( V_1246 & 0x3fff ) ) < V_1245 ) ;
}
return 0 ;
}
static inline int F_357 ( struct V_4 * V_5 , T_9 V_1117 ,
int V_74 )
{
#if F_358 ( V_1247 ) && ( V_1248 == 64 )
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) )
return ( ( T_6 ) V_1117 + V_74 ) > F_359 ( 40 ) ;
return 0 ;
#else
return 0 ;
#endif
}
static inline void F_360 ( struct V_1249 * V_1250 ,
T_9 V_1117 , T_1 V_74 , T_1 V_10 ,
T_1 V_1246 , T_1 V_1251 )
{
V_1250 -> V_1150 = ( ( T_6 ) V_1117 >> 32 ) ;
V_1250 -> V_1151 = ( ( T_6 ) V_1117 & 0xffffffff ) ;
V_1250 -> V_1113 = ( V_74 << V_1252 ) | ( V_10 & 0x0000ffff ) ;
V_1250 -> V_1253 = ( V_1246 << V_1254 ) | ( V_1251 << V_1255 ) ;
}
static bool F_361 ( struct V_130 * V_131 , T_1 * V_1256 , T_1 * V_1159 ,
T_9 V_1136 , T_1 V_74 , T_1 V_10 ,
T_1 V_1246 , T_1 V_1251 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
bool V_1257 = false ;
if ( F_23 ( V_5 , V_1258 ) && V_74 <= 8 )
V_1257 = true ;
if ( F_355 ( V_1136 , V_74 ) )
V_1257 = true ;
if ( F_356 ( V_5 , V_1136 , V_74 , V_1246 ) )
V_1257 = true ;
if ( F_357 ( V_5 , V_1136 , V_74 ) )
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
F_360 ( & V_131 -> V_1112 [ * V_1256 ] , V_1136 ,
V_1263 , V_1261 , V_1246 , V_1251 ) ;
* V_1159 -= 1 ;
V_1260 = * V_1256 ;
* V_1256 = F_271 ( * V_1256 ) ;
V_1136 += V_1263 ;
}
if ( V_74 ) {
if ( * V_1159 ) {
F_360 ( & V_131 -> V_1112 [ * V_1256 ] , V_1136 ,
V_74 , V_10 , V_1246 , V_1251 ) ;
* V_1159 -= 1 ;
* V_1256 = F_271 ( * V_1256 ) ;
} else {
V_1257 = true ;
V_131 -> V_1108 [ V_1260 ] . V_1119 = false ;
}
}
} else {
F_360 ( & V_131 -> V_1112 [ * V_1256 ] , V_1136 ,
V_74 , V_10 , V_1246 , V_1251 ) ;
* V_1256 = F_271 ( * V_1256 ) ;
}
return V_1257 ;
}
static void F_362 ( struct V_130 * V_131 , T_1 V_1256 , int V_1264 )
{
int V_42 ;
struct V_1109 * V_1110 ;
struct V_1106 * V_1265 = & V_131 -> V_1108 [ V_1256 ] ;
V_1110 = V_1265 -> V_1110 ;
V_1265 -> V_1110 = NULL ;
F_268 ( V_131 -> V_5 -> V_12 ,
F_269 ( V_1265 , V_1117 ) ,
F_270 ( V_1110 ) ,
V_1118 ) ;
while ( V_1265 -> V_1119 ) {
V_1265 -> V_1119 = false ;
V_1256 = F_271 ( V_1256 ) ;
V_1265 = & V_131 -> V_1108 [ V_1256 ] ;
}
for ( V_42 = 0 ; V_42 <= V_1264 ; V_42 ++ ) {
const T_11 * V_1266 = & F_272 ( V_1110 ) -> V_1121 [ V_42 ] ;
V_1256 = F_271 ( V_1256 ) ;
V_1265 = & V_131 -> V_1108 [ V_1256 ] ;
F_273 ( V_131 -> V_5 -> V_12 ,
F_269 ( V_1265 , V_1117 ) ,
F_274 ( V_1266 ) , V_1118 ) ;
while ( V_1265 -> V_1119 ) {
V_1265 -> V_1119 = false ;
V_1256 = F_271 ( V_1256 ) ;
V_1265 = & V_131 -> V_1108 [ V_1256 ] ;
}
}
}
static int F_363 ( struct V_130 * V_131 ,
struct V_1109 * * V_1267 ,
T_1 * V_1256 , T_1 * V_1159 ,
T_1 V_1268 , T_1 V_1246 , T_1 V_1251 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_1109 * V_1269 , * V_1110 = * V_1267 ;
T_9 V_1270 = 0 ;
int V_56 = 0 ;
if ( F_30 ( V_5 ) != V_538 )
V_1269 = F_364 ( V_1110 , V_1080 ) ;
else {
int V_1271 = 4 - ( ( unsigned long ) V_1110 -> V_72 & 3 ) ;
V_1269 = F_365 ( V_1110 ,
F_366 ( V_1110 ) + V_1271 ,
F_367 ( V_1110 ) , V_1080 ) ;
}
if ( ! V_1269 ) {
V_56 = - 1 ;
} else {
V_1270 = F_292 ( V_5 -> V_12 , V_1269 -> V_72 , V_1269 -> V_74 ,
V_1118 ) ;
if ( F_293 ( V_5 -> V_12 , V_1270 ) ) {
F_275 ( V_1269 ) ;
V_56 = - 1 ;
} else {
T_1 V_1272 = * V_1256 ;
V_1268 |= V_1262 ;
V_131 -> V_1108 [ * V_1256 ] . V_1110 = V_1269 ;
F_294 ( & V_131 -> V_1108 [ * V_1256 ] ,
V_1117 , V_1270 ) ;
if ( F_361 ( V_131 , V_1256 , V_1159 , V_1270 ,
V_1269 -> V_74 , V_1268 ,
V_1246 , V_1251 ) ) {
F_362 ( V_131 , V_1272 , - 1 ) ;
F_275 ( V_1269 ) ;
V_56 = - 1 ;
}
}
}
F_275 ( V_1110 ) ;
* V_1267 = V_1269 ;
return V_56 ;
}
static int F_368 ( struct V_4 * V_5 , struct V_1109 * V_1110 )
{
struct V_1109 * V_1273 , * V_1274 ;
T_1 V_1275 = F_272 ( V_1110 ) -> V_1276 * 3 ;
if ( F_266 ( F_262 ( & V_5 -> V_123 [ 0 ] ) <= V_1275 ) ) {
F_369 ( V_5 -> V_111 ) ;
F_277 () ;
if ( F_262 ( & V_5 -> V_123 [ 0 ] ) <= V_1275 )
return V_1277 ;
F_370 ( V_5 -> V_111 ) ;
}
V_1273 = F_371 ( V_1110 , V_5 -> V_111 -> V_1192 & ~ V_1278 ) ;
if ( F_116 ( V_1273 ) )
goto V_1279;
do {
V_1274 = V_1273 ;
V_1273 = V_1273 -> V_1280 ;
V_1274 -> V_1280 = NULL ;
F_372 ( V_1274 , V_5 -> V_111 ) ;
} while ( V_1273 );
V_1279:
F_275 ( V_1110 ) ;
return V_1281 ;
}
static T_12 F_372 ( struct V_1109 * V_1110 , struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_74 , V_1256 , V_1268 , V_1246 , V_1251 = 0 ;
T_1 V_1159 ;
int V_42 = - 1 , V_1282 ;
T_9 V_1117 ;
struct V_130 * V_131 ;
struct V_1101 * V_1102 ;
unsigned int V_1264 ;
V_1102 = F_265 ( V_111 , F_373 ( V_1110 ) ) ;
V_131 = & V_5 -> V_123 [ F_373 ( V_1110 ) ] ;
if ( F_23 ( V_5 , V_1105 ) )
V_131 ++ ;
V_1159 = F_262 ( V_131 ) ;
if ( F_266 ( V_1159 <= ( F_272 ( V_1110 ) -> V_1120 + 1 ) ) ) {
if ( ! F_278 ( V_1102 ) ) {
F_374 ( V_1102 ) ;
F_185 ( V_111 ,
L_41 ) ;
}
return V_1277 ;
}
V_1256 = V_131 -> V_1089 ;
V_1268 = 0 ;
if ( V_1110 -> V_1198 == V_1283 )
V_1268 |= V_1284 ;
V_1246 = F_272 ( V_1110 ) -> V_1285 ;
if ( V_1246 ) {
struct V_1286 * V_1287 ;
T_1 V_1288 , V_1289 ;
if ( F_375 ( V_1110 ) &&
F_376 ( V_1110 , 0 , 0 , V_1080 ) )
goto V_1290;
V_1287 = F_377 ( V_1110 ) ;
V_1288 = F_378 ( V_1110 ) ;
V_1289 = F_379 ( V_1110 ) + F_380 ( V_1110 ) - V_1202 ;
if ( ! F_381 ( V_1110 ) ) {
V_1287 -> V_1291 = 0 ;
V_1287 -> V_1292 = F_310 ( V_1246 + V_1289 ) ;
}
if ( F_266 ( ( V_1202 + V_1289 ) > 80 ) &&
F_23 ( V_5 , V_1293 ) )
return F_368 ( V_5 , V_1110 ) ;
V_1268 |= ( V_1294 |
V_1295 ) ;
if ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ) {
F_382 ( V_1110 ) -> V_1291 = 0 ;
V_1268 &= ~ V_1284 ;
} else
F_382 ( V_1110 ) -> V_1291 = ~ F_383 ( V_1287 -> V_1299 ,
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
F_30 ( V_5 ) == V_502 ) {
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
if ( F_384 ( V_1110 ) ) {
V_1268 |= V_1307 ;
V_1251 = F_385 ( V_1110 ) ;
}
if ( ( F_266 ( F_272 ( V_1110 ) -> V_1308 & V_1309 ) ) &&
F_23 ( V_5 , V_1310 ) ) {
F_272 ( V_1110 ) -> V_1308 |= V_1311 ;
V_1268 |= V_1114 ;
}
V_74 = F_270 ( V_1110 ) ;
V_1117 = F_292 ( V_5 -> V_12 , V_1110 -> V_72 , V_74 , V_1118 ) ;
if ( F_293 ( V_5 -> V_12 , V_1117 ) )
goto V_1290;
V_131 -> V_1108 [ V_1256 ] . V_1110 = V_1110 ;
F_294 ( & V_131 -> V_1108 [ V_1256 ] , V_1117 , V_1117 ) ;
V_1282 = 0 ;
if ( F_23 ( V_5 , 5701_DMA_BUG ) )
V_1282 = 1 ;
if ( F_361 ( V_131 , & V_1256 , & V_1159 , V_1117 , V_74 , V_1268 |
( ( F_272 ( V_1110 ) -> V_1120 == 0 ) ? V_1262 : 0 ) ,
V_1246 , V_1251 ) ) {
V_1282 = 1 ;
} else if ( F_272 ( V_1110 ) -> V_1120 > 0 ) {
T_1 V_1312 = V_1246 ;
if ( ! F_23 ( V_5 , V_1296 ) &&
! F_23 ( V_5 , V_1297 ) &&
! F_23 ( V_5 , V_1298 ) )
V_1312 = 0 ;
V_1264 = F_272 ( V_1110 ) -> V_1120 - 1 ;
for ( V_42 = 0 ; V_42 <= V_1264 ; V_42 ++ ) {
T_11 * V_1266 = & F_272 ( V_1110 ) -> V_1121 [ V_42 ] ;
V_74 = F_274 ( V_1266 ) ;
V_1117 = F_386 ( & V_5 -> V_12 -> V_111 , V_1266 , 0 ,
V_74 , V_1313 ) ;
V_131 -> V_1108 [ V_1256 ] . V_1110 = NULL ;
F_294 ( & V_131 -> V_1108 [ V_1256 ] , V_1117 ,
V_1117 ) ;
if ( F_387 ( & V_5 -> V_12 -> V_111 , V_1117 ) )
goto V_1314;
if ( ! V_1159 ||
F_361 ( V_131 , & V_1256 , & V_1159 , V_1117 ,
V_74 , V_1268 |
( ( V_42 == V_1264 ) ? V_1262 : 0 ) ,
V_1312 , V_1251 ) ) {
V_1282 = 1 ;
break;
}
}
}
if ( V_1282 ) {
F_362 ( V_131 , V_131 -> V_1089 , V_42 ) ;
V_1256 = V_131 -> V_1089 ;
V_1159 = F_262 ( V_131 ) ;
if ( F_363 ( V_131 , & V_1110 , & V_1256 , & V_1159 ,
V_1268 , V_1246 , V_1251 ) )
goto V_1315;
}
F_388 ( V_1110 ) ;
F_389 ( V_1102 , V_1110 -> V_74 ) ;
F_49 () ;
F_390 ( V_131 -> V_1316 , V_1256 ) ;
V_131 -> V_1089 = V_1256 ;
if ( F_266 ( F_262 ( V_131 ) <= ( V_1317 + 1 ) ) ) {
F_374 ( V_1102 ) ;
F_277 () ;
if ( F_262 ( V_131 ) > F_279 ( V_131 ) )
F_282 ( V_1102 ) ;
}
F_53 () ;
return V_1281 ;
V_1314:
F_362 ( V_131 , V_131 -> V_1089 , -- V_42 ) ;
V_131 -> V_1108 [ V_131 -> V_1089 ] . V_1110 = NULL ;
V_1290:
F_275 ( V_1110 ) ;
V_1315:
V_5 -> V_1318 ++ ;
return V_1281 ;
}
static void F_391 ( struct V_4 * V_5 , bool V_195 )
{
if ( V_195 ) {
V_5 -> V_368 &= ~ ( V_372 |
V_371 ) ;
V_5 -> V_368 |= V_832 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_368 |= V_724 ;
if ( V_5 -> V_178 & V_393 )
V_5 -> V_368 |= V_375 ;
else
V_5 -> V_368 |= V_376 ;
} else {
V_5 -> V_368 &= ~ V_832 ;
if ( F_23 ( V_5 , 5705_PLUS ) ||
( V_5 -> V_178 & V_568 ) ||
F_30 ( V_5 ) == V_537 )
V_5 -> V_368 &= ~ V_724 ;
}
F_46 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
}
static int F_392 ( struct V_4 * V_5 , T_1 V_373 , bool V_1319 )
{
T_1 V_7 , V_772 , V_368 , V_1320 = 0 ;
F_128 ( V_5 , false ) ;
F_129 ( V_5 , false ) ;
if ( V_1319 && F_126 ( V_5 ) )
return - V_210 ;
V_772 = V_493 ;
switch ( V_373 ) {
case V_374 :
break;
case V_333 :
V_772 |= V_774 ;
break;
case V_332 :
default:
if ( V_5 -> V_178 & V_179 ) {
V_373 = V_333 ;
V_772 |= V_774 ;
} else {
V_373 = V_332 ;
V_772 |= V_494 ;
}
}
if ( V_1319 ) {
if ( ! ( V_5 -> V_178 & V_179 ) ) {
F_57 ( V_5 , V_180 , & V_7 ) ;
V_7 |= V_495 |
V_496 ;
F_59 ( V_5 , V_180 , V_7 ) ;
} else {
V_1320 = V_1321 |
V_1322 ;
F_59 ( V_5 , V_525 , V_1320 ) ;
}
} else
V_772 |= V_775 ;
F_59 ( V_5 , V_204 , V_772 ) ;
if ( V_5 -> V_178 & V_179 )
F_57 ( V_5 , V_204 , & V_772 ) ;
F_24 ( 40 ) ;
if ( ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) == V_257 ) {
F_59 ( V_5 , V_525 , V_1320 |
V_1323 |
V_1324 ) ;
F_57 ( V_5 , V_525 , & V_7 ) ;
}
if ( ( V_5 -> V_178 & V_306 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_31 ( V_362 , V_1325 ) ;
F_24 ( 10 ) ;
F_31 ( V_362 , V_5 -> V_355 ) ;
}
V_368 = V_5 -> V_368 &
~ ( V_371 | V_372 ) ;
if ( V_373 == V_332 )
V_368 |= V_376 ;
else
V_368 |= V_375 ;
if ( F_30 ( V_5 ) == V_537 ) {
T_1 V_1326 = V_5 -> V_216 & V_401 ;
if ( V_1326 == V_402 )
V_368 &= ~ V_724 ;
else if ( V_1326 == V_566 )
V_368 |= V_724 ;
F_59 ( V_5 , V_492 ,
V_820 ) ;
}
F_46 ( V_383 , V_368 ) ;
F_24 ( 40 ) ;
return 0 ;
}
static void F_393 ( struct V_365 * V_111 , T_13 V_1192 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_1192 & V_1327 ) {
if ( V_5 -> V_368 & V_832 )
return;
F_70 ( & V_5 -> V_209 ) ;
F_391 ( V_5 , true ) ;
F_219 ( V_5 -> V_111 ) ;
F_71 ( & V_5 -> V_209 ) ;
F_98 ( V_111 , L_42 ) ;
} else {
if ( ! ( V_5 -> V_368 & V_832 ) )
return;
F_70 ( & V_5 -> V_209 ) ;
F_391 ( V_5 , false ) ;
F_200 ( V_5 , true ) ;
F_71 ( & V_5 -> V_209 ) ;
F_98 ( V_111 , L_43 ) ;
}
}
static T_13 F_394 ( struct V_365 * V_111 ,
T_13 V_1192 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_111 -> V_1201 > V_1328 && F_23 ( V_5 , 5780_CLASS ) )
V_1192 &= ~ V_1329 ;
return V_1192 ;
}
static int F_395 ( struct V_365 * V_111 , T_13 V_1192 )
{
T_13 V_1330 = V_111 -> V_1192 ^ V_1192 ;
if ( ( V_1330 & V_1327 ) && F_145 ( V_111 ) )
F_393 ( V_111 , V_1192 ) ;
return 0 ;
}
static void F_396 ( struct V_4 * V_5 ,
struct V_1129 * V_1130 )
{
int V_42 ;
if ( V_1130 != & V_5 -> V_123 [ 0 ] . V_1091 ) {
for ( V_42 = V_1130 -> V_1093 ; V_42 != V_1130 -> V_1092 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1140 )
F_287 ( V_5 , & V_1130 -> V_1142 [ V_42 ] ,
V_5 -> V_1143 ) ;
if ( F_23 ( V_5 , V_522 ) ) {
for ( V_42 = V_1130 -> V_1095 ;
V_42 != V_1130 -> V_1094 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1145 ) {
F_287 ( V_5 , & V_1130 -> V_1148 [ V_42 ] ,
V_1149 ) ;
}
}
return;
}
for ( V_42 = 0 ; V_42 <= V_5 -> V_1140 ; V_42 ++ )
F_287 ( V_5 , & V_1130 -> V_1142 [ V_42 ] ,
V_5 -> V_1143 ) ;
if ( F_23 ( V_5 , V_522 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
for ( V_42 = 0 ; V_42 <= V_5 -> V_1145 ; V_42 ++ )
F_287 ( V_5 , & V_1130 -> V_1148 [ V_42 ] ,
V_1149 ) ;
}
}
static int F_397 ( struct V_4 * V_5 ,
struct V_1129 * V_1130 )
{
T_1 V_42 , V_1331 ;
V_1130 -> V_1093 = 0 ;
V_1130 -> V_1092 = 0 ;
V_1130 -> V_1095 = 0 ;
V_1130 -> V_1094 = 0 ;
if ( V_1130 != & V_5 -> V_123 [ 0 ] . V_1091 ) {
memset ( & V_1130 -> V_1142 [ 0 ] , 0 ,
F_398 ( V_5 ) ) ;
if ( V_1130 -> V_1148 )
memset ( & V_1130 -> V_1148 [ 0 ] , 0 ,
F_399 ( V_5 ) ) ;
goto V_186;
}
memset ( V_1130 -> V_1141 , 0 , F_400 ( V_5 ) ) ;
V_1331 = V_1332 ;
if ( F_23 ( V_5 , 5780_CLASS ) &&
V_5 -> V_111 -> V_1201 > V_1328 )
V_1331 = V_1333 ;
V_5 -> V_1143 = F_401 ( V_1331 ) ;
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
if ( F_290 ( V_5 , V_1130 , V_1139 , V_42 ,
& V_1133 ) < 0 ) {
F_143 ( V_5 -> V_111 ,
L_44
L_45
L_46 , V_42 , V_5 -> V_1338 ) ;
if ( V_42 == 0 )
goto V_1339;
V_5 -> V_1338 = V_42 ;
break;
}
}
if ( ! F_23 ( V_5 , V_522 ) || F_23 ( V_5 , 5780_CLASS ) )
goto V_186;
memset ( V_1130 -> V_1146 , 0 , F_402 ( V_5 ) ) ;
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
if ( F_290 ( V_5 , V_1130 , V_1144 , V_42 ,
& V_1133 ) < 0 ) {
F_143 ( V_5 -> V_111 ,
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
F_396 ( V_5 , V_1130 ) ;
return - V_268 ;
}
static void F_403 ( struct V_4 * V_5 ,
struct V_1129 * V_1130 )
{
F_175 ( V_1130 -> V_1142 ) ;
V_1130 -> V_1142 = NULL ;
F_175 ( V_1130 -> V_1148 ) ;
V_1130 -> V_1148 = NULL ;
if ( V_1130 -> V_1141 ) {
F_404 ( & V_5 -> V_12 -> V_111 , F_400 ( V_5 ) ,
V_1130 -> V_1141 , V_1130 -> V_1343 ) ;
V_1130 -> V_1141 = NULL ;
}
if ( V_1130 -> V_1146 ) {
F_404 ( & V_5 -> V_12 -> V_111 , F_402 ( V_5 ) ,
V_1130 -> V_1146 , V_1130 -> V_1344 ) ;
V_1130 -> V_1146 = NULL ;
}
}
static int F_405 ( struct V_4 * V_5 ,
struct V_1129 * V_1130 )
{
V_1130 -> V_1142 = F_260 ( F_398 ( V_5 ) ,
V_633 ) ;
if ( ! V_1130 -> V_1142 )
return - V_268 ;
V_1130 -> V_1141 = F_406 ( & V_5 -> V_12 -> V_111 ,
F_400 ( V_5 ) ,
& V_1130 -> V_1343 ,
V_633 ) ;
if ( ! V_1130 -> V_1141 )
goto V_1033;
if ( F_23 ( V_5 , V_522 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
V_1130 -> V_1148 = F_260 ( F_399 ( V_5 ) ,
V_633 ) ;
if ( ! V_1130 -> V_1148 )
goto V_1033;
V_1130 -> V_1146 = F_406 ( & V_5 -> V_12 -> V_111 ,
F_402 ( V_5 ) ,
& V_1130 -> V_1344 ,
V_633 ) ;
if ( ! V_1130 -> V_1146 )
goto V_1033;
}
return 0 ;
V_1033:
F_403 ( V_5 , V_1130 ) ;
return - V_268 ;
}
static void F_407 ( struct V_4 * V_5 )
{
int V_42 , V_628 ;
for ( V_628 = 0 ; V_628 < V_5 -> V_129 ; V_628 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_628 ] ;
F_396 ( V_5 , & V_131 -> V_1091 ) ;
if ( ! V_131 -> V_1108 )
continue;
for ( V_42 = 0 ; V_42 < V_1098 ; V_42 ++ ) {
struct V_1109 * V_1110 = V_131 -> V_1108 [ V_42 ] . V_1110 ;
if ( ! V_1110 )
continue;
F_362 ( V_131 , V_42 ,
F_272 ( V_1110 ) -> V_1120 - 1 ) ;
F_408 ( V_1110 ) ;
}
F_409 ( F_265 ( V_5 -> V_111 , V_628 ) ) ;
}
}
static int F_410 ( struct V_4 * V_5 )
{
int V_42 ;
F_407 ( V_5 ) ;
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
memset ( V_131 -> V_1165 , 0 , F_411 ( V_5 ) ) ;
if ( F_397 ( V_5 , & V_131 -> V_1091 ) ) {
F_407 ( V_5 ) ;
return - V_268 ;
}
}
return 0 ;
}
static void F_412 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_1112 ) {
F_404 ( & V_5 -> V_12 -> V_111 , V_1346 ,
V_131 -> V_1112 , V_131 -> V_1347 ) ;
V_131 -> V_1112 = NULL ;
}
F_175 ( V_131 -> V_1108 ) ;
V_131 -> V_1108 = NULL ;
}
}
static int F_413 ( struct V_4 * V_5 )
{
int V_42 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
if ( F_23 ( V_5 , V_1105 ) )
V_131 ++ ;
for ( V_42 = 0 ; V_42 < V_5 -> V_1348 ; V_42 ++ , V_131 ++ ) {
V_131 -> V_1108 = F_260 ( sizeof( struct V_1106 ) *
V_1098 , V_633 ) ;
if ( ! V_131 -> V_1108 )
goto V_1033;
V_131 -> V_1112 = F_406 ( & V_5 -> V_12 -> V_111 ,
V_1346 ,
& V_131 -> V_1347 ,
V_633 ) ;
if ( ! V_131 -> V_1112 )
goto V_1033;
}
return 0 ;
V_1033:
F_412 ( V_5 ) ;
return - V_268 ;
}
static void F_414 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_403 ( V_5 , & V_131 -> V_1091 ) ;
if ( ! V_131 -> V_1165 )
continue;
F_404 ( & V_5 -> V_12 -> V_111 ,
F_411 ( V_5 ) ,
V_131 -> V_1165 ,
V_131 -> V_1349 ) ;
V_131 -> V_1165 = NULL ;
}
}
static int F_415 ( struct V_4 * V_5 )
{
unsigned int V_42 , V_202 ;
V_202 = V_5 -> V_1221 ;
if ( F_23 ( V_5 , V_1210 ) )
V_202 ++ ;
for ( V_42 = 0 ; V_42 < V_202 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( F_405 ( V_5 , & V_131 -> V_1091 ) )
goto V_1033;
if ( ! V_42 && F_23 ( V_5 , V_1210 ) )
continue;
V_131 -> V_1165 = F_416 ( & V_5 -> V_12 -> V_111 ,
F_411 ( V_5 ) ,
& V_131 -> V_1349 ,
V_633 ) ;
if ( ! V_131 -> V_1165 )
goto V_1033;
}
return 0 ;
V_1033:
F_414 ( V_5 ) ;
return - V_268 ;
}
static void F_417 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
F_404 ( & V_5 -> V_12 -> V_111 , V_1345 ,
V_131 -> V_134 ,
V_131 -> V_1350 ) ;
V_131 -> V_134 = NULL ;
}
}
F_414 ( V_5 ) ;
F_412 ( V_5 ) ;
if ( V_5 -> V_1351 ) {
F_404 ( & V_5 -> V_12 -> V_111 , sizeof( struct V_1352 ) ,
V_5 -> V_1351 , V_5 -> V_1353 ) ;
V_5 -> V_1351 = NULL ;
}
}
static int F_418 ( struct V_4 * V_5 )
{
int V_42 ;
V_5 -> V_1351 = F_416 ( & V_5 -> V_12 -> V_111 ,
sizeof( struct V_1352 ) ,
& V_5 -> V_1353 , V_633 ) ;
if ( ! V_5 -> V_1351 )
goto V_1033;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
struct V_139 * V_140 ;
V_131 -> V_134 = F_416 ( & V_5 -> V_12 -> V_111 ,
V_1345 ,
& V_131 -> V_1350 ,
V_633 ) ;
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
if ( F_413 ( V_5 ) || F_415 ( V_5 ) )
goto V_1033;
return 0 ;
V_1033:
F_417 ( V_5 ) ;
return - V_268 ;
}
static int F_419 ( struct V_4 * V_5 , unsigned long V_1356 , T_1 V_1357 , bool V_1358 )
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
F_117 ( & V_5 -> V_12 -> V_111 ,
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
F_117 ( & V_5 -> V_12 -> V_111 ,
L_51 ,
V_1356 , V_1357 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_420 ( struct V_4 * V_5 , bool V_1358 )
{
int V_42 , V_75 ;
F_45 ( V_5 ) ;
if ( F_36 ( V_5 -> V_12 ) ) {
V_5 -> V_355 &= ~ ( V_732 | V_1360 ) ;
V_5 -> V_368 &= ~ V_731 ;
V_75 = - V_82 ;
goto V_1361;
}
V_5 -> V_355 &= ~ V_732 ;
F_31 ( V_362 , V_5 -> V_355 ) ;
F_24 ( 10 ) ;
V_75 = F_419 ( V_5 , V_1059 , V_1362 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1053 , V_1363 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1061 , V_1364 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1055 , V_1365 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1058 , V_1366 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1060 , V_1367 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1050 , V_1368 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1051 , V_1369 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1048 , V_1370 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1067 , V_1371 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1049 , V_1372 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1078 , V_1373 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1052 , V_1374 , V_1358 ) ;
V_5 -> V_368 &= ~ V_731 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
V_5 -> V_357 &= ~ V_1360 ;
F_31 ( V_364 , V_5 -> V_357 ) ;
for ( V_42 = 0 ; V_42 < V_1359 ; V_42 ++ ) {
F_24 ( 100 ) ;
if ( ! ( F_33 ( V_364 ) & V_1360 ) )
break;
}
if ( V_42 >= V_1359 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_52
L_53 , V_658 , F_33 ( V_364 ) ) ;
V_75 |= - V_82 ;
}
V_75 |= F_419 ( V_5 , V_138 , V_128 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1068 , V_1375 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1062 , V_1376 , V_1358 ) ;
F_46 ( V_1076 , 0xffffffff ) ;
F_46 ( V_1076 , 0x00000000 ) ;
V_75 |= F_419 ( V_5 , V_1066 , V_1377 , V_1358 ) ;
V_75 |= F_419 ( V_5 , V_1065 , V_1378 , V_1358 ) ;
V_1361:
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 )
memset ( V_131 -> V_134 , 0 , V_1345 ) ;
}
return V_75 ;
}
static void F_421 ( struct V_4 * V_5 )
{
F_422 ( V_5 -> V_12 , V_1379 , & V_5 -> V_1380 ) ;
}
static void F_423 ( struct V_4 * V_5 )
{
T_1 V_7 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
V_7 = ( V_1381 | V_1382 ) ;
if ( F_77 ( V_5 ) == V_916 &&
F_23 ( V_5 , V_839 ) )
V_7 |= V_1383 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_1384 |
V_1385 |
V_1386 ;
F_15 ( V_5 -> V_12 , V_1243 , V_7 ) ;
F_424 ( V_5 -> V_12 , V_1379 , V_5 -> V_1380 ) ;
if ( ! F_23 ( V_5 , V_1081 ) ) {
F_425 ( V_5 -> V_12 , V_1387 ,
V_5 -> V_1388 ) ;
F_425 ( V_5 -> V_12 , V_1389 ,
V_5 -> V_1390 ) ;
}
if ( F_23 ( V_5 , V_839 ) ) {
T_3 V_1391 ;
F_422 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
& V_1391 ) ;
V_1391 &= ~ V_1394 ;
F_424 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
V_1391 ) ;
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_1395 ) ) {
T_3 V_1396 ;
F_422 ( V_5 -> V_12 ,
V_5 -> V_1397 + V_1398 ,
& V_1396 ) ;
F_424 ( V_5 -> V_12 ,
V_5 -> V_1397 + V_1398 ,
V_1396 | V_1399 ) ;
V_7 = F_33 ( V_1077 ) ;
F_46 ( V_1077 , V_7 | V_1400 ) ;
}
}
}
static int F_426 ( struct V_4 * V_5 )
{
T_1 V_7 ;
void (* F_188)( struct V_4 * , T_1 , T_1 );
int V_42 , V_75 ;
if ( ! F_427 ( V_5 -> V_12 ) )
return - V_82 ;
F_158 ( V_5 ) ;
F_35 ( V_5 , V_61 ) ;
V_5 -> V_587 = 0 ;
F_421 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_641 ||
F_23 ( V_5 , 5755_PLUS ) )
F_46 ( V_1401 , 0 ) ;
F_188 = V_5 -> V_27 ;
if ( F_188 == F_17 )
V_5 -> V_27 = F_7 ;
F_84 ( V_5 , V_1242 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
V_131 -> V_134 -> V_57 = 0 ;
V_131 -> V_134 -> V_1083 = 0 ;
}
V_131 -> V_132 = 0 ;
V_131 -> V_1088 = 0 ;
}
F_277 () ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_345 ( V_5 -> V_123 [ V_42 ] . V_1238 ) ;
if ( F_30 ( V_5 ) == V_1402 ) {
V_7 = F_33 ( V_1403 ) & ~ V_1404 ;
F_46 ( V_1403 , V_7 | V_1405 ) ;
}
V_7 = V_1406 ;
if ( F_23 ( V_5 , V_1081 ) ) {
if ( F_30 ( V_5 ) != V_257 &&
! F_23 ( V_5 , 57765_PLUS ) &&
F_33 ( V_1407 ) ==
( V_1408 | V_1409 ) )
F_46 ( V_1407 , V_1409 ) ;
if ( F_77 ( V_5 ) != V_1410 ) {
F_46 ( V_498 , ( 1 << 29 ) ) ;
V_7 |= ( 1 << 29 ) ;
}
}
if ( F_30 ( V_5 ) == V_36 ) {
F_46 ( V_326 , F_33 ( V_326 ) | V_1411 ) ;
F_46 ( V_656 ,
F_33 ( V_656 ) & ~ V_657 ) ;
}
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , V_152 ) )
V_7 |= V_1412 ;
F_46 ( V_498 , V_7 ) ;
V_5 -> V_27 = F_188 ;
F_24 ( 120 ) ;
F_19 ( V_5 -> V_12 , V_1379 , & V_7 ) ;
F_24 ( 120 ) ;
if ( F_23 ( V_5 , V_1081 ) && F_428 ( V_5 -> V_12 ) ) {
T_3 V_1413 ;
if ( F_77 ( V_5 ) == V_1410 ) {
int V_628 ;
T_1 V_1414 ;
for ( V_628 = 0 ; V_628 < 5000 ; V_628 ++ )
F_24 ( 100 ) ;
F_19 ( V_5 -> V_12 , 0xc4 , & V_1414 ) ;
F_15 ( V_5 -> V_12 , 0xc4 ,
V_1414 | ( 1 << 15 ) ) ;
}
V_1413 = V_1415 | V_1416 ;
if ( ! F_23 ( V_5 , V_152 ) )
V_1413 |= V_1417 ;
F_223 ( V_5 -> V_12 , V_1418 , V_1413 ) ;
F_429 ( V_5 -> V_12 , V_1419 ,
V_1420 |
V_1421 |
V_1422 |
V_1423 ) ;
}
F_423 ( V_5 ) ;
F_86 ( V_5 , V_1242 ) ;
F_86 ( V_5 , V_1229 ) ;
V_7 = 0 ;
if ( F_23 ( V_5 , 5780_CLASS ) )
V_7 = F_33 ( V_1065 ) ;
F_46 ( V_1065 , V_7 | V_1378 ) ;
if ( F_77 ( V_5 ) == V_1424 ) {
F_93 ( V_5 ) ;
F_46 ( 0x5000 , 0x400 ) ;
}
if ( F_23 ( V_5 , V_264 ) ) {
F_93 ( V_5 ) ;
F_183 ( V_5 , V_654 ) ;
}
V_75 = F_97 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_46 ( V_647 , V_5 -> V_645 ) ;
if ( F_77 ( V_5 ) == V_1425 ) {
V_7 = F_33 ( 0xc4 ) ;
F_46 ( 0xc4 , V_7 | ( 1 << 15 ) ) ;
}
if ( ( V_5 -> V_551 & V_1426 ) != 0 &&
F_30 ( V_5 ) == V_502 ) {
V_5 -> V_156 |= V_155 ;
if ( F_77 ( V_5 ) == V_1425 )
V_5 -> V_156 |= V_154 ;
F_46 ( V_153 , V_5 -> V_156 ) ;
}
if ( V_5 -> V_178 & V_568 ) {
V_5 -> V_368 = V_725 ;
V_7 = V_5 -> V_368 ;
} else if ( V_5 -> V_178 & V_306 ) {
V_5 -> V_368 = V_376 ;
V_7 = V_5 -> V_368 ;
} else
V_7 = 0 ;
F_31 ( V_383 , V_7 ) ;
F_24 ( 40 ) ;
F_37 ( V_5 , V_61 ) ;
F_75 ( V_5 ) ;
if ( F_23 ( V_5 , V_1081 ) &&
F_77 ( V_5 ) != V_1410 &&
F_30 ( V_5 ) != V_257 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( 0x7c00 ) ;
F_46 ( 0x7c00 , V_7 | ( 1 << 25 ) ) ;
}
if ( F_30 ( V_5 ) == V_534 ) {
V_7 = F_33 ( V_1427 ) ;
F_46 ( V_1427 , V_7 & ~ V_1428 ) ;
}
F_86 ( V_5 , V_309 ) ;
V_5 -> V_178 &= ~ ( V_770 |
V_570 ) ;
F_86 ( V_5 , V_317 ) ;
F_32 ( V_5 , V_1429 , & V_7 ) ;
if ( V_7 == V_1430 ) {
T_1 V_1431 ;
F_32 ( V_5 , V_1432 , & V_1431 ) ;
if ( V_1431 & V_1433 ) {
F_84 ( V_5 , V_309 ) ;
V_5 -> V_298 = V_299 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , V_317 ) ;
F_32 ( V_5 , V_1434 , & V_1431 ) ;
if ( V_1431 & V_1435 )
V_5 -> V_178 |= V_770 ;
if ( V_1431 & V_1436 )
V_5 -> V_178 |= V_570 ;
}
}
return 0 ;
}
static int F_430 ( struct V_4 * V_5 , int V_95 , bool V_1358 )
{
int V_75 ;
F_93 ( V_5 ) ;
F_94 ( V_5 , V_95 ) ;
F_420 ( V_5 , V_1358 ) ;
V_75 = F_426 ( V_5 ) ;
F_194 ( V_5 , false ) ;
F_96 ( V_5 , V_95 ) ;
F_95 ( V_5 , V_95 ) ;
if ( V_5 -> V_1351 ) {
F_431 ( V_5 , & V_5 -> V_1437 ) ;
F_432 ( V_5 , & V_5 -> V_1438 ) ;
memset ( V_5 -> V_1351 , 0 , sizeof( struct V_1352 ) ) ;
}
return V_75 ;
}
static int F_433 ( struct V_365 * V_111 , void * V_1439 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_1440 * V_184 = V_1439 ;
int V_75 = 0 ;
bool V_686 = false ;
if ( ! F_434 ( V_184 -> V_1441 ) )
return - V_1442 ;
memcpy ( V_111 -> V_689 , V_184 -> V_1441 , V_111 -> V_1443 ) ;
if ( ! F_145 ( V_111 ) )
return 0 ;
if ( F_23 ( V_5 , V_309 ) ) {
T_1 V_1444 , V_1445 , V_1446 , V_1447 ;
V_1444 = F_33 ( V_690 ) ;
V_1445 = F_33 ( V_691 ) ;
V_1446 = F_33 ( V_1448 ) ;
V_1447 = F_33 ( V_1449 ) ;
if ( ( V_1444 != V_1446 || V_1445 != V_1447 ) &&
! ( V_1446 == 0 && V_1447 == 0 ) )
V_686 = true ;
}
F_70 ( & V_5 -> V_209 ) ;
F_194 ( V_5 , V_686 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_75 ;
}
static void F_435 ( struct V_4 * V_5 , T_1 V_1450 ,
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
static void F_436 ( struct V_4 * V_5 , struct V_1457 * V_1458 )
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
static void F_437 ( struct V_4 * V_5 , struct V_1457 * V_1458 )
{
int V_42 = 0 ;
T_1 V_202 = V_5 -> V_1221 ;
if ( ! F_23 ( V_5 , V_1210 ) ) {
F_46 ( V_1468 , V_1458 -> V_1469 ) ;
F_46 ( V_1470 , V_1458 -> V_1471 ) ;
F_46 ( V_1472 , V_1458 -> V_1473 ) ;
V_202 -- ;
} else {
F_46 ( V_1468 , 0 ) ;
F_46 ( V_1470 , 0 ) ;
F_46 ( V_1472 , 0 ) ;
}
for (; V_42 < V_202 ; V_42 ++ ) {
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
static void F_438 ( struct V_4 * V_5 , struct V_1457 * V_1458 )
{
F_436 ( V_5 , V_1458 ) ;
F_437 ( V_5 , V_1458 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_7 = V_1458 -> V_971 ;
F_46 ( V_1476 , V_1458 -> V_1477 ) ;
F_46 ( V_1478 , V_1458 -> V_1479 ) ;
if ( ! V_5 -> V_341 )
V_7 = 0 ;
F_46 ( V_969 , V_7 ) ;
}
}
static void F_439 ( struct V_4 * V_5 )
{
T_1 V_1480 , V_202 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_202 = V_1481 + V_1482 * 16 ;
else if ( F_23 ( V_5 , 5717_PLUS ) )
V_202 = V_1481 + V_1482 * 4 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_766 )
V_202 = V_1481 + V_1482 * 2 ;
else
V_202 = V_1481 + V_1482 ;
for ( V_1480 = V_1481 + V_1482 ;
V_1480 < V_202 ; V_1480 += V_1482 )
F_29 ( V_5 , V_1480 + V_1455 ,
V_1483 ) ;
}
static void F_440 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1480 = V_1481 ;
if ( F_23 ( V_5 , V_1105 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1480 += V_1482 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1112 )
continue;
F_435 ( V_5 , V_1480 , V_131 -> V_1347 ,
( V_1098 << V_1484 ) ,
V_38 ) ;
}
}
static void F_441 ( struct V_4 * V_5 )
{
T_1 V_1485 , V_202 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_202 = V_1486 + V_1482 * 17 ;
else if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_202 = V_1486 + V_1482 * 16 ;
else if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_766 ||
F_23 ( V_5 , 57765_CLASS ) )
V_202 = V_1486 + V_1482 * 4 ;
else
V_202 = V_1486 + V_1482 ;
for ( V_1485 = V_1486 + V_1482 ;
V_1485 < V_202 ; V_1485 += V_1482 )
F_29 ( V_5 , V_1485 + V_1455 ,
V_1483 ) ;
}
static void F_442 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1485 = V_1486 ;
if ( F_23 ( V_5 , V_1210 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1485 += V_1482 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1165 )
continue;
F_435 ( V_5 , V_1485 , V_131 -> V_1349 ,
( V_5 -> V_1208 + 1 ) <<
V_1484 , 0 ) ;
}
}
static void F_443 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_1488 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
F_439 ( V_5 ) ;
F_441 ( V_5 ) ;
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
F_313 ( V_5 -> V_123 [ V_42 ] . V_1209 , 0 ) ;
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
F_313 ( V_5 -> V_123 [ 0 ] . V_1209 , 0 ) ;
}
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_33 = V_1492 + V_16 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
F_390 ( V_33 + V_42 * 8 , 0 ) ;
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
F_440 ( V_5 ) ;
F_442 ( V_5 ) ;
}
static void F_444 ( struct V_4 * V_5 )
{
T_1 V_7 , V_1495 , V_1496 , V_1497 ;
if ( ! F_23 ( V_5 , 5750_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_30 ( V_5 ) == V_1498 ||
F_30 ( V_5 ) == V_641 ||
F_23 ( V_5 , 57765_PLUS ) )
V_1495 = V_1499 ;
else if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_1500 )
V_1495 = V_1501 ;
else
V_1495 = V_1502 ;
V_1497 = F_320 ( V_1495 / 2 , V_5 -> V_1207 ) ;
V_1496 = F_445 ( T_1 , V_5 -> V_1338 / 8 , 1 ) ;
V_7 = F_320 ( V_1497 , V_1496 ) ;
F_46 ( V_1503 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1504 , V_1495 ) ;
if ( ! F_23 ( V_5 , V_522 ) || F_23 ( V_5 , 5780_CLASS ) )
return;
V_1495 = V_1505 ;
V_1496 = F_445 ( T_1 , V_5 -> V_1342 / 8 , 1 ) ;
V_7 = F_320 ( V_1495 / 2 , V_1496 ) ;
F_46 ( V_1506 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1507 , V_1495 ) ;
}
static inline T_1 F_446 ( unsigned char * V_627 , int V_74 )
{
T_1 V_161 ;
T_1 V_597 ;
int V_628 , V_1508 ;
V_161 = 0xffffffff ;
for ( V_628 = 0 ; V_628 < V_74 ; V_628 ++ ) {
V_161 ^= V_627 [ V_628 ] ;
for ( V_1508 = 0 ; V_1508 < 8 ; V_1508 ++ ) {
V_597 = V_161 & 0x01 ;
V_161 >>= 1 ;
if ( V_597 )
V_161 ^= 0xedb88320 ;
}
}
return ~ V_161 ;
}
static void F_447 ( struct V_4 * V_5 , unsigned int V_1509 )
{
F_46 ( V_1510 , V_1509 ? 0xffffffff : 0 ) ;
F_46 ( V_1511 , V_1509 ? 0xffffffff : 0 ) ;
F_46 ( V_1512 , V_1509 ? 0xffffffff : 0 ) ;
F_46 ( V_1513 , V_1509 ? 0xffffffff : 0 ) ;
}
static void F_448 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_355 ;
V_355 = V_5 -> V_355 & ~ ( V_1514 |
V_1205 ) ;
#if ! F_358 ( V_1515 ) && ! F_358 ( V_1516 )
if ( ! F_23 ( V_5 , V_309 ) )
V_355 |= V_1205 ;
#endif
if ( V_111 -> V_10 & V_1517 ) {
V_355 |= V_1514 ;
} else if ( V_111 -> V_10 & V_1518 ) {
F_447 ( V_5 , 1 ) ;
} else if ( F_449 ( V_111 ) ) {
F_447 ( V_5 , 0 ) ;
} else {
struct V_1519 * V_1520 ;
T_1 V_1521 [ 4 ] = { 0 , } ;
T_1 V_1522 ;
T_1 V_44 ;
T_1 V_1523 ;
F_450 (ha, dev) {
V_1523 = F_446 ( V_1520 -> V_184 , V_1524 ) ;
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
if ( V_355 != V_5 -> V_355 ) {
V_5 -> V_355 = V_355 ;
F_31 ( V_362 , V_355 ) ;
F_24 ( 10 ) ;
}
}
static void F_451 ( struct V_4 * V_5 , T_1 V_1525 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1526 ; V_42 ++ )
V_5 -> V_1527 [ V_42 ] = F_452 ( V_42 , V_1525 ) ;
}
static void F_453 ( struct V_4 * V_5 )
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
F_451 ( V_5 , V_5 -> V_1221 ) ;
}
static void F_454 ( struct V_4 * V_5 )
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
static inline T_1 F_455 ( struct V_4 * V_5 )
{
if ( F_30 ( V_5 ) == V_478 )
return V_1529 ;
else
return V_1530 ;
}
static int F_456 ( struct V_4 * V_5 , bool V_1531 )
{
T_1 V_7 , V_1532 ;
int V_42 , V_75 , V_202 ;
struct V_1129 * V_1130 = & V_5 -> V_123 [ 0 ] . V_1091 ;
F_45 ( V_5 ) ;
F_93 ( V_5 ) ;
F_94 ( V_5 , V_96 ) ;
if ( F_23 ( V_5 , V_563 ) )
F_420 ( V_5 , 1 ) ;
if ( ( V_5 -> V_178 & V_570 ) &&
! ( V_5 -> V_178 & V_1533 ) ) {
F_208 ( V_5 ) ;
F_132 ( V_5 , NULL ) ;
V_5 -> V_178 |= V_1533 ;
}
if ( V_5 -> V_178 & V_339 )
F_221 ( V_5 ) ;
if ( V_1531 )
F_144 ( V_5 ) ;
V_75 = F_426 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_96 ( V_5 , V_96 ) ;
if ( F_146 ( V_5 ) == V_504 ) {
V_7 = F_33 ( V_505 ) ;
V_7 &= ~ ( V_1534 | V_1535 ) ;
F_46 ( V_505 , V_7 ) ;
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
T_1 V_645 = F_33 ( V_647 ) ;
V_7 = V_645 & ~ V_1553 ;
F_46 ( V_647 , V_7 | V_1554 ) ;
V_7 = F_33 ( V_1082 + V_1555 ) ;
F_46 ( V_1082 + V_1555 ,
V_7 | V_1556 ) ;
F_46 ( V_647 , V_645 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) ) {
if ( F_77 ( V_5 ) == V_328 ) {
T_1 V_645 = F_33 ( V_647 ) ;
V_7 = V_645 & ~ V_1553 ;
F_46 ( V_647 , V_7 | V_1554 ) ;
V_7 = F_33 ( V_1082 +
V_1557 ) ;
F_46 ( V_1082 + V_1557 ,
V_7 | V_1558 ) ;
F_46 ( V_647 , V_645 ) ;
}
if ( F_146 ( V_5 ) != V_1559 ) {
T_1 V_645 ;
V_7 = F_33 ( V_1560 ) ;
V_7 |= V_1561 ;
F_46 ( V_1560 , V_7 ) ;
V_645 = F_33 ( V_647 ) ;
V_7 = V_645 & ~ V_1553 ;
F_46 ( V_647 , V_7 | V_1562 ) ;
V_7 = F_33 ( V_1082 +
V_1563 ) ;
V_7 &= ~ V_1564 ;
F_46 ( V_1082 + V_1563 ,
V_7 | V_1565 ) ;
F_46 ( V_647 , V_645 ) ;
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
if ( F_77 ( V_5 ) == V_916 &&
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
if ( F_146 ( V_5 ) == V_1567 ) {
V_7 = F_33 ( V_1568 ) ;
V_7 |= ( 1 << 26 ) | ( 1 << 28 ) | ( 1 << 29 ) ;
F_46 ( V_1568 , V_7 ) ;
}
V_75 = F_410 ( V_5 ) ;
if ( V_75 )
return V_75 ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1569 ) &
~ V_1570 ;
if ( F_77 ( V_5 ) == V_328 )
V_7 &= ~ V_1571 ;
if ( ! F_23 ( V_5 , 57765_CLASS ) &&
F_30 ( V_5 ) != V_477 &&
F_30 ( V_5 ) != V_766 )
V_7 |= V_1572 ;
F_46 ( V_1569 , V_7 | V_5 -> V_1573 ) ;
} else if ( F_30 ( V_5 ) != V_414 &&
F_30 ( V_5 ) != V_45 ) {
F_46 ( V_1569 , V_5 -> V_1573 ) ;
}
V_5 -> V_645 &= ~ ( V_1574 |
V_1575 |
V_1576 |
V_1577 ) ;
V_5 -> V_645 |= V_1574 ;
V_5 -> V_645 |= V_1576 ;
V_7 = V_1578 | V_1579 ;
if ( V_5 -> V_1580 )
F_46 ( V_1581 ,
V_5 -> V_1580 | V_1582 ) ;
if ( F_23 ( V_5 , V_990 ) )
V_7 |= V_1583 ;
F_46 ( V_647 , V_5 -> V_645 | V_7 ) ;
V_7 = F_33 ( V_498 ) ;
V_7 &= ~ 0xff ;
V_7 |= ( 65 << V_966 ) ;
F_46 ( V_498 , V_7 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
} else if ( F_30 ( V_5 ) != V_502 ) {
F_46 ( V_1584 , V_1585 ) ;
if ( F_30 ( V_5 ) == V_501 )
F_46 ( V_1586 , V_1587 ) ;
else
F_46 ( V_1586 , V_1588 ) ;
F_46 ( V_1589 , V_1590 ) ;
F_46 ( V_1591 , V_1592 ) ;
} else if ( F_23 ( V_5 , V_1593 ) ) {
int V_662 ;
V_662 = V_5 -> V_662 ;
V_662 = ( V_662 + ( 0x80 - 1 ) ) & ~ ( 0x80 - 1 ) ;
F_46 ( V_1584 ,
V_685 + V_662 ) ;
F_46 ( V_1586 ,
V_1594 - V_662 - 0xa00 ) ;
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
if ( F_30 ( V_5 ) == V_478 )
V_7 |= V_1610 ;
if ( F_30 ( V_5 ) == V_477 ||
F_77 ( V_5 ) == V_1611 ||
F_77 ( V_5 ) == V_1612 )
V_7 |= V_1613 ;
F_46 ( V_1066 , V_7 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
if ( F_33 ( V_1066 ) & V_1377 )
break;
F_24 ( 10 ) ;
}
if ( V_42 >= 2000 ) {
F_185 ( V_5 -> V_111 , L_54 , V_658 ) ;
return - V_82 ;
}
if ( F_77 ( V_5 ) == V_1614 )
F_46 ( V_1615 , ( F_33 ( V_1615 ) & ~ 0x3 ) | 0x2 ) ;
F_444 ( V_5 ) ;
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
if ( F_77 ( V_5 ) == V_1611 ||
( F_23 ( V_5 , V_522 ) && ! F_23 ( V_5 , 5780_CLASS ) ) ) {
if ( F_23 ( V_5 , V_1340 ) ) {
F_46 ( V_1056 + V_1453 + V_1454 ,
( ( T_6 ) V_1130 -> V_1344 >> 32 ) ) ;
F_46 ( V_1056 + V_1453 + V_16 ,
( ( T_6 ) V_1130 -> V_1344 & 0xffffffff ) ) ;
V_7 = F_457 ( V_5 ) <<
V_1484 ;
F_46 ( V_1056 + V_1455 ,
V_7 | V_1619 ) ;
if ( ! F_23 ( V_5 , V_1304 ) ||
F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_766 )
F_46 ( V_1056 + V_1456 ,
V_1620 ) ;
} else {
F_46 ( V_1056 + V_1455 ,
V_1483 ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_458 ( V_5 ) ;
V_7 <<= V_1484 ;
V_7 |= ( V_1332 << 2 ) ;
} else
V_7 = V_1332 << V_1484 ;
} else
V_7 = V_1621 << V_1484 ;
F_46 ( V_1616 + V_1455 , V_7 ) ;
V_1130 -> V_1092 = V_5 -> V_1338 ;
F_313 ( V_18 , V_1130 -> V_1092 ) ;
V_1130 -> V_1094 =
F_23 ( V_5 , V_1340 ) ? V_5 -> V_1342 : 0 ;
F_313 ( V_1211 , V_1130 -> V_1094 ) ;
F_443 ( V_5 ) ;
F_194 ( V_5 , false ) ;
F_46 ( V_1622 ,
V_5 -> V_111 -> V_1201 + V_1202 + V_1184 + V_1623 ) ;
V_7 = ( 2 << V_388 ) |
( 6 << V_389 ) |
( 32 << V_390 ) ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_766 )
V_7 |= F_33 ( V_387 ) &
( V_967 |
V_968 ) ;
F_46 ( V_387 , V_7 ) ;
F_46 ( V_1624 , V_1625 ) ;
F_46 ( V_1626 , 0x0181 ) ;
V_1532 = ( V_1371 | V_1627 |
V_1628 | V_1629 |
V_1630 | V_1631 |
V_1632 | V_1633 |
V_1634 ) ;
if ( F_30 ( V_5 ) == V_477 )
V_1532 |= V_1635 ;
if ( F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1402 )
V_1532 |= V_1636 |
V_1637 |
V_1638 ;
if ( F_30 ( V_5 ) == V_502 &&
F_77 ( V_5 ) != V_1425 ) {
if ( F_23 ( V_5 , V_1593 ) &&
F_30 ( V_5 ) == V_502 ) {
V_1532 |= V_1639 ;
} else if ( ! ( F_33 ( V_1243 ) & V_1640 ) &&
! F_23 ( V_5 , V_1641 ) ) {
V_1532 |= V_1642 ;
}
}
if ( F_23 ( V_5 , V_1081 ) )
V_1532 |= V_1642 ;
if ( F_30 ( V_5 ) == V_668 ) {
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
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1402 )
V_1532 |= V_1646 ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_766 )
V_1532 |= F_33 ( V_1067 ) & V_1647 ;
if ( F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1402 ||
F_23 ( V_5 , 57765_PLUS ) ) {
T_1 V_1648 ;
if ( F_30 ( V_5 ) == V_766 )
V_1648 = V_1649 ;
else
V_1648 = V_1650 ;
V_7 = F_33 ( V_1648 ) ;
if ( F_77 ( V_5 ) == V_1611 ||
F_30 ( V_5 ) == V_766 ) {
V_7 &= ~ ( V_1651 |
V_1652 |
V_1653 ) ;
V_7 |= V_1654 |
V_1655 |
V_1656 ;
}
F_46 ( V_1648 , V_7 | V_1657 ) ;
}
if ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_766 ) {
T_1 V_1648 ;
if ( F_30 ( V_5 ) == V_766 )
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
F_438 ( V_5 , & V_5 -> V_970 ) ;
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
if ( V_5 -> V_178 & V_306 ) {
V_5 -> V_178 &= ~ V_788 ;
F_31 ( V_362 , V_1325 ) ;
F_24 ( 10 ) ;
}
V_5 -> V_368 |= V_1677 | V_1678 |
V_731 | V_1679 |
V_1680 ;
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_368 |= V_729 | V_730 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_568 ) &&
F_30 ( V_5 ) != V_537 )
V_5 -> V_368 |= V_724 ;
F_31 ( V_383 , V_5 -> V_368 | V_1681 | V_1682 ) ;
F_24 ( 40 ) ;
if ( ! F_23 ( V_5 , V_533 ) ) {
T_1 V_1683 ;
V_1683 = V_541 | V_539 |
V_542 | V_543 |
V_540 | V_547 ;
if ( F_30 ( V_5 ) == V_641 )
V_1683 |= V_550 |
V_1684 ;
if ( F_30 ( V_5 ) == V_1487 )
V_1683 |= V_1685 ;
V_5 -> V_22 &= ~ V_1683 ;
V_5 -> V_22 |= F_33 ( V_136 ) & V_1683 ;
if ( F_23 ( V_5 , V_644 ) )
V_5 -> V_22 |= ( V_539 |
V_540 ) ;
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
if ( F_30 ( V_5 ) == V_502 &&
F_77 ( V_5 ) != V_1425 ) {
if ( F_23 ( V_5 , V_1593 ) &&
( F_77 ( V_5 ) == V_1697 ||
F_77 ( V_5 ) == V_1698 ) ) {
} else if ( ! ( F_33 ( V_1243 ) & V_1640 ) &&
! F_23 ( V_5 , V_1641 ) ) {
V_7 |= V_1699 ;
}
}
if ( F_23 ( V_5 , 5755_PLUS ) )
V_7 |= V_1700 ;
if ( F_30 ( V_5 ) == V_257 )
V_7 |= V_1701 ;
F_31 ( V_1068 , V_7 ) ;
F_24 ( 40 ) ;
if ( F_23 ( V_5 , V_839 ) ) {
T_3 V_1391 ;
F_422 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
& V_1391 ) ;
if ( F_30 ( V_5 ) == V_500 ) {
V_1391 &= ~ V_1702 ;
V_1391 |= V_1703 ;
} else if ( F_30 ( V_5 ) == V_501 ) {
V_1391 &= ~ ( V_1704 | V_1702 ) ;
V_1391 |= V_1703 ;
}
F_424 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
V_1391 ) ;
}
F_31 ( V_1067 , V_1532 ) ;
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ) {
for ( V_42 = 0 ; V_42 < V_1705 ; V_42 ++ ) {
if ( F_33 ( V_1706 + ( V_42 << 2 ) ) > F_459 ( V_5 ) )
break;
}
if ( V_42 < V_1705 ) {
V_7 = F_33 ( V_1659 ) ;
V_7 |= F_455 ( V_5 ) ;
F_46 ( V_1659 , V_7 ) ;
F_84 ( V_5 , 5719_5720_RDMA_BUG ) ;
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
if ( F_77 ( V_5 ) == V_758 ) {
V_75 = F_190 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
if ( F_30 ( V_5 ) == V_668 ) {
F_192 ( V_5 ) ;
}
if ( F_23 ( V_5 , V_1593 ) ) {
V_75 = F_193 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
V_5 -> V_357 = V_1360 ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
V_5 -> V_357 |= V_1717 ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_766 ) {
V_7 = V_1718 | V_1719 ;
V_5 -> V_357 &= ~ V_7 ;
V_5 -> V_357 |= F_33 ( V_364 ) & V_7 ;
}
F_31 ( V_364 , V_5 -> V_357 ) ;
F_24 ( 100 ) ;
if ( F_23 ( V_5 , V_1210 ) ) {
F_454 ( V_5 ) ;
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
V_5 -> V_355 = V_732 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_5 -> V_355 |= V_1730 ;
if ( F_30 ( V_5 ) == V_766 )
V_5 -> V_355 |= V_1731 ;
if ( F_23 ( V_5 , V_1210 ) )
V_5 -> V_355 |= V_1732 |
V_1733 |
V_1734 |
V_1735 |
V_1736 |
V_1737 ;
F_31 ( V_362 , V_5 -> V_355 ) ;
F_24 ( 10 ) ;
F_46 ( V_726 , V_5 -> V_564 ) ;
F_46 ( V_384 , V_386 ) ;
if ( V_5 -> V_178 & V_568 ) {
F_31 ( V_362 , V_1325 ) ;
F_24 ( 10 ) ;
}
F_31 ( V_362 , V_5 -> V_355 ) ;
F_24 ( 10 ) ;
if ( V_5 -> V_178 & V_568 ) {
if ( ( F_30 ( V_5 ) == V_501 ) &&
! ( V_5 -> V_178 & V_1738 ) ) {
V_7 = F_33 ( V_574 ) ;
V_7 &= 0xfffff000 ;
V_7 |= 0x880 ;
F_46 ( V_574 , V_7 ) ;
}
if ( F_77 ( V_5 ) == V_1739 )
F_46 ( V_574 , 0x616000 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) )
V_7 = 1 ;
else
V_7 = 2 ;
F_31 ( V_1740 , V_7 ) ;
if ( F_30 ( V_5 ) == V_501 &&
( V_5 -> V_178 & V_568 ) ) {
F_84 ( V_5 , V_938 ) ;
}
if ( ( V_5 -> V_178 & V_306 ) &&
F_30 ( V_5 ) == V_549 ) {
T_1 V_597 ;
V_597 = F_33 ( V_1741 ) ;
F_46 ( V_1741 , V_597 | V_1742 ) ;
V_5 -> V_22 &= ~ V_1743 ;
V_5 -> V_22 |= V_1744 ;
F_46 ( V_136 , V_5 -> V_22 ) ;
}
if ( ! F_23 ( V_5 , V_267 ) ) {
if ( V_5 -> V_178 & V_400 )
V_5 -> V_178 &= ~ V_400 ;
V_75 = F_200 ( V_5 , false ) ;
if ( V_75 )
return V_75 ;
if ( ! ( V_5 -> V_178 & V_568 ) &&
! ( V_5 -> V_178 & V_179 ) ) {
T_1 V_597 ;
if ( ! F_57 ( V_5 , V_520 , & V_597 ) ) {
F_59 ( V_5 , V_520 ,
V_597 | V_1745 ) ;
F_57 ( V_5 , V_1746 , & V_597 ) ;
}
}
}
F_448 ( V_5 -> V_111 ) ;
F_46 ( V_1747 , 0xc2000000 & V_1748 ) ;
F_46 ( V_1749 , 0xffffffff & V_1748 ) ;
F_46 ( V_1750 , 0x86000004 & V_1748 ) ;
F_46 ( V_1751 , 0xffffffff & V_1748 ) ;
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) )
V_202 = 8 ;
else
V_202 = 16 ;
if ( F_23 ( V_5 , V_309 ) )
V_202 -= 4 ;
switch ( V_202 ) {
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
F_95 ( V_5 , V_96 ) ;
return 0 ;
}
static int F_460 ( struct V_4 * V_5 , bool V_1531 )
{
F_195 ( V_5 ) ;
F_97 ( V_5 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
return F_456 ( V_5 , V_1531 ) ;
}
static void F_461 ( struct V_4 * V_5 , struct V_1778 * V_1779 )
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
static T_14 F_462 ( struct V_544 * V_111 ,
struct V_1786 * V_1787 , char * V_627 )
{
struct V_1788 * V_1789 = F_463 ( V_1787 ) ;
struct V_4 * V_5 = F_464 ( V_111 ) ;
T_1 V_1790 ;
F_70 ( & V_5 -> V_209 ) ;
F_40 ( V_5 , & V_1790 , V_1789 -> V_1027 ,
sizeof( V_1790 ) ) ;
F_71 ( & V_5 -> V_209 ) ;
return sprintf ( V_627 , L_55 , V_1790 ) ;
}
static void F_465 ( struct V_4 * V_5 )
{
if ( V_5 -> V_1791 ) {
F_466 ( V_5 -> V_1791 ) ;
V_5 -> V_1791 = NULL ;
}
}
static void F_467 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_635 = 0 ;
struct V_1792 * V_12 = V_5 -> V_12 ;
struct V_1778 V_1793 [ V_1780 ] ;
F_461 ( V_5 , V_1793 ) ;
for ( V_42 = 0 ; V_42 < V_1780 ; V_42 ++ ) {
if ( ! V_1793 [ V_42 ] . V_1794 )
continue;
V_635 += V_1793 [ V_42 ] . V_1795 ;
V_635 += V_1793 [ V_42 ] . V_1794 ;
}
if ( ! V_635 )
return;
V_5 -> V_1791 = F_468 ( & V_12 -> V_111 , L_56 ,
V_5 , V_1796 ) ;
if ( F_116 ( V_5 -> V_1791 ) ) {
V_5 -> V_1791 = NULL ;
F_117 ( & V_12 -> V_111 , L_57 ) ;
}
}
static void F_469 ( struct V_4 * V_5 )
{
struct V_1352 * V_1797 = V_5 -> V_1351 ;
if ( ! V_5 -> V_341 )
return;
F_470 ( & V_1797 -> V_1798 , V_1799 ) ;
F_470 ( & V_1797 -> V_1800 , V_1801 ) ;
F_470 ( & V_1797 -> V_1802 , V_1803 ) ;
F_470 ( & V_1797 -> V_1804 , V_1805 ) ;
F_470 ( & V_1797 -> V_1806 , V_1807 ) ;
F_470 ( & V_1797 -> V_1808 , V_1809 ) ;
F_470 ( & V_1797 -> V_1810 , V_1811 ) ;
F_470 ( & V_1797 -> V_1812 , V_1813 ) ;
F_470 ( & V_1797 -> V_1814 , V_1815 ) ;
F_470 ( & V_1797 -> V_1816 , V_1817 ) ;
F_470 ( & V_1797 -> V_1818 , V_1819 ) ;
F_470 ( & V_1797 -> V_1820 , V_1821 ) ;
F_470 ( & V_1797 -> V_1822 , V_1823 ) ;
if ( F_266 ( F_23 ( V_5 , 5719_5720_RDMA_BUG ) &&
( V_1797 -> V_1818 . V_486 + V_1797 -> V_1820 . V_486 +
V_1797 -> V_1822 . V_486 ) > V_1705 ) ) {
T_1 V_7 ;
V_7 = F_33 ( V_1659 ) ;
V_7 &= ~ F_455 ( V_5 ) ;
F_46 ( V_1659 , V_7 ) ;
F_86 ( V_5 , 5719_5720_RDMA_BUG ) ;
}
F_470 ( & V_1797 -> V_1824 , V_1825 ) ;
F_470 ( & V_1797 -> V_1826 , V_1827 ) ;
F_470 ( & V_1797 -> V_1828 , V_1829 ) ;
F_470 ( & V_1797 -> V_1830 , V_1831 ) ;
F_470 ( & V_1797 -> V_1832 , V_1833 ) ;
F_470 ( & V_1797 -> V_1834 , V_1835 ) ;
F_470 ( & V_1797 -> V_1836 , V_1837 ) ;
F_470 ( & V_1797 -> V_1838 , V_1839 ) ;
F_470 ( & V_1797 -> V_1840 , V_1841 ) ;
F_470 ( & V_1797 -> V_1842 , V_1843 ) ;
F_470 ( & V_1797 -> V_1844 , V_1845 ) ;
F_470 ( & V_1797 -> V_1846 , V_1847 ) ;
F_470 ( & V_1797 -> V_1848 , V_1849 ) ;
F_470 ( & V_1797 -> V_1850 , V_1851 ) ;
F_470 ( & V_1797 -> V_1852 , V_1853 ) ;
if ( F_30 ( V_5 ) != V_477 &&
F_77 ( V_5 ) != V_1611 &&
F_77 ( V_5 ) != V_1612 ) {
F_470 ( & V_1797 -> V_1854 , V_1855 ) ;
} else {
T_1 V_7 = F_33 ( V_1230 ) ;
V_7 = ( V_7 & V_1231 ) ? 1 : 0 ;
if ( V_7 ) {
F_46 ( V_1230 , V_1231 ) ;
V_1797 -> V_1854 . V_486 += V_7 ;
if ( V_1797 -> V_1854 . V_486 < V_7 )
V_1797 -> V_1854 . V_487 += 1 ;
}
V_1797 -> V_1856 = V_1797 -> V_1854 ;
}
F_470 ( & V_1797 -> V_1857 , V_1858 ) ;
}
static void F_471 ( struct V_4 * V_5 )
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
F_347 ( 0 , V_131 ) ;
}
}
V_131 -> V_1489 = 0 ;
V_131 -> V_1490 = V_131 -> V_149 ;
V_131 -> V_1491 = V_131 -> V_147 ;
}
}
static void F_472 ( unsigned long V_1859 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1859 ;
if ( V_5 -> V_125 || F_23 ( V_5 , V_1225 ) )
goto V_1860;
F_316 ( & V_5 -> V_209 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_23 ( V_5 , 57765_CLASS ) )
F_471 ( V_5 ) ;
if ( F_23 ( V_5 , V_30 ) ) {
F_33 ( V_138 ) ;
}
if ( ! F_23 ( V_5 , V_133 ) ) {
if ( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & V_135 ) {
F_46 ( V_136 ,
V_5 -> V_22 | V_137 ) ;
} else {
F_46 ( V_138 , V_5 -> V_127 |
V_128 | V_1861 ) ;
}
if ( ! ( F_33 ( V_1068 ) & V_1375 ) ) {
F_317 ( & V_5 -> V_209 ) ;
F_322 ( V_5 ) ;
goto V_1860;
}
}
if ( ! -- V_5 -> V_1862 ) {
if ( F_23 ( V_5 , 5705_PLUS ) )
F_469 ( V_5 ) ;
if ( V_5 -> V_340 && ! -- V_5 -> V_340 )
F_135 ( V_5 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
T_1 V_1863 ;
int V_1864 ;
V_1863 = F_33 ( V_790 ) ;
V_1864 = 0 ;
if ( V_5 -> V_178 & V_816 ) {
if ( V_1863 & V_1865 )
V_1864 = 1 ;
} else if ( V_1863 & V_794 )
V_1864 = 1 ;
if ( V_1864 )
F_200 ( V_5 , false ) ;
} else if ( F_23 ( V_5 , V_143 ) ) {
T_1 V_1863 = F_33 ( V_790 ) ;
int V_1866 = 0 ;
if ( V_5 -> V_341 &&
( V_1863 & V_794 ) ) {
V_1866 = 1 ;
}
if ( ! V_5 -> V_341 &&
( V_1863 & ( V_911 |
V_926 ) ) ) {
V_1866 = 1 ;
}
if ( V_1866 ) {
if ( ! V_5 -> V_923 ) {
F_31 ( V_383 ,
( V_5 -> V_368 &
~ V_371 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
}
F_200 ( V_5 , false ) ;
}
} else if ( ( V_5 -> V_178 & V_306 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_232 ( V_5 ) ;
}
V_5 -> V_1862 = V_5 -> V_1867 ;
}
if ( ! -- V_5 -> V_1868 ) {
if ( F_23 ( V_5 , V_309 ) && ! F_23 ( V_5 , V_60 ) ) {
F_88 ( V_5 ) ;
F_29 ( V_5 , V_310 ,
V_1869 ) ;
F_29 ( V_5 , V_312 , 4 ) ;
F_29 ( V_5 , V_313 ,
V_1870 ) ;
F_87 ( V_5 ) ;
}
V_5 -> V_1868 = V_5 -> V_1871 ;
}
F_317 ( & V_5 -> V_209 ) ;
V_1860:
V_5 -> V_1872 . V_1873 = V_299 + V_5 -> V_1874 ;
F_473 ( & V_5 -> V_1872 ) ;
}
static void F_474 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_133 ) &&
F_30 ( V_5 ) != V_477 &&
! F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_1874 = V_1875 ;
else
V_5 -> V_1874 = V_1875 / 10 ;
F_184 ( V_5 -> V_1874 > V_1875 ) ;
V_5 -> V_1867 = ( V_1875 / V_5 -> V_1874 ) ;
V_5 -> V_1871 = ( V_1875 / V_5 -> V_1874 ) *
V_1876 ;
F_475 ( & V_5 -> V_1872 ) ;
V_5 -> V_1872 . V_72 = ( unsigned long ) V_5 ;
V_5 -> V_1872 . V_1877 = F_472 ;
}
static void F_476 ( struct V_4 * V_5 )
{
V_5 -> V_1868 = V_5 -> V_1871 ;
V_5 -> V_1862 = V_5 -> V_1867 ;
V_5 -> V_1872 . V_1873 = V_299 + V_5 -> V_1874 ;
F_473 ( & V_5 -> V_1872 ) ;
}
static void F_477 ( struct V_4 * V_5 )
{
F_478 ( & V_5 -> V_1872 ) ;
}
static int F_479 ( struct V_4 * V_5 , bool V_1531 )
__releases( V_5 -> V_209 )
__acquires( V_5 -> V_209 )
{
int V_75 ;
V_75 = F_460 ( V_5 , V_1531 ) ;
if ( V_75 ) {
F_185 ( V_5 -> V_111 ,
L_58 ) ;
F_430 ( V_5 , V_110 , 1 ) ;
F_241 ( V_5 ) ;
F_477 ( V_5 ) ;
V_5 -> V_125 = 0 ;
F_334 ( V_5 ) ;
F_480 ( V_5 -> V_111 ) ;
F_240 ( V_5 , 0 ) ;
}
return V_75 ;
}
static void F_481 ( struct V_1878 * V_1879 )
{
struct V_4 * V_5 = F_238 ( V_1879 , struct V_4 , V_1224 ) ;
int V_75 ;
F_240 ( V_5 , 0 ) ;
if ( ! F_145 ( V_5 -> V_111 ) ) {
F_86 ( V_5 , V_1225 ) ;
F_241 ( V_5 ) ;
return;
}
F_241 ( V_5 ) ;
F_123 ( V_5 ) ;
F_340 ( V_5 ) ;
F_240 ( V_5 , 1 ) ;
if ( F_23 ( V_5 , V_1097 ) ) {
V_5 -> V_1096 = F_26 ;
V_5 -> V_1880 = F_17 ;
F_84 ( V_5 , V_31 ) ;
F_86 ( V_5 , V_1097 ) ;
}
F_430 ( V_5 , V_110 , 0 ) ;
V_75 = F_460 ( V_5 , true ) ;
if ( V_75 )
goto V_503;
F_342 ( V_5 ) ;
V_503:
F_241 ( V_5 ) ;
if ( ! V_75 )
F_120 ( V_5 ) ;
F_86 ( V_5 , V_1225 ) ;
}
static int F_482 ( struct V_4 * V_5 , int V_1881 )
{
T_15 V_1882 ;
unsigned long V_10 ;
char * V_269 ;
struct V_130 * V_131 = & V_5 -> V_123 [ V_1881 ] ;
if ( V_5 -> V_129 == 1 )
V_269 = V_5 -> V_111 -> V_269 ;
else {
V_269 = & V_131 -> V_1883 [ 0 ] ;
if ( V_131 -> V_1108 && V_131 -> V_1165 )
snprintf ( V_269 , V_1884 ,
L_59 , V_5 -> V_111 -> V_269 , V_1881 ) ;
else if ( V_131 -> V_1108 )
snprintf ( V_269 , V_1884 ,
L_60 , V_5 -> V_111 -> V_269 , V_1881 ) ;
else if ( V_131 -> V_1165 )
snprintf ( V_269 , V_1884 ,
L_61 , V_5 -> V_111 -> V_269 , V_1881 ) ;
else
snprintf ( V_269 , V_1884 ,
L_62 , V_5 -> V_111 -> V_269 , V_1881 ) ;
V_269 [ V_1884 - 1 ] = 0 ;
}
if ( F_23 ( V_5 , V_1395 ) || F_23 ( V_5 , V_1686 ) ) {
V_1882 = F_347 ;
if ( F_23 ( V_5 , 1SHOT_MSI ) )
V_1882 = F_346 ;
V_10 = 0 ;
} else {
V_1882 = F_349 ;
if ( F_23 ( V_5 , V_133 ) )
V_1882 = F_350 ;
V_10 = V_1885 ;
}
return F_483 ( V_131 -> V_1238 , V_1882 , V_10 , V_269 , V_131 ) ;
}
static int F_484 ( struct V_4 * V_5 )
{
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
struct V_365 * V_111 = V_5 -> V_111 ;
int V_75 , V_42 , V_1886 = 0 ;
T_1 V_7 ;
if ( ! F_145 ( V_111 ) )
return - V_82 ;
F_45 ( V_5 ) ;
F_485 ( V_131 -> V_1238 , V_131 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1077 ) | V_1688 ;
F_46 ( V_1077 , V_7 ) ;
}
V_75 = F_483 ( V_131 -> V_1238 , F_351 ,
V_1885 , V_111 -> V_269 , V_131 ) ;
if ( V_75 )
return V_75 ;
V_131 -> V_134 -> V_57 &= ~ V_135 ;
F_48 ( V_5 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_131 -> V_126 ) ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ ) {
T_1 V_124 , V_120 ;
V_124 = F_486 ( V_131 -> V_124 ) ;
V_120 = F_33 ( V_119 ) ;
if ( ( V_124 != 0 ) ||
( V_120 & V_121 ) ) {
V_1886 = 1 ;
break;
}
if ( F_23 ( V_5 , 57765_PLUS ) &&
V_131 -> V_134 -> V_1083 != V_131 -> V_132 )
F_47 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
F_163 ( 10 ) ;
}
F_45 ( V_5 ) ;
F_485 ( V_131 -> V_1238 , V_131 ) ;
V_75 = F_482 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
if ( V_1886 ) {
if ( F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , 1SHOT_MSI ) ) {
V_7 = F_33 ( V_1077 ) & ~ V_1688 ;
F_46 ( V_1077 , V_7 ) ;
}
return 0 ;
}
return - V_210 ;
}
static int F_487 ( struct V_4 * V_5 )
{
int V_75 ;
T_3 V_1380 ;
if ( ! F_23 ( V_5 , V_1395 ) )
return 0 ;
F_422 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
F_424 ( V_5 -> V_12 , V_1379 ,
V_1380 & ~ V_1887 ) ;
V_75 = F_484 ( V_5 ) ;
F_424 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
if ( ! V_75 )
return 0 ;
if ( V_75 != - V_210 )
return V_75 ;
F_143 ( V_5 -> V_111 , L_63
L_64
L_65 ) ;
F_485 ( V_5 -> V_123 [ 0 ] . V_1238 , & V_5 -> V_123 [ 0 ] ) ;
F_488 ( V_5 -> V_12 ) ;
F_86 ( V_5 , V_1395 ) ;
V_5 -> V_123 [ 0 ] . V_1238 = V_5 -> V_12 -> V_280 ;
V_75 = F_482 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
F_240 ( V_5 , 1 ) ;
F_430 ( V_5 , V_110 , 1 ) ;
V_75 = F_460 ( V_5 , true ) ;
F_241 ( V_5 ) ;
if ( V_75 )
F_485 ( V_5 -> V_123 [ 0 ] . V_1238 , & V_5 -> V_123 [ 0 ] ) ;
return V_75 ;
}
static int F_489 ( struct V_4 * V_5 )
{
const struct V_660 * V_661 ;
if ( F_490 ( & V_5 -> V_663 , V_5 -> V_1888 , & V_5 -> V_12 -> V_111 ) ) {
F_185 ( V_5 -> V_111 , L_66 ,
V_5 -> V_1888 ) ;
return - V_1889 ;
}
V_661 = (struct V_660 * ) V_5 -> V_663 -> V_72 ;
V_5 -> V_662 = F_172 ( V_661 -> V_74 ) ;
if ( V_5 -> V_662 < ( V_5 -> V_663 -> V_635 - V_664 ) ) {
F_185 ( V_5 -> V_111 , L_67 ,
V_5 -> V_662 , V_5 -> V_1888 ) ;
F_491 ( V_5 -> V_663 ) ;
V_5 -> V_663 = NULL ;
return - V_64 ;
}
V_5 -> V_1888 = NULL ;
return 0 ;
}
static T_1 F_492 ( struct V_4 * V_5 )
{
T_1 V_129 = F_493 ( V_5 -> V_1221 , V_5 -> V_1348 ) ;
if ( V_129 > 1 ) {
V_129 = F_494 ( unsigned , V_129 + 1 , V_5 -> V_122 ) ;
}
return V_129 ;
}
static bool F_495 ( struct V_4 * V_5 )
{
int V_42 , V_629 ;
struct V_1890 V_1891 [ V_1892 ] ;
V_5 -> V_1348 = V_5 -> V_1893 ;
V_5 -> V_1221 = V_5 -> V_1894 ;
if ( ! V_5 -> V_1221 )
V_5 -> V_1221 = F_496 () ;
if ( V_5 -> V_1221 > V_5 -> V_1895 )
V_5 -> V_1221 = V_5 -> V_1895 ;
if ( ! V_5 -> V_1893 )
V_5 -> V_1348 = 1 ;
V_5 -> V_129 = F_492 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
V_1891 [ V_42 ] . V_1256 = V_42 ;
V_1891 [ V_42 ] . V_1896 = 0 ;
}
V_629 = F_497 ( V_5 -> V_12 , V_1891 , V_5 -> V_129 ) ;
if ( V_629 < 0 ) {
return false ;
} else if ( V_629 != 0 ) {
if ( F_497 ( V_5 -> V_12 , V_1891 , V_629 ) )
return false ;
F_498 ( V_5 -> V_111 , L_68 ,
V_5 -> V_129 , V_629 ) ;
V_5 -> V_129 = V_629 ;
V_5 -> V_1221 = F_493 ( V_629 - 1 , 1 ) ;
if ( V_5 -> V_1348 )
V_5 -> V_1348 = F_320 ( V_5 -> V_1221 , V_5 -> V_1897 ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1238 = V_1891 [ V_42 ] . V_1896 ;
if ( F_499 ( V_5 -> V_111 , V_5 -> V_1221 ) ) {
F_500 ( V_5 -> V_12 ) ;
return false ;
}
if ( V_5 -> V_129 == 1 )
return true ;
F_84 ( V_5 , V_1210 ) ;
if ( V_5 -> V_1348 > 1 )
F_84 ( V_5 , V_1105 ) ;
F_501 ( V_5 -> V_111 , V_5 -> V_1348 ) ;
return true ;
}
static void F_502 ( struct V_4 * V_5 )
{
if ( ( F_23 ( V_5 , V_1898 ) || F_23 ( V_5 , V_1063 ) ) &&
! F_23 ( V_5 , V_133 ) ) {
F_143 ( V_5 -> V_111 ,
L_69 ) ;
goto V_1899;
}
if ( F_23 ( V_5 , V_1063 ) && F_495 ( V_5 ) )
F_84 ( V_5 , V_1686 ) ;
else if ( F_23 ( V_5 , V_1898 ) && F_503 ( V_5 -> V_12 ) == 0 )
F_84 ( V_5 , V_1395 ) ;
if ( F_23 ( V_5 , V_1395 ) || F_23 ( V_5 , V_1686 ) ) {
T_1 V_1900 = F_33 ( V_1077 ) ;
if ( F_23 ( V_5 , V_1686 ) && V_5 -> V_129 > 1 )
V_1900 |= V_1687 ;
if ( ! F_23 ( V_5 , 1SHOT_MSI ) )
V_1900 |= V_1688 ;
F_46 ( V_1077 , V_1900 | V_1400 ) ;
}
V_1899:
if ( ! F_23 ( V_5 , V_1686 ) ) {
V_5 -> V_129 = 1 ;
V_5 -> V_123 [ 0 ] . V_1238 = V_5 -> V_12 -> V_280 ;
}
if ( V_5 -> V_129 == 1 ) {
V_5 -> V_1348 = 1 ;
V_5 -> V_1221 = 1 ;
F_501 ( V_5 -> V_111 , 1 ) ;
F_499 ( V_5 -> V_111 , 1 ) ;
}
}
static void F_504 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1686 ) )
F_500 ( V_5 -> V_12 ) ;
else if ( F_23 ( V_5 , V_1395 ) )
F_488 ( V_5 -> V_12 ) ;
F_86 ( V_5 , V_1395 ) ;
F_86 ( V_5 , V_1686 ) ;
F_86 ( V_5 , V_1210 ) ;
F_86 ( V_5 , V_1105 ) ;
}
static int F_505 ( struct V_4 * V_5 , bool V_1531 , bool V_1901 ,
bool V_1902 )
{
struct V_365 * V_111 = V_5 -> V_111 ;
int V_42 , V_75 ;
F_502 ( V_5 ) ;
F_453 ( V_5 ) ;
V_75 = F_418 ( V_5 ) ;
if ( V_75 )
goto V_1903;
F_336 ( V_5 ) ;
F_334 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_75 = F_482 ( V_5 , V_42 ) ;
if ( V_75 ) {
for ( V_42 -- ; V_42 >= 0 ; V_42 -- ) {
V_131 = & V_5 -> V_123 [ V_42 ] ;
F_485 ( V_131 -> V_1238 , V_131 ) ;
}
goto V_1904;
}
}
F_240 ( V_5 , 0 ) ;
if ( V_1902 )
F_42 ( V_5 , V_96 ) ;
V_75 = F_460 ( V_5 , V_1531 ) ;
if ( V_75 ) {
F_430 ( V_5 , V_110 , 1 ) ;
F_407 ( V_5 ) ;
}
F_241 ( V_5 ) ;
if ( V_75 )
goto V_1905;
if ( V_1901 && F_23 ( V_5 , V_1395 ) ) {
V_75 = F_487 ( V_5 ) ;
if ( V_75 ) {
F_240 ( V_5 , 0 ) ;
F_430 ( V_5 , V_110 , 1 ) ;
F_407 ( V_5 ) ;
F_241 ( V_5 ) ;
goto V_1904;
}
if ( ! F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , V_1395 ) ) {
T_1 V_7 = F_33 ( V_1906 ) ;
F_46 ( V_1906 ,
V_7 | V_1907 ) ;
}
}
F_120 ( V_5 ) ;
F_467 ( V_5 ) ;
F_240 ( V_5 , 0 ) ;
F_476 ( V_5 ) ;
F_84 ( V_5 , V_563 ) ;
F_48 ( V_5 ) ;
if ( V_1902 )
F_250 ( V_5 ) ;
else
F_253 ( V_5 ) ;
F_241 ( V_5 ) ;
F_506 ( V_111 ) ;
if ( V_111 -> V_1192 & V_1327 )
F_393 ( V_111 , V_111 -> V_1192 ) ;
return 0 ;
V_1905:
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_485 ( V_131 -> V_1238 , V_131 ) ;
}
V_1904:
F_332 ( V_5 ) ;
F_338 ( V_5 ) ;
F_417 ( V_5 ) ;
V_1903:
F_504 ( V_5 ) ;
return V_75 ;
}
static void F_507 ( struct V_4 * V_5 )
{
int V_42 ;
F_325 ( V_5 ) ;
F_340 ( V_5 ) ;
F_477 ( V_5 ) ;
F_465 ( V_5 ) ;
F_123 ( V_5 ) ;
F_240 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_430 ( V_5 , V_110 , 1 ) ;
F_407 ( V_5 ) ;
F_86 ( V_5 , V_563 ) ;
F_241 ( V_5 ) ;
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_485 ( V_131 -> V_1238 , V_131 ) ;
}
F_504 ( V_5 ) ;
F_338 ( V_5 ) ;
F_417 ( V_5 ) ;
}
static int F_508 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 ;
if ( V_5 -> V_1888 ) {
V_75 = F_489 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_668 ) {
if ( V_75 ) {
F_143 ( V_5 -> V_111 , L_70 ) ;
V_5 -> V_178 &= ~ V_339 ;
} else if ( ! ( V_5 -> V_178 & V_339 ) ) {
F_143 ( V_5 -> V_111 , L_71 ) ;
V_5 -> V_178 |= V_339 ;
}
} else if ( F_77 ( V_5 ) == V_758 ) {
if ( V_75 )
return V_75 ;
} else if ( V_75 ) {
F_143 ( V_5 -> V_111 , L_72 ) ;
F_86 ( V_5 , V_1593 ) ;
} else if ( ! F_23 ( V_5 , V_1593 ) ) {
F_498 ( V_5 -> V_111 , L_73 ) ;
F_84 ( V_5 , V_1593 ) ;
}
}
F_140 ( V_5 ) ;
V_75 = F_196 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_240 ( V_5 , 0 ) ;
F_45 ( V_5 ) ;
F_86 ( V_5 , V_563 ) ;
F_241 ( V_5 ) ;
V_75 = F_505 ( V_5 ,
! ( V_5 -> V_178 & V_570 ) ,
true , true ) ;
if ( V_75 ) {
F_152 ( V_5 , false ) ;
F_197 ( V_5 -> V_12 , V_742 ) ;
}
if ( F_23 ( V_5 , V_990 ) ) {
V_5 -> V_994 = F_509 ( & V_5 -> V_1007 ,
& V_5 -> V_12 -> V_111 ) ;
if ( F_116 ( V_5 -> V_994 ) )
V_5 -> V_994 = NULL ;
}
return V_75 ;
}
static int F_510 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_254 ( V_5 ) ;
F_507 ( V_5 ) ;
memset ( & V_5 -> V_1437 , 0 , sizeof( V_5 -> V_1437 ) ) ;
memset ( & V_5 -> V_1438 , 0 , sizeof( V_5 -> V_1438 ) ) ;
if ( F_427 ( V_5 -> V_12 ) ) {
F_198 ( V_5 ) ;
F_140 ( V_5 ) ;
}
return 0 ;
}
static inline T_6 F_511 ( T_16 * V_7 )
{
return ( ( T_6 ) V_7 -> V_487 << 32 ) | ( ( T_6 ) V_7 -> V_486 ) ;
}
static T_6 F_512 ( struct V_4 * V_5 )
{
struct V_1352 * V_1351 = V_5 -> V_1351 ;
if ( ! ( V_5 -> V_178 & V_568 ) &&
( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) ) {
T_1 V_7 ;
if ( ! F_57 ( V_5 , V_520 , & V_7 ) ) {
F_59 ( V_5 , V_520 ,
V_7 | V_1745 ) ;
F_57 ( V_5 , V_1746 , & V_7 ) ;
} else
V_7 = 0 ;
V_5 -> V_1908 += V_7 ;
return V_5 -> V_1908 ;
}
return F_511 ( & V_1351 -> V_1834 ) ;
}
static void F_432 ( struct V_4 * V_5 , struct V_1909 * V_1910 )
{
struct V_1909 * V_1911 = & V_5 -> V_1438 ;
struct V_1352 * V_1351 = V_5 -> V_1351 ;
F_513 ( V_1824 ) ;
F_513 ( V_1826 ) ;
F_513 ( V_1828 ) ;
F_513 ( V_1830 ) ;
F_513 ( V_1832 ) ;
F_513 ( V_1834 ) ;
F_513 ( V_1836 ) ;
F_513 ( V_1838 ) ;
F_513 ( V_1840 ) ;
F_513 ( V_1842 ) ;
F_513 ( V_1844 ) ;
F_513 ( V_1846 ) ;
F_513 ( V_1848 ) ;
F_513 ( V_1850 ) ;
F_513 ( V_1912 ) ;
F_513 ( V_1913 ) ;
F_513 ( V_1914 ) ;
F_513 ( V_1915 ) ;
F_513 ( V_1916 ) ;
F_513 ( V_1917 ) ;
F_513 ( V_1918 ) ;
F_513 ( V_1919 ) ;
F_513 ( V_1920 ) ;
F_513 ( V_1921 ) ;
F_513 ( V_1922 ) ;
F_513 ( V_1923 ) ;
F_513 ( V_1798 ) ;
F_513 ( V_1800 ) ;
F_513 ( V_1802 ) ;
F_513 ( V_1804 ) ;
F_513 ( V_1924 ) ;
F_513 ( V_1806 ) ;
F_513 ( V_1808 ) ;
F_513 ( V_1810 ) ;
F_513 ( V_1812 ) ;
F_513 ( V_1814 ) ;
F_513 ( V_1816 ) ;
F_513 ( V_1925 ) ;
F_513 ( V_1926 ) ;
F_513 ( V_1927 ) ;
F_513 ( V_1928 ) ;
F_513 ( V_1929 ) ;
F_513 ( V_1930 ) ;
F_513 ( V_1931 ) ;
F_513 ( V_1932 ) ;
F_513 ( V_1933 ) ;
F_513 ( V_1934 ) ;
F_513 ( V_1935 ) ;
F_513 ( V_1936 ) ;
F_513 ( V_1937 ) ;
F_513 ( V_1938 ) ;
F_513 ( V_1818 ) ;
F_513 ( V_1820 ) ;
F_513 ( V_1822 ) ;
F_513 ( V_1939 ) ;
F_513 ( V_1940 ) ;
F_513 ( V_1941 ) ;
F_513 ( V_1942 ) ;
F_513 ( V_1943 ) ;
F_513 ( V_1852 ) ;
F_513 ( V_1854 ) ;
F_513 ( V_1857 ) ;
F_513 ( V_1944 ) ;
F_513 ( V_1945 ) ;
F_513 ( V_1946 ) ;
F_513 ( V_1947 ) ;
F_513 ( V_1948 ) ;
F_513 ( V_1949 ) ;
F_513 ( V_1950 ) ;
F_513 ( V_1951 ) ;
F_513 ( V_1952 ) ;
F_513 ( V_1856 ) ;
}
static void F_431 ( struct V_4 * V_5 , struct V_1953 * V_1954 )
{
struct V_1953 * V_1955 = & V_5 -> V_1437 ;
struct V_1352 * V_1351 = V_5 -> V_1351 ;
V_1954 -> V_1956 = V_1955 -> V_1956 +
F_511 ( & V_1351 -> V_1828 ) +
F_511 ( & V_1351 -> V_1830 ) +
F_511 ( & V_1351 -> V_1832 ) ;
V_1954 -> V_1957 = V_1955 -> V_1957 +
F_511 ( & V_1351 -> V_1818 ) +
F_511 ( & V_1351 -> V_1820 ) +
F_511 ( & V_1351 -> V_1822 ) ;
V_1954 -> V_1958 = V_1955 -> V_1958 +
F_511 ( & V_1351 -> V_1824 ) ;
V_1954 -> V_1959 = V_1955 -> V_1959 +
F_511 ( & V_1351 -> V_1798 ) ;
V_1954 -> V_1857 = V_1955 -> V_1857 +
F_511 ( & V_1351 -> V_1857 ) ;
V_1954 -> V_1941 = V_1955 -> V_1941 +
F_511 ( & V_1351 -> V_1941 ) +
F_511 ( & V_1351 -> V_1806 ) +
F_511 ( & V_1351 -> V_1939 ) +
F_511 ( & V_1351 -> V_1940 ) ;
V_1954 -> V_1960 = V_1955 -> V_1960 +
F_511 ( & V_1351 -> V_1830 ) ;
V_1954 -> V_1961 = V_1955 -> V_1961 +
F_511 ( & V_1351 -> V_1800 ) ;
V_1954 -> V_1962 = V_1955 -> V_1962 +
F_511 ( & V_1351 -> V_1846 ) +
F_511 ( & V_1351 -> V_1850 ) ;
V_1954 -> V_1963 = V_1955 -> V_1963 +
F_511 ( & V_1351 -> V_1852 ) ;
V_1954 -> V_1964 = V_1955 -> V_1964 +
F_511 ( & V_1351 -> V_1836 ) ;
V_1954 -> V_1965 = V_1955 -> V_1965 +
F_511 ( & V_1351 -> V_1940 ) ;
V_1954 -> V_1966 = V_1955 -> V_1966 +
F_511 ( & V_1351 -> V_1939 ) ;
V_1954 -> V_1967 = V_1955 -> V_1967 +
F_512 ( V_5 ) ;
V_1954 -> V_1968 = V_1955 -> V_1968 +
F_511 ( & V_1351 -> V_1854 ) ;
V_1954 -> V_1179 = V_5 -> V_1179 ;
V_1954 -> V_1318 = V_5 -> V_1318 ;
}
static int F_514 ( struct V_365 * V_111 )
{
return V_1079 ;
}
static void F_515 ( struct V_365 * V_111 ,
struct V_1969 * V_8 , void * V_1970 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_8 -> V_1971 = 0 ;
memset ( V_1970 , 0 , V_1079 ) ;
if ( V_5 -> V_178 & V_400 )
return;
F_240 ( V_5 , 0 ) ;
F_258 ( V_5 , ( T_1 * ) V_1970 ) ;
F_241 ( V_5 ) ;
}
static int F_516 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
return V_5 -> V_1972 ;
}
static int F_517 ( struct V_365 * V_111 , struct V_1973 * V_1974 , T_4 * V_72 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_56 ;
T_4 * V_1975 ;
T_1 V_42 , V_596 , V_74 , V_1976 , V_1977 ;
T_5 V_7 ;
if ( F_23 ( V_5 , V_682 ) )
return - V_64 ;
V_596 = V_1974 -> V_596 ;
V_74 = V_1974 -> V_74 ;
V_1974 -> V_74 = 0 ;
V_1974 -> V_1978 = V_1979 ;
if ( V_596 & 3 ) {
V_1976 = V_596 & 3 ;
V_1977 = 4 - V_1976 ;
if ( V_1977 > V_74 ) {
V_1977 = V_74 ;
}
V_56 = F_169 ( V_5 , V_596 - V_1976 , & V_7 ) ;
if ( V_56 )
return V_56 ;
memcpy ( V_72 , ( ( char * ) & V_7 ) + V_1976 , V_1977 ) ;
V_74 -= V_1977 ;
V_596 += V_1977 ;
V_1974 -> V_74 += V_1977 ;
}
V_1975 = & V_72 [ V_1974 -> V_74 ] ;
for ( V_42 = 0 ; V_42 < ( V_74 - ( V_74 & 3 ) ) ; V_42 += 4 ) {
V_56 = F_169 ( V_5 , V_596 + V_42 , & V_7 ) ;
if ( V_56 ) {
V_1974 -> V_74 += V_42 ;
return V_56 ;
}
memcpy ( V_1975 + V_42 , & V_7 , 4 ) ;
}
V_1974 -> V_74 += V_42 ;
if ( V_74 & 3 ) {
V_1975 = & V_72 [ V_1974 -> V_74 ] ;
V_1977 = V_74 & 3 ;
V_1976 = V_596 + V_74 - V_1977 ;
V_56 = F_169 ( V_5 , V_1976 , & V_7 ) ;
if ( V_56 )
return V_56 ;
memcpy ( V_1975 , & V_7 , V_1977 ) ;
V_1974 -> V_74 += V_1977 ;
}
return 0 ;
}
static int F_518 ( struct V_365 * V_111 , struct V_1973 * V_1974 , T_4 * V_72 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_56 ;
T_1 V_596 , V_74 , V_1976 , V_1980 ;
T_4 * V_627 ;
T_5 V_1030 , V_1981 ;
if ( F_23 ( V_5 , V_682 ) ||
V_1974 -> V_1978 != V_1979 )
return - V_64 ;
V_596 = V_1974 -> V_596 ;
V_74 = V_1974 -> V_74 ;
if ( ( V_1976 = ( V_596 & 3 ) ) ) {
V_56 = F_169 ( V_5 , V_596 - V_1976 , & V_1030 ) ;
if ( V_56 )
return V_56 ;
V_74 += V_1976 ;
V_596 &= ~ 3 ;
if ( V_74 < 4 )
V_74 = 4 ;
}
V_1980 = 0 ;
if ( V_74 & 3 ) {
V_1980 = 1 ;
V_74 = ( V_74 + 3 ) & ~ 3 ;
V_56 = F_169 ( V_5 , V_596 + V_74 - 4 , & V_1981 ) ;
if ( V_56 )
return V_56 ;
}
V_627 = V_72 ;
if ( V_1976 || V_1980 ) {
V_627 = F_174 ( V_74 , V_633 ) ;
if ( ! V_627 )
return - V_268 ;
if ( V_1976 )
memcpy ( V_627 , & V_1030 , 4 ) ;
if ( V_1980 )
memcpy ( V_627 + V_74 - 4 , & V_1981 , 4 ) ;
memcpy ( V_627 + V_1976 , V_72 , V_1974 -> V_74 ) ;
}
V_56 = F_177 ( V_5 , V_596 , V_74 , V_627 ) ;
if ( V_627 != V_72 )
F_175 ( V_627 ) ;
return V_56 ;
}
static int F_519 ( struct V_365 * V_111 , struct V_1982 * V_643 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_392 ) )
return - V_85 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
return F_520 ( V_212 , V_643 ) ;
}
V_643 -> V_394 = ( V_1983 ) ;
if ( ! ( V_5 -> V_178 & V_393 ) )
V_643 -> V_394 |= ( V_1984 |
V_1985 ) ;
if ( ! ( V_5 -> V_178 & V_360 ) ) {
V_643 -> V_394 |= ( V_1986 |
V_1987 |
V_1988 |
V_1989 |
V_1990 ) ;
V_643 -> V_1991 = V_1992 ;
} else {
V_643 -> V_394 |= V_1993 ;
V_643 -> V_1991 = V_1994 ;
}
V_643 -> V_399 = V_5 -> V_330 . V_399 ;
if ( F_23 ( V_5 , V_359 ) ) {
if ( V_5 -> V_330 . V_343 & V_338 ) {
if ( V_5 -> V_330 . V_343 & V_337 ) {
V_643 -> V_399 |= V_703 ;
} else {
V_643 -> V_399 |= V_703 |
V_1995 ;
}
} else if ( V_5 -> V_330 . V_343 & V_337 ) {
V_643 -> V_399 |= V_1995 ;
}
}
if ( F_145 ( V_111 ) && V_5 -> V_341 ) {
F_521 ( V_643 , V_5 -> V_330 . V_331 ) ;
V_643 -> V_377 = V_5 -> V_330 . V_334 ;
V_643 -> V_1996 = V_5 -> V_330 . V_370 ;
if ( ! ( V_5 -> V_178 & V_360 ) ) {
if ( V_5 -> V_178 & V_821 )
V_643 -> V_1997 = V_1998 ;
else
V_643 -> V_1997 = V_1999 ;
}
} else {
F_521 ( V_643 , V_752 ) ;
V_643 -> V_377 = V_753 ;
V_643 -> V_1997 = V_2000 ;
}
V_643 -> V_2001 = V_5 -> V_160 ;
V_643 -> V_2002 = V_2003 ;
V_643 -> V_353 = V_5 -> V_330 . V_353 ;
V_643 -> V_2004 = 0 ;
V_643 -> V_2005 = 0 ;
return 0 ;
}
static int F_522 ( struct V_365 * V_111 , struct V_1982 * V_643 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_373 = F_523 ( V_643 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_392 ) )
return - V_85 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
return F_524 ( V_212 , V_643 ) ;
}
if ( V_643 -> V_353 != V_358 &&
V_643 -> V_353 != V_777 )
return - V_64 ;
if ( V_643 -> V_353 == V_777 &&
V_643 -> V_377 != V_335 &&
V_643 -> V_377 != V_378 )
return - V_64 ;
if ( V_643 -> V_353 == V_358 ) {
T_1 V_2006 = V_704 |
V_703 |
V_1995 ;
if ( ! ( V_5 -> V_178 & V_393 ) )
V_2006 |= V_771 |
V_762 ;
if ( ! ( V_5 -> V_178 & V_360 ) )
V_2006 |= V_707 |
V_708 |
V_705 |
V_709 |
V_702 ;
else
V_2006 |= V_778 ;
if ( V_643 -> V_399 & ~ V_2006 )
return - V_64 ;
V_2006 &= ( V_771 |
V_762 |
V_707 |
V_708 |
V_705 |
V_709 ) ;
V_643 -> V_399 &= V_2006 ;
} else {
if ( V_5 -> V_178 & V_360 ) {
if ( V_373 != V_332 )
return - V_64 ;
if ( V_643 -> V_377 != V_335 )
return - V_64 ;
} else {
if ( V_373 != V_333 &&
V_373 != V_374 )
return - V_64 ;
}
}
F_240 ( V_5 , 0 ) ;
V_5 -> V_330 . V_353 = V_643 -> V_353 ;
if ( V_643 -> V_353 == V_358 ) {
V_5 -> V_330 . V_399 = ( V_643 -> V_399 |
V_704 ) ;
V_5 -> V_330 . V_373 = V_752 ;
V_5 -> V_330 . V_377 = V_753 ;
} else {
V_5 -> V_330 . V_399 = 0 ;
V_5 -> V_330 . V_373 = V_373 ;
V_5 -> V_330 . V_377 = V_643 -> V_377 ;
}
V_5 -> V_178 |= V_1533 ;
F_142 ( V_5 ) ;
if ( F_145 ( V_111 ) )
F_200 ( V_5 , true ) ;
F_241 ( V_5 ) ;
return 0 ;
}
static void F_525 ( struct V_365 * V_111 , struct V_2007 * V_985 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_526 ( V_985 -> V_2008 , V_2009 , sizeof( V_985 -> V_2008 ) ) ;
F_526 ( V_985 -> V_1971 , V_2010 , sizeof( V_985 -> V_1971 ) ) ;
F_526 ( V_985 -> V_2011 , V_5 -> V_2012 , sizeof( V_985 -> V_2011 ) ) ;
F_526 ( V_985 -> V_2013 , F_527 ( V_5 -> V_12 ) , sizeof( V_985 -> V_2013 ) ) ;
}
static void F_528 ( struct V_365 * V_111 , struct V_2014 * V_2015 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_23 ( V_5 , V_716 ) && F_529 ( & V_5 -> V_12 -> V_111 ) )
V_2015 -> V_394 = V_2016 ;
else
V_2015 -> V_394 = 0 ;
V_2015 -> V_2017 = 0 ;
if ( F_23 ( V_5 , V_112 ) && F_529 ( & V_5 -> V_12 -> V_111 ) )
V_2015 -> V_2017 = V_2016 ;
memset ( & V_2015 -> V_2018 , 0 , sizeof( V_2015 -> V_2018 ) ) ;
}
static int F_530 ( struct V_365 * V_111 , struct V_2014 * V_2015 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_544 * V_2019 = & V_5 -> V_12 -> V_111 ;
if ( V_2015 -> V_2017 & ~ V_2016 )
return - V_64 ;
if ( ( V_2015 -> V_2017 & V_2016 ) &&
! ( F_23 ( V_5 , V_716 ) && F_529 ( V_2019 ) ) )
return - V_64 ;
F_531 ( V_2019 , V_2015 -> V_2017 & V_2016 ) ;
if ( F_44 ( V_2019 ) )
F_84 ( V_5 , V_112 ) ;
else
F_86 ( V_5 , V_112 ) ;
return 0 ;
}
static T_1 F_532 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
return V_5 -> V_2020 ;
}
static void F_533 ( struct V_365 * V_111 , T_1 V_2021 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_5 -> V_2020 = V_2021 ;
}
static int F_534 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_2022 ;
if ( ! F_145 ( V_111 ) )
return - V_85 ;
if ( V_5 -> V_178 & V_568 )
return - V_64 ;
F_142 ( V_5 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
if ( ! ( V_5 -> V_178 & V_392 ) )
return - V_85 ;
V_2022 = F_122 ( V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ) ;
} else {
T_1 V_772 ;
F_70 ( & V_5 -> V_209 ) ;
V_2022 = - V_64 ;
F_57 ( V_5 , V_204 , & V_772 ) ;
if ( ! F_57 ( V_5 , V_204 , & V_772 ) &&
( ( V_772 & V_577 ) ||
( V_5 -> V_178 & V_788 ) ) ) {
F_59 ( V_5 , V_204 , V_772 | V_578 |
V_577 ) ;
V_2022 = 0 ;
}
F_71 ( & V_5 -> V_209 ) ;
}
return V_2022 ;
}
static void F_535 ( struct V_365 * V_111 , struct V_2023 * V_2024 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_2024 -> V_2025 = V_5 -> V_1140 ;
if ( F_23 ( V_5 , V_1340 ) )
V_2024 -> V_2026 = V_5 -> V_1145 ;
else
V_2024 -> V_2026 = 0 ;
V_2024 -> V_2027 = V_1098 - 1 ;
V_2024 -> V_1338 = V_5 -> V_1338 ;
if ( F_23 ( V_5 , V_1340 ) )
V_2024 -> V_1342 = V_5 -> V_1342 ;
else
V_2024 -> V_1342 = 0 ;
V_2024 -> V_1090 = V_5 -> V_123 [ 0 ] . V_1090 ;
}
static int F_536 ( struct V_365 * V_111 , struct V_2023 * V_2024 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_42 , V_125 = 0 , V_75 = 0 ;
if ( ( V_2024 -> V_1338 > V_5 -> V_1140 ) ||
( V_2024 -> V_1342 > V_5 -> V_1145 ) ||
( V_2024 -> V_1090 > V_1098 - 1 ) ||
( V_2024 -> V_1090 <= V_1317 ) ||
( F_23 ( V_5 , V_1293 ) &&
( V_2024 -> V_1090 <= ( V_1317 * 3 ) ) ) )
return - V_64 ;
if ( F_145 ( V_111 ) ) {
F_123 ( V_5 ) ;
F_340 ( V_5 ) ;
V_125 = 1 ;
}
F_240 ( V_5 , V_125 ) ;
V_5 -> V_1338 = V_2024 -> V_1338 ;
if ( F_23 ( V_5 , V_2028 ) &&
V_5 -> V_1338 > 63 )
V_5 -> V_1338 = 63 ;
V_5 -> V_1342 = V_2024 -> V_1342 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1090 = V_2024 -> V_1090 ;
if ( F_145 ( V_111 ) ) {
F_430 ( V_5 , V_110 , 1 ) ;
V_75 = F_479 ( V_5 , false ) ;
if ( ! V_75 )
F_342 ( V_5 ) ;
}
F_241 ( V_5 ) ;
if ( V_125 && ! V_75 )
F_120 ( V_5 ) ;
return V_75 ;
}
static void F_537 ( struct V_365 * V_111 , struct V_2029 * V_2030 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_2030 -> V_353 = ! ! F_23 ( V_5 , V_359 ) ;
if ( V_5 -> V_330 . V_343 & V_338 )
V_2030 -> V_2031 = 1 ;
else
V_2030 -> V_2031 = 0 ;
if ( V_5 -> V_330 . V_343 & V_337 )
V_2030 -> V_2032 = 1 ;
else
V_2030 -> V_2032 = 0 ;
}
static int F_538 ( struct V_365 * V_111 , struct V_2029 * V_2030 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 = 0 ;
if ( V_5 -> V_330 . V_353 == V_358 )
F_142 ( V_5 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
T_1 V_952 ;
struct V_211 * V_212 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
if ( ! ( V_212 -> V_394 & V_396 ) ||
( ! ( V_212 -> V_394 & V_397 ) &&
( V_2030 -> V_2031 != V_2030 -> V_2032 ) ) )
return - V_64 ;
V_5 -> V_330 . V_343 = 0 ;
if ( V_2030 -> V_2031 ) {
V_5 -> V_330 . V_343 |= V_338 ;
if ( V_2030 -> V_2032 ) {
V_5 -> V_330 . V_343 |= V_337 ;
V_952 = V_703 ;
} else
V_952 = V_703 |
V_1995 ;
} else if ( V_2030 -> V_2032 ) {
V_5 -> V_330 . V_343 |= V_337 ;
V_952 = V_1995 ;
} else
V_952 = 0 ;
if ( V_2030 -> V_353 )
F_84 ( V_5 , V_359 ) ;
else
F_86 ( V_5 , V_359 ) ;
if ( V_5 -> V_178 & V_392 ) {
T_1 V_2033 = V_212 -> V_399 &
( V_703 | V_1995 ) ;
if ( V_2033 != V_952 ) {
V_212 -> V_399 &=
~ ( V_703 |
V_1995 ) ;
V_212 -> V_399 |= V_952 ;
if ( V_212 -> V_353 ) {
return F_122 ( V_212 ) ;
}
}
if ( ! V_2030 -> V_353 )
F_108 ( V_5 , 0 , 0 ) ;
} else {
V_5 -> V_330 . V_399 &=
~ ( V_703 |
V_1995 ) ;
V_5 -> V_330 . V_399 |= V_952 ;
}
} else {
int V_125 = 0 ;
if ( F_145 ( V_111 ) ) {
F_340 ( V_5 ) ;
V_125 = 1 ;
}
F_240 ( V_5 , V_125 ) ;
if ( V_2030 -> V_353 )
F_84 ( V_5 , V_359 ) ;
else
F_86 ( V_5 , V_359 ) ;
if ( V_2030 -> V_2031 )
V_5 -> V_330 . V_343 |= V_338 ;
else
V_5 -> V_330 . V_343 &= ~ V_338 ;
if ( V_2030 -> V_2032 )
V_5 -> V_330 . V_343 |= V_337 ;
else
V_5 -> V_330 . V_343 &= ~ V_337 ;
if ( F_145 ( V_111 ) ) {
F_430 ( V_5 , V_110 , 1 ) ;
V_75 = F_479 ( V_5 , false ) ;
if ( ! V_75 )
F_342 ( V_5 ) ;
}
F_241 ( V_5 ) ;
}
V_5 -> V_178 |= V_1533 ;
return V_75 ;
}
static int F_539 ( struct V_365 * V_111 , int V_2034 )
{
switch ( V_2034 ) {
case V_2035 :
return V_2036 ;
case V_2037 :
return V_2038 ;
default:
return - V_1039 ;
}
}
static int F_540 ( struct V_365 * V_111 , struct V_2039 * V_985 ,
T_1 * T_17 V_2040 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1063 ) )
return - V_1039 ;
switch ( V_985 -> V_643 ) {
case V_2041 :
if ( F_145 ( V_5 -> V_111 ) )
V_985 -> V_72 = V_5 -> V_1221 ;
else {
V_985 -> V_72 = F_541 () ;
if ( V_985 -> V_72 > V_2042 )
V_985 -> V_72 = V_2042 ;
}
V_985 -> V_72 -= 1 ;
return 0 ;
default:
return - V_1039 ;
}
}
static T_1 F_542 ( struct V_365 * V_111 )
{
T_1 V_635 = 0 ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_23 ( V_5 , V_1063 ) )
V_635 = V_1526 ;
return V_635 ;
}
static int F_543 ( struct V_365 * V_111 , T_1 * V_2043 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1526 ; V_42 ++ )
V_2043 [ V_42 ] = V_5 -> V_1527 [ V_42 ] ;
return 0 ;
}
static int F_544 ( struct V_365 * V_111 , const T_1 * V_2043 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_18 V_42 ;
for ( V_42 = 0 ; V_42 < V_1526 ; V_42 ++ )
V_5 -> V_1527 [ V_42 ] = V_2043 [ V_42 ] ;
if ( ! F_145 ( V_111 ) || ! F_23 ( V_5 , V_1210 ) )
return 0 ;
F_240 ( V_5 , 0 ) ;
F_454 ( V_5 ) ;
F_241 ( V_5 ) ;
return 0 ;
}
static void F_545 ( struct V_365 * V_111 ,
struct V_2044 * V_2045 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_2046 = F_496 () ;
V_2045 -> V_2047 = V_5 -> V_1895 ;
V_2045 -> V_2048 = V_5 -> V_1897 ;
if ( F_145 ( V_111 ) ) {
V_2045 -> V_2049 = V_5 -> V_1221 ;
V_2045 -> V_2050 = V_5 -> V_1348 ;
} else {
if ( V_5 -> V_1894 )
V_2045 -> V_2049 = V_5 -> V_1894 ;
else
V_2045 -> V_2049 = F_320 ( V_2046 , V_5 -> V_1895 ) ;
if ( V_5 -> V_1893 )
V_2045 -> V_2050 = V_5 -> V_1893 ;
else
V_2045 -> V_2050 = F_320 ( V_2046 , V_5 -> V_1897 ) ;
}
}
static int F_546 ( struct V_365 * V_111 ,
struct V_2044 * V_2045 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1063 ) )
return - V_1039 ;
if ( V_2045 -> V_2049 > V_5 -> V_1895 ||
V_2045 -> V_2050 > V_5 -> V_1897 )
return - V_64 ;
V_5 -> V_1894 = V_2045 -> V_2049 ;
V_5 -> V_1893 = V_2045 -> V_2050 ;
if ( ! F_145 ( V_111 ) )
return 0 ;
F_507 ( V_5 ) ;
F_140 ( V_5 ) ;
F_505 ( V_5 , true , false , false ) ;
return 0 ;
}
static void F_547 ( struct V_365 * V_111 , T_1 V_2051 , T_4 * V_627 )
{
switch ( V_2051 ) {
case V_2037 :
memcpy ( V_627 , & V_2052 , sizeof( V_2052 ) ) ;
break;
case V_2035 :
memcpy ( V_627 , & V_2053 , sizeof( V_2053 ) ) ;
break;
default:
F_548 ( 1 ) ;
break;
}
}
static int F_549 ( struct V_365 * V_111 ,
enum V_2054 V_846 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_145 ( V_5 -> V_111 ) )
return - V_85 ;
switch ( V_846 ) {
case V_2055 :
return 1 ;
case V_2056 :
F_46 ( V_726 , V_836 |
V_834 |
V_835 |
V_2057 |
V_940 |
V_2058 |
V_2059 ) ;
break;
case V_2060 :
F_46 ( V_726 , V_836 |
V_940 ) ;
break;
case V_2061 :
F_46 ( V_726 , V_5 -> V_564 ) ;
break;
}
return 0 ;
}
static void F_550 ( struct V_365 * V_111 ,
struct V_2062 * V_1910 , T_6 * V_2063 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_5 -> V_1351 )
F_432 ( V_5 , (struct V_1909 * ) V_2063 ) ;
else
memset ( V_2063 , 0 , sizeof( struct V_1909 ) ) ;
}
static T_5 * F_551 ( struct V_4 * V_5 , T_1 * V_2064 )
{
int V_42 ;
T_5 * V_627 ;
T_1 V_596 = 0 , V_74 = 0 ;
T_1 V_1978 , V_7 ;
if ( F_23 ( V_5 , V_682 ) || F_168 ( V_5 , 0 , & V_1978 ) )
return NULL ;
if ( V_1978 == V_1979 ) {
for ( V_596 = V_2065 ;
V_596 < V_2066 ;
V_596 += V_2067 ) {
if ( F_168 ( V_5 , V_596 , & V_7 ) )
return NULL ;
if ( ( V_7 >> V_2068 ) ==
V_2069 )
break;
}
if ( V_596 != V_2066 ) {
V_74 = ( V_7 & V_2070 ) * 4 ;
if ( F_168 ( V_5 , V_596 + 4 , & V_596 ) )
return NULL ;
V_596 = F_167 ( V_5 , V_596 ) ;
}
}
if ( ! V_596 || ! V_74 ) {
V_596 = V_2071 ;
V_74 = V_2072 ;
}
V_627 = F_174 ( V_74 , V_633 ) ;
if ( V_627 == NULL )
return NULL ;
if ( V_1978 == V_1979 ) {
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 ) {
if ( F_169 ( V_5 , V_596 + V_42 , & V_627 [ V_42 / 4 ] ) )
goto error;
}
} else {
T_4 * V_2073 ;
T_14 V_2074 ;
unsigned int V_2075 = 0 ;
V_2073 = ( T_4 * ) & V_627 [ 0 ] ;
for ( V_42 = 0 ; V_2075 < V_74 && V_42 < 3 ; V_42 ++ , V_2075 += V_2074 , V_2073 += V_2074 ) {
V_2074 = F_552 ( V_5 -> V_12 , V_2075 ,
V_74 - V_2075 , V_2073 ) ;
if ( V_2074 == - V_2076 || V_2074 == - V_2077 )
V_2074 = 0 ;
else if ( V_2074 < 0 )
goto error;
}
if ( V_2075 != V_74 )
goto error;
}
* V_2064 = V_74 ;
return V_627 ;
error:
F_175 ( V_627 ) ;
return NULL ;
}
static int F_553 ( struct V_4 * V_5 )
{
T_1 V_2078 , V_1978 , V_74 ;
T_5 * V_627 ;
int V_42 , V_628 , V_1508 , V_75 = 0 , V_635 ;
if ( F_23 ( V_5 , V_682 ) )
return 0 ;
if ( F_168 ( V_5 , 0 , & V_1978 ) != 0 )
return - V_210 ;
if ( V_1978 == V_1979 )
V_635 = V_2079 ;
else if ( ( V_1978 & V_2080 ) == V_2081 ) {
if ( ( V_1978 & V_2082 ) ==
V_2083 ) {
switch ( V_1978 & V_2084 ) {
case V_2085 :
V_635 = V_2086 ;
break;
case V_2087 :
V_635 = V_2088 ;
break;
case V_2089 :
V_635 = V_2090 ;
break;
case V_2091 :
V_635 = V_2092 ;
break;
case V_2093 :
V_635 = V_2094 ;
break;
case V_2095 :
V_635 = V_2096 ;
break;
default:
return - V_210 ;
}
} else
return 0 ;
} else if ( ( V_1978 & V_2097 ) == V_2098 )
V_635 = V_2099 ;
else
return - V_210 ;
V_627 = F_174 ( V_635 , V_633 ) ;
if ( V_627 == NULL )
return - V_268 ;
V_75 = - V_210 ;
for ( V_42 = 0 , V_628 = 0 ; V_42 < V_635 ; V_42 += 4 , V_628 ++ ) {
V_75 = F_169 ( V_5 , V_42 , & V_627 [ V_628 ] ) ;
if ( V_75 )
break;
}
if ( V_42 < V_635 )
goto V_503;
V_1978 = F_172 ( V_627 [ 0 ] ) ;
if ( ( V_1978 & V_2080 ) ==
V_2081 ) {
T_4 * V_2100 = ( T_4 * ) V_627 , V_2101 = 0 ;
if ( ( V_1978 & V_2084 ) ==
V_2087 ) {
for ( V_42 = 0 ; V_42 < V_2102 ; V_42 ++ )
V_2101 += V_2100 [ V_42 ] ;
for ( V_42 = V_2102 + 4 ; V_42 < V_635 ; V_42 ++ )
V_2101 += V_2100 [ V_42 ] ;
} else {
for ( V_42 = 0 ; V_42 < V_635 ; V_42 ++ )
V_2101 += V_2100 [ V_42 ] ;
}
if ( V_2101 == 0 ) {
V_75 = 0 ;
goto V_503;
}
V_75 = - V_210 ;
goto V_503;
}
if ( ( V_1978 & V_2097 ) ==
V_2098 ) {
T_4 V_72 [ V_2103 ] ;
T_4 V_2104 [ V_2103 ] ;
T_4 * V_2100 = ( T_4 * ) V_627 ;
for ( V_42 = 0 , V_628 = 0 , V_1508 = 0 ; V_42 < V_2099 ; V_42 ++ ) {
if ( ( V_42 == 0 ) || ( V_42 == 8 ) ) {
int V_2105 ;
T_4 V_2106 ;
for ( V_2105 = 0 , V_2106 = 0x80 ; V_2105 < 7 ; V_2105 ++ , V_2106 >>= 1 )
V_2104 [ V_1508 ++ ] = V_2100 [ V_42 ] & V_2106 ;
V_42 ++ ;
} else if ( V_42 == 16 ) {
int V_2105 ;
T_4 V_2106 ;
for ( V_2105 = 0 , V_2106 = 0x20 ; V_2105 < 6 ; V_2105 ++ , V_2106 >>= 1 )
V_2104 [ V_1508 ++ ] = V_2100 [ V_42 ] & V_2106 ;
V_42 ++ ;
for ( V_2105 = 0 , V_2106 = 0x80 ; V_2105 < 8 ; V_2105 ++ , V_2106 >>= 1 )
V_2104 [ V_1508 ++ ] = V_2100 [ V_42 ] & V_2106 ;
V_42 ++ ;
}
V_72 [ V_628 ++ ] = V_2100 [ V_42 ] ;
}
V_75 = - V_210 ;
for ( V_42 = 0 ; V_42 < V_2103 ; V_42 ++ ) {
T_4 V_2107 = F_554 ( V_72 [ V_42 ] ) ;
if ( ( V_2107 & 0x1 ) && V_2104 [ V_42 ] )
goto V_503;
else if ( ! ( V_2107 & 0x1 ) && ! V_2104 [ V_42 ] )
goto V_503;
}
V_75 = 0 ;
goto V_503;
}
V_75 = - V_210 ;
V_2078 = F_446 ( ( unsigned char * ) V_627 , 0x10 ) ;
if ( V_2078 != F_555 ( V_627 [ 0x10 / 4 ] ) )
goto V_503;
V_2078 = F_446 ( ( unsigned char * ) & V_627 [ 0x74 / 4 ] , 0x88 ) ;
if ( V_2078 != F_555 ( V_627 [ 0xfc / 4 ] ) )
goto V_503;
F_175 ( V_627 ) ;
V_627 = F_551 ( V_5 , & V_74 ) ;
if ( ! V_627 )
return - V_268 ;
V_42 = F_556 ( ( T_4 * ) V_627 , 0 , V_74 , V_2108 ) ;
if ( V_42 > 0 ) {
V_628 = F_557 ( & ( ( T_4 * ) V_627 ) [ V_42 ] ) ;
if ( V_628 < 0 )
goto V_503;
if ( V_42 + V_2109 + V_628 > V_74 )
goto V_503;
V_42 += V_2109 ;
V_628 = F_558 ( ( T_4 * ) V_627 , V_42 , V_628 ,
V_2110 ) ;
if ( V_628 > 0 ) {
T_4 V_2101 = 0 ;
V_628 += V_2111 ;
for ( V_42 = 0 ; V_42 <= V_628 ; V_42 ++ )
V_2101 += ( ( T_4 * ) V_627 ) [ V_42 ] ;
if ( V_2101 )
goto V_503;
}
}
V_75 = 0 ;
V_503:
F_175 ( V_627 ) ;
return V_75 ;
}
static int F_559 ( struct V_4 * V_5 )
{
int V_42 , F_493 ;
if ( ! F_145 ( V_5 -> V_111 ) )
return - V_82 ;
if ( V_5 -> V_178 & V_360 )
F_493 = V_2112 ;
else
F_493 = V_2113 ;
for ( V_42 = 0 ; V_42 < F_493 ; V_42 ++ ) {
if ( V_5 -> V_341 )
return 0 ;
if ( F_560 ( 1000 ) )
break;
}
return - V_210 ;
}
static int F_561 ( struct V_4 * V_5 )
{
int V_42 , V_2114 , V_2115 ;
T_1 V_596 , V_2116 , V_2117 , V_7 , V_2118 , V_2119 ;
static struct {
T_3 V_596 ;
T_3 V_10 ;
#define F_562 0x1
#define F_563 0x2
#define F_564 0x4
#define F_565 0x8
T_1 V_2116 ;
T_1 V_2117 ;
} V_2120 [] = {
{ V_383 , F_563 ,
0x00000000 , 0x00ef6f8c } ,
{ V_383 , F_562 ,
0x00000000 , 0x01ef6b8c } ,
{ V_790 , F_563 ,
0x03800107 , 0x00000000 } ,
{ V_790 , F_562 ,
0x03800100 , 0x00000000 } ,
{ V_690 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_691 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1622 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_364 , 0x0000 ,
0x00000000 , 0x00000070 } ,
{ V_387 , 0x0000 ,
0x00000000 , 0x00003fff } ,
{ V_362 , F_563 ,
0x00000000 , 0x000007fc } ,
{ V_362 , F_562 ,
0x00000000 , 0x000007dc } ,
{ V_1510 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1511 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1512 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1513 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1056 + 0 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1056 + 4 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1056 + 8 , F_563 ,
0x00000000 , 0x00000003 } ,
{ V_1056 + 0xc , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1616 + 0 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1616 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1616 + 8 , 0x0000 ,
0x00000000 , 0xffff0002 } ,
{ V_1616 + 0xc , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1503 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1503 , F_562 ,
0x00000000 , 0x000003ff } ,
{ V_1506 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_138 , F_563 ,
0x00000000 , 0x00000004 } ,
{ V_138 , F_562 ,
0x00000000 , 0x000000f6 } ,
{ V_1468 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1468 , F_562 ,
0x00000000 , 0x000003ff } ,
{ V_1459 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1459 , F_562 ,
0x00000000 , 0x000003ff } ,
{ V_1470 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1470 , F_562 | F_564 ,
0x00000000 , 0x000000ff } ,
{ V_1461 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1461 , F_562 | F_564 ,
0x00000000 , 0x000000ff } ,
{ V_1476 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1478 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1472 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1472 , F_562 | F_564 ,
0x00000000 , 0x000000ff } ,
{ V_1463 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1463 , F_562 | F_564 ,
0x00000000 , 0x000000ff } ,
{ V_969 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1671 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1671 + 4 , F_563 ,
0x00000000 , 0xffffffff } ,
{ V_1493 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1493 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1672 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1673 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1584 , F_565 ,
0x00000000 , 0x007fff80 } ,
{ V_1586 , F_565 ,
0x00000000 , 0x007fffff } ,
{ V_1595 , 0x0000 ,
0x00000000 , 0x0000003f } ,
{ V_1598 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1600 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1589 , F_563 ,
0xffffffff , 0x00000000 } ,
{ V_1591 , F_563 ,
0xffffffff , 0x00000000 } ,
{ V_2121 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_2122 + 4 , F_563 ,
0x00000000 , 0x000001ff } ,
{ V_2123 + 4 , 0x0000 ,
0x00000000 , 0x000007ff } ,
{ V_2124 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ 0xffff , 0x0000 , 0x00000000 , 0x00000000 } ,
} ;
V_2114 = V_2115 = 0 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_2114 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2115 = 1 ;
}
for ( V_42 = 0 ; V_2120 [ V_42 ] . V_596 != 0xffff ; V_42 ++ ) {
if ( V_2114 && ( V_2120 [ V_42 ] . V_10 & F_563 ) )
continue;
if ( ! V_2114 && ( V_2120 [ V_42 ] . V_10 & F_562 ) )
continue;
if ( F_23 ( V_5 , V_1641 ) &&
( V_2120 [ V_42 ] . V_10 & F_564 ) )
continue;
if ( V_2115 && ( V_2120 [ V_42 ] . V_10 & F_565 ) )
continue;
V_596 = ( T_1 ) V_2120 [ V_42 ] . V_596 ;
V_2116 = V_2120 [ V_42 ] . V_2116 ;
V_2117 = V_2120 [ V_42 ] . V_2117 ;
V_2118 = F_33 ( V_596 ) ;
V_2119 = V_2118 & V_2116 ;
F_46 ( V_596 , 0 ) ;
V_7 = F_33 ( V_596 ) ;
if ( ( ( V_7 & V_2116 ) != V_2119 ) || ( V_7 & V_2117 ) )
goto V_503;
F_46 ( V_596 , V_2116 | V_2117 ) ;
V_7 = F_33 ( V_596 ) ;
if ( ( V_7 & V_2116 ) != V_2119 )
goto V_503;
if ( ( V_7 & V_2117 ) != V_2117 )
goto V_503;
F_46 ( V_596 , V_2118 ) ;
}
return 0 ;
V_503:
if ( F_566 ( V_5 ) )
F_185 ( V_5 -> V_111 ,
L_74 , V_596 ) ;
F_46 ( V_596 , V_2118 ) ;
return - V_210 ;
}
static int F_567 ( struct V_4 * V_5 , T_1 V_596 , T_1 V_74 )
{
static const T_1 V_2125 [] = { 0x00000000 , 0xffffffff , 0xaa55a55a } ;
int V_42 ;
T_1 V_628 ;
for ( V_42 = 0 ; V_42 < F_568 ( V_2125 ) ; V_42 ++ ) {
for ( V_628 = 0 ; V_628 < V_74 ; V_628 += 4 ) {
T_1 V_7 ;
F_29 ( V_5 , V_596 + V_628 , V_2125 [ V_42 ] ) ;
F_32 ( V_5 , V_596 + V_628 , & V_7 ) ;
if ( V_7 != V_2125 [ V_42 ] )
return - V_210 ;
}
}
return 0 ;
}
static int F_569 ( struct V_4 * V_5 )
{
static struct V_2126 {
T_1 V_596 ;
T_1 V_74 ;
} V_2127 [] = {
{ 0x00000000 , 0x00b50 } ,
{ 0x00002000 , 0x1c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2128 [] = {
{ 0x00000100 , 0x0000c } ,
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x01000 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0e000 } ,
{ 0xffffffff , 0x00000 }
} , V_2129 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x00800 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2130 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00400 } ,
{ 0x00006000 , 0x00400 } ,
{ 0x00008000 , 0x01000 } ,
{ 0x00010000 , 0x01000 } ,
{ 0xffffffff , 0x00000 }
} , V_2131 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0x00020000 , 0x13c00 } ,
{ 0xffffffff , 0x00000 }
} , V_2132 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x09800 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0xffffffff , 0x00000 }
} ;
struct V_2126 * V_2133 ;
int V_75 = 0 ;
int V_42 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_2133 = V_2131 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_766 )
V_2133 = V_2132 ;
else if ( F_23 ( V_5 , 5755_PLUS ) )
V_2133 = V_2129 ;
else if ( F_30 ( V_5 ) == V_36 )
V_2133 = V_2130 ;
else if ( F_23 ( V_5 , 5705_PLUS ) )
V_2133 = V_2128 ;
else
V_2133 = V_2127 ;
for ( V_42 = 0 ; V_2133 [ V_42 ] . V_596 != 0xffffffff ; V_42 ++ ) {
V_75 = F_567 ( V_5 , V_2133 [ V_42 ] . V_596 , V_2133 [ V_42 ] . V_74 ) ;
if ( V_75 )
break;
}
return V_75 ;
}
static int F_570 ( struct V_4 * V_5 , T_1 V_2134 , bool V_2135 )
{
T_1 V_2136 , V_2137 , V_2138 , V_1131 ;
T_1 V_1268 = 0 , V_1246 = 0 , V_1167 , V_126 , V_2139 , V_7 ;
T_1 V_1159 ;
struct V_1109 * V_1110 ;
T_4 * V_2140 , * V_2141 ;
T_9 V_1136 ;
int V_2142 , V_2143 , V_2144 , V_42 , V_75 ;
struct V_1134 * V_1135 ;
struct V_130 * V_131 , * V_2145 ;
struct V_1129 * V_1130 = & V_5 -> V_123 [ 0 ] . V_1091 ;
V_131 = & V_5 -> V_123 [ 0 ] ;
V_2145 = & V_5 -> V_123 [ 0 ] ;
if ( V_5 -> V_129 > 1 ) {
if ( F_23 ( V_5 , V_1210 ) )
V_2145 = & V_5 -> V_123 [ 1 ] ;
if ( F_23 ( V_5 , V_1105 ) )
V_131 = & V_5 -> V_123 [ 1 ] ;
}
V_126 = V_131 -> V_126 | V_2145 -> V_126 ;
V_75 = - V_210 ;
V_2143 = V_2134 ;
V_1110 = F_303 ( V_5 -> V_111 , V_2143 ) ;
if ( ! V_1110 )
return - V_268 ;
V_2140 = F_306 ( V_1110 , V_2143 ) ;
memcpy ( V_2140 , V_5 -> V_111 -> V_689 , V_1524 ) ;
memset ( V_2140 + V_1524 , 0x0 , 8 ) ;
F_46 ( V_1622 , V_2143 + V_1184 ) ;
if ( V_2135 ) {
struct V_1286 * V_1287 = (struct V_1286 * ) & V_2140 [ V_1202 ] ;
T_1 V_1289 = V_2146 + V_2147 +
V_2148 ;
memcpy ( V_2140 + V_1524 * 2 , V_2149 ,
sizeof( V_2149 ) ) ;
V_1246 = V_2150 ;
V_7 = V_2143 - V_1524 * 2 - sizeof( V_2149 ) ;
V_2142 = F_571 ( V_7 , V_2150 ) ;
V_1287 -> V_1292 = F_310 ( ( T_3 ) ( V_1246 + V_1289 ) ) ;
V_1268 = ( V_1294 |
V_1295 ) ;
if ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ) {
struct V_2151 * V_2152 ;
V_7 = V_1202 + V_2146 ;
V_2152 = (struct V_2151 * ) & V_2140 [ V_7 ] ;
V_2152 -> V_1291 = 0 ;
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
F_30 ( V_5 ) == V_502 ) {
V_1246 |= ( V_2148 << 9 ) ;
} else {
V_1268 |= ( V_2148 << 10 ) ;
}
V_2139 = V_1524 * 2 + sizeof( V_2149 ) ;
} else {
V_2142 = 1 ;
V_2139 = V_1202 ;
if ( F_23 ( V_5 , V_1304 ) &&
V_2143 > V_1305 )
V_1268 |= V_1306 ;
}
for ( V_42 = V_2139 ; V_42 < V_2143 ; V_42 ++ )
V_2140 [ V_42 ] = ( T_4 ) ( V_42 & 0xff ) ;
V_1136 = F_292 ( V_5 -> V_12 , V_1110 -> V_72 , V_2143 , V_1118 ) ;
if ( F_293 ( V_5 -> V_12 , V_1136 ) ) {
F_275 ( V_1110 ) ;
return - V_210 ;
}
V_7 = V_131 -> V_1089 ;
V_131 -> V_1108 [ V_7 ] . V_1110 = V_1110 ;
F_294 ( & V_131 -> V_1108 [ V_7 ] , V_1117 , V_1136 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_2145 -> V_126 ) ;
F_24 ( 10 ) ;
V_2136 = V_2145 -> V_134 -> V_145 [ 0 ] . V_1087 ;
V_1159 = F_262 ( V_131 ) ;
if ( F_361 ( V_131 , & V_7 , & V_1159 , V_1136 , V_2143 ,
V_1268 | V_1262 , V_1246 , 0 ) ) {
V_131 -> V_1108 [ V_7 ] . V_1110 = NULL ;
F_275 ( V_1110 ) ;
return - V_210 ;
}
V_131 -> V_1089 ++ ;
F_49 () ;
F_390 ( V_131 -> V_1316 , V_131 -> V_1089 ) ;
F_486 ( V_131 -> V_1316 ) ;
F_24 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 35 ; V_42 ++ ) {
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_126 ) ;
F_24 ( 10 ) ;
V_2138 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
V_2137 = V_2145 -> V_134 -> V_145 [ 0 ] . V_1087 ;
if ( ( V_2138 == V_131 -> V_1089 ) &&
( V_2137 == ( V_2136 + V_2142 ) ) )
break;
}
F_362 ( V_131 , V_131 -> V_1089 - 1 , - 1 ) ;
F_275 ( V_1110 ) ;
if ( V_2138 != V_131 -> V_1089 )
goto V_503;
if ( V_2137 != V_2136 + V_2142 )
goto V_503;
V_7 = V_2139 ;
while ( V_2137 != V_2136 ) {
V_1135 = & V_2145 -> V_1165 [ V_2136 ++ ] ;
V_1167 = V_1135 -> V_1170 & V_1171 ;
V_1131 = V_1135 -> V_1170 & V_1172 ;
if ( ( V_1135 -> V_1174 & V_1175 ) != 0 &&
( V_1135 -> V_1174 != V_1176 ) )
goto V_503;
V_2144 = ( ( V_1135 -> V_1181 & V_1182 ) >> V_1183 )
- V_1184 ;
if ( ! V_2135 ) {
if ( V_2144 != V_2143 )
goto V_503;
if ( V_2134 <= V_1332 - V_1184 ) {
if ( V_1131 != V_1139 )
goto V_503;
} else {
if ( V_1131 != V_1144 )
goto V_503;
}
} else if ( ( V_1135 -> V_1185 & V_1194 ) &&
( V_1135 -> V_1195 & V_1196 )
>> V_1197 != 0xffff ) {
goto V_503;
}
if ( V_1131 == V_1139 ) {
V_2141 = V_1130 -> V_1142 [ V_1167 ] . V_72 ;
V_1136 = F_269 ( & V_1130 -> V_1142 [ V_1167 ] ,
V_1117 ) ;
} else if ( V_1131 == V_1144 ) {
V_2141 = V_1130 -> V_1148 [ V_1167 ] . V_72 ;
V_1136 = F_269 ( & V_1130 -> V_1148 [ V_1167 ] ,
V_1117 ) ;
} else
goto V_503;
F_304 ( V_5 -> V_12 , V_1136 , V_2144 ,
V_1127 ) ;
V_2141 += F_289 ( V_5 ) ;
for ( V_42 = V_2139 ; V_42 < V_2144 ; V_42 ++ , V_7 ++ ) {
if ( * ( V_2141 + V_42 ) != ( T_4 ) ( V_7 & 0xff ) )
goto V_503;
}
}
V_75 = 0 ;
V_503:
return V_75 ;
}
static int F_572 ( struct V_4 * V_5 , T_6 * V_72 , bool V_2153 )
{
int V_75 = - V_210 ;
T_1 V_2154 ;
T_1 V_2155 = 9000 ;
if ( V_5 -> V_1259 )
V_2155 = V_5 -> V_1259 - V_1202 ;
V_2154 = V_5 -> V_178 & V_339 ;
V_5 -> V_178 &= ~ V_339 ;
if ( ! F_145 ( V_5 -> V_111 ) ) {
V_72 [ V_2156 ] = V_2157 ;
V_72 [ V_2158 ] = V_2157 ;
if ( V_2153 )
V_72 [ V_2159 ] = V_2157 ;
goto V_186;
}
V_75 = F_456 ( V_5 , true ) ;
if ( V_75 ) {
V_72 [ V_2156 ] = V_2157 ;
V_72 [ V_2158 ] = V_2157 ;
if ( V_2153 )
V_72 [ V_2159 ] = V_2157 ;
goto V_186;
}
if ( F_23 ( V_5 , V_1210 ) ) {
int V_42 ;
for ( V_42 = V_1528 ;
V_42 < V_1528 + V_1526 ; V_42 += 4 )
F_46 ( V_42 , 0x0 ) ;
}
if ( F_30 ( V_5 ) != V_567 &&
! F_23 ( V_5 , V_152 ) ) {
F_391 ( V_5 , true ) ;
if ( F_570 ( V_5 , V_2160 , false ) )
V_72 [ V_2156 ] |= V_2161 ;
if ( F_23 ( V_5 , V_1340 ) &&
F_570 ( V_5 , V_2155 + V_1202 , false ) )
V_72 [ V_2156 ] |= V_2162 ;
F_391 ( V_5 , false ) ;
}
if ( ! ( V_5 -> V_178 & V_568 ) &&
! F_23 ( V_5 , V_267 ) ) {
int V_42 ;
F_392 ( V_5 , 0 , false ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
if ( F_33 ( V_950 ) & V_951 )
break;
F_99 ( 1 ) ;
}
if ( F_570 ( V_5 , V_2160 , false ) )
V_72 [ V_2158 ] |= V_2161 ;
if ( F_23 ( V_5 , V_1593 ) &&
F_570 ( V_5 , V_2160 , true ) )
V_72 [ V_2158 ] |= V_2163 ;
if ( F_23 ( V_5 , V_1340 ) &&
F_570 ( V_5 , V_2155 + V_1202 , false ) )
V_72 [ V_2158 ] |= V_2162 ;
if ( V_2153 ) {
F_392 ( V_5 , 0 , true ) ;
F_99 ( 40 ) ;
if ( F_570 ( V_5 , V_2160 , false ) )
V_72 [ V_2159 ] |=
V_2161 ;
if ( F_23 ( V_5 , V_1593 ) &&
F_570 ( V_5 , V_2160 , true ) )
V_72 [ V_2159 ] |=
V_2163 ;
if ( F_23 ( V_5 , V_1340 ) &&
F_570 ( V_5 , V_2155 + V_1202 , false ) )
V_72 [ V_2159 ] |=
V_2162 ;
}
if ( V_5 -> V_178 & V_514 )
F_128 ( V_5 , true ) ;
}
V_75 = ( V_72 [ V_2156 ] | V_72 [ V_2158 ] |
V_72 [ V_2159 ] ) ? - V_210 : 0 ;
V_186:
V_5 -> V_178 |= V_2154 ;
return V_75 ;
}
static void F_573 ( struct V_365 * V_111 , struct V_2164 * V_2165 ,
T_6 * V_72 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
bool V_2166 = V_2165 -> V_10 & V_2167 ;
if ( V_5 -> V_178 & V_400 ) {
if ( F_196 ( V_5 ) ) {
V_2165 -> V_10 |= V_2168 ;
memset ( V_72 , 1 , sizeof( T_6 ) * V_2036 ) ;
return;
}
F_42 ( V_5 , V_96 ) ;
}
memset ( V_72 , 0 , sizeof( T_6 ) * V_2036 ) ;
if ( F_553 ( V_5 ) != 0 ) {
V_2165 -> V_10 |= V_2168 ;
V_72 [ V_2169 ] = 1 ;
}
if ( ! V_2166 && F_559 ( V_5 ) ) {
V_2165 -> V_10 |= V_2168 ;
V_72 [ V_2170 ] = 1 ;
}
if ( V_2165 -> V_10 & V_2171 ) {
int V_75 , V_760 = 0 , V_125 = 0 ;
if ( F_145 ( V_111 ) ) {
F_123 ( V_5 ) ;
F_340 ( V_5 ) ;
V_125 = 1 ;
}
F_240 ( V_5 , V_125 ) ;
F_430 ( V_5 , V_321 , 1 ) ;
V_75 = F_158 ( V_5 ) ;
F_183 ( V_5 , V_654 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_183 ( V_5 , V_655 ) ;
if ( ! V_75 )
F_159 ( V_5 ) ;
if ( V_5 -> V_178 & V_306 )
F_144 ( V_5 ) ;
if ( F_561 ( V_5 ) != 0 ) {
V_2165 -> V_10 |= V_2168 ;
V_72 [ V_2172 ] = 1 ;
}
if ( F_569 ( V_5 ) != 0 ) {
V_2165 -> V_10 |= V_2168 ;
V_72 [ V_2173 ] = 1 ;
}
if ( V_2166 )
V_2165 -> V_10 |= V_2174 ;
if ( F_572 ( V_5 , V_72 , V_2166 ) )
V_2165 -> V_10 |= V_2168 ;
F_241 ( V_5 ) ;
if ( F_484 ( V_5 ) != 0 ) {
V_2165 -> V_10 |= V_2168 ;
V_72 [ V_2175 ] = 1 ;
}
F_240 ( V_5 , 0 ) ;
F_430 ( V_5 , V_110 , 1 ) ;
if ( F_145 ( V_111 ) ) {
F_84 ( V_5 , V_563 ) ;
V_760 = F_479 ( V_5 , true ) ;
if ( ! V_760 )
F_342 ( V_5 ) ;
}
F_241 ( V_5 ) ;
if ( V_125 && ! V_760 )
F_120 ( V_5 ) ;
}
if ( V_5 -> V_178 & V_400 )
F_198 ( V_5 ) ;
}
static int F_574 ( struct V_365 * V_111 ,
struct V_2176 * V_2177 , int V_643 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_2178 V_2179 ;
if ( ! F_23 ( V_5 , V_990 ) )
return - V_64 ;
if ( F_575 ( & V_2179 , V_2177 -> V_2180 , sizeof( V_2179 ) ) )
return - V_2181 ;
if ( V_2179 . V_10 )
return - V_64 ;
if ( V_2179 . V_2182 != V_998 &&
V_2179 . V_2182 != V_997 )
return - V_2183 ;
switch ( V_2179 . V_2184 ) {
case V_1000 :
V_5 -> V_1580 = 0 ;
break;
case V_1001 :
V_5 -> V_1580 = V_2185 |
V_2186 ;
break;
case V_2187 :
V_5 -> V_1580 = V_2185 |
V_2188 ;
break;
case V_2189 :
V_5 -> V_1580 = V_2185 |
V_2190 ;
break;
case V_2191 :
V_5 -> V_1580 = V_2192 |
V_2193 ;
break;
case V_1002 :
V_5 -> V_1580 = V_2194 |
V_2193 ;
break;
case V_1003 :
V_5 -> V_1580 = V_2195 |
V_2193 ;
break;
case V_2196 :
V_5 -> V_1580 = V_2192 |
V_2188 ;
break;
case V_2197 :
V_5 -> V_1580 = V_2194 |
V_2188 ;
break;
case V_2198 :
V_5 -> V_1580 = V_2195 |
V_2188 ;
break;
case V_2199 :
V_5 -> V_1580 = V_2192 |
V_2190 ;
break;
case V_2200 :
V_5 -> V_1580 = V_2194 |
V_2190 ;
break;
case V_2201 :
V_5 -> V_1580 = V_2195 |
V_2190 ;
break;
default:
return - V_2183 ;
}
if ( F_145 ( V_111 ) && V_5 -> V_1580 )
F_46 ( V_1581 ,
V_5 -> V_1580 | V_1582 ) ;
if ( V_2179 . V_2182 == V_998 )
F_84 ( V_5 , V_1310 ) ;
else
F_86 ( V_5 , V_1310 ) ;
return F_576 ( V_2177 -> V_2180 , & V_2179 , sizeof( V_2179 ) ) ?
- V_2181 : 0 ;
}
static int F_577 ( struct V_365 * V_111 , struct V_2176 * V_2177 , int V_643 )
{
struct V_2202 * V_72 = F_578 ( V_2177 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 ;
if ( F_23 ( V_5 , V_267 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_392 ) )
return - V_85 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
return F_579 ( V_212 , V_2177 , V_643 ) ;
}
switch ( V_643 ) {
case V_2203 :
V_72 -> V_216 = V_5 -> V_160 ;
case V_2204 : {
T_1 V_2205 ;
if ( V_5 -> V_178 & V_568 )
break;
if ( ! F_145 ( V_111 ) )
return - V_85 ;
F_70 ( & V_5 -> V_209 ) ;
V_75 = F_56 ( V_5 , V_72 -> V_216 & 0x1f ,
V_72 -> V_2206 & 0x1f , & V_2205 ) ;
F_71 ( & V_5 -> V_209 ) ;
V_72 -> V_2207 = V_2205 ;
return V_75 ;
}
case V_2208 :
if ( V_5 -> V_178 & V_568 )
break;
if ( ! F_145 ( V_111 ) )
return - V_85 ;
F_70 ( & V_5 -> V_209 ) ;
V_75 = F_58 ( V_5 , V_72 -> V_216 & 0x1f ,
V_72 -> V_2206 & 0x1f , V_72 -> V_2209 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_75 ;
case V_2210 :
return F_574 ( V_111 , V_2177 , V_643 ) ;
default:
break;
}
return - V_1039 ;
}
static int F_580 ( struct V_365 * V_111 , struct V_1457 * V_1458 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
memcpy ( V_1458 , & V_5 -> V_970 , sizeof( * V_1458 ) ) ;
return 0 ;
}
static int F_581 ( struct V_365 * V_111 , struct V_1457 * V_1458 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_2211 = 0 , V_2212 = 0 ;
T_1 V_2213 = 0 , V_2214 = 0 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
V_2211 = V_2215 ;
V_2212 = V_2216 ;
V_2213 = V_2217 ;
V_2214 = V_2218 ;
}
if ( ( V_1458 -> V_1469 > V_2219 ) ||
( V_1458 -> V_1460 > V_2220 ) ||
( V_1458 -> V_1471 > V_2221 ) ||
( V_1458 -> V_1462 > V_2222 ) ||
( V_1458 -> V_1477 > V_2211 ) ||
( V_1458 -> V_1479 > V_2212 ) ||
( V_1458 -> V_1473 > V_2223 ) ||
( V_1458 -> V_1464 > V_2224 ) ||
( V_1458 -> V_971 > V_2213 ) ||
( V_1458 -> V_971 < V_2214 ) )
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
if ( F_145 ( V_111 ) ) {
F_240 ( V_5 , 0 ) ;
F_438 ( V_5 , & V_5 -> V_970 ) ;
F_241 ( V_5 ) ;
}
return 0 ;
}
static int F_582 ( struct V_365 * V_111 , struct V_452 * V_2225 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_339 ) ) {
F_143 ( V_5 -> V_111 , L_75 ) ;
return - V_1039 ;
}
if ( V_2225 -> V_464 != V_5 -> V_453 . V_464 ) {
F_143 ( V_5 -> V_111 ,
L_76 ) ;
return - V_64 ;
}
if ( V_2225 -> V_468 > V_2226 ) {
F_143 ( V_5 -> V_111 ,
L_77 ,
V_2226 ) ;
return - V_64 ;
}
V_5 -> V_453 = * V_2225 ;
V_5 -> V_178 |= V_1533 ;
F_142 ( V_5 ) ;
if ( F_145 ( V_5 -> V_111 ) ) {
F_240 ( V_5 , 0 ) ;
F_221 ( V_5 ) ;
F_144 ( V_5 ) ;
F_241 ( V_5 ) ;
}
return 0 ;
}
static int F_583 ( struct V_365 * V_111 , struct V_452 * V_2225 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_339 ) ) {
F_143 ( V_5 -> V_111 ,
L_75 ) ;
return - V_1039 ;
}
* V_2225 = V_5 -> V_453 ;
return 0 ;
}
static struct V_1953 * F_584 ( struct V_365 * V_111 ,
struct V_1953 * V_1954 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_70 ( & V_5 -> V_209 ) ;
if ( ! V_5 -> V_1351 ) {
F_71 ( & V_5 -> V_209 ) ;
return & V_5 -> V_1437 ;
}
F_431 ( V_5 , V_1954 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_1954 ;
}
static void F_585 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_145 ( V_111 ) )
return;
F_240 ( V_5 , 0 ) ;
F_448 ( V_111 ) ;
F_241 ( V_5 ) ;
}
static inline void F_586 ( struct V_365 * V_111 , struct V_4 * V_5 ,
int V_2227 )
{
V_111 -> V_1201 = V_2227 ;
if ( V_2227 > V_1328 ) {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_587 ( V_111 ) ;
F_86 ( V_5 , V_1593 ) ;
} else {
F_84 ( V_5 , V_1340 ) ;
}
} else {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_84 ( V_5 , V_1593 ) ;
F_587 ( V_111 ) ;
}
F_86 ( V_5 , V_1340 ) ;
}
}
static int F_588 ( struct V_365 * V_111 , int V_2227 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 ;
bool V_1531 = false ;
if ( V_2227 < V_2228 || V_2227 > F_459 ( V_5 ) )
return - V_64 ;
if ( ! F_145 ( V_111 ) ) {
F_586 ( V_111 , V_5 , V_2227 ) ;
return 0 ;
}
F_123 ( V_5 ) ;
F_340 ( V_5 ) ;
F_240 ( V_5 , 1 ) ;
F_430 ( V_5 , V_110 , 1 ) ;
F_586 ( V_111 , V_5 , V_2227 ) ;
if ( F_30 ( V_5 ) == V_668 )
V_1531 = true ;
V_75 = F_479 ( V_5 , V_1531 ) ;
if ( ! V_75 )
F_342 ( V_5 ) ;
F_241 ( V_5 ) ;
if ( ! V_75 )
F_120 ( V_5 ) ;
return V_75 ;
}
static void F_589 ( struct V_4 * V_5 )
{
T_1 V_2229 , V_7 , V_1978 ;
V_5 -> V_1972 = V_2230 ;
if ( F_168 ( V_5 , 0 , & V_1978 ) != 0 )
return;
if ( ( V_1978 != V_1979 ) &&
( ( V_1978 & V_2080 ) != V_2081 ) &&
( ( V_1978 & V_2097 ) != V_2098 ) )
return;
V_2229 = 0x10 ;
while ( V_2229 < V_5 -> V_1972 ) {
if ( F_168 ( V_5 , V_2229 , & V_7 ) != 0 )
return;
if ( V_7 == V_1978 )
break;
V_2229 <<= 1 ;
}
V_5 -> V_1972 = V_2229 ;
}
static void F_590 ( struct V_4 * V_5 )
{
T_1 V_7 ;
if ( F_23 ( V_5 , V_682 ) || F_168 ( V_5 , 0 , & V_7 ) != 0 )
return;
if ( V_7 != V_1979 ) {
F_589 ( V_5 ) ;
return;
}
if ( F_168 ( V_5 , 0xf0 , & V_7 ) == 0 ) {
if ( V_7 != 0 ) {
V_5 -> V_1972 = F_591 ( ( T_3 ) ( V_7 & 0x0000ffff ) ) * 1024 ;
return;
}
}
V_5 -> V_1972 = V_2231 ;
}
static void F_592 ( struct V_4 * V_5 )
{
T_1 V_2232 ;
V_2232 = F_33 ( V_2233 ) ;
if ( V_2232 & V_2234 ) {
F_84 ( V_5 , V_612 ) ;
} else {
V_2232 &= ~ V_2235 ;
F_46 ( V_2233 , V_2232 ) ;
}
if ( F_30 ( V_5 ) == V_1498 ||
F_23 ( V_5 , 5780_CLASS ) ) {
switch ( V_2232 & V_2236 ) {
case V_2237 :
V_5 -> V_614 = V_615 ;
V_5 -> V_616 = V_2238 ;
F_84 ( V_5 , V_611 ) ;
break;
case V_2239 :
V_5 -> V_614 = V_615 ;
V_5 -> V_616 = V_2240 ;
break;
case V_2241 :
V_5 -> V_614 = V_615 ;
V_5 -> V_616 = V_2242 ;
F_84 ( V_5 , V_611 ) ;
break;
case V_2243 :
V_5 -> V_614 = V_642 ;
V_5 -> V_616 = V_2244 ;
F_84 ( V_5 , V_611 ) ;
break;
case V_2245 :
V_5 -> V_614 = V_2246 ;
V_5 -> V_616 = V_2247 ;
break;
case V_2248 :
case V_2249 :
V_5 -> V_614 = V_2250 ;
V_5 -> V_616 = V_2251 ;
break;
}
} else {
V_5 -> V_614 = V_615 ;
V_5 -> V_616 = V_2238 ;
F_84 ( V_5 , V_611 ) ;
}
}
static void F_593 ( struct V_4 * V_5 , T_1 V_2252 )
{
switch ( V_2252 & V_2253 ) {
case V_2254 :
V_5 -> V_616 = 256 ;
break;
case V_2255 :
V_5 -> V_616 = 512 ;
break;
case V_2256 :
V_5 -> V_616 = 1024 ;
break;
case V_2257 :
V_5 -> V_616 = 2048 ;
break;
case V_2258 :
V_5 -> V_616 = 4096 ;
break;
case V_2259 :
V_5 -> V_616 = 264 ;
break;
case V_2260 :
V_5 -> V_616 = 528 ;
break;
}
}
static void F_594 ( struct V_4 * V_5 )
{
T_1 V_2232 ;
V_2232 = F_33 ( V_2233 ) ;
if ( V_2232 & ( 1 << 27 ) )
F_84 ( V_5 , V_592 ) ;
switch ( V_2232 & V_2261 ) {
case V_2262 :
case V_2263 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
break;
case V_2264 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
break;
case V_2265 :
case V_2266 :
case V_2267 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
break;
}
if ( F_23 ( V_5 , V_612 ) ) {
F_593 ( V_5 , V_2232 ) ;
} else {
V_5 -> V_616 = V_2242 ;
V_2232 &= ~ V_2235 ;
F_46 ( V_2233 , V_2232 ) ;
}
}
static void F_595 ( struct V_4 * V_5 )
{
T_1 V_2232 , V_2268 = 0 ;
V_2232 = F_33 ( V_2233 ) ;
if ( V_2232 & ( 1 << 27 ) ) {
F_84 ( V_5 , V_592 ) ;
V_2268 = 1 ;
}
V_2232 &= V_2261 ;
switch ( V_2232 ) {
case V_2269 :
case V_2270 :
case V_2271 :
case V_2272 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 264 ;
if ( V_2232 == V_2269 ||
V_2232 == V_2272 )
V_5 -> V_1972 = ( V_2268 ? 0x3e200 :
V_2231 ) ;
else if ( V_2232 == V_2270 )
V_5 -> V_1972 = ( V_2268 ? 0x1f200 :
V_2273 ) ;
else
V_5 -> V_1972 = ( V_2268 ? 0x1f200 :
V_2274 ) ;
break;
case V_2265 :
case V_2266 :
case V_2267 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 256 ;
if ( V_2232 == V_2265 )
V_5 -> V_1972 = ( V_2268 ?
V_2275 :
V_2274 ) ;
else if ( V_2232 == V_2266 )
V_5 -> V_1972 = ( V_2268 ?
V_2275 :
V_2273 ) ;
else
V_5 -> V_1972 = ( V_2268 ?
V_2274 :
V_2231 ) ;
break;
}
}
static void F_596 ( struct V_4 * V_5 )
{
T_1 V_2232 ;
V_2232 = F_33 ( V_2233 ) ;
switch ( V_2232 & V_2261 ) {
case V_2276 :
case V_2277 :
case V_2278 :
case V_2279 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_5 -> V_616 = V_2242 ;
V_2232 &= ~ V_2235 ;
F_46 ( V_2233 , V_2232 ) ;
break;
case V_2264 :
case V_2269 :
case V_2270 :
case V_2271 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 264 ;
break;
case V_2265 :
case V_2266 :
case V_2267 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 256 ;
break;
}
}
static void F_597 ( struct V_4 * V_5 )
{
T_1 V_2232 , V_2268 = 0 ;
V_2232 = F_33 ( V_2233 ) ;
if ( V_2232 & ( 1 << 27 ) ) {
F_84 ( V_5 , V_592 ) ;
V_2268 = 1 ;
}
V_2232 &= V_2261 ;
switch ( V_2232 ) {
case V_2280 :
case V_2281 :
case V_2282 :
case V_2283 :
case V_2284 :
case V_2285 :
case V_2286 :
case V_2287 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
F_84 ( V_5 , V_613 ) ;
V_5 -> V_616 = 256 ;
break;
case V_2288 :
case V_2289 :
case V_2290 :
case V_2291 :
case V_2292 :
case V_2293 :
case V_2294 :
case V_2295 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 256 ;
break;
}
if ( V_2268 ) {
V_5 -> V_1972 = F_33 ( V_2296 ) ;
} else {
switch ( V_2232 ) {
case V_2283 :
case V_2287 :
case V_2291 :
case V_2295 :
V_5 -> V_1972 = V_2297 ;
break;
case V_2282 :
case V_2286 :
case V_2290 :
case V_2294 :
V_5 -> V_1972 = V_2298 ;
break;
case V_2281 :
case V_2285 :
case V_2289 :
case V_2293 :
V_5 -> V_1972 = V_2231 ;
break;
case V_2280 :
case V_2284 :
case V_2288 :
case V_2292 :
V_5 -> V_1972 = V_2273 ;
break;
}
}
}
static void F_598 ( struct V_4 * V_5 )
{
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_5 -> V_616 = V_2242 ;
}
static void F_599 ( struct V_4 * V_5 )
{
T_1 V_2232 ;
V_2232 = F_33 ( V_2233 ) ;
switch ( V_2232 & V_2261 ) {
case V_2277 :
case V_2279 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_5 -> V_616 = V_2242 ;
V_2232 &= ~ V_2235 ;
F_46 ( V_2233 , V_2232 ) ;
return;
case V_2264 :
case V_2299 :
case V_2300 :
case V_2301 :
case V_2302 :
case V_2303 :
case V_2304 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2232 & V_2261 ) {
case V_2264 :
case V_2299 :
case V_2300 :
V_5 -> V_1972 = V_2274 ;
break;
case V_2301 :
case V_2302 :
V_5 -> V_1972 = V_2273 ;
break;
case V_2303 :
case V_2304 :
V_5 -> V_1972 = V_2231 ;
break;
}
break;
case V_2265 :
case V_2266 :
case V_2267 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2232 & V_2261 ) {
case V_2265 :
V_5 -> V_1972 = V_2274 ;
break;
case V_2266 :
V_5 -> V_1972 = V_2273 ;
break;
case V_2267 :
V_5 -> V_1972 = V_2231 ;
break;
}
break;
default:
F_84 ( V_5 , V_682 ) ;
return;
}
F_593 ( V_5 , V_2232 ) ;
if ( V_5 -> V_616 != 264 && V_5 -> V_616 != 528 )
F_84 ( V_5 , V_613 ) ;
}
static void F_600 ( struct V_4 * V_5 )
{
T_1 V_2232 ;
V_2232 = F_33 ( V_2233 ) ;
switch ( V_2232 & V_2261 ) {
case V_2305 :
case V_2306 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_5 -> V_616 = V_2242 ;
V_2232 &= ~ V_2235 ;
F_46 ( V_2233 , V_2232 ) ;
return;
case V_2307 :
case V_2308 :
case V_2309 :
case V_2310 :
case V_2311 :
case V_2312 :
case V_2313 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2232 & V_2261 ) {
case V_2310 :
break;
case V_2311 :
case V_2312 :
V_5 -> V_1972 = V_2273 ;
break;
default:
V_5 -> V_1972 = V_2274 ;
break;
}
break;
case V_2314 :
case V_2315 :
case V_2316 :
case V_2317 :
case V_2318 :
case V_2319 :
case V_2320 :
case V_2321 :
case V_2322 :
case V_2323 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2232 & V_2261 ) {
case V_2318 :
case V_2320 :
break;
case V_2319 :
case V_2321 :
V_5 -> V_1972 = V_2273 ;
break;
default:
V_5 -> V_1972 = V_2274 ;
break;
}
break;
default:
F_84 ( V_5 , V_682 ) ;
return;
}
F_593 ( V_5 , V_2232 ) ;
if ( V_5 -> V_616 != 264 && V_5 -> V_616 != 528 )
F_84 ( V_5 , V_613 ) ;
}
static void F_601 ( struct V_4 * V_5 )
{
T_1 V_2232 , V_2324 ;
V_2232 = F_33 ( V_2233 ) ;
V_2324 = V_2232 & V_2261 ;
if ( F_30 ( V_5 ) == V_766 ) {
if ( ! ( V_2232 & V_2325 ) ) {
F_84 ( V_5 , V_682 ) ;
return;
}
switch ( V_2324 ) {
case V_2326 :
V_2324 = V_2327 ;
break;
case V_2328 :
V_2324 = V_2329 ;
break;
case V_2330 :
V_2324 = V_2331 ;
break;
}
}
switch ( V_2324 ) {
case V_2327 :
case V_2329 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_2232 &= ~ V_2235 ;
F_46 ( V_2233 , V_2232 ) ;
if ( V_2324 == V_2327 )
V_5 -> V_616 = V_2242 ;
else
V_5 -> V_616 = V_2332 ;
return;
case V_2333 :
case V_2334 :
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
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2324 ) {
case V_2336 :
case V_2337 :
case V_2338 :
V_5 -> V_1972 = V_2273 ;
break;
case V_2339 :
case V_2340 :
case V_2341 :
V_5 -> V_1972 = V_2231 ;
break;
case V_2342 :
case V_2343 :
V_5 -> V_1972 = V_2298 ;
break;
default:
if ( F_30 ( V_5 ) != V_766 )
V_5 -> V_1972 = V_2274 ;
break;
}
break;
case V_2345 :
case V_2346 :
case V_2347 :
case V_2348 :
case V_2349 :
case V_2330 :
case V_2350 :
case V_2351 :
case V_2352 :
case V_2353 :
case V_2354 :
case V_2355 :
case V_2356 :
case V_2357 :
case V_2358 :
case V_2359 :
case V_2360 :
case V_2331 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2324 ) {
case V_2349 :
case V_2330 :
case V_2350 :
case V_2351 :
V_5 -> V_1972 = V_2273 ;
break;
case V_2352 :
case V_2353 :
case V_2354 :
case V_2355 :
V_5 -> V_1972 = V_2231 ;
break;
case V_2356 :
case V_2357 :
case V_2358 :
case V_2359 :
V_5 -> V_1972 = V_2298 ;
break;
default:
if ( F_30 ( V_5 ) != V_766 )
V_5 -> V_1972 = V_2274 ;
break;
}
break;
default:
F_84 ( V_5 , V_682 ) ;
return;
}
F_593 ( V_5 , V_2232 ) ;
if ( V_5 -> V_616 != 264 && V_5 -> V_616 != 528 )
F_84 ( V_5 , V_613 ) ;
if ( F_30 ( V_5 ) == V_766 ) {
T_1 V_7 ;
if ( F_168 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 != V_1979 &&
( V_7 & V_2080 ) != V_2081 )
F_84 ( V_5 , V_682 ) ;
}
}
static void F_602 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_264 ) ) {
F_86 ( V_5 , V_586 ) ;
F_86 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_682 ) ;
return;
}
F_31 ( V_599 ,
( V_2361 |
( V_2362 <<
V_2363 ) ) ) ;
F_163 ( 1 ) ;
F_31 ( V_136 ,
F_33 ( V_136 ) | V_2364 ) ;
F_24 ( 100 ) ;
if ( F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_538 ) {
F_84 ( V_5 , V_586 ) ;
if ( F_158 ( V_5 ) ) {
F_143 ( V_5 -> V_111 ,
L_78 ,
V_658 ) ;
return;
}
F_160 ( V_5 ) ;
V_5 -> V_1972 = 0 ;
if ( F_30 ( V_5 ) == V_641 )
F_594 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1487 )
F_595 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1500 ||
F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_257 )
F_596 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_45 )
F_597 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_36 )
F_598 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1402 ||
F_23 ( V_5 , 57765_CLASS ) )
F_599 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 )
F_600 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_766 )
F_601 ( V_5 ) ;
else
F_592 ( V_5 ) ;
if ( V_5 -> V_1972 == 0 )
F_590 ( V_5 ) ;
F_161 ( V_5 ) ;
F_159 ( V_5 ) ;
} else {
F_86 ( V_5 , V_586 ) ;
F_86 ( V_5 , V_611 ) ;
F_589 ( V_5 ) ;
}
}
static struct V_2365 * F_603 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_568 ( V_2366 ) ; V_42 ++ ) {
if ( ( V_2366 [ V_42 ] . V_2367 ==
V_5 -> V_12 -> V_2368 ) &&
( V_2366 [ V_42 ] . V_2369 ==
V_5 -> V_12 -> V_2370 ) )
return & V_2366 [ V_42 ] ;
}
return NULL ;
}
static void F_604 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_5 -> V_216 = V_2371 ;
V_5 -> V_564 = V_819 ;
F_84 ( V_5 , V_644 ) ;
F_84 ( V_5 , V_716 ) ;
if ( F_30 ( V_5 ) == V_36 ) {
if ( ! ( F_33 ( V_1906 ) & V_2372 ) ) {
F_86 ( V_5 , V_644 ) ;
F_84 ( V_5 , V_533 ) ;
}
V_7 = F_33 ( V_2373 ) ;
if ( V_7 & V_2374 )
F_84 ( V_5 , V_972 ) ;
if ( ( V_7 & V_2375 ) &&
( V_7 & V_2376 ) ) {
F_84 ( V_5 , V_112 ) ;
F_531 ( & V_5 -> V_12 -> V_111 , true ) ;
}
goto V_186;
}
F_32 ( V_5 , V_1429 , & V_7 ) ;
if ( V_7 == V_1430 ) {
T_1 V_1431 , V_2377 ;
T_1 V_2378 , V_2379 , V_2380 = 0 , V_2381 = 0 , V_2382 ;
int V_2383 = 0 ;
F_32 ( V_5 , V_1432 , & V_1431 ) ;
V_5 -> V_551 = V_1431 ;
F_32 ( V_5 , V_2384 , & V_2379 ) ;
V_2379 >>= V_2385 ;
if ( F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_538 &&
F_30 ( V_5 ) != V_500 &&
( V_2379 > 0 ) && ( V_2379 < 0x100 ) )
F_32 ( V_5 , V_2386 , & V_2380 ) ;
if ( F_30 ( V_5 ) == V_257 )
F_32 ( V_5 , V_2387 , & V_2381 ) ;
if ( ( V_1431 & V_2388 ) ==
V_2389 )
V_2383 = 1 ;
F_32 ( V_5 , V_2390 , & V_2378 ) ;
if ( V_2378 != 0 ) {
T_1 V_2391 = V_2378 & V_2392 ;
T_1 V_2393 = V_2378 & V_2394 ;
V_2382 = ( V_2391 >> 16 ) << 10 ;
V_2382 |= ( V_2393 & 0xfc00 ) << 16 ;
V_2382 |= ( V_2393 & 0x03ff ) << 0 ;
} else
V_2382 = 0 ;
V_5 -> V_216 = V_2382 ;
if ( V_2383 ) {
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_178 |= V_568 ;
else
V_5 -> V_178 |= V_306 ;
}
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2377 = V_2380 & ( V_2395 |
V_2396 ) ;
else
V_2377 = V_1431 & V_2395 ;
switch ( V_2377 ) {
default:
case V_2397 :
V_5 -> V_564 = V_819 ;
break;
case V_2398 :
V_5 -> V_564 = V_565 ;
break;
case V_2399 :
V_5 -> V_564 = V_2400 ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 )
V_5 -> V_564 = V_819 ;
break;
case V_2401 :
V_5 -> V_564 = V_2402 ;
if ( F_77 ( V_5 ) != V_1410 &&
F_77 ( V_5 ) != V_2403 )
V_5 -> V_564 |= ( V_819 |
V_565 ) ;
if ( F_23 ( V_5 , 5717_PLUS ) ||
F_30 ( V_5 ) == V_766 )
V_5 -> V_564 |= V_2404 |
V_2405 ;
break;
case V_2406 :
V_5 -> V_564 = V_2407 ;
break;
case V_2408 :
V_5 -> V_564 = V_2409 ;
if ( F_77 ( V_5 ) != V_1410 )
V_5 -> V_564 |= ( V_819 |
V_565 ) ;
break;
}
if ( ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) &&
V_5 -> V_12 -> V_2368 == V_2410 )
V_5 -> V_564 = V_565 ;
if ( F_146 ( V_5 ) == V_504 )
V_5 -> V_564 = V_819 ;
if ( V_1431 & V_2411 ) {
F_84 ( V_5 , V_644 ) ;
if ( ( V_5 -> V_12 -> V_2368 ==
V_2412 ) &&
( V_5 -> V_12 -> V_2370 == 0x205a ||
V_5 -> V_12 -> V_2370 == 0x2063 ) )
F_86 ( V_5 , V_644 ) ;
} else {
F_86 ( V_5 , V_644 ) ;
F_84 ( V_5 , V_533 ) ;
}
if ( V_1431 & V_1433 ) {
F_84 ( V_5 , V_309 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , V_317 ) ;
}
if ( ( V_1431 & V_2413 ) &&
F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , V_60 ) ;
if ( V_5 -> V_178 & V_360 &&
! ( V_1431 & V_2414 ) )
F_86 ( V_5 , V_716 ) ;
if ( F_23 ( V_5 , V_716 ) &&
( V_1431 & V_2415 ) ) {
F_84 ( V_5 , V_112 ) ;
F_531 ( & V_5 -> V_12 -> V_111 , true ) ;
}
if ( V_2380 & ( 1 << 17 ) )
V_5 -> V_178 |= V_822 ;
if ( V_2380 & ( 1 << 18 ) )
V_5 -> V_178 |= V_1738 ;
if ( ( F_23 ( V_5 , 57765_PLUS ) ||
( F_30 ( V_5 ) == V_414 &&
F_146 ( V_5 ) != V_504 ) ) &&
( V_2380 & V_2416 ) )
V_5 -> V_178 |= V_514 ;
if ( F_23 ( V_5 , V_1081 ) ) {
T_1 V_2417 ;
F_32 ( V_5 , V_1434 , & V_2417 ) ;
if ( F_30 ( V_5 ) != V_257 &&
! F_23 ( V_5 , 57765_PLUS ) &&
( V_2417 & V_2418 ) )
F_84 ( V_5 , V_972 ) ;
if ( V_2417 & V_1436 )
V_5 -> V_178 |= V_570 ;
if ( V_2417 & V_1435 )
V_5 -> V_178 |= V_770 ;
}
if ( V_2381 & V_2419 )
F_84 ( V_5 , V_236 ) ;
if ( V_2381 & V_2420 )
F_84 ( V_5 , V_245 ) ;
if ( V_2381 & V_2421 )
F_84 ( V_5 , V_246 ) ;
}
V_186:
if ( F_23 ( V_5 , V_716 ) )
F_531 ( & V_5 -> V_12 -> V_111 ,
F_23 ( V_5 , V_112 ) ) ;
else
F_605 ( & V_5 -> V_12 -> V_111 , false ) ;
}
static int F_606 ( struct V_4 * V_5 , T_1 V_596 , T_1 * V_7 )
{
int V_42 , V_75 ;
T_1 V_2422 , V_6 = V_596 * 8 ;
V_75 = F_158 ( V_5 ) ;
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
F_159 ( V_5 ) ;
if ( V_2422 & V_2430 )
return 0 ;
return - V_67 ;
}
static int F_607 ( struct V_4 * V_5 , T_1 V_643 )
{
int V_42 ;
T_1 V_7 ;
F_46 ( V_2432 , V_643 | V_2433 ) ;
F_46 ( V_2432 , V_643 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_7 = F_33 ( V_2434 ) ;
if ( V_7 & V_2435 )
break;
F_24 ( 10 ) ;
}
return ( V_7 & V_2435 ) ? 0 : - V_67 ;
}
static T_1 F_608 ( struct V_4 * V_5 )
{
T_1 V_2436 , V_2437 ;
F_46 ( V_2438 , V_2439 ) ;
if ( F_607 ( V_5 , V_2440 ) )
return 0 ;
F_46 ( V_2441 , V_2442 ) ;
if ( F_607 ( V_5 , V_2443 ) )
return 0 ;
V_2437 = F_33 ( V_2444 ) ;
F_46 ( V_2441 , V_2445 ) ;
if ( F_607 ( V_5 , V_2443 ) )
return 0 ;
V_2436 = F_33 ( V_2444 ) ;
return ( ( V_2437 & 0x0000ffff ) << 16 ) | ( V_2436 >> 16 ) ;
}
static void F_609 ( struct V_4 * V_5 )
{
T_1 V_342 = V_704 ;
if ( ! ( V_5 -> V_178 & V_393 ) )
V_342 |= V_771 |
V_762 ;
if ( ! ( V_5 -> V_178 & V_360 ) )
V_342 |= V_707 |
V_708 |
V_705 |
V_709 |
V_702 ;
else
V_342 |= V_778 ;
V_5 -> V_330 . V_399 = V_342 ;
V_5 -> V_330 . V_373 = V_752 ;
V_5 -> V_330 . V_377 = V_753 ;
V_5 -> V_330 . V_353 = V_358 ;
V_5 -> V_330 . V_331 = V_752 ;
V_5 -> V_330 . V_334 = V_753 ;
V_5 -> V_391 = - 1 ;
}
static int F_610 ( struct V_4 * V_5 )
{
T_1 V_2446 , V_2447 ;
T_1 V_2448 , V_2449 ;
int V_75 ;
F_84 ( V_5 , V_359 ) ;
V_5 -> V_330 . V_343 = V_337 | V_338 ;
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
if ( ! F_23 ( V_5 , V_309 ) &&
! ( V_5 -> V_178 & V_360 ) &&
! ( V_5 -> V_178 & V_393 ) )
V_5 -> V_178 &= ~ ( V_770 |
V_570 ) ;
if ( F_23 ( V_5 , V_267 ) )
return F_113 ( V_5 ) ;
V_75 = 0 ;
if ( F_23 ( V_5 , V_309 ) || F_23 ( V_5 , V_60 ) ) {
V_2448 = V_2449 = V_2371 ;
} else {
V_75 |= F_57 ( V_5 , V_2450 , & V_2446 ) ;
V_75 |= F_57 ( V_5 , V_2451 , & V_2447 ) ;
V_2448 = ( V_2446 & 0xffff ) << 10 ;
V_2448 |= ( V_2447 & 0xfc00 ) << 16 ;
V_2448 |= ( V_2447 & 0x03ff ) << 0 ;
V_2449 = V_2448 & V_401 ;
}
if ( ! V_75 && F_611 ( V_2449 ) ) {
V_5 -> V_216 = V_2448 ;
if ( V_2449 == V_939 )
V_5 -> V_178 |= V_568 ;
else
V_5 -> V_178 &= ~ V_568 ;
} else {
if ( V_5 -> V_216 != V_2371 ) {
} else {
struct V_2365 * V_1439 ;
V_1439 = F_603 ( V_5 ) ;
if ( V_1439 ) {
V_5 -> V_216 = V_1439 -> V_216 ;
} else if ( ! F_23 ( V_5 , V_264 ) ) {
return - V_82 ;
}
if ( ! V_5 -> V_216 ||
V_5 -> V_216 == V_939 )
V_5 -> V_178 |= V_568 ;
}
}
if ( ! ( V_5 -> V_178 & V_360 ) &&
( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_668 ||
F_30 ( V_5 ) == V_766 ||
( F_30 ( V_5 ) == V_477 &&
F_77 ( V_5 ) != V_259 ) ||
( F_30 ( V_5 ) == V_764 &&
F_77 ( V_5 ) != V_328 ) ) ) {
V_5 -> V_178 |= V_339 ;
V_5 -> V_453 . V_394 = V_1987 |
V_1985 ;
V_5 -> V_453 . V_464 = V_708 |
V_762 ;
V_5 -> V_453 . V_463 = 1 ;
V_5 -> V_453 . V_466 = 1 ;
V_5 -> V_453 . V_468 = V_2452 ;
}
F_609 ( V_5 ) ;
if ( ! ( V_5 -> V_178 & V_570 ) &&
! ( V_5 -> V_178 & V_360 ) &&
! F_23 ( V_5 , V_60 ) &&
! F_23 ( V_5 , V_309 ) ) {
T_1 V_810 , V_2453 ;
F_57 ( V_5 , V_303 , & V_810 ) ;
if ( ! F_57 ( V_5 , V_303 , & V_810 ) &&
( V_810 & V_776 ) )
goto V_2454;
V_75 = F_144 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_130 ( V_5 ) ;
if ( ! F_214 ( V_5 , & V_2453 ) ) {
F_204 ( V_5 , V_5 -> V_330 . V_399 ,
V_5 -> V_330 . V_343 ) ;
F_59 ( V_5 , V_204 ,
V_577 | V_578 ) ;
}
}
V_2454:
if ( ( V_5 -> V_216 & V_401 ) == V_402 ) {
V_75 = F_212 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_212 ( V_5 ) ;
}
return V_75 ;
}
static void F_612 ( struct V_4 * V_5 )
{
T_4 * V_2455 ;
unsigned int V_2456 , V_2457 , V_74 ;
T_1 V_2064 ;
int V_628 , V_42 = 0 ;
V_2455 = ( T_4 * ) F_551 ( V_5 , & V_2064 ) ;
if ( ! V_2455 )
goto V_2458;
V_42 = F_556 ( V_2455 , 0 , V_2064 , V_2108 ) ;
if ( V_42 < 0 )
goto V_2459;
V_2457 = F_557 ( & V_2455 [ V_42 ] ) ;
V_2456 = V_42 + V_2109 + V_2457 ;
V_42 += V_2109 ;
if ( V_2456 > V_2064 )
goto V_2459;
V_628 = F_558 ( V_2455 , V_42 , V_2457 ,
V_2460 ) ;
if ( V_628 > 0 ) {
V_74 = F_613 ( & V_2455 [ V_628 ] ) ;
V_628 += V_2111 ;
if ( V_628 + V_74 > V_2456 || V_74 != 4 ||
memcmp ( & V_2455 [ V_628 ] , L_79 , 4 ) )
goto V_2461;
V_628 = F_558 ( V_2455 , V_42 , V_2457 ,
V_2462 ) ;
if ( V_628 < 0 )
goto V_2461;
V_74 = F_613 ( & V_2455 [ V_628 ] ) ;
V_628 += V_2111 ;
if ( V_628 + V_74 > V_2456 )
goto V_2461;
if ( V_74 >= sizeof( V_5 -> V_2012 ) )
V_74 = sizeof( V_5 -> V_2012 ) - 1 ;
memset ( V_5 -> V_2012 , 0 , sizeof( V_5 -> V_2012 ) ) ;
snprintf ( V_5 -> V_2012 , sizeof( V_5 -> V_2012 ) , L_80 , V_74 ,
& V_2455 [ V_628 ] ) ;
}
V_2461:
V_42 = F_558 ( V_2455 , V_42 , V_2457 ,
V_2463 ) ;
if ( V_42 < 0 )
goto V_2459;
V_74 = F_613 ( & V_2455 [ V_42 ] ) ;
V_42 += V_2111 ;
if ( V_74 > V_2464 ||
( V_74 + V_42 ) > V_2064 )
goto V_2459;
memcpy ( V_5 -> V_2465 , & V_2455 [ V_42 ] , V_74 ) ;
V_2459:
F_175 ( V_2455 ) ;
if ( V_5 -> V_2465 [ 0 ] )
return;
V_2458:
if ( F_30 ( V_5 ) == V_477 ) {
if ( V_5 -> V_12 -> V_544 == V_2466 ||
V_5 -> V_12 -> V_544 == V_2467 )
strcpy ( V_5 -> V_2465 , L_81 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2468 )
strcpy ( V_5 -> V_2465 , L_82 ) ;
else
goto V_2469;
} else if ( F_30 ( V_5 ) == V_1402 ) {
if ( V_5 -> V_12 -> V_544 == V_2470 )
strcpy ( V_5 -> V_2465 , L_83 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2471 )
strcpy ( V_5 -> V_2465 , L_84 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2472 )
strcpy ( V_5 -> V_2465 , L_85 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2473 )
strcpy ( V_5 -> V_2465 , L_86 ) ;
else
goto V_2469;
} else if ( F_30 ( V_5 ) == V_764 ) {
if ( V_5 -> V_12 -> V_544 == V_2474 )
strcpy ( V_5 -> V_2465 , L_87 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2475 )
strcpy ( V_5 -> V_2465 , L_88 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2476 )
strcpy ( V_5 -> V_2465 , L_89 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2477 )
strcpy ( V_5 -> V_2465 , L_90 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2478 )
strcpy ( V_5 -> V_2465 , L_91 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2479 )
strcpy ( V_5 -> V_2465 , L_92 ) ;
else
goto V_2469;
} else if ( F_30 ( V_5 ) == V_668 ) {
if ( V_5 -> V_12 -> V_544 == V_2480 )
strcpy ( V_5 -> V_2465 , L_93 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2481 )
strcpy ( V_5 -> V_2465 , L_94 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2482 )
strcpy ( V_5 -> V_2465 , L_95 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2483 )
strcpy ( V_5 -> V_2465 , L_96 ) ;
else
goto V_2469;
} else if ( F_30 ( V_5 ) == V_36 ) {
strcpy ( V_5 -> V_2465 , L_97 ) ;
} else {
V_2469:
strcpy ( V_5 -> V_2465 , L_98 ) ;
}
}
static int F_614 ( struct V_4 * V_5 , T_1 V_596 )
{
T_1 V_7 ;
if ( F_168 ( V_5 , V_596 , & V_7 ) ||
( V_7 & 0xfc000000 ) != 0x0c000000 ||
F_168 ( V_5 , V_596 + 4 , & V_7 ) ||
V_7 != 0 )
return 0 ;
return 1 ;
}
static void F_615 ( struct V_4 * V_5 )
{
T_1 V_7 , V_596 , V_1030 , V_2484 ;
int V_42 , V_2485 ;
bool V_2486 = false ;
if ( F_168 ( V_5 , 0xc , & V_596 ) ||
F_168 ( V_5 , 0x4 , & V_1030 ) )
return;
V_596 = F_167 ( V_5 , V_596 ) ;
if ( F_168 ( V_5 , V_596 , & V_7 ) )
return;
if ( ( V_7 & 0xfc000000 ) == 0x0c000000 ) {
if ( F_168 ( V_5 , V_596 + 4 , & V_7 ) )
return;
if ( V_7 == 0 )
V_2486 = true ;
}
V_2485 = strlen ( V_5 -> V_2012 ) ;
if ( V_2486 ) {
if ( V_2487 - V_2485 < 16 ||
F_168 ( V_5 , V_596 + 8 , & V_2484 ) )
return;
V_596 = V_596 + V_2484 - V_1030 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 += 4 ) {
T_5 V_625 ;
if ( F_169 ( V_5 , V_596 + V_42 , & V_625 ) )
return;
memcpy ( V_5 -> V_2012 + V_2485 + V_42 , & V_625 , sizeof( V_625 ) ) ;
}
} else {
T_1 V_2488 , V_2489 ;
if ( F_168 ( V_5 , V_2490 , & V_2484 ) )
return;
V_2488 = ( V_2484 & V_2491 ) >>
V_2492 ;
V_2489 = V_2484 & V_2493 ;
snprintf ( & V_5 -> V_2012 [ V_2485 ] , V_2487 - V_2485 ,
L_99 , V_2488 , V_2489 ) ;
}
}
static void F_616 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2488 , V_2489 ;
if ( F_168 ( V_5 , V_2494 , & V_7 ) )
return;
V_2488 = ( V_7 & V_2495 ) >>
V_2496 ;
V_2489 = ( V_7 & V_2497 ) >>
V_2498 ;
snprintf ( & V_5 -> V_2012 [ 0 ] , 32 , L_100 , V_2488 , V_2489 ) ;
}
static void F_617 ( struct V_4 * V_5 , T_1 V_7 )
{
T_1 V_596 , V_2488 , V_2489 , V_2499 ;
strncat ( V_5 -> V_2012 , L_101 , V_2487 - strlen ( V_5 -> V_2012 ) - 1 ) ;
if ( ( V_7 & V_2082 ) != V_2083 )
return;
switch ( V_7 & V_2084 ) {
case V_2085 :
V_596 = V_2500 ;
break;
case V_2087 :
V_596 = V_2501 ;
break;
case V_2089 :
V_596 = V_2502 ;
break;
case V_2091 :
V_596 = V_2503 ;
break;
case V_2093 :
V_596 = V_2504 ;
break;
case V_2095 :
V_596 = V_2505 ;
break;
default:
return;
}
if ( F_168 ( V_5 , V_596 , & V_7 ) )
return;
V_2499 = ( V_7 & V_2506 ) >>
V_2507 ;
V_2488 = ( V_7 & V_2508 ) >>
V_2509 ;
V_2489 = V_7 & V_2510 ;
if ( V_2489 > 99 || V_2499 > 26 )
return;
V_596 = strlen ( V_5 -> V_2012 ) ;
snprintf ( & V_5 -> V_2012 [ V_596 ] , V_2487 - V_596 ,
L_102 , V_2488 , V_2489 ) ;
if ( V_2499 > 0 ) {
V_596 = strlen ( V_5 -> V_2012 ) ;
if ( V_596 < V_2487 - 1 )
V_5 -> V_2012 [ V_596 ] = 'a' + V_2499 - 1 ;
}
}
static void F_618 ( struct V_4 * V_5 )
{
T_1 V_7 , V_596 , V_1030 ;
int V_42 , V_2511 ;
for ( V_596 = V_2065 ;
V_596 < V_2066 ;
V_596 += V_2067 ) {
if ( F_168 ( V_5 , V_596 , & V_7 ) )
return;
if ( ( V_7 >> V_2068 ) == V_2512 )
break;
}
if ( V_596 == V_2066 )
return;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_1030 = 0x08000000 ;
else if ( F_168 ( V_5 , V_596 - 4 , & V_1030 ) )
return;
if ( F_168 ( V_5 , V_596 + 4 , & V_596 ) ||
! F_614 ( V_5 , V_596 ) ||
F_168 ( V_5 , V_596 + 8 , & V_7 ) )
return;
V_596 += V_7 - V_1030 ;
V_2511 = strlen ( V_5 -> V_2012 ) ;
V_5 -> V_2012 [ V_2511 ++ ] = ',' ;
V_5 -> V_2012 [ V_2511 ++ ] = ' ' ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
T_5 V_625 ;
if ( F_169 ( V_5 , V_596 , & V_625 ) )
return;
V_596 += sizeof( V_625 ) ;
if ( V_2511 > V_2487 - sizeof( V_625 ) ) {
memcpy ( & V_5 -> V_2012 [ V_2511 ] , & V_625 , V_2487 - V_2511 ) ;
break;
}
memcpy ( & V_5 -> V_2012 [ V_2511 ] , & V_625 , sizeof( V_625 ) ) ;
V_2511 += sizeof( V_625 ) ;
}
}
static void F_619 ( struct V_4 * V_5 )
{
T_1 V_69 ;
V_69 = F_12 ( V_5 , V_80 ) ;
if ( V_69 != V_81 )
return;
V_69 = F_12 ( V_5 , V_83 ) ;
if ( ! ( V_69 & V_84 ) )
return;
if ( F_12 ( V_5 , V_2513 ) & V_2514 )
F_84 ( V_5 , V_79 ) ;
}
static void F_620 ( struct V_4 * V_5 )
{
int V_2511 ;
T_1 V_69 ;
char * V_2515 ;
V_69 = F_12 ( V_5 , V_2516 ) ;
if ( F_23 ( V_5 , V_79 ) )
V_2515 = L_103 ;
else if ( V_5 -> V_12 -> V_544 == V_2517 )
V_2515 = L_104 ;
else
V_2515 = L_105 ;
V_2511 = strlen ( V_5 -> V_2012 ) ;
snprintf ( & V_5 -> V_2012 [ V_2511 ] , V_2487 - V_2511 , L_106 ,
V_2515 ,
( V_69 & V_2518 ) >> V_2519 ,
( V_69 & V_2520 ) >> V_2521 ,
( V_69 & V_2522 ) >> V_2523 ,
( V_69 & V_2524 ) ) ;
}
static void F_621 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2422 ;
if ( F_30 ( V_5 ) != V_766 )
return;
if ( ! F_606 ( V_5 , V_2525 , & V_7 ) &&
! F_606 ( V_5 , V_2525 + 4 , & V_2422 ) &&
F_622 ( V_7 ) ) {
T_6 V_2526 = ( T_6 ) V_7 << 32 | V_2422 ;
T_1 V_2379 = 0 ;
int V_42 , V_2511 ;
for ( V_42 = 0 ; V_42 < 7 ; V_42 ++ ) {
if ( ( V_2526 & 0xff ) == 0 )
break;
V_2379 = V_2526 & 0xff ;
V_2526 >>= 8 ;
}
V_2511 = strlen ( V_5 -> V_2012 ) ;
snprintf ( & V_5 -> V_2012 [ V_2511 ] , V_2487 - V_2511 , L_107 , V_2379 ) ;
}
}
static void F_623 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_2527 = false ;
if ( V_5 -> V_2012 [ 0 ] != 0 )
V_2527 = true ;
if ( F_23 ( V_5 , V_682 ) ) {
strcat ( V_5 -> V_2012 , L_101 ) ;
F_621 ( V_5 ) ;
return;
}
if ( F_168 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 == V_1979 )
F_615 ( V_5 ) ;
else if ( ( V_7 & V_2080 ) == V_2081 )
F_617 ( V_5 , V_7 ) ;
else if ( ( V_7 & V_2097 ) == V_2098 )
F_616 ( V_5 ) ;
if ( F_23 ( V_5 , V_309 ) ) {
if ( F_23 ( V_5 , V_60 ) ) {
F_619 ( V_5 ) ;
if ( ! V_2527 )
F_620 ( V_5 ) ;
} else if ( ! V_2527 ) {
F_618 ( V_5 ) ;
}
}
V_5 -> V_2012 [ V_2487 - 1 ] = 0 ;
}
static inline T_1 F_624 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1712 ) )
return V_2528 ;
else if ( F_23 ( V_5 , V_522 ) && ! F_23 ( V_5 , 5780_CLASS ) )
return V_2529 ;
else
return V_2530 ;
}
static struct V_1792 * F_625 ( struct V_4 * V_5 )
{
struct V_1792 * V_2531 ;
unsigned int V_2532 , V_2533 = V_5 -> V_12 -> V_274 & ~ 7 ;
for ( V_2532 = 0 ; V_2532 < 8 ; V_2532 ++ ) {
V_2531 = F_626 ( V_5 -> V_12 -> V_272 , V_2533 | V_2532 ) ;
if ( V_2531 && V_2531 != V_5 -> V_12 )
break;
F_627 ( V_2531 ) ;
}
if ( ! V_2531 ) {
V_2531 = V_5 -> V_12 ;
return V_2531 ;
}
F_627 ( V_2531 ) ;
return V_2531 ;
}
static void F_628 ( struct V_4 * V_5 , T_1 V_2534 )
{
V_5 -> V_2535 = V_2534 >> V_2536 ;
if ( F_30 ( V_5 ) == V_2537 ) {
T_1 V_161 ;
F_84 ( V_5 , V_152 ) ;
if ( V_5 -> V_12 -> V_544 == V_2466 ||
V_5 -> V_12 -> V_544 == V_2467 ||
V_5 -> V_12 -> V_544 == V_2468 ||
V_5 -> V_12 -> V_544 == V_2538 ||
V_5 -> V_12 -> V_544 == V_2539 ||
V_5 -> V_12 -> V_544 == V_2540 ||
V_5 -> V_12 -> V_544 == V_2541 ||
V_5 -> V_12 -> V_544 == V_2542 ||
V_5 -> V_12 -> V_544 == V_2517 ||
V_5 -> V_12 -> V_544 == V_2543 ||
V_5 -> V_12 -> V_544 == V_2544 )
V_161 = V_2545 ;
else if ( V_5 -> V_12 -> V_544 == V_2476 ||
V_5 -> V_12 -> V_544 == V_2477 ||
V_5 -> V_12 -> V_544 == V_2474 ||
V_5 -> V_12 -> V_544 == V_2475 ||
V_5 -> V_12 -> V_544 == V_2478 ||
V_5 -> V_12 -> V_544 == V_2479 ||
V_5 -> V_12 -> V_544 == V_2480 ||
V_5 -> V_12 -> V_544 == V_2481 ||
V_5 -> V_12 -> V_544 == V_2482 ||
V_5 -> V_12 -> V_544 == V_2483 )
V_161 = V_2546 ;
else
V_161 = V_2547 ;
F_19 ( V_5 -> V_12 , V_161 , & V_5 -> V_2535 ) ;
}
if ( F_77 ( V_5 ) == V_2548 )
V_5 -> V_2535 = V_2549 ;
if ( F_77 ( V_5 ) == V_2550 )
V_5 -> V_2535 = V_1612 ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 )
F_84 ( V_5 , 5717_PLUS ) ;
if ( F_30 ( V_5 ) == V_764 ||
F_30 ( V_5 ) == V_668 )
F_84 ( V_5 , 57765_CLASS ) ;
if ( F_23 ( V_5 , 57765_CLASS ) || F_23 ( V_5 , 5717_PLUS ) ||
F_30 ( V_5 ) == V_766 )
F_84 ( V_5 , 57765_PLUS ) ;
if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_1500 ||
F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1402 ||
F_23 ( V_5 , 57765_PLUS ) )
F_84 ( V_5 , 5755_PLUS ) ;
if ( F_30 ( V_5 ) == V_567 ||
F_30 ( V_5 ) == V_549 )
F_84 ( V_5 , 5780_CLASS ) ;
if ( F_30 ( V_5 ) == V_1498 ||
F_30 ( V_5 ) == V_641 ||
F_30 ( V_5 ) == V_36 ||
F_23 ( V_5 , 5755_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) )
F_84 ( V_5 , 5750_PLUS ) ;
if ( F_30 ( V_5 ) == V_502 ||
F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , 5705_PLUS ) ;
}
static bool F_629 ( struct V_4 * V_5 ,
const struct V_2551 * V_2552 )
{
T_1 V_2553 = F_33 ( V_498 ) & V_2554 ;
if ( ( F_30 ( V_5 ) == V_500 &&
( V_2553 == 0x8000 || V_2553 == 0x4000 ) ) ||
( V_5 -> V_178 & V_179 ) )
return true ;
if ( V_2552 -> V_2555 & V_2556 ) {
if ( F_30 ( V_5 ) == V_502 ) {
if ( V_2552 -> V_2555 & V_2557 )
return true ;
} else {
return true ;
}
}
return false ;
}
static int F_630 ( struct V_4 * V_5 , const struct V_2551 * V_2552 )
{
T_1 V_2534 ;
T_1 V_2558 , V_2553 ;
T_1 V_7 ;
T_3 V_1380 ;
int V_75 ;
F_422 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
V_1380 &= ~ V_2559 ;
F_424 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
F_19 ( V_5 -> V_12 , V_119 ,
& V_2534 ) ;
V_5 -> V_120 |= ( V_2534 &
V_2560 ) ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
F_628 ( V_5 , V_2534 ) ;
if ( ( F_77 ( V_5 ) == V_1739 ) ||
( F_77 ( V_5 ) == V_2561 ) ) {
static struct V_2562 {
T_1 V_2563 ;
T_1 V_544 ;
T_1 V_2564 ;
} V_2565 [] = {
{ V_2566 , V_2567 ,
V_2568 } ,
{ V_2566 , V_2569 ,
V_2568 } ,
{ V_2566 , V_2570 ,
0xa } ,
{ V_2566 , V_2571 ,
V_2568 } ,
{ } ,
} ;
struct V_2562 * V_2572 = & V_2565 [ 0 ] ;
struct V_1792 * V_2573 = NULL ;
while ( V_2572 -> V_2563 != 0 ) {
V_2573 = F_631 ( V_2572 -> V_2563 , V_2572 -> V_544 ,
V_2573 ) ;
if ( ! V_2573 ) {
V_2572 ++ ;
continue;
}
if ( V_2572 -> V_2564 != V_2568 ) {
if ( V_2573 -> V_2574 > V_2572 -> V_2564 )
continue;
}
if ( V_2573 -> V_2575 &&
( V_2573 -> V_2575 -> V_273 ==
V_5 -> V_12 -> V_272 -> V_273 ) ) {
F_84 ( V_5 , V_26 ) ;
F_627 ( V_2573 ) ;
break;
}
}
}
if ( F_30 ( V_5 ) == V_538 ) {
static struct V_2562 {
T_1 V_2563 ;
T_1 V_544 ;
} V_2576 [] = {
{ V_2566 , V_2577 } ,
{ V_2566 , V_2578 } ,
{ } ,
} ;
struct V_2562 * V_2572 = & V_2576 [ 0 ] ;
struct V_1792 * V_2573 = NULL ;
while ( V_2572 -> V_2563 != 0 ) {
V_2573 = F_631 ( V_2572 -> V_2563 ,
V_2572 -> V_544 ,
V_2573 ) ;
if ( ! V_2573 ) {
V_2572 ++ ;
continue;
}
if ( V_2573 -> V_2575 &&
( V_2573 -> V_2575 -> V_273 <=
V_5 -> V_12 -> V_272 -> V_273 ) &&
( V_2573 -> V_2575 -> V_2579 . V_1981 >=
V_5 -> V_12 -> V_272 -> V_273 ) ) {
F_84 ( V_5 , 5701_DMA_BUG ) ;
F_627 ( V_2573 ) ;
break;
}
}
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_84 ( V_5 , 40BIT_DMA_BUG ) ;
V_5 -> V_1397 = V_5 -> V_12 -> V_1397 ;
} else {
struct V_1792 * V_2573 = NULL ;
do {
V_2573 = F_631 ( V_2580 ,
V_2581 ,
V_2573 ) ;
if ( V_2573 && V_2573 -> V_2575 &&
( V_2573 -> V_2575 -> V_273 <=
V_5 -> V_12 -> V_272 -> V_273 ) &&
( V_2573 -> V_2575 -> V_2579 . V_1981 >=
V_5 -> V_12 -> V_272 -> V_273 ) ) {
F_84 ( V_5 , 40BIT_DMA_BUG ) ;
F_627 ( V_2573 ) ;
break;
}
} while ( V_2573 );
}
if ( F_30 ( V_5 ) == V_501 ||
F_30 ( V_5 ) == V_549 )
V_5 -> V_560 = F_625 ( V_5 ) ;
if ( F_77 ( V_5 ) == V_1611 )
;
else if ( F_23 ( V_5 , 57765_PLUS ) )
F_84 ( V_5 , V_1298 ) ;
else if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_84 ( V_5 , V_1297 ) ;
else if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_84 ( V_5 , V_1296 ) ;
F_84 ( V_5 , V_1293 ) ;
if ( F_30 ( V_5 ) == V_1498 &&
F_77 ( V_5 ) >= V_2582 )
F_86 ( V_5 , V_1293 ) ;
} else if ( F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_538 &&
F_77 ( V_5 ) != V_1425 ) {
F_84 ( V_5 , V_684 ) ;
F_84 ( V_5 , V_1293 ) ;
if ( F_30 ( V_5 ) == V_502 )
V_5 -> V_1888 = V_2583 ;
else
V_5 -> V_1888 = V_2584 ;
}
if ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_684 ) ) {
F_84 ( V_5 , V_1593 ) ;
} else {
F_86 ( V_5 , V_1593 ) ;
F_86 ( V_5 , V_1293 ) ;
V_5 -> V_1888 = NULL ;
}
if ( F_77 ( V_5 ) == V_758 )
V_5 -> V_1888 = V_2585 ;
if ( F_30 ( V_5 ) == V_668 )
V_5 -> V_1888 = V_2586 ;
V_5 -> V_122 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_84 ( V_5 , V_1898 ) ;
if ( F_146 ( V_5 ) == V_740 ||
F_146 ( V_5 ) == V_741 ||
( F_30 ( V_5 ) == V_549 &&
F_77 ( V_5 ) <= V_2587 &&
V_5 -> V_560 == V_5 -> V_12 ) )
F_86 ( V_5 , V_1898 ) ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 ) {
F_84 ( V_5 , 1SHOT_MSI ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
F_84 ( V_5 , V_1063 ) ;
V_5 -> V_122 = V_1892 ;
}
}
V_5 -> V_1897 = 1 ;
V_5 -> V_1895 = 1 ;
if ( V_5 -> V_122 > 1 ) {
V_5 -> V_1895 = V_2042 ;
F_451 ( V_5 , V_2042 ) ;
if ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 )
V_5 -> V_1897 = V_5 -> V_122 - 1 ;
}
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_84 ( V_5 , V_1258 ) ;
if ( F_30 ( V_5 ) == V_478 )
V_5 -> V_1259 = V_2588 ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_766 )
F_84 ( V_5 , V_1712 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) &&
F_77 ( V_5 ) != V_1611 )
F_84 ( V_5 , V_1304 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_1304 ) )
F_84 ( V_5 , V_522 ) ;
F_19 ( V_5 -> V_12 , V_1243 ,
& V_2558 ) ;
if ( F_428 ( V_5 -> V_12 ) ) {
T_3 V_2589 ;
F_84 ( V_5 , V_1081 ) ;
F_632 ( V_5 -> V_12 , V_699 , & V_2589 ) ;
if ( V_2589 & V_700 ) {
if ( F_30 ( V_5 ) == V_36 ) {
F_86 ( V_5 , V_1297 ) ;
F_86 ( V_5 , V_1593 ) ;
}
if ( F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_45 ||
F_77 ( V_5 ) == V_2590 ||
F_77 ( V_5 ) == V_2591 )
F_84 ( V_5 , V_698 ) ;
} else if ( F_77 ( V_5 ) == V_259 ) {
F_84 ( V_5 , V_1552 ) ;
}
} else if ( F_30 ( V_5 ) == V_257 ) {
F_84 ( V_5 , V_1081 ) ;
} else if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ) {
V_5 -> V_1392 = F_633 ( V_5 -> V_12 , V_2592 ) ;
if ( ! V_5 -> V_1392 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_108 ) ;
return - V_210 ;
}
if ( ! ( V_2558 & V_2593 ) )
F_84 ( V_5 , V_839 ) ;
}
if ( F_634 ( V_2594 ) &&
! F_23 ( V_5 , V_1081 ) )
F_84 ( V_5 , V_31 ) ;
F_635 ( V_5 -> V_12 , V_1387 ,
& V_5 -> V_1388 ) ;
F_635 ( V_5 -> V_12 , V_1389 ,
& V_5 -> V_1390 ) ;
if ( F_30 ( V_5 ) == V_500 &&
V_5 -> V_1390 < 64 ) {
V_5 -> V_1390 = 64 ;
F_425 ( V_5 -> V_12 , V_1389 ,
V_5 -> V_1390 ) ;
}
if ( F_146 ( V_5 ) == V_2595 ) {
F_84 ( V_5 , V_34 ) ;
if ( F_23 ( V_5 , V_839 ) ) {
T_1 V_2596 ;
F_84 ( V_5 , V_25 ) ;
F_19 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2597 + V_2598 ,
& V_2596 ) ;
V_2596 &= ~ V_2599 ;
V_2596 |= V_2600 | 0 ;
F_15 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2597 + V_2598 ,
V_2596 ) ;
F_422 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
V_1380 |= V_2601 | V_1887 ;
F_424 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
}
}
if ( ( V_2558 & V_1640 ) != 0 )
F_84 ( V_5 , V_840 ) ;
if ( ( V_2558 & V_2602 ) != 0 )
F_84 ( V_5 , V_2603 ) ;
if ( ( F_77 ( V_5 ) == V_916 ) &&
( ! ( V_2558 & V_1383 ) ) ) {
V_2558 |= V_1383 ;
F_15 ( V_5 -> V_12 , V_1243 , V_2558 ) ;
}
V_5 -> V_28 = F_9 ;
V_5 -> V_27 = F_7 ;
V_5 -> V_32 = F_9 ;
V_5 -> V_29 = F_7 ;
V_5 -> V_1096 = F_7 ;
V_5 -> V_1880 = F_7 ;
if ( F_23 ( V_5 , V_25 ) )
V_5 -> V_27 = F_13 ;
else if ( F_30 ( V_5 ) == V_538 ||
( F_23 ( V_5 , V_1081 ) &&
F_77 ( V_5 ) == V_1410 ) ) {
V_5 -> V_27 = F_17 ;
}
if ( F_23 ( V_5 , V_34 ) || F_23 ( V_5 , V_31 ) ) {
V_5 -> V_1096 = F_26 ;
if ( F_23 ( V_5 , V_31 ) )
V_5 -> V_1880 = F_17 ;
}
if ( F_23 ( V_5 , V_26 ) ) {
V_5 -> V_28 = F_18 ;
V_5 -> V_27 = F_13 ;
V_5 -> V_32 = F_21 ;
V_5 -> V_29 = F_20 ;
V_5 -> V_1096 = F_20 ;
V_5 -> V_1880 = F_20 ;
F_636 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
F_422 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
V_1380 &= ~ V_2604 ;
F_424 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_32 = F_27 ;
V_5 -> V_29 = F_28 ;
V_5 -> V_1096 = F_28 ;
V_5 -> V_1880 = F_28 ;
}
if ( V_5 -> V_27 == F_13 ||
( F_23 ( V_5 , V_839 ) &&
( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) ) )
F_84 ( V_5 , V_39 ) ;
V_7 = F_33 ( V_1065 ) ;
F_46 ( V_1065 , V_7 | V_1378 ) ;
V_5 -> V_54 = F_637 ( V_5 -> V_12 -> V_274 ) & 3 ;
if ( F_30 ( V_5 ) == V_501 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_839 ) ) {
F_19 ( V_5 -> V_12 ,
V_5 -> V_1392 + V_2605 ,
& V_7 ) ;
V_5 -> V_54 = V_7 & 0x7 ;
}
} else if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ) {
F_32 ( V_5 , V_2606 , & V_7 ) ;
if ( ( V_7 & V_2607 ) != V_2608 )
V_7 = F_33 ( V_2609 ) ;
if ( F_30 ( V_5 ) == V_477 )
V_5 -> V_54 = ( V_7 & V_2610 ) ? 1 : 0 ;
else
V_5 -> V_54 = ( V_7 & V_2611 ) >>
V_2612 ;
}
if ( F_23 ( V_5 , V_30 ) ) {
V_5 -> V_1096 = F_17 ;
V_5 -> V_1880 = F_17 ;
}
F_604 ( V_5 ) ;
if ( F_23 ( V_5 , V_684 ) && F_23 ( V_5 , V_309 ) ) {
F_86 ( V_5 , V_1593 ) ;
F_86 ( V_5 , V_1293 ) ;
V_5 -> V_1888 = NULL ;
}
if ( F_23 ( V_5 , V_60 ) ) {
V_2558 |= V_1384 |
V_1385 |
V_1386 ;
F_15 ( V_5 -> V_12 , V_1243 ,
V_2558 ) ;
F_34 ( V_5 ) ;
}
V_5 -> V_22 = V_2613 | V_2364 ;
if ( F_30 ( V_5 ) == V_537 ||
F_23 ( V_5 , V_644 ) )
V_5 -> V_22 |= ( V_539 |
V_540 ) ;
else if ( F_30 ( V_5 ) == V_641 )
V_5 -> V_22 |= V_550 ;
if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_1402 ||
F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_22 |= V_1685 ;
if ( V_5 -> V_12 -> V_544 == V_545 ||
V_5 -> V_12 -> V_544 == V_546 ) {
V_5 -> V_22 |= V_1685 ;
if ( F_23 ( V_5 , V_533 ) )
V_5 -> V_22 |= V_541 |
V_543 ;
}
if ( F_30 ( V_5 ) == V_766 )
V_5 -> V_22 |=
F_33 ( V_136 ) & V_1685 ;
F_148 ( V_5 ) ;
if ( V_5 -> V_111 -> V_1201 > V_1328 && ! F_23 ( V_5 , 5780_CLASS ) )
F_84 ( V_5 , V_1340 ) ;
if ( F_30 ( V_5 ) == V_537 ||
F_77 ( V_5 ) == V_758 ||
F_77 ( V_5 ) == V_759 ||
F_77 ( V_5 ) == V_2614 ) {
F_86 ( V_5 , V_706 ) ;
} else {
F_84 ( V_5 , V_706 ) ;
}
if ( F_30 ( V_5 ) == V_36 )
V_5 -> V_178 |= V_179 ;
if ( F_30 ( V_5 ) == V_537 ||
( F_30 ( V_5 ) == V_502 &&
( F_77 ( V_5 ) != V_1425 ) &&
( F_77 ( V_5 ) != V_1697 ) ) ||
( V_5 -> V_178 & V_179 ) ||
( V_5 -> V_178 & V_360 ) )
V_5 -> V_178 |= V_424 ;
if ( F_146 ( V_5 ) == V_2615 ||
F_146 ( V_5 ) == V_2616 )
V_5 -> V_178 |= V_515 ;
if ( F_77 ( V_5 ) == V_916 )
V_5 -> V_178 |= V_516 ;
if ( F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) != V_257 &&
F_30 ( V_5 ) != V_1402 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
if ( F_30 ( V_5 ) == V_1487 ||
F_30 ( V_5 ) == V_1500 ||
F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_45 ) {
if ( V_5 -> V_12 -> V_544 != V_2617 &&
V_5 -> V_12 -> V_544 != V_2618 )
V_5 -> V_178 |= V_518 ;
if ( V_5 -> V_12 -> V_544 == V_2619 )
V_5 -> V_178 |= V_519 ;
} else
V_5 -> V_178 |= V_517 ;
}
if ( F_30 ( V_5 ) == V_414 &&
F_146 ( V_5 ) != V_504 ) {
V_5 -> V_427 = F_608 ( V_5 ) ;
if ( V_5 -> V_427 == 0 )
V_5 -> V_427 = V_2620 ;
}
if ( F_23 ( V_5 , V_152 ) )
V_5 -> V_164 = V_2621 ;
else
V_5 -> V_164 = V_2622 ;
V_5 -> V_127 = 0 ;
if ( F_146 ( V_5 ) != V_2623 &&
F_146 ( V_5 ) != V_2595 )
V_5 -> V_127 |= V_2624 ;
if ( F_30 ( V_5 ) == V_477 ||
F_77 ( V_5 ) == V_1611 ||
F_77 ( V_5 ) == V_1612 ) {
V_5 -> V_127 |= V_2625 ;
V_5 -> V_645 |= V_2626 ;
}
if ( F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1402 )
F_84 ( V_5 , V_267 ) ;
V_75 = F_76 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_7 = F_33 ( V_647 ) ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_766 )
V_7 &= ( V_2627 |
V_2628 |
V_2629 |
V_2630 |
V_1579 ) ;
else
V_7 &= V_1579 ;
F_46 ( V_647 , V_7 | V_5 -> V_645 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
F_46 ( V_13 , 0 ) ;
F_19 ( V_5 -> V_12 , V_1243 ,
& V_2558 ) ;
if ( ( V_2558 & V_2593 ) == 0 &&
! F_23 ( V_5 , V_25 ) ) {
if ( F_77 ( V_5 ) == V_758 ||
F_77 ( V_5 ) == V_759 ||
F_77 ( V_5 ) == V_2614 ||
F_77 ( V_5 ) == V_2631 ) {
void T_2 * V_2632 ;
V_2632 = V_5 -> V_8 + V_2633 + V_37 ;
F_8 ( 0x00000000 , V_2632 ) ;
F_8 ( 0x00000000 , V_2632 + 4 ) ;
F_8 ( 0xffffffff , V_2632 + 4 ) ;
if ( F_10 ( V_2632 ) != 0x00000000 )
F_84 ( V_5 , V_25 ) ;
}
}
F_24 ( 50 ) ;
F_602 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_668 &&
! F_23 ( V_5 , V_682 ) )
V_5 -> V_1888 = NULL ;
V_2553 = F_33 ( V_498 ) ;
V_2553 &= V_2554 ;
if ( F_30 ( V_5 ) == V_502 &&
( V_2553 == V_2634 ||
V_2553 == V_2635 ) )
F_84 ( V_5 , V_1641 ) ;
if ( ! F_23 ( V_5 , V_1641 ) &&
F_30 ( V_5 ) != V_537 )
F_84 ( V_5 , V_133 ) ;
if ( F_23 ( V_5 , V_133 ) ) {
V_5 -> V_127 |= ( V_2636 |
V_2637 ) ;
V_5 -> V_120 |= V_2638 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
}
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_368 = V_729 | V_730 ;
else
V_5 -> V_368 = 0 ;
if ( F_629 ( V_5 , V_2552 ) )
V_5 -> V_178 |= V_393 ;
V_75 = F_610 ( V_5 ) ;
if ( V_75 ) {
F_117 ( & V_5 -> V_12 -> V_111 , L_109 , V_75 ) ;
F_85 ( V_5 ) ;
}
F_612 ( V_5 ) ;
F_623 ( V_5 ) ;
if ( V_5 -> V_178 & V_568 ) {
V_5 -> V_178 &= ~ V_816 ;
} else {
if ( F_30 ( V_5 ) == V_537 )
V_5 -> V_178 |= V_816 ;
else
V_5 -> V_178 &= ~ V_816 ;
}
if ( F_30 ( V_5 ) == V_537 )
F_84 ( V_5 , V_142 ) ;
else
F_86 ( V_5 , V_142 ) ;
if ( V_5 -> V_12 -> V_2368 == V_2410 &&
F_30 ( V_5 ) == V_538 &&
! ( V_5 -> V_178 & V_568 ) ) {
V_5 -> V_178 |= V_816 ;
F_84 ( V_5 , V_142 ) ;
}
if ( V_5 -> V_178 & V_568 )
F_84 ( V_5 , V_143 ) ;
else
F_86 ( V_5 , V_143 ) ;
V_5 -> V_2639 = V_2640 + V_2641 ;
V_5 -> V_2642 = V_2643 ;
if ( F_30 ( V_5 ) == V_538 &&
F_23 ( V_5 , V_839 ) ) {
V_5 -> V_2639 = V_2640 ;
#ifndef F_638
V_5 -> V_2642 = ~ ( T_3 ) 0 ;
#endif
}
V_5 -> V_1140 = F_458 ( V_5 ) - 1 ;
V_5 -> V_1145 = F_457 ( V_5 ) - 1 ;
V_5 -> V_1208 = F_624 ( V_5 ) - 1 ;
V_5 -> V_1207 = V_5 -> V_1140 + 1 ;
if ( F_30 ( V_5 ) == V_1498 ||
F_30 ( V_5 ) == V_641 ||
F_30 ( V_5 ) == V_1487 )
V_5 -> V_1207 = 8 ;
if ( F_23 ( V_5 , V_972 ) )
V_5 -> V_975 = F_33 ( V_973 ) &
V_974 ;
return V_75 ;
}
static int F_639 ( struct V_4 * V_5 )
{
struct V_365 * V_111 = V_5 -> V_111 ;
struct V_1792 * V_12 = V_5 -> V_12 ;
struct V_2644 * V_2019 = F_640 ( V_12 ) ;
const unsigned char * V_184 ;
int V_74 ;
V_184 = F_641 ( V_2019 , L_110 , & V_74 ) ;
if ( V_184 && V_74 == V_1524 ) {
memcpy ( V_111 -> V_689 , V_184 , V_1524 ) ;
return 0 ;
}
return - V_82 ;
}
static int F_642 ( struct V_4 * V_5 )
{
struct V_365 * V_111 = V_5 -> V_111 ;
memcpy ( V_111 -> V_689 , V_2645 -> V_2646 , V_1524 ) ;
return 0 ;
}
static int F_643 ( struct V_4 * V_5 )
{
struct V_365 * V_111 = V_5 -> V_111 ;
T_1 V_2647 , V_2648 , V_2649 ;
int V_2650 = 0 ;
int V_75 ;
#ifdef F_644
if ( ! F_639 ( V_5 ) )
return 0 ;
#endif
if ( F_23 ( V_5 , V_264 ) ) {
V_75 = F_645 ( V_5 -> V_12 , & V_111 -> V_689 [ 0 ] ) ;
if ( ! V_75 && F_434 ( & V_111 -> V_689 [ 0 ] ) )
return 0 ;
}
V_2649 = 0x7c ;
if ( F_30 ( V_5 ) == V_501 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_33 ( V_918 ) & V_919 )
V_2649 = 0xcc ;
if ( F_158 ( V_5 ) )
F_31 ( V_608 , V_2651 ) ;
else
F_159 ( V_5 ) ;
} else if ( F_23 ( V_5 , 5717_PLUS ) ) {
if ( V_5 -> V_54 & 1 )
V_2649 = 0xcc ;
if ( V_5 -> V_54 > 1 )
V_2649 += 0x18c ;
} else if ( F_30 ( V_5 ) == V_36 )
V_2649 = 0x10 ;
F_32 ( V_5 , V_2652 , & V_2647 ) ;
if ( ( V_2647 >> 16 ) == 0x484b ) {
V_111 -> V_689 [ 0 ] = ( V_2647 >> 8 ) & 0xff ;
V_111 -> V_689 [ 1 ] = ( V_2647 >> 0 ) & 0xff ;
F_32 ( V_5 , V_2653 , & V_2648 ) ;
V_111 -> V_689 [ 2 ] = ( V_2648 >> 24 ) & 0xff ;
V_111 -> V_689 [ 3 ] = ( V_2648 >> 16 ) & 0xff ;
V_111 -> V_689 [ 4 ] = ( V_2648 >> 8 ) & 0xff ;
V_111 -> V_689 [ 5 ] = ( V_2648 >> 0 ) & 0xff ;
V_2650 = F_434 ( & V_111 -> V_689 [ 0 ] ) ;
}
if ( ! V_2650 ) {
if ( ! F_23 ( V_5 , V_682 ) &&
! F_169 ( V_5 , V_2649 + 0 , & V_2647 ) &&
! F_169 ( V_5 , V_2649 + 4 , & V_2648 ) ) {
memcpy ( & V_111 -> V_689 [ 0 ] , ( ( char * ) & V_2647 ) + 2 , 2 ) ;
memcpy ( & V_111 -> V_689 [ 2 ] , ( char * ) & V_2648 , sizeof( V_2648 ) ) ;
}
else {
V_2647 = F_33 ( V_690 ) ;
V_2648 = F_33 ( V_691 ) ;
V_111 -> V_689 [ 5 ] = V_2648 & 0xff ;
V_111 -> V_689 [ 4 ] = ( V_2648 >> 8 ) & 0xff ;
V_111 -> V_689 [ 3 ] = ( V_2648 >> 16 ) & 0xff ;
V_111 -> V_689 [ 2 ] = ( V_2648 >> 24 ) & 0xff ;
V_111 -> V_689 [ 1 ] = V_2647 & 0xff ;
V_111 -> V_689 [ 0 ] = ( V_2647 >> 8 ) & 0xff ;
}
}
if ( ! F_434 ( & V_111 -> V_689 [ 0 ] ) ) {
#ifdef F_644
if ( ! F_642 ( V_5 ) )
return 0 ;
#endif
return - V_64 ;
}
return 0 ;
}
static T_1 F_646 ( struct V_4 * V_5 , T_1 V_7 )
{
int V_2654 ;
T_4 V_2655 ;
int V_2656 ;
F_635 ( V_5 -> V_12 , V_1387 , & V_2655 ) ;
if ( V_2655 == 0 )
V_2654 = 1024 ;
else
V_2654 = ( int ) V_2655 * 4 ;
if ( F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_538 &&
! F_23 ( V_5 , V_1081 ) )
goto V_503;
#if F_358 ( V_2657 ) || F_358 ( V_2658 ) || F_358 ( V_2659 )
V_2656 = V_2660 ;
#else
#if F_358 ( V_2661 ) || F_358 ( V_2662 )
V_2656 = V_2663 ;
#else
V_2656 = 0 ;
#endif
#endif
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = V_2656 ? 0 : V_1570 ;
goto V_503;
}
if ( ! V_2656 )
goto V_503;
if ( F_23 ( V_5 , V_839 ) && ! F_23 ( V_5 , V_1081 ) ) {
switch ( V_2654 ) {
case 16 :
case 32 :
case 64 :
case 128 :
if ( V_2656 == V_2663 ) {
V_7 |= ( V_2664 |
V_2665 ) ;
} else {
V_7 |= ( V_2666 |
V_2667 ) ;
}
break;
case 256 :
V_7 |= ( V_2668 |
V_2669 ) ;
break;
default:
V_7 |= ( V_2666 |
V_2667 ) ;
break;
}
} else if ( F_23 ( V_5 , V_1081 ) ) {
switch ( V_2654 ) {
case 16 :
case 32 :
case 64 :
if ( V_2656 == V_2663 ) {
V_7 &= ~ V_2670 ;
V_7 |= V_2671 ;
break;
}
case 128 :
default:
V_7 &= ~ V_2670 ;
V_7 |= V_2672 ;
break;
}
} else {
switch ( V_2654 ) {
case 16 :
if ( V_2656 == V_2663 ) {
V_7 |= ( V_2673 |
V_2674 ) ;
break;
}
case 32 :
if ( V_2656 == V_2663 ) {
V_7 |= ( V_2675 |
V_2676 ) ;
break;
}
case 64 :
if ( V_2656 == V_2663 ) {
V_7 |= ( V_2677 |
V_2678 ) ;
break;
}
case 128 :
if ( V_2656 == V_2663 ) {
V_7 |= ( V_2679 |
V_2680 ) ;
break;
}
case 256 :
V_7 |= ( V_2681 |
V_2682 ) ;
break;
case 512 :
V_7 |= ( V_2683 |
V_2684 ) ;
break;
case 1024 :
default:
V_7 |= ( V_2685 |
V_2686 ) ;
break;
}
}
V_503:
return V_7 ;
}
static int F_647 ( struct V_4 * V_5 , T_1 * V_627 , T_9 V_2687 ,
int V_635 , bool V_2688 )
{
struct V_2689 V_2690 ;
T_1 V_2691 ;
int V_42 , V_56 ;
V_2691 = V_1590 ;
F_46 ( V_2692 , 0 ) ;
F_46 ( V_2693 , 0 ) ;
F_46 ( V_1234 , 0 ) ;
F_46 ( V_1235 , 0 ) ;
F_46 ( V_1066 , 0 ) ;
F_46 ( V_1076 , 0 ) ;
V_2690 . V_1150 = ( ( T_6 ) V_2687 ) >> 32 ;
V_2690 . V_1151 = V_2687 & 0xffffffff ;
V_2690 . V_2694 = 0x00002100 ;
V_2690 . V_74 = V_635 ;
if ( V_2688 ) {
V_2690 . V_2695 = ( 13 << 8 ) | 2 ;
F_31 ( V_1067 , V_1371 ) ;
F_24 ( 40 ) ;
} else {
V_2690 . V_2695 = ( 16 << 8 ) | 7 ;
F_31 ( V_1068 , V_1375 ) ;
F_24 ( 40 ) ;
}
V_2690 . V_10 = 0x00000005 ;
for ( V_42 = 0 ; V_42 < ( sizeof( V_2690 ) / sizeof( T_1 ) ) ; V_42 ++ ) {
T_1 V_7 ;
V_7 = * ( ( ( T_1 * ) & V_2690 ) + V_42 ) ;
F_15 ( V_5 -> V_12 , V_40 ,
V_2691 + ( V_42 * sizeof( T_1 ) ) ) ;
F_15 ( V_5 -> V_12 , V_41 , V_7 ) ;
}
F_15 ( V_5 -> V_12 , V_40 , 0 ) ;
if ( V_2688 )
F_46 ( V_2696 , V_2691 ) ;
else
F_46 ( V_2697 , V_2691 ) ;
V_56 = - V_82 ;
for ( V_42 = 0 ; V_42 < 40 ; V_42 ++ ) {
T_1 V_7 ;
if ( V_2688 )
V_7 = F_33 ( V_2692 ) ;
else
V_7 = F_33 ( V_2693 ) ;
if ( ( V_7 & 0xffff ) == V_2691 ) {
V_56 = 0 ;
break;
}
F_24 ( 100 ) ;
}
return V_56 ;
}
static int F_648 ( struct V_4 * V_5 )
{
T_9 V_2687 ;
T_1 * V_627 , V_2698 ;
int V_56 = 0 ;
V_627 = F_406 ( & V_5 -> V_12 -> V_111 , V_2699 ,
& V_2687 , V_633 ) ;
if ( ! V_627 ) {
V_56 = - V_268 ;
goto V_2700;
}
V_5 -> V_1573 = ( ( 0x7 << V_2701 ) |
( 0x6 << V_2702 ) ) ;
V_5 -> V_1573 = F_646 ( V_5 , V_5 -> V_1573 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
goto V_503;
if ( F_23 ( V_5 , V_1081 ) ) {
V_5 -> V_1573 |= 0x00180000 ;
} else if ( ! F_23 ( V_5 , V_839 ) ) {
if ( F_30 ( V_5 ) == V_502 ||
F_30 ( V_5 ) == V_1498 )
V_5 -> V_1573 |= 0x003f0000 ;
else
V_5 -> V_1573 |= 0x003f000f ;
} else {
if ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ) {
T_1 V_2703 = ( F_33 ( V_153 ) & 0x1f ) ;
T_1 V_2704 = 0x7 ;
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) &&
F_30 ( V_5 ) == V_501 )
V_5 -> V_1573 |= 0x8000 ;
else if ( V_2703 == 0x6 || V_2703 == 0x7 )
V_5 -> V_1573 |= V_2705 ;
if ( F_30 ( V_5 ) == V_500 )
V_2704 = 4 ;
V_5 -> V_1573 |=
( V_2704 << V_2706 ) |
( 0x3 << V_2707 ) |
( 1 << 23 ) ;
} else if ( F_30 ( V_5 ) == V_567 ) {
V_5 -> V_1573 |= 0x00144000 ;
} else if ( F_30 ( V_5 ) == V_549 ) {
V_5 -> V_1573 |= 0x00148000 ;
} else {
V_5 -> V_1573 |= 0x001b000f ;
}
}
if ( F_23 ( V_5 , V_2708 ) )
V_5 -> V_1573 |= V_2705 ;
if ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 )
V_5 -> V_1573 &= 0xfffffff0 ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) {
V_5 -> V_1573 |= V_2709 ;
V_5 -> V_1573 |= V_2710 ;
}
F_46 ( V_1569 , V_5 -> V_1573 ) ;
if ( F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_538 )
goto V_503;
V_2698 = V_5 -> V_1573 ;
V_5 -> V_1573 &= ~ V_2711 ;
F_46 ( V_1569 , V_5 -> V_1573 ) ;
while ( 1 ) {
T_1 * V_1439 = V_627 , V_42 ;
for ( V_42 = 0 ; V_42 < V_2699 / sizeof( T_1 ) ; V_42 ++ )
V_1439 [ V_42 ] = V_42 ;
V_56 = F_647 ( V_5 , V_627 , V_2687 , V_2699 , true ) ;
if ( V_56 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_111 ,
V_658 , V_56 ) ;
break;
}
V_56 = F_647 ( V_5 , V_627 , V_2687 , V_2699 , false ) ;
if ( V_56 ) {
F_117 ( & V_5 -> V_12 -> V_111 , L_112
L_113 , V_658 , V_56 ) ;
break;
}
for ( V_42 = 0 ; V_42 < V_2699 / sizeof( T_1 ) ; V_42 ++ ) {
if ( V_1439 [ V_42 ] == V_42 )
continue;
if ( ( V_5 -> V_1573 & V_2711 ) !=
V_2674 ) {
V_5 -> V_1573 &= ~ V_2711 ;
V_5 -> V_1573 |= V_2674 ;
F_46 ( V_1569 , V_5 -> V_1573 ) ;
break;
} else {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_114
L_115 , V_658 , V_1439 [ V_42 ] , V_42 ) ;
V_56 = - V_82 ;
goto V_503;
}
}
if ( V_42 == ( V_2699 / sizeof( T_1 ) ) ) {
V_56 = 0 ;
break;
}
}
if ( ( V_5 -> V_1573 & V_2711 ) !=
V_2674 ) {
if ( F_634 ( V_2712 ) ) {
V_5 -> V_1573 &= ~ V_2711 ;
V_5 -> V_1573 |= V_2674 ;
} else {
V_5 -> V_1573 = V_2698 ;
}
F_46 ( V_1569 , V_5 -> V_1573 ) ;
}
V_503:
F_404 ( & V_5 -> V_12 -> V_111 , V_2699 , V_627 , V_2687 ) ;
V_2700:
return V_56 ;
}
static void F_649 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_5 -> V_1596 . V_1597 =
V_2713 ;
V_5 -> V_1596 . V_1599 =
V_2714 ;
V_5 -> V_1596 . V_1601 =
V_2715 ;
V_5 -> V_1596 . V_1602 =
V_2713 ;
V_5 -> V_1596 . V_1603 =
V_2716 ;
V_5 -> V_1596 . V_1604 =
V_2717 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_5 -> V_1596 . V_1597 =
V_2713 ;
V_5 -> V_1596 . V_1599 =
V_2718 ;
V_5 -> V_1596 . V_1601 =
V_2719 ;
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_1596 . V_1599 =
V_2720 ;
V_5 -> V_1596 . V_1601 =
V_2721 ;
}
V_5 -> V_1596 . V_1602 =
V_2722 ;
V_5 -> V_1596 . V_1603 =
V_2723 ;
V_5 -> V_1596 . V_1604 =
V_2724 ;
} else {
V_5 -> V_1596 . V_1597 =
V_2725 ;
V_5 -> V_1596 . V_1599 =
V_2726 ;
V_5 -> V_1596 . V_1601 =
V_2727 ;
V_5 -> V_1596 . V_1602 =
V_2728 ;
V_5 -> V_1596 . V_1603 =
V_2729 ;
V_5 -> V_1596 . V_1604 =
V_2730 ;
}
V_5 -> V_1596 . V_1606 = V_2731 ;
V_5 -> V_1596 . V_1608 = V_2732 ;
}
static char * F_650 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_216 & V_401 ) {
case V_2733 : return L_116 ;
case V_402 : return L_117 ;
case V_566 : return L_118 ;
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
case V_2751 : return L_136 ;
case V_2752 : return L_137 ;
case V_2753 : return L_138 ;
case V_939 : return L_139 ;
case 0 : return L_140 ;
default: return L_141 ;
}
}
static char * F_651 ( struct V_4 * V_5 , char * V_2754 )
{
if ( F_23 ( V_5 , V_1081 ) ) {
strcpy ( V_2754 , L_142 ) ;
return V_2754 ;
} else if ( F_23 ( V_5 , V_839 ) ) {
T_1 V_150 = F_33 ( V_153 ) & 0x1f ;
strcpy ( V_2754 , L_143 ) ;
if ( ( V_150 == 7 ) ||
( ( F_33 ( V_498 ) & V_2554 ) ==
V_2755 ) )
strcat ( V_2754 , L_144 ) ;
else if ( V_150 == 0 )
strcat ( V_2754 , L_145 ) ;
else if ( V_150 == 2 )
strcat ( V_2754 , L_146 ) ;
else if ( V_150 == 4 )
strcat ( V_2754 , L_147 ) ;
else if ( V_150 == 6 )
strcat ( V_2754 , L_148 ) ;
} else {
strcpy ( V_2754 , L_149 ) ;
if ( F_23 ( V_5 , V_840 ) )
strcat ( V_2754 , L_147 ) ;
else
strcat ( V_2754 , L_145 ) ;
}
if ( F_23 ( V_5 , V_2603 ) )
strcat ( V_2754 , L_150 ) ;
else
strcat ( V_2754 , L_151 ) ;
return V_2754 ;
}
static void F_652 ( struct V_4 * V_5 )
{
struct V_1457 * V_1458 = & V_5 -> V_970 ;
memset ( V_1458 , 0 , sizeof( * V_1458 ) ) ;
V_1458 -> V_643 = V_2756 ;
V_1458 -> V_1469 = V_2757 ;
V_1458 -> V_1460 = V_2758 ;
V_1458 -> V_1471 = V_2759 ;
V_1458 -> V_1462 = V_2760 ;
V_1458 -> V_1477 = V_2761 ;
V_1458 -> V_1479 = V_2762 ;
V_1458 -> V_1473 = V_2763 ;
V_1458 -> V_1464 = V_2764 ;
V_1458 -> V_971 = V_2765 ;
if ( V_5 -> V_127 & ( V_2636 |
V_2637 ) ) {
V_1458 -> V_1469 = V_2766 ;
V_1458 -> V_1477 = V_2767 ;
V_1458 -> V_1460 = V_2768 ;
V_1458 -> V_1479 = V_2769 ;
}
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_1458 -> V_1477 = 0 ;
V_1458 -> V_1479 = 0 ;
V_1458 -> V_971 = 0 ;
}
}
static int F_653 ( struct V_1792 * V_12 ,
const struct V_2551 * V_2552 )
{
struct V_365 * V_111 ;
struct V_4 * V_5 ;
int V_42 , V_75 ;
T_1 V_2770 , V_2771 , V_2772 ;
char V_2754 [ 40 ] ;
T_6 V_2773 , V_2774 ;
T_13 V_1192 = 0 ;
F_654 ( V_2775 L_152 , V_1971 ) ;
V_75 = F_655 ( V_12 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_153 ) ;
return V_75 ;
}
V_75 = F_656 ( V_12 , V_2009 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_154 ) ;
goto V_2776;
}
F_657 ( V_12 ) ;
V_111 = F_658 ( sizeof( * V_5 ) , V_1892 ) ;
if ( ! V_111 ) {
V_75 = - V_268 ;
goto V_2777;
}
F_659 ( V_111 , & V_12 -> V_111 ) ;
V_5 = F_111 ( V_111 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_111 = V_111 ;
V_5 -> V_355 = V_2778 ;
V_5 -> V_357 = V_2779 ;
V_5 -> V_125 = 1 ;
if ( V_2780 > 0 )
V_5 -> V_2020 = V_2780 ;
else
V_5 -> V_2020 = V_2781 ;
if ( F_660 ( V_12 ) ) {
F_84 ( V_5 , V_264 ) ;
if ( F_661 ( V_12 ) )
F_84 ( V_5 , V_30 ) ;
if ( F_662 ( V_12 ) )
F_84 ( V_5 , V_2708 ) ;
if ( F_663 ( V_12 ) ) {
F_84 ( V_5 , V_267 ) ;
F_84 ( V_5 , V_265 ) ;
}
if ( F_664 ( V_12 ) )
F_84 ( V_5 , V_833 ) ;
}
V_5 -> V_120 =
V_121 |
V_2782 |
V_2783 |
V_2784 ;
V_5 -> V_645 = ( V_2785 | V_2786 |
V_2787 ) ;
#ifdef F_665
V_5 -> V_645 |= V_2788 ;
#endif
F_666 ( & V_5 -> V_209 ) ;
F_666 ( & V_5 -> V_11 ) ;
F_667 ( & V_5 -> V_1224 , F_481 ) ;
V_5 -> V_8 = F_668 ( V_12 , V_2789 ) ;
if ( ! V_5 -> V_8 ) {
F_117 ( & V_12 -> V_111 , L_155 ) ;
V_75 = - V_268 ;
goto V_2790;
}
if ( V_5 -> V_12 -> V_544 == V_545 ||
V_5 -> V_12 -> V_544 == V_2791 ||
V_5 -> V_12 -> V_544 == V_546 ||
V_5 -> V_12 -> V_544 == V_2792 ||
V_5 -> V_12 -> V_544 == V_2466 ||
V_5 -> V_12 -> V_544 == V_2467 ||
V_5 -> V_12 -> V_544 == V_2468 ||
V_5 -> V_12 -> V_544 == V_2538 ||
V_5 -> V_12 -> V_544 == V_2539 ||
V_5 -> V_12 -> V_544 == V_2540 ||
V_5 -> V_12 -> V_544 == V_2541 ||
V_5 -> V_12 -> V_544 == V_2542 ||
V_5 -> V_12 -> V_544 == V_2517 ||
V_5 -> V_12 -> V_544 == V_2543 ||
V_5 -> V_12 -> V_544 == V_2544 ) {
F_84 ( V_5 , V_60 ) ;
V_5 -> V_9 = F_668 ( V_12 , V_2793 ) ;
if ( ! V_5 -> V_9 ) {
F_117 ( & V_12 -> V_111 ,
L_156 ) ;
V_75 = - V_268 ;
goto V_2794;
}
}
V_5 -> V_1338 = V_2795 ;
V_5 -> V_1342 = V_2796 ;
V_111 -> V_2797 = & V_2798 ;
V_111 -> V_2799 = V_2800 ;
V_111 -> V_2801 = & V_2802 ;
V_111 -> V_280 = V_12 -> V_280 ;
V_75 = F_630 ( V_5 , V_2552 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 ,
L_157 ) ;
goto V_2803;
}
if ( F_23 ( V_5 , V_1641 ) )
V_2774 = V_2773 = F_359 ( 32 ) ;
else if ( F_23 ( V_5 , 40BIT_DMA_BUG ) ) {
V_2774 = V_2773 = F_359 ( 40 ) ;
#ifdef V_1247
V_2773 = F_359 ( 64 ) ;
#endif
} else
V_2774 = V_2773 = F_359 ( 64 ) ;
if ( V_2773 > F_359 ( 32 ) ) {
V_75 = F_669 ( V_12 , V_2773 ) ;
if ( ! V_75 ) {
V_1192 |= V_2804 ;
V_75 = F_670 ( V_12 ,
V_2774 ) ;
if ( V_75 < 0 ) {
F_117 ( & V_12 -> V_111 , L_158
L_159 ) ;
goto V_2803;
}
}
}
if ( V_75 || V_2773 == F_359 ( 32 ) ) {
V_75 = F_669 ( V_12 , F_359 ( 32 ) ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 ,
L_160 ) ;
goto V_2803;
}
}
F_649 ( V_5 ) ;
V_1192 |= V_2805 | V_2806 ;
if ( F_77 ( V_5 ) != V_2807 ) {
V_1192 |= V_2808 | V_2809 | V_1193 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_1192 |= V_2810 ;
}
if ( ( F_23 ( V_5 , V_1296 ) ||
F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ) &&
( V_1192 & V_2809 ) )
V_1192 |= V_1278 ;
if ( F_23 ( V_5 , V_1297 ) || F_23 ( V_5 , V_1298 ) ) {
if ( V_1192 & V_2810 )
V_1192 |= V_2811 ;
if ( F_23 ( V_5 , V_1298 ) ||
F_30 ( V_5 ) == V_45 ||
( F_30 ( V_5 ) == V_414 &&
F_146 ( V_5 ) != V_504 ) ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1402 )
V_1192 |= V_2812 ;
}
V_111 -> V_1192 |= V_1192 ;
V_111 -> V_2813 |= V_1192 ;
if ( F_30 ( V_5 ) != V_567 &&
! F_23 ( V_5 , V_152 ) )
V_1192 |= V_1327 ;
V_111 -> V_2814 |= V_1192 ;
if ( F_77 ( V_5 ) == V_1697 &&
! F_23 ( V_5 , V_1593 ) &&
! ( F_33 ( V_1243 ) & V_1640 ) ) {
F_84 ( V_5 , V_2028 ) ;
V_5 -> V_1338 = 63 ;
}
V_75 = F_643 ( V_5 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 ,
L_161 ) ;
goto V_2803;
}
if ( ( F_33 ( V_138 ) & V_128 ) ||
( F_33 ( V_1068 ) & V_1375 ) ) {
F_46 ( V_1065 , V_1378 ) ;
F_430 ( V_5 , V_110 , 1 ) ;
}
V_75 = F_648 ( V_5 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_162 ) ;
goto V_2803;
}
V_2772 = V_20 + V_16 ;
V_2771 = V_15 + V_16 ;
V_2770 = V_2815 + V_16 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_131 -> V_5 = V_5 ;
V_131 -> V_1090 = V_2816 ;
V_131 -> V_124 = V_2772 ;
if ( V_42 <= 4 )
V_2772 += 0x8 ;
else
V_2772 += 0x4 ;
V_131 -> V_1209 = V_2771 ;
V_131 -> V_1316 = V_2770 ;
if ( V_42 )
V_131 -> V_126 = V_2817 << ( V_42 - 1 ) ;
else
V_131 -> V_126 = V_1861 ;
if ( ! F_23 ( V_5 , V_1063 ) )
break;
if ( ! V_42 )
continue;
V_2771 += 0x8 ;
if ( V_2770 & 0x4 )
V_2770 -= 0x4 ;
else
V_2770 += 0xc ;
}
F_652 ( V_5 ) ;
F_671 ( V_12 , V_111 ) ;
if ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_766 )
F_84 ( V_5 , V_990 ) ;
F_474 ( V_5 ) ;
F_140 ( V_5 ) ;
V_75 = F_672 ( V_111 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_163 ) ;
goto V_2803;
}
F_98 ( V_111 , L_164 ,
V_5 -> V_2465 ,
F_77 ( V_5 ) ,
F_651 ( V_5 , V_2754 ) ,
V_111 -> V_689 ) ;
if ( V_5 -> V_178 & V_392 ) {
struct V_211 * V_212 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
F_98 ( V_111 ,
L_165 ,
V_212 -> V_215 -> V_269 , F_115 ( & V_212 -> V_111 ) ) ;
} else {
char * V_2818 ;
if ( V_5 -> V_178 & V_393 )
V_2818 = L_166 ;
else if ( V_5 -> V_178 & V_360 )
V_2818 = L_167 ;
else
V_2818 = L_168 ;
F_98 ( V_111 , L_169
L_170 ,
F_650 ( V_5 ) , V_2818 ,
( V_5 -> V_178 & V_424 ) == 0 ,
( V_5 -> V_178 & V_339 ) != 0 ) ;
}
F_98 ( V_111 , L_171 ,
( V_111 -> V_1192 & V_1193 ) != 0 ,
F_23 ( V_5 , V_142 ) != 0 ,
( V_5 -> V_178 & V_816 ) != 0 ,
F_23 ( V_5 , V_309 ) != 0 ,
F_23 ( V_5 , V_1593 ) != 0 ) ;
F_98 ( V_111 , L_172 ,
V_5 -> V_1573 ,
V_12 -> V_2773 == F_359 ( 32 ) ? 32 :
( ( T_6 ) V_12 -> V_2773 ) == F_359 ( 40 ) ? 40 : 64 ) ;
F_673 ( V_12 ) ;
return 0 ;
V_2803:
if ( V_5 -> V_9 ) {
F_636 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
V_2794:
if ( V_5 -> V_8 ) {
F_636 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
V_2790:
F_674 ( V_111 ) ;
V_2777:
F_675 ( V_12 ) ;
V_2776:
if ( F_676 ( V_12 ) )
F_677 ( V_12 ) ;
return V_75 ;
}
static void F_678 ( struct V_1792 * V_12 )
{
struct V_365 * V_111 = F_153 ( V_12 ) ;
if ( V_111 ) {
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_491 ( V_5 -> V_663 ) ;
F_325 ( V_5 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
F_125 ( V_5 ) ;
F_85 ( V_5 ) ;
}
F_679 ( V_111 ) ;
if ( V_5 -> V_9 ) {
F_636 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
if ( V_5 -> V_8 ) {
F_636 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
F_674 ( V_111 ) ;
F_675 ( V_12 ) ;
F_677 ( V_12 ) ;
}
}
static int F_680 ( struct V_544 * V_544 )
{
struct V_1792 * V_12 = F_681 ( V_544 ) ;
struct V_365 * V_111 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 = 0 ;
F_682 () ;
if ( ! F_145 ( V_111 ) )
goto V_2819;
F_325 ( V_5 ) ;
F_123 ( V_5 ) ;
F_340 ( V_5 ) ;
F_477 ( V_5 ) ;
F_240 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_241 ( V_5 ) ;
F_683 ( V_111 ) ;
F_240 ( V_5 , 0 ) ;
F_430 ( V_5 , V_110 , 1 ) ;
F_86 ( V_5 , V_563 ) ;
F_241 ( V_5 ) ;
V_75 = F_198 ( V_5 ) ;
if ( V_75 ) {
int V_760 ;
F_240 ( V_5 , 0 ) ;
F_84 ( V_5 , V_563 ) ;
V_760 = F_479 ( V_5 , true ) ;
if ( V_760 )
goto V_503;
F_476 ( V_5 ) ;
F_684 ( V_111 ) ;
F_342 ( V_5 ) ;
V_503:
F_241 ( V_5 ) ;
if ( ! V_760 )
F_120 ( V_5 ) ;
}
V_2819:
F_685 () ;
return V_75 ;
}
static int F_686 ( struct V_544 * V_544 )
{
struct V_1792 * V_12 = F_681 ( V_544 ) ;
struct V_365 * V_111 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 = 0 ;
F_682 () ;
if ( ! F_145 ( V_111 ) )
goto V_2819;
F_684 ( V_111 ) ;
F_240 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_84 ( V_5 , V_563 ) ;
V_75 = F_479 ( V_5 ,
! ( V_5 -> V_178 & V_570 ) ) ;
if ( V_75 )
goto V_503;
F_476 ( V_5 ) ;
F_342 ( V_5 ) ;
V_503:
F_241 ( V_5 ) ;
if ( ! V_75 )
F_120 ( V_5 ) ;
V_2819:
F_685 () ;
return V_75 ;
}
static void F_687 ( struct V_1792 * V_12 )
{
struct V_365 * V_111 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_682 () ;
F_683 ( V_111 ) ;
if ( F_145 ( V_111 ) )
F_480 ( V_111 ) ;
if ( V_2820 == V_2821 )
F_201 ( V_5 ) ;
F_685 () ;
}
static T_19 F_688 ( struct V_1792 * V_12 ,
T_20 V_846 )
{
struct V_365 * V_2822 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_2822 ) ;
T_19 V_75 = V_2823 ;
F_98 ( V_2822 , L_173 ) ;
F_682 () ;
if ( ! V_2822 || ! F_145 ( V_2822 ) )
goto V_186;
F_123 ( V_5 ) ;
F_340 ( V_5 ) ;
F_477 ( V_5 ) ;
F_325 ( V_5 ) ;
F_683 ( V_2822 ) ;
F_240 ( V_5 , 0 ) ;
F_430 ( V_5 , V_110 , 0 ) ;
F_241 ( V_5 ) ;
V_186:
if ( V_846 == V_2824 ) {
if ( V_2822 ) {
F_334 ( V_5 ) ;
F_480 ( V_2822 ) ;
}
V_75 = V_2825 ;
} else {
F_677 ( V_12 ) ;
}
F_685 () ;
return V_75 ;
}
static T_19 F_689 ( struct V_1792 * V_12 )
{
struct V_365 * V_2822 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_2822 ) ;
T_19 V_629 = V_2825 ;
int V_75 ;
F_682 () ;
if ( F_655 ( V_12 ) ) {
F_117 ( & V_12 -> V_111 ,
L_174 ) ;
goto V_186;
}
F_657 ( V_12 ) ;
F_690 ( V_12 ) ;
F_673 ( V_12 ) ;
if ( ! V_2822 || ! F_145 ( V_2822 ) ) {
V_629 = V_2826 ;
goto V_186;
}
V_75 = F_196 ( V_5 ) ;
if ( V_75 )
goto V_186;
V_629 = V_2826 ;
V_186:
if ( V_629 != V_2826 && V_2822 && F_145 ( V_2822 ) ) {
F_334 ( V_5 ) ;
F_480 ( V_2822 ) ;
}
F_685 () ;
return V_629 ;
}
static void F_691 ( struct V_1792 * V_12 )
{
struct V_365 * V_2822 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_2822 ) ;
int V_75 ;
F_682 () ;
if ( ! F_145 ( V_2822 ) )
goto V_186;
F_240 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_84 ( V_5 , V_563 ) ;
V_75 = F_479 ( V_5 , true ) ;
if ( V_75 ) {
F_241 ( V_5 ) ;
F_185 ( V_2822 , L_175 ) ;
goto V_186;
}
F_684 ( V_2822 ) ;
F_476 ( V_5 ) ;
F_342 ( V_5 ) ;
F_241 ( V_5 ) ;
F_120 ( V_5 ) ;
V_186:
F_685 () ;
}
