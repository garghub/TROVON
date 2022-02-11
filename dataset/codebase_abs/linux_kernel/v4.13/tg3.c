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
static void F_73 ( struct V_4 * V_5 )
{
T_1 V_7 ;
struct V_211 * V_212 ;
V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
switch ( V_212 -> V_214 -> V_215 & V_212 -> V_214 -> V_216 ) {
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
if ( V_212 -> V_226 != V_227 ) {
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
static void F_75 ( struct V_4 * V_5 )
{
V_5 -> V_164 &= ~ V_165 ;
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
if ( F_23 ( V_5 , V_255 ) &&
F_30 ( V_5 ) == V_256 )
F_73 ( V_5 ) ;
}
static int F_76 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_161 ;
struct V_211 * V_212 ;
if ( F_23 ( V_5 , 5717_PLUS ) ) {
T_1 V_257 ;
V_5 -> V_160 = V_5 -> V_54 + 1 ;
if ( F_77 ( V_5 ) != V_258 )
V_257 = F_33 ( V_259 ) & V_260 ;
else
V_257 = F_33 ( V_261 ) &
V_262 ;
if ( V_257 )
V_5 -> V_160 += 7 ;
} else if ( F_23 ( V_5 , V_263 ) && F_23 ( V_5 , V_264 ) ) {
int V_184 ;
V_184 = F_78 ( V_5 -> V_12 ) ;
if ( V_184 < 0 )
return V_184 ;
V_5 -> V_160 = V_184 ;
} else
V_5 -> V_160 = V_265 ;
F_75 ( V_5 ) ;
if ( ! F_23 ( V_5 , V_266 ) || F_23 ( V_5 , V_255 ) )
return 0 ;
V_5 -> V_213 = F_79 () ;
if ( V_5 -> V_213 == NULL )
return - V_267 ;
V_5 -> V_213 -> V_268 = L_1 ;
snprintf ( V_5 -> V_213 -> V_269 , V_270 , L_2 ,
( V_5 -> V_12 -> V_271 -> V_272 << 8 ) | V_5 -> V_12 -> V_273 ) ;
V_5 -> V_213 -> V_208 = V_5 ;
V_5 -> V_213 -> V_274 = & V_5 -> V_12 -> V_111 ;
V_5 -> V_213 -> V_275 = & F_69 ;
V_5 -> V_213 -> V_276 = & F_72 ;
V_5 -> V_213 -> V_277 = ~ ( 1 << V_5 -> V_160 ) ;
if ( F_57 ( V_5 , V_204 , & V_161 ) || ( V_161 & V_278 ) )
F_68 ( V_5 ) ;
V_42 = F_80 ( V_5 -> V_213 ) ;
if ( V_42 ) {
F_81 ( & V_5 -> V_12 -> V_111 , L_3 , V_42 ) ;
F_82 ( V_5 -> V_213 ) ;
return V_42 ;
}
V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
if ( ! V_212 || ! V_212 -> V_214 ) {
F_81 ( & V_5 -> V_12 -> V_111 , L_4 ) ;
F_83 ( V_5 -> V_213 ) ;
F_82 ( V_5 -> V_213 ) ;
return - V_82 ;
}
switch ( V_212 -> V_214 -> V_215 & V_212 -> V_214 -> V_216 ) {
case V_279 :
V_212 -> V_226 = V_280 ;
V_212 -> V_281 |= V_282 ;
break;
case V_217 :
case V_218 :
V_212 -> V_281 |= V_283 |
V_284 |
V_285 |
V_282 ;
if ( F_23 ( V_5 , V_235 ) )
V_212 -> V_281 |= V_286 ;
if ( F_23 ( V_5 , V_244 ) )
V_212 -> V_281 |= V_287 ;
if ( F_23 ( V_5 , V_245 ) )
V_212 -> V_281 |= V_288 ;
case V_222 :
V_212 -> V_226 = V_227 ;
break;
case V_224 :
case V_220 :
V_212 -> V_226 = V_289 ;
V_212 -> V_281 |= V_282 ;
V_5 -> V_178 |= V_179 ;
break;
}
F_84 ( V_5 , V_255 ) ;
if ( F_30 ( V_5 ) == V_256 )
F_73 ( V_5 ) ;
return 0 ;
}
static void F_85 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_255 ) ) {
F_86 ( V_5 , V_255 ) ;
F_83 ( V_5 -> V_213 ) ;
F_82 ( V_5 -> V_213 ) ;
}
}
static inline void F_87 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_7 = F_33 ( V_290 ) ;
V_7 |= V_291 ;
F_31 ( V_290 , V_7 ) ;
V_5 -> V_292 = V_293 ;
}
static void F_88 ( struct V_4 * V_5 )
{
int V_42 ;
unsigned int V_294 ;
long V_295 ;
V_295 = ( long ) ( V_5 -> V_292 + 1 +
F_89 ( V_296 ) ) -
( long ) V_293 ;
if ( V_295 < 0 )
return;
V_294 = F_90 ( V_295 ) ;
if ( V_294 > V_296 )
V_294 = V_296 ;
V_294 = ( V_294 >> 3 ) + 1 ;
for ( V_42 = 0 ; V_42 < V_294 ; V_42 ++ ) {
if ( ! ( F_33 ( V_290 ) & V_291 ) )
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
if ( ! F_57 ( V_5 , V_297 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
* V_72 ++ = V_7 ;
V_7 = 0 ;
if ( ! F_57 ( V_5 , V_298 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_299 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
* V_72 ++ = V_7 ;
V_7 = 0 ;
if ( ! ( V_5 -> V_178 & V_300 ) ) {
if ( ! F_57 ( V_5 , V_180 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_301 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
}
* V_72 ++ = V_7 ;
if ( ! F_57 ( V_5 , V_302 , & V_161 ) )
V_7 = V_161 << 16 ;
else
V_7 = 0 ;
* V_72 ++ = V_7 ;
}
static void F_92 ( struct V_4 * V_5 )
{
T_1 V_72 [ 4 ] ;
if ( ! F_23 ( V_5 , 5780_CLASS ) || ! F_23 ( V_5 , V_303 ) )
return;
F_91 ( V_5 , V_72 ) ;
F_88 ( V_5 ) ;
F_29 ( V_5 , V_304 , V_305 ) ;
F_29 ( V_5 , V_306 , 14 ) ;
F_29 ( V_5 , V_307 + 0x0 , V_72 [ 0 ] ) ;
F_29 ( V_5 , V_307 + 0x4 , V_72 [ 1 ] ) ;
F_29 ( V_5 , V_307 + 0x8 , V_72 [ 2 ] ) ;
F_29 ( V_5 , V_307 + 0xc , V_72 [ 3 ] ) ;
F_87 ( V_5 ) ;
}
static void F_93 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_303 ) && ! F_23 ( V_5 , V_60 ) ) {
F_88 ( V_5 ) ;
F_29 ( V_5 , V_304 , V_308 ) ;
F_87 ( V_5 ) ;
F_88 ( V_5 ) ;
}
}
static void F_94 ( struct V_4 * V_5 , int V_95 )
{
F_29 ( V_5 , V_309 ,
V_310 ) ;
if ( F_23 ( V_5 , V_311 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_312 ,
V_313 ) ;
break;
case V_110 :
F_29 ( V_5 , V_312 ,
V_314 ) ;
break;
case V_315 :
F_29 ( V_5 , V_312 ,
V_316 ) ;
break;
default:
break;
}
}
}
static void F_95 ( struct V_4 * V_5 , int V_95 )
{
if ( F_23 ( V_5 , V_311 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_312 ,
V_317 ) ;
break;
case V_110 :
F_29 ( V_5 , V_312 ,
V_318 ) ;
break;
default:
break;
}
}
}
static void F_96 ( struct V_4 * V_5 , int V_95 )
{
if ( F_23 ( V_5 , V_303 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_312 ,
V_313 ) ;
break;
case V_110 :
F_29 ( V_5 , V_312 ,
V_314 ) ;
break;
case V_315 :
F_29 ( V_5 , V_312 ,
V_316 ) ;
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
if ( F_23 ( V_5 , V_319 ) )
return 0 ;
if ( F_23 ( V_5 , V_263 ) ) {
return 0 ;
}
if ( F_30 ( V_5 ) == V_36 ) {
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
if ( F_33 ( V_320 ) & V_321 )
return 0 ;
if ( F_36 ( V_5 -> V_12 ) )
return - V_82 ;
F_24 ( 100 ) ;
}
return - V_82 ;
}
for ( V_42 = 0 ; V_42 < 100000 ; V_42 ++ ) {
F_32 ( V_5 , V_309 , & V_7 ) ;
if ( V_7 == ~ V_310 )
break;
if ( F_36 ( V_5 -> V_12 ) ) {
if ( ! F_23 ( V_5 , V_319 ) ) {
F_84 ( V_5 , V_319 ) ;
F_98 ( V_5 -> V_111 , L_5 ) ;
}
break;
}
F_24 ( 10 ) ;
}
if ( V_42 >= 100000 && ! F_23 ( V_5 , V_319 ) ) {
F_84 ( V_5 , V_319 ) ;
F_98 ( V_5 -> V_111 , L_5 ) ;
}
if ( F_77 ( V_5 ) == V_322 ) {
F_99 ( 10 ) ;
}
return 0 ;
}
static void F_100 ( struct V_4 * V_5 )
{
if ( ! F_101 ( V_5 -> V_111 ) ) {
F_102 ( V_5 , V_323 , V_5 -> V_111 , L_6 ) ;
F_92 ( V_5 ) ;
} else if ( F_103 ( V_5 ) ) {
F_98 ( V_5 -> V_111 , L_7 ,
( V_5 -> V_324 . V_325 == V_326 ?
1000 :
( V_5 -> V_324 . V_325 == V_327 ?
100 : 10 ) ) ,
( V_5 -> V_324 . V_328 == V_329 ?
L_8 : L_9 ) ) ;
F_98 ( V_5 -> V_111 , L_10 ,
( V_5 -> V_324 . V_330 & V_331 ) ?
L_11 : L_12 ,
( V_5 -> V_324 . V_330 & V_332 ) ?
L_11 : L_12 ) ;
if ( V_5 -> V_178 & V_333 )
F_98 ( V_5 -> V_111 , L_13 ,
V_5 -> V_334 ? L_14 : L_15 ) ;
F_92 ( V_5 ) ;
}
V_5 -> V_335 = F_101 ( V_5 -> V_111 ) ;
}
static T_1 F_104 ( T_1 V_336 )
{
T_1 V_337 = 0 ;
if ( V_336 & V_338 ) {
V_337 |= V_332 ;
if ( ! ( V_336 & V_339 ) )
V_337 |= V_331 ;
} else if ( V_336 & V_339 )
V_337 |= V_331 ;
return V_337 ;
}
static T_3 F_105 ( T_4 V_340 )
{
T_3 V_341 ;
if ( ( V_340 & V_331 ) && ( V_340 & V_332 ) )
V_341 = V_342 ;
else if ( V_340 & V_331 )
V_341 = V_343 ;
else if ( V_340 & V_332 )
V_341 = V_342 | V_343 ;
else
V_341 = 0 ;
return V_341 ;
}
static T_1 F_106 ( T_1 V_336 )
{
T_1 V_337 = 0 ;
if ( V_336 & V_342 ) {
V_337 |= V_332 ;
if ( ! ( V_336 & V_343 ) )
V_337 |= V_331 ;
} else if ( V_336 & V_343 )
V_337 |= V_331 ;
return V_337 ;
}
static T_4 F_107 ( T_3 V_344 , T_3 V_345 )
{
T_4 V_346 = 0 ;
if ( V_344 & V_345 & V_342 ) {
V_346 = V_331 | V_332 ;
} else if ( V_344 & V_345 & V_343 ) {
if ( V_344 & V_342 )
V_346 = V_332 ;
if ( V_345 & V_342 )
V_346 = V_331 ;
}
return V_346 ;
}
static void F_108 ( struct V_4 * V_5 , T_1 V_344 , T_1 V_345 )
{
T_4 V_347 ;
T_4 V_337 = 0 ;
T_1 V_348 = V_5 -> V_349 ;
T_1 V_350 = V_5 -> V_351 ;
if ( F_23 ( V_5 , V_266 ) )
V_347 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) -> V_347 ;
else
V_347 = V_5 -> V_324 . V_347 ;
if ( V_347 == V_352 && F_23 ( V_5 , V_353 ) ) {
if ( V_5 -> V_178 & V_354 )
V_337 = F_107 ( V_344 , V_345 ) ;
else
V_337 = F_109 ( V_344 , V_345 ) ;
} else
V_337 = V_5 -> V_324 . V_337 ;
V_5 -> V_324 . V_330 = V_337 ;
if ( V_337 & V_332 )
V_5 -> V_349 |= V_355 ;
else
V_5 -> V_349 &= ~ V_355 ;
if ( V_348 != V_5 -> V_349 )
F_31 ( V_356 , V_5 -> V_349 ) ;
if ( V_337 & V_331 )
V_5 -> V_351 |= V_357 ;
else
V_5 -> V_351 &= ~ V_357 ;
if ( V_350 != V_5 -> V_351 )
F_31 ( V_358 , V_5 -> V_351 ) ;
}
static void F_110 ( struct V_359 * V_111 )
{
T_4 V_360 , V_361 = 0 ;
T_1 V_362 , V_363 , V_364 ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_211 * V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
F_70 ( & V_5 -> V_209 ) ;
V_362 = V_5 -> V_362 & ~ ( V_365 |
V_366 ) ;
V_360 = V_5 -> V_324 . V_330 ;
if ( V_212 -> V_323 ) {
V_363 = 0 ;
V_364 = 0 ;
if ( V_212 -> V_367 == V_327 || V_212 -> V_367 == V_368 )
V_362 |= V_369 ;
else if ( V_212 -> V_367 == V_326 ||
F_30 ( V_5 ) != V_256 )
V_362 |= V_370 ;
else
V_362 |= V_369 ;
if ( V_212 -> V_371 == V_372 )
V_362 |= V_366 ;
else {
V_363 = F_112 (
V_5 -> V_324 . V_337 ) ;
if ( V_212 -> V_373 )
V_364 = V_374 ;
if ( V_212 -> V_375 )
V_364 |= V_376 ;
}
F_108 ( V_5 , V_363 , V_364 ) ;
} else
V_362 |= V_370 ;
if ( V_362 != V_5 -> V_362 ) {
V_5 -> V_362 = V_362 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
}
if ( F_30 ( V_5 ) == V_256 ) {
if ( V_212 -> V_367 == V_368 )
F_46 ( V_378 ,
V_379 |
V_380 ) ;
else
F_46 ( V_378 , V_380 ) ;
}
if ( V_212 -> V_367 == V_326 && V_212 -> V_371 == V_372 )
F_46 ( V_381 ,
( ( 2 << V_382 ) |
( 6 << V_383 ) |
( 0xff << V_384 ) ) ) ;
else
F_46 ( V_381 ,
( ( 2 << V_382 ) |
( 6 << V_383 ) |
( 32 << V_384 ) ) ) ;
if ( V_212 -> V_323 != V_5 -> V_385 ||
V_212 -> V_367 != V_5 -> V_324 . V_325 ||
V_212 -> V_371 != V_5 -> V_324 . V_328 ||
V_360 != V_5 -> V_324 . V_330 )
V_361 = 1 ;
V_5 -> V_385 = V_212 -> V_323 ;
V_5 -> V_324 . V_325 = V_212 -> V_367 ;
V_5 -> V_324 . V_328 = V_212 -> V_371 ;
F_71 ( & V_5 -> V_209 ) ;
if ( V_361 )
F_100 ( V_5 ) ;
}
static int F_113 ( struct V_4 * V_5 )
{
struct V_211 * V_212 ;
if ( V_5 -> V_178 & V_386 )
return 0 ;
F_68 ( V_5 ) ;
V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
V_212 = F_114 ( V_5 -> V_111 , F_115 ( V_212 ) ,
F_110 , V_212 -> V_226 ) ;
if ( F_116 ( V_212 ) ) {
F_117 ( & V_5 -> V_12 -> V_111 , L_16 ) ;
return F_118 ( V_212 ) ;
}
switch ( V_212 -> V_226 ) {
case V_280 :
case V_227 :
if ( ! ( V_5 -> V_178 & V_387 ) ) {
V_212 -> V_388 &= ( V_389 |
V_390 |
V_391 ) ;
break;
}
case V_289 :
V_212 -> V_388 &= ( V_392 |
V_390 |
V_391 ) ;
break;
default:
F_119 ( F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ) ;
return - V_64 ;
}
V_5 -> V_178 |= V_386 ;
V_212 -> V_393 = V_212 -> V_388 ;
F_120 ( V_212 ) ;
return 0 ;
}
static void F_121 ( struct V_4 * V_5 )
{
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_386 ) )
return;
V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
if ( V_5 -> V_178 & V_394 ) {
V_5 -> V_178 &= ~ V_394 ;
V_212 -> V_367 = V_5 -> V_324 . V_367 ;
V_212 -> V_371 = V_5 -> V_324 . V_371 ;
V_212 -> V_347 = V_5 -> V_324 . V_347 ;
V_212 -> V_393 = V_5 -> V_324 . V_393 ;
}
F_122 ( V_212 ) ;
F_123 ( V_212 ) ;
}
static void F_124 ( struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_178 & V_386 ) )
return;
F_125 ( F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ) ;
}
static void F_126 ( struct V_4 * V_5 )
{
if ( V_5 -> V_178 & V_386 ) {
F_119 ( F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ) ;
V_5 -> V_178 &= ~ V_386 ;
}
}
static int F_127 ( struct V_4 * V_5 )
{
int V_75 ;
T_1 V_7 ;
if ( V_5 -> V_178 & V_179 )
return 0 ;
if ( ( V_5 -> V_215 & V_395 ) == V_396 ) {
V_75 = F_65 ( V_5 ,
V_196 ,
V_397 |
0x4c20 ) ;
goto V_186;
}
V_75 = F_64 ( V_5 ,
V_196 , & V_7 ) ;
if ( V_75 )
return V_75 ;
V_7 |= V_397 ;
V_75 = F_65 ( V_5 ,
V_196 , V_7 ) ;
V_186:
return V_75 ;
}
static void F_128 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_398 ;
if ( ! F_57 ( V_5 , V_399 , & V_398 ) ) {
T_1 V_400 ;
F_59 ( V_5 , V_399 ,
V_398 | V_401 ) ;
if ( ! F_57 ( V_5 , V_402 , & V_400 ) ) {
if ( V_195 )
V_400 |= V_403 ;
else
V_400 &= ~ V_403 ;
F_59 ( V_5 , V_402 , V_400 ) ;
}
F_59 ( V_5 , V_399 , V_398 ) ;
}
}
static void F_129 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_161 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
( F_23 ( V_5 , 5717_PLUS ) &&
( V_5 -> V_178 & V_300 ) ) )
return;
if ( V_5 -> V_178 & V_179 ) {
F_128 ( V_5 , V_195 ) ;
return;
}
V_161 = V_404 |
V_405 |
V_406 |
V_407 ;
if ( F_30 ( V_5 ) != V_408 || ! V_195 )
V_161 |= V_409 ;
F_67 ( V_5 , V_410 , V_161 ) ;
V_161 = V_411 ;
if ( V_195 )
V_161 |= V_412 ;
F_67 ( V_5 , V_413 , V_161 ) ;
}
static void F_130 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_400 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
( V_5 -> V_178 & V_354 ) )
return;
if ( V_5 -> V_178 & V_179 ) {
T_1 V_414 ;
if ( ! F_57 ( V_5 , V_399 , & V_414 ) ) {
T_1 V_161 = V_415 ;
F_59 ( V_5 , V_399 ,
V_414 | V_401 ) ;
if ( ! F_57 ( V_5 , V_161 , & V_400 ) ) {
if ( V_195 )
V_400 |= V_416 ;
else
V_400 &= ~ V_416 ;
F_59 ( V_5 , V_161 , V_400 ) ;
}
F_59 ( V_5 , V_399 , V_414 ) ;
}
} else {
int V_56 ;
V_56 = F_64 ( V_5 ,
V_192 , & V_400 ) ;
if ( ! V_56 ) {
if ( V_195 )
V_400 |= V_417 ;
else
V_400 &= ~ V_417 ;
F_65 ( V_5 ,
V_192 , V_400 ) ;
}
}
}
static void F_131 ( struct V_4 * V_5 )
{
int V_56 ;
T_1 V_7 ;
if ( V_5 -> V_178 & V_418 )
return;
V_56 = F_64 ( V_5 , V_192 , & V_7 ) ;
if ( ! V_56 )
F_65 ( V_5 , V_192 ,
V_7 | V_419 ) ;
}
static void F_132 ( struct V_4 * V_5 )
{
T_1 V_420 , V_400 ;
if ( ! V_5 -> V_421 )
return;
V_420 = V_5 -> V_421 ;
if ( F_66 ( V_5 , true ) )
return;
V_400 = ( ( V_420 & V_422 ) >> V_423 ) ;
V_400 |= V_424 ;
F_63 ( V_5 , V_425 , V_400 ) ;
V_400 = ( ( V_420 & V_426 ) >> V_427 ) |
( ( V_420 & V_428 ) >> V_429 ) ;
F_63 ( V_5 , V_430 , V_400 ) ;
V_400 = ( ( V_420 & V_431 ) >> V_432 ) ;
V_400 |= V_433 ;
F_63 ( V_5 , V_434 , V_400 ) ;
V_400 = ( ( V_420 & V_435 ) >> V_436 ) ;
F_63 ( V_5 , V_437 , V_400 ) ;
V_400 = ( ( V_420 & V_438 ) >> V_439 ) ;
F_63 ( V_5 , V_440 , V_400 ) ;
V_400 = ( ( V_420 & V_441 ) >> V_442 ) |
( ( V_420 & V_443 ) >> V_444 ) ;
F_63 ( V_5 , V_445 , V_400 ) ;
F_66 ( V_5 , false ) ;
}
static void F_133 ( struct V_4 * V_5 , struct V_446 * V_447 )
{
T_1 V_7 ;
struct V_446 * V_448 = & V_5 -> V_447 ;
if ( ! ( V_5 -> V_178 & V_333 ) )
return;
if ( V_447 )
V_448 = V_447 ;
if ( F_61 ( V_5 , V_449 , V_450 , & V_7 ) )
return;
if ( V_7 == V_451 ||
V_7 == V_452 ) {
V_448 -> V_453 = 1 ;
} else
V_448 -> V_453 = 0 ;
if ( F_61 ( V_5 , V_449 , V_454 , & V_7 ) )
return;
V_448 -> V_455 = F_134 ( V_7 ) ;
if ( F_61 ( V_5 , V_449 , V_456 , & V_7 ) )
return;
V_448 -> V_457 = ! ! V_7 ;
V_448 -> V_458 = F_134 ( V_7 ) ;
V_7 = F_33 ( V_459 ) ;
V_448 -> V_460 = ! ! ( V_7 & V_461 ) ;
V_448 -> V_462 = F_33 ( V_463 ) & 0xffff ;
}
static void F_135 ( struct V_4 * V_5 , bool V_464 )
{
T_1 V_7 ;
if ( ! ( V_5 -> V_178 & V_333 ) )
return;
V_5 -> V_334 = 0 ;
if ( V_5 -> V_324 . V_347 == V_352 &&
V_464 &&
V_5 -> V_324 . V_328 == V_329 &&
( V_5 -> V_324 . V_325 == V_327 ||
V_5 -> V_324 . V_325 == V_326 ) ) {
T_1 V_465 ;
if ( V_5 -> V_324 . V_325 == V_326 )
V_465 = V_466 ;
else
V_465 = V_467 ;
F_46 ( V_468 , V_465 ) ;
F_133 ( V_5 , NULL ) ;
if ( V_5 -> V_447 . V_453 )
V_5 -> V_334 = 2 ;
}
if ( ! V_5 -> V_334 ) {
if ( V_464 &&
! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , V_469 , 0x0000 ) ;
F_66 ( V_5 , false ) ;
}
V_7 = F_33 ( V_459 ) ;
F_46 ( V_459 , V_7 & ~ V_470 ) ;
}
}
static void F_136 ( struct V_4 * V_5 )
{
T_1 V_7 ;
if ( V_5 -> V_324 . V_325 == V_326 &&
( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 ||
F_23 ( V_5 , 57765_CLASS ) ) &&
! F_66 ( V_5 , true ) ) {
V_7 = V_473 |
V_474 ;
F_63 ( V_5 , V_469 , V_7 ) ;
F_66 ( V_5 , false ) ;
}
V_7 = F_33 ( V_459 ) ;
F_46 ( V_459 , V_7 | V_470 ) ;
}
static int F_137 ( struct V_4 * V_5 )
{
int V_202 = 100 ;
while ( V_202 -- ) {
T_1 V_475 ;
if ( ! F_57 ( V_5 , V_476 , & V_475 ) ) {
if ( ( V_475 & 0x1000 ) == 0 )
break;
}
}
if ( V_202 < 0 )
return - V_67 ;
return 0 ;
}
static int F_138 ( struct V_4 * V_5 , int * V_477 )
{
static const T_1 V_478 [ 4 ] [ 6 ] = {
{ 0x00005555 , 0x00000005 , 0x00002aaa , 0x0000000a , 0x00003456 , 0x00000003 } ,
{ 0x00002aaa , 0x0000000a , 0x00003333 , 0x00000003 , 0x0000789a , 0x00000005 } ,
{ 0x00005a5a , 0x00000005 , 0x00002a6a , 0x0000000a , 0x00001bcd , 0x00000003 } ,
{ 0x00002a5a , 0x0000000a , 0x000033c3 , 0x00000003 , 0x00002ef1 , 0x00000005 }
} ;
int V_479 ;
for ( V_479 = 0 ; V_479 < 4 ; V_479 ++ ) {
int V_42 ;
F_59 ( V_5 , V_189 ,
( V_479 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_476 , 0x0002 ) ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ )
F_59 ( V_5 , V_190 ,
V_478 [ V_479 ] [ V_42 ] ) ;
F_59 ( V_5 , V_476 , 0x0202 ) ;
if ( F_137 ( V_5 ) ) {
* V_477 = 1 ;
return - V_67 ;
}
F_59 ( V_5 , V_189 ,
( V_479 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_476 , 0x0082 ) ;
if ( F_137 ( V_5 ) ) {
* V_477 = 1 ;
return - V_67 ;
}
F_59 ( V_5 , V_476 , 0x0802 ) ;
if ( F_137 ( V_5 ) ) {
* V_477 = 1 ;
return - V_67 ;
}
for ( V_42 = 0 ; V_42 < 6 ; V_42 += 2 ) {
T_1 V_480 , V_481 ;
if ( F_57 ( V_5 , V_190 , & V_480 ) ||
F_57 ( V_5 , V_190 , & V_481 ) ||
F_137 ( V_5 ) ) {
* V_477 = 1 ;
return - V_67 ;
}
V_480 &= 0x7fff ;
V_481 &= 0x000f ;
if ( V_480 != V_478 [ V_479 ] [ V_42 ] ||
V_481 != V_478 [ V_479 ] [ V_42 + 1 ] ) {
F_59 ( V_5 , V_189 , 0x000b ) ;
F_59 ( V_5 , V_190 , 0x4001 ) ;
F_59 ( V_5 , V_190 , 0x4005 ) ;
return - V_67 ;
}
}
}
return 0 ;
}
static int F_139 ( struct V_4 * V_5 )
{
int V_479 ;
for ( V_479 = 0 ; V_479 < 4 ; V_479 ++ ) {
int V_42 ;
F_59 ( V_5 , V_189 ,
( V_479 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_476 , 0x0002 ) ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ )
F_59 ( V_5 , V_190 , 0x000 ) ;
F_59 ( V_5 , V_476 , 0x0202 ) ;
if ( F_137 ( V_5 ) )
return - V_67 ;
}
return 0 ;
}
static int F_140 ( struct V_4 * V_5 )
{
T_1 V_482 , V_483 ;
int V_484 , V_485 , V_75 ;
V_484 = 10 ;
V_485 = 1 ;
do {
if ( V_485 ) {
V_75 = F_68 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_485 = 0 ;
}
if ( F_57 ( V_5 , V_486 , & V_482 ) )
continue;
V_482 |= 0x3000 ;
F_59 ( V_5 , V_486 , V_482 ) ;
F_59 ( V_5 , V_204 ,
V_487 | V_488 ) ;
if ( F_57 ( V_5 , V_180 , & V_483 ) )
continue;
F_59 ( V_5 , V_180 ,
V_489 | V_490 ) ;
V_75 = F_66 ( V_5 , true ) ;
if ( V_75 )
return V_75 ;
F_63 ( V_5 , 0x8005 , 0x0800 ) ;
V_75 = F_138 ( V_5 , & V_485 ) ;
if ( ! V_75 )
break;
} while ( -- V_484 );
V_75 = F_139 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_63 ( V_5 , 0x8005 , 0x0000 ) ;
F_59 ( V_5 , V_189 , 0x8200 ) ;
F_59 ( V_5 , V_476 , 0x0000 ) ;
F_66 ( V_5 , false ) ;
F_59 ( V_5 , V_180 , V_483 ) ;
V_75 = F_57 ( V_5 , V_486 , & V_482 ) ;
if ( V_75 )
return V_75 ;
V_482 &= ~ 0x3000 ;
F_59 ( V_5 , V_486 , V_482 ) ;
return 0 ;
}
static void F_141 ( struct V_4 * V_5 )
{
F_142 ( V_5 -> V_111 ) ;
V_5 -> V_335 = false ;
}
static void F_143 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_303 ) )
F_144 ( V_5 -> V_111 ,
L_17 ) ;
}
static int F_145 ( struct V_4 * V_5 )
{
T_1 V_7 , V_491 ;
int V_75 ;
if ( F_30 ( V_5 ) == V_36 ) {
V_7 = F_33 ( V_492 ) ;
F_31 ( V_492 , V_7 & ~ V_493 ) ;
F_24 ( 40 ) ;
}
V_75 = F_57 ( V_5 , V_297 , & V_7 ) ;
V_75 |= F_57 ( V_5 , V_297 , & V_7 ) ;
if ( V_75 != 0 )
return - V_67 ;
if ( F_146 ( V_5 -> V_111 ) && V_5 -> V_335 ) {
F_142 ( V_5 -> V_111 ) ;
F_100 ( V_5 ) ;
}
if ( F_30 ( V_5 ) == V_494 ||
F_30 ( V_5 ) == V_495 ||
F_30 ( V_5 ) == V_496 ) {
V_75 = F_140 ( V_5 ) ;
if ( V_75 )
return V_75 ;
goto V_497;
}
V_491 = 0 ;
if ( F_30 ( V_5 ) == V_408 &&
F_147 ( V_5 ) != V_498 ) {
V_491 = F_33 ( V_499 ) ;
if ( V_491 & V_500 )
F_46 ( V_499 ,
V_491 & ~ V_500 ) ;
}
V_75 = F_68 ( V_5 ) ;
if ( V_75 )
return V_75 ;
if ( V_491 & V_500 ) {
V_7 = V_501 | V_502 ;
F_63 ( V_5 , V_503 , V_7 ) ;
F_46 ( V_499 , V_491 ) ;
}
if ( F_147 ( V_5 ) == V_498 ||
F_147 ( V_5 ) == V_504 ) {
V_7 = F_33 ( V_505 ) ;
if ( ( V_7 & V_506 ) ==
V_507 ) {
V_7 &= ~ V_506 ;
F_24 ( 40 ) ;
F_31 ( V_505 , V_7 ) ;
}
}
if ( F_23 ( V_5 , 5717_PLUS ) &&
( V_5 -> V_178 & V_300 ) )
return 0 ;
F_132 ( V_5 ) ;
if ( V_5 -> V_178 & V_508 )
F_129 ( V_5 , true ) ;
else
F_129 ( V_5 , false ) ;
V_497:
if ( ( V_5 -> V_178 & V_509 ) &&
! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , 0x201f , 0x2aaa ) ;
F_63 ( V_5 , 0x000a , 0x0323 ) ;
F_66 ( V_5 , false ) ;
}
if ( V_5 -> V_178 & V_510 ) {
F_59 ( V_5 , V_199 , 0x8d68 ) ;
F_59 ( V_5 , V_199 , 0x8d68 ) ;
}
if ( V_5 -> V_178 & V_511 ) {
if ( ! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , 0x000a , 0x310b ) ;
F_63 ( V_5 , 0x201f , 0x9506 ) ;
F_63 ( V_5 , 0x401f , 0x14e2 ) ;
F_66 ( V_5 , false ) ;
}
} else if ( V_5 -> V_178 & V_512 ) {
if ( ! F_66 ( V_5 , true ) ) {
F_59 ( V_5 , V_189 , 0x000a ) ;
if ( V_5 -> V_178 & V_513 ) {
F_59 ( V_5 , V_190 , 0x110b ) ;
F_59 ( V_5 , V_514 ,
V_515 | 0x4 ) ;
} else
F_59 ( V_5 , V_190 , 0x010b ) ;
F_66 ( V_5 , false ) ;
}
}
if ( ( V_5 -> V_215 & V_395 ) == V_396 ) {
F_65 ( V_5 , V_196 , 0x4c20 ) ;
} else if ( F_23 ( V_5 , V_516 ) ) {
V_75 = F_64 ( V_5 ,
V_196 , & V_7 ) ;
if ( ! V_75 )
F_65 ( V_5 , V_196 ,
V_7 | V_517 ) ;
}
if ( F_23 ( V_5 , V_516 ) ) {
if ( ! F_57 ( V_5 , V_486 , & V_7 ) )
F_59 ( V_5 , V_486 ,
V_7 | V_518 ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
F_59 ( V_5 , V_519 , 0x12 ) ;
}
if ( F_77 ( V_5 ) == V_520 )
F_63 ( V_5 , 0xffb , 0x4000 ) ;
F_130 ( V_5 , true ) ;
F_131 ( V_5 ) ;
return 0 ;
}
static inline T_1 F_148 ( struct V_4 * V_5 , T_1 V_521 )
{
T_1 V_57 , V_522 ;
if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 )
V_57 = F_12 ( V_5 , V_523 ) ;
else
V_57 = F_33 ( V_524 ) ;
V_522 = V_525 + 4 * V_5 -> V_54 ;
V_57 &= ~ ( V_526 << V_522 ) ;
V_57 |= ( V_521 << V_522 ) ;
if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 )
F_11 ( V_5 , V_523 , V_57 ) ;
else
F_46 ( V_524 , V_57 ) ;
return V_57 >> V_525 ;
}
static inline int F_149 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_527 ) )
return 0 ;
if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 ) {
if ( F_35 ( V_5 , V_49 ) )
return - V_210 ;
F_148 ( V_5 , V_529 ) ;
F_55 ( V_136 , V_5 -> V_22 ,
V_530 ) ;
F_37 ( V_5 , V_49 ) ;
} else {
F_55 ( V_136 , V_5 -> V_22 ,
V_530 ) ;
}
return 0 ;
}
static void F_150 ( struct V_4 * V_5 )
{
T_1 V_22 ;
if ( ! F_23 ( V_5 , V_527 ) ||
F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 )
return;
V_22 = V_5 -> V_22 | V_533 ;
F_55 ( V_136 ,
V_22 | V_534 ,
V_530 ) ;
F_55 ( V_136 ,
V_22 ,
V_530 ) ;
F_55 ( V_136 ,
V_22 | V_534 ,
V_530 ) ;
}
static void F_151 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_527 ) )
return;
if ( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 ) {
F_55 ( V_136 , V_5 -> V_22 |
( V_535 |
V_533 |
V_536 |
V_537 |
V_534 ) ,
V_530 ) ;
} else if ( V_5 -> V_12 -> V_538 == V_539 ||
V_5 -> V_12 -> V_538 == V_540 ) {
T_1 V_22 = V_535 |
V_533 |
V_536 |
V_537 |
V_534 |
V_5 -> V_22 ;
F_55 ( V_136 , V_22 ,
V_530 ) ;
V_22 |= V_541 ;
F_55 ( V_136 , V_22 ,
V_530 ) ;
V_22 &= ~ V_537 ;
F_55 ( V_136 , V_22 ,
V_530 ) ;
} else {
T_1 V_542 ;
T_1 V_22 = 0 ;
if ( F_30 ( V_5 ) == V_543 ) {
V_22 |= V_544 ;
F_55 ( V_136 , V_5 -> V_22 |
V_22 ,
V_530 ) ;
}
V_542 = V_5 -> V_545 &
V_546 ;
V_22 |= V_535 |
V_533 |
V_536 |
V_534 |
V_541 ;
if ( V_542 ) {
V_22 &= ~ ( V_536 |
V_541 ) ;
}
F_55 ( V_136 ,
V_5 -> V_22 | V_22 ,
V_530 ) ;
V_22 |= V_537 ;
F_55 ( V_136 ,
V_5 -> V_22 | V_22 ,
V_530 ) ;
if ( ! V_542 ) {
V_22 &= ~ V_541 ;
F_55 ( V_136 ,
V_5 -> V_22 | V_22 ,
V_530 ) ;
}
}
}
static void F_152 ( struct V_4 * V_5 , bool V_547 )
{
T_1 V_548 = 0 ;
if ( F_35 ( V_5 , V_49 ) )
return;
if ( F_23 ( V_5 , V_303 ) || F_23 ( V_5 , V_60 ) || V_547 )
V_548 = V_549 ;
V_548 = F_148 ( V_5 , V_548 ) ;
if ( V_548 & V_550 )
goto V_186;
if ( V_548 & V_551 )
F_151 ( V_5 ) ;
else
F_150 ( V_5 ) ;
V_186:
F_37 ( V_5 , V_49 ) ;
}
static void F_153 ( struct V_4 * V_5 , bool V_552 )
{
bool V_553 = false ;
if ( ! F_23 ( V_5 , V_527 ) || F_23 ( V_5 , 57765_CLASS ) )
return;
if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 ) {
F_152 ( V_5 , V_552 ?
F_23 ( V_5 , V_112 ) != 0 : 0 ) ;
return;
}
if ( V_5 -> V_554 && V_5 -> V_554 != V_5 -> V_12 ) {
struct V_359 * V_555 ;
V_555 = F_154 ( V_5 -> V_554 ) ;
if ( V_555 ) {
struct V_4 * V_556 = F_111 ( V_555 ) ;
if ( F_23 ( V_556 , V_557 ) )
return;
if ( ( V_552 && F_23 ( V_556 , V_112 ) ) ||
F_23 ( V_556 , V_303 ) )
V_553 = true ;
}
}
if ( ( V_552 && F_23 ( V_5 , V_112 ) ) ||
F_23 ( V_5 , V_303 ) )
V_553 = true ;
if ( V_553 )
F_151 ( V_5 ) ;
else
F_150 ( V_5 ) ;
}
static int F_155 ( struct V_4 * V_5 , T_1 V_367 )
{
if ( V_5 -> V_558 == V_559 )
return 1 ;
else if ( ( V_5 -> V_215 & V_395 ) == V_560 ) {
if ( V_367 != V_368 )
return 1 ;
} else if ( V_367 == V_368 )
return 1 ;
return 0 ;
}
static bool F_156 ( struct V_4 * V_5 )
{
switch ( F_30 ( V_5 ) ) {
case V_531 :
case V_495 :
return true ;
case V_561 :
if ( V_5 -> V_178 & V_300 )
return true ;
return false ;
case V_471 :
if ( ! V_5 -> V_54 )
return true ;
return false ;
case V_472 :
case V_528 :
if ( ( V_5 -> V_178 & V_562 ) &&
! V_5 -> V_54 )
return true ;
return false ;
}
return false ;
}
static bool F_157 ( struct V_4 * V_5 )
{
switch ( F_30 ( V_5 ) ) {
case V_472 :
case V_528 :
if ( ( V_5 -> V_178 & V_300 ) &&
! V_5 -> V_54 )
return true ;
return false ;
}
return false ;
}
static void F_158 ( struct V_4 * V_5 , bool V_563 )
{
T_1 V_7 ;
if ( V_5 -> V_178 & V_564 )
return;
if ( V_5 -> V_178 & V_562 ) {
if ( F_30 ( V_5 ) == V_495 ) {
T_1 V_565 = F_33 ( V_566 ) ;
T_1 V_567 = F_33 ( V_568 ) ;
V_565 |=
V_569 | V_570 ;
F_46 ( V_566 , V_565 ) ;
F_46 ( V_568 , V_567 | ( 1 << 15 ) ) ;
}
return;
}
if ( F_30 ( V_5 ) == V_36 ) {
F_68 ( V_5 ) ;
V_7 = F_33 ( V_492 ) ;
F_31 ( V_492 , V_7 | V_493 ) ;
F_24 ( 40 ) ;
return;
} else if ( V_5 -> V_178 & V_179 ) {
T_1 V_398 ;
if ( ! F_57 ( V_5 , V_399 , & V_398 ) ) {
T_1 V_400 ;
F_59 ( V_5 , V_298 , 0 ) ;
F_59 ( V_5 , V_204 ,
V_571 | V_572 ) ;
F_59 ( V_5 , V_399 ,
V_398 | V_401 ) ;
if ( ! F_57 ( V_5 , V_573 , & V_400 ) ) {
V_400 |= V_574 ;
F_59 ( V_5 ,
V_573 ,
V_400 ) ;
}
F_59 ( V_5 , V_399 , V_398 ) ;
}
return;
} else if ( V_563 ) {
if ( ! F_157 ( V_5 ) )
F_59 ( V_5 , V_486 ,
V_575 ) ;
V_7 = V_576 |
V_577 |
V_578 ;
F_65 ( V_5 , V_579 , V_7 ) ;
}
if ( F_156 ( V_5 ) )
return;
if ( F_147 ( V_5 ) == V_498 ||
F_147 ( V_5 ) == V_504 ) {
V_7 = F_33 ( V_505 ) ;
V_7 &= ~ V_506 ;
V_7 |= V_507 ;
F_31 ( V_505 , V_7 ) ;
}
F_59 ( V_5 , V_204 , V_278 ) ;
}
static int F_159 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_580 ) ) {
int V_42 ;
if ( V_5 -> V_581 == 0 ) {
F_46 ( V_582 , V_583 ) ;
for ( V_42 = 0 ; V_42 < 8000 ; V_42 ++ ) {
if ( F_33 ( V_582 ) & V_584 )
break;
F_24 ( 20 ) ;
}
if ( V_42 == 8000 ) {
F_46 ( V_582 , V_585 ) ;
return - V_82 ;
}
}
V_5 -> V_581 ++ ;
}
return 0 ;
}
static void F_160 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_580 ) ) {
if ( V_5 -> V_581 > 0 )
V_5 -> V_581 -- ;
if ( V_5 -> V_581 == 0 )
F_31 ( V_582 , V_585 ) ;
}
}
static void F_161 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_586 ) ) {
T_1 V_587 = F_33 ( V_588 ) ;
F_46 ( V_588 , V_587 | V_589 ) ;
}
}
static void F_162 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_586 ) ) {
T_1 V_587 = F_33 ( V_588 ) ;
F_46 ( V_588 , V_587 & ~ V_589 ) ;
}
}
static int F_163 ( struct V_4 * V_5 ,
T_1 V_590 , T_1 * V_7 )
{
T_1 V_591 ;
int V_42 ;
if ( V_590 > V_592 || ( V_590 % 4 ) != 0 )
return - V_64 ;
V_591 = F_33 ( V_593 ) & ~ ( V_592 |
V_594 |
V_595 ) ;
F_46 ( V_593 ,
V_591 |
( 0 << V_596 ) |
( ( V_590 << V_597 ) &
V_592 ) |
V_595 | V_598 ) ;
for ( V_42 = 0 ; V_42 < 1000 ; V_42 ++ ) {
V_591 = F_33 ( V_593 ) ;
if ( V_591 & V_599 )
break;
F_164 ( 1 ) ;
}
if ( ! ( V_591 & V_599 ) )
return - V_67 ;
V_591 = F_33 ( V_600 ) ;
* V_7 = F_165 ( V_591 ) ;
return 0 ;
}
static int F_166 ( struct V_4 * V_5 , T_1 V_601 )
{
int V_42 ;
F_46 ( V_602 , V_601 ) ;
for ( V_42 = 0 ; V_42 < V_603 ; V_42 ++ ) {
F_167 ( 10 , 40 ) ;
if ( F_33 ( V_602 ) & V_604 ) {
F_24 ( 10 ) ;
break;
}
}
if ( V_42 == V_603 )
return - V_67 ;
return 0 ;
}
static T_1 F_168 ( struct V_4 * V_5 , T_1 V_184 )
{
if ( F_23 ( V_5 , V_580 ) &&
F_23 ( V_5 , V_605 ) &&
F_23 ( V_5 , V_606 ) &&
! F_23 ( V_5 , V_607 ) &&
( V_5 -> V_608 == V_609 ) )
V_184 = ( ( V_184 / V_5 -> V_610 ) <<
V_611 ) +
( V_184 % V_5 -> V_610 ) ;
return V_184 ;
}
static T_1 F_169 ( struct V_4 * V_5 , T_1 V_184 )
{
if ( F_23 ( V_5 , V_580 ) &&
F_23 ( V_5 , V_605 ) &&
F_23 ( V_5 , V_606 ) &&
! F_23 ( V_5 , V_607 ) &&
( V_5 -> V_608 == V_609 ) )
V_184 = ( ( V_184 >> V_611 ) *
V_5 -> V_610 ) +
( V_184 & ( ( 1 << V_611 ) - 1 ) ) ;
return V_184 ;
}
static int F_170 ( struct V_4 * V_5 , T_1 V_590 , T_1 * V_7 )
{
int V_56 ;
if ( ! F_23 ( V_5 , V_580 ) )
return F_163 ( V_5 , V_590 , V_7 ) ;
V_590 = F_168 ( V_5 , V_590 ) ;
if ( V_590 > V_612 )
return - V_64 ;
V_56 = F_159 ( V_5 ) ;
if ( V_56 )
return V_56 ;
F_161 ( V_5 ) ;
F_46 ( V_613 , V_590 ) ;
V_56 = F_166 ( V_5 , V_614 | V_615 |
V_616 | V_617 | V_604 ) ;
if ( V_56 == 0 )
* V_7 = F_33 ( V_618 ) ;
F_162 ( V_5 ) ;
F_160 ( V_5 ) ;
return V_56 ;
}
static int F_171 ( struct V_4 * V_5 , T_1 V_590 , T_5 * V_7 )
{
T_1 V_619 ;
int V_620 = F_170 ( V_5 , V_590 , & V_619 ) ;
if ( ! V_620 )
* V_7 = F_172 ( V_619 ) ;
return V_620 ;
}
static int F_173 ( struct V_4 * V_5 ,
T_1 V_590 , T_1 V_74 , T_4 * V_621 )
{
int V_42 , V_622 , V_623 = 0 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 ) {
T_1 V_184 ;
T_5 V_72 ;
V_184 = V_590 + V_42 ;
memcpy ( & V_72 , V_621 + V_42 , 4 ) ;
F_46 ( V_600 , F_165 ( F_174 ( V_72 ) ) ) ;
V_7 = F_33 ( V_593 ) ;
F_46 ( V_593 , V_7 | V_599 ) ;
V_7 &= ~ ( V_592 | V_594 |
V_595 ) ;
F_46 ( V_593 , V_7 |
( 0 << V_596 ) |
( V_184 & V_592 ) |
V_598 |
V_624 ) ;
for ( V_622 = 0 ; V_622 < 1000 ; V_622 ++ ) {
V_7 = F_33 ( V_593 ) ;
if ( V_7 & V_599 )
break;
F_164 ( 1 ) ;
}
if ( ! ( V_7 & V_599 ) ) {
V_623 = - V_67 ;
break;
}
}
return V_623 ;
}
static int F_175 ( struct V_4 * V_5 , T_1 V_590 , T_1 V_74 ,
T_4 * V_621 )
{
int V_56 = 0 ;
T_1 V_625 = V_5 -> V_610 ;
T_1 V_626 = V_625 - 1 ;
T_1 V_601 ;
T_4 * V_591 ;
V_591 = F_176 ( V_625 , V_627 ) ;
if ( V_591 == NULL )
return - V_267 ;
while ( V_74 ) {
int V_622 ;
T_1 V_160 , V_628 , V_629 ;
V_160 = V_590 & ~ V_626 ;
for ( V_622 = 0 ; V_622 < V_625 ; V_622 += 4 ) {
V_56 = F_171 ( V_5 , V_160 + V_622 ,
( T_5 * ) ( V_591 + V_622 ) ) ;
if ( V_56 )
break;
}
if ( V_56 )
break;
V_628 = V_590 & V_626 ;
V_629 = V_625 ;
if ( V_74 < V_629 )
V_629 = V_74 ;
V_74 -= V_629 ;
memcpy ( V_591 + V_628 , V_621 , V_629 ) ;
V_590 = V_590 + ( V_625 - V_628 ) ;
F_161 ( V_5 ) ;
V_601 = V_630 | V_615 | V_604 ;
if ( F_166 ( V_5 , V_601 ) )
break;
F_46 ( V_613 , V_160 ) ;
V_601 = V_615 | V_604 | V_631 |
V_616 | V_617 | V_632 ;
if ( F_166 ( V_5 , V_601 ) )
break;
V_601 = V_630 | V_615 | V_604 ;
if ( F_166 ( V_5 , V_601 ) )
break;
for ( V_622 = 0 ; V_622 < V_625 ; V_622 += 4 ) {
T_5 V_72 ;
V_72 = * ( ( T_5 * ) ( V_591 + V_622 ) ) ;
F_46 ( V_633 , F_174 ( V_72 ) ) ;
F_46 ( V_613 , V_160 + V_622 ) ;
V_601 = V_615 | V_604 |
V_631 ;
if ( V_622 == 0 )
V_601 |= V_616 ;
else if ( V_622 == ( V_625 - 4 ) )
V_601 |= V_617 ;
V_56 = F_166 ( V_5 , V_601 ) ;
if ( V_56 )
break;
}
if ( V_56 )
break;
}
V_601 = V_634 | V_615 | V_604 ;
F_166 ( V_5 , V_601 ) ;
F_177 ( V_591 ) ;
return V_56 ;
}
static int F_178 ( struct V_4 * V_5 , T_1 V_590 , T_1 V_74 ,
T_4 * V_621 )
{
int V_42 , V_56 = 0 ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 , V_590 += 4 ) {
T_1 V_628 , V_160 , V_601 ;
T_5 V_72 ;
memcpy ( & V_72 , V_621 + V_42 , 4 ) ;
F_46 ( V_633 , F_174 ( V_72 ) ) ;
V_628 = V_590 % V_5 -> V_610 ;
V_160 = F_168 ( V_5 , V_590 ) ;
V_601 = V_615 | V_604 | V_631 ;
if ( V_628 == 0 || V_42 == 0 )
V_601 |= V_616 ;
if ( V_628 == ( V_5 -> V_610 - 4 ) )
V_601 |= V_617 ;
if ( V_42 == ( V_74 - 4 ) )
V_601 |= V_617 ;
if ( ( V_601 & V_616 ) ||
! F_23 ( V_5 , V_606 ) ||
! F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_613 , V_160 ) ;
if ( F_30 ( V_5 ) != V_635 &&
! F_23 ( V_5 , 5755_PLUS ) &&
( V_5 -> V_608 == V_636 ) &&
( V_601 & V_616 ) ) {
T_1 V_637 ;
V_637 = V_630 | V_615 | V_604 ;
V_56 = F_166 ( V_5 , V_637 ) ;
if ( V_56 )
break;
}
if ( ! F_23 ( V_5 , V_606 ) ) {
V_601 |= ( V_616 | V_617 ) ;
}
V_56 = F_166 ( V_5 , V_601 ) ;
if ( V_56 )
break;
}
return V_56 ;
}
static int F_179 ( struct V_4 * V_5 , T_1 V_590 , T_1 V_74 , T_4 * V_621 )
{
int V_56 ;
if ( F_23 ( V_5 , V_638 ) ) {
F_31 ( V_136 , V_5 -> V_22 &
~ V_534 ) ;
F_24 ( 40 ) ;
}
if ( ! F_23 ( V_5 , V_580 ) ) {
V_56 = F_173 ( V_5 , V_590 , V_74 , V_621 ) ;
} else {
T_1 V_639 ;
V_56 = F_159 ( V_5 ) ;
if ( V_56 )
return V_56 ;
F_161 ( V_5 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_586 ) )
F_46 ( V_640 , 0x406 ) ;
V_639 = F_33 ( V_641 ) ;
F_46 ( V_641 , V_639 | V_642 ) ;
if ( F_23 ( V_5 , V_605 ) || ! F_23 ( V_5 , V_606 ) ) {
V_56 = F_178 ( V_5 , V_590 , V_74 ,
V_621 ) ;
} else {
V_56 = F_175 ( V_5 , V_590 , V_74 ,
V_621 ) ;
}
V_639 = F_33 ( V_641 ) ;
F_46 ( V_641 , V_639 & ~ V_642 ) ;
F_162 ( V_5 ) ;
F_160 ( V_5 ) ;
}
if ( F_23 ( V_5 , V_638 ) ) {
F_31 ( V_136 , V_5 -> V_22 ) ;
F_24 ( 40 ) ;
}
return V_56 ;
}
static int F_180 ( struct V_4 * V_5 , T_1 V_643 )
{
int V_42 ;
const int V_644 = 10000 ;
for ( V_42 = 0 ; V_42 < V_644 ; V_42 ++ ) {
F_46 ( V_643 + V_645 , 0xffffffff ) ;
F_46 ( V_643 + V_646 , V_647 ) ;
if ( F_33 ( V_643 + V_646 ) & V_647 )
break;
if ( F_36 ( V_5 -> V_12 ) )
return - V_67 ;
}
return ( V_42 == V_644 ) ? - V_67 : 0 ;
}
static int F_181 ( struct V_4 * V_5 )
{
int V_623 = F_180 ( V_5 , V_648 ) ;
F_46 ( V_648 + V_645 , 0xffffffff ) ;
F_31 ( V_648 + V_646 , V_647 ) ;
F_24 ( 10 ) ;
return V_623 ;
}
static int F_182 ( struct V_4 * V_5 )
{
return F_180 ( V_5 , V_649 ) ;
}
static void F_183 ( struct V_4 * V_5 , T_1 V_643 )
{
F_46 ( V_643 + V_645 , 0xffffffff ) ;
F_31 ( V_643 + V_646 , 0x00000000 ) ;
}
static void F_184 ( struct V_4 * V_5 )
{
F_183 ( V_5 , V_648 ) ;
}
static int F_185 ( struct V_4 * V_5 , T_1 V_643 )
{
int V_623 ;
F_186 ( V_643 == V_649 && F_23 ( V_5 , 5705_PLUS ) ) ;
if ( F_30 ( V_5 ) == V_36 ) {
T_1 V_7 = F_33 ( V_650 ) ;
F_46 ( V_650 , V_7 | V_651 ) ;
return 0 ;
}
if ( V_643 == V_648 ) {
V_623 = F_181 ( V_5 ) ;
} else {
if ( F_23 ( V_5 , V_263 ) )
return 0 ;
V_623 = F_182 ( V_5 ) ;
}
if ( V_623 ) {
F_187 ( V_5 -> V_111 , L_18 ,
V_652 , V_643 == V_648 ? L_19 : L_20 ) ;
return - V_82 ;
}
if ( F_23 ( V_5 , V_580 ) )
F_46 ( V_582 , V_653 ) ;
return 0 ;
}
static int F_188 ( struct V_4 * V_5 ,
const struct V_654 * V_655 )
{
int V_656 ;
if ( V_5 -> V_656 == 0xffffffff )
V_656 = F_174 ( V_655 -> V_74 ) ;
else
V_656 = V_5 -> V_657 -> V_629 ;
return ( V_656 - V_658 ) / sizeof( T_1 ) ;
}
static int F_189 ( struct V_4 * V_5 , T_1 V_643 ,
T_1 V_659 , int V_660 ,
const struct V_654 * V_655 )
{
int V_75 , V_42 ;
void (* F_190)( struct V_4 * , T_1 , T_1 );
int V_661 = V_5 -> V_657 -> V_629 ;
if ( V_643 == V_649 && F_23 ( V_5 , 5705_PLUS ) ) {
F_187 ( V_5 -> V_111 ,
L_21 ,
V_652 ) ;
return - V_64 ;
}
if ( F_23 ( V_5 , 5705_PLUS ) && F_30 ( V_5 ) != V_662 )
F_190 = F_29 ;
else
F_190 = F_13 ;
if ( F_30 ( V_5 ) != V_662 ) {
int V_663 = F_159 ( V_5 ) ;
V_75 = F_185 ( V_5 , V_643 ) ;
if ( ! V_663 )
F_160 ( V_5 ) ;
if ( V_75 )
goto V_497;
for ( V_42 = 0 ; V_42 < V_660 ; V_42 += sizeof( T_1 ) )
F_190 ( V_5 , V_659 + V_42 , 0 ) ;
F_46 ( V_643 + V_645 , 0xffffffff ) ;
F_46 ( V_643 + V_646 ,
F_33 ( V_643 + V_646 ) | V_647 ) ;
} else {
V_661 -= V_658 ;
V_655 ++ ;
}
do {
T_1 * V_664 = ( T_1 * ) ( V_655 + 1 ) ;
for ( V_42 = 0 ; V_42 < F_188 ( V_5 , V_655 ) ; V_42 ++ )
F_190 ( V_5 , V_659 +
( F_174 ( V_655 -> V_665 ) & 0xffff ) +
( V_42 * sizeof( T_1 ) ) ,
F_174 ( V_664 [ V_42 ] ) ) ;
V_661 -= F_174 ( V_655 -> V_74 ) ;
V_655 = (struct V_654 * )
( ( void * ) V_655 + F_174 ( V_655 -> V_74 ) ) ;
} while ( V_661 > 0 );
V_75 = 0 ;
V_497:
return V_75 ;
}
static int F_191 ( struct V_4 * V_5 , T_1 V_643 , T_1 V_666 )
{
int V_42 ;
const int V_644 = 5 ;
F_46 ( V_643 + V_645 , 0xffffffff ) ;
F_31 ( V_643 + V_667 , V_666 ) ;
for ( V_42 = 0 ; V_42 < V_644 ; V_42 ++ ) {
if ( F_33 ( V_643 + V_667 ) == V_666 )
break;
F_46 ( V_643 + V_645 , 0xffffffff ) ;
F_46 ( V_643 + V_646 , V_647 ) ;
F_31 ( V_643 + V_667 , V_666 ) ;
F_24 ( 1000 ) ;
}
return ( V_42 == V_644 ) ? - V_67 : 0 ;
}
static int F_192 ( struct V_4 * V_5 )
{
const struct V_654 * V_655 ;
int V_75 ;
V_655 = (struct V_654 * ) V_5 -> V_657 -> V_72 ;
V_75 = F_189 ( V_5 , V_648 ,
V_668 , V_669 ,
V_655 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_189 ( V_5 , V_649 ,
V_670 , V_671 ,
V_655 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_191 ( V_5 , V_648 ,
F_174 ( V_655 -> V_665 ) ) ;
if ( V_75 ) {
F_187 ( V_5 -> V_111 , L_22
L_23 , V_652 ,
F_33 ( V_648 + V_667 ) ,
F_174 ( V_655 -> V_665 ) ) ;
return - V_82 ;
}
F_184 ( V_5 ) ;
return 0 ;
}
static int F_193 ( struct V_4 * V_5 )
{
const int V_644 = 1000 ;
int V_42 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < V_644 ; V_42 ++ ) {
if ( F_33 ( V_672 ) == V_673 )
break;
F_24 ( 10 ) ;
}
if ( V_42 == V_644 ) {
F_187 ( V_5 -> V_111 , L_24 ) ;
return - V_67 ;
}
V_7 = F_18 ( V_5 , V_674 ) ;
if ( V_7 & 0xff ) {
F_144 ( V_5 -> V_111 ,
L_25 ) ;
return - V_675 ;
}
return 0 ;
}
static void F_194 ( struct V_4 * V_5 )
{
struct V_654 * V_655 ;
if ( ! F_23 ( V_5 , V_676 ) )
return;
if ( F_193 ( V_5 ) )
return;
if ( ! V_5 -> V_657 )
return;
V_655 = (struct V_654 * ) V_5 -> V_657 -> V_72 ;
if ( F_174 ( V_655 -> V_665 ) != V_677 )
return;
if ( F_181 ( V_5 ) )
return;
F_189 ( V_5 , 0 , V_677 , 0 , V_655 ) ;
F_184 ( V_5 ) ;
}
static int F_195 ( struct V_4 * V_5 )
{
const struct V_654 * V_655 ;
unsigned long V_643 , V_659 , V_660 ;
int V_75 ;
if ( ! F_23 ( V_5 , V_678 ) )
return 0 ;
V_655 = (struct V_654 * ) V_5 -> V_657 -> V_72 ;
V_660 = V_5 -> V_656 ;
if ( F_30 ( V_5 ) == V_496 ) {
V_643 = V_648 ;
V_659 = V_679 ;
} else {
V_643 = V_649 ;
V_659 = V_670 ;
V_660 = V_671 ;
}
V_75 = F_189 ( V_5 , V_643 ,
V_659 , V_660 ,
V_655 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_191 ( V_5 , V_643 ,
F_174 ( V_655 -> V_665 ) ) ;
if ( V_75 ) {
F_187 ( V_5 -> V_111 ,
L_26 ,
V_652 , F_33 ( V_643 + V_667 ) ,
F_174 ( V_655 -> V_665 ) ) ;
return - V_82 ;
}
F_183 ( V_5 , V_643 ) ;
return 0 ;
}
static void F_196 ( struct V_4 * V_5 , T_4 * V_680 , int V_681 )
{
T_1 V_682 , V_683 ;
V_682 = ( ( V_680 [ 0 ] << 8 ) | V_680 [ 1 ] ) ;
V_683 = ( ( V_680 [ 2 ] << 24 ) | ( V_680 [ 3 ] << 16 ) |
( V_680 [ 4 ] << 8 ) | V_680 [ 5 ] ) ;
if ( V_681 < 4 ) {
F_46 ( V_684 + ( V_681 * 8 ) , V_682 ) ;
F_46 ( V_685 + ( V_681 * 8 ) , V_683 ) ;
} else {
V_681 -= 4 ;
F_46 ( V_686 + ( V_681 * 8 ) , V_682 ) ;
F_46 ( V_687 + ( V_681 * 8 ) , V_683 ) ;
}
}
static void F_197 ( struct V_4 * V_5 , bool V_688 )
{
T_1 V_682 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
if ( V_42 == 1 && V_688 )
continue;
F_196 ( V_5 , V_5 -> V_111 -> V_689 , V_42 ) ;
}
if ( F_30 ( V_5 ) == V_494 ||
F_30 ( V_5 ) == V_495 ) {
for ( V_42 = 4 ; V_42 < 16 ; V_42 ++ )
F_196 ( V_5 , V_5 -> V_111 -> V_689 , V_42 ) ;
}
V_682 = ( V_5 -> V_111 -> V_689 [ 0 ] +
V_5 -> V_111 -> V_689 [ 1 ] +
V_5 -> V_111 -> V_689 [ 2 ] +
V_5 -> V_111 -> V_689 [ 3 ] +
V_5 -> V_111 -> V_689 [ 4 ] +
V_5 -> V_111 -> V_689 [ 5 ] ) &
V_690 ;
F_46 ( V_691 , V_682 ) ;
}
static void F_198 ( struct V_4 * V_5 )
{
F_15 ( V_5 -> V_12 ,
V_119 , V_5 -> V_120 ) ;
}
static int F_199 ( struct V_4 * V_5 )
{
int V_75 ;
F_198 ( V_5 ) ;
V_75 = F_200 ( V_5 -> V_12 , V_692 ) ;
if ( ! V_75 ) {
F_149 ( V_5 ) ;
} else {
F_187 ( V_5 -> V_111 , L_27 ) ;
}
return V_75 ;
}
static int F_201 ( struct V_4 * V_5 )
{
T_1 V_120 ;
bool V_693 , V_563 ;
F_198 ( V_5 ) ;
if ( F_23 ( V_5 , V_694 ) )
F_202 ( V_5 -> V_12 , V_695 ,
V_696 ) ;
V_120 = F_33 ( V_119 ) ;
F_46 ( V_119 ,
V_120 | V_121 ) ;
V_693 = F_44 ( & V_5 -> V_12 -> V_111 ) &&
F_23 ( V_5 , V_112 ) ;
if ( F_23 ( V_5 , V_266 ) ) {
V_563 = false ;
if ( ( V_5 -> V_178 & V_386 ) &&
! ( V_5 -> V_178 & V_394 ) ) {
struct V_211 * V_212 ;
T_1 V_697 , V_393 ;
V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
V_5 -> V_178 |= V_394 ;
V_5 -> V_324 . V_367 = V_212 -> V_367 ;
V_5 -> V_324 . V_371 = V_212 -> V_371 ;
V_5 -> V_324 . V_347 = V_212 -> V_347 ;
V_5 -> V_324 . V_393 = V_212 -> V_393 ;
V_393 = V_698 |
V_699 |
V_700 |
V_701 ;
if ( F_23 ( V_5 , V_303 ) || V_693 ) {
if ( F_23 ( V_5 , V_702 ) )
V_393 |=
V_703 |
V_704 |
V_705 ;
else
V_393 |= V_705 ;
}
V_212 -> V_393 = V_393 ;
F_123 ( V_212 ) ;
V_697 = V_212 -> V_214 -> V_215 & V_212 -> V_214 -> V_216 ;
if ( V_697 != V_220 ) {
V_697 &= V_706 ;
if ( V_697 == V_707 ||
V_697 == V_708 ||
V_697 == V_709 )
V_563 = true ;
}
}
} else {
V_563 = true ;
if ( ! ( V_5 -> V_178 & V_394 ) )
V_5 -> V_178 |= V_394 ;
if ( ! ( V_5 -> V_178 & V_354 ) )
F_203 ( V_5 , false ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
T_1 V_7 ;
V_7 = F_33 ( V_650 ) ;
F_46 ( V_650 , V_7 | V_710 ) ;
} else if ( ! F_23 ( V_5 , V_303 ) ) {
int V_42 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_32 ( V_5 , V_711 , & V_7 ) ;
if ( V_7 == ~ V_310 )
break;
F_164 ( 1 ) ;
}
}
if ( F_23 ( V_5 , V_712 ) )
F_29 ( V_5 , V_713 , V_714 |
V_715 |
V_716 |
V_717 ) ;
if ( V_693 ) {
T_1 V_362 ;
if ( ! ( V_5 -> V_178 & V_562 ) ) {
if ( V_563 &&
! ( V_5 -> V_178 & V_179 ) ) {
F_65 ( V_5 ,
V_579 ,
V_718 |
V_576 |
V_719 ) ;
F_24 ( 40 ) ;
}
if ( V_5 -> V_178 & V_300 )
V_362 = V_370 ;
else if ( V_5 -> V_178 &
V_564 ) {
if ( V_5 -> V_324 . V_325 == V_326 )
V_362 = V_370 ;
else
V_362 = V_369 ;
} else
V_362 = V_369 ;
V_362 |= V_5 -> V_362 & V_720 ;
if ( F_30 ( V_5 ) == V_531 ) {
T_1 V_367 = F_23 ( V_5 , V_702 ) ?
V_327 : V_368 ;
if ( F_155 ( V_5 , V_367 ) )
V_362 |= V_720 ;
else
V_362 &= ~ V_720 ;
}
} else {
V_362 = V_721 ;
}
if ( ! F_23 ( V_5 , 5750_PLUS ) )
F_46 ( V_722 , V_5 -> V_558 ) ;
V_362 |= V_723 ;
if ( ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) ) &&
( F_23 ( V_5 , V_303 ) || F_23 ( V_5 , V_60 ) ) )
V_362 |= V_724 ;
if ( F_23 ( V_5 , V_60 ) )
V_362 |= V_725 |
V_726 |
V_727 ;
F_31 ( V_377 , V_362 ) ;
F_24 ( 100 ) ;
F_31 ( V_356 , V_728 ) ;
F_24 ( 10 ) ;
}
if ( ! F_23 ( V_5 , V_702 ) &&
( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 ) ) {
T_1 V_729 ;
V_729 = V_5 -> V_156 ;
V_729 |= ( V_730 |
V_731 ) ;
F_55 ( V_153 , V_729 | V_159 |
V_732 , 40 ) ;
} else if ( F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_152 ) ||
F_30 ( V_5 ) == V_36 ) {
} else if ( ! ( F_23 ( V_5 , 5750_PLUS ) && F_23 ( V_5 , V_303 ) ) ) {
T_1 V_733 , V_734 ;
if ( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 ) {
V_733 = ( V_730 |
V_731 |
V_159 ) ;
V_734 = V_733 | V_158 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_733 = V_157 ;
V_734 = V_733 | V_159 ;
} else {
V_733 = V_159 ;
V_734 = V_733 | V_158 ;
}
F_55 ( V_153 , V_5 -> V_156 | V_733 ,
40 ) ;
F_55 ( V_153 , V_5 -> V_156 | V_734 ,
40 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_735 ;
if ( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 ) {
V_735 = ( V_730 |
V_731 |
V_158 ) ;
} else {
V_735 = V_158 ;
}
F_55 ( V_153 ,
V_5 -> V_156 | V_735 , 40 ) ;
}
}
if ( ! ( V_693 ) && ! F_23 ( V_5 , V_303 ) )
F_158 ( V_5 , V_563 ) ;
F_153 ( V_5 , true ) ;
if ( ( ! F_23 ( V_5 , V_263 ) ) &&
( ( F_147 ( V_5 ) == V_736 ) ||
( F_147 ( V_5 ) == V_737 ) ) ) {
T_1 V_7 = F_33 ( 0x7d00 ) ;
V_7 &= ~ ( ( 1 << 16 ) | ( 1 << 4 ) | ( 1 << 2 ) | ( 1 << 1 ) | 1 ) ;
F_46 ( 0x7d00 , V_7 ) ;
if ( ! F_23 ( V_5 , V_303 ) ) {
int V_75 ;
V_75 = F_159 ( V_5 ) ;
F_185 ( V_5 , V_648 ) ;
if ( ! V_75 )
F_160 ( V_5 ) ;
}
}
F_95 ( V_5 , V_110 ) ;
F_42 ( V_5 , V_110 ) ;
return 0 ;
}
static void F_204 ( struct V_4 * V_5 )
{
F_205 ( V_5 -> V_12 , F_23 ( V_5 , V_112 ) ) ;
F_200 ( V_5 -> V_12 , V_738 ) ;
}
static void F_206 ( struct V_4 * V_5 , T_1 V_7 , T_3 * V_367 , T_4 * V_371 )
{
switch ( V_7 & V_739 ) {
case V_740 :
* V_367 = V_368 ;
* V_371 = V_372 ;
break;
case V_741 :
* V_367 = V_368 ;
* V_371 = V_329 ;
break;
case V_742 :
* V_367 = V_327 ;
* V_371 = V_372 ;
break;
case V_743 :
* V_367 = V_327 ;
* V_371 = V_329 ;
break;
case V_744 :
* V_367 = V_326 ;
* V_371 = V_372 ;
break;
case V_745 :
* V_367 = V_326 ;
* V_371 = V_329 ;
break;
default:
if ( V_5 -> V_178 & V_179 ) {
* V_367 = ( V_7 & V_746 ) ? V_327 :
V_368 ;
* V_371 = ( V_7 & V_747 ) ? V_329 :
V_372 ;
break;
}
* V_367 = V_748 ;
* V_371 = V_749 ;
break;
}
}
static int F_207 ( struct V_4 * V_5 , T_1 V_750 , T_1 V_337 )
{
int V_75 = 0 ;
T_1 V_7 , V_751 ;
V_751 = V_752 ;
V_751 |= F_208 ( V_750 ) & V_753 ;
V_751 |= F_112 ( V_337 ) ;
V_75 = F_59 ( V_5 , V_298 , V_751 ) ;
if ( V_75 )
goto V_186;
if ( ! ( V_5 -> V_178 & V_387 ) ) {
V_751 = F_209 ( V_750 ) ;
if ( F_77 ( V_5 ) == V_754 ||
F_77 ( V_5 ) == V_755 )
V_751 |= V_489 | V_490 ;
V_75 = F_59 ( V_5 , V_180 , V_751 ) ;
if ( V_75 )
goto V_186;
}
if ( ! ( V_5 -> V_178 & V_333 ) )
goto V_186;
F_46 ( V_459 ,
F_33 ( V_459 ) & ~ V_470 ) ;
V_75 = F_66 ( V_5 , true ) ;
if ( ! V_75 ) {
T_1 V_756 ;
V_7 = 0 ;
if ( V_750 & V_704 )
V_7 |= V_757 ;
if ( V_750 & V_758 )
V_7 |= V_759 ;
if ( ! V_5 -> V_447 . V_457 ) {
V_7 = 0 ;
V_5 -> V_447 . V_458 = 0 ;
} else {
V_5 -> V_447 . V_458 = V_750 &
( V_704 |
V_758 ) ;
}
V_75 = F_60 ( V_5 , V_449 , V_456 , V_7 ) ;
if ( V_75 )
V_7 = 0 ;
switch ( F_30 ( V_5 ) ) {
case V_471 :
case V_760 :
case V_662 :
case V_472 :
if ( V_7 )
V_7 = V_473 |
V_474 |
V_761 ;
F_63 ( V_5 , V_469 , V_7 ) ;
case V_528 :
case V_762 :
if ( ! F_62 ( V_5 , V_763 , & V_7 ) )
F_63 ( V_5 , V_763 , V_7 |
V_764 ) ;
}
V_756 = F_66 ( V_5 , false ) ;
if ( ! V_75 )
V_75 = V_756 ;
}
V_186:
return V_75 ;
}
static void F_210 ( struct V_4 * V_5 )
{
if ( V_5 -> V_324 . V_347 == V_352 ||
( V_5 -> V_178 & V_394 ) ) {
T_1 V_336 , V_765 ;
if ( ( V_5 -> V_178 & V_394 ) &&
! ( V_5 -> V_178 & V_564 ) ) {
V_336 = V_701 |
V_705 ;
if ( F_23 ( V_5 , V_702 ) )
V_336 |= V_703 |
V_704 ;
if ( V_5 -> V_178 & V_766 ) {
if ( ! ( V_5 -> V_178 &
V_767 ) )
V_336 |= V_768 ;
V_336 |= V_758 ;
}
V_765 = V_331 | V_332 ;
} else {
V_336 = V_5 -> V_324 . V_393 ;
if ( V_5 -> V_178 & V_387 )
V_336 &= ~ ( V_768 |
V_758 ) ;
V_765 = V_5 -> V_324 . V_337 ;
}
F_207 ( V_5 , V_336 , V_765 ) ;
if ( ( V_5 -> V_178 & V_394 ) &&
( V_5 -> V_178 & V_564 ) ) {
return;
}
F_59 ( V_5 , V_204 ,
V_571 | V_572 ) ;
} else {
int V_42 ;
T_1 V_769 , V_770 ;
V_5 -> V_324 . V_325 = V_5 -> V_324 . V_367 ;
V_5 -> V_324 . V_328 = V_5 -> V_324 . V_371 ;
if ( F_30 ( V_5 ) == V_543 ) {
F_59 ( V_5 , V_298 , V_753 ) ;
}
V_769 = 0 ;
switch ( V_5 -> V_324 . V_367 ) {
default:
case V_368 :
break;
case V_327 :
V_769 |= V_771 ;
break;
case V_326 :
V_769 |= V_488 ;
break;
}
if ( V_5 -> V_324 . V_371 == V_329 )
V_769 |= V_487 ;
if ( ! F_57 ( V_5 , V_204 , & V_770 ) &&
( V_769 != V_770 ) ) {
F_59 ( V_5 , V_204 , V_772 ) ;
for ( V_42 = 0 ; V_42 < 1500 ; V_42 ++ ) {
T_1 V_591 ;
F_24 ( 10 ) ;
if ( F_57 ( V_5 , V_297 , & V_591 ) ||
F_57 ( V_5 , V_297 , & V_591 ) )
continue;
if ( ! ( V_591 & V_773 ) ) {
F_24 ( 40 ) ;
break;
}
}
F_59 ( V_5 , V_204 , V_769 ) ;
F_24 ( 40 ) ;
}
}
}
static int F_211 ( struct V_4 * V_5 )
{
int V_75 ;
T_1 V_7 ;
V_75 = F_57 ( V_5 , V_204 , & V_7 ) ;
if ( V_75 )
goto V_186;
if ( ! ( V_7 & V_571 ) ) {
V_5 -> V_324 . V_347 = V_774 ;
V_5 -> V_324 . V_393 = 0 ;
F_86 ( V_5 , V_353 ) ;
V_75 = - V_210 ;
switch ( V_7 & ( V_488 | V_771 ) ) {
case 0 :
if ( V_5 -> V_178 & V_354 )
goto V_186;
V_5 -> V_324 . V_367 = V_368 ;
break;
case V_771 :
if ( V_5 -> V_178 & V_354 )
goto V_186;
V_5 -> V_324 . V_367 = V_327 ;
break;
case V_488 :
if ( ! ( V_5 -> V_178 & V_387 ) ) {
V_5 -> V_324 . V_367 = V_326 ;
break;
}
default:
goto V_186;
}
if ( V_7 & V_487 )
V_5 -> V_324 . V_371 = V_329 ;
else
V_5 -> V_324 . V_371 = V_372 ;
V_5 -> V_324 . V_337 = V_332 | V_331 ;
V_75 = 0 ;
goto V_186;
}
V_5 -> V_324 . V_347 = V_352 ;
V_5 -> V_324 . V_393 = V_700 ;
F_84 ( V_5 , V_353 ) ;
if ( ! ( V_5 -> V_178 & V_354 ) ) {
T_1 V_336 ;
V_75 = F_57 ( V_5 , V_298 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_336 = F_212 ( V_7 & V_753 ) ;
V_5 -> V_324 . V_393 |= V_336 | V_698 ;
V_5 -> V_324 . V_337 = F_104 ( V_7 ) ;
} else {
V_5 -> V_324 . V_393 |= V_775 ;
}
if ( ! ( V_5 -> V_178 & V_387 ) ) {
T_1 V_336 ;
if ( ! ( V_5 -> V_178 & V_354 ) ) {
V_75 = F_57 ( V_5 , V_180 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_336 = F_213 ( V_7 ) ;
} else {
V_75 = F_57 ( V_5 , V_298 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_336 = F_106 ( V_7 ) ;
V_5 -> V_324 . V_337 = V_336 ;
V_7 &= ( V_776 | V_777 ) ;
V_336 = F_214 ( V_7 ) ;
}
V_5 -> V_324 . V_393 |= V_336 ;
}
V_186:
return V_75 ;
}
static int F_215 ( struct V_4 * V_5 )
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
static bool F_216 ( struct V_4 * V_5 )
{
struct V_446 V_447 ;
if ( ! ( V_5 -> V_178 & V_333 ) )
return true ;
F_133 ( V_5 , & V_447 ) ;
if ( V_5 -> V_447 . V_457 ) {
if ( V_5 -> V_447 . V_458 != V_447 . V_458 ||
V_5 -> V_447 . V_462 != V_447 . V_462 ||
V_5 -> V_447 . V_460 != V_447 . V_460 )
return false ;
} else {
if ( V_447 . V_458 )
return false ;
}
return true ;
}
static bool F_217 ( struct V_4 * V_5 , T_1 * V_344 )
{
T_1 V_778 , V_779 , V_393 ;
V_393 = V_5 -> V_324 . V_393 ;
V_779 = F_208 ( V_393 ) & V_753 ;
V_778 = V_753 ;
if ( V_5 -> V_324 . V_328 == V_329 ) {
V_779 |= F_112 ( V_5 -> V_324 . V_337 ) ;
V_778 |= V_338 | V_339 ;
}
if ( F_57 ( V_5 , V_298 , V_344 ) )
return false ;
if ( ( * V_344 & V_778 ) != V_779 )
return false ;
if ( ! ( V_5 -> V_178 & V_387 ) ) {
T_1 V_780 ;
V_779 = F_209 ( V_393 ) ;
if ( F_57 ( V_5 , V_180 , & V_780 ) )
return false ;
if ( V_779 &&
( F_77 ( V_5 ) == V_754 ||
F_77 ( V_5 ) == V_755 ) ) {
V_779 |= V_489 | V_490 ;
V_780 &= ( V_781 | V_782 |
V_489 | V_490 ) ;
} else {
V_780 &= ( V_781 | V_782 ) ;
}
if ( V_780 != V_779 )
return false ;
}
return true ;
}
static bool F_218 ( struct V_4 * V_5 , T_1 * V_345 )
{
T_1 V_783 = 0 ;
if ( ! ( V_5 -> V_178 & V_387 ) ) {
T_1 V_7 ;
if ( F_57 ( V_5 , V_301 , & V_7 ) )
return false ;
V_783 = F_219 ( V_7 ) ;
}
if ( F_57 ( V_5 , V_299 , V_345 ) )
return false ;
V_783 |= F_220 ( * V_345 ) ;
V_5 -> V_324 . V_364 = V_783 ;
return true ;
}
static bool F_221 ( struct V_4 * V_5 , bool V_784 )
{
if ( V_784 != V_5 -> V_335 ) {
if ( V_784 ) {
F_222 ( V_5 -> V_111 ) ;
} else {
F_142 ( V_5 -> V_111 ) ;
if ( V_5 -> V_178 & V_300 )
V_5 -> V_178 &= ~ V_785 ;
}
F_100 ( V_5 ) ;
return true ;
}
return false ;
}
static void F_223 ( struct V_4 * V_5 )
{
F_46 ( V_786 , 0 ) ;
F_31 ( V_787 ,
V_788 |
V_789 |
V_790 |
V_791 ) ;
F_24 ( 40 ) ;
}
static void F_224 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_7 = V_792 |
V_793 ;
if ( F_77 ( V_5 ) == V_322 )
V_7 |= V_794 ;
F_31 ( V_795 , V_7 ) ;
F_31 ( V_468 ,
V_796 ) ;
V_7 = V_797 |
( V_5 -> V_447 . V_460 ? V_461 : 0 ) |
V_798 |
V_799 ;
if ( F_30 ( V_5 ) != V_471 )
V_7 |= V_800 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_801 ;
F_31 ( V_459 , V_5 -> V_447 . V_457 ? V_7 : 0 ) ;
F_31 ( V_463 ,
V_802 |
( V_5 -> V_447 . V_462 & 0xffff ) ) ;
F_31 ( V_803 ,
V_804 |
V_805 ) ;
}
static int F_225 ( struct V_4 * V_5 , bool V_806 )
{
bool V_464 ;
T_1 V_807 , V_7 ;
T_1 V_363 , V_364 ;
T_3 V_808 ;
T_4 V_809 ;
int V_42 , V_75 ;
F_223 ( V_5 ) ;
if ( ( V_5 -> V_164 & V_165 ) != 0 ) {
F_31 ( V_166 ,
( V_5 -> V_164 & ~ V_165 ) ) ;
F_24 ( 80 ) ;
}
F_65 ( V_5 , V_579 , 0 ) ;
if ( ( F_30 ( V_5 ) == V_494 ||
F_30 ( V_5 ) == V_495 ||
F_30 ( V_5 ) == V_496 ) &&
V_5 -> V_335 ) {
F_57 ( V_5 , V_297 , & V_807 ) ;
if ( ! F_57 ( V_5 , V_297 , & V_807 ) &&
! ( V_807 & V_773 ) )
V_806 = true ;
}
if ( V_806 )
F_145 ( V_5 ) ;
if ( ( V_5 -> V_215 & V_395 ) == V_396 ) {
F_57 ( V_5 , V_297 , & V_807 ) ;
if ( F_57 ( V_5 , V_297 , & V_807 ) ||
! F_23 ( V_5 , V_557 ) )
V_807 = 0 ;
if ( ! ( V_807 & V_773 ) ) {
V_75 = F_215 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_57 ( V_5 , V_297 , & V_807 ) ;
for ( V_42 = 0 ; V_42 < 1000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_297 , & V_807 ) &&
( V_807 & V_773 ) ) {
F_24 ( 40 ) ;
break;
}
}
if ( ( V_5 -> V_215 & V_810 ) ==
V_811 &&
! ( V_807 & V_773 ) &&
V_5 -> V_324 . V_325 == V_326 ) {
V_75 = F_145 ( V_5 ) ;
if ( ! V_75 )
V_75 = F_215 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
}
} else if ( F_77 ( V_5 ) == V_754 ||
F_77 ( V_5 ) == V_755 ) {
F_59 ( V_5 , 0x15 , 0x0a75 ) ;
F_59 ( V_5 , V_199 , 0x8c68 ) ;
F_59 ( V_5 , V_199 , 0x8d68 ) ;
F_59 ( V_5 , V_199 , 0x8c68 ) ;
}
F_57 ( V_5 , V_812 , & V_7 ) ;
F_57 ( V_5 , V_812 , & V_7 ) ;
if ( V_5 -> V_178 & V_813 )
F_59 ( V_5 , V_814 , ~ V_815 ) ;
else if ( ! ( V_5 -> V_178 & V_179 ) )
F_59 ( V_5 , V_814 , ~ 0 ) ;
if ( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 ) {
if ( V_5 -> V_558 == V_816 )
F_59 ( V_5 , V_486 ,
V_817 ) ;
else
F_59 ( V_5 , V_486 , 0 ) ;
}
V_464 = false ;
V_808 = V_748 ;
V_809 = V_749 ;
V_5 -> V_178 &= ~ V_818 ;
V_5 -> V_324 . V_364 = 0 ;
if ( V_5 -> V_178 & V_819 ) {
V_75 = F_64 ( V_5 ,
V_820 ,
& V_7 ) ;
if ( ! V_75 && ! ( V_7 & ( 1 << 10 ) ) ) {
F_65 ( V_5 ,
V_820 ,
V_7 | ( 1 << 10 ) ) ;
goto V_821;
}
}
V_807 = 0 ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_57 ( V_5 , V_297 , & V_807 ) ;
if ( ! F_57 ( V_5 , V_297 , & V_807 ) &&
( V_807 & V_773 ) )
break;
F_24 ( 40 ) ;
}
if ( V_807 & V_773 ) {
T_1 V_822 , V_769 ;
F_57 ( V_5 , V_823 , & V_822 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_823 , & V_822 ) &&
V_822 )
break;
}
F_206 ( V_5 , V_822 ,
& V_808 ,
& V_809 ) ;
V_769 = 0 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_57 ( V_5 , V_204 , & V_769 ) ;
if ( F_57 ( V_5 , V_204 , & V_769 ) )
continue;
if ( V_769 && V_769 != 0x7fff )
break;
F_24 ( 10 ) ;
}
V_363 = 0 ;
V_364 = 0 ;
V_5 -> V_324 . V_325 = V_808 ;
V_5 -> V_324 . V_328 = V_809 ;
if ( V_5 -> V_324 . V_347 == V_352 ) {
bool V_824 = F_216 ( V_5 ) ;
if ( ( V_769 & V_571 ) &&
V_824 &&
F_217 ( V_5 , & V_363 ) &&
F_218 ( V_5 , & V_364 ) )
V_464 = true ;
if ( ! V_824 &&
( V_5 -> V_178 & V_564 ) &&
! V_806 ) {
F_224 ( V_5 ) ;
F_145 ( V_5 ) ;
}
} else {
if ( ! ( V_769 & V_571 ) &&
V_5 -> V_324 . V_367 == V_808 &&
V_5 -> V_324 . V_371 == V_809 ) {
V_464 = true ;
}
}
if ( V_464 &&
V_5 -> V_324 . V_328 == V_329 ) {
T_1 V_161 , V_44 ;
if ( V_5 -> V_178 & V_179 ) {
V_161 = V_825 ;
V_44 = V_826 ;
} else {
V_161 = V_827 ;
V_44 = V_828 ;
}
if ( ! F_57 ( V_5 , V_161 , & V_7 ) && ( V_7 & V_44 ) )
V_5 -> V_178 |= V_818 ;
F_108 ( V_5 , V_363 , V_364 ) ;
}
}
V_821:
if ( ! V_464 || ( V_5 -> V_178 & V_394 ) ) {
F_210 ( V_5 ) ;
if ( F_23 ( V_5 , V_264 ) ) {
V_464 = true ;
V_808 = V_326 ;
V_809 = V_329 ;
V_5 -> V_324 . V_325 = V_808 ;
V_5 -> V_324 . V_328 = V_809 ;
}
F_57 ( V_5 , V_297 , & V_807 ) ;
if ( ( ! F_57 ( V_5 , V_297 , & V_807 ) && ( V_807 & V_773 ) ) ||
( V_5 -> V_362 & V_829 ) )
V_464 = true ;
}
V_5 -> V_362 &= ~ V_365 ;
if ( V_464 ) {
if ( V_5 -> V_324 . V_325 == V_327 ||
V_5 -> V_324 . V_325 == V_368 )
V_5 -> V_362 |= V_369 ;
else
V_5 -> V_362 |= V_370 ;
} else if ( V_5 -> V_178 & V_179 )
V_5 -> V_362 |= V_369 ;
else
V_5 -> V_362 |= V_370 ;
if ( F_23 ( V_5 , V_830 ) ) {
T_1 V_558 = F_33 ( V_722 ) ;
V_558 &= ~ ( V_831 | V_832 ) ;
if ( V_5 -> V_324 . V_325 == V_368 )
V_558 |= V_833 ;
else if ( V_5 -> V_324 . V_325 == V_327 )
V_558 |= ( V_833 |
V_832 ) ;
else if ( V_5 -> V_324 . V_325 == V_326 )
V_558 |= ( V_833 |
V_831 ) ;
F_46 ( V_722 , V_558 ) ;
F_24 ( 40 ) ;
}
V_5 -> V_362 &= ~ V_366 ;
if ( V_5 -> V_324 . V_328 == V_372 )
V_5 -> V_362 |= V_366 ;
if ( F_30 ( V_5 ) == V_531 ) {
if ( V_464 &&
F_155 ( V_5 , V_5 -> V_324 . V_325 ) )
V_5 -> V_362 |= V_720 ;
else
V_5 -> V_362 &= ~ V_720 ;
}
if ( ( V_5 -> V_215 & V_395 ) == V_560 &&
F_77 ( V_5 ) == V_834 ) {
V_5 -> V_164 |= V_165 ;
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
}
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
F_135 ( V_5 , V_464 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
F_31 ( V_786 , 0 ) ;
} else {
F_31 ( V_786 , V_835 ) ;
}
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_531 &&
V_464 &&
V_5 -> V_324 . V_325 == V_326 &&
( F_23 ( V_5 , V_836 ) || F_23 ( V_5 , V_837 ) ) ) {
F_24 ( 120 ) ;
F_31 ( V_787 ,
( V_788 |
V_789 ) ) ;
F_24 ( 40 ) ;
F_29 ( V_5 ,
V_309 ,
V_838 ) ;
}
if ( F_23 ( V_5 , V_694 ) ) {
if ( V_5 -> V_324 . V_325 == V_327 ||
V_5 -> V_324 . V_325 == V_368 )
F_226 ( V_5 -> V_12 , V_695 ,
V_696 ) ;
else
F_202 ( V_5 -> V_12 , V_695 ,
V_696 ) ;
}
F_221 ( V_5 , V_464 ) ;
return 0 ;
}
static int F_227 ( struct V_4 * V_5 ,
struct V_839 * V_840 )
{
T_3 V_337 ;
unsigned long V_841 ;
T_1 V_842 ;
int V_56 ;
if ( V_840 -> V_843 == V_844 ) {
V_840 -> V_845 = 0 ;
V_840 -> V_846 = 0 ;
V_840 -> V_847 = 0 ;
V_840 -> V_848 = 0 ;
V_840 -> V_849 = 0 ;
V_840 -> V_850 = 0 ;
V_840 -> V_851 = 0 ;
V_840 -> V_852 = 0 ;
}
V_840 -> V_847 ++ ;
if ( F_33 ( V_787 ) & V_853 ) {
V_842 = F_33 ( V_854 ) ;
if ( V_842 != V_840 -> V_848 ) {
V_840 -> V_848 = V_842 ;
V_840 -> V_850 = 0 ;
V_840 -> V_849 = 0 ;
} else {
if ( ++ V_840 -> V_849 > 1 ) {
V_840 -> V_850 = 1 ;
V_840 -> V_848 = V_842 ;
}
}
if ( V_842 & V_855 )
V_840 -> V_852 = 1 ;
else
V_840 -> V_852 = 0 ;
V_840 -> V_851 = 0 ;
} else {
V_840 -> V_851 = 1 ;
V_840 -> V_848 = 0 ;
V_840 -> V_849 = 0 ;
V_840 -> V_850 = 0 ;
V_840 -> V_852 = 0 ;
V_842 = 0 ;
}
V_840 -> V_845 = V_842 ;
V_56 = V_856 ;
switch ( V_840 -> V_843 ) {
case V_844 :
if ( V_840 -> V_10 & ( V_857 | V_858 ) )
V_840 -> V_843 = V_859 ;
case V_859 :
V_840 -> V_10 &= ~ ( V_860 | V_861 ) ;
if ( V_840 -> V_10 & V_857 ) {
V_840 -> V_846 = 0 ;
V_840 -> V_847 = 0 ;
V_840 -> V_848 = 0 ;
V_840 -> V_849 = 0 ;
V_840 -> V_850 = 0 ;
V_840 -> V_851 = 0 ;
V_840 -> V_852 = 0 ;
V_840 -> V_843 = V_862 ;
} else {
V_840 -> V_843 = V_863 ;
}
break;
case V_862 :
V_840 -> V_846 = V_840 -> V_847 ;
V_840 -> V_10 &= ~ ( V_864 ) ;
V_840 -> V_865 = 0 ;
F_46 ( V_866 , 0 ) ;
V_5 -> V_362 |= V_867 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
V_56 = V_868 ;
V_840 -> V_843 = V_869 ;
case V_869 :
V_841 = V_840 -> V_847 - V_840 -> V_846 ;
if ( V_841 > V_870 )
V_840 -> V_843 = V_871 ;
else
V_56 = V_868 ;
break;
case V_863 :
V_56 = V_872 ;
break;
case V_871 :
V_840 -> V_10 &= ~ ( V_873 ) ;
V_840 -> V_865 = V_874 ;
V_337 = F_105 ( V_5 -> V_324 . V_337 ) ;
if ( V_337 & V_342 )
V_840 -> V_865 |= V_875 ;
if ( V_337 & V_343 )
V_840 -> V_865 |= V_876 ;
F_46 ( V_866 , V_840 -> V_865 ) ;
V_5 -> V_362 |= V_867 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
V_840 -> V_843 = V_877 ;
break;
case V_877 :
if ( V_840 -> V_850 != 0 && V_840 -> V_845 != 0 )
V_840 -> V_843 = V_878 ;
break;
case V_878 :
V_840 -> V_865 |= V_855 ;
F_46 ( V_866 , V_840 -> V_865 ) ;
V_5 -> V_362 |= V_867 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
V_840 -> V_843 = V_879 ;
case V_879 :
if ( V_840 -> V_852 != 0 ) {
if ( ( V_840 -> V_845 & ~ V_855 ) ==
( V_840 -> V_848 & ~ V_855 ) ) {
V_840 -> V_843 = V_880 ;
} else {
V_840 -> V_843 = V_859 ;
}
} else if ( V_840 -> V_850 != 0 &&
V_840 -> V_845 == 0 ) {
V_840 -> V_843 = V_859 ;
}
break;
case V_880 :
if ( V_840 -> V_845 & V_881 ) {
V_56 = V_882 ;
break;
}
V_840 -> V_10 &= ~ ( V_883 |
V_884 |
V_885 |
V_886 |
V_887 |
V_888 |
V_889 |
V_890 |
V_891 ) ;
if ( V_840 -> V_845 & V_874 )
V_840 -> V_10 |= V_883 ;
if ( V_840 -> V_845 & V_892 )
V_840 -> V_10 |= V_884 ;
if ( V_840 -> V_845 & V_875 )
V_840 -> V_10 |= V_885 ;
if ( V_840 -> V_845 & V_876 )
V_840 -> V_10 |= V_886 ;
if ( V_840 -> V_845 & V_893 )
V_840 -> V_10 |= V_887 ;
if ( V_840 -> V_845 & V_894 )
V_840 -> V_10 |= V_888 ;
if ( V_840 -> V_845 & V_895 )
V_840 -> V_10 |= V_889 ;
V_840 -> V_846 = V_840 -> V_847 ;
V_840 -> V_10 ^= ( V_873 ) ;
if ( V_840 -> V_845 & 0x0008 )
V_840 -> V_10 |= V_890 ;
if ( V_840 -> V_845 & V_895 )
V_840 -> V_10 |= V_891 ;
V_840 -> V_10 |= V_861 ;
V_840 -> V_843 = V_896 ;
V_56 = V_868 ;
break;
case V_896 :
if ( V_840 -> V_850 != 0 &&
V_840 -> V_845 == 0 ) {
V_840 -> V_843 = V_859 ;
break;
}
V_841 = V_840 -> V_847 - V_840 -> V_846 ;
if ( V_841 > V_870 ) {
if ( ! ( V_840 -> V_10 & ( V_889 ) ) ) {
V_840 -> V_843 = V_897 ;
} else {
if ( ( V_840 -> V_865 & V_895 ) == 0 &&
! ( V_840 -> V_10 & V_891 ) ) {
V_840 -> V_843 = V_897 ;
} else {
V_56 = V_882 ;
}
}
}
break;
case V_897 :
V_840 -> V_846 = V_840 -> V_847 ;
V_5 -> V_362 &= ~ V_867 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
V_840 -> V_843 = V_898 ;
V_56 = V_868 ;
break;
case V_898 :
if ( V_840 -> V_850 != 0 &&
V_840 -> V_845 == 0 ) {
V_840 -> V_843 = V_859 ;
break;
}
V_841 = V_840 -> V_847 - V_840 -> V_846 ;
if ( V_841 > V_870 ) {
V_840 -> V_843 = V_899 ;
}
break;
case V_899 :
V_840 -> V_10 |= ( V_860 | V_900 ) ;
V_56 = V_872 ;
break;
case V_901 :
break;
case V_902 :
break;
default:
V_56 = V_882 ;
break;
}
return V_56 ;
}
static int F_228 ( struct V_4 * V_5 , T_1 * V_903 , T_1 * V_904 )
{
int V_620 = 0 ;
struct V_839 V_905 ;
int V_57 = V_882 ;
unsigned int V_906 ;
T_1 V_591 ;
F_31 ( V_866 , 0 ) ;
V_591 = V_5 -> V_362 & ~ V_365 ;
F_31 ( V_377 , V_591 | V_370 ) ;
F_24 ( 40 ) ;
F_31 ( V_377 , V_5 -> V_362 | V_867 ) ;
F_24 ( 40 ) ;
memset ( & V_905 , 0 , sizeof( V_905 ) ) ;
V_905 . V_10 |= V_857 ;
V_905 . V_843 = V_844 ;
V_905 . V_847 = 0 ;
V_906 = 0 ;
while ( ++ V_906 < 195000 ) {
V_57 = F_227 ( V_5 , & V_905 ) ;
if ( V_57 == V_872 || V_57 == V_882 )
break;
F_24 ( 1 ) ;
}
V_5 -> V_362 &= ~ V_867 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
* V_903 = V_905 . V_865 ;
* V_904 = V_905 . V_10 ;
if ( V_57 == V_872 &&
( V_905 . V_10 & ( V_860 | V_900 |
V_883 ) ) )
V_620 = 1 ;
return V_620 ;
}
static void F_229 ( struct V_4 * V_5 )
{
T_1 V_907 = F_33 ( V_787 ) ;
int V_42 ;
if ( F_23 ( V_5 , V_557 ) &&
! ( V_907 & V_908 ) )
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
static bool F_230 ( struct V_4 * V_5 , T_1 V_907 )
{
T_3 V_337 ;
bool V_464 ;
T_1 V_565 , V_909 ;
T_1 V_567 , V_910 ;
int V_911 , V_912 ;
V_567 = 0 ;
V_910 = 0 ;
V_911 = 0 ;
V_912 = 1 ;
V_464 = false ;
if ( F_77 ( V_5 ) != V_913 &&
F_77 ( V_5 ) != V_914 ) {
V_911 = 1 ;
if ( F_33 ( V_915 ) & V_916 )
V_912 = 0 ;
V_567 = F_33 ( V_568 ) & 0x00f06fff ;
}
V_565 = F_33 ( V_566 ) ;
if ( V_5 -> V_324 . V_347 != V_352 ) {
if ( V_565 & V_569 ) {
if ( V_911 ) {
T_1 V_7 = V_567 ;
if ( V_912 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_568 , V_7 ) ;
}
F_31 ( V_566 , V_917 ) ;
}
if ( V_907 & V_908 ) {
F_108 ( V_5 , 0 , 0 ) ;
V_464 = true ;
}
goto V_497;
}
V_910 = V_569 | V_917 ;
V_337 = F_105 ( V_5 -> V_324 . V_337 ) ;
if ( V_337 & V_342 )
V_910 |= V_918 ;
if ( V_337 & V_343 )
V_910 |= V_919 ;
if ( V_565 != V_910 ) {
if ( ( V_5 -> V_178 & V_785 ) &&
V_5 -> V_920 &&
( ( V_907 & ( V_908 |
V_853 ) ) ==
V_908 ) ) {
V_5 -> V_920 -- ;
V_464 = true ;
goto V_497;
}
V_921:
if ( V_911 )
F_31 ( V_568 , V_567 | 0xc011000 ) ;
F_31 ( V_566 , V_910 | V_570 ) ;
F_24 ( 5 ) ;
F_31 ( V_566 , V_910 ) ;
V_5 -> V_920 = V_922 ;
V_5 -> V_178 &= ~ V_785 ;
} else if ( V_907 & ( V_908 |
V_923 ) ) {
V_909 = F_33 ( V_259 ) ;
V_907 = F_33 ( V_787 ) ;
if ( ( V_909 & V_924 ) &&
( V_907 & V_908 ) ) {
T_1 V_925 = 0 , V_926 = 0 ;
if ( V_565 & V_918 )
V_925 |= V_342 ;
if ( V_565 & V_919 )
V_925 |= V_343 ;
if ( V_909 & V_927 )
V_926 |= V_928 ;
if ( V_909 & V_929 )
V_926 |= V_930 ;
V_5 -> V_324 . V_364 =
F_214 ( V_926 ) ;
F_108 ( V_5 , V_925 , V_926 ) ;
V_464 = true ;
V_5 -> V_920 = 0 ;
V_5 -> V_178 &= ~ V_785 ;
} else if ( ! ( V_909 & V_924 ) ) {
if ( V_5 -> V_920 )
V_5 -> V_920 -- ;
else {
if ( V_911 ) {
T_1 V_7 = V_567 ;
if ( V_912 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_568 , V_7 ) ;
}
F_31 ( V_566 , V_917 ) ;
F_24 ( 40 ) ;
V_907 = F_33 ( V_787 ) ;
if ( ( V_907 & V_908 ) &&
! ( V_907 & V_853 ) ) {
F_108 ( V_5 , 0 , 0 ) ;
V_464 = true ;
V_5 -> V_178 |=
V_785 ;
V_5 -> V_920 =
V_931 ;
} else
goto V_921;
}
}
} else {
V_5 -> V_920 = V_922 ;
V_5 -> V_178 &= ~ V_785 ;
}
V_497:
return V_464 ;
}
static bool F_231 ( struct V_4 * V_5 , T_1 V_907 )
{
bool V_464 = false ;
if ( ! ( V_907 & V_908 ) )
goto V_497;
if ( V_5 -> V_324 . V_347 == V_352 ) {
T_1 V_903 , V_904 ;
int V_42 ;
if ( F_228 ( V_5 , & V_903 , & V_904 ) ) {
T_1 V_925 = 0 , V_926 = 0 ;
if ( V_903 & V_875 )
V_925 |= V_342 ;
if ( V_903 & V_876 )
V_925 |= V_343 ;
if ( V_904 & V_885 )
V_926 |= V_928 ;
if ( V_904 & V_886 )
V_926 |= V_930 ;
V_5 -> V_324 . V_364 =
F_214 ( V_926 ) ;
F_108 ( V_5 , V_925 , V_926 ) ;
V_464 = true ;
}
for ( V_42 = 0 ; V_42 < 30 ; V_42 ++ ) {
F_24 ( 20 ) ;
F_31 ( V_787 ,
( V_788 |
V_789 ) ) ;
F_24 ( 40 ) ;
if ( ( F_33 ( V_787 ) &
( V_788 |
V_789 ) ) == 0 )
break;
}
V_907 = F_33 ( V_787 ) ;
if ( ! V_464 &&
( V_907 & V_908 ) &&
! ( V_907 & V_853 ) )
V_464 = true ;
} else {
F_108 ( V_5 , 0 , 0 ) ;
V_464 = true ;
F_31 ( V_377 , ( V_5 -> V_362 | V_867 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
}
V_497:
return V_464 ;
}
static int F_232 ( struct V_4 * V_5 , bool V_806 )
{
T_1 V_932 ;
T_3 V_933 ;
T_4 V_934 ;
T_1 V_907 ;
bool V_464 ;
int V_42 ;
V_932 = V_5 -> V_324 . V_330 ;
V_933 = V_5 -> V_324 . V_325 ;
V_934 = V_5 -> V_324 . V_328 ;
if ( ! F_23 ( V_5 , V_935 ) &&
V_5 -> V_335 &&
F_23 ( V_5 , V_557 ) ) {
V_907 = F_33 ( V_787 ) ;
V_907 &= ( V_908 |
V_923 |
V_789 |
V_853 ) ;
if ( V_907 == ( V_908 |
V_923 ) ) {
F_31 ( V_787 , ( V_788 |
V_789 ) ) ;
return 0 ;
}
}
F_31 ( V_866 , 0 ) ;
V_5 -> V_362 &= ~ ( V_365 | V_366 ) ;
V_5 -> V_362 |= V_721 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
if ( V_5 -> V_215 == V_936 )
F_229 ( V_5 ) ;
F_31 ( V_786 , V_835 ) ;
F_24 ( 40 ) ;
V_464 = false ;
V_5 -> V_324 . V_364 = 0 ;
V_907 = F_33 ( V_787 ) ;
if ( F_23 ( V_5 , V_935 ) )
V_464 = F_230 ( V_5 , V_907 ) ;
else
V_464 = F_231 ( V_5 , V_907 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 =
( V_135 |
( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & ~ V_144 ) ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_31 ( V_787 , ( V_788 |
V_789 ) ) ;
F_24 ( 5 ) ;
if ( ( F_33 ( V_787 ) & ( V_788 |
V_789 |
V_791 ) ) == 0 )
break;
}
V_907 = F_33 ( V_787 ) ;
if ( ( V_907 & V_908 ) == 0 ) {
V_464 = false ;
if ( V_5 -> V_324 . V_347 == V_352 &&
V_5 -> V_920 == 0 ) {
F_31 ( V_377 , ( V_5 -> V_362 |
V_867 ) ) ;
F_24 ( 1 ) ;
F_31 ( V_377 , V_5 -> V_362 ) ;
}
}
if ( V_464 ) {
V_5 -> V_324 . V_325 = V_326 ;
V_5 -> V_324 . V_328 = V_329 ;
F_46 ( V_722 , ( V_5 -> V_558 |
V_833 |
V_831 ) ) ;
} else {
V_5 -> V_324 . V_325 = V_748 ;
V_5 -> V_324 . V_328 = V_749 ;
F_46 ( V_722 , ( V_5 -> V_558 |
V_833 |
V_937 ) ) ;
}
if ( ! F_221 ( V_5 , V_464 ) ) {
T_1 V_938 = V_5 -> V_324 . V_330 ;
if ( V_932 != V_938 ||
V_933 != V_5 -> V_324 . V_325 ||
V_934 != V_5 -> V_324 . V_328 )
F_100 ( V_5 ) ;
}
return 0 ;
}
static int F_233 ( struct V_4 * V_5 , bool V_806 )
{
int V_75 = 0 ;
T_1 V_807 , V_769 ;
T_3 V_808 = V_748 ;
T_4 V_809 = V_749 ;
bool V_464 = false ;
T_1 V_925 , V_926 , V_939 ;
if ( ( F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 ) &&
! F_57 ( V_5 , V_940 , & V_939 ) &&
( V_939 & V_941 ) ) {
if ( V_806 )
F_145 ( V_5 ) ;
V_5 -> V_362 &= ~ V_365 ;
if ( ! ( V_939 & V_942 ) ) {
V_5 -> V_362 |= V_370 ;
} else {
V_464 = true ;
if ( V_939 & V_943 ) {
V_808 = V_326 ;
V_5 -> V_362 |= V_370 ;
} else if ( V_939 & V_944 ) {
V_808 = V_327 ;
V_5 -> V_362 |= V_369 ;
} else {
V_808 = V_368 ;
V_5 -> V_362 |= V_369 ;
}
if ( V_939 & V_945 )
V_809 = V_329 ;
else
V_809 = V_372 ;
}
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
F_223 ( V_5 ) ;
goto V_946;
}
V_5 -> V_362 |= V_370 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
F_223 ( V_5 ) ;
if ( V_806 )
F_145 ( V_5 ) ;
V_5 -> V_324 . V_364 = 0 ;
V_75 |= F_57 ( V_5 , V_297 , & V_807 ) ;
V_75 |= F_57 ( V_5 , V_297 , & V_807 ) ;
if ( F_30 ( V_5 ) == V_543 ) {
if ( F_33 ( V_947 ) & V_948 )
V_807 |= V_773 ;
else
V_807 &= ~ V_773 ;
}
V_75 |= F_57 ( V_5 , V_204 , & V_769 ) ;
if ( ( V_5 -> V_324 . V_347 == V_352 ) && ! V_806 &&
( V_5 -> V_178 & V_785 ) ) {
} else if ( V_5 -> V_324 . V_347 == V_352 ) {
T_1 V_336 , V_949 ;
V_75 |= F_57 ( V_5 , V_298 , & V_336 ) ;
V_949 = V_336 & ~ ( V_777 | V_776 |
V_342 |
V_343 |
V_950 ) ;
V_949 |= F_105 ( V_5 -> V_324 . V_337 ) ;
V_949 |= F_234 ( V_5 -> V_324 . V_393 ) ;
if ( ( V_949 != V_336 ) || ! ( V_769 & V_571 ) ) {
F_59 ( V_5 , V_298 , V_949 ) ;
V_769 |= V_571 | V_572 ;
F_59 ( V_5 , V_204 , V_769 ) ;
F_31 ( V_786 , V_835 ) ;
V_5 -> V_920 = V_951 ;
V_5 -> V_178 &= ~ V_785 ;
return V_75 ;
}
} else {
T_1 V_952 ;
V_769 &= ~ V_488 ;
V_952 = V_769 & ~ ( V_571 | V_487 ) ;
if ( V_5 -> V_324 . V_371 == V_329 )
V_952 |= V_487 ;
if ( V_952 != V_769 ) {
V_952 |= V_488 ;
if ( V_5 -> V_335 ) {
T_1 V_336 ;
V_75 |= F_57 ( V_5 , V_298 , & V_336 ) ;
V_336 &= ~ ( V_777 |
V_776 |
V_950 ) ;
F_59 ( V_5 , V_298 , V_336 ) ;
F_59 ( V_5 , V_204 , V_769 |
V_572 |
V_571 ) ;
F_24 ( 10 ) ;
F_141 ( V_5 ) ;
}
F_59 ( V_5 , V_204 , V_952 ) ;
V_769 = V_952 ;
V_75 |= F_57 ( V_5 , V_297 , & V_807 ) ;
V_75 |= F_57 ( V_5 , V_297 , & V_807 ) ;
if ( F_30 ( V_5 ) == V_543 ) {
if ( F_33 ( V_947 ) & V_948 )
V_807 |= V_773 ;
else
V_807 &= ~ V_773 ;
}
V_5 -> V_178 &= ~ V_785 ;
}
}
if ( V_807 & V_773 ) {
V_808 = V_326 ;
V_464 = true ;
if ( V_769 & V_487 )
V_809 = V_329 ;
else
V_809 = V_372 ;
V_925 = 0 ;
V_926 = 0 ;
if ( V_769 & V_571 ) {
T_1 V_953 ;
V_75 |= F_57 ( V_5 , V_298 , & V_925 ) ;
V_75 |= F_57 ( V_5 , V_299 , & V_926 ) ;
V_953 = V_925 & V_926 ;
if ( V_953 & ( V_776 |
V_777 ) ) {
if ( V_953 & V_777 )
V_809 = V_329 ;
else
V_809 = V_372 ;
V_5 -> V_324 . V_364 =
F_214 ( V_926 ) ;
} else if ( ! F_23 ( V_5 , 5780_CLASS ) ) {
} else {
V_464 = false ;
}
}
}
V_946:
if ( V_464 && V_809 == V_329 )
F_108 ( V_5 , V_925 , V_926 ) ;
V_5 -> V_362 &= ~ V_366 ;
if ( V_5 -> V_324 . V_328 == V_372 )
V_5 -> V_362 |= V_366 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
F_31 ( V_786 , V_835 ) ;
V_5 -> V_324 . V_325 = V_808 ;
V_5 -> V_324 . V_328 = V_809 ;
F_221 ( V_5 , V_464 ) ;
return V_75 ;
}
static void F_235 ( struct V_4 * V_5 )
{
if ( V_5 -> V_920 ) {
V_5 -> V_920 -- ;
return;
}
if ( ! V_5 -> V_335 &&
( V_5 -> V_324 . V_347 == V_352 ) ) {
T_1 V_769 ;
F_57 ( V_5 , V_204 , & V_769 ) ;
if ( V_769 & V_571 ) {
T_1 V_954 , V_955 ;
F_59 ( V_5 , V_199 , 0x7c00 ) ;
F_57 ( V_5 , V_199 , & V_954 ) ;
F_59 ( V_5 , V_189 ,
V_956 ) ;
F_57 ( V_5 , V_190 , & V_955 ) ;
F_57 ( V_5 , V_190 , & V_955 ) ;
if ( ( V_954 & 0x10 ) && ! ( V_955 & 0x20 ) ) {
V_769 &= ~ V_571 ;
V_769 |= V_488 | V_487 ;
F_59 ( V_5 , V_204 , V_769 ) ;
V_5 -> V_178 |= V_785 ;
}
}
} else if ( V_5 -> V_335 &&
( V_5 -> V_324 . V_347 == V_352 ) &&
( V_5 -> V_178 & V_785 ) ) {
T_1 V_955 ;
F_59 ( V_5 , V_189 ,
V_956 ) ;
F_57 ( V_5 , V_190 , & V_955 ) ;
if ( V_955 & 0x20 ) {
T_1 V_769 ;
F_57 ( V_5 , V_204 , & V_769 ) ;
F_59 ( V_5 , V_204 , V_769 | V_571 ) ;
V_5 -> V_178 &= ~ V_785 ;
}
}
}
static int F_203 ( struct V_4 * V_5 , bool V_806 )
{
T_1 V_7 ;
int V_75 ;
if ( V_5 -> V_178 & V_562 )
V_75 = F_232 ( V_5 , V_806 ) ;
else if ( V_5 -> V_178 & V_300 )
V_75 = F_233 ( V_5 , V_806 ) ;
else
V_75 = F_225 ( V_5 , V_806 ) ;
if ( F_147 ( V_5 ) == V_498 ) {
T_1 V_957 ;
V_7 = F_33 ( V_958 ) & V_959 ;
if ( V_7 == V_960 )
V_957 = 65 ;
else if ( V_7 == V_961 )
V_957 = 6 ;
else
V_957 = 12 ;
V_7 = F_33 ( V_492 ) & ~ V_962 ;
V_7 |= ( V_957 << V_963 ) ;
F_46 ( V_492 , V_7 ) ;
}
V_7 = ( 2 << V_382 ) |
( 6 << V_383 ) ;
if ( F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_762 )
V_7 |= F_33 ( V_381 ) &
( V_964 |
V_965 ) ;
if ( V_5 -> V_324 . V_325 == V_326 &&
V_5 -> V_324 . V_328 == V_372 )
F_46 ( V_381 , V_7 |
( 0xff << V_384 ) ) ;
else
F_46 ( V_381 , V_7 |
( 32 << V_384 ) ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
if ( V_5 -> V_335 ) {
F_46 ( V_966 ,
V_5 -> V_967 . V_968 ) ;
} else {
F_46 ( V_966 , 0 ) ;
}
}
if ( F_23 ( V_5 , V_969 ) ) {
V_7 = F_33 ( V_970 ) ;
if ( ! V_5 -> V_335 )
V_7 = ( V_7 & ~ V_971 ) |
V_5 -> V_972 ;
else
V_7 |= V_971 ;
F_46 ( V_970 , V_7 ) ;
}
return V_75 ;
}
static T_6 F_236 ( struct V_4 * V_5 )
{
T_6 V_973 = F_33 ( V_974 ) ;
return V_973 | ( T_6 ) F_33 ( V_975 ) << 32 ;
}
static void F_237 ( struct V_4 * V_5 , T_6 V_976 )
{
T_1 V_977 = F_33 ( V_978 ) ;
F_46 ( V_978 , V_977 | V_979 ) ;
F_46 ( V_974 , V_976 & 0xffffffff ) ;
F_46 ( V_975 , V_976 >> 32 ) ;
F_31 ( V_978 , V_977 | V_980 ) ;
}
static int F_238 ( struct V_359 * V_111 , struct V_981 * V_982 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_982 -> V_983 = V_984 |
V_985 |
V_986 ;
if ( F_23 ( V_5 , V_987 ) ) {
V_982 -> V_983 |= V_988 |
V_989 |
V_990 ;
}
if ( V_5 -> V_991 )
V_982 -> V_992 = F_239 ( V_5 -> V_991 ) ;
else
V_982 -> V_992 = - 1 ;
V_982 -> V_993 = ( 1 << V_994 ) | ( 1 << V_995 ) ;
V_982 -> V_996 = ( 1 << V_997 ) |
( 1 << V_998 ) |
( 1 << V_999 ) |
( 1 << V_1000 ) ;
return 0 ;
}
static int F_240 ( struct V_1001 * V_1002 , T_7 V_1003 )
{
struct V_4 * V_5 = F_241 ( V_1002 , struct V_4 , V_1004 ) ;
bool V_1005 = false ;
T_1 V_1006 = 0 ;
if ( V_1003 < 0 ) {
V_1005 = true ;
V_1003 = - V_1003 ;
}
V_1006 = F_242 ( ( T_6 ) V_1003 * ( 1 << 24 ) , 1000000000ULL ) &
V_1007 ;
F_243 ( V_5 , 0 ) ;
if ( V_1006 )
F_46 ( V_1008 ,
V_1009 |
( V_1005 ? V_1010 : 0 ) | V_1006 ) ;
else
F_46 ( V_1008 , 0 ) ;
F_244 ( V_5 ) ;
return 0 ;
}
static int F_245 ( struct V_1001 * V_1002 , T_8 V_841 )
{
struct V_4 * V_5 = F_241 ( V_1002 , struct V_4 , V_1004 ) ;
F_243 ( V_5 , 0 ) ;
V_5 -> V_1011 += V_841 ;
F_244 ( V_5 ) ;
return 0 ;
}
static int F_246 ( struct V_1001 * V_1002 , struct V_1012 * V_1013 )
{
T_6 V_1014 ;
struct V_4 * V_5 = F_241 ( V_1002 , struct V_4 , V_1004 ) ;
F_243 ( V_5 , 0 ) ;
V_1014 = F_236 ( V_5 ) ;
V_1014 += V_5 -> V_1011 ;
F_244 ( V_5 ) ;
* V_1013 = F_247 ( V_1014 ) ;
return 0 ;
}
static int F_248 ( struct V_1001 * V_1002 ,
const struct V_1012 * V_1013 )
{
T_6 V_1014 ;
struct V_4 * V_5 = F_241 ( V_1002 , struct V_4 , V_1004 ) ;
V_1014 = F_249 ( V_1013 ) ;
F_243 ( V_5 , 0 ) ;
F_237 ( V_5 , V_1014 ) ;
V_5 -> V_1011 = 0 ;
F_244 ( V_5 ) ;
return 0 ;
}
static int F_250 ( struct V_1001 * V_1002 ,
struct V_1015 * V_1016 , int V_1017 )
{
struct V_4 * V_5 = F_241 ( V_1002 , struct V_4 , V_1004 ) ;
T_1 V_977 ;
int V_1018 = 0 ;
switch ( V_1016 -> type ) {
case V_1019 :
if ( V_1016 -> V_1020 . V_681 != 0 )
return - V_64 ;
F_243 ( V_5 , 0 ) ;
V_977 = F_33 ( V_978 ) ;
V_977 &= ~ V_1021 ;
if ( V_1017 ) {
T_6 V_1022 ;
V_1022 = V_1016 -> V_1020 . V_1023 . V_1024 * 1000000000ULL +
V_1016 -> V_1020 . V_1023 . V_1022 ;
if ( V_1016 -> V_1020 . V_1025 . V_1024 || V_1016 -> V_1020 . V_1025 . V_1022 ) {
F_144 ( V_5 -> V_111 ,
L_28 ) ;
V_1018 = - V_64 ;
goto V_1026;
}
if ( V_1022 & ( 1ULL << 63 ) ) {
F_144 ( V_5 -> V_111 ,
L_29 ) ;
V_1018 = - V_64 ;
goto V_1026;
}
F_46 ( V_1027 , ( V_1022 & 0xffffffff ) ) ;
F_46 ( V_1028 ,
V_1029 |
( ( V_1022 >> 32 ) & V_1030 ) ) ;
F_46 ( V_978 ,
V_977 | V_1031 ) ;
} else {
F_46 ( V_1028 , 0 ) ;
F_46 ( V_978 , V_977 ) ;
}
V_1026:
F_244 ( V_5 ) ;
return V_1018 ;
default:
break;
}
return - V_1032 ;
}
static void F_251 ( struct V_4 * V_5 , T_6 V_1033 ,
struct V_1034 * V_1035 )
{
memset ( V_1035 , 0 , sizeof( struct V_1034 ) ) ;
V_1035 -> V_1036 = F_252 ( ( V_1033 & V_1037 ) +
V_5 -> V_1011 ) ;
}
static void F_253 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_987 ) )
return;
F_237 ( V_5 , F_254 ( F_255 () ) ) ;
V_5 -> V_1011 = 0 ;
V_5 -> V_1004 = V_1038 ;
}
static void F_256 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_987 ) )
return;
F_237 ( V_5 , F_254 ( F_255 () ) + V_5 -> V_1011 ) ;
V_5 -> V_1011 = 0 ;
}
static void F_257 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_987 ) || ! V_5 -> V_991 )
return;
F_258 ( V_5 -> V_991 ) ;
V_5 -> V_991 = NULL ;
V_5 -> V_1011 = 0 ;
}
static inline int F_259 ( struct V_4 * V_5 )
{
return V_5 -> V_125 ;
}
static inline void F_260 ( struct V_4 * V_5 , T_1 * V_1039 , T_1 V_6 , T_1 V_74 )
{
int V_42 ;
V_1039 = ( T_1 * ) ( ( T_4 * ) V_1039 + V_6 ) ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += sizeof( T_1 ) )
* V_1039 ++ = F_33 ( V_6 + V_42 ) ;
}
static void F_261 ( struct V_4 * V_5 , T_1 * V_8 )
{
F_260 ( V_5 , V_8 , V_1040 , 0xb0 ) ;
F_260 ( V_5 , V_8 , V_20 , 0x200 ) ;
F_260 ( V_5 , V_8 , V_377 , 0x4f0 ) ;
F_260 ( V_5 , V_8 , V_1041 , 0xe0 ) ;
F_260 ( V_5 , V_8 , V_1042 , 0x04 ) ;
F_260 ( V_5 , V_8 , V_1043 , 0x80 ) ;
F_260 ( V_5 , V_8 , V_1044 , 0x48 ) ;
F_260 ( V_5 , V_8 , V_1045 , 0x04 ) ;
F_260 ( V_5 , V_8 , V_1046 , 0x20 ) ;
F_260 ( V_5 , V_8 , V_1047 , 0x15c ) ;
F_260 ( V_5 , V_8 , V_1048 , 0x0c ) ;
F_260 ( V_5 , V_8 , V_1049 , 0x3c ) ;
F_260 ( V_5 , V_8 , V_1050 , 0x44 ) ;
F_260 ( V_5 , V_8 , V_1051 , 0x04 ) ;
F_260 ( V_5 , V_8 , V_1052 , 0x20 ) ;
F_260 ( V_5 , V_8 , V_1053 , 0x14 ) ;
F_260 ( V_5 , V_8 , V_1054 , 0x08 ) ;
F_260 ( V_5 , V_8 , V_1055 , 0x08 ) ;
F_260 ( V_5 , V_8 , V_138 , 0x100 ) ;
if ( F_23 ( V_5 , V_1056 ) )
F_260 ( V_5 , V_8 , V_1057 , 0x180 ) ;
F_260 ( V_5 , V_8 , V_1058 , 0x10 ) ;
F_260 ( V_5 , V_8 , V_1059 , 0x58 ) ;
F_260 ( V_5 , V_8 , V_1060 , 0x08 ) ;
F_260 ( V_5 , V_8 , V_1061 , 0x08 ) ;
F_260 ( V_5 , V_8 , V_1062 , 0x04 ) ;
F_260 ( V_5 , V_8 , V_1063 , 0x04 ) ;
F_260 ( V_5 , V_8 , V_1064 , 0x04 ) ;
F_260 ( V_5 , V_8 , V_672 , 0x04 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_260 ( V_5 , V_8 , V_1065 , 0x04 ) ;
F_260 ( V_5 , V_8 , V_1066 , 0x04 ) ;
F_260 ( V_5 , V_8 , V_1067 , 0x04 ) ;
}
F_260 ( V_5 , V_8 , V_1068 , 0x110 ) ;
F_260 ( V_5 , V_8 , V_1069 , 0x120 ) ;
F_260 ( V_5 , V_8 , V_1070 , 0x0c ) ;
F_260 ( V_5 , V_8 , V_1071 , 0x04 ) ;
F_260 ( V_5 , V_8 , V_641 , 0x4c ) ;
if ( F_23 ( V_5 , V_580 ) )
F_260 ( V_5 , V_8 , V_602 , 0x24 ) ;
}
static void F_262 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 * V_8 ;
V_8 = F_263 ( V_1072 , V_1073 ) ;
if ( ! V_8 )
return;
if ( F_23 ( V_5 , V_1074 ) ) {
for ( V_42 = 0 ; V_42 < V_1075 ; V_42 += sizeof( T_1 ) )
V_8 [ V_42 / sizeof( T_1 ) ] = F_33 ( V_42 ) ;
} else
F_261 ( V_5 , V_8 ) ;
for ( V_42 = 0 ; V_42 < V_1072 / sizeof( T_1 ) ; V_42 += 4 ) {
if ( ! V_8 [ V_42 + 0 ] && ! V_8 [ V_42 + 1 ] &&
! V_8 [ V_42 + 2 ] && ! V_8 [ V_42 + 3 ] )
continue;
F_187 ( V_5 -> V_111 , L_30 ,
V_42 * 4 ,
V_8 [ V_42 + 0 ] , V_8 [ V_42 + 1 ] , V_8 [ V_42 + 2 ] , V_8 [ V_42 + 3 ] ) ;
}
F_177 ( V_8 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_187 ( V_5 -> V_111 ,
L_31 ,
V_42 ,
V_131 -> V_134 -> V_57 ,
V_131 -> V_134 -> V_1076 ,
V_131 -> V_134 -> V_1077 ,
V_131 -> V_134 -> V_1078 ,
V_131 -> V_134 -> V_1079 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_1080 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_146 ) ;
F_187 ( V_5 -> V_111 ,
L_32 ,
V_42 ,
V_131 -> V_132 , V_131 -> V_1081 ,
V_131 -> V_1082 , V_131 -> V_147 , V_131 -> V_1083 ,
V_131 -> V_149 ,
V_131 -> V_1084 . V_1085 ,
V_131 -> V_1084 . V_1086 ,
V_131 -> V_1084 . V_1087 ,
V_131 -> V_1084 . V_1088 ) ;
}
}
static void F_264 ( struct V_4 * V_5 )
{
F_186 ( F_23 ( V_5 , V_31 ) ||
V_5 -> V_1089 == F_20 ) ;
F_144 ( V_5 -> V_111 ,
L_33
L_34
L_35
L_36 ) ;
F_84 ( V_5 , V_1090 ) ;
}
static inline T_1 F_265 ( struct V_130 * V_131 )
{
F_266 () ;
return V_131 -> V_1083 -
( ( V_131 -> V_1082 - V_131 -> V_147 ) & ( V_1091 - 1 ) ) ;
}
static void F_267 ( struct V_130 * V_131 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1092 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
T_1 V_1093 = V_131 -> V_147 ;
struct V_1094 * V_1095 ;
int V_681 = V_131 - V_5 -> V_123 ;
unsigned int V_1096 = 0 , V_1097 = 0 ;
if ( F_23 ( V_5 , V_1098 ) )
V_681 -- ;
V_1095 = F_268 ( V_5 -> V_111 , V_681 ) ;
while ( V_1093 != V_1092 ) {
struct V_1099 * V_1100 = & V_131 -> V_1101 [ V_1093 ] ;
struct V_1102 * V_1103 = V_1100 -> V_1103 ;
int V_42 , V_1104 = 0 ;
if ( F_269 ( V_1103 == NULL ) ) {
F_264 ( V_5 ) ;
return;
}
if ( V_131 -> V_1105 [ V_1093 ] . V_1106 & V_1107 ) {
struct V_1034 V_1035 ;
T_6 V_1033 = F_33 ( V_1108 ) ;
V_1033 |= ( T_6 ) F_33 ( V_1109 ) << 32 ;
F_251 ( V_5 , V_1033 , & V_1035 ) ;
F_270 ( V_1103 , & V_1035 ) ;
}
F_271 ( V_5 -> V_12 ,
F_272 ( V_1100 , V_1110 ) ,
F_273 ( V_1103 ) ,
V_1111 ) ;
V_1100 -> V_1103 = NULL ;
while ( V_1100 -> V_1112 ) {
V_1100 -> V_1112 = false ;
V_1093 = F_274 ( V_1093 ) ;
V_1100 = & V_131 -> V_1101 [ V_1093 ] ;
}
V_1093 = F_274 ( V_1093 ) ;
for ( V_42 = 0 ; V_42 < F_275 ( V_1103 ) -> V_1113 ; V_42 ++ ) {
V_1100 = & V_131 -> V_1101 [ V_1093 ] ;
if ( F_269 ( V_1100 -> V_1103 != NULL || V_1093 == V_1092 ) )
V_1104 = 1 ;
F_276 ( V_5 -> V_12 ,
F_272 ( V_1100 , V_1110 ) ,
F_277 ( & F_275 ( V_1103 ) -> V_1114 [ V_42 ] ) ,
V_1111 ) ;
while ( V_1100 -> V_1112 ) {
V_1100 -> V_1112 = false ;
V_1093 = F_274 ( V_1093 ) ;
V_1100 = & V_131 -> V_1101 [ V_1093 ] ;
}
V_1093 = F_274 ( V_1093 ) ;
}
V_1096 ++ ;
V_1097 += V_1103 -> V_74 ;
F_278 ( V_1103 ) ;
if ( F_269 ( V_1104 ) ) {
F_264 ( V_5 ) ;
return;
}
}
F_279 ( V_1095 , V_1096 , V_1097 ) ;
V_131 -> V_147 = V_1093 ;
F_280 () ;
if ( F_269 ( F_281 ( V_1095 ) &&
( F_265 ( V_131 ) > F_282 ( V_131 ) ) ) ) {
F_283 ( V_1095 , F_284 () ) ;
if ( F_281 ( V_1095 ) &&
( F_265 ( V_131 ) > F_282 ( V_131 ) ) )
F_285 ( V_1095 ) ;
F_286 ( V_1095 ) ;
}
}
static void F_287 ( bool V_1115 , void * V_72 )
{
if ( V_1115 )
F_288 ( V_72 ) ;
else
F_177 ( V_72 ) ;
}
static void F_289 ( struct V_4 * V_5 , struct V_1116 * V_1100 , T_1 V_1117 )
{
unsigned int V_1118 = F_290 ( V_1117 + F_291 ( V_5 ) ) +
F_290 ( sizeof( struct V_1119 ) ) ;
if ( ! V_1100 -> V_72 )
return;
F_271 ( V_5 -> V_12 , F_272 ( V_1100 , V_1110 ) ,
V_1117 , V_1120 ) ;
F_287 ( V_1118 <= V_1121 , V_1100 -> V_72 ) ;
V_1100 -> V_72 = NULL ;
}
static int F_292 ( struct V_4 * V_5 , struct V_1122 * V_1123 ,
T_1 V_1124 , T_1 V_1125 ,
unsigned int * V_1126 )
{
struct V_1127 * V_1128 ;
struct V_1116 * V_1129 ;
T_4 * V_72 ;
T_9 V_1110 ;
int V_1118 , V_1130 , V_1131 ;
switch ( V_1124 ) {
case V_1132 :
V_1131 = V_1125 & V_5 -> V_1133 ;
V_1128 = & V_1123 -> V_1134 [ V_1131 ] ;
V_1129 = & V_1123 -> V_1135 [ V_1131 ] ;
V_1130 = V_5 -> V_1136 ;
break;
case V_1137 :
V_1131 = V_1125 & V_5 -> V_1138 ;
V_1128 = & V_1123 -> V_1139 [ V_1131 ] . V_1140 ;
V_1129 = & V_1123 -> V_1141 [ V_1131 ] ;
V_1130 = V_1142 ;
break;
default:
return - V_64 ;
}
V_1118 = F_290 ( V_1130 + F_291 ( V_5 ) ) +
F_290 ( sizeof( struct V_1119 ) ) ;
if ( V_1118 <= V_1121 ) {
V_72 = F_293 ( V_1118 ) ;
* V_1126 = V_1118 ;
} else {
V_72 = F_176 ( V_1118 , V_1073 ) ;
* V_1126 = 0 ;
}
if ( ! V_72 )
return - V_267 ;
V_1110 = F_294 ( V_5 -> V_12 ,
V_72 + F_291 ( V_5 ) ,
V_1130 ,
V_1120 ) ;
if ( F_269 ( F_295 ( V_5 -> V_12 , V_1110 ) ) ) {
F_287 ( V_1118 <= V_1121 , V_72 ) ;
return - V_210 ;
}
V_1129 -> V_72 = V_72 ;
F_296 ( V_1129 , V_1110 , V_1110 ) ;
V_1128 -> V_1143 = ( ( T_6 ) V_1110 >> 32 ) ;
V_1128 -> V_1144 = ( ( T_6 ) V_1110 & 0xffffffff ) ;
return V_1130 ;
}
static void F_297 ( struct V_130 * V_131 ,
struct V_1122 * V_1145 ,
T_1 V_1124 , int V_1146 ,
T_1 V_1125 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_1127 * V_1147 , * V_1148 ;
struct V_1116 * V_1149 , * V_1150 ;
struct V_1122 * V_1151 = & V_5 -> V_123 [ 0 ] . V_1084 ;
int V_1131 ;
switch ( V_1124 ) {
case V_1132 :
V_1131 = V_1125 & V_5 -> V_1133 ;
V_1148 = & V_1145 -> V_1134 [ V_1131 ] ;
V_1150 = & V_1145 -> V_1135 [ V_1131 ] ;
V_1147 = & V_1151 -> V_1134 [ V_1146 ] ;
V_1149 = & V_1151 -> V_1135 [ V_1146 ] ;
break;
case V_1137 :
V_1131 = V_1125 & V_5 -> V_1138 ;
V_1148 = & V_1145 -> V_1139 [ V_1131 ] . V_1140 ;
V_1150 = & V_1145 -> V_1141 [ V_1131 ] ;
V_1147 = & V_1151 -> V_1139 [ V_1146 ] . V_1140 ;
V_1149 = & V_1151 -> V_1141 [ V_1146 ] ;
break;
default:
return;
}
V_1150 -> V_72 = V_1149 -> V_72 ;
F_296 ( V_1150 , V_1110 ,
F_272 ( V_1149 , V_1110 ) ) ;
V_1148 -> V_1143 = V_1147 -> V_1143 ;
V_1148 -> V_1144 = V_1147 -> V_1144 ;
F_298 () ;
V_1149 -> V_72 = NULL ;
}
static int F_299 ( struct V_130 * V_131 , int V_1152 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1153 , V_1154 = 0 ;
T_1 V_1155 , V_1156 ;
T_1 V_1093 = V_131 -> V_149 ;
T_3 V_1092 ;
int V_1157 ;
struct V_1122 * V_1123 = & V_131 -> V_1084 ;
V_1092 = * ( V_131 -> V_148 ) ;
F_300 () ;
V_1153 = 0 ;
V_1157 = 0 ;
V_1155 = V_1123 -> V_1085 ;
V_1156 = V_1123 -> V_1087 ;
while ( V_1093 != V_1092 && V_1152 > 0 ) {
struct V_1116 * V_1100 ;
struct V_1127 * V_1128 = & V_131 -> V_1158 [ V_1093 ] ;
unsigned int V_74 ;
struct V_1102 * V_1103 ;
T_9 V_1159 ;
T_1 V_1124 , V_1160 , * V_1161 ;
T_4 * V_72 ;
T_6 V_1162 = 0 ;
V_1160 = V_1128 -> V_1163 & V_1164 ;
V_1124 = V_1128 -> V_1163 & V_1165 ;
if ( V_1124 == V_1132 ) {
V_1100 = & V_5 -> V_123 [ 0 ] . V_1084 . V_1135 [ V_1160 ] ;
V_1159 = F_272 ( V_1100 , V_1110 ) ;
V_72 = V_1100 -> V_72 ;
V_1161 = & V_1155 ;
V_1154 ++ ;
} else if ( V_1124 == V_1137 ) {
V_1100 = & V_5 -> V_123 [ 0 ] . V_1084 . V_1141 [ V_1160 ] ;
V_1159 = F_272 ( V_1100 , V_1110 ) ;
V_72 = V_1100 -> V_72 ;
V_1161 = & V_1156 ;
} else
goto V_1166;
V_1153 |= V_1124 ;
if ( V_1128 -> V_1167 & V_1168 ) {
V_1169:
F_297 ( V_131 , V_1123 , V_1124 ,
V_1160 , * V_1161 ) ;
V_1170:
V_5 -> V_1171 ++ ;
goto V_1172;
}
F_301 ( V_72 + F_291 ( V_5 ) ) ;
V_74 = ( ( V_1128 -> V_1173 & V_1174 ) >> V_1175 ) -
V_1176 ;
if ( ( V_1128 -> V_1177 & V_1178 ) ==
V_1179 ||
( V_1128 -> V_1177 & V_1178 ) ==
V_1180 ) {
V_1162 = F_33 ( V_1181 ) ;
V_1162 |= ( T_6 ) F_33 ( V_1182 ) << 32 ;
}
if ( V_74 > F_302 ( V_5 ) ) {
int V_1118 ;
unsigned int V_1126 ;
V_1118 = F_292 ( V_5 , V_1123 , V_1124 ,
* V_1161 , & V_1126 ) ;
if ( V_1118 < 0 )
goto V_1169;
F_271 ( V_5 -> V_12 , V_1159 , V_1118 ,
V_1120 ) ;
F_298 () ;
V_1100 -> V_72 = NULL ;
V_1103 = F_303 ( V_72 , V_1126 ) ;
if ( ! V_1103 ) {
F_287 ( V_1126 != 0 , V_72 ) ;
goto V_1170;
}
F_304 ( V_1103 , F_291 ( V_5 ) ) ;
} else {
F_297 ( V_131 , V_1123 , V_1124 ,
V_1160 , * V_1161 ) ;
V_1103 = F_305 ( V_5 -> V_111 ,
V_74 + V_1183 ) ;
if ( V_1103 == NULL )
goto V_1170;
F_304 ( V_1103 , V_1183 ) ;
F_306 ( V_5 -> V_12 , V_1159 , V_74 , V_1120 ) ;
memcpy ( V_1103 -> V_72 ,
V_72 + F_291 ( V_5 ) ,
V_74 ) ;
F_307 ( V_5 -> V_12 , V_1159 , V_74 , V_1120 ) ;
}
F_308 ( V_1103 , V_74 ) ;
if ( V_1162 )
F_251 ( V_5 , V_1162 ,
F_309 ( V_1103 ) ) ;
if ( ( V_5 -> V_111 -> V_1184 & V_1185 ) &&
( V_1128 -> V_1177 & V_1186 ) &&
( ( ( V_1128 -> V_1187 & V_1188 )
>> V_1189 ) == 0xffff ) )
V_1103 -> V_1190 = V_1191 ;
else
F_310 ( V_1103 ) ;
V_1103 -> V_1192 = F_311 ( V_1103 , V_5 -> V_111 ) ;
if ( V_74 > ( V_5 -> V_111 -> V_1193 + V_1194 ) &&
V_1103 -> V_1192 != F_312 ( V_1195 ) &&
V_1103 -> V_1192 != F_312 ( V_1196 ) ) {
F_278 ( V_1103 ) ;
goto V_1170;
}
if ( V_1128 -> V_1177 & V_1197 &&
! ( V_5 -> V_349 & V_1198 ) )
F_313 ( V_1103 , F_312 ( V_1195 ) ,
V_1128 -> V_1167 & V_1199 ) ;
F_314 ( & V_131 -> V_123 , V_1103 ) ;
V_1157 ++ ;
V_1152 -- ;
V_1172:
( * V_1161 ) ++ ;
if ( F_269 ( V_1154 >= V_5 -> V_1200 ) ) {
V_1123 -> V_1085 = V_1155 &
V_5 -> V_1133 ;
F_315 ( V_18 ,
V_1123 -> V_1085 ) ;
V_1153 &= ~ V_1132 ;
V_1154 = 0 ;
}
V_1166:
V_1093 ++ ;
V_1093 &= V_5 -> V_1201 ;
if ( V_1093 == V_1092 ) {
V_1092 = * ( V_131 -> V_148 ) ;
F_300 () ;
}
}
V_131 -> V_149 = V_1093 ;
F_315 ( V_131 -> V_1202 , V_1093 ) ;
if ( ! F_23 ( V_5 , V_1203 ) ) {
F_49 () ;
if ( V_1153 & V_1132 ) {
V_1123 -> V_1085 = V_1155 &
V_5 -> V_1133 ;
F_315 ( V_18 ,
V_1123 -> V_1085 ) ;
}
if ( V_1153 & V_1137 ) {
V_1123 -> V_1087 = V_1156 &
V_5 -> V_1138 ;
F_315 ( V_1204 ,
V_1123 -> V_1087 ) ;
}
F_53 () ;
} else if ( V_1153 ) {
F_298 () ;
V_1123 -> V_1085 = V_1155 & V_5 -> V_1133 ;
V_1123 -> V_1087 = V_1156 & V_5 -> V_1138 ;
if ( V_131 != & V_5 -> V_123 [ 1 ] ) {
V_5 -> V_1205 = true ;
F_316 ( & V_5 -> V_123 [ 1 ] . V_123 ) ;
}
}
return V_1157 ;
}
static void F_317 ( struct V_4 * V_5 )
{
if ( ! ( F_23 ( V_5 , V_142 ) || F_23 ( V_5 , V_143 ) ) ) {
struct V_139 * V_140 = V_5 -> V_123 [ 0 ] . V_134 ;
if ( V_140 -> V_57 & V_144 ) {
V_140 -> V_57 = V_135 |
( V_140 -> V_57 & ~ V_144 ) ;
F_318 ( & V_5 -> V_209 ) ;
if ( F_23 ( V_5 , V_266 ) ) {
F_31 ( V_787 ,
( V_788 |
V_789 |
V_790 |
V_791 ) ) ;
F_24 ( 40 ) ;
} else
F_203 ( V_5 , false ) ;
F_319 ( & V_5 -> V_209 ) ;
}
}
}
static int F_320 ( struct V_4 * V_5 ,
struct V_1122 * V_1145 ,
struct V_1122 * V_1151 )
{
T_1 V_1206 , V_1207 , V_1208 , V_1209 ;
int V_42 , V_75 = 0 ;
while ( 1 ) {
V_1209 = V_1151 -> V_1085 ;
F_321 () ;
if ( V_1151 -> V_1086 == V_1209 )
break;
if ( V_1151 -> V_1086 < V_1209 )
V_1208 = V_1209 - V_1151 -> V_1086 ;
else
V_1208 = V_5 -> V_1133 + 1 -
V_1151 -> V_1086 ;
V_1208 = F_322 ( V_1208 ,
V_5 -> V_1133 + 1 - V_1145 -> V_1085 ) ;
V_1206 = V_1151 -> V_1086 ;
V_1207 = V_1145 -> V_1085 ;
for ( V_42 = V_1207 ; V_42 < V_1207 + V_1208 ; V_42 ++ ) {
if ( V_1145 -> V_1135 [ V_42 ] . V_72 ) {
V_1208 = V_42 - V_1207 ;
V_75 = - V_1210 ;
break;
}
}
if ( ! V_1208 )
break;
F_321 () ;
memcpy ( & V_1145 -> V_1135 [ V_1207 ] ,
& V_1151 -> V_1135 [ V_1206 ] ,
V_1208 * sizeof( struct V_1116 ) ) ;
for ( V_42 = 0 ; V_42 < V_1208 ; V_42 ++ , V_1207 ++ , V_1206 ++ ) {
struct V_1127 * V_1211 , * V_1212 ;
V_1211 = & V_1151 -> V_1134 [ V_1206 ] ;
V_1212 = & V_1145 -> V_1134 [ V_1207 ] ;
V_1212 -> V_1143 = V_1211 -> V_1143 ;
V_1212 -> V_1144 = V_1211 -> V_1144 ;
}
V_1151 -> V_1086 = ( V_1151 -> V_1086 + V_1208 ) &
V_5 -> V_1133 ;
V_1145 -> V_1085 = ( V_1145 -> V_1085 + V_1208 ) &
V_5 -> V_1133 ;
}
while ( 1 ) {
V_1209 = V_1151 -> V_1087 ;
F_321 () ;
if ( V_1151 -> V_1088 == V_1209 )
break;
if ( V_1151 -> V_1088 < V_1209 )
V_1208 = V_1209 - V_1151 -> V_1088 ;
else
V_1208 = V_5 -> V_1138 + 1 -
V_1151 -> V_1088 ;
V_1208 = F_322 ( V_1208 ,
V_5 -> V_1138 + 1 - V_1145 -> V_1087 ) ;
V_1206 = V_1151 -> V_1088 ;
V_1207 = V_1145 -> V_1087 ;
for ( V_42 = V_1207 ; V_42 < V_1207 + V_1208 ; V_42 ++ ) {
if ( V_1145 -> V_1141 [ V_42 ] . V_72 ) {
V_1208 = V_42 - V_1207 ;
V_75 = - V_1210 ;
break;
}
}
if ( ! V_1208 )
break;
F_321 () ;
memcpy ( & V_1145 -> V_1141 [ V_1207 ] ,
& V_1151 -> V_1141 [ V_1206 ] ,
V_1208 * sizeof( struct V_1116 ) ) ;
for ( V_42 = 0 ; V_42 < V_1208 ; V_42 ++ , V_1207 ++ , V_1206 ++ ) {
struct V_1127 * V_1211 , * V_1212 ;
V_1211 = & V_1151 -> V_1139 [ V_1206 ] . V_1140 ;
V_1212 = & V_1145 -> V_1139 [ V_1207 ] . V_1140 ;
V_1212 -> V_1143 = V_1211 -> V_1143 ;
V_1212 -> V_1144 = V_1211 -> V_1144 ;
}
V_1151 -> V_1088 = ( V_1151 -> V_1088 + V_1208 ) &
V_5 -> V_1138 ;
V_1145 -> V_1087 = ( V_1145 -> V_1087 + V_1208 ) &
V_5 -> V_1138 ;
}
return V_75 ;
}
static int F_323 ( struct V_130 * V_131 , int V_1213 , int V_1152 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
if ( V_131 -> V_134 -> V_145 [ 0 ] . V_146 != V_131 -> V_147 ) {
F_267 ( V_131 ) ;
if ( F_269 ( F_23 ( V_5 , V_1090 ) ) )
return V_1213 ;
}
if ( ! V_131 -> V_148 )
return V_1213 ;
if ( * ( V_131 -> V_148 ) != V_131 -> V_149 )
V_1213 += F_299 ( V_131 , V_1152 - V_1213 ) ;
if ( F_23 ( V_5 , V_1203 ) && V_131 == & V_5 -> V_123 [ 1 ] ) {
struct V_1122 * V_1145 = & V_5 -> V_123 [ 0 ] . V_1084 ;
int V_42 , V_75 = 0 ;
T_1 V_1155 = V_1145 -> V_1085 ;
T_1 V_1156 = V_1145 -> V_1087 ;
V_5 -> V_1205 = false ;
for ( V_42 = 1 ; V_42 <= V_5 -> V_1214 ; V_42 ++ )
V_75 |= F_320 ( V_5 , V_1145 ,
& V_5 -> V_123 [ V_42 ] . V_1084 ) ;
F_49 () ;
if ( V_1155 != V_1145 -> V_1085 )
F_315 ( V_18 ,
V_1145 -> V_1085 ) ;
if ( V_1156 != V_1145 -> V_1087 )
F_315 ( V_1204 ,
V_1145 -> V_1087 ) ;
F_53 () ;
if ( V_75 )
F_31 ( V_138 , V_5 -> V_126 ) ;
}
return V_1213 ;
}
static inline void F_324 ( struct V_4 * V_5 )
{
if ( ! F_325 ( V_1215 , V_5 -> V_1216 ) )
F_326 ( & V_5 -> V_1217 ) ;
}
static inline void F_327 ( struct V_4 * V_5 )
{
F_328 ( & V_5 -> V_1217 ) ;
F_86 ( V_5 , V_1218 ) ;
F_86 ( V_5 , V_1090 ) ;
}
static int F_329 ( struct V_1219 * V_123 , int V_1152 )
{
struct V_130 * V_131 = F_241 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1213 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
V_1213 = F_323 ( V_131 , V_1213 , V_1152 ) ;
if ( F_269 ( F_23 ( V_5 , V_1090 ) ) )
goto V_1220;
if ( F_269 ( V_1213 >= V_1152 ) )
break;
V_131 -> V_132 = V_140 -> V_1076 ;
V_131 -> V_1081 = V_131 -> V_132 ;
F_300 () ;
if ( F_330 ( V_140 -> V_145 [ 0 ] . V_146 == V_131 -> V_147 &&
* ( V_131 -> V_148 ) == V_131 -> V_149 ) ) {
if ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1205 )
continue;
F_331 ( V_123 , V_1213 ) ;
F_52 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
if ( F_269 ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1205 ) ) {
F_46 ( V_138 , V_5 -> V_127 |
V_128 |
V_131 -> V_126 ) ;
}
F_53 () ;
break;
}
}
return V_1213 ;
V_1220:
F_332 ( V_123 ) ;
F_324 ( V_5 ) ;
return V_1213 ;
}
static void F_333 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_1221 = false ;
if ( F_23 ( V_5 , V_1222 ) )
return;
V_7 = F_33 ( V_1223 ) ;
if ( V_7 & ~ V_1224 ) {
F_187 ( V_5 -> V_111 , L_37 ) ;
V_1221 = true ;
}
if ( F_33 ( V_1225 ) & ~ V_1226 ) {
F_187 ( V_5 -> V_111 , L_38 ) ;
V_1221 = true ;
}
if ( F_33 ( V_1227 ) || F_33 ( V_1228 ) ) {
F_187 ( V_5 -> V_111 , L_39 ) ;
V_1221 = true ;
}
if ( ! V_1221 )
return;
F_262 ( V_5 ) ;
F_84 ( V_5 , V_1222 ) ;
F_324 ( V_5 ) ;
}
static int F_334 ( struct V_1219 * V_123 , int V_1152 )
{
struct V_130 * V_131 = F_241 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1213 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
if ( V_140 -> V_57 & V_1229 )
F_333 ( V_5 ) ;
F_317 ( V_5 ) ;
V_1213 = F_323 ( V_131 , V_1213 , V_1152 ) ;
if ( F_269 ( F_23 ( V_5 , V_1090 ) ) )
goto V_1220;
if ( F_269 ( V_1213 >= V_1152 ) )
break;
if ( F_23 ( V_5 , V_133 ) ) {
V_131 -> V_132 = V_140 -> V_1076 ;
V_131 -> V_1081 = V_131 -> V_132 ;
F_300 () ;
} else
V_140 -> V_57 &= ~ V_135 ;
if ( F_330 ( ! F_50 ( V_131 ) ) ) {
F_331 ( V_123 , V_1213 ) ;
F_51 ( V_131 ) ;
break;
}
}
return V_1213 ;
V_1220:
F_332 ( V_123 ) ;
F_324 ( V_5 ) ;
return V_1213 ;
}
static void F_335 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- )
F_336 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static void F_337 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_338 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static void F_339 ( struct V_4 * V_5 )
{
int V_42 ;
F_340 ( V_5 -> V_111 , & V_5 -> V_123 [ 0 ] . V_123 , F_334 , 64 ) ;
for ( V_42 = 1 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_340 ( V_5 -> V_111 , & V_5 -> V_123 [ V_42 ] . V_123 , F_329 , 64 ) ;
}
static void F_341 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_342 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static inline void F_343 ( struct V_4 * V_5 )
{
F_344 ( V_5 -> V_111 ) ;
F_335 ( V_5 ) ;
F_142 ( V_5 -> V_111 ) ;
F_345 ( V_5 -> V_111 ) ;
}
static inline void F_346 ( struct V_4 * V_5 )
{
F_256 ( V_5 ) ;
F_347 ( V_5 -> V_111 ) ;
if ( V_5 -> V_335 )
F_222 ( V_5 -> V_111 ) ;
F_337 ( V_5 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 |= V_135 ;
F_48 ( V_5 ) ;
}
static void F_348 ( struct V_4 * V_5 )
__releases( V_5 -> V_209 )
__acquires( V_5 -> V_209 )
{
int V_42 ;
F_186 ( V_5 -> V_125 ) ;
V_5 -> V_125 = 1 ;
F_280 () ;
F_71 ( & V_5 -> V_209 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_349 ( V_5 -> V_123 [ V_42 ] . V_1230 ) ;
F_70 ( & V_5 -> V_209 ) ;
}
static inline void F_243 ( struct V_4 * V_5 , int V_125 )
{
F_70 ( & V_5 -> V_209 ) ;
if ( V_125 )
F_348 ( V_5 ) ;
}
static inline void F_244 ( struct V_4 * V_5 )
{
F_71 ( & V_5 -> V_209 ) ;
}
static T_10 F_350 ( int V_1231 , void * V_1232 )
{
struct V_130 * V_131 = V_1232 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_301 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1158 )
F_301 ( & V_131 -> V_1158 [ V_131 -> V_149 ] ) ;
if ( F_330 ( ! F_259 ( V_5 ) ) )
F_316 ( & V_131 -> V_123 ) ;
return V_1233 ;
}
static T_10 F_351 ( int V_1231 , void * V_1232 )
{
struct V_130 * V_131 = V_1232 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_301 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1158 )
F_301 ( & V_131 -> V_1158 [ V_131 -> V_149 ] ) ;
F_52 ( V_131 -> V_124 , 0x00000001 ) ;
if ( F_330 ( ! F_259 ( V_5 ) ) )
F_316 ( & V_131 -> V_123 ) ;
return F_352 ( 1 ) ;
}
static T_10 F_353 ( int V_1231 , void * V_1232 )
{
struct V_130 * V_131 = V_1232 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1234 = 1 ;
if ( F_269 ( ! ( V_140 -> V_57 & V_135 ) ) ) {
if ( F_23 ( V_5 , V_1235 ) ||
( F_33 ( V_1236 ) & V_1237 ) ) {
V_1234 = 0 ;
goto V_497;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
if ( F_259 ( V_5 ) )
goto V_497;
V_140 -> V_57 &= ~ V_135 ;
if ( F_330 ( F_50 ( V_131 ) ) ) {
F_301 ( & V_131 -> V_1158 [ V_131 -> V_149 ] ) ;
F_316 ( & V_131 -> V_123 ) ;
} else {
F_47 ( V_20 + V_16 ,
0x00000000 ) ;
}
V_497:
return F_352 ( V_1234 ) ;
}
static T_10 F_354 ( int V_1231 , void * V_1232 )
{
struct V_130 * V_131 = V_1232 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1234 = 1 ;
if ( F_269 ( V_140 -> V_1076 == V_131 -> V_1081 ) ) {
if ( F_23 ( V_5 , V_1235 ) ||
( F_33 ( V_1236 ) & V_1237 ) ) {
V_1234 = 0 ;
goto V_497;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
V_131 -> V_1081 = V_140 -> V_1076 ;
if ( F_259 ( V_5 ) )
goto V_497;
F_301 ( & V_131 -> V_1158 [ V_131 -> V_149 ] ) ;
F_316 ( & V_131 -> V_123 ) ;
V_497:
return F_352 ( V_1234 ) ;
}
static T_10 F_355 ( int V_1231 , void * V_1232 )
{
struct V_130 * V_131 = V_1232 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
if ( ( V_140 -> V_57 & V_135 ) ||
! ( F_33 ( V_1236 ) & V_1237 ) ) {
F_45 ( V_5 ) ;
return F_352 ( 1 ) ;
}
return F_352 ( 0 ) ;
}
static void F_356 ( struct V_359 * V_111 )
{
int V_42 ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_259 ( V_5 ) )
return;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_353 ( V_5 -> V_123 [ V_42 ] . V_1230 , & V_5 -> V_123 [ V_42 ] ) ;
}
static void F_357 ( struct V_359 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_358 ( V_5 ) ) {
F_187 ( V_111 , L_40 ) ;
F_262 ( V_5 ) ;
}
F_324 ( V_5 ) ;
}
static inline int F_359 ( T_9 V_1110 , int V_74 )
{
T_1 V_1238 = ( T_1 ) V_1110 & 0xffffffff ;
return V_1238 + V_74 + 8 < V_1238 ;
}
static inline int F_360 ( struct V_4 * V_5 , T_9 V_1110 ,
T_1 V_74 , T_1 V_1239 )
{
if ( F_30 ( V_5 ) == V_762 && V_1239 ) {
T_1 V_1238 = ( T_1 ) V_1110 & 0xffffffff ;
return ( ( V_1238 + V_74 + ( V_1239 & 0x3fff ) ) < V_1238 ) ;
}
return 0 ;
}
static inline int F_361 ( struct V_4 * V_5 , T_9 V_1110 ,
int V_74 )
{
#if F_362 ( V_1240 ) && ( V_1241 == 64 )
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) )
return ( ( T_6 ) V_1110 + V_74 ) > F_363 ( 40 ) ;
return 0 ;
#else
return 0 ;
#endif
}
static inline void F_364 ( struct V_1242 * V_1243 ,
T_9 V_1110 , T_1 V_74 , T_1 V_10 ,
T_1 V_1239 , T_1 V_1244 )
{
V_1243 -> V_1143 = ( ( T_6 ) V_1110 >> 32 ) ;
V_1243 -> V_1144 = ( ( T_6 ) V_1110 & 0xffffffff ) ;
V_1243 -> V_1106 = ( V_74 << V_1245 ) | ( V_10 & 0x0000ffff ) ;
V_1243 -> V_1246 = ( V_1239 << V_1247 ) | ( V_1244 << V_1248 ) ;
}
static bool F_365 ( struct V_130 * V_131 , T_1 * V_1249 , T_1 * V_1152 ,
T_9 V_1129 , T_1 V_74 , T_1 V_10 ,
T_1 V_1239 , T_1 V_1244 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
bool V_1250 = false ;
if ( F_23 ( V_5 , V_1251 ) && V_74 <= 8 )
V_1250 = true ;
if ( F_359 ( V_1129 , V_74 ) )
V_1250 = true ;
if ( F_360 ( V_5 , V_1129 , V_74 , V_1239 ) )
V_1250 = true ;
if ( F_361 ( V_5 , V_1129 , V_74 ) )
V_1250 = true ;
if ( V_5 -> V_1252 ) {
T_1 V_1253 = * V_1249 ;
T_1 V_1254 = V_10 & ~ V_1255 ;
while ( V_74 > V_5 -> V_1252 && * V_1152 ) {
T_1 V_1256 = V_5 -> V_1252 ;
V_74 -= V_5 -> V_1252 ;
if ( V_74 <= 8 ) {
V_74 += V_5 -> V_1252 / 2 ;
V_1256 = V_5 -> V_1252 / 2 ;
}
V_131 -> V_1101 [ * V_1249 ] . V_1112 = true ;
F_364 ( & V_131 -> V_1105 [ * V_1249 ] , V_1129 ,
V_1256 , V_1254 , V_1239 , V_1244 ) ;
* V_1152 -= 1 ;
V_1253 = * V_1249 ;
* V_1249 = F_274 ( * V_1249 ) ;
V_1129 += V_1256 ;
}
if ( V_74 ) {
if ( * V_1152 ) {
F_364 ( & V_131 -> V_1105 [ * V_1249 ] , V_1129 ,
V_74 , V_10 , V_1239 , V_1244 ) ;
* V_1152 -= 1 ;
* V_1249 = F_274 ( * V_1249 ) ;
} else {
V_1250 = true ;
V_131 -> V_1101 [ V_1253 ] . V_1112 = false ;
}
}
} else {
F_364 ( & V_131 -> V_1105 [ * V_1249 ] , V_1129 ,
V_74 , V_10 , V_1239 , V_1244 ) ;
* V_1249 = F_274 ( * V_1249 ) ;
}
return V_1250 ;
}
static void F_366 ( struct V_130 * V_131 , T_1 V_1249 , int V_1257 )
{
int V_42 ;
struct V_1102 * V_1103 ;
struct V_1099 * V_1258 = & V_131 -> V_1101 [ V_1249 ] ;
V_1103 = V_1258 -> V_1103 ;
V_1258 -> V_1103 = NULL ;
F_271 ( V_131 -> V_5 -> V_12 ,
F_272 ( V_1258 , V_1110 ) ,
F_273 ( V_1103 ) ,
V_1111 ) ;
while ( V_1258 -> V_1112 ) {
V_1258 -> V_1112 = false ;
V_1249 = F_274 ( V_1249 ) ;
V_1258 = & V_131 -> V_1101 [ V_1249 ] ;
}
for ( V_42 = 0 ; V_42 <= V_1257 ; V_42 ++ ) {
const T_11 * V_1259 = & F_275 ( V_1103 ) -> V_1114 [ V_42 ] ;
V_1249 = F_274 ( V_1249 ) ;
V_1258 = & V_131 -> V_1101 [ V_1249 ] ;
F_276 ( V_131 -> V_5 -> V_12 ,
F_272 ( V_1258 , V_1110 ) ,
F_277 ( V_1259 ) , V_1111 ) ;
while ( V_1258 -> V_1112 ) {
V_1258 -> V_1112 = false ;
V_1249 = F_274 ( V_1249 ) ;
V_1258 = & V_131 -> V_1101 [ V_1249 ] ;
}
}
}
static int F_367 ( struct V_130 * V_131 ,
struct V_1102 * * V_1260 ,
T_1 * V_1249 , T_1 * V_1152 ,
T_1 V_1261 , T_1 V_1239 , T_1 V_1244 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_1102 * V_1262 , * V_1103 = * V_1260 ;
T_9 V_1263 = 0 ;
int V_56 = 0 ;
if ( F_30 ( V_5 ) != V_532 )
V_1262 = F_368 ( V_1103 , V_1073 ) ;
else {
int V_1264 = 4 - ( ( unsigned long ) V_1103 -> V_72 & 3 ) ;
V_1262 = F_369 ( V_1103 ,
F_370 ( V_1103 ) + V_1264 ,
F_371 ( V_1103 ) , V_1073 ) ;
}
if ( ! V_1262 ) {
V_56 = - 1 ;
} else {
V_1263 = F_294 ( V_5 -> V_12 , V_1262 -> V_72 , V_1262 -> V_74 ,
V_1111 ) ;
if ( F_295 ( V_5 -> V_12 , V_1263 ) ) {
F_278 ( V_1262 ) ;
V_56 = - 1 ;
} else {
T_1 V_1265 = * V_1249 ;
V_1261 |= V_1255 ;
V_131 -> V_1101 [ * V_1249 ] . V_1103 = V_1262 ;
F_296 ( & V_131 -> V_1101 [ * V_1249 ] ,
V_1110 , V_1263 ) ;
if ( F_365 ( V_131 , V_1249 , V_1152 , V_1263 ,
V_1262 -> V_74 , V_1261 ,
V_1239 , V_1244 ) ) {
F_366 ( V_131 , V_1265 , - 1 ) ;
F_278 ( V_1262 ) ;
V_56 = - 1 ;
}
}
}
F_278 ( V_1103 ) ;
* V_1260 = V_1262 ;
return V_56 ;
}
static bool F_372 ( struct V_130 * V_131 , struct V_1102 * V_1103 )
{
return F_275 ( V_1103 ) -> V_1266 < V_131 -> V_1083 / 3 ;
}
static int F_373 ( struct V_4 * V_5 , struct V_130 * V_131 ,
struct V_1094 * V_1095 , struct V_1102 * V_1103 )
{
struct V_1102 * V_1267 , * V_1268 ;
T_1 V_1269 = F_275 ( V_1103 ) -> V_1266 * 3 ;
if ( F_269 ( F_265 ( V_131 ) <= V_1269 ) ) {
F_374 ( V_1095 ) ;
F_280 () ;
if ( F_265 ( V_131 ) <= V_1269 )
return V_1270 ;
F_285 ( V_1095 ) ;
}
V_1267 = F_375 ( V_1103 , V_5 -> V_111 -> V_1184 &
~ ( V_1271 | V_1272 ) ) ;
if ( F_116 ( V_1267 ) || ! V_1267 )
goto V_1273;
do {
V_1268 = V_1267 ;
V_1267 = V_1267 -> V_1274 ;
V_1268 -> V_1274 = NULL ;
F_376 ( V_1268 , V_5 -> V_111 ) ;
} while ( V_1267 );
V_1273:
F_278 ( V_1103 ) ;
return V_1275 ;
}
static T_12 F_376 ( struct V_1102 * V_1103 , struct V_359 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_74 , V_1249 , V_1261 , V_1239 , V_1244 = 0 ;
T_1 V_1152 ;
int V_42 = - 1 , V_1276 ;
T_9 V_1110 ;
struct V_130 * V_131 ;
struct V_1094 * V_1095 ;
unsigned int V_1257 ;
struct V_1277 * V_1278 = NULL ;
struct V_1279 * V_1280 = NULL ;
T_13 V_1281 = 0 , V_1282 = 0 ;
T_14 V_1283 = 0 ;
V_1095 = F_268 ( V_111 , F_377 ( V_1103 ) ) ;
V_131 = & V_5 -> V_123 [ F_377 ( V_1103 ) ] ;
if ( F_23 ( V_5 , V_1098 ) )
V_131 ++ ;
V_1152 = F_265 ( V_131 ) ;
if ( F_269 ( V_1152 <= ( F_275 ( V_1103 ) -> V_1113 + 1 ) ) ) {
if ( ! F_281 ( V_1095 ) ) {
F_374 ( V_1095 ) ;
F_187 ( V_111 ,
L_41 ) ;
}
return V_1270 ;
}
V_1249 = V_131 -> V_1082 ;
V_1261 = 0 ;
V_1239 = F_275 ( V_1103 ) -> V_1284 ;
if ( V_1239 ) {
T_1 V_1285 , V_1286 ;
if ( F_378 ( V_1103 , 0 ) )
goto V_1287;
V_1278 = F_379 ( V_1103 ) ;
V_1285 = F_380 ( V_1103 ) ;
V_1286 = F_381 ( V_1103 ) + F_382 ( V_1103 ) - V_1194 ;
if ( V_1103 -> V_1192 == F_312 ( V_1195 ) ||
V_1103 -> V_1192 == F_312 ( V_1196 ) ) {
if ( F_372 ( V_131 , V_1103 ) )
return F_373 ( V_5 , V_131 , V_1095 , V_1103 ) ;
goto V_1287;
}
if ( ! F_383 ( V_1103 ) ) {
if ( F_269 ( ( V_1194 + V_1286 ) > 80 ) &&
F_23 ( V_5 , V_1288 ) ) {
if ( F_372 ( V_131 , V_1103 ) )
return F_373 ( V_5 , V_131 , V_1095 , V_1103 ) ;
goto V_1287;
}
V_1282 = V_1278 -> V_1289 ;
V_1283 = V_1278 -> V_1290 ;
V_1278 -> V_1289 = 0 ;
V_1278 -> V_1290 = F_312 ( V_1239 + V_1286 ) ;
}
V_1261 |= ( V_1291 |
V_1292 ) ;
V_1280 = F_384 ( V_1103 ) ;
V_1281 = V_1280 -> V_1289 ;
if ( F_23 ( V_5 , V_1293 ) ||
F_23 ( V_5 , V_1294 ) ||
F_23 ( V_5 , V_1295 ) ) {
V_1280 -> V_1289 = 0 ;
V_1261 &= ~ V_1296 ;
} else {
V_1280 -> V_1289 = ~ F_385 ( V_1278 -> V_1297 , V_1278 -> V_1298 ,
0 , V_1299 , 0 ) ;
}
if ( F_23 ( V_5 , V_1295 ) ) {
V_1239 |= ( V_1286 & 0xc ) << 12 ;
if ( V_1286 & 0x10 )
V_1261 |= 0x00000010 ;
V_1261 |= ( V_1286 & 0x3e0 ) << 5 ;
} else if ( F_23 ( V_5 , V_1294 ) )
V_1239 |= V_1286 << 9 ;
else if ( F_23 ( V_5 , V_1293 ) ||
F_30 ( V_5 ) == V_496 ) {
if ( V_1285 || V_1278 -> V_1300 > 5 ) {
int V_1301 ;
V_1301 = ( V_1278 -> V_1300 - 5 ) + ( V_1285 >> 2 ) ;
V_1239 |= ( V_1301 << 11 ) ;
}
} else {
if ( V_1285 || V_1278 -> V_1300 > 5 ) {
int V_1301 ;
V_1301 = ( V_1278 -> V_1300 - 5 ) + ( V_1285 >> 2 ) ;
V_1261 |= V_1301 << 12 ;
}
}
} else if ( V_1103 -> V_1190 == V_1302 ) {
if ( V_1103 -> V_1192 == F_312 ( V_1195 ) ||
V_1103 -> V_1192 == F_312 ( V_1196 ) ) {
if ( F_386 ( V_1103 ) )
goto V_1287;
} else {
V_1261 |= V_1296 ;
}
}
if ( F_23 ( V_5 , V_1303 ) &&
! V_1239 && V_1103 -> V_74 > V_1304 )
V_1261 |= V_1305 ;
if ( F_387 ( V_1103 ) ) {
V_1261 |= V_1306 ;
V_1244 = F_388 ( V_1103 ) ;
}
if ( ( F_269 ( F_275 ( V_1103 ) -> V_1307 & V_1308 ) ) &&
F_23 ( V_5 , V_1309 ) ) {
F_275 ( V_1103 ) -> V_1307 |= V_1310 ;
V_1261 |= V_1107 ;
}
V_74 = F_273 ( V_1103 ) ;
V_1110 = F_294 ( V_5 -> V_12 , V_1103 -> V_72 , V_74 , V_1111 ) ;
if ( F_295 ( V_5 -> V_12 , V_1110 ) )
goto V_1287;
V_131 -> V_1101 [ V_1249 ] . V_1103 = V_1103 ;
F_296 ( & V_131 -> V_1101 [ V_1249 ] , V_1110 , V_1110 ) ;
V_1276 = 0 ;
if ( F_23 ( V_5 , 5701_DMA_BUG ) )
V_1276 = 1 ;
if ( F_365 ( V_131 , & V_1249 , & V_1152 , V_1110 , V_74 , V_1261 |
( ( F_275 ( V_1103 ) -> V_1113 == 0 ) ? V_1255 : 0 ) ,
V_1239 , V_1244 ) ) {
V_1276 = 1 ;
} else if ( F_275 ( V_1103 ) -> V_1113 > 0 ) {
T_1 V_1311 = V_1239 ;
if ( ! F_23 ( V_5 , V_1293 ) &&
! F_23 ( V_5 , V_1294 ) &&
! F_23 ( V_5 , V_1295 ) )
V_1311 = 0 ;
V_1257 = F_275 ( V_1103 ) -> V_1113 - 1 ;
for ( V_42 = 0 ; V_42 <= V_1257 ; V_42 ++ ) {
T_11 * V_1259 = & F_275 ( V_1103 ) -> V_1114 [ V_42 ] ;
V_74 = F_277 ( V_1259 ) ;
V_1110 = F_389 ( & V_5 -> V_12 -> V_111 , V_1259 , 0 ,
V_74 , V_1312 ) ;
V_131 -> V_1101 [ V_1249 ] . V_1103 = NULL ;
F_296 ( & V_131 -> V_1101 [ V_1249 ] , V_1110 ,
V_1110 ) ;
if ( F_390 ( & V_5 -> V_12 -> V_111 , V_1110 ) )
goto V_1313;
if ( ! V_1152 ||
F_365 ( V_131 , & V_1249 , & V_1152 , V_1110 ,
V_74 , V_1261 |
( ( V_42 == V_1257 ) ? V_1255 : 0 ) ,
V_1311 , V_1244 ) ) {
V_1276 = 1 ;
break;
}
}
}
if ( V_1276 ) {
F_366 ( V_131 , V_131 -> V_1082 , V_42 ) ;
if ( V_1239 && F_372 ( V_131 , V_1103 ) ) {
if ( V_1283 ) {
V_1278 -> V_1289 = V_1282 ;
V_1278 -> V_1290 = V_1283 ;
}
V_1280 -> V_1289 = V_1281 ;
return F_373 ( V_5 , V_131 , V_1095 , V_1103 ) ;
}
V_1249 = V_131 -> V_1082 ;
V_1152 = F_265 ( V_131 ) ;
if ( F_367 ( V_131 , & V_1103 , & V_1249 , & V_1152 ,
V_1261 , V_1239 , V_1244 ) )
goto V_1314;
}
F_391 ( V_1103 ) ;
F_392 ( V_1095 , V_1103 -> V_74 ) ;
F_49 () ;
V_131 -> V_1082 = V_1249 ;
if ( F_269 ( F_265 ( V_131 ) <= ( V_1315 + 1 ) ) ) {
F_374 ( V_1095 ) ;
F_280 () ;
if ( F_265 ( V_131 ) > F_282 ( V_131 ) )
F_285 ( V_1095 ) ;
}
if ( ! V_1103 -> V_1316 || F_393 ( V_1095 ) ) {
F_394 ( V_131 -> V_1317 , V_1249 ) ;
F_53 () ;
}
return V_1275 ;
V_1313:
F_366 ( V_131 , V_131 -> V_1082 , -- V_42 ) ;
V_131 -> V_1101 [ V_131 -> V_1082 ] . V_1103 = NULL ;
V_1287:
F_278 ( V_1103 ) ;
V_1314:
V_5 -> V_1318 ++ ;
return V_1275 ;
}
static void F_395 ( struct V_4 * V_5 , bool V_195 )
{
if ( V_195 ) {
V_5 -> V_362 &= ~ ( V_366 |
V_365 ) ;
V_5 -> V_362 |= V_829 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_362 |= V_720 ;
if ( V_5 -> V_178 & V_387 )
V_5 -> V_362 |= V_369 ;
else
V_5 -> V_362 |= V_370 ;
} else {
V_5 -> V_362 &= ~ V_829 ;
if ( F_23 ( V_5 , 5705_PLUS ) ||
( V_5 -> V_178 & V_562 ) ||
F_30 ( V_5 ) == V_531 )
V_5 -> V_362 &= ~ V_720 ;
}
F_46 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
}
static int F_396 ( struct V_4 * V_5 , T_1 V_367 , bool V_1319 )
{
T_1 V_7 , V_769 , V_362 , V_1320 = 0 ;
F_129 ( V_5 , false ) ;
F_130 ( V_5 , false ) ;
if ( V_1319 && F_127 ( V_5 ) )
return - V_210 ;
V_769 = V_487 ;
switch ( V_367 ) {
case V_368 :
break;
case V_327 :
V_769 |= V_771 ;
break;
case V_326 :
default:
if ( V_5 -> V_178 & V_179 ) {
V_367 = V_327 ;
V_769 |= V_771 ;
} else {
V_367 = V_326 ;
V_769 |= V_488 ;
}
}
if ( V_1319 ) {
if ( ! ( V_5 -> V_178 & V_179 ) ) {
F_57 ( V_5 , V_180 , & V_7 ) ;
V_7 |= V_489 |
V_490 ;
F_59 ( V_5 , V_180 , V_7 ) ;
} else {
V_1320 = V_1321 |
V_1322 ;
F_59 ( V_5 , V_519 , V_1320 ) ;
}
} else
V_769 |= V_772 ;
F_59 ( V_5 , V_204 , V_769 ) ;
if ( V_5 -> V_178 & V_179 )
F_57 ( V_5 , V_204 , & V_769 ) ;
F_24 ( 40 ) ;
if ( ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) == V_256 ) {
F_59 ( V_5 , V_519 , V_1320 |
V_1323 |
V_1324 ) ;
F_57 ( V_5 , V_519 , & V_7 ) ;
}
if ( ( V_5 -> V_178 & V_300 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_31 ( V_356 , V_1325 ) ;
F_24 ( 10 ) ;
F_31 ( V_356 , V_5 -> V_349 ) ;
}
V_362 = V_5 -> V_362 &
~ ( V_365 | V_366 ) ;
if ( V_367 == V_326 )
V_362 |= V_370 ;
else
V_362 |= V_369 ;
if ( F_30 ( V_5 ) == V_531 ) {
T_1 V_1326 = V_5 -> V_215 & V_395 ;
if ( V_1326 == V_396 )
V_362 &= ~ V_720 ;
else if ( V_1326 == V_560 )
V_362 |= V_720 ;
F_59 ( V_5 , V_486 ,
V_817 ) ;
}
F_46 ( V_377 , V_362 ) ;
F_24 ( 40 ) ;
return 0 ;
}
static void F_397 ( struct V_359 * V_111 , T_15 V_1184 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_1184 & V_1327 ) {
if ( V_5 -> V_362 & V_829 )
return;
F_70 ( & V_5 -> V_209 ) ;
F_395 ( V_5 , true ) ;
F_222 ( V_5 -> V_111 ) ;
F_71 ( & V_5 -> V_209 ) ;
F_98 ( V_111 , L_42 ) ;
} else {
if ( ! ( V_5 -> V_362 & V_829 ) )
return;
F_70 ( & V_5 -> V_209 ) ;
F_395 ( V_5 , false ) ;
F_203 ( V_5 , true ) ;
F_71 ( & V_5 -> V_209 ) ;
F_98 ( V_111 , L_43 ) ;
}
}
static T_15 F_398 ( struct V_359 * V_111 ,
T_15 V_1184 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_111 -> V_1193 > V_1328 && F_23 ( V_5 , 5780_CLASS ) )
V_1184 &= ~ V_1329 ;
return V_1184 ;
}
static int F_399 ( struct V_359 * V_111 , T_15 V_1184 )
{
T_15 V_1330 = V_111 -> V_1184 ^ V_1184 ;
if ( ( V_1330 & V_1327 ) && F_146 ( V_111 ) )
F_397 ( V_111 , V_1184 ) ;
return 0 ;
}
static void F_400 ( struct V_4 * V_5 ,
struct V_1122 * V_1123 )
{
int V_42 ;
if ( V_1123 != & V_5 -> V_123 [ 0 ] . V_1084 ) {
for ( V_42 = V_1123 -> V_1086 ; V_42 != V_1123 -> V_1085 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1133 )
F_289 ( V_5 , & V_1123 -> V_1135 [ V_42 ] ,
V_5 -> V_1136 ) ;
if ( F_23 ( V_5 , V_516 ) ) {
for ( V_42 = V_1123 -> V_1088 ;
V_42 != V_1123 -> V_1087 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1138 ) {
F_289 ( V_5 , & V_1123 -> V_1141 [ V_42 ] ,
V_1142 ) ;
}
}
return;
}
for ( V_42 = 0 ; V_42 <= V_5 -> V_1133 ; V_42 ++ )
F_289 ( V_5 , & V_1123 -> V_1135 [ V_42 ] ,
V_5 -> V_1136 ) ;
if ( F_23 ( V_5 , V_516 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
for ( V_42 = 0 ; V_42 <= V_5 -> V_1138 ; V_42 ++ )
F_289 ( V_5 , & V_1123 -> V_1141 [ V_42 ] ,
V_1142 ) ;
}
}
static int F_401 ( struct V_4 * V_5 ,
struct V_1122 * V_1123 )
{
T_1 V_42 , V_1331 ;
V_1123 -> V_1086 = 0 ;
V_1123 -> V_1085 = 0 ;
V_1123 -> V_1088 = 0 ;
V_1123 -> V_1087 = 0 ;
if ( V_1123 != & V_5 -> V_123 [ 0 ] . V_1084 ) {
memset ( & V_1123 -> V_1135 [ 0 ] , 0 ,
F_402 ( V_5 ) ) ;
if ( V_1123 -> V_1141 )
memset ( & V_1123 -> V_1141 [ 0 ] , 0 ,
F_403 ( V_5 ) ) ;
goto V_186;
}
memset ( V_1123 -> V_1134 , 0 , F_404 ( V_5 ) ) ;
V_1331 = V_1332 ;
if ( F_23 ( V_5 , 5780_CLASS ) &&
V_5 -> V_111 -> V_1193 > V_1328 )
V_1331 = V_1333 ;
V_5 -> V_1136 = F_405 ( V_1331 ) ;
for ( V_42 = 0 ; V_42 <= V_5 -> V_1133 ; V_42 ++ ) {
struct V_1127 * V_1334 ;
V_1334 = & V_1123 -> V_1134 [ V_42 ] ;
V_1334 -> V_1173 = V_1331 << V_1175 ;
V_1334 -> V_1177 = ( V_1335 << V_1336 ) ;
V_1334 -> V_1163 = ( V_1132 |
( V_42 << V_1337 ) ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_1338 ; V_42 ++ ) {
unsigned int V_1126 ;
if ( F_292 ( V_5 , V_1123 , V_1132 , V_42 ,
& V_1126 ) < 0 ) {
F_144 ( V_5 -> V_111 ,
L_44
L_45
L_46 , V_42 , V_5 -> V_1338 ) ;
if ( V_42 == 0 )
goto V_1339;
V_5 -> V_1338 = V_42 ;
break;
}
}
if ( ! F_23 ( V_5 , V_516 ) || F_23 ( V_5 , 5780_CLASS ) )
goto V_186;
memset ( V_1123 -> V_1139 , 0 , F_406 ( V_5 ) ) ;
if ( ! F_23 ( V_5 , V_1340 ) )
goto V_186;
for ( V_42 = 0 ; V_42 <= V_5 -> V_1138 ; V_42 ++ ) {
struct V_1127 * V_1334 ;
V_1334 = & V_1123 -> V_1139 [ V_42 ] . V_1140 ;
V_1334 -> V_1173 = V_1333 << V_1175 ;
V_1334 -> V_1177 = ( V_1335 << V_1336 ) |
V_1341 ;
V_1334 -> V_1163 = ( V_1137 |
( V_42 << V_1337 ) ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_1342 ; V_42 ++ ) {
unsigned int V_1126 ;
if ( F_292 ( V_5 , V_1123 , V_1137 , V_42 ,
& V_1126 ) < 0 ) {
F_144 ( V_5 -> V_111 ,
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
F_400 ( V_5 , V_1123 ) ;
return - V_267 ;
}
static void F_407 ( struct V_4 * V_5 ,
struct V_1122 * V_1123 )
{
F_177 ( V_1123 -> V_1135 ) ;
V_1123 -> V_1135 = NULL ;
F_177 ( V_1123 -> V_1141 ) ;
V_1123 -> V_1141 = NULL ;
if ( V_1123 -> V_1134 ) {
F_408 ( & V_5 -> V_12 -> V_111 , F_404 ( V_5 ) ,
V_1123 -> V_1134 , V_1123 -> V_1343 ) ;
V_1123 -> V_1134 = NULL ;
}
if ( V_1123 -> V_1139 ) {
F_408 ( & V_5 -> V_12 -> V_111 , F_406 ( V_5 ) ,
V_1123 -> V_1139 , V_1123 -> V_1344 ) ;
V_1123 -> V_1139 = NULL ;
}
}
static int F_409 ( struct V_4 * V_5 ,
struct V_1122 * V_1123 )
{
V_1123 -> V_1135 = F_263 ( F_402 ( V_5 ) ,
V_627 ) ;
if ( ! V_1123 -> V_1135 )
return - V_267 ;
V_1123 -> V_1134 = F_410 ( & V_5 -> V_12 -> V_111 ,
F_404 ( V_5 ) ,
& V_1123 -> V_1343 ,
V_627 ) ;
if ( ! V_1123 -> V_1134 )
goto V_1026;
if ( F_23 ( V_5 , V_516 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
V_1123 -> V_1141 = F_263 ( F_403 ( V_5 ) ,
V_627 ) ;
if ( ! V_1123 -> V_1141 )
goto V_1026;
V_1123 -> V_1139 = F_410 ( & V_5 -> V_12 -> V_111 ,
F_406 ( V_5 ) ,
& V_1123 -> V_1344 ,
V_627 ) ;
if ( ! V_1123 -> V_1139 )
goto V_1026;
}
return 0 ;
V_1026:
F_407 ( V_5 , V_1123 ) ;
return - V_267 ;
}
static void F_411 ( struct V_4 * V_5 )
{
int V_42 , V_622 ;
for ( V_622 = 0 ; V_622 < V_5 -> V_129 ; V_622 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_622 ] ;
F_400 ( V_5 , & V_131 -> V_1084 ) ;
if ( ! V_131 -> V_1101 )
continue;
for ( V_42 = 0 ; V_42 < V_1091 ; V_42 ++ ) {
struct V_1102 * V_1103 = V_131 -> V_1101 [ V_42 ] . V_1103 ;
if ( ! V_1103 )
continue;
F_366 ( V_131 , V_42 ,
F_275 ( V_1103 ) -> V_1113 - 1 ) ;
F_278 ( V_1103 ) ;
}
F_412 ( F_268 ( V_5 -> V_111 , V_622 ) ) ;
}
}
static int F_413 ( struct V_4 * V_5 )
{
int V_42 ;
F_411 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_131 -> V_132 = 0 ;
V_131 -> V_1081 = 0 ;
V_131 -> V_134 -> V_57 = 0 ;
V_131 -> V_134 -> V_1076 = 0 ;
memset ( V_131 -> V_134 , 0 , V_1345 ) ;
V_131 -> V_1082 = 0 ;
V_131 -> V_147 = 0 ;
if ( V_131 -> V_1105 )
memset ( V_131 -> V_1105 , 0 , V_1346 ) ;
V_131 -> V_149 = 0 ;
if ( V_131 -> V_1158 )
memset ( V_131 -> V_1158 , 0 , F_414 ( V_5 ) ) ;
if ( V_131 -> V_1084 . V_1134 &&
F_401 ( V_5 , & V_131 -> V_1084 ) ) {
F_411 ( V_5 ) ;
return - V_267 ;
}
}
return 0 ;
}
static void F_415 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_1105 ) {
F_408 ( & V_5 -> V_12 -> V_111 , V_1346 ,
V_131 -> V_1105 , V_131 -> V_1347 ) ;
V_131 -> V_1105 = NULL ;
}
F_177 ( V_131 -> V_1101 ) ;
V_131 -> V_1101 = NULL ;
}
}
static int F_416 ( struct V_4 * V_5 )
{
int V_42 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
if ( F_23 ( V_5 , V_1098 ) )
V_131 ++ ;
for ( V_42 = 0 ; V_42 < V_5 -> V_1348 ; V_42 ++ , V_131 ++ ) {
V_131 -> V_1101 = F_263 ( sizeof( struct V_1099 ) *
V_1091 , V_627 ) ;
if ( ! V_131 -> V_1101 )
goto V_1026;
V_131 -> V_1105 = F_410 ( & V_5 -> V_12 -> V_111 ,
V_1346 ,
& V_131 -> V_1347 ,
V_627 ) ;
if ( ! V_131 -> V_1105 )
goto V_1026;
}
return 0 ;
V_1026:
F_415 ( V_5 ) ;
return - V_267 ;
}
static void F_417 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_407 ( V_5 , & V_131 -> V_1084 ) ;
if ( ! V_131 -> V_1158 )
continue;
F_408 ( & V_5 -> V_12 -> V_111 ,
F_414 ( V_5 ) ,
V_131 -> V_1158 ,
V_131 -> V_1349 ) ;
V_131 -> V_1158 = NULL ;
}
}
static int F_418 ( struct V_4 * V_5 )
{
unsigned int V_42 , V_202 ;
V_202 = V_5 -> V_1214 ;
if ( F_23 ( V_5 , V_1203 ) )
V_202 ++ ;
for ( V_42 = 0 ; V_42 < V_202 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( F_409 ( V_5 , & V_131 -> V_1084 ) )
goto V_1026;
if ( ! V_42 && F_23 ( V_5 , V_1203 ) )
continue;
V_131 -> V_1158 = F_419 ( & V_5 -> V_12 -> V_111 ,
F_414 ( V_5 ) ,
& V_131 -> V_1349 ,
V_627 ) ;
if ( ! V_131 -> V_1158 )
goto V_1026;
}
return 0 ;
V_1026:
F_417 ( V_5 ) ;
return - V_267 ;
}
static void F_420 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
F_408 ( & V_5 -> V_12 -> V_111 , V_1345 ,
V_131 -> V_134 ,
V_131 -> V_1350 ) ;
V_131 -> V_134 = NULL ;
}
}
F_417 ( V_5 ) ;
F_415 ( V_5 ) ;
F_243 ( V_5 , 0 ) ;
if ( V_5 -> V_1351 ) {
F_408 ( & V_5 -> V_12 -> V_111 , sizeof( struct V_1352 ) ,
V_5 -> V_1351 , V_5 -> V_1353 ) ;
V_5 -> V_1351 = NULL ;
}
F_244 ( V_5 ) ;
}
static int F_421 ( struct V_4 * V_5 )
{
int V_42 ;
V_5 -> V_1351 = F_419 ( & V_5 -> V_12 -> V_111 ,
sizeof( struct V_1352 ) ,
& V_5 -> V_1353 , V_627 ) ;
if ( ! V_5 -> V_1351 )
goto V_1026;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
struct V_139 * V_140 ;
V_131 -> V_134 = F_419 ( & V_5 -> V_12 -> V_111 ,
V_1345 ,
& V_131 -> V_1350 ,
V_627 ) ;
if ( ! V_131 -> V_134 )
goto V_1026;
V_140 = V_131 -> V_134 ;
if ( F_23 ( V_5 , V_1203 ) ) {
T_3 * V_1354 = NULL ;
switch ( V_42 ) {
case 1 :
V_1354 = & V_140 -> V_145 [ 0 ] . V_1080 ;
break;
case 2 :
V_1354 = & V_140 -> V_1077 ;
break;
case 3 :
V_1354 = & V_140 -> V_1355 ;
break;
case 4 :
V_1354 = & V_140 -> V_1079 ;
break;
}
V_131 -> V_148 = V_1354 ;
} else {
V_131 -> V_148 = & V_140 -> V_145 [ 0 ] . V_1080 ;
}
}
if ( F_416 ( V_5 ) || F_418 ( V_5 ) )
goto V_1026;
return 0 ;
V_1026:
F_420 ( V_5 ) ;
return - V_267 ;
}
static int F_422 ( struct V_4 * V_5 , unsigned long V_1356 , T_1 V_1357 , bool V_1358 )
{
unsigned int V_42 ;
T_1 V_7 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
switch ( V_1356 ) {
case V_1054 :
case V_1071 :
case V_1055 :
case V_1059 :
case V_1058 :
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
static int F_423 ( struct V_4 * V_5 , bool V_1358 )
{
int V_42 , V_75 ;
F_45 ( V_5 ) ;
if ( F_36 ( V_5 -> V_12 ) ) {
V_5 -> V_349 &= ~ ( V_728 | V_1360 ) ;
V_5 -> V_362 &= ~ V_727 ;
V_75 = - V_82 ;
goto V_1361;
}
V_5 -> V_349 &= ~ V_728 ;
F_31 ( V_356 , V_5 -> V_349 ) ;
F_24 ( 10 ) ;
V_75 = F_422 ( V_5 , V_1052 , V_1362 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1046 , V_1363 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1054 , V_1364 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1048 , V_1365 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1051 , V_1366 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1053 , V_1367 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1043 , V_1368 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1044 , V_1369 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1041 , V_1370 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1060 , V_1371 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1042 , V_1372 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1071 , V_1373 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1045 , V_1374 , V_1358 ) ;
V_5 -> V_362 &= ~ V_727 ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
V_5 -> V_351 &= ~ V_1360 ;
F_31 ( V_358 , V_5 -> V_351 ) ;
for ( V_42 = 0 ; V_42 < V_1359 ; V_42 ++ ) {
F_24 ( 100 ) ;
if ( ! ( F_33 ( V_358 ) & V_1360 ) )
break;
}
if ( V_42 >= V_1359 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_52
L_53 , V_652 , F_33 ( V_358 ) ) ;
V_75 |= - V_82 ;
}
V_75 |= F_422 ( V_5 , V_138 , V_128 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1061 , V_1375 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1055 , V_1376 , V_1358 ) ;
F_46 ( V_1069 , 0xffffffff ) ;
F_46 ( V_1069 , 0x00000000 ) ;
V_75 |= F_422 ( V_5 , V_1059 , V_1377 , V_1358 ) ;
V_75 |= F_422 ( V_5 , V_1058 , V_1378 , V_1358 ) ;
V_1361:
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 )
memset ( V_131 -> V_134 , 0 , V_1345 ) ;
}
return V_75 ;
}
static void F_424 ( struct V_4 * V_5 )
{
F_425 ( V_5 -> V_12 , V_1379 , & V_5 -> V_1380 ) ;
}
static void F_426 ( struct V_4 * V_5 )
{
T_1 V_7 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
V_7 = ( V_1381 | V_1382 ) ;
if ( F_77 ( V_5 ) == V_913 &&
F_23 ( V_5 , V_836 ) )
V_7 |= V_1383 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_1384 |
V_1385 |
V_1386 ;
F_15 ( V_5 -> V_12 , V_1236 , V_7 ) ;
F_427 ( V_5 -> V_12 , V_1379 , V_5 -> V_1380 ) ;
if ( ! F_23 ( V_5 , V_1074 ) ) {
F_428 ( V_5 -> V_12 , V_1387 ,
V_5 -> V_1388 ) ;
F_428 ( V_5 -> V_12 , V_1389 ,
V_5 -> V_1390 ) ;
}
if ( F_23 ( V_5 , V_836 ) ) {
T_3 V_1391 ;
F_425 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
& V_1391 ) ;
V_1391 &= ~ V_1394 ;
F_427 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
V_1391 ) ;
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_1395 ) ) {
T_3 V_1396 ;
F_425 ( V_5 -> V_12 ,
V_5 -> V_1397 + V_1398 ,
& V_1396 ) ;
F_427 ( V_5 -> V_12 ,
V_5 -> V_1397 + V_1398 ,
V_1396 | V_1399 ) ;
V_7 = F_33 ( V_1070 ) ;
F_46 ( V_1070 , V_7 | V_1400 ) ;
}
}
}
static void F_429 ( struct V_4 * V_5 )
{
T_1 V_7 ;
switch ( F_30 ( V_5 ) ) {
case V_471 :
V_7 = F_33 ( V_1401 ) ;
F_46 ( V_1401 , V_7 |
V_1402 ) ;
break;
case V_472 :
case V_528 :
F_46 ( V_1403 , V_1404 ) ;
break;
default:
return;
}
}
static void F_430 ( struct V_4 * V_5 )
{
T_1 V_7 ;
switch ( F_30 ( V_5 ) ) {
case V_471 :
V_7 = F_33 ( V_1401 ) ;
F_46 ( V_1401 ,
V_7 & ~ V_1402 ) ;
break;
case V_472 :
case V_528 :
V_7 = F_33 ( V_1403 ) ;
F_46 ( V_1403 , V_7 & ~ V_1404 ) ;
break;
default:
return;
}
}
static int F_431 ( struct V_4 * V_5 )
__releases( V_5 -> V_209 )
__acquires( V_5 -> V_209 )
{
T_1 V_7 ;
void (* F_190)( struct V_4 * , T_1 , T_1 );
int V_42 , V_75 ;
if ( ! F_432 ( V_5 -> V_12 ) )
return - V_82 ;
F_159 ( V_5 ) ;
F_35 ( V_5 , V_61 ) ;
V_5 -> V_581 = 0 ;
F_424 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_635 ||
F_23 ( V_5 , 5755_PLUS ) )
F_46 ( V_1405 , 0 ) ;
F_190 = V_5 -> V_27 ;
if ( F_190 == F_17 )
V_5 -> V_27 = F_7 ;
F_84 ( V_5 , V_1235 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
V_131 -> V_134 -> V_57 = 0 ;
V_131 -> V_134 -> V_1076 = 0 ;
}
V_131 -> V_132 = 0 ;
V_131 -> V_1081 = 0 ;
}
F_280 () ;
F_244 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_349 ( V_5 -> V_123 [ V_42 ] . V_1230 ) ;
F_243 ( V_5 , 0 ) ;
if ( F_30 ( V_5 ) == V_1406 ) {
V_7 = F_33 ( V_1407 ) & ~ V_1408 ;
F_46 ( V_1407 , V_7 | V_1409 ) ;
}
V_7 = V_1410 ;
if ( F_23 ( V_5 , V_1074 ) ) {
if ( F_30 ( V_5 ) != V_256 &&
! F_23 ( V_5 , 57765_PLUS ) &&
F_33 ( V_1411 ) ==
( V_1412 | V_1413 ) )
F_46 ( V_1411 , V_1413 ) ;
if ( F_77 ( V_5 ) != V_1414 ) {
F_46 ( V_492 , ( 1 << 29 ) ) ;
V_7 |= ( 1 << 29 ) ;
}
}
if ( F_30 ( V_5 ) == V_36 ) {
F_46 ( V_320 , F_33 ( V_320 ) | V_1415 ) ;
F_46 ( V_650 ,
F_33 ( V_650 ) & ~ V_651 ) ;
}
F_429 ( V_5 ) ;
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , V_152 ) )
V_7 |= V_1416 ;
F_46 ( V_492 , V_7 ) ;
V_5 -> V_27 = F_190 ;
F_24 ( 120 ) ;
F_19 ( V_5 -> V_12 , V_1379 , & V_7 ) ;
F_24 ( 120 ) ;
if ( F_23 ( V_5 , V_1074 ) && F_433 ( V_5 -> V_12 ) ) {
T_3 V_1417 ;
if ( F_77 ( V_5 ) == V_1414 ) {
int V_622 ;
T_1 V_1418 ;
for ( V_622 = 0 ; V_622 < 5000 ; V_622 ++ )
F_24 ( 100 ) ;
F_19 ( V_5 -> V_12 , 0xc4 , & V_1418 ) ;
F_15 ( V_5 -> V_12 , 0xc4 ,
V_1418 | ( 1 << 15 ) ) ;
}
V_1417 = V_1419 | V_1420 ;
if ( ! F_23 ( V_5 , V_152 ) )
V_1417 |= V_1421 ;
F_226 ( V_5 -> V_12 , V_1422 , V_1417 ) ;
F_434 ( V_5 -> V_12 , V_1423 ,
V_1424 |
V_1425 |
V_1426 |
V_1427 ) ;
}
F_426 ( V_5 ) ;
F_86 ( V_5 , V_1235 ) ;
F_86 ( V_5 , V_1222 ) ;
V_7 = 0 ;
if ( F_23 ( V_5 , 5780_CLASS ) )
V_7 = F_33 ( V_1058 ) ;
F_46 ( V_1058 , V_7 | V_1378 ) ;
if ( F_77 ( V_5 ) == V_1428 ) {
F_93 ( V_5 ) ;
F_46 ( 0x5000 , 0x400 ) ;
}
if ( F_23 ( V_5 , V_263 ) ) {
F_93 ( V_5 ) ;
F_185 ( V_5 , V_648 ) ;
}
V_75 = F_97 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_46 ( V_641 , V_5 -> V_639 ) ;
if ( F_77 ( V_5 ) == V_1429 ) {
V_7 = F_33 ( 0xc4 ) ;
F_46 ( 0xc4 , V_7 | ( 1 << 15 ) ) ;
}
if ( ( V_5 -> V_545 & V_1430 ) != 0 &&
F_30 ( V_5 ) == V_496 ) {
V_5 -> V_156 |= V_155 ;
if ( F_77 ( V_5 ) == V_1429 )
V_5 -> V_156 |= V_154 ;
F_46 ( V_153 , V_5 -> V_156 ) ;
}
if ( V_5 -> V_178 & V_562 ) {
V_5 -> V_362 = V_721 ;
V_7 = V_5 -> V_362 ;
} else if ( V_5 -> V_178 & V_300 ) {
V_5 -> V_362 = V_370 ;
V_7 = V_5 -> V_362 ;
} else
V_7 = 0 ;
F_31 ( V_377 , V_7 ) ;
F_24 ( 40 ) ;
F_37 ( V_5 , V_61 ) ;
F_75 ( V_5 ) ;
if ( F_23 ( V_5 , V_1074 ) &&
F_77 ( V_5 ) != V_1414 &&
F_30 ( V_5 ) != V_256 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( 0x7c00 ) ;
F_46 ( 0x7c00 , V_7 | ( 1 << 25 ) ) ;
}
F_430 ( V_5 ) ;
F_86 ( V_5 , V_303 ) ;
V_5 -> V_178 &= ~ ( V_766 |
V_564 ) ;
F_86 ( V_5 , V_311 ) ;
F_32 ( V_5 , V_1431 , & V_7 ) ;
if ( V_7 == V_1432 ) {
T_1 V_1433 ;
F_32 ( V_5 , V_1434 , & V_1433 ) ;
if ( V_1433 & V_1435 ) {
F_84 ( V_5 , V_303 ) ;
V_5 -> V_292 = V_293 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , V_311 ) ;
F_32 ( V_5 , V_1436 , & V_1433 ) ;
if ( V_1433 & V_1437 )
V_5 -> V_178 |= V_766 ;
if ( V_1433 & V_1438 )
V_5 -> V_178 |= V_564 ;
}
}
return 0 ;
}
static int F_435 ( struct V_4 * V_5 , int V_95 , bool V_1358 )
{
int V_75 ;
F_93 ( V_5 ) ;
F_94 ( V_5 , V_95 ) ;
F_423 ( V_5 , V_1358 ) ;
V_75 = F_431 ( V_5 ) ;
F_197 ( V_5 , false ) ;
F_96 ( V_5 , V_95 ) ;
F_95 ( V_5 , V_95 ) ;
if ( V_5 -> V_1351 ) {
F_436 ( V_5 , & V_5 -> V_1439 ) ;
F_437 ( V_5 , & V_5 -> V_1440 ) ;
memset ( V_5 -> V_1351 , 0 , sizeof( struct V_1352 ) ) ;
}
return V_75 ;
}
static int F_438 ( struct V_359 * V_111 , void * V_1441 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_1442 * V_184 = V_1441 ;
int V_75 = 0 ;
bool V_688 = false ;
if ( ! F_439 ( V_184 -> V_1443 ) )
return - V_1444 ;
memcpy ( V_111 -> V_689 , V_184 -> V_1443 , V_111 -> V_1445 ) ;
if ( ! F_146 ( V_111 ) )
return 0 ;
if ( F_23 ( V_5 , V_303 ) ) {
T_1 V_1446 , V_1447 , V_1448 , V_1449 ;
V_1446 = F_33 ( V_684 ) ;
V_1447 = F_33 ( V_685 ) ;
V_1448 = F_33 ( V_1450 ) ;
V_1449 = F_33 ( V_1451 ) ;
if ( ( V_1446 != V_1448 || V_1447 != V_1449 ) &&
! ( V_1448 == 0 && V_1449 == 0 ) )
V_688 = true ;
}
F_70 ( & V_5 -> V_209 ) ;
F_197 ( V_5 , V_688 ) ;
F_440 ( V_111 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_75 ;
}
static void F_441 ( struct V_4 * V_5 , T_1 V_1452 ,
T_9 V_1110 , T_1 V_1453 ,
T_1 V_1454 )
{
F_29 ( V_5 ,
( V_1452 + V_1455 + V_1456 ) ,
( ( T_6 ) V_1110 >> 32 ) ) ;
F_29 ( V_5 ,
( V_1452 + V_1455 + V_16 ) ,
( ( T_6 ) V_1110 & 0xffffffff ) ) ;
F_29 ( V_5 ,
( V_1452 + V_1457 ) ,
V_1453 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_29 ( V_5 ,
( V_1452 + V_1458 ) ,
V_1454 ) ;
}
static void F_442 ( struct V_4 * V_5 , struct V_1459 * V_1460 )
{
int V_42 = 0 ;
if ( ! F_23 ( V_5 , V_1098 ) ) {
F_46 ( V_1461 , V_1460 -> V_1462 ) ;
F_46 ( V_1463 , V_1460 -> V_1464 ) ;
F_46 ( V_1465 , V_1460 -> V_1466 ) ;
} else {
F_46 ( V_1461 , 0 ) ;
F_46 ( V_1463 , 0 ) ;
F_46 ( V_1465 , 0 ) ;
for (; V_42 < V_5 -> V_1348 ; V_42 ++ ) {
T_1 V_161 ;
V_161 = V_1467 + V_42 * 0x18 ;
F_46 ( V_161 , V_1460 -> V_1462 ) ;
V_161 = V_1468 + V_42 * 0x18 ;
F_46 ( V_161 , V_1460 -> V_1464 ) ;
V_161 = V_1469 + V_42 * 0x18 ;
F_46 ( V_161 , V_1460 -> V_1466 ) ;
}
}
for (; V_42 < V_5 -> V_122 - 1 ; V_42 ++ ) {
F_46 ( V_1467 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1468 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1469 + V_42 * 0x18 , 0 ) ;
}
}
static void F_443 ( struct V_4 * V_5 , struct V_1459 * V_1460 )
{
int V_42 = 0 ;
T_1 V_202 = V_5 -> V_1214 ;
if ( ! F_23 ( V_5 , V_1203 ) ) {
F_46 ( V_1470 , V_1460 -> V_1471 ) ;
F_46 ( V_1472 , V_1460 -> V_1473 ) ;
F_46 ( V_1474 , V_1460 -> V_1475 ) ;
V_202 -- ;
} else {
F_46 ( V_1470 , 0 ) ;
F_46 ( V_1472 , 0 ) ;
F_46 ( V_1474 , 0 ) ;
}
for (; V_42 < V_202 ; V_42 ++ ) {
T_1 V_161 ;
V_161 = V_1057 + V_42 * 0x18 ;
F_46 ( V_161 , V_1460 -> V_1471 ) ;
V_161 = V_1476 + V_42 * 0x18 ;
F_46 ( V_161 , V_1460 -> V_1473 ) ;
V_161 = V_1477 + V_42 * 0x18 ;
F_46 ( V_161 , V_1460 -> V_1475 ) ;
}
for (; V_42 < V_5 -> V_122 - 1 ; V_42 ++ ) {
F_46 ( V_1057 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1476 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1477 + V_42 * 0x18 , 0 ) ;
}
}
static void F_444 ( struct V_4 * V_5 , struct V_1459 * V_1460 )
{
F_442 ( V_5 , V_1460 ) ;
F_443 ( V_5 , V_1460 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_7 = V_1460 -> V_968 ;
F_46 ( V_1478 , V_1460 -> V_1479 ) ;
F_46 ( V_1480 , V_1460 -> V_1481 ) ;
if ( ! V_5 -> V_335 )
V_7 = 0 ;
F_46 ( V_966 , V_7 ) ;
}
}
static void F_445 ( struct V_4 * V_5 )
{
T_1 V_1482 , V_202 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_202 = V_1483 + V_1484 * 16 ;
else if ( F_23 ( V_5 , 5717_PLUS ) )
V_202 = V_1483 + V_1484 * 4 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_762 )
V_202 = V_1483 + V_1484 * 2 ;
else
V_202 = V_1483 + V_1484 ;
for ( V_1482 = V_1483 + V_1484 ;
V_1482 < V_202 ; V_1482 += V_1484 )
F_29 ( V_5 , V_1482 + V_1457 ,
V_1485 ) ;
}
static void F_446 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1482 = V_1483 ;
if ( F_23 ( V_5 , V_1098 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1482 += V_1484 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1105 )
continue;
F_441 ( V_5 , V_1482 , V_131 -> V_1347 ,
( V_1091 << V_1486 ) ,
V_38 ) ;
}
}
static void F_447 ( struct V_4 * V_5 )
{
T_1 V_1487 , V_202 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_202 = V_1488 + V_1484 * 17 ;
else if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_202 = V_1488 + V_1484 * 16 ;
else if ( F_30 ( V_5 ) == V_1489 ||
F_30 ( V_5 ) == V_762 ||
F_23 ( V_5 , 57765_CLASS ) )
V_202 = V_1488 + V_1484 * 4 ;
else
V_202 = V_1488 + V_1484 ;
for ( V_1487 = V_1488 + V_1484 ;
V_1487 < V_202 ; V_1487 += V_1484 )
F_29 ( V_5 , V_1487 + V_1457 ,
V_1485 ) ;
}
static void F_448 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1487 = V_1488 ;
if ( F_23 ( V_5 , V_1203 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1487 += V_1484 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1158 )
continue;
F_441 ( V_5 , V_1487 , V_131 -> V_1349 ,
( V_5 -> V_1201 + 1 ) <<
V_1486 , 0 ) ;
}
}
static void F_449 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_1490 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
F_445 ( V_5 ) ;
F_447 ( V_5 ) ;
F_47 ( V_5 -> V_123 [ 0 ] . V_124 , 1 ) ;
V_5 -> V_123 [ 0 ] . V_1491 = 0 ;
V_5 -> V_123 [ 0 ] . V_1492 = 0 ;
V_5 -> V_123 [ 0 ] . V_1493 = 0 ;
if ( F_23 ( V_5 , V_1056 ) ) {
for ( V_42 = 1 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
V_5 -> V_123 [ V_42 ] . V_1082 = 0 ;
V_5 -> V_123 [ V_42 ] . V_147 = 0 ;
if ( F_23 ( V_5 , V_1098 ) )
F_52 ( V_5 -> V_123 [ V_42 ] . V_1317 , 0 ) ;
F_315 ( V_5 -> V_123 [ V_42 ] . V_1202 , 0 ) ;
F_47 ( V_5 -> V_123 [ V_42 ] . V_124 , 1 ) ;
V_5 -> V_123 [ V_42 ] . V_1491 = 0 ;
V_5 -> V_123 [ V_42 ] . V_1492 = 0 ;
V_5 -> V_123 [ V_42 ] . V_1493 = 0 ;
}
if ( ! F_23 ( V_5 , V_1098 ) )
F_52 ( V_5 -> V_123 [ 0 ] . V_1317 , 0 ) ;
} else {
V_5 -> V_123 [ 0 ] . V_1082 = 0 ;
V_5 -> V_123 [ 0 ] . V_147 = 0 ;
F_52 ( V_5 -> V_123 [ 0 ] . V_1317 , 0 ) ;
F_315 ( V_5 -> V_123 [ 0 ] . V_1202 , 0 ) ;
}
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_33 = V_1494 + V_16 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
F_394 ( V_33 + V_42 * 8 , 0 ) ;
}
memset ( V_131 -> V_134 , 0 , V_1345 ) ;
F_46 ( V_1495 + V_1456 ,
( ( T_6 ) V_131 -> V_1350 >> 32 ) ) ;
F_46 ( V_1495 + V_16 ,
( ( T_6 ) V_131 -> V_1350 & 0xffffffff ) ) ;
V_1490 = V_1496 ;
for ( V_42 = 1 , V_131 ++ ; V_42 < V_5 -> V_129 ; V_42 ++ , V_131 ++ ) {
T_6 V_1110 = ( T_6 ) V_131 -> V_1350 ;
F_46 ( V_1490 + V_1456 , V_1110 >> 32 ) ;
F_46 ( V_1490 + V_16 , V_1110 & 0xffffffff ) ;
V_1490 += 8 ;
memset ( V_131 -> V_134 , 0 , V_1345 ) ;
}
F_446 ( V_5 ) ;
F_448 ( V_5 ) ;
}
static void F_450 ( struct V_4 * V_5 )
{
T_1 V_7 , V_1497 , V_1498 , V_1499 ;
if ( ! F_23 ( V_5 , 5750_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_30 ( V_5 ) == V_1500 ||
F_30 ( V_5 ) == V_635 ||
F_23 ( V_5 , 57765_PLUS ) )
V_1497 = V_1501 ;
else if ( F_30 ( V_5 ) == V_1489 ||
F_30 ( V_5 ) == V_1502 )
V_1497 = V_1503 ;
else
V_1497 = V_1504 ;
V_1499 = F_322 ( V_1497 / 2 , V_5 -> V_1200 ) ;
V_1498 = F_451 ( T_1 , V_5 -> V_1338 / 8 , 1 ) ;
V_7 = F_322 ( V_1499 , V_1498 ) ;
F_46 ( V_1505 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1506 , V_1497 ) ;
if ( ! F_23 ( V_5 , V_516 ) || F_23 ( V_5 , 5780_CLASS ) )
return;
V_1497 = V_1507 ;
V_1498 = F_451 ( T_1 , V_5 -> V_1342 / 8 , 1 ) ;
V_7 = F_322 ( V_1497 / 2 , V_1498 ) ;
F_46 ( V_1508 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1509 , V_1497 ) ;
}
static inline T_1 F_452 ( unsigned char * V_621 , int V_74 )
{
T_1 V_161 ;
T_1 V_591 ;
int V_622 , V_1510 ;
V_161 = 0xffffffff ;
for ( V_622 = 0 ; V_622 < V_74 ; V_622 ++ ) {
V_161 ^= V_621 [ V_622 ] ;
for ( V_1510 = 0 ; V_1510 < 8 ; V_1510 ++ ) {
V_591 = V_161 & 0x01 ;
V_161 >>= 1 ;
if ( V_591 )
V_161 ^= 0xedb88320 ;
}
}
return ~ V_161 ;
}
static void F_453 ( struct V_4 * V_5 , unsigned int V_1511 )
{
F_46 ( V_1512 , V_1511 ? 0xffffffff : 0 ) ;
F_46 ( V_1513 , V_1511 ? 0xffffffff : 0 ) ;
F_46 ( V_1514 , V_1511 ? 0xffffffff : 0 ) ;
F_46 ( V_1515 , V_1511 ? 0xffffffff : 0 ) ;
}
static void F_440 ( struct V_359 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_349 ;
V_349 = V_5 -> V_349 & ~ ( V_1516 |
V_1198 ) ;
#if ! F_362 ( V_1517 ) && ! F_362 ( V_1518 )
if ( ! F_23 ( V_5 , V_303 ) )
V_349 |= V_1198 ;
#endif
if ( V_111 -> V_10 & V_1519 ) {
V_349 |= V_1516 ;
} else if ( V_111 -> V_10 & V_1520 ) {
F_453 ( V_5 , 1 ) ;
} else if ( F_454 ( V_111 ) ) {
F_453 ( V_5 , 0 ) ;
} else {
struct V_1521 * V_1522 ;
T_1 V_1523 [ 4 ] = { 0 , } ;
T_1 V_1524 ;
T_1 V_44 ;
T_1 V_1525 ;
F_455 (ha, dev) {
V_1525 = F_452 ( V_1522 -> V_184 , V_1526 ) ;
V_44 = ~ V_1525 & 0x7f ;
V_1524 = ( V_44 & 0x60 ) >> 5 ;
V_44 &= 0x1f ;
V_1523 [ V_1524 ] |= ( 1 << V_44 ) ;
}
F_46 ( V_1512 , V_1523 [ 0 ] ) ;
F_46 ( V_1513 , V_1523 [ 1 ] ) ;
F_46 ( V_1514 , V_1523 [ 2 ] ) ;
F_46 ( V_1515 , V_1523 [ 3 ] ) ;
}
if ( F_456 ( V_111 ) > F_457 ( V_5 ) ) {
V_349 |= V_1516 ;
} else if ( ! ( V_111 -> V_10 & V_1519 ) ) {
int V_42 = 0 ;
struct V_1521 * V_1522 ;
F_458 (ha, dev) {
F_196 ( V_5 , V_1522 -> V_184 ,
V_42 + F_459 ( V_5 ) ) ;
V_42 ++ ;
}
}
if ( V_349 != V_5 -> V_349 ) {
V_5 -> V_349 = V_349 ;
F_31 ( V_356 , V_349 ) ;
F_24 ( 10 ) ;
}
}
static void F_460 ( struct V_4 * V_5 , T_1 V_1527 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1528 ; V_42 ++ )
V_5 -> V_1529 [ V_42 ] = F_461 ( V_42 , V_1527 ) ;
}
static void F_462 ( struct V_4 * V_5 )
{
int V_42 ;
if ( ! F_23 ( V_5 , V_1056 ) )
return;
if ( V_5 -> V_1214 == 1 ) {
memset ( & V_5 -> V_1529 [ 0 ] , 0 , sizeof( V_5 -> V_1529 ) ) ;
return;
}
for ( V_42 = 0 ; V_42 < V_1528 ; V_42 ++ ) {
if ( V_5 -> V_1529 [ V_42 ] >= V_5 -> V_1214 )
break;
}
if ( V_42 != V_1528 )
F_460 ( V_5 , V_5 -> V_1214 ) ;
}
static void F_463 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_161 = V_1530 ;
while ( V_42 < V_1528 ) {
T_1 V_7 = V_5 -> V_1529 [ V_42 ] ;
V_42 ++ ;
for (; V_42 % 8 ; V_42 ++ ) {
V_7 <<= 4 ;
V_7 |= V_5 -> V_1529 [ V_42 ] ;
}
F_46 ( V_161 , V_7 ) ;
V_161 += 4 ;
}
}
static inline T_1 F_464 ( struct V_4 * V_5 )
{
if ( F_30 ( V_5 ) == V_472 )
return V_1531 ;
else
return V_1532 ;
}
static int F_465 ( struct V_4 * V_5 , bool V_1533 )
{
T_1 V_7 , V_1534 ;
int V_42 , V_75 , V_202 ;
struct V_1122 * V_1123 = & V_5 -> V_123 [ 0 ] . V_1084 ;
F_45 ( V_5 ) ;
F_93 ( V_5 ) ;
F_94 ( V_5 , V_96 ) ;
if ( F_23 ( V_5 , V_557 ) )
F_423 ( V_5 , 1 ) ;
if ( ( V_5 -> V_178 & V_564 ) &&
! ( V_5 -> V_178 & V_1535 ) ) {
F_211 ( V_5 ) ;
F_133 ( V_5 , NULL ) ;
V_5 -> V_178 |= V_1535 ;
}
if ( V_5 -> V_178 & V_333 )
F_224 ( V_5 ) ;
if ( V_1533 )
F_145 ( V_5 ) ;
V_75 = F_431 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_96 ( V_5 , V_96 ) ;
if ( F_147 ( V_5 ) == V_498 ) {
V_7 = F_33 ( V_499 ) ;
V_7 &= ~ ( V_1536 | V_1537 ) ;
F_46 ( V_499 , V_7 ) ;
V_7 = F_33 ( V_1538 ) ;
V_7 &= ~ V_1539 ;
V_7 |= V_1540 ;
F_46 ( V_1538 , V_7 ) ;
V_7 = F_33 ( V_1541 ) ;
V_7 &= ~ V_1542 ;
V_7 |= V_1543 ;
F_46 ( V_1541 , V_7 ) ;
V_7 = F_33 ( V_1544 ) ;
V_7 &= ~ V_1545 ;
V_7 |= V_1546 ;
F_46 ( V_1544 , V_7 ) ;
}
if ( F_30 ( V_5 ) == V_1406 ) {
V_7 = F_33 ( V_970 ) & ~ V_971 ;
V_7 |= V_1547 |
V_1548 ;
F_46 ( V_970 , V_7 ) ;
V_7 = F_33 ( V_1549 ) & ~ V_1550 ;
F_46 ( V_1549 , V_7 | V_1551 ) ;
F_46 ( V_1552 , V_1553 ) ;
V_7 = F_33 ( V_1407 ) & ~ V_1408 ;
F_46 ( V_1407 , V_7 | V_1409 ) ;
}
if ( F_23 ( V_5 , V_1554 ) ) {
T_1 V_639 = F_33 ( V_641 ) ;
V_7 = V_639 & ~ V_1555 ;
F_46 ( V_641 , V_7 | V_1556 ) ;
V_7 = F_33 ( V_1075 + V_1557 ) ;
F_46 ( V_1075 + V_1557 ,
V_7 | V_1558 ) ;
F_46 ( V_641 , V_639 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) ) {
if ( F_77 ( V_5 ) == V_322 ) {
T_1 V_639 = F_33 ( V_641 ) ;
V_7 = V_639 & ~ V_1555 ;
F_46 ( V_641 , V_7 | V_1556 ) ;
V_7 = F_33 ( V_1075 +
V_1559 ) ;
F_46 ( V_1075 + V_1559 ,
V_7 | V_1560 ) ;
F_46 ( V_641 , V_639 ) ;
}
if ( F_147 ( V_5 ) != V_1561 ) {
T_1 V_639 ;
V_7 = F_33 ( V_1562 ) ;
V_7 |= V_1563 ;
F_46 ( V_1562 , V_7 ) ;
V_639 = F_33 ( V_641 ) ;
V_7 = V_639 & ~ V_1555 ;
F_46 ( V_641 , V_7 | V_1564 ) ;
V_7 = F_33 ( V_1075 +
V_1565 ) ;
V_7 &= ~ V_1566 ;
F_46 ( V_1075 + V_1565 ,
V_7 | V_1567 ) ;
F_46 ( V_641 , V_639 ) ;
}
V_7 = F_33 ( V_1538 ) ;
V_7 &= ~ V_1539 ;
V_7 |= V_1540 ;
F_46 ( V_1538 , V_7 ) ;
}
if ( ! F_23 ( V_5 , V_152 ) ) {
if ( ! F_23 ( V_5 , V_1074 ) )
V_5 -> V_156 |= V_1568 ;
F_31 ( V_153 , V_5 -> V_156 ) ;
}
if ( F_77 ( V_5 ) == V_913 &&
F_23 ( V_5 , V_836 ) ) {
V_7 = F_33 ( V_1236 ) ;
V_7 |= V_1383 ;
F_46 ( V_1236 , V_7 ) ;
}
if ( F_23 ( V_5 , V_60 ) ) {
V_7 = F_33 ( V_1236 ) ;
V_7 |= V_1384 |
V_1385 |
V_1386 ;
F_46 ( V_1236 , V_7 ) ;
}
if ( F_147 ( V_5 ) == V_1569 ) {
V_7 = F_33 ( V_1570 ) ;
V_7 |= ( 1 << 26 ) | ( 1 << 28 ) | ( 1 << 29 ) ;
F_46 ( V_1570 , V_7 ) ;
}
V_75 = F_413 ( V_5 ) ;
if ( V_75 )
return V_75 ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1571 ) &
~ V_1572 ;
if ( F_77 ( V_5 ) == V_322 )
V_7 &= ~ V_1573 ;
if ( ! F_23 ( V_5 , 57765_CLASS ) &&
F_30 ( V_5 ) != V_471 &&
F_30 ( V_5 ) != V_762 )
V_7 |= V_1574 ;
F_46 ( V_1571 , V_7 | V_5 -> V_1575 ) ;
} else if ( F_30 ( V_5 ) != V_408 &&
F_30 ( V_5 ) != V_45 ) {
F_46 ( V_1571 , V_5 -> V_1575 ) ;
}
V_5 -> V_639 &= ~ ( V_1576 |
V_1577 |
V_1578 |
V_1579 ) ;
V_5 -> V_639 |= V_1576 ;
V_5 -> V_639 |= V_1578 ;
V_7 = V_1580 | V_1581 ;
if ( V_5 -> V_1582 )
F_46 ( V_1583 ,
V_5 -> V_1582 | V_1584 ) ;
if ( F_23 ( V_5 , V_987 ) )
V_7 |= V_1585 ;
F_46 ( V_641 , V_5 -> V_639 | V_7 ) ;
V_7 = F_33 ( V_492 ) ;
V_7 &= ~ 0xff ;
V_7 |= ( 65 << V_963 ) ;
F_46 ( V_492 , V_7 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
} else if ( F_30 ( V_5 ) != V_496 ) {
F_46 ( V_1586 , V_1587 ) ;
if ( F_30 ( V_5 ) == V_495 )
F_46 ( V_1588 , V_1589 ) ;
else
F_46 ( V_1588 , V_1590 ) ;
F_46 ( V_1591 , V_1592 ) ;
F_46 ( V_1593 , V_1594 ) ;
} else if ( F_23 ( V_5 , V_1595 ) ) {
int V_656 ;
V_656 = V_5 -> V_656 ;
V_656 = ( V_656 + ( 0x80 - 1 ) ) & ~ ( 0x80 - 1 ) ;
F_46 ( V_1586 ,
V_679 + V_656 ) ;
F_46 ( V_1588 ,
V_1596 - V_656 - 0xa00 ) ;
}
if ( V_5 -> V_111 -> V_1193 <= V_1328 ) {
F_46 ( V_1597 ,
V_5 -> V_1598 . V_1599 ) ;
F_46 ( V_1600 ,
V_5 -> V_1598 . V_1601 ) ;
F_46 ( V_1602 ,
V_5 -> V_1598 . V_1603 ) ;
} else {
F_46 ( V_1597 ,
V_5 -> V_1598 . V_1604 ) ;
F_46 ( V_1600 ,
V_5 -> V_1598 . V_1605 ) ;
F_46 ( V_1602 ,
V_5 -> V_1598 . V_1606 ) ;
}
F_46 ( V_1607 ,
V_5 -> V_1598 . V_1608 ) ;
F_46 ( V_1609 ,
V_5 -> V_1598 . V_1610 ) ;
V_7 = V_1377 | V_1611 ;
if ( F_30 ( V_5 ) == V_472 )
V_7 |= V_1612 ;
if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_762 ||
F_77 ( V_5 ) == V_1613 ||
F_77 ( V_5 ) == V_1614 )
V_7 |= V_1615 ;
F_46 ( V_1059 , V_7 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
if ( F_33 ( V_1059 ) & V_1377 )
break;
F_24 ( 10 ) ;
}
if ( V_42 >= 2000 ) {
F_187 ( V_5 -> V_111 , L_54 , V_652 ) ;
return - V_82 ;
}
if ( F_77 ( V_5 ) == V_1616 )
F_46 ( V_1617 , ( F_33 ( V_1617 ) & ~ 0x3 ) | 0x2 ) ;
F_450 ( V_5 ) ;
F_46 ( V_1618 + V_1455 + V_1456 ,
( ( T_6 ) V_1123 -> V_1343 >> 32 ) ) ;
F_46 ( V_1618 + V_1455 + V_16 ,
( ( T_6 ) V_1123 -> V_1343 & 0xffffffff ) ) ;
if ( ! F_23 ( V_5 , 5717_PLUS ) )
F_46 ( V_1618 + V_1458 ,
V_1619 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1620 + V_1457 ,
V_1485 ) ;
if ( F_77 ( V_5 ) == V_1613 ||
( F_23 ( V_5 , V_516 ) && ! F_23 ( V_5 , 5780_CLASS ) ) ) {
if ( F_23 ( V_5 , V_1340 ) ) {
F_46 ( V_1049 + V_1455 + V_1456 ,
( ( T_6 ) V_1123 -> V_1344 >> 32 ) ) ;
F_46 ( V_1049 + V_1455 + V_16 ,
( ( T_6 ) V_1123 -> V_1344 & 0xffffffff ) ) ;
V_7 = F_466 ( V_5 ) <<
V_1486 ;
F_46 ( V_1049 + V_1457 ,
V_7 | V_1621 ) ;
if ( ! F_23 ( V_5 , V_1303 ) ||
F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_762 )
F_46 ( V_1049 + V_1458 ,
V_1622 ) ;
} else {
F_46 ( V_1049 + V_1457 ,
V_1485 ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_467 ( V_5 ) ;
V_7 <<= V_1486 ;
V_7 |= ( V_1332 << 2 ) ;
} else
V_7 = V_1332 << V_1486 ;
} else
V_7 = V_1623 << V_1486 ;
F_46 ( V_1618 + V_1457 , V_7 ) ;
V_1123 -> V_1085 = V_5 -> V_1338 ;
F_315 ( V_18 , V_1123 -> V_1085 ) ;
V_1123 -> V_1087 =
F_23 ( V_5 , V_1340 ) ? V_5 -> V_1342 : 0 ;
F_315 ( V_1204 , V_1123 -> V_1087 ) ;
F_449 ( V_5 ) ;
F_197 ( V_5 , false ) ;
F_46 ( V_1624 ,
V_5 -> V_111 -> V_1193 + V_1194 + V_1176 + V_1625 ) ;
V_7 = ( 2 << V_382 ) |
( 6 << V_383 ) |
( 32 << V_384 ) ;
if ( F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_762 )
V_7 |= F_33 ( V_381 ) &
( V_964 |
V_965 ) ;
F_46 ( V_381 , V_7 ) ;
F_46 ( V_1626 , V_1627 ) ;
F_46 ( V_1628 , 0x0181 ) ;
V_1534 = ( V_1371 | V_1629 |
V_1630 | V_1631 |
V_1632 | V_1633 |
V_1634 | V_1635 |
V_1636 ) ;
if ( F_30 ( V_5 ) == V_471 )
V_1534 |= V_1637 ;
if ( F_30 ( V_5 ) == V_408 ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1406 )
V_1534 |= V_1638 |
V_1639 |
V_1640 ;
if ( F_30 ( V_5 ) == V_496 &&
F_77 ( V_5 ) != V_1429 ) {
if ( F_23 ( V_5 , V_1595 ) &&
F_30 ( V_5 ) == V_496 ) {
V_1534 |= V_1641 ;
} else if ( ! ( F_33 ( V_1236 ) & V_1642 ) &&
! F_23 ( V_5 , V_1643 ) ) {
V_1534 |= V_1644 ;
}
}
if ( F_23 ( V_5 , V_1074 ) )
V_1534 |= V_1644 ;
if ( F_30 ( V_5 ) == V_662 ) {
V_5 -> V_1252 = 0 ;
if ( V_5 -> V_111 -> V_1193 <= V_1328 ) {
V_1534 |= V_1645 ;
V_5 -> V_1252 = V_1646 ;
}
}
if ( F_23 ( V_5 , V_1293 ) ||
F_23 ( V_5 , V_1294 ) ||
F_23 ( V_5 , V_1295 ) )
V_1534 |= V_1647 ;
if ( F_23 ( V_5 , 57765_PLUS ) ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1406 )
V_1534 |= V_1648 ;
if ( F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_762 )
V_1534 |= F_33 ( V_1060 ) & V_1649 ;
if ( F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_408 ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1406 ||
F_23 ( V_5 , 57765_PLUS ) ) {
T_1 V_1650 ;
if ( F_30 ( V_5 ) == V_762 )
V_1650 = V_1651 ;
else
V_1650 = V_1652 ;
V_7 = F_33 ( V_1650 ) ;
if ( F_77 ( V_5 ) == V_1613 ||
F_30 ( V_5 ) == V_762 ) {
V_7 &= ~ ( V_1653 |
V_1654 |
V_1655 ) ;
V_7 |= V_1656 |
V_1657 |
V_1658 ;
}
F_46 ( V_1650 , V_7 | V_1659 ) ;
}
if ( F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_762 ) {
T_1 V_1650 ;
if ( F_30 ( V_5 ) == V_762 )
V_1650 = V_1660 ;
else
V_1650 = V_1661 ;
V_7 = F_33 ( V_1650 ) ;
F_46 ( V_1650 , V_7 |
V_1662 |
V_1663 ) ;
}
if ( F_23 ( V_5 , 5750_PLUS ) ) {
V_7 = F_33 ( V_1664 ) ;
V_7 &= ~ V_1665 ;
F_46 ( V_1664 , V_7 ) ;
} else if ( ( V_1534 & V_1641 ) &&
F_23 ( V_5 , V_1595 ) ) {
V_7 = F_33 ( V_1664 ) ;
V_7 &= ~ V_1666 ;
F_46 ( V_1664 , V_7 ) ;
} else {
F_46 ( V_1664 , 0xffffff ) ;
}
F_46 ( V_1667 , V_1668 ) ;
F_46 ( V_1669 , 0xffffff ) ;
F_46 ( V_1670 ,
( V_1671 |
V_1672 ) ) ;
F_46 ( V_138 , 0 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
if ( ! ( F_33 ( V_138 ) & V_128 ) )
break;
F_24 ( 10 ) ;
}
F_444 ( V_5 , & V_5 -> V_967 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_46 ( V_1673 + V_1456 ,
( ( T_6 ) V_5 -> V_1353 >> 32 ) ) ;
F_46 ( V_1673 + V_16 ,
( ( T_6 ) V_5 -> V_1353 & 0xffffffff ) ) ;
F_46 ( V_1674 , V_37 ) ;
F_46 ( V_1675 , V_1676 ) ;
for ( V_42 = V_37 ;
V_42 < V_1676 + V_1345 ;
V_42 += sizeof( T_1 ) ) {
F_29 ( V_5 , V_42 , 0 ) ;
F_24 ( 40 ) ;
}
}
F_46 ( V_138 , V_128 | V_5 -> V_127 ) ;
F_46 ( V_1053 , V_1367 | V_1677 ) ;
F_46 ( V_1046 , V_1363 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1054 , V_1364 | V_1678 ) ;
if ( V_5 -> V_178 & V_300 ) {
V_5 -> V_178 &= ~ V_785 ;
F_31 ( V_356 , V_1325 ) ;
F_24 ( 10 ) ;
}
V_5 -> V_362 |= V_1679 | V_1680 |
V_727 | V_1681 |
V_1682 ;
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_362 |= V_725 | V_726 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_562 ) &&
F_30 ( V_5 ) != V_531 )
V_5 -> V_362 |= V_720 ;
F_31 ( V_377 , V_5 -> V_362 | V_1683 | V_1684 ) ;
F_24 ( 40 ) ;
if ( ! F_23 ( V_5 , V_527 ) ) {
T_1 V_1685 ;
V_1685 = V_535 | V_533 |
V_536 | V_537 |
V_534 | V_541 ;
if ( F_30 ( V_5 ) == V_635 )
V_1685 |= V_544 |
V_1686 ;
if ( F_30 ( V_5 ) == V_1489 )
V_1685 |= V_1687 ;
V_5 -> V_22 &= ~ V_1685 ;
V_5 -> V_22 |= F_33 ( V_136 ) & V_1685 ;
if ( F_23 ( V_5 , V_638 ) )
V_5 -> V_22 |= ( V_533 |
V_534 ) ;
}
F_31 ( V_136 , V_5 -> V_22 ) ;
F_24 ( 100 ) ;
if ( F_23 ( V_5 , V_1688 ) ) {
V_7 = F_33 ( V_1070 ) ;
V_7 |= V_1400 ;
if ( V_5 -> V_129 > 1 )
V_7 |= V_1689 ;
if ( ! F_23 ( V_5 , 1SHOT_MSI ) )
V_7 |= V_1690 ;
F_46 ( V_1070 , V_7 ) ;
}
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_31 ( V_1071 , V_1373 ) ;
F_24 ( 40 ) ;
}
V_7 = ( V_1375 | V_1691 |
V_1692 | V_1693 |
V_1694 | V_1695 |
V_1696 | V_1697 |
V_1698 ) ;
if ( F_30 ( V_5 ) == V_496 &&
F_77 ( V_5 ) != V_1429 ) {
if ( F_23 ( V_5 , V_1595 ) &&
( F_77 ( V_5 ) == V_1699 ||
F_77 ( V_5 ) == V_1700 ) ) {
} else if ( ! ( F_33 ( V_1236 ) & V_1642 ) &&
! F_23 ( V_5 , V_1643 ) ) {
V_7 |= V_1701 ;
}
}
if ( F_23 ( V_5 , 5755_PLUS ) )
V_7 |= V_1702 ;
if ( F_30 ( V_5 ) == V_256 )
V_7 |= V_1703 ;
F_31 ( V_1061 , V_7 ) ;
F_24 ( 40 ) ;
if ( F_23 ( V_5 , V_836 ) ) {
T_3 V_1391 ;
F_425 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
& V_1391 ) ;
if ( F_30 ( V_5 ) == V_494 ) {
V_1391 &= ~ V_1704 ;
V_1391 |= V_1705 ;
} else if ( F_30 ( V_5 ) == V_495 ) {
V_1391 &= ~ ( V_1706 | V_1704 ) ;
V_1391 |= V_1705 ;
}
F_427 ( V_5 -> V_12 , V_5 -> V_1392 + V_1393 ,
V_1391 ) ;
}
F_31 ( V_1060 , V_1534 ) ;
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 ) {
for ( V_42 = 0 ; V_42 < V_1707 ; V_42 ++ ) {
if ( F_33 ( V_1708 + ( V_42 << 2 ) ) > F_468 ( V_5 ) )
break;
}
if ( V_42 < V_1707 ) {
V_7 = F_33 ( V_1661 ) ;
V_7 |= F_464 ( V_5 ) ;
F_46 ( V_1661 , V_7 ) ;
F_84 ( V_5 , 5719_5720_RDMA_BUG ) ;
}
}
F_46 ( V_1051 , V_1366 | V_1709 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1055 , V_1376 ) ;
if ( F_30 ( V_5 ) == V_45 )
F_46 ( V_1042 ,
V_1372 | V_1710 ) ;
else
F_46 ( V_1042 , V_1372 ) ;
F_46 ( V_1045 , V_1374 | V_1711 ) ;
F_46 ( V_1052 , V_1362 | V_1712 ) ;
V_7 = V_1365 | V_1713 ;
if ( F_23 ( V_5 , V_1714 ) )
V_7 |= V_1715 ;
F_46 ( V_1048 , V_7 ) ;
F_46 ( V_1041 , V_1370 ) ;
if ( F_23 ( V_5 , V_1293 ) ||
F_23 ( V_5 , V_1294 ) ||
F_23 ( V_5 , V_1295 ) )
F_46 ( V_1041 , V_1370 | 0x8 ) ;
V_7 = V_1369 | V_1716 ;
if ( F_23 ( V_5 , V_1098 ) )
V_7 |= V_1717 ;
F_46 ( V_1044 , V_7 ) ;
F_46 ( V_1043 , V_1368 | V_1718 ) ;
if ( F_77 ( V_5 ) == V_754 ) {
V_75 = F_192 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
if ( F_30 ( V_5 ) == V_662 ) {
F_194 ( V_5 ) ;
}
if ( F_23 ( V_5 , V_1595 ) ) {
V_75 = F_195 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
V_5 -> V_351 = V_1360 ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
V_5 -> V_351 |= V_1719 ;
if ( F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_762 ) {
V_7 = V_1720 | V_1721 ;
V_5 -> V_351 &= ~ V_7 ;
V_5 -> V_351 |= F_33 ( V_358 ) & V_7 ;
}
F_31 ( V_358 , V_5 -> V_351 ) ;
F_24 ( 100 ) ;
if ( F_23 ( V_5 , V_1203 ) ) {
T_1 V_1722 [ 10 ] ;
F_463 ( V_5 ) ;
F_469 ( V_1722 , 10 * sizeof( T_1 ) ) ;
for ( V_42 = 0 ; V_42 < 10 ; V_42 ++ )
F_46 ( V_1723 + V_42 * 4 , V_1722 [ V_42 ] ) ;
}
V_5 -> V_349 = V_728 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_5 -> V_349 |= V_1724 ;
if ( F_30 ( V_5 ) == V_762 )
V_5 -> V_349 |= V_1725 ;
if ( F_23 ( V_5 , V_1203 ) )
V_5 -> V_349 |= V_1726 |
V_1727 |
V_1728 |
V_1729 |
V_1730 |
V_1731 ;
F_31 ( V_356 , V_5 -> V_349 ) ;
F_24 ( 10 ) ;
F_46 ( V_722 , V_5 -> V_558 ) ;
F_46 ( V_378 , V_380 ) ;
if ( V_5 -> V_178 & V_562 ) {
F_31 ( V_356 , V_1325 ) ;
F_24 ( 10 ) ;
}
F_31 ( V_356 , V_5 -> V_349 ) ;
F_24 ( 10 ) ;
if ( V_5 -> V_178 & V_562 ) {
if ( ( F_30 ( V_5 ) == V_495 ) &&
! ( V_5 -> V_178 & V_1732 ) ) {
V_7 = F_33 ( V_568 ) ;
V_7 &= 0xfffff000 ;
V_7 |= 0x880 ;
F_46 ( V_568 , V_7 ) ;
}
if ( F_77 ( V_5 ) == V_1733 )
F_46 ( V_568 , 0x616000 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) )
V_7 = 1 ;
else
V_7 = 2 ;
F_31 ( V_1734 , V_7 ) ;
if ( F_30 ( V_5 ) == V_495 &&
( V_5 -> V_178 & V_562 ) ) {
F_84 ( V_5 , V_935 ) ;
}
if ( ( V_5 -> V_178 & V_300 ) &&
F_30 ( V_5 ) == V_543 ) {
T_1 V_591 ;
V_591 = F_33 ( V_1735 ) ;
F_46 ( V_1735 , V_591 | V_1736 ) ;
V_5 -> V_22 &= ~ V_1737 ;
V_5 -> V_22 |= V_1738 ;
F_46 ( V_136 , V_5 -> V_22 ) ;
}
if ( ! F_23 ( V_5 , V_266 ) ) {
if ( V_5 -> V_178 & V_394 )
V_5 -> V_178 &= ~ V_394 ;
V_75 = F_203 ( V_5 , false ) ;
if ( V_75 )
return V_75 ;
if ( ! ( V_5 -> V_178 & V_562 ) &&
! ( V_5 -> V_178 & V_179 ) ) {
T_1 V_591 ;
if ( ! F_57 ( V_5 , V_514 , & V_591 ) ) {
F_59 ( V_5 , V_514 ,
V_591 | V_1739 ) ;
F_57 ( V_5 , V_1740 , & V_591 ) ;
}
}
}
F_440 ( V_5 -> V_111 ) ;
F_46 ( V_1741 , 0xc2000000 & V_1742 ) ;
F_46 ( V_1743 , 0xffffffff & V_1742 ) ;
F_46 ( V_1744 , 0x86000004 & V_1742 ) ;
F_46 ( V_1745 , 0xffffffff & V_1742 ) ;
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) )
V_202 = 8 ;
else
V_202 = 16 ;
if ( F_23 ( V_5 , V_303 ) )
V_202 -= 4 ;
switch ( V_202 ) {
case 16 :
F_46 ( V_1746 , 0 ) ; F_46 ( V_1747 , 0 ) ;
case 15 :
F_46 ( V_1748 , 0 ) ; F_46 ( V_1749 , 0 ) ;
case 14 :
F_46 ( V_1750 , 0 ) ; F_46 ( V_1751 , 0 ) ;
case 13 :
F_46 ( V_1752 , 0 ) ; F_46 ( V_1753 , 0 ) ;
case 12 :
F_46 ( V_1754 , 0 ) ; F_46 ( V_1755 , 0 ) ;
case 11 :
F_46 ( V_1756 , 0 ) ; F_46 ( V_1757 , 0 ) ;
case 10 :
F_46 ( V_1758 , 0 ) ; F_46 ( V_1759 , 0 ) ;
case 9 :
F_46 ( V_1760 , 0 ) ; F_46 ( V_1761 , 0 ) ;
case 8 :
F_46 ( V_1762 , 0 ) ; F_46 ( V_1763 , 0 ) ;
case 7 :
F_46 ( V_1764 , 0 ) ; F_46 ( V_1765 , 0 ) ;
case 6 :
F_46 ( V_1766 , 0 ) ; F_46 ( V_1767 , 0 ) ;
case 5 :
F_46 ( V_1768 , 0 ) ; F_46 ( V_1769 , 0 ) ;
case 4 :
case 3 :
case 2 :
case 1 :
default:
break;
}
if ( F_23 ( V_5 , V_60 ) )
F_11 ( V_5 , V_1770 ,
V_1771 ) ;
F_95 ( V_5 , V_96 ) ;
return 0 ;
}
static int F_470 ( struct V_4 * V_5 , bool V_1533 )
{
F_198 ( V_5 ) ;
F_97 ( V_5 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
return F_465 ( V_5 , V_1533 ) ;
}
static void F_471 ( struct V_4 * V_5 , struct V_1772 * V_1773 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1774 ; V_42 ++ , V_1773 ++ ) {
T_1 V_6 = V_42 * V_1775 , V_74 = V_1775 ;
F_40 ( V_5 , ( T_1 * ) V_1773 , V_6 , V_74 ) ;
V_6 += V_74 ;
if ( V_1773 -> V_1776 != V_1777 ||
! ( V_1773 -> V_1778 & V_1779 ) )
memset ( V_1773 , 0 , V_1775 ) ;
}
}
static T_16 F_472 ( struct V_538 * V_111 ,
struct V_1780 * V_1781 , char * V_621 )
{
struct V_1782 * V_1783 = F_473 ( V_1781 ) ;
struct V_4 * V_5 = F_474 ( V_111 ) ;
T_1 V_1784 ;
F_70 ( & V_5 -> V_209 ) ;
F_40 ( V_5 , & V_1784 , V_1783 -> V_681 ,
sizeof( V_1784 ) ) ;
F_71 ( & V_5 -> V_209 ) ;
return sprintf ( V_621 , L_55 , V_1784 * 1000 ) ;
}
static void F_475 ( struct V_4 * V_5 )
{
if ( V_5 -> V_1785 ) {
F_476 ( V_5 -> V_1785 ) ;
V_5 -> V_1785 = NULL ;
}
}
static void F_477 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_629 = 0 ;
struct V_1786 * V_12 = V_5 -> V_12 ;
struct V_1772 V_1787 [ V_1774 ] ;
F_471 ( V_5 , V_1787 ) ;
for ( V_42 = 0 ; V_42 < V_1774 ; V_42 ++ ) {
if ( ! V_1787 [ V_42 ] . V_1788 )
continue;
V_629 += V_1787 [ V_42 ] . V_1789 ;
V_629 += V_1787 [ V_42 ] . V_1788 ;
}
if ( ! V_629 )
return;
V_5 -> V_1785 = F_478 ( & V_12 -> V_111 , L_56 ,
V_5 , V_1790 ) ;
if ( F_116 ( V_5 -> V_1785 ) ) {
V_5 -> V_1785 = NULL ;
F_117 ( & V_12 -> V_111 , L_57 ) ;
}
}
static inline void F_475 ( struct V_4 * V_5 ) { }
static inline void F_477 ( struct V_4 * V_5 ) { }
static void F_479 ( struct V_4 * V_5 )
{
struct V_1352 * V_1791 = V_5 -> V_1351 ;
if ( ! V_5 -> V_335 )
return;
F_480 ( & V_1791 -> V_1792 , V_1793 ) ;
F_480 ( & V_1791 -> V_1794 , V_1795 ) ;
F_480 ( & V_1791 -> V_1796 , V_1797 ) ;
F_480 ( & V_1791 -> V_1798 , V_1799 ) ;
F_480 ( & V_1791 -> V_1800 , V_1801 ) ;
F_480 ( & V_1791 -> V_1802 , V_1803 ) ;
F_480 ( & V_1791 -> V_1804 , V_1805 ) ;
F_480 ( & V_1791 -> V_1806 , V_1807 ) ;
F_480 ( & V_1791 -> V_1808 , V_1809 ) ;
F_480 ( & V_1791 -> V_1810 , V_1811 ) ;
F_480 ( & V_1791 -> V_1812 , V_1813 ) ;
F_480 ( & V_1791 -> V_1814 , V_1815 ) ;
F_480 ( & V_1791 -> V_1816 , V_1817 ) ;
if ( F_269 ( F_23 ( V_5 , 5719_5720_RDMA_BUG ) &&
( V_1791 -> V_1812 . V_480 + V_1791 -> V_1814 . V_480 +
V_1791 -> V_1816 . V_480 ) > V_1707 ) ) {
T_1 V_7 ;
V_7 = F_33 ( V_1661 ) ;
V_7 &= ~ F_464 ( V_5 ) ;
F_46 ( V_1661 , V_7 ) ;
F_86 ( V_5 , 5719_5720_RDMA_BUG ) ;
}
F_480 ( & V_1791 -> V_1818 , V_1819 ) ;
F_480 ( & V_1791 -> V_1820 , V_1821 ) ;
F_480 ( & V_1791 -> V_1822 , V_1823 ) ;
F_480 ( & V_1791 -> V_1824 , V_1825 ) ;
F_480 ( & V_1791 -> V_1826 , V_1827 ) ;
F_480 ( & V_1791 -> V_1828 , V_1829 ) ;
F_480 ( & V_1791 -> V_1830 , V_1831 ) ;
F_480 ( & V_1791 -> V_1832 , V_1833 ) ;
F_480 ( & V_1791 -> V_1834 , V_1835 ) ;
F_480 ( & V_1791 -> V_1836 , V_1837 ) ;
F_480 ( & V_1791 -> V_1838 , V_1839 ) ;
F_480 ( & V_1791 -> V_1840 , V_1841 ) ;
F_480 ( & V_1791 -> V_1842 , V_1843 ) ;
F_480 ( & V_1791 -> V_1844 , V_1845 ) ;
F_480 ( & V_1791 -> V_1846 , V_1847 ) ;
if ( F_30 ( V_5 ) != V_471 &&
F_30 ( V_5 ) != V_762 &&
F_77 ( V_5 ) != V_1613 &&
F_77 ( V_5 ) != V_1614 ) {
F_480 ( & V_1791 -> V_1848 , V_1849 ) ;
} else {
T_1 V_7 = F_33 ( V_1223 ) ;
V_7 = ( V_7 & V_1224 ) ? 1 : 0 ;
if ( V_7 ) {
F_46 ( V_1223 , V_1224 ) ;
V_1791 -> V_1848 . V_480 += V_7 ;
if ( V_1791 -> V_1848 . V_480 < V_7 )
V_1791 -> V_1848 . V_481 += 1 ;
}
V_1791 -> V_1850 = V_1791 -> V_1848 ;
}
F_480 ( & V_1791 -> V_1851 , V_1852 ) ;
}
static void F_481 ( struct V_4 * V_5 )
{
T_1 V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( F_50 ( V_131 ) ) {
if ( V_131 -> V_1492 == V_131 -> V_149 &&
V_131 -> V_1493 == V_131 -> V_147 ) {
if ( V_131 -> V_1491 < 1 ) {
V_131 -> V_1491 ++ ;
return;
}
F_351 ( 0 , V_131 ) ;
}
}
V_131 -> V_1491 = 0 ;
V_131 -> V_1492 = V_131 -> V_149 ;
V_131 -> V_1493 = V_131 -> V_147 ;
}
}
static void F_482 ( unsigned long V_1853 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1853 ;
F_318 ( & V_5 -> V_209 ) ;
if ( V_5 -> V_125 || F_23 ( V_5 , V_1218 ) ) {
F_319 ( & V_5 -> V_209 ) ;
goto V_1854;
}
if ( F_30 ( V_5 ) == V_471 ||
F_23 ( V_5 , 57765_CLASS ) )
F_481 ( V_5 ) ;
if ( F_23 ( V_5 , V_30 ) ) {
F_33 ( V_138 ) ;
}
if ( ! F_23 ( V_5 , V_133 ) ) {
if ( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & V_135 ) {
F_46 ( V_136 ,
V_5 -> V_22 | V_137 ) ;
} else {
F_46 ( V_138 , V_5 -> V_127 |
V_128 | V_1855 ) ;
}
if ( ! ( F_33 ( V_1061 ) & V_1375 ) ) {
F_319 ( & V_5 -> V_209 ) ;
F_324 ( V_5 ) ;
goto V_1854;
}
}
if ( ! -- V_5 -> V_1856 ) {
if ( F_23 ( V_5 , 5705_PLUS ) )
F_479 ( V_5 ) ;
if ( V_5 -> V_334 && ! -- V_5 -> V_334 )
F_136 ( V_5 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
T_1 V_1857 ;
int V_1858 ;
V_1857 = F_33 ( V_787 ) ;
V_1858 = 0 ;
if ( V_5 -> V_178 & V_813 ) {
if ( V_1857 & V_1859 )
V_1858 = 1 ;
} else if ( V_1857 & V_791 )
V_1858 = 1 ;
if ( V_1858 )
F_203 ( V_5 , false ) ;
} else if ( F_23 ( V_5 , V_143 ) ) {
T_1 V_1857 = F_33 ( V_787 ) ;
int V_1860 = 0 ;
if ( V_5 -> V_335 &&
( V_1857 & V_791 ) ) {
V_1860 = 1 ;
}
if ( ! V_5 -> V_335 &&
( V_1857 & ( V_908 |
V_923 ) ) ) {
V_1860 = 1 ;
}
if ( V_1860 ) {
if ( ! V_5 -> V_920 ) {
F_31 ( V_377 ,
( V_5 -> V_362 &
~ V_365 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_377 , V_5 -> V_362 ) ;
F_24 ( 40 ) ;
}
F_203 ( V_5 , false ) ;
}
} else if ( ( V_5 -> V_178 & V_300 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_235 ( V_5 ) ;
} else if ( F_23 ( V_5 , V_1861 ) ) {
T_1 V_1862 = F_33 ( V_1863 ) ;
bool V_335 = ! ( ( V_1862 & V_1864 ) ==
V_1864 ) ;
if ( V_335 != V_5 -> V_335 )
F_203 ( V_5 , false ) ;
}
V_5 -> V_1856 = V_5 -> V_1865 ;
}
if ( ! -- V_5 -> V_1866 ) {
if ( F_23 ( V_5 , V_303 ) && ! F_23 ( V_5 , V_60 ) ) {
F_88 ( V_5 ) ;
F_29 ( V_5 , V_304 ,
V_1867 ) ;
F_29 ( V_5 , V_306 , 4 ) ;
F_29 ( V_5 , V_307 ,
V_1868 ) ;
F_87 ( V_5 ) ;
}
V_5 -> V_1866 = V_5 -> V_1869 ;
}
F_319 ( & V_5 -> V_209 ) ;
V_1854:
V_5 -> V_1870 . V_1871 = V_293 + V_5 -> V_1872 ;
F_483 ( & V_5 -> V_1870 ) ;
}
static void F_484 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_133 ) &&
F_30 ( V_5 ) != V_471 &&
! F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_1872 = V_1873 ;
else
V_5 -> V_1872 = V_1873 / 10 ;
F_186 ( V_5 -> V_1872 > V_1873 ) ;
V_5 -> V_1865 = ( V_1873 / V_5 -> V_1872 ) ;
V_5 -> V_1869 = ( V_1873 / V_5 -> V_1872 ) *
V_1874 ;
F_485 ( & V_5 -> V_1870 ) ;
V_5 -> V_1870 . V_72 = ( unsigned long ) V_5 ;
V_5 -> V_1870 . V_1875 = F_482 ;
}
static void F_486 ( struct V_4 * V_5 )
{
V_5 -> V_1866 = V_5 -> V_1869 ;
V_5 -> V_1856 = V_5 -> V_1865 ;
V_5 -> V_1870 . V_1871 = V_293 + V_5 -> V_1872 ;
F_483 ( & V_5 -> V_1870 ) ;
}
static void F_487 ( struct V_4 * V_5 )
{
F_488 ( & V_5 -> V_1870 ) ;
}
static int F_489 ( struct V_4 * V_5 , bool V_1533 )
__releases( V_5 -> V_209 )
__acquires( V_5 -> V_209 )
{
int V_75 ;
V_75 = F_470 ( V_5 , V_1533 ) ;
if ( V_75 ) {
F_187 ( V_5 -> V_111 ,
L_58 ) ;
F_435 ( V_5 , V_110 , 1 ) ;
F_244 ( V_5 ) ;
F_487 ( V_5 ) ;
V_5 -> V_125 = 0 ;
F_337 ( V_5 ) ;
F_490 ( V_5 -> V_111 ) ;
F_243 ( V_5 , 0 ) ;
}
return V_75 ;
}
static void F_491 ( struct V_1876 * V_1877 )
{
struct V_4 * V_5 = F_241 ( V_1877 , struct V_4 , V_1217 ) ;
int V_75 ;
F_492 () ;
F_243 ( V_5 , 0 ) ;
if ( ! F_146 ( V_5 -> V_111 ) ) {
F_86 ( V_5 , V_1218 ) ;
F_244 ( V_5 ) ;
F_493 () ;
return;
}
F_244 ( V_5 ) ;
F_124 ( V_5 ) ;
F_343 ( V_5 ) ;
F_243 ( V_5 , 1 ) ;
if ( F_23 ( V_5 , V_1090 ) ) {
V_5 -> V_1089 = F_26 ;
V_5 -> V_1878 = F_17 ;
F_84 ( V_5 , V_31 ) ;
F_86 ( V_5 , V_1090 ) ;
}
F_435 ( V_5 , V_110 , 0 ) ;
V_75 = F_470 ( V_5 , true ) ;
if ( V_75 )
goto V_497;
F_346 ( V_5 ) ;
V_497:
F_244 ( V_5 ) ;
if ( ! V_75 )
F_121 ( V_5 ) ;
F_86 ( V_5 , V_1218 ) ;
F_493 () ;
}
static int F_494 ( struct V_4 * V_5 , int V_1879 )
{
T_17 V_1880 ;
unsigned long V_10 ;
char * V_268 ;
struct V_130 * V_131 = & V_5 -> V_123 [ V_1879 ] ;
if ( V_5 -> V_129 == 1 )
V_268 = V_5 -> V_111 -> V_268 ;
else {
V_268 = & V_131 -> V_1881 [ 0 ] ;
if ( V_131 -> V_1101 && V_131 -> V_1158 )
snprintf ( V_268 , V_1882 ,
L_59 , V_5 -> V_111 -> V_268 , V_1879 ) ;
else if ( V_131 -> V_1101 )
snprintf ( V_268 , V_1882 ,
L_60 , V_5 -> V_111 -> V_268 , V_1879 ) ;
else if ( V_131 -> V_1158 )
snprintf ( V_268 , V_1882 ,
L_61 , V_5 -> V_111 -> V_268 , V_1879 ) ;
else
snprintf ( V_268 , V_1882 ,
L_62 , V_5 -> V_111 -> V_268 , V_1879 ) ;
V_268 [ V_1882 - 1 ] = 0 ;
}
if ( F_23 ( V_5 , V_1395 ) || F_23 ( V_5 , V_1688 ) ) {
V_1880 = F_351 ;
if ( F_23 ( V_5 , 1SHOT_MSI ) )
V_1880 = F_350 ;
V_10 = 0 ;
} else {
V_1880 = F_353 ;
if ( F_23 ( V_5 , V_133 ) )
V_1880 = F_354 ;
V_10 = V_1883 ;
}
return F_495 ( V_131 -> V_1230 , V_1880 , V_10 , V_268 , V_131 ) ;
}
static int F_496 ( struct V_4 * V_5 )
{
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
struct V_359 * V_111 = V_5 -> V_111 ;
int V_75 , V_42 , V_1884 = 0 ;
T_1 V_7 ;
if ( ! F_146 ( V_111 ) )
return - V_82 ;
F_45 ( V_5 ) ;
F_497 ( V_131 -> V_1230 , V_131 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1070 ) | V_1690 ;
F_46 ( V_1070 , V_7 ) ;
}
V_75 = F_495 ( V_131 -> V_1230 , F_355 ,
V_1883 , V_111 -> V_268 , V_131 ) ;
if ( V_75 )
return V_75 ;
V_131 -> V_134 -> V_57 &= ~ V_135 ;
F_48 ( V_5 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_131 -> V_126 ) ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ ) {
T_1 V_124 , V_120 ;
V_124 = F_498 ( V_131 -> V_124 ) ;
V_120 = F_33 ( V_119 ) ;
if ( ( V_124 != 0 ) ||
( V_120 & V_121 ) ) {
V_1884 = 1 ;
break;
}
if ( F_23 ( V_5 , 57765_PLUS ) &&
V_131 -> V_134 -> V_1076 != V_131 -> V_132 )
F_47 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
F_164 ( 10 ) ;
}
F_45 ( V_5 ) ;
F_497 ( V_131 -> V_1230 , V_131 ) ;
V_75 = F_494 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
if ( V_1884 ) {
if ( F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , 1SHOT_MSI ) ) {
V_7 = F_33 ( V_1070 ) & ~ V_1690 ;
F_46 ( V_1070 , V_7 ) ;
}
return 0 ;
}
return - V_210 ;
}
static int F_499 ( struct V_4 * V_5 )
{
int V_75 ;
T_3 V_1380 ;
if ( ! F_23 ( V_5 , V_1395 ) )
return 0 ;
F_425 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
F_427 ( V_5 -> V_12 , V_1379 ,
V_1380 & ~ V_1885 ) ;
V_75 = F_496 ( V_5 ) ;
F_427 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
if ( ! V_75 )
return 0 ;
if ( V_75 != - V_210 )
return V_75 ;
F_144 ( V_5 -> V_111 , L_63
L_64
L_65 ) ;
F_497 ( V_5 -> V_123 [ 0 ] . V_1230 , & V_5 -> V_123 [ 0 ] ) ;
F_500 ( V_5 -> V_12 ) ;
F_86 ( V_5 , V_1395 ) ;
V_5 -> V_123 [ 0 ] . V_1230 = V_5 -> V_12 -> V_1231 ;
V_75 = F_494 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
F_243 ( V_5 , 1 ) ;
F_435 ( V_5 , V_110 , 1 ) ;
V_75 = F_470 ( V_5 , true ) ;
F_244 ( V_5 ) ;
if ( V_75 )
F_497 ( V_5 -> V_123 [ 0 ] . V_1230 , & V_5 -> V_123 [ 0 ] ) ;
return V_75 ;
}
static int F_501 ( struct V_4 * V_5 )
{
const struct V_654 * V_655 ;
if ( F_502 ( & V_5 -> V_657 , V_5 -> V_1886 , & V_5 -> V_12 -> V_111 ) ) {
F_187 ( V_5 -> V_111 , L_66 ,
V_5 -> V_1886 ) ;
return - V_1887 ;
}
V_655 = (struct V_654 * ) V_5 -> V_657 -> V_72 ;
V_5 -> V_656 = F_174 ( V_655 -> V_74 ) ;
if ( V_5 -> V_656 < ( V_5 -> V_657 -> V_629 - V_658 ) ) {
F_187 ( V_5 -> V_111 , L_67 ,
V_5 -> V_656 , V_5 -> V_1886 ) ;
F_503 ( V_5 -> V_657 ) ;
V_5 -> V_657 = NULL ;
return - V_64 ;
}
V_5 -> V_1886 = NULL ;
return 0 ;
}
static T_1 F_504 ( struct V_4 * V_5 )
{
T_1 V_129 = F_505 ( V_5 -> V_1214 , V_5 -> V_1348 ) ;
if ( V_129 > 1 ) {
V_129 = F_506 ( unsigned , V_129 + 1 , V_5 -> V_122 ) ;
}
return V_129 ;
}
static bool F_507 ( struct V_4 * V_5 )
{
int V_42 , V_623 ;
struct V_1888 V_1889 [ V_1890 ] ;
V_5 -> V_1348 = V_5 -> V_1891 ;
V_5 -> V_1214 = V_5 -> V_1892 ;
if ( ! V_5 -> V_1214 )
V_5 -> V_1214 = F_508 () ;
if ( V_5 -> V_1214 > V_5 -> V_1893 )
V_5 -> V_1214 = V_5 -> V_1893 ;
if ( ! V_5 -> V_1891 )
V_5 -> V_1348 = 1 ;
V_5 -> V_129 = F_504 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
V_1889 [ V_42 ] . V_1249 = V_42 ;
V_1889 [ V_42 ] . V_1894 = 0 ;
}
V_623 = F_509 ( V_5 -> V_12 , V_1889 , 1 , V_5 -> V_129 ) ;
if ( V_623 < 0 ) {
return false ;
} else if ( V_623 < V_5 -> V_129 ) {
F_510 ( V_5 -> V_111 , L_68 ,
V_5 -> V_129 , V_623 ) ;
V_5 -> V_129 = V_623 ;
V_5 -> V_1214 = F_505 ( V_623 - 1 , 1 ) ;
if ( V_5 -> V_1348 )
V_5 -> V_1348 = F_322 ( V_5 -> V_1214 , V_5 -> V_1895 ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1230 = V_1889 [ V_42 ] . V_1894 ;
if ( F_511 ( V_5 -> V_111 , V_5 -> V_1214 ) ) {
F_512 ( V_5 -> V_12 ) ;
return false ;
}
if ( V_5 -> V_129 == 1 )
return true ;
F_84 ( V_5 , V_1203 ) ;
if ( V_5 -> V_1348 > 1 )
F_84 ( V_5 , V_1098 ) ;
F_513 ( V_5 -> V_111 , V_5 -> V_1348 ) ;
return true ;
}
static void F_514 ( struct V_4 * V_5 )
{
if ( ( F_23 ( V_5 , V_1896 ) || F_23 ( V_5 , V_1056 ) ) &&
! F_23 ( V_5 , V_133 ) ) {
F_144 ( V_5 -> V_111 ,
L_69 ) ;
goto V_1897;
}
if ( F_23 ( V_5 , V_1056 ) && F_507 ( V_5 ) )
F_84 ( V_5 , V_1688 ) ;
else if ( F_23 ( V_5 , V_1896 ) && F_515 ( V_5 -> V_12 ) == 0 )
F_84 ( V_5 , V_1395 ) ;
if ( F_23 ( V_5 , V_1395 ) || F_23 ( V_5 , V_1688 ) ) {
T_1 V_1898 = F_33 ( V_1070 ) ;
if ( F_23 ( V_5 , V_1688 ) && V_5 -> V_129 > 1 )
V_1898 |= V_1689 ;
if ( ! F_23 ( V_5 , 1SHOT_MSI ) )
V_1898 |= V_1690 ;
F_46 ( V_1070 , V_1898 | V_1400 ) ;
}
V_1897:
if ( ! F_23 ( V_5 , V_1688 ) ) {
V_5 -> V_129 = 1 ;
V_5 -> V_123 [ 0 ] . V_1230 = V_5 -> V_12 -> V_1231 ;
}
if ( V_5 -> V_129 == 1 ) {
V_5 -> V_1348 = 1 ;
V_5 -> V_1214 = 1 ;
F_513 ( V_5 -> V_111 , 1 ) ;
F_511 ( V_5 -> V_111 , 1 ) ;
}
}
static void F_516 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1688 ) )
F_512 ( V_5 -> V_12 ) ;
else if ( F_23 ( V_5 , V_1395 ) )
F_500 ( V_5 -> V_12 ) ;
F_86 ( V_5 , V_1395 ) ;
F_86 ( V_5 , V_1688 ) ;
F_86 ( V_5 , V_1203 ) ;
F_86 ( V_5 , V_1098 ) ;
}
static int F_517 ( struct V_4 * V_5 , bool V_1533 , bool V_1899 ,
bool V_1900 )
{
struct V_359 * V_111 = V_5 -> V_111 ;
int V_42 , V_75 ;
F_514 ( V_5 ) ;
F_462 ( V_5 ) ;
V_75 = F_421 ( V_5 ) ;
if ( V_75 )
goto V_1901;
F_339 ( V_5 ) ;
F_337 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_75 = F_494 ( V_5 , V_42 ) ;
if ( V_75 ) {
for ( V_42 -- ; V_42 >= 0 ; V_42 -- ) {
V_131 = & V_5 -> V_123 [ V_42 ] ;
F_497 ( V_131 -> V_1230 , V_131 ) ;
}
goto V_1902;
}
}
F_243 ( V_5 , 0 ) ;
if ( V_1900 )
F_42 ( V_5 , V_96 ) ;
V_75 = F_470 ( V_5 , V_1533 ) ;
if ( V_75 ) {
F_435 ( V_5 , V_110 , 1 ) ;
F_411 ( V_5 ) ;
}
F_244 ( V_5 ) ;
if ( V_75 )
goto V_1903;
if ( V_1899 && F_23 ( V_5 , V_1395 ) ) {
V_75 = F_499 ( V_5 ) ;
if ( V_75 ) {
F_243 ( V_5 , 0 ) ;
F_435 ( V_5 , V_110 , 1 ) ;
F_411 ( V_5 ) ;
F_244 ( V_5 ) ;
goto V_1902;
}
if ( ! F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , V_1395 ) ) {
T_1 V_7 = F_33 ( V_1904 ) ;
F_46 ( V_1904 ,
V_7 | V_1905 ) ;
}
}
F_121 ( V_5 ) ;
F_477 ( V_5 ) ;
F_243 ( V_5 , 0 ) ;
F_486 ( V_5 ) ;
F_84 ( V_5 , V_557 ) ;
F_48 ( V_5 ) ;
F_256 ( V_5 ) ;
F_244 ( V_5 ) ;
F_518 ( V_111 ) ;
if ( V_111 -> V_1184 & V_1327 )
F_397 ( V_111 , V_111 -> V_1184 ) ;
return 0 ;
V_1903:
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_497 ( V_131 -> V_1230 , V_131 ) ;
}
V_1902:
F_335 ( V_5 ) ;
F_341 ( V_5 ) ;
F_420 ( V_5 ) ;
V_1901:
F_516 ( V_5 ) ;
return V_75 ;
}
static void F_519 ( struct V_4 * V_5 )
{
int V_42 ;
F_327 ( V_5 ) ;
F_343 ( V_5 ) ;
F_487 ( V_5 ) ;
F_475 ( V_5 ) ;
F_124 ( V_5 ) ;
F_243 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_435 ( V_5 , V_110 , 1 ) ;
F_411 ( V_5 ) ;
F_86 ( V_5 , V_557 ) ;
F_244 ( V_5 ) ;
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_497 ( V_131 -> V_1230 , V_131 ) ;
}
F_516 ( V_5 ) ;
F_341 ( V_5 ) ;
F_420 ( V_5 ) ;
}
static int F_520 ( struct V_359 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 ;
if ( V_5 -> V_1906 ) {
F_187 ( V_111 , L_70
L_71 ) ;
return - V_85 ;
}
if ( V_5 -> V_1886 ) {
V_75 = F_501 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_662 ) {
if ( V_75 ) {
F_144 ( V_5 -> V_111 , L_72 ) ;
V_5 -> V_178 &= ~ V_333 ;
} else if ( ! ( V_5 -> V_178 & V_333 ) ) {
F_144 ( V_5 -> V_111 , L_73 ) ;
V_5 -> V_178 |= V_333 ;
}
} else if ( F_77 ( V_5 ) == V_754 ) {
if ( V_75 )
return V_75 ;
} else if ( V_75 ) {
F_144 ( V_5 -> V_111 , L_74 ) ;
F_86 ( V_5 , V_1595 ) ;
} else if ( ! F_23 ( V_5 , V_1595 ) ) {
F_510 ( V_5 -> V_111 , L_75 ) ;
F_84 ( V_5 , V_1595 ) ;
}
}
F_141 ( V_5 ) ;
V_75 = F_199 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_243 ( V_5 , 0 ) ;
F_45 ( V_5 ) ;
F_86 ( V_5 , V_557 ) ;
F_244 ( V_5 ) ;
V_75 = F_517 ( V_5 ,
! ( V_5 -> V_178 & V_564 ) ,
true , true ) ;
if ( V_75 ) {
F_153 ( V_5 , false ) ;
F_200 ( V_5 -> V_12 , V_738 ) ;
}
return V_75 ;
}
static int F_521 ( struct V_359 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_5 -> V_1906 ) {
F_187 ( V_111 , L_76
L_71 ) ;
return - V_85 ;
}
F_519 ( V_5 ) ;
if ( F_432 ( V_5 -> V_12 ) ) {
F_201 ( V_5 ) ;
F_141 ( V_5 ) ;
}
return 0 ;
}
static inline T_6 F_522 ( T_18 * V_7 )
{
return ( ( T_6 ) V_7 -> V_481 << 32 ) | ( ( T_6 ) V_7 -> V_480 ) ;
}
static T_6 F_523 ( struct V_4 * V_5 )
{
struct V_1352 * V_1351 = V_5 -> V_1351 ;
if ( ! ( V_5 -> V_178 & V_562 ) &&
( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 ) ) {
T_1 V_7 ;
if ( ! F_57 ( V_5 , V_514 , & V_7 ) ) {
F_59 ( V_5 , V_514 ,
V_7 | V_1739 ) ;
F_57 ( V_5 , V_1740 , & V_7 ) ;
} else
V_7 = 0 ;
V_5 -> V_1907 += V_7 ;
return V_5 -> V_1907 ;
}
return F_522 ( & V_1351 -> V_1828 ) ;
}
static void F_437 ( struct V_4 * V_5 , struct V_1908 * V_1909 )
{
struct V_1908 * V_1910 = & V_5 -> V_1440 ;
struct V_1352 * V_1351 = V_5 -> V_1351 ;
F_524 ( V_1818 ) ;
F_524 ( V_1820 ) ;
F_524 ( V_1822 ) ;
F_524 ( V_1824 ) ;
F_524 ( V_1826 ) ;
F_524 ( V_1828 ) ;
F_524 ( V_1830 ) ;
F_524 ( V_1832 ) ;
F_524 ( V_1834 ) ;
F_524 ( V_1836 ) ;
F_524 ( V_1838 ) ;
F_524 ( V_1840 ) ;
F_524 ( V_1842 ) ;
F_524 ( V_1844 ) ;
F_524 ( V_1911 ) ;
F_524 ( V_1912 ) ;
F_524 ( V_1913 ) ;
F_524 ( V_1914 ) ;
F_524 ( V_1915 ) ;
F_524 ( V_1916 ) ;
F_524 ( V_1917 ) ;
F_524 ( V_1918 ) ;
F_524 ( V_1919 ) ;
F_524 ( V_1920 ) ;
F_524 ( V_1921 ) ;
F_524 ( V_1922 ) ;
F_524 ( V_1792 ) ;
F_524 ( V_1794 ) ;
F_524 ( V_1796 ) ;
F_524 ( V_1798 ) ;
F_524 ( V_1923 ) ;
F_524 ( V_1800 ) ;
F_524 ( V_1802 ) ;
F_524 ( V_1804 ) ;
F_524 ( V_1806 ) ;
F_524 ( V_1808 ) ;
F_524 ( V_1810 ) ;
F_524 ( V_1924 ) ;
F_524 ( V_1925 ) ;
F_524 ( V_1926 ) ;
F_524 ( V_1927 ) ;
F_524 ( V_1928 ) ;
F_524 ( V_1929 ) ;
F_524 ( V_1930 ) ;
F_524 ( V_1931 ) ;
F_524 ( V_1932 ) ;
F_524 ( V_1933 ) ;
F_524 ( V_1934 ) ;
F_524 ( V_1935 ) ;
F_524 ( V_1936 ) ;
F_524 ( V_1937 ) ;
F_524 ( V_1812 ) ;
F_524 ( V_1814 ) ;
F_524 ( V_1816 ) ;
F_524 ( V_1938 ) ;
F_524 ( V_1939 ) ;
F_524 ( V_1940 ) ;
F_524 ( V_1941 ) ;
F_524 ( V_1942 ) ;
F_524 ( V_1846 ) ;
F_524 ( V_1848 ) ;
F_524 ( V_1851 ) ;
F_524 ( V_1943 ) ;
F_524 ( V_1944 ) ;
F_524 ( V_1945 ) ;
F_524 ( V_1946 ) ;
F_524 ( V_1947 ) ;
F_524 ( V_1948 ) ;
F_524 ( V_1949 ) ;
F_524 ( V_1950 ) ;
F_524 ( V_1951 ) ;
F_524 ( V_1850 ) ;
}
static void F_436 ( struct V_4 * V_5 , struct V_1952 * V_1953 )
{
struct V_1952 * V_1954 = & V_5 -> V_1439 ;
struct V_1352 * V_1351 = V_5 -> V_1351 ;
V_1953 -> V_1955 = V_1954 -> V_1955 +
F_522 ( & V_1351 -> V_1822 ) +
F_522 ( & V_1351 -> V_1824 ) +
F_522 ( & V_1351 -> V_1826 ) ;
V_1953 -> V_1956 = V_1954 -> V_1956 +
F_522 ( & V_1351 -> V_1812 ) +
F_522 ( & V_1351 -> V_1814 ) +
F_522 ( & V_1351 -> V_1816 ) ;
V_1953 -> V_1957 = V_1954 -> V_1957 +
F_522 ( & V_1351 -> V_1818 ) ;
V_1953 -> V_1958 = V_1954 -> V_1958 +
F_522 ( & V_1351 -> V_1792 ) ;
V_1953 -> V_1851 = V_1954 -> V_1851 +
F_522 ( & V_1351 -> V_1851 ) ;
V_1953 -> V_1940 = V_1954 -> V_1940 +
F_522 ( & V_1351 -> V_1940 ) +
F_522 ( & V_1351 -> V_1800 ) +
F_522 ( & V_1351 -> V_1938 ) +
F_522 ( & V_1351 -> V_1939 ) ;
V_1953 -> V_1959 = V_1954 -> V_1959 +
F_522 ( & V_1351 -> V_1824 ) ;
V_1953 -> V_1960 = V_1954 -> V_1960 +
F_522 ( & V_1351 -> V_1794 ) ;
V_1953 -> V_1961 = V_1954 -> V_1961 +
F_522 ( & V_1351 -> V_1840 ) +
F_522 ( & V_1351 -> V_1844 ) ;
V_1953 -> V_1962 = V_1954 -> V_1962 +
F_522 ( & V_1351 -> V_1830 ) ;
V_1953 -> V_1963 = V_1954 -> V_1963 +
F_522 ( & V_1351 -> V_1939 ) ;
V_1953 -> V_1964 = V_1954 -> V_1964 +
F_522 ( & V_1351 -> V_1938 ) ;
V_1953 -> V_1965 = V_1954 -> V_1965 +
F_523 ( V_5 ) ;
V_1953 -> V_1966 = V_1954 -> V_1966 +
F_522 ( & V_1351 -> V_1848 ) ;
V_1953 -> V_1171 = V_5 -> V_1171 ;
V_1953 -> V_1318 = V_5 -> V_1318 ;
}
static int F_525 ( struct V_359 * V_111 )
{
return V_1072 ;
}
static void F_526 ( struct V_359 * V_111 ,
struct V_1967 * V_8 , void * V_1968 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_8 -> V_1969 = 0 ;
memset ( V_1968 , 0 , V_1072 ) ;
if ( V_5 -> V_178 & V_394 )
return;
F_243 ( V_5 , 0 ) ;
F_261 ( V_5 , ( T_1 * ) V_1968 ) ;
F_244 ( V_5 ) ;
}
static int F_527 ( struct V_359 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
return V_5 -> V_1970 ;
}
static int F_528 ( struct V_359 * V_111 , struct V_1971 * V_1972 , T_4 * V_72 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_56 , V_1973 = 0 ;
T_4 * V_1974 ;
T_1 V_42 , V_590 , V_74 , V_1975 , V_1976 , V_1977 = 0 ;
T_5 V_7 ;
if ( F_23 ( V_5 , V_676 ) )
return - V_64 ;
V_590 = V_1972 -> V_590 ;
V_74 = V_1972 -> V_74 ;
V_1972 -> V_74 = 0 ;
V_1972 -> V_1978 = V_1979 ;
if ( F_23 ( V_5 , V_152 ) ) {
V_1977 = F_33 ( V_499 ) ;
if ( V_1977 & ( V_1536 |
V_1537 ) ) {
F_46 ( V_499 , V_1977 &
~ ( V_1536 |
V_1537 ) ) ;
V_1973 = 1 ;
}
}
F_429 ( V_5 ) ;
if ( V_590 & 3 ) {
V_1975 = V_590 & 3 ;
V_1976 = 4 - V_1975 ;
if ( V_1976 > V_74 ) {
V_1976 = V_74 ;
}
V_56 = F_171 ( V_5 , V_590 - V_1975 , & V_7 ) ;
if ( V_56 )
goto V_1980;
memcpy ( V_72 , ( ( char * ) & V_7 ) + V_1975 , V_1976 ) ;
V_74 -= V_1976 ;
V_590 += V_1976 ;
V_1972 -> V_74 += V_1976 ;
}
V_1974 = & V_72 [ V_1972 -> V_74 ] ;
for ( V_42 = 0 ; V_42 < ( V_74 - ( V_74 & 3 ) ) ; V_42 += 4 ) {
V_56 = F_171 ( V_5 , V_590 + V_42 , & V_7 ) ;
if ( V_56 ) {
if ( V_42 )
V_42 -= 4 ;
V_1972 -> V_74 += V_42 ;
goto V_1980;
}
memcpy ( V_1974 + V_42 , & V_7 , 4 ) ;
if ( F_529 () ) {
if ( F_530 ( V_1981 ) ) {
V_1972 -> V_74 += V_42 ;
V_56 = - V_1982 ;
goto V_1980;
}
F_531 () ;
}
}
V_1972 -> V_74 += V_42 ;
if ( V_74 & 3 ) {
V_1974 = & V_72 [ V_1972 -> V_74 ] ;
V_1976 = V_74 & 3 ;
V_1975 = V_590 + V_74 - V_1976 ;
V_56 = F_171 ( V_5 , V_1975 , & V_7 ) ;
if ( V_56 )
goto V_1980;
memcpy ( V_1974 , & V_7 , V_1976 ) ;
V_1972 -> V_74 += V_1976 ;
}
V_56 = 0 ;
V_1980:
F_430 ( V_5 ) ;
if ( V_1973 )
F_46 ( V_499 , V_1977 ) ;
return V_56 ;
}
static int F_532 ( struct V_359 * V_111 , struct V_1971 * V_1972 , T_4 * V_72 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_56 ;
T_1 V_590 , V_74 , V_1975 , V_1983 ;
T_4 * V_621 ;
T_5 V_1023 = 0 , V_1984 ;
if ( F_23 ( V_5 , V_676 ) ||
V_1972 -> V_1978 != V_1979 )
return - V_64 ;
V_590 = V_1972 -> V_590 ;
V_74 = V_1972 -> V_74 ;
if ( ( V_1975 = ( V_590 & 3 ) ) ) {
V_56 = F_171 ( V_5 , V_590 - V_1975 , & V_1023 ) ;
if ( V_56 )
return V_56 ;
V_74 += V_1975 ;
V_590 &= ~ 3 ;
if ( V_74 < 4 )
V_74 = 4 ;
}
V_1983 = 0 ;
if ( V_74 & 3 ) {
V_1983 = 1 ;
V_74 = ( V_74 + 3 ) & ~ 3 ;
V_56 = F_171 ( V_5 , V_590 + V_74 - 4 , & V_1984 ) ;
if ( V_56 )
return V_56 ;
}
V_621 = V_72 ;
if ( V_1975 || V_1983 ) {
V_621 = F_176 ( V_74 , V_627 ) ;
if ( ! V_621 )
return - V_267 ;
if ( V_1975 )
memcpy ( V_621 , & V_1023 , 4 ) ;
if ( V_1983 )
memcpy ( V_621 + V_74 - 4 , & V_1984 , 4 ) ;
memcpy ( V_621 + V_1975 , V_72 , V_1972 -> V_74 ) ;
}
V_56 = F_179 ( V_5 , V_590 , V_74 , V_621 ) ;
if ( V_621 != V_72 )
F_177 ( V_621 ) ;
return V_56 ;
}
static int F_533 ( struct V_359 * V_111 ,
struct V_1985 * V_637 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_388 , V_393 ;
if ( F_23 ( V_5 , V_266 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_386 ) )
return - V_85 ;
V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
F_534 ( V_212 , V_637 ) ;
return 0 ;
}
V_388 = ( V_1986 ) ;
if ( ! ( V_5 -> V_178 & V_387 ) )
V_388 |= ( V_1987 |
V_1988 ) ;
if ( ! ( V_5 -> V_178 & V_354 ) ) {
V_388 |= ( V_1989 |
V_1990 |
V_1991 |
V_1992 |
V_1993 ) ;
V_637 -> V_1238 . V_1994 = V_1995 ;
} else {
V_388 |= V_1996 ;
V_637 -> V_1238 . V_1994 = V_1997 ;
}
F_535 ( V_637 -> V_1998 . V_388 ,
V_388 ) ;
V_393 = V_5 -> V_324 . V_393 ;
if ( F_23 ( V_5 , V_353 ) ) {
if ( V_5 -> V_324 . V_337 & V_332 ) {
if ( V_5 -> V_324 . V_337 & V_331 ) {
V_393 |= V_699 ;
} else {
V_393 |= V_699 |
V_1999 ;
}
} else if ( V_5 -> V_324 . V_337 & V_331 ) {
V_393 |= V_1999 ;
}
}
F_535 ( V_637 -> V_1998 . V_393 ,
V_393 ) ;
if ( F_146 ( V_111 ) && V_5 -> V_335 ) {
V_637 -> V_1238 . V_367 = V_5 -> V_324 . V_325 ;
V_637 -> V_1238 . V_371 = V_5 -> V_324 . V_328 ;
F_535 (
V_637 -> V_1998 . V_2000 ,
V_5 -> V_324 . V_364 ) ;
if ( ! ( V_5 -> V_178 & V_354 ) ) {
if ( V_5 -> V_178 & V_818 )
V_637 -> V_1238 . V_2001 = V_2002 ;
else
V_637 -> V_1238 . V_2001 = V_2003 ;
}
} else {
V_637 -> V_1238 . V_367 = V_748 ;
V_637 -> V_1238 . V_371 = V_749 ;
V_637 -> V_1238 . V_2001 = V_2004 ;
}
V_637 -> V_1238 . V_2005 = V_5 -> V_160 ;
V_637 -> V_1238 . V_347 = V_5 -> V_324 . V_347 ;
return 0 ;
}
static int F_536 ( struct V_359 * V_111 ,
const struct V_1985 * V_637 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_367 = V_637 -> V_1238 . V_367 ;
T_1 V_393 ;
if ( F_23 ( V_5 , V_266 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_386 ) )
return - V_85 ;
V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
return F_537 ( V_212 , V_637 ) ;
}
if ( V_637 -> V_1238 . V_347 != V_352 &&
V_637 -> V_1238 . V_347 != V_774 )
return - V_64 ;
if ( V_637 -> V_1238 . V_347 == V_774 &&
V_637 -> V_1238 . V_371 != V_329 &&
V_637 -> V_1238 . V_371 != V_372 )
return - V_64 ;
F_538 ( & V_393 ,
V_637 -> V_1998 . V_393 ) ;
if ( V_637 -> V_1238 . V_347 == V_352 ) {
T_1 V_2006 = V_700 |
V_699 |
V_1999 ;
if ( ! ( V_5 -> V_178 & V_387 ) )
V_2006 |= V_768 |
V_758 ;
if ( ! ( V_5 -> V_178 & V_354 ) )
V_2006 |= V_703 |
V_704 |
V_701 |
V_705 |
V_698 ;
else
V_2006 |= V_775 ;
if ( V_393 & ~ V_2006 )
return - V_64 ;
V_2006 &= ( V_768 |
V_758 |
V_703 |
V_704 |
V_701 |
V_705 ) ;
V_393 &= V_2006 ;
} else {
if ( V_5 -> V_178 & V_354 ) {
if ( V_367 != V_326 )
return - V_64 ;
if ( V_637 -> V_1238 . V_371 != V_329 )
return - V_64 ;
} else {
if ( V_367 != V_327 &&
V_367 != V_368 )
return - V_64 ;
}
}
F_243 ( V_5 , 0 ) ;
V_5 -> V_324 . V_347 = V_637 -> V_1238 . V_347 ;
if ( V_637 -> V_1238 . V_347 == V_352 ) {
V_5 -> V_324 . V_393 = ( V_393 |
V_700 ) ;
V_5 -> V_324 . V_367 = V_748 ;
V_5 -> V_324 . V_371 = V_749 ;
} else {
V_5 -> V_324 . V_393 = 0 ;
V_5 -> V_324 . V_367 = V_367 ;
V_5 -> V_324 . V_371 = V_637 -> V_1238 . V_371 ;
}
V_5 -> V_178 |= V_1535 ;
F_143 ( V_5 ) ;
if ( F_146 ( V_111 ) )
F_203 ( V_5 , true ) ;
F_244 ( V_5 ) ;
return 0 ;
}
static void F_539 ( struct V_359 * V_111 , struct V_2007 * V_982 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_540 ( V_982 -> V_2008 , V_2009 , sizeof( V_982 -> V_2008 ) ) ;
F_540 ( V_982 -> V_1969 , V_2010 , sizeof( V_982 -> V_1969 ) ) ;
F_540 ( V_982 -> V_2011 , V_5 -> V_2012 , sizeof( V_982 -> V_2011 ) ) ;
F_540 ( V_982 -> V_2013 , F_541 ( V_5 -> V_12 ) , sizeof( V_982 -> V_2013 ) ) ;
}
static void F_542 ( struct V_359 * V_111 , struct V_2014 * V_2015 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_23 ( V_5 , V_712 ) && F_543 ( & V_5 -> V_12 -> V_111 ) )
V_2015 -> V_388 = V_2016 ;
else
V_2015 -> V_388 = 0 ;
V_2015 -> V_2017 = 0 ;
if ( F_23 ( V_5 , V_112 ) && F_543 ( & V_5 -> V_12 -> V_111 ) )
V_2015 -> V_2017 = V_2016 ;
memset ( & V_2015 -> V_2018 , 0 , sizeof( V_2015 -> V_2018 ) ) ;
}
static int F_544 ( struct V_359 * V_111 , struct V_2014 * V_2015 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_538 * V_2019 = & V_5 -> V_12 -> V_111 ;
if ( V_2015 -> V_2017 & ~ V_2016 )
return - V_64 ;
if ( ( V_2015 -> V_2017 & V_2016 ) &&
! ( F_23 ( V_5 , V_712 ) && F_543 ( V_2019 ) ) )
return - V_64 ;
F_545 ( V_2019 , V_2015 -> V_2017 & V_2016 ) ;
if ( F_44 ( V_2019 ) )
F_84 ( V_5 , V_112 ) ;
else
F_86 ( V_5 , V_112 ) ;
return 0 ;
}
static T_1 F_546 ( struct V_359 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
return V_5 -> V_2020 ;
}
static void F_547 ( struct V_359 * V_111 , T_1 V_2021 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_5 -> V_2020 = V_2021 ;
}
static int F_548 ( struct V_359 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_2022 ;
if ( ! F_146 ( V_111 ) )
return - V_85 ;
if ( V_5 -> V_178 & V_562 )
return - V_64 ;
F_143 ( V_5 ) ;
if ( F_23 ( V_5 , V_266 ) ) {
if ( ! ( V_5 -> V_178 & V_386 ) )
return - V_85 ;
V_2022 = F_123 ( F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ) ;
} else {
T_1 V_769 ;
F_70 ( & V_5 -> V_209 ) ;
V_2022 = - V_64 ;
F_57 ( V_5 , V_204 , & V_769 ) ;
if ( ! F_57 ( V_5 , V_204 , & V_769 ) &&
( ( V_769 & V_571 ) ||
( V_5 -> V_178 & V_785 ) ) ) {
F_59 ( V_5 , V_204 , V_769 | V_572 |
V_571 ) ;
V_2022 = 0 ;
}
F_71 ( & V_5 -> V_209 ) ;
}
return V_2022 ;
}
static void F_549 ( struct V_359 * V_111 , struct V_2023 * V_2024 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_2024 -> V_2025 = V_5 -> V_1133 ;
if ( F_23 ( V_5 , V_1340 ) )
V_2024 -> V_2026 = V_5 -> V_1138 ;
else
V_2024 -> V_2026 = 0 ;
V_2024 -> V_2027 = V_1091 - 1 ;
V_2024 -> V_1338 = V_5 -> V_1338 ;
if ( F_23 ( V_5 , V_1340 ) )
V_2024 -> V_1342 = V_5 -> V_1342 ;
else
V_2024 -> V_1342 = 0 ;
V_2024 -> V_1083 = V_5 -> V_123 [ 0 ] . V_1083 ;
}
static int F_550 ( struct V_359 * V_111 , struct V_2023 * V_2024 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_42 , V_125 = 0 , V_75 = 0 ;
if ( ( V_2024 -> V_1338 > V_5 -> V_1133 ) ||
( V_2024 -> V_1342 > V_5 -> V_1138 ) ||
( V_2024 -> V_1083 > V_1091 - 1 ) ||
( V_2024 -> V_1083 <= V_1315 ) ||
( F_23 ( V_5 , V_1288 ) &&
( V_2024 -> V_1083 <= ( V_1315 * 3 ) ) ) )
return - V_64 ;
if ( F_146 ( V_111 ) ) {
F_124 ( V_5 ) ;
F_343 ( V_5 ) ;
V_125 = 1 ;
}
F_243 ( V_5 , V_125 ) ;
V_5 -> V_1338 = V_2024 -> V_1338 ;
if ( F_23 ( V_5 , V_2028 ) &&
V_5 -> V_1338 > 63 )
V_5 -> V_1338 = 63 ;
if ( F_23 ( V_5 , V_1340 ) )
V_5 -> V_1342 = V_2024 -> V_1342 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1083 = V_2024 -> V_1083 ;
if ( F_146 ( V_111 ) ) {
F_435 ( V_5 , V_110 , 1 ) ;
V_75 = F_489 ( V_5 , false ) ;
if ( ! V_75 )
F_346 ( V_5 ) ;
}
F_244 ( V_5 ) ;
if ( V_125 && ! V_75 )
F_121 ( V_5 ) ;
return V_75 ;
}
static void F_551 ( struct V_359 * V_111 , struct V_2029 * V_2030 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
V_2030 -> V_347 = ! ! F_23 ( V_5 , V_353 ) ;
if ( V_5 -> V_324 . V_337 & V_332 )
V_2030 -> V_2031 = 1 ;
else
V_2030 -> V_2031 = 0 ;
if ( V_5 -> V_324 . V_337 & V_331 )
V_2030 -> V_2032 = 1 ;
else
V_2030 -> V_2032 = 0 ;
}
static int F_552 ( struct V_359 * V_111 , struct V_2029 * V_2030 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 = 0 ;
if ( V_5 -> V_324 . V_347 == V_352 )
F_143 ( V_5 ) ;
if ( F_23 ( V_5 , V_266 ) ) {
T_1 V_949 ;
struct V_211 * V_212 ;
V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
if ( ! ( V_212 -> V_388 & V_390 ) ||
( ! ( V_212 -> V_388 & V_391 ) &&
( V_2030 -> V_2031 != V_2030 -> V_2032 ) ) )
return - V_64 ;
V_5 -> V_324 . V_337 = 0 ;
if ( V_2030 -> V_2031 ) {
V_5 -> V_324 . V_337 |= V_332 ;
if ( V_2030 -> V_2032 ) {
V_5 -> V_324 . V_337 |= V_331 ;
V_949 = V_699 ;
} else
V_949 = V_699 |
V_1999 ;
} else if ( V_2030 -> V_2032 ) {
V_5 -> V_324 . V_337 |= V_331 ;
V_949 = V_1999 ;
} else
V_949 = 0 ;
if ( V_2030 -> V_347 )
F_84 ( V_5 , V_353 ) ;
else
F_86 ( V_5 , V_353 ) ;
if ( V_5 -> V_178 & V_386 ) {
T_1 V_2033 = V_212 -> V_393 &
( V_699 | V_1999 ) ;
if ( V_2033 != V_949 ) {
V_212 -> V_393 &=
~ ( V_699 |
V_1999 ) ;
V_212 -> V_393 |= V_949 ;
if ( V_212 -> V_347 ) {
return F_123 ( V_212 ) ;
}
}
if ( ! V_2030 -> V_347 )
F_108 ( V_5 , 0 , 0 ) ;
} else {
V_5 -> V_324 . V_393 &=
~ ( V_699 |
V_1999 ) ;
V_5 -> V_324 . V_393 |= V_949 ;
}
} else {
int V_125 = 0 ;
if ( F_146 ( V_111 ) ) {
F_343 ( V_5 ) ;
V_125 = 1 ;
}
F_243 ( V_5 , V_125 ) ;
if ( V_2030 -> V_347 )
F_84 ( V_5 , V_353 ) ;
else
F_86 ( V_5 , V_353 ) ;
if ( V_2030 -> V_2031 )
V_5 -> V_324 . V_337 |= V_332 ;
else
V_5 -> V_324 . V_337 &= ~ V_332 ;
if ( V_2030 -> V_2032 )
V_5 -> V_324 . V_337 |= V_331 ;
else
V_5 -> V_324 . V_337 &= ~ V_331 ;
if ( F_146 ( V_111 ) ) {
F_435 ( V_5 , V_110 , 1 ) ;
V_75 = F_489 ( V_5 , false ) ;
if ( ! V_75 )
F_346 ( V_5 ) ;
}
F_244 ( V_5 ) ;
}
V_5 -> V_178 |= V_1535 ;
return V_75 ;
}
static int F_553 ( struct V_359 * V_111 , int V_2034 )
{
switch ( V_2034 ) {
case V_2035 :
return V_2036 ;
case V_2037 :
return V_2038 ;
default:
return - V_1032 ;
}
}
static int F_554 ( struct V_359 * V_111 , struct V_2039 * V_982 ,
T_1 * T_19 V_2040 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1056 ) )
return - V_1032 ;
switch ( V_982 -> V_637 ) {
case V_2041 :
if ( F_146 ( V_5 -> V_111 ) )
V_982 -> V_72 = V_5 -> V_1214 ;
else {
V_982 -> V_72 = F_555 () ;
if ( V_982 -> V_72 > V_2042 )
V_982 -> V_72 = V_2042 ;
}
return 0 ;
default:
return - V_1032 ;
}
}
static T_1 F_556 ( struct V_359 * V_111 )
{
T_1 V_629 = 0 ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( F_23 ( V_5 , V_1056 ) )
V_629 = V_1528 ;
return V_629 ;
}
static int F_557 ( struct V_359 * V_111 , T_1 * V_2043 , T_4 * V_2044 , T_4 * V_2045 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_42 ;
if ( V_2045 )
* V_2045 = V_2046 ;
if ( ! V_2043 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_1528 ; V_42 ++ )
V_2043 [ V_42 ] = V_5 -> V_1529 [ V_42 ] ;
return 0 ;
}
static int F_558 ( struct V_359 * V_111 , const T_1 * V_2043 , const T_4 * V_2044 ,
const T_4 V_2045 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_20 V_42 ;
if ( V_2044 ||
( V_2045 != V_2047 && V_2045 != V_2046 ) )
return - V_1032 ;
if ( ! V_2043 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_1528 ; V_42 ++ )
V_5 -> V_1529 [ V_42 ] = V_2043 [ V_42 ] ;
if ( ! F_146 ( V_111 ) || ! F_23 ( V_5 , V_1203 ) )
return 0 ;
F_243 ( V_5 , 0 ) ;
F_463 ( V_5 ) ;
F_244 ( V_5 ) ;
return 0 ;
}
static void F_559 ( struct V_359 * V_111 ,
struct V_2048 * V_2049 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_2050 = F_508 () ;
V_2049 -> V_2051 = V_5 -> V_1893 ;
V_2049 -> V_2052 = V_5 -> V_1895 ;
if ( F_146 ( V_111 ) ) {
V_2049 -> V_2053 = V_5 -> V_1214 ;
V_2049 -> V_2054 = V_5 -> V_1348 ;
} else {
if ( V_5 -> V_1892 )
V_2049 -> V_2053 = V_5 -> V_1892 ;
else
V_2049 -> V_2053 = F_322 ( V_2050 , V_5 -> V_1893 ) ;
if ( V_5 -> V_1891 )
V_2049 -> V_2054 = V_5 -> V_1891 ;
else
V_2049 -> V_2054 = F_322 ( V_2050 , V_5 -> V_1895 ) ;
}
}
static int F_560 ( struct V_359 * V_111 ,
struct V_2048 * V_2049 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1056 ) )
return - V_1032 ;
if ( V_2049 -> V_2053 > V_5 -> V_1893 ||
V_2049 -> V_2054 > V_5 -> V_1895 )
return - V_64 ;
V_5 -> V_1892 = V_2049 -> V_2053 ;
V_5 -> V_1891 = V_2049 -> V_2054 ;
if ( ! F_146 ( V_111 ) )
return 0 ;
F_519 ( V_5 ) ;
F_141 ( V_5 ) ;
F_517 ( V_5 , true , false , false ) ;
return 0 ;
}
static void F_561 ( struct V_359 * V_111 , T_1 V_2055 , T_4 * V_621 )
{
switch ( V_2055 ) {
case V_2037 :
memcpy ( V_621 , & V_2056 , sizeof( V_2056 ) ) ;
break;
case V_2035 :
memcpy ( V_621 , & V_2057 , sizeof( V_2057 ) ) ;
break;
default:
F_562 ( 1 ) ;
break;
}
}
static int F_563 ( struct V_359 * V_111 ,
enum V_2058 V_843 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_146 ( V_5 -> V_111 ) )
return - V_85 ;
switch ( V_843 ) {
case V_2059 :
return 1 ;
case V_2060 :
F_46 ( V_722 , V_833 |
V_831 |
V_832 |
V_2061 |
V_937 |
V_2062 |
V_2063 ) ;
break;
case V_2064 :
F_46 ( V_722 , V_833 |
V_937 ) ;
break;
case V_2065 :
F_46 ( V_722 , V_5 -> V_558 ) ;
break;
}
return 0 ;
}
static void F_564 ( struct V_359 * V_111 ,
struct V_2066 * V_1909 , T_6 * V_2067 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( V_5 -> V_1351 )
F_437 ( V_5 , (struct V_1908 * ) V_2067 ) ;
else
memset ( V_2067 , 0 , sizeof( struct V_1908 ) ) ;
}
static T_5 * F_565 ( struct V_4 * V_5 , T_1 * V_2068 )
{
int V_42 ;
T_5 * V_621 ;
T_1 V_590 = 0 , V_74 = 0 ;
T_1 V_1978 , V_7 ;
if ( F_23 ( V_5 , V_676 ) || F_170 ( V_5 , 0 , & V_1978 ) )
return NULL ;
if ( V_1978 == V_1979 ) {
for ( V_590 = V_2069 ;
V_590 < V_2070 ;
V_590 += V_2071 ) {
if ( F_170 ( V_5 , V_590 , & V_7 ) )
return NULL ;
if ( ( V_7 >> V_2072 ) ==
V_2073 )
break;
}
if ( V_590 != V_2070 ) {
V_74 = ( V_7 & V_2074 ) * 4 ;
if ( F_170 ( V_5 , V_590 + 4 , & V_590 ) )
return NULL ;
V_590 = F_169 ( V_5 , V_590 ) ;
}
}
if ( ! V_590 || ! V_74 ) {
V_590 = V_2075 ;
V_74 = V_2076 ;
}
V_621 = F_176 ( V_74 , V_627 ) ;
if ( V_621 == NULL )
return NULL ;
if ( V_1978 == V_1979 ) {
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 ) {
if ( F_171 ( V_5 , V_590 + V_42 , & V_621 [ V_42 / 4 ] ) )
goto error;
}
} else {
T_4 * V_2077 ;
T_16 V_2078 ;
unsigned int V_2079 = 0 ;
V_2077 = ( T_4 * ) & V_621 [ 0 ] ;
for ( V_42 = 0 ; V_2079 < V_74 && V_42 < 3 ; V_42 ++ , V_2079 += V_2078 , V_2077 += V_2078 ) {
V_2078 = F_566 ( V_5 -> V_12 , V_2079 ,
V_74 - V_2079 , V_2077 ) ;
if ( V_2078 == - V_2080 || V_2078 == - V_1982 )
V_2078 = 0 ;
else if ( V_2078 < 0 )
goto error;
}
if ( V_2079 != V_74 )
goto error;
}
* V_2068 = V_74 ;
return V_621 ;
error:
F_177 ( V_621 ) ;
return NULL ;
}
static int F_567 ( struct V_4 * V_5 )
{
T_1 V_2081 , V_1978 , V_74 ;
T_5 * V_621 ;
int V_42 , V_622 , V_1510 , V_75 = 0 , V_629 ;
if ( F_23 ( V_5 , V_676 ) )
return 0 ;
if ( F_170 ( V_5 , 0 , & V_1978 ) != 0 )
return - V_210 ;
if ( V_1978 == V_1979 )
V_629 = V_2082 ;
else if ( ( V_1978 & V_2083 ) == V_2084 ) {
if ( ( V_1978 & V_2085 ) ==
V_2086 ) {
switch ( V_1978 & V_2087 ) {
case V_2088 :
V_629 = V_2089 ;
break;
case V_2090 :
V_629 = V_2091 ;
break;
case V_2092 :
V_629 = V_2093 ;
break;
case V_2094 :
V_629 = V_2095 ;
break;
case V_2096 :
V_629 = V_2097 ;
break;
case V_2098 :
V_629 = V_2099 ;
break;
default:
return - V_210 ;
}
} else
return 0 ;
} else if ( ( V_1978 & V_2100 ) == V_2101 )
V_629 = V_2102 ;
else
return - V_210 ;
V_621 = F_176 ( V_629 , V_627 ) ;
if ( V_621 == NULL )
return - V_267 ;
V_75 = - V_210 ;
for ( V_42 = 0 , V_622 = 0 ; V_42 < V_629 ; V_42 += 4 , V_622 ++ ) {
V_75 = F_171 ( V_5 , V_42 , & V_621 [ V_622 ] ) ;
if ( V_75 )
break;
}
if ( V_42 < V_629 )
goto V_497;
V_1978 = F_174 ( V_621 [ 0 ] ) ;
if ( ( V_1978 & V_2083 ) ==
V_2084 ) {
T_4 * V_2103 = ( T_4 * ) V_621 , V_2104 = 0 ;
if ( ( V_1978 & V_2087 ) ==
V_2090 ) {
for ( V_42 = 0 ; V_42 < V_2105 ; V_42 ++ )
V_2104 += V_2103 [ V_42 ] ;
for ( V_42 = V_2105 + 4 ; V_42 < V_629 ; V_42 ++ )
V_2104 += V_2103 [ V_42 ] ;
} else {
for ( V_42 = 0 ; V_42 < V_629 ; V_42 ++ )
V_2104 += V_2103 [ V_42 ] ;
}
if ( V_2104 == 0 ) {
V_75 = 0 ;
goto V_497;
}
V_75 = - V_210 ;
goto V_497;
}
if ( ( V_1978 & V_2100 ) ==
V_2101 ) {
T_4 V_72 [ V_2106 ] ;
T_4 V_2107 [ V_2106 ] ;
T_4 * V_2103 = ( T_4 * ) V_621 ;
for ( V_42 = 0 , V_622 = 0 , V_1510 = 0 ; V_42 < V_2102 ; V_42 ++ ) {
if ( ( V_42 == 0 ) || ( V_42 == 8 ) ) {
int V_2108 ;
T_4 V_2109 ;
for ( V_2108 = 0 , V_2109 = 0x80 ; V_2108 < 7 ; V_2108 ++ , V_2109 >>= 1 )
V_2107 [ V_1510 ++ ] = V_2103 [ V_42 ] & V_2109 ;
V_42 ++ ;
} else if ( V_42 == 16 ) {
int V_2108 ;
T_4 V_2109 ;
for ( V_2108 = 0 , V_2109 = 0x20 ; V_2108 < 6 ; V_2108 ++ , V_2109 >>= 1 )
V_2107 [ V_1510 ++ ] = V_2103 [ V_42 ] & V_2109 ;
V_42 ++ ;
for ( V_2108 = 0 , V_2109 = 0x80 ; V_2108 < 8 ; V_2108 ++ , V_2109 >>= 1 )
V_2107 [ V_1510 ++ ] = V_2103 [ V_42 ] & V_2109 ;
V_42 ++ ;
}
V_72 [ V_622 ++ ] = V_2103 [ V_42 ] ;
}
V_75 = - V_210 ;
for ( V_42 = 0 ; V_42 < V_2106 ; V_42 ++ ) {
T_4 V_2110 = F_568 ( V_72 [ V_42 ] ) ;
if ( ( V_2110 & 0x1 ) && V_2107 [ V_42 ] )
goto V_497;
else if ( ! ( V_2110 & 0x1 ) && ! V_2107 [ V_42 ] )
goto V_497;
}
V_75 = 0 ;
goto V_497;
}
V_75 = - V_210 ;
V_2081 = F_452 ( ( unsigned char * ) V_621 , 0x10 ) ;
if ( V_2081 != F_569 ( V_621 [ 0x10 / 4 ] ) )
goto V_497;
V_2081 = F_452 ( ( unsigned char * ) & V_621 [ 0x74 / 4 ] , 0x88 ) ;
if ( V_2081 != F_569 ( V_621 [ 0xfc / 4 ] ) )
goto V_497;
F_177 ( V_621 ) ;
V_621 = F_565 ( V_5 , & V_74 ) ;
if ( ! V_621 )
return - V_267 ;
V_42 = F_570 ( ( T_4 * ) V_621 , 0 , V_74 , V_2111 ) ;
if ( V_42 > 0 ) {
V_622 = F_571 ( & ( ( T_4 * ) V_621 ) [ V_42 ] ) ;
if ( V_622 < 0 )
goto V_497;
if ( V_42 + V_2112 + V_622 > V_74 )
goto V_497;
V_42 += V_2112 ;
V_622 = F_572 ( ( T_4 * ) V_621 , V_42 , V_622 ,
V_2113 ) ;
if ( V_622 > 0 ) {
T_4 V_2104 = 0 ;
V_622 += V_2114 ;
for ( V_42 = 0 ; V_42 <= V_622 ; V_42 ++ )
V_2104 += ( ( T_4 * ) V_621 ) [ V_42 ] ;
if ( V_2104 )
goto V_497;
}
}
V_75 = 0 ;
V_497:
F_177 ( V_621 ) ;
return V_75 ;
}
static int F_573 ( struct V_4 * V_5 )
{
int V_42 , F_505 ;
if ( ! F_146 ( V_5 -> V_111 ) )
return - V_82 ;
if ( V_5 -> V_178 & V_354 )
F_505 = V_2115 ;
else
F_505 = V_2116 ;
for ( V_42 = 0 ; V_42 < F_505 ; V_42 ++ ) {
if ( V_5 -> V_335 )
return 0 ;
if ( F_574 ( 1000 ) )
break;
}
return - V_210 ;
}
static int F_575 ( struct V_4 * V_5 )
{
int V_42 , V_2117 , V_2118 ;
T_1 V_590 , V_2119 , V_2120 , V_7 , V_2121 , V_2122 ;
static struct {
T_3 V_590 ;
T_3 V_10 ;
#define F_576 0x1
#define F_577 0x2
#define F_578 0x4
#define F_579 0x8
T_1 V_2119 ;
T_1 V_2120 ;
} V_2123 [] = {
{ V_377 , F_577 ,
0x00000000 , 0x00ef6f8c } ,
{ V_377 , F_576 ,
0x00000000 , 0x01ef6b8c } ,
{ V_787 , F_577 ,
0x03800107 , 0x00000000 } ,
{ V_787 , F_576 ,
0x03800100 , 0x00000000 } ,
{ V_684 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_685 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1624 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_358 , 0x0000 ,
0x00000000 , 0x00000070 } ,
{ V_381 , 0x0000 ,
0x00000000 , 0x00003fff } ,
{ V_356 , F_577 ,
0x00000000 , 0x000007fc } ,
{ V_356 , F_576 ,
0x00000000 , 0x000007dc } ,
{ V_1512 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1513 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1514 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1515 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1049 + 0 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1049 + 4 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1049 + 8 , F_577 ,
0x00000000 , 0x00000003 } ,
{ V_1049 + 0xc , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1618 + 0 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1618 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1618 + 8 , 0x0000 ,
0x00000000 , 0xffff0002 } ,
{ V_1618 + 0xc , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1505 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1505 , F_576 ,
0x00000000 , 0x000003ff } ,
{ V_1508 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_138 , F_577 ,
0x00000000 , 0x00000004 } ,
{ V_138 , F_576 ,
0x00000000 , 0x000000f6 } ,
{ V_1470 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1470 , F_576 ,
0x00000000 , 0x000003ff } ,
{ V_1461 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1461 , F_576 ,
0x00000000 , 0x000003ff } ,
{ V_1472 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1472 , F_576 | F_578 ,
0x00000000 , 0x000000ff } ,
{ V_1463 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1463 , F_576 | F_578 ,
0x00000000 , 0x000000ff } ,
{ V_1478 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1480 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1474 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1474 , F_576 | F_578 ,
0x00000000 , 0x000000ff } ,
{ V_1465 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1465 , F_576 | F_578 ,
0x00000000 , 0x000000ff } ,
{ V_966 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1673 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1673 + 4 , F_577 ,
0x00000000 , 0xffffffff } ,
{ V_1495 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1495 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1674 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1675 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1586 , F_579 ,
0x00000000 , 0x007fff80 } ,
{ V_1588 , F_579 ,
0x00000000 , 0x007fffff } ,
{ V_1597 , 0x0000 ,
0x00000000 , 0x0000003f } ,
{ V_1600 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1602 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1591 , F_577 ,
0xffffffff , 0x00000000 } ,
{ V_1593 , F_577 ,
0xffffffff , 0x00000000 } ,
{ V_2124 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_2125 + 4 , F_577 ,
0x00000000 , 0x000001ff } ,
{ V_2126 + 4 , 0x0000 ,
0x00000000 , 0x000007ff } ,
{ V_2127 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ 0xffff , 0x0000 , 0x00000000 , 0x00000000 } ,
} ;
V_2117 = V_2118 = 0 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_2117 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2118 = 1 ;
}
for ( V_42 = 0 ; V_2123 [ V_42 ] . V_590 != 0xffff ; V_42 ++ ) {
if ( V_2117 && ( V_2123 [ V_42 ] . V_10 & F_577 ) )
continue;
if ( ! V_2117 && ( V_2123 [ V_42 ] . V_10 & F_576 ) )
continue;
if ( F_23 ( V_5 , V_1643 ) &&
( V_2123 [ V_42 ] . V_10 & F_578 ) )
continue;
if ( V_2118 && ( V_2123 [ V_42 ] . V_10 & F_579 ) )
continue;
V_590 = ( T_1 ) V_2123 [ V_42 ] . V_590 ;
V_2119 = V_2123 [ V_42 ] . V_2119 ;
V_2120 = V_2123 [ V_42 ] . V_2120 ;
V_2121 = F_33 ( V_590 ) ;
V_2122 = V_2121 & V_2119 ;
F_46 ( V_590 , 0 ) ;
V_7 = F_33 ( V_590 ) ;
if ( ( ( V_7 & V_2119 ) != V_2122 ) || ( V_7 & V_2120 ) )
goto V_497;
F_46 ( V_590 , V_2119 | V_2120 ) ;
V_7 = F_33 ( V_590 ) ;
if ( ( V_7 & V_2119 ) != V_2122 )
goto V_497;
if ( ( V_7 & V_2120 ) != V_2120 )
goto V_497;
F_46 ( V_590 , V_2121 ) ;
}
return 0 ;
V_497:
if ( F_580 ( V_5 ) )
F_187 ( V_5 -> V_111 ,
L_77 , V_590 ) ;
F_46 ( V_590 , V_2121 ) ;
return - V_210 ;
}
static int F_581 ( struct V_4 * V_5 , T_1 V_590 , T_1 V_74 )
{
static const T_1 V_2128 [] = { 0x00000000 , 0xffffffff , 0xaa55a55a } ;
int V_42 ;
T_1 V_622 ;
for ( V_42 = 0 ; V_42 < F_582 ( V_2128 ) ; V_42 ++ ) {
for ( V_622 = 0 ; V_622 < V_74 ; V_622 += 4 ) {
T_1 V_7 ;
F_29 ( V_5 , V_590 + V_622 , V_2128 [ V_42 ] ) ;
F_32 ( V_5 , V_590 + V_622 , & V_7 ) ;
if ( V_7 != V_2128 [ V_42 ] )
return - V_210 ;
}
}
return 0 ;
}
static int F_583 ( struct V_4 * V_5 )
{
static struct V_2129 {
T_1 V_590 ;
T_1 V_74 ;
} V_2130 [] = {
{ 0x00000000 , 0x00b50 } ,
{ 0x00002000 , 0x1c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2131 [] = {
{ 0x00000100 , 0x0000c } ,
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x01000 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0e000 } ,
{ 0xffffffff , 0x00000 }
} , V_2132 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x00800 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2133 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00400 } ,
{ 0x00006000 , 0x00400 } ,
{ 0x00008000 , 0x01000 } ,
{ 0x00010000 , 0x01000 } ,
{ 0xffffffff , 0x00000 }
} , V_2134 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0x00020000 , 0x13c00 } ,
{ 0xffffffff , 0x00000 }
} , V_2135 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x09800 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0xffffffff , 0x00000 }
} ;
struct V_2129 * V_2136 ;
int V_75 = 0 ;
int V_42 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_2136 = V_2134 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_762 )
V_2136 = V_2135 ;
else if ( F_23 ( V_5 , 5755_PLUS ) )
V_2136 = V_2132 ;
else if ( F_30 ( V_5 ) == V_36 )
V_2136 = V_2133 ;
else if ( F_23 ( V_5 , 5705_PLUS ) )
V_2136 = V_2131 ;
else
V_2136 = V_2130 ;
for ( V_42 = 0 ; V_2136 [ V_42 ] . V_590 != 0xffffffff ; V_42 ++ ) {
V_75 = F_581 ( V_5 , V_2136 [ V_42 ] . V_590 , V_2136 [ V_42 ] . V_74 ) ;
if ( V_75 )
break;
}
return V_75 ;
}
static int F_584 ( struct V_4 * V_5 , T_1 V_2137 , bool V_2138 )
{
T_1 V_2139 , V_2140 , V_2141 , V_1124 ;
T_1 V_1261 = 0 , V_1239 = 0 , V_1160 , V_126 , V_2142 , V_7 ;
T_1 V_1152 ;
struct V_1102 * V_1103 ;
T_4 * V_2143 , * V_2144 ;
T_9 V_1129 ;
int V_2145 , V_2146 , V_2147 , V_42 , V_75 ;
struct V_1127 * V_1128 ;
struct V_130 * V_131 , * V_2148 ;
struct V_1122 * V_1123 = & V_5 -> V_123 [ 0 ] . V_1084 ;
V_131 = & V_5 -> V_123 [ 0 ] ;
V_2148 = & V_5 -> V_123 [ 0 ] ;
if ( V_5 -> V_129 > 1 ) {
if ( F_23 ( V_5 , V_1203 ) )
V_2148 = & V_5 -> V_123 [ 1 ] ;
if ( F_23 ( V_5 , V_1098 ) )
V_131 = & V_5 -> V_123 [ 1 ] ;
}
V_126 = V_131 -> V_126 | V_2148 -> V_126 ;
V_75 = - V_210 ;
V_2146 = V_2137 ;
V_1103 = F_305 ( V_5 -> V_111 , V_2146 ) ;
if ( ! V_1103 )
return - V_267 ;
V_2143 = F_308 ( V_1103 , V_2146 ) ;
memcpy ( V_2143 , V_5 -> V_111 -> V_689 , V_1526 ) ;
memset ( V_2143 + V_1526 , 0x0 , 8 ) ;
F_46 ( V_1624 , V_2146 + V_1176 ) ;
if ( V_2138 ) {
struct V_1277 * V_1278 = (struct V_1277 * ) & V_2143 [ V_1194 ] ;
T_1 V_1286 = V_2149 + V_2150 +
V_2151 ;
memcpy ( V_2143 + V_1526 * 2 , V_2152 ,
sizeof( V_2152 ) ) ;
V_1239 = V_2153 ;
V_7 = V_2146 - V_1526 * 2 - sizeof( V_2152 ) ;
V_2145 = F_585 ( V_7 , V_2153 ) ;
V_1278 -> V_1290 = F_312 ( ( T_3 ) ( V_1239 + V_1286 ) ) ;
V_1261 = ( V_1291 |
V_1292 ) ;
if ( F_23 ( V_5 , V_1293 ) ||
F_23 ( V_5 , V_1294 ) ||
F_23 ( V_5 , V_1295 ) ) {
struct V_1279 * V_2154 ;
V_7 = V_1194 + V_2149 ;
V_2154 = (struct V_1279 * ) & V_2143 [ V_7 ] ;
V_2154 -> V_1289 = 0 ;
} else
V_1261 |= V_1296 ;
if ( F_23 ( V_5 , V_1295 ) ) {
V_1239 |= ( V_1286 & 0xc ) << 12 ;
if ( V_1286 & 0x10 )
V_1261 |= 0x00000010 ;
V_1261 |= ( V_1286 & 0x3e0 ) << 5 ;
} else if ( F_23 ( V_5 , V_1294 ) )
V_1239 |= V_1286 << 9 ;
else if ( F_23 ( V_5 , V_1293 ) ||
F_30 ( V_5 ) == V_496 ) {
V_1239 |= ( V_2151 << 9 ) ;
} else {
V_1261 |= ( V_2151 << 10 ) ;
}
V_2142 = V_1526 * 2 + sizeof( V_2152 ) ;
} else {
V_2145 = 1 ;
V_2142 = V_1194 ;
if ( F_23 ( V_5 , V_1303 ) &&
V_2146 > V_1304 )
V_1261 |= V_1305 ;
}
for ( V_42 = V_2142 ; V_42 < V_2146 ; V_42 ++ )
V_2143 [ V_42 ] = ( T_4 ) ( V_42 & 0xff ) ;
V_1129 = F_294 ( V_5 -> V_12 , V_1103 -> V_72 , V_2146 , V_1111 ) ;
if ( F_295 ( V_5 -> V_12 , V_1129 ) ) {
F_586 ( V_1103 ) ;
return - V_210 ;
}
V_7 = V_131 -> V_1082 ;
V_131 -> V_1101 [ V_7 ] . V_1103 = V_1103 ;
F_296 ( & V_131 -> V_1101 [ V_7 ] , V_1110 , V_1129 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_2148 -> V_126 ) ;
F_24 ( 10 ) ;
V_2139 = V_2148 -> V_134 -> V_145 [ 0 ] . V_1080 ;
V_1152 = F_265 ( V_131 ) ;
if ( F_365 ( V_131 , & V_7 , & V_1152 , V_1129 , V_2146 ,
V_1261 | V_1255 , V_1239 , 0 ) ) {
V_131 -> V_1101 [ V_7 ] . V_1103 = NULL ;
F_586 ( V_1103 ) ;
return - V_210 ;
}
V_131 -> V_1082 ++ ;
F_49 () ;
F_394 ( V_131 -> V_1317 , V_131 -> V_1082 ) ;
F_498 ( V_131 -> V_1317 ) ;
F_24 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 35 ; V_42 ++ ) {
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_126 ) ;
F_24 ( 10 ) ;
V_2141 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
V_2140 = V_2148 -> V_134 -> V_145 [ 0 ] . V_1080 ;
if ( ( V_2141 == V_131 -> V_1082 ) &&
( V_2140 == ( V_2139 + V_2145 ) ) )
break;
}
F_366 ( V_131 , V_131 -> V_1082 - 1 , - 1 ) ;
F_586 ( V_1103 ) ;
if ( V_2141 != V_131 -> V_1082 )
goto V_497;
if ( V_2140 != V_2139 + V_2145 )
goto V_497;
V_7 = V_2142 ;
while ( V_2140 != V_2139 ) {
V_1128 = & V_2148 -> V_1158 [ V_2139 ++ ] ;
V_1160 = V_1128 -> V_1163 & V_1164 ;
V_1124 = V_1128 -> V_1163 & V_1165 ;
if ( ( V_1128 -> V_1167 & V_1168 ) != 0 &&
( V_1128 -> V_1167 != V_2155 ) )
goto V_497;
V_2147 = ( ( V_1128 -> V_1173 & V_1174 ) >> V_1175 )
- V_1176 ;
if ( ! V_2138 ) {
if ( V_2147 != V_2146 )
goto V_497;
if ( V_2137 <= V_1332 - V_1176 ) {
if ( V_1124 != V_1132 )
goto V_497;
} else {
if ( V_1124 != V_1137 )
goto V_497;
}
} else if ( ( V_1128 -> V_1177 & V_1186 ) &&
( V_1128 -> V_1187 & V_1188 )
>> V_1189 != 0xffff ) {
goto V_497;
}
if ( V_1124 == V_1132 ) {
V_2144 = V_1123 -> V_1135 [ V_1160 ] . V_72 ;
V_1129 = F_272 ( & V_1123 -> V_1135 [ V_1160 ] ,
V_1110 ) ;
} else if ( V_1124 == V_1137 ) {
V_2144 = V_1123 -> V_1141 [ V_1160 ] . V_72 ;
V_1129 = F_272 ( & V_1123 -> V_1141 [ V_1160 ] ,
V_1110 ) ;
} else
goto V_497;
F_306 ( V_5 -> V_12 , V_1129 , V_2147 ,
V_1120 ) ;
V_2144 += F_291 ( V_5 ) ;
for ( V_42 = V_2142 ; V_42 < V_2147 ; V_42 ++ , V_7 ++ ) {
if ( * ( V_2144 + V_42 ) != ( T_4 ) ( V_7 & 0xff ) )
goto V_497;
}
}
V_75 = 0 ;
V_497:
return V_75 ;
}
static int F_587 ( struct V_4 * V_5 , T_6 * V_72 , bool V_2156 )
{
int V_75 = - V_210 ;
T_1 V_2157 ;
T_1 V_2158 = 9000 ;
if ( V_5 -> V_1252 )
V_2158 = V_5 -> V_1252 - V_1194 ;
V_2157 = V_5 -> V_178 & V_333 ;
V_5 -> V_178 &= ~ V_333 ;
if ( ! F_146 ( V_5 -> V_111 ) ) {
V_72 [ V_2159 ] = V_2160 ;
V_72 [ V_2161 ] = V_2160 ;
if ( V_2156 )
V_72 [ V_2162 ] = V_2160 ;
goto V_186;
}
V_75 = F_465 ( V_5 , true ) ;
if ( V_75 ) {
V_72 [ V_2159 ] = V_2160 ;
V_72 [ V_2161 ] = V_2160 ;
if ( V_2156 )
V_72 [ V_2162 ] = V_2160 ;
goto V_186;
}
if ( F_23 ( V_5 , V_1203 ) ) {
int V_42 ;
for ( V_42 = V_1530 ;
V_42 < V_1530 + V_1528 ; V_42 += 4 )
F_46 ( V_42 , 0x0 ) ;
}
if ( F_30 ( V_5 ) != V_561 &&
! F_23 ( V_5 , V_152 ) ) {
F_395 ( V_5 , true ) ;
if ( F_584 ( V_5 , V_2163 , false ) )
V_72 [ V_2159 ] |= V_2164 ;
if ( F_23 ( V_5 , V_1340 ) &&
F_584 ( V_5 , V_2158 + V_1194 , false ) )
V_72 [ V_2159 ] |= V_2165 ;
F_395 ( V_5 , false ) ;
}
if ( ! ( V_5 -> V_178 & V_562 ) &&
! F_23 ( V_5 , V_266 ) ) {
int V_42 ;
F_396 ( V_5 , 0 , false ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
if ( F_33 ( V_947 ) & V_948 )
break;
F_99 ( 1 ) ;
}
if ( F_584 ( V_5 , V_2163 , false ) )
V_72 [ V_2161 ] |= V_2164 ;
if ( F_23 ( V_5 , V_1595 ) &&
F_584 ( V_5 , V_2163 , true ) )
V_72 [ V_2161 ] |= V_2166 ;
if ( F_23 ( V_5 , V_1340 ) &&
F_584 ( V_5 , V_2158 + V_1194 , false ) )
V_72 [ V_2161 ] |= V_2165 ;
if ( V_2156 ) {
F_396 ( V_5 , 0 , true ) ;
F_99 ( 40 ) ;
if ( F_584 ( V_5 , V_2163 , false ) )
V_72 [ V_2162 ] |=
V_2164 ;
if ( F_23 ( V_5 , V_1595 ) &&
F_584 ( V_5 , V_2163 , true ) )
V_72 [ V_2162 ] |=
V_2166 ;
if ( F_23 ( V_5 , V_1340 ) &&
F_584 ( V_5 , V_2158 + V_1194 , false ) )
V_72 [ V_2162 ] |=
V_2165 ;
}
if ( V_5 -> V_178 & V_508 )
F_129 ( V_5 , true ) ;
}
V_75 = ( V_72 [ V_2159 ] | V_72 [ V_2161 ] |
V_72 [ V_2162 ] ) ? - V_210 : 0 ;
V_186:
V_5 -> V_178 |= V_2157 ;
return V_75 ;
}
static void F_588 ( struct V_359 * V_111 , struct V_2167 * V_2168 ,
T_6 * V_72 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
bool V_2169 = V_2168 -> V_10 & V_2170 ;
if ( V_5 -> V_178 & V_394 ) {
if ( F_199 ( V_5 ) ) {
V_2168 -> V_10 |= V_2171 ;
memset ( V_72 , 1 , sizeof( T_6 ) * V_2036 ) ;
return;
}
F_42 ( V_5 , V_96 ) ;
}
memset ( V_72 , 0 , sizeof( T_6 ) * V_2036 ) ;
if ( F_567 ( V_5 ) != 0 ) {
V_2168 -> V_10 |= V_2171 ;
V_72 [ V_2172 ] = 1 ;
}
if ( ! V_2169 && F_573 ( V_5 ) ) {
V_2168 -> V_10 |= V_2171 ;
V_72 [ V_2173 ] = 1 ;
}
if ( V_2168 -> V_10 & V_2174 ) {
int V_75 , V_756 = 0 , V_125 = 0 ;
if ( F_146 ( V_111 ) ) {
F_124 ( V_5 ) ;
F_343 ( V_5 ) ;
V_125 = 1 ;
}
F_243 ( V_5 , V_125 ) ;
F_435 ( V_5 , V_315 , 1 ) ;
V_75 = F_159 ( V_5 ) ;
F_185 ( V_5 , V_648 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_185 ( V_5 , V_649 ) ;
if ( ! V_75 )
F_160 ( V_5 ) ;
if ( V_5 -> V_178 & V_300 )
F_145 ( V_5 ) ;
if ( F_575 ( V_5 ) != 0 ) {
V_2168 -> V_10 |= V_2171 ;
V_72 [ V_2175 ] = 1 ;
}
if ( F_583 ( V_5 ) != 0 ) {
V_2168 -> V_10 |= V_2171 ;
V_72 [ V_2176 ] = 1 ;
}
if ( V_2169 )
V_2168 -> V_10 |= V_2177 ;
if ( F_587 ( V_5 , V_72 , V_2169 ) )
V_2168 -> V_10 |= V_2171 ;
F_244 ( V_5 ) ;
if ( F_496 ( V_5 ) != 0 ) {
V_2168 -> V_10 |= V_2171 ;
V_72 [ V_2178 ] = 1 ;
}
F_243 ( V_5 , 0 ) ;
F_435 ( V_5 , V_110 , 1 ) ;
if ( F_146 ( V_111 ) ) {
F_84 ( V_5 , V_557 ) ;
V_756 = F_489 ( V_5 , true ) ;
if ( ! V_756 )
F_346 ( V_5 ) ;
}
F_244 ( V_5 ) ;
if ( V_125 && ! V_756 )
F_121 ( V_5 ) ;
}
if ( V_5 -> V_178 & V_394 )
F_201 ( V_5 ) ;
}
static int F_589 ( struct V_359 * V_111 , struct V_2179 * V_2180 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_2181 V_2182 ;
if ( ! F_23 ( V_5 , V_987 ) )
return - V_1032 ;
if ( F_590 ( & V_2182 , V_2180 -> V_2183 , sizeof( V_2182 ) ) )
return - V_2184 ;
if ( V_2182 . V_10 )
return - V_64 ;
if ( V_2182 . V_2185 != V_995 &&
V_2182 . V_2185 != V_994 )
return - V_2186 ;
switch ( V_2182 . V_2187 ) {
case V_997 :
V_5 -> V_1582 = 0 ;
break;
case V_998 :
V_5 -> V_1582 = V_2188 |
V_2189 ;
break;
case V_2190 :
V_5 -> V_1582 = V_2188 |
V_2191 ;
break;
case V_2192 :
V_5 -> V_1582 = V_2188 |
V_2193 ;
break;
case V_2194 :
V_5 -> V_1582 = V_2195 |
V_2196 ;
break;
case V_999 :
V_5 -> V_1582 = V_2197 |
V_2196 ;
break;
case V_1000 :
V_5 -> V_1582 = V_2198 |
V_2196 ;
break;
case V_2199 :
V_5 -> V_1582 = V_2195 |
V_2191 ;
break;
case V_2200 :
V_5 -> V_1582 = V_2197 |
V_2191 ;
break;
case V_2201 :
V_5 -> V_1582 = V_2198 |
V_2191 ;
break;
case V_2202 :
V_5 -> V_1582 = V_2195 |
V_2193 ;
break;
case V_2203 :
V_5 -> V_1582 = V_2197 |
V_2193 ;
break;
case V_2204 :
V_5 -> V_1582 = V_2198 |
V_2193 ;
break;
default:
return - V_2186 ;
}
if ( F_146 ( V_111 ) && V_5 -> V_1582 )
F_46 ( V_1583 ,
V_5 -> V_1582 | V_1584 ) ;
if ( V_2182 . V_2185 == V_995 )
F_84 ( V_5 , V_1309 ) ;
else
F_86 ( V_5 , V_1309 ) ;
return F_591 ( V_2180 -> V_2183 , & V_2182 , sizeof( V_2182 ) ) ?
- V_2184 : 0 ;
}
static int F_592 ( struct V_359 * V_111 , struct V_2179 * V_2180 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
struct V_2181 V_2182 ;
if ( ! F_23 ( V_5 , V_987 ) )
return - V_1032 ;
V_2182 . V_10 = 0 ;
V_2182 . V_2185 = ( F_23 ( V_5 , V_1309 ) ?
V_995 : V_994 ) ;
switch ( V_5 -> V_1582 ) {
case 0 :
V_2182 . V_2187 = V_997 ;
break;
case V_2188 | V_2189 :
V_2182 . V_2187 = V_998 ;
break;
case V_2188 | V_2191 :
V_2182 . V_2187 = V_2190 ;
break;
case V_2188 | V_2193 :
V_2182 . V_2187 = V_2192 ;
break;
case V_2195 | V_2196 :
V_2182 . V_2187 = V_2194 ;
break;
case V_2197 | V_2196 :
V_2182 . V_2187 = V_999 ;
break;
case V_2198 | V_2196 :
V_2182 . V_2187 = V_1000 ;
break;
case V_2195 | V_2191 :
V_2182 . V_2187 = V_2199 ;
break;
case V_2197 | V_2191 :
V_2182 . V_2187 = V_2200 ;
break;
case V_2198 | V_2191 :
V_2182 . V_2187 = V_2201 ;
break;
case V_2195 | V_2193 :
V_2182 . V_2187 = V_2202 ;
break;
case V_2197 | V_2193 :
V_2182 . V_2187 = V_2203 ;
break;
case V_2198 | V_2193 :
V_2182 . V_2187 = V_2204 ;
break;
default:
F_593 ( 1 ) ;
return - V_2186 ;
}
return F_591 ( V_2180 -> V_2183 , & V_2182 , sizeof( V_2182 ) ) ?
- V_2184 : 0 ;
}
static int F_594 ( struct V_359 * V_111 , struct V_2179 * V_2180 , int V_637 )
{
struct V_2205 * V_72 = F_595 ( V_2180 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 ;
if ( F_23 ( V_5 , V_266 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_386 ) )
return - V_85 ;
V_212 = F_74 ( V_5 -> V_213 , V_5 -> V_160 ) ;
return F_596 ( V_212 , V_2180 , V_637 ) ;
}
switch ( V_637 ) {
case V_2206 :
V_72 -> V_215 = V_5 -> V_160 ;
case V_2207 : {
T_1 V_2208 ;
if ( V_5 -> V_178 & V_562 )
break;
if ( ! F_146 ( V_111 ) )
return - V_85 ;
F_70 ( & V_5 -> V_209 ) ;
V_75 = F_56 ( V_5 , V_72 -> V_215 & 0x1f ,
V_72 -> V_2209 & 0x1f , & V_2208 ) ;
F_71 ( & V_5 -> V_209 ) ;
V_72 -> V_2210 = V_2208 ;
return V_75 ;
}
case V_2211 :
if ( V_5 -> V_178 & V_562 )
break;
if ( ! F_146 ( V_111 ) )
return - V_85 ;
F_70 ( & V_5 -> V_209 ) ;
V_75 = F_58 ( V_5 , V_72 -> V_215 & 0x1f ,
V_72 -> V_2209 & 0x1f , V_72 -> V_2212 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_75 ;
case V_2213 :
return F_589 ( V_111 , V_2180 ) ;
case V_2214 :
return F_592 ( V_111 , V_2180 ) ;
default:
break;
}
return - V_1032 ;
}
static int F_597 ( struct V_359 * V_111 , struct V_1459 * V_1460 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
memcpy ( V_1460 , & V_5 -> V_967 , sizeof( * V_1460 ) ) ;
return 0 ;
}
static int F_598 ( struct V_359 * V_111 , struct V_1459 * V_1460 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
T_1 V_2215 = 0 , V_2216 = 0 ;
T_1 V_2217 = 0 , V_2218 = 0 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
V_2215 = V_2219 ;
V_2216 = V_2220 ;
V_2217 = V_2221 ;
V_2218 = V_2222 ;
}
if ( ( V_1460 -> V_1471 > V_2223 ) ||
( ! V_1460 -> V_1471 ) ||
( V_1460 -> V_1462 > V_2224 ) ||
( ! V_1460 -> V_1462 ) ||
( V_1460 -> V_1473 > V_2225 ) ||
( V_1460 -> V_1464 > V_2226 ) ||
( V_1460 -> V_1479 > V_2215 ) ||
( V_1460 -> V_1481 > V_2216 ) ||
( V_1460 -> V_1475 > V_2227 ) ||
( V_1460 -> V_1466 > V_2228 ) ||
( V_1460 -> V_968 > V_2217 ) ||
( V_1460 -> V_968 < V_2218 ) )
return - V_64 ;
V_5 -> V_967 . V_1471 = V_1460 -> V_1471 ;
V_5 -> V_967 . V_1462 = V_1460 -> V_1462 ;
V_5 -> V_967 . V_1473 = V_1460 -> V_1473 ;
V_5 -> V_967 . V_1464 = V_1460 -> V_1464 ;
V_5 -> V_967 . V_1479 = V_1460 -> V_1479 ;
V_5 -> V_967 . V_1481 = V_1460 -> V_1481 ;
V_5 -> V_967 . V_1475 = V_1460 -> V_1475 ;
V_5 -> V_967 . V_1466 = V_1460 -> V_1466 ;
V_5 -> V_967 . V_968 = V_1460 -> V_968 ;
if ( F_146 ( V_111 ) ) {
F_243 ( V_5 , 0 ) ;
F_444 ( V_5 , & V_5 -> V_967 ) ;
F_244 ( V_5 ) ;
}
return 0 ;
}
static int F_599 ( struct V_359 * V_111 , struct V_446 * V_2229 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_333 ) ) {
F_144 ( V_5 -> V_111 , L_78 ) ;
return - V_1032 ;
}
if ( V_2229 -> V_458 != V_5 -> V_447 . V_458 ) {
F_144 ( V_5 -> V_111 ,
L_79 ) ;
return - V_64 ;
}
if ( V_2229 -> V_462 > V_2230 ) {
F_144 ( V_5 -> V_111 ,
L_80 ,
V_2230 ) ;
return - V_64 ;
}
V_5 -> V_447 = * V_2229 ;
V_5 -> V_178 |= V_1535 ;
F_143 ( V_5 ) ;
if ( F_146 ( V_5 -> V_111 ) ) {
F_243 ( V_5 , 0 ) ;
F_224 ( V_5 ) ;
F_145 ( V_5 ) ;
F_244 ( V_5 ) ;
}
return 0 ;
}
static int F_600 ( struct V_359 * V_111 , struct V_446 * V_2229 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_333 ) ) {
F_144 ( V_5 -> V_111 ,
L_78 ) ;
return - V_1032 ;
}
* V_2229 = V_5 -> V_447 ;
return 0 ;
}
static void F_601 ( struct V_359 * V_111 ,
struct V_1952 * V_1953 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_70 ( & V_5 -> V_209 ) ;
if ( ! V_5 -> V_1351 ) {
* V_1953 = V_5 -> V_1439 ;
F_71 ( & V_5 -> V_209 ) ;
return;
}
F_436 ( V_5 , V_1953 ) ;
F_71 ( & V_5 -> V_209 ) ;
}
static void F_602 ( struct V_359 * V_111 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
if ( ! F_146 ( V_111 ) )
return;
F_243 ( V_5 , 0 ) ;
F_440 ( V_111 ) ;
F_244 ( V_5 ) ;
}
static inline void F_603 ( struct V_359 * V_111 , struct V_4 * V_5 ,
int V_2231 )
{
V_111 -> V_1193 = V_2231 ;
if ( V_2231 > V_1328 ) {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_604 ( V_111 ) ;
F_86 ( V_5 , V_1595 ) ;
} else {
F_84 ( V_5 , V_1340 ) ;
}
} else {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_84 ( V_5 , V_1595 ) ;
F_604 ( V_111 ) ;
}
F_86 ( V_5 , V_1340 ) ;
}
}
static int F_605 ( struct V_359 * V_111 , int V_2231 )
{
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 ;
bool V_1533 = false ;
if ( ! F_146 ( V_111 ) ) {
F_603 ( V_111 , V_5 , V_2231 ) ;
return 0 ;
}
F_124 ( V_5 ) ;
F_343 ( V_5 ) ;
F_603 ( V_111 , V_5 , V_2231 ) ;
F_243 ( V_5 , 1 ) ;
F_435 ( V_5 , V_110 , 1 ) ;
if ( F_30 ( V_5 ) == V_662 )
V_1533 = true ;
V_75 = F_489 ( V_5 , V_1533 ) ;
if ( ! V_75 )
F_346 ( V_5 ) ;
F_244 ( V_5 ) ;
if ( ! V_75 )
F_121 ( V_5 ) ;
return V_75 ;
}
static void F_606 ( struct V_4 * V_5 )
{
T_1 V_2232 , V_7 , V_1978 ;
V_5 -> V_1970 = V_2233 ;
if ( F_170 ( V_5 , 0 , & V_1978 ) != 0 )
return;
if ( ( V_1978 != V_1979 ) &&
( ( V_1978 & V_2083 ) != V_2084 ) &&
( ( V_1978 & V_2100 ) != V_2101 ) )
return;
V_2232 = 0x10 ;
while ( V_2232 < V_5 -> V_1970 ) {
if ( F_170 ( V_5 , V_2232 , & V_7 ) != 0 )
return;
if ( V_7 == V_1978 )
break;
V_2232 <<= 1 ;
}
V_5 -> V_1970 = V_2232 ;
}
static void F_607 ( struct V_4 * V_5 )
{
T_1 V_7 ;
if ( F_23 ( V_5 , V_676 ) || F_170 ( V_5 , 0 , & V_7 ) != 0 )
return;
if ( V_7 != V_1979 ) {
F_606 ( V_5 ) ;
return;
}
if ( F_170 ( V_5 , 0xf0 , & V_7 ) == 0 ) {
if ( V_7 != 0 ) {
V_5 -> V_1970 = F_608 ( ( T_3 ) ( V_7 & 0x0000ffff ) ) * 1024 ;
return;
}
}
V_5 -> V_1970 = V_2234 ;
}
static void F_609 ( struct V_4 * V_5 )
{
T_1 V_2235 ;
V_2235 = F_33 ( V_2236 ) ;
if ( V_2235 & V_2237 ) {
F_84 ( V_5 , V_606 ) ;
} else {
V_2235 &= ~ V_2238 ;
F_46 ( V_2236 , V_2235 ) ;
}
if ( F_30 ( V_5 ) == V_1500 ||
F_23 ( V_5 , 5780_CLASS ) ) {
switch ( V_2235 & V_2239 ) {
case V_2240 :
V_5 -> V_608 = V_609 ;
V_5 -> V_610 = V_2241 ;
F_84 ( V_5 , V_605 ) ;
break;
case V_2242 :
V_5 -> V_608 = V_609 ;
V_5 -> V_610 = V_2243 ;
break;
case V_2244 :
V_5 -> V_608 = V_609 ;
V_5 -> V_610 = V_2245 ;
F_84 ( V_5 , V_605 ) ;
break;
case V_2246 :
V_5 -> V_608 = V_636 ;
V_5 -> V_610 = V_2247 ;
F_84 ( V_5 , V_605 ) ;
break;
case V_2248 :
V_5 -> V_608 = V_2249 ;
V_5 -> V_610 = V_2250 ;
break;
case V_2251 :
case V_2252 :
V_5 -> V_608 = V_2253 ;
V_5 -> V_610 = V_2254 ;
break;
}
} else {
V_5 -> V_608 = V_609 ;
V_5 -> V_610 = V_2241 ;
F_84 ( V_5 , V_605 ) ;
}
}
static void F_610 ( struct V_4 * V_5 , T_1 V_2255 )
{
switch ( V_2255 & V_2256 ) {
case V_2257 :
V_5 -> V_610 = 256 ;
break;
case V_2258 :
V_5 -> V_610 = 512 ;
break;
case V_2259 :
V_5 -> V_610 = 1024 ;
break;
case V_2260 :
V_5 -> V_610 = 2048 ;
break;
case V_2261 :
V_5 -> V_610 = 4096 ;
break;
case V_2262 :
V_5 -> V_610 = 264 ;
break;
case V_2263 :
V_5 -> V_610 = 528 ;
break;
}
}
static void F_611 ( struct V_4 * V_5 )
{
T_1 V_2235 ;
V_2235 = F_33 ( V_2236 ) ;
if ( V_2235 & ( 1 << 27 ) )
F_84 ( V_5 , V_586 ) ;
switch ( V_2235 & V_2264 ) {
case V_2265 :
case V_2266 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
break;
case V_2267 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
break;
case V_2268 :
case V_2269 :
case V_2270 :
V_5 -> V_608 = V_636 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
break;
}
if ( F_23 ( V_5 , V_606 ) ) {
F_610 ( V_5 , V_2235 ) ;
} else {
V_5 -> V_610 = V_2245 ;
V_2235 &= ~ V_2238 ;
F_46 ( V_2236 , V_2235 ) ;
}
}
static void F_612 ( struct V_4 * V_5 )
{
T_1 V_2235 , V_2271 = 0 ;
V_2235 = F_33 ( V_2236 ) ;
if ( V_2235 & ( 1 << 27 ) ) {
F_84 ( V_5 , V_586 ) ;
V_2271 = 1 ;
}
V_2235 &= V_2264 ;
switch ( V_2235 ) {
case V_2272 :
case V_2273 :
case V_2274 :
case V_2275 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
V_5 -> V_610 = 264 ;
if ( V_2235 == V_2272 ||
V_2235 == V_2275 )
V_5 -> V_1970 = ( V_2271 ? 0x3e200 :
V_2234 ) ;
else if ( V_2235 == V_2273 )
V_5 -> V_1970 = ( V_2271 ? 0x1f200 :
V_2276 ) ;
else
V_5 -> V_1970 = ( V_2271 ? 0x1f200 :
V_2277 ) ;
break;
case V_2268 :
case V_2269 :
case V_2270 :
V_5 -> V_608 = V_636 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
V_5 -> V_610 = 256 ;
if ( V_2235 == V_2268 )
V_5 -> V_1970 = ( V_2271 ?
V_2278 :
V_2277 ) ;
else if ( V_2235 == V_2269 )
V_5 -> V_1970 = ( V_2271 ?
V_2278 :
V_2276 ) ;
else
V_5 -> V_1970 = ( V_2271 ?
V_2277 :
V_2234 ) ;
break;
}
}
static void F_613 ( struct V_4 * V_5 )
{
T_1 V_2235 ;
V_2235 = F_33 ( V_2236 ) ;
switch ( V_2235 & V_2264 ) {
case V_2279 :
case V_2280 :
case V_2281 :
case V_2282 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
V_5 -> V_610 = V_2245 ;
V_2235 &= ~ V_2238 ;
F_46 ( V_2236 , V_2235 ) ;
break;
case V_2267 :
case V_2272 :
case V_2273 :
case V_2274 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
V_5 -> V_610 = 264 ;
break;
case V_2268 :
case V_2269 :
case V_2270 :
V_5 -> V_608 = V_636 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
V_5 -> V_610 = 256 ;
break;
}
}
static void F_614 ( struct V_4 * V_5 )
{
T_1 V_2235 , V_2271 = 0 ;
V_2235 = F_33 ( V_2236 ) ;
if ( V_2235 & ( 1 << 27 ) ) {
F_84 ( V_5 , V_586 ) ;
V_2271 = 1 ;
}
V_2235 &= V_2264 ;
switch ( V_2235 ) {
case V_2283 :
case V_2284 :
case V_2285 :
case V_2286 :
case V_2287 :
case V_2288 :
case V_2289 :
case V_2290 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
F_84 ( V_5 , V_607 ) ;
V_5 -> V_610 = 256 ;
break;
case V_2291 :
case V_2292 :
case V_2293 :
case V_2294 :
case V_2295 :
case V_2296 :
case V_2297 :
case V_2298 :
V_5 -> V_608 = V_636 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
V_5 -> V_610 = 256 ;
break;
}
if ( V_2271 ) {
V_5 -> V_1970 = F_33 ( V_2299 ) ;
} else {
switch ( V_2235 ) {
case V_2286 :
case V_2290 :
case V_2294 :
case V_2298 :
V_5 -> V_1970 = V_2300 ;
break;
case V_2285 :
case V_2289 :
case V_2293 :
case V_2297 :
V_5 -> V_1970 = V_2301 ;
break;
case V_2284 :
case V_2288 :
case V_2292 :
case V_2296 :
V_5 -> V_1970 = V_2234 ;
break;
case V_2283 :
case V_2287 :
case V_2291 :
case V_2295 :
V_5 -> V_1970 = V_2276 ;
break;
}
}
}
static void F_615 ( struct V_4 * V_5 )
{
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
V_5 -> V_610 = V_2245 ;
}
static void F_616 ( struct V_4 * V_5 )
{
T_1 V_2235 ;
V_2235 = F_33 ( V_2236 ) ;
switch ( V_2235 & V_2264 ) {
case V_2280 :
case V_2282 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
V_5 -> V_610 = V_2245 ;
V_2235 &= ~ V_2238 ;
F_46 ( V_2236 , V_2235 ) ;
return;
case V_2267 :
case V_2302 :
case V_2303 :
case V_2304 :
case V_2305 :
case V_2306 :
case V_2307 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
switch ( V_2235 & V_2264 ) {
case V_2267 :
case V_2302 :
case V_2303 :
V_5 -> V_1970 = V_2277 ;
break;
case V_2304 :
case V_2305 :
V_5 -> V_1970 = V_2276 ;
break;
case V_2306 :
case V_2307 :
V_5 -> V_1970 = V_2234 ;
break;
}
break;
case V_2268 :
case V_2269 :
case V_2270 :
V_5 -> V_608 = V_636 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
switch ( V_2235 & V_2264 ) {
case V_2268 :
V_5 -> V_1970 = V_2277 ;
break;
case V_2269 :
V_5 -> V_1970 = V_2276 ;
break;
case V_2270 :
V_5 -> V_1970 = V_2234 ;
break;
}
break;
default:
F_84 ( V_5 , V_676 ) ;
return;
}
F_610 ( V_5 , V_2235 ) ;
if ( V_5 -> V_610 != 264 && V_5 -> V_610 != 528 )
F_84 ( V_5 , V_607 ) ;
}
static void F_617 ( struct V_4 * V_5 )
{
T_1 V_2235 ;
V_2235 = F_33 ( V_2236 ) ;
switch ( V_2235 & V_2264 ) {
case V_2308 :
case V_2309 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
V_5 -> V_610 = V_2245 ;
V_2235 &= ~ V_2238 ;
F_46 ( V_2236 , V_2235 ) ;
return;
case V_2310 :
case V_2311 :
case V_2312 :
case V_2313 :
case V_2314 :
case V_2315 :
case V_2316 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
switch ( V_2235 & V_2264 ) {
case V_2313 :
break;
case V_2314 :
case V_2315 :
V_5 -> V_1970 = V_2276 ;
break;
default:
V_5 -> V_1970 = V_2277 ;
break;
}
break;
case V_2317 :
case V_2318 :
case V_2319 :
case V_2320 :
case V_2321 :
case V_2322 :
case V_2323 :
case V_2324 :
case V_2325 :
case V_2326 :
V_5 -> V_608 = V_636 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
switch ( V_2235 & V_2264 ) {
case V_2321 :
case V_2323 :
break;
case V_2322 :
case V_2324 :
V_5 -> V_1970 = V_2276 ;
break;
default:
V_5 -> V_1970 = V_2277 ;
break;
}
break;
default:
F_84 ( V_5 , V_676 ) ;
return;
}
F_610 ( V_5 , V_2235 ) ;
if ( V_5 -> V_610 != 264 && V_5 -> V_610 != 528 )
F_84 ( V_5 , V_607 ) ;
}
static void F_618 ( struct V_4 * V_5 )
{
T_1 V_2235 , V_2327 ;
V_2235 = F_33 ( V_2236 ) ;
V_2327 = V_2235 & V_2264 ;
if ( F_30 ( V_5 ) == V_762 ) {
if ( ! ( V_2235 & V_2328 ) ) {
F_84 ( V_5 , V_676 ) ;
return;
}
switch ( V_2327 ) {
case V_2329 :
V_2327 = V_2330 ;
break;
case V_2331 :
V_2327 = V_2332 ;
break;
case V_2333 :
V_2327 = V_2334 ;
break;
}
}
switch ( V_2327 ) {
case V_2330 :
case V_2332 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
V_2235 &= ~ V_2238 ;
F_46 ( V_2236 , V_2235 ) ;
if ( V_2327 == V_2330 )
V_5 -> V_610 = V_2245 ;
else
V_5 -> V_610 = V_2335 ;
return;
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
case V_2347 :
V_5 -> V_608 = V_609 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
switch ( V_2327 ) {
case V_2339 :
case V_2340 :
case V_2341 :
V_5 -> V_1970 = V_2276 ;
break;
case V_2342 :
case V_2343 :
case V_2344 :
V_5 -> V_1970 = V_2234 ;
break;
case V_2345 :
case V_2346 :
V_5 -> V_1970 = V_2301 ;
break;
default:
if ( F_30 ( V_5 ) != V_762 )
V_5 -> V_1970 = V_2277 ;
break;
}
break;
case V_2348 :
case V_2349 :
case V_2350 :
case V_2351 :
case V_2352 :
case V_2333 :
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
case V_2363 :
case V_2334 :
V_5 -> V_608 = V_636 ;
F_84 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_606 ) ;
switch ( V_2327 ) {
case V_2352 :
case V_2333 :
case V_2353 :
case V_2354 :
V_5 -> V_1970 = V_2276 ;
break;
case V_2355 :
case V_2356 :
case V_2357 :
case V_2358 :
V_5 -> V_1970 = V_2234 ;
break;
case V_2359 :
case V_2360 :
case V_2361 :
case V_2362 :
V_5 -> V_1970 = V_2301 ;
break;
default:
if ( F_30 ( V_5 ) != V_762 )
V_5 -> V_1970 = V_2277 ;
break;
}
break;
default:
F_84 ( V_5 , V_676 ) ;
return;
}
F_610 ( V_5 , V_2235 ) ;
if ( V_5 -> V_610 != 264 && V_5 -> V_610 != 528 )
F_84 ( V_5 , V_607 ) ;
if ( F_30 ( V_5 ) == V_762 ) {
T_1 V_7 ;
if ( F_170 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 != V_1979 &&
( V_7 & V_2083 ) != V_2084 )
F_84 ( V_5 , V_676 ) ;
}
}
static void F_619 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_263 ) ) {
F_86 ( V_5 , V_580 ) ;
F_86 ( V_5 , V_605 ) ;
F_84 ( V_5 , V_676 ) ;
return;
}
F_31 ( V_593 ,
( V_2364 |
( V_2365 <<
V_2366 ) ) ) ;
F_164 ( 1 ) ;
F_31 ( V_136 ,
F_33 ( V_136 ) | V_2367 ) ;
F_24 ( 100 ) ;
if ( F_30 ( V_5 ) != V_531 &&
F_30 ( V_5 ) != V_532 ) {
F_84 ( V_5 , V_580 ) ;
if ( F_159 ( V_5 ) ) {
F_144 ( V_5 -> V_111 ,
L_81 ,
V_652 ) ;
return;
}
F_161 ( V_5 ) ;
V_5 -> V_1970 = 0 ;
if ( F_30 ( V_5 ) == V_635 )
F_611 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1489 )
F_612 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1502 ||
F_30 ( V_5 ) == V_408 ||
F_30 ( V_5 ) == V_256 )
F_613 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_45 )
F_614 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_36 )
F_615 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1406 ||
F_23 ( V_5 , 57765_CLASS ) )
F_616 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 )
F_617 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_762 )
F_618 ( V_5 ) ;
else
F_609 ( V_5 ) ;
if ( V_5 -> V_1970 == 0 )
F_607 ( V_5 ) ;
F_162 ( V_5 ) ;
F_160 ( V_5 ) ;
} else {
F_86 ( V_5 , V_580 ) ;
F_86 ( V_5 , V_605 ) ;
F_606 ( V_5 ) ;
}
}
static struct V_2368 * F_620 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_582 ( V_2369 ) ; V_42 ++ ) {
if ( ( V_2369 [ V_42 ] . V_2370 ==
V_5 -> V_12 -> V_2371 ) &&
( V_2369 [ V_42 ] . V_2372 ==
V_5 -> V_12 -> V_2373 ) )
return & V_2369 [ V_42 ] ;
}
return NULL ;
}
static void F_621 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_5 -> V_215 = V_2374 ;
V_5 -> V_558 = V_816 ;
F_84 ( V_5 , V_638 ) ;
F_84 ( V_5 , V_712 ) ;
if ( F_30 ( V_5 ) == V_36 ) {
if ( ! ( F_33 ( V_1904 ) & V_2375 ) ) {
F_86 ( V_5 , V_638 ) ;
F_84 ( V_5 , V_527 ) ;
}
V_7 = F_33 ( V_2376 ) ;
if ( V_7 & V_2377 )
F_84 ( V_5 , V_969 ) ;
if ( ( V_7 & V_2378 ) &&
( V_7 & V_2379 ) ) {
F_84 ( V_5 , V_112 ) ;
F_545 ( & V_5 -> V_12 -> V_111 , true ) ;
}
goto V_186;
}
F_32 ( V_5 , V_1431 , & V_7 ) ;
if ( V_7 == V_1432 ) {
T_1 V_1433 , V_2380 ;
T_1 V_2381 = 0 , V_2382 = 0 , V_2383 = 0 ;
T_1 V_2384 , V_2385 , V_2386 ;
int V_2387 = 0 ;
F_32 ( V_5 , V_1434 , & V_1433 ) ;
V_5 -> V_545 = V_1433 ;
F_32 ( V_5 , V_2388 , & V_2385 ) ;
V_2385 >>= V_2389 ;
if ( F_30 ( V_5 ) != V_531 &&
F_30 ( V_5 ) != V_532 &&
F_30 ( V_5 ) != V_494 &&
( V_2385 > 0 ) && ( V_2385 < 0x100 ) )
F_32 ( V_5 , V_2390 , & V_2381 ) ;
if ( F_30 ( V_5 ) == V_256 )
F_32 ( V_5 , V_2391 , & V_2382 ) ;
if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 )
F_32 ( V_5 , V_2392 , & V_2383 ) ;
if ( ( V_1433 & V_2393 ) ==
V_2394 )
V_2387 = 1 ;
F_32 ( V_5 , V_2395 , & V_2384 ) ;
if ( V_2384 != 0 ) {
T_1 V_2396 = V_2384 & V_2397 ;
T_1 V_2398 = V_2384 & V_2399 ;
V_2386 = ( V_2396 >> 16 ) << 10 ;
V_2386 |= ( V_2398 & 0xfc00 ) << 16 ;
V_2386 |= ( V_2398 & 0x03ff ) << 0 ;
} else
V_2386 = 0 ;
V_5 -> V_215 = V_2386 ;
if ( V_2387 ) {
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_178 |= V_562 ;
else
V_5 -> V_178 |= V_300 ;
}
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2380 = V_2381 & ( V_2400 |
V_2401 ) ;
else
V_2380 = V_1433 & V_2400 ;
switch ( V_2380 ) {
default:
case V_2402 :
V_5 -> V_558 = V_816 ;
break;
case V_2403 :
V_5 -> V_558 = V_559 ;
break;
case V_2404 :
V_5 -> V_558 = V_2405 ;
if ( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 )
V_5 -> V_558 = V_816 ;
break;
case V_2406 :
V_5 -> V_558 = V_2407 ;
if ( F_77 ( V_5 ) != V_1414 &&
F_77 ( V_5 ) != V_2408 )
V_5 -> V_558 |= ( V_816 |
V_559 ) ;
if ( F_23 ( V_5 , 5717_PLUS ) ||
F_30 ( V_5 ) == V_762 )
V_5 -> V_558 |= V_2409 |
V_2410 ;
break;
case V_2411 :
V_5 -> V_558 = V_2412 ;
break;
case V_2413 :
V_5 -> V_558 = V_2414 ;
if ( F_77 ( V_5 ) != V_1414 )
V_5 -> V_558 |= ( V_816 |
V_559 ) ;
break;
}
if ( ( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 ) &&
V_5 -> V_12 -> V_2371 == V_2415 )
V_5 -> V_558 = V_559 ;
if ( F_147 ( V_5 ) == V_498 )
V_5 -> V_558 = V_816 ;
if ( V_1433 & V_2416 ) {
F_84 ( V_5 , V_638 ) ;
if ( ( V_5 -> V_12 -> V_2371 ==
V_2417 ) &&
( V_5 -> V_12 -> V_2373 == 0x205a ||
V_5 -> V_12 -> V_2373 == 0x2063 ) )
F_86 ( V_5 , V_638 ) ;
} else {
F_86 ( V_5 , V_638 ) ;
F_84 ( V_5 , V_527 ) ;
}
if ( V_1433 & V_1435 ) {
F_84 ( V_5 , V_303 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , V_311 ) ;
}
if ( ( V_1433 & V_2418 ) &&
F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , V_60 ) ;
if ( V_5 -> V_178 & V_354 &&
! ( V_1433 & V_2419 ) )
F_86 ( V_5 , V_712 ) ;
if ( F_23 ( V_5 , V_712 ) &&
( V_1433 & V_2420 ) ) {
F_84 ( V_5 , V_112 ) ;
F_545 ( & V_5 -> V_12 -> V_111 , true ) ;
}
if ( V_2381 & ( 1 << 17 ) )
V_5 -> V_178 |= V_819 ;
if ( V_2381 & ( 1 << 18 ) )
V_5 -> V_178 |= V_1732 ;
if ( ( F_23 ( V_5 , 57765_PLUS ) ||
( F_30 ( V_5 ) == V_408 &&
F_147 ( V_5 ) != V_498 ) ) &&
( V_2381 & V_2421 ) )
V_5 -> V_178 |= V_508 ;
if ( F_23 ( V_5 , V_1074 ) ) {
T_1 V_2422 ;
F_32 ( V_5 , V_1436 , & V_2422 ) ;
if ( F_30 ( V_5 ) != V_256 &&
! F_23 ( V_5 , 57765_PLUS ) &&
( V_2422 & V_2423 ) )
F_84 ( V_5 , V_969 ) ;
if ( V_2422 & V_1438 )
V_5 -> V_178 |= V_564 ;
if ( V_2422 & V_1437 )
V_5 -> V_178 |= V_766 ;
}
if ( V_2382 & V_2424 )
F_84 ( V_5 , V_235 ) ;
if ( V_2382 & V_2425 )
F_84 ( V_5 , V_244 ) ;
if ( V_2382 & V_2426 )
F_84 ( V_5 , V_245 ) ;
if ( V_2383 & V_2427 )
V_5 -> V_178 |= V_767 ;
}
V_186:
if ( F_23 ( V_5 , V_712 ) )
F_545 ( & V_5 -> V_12 -> V_111 ,
F_23 ( V_5 , V_112 ) ) ;
else
F_622 ( & V_5 -> V_12 -> V_111 , false ) ;
}
static int F_623 ( struct V_4 * V_5 , T_1 V_590 , T_1 * V_7 )
{
int V_42 , V_75 ;
T_1 V_2428 , V_6 = V_590 * 8 ;
V_75 = F_159 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_11 ( V_5 , V_2429 , V_6 | V_2430 ) ;
F_11 ( V_5 , V_2431 , V_2432 |
V_2433 | V_2434 ) ;
F_12 ( V_5 , V_2431 ) ;
F_24 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_2428 = F_12 ( V_5 , V_2435 ) ;
if ( V_2428 & V_2436 ) {
* V_7 = F_12 ( V_5 , V_2437 ) ;
break;
}
F_24 ( 10 ) ;
}
F_11 ( V_5 , V_2431 , 0 ) ;
F_160 ( V_5 ) ;
if ( V_2428 & V_2436 )
return 0 ;
return - V_67 ;
}
static int F_624 ( struct V_4 * V_5 , T_1 V_637 )
{
int V_42 ;
T_1 V_7 ;
F_46 ( V_2438 , V_637 | V_2439 ) ;
F_46 ( V_2438 , V_637 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_7 = F_33 ( V_2440 ) ;
if ( V_7 & V_2441 )
break;
F_24 ( 10 ) ;
}
return ( V_7 & V_2441 ) ? 0 : - V_67 ;
}
static T_1 F_625 ( struct V_4 * V_5 )
{
T_1 V_2442 , V_2443 ;
F_46 ( V_2444 , V_2445 ) ;
if ( F_624 ( V_5 , V_2446 ) )
return 0 ;
F_46 ( V_2447 , V_2448 ) ;
if ( F_624 ( V_5 , V_2449 ) )
return 0 ;
V_2443 = F_33 ( V_2450 ) ;
F_46 ( V_2447 , V_2451 ) ;
if ( F_624 ( V_5 , V_2449 ) )
return 0 ;
V_2442 = F_33 ( V_2450 ) ;
return ( ( V_2443 & 0x0000ffff ) << 16 ) | ( V_2442 >> 16 ) ;
}
static void F_626 ( struct V_4 * V_5 )
{
T_1 V_336 = V_700 ;
if ( ! ( V_5 -> V_178 & V_387 ) ) {
if ( ! ( V_5 -> V_178 & V_767 ) )
V_336 |= V_768 ;
V_336 |= V_758 ;
}
if ( ! ( V_5 -> V_178 & V_354 ) )
V_336 |= V_703 |
V_704 |
V_701 |
V_705 |
V_698 ;
else
V_336 |= V_775 ;
V_5 -> V_324 . V_393 = V_336 ;
V_5 -> V_324 . V_367 = V_748 ;
V_5 -> V_324 . V_371 = V_749 ;
V_5 -> V_324 . V_347 = V_352 ;
V_5 -> V_324 . V_325 = V_748 ;
V_5 -> V_324 . V_328 = V_749 ;
V_5 -> V_385 = - 1 ;
}
static int F_627 ( struct V_4 * V_5 )
{
T_1 V_2452 , V_2453 ;
T_1 V_2454 , V_2455 ;
int V_75 ;
F_84 ( V_5 , V_353 ) ;
V_5 -> V_324 . V_337 = V_331 | V_332 ;
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
if ( ! F_23 ( V_5 , V_303 ) &&
! ( V_5 -> V_178 & V_354 ) &&
! ( V_5 -> V_178 & V_387 ) )
V_5 -> V_178 &= ~ ( V_766 |
V_564 ) ;
if ( F_23 ( V_5 , V_266 ) )
return F_113 ( V_5 ) ;
V_75 = 0 ;
if ( F_23 ( V_5 , V_303 ) || F_23 ( V_5 , V_60 ) ) {
V_2454 = V_2455 = V_2374 ;
} else {
V_75 |= F_57 ( V_5 , V_2456 , & V_2452 ) ;
V_75 |= F_57 ( V_5 , V_2457 , & V_2453 ) ;
V_2454 = ( V_2452 & 0xffff ) << 10 ;
V_2454 |= ( V_2453 & 0xfc00 ) << 16 ;
V_2454 |= ( V_2453 & 0x03ff ) << 0 ;
V_2455 = V_2454 & V_395 ;
}
if ( ! V_75 && F_628 ( V_2455 ) ) {
V_5 -> V_215 = V_2454 ;
if ( V_2455 == V_936 )
V_5 -> V_178 |= V_562 ;
else
V_5 -> V_178 &= ~ V_562 ;
} else {
if ( V_5 -> V_215 != V_2374 ) {
} else {
struct V_2368 * V_1441 ;
V_1441 = F_620 ( V_5 ) ;
if ( V_1441 ) {
V_5 -> V_215 = V_1441 -> V_215 ;
} else if ( ! F_23 ( V_5 , V_263 ) ) {
return - V_82 ;
}
if ( ! V_5 -> V_215 ||
V_5 -> V_215 == V_936 )
V_5 -> V_178 |= V_562 ;
}
}
if ( ! ( V_5 -> V_178 & V_354 ) &&
( F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_662 ||
F_30 ( V_5 ) == V_762 ||
( F_30 ( V_5 ) == V_471 &&
F_77 ( V_5 ) != V_258 ) ||
( F_30 ( V_5 ) == V_760 &&
F_77 ( V_5 ) != V_322 ) ) ) {
V_5 -> V_178 |= V_333 ;
V_5 -> V_447 . V_388 = V_1990 |
V_1988 ;
V_5 -> V_447 . V_458 = V_704 |
V_758 ;
V_5 -> V_447 . V_457 = 1 ;
V_5 -> V_447 . V_460 = 1 ;
V_5 -> V_447 . V_462 = V_2458 ;
}
F_626 ( V_5 ) ;
if ( ! ( V_5 -> V_178 & V_564 ) &&
! ( V_5 -> V_178 & V_354 ) &&
! F_23 ( V_5 , V_60 ) &&
! F_23 ( V_5 , V_303 ) ) {
T_1 V_807 , V_2459 ;
F_57 ( V_5 , V_297 , & V_807 ) ;
if ( ! F_57 ( V_5 , V_297 , & V_807 ) &&
( V_807 & V_773 ) )
goto V_2460;
V_75 = F_145 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_131 ( V_5 ) ;
if ( ! F_217 ( V_5 , & V_2459 ) ) {
F_207 ( V_5 , V_5 -> V_324 . V_393 ,
V_5 -> V_324 . V_337 ) ;
F_59 ( V_5 , V_204 ,
V_571 | V_572 ) ;
}
}
V_2460:
if ( ( V_5 -> V_215 & V_395 ) == V_396 ) {
V_75 = F_215 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_215 ( V_5 ) ;
}
return V_75 ;
}
static void F_629 ( struct V_4 * V_5 )
{
T_4 * V_2461 ;
unsigned int V_2462 , V_2463 , V_74 ;
T_1 V_2068 ;
int V_622 , V_42 = 0 ;
V_2461 = ( T_4 * ) F_565 ( V_5 , & V_2068 ) ;
if ( ! V_2461 )
goto V_2464;
V_42 = F_570 ( V_2461 , 0 , V_2068 , V_2111 ) ;
if ( V_42 < 0 )
goto V_2465;
V_2463 = F_571 ( & V_2461 [ V_42 ] ) ;
V_2462 = V_42 + V_2112 + V_2463 ;
V_42 += V_2112 ;
if ( V_2462 > V_2068 )
goto V_2465;
V_622 = F_572 ( V_2461 , V_42 , V_2463 ,
V_2466 ) ;
if ( V_622 > 0 ) {
V_74 = F_630 ( & V_2461 [ V_622 ] ) ;
V_622 += V_2114 ;
if ( V_622 + V_74 > V_2462 || V_74 != 4 ||
memcmp ( & V_2461 [ V_622 ] , L_82 , 4 ) )
goto V_2467;
V_622 = F_572 ( V_2461 , V_42 , V_2463 ,
V_2468 ) ;
if ( V_622 < 0 )
goto V_2467;
V_74 = F_630 ( & V_2461 [ V_622 ] ) ;
V_622 += V_2114 ;
if ( V_622 + V_74 > V_2462 )
goto V_2467;
if ( V_74 >= sizeof( V_5 -> V_2012 ) )
V_74 = sizeof( V_5 -> V_2012 ) - 1 ;
memset ( V_5 -> V_2012 , 0 , sizeof( V_5 -> V_2012 ) ) ;
snprintf ( V_5 -> V_2012 , sizeof( V_5 -> V_2012 ) , L_83 , V_74 ,
& V_2461 [ V_622 ] ) ;
}
V_2467:
V_42 = F_572 ( V_2461 , V_42 , V_2463 ,
V_2469 ) ;
if ( V_42 < 0 )
goto V_2465;
V_74 = F_630 ( & V_2461 [ V_42 ] ) ;
V_42 += V_2114 ;
if ( V_74 > V_2470 ||
( V_74 + V_42 ) > V_2068 )
goto V_2465;
memcpy ( V_5 -> V_2471 , & V_2461 [ V_42 ] , V_74 ) ;
V_2465:
F_177 ( V_2461 ) ;
if ( V_5 -> V_2471 [ 0 ] )
return;
V_2464:
if ( F_30 ( V_5 ) == V_471 ) {
if ( V_5 -> V_12 -> V_538 == V_2472 ||
V_5 -> V_12 -> V_538 == V_2473 )
strcpy ( V_5 -> V_2471 , L_84 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2474 )
strcpy ( V_5 -> V_2471 , L_85 ) ;
else
goto V_2475;
} else if ( F_30 ( V_5 ) == V_1406 ) {
if ( V_5 -> V_12 -> V_538 == V_2476 )
strcpy ( V_5 -> V_2471 , L_86 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2477 )
strcpy ( V_5 -> V_2471 , L_87 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2478 )
strcpy ( V_5 -> V_2471 , L_88 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2479 )
strcpy ( V_5 -> V_2471 , L_89 ) ;
else
goto V_2475;
} else if ( F_30 ( V_5 ) == V_760 ) {
if ( V_5 -> V_12 -> V_538 == V_2480 )
strcpy ( V_5 -> V_2471 , L_90 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2481 )
strcpy ( V_5 -> V_2471 , L_91 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2482 )
strcpy ( V_5 -> V_2471 , L_92 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2483 )
strcpy ( V_5 -> V_2471 , L_93 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2484 )
strcpy ( V_5 -> V_2471 , L_94 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2485 )
strcpy ( V_5 -> V_2471 , L_95 ) ;
else
goto V_2475;
} else if ( F_30 ( V_5 ) == V_662 ) {
if ( V_5 -> V_12 -> V_538 == V_2486 )
strcpy ( V_5 -> V_2471 , L_96 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2487 )
strcpy ( V_5 -> V_2471 , L_97 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2488 )
strcpy ( V_5 -> V_2471 , L_98 ) ;
else if ( V_5 -> V_12 -> V_538 == V_2489 )
strcpy ( V_5 -> V_2471 , L_99 ) ;
else
goto V_2475;
} else if ( F_30 ( V_5 ) == V_36 ) {
strcpy ( V_5 -> V_2471 , L_100 ) ;
} else {
V_2475:
strcpy ( V_5 -> V_2471 , L_101 ) ;
}
}
static int F_631 ( struct V_4 * V_5 , T_1 V_590 )
{
T_1 V_7 ;
if ( F_170 ( V_5 , V_590 , & V_7 ) ||
( V_7 & 0xfc000000 ) != 0x0c000000 ||
F_170 ( V_5 , V_590 + 4 , & V_7 ) ||
V_7 != 0 )
return 0 ;
return 1 ;
}
static void F_632 ( struct V_4 * V_5 )
{
T_1 V_7 , V_590 , V_1023 , V_2490 ;
int V_42 , V_2491 ;
bool V_2492 = false ;
if ( F_170 ( V_5 , 0xc , & V_590 ) ||
F_170 ( V_5 , 0x4 , & V_1023 ) )
return;
V_590 = F_169 ( V_5 , V_590 ) ;
if ( F_170 ( V_5 , V_590 , & V_7 ) )
return;
if ( ( V_7 & 0xfc000000 ) == 0x0c000000 ) {
if ( F_170 ( V_5 , V_590 + 4 , & V_7 ) )
return;
if ( V_7 == 0 )
V_2492 = true ;
}
V_2491 = strlen ( V_5 -> V_2012 ) ;
if ( V_2492 ) {
if ( V_2493 - V_2491 < 16 ||
F_170 ( V_5 , V_590 + 8 , & V_2490 ) )
return;
V_590 = V_590 + V_2490 - V_1023 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 += 4 ) {
T_5 V_619 ;
if ( F_171 ( V_5 , V_590 + V_42 , & V_619 ) )
return;
memcpy ( V_5 -> V_2012 + V_2491 + V_42 , & V_619 , sizeof( V_619 ) ) ;
}
} else {
T_1 V_2494 , V_2495 ;
if ( F_170 ( V_5 , V_2496 , & V_2490 ) )
return;
V_2494 = ( V_2490 & V_2497 ) >>
V_2498 ;
V_2495 = V_2490 & V_2499 ;
snprintf ( & V_5 -> V_2012 [ V_2491 ] , V_2493 - V_2491 ,
L_102 , V_2494 , V_2495 ) ;
}
}
static void F_633 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2494 , V_2495 ;
if ( F_170 ( V_5 , V_2500 , & V_7 ) )
return;
V_2494 = ( V_7 & V_2501 ) >>
V_2502 ;
V_2495 = ( V_7 & V_2503 ) >>
V_2504 ;
snprintf ( & V_5 -> V_2012 [ 0 ] , 32 , L_103 , V_2494 , V_2495 ) ;
}
static void F_634 ( struct V_4 * V_5 , T_1 V_7 )
{
T_1 V_590 , V_2494 , V_2495 , V_2505 ;
strncat ( V_5 -> V_2012 , L_104 , V_2493 - strlen ( V_5 -> V_2012 ) - 1 ) ;
if ( ( V_7 & V_2085 ) != V_2086 )
return;
switch ( V_7 & V_2087 ) {
case V_2088 :
V_590 = V_2506 ;
break;
case V_2090 :
V_590 = V_2507 ;
break;
case V_2092 :
V_590 = V_2508 ;
break;
case V_2094 :
V_590 = V_2509 ;
break;
case V_2096 :
V_590 = V_2510 ;
break;
case V_2098 :
V_590 = V_2511 ;
break;
default:
return;
}
if ( F_170 ( V_5 , V_590 , & V_7 ) )
return;
V_2505 = ( V_7 & V_2512 ) >>
V_2513 ;
V_2494 = ( V_7 & V_2514 ) >>
V_2515 ;
V_2495 = V_7 & V_2516 ;
if ( V_2495 > 99 || V_2505 > 26 )
return;
V_590 = strlen ( V_5 -> V_2012 ) ;
snprintf ( & V_5 -> V_2012 [ V_590 ] , V_2493 - V_590 ,
L_105 , V_2494 , V_2495 ) ;
if ( V_2505 > 0 ) {
V_590 = strlen ( V_5 -> V_2012 ) ;
if ( V_590 < V_2493 - 1 )
V_5 -> V_2012 [ V_590 ] = 'a' + V_2505 - 1 ;
}
}
static void F_635 ( struct V_4 * V_5 )
{
T_1 V_7 , V_590 , V_1023 ;
int V_42 , V_2517 ;
for ( V_590 = V_2069 ;
V_590 < V_2070 ;
V_590 += V_2071 ) {
if ( F_170 ( V_5 , V_590 , & V_7 ) )
return;
if ( ( V_7 >> V_2072 ) == V_2518 )
break;
}
if ( V_590 == V_2070 )
return;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_1023 = 0x08000000 ;
else if ( F_170 ( V_5 , V_590 - 4 , & V_1023 ) )
return;
if ( F_170 ( V_5 , V_590 + 4 , & V_590 ) ||
! F_631 ( V_5 , V_590 ) ||
F_170 ( V_5 , V_590 + 8 , & V_7 ) )
return;
V_590 += V_7 - V_1023 ;
V_2517 = strlen ( V_5 -> V_2012 ) ;
V_5 -> V_2012 [ V_2517 ++ ] = ',' ;
V_5 -> V_2012 [ V_2517 ++ ] = ' ' ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
T_5 V_619 ;
if ( F_171 ( V_5 , V_590 , & V_619 ) )
return;
V_590 += sizeof( V_619 ) ;
if ( V_2517 > V_2493 - sizeof( V_619 ) ) {
memcpy ( & V_5 -> V_2012 [ V_2517 ] , & V_619 , V_2493 - V_2517 ) ;
break;
}
memcpy ( & V_5 -> V_2012 [ V_2517 ] , & V_619 , sizeof( V_619 ) ) ;
V_2517 += sizeof( V_619 ) ;
}
}
static void F_636 ( struct V_4 * V_5 )
{
T_1 V_69 ;
V_69 = F_12 ( V_5 , V_80 ) ;
if ( V_69 != V_81 )
return;
V_69 = F_12 ( V_5 , V_83 ) ;
if ( ! ( V_69 & V_84 ) )
return;
if ( F_12 ( V_5 , V_2519 ) & V_2520 )
F_84 ( V_5 , V_79 ) ;
}
static void F_637 ( struct V_4 * V_5 )
{
int V_2517 ;
T_1 V_69 ;
char * V_2521 ;
V_69 = F_12 ( V_5 , V_2522 ) ;
if ( F_23 ( V_5 , V_79 ) )
V_2521 = L_106 ;
else if ( V_5 -> V_12 -> V_538 == V_2523 )
V_2521 = L_107 ;
else
V_2521 = L_108 ;
V_2517 = strlen ( V_5 -> V_2012 ) ;
snprintf ( & V_5 -> V_2012 [ V_2517 ] , V_2493 - V_2517 , L_109 ,
V_2521 ,
( V_69 & V_2524 ) >> V_2525 ,
( V_69 & V_2526 ) >> V_2527 ,
( V_69 & V_2528 ) >> V_2529 ,
( V_69 & V_2530 ) ) ;
}
static void F_638 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2428 ;
if ( F_30 ( V_5 ) != V_762 )
return;
if ( ! F_623 ( V_5 , V_2531 , & V_7 ) &&
! F_623 ( V_5 , V_2531 + 4 , & V_2428 ) &&
F_639 ( V_7 ) ) {
T_6 V_2532 = ( T_6 ) V_7 << 32 | V_2428 ;
T_1 V_2385 = 0 ;
int V_42 , V_2517 ;
for ( V_42 = 0 ; V_42 < 7 ; V_42 ++ ) {
if ( ( V_2532 & 0xff ) == 0 )
break;
V_2385 = V_2532 & 0xff ;
V_2532 >>= 8 ;
}
V_2517 = strlen ( V_5 -> V_2012 ) ;
snprintf ( & V_5 -> V_2012 [ V_2517 ] , V_2493 - V_2517 , L_110 , V_2385 ) ;
}
}
static void F_640 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_2533 = false ;
if ( V_5 -> V_2012 [ 0 ] != 0 )
V_2533 = true ;
if ( F_23 ( V_5 , V_676 ) ) {
strcat ( V_5 -> V_2012 , L_104 ) ;
F_638 ( V_5 ) ;
return;
}
if ( F_170 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 == V_1979 )
F_632 ( V_5 ) ;
else if ( ( V_7 & V_2083 ) == V_2084 )
F_634 ( V_5 , V_7 ) ;
else if ( ( V_7 & V_2100 ) == V_2101 )
F_633 ( V_5 ) ;
if ( F_23 ( V_5 , V_303 ) ) {
if ( F_23 ( V_5 , V_60 ) ) {
F_636 ( V_5 ) ;
if ( ! V_2533 )
F_637 ( V_5 ) ;
} else if ( ! V_2533 ) {
F_635 ( V_5 ) ;
}
}
V_5 -> V_2012 [ V_2493 - 1 ] = 0 ;
}
static inline T_1 F_641 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1714 ) )
return V_2534 ;
else if ( F_23 ( V_5 , V_516 ) && ! F_23 ( V_5 , 5780_CLASS ) )
return V_2535 ;
else
return V_2536 ;
}
static struct V_1786 * F_642 ( struct V_4 * V_5 )
{
struct V_1786 * V_2537 ;
unsigned int V_2538 , V_2539 = V_5 -> V_12 -> V_273 & ~ 7 ;
for ( V_2538 = 0 ; V_2538 < 8 ; V_2538 ++ ) {
V_2537 = F_643 ( V_5 -> V_12 -> V_271 , V_2539 | V_2538 ) ;
if ( V_2537 && V_2537 != V_5 -> V_12 )
break;
F_644 ( V_2537 ) ;
}
if ( ! V_2537 ) {
V_2537 = V_5 -> V_12 ;
return V_2537 ;
}
F_644 ( V_2537 ) ;
return V_2537 ;
}
static void F_645 ( struct V_4 * V_5 , T_1 V_2540 )
{
V_5 -> V_2541 = V_2540 >> V_2542 ;
if ( F_30 ( V_5 ) == V_2543 ) {
T_1 V_161 ;
F_84 ( V_5 , V_152 ) ;
if ( V_5 -> V_12 -> V_538 == V_2472 ||
V_5 -> V_12 -> V_538 == V_2473 ||
V_5 -> V_12 -> V_538 == V_2474 ||
V_5 -> V_12 -> V_538 == V_2544 ||
V_5 -> V_12 -> V_538 == V_2545 ||
V_5 -> V_12 -> V_538 == V_2546 ||
V_5 -> V_12 -> V_538 == V_2547 ||
V_5 -> V_12 -> V_538 == V_2548 ||
V_5 -> V_12 -> V_538 == V_2523 ||
V_5 -> V_12 -> V_538 == V_2549 ||
V_5 -> V_12 -> V_538 == V_2550 )
V_161 = V_2551 ;
else if ( V_5 -> V_12 -> V_538 == V_2482 ||
V_5 -> V_12 -> V_538 == V_2483 ||
V_5 -> V_12 -> V_538 == V_2480 ||
V_5 -> V_12 -> V_538 == V_2481 ||
V_5 -> V_12 -> V_538 == V_2484 ||
V_5 -> V_12 -> V_538 == V_2485 ||
V_5 -> V_12 -> V_538 == V_2486 ||
V_5 -> V_12 -> V_538 == V_2487 ||
V_5 -> V_12 -> V_538 == V_2488 ||
V_5 -> V_12 -> V_538 == V_2489 )
V_161 = V_2552 ;
else
V_161 = V_2553 ;
F_19 ( V_5 -> V_12 , V_161 , & V_5 -> V_2541 ) ;
}
if ( F_77 ( V_5 ) == V_2554 )
V_5 -> V_2541 = V_2555 ;
if ( F_77 ( V_5 ) == V_2556 )
V_5 -> V_2541 = V_1614 ;
if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 )
F_84 ( V_5 , 5717_PLUS ) ;
if ( F_30 ( V_5 ) == V_760 ||
F_30 ( V_5 ) == V_662 )
F_84 ( V_5 , 57765_CLASS ) ;
if ( F_23 ( V_5 , 57765_CLASS ) || F_23 ( V_5 , 5717_PLUS ) ||
F_30 ( V_5 ) == V_762 )
F_84 ( V_5 , 57765_PLUS ) ;
if ( F_30 ( V_5 ) == V_1489 ||
F_30 ( V_5 ) == V_1502 ||
F_30 ( V_5 ) == V_408 ||
F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1406 ||
F_23 ( V_5 , 57765_PLUS ) )
F_84 ( V_5 , 5755_PLUS ) ;
if ( F_30 ( V_5 ) == V_561 ||
F_30 ( V_5 ) == V_543 )
F_84 ( V_5 , 5780_CLASS ) ;
if ( F_30 ( V_5 ) == V_1500 ||
F_30 ( V_5 ) == V_635 ||
F_30 ( V_5 ) == V_36 ||
F_23 ( V_5 , 5755_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) )
F_84 ( V_5 , 5750_PLUS ) ;
if ( F_30 ( V_5 ) == V_496 ||
F_23 ( V_5 , 5750_PLUS ) )
F_84 ( V_5 , 5705_PLUS ) ;
}
static bool F_646 ( struct V_4 * V_5 ,
const struct V_2557 * V_2558 )
{
T_1 V_2559 = F_33 ( V_492 ) & V_2560 ;
if ( ( F_30 ( V_5 ) == V_494 &&
( V_2559 == 0x8000 || V_2559 == 0x4000 ) ) ||
( V_5 -> V_178 & V_179 ) )
return true ;
if ( V_2558 -> V_2561 & V_2562 ) {
if ( F_30 ( V_5 ) == V_496 ) {
if ( V_2558 -> V_2561 & V_2563 )
return true ;
} else {
return true ;
}
}
return false ;
}
static int F_647 ( struct V_4 * V_5 , const struct V_2557 * V_2558 )
{
T_1 V_2540 ;
T_1 V_2564 , V_2559 ;
T_1 V_7 ;
T_3 V_1380 ;
int V_75 ;
F_425 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
V_1380 &= ~ V_2565 ;
F_427 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
F_19 ( V_5 -> V_12 , V_119 ,
& V_2540 ) ;
V_5 -> V_120 |= ( V_2540 &
V_2566 ) ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
F_645 ( V_5 , V_2540 ) ;
if ( ( F_77 ( V_5 ) == V_1733 ) ||
( F_77 ( V_5 ) == V_2567 ) ) {
static struct V_2568 {
T_1 V_2569 ;
T_1 V_538 ;
T_1 V_2570 ;
} V_2571 [] = {
{ V_2572 , V_2573 ,
V_2574 } ,
{ V_2572 , V_2575 ,
V_2574 } ,
{ V_2572 , V_2576 ,
0xa } ,
{ V_2572 , V_2577 ,
V_2574 } ,
{ } ,
} ;
struct V_2568 * V_2578 = & V_2571 [ 0 ] ;
struct V_1786 * V_2579 = NULL ;
while ( V_2578 -> V_2569 != 0 ) {
V_2579 = F_648 ( V_2578 -> V_2569 , V_2578 -> V_538 ,
V_2579 ) ;
if ( ! V_2579 ) {
V_2578 ++ ;
continue;
}
if ( V_2578 -> V_2570 != V_2574 ) {
if ( V_2579 -> V_2580 > V_2578 -> V_2570 )
continue;
}
if ( V_2579 -> V_2581 &&
( V_2579 -> V_2581 -> V_272 ==
V_5 -> V_12 -> V_271 -> V_272 ) ) {
F_84 ( V_5 , V_26 ) ;
F_644 ( V_2579 ) ;
break;
}
}
}
if ( F_30 ( V_5 ) == V_532 ) {
static struct V_2568 {
T_1 V_2569 ;
T_1 V_538 ;
} V_2582 [] = {
{ V_2572 , V_2583 } ,
{ V_2572 , V_2584 } ,
{ } ,
} ;
struct V_2568 * V_2578 = & V_2582 [ 0 ] ;
struct V_1786 * V_2579 = NULL ;
while ( V_2578 -> V_2569 != 0 ) {
V_2579 = F_648 ( V_2578 -> V_2569 ,
V_2578 -> V_538 ,
V_2579 ) ;
if ( ! V_2579 ) {
V_2578 ++ ;
continue;
}
if ( V_2579 -> V_2581 &&
( V_2579 -> V_2581 -> V_272 <=
V_5 -> V_12 -> V_271 -> V_272 ) &&
( V_2579 -> V_2581 -> V_2585 . V_1984 >=
V_5 -> V_12 -> V_271 -> V_272 ) ) {
F_84 ( V_5 , 5701_DMA_BUG ) ;
F_644 ( V_2579 ) ;
break;
}
}
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_84 ( V_5 , 40BIT_DMA_BUG ) ;
V_5 -> V_1397 = V_5 -> V_12 -> V_1397 ;
} else {
struct V_1786 * V_2579 = NULL ;
do {
V_2579 = F_648 ( V_2586 ,
V_2587 ,
V_2579 ) ;
if ( V_2579 && V_2579 -> V_2581 &&
( V_2579 -> V_2581 -> V_272 <=
V_5 -> V_12 -> V_271 -> V_272 ) &&
( V_2579 -> V_2581 -> V_2585 . V_1984 >=
V_5 -> V_12 -> V_271 -> V_272 ) ) {
F_84 ( V_5 , 40BIT_DMA_BUG ) ;
F_644 ( V_2579 ) ;
break;
}
} while ( V_2579 );
}
if ( F_30 ( V_5 ) == V_495 ||
F_30 ( V_5 ) == V_543 )
V_5 -> V_554 = F_642 ( V_5 ) ;
if ( F_77 ( V_5 ) == V_1613 )
;
else if ( F_23 ( V_5 , 57765_PLUS ) )
F_84 ( V_5 , V_1295 ) ;
else if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_84 ( V_5 , V_1294 ) ;
else if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_84 ( V_5 , V_1293 ) ;
F_84 ( V_5 , V_1288 ) ;
if ( F_30 ( V_5 ) == V_1500 &&
F_77 ( V_5 ) >= V_2588 )
F_86 ( V_5 , V_1288 ) ;
} else if ( F_30 ( V_5 ) != V_531 &&
F_30 ( V_5 ) != V_532 &&
F_77 ( V_5 ) != V_1429 ) {
F_84 ( V_5 , V_678 ) ;
F_84 ( V_5 , V_1288 ) ;
if ( F_30 ( V_5 ) == V_496 )
V_5 -> V_1886 = V_2589 ;
else
V_5 -> V_1886 = V_2590 ;
}
if ( F_23 ( V_5 , V_1293 ) ||
F_23 ( V_5 , V_1294 ) ||
F_23 ( V_5 , V_1295 ) ||
F_23 ( V_5 , V_678 ) ) {
F_84 ( V_5 , V_1595 ) ;
} else {
F_86 ( V_5 , V_1595 ) ;
F_86 ( V_5 , V_1288 ) ;
V_5 -> V_1886 = NULL ;
}
if ( F_77 ( V_5 ) == V_754 )
V_5 -> V_1886 = V_2591 ;
if ( F_30 ( V_5 ) == V_662 )
V_5 -> V_1886 = V_2592 ;
V_5 -> V_122 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_84 ( V_5 , V_1896 ) ;
if ( F_147 ( V_5 ) == V_736 ||
F_147 ( V_5 ) == V_737 ||
( F_30 ( V_5 ) == V_543 &&
F_77 ( V_5 ) <= V_2593 &&
V_5 -> V_554 == V_5 -> V_12 ) )
F_86 ( V_5 , V_1896 ) ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 ) {
F_84 ( V_5 , 1SHOT_MSI ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
F_84 ( V_5 , V_1056 ) ;
V_5 -> V_122 = V_1890 ;
}
}
V_5 -> V_1895 = 1 ;
V_5 -> V_1893 = 1 ;
if ( V_5 -> V_122 > 1 ) {
V_5 -> V_1893 = V_2042 ;
F_460 ( V_5 , V_2042 ) ;
if ( F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 )
V_5 -> V_1895 = V_5 -> V_122 - 1 ;
}
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_84 ( V_5 , V_1251 ) ;
if ( F_30 ( V_5 ) == V_472 )
V_5 -> V_1252 = V_2594 ;
if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_762 )
F_84 ( V_5 , V_1714 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) &&
F_77 ( V_5 ) != V_1613 )
F_84 ( V_5 , V_1303 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_1303 ) )
F_84 ( V_5 , V_516 ) ;
F_19 ( V_5 -> V_12 , V_1236 ,
& V_2564 ) ;
if ( F_433 ( V_5 -> V_12 ) ) {
T_3 V_2595 ;
F_84 ( V_5 , V_1074 ) ;
F_649 ( V_5 -> V_12 , V_695 , & V_2595 ) ;
if ( V_2595 & V_696 ) {
if ( F_30 ( V_5 ) == V_36 ) {
F_86 ( V_5 , V_1294 ) ;
F_86 ( V_5 , V_1595 ) ;
}
if ( F_30 ( V_5 ) == V_408 ||
F_30 ( V_5 ) == V_45 ||
F_77 ( V_5 ) == V_2596 ||
F_77 ( V_5 ) == V_2597 )
F_84 ( V_5 , V_694 ) ;
} else if ( F_77 ( V_5 ) == V_258 ) {
F_84 ( V_5 , V_1554 ) ;
}
} else if ( F_30 ( V_5 ) == V_256 ) {
F_84 ( V_5 , V_1074 ) ;
} else if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ) {
V_5 -> V_1392 = F_650 ( V_5 -> V_12 , V_2598 ) ;
if ( ! V_5 -> V_1392 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_111 ) ;
return - V_210 ;
}
if ( ! ( V_2564 & V_2599 ) )
F_84 ( V_5 , V_836 ) ;
}
if ( F_651 ( V_2600 ) &&
! F_23 ( V_5 , V_1074 ) )
F_84 ( V_5 , V_31 ) ;
F_652 ( V_5 -> V_12 , V_1387 ,
& V_5 -> V_1388 ) ;
F_652 ( V_5 -> V_12 , V_1389 ,
& V_5 -> V_1390 ) ;
if ( F_30 ( V_5 ) == V_494 &&
V_5 -> V_1390 < 64 ) {
V_5 -> V_1390 = 64 ;
F_428 ( V_5 -> V_12 , V_1389 ,
V_5 -> V_1390 ) ;
}
if ( F_147 ( V_5 ) == V_2601 ) {
F_84 ( V_5 , V_34 ) ;
if ( F_23 ( V_5 , V_836 ) ) {
T_1 V_2602 ;
F_84 ( V_5 , V_25 ) ;
F_19 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2603 + V_2604 ,
& V_2602 ) ;
V_2602 &= ~ V_2605 ;
V_2602 |= V_2606 | 0 ;
F_15 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2603 + V_2604 ,
V_2602 ) ;
F_425 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
V_1380 |= V_2607 | V_1885 ;
F_427 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
}
}
if ( ( V_2564 & V_1642 ) != 0 )
F_84 ( V_5 , V_837 ) ;
if ( ( V_2564 & V_2608 ) != 0 )
F_84 ( V_5 , V_2609 ) ;
if ( ( F_77 ( V_5 ) == V_913 ) &&
( ! ( V_2564 & V_1383 ) ) ) {
V_2564 |= V_1383 ;
F_15 ( V_5 -> V_12 , V_1236 , V_2564 ) ;
}
V_5 -> V_28 = F_9 ;
V_5 -> V_27 = F_7 ;
V_5 -> V_32 = F_9 ;
V_5 -> V_29 = F_7 ;
V_5 -> V_1089 = F_7 ;
V_5 -> V_1878 = F_7 ;
if ( F_23 ( V_5 , V_25 ) )
V_5 -> V_27 = F_13 ;
else if ( F_30 ( V_5 ) == V_532 ||
( F_23 ( V_5 , V_1074 ) &&
F_77 ( V_5 ) == V_1414 ) ) {
V_5 -> V_27 = F_17 ;
}
if ( F_23 ( V_5 , V_34 ) || F_23 ( V_5 , V_31 ) ) {
V_5 -> V_1089 = F_26 ;
if ( F_23 ( V_5 , V_31 ) )
V_5 -> V_1878 = F_17 ;
}
if ( F_23 ( V_5 , V_26 ) ) {
V_5 -> V_28 = F_18 ;
V_5 -> V_27 = F_13 ;
V_5 -> V_32 = F_21 ;
V_5 -> V_29 = F_20 ;
V_5 -> V_1089 = F_20 ;
V_5 -> V_1878 = F_20 ;
F_653 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
F_425 ( V_5 -> V_12 , V_1379 , & V_1380 ) ;
V_1380 &= ~ V_2610 ;
F_427 ( V_5 -> V_12 , V_1379 , V_1380 ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_32 = F_27 ;
V_5 -> V_29 = F_28 ;
V_5 -> V_1089 = F_28 ;
V_5 -> V_1878 = F_28 ;
}
if ( V_5 -> V_27 == F_13 ||
( F_23 ( V_5 , V_836 ) &&
( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 ) ) )
F_84 ( V_5 , V_39 ) ;
V_7 = F_33 ( V_1058 ) ;
F_46 ( V_1058 , V_7 | V_1378 ) ;
V_5 -> V_54 = F_654 ( V_5 -> V_12 -> V_273 ) & 3 ;
if ( F_30 ( V_5 ) == V_495 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_836 ) ) {
F_19 ( V_5 -> V_12 ,
V_5 -> V_1392 + V_2611 ,
& V_7 ) ;
V_5 -> V_54 = V_7 & 0x7 ;
}
} else if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 ) {
F_32 ( V_5 , V_2612 , & V_7 ) ;
if ( ( V_7 & V_2613 ) != V_2614 )
V_7 = F_33 ( V_1863 ) ;
if ( F_30 ( V_5 ) == V_471 )
V_5 -> V_54 = ( V_7 & V_2615 ) ? 1 : 0 ;
else
V_5 -> V_54 = ( V_7 & V_2616 ) >>
V_2617 ;
}
if ( F_23 ( V_5 , V_30 ) ) {
V_5 -> V_1089 = F_17 ;
V_5 -> V_1878 = F_17 ;
}
F_621 ( V_5 ) ;
if ( F_23 ( V_5 , V_678 ) && F_23 ( V_5 , V_303 ) ) {
F_86 ( V_5 , V_1595 ) ;
F_86 ( V_5 , V_1288 ) ;
V_5 -> V_1886 = NULL ;
}
if ( F_23 ( V_5 , V_60 ) ) {
V_2564 |= V_1384 |
V_1385 |
V_1386 ;
F_15 ( V_5 -> V_12 , V_1236 ,
V_2564 ) ;
F_34 ( V_5 ) ;
}
V_5 -> V_22 = V_2618 | V_2367 ;
if ( F_30 ( V_5 ) == V_531 ||
F_23 ( V_5 , V_638 ) )
V_5 -> V_22 |= ( V_533 |
V_534 ) ;
else if ( F_30 ( V_5 ) == V_635 )
V_5 -> V_22 |= V_544 ;
if ( F_30 ( V_5 ) == V_1489 ||
F_30 ( V_5 ) == V_1406 ||
F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_22 |= V_1687 ;
if ( V_5 -> V_12 -> V_538 == V_539 ||
V_5 -> V_12 -> V_538 == V_540 ) {
V_5 -> V_22 |= V_1687 ;
if ( F_23 ( V_5 , V_527 ) )
V_5 -> V_22 |= V_535 |
V_537 ;
}
if ( F_30 ( V_5 ) == V_762 )
V_5 -> V_22 |=
F_33 ( V_136 ) & V_1687 ;
F_149 ( V_5 ) ;
if ( V_5 -> V_111 -> V_1193 > V_1328 && ! F_23 ( V_5 , 5780_CLASS ) )
F_84 ( V_5 , V_1340 ) ;
if ( F_30 ( V_5 ) == V_531 ||
F_77 ( V_5 ) == V_754 ||
F_77 ( V_5 ) == V_755 ||
F_77 ( V_5 ) == V_2619 ) {
F_86 ( V_5 , V_702 ) ;
} else {
F_84 ( V_5 , V_702 ) ;
}
if ( F_30 ( V_5 ) == V_36 )
V_5 -> V_178 |= V_179 ;
if ( F_30 ( V_5 ) == V_531 ||
( F_30 ( V_5 ) == V_496 &&
( F_77 ( V_5 ) != V_1429 ) &&
( F_77 ( V_5 ) != V_1699 ) ) ||
( V_5 -> V_178 & V_179 ) ||
( V_5 -> V_178 & V_354 ) )
V_5 -> V_178 |= V_418 ;
if ( F_147 ( V_5 ) == V_2620 ||
F_147 ( V_5 ) == V_2621 )
V_5 -> V_178 |= V_509 ;
if ( F_77 ( V_5 ) == V_913 )
V_5 -> V_178 |= V_510 ;
if ( F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) != V_256 &&
F_30 ( V_5 ) != V_1406 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
if ( F_30 ( V_5 ) == V_1489 ||
F_30 ( V_5 ) == V_1502 ||
F_30 ( V_5 ) == V_408 ||
F_30 ( V_5 ) == V_45 ) {
if ( V_5 -> V_12 -> V_538 != V_2622 &&
V_5 -> V_12 -> V_538 != V_2623 )
V_5 -> V_178 |= V_512 ;
if ( V_5 -> V_12 -> V_538 == V_2624 )
V_5 -> V_178 |= V_513 ;
} else
V_5 -> V_178 |= V_511 ;
}
if ( F_30 ( V_5 ) == V_408 &&
F_147 ( V_5 ) != V_498 ) {
V_5 -> V_421 = F_625 ( V_5 ) ;
if ( V_5 -> V_421 == 0 )
V_5 -> V_421 = V_2625 ;
}
if ( F_23 ( V_5 , V_152 ) )
V_5 -> V_164 = V_2626 ;
else
V_5 -> V_164 = V_2627 ;
V_5 -> V_127 = 0 ;
if ( F_147 ( V_5 ) != V_2628 &&
F_147 ( V_5 ) != V_2601 )
V_5 -> V_127 |= V_2629 ;
if ( F_30 ( V_5 ) == V_471 ||
F_30 ( V_5 ) == V_762 ||
F_77 ( V_5 ) == V_1613 ||
F_77 ( V_5 ) == V_1614 ) {
V_5 -> V_127 |= V_2630 ;
V_5 -> V_639 |= V_2631 ;
}
if ( F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1406 )
F_84 ( V_5 , V_266 ) ;
V_75 = F_76 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_7 = F_33 ( V_641 ) ;
if ( F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_762 )
V_7 &= ( V_2632 |
V_2633 |
V_2634 |
V_2635 |
V_1581 ) ;
else
V_7 &= V_1581 ;
F_46 ( V_641 , V_7 | V_5 -> V_639 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
F_46 ( V_13 , 0 ) ;
F_19 ( V_5 -> V_12 , V_1236 ,
& V_2564 ) ;
if ( ( V_2564 & V_2599 ) == 0 &&
! F_23 ( V_5 , V_25 ) ) {
if ( F_77 ( V_5 ) == V_754 ||
F_77 ( V_5 ) == V_755 ||
F_77 ( V_5 ) == V_2619 ||
F_77 ( V_5 ) == V_2636 ) {
void T_2 * V_2637 ;
V_2637 = V_5 -> V_8 + V_2638 + V_37 ;
F_8 ( 0x00000000 , V_2637 ) ;
F_8 ( 0x00000000 , V_2637 + 4 ) ;
F_8 ( 0xffffffff , V_2637 + 4 ) ;
if ( F_10 ( V_2637 ) != 0x00000000 )
F_84 ( V_5 , V_25 ) ;
}
}
F_24 ( 50 ) ;
F_619 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_662 &&
! F_23 ( V_5 , V_676 ) )
V_5 -> V_1886 = NULL ;
V_2559 = F_33 ( V_492 ) ;
V_2559 &= V_2560 ;
if ( F_30 ( V_5 ) == V_496 &&
( V_2559 == V_2639 ||
V_2559 == V_2640 ) )
F_84 ( V_5 , V_1643 ) ;
if ( ! F_23 ( V_5 , V_1643 ) &&
F_30 ( V_5 ) != V_531 )
F_84 ( V_5 , V_133 ) ;
if ( F_23 ( V_5 , V_133 ) ) {
V_5 -> V_127 |= ( V_2641 |
V_2642 ) ;
V_5 -> V_120 |= V_2643 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
}
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_362 = V_725 | V_726 ;
else
V_5 -> V_362 = 0 ;
if ( F_646 ( V_5 , V_2558 ) )
V_5 -> V_178 |= V_387 ;
V_75 = F_627 ( V_5 ) ;
if ( V_75 ) {
F_117 ( & V_5 -> V_12 -> V_111 , L_112 , V_75 ) ;
F_85 ( V_5 ) ;
}
F_629 ( V_5 ) ;
F_640 ( V_5 ) ;
if ( V_5 -> V_178 & V_562 ) {
V_5 -> V_178 &= ~ V_813 ;
} else {
if ( F_30 ( V_5 ) == V_531 )
V_5 -> V_178 |= V_813 ;
else
V_5 -> V_178 &= ~ V_813 ;
}
if ( F_30 ( V_5 ) == V_531 )
F_84 ( V_5 , V_142 ) ;
else
F_86 ( V_5 , V_142 ) ;
if ( V_5 -> V_12 -> V_2371 == V_2415 &&
F_30 ( V_5 ) == V_532 &&
! ( V_5 -> V_178 & V_562 ) ) {
V_5 -> V_178 |= V_813 ;
F_84 ( V_5 , V_142 ) ;
}
if ( V_5 -> V_178 & V_562 )
F_84 ( V_5 , V_143 ) ;
else
F_86 ( V_5 , V_143 ) ;
if ( F_23 ( V_5 , V_60 ) && F_23 ( V_5 , V_303 ) )
F_84 ( V_5 , V_1861 ) ;
V_5 -> V_2644 = V_2645 + V_2646 ;
V_5 -> V_2647 = V_2648 ;
if ( F_30 ( V_5 ) == V_532 &&
F_23 ( V_5 , V_836 ) ) {
V_5 -> V_2644 = V_2645 ;
#ifndef F_655
V_5 -> V_2647 = ~ ( T_3 ) 0 ;
#endif
}
V_5 -> V_1133 = F_467 ( V_5 ) - 1 ;
V_5 -> V_1138 = F_466 ( V_5 ) - 1 ;
V_5 -> V_1201 = F_641 ( V_5 ) - 1 ;
V_5 -> V_1200 = V_5 -> V_1133 + 1 ;
if ( F_30 ( V_5 ) == V_1500 ||
F_30 ( V_5 ) == V_635 ||
F_30 ( V_5 ) == V_1489 )
V_5 -> V_1200 = 8 ;
if ( F_23 ( V_5 , V_969 ) )
V_5 -> V_972 = F_33 ( V_970 ) &
V_971 ;
return V_75 ;
}
static int F_656 ( struct V_4 * V_5 )
{
struct V_359 * V_111 = V_5 -> V_111 ;
struct V_1786 * V_12 = V_5 -> V_12 ;
struct V_2649 * V_2019 = F_657 ( V_12 ) ;
const unsigned char * V_184 ;
int V_74 ;
V_184 = F_658 ( V_2019 , L_113 , & V_74 ) ;
if ( V_184 && V_74 == V_1526 ) {
memcpy ( V_111 -> V_689 , V_184 , V_1526 ) ;
return 0 ;
}
return - V_82 ;
}
static int F_659 ( struct V_4 * V_5 )
{
struct V_359 * V_111 = V_5 -> V_111 ;
memcpy ( V_111 -> V_689 , V_2650 -> V_2651 , V_1526 ) ;
return 0 ;
}
static int F_660 ( struct V_4 * V_5 )
{
struct V_359 * V_111 = V_5 -> V_111 ;
T_1 V_2652 , V_2653 , V_2654 ;
int V_2655 = 0 ;
int V_75 ;
#ifdef F_661
if ( ! F_656 ( V_5 ) )
return 0 ;
#endif
if ( F_23 ( V_5 , V_263 ) ) {
V_75 = F_662 ( V_5 -> V_12 , & V_111 -> V_689 [ 0 ] ) ;
if ( ! V_75 && F_439 ( & V_111 -> V_689 [ 0 ] ) )
return 0 ;
}
V_2654 = 0x7c ;
if ( F_30 ( V_5 ) == V_495 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_33 ( V_915 ) & V_916 )
V_2654 = 0xcc ;
if ( F_159 ( V_5 ) )
F_31 ( V_602 , V_2656 ) ;
else
F_160 ( V_5 ) ;
} else if ( F_23 ( V_5 , 5717_PLUS ) ) {
if ( V_5 -> V_54 & 1 )
V_2654 = 0xcc ;
if ( V_5 -> V_54 > 1 )
V_2654 += 0x18c ;
} else if ( F_30 ( V_5 ) == V_36 )
V_2654 = 0x10 ;
F_32 ( V_5 , V_2657 , & V_2652 ) ;
if ( ( V_2652 >> 16 ) == 0x484b ) {
V_111 -> V_689 [ 0 ] = ( V_2652 >> 8 ) & 0xff ;
V_111 -> V_689 [ 1 ] = ( V_2652 >> 0 ) & 0xff ;
F_32 ( V_5 , V_2658 , & V_2653 ) ;
V_111 -> V_689 [ 2 ] = ( V_2653 >> 24 ) & 0xff ;
V_111 -> V_689 [ 3 ] = ( V_2653 >> 16 ) & 0xff ;
V_111 -> V_689 [ 4 ] = ( V_2653 >> 8 ) & 0xff ;
V_111 -> V_689 [ 5 ] = ( V_2653 >> 0 ) & 0xff ;
V_2655 = F_439 ( & V_111 -> V_689 [ 0 ] ) ;
}
if ( ! V_2655 ) {
if ( ! F_23 ( V_5 , V_676 ) &&
! F_171 ( V_5 , V_2654 + 0 , & V_2652 ) &&
! F_171 ( V_5 , V_2654 + 4 , & V_2653 ) ) {
memcpy ( & V_111 -> V_689 [ 0 ] , ( ( char * ) & V_2652 ) + 2 , 2 ) ;
memcpy ( & V_111 -> V_689 [ 2 ] , ( char * ) & V_2653 , sizeof( V_2653 ) ) ;
}
else {
V_2652 = F_33 ( V_684 ) ;
V_2653 = F_33 ( V_685 ) ;
V_111 -> V_689 [ 5 ] = V_2653 & 0xff ;
V_111 -> V_689 [ 4 ] = ( V_2653 >> 8 ) & 0xff ;
V_111 -> V_689 [ 3 ] = ( V_2653 >> 16 ) & 0xff ;
V_111 -> V_689 [ 2 ] = ( V_2653 >> 24 ) & 0xff ;
V_111 -> V_689 [ 1 ] = V_2652 & 0xff ;
V_111 -> V_689 [ 0 ] = ( V_2652 >> 8 ) & 0xff ;
}
}
if ( ! F_439 ( & V_111 -> V_689 [ 0 ] ) ) {
#ifdef F_661
if ( ! F_659 ( V_5 ) )
return 0 ;
#endif
return - V_64 ;
}
return 0 ;
}
static T_1 F_663 ( struct V_4 * V_5 , T_1 V_7 )
{
int V_2659 ;
T_4 V_2660 ;
int V_2661 ;
F_652 ( V_5 -> V_12 , V_1387 , & V_2660 ) ;
if ( V_2660 == 0 )
V_2659 = 1024 ;
else
V_2659 = ( int ) V_2660 * 4 ;
if ( F_30 ( V_5 ) != V_531 &&
F_30 ( V_5 ) != V_532 &&
! F_23 ( V_5 , V_1074 ) )
goto V_497;
#if F_362 ( V_2662 ) || F_362 ( V_2663 ) || F_362 ( V_2664 )
V_2661 = V_2665 ;
#else
#if F_362 ( V_2666 ) || F_362 ( V_2667 )
V_2661 = V_2668 ;
#else
V_2661 = 0 ;
#endif
#endif
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = V_2661 ? 0 : V_1572 ;
goto V_497;
}
if ( ! V_2661 )
goto V_497;
if ( F_23 ( V_5 , V_836 ) && ! F_23 ( V_5 , V_1074 ) ) {
switch ( V_2659 ) {
case 16 :
case 32 :
case 64 :
case 128 :
if ( V_2661 == V_2668 ) {
V_7 |= ( V_2669 |
V_2670 ) ;
} else {
V_7 |= ( V_2671 |
V_2672 ) ;
}
break;
case 256 :
V_7 |= ( V_2673 |
V_2674 ) ;
break;
default:
V_7 |= ( V_2671 |
V_2672 ) ;
break;
}
} else if ( F_23 ( V_5 , V_1074 ) ) {
switch ( V_2659 ) {
case 16 :
case 32 :
case 64 :
if ( V_2661 == V_2668 ) {
V_7 &= ~ V_2675 ;
V_7 |= V_2676 ;
break;
}
case 128 :
default:
V_7 &= ~ V_2675 ;
V_7 |= V_2677 ;
break;
}
} else {
switch ( V_2659 ) {
case 16 :
if ( V_2661 == V_2668 ) {
V_7 |= ( V_2678 |
V_2679 ) ;
break;
}
case 32 :
if ( V_2661 == V_2668 ) {
V_7 |= ( V_2680 |
V_2681 ) ;
break;
}
case 64 :
if ( V_2661 == V_2668 ) {
V_7 |= ( V_2682 |
V_2683 ) ;
break;
}
case 128 :
if ( V_2661 == V_2668 ) {
V_7 |= ( V_2684 |
V_2685 ) ;
break;
}
case 256 :
V_7 |= ( V_2686 |
V_2687 ) ;
break;
case 512 :
V_7 |= ( V_2688 |
V_2689 ) ;
break;
case 1024 :
default:
V_7 |= ( V_2690 |
V_2691 ) ;
break;
}
}
V_497:
return V_7 ;
}
static int F_664 ( struct V_4 * V_5 , T_1 * V_621 , T_9 V_2692 ,
int V_629 , bool V_2693 )
{
struct V_2694 V_2695 ;
T_1 V_2696 ;
int V_42 , V_56 ;
V_2696 = V_1592 ;
F_46 ( V_2697 , 0 ) ;
F_46 ( V_2698 , 0 ) ;
F_46 ( V_1227 , 0 ) ;
F_46 ( V_1228 , 0 ) ;
F_46 ( V_1059 , 0 ) ;
F_46 ( V_1069 , 0 ) ;
V_2695 . V_1143 = ( ( T_6 ) V_2692 ) >> 32 ;
V_2695 . V_1144 = V_2692 & 0xffffffff ;
V_2695 . V_2699 = 0x00002100 ;
V_2695 . V_74 = V_629 ;
if ( V_2693 ) {
V_2695 . V_2700 = ( 13 << 8 ) | 2 ;
F_31 ( V_1060 , V_1371 ) ;
F_24 ( 40 ) ;
} else {
V_2695 . V_2700 = ( 16 << 8 ) | 7 ;
F_31 ( V_1061 , V_1375 ) ;
F_24 ( 40 ) ;
}
V_2695 . V_10 = 0x00000005 ;
for ( V_42 = 0 ; V_42 < ( sizeof( V_2695 ) / sizeof( T_1 ) ) ; V_42 ++ ) {
T_1 V_7 ;
V_7 = * ( ( ( T_1 * ) & V_2695 ) + V_42 ) ;
F_15 ( V_5 -> V_12 , V_40 ,
V_2696 + ( V_42 * sizeof( T_1 ) ) ) ;
F_15 ( V_5 -> V_12 , V_41 , V_7 ) ;
}
F_15 ( V_5 -> V_12 , V_40 , 0 ) ;
if ( V_2693 )
F_46 ( V_2701 , V_2696 ) ;
else
F_46 ( V_2702 , V_2696 ) ;
V_56 = - V_82 ;
for ( V_42 = 0 ; V_42 < 40 ; V_42 ++ ) {
T_1 V_7 ;
if ( V_2693 )
V_7 = F_33 ( V_2697 ) ;
else
V_7 = F_33 ( V_2698 ) ;
if ( ( V_7 & 0xffff ) == V_2696 ) {
V_56 = 0 ;
break;
}
F_24 ( 100 ) ;
}
return V_56 ;
}
static int F_665 ( struct V_4 * V_5 )
{
T_9 V_2692 ;
T_1 * V_621 , V_2703 ;
int V_56 = 0 ;
V_621 = F_410 ( & V_5 -> V_12 -> V_111 , V_2704 ,
& V_2692 , V_627 ) ;
if ( ! V_621 ) {
V_56 = - V_267 ;
goto V_2705;
}
V_5 -> V_1575 = ( ( 0x7 << V_2706 ) |
( 0x6 << V_2707 ) ) ;
V_5 -> V_1575 = F_663 ( V_5 , V_5 -> V_1575 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
goto V_497;
if ( F_23 ( V_5 , V_1074 ) ) {
V_5 -> V_1575 |= 0x00180000 ;
} else if ( ! F_23 ( V_5 , V_836 ) ) {
if ( F_30 ( V_5 ) == V_496 ||
F_30 ( V_5 ) == V_1500 )
V_5 -> V_1575 |= 0x003f0000 ;
else
V_5 -> V_1575 |= 0x003f000f ;
} else {
if ( F_30 ( V_5 ) == V_494 ||
F_30 ( V_5 ) == V_495 ) {
T_1 V_2708 = ( F_33 ( V_153 ) & 0x1f ) ;
T_1 V_2709 = 0x7 ;
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) &&
F_30 ( V_5 ) == V_495 )
V_5 -> V_1575 |= 0x8000 ;
else if ( V_2708 == 0x6 || V_2708 == 0x7 )
V_5 -> V_1575 |= V_2710 ;
if ( F_30 ( V_5 ) == V_494 )
V_2709 = 4 ;
V_5 -> V_1575 |=
( V_2709 << V_2711 ) |
( 0x3 << V_2712 ) |
( 1 << 23 ) ;
} else if ( F_30 ( V_5 ) == V_561 ) {
V_5 -> V_1575 |= 0x00144000 ;
} else if ( F_30 ( V_5 ) == V_543 ) {
V_5 -> V_1575 |= 0x00148000 ;
} else {
V_5 -> V_1575 |= 0x001b000f ;
}
}
if ( F_23 ( V_5 , V_2713 ) )
V_5 -> V_1575 |= V_2710 ;
if ( F_30 ( V_5 ) == V_494 ||
F_30 ( V_5 ) == V_495 )
V_5 -> V_1575 &= 0xfffffff0 ;
if ( F_30 ( V_5 ) == V_531 ||
F_30 ( V_5 ) == V_532 ) {
V_5 -> V_1575 |= V_2714 ;
V_5 -> V_1575 |= V_2715 ;
}
F_46 ( V_1571 , V_5 -> V_1575 ) ;
if ( F_30 ( V_5 ) != V_531 &&
F_30 ( V_5 ) != V_532 )
goto V_497;
V_2703 = V_5 -> V_1575 ;
V_5 -> V_1575 &= ~ V_2716 ;
F_46 ( V_1571 , V_5 -> V_1575 ) ;
while ( 1 ) {
T_1 * V_1441 = V_621 , V_42 ;
for ( V_42 = 0 ; V_42 < V_2704 / sizeof( T_1 ) ; V_42 ++ )
V_1441 [ V_42 ] = V_42 ;
V_56 = F_664 ( V_5 , V_621 , V_2692 , V_2704 , true ) ;
if ( V_56 ) {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_114 ,
V_652 , V_56 ) ;
break;
}
V_56 = F_664 ( V_5 , V_621 , V_2692 , V_2704 , false ) ;
if ( V_56 ) {
F_117 ( & V_5 -> V_12 -> V_111 , L_115
L_116 , V_652 , V_56 ) ;
break;
}
for ( V_42 = 0 ; V_42 < V_2704 / sizeof( T_1 ) ; V_42 ++ ) {
if ( V_1441 [ V_42 ] == V_42 )
continue;
if ( ( V_5 -> V_1575 & V_2716 ) !=
V_2679 ) {
V_5 -> V_1575 &= ~ V_2716 ;
V_5 -> V_1575 |= V_2679 ;
F_46 ( V_1571 , V_5 -> V_1575 ) ;
break;
} else {
F_117 ( & V_5 -> V_12 -> V_111 ,
L_117
L_118 , V_652 , V_1441 [ V_42 ] , V_42 ) ;
V_56 = - V_82 ;
goto V_497;
}
}
if ( V_42 == ( V_2704 / sizeof( T_1 ) ) ) {
V_56 = 0 ;
break;
}
}
if ( ( V_5 -> V_1575 & V_2716 ) !=
V_2679 ) {
if ( F_651 ( V_2717 ) ) {
V_5 -> V_1575 &= ~ V_2716 ;
V_5 -> V_1575 |= V_2679 ;
} else {
V_5 -> V_1575 = V_2703 ;
}
F_46 ( V_1571 , V_5 -> V_1575 ) ;
}
V_497:
F_408 ( & V_5 -> V_12 -> V_111 , V_2704 , V_621 , V_2692 ) ;
V_2705:
return V_56 ;
}
static void F_666 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_5 -> V_1598 . V_1599 =
V_2718 ;
V_5 -> V_1598 . V_1601 =
V_2719 ;
V_5 -> V_1598 . V_1603 =
V_2720 ;
V_5 -> V_1598 . V_1604 =
V_2718 ;
V_5 -> V_1598 . V_1605 =
V_2721 ;
V_5 -> V_1598 . V_1606 =
V_2722 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_5 -> V_1598 . V_1599 =
V_2718 ;
V_5 -> V_1598 . V_1601 =
V_2723 ;
V_5 -> V_1598 . V_1603 =
V_2724 ;
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_1598 . V_1601 =
V_2725 ;
V_5 -> V_1598 . V_1603 =
V_2726 ;
}
V_5 -> V_1598 . V_1604 =
V_2727 ;
V_5 -> V_1598 . V_1605 =
V_2728 ;
V_5 -> V_1598 . V_1606 =
V_2729 ;
} else {
V_5 -> V_1598 . V_1599 =
V_2730 ;
V_5 -> V_1598 . V_1601 =
V_2731 ;
V_5 -> V_1598 . V_1603 =
V_2732 ;
V_5 -> V_1598 . V_1604 =
V_2733 ;
V_5 -> V_1598 . V_1605 =
V_2734 ;
V_5 -> V_1598 . V_1606 =
V_2735 ;
}
V_5 -> V_1598 . V_1608 = V_2736 ;
V_5 -> V_1598 . V_1610 = V_2737 ;
}
static char * F_667 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_215 & V_395 ) {
case V_2738 : return L_119 ;
case V_396 : return L_120 ;
case V_560 : return L_121 ;
case V_2739 : return L_122 ;
case V_2740 : return L_123 ;
case V_2741 : return L_124 ;
case V_2742 : return L_125 ;
case V_2743 : return L_126 ;
case V_2744 : return L_127 ;
case V_2745 : return L_128 ;
case V_2746 : return L_129 ;
case V_2747 : return L_130 ;
case V_2748 : return L_131 ;
case V_2749 : return L_132 ;
case V_2750 : return L_133 ;
case V_2751 : return L_134 ;
case V_2752 : return L_135 ;
case V_2753 : return L_136 ;
case V_2754 : return L_137 ;
case V_2755 : return L_138 ;
case V_2756 : return L_139 ;
case V_2757 : return L_140 ;
case V_2758 : return L_141 ;
case V_936 : return L_142 ;
case 0 : return L_143 ;
default: return L_144 ;
}
}
static char * F_668 ( struct V_4 * V_5 , char * V_2759 )
{
if ( F_23 ( V_5 , V_1074 ) ) {
strcpy ( V_2759 , L_145 ) ;
return V_2759 ;
} else if ( F_23 ( V_5 , V_836 ) ) {
T_1 V_150 = F_33 ( V_153 ) & 0x1f ;
strcpy ( V_2759 , L_146 ) ;
if ( ( V_150 == 7 ) ||
( ( F_33 ( V_492 ) & V_2560 ) ==
V_2760 ) )
strcat ( V_2759 , L_147 ) ;
else if ( V_150 == 0 )
strcat ( V_2759 , L_148 ) ;
else if ( V_150 == 2 )
strcat ( V_2759 , L_149 ) ;
else if ( V_150 == 4 )
strcat ( V_2759 , L_150 ) ;
else if ( V_150 == 6 )
strcat ( V_2759 , L_151 ) ;
} else {
strcpy ( V_2759 , L_152 ) ;
if ( F_23 ( V_5 , V_837 ) )
strcat ( V_2759 , L_150 ) ;
else
strcat ( V_2759 , L_148 ) ;
}
if ( F_23 ( V_5 , V_2609 ) )
strcat ( V_2759 , L_153 ) ;
else
strcat ( V_2759 , L_154 ) ;
return V_2759 ;
}
static void F_669 ( struct V_4 * V_5 )
{
struct V_1459 * V_1460 = & V_5 -> V_967 ;
memset ( V_1460 , 0 , sizeof( * V_1460 ) ) ;
V_1460 -> V_637 = V_2761 ;
V_1460 -> V_1471 = V_2762 ;
V_1460 -> V_1462 = V_2763 ;
V_1460 -> V_1473 = V_2764 ;
V_1460 -> V_1464 = V_2765 ;
V_1460 -> V_1479 = V_2766 ;
V_1460 -> V_1481 = V_2767 ;
V_1460 -> V_1475 = V_2768 ;
V_1460 -> V_1466 = V_2769 ;
V_1460 -> V_968 = V_2770 ;
if ( V_5 -> V_127 & ( V_2641 |
V_2642 ) ) {
V_1460 -> V_1471 = V_2771 ;
V_1460 -> V_1479 = V_2772 ;
V_1460 -> V_1462 = V_2773 ;
V_1460 -> V_1481 = V_2774 ;
}
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_1460 -> V_1479 = 0 ;
V_1460 -> V_1481 = 0 ;
V_1460 -> V_968 = 0 ;
}
}
static int F_670 ( struct V_1786 * V_12 ,
const struct V_2557 * V_2558 )
{
struct V_359 * V_111 ;
struct V_4 * V_5 ;
int V_42 , V_75 ;
T_1 V_2775 , V_2776 , V_2777 ;
char V_2759 [ 40 ] ;
T_6 V_2778 , V_2779 ;
T_15 V_1184 = 0 ;
F_671 ( V_2780 L_155 , V_1969 ) ;
V_75 = F_672 ( V_12 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_156 ) ;
return V_75 ;
}
V_75 = F_673 ( V_12 , V_2009 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_157 ) ;
goto V_2781;
}
F_674 ( V_12 ) ;
V_111 = F_675 ( sizeof( * V_5 ) , V_1890 ) ;
if ( ! V_111 ) {
V_75 = - V_267 ;
goto V_2782;
}
F_676 ( V_111 , & V_12 -> V_111 ) ;
V_5 = F_111 ( V_111 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_111 = V_111 ;
V_5 -> V_349 = V_2783 ;
V_5 -> V_351 = V_2784 ;
V_5 -> V_125 = 1 ;
V_5 -> V_1906 = false ;
if ( V_2785 > 0 )
V_5 -> V_2020 = V_2785 ;
else
V_5 -> V_2020 = V_2786 ;
if ( F_677 ( V_12 ) ) {
F_84 ( V_5 , V_263 ) ;
if ( F_678 ( V_12 ) )
F_84 ( V_5 , V_30 ) ;
if ( F_679 ( V_12 ) )
F_84 ( V_5 , V_2713 ) ;
if ( F_680 ( V_12 ) ) {
F_84 ( V_5 , V_266 ) ;
F_84 ( V_5 , V_264 ) ;
}
if ( F_681 ( V_12 ) )
F_84 ( V_5 , V_830 ) ;
}
V_5 -> V_120 =
V_121 |
V_2787 |
V_2788 |
V_2789 ;
V_5 -> V_639 = ( V_2790 | V_2791 |
V_2792 ) ;
#ifdef F_682
V_5 -> V_639 |= V_2793 ;
#endif
F_683 ( & V_5 -> V_209 ) ;
F_683 ( & V_5 -> V_11 ) ;
F_684 ( & V_5 -> V_1217 , F_491 ) ;
V_5 -> V_8 = F_685 ( V_12 , V_2794 ) ;
if ( ! V_5 -> V_8 ) {
F_117 ( & V_12 -> V_111 , L_158 ) ;
V_75 = - V_267 ;
goto V_2795;
}
if ( V_5 -> V_12 -> V_538 == V_539 ||
V_5 -> V_12 -> V_538 == V_2796 ||
V_5 -> V_12 -> V_538 == V_540 ||
V_5 -> V_12 -> V_538 == V_2797 ||
V_5 -> V_12 -> V_538 == V_2472 ||
V_5 -> V_12 -> V_538 == V_2473 ||
V_5 -> V_12 -> V_538 == V_2474 ||
V_5 -> V_12 -> V_538 == V_2544 ||
V_5 -> V_12 -> V_538 == V_2545 ||
V_5 -> V_12 -> V_538 == V_2546 ||
V_5 -> V_12 -> V_538 == V_2547 ||
V_5 -> V_12 -> V_538 == V_2548 ||
V_5 -> V_12 -> V_538 == V_2523 ||
V_5 -> V_12 -> V_538 == V_2549 ||
V_5 -> V_12 -> V_538 == V_2550 ) {
F_84 ( V_5 , V_60 ) ;
V_5 -> V_9 = F_685 ( V_12 , V_2798 ) ;
if ( ! V_5 -> V_9 ) {
F_117 ( & V_12 -> V_111 ,
L_159 ) ;
V_75 = - V_267 ;
goto V_2799;
}
}
V_5 -> V_1338 = V_2800 ;
V_5 -> V_1342 = V_2801 ;
V_111 -> V_2802 = & V_2803 ;
V_111 -> V_2804 = V_2805 ;
V_111 -> V_2806 = & V_2807 ;
V_111 -> V_1231 = V_12 -> V_1231 ;
V_75 = F_647 ( V_5 , V_2558 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 ,
L_160 ) ;
goto V_2808;
}
if ( F_23 ( V_5 , V_1643 ) )
V_2779 = V_2778 = F_363 ( 32 ) ;
else if ( F_23 ( V_5 , 40BIT_DMA_BUG ) ) {
V_2779 = V_2778 = F_363 ( 40 ) ;
#ifdef V_1240
V_2778 = F_363 ( 64 ) ;
#endif
} else
V_2779 = V_2778 = F_363 ( 64 ) ;
if ( V_2778 > F_363 ( 32 ) ) {
V_75 = F_686 ( V_12 , V_2778 ) ;
if ( ! V_75 ) {
V_1184 |= V_2809 ;
V_75 = F_687 ( V_12 ,
V_2779 ) ;
if ( V_75 < 0 ) {
F_117 ( & V_12 -> V_111 , L_161
L_162 ) ;
goto V_2808;
}
}
}
if ( V_75 || V_2778 == F_363 ( 32 ) ) {
V_75 = F_686 ( V_12 , F_363 ( 32 ) ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 ,
L_163 ) ;
goto V_2808;
}
}
F_666 ( V_5 ) ;
if ( F_77 ( V_5 ) != V_2810 ) {
V_1184 |= V_2811 | V_2812 | V_1185 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_1184 |= V_2813 ;
}
if ( ( F_23 ( V_5 , V_1293 ) ||
F_23 ( V_5 , V_1294 ) ||
F_23 ( V_5 , V_1295 ) ) &&
( V_1184 & V_2812 ) )
V_1184 |= V_1271 ;
if ( F_23 ( V_5 , V_1294 ) || F_23 ( V_5 , V_1295 ) ) {
if ( V_1184 & V_2813 )
V_1184 |= V_1272 ;
if ( F_23 ( V_5 , V_1295 ) ||
F_30 ( V_5 ) == V_45 ||
( F_30 ( V_5 ) == V_408 &&
F_147 ( V_5 ) != V_498 ) ||
F_30 ( V_5 ) == V_256 ||
F_30 ( V_5 ) == V_1406 )
V_1184 |= V_2814 ;
}
V_111 -> V_1184 |= V_1184 | V_2815 |
V_2816 ;
V_111 -> V_2817 |= V_1184 ;
if ( F_30 ( V_5 ) != V_561 &&
! F_23 ( V_5 , V_152 ) )
V_1184 |= V_1327 ;
V_111 -> V_2818 |= V_1184 ;
V_111 -> V_2819 |= V_2820 ;
V_111 -> V_2821 = V_2822 ;
V_111 -> V_2823 = F_468 ( V_5 ) ;
if ( F_77 ( V_5 ) == V_1699 &&
! F_23 ( V_5 , V_1595 ) &&
! ( F_33 ( V_1236 ) & V_1642 ) ) {
F_84 ( V_5 , V_2028 ) ;
V_5 -> V_1338 = 63 ;
}
V_75 = F_660 ( V_5 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 ,
L_164 ) ;
goto V_2808;
}
V_2777 = V_20 + V_16 ;
V_2776 = V_15 + V_16 ;
V_2775 = V_2824 + V_16 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_131 -> V_5 = V_5 ;
V_131 -> V_1083 = V_2825 ;
V_131 -> V_124 = V_2777 ;
if ( V_42 <= 4 )
V_2777 += 0x8 ;
else
V_2777 += 0x4 ;
V_131 -> V_1202 = V_2776 ;
V_131 -> V_1317 = V_2775 ;
if ( V_42 )
V_131 -> V_126 = V_2826 << ( V_42 - 1 ) ;
else
V_131 -> V_126 = V_1855 ;
if ( ! F_23 ( V_5 , V_1056 ) )
break;
if ( ! V_42 )
continue;
V_2776 += 0x8 ;
if ( V_2775 & 0x4 )
V_2775 -= 0x4 ;
else
V_2775 += 0xc ;
}
if ( ( F_33 ( V_138 ) & V_128 ) ||
( F_33 ( V_1061 ) & V_1375 ) ) {
F_243 ( V_5 , 0 ) ;
F_46 ( V_1058 , V_1378 ) ;
F_435 ( V_5 , V_110 , 1 ) ;
F_244 ( V_5 ) ;
}
V_75 = F_665 ( V_5 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_165 ) ;
goto V_2808;
}
F_669 ( V_5 ) ;
F_688 ( V_12 , V_111 ) ;
if ( F_30 ( V_5 ) == V_472 ||
F_30 ( V_5 ) == V_528 ||
F_30 ( V_5 ) == V_762 )
F_84 ( V_5 , V_987 ) ;
F_484 ( V_5 ) ;
F_141 ( V_5 ) ;
V_75 = F_689 ( V_111 ) ;
if ( V_75 ) {
F_117 ( & V_12 -> V_111 , L_166 ) ;
goto V_2808;
}
if ( F_23 ( V_5 , V_987 ) ) {
F_253 ( V_5 ) ;
V_5 -> V_991 = F_690 ( & V_5 -> V_1004 ,
& V_5 -> V_12 -> V_111 ) ;
if ( F_116 ( V_5 -> V_991 ) )
V_5 -> V_991 = NULL ;
}
F_98 ( V_111 , L_167 ,
V_5 -> V_2471 ,
F_77 ( V_5 ) ,
F_668 ( V_5 , V_2759 ) ,
V_111 -> V_689 ) ;
if ( ! ( V_5 -> V_178 & V_386 ) ) {
char * V_2827 ;
if ( V_5 -> V_178 & V_387 )
V_2827 = L_168 ;
else if ( V_5 -> V_178 & V_354 )
V_2827 = L_169 ;
else
V_2827 = L_170 ;
F_98 ( V_111 , L_171
L_172 ,
F_667 ( V_5 ) , V_2827 ,
( V_5 -> V_178 & V_418 ) == 0 ,
( V_5 -> V_178 & V_333 ) != 0 ) ;
}
F_98 ( V_111 , L_173 ,
( V_111 -> V_1184 & V_1185 ) != 0 ,
F_23 ( V_5 , V_142 ) != 0 ,
( V_5 -> V_178 & V_813 ) != 0 ,
F_23 ( V_5 , V_303 ) != 0 ,
F_23 ( V_5 , V_1595 ) != 0 ) ;
F_98 ( V_111 , L_174 ,
V_5 -> V_1575 ,
V_12 -> V_2778 == F_363 ( 32 ) ? 32 :
( ( T_6 ) V_12 -> V_2778 ) == F_363 ( 40 ) ? 40 : 64 ) ;
F_691 ( V_12 ) ;
return 0 ;
V_2808:
if ( V_5 -> V_9 ) {
F_653 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
V_2799:
if ( V_5 -> V_8 ) {
F_653 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
V_2795:
F_692 ( V_111 ) ;
V_2782:
F_693 ( V_12 ) ;
V_2781:
if ( F_694 ( V_12 ) )
F_695 ( V_12 ) ;
return V_75 ;
}
static void F_696 ( struct V_1786 * V_12 )
{
struct V_359 * V_111 = F_154 ( V_12 ) ;
if ( V_111 ) {
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_257 ( V_5 ) ;
F_503 ( V_5 -> V_657 ) ;
F_327 ( V_5 ) ;
if ( F_23 ( V_5 , V_266 ) ) {
F_126 ( V_5 ) ;
F_85 ( V_5 ) ;
}
F_697 ( V_111 ) ;
if ( V_5 -> V_9 ) {
F_653 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
if ( V_5 -> V_8 ) {
F_653 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
F_692 ( V_111 ) ;
F_693 ( V_12 ) ;
F_695 ( V_12 ) ;
}
}
static int F_698 ( struct V_538 * V_538 )
{
struct V_1786 * V_12 = F_699 ( V_538 ) ;
struct V_359 * V_111 = F_154 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 = 0 ;
F_492 () ;
if ( ! F_146 ( V_111 ) )
goto V_2828;
F_327 ( V_5 ) ;
F_124 ( V_5 ) ;
F_343 ( V_5 ) ;
F_487 ( V_5 ) ;
F_243 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_244 ( V_5 ) ;
F_700 ( V_111 ) ;
F_243 ( V_5 , 0 ) ;
F_435 ( V_5 , V_110 , 1 ) ;
F_86 ( V_5 , V_557 ) ;
F_244 ( V_5 ) ;
V_75 = F_201 ( V_5 ) ;
if ( V_75 ) {
int V_756 ;
F_243 ( V_5 , 0 ) ;
F_84 ( V_5 , V_557 ) ;
V_756 = F_489 ( V_5 , true ) ;
if ( V_756 )
goto V_497;
F_486 ( V_5 ) ;
F_701 ( V_111 ) ;
F_346 ( V_5 ) ;
V_497:
F_244 ( V_5 ) ;
if ( ! V_756 )
F_121 ( V_5 ) ;
}
V_2828:
F_493 () ;
return V_75 ;
}
static int F_702 ( struct V_538 * V_538 )
{
struct V_1786 * V_12 = F_699 ( V_538 ) ;
struct V_359 * V_111 = F_154 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
int V_75 = 0 ;
F_492 () ;
if ( ! F_146 ( V_111 ) )
goto V_2828;
F_701 ( V_111 ) ;
F_243 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_84 ( V_5 , V_557 ) ;
V_75 = F_489 ( V_5 ,
! ( V_5 -> V_178 & V_564 ) ) ;
if ( V_75 )
goto V_497;
F_486 ( V_5 ) ;
F_346 ( V_5 ) ;
V_497:
F_244 ( V_5 ) ;
if ( ! V_75 )
F_121 ( V_5 ) ;
V_2828:
F_493 () ;
return V_75 ;
}
static void F_703 ( struct V_1786 * V_12 )
{
struct V_359 * V_111 = F_154 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_111 ) ;
F_492 () ;
F_700 ( V_111 ) ;
if ( F_146 ( V_111 ) )
F_490 ( V_111 ) ;
if ( V_2829 == V_2830 )
F_204 ( V_5 ) ;
F_493 () ;
}
static T_21 F_704 ( struct V_1786 * V_12 ,
T_22 V_843 )
{
struct V_359 * V_2831 = F_154 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_2831 ) ;
T_21 V_75 = V_2832 ;
F_98 ( V_2831 , L_175 ) ;
F_492 () ;
if ( ! V_2831 || ! F_146 ( V_2831 ) )
goto V_186;
if ( V_843 == V_2833 )
V_5 -> V_1906 = true ;
F_124 ( V_5 ) ;
F_343 ( V_5 ) ;
F_487 ( V_5 ) ;
F_327 ( V_5 ) ;
F_700 ( V_2831 ) ;
F_243 ( V_5 , 0 ) ;
F_435 ( V_5 , V_110 , 0 ) ;
F_244 ( V_5 ) ;
V_186:
if ( V_843 == V_2834 ) {
if ( V_2831 ) {
F_337 ( V_5 ) ;
F_490 ( V_2831 ) ;
}
V_75 = V_2835 ;
} else {
F_695 ( V_12 ) ;
}
F_493 () ;
return V_75 ;
}
static T_21 F_705 ( struct V_1786 * V_12 )
{
struct V_359 * V_2831 = F_154 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_2831 ) ;
T_21 V_623 = V_2835 ;
int V_75 ;
F_492 () ;
if ( F_672 ( V_12 ) ) {
F_117 ( & V_12 -> V_111 ,
L_176 ) ;
goto V_186;
}
F_674 ( V_12 ) ;
F_706 ( V_12 ) ;
F_691 ( V_12 ) ;
if ( ! V_2831 || ! F_146 ( V_2831 ) ) {
V_623 = V_2836 ;
goto V_186;
}
V_75 = F_199 ( V_5 ) ;
if ( V_75 )
goto V_186;
V_623 = V_2836 ;
V_186:
if ( V_623 != V_2836 && V_2831 && F_146 ( V_2831 ) ) {
F_337 ( V_5 ) ;
F_490 ( V_2831 ) ;
}
F_493 () ;
return V_623 ;
}
static void F_707 ( struct V_1786 * V_12 )
{
struct V_359 * V_2831 = F_154 ( V_12 ) ;
struct V_4 * V_5 = F_111 ( V_2831 ) ;
int V_75 ;
F_492 () ;
if ( ! V_2831 || ! F_146 ( V_2831 ) )
goto V_186;
F_243 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_84 ( V_5 , V_557 ) ;
V_75 = F_489 ( V_5 , true ) ;
if ( V_75 ) {
F_244 ( V_5 ) ;
F_187 ( V_2831 , L_177 ) ;
goto V_186;
}
F_701 ( V_2831 ) ;
F_486 ( V_5 ) ;
F_346 ( V_5 ) ;
F_244 ( V_5 ) ;
F_121 ( V_5 ) ;
V_186:
V_5 -> V_1906 = false ;
F_493 () ;
}
