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
V_75 = F_57 ( V_5 , V_492 , & V_488 ) ;
if ( V_75 )
return V_75 ;
V_488 &= ~ 0x3000 ;
F_59 ( V_5 , V_492 , V_488 ) ;
return 0 ;
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
static void F_194 ( struct V_4 * V_5 , T_4 * V_686 , int V_687 )
{
T_1 V_688 , V_689 ;
V_688 = ( ( V_686 [ 0 ] << 8 ) | V_686 [ 1 ] ) ;
V_689 = ( ( V_686 [ 2 ] << 24 ) | ( V_686 [ 3 ] << 16 ) |
( V_686 [ 4 ] << 8 ) | V_686 [ 5 ] ) ;
if ( V_687 < 4 ) {
F_46 ( V_690 + ( V_687 * 8 ) , V_688 ) ;
F_46 ( V_691 + ( V_687 * 8 ) , V_689 ) ;
} else {
V_687 -= 4 ;
F_46 ( V_692 + ( V_687 * 8 ) , V_688 ) ;
F_46 ( V_693 + ( V_687 * 8 ) , V_689 ) ;
}
}
static void F_195 ( struct V_4 * V_5 , bool V_694 )
{
T_1 V_688 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
if ( V_42 == 1 && V_694 )
continue;
F_194 ( V_5 , V_5 -> V_111 -> V_695 , V_42 ) ;
}
if ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ) {
for ( V_42 = 4 ; V_42 < 16 ; V_42 ++ )
F_194 ( V_5 , V_5 -> V_111 -> V_695 , V_42 ) ;
}
V_688 = ( V_5 -> V_111 -> V_695 [ 0 ] +
V_5 -> V_111 -> V_695 [ 1 ] +
V_5 -> V_111 -> V_695 [ 2 ] +
V_5 -> V_111 -> V_695 [ 3 ] +
V_5 -> V_111 -> V_695 [ 4 ] +
V_5 -> V_111 -> V_695 [ 5 ] ) &
V_696 ;
F_46 ( V_697 , V_688 ) ;
}
static void F_196 ( struct V_4 * V_5 )
{
F_15 ( V_5 -> V_12 ,
V_119 , V_5 -> V_120 ) ;
}
static int F_197 ( struct V_4 * V_5 )
{
int V_75 ;
F_196 ( V_5 ) ;
V_75 = F_198 ( V_5 -> V_12 , V_698 ) ;
if ( ! V_75 ) {
F_148 ( V_5 ) ;
} else {
F_185 ( V_5 -> V_111 , L_27 ) ;
}
return V_75 ;
}
static int F_199 ( struct V_4 * V_5 )
{
T_1 V_120 ;
bool V_699 , V_569 ;
F_196 ( V_5 ) ;
if ( F_23 ( V_5 , V_700 ) )
F_200 ( V_5 -> V_12 , V_701 ,
V_702 ) ;
V_120 = F_33 ( V_119 ) ;
F_46 ( V_119 ,
V_120 | V_121 ) ;
V_699 = F_44 ( & V_5 -> V_12 -> V_111 ) &&
F_23 ( V_5 , V_112 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
V_569 = false ;
if ( ( V_5 -> V_178 & V_392 ) &&
! ( V_5 -> V_178 & V_400 ) ) {
struct V_211 * V_212 ;
T_1 V_703 , V_399 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
V_5 -> V_178 |= V_400 ;
V_5 -> V_330 . V_373 = V_212 -> V_373 ;
V_5 -> V_330 . V_377 = V_212 -> V_377 ;
V_5 -> V_330 . V_353 = V_212 -> V_353 ;
V_5 -> V_330 . V_399 = V_212 -> V_399 ;
V_399 = V_704 |
V_705 |
V_706 |
V_707 ;
if ( F_23 ( V_5 , V_309 ) || V_699 ) {
if ( F_23 ( V_5 , V_708 ) )
V_399 |=
V_709 |
V_710 |
V_711 ;
else
V_399 |= V_711 ;
}
V_212 -> V_399 = V_399 ;
F_122 ( V_212 ) ;
V_703 = V_212 -> V_215 -> V_216 & V_212 -> V_215 -> V_217 ;
if ( V_703 != V_221 ) {
V_703 &= V_712 ;
if ( V_703 == V_713 ||
V_703 == V_714 ||
V_703 == V_715 )
V_569 = true ;
}
}
} else {
V_569 = true ;
if ( ! ( V_5 -> V_178 & V_400 ) )
V_5 -> V_178 |= V_400 ;
if ( ! ( V_5 -> V_178 & V_360 ) )
F_201 ( V_5 , false ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
T_1 V_7 ;
V_7 = F_33 ( V_656 ) ;
F_46 ( V_656 , V_7 | V_716 ) ;
} else if ( ! F_23 ( V_5 , V_309 ) ) {
int V_42 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_32 ( V_5 , V_717 , & V_7 ) ;
if ( V_7 == ~ V_316 )
break;
F_163 ( 1 ) ;
}
}
if ( F_23 ( V_5 , V_718 ) )
F_29 ( V_5 , V_719 , V_720 |
V_721 |
V_722 |
V_723 ) ;
if ( V_699 ) {
T_1 V_368 ;
if ( ! ( V_5 -> V_178 & V_568 ) ) {
if ( V_569 &&
! ( V_5 -> V_178 & V_179 ) ) {
F_65 ( V_5 ,
V_585 ,
V_724 |
V_582 |
V_725 ) ;
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
V_368 |= V_5 -> V_368 & V_726 ;
if ( F_30 ( V_5 ) == V_537 ) {
T_1 V_373 = F_23 ( V_5 , V_708 ) ?
V_333 : V_374 ;
if ( F_154 ( V_5 , V_373 ) )
V_368 |= V_726 ;
else
V_368 &= ~ V_726 ;
}
} else {
V_368 = V_727 ;
}
if ( ! F_23 ( V_5 , 5750_PLUS ) )
F_46 ( V_728 , V_5 -> V_564 ) ;
V_368 |= V_729 ;
if ( ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) ) &&
( F_23 ( V_5 , V_309 ) || F_23 ( V_5 , V_60 ) ) )
V_368 |= V_730 ;
if ( F_23 ( V_5 , V_60 ) )
V_368 |= V_731 |
V_732 |
V_733 ;
F_31 ( V_383 , V_368 ) ;
F_24 ( 100 ) ;
F_31 ( V_362 , V_734 ) ;
F_24 ( 10 ) ;
}
if ( ! F_23 ( V_5 , V_708 ) &&
( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) ) {
T_1 V_735 ;
V_735 = V_5 -> V_156 ;
V_735 |= ( V_736 |
V_737 ) ;
F_55 ( V_153 , V_735 | V_159 |
V_738 , 40 ) ;
} else if ( F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_152 ) ||
F_30 ( V_5 ) == V_36 ) {
} else if ( ! ( F_23 ( V_5 , 5750_PLUS ) && F_23 ( V_5 , V_309 ) ) ) {
T_1 V_739 , V_740 ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) {
V_739 = ( V_736 |
V_737 |
V_159 ) ;
V_740 = V_739 | V_158 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_739 = V_157 ;
V_740 = V_739 | V_159 ;
} else {
V_739 = V_159 ;
V_740 = V_739 | V_158 ;
}
F_55 ( V_153 , V_5 -> V_156 | V_739 ,
40 ) ;
F_55 ( V_153 , V_5 -> V_156 | V_740 ,
40 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_741 ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) {
V_741 = ( V_736 |
V_737 |
V_158 ) ;
} else {
V_741 = V_158 ;
}
F_55 ( V_153 ,
V_5 -> V_156 | V_741 , 40 ) ;
}
}
if ( ! ( V_699 ) && ! F_23 ( V_5 , V_309 ) )
F_157 ( V_5 , V_569 ) ;
F_152 ( V_5 , true ) ;
if ( ( ! F_23 ( V_5 , V_264 ) ) &&
( ( F_146 ( V_5 ) == V_742 ) ||
( F_146 ( V_5 ) == V_743 ) ) ) {
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
static void F_202 ( struct V_4 * V_5 )
{
F_203 ( V_5 -> V_12 , F_23 ( V_5 , V_112 ) ) ;
F_198 ( V_5 -> V_12 , V_744 ) ;
}
static void F_204 ( struct V_4 * V_5 , T_1 V_7 , T_3 * V_373 , T_4 * V_377 )
{
switch ( V_7 & V_745 ) {
case V_746 :
* V_373 = V_374 ;
* V_377 = V_378 ;
break;
case V_747 :
* V_373 = V_374 ;
* V_377 = V_335 ;
break;
case V_748 :
* V_373 = V_333 ;
* V_377 = V_378 ;
break;
case V_749 :
* V_373 = V_333 ;
* V_377 = V_335 ;
break;
case V_750 :
* V_373 = V_332 ;
* V_377 = V_378 ;
break;
case V_751 :
* V_373 = V_332 ;
* V_377 = V_335 ;
break;
default:
if ( V_5 -> V_178 & V_179 ) {
* V_373 = ( V_7 & V_752 ) ? V_333 :
V_374 ;
* V_377 = ( V_7 & V_753 ) ? V_335 :
V_378 ;
break;
}
* V_373 = V_754 ;
* V_377 = V_755 ;
break;
}
}
static int F_205 ( struct V_4 * V_5 , T_1 V_756 , T_1 V_343 )
{
int V_75 = 0 ;
T_1 V_7 , V_757 ;
V_757 = V_758 ;
V_757 |= F_206 ( V_756 ) & V_759 ;
V_757 |= F_112 ( V_343 ) ;
V_75 = F_59 ( V_5 , V_304 , V_757 ) ;
if ( V_75 )
goto V_186;
if ( ! ( V_5 -> V_178 & V_393 ) ) {
V_757 = F_207 ( V_756 ) ;
if ( F_77 ( V_5 ) == V_760 ||
F_77 ( V_5 ) == V_761 )
V_757 |= V_495 | V_496 ;
V_75 = F_59 ( V_5 , V_180 , V_757 ) ;
if ( V_75 )
goto V_186;
}
if ( ! ( V_5 -> V_178 & V_339 ) )
goto V_186;
F_46 ( V_465 ,
F_33 ( V_465 ) & ~ V_476 ) ;
V_75 = F_66 ( V_5 , true ) ;
if ( ! V_75 ) {
T_1 V_762 ;
V_7 = 0 ;
if ( V_756 & V_710 )
V_7 |= V_763 ;
if ( V_756 & V_764 )
V_7 |= V_765 ;
if ( ! V_5 -> V_453 . V_463 ) {
V_7 = 0 ;
V_5 -> V_453 . V_464 = 0 ;
} else {
V_5 -> V_453 . V_464 = V_756 &
( V_710 |
V_764 ) ;
}
V_75 = F_60 ( V_5 , V_455 , V_462 , V_7 ) ;
if ( V_75 )
V_7 = 0 ;
switch ( F_30 ( V_5 ) ) {
case V_477 :
case V_766 :
case V_668 :
case V_478 :
if ( V_7 )
V_7 = V_479 |
V_480 |
V_767 ;
F_63 ( V_5 , V_475 , V_7 ) ;
case V_534 :
case V_768 :
if ( ! F_62 ( V_5 , V_769 , & V_7 ) )
F_63 ( V_5 , V_769 , V_7 |
V_770 ) ;
}
V_762 = F_66 ( V_5 , false ) ;
if ( ! V_75 )
V_75 = V_762 ;
}
V_186:
return V_75 ;
}
static void F_208 ( struct V_4 * V_5 )
{
if ( V_5 -> V_330 . V_353 == V_358 ||
( V_5 -> V_178 & V_400 ) ) {
T_1 V_342 , V_771 ;
if ( ( V_5 -> V_178 & V_400 ) &&
! ( V_5 -> V_178 & V_570 ) ) {
V_342 = V_707 |
V_711 ;
if ( F_23 ( V_5 , V_708 ) )
V_342 |= V_709 |
V_710 ;
if ( V_5 -> V_178 & V_772 ) {
if ( ! ( V_5 -> V_178 &
V_773 ) )
V_342 |= V_774 ;
V_342 |= V_764 ;
}
V_771 = V_337 | V_338 ;
} else {
V_342 = V_5 -> V_330 . V_399 ;
if ( V_5 -> V_178 & V_393 )
V_342 &= ~ ( V_774 |
V_764 ) ;
V_771 = V_5 -> V_330 . V_343 ;
}
F_205 ( V_5 , V_342 , V_771 ) ;
if ( ( V_5 -> V_178 & V_400 ) &&
( V_5 -> V_178 & V_570 ) ) {
return;
}
F_59 ( V_5 , V_204 ,
V_577 | V_578 ) ;
} else {
int V_42 ;
T_1 V_775 , V_776 ;
V_5 -> V_330 . V_331 = V_5 -> V_330 . V_373 ;
V_5 -> V_330 . V_334 = V_5 -> V_330 . V_377 ;
if ( F_30 ( V_5 ) == V_549 ) {
F_59 ( V_5 , V_304 , V_759 ) ;
}
V_775 = 0 ;
switch ( V_5 -> V_330 . V_373 ) {
default:
case V_374 :
break;
case V_333 :
V_775 |= V_777 ;
break;
case V_332 :
V_775 |= V_494 ;
break;
}
if ( V_5 -> V_330 . V_377 == V_335 )
V_775 |= V_493 ;
if ( ! F_57 ( V_5 , V_204 , & V_776 ) &&
( V_775 != V_776 ) ) {
F_59 ( V_5 , V_204 , V_778 ) ;
for ( V_42 = 0 ; V_42 < 1500 ; V_42 ++ ) {
T_1 V_597 ;
F_24 ( 10 ) ;
if ( F_57 ( V_5 , V_303 , & V_597 ) ||
F_57 ( V_5 , V_303 , & V_597 ) )
continue;
if ( ! ( V_597 & V_779 ) ) {
F_24 ( 40 ) ;
break;
}
}
F_59 ( V_5 , V_204 , V_775 ) ;
F_24 ( 40 ) ;
}
}
}
static int F_209 ( struct V_4 * V_5 )
{
int V_75 ;
T_1 V_7 ;
V_75 = F_57 ( V_5 , V_204 , & V_7 ) ;
if ( V_75 )
goto V_186;
if ( ! ( V_7 & V_577 ) ) {
V_5 -> V_330 . V_353 = V_780 ;
V_5 -> V_330 . V_399 = 0 ;
F_86 ( V_5 , V_359 ) ;
V_75 = - V_210 ;
switch ( V_7 & ( V_494 | V_777 ) ) {
case 0 :
if ( V_5 -> V_178 & V_360 )
goto V_186;
V_5 -> V_330 . V_373 = V_374 ;
break;
case V_777 :
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
V_5 -> V_330 . V_399 = V_706 ;
F_84 ( V_5 , V_359 ) ;
if ( ! ( V_5 -> V_178 & V_360 ) ) {
T_1 V_342 ;
V_75 = F_57 ( V_5 , V_304 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_342 = F_210 ( V_7 & V_759 ) ;
V_5 -> V_330 . V_399 |= V_342 | V_704 ;
V_5 -> V_330 . V_343 = F_104 ( V_7 ) ;
} else {
V_5 -> V_330 . V_399 |= V_781 ;
}
if ( ! ( V_5 -> V_178 & V_393 ) ) {
T_1 V_342 ;
if ( ! ( V_5 -> V_178 & V_360 ) ) {
V_75 = F_57 ( V_5 , V_180 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_342 = F_211 ( V_7 ) ;
} else {
V_75 = F_57 ( V_5 , V_304 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_342 = F_106 ( V_7 ) ;
V_5 -> V_330 . V_343 = V_342 ;
V_7 &= ( V_782 | V_783 ) ;
V_342 = F_212 ( V_7 ) ;
}
V_5 -> V_330 . V_399 |= V_342 ;
}
V_186:
return V_75 ;
}
static int F_213 ( struct V_4 * V_5 )
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
static bool F_214 ( struct V_4 * V_5 )
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
static bool F_215 ( struct V_4 * V_5 , T_1 * V_350 )
{
T_1 V_784 , V_785 , V_399 ;
V_399 = V_5 -> V_330 . V_399 ;
V_785 = F_206 ( V_399 ) & V_759 ;
V_784 = V_759 ;
if ( V_5 -> V_330 . V_334 == V_335 ) {
V_785 |= F_112 ( V_5 -> V_330 . V_343 ) ;
V_784 |= V_344 | V_345 ;
}
if ( F_57 ( V_5 , V_304 , V_350 ) )
return false ;
if ( ( * V_350 & V_784 ) != V_785 )
return false ;
if ( ! ( V_5 -> V_178 & V_393 ) ) {
T_1 V_786 ;
V_785 = F_207 ( V_399 ) ;
if ( F_57 ( V_5 , V_180 , & V_786 ) )
return false ;
if ( V_785 &&
( F_77 ( V_5 ) == V_760 ||
F_77 ( V_5 ) == V_761 ) ) {
V_785 |= V_495 | V_496 ;
V_786 &= ( V_787 | V_788 |
V_495 | V_496 ) ;
} else {
V_786 &= ( V_787 | V_788 ) ;
}
if ( V_786 != V_785 )
return false ;
}
return true ;
}
static bool F_216 ( struct V_4 * V_5 , T_1 * V_351 )
{
T_1 V_789 = 0 ;
if ( ! ( V_5 -> V_178 & V_393 ) ) {
T_1 V_7 ;
if ( F_57 ( V_5 , V_307 , & V_7 ) )
return false ;
V_789 = F_217 ( V_7 ) ;
}
if ( F_57 ( V_5 , V_305 , V_351 ) )
return false ;
V_789 |= F_218 ( * V_351 ) ;
V_5 -> V_330 . V_370 = V_789 ;
return true ;
}
static bool F_219 ( struct V_4 * V_5 , bool V_790 )
{
if ( V_790 != V_5 -> V_341 ) {
if ( V_790 ) {
F_220 ( V_5 -> V_111 ) ;
} else {
F_141 ( V_5 -> V_111 ) ;
if ( V_5 -> V_178 & V_306 )
V_5 -> V_178 &= ~ V_791 ;
}
F_100 ( V_5 ) ;
return true ;
}
return false ;
}
static void F_221 ( struct V_4 * V_5 )
{
F_46 ( V_792 , 0 ) ;
F_31 ( V_793 ,
V_794 |
V_795 |
V_796 |
V_797 ) ;
F_24 ( 40 ) ;
}
static void F_222 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_7 = V_798 |
V_799 ;
if ( F_77 ( V_5 ) == V_328 )
V_7 |= V_800 ;
F_31 ( V_801 , V_7 ) ;
F_31 ( V_474 ,
V_802 ) ;
V_7 = V_803 |
( V_5 -> V_453 . V_466 ? V_467 : 0 ) |
V_804 |
V_805 ;
if ( F_30 ( V_5 ) != V_477 )
V_7 |= V_806 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_807 ;
F_31 ( V_465 , V_5 -> V_453 . V_463 ? V_7 : 0 ) ;
F_31 ( V_469 ,
V_808 |
( V_5 -> V_453 . V_468 & 0xffff ) ) ;
F_31 ( V_809 ,
V_810 |
V_811 ) ;
}
static int F_223 ( struct V_4 * V_5 , bool V_812 )
{
bool V_470 ;
T_1 V_813 , V_7 ;
T_1 V_369 , V_370 ;
T_3 V_814 ;
T_4 V_815 ;
int V_42 , V_75 ;
F_221 ( V_5 ) ;
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
F_57 ( V_5 , V_303 , & V_813 ) ;
if ( ! F_57 ( V_5 , V_303 , & V_813 ) &&
! ( V_813 & V_779 ) )
V_812 = true ;
}
if ( V_812 )
F_144 ( V_5 ) ;
if ( ( V_5 -> V_216 & V_401 ) == V_402 ) {
F_57 ( V_5 , V_303 , & V_813 ) ;
if ( F_57 ( V_5 , V_303 , & V_813 ) ||
! F_23 ( V_5 , V_563 ) )
V_813 = 0 ;
if ( ! ( V_813 & V_779 ) ) {
V_75 = F_213 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_57 ( V_5 , V_303 , & V_813 ) ;
for ( V_42 = 0 ; V_42 < 1000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_303 , & V_813 ) &&
( V_813 & V_779 ) ) {
F_24 ( 40 ) ;
break;
}
}
if ( ( V_5 -> V_216 & V_816 ) ==
V_817 &&
! ( V_813 & V_779 ) &&
V_5 -> V_330 . V_331 == V_332 ) {
V_75 = F_144 ( V_5 ) ;
if ( ! V_75 )
V_75 = F_213 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
}
} else if ( F_77 ( V_5 ) == V_760 ||
F_77 ( V_5 ) == V_761 ) {
F_59 ( V_5 , 0x15 , 0x0a75 ) ;
F_59 ( V_5 , V_199 , 0x8c68 ) ;
F_59 ( V_5 , V_199 , 0x8d68 ) ;
F_59 ( V_5 , V_199 , 0x8c68 ) ;
}
F_57 ( V_5 , V_818 , & V_7 ) ;
F_57 ( V_5 , V_818 , & V_7 ) ;
if ( V_5 -> V_178 & V_819 )
F_59 ( V_5 , V_820 , ~ V_821 ) ;
else if ( ! ( V_5 -> V_178 & V_179 ) )
F_59 ( V_5 , V_820 , ~ 0 ) ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) {
if ( V_5 -> V_564 == V_822 )
F_59 ( V_5 , V_492 ,
V_823 ) ;
else
F_59 ( V_5 , V_492 , 0 ) ;
}
V_470 = false ;
V_814 = V_754 ;
V_815 = V_755 ;
V_5 -> V_178 &= ~ V_824 ;
V_5 -> V_330 . V_370 = 0 ;
if ( V_5 -> V_178 & V_825 ) {
V_75 = F_64 ( V_5 ,
V_826 ,
& V_7 ) ;
if ( ! V_75 && ! ( V_7 & ( 1 << 10 ) ) ) {
F_65 ( V_5 ,
V_826 ,
V_7 | ( 1 << 10 ) ) ;
goto V_827;
}
}
V_813 = 0 ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_57 ( V_5 , V_303 , & V_813 ) ;
if ( ! F_57 ( V_5 , V_303 , & V_813 ) &&
( V_813 & V_779 ) )
break;
F_24 ( 40 ) ;
}
if ( V_813 & V_779 ) {
T_1 V_828 , V_775 ;
F_57 ( V_5 , V_829 , & V_828 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_829 , & V_828 ) &&
V_828 )
break;
}
F_204 ( V_5 , V_828 ,
& V_814 ,
& V_815 ) ;
V_775 = 0 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_57 ( V_5 , V_204 , & V_775 ) ;
if ( F_57 ( V_5 , V_204 , & V_775 ) )
continue;
if ( V_775 && V_775 != 0x7fff )
break;
F_24 ( 10 ) ;
}
V_369 = 0 ;
V_370 = 0 ;
V_5 -> V_330 . V_331 = V_814 ;
V_5 -> V_330 . V_334 = V_815 ;
if ( V_5 -> V_330 . V_353 == V_358 ) {
bool V_830 = F_214 ( V_5 ) ;
if ( ( V_775 & V_577 ) &&
V_830 &&
F_215 ( V_5 , & V_369 ) &&
F_216 ( V_5 , & V_370 ) )
V_470 = true ;
if ( ! V_830 &&
( V_5 -> V_178 & V_570 ) &&
! V_812 ) {
F_222 ( V_5 ) ;
F_144 ( V_5 ) ;
}
} else {
if ( ! ( V_775 & V_577 ) &&
V_5 -> V_330 . V_373 == V_814 &&
V_5 -> V_330 . V_377 == V_815 ) {
V_470 = true ;
}
}
if ( V_470 &&
V_5 -> V_330 . V_334 == V_335 ) {
T_1 V_161 , V_44 ;
if ( V_5 -> V_178 & V_179 ) {
V_161 = V_831 ;
V_44 = V_832 ;
} else {
V_161 = V_833 ;
V_44 = V_834 ;
}
if ( ! F_57 ( V_5 , V_161 , & V_7 ) && ( V_7 & V_44 ) )
V_5 -> V_178 |= V_824 ;
F_108 ( V_5 , V_369 , V_370 ) ;
}
}
V_827:
if ( ! V_470 || ( V_5 -> V_178 & V_400 ) ) {
F_208 ( V_5 ) ;
if ( F_23 ( V_5 , V_265 ) ) {
V_470 = true ;
V_814 = V_332 ;
V_815 = V_335 ;
V_5 -> V_330 . V_331 = V_814 ;
V_5 -> V_330 . V_334 = V_815 ;
}
F_57 ( V_5 , V_303 , & V_813 ) ;
if ( ( ! F_57 ( V_5 , V_303 , & V_813 ) && ( V_813 & V_779 ) ) ||
( V_5 -> V_368 & V_835 ) )
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
if ( F_23 ( V_5 , V_836 ) ) {
T_1 V_564 = F_33 ( V_728 ) ;
V_564 &= ~ ( V_837 | V_838 ) ;
if ( V_5 -> V_330 . V_331 == V_374 )
V_564 |= V_839 ;
else if ( V_5 -> V_330 . V_331 == V_333 )
V_564 |= ( V_839 |
V_838 ) ;
else if ( V_5 -> V_330 . V_331 == V_332 )
V_564 |= ( V_839 |
V_837 ) ;
F_46 ( V_728 , V_564 ) ;
F_24 ( 40 ) ;
}
V_5 -> V_368 &= ~ V_372 ;
if ( V_5 -> V_330 . V_334 == V_378 )
V_5 -> V_368 |= V_372 ;
if ( F_30 ( V_5 ) == V_537 ) {
if ( V_470 &&
F_154 ( V_5 , V_5 -> V_330 . V_331 ) )
V_5 -> V_368 |= V_726 ;
else
V_5 -> V_368 &= ~ V_726 ;
}
if ( ( V_5 -> V_216 & V_401 ) == V_566 &&
F_77 ( V_5 ) == V_840 ) {
V_5 -> V_164 |= V_165 ;
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
}
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
F_134 ( V_5 , V_470 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
F_31 ( V_792 , 0 ) ;
} else {
F_31 ( V_792 , V_841 ) ;
}
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_537 &&
V_470 &&
V_5 -> V_330 . V_331 == V_332 &&
( F_23 ( V_5 , V_842 ) || F_23 ( V_5 , V_843 ) ) ) {
F_24 ( 120 ) ;
F_31 ( V_793 ,
( V_794 |
V_795 ) ) ;
F_24 ( 40 ) ;
F_29 ( V_5 ,
V_315 ,
V_844 ) ;
}
if ( F_23 ( V_5 , V_700 ) ) {
if ( V_5 -> V_330 . V_331 == V_333 ||
V_5 -> V_330 . V_331 == V_374 )
F_224 ( V_5 -> V_12 , V_701 ,
V_702 ) ;
else
F_200 ( V_5 -> V_12 , V_701 ,
V_702 ) ;
}
F_219 ( V_5 , V_470 ) ;
return 0 ;
}
static int F_225 ( struct V_4 * V_5 ,
struct V_845 * V_846 )
{
T_3 V_343 ;
unsigned long V_847 ;
T_1 V_848 ;
int V_56 ;
if ( V_846 -> V_849 == V_850 ) {
V_846 -> V_851 = 0 ;
V_846 -> V_852 = 0 ;
V_846 -> V_853 = 0 ;
V_846 -> V_854 = 0 ;
V_846 -> V_855 = 0 ;
V_846 -> V_856 = 0 ;
V_846 -> V_857 = 0 ;
V_846 -> V_858 = 0 ;
}
V_846 -> V_853 ++ ;
if ( F_33 ( V_793 ) & V_859 ) {
V_848 = F_33 ( V_860 ) ;
if ( V_848 != V_846 -> V_854 ) {
V_846 -> V_854 = V_848 ;
V_846 -> V_856 = 0 ;
V_846 -> V_855 = 0 ;
} else {
if ( ++ V_846 -> V_855 > 1 ) {
V_846 -> V_856 = 1 ;
V_846 -> V_854 = V_848 ;
}
}
if ( V_848 & V_861 )
V_846 -> V_858 = 1 ;
else
V_846 -> V_858 = 0 ;
V_846 -> V_857 = 0 ;
} else {
V_846 -> V_857 = 1 ;
V_846 -> V_854 = 0 ;
V_846 -> V_855 = 0 ;
V_846 -> V_856 = 0 ;
V_846 -> V_858 = 0 ;
V_848 = 0 ;
}
V_846 -> V_851 = V_848 ;
V_56 = V_862 ;
switch ( V_846 -> V_849 ) {
case V_850 :
if ( V_846 -> V_10 & ( V_863 | V_864 ) )
V_846 -> V_849 = V_865 ;
case V_865 :
V_846 -> V_10 &= ~ ( V_866 | V_867 ) ;
if ( V_846 -> V_10 & V_863 ) {
V_846 -> V_852 = 0 ;
V_846 -> V_853 = 0 ;
V_846 -> V_854 = 0 ;
V_846 -> V_855 = 0 ;
V_846 -> V_856 = 0 ;
V_846 -> V_857 = 0 ;
V_846 -> V_858 = 0 ;
V_846 -> V_849 = V_868 ;
} else {
V_846 -> V_849 = V_869 ;
}
break;
case V_868 :
V_846 -> V_852 = V_846 -> V_853 ;
V_846 -> V_10 &= ~ ( V_870 ) ;
V_846 -> V_871 = 0 ;
F_46 ( V_872 , 0 ) ;
V_5 -> V_368 |= V_873 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
V_56 = V_874 ;
V_846 -> V_849 = V_875 ;
case V_875 :
V_847 = V_846 -> V_853 - V_846 -> V_852 ;
if ( V_847 > V_876 )
V_846 -> V_849 = V_877 ;
else
V_56 = V_874 ;
break;
case V_869 :
V_56 = V_878 ;
break;
case V_877 :
V_846 -> V_10 &= ~ ( V_879 ) ;
V_846 -> V_871 = V_880 ;
V_343 = F_105 ( V_5 -> V_330 . V_343 ) ;
if ( V_343 & V_348 )
V_846 -> V_871 |= V_881 ;
if ( V_343 & V_349 )
V_846 -> V_871 |= V_882 ;
F_46 ( V_872 , V_846 -> V_871 ) ;
V_5 -> V_368 |= V_873 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
V_846 -> V_849 = V_883 ;
break;
case V_883 :
if ( V_846 -> V_856 != 0 && V_846 -> V_851 != 0 )
V_846 -> V_849 = V_884 ;
break;
case V_884 :
V_846 -> V_871 |= V_861 ;
F_46 ( V_872 , V_846 -> V_871 ) ;
V_5 -> V_368 |= V_873 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
V_846 -> V_849 = V_885 ;
case V_885 :
if ( V_846 -> V_858 != 0 ) {
if ( ( V_846 -> V_851 & ~ V_861 ) ==
( V_846 -> V_854 & ~ V_861 ) ) {
V_846 -> V_849 = V_886 ;
} else {
V_846 -> V_849 = V_865 ;
}
} else if ( V_846 -> V_856 != 0 &&
V_846 -> V_851 == 0 ) {
V_846 -> V_849 = V_865 ;
}
break;
case V_886 :
if ( V_846 -> V_851 & V_887 ) {
V_56 = V_888 ;
break;
}
V_846 -> V_10 &= ~ ( V_889 |
V_890 |
V_891 |
V_892 |
V_893 |
V_894 |
V_895 |
V_896 |
V_897 ) ;
if ( V_846 -> V_851 & V_880 )
V_846 -> V_10 |= V_889 ;
if ( V_846 -> V_851 & V_898 )
V_846 -> V_10 |= V_890 ;
if ( V_846 -> V_851 & V_881 )
V_846 -> V_10 |= V_891 ;
if ( V_846 -> V_851 & V_882 )
V_846 -> V_10 |= V_892 ;
if ( V_846 -> V_851 & V_899 )
V_846 -> V_10 |= V_893 ;
if ( V_846 -> V_851 & V_900 )
V_846 -> V_10 |= V_894 ;
if ( V_846 -> V_851 & V_901 )
V_846 -> V_10 |= V_895 ;
V_846 -> V_852 = V_846 -> V_853 ;
V_846 -> V_10 ^= ( V_879 ) ;
if ( V_846 -> V_851 & 0x0008 )
V_846 -> V_10 |= V_896 ;
if ( V_846 -> V_851 & V_901 )
V_846 -> V_10 |= V_897 ;
V_846 -> V_10 |= V_867 ;
V_846 -> V_849 = V_902 ;
V_56 = V_874 ;
break;
case V_902 :
if ( V_846 -> V_856 != 0 &&
V_846 -> V_851 == 0 ) {
V_846 -> V_849 = V_865 ;
break;
}
V_847 = V_846 -> V_853 - V_846 -> V_852 ;
if ( V_847 > V_876 ) {
if ( ! ( V_846 -> V_10 & ( V_895 ) ) ) {
V_846 -> V_849 = V_903 ;
} else {
if ( ( V_846 -> V_871 & V_901 ) == 0 &&
! ( V_846 -> V_10 & V_897 ) ) {
V_846 -> V_849 = V_903 ;
} else {
V_56 = V_888 ;
}
}
}
break;
case V_903 :
V_846 -> V_852 = V_846 -> V_853 ;
V_5 -> V_368 &= ~ V_873 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
V_846 -> V_849 = V_904 ;
V_56 = V_874 ;
break;
case V_904 :
if ( V_846 -> V_856 != 0 &&
V_846 -> V_851 == 0 ) {
V_846 -> V_849 = V_865 ;
break;
}
V_847 = V_846 -> V_853 - V_846 -> V_852 ;
if ( V_847 > V_876 ) {
V_846 -> V_849 = V_905 ;
}
break;
case V_905 :
V_846 -> V_10 |= ( V_866 | V_906 ) ;
V_56 = V_878 ;
break;
case V_907 :
break;
case V_908 :
break;
default:
V_56 = V_888 ;
break;
}
return V_56 ;
}
static int F_226 ( struct V_4 * V_5 , T_1 * V_909 , T_1 * V_910 )
{
int V_626 = 0 ;
struct V_845 V_911 ;
int V_57 = V_888 ;
unsigned int V_912 ;
T_1 V_597 ;
F_31 ( V_872 , 0 ) ;
V_597 = V_5 -> V_368 & ~ V_371 ;
F_31 ( V_383 , V_597 | V_376 ) ;
F_24 ( 40 ) ;
F_31 ( V_383 , V_5 -> V_368 | V_873 ) ;
F_24 ( 40 ) ;
memset ( & V_911 , 0 , sizeof( V_911 ) ) ;
V_911 . V_10 |= V_863 ;
V_911 . V_849 = V_850 ;
V_911 . V_853 = 0 ;
V_912 = 0 ;
while ( ++ V_912 < 195000 ) {
V_57 = F_225 ( V_5 , & V_911 ) ;
if ( V_57 == V_878 || V_57 == V_888 )
break;
F_24 ( 1 ) ;
}
V_5 -> V_368 &= ~ V_873 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
* V_909 = V_911 . V_871 ;
* V_910 = V_911 . V_10 ;
if ( V_57 == V_878 &&
( V_911 . V_10 & ( V_866 | V_906 |
V_889 ) ) )
V_626 = 1 ;
return V_626 ;
}
static void F_227 ( struct V_4 * V_5 )
{
T_1 V_913 = F_33 ( V_793 ) ;
int V_42 ;
if ( F_23 ( V_5 , V_563 ) &&
! ( V_913 & V_914 ) )
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
static bool F_228 ( struct V_4 * V_5 , T_1 V_913 )
{
T_3 V_343 ;
bool V_470 ;
T_1 V_571 , V_915 ;
T_1 V_573 , V_916 ;
int V_917 , V_918 ;
V_573 = 0 ;
V_916 = 0 ;
V_917 = 0 ;
V_918 = 1 ;
V_470 = false ;
if ( F_77 ( V_5 ) != V_919 &&
F_77 ( V_5 ) != V_920 ) {
V_917 = 1 ;
if ( F_33 ( V_921 ) & V_922 )
V_918 = 0 ;
V_573 = F_33 ( V_574 ) & 0x00f06fff ;
}
V_571 = F_33 ( V_572 ) ;
if ( V_5 -> V_330 . V_353 != V_358 ) {
if ( V_571 & V_575 ) {
if ( V_917 ) {
T_1 V_7 = V_573 ;
if ( V_918 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_574 , V_7 ) ;
}
F_31 ( V_572 , V_923 ) ;
}
if ( V_913 & V_914 ) {
F_108 ( V_5 , 0 , 0 ) ;
V_470 = true ;
}
goto V_503;
}
V_916 = V_575 | V_923 ;
V_343 = F_105 ( V_5 -> V_330 . V_343 ) ;
if ( V_343 & V_348 )
V_916 |= V_924 ;
if ( V_343 & V_349 )
V_916 |= V_925 ;
if ( V_571 != V_916 ) {
if ( ( V_5 -> V_178 & V_791 ) &&
V_5 -> V_926 &&
( ( V_913 & ( V_914 |
V_859 ) ) ==
V_914 ) ) {
V_5 -> V_926 -- ;
V_470 = true ;
goto V_503;
}
V_927:
if ( V_917 )
F_31 ( V_574 , V_573 | 0xc011000 ) ;
F_31 ( V_572 , V_916 | V_576 ) ;
F_24 ( 5 ) ;
F_31 ( V_572 , V_916 ) ;
V_5 -> V_926 = V_928 ;
V_5 -> V_178 &= ~ V_791 ;
} else if ( V_913 & ( V_914 |
V_929 ) ) {
V_915 = F_33 ( V_260 ) ;
V_913 = F_33 ( V_793 ) ;
if ( ( V_915 & V_930 ) &&
( V_913 & V_914 ) ) {
T_1 V_931 = 0 , V_932 = 0 ;
if ( V_571 & V_924 )
V_931 |= V_348 ;
if ( V_571 & V_925 )
V_931 |= V_349 ;
if ( V_915 & V_933 )
V_932 |= V_934 ;
if ( V_915 & V_935 )
V_932 |= V_936 ;
V_5 -> V_330 . V_370 =
F_212 ( V_932 ) ;
F_108 ( V_5 , V_931 , V_932 ) ;
V_470 = true ;
V_5 -> V_926 = 0 ;
V_5 -> V_178 &= ~ V_791 ;
} else if ( ! ( V_915 & V_930 ) ) {
if ( V_5 -> V_926 )
V_5 -> V_926 -- ;
else {
if ( V_917 ) {
T_1 V_7 = V_573 ;
if ( V_918 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_574 , V_7 ) ;
}
F_31 ( V_572 , V_923 ) ;
F_24 ( 40 ) ;
V_913 = F_33 ( V_793 ) ;
if ( ( V_913 & V_914 ) &&
! ( V_913 & V_859 ) ) {
F_108 ( V_5 , 0 , 0 ) ;
V_470 = true ;
V_5 -> V_178 |=
V_791 ;
V_5 -> V_926 =
V_937 ;
} else
goto V_927;
}
}
} else {
V_5 -> V_926 = V_928 ;
V_5 -> V_178 &= ~ V_791 ;
}
V_503:
return V_470 ;
}
static bool F_229 ( struct V_4 * V_5 , T_1 V_913 )
{
bool V_470 = false ;
if ( ! ( V_913 & V_914 ) )
goto V_503;
if ( V_5 -> V_330 . V_353 == V_358 ) {
T_1 V_909 , V_910 ;
int V_42 ;
if ( F_226 ( V_5 , & V_909 , & V_910 ) ) {
T_1 V_931 = 0 , V_932 = 0 ;
if ( V_909 & V_881 )
V_931 |= V_348 ;
if ( V_909 & V_882 )
V_931 |= V_349 ;
if ( V_910 & V_891 )
V_932 |= V_934 ;
if ( V_910 & V_892 )
V_932 |= V_936 ;
V_5 -> V_330 . V_370 =
F_212 ( V_932 ) ;
F_108 ( V_5 , V_931 , V_932 ) ;
V_470 = true ;
}
for ( V_42 = 0 ; V_42 < 30 ; V_42 ++ ) {
F_24 ( 20 ) ;
F_31 ( V_793 ,
( V_794 |
V_795 ) ) ;
F_24 ( 40 ) ;
if ( ( F_33 ( V_793 ) &
( V_794 |
V_795 ) ) == 0 )
break;
}
V_913 = F_33 ( V_793 ) ;
if ( ! V_470 &&
( V_913 & V_914 ) &&
! ( V_913 & V_859 ) )
V_470 = true ;
} else {
F_108 ( V_5 , 0 , 0 ) ;
V_470 = true ;
F_31 ( V_383 , ( V_5 -> V_368 | V_873 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
}
V_503:
return V_470 ;
}
static int F_230 ( struct V_4 * V_5 , bool V_812 )
{
T_1 V_938 ;
T_3 V_939 ;
T_4 V_940 ;
T_1 V_913 ;
bool V_470 ;
int V_42 ;
V_938 = V_5 -> V_330 . V_336 ;
V_939 = V_5 -> V_330 . V_331 ;
V_940 = V_5 -> V_330 . V_334 ;
if ( ! F_23 ( V_5 , V_941 ) &&
V_5 -> V_341 &&
F_23 ( V_5 , V_563 ) ) {
V_913 = F_33 ( V_793 ) ;
V_913 &= ( V_914 |
V_929 |
V_795 |
V_859 ) ;
if ( V_913 == ( V_914 |
V_929 ) ) {
F_31 ( V_793 , ( V_794 |
V_795 ) ) ;
return 0 ;
}
}
F_31 ( V_872 , 0 ) ;
V_5 -> V_368 &= ~ ( V_371 | V_372 ) ;
V_5 -> V_368 |= V_727 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
if ( V_5 -> V_216 == V_942 )
F_227 ( V_5 ) ;
F_31 ( V_792 , V_841 ) ;
F_24 ( 40 ) ;
V_470 = false ;
V_5 -> V_330 . V_370 = 0 ;
V_913 = F_33 ( V_793 ) ;
if ( F_23 ( V_5 , V_941 ) )
V_470 = F_228 ( V_5 , V_913 ) ;
else
V_470 = F_229 ( V_5 , V_913 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 =
( V_135 |
( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & ~ V_144 ) ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_31 ( V_793 , ( V_794 |
V_795 ) ) ;
F_24 ( 5 ) ;
if ( ( F_33 ( V_793 ) & ( V_794 |
V_795 |
V_797 ) ) == 0 )
break;
}
V_913 = F_33 ( V_793 ) ;
if ( ( V_913 & V_914 ) == 0 ) {
V_470 = false ;
if ( V_5 -> V_330 . V_353 == V_358 &&
V_5 -> V_926 == 0 ) {
F_31 ( V_383 , ( V_5 -> V_368 |
V_873 ) ) ;
F_24 ( 1 ) ;
F_31 ( V_383 , V_5 -> V_368 ) ;
}
}
if ( V_470 ) {
V_5 -> V_330 . V_331 = V_332 ;
V_5 -> V_330 . V_334 = V_335 ;
F_46 ( V_728 , ( V_5 -> V_564 |
V_839 |
V_837 ) ) ;
} else {
V_5 -> V_330 . V_331 = V_754 ;
V_5 -> V_330 . V_334 = V_755 ;
F_46 ( V_728 , ( V_5 -> V_564 |
V_839 |
V_943 ) ) ;
}
if ( ! F_219 ( V_5 , V_470 ) ) {
T_1 V_944 = V_5 -> V_330 . V_336 ;
if ( V_938 != V_944 ||
V_939 != V_5 -> V_330 . V_331 ||
V_940 != V_5 -> V_330 . V_334 )
F_100 ( V_5 ) ;
}
return 0 ;
}
static int F_231 ( struct V_4 * V_5 , bool V_812 )
{
int V_75 = 0 ;
T_1 V_813 , V_775 ;
T_3 V_814 = V_754 ;
T_4 V_815 = V_755 ;
bool V_470 = false ;
T_1 V_931 , V_932 , V_945 ;
if ( ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ) &&
! F_57 ( V_5 , V_946 , & V_945 ) &&
( V_945 & V_947 ) ) {
if ( V_812 )
F_144 ( V_5 ) ;
V_5 -> V_368 &= ~ V_371 ;
if ( ! ( V_945 & V_948 ) ) {
V_5 -> V_368 |= V_376 ;
} else {
V_470 = true ;
if ( V_945 & V_949 ) {
V_814 = V_332 ;
V_5 -> V_368 |= V_376 ;
} else if ( V_945 & V_950 ) {
V_814 = V_333 ;
V_5 -> V_368 |= V_375 ;
} else {
V_814 = V_374 ;
V_5 -> V_368 |= V_375 ;
}
if ( V_945 & V_951 )
V_815 = V_335 ;
else
V_815 = V_378 ;
}
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
F_221 ( V_5 ) ;
goto V_952;
}
V_5 -> V_368 |= V_376 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
F_221 ( V_5 ) ;
if ( V_812 )
F_144 ( V_5 ) ;
V_5 -> V_330 . V_370 = 0 ;
V_75 |= F_57 ( V_5 , V_303 , & V_813 ) ;
V_75 |= F_57 ( V_5 , V_303 , & V_813 ) ;
if ( F_30 ( V_5 ) == V_549 ) {
if ( F_33 ( V_953 ) & V_954 )
V_813 |= V_779 ;
else
V_813 &= ~ V_779 ;
}
V_75 |= F_57 ( V_5 , V_204 , & V_775 ) ;
if ( ( V_5 -> V_330 . V_353 == V_358 ) && ! V_812 &&
( V_5 -> V_178 & V_791 ) ) {
} else if ( V_5 -> V_330 . V_353 == V_358 ) {
T_1 V_342 , V_955 ;
V_75 |= F_57 ( V_5 , V_304 , & V_342 ) ;
V_955 = V_342 & ~ ( V_783 | V_782 |
V_348 |
V_349 |
V_956 ) ;
V_955 |= F_105 ( V_5 -> V_330 . V_343 ) ;
V_955 |= F_232 ( V_5 -> V_330 . V_399 ) ;
if ( ( V_955 != V_342 ) || ! ( V_775 & V_577 ) ) {
F_59 ( V_5 , V_304 , V_955 ) ;
V_775 |= V_577 | V_578 ;
F_59 ( V_5 , V_204 , V_775 ) ;
F_31 ( V_792 , V_841 ) ;
V_5 -> V_926 = V_957 ;
V_5 -> V_178 &= ~ V_791 ;
return V_75 ;
}
} else {
T_1 V_958 ;
V_775 &= ~ V_494 ;
V_958 = V_775 & ~ ( V_577 | V_493 ) ;
if ( V_5 -> V_330 . V_377 == V_335 )
V_958 |= V_493 ;
if ( V_958 != V_775 ) {
V_958 |= V_494 ;
if ( V_5 -> V_341 ) {
T_1 V_342 ;
V_75 |= F_57 ( V_5 , V_304 , & V_342 ) ;
V_342 &= ~ ( V_783 |
V_782 |
V_956 ) ;
F_59 ( V_5 , V_304 , V_342 ) ;
F_59 ( V_5 , V_204 , V_775 |
V_578 |
V_577 ) ;
F_24 ( 10 ) ;
F_140 ( V_5 ) ;
}
F_59 ( V_5 , V_204 , V_958 ) ;
V_775 = V_958 ;
V_75 |= F_57 ( V_5 , V_303 , & V_813 ) ;
V_75 |= F_57 ( V_5 , V_303 , & V_813 ) ;
if ( F_30 ( V_5 ) == V_549 ) {
if ( F_33 ( V_953 ) & V_954 )
V_813 |= V_779 ;
else
V_813 &= ~ V_779 ;
}
V_5 -> V_178 &= ~ V_791 ;
}
}
if ( V_813 & V_779 ) {
V_814 = V_332 ;
V_470 = true ;
if ( V_775 & V_493 )
V_815 = V_335 ;
else
V_815 = V_378 ;
V_931 = 0 ;
V_932 = 0 ;
if ( V_775 & V_577 ) {
T_1 V_959 ;
V_75 |= F_57 ( V_5 , V_304 , & V_931 ) ;
V_75 |= F_57 ( V_5 , V_305 , & V_932 ) ;
V_959 = V_931 & V_932 ;
if ( V_959 & ( V_782 |
V_783 ) ) {
if ( V_959 & V_783 )
V_815 = V_335 ;
else
V_815 = V_378 ;
V_5 -> V_330 . V_370 =
F_212 ( V_932 ) ;
} else if ( ! F_23 ( V_5 , 5780_CLASS ) ) {
} else {
V_470 = false ;
}
}
}
V_952:
if ( V_470 && V_815 == V_335 )
F_108 ( V_5 , V_931 , V_932 ) ;
V_5 -> V_368 &= ~ V_372 ;
if ( V_5 -> V_330 . V_334 == V_378 )
V_5 -> V_368 |= V_372 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
F_31 ( V_792 , V_841 ) ;
V_5 -> V_330 . V_331 = V_814 ;
V_5 -> V_330 . V_334 = V_815 ;
F_219 ( V_5 , V_470 ) ;
return V_75 ;
}
static void F_233 ( struct V_4 * V_5 )
{
if ( V_5 -> V_926 ) {
V_5 -> V_926 -- ;
return;
}
if ( ! V_5 -> V_341 &&
( V_5 -> V_330 . V_353 == V_358 ) ) {
T_1 V_775 ;
F_57 ( V_5 , V_204 , & V_775 ) ;
if ( V_775 & V_577 ) {
T_1 V_960 , V_961 ;
F_59 ( V_5 , V_199 , 0x7c00 ) ;
F_57 ( V_5 , V_199 , & V_960 ) ;
F_59 ( V_5 , V_189 ,
V_962 ) ;
F_57 ( V_5 , V_190 , & V_961 ) ;
F_57 ( V_5 , V_190 , & V_961 ) ;
if ( ( V_960 & 0x10 ) && ! ( V_961 & 0x20 ) ) {
V_775 &= ~ V_577 ;
V_775 |= V_494 | V_493 ;
F_59 ( V_5 , V_204 , V_775 ) ;
V_5 -> V_178 |= V_791 ;
}
}
} else if ( V_5 -> V_341 &&
( V_5 -> V_330 . V_353 == V_358 ) &&
( V_5 -> V_178 & V_791 ) ) {
T_1 V_961 ;
F_59 ( V_5 , V_189 ,
V_962 ) ;
F_57 ( V_5 , V_190 , & V_961 ) ;
if ( V_961 & 0x20 ) {
T_1 V_775 ;
F_57 ( V_5 , V_204 , & V_775 ) ;
F_59 ( V_5 , V_204 , V_775 | V_577 ) ;
V_5 -> V_178 &= ~ V_791 ;
}
}
}
static int F_201 ( struct V_4 * V_5 , bool V_812 )
{
T_1 V_7 ;
int V_75 ;
if ( V_5 -> V_178 & V_568 )
V_75 = F_230 ( V_5 , V_812 ) ;
else if ( V_5 -> V_178 & V_306 )
V_75 = F_231 ( V_5 , V_812 ) ;
else
V_75 = F_223 ( V_5 , V_812 ) ;
if ( F_146 ( V_5 ) == V_504 ) {
T_1 V_963 ;
V_7 = F_33 ( V_964 ) & V_965 ;
if ( V_7 == V_966 )
V_963 = 65 ;
else if ( V_7 == V_967 )
V_963 = 6 ;
else
V_963 = 12 ;
V_7 = F_33 ( V_498 ) & ~ V_968 ;
V_7 |= ( V_963 << V_969 ) ;
F_46 ( V_498 , V_7 ) ;
}
V_7 = ( 2 << V_388 ) |
( 6 << V_389 ) ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_768 )
V_7 |= F_33 ( V_387 ) &
( V_970 |
V_971 ) ;
if ( V_5 -> V_330 . V_331 == V_332 &&
V_5 -> V_330 . V_334 == V_378 )
F_46 ( V_387 , V_7 |
( 0xff << V_390 ) ) ;
else
F_46 ( V_387 , V_7 |
( 32 << V_390 ) ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
if ( V_5 -> V_341 ) {
F_46 ( V_972 ,
V_5 -> V_973 . V_974 ) ;
} else {
F_46 ( V_972 , 0 ) ;
}
}
if ( F_23 ( V_5 , V_975 ) ) {
V_7 = F_33 ( V_976 ) ;
if ( ! V_5 -> V_341 )
V_7 = ( V_7 & ~ V_977 ) |
V_5 -> V_978 ;
else
V_7 |= V_977 ;
F_46 ( V_976 , V_7 ) ;
}
return V_75 ;
}
static T_6 F_234 ( struct V_4 * V_5 )
{
T_6 V_979 = F_33 ( V_980 ) ;
return V_979 | ( T_6 ) F_33 ( V_981 ) << 32 ;
}
static void F_235 ( struct V_4 * V_5 , T_6 V_982 )
{
T_1 V_983 = F_33 ( V_984 ) ;
F_46 ( V_984 , V_983 | V_985 ) ;
F_46 ( V_980 , V_982 & 0xffffffff ) ;
F_46 ( V_981 , V_982 >> 32 ) ;
F_31 ( V_984 , V_983 | V_986 ) ;
}
static int F_236 ( struct V_365 * V_111 , struct V_987 * V_988 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_988 -> V_989 = V_990 |
V_991 |
V_992 ;
if ( F_23 ( V_5 , V_993 ) ) {
V_988 -> V_989 |= V_994 |
V_995 |
V_996 ;
}
if ( V_5 -> V_997 )
V_988 -> V_998 = F_237 ( V_5 -> V_997 ) ;
else
V_988 -> V_998 = - 1 ;
V_988 -> V_999 = ( 1 << V_1000 ) | ( 1 << V_1001 ) ;
V_988 -> V_1002 = ( 1 << V_1003 ) |
( 1 << V_1004 ) |
( 1 << V_1005 ) |
( 1 << V_1006 ) ;
return 0 ;
}
static int F_238 ( struct V_1007 * V_1008 , T_7 V_1009 )
{
struct V_4 * V_5 = F_239 ( V_1008 , struct V_4 , V_1010 ) ;
bool V_1011 = false ;
T_1 V_1012 = 0 ;
if ( V_1009 < 0 ) {
V_1011 = true ;
V_1009 = - V_1009 ;
}
V_1012 = F_240 ( ( T_6 ) V_1009 * ( 1 << 24 ) , 1000000000ULL ) &
V_1013 ;
F_241 ( V_5 , 0 ) ;
if ( V_1012 )
F_46 ( V_1014 ,
V_1015 |
( V_1011 ? V_1016 : 0 ) | V_1012 ) ;
else
F_46 ( V_1014 , 0 ) ;
F_242 ( V_5 ) ;
return 0 ;
}
static int F_243 ( struct V_1007 * V_1008 , T_8 V_847 )
{
struct V_4 * V_5 = F_239 ( V_1008 , struct V_4 , V_1010 ) ;
F_241 ( V_5 , 0 ) ;
V_5 -> V_1017 += V_847 ;
F_242 ( V_5 ) ;
return 0 ;
}
static int F_244 ( struct V_1007 * V_1008 , struct V_1018 * V_1019 )
{
T_6 V_1020 ;
T_1 V_1021 ;
struct V_4 * V_5 = F_239 ( V_1008 , struct V_4 , V_1010 ) ;
F_241 ( V_5 , 0 ) ;
V_1020 = F_234 ( V_5 ) ;
V_1020 += V_5 -> V_1017 ;
F_242 ( V_5 ) ;
V_1019 -> V_1022 = F_245 ( V_1020 , 1000000000 , & V_1021 ) ;
V_1019 -> V_1023 = V_1021 ;
return 0 ;
}
static int F_246 ( struct V_1007 * V_1008 ,
const struct V_1018 * V_1019 )
{
T_6 V_1020 ;
struct V_4 * V_5 = F_239 ( V_1008 , struct V_4 , V_1010 ) ;
V_1020 = F_247 ( V_1019 ) ;
F_241 ( V_5 , 0 ) ;
F_235 ( V_5 , V_1020 ) ;
V_5 -> V_1017 = 0 ;
F_242 ( V_5 ) ;
return 0 ;
}
static int F_248 ( struct V_1007 * V_1008 ,
struct V_1024 * V_1025 , int V_1026 )
{
struct V_4 * V_5 = F_239 ( V_1008 , struct V_4 , V_1010 ) ;
T_1 V_983 ;
int V_1027 = 0 ;
switch ( V_1025 -> type ) {
case V_1028 :
if ( V_1025 -> V_1029 . V_687 != 0 )
return - V_64 ;
F_241 ( V_5 , 0 ) ;
V_983 = F_33 ( V_984 ) ;
V_983 &= ~ V_1030 ;
if ( V_1026 ) {
T_6 V_1031 ;
V_1031 = V_1025 -> V_1029 . V_1032 . V_1033 * 1000000000ULL +
V_1025 -> V_1029 . V_1032 . V_1031 ;
if ( V_1025 -> V_1029 . V_1034 . V_1033 || V_1025 -> V_1029 . V_1034 . V_1031 ) {
F_143 ( V_5 -> V_111 ,
L_28 ) ;
V_1027 = - V_64 ;
goto V_1035;
}
if ( V_1031 & ( 1ULL << 63 ) ) {
F_143 ( V_5 -> V_111 ,
L_29 ) ;
V_1027 = - V_64 ;
goto V_1035;
}
F_46 ( V_1036 , ( V_1031 & 0xffffffff ) ) ;
F_46 ( V_1037 ,
V_1038 |
( ( V_1031 >> 32 ) & V_1039 ) ) ;
F_46 ( V_984 ,
V_983 | V_1040 ) ;
} else {
F_46 ( V_1037 , 0 ) ;
F_46 ( V_984 , V_983 ) ;
}
V_1035:
F_242 ( V_5 ) ;
return V_1027 ;
default:
break;
}
return - V_1041 ;
}
static void F_249 ( struct V_4 * V_5 , T_6 V_1042 ,
struct V_1043 * V_1044 )
{
memset ( V_1044 , 0 , sizeof( struct V_1043 ) ) ;
V_1044 -> V_1045 = F_250 ( ( V_1042 & V_1046 ) +
V_5 -> V_1017 ) ;
}
static void F_251 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_993 ) )
return;
F_235 ( V_5 , F_252 ( F_253 () ) ) ;
V_5 -> V_1017 = 0 ;
V_5 -> V_1010 = V_1047 ;
}
static void F_254 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_993 ) )
return;
F_235 ( V_5 , F_252 ( F_253 () ) + V_5 -> V_1017 ) ;
V_5 -> V_1017 = 0 ;
}
static void F_255 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_993 ) || ! V_5 -> V_997 )
return;
F_256 ( V_5 -> V_997 ) ;
V_5 -> V_997 = NULL ;
V_5 -> V_1017 = 0 ;
}
static inline int F_257 ( struct V_4 * V_5 )
{
return V_5 -> V_125 ;
}
static inline void F_258 ( struct V_4 * V_5 , T_1 * V_1048 , T_1 V_6 , T_1 V_74 )
{
int V_42 ;
V_1048 = ( T_1 * ) ( ( T_4 * ) V_1048 + V_6 ) ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += sizeof( T_1 ) )
* V_1048 ++ = F_33 ( V_6 + V_42 ) ;
}
static void F_259 ( struct V_4 * V_5 , T_1 * V_8 )
{
F_258 ( V_5 , V_8 , V_1049 , 0xb0 ) ;
F_258 ( V_5 , V_8 , V_20 , 0x200 ) ;
F_258 ( V_5 , V_8 , V_383 , 0x4f0 ) ;
F_258 ( V_5 , V_8 , V_1050 , 0xe0 ) ;
F_258 ( V_5 , V_8 , V_1051 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1052 , 0x80 ) ;
F_258 ( V_5 , V_8 , V_1053 , 0x48 ) ;
F_258 ( V_5 , V_8 , V_1054 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1055 , 0x20 ) ;
F_258 ( V_5 , V_8 , V_1056 , 0x15c ) ;
F_258 ( V_5 , V_8 , V_1057 , 0x0c ) ;
F_258 ( V_5 , V_8 , V_1058 , 0x3c ) ;
F_258 ( V_5 , V_8 , V_1059 , 0x44 ) ;
F_258 ( V_5 , V_8 , V_1060 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1061 , 0x20 ) ;
F_258 ( V_5 , V_8 , V_1062 , 0x14 ) ;
F_258 ( V_5 , V_8 , V_1063 , 0x08 ) ;
F_258 ( V_5 , V_8 , V_1064 , 0x08 ) ;
F_258 ( V_5 , V_8 , V_138 , 0x100 ) ;
if ( F_23 ( V_5 , V_1065 ) )
F_258 ( V_5 , V_8 , V_1066 , 0x180 ) ;
F_258 ( V_5 , V_8 , V_1067 , 0x10 ) ;
F_258 ( V_5 , V_8 , V_1068 , 0x58 ) ;
F_258 ( V_5 , V_8 , V_1069 , 0x08 ) ;
F_258 ( V_5 , V_8 , V_1070 , 0x08 ) ;
F_258 ( V_5 , V_8 , V_1071 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1072 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1073 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_678 , 0x04 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_258 ( V_5 , V_8 , V_1074 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1075 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1076 , 0x04 ) ;
}
F_258 ( V_5 , V_8 , V_1077 , 0x110 ) ;
F_258 ( V_5 , V_8 , V_1078 , 0x120 ) ;
F_258 ( V_5 , V_8 , V_1079 , 0x0c ) ;
F_258 ( V_5 , V_8 , V_1080 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_647 , 0x4c ) ;
if ( F_23 ( V_5 , V_586 ) )
F_258 ( V_5 , V_8 , V_608 , 0x24 ) ;
}
static void F_260 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 * V_8 ;
V_8 = F_261 ( V_1081 , V_1082 ) ;
if ( ! V_8 )
return;
if ( F_23 ( V_5 , V_1083 ) ) {
for ( V_42 = 0 ; V_42 < V_1084 ; V_42 += sizeof( T_1 ) )
V_8 [ V_42 / sizeof( T_1 ) ] = F_33 ( V_42 ) ;
} else
F_259 ( V_5 , V_8 ) ;
for ( V_42 = 0 ; V_42 < V_1081 / sizeof( T_1 ) ; V_42 += 4 ) {
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
V_131 -> V_134 -> V_1085 ,
V_131 -> V_134 -> V_1086 ,
V_131 -> V_134 -> V_1087 ,
V_131 -> V_134 -> V_1088 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_1089 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_146 ) ;
F_185 ( V_5 -> V_111 ,
L_32 ,
V_42 ,
V_131 -> V_132 , V_131 -> V_1090 ,
V_131 -> V_1091 , V_131 -> V_147 , V_131 -> V_1092 ,
V_131 -> V_149 ,
V_131 -> V_1093 . V_1094 ,
V_131 -> V_1093 . V_1095 ,
V_131 -> V_1093 . V_1096 ,
V_131 -> V_1093 . V_1097 ) ;
}
}
static void F_262 ( struct V_4 * V_5 )
{
F_184 ( F_23 ( V_5 , V_31 ) ||
V_5 -> V_1098 == F_20 ) ;
F_143 ( V_5 -> V_111 ,
L_33
L_34
L_35
L_36 ) ;
F_84 ( V_5 , V_1099 ) ;
}
static inline T_1 F_263 ( struct V_130 * V_131 )
{
F_264 () ;
return V_131 -> V_1092 -
( ( V_131 -> V_1091 - V_131 -> V_147 ) & ( V_1100 - 1 ) ) ;
}
static void F_265 ( struct V_130 * V_131 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1101 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
T_1 V_1102 = V_131 -> V_147 ;
struct V_1103 * V_1104 ;
int V_687 = V_131 - V_5 -> V_123 ;
unsigned int V_1105 = 0 , V_1106 = 0 ;
if ( F_23 ( V_5 , V_1107 ) )
V_687 -- ;
V_1104 = F_266 ( V_5 -> V_111 , V_687 ) ;
while ( V_1102 != V_1101 ) {
struct V_1108 * V_1109 = & V_131 -> V_1110 [ V_1102 ] ;
struct V_1111 * V_1112 = V_1109 -> V_1112 ;
int V_42 , V_1113 = 0 ;
if ( F_267 ( V_1112 == NULL ) ) {
F_262 ( V_5 ) ;
return;
}
if ( V_131 -> V_1114 [ V_1102 ] . V_1115 & V_1116 ) {
struct V_1043 V_1044 ;
T_6 V_1042 = F_33 ( V_1117 ) ;
V_1042 |= ( T_6 ) F_33 ( V_1118 ) << 32 ;
F_249 ( V_5 , V_1042 , & V_1044 ) ;
F_268 ( V_1112 , & V_1044 ) ;
}
F_269 ( V_5 -> V_12 ,
F_270 ( V_1109 , V_1119 ) ,
F_271 ( V_1112 ) ,
V_1120 ) ;
V_1109 -> V_1112 = NULL ;
while ( V_1109 -> V_1121 ) {
V_1109 -> V_1121 = false ;
V_1102 = F_272 ( V_1102 ) ;
V_1109 = & V_131 -> V_1110 [ V_1102 ] ;
}
V_1102 = F_272 ( V_1102 ) ;
for ( V_42 = 0 ; V_42 < F_273 ( V_1112 ) -> V_1122 ; V_42 ++ ) {
V_1109 = & V_131 -> V_1110 [ V_1102 ] ;
if ( F_267 ( V_1109 -> V_1112 != NULL || V_1102 == V_1101 ) )
V_1113 = 1 ;
F_274 ( V_5 -> V_12 ,
F_270 ( V_1109 , V_1119 ) ,
F_275 ( & F_273 ( V_1112 ) -> V_1123 [ V_42 ] ) ,
V_1120 ) ;
while ( V_1109 -> V_1121 ) {
V_1109 -> V_1121 = false ;
V_1102 = F_272 ( V_1102 ) ;
V_1109 = & V_131 -> V_1110 [ V_1102 ] ;
}
V_1102 = F_272 ( V_1102 ) ;
}
V_1105 ++ ;
V_1106 += V_1112 -> V_74 ;
F_276 ( V_1112 ) ;
if ( F_267 ( V_1113 ) ) {
F_262 ( V_5 ) ;
return;
}
}
F_277 ( V_1104 , V_1105 , V_1106 ) ;
V_131 -> V_147 = V_1102 ;
F_278 () ;
if ( F_267 ( F_279 ( V_1104 ) &&
( F_263 ( V_131 ) > F_280 ( V_131 ) ) ) ) {
F_281 ( V_1104 , F_282 () ) ;
if ( F_279 ( V_1104 ) &&
( F_263 ( V_131 ) > F_280 ( V_131 ) ) )
F_283 ( V_1104 ) ;
F_284 ( V_1104 ) ;
}
}
static void F_285 ( bool V_1124 , void * V_72 )
{
if ( V_1124 )
F_286 ( F_287 ( V_72 ) ) ;
else
F_175 ( V_72 ) ;
}
static void F_288 ( struct V_4 * V_5 , struct V_1125 * V_1109 , T_1 V_1126 )
{
unsigned int V_1127 = F_289 ( V_1126 + F_290 ( V_5 ) ) +
F_289 ( sizeof( struct V_1128 ) ) ;
if ( ! V_1109 -> V_72 )
return;
F_269 ( V_5 -> V_12 , F_270 ( V_1109 , V_1119 ) ,
V_1126 , V_1129 ) ;
F_285 ( V_1127 <= V_1130 , V_1109 -> V_72 ) ;
V_1109 -> V_72 = NULL ;
}
static int F_291 ( struct V_4 * V_5 , struct V_1131 * V_1132 ,
T_1 V_1133 , T_1 V_1134 ,
unsigned int * V_1135 )
{
struct V_1136 * V_1137 ;
struct V_1125 * V_1138 ;
T_4 * V_72 ;
T_9 V_1119 ;
int V_1127 , V_1139 , V_1140 ;
switch ( V_1133 ) {
case V_1141 :
V_1140 = V_1134 & V_5 -> V_1142 ;
V_1137 = & V_1132 -> V_1143 [ V_1140 ] ;
V_1138 = & V_1132 -> V_1144 [ V_1140 ] ;
V_1139 = V_5 -> V_1145 ;
break;
case V_1146 :
V_1140 = V_1134 & V_5 -> V_1147 ;
V_1137 = & V_1132 -> V_1148 [ V_1140 ] . V_1149 ;
V_1138 = & V_1132 -> V_1150 [ V_1140 ] ;
V_1139 = V_1151 ;
break;
default:
return - V_64 ;
}
V_1127 = F_289 ( V_1139 + F_290 ( V_5 ) ) +
F_289 ( sizeof( struct V_1128 ) ) ;
if ( V_1127 <= V_1130 ) {
V_72 = F_292 ( V_1127 ) ;
* V_1135 = V_1127 ;
} else {
V_72 = F_174 ( V_1127 , V_1082 ) ;
* V_1135 = 0 ;
}
if ( ! V_72 )
return - V_268 ;
V_1119 = F_293 ( V_5 -> V_12 ,
V_72 + F_290 ( V_5 ) ,
V_1139 ,
V_1129 ) ;
if ( F_267 ( F_294 ( V_5 -> V_12 , V_1119 ) ) ) {
F_285 ( V_1127 <= V_1130 , V_72 ) ;
return - V_210 ;
}
V_1138 -> V_72 = V_72 ;
F_295 ( V_1138 , V_1119 , V_1119 ) ;
V_1137 -> V_1152 = ( ( T_6 ) V_1119 >> 32 ) ;
V_1137 -> V_1153 = ( ( T_6 ) V_1119 & 0xffffffff ) ;
return V_1139 ;
}
static void F_296 ( struct V_130 * V_131 ,
struct V_1131 * V_1154 ,
T_1 V_1133 , int V_1155 ,
T_1 V_1134 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_1136 * V_1156 , * V_1157 ;
struct V_1125 * V_1158 , * V_1159 ;
struct V_1131 * V_1160 = & V_5 -> V_123 [ 0 ] . V_1093 ;
int V_1140 ;
switch ( V_1133 ) {
case V_1141 :
V_1140 = V_1134 & V_5 -> V_1142 ;
V_1157 = & V_1154 -> V_1143 [ V_1140 ] ;
V_1159 = & V_1154 -> V_1144 [ V_1140 ] ;
V_1156 = & V_1160 -> V_1143 [ V_1155 ] ;
V_1158 = & V_1160 -> V_1144 [ V_1155 ] ;
break;
case V_1146 :
V_1140 = V_1134 & V_5 -> V_1147 ;
V_1157 = & V_1154 -> V_1148 [ V_1140 ] . V_1149 ;
V_1159 = & V_1154 -> V_1150 [ V_1140 ] ;
V_1156 = & V_1160 -> V_1148 [ V_1155 ] . V_1149 ;
V_1158 = & V_1160 -> V_1150 [ V_1155 ] ;
break;
default:
return;
}
V_1159 -> V_72 = V_1158 -> V_72 ;
F_295 ( V_1159 , V_1119 ,
F_270 ( V_1158 , V_1119 ) ) ;
V_1157 -> V_1152 = V_1156 -> V_1152 ;
V_1157 -> V_1153 = V_1156 -> V_1153 ;
F_297 () ;
V_1158 -> V_72 = NULL ;
}
static int F_298 ( struct V_130 * V_131 , int V_1161 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1162 , V_1163 = 0 ;
T_1 V_1164 , V_1165 ;
T_1 V_1102 = V_131 -> V_149 ;
T_3 V_1101 ;
int V_1166 ;
struct V_1131 * V_1132 = & V_131 -> V_1093 ;
V_1101 = * ( V_131 -> V_148 ) ;
F_299 () ;
V_1162 = 0 ;
V_1166 = 0 ;
V_1164 = V_1132 -> V_1094 ;
V_1165 = V_1132 -> V_1096 ;
while ( V_1102 != V_1101 && V_1161 > 0 ) {
struct V_1125 * V_1109 ;
struct V_1136 * V_1137 = & V_131 -> V_1167 [ V_1102 ] ;
unsigned int V_74 ;
struct V_1111 * V_1112 ;
T_9 V_1168 ;
T_1 V_1133 , V_1169 , * V_1170 ;
T_4 * V_72 ;
T_6 V_1171 = 0 ;
V_1169 = V_1137 -> V_1172 & V_1173 ;
V_1133 = V_1137 -> V_1172 & V_1174 ;
if ( V_1133 == V_1141 ) {
V_1109 = & V_5 -> V_123 [ 0 ] . V_1093 . V_1144 [ V_1169 ] ;
V_1168 = F_270 ( V_1109 , V_1119 ) ;
V_72 = V_1109 -> V_72 ;
V_1170 = & V_1164 ;
V_1163 ++ ;
} else if ( V_1133 == V_1146 ) {
V_1109 = & V_5 -> V_123 [ 0 ] . V_1093 . V_1150 [ V_1169 ] ;
V_1168 = F_270 ( V_1109 , V_1119 ) ;
V_72 = V_1109 -> V_72 ;
V_1170 = & V_1165 ;
} else
goto V_1175;
V_1162 |= V_1133 ;
if ( V_1137 -> V_1176 & V_1177 ) {
V_1178:
F_296 ( V_131 , V_1132 , V_1133 ,
V_1169 , * V_1170 ) ;
V_1179:
V_5 -> V_1180 ++ ;
goto V_1181;
}
F_300 ( V_72 + F_290 ( V_5 ) ) ;
V_74 = ( ( V_1137 -> V_1182 & V_1183 ) >> V_1184 ) -
V_1185 ;
if ( ( V_1137 -> V_1186 & V_1187 ) ==
V_1188 ||
( V_1137 -> V_1186 & V_1187 ) ==
V_1189 ) {
V_1171 = F_33 ( V_1190 ) ;
V_1171 |= ( T_6 ) F_33 ( V_1191 ) << 32 ;
}
if ( V_74 > F_301 ( V_5 ) ) {
int V_1127 ;
unsigned int V_1135 ;
V_1127 = F_291 ( V_5 , V_1132 , V_1133 ,
* V_1170 , & V_1135 ) ;
if ( V_1127 < 0 )
goto V_1178;
F_269 ( V_5 -> V_12 , V_1168 , V_1127 ,
V_1129 ) ;
F_297 () ;
V_1109 -> V_72 = NULL ;
V_1112 = F_302 ( V_72 , V_1135 ) ;
if ( ! V_1112 ) {
F_285 ( V_1135 != 0 , V_72 ) ;
goto V_1179;
}
F_303 ( V_1112 , F_290 ( V_5 ) ) ;
} else {
F_296 ( V_131 , V_1132 , V_1133 ,
V_1169 , * V_1170 ) ;
V_1112 = F_304 ( V_5 -> V_111 ,
V_74 + V_1192 ) ;
if ( V_1112 == NULL )
goto V_1179;
F_303 ( V_1112 , V_1192 ) ;
F_305 ( V_5 -> V_12 , V_1168 , V_74 , V_1129 ) ;
memcpy ( V_1112 -> V_72 ,
V_72 + F_290 ( V_5 ) ,
V_74 ) ;
F_306 ( V_5 -> V_12 , V_1168 , V_74 , V_1129 ) ;
}
F_307 ( V_1112 , V_74 ) ;
if ( V_1171 )
F_249 ( V_5 , V_1171 ,
F_308 ( V_1112 ) ) ;
if ( ( V_5 -> V_111 -> V_1193 & V_1194 ) &&
( V_1137 -> V_1186 & V_1195 ) &&
( ( ( V_1137 -> V_1196 & V_1197 )
>> V_1198 ) == 0xffff ) )
V_1112 -> V_1199 = V_1200 ;
else
F_309 ( V_1112 ) ;
V_1112 -> V_1201 = F_310 ( V_1112 , V_5 -> V_111 ) ;
if ( V_74 > ( V_5 -> V_111 -> V_1202 + V_1203 ) &&
V_1112 -> V_1201 != F_311 ( V_1204 ) ) {
F_276 ( V_1112 ) ;
goto V_1179;
}
if ( V_1137 -> V_1186 & V_1205 &&
! ( V_5 -> V_355 & V_1206 ) )
F_312 ( V_1112 , F_311 ( V_1204 ) ,
V_1137 -> V_1176 & V_1207 ) ;
F_313 ( & V_131 -> V_123 , V_1112 ) ;
V_1166 ++ ;
V_1161 -- ;
V_1181:
( * V_1170 ) ++ ;
if ( F_267 ( V_1163 >= V_5 -> V_1208 ) ) {
V_1132 -> V_1094 = V_1164 &
V_5 -> V_1142 ;
F_314 ( V_18 ,
V_1132 -> V_1094 ) ;
V_1162 &= ~ V_1141 ;
V_1163 = 0 ;
}
V_1175:
V_1102 ++ ;
V_1102 &= V_5 -> V_1209 ;
if ( V_1102 == V_1101 ) {
V_1101 = * ( V_131 -> V_148 ) ;
F_299 () ;
}
}
V_131 -> V_149 = V_1102 ;
F_314 ( V_131 -> V_1210 , V_1102 ) ;
if ( ! F_23 ( V_5 , V_1211 ) ) {
F_49 () ;
if ( V_1162 & V_1141 ) {
V_1132 -> V_1094 = V_1164 &
V_5 -> V_1142 ;
F_314 ( V_18 ,
V_1132 -> V_1094 ) ;
}
if ( V_1162 & V_1146 ) {
V_1132 -> V_1096 = V_1165 &
V_5 -> V_1147 ;
F_314 ( V_1212 ,
V_1132 -> V_1096 ) ;
}
F_53 () ;
} else if ( V_1162 ) {
F_297 () ;
V_1132 -> V_1094 = V_1164 & V_5 -> V_1142 ;
V_1132 -> V_1096 = V_1165 & V_5 -> V_1147 ;
if ( V_131 != & V_5 -> V_123 [ 1 ] ) {
V_5 -> V_1213 = true ;
F_315 ( & V_5 -> V_123 [ 1 ] . V_123 ) ;
}
}
return V_1166 ;
}
static void F_316 ( struct V_4 * V_5 )
{
if ( ! ( F_23 ( V_5 , V_142 ) || F_23 ( V_5 , V_143 ) ) ) {
struct V_139 * V_140 = V_5 -> V_123 [ 0 ] . V_134 ;
if ( V_140 -> V_57 & V_144 ) {
V_140 -> V_57 = V_135 |
( V_140 -> V_57 & ~ V_144 ) ;
F_317 ( & V_5 -> V_209 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
F_31 ( V_793 ,
( V_794 |
V_795 |
V_796 |
V_797 ) ) ;
F_24 ( 40 ) ;
} else
F_201 ( V_5 , false ) ;
F_318 ( & V_5 -> V_209 ) ;
}
}
}
static int F_319 ( struct V_4 * V_5 ,
struct V_1131 * V_1154 ,
struct V_1131 * V_1160 )
{
T_1 V_1214 , V_1215 , V_1216 , V_1217 ;
int V_42 , V_75 = 0 ;
while ( 1 ) {
V_1217 = V_1160 -> V_1094 ;
F_320 () ;
if ( V_1160 -> V_1095 == V_1217 )
break;
if ( V_1160 -> V_1095 < V_1217 )
V_1216 = V_1217 - V_1160 -> V_1095 ;
else
V_1216 = V_5 -> V_1142 + 1 -
V_1160 -> V_1095 ;
V_1216 = F_321 ( V_1216 ,
V_5 -> V_1142 + 1 - V_1154 -> V_1094 ) ;
V_1214 = V_1160 -> V_1095 ;
V_1215 = V_1154 -> V_1094 ;
for ( V_42 = V_1215 ; V_42 < V_1215 + V_1216 ; V_42 ++ ) {
if ( V_1154 -> V_1144 [ V_42 ] . V_72 ) {
V_1216 = V_42 - V_1215 ;
V_75 = - V_1218 ;
break;
}
}
if ( ! V_1216 )
break;
F_320 () ;
memcpy ( & V_1154 -> V_1144 [ V_1215 ] ,
& V_1160 -> V_1144 [ V_1214 ] ,
V_1216 * sizeof( struct V_1125 ) ) ;
for ( V_42 = 0 ; V_42 < V_1216 ; V_42 ++ , V_1215 ++ , V_1214 ++ ) {
struct V_1136 * V_1219 , * V_1220 ;
V_1219 = & V_1160 -> V_1143 [ V_1214 ] ;
V_1220 = & V_1154 -> V_1143 [ V_1215 ] ;
V_1220 -> V_1152 = V_1219 -> V_1152 ;
V_1220 -> V_1153 = V_1219 -> V_1153 ;
}
V_1160 -> V_1095 = ( V_1160 -> V_1095 + V_1216 ) &
V_5 -> V_1142 ;
V_1154 -> V_1094 = ( V_1154 -> V_1094 + V_1216 ) &
V_5 -> V_1142 ;
}
while ( 1 ) {
V_1217 = V_1160 -> V_1096 ;
F_320 () ;
if ( V_1160 -> V_1097 == V_1217 )
break;
if ( V_1160 -> V_1097 < V_1217 )
V_1216 = V_1217 - V_1160 -> V_1097 ;
else
V_1216 = V_5 -> V_1147 + 1 -
V_1160 -> V_1097 ;
V_1216 = F_321 ( V_1216 ,
V_5 -> V_1147 + 1 - V_1154 -> V_1096 ) ;
V_1214 = V_1160 -> V_1097 ;
V_1215 = V_1154 -> V_1096 ;
for ( V_42 = V_1215 ; V_42 < V_1215 + V_1216 ; V_42 ++ ) {
if ( V_1154 -> V_1150 [ V_42 ] . V_72 ) {
V_1216 = V_42 - V_1215 ;
V_75 = - V_1218 ;
break;
}
}
if ( ! V_1216 )
break;
F_320 () ;
memcpy ( & V_1154 -> V_1150 [ V_1215 ] ,
& V_1160 -> V_1150 [ V_1214 ] ,
V_1216 * sizeof( struct V_1125 ) ) ;
for ( V_42 = 0 ; V_42 < V_1216 ; V_42 ++ , V_1215 ++ , V_1214 ++ ) {
struct V_1136 * V_1219 , * V_1220 ;
V_1219 = & V_1160 -> V_1148 [ V_1214 ] . V_1149 ;
V_1220 = & V_1154 -> V_1148 [ V_1215 ] . V_1149 ;
V_1220 -> V_1152 = V_1219 -> V_1152 ;
V_1220 -> V_1153 = V_1219 -> V_1153 ;
}
V_1160 -> V_1097 = ( V_1160 -> V_1097 + V_1216 ) &
V_5 -> V_1147 ;
V_1154 -> V_1096 = ( V_1154 -> V_1096 + V_1216 ) &
V_5 -> V_1147 ;
}
return V_75 ;
}
static int F_322 ( struct V_130 * V_131 , int V_1221 , int V_1161 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
if ( V_131 -> V_134 -> V_145 [ 0 ] . V_146 != V_131 -> V_147 ) {
F_265 ( V_131 ) ;
if ( F_267 ( F_23 ( V_5 , V_1099 ) ) )
return V_1221 ;
}
if ( ! V_131 -> V_148 )
return V_1221 ;
if ( * ( V_131 -> V_148 ) != V_131 -> V_149 )
V_1221 += F_298 ( V_131 , V_1161 - V_1221 ) ;
if ( F_23 ( V_5 , V_1211 ) && V_131 == & V_5 -> V_123 [ 1 ] ) {
struct V_1131 * V_1154 = & V_5 -> V_123 [ 0 ] . V_1093 ;
int V_42 , V_75 = 0 ;
T_1 V_1164 = V_1154 -> V_1094 ;
T_1 V_1165 = V_1154 -> V_1096 ;
V_5 -> V_1213 = false ;
for ( V_42 = 1 ; V_42 <= V_5 -> V_1222 ; V_42 ++ )
V_75 |= F_319 ( V_5 , V_1154 ,
& V_5 -> V_123 [ V_42 ] . V_1093 ) ;
F_49 () ;
if ( V_1164 != V_1154 -> V_1094 )
F_314 ( V_18 ,
V_1154 -> V_1094 ) ;
if ( V_1165 != V_1154 -> V_1096 )
F_314 ( V_1212 ,
V_1154 -> V_1096 ) ;
F_53 () ;
if ( V_75 )
F_31 ( V_138 , V_5 -> V_126 ) ;
}
return V_1221 ;
}
static inline void F_323 ( struct V_4 * V_5 )
{
if ( ! F_324 ( V_1223 , V_5 -> V_1224 ) )
F_325 ( & V_5 -> V_1225 ) ;
}
static inline void F_326 ( struct V_4 * V_5 )
{
F_327 ( & V_5 -> V_1225 ) ;
F_86 ( V_5 , V_1226 ) ;
F_86 ( V_5 , V_1099 ) ;
}
static int F_328 ( struct V_1227 * V_123 , int V_1161 )
{
struct V_130 * V_131 = F_239 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1221 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
V_1221 = F_322 ( V_131 , V_1221 , V_1161 ) ;
if ( F_267 ( F_23 ( V_5 , V_1099 ) ) )
goto V_1228;
if ( F_267 ( V_1221 >= V_1161 ) )
break;
V_131 -> V_132 = V_140 -> V_1085 ;
V_131 -> V_1090 = V_131 -> V_132 ;
F_299 () ;
if ( F_329 ( V_140 -> V_145 [ 0 ] . V_146 == V_131 -> V_147 &&
* ( V_131 -> V_148 ) == V_131 -> V_149 ) ) {
if ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1213 )
continue;
F_330 ( V_123 ) ;
F_52 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
if ( F_267 ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1213 ) ) {
F_46 ( V_138 , V_5 -> V_127 |
V_128 |
V_131 -> V_126 ) ;
}
F_53 () ;
break;
}
}
return V_1221 ;
V_1228:
F_330 ( V_123 ) ;
F_323 ( V_5 ) ;
return V_1221 ;
}
static void F_331 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_1229 = false ;
if ( F_23 ( V_5 , V_1230 ) )
return;
V_7 = F_33 ( V_1231 ) ;
if ( V_7 & ~ V_1232 ) {
F_185 ( V_5 -> V_111 , L_37 ) ;
V_1229 = true ;
}
if ( F_33 ( V_1233 ) & ~ V_1234 ) {
F_185 ( V_5 -> V_111 , L_38 ) ;
V_1229 = true ;
}
if ( F_33 ( V_1235 ) || F_33 ( V_1236 ) ) {
F_185 ( V_5 -> V_111 , L_39 ) ;
V_1229 = true ;
}
if ( ! V_1229 )
return;
F_260 ( V_5 ) ;
F_84 ( V_5 , V_1230 ) ;
F_323 ( V_5 ) ;
}
static int F_332 ( struct V_1227 * V_123 , int V_1161 )
{
struct V_130 * V_131 = F_239 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1221 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
if ( V_140 -> V_57 & V_1237 )
F_331 ( V_5 ) ;
F_316 ( V_5 ) ;
V_1221 = F_322 ( V_131 , V_1221 , V_1161 ) ;
if ( F_267 ( F_23 ( V_5 , V_1099 ) ) )
goto V_1228;
if ( F_267 ( V_1221 >= V_1161 ) )
break;
if ( F_23 ( V_5 , V_133 ) ) {
V_131 -> V_132 = V_140 -> V_1085 ;
V_131 -> V_1090 = V_131 -> V_132 ;
F_299 () ;
} else
V_140 -> V_57 &= ~ V_135 ;
if ( F_329 ( ! F_50 ( V_131 ) ) ) {
F_330 ( V_123 ) ;
F_51 ( V_131 ) ;
break;
}
}
return V_1221 ;
V_1228:
F_330 ( V_123 ) ;
F_323 ( V_5 ) ;
return V_1221 ;
}
static void F_333 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- )
F_334 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static void F_335 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_336 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static void F_337 ( struct V_4 * V_5 )
{
int V_42 ;
F_338 ( V_5 -> V_111 , & V_5 -> V_123 [ 0 ] . V_123 , F_332 , 64 ) ;
for ( V_42 = 1 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_338 ( V_5 -> V_111 , & V_5 -> V_123 [ V_42 ] . V_123 , F_328 , 64 ) ;
}
static void F_339 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_340 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static inline void F_341 ( struct V_4 * V_5 )
{
V_5 -> V_111 -> V_1238 = V_299 ;
F_333 ( V_5 ) ;
F_141 ( V_5 -> V_111 ) ;
F_342 ( V_5 -> V_111 ) ;
}
static inline void F_343 ( struct V_4 * V_5 )
{
F_254 ( V_5 ) ;
F_344 ( V_5 -> V_111 ) ;
if ( V_5 -> V_341 )
F_220 ( V_5 -> V_111 ) ;
F_335 ( V_5 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 |= V_135 ;
F_48 ( V_5 ) ;
}
static void F_345 ( struct V_4 * V_5 )
{
int V_42 ;
F_184 ( V_5 -> V_125 ) ;
V_5 -> V_125 = 1 ;
F_278 () ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_346 ( V_5 -> V_123 [ V_42 ] . V_1239 ) ;
}
static inline void F_241 ( struct V_4 * V_5 , int V_125 )
{
F_70 ( & V_5 -> V_209 ) ;
if ( V_125 )
F_345 ( V_5 ) ;
}
static inline void F_242 ( struct V_4 * V_5 )
{
F_71 ( & V_5 -> V_209 ) ;
}
static T_10 F_347 ( int V_280 , void * V_1240 )
{
struct V_130 * V_131 = V_1240 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_300 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1167 )
F_300 ( & V_131 -> V_1167 [ V_131 -> V_149 ] ) ;
if ( F_329 ( ! F_257 ( V_5 ) ) )
F_315 ( & V_131 -> V_123 ) ;
return V_1241 ;
}
static T_10 F_348 ( int V_280 , void * V_1240 )
{
struct V_130 * V_131 = V_1240 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_300 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1167 )
F_300 ( & V_131 -> V_1167 [ V_131 -> V_149 ] ) ;
F_52 ( V_131 -> V_124 , 0x00000001 ) ;
if ( F_329 ( ! F_257 ( V_5 ) ) )
F_315 ( & V_131 -> V_123 ) ;
return F_349 ( 1 ) ;
}
static T_10 F_350 ( int V_280 , void * V_1240 )
{
struct V_130 * V_131 = V_1240 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1242 = 1 ;
if ( F_267 ( ! ( V_140 -> V_57 & V_135 ) ) ) {
if ( F_23 ( V_5 , V_1243 ) ||
( F_33 ( V_1244 ) & V_1245 ) ) {
V_1242 = 0 ;
goto V_503;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
if ( F_257 ( V_5 ) )
goto V_503;
V_140 -> V_57 &= ~ V_135 ;
if ( F_329 ( F_50 ( V_131 ) ) ) {
F_300 ( & V_131 -> V_1167 [ V_131 -> V_149 ] ) ;
F_315 ( & V_131 -> V_123 ) ;
} else {
F_47 ( V_20 + V_16 ,
0x00000000 ) ;
}
V_503:
return F_349 ( V_1242 ) ;
}
static T_10 F_351 ( int V_280 , void * V_1240 )
{
struct V_130 * V_131 = V_1240 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1242 = 1 ;
if ( F_267 ( V_140 -> V_1085 == V_131 -> V_1090 ) ) {
if ( F_23 ( V_5 , V_1243 ) ||
( F_33 ( V_1244 ) & V_1245 ) ) {
V_1242 = 0 ;
goto V_503;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
V_131 -> V_1090 = V_140 -> V_1085 ;
if ( F_257 ( V_5 ) )
goto V_503;
F_300 ( & V_131 -> V_1167 [ V_131 -> V_149 ] ) ;
F_315 ( & V_131 -> V_123 ) ;
V_503:
return F_349 ( V_1242 ) ;
}
static T_10 F_352 ( int V_280 , void * V_1240 )
{
struct V_130 * V_131 = V_1240 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
if ( ( V_140 -> V_57 & V_135 ) ||
! ( F_33 ( V_1244 ) & V_1245 ) ) {
F_45 ( V_5 ) ;
return F_349 ( 1 ) ;
}
return F_349 ( 0 ) ;
}
static void F_353 ( struct V_365 * V_111 )
{
int V_42 ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_257 ( V_5 ) )
return;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_350 ( V_5 -> V_123 [ V_42 ] . V_1239 , & V_5 -> V_123 [ V_42 ] ) ;
}
static void F_354 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_355 ( V_5 ) ) {
F_185 ( V_111 , L_40 ) ;
F_260 ( V_5 ) ;
}
F_323 ( V_5 ) ;
}
static inline int F_356 ( T_9 V_1119 , int V_74 )
{
T_1 V_1246 = ( T_1 ) V_1119 & 0xffffffff ;
return V_1246 + V_74 + 8 < V_1246 ;
}
static inline int F_357 ( struct V_4 * V_5 , T_9 V_1119 ,
T_1 V_74 , T_1 V_1247 )
{
if ( F_30 ( V_5 ) == V_768 && V_1247 ) {
T_1 V_1246 = ( T_1 ) V_1119 & 0xffffffff ;
return ( ( V_1246 + V_74 + ( V_1247 & 0x3fff ) ) < V_1246 ) ;
}
return 0 ;
}
static inline int F_358 ( struct V_4 * V_5 , T_9 V_1119 ,
int V_74 )
{
#if F_359 ( V_1248 ) && ( V_1249 == 64 )
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) )
return ( ( T_6 ) V_1119 + V_74 ) > F_360 ( 40 ) ;
return 0 ;
#else
return 0 ;
#endif
}
static inline void F_361 ( struct V_1250 * V_1251 ,
T_9 V_1119 , T_1 V_74 , T_1 V_10 ,
T_1 V_1247 , T_1 V_1252 )
{
V_1251 -> V_1152 = ( ( T_6 ) V_1119 >> 32 ) ;
V_1251 -> V_1153 = ( ( T_6 ) V_1119 & 0xffffffff ) ;
V_1251 -> V_1115 = ( V_74 << V_1253 ) | ( V_10 & 0x0000ffff ) ;
V_1251 -> V_1254 = ( V_1247 << V_1255 ) | ( V_1252 << V_1256 ) ;
}
static bool F_362 ( struct V_130 * V_131 , T_1 * V_1257 , T_1 * V_1161 ,
T_9 V_1138 , T_1 V_74 , T_1 V_10 ,
T_1 V_1247 , T_1 V_1252 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
bool V_1258 = false ;
if ( F_23 ( V_5 , V_1259 ) && V_74 <= 8 )
V_1258 = true ;
if ( F_356 ( V_1138 , V_74 ) )
V_1258 = true ;
if ( F_357 ( V_5 , V_1138 , V_74 , V_1247 ) )
V_1258 = true ;
if ( F_358 ( V_5 , V_1138 , V_74 ) )
V_1258 = true ;
if ( V_5 -> V_1260 ) {
T_1 V_1261 = * V_1257 ;
T_1 V_1262 = V_10 & ~ V_1263 ;
while ( V_74 > V_5 -> V_1260 && * V_1161 ) {
T_1 V_1264 = V_5 -> V_1260 ;
V_74 -= V_5 -> V_1260 ;
if ( V_74 <= 8 ) {
V_74 += V_5 -> V_1260 / 2 ;
V_1264 = V_5 -> V_1260 / 2 ;
}
V_131 -> V_1110 [ * V_1257 ] . V_1121 = true ;
F_361 ( & V_131 -> V_1114 [ * V_1257 ] , V_1138 ,
V_1264 , V_1262 , V_1247 , V_1252 ) ;
* V_1161 -= 1 ;
V_1261 = * V_1257 ;
* V_1257 = F_272 ( * V_1257 ) ;
V_1138 += V_1264 ;
}
if ( V_74 ) {
if ( * V_1161 ) {
F_361 ( & V_131 -> V_1114 [ * V_1257 ] , V_1138 ,
V_74 , V_10 , V_1247 , V_1252 ) ;
* V_1161 -= 1 ;
* V_1257 = F_272 ( * V_1257 ) ;
} else {
V_1258 = true ;
V_131 -> V_1110 [ V_1261 ] . V_1121 = false ;
}
}
} else {
F_361 ( & V_131 -> V_1114 [ * V_1257 ] , V_1138 ,
V_74 , V_10 , V_1247 , V_1252 ) ;
* V_1257 = F_272 ( * V_1257 ) ;
}
return V_1258 ;
}
static void F_363 ( struct V_130 * V_131 , T_1 V_1257 , int V_1265 )
{
int V_42 ;
struct V_1111 * V_1112 ;
struct V_1108 * V_1266 = & V_131 -> V_1110 [ V_1257 ] ;
V_1112 = V_1266 -> V_1112 ;
V_1266 -> V_1112 = NULL ;
F_269 ( V_131 -> V_5 -> V_12 ,
F_270 ( V_1266 , V_1119 ) ,
F_271 ( V_1112 ) ,
V_1120 ) ;
while ( V_1266 -> V_1121 ) {
V_1266 -> V_1121 = false ;
V_1257 = F_272 ( V_1257 ) ;
V_1266 = & V_131 -> V_1110 [ V_1257 ] ;
}
for ( V_42 = 0 ; V_42 <= V_1265 ; V_42 ++ ) {
const T_11 * V_1267 = & F_273 ( V_1112 ) -> V_1123 [ V_42 ] ;
V_1257 = F_272 ( V_1257 ) ;
V_1266 = & V_131 -> V_1110 [ V_1257 ] ;
F_274 ( V_131 -> V_5 -> V_12 ,
F_270 ( V_1266 , V_1119 ) ,
F_275 ( V_1267 ) , V_1120 ) ;
while ( V_1266 -> V_1121 ) {
V_1266 -> V_1121 = false ;
V_1257 = F_272 ( V_1257 ) ;
V_1266 = & V_131 -> V_1110 [ V_1257 ] ;
}
}
}
static int F_364 ( struct V_130 * V_131 ,
struct V_1111 * * V_1268 ,
T_1 * V_1257 , T_1 * V_1161 ,
T_1 V_1269 , T_1 V_1247 , T_1 V_1252 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_1111 * V_1270 , * V_1112 = * V_1268 ;
T_9 V_1271 = 0 ;
int V_56 = 0 ;
if ( F_30 ( V_5 ) != V_538 )
V_1270 = F_365 ( V_1112 , V_1082 ) ;
else {
int V_1272 = 4 - ( ( unsigned long ) V_1112 -> V_72 & 3 ) ;
V_1270 = F_366 ( V_1112 ,
F_367 ( V_1112 ) + V_1272 ,
F_368 ( V_1112 ) , V_1082 ) ;
}
if ( ! V_1270 ) {
V_56 = - 1 ;
} else {
V_1271 = F_293 ( V_5 -> V_12 , V_1270 -> V_72 , V_1270 -> V_74 ,
V_1120 ) ;
if ( F_294 ( V_5 -> V_12 , V_1271 ) ) {
F_276 ( V_1270 ) ;
V_56 = - 1 ;
} else {
T_1 V_1273 = * V_1257 ;
V_1269 |= V_1263 ;
V_131 -> V_1110 [ * V_1257 ] . V_1112 = V_1270 ;
F_295 ( & V_131 -> V_1110 [ * V_1257 ] ,
V_1119 , V_1271 ) ;
if ( F_362 ( V_131 , V_1257 , V_1161 , V_1271 ,
V_1270 -> V_74 , V_1269 ,
V_1247 , V_1252 ) ) {
F_363 ( V_131 , V_1273 , - 1 ) ;
F_276 ( V_1270 ) ;
V_56 = - 1 ;
}
}
}
F_276 ( V_1112 ) ;
* V_1268 = V_1270 ;
return V_56 ;
}
static int F_369 ( struct V_4 * V_5 , struct V_1111 * V_1112 )
{
struct V_1111 * V_1274 , * V_1275 ;
T_1 V_1276 = F_273 ( V_1112 ) -> V_1277 * 3 ;
if ( F_267 ( F_263 ( & V_5 -> V_123 [ 0 ] ) <= V_1276 ) ) {
F_370 ( V_5 -> V_111 ) ;
F_278 () ;
if ( F_263 ( & V_5 -> V_123 [ 0 ] ) <= V_1276 )
return V_1278 ;
F_371 ( V_5 -> V_111 ) ;
}
V_1274 = F_372 ( V_1112 , V_5 -> V_111 -> V_1193 & ~ V_1279 ) ;
if ( F_116 ( V_1274 ) )
goto V_1280;
do {
V_1275 = V_1274 ;
V_1274 = V_1274 -> V_1281 ;
V_1275 -> V_1281 = NULL ;
F_373 ( V_1275 , V_5 -> V_111 ) ;
} while ( V_1274 );
V_1280:
F_276 ( V_1112 ) ;
return V_1282 ;
}
static T_12 F_373 ( struct V_1111 * V_1112 , struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_74 , V_1257 , V_1269 , V_1247 , V_1252 = 0 ;
T_1 V_1161 ;
int V_42 = - 1 , V_1283 ;
T_9 V_1119 ;
struct V_130 * V_131 ;
struct V_1103 * V_1104 ;
unsigned int V_1265 ;
V_1104 = F_266 ( V_111 , F_374 ( V_1112 ) ) ;
V_131 = & V_5 -> V_123 [ F_374 ( V_1112 ) ] ;
if ( F_23 ( V_5 , V_1107 ) )
V_131 ++ ;
V_1161 = F_263 ( V_131 ) ;
if ( F_267 ( V_1161 <= ( F_273 ( V_1112 ) -> V_1122 + 1 ) ) ) {
if ( ! F_279 ( V_1104 ) ) {
F_375 ( V_1104 ) ;
F_185 ( V_111 ,
L_41 ) ;
}
return V_1278 ;
}
V_1257 = V_131 -> V_1091 ;
V_1269 = 0 ;
if ( V_1112 -> V_1199 == V_1284 )
V_1269 |= V_1285 ;
V_1247 = F_273 ( V_1112 ) -> V_1286 ;
if ( V_1247 ) {
struct V_1287 * V_1288 ;
T_1 V_1289 , V_1290 ;
if ( F_376 ( V_1112 ) &&
F_377 ( V_1112 , 0 , 0 , V_1082 ) )
goto V_1291;
V_1288 = F_378 ( V_1112 ) ;
V_1289 = F_379 ( V_1112 ) ;
V_1290 = F_380 ( V_1112 ) + F_381 ( V_1112 ) - V_1203 ;
if ( ! F_382 ( V_1112 ) ) {
V_1288 -> V_1292 = 0 ;
V_1288 -> V_1293 = F_311 ( V_1247 + V_1290 ) ;
}
if ( F_267 ( ( V_1203 + V_1290 ) > 80 ) &&
F_23 ( V_5 , V_1294 ) )
return F_369 ( V_5 , V_1112 ) ;
V_1269 |= ( V_1295 |
V_1296 ) ;
if ( F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ) {
F_383 ( V_1112 ) -> V_1292 = 0 ;
V_1269 &= ~ V_1285 ;
} else
F_383 ( V_1112 ) -> V_1292 = ~ F_384 ( V_1288 -> V_1300 ,
V_1288 -> V_1301 , 0 ,
V_1302 ,
0 ) ;
if ( F_23 ( V_5 , V_1299 ) ) {
V_1247 |= ( V_1290 & 0xc ) << 12 ;
if ( V_1290 & 0x10 )
V_1269 |= 0x00000010 ;
V_1269 |= ( V_1290 & 0x3e0 ) << 5 ;
} else if ( F_23 ( V_5 , V_1298 ) )
V_1247 |= V_1290 << 9 ;
else if ( F_23 ( V_5 , V_1297 ) ||
F_30 ( V_5 ) == V_502 ) {
if ( V_1289 || V_1288 -> V_1303 > 5 ) {
int V_1304 ;
V_1304 = ( V_1288 -> V_1303 - 5 ) + ( V_1289 >> 2 ) ;
V_1247 |= ( V_1304 << 11 ) ;
}
} else {
if ( V_1289 || V_1288 -> V_1303 > 5 ) {
int V_1304 ;
V_1304 = ( V_1288 -> V_1303 - 5 ) + ( V_1289 >> 2 ) ;
V_1269 |= V_1304 << 12 ;
}
}
}
if ( F_23 ( V_5 , V_1305 ) &&
! V_1247 && V_1112 -> V_74 > V_1306 )
V_1269 |= V_1307 ;
if ( F_385 ( V_1112 ) ) {
V_1269 |= V_1308 ;
V_1252 = F_386 ( V_1112 ) ;
}
if ( ( F_267 ( F_273 ( V_1112 ) -> V_1309 & V_1310 ) ) &&
F_23 ( V_5 , V_1311 ) ) {
F_273 ( V_1112 ) -> V_1309 |= V_1312 ;
V_1269 |= V_1116 ;
}
V_74 = F_271 ( V_1112 ) ;
V_1119 = F_293 ( V_5 -> V_12 , V_1112 -> V_72 , V_74 , V_1120 ) ;
if ( F_294 ( V_5 -> V_12 , V_1119 ) )
goto V_1291;
V_131 -> V_1110 [ V_1257 ] . V_1112 = V_1112 ;
F_295 ( & V_131 -> V_1110 [ V_1257 ] , V_1119 , V_1119 ) ;
V_1283 = 0 ;
if ( F_23 ( V_5 , 5701_DMA_BUG ) )
V_1283 = 1 ;
if ( F_362 ( V_131 , & V_1257 , & V_1161 , V_1119 , V_74 , V_1269 |
( ( F_273 ( V_1112 ) -> V_1122 == 0 ) ? V_1263 : 0 ) ,
V_1247 , V_1252 ) ) {
V_1283 = 1 ;
} else if ( F_273 ( V_1112 ) -> V_1122 > 0 ) {
T_1 V_1313 = V_1247 ;
if ( ! F_23 ( V_5 , V_1297 ) &&
! F_23 ( V_5 , V_1298 ) &&
! F_23 ( V_5 , V_1299 ) )
V_1313 = 0 ;
V_1265 = F_273 ( V_1112 ) -> V_1122 - 1 ;
for ( V_42 = 0 ; V_42 <= V_1265 ; V_42 ++ ) {
T_11 * V_1267 = & F_273 ( V_1112 ) -> V_1123 [ V_42 ] ;
V_74 = F_275 ( V_1267 ) ;
V_1119 = F_387 ( & V_5 -> V_12 -> V_111 , V_1267 , 0 ,
V_74 , V_1314 ) ;
V_131 -> V_1110 [ V_1257 ] . V_1112 = NULL ;
F_295 ( & V_131 -> V_1110 [ V_1257 ] , V_1119 ,
V_1119 ) ;
if ( F_388 ( & V_5 -> V_12 -> V_111 , V_1119 ) )
goto V_1315;
if ( ! V_1161 ||
F_362 ( V_131 , & V_1257 , & V_1161 , V_1119 ,
V_74 , V_1269 |
( ( V_42 == V_1265 ) ? V_1263 : 0 ) ,
V_1313 , V_1252 ) ) {
V_1283 = 1 ;
break;
}
}
}
if ( V_1283 ) {
F_363 ( V_131 , V_131 -> V_1091 , V_42 ) ;
V_1257 = V_131 -> V_1091 ;
V_1161 = F_263 ( V_131 ) ;
if ( F_364 ( V_131 , & V_1112 , & V_1257 , & V_1161 ,
V_1269 , V_1247 , V_1252 ) )
goto V_1316;
}
F_389 ( V_1112 ) ;
F_390 ( V_1104 , V_1112 -> V_74 ) ;
F_49 () ;
F_391 ( V_131 -> V_1317 , V_1257 ) ;
V_131 -> V_1091 = V_1257 ;
if ( F_267 ( F_263 ( V_131 ) <= ( V_1318 + 1 ) ) ) {
F_375 ( V_1104 ) ;
F_278 () ;
if ( F_263 ( V_131 ) > F_280 ( V_131 ) )
F_283 ( V_1104 ) ;
}
F_53 () ;
return V_1282 ;
V_1315:
F_363 ( V_131 , V_131 -> V_1091 , -- V_42 ) ;
V_131 -> V_1110 [ V_131 -> V_1091 ] . V_1112 = NULL ;
V_1291:
F_276 ( V_1112 ) ;
V_1316:
V_5 -> V_1319 ++ ;
return V_1282 ;
}
static void F_392 ( struct V_4 * V_5 , bool V_195 )
{
if ( V_195 ) {
V_5 -> V_368 &= ~ ( V_372 |
V_371 ) ;
V_5 -> V_368 |= V_835 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_368 |= V_726 ;
if ( V_5 -> V_178 & V_393 )
V_5 -> V_368 |= V_375 ;
else
V_5 -> V_368 |= V_376 ;
} else {
V_5 -> V_368 &= ~ V_835 ;
if ( F_23 ( V_5 , 5705_PLUS ) ||
( V_5 -> V_178 & V_568 ) ||
F_30 ( V_5 ) == V_537 )
V_5 -> V_368 &= ~ V_726 ;
}
F_46 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
}
static int F_393 ( struct V_4 * V_5 , T_1 V_373 , bool V_1320 )
{
T_1 V_7 , V_775 , V_368 , V_1321 = 0 ;
F_128 ( V_5 , false ) ;
F_129 ( V_5 , false ) ;
if ( V_1320 && F_126 ( V_5 ) )
return - V_210 ;
V_775 = V_493 ;
switch ( V_373 ) {
case V_374 :
break;
case V_333 :
V_775 |= V_777 ;
break;
case V_332 :
default:
if ( V_5 -> V_178 & V_179 ) {
V_373 = V_333 ;
V_775 |= V_777 ;
} else {
V_373 = V_332 ;
V_775 |= V_494 ;
}
}
if ( V_1320 ) {
if ( ! ( V_5 -> V_178 & V_179 ) ) {
F_57 ( V_5 , V_180 , & V_7 ) ;
V_7 |= V_495 |
V_496 ;
F_59 ( V_5 , V_180 , V_7 ) ;
} else {
V_1321 = V_1322 |
V_1323 ;
F_59 ( V_5 , V_525 , V_1321 ) ;
}
} else
V_775 |= V_778 ;
F_59 ( V_5 , V_204 , V_775 ) ;
if ( V_5 -> V_178 & V_179 )
F_57 ( V_5 , V_204 , & V_775 ) ;
F_24 ( 40 ) ;
if ( ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) == V_257 ) {
F_59 ( V_5 , V_525 , V_1321 |
V_1324 |
V_1325 ) ;
F_57 ( V_5 , V_525 , & V_7 ) ;
}
if ( ( V_5 -> V_178 & V_306 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_31 ( V_362 , V_1326 ) ;
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
T_1 V_1327 = V_5 -> V_216 & V_401 ;
if ( V_1327 == V_402 )
V_368 &= ~ V_726 ;
else if ( V_1327 == V_566 )
V_368 |= V_726 ;
F_59 ( V_5 , V_492 ,
V_823 ) ;
}
F_46 ( V_383 , V_368 ) ;
F_24 ( 40 ) ;
return 0 ;
}
static void F_394 ( struct V_365 * V_111 , T_13 V_1193 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_1193 & V_1328 ) {
if ( V_5 -> V_368 & V_835 )
return;
F_70 ( & V_5 -> V_209 ) ;
F_392 ( V_5 , true ) ;
F_220 ( V_5 -> V_111 ) ;
F_71 ( & V_5 -> V_209 ) ;
F_98 ( V_111 , L_42 ) ;
} else {
if ( ! ( V_5 -> V_368 & V_835 ) )
return;
F_70 ( & V_5 -> V_209 ) ;
F_392 ( V_5 , false ) ;
F_201 ( V_5 , true ) ;
F_71 ( & V_5 -> V_209 ) ;
F_98 ( V_111 , L_43 ) ;
}
}
static T_13 F_395 ( struct V_365 * V_111 ,
T_13 V_1193 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_111 -> V_1202 > V_1329 && F_23 ( V_5 , 5780_CLASS ) )
V_1193 &= ~ V_1330 ;
return V_1193 ;
}
static int F_396 ( struct V_365 * V_111 , T_13 V_1193 )
{
T_13 V_1331 = V_111 -> V_1193 ^ V_1193 ;
if ( ( V_1331 & V_1328 ) && F_145 ( V_111 ) )
F_394 ( V_111 , V_1193 ) ;
return 0 ;
}
static void F_397 ( struct V_4 * V_5 ,
struct V_1131 * V_1132 )
{
int V_42 ;
if ( V_1132 != & V_5 -> V_123 [ 0 ] . V_1093 ) {
for ( V_42 = V_1132 -> V_1095 ; V_42 != V_1132 -> V_1094 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1142 )
F_288 ( V_5 , & V_1132 -> V_1144 [ V_42 ] ,
V_5 -> V_1145 ) ;
if ( F_23 ( V_5 , V_522 ) ) {
for ( V_42 = V_1132 -> V_1097 ;
V_42 != V_1132 -> V_1096 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1147 ) {
F_288 ( V_5 , & V_1132 -> V_1150 [ V_42 ] ,
V_1151 ) ;
}
}
return;
}
for ( V_42 = 0 ; V_42 <= V_5 -> V_1142 ; V_42 ++ )
F_288 ( V_5 , & V_1132 -> V_1144 [ V_42 ] ,
V_5 -> V_1145 ) ;
if ( F_23 ( V_5 , V_522 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
for ( V_42 = 0 ; V_42 <= V_5 -> V_1147 ; V_42 ++ )
F_288 ( V_5 , & V_1132 -> V_1150 [ V_42 ] ,
V_1151 ) ;
}
}
static int F_398 ( struct V_4 * V_5 ,
struct V_1131 * V_1132 )
{
T_1 V_42 , V_1332 ;
V_1132 -> V_1095 = 0 ;
V_1132 -> V_1094 = 0 ;
V_1132 -> V_1097 = 0 ;
V_1132 -> V_1096 = 0 ;
if ( V_1132 != & V_5 -> V_123 [ 0 ] . V_1093 ) {
memset ( & V_1132 -> V_1144 [ 0 ] , 0 ,
F_399 ( V_5 ) ) ;
if ( V_1132 -> V_1150 )
memset ( & V_1132 -> V_1150 [ 0 ] , 0 ,
F_400 ( V_5 ) ) ;
goto V_186;
}
memset ( V_1132 -> V_1143 , 0 , F_401 ( V_5 ) ) ;
V_1332 = V_1333 ;
if ( F_23 ( V_5 , 5780_CLASS ) &&
V_5 -> V_111 -> V_1202 > V_1329 )
V_1332 = V_1334 ;
V_5 -> V_1145 = F_402 ( V_1332 ) ;
for ( V_42 = 0 ; V_42 <= V_5 -> V_1142 ; V_42 ++ ) {
struct V_1136 * V_1335 ;
V_1335 = & V_1132 -> V_1143 [ V_42 ] ;
V_1335 -> V_1182 = V_1332 << V_1184 ;
V_1335 -> V_1186 = ( V_1336 << V_1337 ) ;
V_1335 -> V_1172 = ( V_1141 |
( V_42 << V_1338 ) ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_1339 ; V_42 ++ ) {
unsigned int V_1135 ;
if ( F_291 ( V_5 , V_1132 , V_1141 , V_42 ,
& V_1135 ) < 0 ) {
F_143 ( V_5 -> V_111 ,
L_44
L_45
L_46 , V_42 , V_5 -> V_1339 ) ;
if ( V_42 == 0 )
goto V_1340;
V_5 -> V_1339 = V_42 ;
break;
}
}
if ( ! F_23 ( V_5 , V_522 ) || F_23 ( V_5 , 5780_CLASS ) )
goto V_186;
memset ( V_1132 -> V_1148 , 0 , F_403 ( V_5 ) ) ;
if ( ! F_23 ( V_5 , V_1341 ) )
goto V_186;
for ( V_42 = 0 ; V_42 <= V_5 -> V_1147 ; V_42 ++ ) {
struct V_1136 * V_1335 ;
V_1335 = & V_1132 -> V_1148 [ V_42 ] . V_1149 ;
V_1335 -> V_1182 = V_1334 << V_1184 ;
V_1335 -> V_1186 = ( V_1336 << V_1337 ) |
V_1342 ;
V_1335 -> V_1172 = ( V_1146 |
( V_42 << V_1338 ) ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_1343 ; V_42 ++ ) {
unsigned int V_1135 ;
if ( F_291 ( V_5 , V_1132 , V_1146 , V_42 ,
& V_1135 ) < 0 ) {
F_143 ( V_5 -> V_111 ,
L_47
L_48
L_46 , V_42 , V_5 -> V_1343 ) ;
if ( V_42 == 0 )
goto V_1340;
V_5 -> V_1343 = V_42 ;
break;
}
}
V_186:
return 0 ;
V_1340:
F_397 ( V_5 , V_1132 ) ;
return - V_268 ;
}
static void F_404 ( struct V_4 * V_5 ,
struct V_1131 * V_1132 )
{
F_175 ( V_1132 -> V_1144 ) ;
V_1132 -> V_1144 = NULL ;
F_175 ( V_1132 -> V_1150 ) ;
V_1132 -> V_1150 = NULL ;
if ( V_1132 -> V_1143 ) {
F_405 ( & V_5 -> V_12 -> V_111 , F_401 ( V_5 ) ,
V_1132 -> V_1143 , V_1132 -> V_1344 ) ;
V_1132 -> V_1143 = NULL ;
}
if ( V_1132 -> V_1148 ) {
F_405 ( & V_5 -> V_12 -> V_111 , F_403 ( V_5 ) ,
V_1132 -> V_1148 , V_1132 -> V_1345 ) ;
V_1132 -> V_1148 = NULL ;
}
}
static int F_406 ( struct V_4 * V_5 ,
struct V_1131 * V_1132 )
{
V_1132 -> V_1144 = F_261 ( F_399 ( V_5 ) ,
V_633 ) ;
if ( ! V_1132 -> V_1144 )
return - V_268 ;
V_1132 -> V_1143 = F_407 ( & V_5 -> V_12 -> V_111 ,
F_401 ( V_5 ) ,
& V_1132 -> V_1344 ,
V_633 ) ;
if ( ! V_1132 -> V_1143 )
goto V_1035;
if ( F_23 ( V_5 , V_522 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
V_1132 -> V_1150 = F_261 ( F_400 ( V_5 ) ,
V_633 ) ;
if ( ! V_1132 -> V_1150 )
goto V_1035;
V_1132 -> V_1148 = F_407 ( & V_5 -> V_12 -> V_111 ,
F_403 ( V_5 ) ,
& V_1132 -> V_1345 ,
V_633 ) ;
if ( ! V_1132 -> V_1148 )
goto V_1035;
}
return 0 ;
V_1035:
F_404 ( V_5 , V_1132 ) ;
return - V_268 ;
}
static void F_408 ( struct V_4 * V_5 )
{
int V_42 , V_628 ;
for ( V_628 = 0 ; V_628 < V_5 -> V_129 ; V_628 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_628 ] ;
F_397 ( V_5 , & V_131 -> V_1093 ) ;
if ( ! V_131 -> V_1110 )
continue;
for ( V_42 = 0 ; V_42 < V_1100 ; V_42 ++ ) {
struct V_1111 * V_1112 = V_131 -> V_1110 [ V_42 ] . V_1112 ;
if ( ! V_1112 )
continue;
F_363 ( V_131 , V_42 ,
F_273 ( V_1112 ) -> V_1122 - 1 ) ;
F_409 ( V_1112 ) ;
}
F_410 ( F_266 ( V_5 -> V_111 , V_628 ) ) ;
}
}
static int F_411 ( struct V_4 * V_5 )
{
int V_42 ;
F_408 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_131 -> V_132 = 0 ;
V_131 -> V_1090 = 0 ;
V_131 -> V_134 -> V_57 = 0 ;
V_131 -> V_134 -> V_1085 = 0 ;
memset ( V_131 -> V_134 , 0 , V_1346 ) ;
V_131 -> V_1091 = 0 ;
V_131 -> V_147 = 0 ;
if ( V_131 -> V_1114 )
memset ( V_131 -> V_1114 , 0 , V_1347 ) ;
V_131 -> V_149 = 0 ;
if ( V_131 -> V_1167 )
memset ( V_131 -> V_1167 , 0 , F_412 ( V_5 ) ) ;
if ( F_398 ( V_5 , & V_131 -> V_1093 ) ) {
F_408 ( V_5 ) ;
return - V_268 ;
}
}
return 0 ;
}
static void F_413 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_1114 ) {
F_405 ( & V_5 -> V_12 -> V_111 , V_1347 ,
V_131 -> V_1114 , V_131 -> V_1348 ) ;
V_131 -> V_1114 = NULL ;
}
F_175 ( V_131 -> V_1110 ) ;
V_131 -> V_1110 = NULL ;
}
}
static int F_414 ( struct V_4 * V_5 )
{
int V_42 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
if ( F_23 ( V_5 , V_1107 ) )
V_131 ++ ;
for ( V_42 = 0 ; V_42 < V_5 -> V_1349 ; V_42 ++ , V_131 ++ ) {
V_131 -> V_1110 = F_261 ( sizeof( struct V_1108 ) *
V_1100 , V_633 ) ;
if ( ! V_131 -> V_1110 )
goto V_1035;
V_131 -> V_1114 = F_407 ( & V_5 -> V_12 -> V_111 ,
V_1347 ,
& V_131 -> V_1348 ,
V_633 ) ;
if ( ! V_131 -> V_1114 )
goto V_1035;
}
return 0 ;
V_1035:
F_413 ( V_5 ) ;
return - V_268 ;
}
static void F_415 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_404 ( V_5 , & V_131 -> V_1093 ) ;
if ( ! V_131 -> V_1167 )
continue;
F_405 ( & V_5 -> V_12 -> V_111 ,
F_412 ( V_5 ) ,
V_131 -> V_1167 ,
V_131 -> V_1350 ) ;
V_131 -> V_1167 = NULL ;
}
}
static int F_416 ( struct V_4 * V_5 )
{
unsigned int V_42 , V_202 ;
V_202 = V_5 -> V_1222 ;
if ( F_23 ( V_5 , V_1211 ) )
V_202 ++ ;
for ( V_42 = 0 ; V_42 < V_202 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( F_406 ( V_5 , & V_131 -> V_1093 ) )
goto V_1035;
if ( ! V_42 && F_23 ( V_5 , V_1211 ) )
continue;
V_131 -> V_1167 = F_417 ( & V_5 -> V_12 -> V_111 ,
F_412 ( V_5 ) ,
& V_131 -> V_1350 ,
V_633 ) ;
if ( ! V_131 -> V_1167 )
goto V_1035;
}
return 0 ;
V_1035:
F_415 ( V_5 ) ;
return - V_268 ;
}
static void F_418 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
F_405 ( & V_5 -> V_12 -> V_111 , V_1346 ,
V_131 -> V_134 ,
V_131 -> V_1351 ) ;
V_131 -> V_134 = NULL ;
}
}
F_415 ( V_5 ) ;
F_413 ( V_5 ) ;
if ( V_5 -> V_1352 ) {
F_405 ( & V_5 -> V_12 -> V_111 , sizeof( struct V_1353 ) ,
V_5 -> V_1352 , V_5 -> V_1354 ) ;
V_5 -> V_1352 = NULL ;
}
}
static int F_419 ( struct V_4 * V_5 )
{
int V_42 ;
V_5 -> V_1352 = F_417 ( & V_5 -> V_12 -> V_111 ,
sizeof( struct V_1353 ) ,
& V_5 -> V_1354 , V_633 ) ;
if ( ! V_5 -> V_1352 )
goto V_1035;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
struct V_139 * V_140 ;
V_131 -> V_134 = F_417 ( & V_5 -> V_12 -> V_111 ,
V_1346 ,
& V_131 -> V_1351 ,
V_633 ) ;
if ( ! V_131 -> V_134 )
goto V_1035;
V_140 = V_131 -> V_134 ;
if ( F_23 ( V_5 , V_1211 ) ) {
T_3 * V_1355 = NULL ;
switch ( V_42 ) {
case 1 :
V_1355 = & V_140 -> V_145 [ 0 ] . V_1089 ;
break;
case 2 :
V_1355 = & V_140 -> V_1086 ;
break;
case 3 :
V_1355 = & V_140 -> V_1356 ;
break;
case 4 :
V_1355 = & V_140 -> V_1088 ;
break;
}
V_131 -> V_148 = V_1355 ;
} else {
V_131 -> V_148 = & V_140 -> V_145 [ 0 ] . V_1089 ;
}
}
if ( F_414 ( V_5 ) || F_416 ( V_5 ) )
goto V_1035;
return 0 ;
V_1035:
F_418 ( V_5 ) ;
return - V_268 ;
}
static int F_420 ( struct V_4 * V_5 , unsigned long V_1357 , T_1 V_1358 , bool V_1359 )
{
unsigned int V_42 ;
T_1 V_7 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
switch ( V_1357 ) {
case V_1063 :
case V_1080 :
case V_1064 :
case V_1068 :
case V_1067 :
return 0 ;
default:
break;
}
}
V_7 = F_33 ( V_1357 ) ;
V_7 &= ~ V_1358 ;
F_31 ( V_1357 , V_7 ) ;
for ( V_42 = 0 ; V_42 < V_1360 ; V_42 ++ ) {
if ( F_36 ( V_5 -> V_12 ) ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_49
L_50 ,
V_1357 , V_1358 ) ;
return - V_82 ;
}
F_24 ( 100 ) ;
V_7 = F_33 ( V_1357 ) ;
if ( ( V_7 & V_1358 ) == 0 )
break;
}
if ( V_42 == V_1360 && ! V_1359 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_51 ,
V_1357 , V_1358 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_421 ( struct V_4 * V_5 , bool V_1359 )
{
int V_42 , V_75 ;
F_45 ( V_5 ) ;
if ( F_36 ( V_5 -> V_12 ) ) {
V_5 -> V_355 &= ~ ( V_734 | V_1361 ) ;
V_5 -> V_368 &= ~ V_733 ;
V_75 = - V_82 ;
goto V_1362;
}
V_5 -> V_355 &= ~ V_734 ;
F_31 ( V_362 , V_5 -> V_355 ) ;
F_24 ( 10 ) ;
V_75 = F_420 ( V_5 , V_1061 , V_1363 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1055 , V_1364 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1063 , V_1365 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1057 , V_1366 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1060 , V_1367 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1062 , V_1368 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1052 , V_1369 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1053 , V_1370 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1050 , V_1371 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1069 , V_1372 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1051 , V_1373 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1080 , V_1374 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1054 , V_1375 , V_1359 ) ;
V_5 -> V_368 &= ~ V_733 ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
V_5 -> V_357 &= ~ V_1361 ;
F_31 ( V_364 , V_5 -> V_357 ) ;
for ( V_42 = 0 ; V_42 < V_1360 ; V_42 ++ ) {
F_24 ( 100 ) ;
if ( ! ( F_33 ( V_364 ) & V_1361 ) )
break;
}
if ( V_42 >= V_1360 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_52
L_53 , V_658 , F_33 ( V_364 ) ) ;
V_75 |= - V_82 ;
}
V_75 |= F_420 ( V_5 , V_138 , V_128 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1070 , V_1376 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1064 , V_1377 , V_1359 ) ;
F_46 ( V_1078 , 0xffffffff ) ;
F_46 ( V_1078 , 0x00000000 ) ;
V_75 |= F_420 ( V_5 , V_1068 , V_1378 , V_1359 ) ;
V_75 |= F_420 ( V_5 , V_1067 , V_1379 , V_1359 ) ;
V_1362:
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 )
memset ( V_131 -> V_134 , 0 , V_1346 ) ;
}
return V_75 ;
}
static void F_422 ( struct V_4 * V_5 )
{
F_423 ( V_5 -> V_12 , V_1380 , & V_5 -> V_1381 ) ;
}
static void F_424 ( struct V_4 * V_5 )
{
T_1 V_7 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
V_7 = ( V_1382 | V_1383 ) ;
if ( F_77 ( V_5 ) == V_919 &&
F_23 ( V_5 , V_842 ) )
V_7 |= V_1384 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_1385 |
V_1386 |
V_1387 ;
F_15 ( V_5 -> V_12 , V_1244 , V_7 ) ;
F_425 ( V_5 -> V_12 , V_1380 , V_5 -> V_1381 ) ;
if ( ! F_23 ( V_5 , V_1083 ) ) {
F_426 ( V_5 -> V_12 , V_1388 ,
V_5 -> V_1389 ) ;
F_426 ( V_5 -> V_12 , V_1390 ,
V_5 -> V_1391 ) ;
}
if ( F_23 ( V_5 , V_842 ) ) {
T_3 V_1392 ;
F_423 ( V_5 -> V_12 , V_5 -> V_1393 + V_1394 ,
& V_1392 ) ;
V_1392 &= ~ V_1395 ;
F_425 ( V_5 -> V_12 , V_5 -> V_1393 + V_1394 ,
V_1392 ) ;
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_1396 ) ) {
T_3 V_1397 ;
F_423 ( V_5 -> V_12 ,
V_5 -> V_1398 + V_1399 ,
& V_1397 ) ;
F_425 ( V_5 -> V_12 ,
V_5 -> V_1398 + V_1399 ,
V_1397 | V_1400 ) ;
V_7 = F_33 ( V_1079 ) ;
F_46 ( V_1079 , V_7 | V_1401 ) ;
}
}
}
static void F_427 ( struct V_4 * V_5 )
{
T_1 V_7 ;
switch ( F_30 ( V_5 ) ) {
case V_477 :
V_7 = F_33 ( V_1402 ) ;
F_46 ( V_1402 , V_7 |
V_1403 ) ;
break;
case V_478 :
case V_534 :
F_46 ( V_1404 , V_1405 ) ;
break;
default:
return;
}
}
static void F_428 ( struct V_4 * V_5 )
{
T_1 V_7 ;
switch ( F_30 ( V_5 ) ) {
case V_477 :
V_7 = F_33 ( V_1402 ) ;
F_46 ( V_1402 ,
V_7 & ~ V_1403 ) ;
break;
case V_478 :
case V_534 :
V_7 = F_33 ( V_1404 ) ;
F_46 ( V_1404 , V_7 & ~ V_1405 ) ;
break;
default:
return;
}
}
static int F_429 ( struct V_4 * V_5 )
{
T_1 V_7 ;
void (* F_188)( struct V_4 * , T_1 , T_1 );
int V_42 , V_75 ;
if ( ! F_430 ( V_5 -> V_12 ) )
return - V_82 ;
F_158 ( V_5 ) ;
F_35 ( V_5 , V_61 ) ;
V_5 -> V_587 = 0 ;
F_422 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_641 ||
F_23 ( V_5 , 5755_PLUS ) )
F_46 ( V_1406 , 0 ) ;
F_188 = V_5 -> V_27 ;
if ( F_188 == F_17 )
V_5 -> V_27 = F_7 ;
F_84 ( V_5 , V_1243 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
V_131 -> V_134 -> V_57 = 0 ;
V_131 -> V_134 -> V_1085 = 0 ;
}
V_131 -> V_132 = 0 ;
V_131 -> V_1090 = 0 ;
}
F_278 () ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_346 ( V_5 -> V_123 [ V_42 ] . V_1239 ) ;
if ( F_30 ( V_5 ) == V_1407 ) {
V_7 = F_33 ( V_1408 ) & ~ V_1409 ;
F_46 ( V_1408 , V_7 | V_1410 ) ;
}
V_7 = V_1411 ;
if ( F_23 ( V_5 , V_1083 ) ) {
if ( F_30 ( V_5 ) != V_257 &&
! F_23 ( V_5 , 57765_PLUS ) &&
F_33 ( V_1412 ) ==
( V_1413 | V_1414 ) )
F_46 ( V_1412 , V_1414 ) ;
if ( F_77 ( V_5 ) != V_1415 ) {
F_46 ( V_498 , ( 1 << 29 ) ) ;
V_7 |= ( 1 << 29 ) ;
}
}
if ( F_30 ( V_5 ) == V_36 ) {
F_46 ( V_326 , F_33 ( V_326 ) | V_1416 ) ;
F_46 ( V_656 ,
F_33 ( V_656 ) & ~ V_657 ) ;
}
F_427 ( V_5 ) ;
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , V_152 ) )
V_7 |= V_1417 ;
F_46 ( V_498 , V_7 ) ;
V_5 -> V_27 = F_188 ;
F_24 ( 120 ) ;
F_19 ( V_5 -> V_12 , V_1380 , & V_7 ) ;
F_24 ( 120 ) ;
if ( F_23 ( V_5 , V_1083 ) && F_431 ( V_5 -> V_12 ) ) {
T_3 V_1418 ;
if ( F_77 ( V_5 ) == V_1415 ) {
int V_628 ;
T_1 V_1419 ;
for ( V_628 = 0 ; V_628 < 5000 ; V_628 ++ )
F_24 ( 100 ) ;
F_19 ( V_5 -> V_12 , 0xc4 , & V_1419 ) ;
F_15 ( V_5 -> V_12 , 0xc4 ,
V_1419 | ( 1 << 15 ) ) ;
}
V_1418 = V_1420 | V_1421 ;
if ( ! F_23 ( V_5 , V_152 ) )
V_1418 |= V_1422 ;
F_224 ( V_5 -> V_12 , V_1423 , V_1418 ) ;
F_432 ( V_5 -> V_12 , V_1424 ,
V_1425 |
V_1426 |
V_1427 |
V_1428 ) ;
}
F_424 ( V_5 ) ;
F_86 ( V_5 , V_1243 ) ;
F_86 ( V_5 , V_1230 ) ;
V_7 = 0 ;
if ( F_23 ( V_5 , 5780_CLASS ) )
V_7 = F_33 ( V_1067 ) ;
F_46 ( V_1067 , V_7 | V_1379 ) ;
if ( F_77 ( V_5 ) == V_1429 ) {
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
if ( F_77 ( V_5 ) == V_1430 ) {
V_7 = F_33 ( 0xc4 ) ;
F_46 ( 0xc4 , V_7 | ( 1 << 15 ) ) ;
}
if ( ( V_5 -> V_551 & V_1431 ) != 0 &&
F_30 ( V_5 ) == V_502 ) {
V_5 -> V_156 |= V_155 ;
if ( F_77 ( V_5 ) == V_1430 )
V_5 -> V_156 |= V_154 ;
F_46 ( V_153 , V_5 -> V_156 ) ;
}
if ( V_5 -> V_178 & V_568 ) {
V_5 -> V_368 = V_727 ;
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
if ( F_23 ( V_5 , V_1083 ) &&
F_77 ( V_5 ) != V_1415 &&
F_30 ( V_5 ) != V_257 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( 0x7c00 ) ;
F_46 ( 0x7c00 , V_7 | ( 1 << 25 ) ) ;
}
F_428 ( V_5 ) ;
F_86 ( V_5 , V_309 ) ;
V_5 -> V_178 &= ~ ( V_772 |
V_570 ) ;
F_86 ( V_5 , V_317 ) ;
F_32 ( V_5 , V_1432 , & V_7 ) ;
if ( V_7 == V_1433 ) {
T_1 V_1434 ;
F_32 ( V_5 , V_1435 , & V_1434 ) ;
if ( V_1434 & V_1436 ) {
F_84 ( V_5 , V_309 ) ;
V_5 -> V_298 = V_299 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , V_317 ) ;
F_32 ( V_5 , V_1437 , & V_1434 ) ;
if ( V_1434 & V_1438 )
V_5 -> V_178 |= V_772 ;
if ( V_1434 & V_1439 )
V_5 -> V_178 |= V_570 ;
}
}
return 0 ;
}
static int F_433 ( struct V_4 * V_5 , int V_95 , bool V_1359 )
{
int V_75 ;
F_93 ( V_5 ) ;
F_94 ( V_5 , V_95 ) ;
F_421 ( V_5 , V_1359 ) ;
V_75 = F_429 ( V_5 ) ;
F_195 ( V_5 , false ) ;
F_96 ( V_5 , V_95 ) ;
F_95 ( V_5 , V_95 ) ;
if ( V_5 -> V_1352 ) {
F_434 ( V_5 , & V_5 -> V_1440 ) ;
F_435 ( V_5 , & V_5 -> V_1441 ) ;
memset ( V_5 -> V_1352 , 0 , sizeof( struct V_1353 ) ) ;
}
return V_75 ;
}
static int F_436 ( struct V_365 * V_111 , void * V_1442 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_1443 * V_184 = V_1442 ;
int V_75 = 0 ;
bool V_694 = false ;
if ( ! F_437 ( V_184 -> V_1444 ) )
return - V_1445 ;
memcpy ( V_111 -> V_695 , V_184 -> V_1444 , V_111 -> V_1446 ) ;
if ( ! F_145 ( V_111 ) )
return 0 ;
if ( F_23 ( V_5 , V_309 ) ) {
T_1 V_1447 , V_1448 , V_1449 , V_1450 ;
V_1447 = F_33 ( V_690 ) ;
V_1448 = F_33 ( V_691 ) ;
V_1449 = F_33 ( V_1451 ) ;
V_1450 = F_33 ( V_1452 ) ;
if ( ( V_1447 != V_1449 || V_1448 != V_1450 ) &&
! ( V_1449 == 0 && V_1450 == 0 ) )
V_694 = true ;
}
F_70 ( & V_5 -> V_209 ) ;
F_195 ( V_5 , V_694 ) ;
F_438 ( V_111 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_75 ;
}
static void F_439 ( struct V_4 * V_5 , T_1 V_1453 ,
T_9 V_1119 , T_1 V_1454 ,
T_1 V_1455 )
{
F_29 ( V_5 ,
( V_1453 + V_1456 + V_1457 ) ,
( ( T_6 ) V_1119 >> 32 ) ) ;
F_29 ( V_5 ,
( V_1453 + V_1456 + V_16 ) ,
( ( T_6 ) V_1119 & 0xffffffff ) ) ;
F_29 ( V_5 ,
( V_1453 + V_1458 ) ,
V_1454 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_29 ( V_5 ,
( V_1453 + V_1459 ) ,
V_1455 ) ;
}
static void F_440 ( struct V_4 * V_5 , struct V_1460 * V_1461 )
{
int V_42 = 0 ;
if ( ! F_23 ( V_5 , V_1107 ) ) {
F_46 ( V_1462 , V_1461 -> V_1463 ) ;
F_46 ( V_1464 , V_1461 -> V_1465 ) ;
F_46 ( V_1466 , V_1461 -> V_1467 ) ;
} else {
F_46 ( V_1462 , 0 ) ;
F_46 ( V_1464 , 0 ) ;
F_46 ( V_1466 , 0 ) ;
for (; V_42 < V_5 -> V_1349 ; V_42 ++ ) {
T_1 V_161 ;
V_161 = V_1468 + V_42 * 0x18 ;
F_46 ( V_161 , V_1461 -> V_1463 ) ;
V_161 = V_1469 + V_42 * 0x18 ;
F_46 ( V_161 , V_1461 -> V_1465 ) ;
V_161 = V_1470 + V_42 * 0x18 ;
F_46 ( V_161 , V_1461 -> V_1467 ) ;
}
}
for (; V_42 < V_5 -> V_122 - 1 ; V_42 ++ ) {
F_46 ( V_1468 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1469 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1470 + V_42 * 0x18 , 0 ) ;
}
}
static void F_441 ( struct V_4 * V_5 , struct V_1460 * V_1461 )
{
int V_42 = 0 ;
T_1 V_202 = V_5 -> V_1222 ;
if ( ! F_23 ( V_5 , V_1211 ) ) {
F_46 ( V_1471 , V_1461 -> V_1472 ) ;
F_46 ( V_1473 , V_1461 -> V_1474 ) ;
F_46 ( V_1475 , V_1461 -> V_1476 ) ;
V_202 -- ;
} else {
F_46 ( V_1471 , 0 ) ;
F_46 ( V_1473 , 0 ) ;
F_46 ( V_1475 , 0 ) ;
}
for (; V_42 < V_202 ; V_42 ++ ) {
T_1 V_161 ;
V_161 = V_1066 + V_42 * 0x18 ;
F_46 ( V_161 , V_1461 -> V_1472 ) ;
V_161 = V_1477 + V_42 * 0x18 ;
F_46 ( V_161 , V_1461 -> V_1474 ) ;
V_161 = V_1478 + V_42 * 0x18 ;
F_46 ( V_161 , V_1461 -> V_1476 ) ;
}
for (; V_42 < V_5 -> V_122 - 1 ; V_42 ++ ) {
F_46 ( V_1066 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1477 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1478 + V_42 * 0x18 , 0 ) ;
}
}
static void F_442 ( struct V_4 * V_5 , struct V_1460 * V_1461 )
{
F_440 ( V_5 , V_1461 ) ;
F_441 ( V_5 , V_1461 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_7 = V_1461 -> V_974 ;
F_46 ( V_1479 , V_1461 -> V_1480 ) ;
F_46 ( V_1481 , V_1461 -> V_1482 ) ;
if ( ! V_5 -> V_341 )
V_7 = 0 ;
F_46 ( V_972 , V_7 ) ;
}
}
static void F_443 ( struct V_4 * V_5 )
{
T_1 V_1483 , V_202 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_202 = V_1484 + V_1485 * 16 ;
else if ( F_23 ( V_5 , 5717_PLUS ) )
V_202 = V_1484 + V_1485 * 4 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_768 )
V_202 = V_1484 + V_1485 * 2 ;
else
V_202 = V_1484 + V_1485 ;
for ( V_1483 = V_1484 + V_1485 ;
V_1483 < V_202 ; V_1483 += V_1485 )
F_29 ( V_5 , V_1483 + V_1458 ,
V_1486 ) ;
}
static void F_444 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1483 = V_1484 ;
if ( F_23 ( V_5 , V_1107 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1483 += V_1485 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1114 )
continue;
F_439 ( V_5 , V_1483 , V_131 -> V_1348 ,
( V_1100 << V_1487 ) ,
V_38 ) ;
}
}
static void F_445 ( struct V_4 * V_5 )
{
T_1 V_1488 , V_202 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_202 = V_1489 + V_1485 * 17 ;
else if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_202 = V_1489 + V_1485 * 16 ;
else if ( F_30 ( V_5 ) == V_1490 ||
F_30 ( V_5 ) == V_768 ||
F_23 ( V_5 , 57765_CLASS ) )
V_202 = V_1489 + V_1485 * 4 ;
else
V_202 = V_1489 + V_1485 ;
for ( V_1488 = V_1489 + V_1485 ;
V_1488 < V_202 ; V_1488 += V_1485 )
F_29 ( V_5 , V_1488 + V_1458 ,
V_1486 ) ;
}
static void F_446 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1488 = V_1489 ;
if ( F_23 ( V_5 , V_1211 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1488 += V_1485 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1167 )
continue;
F_439 ( V_5 , V_1488 , V_131 -> V_1350 ,
( V_5 -> V_1209 + 1 ) <<
V_1487 , 0 ) ;
}
}
static void F_447 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_1491 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
F_443 ( V_5 ) ;
F_445 ( V_5 ) ;
F_47 ( V_5 -> V_123 [ 0 ] . V_124 , 1 ) ;
V_5 -> V_123 [ 0 ] . V_1492 = 0 ;
V_5 -> V_123 [ 0 ] . V_1493 = 0 ;
V_5 -> V_123 [ 0 ] . V_1494 = 0 ;
if ( F_23 ( V_5 , V_1065 ) ) {
for ( V_42 = 1 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
V_5 -> V_123 [ V_42 ] . V_1091 = 0 ;
V_5 -> V_123 [ V_42 ] . V_147 = 0 ;
if ( F_23 ( V_5 , V_1107 ) )
F_52 ( V_5 -> V_123 [ V_42 ] . V_1317 , 0 ) ;
F_314 ( V_5 -> V_123 [ V_42 ] . V_1210 , 0 ) ;
F_47 ( V_5 -> V_123 [ V_42 ] . V_124 , 1 ) ;
V_5 -> V_123 [ V_42 ] . V_1492 = 0 ;
V_5 -> V_123 [ V_42 ] . V_1493 = 0 ;
V_5 -> V_123 [ V_42 ] . V_1494 = 0 ;
}
if ( ! F_23 ( V_5 , V_1107 ) )
F_52 ( V_5 -> V_123 [ 0 ] . V_1317 , 0 ) ;
} else {
V_5 -> V_123 [ 0 ] . V_1091 = 0 ;
V_5 -> V_123 [ 0 ] . V_147 = 0 ;
F_52 ( V_5 -> V_123 [ 0 ] . V_1317 , 0 ) ;
F_314 ( V_5 -> V_123 [ 0 ] . V_1210 , 0 ) ;
}
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_33 = V_1495 + V_16 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
F_391 ( V_33 + V_42 * 8 , 0 ) ;
}
memset ( V_131 -> V_134 , 0 , V_1346 ) ;
F_46 ( V_1496 + V_1457 ,
( ( T_6 ) V_131 -> V_1351 >> 32 ) ) ;
F_46 ( V_1496 + V_16 ,
( ( T_6 ) V_131 -> V_1351 & 0xffffffff ) ) ;
V_1491 = V_1497 ;
for ( V_42 = 1 , V_131 ++ ; V_42 < V_5 -> V_129 ; V_42 ++ , V_131 ++ ) {
T_6 V_1119 = ( T_6 ) V_131 -> V_1351 ;
F_46 ( V_1491 + V_1457 , V_1119 >> 32 ) ;
F_46 ( V_1491 + V_16 , V_1119 & 0xffffffff ) ;
V_1491 += 8 ;
memset ( V_131 -> V_134 , 0 , V_1346 ) ;
}
F_444 ( V_5 ) ;
F_446 ( V_5 ) ;
}
static void F_448 ( struct V_4 * V_5 )
{
T_1 V_7 , V_1498 , V_1499 , V_1500 ;
if ( ! F_23 ( V_5 , 5750_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_30 ( V_5 ) == V_1501 ||
F_30 ( V_5 ) == V_641 ||
F_23 ( V_5 , 57765_PLUS ) )
V_1498 = V_1502 ;
else if ( F_30 ( V_5 ) == V_1490 ||
F_30 ( V_5 ) == V_1503 )
V_1498 = V_1504 ;
else
V_1498 = V_1505 ;
V_1500 = F_321 ( V_1498 / 2 , V_5 -> V_1208 ) ;
V_1499 = F_449 ( T_1 , V_5 -> V_1339 / 8 , 1 ) ;
V_7 = F_321 ( V_1500 , V_1499 ) ;
F_46 ( V_1506 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1507 , V_1498 ) ;
if ( ! F_23 ( V_5 , V_522 ) || F_23 ( V_5 , 5780_CLASS ) )
return;
V_1498 = V_1508 ;
V_1499 = F_449 ( T_1 , V_5 -> V_1343 / 8 , 1 ) ;
V_7 = F_321 ( V_1498 / 2 , V_1499 ) ;
F_46 ( V_1509 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1510 , V_1498 ) ;
}
static inline T_1 F_450 ( unsigned char * V_627 , int V_74 )
{
T_1 V_161 ;
T_1 V_597 ;
int V_628 , V_1511 ;
V_161 = 0xffffffff ;
for ( V_628 = 0 ; V_628 < V_74 ; V_628 ++ ) {
V_161 ^= V_627 [ V_628 ] ;
for ( V_1511 = 0 ; V_1511 < 8 ; V_1511 ++ ) {
V_597 = V_161 & 0x01 ;
V_161 >>= 1 ;
if ( V_597 )
V_161 ^= 0xedb88320 ;
}
}
return ~ V_161 ;
}
static void F_451 ( struct V_4 * V_5 , unsigned int V_1512 )
{
F_46 ( V_1513 , V_1512 ? 0xffffffff : 0 ) ;
F_46 ( V_1514 , V_1512 ? 0xffffffff : 0 ) ;
F_46 ( V_1515 , V_1512 ? 0xffffffff : 0 ) ;
F_46 ( V_1516 , V_1512 ? 0xffffffff : 0 ) ;
}
static void F_438 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_355 ;
V_355 = V_5 -> V_355 & ~ ( V_1517 |
V_1206 ) ;
#if ! F_359 ( V_1518 ) && ! F_359 ( V_1519 )
if ( ! F_23 ( V_5 , V_309 ) )
V_355 |= V_1206 ;
#endif
if ( V_111 -> V_10 & V_1520 ) {
V_355 |= V_1517 ;
} else if ( V_111 -> V_10 & V_1521 ) {
F_451 ( V_5 , 1 ) ;
} else if ( F_452 ( V_111 ) ) {
F_451 ( V_5 , 0 ) ;
} else {
struct V_1522 * V_1523 ;
T_1 V_1524 [ 4 ] = { 0 , } ;
T_1 V_1525 ;
T_1 V_44 ;
T_1 V_1526 ;
F_453 (ha, dev) {
V_1526 = F_450 ( V_1523 -> V_184 , V_1527 ) ;
V_44 = ~ V_1526 & 0x7f ;
V_1525 = ( V_44 & 0x60 ) >> 5 ;
V_44 &= 0x1f ;
V_1524 [ V_1525 ] |= ( 1 << V_44 ) ;
}
F_46 ( V_1513 , V_1524 [ 0 ] ) ;
F_46 ( V_1514 , V_1524 [ 1 ] ) ;
F_46 ( V_1515 , V_1524 [ 2 ] ) ;
F_46 ( V_1516 , V_1524 [ 3 ] ) ;
}
if ( F_454 ( V_111 ) > F_455 ( V_5 ) ) {
V_355 |= V_1517 ;
} else if ( ! ( V_111 -> V_10 & V_1520 ) ) {
int V_42 = 0 ;
struct V_1522 * V_1523 ;
F_456 (ha, dev) {
F_194 ( V_5 , V_1523 -> V_184 ,
V_42 + F_457 ( V_5 ) ) ;
V_42 ++ ;
}
}
if ( V_355 != V_5 -> V_355 ) {
V_5 -> V_355 = V_355 ;
F_31 ( V_362 , V_355 ) ;
F_24 ( 10 ) ;
}
}
static void F_458 ( struct V_4 * V_5 , T_1 V_1528 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1529 ; V_42 ++ )
V_5 -> V_1530 [ V_42 ] = F_459 ( V_42 , V_1528 ) ;
}
static void F_460 ( struct V_4 * V_5 )
{
int V_42 ;
if ( ! F_23 ( V_5 , V_1065 ) )
return;
if ( V_5 -> V_1222 == 1 ) {
memset ( & V_5 -> V_1530 [ 0 ] , 0 , sizeof( V_5 -> V_1530 ) ) ;
return;
}
for ( V_42 = 0 ; V_42 < V_1529 ; V_42 ++ ) {
if ( V_5 -> V_1530 [ V_42 ] >= V_5 -> V_1222 )
break;
}
if ( V_42 != V_1529 )
F_458 ( V_5 , V_5 -> V_1222 ) ;
}
static void F_461 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_161 = V_1531 ;
while ( V_42 < V_1529 ) {
T_1 V_7 = V_5 -> V_1530 [ V_42 ] ;
V_42 ++ ;
for (; V_42 % 8 ; V_42 ++ ) {
V_7 <<= 4 ;
V_7 |= V_5 -> V_1530 [ V_42 ] ;
}
F_46 ( V_161 , V_7 ) ;
V_161 += 4 ;
}
}
static inline T_1 F_462 ( struct V_4 * V_5 )
{
if ( F_30 ( V_5 ) == V_478 )
return V_1532 ;
else
return V_1533 ;
}
static int F_463 ( struct V_4 * V_5 , bool V_1534 )
{
T_1 V_7 , V_1535 ;
int V_42 , V_75 , V_202 ;
struct V_1131 * V_1132 = & V_5 -> V_123 [ 0 ] . V_1093 ;
F_45 ( V_5 ) ;
F_93 ( V_5 ) ;
F_94 ( V_5 , V_96 ) ;
if ( F_23 ( V_5 , V_563 ) )
F_421 ( V_5 , 1 ) ;
if ( ( V_5 -> V_178 & V_570 ) &&
! ( V_5 -> V_178 & V_1536 ) ) {
F_209 ( V_5 ) ;
F_132 ( V_5 , NULL ) ;
V_5 -> V_178 |= V_1536 ;
}
if ( V_5 -> V_178 & V_339 )
F_222 ( V_5 ) ;
if ( V_1534 )
F_144 ( V_5 ) ;
V_75 = F_429 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_96 ( V_5 , V_96 ) ;
if ( F_146 ( V_5 ) == V_504 ) {
V_7 = F_33 ( V_505 ) ;
V_7 &= ~ ( V_1537 | V_1538 ) ;
F_46 ( V_505 , V_7 ) ;
V_7 = F_33 ( V_1539 ) ;
V_7 &= ~ V_1540 ;
V_7 |= V_1541 ;
F_46 ( V_1539 , V_7 ) ;
V_7 = F_33 ( V_1542 ) ;
V_7 &= ~ V_1543 ;
V_7 |= V_1544 ;
F_46 ( V_1542 , V_7 ) ;
V_7 = F_33 ( V_1545 ) ;
V_7 &= ~ V_1546 ;
V_7 |= V_1547 ;
F_46 ( V_1545 , V_7 ) ;
}
if ( F_30 ( V_5 ) == V_1407 ) {
V_7 = F_33 ( V_976 ) & ~ V_977 ;
V_7 |= V_1548 |
V_1549 ;
F_46 ( V_976 , V_7 ) ;
V_7 = F_33 ( V_1550 ) & ~ V_1551 ;
F_46 ( V_1550 , V_7 | V_1552 ) ;
F_46 ( V_1553 , V_1554 ) ;
V_7 = F_33 ( V_1408 ) & ~ V_1409 ;
F_46 ( V_1408 , V_7 | V_1410 ) ;
}
if ( F_23 ( V_5 , V_1555 ) ) {
T_1 V_645 = F_33 ( V_647 ) ;
V_7 = V_645 & ~ V_1556 ;
F_46 ( V_647 , V_7 | V_1557 ) ;
V_7 = F_33 ( V_1084 + V_1558 ) ;
F_46 ( V_1084 + V_1558 ,
V_7 | V_1559 ) ;
F_46 ( V_647 , V_645 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) ) {
if ( F_77 ( V_5 ) == V_328 ) {
T_1 V_645 = F_33 ( V_647 ) ;
V_7 = V_645 & ~ V_1556 ;
F_46 ( V_647 , V_7 | V_1557 ) ;
V_7 = F_33 ( V_1084 +
V_1560 ) ;
F_46 ( V_1084 + V_1560 ,
V_7 | V_1561 ) ;
F_46 ( V_647 , V_645 ) ;
}
if ( F_146 ( V_5 ) != V_1562 ) {
T_1 V_645 ;
V_7 = F_33 ( V_1563 ) ;
V_7 |= V_1564 ;
F_46 ( V_1563 , V_7 ) ;
V_645 = F_33 ( V_647 ) ;
V_7 = V_645 & ~ V_1556 ;
F_46 ( V_647 , V_7 | V_1565 ) ;
V_7 = F_33 ( V_1084 +
V_1566 ) ;
V_7 &= ~ V_1567 ;
F_46 ( V_1084 + V_1566 ,
V_7 | V_1568 ) ;
F_46 ( V_647 , V_645 ) ;
}
V_7 = F_33 ( V_1539 ) ;
V_7 &= ~ V_1540 ;
V_7 |= V_1541 ;
F_46 ( V_1539 , V_7 ) ;
}
if ( ! F_23 ( V_5 , V_152 ) ) {
if ( ! F_23 ( V_5 , V_1083 ) )
V_5 -> V_156 |= V_1569 ;
F_31 ( V_153 , V_5 -> V_156 ) ;
}
if ( F_77 ( V_5 ) == V_919 &&
F_23 ( V_5 , V_842 ) ) {
V_7 = F_33 ( V_1244 ) ;
V_7 |= V_1384 ;
F_46 ( V_1244 , V_7 ) ;
}
if ( F_23 ( V_5 , V_60 ) ) {
V_7 = F_33 ( V_1244 ) ;
V_7 |= V_1385 |
V_1386 |
V_1387 ;
F_46 ( V_1244 , V_7 ) ;
}
if ( F_146 ( V_5 ) == V_1570 ) {
V_7 = F_33 ( V_1571 ) ;
V_7 |= ( 1 << 26 ) | ( 1 << 28 ) | ( 1 << 29 ) ;
F_46 ( V_1571 , V_7 ) ;
}
V_75 = F_411 ( V_5 ) ;
if ( V_75 )
return V_75 ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1572 ) &
~ V_1573 ;
if ( F_77 ( V_5 ) == V_328 )
V_7 &= ~ V_1574 ;
if ( ! F_23 ( V_5 , 57765_CLASS ) &&
F_30 ( V_5 ) != V_477 &&
F_30 ( V_5 ) != V_768 )
V_7 |= V_1575 ;
F_46 ( V_1572 , V_7 | V_5 -> V_1576 ) ;
} else if ( F_30 ( V_5 ) != V_414 &&
F_30 ( V_5 ) != V_45 ) {
F_46 ( V_1572 , V_5 -> V_1576 ) ;
}
V_5 -> V_645 &= ~ ( V_1577 |
V_1578 |
V_1579 |
V_1580 ) ;
V_5 -> V_645 |= V_1577 ;
V_5 -> V_645 |= V_1579 ;
V_7 = V_1581 | V_1582 ;
if ( V_5 -> V_1583 )
F_46 ( V_1584 ,
V_5 -> V_1583 | V_1585 ) ;
if ( F_23 ( V_5 , V_993 ) )
V_7 |= V_1586 ;
F_46 ( V_647 , V_5 -> V_645 | V_7 ) ;
V_7 = F_33 ( V_498 ) ;
V_7 &= ~ 0xff ;
V_7 |= ( 65 << V_969 ) ;
F_46 ( V_498 , V_7 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
} else if ( F_30 ( V_5 ) != V_502 ) {
F_46 ( V_1587 , V_1588 ) ;
if ( F_30 ( V_5 ) == V_501 )
F_46 ( V_1589 , V_1590 ) ;
else
F_46 ( V_1589 , V_1591 ) ;
F_46 ( V_1592 , V_1593 ) ;
F_46 ( V_1594 , V_1595 ) ;
} else if ( F_23 ( V_5 , V_1596 ) ) {
int V_662 ;
V_662 = V_5 -> V_662 ;
V_662 = ( V_662 + ( 0x80 - 1 ) ) & ~ ( 0x80 - 1 ) ;
F_46 ( V_1587 ,
V_685 + V_662 ) ;
F_46 ( V_1589 ,
V_1597 - V_662 - 0xa00 ) ;
}
if ( V_5 -> V_111 -> V_1202 <= V_1329 ) {
F_46 ( V_1598 ,
V_5 -> V_1599 . V_1600 ) ;
F_46 ( V_1601 ,
V_5 -> V_1599 . V_1602 ) ;
F_46 ( V_1603 ,
V_5 -> V_1599 . V_1604 ) ;
} else {
F_46 ( V_1598 ,
V_5 -> V_1599 . V_1605 ) ;
F_46 ( V_1601 ,
V_5 -> V_1599 . V_1606 ) ;
F_46 ( V_1603 ,
V_5 -> V_1599 . V_1607 ) ;
}
F_46 ( V_1608 ,
V_5 -> V_1599 . V_1609 ) ;
F_46 ( V_1610 ,
V_5 -> V_1599 . V_1611 ) ;
V_7 = V_1378 | V_1612 ;
if ( F_30 ( V_5 ) == V_478 )
V_7 |= V_1613 ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_768 ||
F_77 ( V_5 ) == V_1614 ||
F_77 ( V_5 ) == V_1615 )
V_7 |= V_1616 ;
F_46 ( V_1068 , V_7 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
if ( F_33 ( V_1068 ) & V_1378 )
break;
F_24 ( 10 ) ;
}
if ( V_42 >= 2000 ) {
F_185 ( V_5 -> V_111 , L_54 , V_658 ) ;
return - V_82 ;
}
if ( F_77 ( V_5 ) == V_1617 )
F_46 ( V_1618 , ( F_33 ( V_1618 ) & ~ 0x3 ) | 0x2 ) ;
F_448 ( V_5 ) ;
F_46 ( V_1619 + V_1456 + V_1457 ,
( ( T_6 ) V_1132 -> V_1344 >> 32 ) ) ;
F_46 ( V_1619 + V_1456 + V_16 ,
( ( T_6 ) V_1132 -> V_1344 & 0xffffffff ) ) ;
if ( ! F_23 ( V_5 , 5717_PLUS ) )
F_46 ( V_1619 + V_1459 ,
V_1620 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1621 + V_1458 ,
V_1486 ) ;
if ( F_77 ( V_5 ) == V_1614 ||
( F_23 ( V_5 , V_522 ) && ! F_23 ( V_5 , 5780_CLASS ) ) ) {
if ( F_23 ( V_5 , V_1341 ) ) {
F_46 ( V_1058 + V_1456 + V_1457 ,
( ( T_6 ) V_1132 -> V_1345 >> 32 ) ) ;
F_46 ( V_1058 + V_1456 + V_16 ,
( ( T_6 ) V_1132 -> V_1345 & 0xffffffff ) ) ;
V_7 = F_464 ( V_5 ) <<
V_1487 ;
F_46 ( V_1058 + V_1458 ,
V_7 | V_1622 ) ;
if ( ! F_23 ( V_5 , V_1305 ) ||
F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_768 )
F_46 ( V_1058 + V_1459 ,
V_1623 ) ;
} else {
F_46 ( V_1058 + V_1458 ,
V_1486 ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_465 ( V_5 ) ;
V_7 <<= V_1487 ;
V_7 |= ( V_1333 << 2 ) ;
} else
V_7 = V_1333 << V_1487 ;
} else
V_7 = V_1624 << V_1487 ;
F_46 ( V_1619 + V_1458 , V_7 ) ;
V_1132 -> V_1094 = V_5 -> V_1339 ;
F_314 ( V_18 , V_1132 -> V_1094 ) ;
V_1132 -> V_1096 =
F_23 ( V_5 , V_1341 ) ? V_5 -> V_1343 : 0 ;
F_314 ( V_1212 , V_1132 -> V_1096 ) ;
F_447 ( V_5 ) ;
F_195 ( V_5 , false ) ;
F_46 ( V_1625 ,
V_5 -> V_111 -> V_1202 + V_1203 + V_1185 + V_1626 ) ;
V_7 = ( 2 << V_388 ) |
( 6 << V_389 ) |
( 32 << V_390 ) ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_768 )
V_7 |= F_33 ( V_387 ) &
( V_970 |
V_971 ) ;
F_46 ( V_387 , V_7 ) ;
F_46 ( V_1627 , V_1628 ) ;
F_46 ( V_1629 , 0x0181 ) ;
V_1535 = ( V_1372 | V_1630 |
V_1631 | V_1632 |
V_1633 | V_1634 |
V_1635 | V_1636 |
V_1637 ) ;
if ( F_30 ( V_5 ) == V_477 )
V_1535 |= V_1638 ;
if ( F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1407 )
V_1535 |= V_1639 |
V_1640 |
V_1641 ;
if ( F_30 ( V_5 ) == V_502 &&
F_77 ( V_5 ) != V_1430 ) {
if ( F_23 ( V_5 , V_1596 ) &&
F_30 ( V_5 ) == V_502 ) {
V_1535 |= V_1642 ;
} else if ( ! ( F_33 ( V_1244 ) & V_1643 ) &&
! F_23 ( V_5 , V_1644 ) ) {
V_1535 |= V_1645 ;
}
}
if ( F_23 ( V_5 , V_1083 ) )
V_1535 |= V_1645 ;
if ( F_30 ( V_5 ) == V_668 ) {
V_5 -> V_1260 = 0 ;
if ( V_5 -> V_111 -> V_1202 <= V_1329 ) {
V_1535 |= V_1646 ;
V_5 -> V_1260 = V_1647 ;
}
}
if ( F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) )
V_1535 |= V_1648 ;
if ( F_23 ( V_5 , 57765_PLUS ) ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1407 )
V_1535 |= V_1649 ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_768 )
V_1535 |= F_33 ( V_1069 ) & V_1650 ;
if ( F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1407 ||
F_23 ( V_5 , 57765_PLUS ) ) {
T_1 V_1651 ;
if ( F_30 ( V_5 ) == V_768 )
V_1651 = V_1652 ;
else
V_1651 = V_1653 ;
V_7 = F_33 ( V_1651 ) ;
if ( F_77 ( V_5 ) == V_1614 ||
F_30 ( V_5 ) == V_768 ) {
V_7 &= ~ ( V_1654 |
V_1655 |
V_1656 ) ;
V_7 |= V_1657 |
V_1658 |
V_1659 ;
}
F_46 ( V_1651 , V_7 | V_1660 ) ;
}
if ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_768 ) {
T_1 V_1651 ;
if ( F_30 ( V_5 ) == V_768 )
V_1651 = V_1661 ;
else
V_1651 = V_1662 ;
V_7 = F_33 ( V_1651 ) ;
F_46 ( V_1651 , V_7 |
V_1663 |
V_1664 ) ;
}
if ( F_23 ( V_5 , 5750_PLUS ) ) {
V_7 = F_33 ( V_1665 ) ;
V_7 &= ~ V_1666 ;
F_46 ( V_1665 , V_7 ) ;
} else if ( ( V_1535 & V_1642 ) &&
F_23 ( V_5 , V_1596 ) ) {
V_7 = F_33 ( V_1665 ) ;
V_7 &= ~ V_1667 ;
F_46 ( V_1665 , V_7 ) ;
} else {
F_46 ( V_1665 , 0xffffff ) ;
}
F_46 ( V_1668 , V_1669 ) ;
F_46 ( V_1670 , 0xffffff ) ;
F_46 ( V_1671 ,
( V_1672 |
V_1673 ) ) ;
F_46 ( V_138 , 0 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
if ( ! ( F_33 ( V_138 ) & V_128 ) )
break;
F_24 ( 10 ) ;
}
F_442 ( V_5 , & V_5 -> V_973 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_46 ( V_1674 + V_1457 ,
( ( T_6 ) V_5 -> V_1354 >> 32 ) ) ;
F_46 ( V_1674 + V_16 ,
( ( T_6 ) V_5 -> V_1354 & 0xffffffff ) ) ;
F_46 ( V_1675 , V_37 ) ;
F_46 ( V_1676 , V_1677 ) ;
for ( V_42 = V_37 ;
V_42 < V_1677 + V_1346 ;
V_42 += sizeof( T_1 ) ) {
F_29 ( V_5 , V_42 , 0 ) ;
F_24 ( 40 ) ;
}
}
F_46 ( V_138 , V_128 | V_5 -> V_127 ) ;
F_46 ( V_1062 , V_1368 | V_1678 ) ;
F_46 ( V_1055 , V_1364 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1063 , V_1365 | V_1679 ) ;
if ( V_5 -> V_178 & V_306 ) {
V_5 -> V_178 &= ~ V_791 ;
F_31 ( V_362 , V_1326 ) ;
F_24 ( 10 ) ;
}
V_5 -> V_368 |= V_1680 | V_1681 |
V_733 | V_1682 |
V_1683 ;
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_368 |= V_731 | V_732 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_568 ) &&
F_30 ( V_5 ) != V_537 )
V_5 -> V_368 |= V_726 ;
F_31 ( V_383 , V_5 -> V_368 | V_1684 | V_1685 ) ;
F_24 ( 40 ) ;
if ( ! F_23 ( V_5 , V_533 ) ) {
T_1 V_1686 ;
V_1686 = V_541 | V_539 |
V_542 | V_543 |
V_540 | V_547 ;
if ( F_30 ( V_5 ) == V_641 )
V_1686 |= V_550 |
V_1687 ;
if ( F_30 ( V_5 ) == V_1490 )
V_1686 |= V_1688 ;
V_5 -> V_22 &= ~ V_1686 ;
V_5 -> V_22 |= F_33 ( V_136 ) & V_1686 ;
if ( F_23 ( V_5 , V_644 ) )
V_5 -> V_22 |= ( V_539 |
V_540 ) ;
}
F_31 ( V_136 , V_5 -> V_22 ) ;
F_24 ( 100 ) ;
if ( F_23 ( V_5 , V_1689 ) ) {
V_7 = F_33 ( V_1079 ) ;
V_7 |= V_1401 ;
if ( V_5 -> V_129 > 1 )
V_7 |= V_1690 ;
if ( ! F_23 ( V_5 , 1SHOT_MSI ) )
V_7 |= V_1691 ;
F_46 ( V_1079 , V_7 ) ;
}
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_31 ( V_1080 , V_1374 ) ;
F_24 ( 40 ) ;
}
V_7 = ( V_1376 | V_1692 |
V_1693 | V_1694 |
V_1695 | V_1696 |
V_1697 | V_1698 |
V_1699 ) ;
if ( F_30 ( V_5 ) == V_502 &&
F_77 ( V_5 ) != V_1430 ) {
if ( F_23 ( V_5 , V_1596 ) &&
( F_77 ( V_5 ) == V_1700 ||
F_77 ( V_5 ) == V_1701 ) ) {
} else if ( ! ( F_33 ( V_1244 ) & V_1643 ) &&
! F_23 ( V_5 , V_1644 ) ) {
V_7 |= V_1702 ;
}
}
if ( F_23 ( V_5 , 5755_PLUS ) )
V_7 |= V_1703 ;
if ( F_30 ( V_5 ) == V_257 )
V_7 |= V_1704 ;
F_31 ( V_1070 , V_7 ) ;
F_24 ( 40 ) ;
if ( F_23 ( V_5 , V_842 ) ) {
T_3 V_1392 ;
F_423 ( V_5 -> V_12 , V_5 -> V_1393 + V_1394 ,
& V_1392 ) ;
if ( F_30 ( V_5 ) == V_500 ) {
V_1392 &= ~ V_1705 ;
V_1392 |= V_1706 ;
} else if ( F_30 ( V_5 ) == V_501 ) {
V_1392 &= ~ ( V_1707 | V_1705 ) ;
V_1392 |= V_1706 ;
}
F_425 ( V_5 -> V_12 , V_5 -> V_1393 + V_1394 ,
V_1392 ) ;
}
F_31 ( V_1069 , V_1535 ) ;
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ) {
for ( V_42 = 0 ; V_42 < V_1708 ; V_42 ++ ) {
if ( F_33 ( V_1709 + ( V_42 << 2 ) ) > F_466 ( V_5 ) )
break;
}
if ( V_42 < V_1708 ) {
V_7 = F_33 ( V_1662 ) ;
V_7 |= F_462 ( V_5 ) ;
F_46 ( V_1662 , V_7 ) ;
F_84 ( V_5 , 5719_5720_RDMA_BUG ) ;
}
}
F_46 ( V_1060 , V_1367 | V_1710 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1064 , V_1377 ) ;
if ( F_30 ( V_5 ) == V_45 )
F_46 ( V_1051 ,
V_1373 | V_1711 ) ;
else
F_46 ( V_1051 , V_1373 ) ;
F_46 ( V_1054 , V_1375 | V_1712 ) ;
F_46 ( V_1061 , V_1363 | V_1713 ) ;
V_7 = V_1366 | V_1714 ;
if ( F_23 ( V_5 , V_1715 ) )
V_7 |= V_1716 ;
F_46 ( V_1057 , V_7 ) ;
F_46 ( V_1050 , V_1371 ) ;
if ( F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) )
F_46 ( V_1050 , V_1371 | 0x8 ) ;
V_7 = V_1370 | V_1717 ;
if ( F_23 ( V_5 , V_1107 ) )
V_7 |= V_1718 ;
F_46 ( V_1053 , V_7 ) ;
F_46 ( V_1052 , V_1369 | V_1719 ) ;
if ( F_77 ( V_5 ) == V_760 ) {
V_75 = F_190 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
if ( F_30 ( V_5 ) == V_668 ) {
F_192 ( V_5 ) ;
}
if ( F_23 ( V_5 , V_1596 ) ) {
V_75 = F_193 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
V_5 -> V_357 = V_1361 ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
V_5 -> V_357 |= V_1720 ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_768 ) {
V_7 = V_1721 | V_1722 ;
V_5 -> V_357 &= ~ V_7 ;
V_5 -> V_357 |= F_33 ( V_364 ) & V_7 ;
}
F_31 ( V_364 , V_5 -> V_357 ) ;
F_24 ( 100 ) ;
if ( F_23 ( V_5 , V_1211 ) ) {
F_461 ( V_5 ) ;
F_46 ( V_1723 , 0x5f865437 ) ;
F_46 ( V_1724 , 0xe4ac62cc ) ;
F_46 ( V_1725 , 0x50103a45 ) ;
F_46 ( V_1726 , 0x36621985 ) ;
F_46 ( V_1727 , 0xbf14c0e8 ) ;
F_46 ( V_1728 , 0x1bc27a1e ) ;
F_46 ( V_1729 , 0x84f4b556 ) ;
F_46 ( V_1730 , 0x094ea6fe ) ;
F_46 ( V_1731 , 0x7dda01e7 ) ;
F_46 ( V_1732 , 0xc04d7481 ) ;
}
V_5 -> V_355 = V_734 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_5 -> V_355 |= V_1733 ;
if ( F_30 ( V_5 ) == V_768 )
V_5 -> V_355 |= V_1734 ;
if ( F_23 ( V_5 , V_1211 ) )
V_5 -> V_355 |= V_1735 |
V_1736 |
V_1737 |
V_1738 |
V_1739 |
V_1740 ;
F_31 ( V_362 , V_5 -> V_355 ) ;
F_24 ( 10 ) ;
F_46 ( V_728 , V_5 -> V_564 ) ;
F_46 ( V_384 , V_386 ) ;
if ( V_5 -> V_178 & V_568 ) {
F_31 ( V_362 , V_1326 ) ;
F_24 ( 10 ) ;
}
F_31 ( V_362 , V_5 -> V_355 ) ;
F_24 ( 10 ) ;
if ( V_5 -> V_178 & V_568 ) {
if ( ( F_30 ( V_5 ) == V_501 ) &&
! ( V_5 -> V_178 & V_1741 ) ) {
V_7 = F_33 ( V_574 ) ;
V_7 &= 0xfffff000 ;
V_7 |= 0x880 ;
F_46 ( V_574 , V_7 ) ;
}
if ( F_77 ( V_5 ) == V_1742 )
F_46 ( V_574 , 0x616000 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) )
V_7 = 1 ;
else
V_7 = 2 ;
F_31 ( V_1743 , V_7 ) ;
if ( F_30 ( V_5 ) == V_501 &&
( V_5 -> V_178 & V_568 ) ) {
F_84 ( V_5 , V_941 ) ;
}
if ( ( V_5 -> V_178 & V_306 ) &&
F_30 ( V_5 ) == V_549 ) {
T_1 V_597 ;
V_597 = F_33 ( V_1744 ) ;
F_46 ( V_1744 , V_597 | V_1745 ) ;
V_5 -> V_22 &= ~ V_1746 ;
V_5 -> V_22 |= V_1747 ;
F_46 ( V_136 , V_5 -> V_22 ) ;
}
if ( ! F_23 ( V_5 , V_267 ) ) {
if ( V_5 -> V_178 & V_400 )
V_5 -> V_178 &= ~ V_400 ;
V_75 = F_201 ( V_5 , false ) ;
if ( V_75 )
return V_75 ;
if ( ! ( V_5 -> V_178 & V_568 ) &&
! ( V_5 -> V_178 & V_179 ) ) {
T_1 V_597 ;
if ( ! F_57 ( V_5 , V_520 , & V_597 ) ) {
F_59 ( V_5 , V_520 ,
V_597 | V_1748 ) ;
F_57 ( V_5 , V_1749 , & V_597 ) ;
}
}
}
F_438 ( V_5 -> V_111 ) ;
F_46 ( V_1750 , 0xc2000000 & V_1751 ) ;
F_46 ( V_1752 , 0xffffffff & V_1751 ) ;
F_46 ( V_1753 , 0x86000004 & V_1751 ) ;
F_46 ( V_1754 , 0xffffffff & V_1751 ) ;
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) )
V_202 = 8 ;
else
V_202 = 16 ;
if ( F_23 ( V_5 , V_309 ) )
V_202 -= 4 ;
switch ( V_202 ) {
case 16 :
F_46 ( V_1755 , 0 ) ; F_46 ( V_1756 , 0 ) ;
case 15 :
F_46 ( V_1757 , 0 ) ; F_46 ( V_1758 , 0 ) ;
case 14 :
F_46 ( V_1759 , 0 ) ; F_46 ( V_1760 , 0 ) ;
case 13 :
F_46 ( V_1761 , 0 ) ; F_46 ( V_1762 , 0 ) ;
case 12 :
F_46 ( V_1763 , 0 ) ; F_46 ( V_1764 , 0 ) ;
case 11 :
F_46 ( V_1765 , 0 ) ; F_46 ( V_1766 , 0 ) ;
case 10 :
F_46 ( V_1767 , 0 ) ; F_46 ( V_1768 , 0 ) ;
case 9 :
F_46 ( V_1769 , 0 ) ; F_46 ( V_1770 , 0 ) ;
case 8 :
F_46 ( V_1771 , 0 ) ; F_46 ( V_1772 , 0 ) ;
case 7 :
F_46 ( V_1773 , 0 ) ; F_46 ( V_1774 , 0 ) ;
case 6 :
F_46 ( V_1775 , 0 ) ; F_46 ( V_1776 , 0 ) ;
case 5 :
F_46 ( V_1777 , 0 ) ; F_46 ( V_1778 , 0 ) ;
case 4 :
case 3 :
case 2 :
case 1 :
default:
break;
}
if ( F_23 ( V_5 , V_60 ) )
F_11 ( V_5 , V_1779 ,
V_1780 ) ;
F_95 ( V_5 , V_96 ) ;
return 0 ;
}
static int F_467 ( struct V_4 * V_5 , bool V_1534 )
{
F_196 ( V_5 ) ;
F_97 ( V_5 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
return F_463 ( V_5 , V_1534 ) ;
}
static void F_468 ( struct V_4 * V_5 , struct V_1781 * V_1782 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1783 ; V_42 ++ , V_1782 ++ ) {
T_1 V_6 = V_42 * V_1784 , V_74 = V_1784 ;
F_40 ( V_5 , ( T_1 * ) V_1782 , V_6 , V_74 ) ;
V_6 += V_74 ;
if ( V_1782 -> V_1785 != V_1786 ||
! ( V_1782 -> V_1787 & V_1788 ) )
memset ( V_1782 , 0 , V_1784 ) ;
}
}
static T_14 F_469 ( struct V_544 * V_111 ,
struct V_1789 * V_1790 , char * V_627 )
{
struct V_1791 * V_1792 = F_470 ( V_1790 ) ;
struct V_4 * V_5 = F_471 ( V_111 ) ;
T_1 V_1793 ;
F_70 ( & V_5 -> V_209 ) ;
F_40 ( V_5 , & V_1793 , V_1792 -> V_687 ,
sizeof( V_1793 ) ) ;
F_71 ( & V_5 -> V_209 ) ;
return sprintf ( V_627 , L_55 , V_1793 ) ;
}
static void F_472 ( struct V_4 * V_5 )
{
if ( V_5 -> V_1794 ) {
F_473 ( V_5 -> V_1794 ) ;
V_5 -> V_1794 = NULL ;
}
}
static void F_474 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_635 = 0 ;
struct V_1795 * V_12 = V_5 -> V_12 ;
struct V_1781 V_1796 [ V_1783 ] ;
F_468 ( V_5 , V_1796 ) ;
for ( V_42 = 0 ; V_42 < V_1783 ; V_42 ++ ) {
if ( ! V_1796 [ V_42 ] . V_1797 )
continue;
V_635 += V_1796 [ V_42 ] . V_1798 ;
V_635 += V_1796 [ V_42 ] . V_1797 ;
}
if ( ! V_635 )
return;
V_5 -> V_1794 = F_475 ( & V_12 -> V_111 , L_56 ,
V_5 , V_1799 ) ;
if ( F_116 ( V_5 -> V_1794 ) ) {
V_5 -> V_1794 = NULL ;
F_117 ( & V_12 -> V_111 , L_57 ) ;
}
}
static void F_476 ( struct V_4 * V_5 )
{
struct V_1353 * V_1800 = V_5 -> V_1352 ;
if ( ! V_5 -> V_341 )
return;
F_477 ( & V_1800 -> V_1801 , V_1802 ) ;
F_477 ( & V_1800 -> V_1803 , V_1804 ) ;
F_477 ( & V_1800 -> V_1805 , V_1806 ) ;
F_477 ( & V_1800 -> V_1807 , V_1808 ) ;
F_477 ( & V_1800 -> V_1809 , V_1810 ) ;
F_477 ( & V_1800 -> V_1811 , V_1812 ) ;
F_477 ( & V_1800 -> V_1813 , V_1814 ) ;
F_477 ( & V_1800 -> V_1815 , V_1816 ) ;
F_477 ( & V_1800 -> V_1817 , V_1818 ) ;
F_477 ( & V_1800 -> V_1819 , V_1820 ) ;
F_477 ( & V_1800 -> V_1821 , V_1822 ) ;
F_477 ( & V_1800 -> V_1823 , V_1824 ) ;
F_477 ( & V_1800 -> V_1825 , V_1826 ) ;
if ( F_267 ( F_23 ( V_5 , 5719_5720_RDMA_BUG ) &&
( V_1800 -> V_1821 . V_486 + V_1800 -> V_1823 . V_486 +
V_1800 -> V_1825 . V_486 ) > V_1708 ) ) {
T_1 V_7 ;
V_7 = F_33 ( V_1662 ) ;
V_7 &= ~ F_462 ( V_5 ) ;
F_46 ( V_1662 , V_7 ) ;
F_86 ( V_5 , 5719_5720_RDMA_BUG ) ;
}
F_477 ( & V_1800 -> V_1827 , V_1828 ) ;
F_477 ( & V_1800 -> V_1829 , V_1830 ) ;
F_477 ( & V_1800 -> V_1831 , V_1832 ) ;
F_477 ( & V_1800 -> V_1833 , V_1834 ) ;
F_477 ( & V_1800 -> V_1835 , V_1836 ) ;
F_477 ( & V_1800 -> V_1837 , V_1838 ) ;
F_477 ( & V_1800 -> V_1839 , V_1840 ) ;
F_477 ( & V_1800 -> V_1841 , V_1842 ) ;
F_477 ( & V_1800 -> V_1843 , V_1844 ) ;
F_477 ( & V_1800 -> V_1845 , V_1846 ) ;
F_477 ( & V_1800 -> V_1847 , V_1848 ) ;
F_477 ( & V_1800 -> V_1849 , V_1850 ) ;
F_477 ( & V_1800 -> V_1851 , V_1852 ) ;
F_477 ( & V_1800 -> V_1853 , V_1854 ) ;
F_477 ( & V_1800 -> V_1855 , V_1856 ) ;
if ( F_30 ( V_5 ) != V_477 &&
F_30 ( V_5 ) != V_768 &&
F_77 ( V_5 ) != V_1614 &&
F_77 ( V_5 ) != V_1615 ) {
F_477 ( & V_1800 -> V_1857 , V_1858 ) ;
} else {
T_1 V_7 = F_33 ( V_1231 ) ;
V_7 = ( V_7 & V_1232 ) ? 1 : 0 ;
if ( V_7 ) {
F_46 ( V_1231 , V_1232 ) ;
V_1800 -> V_1857 . V_486 += V_7 ;
if ( V_1800 -> V_1857 . V_486 < V_7 )
V_1800 -> V_1857 . V_487 += 1 ;
}
V_1800 -> V_1859 = V_1800 -> V_1857 ;
}
F_477 ( & V_1800 -> V_1860 , V_1861 ) ;
}
static void F_478 ( struct V_4 * V_5 )
{
T_1 V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( F_50 ( V_131 ) ) {
if ( V_131 -> V_1493 == V_131 -> V_149 &&
V_131 -> V_1494 == V_131 -> V_147 ) {
if ( V_131 -> V_1492 < 1 ) {
V_131 -> V_1492 ++ ;
return;
}
F_348 ( 0 , V_131 ) ;
}
}
V_131 -> V_1492 = 0 ;
V_131 -> V_1493 = V_131 -> V_149 ;
V_131 -> V_1494 = V_131 -> V_147 ;
}
}
static void F_479 ( unsigned long V_1862 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1862 ;
if ( V_5 -> V_125 || F_23 ( V_5 , V_1226 ) )
goto V_1863;
F_317 ( & V_5 -> V_209 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_23 ( V_5 , 57765_CLASS ) )
F_478 ( V_5 ) ;
if ( F_23 ( V_5 , V_30 ) ) {
F_33 ( V_138 ) ;
}
if ( ! F_23 ( V_5 , V_133 ) ) {
if ( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & V_135 ) {
F_46 ( V_136 ,
V_5 -> V_22 | V_137 ) ;
} else {
F_46 ( V_138 , V_5 -> V_127 |
V_128 | V_1864 ) ;
}
if ( ! ( F_33 ( V_1070 ) & V_1376 ) ) {
F_318 ( & V_5 -> V_209 ) ;
F_323 ( V_5 ) ;
goto V_1863;
}
}
if ( ! -- V_5 -> V_1865 ) {
if ( F_23 ( V_5 , 5705_PLUS ) )
F_476 ( V_5 ) ;
if ( V_5 -> V_340 && ! -- V_5 -> V_340 )
F_135 ( V_5 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
T_1 V_1866 ;
int V_1867 ;
V_1866 = F_33 ( V_793 ) ;
V_1867 = 0 ;
if ( V_5 -> V_178 & V_819 ) {
if ( V_1866 & V_1868 )
V_1867 = 1 ;
} else if ( V_1866 & V_797 )
V_1867 = 1 ;
if ( V_1867 )
F_201 ( V_5 , false ) ;
} else if ( F_23 ( V_5 , V_143 ) ) {
T_1 V_1866 = F_33 ( V_793 ) ;
int V_1869 = 0 ;
if ( V_5 -> V_341 &&
( V_1866 & V_797 ) ) {
V_1869 = 1 ;
}
if ( ! V_5 -> V_341 &&
( V_1866 & ( V_914 |
V_929 ) ) ) {
V_1869 = 1 ;
}
if ( V_1869 ) {
if ( ! V_5 -> V_926 ) {
F_31 ( V_383 ,
( V_5 -> V_368 &
~ V_371 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_383 , V_5 -> V_368 ) ;
F_24 ( 40 ) ;
}
F_201 ( V_5 , false ) ;
}
} else if ( ( V_5 -> V_178 & V_306 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_233 ( V_5 ) ;
} else if ( F_23 ( V_5 , V_1870 ) ) {
T_1 V_1871 = F_33 ( V_1872 ) ;
bool V_341 = ! ( ( V_1871 & V_1873 ) ==
V_1873 ) ;
if ( V_341 != V_5 -> V_341 )
F_201 ( V_5 , false ) ;
}
V_5 -> V_1865 = V_5 -> V_1874 ;
}
if ( ! -- V_5 -> V_1875 ) {
if ( F_23 ( V_5 , V_309 ) && ! F_23 ( V_5 , V_60 ) ) {
F_88 ( V_5 ) ;
F_29 ( V_5 , V_310 ,
V_1876 ) ;
F_29 ( V_5 , V_312 , 4 ) ;
F_29 ( V_5 , V_313 ,
V_1877 ) ;
F_87 ( V_5 ) ;
}
V_5 -> V_1875 = V_5 -> V_1878 ;
}
F_318 ( & V_5 -> V_209 ) ;
V_1863:
V_5 -> V_1879 . V_1880 = V_299 + V_5 -> V_1881 ;
F_480 ( & V_5 -> V_1879 ) ;
}
static void F_481 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_133 ) &&
F_30 ( V_5 ) != V_477 &&
! F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_1881 = V_1882 ;
else
V_5 -> V_1881 = V_1882 / 10 ;
F_184 ( V_5 -> V_1881 > V_1882 ) ;
V_5 -> V_1874 = ( V_1882 / V_5 -> V_1881 ) ;
V_5 -> V_1878 = ( V_1882 / V_5 -> V_1881 ) *
V_1883 ;
F_482 ( & V_5 -> V_1879 ) ;
V_5 -> V_1879 . V_72 = ( unsigned long ) V_5 ;
V_5 -> V_1879 . V_1884 = F_479 ;
}
static void F_483 ( struct V_4 * V_5 )
{
V_5 -> V_1875 = V_5 -> V_1878 ;
V_5 -> V_1865 = V_5 -> V_1874 ;
V_5 -> V_1879 . V_1880 = V_299 + V_5 -> V_1881 ;
F_480 ( & V_5 -> V_1879 ) ;
}
static void F_484 ( struct V_4 * V_5 )
{
F_485 ( & V_5 -> V_1879 ) ;
}
static int F_486 ( struct V_4 * V_5 , bool V_1534 )
__releases( V_5 -> V_209 )
__acquires( V_5 -> V_209 )
{
int V_75 ;
V_75 = F_467 ( V_5 , V_1534 ) ;
if ( V_75 ) {
F_185 ( V_5 -> V_111 ,
L_58 ) ;
F_433 ( V_5 , V_110 , 1 ) ;
F_242 ( V_5 ) ;
F_484 ( V_5 ) ;
V_5 -> V_125 = 0 ;
F_335 ( V_5 ) ;
F_487 ( V_5 -> V_111 ) ;
F_241 ( V_5 , 0 ) ;
}
return V_75 ;
}
static void F_488 ( struct V_1885 * V_1886 )
{
struct V_4 * V_5 = F_239 ( V_1886 , struct V_4 , V_1225 ) ;
int V_75 ;
F_241 ( V_5 , 0 ) ;
if ( ! F_145 ( V_5 -> V_111 ) ) {
F_86 ( V_5 , V_1226 ) ;
F_242 ( V_5 ) ;
return;
}
F_242 ( V_5 ) ;
F_123 ( V_5 ) ;
F_341 ( V_5 ) ;
F_241 ( V_5 , 1 ) ;
if ( F_23 ( V_5 , V_1099 ) ) {
V_5 -> V_1098 = F_26 ;
V_5 -> V_1887 = F_17 ;
F_84 ( V_5 , V_31 ) ;
F_86 ( V_5 , V_1099 ) ;
}
F_433 ( V_5 , V_110 , 0 ) ;
V_75 = F_467 ( V_5 , true ) ;
if ( V_75 )
goto V_503;
F_343 ( V_5 ) ;
V_503:
F_242 ( V_5 ) ;
if ( ! V_75 )
F_120 ( V_5 ) ;
F_86 ( V_5 , V_1226 ) ;
}
static int F_489 ( struct V_4 * V_5 , int V_1888 )
{
T_15 V_1889 ;
unsigned long V_10 ;
char * V_269 ;
struct V_130 * V_131 = & V_5 -> V_123 [ V_1888 ] ;
if ( V_5 -> V_129 == 1 )
V_269 = V_5 -> V_111 -> V_269 ;
else {
V_269 = & V_131 -> V_1890 [ 0 ] ;
if ( V_131 -> V_1110 && V_131 -> V_1167 )
snprintf ( V_269 , V_1891 ,
L_59 , V_5 -> V_111 -> V_269 , V_1888 ) ;
else if ( V_131 -> V_1110 )
snprintf ( V_269 , V_1891 ,
L_60 , V_5 -> V_111 -> V_269 , V_1888 ) ;
else if ( V_131 -> V_1167 )
snprintf ( V_269 , V_1891 ,
L_61 , V_5 -> V_111 -> V_269 , V_1888 ) ;
else
snprintf ( V_269 , V_1891 ,
L_62 , V_5 -> V_111 -> V_269 , V_1888 ) ;
V_269 [ V_1891 - 1 ] = 0 ;
}
if ( F_23 ( V_5 , V_1396 ) || F_23 ( V_5 , V_1689 ) ) {
V_1889 = F_348 ;
if ( F_23 ( V_5 , 1SHOT_MSI ) )
V_1889 = F_347 ;
V_10 = 0 ;
} else {
V_1889 = F_350 ;
if ( F_23 ( V_5 , V_133 ) )
V_1889 = F_351 ;
V_10 = V_1892 ;
}
return F_490 ( V_131 -> V_1239 , V_1889 , V_10 , V_269 , V_131 ) ;
}
static int F_491 ( struct V_4 * V_5 )
{
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
struct V_365 * V_111 = V_5 -> V_111 ;
int V_75 , V_42 , V_1893 = 0 ;
T_1 V_7 ;
if ( ! F_145 ( V_111 ) )
return - V_82 ;
F_45 ( V_5 ) ;
F_492 ( V_131 -> V_1239 , V_131 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1079 ) | V_1691 ;
F_46 ( V_1079 , V_7 ) ;
}
V_75 = F_490 ( V_131 -> V_1239 , F_352 ,
V_1892 , V_111 -> V_269 , V_131 ) ;
if ( V_75 )
return V_75 ;
V_131 -> V_134 -> V_57 &= ~ V_135 ;
F_48 ( V_5 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_131 -> V_126 ) ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ ) {
T_1 V_124 , V_120 ;
V_124 = F_493 ( V_131 -> V_124 ) ;
V_120 = F_33 ( V_119 ) ;
if ( ( V_124 != 0 ) ||
( V_120 & V_121 ) ) {
V_1893 = 1 ;
break;
}
if ( F_23 ( V_5 , 57765_PLUS ) &&
V_131 -> V_134 -> V_1085 != V_131 -> V_132 )
F_47 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
F_163 ( 10 ) ;
}
F_45 ( V_5 ) ;
F_492 ( V_131 -> V_1239 , V_131 ) ;
V_75 = F_489 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
if ( V_1893 ) {
if ( F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , 1SHOT_MSI ) ) {
V_7 = F_33 ( V_1079 ) & ~ V_1691 ;
F_46 ( V_1079 , V_7 ) ;
}
return 0 ;
}
return - V_210 ;
}
static int F_494 ( struct V_4 * V_5 )
{
int V_75 ;
T_3 V_1381 ;
if ( ! F_23 ( V_5 , V_1396 ) )
return 0 ;
F_423 ( V_5 -> V_12 , V_1380 , & V_1381 ) ;
F_425 ( V_5 -> V_12 , V_1380 ,
V_1381 & ~ V_1894 ) ;
V_75 = F_491 ( V_5 ) ;
F_425 ( V_5 -> V_12 , V_1380 , V_1381 ) ;
if ( ! V_75 )
return 0 ;
if ( V_75 != - V_210 )
return V_75 ;
F_143 ( V_5 -> V_111 , L_63
L_64
L_65 ) ;
F_492 ( V_5 -> V_123 [ 0 ] . V_1239 , & V_5 -> V_123 [ 0 ] ) ;
F_495 ( V_5 -> V_12 ) ;
F_86 ( V_5 , V_1396 ) ;
V_5 -> V_123 [ 0 ] . V_1239 = V_5 -> V_12 -> V_280 ;
V_75 = F_489 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
F_241 ( V_5 , 1 ) ;
F_433 ( V_5 , V_110 , 1 ) ;
V_75 = F_467 ( V_5 , true ) ;
F_242 ( V_5 ) ;
if ( V_75 )
F_492 ( V_5 -> V_123 [ 0 ] . V_1239 , & V_5 -> V_123 [ 0 ] ) ;
return V_75 ;
}
static int F_496 ( struct V_4 * V_5 )
{
const struct V_660 * V_661 ;
if ( F_497 ( & V_5 -> V_663 , V_5 -> V_1895 , & V_5 -> V_12 -> V_111 ) ) {
F_185 ( V_5 -> V_111 , L_66 ,
V_5 -> V_1895 ) ;
return - V_1896 ;
}
V_661 = (struct V_660 * ) V_5 -> V_663 -> V_72 ;
V_5 -> V_662 = F_172 ( V_661 -> V_74 ) ;
if ( V_5 -> V_662 < ( V_5 -> V_663 -> V_635 - V_664 ) ) {
F_185 ( V_5 -> V_111 , L_67 ,
V_5 -> V_662 , V_5 -> V_1895 ) ;
F_498 ( V_5 -> V_663 ) ;
V_5 -> V_663 = NULL ;
return - V_64 ;
}
V_5 -> V_1895 = NULL ;
return 0 ;
}
static T_1 F_499 ( struct V_4 * V_5 )
{
T_1 V_129 = F_500 ( V_5 -> V_1222 , V_5 -> V_1349 ) ;
if ( V_129 > 1 ) {
V_129 = F_501 ( unsigned , V_129 + 1 , V_5 -> V_122 ) ;
}
return V_129 ;
}
static bool F_502 ( struct V_4 * V_5 )
{
int V_42 , V_629 ;
struct V_1897 V_1898 [ V_1899 ] ;
V_5 -> V_1349 = V_5 -> V_1900 ;
V_5 -> V_1222 = V_5 -> V_1901 ;
if ( ! V_5 -> V_1222 )
V_5 -> V_1222 = F_503 () ;
if ( V_5 -> V_1222 > V_5 -> V_1902 )
V_5 -> V_1222 = V_5 -> V_1902 ;
if ( ! V_5 -> V_1900 )
V_5 -> V_1349 = 1 ;
V_5 -> V_129 = F_499 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
V_1898 [ V_42 ] . V_1257 = V_42 ;
V_1898 [ V_42 ] . V_1903 = 0 ;
}
V_629 = F_504 ( V_5 -> V_12 , V_1898 , V_5 -> V_129 ) ;
if ( V_629 < 0 ) {
return false ;
} else if ( V_629 != 0 ) {
if ( F_504 ( V_5 -> V_12 , V_1898 , V_629 ) )
return false ;
F_505 ( V_5 -> V_111 , L_68 ,
V_5 -> V_129 , V_629 ) ;
V_5 -> V_129 = V_629 ;
V_5 -> V_1222 = F_500 ( V_629 - 1 , 1 ) ;
if ( V_5 -> V_1349 )
V_5 -> V_1349 = F_321 ( V_5 -> V_1222 , V_5 -> V_1904 ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1239 = V_1898 [ V_42 ] . V_1903 ;
if ( F_506 ( V_5 -> V_111 , V_5 -> V_1222 ) ) {
F_507 ( V_5 -> V_12 ) ;
return false ;
}
if ( V_5 -> V_129 == 1 )
return true ;
F_84 ( V_5 , V_1211 ) ;
if ( V_5 -> V_1349 > 1 )
F_84 ( V_5 , V_1107 ) ;
F_508 ( V_5 -> V_111 , V_5 -> V_1349 ) ;
return true ;
}
static void F_509 ( struct V_4 * V_5 )
{
if ( ( F_23 ( V_5 , V_1905 ) || F_23 ( V_5 , V_1065 ) ) &&
! F_23 ( V_5 , V_133 ) ) {
F_143 ( V_5 -> V_111 ,
L_69 ) ;
goto V_1906;
}
if ( F_23 ( V_5 , V_1065 ) && F_502 ( V_5 ) )
F_84 ( V_5 , V_1689 ) ;
else if ( F_23 ( V_5 , V_1905 ) && F_510 ( V_5 -> V_12 ) == 0 )
F_84 ( V_5 , V_1396 ) ;
if ( F_23 ( V_5 , V_1396 ) || F_23 ( V_5 , V_1689 ) ) {
T_1 V_1907 = F_33 ( V_1079 ) ;
if ( F_23 ( V_5 , V_1689 ) && V_5 -> V_129 > 1 )
V_1907 |= V_1690 ;
if ( ! F_23 ( V_5 , 1SHOT_MSI ) )
V_1907 |= V_1691 ;
F_46 ( V_1079 , V_1907 | V_1401 ) ;
}
V_1906:
if ( ! F_23 ( V_5 , V_1689 ) ) {
V_5 -> V_129 = 1 ;
V_5 -> V_123 [ 0 ] . V_1239 = V_5 -> V_12 -> V_280 ;
}
if ( V_5 -> V_129 == 1 ) {
V_5 -> V_1349 = 1 ;
V_5 -> V_1222 = 1 ;
F_508 ( V_5 -> V_111 , 1 ) ;
F_506 ( V_5 -> V_111 , 1 ) ;
}
}
static void F_511 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1689 ) )
F_507 ( V_5 -> V_12 ) ;
else if ( F_23 ( V_5 , V_1396 ) )
F_495 ( V_5 -> V_12 ) ;
F_86 ( V_5 , V_1396 ) ;
F_86 ( V_5 , V_1689 ) ;
F_86 ( V_5 , V_1211 ) ;
F_86 ( V_5 , V_1107 ) ;
}
static int F_512 ( struct V_4 * V_5 , bool V_1534 , bool V_1908 ,
bool V_1909 )
{
struct V_365 * V_111 = V_5 -> V_111 ;
int V_42 , V_75 ;
F_509 ( V_5 ) ;
F_460 ( V_5 ) ;
V_75 = F_419 ( V_5 ) ;
if ( V_75 )
goto V_1910;
F_337 ( V_5 ) ;
F_335 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_75 = F_489 ( V_5 , V_42 ) ;
if ( V_75 ) {
for ( V_42 -- ; V_42 >= 0 ; V_42 -- ) {
V_131 = & V_5 -> V_123 [ V_42 ] ;
F_492 ( V_131 -> V_1239 , V_131 ) ;
}
goto V_1911;
}
}
F_241 ( V_5 , 0 ) ;
if ( V_1909 )
F_42 ( V_5 , V_96 ) ;
V_75 = F_467 ( V_5 , V_1534 ) ;
if ( V_75 ) {
F_433 ( V_5 , V_110 , 1 ) ;
F_408 ( V_5 ) ;
}
F_242 ( V_5 ) ;
if ( V_75 )
goto V_1912;
if ( V_1908 && F_23 ( V_5 , V_1396 ) ) {
V_75 = F_494 ( V_5 ) ;
if ( V_75 ) {
F_241 ( V_5 , 0 ) ;
F_433 ( V_5 , V_110 , 1 ) ;
F_408 ( V_5 ) ;
F_242 ( V_5 ) ;
goto V_1911;
}
if ( ! F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , V_1396 ) ) {
T_1 V_7 = F_33 ( V_1913 ) ;
F_46 ( V_1913 ,
V_7 | V_1914 ) ;
}
}
F_120 ( V_5 ) ;
F_474 ( V_5 ) ;
F_241 ( V_5 , 0 ) ;
F_483 ( V_5 ) ;
F_84 ( V_5 , V_563 ) ;
F_48 ( V_5 ) ;
if ( V_1909 )
F_251 ( V_5 ) ;
else
F_254 ( V_5 ) ;
F_242 ( V_5 ) ;
F_513 ( V_111 ) ;
if ( V_111 -> V_1193 & V_1328 )
F_394 ( V_111 , V_111 -> V_1193 ) ;
return 0 ;
V_1912:
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_492 ( V_131 -> V_1239 , V_131 ) ;
}
V_1911:
F_333 ( V_5 ) ;
F_339 ( V_5 ) ;
F_418 ( V_5 ) ;
V_1910:
F_511 ( V_5 ) ;
return V_75 ;
}
static void F_514 ( struct V_4 * V_5 )
{
int V_42 ;
F_326 ( V_5 ) ;
F_341 ( V_5 ) ;
F_484 ( V_5 ) ;
F_472 ( V_5 ) ;
F_123 ( V_5 ) ;
F_241 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_433 ( V_5 , V_110 , 1 ) ;
F_408 ( V_5 ) ;
F_86 ( V_5 , V_563 ) ;
F_242 ( V_5 ) ;
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_492 ( V_131 -> V_1239 , V_131 ) ;
}
F_511 ( V_5 ) ;
F_339 ( V_5 ) ;
F_418 ( V_5 ) ;
}
static int F_515 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 ;
if ( V_5 -> V_1895 ) {
V_75 = F_496 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_668 ) {
if ( V_75 ) {
F_143 ( V_5 -> V_111 , L_70 ) ;
V_5 -> V_178 &= ~ V_339 ;
} else if ( ! ( V_5 -> V_178 & V_339 ) ) {
F_143 ( V_5 -> V_111 , L_71 ) ;
V_5 -> V_178 |= V_339 ;
}
} else if ( F_77 ( V_5 ) == V_760 ) {
if ( V_75 )
return V_75 ;
} else if ( V_75 ) {
F_143 ( V_5 -> V_111 , L_72 ) ;
F_86 ( V_5 , V_1596 ) ;
} else if ( ! F_23 ( V_5 , V_1596 ) ) {
F_505 ( V_5 -> V_111 , L_73 ) ;
F_84 ( V_5 , V_1596 ) ;
}
}
F_140 ( V_5 ) ;
V_75 = F_197 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_241 ( V_5 , 0 ) ;
F_45 ( V_5 ) ;
F_86 ( V_5 , V_563 ) ;
F_242 ( V_5 ) ;
V_75 = F_512 ( V_5 ,
! ( V_5 -> V_178 & V_570 ) ,
true , true ) ;
if ( V_75 ) {
F_152 ( V_5 , false ) ;
F_198 ( V_5 -> V_12 , V_744 ) ;
}
if ( F_23 ( V_5 , V_993 ) ) {
V_5 -> V_997 = F_516 ( & V_5 -> V_1010 ,
& V_5 -> V_12 -> V_111 ) ;
if ( F_116 ( V_5 -> V_997 ) )
V_5 -> V_997 = NULL ;
}
return V_75 ;
}
static int F_517 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_255 ( V_5 ) ;
F_514 ( V_5 ) ;
memset ( & V_5 -> V_1440 , 0 , sizeof( V_5 -> V_1440 ) ) ;
memset ( & V_5 -> V_1441 , 0 , sizeof( V_5 -> V_1441 ) ) ;
if ( F_430 ( V_5 -> V_12 ) ) {
F_199 ( V_5 ) ;
F_140 ( V_5 ) ;
}
return 0 ;
}
static inline T_6 F_518 ( T_16 * V_7 )
{
return ( ( T_6 ) V_7 -> V_487 << 32 ) | ( ( T_6 ) V_7 -> V_486 ) ;
}
static T_6 F_519 ( struct V_4 * V_5 )
{
struct V_1353 * V_1352 = V_5 -> V_1352 ;
if ( ! ( V_5 -> V_178 & V_568 ) &&
( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) ) {
T_1 V_7 ;
if ( ! F_57 ( V_5 , V_520 , & V_7 ) ) {
F_59 ( V_5 , V_520 ,
V_7 | V_1748 ) ;
F_57 ( V_5 , V_1749 , & V_7 ) ;
} else
V_7 = 0 ;
V_5 -> V_1915 += V_7 ;
return V_5 -> V_1915 ;
}
return F_518 ( & V_1352 -> V_1837 ) ;
}
static void F_435 ( struct V_4 * V_5 , struct V_1916 * V_1917 )
{
struct V_1916 * V_1918 = & V_5 -> V_1441 ;
struct V_1353 * V_1352 = V_5 -> V_1352 ;
F_520 ( V_1827 ) ;
F_520 ( V_1829 ) ;
F_520 ( V_1831 ) ;
F_520 ( V_1833 ) ;
F_520 ( V_1835 ) ;
F_520 ( V_1837 ) ;
F_520 ( V_1839 ) ;
F_520 ( V_1841 ) ;
F_520 ( V_1843 ) ;
F_520 ( V_1845 ) ;
F_520 ( V_1847 ) ;
F_520 ( V_1849 ) ;
F_520 ( V_1851 ) ;
F_520 ( V_1853 ) ;
F_520 ( V_1919 ) ;
F_520 ( V_1920 ) ;
F_520 ( V_1921 ) ;
F_520 ( V_1922 ) ;
F_520 ( V_1923 ) ;
F_520 ( V_1924 ) ;
F_520 ( V_1925 ) ;
F_520 ( V_1926 ) ;
F_520 ( V_1927 ) ;
F_520 ( V_1928 ) ;
F_520 ( V_1929 ) ;
F_520 ( V_1930 ) ;
F_520 ( V_1801 ) ;
F_520 ( V_1803 ) ;
F_520 ( V_1805 ) ;
F_520 ( V_1807 ) ;
F_520 ( V_1931 ) ;
F_520 ( V_1809 ) ;
F_520 ( V_1811 ) ;
F_520 ( V_1813 ) ;
F_520 ( V_1815 ) ;
F_520 ( V_1817 ) ;
F_520 ( V_1819 ) ;
F_520 ( V_1932 ) ;
F_520 ( V_1933 ) ;
F_520 ( V_1934 ) ;
F_520 ( V_1935 ) ;
F_520 ( V_1936 ) ;
F_520 ( V_1937 ) ;
F_520 ( V_1938 ) ;
F_520 ( V_1939 ) ;
F_520 ( V_1940 ) ;
F_520 ( V_1941 ) ;
F_520 ( V_1942 ) ;
F_520 ( V_1943 ) ;
F_520 ( V_1944 ) ;
F_520 ( V_1945 ) ;
F_520 ( V_1821 ) ;
F_520 ( V_1823 ) ;
F_520 ( V_1825 ) ;
F_520 ( V_1946 ) ;
F_520 ( V_1947 ) ;
F_520 ( V_1948 ) ;
F_520 ( V_1949 ) ;
F_520 ( V_1950 ) ;
F_520 ( V_1855 ) ;
F_520 ( V_1857 ) ;
F_520 ( V_1860 ) ;
F_520 ( V_1951 ) ;
F_520 ( V_1952 ) ;
F_520 ( V_1953 ) ;
F_520 ( V_1954 ) ;
F_520 ( V_1955 ) ;
F_520 ( V_1956 ) ;
F_520 ( V_1957 ) ;
F_520 ( V_1958 ) ;
F_520 ( V_1959 ) ;
F_520 ( V_1859 ) ;
}
static void F_434 ( struct V_4 * V_5 , struct V_1960 * V_1961 )
{
struct V_1960 * V_1962 = & V_5 -> V_1440 ;
struct V_1353 * V_1352 = V_5 -> V_1352 ;
V_1961 -> V_1963 = V_1962 -> V_1963 +
F_518 ( & V_1352 -> V_1831 ) +
F_518 ( & V_1352 -> V_1833 ) +
F_518 ( & V_1352 -> V_1835 ) ;
V_1961 -> V_1964 = V_1962 -> V_1964 +
F_518 ( & V_1352 -> V_1821 ) +
F_518 ( & V_1352 -> V_1823 ) +
F_518 ( & V_1352 -> V_1825 ) ;
V_1961 -> V_1965 = V_1962 -> V_1965 +
F_518 ( & V_1352 -> V_1827 ) ;
V_1961 -> V_1966 = V_1962 -> V_1966 +
F_518 ( & V_1352 -> V_1801 ) ;
V_1961 -> V_1860 = V_1962 -> V_1860 +
F_518 ( & V_1352 -> V_1860 ) ;
V_1961 -> V_1948 = V_1962 -> V_1948 +
F_518 ( & V_1352 -> V_1948 ) +
F_518 ( & V_1352 -> V_1809 ) +
F_518 ( & V_1352 -> V_1946 ) +
F_518 ( & V_1352 -> V_1947 ) ;
V_1961 -> V_1967 = V_1962 -> V_1967 +
F_518 ( & V_1352 -> V_1833 ) ;
V_1961 -> V_1968 = V_1962 -> V_1968 +
F_518 ( & V_1352 -> V_1803 ) ;
V_1961 -> V_1969 = V_1962 -> V_1969 +
F_518 ( & V_1352 -> V_1849 ) +
F_518 ( & V_1352 -> V_1853 ) ;
V_1961 -> V_1970 = V_1962 -> V_1970 +
F_518 ( & V_1352 -> V_1839 ) ;
V_1961 -> V_1971 = V_1962 -> V_1971 +
F_518 ( & V_1352 -> V_1947 ) ;
V_1961 -> V_1972 = V_1962 -> V_1972 +
F_518 ( & V_1352 -> V_1946 ) ;
V_1961 -> V_1973 = V_1962 -> V_1973 +
F_519 ( V_5 ) ;
V_1961 -> V_1974 = V_1962 -> V_1974 +
F_518 ( & V_1352 -> V_1857 ) ;
V_1961 -> V_1180 = V_5 -> V_1180 ;
V_1961 -> V_1319 = V_5 -> V_1319 ;
}
static int F_521 ( struct V_365 * V_111 )
{
return V_1081 ;
}
static void F_522 ( struct V_365 * V_111 ,
struct V_1975 * V_8 , void * V_1976 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_8 -> V_1977 = 0 ;
memset ( V_1976 , 0 , V_1081 ) ;
if ( V_5 -> V_178 & V_400 )
return;
F_241 ( V_5 , 0 ) ;
F_259 ( V_5 , ( T_1 * ) V_1976 ) ;
F_242 ( V_5 ) ;
}
static int F_523 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
return V_5 -> V_1978 ;
}
static int F_524 ( struct V_365 * V_111 , struct V_1979 * V_1980 , T_4 * V_72 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_56 ;
T_4 * V_1981 ;
T_1 V_42 , V_596 , V_74 , V_1982 , V_1983 ;
T_5 V_7 ;
if ( F_23 ( V_5 , V_682 ) )
return - V_64 ;
V_596 = V_1980 -> V_596 ;
V_74 = V_1980 -> V_74 ;
V_1980 -> V_74 = 0 ;
V_1980 -> V_1984 = V_1985 ;
if ( V_596 & 3 ) {
V_1982 = V_596 & 3 ;
V_1983 = 4 - V_1982 ;
if ( V_1983 > V_74 ) {
V_1983 = V_74 ;
}
V_56 = F_169 ( V_5 , V_596 - V_1982 , & V_7 ) ;
if ( V_56 )
return V_56 ;
memcpy ( V_72 , ( ( char * ) & V_7 ) + V_1982 , V_1983 ) ;
V_74 -= V_1983 ;
V_596 += V_1983 ;
V_1980 -> V_74 += V_1983 ;
}
V_1981 = & V_72 [ V_1980 -> V_74 ] ;
for ( V_42 = 0 ; V_42 < ( V_74 - ( V_74 & 3 ) ) ; V_42 += 4 ) {
V_56 = F_169 ( V_5 , V_596 + V_42 , & V_7 ) ;
if ( V_56 ) {
V_1980 -> V_74 += V_42 ;
return V_56 ;
}
memcpy ( V_1981 + V_42 , & V_7 , 4 ) ;
}
V_1980 -> V_74 += V_42 ;
if ( V_74 & 3 ) {
V_1981 = & V_72 [ V_1980 -> V_74 ] ;
V_1983 = V_74 & 3 ;
V_1982 = V_596 + V_74 - V_1983 ;
V_56 = F_169 ( V_5 , V_1982 , & V_7 ) ;
if ( V_56 )
return V_56 ;
memcpy ( V_1981 , & V_7 , V_1983 ) ;
V_1980 -> V_74 += V_1983 ;
}
return 0 ;
}
static int F_525 ( struct V_365 * V_111 , struct V_1979 * V_1980 , T_4 * V_72 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_56 ;
T_1 V_596 , V_74 , V_1982 , V_1986 ;
T_4 * V_627 ;
T_5 V_1032 , V_1987 ;
if ( F_23 ( V_5 , V_682 ) ||
V_1980 -> V_1984 != V_1985 )
return - V_64 ;
V_596 = V_1980 -> V_596 ;
V_74 = V_1980 -> V_74 ;
if ( ( V_1982 = ( V_596 & 3 ) ) ) {
V_56 = F_169 ( V_5 , V_596 - V_1982 , & V_1032 ) ;
if ( V_56 )
return V_56 ;
V_74 += V_1982 ;
V_596 &= ~ 3 ;
if ( V_74 < 4 )
V_74 = 4 ;
}
V_1986 = 0 ;
if ( V_74 & 3 ) {
V_1986 = 1 ;
V_74 = ( V_74 + 3 ) & ~ 3 ;
V_56 = F_169 ( V_5 , V_596 + V_74 - 4 , & V_1987 ) ;
if ( V_56 )
return V_56 ;
}
V_627 = V_72 ;
if ( V_1982 || V_1986 ) {
V_627 = F_174 ( V_74 , V_633 ) ;
if ( ! V_627 )
return - V_268 ;
if ( V_1982 )
memcpy ( V_627 , & V_1032 , 4 ) ;
if ( V_1986 )
memcpy ( V_627 + V_74 - 4 , & V_1987 , 4 ) ;
memcpy ( V_627 + V_1982 , V_72 , V_1980 -> V_74 ) ;
}
V_56 = F_177 ( V_5 , V_596 , V_74 , V_627 ) ;
if ( V_627 != V_72 )
F_175 ( V_627 ) ;
return V_56 ;
}
static int F_526 ( struct V_365 * V_111 , struct V_1988 * V_643 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_392 ) )
return - V_85 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
return F_527 ( V_212 , V_643 ) ;
}
V_643 -> V_394 = ( V_1989 ) ;
if ( ! ( V_5 -> V_178 & V_393 ) )
V_643 -> V_394 |= ( V_1990 |
V_1991 ) ;
if ( ! ( V_5 -> V_178 & V_360 ) ) {
V_643 -> V_394 |= ( V_1992 |
V_1993 |
V_1994 |
V_1995 |
V_1996 ) ;
V_643 -> V_1997 = V_1998 ;
} else {
V_643 -> V_394 |= V_1999 ;
V_643 -> V_1997 = V_2000 ;
}
V_643 -> V_399 = V_5 -> V_330 . V_399 ;
if ( F_23 ( V_5 , V_359 ) ) {
if ( V_5 -> V_330 . V_343 & V_338 ) {
if ( V_5 -> V_330 . V_343 & V_337 ) {
V_643 -> V_399 |= V_705 ;
} else {
V_643 -> V_399 |= V_705 |
V_2001 ;
}
} else if ( V_5 -> V_330 . V_343 & V_337 ) {
V_643 -> V_399 |= V_2001 ;
}
}
if ( F_145 ( V_111 ) && V_5 -> V_341 ) {
F_528 ( V_643 , V_5 -> V_330 . V_331 ) ;
V_643 -> V_377 = V_5 -> V_330 . V_334 ;
V_643 -> V_2002 = V_5 -> V_330 . V_370 ;
if ( ! ( V_5 -> V_178 & V_360 ) ) {
if ( V_5 -> V_178 & V_824 )
V_643 -> V_2003 = V_2004 ;
else
V_643 -> V_2003 = V_2005 ;
}
} else {
F_528 ( V_643 , V_754 ) ;
V_643 -> V_377 = V_755 ;
V_643 -> V_2003 = V_2006 ;
}
V_643 -> V_2007 = V_5 -> V_160 ;
V_643 -> V_2008 = V_2009 ;
V_643 -> V_353 = V_5 -> V_330 . V_353 ;
V_643 -> V_2010 = 0 ;
V_643 -> V_2011 = 0 ;
return 0 ;
}
static int F_529 ( struct V_365 * V_111 , struct V_1988 * V_643 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_373 = F_530 ( V_643 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_392 ) )
return - V_85 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
return F_531 ( V_212 , V_643 ) ;
}
if ( V_643 -> V_353 != V_358 &&
V_643 -> V_353 != V_780 )
return - V_64 ;
if ( V_643 -> V_353 == V_780 &&
V_643 -> V_377 != V_335 &&
V_643 -> V_377 != V_378 )
return - V_64 ;
if ( V_643 -> V_353 == V_358 ) {
T_1 V_2012 = V_706 |
V_705 |
V_2001 ;
if ( ! ( V_5 -> V_178 & V_393 ) )
V_2012 |= V_774 |
V_764 ;
if ( ! ( V_5 -> V_178 & V_360 ) )
V_2012 |= V_709 |
V_710 |
V_707 |
V_711 |
V_704 ;
else
V_2012 |= V_781 ;
if ( V_643 -> V_399 & ~ V_2012 )
return - V_64 ;
V_2012 &= ( V_774 |
V_764 |
V_709 |
V_710 |
V_707 |
V_711 ) ;
V_643 -> V_399 &= V_2012 ;
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
F_241 ( V_5 , 0 ) ;
V_5 -> V_330 . V_353 = V_643 -> V_353 ;
if ( V_643 -> V_353 == V_358 ) {
V_5 -> V_330 . V_399 = ( V_643 -> V_399 |
V_706 ) ;
V_5 -> V_330 . V_373 = V_754 ;
V_5 -> V_330 . V_377 = V_755 ;
} else {
V_5 -> V_330 . V_399 = 0 ;
V_5 -> V_330 . V_373 = V_373 ;
V_5 -> V_330 . V_377 = V_643 -> V_377 ;
}
V_5 -> V_178 |= V_1536 ;
F_142 ( V_5 ) ;
if ( F_145 ( V_111 ) )
F_201 ( V_5 , true ) ;
F_242 ( V_5 ) ;
return 0 ;
}
static void F_532 ( struct V_365 * V_111 , struct V_2013 * V_988 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_533 ( V_988 -> V_2014 , V_2015 , sizeof( V_988 -> V_2014 ) ) ;
F_533 ( V_988 -> V_1977 , V_2016 , sizeof( V_988 -> V_1977 ) ) ;
F_533 ( V_988 -> V_2017 , V_5 -> V_2018 , sizeof( V_988 -> V_2017 ) ) ;
F_533 ( V_988 -> V_2019 , F_534 ( V_5 -> V_12 ) , sizeof( V_988 -> V_2019 ) ) ;
}
static void F_535 ( struct V_365 * V_111 , struct V_2020 * V_2021 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_23 ( V_5 , V_718 ) && F_536 ( & V_5 -> V_12 -> V_111 ) )
V_2021 -> V_394 = V_2022 ;
else
V_2021 -> V_394 = 0 ;
V_2021 -> V_2023 = 0 ;
if ( F_23 ( V_5 , V_112 ) && F_536 ( & V_5 -> V_12 -> V_111 ) )
V_2021 -> V_2023 = V_2022 ;
memset ( & V_2021 -> V_2024 , 0 , sizeof( V_2021 -> V_2024 ) ) ;
}
static int F_537 ( struct V_365 * V_111 , struct V_2020 * V_2021 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_544 * V_2025 = & V_5 -> V_12 -> V_111 ;
if ( V_2021 -> V_2023 & ~ V_2022 )
return - V_64 ;
if ( ( V_2021 -> V_2023 & V_2022 ) &&
! ( F_23 ( V_5 , V_718 ) && F_536 ( V_2025 ) ) )
return - V_64 ;
F_538 ( V_2025 , V_2021 -> V_2023 & V_2022 ) ;
if ( F_44 ( V_2025 ) )
F_84 ( V_5 , V_112 ) ;
else
F_86 ( V_5 , V_112 ) ;
return 0 ;
}
static T_1 F_539 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
return V_5 -> V_2026 ;
}
static void F_540 ( struct V_365 * V_111 , T_1 V_2027 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_5 -> V_2026 = V_2027 ;
}
static int F_541 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_2028 ;
if ( ! F_145 ( V_111 ) )
return - V_85 ;
if ( V_5 -> V_178 & V_568 )
return - V_64 ;
F_142 ( V_5 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
if ( ! ( V_5 -> V_178 & V_392 ) )
return - V_85 ;
V_2028 = F_122 ( V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ) ;
} else {
T_1 V_775 ;
F_70 ( & V_5 -> V_209 ) ;
V_2028 = - V_64 ;
F_57 ( V_5 , V_204 , & V_775 ) ;
if ( ! F_57 ( V_5 , V_204 , & V_775 ) &&
( ( V_775 & V_577 ) ||
( V_5 -> V_178 & V_791 ) ) ) {
F_59 ( V_5 , V_204 , V_775 | V_578 |
V_577 ) ;
V_2028 = 0 ;
}
F_71 ( & V_5 -> V_209 ) ;
}
return V_2028 ;
}
static void F_542 ( struct V_365 * V_111 , struct V_2029 * V_2030 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_2030 -> V_2031 = V_5 -> V_1142 ;
if ( F_23 ( V_5 , V_1341 ) )
V_2030 -> V_2032 = V_5 -> V_1147 ;
else
V_2030 -> V_2032 = 0 ;
V_2030 -> V_2033 = V_1100 - 1 ;
V_2030 -> V_1339 = V_5 -> V_1339 ;
if ( F_23 ( V_5 , V_1341 ) )
V_2030 -> V_1343 = V_5 -> V_1343 ;
else
V_2030 -> V_1343 = 0 ;
V_2030 -> V_1092 = V_5 -> V_123 [ 0 ] . V_1092 ;
}
static int F_543 ( struct V_365 * V_111 , struct V_2029 * V_2030 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_42 , V_125 = 0 , V_75 = 0 ;
if ( ( V_2030 -> V_1339 > V_5 -> V_1142 ) ||
( V_2030 -> V_1343 > V_5 -> V_1147 ) ||
( V_2030 -> V_1092 > V_1100 - 1 ) ||
( V_2030 -> V_1092 <= V_1318 ) ||
( F_23 ( V_5 , V_1294 ) &&
( V_2030 -> V_1092 <= ( V_1318 * 3 ) ) ) )
return - V_64 ;
if ( F_145 ( V_111 ) ) {
F_123 ( V_5 ) ;
F_341 ( V_5 ) ;
V_125 = 1 ;
}
F_241 ( V_5 , V_125 ) ;
V_5 -> V_1339 = V_2030 -> V_1339 ;
if ( F_23 ( V_5 , V_2034 ) &&
V_5 -> V_1339 > 63 )
V_5 -> V_1339 = 63 ;
V_5 -> V_1343 = V_2030 -> V_1343 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1092 = V_2030 -> V_1092 ;
if ( F_145 ( V_111 ) ) {
F_433 ( V_5 , V_110 , 1 ) ;
V_75 = F_486 ( V_5 , false ) ;
if ( ! V_75 )
F_343 ( V_5 ) ;
}
F_242 ( V_5 ) ;
if ( V_125 && ! V_75 )
F_120 ( V_5 ) ;
return V_75 ;
}
static void F_544 ( struct V_365 * V_111 , struct V_2035 * V_2036 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_2036 -> V_353 = ! ! F_23 ( V_5 , V_359 ) ;
if ( V_5 -> V_330 . V_343 & V_338 )
V_2036 -> V_2037 = 1 ;
else
V_2036 -> V_2037 = 0 ;
if ( V_5 -> V_330 . V_343 & V_337 )
V_2036 -> V_2038 = 1 ;
else
V_2036 -> V_2038 = 0 ;
}
static int F_545 ( struct V_365 * V_111 , struct V_2035 * V_2036 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 = 0 ;
if ( V_5 -> V_330 . V_353 == V_358 )
F_142 ( V_5 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
T_1 V_955 ;
struct V_211 * V_212 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
if ( ! ( V_212 -> V_394 & V_396 ) ||
( ! ( V_212 -> V_394 & V_397 ) &&
( V_2036 -> V_2037 != V_2036 -> V_2038 ) ) )
return - V_64 ;
V_5 -> V_330 . V_343 = 0 ;
if ( V_2036 -> V_2037 ) {
V_5 -> V_330 . V_343 |= V_338 ;
if ( V_2036 -> V_2038 ) {
V_5 -> V_330 . V_343 |= V_337 ;
V_955 = V_705 ;
} else
V_955 = V_705 |
V_2001 ;
} else if ( V_2036 -> V_2038 ) {
V_5 -> V_330 . V_343 |= V_337 ;
V_955 = V_2001 ;
} else
V_955 = 0 ;
if ( V_2036 -> V_353 )
F_84 ( V_5 , V_359 ) ;
else
F_86 ( V_5 , V_359 ) ;
if ( V_5 -> V_178 & V_392 ) {
T_1 V_2039 = V_212 -> V_399 &
( V_705 | V_2001 ) ;
if ( V_2039 != V_955 ) {
V_212 -> V_399 &=
~ ( V_705 |
V_2001 ) ;
V_212 -> V_399 |= V_955 ;
if ( V_212 -> V_353 ) {
return F_122 ( V_212 ) ;
}
}
if ( ! V_2036 -> V_353 )
F_108 ( V_5 , 0 , 0 ) ;
} else {
V_5 -> V_330 . V_399 &=
~ ( V_705 |
V_2001 ) ;
V_5 -> V_330 . V_399 |= V_955 ;
}
} else {
int V_125 = 0 ;
if ( F_145 ( V_111 ) ) {
F_341 ( V_5 ) ;
V_125 = 1 ;
}
F_241 ( V_5 , V_125 ) ;
if ( V_2036 -> V_353 )
F_84 ( V_5 , V_359 ) ;
else
F_86 ( V_5 , V_359 ) ;
if ( V_2036 -> V_2037 )
V_5 -> V_330 . V_343 |= V_338 ;
else
V_5 -> V_330 . V_343 &= ~ V_338 ;
if ( V_2036 -> V_2038 )
V_5 -> V_330 . V_343 |= V_337 ;
else
V_5 -> V_330 . V_343 &= ~ V_337 ;
if ( F_145 ( V_111 ) ) {
F_433 ( V_5 , V_110 , 1 ) ;
V_75 = F_486 ( V_5 , false ) ;
if ( ! V_75 )
F_343 ( V_5 ) ;
}
F_242 ( V_5 ) ;
}
V_5 -> V_178 |= V_1536 ;
return V_75 ;
}
static int F_546 ( struct V_365 * V_111 , int V_2040 )
{
switch ( V_2040 ) {
case V_2041 :
return V_2042 ;
case V_2043 :
return V_2044 ;
default:
return - V_1041 ;
}
}
static int F_547 ( struct V_365 * V_111 , struct V_2045 * V_988 ,
T_1 * T_17 V_2046 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1065 ) )
return - V_1041 ;
switch ( V_988 -> V_643 ) {
case V_2047 :
if ( F_145 ( V_5 -> V_111 ) )
V_988 -> V_72 = V_5 -> V_1222 ;
else {
V_988 -> V_72 = F_548 () ;
if ( V_988 -> V_72 > V_2048 )
V_988 -> V_72 = V_2048 ;
}
V_988 -> V_72 -= 1 ;
return 0 ;
default:
return - V_1041 ;
}
}
static T_1 F_549 ( struct V_365 * V_111 )
{
T_1 V_635 = 0 ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_23 ( V_5 , V_1065 ) )
V_635 = V_1529 ;
return V_635 ;
}
static int F_550 ( struct V_365 * V_111 , T_1 * V_2049 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1529 ; V_42 ++ )
V_2049 [ V_42 ] = V_5 -> V_1530 [ V_42 ] ;
return 0 ;
}
static int F_551 ( struct V_365 * V_111 , const T_1 * V_2049 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_18 V_42 ;
for ( V_42 = 0 ; V_42 < V_1529 ; V_42 ++ )
V_5 -> V_1530 [ V_42 ] = V_2049 [ V_42 ] ;
if ( ! F_145 ( V_111 ) || ! F_23 ( V_5 , V_1211 ) )
return 0 ;
F_241 ( V_5 , 0 ) ;
F_461 ( V_5 ) ;
F_242 ( V_5 ) ;
return 0 ;
}
static void F_552 ( struct V_365 * V_111 ,
struct V_2050 * V_2051 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_2052 = F_503 () ;
V_2051 -> V_2053 = V_5 -> V_1902 ;
V_2051 -> V_2054 = V_5 -> V_1904 ;
if ( F_145 ( V_111 ) ) {
V_2051 -> V_2055 = V_5 -> V_1222 ;
V_2051 -> V_2056 = V_5 -> V_1349 ;
} else {
if ( V_5 -> V_1901 )
V_2051 -> V_2055 = V_5 -> V_1901 ;
else
V_2051 -> V_2055 = F_321 ( V_2052 , V_5 -> V_1902 ) ;
if ( V_5 -> V_1900 )
V_2051 -> V_2056 = V_5 -> V_1900 ;
else
V_2051 -> V_2056 = F_321 ( V_2052 , V_5 -> V_1904 ) ;
}
}
static int F_553 ( struct V_365 * V_111 ,
struct V_2050 * V_2051 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1065 ) )
return - V_1041 ;
if ( V_2051 -> V_2055 > V_5 -> V_1902 ||
V_2051 -> V_2056 > V_5 -> V_1904 )
return - V_64 ;
V_5 -> V_1901 = V_2051 -> V_2055 ;
V_5 -> V_1900 = V_2051 -> V_2056 ;
if ( ! F_145 ( V_111 ) )
return 0 ;
F_514 ( V_5 ) ;
F_140 ( V_5 ) ;
F_512 ( V_5 , true , false , false ) ;
return 0 ;
}
static void F_554 ( struct V_365 * V_111 , T_1 V_2057 , T_4 * V_627 )
{
switch ( V_2057 ) {
case V_2043 :
memcpy ( V_627 , & V_2058 , sizeof( V_2058 ) ) ;
break;
case V_2041 :
memcpy ( V_627 , & V_2059 , sizeof( V_2059 ) ) ;
break;
default:
F_555 ( 1 ) ;
break;
}
}
static int F_556 ( struct V_365 * V_111 ,
enum V_2060 V_849 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_145 ( V_5 -> V_111 ) )
return - V_85 ;
switch ( V_849 ) {
case V_2061 :
return 1 ;
case V_2062 :
F_46 ( V_728 , V_839 |
V_837 |
V_838 |
V_2063 |
V_943 |
V_2064 |
V_2065 ) ;
break;
case V_2066 :
F_46 ( V_728 , V_839 |
V_943 ) ;
break;
case V_2067 :
F_46 ( V_728 , V_5 -> V_564 ) ;
break;
}
return 0 ;
}
static void F_557 ( struct V_365 * V_111 ,
struct V_2068 * V_1917 , T_6 * V_2069 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_5 -> V_1352 )
F_435 ( V_5 , (struct V_1916 * ) V_2069 ) ;
else
memset ( V_2069 , 0 , sizeof( struct V_1916 ) ) ;
}
static T_5 * F_558 ( struct V_4 * V_5 , T_1 * V_2070 )
{
int V_42 ;
T_5 * V_627 ;
T_1 V_596 = 0 , V_74 = 0 ;
T_1 V_1984 , V_7 ;
if ( F_23 ( V_5 , V_682 ) || F_168 ( V_5 , 0 , & V_1984 ) )
return NULL ;
if ( V_1984 == V_1985 ) {
for ( V_596 = V_2071 ;
V_596 < V_2072 ;
V_596 += V_2073 ) {
if ( F_168 ( V_5 , V_596 , & V_7 ) )
return NULL ;
if ( ( V_7 >> V_2074 ) ==
V_2075 )
break;
}
if ( V_596 != V_2072 ) {
V_74 = ( V_7 & V_2076 ) * 4 ;
if ( F_168 ( V_5 , V_596 + 4 , & V_596 ) )
return NULL ;
V_596 = F_167 ( V_5 , V_596 ) ;
}
}
if ( ! V_596 || ! V_74 ) {
V_596 = V_2077 ;
V_74 = V_2078 ;
}
V_627 = F_174 ( V_74 , V_633 ) ;
if ( V_627 == NULL )
return NULL ;
if ( V_1984 == V_1985 ) {
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 ) {
if ( F_169 ( V_5 , V_596 + V_42 , & V_627 [ V_42 / 4 ] ) )
goto error;
}
} else {
T_4 * V_2079 ;
T_14 V_2080 ;
unsigned int V_2081 = 0 ;
V_2079 = ( T_4 * ) & V_627 [ 0 ] ;
for ( V_42 = 0 ; V_2081 < V_74 && V_42 < 3 ; V_42 ++ , V_2081 += V_2080 , V_2079 += V_2080 ) {
V_2080 = F_559 ( V_5 -> V_12 , V_2081 ,
V_74 - V_2081 , V_2079 ) ;
if ( V_2080 == - V_2082 || V_2080 == - V_2083 )
V_2080 = 0 ;
else if ( V_2080 < 0 )
goto error;
}
if ( V_2081 != V_74 )
goto error;
}
* V_2070 = V_74 ;
return V_627 ;
error:
F_175 ( V_627 ) ;
return NULL ;
}
static int F_560 ( struct V_4 * V_5 )
{
T_1 V_2084 , V_1984 , V_74 ;
T_5 * V_627 ;
int V_42 , V_628 , V_1511 , V_75 = 0 , V_635 ;
if ( F_23 ( V_5 , V_682 ) )
return 0 ;
if ( F_168 ( V_5 , 0 , & V_1984 ) != 0 )
return - V_210 ;
if ( V_1984 == V_1985 )
V_635 = V_2085 ;
else if ( ( V_1984 & V_2086 ) == V_2087 ) {
if ( ( V_1984 & V_2088 ) ==
V_2089 ) {
switch ( V_1984 & V_2090 ) {
case V_2091 :
V_635 = V_2092 ;
break;
case V_2093 :
V_635 = V_2094 ;
break;
case V_2095 :
V_635 = V_2096 ;
break;
case V_2097 :
V_635 = V_2098 ;
break;
case V_2099 :
V_635 = V_2100 ;
break;
case V_2101 :
V_635 = V_2102 ;
break;
default:
return - V_210 ;
}
} else
return 0 ;
} else if ( ( V_1984 & V_2103 ) == V_2104 )
V_635 = V_2105 ;
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
V_1984 = F_172 ( V_627 [ 0 ] ) ;
if ( ( V_1984 & V_2086 ) ==
V_2087 ) {
T_4 * V_2106 = ( T_4 * ) V_627 , V_2107 = 0 ;
if ( ( V_1984 & V_2090 ) ==
V_2093 ) {
for ( V_42 = 0 ; V_42 < V_2108 ; V_42 ++ )
V_2107 += V_2106 [ V_42 ] ;
for ( V_42 = V_2108 + 4 ; V_42 < V_635 ; V_42 ++ )
V_2107 += V_2106 [ V_42 ] ;
} else {
for ( V_42 = 0 ; V_42 < V_635 ; V_42 ++ )
V_2107 += V_2106 [ V_42 ] ;
}
if ( V_2107 == 0 ) {
V_75 = 0 ;
goto V_503;
}
V_75 = - V_210 ;
goto V_503;
}
if ( ( V_1984 & V_2103 ) ==
V_2104 ) {
T_4 V_72 [ V_2109 ] ;
T_4 V_2110 [ V_2109 ] ;
T_4 * V_2106 = ( T_4 * ) V_627 ;
for ( V_42 = 0 , V_628 = 0 , V_1511 = 0 ; V_42 < V_2105 ; V_42 ++ ) {
if ( ( V_42 == 0 ) || ( V_42 == 8 ) ) {
int V_2111 ;
T_4 V_2112 ;
for ( V_2111 = 0 , V_2112 = 0x80 ; V_2111 < 7 ; V_2111 ++ , V_2112 >>= 1 )
V_2110 [ V_1511 ++ ] = V_2106 [ V_42 ] & V_2112 ;
V_42 ++ ;
} else if ( V_42 == 16 ) {
int V_2111 ;
T_4 V_2112 ;
for ( V_2111 = 0 , V_2112 = 0x20 ; V_2111 < 6 ; V_2111 ++ , V_2112 >>= 1 )
V_2110 [ V_1511 ++ ] = V_2106 [ V_42 ] & V_2112 ;
V_42 ++ ;
for ( V_2111 = 0 , V_2112 = 0x80 ; V_2111 < 8 ; V_2111 ++ , V_2112 >>= 1 )
V_2110 [ V_1511 ++ ] = V_2106 [ V_42 ] & V_2112 ;
V_42 ++ ;
}
V_72 [ V_628 ++ ] = V_2106 [ V_42 ] ;
}
V_75 = - V_210 ;
for ( V_42 = 0 ; V_42 < V_2109 ; V_42 ++ ) {
T_4 V_2113 = F_561 ( V_72 [ V_42 ] ) ;
if ( ( V_2113 & 0x1 ) && V_2110 [ V_42 ] )
goto V_503;
else if ( ! ( V_2113 & 0x1 ) && ! V_2110 [ V_42 ] )
goto V_503;
}
V_75 = 0 ;
goto V_503;
}
V_75 = - V_210 ;
V_2084 = F_450 ( ( unsigned char * ) V_627 , 0x10 ) ;
if ( V_2084 != F_562 ( V_627 [ 0x10 / 4 ] ) )
goto V_503;
V_2084 = F_450 ( ( unsigned char * ) & V_627 [ 0x74 / 4 ] , 0x88 ) ;
if ( V_2084 != F_562 ( V_627 [ 0xfc / 4 ] ) )
goto V_503;
F_175 ( V_627 ) ;
V_627 = F_558 ( V_5 , & V_74 ) ;
if ( ! V_627 )
return - V_268 ;
V_42 = F_563 ( ( T_4 * ) V_627 , 0 , V_74 , V_2114 ) ;
if ( V_42 > 0 ) {
V_628 = F_564 ( & ( ( T_4 * ) V_627 ) [ V_42 ] ) ;
if ( V_628 < 0 )
goto V_503;
if ( V_42 + V_2115 + V_628 > V_74 )
goto V_503;
V_42 += V_2115 ;
V_628 = F_565 ( ( T_4 * ) V_627 , V_42 , V_628 ,
V_2116 ) ;
if ( V_628 > 0 ) {
T_4 V_2107 = 0 ;
V_628 += V_2117 ;
for ( V_42 = 0 ; V_42 <= V_628 ; V_42 ++ )
V_2107 += ( ( T_4 * ) V_627 ) [ V_42 ] ;
if ( V_2107 )
goto V_503;
}
}
V_75 = 0 ;
V_503:
F_175 ( V_627 ) ;
return V_75 ;
}
static int F_566 ( struct V_4 * V_5 )
{
int V_42 , F_500 ;
if ( ! F_145 ( V_5 -> V_111 ) )
return - V_82 ;
if ( V_5 -> V_178 & V_360 )
F_500 = V_2118 ;
else
F_500 = V_2119 ;
for ( V_42 = 0 ; V_42 < F_500 ; V_42 ++ ) {
if ( V_5 -> V_341 )
return 0 ;
if ( F_567 ( 1000 ) )
break;
}
return - V_210 ;
}
static int F_568 ( struct V_4 * V_5 )
{
int V_42 , V_2120 , V_2121 ;
T_1 V_596 , V_2122 , V_2123 , V_7 , V_2124 , V_2125 ;
static struct {
T_3 V_596 ;
T_3 V_10 ;
#define F_569 0x1
#define F_570 0x2
#define F_571 0x4
#define F_572 0x8
T_1 V_2122 ;
T_1 V_2123 ;
} V_2126 [] = {
{ V_383 , F_570 ,
0x00000000 , 0x00ef6f8c } ,
{ V_383 , F_569 ,
0x00000000 , 0x01ef6b8c } ,
{ V_793 , F_570 ,
0x03800107 , 0x00000000 } ,
{ V_793 , F_569 ,
0x03800100 , 0x00000000 } ,
{ V_690 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_691 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1625 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_364 , 0x0000 ,
0x00000000 , 0x00000070 } ,
{ V_387 , 0x0000 ,
0x00000000 , 0x00003fff } ,
{ V_362 , F_570 ,
0x00000000 , 0x000007fc } ,
{ V_362 , F_569 ,
0x00000000 , 0x000007dc } ,
{ V_1513 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1514 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1515 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1516 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1058 + 0 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1058 + 4 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1058 + 8 , F_570 ,
0x00000000 , 0x00000003 } ,
{ V_1058 + 0xc , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1619 + 0 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1619 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1619 + 8 , 0x0000 ,
0x00000000 , 0xffff0002 } ,
{ V_1619 + 0xc , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1506 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1506 , F_569 ,
0x00000000 , 0x000003ff } ,
{ V_1509 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_138 , F_570 ,
0x00000000 , 0x00000004 } ,
{ V_138 , F_569 ,
0x00000000 , 0x000000f6 } ,
{ V_1471 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1471 , F_569 ,
0x00000000 , 0x000003ff } ,
{ V_1462 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1462 , F_569 ,
0x00000000 , 0x000003ff } ,
{ V_1473 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1473 , F_569 | F_571 ,
0x00000000 , 0x000000ff } ,
{ V_1464 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1464 , F_569 | F_571 ,
0x00000000 , 0x000000ff } ,
{ V_1479 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1481 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1475 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1475 , F_569 | F_571 ,
0x00000000 , 0x000000ff } ,
{ V_1466 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1466 , F_569 | F_571 ,
0x00000000 , 0x000000ff } ,
{ V_972 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1674 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1674 + 4 , F_570 ,
0x00000000 , 0xffffffff } ,
{ V_1496 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1496 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1675 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1676 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1587 , F_572 ,
0x00000000 , 0x007fff80 } ,
{ V_1589 , F_572 ,
0x00000000 , 0x007fffff } ,
{ V_1598 , 0x0000 ,
0x00000000 , 0x0000003f } ,
{ V_1601 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1603 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1592 , F_570 ,
0xffffffff , 0x00000000 } ,
{ V_1594 , F_570 ,
0xffffffff , 0x00000000 } ,
{ V_2127 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_2128 + 4 , F_570 ,
0x00000000 , 0x000001ff } ,
{ V_2129 + 4 , 0x0000 ,
0x00000000 , 0x000007ff } ,
{ V_2130 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ 0xffff , 0x0000 , 0x00000000 , 0x00000000 } ,
} ;
V_2120 = V_2121 = 0 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_2120 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2121 = 1 ;
}
for ( V_42 = 0 ; V_2126 [ V_42 ] . V_596 != 0xffff ; V_42 ++ ) {
if ( V_2120 && ( V_2126 [ V_42 ] . V_10 & F_570 ) )
continue;
if ( ! V_2120 && ( V_2126 [ V_42 ] . V_10 & F_569 ) )
continue;
if ( F_23 ( V_5 , V_1644 ) &&
( V_2126 [ V_42 ] . V_10 & F_571 ) )
continue;
if ( V_2121 && ( V_2126 [ V_42 ] . V_10 & F_572 ) )
continue;
V_596 = ( T_1 ) V_2126 [ V_42 ] . V_596 ;
V_2122 = V_2126 [ V_42 ] . V_2122 ;
V_2123 = V_2126 [ V_42 ] . V_2123 ;
V_2124 = F_33 ( V_596 ) ;
V_2125 = V_2124 & V_2122 ;
F_46 ( V_596 , 0 ) ;
V_7 = F_33 ( V_596 ) ;
if ( ( ( V_7 & V_2122 ) != V_2125 ) || ( V_7 & V_2123 ) )
goto V_503;
F_46 ( V_596 , V_2122 | V_2123 ) ;
V_7 = F_33 ( V_596 ) ;
if ( ( V_7 & V_2122 ) != V_2125 )
goto V_503;
if ( ( V_7 & V_2123 ) != V_2123 )
goto V_503;
F_46 ( V_596 , V_2124 ) ;
}
return 0 ;
V_503:
if ( F_573 ( V_5 ) )
F_185 ( V_5 -> V_111 ,
L_74 , V_596 ) ;
F_46 ( V_596 , V_2124 ) ;
return - V_210 ;
}
static int F_574 ( struct V_4 * V_5 , T_1 V_596 , T_1 V_74 )
{
static const T_1 V_2131 [] = { 0x00000000 , 0xffffffff , 0xaa55a55a } ;
int V_42 ;
T_1 V_628 ;
for ( V_42 = 0 ; V_42 < F_575 ( V_2131 ) ; V_42 ++ ) {
for ( V_628 = 0 ; V_628 < V_74 ; V_628 += 4 ) {
T_1 V_7 ;
F_29 ( V_5 , V_596 + V_628 , V_2131 [ V_42 ] ) ;
F_32 ( V_5 , V_596 + V_628 , & V_7 ) ;
if ( V_7 != V_2131 [ V_42 ] )
return - V_210 ;
}
}
return 0 ;
}
static int F_576 ( struct V_4 * V_5 )
{
static struct V_2132 {
T_1 V_596 ;
T_1 V_74 ;
} V_2133 [] = {
{ 0x00000000 , 0x00b50 } ,
{ 0x00002000 , 0x1c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2134 [] = {
{ 0x00000100 , 0x0000c } ,
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x01000 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0e000 } ,
{ 0xffffffff , 0x00000 }
} , V_2135 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x00800 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2136 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00400 } ,
{ 0x00006000 , 0x00400 } ,
{ 0x00008000 , 0x01000 } ,
{ 0x00010000 , 0x01000 } ,
{ 0xffffffff , 0x00000 }
} , V_2137 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0x00020000 , 0x13c00 } ,
{ 0xffffffff , 0x00000 }
} , V_2138 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x09800 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0xffffffff , 0x00000 }
} ;
struct V_2132 * V_2139 ;
int V_75 = 0 ;
int V_42 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_2139 = V_2137 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_768 )
V_2139 = V_2138 ;
else if ( F_23 ( V_5 , 5755_PLUS ) )
V_2139 = V_2135 ;
else if ( F_30 ( V_5 ) == V_36 )
V_2139 = V_2136 ;
else if ( F_23 ( V_5 , 5705_PLUS ) )
V_2139 = V_2134 ;
else
V_2139 = V_2133 ;
for ( V_42 = 0 ; V_2139 [ V_42 ] . V_596 != 0xffffffff ; V_42 ++ ) {
V_75 = F_574 ( V_5 , V_2139 [ V_42 ] . V_596 , V_2139 [ V_42 ] . V_74 ) ;
if ( V_75 )
break;
}
return V_75 ;
}
static int F_577 ( struct V_4 * V_5 , T_1 V_2140 , bool V_2141 )
{
T_1 V_2142 , V_2143 , V_2144 , V_1133 ;
T_1 V_1269 = 0 , V_1247 = 0 , V_1169 , V_126 , V_2145 , V_7 ;
T_1 V_1161 ;
struct V_1111 * V_1112 ;
T_4 * V_2146 , * V_2147 ;
T_9 V_1138 ;
int V_2148 , V_2149 , V_2150 , V_42 , V_75 ;
struct V_1136 * V_1137 ;
struct V_130 * V_131 , * V_2151 ;
struct V_1131 * V_1132 = & V_5 -> V_123 [ 0 ] . V_1093 ;
V_131 = & V_5 -> V_123 [ 0 ] ;
V_2151 = & V_5 -> V_123 [ 0 ] ;
if ( V_5 -> V_129 > 1 ) {
if ( F_23 ( V_5 , V_1211 ) )
V_2151 = & V_5 -> V_123 [ 1 ] ;
if ( F_23 ( V_5 , V_1107 ) )
V_131 = & V_5 -> V_123 [ 1 ] ;
}
V_126 = V_131 -> V_126 | V_2151 -> V_126 ;
V_75 = - V_210 ;
V_2149 = V_2140 ;
V_1112 = F_304 ( V_5 -> V_111 , V_2149 ) ;
if ( ! V_1112 )
return - V_268 ;
V_2146 = F_307 ( V_1112 , V_2149 ) ;
memcpy ( V_2146 , V_5 -> V_111 -> V_695 , V_1527 ) ;
memset ( V_2146 + V_1527 , 0x0 , 8 ) ;
F_46 ( V_1625 , V_2149 + V_1185 ) ;
if ( V_2141 ) {
struct V_1287 * V_1288 = (struct V_1287 * ) & V_2146 [ V_1203 ] ;
T_1 V_1290 = V_2152 + V_2153 +
V_2154 ;
memcpy ( V_2146 + V_1527 * 2 , V_2155 ,
sizeof( V_2155 ) ) ;
V_1247 = V_2156 ;
V_7 = V_2149 - V_1527 * 2 - sizeof( V_2155 ) ;
V_2148 = F_578 ( V_7 , V_2156 ) ;
V_1288 -> V_1293 = F_311 ( ( T_3 ) ( V_1247 + V_1290 ) ) ;
V_1269 = ( V_1295 |
V_1296 ) ;
if ( F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ) {
struct V_2157 * V_2158 ;
V_7 = V_1203 + V_2152 ;
V_2158 = (struct V_2157 * ) & V_2146 [ V_7 ] ;
V_2158 -> V_1292 = 0 ;
} else
V_1269 |= V_1285 ;
if ( F_23 ( V_5 , V_1299 ) ) {
V_1247 |= ( V_1290 & 0xc ) << 12 ;
if ( V_1290 & 0x10 )
V_1269 |= 0x00000010 ;
V_1269 |= ( V_1290 & 0x3e0 ) << 5 ;
} else if ( F_23 ( V_5 , V_1298 ) )
V_1247 |= V_1290 << 9 ;
else if ( F_23 ( V_5 , V_1297 ) ||
F_30 ( V_5 ) == V_502 ) {
V_1247 |= ( V_2154 << 9 ) ;
} else {
V_1269 |= ( V_2154 << 10 ) ;
}
V_2145 = V_1527 * 2 + sizeof( V_2155 ) ;
} else {
V_2148 = 1 ;
V_2145 = V_1203 ;
if ( F_23 ( V_5 , V_1305 ) &&
V_2149 > V_1306 )
V_1269 |= V_1307 ;
}
for ( V_42 = V_2145 ; V_42 < V_2149 ; V_42 ++ )
V_2146 [ V_42 ] = ( T_4 ) ( V_42 & 0xff ) ;
V_1138 = F_293 ( V_5 -> V_12 , V_1112 -> V_72 , V_2149 , V_1120 ) ;
if ( F_294 ( V_5 -> V_12 , V_1138 ) ) {
F_276 ( V_1112 ) ;
return - V_210 ;
}
V_7 = V_131 -> V_1091 ;
V_131 -> V_1110 [ V_7 ] . V_1112 = V_1112 ;
F_295 ( & V_131 -> V_1110 [ V_7 ] , V_1119 , V_1138 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_2151 -> V_126 ) ;
F_24 ( 10 ) ;
V_2142 = V_2151 -> V_134 -> V_145 [ 0 ] . V_1089 ;
V_1161 = F_263 ( V_131 ) ;
if ( F_362 ( V_131 , & V_7 , & V_1161 , V_1138 , V_2149 ,
V_1269 | V_1263 , V_1247 , 0 ) ) {
V_131 -> V_1110 [ V_7 ] . V_1112 = NULL ;
F_276 ( V_1112 ) ;
return - V_210 ;
}
V_131 -> V_1091 ++ ;
F_49 () ;
F_391 ( V_131 -> V_1317 , V_131 -> V_1091 ) ;
F_493 ( V_131 -> V_1317 ) ;
F_24 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 35 ; V_42 ++ ) {
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_126 ) ;
F_24 ( 10 ) ;
V_2144 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
V_2143 = V_2151 -> V_134 -> V_145 [ 0 ] . V_1089 ;
if ( ( V_2144 == V_131 -> V_1091 ) &&
( V_2143 == ( V_2142 + V_2148 ) ) )
break;
}
F_363 ( V_131 , V_131 -> V_1091 - 1 , - 1 ) ;
F_276 ( V_1112 ) ;
if ( V_2144 != V_131 -> V_1091 )
goto V_503;
if ( V_2143 != V_2142 + V_2148 )
goto V_503;
V_7 = V_2145 ;
while ( V_2143 != V_2142 ) {
V_1137 = & V_2151 -> V_1167 [ V_2142 ++ ] ;
V_1169 = V_1137 -> V_1172 & V_1173 ;
V_1133 = V_1137 -> V_1172 & V_1174 ;
if ( ( V_1137 -> V_1176 & V_1177 ) != 0 &&
( V_1137 -> V_1176 != V_2159 ) )
goto V_503;
V_2150 = ( ( V_1137 -> V_1182 & V_1183 ) >> V_1184 )
- V_1185 ;
if ( ! V_2141 ) {
if ( V_2150 != V_2149 )
goto V_503;
if ( V_2140 <= V_1333 - V_1185 ) {
if ( V_1133 != V_1141 )
goto V_503;
} else {
if ( V_1133 != V_1146 )
goto V_503;
}
} else if ( ( V_1137 -> V_1186 & V_1195 ) &&
( V_1137 -> V_1196 & V_1197 )
>> V_1198 != 0xffff ) {
goto V_503;
}
if ( V_1133 == V_1141 ) {
V_2147 = V_1132 -> V_1144 [ V_1169 ] . V_72 ;
V_1138 = F_270 ( & V_1132 -> V_1144 [ V_1169 ] ,
V_1119 ) ;
} else if ( V_1133 == V_1146 ) {
V_2147 = V_1132 -> V_1150 [ V_1169 ] . V_72 ;
V_1138 = F_270 ( & V_1132 -> V_1150 [ V_1169 ] ,
V_1119 ) ;
} else
goto V_503;
F_305 ( V_5 -> V_12 , V_1138 , V_2150 ,
V_1129 ) ;
V_2147 += F_290 ( V_5 ) ;
for ( V_42 = V_2145 ; V_42 < V_2150 ; V_42 ++ , V_7 ++ ) {
if ( * ( V_2147 + V_42 ) != ( T_4 ) ( V_7 & 0xff ) )
goto V_503;
}
}
V_75 = 0 ;
V_503:
return V_75 ;
}
static int F_579 ( struct V_4 * V_5 , T_6 * V_72 , bool V_2160 )
{
int V_75 = - V_210 ;
T_1 V_2161 ;
T_1 V_2162 = 9000 ;
if ( V_5 -> V_1260 )
V_2162 = V_5 -> V_1260 - V_1203 ;
V_2161 = V_5 -> V_178 & V_339 ;
V_5 -> V_178 &= ~ V_339 ;
if ( ! F_145 ( V_5 -> V_111 ) ) {
V_72 [ V_2163 ] = V_2164 ;
V_72 [ V_2165 ] = V_2164 ;
if ( V_2160 )
V_72 [ V_2166 ] = V_2164 ;
goto V_186;
}
V_75 = F_463 ( V_5 , true ) ;
if ( V_75 ) {
V_72 [ V_2163 ] = V_2164 ;
V_72 [ V_2165 ] = V_2164 ;
if ( V_2160 )
V_72 [ V_2166 ] = V_2164 ;
goto V_186;
}
if ( F_23 ( V_5 , V_1211 ) ) {
int V_42 ;
for ( V_42 = V_1531 ;
V_42 < V_1531 + V_1529 ; V_42 += 4 )
F_46 ( V_42 , 0x0 ) ;
}
if ( F_30 ( V_5 ) != V_567 &&
! F_23 ( V_5 , V_152 ) ) {
F_392 ( V_5 , true ) ;
if ( F_577 ( V_5 , V_2167 , false ) )
V_72 [ V_2163 ] |= V_2168 ;
if ( F_23 ( V_5 , V_1341 ) &&
F_577 ( V_5 , V_2162 + V_1203 , false ) )
V_72 [ V_2163 ] |= V_2169 ;
F_392 ( V_5 , false ) ;
}
if ( ! ( V_5 -> V_178 & V_568 ) &&
! F_23 ( V_5 , V_267 ) ) {
int V_42 ;
F_393 ( V_5 , 0 , false ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
if ( F_33 ( V_953 ) & V_954 )
break;
F_99 ( 1 ) ;
}
if ( F_577 ( V_5 , V_2167 , false ) )
V_72 [ V_2165 ] |= V_2168 ;
if ( F_23 ( V_5 , V_1596 ) &&
F_577 ( V_5 , V_2167 , true ) )
V_72 [ V_2165 ] |= V_2170 ;
if ( F_23 ( V_5 , V_1341 ) &&
F_577 ( V_5 , V_2162 + V_1203 , false ) )
V_72 [ V_2165 ] |= V_2169 ;
if ( V_2160 ) {
F_393 ( V_5 , 0 , true ) ;
F_99 ( 40 ) ;
if ( F_577 ( V_5 , V_2167 , false ) )
V_72 [ V_2166 ] |=
V_2168 ;
if ( F_23 ( V_5 , V_1596 ) &&
F_577 ( V_5 , V_2167 , true ) )
V_72 [ V_2166 ] |=
V_2170 ;
if ( F_23 ( V_5 , V_1341 ) &&
F_577 ( V_5 , V_2162 + V_1203 , false ) )
V_72 [ V_2166 ] |=
V_2169 ;
}
if ( V_5 -> V_178 & V_514 )
F_128 ( V_5 , true ) ;
}
V_75 = ( V_72 [ V_2163 ] | V_72 [ V_2165 ] |
V_72 [ V_2166 ] ) ? - V_210 : 0 ;
V_186:
V_5 -> V_178 |= V_2161 ;
return V_75 ;
}
static void F_580 ( struct V_365 * V_111 , struct V_2171 * V_2172 ,
T_6 * V_72 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
bool V_2173 = V_2172 -> V_10 & V_2174 ;
if ( V_5 -> V_178 & V_400 ) {
if ( F_197 ( V_5 ) ) {
V_2172 -> V_10 |= V_2175 ;
memset ( V_72 , 1 , sizeof( T_6 ) * V_2042 ) ;
return;
}
F_42 ( V_5 , V_96 ) ;
}
memset ( V_72 , 0 , sizeof( T_6 ) * V_2042 ) ;
if ( F_560 ( V_5 ) != 0 ) {
V_2172 -> V_10 |= V_2175 ;
V_72 [ V_2176 ] = 1 ;
}
if ( ! V_2173 && F_566 ( V_5 ) ) {
V_2172 -> V_10 |= V_2175 ;
V_72 [ V_2177 ] = 1 ;
}
if ( V_2172 -> V_10 & V_2178 ) {
int V_75 , V_762 = 0 , V_125 = 0 ;
if ( F_145 ( V_111 ) ) {
F_123 ( V_5 ) ;
F_341 ( V_5 ) ;
V_125 = 1 ;
}
F_241 ( V_5 , V_125 ) ;
F_433 ( V_5 , V_321 , 1 ) ;
V_75 = F_158 ( V_5 ) ;
F_183 ( V_5 , V_654 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_183 ( V_5 , V_655 ) ;
if ( ! V_75 )
F_159 ( V_5 ) ;
if ( V_5 -> V_178 & V_306 )
F_144 ( V_5 ) ;
if ( F_568 ( V_5 ) != 0 ) {
V_2172 -> V_10 |= V_2175 ;
V_72 [ V_2179 ] = 1 ;
}
if ( F_576 ( V_5 ) != 0 ) {
V_2172 -> V_10 |= V_2175 ;
V_72 [ V_2180 ] = 1 ;
}
if ( V_2173 )
V_2172 -> V_10 |= V_2181 ;
if ( F_579 ( V_5 , V_72 , V_2173 ) )
V_2172 -> V_10 |= V_2175 ;
F_242 ( V_5 ) ;
if ( F_491 ( V_5 ) != 0 ) {
V_2172 -> V_10 |= V_2175 ;
V_72 [ V_2182 ] = 1 ;
}
F_241 ( V_5 , 0 ) ;
F_433 ( V_5 , V_110 , 1 ) ;
if ( F_145 ( V_111 ) ) {
F_84 ( V_5 , V_563 ) ;
V_762 = F_486 ( V_5 , true ) ;
if ( ! V_762 )
F_343 ( V_5 ) ;
}
F_242 ( V_5 ) ;
if ( V_125 && ! V_762 )
F_120 ( V_5 ) ;
}
if ( V_5 -> V_178 & V_400 )
F_199 ( V_5 ) ;
}
static int F_581 ( struct V_365 * V_111 , struct V_2183 * V_2184 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_2185 V_2186 ;
if ( ! F_23 ( V_5 , V_993 ) )
return - V_1041 ;
if ( F_582 ( & V_2186 , V_2184 -> V_2187 , sizeof( V_2186 ) ) )
return - V_2188 ;
if ( V_2186 . V_10 )
return - V_64 ;
if ( V_2186 . V_2189 != V_1001 &&
V_2186 . V_2189 != V_1000 )
return - V_2190 ;
switch ( V_2186 . V_2191 ) {
case V_1003 :
V_5 -> V_1583 = 0 ;
break;
case V_1004 :
V_5 -> V_1583 = V_2192 |
V_2193 ;
break;
case V_2194 :
V_5 -> V_1583 = V_2192 |
V_2195 ;
break;
case V_2196 :
V_5 -> V_1583 = V_2192 |
V_2197 ;
break;
case V_2198 :
V_5 -> V_1583 = V_2199 |
V_2200 ;
break;
case V_1005 :
V_5 -> V_1583 = V_2201 |
V_2200 ;
break;
case V_1006 :
V_5 -> V_1583 = V_2202 |
V_2200 ;
break;
case V_2203 :
V_5 -> V_1583 = V_2199 |
V_2195 ;
break;
case V_2204 :
V_5 -> V_1583 = V_2201 |
V_2195 ;
break;
case V_2205 :
V_5 -> V_1583 = V_2202 |
V_2195 ;
break;
case V_2206 :
V_5 -> V_1583 = V_2199 |
V_2197 ;
break;
case V_2207 :
V_5 -> V_1583 = V_2201 |
V_2197 ;
break;
case V_2208 :
V_5 -> V_1583 = V_2202 |
V_2197 ;
break;
default:
return - V_2190 ;
}
if ( F_145 ( V_111 ) && V_5 -> V_1583 )
F_46 ( V_1584 ,
V_5 -> V_1583 | V_1585 ) ;
if ( V_2186 . V_2189 == V_1001 )
F_84 ( V_5 , V_1311 ) ;
else
F_86 ( V_5 , V_1311 ) ;
return F_583 ( V_2184 -> V_2187 , & V_2186 , sizeof( V_2186 ) ) ?
- V_2188 : 0 ;
}
static int F_584 ( struct V_365 * V_111 , struct V_2183 * V_2184 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_2185 V_2186 ;
if ( ! F_23 ( V_5 , V_993 ) )
return - V_1041 ;
V_2186 . V_10 = 0 ;
V_2186 . V_2189 = ( F_23 ( V_5 , V_1311 ) ?
V_1001 : V_1000 ) ;
switch ( V_5 -> V_1583 ) {
case 0 :
V_2186 . V_2191 = V_1003 ;
break;
case V_2192 | V_2193 :
V_2186 . V_2191 = V_1004 ;
break;
case V_2192 | V_2195 :
V_2186 . V_2191 = V_2194 ;
break;
case V_2192 | V_2197 :
V_2186 . V_2191 = V_2196 ;
break;
case V_2199 | V_2200 :
V_2186 . V_2191 = V_2198 ;
break;
case V_2201 | V_2200 :
V_2186 . V_2191 = V_1005 ;
break;
case V_2202 | V_2200 :
V_2186 . V_2191 = V_1006 ;
break;
case V_2199 | V_2195 :
V_2186 . V_2191 = V_2203 ;
break;
case V_2201 | V_2195 :
V_2186 . V_2191 = V_2204 ;
break;
case V_2202 | V_2195 :
V_2186 . V_2191 = V_2205 ;
break;
case V_2199 | V_2197 :
V_2186 . V_2191 = V_2206 ;
break;
case V_2201 | V_2197 :
V_2186 . V_2191 = V_2207 ;
break;
case V_2202 | V_2197 :
V_2186 . V_2191 = V_2208 ;
break;
default:
F_585 ( 1 ) ;
return - V_2190 ;
}
return F_583 ( V_2184 -> V_2187 , & V_2186 , sizeof( V_2186 ) ) ?
- V_2188 : 0 ;
}
static int F_586 ( struct V_365 * V_111 , struct V_2183 * V_2184 , int V_643 )
{
struct V_2209 * V_72 = F_587 ( V_2184 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 ;
if ( F_23 ( V_5 , V_267 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_392 ) )
return - V_85 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
return F_588 ( V_212 , V_2184 , V_643 ) ;
}
switch ( V_643 ) {
case V_2210 :
V_72 -> V_216 = V_5 -> V_160 ;
case V_2211 : {
T_1 V_2212 ;
if ( V_5 -> V_178 & V_568 )
break;
if ( ! F_145 ( V_111 ) )
return - V_85 ;
F_70 ( & V_5 -> V_209 ) ;
V_75 = F_56 ( V_5 , V_72 -> V_216 & 0x1f ,
V_72 -> V_2213 & 0x1f , & V_2212 ) ;
F_71 ( & V_5 -> V_209 ) ;
V_72 -> V_2214 = V_2212 ;
return V_75 ;
}
case V_2215 :
if ( V_5 -> V_178 & V_568 )
break;
if ( ! F_145 ( V_111 ) )
return - V_85 ;
F_70 ( & V_5 -> V_209 ) ;
V_75 = F_58 ( V_5 , V_72 -> V_216 & 0x1f ,
V_72 -> V_2213 & 0x1f , V_72 -> V_2216 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_75 ;
case V_2217 :
return F_581 ( V_111 , V_2184 ) ;
case V_2218 :
return F_584 ( V_111 , V_2184 ) ;
default:
break;
}
return - V_1041 ;
}
static int F_589 ( struct V_365 * V_111 , struct V_1460 * V_1461 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
memcpy ( V_1461 , & V_5 -> V_973 , sizeof( * V_1461 ) ) ;
return 0 ;
}
static int F_590 ( struct V_365 * V_111 , struct V_1460 * V_1461 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_2219 = 0 , V_2220 = 0 ;
T_1 V_2221 = 0 , V_2222 = 0 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
V_2219 = V_2223 ;
V_2220 = V_2224 ;
V_2221 = V_2225 ;
V_2222 = V_2226 ;
}
if ( ( V_1461 -> V_1472 > V_2227 ) ||
( V_1461 -> V_1463 > V_2228 ) ||
( V_1461 -> V_1474 > V_2229 ) ||
( V_1461 -> V_1465 > V_2230 ) ||
( V_1461 -> V_1480 > V_2219 ) ||
( V_1461 -> V_1482 > V_2220 ) ||
( V_1461 -> V_1476 > V_2231 ) ||
( V_1461 -> V_1467 > V_2232 ) ||
( V_1461 -> V_974 > V_2221 ) ||
( V_1461 -> V_974 < V_2222 ) )
return - V_64 ;
if ( ( V_1461 -> V_1472 == 0 ) &&
( V_1461 -> V_1474 == 0 ) )
return - V_64 ;
if ( ( V_1461 -> V_1463 == 0 ) &&
( V_1461 -> V_1465 == 0 ) )
return - V_64 ;
V_5 -> V_973 . V_1472 = V_1461 -> V_1472 ;
V_5 -> V_973 . V_1463 = V_1461 -> V_1463 ;
V_5 -> V_973 . V_1474 = V_1461 -> V_1474 ;
V_5 -> V_973 . V_1465 = V_1461 -> V_1465 ;
V_5 -> V_973 . V_1480 = V_1461 -> V_1480 ;
V_5 -> V_973 . V_1482 = V_1461 -> V_1482 ;
V_5 -> V_973 . V_1476 = V_1461 -> V_1476 ;
V_5 -> V_973 . V_1467 = V_1461 -> V_1467 ;
V_5 -> V_973 . V_974 = V_1461 -> V_974 ;
if ( F_145 ( V_111 ) ) {
F_241 ( V_5 , 0 ) ;
F_442 ( V_5 , & V_5 -> V_973 ) ;
F_242 ( V_5 ) ;
}
return 0 ;
}
static int F_591 ( struct V_365 * V_111 , struct V_452 * V_2233 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_339 ) ) {
F_143 ( V_5 -> V_111 , L_75 ) ;
return - V_1041 ;
}
if ( V_2233 -> V_464 != V_5 -> V_453 . V_464 ) {
F_143 ( V_5 -> V_111 ,
L_76 ) ;
return - V_64 ;
}
if ( V_2233 -> V_468 > V_2234 ) {
F_143 ( V_5 -> V_111 ,
L_77 ,
V_2234 ) ;
return - V_64 ;
}
V_5 -> V_453 = * V_2233 ;
V_5 -> V_178 |= V_1536 ;
F_142 ( V_5 ) ;
if ( F_145 ( V_5 -> V_111 ) ) {
F_241 ( V_5 , 0 ) ;
F_222 ( V_5 ) ;
F_144 ( V_5 ) ;
F_242 ( V_5 ) ;
}
return 0 ;
}
static int F_592 ( struct V_365 * V_111 , struct V_452 * V_2233 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_339 ) ) {
F_143 ( V_5 -> V_111 ,
L_75 ) ;
return - V_1041 ;
}
* V_2233 = V_5 -> V_453 ;
return 0 ;
}
static struct V_1960 * F_593 ( struct V_365 * V_111 ,
struct V_1960 * V_1961 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_70 ( & V_5 -> V_209 ) ;
if ( ! V_5 -> V_1352 ) {
F_71 ( & V_5 -> V_209 ) ;
return & V_5 -> V_1440 ;
}
F_434 ( V_5 , V_1961 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_1961 ;
}
static void F_594 ( struct V_365 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_145 ( V_111 ) )
return;
F_241 ( V_5 , 0 ) ;
F_438 ( V_111 ) ;
F_242 ( V_5 ) ;
}
static inline void F_595 ( struct V_365 * V_111 , struct V_4 * V_5 ,
int V_2235 )
{
V_111 -> V_1202 = V_2235 ;
if ( V_2235 > V_1329 ) {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_596 ( V_111 ) ;
F_86 ( V_5 , V_1596 ) ;
} else {
F_84 ( V_5 , V_1341 ) ;
}
} else {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_84 ( V_5 , V_1596 ) ;
F_596 ( V_111 ) ;
}
F_86 ( V_5 , V_1341 ) ;
}
}
static int F_597 ( struct V_365 * V_111 , int V_2235 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 ;
bool V_1534 = false ;
if ( V_2235 < V_2236 || V_2235 > F_466 ( V_5 ) )
return - V_64 ;
if ( ! F_145 ( V_111 ) ) {
F_595 ( V_111 , V_5 , V_2235 ) ;
return 0 ;
}
F_123 ( V_5 ) ;
F_341 ( V_5 ) ;
F_595 ( V_111 , V_5 , V_2235 ) ;
F_241 ( V_5 , 1 ) ;
F_433 ( V_5 , V_110 , 1 ) ;
if ( F_30 ( V_5 ) == V_668 )
V_1534 = true ;
V_75 = F_486 ( V_5 , V_1534 ) ;
if ( ! V_75 )
F_343 ( V_5 ) ;
F_242 ( V_5 ) ;
if ( ! V_75 )
F_120 ( V_5 ) ;
return V_75 ;
}
static void F_598 ( struct V_4 * V_5 )
{
T_1 V_2237 , V_7 , V_1984 ;
V_5 -> V_1978 = V_2238 ;
if ( F_168 ( V_5 , 0 , & V_1984 ) != 0 )
return;
if ( ( V_1984 != V_1985 ) &&
( ( V_1984 & V_2086 ) != V_2087 ) &&
( ( V_1984 & V_2103 ) != V_2104 ) )
return;
V_2237 = 0x10 ;
while ( V_2237 < V_5 -> V_1978 ) {
if ( F_168 ( V_5 , V_2237 , & V_7 ) != 0 )
return;
if ( V_7 == V_1984 )
break;
V_2237 <<= 1 ;
}
V_5 -> V_1978 = V_2237 ;
}
static void F_599 ( struct V_4 * V_5 )
{
T_1 V_7 ;
if ( F_23 ( V_5 , V_682 ) || F_168 ( V_5 , 0 , & V_7 ) != 0 )
return;
if ( V_7 != V_1985 ) {
F_598 ( V_5 ) ;
return;
}
if ( F_168 ( V_5 , 0xf0 , & V_7 ) == 0 ) {
if ( V_7 != 0 ) {
V_5 -> V_1978 = F_600 ( ( T_3 ) ( V_7 & 0x0000ffff ) ) * 1024 ;
return;
}
}
V_5 -> V_1978 = V_2239 ;
}
static void F_601 ( struct V_4 * V_5 )
{
T_1 V_2240 ;
V_2240 = F_33 ( V_2241 ) ;
if ( V_2240 & V_2242 ) {
F_84 ( V_5 , V_612 ) ;
} else {
V_2240 &= ~ V_2243 ;
F_46 ( V_2241 , V_2240 ) ;
}
if ( F_30 ( V_5 ) == V_1501 ||
F_23 ( V_5 , 5780_CLASS ) ) {
switch ( V_2240 & V_2244 ) {
case V_2245 :
V_5 -> V_614 = V_615 ;
V_5 -> V_616 = V_2246 ;
F_84 ( V_5 , V_611 ) ;
break;
case V_2247 :
V_5 -> V_614 = V_615 ;
V_5 -> V_616 = V_2248 ;
break;
case V_2249 :
V_5 -> V_614 = V_615 ;
V_5 -> V_616 = V_2250 ;
F_84 ( V_5 , V_611 ) ;
break;
case V_2251 :
V_5 -> V_614 = V_642 ;
V_5 -> V_616 = V_2252 ;
F_84 ( V_5 , V_611 ) ;
break;
case V_2253 :
V_5 -> V_614 = V_2254 ;
V_5 -> V_616 = V_2255 ;
break;
case V_2256 :
case V_2257 :
V_5 -> V_614 = V_2258 ;
V_5 -> V_616 = V_2259 ;
break;
}
} else {
V_5 -> V_614 = V_615 ;
V_5 -> V_616 = V_2246 ;
F_84 ( V_5 , V_611 ) ;
}
}
static void F_602 ( struct V_4 * V_5 , T_1 V_2260 )
{
switch ( V_2260 & V_2261 ) {
case V_2262 :
V_5 -> V_616 = 256 ;
break;
case V_2263 :
V_5 -> V_616 = 512 ;
break;
case V_2264 :
V_5 -> V_616 = 1024 ;
break;
case V_2265 :
V_5 -> V_616 = 2048 ;
break;
case V_2266 :
V_5 -> V_616 = 4096 ;
break;
case V_2267 :
V_5 -> V_616 = 264 ;
break;
case V_2268 :
V_5 -> V_616 = 528 ;
break;
}
}
static void F_603 ( struct V_4 * V_5 )
{
T_1 V_2240 ;
V_2240 = F_33 ( V_2241 ) ;
if ( V_2240 & ( 1 << 27 ) )
F_84 ( V_5 , V_592 ) ;
switch ( V_2240 & V_2269 ) {
case V_2270 :
case V_2271 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
break;
case V_2272 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
break;
case V_2273 :
case V_2274 :
case V_2275 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
break;
}
if ( F_23 ( V_5 , V_612 ) ) {
F_602 ( V_5 , V_2240 ) ;
} else {
V_5 -> V_616 = V_2250 ;
V_2240 &= ~ V_2243 ;
F_46 ( V_2241 , V_2240 ) ;
}
}
static void F_604 ( struct V_4 * V_5 )
{
T_1 V_2240 , V_2276 = 0 ;
V_2240 = F_33 ( V_2241 ) ;
if ( V_2240 & ( 1 << 27 ) ) {
F_84 ( V_5 , V_592 ) ;
V_2276 = 1 ;
}
V_2240 &= V_2269 ;
switch ( V_2240 ) {
case V_2277 :
case V_2278 :
case V_2279 :
case V_2280 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 264 ;
if ( V_2240 == V_2277 ||
V_2240 == V_2280 )
V_5 -> V_1978 = ( V_2276 ? 0x3e200 :
V_2239 ) ;
else if ( V_2240 == V_2278 )
V_5 -> V_1978 = ( V_2276 ? 0x1f200 :
V_2281 ) ;
else
V_5 -> V_1978 = ( V_2276 ? 0x1f200 :
V_2282 ) ;
break;
case V_2273 :
case V_2274 :
case V_2275 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 256 ;
if ( V_2240 == V_2273 )
V_5 -> V_1978 = ( V_2276 ?
V_2283 :
V_2282 ) ;
else if ( V_2240 == V_2274 )
V_5 -> V_1978 = ( V_2276 ?
V_2283 :
V_2281 ) ;
else
V_5 -> V_1978 = ( V_2276 ?
V_2282 :
V_2239 ) ;
break;
}
}
static void F_605 ( struct V_4 * V_5 )
{
T_1 V_2240 ;
V_2240 = F_33 ( V_2241 ) ;
switch ( V_2240 & V_2269 ) {
case V_2284 :
case V_2285 :
case V_2286 :
case V_2287 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_5 -> V_616 = V_2250 ;
V_2240 &= ~ V_2243 ;
F_46 ( V_2241 , V_2240 ) ;
break;
case V_2272 :
case V_2277 :
case V_2278 :
case V_2279 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 264 ;
break;
case V_2273 :
case V_2274 :
case V_2275 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 256 ;
break;
}
}
static void F_606 ( struct V_4 * V_5 )
{
T_1 V_2240 , V_2276 = 0 ;
V_2240 = F_33 ( V_2241 ) ;
if ( V_2240 & ( 1 << 27 ) ) {
F_84 ( V_5 , V_592 ) ;
V_2276 = 1 ;
}
V_2240 &= V_2269 ;
switch ( V_2240 ) {
case V_2288 :
case V_2289 :
case V_2290 :
case V_2291 :
case V_2292 :
case V_2293 :
case V_2294 :
case V_2295 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
F_84 ( V_5 , V_613 ) ;
V_5 -> V_616 = 256 ;
break;
case V_2296 :
case V_2297 :
case V_2298 :
case V_2299 :
case V_2300 :
case V_2301 :
case V_2302 :
case V_2303 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
V_5 -> V_616 = 256 ;
break;
}
if ( V_2276 ) {
V_5 -> V_1978 = F_33 ( V_2304 ) ;
} else {
switch ( V_2240 ) {
case V_2291 :
case V_2295 :
case V_2299 :
case V_2303 :
V_5 -> V_1978 = V_2305 ;
break;
case V_2290 :
case V_2294 :
case V_2298 :
case V_2302 :
V_5 -> V_1978 = V_2306 ;
break;
case V_2289 :
case V_2293 :
case V_2297 :
case V_2301 :
V_5 -> V_1978 = V_2239 ;
break;
case V_2288 :
case V_2292 :
case V_2296 :
case V_2300 :
V_5 -> V_1978 = V_2281 ;
break;
}
}
}
static void F_607 ( struct V_4 * V_5 )
{
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_5 -> V_616 = V_2250 ;
}
static void F_608 ( struct V_4 * V_5 )
{
T_1 V_2240 ;
V_2240 = F_33 ( V_2241 ) ;
switch ( V_2240 & V_2269 ) {
case V_2285 :
case V_2287 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_5 -> V_616 = V_2250 ;
V_2240 &= ~ V_2243 ;
F_46 ( V_2241 , V_2240 ) ;
return;
case V_2272 :
case V_2307 :
case V_2308 :
case V_2309 :
case V_2310 :
case V_2311 :
case V_2312 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2240 & V_2269 ) {
case V_2272 :
case V_2307 :
case V_2308 :
V_5 -> V_1978 = V_2282 ;
break;
case V_2309 :
case V_2310 :
V_5 -> V_1978 = V_2281 ;
break;
case V_2311 :
case V_2312 :
V_5 -> V_1978 = V_2239 ;
break;
}
break;
case V_2273 :
case V_2274 :
case V_2275 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2240 & V_2269 ) {
case V_2273 :
V_5 -> V_1978 = V_2282 ;
break;
case V_2274 :
V_5 -> V_1978 = V_2281 ;
break;
case V_2275 :
V_5 -> V_1978 = V_2239 ;
break;
}
break;
default:
F_84 ( V_5 , V_682 ) ;
return;
}
F_602 ( V_5 , V_2240 ) ;
if ( V_5 -> V_616 != 264 && V_5 -> V_616 != 528 )
F_84 ( V_5 , V_613 ) ;
}
static void F_609 ( struct V_4 * V_5 )
{
T_1 V_2240 ;
V_2240 = F_33 ( V_2241 ) ;
switch ( V_2240 & V_2269 ) {
case V_2313 :
case V_2314 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_5 -> V_616 = V_2250 ;
V_2240 &= ~ V_2243 ;
F_46 ( V_2241 , V_2240 ) ;
return;
case V_2315 :
case V_2316 :
case V_2317 :
case V_2318 :
case V_2319 :
case V_2320 :
case V_2321 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2240 & V_2269 ) {
case V_2318 :
break;
case V_2319 :
case V_2320 :
V_5 -> V_1978 = V_2281 ;
break;
default:
V_5 -> V_1978 = V_2282 ;
break;
}
break;
case V_2322 :
case V_2323 :
case V_2324 :
case V_2325 :
case V_2326 :
case V_2327 :
case V_2328 :
case V_2329 :
case V_2330 :
case V_2331 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2240 & V_2269 ) {
case V_2326 :
case V_2328 :
break;
case V_2327 :
case V_2329 :
V_5 -> V_1978 = V_2281 ;
break;
default:
V_5 -> V_1978 = V_2282 ;
break;
}
break;
default:
F_84 ( V_5 , V_682 ) ;
return;
}
F_602 ( V_5 , V_2240 ) ;
if ( V_5 -> V_616 != 264 && V_5 -> V_616 != 528 )
F_84 ( V_5 , V_613 ) ;
}
static void F_610 ( struct V_4 * V_5 )
{
T_1 V_2240 , V_2332 ;
V_2240 = F_33 ( V_2241 ) ;
V_2332 = V_2240 & V_2269 ;
if ( F_30 ( V_5 ) == V_768 ) {
if ( ! ( V_2240 & V_2333 ) ) {
F_84 ( V_5 , V_682 ) ;
return;
}
switch ( V_2332 ) {
case V_2334 :
V_2332 = V_2335 ;
break;
case V_2336 :
V_2332 = V_2337 ;
break;
case V_2338 :
V_2332 = V_2339 ;
break;
}
}
switch ( V_2332 ) {
case V_2335 :
case V_2337 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
V_2240 &= ~ V_2243 ;
F_46 ( V_2241 , V_2240 ) ;
if ( V_2332 == V_2335 )
V_5 -> V_616 = V_2250 ;
else
V_5 -> V_616 = V_2340 ;
return;
case V_2341 :
case V_2342 :
case V_2343 :
case V_2344 :
case V_2345 :
case V_2346 :
case V_2347 :
case V_2348 :
case V_2349 :
case V_2350 :
case V_2351 :
case V_2352 :
V_5 -> V_614 = V_615 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2332 ) {
case V_2344 :
case V_2345 :
case V_2346 :
V_5 -> V_1978 = V_2281 ;
break;
case V_2347 :
case V_2348 :
case V_2349 :
V_5 -> V_1978 = V_2239 ;
break;
case V_2350 :
case V_2351 :
V_5 -> V_1978 = V_2306 ;
break;
default:
if ( F_30 ( V_5 ) != V_768 )
V_5 -> V_1978 = V_2282 ;
break;
}
break;
case V_2353 :
case V_2354 :
case V_2355 :
case V_2356 :
case V_2357 :
case V_2338 :
case V_2358 :
case V_2359 :
case V_2360 :
case V_2361 :
case V_2362 :
case V_2363 :
case V_2364 :
case V_2365 :
case V_2366 :
case V_2367 :
case V_2368 :
case V_2339 :
V_5 -> V_614 = V_642 ;
F_84 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_612 ) ;
switch ( V_2332 ) {
case V_2357 :
case V_2338 :
case V_2358 :
case V_2359 :
V_5 -> V_1978 = V_2281 ;
break;
case V_2360 :
case V_2361 :
case V_2362 :
case V_2363 :
V_5 -> V_1978 = V_2239 ;
break;
case V_2364 :
case V_2365 :
case V_2366 :
case V_2367 :
V_5 -> V_1978 = V_2306 ;
break;
default:
if ( F_30 ( V_5 ) != V_768 )
V_5 -> V_1978 = V_2282 ;
break;
}
break;
default:
F_84 ( V_5 , V_682 ) ;
return;
}
F_602 ( V_5 , V_2240 ) ;
if ( V_5 -> V_616 != 264 && V_5 -> V_616 != 528 )
F_84 ( V_5 , V_613 ) ;
if ( F_30 ( V_5 ) == V_768 ) {
T_1 V_7 ;
if ( F_168 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 != V_1985 &&
( V_7 & V_2086 ) != V_2087 )
F_84 ( V_5 , V_682 ) ;
}
}
static void F_611 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_264 ) ) {
F_86 ( V_5 , V_586 ) ;
F_86 ( V_5 , V_611 ) ;
F_84 ( V_5 , V_682 ) ;
return;
}
F_31 ( V_599 ,
( V_2369 |
( V_2370 <<
V_2371 ) ) ) ;
F_163 ( 1 ) ;
F_31 ( V_136 ,
F_33 ( V_136 ) | V_2372 ) ;
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
V_5 -> V_1978 = 0 ;
if ( F_30 ( V_5 ) == V_641 )
F_603 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1490 )
F_604 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1503 ||
F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_257 )
F_605 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_45 )
F_606 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_36 )
F_607 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1407 ||
F_23 ( V_5 , 57765_CLASS ) )
F_608 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 )
F_609 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_768 )
F_610 ( V_5 ) ;
else
F_601 ( V_5 ) ;
if ( V_5 -> V_1978 == 0 )
F_599 ( V_5 ) ;
F_161 ( V_5 ) ;
F_159 ( V_5 ) ;
} else {
F_86 ( V_5 , V_586 ) ;
F_86 ( V_5 , V_611 ) ;
F_598 ( V_5 ) ;
}
}
static struct V_2373 * F_612 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_575 ( V_2374 ) ; V_42 ++ ) {
if ( ( V_2374 [ V_42 ] . V_2375 ==
V_5 -> V_12 -> V_2376 ) &&
( V_2374 [ V_42 ] . V_2377 ==
V_5 -> V_12 -> V_2378 ) )
return & V_2374 [ V_42 ] ;
}
return NULL ;
}
static void F_613 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_5 -> V_216 = V_2379 ;
V_5 -> V_564 = V_822 ;
F_84 ( V_5 , V_644 ) ;
F_84 ( V_5 , V_718 ) ;
if ( F_30 ( V_5 ) == V_36 ) {
if ( ! ( F_33 ( V_1913 ) & V_2380 ) ) {
F_86 ( V_5 , V_644 ) ;
F_84 ( V_5 , V_533 ) ;
}
V_7 = F_33 ( V_2381 ) ;
if ( V_7 & V_2382 )
F_84 ( V_5 , V_975 ) ;
if ( ( V_7 & V_2383 ) &&
( V_7 & V_2384 ) ) {
F_84 ( V_5 , V_112 ) ;
F_538 ( & V_5 -> V_12 -> V_111 , true ) ;
}
goto V_186;
}
F_32 ( V_5 , V_1432 , & V_7 ) ;
if ( V_7 == V_1433 ) {
T_1 V_1434 , V_2385 ;
T_1 V_2386 = 0 , V_2387 = 0 , V_2388 = 0 ;
T_1 V_2389 , V_2390 , V_2391 ;
int V_2392 = 0 ;
F_32 ( V_5 , V_1435 , & V_1434 ) ;
V_5 -> V_551 = V_1434 ;
F_32 ( V_5 , V_2393 , & V_2390 ) ;
V_2390 >>= V_2394 ;
if ( F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_538 &&
F_30 ( V_5 ) != V_500 &&
( V_2390 > 0 ) && ( V_2390 < 0x100 ) )
F_32 ( V_5 , V_2395 , & V_2386 ) ;
if ( F_30 ( V_5 ) == V_257 )
F_32 ( V_5 , V_2396 , & V_2387 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 )
F_32 ( V_5 , V_2397 , & V_2388 ) ;
if ( ( V_1434 & V_2398 ) ==
V_2399 )
V_2392 = 1 ;
F_32 ( V_5 , V_2400 , & V_2389 ) ;
if ( V_2389 != 0 ) {
T_1 V_2401 = V_2389 & V_2402 ;
T_1 V_2403 = V_2389 & V_2404 ;
V_2391 = ( V_2401 >> 16 ) << 10 ;
V_2391 |= ( V_2403 & 0xfc00 ) << 16 ;
V_2391 |= ( V_2403 & 0x03ff ) << 0 ;
} else
V_2391 = 0 ;
V_5 -> V_216 = V_2391 ;
if ( V_2392 ) {
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_178 |= V_568 ;
else
V_5 -> V_178 |= V_306 ;
}
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2385 = V_2386 & ( V_2405 |
V_2406 ) ;
else
V_2385 = V_1434 & V_2405 ;
switch ( V_2385 ) {
default:
case V_2407 :
V_5 -> V_564 = V_822 ;
break;
case V_2408 :
V_5 -> V_564 = V_565 ;
break;
case V_2409 :
V_5 -> V_564 = V_2410 ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 )
V_5 -> V_564 = V_822 ;
break;
case V_2411 :
V_5 -> V_564 = V_2412 ;
if ( F_77 ( V_5 ) != V_1415 &&
F_77 ( V_5 ) != V_2413 )
V_5 -> V_564 |= ( V_822 |
V_565 ) ;
if ( F_23 ( V_5 , 5717_PLUS ) ||
F_30 ( V_5 ) == V_768 )
V_5 -> V_564 |= V_2414 |
V_2415 ;
break;
case V_2416 :
V_5 -> V_564 = V_2417 ;
break;
case V_2418 :
V_5 -> V_564 = V_2419 ;
if ( F_77 ( V_5 ) != V_1415 )
V_5 -> V_564 |= ( V_822 |
V_565 ) ;
break;
}
if ( ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) &&
V_5 -> V_12 -> V_2376 == V_2420 )
V_5 -> V_564 = V_565 ;
if ( F_146 ( V_5 ) == V_504 )
V_5 -> V_564 = V_822 ;
if ( V_1434 & V_2421 ) {
F_84 ( V_5 , V_644 ) ;
if ( ( V_5 -> V_12 -> V_2376 ==
V_2422 ) &&
( V_5 -> V_12 -> V_2378 == 0x205a ||
V_5 -> V_12 -> V_2378 == 0x2063 ) )
F_86 ( V_5 , V_644 ) ;
} else {
F_86 ( V_5 , V_644 ) ;
F_84 ( V_5 , V_533 ) ;
}
if ( V_1434 & V_1436 ) {
F_84 ( V_5 , V_309 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , V_317 ) ;
}
if ( ( V_1434 & V_2423 ) &&
F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , V_60 ) ;
if ( V_5 -> V_178 & V_360 &&
! ( V_1434 & V_2424 ) )
F_86 ( V_5 , V_718 ) ;
if ( F_23 ( V_5 , V_718 ) &&
( V_1434 & V_2425 ) ) {
F_84 ( V_5 , V_112 ) ;
F_538 ( & V_5 -> V_12 -> V_111 , true ) ;
}
if ( V_2386 & ( 1 << 17 ) )
V_5 -> V_178 |= V_825 ;
if ( V_2386 & ( 1 << 18 ) )
V_5 -> V_178 |= V_1741 ;
if ( ( F_23 ( V_5 , 57765_PLUS ) ||
( F_30 ( V_5 ) == V_414 &&
F_146 ( V_5 ) != V_504 ) ) &&
( V_2386 & V_2426 ) )
V_5 -> V_178 |= V_514 ;
if ( F_23 ( V_5 , V_1083 ) ) {
T_1 V_2427 ;
F_32 ( V_5 , V_1437 , & V_2427 ) ;
if ( F_30 ( V_5 ) != V_257 &&
! F_23 ( V_5 , 57765_PLUS ) &&
( V_2427 & V_2428 ) )
F_84 ( V_5 , V_975 ) ;
if ( V_2427 & V_1439 )
V_5 -> V_178 |= V_570 ;
if ( V_2427 & V_1438 )
V_5 -> V_178 |= V_772 ;
}
if ( V_2387 & V_2429 )
F_84 ( V_5 , V_236 ) ;
if ( V_2387 & V_2430 )
F_84 ( V_5 , V_245 ) ;
if ( V_2387 & V_2431 )
F_84 ( V_5 , V_246 ) ;
if ( V_2388 & V_2432 )
V_5 -> V_178 |= V_773 ;
}
V_186:
if ( F_23 ( V_5 , V_718 ) )
F_538 ( & V_5 -> V_12 -> V_111 ,
F_23 ( V_5 , V_112 ) ) ;
else
F_614 ( & V_5 -> V_12 -> V_111 , false ) ;
}
static int F_615 ( struct V_4 * V_5 , T_1 V_596 , T_1 * V_7 )
{
int V_42 , V_75 ;
T_1 V_2433 , V_6 = V_596 * 8 ;
V_75 = F_158 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_11 ( V_5 , V_2434 , V_6 | V_2435 ) ;
F_11 ( V_5 , V_2436 , V_2437 |
V_2438 | V_2439 ) ;
F_12 ( V_5 , V_2436 ) ;
F_24 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_2433 = F_12 ( V_5 , V_2440 ) ;
if ( V_2433 & V_2441 ) {
* V_7 = F_12 ( V_5 , V_2442 ) ;
break;
}
F_24 ( 10 ) ;
}
F_11 ( V_5 , V_2436 , 0 ) ;
F_159 ( V_5 ) ;
if ( V_2433 & V_2441 )
return 0 ;
return - V_67 ;
}
static int F_616 ( struct V_4 * V_5 , T_1 V_643 )
{
int V_42 ;
T_1 V_7 ;
F_46 ( V_2443 , V_643 | V_2444 ) ;
F_46 ( V_2443 , V_643 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_7 = F_33 ( V_2445 ) ;
if ( V_7 & V_2446 )
break;
F_24 ( 10 ) ;
}
return ( V_7 & V_2446 ) ? 0 : - V_67 ;
}
static T_1 F_617 ( struct V_4 * V_5 )
{
T_1 V_2447 , V_2448 ;
F_46 ( V_2449 , V_2450 ) ;
if ( F_616 ( V_5 , V_2451 ) )
return 0 ;
F_46 ( V_2452 , V_2453 ) ;
if ( F_616 ( V_5 , V_2454 ) )
return 0 ;
V_2448 = F_33 ( V_2455 ) ;
F_46 ( V_2452 , V_2456 ) ;
if ( F_616 ( V_5 , V_2454 ) )
return 0 ;
V_2447 = F_33 ( V_2455 ) ;
return ( ( V_2448 & 0x0000ffff ) << 16 ) | ( V_2447 >> 16 ) ;
}
static void F_618 ( struct V_4 * V_5 )
{
T_1 V_342 = V_706 ;
if ( ! ( V_5 -> V_178 & V_393 ) ) {
if ( ! ( V_5 -> V_178 & V_773 ) )
V_342 |= V_774 ;
V_342 |= V_764 ;
}
if ( ! ( V_5 -> V_178 & V_360 ) )
V_342 |= V_709 |
V_710 |
V_707 |
V_711 |
V_704 ;
else
V_342 |= V_781 ;
V_5 -> V_330 . V_399 = V_342 ;
V_5 -> V_330 . V_373 = V_754 ;
V_5 -> V_330 . V_377 = V_755 ;
V_5 -> V_330 . V_353 = V_358 ;
V_5 -> V_330 . V_331 = V_754 ;
V_5 -> V_330 . V_334 = V_755 ;
V_5 -> V_391 = - 1 ;
}
static int F_619 ( struct V_4 * V_5 )
{
T_1 V_2457 , V_2458 ;
T_1 V_2459 , V_2460 ;
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
V_5 -> V_178 &= ~ ( V_772 |
V_570 ) ;
if ( F_23 ( V_5 , V_267 ) )
return F_113 ( V_5 ) ;
V_75 = 0 ;
if ( F_23 ( V_5 , V_309 ) || F_23 ( V_5 , V_60 ) ) {
V_2459 = V_2460 = V_2379 ;
} else {
V_75 |= F_57 ( V_5 , V_2461 , & V_2457 ) ;
V_75 |= F_57 ( V_5 , V_2462 , & V_2458 ) ;
V_2459 = ( V_2457 & 0xffff ) << 10 ;
V_2459 |= ( V_2458 & 0xfc00 ) << 16 ;
V_2459 |= ( V_2458 & 0x03ff ) << 0 ;
V_2460 = V_2459 & V_401 ;
}
if ( ! V_75 && F_620 ( V_2460 ) ) {
V_5 -> V_216 = V_2459 ;
if ( V_2460 == V_942 )
V_5 -> V_178 |= V_568 ;
else
V_5 -> V_178 &= ~ V_568 ;
} else {
if ( V_5 -> V_216 != V_2379 ) {
} else {
struct V_2373 * V_1442 ;
V_1442 = F_612 ( V_5 ) ;
if ( V_1442 ) {
V_5 -> V_216 = V_1442 -> V_216 ;
} else if ( ! F_23 ( V_5 , V_264 ) ) {
return - V_82 ;
}
if ( ! V_5 -> V_216 ||
V_5 -> V_216 == V_942 )
V_5 -> V_178 |= V_568 ;
}
}
if ( ! ( V_5 -> V_178 & V_360 ) &&
( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_668 ||
F_30 ( V_5 ) == V_768 ||
( F_30 ( V_5 ) == V_477 &&
F_77 ( V_5 ) != V_259 ) ||
( F_30 ( V_5 ) == V_766 &&
F_77 ( V_5 ) != V_328 ) ) ) {
V_5 -> V_178 |= V_339 ;
V_5 -> V_453 . V_394 = V_1993 |
V_1991 ;
V_5 -> V_453 . V_464 = V_710 |
V_764 ;
V_5 -> V_453 . V_463 = 1 ;
V_5 -> V_453 . V_466 = 1 ;
V_5 -> V_453 . V_468 = V_2463 ;
}
F_618 ( V_5 ) ;
if ( ! ( V_5 -> V_178 & V_570 ) &&
! ( V_5 -> V_178 & V_360 ) &&
! F_23 ( V_5 , V_60 ) &&
! F_23 ( V_5 , V_309 ) ) {
T_1 V_813 , V_2464 ;
F_57 ( V_5 , V_303 , & V_813 ) ;
if ( ! F_57 ( V_5 , V_303 , & V_813 ) &&
( V_813 & V_779 ) )
goto V_2465;
V_75 = F_144 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_130 ( V_5 ) ;
if ( ! F_215 ( V_5 , & V_2464 ) ) {
F_205 ( V_5 , V_5 -> V_330 . V_399 ,
V_5 -> V_330 . V_343 ) ;
F_59 ( V_5 , V_204 ,
V_577 | V_578 ) ;
}
}
V_2465:
if ( ( V_5 -> V_216 & V_401 ) == V_402 ) {
V_75 = F_213 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_213 ( V_5 ) ;
}
return V_75 ;
}
static void F_621 ( struct V_4 * V_5 )
{
T_4 * V_2466 ;
unsigned int V_2467 , V_2468 , V_74 ;
T_1 V_2070 ;
int V_628 , V_42 = 0 ;
V_2466 = ( T_4 * ) F_558 ( V_5 , & V_2070 ) ;
if ( ! V_2466 )
goto V_2469;
V_42 = F_563 ( V_2466 , 0 , V_2070 , V_2114 ) ;
if ( V_42 < 0 )
goto V_2470;
V_2468 = F_564 ( & V_2466 [ V_42 ] ) ;
V_2467 = V_42 + V_2115 + V_2468 ;
V_42 += V_2115 ;
if ( V_2467 > V_2070 )
goto V_2470;
V_628 = F_565 ( V_2466 , V_42 , V_2468 ,
V_2471 ) ;
if ( V_628 > 0 ) {
V_74 = F_622 ( & V_2466 [ V_628 ] ) ;
V_628 += V_2117 ;
if ( V_628 + V_74 > V_2467 || V_74 != 4 ||
memcmp ( & V_2466 [ V_628 ] , L_79 , 4 ) )
goto V_2472;
V_628 = F_565 ( V_2466 , V_42 , V_2468 ,
V_2473 ) ;
if ( V_628 < 0 )
goto V_2472;
V_74 = F_622 ( & V_2466 [ V_628 ] ) ;
V_628 += V_2117 ;
if ( V_628 + V_74 > V_2467 )
goto V_2472;
if ( V_74 >= sizeof( V_5 -> V_2018 ) )
V_74 = sizeof( V_5 -> V_2018 ) - 1 ;
memset ( V_5 -> V_2018 , 0 , sizeof( V_5 -> V_2018 ) ) ;
snprintf ( V_5 -> V_2018 , sizeof( V_5 -> V_2018 ) , L_80 , V_74 ,
& V_2466 [ V_628 ] ) ;
}
V_2472:
V_42 = F_565 ( V_2466 , V_42 , V_2468 ,
V_2474 ) ;
if ( V_42 < 0 )
goto V_2470;
V_74 = F_622 ( & V_2466 [ V_42 ] ) ;
V_42 += V_2117 ;
if ( V_74 > V_2475 ||
( V_74 + V_42 ) > V_2070 )
goto V_2470;
memcpy ( V_5 -> V_2476 , & V_2466 [ V_42 ] , V_74 ) ;
V_2470:
F_175 ( V_2466 ) ;
if ( V_5 -> V_2476 [ 0 ] )
return;
V_2469:
if ( F_30 ( V_5 ) == V_477 ) {
if ( V_5 -> V_12 -> V_544 == V_2477 ||
V_5 -> V_12 -> V_544 == V_2478 )
strcpy ( V_5 -> V_2476 , L_81 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2479 )
strcpy ( V_5 -> V_2476 , L_82 ) ;
else
goto V_2480;
} else if ( F_30 ( V_5 ) == V_1407 ) {
if ( V_5 -> V_12 -> V_544 == V_2481 )
strcpy ( V_5 -> V_2476 , L_83 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2482 )
strcpy ( V_5 -> V_2476 , L_84 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2483 )
strcpy ( V_5 -> V_2476 , L_85 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2484 )
strcpy ( V_5 -> V_2476 , L_86 ) ;
else
goto V_2480;
} else if ( F_30 ( V_5 ) == V_766 ) {
if ( V_5 -> V_12 -> V_544 == V_2485 )
strcpy ( V_5 -> V_2476 , L_87 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2486 )
strcpy ( V_5 -> V_2476 , L_88 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2487 )
strcpy ( V_5 -> V_2476 , L_89 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2488 )
strcpy ( V_5 -> V_2476 , L_90 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2489 )
strcpy ( V_5 -> V_2476 , L_91 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2490 )
strcpy ( V_5 -> V_2476 , L_92 ) ;
else
goto V_2480;
} else if ( F_30 ( V_5 ) == V_668 ) {
if ( V_5 -> V_12 -> V_544 == V_2491 )
strcpy ( V_5 -> V_2476 , L_93 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2492 )
strcpy ( V_5 -> V_2476 , L_94 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2493 )
strcpy ( V_5 -> V_2476 , L_95 ) ;
else if ( V_5 -> V_12 -> V_544 == V_2494 )
strcpy ( V_5 -> V_2476 , L_96 ) ;
else
goto V_2480;
} else if ( F_30 ( V_5 ) == V_36 ) {
strcpy ( V_5 -> V_2476 , L_97 ) ;
} else {
V_2480:
strcpy ( V_5 -> V_2476 , L_98 ) ;
}
}
static int F_623 ( struct V_4 * V_5 , T_1 V_596 )
{
T_1 V_7 ;
if ( F_168 ( V_5 , V_596 , & V_7 ) ||
( V_7 & 0xfc000000 ) != 0x0c000000 ||
F_168 ( V_5 , V_596 + 4 , & V_7 ) ||
V_7 != 0 )
return 0 ;
return 1 ;
}
static void F_624 ( struct V_4 * V_5 )
{
T_1 V_7 , V_596 , V_1032 , V_2495 ;
int V_42 , V_2496 ;
bool V_2497 = false ;
if ( F_168 ( V_5 , 0xc , & V_596 ) ||
F_168 ( V_5 , 0x4 , & V_1032 ) )
return;
V_596 = F_167 ( V_5 , V_596 ) ;
if ( F_168 ( V_5 , V_596 , & V_7 ) )
return;
if ( ( V_7 & 0xfc000000 ) == 0x0c000000 ) {
if ( F_168 ( V_5 , V_596 + 4 , & V_7 ) )
return;
if ( V_7 == 0 )
V_2497 = true ;
}
V_2496 = strlen ( V_5 -> V_2018 ) ;
if ( V_2497 ) {
if ( V_2498 - V_2496 < 16 ||
F_168 ( V_5 , V_596 + 8 , & V_2495 ) )
return;
V_596 = V_596 + V_2495 - V_1032 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 += 4 ) {
T_5 V_625 ;
if ( F_169 ( V_5 , V_596 + V_42 , & V_625 ) )
return;
memcpy ( V_5 -> V_2018 + V_2496 + V_42 , & V_625 , sizeof( V_625 ) ) ;
}
} else {
T_1 V_2499 , V_2500 ;
if ( F_168 ( V_5 , V_2501 , & V_2495 ) )
return;
V_2499 = ( V_2495 & V_2502 ) >>
V_2503 ;
V_2500 = V_2495 & V_2504 ;
snprintf ( & V_5 -> V_2018 [ V_2496 ] , V_2498 - V_2496 ,
L_99 , V_2499 , V_2500 ) ;
}
}
static void F_625 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2499 , V_2500 ;
if ( F_168 ( V_5 , V_2505 , & V_7 ) )
return;
V_2499 = ( V_7 & V_2506 ) >>
V_2507 ;
V_2500 = ( V_7 & V_2508 ) >>
V_2509 ;
snprintf ( & V_5 -> V_2018 [ 0 ] , 32 , L_100 , V_2499 , V_2500 ) ;
}
static void F_626 ( struct V_4 * V_5 , T_1 V_7 )
{
T_1 V_596 , V_2499 , V_2500 , V_2510 ;
strncat ( V_5 -> V_2018 , L_101 , V_2498 - strlen ( V_5 -> V_2018 ) - 1 ) ;
if ( ( V_7 & V_2088 ) != V_2089 )
return;
switch ( V_7 & V_2090 ) {
case V_2091 :
V_596 = V_2511 ;
break;
case V_2093 :
V_596 = V_2512 ;
break;
case V_2095 :
V_596 = V_2513 ;
break;
case V_2097 :
V_596 = V_2514 ;
break;
case V_2099 :
V_596 = V_2515 ;
break;
case V_2101 :
V_596 = V_2516 ;
break;
default:
return;
}
if ( F_168 ( V_5 , V_596 , & V_7 ) )
return;
V_2510 = ( V_7 & V_2517 ) >>
V_2518 ;
V_2499 = ( V_7 & V_2519 ) >>
V_2520 ;
V_2500 = V_7 & V_2521 ;
if ( V_2500 > 99 || V_2510 > 26 )
return;
V_596 = strlen ( V_5 -> V_2018 ) ;
snprintf ( & V_5 -> V_2018 [ V_596 ] , V_2498 - V_596 ,
L_102 , V_2499 , V_2500 ) ;
if ( V_2510 > 0 ) {
V_596 = strlen ( V_5 -> V_2018 ) ;
if ( V_596 < V_2498 - 1 )
V_5 -> V_2018 [ V_596 ] = 'a' + V_2510 - 1 ;
}
}
static void F_627 ( struct V_4 * V_5 )
{
T_1 V_7 , V_596 , V_1032 ;
int V_42 , V_2522 ;
for ( V_596 = V_2071 ;
V_596 < V_2072 ;
V_596 += V_2073 ) {
if ( F_168 ( V_5 , V_596 , & V_7 ) )
return;
if ( ( V_7 >> V_2074 ) == V_2523 )
break;
}
if ( V_596 == V_2072 )
return;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_1032 = 0x08000000 ;
else if ( F_168 ( V_5 , V_596 - 4 , & V_1032 ) )
return;
if ( F_168 ( V_5 , V_596 + 4 , & V_596 ) ||
! F_623 ( V_5 , V_596 ) ||
F_168 ( V_5 , V_596 + 8 , & V_7 ) )
return;
V_596 += V_7 - V_1032 ;
V_2522 = strlen ( V_5 -> V_2018 ) ;
V_5 -> V_2018 [ V_2522 ++ ] = ',' ;
V_5 -> V_2018 [ V_2522 ++ ] = ' ' ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
T_5 V_625 ;
if ( F_169 ( V_5 , V_596 , & V_625 ) )
return;
V_596 += sizeof( V_625 ) ;
if ( V_2522 > V_2498 - sizeof( V_625 ) ) {
memcpy ( & V_5 -> V_2018 [ V_2522 ] , & V_625 , V_2498 - V_2522 ) ;
break;
}
memcpy ( & V_5 -> V_2018 [ V_2522 ] , & V_625 , sizeof( V_625 ) ) ;
V_2522 += sizeof( V_625 ) ;
}
}
static void F_628 ( struct V_4 * V_5 )
{
T_1 V_69 ;
V_69 = F_12 ( V_5 , V_80 ) ;
if ( V_69 != V_81 )
return;
V_69 = F_12 ( V_5 , V_83 ) ;
if ( ! ( V_69 & V_84 ) )
return;
if ( F_12 ( V_5 , V_2524 ) & V_2525 )
F_84 ( V_5 , V_79 ) ;
}
static void F_629 ( struct V_4 * V_5 )
{
int V_2522 ;
T_1 V_69 ;
char * V_2526 ;
V_69 = F_12 ( V_5 , V_2527 ) ;
if ( F_23 ( V_5 , V_79 ) )
V_2526 = L_103 ;
else if ( V_5 -> V_12 -> V_544 == V_2528 )
V_2526 = L_104 ;
else
V_2526 = L_105 ;
V_2522 = strlen ( V_5 -> V_2018 ) ;
snprintf ( & V_5 -> V_2018 [ V_2522 ] , V_2498 - V_2522 , L_106 ,
V_2526 ,
( V_69 & V_2529 ) >> V_2530 ,
( V_69 & V_2531 ) >> V_2532 ,
( V_69 & V_2533 ) >> V_2534 ,
( V_69 & V_2535 ) ) ;
}
static void F_630 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2433 ;
if ( F_30 ( V_5 ) != V_768 )
return;
if ( ! F_615 ( V_5 , V_2536 , & V_7 ) &&
! F_615 ( V_5 , V_2536 + 4 , & V_2433 ) &&
F_631 ( V_7 ) ) {
T_6 V_2537 = ( T_6 ) V_7 << 32 | V_2433 ;
T_1 V_2390 = 0 ;
int V_42 , V_2522 ;
for ( V_42 = 0 ; V_42 < 7 ; V_42 ++ ) {
if ( ( V_2537 & 0xff ) == 0 )
break;
V_2390 = V_2537 & 0xff ;
V_2537 >>= 8 ;
}
V_2522 = strlen ( V_5 -> V_2018 ) ;
snprintf ( & V_5 -> V_2018 [ V_2522 ] , V_2498 - V_2522 , L_107 , V_2390 ) ;
}
}
static void F_632 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_2538 = false ;
if ( V_5 -> V_2018 [ 0 ] != 0 )
V_2538 = true ;
if ( F_23 ( V_5 , V_682 ) ) {
strcat ( V_5 -> V_2018 , L_101 ) ;
F_630 ( V_5 ) ;
return;
}
if ( F_168 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 == V_1985 )
F_624 ( V_5 ) ;
else if ( ( V_7 & V_2086 ) == V_2087 )
F_626 ( V_5 , V_7 ) ;
else if ( ( V_7 & V_2103 ) == V_2104 )
F_625 ( V_5 ) ;
if ( F_23 ( V_5 , V_309 ) ) {
if ( F_23 ( V_5 , V_60 ) ) {
F_628 ( V_5 ) ;
if ( ! V_2538 )
F_629 ( V_5 ) ;
} else if ( ! V_2538 ) {
F_627 ( V_5 ) ;
}
}
V_5 -> V_2018 [ V_2498 - 1 ] = 0 ;
}
static inline T_1 F_633 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1715 ) )
return V_2539 ;
else if ( F_23 ( V_5 , V_522 ) && ! F_23 ( V_5 , 5780_CLASS ) )
return V_2540 ;
else
return V_2541 ;
}
static struct V_1795 * F_634 ( struct V_4 * V_5 )
{
struct V_1795 * V_2542 ;
unsigned int V_2543 , V_2544 = V_5 -> V_12 -> V_274 & ~ 7 ;
for ( V_2543 = 0 ; V_2543 < 8 ; V_2543 ++ ) {
V_2542 = F_635 ( V_5 -> V_12 -> V_272 , V_2544 | V_2543 ) ;
if ( V_2542 && V_2542 != V_5 -> V_12 )
break;
F_636 ( V_2542 ) ;
}
if ( ! V_2542 ) {
V_2542 = V_5 -> V_12 ;
return V_2542 ;
}
F_636 ( V_2542 ) ;
return V_2542 ;
}
static void F_637 ( struct V_4 * V_5 , T_1 V_2545 )
{
V_5 -> V_2546 = V_2545 >> V_2547 ;
if ( F_30 ( V_5 ) == V_2548 ) {
T_1 V_161 ;
F_84 ( V_5 , V_152 ) ;
if ( V_5 -> V_12 -> V_544 == V_2477 ||
V_5 -> V_12 -> V_544 == V_2478 ||
V_5 -> V_12 -> V_544 == V_2479 ||
V_5 -> V_12 -> V_544 == V_2549 ||
V_5 -> V_12 -> V_544 == V_2550 ||
V_5 -> V_12 -> V_544 == V_2551 ||
V_5 -> V_12 -> V_544 == V_2552 ||
V_5 -> V_12 -> V_544 == V_2553 ||
V_5 -> V_12 -> V_544 == V_2528 ||
V_5 -> V_12 -> V_544 == V_2554 ||
V_5 -> V_12 -> V_544 == V_2555 )
V_161 = V_2556 ;
else if ( V_5 -> V_12 -> V_544 == V_2487 ||
V_5 -> V_12 -> V_544 == V_2488 ||
V_5 -> V_12 -> V_544 == V_2485 ||
V_5 -> V_12 -> V_544 == V_2486 ||
V_5 -> V_12 -> V_544 == V_2489 ||
V_5 -> V_12 -> V_544 == V_2490 ||
V_5 -> V_12 -> V_544 == V_2491 ||
V_5 -> V_12 -> V_544 == V_2492 ||
V_5 -> V_12 -> V_544 == V_2493 ||
V_5 -> V_12 -> V_544 == V_2494 )
V_161 = V_2557 ;
else
V_161 = V_2558 ;
F_19 ( V_5 -> V_12 , V_161 , & V_5 -> V_2546 ) ;
}
if ( F_77 ( V_5 ) == V_2559 )
V_5 -> V_2546 = V_2560 ;
if ( F_77 ( V_5 ) == V_2561 )
V_5 -> V_2546 = V_1615 ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 )
F_84 ( V_5 , 5717_PLUS ) ;
if ( F_30 ( V_5 ) == V_766 ||
F_30 ( V_5 ) == V_668 )
F_84 ( V_5 , 57765_CLASS ) ;
if ( F_23 ( V_5 , 57765_CLASS ) || F_23 ( V_5 , 5717_PLUS ) ||
F_30 ( V_5 ) == V_768 )
F_84 ( V_5 , 57765_PLUS ) ;
if ( F_30 ( V_5 ) == V_1490 ||
F_30 ( V_5 ) == V_1503 ||
F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1407 ||
F_23 ( V_5 , 57765_PLUS ) )
F_84 ( V_5 , 5755_PLUS ) ;
if ( F_30 ( V_5 ) == V_567 ||
F_30 ( V_5 ) == V_549 )
F_84 ( V_5 , 5780_CLASS ) ;
if ( F_30 ( V_5 ) == V_1501 ||
F_30 ( V_5 ) == V_641 ||
F_30 ( V_5 ) == V_36 ||
F_23 ( V_5 , 5755_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) )
F_84 ( V_5 , 5750_PLUS ) ;
if ( F_30 ( V_5 ) == V_502 ||
F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , 5705_PLUS ) ;
}
static bool F_638 ( struct V_4 * V_5 ,
const struct V_2562 * V_2563 )
{
T_1 V_2564 = F_33 ( V_498 ) & V_2565 ;
if ( ( F_30 ( V_5 ) == V_500 &&
( V_2564 == 0x8000 || V_2564 == 0x4000 ) ) ||
( V_5 -> V_178 & V_179 ) )
return true ;
if ( V_2563 -> V_2566 & V_2567 ) {
if ( F_30 ( V_5 ) == V_502 ) {
if ( V_2563 -> V_2566 & V_2568 )
return true ;
} else {
return true ;
}
}
return false ;
}
static int F_639 ( struct V_4 * V_5 , const struct V_2562 * V_2563 )
{
T_1 V_2545 ;
T_1 V_2569 , V_2564 ;
T_1 V_7 ;
T_3 V_1381 ;
int V_75 ;
F_423 ( V_5 -> V_12 , V_1380 , & V_1381 ) ;
V_1381 &= ~ V_2570 ;
F_425 ( V_5 -> V_12 , V_1380 , V_1381 ) ;
F_19 ( V_5 -> V_12 , V_119 ,
& V_2545 ) ;
V_5 -> V_120 |= ( V_2545 &
V_2571 ) ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
F_637 ( V_5 , V_2545 ) ;
if ( ( F_77 ( V_5 ) == V_1742 ) ||
( F_77 ( V_5 ) == V_2572 ) ) {
static struct V_2573 {
T_1 V_2574 ;
T_1 V_544 ;
T_1 V_2575 ;
} V_2576 [] = {
{ V_2577 , V_2578 ,
V_2579 } ,
{ V_2577 , V_2580 ,
V_2579 } ,
{ V_2577 , V_2581 ,
0xa } ,
{ V_2577 , V_2582 ,
V_2579 } ,
{ } ,
} ;
struct V_2573 * V_2583 = & V_2576 [ 0 ] ;
struct V_1795 * V_2584 = NULL ;
while ( V_2583 -> V_2574 != 0 ) {
V_2584 = F_640 ( V_2583 -> V_2574 , V_2583 -> V_544 ,
V_2584 ) ;
if ( ! V_2584 ) {
V_2583 ++ ;
continue;
}
if ( V_2583 -> V_2575 != V_2579 ) {
if ( V_2584 -> V_2585 > V_2583 -> V_2575 )
continue;
}
if ( V_2584 -> V_2586 &&
( V_2584 -> V_2586 -> V_273 ==
V_5 -> V_12 -> V_272 -> V_273 ) ) {
F_84 ( V_5 , V_26 ) ;
F_636 ( V_2584 ) ;
break;
}
}
}
if ( F_30 ( V_5 ) == V_538 ) {
static struct V_2573 {
T_1 V_2574 ;
T_1 V_544 ;
} V_2587 [] = {
{ V_2577 , V_2588 } ,
{ V_2577 , V_2589 } ,
{ } ,
} ;
struct V_2573 * V_2583 = & V_2587 [ 0 ] ;
struct V_1795 * V_2584 = NULL ;
while ( V_2583 -> V_2574 != 0 ) {
V_2584 = F_640 ( V_2583 -> V_2574 ,
V_2583 -> V_544 ,
V_2584 ) ;
if ( ! V_2584 ) {
V_2583 ++ ;
continue;
}
if ( V_2584 -> V_2586 &&
( V_2584 -> V_2586 -> V_273 <=
V_5 -> V_12 -> V_272 -> V_273 ) &&
( V_2584 -> V_2586 -> V_2590 . V_1987 >=
V_5 -> V_12 -> V_272 -> V_273 ) ) {
F_84 ( V_5 , 5701_DMA_BUG ) ;
F_636 ( V_2584 ) ;
break;
}
}
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_84 ( V_5 , 40BIT_DMA_BUG ) ;
V_5 -> V_1398 = V_5 -> V_12 -> V_1398 ;
} else {
struct V_1795 * V_2584 = NULL ;
do {
V_2584 = F_640 ( V_2591 ,
V_2592 ,
V_2584 ) ;
if ( V_2584 && V_2584 -> V_2586 &&
( V_2584 -> V_2586 -> V_273 <=
V_5 -> V_12 -> V_272 -> V_273 ) &&
( V_2584 -> V_2586 -> V_2590 . V_1987 >=
V_5 -> V_12 -> V_272 -> V_273 ) ) {
F_84 ( V_5 , 40BIT_DMA_BUG ) ;
F_636 ( V_2584 ) ;
break;
}
} while ( V_2584 );
}
if ( F_30 ( V_5 ) == V_501 ||
F_30 ( V_5 ) == V_549 )
V_5 -> V_560 = F_634 ( V_5 ) ;
if ( F_77 ( V_5 ) == V_1614 )
;
else if ( F_23 ( V_5 , 57765_PLUS ) )
F_84 ( V_5 , V_1299 ) ;
else if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_84 ( V_5 , V_1298 ) ;
else if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_84 ( V_5 , V_1297 ) ;
F_84 ( V_5 , V_1294 ) ;
if ( F_30 ( V_5 ) == V_1501 &&
F_77 ( V_5 ) >= V_2593 )
F_86 ( V_5 , V_1294 ) ;
} else if ( F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_538 &&
F_77 ( V_5 ) != V_1430 ) {
F_84 ( V_5 , V_684 ) ;
F_84 ( V_5 , V_1294 ) ;
if ( F_30 ( V_5 ) == V_502 )
V_5 -> V_1895 = V_2594 ;
else
V_5 -> V_1895 = V_2595 ;
}
if ( F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ||
F_23 ( V_5 , V_684 ) ) {
F_84 ( V_5 , V_1596 ) ;
} else {
F_86 ( V_5 , V_1596 ) ;
F_86 ( V_5 , V_1294 ) ;
V_5 -> V_1895 = NULL ;
}
if ( F_77 ( V_5 ) == V_760 )
V_5 -> V_1895 = V_2596 ;
if ( F_30 ( V_5 ) == V_668 )
V_5 -> V_1895 = V_2597 ;
V_5 -> V_122 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_84 ( V_5 , V_1905 ) ;
if ( F_146 ( V_5 ) == V_742 ||
F_146 ( V_5 ) == V_743 ||
( F_30 ( V_5 ) == V_549 &&
F_77 ( V_5 ) <= V_2598 &&
V_5 -> V_560 == V_5 -> V_12 ) )
F_86 ( V_5 , V_1905 ) ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 ) {
F_84 ( V_5 , 1SHOT_MSI ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
F_84 ( V_5 , V_1065 ) ;
V_5 -> V_122 = V_1899 ;
}
}
V_5 -> V_1904 = 1 ;
V_5 -> V_1902 = 1 ;
if ( V_5 -> V_122 > 1 ) {
V_5 -> V_1902 = V_2048 ;
F_458 ( V_5 , V_2048 ) ;
if ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 )
V_5 -> V_1904 = V_5 -> V_122 - 1 ;
}
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_84 ( V_5 , V_1259 ) ;
if ( F_30 ( V_5 ) == V_478 )
V_5 -> V_1260 = V_2599 ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_768 )
F_84 ( V_5 , V_1715 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) &&
F_77 ( V_5 ) != V_1614 )
F_84 ( V_5 , V_1305 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_1305 ) )
F_84 ( V_5 , V_522 ) ;
F_19 ( V_5 -> V_12 , V_1244 ,
& V_2569 ) ;
if ( F_431 ( V_5 -> V_12 ) ) {
T_3 V_2600 ;
F_84 ( V_5 , V_1083 ) ;
F_641 ( V_5 -> V_12 , V_701 , & V_2600 ) ;
if ( V_2600 & V_702 ) {
if ( F_30 ( V_5 ) == V_36 ) {
F_86 ( V_5 , V_1298 ) ;
F_86 ( V_5 , V_1596 ) ;
}
if ( F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_45 ||
F_77 ( V_5 ) == V_2601 ||
F_77 ( V_5 ) == V_2602 )
F_84 ( V_5 , V_700 ) ;
} else if ( F_77 ( V_5 ) == V_259 ) {
F_84 ( V_5 , V_1555 ) ;
}
} else if ( F_30 ( V_5 ) == V_257 ) {
F_84 ( V_5 , V_1083 ) ;
} else if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ) {
V_5 -> V_1393 = F_642 ( V_5 -> V_12 , V_2603 ) ;
if ( ! V_5 -> V_1393 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_108 ) ;
return - V_210 ;
}
if ( ! ( V_2569 & V_2604 ) )
F_84 ( V_5 , V_842 ) ;
}
if ( F_643 ( V_2605 ) &&
! F_23 ( V_5 , V_1083 ) )
F_84 ( V_5 , V_31 ) ;
F_644 ( V_5 -> V_12 , V_1388 ,
& V_5 -> V_1389 ) ;
F_644 ( V_5 -> V_12 , V_1390 ,
& V_5 -> V_1391 ) ;
if ( F_30 ( V_5 ) == V_500 &&
V_5 -> V_1391 < 64 ) {
V_5 -> V_1391 = 64 ;
F_426 ( V_5 -> V_12 , V_1390 ,
V_5 -> V_1391 ) ;
}
if ( F_146 ( V_5 ) == V_2606 ) {
F_84 ( V_5 , V_34 ) ;
if ( F_23 ( V_5 , V_842 ) ) {
T_1 V_2607 ;
F_84 ( V_5 , V_25 ) ;
F_19 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2608 + V_2609 ,
& V_2607 ) ;
V_2607 &= ~ V_2610 ;
V_2607 |= V_2611 | 0 ;
F_15 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2608 + V_2609 ,
V_2607 ) ;
F_423 ( V_5 -> V_12 , V_1380 , & V_1381 ) ;
V_1381 |= V_2612 | V_1894 ;
F_425 ( V_5 -> V_12 , V_1380 , V_1381 ) ;
}
}
if ( ( V_2569 & V_1643 ) != 0 )
F_84 ( V_5 , V_843 ) ;
if ( ( V_2569 & V_2613 ) != 0 )
F_84 ( V_5 , V_2614 ) ;
if ( ( F_77 ( V_5 ) == V_919 ) &&
( ! ( V_2569 & V_1384 ) ) ) {
V_2569 |= V_1384 ;
F_15 ( V_5 -> V_12 , V_1244 , V_2569 ) ;
}
V_5 -> V_28 = F_9 ;
V_5 -> V_27 = F_7 ;
V_5 -> V_32 = F_9 ;
V_5 -> V_29 = F_7 ;
V_5 -> V_1098 = F_7 ;
V_5 -> V_1887 = F_7 ;
if ( F_23 ( V_5 , V_25 ) )
V_5 -> V_27 = F_13 ;
else if ( F_30 ( V_5 ) == V_538 ||
( F_23 ( V_5 , V_1083 ) &&
F_77 ( V_5 ) == V_1415 ) ) {
V_5 -> V_27 = F_17 ;
}
if ( F_23 ( V_5 , V_34 ) || F_23 ( V_5 , V_31 ) ) {
V_5 -> V_1098 = F_26 ;
if ( F_23 ( V_5 , V_31 ) )
V_5 -> V_1887 = F_17 ;
}
if ( F_23 ( V_5 , V_26 ) ) {
V_5 -> V_28 = F_18 ;
V_5 -> V_27 = F_13 ;
V_5 -> V_32 = F_21 ;
V_5 -> V_29 = F_20 ;
V_5 -> V_1098 = F_20 ;
V_5 -> V_1887 = F_20 ;
F_645 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
F_423 ( V_5 -> V_12 , V_1380 , & V_1381 ) ;
V_1381 &= ~ V_2615 ;
F_425 ( V_5 -> V_12 , V_1380 , V_1381 ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_32 = F_27 ;
V_5 -> V_29 = F_28 ;
V_5 -> V_1098 = F_28 ;
V_5 -> V_1887 = F_28 ;
}
if ( V_5 -> V_27 == F_13 ||
( F_23 ( V_5 , V_842 ) &&
( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) ) )
F_84 ( V_5 , V_39 ) ;
V_7 = F_33 ( V_1067 ) ;
F_46 ( V_1067 , V_7 | V_1379 ) ;
V_5 -> V_54 = F_646 ( V_5 -> V_12 -> V_274 ) & 3 ;
if ( F_30 ( V_5 ) == V_501 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_842 ) ) {
F_19 ( V_5 -> V_12 ,
V_5 -> V_1393 + V_2616 ,
& V_7 ) ;
V_5 -> V_54 = V_7 & 0x7 ;
}
} else if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ) {
F_32 ( V_5 , V_2617 , & V_7 ) ;
if ( ( V_7 & V_2618 ) != V_2619 )
V_7 = F_33 ( V_1872 ) ;
if ( F_30 ( V_5 ) == V_477 )
V_5 -> V_54 = ( V_7 & V_2620 ) ? 1 : 0 ;
else
V_5 -> V_54 = ( V_7 & V_2621 ) >>
V_2622 ;
}
if ( F_23 ( V_5 , V_30 ) ) {
V_5 -> V_1098 = F_17 ;
V_5 -> V_1887 = F_17 ;
}
F_613 ( V_5 ) ;
if ( F_23 ( V_5 , V_684 ) && F_23 ( V_5 , V_309 ) ) {
F_86 ( V_5 , V_1596 ) ;
F_86 ( V_5 , V_1294 ) ;
V_5 -> V_1895 = NULL ;
}
if ( F_23 ( V_5 , V_60 ) ) {
V_2569 |= V_1385 |
V_1386 |
V_1387 ;
F_15 ( V_5 -> V_12 , V_1244 ,
V_2569 ) ;
F_34 ( V_5 ) ;
}
V_5 -> V_22 = V_2623 | V_2372 ;
if ( F_30 ( V_5 ) == V_537 ||
F_23 ( V_5 , V_644 ) )
V_5 -> V_22 |= ( V_539 |
V_540 ) ;
else if ( F_30 ( V_5 ) == V_641 )
V_5 -> V_22 |= V_550 ;
if ( F_30 ( V_5 ) == V_1490 ||
F_30 ( V_5 ) == V_1407 ||
F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_22 |= V_1688 ;
if ( V_5 -> V_12 -> V_544 == V_545 ||
V_5 -> V_12 -> V_544 == V_546 ) {
V_5 -> V_22 |= V_1688 ;
if ( F_23 ( V_5 , V_533 ) )
V_5 -> V_22 |= V_541 |
V_543 ;
}
if ( F_30 ( V_5 ) == V_768 )
V_5 -> V_22 |=
F_33 ( V_136 ) & V_1688 ;
F_148 ( V_5 ) ;
if ( V_5 -> V_111 -> V_1202 > V_1329 && ! F_23 ( V_5 , 5780_CLASS ) )
F_84 ( V_5 , V_1341 ) ;
if ( F_30 ( V_5 ) == V_537 ||
F_77 ( V_5 ) == V_760 ||
F_77 ( V_5 ) == V_761 ||
F_77 ( V_5 ) == V_2624 ) {
F_86 ( V_5 , V_708 ) ;
} else {
F_84 ( V_5 , V_708 ) ;
}
if ( F_30 ( V_5 ) == V_36 )
V_5 -> V_178 |= V_179 ;
if ( F_30 ( V_5 ) == V_537 ||
( F_30 ( V_5 ) == V_502 &&
( F_77 ( V_5 ) != V_1430 ) &&
( F_77 ( V_5 ) != V_1700 ) ) ||
( V_5 -> V_178 & V_179 ) ||
( V_5 -> V_178 & V_360 ) )
V_5 -> V_178 |= V_424 ;
if ( F_146 ( V_5 ) == V_2625 ||
F_146 ( V_5 ) == V_2626 )
V_5 -> V_178 |= V_515 ;
if ( F_77 ( V_5 ) == V_919 )
V_5 -> V_178 |= V_516 ;
if ( F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) != V_257 &&
F_30 ( V_5 ) != V_1407 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
if ( F_30 ( V_5 ) == V_1490 ||
F_30 ( V_5 ) == V_1503 ||
F_30 ( V_5 ) == V_414 ||
F_30 ( V_5 ) == V_45 ) {
if ( V_5 -> V_12 -> V_544 != V_2627 &&
V_5 -> V_12 -> V_544 != V_2628 )
V_5 -> V_178 |= V_518 ;
if ( V_5 -> V_12 -> V_544 == V_2629 )
V_5 -> V_178 |= V_519 ;
} else
V_5 -> V_178 |= V_517 ;
}
if ( F_30 ( V_5 ) == V_414 &&
F_146 ( V_5 ) != V_504 ) {
V_5 -> V_427 = F_617 ( V_5 ) ;
if ( V_5 -> V_427 == 0 )
V_5 -> V_427 = V_2630 ;
}
if ( F_23 ( V_5 , V_152 ) )
V_5 -> V_164 = V_2631 ;
else
V_5 -> V_164 = V_2632 ;
V_5 -> V_127 = 0 ;
if ( F_146 ( V_5 ) != V_2633 &&
F_146 ( V_5 ) != V_2606 )
V_5 -> V_127 |= V_2634 ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_768 ||
F_77 ( V_5 ) == V_1614 ||
F_77 ( V_5 ) == V_1615 ) {
V_5 -> V_127 |= V_2635 ;
V_5 -> V_645 |= V_2636 ;
}
if ( F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1407 )
F_84 ( V_5 , V_267 ) ;
V_75 = F_76 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_7 = F_33 ( V_647 ) ;
if ( F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_768 )
V_7 &= ( V_2637 |
V_2638 |
V_2639 |
V_2640 |
V_1582 ) ;
else
V_7 &= V_1582 ;
F_46 ( V_647 , V_7 | V_5 -> V_645 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
F_46 ( V_13 , 0 ) ;
F_19 ( V_5 -> V_12 , V_1244 ,
& V_2569 ) ;
if ( ( V_2569 & V_2604 ) == 0 &&
! F_23 ( V_5 , V_25 ) ) {
if ( F_77 ( V_5 ) == V_760 ||
F_77 ( V_5 ) == V_761 ||
F_77 ( V_5 ) == V_2624 ||
F_77 ( V_5 ) == V_2641 ) {
void T_2 * V_2642 ;
V_2642 = V_5 -> V_8 + V_2643 + V_37 ;
F_8 ( 0x00000000 , V_2642 ) ;
F_8 ( 0x00000000 , V_2642 + 4 ) ;
F_8 ( 0xffffffff , V_2642 + 4 ) ;
if ( F_10 ( V_2642 ) != 0x00000000 )
F_84 ( V_5 , V_25 ) ;
}
}
F_24 ( 50 ) ;
F_611 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_668 &&
! F_23 ( V_5 , V_682 ) )
V_5 -> V_1895 = NULL ;
V_2564 = F_33 ( V_498 ) ;
V_2564 &= V_2565 ;
if ( F_30 ( V_5 ) == V_502 &&
( V_2564 == V_2644 ||
V_2564 == V_2645 ) )
F_84 ( V_5 , V_1644 ) ;
if ( ! F_23 ( V_5 , V_1644 ) &&
F_30 ( V_5 ) != V_537 )
F_84 ( V_5 , V_133 ) ;
if ( F_23 ( V_5 , V_133 ) ) {
V_5 -> V_127 |= ( V_2646 |
V_2647 ) ;
V_5 -> V_120 |= V_2648 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
}
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_368 = V_731 | V_732 ;
else
V_5 -> V_368 = 0 ;
if ( F_638 ( V_5 , V_2563 ) )
V_5 -> V_178 |= V_393 ;
V_75 = F_619 ( V_5 ) ;
if ( V_75 ) {
F_117 ( & V_5 -> V_12 -> V_111 , L_109 , V_75 ) ;
F_85 ( V_5 ) ;
}
F_621 ( V_5 ) ;
F_632 ( V_5 ) ;
if ( V_5 -> V_178 & V_568 ) {
V_5 -> V_178 &= ~ V_819 ;
} else {
if ( F_30 ( V_5 ) == V_537 )
V_5 -> V_178 |= V_819 ;
else
V_5 -> V_178 &= ~ V_819 ;
}
if ( F_30 ( V_5 ) == V_537 )
F_84 ( V_5 , V_142 ) ;
else
F_86 ( V_5 , V_142 ) ;
if ( V_5 -> V_12 -> V_2376 == V_2420 &&
F_30 ( V_5 ) == V_538 &&
! ( V_5 -> V_178 & V_568 ) ) {
V_5 -> V_178 |= V_819 ;
F_84 ( V_5 , V_142 ) ;
}
if ( V_5 -> V_178 & V_568 )
F_84 ( V_5 , V_143 ) ;
else
F_86 ( V_5 , V_143 ) ;
if ( F_23 ( V_5 , V_60 ) && F_23 ( V_5 , V_309 ) )
F_84 ( V_5 , V_1870 ) ;
V_5 -> V_2649 = V_2650 + V_2651 ;
V_5 -> V_2652 = V_2653 ;
if ( F_30 ( V_5 ) == V_538 &&
F_23 ( V_5 , V_842 ) ) {
V_5 -> V_2649 = V_2650 ;
#ifndef F_647
V_5 -> V_2652 = ~ ( T_3 ) 0 ;
#endif
}
V_5 -> V_1142 = F_465 ( V_5 ) - 1 ;
V_5 -> V_1147 = F_464 ( V_5 ) - 1 ;
V_5 -> V_1209 = F_633 ( V_5 ) - 1 ;
V_5 -> V_1208 = V_5 -> V_1142 + 1 ;
if ( F_30 ( V_5 ) == V_1501 ||
F_30 ( V_5 ) == V_641 ||
F_30 ( V_5 ) == V_1490 )
V_5 -> V_1208 = 8 ;
if ( F_23 ( V_5 , V_975 ) )
V_5 -> V_978 = F_33 ( V_976 ) &
V_977 ;
return V_75 ;
}
static int F_648 ( struct V_4 * V_5 )
{
struct V_365 * V_111 = V_5 -> V_111 ;
struct V_1795 * V_12 = V_5 -> V_12 ;
struct V_2654 * V_2025 = F_649 ( V_12 ) ;
const unsigned char * V_184 ;
int V_74 ;
V_184 = F_650 ( V_2025 , L_110 , & V_74 ) ;
if ( V_184 && V_74 == V_1527 ) {
memcpy ( V_111 -> V_695 , V_184 , V_1527 ) ;
return 0 ;
}
return - V_82 ;
}
static int F_651 ( struct V_4 * V_5 )
{
struct V_365 * V_111 = V_5 -> V_111 ;
memcpy ( V_111 -> V_695 , V_2655 -> V_2656 , V_1527 ) ;
return 0 ;
}
static int F_652 ( struct V_4 * V_5 )
{
struct V_365 * V_111 = V_5 -> V_111 ;
T_1 V_2657 , V_2658 , V_2659 ;
int V_2660 = 0 ;
int V_75 ;
#ifdef F_653
if ( ! F_648 ( V_5 ) )
return 0 ;
#endif
if ( F_23 ( V_5 , V_264 ) ) {
V_75 = F_654 ( V_5 -> V_12 , & V_111 -> V_695 [ 0 ] ) ;
if ( ! V_75 && F_437 ( & V_111 -> V_695 [ 0 ] ) )
return 0 ;
}
V_2659 = 0x7c ;
if ( F_30 ( V_5 ) == V_501 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_33 ( V_921 ) & V_922 )
V_2659 = 0xcc ;
if ( F_158 ( V_5 ) )
F_31 ( V_608 , V_2661 ) ;
else
F_159 ( V_5 ) ;
} else if ( F_23 ( V_5 , 5717_PLUS ) ) {
if ( V_5 -> V_54 & 1 )
V_2659 = 0xcc ;
if ( V_5 -> V_54 > 1 )
V_2659 += 0x18c ;
} else if ( F_30 ( V_5 ) == V_36 )
V_2659 = 0x10 ;
F_32 ( V_5 , V_2662 , & V_2657 ) ;
if ( ( V_2657 >> 16 ) == 0x484b ) {
V_111 -> V_695 [ 0 ] = ( V_2657 >> 8 ) & 0xff ;
V_111 -> V_695 [ 1 ] = ( V_2657 >> 0 ) & 0xff ;
F_32 ( V_5 , V_2663 , & V_2658 ) ;
V_111 -> V_695 [ 2 ] = ( V_2658 >> 24 ) & 0xff ;
V_111 -> V_695 [ 3 ] = ( V_2658 >> 16 ) & 0xff ;
V_111 -> V_695 [ 4 ] = ( V_2658 >> 8 ) & 0xff ;
V_111 -> V_695 [ 5 ] = ( V_2658 >> 0 ) & 0xff ;
V_2660 = F_437 ( & V_111 -> V_695 [ 0 ] ) ;
}
if ( ! V_2660 ) {
if ( ! F_23 ( V_5 , V_682 ) &&
! F_169 ( V_5 , V_2659 + 0 , & V_2657 ) &&
! F_169 ( V_5 , V_2659 + 4 , & V_2658 ) ) {
memcpy ( & V_111 -> V_695 [ 0 ] , ( ( char * ) & V_2657 ) + 2 , 2 ) ;
memcpy ( & V_111 -> V_695 [ 2 ] , ( char * ) & V_2658 , sizeof( V_2658 ) ) ;
}
else {
V_2657 = F_33 ( V_690 ) ;
V_2658 = F_33 ( V_691 ) ;
V_111 -> V_695 [ 5 ] = V_2658 & 0xff ;
V_111 -> V_695 [ 4 ] = ( V_2658 >> 8 ) & 0xff ;
V_111 -> V_695 [ 3 ] = ( V_2658 >> 16 ) & 0xff ;
V_111 -> V_695 [ 2 ] = ( V_2658 >> 24 ) & 0xff ;
V_111 -> V_695 [ 1 ] = V_2657 & 0xff ;
V_111 -> V_695 [ 0 ] = ( V_2657 >> 8 ) & 0xff ;
}
}
if ( ! F_437 ( & V_111 -> V_695 [ 0 ] ) ) {
#ifdef F_653
if ( ! F_651 ( V_5 ) )
return 0 ;
#endif
return - V_64 ;
}
return 0 ;
}
static T_1 F_655 ( struct V_4 * V_5 , T_1 V_7 )
{
int V_2664 ;
T_4 V_2665 ;
int V_2666 ;
F_644 ( V_5 -> V_12 , V_1388 , & V_2665 ) ;
if ( V_2665 == 0 )
V_2664 = 1024 ;
else
V_2664 = ( int ) V_2665 * 4 ;
if ( F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_538 &&
! F_23 ( V_5 , V_1083 ) )
goto V_503;
#if F_359 ( V_2667 ) || F_359 ( V_2668 ) || F_359 ( V_2669 )
V_2666 = V_2670 ;
#else
#if F_359 ( V_2671 ) || F_359 ( V_2672 )
V_2666 = V_2673 ;
#else
V_2666 = 0 ;
#endif
#endif
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = V_2666 ? 0 : V_1573 ;
goto V_503;
}
if ( ! V_2666 )
goto V_503;
if ( F_23 ( V_5 , V_842 ) && ! F_23 ( V_5 , V_1083 ) ) {
switch ( V_2664 ) {
case 16 :
case 32 :
case 64 :
case 128 :
if ( V_2666 == V_2673 ) {
V_7 |= ( V_2674 |
V_2675 ) ;
} else {
V_7 |= ( V_2676 |
V_2677 ) ;
}
break;
case 256 :
V_7 |= ( V_2678 |
V_2679 ) ;
break;
default:
V_7 |= ( V_2676 |
V_2677 ) ;
break;
}
} else if ( F_23 ( V_5 , V_1083 ) ) {
switch ( V_2664 ) {
case 16 :
case 32 :
case 64 :
if ( V_2666 == V_2673 ) {
V_7 &= ~ V_2680 ;
V_7 |= V_2681 ;
break;
}
case 128 :
default:
V_7 &= ~ V_2680 ;
V_7 |= V_2682 ;
break;
}
} else {
switch ( V_2664 ) {
case 16 :
if ( V_2666 == V_2673 ) {
V_7 |= ( V_2683 |
V_2684 ) ;
break;
}
case 32 :
if ( V_2666 == V_2673 ) {
V_7 |= ( V_2685 |
V_2686 ) ;
break;
}
case 64 :
if ( V_2666 == V_2673 ) {
V_7 |= ( V_2687 |
V_2688 ) ;
break;
}
case 128 :
if ( V_2666 == V_2673 ) {
V_7 |= ( V_2689 |
V_2690 ) ;
break;
}
case 256 :
V_7 |= ( V_2691 |
V_2692 ) ;
break;
case 512 :
V_7 |= ( V_2693 |
V_2694 ) ;
break;
case 1024 :
default:
V_7 |= ( V_2695 |
V_2696 ) ;
break;
}
}
V_503:
return V_7 ;
}
static int F_656 ( struct V_4 * V_5 , T_1 * V_627 , T_9 V_2697 ,
int V_635 , bool V_2698 )
{
struct V_2699 V_2700 ;
T_1 V_2701 ;
int V_42 , V_56 ;
V_2701 = V_1593 ;
F_46 ( V_2702 , 0 ) ;
F_46 ( V_2703 , 0 ) ;
F_46 ( V_1235 , 0 ) ;
F_46 ( V_1236 , 0 ) ;
F_46 ( V_1068 , 0 ) ;
F_46 ( V_1078 , 0 ) ;
V_2700 . V_1152 = ( ( T_6 ) V_2697 ) >> 32 ;
V_2700 . V_1153 = V_2697 & 0xffffffff ;
V_2700 . V_2704 = 0x00002100 ;
V_2700 . V_74 = V_635 ;
if ( V_2698 ) {
V_2700 . V_2705 = ( 13 << 8 ) | 2 ;
F_31 ( V_1069 , V_1372 ) ;
F_24 ( 40 ) ;
} else {
V_2700 . V_2705 = ( 16 << 8 ) | 7 ;
F_31 ( V_1070 , V_1376 ) ;
F_24 ( 40 ) ;
}
V_2700 . V_10 = 0x00000005 ;
for ( V_42 = 0 ; V_42 < ( sizeof( V_2700 ) / sizeof( T_1 ) ) ; V_42 ++ ) {
T_1 V_7 ;
V_7 = * ( ( ( T_1 * ) & V_2700 ) + V_42 ) ;
F_15 ( V_5 -> V_12 , V_40 ,
V_2701 + ( V_42 * sizeof( T_1 ) ) ) ;
F_15 ( V_5 -> V_12 , V_41 , V_7 ) ;
}
F_15 ( V_5 -> V_12 , V_40 , 0 ) ;
if ( V_2698 )
F_46 ( V_2706 , V_2701 ) ;
else
F_46 ( V_2707 , V_2701 ) ;
V_56 = - V_82 ;
for ( V_42 = 0 ; V_42 < 40 ; V_42 ++ ) {
T_1 V_7 ;
if ( V_2698 )
V_7 = F_33 ( V_2702 ) ;
else
V_7 = F_33 ( V_2703 ) ;
if ( ( V_7 & 0xffff ) == V_2701 ) {
V_56 = 0 ;
break;
}
F_24 ( 100 ) ;
}
return V_56 ;
}
static int F_657 ( struct V_4 * V_5 )
{
T_9 V_2697 ;
T_1 * V_627 , V_2708 ;
int V_56 = 0 ;
V_627 = F_407 ( & V_5 -> V_12 -> V_111 , V_2709 ,
& V_2697 , V_633 ) ;
if ( ! V_627 ) {
V_56 = - V_268 ;
goto V_2710;
}
V_5 -> V_1576 = ( ( 0x7 << V_2711 ) |
( 0x6 << V_2712 ) ) ;
V_5 -> V_1576 = F_655 ( V_5 , V_5 -> V_1576 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
goto V_503;
if ( F_23 ( V_5 , V_1083 ) ) {
V_5 -> V_1576 |= 0x00180000 ;
} else if ( ! F_23 ( V_5 , V_842 ) ) {
if ( F_30 ( V_5 ) == V_502 ||
F_30 ( V_5 ) == V_1501 )
V_5 -> V_1576 |= 0x003f0000 ;
else
V_5 -> V_1576 |= 0x003f000f ;
} else {
if ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ) {
T_1 V_2713 = ( F_33 ( V_153 ) & 0x1f ) ;
T_1 V_2714 = 0x7 ;
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) &&
F_30 ( V_5 ) == V_501 )
V_5 -> V_1576 |= 0x8000 ;
else if ( V_2713 == 0x6 || V_2713 == 0x7 )
V_5 -> V_1576 |= V_2715 ;
if ( F_30 ( V_5 ) == V_500 )
V_2714 = 4 ;
V_5 -> V_1576 |=
( V_2714 << V_2716 ) |
( 0x3 << V_2717 ) |
( 1 << 23 ) ;
} else if ( F_30 ( V_5 ) == V_567 ) {
V_5 -> V_1576 |= 0x00144000 ;
} else if ( F_30 ( V_5 ) == V_549 ) {
V_5 -> V_1576 |= 0x00148000 ;
} else {
V_5 -> V_1576 |= 0x001b000f ;
}
}
if ( F_23 ( V_5 , V_2718 ) )
V_5 -> V_1576 |= V_2715 ;
if ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 )
V_5 -> V_1576 &= 0xfffffff0 ;
if ( F_30 ( V_5 ) == V_537 ||
F_30 ( V_5 ) == V_538 ) {
V_5 -> V_1576 |= V_2719 ;
V_5 -> V_1576 |= V_2720 ;
}
F_46 ( V_1572 , V_5 -> V_1576 ) ;
if ( F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_538 )
goto V_503;
V_2708 = V_5 -> V_1576 ;
V_5 -> V_1576 &= ~ V_2721 ;
F_46 ( V_1572 , V_5 -> V_1576 ) ;
while ( 1 ) {
T_1 * V_1442 = V_627 , V_42 ;
for ( V_42 = 0 ; V_42 < V_2709 / sizeof( T_1 ) ; V_42 ++ )
V_1442 [ V_42 ] = V_42 ;
V_56 = F_656 ( V_5 , V_627 , V_2697 , V_2709 , true ) ;
if ( V_56 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_111 ,
V_658 , V_56 ) ;
break;
}
V_56 = F_656 ( V_5 , V_627 , V_2697 , V_2709 , false ) ;
if ( V_56 ) {
F_117 ( & V_5 -> V_12 -> V_111 , L_112
L_113 , V_658 , V_56 ) ;
break;
}
for ( V_42 = 0 ; V_42 < V_2709 / sizeof( T_1 ) ; V_42 ++ ) {
if ( V_1442 [ V_42 ] == V_42 )
continue;
if ( ( V_5 -> V_1576 & V_2721 ) !=
V_2684 ) {
V_5 -> V_1576 &= ~ V_2721 ;
V_5 -> V_1576 |= V_2684 ;
F_46 ( V_1572 , V_5 -> V_1576 ) ;
break;
} else {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_114
L_115 , V_658 , V_1442 [ V_42 ] , V_42 ) ;
V_56 = - V_82 ;
goto V_503;
}
}
if ( V_42 == ( V_2709 / sizeof( T_1 ) ) ) {
V_56 = 0 ;
break;
}
}
if ( ( V_5 -> V_1576 & V_2721 ) !=
V_2684 ) {
if ( F_643 ( V_2722 ) ) {
V_5 -> V_1576 &= ~ V_2721 ;
V_5 -> V_1576 |= V_2684 ;
} else {
V_5 -> V_1576 = V_2708 ;
}
F_46 ( V_1572 , V_5 -> V_1576 ) ;
}
V_503:
F_405 ( & V_5 -> V_12 -> V_111 , V_2709 , V_627 , V_2697 ) ;
V_2710:
return V_56 ;
}
static void F_658 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_5 -> V_1599 . V_1600 =
V_2723 ;
V_5 -> V_1599 . V_1602 =
V_2724 ;
V_5 -> V_1599 . V_1604 =
V_2725 ;
V_5 -> V_1599 . V_1605 =
V_2723 ;
V_5 -> V_1599 . V_1606 =
V_2726 ;
V_5 -> V_1599 . V_1607 =
V_2727 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_5 -> V_1599 . V_1600 =
V_2723 ;
V_5 -> V_1599 . V_1602 =
V_2728 ;
V_5 -> V_1599 . V_1604 =
V_2729 ;
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_1599 . V_1602 =
V_2730 ;
V_5 -> V_1599 . V_1604 =
V_2731 ;
}
V_5 -> V_1599 . V_1605 =
V_2732 ;
V_5 -> V_1599 . V_1606 =
V_2733 ;
V_5 -> V_1599 . V_1607 =
V_2734 ;
} else {
V_5 -> V_1599 . V_1600 =
V_2735 ;
V_5 -> V_1599 . V_1602 =
V_2736 ;
V_5 -> V_1599 . V_1604 =
V_2737 ;
V_5 -> V_1599 . V_1605 =
V_2738 ;
V_5 -> V_1599 . V_1606 =
V_2739 ;
V_5 -> V_1599 . V_1607 =
V_2740 ;
}
V_5 -> V_1599 . V_1609 = V_2741 ;
V_5 -> V_1599 . V_1611 = V_2742 ;
}
static char * F_659 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_216 & V_401 ) {
case V_2743 : return L_116 ;
case V_402 : return L_117 ;
case V_566 : return L_118 ;
case V_2744 : return L_119 ;
case V_2745 : return L_120 ;
case V_2746 : return L_121 ;
case V_2747 : return L_122 ;
case V_2748 : return L_123 ;
case V_2749 : return L_124 ;
case V_2750 : return L_125 ;
case V_2751 : return L_126 ;
case V_2752 : return L_127 ;
case V_2753 : return L_128 ;
case V_2754 : return L_129 ;
case V_2755 : return L_130 ;
case V_2756 : return L_131 ;
case V_2757 : return L_132 ;
case V_2758 : return L_133 ;
case V_2759 : return L_134 ;
case V_2760 : return L_135 ;
case V_2761 : return L_136 ;
case V_2762 : return L_137 ;
case V_2763 : return L_138 ;
case V_942 : return L_139 ;
case 0 : return L_140 ;
default: return L_141 ;
}
}
static char * F_660 ( struct V_4 * V_5 , char * V_2764 )
{
if ( F_23 ( V_5 , V_1083 ) ) {
strcpy ( V_2764 , L_142 ) ;
return V_2764 ;
} else if ( F_23 ( V_5 , V_842 ) ) {
T_1 V_150 = F_33 ( V_153 ) & 0x1f ;
strcpy ( V_2764 , L_143 ) ;
if ( ( V_150 == 7 ) ||
( ( F_33 ( V_498 ) & V_2565 ) ==
V_2765 ) )
strcat ( V_2764 , L_144 ) ;
else if ( V_150 == 0 )
strcat ( V_2764 , L_145 ) ;
else if ( V_150 == 2 )
strcat ( V_2764 , L_146 ) ;
else if ( V_150 == 4 )
strcat ( V_2764 , L_147 ) ;
else if ( V_150 == 6 )
strcat ( V_2764 , L_148 ) ;
} else {
strcpy ( V_2764 , L_149 ) ;
if ( F_23 ( V_5 , V_843 ) )
strcat ( V_2764 , L_147 ) ;
else
strcat ( V_2764 , L_145 ) ;
}
if ( F_23 ( V_5 , V_2614 ) )
strcat ( V_2764 , L_150 ) ;
else
strcat ( V_2764 , L_151 ) ;
return V_2764 ;
}
static void F_661 ( struct V_4 * V_5 )
{
struct V_1460 * V_1461 = & V_5 -> V_973 ;
memset ( V_1461 , 0 , sizeof( * V_1461 ) ) ;
V_1461 -> V_643 = V_2766 ;
V_1461 -> V_1472 = V_2767 ;
V_1461 -> V_1463 = V_2768 ;
V_1461 -> V_1474 = V_2769 ;
V_1461 -> V_1465 = V_2770 ;
V_1461 -> V_1480 = V_2771 ;
V_1461 -> V_1482 = V_2772 ;
V_1461 -> V_1476 = V_2773 ;
V_1461 -> V_1467 = V_2774 ;
V_1461 -> V_974 = V_2775 ;
if ( V_5 -> V_127 & ( V_2646 |
V_2647 ) ) {
V_1461 -> V_1472 = V_2776 ;
V_1461 -> V_1480 = V_2777 ;
V_1461 -> V_1463 = V_2778 ;
V_1461 -> V_1482 = V_2779 ;
}
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_1461 -> V_1480 = 0 ;
V_1461 -> V_1482 = 0 ;
V_1461 -> V_974 = 0 ;
}
}
static int F_662 ( struct V_1795 * V_12 ,
const struct V_2562 * V_2563 )
{
struct V_365 * V_111 ;
struct V_4 * V_5 ;
int V_42 , V_75 ;
T_1 V_2780 , V_2781 , V_2782 ;
char V_2764 [ 40 ] ;
T_6 V_2783 , V_2784 ;
T_13 V_1193 = 0 ;
F_663 ( V_2785 L_152 , V_1977 ) ;
V_75 = F_664 ( V_12 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_153 ) ;
return V_75 ;
}
V_75 = F_665 ( V_12 , V_2015 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_154 ) ;
goto V_2786;
}
F_666 ( V_12 ) ;
V_111 = F_667 ( sizeof( * V_5 ) , V_1899 ) ;
if ( ! V_111 ) {
V_75 = - V_268 ;
goto V_2787;
}
F_668 ( V_111 , & V_12 -> V_111 ) ;
V_5 = F_111 ( V_111 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_111 = V_111 ;
V_5 -> V_355 = V_2788 ;
V_5 -> V_357 = V_2789 ;
V_5 -> V_125 = 1 ;
if ( V_2790 > 0 )
V_5 -> V_2026 = V_2790 ;
else
V_5 -> V_2026 = V_2791 ;
if ( F_669 ( V_12 ) ) {
F_84 ( V_5 , V_264 ) ;
if ( F_670 ( V_12 ) )
F_84 ( V_5 , V_30 ) ;
if ( F_671 ( V_12 ) )
F_84 ( V_5 , V_2718 ) ;
if ( F_672 ( V_12 ) ) {
F_84 ( V_5 , V_267 ) ;
F_84 ( V_5 , V_265 ) ;
}
if ( F_673 ( V_12 ) )
F_84 ( V_5 , V_836 ) ;
}
V_5 -> V_120 =
V_121 |
V_2792 |
V_2793 |
V_2794 ;
V_5 -> V_645 = ( V_2795 | V_2796 |
V_2797 ) ;
#ifdef F_674
V_5 -> V_645 |= V_2798 ;
#endif
F_675 ( & V_5 -> V_209 ) ;
F_675 ( & V_5 -> V_11 ) ;
F_676 ( & V_5 -> V_1225 , F_488 ) ;
V_5 -> V_8 = F_677 ( V_12 , V_2799 ) ;
if ( ! V_5 -> V_8 ) {
F_117 ( & V_12 -> V_111 , L_155 ) ;
V_75 = - V_268 ;
goto V_2800;
}
if ( V_5 -> V_12 -> V_544 == V_545 ||
V_5 -> V_12 -> V_544 == V_2801 ||
V_5 -> V_12 -> V_544 == V_546 ||
V_5 -> V_12 -> V_544 == V_2802 ||
V_5 -> V_12 -> V_544 == V_2477 ||
V_5 -> V_12 -> V_544 == V_2478 ||
V_5 -> V_12 -> V_544 == V_2479 ||
V_5 -> V_12 -> V_544 == V_2549 ||
V_5 -> V_12 -> V_544 == V_2550 ||
V_5 -> V_12 -> V_544 == V_2551 ||
V_5 -> V_12 -> V_544 == V_2552 ||
V_5 -> V_12 -> V_544 == V_2553 ||
V_5 -> V_12 -> V_544 == V_2528 ||
V_5 -> V_12 -> V_544 == V_2554 ||
V_5 -> V_12 -> V_544 == V_2555 ) {
F_84 ( V_5 , V_60 ) ;
V_5 -> V_9 = F_677 ( V_12 , V_2803 ) ;
if ( ! V_5 -> V_9 ) {
F_117 ( & V_12 -> V_111 ,
L_156 ) ;
V_75 = - V_268 ;
goto V_2804;
}
}
V_5 -> V_1339 = V_2805 ;
V_5 -> V_1343 = V_2806 ;
V_111 -> V_2807 = & V_2808 ;
V_111 -> V_2809 = V_2810 ;
V_111 -> V_2811 = & V_2812 ;
V_111 -> V_280 = V_12 -> V_280 ;
V_75 = F_639 ( V_5 , V_2563 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 ,
L_157 ) ;
goto V_2813;
}
if ( F_23 ( V_5 , V_1644 ) )
V_2784 = V_2783 = F_360 ( 32 ) ;
else if ( F_23 ( V_5 , 40BIT_DMA_BUG ) ) {
V_2784 = V_2783 = F_360 ( 40 ) ;
#ifdef V_1248
V_2783 = F_360 ( 64 ) ;
#endif
} else
V_2784 = V_2783 = F_360 ( 64 ) ;
if ( V_2783 > F_360 ( 32 ) ) {
V_75 = F_678 ( V_12 , V_2783 ) ;
if ( ! V_75 ) {
V_1193 |= V_2814 ;
V_75 = F_679 ( V_12 ,
V_2784 ) ;
if ( V_75 < 0 ) {
F_117 ( & V_12 -> V_111 , L_158
L_159 ) ;
goto V_2813;
}
}
}
if ( V_75 || V_2783 == F_360 ( 32 ) ) {
V_75 = F_678 ( V_12 , F_360 ( 32 ) ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 ,
L_160 ) ;
goto V_2813;
}
}
F_658 ( V_5 ) ;
if ( F_77 ( V_5 ) != V_2815 ) {
V_1193 |= V_2816 | V_2817 | V_1194 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_1193 |= V_2818 ;
}
if ( ( F_23 ( V_5 , V_1297 ) ||
F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ) &&
( V_1193 & V_2817 ) )
V_1193 |= V_1279 ;
if ( F_23 ( V_5 , V_1298 ) || F_23 ( V_5 , V_1299 ) ) {
if ( V_1193 & V_2818 )
V_1193 |= V_2819 ;
if ( F_23 ( V_5 , V_1299 ) ||
F_30 ( V_5 ) == V_45 ||
( F_30 ( V_5 ) == V_414 &&
F_146 ( V_5 ) != V_504 ) ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1407 )
V_1193 |= V_2820 ;
}
V_111 -> V_1193 |= V_1193 | V_2821 |
V_2822 ;
V_111 -> V_2823 |= V_1193 ;
if ( F_30 ( V_5 ) != V_567 &&
! F_23 ( V_5 , V_152 ) )
V_1193 |= V_1328 ;
V_111 -> V_2824 |= V_1193 ;
V_111 -> V_2825 |= V_2826 ;
if ( F_77 ( V_5 ) == V_1700 &&
! F_23 ( V_5 , V_1596 ) &&
! ( F_33 ( V_1244 ) & V_1643 ) ) {
F_84 ( V_5 , V_2034 ) ;
V_5 -> V_1339 = 63 ;
}
V_75 = F_652 ( V_5 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 ,
L_161 ) ;
goto V_2813;
}
if ( ( F_33 ( V_138 ) & V_128 ) ||
( F_33 ( V_1070 ) & V_1376 ) ) {
F_46 ( V_1067 , V_1379 ) ;
F_433 ( V_5 , V_110 , 1 ) ;
}
V_75 = F_657 ( V_5 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_162 ) ;
goto V_2813;
}
V_2782 = V_20 + V_16 ;
V_2781 = V_15 + V_16 ;
V_2780 = V_2827 + V_16 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_131 -> V_5 = V_5 ;
V_131 -> V_1092 = V_2828 ;
V_131 -> V_124 = V_2782 ;
if ( V_42 <= 4 )
V_2782 += 0x8 ;
else
V_2782 += 0x4 ;
V_131 -> V_1210 = V_2781 ;
V_131 -> V_1317 = V_2780 ;
if ( V_42 )
V_131 -> V_126 = V_2829 << ( V_42 - 1 ) ;
else
V_131 -> V_126 = V_1864 ;
if ( ! F_23 ( V_5 , V_1065 ) )
break;
if ( ! V_42 )
continue;
V_2781 += 0x8 ;
if ( V_2780 & 0x4 )
V_2780 -= 0x4 ;
else
V_2780 += 0xc ;
}
F_661 ( V_5 ) ;
F_680 ( V_12 , V_111 ) ;
if ( F_30 ( V_5 ) == V_478 ||
F_30 ( V_5 ) == V_534 ||
F_30 ( V_5 ) == V_768 )
F_84 ( V_5 , V_993 ) ;
F_481 ( V_5 ) ;
F_140 ( V_5 ) ;
V_75 = F_681 ( V_111 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_163 ) ;
goto V_2813;
}
F_98 ( V_111 , L_164 ,
V_5 -> V_2476 ,
F_77 ( V_5 ) ,
F_660 ( V_5 , V_2764 ) ,
V_111 -> V_695 ) ;
if ( V_5 -> V_178 & V_392 ) {
struct V_211 * V_212 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
F_98 ( V_111 ,
L_165 ,
V_212 -> V_215 -> V_269 , F_115 ( & V_212 -> V_111 ) ) ;
} else {
char * V_2830 ;
if ( V_5 -> V_178 & V_393 )
V_2830 = L_166 ;
else if ( V_5 -> V_178 & V_360 )
V_2830 = L_167 ;
else
V_2830 = L_168 ;
F_98 ( V_111 , L_169
L_170 ,
F_659 ( V_5 ) , V_2830 ,
( V_5 -> V_178 & V_424 ) == 0 ,
( V_5 -> V_178 & V_339 ) != 0 ) ;
}
F_98 ( V_111 , L_171 ,
( V_111 -> V_1193 & V_1194 ) != 0 ,
F_23 ( V_5 , V_142 ) != 0 ,
( V_5 -> V_178 & V_819 ) != 0 ,
F_23 ( V_5 , V_309 ) != 0 ,
F_23 ( V_5 , V_1596 ) != 0 ) ;
F_98 ( V_111 , L_172 ,
V_5 -> V_1576 ,
V_12 -> V_2783 == F_360 ( 32 ) ? 32 :
( ( T_6 ) V_12 -> V_2783 ) == F_360 ( 40 ) ? 40 : 64 ) ;
F_682 ( V_12 ) ;
return 0 ;
V_2813:
if ( V_5 -> V_9 ) {
F_645 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
V_2804:
if ( V_5 -> V_8 ) {
F_645 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
V_2800:
F_683 ( V_111 ) ;
V_2787:
F_684 ( V_12 ) ;
V_2786:
if ( F_685 ( V_12 ) )
F_686 ( V_12 ) ;
return V_75 ;
}
static void F_687 ( struct V_1795 * V_12 )
{
struct V_365 * V_111 = F_153 ( V_12 ) ;
if ( V_111 ) {
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_498 ( V_5 -> V_663 ) ;
F_326 ( V_5 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
F_125 ( V_5 ) ;
F_85 ( V_5 ) ;
}
F_688 ( V_111 ) ;
if ( V_5 -> V_9 ) {
F_645 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
if ( V_5 -> V_8 ) {
F_645 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
F_683 ( V_111 ) ;
F_684 ( V_12 ) ;
F_686 ( V_12 ) ;
}
}
static int F_689 ( struct V_544 * V_544 )
{
struct V_1795 * V_12 = F_690 ( V_544 ) ;
struct V_365 * V_111 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 = 0 ;
F_691 () ;
if ( ! F_145 ( V_111 ) )
goto V_2831;
F_326 ( V_5 ) ;
F_123 ( V_5 ) ;
F_341 ( V_5 ) ;
F_484 ( V_5 ) ;
F_241 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_242 ( V_5 ) ;
F_692 ( V_111 ) ;
F_241 ( V_5 , 0 ) ;
F_433 ( V_5 , V_110 , 1 ) ;
F_86 ( V_5 , V_563 ) ;
F_242 ( V_5 ) ;
V_75 = F_199 ( V_5 ) ;
if ( V_75 ) {
int V_762 ;
F_241 ( V_5 , 0 ) ;
F_84 ( V_5 , V_563 ) ;
V_762 = F_486 ( V_5 , true ) ;
if ( V_762 )
goto V_503;
F_483 ( V_5 ) ;
F_693 ( V_111 ) ;
F_343 ( V_5 ) ;
V_503:
F_242 ( V_5 ) ;
if ( ! V_762 )
F_120 ( V_5 ) ;
}
V_2831:
F_694 () ;
return V_75 ;
}
static int F_695 ( struct V_544 * V_544 )
{
struct V_1795 * V_12 = F_690 ( V_544 ) ;
struct V_365 * V_111 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 = 0 ;
F_691 () ;
if ( ! F_145 ( V_111 ) )
goto V_2831;
F_693 ( V_111 ) ;
F_241 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_84 ( V_5 , V_563 ) ;
V_75 = F_486 ( V_5 ,
! ( V_5 -> V_178 & V_570 ) ) ;
if ( V_75 )
goto V_503;
F_483 ( V_5 ) ;
F_343 ( V_5 ) ;
V_503:
F_242 ( V_5 ) ;
if ( ! V_75 )
F_120 ( V_5 ) ;
V_2831:
F_694 () ;
return V_75 ;
}
static void F_696 ( struct V_1795 * V_12 )
{
struct V_365 * V_111 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_691 () ;
F_692 ( V_111 ) ;
if ( F_145 ( V_111 ) )
F_487 ( V_111 ) ;
if ( V_2832 == V_2833 )
F_202 ( V_5 ) ;
F_694 () ;
}
static T_19 F_697 ( struct V_1795 * V_12 ,
T_20 V_849 )
{
struct V_365 * V_2834 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_2834 ) ;
T_19 V_75 = V_2835 ;
F_98 ( V_2834 , L_173 ) ;
F_691 () ;
if ( ! V_2834 || ! F_145 ( V_2834 ) )
goto V_186;
F_123 ( V_5 ) ;
F_341 ( V_5 ) ;
F_484 ( V_5 ) ;
F_326 ( V_5 ) ;
F_692 ( V_2834 ) ;
F_241 ( V_5 , 0 ) ;
F_433 ( V_5 , V_110 , 0 ) ;
F_242 ( V_5 ) ;
V_186:
if ( V_849 == V_2836 ) {
if ( V_2834 ) {
F_335 ( V_5 ) ;
F_487 ( V_2834 ) ;
}
V_75 = V_2837 ;
} else {
F_686 ( V_12 ) ;
}
F_694 () ;
return V_75 ;
}
static T_19 F_698 ( struct V_1795 * V_12 )
{
struct V_365 * V_2834 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_2834 ) ;
T_19 V_629 = V_2837 ;
int V_75 ;
F_691 () ;
if ( F_664 ( V_12 ) ) {
F_117 ( & V_12 -> V_111 ,
L_174 ) ;
goto V_186;
}
F_666 ( V_12 ) ;
F_699 ( V_12 ) ;
F_682 ( V_12 ) ;
if ( ! V_2834 || ! F_145 ( V_2834 ) ) {
V_629 = V_2838 ;
goto V_186;
}
V_75 = F_197 ( V_5 ) ;
if ( V_75 )
goto V_186;
V_629 = V_2838 ;
V_186:
if ( V_629 != V_2838 && V_2834 && F_145 ( V_2834 ) ) {
F_335 ( V_5 ) ;
F_487 ( V_2834 ) ;
}
F_694 () ;
return V_629 ;
}
static void F_700 ( struct V_1795 * V_12 )
{
struct V_365 * V_2834 = F_153 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_2834 ) ;
int V_75 ;
F_691 () ;
if ( ! F_145 ( V_2834 ) )
goto V_186;
F_241 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_84 ( V_5 , V_563 ) ;
V_75 = F_486 ( V_5 , true ) ;
if ( V_75 ) {
F_242 ( V_5 ) ;
F_185 ( V_2834 , L_175 ) ;
goto V_186;
}
F_693 ( V_2834 ) ;
F_483 ( V_5 ) ;
F_343 ( V_5 ) ;
F_242 ( V_5 ) ;
F_120 ( V_5 ) ;
V_186:
F_694 () ;
}
