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
static void F_74 ( struct V_4 * V_5 )
{
V_5 -> V_164 &= ~ V_165 ;
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
if ( F_23 ( V_5 , V_256 ) &&
F_30 ( V_5 ) == V_257 )
F_73 ( V_5 ) ;
}
static int F_75 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_161 ;
struct V_211 * V_212 ;
if ( F_23 ( V_5 , 5717_PLUS ) ) {
T_1 V_258 ;
V_5 -> V_160 = V_5 -> V_54 + 1 ;
if ( F_76 ( V_5 ) != V_259 )
V_258 = F_33 ( V_260 ) & V_261 ;
else
V_258 = F_33 ( V_262 ) &
V_263 ;
if ( V_258 )
V_5 -> V_160 += 7 ;
} else if ( F_23 ( V_5 , V_264 ) && F_23 ( V_5 , V_265 ) ) {
int V_184 ;
V_184 = F_77 ( V_5 -> V_12 ) ;
if ( V_184 < 0 )
return V_184 ;
V_5 -> V_160 = V_184 ;
} else
V_5 -> V_160 = V_266 ;
F_74 ( V_5 ) ;
if ( ! F_23 ( V_5 , V_267 ) || F_23 ( V_5 , V_256 ) )
return 0 ;
V_5 -> V_213 = F_78 () ;
if ( V_5 -> V_213 == NULL )
return - V_268 ;
V_5 -> V_213 -> V_269 = L_1 ;
snprintf ( V_5 -> V_213 -> V_270 , V_271 , L_2 ,
( V_5 -> V_12 -> V_272 -> V_273 << 8 ) | V_5 -> V_12 -> V_274 ) ;
V_5 -> V_213 -> V_208 = V_5 ;
V_5 -> V_213 -> V_275 = & V_5 -> V_12 -> V_111 ;
V_5 -> V_213 -> V_276 = & F_69 ;
V_5 -> V_213 -> V_277 = & F_72 ;
V_5 -> V_213 -> V_278 = ~ ( 1 << V_5 -> V_160 ) ;
V_5 -> V_213 -> V_279 = & V_5 -> V_280 [ 0 ] ;
for ( V_42 = 0 ; V_42 < V_281 ; V_42 ++ )
V_5 -> V_213 -> V_279 [ V_42 ] = V_282 ;
if ( F_57 ( V_5 , V_204 , & V_161 ) || ( V_161 & V_283 ) )
F_68 ( V_5 ) ;
V_42 = F_79 ( V_5 -> V_213 ) ;
if ( V_42 ) {
F_80 ( & V_5 -> V_12 -> V_111 , L_3 , V_42 ) ;
F_81 ( V_5 -> V_213 ) ;
return V_42 ;
}
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
if ( ! V_212 || ! V_212 -> V_215 ) {
F_80 ( & V_5 -> V_12 -> V_111 , L_4 ) ;
F_82 ( V_5 -> V_213 ) ;
F_81 ( V_5 -> V_213 ) ;
return - V_82 ;
}
switch ( V_212 -> V_215 -> V_216 & V_212 -> V_215 -> V_217 ) {
case V_284 :
V_212 -> V_227 = V_285 ;
V_212 -> V_286 |= V_287 ;
break;
case V_218 :
case V_219 :
V_212 -> V_286 |= V_288 |
V_289 |
V_290 |
V_287 ;
if ( F_23 ( V_5 , V_236 ) )
V_212 -> V_286 |= V_291 ;
if ( F_23 ( V_5 , V_245 ) )
V_212 -> V_286 |= V_292 ;
if ( F_23 ( V_5 , V_246 ) )
V_212 -> V_286 |= V_293 ;
case V_223 :
V_212 -> V_227 = V_228 ;
break;
case V_225 :
case V_221 :
V_212 -> V_227 = V_294 ;
V_212 -> V_286 |= V_287 ;
V_5 -> V_178 |= V_179 ;
break;
}
F_83 ( V_5 , V_256 ) ;
if ( F_30 ( V_5 ) == V_257 )
F_73 ( V_5 ) ;
return 0 ;
}
static void F_84 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_256 ) ) {
F_85 ( V_5 , V_256 ) ;
F_82 ( V_5 -> V_213 ) ;
F_81 ( V_5 -> V_213 ) ;
}
}
static inline void F_86 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_7 = F_33 ( V_295 ) ;
V_7 |= V_296 ;
F_31 ( V_295 , V_7 ) ;
V_5 -> V_297 = V_298 ;
}
static void F_87 ( struct V_4 * V_5 )
{
int V_42 ;
unsigned int V_299 ;
long V_300 ;
V_300 = ( long ) ( V_5 -> V_297 + 1 +
F_88 ( V_301 ) ) -
( long ) V_298 ;
if ( V_300 < 0 )
return;
V_299 = F_89 ( V_300 ) ;
if ( V_299 > V_301 )
V_299 = V_301 ;
V_299 = ( V_299 >> 3 ) + 1 ;
for ( V_42 = 0 ; V_42 < V_299 ; V_42 ++ ) {
if ( ! ( F_33 ( V_295 ) & V_296 ) )
break;
if ( F_36 ( V_5 -> V_12 ) )
break;
F_24 ( 8 ) ;
}
}
static void F_90 ( struct V_4 * V_5 , T_1 * V_72 )
{
T_1 V_161 , V_7 ;
V_7 = 0 ;
if ( ! F_57 ( V_5 , V_204 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_302 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
* V_72 ++ = V_7 ;
V_7 = 0 ;
if ( ! F_57 ( V_5 , V_303 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_304 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
* V_72 ++ = V_7 ;
V_7 = 0 ;
if ( ! ( V_5 -> V_178 & V_305 ) ) {
if ( ! F_57 ( V_5 , V_180 , & V_161 ) )
V_7 = V_161 << 16 ;
if ( ! F_57 ( V_5 , V_306 , & V_161 ) )
V_7 |= ( V_161 & 0xffff ) ;
}
* V_72 ++ = V_7 ;
if ( ! F_57 ( V_5 , V_307 , & V_161 ) )
V_7 = V_161 << 16 ;
else
V_7 = 0 ;
* V_72 ++ = V_7 ;
}
static void F_91 ( struct V_4 * V_5 )
{
T_1 V_72 [ 4 ] ;
if ( ! F_23 ( V_5 , 5780_CLASS ) || ! F_23 ( V_5 , V_308 ) )
return;
F_90 ( V_5 , V_72 ) ;
F_87 ( V_5 ) ;
F_29 ( V_5 , V_309 , V_310 ) ;
F_29 ( V_5 , V_311 , 14 ) ;
F_29 ( V_5 , V_312 + 0x0 , V_72 [ 0 ] ) ;
F_29 ( V_5 , V_312 + 0x4 , V_72 [ 1 ] ) ;
F_29 ( V_5 , V_312 + 0x8 , V_72 [ 2 ] ) ;
F_29 ( V_5 , V_312 + 0xc , V_72 [ 3 ] ) ;
F_86 ( V_5 ) ;
}
static void F_92 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_308 ) && ! F_23 ( V_5 , V_60 ) ) {
F_87 ( V_5 ) ;
F_29 ( V_5 , V_309 , V_313 ) ;
F_86 ( V_5 ) ;
F_87 ( V_5 ) ;
}
}
static void F_93 ( struct V_4 * V_5 , int V_95 )
{
F_29 ( V_5 , V_314 ,
V_315 ) ;
if ( F_23 ( V_5 , V_316 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_317 ,
V_318 ) ;
break;
case V_110 :
F_29 ( V_5 , V_317 ,
V_319 ) ;
break;
case V_320 :
F_29 ( V_5 , V_317 ,
V_321 ) ;
break;
default:
break;
}
}
}
static void F_94 ( struct V_4 * V_5 , int V_95 )
{
if ( F_23 ( V_5 , V_316 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_317 ,
V_322 ) ;
break;
case V_110 :
F_29 ( V_5 , V_317 ,
V_323 ) ;
break;
default:
break;
}
}
}
static void F_95 ( struct V_4 * V_5 , int V_95 )
{
if ( F_23 ( V_5 , V_308 ) ) {
switch ( V_95 ) {
case V_96 :
F_29 ( V_5 , V_317 ,
V_318 ) ;
break;
case V_110 :
F_29 ( V_5 , V_317 ,
V_319 ) ;
break;
case V_320 :
F_29 ( V_5 , V_317 ,
V_321 ) ;
break;
default:
break;
}
}
}
static int F_96 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_7 ;
if ( F_23 ( V_5 , V_324 ) )
return 0 ;
if ( F_23 ( V_5 , V_264 ) ) {
return 0 ;
}
if ( F_30 ( V_5 ) == V_36 ) {
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
if ( F_33 ( V_325 ) & V_326 )
return 0 ;
if ( F_36 ( V_5 -> V_12 ) )
return - V_82 ;
F_24 ( 100 ) ;
}
return - V_82 ;
}
for ( V_42 = 0 ; V_42 < 100000 ; V_42 ++ ) {
F_32 ( V_5 , V_314 , & V_7 ) ;
if ( V_7 == ~ V_315 )
break;
if ( F_36 ( V_5 -> V_12 ) ) {
if ( ! F_23 ( V_5 , V_324 ) ) {
F_83 ( V_5 , V_324 ) ;
F_97 ( V_5 -> V_111 , L_5 ) ;
}
break;
}
F_24 ( 10 ) ;
}
if ( V_42 >= 100000 && ! F_23 ( V_5 , V_324 ) ) {
F_83 ( V_5 , V_324 ) ;
F_97 ( V_5 -> V_111 , L_5 ) ;
}
if ( F_76 ( V_5 ) == V_327 ) {
F_98 ( 10 ) ;
}
return 0 ;
}
static void F_99 ( struct V_4 * V_5 )
{
if ( ! F_100 ( V_5 -> V_111 ) ) {
F_101 ( V_5 , V_328 , V_5 -> V_111 , L_6 ) ;
F_91 ( V_5 ) ;
} else if ( F_102 ( V_5 ) ) {
F_97 ( V_5 -> V_111 , L_7 ,
( V_5 -> V_329 . V_330 == V_331 ?
1000 :
( V_5 -> V_329 . V_330 == V_332 ?
100 : 10 ) ) ,
( V_5 -> V_329 . V_333 == V_334 ?
L_8 : L_9 ) ) ;
F_97 ( V_5 -> V_111 , L_10 ,
( V_5 -> V_329 . V_335 & V_336 ) ?
L_11 : L_12 ,
( V_5 -> V_329 . V_335 & V_337 ) ?
L_11 : L_12 ) ;
if ( V_5 -> V_178 & V_338 )
F_97 ( V_5 -> V_111 , L_13 ,
V_5 -> V_339 ? L_14 : L_15 ) ;
F_91 ( V_5 ) ;
}
V_5 -> V_340 = F_100 ( V_5 -> V_111 ) ;
}
static T_1 F_103 ( T_1 V_341 )
{
T_1 V_342 = 0 ;
if ( V_341 & V_343 ) {
V_342 |= V_337 ;
if ( ! ( V_341 & V_344 ) )
V_342 |= V_336 ;
} else if ( V_341 & V_344 )
V_342 |= V_336 ;
return V_342 ;
}
static T_3 F_104 ( T_4 V_345 )
{
T_3 V_346 ;
if ( ( V_345 & V_336 ) && ( V_345 & V_337 ) )
V_346 = V_347 ;
else if ( V_345 & V_336 )
V_346 = V_348 ;
else if ( V_345 & V_337 )
V_346 = V_347 | V_348 ;
else
V_346 = 0 ;
return V_346 ;
}
static T_1 F_105 ( T_1 V_341 )
{
T_1 V_342 = 0 ;
if ( V_341 & V_347 ) {
V_342 |= V_337 ;
if ( ! ( V_341 & V_348 ) )
V_342 |= V_336 ;
} else if ( V_341 & V_348 )
V_342 |= V_336 ;
return V_342 ;
}
static T_4 F_106 ( T_3 V_349 , T_3 V_350 )
{
T_4 V_351 = 0 ;
if ( V_349 & V_350 & V_347 ) {
V_351 = V_336 | V_337 ;
} else if ( V_349 & V_350 & V_348 ) {
if ( V_349 & V_347 )
V_351 = V_337 ;
if ( V_350 & V_347 )
V_351 = V_336 ;
}
return V_351 ;
}
static void F_107 ( struct V_4 * V_5 , T_1 V_349 , T_1 V_350 )
{
T_4 V_352 ;
T_4 V_342 = 0 ;
T_1 V_353 = V_5 -> V_354 ;
T_1 V_355 = V_5 -> V_356 ;
if ( F_23 ( V_5 , V_267 ) )
V_352 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] -> V_352 ;
else
V_352 = V_5 -> V_329 . V_352 ;
if ( V_352 == V_357 && F_23 ( V_5 , V_358 ) ) {
if ( V_5 -> V_178 & V_359 )
V_342 = F_106 ( V_349 , V_350 ) ;
else
V_342 = F_108 ( V_349 , V_350 ) ;
} else
V_342 = V_5 -> V_329 . V_342 ;
V_5 -> V_329 . V_335 = V_342 ;
if ( V_342 & V_337 )
V_5 -> V_354 |= V_360 ;
else
V_5 -> V_354 &= ~ V_360 ;
if ( V_353 != V_5 -> V_354 )
F_31 ( V_361 , V_5 -> V_354 ) ;
if ( V_342 & V_336 )
V_5 -> V_356 |= V_362 ;
else
V_5 -> V_356 &= ~ V_362 ;
if ( V_355 != V_5 -> V_356 )
F_31 ( V_363 , V_5 -> V_356 ) ;
}
static void F_109 ( struct V_364 * V_111 )
{
T_4 V_365 , V_366 = 0 ;
T_1 V_367 , V_368 , V_369 ;
struct V_4 * V_5 = F_110 ( V_111 ) ;
struct V_211 * V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
F_70 ( & V_5 -> V_209 ) ;
V_367 = V_5 -> V_367 & ~ ( V_370 |
V_371 ) ;
V_365 = V_5 -> V_329 . V_335 ;
if ( V_212 -> V_328 ) {
V_368 = 0 ;
V_369 = 0 ;
if ( V_212 -> V_372 == V_332 || V_212 -> V_372 == V_373 )
V_367 |= V_374 ;
else if ( V_212 -> V_372 == V_331 ||
F_30 ( V_5 ) != V_257 )
V_367 |= V_375 ;
else
V_367 |= V_374 ;
if ( V_212 -> V_376 == V_377 )
V_367 |= V_371 ;
else {
V_368 = F_111 (
V_5 -> V_329 . V_342 ) ;
if ( V_212 -> V_378 )
V_369 = V_379 ;
if ( V_212 -> V_380 )
V_369 |= V_381 ;
}
F_107 ( V_5 , V_368 , V_369 ) ;
} else
V_367 |= V_375 ;
if ( V_367 != V_5 -> V_367 ) {
V_5 -> V_367 = V_367 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
}
if ( F_30 ( V_5 ) == V_257 ) {
if ( V_212 -> V_372 == V_373 )
F_46 ( V_383 ,
V_384 |
V_385 ) ;
else
F_46 ( V_383 , V_385 ) ;
}
if ( V_212 -> V_372 == V_331 && V_212 -> V_376 == V_377 )
F_46 ( V_386 ,
( ( 2 << V_387 ) |
( 6 << V_388 ) |
( 0xff << V_389 ) ) ) ;
else
F_46 ( V_386 ,
( ( 2 << V_387 ) |
( 6 << V_388 ) |
( 32 << V_389 ) ) ) ;
if ( V_212 -> V_328 != V_5 -> V_390 ||
V_212 -> V_372 != V_5 -> V_329 . V_330 ||
V_212 -> V_376 != V_5 -> V_329 . V_333 ||
V_365 != V_5 -> V_329 . V_335 )
V_366 = 1 ;
V_5 -> V_390 = V_212 -> V_328 ;
V_5 -> V_329 . V_330 = V_212 -> V_372 ;
V_5 -> V_329 . V_333 = V_212 -> V_376 ;
F_71 ( & V_5 -> V_209 ) ;
if ( V_366 )
F_99 ( V_5 ) ;
}
static int F_112 ( struct V_4 * V_5 )
{
struct V_211 * V_212 ;
if ( V_5 -> V_178 & V_391 )
return 0 ;
F_68 ( V_5 ) ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
V_212 = F_113 ( V_5 -> V_111 , F_114 ( & V_212 -> V_111 ) ,
F_109 , V_212 -> V_227 ) ;
if ( F_115 ( V_212 ) ) {
F_116 ( & V_5 -> V_12 -> V_111 , L_16 ) ;
return F_117 ( V_212 ) ;
}
switch ( V_212 -> V_227 ) {
case V_285 :
case V_228 :
if ( ! ( V_5 -> V_178 & V_392 ) ) {
V_212 -> V_393 &= ( V_394 |
V_395 |
V_396 ) ;
break;
}
case V_294 :
V_212 -> V_393 &= ( V_397 |
V_395 |
V_396 ) ;
break;
default:
F_118 ( V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ) ;
return - V_64 ;
}
V_5 -> V_178 |= V_391 ;
V_212 -> V_398 = V_212 -> V_393 ;
return 0 ;
}
static void F_119 ( struct V_4 * V_5 )
{
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_391 ) )
return;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
if ( V_5 -> V_178 & V_399 ) {
V_5 -> V_178 &= ~ V_399 ;
V_212 -> V_372 = V_5 -> V_329 . V_372 ;
V_212 -> V_376 = V_5 -> V_329 . V_376 ;
V_212 -> V_352 = V_5 -> V_329 . V_352 ;
V_212 -> V_398 = V_5 -> V_329 . V_398 ;
}
F_120 ( V_212 ) ;
F_121 ( V_212 ) ;
}
static void F_122 ( struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_178 & V_391 ) )
return;
F_123 ( V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ) ;
}
static void F_124 ( struct V_4 * V_5 )
{
if ( V_5 -> V_178 & V_391 ) {
F_118 ( V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ) ;
V_5 -> V_178 &= ~ V_391 ;
}
}
static int F_125 ( struct V_4 * V_5 )
{
int V_75 ;
T_1 V_7 ;
if ( V_5 -> V_178 & V_179 )
return 0 ;
if ( ( V_5 -> V_216 & V_400 ) == V_401 ) {
V_75 = F_65 ( V_5 ,
V_196 ,
V_402 |
0x4c20 ) ;
goto V_186;
}
V_75 = F_64 ( V_5 ,
V_196 , & V_7 ) ;
if ( V_75 )
return V_75 ;
V_7 |= V_402 ;
V_75 = F_65 ( V_5 ,
V_196 , V_7 ) ;
V_186:
return V_75 ;
}
static void F_126 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_403 ;
if ( ! F_57 ( V_5 , V_404 , & V_403 ) ) {
T_1 V_405 ;
F_59 ( V_5 , V_404 ,
V_403 | V_406 ) ;
if ( ! F_57 ( V_5 , V_407 , & V_405 ) ) {
if ( V_195 )
V_405 |= V_408 ;
else
V_405 &= ~ V_408 ;
F_59 ( V_5 , V_407 , V_405 ) ;
}
F_59 ( V_5 , V_404 , V_403 ) ;
}
}
static void F_127 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_161 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
( F_23 ( V_5 , 5717_PLUS ) &&
( V_5 -> V_178 & V_305 ) ) )
return;
if ( V_5 -> V_178 & V_179 ) {
F_126 ( V_5 , V_195 ) ;
return;
}
V_161 = V_409 |
V_410 |
V_411 |
V_412 ;
if ( F_30 ( V_5 ) != V_413 || ! V_195 )
V_161 |= V_414 ;
F_67 ( V_5 , V_415 , V_161 ) ;
V_161 = V_416 ;
if ( V_195 )
V_161 |= V_417 ;
F_67 ( V_5 , V_418 , V_161 ) ;
}
static void F_128 ( struct V_4 * V_5 , bool V_195 )
{
T_1 V_405 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
( V_5 -> V_178 & V_359 ) )
return;
if ( V_5 -> V_178 & V_179 ) {
T_1 V_419 ;
if ( ! F_57 ( V_5 , V_404 , & V_419 ) ) {
T_1 V_161 = V_420 ;
F_59 ( V_5 , V_404 ,
V_419 | V_406 ) ;
if ( ! F_57 ( V_5 , V_161 , & V_405 ) ) {
if ( V_195 )
V_405 |= V_421 ;
else
V_405 &= ~ V_421 ;
F_59 ( V_5 , V_161 , V_405 ) ;
}
F_59 ( V_5 , V_404 , V_419 ) ;
}
} else {
int V_56 ;
V_56 = F_64 ( V_5 ,
V_192 , & V_405 ) ;
if ( ! V_56 ) {
if ( V_195 )
V_405 |= V_422 ;
else
V_405 &= ~ V_422 ;
F_65 ( V_5 ,
V_192 , V_405 ) ;
}
}
}
static void F_129 ( struct V_4 * V_5 )
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
static void F_130 ( struct V_4 * V_5 )
{
T_1 V_425 , V_405 ;
if ( ! V_5 -> V_426 )
return;
V_425 = V_5 -> V_426 ;
if ( F_66 ( V_5 , true ) )
return;
V_405 = ( ( V_425 & V_427 ) >> V_428 ) ;
V_405 |= V_429 ;
F_63 ( V_5 , V_430 , V_405 ) ;
V_405 = ( ( V_425 & V_431 ) >> V_432 ) |
( ( V_425 & V_433 ) >> V_434 ) ;
F_63 ( V_5 , V_435 , V_405 ) ;
V_405 = ( ( V_425 & V_436 ) >> V_437 ) ;
V_405 |= V_438 ;
F_63 ( V_5 , V_439 , V_405 ) ;
V_405 = ( ( V_425 & V_440 ) >> V_441 ) ;
F_63 ( V_5 , V_442 , V_405 ) ;
V_405 = ( ( V_425 & V_443 ) >> V_444 ) ;
F_63 ( V_5 , V_445 , V_405 ) ;
V_405 = ( ( V_425 & V_446 ) >> V_447 ) |
( ( V_425 & V_448 ) >> V_449 ) ;
F_63 ( V_5 , V_450 , V_405 ) ;
F_66 ( V_5 , false ) ;
}
static void F_131 ( struct V_4 * V_5 , struct V_451 * V_452 )
{
T_1 V_7 ;
struct V_451 * V_453 = & V_5 -> V_452 ;
if ( ! ( V_5 -> V_178 & V_338 ) )
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
V_453 -> V_460 = F_132 ( V_7 ) ;
if ( F_61 ( V_5 , V_454 , V_461 , & V_7 ) )
return;
V_453 -> V_462 = ! ! V_7 ;
V_453 -> V_463 = F_132 ( V_7 ) ;
V_7 = F_33 ( V_464 ) ;
V_453 -> V_465 = ! ! ( V_7 & V_466 ) ;
V_453 -> V_467 = F_33 ( V_468 ) & 0xffff ;
}
static void F_133 ( struct V_4 * V_5 , bool V_469 )
{
T_1 V_7 ;
if ( ! ( V_5 -> V_178 & V_338 ) )
return;
V_5 -> V_339 = 0 ;
if ( V_5 -> V_329 . V_352 == V_357 &&
V_469 &&
V_5 -> V_329 . V_333 == V_334 &&
( V_5 -> V_329 . V_330 == V_332 ||
V_5 -> V_329 . V_330 == V_331 ) ) {
T_1 V_470 ;
if ( V_5 -> V_329 . V_330 == V_331 )
V_470 = V_471 ;
else
V_470 = V_472 ;
F_46 ( V_473 , V_470 ) ;
F_131 ( V_5 , NULL ) ;
if ( V_5 -> V_452 . V_458 )
V_5 -> V_339 = 2 ;
}
if ( ! V_5 -> V_339 ) {
if ( V_469 &&
! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , V_474 , 0x0000 ) ;
F_66 ( V_5 , false ) ;
}
V_7 = F_33 ( V_464 ) ;
F_46 ( V_464 , V_7 & ~ V_475 ) ;
}
}
static void F_134 ( struct V_4 * V_5 )
{
T_1 V_7 ;
if ( V_5 -> V_329 . V_330 == V_331 &&
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
static int F_135 ( struct V_4 * V_5 )
{
int V_202 = 100 ;
while ( V_202 -- ) {
T_1 V_480 ;
if ( ! F_57 ( V_5 , V_481 , & V_480 ) ) {
if ( ( V_480 & 0x1000 ) == 0 )
break;
}
}
if ( V_202 < 0 )
return - V_67 ;
return 0 ;
}
static int F_136 ( struct V_4 * V_5 , int * V_482 )
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
if ( F_135 ( V_5 ) ) {
* V_482 = 1 ;
return - V_67 ;
}
F_59 ( V_5 , V_189 ,
( V_484 * 0x2000 ) | 0x0200 ) ;
F_59 ( V_5 , V_481 , 0x0082 ) ;
if ( F_135 ( V_5 ) ) {
* V_482 = 1 ;
return - V_67 ;
}
F_59 ( V_5 , V_481 , 0x0802 ) ;
if ( F_135 ( V_5 ) ) {
* V_482 = 1 ;
return - V_67 ;
}
for ( V_42 = 0 ; V_42 < 6 ; V_42 += 2 ) {
T_1 V_485 , V_486 ;
if ( F_57 ( V_5 , V_190 , & V_485 ) ||
F_57 ( V_5 , V_190 , & V_486 ) ||
F_135 ( V_5 ) ) {
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
static int F_137 ( struct V_4 * V_5 )
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
if ( F_135 ( V_5 ) )
return - V_67 ;
}
return 0 ;
}
static int F_138 ( struct V_4 * V_5 )
{
T_1 V_487 , V_488 ;
int V_489 , V_490 , V_75 ;
V_489 = 10 ;
V_490 = 1 ;
do {
if ( V_490 ) {
V_75 = F_68 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_490 = 0 ;
}
if ( F_57 ( V_5 , V_491 , & V_487 ) )
continue;
V_487 |= 0x3000 ;
F_59 ( V_5 , V_491 , V_487 ) ;
F_59 ( V_5 , V_204 ,
V_492 | V_493 ) ;
if ( F_57 ( V_5 , V_180 , & V_488 ) )
continue;
F_59 ( V_5 , V_180 ,
V_494 | V_495 ) ;
V_75 = F_66 ( V_5 , true ) ;
if ( V_75 )
return V_75 ;
F_63 ( V_5 , 0x8005 , 0x0800 ) ;
V_75 = F_136 ( V_5 , & V_490 ) ;
if ( ! V_75 )
break;
} while ( -- V_489 );
V_75 = F_137 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_63 ( V_5 , 0x8005 , 0x0000 ) ;
F_59 ( V_5 , V_189 , 0x8200 ) ;
F_59 ( V_5 , V_481 , 0x0000 ) ;
F_66 ( V_5 , false ) ;
F_59 ( V_5 , V_180 , V_488 ) ;
V_75 = F_57 ( V_5 , V_491 , & V_487 ) ;
if ( V_75 )
return V_75 ;
V_487 &= ~ 0x3000 ;
F_59 ( V_5 , V_491 , V_487 ) ;
return 0 ;
}
static void F_139 ( struct V_4 * V_5 )
{
F_140 ( V_5 -> V_111 ) ;
V_5 -> V_340 = false ;
}
static void F_141 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_308 ) )
F_142 ( V_5 -> V_111 ,
L_17 ) ;
}
static int F_143 ( struct V_4 * V_5 )
{
T_1 V_7 , V_496 ;
int V_75 ;
if ( F_30 ( V_5 ) == V_36 ) {
V_7 = F_33 ( V_497 ) ;
F_31 ( V_497 , V_7 & ~ V_498 ) ;
F_24 ( 40 ) ;
}
V_75 = F_57 ( V_5 , V_302 , & V_7 ) ;
V_75 |= F_57 ( V_5 , V_302 , & V_7 ) ;
if ( V_75 != 0 )
return - V_67 ;
if ( F_144 ( V_5 -> V_111 ) && V_5 -> V_340 ) {
F_140 ( V_5 -> V_111 ) ;
F_99 ( V_5 ) ;
}
if ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ) {
V_75 = F_138 ( V_5 ) ;
if ( V_75 )
return V_75 ;
goto V_502;
}
V_496 = 0 ;
if ( F_30 ( V_5 ) == V_413 &&
F_145 ( V_5 ) != V_503 ) {
V_496 = F_33 ( V_504 ) ;
if ( V_496 & V_505 )
F_46 ( V_504 ,
V_496 & ~ V_505 ) ;
}
V_75 = F_68 ( V_5 ) ;
if ( V_75 )
return V_75 ;
if ( V_496 & V_505 ) {
V_7 = V_506 | V_507 ;
F_63 ( V_5 , V_508 , V_7 ) ;
F_46 ( V_504 , V_496 ) ;
}
if ( F_145 ( V_5 ) == V_503 ||
F_145 ( V_5 ) == V_509 ) {
V_7 = F_33 ( V_510 ) ;
if ( ( V_7 & V_511 ) ==
V_512 ) {
V_7 &= ~ V_511 ;
F_24 ( 40 ) ;
F_31 ( V_510 , V_7 ) ;
}
}
if ( F_23 ( V_5 , 5717_PLUS ) &&
( V_5 -> V_178 & V_305 ) )
return 0 ;
F_130 ( V_5 ) ;
if ( V_5 -> V_178 & V_513 )
F_127 ( V_5 , true ) ;
else
F_127 ( V_5 , false ) ;
V_502:
if ( ( V_5 -> V_178 & V_514 ) &&
! F_66 ( V_5 , true ) ) {
F_63 ( V_5 , 0x201f , 0x2aaa ) ;
F_63 ( V_5 , 0x000a , 0x0323 ) ;
F_66 ( V_5 , false ) ;
}
if ( V_5 -> V_178 & V_515 ) {
F_59 ( V_5 , V_199 , 0x8d68 ) ;
F_59 ( V_5 , V_199 , 0x8d68 ) ;
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
if ( ( V_5 -> V_216 & V_400 ) == V_401 ) {
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
F_128 ( V_5 , true ) ;
F_129 ( V_5 ) ;
return 0 ;
}
static inline T_1 F_146 ( struct V_4 * V_5 , T_1 V_526 )
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
static inline int F_147 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_532 ) )
return 0 ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) {
if ( F_35 ( V_5 , V_49 ) )
return - V_210 ;
F_146 ( V_5 , V_534 ) ;
F_55 ( V_136 , V_5 -> V_22 ,
V_535 ) ;
F_37 ( V_5 , V_49 ) ;
} else {
F_55 ( V_136 , V_5 -> V_22 ,
V_535 ) ;
}
return 0 ;
}
static void F_148 ( struct V_4 * V_5 )
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
static void F_149 ( struct V_4 * V_5 )
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
static void F_150 ( struct V_4 * V_5 , bool V_552 )
{
T_1 V_553 = 0 ;
if ( F_35 ( V_5 , V_49 ) )
return;
if ( F_23 ( V_5 , V_308 ) || F_23 ( V_5 , V_60 ) || V_552 )
V_553 = V_554 ;
V_553 = F_146 ( V_5 , V_553 ) ;
if ( V_553 & V_555 )
goto V_186;
if ( V_553 & V_556 )
F_149 ( V_5 ) ;
else
F_148 ( V_5 ) ;
V_186:
F_37 ( V_5 , V_49 ) ;
}
static void F_151 ( struct V_4 * V_5 , bool V_557 )
{
bool V_558 = false ;
if ( ! F_23 ( V_5 , V_532 ) || F_23 ( V_5 , 57765_CLASS ) )
return;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) {
F_150 ( V_5 , V_557 ?
F_23 ( V_5 , V_112 ) != 0 : 0 ) ;
return;
}
if ( V_5 -> V_559 && V_5 -> V_559 != V_5 -> V_12 ) {
struct V_364 * V_560 ;
V_560 = F_152 ( V_5 -> V_559 ) ;
if ( V_560 ) {
struct V_4 * V_561 = F_110 ( V_560 ) ;
if ( F_23 ( V_561 , V_562 ) )
return;
if ( ( V_557 && F_23 ( V_561 , V_112 ) ) ||
F_23 ( V_561 , V_308 ) )
V_558 = true ;
}
}
if ( ( V_557 && F_23 ( V_5 , V_112 ) ) ||
F_23 ( V_5 , V_308 ) )
V_558 = true ;
if ( V_558 )
F_149 ( V_5 ) ;
else
F_148 ( V_5 ) ;
}
static int F_153 ( struct V_4 * V_5 , T_1 V_372 )
{
if ( V_5 -> V_563 == V_564 )
return 1 ;
else if ( ( V_5 -> V_216 & V_400 ) == V_565 ) {
if ( V_372 != V_373 )
return 1 ;
} else if ( V_372 == V_373 )
return 1 ;
return 0 ;
}
static bool F_154 ( struct V_4 * V_5 )
{
switch ( F_30 ( V_5 ) ) {
case V_536 :
case V_500 :
return true ;
case V_566 :
if ( V_5 -> V_178 & V_305 )
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
static bool F_155 ( struct V_4 * V_5 )
{
switch ( F_30 ( V_5 ) ) {
case V_477 :
case V_533 :
if ( ( V_5 -> V_178 & V_305 ) &&
! V_5 -> V_54 )
return true ;
return false ;
}
return false ;
}
static void F_156 ( struct V_4 * V_5 , bool V_568 )
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
F_68 ( V_5 ) ;
V_7 = F_33 ( V_497 ) ;
F_31 ( V_497 , V_7 | V_498 ) ;
F_24 ( 40 ) ;
return;
} else if ( V_5 -> V_178 & V_179 ) {
T_1 V_403 ;
if ( ! F_57 ( V_5 , V_404 , & V_403 ) ) {
T_1 V_405 ;
F_59 ( V_5 , V_303 , 0 ) ;
F_59 ( V_5 , V_204 ,
V_576 | V_577 ) ;
F_59 ( V_5 , V_404 ,
V_403 | V_406 ) ;
if ( ! F_57 ( V_5 , V_578 , & V_405 ) ) {
V_405 |= V_579 ;
F_59 ( V_5 ,
V_578 ,
V_405 ) ;
}
F_59 ( V_5 , V_404 , V_403 ) ;
}
return;
} else if ( V_568 ) {
if ( ! F_155 ( V_5 ) )
F_59 ( V_5 , V_491 ,
V_580 ) ;
V_7 = V_581 |
V_582 |
V_583 ;
F_65 ( V_5 , V_584 , V_7 ) ;
}
if ( F_154 ( V_5 ) )
return;
if ( F_145 ( V_5 ) == V_503 ||
F_145 ( V_5 ) == V_509 ) {
V_7 = F_33 ( V_510 ) ;
V_7 &= ~ V_511 ;
V_7 |= V_512 ;
F_31 ( V_510 , V_7 ) ;
}
F_59 ( V_5 , V_204 , V_283 ) ;
}
static int F_157 ( struct V_4 * V_5 )
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
static void F_158 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_585 ) ) {
if ( V_5 -> V_586 > 0 )
V_5 -> V_586 -- ;
if ( V_5 -> V_586 == 0 )
F_31 ( V_587 , V_590 ) ;
}
}
static void F_159 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_591 ) ) {
T_1 V_592 = F_33 ( V_593 ) ;
F_46 ( V_593 , V_592 | V_594 ) ;
}
}
static void F_160 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_591 ) ) {
T_1 V_592 = F_33 ( V_593 ) ;
F_46 ( V_593 , V_592 & ~ V_594 ) ;
}
}
static int F_161 ( struct V_4 * V_5 ,
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
F_162 ( 1 ) ;
}
if ( ! ( V_596 & V_604 ) )
return - V_67 ;
V_596 = F_33 ( V_605 ) ;
* V_7 = F_163 ( V_596 ) ;
return 0 ;
}
static int F_164 ( struct V_4 * V_5 , T_1 V_606 )
{
int V_42 ;
F_46 ( V_607 , V_606 ) ;
for ( V_42 = 0 ; V_42 < V_608 ; V_42 ++ ) {
F_165 ( 10 , 40 ) ;
if ( F_33 ( V_607 ) & V_609 ) {
F_24 ( 10 ) ;
break;
}
}
if ( V_42 == V_608 )
return - V_67 ;
return 0 ;
}
static T_1 F_166 ( struct V_4 * V_5 , T_1 V_184 )
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
static T_1 F_167 ( struct V_4 * V_5 , T_1 V_184 )
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
static int F_168 ( struct V_4 * V_5 , T_1 V_595 , T_1 * V_7 )
{
int V_56 ;
if ( ! F_23 ( V_5 , V_585 ) )
return F_161 ( V_5 , V_595 , V_7 ) ;
V_595 = F_166 ( V_5 , V_595 ) ;
if ( V_595 > V_617 )
return - V_64 ;
V_56 = F_157 ( V_5 ) ;
if ( V_56 )
return V_56 ;
F_159 ( V_5 ) ;
F_46 ( V_618 , V_595 ) ;
V_56 = F_164 ( V_5 , V_619 | V_620 |
V_621 | V_622 | V_609 ) ;
if ( V_56 == 0 )
* V_7 = F_33 ( V_623 ) ;
F_160 ( V_5 ) ;
F_158 ( V_5 ) ;
return V_56 ;
}
static int F_169 ( struct V_4 * V_5 , T_1 V_595 , T_5 * V_7 )
{
T_1 V_624 ;
int V_625 = F_168 ( V_5 , V_595 , & V_624 ) ;
if ( ! V_625 )
* V_7 = F_170 ( V_624 ) ;
return V_625 ;
}
static int F_171 ( struct V_4 * V_5 ,
T_1 V_595 , T_1 V_74 , T_4 * V_626 )
{
int V_42 , V_627 , V_628 = 0 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 ) {
T_1 V_184 ;
T_5 V_72 ;
V_184 = V_595 + V_42 ;
memcpy ( & V_72 , V_626 + V_42 , 4 ) ;
F_46 ( V_605 , F_163 ( F_172 ( V_72 ) ) ) ;
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
F_162 ( 1 ) ;
}
if ( ! ( V_7 & V_604 ) ) {
V_628 = - V_67 ;
break;
}
}
return V_628 ;
}
static int F_173 ( struct V_4 * V_5 , T_1 V_595 , T_1 V_74 ,
T_4 * V_626 )
{
int V_56 = 0 ;
T_1 V_630 = V_5 -> V_615 ;
T_1 V_631 = V_630 - 1 ;
T_1 V_606 ;
T_4 * V_596 ;
V_596 = F_174 ( V_630 , V_632 ) ;
if ( V_596 == NULL )
return - V_268 ;
while ( V_74 ) {
int V_627 ;
T_1 V_160 , V_633 , V_634 ;
V_160 = V_595 & ~ V_631 ;
for ( V_627 = 0 ; V_627 < V_630 ; V_627 += 4 ) {
V_56 = F_169 ( V_5 , V_160 + V_627 ,
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
F_159 ( V_5 ) ;
V_606 = V_635 | V_620 | V_609 ;
if ( F_164 ( V_5 , V_606 ) )
break;
F_46 ( V_618 , V_160 ) ;
V_606 = V_620 | V_609 | V_636 |
V_621 | V_622 | V_637 ;
if ( F_164 ( V_5 , V_606 ) )
break;
V_606 = V_635 | V_620 | V_609 ;
if ( F_164 ( V_5 , V_606 ) )
break;
for ( V_627 = 0 ; V_627 < V_630 ; V_627 += 4 ) {
T_5 V_72 ;
V_72 = * ( ( T_5 * ) ( V_596 + V_627 ) ) ;
F_46 ( V_638 , F_172 ( V_72 ) ) ;
F_46 ( V_618 , V_160 + V_627 ) ;
V_606 = V_620 | V_609 |
V_636 ;
if ( V_627 == 0 )
V_606 |= V_621 ;
else if ( V_627 == ( V_630 - 4 ) )
V_606 |= V_622 ;
V_56 = F_164 ( V_5 , V_606 ) ;
if ( V_56 )
break;
}
if ( V_56 )
break;
}
V_606 = V_639 | V_620 | V_609 ;
F_164 ( V_5 , V_606 ) ;
F_175 ( V_596 ) ;
return V_56 ;
}
static int F_176 ( struct V_4 * V_5 , T_1 V_595 , T_1 V_74 ,
T_4 * V_626 )
{
int V_42 , V_56 = 0 ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 , V_595 += 4 ) {
T_1 V_633 , V_160 , V_606 ;
T_5 V_72 ;
memcpy ( & V_72 , V_626 + V_42 , 4 ) ;
F_46 ( V_638 , F_172 ( V_72 ) ) ;
V_633 = V_595 % V_5 -> V_615 ;
V_160 = F_166 ( V_5 , V_595 ) ;
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
V_56 = F_164 ( V_5 , V_642 ) ;
if ( V_56 )
break;
}
if ( ! F_23 ( V_5 , V_611 ) ) {
V_606 |= ( V_621 | V_622 ) ;
}
V_56 = F_164 ( V_5 , V_606 ) ;
if ( V_56 )
break;
}
return V_56 ;
}
static int F_177 ( struct V_4 * V_5 , T_1 V_595 , T_1 V_74 , T_4 * V_626 )
{
int V_56 ;
if ( F_23 ( V_5 , V_643 ) ) {
F_31 ( V_136 , V_5 -> V_22 &
~ V_539 ) ;
F_24 ( 40 ) ;
}
if ( ! F_23 ( V_5 , V_585 ) ) {
V_56 = F_171 ( V_5 , V_595 , V_74 , V_626 ) ;
} else {
T_1 V_644 ;
V_56 = F_157 ( V_5 ) ;
if ( V_56 )
return V_56 ;
F_159 ( V_5 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) && ! F_23 ( V_5 , V_591 ) )
F_46 ( V_645 , 0x406 ) ;
V_644 = F_33 ( V_646 ) ;
F_46 ( V_646 , V_644 | V_647 ) ;
if ( F_23 ( V_5 , V_610 ) || ! F_23 ( V_5 , V_611 ) ) {
V_56 = F_176 ( V_5 , V_595 , V_74 ,
V_626 ) ;
} else {
V_56 = F_173 ( V_5 , V_595 , V_74 ,
V_626 ) ;
}
V_644 = F_33 ( V_646 ) ;
F_46 ( V_646 , V_644 & ~ V_647 ) ;
F_160 ( V_5 ) ;
F_158 ( V_5 ) ;
}
if ( F_23 ( V_5 , V_643 ) ) {
F_31 ( V_136 , V_5 -> V_22 ) ;
F_24 ( 40 ) ;
}
return V_56 ;
}
static int F_178 ( struct V_4 * V_5 , T_1 V_648 )
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
static int F_179 ( struct V_4 * V_5 )
{
int V_628 = F_178 ( V_5 , V_653 ) ;
F_46 ( V_653 + V_650 , 0xffffffff ) ;
F_31 ( V_653 + V_651 , V_652 ) ;
F_24 ( 10 ) ;
return V_628 ;
}
static int F_180 ( struct V_4 * V_5 )
{
return F_178 ( V_5 , V_654 ) ;
}
static void F_181 ( struct V_4 * V_5 , T_1 V_648 )
{
F_46 ( V_648 + V_650 , 0xffffffff ) ;
F_31 ( V_648 + V_651 , 0x00000000 ) ;
}
static void F_182 ( struct V_4 * V_5 )
{
F_181 ( V_5 , V_653 ) ;
}
static int F_183 ( struct V_4 * V_5 , T_1 V_648 )
{
int V_628 ;
F_184 ( V_648 == V_654 && F_23 ( V_5 , 5705_PLUS ) ) ;
if ( F_30 ( V_5 ) == V_36 ) {
T_1 V_7 = F_33 ( V_655 ) ;
F_46 ( V_655 , V_7 | V_656 ) ;
return 0 ;
}
if ( V_648 == V_653 ) {
V_628 = F_179 ( V_5 ) ;
} else {
if ( F_23 ( V_5 , V_264 ) )
return 0 ;
V_628 = F_180 ( V_5 ) ;
}
if ( V_628 ) {
F_185 ( V_5 -> V_111 , L_18 ,
V_657 , V_648 == V_653 ? L_19 : L_20 ) ;
return - V_82 ;
}
if ( F_23 ( V_5 , V_585 ) )
F_46 ( V_587 , V_658 ) ;
return 0 ;
}
static int F_186 ( struct V_4 * V_5 ,
const struct V_659 * V_660 )
{
int V_661 ;
if ( V_5 -> V_661 == 0xffffffff )
V_661 = F_172 ( V_660 -> V_74 ) ;
else
V_661 = V_5 -> V_662 -> V_634 ;
return ( V_661 - V_663 ) / sizeof( T_1 ) ;
}
static int F_187 ( struct V_4 * V_5 , T_1 V_648 ,
T_1 V_664 , int V_665 ,
const struct V_659 * V_660 )
{
int V_75 , V_42 ;
void (* F_188)( struct V_4 * , T_1 , T_1 );
int V_666 = V_5 -> V_662 -> V_634 ;
if ( V_648 == V_654 && F_23 ( V_5 , 5705_PLUS ) ) {
F_185 ( V_5 -> V_111 ,
L_21 ,
V_657 ) ;
return - V_64 ;
}
if ( F_23 ( V_5 , 5705_PLUS ) && F_30 ( V_5 ) != V_667 )
F_188 = F_29 ;
else
F_188 = F_13 ;
if ( F_30 ( V_5 ) != V_667 ) {
int V_668 = F_157 ( V_5 ) ;
V_75 = F_183 ( V_5 , V_648 ) ;
if ( ! V_668 )
F_158 ( V_5 ) ;
if ( V_75 )
goto V_502;
for ( V_42 = 0 ; V_42 < V_665 ; V_42 += sizeof( T_1 ) )
F_188 ( V_5 , V_664 + V_42 , 0 ) ;
F_46 ( V_648 + V_650 , 0xffffffff ) ;
F_46 ( V_648 + V_651 ,
F_33 ( V_648 + V_651 ) | V_652 ) ;
} else {
V_666 -= V_663 ;
V_660 ++ ;
}
do {
T_1 * V_669 = ( T_1 * ) ( V_660 + 1 ) ;
for ( V_42 = 0 ; V_42 < F_186 ( V_5 , V_660 ) ; V_42 ++ )
F_188 ( V_5 , V_664 +
( F_172 ( V_660 -> V_670 ) & 0xffff ) +
( V_42 * sizeof( T_1 ) ) ,
F_172 ( V_669 [ V_42 ] ) ) ;
V_666 -= F_172 ( V_660 -> V_74 ) ;
V_660 = (struct V_659 * )
( ( void * ) V_660 + F_172 ( V_660 -> V_74 ) ) ;
} while ( V_666 > 0 );
V_75 = 0 ;
V_502:
return V_75 ;
}
static int F_189 ( struct V_4 * V_5 , T_1 V_648 , T_1 V_671 )
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
static int F_190 ( struct V_4 * V_5 )
{
const struct V_659 * V_660 ;
int V_75 ;
V_660 = (struct V_659 * ) V_5 -> V_662 -> V_72 ;
V_75 = F_187 ( V_5 , V_653 ,
V_673 , V_674 ,
V_660 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_187 ( V_5 , V_654 ,
V_675 , V_676 ,
V_660 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_189 ( V_5 , V_653 ,
F_172 ( V_660 -> V_670 ) ) ;
if ( V_75 ) {
F_185 ( V_5 -> V_111 , L_22
L_23 , V_657 ,
F_33 ( V_653 + V_672 ) ,
F_172 ( V_660 -> V_670 ) ) ;
return - V_82 ;
}
F_182 ( V_5 ) ;
return 0 ;
}
static int F_191 ( struct V_4 * V_5 )
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
F_185 ( V_5 -> V_111 , L_24 ) ;
return - V_67 ;
}
V_7 = F_18 ( V_5 , V_679 ) ;
if ( V_7 & 0xff ) {
F_142 ( V_5 -> V_111 ,
L_25 ) ;
return - V_680 ;
}
return 0 ;
}
static void F_192 ( struct V_4 * V_5 )
{
struct V_659 * V_660 ;
if ( ! F_23 ( V_5 , V_681 ) )
return;
if ( F_191 ( V_5 ) )
return;
if ( ! V_5 -> V_662 )
return;
V_660 = (struct V_659 * ) V_5 -> V_662 -> V_72 ;
if ( F_172 ( V_660 -> V_670 ) != V_682 )
return;
if ( F_179 ( V_5 ) )
return;
F_187 ( V_5 , 0 , V_682 , 0 , V_660 ) ;
F_182 ( V_5 ) ;
}
static int F_193 ( struct V_4 * V_5 )
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
V_75 = F_187 ( V_5 , V_648 ,
V_664 , V_665 ,
V_660 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_189 ( V_5 , V_648 ,
F_172 ( V_660 -> V_670 ) ) ;
if ( V_75 ) {
F_185 ( V_5 -> V_111 ,
L_26 ,
V_657 , F_33 ( V_648 + V_672 ) ,
F_172 ( V_660 -> V_670 ) ) ;
return - V_82 ;
}
F_181 ( V_5 , V_648 ) ;
return 0 ;
}
static void F_194 ( struct V_4 * V_5 , T_4 * V_685 , int V_686 )
{
T_1 V_687 , V_688 ;
V_687 = ( ( V_685 [ 0 ] << 8 ) | V_685 [ 1 ] ) ;
V_688 = ( ( V_685 [ 2 ] << 24 ) | ( V_685 [ 3 ] << 16 ) |
( V_685 [ 4 ] << 8 ) | V_685 [ 5 ] ) ;
if ( V_686 < 4 ) {
F_46 ( V_689 + ( V_686 * 8 ) , V_687 ) ;
F_46 ( V_690 + ( V_686 * 8 ) , V_688 ) ;
} else {
V_686 -= 4 ;
F_46 ( V_691 + ( V_686 * 8 ) , V_687 ) ;
F_46 ( V_692 + ( V_686 * 8 ) , V_688 ) ;
}
}
static void F_195 ( struct V_4 * V_5 , bool V_693 )
{
T_1 V_687 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
if ( V_42 == 1 && V_693 )
continue;
F_194 ( V_5 , V_5 -> V_111 -> V_694 , V_42 ) ;
}
if ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 ) {
for ( V_42 = 4 ; V_42 < 16 ; V_42 ++ )
F_194 ( V_5 , V_5 -> V_111 -> V_694 , V_42 ) ;
}
V_687 = ( V_5 -> V_111 -> V_694 [ 0 ] +
V_5 -> V_111 -> V_694 [ 1 ] +
V_5 -> V_111 -> V_694 [ 2 ] +
V_5 -> V_111 -> V_694 [ 3 ] +
V_5 -> V_111 -> V_694 [ 4 ] +
V_5 -> V_111 -> V_694 [ 5 ] ) &
V_695 ;
F_46 ( V_696 , V_687 ) ;
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
V_75 = F_198 ( V_5 -> V_12 , V_697 ) ;
if ( ! V_75 ) {
F_147 ( V_5 ) ;
} else {
F_185 ( V_5 -> V_111 , L_27 ) ;
}
return V_75 ;
}
static int F_199 ( struct V_4 * V_5 )
{
T_1 V_120 ;
bool V_698 , V_568 ;
F_196 ( V_5 ) ;
if ( F_23 ( V_5 , V_699 ) )
F_200 ( V_5 -> V_12 , V_700 ,
V_701 ) ;
V_120 = F_33 ( V_119 ) ;
F_46 ( V_119 ,
V_120 | V_121 ) ;
V_698 = F_44 ( & V_5 -> V_12 -> V_111 ) &&
F_23 ( V_5 , V_112 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
V_568 = false ;
if ( ( V_5 -> V_178 & V_391 ) &&
! ( V_5 -> V_178 & V_399 ) ) {
struct V_211 * V_212 ;
T_1 V_702 , V_398 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
V_5 -> V_178 |= V_399 ;
V_5 -> V_329 . V_372 = V_212 -> V_372 ;
V_5 -> V_329 . V_376 = V_212 -> V_376 ;
V_5 -> V_329 . V_352 = V_212 -> V_352 ;
V_5 -> V_329 . V_398 = V_212 -> V_398 ;
V_398 = V_703 |
V_704 |
V_705 |
V_706 ;
if ( F_23 ( V_5 , V_308 ) || V_698 ) {
if ( F_23 ( V_5 , V_707 ) )
V_398 |=
V_708 |
V_709 |
V_710 ;
else
V_398 |= V_710 ;
}
V_212 -> V_398 = V_398 ;
F_121 ( V_212 ) ;
V_702 = V_212 -> V_215 -> V_216 & V_212 -> V_215 -> V_217 ;
if ( V_702 != V_221 ) {
V_702 &= V_711 ;
if ( V_702 == V_712 ||
V_702 == V_713 ||
V_702 == V_714 )
V_568 = true ;
}
}
} else {
V_568 = true ;
if ( ! ( V_5 -> V_178 & V_399 ) )
V_5 -> V_178 |= V_399 ;
if ( ! ( V_5 -> V_178 & V_359 ) )
F_201 ( V_5 , false ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
T_1 V_7 ;
V_7 = F_33 ( V_655 ) ;
F_46 ( V_655 , V_7 | V_715 ) ;
} else if ( ! F_23 ( V_5 , V_308 ) ) {
int V_42 ;
T_1 V_7 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_32 ( V_5 , V_716 , & V_7 ) ;
if ( V_7 == ~ V_315 )
break;
F_162 ( 1 ) ;
}
}
if ( F_23 ( V_5 , V_717 ) )
F_29 ( V_5 , V_718 , V_719 |
V_720 |
V_721 |
V_722 ) ;
if ( V_698 ) {
T_1 V_367 ;
if ( ! ( V_5 -> V_178 & V_567 ) ) {
if ( V_568 &&
! ( V_5 -> V_178 & V_179 ) ) {
F_65 ( V_5 ,
V_584 ,
V_723 |
V_581 |
V_724 ) ;
F_24 ( 40 ) ;
}
if ( V_5 -> V_178 & V_305 )
V_367 = V_375 ;
else if ( V_5 -> V_178 &
V_569 ) {
if ( V_5 -> V_329 . V_330 == V_331 )
V_367 = V_375 ;
else
V_367 = V_374 ;
} else
V_367 = V_374 ;
V_367 |= V_5 -> V_367 & V_725 ;
if ( F_30 ( V_5 ) == V_536 ) {
T_1 V_372 = F_23 ( V_5 , V_707 ) ?
V_332 : V_373 ;
if ( F_153 ( V_5 , V_372 ) )
V_367 |= V_725 ;
else
V_367 &= ~ V_725 ;
}
} else {
V_367 = V_726 ;
}
if ( ! F_23 ( V_5 , 5750_PLUS ) )
F_46 ( V_727 , V_5 -> V_563 ) ;
V_367 |= V_728 ;
if ( ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) ) &&
( F_23 ( V_5 , V_308 ) || F_23 ( V_5 , V_60 ) ) )
V_367 |= V_729 ;
if ( F_23 ( V_5 , V_60 ) )
V_367 |= V_730 |
V_731 |
V_732 ;
F_31 ( V_382 , V_367 ) ;
F_24 ( 100 ) ;
F_31 ( V_361 , V_733 ) ;
F_24 ( 10 ) ;
}
if ( ! F_23 ( V_5 , V_707 ) &&
( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) ) {
T_1 V_734 ;
V_734 = V_5 -> V_156 ;
V_734 |= ( V_735 |
V_736 ) ;
F_55 ( V_153 , V_734 | V_159 |
V_737 , 40 ) ;
} else if ( F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_152 ) ||
F_30 ( V_5 ) == V_36 ) {
} else if ( ! ( F_23 ( V_5 , 5750_PLUS ) && F_23 ( V_5 , V_308 ) ) ) {
T_1 V_738 , V_739 ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) {
V_738 = ( V_735 |
V_736 |
V_159 ) ;
V_739 = V_738 | V_158 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_738 = V_157 ;
V_739 = V_738 | V_159 ;
} else {
V_738 = V_159 ;
V_739 = V_738 | V_158 ;
}
F_55 ( V_153 , V_5 -> V_156 | V_738 ,
40 ) ;
F_55 ( V_153 , V_5 -> V_156 | V_739 ,
40 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_740 ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) {
V_740 = ( V_735 |
V_736 |
V_158 ) ;
} else {
V_740 = V_158 ;
}
F_55 ( V_153 ,
V_5 -> V_156 | V_740 , 40 ) ;
}
}
if ( ! ( V_698 ) && ! F_23 ( V_5 , V_308 ) )
F_156 ( V_5 , V_568 ) ;
F_151 ( V_5 , true ) ;
if ( ( ! F_23 ( V_5 , V_264 ) ) &&
( ( F_145 ( V_5 ) == V_741 ) ||
( F_145 ( V_5 ) == V_742 ) ) ) {
T_1 V_7 = F_33 ( 0x7d00 ) ;
V_7 &= ~ ( ( 1 << 16 ) | ( 1 << 4 ) | ( 1 << 2 ) | ( 1 << 1 ) | 1 ) ;
F_46 ( 0x7d00 , V_7 ) ;
if ( ! F_23 ( V_5 , V_308 ) ) {
int V_75 ;
V_75 = F_157 ( V_5 ) ;
F_183 ( V_5 , V_653 ) ;
if ( ! V_75 )
F_158 ( V_5 ) ;
}
}
F_94 ( V_5 , V_110 ) ;
F_42 ( V_5 , V_110 ) ;
return 0 ;
}
static void F_202 ( struct V_4 * V_5 )
{
F_203 ( V_5 -> V_12 , F_23 ( V_5 , V_112 ) ) ;
F_198 ( V_5 -> V_12 , V_743 ) ;
}
static void F_204 ( struct V_4 * V_5 , T_1 V_7 , T_3 * V_372 , T_4 * V_376 )
{
switch ( V_7 & V_744 ) {
case V_745 :
* V_372 = V_373 ;
* V_376 = V_377 ;
break;
case V_746 :
* V_372 = V_373 ;
* V_376 = V_334 ;
break;
case V_747 :
* V_372 = V_332 ;
* V_376 = V_377 ;
break;
case V_748 :
* V_372 = V_332 ;
* V_376 = V_334 ;
break;
case V_749 :
* V_372 = V_331 ;
* V_376 = V_377 ;
break;
case V_750 :
* V_372 = V_331 ;
* V_376 = V_334 ;
break;
default:
if ( V_5 -> V_178 & V_179 ) {
* V_372 = ( V_7 & V_751 ) ? V_332 :
V_373 ;
* V_376 = ( V_7 & V_752 ) ? V_334 :
V_377 ;
break;
}
* V_372 = V_753 ;
* V_376 = V_754 ;
break;
}
}
static int F_205 ( struct V_4 * V_5 , T_1 V_755 , T_1 V_342 )
{
int V_75 = 0 ;
T_1 V_7 , V_756 ;
V_756 = V_757 ;
V_756 |= F_206 ( V_755 ) & V_758 ;
V_756 |= F_111 ( V_342 ) ;
V_75 = F_59 ( V_5 , V_303 , V_756 ) ;
if ( V_75 )
goto V_186;
if ( ! ( V_5 -> V_178 & V_392 ) ) {
V_756 = F_207 ( V_755 ) ;
if ( F_76 ( V_5 ) == V_759 ||
F_76 ( V_5 ) == V_760 )
V_756 |= V_494 | V_495 ;
V_75 = F_59 ( V_5 , V_180 , V_756 ) ;
if ( V_75 )
goto V_186;
}
if ( ! ( V_5 -> V_178 & V_338 ) )
goto V_186;
F_46 ( V_464 ,
F_33 ( V_464 ) & ~ V_475 ) ;
V_75 = F_66 ( V_5 , true ) ;
if ( ! V_75 ) {
T_1 V_761 ;
V_7 = 0 ;
if ( V_755 & V_709 )
V_7 |= V_762 ;
if ( V_755 & V_763 )
V_7 |= V_764 ;
if ( ! V_5 -> V_452 . V_462 ) {
V_7 = 0 ;
V_5 -> V_452 . V_463 = 0 ;
} else {
V_5 -> V_452 . V_463 = V_755 &
( V_709 |
V_763 ) ;
}
V_75 = F_60 ( V_5 , V_454 , V_461 , V_7 ) ;
if ( V_75 )
V_7 = 0 ;
switch ( F_30 ( V_5 ) ) {
case V_476 :
case V_765 :
case V_667 :
case V_477 :
if ( V_7 )
V_7 = V_478 |
V_479 |
V_766 ;
F_63 ( V_5 , V_474 , V_7 ) ;
case V_533 :
case V_767 :
if ( ! F_62 ( V_5 , V_768 , & V_7 ) )
F_63 ( V_5 , V_768 , V_7 |
V_769 ) ;
}
V_761 = F_66 ( V_5 , false ) ;
if ( ! V_75 )
V_75 = V_761 ;
}
V_186:
return V_75 ;
}
static void F_208 ( struct V_4 * V_5 )
{
if ( V_5 -> V_329 . V_352 == V_357 ||
( V_5 -> V_178 & V_399 ) ) {
T_1 V_341 , V_770 ;
if ( ( V_5 -> V_178 & V_399 ) &&
! ( V_5 -> V_178 & V_569 ) ) {
V_341 = V_706 |
V_710 ;
if ( F_23 ( V_5 , V_707 ) )
V_341 |= V_708 |
V_709 ;
if ( V_5 -> V_178 & V_771 ) {
if ( ! ( V_5 -> V_178 &
V_772 ) )
V_341 |= V_773 ;
V_341 |= V_763 ;
}
V_770 = V_336 | V_337 ;
} else {
V_341 = V_5 -> V_329 . V_398 ;
if ( V_5 -> V_178 & V_392 )
V_341 &= ~ ( V_773 |
V_763 ) ;
V_770 = V_5 -> V_329 . V_342 ;
}
F_205 ( V_5 , V_341 , V_770 ) ;
if ( ( V_5 -> V_178 & V_399 ) &&
( V_5 -> V_178 & V_569 ) ) {
return;
}
F_59 ( V_5 , V_204 ,
V_576 | V_577 ) ;
} else {
int V_42 ;
T_1 V_774 , V_775 ;
V_5 -> V_329 . V_330 = V_5 -> V_329 . V_372 ;
V_5 -> V_329 . V_333 = V_5 -> V_329 . V_376 ;
if ( F_30 ( V_5 ) == V_548 ) {
F_59 ( V_5 , V_303 , V_758 ) ;
}
V_774 = 0 ;
switch ( V_5 -> V_329 . V_372 ) {
default:
case V_373 :
break;
case V_332 :
V_774 |= V_776 ;
break;
case V_331 :
V_774 |= V_493 ;
break;
}
if ( V_5 -> V_329 . V_376 == V_334 )
V_774 |= V_492 ;
if ( ! F_57 ( V_5 , V_204 , & V_775 ) &&
( V_774 != V_775 ) ) {
F_59 ( V_5 , V_204 , V_777 ) ;
for ( V_42 = 0 ; V_42 < 1500 ; V_42 ++ ) {
T_1 V_596 ;
F_24 ( 10 ) ;
if ( F_57 ( V_5 , V_302 , & V_596 ) ||
F_57 ( V_5 , V_302 , & V_596 ) )
continue;
if ( ! ( V_596 & V_778 ) ) {
F_24 ( 40 ) ;
break;
}
}
F_59 ( V_5 , V_204 , V_774 ) ;
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
if ( ! ( V_7 & V_576 ) ) {
V_5 -> V_329 . V_352 = V_779 ;
V_5 -> V_329 . V_398 = 0 ;
F_85 ( V_5 , V_358 ) ;
V_75 = - V_210 ;
switch ( V_7 & ( V_493 | V_776 ) ) {
case 0 :
if ( V_5 -> V_178 & V_359 )
goto V_186;
V_5 -> V_329 . V_372 = V_373 ;
break;
case V_776 :
if ( V_5 -> V_178 & V_359 )
goto V_186;
V_5 -> V_329 . V_372 = V_332 ;
break;
case V_493 :
if ( ! ( V_5 -> V_178 & V_392 ) ) {
V_5 -> V_329 . V_372 = V_331 ;
break;
}
default:
goto V_186;
}
if ( V_7 & V_492 )
V_5 -> V_329 . V_376 = V_334 ;
else
V_5 -> V_329 . V_376 = V_377 ;
V_5 -> V_329 . V_342 = V_337 | V_336 ;
V_75 = 0 ;
goto V_186;
}
V_5 -> V_329 . V_352 = V_357 ;
V_5 -> V_329 . V_398 = V_705 ;
F_83 ( V_5 , V_358 ) ;
if ( ! ( V_5 -> V_178 & V_359 ) ) {
T_1 V_341 ;
V_75 = F_57 ( V_5 , V_303 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_341 = F_210 ( V_7 & V_758 ) ;
V_5 -> V_329 . V_398 |= V_341 | V_703 ;
V_5 -> V_329 . V_342 = F_103 ( V_7 ) ;
} else {
V_5 -> V_329 . V_398 |= V_780 ;
}
if ( ! ( V_5 -> V_178 & V_392 ) ) {
T_1 V_341 ;
if ( ! ( V_5 -> V_178 & V_359 ) ) {
V_75 = F_57 ( V_5 , V_180 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_341 = F_211 ( V_7 ) ;
} else {
V_75 = F_57 ( V_5 , V_303 , & V_7 ) ;
if ( V_75 )
goto V_186;
V_341 = F_105 ( V_7 ) ;
V_5 -> V_329 . V_342 = V_341 ;
V_7 &= ( V_781 | V_782 ) ;
V_341 = F_212 ( V_7 ) ;
}
V_5 -> V_329 . V_398 |= V_341 ;
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
struct V_451 V_452 ;
if ( ! ( V_5 -> V_178 & V_338 ) )
return true ;
F_131 ( V_5 , & V_452 ) ;
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
static bool F_215 ( struct V_4 * V_5 , T_1 * V_349 )
{
T_1 V_783 , V_784 , V_398 ;
V_398 = V_5 -> V_329 . V_398 ;
V_784 = F_206 ( V_398 ) & V_758 ;
V_783 = V_758 ;
if ( V_5 -> V_329 . V_333 == V_334 ) {
V_784 |= F_111 ( V_5 -> V_329 . V_342 ) ;
V_783 |= V_343 | V_344 ;
}
if ( F_57 ( V_5 , V_303 , V_349 ) )
return false ;
if ( ( * V_349 & V_783 ) != V_784 )
return false ;
if ( ! ( V_5 -> V_178 & V_392 ) ) {
T_1 V_785 ;
V_784 = F_207 ( V_398 ) ;
if ( F_57 ( V_5 , V_180 , & V_785 ) )
return false ;
if ( V_784 &&
( F_76 ( V_5 ) == V_759 ||
F_76 ( V_5 ) == V_760 ) ) {
V_784 |= V_494 | V_495 ;
V_785 &= ( V_786 | V_787 |
V_494 | V_495 ) ;
} else {
V_785 &= ( V_786 | V_787 ) ;
}
if ( V_785 != V_784 )
return false ;
}
return true ;
}
static bool F_216 ( struct V_4 * V_5 , T_1 * V_350 )
{
T_1 V_788 = 0 ;
if ( ! ( V_5 -> V_178 & V_392 ) ) {
T_1 V_7 ;
if ( F_57 ( V_5 , V_306 , & V_7 ) )
return false ;
V_788 = F_217 ( V_7 ) ;
}
if ( F_57 ( V_5 , V_304 , V_350 ) )
return false ;
V_788 |= F_218 ( * V_350 ) ;
V_5 -> V_329 . V_369 = V_788 ;
return true ;
}
static bool F_219 ( struct V_4 * V_5 , bool V_789 )
{
if ( V_789 != V_5 -> V_340 ) {
if ( V_789 ) {
F_220 ( V_5 -> V_111 ) ;
} else {
F_140 ( V_5 -> V_111 ) ;
if ( V_5 -> V_178 & V_305 )
V_5 -> V_178 &= ~ V_790 ;
}
F_99 ( V_5 ) ;
return true ;
}
return false ;
}
static void F_221 ( struct V_4 * V_5 )
{
F_46 ( V_791 , 0 ) ;
F_31 ( V_792 ,
V_793 |
V_794 |
V_795 |
V_796 ) ;
F_24 ( 40 ) ;
}
static void F_222 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_7 = V_797 |
V_798 ;
if ( F_76 ( V_5 ) == V_327 )
V_7 |= V_799 ;
F_31 ( V_800 , V_7 ) ;
F_31 ( V_473 ,
V_801 ) ;
V_7 = V_802 |
( V_5 -> V_452 . V_465 ? V_466 : 0 ) |
V_803 |
V_804 ;
if ( F_30 ( V_5 ) != V_476 )
V_7 |= V_805 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_806 ;
F_31 ( V_464 , V_5 -> V_452 . V_462 ? V_7 : 0 ) ;
F_31 ( V_468 ,
V_807 |
( V_5 -> V_452 . V_467 & 0xffff ) ) ;
F_31 ( V_808 ,
V_809 |
V_810 ) ;
}
static int F_223 ( struct V_4 * V_5 , bool V_811 )
{
bool V_469 ;
T_1 V_812 , V_7 ;
T_1 V_368 , V_369 ;
T_3 V_813 ;
T_4 V_814 ;
int V_42 , V_75 ;
F_221 ( V_5 ) ;
if ( ( V_5 -> V_164 & V_165 ) != 0 ) {
F_31 ( V_166 ,
( V_5 -> V_164 & ~ V_165 ) ) ;
F_24 ( 80 ) ;
}
F_65 ( V_5 , V_584 , 0 ) ;
if ( ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_501 ) &&
V_5 -> V_340 ) {
F_57 ( V_5 , V_302 , & V_812 ) ;
if ( ! F_57 ( V_5 , V_302 , & V_812 ) &&
! ( V_812 & V_778 ) )
V_811 = true ;
}
if ( V_811 )
F_143 ( V_5 ) ;
if ( ( V_5 -> V_216 & V_400 ) == V_401 ) {
F_57 ( V_5 , V_302 , & V_812 ) ;
if ( F_57 ( V_5 , V_302 , & V_812 ) ||
! F_23 ( V_5 , V_562 ) )
V_812 = 0 ;
if ( ! ( V_812 & V_778 ) ) {
V_75 = F_213 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_57 ( V_5 , V_302 , & V_812 ) ;
for ( V_42 = 0 ; V_42 < 1000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_302 , & V_812 ) &&
( V_812 & V_778 ) ) {
F_24 ( 40 ) ;
break;
}
}
if ( ( V_5 -> V_216 & V_815 ) ==
V_816 &&
! ( V_812 & V_778 ) &&
V_5 -> V_329 . V_330 == V_331 ) {
V_75 = F_143 ( V_5 ) ;
if ( ! V_75 )
V_75 = F_213 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
}
} else if ( F_76 ( V_5 ) == V_759 ||
F_76 ( V_5 ) == V_760 ) {
F_59 ( V_5 , 0x15 , 0x0a75 ) ;
F_59 ( V_5 , V_199 , 0x8c68 ) ;
F_59 ( V_5 , V_199 , 0x8d68 ) ;
F_59 ( V_5 , V_199 , 0x8c68 ) ;
}
F_57 ( V_5 , V_817 , & V_7 ) ;
F_57 ( V_5 , V_817 , & V_7 ) ;
if ( V_5 -> V_178 & V_818 )
F_59 ( V_5 , V_819 , ~ V_820 ) ;
else if ( ! ( V_5 -> V_178 & V_179 ) )
F_59 ( V_5 , V_819 , ~ 0 ) ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) {
if ( V_5 -> V_563 == V_821 )
F_59 ( V_5 , V_491 ,
V_822 ) ;
else
F_59 ( V_5 , V_491 , 0 ) ;
}
V_469 = false ;
V_813 = V_753 ;
V_814 = V_754 ;
V_5 -> V_178 &= ~ V_823 ;
V_5 -> V_329 . V_369 = 0 ;
if ( V_5 -> V_178 & V_824 ) {
V_75 = F_64 ( V_5 ,
V_825 ,
& V_7 ) ;
if ( ! V_75 && ! ( V_7 & ( 1 << 10 ) ) ) {
F_65 ( V_5 ,
V_825 ,
V_7 | ( 1 << 10 ) ) ;
goto V_826;
}
}
V_812 = 0 ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_57 ( V_5 , V_302 , & V_812 ) ;
if ( ! F_57 ( V_5 , V_302 , & V_812 ) &&
( V_812 & V_778 ) )
break;
F_24 ( 40 ) ;
}
if ( V_812 & V_778 ) {
T_1 V_827 , V_774 ;
F_57 ( V_5 , V_828 , & V_827 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
F_24 ( 10 ) ;
if ( ! F_57 ( V_5 , V_828 , & V_827 ) &&
V_827 )
break;
}
F_204 ( V_5 , V_827 ,
& V_813 ,
& V_814 ) ;
V_774 = 0 ;
for ( V_42 = 0 ; V_42 < 200 ; V_42 ++ ) {
F_57 ( V_5 , V_204 , & V_774 ) ;
if ( F_57 ( V_5 , V_204 , & V_774 ) )
continue;
if ( V_774 && V_774 != 0x7fff )
break;
F_24 ( 10 ) ;
}
V_368 = 0 ;
V_369 = 0 ;
V_5 -> V_329 . V_330 = V_813 ;
V_5 -> V_329 . V_333 = V_814 ;
if ( V_5 -> V_329 . V_352 == V_357 ) {
bool V_829 = F_214 ( V_5 ) ;
if ( ( V_774 & V_576 ) &&
V_829 &&
F_215 ( V_5 , & V_368 ) &&
F_216 ( V_5 , & V_369 ) )
V_469 = true ;
if ( ! V_829 &&
( V_5 -> V_178 & V_569 ) &&
! V_811 ) {
F_222 ( V_5 ) ;
F_143 ( V_5 ) ;
}
} else {
if ( ! ( V_774 & V_576 ) &&
V_5 -> V_329 . V_372 == V_813 &&
V_5 -> V_329 . V_376 == V_814 ) {
V_469 = true ;
}
}
if ( V_469 &&
V_5 -> V_329 . V_333 == V_334 ) {
T_1 V_161 , V_44 ;
if ( V_5 -> V_178 & V_179 ) {
V_161 = V_830 ;
V_44 = V_831 ;
} else {
V_161 = V_832 ;
V_44 = V_833 ;
}
if ( ! F_57 ( V_5 , V_161 , & V_7 ) && ( V_7 & V_44 ) )
V_5 -> V_178 |= V_823 ;
F_107 ( V_5 , V_368 , V_369 ) ;
}
}
V_826:
if ( ! V_469 || ( V_5 -> V_178 & V_399 ) ) {
F_208 ( V_5 ) ;
if ( F_23 ( V_5 , V_265 ) ) {
V_469 = true ;
V_813 = V_331 ;
V_814 = V_334 ;
V_5 -> V_329 . V_330 = V_813 ;
V_5 -> V_329 . V_333 = V_814 ;
}
F_57 ( V_5 , V_302 , & V_812 ) ;
if ( ( ! F_57 ( V_5 , V_302 , & V_812 ) && ( V_812 & V_778 ) ) ||
( V_5 -> V_367 & V_834 ) )
V_469 = true ;
}
V_5 -> V_367 &= ~ V_370 ;
if ( V_469 ) {
if ( V_5 -> V_329 . V_330 == V_332 ||
V_5 -> V_329 . V_330 == V_373 )
V_5 -> V_367 |= V_374 ;
else
V_5 -> V_367 |= V_375 ;
} else if ( V_5 -> V_178 & V_179 )
V_5 -> V_367 |= V_374 ;
else
V_5 -> V_367 |= V_375 ;
if ( F_23 ( V_5 , V_835 ) ) {
T_1 V_563 = F_33 ( V_727 ) ;
V_563 &= ~ ( V_836 | V_837 ) ;
if ( V_5 -> V_329 . V_330 == V_373 )
V_563 |= V_838 ;
else if ( V_5 -> V_329 . V_330 == V_332 )
V_563 |= ( V_838 |
V_837 ) ;
else if ( V_5 -> V_329 . V_330 == V_331 )
V_563 |= ( V_838 |
V_836 ) ;
F_46 ( V_727 , V_563 ) ;
F_24 ( 40 ) ;
}
V_5 -> V_367 &= ~ V_371 ;
if ( V_5 -> V_329 . V_333 == V_377 )
V_5 -> V_367 |= V_371 ;
if ( F_30 ( V_5 ) == V_536 ) {
if ( V_469 &&
F_153 ( V_5 , V_5 -> V_329 . V_330 ) )
V_5 -> V_367 |= V_725 ;
else
V_5 -> V_367 &= ~ V_725 ;
}
if ( ( V_5 -> V_216 & V_400 ) == V_565 &&
F_76 ( V_5 ) == V_839 ) {
V_5 -> V_164 |= V_165 ;
F_31 ( V_166 , V_5 -> V_164 ) ;
F_24 ( 80 ) ;
}
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
F_133 ( V_5 , V_469 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
F_31 ( V_791 , 0 ) ;
} else {
F_31 ( V_791 , V_840 ) ;
}
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_536 &&
V_469 &&
V_5 -> V_329 . V_330 == V_331 &&
( F_23 ( V_5 , V_841 ) || F_23 ( V_5 , V_842 ) ) ) {
F_24 ( 120 ) ;
F_31 ( V_792 ,
( V_793 |
V_794 ) ) ;
F_24 ( 40 ) ;
F_29 ( V_5 ,
V_314 ,
V_843 ) ;
}
if ( F_23 ( V_5 , V_699 ) ) {
if ( V_5 -> V_329 . V_330 == V_332 ||
V_5 -> V_329 . V_330 == V_373 )
F_224 ( V_5 -> V_12 , V_700 ,
V_701 ) ;
else
F_200 ( V_5 -> V_12 , V_700 ,
V_701 ) ;
}
F_219 ( V_5 , V_469 ) ;
return 0 ;
}
static int F_225 ( struct V_4 * V_5 ,
struct V_844 * V_845 )
{
T_3 V_342 ;
unsigned long V_846 ;
T_1 V_847 ;
int V_56 ;
if ( V_845 -> V_848 == V_849 ) {
V_845 -> V_850 = 0 ;
V_845 -> V_851 = 0 ;
V_845 -> V_852 = 0 ;
V_845 -> V_853 = 0 ;
V_845 -> V_854 = 0 ;
V_845 -> V_855 = 0 ;
V_845 -> V_856 = 0 ;
V_845 -> V_857 = 0 ;
}
V_845 -> V_852 ++ ;
if ( F_33 ( V_792 ) & V_858 ) {
V_847 = F_33 ( V_859 ) ;
if ( V_847 != V_845 -> V_853 ) {
V_845 -> V_853 = V_847 ;
V_845 -> V_855 = 0 ;
V_845 -> V_854 = 0 ;
} else {
if ( ++ V_845 -> V_854 > 1 ) {
V_845 -> V_855 = 1 ;
V_845 -> V_853 = V_847 ;
}
}
if ( V_847 & V_860 )
V_845 -> V_857 = 1 ;
else
V_845 -> V_857 = 0 ;
V_845 -> V_856 = 0 ;
} else {
V_845 -> V_856 = 1 ;
V_845 -> V_853 = 0 ;
V_845 -> V_854 = 0 ;
V_845 -> V_855 = 0 ;
V_845 -> V_857 = 0 ;
V_847 = 0 ;
}
V_845 -> V_850 = V_847 ;
V_56 = V_861 ;
switch ( V_845 -> V_848 ) {
case V_849 :
if ( V_845 -> V_10 & ( V_862 | V_863 ) )
V_845 -> V_848 = V_864 ;
case V_864 :
V_845 -> V_10 &= ~ ( V_865 | V_866 ) ;
if ( V_845 -> V_10 & V_862 ) {
V_845 -> V_851 = 0 ;
V_845 -> V_852 = 0 ;
V_845 -> V_853 = 0 ;
V_845 -> V_854 = 0 ;
V_845 -> V_855 = 0 ;
V_845 -> V_856 = 0 ;
V_845 -> V_857 = 0 ;
V_845 -> V_848 = V_867 ;
} else {
V_845 -> V_848 = V_868 ;
}
break;
case V_867 :
V_845 -> V_851 = V_845 -> V_852 ;
V_845 -> V_10 &= ~ ( V_869 ) ;
V_845 -> V_870 = 0 ;
F_46 ( V_871 , 0 ) ;
V_5 -> V_367 |= V_872 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
V_56 = V_873 ;
V_845 -> V_848 = V_874 ;
case V_874 :
V_846 = V_845 -> V_852 - V_845 -> V_851 ;
if ( V_846 > V_875 )
V_845 -> V_848 = V_876 ;
else
V_56 = V_873 ;
break;
case V_868 :
V_56 = V_877 ;
break;
case V_876 :
V_845 -> V_10 &= ~ ( V_878 ) ;
V_845 -> V_870 = V_879 ;
V_342 = F_104 ( V_5 -> V_329 . V_342 ) ;
if ( V_342 & V_347 )
V_845 -> V_870 |= V_880 ;
if ( V_342 & V_348 )
V_845 -> V_870 |= V_881 ;
F_46 ( V_871 , V_845 -> V_870 ) ;
V_5 -> V_367 |= V_872 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
V_845 -> V_848 = V_882 ;
break;
case V_882 :
if ( V_845 -> V_855 != 0 && V_845 -> V_850 != 0 )
V_845 -> V_848 = V_883 ;
break;
case V_883 :
V_845 -> V_870 |= V_860 ;
F_46 ( V_871 , V_845 -> V_870 ) ;
V_5 -> V_367 |= V_872 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
V_845 -> V_848 = V_884 ;
case V_884 :
if ( V_845 -> V_857 != 0 ) {
if ( ( V_845 -> V_850 & ~ V_860 ) ==
( V_845 -> V_853 & ~ V_860 ) ) {
V_845 -> V_848 = V_885 ;
} else {
V_845 -> V_848 = V_864 ;
}
} else if ( V_845 -> V_855 != 0 &&
V_845 -> V_850 == 0 ) {
V_845 -> V_848 = V_864 ;
}
break;
case V_885 :
if ( V_845 -> V_850 & V_886 ) {
V_56 = V_887 ;
break;
}
V_845 -> V_10 &= ~ ( V_888 |
V_889 |
V_890 |
V_891 |
V_892 |
V_893 |
V_894 |
V_895 |
V_896 ) ;
if ( V_845 -> V_850 & V_879 )
V_845 -> V_10 |= V_888 ;
if ( V_845 -> V_850 & V_897 )
V_845 -> V_10 |= V_889 ;
if ( V_845 -> V_850 & V_880 )
V_845 -> V_10 |= V_890 ;
if ( V_845 -> V_850 & V_881 )
V_845 -> V_10 |= V_891 ;
if ( V_845 -> V_850 & V_898 )
V_845 -> V_10 |= V_892 ;
if ( V_845 -> V_850 & V_899 )
V_845 -> V_10 |= V_893 ;
if ( V_845 -> V_850 & V_900 )
V_845 -> V_10 |= V_894 ;
V_845 -> V_851 = V_845 -> V_852 ;
V_845 -> V_10 ^= ( V_878 ) ;
if ( V_845 -> V_850 & 0x0008 )
V_845 -> V_10 |= V_895 ;
if ( V_845 -> V_850 & V_900 )
V_845 -> V_10 |= V_896 ;
V_845 -> V_10 |= V_866 ;
V_845 -> V_848 = V_901 ;
V_56 = V_873 ;
break;
case V_901 :
if ( V_845 -> V_855 != 0 &&
V_845 -> V_850 == 0 ) {
V_845 -> V_848 = V_864 ;
break;
}
V_846 = V_845 -> V_852 - V_845 -> V_851 ;
if ( V_846 > V_875 ) {
if ( ! ( V_845 -> V_10 & ( V_894 ) ) ) {
V_845 -> V_848 = V_902 ;
} else {
if ( ( V_845 -> V_870 & V_900 ) == 0 &&
! ( V_845 -> V_10 & V_896 ) ) {
V_845 -> V_848 = V_902 ;
} else {
V_56 = V_887 ;
}
}
}
break;
case V_902 :
V_845 -> V_851 = V_845 -> V_852 ;
V_5 -> V_367 &= ~ V_872 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
V_845 -> V_848 = V_903 ;
V_56 = V_873 ;
break;
case V_903 :
if ( V_845 -> V_855 != 0 &&
V_845 -> V_850 == 0 ) {
V_845 -> V_848 = V_864 ;
break;
}
V_846 = V_845 -> V_852 - V_845 -> V_851 ;
if ( V_846 > V_875 ) {
V_845 -> V_848 = V_904 ;
}
break;
case V_904 :
V_845 -> V_10 |= ( V_865 | V_905 ) ;
V_56 = V_877 ;
break;
case V_906 :
break;
case V_907 :
break;
default:
V_56 = V_887 ;
break;
}
return V_56 ;
}
static int F_226 ( struct V_4 * V_5 , T_1 * V_908 , T_1 * V_909 )
{
int V_625 = 0 ;
struct V_844 V_910 ;
int V_57 = V_887 ;
unsigned int V_911 ;
T_1 V_596 ;
F_31 ( V_871 , 0 ) ;
V_596 = V_5 -> V_367 & ~ V_370 ;
F_31 ( V_382 , V_596 | V_375 ) ;
F_24 ( 40 ) ;
F_31 ( V_382 , V_5 -> V_367 | V_872 ) ;
F_24 ( 40 ) ;
memset ( & V_910 , 0 , sizeof( V_910 ) ) ;
V_910 . V_10 |= V_862 ;
V_910 . V_848 = V_849 ;
V_910 . V_852 = 0 ;
V_911 = 0 ;
while ( ++ V_911 < 195000 ) {
V_57 = F_225 ( V_5 , & V_910 ) ;
if ( V_57 == V_877 || V_57 == V_887 )
break;
F_24 ( 1 ) ;
}
V_5 -> V_367 &= ~ V_872 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
* V_908 = V_910 . V_870 ;
* V_909 = V_910 . V_10 ;
if ( V_57 == V_877 &&
( V_910 . V_10 & ( V_865 | V_905 |
V_888 ) ) )
V_625 = 1 ;
return V_625 ;
}
static void F_227 ( struct V_4 * V_5 )
{
T_1 V_912 = F_33 ( V_792 ) ;
int V_42 ;
if ( F_23 ( V_5 , V_562 ) &&
! ( V_912 & V_913 ) )
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
static bool F_228 ( struct V_4 * V_5 , T_1 V_912 )
{
T_3 V_342 ;
bool V_469 ;
T_1 V_570 , V_914 ;
T_1 V_572 , V_915 ;
int V_916 , V_917 ;
V_572 = 0 ;
V_915 = 0 ;
V_916 = 0 ;
V_917 = 1 ;
V_469 = false ;
if ( F_76 ( V_5 ) != V_918 &&
F_76 ( V_5 ) != V_919 ) {
V_916 = 1 ;
if ( F_33 ( V_920 ) & V_921 )
V_917 = 0 ;
V_572 = F_33 ( V_573 ) & 0x00f06fff ;
}
V_570 = F_33 ( V_571 ) ;
if ( V_5 -> V_329 . V_352 != V_357 ) {
if ( V_570 & V_574 ) {
if ( V_916 ) {
T_1 V_7 = V_572 ;
if ( V_917 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_573 , V_7 ) ;
}
F_31 ( V_571 , V_922 ) ;
}
if ( V_912 & V_913 ) {
F_107 ( V_5 , 0 , 0 ) ;
V_469 = true ;
}
goto V_502;
}
V_915 = V_574 | V_922 ;
V_342 = F_104 ( V_5 -> V_329 . V_342 ) ;
if ( V_342 & V_347 )
V_915 |= V_923 ;
if ( V_342 & V_348 )
V_915 |= V_924 ;
if ( V_570 != V_915 ) {
if ( ( V_5 -> V_178 & V_790 ) &&
V_5 -> V_925 &&
( ( V_912 & ( V_913 |
V_858 ) ) ==
V_913 ) ) {
V_5 -> V_925 -- ;
V_469 = true ;
goto V_502;
}
V_926:
if ( V_916 )
F_31 ( V_573 , V_572 | 0xc011000 ) ;
F_31 ( V_571 , V_915 | V_575 ) ;
F_24 ( 5 ) ;
F_31 ( V_571 , V_915 ) ;
V_5 -> V_925 = V_927 ;
V_5 -> V_178 &= ~ V_790 ;
} else if ( V_912 & ( V_913 |
V_928 ) ) {
V_914 = F_33 ( V_260 ) ;
V_912 = F_33 ( V_792 ) ;
if ( ( V_914 & V_929 ) &&
( V_912 & V_913 ) ) {
T_1 V_930 = 0 , V_931 = 0 ;
if ( V_570 & V_923 )
V_930 |= V_347 ;
if ( V_570 & V_924 )
V_930 |= V_348 ;
if ( V_914 & V_932 )
V_931 |= V_933 ;
if ( V_914 & V_934 )
V_931 |= V_935 ;
V_5 -> V_329 . V_369 =
F_212 ( V_931 ) ;
F_107 ( V_5 , V_930 , V_931 ) ;
V_469 = true ;
V_5 -> V_925 = 0 ;
V_5 -> V_178 &= ~ V_790 ;
} else if ( ! ( V_914 & V_929 ) ) {
if ( V_5 -> V_925 )
V_5 -> V_925 -- ;
else {
if ( V_916 ) {
T_1 V_7 = V_572 ;
if ( V_917 )
V_7 |= 0xc010000 ;
else
V_7 |= 0x4010000 ;
F_31 ( V_573 , V_7 ) ;
}
F_31 ( V_571 , V_922 ) ;
F_24 ( 40 ) ;
V_912 = F_33 ( V_792 ) ;
if ( ( V_912 & V_913 ) &&
! ( V_912 & V_858 ) ) {
F_107 ( V_5 , 0 , 0 ) ;
V_469 = true ;
V_5 -> V_178 |=
V_790 ;
V_5 -> V_925 =
V_936 ;
} else
goto V_926;
}
}
} else {
V_5 -> V_925 = V_927 ;
V_5 -> V_178 &= ~ V_790 ;
}
V_502:
return V_469 ;
}
static bool F_229 ( struct V_4 * V_5 , T_1 V_912 )
{
bool V_469 = false ;
if ( ! ( V_912 & V_913 ) )
goto V_502;
if ( V_5 -> V_329 . V_352 == V_357 ) {
T_1 V_908 , V_909 ;
int V_42 ;
if ( F_226 ( V_5 , & V_908 , & V_909 ) ) {
T_1 V_930 = 0 , V_931 = 0 ;
if ( V_908 & V_880 )
V_930 |= V_347 ;
if ( V_908 & V_881 )
V_930 |= V_348 ;
if ( V_909 & V_890 )
V_931 |= V_933 ;
if ( V_909 & V_891 )
V_931 |= V_935 ;
V_5 -> V_329 . V_369 =
F_212 ( V_931 ) ;
F_107 ( V_5 , V_930 , V_931 ) ;
V_469 = true ;
}
for ( V_42 = 0 ; V_42 < 30 ; V_42 ++ ) {
F_24 ( 20 ) ;
F_31 ( V_792 ,
( V_793 |
V_794 ) ) ;
F_24 ( 40 ) ;
if ( ( F_33 ( V_792 ) &
( V_793 |
V_794 ) ) == 0 )
break;
}
V_912 = F_33 ( V_792 ) ;
if ( ! V_469 &&
( V_912 & V_913 ) &&
! ( V_912 & V_858 ) )
V_469 = true ;
} else {
F_107 ( V_5 , 0 , 0 ) ;
V_469 = true ;
F_31 ( V_382 , ( V_5 -> V_367 | V_872 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
}
V_502:
return V_469 ;
}
static int F_230 ( struct V_4 * V_5 , bool V_811 )
{
T_1 V_937 ;
T_3 V_938 ;
T_4 V_939 ;
T_1 V_912 ;
bool V_469 ;
int V_42 ;
V_937 = V_5 -> V_329 . V_335 ;
V_938 = V_5 -> V_329 . V_330 ;
V_939 = V_5 -> V_329 . V_333 ;
if ( ! F_23 ( V_5 , V_940 ) &&
V_5 -> V_340 &&
F_23 ( V_5 , V_562 ) ) {
V_912 = F_33 ( V_792 ) ;
V_912 &= ( V_913 |
V_928 |
V_794 |
V_858 ) ;
if ( V_912 == ( V_913 |
V_928 ) ) {
F_31 ( V_792 , ( V_793 |
V_794 ) ) ;
return 0 ;
}
}
F_31 ( V_871 , 0 ) ;
V_5 -> V_367 &= ~ ( V_370 | V_371 ) ;
V_5 -> V_367 |= V_726 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
if ( V_5 -> V_216 == V_941 )
F_227 ( V_5 ) ;
F_31 ( V_791 , V_840 ) ;
F_24 ( 40 ) ;
V_469 = false ;
V_5 -> V_329 . V_369 = 0 ;
V_912 = F_33 ( V_792 ) ;
if ( F_23 ( V_5 , V_940 ) )
V_469 = F_228 ( V_5 , V_912 ) ;
else
V_469 = F_229 ( V_5 , V_912 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 =
( V_135 |
( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & ~ V_144 ) ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_31 ( V_792 , ( V_793 |
V_794 ) ) ;
F_24 ( 5 ) ;
if ( ( F_33 ( V_792 ) & ( V_793 |
V_794 |
V_796 ) ) == 0 )
break;
}
V_912 = F_33 ( V_792 ) ;
if ( ( V_912 & V_913 ) == 0 ) {
V_469 = false ;
if ( V_5 -> V_329 . V_352 == V_357 &&
V_5 -> V_925 == 0 ) {
F_31 ( V_382 , ( V_5 -> V_367 |
V_872 ) ) ;
F_24 ( 1 ) ;
F_31 ( V_382 , V_5 -> V_367 ) ;
}
}
if ( V_469 ) {
V_5 -> V_329 . V_330 = V_331 ;
V_5 -> V_329 . V_333 = V_334 ;
F_46 ( V_727 , ( V_5 -> V_563 |
V_838 |
V_836 ) ) ;
} else {
V_5 -> V_329 . V_330 = V_753 ;
V_5 -> V_329 . V_333 = V_754 ;
F_46 ( V_727 , ( V_5 -> V_563 |
V_838 |
V_942 ) ) ;
}
if ( ! F_219 ( V_5 , V_469 ) ) {
T_1 V_943 = V_5 -> V_329 . V_335 ;
if ( V_937 != V_943 ||
V_938 != V_5 -> V_329 . V_330 ||
V_939 != V_5 -> V_329 . V_333 )
F_99 ( V_5 ) ;
}
return 0 ;
}
static int F_231 ( struct V_4 * V_5 , bool V_811 )
{
int V_75 = 0 ;
T_1 V_812 , V_774 ;
T_3 V_813 = V_753 ;
T_4 V_814 = V_754 ;
bool V_469 = false ;
T_1 V_930 , V_931 , V_944 ;
if ( ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) &&
! F_57 ( V_5 , V_945 , & V_944 ) &&
( V_944 & V_946 ) ) {
if ( V_811 )
F_143 ( V_5 ) ;
V_5 -> V_367 &= ~ V_370 ;
if ( ! ( V_944 & V_947 ) ) {
V_5 -> V_367 |= V_375 ;
} else {
V_469 = true ;
if ( V_944 & V_948 ) {
V_813 = V_331 ;
V_5 -> V_367 |= V_375 ;
} else if ( V_944 & V_949 ) {
V_813 = V_332 ;
V_5 -> V_367 |= V_374 ;
} else {
V_813 = V_373 ;
V_5 -> V_367 |= V_374 ;
}
if ( V_944 & V_950 )
V_814 = V_334 ;
else
V_814 = V_377 ;
}
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
F_221 ( V_5 ) ;
goto V_951;
}
V_5 -> V_367 |= V_375 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
F_221 ( V_5 ) ;
if ( V_811 )
F_143 ( V_5 ) ;
V_5 -> V_329 . V_369 = 0 ;
V_75 |= F_57 ( V_5 , V_302 , & V_812 ) ;
V_75 |= F_57 ( V_5 , V_302 , & V_812 ) ;
if ( F_30 ( V_5 ) == V_548 ) {
if ( F_33 ( V_952 ) & V_953 )
V_812 |= V_778 ;
else
V_812 &= ~ V_778 ;
}
V_75 |= F_57 ( V_5 , V_204 , & V_774 ) ;
if ( ( V_5 -> V_329 . V_352 == V_357 ) && ! V_811 &&
( V_5 -> V_178 & V_790 ) ) {
} else if ( V_5 -> V_329 . V_352 == V_357 ) {
T_1 V_341 , V_954 ;
V_75 |= F_57 ( V_5 , V_303 , & V_341 ) ;
V_954 = V_341 & ~ ( V_782 | V_781 |
V_347 |
V_348 |
V_955 ) ;
V_954 |= F_104 ( V_5 -> V_329 . V_342 ) ;
V_954 |= F_232 ( V_5 -> V_329 . V_398 ) ;
if ( ( V_954 != V_341 ) || ! ( V_774 & V_576 ) ) {
F_59 ( V_5 , V_303 , V_954 ) ;
V_774 |= V_576 | V_577 ;
F_59 ( V_5 , V_204 , V_774 ) ;
F_31 ( V_791 , V_840 ) ;
V_5 -> V_925 = V_956 ;
V_5 -> V_178 &= ~ V_790 ;
return V_75 ;
}
} else {
T_1 V_957 ;
V_774 &= ~ V_493 ;
V_957 = V_774 & ~ ( V_576 | V_492 ) ;
if ( V_5 -> V_329 . V_376 == V_334 )
V_957 |= V_492 ;
if ( V_957 != V_774 ) {
V_957 |= V_493 ;
if ( V_5 -> V_340 ) {
T_1 V_341 ;
V_75 |= F_57 ( V_5 , V_303 , & V_341 ) ;
V_341 &= ~ ( V_782 |
V_781 |
V_955 ) ;
F_59 ( V_5 , V_303 , V_341 ) ;
F_59 ( V_5 , V_204 , V_774 |
V_577 |
V_576 ) ;
F_24 ( 10 ) ;
F_139 ( V_5 ) ;
}
F_59 ( V_5 , V_204 , V_957 ) ;
V_774 = V_957 ;
V_75 |= F_57 ( V_5 , V_302 , & V_812 ) ;
V_75 |= F_57 ( V_5 , V_302 , & V_812 ) ;
if ( F_30 ( V_5 ) == V_548 ) {
if ( F_33 ( V_952 ) & V_953 )
V_812 |= V_778 ;
else
V_812 &= ~ V_778 ;
}
V_5 -> V_178 &= ~ V_790 ;
}
}
if ( V_812 & V_778 ) {
V_813 = V_331 ;
V_469 = true ;
if ( V_774 & V_492 )
V_814 = V_334 ;
else
V_814 = V_377 ;
V_930 = 0 ;
V_931 = 0 ;
if ( V_774 & V_576 ) {
T_1 V_958 ;
V_75 |= F_57 ( V_5 , V_303 , & V_930 ) ;
V_75 |= F_57 ( V_5 , V_304 , & V_931 ) ;
V_958 = V_930 & V_931 ;
if ( V_958 & ( V_781 |
V_782 ) ) {
if ( V_958 & V_782 )
V_814 = V_334 ;
else
V_814 = V_377 ;
V_5 -> V_329 . V_369 =
F_212 ( V_931 ) ;
} else if ( ! F_23 ( V_5 , 5780_CLASS ) ) {
} else {
V_469 = false ;
}
}
}
V_951:
if ( V_469 && V_814 == V_334 )
F_107 ( V_5 , V_930 , V_931 ) ;
V_5 -> V_367 &= ~ V_371 ;
if ( V_5 -> V_329 . V_333 == V_377 )
V_5 -> V_367 |= V_371 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
F_31 ( V_791 , V_840 ) ;
V_5 -> V_329 . V_330 = V_813 ;
V_5 -> V_329 . V_333 = V_814 ;
F_219 ( V_5 , V_469 ) ;
return V_75 ;
}
static void F_233 ( struct V_4 * V_5 )
{
if ( V_5 -> V_925 ) {
V_5 -> V_925 -- ;
return;
}
if ( ! V_5 -> V_340 &&
( V_5 -> V_329 . V_352 == V_357 ) ) {
T_1 V_774 ;
F_57 ( V_5 , V_204 , & V_774 ) ;
if ( V_774 & V_576 ) {
T_1 V_959 , V_960 ;
F_59 ( V_5 , V_199 , 0x7c00 ) ;
F_57 ( V_5 , V_199 , & V_959 ) ;
F_59 ( V_5 , V_189 ,
V_961 ) ;
F_57 ( V_5 , V_190 , & V_960 ) ;
F_57 ( V_5 , V_190 , & V_960 ) ;
if ( ( V_959 & 0x10 ) && ! ( V_960 & 0x20 ) ) {
V_774 &= ~ V_576 ;
V_774 |= V_493 | V_492 ;
F_59 ( V_5 , V_204 , V_774 ) ;
V_5 -> V_178 |= V_790 ;
}
}
} else if ( V_5 -> V_340 &&
( V_5 -> V_329 . V_352 == V_357 ) &&
( V_5 -> V_178 & V_790 ) ) {
T_1 V_960 ;
F_59 ( V_5 , V_189 ,
V_961 ) ;
F_57 ( V_5 , V_190 , & V_960 ) ;
if ( V_960 & 0x20 ) {
T_1 V_774 ;
F_57 ( V_5 , V_204 , & V_774 ) ;
F_59 ( V_5 , V_204 , V_774 | V_576 ) ;
V_5 -> V_178 &= ~ V_790 ;
}
}
}
static int F_201 ( struct V_4 * V_5 , bool V_811 )
{
T_1 V_7 ;
int V_75 ;
if ( V_5 -> V_178 & V_567 )
V_75 = F_230 ( V_5 , V_811 ) ;
else if ( V_5 -> V_178 & V_305 )
V_75 = F_231 ( V_5 , V_811 ) ;
else
V_75 = F_223 ( V_5 , V_811 ) ;
if ( F_145 ( V_5 ) == V_503 ) {
T_1 V_962 ;
V_7 = F_33 ( V_963 ) & V_964 ;
if ( V_7 == V_965 )
V_962 = 65 ;
else if ( V_7 == V_966 )
V_962 = 6 ;
else
V_962 = 12 ;
V_7 = F_33 ( V_497 ) & ~ V_967 ;
V_7 |= ( V_962 << V_968 ) ;
F_46 ( V_497 , V_7 ) ;
}
V_7 = ( 2 << V_387 ) |
( 6 << V_388 ) ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_767 )
V_7 |= F_33 ( V_386 ) &
( V_969 |
V_970 ) ;
if ( V_5 -> V_329 . V_330 == V_331 &&
V_5 -> V_329 . V_333 == V_377 )
F_46 ( V_386 , V_7 |
( 0xff << V_389 ) ) ;
else
F_46 ( V_386 , V_7 |
( 32 << V_389 ) ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
if ( V_5 -> V_340 ) {
F_46 ( V_971 ,
V_5 -> V_972 . V_973 ) ;
} else {
F_46 ( V_971 , 0 ) ;
}
}
if ( F_23 ( V_5 , V_974 ) ) {
V_7 = F_33 ( V_975 ) ;
if ( ! V_5 -> V_340 )
V_7 = ( V_7 & ~ V_976 ) |
V_5 -> V_977 ;
else
V_7 |= V_976 ;
F_46 ( V_975 , V_7 ) ;
}
return V_75 ;
}
static T_6 F_234 ( struct V_4 * V_5 )
{
T_6 V_978 = F_33 ( V_979 ) ;
return V_978 | ( T_6 ) F_33 ( V_980 ) << 32 ;
}
static void F_235 ( struct V_4 * V_5 , T_6 V_981 )
{
T_1 V_982 = F_33 ( V_983 ) ;
F_46 ( V_983 , V_982 | V_984 ) ;
F_46 ( V_979 , V_981 & 0xffffffff ) ;
F_46 ( V_980 , V_981 >> 32 ) ;
F_31 ( V_983 , V_982 | V_985 ) ;
}
static int F_236 ( struct V_364 * V_111 , struct V_986 * V_987 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
V_987 -> V_988 = V_989 |
V_990 |
V_991 ;
if ( F_23 ( V_5 , V_992 ) ) {
V_987 -> V_988 |= V_993 |
V_994 |
V_995 ;
}
if ( V_5 -> V_996 )
V_987 -> V_997 = F_237 ( V_5 -> V_996 ) ;
else
V_987 -> V_997 = - 1 ;
V_987 -> V_998 = ( 1 << V_999 ) | ( 1 << V_1000 ) ;
V_987 -> V_1001 = ( 1 << V_1002 ) |
( 1 << V_1003 ) |
( 1 << V_1004 ) |
( 1 << V_1005 ) ;
return 0 ;
}
static int F_238 ( struct V_1006 * V_1007 , T_7 V_1008 )
{
struct V_4 * V_5 = F_239 ( V_1007 , struct V_4 , V_1009 ) ;
bool V_1010 = false ;
T_1 V_1011 = 0 ;
if ( V_1008 < 0 ) {
V_1010 = true ;
V_1008 = - V_1008 ;
}
V_1011 = F_240 ( ( T_6 ) V_1008 * ( 1 << 24 ) , 1000000000ULL ) &
V_1012 ;
F_241 ( V_5 , 0 ) ;
if ( V_1011 )
F_46 ( V_1013 ,
V_1014 |
( V_1010 ? V_1015 : 0 ) | V_1011 ) ;
else
F_46 ( V_1013 , 0 ) ;
F_242 ( V_5 ) ;
return 0 ;
}
static int F_243 ( struct V_1006 * V_1007 , T_8 V_846 )
{
struct V_4 * V_5 = F_239 ( V_1007 , struct V_4 , V_1009 ) ;
F_241 ( V_5 , 0 ) ;
V_5 -> V_1016 += V_846 ;
F_242 ( V_5 ) ;
return 0 ;
}
static int F_244 ( struct V_1006 * V_1007 , struct V_1017 * V_1018 )
{
T_6 V_1019 ;
struct V_4 * V_5 = F_239 ( V_1007 , struct V_4 , V_1009 ) ;
F_241 ( V_5 , 0 ) ;
V_1019 = F_234 ( V_5 ) ;
V_1019 += V_5 -> V_1016 ;
F_242 ( V_5 ) ;
* V_1018 = F_245 ( V_1019 ) ;
return 0 ;
}
static int F_246 ( struct V_1006 * V_1007 ,
const struct V_1017 * V_1018 )
{
T_6 V_1019 ;
struct V_4 * V_5 = F_239 ( V_1007 , struct V_4 , V_1009 ) ;
V_1019 = F_247 ( V_1018 ) ;
F_241 ( V_5 , 0 ) ;
F_235 ( V_5 , V_1019 ) ;
V_5 -> V_1016 = 0 ;
F_242 ( V_5 ) ;
return 0 ;
}
static int F_248 ( struct V_1006 * V_1007 ,
struct V_1020 * V_1021 , int V_1022 )
{
struct V_4 * V_5 = F_239 ( V_1007 , struct V_4 , V_1009 ) ;
T_1 V_982 ;
int V_1023 = 0 ;
switch ( V_1021 -> type ) {
case V_1024 :
if ( V_1021 -> V_1025 . V_686 != 0 )
return - V_64 ;
F_241 ( V_5 , 0 ) ;
V_982 = F_33 ( V_983 ) ;
V_982 &= ~ V_1026 ;
if ( V_1022 ) {
T_6 V_1027 ;
V_1027 = V_1021 -> V_1025 . V_1028 . V_1029 * 1000000000ULL +
V_1021 -> V_1025 . V_1028 . V_1027 ;
if ( V_1021 -> V_1025 . V_1030 . V_1029 || V_1021 -> V_1025 . V_1030 . V_1027 ) {
F_142 ( V_5 -> V_111 ,
L_28 ) ;
V_1023 = - V_64 ;
goto V_1031;
}
if ( V_1027 & ( 1ULL << 63 ) ) {
F_142 ( V_5 -> V_111 ,
L_29 ) ;
V_1023 = - V_64 ;
goto V_1031;
}
F_46 ( V_1032 , ( V_1027 & 0xffffffff ) ) ;
F_46 ( V_1033 ,
V_1034 |
( ( V_1027 >> 32 ) & V_1035 ) ) ;
F_46 ( V_983 ,
V_982 | V_1036 ) ;
} else {
F_46 ( V_1033 , 0 ) ;
F_46 ( V_983 , V_982 ) ;
}
V_1031:
F_242 ( V_5 ) ;
return V_1023 ;
default:
break;
}
return - V_1037 ;
}
static void F_249 ( struct V_4 * V_5 , T_6 V_1038 ,
struct V_1039 * V_1040 )
{
memset ( V_1040 , 0 , sizeof( struct V_1039 ) ) ;
V_1040 -> V_1041 = F_250 ( ( V_1038 & V_1042 ) +
V_5 -> V_1016 ) ;
}
static void F_251 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_992 ) )
return;
F_235 ( V_5 , F_252 ( F_253 () ) ) ;
V_5 -> V_1016 = 0 ;
V_5 -> V_1009 = V_1043 ;
}
static void F_254 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_992 ) )
return;
F_235 ( V_5 , F_252 ( F_253 () ) + V_5 -> V_1016 ) ;
V_5 -> V_1016 = 0 ;
}
static void F_255 ( struct V_4 * V_5 )
{
if ( ! F_23 ( V_5 , V_992 ) || ! V_5 -> V_996 )
return;
F_256 ( V_5 -> V_996 ) ;
V_5 -> V_996 = NULL ;
V_5 -> V_1016 = 0 ;
}
static inline int F_257 ( struct V_4 * V_5 )
{
return V_5 -> V_125 ;
}
static inline void F_258 ( struct V_4 * V_5 , T_1 * V_1044 , T_1 V_6 , T_1 V_74 )
{
int V_42 ;
V_1044 = ( T_1 * ) ( ( T_4 * ) V_1044 + V_6 ) ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += sizeof( T_1 ) )
* V_1044 ++ = F_33 ( V_6 + V_42 ) ;
}
static void F_259 ( struct V_4 * V_5 , T_1 * V_8 )
{
F_258 ( V_5 , V_8 , V_1045 , 0xb0 ) ;
F_258 ( V_5 , V_8 , V_20 , 0x200 ) ;
F_258 ( V_5 , V_8 , V_382 , 0x4f0 ) ;
F_258 ( V_5 , V_8 , V_1046 , 0xe0 ) ;
F_258 ( V_5 , V_8 , V_1047 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1048 , 0x80 ) ;
F_258 ( V_5 , V_8 , V_1049 , 0x48 ) ;
F_258 ( V_5 , V_8 , V_1050 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1051 , 0x20 ) ;
F_258 ( V_5 , V_8 , V_1052 , 0x15c ) ;
F_258 ( V_5 , V_8 , V_1053 , 0x0c ) ;
F_258 ( V_5 , V_8 , V_1054 , 0x3c ) ;
F_258 ( V_5 , V_8 , V_1055 , 0x44 ) ;
F_258 ( V_5 , V_8 , V_1056 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1057 , 0x20 ) ;
F_258 ( V_5 , V_8 , V_1058 , 0x14 ) ;
F_258 ( V_5 , V_8 , V_1059 , 0x08 ) ;
F_258 ( V_5 , V_8 , V_1060 , 0x08 ) ;
F_258 ( V_5 , V_8 , V_138 , 0x100 ) ;
if ( F_23 ( V_5 , V_1061 ) )
F_258 ( V_5 , V_8 , V_1062 , 0x180 ) ;
F_258 ( V_5 , V_8 , V_1063 , 0x10 ) ;
F_258 ( V_5 , V_8 , V_1064 , 0x58 ) ;
F_258 ( V_5 , V_8 , V_1065 , 0x08 ) ;
F_258 ( V_5 , V_8 , V_1066 , 0x08 ) ;
F_258 ( V_5 , V_8 , V_1067 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1068 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1069 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_677 , 0x04 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_258 ( V_5 , V_8 , V_1070 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1071 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_1072 , 0x04 ) ;
}
F_258 ( V_5 , V_8 , V_1073 , 0x110 ) ;
F_258 ( V_5 , V_8 , V_1074 , 0x120 ) ;
F_258 ( V_5 , V_8 , V_1075 , 0x0c ) ;
F_258 ( V_5 , V_8 , V_1076 , 0x04 ) ;
F_258 ( V_5 , V_8 , V_646 , 0x4c ) ;
if ( F_23 ( V_5 , V_585 ) )
F_258 ( V_5 , V_8 , V_607 , 0x24 ) ;
}
static void F_260 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 * V_8 ;
V_8 = F_261 ( V_1077 , V_1078 ) ;
if ( ! V_8 )
return;
if ( F_23 ( V_5 , V_1079 ) ) {
for ( V_42 = 0 ; V_42 < V_1080 ; V_42 += sizeof( T_1 ) )
V_8 [ V_42 / sizeof( T_1 ) ] = F_33 ( V_42 ) ;
} else
F_259 ( V_5 , V_8 ) ;
for ( V_42 = 0 ; V_42 < V_1077 / sizeof( T_1 ) ; V_42 += 4 ) {
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
V_131 -> V_134 -> V_1081 ,
V_131 -> V_134 -> V_1082 ,
V_131 -> V_134 -> V_1083 ,
V_131 -> V_134 -> V_1084 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_1085 ,
V_131 -> V_134 -> V_145 [ 0 ] . V_146 ) ;
F_185 ( V_5 -> V_111 ,
L_32 ,
V_42 ,
V_131 -> V_132 , V_131 -> V_1086 ,
V_131 -> V_1087 , V_131 -> V_147 , V_131 -> V_1088 ,
V_131 -> V_149 ,
V_131 -> V_1089 . V_1090 ,
V_131 -> V_1089 . V_1091 ,
V_131 -> V_1089 . V_1092 ,
V_131 -> V_1089 . V_1093 ) ;
}
}
static void F_262 ( struct V_4 * V_5 )
{
F_184 ( F_23 ( V_5 , V_31 ) ||
V_5 -> V_1094 == F_20 ) ;
F_142 ( V_5 -> V_111 ,
L_33
L_34
L_35
L_36 ) ;
F_83 ( V_5 , V_1095 ) ;
}
static inline T_1 F_263 ( struct V_130 * V_131 )
{
F_264 () ;
return V_131 -> V_1088 -
( ( V_131 -> V_1087 - V_131 -> V_147 ) & ( V_1096 - 1 ) ) ;
}
static void F_265 ( struct V_130 * V_131 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1097 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
T_1 V_1098 = V_131 -> V_147 ;
struct V_1099 * V_1100 ;
int V_686 = V_131 - V_5 -> V_123 ;
unsigned int V_1101 = 0 , V_1102 = 0 ;
if ( F_23 ( V_5 , V_1103 ) )
V_686 -- ;
V_1100 = F_266 ( V_5 -> V_111 , V_686 ) ;
while ( V_1098 != V_1097 ) {
struct V_1104 * V_1105 = & V_131 -> V_1106 [ V_1098 ] ;
struct V_1107 * V_1108 = V_1105 -> V_1108 ;
int V_42 , V_1109 = 0 ;
if ( F_267 ( V_1108 == NULL ) ) {
F_262 ( V_5 ) ;
return;
}
if ( V_131 -> V_1110 [ V_1098 ] . V_1111 & V_1112 ) {
struct V_1039 V_1040 ;
T_6 V_1038 = F_33 ( V_1113 ) ;
V_1038 |= ( T_6 ) F_33 ( V_1114 ) << 32 ;
F_249 ( V_5 , V_1038 , & V_1040 ) ;
F_268 ( V_1108 , & V_1040 ) ;
}
F_269 ( V_5 -> V_12 ,
F_270 ( V_1105 , V_1115 ) ,
F_271 ( V_1108 ) ,
V_1116 ) ;
V_1105 -> V_1108 = NULL ;
while ( V_1105 -> V_1117 ) {
V_1105 -> V_1117 = false ;
V_1098 = F_272 ( V_1098 ) ;
V_1105 = & V_131 -> V_1106 [ V_1098 ] ;
}
V_1098 = F_272 ( V_1098 ) ;
for ( V_42 = 0 ; V_42 < F_273 ( V_1108 ) -> V_1118 ; V_42 ++ ) {
V_1105 = & V_131 -> V_1106 [ V_1098 ] ;
if ( F_267 ( V_1105 -> V_1108 != NULL || V_1098 == V_1097 ) )
V_1109 = 1 ;
F_274 ( V_5 -> V_12 ,
F_270 ( V_1105 , V_1115 ) ,
F_275 ( & F_273 ( V_1108 ) -> V_1119 [ V_42 ] ) ,
V_1116 ) ;
while ( V_1105 -> V_1117 ) {
V_1105 -> V_1117 = false ;
V_1098 = F_272 ( V_1098 ) ;
V_1105 = & V_131 -> V_1106 [ V_1098 ] ;
}
V_1098 = F_272 ( V_1098 ) ;
}
V_1101 ++ ;
V_1102 += V_1108 -> V_74 ;
F_276 ( V_1108 ) ;
if ( F_267 ( V_1109 ) ) {
F_262 ( V_5 ) ;
return;
}
}
F_277 ( V_1100 , V_1101 , V_1102 ) ;
V_131 -> V_147 = V_1098 ;
F_278 () ;
if ( F_267 ( F_279 ( V_1100 ) &&
( F_263 ( V_131 ) > F_280 ( V_131 ) ) ) ) {
F_281 ( V_1100 , F_282 () ) ;
if ( F_279 ( V_1100 ) &&
( F_263 ( V_131 ) > F_280 ( V_131 ) ) )
F_283 ( V_1100 ) ;
F_284 ( V_1100 ) ;
}
}
static void F_285 ( bool V_1120 , void * V_72 )
{
if ( V_1120 )
F_286 ( V_72 ) ;
else
F_175 ( V_72 ) ;
}
static void F_287 ( struct V_4 * V_5 , struct V_1121 * V_1105 , T_1 V_1122 )
{
unsigned int V_1123 = F_288 ( V_1122 + F_289 ( V_5 ) ) +
F_288 ( sizeof( struct V_1124 ) ) ;
if ( ! V_1105 -> V_72 )
return;
F_269 ( V_5 -> V_12 , F_270 ( V_1105 , V_1115 ) ,
V_1122 , V_1125 ) ;
F_285 ( V_1123 <= V_1126 , V_1105 -> V_72 ) ;
V_1105 -> V_72 = NULL ;
}
static int F_290 ( struct V_4 * V_5 , struct V_1127 * V_1128 ,
T_1 V_1129 , T_1 V_1130 ,
unsigned int * V_1131 )
{
struct V_1132 * V_1133 ;
struct V_1121 * V_1134 ;
T_4 * V_72 ;
T_9 V_1115 ;
int V_1123 , V_1135 , V_1136 ;
switch ( V_1129 ) {
case V_1137 :
V_1136 = V_1130 & V_5 -> V_1138 ;
V_1133 = & V_1128 -> V_1139 [ V_1136 ] ;
V_1134 = & V_1128 -> V_1140 [ V_1136 ] ;
V_1135 = V_5 -> V_1141 ;
break;
case V_1142 :
V_1136 = V_1130 & V_5 -> V_1143 ;
V_1133 = & V_1128 -> V_1144 [ V_1136 ] . V_1145 ;
V_1134 = & V_1128 -> V_1146 [ V_1136 ] ;
V_1135 = V_1147 ;
break;
default:
return - V_64 ;
}
V_1123 = F_288 ( V_1135 + F_289 ( V_5 ) ) +
F_288 ( sizeof( struct V_1124 ) ) ;
if ( V_1123 <= V_1126 ) {
V_72 = F_291 ( V_1123 ) ;
* V_1131 = V_1123 ;
} else {
V_72 = F_174 ( V_1123 , V_1078 ) ;
* V_1131 = 0 ;
}
if ( ! V_72 )
return - V_268 ;
V_1115 = F_292 ( V_5 -> V_12 ,
V_72 + F_289 ( V_5 ) ,
V_1135 ,
V_1125 ) ;
if ( F_267 ( F_293 ( V_5 -> V_12 , V_1115 ) ) ) {
F_285 ( V_1123 <= V_1126 , V_72 ) ;
return - V_210 ;
}
V_1134 -> V_72 = V_72 ;
F_294 ( V_1134 , V_1115 , V_1115 ) ;
V_1133 -> V_1148 = ( ( T_6 ) V_1115 >> 32 ) ;
V_1133 -> V_1149 = ( ( T_6 ) V_1115 & 0xffffffff ) ;
return V_1135 ;
}
static void F_295 ( struct V_130 * V_131 ,
struct V_1127 * V_1150 ,
T_1 V_1129 , int V_1151 ,
T_1 V_1130 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_1132 * V_1152 , * V_1153 ;
struct V_1121 * V_1154 , * V_1155 ;
struct V_1127 * V_1156 = & V_5 -> V_123 [ 0 ] . V_1089 ;
int V_1136 ;
switch ( V_1129 ) {
case V_1137 :
V_1136 = V_1130 & V_5 -> V_1138 ;
V_1153 = & V_1150 -> V_1139 [ V_1136 ] ;
V_1155 = & V_1150 -> V_1140 [ V_1136 ] ;
V_1152 = & V_1156 -> V_1139 [ V_1151 ] ;
V_1154 = & V_1156 -> V_1140 [ V_1151 ] ;
break;
case V_1142 :
V_1136 = V_1130 & V_5 -> V_1143 ;
V_1153 = & V_1150 -> V_1144 [ V_1136 ] . V_1145 ;
V_1155 = & V_1150 -> V_1146 [ V_1136 ] ;
V_1152 = & V_1156 -> V_1144 [ V_1151 ] . V_1145 ;
V_1154 = & V_1156 -> V_1146 [ V_1151 ] ;
break;
default:
return;
}
V_1155 -> V_72 = V_1154 -> V_72 ;
F_294 ( V_1155 , V_1115 ,
F_270 ( V_1154 , V_1115 ) ) ;
V_1153 -> V_1148 = V_1152 -> V_1148 ;
V_1153 -> V_1149 = V_1152 -> V_1149 ;
F_296 () ;
V_1154 -> V_72 = NULL ;
}
static int F_297 ( struct V_130 * V_131 , int V_1157 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
T_1 V_1158 , V_1159 = 0 ;
T_1 V_1160 , V_1161 ;
T_1 V_1098 = V_131 -> V_149 ;
T_3 V_1097 ;
int V_1162 ;
struct V_1127 * V_1128 = & V_131 -> V_1089 ;
V_1097 = * ( V_131 -> V_148 ) ;
F_298 () ;
V_1158 = 0 ;
V_1162 = 0 ;
V_1160 = V_1128 -> V_1090 ;
V_1161 = V_1128 -> V_1092 ;
while ( V_1098 != V_1097 && V_1157 > 0 ) {
struct V_1121 * V_1105 ;
struct V_1132 * V_1133 = & V_131 -> V_1163 [ V_1098 ] ;
unsigned int V_74 ;
struct V_1107 * V_1108 ;
T_9 V_1164 ;
T_1 V_1129 , V_1165 , * V_1166 ;
T_4 * V_72 ;
T_6 V_1167 = 0 ;
V_1165 = V_1133 -> V_1168 & V_1169 ;
V_1129 = V_1133 -> V_1168 & V_1170 ;
if ( V_1129 == V_1137 ) {
V_1105 = & V_5 -> V_123 [ 0 ] . V_1089 . V_1140 [ V_1165 ] ;
V_1164 = F_270 ( V_1105 , V_1115 ) ;
V_72 = V_1105 -> V_72 ;
V_1166 = & V_1160 ;
V_1159 ++ ;
} else if ( V_1129 == V_1142 ) {
V_1105 = & V_5 -> V_123 [ 0 ] . V_1089 . V_1146 [ V_1165 ] ;
V_1164 = F_270 ( V_1105 , V_1115 ) ;
V_72 = V_1105 -> V_72 ;
V_1166 = & V_1161 ;
} else
goto V_1171;
V_1158 |= V_1129 ;
if ( V_1133 -> V_1172 & V_1173 ) {
V_1174:
F_295 ( V_131 , V_1128 , V_1129 ,
V_1165 , * V_1166 ) ;
V_1175:
V_5 -> V_1176 ++ ;
goto V_1177;
}
F_299 ( V_72 + F_289 ( V_5 ) ) ;
V_74 = ( ( V_1133 -> V_1178 & V_1179 ) >> V_1180 ) -
V_1181 ;
if ( ( V_1133 -> V_1182 & V_1183 ) ==
V_1184 ||
( V_1133 -> V_1182 & V_1183 ) ==
V_1185 ) {
V_1167 = F_33 ( V_1186 ) ;
V_1167 |= ( T_6 ) F_33 ( V_1187 ) << 32 ;
}
if ( V_74 > F_300 ( V_5 ) ) {
int V_1123 ;
unsigned int V_1131 ;
V_1123 = F_290 ( V_5 , V_1128 , V_1129 ,
* V_1166 , & V_1131 ) ;
if ( V_1123 < 0 )
goto V_1174;
F_269 ( V_5 -> V_12 , V_1164 , V_1123 ,
V_1125 ) ;
F_296 () ;
V_1105 -> V_72 = NULL ;
V_1108 = F_301 ( V_72 , V_1131 ) ;
if ( ! V_1108 ) {
F_285 ( V_1131 != 0 , V_72 ) ;
goto V_1175;
}
F_302 ( V_1108 , F_289 ( V_5 ) ) ;
} else {
F_295 ( V_131 , V_1128 , V_1129 ,
V_1165 , * V_1166 ) ;
V_1108 = F_303 ( V_5 -> V_111 ,
V_74 + V_1188 ) ;
if ( V_1108 == NULL )
goto V_1175;
F_302 ( V_1108 , V_1188 ) ;
F_304 ( V_5 -> V_12 , V_1164 , V_74 , V_1125 ) ;
memcpy ( V_1108 -> V_72 ,
V_72 + F_289 ( V_5 ) ,
V_74 ) ;
F_305 ( V_5 -> V_12 , V_1164 , V_74 , V_1125 ) ;
}
F_306 ( V_1108 , V_74 ) ;
if ( V_1167 )
F_249 ( V_5 , V_1167 ,
F_307 ( V_1108 ) ) ;
if ( ( V_5 -> V_111 -> V_1189 & V_1190 ) &&
( V_1133 -> V_1182 & V_1191 ) &&
( ( ( V_1133 -> V_1192 & V_1193 )
>> V_1194 ) == 0xffff ) )
V_1108 -> V_1195 = V_1196 ;
else
F_308 ( V_1108 ) ;
V_1108 -> V_1197 = F_309 ( V_1108 , V_5 -> V_111 ) ;
if ( V_74 > ( V_5 -> V_111 -> V_1198 + V_1199 ) &&
V_1108 -> V_1197 != F_310 ( V_1200 ) &&
V_1108 -> V_1197 != F_310 ( V_1201 ) ) {
F_276 ( V_1108 ) ;
goto V_1175;
}
if ( V_1133 -> V_1182 & V_1202 &&
! ( V_5 -> V_354 & V_1203 ) )
F_311 ( V_1108 , F_310 ( V_1200 ) ,
V_1133 -> V_1172 & V_1204 ) ;
F_312 ( & V_131 -> V_123 , V_1108 ) ;
V_1162 ++ ;
V_1157 -- ;
V_1177:
( * V_1166 ) ++ ;
if ( F_267 ( V_1159 >= V_5 -> V_1205 ) ) {
V_1128 -> V_1090 = V_1160 &
V_5 -> V_1138 ;
F_313 ( V_18 ,
V_1128 -> V_1090 ) ;
V_1158 &= ~ V_1137 ;
V_1159 = 0 ;
}
V_1171:
V_1098 ++ ;
V_1098 &= V_5 -> V_1206 ;
if ( V_1098 == V_1097 ) {
V_1097 = * ( V_131 -> V_148 ) ;
F_298 () ;
}
}
V_131 -> V_149 = V_1098 ;
F_313 ( V_131 -> V_1207 , V_1098 ) ;
if ( ! F_23 ( V_5 , V_1208 ) ) {
F_49 () ;
if ( V_1158 & V_1137 ) {
V_1128 -> V_1090 = V_1160 &
V_5 -> V_1138 ;
F_313 ( V_18 ,
V_1128 -> V_1090 ) ;
}
if ( V_1158 & V_1142 ) {
V_1128 -> V_1092 = V_1161 &
V_5 -> V_1143 ;
F_313 ( V_1209 ,
V_1128 -> V_1092 ) ;
}
F_53 () ;
} else if ( V_1158 ) {
F_296 () ;
V_1128 -> V_1090 = V_1160 & V_5 -> V_1138 ;
V_1128 -> V_1092 = V_1161 & V_5 -> V_1143 ;
if ( V_131 != & V_5 -> V_123 [ 1 ] ) {
V_5 -> V_1210 = true ;
F_314 ( & V_5 -> V_123 [ 1 ] . V_123 ) ;
}
}
return V_1162 ;
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
F_31 ( V_792 ,
( V_793 |
V_794 |
V_795 |
V_796 ) ) ;
F_24 ( 40 ) ;
} else
F_201 ( V_5 , false ) ;
F_317 ( & V_5 -> V_209 ) ;
}
}
}
static int F_318 ( struct V_4 * V_5 ,
struct V_1127 * V_1150 ,
struct V_1127 * V_1156 )
{
T_1 V_1211 , V_1212 , V_1213 , V_1214 ;
int V_42 , V_75 = 0 ;
while ( 1 ) {
V_1214 = V_1156 -> V_1090 ;
F_319 () ;
if ( V_1156 -> V_1091 == V_1214 )
break;
if ( V_1156 -> V_1091 < V_1214 )
V_1213 = V_1214 - V_1156 -> V_1091 ;
else
V_1213 = V_5 -> V_1138 + 1 -
V_1156 -> V_1091 ;
V_1213 = F_320 ( V_1213 ,
V_5 -> V_1138 + 1 - V_1150 -> V_1090 ) ;
V_1211 = V_1156 -> V_1091 ;
V_1212 = V_1150 -> V_1090 ;
for ( V_42 = V_1212 ; V_42 < V_1212 + V_1213 ; V_42 ++ ) {
if ( V_1150 -> V_1140 [ V_42 ] . V_72 ) {
V_1213 = V_42 - V_1212 ;
V_75 = - V_1215 ;
break;
}
}
if ( ! V_1213 )
break;
F_319 () ;
memcpy ( & V_1150 -> V_1140 [ V_1212 ] ,
& V_1156 -> V_1140 [ V_1211 ] ,
V_1213 * sizeof( struct V_1121 ) ) ;
for ( V_42 = 0 ; V_42 < V_1213 ; V_42 ++ , V_1212 ++ , V_1211 ++ ) {
struct V_1132 * V_1216 , * V_1217 ;
V_1216 = & V_1156 -> V_1139 [ V_1211 ] ;
V_1217 = & V_1150 -> V_1139 [ V_1212 ] ;
V_1217 -> V_1148 = V_1216 -> V_1148 ;
V_1217 -> V_1149 = V_1216 -> V_1149 ;
}
V_1156 -> V_1091 = ( V_1156 -> V_1091 + V_1213 ) &
V_5 -> V_1138 ;
V_1150 -> V_1090 = ( V_1150 -> V_1090 + V_1213 ) &
V_5 -> V_1138 ;
}
while ( 1 ) {
V_1214 = V_1156 -> V_1092 ;
F_319 () ;
if ( V_1156 -> V_1093 == V_1214 )
break;
if ( V_1156 -> V_1093 < V_1214 )
V_1213 = V_1214 - V_1156 -> V_1093 ;
else
V_1213 = V_5 -> V_1143 + 1 -
V_1156 -> V_1093 ;
V_1213 = F_320 ( V_1213 ,
V_5 -> V_1143 + 1 - V_1150 -> V_1092 ) ;
V_1211 = V_1156 -> V_1093 ;
V_1212 = V_1150 -> V_1092 ;
for ( V_42 = V_1212 ; V_42 < V_1212 + V_1213 ; V_42 ++ ) {
if ( V_1150 -> V_1146 [ V_42 ] . V_72 ) {
V_1213 = V_42 - V_1212 ;
V_75 = - V_1215 ;
break;
}
}
if ( ! V_1213 )
break;
F_319 () ;
memcpy ( & V_1150 -> V_1146 [ V_1212 ] ,
& V_1156 -> V_1146 [ V_1211 ] ,
V_1213 * sizeof( struct V_1121 ) ) ;
for ( V_42 = 0 ; V_42 < V_1213 ; V_42 ++ , V_1212 ++ , V_1211 ++ ) {
struct V_1132 * V_1216 , * V_1217 ;
V_1216 = & V_1156 -> V_1144 [ V_1211 ] . V_1145 ;
V_1217 = & V_1150 -> V_1144 [ V_1212 ] . V_1145 ;
V_1217 -> V_1148 = V_1216 -> V_1148 ;
V_1217 -> V_1149 = V_1216 -> V_1149 ;
}
V_1156 -> V_1093 = ( V_1156 -> V_1093 + V_1213 ) &
V_5 -> V_1143 ;
V_1150 -> V_1092 = ( V_1150 -> V_1092 + V_1213 ) &
V_5 -> V_1143 ;
}
return V_75 ;
}
static int F_321 ( struct V_130 * V_131 , int V_1218 , int V_1157 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
if ( V_131 -> V_134 -> V_145 [ 0 ] . V_146 != V_131 -> V_147 ) {
F_265 ( V_131 ) ;
if ( F_267 ( F_23 ( V_5 , V_1095 ) ) )
return V_1218 ;
}
if ( ! V_131 -> V_148 )
return V_1218 ;
if ( * ( V_131 -> V_148 ) != V_131 -> V_149 )
V_1218 += F_297 ( V_131 , V_1157 - V_1218 ) ;
if ( F_23 ( V_5 , V_1208 ) && V_131 == & V_5 -> V_123 [ 1 ] ) {
struct V_1127 * V_1150 = & V_5 -> V_123 [ 0 ] . V_1089 ;
int V_42 , V_75 = 0 ;
T_1 V_1160 = V_1150 -> V_1090 ;
T_1 V_1161 = V_1150 -> V_1092 ;
V_5 -> V_1210 = false ;
for ( V_42 = 1 ; V_42 <= V_5 -> V_1219 ; V_42 ++ )
V_75 |= F_318 ( V_5 , V_1150 ,
& V_5 -> V_123 [ V_42 ] . V_1089 ) ;
F_49 () ;
if ( V_1160 != V_1150 -> V_1090 )
F_313 ( V_18 ,
V_1150 -> V_1090 ) ;
if ( V_1161 != V_1150 -> V_1092 )
F_313 ( V_1209 ,
V_1150 -> V_1092 ) ;
F_53 () ;
if ( V_75 )
F_31 ( V_138 , V_5 -> V_126 ) ;
}
return V_1218 ;
}
static inline void F_322 ( struct V_4 * V_5 )
{
if ( ! F_323 ( V_1220 , V_5 -> V_1221 ) )
F_324 ( & V_5 -> V_1222 ) ;
}
static inline void F_325 ( struct V_4 * V_5 )
{
F_326 ( & V_5 -> V_1222 ) ;
F_85 ( V_5 , V_1223 ) ;
F_85 ( V_5 , V_1095 ) ;
}
static int F_327 ( struct V_1224 * V_123 , int V_1157 )
{
struct V_130 * V_131 = F_239 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1218 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
V_1218 = F_321 ( V_131 , V_1218 , V_1157 ) ;
if ( F_267 ( F_23 ( V_5 , V_1095 ) ) )
goto V_1225;
if ( F_267 ( V_1218 >= V_1157 ) )
break;
V_131 -> V_132 = V_140 -> V_1081 ;
V_131 -> V_1086 = V_131 -> V_132 ;
F_298 () ;
if ( F_328 ( V_140 -> V_145 [ 0 ] . V_146 == V_131 -> V_147 &&
* ( V_131 -> V_148 ) == V_131 -> V_149 ) ) {
if ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1210 )
continue;
F_329 ( V_123 , V_1218 ) ;
F_52 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
if ( F_267 ( V_131 == & V_5 -> V_123 [ 1 ] && V_5 -> V_1210 ) ) {
F_46 ( V_138 , V_5 -> V_127 |
V_128 |
V_131 -> V_126 ) ;
}
F_53 () ;
break;
}
}
return V_1218 ;
V_1225:
F_330 ( V_123 ) ;
F_322 ( V_5 ) ;
return V_1218 ;
}
static void F_331 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_1226 = false ;
if ( F_23 ( V_5 , V_1227 ) )
return;
V_7 = F_33 ( V_1228 ) ;
if ( V_7 & ~ V_1229 ) {
F_185 ( V_5 -> V_111 , L_37 ) ;
V_1226 = true ;
}
if ( F_33 ( V_1230 ) & ~ V_1231 ) {
F_185 ( V_5 -> V_111 , L_38 ) ;
V_1226 = true ;
}
if ( F_33 ( V_1232 ) || F_33 ( V_1233 ) ) {
F_185 ( V_5 -> V_111 , L_39 ) ;
V_1226 = true ;
}
if ( ! V_1226 )
return;
F_260 ( V_5 ) ;
F_83 ( V_5 , V_1227 ) ;
F_322 ( V_5 ) ;
}
static int F_332 ( struct V_1224 * V_123 , int V_1157 )
{
struct V_130 * V_131 = F_239 ( V_123 , struct V_130 , V_123 ) ;
struct V_4 * V_5 = V_131 -> V_5 ;
int V_1218 = 0 ;
struct V_139 * V_140 = V_131 -> V_134 ;
while ( 1 ) {
if ( V_140 -> V_57 & V_1234 )
F_331 ( V_5 ) ;
F_315 ( V_5 ) ;
V_1218 = F_321 ( V_131 , V_1218 , V_1157 ) ;
if ( F_267 ( F_23 ( V_5 , V_1095 ) ) )
goto V_1225;
if ( F_267 ( V_1218 >= V_1157 ) )
break;
if ( F_23 ( V_5 , V_133 ) ) {
V_131 -> V_132 = V_140 -> V_1081 ;
V_131 -> V_1086 = V_131 -> V_132 ;
F_298 () ;
} else
V_140 -> V_57 &= ~ V_135 ;
if ( F_328 ( ! F_50 ( V_131 ) ) ) {
F_329 ( V_123 , V_1218 ) ;
F_51 ( V_131 ) ;
break;
}
}
return V_1218 ;
V_1225:
F_330 ( V_123 ) ;
F_322 ( V_5 ) ;
return V_1218 ;
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
F_338 ( V_5 -> V_111 , & V_5 -> V_123 [ V_42 ] . V_123 , F_327 , 64 ) ;
}
static void F_339 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_340 ( & V_5 -> V_123 [ V_42 ] . V_123 ) ;
}
static inline void F_341 ( struct V_4 * V_5 )
{
V_5 -> V_111 -> V_1235 = V_298 ;
F_333 ( V_5 ) ;
F_140 ( V_5 -> V_111 ) ;
F_342 ( V_5 -> V_111 ) ;
}
static inline void F_343 ( struct V_4 * V_5 )
{
F_254 ( V_5 ) ;
F_344 ( V_5 -> V_111 ) ;
if ( V_5 -> V_340 )
F_220 ( V_5 -> V_111 ) ;
F_335 ( V_5 ) ;
V_5 -> V_123 [ 0 ] . V_134 -> V_57 |= V_135 ;
F_48 ( V_5 ) ;
}
static void F_345 ( struct V_4 * V_5 )
__releases( V_5 -> V_209 )
__acquires( V_5 -> V_209 )
{
int V_42 ;
F_184 ( V_5 -> V_125 ) ;
V_5 -> V_125 = 1 ;
F_278 () ;
F_71 ( & V_5 -> V_209 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_346 ( V_5 -> V_123 [ V_42 ] . V_1236 ) ;
F_70 ( & V_5 -> V_209 ) ;
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
static T_10 F_347 ( int V_279 , void * V_1237 )
{
struct V_130 * V_131 = V_1237 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_299 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1163 )
F_299 ( & V_131 -> V_1163 [ V_131 -> V_149 ] ) ;
if ( F_328 ( ! F_257 ( V_5 ) ) )
F_314 ( & V_131 -> V_123 ) ;
return V_1238 ;
}
static T_10 F_348 ( int V_279 , void * V_1237 )
{
struct V_130 * V_131 = V_1237 ;
struct V_4 * V_5 = V_131 -> V_5 ;
F_299 ( V_131 -> V_134 ) ;
if ( V_131 -> V_1163 )
F_299 ( & V_131 -> V_1163 [ V_131 -> V_149 ] ) ;
F_52 ( V_131 -> V_124 , 0x00000001 ) ;
if ( F_328 ( ! F_257 ( V_5 ) ) )
F_314 ( & V_131 -> V_123 ) ;
return F_349 ( 1 ) ;
}
static T_10 F_350 ( int V_279 , void * V_1237 )
{
struct V_130 * V_131 = V_1237 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1239 = 1 ;
if ( F_267 ( ! ( V_140 -> V_57 & V_135 ) ) ) {
if ( F_23 ( V_5 , V_1240 ) ||
( F_33 ( V_1241 ) & V_1242 ) ) {
V_1239 = 0 ;
goto V_502;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
if ( F_257 ( V_5 ) )
goto V_502;
V_140 -> V_57 &= ~ V_135 ;
if ( F_328 ( F_50 ( V_131 ) ) ) {
F_299 ( & V_131 -> V_1163 [ V_131 -> V_149 ] ) ;
F_314 ( & V_131 -> V_123 ) ;
} else {
F_47 ( V_20 + V_16 ,
0x00000000 ) ;
}
V_502:
return F_349 ( V_1239 ) ;
}
static T_10 F_351 ( int V_279 , void * V_1237 )
{
struct V_130 * V_131 = V_1237 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
unsigned int V_1239 = 1 ;
if ( F_267 ( V_140 -> V_1081 == V_131 -> V_1086 ) ) {
if ( F_23 ( V_5 , V_1240 ) ||
( F_33 ( V_1241 ) & V_1242 ) ) {
V_1239 = 0 ;
goto V_502;
}
}
F_47 ( V_20 + V_16 , 0x00000001 ) ;
V_131 -> V_1086 = V_140 -> V_1081 ;
if ( F_257 ( V_5 ) )
goto V_502;
F_299 ( & V_131 -> V_1163 [ V_131 -> V_149 ] ) ;
F_314 ( & V_131 -> V_123 ) ;
V_502:
return F_349 ( V_1239 ) ;
}
static T_10 F_352 ( int V_279 , void * V_1237 )
{
struct V_130 * V_131 = V_1237 ;
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_139 * V_140 = V_131 -> V_134 ;
if ( ( V_140 -> V_57 & V_135 ) ||
! ( F_33 ( V_1241 ) & V_1242 ) ) {
F_45 ( V_5 ) ;
return F_349 ( 1 ) ;
}
return F_349 ( 0 ) ;
}
static void F_353 ( struct V_364 * V_111 )
{
int V_42 ;
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( F_257 ( V_5 ) )
return;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_350 ( V_5 -> V_123 [ V_42 ] . V_1236 , & V_5 -> V_123 [ V_42 ] ) ;
}
static void F_354 ( struct V_364 * V_111 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( F_355 ( V_5 ) ) {
F_185 ( V_111 , L_40 ) ;
F_260 ( V_5 ) ;
}
F_322 ( V_5 ) ;
}
static inline int F_356 ( T_9 V_1115 , int V_74 )
{
T_1 V_1243 = ( T_1 ) V_1115 & 0xffffffff ;
return V_1243 + V_74 + 8 < V_1243 ;
}
static inline int F_357 ( struct V_4 * V_5 , T_9 V_1115 ,
T_1 V_74 , T_1 V_1244 )
{
if ( F_30 ( V_5 ) == V_767 && V_1244 ) {
T_1 V_1243 = ( T_1 ) V_1115 & 0xffffffff ;
return ( ( V_1243 + V_74 + ( V_1244 & 0x3fff ) ) < V_1243 ) ;
}
return 0 ;
}
static inline int F_358 ( struct V_4 * V_5 , T_9 V_1115 ,
int V_74 )
{
#if F_359 ( V_1245 ) && ( V_1246 == 64 )
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) )
return ( ( T_6 ) V_1115 + V_74 ) > F_360 ( 40 ) ;
return 0 ;
#else
return 0 ;
#endif
}
static inline void F_361 ( struct V_1247 * V_1248 ,
T_9 V_1115 , T_1 V_74 , T_1 V_10 ,
T_1 V_1244 , T_1 V_1249 )
{
V_1248 -> V_1148 = ( ( T_6 ) V_1115 >> 32 ) ;
V_1248 -> V_1149 = ( ( T_6 ) V_1115 & 0xffffffff ) ;
V_1248 -> V_1111 = ( V_74 << V_1250 ) | ( V_10 & 0x0000ffff ) ;
V_1248 -> V_1251 = ( V_1244 << V_1252 ) | ( V_1249 << V_1253 ) ;
}
static bool F_362 ( struct V_130 * V_131 , T_1 * V_1254 , T_1 * V_1157 ,
T_9 V_1134 , T_1 V_74 , T_1 V_10 ,
T_1 V_1244 , T_1 V_1249 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
bool V_1255 = false ;
if ( F_23 ( V_5 , V_1256 ) && V_74 <= 8 )
V_1255 = true ;
if ( F_356 ( V_1134 , V_74 ) )
V_1255 = true ;
if ( F_357 ( V_5 , V_1134 , V_74 , V_1244 ) )
V_1255 = true ;
if ( F_358 ( V_5 , V_1134 , V_74 ) )
V_1255 = true ;
if ( V_5 -> V_1257 ) {
T_1 V_1258 = * V_1254 ;
T_1 V_1259 = V_10 & ~ V_1260 ;
while ( V_74 > V_5 -> V_1257 && * V_1157 ) {
T_1 V_1261 = V_5 -> V_1257 ;
V_74 -= V_5 -> V_1257 ;
if ( V_74 <= 8 ) {
V_74 += V_5 -> V_1257 / 2 ;
V_1261 = V_5 -> V_1257 / 2 ;
}
V_131 -> V_1106 [ * V_1254 ] . V_1117 = true ;
F_361 ( & V_131 -> V_1110 [ * V_1254 ] , V_1134 ,
V_1261 , V_1259 , V_1244 , V_1249 ) ;
* V_1157 -= 1 ;
V_1258 = * V_1254 ;
* V_1254 = F_272 ( * V_1254 ) ;
V_1134 += V_1261 ;
}
if ( V_74 ) {
if ( * V_1157 ) {
F_361 ( & V_131 -> V_1110 [ * V_1254 ] , V_1134 ,
V_74 , V_10 , V_1244 , V_1249 ) ;
* V_1157 -= 1 ;
* V_1254 = F_272 ( * V_1254 ) ;
} else {
V_1255 = true ;
V_131 -> V_1106 [ V_1258 ] . V_1117 = false ;
}
}
} else {
F_361 ( & V_131 -> V_1110 [ * V_1254 ] , V_1134 ,
V_74 , V_10 , V_1244 , V_1249 ) ;
* V_1254 = F_272 ( * V_1254 ) ;
}
return V_1255 ;
}
static void F_363 ( struct V_130 * V_131 , T_1 V_1254 , int V_1262 )
{
int V_42 ;
struct V_1107 * V_1108 ;
struct V_1104 * V_1263 = & V_131 -> V_1106 [ V_1254 ] ;
V_1108 = V_1263 -> V_1108 ;
V_1263 -> V_1108 = NULL ;
F_269 ( V_131 -> V_5 -> V_12 ,
F_270 ( V_1263 , V_1115 ) ,
F_271 ( V_1108 ) ,
V_1116 ) ;
while ( V_1263 -> V_1117 ) {
V_1263 -> V_1117 = false ;
V_1254 = F_272 ( V_1254 ) ;
V_1263 = & V_131 -> V_1106 [ V_1254 ] ;
}
for ( V_42 = 0 ; V_42 <= V_1262 ; V_42 ++ ) {
const T_11 * V_1264 = & F_273 ( V_1108 ) -> V_1119 [ V_42 ] ;
V_1254 = F_272 ( V_1254 ) ;
V_1263 = & V_131 -> V_1106 [ V_1254 ] ;
F_274 ( V_131 -> V_5 -> V_12 ,
F_270 ( V_1263 , V_1115 ) ,
F_275 ( V_1264 ) , V_1116 ) ;
while ( V_1263 -> V_1117 ) {
V_1263 -> V_1117 = false ;
V_1254 = F_272 ( V_1254 ) ;
V_1263 = & V_131 -> V_1106 [ V_1254 ] ;
}
}
}
static int F_364 ( struct V_130 * V_131 ,
struct V_1107 * * V_1265 ,
T_1 * V_1254 , T_1 * V_1157 ,
T_1 V_1266 , T_1 V_1244 , T_1 V_1249 )
{
struct V_4 * V_5 = V_131 -> V_5 ;
struct V_1107 * V_1267 , * V_1108 = * V_1265 ;
T_9 V_1268 = 0 ;
int V_56 = 0 ;
if ( F_30 ( V_5 ) != V_537 )
V_1267 = F_365 ( V_1108 , V_1078 ) ;
else {
int V_1269 = 4 - ( ( unsigned long ) V_1108 -> V_72 & 3 ) ;
V_1267 = F_366 ( V_1108 ,
F_367 ( V_1108 ) + V_1269 ,
F_368 ( V_1108 ) , V_1078 ) ;
}
if ( ! V_1267 ) {
V_56 = - 1 ;
} else {
V_1268 = F_292 ( V_5 -> V_12 , V_1267 -> V_72 , V_1267 -> V_74 ,
V_1116 ) ;
if ( F_293 ( V_5 -> V_12 , V_1268 ) ) {
F_276 ( V_1267 ) ;
V_56 = - 1 ;
} else {
T_1 V_1270 = * V_1254 ;
V_1266 |= V_1260 ;
V_131 -> V_1106 [ * V_1254 ] . V_1108 = V_1267 ;
F_294 ( & V_131 -> V_1106 [ * V_1254 ] ,
V_1115 , V_1268 ) ;
if ( F_362 ( V_131 , V_1254 , V_1157 , V_1268 ,
V_1267 -> V_74 , V_1266 ,
V_1244 , V_1249 ) ) {
F_363 ( V_131 , V_1270 , - 1 ) ;
F_276 ( V_1267 ) ;
V_56 = - 1 ;
}
}
}
F_276 ( V_1108 ) ;
* V_1265 = V_1267 ;
return V_56 ;
}
static int F_369 ( struct V_4 * V_5 , struct V_130 * V_131 ,
struct V_1099 * V_1100 , struct V_1107 * V_1108 )
{
struct V_1107 * V_1271 , * V_1272 ;
T_1 V_1273 = F_273 ( V_1108 ) -> V_1274 * 3 ;
if ( F_267 ( F_263 ( V_131 ) <= V_1273 ) ) {
F_370 ( V_1100 ) ;
F_278 () ;
if ( F_263 ( V_131 ) <= V_1273 )
return V_1275 ;
F_283 ( V_1100 ) ;
}
V_1271 = F_371 ( V_1108 , V_5 -> V_111 -> V_1189 &
~ ( V_1276 | V_1277 ) ) ;
if ( F_115 ( V_1271 ) || ! V_1271 )
goto V_1278;
do {
V_1272 = V_1271 ;
V_1271 = V_1271 -> V_1279 ;
V_1272 -> V_1279 = NULL ;
F_372 ( V_1272 , V_5 -> V_111 ) ;
} while ( V_1271 );
V_1278:
F_276 ( V_1108 ) ;
return V_1280 ;
}
static T_12 F_372 ( struct V_1107 * V_1108 , struct V_364 * V_111 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
T_1 V_74 , V_1254 , V_1266 , V_1244 , V_1249 = 0 ;
T_1 V_1157 ;
int V_42 = - 1 , V_1281 ;
T_9 V_1115 ;
struct V_130 * V_131 ;
struct V_1099 * V_1100 ;
unsigned int V_1262 ;
struct V_1282 * V_1283 = NULL ;
struct V_1284 * V_1285 = NULL ;
T_13 V_1286 = 0 , V_1287 = 0 ;
T_14 V_1288 = 0 ;
V_1100 = F_266 ( V_111 , F_373 ( V_1108 ) ) ;
V_131 = & V_5 -> V_123 [ F_373 ( V_1108 ) ] ;
if ( F_23 ( V_5 , V_1103 ) )
V_131 ++ ;
V_1157 = F_263 ( V_131 ) ;
if ( F_267 ( V_1157 <= ( F_273 ( V_1108 ) -> V_1118 + 1 ) ) ) {
if ( ! F_279 ( V_1100 ) ) {
F_370 ( V_1100 ) ;
F_185 ( V_111 ,
L_41 ) ;
}
return V_1275 ;
}
V_1254 = V_131 -> V_1087 ;
V_1266 = 0 ;
V_1244 = F_273 ( V_1108 ) -> V_1289 ;
if ( V_1244 ) {
T_1 V_1290 , V_1291 ;
if ( F_374 ( V_1108 , 0 ) )
goto V_1292;
V_1283 = F_375 ( V_1108 ) ;
V_1290 = F_376 ( V_1108 ) ;
V_1291 = F_377 ( V_1108 ) + F_378 ( V_1108 ) - V_1199 ;
if ( V_1108 -> V_1197 == F_310 ( V_1200 ) ||
V_1108 -> V_1197 == F_310 ( V_1201 ) )
return F_369 ( V_5 , V_131 , V_1100 , V_1108 ) ;
if ( ! F_379 ( V_1108 ) ) {
if ( F_267 ( ( V_1199 + V_1291 ) > 80 ) &&
F_23 ( V_5 , V_1293 ) )
return F_369 ( V_5 , V_131 , V_1100 , V_1108 ) ;
V_1287 = V_1283 -> V_1294 ;
V_1288 = V_1283 -> V_1295 ;
V_1283 -> V_1294 = 0 ;
V_1283 -> V_1295 = F_310 ( V_1244 + V_1291 ) ;
}
V_1266 |= ( V_1296 |
V_1297 ) ;
V_1285 = F_380 ( V_1108 ) ;
V_1286 = V_1285 -> V_1294 ;
if ( F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ||
F_23 ( V_5 , V_1300 ) ) {
V_1285 -> V_1294 = 0 ;
V_1266 &= ~ V_1301 ;
} else {
V_1285 -> V_1294 = ~ F_381 ( V_1283 -> V_1302 , V_1283 -> V_1303 ,
0 , V_1304 , 0 ) ;
}
if ( F_23 ( V_5 , V_1300 ) ) {
V_1244 |= ( V_1291 & 0xc ) << 12 ;
if ( V_1291 & 0x10 )
V_1266 |= 0x00000010 ;
V_1266 |= ( V_1291 & 0x3e0 ) << 5 ;
} else if ( F_23 ( V_5 , V_1299 ) )
V_1244 |= V_1291 << 9 ;
else if ( F_23 ( V_5 , V_1298 ) ||
F_30 ( V_5 ) == V_501 ) {
if ( V_1290 || V_1283 -> V_1305 > 5 ) {
int V_1306 ;
V_1306 = ( V_1283 -> V_1305 - 5 ) + ( V_1290 >> 2 ) ;
V_1244 |= ( V_1306 << 11 ) ;
}
} else {
if ( V_1290 || V_1283 -> V_1305 > 5 ) {
int V_1306 ;
V_1306 = ( V_1283 -> V_1305 - 5 ) + ( V_1290 >> 2 ) ;
V_1266 |= V_1306 << 12 ;
}
}
} else if ( V_1108 -> V_1195 == V_1307 ) {
if ( V_1108 -> V_1197 == F_310 ( V_1200 ) ||
V_1108 -> V_1197 == F_310 ( V_1201 ) ) {
if ( F_382 ( V_1108 ) )
goto V_1292;
} else {
V_1266 |= V_1301 ;
}
}
if ( F_23 ( V_5 , V_1308 ) &&
! V_1244 && V_1108 -> V_74 > V_1309 )
V_1266 |= V_1310 ;
if ( F_383 ( V_1108 ) ) {
V_1266 |= V_1311 ;
V_1249 = F_384 ( V_1108 ) ;
}
if ( ( F_267 ( F_273 ( V_1108 ) -> V_1312 & V_1313 ) ) &&
F_23 ( V_5 , V_1314 ) ) {
F_273 ( V_1108 ) -> V_1312 |= V_1315 ;
V_1266 |= V_1112 ;
}
V_74 = F_271 ( V_1108 ) ;
V_1115 = F_292 ( V_5 -> V_12 , V_1108 -> V_72 , V_74 , V_1116 ) ;
if ( F_293 ( V_5 -> V_12 , V_1115 ) )
goto V_1292;
V_131 -> V_1106 [ V_1254 ] . V_1108 = V_1108 ;
F_294 ( & V_131 -> V_1106 [ V_1254 ] , V_1115 , V_1115 ) ;
V_1281 = 0 ;
if ( F_23 ( V_5 , 5701_DMA_BUG ) )
V_1281 = 1 ;
if ( F_362 ( V_131 , & V_1254 , & V_1157 , V_1115 , V_74 , V_1266 |
( ( F_273 ( V_1108 ) -> V_1118 == 0 ) ? V_1260 : 0 ) ,
V_1244 , V_1249 ) ) {
V_1281 = 1 ;
} else if ( F_273 ( V_1108 ) -> V_1118 > 0 ) {
T_1 V_1316 = V_1244 ;
if ( ! F_23 ( V_5 , V_1298 ) &&
! F_23 ( V_5 , V_1299 ) &&
! F_23 ( V_5 , V_1300 ) )
V_1316 = 0 ;
V_1262 = F_273 ( V_1108 ) -> V_1118 - 1 ;
for ( V_42 = 0 ; V_42 <= V_1262 ; V_42 ++ ) {
T_11 * V_1264 = & F_273 ( V_1108 ) -> V_1119 [ V_42 ] ;
V_74 = F_275 ( V_1264 ) ;
V_1115 = F_385 ( & V_5 -> V_12 -> V_111 , V_1264 , 0 ,
V_74 , V_1317 ) ;
V_131 -> V_1106 [ V_1254 ] . V_1108 = NULL ;
F_294 ( & V_131 -> V_1106 [ V_1254 ] , V_1115 ,
V_1115 ) ;
if ( F_386 ( & V_5 -> V_12 -> V_111 , V_1115 ) )
goto V_1318;
if ( ! V_1157 ||
F_362 ( V_131 , & V_1254 , & V_1157 , V_1115 ,
V_74 , V_1266 |
( ( V_42 == V_1262 ) ? V_1260 : 0 ) ,
V_1316 , V_1249 ) ) {
V_1281 = 1 ;
break;
}
}
}
if ( V_1281 ) {
F_363 ( V_131 , V_131 -> V_1087 , V_42 ) ;
if ( V_1244 ) {
if ( V_1288 ) {
V_1283 -> V_1294 = V_1287 ;
V_1283 -> V_1295 = V_1288 ;
}
V_1285 -> V_1294 = V_1286 ;
return F_369 ( V_5 , V_131 , V_1100 , V_1108 ) ;
}
V_1254 = V_131 -> V_1087 ;
V_1157 = F_263 ( V_131 ) ;
if ( F_364 ( V_131 , & V_1108 , & V_1254 , & V_1157 ,
V_1266 , V_1244 , V_1249 ) )
goto V_1319;
}
F_387 ( V_1108 ) ;
F_388 ( V_1100 , V_1108 -> V_74 ) ;
F_49 () ;
V_131 -> V_1087 = V_1254 ;
if ( F_267 ( F_263 ( V_131 ) <= ( V_1320 + 1 ) ) ) {
F_370 ( V_1100 ) ;
F_278 () ;
if ( F_263 ( V_131 ) > F_280 ( V_131 ) )
F_283 ( V_1100 ) ;
}
if ( ! V_1108 -> V_1321 || F_389 ( V_1100 ) ) {
F_390 ( V_131 -> V_1322 , V_1254 ) ;
F_53 () ;
}
return V_1280 ;
V_1318:
F_363 ( V_131 , V_131 -> V_1087 , -- V_42 ) ;
V_131 -> V_1106 [ V_131 -> V_1087 ] . V_1108 = NULL ;
V_1292:
F_276 ( V_1108 ) ;
V_1319:
V_5 -> V_1323 ++ ;
return V_1280 ;
}
static void F_391 ( struct V_4 * V_5 , bool V_195 )
{
if ( V_195 ) {
V_5 -> V_367 &= ~ ( V_371 |
V_370 ) ;
V_5 -> V_367 |= V_834 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_367 |= V_725 ;
if ( V_5 -> V_178 & V_392 )
V_5 -> V_367 |= V_374 ;
else
V_5 -> V_367 |= V_375 ;
} else {
V_5 -> V_367 &= ~ V_834 ;
if ( F_23 ( V_5 , 5705_PLUS ) ||
( V_5 -> V_178 & V_567 ) ||
F_30 ( V_5 ) == V_536 )
V_5 -> V_367 &= ~ V_725 ;
}
F_46 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
}
static int F_392 ( struct V_4 * V_5 , T_1 V_372 , bool V_1324 )
{
T_1 V_7 , V_774 , V_367 , V_1325 = 0 ;
F_127 ( V_5 , false ) ;
F_128 ( V_5 , false ) ;
if ( V_1324 && F_125 ( V_5 ) )
return - V_210 ;
V_774 = V_492 ;
switch ( V_372 ) {
case V_373 :
break;
case V_332 :
V_774 |= V_776 ;
break;
case V_331 :
default:
if ( V_5 -> V_178 & V_179 ) {
V_372 = V_332 ;
V_774 |= V_776 ;
} else {
V_372 = V_331 ;
V_774 |= V_493 ;
}
}
if ( V_1324 ) {
if ( ! ( V_5 -> V_178 & V_179 ) ) {
F_57 ( V_5 , V_180 , & V_7 ) ;
V_7 |= V_494 |
V_495 ;
F_59 ( V_5 , V_180 , V_7 ) ;
} else {
V_1325 = V_1326 |
V_1327 ;
F_59 ( V_5 , V_524 , V_1325 ) ;
}
} else
V_774 |= V_777 ;
F_59 ( V_5 , V_204 , V_774 ) ;
if ( V_5 -> V_178 & V_179 )
F_57 ( V_5 , V_204 , & V_774 ) ;
F_24 ( 40 ) ;
if ( ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) == V_257 ) {
F_59 ( V_5 , V_524 , V_1325 |
V_1328 |
V_1329 ) ;
F_57 ( V_5 , V_524 , & V_7 ) ;
}
if ( ( V_5 -> V_178 & V_305 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_31 ( V_361 , V_1330 ) ;
F_24 ( 10 ) ;
F_31 ( V_361 , V_5 -> V_354 ) ;
}
V_367 = V_5 -> V_367 &
~ ( V_370 | V_371 ) ;
if ( V_372 == V_331 )
V_367 |= V_375 ;
else
V_367 |= V_374 ;
if ( F_30 ( V_5 ) == V_536 ) {
T_1 V_1331 = V_5 -> V_216 & V_400 ;
if ( V_1331 == V_401 )
V_367 &= ~ V_725 ;
else if ( V_1331 == V_565 )
V_367 |= V_725 ;
F_59 ( V_5 , V_491 ,
V_822 ) ;
}
F_46 ( V_382 , V_367 ) ;
F_24 ( 40 ) ;
return 0 ;
}
static void F_393 ( struct V_364 * V_111 , T_15 V_1189 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( V_1189 & V_1332 ) {
if ( V_5 -> V_367 & V_834 )
return;
F_70 ( & V_5 -> V_209 ) ;
F_391 ( V_5 , true ) ;
F_220 ( V_5 -> V_111 ) ;
F_71 ( & V_5 -> V_209 ) ;
F_97 ( V_111 , L_42 ) ;
} else {
if ( ! ( V_5 -> V_367 & V_834 ) )
return;
F_70 ( & V_5 -> V_209 ) ;
F_391 ( V_5 , false ) ;
F_201 ( V_5 , true ) ;
F_71 ( & V_5 -> V_209 ) ;
F_97 ( V_111 , L_43 ) ;
}
}
static T_15 F_394 ( struct V_364 * V_111 ,
T_15 V_1189 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( V_111 -> V_1198 > V_1333 && F_23 ( V_5 , 5780_CLASS ) )
V_1189 &= ~ V_1334 ;
return V_1189 ;
}
static int F_395 ( struct V_364 * V_111 , T_15 V_1189 )
{
T_15 V_1335 = V_111 -> V_1189 ^ V_1189 ;
if ( ( V_1335 & V_1332 ) && F_144 ( V_111 ) )
F_393 ( V_111 , V_1189 ) ;
return 0 ;
}
static void F_396 ( struct V_4 * V_5 ,
struct V_1127 * V_1128 )
{
int V_42 ;
if ( V_1128 != & V_5 -> V_123 [ 0 ] . V_1089 ) {
for ( V_42 = V_1128 -> V_1091 ; V_42 != V_1128 -> V_1090 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1138 )
F_287 ( V_5 , & V_1128 -> V_1140 [ V_42 ] ,
V_5 -> V_1141 ) ;
if ( F_23 ( V_5 , V_521 ) ) {
for ( V_42 = V_1128 -> V_1093 ;
V_42 != V_1128 -> V_1092 ;
V_42 = ( V_42 + 1 ) & V_5 -> V_1143 ) {
F_287 ( V_5 , & V_1128 -> V_1146 [ V_42 ] ,
V_1147 ) ;
}
}
return;
}
for ( V_42 = 0 ; V_42 <= V_5 -> V_1138 ; V_42 ++ )
F_287 ( V_5 , & V_1128 -> V_1140 [ V_42 ] ,
V_5 -> V_1141 ) ;
if ( F_23 ( V_5 , V_521 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
for ( V_42 = 0 ; V_42 <= V_5 -> V_1143 ; V_42 ++ )
F_287 ( V_5 , & V_1128 -> V_1146 [ V_42 ] ,
V_1147 ) ;
}
}
static int F_397 ( struct V_4 * V_5 ,
struct V_1127 * V_1128 )
{
T_1 V_42 , V_1336 ;
V_1128 -> V_1091 = 0 ;
V_1128 -> V_1090 = 0 ;
V_1128 -> V_1093 = 0 ;
V_1128 -> V_1092 = 0 ;
if ( V_1128 != & V_5 -> V_123 [ 0 ] . V_1089 ) {
memset ( & V_1128 -> V_1140 [ 0 ] , 0 ,
F_398 ( V_5 ) ) ;
if ( V_1128 -> V_1146 )
memset ( & V_1128 -> V_1146 [ 0 ] , 0 ,
F_399 ( V_5 ) ) ;
goto V_186;
}
memset ( V_1128 -> V_1139 , 0 , F_400 ( V_5 ) ) ;
V_1336 = V_1337 ;
if ( F_23 ( V_5 , 5780_CLASS ) &&
V_5 -> V_111 -> V_1198 > V_1333 )
V_1336 = V_1338 ;
V_5 -> V_1141 = F_401 ( V_1336 ) ;
for ( V_42 = 0 ; V_42 <= V_5 -> V_1138 ; V_42 ++ ) {
struct V_1132 * V_1339 ;
V_1339 = & V_1128 -> V_1139 [ V_42 ] ;
V_1339 -> V_1178 = V_1336 << V_1180 ;
V_1339 -> V_1182 = ( V_1340 << V_1341 ) ;
V_1339 -> V_1168 = ( V_1137 |
( V_42 << V_1342 ) ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_1343 ; V_42 ++ ) {
unsigned int V_1131 ;
if ( F_290 ( V_5 , V_1128 , V_1137 , V_42 ,
& V_1131 ) < 0 ) {
F_142 ( V_5 -> V_111 ,
L_44
L_45
L_46 , V_42 , V_5 -> V_1343 ) ;
if ( V_42 == 0 )
goto V_1344;
V_5 -> V_1343 = V_42 ;
break;
}
}
if ( ! F_23 ( V_5 , V_521 ) || F_23 ( V_5 , 5780_CLASS ) )
goto V_186;
memset ( V_1128 -> V_1144 , 0 , F_402 ( V_5 ) ) ;
if ( ! F_23 ( V_5 , V_1345 ) )
goto V_186;
for ( V_42 = 0 ; V_42 <= V_5 -> V_1143 ; V_42 ++ ) {
struct V_1132 * V_1339 ;
V_1339 = & V_1128 -> V_1144 [ V_42 ] . V_1145 ;
V_1339 -> V_1178 = V_1338 << V_1180 ;
V_1339 -> V_1182 = ( V_1340 << V_1341 ) |
V_1346 ;
V_1339 -> V_1168 = ( V_1142 |
( V_42 << V_1342 ) ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_1347 ; V_42 ++ ) {
unsigned int V_1131 ;
if ( F_290 ( V_5 , V_1128 , V_1142 , V_42 ,
& V_1131 ) < 0 ) {
F_142 ( V_5 -> V_111 ,
L_47
L_48
L_46 , V_42 , V_5 -> V_1347 ) ;
if ( V_42 == 0 )
goto V_1344;
V_5 -> V_1347 = V_42 ;
break;
}
}
V_186:
return 0 ;
V_1344:
F_396 ( V_5 , V_1128 ) ;
return - V_268 ;
}
static void F_403 ( struct V_4 * V_5 ,
struct V_1127 * V_1128 )
{
F_175 ( V_1128 -> V_1140 ) ;
V_1128 -> V_1140 = NULL ;
F_175 ( V_1128 -> V_1146 ) ;
V_1128 -> V_1146 = NULL ;
if ( V_1128 -> V_1139 ) {
F_404 ( & V_5 -> V_12 -> V_111 , F_400 ( V_5 ) ,
V_1128 -> V_1139 , V_1128 -> V_1348 ) ;
V_1128 -> V_1139 = NULL ;
}
if ( V_1128 -> V_1144 ) {
F_404 ( & V_5 -> V_12 -> V_111 , F_402 ( V_5 ) ,
V_1128 -> V_1144 , V_1128 -> V_1349 ) ;
V_1128 -> V_1144 = NULL ;
}
}
static int F_405 ( struct V_4 * V_5 ,
struct V_1127 * V_1128 )
{
V_1128 -> V_1140 = F_261 ( F_398 ( V_5 ) ,
V_632 ) ;
if ( ! V_1128 -> V_1140 )
return - V_268 ;
V_1128 -> V_1139 = F_406 ( & V_5 -> V_12 -> V_111 ,
F_400 ( V_5 ) ,
& V_1128 -> V_1348 ,
V_632 ) ;
if ( ! V_1128 -> V_1139 )
goto V_1031;
if ( F_23 ( V_5 , V_521 ) && ! F_23 ( V_5 , 5780_CLASS ) ) {
V_1128 -> V_1146 = F_261 ( F_399 ( V_5 ) ,
V_632 ) ;
if ( ! V_1128 -> V_1146 )
goto V_1031;
V_1128 -> V_1144 = F_406 ( & V_5 -> V_12 -> V_111 ,
F_402 ( V_5 ) ,
& V_1128 -> V_1349 ,
V_632 ) ;
if ( ! V_1128 -> V_1144 )
goto V_1031;
}
return 0 ;
V_1031:
F_403 ( V_5 , V_1128 ) ;
return - V_268 ;
}
static void F_407 ( struct V_4 * V_5 )
{
int V_42 , V_627 ;
for ( V_627 = 0 ; V_627 < V_5 -> V_129 ; V_627 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_627 ] ;
F_396 ( V_5 , & V_131 -> V_1089 ) ;
if ( ! V_131 -> V_1106 )
continue;
for ( V_42 = 0 ; V_42 < V_1096 ; V_42 ++ ) {
struct V_1107 * V_1108 = V_131 -> V_1106 [ V_42 ] . V_1108 ;
if ( ! V_1108 )
continue;
F_363 ( V_131 , V_42 ,
F_273 ( V_1108 ) -> V_1118 - 1 ) ;
F_276 ( V_1108 ) ;
}
F_408 ( F_266 ( V_5 -> V_111 , V_627 ) ) ;
}
}
static int F_409 ( struct V_4 * V_5 )
{
int V_42 ;
F_407 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_131 -> V_132 = 0 ;
V_131 -> V_1086 = 0 ;
V_131 -> V_134 -> V_57 = 0 ;
V_131 -> V_134 -> V_1081 = 0 ;
memset ( V_131 -> V_134 , 0 , V_1350 ) ;
V_131 -> V_1087 = 0 ;
V_131 -> V_147 = 0 ;
if ( V_131 -> V_1110 )
memset ( V_131 -> V_1110 , 0 , V_1351 ) ;
V_131 -> V_149 = 0 ;
if ( V_131 -> V_1163 )
memset ( V_131 -> V_1163 , 0 , F_410 ( V_5 ) ) ;
if ( V_131 -> V_1089 . V_1139 &&
F_397 ( V_5 , & V_131 -> V_1089 ) ) {
F_407 ( V_5 ) ;
return - V_268 ;
}
}
return 0 ;
}
static void F_411 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_1110 ) {
F_404 ( & V_5 -> V_12 -> V_111 , V_1351 ,
V_131 -> V_1110 , V_131 -> V_1352 ) ;
V_131 -> V_1110 = NULL ;
}
F_175 ( V_131 -> V_1106 ) ;
V_131 -> V_1106 = NULL ;
}
}
static int F_412 ( struct V_4 * V_5 )
{
int V_42 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
if ( F_23 ( V_5 , V_1103 ) )
V_131 ++ ;
for ( V_42 = 0 ; V_42 < V_5 -> V_1353 ; V_42 ++ , V_131 ++ ) {
V_131 -> V_1106 = F_261 ( sizeof( struct V_1104 ) *
V_1096 , V_632 ) ;
if ( ! V_131 -> V_1106 )
goto V_1031;
V_131 -> V_1110 = F_406 ( & V_5 -> V_12 -> V_111 ,
V_1351 ,
& V_131 -> V_1352 ,
V_632 ) ;
if ( ! V_131 -> V_1110 )
goto V_1031;
}
return 0 ;
V_1031:
F_411 ( V_5 ) ;
return - V_268 ;
}
static void F_413 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_403 ( V_5 , & V_131 -> V_1089 ) ;
if ( ! V_131 -> V_1163 )
continue;
F_404 ( & V_5 -> V_12 -> V_111 ,
F_410 ( V_5 ) ,
V_131 -> V_1163 ,
V_131 -> V_1354 ) ;
V_131 -> V_1163 = NULL ;
}
}
static int F_414 ( struct V_4 * V_5 )
{
unsigned int V_42 , V_202 ;
V_202 = V_5 -> V_1219 ;
if ( F_23 ( V_5 , V_1208 ) )
V_202 ++ ;
for ( V_42 = 0 ; V_42 < V_202 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( F_405 ( V_5 , & V_131 -> V_1089 ) )
goto V_1031;
if ( ! V_42 && F_23 ( V_5 , V_1208 ) )
continue;
V_131 -> V_1163 = F_415 ( & V_5 -> V_12 -> V_111 ,
F_410 ( V_5 ) ,
& V_131 -> V_1354 ,
V_632 ) ;
if ( ! V_131 -> V_1163 )
goto V_1031;
}
return 0 ;
V_1031:
F_413 ( V_5 ) ;
return - V_268 ;
}
static void F_416 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
F_404 ( & V_5 -> V_12 -> V_111 , V_1350 ,
V_131 -> V_134 ,
V_131 -> V_1355 ) ;
V_131 -> V_134 = NULL ;
}
}
F_413 ( V_5 ) ;
F_411 ( V_5 ) ;
if ( V_5 -> V_1356 ) {
F_404 ( & V_5 -> V_12 -> V_111 , sizeof( struct V_1357 ) ,
V_5 -> V_1356 , V_5 -> V_1358 ) ;
V_5 -> V_1356 = NULL ;
}
}
static int F_417 ( struct V_4 * V_5 )
{
int V_42 ;
V_5 -> V_1356 = F_415 ( & V_5 -> V_12 -> V_111 ,
sizeof( struct V_1357 ) ,
& V_5 -> V_1358 , V_632 ) ;
if ( ! V_5 -> V_1356 )
goto V_1031;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
struct V_139 * V_140 ;
V_131 -> V_134 = F_415 ( & V_5 -> V_12 -> V_111 ,
V_1350 ,
& V_131 -> V_1355 ,
V_632 ) ;
if ( ! V_131 -> V_134 )
goto V_1031;
V_140 = V_131 -> V_134 ;
if ( F_23 ( V_5 , V_1208 ) ) {
T_3 * V_1359 = NULL ;
switch ( V_42 ) {
case 1 :
V_1359 = & V_140 -> V_145 [ 0 ] . V_1085 ;
break;
case 2 :
V_1359 = & V_140 -> V_1082 ;
break;
case 3 :
V_1359 = & V_140 -> V_1360 ;
break;
case 4 :
V_1359 = & V_140 -> V_1084 ;
break;
}
V_131 -> V_148 = V_1359 ;
} else {
V_131 -> V_148 = & V_140 -> V_145 [ 0 ] . V_1085 ;
}
}
if ( F_412 ( V_5 ) || F_414 ( V_5 ) )
goto V_1031;
return 0 ;
V_1031:
F_416 ( V_5 ) ;
return - V_268 ;
}
static int F_418 ( struct V_4 * V_5 , unsigned long V_1361 , T_1 V_1362 , bool V_1363 )
{
unsigned int V_42 ;
T_1 V_7 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
switch ( V_1361 ) {
case V_1059 :
case V_1076 :
case V_1060 :
case V_1064 :
case V_1063 :
return 0 ;
default:
break;
}
}
V_7 = F_33 ( V_1361 ) ;
V_7 &= ~ V_1362 ;
F_31 ( V_1361 , V_7 ) ;
for ( V_42 = 0 ; V_42 < V_1364 ; V_42 ++ ) {
if ( F_36 ( V_5 -> V_12 ) ) {
F_116 ( & V_5 -> V_12 -> V_111 ,
L_49
L_50 ,
V_1361 , V_1362 ) ;
return - V_82 ;
}
F_24 ( 100 ) ;
V_7 = F_33 ( V_1361 ) ;
if ( ( V_7 & V_1362 ) == 0 )
break;
}
if ( V_42 == V_1364 && ! V_1363 ) {
F_116 ( & V_5 -> V_12 -> V_111 ,
L_51 ,
V_1361 , V_1362 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_419 ( struct V_4 * V_5 , bool V_1363 )
{
int V_42 , V_75 ;
F_45 ( V_5 ) ;
if ( F_36 ( V_5 -> V_12 ) ) {
V_5 -> V_354 &= ~ ( V_733 | V_1365 ) ;
V_5 -> V_367 &= ~ V_732 ;
V_75 = - V_82 ;
goto V_1366;
}
V_5 -> V_354 &= ~ V_733 ;
F_31 ( V_361 , V_5 -> V_354 ) ;
F_24 ( 10 ) ;
V_75 = F_418 ( V_5 , V_1057 , V_1367 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1051 , V_1368 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1059 , V_1369 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1053 , V_1370 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1056 , V_1371 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1058 , V_1372 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1048 , V_1373 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1049 , V_1374 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1046 , V_1375 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1065 , V_1376 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1047 , V_1377 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1076 , V_1378 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1050 , V_1379 , V_1363 ) ;
V_5 -> V_367 &= ~ V_732 ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
V_5 -> V_356 &= ~ V_1365 ;
F_31 ( V_363 , V_5 -> V_356 ) ;
for ( V_42 = 0 ; V_42 < V_1364 ; V_42 ++ ) {
F_24 ( 100 ) ;
if ( ! ( F_33 ( V_363 ) & V_1365 ) )
break;
}
if ( V_42 >= V_1364 ) {
F_116 ( & V_5 -> V_12 -> V_111 ,
L_52
L_53 , V_657 , F_33 ( V_363 ) ) ;
V_75 |= - V_82 ;
}
V_75 |= F_418 ( V_5 , V_138 , V_128 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1066 , V_1380 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1060 , V_1381 , V_1363 ) ;
F_46 ( V_1074 , 0xffffffff ) ;
F_46 ( V_1074 , 0x00000000 ) ;
V_75 |= F_418 ( V_5 , V_1064 , V_1382 , V_1363 ) ;
V_75 |= F_418 ( V_5 , V_1063 , V_1383 , V_1363 ) ;
V_1366:
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 )
memset ( V_131 -> V_134 , 0 , V_1350 ) ;
}
return V_75 ;
}
static void F_420 ( struct V_4 * V_5 )
{
F_421 ( V_5 -> V_12 , V_1384 , & V_5 -> V_1385 ) ;
}
static void F_422 ( struct V_4 * V_5 )
{
T_1 V_7 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
V_7 = ( V_1386 | V_1387 ) ;
if ( F_76 ( V_5 ) == V_918 &&
F_23 ( V_5 , V_841 ) )
V_7 |= V_1388 ;
if ( F_23 ( V_5 , V_60 ) )
V_7 |= V_1389 |
V_1390 |
V_1391 ;
F_15 ( V_5 -> V_12 , V_1241 , V_7 ) ;
F_423 ( V_5 -> V_12 , V_1384 , V_5 -> V_1385 ) ;
if ( ! F_23 ( V_5 , V_1079 ) ) {
F_424 ( V_5 -> V_12 , V_1392 ,
V_5 -> V_1393 ) ;
F_424 ( V_5 -> V_12 , V_1394 ,
V_5 -> V_1395 ) ;
}
if ( F_23 ( V_5 , V_841 ) ) {
T_3 V_1396 ;
F_421 ( V_5 -> V_12 , V_5 -> V_1397 + V_1398 ,
& V_1396 ) ;
V_1396 &= ~ V_1399 ;
F_423 ( V_5 -> V_12 , V_5 -> V_1397 + V_1398 ,
V_1396 ) ;
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_1400 ) ) {
T_3 V_1401 ;
F_421 ( V_5 -> V_12 ,
V_5 -> V_1402 + V_1403 ,
& V_1401 ) ;
F_423 ( V_5 -> V_12 ,
V_5 -> V_1402 + V_1403 ,
V_1401 | V_1404 ) ;
V_7 = F_33 ( V_1075 ) ;
F_46 ( V_1075 , V_7 | V_1405 ) ;
}
}
}
static void F_425 ( struct V_4 * V_5 )
{
T_1 V_7 ;
switch ( F_30 ( V_5 ) ) {
case V_476 :
V_7 = F_33 ( V_1406 ) ;
F_46 ( V_1406 , V_7 |
V_1407 ) ;
break;
case V_477 :
case V_533 :
F_46 ( V_1408 , V_1409 ) ;
break;
default:
return;
}
}
static void F_426 ( struct V_4 * V_5 )
{
T_1 V_7 ;
switch ( F_30 ( V_5 ) ) {
case V_476 :
V_7 = F_33 ( V_1406 ) ;
F_46 ( V_1406 ,
V_7 & ~ V_1407 ) ;
break;
case V_477 :
case V_533 :
V_7 = F_33 ( V_1408 ) ;
F_46 ( V_1408 , V_7 & ~ V_1409 ) ;
break;
default:
return;
}
}
static int F_427 ( struct V_4 * V_5 )
__releases( V_5 -> V_209 )
__acquires( V_5 -> V_209 )
{
T_1 V_7 ;
void (* F_188)( struct V_4 * , T_1 , T_1 );
int V_42 , V_75 ;
if ( ! F_428 ( V_5 -> V_12 ) )
return - V_82 ;
F_157 ( V_5 ) ;
F_35 ( V_5 , V_61 ) ;
V_5 -> V_586 = 0 ;
F_420 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_640 ||
F_23 ( V_5 , 5755_PLUS ) )
F_46 ( V_1410 , 0 ) ;
F_188 = V_5 -> V_27 ;
if ( F_188 == F_17 )
V_5 -> V_27 = F_7 ;
F_83 ( V_5 , V_1240 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( V_131 -> V_134 ) {
V_131 -> V_134 -> V_57 = 0 ;
V_131 -> V_134 -> V_1081 = 0 ;
}
V_131 -> V_132 = 0 ;
V_131 -> V_1086 = 0 ;
}
F_278 () ;
F_242 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ )
F_346 ( V_5 -> V_123 [ V_42 ] . V_1236 ) ;
F_241 ( V_5 , 0 ) ;
if ( F_30 ( V_5 ) == V_1411 ) {
V_7 = F_33 ( V_1412 ) & ~ V_1413 ;
F_46 ( V_1412 , V_7 | V_1414 ) ;
}
V_7 = V_1415 ;
if ( F_23 ( V_5 , V_1079 ) ) {
if ( F_30 ( V_5 ) != V_257 &&
! F_23 ( V_5 , 57765_PLUS ) &&
F_33 ( V_1416 ) ==
( V_1417 | V_1418 ) )
F_46 ( V_1416 , V_1418 ) ;
if ( F_76 ( V_5 ) != V_1419 ) {
F_46 ( V_497 , ( 1 << 29 ) ) ;
V_7 |= ( 1 << 29 ) ;
}
}
if ( F_30 ( V_5 ) == V_36 ) {
F_46 ( V_325 , F_33 ( V_325 ) | V_1420 ) ;
F_46 ( V_655 ,
F_33 ( V_655 ) & ~ V_656 ) ;
}
F_425 ( V_5 ) ;
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , V_152 ) )
V_7 |= V_1421 ;
F_46 ( V_497 , V_7 ) ;
V_5 -> V_27 = F_188 ;
F_24 ( 120 ) ;
F_19 ( V_5 -> V_12 , V_1384 , & V_7 ) ;
F_24 ( 120 ) ;
if ( F_23 ( V_5 , V_1079 ) && F_429 ( V_5 -> V_12 ) ) {
T_3 V_1422 ;
if ( F_76 ( V_5 ) == V_1419 ) {
int V_627 ;
T_1 V_1423 ;
for ( V_627 = 0 ; V_627 < 5000 ; V_627 ++ )
F_24 ( 100 ) ;
F_19 ( V_5 -> V_12 , 0xc4 , & V_1423 ) ;
F_15 ( V_5 -> V_12 , 0xc4 ,
V_1423 | ( 1 << 15 ) ) ;
}
V_1422 = V_1424 | V_1425 ;
if ( ! F_23 ( V_5 , V_152 ) )
V_1422 |= V_1426 ;
F_224 ( V_5 -> V_12 , V_1427 , V_1422 ) ;
F_430 ( V_5 -> V_12 , V_1428 ,
V_1429 |
V_1430 |
V_1431 |
V_1432 ) ;
}
F_422 ( V_5 ) ;
F_85 ( V_5 , V_1240 ) ;
F_85 ( V_5 , V_1227 ) ;
V_7 = 0 ;
if ( F_23 ( V_5 , 5780_CLASS ) )
V_7 = F_33 ( V_1063 ) ;
F_46 ( V_1063 , V_7 | V_1383 ) ;
if ( F_76 ( V_5 ) == V_1433 ) {
F_92 ( V_5 ) ;
F_46 ( 0x5000 , 0x400 ) ;
}
if ( F_23 ( V_5 , V_264 ) ) {
F_92 ( V_5 ) ;
F_183 ( V_5 , V_653 ) ;
}
V_75 = F_96 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_46 ( V_646 , V_5 -> V_644 ) ;
if ( F_76 ( V_5 ) == V_1434 ) {
V_7 = F_33 ( 0xc4 ) ;
F_46 ( 0xc4 , V_7 | ( 1 << 15 ) ) ;
}
if ( ( V_5 -> V_550 & V_1435 ) != 0 &&
F_30 ( V_5 ) == V_501 ) {
V_5 -> V_156 |= V_155 ;
if ( F_76 ( V_5 ) == V_1434 )
V_5 -> V_156 |= V_154 ;
F_46 ( V_153 , V_5 -> V_156 ) ;
}
if ( V_5 -> V_178 & V_567 ) {
V_5 -> V_367 = V_726 ;
V_7 = V_5 -> V_367 ;
} else if ( V_5 -> V_178 & V_305 ) {
V_5 -> V_367 = V_375 ;
V_7 = V_5 -> V_367 ;
} else
V_7 = 0 ;
F_31 ( V_382 , V_7 ) ;
F_24 ( 40 ) ;
F_37 ( V_5 , V_61 ) ;
F_74 ( V_5 ) ;
if ( F_23 ( V_5 , V_1079 ) &&
F_76 ( V_5 ) != V_1419 &&
F_30 ( V_5 ) != V_257 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( 0x7c00 ) ;
F_46 ( 0x7c00 , V_7 | ( 1 << 25 ) ) ;
}
F_426 ( V_5 ) ;
F_85 ( V_5 , V_308 ) ;
V_5 -> V_178 &= ~ ( V_771 |
V_569 ) ;
F_85 ( V_5 , V_316 ) ;
F_32 ( V_5 , V_1436 , & V_7 ) ;
if ( V_7 == V_1437 ) {
T_1 V_1438 ;
F_32 ( V_5 , V_1439 , & V_1438 ) ;
if ( V_1438 & V_1440 ) {
F_83 ( V_5 , V_308 ) ;
V_5 -> V_297 = V_298 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_83 ( V_5 , V_316 ) ;
F_32 ( V_5 , V_1441 , & V_1438 ) ;
if ( V_1438 & V_1442 )
V_5 -> V_178 |= V_771 ;
if ( V_1438 & V_1443 )
V_5 -> V_178 |= V_569 ;
}
}
return 0 ;
}
static int F_431 ( struct V_4 * V_5 , int V_95 , bool V_1363 )
{
int V_75 ;
F_92 ( V_5 ) ;
F_93 ( V_5 , V_95 ) ;
F_419 ( V_5 , V_1363 ) ;
V_75 = F_427 ( V_5 ) ;
F_195 ( V_5 , false ) ;
F_95 ( V_5 , V_95 ) ;
F_94 ( V_5 , V_95 ) ;
if ( V_5 -> V_1356 ) {
F_432 ( V_5 , & V_5 -> V_1444 ) ;
F_433 ( V_5 , & V_5 -> V_1445 ) ;
memset ( V_5 -> V_1356 , 0 , sizeof( struct V_1357 ) ) ;
}
return V_75 ;
}
static int F_434 ( struct V_364 * V_111 , void * V_1446 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
struct V_1447 * V_184 = V_1446 ;
int V_75 = 0 ;
bool V_693 = false ;
if ( ! F_435 ( V_184 -> V_1448 ) )
return - V_1449 ;
memcpy ( V_111 -> V_694 , V_184 -> V_1448 , V_111 -> V_1450 ) ;
if ( ! F_144 ( V_111 ) )
return 0 ;
if ( F_23 ( V_5 , V_308 ) ) {
T_1 V_1451 , V_1452 , V_1453 , V_1454 ;
V_1451 = F_33 ( V_689 ) ;
V_1452 = F_33 ( V_690 ) ;
V_1453 = F_33 ( V_1455 ) ;
V_1454 = F_33 ( V_1456 ) ;
if ( ( V_1451 != V_1453 || V_1452 != V_1454 ) &&
! ( V_1453 == 0 && V_1454 == 0 ) )
V_693 = true ;
}
F_70 ( & V_5 -> V_209 ) ;
F_195 ( V_5 , V_693 ) ;
F_436 ( V_111 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_75 ;
}
static void F_437 ( struct V_4 * V_5 , T_1 V_1457 ,
T_9 V_1115 , T_1 V_1458 ,
T_1 V_1459 )
{
F_29 ( V_5 ,
( V_1457 + V_1460 + V_1461 ) ,
( ( T_6 ) V_1115 >> 32 ) ) ;
F_29 ( V_5 ,
( V_1457 + V_1460 + V_16 ) ,
( ( T_6 ) V_1115 & 0xffffffff ) ) ;
F_29 ( V_5 ,
( V_1457 + V_1462 ) ,
V_1458 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_29 ( V_5 ,
( V_1457 + V_1463 ) ,
V_1459 ) ;
}
static void F_438 ( struct V_4 * V_5 , struct V_1464 * V_1465 )
{
int V_42 = 0 ;
if ( ! F_23 ( V_5 , V_1103 ) ) {
F_46 ( V_1466 , V_1465 -> V_1467 ) ;
F_46 ( V_1468 , V_1465 -> V_1469 ) ;
F_46 ( V_1470 , V_1465 -> V_1471 ) ;
} else {
F_46 ( V_1466 , 0 ) ;
F_46 ( V_1468 , 0 ) ;
F_46 ( V_1470 , 0 ) ;
for (; V_42 < V_5 -> V_1353 ; V_42 ++ ) {
T_1 V_161 ;
V_161 = V_1472 + V_42 * 0x18 ;
F_46 ( V_161 , V_1465 -> V_1467 ) ;
V_161 = V_1473 + V_42 * 0x18 ;
F_46 ( V_161 , V_1465 -> V_1469 ) ;
V_161 = V_1474 + V_42 * 0x18 ;
F_46 ( V_161 , V_1465 -> V_1471 ) ;
}
}
for (; V_42 < V_5 -> V_122 - 1 ; V_42 ++ ) {
F_46 ( V_1472 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1473 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1474 + V_42 * 0x18 , 0 ) ;
}
}
static void F_439 ( struct V_4 * V_5 , struct V_1464 * V_1465 )
{
int V_42 = 0 ;
T_1 V_202 = V_5 -> V_1219 ;
if ( ! F_23 ( V_5 , V_1208 ) ) {
F_46 ( V_1475 , V_1465 -> V_1476 ) ;
F_46 ( V_1477 , V_1465 -> V_1478 ) ;
F_46 ( V_1479 , V_1465 -> V_1480 ) ;
V_202 -- ;
} else {
F_46 ( V_1475 , 0 ) ;
F_46 ( V_1477 , 0 ) ;
F_46 ( V_1479 , 0 ) ;
}
for (; V_42 < V_202 ; V_42 ++ ) {
T_1 V_161 ;
V_161 = V_1062 + V_42 * 0x18 ;
F_46 ( V_161 , V_1465 -> V_1476 ) ;
V_161 = V_1481 + V_42 * 0x18 ;
F_46 ( V_161 , V_1465 -> V_1478 ) ;
V_161 = V_1482 + V_42 * 0x18 ;
F_46 ( V_161 , V_1465 -> V_1480 ) ;
}
for (; V_42 < V_5 -> V_122 - 1 ; V_42 ++ ) {
F_46 ( V_1062 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1481 + V_42 * 0x18 , 0 ) ;
F_46 ( V_1482 + V_42 * 0x18 , 0 ) ;
}
}
static void F_440 ( struct V_4 * V_5 , struct V_1464 * V_1465 )
{
F_438 ( V_5 , V_1465 ) ;
F_439 ( V_5 , V_1465 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_7 = V_1465 -> V_973 ;
F_46 ( V_1483 , V_1465 -> V_1484 ) ;
F_46 ( V_1485 , V_1465 -> V_1486 ) ;
if ( ! V_5 -> V_340 )
V_7 = 0 ;
F_46 ( V_971 , V_7 ) ;
}
}
static void F_441 ( struct V_4 * V_5 )
{
T_1 V_1487 , V_202 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_202 = V_1488 + V_1489 * 16 ;
else if ( F_23 ( V_5 , 5717_PLUS ) )
V_202 = V_1488 + V_1489 * 4 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_767 )
V_202 = V_1488 + V_1489 * 2 ;
else
V_202 = V_1488 + V_1489 ;
for ( V_1487 = V_1488 + V_1489 ;
V_1487 < V_202 ; V_1487 += V_1489 )
F_29 ( V_5 , V_1487 + V_1462 ,
V_1490 ) ;
}
static void F_442 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1487 = V_1488 ;
if ( F_23 ( V_5 , V_1103 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1487 += V_1489 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1110 )
continue;
F_437 ( V_5 , V_1487 , V_131 -> V_1352 ,
( V_1096 << V_1491 ) ,
V_38 ) ;
}
}
static void F_443 ( struct V_4 * V_5 )
{
T_1 V_1492 , V_202 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_202 = V_1493 + V_1489 * 17 ;
else if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_202 = V_1493 + V_1489 * 16 ;
else if ( F_30 ( V_5 ) == V_1494 ||
F_30 ( V_5 ) == V_767 ||
F_23 ( V_5 , 57765_CLASS ) )
V_202 = V_1493 + V_1489 * 4 ;
else
V_202 = V_1493 + V_1489 ;
for ( V_1492 = V_1493 + V_1489 ;
V_1492 < V_202 ; V_1492 += V_1489 )
F_29 ( V_5 , V_1492 + V_1462 ,
V_1490 ) ;
}
static void F_444 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_1492 = V_1493 ;
if ( F_23 ( V_5 , V_1208 ) )
V_42 ++ ;
for (; V_42 < V_5 -> V_122 ; V_42 ++ , V_1492 += V_1489 ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( ! V_131 -> V_1163 )
continue;
F_437 ( V_5 , V_1492 , V_131 -> V_1354 ,
( V_5 -> V_1206 + 1 ) <<
V_1491 , 0 ) ;
}
}
static void F_445 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_1495 ;
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
F_441 ( V_5 ) ;
F_443 ( V_5 ) ;
F_47 ( V_5 -> V_123 [ 0 ] . V_124 , 1 ) ;
V_5 -> V_123 [ 0 ] . V_1496 = 0 ;
V_5 -> V_123 [ 0 ] . V_1497 = 0 ;
V_5 -> V_123 [ 0 ] . V_1498 = 0 ;
if ( F_23 ( V_5 , V_1061 ) ) {
for ( V_42 = 1 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
V_5 -> V_123 [ V_42 ] . V_1087 = 0 ;
V_5 -> V_123 [ V_42 ] . V_147 = 0 ;
if ( F_23 ( V_5 , V_1103 ) )
F_52 ( V_5 -> V_123 [ V_42 ] . V_1322 , 0 ) ;
F_313 ( V_5 -> V_123 [ V_42 ] . V_1207 , 0 ) ;
F_47 ( V_5 -> V_123 [ V_42 ] . V_124 , 1 ) ;
V_5 -> V_123 [ V_42 ] . V_1496 = 0 ;
V_5 -> V_123 [ V_42 ] . V_1497 = 0 ;
V_5 -> V_123 [ V_42 ] . V_1498 = 0 ;
}
if ( ! F_23 ( V_5 , V_1103 ) )
F_52 ( V_5 -> V_123 [ 0 ] . V_1322 , 0 ) ;
} else {
V_5 -> V_123 [ 0 ] . V_1087 = 0 ;
V_5 -> V_123 [ 0 ] . V_147 = 0 ;
F_52 ( V_5 -> V_123 [ 0 ] . V_1322 , 0 ) ;
F_313 ( V_5 -> V_123 [ 0 ] . V_1207 , 0 ) ;
}
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
T_1 V_33 = V_1499 + V_16 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
F_390 ( V_33 + V_42 * 8 , 0 ) ;
}
memset ( V_131 -> V_134 , 0 , V_1350 ) ;
F_46 ( V_1500 + V_1461 ,
( ( T_6 ) V_131 -> V_1355 >> 32 ) ) ;
F_46 ( V_1500 + V_16 ,
( ( T_6 ) V_131 -> V_1355 & 0xffffffff ) ) ;
V_1495 = V_1501 ;
for ( V_42 = 1 , V_131 ++ ; V_42 < V_5 -> V_129 ; V_42 ++ , V_131 ++ ) {
T_6 V_1115 = ( T_6 ) V_131 -> V_1355 ;
F_46 ( V_1495 + V_1461 , V_1115 >> 32 ) ;
F_46 ( V_1495 + V_16 , V_1115 & 0xffffffff ) ;
V_1495 += 8 ;
memset ( V_131 -> V_134 , 0 , V_1350 ) ;
}
F_442 ( V_5 ) ;
F_444 ( V_5 ) ;
}
static void F_446 ( struct V_4 * V_5 )
{
T_1 V_7 , V_1502 , V_1503 , V_1504 ;
if ( ! F_23 ( V_5 , 5750_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_30 ( V_5 ) == V_1505 ||
F_30 ( V_5 ) == V_640 ||
F_23 ( V_5 , 57765_PLUS ) )
V_1502 = V_1506 ;
else if ( F_30 ( V_5 ) == V_1494 ||
F_30 ( V_5 ) == V_1507 )
V_1502 = V_1508 ;
else
V_1502 = V_1509 ;
V_1504 = F_320 ( V_1502 / 2 , V_5 -> V_1205 ) ;
V_1503 = F_447 ( T_1 , V_5 -> V_1343 / 8 , 1 ) ;
V_7 = F_320 ( V_1504 , V_1503 ) ;
F_46 ( V_1510 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1511 , V_1502 ) ;
if ( ! F_23 ( V_5 , V_521 ) || F_23 ( V_5 , 5780_CLASS ) )
return;
V_1502 = V_1512 ;
V_1503 = F_447 ( T_1 , V_5 -> V_1347 / 8 , 1 ) ;
V_7 = F_320 ( V_1502 / 2 , V_1503 ) ;
F_46 ( V_1513 , V_7 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
F_46 ( V_1514 , V_1502 ) ;
}
static inline T_1 F_448 ( unsigned char * V_626 , int V_74 )
{
T_1 V_161 ;
T_1 V_596 ;
int V_627 , V_1515 ;
V_161 = 0xffffffff ;
for ( V_627 = 0 ; V_627 < V_74 ; V_627 ++ ) {
V_161 ^= V_626 [ V_627 ] ;
for ( V_1515 = 0 ; V_1515 < 8 ; V_1515 ++ ) {
V_596 = V_161 & 0x01 ;
V_161 >>= 1 ;
if ( V_596 )
V_161 ^= 0xedb88320 ;
}
}
return ~ V_161 ;
}
static void F_449 ( struct V_4 * V_5 , unsigned int V_1516 )
{
F_46 ( V_1517 , V_1516 ? 0xffffffff : 0 ) ;
F_46 ( V_1518 , V_1516 ? 0xffffffff : 0 ) ;
F_46 ( V_1519 , V_1516 ? 0xffffffff : 0 ) ;
F_46 ( V_1520 , V_1516 ? 0xffffffff : 0 ) ;
}
static void F_436 ( struct V_364 * V_111 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
T_1 V_354 ;
V_354 = V_5 -> V_354 & ~ ( V_1521 |
V_1203 ) ;
#if ! F_359 ( V_1522 ) && ! F_359 ( V_1523 )
if ( ! F_23 ( V_5 , V_308 ) )
V_354 |= V_1203 ;
#endif
if ( V_111 -> V_10 & V_1524 ) {
V_354 |= V_1521 ;
} else if ( V_111 -> V_10 & V_1525 ) {
F_449 ( V_5 , 1 ) ;
} else if ( F_450 ( V_111 ) ) {
F_449 ( V_5 , 0 ) ;
} else {
struct V_1526 * V_1527 ;
T_1 V_1528 [ 4 ] = { 0 , } ;
T_1 V_1529 ;
T_1 V_44 ;
T_1 V_1530 ;
F_451 (ha, dev) {
V_1530 = F_448 ( V_1527 -> V_184 , V_1531 ) ;
V_44 = ~ V_1530 & 0x7f ;
V_1529 = ( V_44 & 0x60 ) >> 5 ;
V_44 &= 0x1f ;
V_1528 [ V_1529 ] |= ( 1 << V_44 ) ;
}
F_46 ( V_1517 , V_1528 [ 0 ] ) ;
F_46 ( V_1518 , V_1528 [ 1 ] ) ;
F_46 ( V_1519 , V_1528 [ 2 ] ) ;
F_46 ( V_1520 , V_1528 [ 3 ] ) ;
}
if ( F_452 ( V_111 ) > F_453 ( V_5 ) ) {
V_354 |= V_1521 ;
} else if ( ! ( V_111 -> V_10 & V_1524 ) ) {
int V_42 = 0 ;
struct V_1526 * V_1527 ;
F_454 (ha, dev) {
F_194 ( V_5 , V_1527 -> V_184 ,
V_42 + F_455 ( V_5 ) ) ;
V_42 ++ ;
}
}
if ( V_354 != V_5 -> V_354 ) {
V_5 -> V_354 = V_354 ;
F_31 ( V_361 , V_354 ) ;
F_24 ( 10 ) ;
}
}
static void F_456 ( struct V_4 * V_5 , T_1 V_1532 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1533 ; V_42 ++ )
V_5 -> V_1534 [ V_42 ] = F_457 ( V_42 , V_1532 ) ;
}
static void F_458 ( struct V_4 * V_5 )
{
int V_42 ;
if ( ! F_23 ( V_5 , V_1061 ) )
return;
if ( V_5 -> V_1219 == 1 ) {
memset ( & V_5 -> V_1534 [ 0 ] , 0 , sizeof( V_5 -> V_1534 ) ) ;
return;
}
for ( V_42 = 0 ; V_42 < V_1533 ; V_42 ++ ) {
if ( V_5 -> V_1534 [ V_42 ] >= V_5 -> V_1219 )
break;
}
if ( V_42 != V_1533 )
F_456 ( V_5 , V_5 -> V_1219 ) ;
}
static void F_459 ( struct V_4 * V_5 )
{
int V_42 = 0 ;
T_1 V_161 = V_1535 ;
while ( V_42 < V_1533 ) {
T_1 V_7 = V_5 -> V_1534 [ V_42 ] ;
V_42 ++ ;
for (; V_42 % 8 ; V_42 ++ ) {
V_7 <<= 4 ;
V_7 |= V_5 -> V_1534 [ V_42 ] ;
}
F_46 ( V_161 , V_7 ) ;
V_161 += 4 ;
}
}
static inline T_1 F_460 ( struct V_4 * V_5 )
{
if ( F_30 ( V_5 ) == V_477 )
return V_1536 ;
else
return V_1537 ;
}
static int F_461 ( struct V_4 * V_5 , bool V_1538 )
{
T_1 V_7 , V_1539 ;
int V_42 , V_75 , V_202 ;
struct V_1127 * V_1128 = & V_5 -> V_123 [ 0 ] . V_1089 ;
F_45 ( V_5 ) ;
F_92 ( V_5 ) ;
F_93 ( V_5 , V_96 ) ;
if ( F_23 ( V_5 , V_562 ) )
F_419 ( V_5 , 1 ) ;
if ( ( V_5 -> V_178 & V_569 ) &&
! ( V_5 -> V_178 & V_1540 ) ) {
F_209 ( V_5 ) ;
F_131 ( V_5 , NULL ) ;
V_5 -> V_178 |= V_1540 ;
}
if ( V_5 -> V_178 & V_338 )
F_222 ( V_5 ) ;
if ( V_1538 )
F_143 ( V_5 ) ;
V_75 = F_427 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_95 ( V_5 , V_96 ) ;
if ( F_145 ( V_5 ) == V_503 ) {
V_7 = F_33 ( V_504 ) ;
V_7 &= ~ ( V_1541 | V_1542 ) ;
F_46 ( V_504 , V_7 ) ;
V_7 = F_33 ( V_1543 ) ;
V_7 &= ~ V_1544 ;
V_7 |= V_1545 ;
F_46 ( V_1543 , V_7 ) ;
V_7 = F_33 ( V_1546 ) ;
V_7 &= ~ V_1547 ;
V_7 |= V_1548 ;
F_46 ( V_1546 , V_7 ) ;
V_7 = F_33 ( V_1549 ) ;
V_7 &= ~ V_1550 ;
V_7 |= V_1551 ;
F_46 ( V_1549 , V_7 ) ;
}
if ( F_30 ( V_5 ) == V_1411 ) {
V_7 = F_33 ( V_975 ) & ~ V_976 ;
V_7 |= V_1552 |
V_1553 ;
F_46 ( V_975 , V_7 ) ;
V_7 = F_33 ( V_1554 ) & ~ V_1555 ;
F_46 ( V_1554 , V_7 | V_1556 ) ;
F_46 ( V_1557 , V_1558 ) ;
V_7 = F_33 ( V_1412 ) & ~ V_1413 ;
F_46 ( V_1412 , V_7 | V_1414 ) ;
}
if ( F_23 ( V_5 , V_1559 ) ) {
T_1 V_644 = F_33 ( V_646 ) ;
V_7 = V_644 & ~ V_1560 ;
F_46 ( V_646 , V_7 | V_1561 ) ;
V_7 = F_33 ( V_1080 + V_1562 ) ;
F_46 ( V_1080 + V_1562 ,
V_7 | V_1563 ) ;
F_46 ( V_646 , V_644 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) ) {
if ( F_76 ( V_5 ) == V_327 ) {
T_1 V_644 = F_33 ( V_646 ) ;
V_7 = V_644 & ~ V_1560 ;
F_46 ( V_646 , V_7 | V_1561 ) ;
V_7 = F_33 ( V_1080 +
V_1564 ) ;
F_46 ( V_1080 + V_1564 ,
V_7 | V_1565 ) ;
F_46 ( V_646 , V_644 ) ;
}
if ( F_145 ( V_5 ) != V_1566 ) {
T_1 V_644 ;
V_7 = F_33 ( V_1567 ) ;
V_7 |= V_1568 ;
F_46 ( V_1567 , V_7 ) ;
V_644 = F_33 ( V_646 ) ;
V_7 = V_644 & ~ V_1560 ;
F_46 ( V_646 , V_7 | V_1569 ) ;
V_7 = F_33 ( V_1080 +
V_1570 ) ;
V_7 &= ~ V_1571 ;
F_46 ( V_1080 + V_1570 ,
V_7 | V_1572 ) ;
F_46 ( V_646 , V_644 ) ;
}
V_7 = F_33 ( V_1543 ) ;
V_7 &= ~ V_1544 ;
V_7 |= V_1545 ;
F_46 ( V_1543 , V_7 ) ;
}
if ( ! F_23 ( V_5 , V_152 ) ) {
if ( ! F_23 ( V_5 , V_1079 ) )
V_5 -> V_156 |= V_1573 ;
F_31 ( V_153 , V_5 -> V_156 ) ;
}
if ( F_76 ( V_5 ) == V_918 &&
F_23 ( V_5 , V_841 ) ) {
V_7 = F_33 ( V_1241 ) ;
V_7 |= V_1388 ;
F_46 ( V_1241 , V_7 ) ;
}
if ( F_23 ( V_5 , V_60 ) ) {
V_7 = F_33 ( V_1241 ) ;
V_7 |= V_1389 |
V_1390 |
V_1391 ;
F_46 ( V_1241 , V_7 ) ;
}
if ( F_145 ( V_5 ) == V_1574 ) {
V_7 = F_33 ( V_1575 ) ;
V_7 |= ( 1 << 26 ) | ( 1 << 28 ) | ( 1 << 29 ) ;
F_46 ( V_1575 , V_7 ) ;
}
V_75 = F_409 ( V_5 ) ;
if ( V_75 )
return V_75 ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1576 ) &
~ V_1577 ;
if ( F_76 ( V_5 ) == V_327 )
V_7 &= ~ V_1578 ;
if ( ! F_23 ( V_5 , 57765_CLASS ) &&
F_30 ( V_5 ) != V_476 &&
F_30 ( V_5 ) != V_767 )
V_7 |= V_1579 ;
F_46 ( V_1576 , V_7 | V_5 -> V_1580 ) ;
} else if ( F_30 ( V_5 ) != V_413 &&
F_30 ( V_5 ) != V_45 ) {
F_46 ( V_1576 , V_5 -> V_1580 ) ;
}
V_5 -> V_644 &= ~ ( V_1581 |
V_1582 |
V_1583 |
V_1584 ) ;
V_5 -> V_644 |= V_1581 ;
V_5 -> V_644 |= V_1583 ;
V_7 = V_1585 | V_1586 ;
if ( V_5 -> V_1587 )
F_46 ( V_1588 ,
V_5 -> V_1587 | V_1589 ) ;
if ( F_23 ( V_5 , V_992 ) )
V_7 |= V_1590 ;
F_46 ( V_646 , V_5 -> V_644 | V_7 ) ;
V_7 = F_33 ( V_497 ) ;
V_7 &= ~ 0xff ;
V_7 |= ( 65 << V_968 ) ;
F_46 ( V_497 , V_7 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
} else if ( F_30 ( V_5 ) != V_501 ) {
F_46 ( V_1591 , V_1592 ) ;
if ( F_30 ( V_5 ) == V_500 )
F_46 ( V_1593 , V_1594 ) ;
else
F_46 ( V_1593 , V_1595 ) ;
F_46 ( V_1596 , V_1597 ) ;
F_46 ( V_1598 , V_1599 ) ;
} else if ( F_23 ( V_5 , V_1600 ) ) {
int V_661 ;
V_661 = V_5 -> V_661 ;
V_661 = ( V_661 + ( 0x80 - 1 ) ) & ~ ( 0x80 - 1 ) ;
F_46 ( V_1591 ,
V_684 + V_661 ) ;
F_46 ( V_1593 ,
V_1601 - V_661 - 0xa00 ) ;
}
if ( V_5 -> V_111 -> V_1198 <= V_1333 ) {
F_46 ( V_1602 ,
V_5 -> V_1603 . V_1604 ) ;
F_46 ( V_1605 ,
V_5 -> V_1603 . V_1606 ) ;
F_46 ( V_1607 ,
V_5 -> V_1603 . V_1608 ) ;
} else {
F_46 ( V_1602 ,
V_5 -> V_1603 . V_1609 ) ;
F_46 ( V_1605 ,
V_5 -> V_1603 . V_1610 ) ;
F_46 ( V_1607 ,
V_5 -> V_1603 . V_1611 ) ;
}
F_46 ( V_1612 ,
V_5 -> V_1603 . V_1613 ) ;
F_46 ( V_1614 ,
V_5 -> V_1603 . V_1615 ) ;
V_7 = V_1382 | V_1616 ;
if ( F_30 ( V_5 ) == V_477 )
V_7 |= V_1617 ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_767 ||
F_76 ( V_5 ) == V_1618 ||
F_76 ( V_5 ) == V_1619 )
V_7 |= V_1620 ;
F_46 ( V_1064 , V_7 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
if ( F_33 ( V_1064 ) & V_1382 )
break;
F_24 ( 10 ) ;
}
if ( V_42 >= 2000 ) {
F_185 ( V_5 -> V_111 , L_54 , V_657 ) ;
return - V_82 ;
}
if ( F_76 ( V_5 ) == V_1621 )
F_46 ( V_1622 , ( F_33 ( V_1622 ) & ~ 0x3 ) | 0x2 ) ;
F_446 ( V_5 ) ;
F_46 ( V_1623 + V_1460 + V_1461 ,
( ( T_6 ) V_1128 -> V_1348 >> 32 ) ) ;
F_46 ( V_1623 + V_1460 + V_16 ,
( ( T_6 ) V_1128 -> V_1348 & 0xffffffff ) ) ;
if ( ! F_23 ( V_5 , 5717_PLUS ) )
F_46 ( V_1623 + V_1463 ,
V_1624 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1625 + V_1462 ,
V_1490 ) ;
if ( F_76 ( V_5 ) == V_1618 ||
( F_23 ( V_5 , V_521 ) && ! F_23 ( V_5 , 5780_CLASS ) ) ) {
if ( F_23 ( V_5 , V_1345 ) ) {
F_46 ( V_1054 + V_1460 + V_1461 ,
( ( T_6 ) V_1128 -> V_1349 >> 32 ) ) ;
F_46 ( V_1054 + V_1460 + V_16 ,
( ( T_6 ) V_1128 -> V_1349 & 0xffffffff ) ) ;
V_7 = F_462 ( V_5 ) <<
V_1491 ;
F_46 ( V_1054 + V_1462 ,
V_7 | V_1626 ) ;
if ( ! F_23 ( V_5 , V_1308 ) ||
F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_767 )
F_46 ( V_1054 + V_1463 ,
V_1627 ) ;
} else {
F_46 ( V_1054 + V_1462 ,
V_1490 ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_463 ( V_5 ) ;
V_7 <<= V_1491 ;
V_7 |= ( V_1337 << 2 ) ;
} else
V_7 = V_1337 << V_1491 ;
} else
V_7 = V_1628 << V_1491 ;
F_46 ( V_1623 + V_1462 , V_7 ) ;
V_1128 -> V_1090 = V_5 -> V_1343 ;
F_313 ( V_18 , V_1128 -> V_1090 ) ;
V_1128 -> V_1092 =
F_23 ( V_5 , V_1345 ) ? V_5 -> V_1347 : 0 ;
F_313 ( V_1209 , V_1128 -> V_1092 ) ;
F_445 ( V_5 ) ;
F_195 ( V_5 , false ) ;
F_46 ( V_1629 ,
V_5 -> V_111 -> V_1198 + V_1199 + V_1181 + V_1630 ) ;
V_7 = ( 2 << V_387 ) |
( 6 << V_388 ) |
( 32 << V_389 ) ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_767 )
V_7 |= F_33 ( V_386 ) &
( V_969 |
V_970 ) ;
F_46 ( V_386 , V_7 ) ;
F_46 ( V_1631 , V_1632 ) ;
F_46 ( V_1633 , 0x0181 ) ;
V_1539 = ( V_1376 | V_1634 |
V_1635 | V_1636 |
V_1637 | V_1638 |
V_1639 | V_1640 |
V_1641 ) ;
if ( F_30 ( V_5 ) == V_476 )
V_1539 |= V_1642 ;
if ( F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1411 )
V_1539 |= V_1643 |
V_1644 |
V_1645 ;
if ( F_30 ( V_5 ) == V_501 &&
F_76 ( V_5 ) != V_1434 ) {
if ( F_23 ( V_5 , V_1600 ) &&
F_30 ( V_5 ) == V_501 ) {
V_1539 |= V_1646 ;
} else if ( ! ( F_33 ( V_1241 ) & V_1647 ) &&
! F_23 ( V_5 , V_1648 ) ) {
V_1539 |= V_1649 ;
}
}
if ( F_23 ( V_5 , V_1079 ) )
V_1539 |= V_1649 ;
if ( F_30 ( V_5 ) == V_667 ) {
V_5 -> V_1257 = 0 ;
if ( V_5 -> V_111 -> V_1198 <= V_1333 ) {
V_1539 |= V_1650 ;
V_5 -> V_1257 = V_1651 ;
}
}
if ( F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ||
F_23 ( V_5 , V_1300 ) )
V_1539 |= V_1652 ;
if ( F_23 ( V_5 , 57765_PLUS ) ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1411 )
V_1539 |= V_1653 ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_767 )
V_1539 |= F_33 ( V_1065 ) & V_1654 ;
if ( F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1411 ||
F_23 ( V_5 , 57765_PLUS ) ) {
T_1 V_1655 ;
if ( F_30 ( V_5 ) == V_767 )
V_1655 = V_1656 ;
else
V_1655 = V_1657 ;
V_7 = F_33 ( V_1655 ) ;
if ( F_76 ( V_5 ) == V_1618 ||
F_30 ( V_5 ) == V_767 ) {
V_7 &= ~ ( V_1658 |
V_1659 |
V_1660 ) ;
V_7 |= V_1661 |
V_1662 |
V_1663 ;
}
F_46 ( V_1655 , V_7 | V_1664 ) ;
}
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_767 ) {
T_1 V_1655 ;
if ( F_30 ( V_5 ) == V_767 )
V_1655 = V_1665 ;
else
V_1655 = V_1666 ;
V_7 = F_33 ( V_1655 ) ;
F_46 ( V_1655 , V_7 |
V_1667 |
V_1668 ) ;
}
if ( F_23 ( V_5 , 5750_PLUS ) ) {
V_7 = F_33 ( V_1669 ) ;
V_7 &= ~ V_1670 ;
F_46 ( V_1669 , V_7 ) ;
} else if ( ( V_1539 & V_1646 ) &&
F_23 ( V_5 , V_1600 ) ) {
V_7 = F_33 ( V_1669 ) ;
V_7 &= ~ V_1671 ;
F_46 ( V_1669 , V_7 ) ;
} else {
F_46 ( V_1669 , 0xffffff ) ;
}
F_46 ( V_1672 , V_1673 ) ;
F_46 ( V_1674 , 0xffffff ) ;
F_46 ( V_1675 ,
( V_1676 |
V_1677 ) ) ;
F_46 ( V_138 , 0 ) ;
for ( V_42 = 0 ; V_42 < 2000 ; V_42 ++ ) {
if ( ! ( F_33 ( V_138 ) & V_128 ) )
break;
F_24 ( 10 ) ;
}
F_440 ( V_5 , & V_5 -> V_972 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_46 ( V_1678 + V_1461 ,
( ( T_6 ) V_5 -> V_1358 >> 32 ) ) ;
F_46 ( V_1678 + V_16 ,
( ( T_6 ) V_5 -> V_1358 & 0xffffffff ) ) ;
F_46 ( V_1679 , V_37 ) ;
F_46 ( V_1680 , V_1681 ) ;
for ( V_42 = V_37 ;
V_42 < V_1681 + V_1350 ;
V_42 += sizeof( T_1 ) ) {
F_29 ( V_5 , V_42 , 0 ) ;
F_24 ( 40 ) ;
}
}
F_46 ( V_138 , V_128 | V_5 -> V_127 ) ;
F_46 ( V_1058 , V_1372 | V_1682 ) ;
F_46 ( V_1051 , V_1368 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1059 , V_1369 | V_1683 ) ;
if ( V_5 -> V_178 & V_305 ) {
V_5 -> V_178 &= ~ V_790 ;
F_31 ( V_361 , V_1330 ) ;
F_24 ( 10 ) ;
}
V_5 -> V_367 |= V_1684 | V_1685 |
V_732 | V_1686 |
V_1687 ;
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_367 |= V_730 | V_731 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_567 ) &&
F_30 ( V_5 ) != V_536 )
V_5 -> V_367 |= V_725 ;
F_31 ( V_382 , V_5 -> V_367 | V_1688 | V_1689 ) ;
F_24 ( 40 ) ;
if ( ! F_23 ( V_5 , V_532 ) ) {
T_1 V_1690 ;
V_1690 = V_540 | V_538 |
V_541 | V_542 |
V_539 | V_546 ;
if ( F_30 ( V_5 ) == V_640 )
V_1690 |= V_549 |
V_1691 ;
if ( F_30 ( V_5 ) == V_1494 )
V_1690 |= V_1692 ;
V_5 -> V_22 &= ~ V_1690 ;
V_5 -> V_22 |= F_33 ( V_136 ) & V_1690 ;
if ( F_23 ( V_5 , V_643 ) )
V_5 -> V_22 |= ( V_538 |
V_539 ) ;
}
F_31 ( V_136 , V_5 -> V_22 ) ;
F_24 ( 100 ) ;
if ( F_23 ( V_5 , V_1693 ) ) {
V_7 = F_33 ( V_1075 ) ;
V_7 |= V_1405 ;
if ( V_5 -> V_129 > 1 )
V_7 |= V_1694 ;
if ( ! F_23 ( V_5 , 1SHOT_MSI ) )
V_7 |= V_1695 ;
F_46 ( V_1075 , V_7 ) ;
}
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
F_31 ( V_1076 , V_1378 ) ;
F_24 ( 40 ) ;
}
V_7 = ( V_1380 | V_1696 |
V_1697 | V_1698 |
V_1699 | V_1700 |
V_1701 | V_1702 |
V_1703 ) ;
if ( F_30 ( V_5 ) == V_501 &&
F_76 ( V_5 ) != V_1434 ) {
if ( F_23 ( V_5 , V_1600 ) &&
( F_76 ( V_5 ) == V_1704 ||
F_76 ( V_5 ) == V_1705 ) ) {
} else if ( ! ( F_33 ( V_1241 ) & V_1647 ) &&
! F_23 ( V_5 , V_1648 ) ) {
V_7 |= V_1706 ;
}
}
if ( F_23 ( V_5 , 5755_PLUS ) )
V_7 |= V_1707 ;
if ( F_30 ( V_5 ) == V_257 )
V_7 |= V_1708 ;
F_31 ( V_1066 , V_7 ) ;
F_24 ( 40 ) ;
if ( F_23 ( V_5 , V_841 ) ) {
T_3 V_1396 ;
F_421 ( V_5 -> V_12 , V_5 -> V_1397 + V_1398 ,
& V_1396 ) ;
if ( F_30 ( V_5 ) == V_499 ) {
V_1396 &= ~ V_1709 ;
V_1396 |= V_1710 ;
} else if ( F_30 ( V_5 ) == V_500 ) {
V_1396 &= ~ ( V_1711 | V_1709 ) ;
V_1396 |= V_1710 ;
}
F_423 ( V_5 -> V_12 , V_5 -> V_1397 + V_1398 ,
V_1396 ) ;
}
F_31 ( V_1065 , V_1539 ) ;
F_24 ( 40 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) {
for ( V_42 = 0 ; V_42 < V_1712 ; V_42 ++ ) {
if ( F_33 ( V_1713 + ( V_42 << 2 ) ) > F_464 ( V_5 ) )
break;
}
if ( V_42 < V_1712 ) {
V_7 = F_33 ( V_1666 ) ;
V_7 |= F_460 ( V_5 ) ;
F_46 ( V_1666 , V_7 ) ;
F_83 ( V_5 , 5719_5720_RDMA_BUG ) ;
}
}
F_46 ( V_1056 , V_1371 | V_1714 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_46 ( V_1060 , V_1381 ) ;
if ( F_30 ( V_5 ) == V_45 )
F_46 ( V_1047 ,
V_1377 | V_1715 ) ;
else
F_46 ( V_1047 , V_1377 ) ;
F_46 ( V_1050 , V_1379 | V_1716 ) ;
F_46 ( V_1057 , V_1367 | V_1717 ) ;
V_7 = V_1370 | V_1718 ;
if ( F_23 ( V_5 , V_1719 ) )
V_7 |= V_1720 ;
F_46 ( V_1053 , V_7 ) ;
F_46 ( V_1046 , V_1375 ) ;
if ( F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ||
F_23 ( V_5 , V_1300 ) )
F_46 ( V_1046 , V_1375 | 0x8 ) ;
V_7 = V_1374 | V_1721 ;
if ( F_23 ( V_5 , V_1103 ) )
V_7 |= V_1722 ;
F_46 ( V_1049 , V_7 ) ;
F_46 ( V_1048 , V_1373 | V_1723 ) ;
if ( F_76 ( V_5 ) == V_759 ) {
V_75 = F_190 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
if ( F_30 ( V_5 ) == V_667 ) {
F_192 ( V_5 ) ;
}
if ( F_23 ( V_5 , V_1600 ) ) {
V_75 = F_193 ( V_5 ) ;
if ( V_75 )
return V_75 ;
}
V_5 -> V_356 = V_1365 ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
V_5 -> V_356 |= V_1724 ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_767 ) {
V_7 = V_1725 | V_1726 ;
V_5 -> V_356 &= ~ V_7 ;
V_5 -> V_356 |= F_33 ( V_363 ) & V_7 ;
}
F_31 ( V_363 , V_5 -> V_356 ) ;
F_24 ( 100 ) ;
if ( F_23 ( V_5 , V_1208 ) ) {
T_1 V_1727 [ 10 ] ;
F_459 ( V_5 ) ;
F_465 ( V_1727 , 10 * sizeof( T_1 ) ) ;
for ( V_42 = 0 ; V_42 < 10 ; V_42 ++ )
F_46 ( V_1728 + V_42 * 4 , V_1727 [ V_42 ] ) ;
}
V_5 -> V_354 = V_733 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_5 -> V_354 |= V_1729 ;
if ( F_30 ( V_5 ) == V_767 )
V_5 -> V_354 |= V_1730 ;
if ( F_23 ( V_5 , V_1208 ) )
V_5 -> V_354 |= V_1731 |
V_1732 |
V_1733 |
V_1734 |
V_1735 |
V_1736 ;
F_31 ( V_361 , V_5 -> V_354 ) ;
F_24 ( 10 ) ;
F_46 ( V_727 , V_5 -> V_563 ) ;
F_46 ( V_383 , V_385 ) ;
if ( V_5 -> V_178 & V_567 ) {
F_31 ( V_361 , V_1330 ) ;
F_24 ( 10 ) ;
}
F_31 ( V_361 , V_5 -> V_354 ) ;
F_24 ( 10 ) ;
if ( V_5 -> V_178 & V_567 ) {
if ( ( F_30 ( V_5 ) == V_500 ) &&
! ( V_5 -> V_178 & V_1737 ) ) {
V_7 = F_33 ( V_573 ) ;
V_7 &= 0xfffff000 ;
V_7 |= 0x880 ;
F_46 ( V_573 , V_7 ) ;
}
if ( F_76 ( V_5 ) == V_1738 )
F_46 ( V_573 , 0x616000 ) ;
}
if ( F_23 ( V_5 , 57765_CLASS ) )
V_7 = 1 ;
else
V_7 = 2 ;
F_31 ( V_1739 , V_7 ) ;
if ( F_30 ( V_5 ) == V_500 &&
( V_5 -> V_178 & V_567 ) ) {
F_83 ( V_5 , V_940 ) ;
}
if ( ( V_5 -> V_178 & V_305 ) &&
F_30 ( V_5 ) == V_548 ) {
T_1 V_596 ;
V_596 = F_33 ( V_1740 ) ;
F_46 ( V_1740 , V_596 | V_1741 ) ;
V_5 -> V_22 &= ~ V_1742 ;
V_5 -> V_22 |= V_1743 ;
F_46 ( V_136 , V_5 -> V_22 ) ;
}
if ( ! F_23 ( V_5 , V_267 ) ) {
if ( V_5 -> V_178 & V_399 )
V_5 -> V_178 &= ~ V_399 ;
V_75 = F_201 ( V_5 , false ) ;
if ( V_75 )
return V_75 ;
if ( ! ( V_5 -> V_178 & V_567 ) &&
! ( V_5 -> V_178 & V_179 ) ) {
T_1 V_596 ;
if ( ! F_57 ( V_5 , V_519 , & V_596 ) ) {
F_59 ( V_5 , V_519 ,
V_596 | V_1744 ) ;
F_57 ( V_5 , V_1745 , & V_596 ) ;
}
}
}
F_436 ( V_5 -> V_111 ) ;
F_46 ( V_1746 , 0xc2000000 & V_1747 ) ;
F_46 ( V_1748 , 0xffffffff & V_1747 ) ;
F_46 ( V_1749 , 0x86000004 & V_1747 ) ;
F_46 ( V_1750 , 0xffffffff & V_1747 ) ;
if ( F_23 ( V_5 , 5705_PLUS ) && ! F_23 ( V_5 , 5780_CLASS ) )
V_202 = 8 ;
else
V_202 = 16 ;
if ( F_23 ( V_5 , V_308 ) )
V_202 -= 4 ;
switch ( V_202 ) {
case 16 :
F_46 ( V_1751 , 0 ) ; F_46 ( V_1752 , 0 ) ;
case 15 :
F_46 ( V_1753 , 0 ) ; F_46 ( V_1754 , 0 ) ;
case 14 :
F_46 ( V_1755 , 0 ) ; F_46 ( V_1756 , 0 ) ;
case 13 :
F_46 ( V_1757 , 0 ) ; F_46 ( V_1758 , 0 ) ;
case 12 :
F_46 ( V_1759 , 0 ) ; F_46 ( V_1760 , 0 ) ;
case 11 :
F_46 ( V_1761 , 0 ) ; F_46 ( V_1762 , 0 ) ;
case 10 :
F_46 ( V_1763 , 0 ) ; F_46 ( V_1764 , 0 ) ;
case 9 :
F_46 ( V_1765 , 0 ) ; F_46 ( V_1766 , 0 ) ;
case 8 :
F_46 ( V_1767 , 0 ) ; F_46 ( V_1768 , 0 ) ;
case 7 :
F_46 ( V_1769 , 0 ) ; F_46 ( V_1770 , 0 ) ;
case 6 :
F_46 ( V_1771 , 0 ) ; F_46 ( V_1772 , 0 ) ;
case 5 :
F_46 ( V_1773 , 0 ) ; F_46 ( V_1774 , 0 ) ;
case 4 :
case 3 :
case 2 :
case 1 :
default:
break;
}
if ( F_23 ( V_5 , V_60 ) )
F_11 ( V_5 , V_1775 ,
V_1776 ) ;
F_94 ( V_5 , V_96 ) ;
return 0 ;
}
static int F_466 ( struct V_4 * V_5 , bool V_1538 )
{
F_196 ( V_5 ) ;
F_96 ( V_5 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
return F_461 ( V_5 , V_1538 ) ;
}
static void F_467 ( struct V_4 * V_5 , struct V_1777 * V_1778 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_1779 ; V_42 ++ , V_1778 ++ ) {
T_1 V_6 = V_42 * V_1780 , V_74 = V_1780 ;
F_40 ( V_5 , ( T_1 * ) V_1778 , V_6 , V_74 ) ;
V_6 += V_74 ;
if ( V_1778 -> V_1781 != V_1782 ||
! ( V_1778 -> V_1783 & V_1784 ) )
memset ( V_1778 , 0 , V_1780 ) ;
}
}
static T_16 F_468 ( struct V_543 * V_111 ,
struct V_1785 * V_1786 , char * V_626 )
{
struct V_1787 * V_1788 = F_469 ( V_1786 ) ;
struct V_4 * V_5 = F_470 ( V_111 ) ;
T_1 V_1789 ;
F_70 ( & V_5 -> V_209 ) ;
F_40 ( V_5 , & V_1789 , V_1788 -> V_686 ,
sizeof( V_1789 ) ) ;
F_71 ( & V_5 -> V_209 ) ;
return sprintf ( V_626 , L_55 , V_1789 * 1000 ) ;
}
static void F_471 ( struct V_4 * V_5 )
{
if ( V_5 -> V_1790 ) {
F_472 ( V_5 -> V_1790 ) ;
V_5 -> V_1790 = NULL ;
}
}
static void F_473 ( struct V_4 * V_5 )
{
int V_42 ;
T_1 V_634 = 0 ;
struct V_1791 * V_12 = V_5 -> V_12 ;
struct V_1777 V_1792 [ V_1779 ] ;
F_467 ( V_5 , V_1792 ) ;
for ( V_42 = 0 ; V_42 < V_1779 ; V_42 ++ ) {
if ( ! V_1792 [ V_42 ] . V_1793 )
continue;
V_634 += V_1792 [ V_42 ] . V_1794 ;
V_634 += V_1792 [ V_42 ] . V_1793 ;
}
if ( ! V_634 )
return;
V_5 -> V_1790 = F_474 ( & V_12 -> V_111 , L_56 ,
V_5 , V_1795 ) ;
if ( F_115 ( V_5 -> V_1790 ) ) {
V_5 -> V_1790 = NULL ;
F_116 ( & V_12 -> V_111 , L_57 ) ;
}
}
static void F_475 ( struct V_4 * V_5 )
{
struct V_1357 * V_1796 = V_5 -> V_1356 ;
if ( ! V_5 -> V_340 )
return;
F_476 ( & V_1796 -> V_1797 , V_1798 ) ;
F_476 ( & V_1796 -> V_1799 , V_1800 ) ;
F_476 ( & V_1796 -> V_1801 , V_1802 ) ;
F_476 ( & V_1796 -> V_1803 , V_1804 ) ;
F_476 ( & V_1796 -> V_1805 , V_1806 ) ;
F_476 ( & V_1796 -> V_1807 , V_1808 ) ;
F_476 ( & V_1796 -> V_1809 , V_1810 ) ;
F_476 ( & V_1796 -> V_1811 , V_1812 ) ;
F_476 ( & V_1796 -> V_1813 , V_1814 ) ;
F_476 ( & V_1796 -> V_1815 , V_1816 ) ;
F_476 ( & V_1796 -> V_1817 , V_1818 ) ;
F_476 ( & V_1796 -> V_1819 , V_1820 ) ;
F_476 ( & V_1796 -> V_1821 , V_1822 ) ;
if ( F_267 ( F_23 ( V_5 , 5719_5720_RDMA_BUG ) &&
( V_1796 -> V_1817 . V_485 + V_1796 -> V_1819 . V_485 +
V_1796 -> V_1821 . V_485 ) > V_1712 ) ) {
T_1 V_7 ;
V_7 = F_33 ( V_1666 ) ;
V_7 &= ~ F_460 ( V_5 ) ;
F_46 ( V_1666 , V_7 ) ;
F_85 ( V_5 , 5719_5720_RDMA_BUG ) ;
}
F_476 ( & V_1796 -> V_1823 , V_1824 ) ;
F_476 ( & V_1796 -> V_1825 , V_1826 ) ;
F_476 ( & V_1796 -> V_1827 , V_1828 ) ;
F_476 ( & V_1796 -> V_1829 , V_1830 ) ;
F_476 ( & V_1796 -> V_1831 , V_1832 ) ;
F_476 ( & V_1796 -> V_1833 , V_1834 ) ;
F_476 ( & V_1796 -> V_1835 , V_1836 ) ;
F_476 ( & V_1796 -> V_1837 , V_1838 ) ;
F_476 ( & V_1796 -> V_1839 , V_1840 ) ;
F_476 ( & V_1796 -> V_1841 , V_1842 ) ;
F_476 ( & V_1796 -> V_1843 , V_1844 ) ;
F_476 ( & V_1796 -> V_1845 , V_1846 ) ;
F_476 ( & V_1796 -> V_1847 , V_1848 ) ;
F_476 ( & V_1796 -> V_1849 , V_1850 ) ;
F_476 ( & V_1796 -> V_1851 , V_1852 ) ;
if ( F_30 ( V_5 ) != V_476 &&
F_30 ( V_5 ) != V_767 &&
F_76 ( V_5 ) != V_1618 &&
F_76 ( V_5 ) != V_1619 ) {
F_476 ( & V_1796 -> V_1853 , V_1854 ) ;
} else {
T_1 V_7 = F_33 ( V_1228 ) ;
V_7 = ( V_7 & V_1229 ) ? 1 : 0 ;
if ( V_7 ) {
F_46 ( V_1228 , V_1229 ) ;
V_1796 -> V_1853 . V_485 += V_7 ;
if ( V_1796 -> V_1853 . V_485 < V_7 )
V_1796 -> V_1853 . V_486 += 1 ;
}
V_1796 -> V_1855 = V_1796 -> V_1853 ;
}
F_476 ( & V_1796 -> V_1856 , V_1857 ) ;
}
static void F_477 ( struct V_4 * V_5 )
{
T_1 V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
if ( F_50 ( V_131 ) ) {
if ( V_131 -> V_1497 == V_131 -> V_149 &&
V_131 -> V_1498 == V_131 -> V_147 ) {
if ( V_131 -> V_1496 < 1 ) {
V_131 -> V_1496 ++ ;
return;
}
F_348 ( 0 , V_131 ) ;
}
}
V_131 -> V_1496 = 0 ;
V_131 -> V_1497 = V_131 -> V_149 ;
V_131 -> V_1498 = V_131 -> V_147 ;
}
}
static void F_478 ( unsigned long V_1858 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1858 ;
F_316 ( & V_5 -> V_209 ) ;
if ( V_5 -> V_125 || F_23 ( V_5 , V_1223 ) ) {
F_317 ( & V_5 -> V_209 ) ;
goto V_1859;
}
if ( F_30 ( V_5 ) == V_476 ||
F_23 ( V_5 , 57765_CLASS ) )
F_477 ( V_5 ) ;
if ( F_23 ( V_5 , V_30 ) ) {
F_33 ( V_138 ) ;
}
if ( ! F_23 ( V_5 , V_133 ) ) {
if ( V_5 -> V_123 [ 0 ] . V_134 -> V_57 & V_135 ) {
F_46 ( V_136 ,
V_5 -> V_22 | V_137 ) ;
} else {
F_46 ( V_138 , V_5 -> V_127 |
V_128 | V_1860 ) ;
}
if ( ! ( F_33 ( V_1066 ) & V_1380 ) ) {
F_317 ( & V_5 -> V_209 ) ;
F_322 ( V_5 ) ;
goto V_1859;
}
}
if ( ! -- V_5 -> V_1861 ) {
if ( F_23 ( V_5 , 5705_PLUS ) )
F_475 ( V_5 ) ;
if ( V_5 -> V_339 && ! -- V_5 -> V_339 )
F_134 ( V_5 ) ;
if ( F_23 ( V_5 , V_142 ) ) {
T_1 V_1862 ;
int V_1863 ;
V_1862 = F_33 ( V_792 ) ;
V_1863 = 0 ;
if ( V_5 -> V_178 & V_818 ) {
if ( V_1862 & V_1864 )
V_1863 = 1 ;
} else if ( V_1862 & V_796 )
V_1863 = 1 ;
if ( V_1863 )
F_201 ( V_5 , false ) ;
} else if ( F_23 ( V_5 , V_143 ) ) {
T_1 V_1862 = F_33 ( V_792 ) ;
int V_1865 = 0 ;
if ( V_5 -> V_340 &&
( V_1862 & V_796 ) ) {
V_1865 = 1 ;
}
if ( ! V_5 -> V_340 &&
( V_1862 & ( V_913 |
V_928 ) ) ) {
V_1865 = 1 ;
}
if ( V_1865 ) {
if ( ! V_5 -> V_925 ) {
F_31 ( V_382 ,
( V_5 -> V_367 &
~ V_370 ) ) ;
F_24 ( 40 ) ;
F_31 ( V_382 , V_5 -> V_367 ) ;
F_24 ( 40 ) ;
}
F_201 ( V_5 , false ) ;
}
} else if ( ( V_5 -> V_178 & V_305 ) &&
F_23 ( V_5 , 5780_CLASS ) ) {
F_233 ( V_5 ) ;
} else if ( F_23 ( V_5 , V_1866 ) ) {
T_1 V_1867 = F_33 ( V_1868 ) ;
bool V_340 = ! ( ( V_1867 & V_1869 ) ==
V_1869 ) ;
if ( V_340 != V_5 -> V_340 )
F_201 ( V_5 , false ) ;
}
V_5 -> V_1861 = V_5 -> V_1870 ;
}
if ( ! -- V_5 -> V_1871 ) {
if ( F_23 ( V_5 , V_308 ) && ! F_23 ( V_5 , V_60 ) ) {
F_87 ( V_5 ) ;
F_29 ( V_5 , V_309 ,
V_1872 ) ;
F_29 ( V_5 , V_311 , 4 ) ;
F_29 ( V_5 , V_312 ,
V_1873 ) ;
F_86 ( V_5 ) ;
}
V_5 -> V_1871 = V_5 -> V_1874 ;
}
F_317 ( & V_5 -> V_209 ) ;
V_1859:
V_5 -> V_1875 . V_1876 = V_298 + V_5 -> V_1877 ;
F_479 ( & V_5 -> V_1875 ) ;
}
static void F_480 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_133 ) &&
F_30 ( V_5 ) != V_476 &&
! F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_1877 = V_1878 ;
else
V_5 -> V_1877 = V_1878 / 10 ;
F_184 ( V_5 -> V_1877 > V_1878 ) ;
V_5 -> V_1870 = ( V_1878 / V_5 -> V_1877 ) ;
V_5 -> V_1874 = ( V_1878 / V_5 -> V_1877 ) *
V_1879 ;
F_481 ( & V_5 -> V_1875 ) ;
V_5 -> V_1875 . V_72 = ( unsigned long ) V_5 ;
V_5 -> V_1875 . V_1880 = F_478 ;
}
static void F_482 ( struct V_4 * V_5 )
{
V_5 -> V_1871 = V_5 -> V_1874 ;
V_5 -> V_1861 = V_5 -> V_1870 ;
V_5 -> V_1875 . V_1876 = V_298 + V_5 -> V_1877 ;
F_479 ( & V_5 -> V_1875 ) ;
}
static void F_483 ( struct V_4 * V_5 )
{
F_484 ( & V_5 -> V_1875 ) ;
}
static int F_485 ( struct V_4 * V_5 , bool V_1538 )
__releases( V_5 -> V_209 )
__acquires( V_5 -> V_209 )
{
int V_75 ;
V_75 = F_466 ( V_5 , V_1538 ) ;
if ( V_75 ) {
F_185 ( V_5 -> V_111 ,
L_58 ) ;
F_431 ( V_5 , V_110 , 1 ) ;
F_242 ( V_5 ) ;
F_483 ( V_5 ) ;
V_5 -> V_125 = 0 ;
F_335 ( V_5 ) ;
F_486 ( V_5 -> V_111 ) ;
F_241 ( V_5 , 0 ) ;
}
return V_75 ;
}
static void F_487 ( struct V_1881 * V_1882 )
{
struct V_4 * V_5 = F_239 ( V_1882 , struct V_4 , V_1222 ) ;
int V_75 ;
F_488 () ;
F_241 ( V_5 , 0 ) ;
if ( ! F_144 ( V_5 -> V_111 ) ) {
F_85 ( V_5 , V_1223 ) ;
F_242 ( V_5 ) ;
F_489 () ;
return;
}
F_242 ( V_5 ) ;
F_122 ( V_5 ) ;
F_341 ( V_5 ) ;
F_241 ( V_5 , 1 ) ;
if ( F_23 ( V_5 , V_1095 ) ) {
V_5 -> V_1094 = F_26 ;
V_5 -> V_1883 = F_17 ;
F_83 ( V_5 , V_31 ) ;
F_85 ( V_5 , V_1095 ) ;
}
F_431 ( V_5 , V_110 , 0 ) ;
V_75 = F_466 ( V_5 , true ) ;
if ( V_75 )
goto V_502;
F_343 ( V_5 ) ;
V_502:
F_242 ( V_5 ) ;
if ( ! V_75 )
F_119 ( V_5 ) ;
F_85 ( V_5 , V_1223 ) ;
F_489 () ;
}
static int F_490 ( struct V_4 * V_5 , int V_1884 )
{
T_17 V_1885 ;
unsigned long V_10 ;
char * V_269 ;
struct V_130 * V_131 = & V_5 -> V_123 [ V_1884 ] ;
if ( V_5 -> V_129 == 1 )
V_269 = V_5 -> V_111 -> V_269 ;
else {
V_269 = & V_131 -> V_1886 [ 0 ] ;
if ( V_131 -> V_1106 && V_131 -> V_1163 )
snprintf ( V_269 , V_1887 ,
L_59 , V_5 -> V_111 -> V_269 , V_1884 ) ;
else if ( V_131 -> V_1106 )
snprintf ( V_269 , V_1887 ,
L_60 , V_5 -> V_111 -> V_269 , V_1884 ) ;
else if ( V_131 -> V_1163 )
snprintf ( V_269 , V_1887 ,
L_61 , V_5 -> V_111 -> V_269 , V_1884 ) ;
else
snprintf ( V_269 , V_1887 ,
L_62 , V_5 -> V_111 -> V_269 , V_1884 ) ;
V_269 [ V_1887 - 1 ] = 0 ;
}
if ( F_23 ( V_5 , V_1400 ) || F_23 ( V_5 , V_1693 ) ) {
V_1885 = F_348 ;
if ( F_23 ( V_5 , 1SHOT_MSI ) )
V_1885 = F_347 ;
V_10 = 0 ;
} else {
V_1885 = F_350 ;
if ( F_23 ( V_5 , V_133 ) )
V_1885 = F_351 ;
V_10 = V_1888 ;
}
return F_491 ( V_131 -> V_1236 , V_1885 , V_10 , V_269 , V_131 ) ;
}
static int F_492 ( struct V_4 * V_5 )
{
struct V_130 * V_131 = & V_5 -> V_123 [ 0 ] ;
struct V_364 * V_111 = V_5 -> V_111 ;
int V_75 , V_42 , V_1889 = 0 ;
T_1 V_7 ;
if ( ! F_144 ( V_111 ) )
return - V_82 ;
F_45 ( V_5 ) ;
F_493 ( V_131 -> V_1236 , V_131 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = F_33 ( V_1075 ) | V_1695 ;
F_46 ( V_1075 , V_7 ) ;
}
V_75 = F_491 ( V_131 -> V_1236 , F_352 ,
V_1888 , V_111 -> V_269 , V_131 ) ;
if ( V_75 )
return V_75 ;
V_131 -> V_134 -> V_57 &= ~ V_135 ;
F_48 ( V_5 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_131 -> V_126 ) ;
for ( V_42 = 0 ; V_42 < 5 ; V_42 ++ ) {
T_1 V_124 , V_120 ;
V_124 = F_494 ( V_131 -> V_124 ) ;
V_120 = F_33 ( V_119 ) ;
if ( ( V_124 != 0 ) ||
( V_120 & V_121 ) ) {
V_1889 = 1 ;
break;
}
if ( F_23 ( V_5 , 57765_PLUS ) &&
V_131 -> V_134 -> V_1081 != V_131 -> V_132 )
F_47 ( V_131 -> V_124 , V_131 -> V_132 << 24 ) ;
F_162 ( 10 ) ;
}
F_45 ( V_5 ) ;
F_493 ( V_131 -> V_1236 , V_131 ) ;
V_75 = F_490 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
if ( V_1889 ) {
if ( F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , 1SHOT_MSI ) ) {
V_7 = F_33 ( V_1075 ) & ~ V_1695 ;
F_46 ( V_1075 , V_7 ) ;
}
return 0 ;
}
return - V_210 ;
}
static int F_495 ( struct V_4 * V_5 )
{
int V_75 ;
T_3 V_1385 ;
if ( ! F_23 ( V_5 , V_1400 ) )
return 0 ;
F_421 ( V_5 -> V_12 , V_1384 , & V_1385 ) ;
F_423 ( V_5 -> V_12 , V_1384 ,
V_1385 & ~ V_1890 ) ;
V_75 = F_492 ( V_5 ) ;
F_423 ( V_5 -> V_12 , V_1384 , V_1385 ) ;
if ( ! V_75 )
return 0 ;
if ( V_75 != - V_210 )
return V_75 ;
F_142 ( V_5 -> V_111 , L_63
L_64
L_65 ) ;
F_493 ( V_5 -> V_123 [ 0 ] . V_1236 , & V_5 -> V_123 [ 0 ] ) ;
F_496 ( V_5 -> V_12 ) ;
F_85 ( V_5 , V_1400 ) ;
V_5 -> V_123 [ 0 ] . V_1236 = V_5 -> V_12 -> V_279 ;
V_75 = F_490 ( V_5 , 0 ) ;
if ( V_75 )
return V_75 ;
F_241 ( V_5 , 1 ) ;
F_431 ( V_5 , V_110 , 1 ) ;
V_75 = F_466 ( V_5 , true ) ;
F_242 ( V_5 ) ;
if ( V_75 )
F_493 ( V_5 -> V_123 [ 0 ] . V_1236 , & V_5 -> V_123 [ 0 ] ) ;
return V_75 ;
}
static int F_497 ( struct V_4 * V_5 )
{
const struct V_659 * V_660 ;
if ( F_498 ( & V_5 -> V_662 , V_5 -> V_1891 , & V_5 -> V_12 -> V_111 ) ) {
F_185 ( V_5 -> V_111 , L_66 ,
V_5 -> V_1891 ) ;
return - V_1892 ;
}
V_660 = (struct V_659 * ) V_5 -> V_662 -> V_72 ;
V_5 -> V_661 = F_172 ( V_660 -> V_74 ) ;
if ( V_5 -> V_661 < ( V_5 -> V_662 -> V_634 - V_663 ) ) {
F_185 ( V_5 -> V_111 , L_67 ,
V_5 -> V_661 , V_5 -> V_1891 ) ;
F_499 ( V_5 -> V_662 ) ;
V_5 -> V_662 = NULL ;
return - V_64 ;
}
V_5 -> V_1891 = NULL ;
return 0 ;
}
static T_1 F_500 ( struct V_4 * V_5 )
{
T_1 V_129 = F_501 ( V_5 -> V_1219 , V_5 -> V_1353 ) ;
if ( V_129 > 1 ) {
V_129 = F_502 ( unsigned , V_129 + 1 , V_5 -> V_122 ) ;
}
return V_129 ;
}
static bool F_503 ( struct V_4 * V_5 )
{
int V_42 , V_628 ;
struct V_1893 V_1894 [ V_1895 ] ;
V_5 -> V_1353 = V_5 -> V_1896 ;
V_5 -> V_1219 = V_5 -> V_1897 ;
if ( ! V_5 -> V_1219 )
V_5 -> V_1219 = F_504 () ;
if ( V_5 -> V_1219 > V_5 -> V_1898 )
V_5 -> V_1219 = V_5 -> V_1898 ;
if ( ! V_5 -> V_1896 )
V_5 -> V_1353 = 1 ;
V_5 -> V_129 = F_500 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
V_1894 [ V_42 ] . V_1254 = V_42 ;
V_1894 [ V_42 ] . V_1899 = 0 ;
}
V_628 = F_505 ( V_5 -> V_12 , V_1894 , 1 , V_5 -> V_129 ) ;
if ( V_628 < 0 ) {
return false ;
} else if ( V_628 < V_5 -> V_129 ) {
F_506 ( V_5 -> V_111 , L_68 ,
V_5 -> V_129 , V_628 ) ;
V_5 -> V_129 = V_628 ;
V_5 -> V_1219 = F_501 ( V_628 - 1 , 1 ) ;
if ( V_5 -> V_1353 )
V_5 -> V_1353 = F_320 ( V_5 -> V_1219 , V_5 -> V_1900 ) ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1236 = V_1894 [ V_42 ] . V_1899 ;
if ( F_507 ( V_5 -> V_111 , V_5 -> V_1219 ) ) {
F_508 ( V_5 -> V_12 ) ;
return false ;
}
if ( V_5 -> V_129 == 1 )
return true ;
F_83 ( V_5 , V_1208 ) ;
if ( V_5 -> V_1353 > 1 )
F_83 ( V_5 , V_1103 ) ;
F_509 ( V_5 -> V_111 , V_5 -> V_1353 ) ;
return true ;
}
static void F_510 ( struct V_4 * V_5 )
{
if ( ( F_23 ( V_5 , V_1901 ) || F_23 ( V_5 , V_1061 ) ) &&
! F_23 ( V_5 , V_133 ) ) {
F_142 ( V_5 -> V_111 ,
L_69 ) ;
goto V_1902;
}
if ( F_23 ( V_5 , V_1061 ) && F_503 ( V_5 ) )
F_83 ( V_5 , V_1693 ) ;
else if ( F_23 ( V_5 , V_1901 ) && F_511 ( V_5 -> V_12 ) == 0 )
F_83 ( V_5 , V_1400 ) ;
if ( F_23 ( V_5 , V_1400 ) || F_23 ( V_5 , V_1693 ) ) {
T_1 V_1903 = F_33 ( V_1075 ) ;
if ( F_23 ( V_5 , V_1693 ) && V_5 -> V_129 > 1 )
V_1903 |= V_1694 ;
if ( ! F_23 ( V_5 , 1SHOT_MSI ) )
V_1903 |= V_1695 ;
F_46 ( V_1075 , V_1903 | V_1405 ) ;
}
V_1902:
if ( ! F_23 ( V_5 , V_1693 ) ) {
V_5 -> V_129 = 1 ;
V_5 -> V_123 [ 0 ] . V_1236 = V_5 -> V_12 -> V_279 ;
}
if ( V_5 -> V_129 == 1 ) {
V_5 -> V_1353 = 1 ;
V_5 -> V_1219 = 1 ;
F_509 ( V_5 -> V_111 , 1 ) ;
F_507 ( V_5 -> V_111 , 1 ) ;
}
}
static void F_512 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1693 ) )
F_508 ( V_5 -> V_12 ) ;
else if ( F_23 ( V_5 , V_1400 ) )
F_496 ( V_5 -> V_12 ) ;
F_85 ( V_5 , V_1400 ) ;
F_85 ( V_5 , V_1693 ) ;
F_85 ( V_5 , V_1208 ) ;
F_85 ( V_5 , V_1103 ) ;
}
static int F_513 ( struct V_4 * V_5 , bool V_1538 , bool V_1904 ,
bool V_1905 )
{
struct V_364 * V_111 = V_5 -> V_111 ;
int V_42 , V_75 ;
F_510 ( V_5 ) ;
F_458 ( V_5 ) ;
V_75 = F_417 ( V_5 ) ;
if ( V_75 )
goto V_1906;
F_337 ( V_5 ) ;
F_335 ( V_5 ) ;
for ( V_42 = 0 ; V_42 < V_5 -> V_129 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_75 = F_490 ( V_5 , V_42 ) ;
if ( V_75 ) {
for ( V_42 -- ; V_42 >= 0 ; V_42 -- ) {
V_131 = & V_5 -> V_123 [ V_42 ] ;
F_493 ( V_131 -> V_1236 , V_131 ) ;
}
goto V_1907;
}
}
F_241 ( V_5 , 0 ) ;
if ( V_1905 )
F_42 ( V_5 , V_96 ) ;
V_75 = F_466 ( V_5 , V_1538 ) ;
if ( V_75 ) {
F_431 ( V_5 , V_110 , 1 ) ;
F_407 ( V_5 ) ;
}
F_242 ( V_5 ) ;
if ( V_75 )
goto V_1908;
if ( V_1904 && F_23 ( V_5 , V_1400 ) ) {
V_75 = F_495 ( V_5 ) ;
if ( V_75 ) {
F_241 ( V_5 , 0 ) ;
F_431 ( V_5 , V_110 , 1 ) ;
F_407 ( V_5 ) ;
F_242 ( V_5 ) ;
goto V_1907;
}
if ( ! F_23 ( V_5 , 57765_PLUS ) && F_23 ( V_5 , V_1400 ) ) {
T_1 V_7 = F_33 ( V_1909 ) ;
F_46 ( V_1909 ,
V_7 | V_1910 ) ;
}
}
F_119 ( V_5 ) ;
F_473 ( V_5 ) ;
F_241 ( V_5 , 0 ) ;
F_482 ( V_5 ) ;
F_83 ( V_5 , V_562 ) ;
F_48 ( V_5 ) ;
F_254 ( V_5 ) ;
F_242 ( V_5 ) ;
F_514 ( V_111 ) ;
if ( V_111 -> V_1189 & V_1332 )
F_393 ( V_111 , V_111 -> V_1189 ) ;
return 0 ;
V_1908:
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_493 ( V_131 -> V_1236 , V_131 ) ;
}
V_1907:
F_333 ( V_5 ) ;
F_339 ( V_5 ) ;
F_416 ( V_5 ) ;
V_1906:
F_512 ( V_5 ) ;
return V_75 ;
}
static void F_515 ( struct V_4 * V_5 )
{
int V_42 ;
F_325 ( V_5 ) ;
F_341 ( V_5 ) ;
F_483 ( V_5 ) ;
F_471 ( V_5 ) ;
F_122 ( V_5 ) ;
F_241 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_431 ( V_5 , V_110 , 1 ) ;
F_407 ( V_5 ) ;
F_85 ( V_5 , V_562 ) ;
F_242 ( V_5 ) ;
for ( V_42 = V_5 -> V_129 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
F_493 ( V_131 -> V_1236 , V_131 ) ;
}
F_512 ( V_5 ) ;
F_339 ( V_5 ) ;
F_416 ( V_5 ) ;
}
static int F_516 ( struct V_364 * V_111 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_75 ;
if ( V_5 -> V_1911 ) {
F_185 ( V_111 , L_70
L_71 ) ;
return - V_85 ;
}
if ( V_5 -> V_1891 ) {
V_75 = F_497 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_667 ) {
if ( V_75 ) {
F_142 ( V_5 -> V_111 , L_72 ) ;
V_5 -> V_178 &= ~ V_338 ;
} else if ( ! ( V_5 -> V_178 & V_338 ) ) {
F_142 ( V_5 -> V_111 , L_73 ) ;
V_5 -> V_178 |= V_338 ;
}
} else if ( F_76 ( V_5 ) == V_759 ) {
if ( V_75 )
return V_75 ;
} else if ( V_75 ) {
F_142 ( V_5 -> V_111 , L_74 ) ;
F_85 ( V_5 , V_1600 ) ;
} else if ( ! F_23 ( V_5 , V_1600 ) ) {
F_506 ( V_5 -> V_111 , L_75 ) ;
F_83 ( V_5 , V_1600 ) ;
}
}
F_139 ( V_5 ) ;
V_75 = F_197 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_241 ( V_5 , 0 ) ;
F_45 ( V_5 ) ;
F_85 ( V_5 , V_562 ) ;
F_242 ( V_5 ) ;
V_75 = F_513 ( V_5 ,
! ( V_5 -> V_178 & V_569 ) ,
true , true ) ;
if ( V_75 ) {
F_151 ( V_5 , false ) ;
F_198 ( V_5 -> V_12 , V_743 ) ;
}
return V_75 ;
}
static int F_517 ( struct V_364 * V_111 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( V_5 -> V_1911 ) {
F_185 ( V_111 , L_76
L_71 ) ;
return - V_85 ;
}
F_515 ( V_5 ) ;
memset ( & V_5 -> V_1444 , 0 , sizeof( V_5 -> V_1444 ) ) ;
memset ( & V_5 -> V_1445 , 0 , sizeof( V_5 -> V_1445 ) ) ;
if ( F_428 ( V_5 -> V_12 ) ) {
F_199 ( V_5 ) ;
F_139 ( V_5 ) ;
}
return 0 ;
}
static inline T_6 F_518 ( T_18 * V_7 )
{
return ( ( T_6 ) V_7 -> V_486 << 32 ) | ( ( T_6 ) V_7 -> V_485 ) ;
}
static T_6 F_519 ( struct V_4 * V_5 )
{
struct V_1357 * V_1356 = V_5 -> V_1356 ;
if ( ! ( V_5 -> V_178 & V_567 ) &&
( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) ) {
T_1 V_7 ;
if ( ! F_57 ( V_5 , V_519 , & V_7 ) ) {
F_59 ( V_5 , V_519 ,
V_7 | V_1744 ) ;
F_57 ( V_5 , V_1745 , & V_7 ) ;
} else
V_7 = 0 ;
V_5 -> V_1912 += V_7 ;
return V_5 -> V_1912 ;
}
return F_518 ( & V_1356 -> V_1833 ) ;
}
static void F_433 ( struct V_4 * V_5 , struct V_1913 * V_1914 )
{
struct V_1913 * V_1915 = & V_5 -> V_1445 ;
struct V_1357 * V_1356 = V_5 -> V_1356 ;
F_520 ( V_1823 ) ;
F_520 ( V_1825 ) ;
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
F_520 ( V_1916 ) ;
F_520 ( V_1917 ) ;
F_520 ( V_1918 ) ;
F_520 ( V_1919 ) ;
F_520 ( V_1920 ) ;
F_520 ( V_1921 ) ;
F_520 ( V_1922 ) ;
F_520 ( V_1923 ) ;
F_520 ( V_1924 ) ;
F_520 ( V_1925 ) ;
F_520 ( V_1926 ) ;
F_520 ( V_1927 ) ;
F_520 ( V_1797 ) ;
F_520 ( V_1799 ) ;
F_520 ( V_1801 ) ;
F_520 ( V_1803 ) ;
F_520 ( V_1928 ) ;
F_520 ( V_1805 ) ;
F_520 ( V_1807 ) ;
F_520 ( V_1809 ) ;
F_520 ( V_1811 ) ;
F_520 ( V_1813 ) ;
F_520 ( V_1815 ) ;
F_520 ( V_1929 ) ;
F_520 ( V_1930 ) ;
F_520 ( V_1931 ) ;
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
F_520 ( V_1817 ) ;
F_520 ( V_1819 ) ;
F_520 ( V_1821 ) ;
F_520 ( V_1943 ) ;
F_520 ( V_1944 ) ;
F_520 ( V_1945 ) ;
F_520 ( V_1946 ) ;
F_520 ( V_1947 ) ;
F_520 ( V_1851 ) ;
F_520 ( V_1853 ) ;
F_520 ( V_1856 ) ;
F_520 ( V_1948 ) ;
F_520 ( V_1949 ) ;
F_520 ( V_1950 ) ;
F_520 ( V_1951 ) ;
F_520 ( V_1952 ) ;
F_520 ( V_1953 ) ;
F_520 ( V_1954 ) ;
F_520 ( V_1955 ) ;
F_520 ( V_1956 ) ;
F_520 ( V_1855 ) ;
}
static void F_432 ( struct V_4 * V_5 , struct V_1957 * V_1958 )
{
struct V_1957 * V_1959 = & V_5 -> V_1444 ;
struct V_1357 * V_1356 = V_5 -> V_1356 ;
V_1958 -> V_1960 = V_1959 -> V_1960 +
F_518 ( & V_1356 -> V_1827 ) +
F_518 ( & V_1356 -> V_1829 ) +
F_518 ( & V_1356 -> V_1831 ) ;
V_1958 -> V_1961 = V_1959 -> V_1961 +
F_518 ( & V_1356 -> V_1817 ) +
F_518 ( & V_1356 -> V_1819 ) +
F_518 ( & V_1356 -> V_1821 ) ;
V_1958 -> V_1962 = V_1959 -> V_1962 +
F_518 ( & V_1356 -> V_1823 ) ;
V_1958 -> V_1963 = V_1959 -> V_1963 +
F_518 ( & V_1356 -> V_1797 ) ;
V_1958 -> V_1856 = V_1959 -> V_1856 +
F_518 ( & V_1356 -> V_1856 ) ;
V_1958 -> V_1945 = V_1959 -> V_1945 +
F_518 ( & V_1356 -> V_1945 ) +
F_518 ( & V_1356 -> V_1805 ) +
F_518 ( & V_1356 -> V_1943 ) +
F_518 ( & V_1356 -> V_1944 ) ;
V_1958 -> V_1964 = V_1959 -> V_1964 +
F_518 ( & V_1356 -> V_1829 ) ;
V_1958 -> V_1965 = V_1959 -> V_1965 +
F_518 ( & V_1356 -> V_1799 ) ;
V_1958 -> V_1966 = V_1959 -> V_1966 +
F_518 ( & V_1356 -> V_1845 ) +
F_518 ( & V_1356 -> V_1849 ) ;
V_1958 -> V_1967 = V_1959 -> V_1967 +
F_518 ( & V_1356 -> V_1835 ) ;
V_1958 -> V_1968 = V_1959 -> V_1968 +
F_518 ( & V_1356 -> V_1944 ) ;
V_1958 -> V_1969 = V_1959 -> V_1969 +
F_518 ( & V_1356 -> V_1943 ) ;
V_1958 -> V_1970 = V_1959 -> V_1970 +
F_519 ( V_5 ) ;
V_1958 -> V_1971 = V_1959 -> V_1971 +
F_518 ( & V_1356 -> V_1853 ) ;
V_1958 -> V_1176 = V_5 -> V_1176 ;
V_1958 -> V_1323 = V_5 -> V_1323 ;
}
static int F_521 ( struct V_364 * V_111 )
{
return V_1077 ;
}
static void F_522 ( struct V_364 * V_111 ,
struct V_1972 * V_8 , void * V_1973 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
V_8 -> V_1974 = 0 ;
memset ( V_1973 , 0 , V_1077 ) ;
if ( V_5 -> V_178 & V_399 )
return;
F_241 ( V_5 , 0 ) ;
F_259 ( V_5 , ( T_1 * ) V_1973 ) ;
F_242 ( V_5 ) ;
}
static int F_523 ( struct V_364 * V_111 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
return V_5 -> V_1975 ;
}
static int F_524 ( struct V_364 * V_111 , struct V_1976 * V_1977 , T_4 * V_72 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_56 , V_1978 = 0 ;
T_4 * V_1979 ;
T_1 V_42 , V_595 , V_74 , V_1980 , V_1981 , V_1982 = 0 ;
T_5 V_7 ;
if ( F_23 ( V_5 , V_681 ) )
return - V_64 ;
V_595 = V_1977 -> V_595 ;
V_74 = V_1977 -> V_74 ;
V_1977 -> V_74 = 0 ;
V_1977 -> V_1983 = V_1984 ;
if ( F_23 ( V_5 , V_152 ) ) {
V_1982 = F_33 ( V_504 ) ;
if ( V_1982 & ( V_1541 |
V_1542 ) ) {
F_46 ( V_504 , V_1982 &
~ ( V_1541 |
V_1542 ) ) ;
V_1978 = 1 ;
}
}
F_425 ( V_5 ) ;
if ( V_595 & 3 ) {
V_1980 = V_595 & 3 ;
V_1981 = 4 - V_1980 ;
if ( V_1981 > V_74 ) {
V_1981 = V_74 ;
}
V_56 = F_169 ( V_5 , V_595 - V_1980 , & V_7 ) ;
if ( V_56 )
goto V_1985;
memcpy ( V_72 , ( ( char * ) & V_7 ) + V_1980 , V_1981 ) ;
V_74 -= V_1981 ;
V_595 += V_1981 ;
V_1977 -> V_74 += V_1981 ;
}
V_1979 = & V_72 [ V_1977 -> V_74 ] ;
for ( V_42 = 0 ; V_42 < ( V_74 - ( V_74 & 3 ) ) ; V_42 += 4 ) {
V_56 = F_169 ( V_5 , V_595 + V_42 , & V_7 ) ;
if ( V_56 ) {
if ( V_42 )
V_42 -= 4 ;
V_1977 -> V_74 += V_42 ;
goto V_1985;
}
memcpy ( V_1979 + V_42 , & V_7 , 4 ) ;
if ( F_525 () ) {
if ( F_526 ( V_1986 ) ) {
V_1977 -> V_74 += V_42 ;
V_56 = - V_1987 ;
goto V_1985;
}
F_527 () ;
}
}
V_1977 -> V_74 += V_42 ;
if ( V_74 & 3 ) {
V_1979 = & V_72 [ V_1977 -> V_74 ] ;
V_1981 = V_74 & 3 ;
V_1980 = V_595 + V_74 - V_1981 ;
V_56 = F_169 ( V_5 , V_1980 , & V_7 ) ;
if ( V_56 )
goto V_1985;
memcpy ( V_1979 , & V_7 , V_1981 ) ;
V_1977 -> V_74 += V_1981 ;
}
V_56 = 0 ;
V_1985:
F_426 ( V_5 ) ;
if ( V_1978 )
F_46 ( V_504 , V_1982 ) ;
return V_56 ;
}
static int F_528 ( struct V_364 * V_111 , struct V_1976 * V_1977 , T_4 * V_72 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_56 ;
T_1 V_595 , V_74 , V_1980 , V_1988 ;
T_4 * V_626 ;
T_5 V_1028 , V_1989 ;
if ( F_23 ( V_5 , V_681 ) ||
V_1977 -> V_1983 != V_1984 )
return - V_64 ;
V_595 = V_1977 -> V_595 ;
V_74 = V_1977 -> V_74 ;
if ( ( V_1980 = ( V_595 & 3 ) ) ) {
V_56 = F_169 ( V_5 , V_595 - V_1980 , & V_1028 ) ;
if ( V_56 )
return V_56 ;
V_74 += V_1980 ;
V_595 &= ~ 3 ;
if ( V_74 < 4 )
V_74 = 4 ;
}
V_1988 = 0 ;
if ( V_74 & 3 ) {
V_1988 = 1 ;
V_74 = ( V_74 + 3 ) & ~ 3 ;
V_56 = F_169 ( V_5 , V_595 + V_74 - 4 , & V_1989 ) ;
if ( V_56 )
return V_56 ;
}
V_626 = V_72 ;
if ( V_1980 || V_1988 ) {
V_626 = F_174 ( V_74 , V_632 ) ;
if ( ! V_626 )
return - V_268 ;
if ( V_1980 )
memcpy ( V_626 , & V_1028 , 4 ) ;
if ( V_1988 )
memcpy ( V_626 + V_74 - 4 , & V_1989 , 4 ) ;
memcpy ( V_626 + V_1980 , V_72 , V_1977 -> V_74 ) ;
}
V_56 = F_177 ( V_5 , V_595 , V_74 , V_626 ) ;
if ( V_626 != V_72 )
F_175 ( V_626 ) ;
return V_56 ;
}
static int F_529 ( struct V_364 * V_111 , struct V_1990 * V_642 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_391 ) )
return - V_85 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
return F_530 ( V_212 , V_642 ) ;
}
V_642 -> V_393 = ( V_1991 ) ;
if ( ! ( V_5 -> V_178 & V_392 ) )
V_642 -> V_393 |= ( V_1992 |
V_1993 ) ;
if ( ! ( V_5 -> V_178 & V_359 ) ) {
V_642 -> V_393 |= ( V_1994 |
V_1995 |
V_1996 |
V_1997 |
V_1998 ) ;
V_642 -> V_1999 = V_2000 ;
} else {
V_642 -> V_393 |= V_2001 ;
V_642 -> V_1999 = V_2002 ;
}
V_642 -> V_398 = V_5 -> V_329 . V_398 ;
if ( F_23 ( V_5 , V_358 ) ) {
if ( V_5 -> V_329 . V_342 & V_337 ) {
if ( V_5 -> V_329 . V_342 & V_336 ) {
V_642 -> V_398 |= V_704 ;
} else {
V_642 -> V_398 |= V_704 |
V_2003 ;
}
} else if ( V_5 -> V_329 . V_342 & V_336 ) {
V_642 -> V_398 |= V_2003 ;
}
}
if ( F_144 ( V_111 ) && V_5 -> V_340 ) {
F_531 ( V_642 , V_5 -> V_329 . V_330 ) ;
V_642 -> V_376 = V_5 -> V_329 . V_333 ;
V_642 -> V_2004 = V_5 -> V_329 . V_369 ;
if ( ! ( V_5 -> V_178 & V_359 ) ) {
if ( V_5 -> V_178 & V_823 )
V_642 -> V_2005 = V_2006 ;
else
V_642 -> V_2005 = V_2007 ;
}
} else {
F_531 ( V_642 , V_753 ) ;
V_642 -> V_376 = V_754 ;
V_642 -> V_2005 = V_2008 ;
}
V_642 -> V_2009 = V_5 -> V_160 ;
V_642 -> V_2010 = V_2011 ;
V_642 -> V_352 = V_5 -> V_329 . V_352 ;
V_642 -> V_2012 = 0 ;
V_642 -> V_2013 = 0 ;
return 0 ;
}
static int F_532 ( struct V_364 * V_111 , struct V_1990 * V_642 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
T_1 V_372 = F_533 ( V_642 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_391 ) )
return - V_85 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
return F_534 ( V_212 , V_642 ) ;
}
if ( V_642 -> V_352 != V_357 &&
V_642 -> V_352 != V_779 )
return - V_64 ;
if ( V_642 -> V_352 == V_779 &&
V_642 -> V_376 != V_334 &&
V_642 -> V_376 != V_377 )
return - V_64 ;
if ( V_642 -> V_352 == V_357 ) {
T_1 V_2014 = V_705 |
V_704 |
V_2003 ;
if ( ! ( V_5 -> V_178 & V_392 ) )
V_2014 |= V_773 |
V_763 ;
if ( ! ( V_5 -> V_178 & V_359 ) )
V_2014 |= V_708 |
V_709 |
V_706 |
V_710 |
V_703 ;
else
V_2014 |= V_780 ;
if ( V_642 -> V_398 & ~ V_2014 )
return - V_64 ;
V_2014 &= ( V_773 |
V_763 |
V_708 |
V_709 |
V_706 |
V_710 ) ;
V_642 -> V_398 &= V_2014 ;
} else {
if ( V_5 -> V_178 & V_359 ) {
if ( V_372 != V_331 )
return - V_64 ;
if ( V_642 -> V_376 != V_334 )
return - V_64 ;
} else {
if ( V_372 != V_332 &&
V_372 != V_373 )
return - V_64 ;
}
}
F_241 ( V_5 , 0 ) ;
V_5 -> V_329 . V_352 = V_642 -> V_352 ;
if ( V_642 -> V_352 == V_357 ) {
V_5 -> V_329 . V_398 = ( V_642 -> V_398 |
V_705 ) ;
V_5 -> V_329 . V_372 = V_753 ;
V_5 -> V_329 . V_376 = V_754 ;
} else {
V_5 -> V_329 . V_398 = 0 ;
V_5 -> V_329 . V_372 = V_372 ;
V_5 -> V_329 . V_376 = V_642 -> V_376 ;
}
V_5 -> V_178 |= V_1540 ;
F_141 ( V_5 ) ;
if ( F_144 ( V_111 ) )
F_201 ( V_5 , true ) ;
F_242 ( V_5 ) ;
return 0 ;
}
static void F_535 ( struct V_364 * V_111 , struct V_2015 * V_987 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
F_536 ( V_987 -> V_2016 , V_2017 , sizeof( V_987 -> V_2016 ) ) ;
F_536 ( V_987 -> V_1974 , V_2018 , sizeof( V_987 -> V_1974 ) ) ;
F_536 ( V_987 -> V_2019 , V_5 -> V_2020 , sizeof( V_987 -> V_2019 ) ) ;
F_536 ( V_987 -> V_2021 , F_537 ( V_5 -> V_12 ) , sizeof( V_987 -> V_2021 ) ) ;
}
static void F_538 ( struct V_364 * V_111 , struct V_2022 * V_2023 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( F_23 ( V_5 , V_717 ) && F_539 ( & V_5 -> V_12 -> V_111 ) )
V_2023 -> V_393 = V_2024 ;
else
V_2023 -> V_393 = 0 ;
V_2023 -> V_2025 = 0 ;
if ( F_23 ( V_5 , V_112 ) && F_539 ( & V_5 -> V_12 -> V_111 ) )
V_2023 -> V_2025 = V_2024 ;
memset ( & V_2023 -> V_2026 , 0 , sizeof( V_2023 -> V_2026 ) ) ;
}
static int F_540 ( struct V_364 * V_111 , struct V_2022 * V_2023 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
struct V_543 * V_2027 = & V_5 -> V_12 -> V_111 ;
if ( V_2023 -> V_2025 & ~ V_2024 )
return - V_64 ;
if ( ( V_2023 -> V_2025 & V_2024 ) &&
! ( F_23 ( V_5 , V_717 ) && F_539 ( V_2027 ) ) )
return - V_64 ;
F_541 ( V_2027 , V_2023 -> V_2025 & V_2024 ) ;
if ( F_44 ( V_2027 ) )
F_83 ( V_5 , V_112 ) ;
else
F_85 ( V_5 , V_112 ) ;
return 0 ;
}
static T_1 F_542 ( struct V_364 * V_111 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
return V_5 -> V_2028 ;
}
static void F_543 ( struct V_364 * V_111 , T_1 V_2029 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
V_5 -> V_2028 = V_2029 ;
}
static int F_544 ( struct V_364 * V_111 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_2030 ;
if ( ! F_144 ( V_111 ) )
return - V_85 ;
if ( V_5 -> V_178 & V_567 )
return - V_64 ;
F_141 ( V_5 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
if ( ! ( V_5 -> V_178 & V_391 ) )
return - V_85 ;
V_2030 = F_121 ( V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ) ;
} else {
T_1 V_774 ;
F_70 ( & V_5 -> V_209 ) ;
V_2030 = - V_64 ;
F_57 ( V_5 , V_204 , & V_774 ) ;
if ( ! F_57 ( V_5 , V_204 , & V_774 ) &&
( ( V_774 & V_576 ) ||
( V_5 -> V_178 & V_790 ) ) ) {
F_59 ( V_5 , V_204 , V_774 | V_577 |
V_576 ) ;
V_2030 = 0 ;
}
F_71 ( & V_5 -> V_209 ) ;
}
return V_2030 ;
}
static void F_545 ( struct V_364 * V_111 , struct V_2031 * V_2032 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
V_2032 -> V_2033 = V_5 -> V_1138 ;
if ( F_23 ( V_5 , V_1345 ) )
V_2032 -> V_2034 = V_5 -> V_1143 ;
else
V_2032 -> V_2034 = 0 ;
V_2032 -> V_2035 = V_1096 - 1 ;
V_2032 -> V_1343 = V_5 -> V_1343 ;
if ( F_23 ( V_5 , V_1345 ) )
V_2032 -> V_1347 = V_5 -> V_1347 ;
else
V_2032 -> V_1347 = 0 ;
V_2032 -> V_1088 = V_5 -> V_123 [ 0 ] . V_1088 ;
}
static int F_546 ( struct V_364 * V_111 , struct V_2031 * V_2032 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_42 , V_125 = 0 , V_75 = 0 ;
if ( ( V_2032 -> V_1343 > V_5 -> V_1138 ) ||
( V_2032 -> V_1347 > V_5 -> V_1143 ) ||
( V_2032 -> V_1088 > V_1096 - 1 ) ||
( V_2032 -> V_1088 <= V_1320 ) ||
( F_23 ( V_5 , V_1293 ) &&
( V_2032 -> V_1088 <= ( V_1320 * 3 ) ) ) )
return - V_64 ;
if ( F_144 ( V_111 ) ) {
F_122 ( V_5 ) ;
F_341 ( V_5 ) ;
V_125 = 1 ;
}
F_241 ( V_5 , V_125 ) ;
V_5 -> V_1343 = V_2032 -> V_1343 ;
if ( F_23 ( V_5 , V_2036 ) &&
V_5 -> V_1343 > 63 )
V_5 -> V_1343 = 63 ;
if ( F_23 ( V_5 , V_1345 ) )
V_5 -> V_1347 = V_2032 -> V_1347 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ )
V_5 -> V_123 [ V_42 ] . V_1088 = V_2032 -> V_1088 ;
if ( F_144 ( V_111 ) ) {
F_431 ( V_5 , V_110 , 1 ) ;
V_75 = F_485 ( V_5 , false ) ;
if ( ! V_75 )
F_343 ( V_5 ) ;
}
F_242 ( V_5 ) ;
if ( V_125 && ! V_75 )
F_119 ( V_5 ) ;
return V_75 ;
}
static void F_547 ( struct V_364 * V_111 , struct V_2037 * V_2038 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
V_2038 -> V_352 = ! ! F_23 ( V_5 , V_358 ) ;
if ( V_5 -> V_329 . V_342 & V_337 )
V_2038 -> V_2039 = 1 ;
else
V_2038 -> V_2039 = 0 ;
if ( V_5 -> V_329 . V_342 & V_336 )
V_2038 -> V_2040 = 1 ;
else
V_2038 -> V_2040 = 0 ;
}
static int F_548 ( struct V_364 * V_111 , struct V_2037 * V_2038 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_75 = 0 ;
if ( V_5 -> V_329 . V_352 == V_357 )
F_141 ( V_5 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
T_1 V_954 ;
struct V_211 * V_212 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
if ( ! ( V_212 -> V_393 & V_395 ) ||
( ! ( V_212 -> V_393 & V_396 ) &&
( V_2038 -> V_2039 != V_2038 -> V_2040 ) ) )
return - V_64 ;
V_5 -> V_329 . V_342 = 0 ;
if ( V_2038 -> V_2039 ) {
V_5 -> V_329 . V_342 |= V_337 ;
if ( V_2038 -> V_2040 ) {
V_5 -> V_329 . V_342 |= V_336 ;
V_954 = V_704 ;
} else
V_954 = V_704 |
V_2003 ;
} else if ( V_2038 -> V_2040 ) {
V_5 -> V_329 . V_342 |= V_336 ;
V_954 = V_2003 ;
} else
V_954 = 0 ;
if ( V_2038 -> V_352 )
F_83 ( V_5 , V_358 ) ;
else
F_85 ( V_5 , V_358 ) ;
if ( V_5 -> V_178 & V_391 ) {
T_1 V_2041 = V_212 -> V_398 &
( V_704 | V_2003 ) ;
if ( V_2041 != V_954 ) {
V_212 -> V_398 &=
~ ( V_704 |
V_2003 ) ;
V_212 -> V_398 |= V_954 ;
if ( V_212 -> V_352 ) {
return F_121 ( V_212 ) ;
}
}
if ( ! V_2038 -> V_352 )
F_107 ( V_5 , 0 , 0 ) ;
} else {
V_5 -> V_329 . V_398 &=
~ ( V_704 |
V_2003 ) ;
V_5 -> V_329 . V_398 |= V_954 ;
}
} else {
int V_125 = 0 ;
if ( F_144 ( V_111 ) ) {
F_341 ( V_5 ) ;
V_125 = 1 ;
}
F_241 ( V_5 , V_125 ) ;
if ( V_2038 -> V_352 )
F_83 ( V_5 , V_358 ) ;
else
F_85 ( V_5 , V_358 ) ;
if ( V_2038 -> V_2039 )
V_5 -> V_329 . V_342 |= V_337 ;
else
V_5 -> V_329 . V_342 &= ~ V_337 ;
if ( V_2038 -> V_2040 )
V_5 -> V_329 . V_342 |= V_336 ;
else
V_5 -> V_329 . V_342 &= ~ V_336 ;
if ( F_144 ( V_111 ) ) {
F_431 ( V_5 , V_110 , 1 ) ;
V_75 = F_485 ( V_5 , false ) ;
if ( ! V_75 )
F_343 ( V_5 ) ;
}
F_242 ( V_5 ) ;
}
V_5 -> V_178 |= V_1540 ;
return V_75 ;
}
static int F_549 ( struct V_364 * V_111 , int V_2042 )
{
switch ( V_2042 ) {
case V_2043 :
return V_2044 ;
case V_2045 :
return V_2046 ;
default:
return - V_1037 ;
}
}
static int F_550 ( struct V_364 * V_111 , struct V_2047 * V_987 ,
T_1 * T_19 V_2048 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1061 ) )
return - V_1037 ;
switch ( V_987 -> V_642 ) {
case V_2049 :
if ( F_144 ( V_5 -> V_111 ) )
V_987 -> V_72 = V_5 -> V_1219 ;
else {
V_987 -> V_72 = F_551 () ;
if ( V_987 -> V_72 > V_2050 )
V_987 -> V_72 = V_2050 ;
}
V_987 -> V_72 -= 1 ;
return 0 ;
default:
return - V_1037 ;
}
}
static T_1 F_552 ( struct V_364 * V_111 )
{
T_1 V_634 = 0 ;
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( F_23 ( V_5 , V_1061 ) )
V_634 = V_1533 ;
return V_634 ;
}
static int F_553 ( struct V_364 * V_111 , T_1 * V_2051 , T_4 * V_2052 , T_4 * V_2053 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_42 ;
if ( V_2053 )
* V_2053 = V_2054 ;
if ( ! V_2051 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_1533 ; V_42 ++ )
V_2051 [ V_42 ] = V_5 -> V_1534 [ V_42 ] ;
return 0 ;
}
static int F_554 ( struct V_364 * V_111 , const T_1 * V_2051 , const T_4 * V_2052 ,
const T_4 V_2053 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
T_20 V_42 ;
if ( V_2052 ||
( V_2053 != V_2055 && V_2053 != V_2054 ) )
return - V_1037 ;
if ( ! V_2051 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_1533 ; V_42 ++ )
V_5 -> V_1534 [ V_42 ] = V_2051 [ V_42 ] ;
if ( ! F_144 ( V_111 ) || ! F_23 ( V_5 , V_1208 ) )
return 0 ;
F_241 ( V_5 , 0 ) ;
F_459 ( V_5 ) ;
F_242 ( V_5 ) ;
return 0 ;
}
static void F_555 ( struct V_364 * V_111 ,
struct V_2056 * V_2057 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
T_1 V_2058 = F_504 () ;
V_2057 -> V_2059 = V_5 -> V_1898 ;
V_2057 -> V_2060 = V_5 -> V_1900 ;
if ( F_144 ( V_111 ) ) {
V_2057 -> V_2061 = V_5 -> V_1219 ;
V_2057 -> V_2062 = V_5 -> V_1353 ;
} else {
if ( V_5 -> V_1897 )
V_2057 -> V_2061 = V_5 -> V_1897 ;
else
V_2057 -> V_2061 = F_320 ( V_2058 , V_5 -> V_1898 ) ;
if ( V_5 -> V_1896 )
V_2057 -> V_2062 = V_5 -> V_1896 ;
else
V_2057 -> V_2062 = F_320 ( V_2058 , V_5 -> V_1900 ) ;
}
}
static int F_556 ( struct V_364 * V_111 ,
struct V_2056 * V_2057 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( ! F_23 ( V_5 , V_1061 ) )
return - V_1037 ;
if ( V_2057 -> V_2061 > V_5 -> V_1898 ||
V_2057 -> V_2062 > V_5 -> V_1900 )
return - V_64 ;
V_5 -> V_1897 = V_2057 -> V_2061 ;
V_5 -> V_1896 = V_2057 -> V_2062 ;
if ( ! F_144 ( V_111 ) )
return 0 ;
F_515 ( V_5 ) ;
F_139 ( V_5 ) ;
F_513 ( V_5 , true , false , false ) ;
return 0 ;
}
static void F_557 ( struct V_364 * V_111 , T_1 V_2063 , T_4 * V_626 )
{
switch ( V_2063 ) {
case V_2045 :
memcpy ( V_626 , & V_2064 , sizeof( V_2064 ) ) ;
break;
case V_2043 :
memcpy ( V_626 , & V_2065 , sizeof( V_2065 ) ) ;
break;
default:
F_558 ( 1 ) ;
break;
}
}
static int F_559 ( struct V_364 * V_111 ,
enum V_2066 V_848 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( ! F_144 ( V_5 -> V_111 ) )
return - V_85 ;
switch ( V_848 ) {
case V_2067 :
return 1 ;
case V_2068 :
F_46 ( V_727 , V_838 |
V_836 |
V_837 |
V_2069 |
V_942 |
V_2070 |
V_2071 ) ;
break;
case V_2072 :
F_46 ( V_727 , V_838 |
V_942 ) ;
break;
case V_2073 :
F_46 ( V_727 , V_5 -> V_563 ) ;
break;
}
return 0 ;
}
static void F_560 ( struct V_364 * V_111 ,
struct V_2074 * V_1914 , T_6 * V_2075 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( V_5 -> V_1356 )
F_433 ( V_5 , (struct V_1913 * ) V_2075 ) ;
else
memset ( V_2075 , 0 , sizeof( struct V_1913 ) ) ;
}
static T_5 * F_561 ( struct V_4 * V_5 , T_1 * V_2076 )
{
int V_42 ;
T_5 * V_626 ;
T_1 V_595 = 0 , V_74 = 0 ;
T_1 V_1983 , V_7 ;
if ( F_23 ( V_5 , V_681 ) || F_168 ( V_5 , 0 , & V_1983 ) )
return NULL ;
if ( V_1983 == V_1984 ) {
for ( V_595 = V_2077 ;
V_595 < V_2078 ;
V_595 += V_2079 ) {
if ( F_168 ( V_5 , V_595 , & V_7 ) )
return NULL ;
if ( ( V_7 >> V_2080 ) ==
V_2081 )
break;
}
if ( V_595 != V_2078 ) {
V_74 = ( V_7 & V_2082 ) * 4 ;
if ( F_168 ( V_5 , V_595 + 4 , & V_595 ) )
return NULL ;
V_595 = F_167 ( V_5 , V_595 ) ;
}
}
if ( ! V_595 || ! V_74 ) {
V_595 = V_2083 ;
V_74 = V_2084 ;
}
V_626 = F_174 ( V_74 , V_632 ) ;
if ( V_626 == NULL )
return NULL ;
if ( V_1983 == V_1984 ) {
for ( V_42 = 0 ; V_42 < V_74 ; V_42 += 4 ) {
if ( F_169 ( V_5 , V_595 + V_42 , & V_626 [ V_42 / 4 ] ) )
goto error;
}
} else {
T_4 * V_2085 ;
T_16 V_2086 ;
unsigned int V_2087 = 0 ;
V_2085 = ( T_4 * ) & V_626 [ 0 ] ;
for ( V_42 = 0 ; V_2087 < V_74 && V_42 < 3 ; V_42 ++ , V_2087 += V_2086 , V_2085 += V_2086 ) {
V_2086 = F_562 ( V_5 -> V_12 , V_2087 ,
V_74 - V_2087 , V_2085 ) ;
if ( V_2086 == - V_2088 || V_2086 == - V_1987 )
V_2086 = 0 ;
else if ( V_2086 < 0 )
goto error;
}
if ( V_2087 != V_74 )
goto error;
}
* V_2076 = V_74 ;
return V_626 ;
error:
F_175 ( V_626 ) ;
return NULL ;
}
static int F_563 ( struct V_4 * V_5 )
{
T_1 V_2089 , V_1983 , V_74 ;
T_5 * V_626 ;
int V_42 , V_627 , V_1515 , V_75 = 0 , V_634 ;
if ( F_23 ( V_5 , V_681 ) )
return 0 ;
if ( F_168 ( V_5 , 0 , & V_1983 ) != 0 )
return - V_210 ;
if ( V_1983 == V_1984 )
V_634 = V_2090 ;
else if ( ( V_1983 & V_2091 ) == V_2092 ) {
if ( ( V_1983 & V_2093 ) ==
V_2094 ) {
switch ( V_1983 & V_2095 ) {
case V_2096 :
V_634 = V_2097 ;
break;
case V_2098 :
V_634 = V_2099 ;
break;
case V_2100 :
V_634 = V_2101 ;
break;
case V_2102 :
V_634 = V_2103 ;
break;
case V_2104 :
V_634 = V_2105 ;
break;
case V_2106 :
V_634 = V_2107 ;
break;
default:
return - V_210 ;
}
} else
return 0 ;
} else if ( ( V_1983 & V_2108 ) == V_2109 )
V_634 = V_2110 ;
else
return - V_210 ;
V_626 = F_174 ( V_634 , V_632 ) ;
if ( V_626 == NULL )
return - V_268 ;
V_75 = - V_210 ;
for ( V_42 = 0 , V_627 = 0 ; V_42 < V_634 ; V_42 += 4 , V_627 ++ ) {
V_75 = F_169 ( V_5 , V_42 , & V_626 [ V_627 ] ) ;
if ( V_75 )
break;
}
if ( V_42 < V_634 )
goto V_502;
V_1983 = F_172 ( V_626 [ 0 ] ) ;
if ( ( V_1983 & V_2091 ) ==
V_2092 ) {
T_4 * V_2111 = ( T_4 * ) V_626 , V_2112 = 0 ;
if ( ( V_1983 & V_2095 ) ==
V_2098 ) {
for ( V_42 = 0 ; V_42 < V_2113 ; V_42 ++ )
V_2112 += V_2111 [ V_42 ] ;
for ( V_42 = V_2113 + 4 ; V_42 < V_634 ; V_42 ++ )
V_2112 += V_2111 [ V_42 ] ;
} else {
for ( V_42 = 0 ; V_42 < V_634 ; V_42 ++ )
V_2112 += V_2111 [ V_42 ] ;
}
if ( V_2112 == 0 ) {
V_75 = 0 ;
goto V_502;
}
V_75 = - V_210 ;
goto V_502;
}
if ( ( V_1983 & V_2108 ) ==
V_2109 ) {
T_4 V_72 [ V_2114 ] ;
T_4 V_2115 [ V_2114 ] ;
T_4 * V_2111 = ( T_4 * ) V_626 ;
for ( V_42 = 0 , V_627 = 0 , V_1515 = 0 ; V_42 < V_2110 ; V_42 ++ ) {
if ( ( V_42 == 0 ) || ( V_42 == 8 ) ) {
int V_2116 ;
T_4 V_2117 ;
for ( V_2116 = 0 , V_2117 = 0x80 ; V_2116 < 7 ; V_2116 ++ , V_2117 >>= 1 )
V_2115 [ V_1515 ++ ] = V_2111 [ V_42 ] & V_2117 ;
V_42 ++ ;
} else if ( V_42 == 16 ) {
int V_2116 ;
T_4 V_2117 ;
for ( V_2116 = 0 , V_2117 = 0x20 ; V_2116 < 6 ; V_2116 ++ , V_2117 >>= 1 )
V_2115 [ V_1515 ++ ] = V_2111 [ V_42 ] & V_2117 ;
V_42 ++ ;
for ( V_2116 = 0 , V_2117 = 0x80 ; V_2116 < 8 ; V_2116 ++ , V_2117 >>= 1 )
V_2115 [ V_1515 ++ ] = V_2111 [ V_42 ] & V_2117 ;
V_42 ++ ;
}
V_72 [ V_627 ++ ] = V_2111 [ V_42 ] ;
}
V_75 = - V_210 ;
for ( V_42 = 0 ; V_42 < V_2114 ; V_42 ++ ) {
T_4 V_2118 = F_564 ( V_72 [ V_42 ] ) ;
if ( ( V_2118 & 0x1 ) && V_2115 [ V_42 ] )
goto V_502;
else if ( ! ( V_2118 & 0x1 ) && ! V_2115 [ V_42 ] )
goto V_502;
}
V_75 = 0 ;
goto V_502;
}
V_75 = - V_210 ;
V_2089 = F_448 ( ( unsigned char * ) V_626 , 0x10 ) ;
if ( V_2089 != F_565 ( V_626 [ 0x10 / 4 ] ) )
goto V_502;
V_2089 = F_448 ( ( unsigned char * ) & V_626 [ 0x74 / 4 ] , 0x88 ) ;
if ( V_2089 != F_565 ( V_626 [ 0xfc / 4 ] ) )
goto V_502;
F_175 ( V_626 ) ;
V_626 = F_561 ( V_5 , & V_74 ) ;
if ( ! V_626 )
return - V_268 ;
V_42 = F_566 ( ( T_4 * ) V_626 , 0 , V_74 , V_2119 ) ;
if ( V_42 > 0 ) {
V_627 = F_567 ( & ( ( T_4 * ) V_626 ) [ V_42 ] ) ;
if ( V_627 < 0 )
goto V_502;
if ( V_42 + V_2120 + V_627 > V_74 )
goto V_502;
V_42 += V_2120 ;
V_627 = F_568 ( ( T_4 * ) V_626 , V_42 , V_627 ,
V_2121 ) ;
if ( V_627 > 0 ) {
T_4 V_2112 = 0 ;
V_627 += V_2122 ;
for ( V_42 = 0 ; V_42 <= V_627 ; V_42 ++ )
V_2112 += ( ( T_4 * ) V_626 ) [ V_42 ] ;
if ( V_2112 )
goto V_502;
}
}
V_75 = 0 ;
V_502:
F_175 ( V_626 ) ;
return V_75 ;
}
static int F_569 ( struct V_4 * V_5 )
{
int V_42 , F_501 ;
if ( ! F_144 ( V_5 -> V_111 ) )
return - V_82 ;
if ( V_5 -> V_178 & V_359 )
F_501 = V_2123 ;
else
F_501 = V_2124 ;
for ( V_42 = 0 ; V_42 < F_501 ; V_42 ++ ) {
if ( V_5 -> V_340 )
return 0 ;
if ( F_570 ( 1000 ) )
break;
}
return - V_210 ;
}
static int F_571 ( struct V_4 * V_5 )
{
int V_42 , V_2125 , V_2126 ;
T_1 V_595 , V_2127 , V_2128 , V_7 , V_2129 , V_2130 ;
static struct {
T_3 V_595 ;
T_3 V_10 ;
#define F_572 0x1
#define F_573 0x2
#define F_574 0x4
#define F_575 0x8
T_1 V_2127 ;
T_1 V_2128 ;
} V_2131 [] = {
{ V_382 , F_573 ,
0x00000000 , 0x00ef6f8c } ,
{ V_382 , F_572 ,
0x00000000 , 0x01ef6b8c } ,
{ V_792 , F_573 ,
0x03800107 , 0x00000000 } ,
{ V_792 , F_572 ,
0x03800100 , 0x00000000 } ,
{ V_689 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_690 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1629 , 0x0000 ,
0x00000000 , 0x0000ffff } ,
{ V_363 , 0x0000 ,
0x00000000 , 0x00000070 } ,
{ V_386 , 0x0000 ,
0x00000000 , 0x00003fff } ,
{ V_361 , F_573 ,
0x00000000 , 0x000007fc } ,
{ V_361 , F_572 ,
0x00000000 , 0x000007dc } ,
{ V_1517 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1518 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1519 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1520 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1054 + 0 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1054 + 4 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1054 + 8 , F_573 ,
0x00000000 , 0x00000003 } ,
{ V_1054 + 0xc , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1623 + 0 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1623 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1623 + 8 , 0x0000 ,
0x00000000 , 0xffff0002 } ,
{ V_1623 + 0xc , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1510 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1510 , F_572 ,
0x00000000 , 0x000003ff } ,
{ V_1513 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_138 , F_573 ,
0x00000000 , 0x00000004 } ,
{ V_138 , F_572 ,
0x00000000 , 0x000000f6 } ,
{ V_1475 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1475 , F_572 ,
0x00000000 , 0x000003ff } ,
{ V_1466 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1466 , F_572 ,
0x00000000 , 0x000003ff } ,
{ V_1477 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1477 , F_572 | F_574 ,
0x00000000 , 0x000000ff } ,
{ V_1468 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1468 , F_572 | F_574 ,
0x00000000 , 0x000000ff } ,
{ V_1483 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1485 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1479 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1479 , F_572 | F_574 ,
0x00000000 , 0x000000ff } ,
{ V_1470 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1470 , F_572 | F_574 ,
0x00000000 , 0x000000ff } ,
{ V_971 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1678 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1678 + 4 , F_573 ,
0x00000000 , 0xffffffff } ,
{ V_1500 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1500 + 4 , 0x0000 ,
0x00000000 , 0xffffffff } ,
{ V_1679 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1680 , 0x0000 ,
0xffffffff , 0x00000000 } ,
{ V_1591 , F_575 ,
0x00000000 , 0x007fff80 } ,
{ V_1593 , F_575 ,
0x00000000 , 0x007fffff } ,
{ V_1602 , 0x0000 ,
0x00000000 , 0x0000003f } ,
{ V_1605 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1607 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_1596 , F_573 ,
0xffffffff , 0x00000000 } ,
{ V_1598 , F_573 ,
0xffffffff , 0x00000000 } ,
{ V_2132 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ V_2133 + 4 , F_573 ,
0x00000000 , 0x000001ff } ,
{ V_2134 + 4 , 0x0000 ,
0x00000000 , 0x000007ff } ,
{ V_2135 + 4 , 0x0000 ,
0x00000000 , 0x000001ff } ,
{ 0xffff , 0x0000 , 0x00000000 , 0x00000000 } ,
} ;
V_2125 = V_2126 = 0 ;
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_2125 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2126 = 1 ;
}
for ( V_42 = 0 ; V_2131 [ V_42 ] . V_595 != 0xffff ; V_42 ++ ) {
if ( V_2125 && ( V_2131 [ V_42 ] . V_10 & F_573 ) )
continue;
if ( ! V_2125 && ( V_2131 [ V_42 ] . V_10 & F_572 ) )
continue;
if ( F_23 ( V_5 , V_1648 ) &&
( V_2131 [ V_42 ] . V_10 & F_574 ) )
continue;
if ( V_2126 && ( V_2131 [ V_42 ] . V_10 & F_575 ) )
continue;
V_595 = ( T_1 ) V_2131 [ V_42 ] . V_595 ;
V_2127 = V_2131 [ V_42 ] . V_2127 ;
V_2128 = V_2131 [ V_42 ] . V_2128 ;
V_2129 = F_33 ( V_595 ) ;
V_2130 = V_2129 & V_2127 ;
F_46 ( V_595 , 0 ) ;
V_7 = F_33 ( V_595 ) ;
if ( ( ( V_7 & V_2127 ) != V_2130 ) || ( V_7 & V_2128 ) )
goto V_502;
F_46 ( V_595 , V_2127 | V_2128 ) ;
V_7 = F_33 ( V_595 ) ;
if ( ( V_7 & V_2127 ) != V_2130 )
goto V_502;
if ( ( V_7 & V_2128 ) != V_2128 )
goto V_502;
F_46 ( V_595 , V_2129 ) ;
}
return 0 ;
V_502:
if ( F_576 ( V_5 ) )
F_185 ( V_5 -> V_111 ,
L_77 , V_595 ) ;
F_46 ( V_595 , V_2129 ) ;
return - V_210 ;
}
static int F_577 ( struct V_4 * V_5 , T_1 V_595 , T_1 V_74 )
{
static const T_1 V_2136 [] = { 0x00000000 , 0xffffffff , 0xaa55a55a } ;
int V_42 ;
T_1 V_627 ;
for ( V_42 = 0 ; V_42 < F_578 ( V_2136 ) ; V_42 ++ ) {
for ( V_627 = 0 ; V_627 < V_74 ; V_627 += 4 ) {
T_1 V_7 ;
F_29 ( V_5 , V_595 + V_627 , V_2136 [ V_42 ] ) ;
F_32 ( V_5 , V_595 + V_627 , & V_7 ) ;
if ( V_7 != V_2136 [ V_42 ] )
return - V_210 ;
}
}
return 0 ;
}
static int F_579 ( struct V_4 * V_5 )
{
static struct V_2137 {
T_1 V_595 ;
T_1 V_74 ;
} V_2138 [] = {
{ 0x00000000 , 0x00b50 } ,
{ 0x00002000 , 0x1c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2139 [] = {
{ 0x00000100 , 0x0000c } ,
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x01000 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0e000 } ,
{ 0xffffffff , 0x00000 }
} , V_2140 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x00800 } ,
{ 0x00008000 , 0x02000 } ,
{ 0x00010000 , 0x0c000 } ,
{ 0xffffffff , 0x00000 }
} , V_2141 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00400 } ,
{ 0x00006000 , 0x00400 } ,
{ 0x00008000 , 0x01000 } ,
{ 0x00010000 , 0x01000 } ,
{ 0xffffffff , 0x00000 }
} , V_2142 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0x00020000 , 0x13c00 } ,
{ 0xffffffff , 0x00000 }
} , V_2143 [] = {
{ 0x00000200 , 0x00008 } ,
{ 0x00004000 , 0x00800 } ,
{ 0x00006000 , 0x09800 } ,
{ 0x00010000 , 0x0a000 } ,
{ 0xffffffff , 0x00000 }
} ;
struct V_2137 * V_2144 ;
int V_75 = 0 ;
int V_42 ;
if ( F_23 ( V_5 , 5717_PLUS ) )
V_2144 = V_2142 ;
else if ( F_23 ( V_5 , 57765_CLASS ) ||
F_30 ( V_5 ) == V_767 )
V_2144 = V_2143 ;
else if ( F_23 ( V_5 , 5755_PLUS ) )
V_2144 = V_2140 ;
else if ( F_30 ( V_5 ) == V_36 )
V_2144 = V_2141 ;
else if ( F_23 ( V_5 , 5705_PLUS ) )
V_2144 = V_2139 ;
else
V_2144 = V_2138 ;
for ( V_42 = 0 ; V_2144 [ V_42 ] . V_595 != 0xffffffff ; V_42 ++ ) {
V_75 = F_577 ( V_5 , V_2144 [ V_42 ] . V_595 , V_2144 [ V_42 ] . V_74 ) ;
if ( V_75 )
break;
}
return V_75 ;
}
static int F_580 ( struct V_4 * V_5 , T_1 V_2145 , bool V_2146 )
{
T_1 V_2147 , V_2148 , V_2149 , V_1129 ;
T_1 V_1266 = 0 , V_1244 = 0 , V_1165 , V_126 , V_2150 , V_7 ;
T_1 V_1157 ;
struct V_1107 * V_1108 ;
T_4 * V_2151 , * V_2152 ;
T_9 V_1134 ;
int V_2153 , V_2154 , V_2155 , V_42 , V_75 ;
struct V_1132 * V_1133 ;
struct V_130 * V_131 , * V_2156 ;
struct V_1127 * V_1128 = & V_5 -> V_123 [ 0 ] . V_1089 ;
V_131 = & V_5 -> V_123 [ 0 ] ;
V_2156 = & V_5 -> V_123 [ 0 ] ;
if ( V_5 -> V_129 > 1 ) {
if ( F_23 ( V_5 , V_1208 ) )
V_2156 = & V_5 -> V_123 [ 1 ] ;
if ( F_23 ( V_5 , V_1103 ) )
V_131 = & V_5 -> V_123 [ 1 ] ;
}
V_126 = V_131 -> V_126 | V_2156 -> V_126 ;
V_75 = - V_210 ;
V_2154 = V_2145 ;
V_1108 = F_303 ( V_5 -> V_111 , V_2154 ) ;
if ( ! V_1108 )
return - V_268 ;
V_2151 = F_306 ( V_1108 , V_2154 ) ;
memcpy ( V_2151 , V_5 -> V_111 -> V_694 , V_1531 ) ;
memset ( V_2151 + V_1531 , 0x0 , 8 ) ;
F_46 ( V_1629 , V_2154 + V_1181 ) ;
if ( V_2146 ) {
struct V_1282 * V_1283 = (struct V_1282 * ) & V_2151 [ V_1199 ] ;
T_1 V_1291 = V_2157 + V_2158 +
V_2159 ;
memcpy ( V_2151 + V_1531 * 2 , V_2160 ,
sizeof( V_2160 ) ) ;
V_1244 = V_2161 ;
V_7 = V_2154 - V_1531 * 2 - sizeof( V_2160 ) ;
V_2153 = F_581 ( V_7 , V_2161 ) ;
V_1283 -> V_1295 = F_310 ( ( T_3 ) ( V_1244 + V_1291 ) ) ;
V_1266 = ( V_1296 |
V_1297 ) ;
if ( F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ||
F_23 ( V_5 , V_1300 ) ) {
struct V_1284 * V_2162 ;
V_7 = V_1199 + V_2157 ;
V_2162 = (struct V_1284 * ) & V_2151 [ V_7 ] ;
V_2162 -> V_1294 = 0 ;
} else
V_1266 |= V_1301 ;
if ( F_23 ( V_5 , V_1300 ) ) {
V_1244 |= ( V_1291 & 0xc ) << 12 ;
if ( V_1291 & 0x10 )
V_1266 |= 0x00000010 ;
V_1266 |= ( V_1291 & 0x3e0 ) << 5 ;
} else if ( F_23 ( V_5 , V_1299 ) )
V_1244 |= V_1291 << 9 ;
else if ( F_23 ( V_5 , V_1298 ) ||
F_30 ( V_5 ) == V_501 ) {
V_1244 |= ( V_2159 << 9 ) ;
} else {
V_1266 |= ( V_2159 << 10 ) ;
}
V_2150 = V_1531 * 2 + sizeof( V_2160 ) ;
} else {
V_2153 = 1 ;
V_2150 = V_1199 ;
if ( F_23 ( V_5 , V_1308 ) &&
V_2154 > V_1309 )
V_1266 |= V_1310 ;
}
for ( V_42 = V_2150 ; V_42 < V_2154 ; V_42 ++ )
V_2151 [ V_42 ] = ( T_4 ) ( V_42 & 0xff ) ;
V_1134 = F_292 ( V_5 -> V_12 , V_1108 -> V_72 , V_2154 , V_1116 ) ;
if ( F_293 ( V_5 -> V_12 , V_1134 ) ) {
F_582 ( V_1108 ) ;
return - V_210 ;
}
V_7 = V_131 -> V_1087 ;
V_131 -> V_1106 [ V_7 ] . V_1108 = V_1108 ;
F_294 ( & V_131 -> V_1106 [ V_7 ] , V_1115 , V_1134 ) ;
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_2156 -> V_126 ) ;
F_24 ( 10 ) ;
V_2147 = V_2156 -> V_134 -> V_145 [ 0 ] . V_1085 ;
V_1157 = F_263 ( V_131 ) ;
if ( F_362 ( V_131 , & V_7 , & V_1157 , V_1134 , V_2154 ,
V_1266 | V_1260 , V_1244 , 0 ) ) {
V_131 -> V_1106 [ V_7 ] . V_1108 = NULL ;
F_582 ( V_1108 ) ;
return - V_210 ;
}
V_131 -> V_1087 ++ ;
F_49 () ;
F_390 ( V_131 -> V_1322 , V_131 -> V_1087 ) ;
F_494 ( V_131 -> V_1322 ) ;
F_24 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 35 ; V_42 ++ ) {
F_31 ( V_138 , V_5 -> V_127 | V_128 |
V_126 ) ;
F_24 ( 10 ) ;
V_2149 = V_131 -> V_134 -> V_145 [ 0 ] . V_146 ;
V_2148 = V_2156 -> V_134 -> V_145 [ 0 ] . V_1085 ;
if ( ( V_2149 == V_131 -> V_1087 ) &&
( V_2148 == ( V_2147 + V_2153 ) ) )
break;
}
F_363 ( V_131 , V_131 -> V_1087 - 1 , - 1 ) ;
F_582 ( V_1108 ) ;
if ( V_2149 != V_131 -> V_1087 )
goto V_502;
if ( V_2148 != V_2147 + V_2153 )
goto V_502;
V_7 = V_2150 ;
while ( V_2148 != V_2147 ) {
V_1133 = & V_2156 -> V_1163 [ V_2147 ++ ] ;
V_1165 = V_1133 -> V_1168 & V_1169 ;
V_1129 = V_1133 -> V_1168 & V_1170 ;
if ( ( V_1133 -> V_1172 & V_1173 ) != 0 &&
( V_1133 -> V_1172 != V_2163 ) )
goto V_502;
V_2155 = ( ( V_1133 -> V_1178 & V_1179 ) >> V_1180 )
- V_1181 ;
if ( ! V_2146 ) {
if ( V_2155 != V_2154 )
goto V_502;
if ( V_2145 <= V_1337 - V_1181 ) {
if ( V_1129 != V_1137 )
goto V_502;
} else {
if ( V_1129 != V_1142 )
goto V_502;
}
} else if ( ( V_1133 -> V_1182 & V_1191 ) &&
( V_1133 -> V_1192 & V_1193 )
>> V_1194 != 0xffff ) {
goto V_502;
}
if ( V_1129 == V_1137 ) {
V_2152 = V_1128 -> V_1140 [ V_1165 ] . V_72 ;
V_1134 = F_270 ( & V_1128 -> V_1140 [ V_1165 ] ,
V_1115 ) ;
} else if ( V_1129 == V_1142 ) {
V_2152 = V_1128 -> V_1146 [ V_1165 ] . V_72 ;
V_1134 = F_270 ( & V_1128 -> V_1146 [ V_1165 ] ,
V_1115 ) ;
} else
goto V_502;
F_304 ( V_5 -> V_12 , V_1134 , V_2155 ,
V_1125 ) ;
V_2152 += F_289 ( V_5 ) ;
for ( V_42 = V_2150 ; V_42 < V_2155 ; V_42 ++ , V_7 ++ ) {
if ( * ( V_2152 + V_42 ) != ( T_4 ) ( V_7 & 0xff ) )
goto V_502;
}
}
V_75 = 0 ;
V_502:
return V_75 ;
}
static int F_583 ( struct V_4 * V_5 , T_6 * V_72 , bool V_2164 )
{
int V_75 = - V_210 ;
T_1 V_2165 ;
T_1 V_2166 = 9000 ;
if ( V_5 -> V_1257 )
V_2166 = V_5 -> V_1257 - V_1199 ;
V_2165 = V_5 -> V_178 & V_338 ;
V_5 -> V_178 &= ~ V_338 ;
if ( ! F_144 ( V_5 -> V_111 ) ) {
V_72 [ V_2167 ] = V_2168 ;
V_72 [ V_2169 ] = V_2168 ;
if ( V_2164 )
V_72 [ V_2170 ] = V_2168 ;
goto V_186;
}
V_75 = F_461 ( V_5 , true ) ;
if ( V_75 ) {
V_72 [ V_2167 ] = V_2168 ;
V_72 [ V_2169 ] = V_2168 ;
if ( V_2164 )
V_72 [ V_2170 ] = V_2168 ;
goto V_186;
}
if ( F_23 ( V_5 , V_1208 ) ) {
int V_42 ;
for ( V_42 = V_1535 ;
V_42 < V_1535 + V_1533 ; V_42 += 4 )
F_46 ( V_42 , 0x0 ) ;
}
if ( F_30 ( V_5 ) != V_566 &&
! F_23 ( V_5 , V_152 ) ) {
F_391 ( V_5 , true ) ;
if ( F_580 ( V_5 , V_2171 , false ) )
V_72 [ V_2167 ] |= V_2172 ;
if ( F_23 ( V_5 , V_1345 ) &&
F_580 ( V_5 , V_2166 + V_1199 , false ) )
V_72 [ V_2167 ] |= V_2173 ;
F_391 ( V_5 , false ) ;
}
if ( ! ( V_5 -> V_178 & V_567 ) &&
! F_23 ( V_5 , V_267 ) ) {
int V_42 ;
F_392 ( V_5 , 0 , false ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
if ( F_33 ( V_952 ) & V_953 )
break;
F_98 ( 1 ) ;
}
if ( F_580 ( V_5 , V_2171 , false ) )
V_72 [ V_2169 ] |= V_2172 ;
if ( F_23 ( V_5 , V_1600 ) &&
F_580 ( V_5 , V_2171 , true ) )
V_72 [ V_2169 ] |= V_2174 ;
if ( F_23 ( V_5 , V_1345 ) &&
F_580 ( V_5 , V_2166 + V_1199 , false ) )
V_72 [ V_2169 ] |= V_2173 ;
if ( V_2164 ) {
F_392 ( V_5 , 0 , true ) ;
F_98 ( 40 ) ;
if ( F_580 ( V_5 , V_2171 , false ) )
V_72 [ V_2170 ] |=
V_2172 ;
if ( F_23 ( V_5 , V_1600 ) &&
F_580 ( V_5 , V_2171 , true ) )
V_72 [ V_2170 ] |=
V_2174 ;
if ( F_23 ( V_5 , V_1345 ) &&
F_580 ( V_5 , V_2166 + V_1199 , false ) )
V_72 [ V_2170 ] |=
V_2173 ;
}
if ( V_5 -> V_178 & V_513 )
F_127 ( V_5 , true ) ;
}
V_75 = ( V_72 [ V_2167 ] | V_72 [ V_2169 ] |
V_72 [ V_2170 ] ) ? - V_210 : 0 ;
V_186:
V_5 -> V_178 |= V_2165 ;
return V_75 ;
}
static void F_584 ( struct V_364 * V_111 , struct V_2175 * V_2176 ,
T_6 * V_72 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
bool V_2177 = V_2176 -> V_10 & V_2178 ;
if ( V_5 -> V_178 & V_399 ) {
if ( F_197 ( V_5 ) ) {
V_2176 -> V_10 |= V_2179 ;
memset ( V_72 , 1 , sizeof( T_6 ) * V_2044 ) ;
return;
}
F_42 ( V_5 , V_96 ) ;
}
memset ( V_72 , 0 , sizeof( T_6 ) * V_2044 ) ;
if ( F_563 ( V_5 ) != 0 ) {
V_2176 -> V_10 |= V_2179 ;
V_72 [ V_2180 ] = 1 ;
}
if ( ! V_2177 && F_569 ( V_5 ) ) {
V_2176 -> V_10 |= V_2179 ;
V_72 [ V_2181 ] = 1 ;
}
if ( V_2176 -> V_10 & V_2182 ) {
int V_75 , V_761 = 0 , V_125 = 0 ;
if ( F_144 ( V_111 ) ) {
F_122 ( V_5 ) ;
F_341 ( V_5 ) ;
V_125 = 1 ;
}
F_241 ( V_5 , V_125 ) ;
F_431 ( V_5 , V_320 , 1 ) ;
V_75 = F_157 ( V_5 ) ;
F_183 ( V_5 , V_653 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
F_183 ( V_5 , V_654 ) ;
if ( ! V_75 )
F_158 ( V_5 ) ;
if ( V_5 -> V_178 & V_305 )
F_143 ( V_5 ) ;
if ( F_571 ( V_5 ) != 0 ) {
V_2176 -> V_10 |= V_2179 ;
V_72 [ V_2183 ] = 1 ;
}
if ( F_579 ( V_5 ) != 0 ) {
V_2176 -> V_10 |= V_2179 ;
V_72 [ V_2184 ] = 1 ;
}
if ( V_2177 )
V_2176 -> V_10 |= V_2185 ;
if ( F_583 ( V_5 , V_72 , V_2177 ) )
V_2176 -> V_10 |= V_2179 ;
F_242 ( V_5 ) ;
if ( F_492 ( V_5 ) != 0 ) {
V_2176 -> V_10 |= V_2179 ;
V_72 [ V_2186 ] = 1 ;
}
F_241 ( V_5 , 0 ) ;
F_431 ( V_5 , V_110 , 1 ) ;
if ( F_144 ( V_111 ) ) {
F_83 ( V_5 , V_562 ) ;
V_761 = F_485 ( V_5 , true ) ;
if ( ! V_761 )
F_343 ( V_5 ) ;
}
F_242 ( V_5 ) ;
if ( V_125 && ! V_761 )
F_119 ( V_5 ) ;
}
if ( V_5 -> V_178 & V_399 )
F_199 ( V_5 ) ;
}
static int F_585 ( struct V_364 * V_111 , struct V_2187 * V_2188 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
struct V_2189 V_2190 ;
if ( ! F_23 ( V_5 , V_992 ) )
return - V_1037 ;
if ( F_586 ( & V_2190 , V_2188 -> V_2191 , sizeof( V_2190 ) ) )
return - V_2192 ;
if ( V_2190 . V_10 )
return - V_64 ;
if ( V_2190 . V_2193 != V_1000 &&
V_2190 . V_2193 != V_999 )
return - V_2194 ;
switch ( V_2190 . V_2195 ) {
case V_1002 :
V_5 -> V_1587 = 0 ;
break;
case V_1003 :
V_5 -> V_1587 = V_2196 |
V_2197 ;
break;
case V_2198 :
V_5 -> V_1587 = V_2196 |
V_2199 ;
break;
case V_2200 :
V_5 -> V_1587 = V_2196 |
V_2201 ;
break;
case V_2202 :
V_5 -> V_1587 = V_2203 |
V_2204 ;
break;
case V_1004 :
V_5 -> V_1587 = V_2205 |
V_2204 ;
break;
case V_1005 :
V_5 -> V_1587 = V_2206 |
V_2204 ;
break;
case V_2207 :
V_5 -> V_1587 = V_2203 |
V_2199 ;
break;
case V_2208 :
V_5 -> V_1587 = V_2205 |
V_2199 ;
break;
case V_2209 :
V_5 -> V_1587 = V_2206 |
V_2199 ;
break;
case V_2210 :
V_5 -> V_1587 = V_2203 |
V_2201 ;
break;
case V_2211 :
V_5 -> V_1587 = V_2205 |
V_2201 ;
break;
case V_2212 :
V_5 -> V_1587 = V_2206 |
V_2201 ;
break;
default:
return - V_2194 ;
}
if ( F_144 ( V_111 ) && V_5 -> V_1587 )
F_46 ( V_1588 ,
V_5 -> V_1587 | V_1589 ) ;
if ( V_2190 . V_2193 == V_1000 )
F_83 ( V_5 , V_1314 ) ;
else
F_85 ( V_5 , V_1314 ) ;
return F_587 ( V_2188 -> V_2191 , & V_2190 , sizeof( V_2190 ) ) ?
- V_2192 : 0 ;
}
static int F_588 ( struct V_364 * V_111 , struct V_2187 * V_2188 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
struct V_2189 V_2190 ;
if ( ! F_23 ( V_5 , V_992 ) )
return - V_1037 ;
V_2190 . V_10 = 0 ;
V_2190 . V_2193 = ( F_23 ( V_5 , V_1314 ) ?
V_1000 : V_999 ) ;
switch ( V_5 -> V_1587 ) {
case 0 :
V_2190 . V_2195 = V_1002 ;
break;
case V_2196 | V_2197 :
V_2190 . V_2195 = V_1003 ;
break;
case V_2196 | V_2199 :
V_2190 . V_2195 = V_2198 ;
break;
case V_2196 | V_2201 :
V_2190 . V_2195 = V_2200 ;
break;
case V_2203 | V_2204 :
V_2190 . V_2195 = V_2202 ;
break;
case V_2205 | V_2204 :
V_2190 . V_2195 = V_1004 ;
break;
case V_2206 | V_2204 :
V_2190 . V_2195 = V_1005 ;
break;
case V_2203 | V_2199 :
V_2190 . V_2195 = V_2207 ;
break;
case V_2205 | V_2199 :
V_2190 . V_2195 = V_2208 ;
break;
case V_2206 | V_2199 :
V_2190 . V_2195 = V_2209 ;
break;
case V_2203 | V_2201 :
V_2190 . V_2195 = V_2210 ;
break;
case V_2205 | V_2201 :
V_2190 . V_2195 = V_2211 ;
break;
case V_2206 | V_2201 :
V_2190 . V_2195 = V_2212 ;
break;
default:
F_589 ( 1 ) ;
return - V_2194 ;
}
return F_587 ( V_2188 -> V_2191 , & V_2190 , sizeof( V_2190 ) ) ?
- V_2192 : 0 ;
}
static int F_590 ( struct V_364 * V_111 , struct V_2187 * V_2188 , int V_642 )
{
struct V_2213 * V_72 = F_591 ( V_2188 ) ;
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_75 ;
if ( F_23 ( V_5 , V_267 ) ) {
struct V_211 * V_212 ;
if ( ! ( V_5 -> V_178 & V_391 ) )
return - V_85 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
return F_592 ( V_212 , V_2188 , V_642 ) ;
}
switch ( V_642 ) {
case V_2214 :
V_72 -> V_216 = V_5 -> V_160 ;
case V_2215 : {
T_1 V_2216 ;
if ( V_5 -> V_178 & V_567 )
break;
if ( ! F_144 ( V_111 ) )
return - V_85 ;
F_70 ( & V_5 -> V_209 ) ;
V_75 = F_56 ( V_5 , V_72 -> V_216 & 0x1f ,
V_72 -> V_2217 & 0x1f , & V_2216 ) ;
F_71 ( & V_5 -> V_209 ) ;
V_72 -> V_2218 = V_2216 ;
return V_75 ;
}
case V_2219 :
if ( V_5 -> V_178 & V_567 )
break;
if ( ! F_144 ( V_111 ) )
return - V_85 ;
F_70 ( & V_5 -> V_209 ) ;
V_75 = F_58 ( V_5 , V_72 -> V_216 & 0x1f ,
V_72 -> V_2217 & 0x1f , V_72 -> V_2220 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_75 ;
case V_2221 :
return F_585 ( V_111 , V_2188 ) ;
case V_2222 :
return F_588 ( V_111 , V_2188 ) ;
default:
break;
}
return - V_1037 ;
}
static int F_593 ( struct V_364 * V_111 , struct V_1464 * V_1465 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
memcpy ( V_1465 , & V_5 -> V_972 , sizeof( * V_1465 ) ) ;
return 0 ;
}
static int F_594 ( struct V_364 * V_111 , struct V_1464 * V_1465 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
T_1 V_2223 = 0 , V_2224 = 0 ;
T_1 V_2225 = 0 , V_2226 = 0 ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ) {
V_2223 = V_2227 ;
V_2224 = V_2228 ;
V_2225 = V_2229 ;
V_2226 = V_2230 ;
}
if ( ( V_1465 -> V_1476 > V_2231 ) ||
( V_1465 -> V_1467 > V_2232 ) ||
( V_1465 -> V_1478 > V_2233 ) ||
( V_1465 -> V_1469 > V_2234 ) ||
( V_1465 -> V_1484 > V_2223 ) ||
( V_1465 -> V_1486 > V_2224 ) ||
( V_1465 -> V_1480 > V_2235 ) ||
( V_1465 -> V_1471 > V_2236 ) ||
( V_1465 -> V_973 > V_2225 ) ||
( V_1465 -> V_973 < V_2226 ) )
return - V_64 ;
if ( ( V_1465 -> V_1476 == 0 ) &&
( V_1465 -> V_1478 == 0 ) )
return - V_64 ;
if ( ( V_1465 -> V_1467 == 0 ) &&
( V_1465 -> V_1469 == 0 ) )
return - V_64 ;
V_5 -> V_972 . V_1476 = V_1465 -> V_1476 ;
V_5 -> V_972 . V_1467 = V_1465 -> V_1467 ;
V_5 -> V_972 . V_1478 = V_1465 -> V_1478 ;
V_5 -> V_972 . V_1469 = V_1465 -> V_1469 ;
V_5 -> V_972 . V_1484 = V_1465 -> V_1484 ;
V_5 -> V_972 . V_1486 = V_1465 -> V_1486 ;
V_5 -> V_972 . V_1480 = V_1465 -> V_1480 ;
V_5 -> V_972 . V_1471 = V_1465 -> V_1471 ;
V_5 -> V_972 . V_973 = V_1465 -> V_973 ;
if ( F_144 ( V_111 ) ) {
F_241 ( V_5 , 0 ) ;
F_440 ( V_5 , & V_5 -> V_972 ) ;
F_242 ( V_5 ) ;
}
return 0 ;
}
static int F_595 ( struct V_364 * V_111 , struct V_451 * V_2237 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_338 ) ) {
F_142 ( V_5 -> V_111 , L_78 ) ;
return - V_1037 ;
}
if ( V_2237 -> V_463 != V_5 -> V_452 . V_463 ) {
F_142 ( V_5 -> V_111 ,
L_79 ) ;
return - V_64 ;
}
if ( V_2237 -> V_467 > V_2238 ) {
F_142 ( V_5 -> V_111 ,
L_80 ,
V_2238 ) ;
return - V_64 ;
}
V_5 -> V_452 = * V_2237 ;
V_5 -> V_178 |= V_1540 ;
F_141 ( V_5 ) ;
if ( F_144 ( V_5 -> V_111 ) ) {
F_241 ( V_5 , 0 ) ;
F_222 ( V_5 ) ;
F_143 ( V_5 ) ;
F_242 ( V_5 ) ;
}
return 0 ;
}
static int F_596 ( struct V_364 * V_111 , struct V_451 * V_2237 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( ! ( V_5 -> V_178 & V_338 ) ) {
F_142 ( V_5 -> V_111 ,
L_78 ) ;
return - V_1037 ;
}
* V_2237 = V_5 -> V_452 ;
return 0 ;
}
static struct V_1957 * F_597 ( struct V_364 * V_111 ,
struct V_1957 * V_1958 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
F_70 ( & V_5 -> V_209 ) ;
if ( ! V_5 -> V_1356 ) {
* V_1958 = V_5 -> V_1444 ;
F_71 ( & V_5 -> V_209 ) ;
return V_1958 ;
}
F_432 ( V_5 , V_1958 ) ;
F_71 ( & V_5 -> V_209 ) ;
return V_1958 ;
}
static void F_598 ( struct V_364 * V_111 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
if ( ! F_144 ( V_111 ) )
return;
F_241 ( V_5 , 0 ) ;
F_436 ( V_111 ) ;
F_242 ( V_5 ) ;
}
static inline void F_599 ( struct V_364 * V_111 , struct V_4 * V_5 ,
int V_2239 )
{
V_111 -> V_1198 = V_2239 ;
if ( V_2239 > V_1333 ) {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_600 ( V_111 ) ;
F_85 ( V_5 , V_1600 ) ;
} else {
F_83 ( V_5 , V_1345 ) ;
}
} else {
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_83 ( V_5 , V_1600 ) ;
F_600 ( V_111 ) ;
}
F_85 ( V_5 , V_1345 ) ;
}
}
static int F_601 ( struct V_364 * V_111 , int V_2239 )
{
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_75 ;
bool V_1538 = false ;
if ( V_2239 < V_2240 || V_2239 > F_464 ( V_5 ) )
return - V_64 ;
if ( ! F_144 ( V_111 ) ) {
F_599 ( V_111 , V_5 , V_2239 ) ;
return 0 ;
}
F_122 ( V_5 ) ;
F_341 ( V_5 ) ;
F_599 ( V_111 , V_5 , V_2239 ) ;
F_241 ( V_5 , 1 ) ;
F_431 ( V_5 , V_110 , 1 ) ;
if ( F_30 ( V_5 ) == V_667 )
V_1538 = true ;
V_75 = F_485 ( V_5 , V_1538 ) ;
if ( ! V_75 )
F_343 ( V_5 ) ;
F_242 ( V_5 ) ;
if ( ! V_75 )
F_119 ( V_5 ) ;
return V_75 ;
}
static void F_602 ( struct V_4 * V_5 )
{
T_1 V_2241 , V_7 , V_1983 ;
V_5 -> V_1975 = V_2242 ;
if ( F_168 ( V_5 , 0 , & V_1983 ) != 0 )
return;
if ( ( V_1983 != V_1984 ) &&
( ( V_1983 & V_2091 ) != V_2092 ) &&
( ( V_1983 & V_2108 ) != V_2109 ) )
return;
V_2241 = 0x10 ;
while ( V_2241 < V_5 -> V_1975 ) {
if ( F_168 ( V_5 , V_2241 , & V_7 ) != 0 )
return;
if ( V_7 == V_1983 )
break;
V_2241 <<= 1 ;
}
V_5 -> V_1975 = V_2241 ;
}
static void F_603 ( struct V_4 * V_5 )
{
T_1 V_7 ;
if ( F_23 ( V_5 , V_681 ) || F_168 ( V_5 , 0 , & V_7 ) != 0 )
return;
if ( V_7 != V_1984 ) {
F_602 ( V_5 ) ;
return;
}
if ( F_168 ( V_5 , 0xf0 , & V_7 ) == 0 ) {
if ( V_7 != 0 ) {
V_5 -> V_1975 = F_604 ( ( T_3 ) ( V_7 & 0x0000ffff ) ) * 1024 ;
return;
}
}
V_5 -> V_1975 = V_2243 ;
}
static void F_605 ( struct V_4 * V_5 )
{
T_1 V_2244 ;
V_2244 = F_33 ( V_2245 ) ;
if ( V_2244 & V_2246 ) {
F_83 ( V_5 , V_611 ) ;
} else {
V_2244 &= ~ V_2247 ;
F_46 ( V_2245 , V_2244 ) ;
}
if ( F_30 ( V_5 ) == V_1505 ||
F_23 ( V_5 , 5780_CLASS ) ) {
switch ( V_2244 & V_2248 ) {
case V_2249 :
V_5 -> V_613 = V_614 ;
V_5 -> V_615 = V_2250 ;
F_83 ( V_5 , V_610 ) ;
break;
case V_2251 :
V_5 -> V_613 = V_614 ;
V_5 -> V_615 = V_2252 ;
break;
case V_2253 :
V_5 -> V_613 = V_614 ;
V_5 -> V_615 = V_2254 ;
F_83 ( V_5 , V_610 ) ;
break;
case V_2255 :
V_5 -> V_613 = V_641 ;
V_5 -> V_615 = V_2256 ;
F_83 ( V_5 , V_610 ) ;
break;
case V_2257 :
V_5 -> V_613 = V_2258 ;
V_5 -> V_615 = V_2259 ;
break;
case V_2260 :
case V_2261 :
V_5 -> V_613 = V_2262 ;
V_5 -> V_615 = V_2263 ;
break;
}
} else {
V_5 -> V_613 = V_614 ;
V_5 -> V_615 = V_2250 ;
F_83 ( V_5 , V_610 ) ;
}
}
static void F_606 ( struct V_4 * V_5 , T_1 V_2264 )
{
switch ( V_2264 & V_2265 ) {
case V_2266 :
V_5 -> V_615 = 256 ;
break;
case V_2267 :
V_5 -> V_615 = 512 ;
break;
case V_2268 :
V_5 -> V_615 = 1024 ;
break;
case V_2269 :
V_5 -> V_615 = 2048 ;
break;
case V_2270 :
V_5 -> V_615 = 4096 ;
break;
case V_2271 :
V_5 -> V_615 = 264 ;
break;
case V_2272 :
V_5 -> V_615 = 528 ;
break;
}
}
static void F_607 ( struct V_4 * V_5 )
{
T_1 V_2244 ;
V_2244 = F_33 ( V_2245 ) ;
if ( V_2244 & ( 1 << 27 ) )
F_83 ( V_5 , V_591 ) ;
switch ( V_2244 & V_2273 ) {
case V_2274 :
case V_2275 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
break;
case V_2276 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
break;
case V_2277 :
case V_2278 :
case V_2279 :
V_5 -> V_613 = V_641 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
break;
}
if ( F_23 ( V_5 , V_611 ) ) {
F_606 ( V_5 , V_2244 ) ;
} else {
V_5 -> V_615 = V_2254 ;
V_2244 &= ~ V_2247 ;
F_46 ( V_2245 , V_2244 ) ;
}
}
static void F_608 ( struct V_4 * V_5 )
{
T_1 V_2244 , V_2280 = 0 ;
V_2244 = F_33 ( V_2245 ) ;
if ( V_2244 & ( 1 << 27 ) ) {
F_83 ( V_5 , V_591 ) ;
V_2280 = 1 ;
}
V_2244 &= V_2273 ;
switch ( V_2244 ) {
case V_2281 :
case V_2282 :
case V_2283 :
case V_2284 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
V_5 -> V_615 = 264 ;
if ( V_2244 == V_2281 ||
V_2244 == V_2284 )
V_5 -> V_1975 = ( V_2280 ? 0x3e200 :
V_2243 ) ;
else if ( V_2244 == V_2282 )
V_5 -> V_1975 = ( V_2280 ? 0x1f200 :
V_2285 ) ;
else
V_5 -> V_1975 = ( V_2280 ? 0x1f200 :
V_2286 ) ;
break;
case V_2277 :
case V_2278 :
case V_2279 :
V_5 -> V_613 = V_641 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
V_5 -> V_615 = 256 ;
if ( V_2244 == V_2277 )
V_5 -> V_1975 = ( V_2280 ?
V_2287 :
V_2286 ) ;
else if ( V_2244 == V_2278 )
V_5 -> V_1975 = ( V_2280 ?
V_2287 :
V_2285 ) ;
else
V_5 -> V_1975 = ( V_2280 ?
V_2286 :
V_2243 ) ;
break;
}
}
static void F_609 ( struct V_4 * V_5 )
{
T_1 V_2244 ;
V_2244 = F_33 ( V_2245 ) ;
switch ( V_2244 & V_2273 ) {
case V_2288 :
case V_2289 :
case V_2290 :
case V_2291 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
V_5 -> V_615 = V_2254 ;
V_2244 &= ~ V_2247 ;
F_46 ( V_2245 , V_2244 ) ;
break;
case V_2276 :
case V_2281 :
case V_2282 :
case V_2283 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
V_5 -> V_615 = 264 ;
break;
case V_2277 :
case V_2278 :
case V_2279 :
V_5 -> V_613 = V_641 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
V_5 -> V_615 = 256 ;
break;
}
}
static void F_610 ( struct V_4 * V_5 )
{
T_1 V_2244 , V_2280 = 0 ;
V_2244 = F_33 ( V_2245 ) ;
if ( V_2244 & ( 1 << 27 ) ) {
F_83 ( V_5 , V_591 ) ;
V_2280 = 1 ;
}
V_2244 &= V_2273 ;
switch ( V_2244 ) {
case V_2292 :
case V_2293 :
case V_2294 :
case V_2295 :
case V_2296 :
case V_2297 :
case V_2298 :
case V_2299 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
F_83 ( V_5 , V_612 ) ;
V_5 -> V_615 = 256 ;
break;
case V_2300 :
case V_2301 :
case V_2302 :
case V_2303 :
case V_2304 :
case V_2305 :
case V_2306 :
case V_2307 :
V_5 -> V_613 = V_641 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
V_5 -> V_615 = 256 ;
break;
}
if ( V_2280 ) {
V_5 -> V_1975 = F_33 ( V_2308 ) ;
} else {
switch ( V_2244 ) {
case V_2295 :
case V_2299 :
case V_2303 :
case V_2307 :
V_5 -> V_1975 = V_2309 ;
break;
case V_2294 :
case V_2298 :
case V_2302 :
case V_2306 :
V_5 -> V_1975 = V_2310 ;
break;
case V_2293 :
case V_2297 :
case V_2301 :
case V_2305 :
V_5 -> V_1975 = V_2243 ;
break;
case V_2292 :
case V_2296 :
case V_2300 :
case V_2304 :
V_5 -> V_1975 = V_2285 ;
break;
}
}
}
static void F_611 ( struct V_4 * V_5 )
{
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
V_5 -> V_615 = V_2254 ;
}
static void F_612 ( struct V_4 * V_5 )
{
T_1 V_2244 ;
V_2244 = F_33 ( V_2245 ) ;
switch ( V_2244 & V_2273 ) {
case V_2289 :
case V_2291 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
V_5 -> V_615 = V_2254 ;
V_2244 &= ~ V_2247 ;
F_46 ( V_2245 , V_2244 ) ;
return;
case V_2276 :
case V_2311 :
case V_2312 :
case V_2313 :
case V_2314 :
case V_2315 :
case V_2316 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
switch ( V_2244 & V_2273 ) {
case V_2276 :
case V_2311 :
case V_2312 :
V_5 -> V_1975 = V_2286 ;
break;
case V_2313 :
case V_2314 :
V_5 -> V_1975 = V_2285 ;
break;
case V_2315 :
case V_2316 :
V_5 -> V_1975 = V_2243 ;
break;
}
break;
case V_2277 :
case V_2278 :
case V_2279 :
V_5 -> V_613 = V_641 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
switch ( V_2244 & V_2273 ) {
case V_2277 :
V_5 -> V_1975 = V_2286 ;
break;
case V_2278 :
V_5 -> V_1975 = V_2285 ;
break;
case V_2279 :
V_5 -> V_1975 = V_2243 ;
break;
}
break;
default:
F_83 ( V_5 , V_681 ) ;
return;
}
F_606 ( V_5 , V_2244 ) ;
if ( V_5 -> V_615 != 264 && V_5 -> V_615 != 528 )
F_83 ( V_5 , V_612 ) ;
}
static void F_613 ( struct V_4 * V_5 )
{
T_1 V_2244 ;
V_2244 = F_33 ( V_2245 ) ;
switch ( V_2244 & V_2273 ) {
case V_2317 :
case V_2318 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
V_5 -> V_615 = V_2254 ;
V_2244 &= ~ V_2247 ;
F_46 ( V_2245 , V_2244 ) ;
return;
case V_2319 :
case V_2320 :
case V_2321 :
case V_2322 :
case V_2323 :
case V_2324 :
case V_2325 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
switch ( V_2244 & V_2273 ) {
case V_2322 :
break;
case V_2323 :
case V_2324 :
V_5 -> V_1975 = V_2285 ;
break;
default:
V_5 -> V_1975 = V_2286 ;
break;
}
break;
case V_2326 :
case V_2327 :
case V_2328 :
case V_2329 :
case V_2330 :
case V_2331 :
case V_2332 :
case V_2333 :
case V_2334 :
case V_2335 :
V_5 -> V_613 = V_641 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
switch ( V_2244 & V_2273 ) {
case V_2330 :
case V_2332 :
break;
case V_2331 :
case V_2333 :
V_5 -> V_1975 = V_2285 ;
break;
default:
V_5 -> V_1975 = V_2286 ;
break;
}
break;
default:
F_83 ( V_5 , V_681 ) ;
return;
}
F_606 ( V_5 , V_2244 ) ;
if ( V_5 -> V_615 != 264 && V_5 -> V_615 != 528 )
F_83 ( V_5 , V_612 ) ;
}
static void F_614 ( struct V_4 * V_5 )
{
T_1 V_2244 , V_2336 ;
V_2244 = F_33 ( V_2245 ) ;
V_2336 = V_2244 & V_2273 ;
if ( F_30 ( V_5 ) == V_767 ) {
if ( ! ( V_2244 & V_2337 ) ) {
F_83 ( V_5 , V_681 ) ;
return;
}
switch ( V_2336 ) {
case V_2338 :
V_2336 = V_2339 ;
break;
case V_2340 :
V_2336 = V_2341 ;
break;
case V_2342 :
V_2336 = V_2343 ;
break;
}
}
switch ( V_2336 ) {
case V_2339 :
case V_2341 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
V_2244 &= ~ V_2247 ;
F_46 ( V_2245 , V_2244 ) ;
if ( V_2336 == V_2339 )
V_5 -> V_615 = V_2254 ;
else
V_5 -> V_615 = V_2344 ;
return;
case V_2345 :
case V_2346 :
case V_2347 :
case V_2348 :
case V_2349 :
case V_2350 :
case V_2351 :
case V_2352 :
case V_2353 :
case V_2354 :
case V_2355 :
case V_2356 :
V_5 -> V_613 = V_614 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
switch ( V_2336 ) {
case V_2348 :
case V_2349 :
case V_2350 :
V_5 -> V_1975 = V_2285 ;
break;
case V_2351 :
case V_2352 :
case V_2353 :
V_5 -> V_1975 = V_2243 ;
break;
case V_2354 :
case V_2355 :
V_5 -> V_1975 = V_2310 ;
break;
default:
if ( F_30 ( V_5 ) != V_767 )
V_5 -> V_1975 = V_2286 ;
break;
}
break;
case V_2357 :
case V_2358 :
case V_2359 :
case V_2360 :
case V_2361 :
case V_2342 :
case V_2362 :
case V_2363 :
case V_2364 :
case V_2365 :
case V_2366 :
case V_2367 :
case V_2368 :
case V_2369 :
case V_2370 :
case V_2371 :
case V_2372 :
case V_2343 :
V_5 -> V_613 = V_641 ;
F_83 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_611 ) ;
switch ( V_2336 ) {
case V_2361 :
case V_2342 :
case V_2362 :
case V_2363 :
V_5 -> V_1975 = V_2285 ;
break;
case V_2364 :
case V_2365 :
case V_2366 :
case V_2367 :
V_5 -> V_1975 = V_2243 ;
break;
case V_2368 :
case V_2369 :
case V_2370 :
case V_2371 :
V_5 -> V_1975 = V_2310 ;
break;
default:
if ( F_30 ( V_5 ) != V_767 )
V_5 -> V_1975 = V_2286 ;
break;
}
break;
default:
F_83 ( V_5 , V_681 ) ;
return;
}
F_606 ( V_5 , V_2244 ) ;
if ( V_5 -> V_615 != 264 && V_5 -> V_615 != 528 )
F_83 ( V_5 , V_612 ) ;
if ( F_30 ( V_5 ) == V_767 ) {
T_1 V_7 ;
if ( F_168 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 != V_1984 &&
( V_7 & V_2091 ) != V_2092 )
F_83 ( V_5 , V_681 ) ;
}
}
static void F_615 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_264 ) ) {
F_85 ( V_5 , V_585 ) ;
F_85 ( V_5 , V_610 ) ;
F_83 ( V_5 , V_681 ) ;
return;
}
F_31 ( V_598 ,
( V_2373 |
( V_2374 <<
V_2375 ) ) ) ;
F_162 ( 1 ) ;
F_31 ( V_136 ,
F_33 ( V_136 ) | V_2376 ) ;
F_24 ( 100 ) ;
if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 ) {
F_83 ( V_5 , V_585 ) ;
if ( F_157 ( V_5 ) ) {
F_142 ( V_5 -> V_111 ,
L_81 ,
V_657 ) ;
return;
}
F_159 ( V_5 ) ;
V_5 -> V_1975 = 0 ;
if ( F_30 ( V_5 ) == V_640 )
F_607 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1494 )
F_608 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1507 ||
F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_257 )
F_609 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_45 )
F_610 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_36 )
F_611 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_1411 ||
F_23 ( V_5 , 57765_CLASS ) )
F_612 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 )
F_613 ( V_5 ) ;
else if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_767 )
F_614 ( V_5 ) ;
else
F_605 ( V_5 ) ;
if ( V_5 -> V_1975 == 0 )
F_603 ( V_5 ) ;
F_160 ( V_5 ) ;
F_158 ( V_5 ) ;
} else {
F_85 ( V_5 , V_585 ) ;
F_85 ( V_5 , V_610 ) ;
F_602 ( V_5 ) ;
}
}
static struct V_2377 * F_616 ( struct V_4 * V_5 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_578 ( V_2378 ) ; V_42 ++ ) {
if ( ( V_2378 [ V_42 ] . V_2379 ==
V_5 -> V_12 -> V_2380 ) &&
( V_2378 [ V_42 ] . V_2381 ==
V_5 -> V_12 -> V_2382 ) )
return & V_2378 [ V_42 ] ;
}
return NULL ;
}
static void F_617 ( struct V_4 * V_5 )
{
T_1 V_7 ;
V_5 -> V_216 = V_2383 ;
V_5 -> V_563 = V_821 ;
F_83 ( V_5 , V_643 ) ;
F_83 ( V_5 , V_717 ) ;
if ( F_30 ( V_5 ) == V_36 ) {
if ( ! ( F_33 ( V_1909 ) & V_2384 ) ) {
F_85 ( V_5 , V_643 ) ;
F_83 ( V_5 , V_532 ) ;
}
V_7 = F_33 ( V_2385 ) ;
if ( V_7 & V_2386 )
F_83 ( V_5 , V_974 ) ;
if ( ( V_7 & V_2387 ) &&
( V_7 & V_2388 ) ) {
F_83 ( V_5 , V_112 ) ;
F_541 ( & V_5 -> V_12 -> V_111 , true ) ;
}
goto V_186;
}
F_32 ( V_5 , V_1436 , & V_7 ) ;
if ( V_7 == V_1437 ) {
T_1 V_1438 , V_2389 ;
T_1 V_2390 = 0 , V_2391 = 0 , V_2392 = 0 ;
T_1 V_2393 , V_2394 , V_2395 ;
int V_2396 = 0 ;
F_32 ( V_5 , V_1439 , & V_1438 ) ;
V_5 -> V_550 = V_1438 ;
F_32 ( V_5 , V_2397 , & V_2394 ) ;
V_2394 >>= V_2398 ;
if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 &&
F_30 ( V_5 ) != V_499 &&
( V_2394 > 0 ) && ( V_2394 < 0x100 ) )
F_32 ( V_5 , V_2399 , & V_2390 ) ;
if ( F_30 ( V_5 ) == V_257 )
F_32 ( V_5 , V_2400 , & V_2391 ) ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 )
F_32 ( V_5 , V_2401 , & V_2392 ) ;
if ( ( V_1438 & V_2402 ) ==
V_2403 )
V_2396 = 1 ;
F_32 ( V_5 , V_2404 , & V_2393 ) ;
if ( V_2393 != 0 ) {
T_1 V_2405 = V_2393 & V_2406 ;
T_1 V_2407 = V_2393 & V_2408 ;
V_2395 = ( V_2405 >> 16 ) << 10 ;
V_2395 |= ( V_2407 & 0xfc00 ) << 16 ;
V_2395 |= ( V_2407 & 0x03ff ) << 0 ;
} else
V_2395 = 0 ;
V_5 -> V_216 = V_2395 ;
if ( V_2396 ) {
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_5 -> V_178 |= V_567 ;
else
V_5 -> V_178 |= V_305 ;
}
if ( F_23 ( V_5 , 5750_PLUS ) )
V_2389 = V_2390 & ( V_2409 |
V_2410 ) ;
else
V_2389 = V_1438 & V_2409 ;
switch ( V_2389 ) {
default:
case V_2411 :
V_5 -> V_563 = V_821 ;
break;
case V_2412 :
V_5 -> V_563 = V_564 ;
break;
case V_2413 :
V_5 -> V_563 = V_2414 ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 )
V_5 -> V_563 = V_821 ;
break;
case V_2415 :
V_5 -> V_563 = V_2416 ;
if ( F_76 ( V_5 ) != V_1419 &&
F_76 ( V_5 ) != V_2417 )
V_5 -> V_563 |= ( V_821 |
V_564 ) ;
if ( F_23 ( V_5 , 5717_PLUS ) ||
F_30 ( V_5 ) == V_767 )
V_5 -> V_563 |= V_2418 |
V_2419 ;
break;
case V_2420 :
V_5 -> V_563 = V_2421 ;
break;
case V_2422 :
V_5 -> V_563 = V_2423 ;
if ( F_76 ( V_5 ) != V_1419 )
V_5 -> V_563 |= ( V_821 |
V_564 ) ;
break;
}
if ( ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) &&
V_5 -> V_12 -> V_2380 == V_2424 )
V_5 -> V_563 = V_564 ;
if ( F_145 ( V_5 ) == V_503 )
V_5 -> V_563 = V_821 ;
if ( V_1438 & V_2425 ) {
F_83 ( V_5 , V_643 ) ;
if ( ( V_5 -> V_12 -> V_2380 ==
V_2426 ) &&
( V_5 -> V_12 -> V_2382 == 0x205a ||
V_5 -> V_12 -> V_2382 == 0x2063 ) )
F_85 ( V_5 , V_643 ) ;
} else {
F_85 ( V_5 , V_643 ) ;
F_83 ( V_5 , V_532 ) ;
}
if ( V_1438 & V_1440 ) {
F_83 ( V_5 , V_308 ) ;
if ( F_23 ( V_5 , 5750_PLUS ) )
F_83 ( V_5 , V_316 ) ;
}
if ( ( V_1438 & V_2427 ) &&
F_23 ( V_5 , 5750_PLUS ) )
F_83 ( V_5 , V_60 ) ;
if ( V_5 -> V_178 & V_359 &&
! ( V_1438 & V_2428 ) )
F_85 ( V_5 , V_717 ) ;
if ( F_23 ( V_5 , V_717 ) &&
( V_1438 & V_2429 ) ) {
F_83 ( V_5 , V_112 ) ;
F_541 ( & V_5 -> V_12 -> V_111 , true ) ;
}
if ( V_2390 & ( 1 << 17 ) )
V_5 -> V_178 |= V_824 ;
if ( V_2390 & ( 1 << 18 ) )
V_5 -> V_178 |= V_1737 ;
if ( ( F_23 ( V_5 , 57765_PLUS ) ||
( F_30 ( V_5 ) == V_413 &&
F_145 ( V_5 ) != V_503 ) ) &&
( V_2390 & V_2430 ) )
V_5 -> V_178 |= V_513 ;
if ( F_23 ( V_5 , V_1079 ) ) {
T_1 V_2431 ;
F_32 ( V_5 , V_1441 , & V_2431 ) ;
if ( F_30 ( V_5 ) != V_257 &&
! F_23 ( V_5 , 57765_PLUS ) &&
( V_2431 & V_2432 ) )
F_83 ( V_5 , V_974 ) ;
if ( V_2431 & V_1443 )
V_5 -> V_178 |= V_569 ;
if ( V_2431 & V_1442 )
V_5 -> V_178 |= V_771 ;
}
if ( V_2391 & V_2433 )
F_83 ( V_5 , V_236 ) ;
if ( V_2391 & V_2434 )
F_83 ( V_5 , V_245 ) ;
if ( V_2391 & V_2435 )
F_83 ( V_5 , V_246 ) ;
if ( V_2392 & V_2436 )
V_5 -> V_178 |= V_772 ;
}
V_186:
if ( F_23 ( V_5 , V_717 ) )
F_541 ( & V_5 -> V_12 -> V_111 ,
F_23 ( V_5 , V_112 ) ) ;
else
F_618 ( & V_5 -> V_12 -> V_111 , false ) ;
}
static int F_619 ( struct V_4 * V_5 , T_1 V_595 , T_1 * V_7 )
{
int V_42 , V_75 ;
T_1 V_2437 , V_6 = V_595 * 8 ;
V_75 = F_157 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_11 ( V_5 , V_2438 , V_6 | V_2439 ) ;
F_11 ( V_5 , V_2440 , V_2441 |
V_2442 | V_2443 ) ;
F_12 ( V_5 , V_2440 ) ;
F_24 ( 10 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_2437 = F_12 ( V_5 , V_2444 ) ;
if ( V_2437 & V_2445 ) {
* V_7 = F_12 ( V_5 , V_2446 ) ;
break;
}
F_24 ( 10 ) ;
}
F_11 ( V_5 , V_2440 , 0 ) ;
F_158 ( V_5 ) ;
if ( V_2437 & V_2445 )
return 0 ;
return - V_67 ;
}
static int F_620 ( struct V_4 * V_5 , T_1 V_642 )
{
int V_42 ;
T_1 V_7 ;
F_46 ( V_2447 , V_642 | V_2448 ) ;
F_46 ( V_2447 , V_642 ) ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_7 = F_33 ( V_2449 ) ;
if ( V_7 & V_2450 )
break;
F_24 ( 10 ) ;
}
return ( V_7 & V_2450 ) ? 0 : - V_67 ;
}
static T_1 F_621 ( struct V_4 * V_5 )
{
T_1 V_2451 , V_2452 ;
F_46 ( V_2453 , V_2454 ) ;
if ( F_620 ( V_5 , V_2455 ) )
return 0 ;
F_46 ( V_2456 , V_2457 ) ;
if ( F_620 ( V_5 , V_2458 ) )
return 0 ;
V_2452 = F_33 ( V_2459 ) ;
F_46 ( V_2456 , V_2460 ) ;
if ( F_620 ( V_5 , V_2458 ) )
return 0 ;
V_2451 = F_33 ( V_2459 ) ;
return ( ( V_2452 & 0x0000ffff ) << 16 ) | ( V_2451 >> 16 ) ;
}
static void F_622 ( struct V_4 * V_5 )
{
T_1 V_341 = V_705 ;
if ( ! ( V_5 -> V_178 & V_392 ) ) {
if ( ! ( V_5 -> V_178 & V_772 ) )
V_341 |= V_773 ;
V_341 |= V_763 ;
}
if ( ! ( V_5 -> V_178 & V_359 ) )
V_341 |= V_708 |
V_709 |
V_706 |
V_710 |
V_703 ;
else
V_341 |= V_780 ;
V_5 -> V_329 . V_398 = V_341 ;
V_5 -> V_329 . V_372 = V_753 ;
V_5 -> V_329 . V_376 = V_754 ;
V_5 -> V_329 . V_352 = V_357 ;
V_5 -> V_329 . V_330 = V_753 ;
V_5 -> V_329 . V_333 = V_754 ;
V_5 -> V_390 = - 1 ;
}
static int F_623 ( struct V_4 * V_5 )
{
T_1 V_2461 , V_2462 ;
T_1 V_2463 , V_2464 ;
int V_75 ;
F_83 ( V_5 , V_358 ) ;
V_5 -> V_329 . V_342 = V_336 | V_337 ;
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
if ( ! F_23 ( V_5 , V_308 ) &&
! ( V_5 -> V_178 & V_359 ) &&
! ( V_5 -> V_178 & V_392 ) )
V_5 -> V_178 &= ~ ( V_771 |
V_569 ) ;
if ( F_23 ( V_5 , V_267 ) )
return F_112 ( V_5 ) ;
V_75 = 0 ;
if ( F_23 ( V_5 , V_308 ) || F_23 ( V_5 , V_60 ) ) {
V_2463 = V_2464 = V_2383 ;
} else {
V_75 |= F_57 ( V_5 , V_2465 , & V_2461 ) ;
V_75 |= F_57 ( V_5 , V_2466 , & V_2462 ) ;
V_2463 = ( V_2461 & 0xffff ) << 10 ;
V_2463 |= ( V_2462 & 0xfc00 ) << 16 ;
V_2463 |= ( V_2462 & 0x03ff ) << 0 ;
V_2464 = V_2463 & V_400 ;
}
if ( ! V_75 && F_624 ( V_2464 ) ) {
V_5 -> V_216 = V_2463 ;
if ( V_2464 == V_941 )
V_5 -> V_178 |= V_567 ;
else
V_5 -> V_178 &= ~ V_567 ;
} else {
if ( V_5 -> V_216 != V_2383 ) {
} else {
struct V_2377 * V_1446 ;
V_1446 = F_616 ( V_5 ) ;
if ( V_1446 ) {
V_5 -> V_216 = V_1446 -> V_216 ;
} else if ( ! F_23 ( V_5 , V_264 ) ) {
return - V_82 ;
}
if ( ! V_5 -> V_216 ||
V_5 -> V_216 == V_941 )
V_5 -> V_178 |= V_567 ;
}
}
if ( ! ( V_5 -> V_178 & V_359 ) &&
( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_667 ||
F_30 ( V_5 ) == V_767 ||
( F_30 ( V_5 ) == V_476 &&
F_76 ( V_5 ) != V_259 ) ||
( F_30 ( V_5 ) == V_765 &&
F_76 ( V_5 ) != V_327 ) ) ) {
V_5 -> V_178 |= V_338 ;
V_5 -> V_452 . V_393 = V_1995 |
V_1993 ;
V_5 -> V_452 . V_463 = V_709 |
V_763 ;
V_5 -> V_452 . V_462 = 1 ;
V_5 -> V_452 . V_465 = 1 ;
V_5 -> V_452 . V_467 = V_2467 ;
}
F_622 ( V_5 ) ;
if ( ! ( V_5 -> V_178 & V_569 ) &&
! ( V_5 -> V_178 & V_359 ) &&
! F_23 ( V_5 , V_60 ) &&
! F_23 ( V_5 , V_308 ) ) {
T_1 V_812 , V_2468 ;
F_57 ( V_5 , V_302 , & V_812 ) ;
if ( ! F_57 ( V_5 , V_302 , & V_812 ) &&
( V_812 & V_778 ) )
goto V_2469;
V_75 = F_143 ( V_5 ) ;
if ( V_75 )
return V_75 ;
F_129 ( V_5 ) ;
if ( ! F_215 ( V_5 , & V_2468 ) ) {
F_205 ( V_5 , V_5 -> V_329 . V_398 ,
V_5 -> V_329 . V_342 ) ;
F_59 ( V_5 , V_204 ,
V_576 | V_577 ) ;
}
}
V_2469:
if ( ( V_5 -> V_216 & V_400 ) == V_401 ) {
V_75 = F_213 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_213 ( V_5 ) ;
}
return V_75 ;
}
static void F_625 ( struct V_4 * V_5 )
{
T_4 * V_2470 ;
unsigned int V_2471 , V_2472 , V_74 ;
T_1 V_2076 ;
int V_627 , V_42 = 0 ;
V_2470 = ( T_4 * ) F_561 ( V_5 , & V_2076 ) ;
if ( ! V_2470 )
goto V_2473;
V_42 = F_566 ( V_2470 , 0 , V_2076 , V_2119 ) ;
if ( V_42 < 0 )
goto V_2474;
V_2472 = F_567 ( & V_2470 [ V_42 ] ) ;
V_2471 = V_42 + V_2120 + V_2472 ;
V_42 += V_2120 ;
if ( V_2471 > V_2076 )
goto V_2474;
V_627 = F_568 ( V_2470 , V_42 , V_2472 ,
V_2475 ) ;
if ( V_627 > 0 ) {
V_74 = F_626 ( & V_2470 [ V_627 ] ) ;
V_627 += V_2122 ;
if ( V_627 + V_74 > V_2471 || V_74 != 4 ||
memcmp ( & V_2470 [ V_627 ] , L_82 , 4 ) )
goto V_2476;
V_627 = F_568 ( V_2470 , V_42 , V_2472 ,
V_2477 ) ;
if ( V_627 < 0 )
goto V_2476;
V_74 = F_626 ( & V_2470 [ V_627 ] ) ;
V_627 += V_2122 ;
if ( V_627 + V_74 > V_2471 )
goto V_2476;
if ( V_74 >= sizeof( V_5 -> V_2020 ) )
V_74 = sizeof( V_5 -> V_2020 ) - 1 ;
memset ( V_5 -> V_2020 , 0 , sizeof( V_5 -> V_2020 ) ) ;
snprintf ( V_5 -> V_2020 , sizeof( V_5 -> V_2020 ) , L_83 , V_74 ,
& V_2470 [ V_627 ] ) ;
}
V_2476:
V_42 = F_568 ( V_2470 , V_42 , V_2472 ,
V_2478 ) ;
if ( V_42 < 0 )
goto V_2474;
V_74 = F_626 ( & V_2470 [ V_42 ] ) ;
V_42 += V_2122 ;
if ( V_74 > V_2479 ||
( V_74 + V_42 ) > V_2076 )
goto V_2474;
memcpy ( V_5 -> V_2480 , & V_2470 [ V_42 ] , V_74 ) ;
V_2474:
F_175 ( V_2470 ) ;
if ( V_5 -> V_2480 [ 0 ] )
return;
V_2473:
if ( F_30 ( V_5 ) == V_476 ) {
if ( V_5 -> V_12 -> V_543 == V_2481 ||
V_5 -> V_12 -> V_543 == V_2482 )
strcpy ( V_5 -> V_2480 , L_84 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2483 )
strcpy ( V_5 -> V_2480 , L_85 ) ;
else
goto V_2484;
} else if ( F_30 ( V_5 ) == V_1411 ) {
if ( V_5 -> V_12 -> V_543 == V_2485 )
strcpy ( V_5 -> V_2480 , L_86 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2486 )
strcpy ( V_5 -> V_2480 , L_87 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2487 )
strcpy ( V_5 -> V_2480 , L_88 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2488 )
strcpy ( V_5 -> V_2480 , L_89 ) ;
else
goto V_2484;
} else if ( F_30 ( V_5 ) == V_765 ) {
if ( V_5 -> V_12 -> V_543 == V_2489 )
strcpy ( V_5 -> V_2480 , L_90 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2490 )
strcpy ( V_5 -> V_2480 , L_91 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2491 )
strcpy ( V_5 -> V_2480 , L_92 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2492 )
strcpy ( V_5 -> V_2480 , L_93 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2493 )
strcpy ( V_5 -> V_2480 , L_94 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2494 )
strcpy ( V_5 -> V_2480 , L_95 ) ;
else
goto V_2484;
} else if ( F_30 ( V_5 ) == V_667 ) {
if ( V_5 -> V_12 -> V_543 == V_2495 )
strcpy ( V_5 -> V_2480 , L_96 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2496 )
strcpy ( V_5 -> V_2480 , L_97 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2497 )
strcpy ( V_5 -> V_2480 , L_98 ) ;
else if ( V_5 -> V_12 -> V_543 == V_2498 )
strcpy ( V_5 -> V_2480 , L_99 ) ;
else
goto V_2484;
} else if ( F_30 ( V_5 ) == V_36 ) {
strcpy ( V_5 -> V_2480 , L_100 ) ;
} else {
V_2484:
strcpy ( V_5 -> V_2480 , L_101 ) ;
}
}
static int F_627 ( struct V_4 * V_5 , T_1 V_595 )
{
T_1 V_7 ;
if ( F_168 ( V_5 , V_595 , & V_7 ) ||
( V_7 & 0xfc000000 ) != 0x0c000000 ||
F_168 ( V_5 , V_595 + 4 , & V_7 ) ||
V_7 != 0 )
return 0 ;
return 1 ;
}
static void F_628 ( struct V_4 * V_5 )
{
T_1 V_7 , V_595 , V_1028 , V_2499 ;
int V_42 , V_2500 ;
bool V_2501 = false ;
if ( F_168 ( V_5 , 0xc , & V_595 ) ||
F_168 ( V_5 , 0x4 , & V_1028 ) )
return;
V_595 = F_167 ( V_5 , V_595 ) ;
if ( F_168 ( V_5 , V_595 , & V_7 ) )
return;
if ( ( V_7 & 0xfc000000 ) == 0x0c000000 ) {
if ( F_168 ( V_5 , V_595 + 4 , & V_7 ) )
return;
if ( V_7 == 0 )
V_2501 = true ;
}
V_2500 = strlen ( V_5 -> V_2020 ) ;
if ( V_2501 ) {
if ( V_2502 - V_2500 < 16 ||
F_168 ( V_5 , V_595 + 8 , & V_2499 ) )
return;
V_595 = V_595 + V_2499 - V_1028 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 += 4 ) {
T_5 V_624 ;
if ( F_169 ( V_5 , V_595 + V_42 , & V_624 ) )
return;
memcpy ( V_5 -> V_2020 + V_2500 + V_42 , & V_624 , sizeof( V_624 ) ) ;
}
} else {
T_1 V_2503 , V_2504 ;
if ( F_168 ( V_5 , V_2505 , & V_2499 ) )
return;
V_2503 = ( V_2499 & V_2506 ) >>
V_2507 ;
V_2504 = V_2499 & V_2508 ;
snprintf ( & V_5 -> V_2020 [ V_2500 ] , V_2502 - V_2500 ,
L_102 , V_2503 , V_2504 ) ;
}
}
static void F_629 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2503 , V_2504 ;
if ( F_168 ( V_5 , V_2509 , & V_7 ) )
return;
V_2503 = ( V_7 & V_2510 ) >>
V_2511 ;
V_2504 = ( V_7 & V_2512 ) >>
V_2513 ;
snprintf ( & V_5 -> V_2020 [ 0 ] , 32 , L_103 , V_2503 , V_2504 ) ;
}
static void F_630 ( struct V_4 * V_5 , T_1 V_7 )
{
T_1 V_595 , V_2503 , V_2504 , V_2514 ;
strncat ( V_5 -> V_2020 , L_104 , V_2502 - strlen ( V_5 -> V_2020 ) - 1 ) ;
if ( ( V_7 & V_2093 ) != V_2094 )
return;
switch ( V_7 & V_2095 ) {
case V_2096 :
V_595 = V_2515 ;
break;
case V_2098 :
V_595 = V_2516 ;
break;
case V_2100 :
V_595 = V_2517 ;
break;
case V_2102 :
V_595 = V_2518 ;
break;
case V_2104 :
V_595 = V_2519 ;
break;
case V_2106 :
V_595 = V_2520 ;
break;
default:
return;
}
if ( F_168 ( V_5 , V_595 , & V_7 ) )
return;
V_2514 = ( V_7 & V_2521 ) >>
V_2522 ;
V_2503 = ( V_7 & V_2523 ) >>
V_2524 ;
V_2504 = V_7 & V_2525 ;
if ( V_2504 > 99 || V_2514 > 26 )
return;
V_595 = strlen ( V_5 -> V_2020 ) ;
snprintf ( & V_5 -> V_2020 [ V_595 ] , V_2502 - V_595 ,
L_105 , V_2503 , V_2504 ) ;
if ( V_2514 > 0 ) {
V_595 = strlen ( V_5 -> V_2020 ) ;
if ( V_595 < V_2502 - 1 )
V_5 -> V_2020 [ V_595 ] = 'a' + V_2514 - 1 ;
}
}
static void F_631 ( struct V_4 * V_5 )
{
T_1 V_7 , V_595 , V_1028 ;
int V_42 , V_2526 ;
for ( V_595 = V_2077 ;
V_595 < V_2078 ;
V_595 += V_2079 ) {
if ( F_168 ( V_5 , V_595 , & V_7 ) )
return;
if ( ( V_7 >> V_2080 ) == V_2527 )
break;
}
if ( V_595 == V_2078 )
return;
if ( ! F_23 ( V_5 , 5705_PLUS ) )
V_1028 = 0x08000000 ;
else if ( F_168 ( V_5 , V_595 - 4 , & V_1028 ) )
return;
if ( F_168 ( V_5 , V_595 + 4 , & V_595 ) ||
! F_627 ( V_5 , V_595 ) ||
F_168 ( V_5 , V_595 + 8 , & V_7 ) )
return;
V_595 += V_7 - V_1028 ;
V_2526 = strlen ( V_5 -> V_2020 ) ;
V_5 -> V_2020 [ V_2526 ++ ] = ',' ;
V_5 -> V_2020 [ V_2526 ++ ] = ' ' ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
T_5 V_624 ;
if ( F_169 ( V_5 , V_595 , & V_624 ) )
return;
V_595 += sizeof( V_624 ) ;
if ( V_2526 > V_2502 - sizeof( V_624 ) ) {
memcpy ( & V_5 -> V_2020 [ V_2526 ] , & V_624 , V_2502 - V_2526 ) ;
break;
}
memcpy ( & V_5 -> V_2020 [ V_2526 ] , & V_624 , sizeof( V_624 ) ) ;
V_2526 += sizeof( V_624 ) ;
}
}
static void F_632 ( struct V_4 * V_5 )
{
T_1 V_69 ;
V_69 = F_12 ( V_5 , V_80 ) ;
if ( V_69 != V_81 )
return;
V_69 = F_12 ( V_5 , V_83 ) ;
if ( ! ( V_69 & V_84 ) )
return;
if ( F_12 ( V_5 , V_2528 ) & V_2529 )
F_83 ( V_5 , V_79 ) ;
}
static void F_633 ( struct V_4 * V_5 )
{
int V_2526 ;
T_1 V_69 ;
char * V_2530 ;
V_69 = F_12 ( V_5 , V_2531 ) ;
if ( F_23 ( V_5 , V_79 ) )
V_2530 = L_106 ;
else if ( V_5 -> V_12 -> V_543 == V_2532 )
V_2530 = L_107 ;
else
V_2530 = L_108 ;
V_2526 = strlen ( V_5 -> V_2020 ) ;
snprintf ( & V_5 -> V_2020 [ V_2526 ] , V_2502 - V_2526 , L_109 ,
V_2530 ,
( V_69 & V_2533 ) >> V_2534 ,
( V_69 & V_2535 ) >> V_2536 ,
( V_69 & V_2537 ) >> V_2538 ,
( V_69 & V_2539 ) ) ;
}
static void F_634 ( struct V_4 * V_5 )
{
T_1 V_7 , V_2437 ;
if ( F_30 ( V_5 ) != V_767 )
return;
if ( ! F_619 ( V_5 , V_2540 , & V_7 ) &&
! F_619 ( V_5 , V_2540 + 4 , & V_2437 ) &&
F_635 ( V_7 ) ) {
T_6 V_2541 = ( T_6 ) V_7 << 32 | V_2437 ;
T_1 V_2394 = 0 ;
int V_42 , V_2526 ;
for ( V_42 = 0 ; V_42 < 7 ; V_42 ++ ) {
if ( ( V_2541 & 0xff ) == 0 )
break;
V_2394 = V_2541 & 0xff ;
V_2541 >>= 8 ;
}
V_2526 = strlen ( V_5 -> V_2020 ) ;
snprintf ( & V_5 -> V_2020 [ V_2526 ] , V_2502 - V_2526 , L_110 , V_2394 ) ;
}
}
static void F_636 ( struct V_4 * V_5 )
{
T_1 V_7 ;
bool V_2542 = false ;
if ( V_5 -> V_2020 [ 0 ] != 0 )
V_2542 = true ;
if ( F_23 ( V_5 , V_681 ) ) {
strcat ( V_5 -> V_2020 , L_104 ) ;
F_634 ( V_5 ) ;
return;
}
if ( F_168 ( V_5 , 0 , & V_7 ) )
return;
if ( V_7 == V_1984 )
F_628 ( V_5 ) ;
else if ( ( V_7 & V_2091 ) == V_2092 )
F_630 ( V_5 , V_7 ) ;
else if ( ( V_7 & V_2108 ) == V_2109 )
F_629 ( V_5 ) ;
if ( F_23 ( V_5 , V_308 ) ) {
if ( F_23 ( V_5 , V_60 ) ) {
F_632 ( V_5 ) ;
if ( ! V_2542 )
F_633 ( V_5 ) ;
} else if ( ! V_2542 ) {
F_631 ( V_5 ) ;
}
}
V_5 -> V_2020 [ V_2502 - 1 ] = 0 ;
}
static inline T_1 F_637 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , V_1719 ) )
return V_2543 ;
else if ( F_23 ( V_5 , V_521 ) && ! F_23 ( V_5 , 5780_CLASS ) )
return V_2544 ;
else
return V_2545 ;
}
static struct V_1791 * F_638 ( struct V_4 * V_5 )
{
struct V_1791 * V_2546 ;
unsigned int V_2547 , V_2548 = V_5 -> V_12 -> V_274 & ~ 7 ;
for ( V_2547 = 0 ; V_2547 < 8 ; V_2547 ++ ) {
V_2546 = F_639 ( V_5 -> V_12 -> V_272 , V_2548 | V_2547 ) ;
if ( V_2546 && V_2546 != V_5 -> V_12 )
break;
F_640 ( V_2546 ) ;
}
if ( ! V_2546 ) {
V_2546 = V_5 -> V_12 ;
return V_2546 ;
}
F_640 ( V_2546 ) ;
return V_2546 ;
}
static void F_641 ( struct V_4 * V_5 , T_1 V_2549 )
{
V_5 -> V_2550 = V_2549 >> V_2551 ;
if ( F_30 ( V_5 ) == V_2552 ) {
T_1 V_161 ;
F_83 ( V_5 , V_152 ) ;
if ( V_5 -> V_12 -> V_543 == V_2481 ||
V_5 -> V_12 -> V_543 == V_2482 ||
V_5 -> V_12 -> V_543 == V_2483 ||
V_5 -> V_12 -> V_543 == V_2553 ||
V_5 -> V_12 -> V_543 == V_2554 ||
V_5 -> V_12 -> V_543 == V_2555 ||
V_5 -> V_12 -> V_543 == V_2556 ||
V_5 -> V_12 -> V_543 == V_2557 ||
V_5 -> V_12 -> V_543 == V_2532 ||
V_5 -> V_12 -> V_543 == V_2558 ||
V_5 -> V_12 -> V_543 == V_2559 )
V_161 = V_2560 ;
else if ( V_5 -> V_12 -> V_543 == V_2491 ||
V_5 -> V_12 -> V_543 == V_2492 ||
V_5 -> V_12 -> V_543 == V_2489 ||
V_5 -> V_12 -> V_543 == V_2490 ||
V_5 -> V_12 -> V_543 == V_2493 ||
V_5 -> V_12 -> V_543 == V_2494 ||
V_5 -> V_12 -> V_543 == V_2495 ||
V_5 -> V_12 -> V_543 == V_2496 ||
V_5 -> V_12 -> V_543 == V_2497 ||
V_5 -> V_12 -> V_543 == V_2498 )
V_161 = V_2561 ;
else
V_161 = V_2562 ;
F_19 ( V_5 -> V_12 , V_161 , & V_5 -> V_2550 ) ;
}
if ( F_76 ( V_5 ) == V_2563 )
V_5 -> V_2550 = V_2564 ;
if ( F_76 ( V_5 ) == V_2565 )
V_5 -> V_2550 = V_1619 ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 )
F_83 ( V_5 , 5717_PLUS ) ;
if ( F_30 ( V_5 ) == V_765 ||
F_30 ( V_5 ) == V_667 )
F_83 ( V_5 , 57765_CLASS ) ;
if ( F_23 ( V_5 , 57765_CLASS ) || F_23 ( V_5 , 5717_PLUS ) ||
F_30 ( V_5 ) == V_767 )
F_83 ( V_5 , 57765_PLUS ) ;
if ( F_30 ( V_5 ) == V_1494 ||
F_30 ( V_5 ) == V_1507 ||
F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_45 ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1411 ||
F_23 ( V_5 , 57765_PLUS ) )
F_83 ( V_5 , 5755_PLUS ) ;
if ( F_30 ( V_5 ) == V_566 ||
F_30 ( V_5 ) == V_548 )
F_83 ( V_5 , 5780_CLASS ) ;
if ( F_30 ( V_5 ) == V_1505 ||
F_30 ( V_5 ) == V_640 ||
F_30 ( V_5 ) == V_36 ||
F_23 ( V_5 , 5755_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) )
F_83 ( V_5 , 5750_PLUS ) ;
if ( F_30 ( V_5 ) == V_501 ||
F_23 ( V_5 , 5750_PLUS ) )
F_83 ( V_5 , 5705_PLUS ) ;
}
static bool F_642 ( struct V_4 * V_5 ,
const struct V_2566 * V_2567 )
{
T_1 V_2568 = F_33 ( V_497 ) & V_2569 ;
if ( ( F_30 ( V_5 ) == V_499 &&
( V_2568 == 0x8000 || V_2568 == 0x4000 ) ) ||
( V_5 -> V_178 & V_179 ) )
return true ;
if ( V_2567 -> V_2570 & V_2571 ) {
if ( F_30 ( V_5 ) == V_501 ) {
if ( V_2567 -> V_2570 & V_2572 )
return true ;
} else {
return true ;
}
}
return false ;
}
static int F_643 ( struct V_4 * V_5 , const struct V_2566 * V_2567 )
{
T_1 V_2549 ;
T_1 V_2573 , V_2568 ;
T_1 V_7 ;
T_3 V_1385 ;
int V_75 ;
F_421 ( V_5 -> V_12 , V_1384 , & V_1385 ) ;
V_1385 &= ~ V_2574 ;
F_423 ( V_5 -> V_12 , V_1384 , V_1385 ) ;
F_19 ( V_5 -> V_12 , V_119 ,
& V_2549 ) ;
V_5 -> V_120 |= ( V_2549 &
V_2575 ) ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
F_641 ( V_5 , V_2549 ) ;
if ( ( F_76 ( V_5 ) == V_1738 ) ||
( F_76 ( V_5 ) == V_2576 ) ) {
static struct V_2577 {
T_1 V_2578 ;
T_1 V_543 ;
T_1 V_2579 ;
} V_2580 [] = {
{ V_2581 , V_2582 ,
V_2583 } ,
{ V_2581 , V_2584 ,
V_2583 } ,
{ V_2581 , V_2585 ,
0xa } ,
{ V_2581 , V_2586 ,
V_2583 } ,
{ } ,
} ;
struct V_2577 * V_2587 = & V_2580 [ 0 ] ;
struct V_1791 * V_2588 = NULL ;
while ( V_2587 -> V_2578 != 0 ) {
V_2588 = F_644 ( V_2587 -> V_2578 , V_2587 -> V_543 ,
V_2588 ) ;
if ( ! V_2588 ) {
V_2587 ++ ;
continue;
}
if ( V_2587 -> V_2579 != V_2583 ) {
if ( V_2588 -> V_2589 > V_2587 -> V_2579 )
continue;
}
if ( V_2588 -> V_2590 &&
( V_2588 -> V_2590 -> V_273 ==
V_5 -> V_12 -> V_272 -> V_273 ) ) {
F_83 ( V_5 , V_26 ) ;
F_640 ( V_2588 ) ;
break;
}
}
}
if ( F_30 ( V_5 ) == V_537 ) {
static struct V_2577 {
T_1 V_2578 ;
T_1 V_543 ;
} V_2591 [] = {
{ V_2581 , V_2592 } ,
{ V_2581 , V_2593 } ,
{ } ,
} ;
struct V_2577 * V_2587 = & V_2591 [ 0 ] ;
struct V_1791 * V_2588 = NULL ;
while ( V_2587 -> V_2578 != 0 ) {
V_2588 = F_644 ( V_2587 -> V_2578 ,
V_2587 -> V_543 ,
V_2588 ) ;
if ( ! V_2588 ) {
V_2587 ++ ;
continue;
}
if ( V_2588 -> V_2590 &&
( V_2588 -> V_2590 -> V_273 <=
V_5 -> V_12 -> V_272 -> V_273 ) &&
( V_2588 -> V_2590 -> V_2594 . V_1989 >=
V_5 -> V_12 -> V_272 -> V_273 ) ) {
F_83 ( V_5 , 5701_DMA_BUG ) ;
F_640 ( V_2588 ) ;
break;
}
}
}
if ( F_23 ( V_5 , 5780_CLASS ) ) {
F_83 ( V_5 , 40BIT_DMA_BUG ) ;
V_5 -> V_1402 = V_5 -> V_12 -> V_1402 ;
} else {
struct V_1791 * V_2588 = NULL ;
do {
V_2588 = F_644 ( V_2595 ,
V_2596 ,
V_2588 ) ;
if ( V_2588 && V_2588 -> V_2590 &&
( V_2588 -> V_2590 -> V_273 <=
V_5 -> V_12 -> V_272 -> V_273 ) &&
( V_2588 -> V_2590 -> V_2594 . V_1989 >=
V_5 -> V_12 -> V_272 -> V_273 ) ) {
F_83 ( V_5 , 40BIT_DMA_BUG ) ;
F_640 ( V_2588 ) ;
break;
}
} while ( V_2588 );
}
if ( F_30 ( V_5 ) == V_500 ||
F_30 ( V_5 ) == V_548 )
V_5 -> V_559 = F_638 ( V_5 ) ;
if ( F_76 ( V_5 ) == V_1618 )
;
else if ( F_23 ( V_5 , 57765_PLUS ) )
F_83 ( V_5 , V_1300 ) ;
else if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_83 ( V_5 , V_1299 ) ;
else if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_83 ( V_5 , V_1298 ) ;
F_83 ( V_5 , V_1293 ) ;
if ( F_30 ( V_5 ) == V_1505 &&
F_76 ( V_5 ) >= V_2597 )
F_85 ( V_5 , V_1293 ) ;
} else if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 &&
F_76 ( V_5 ) != V_1434 ) {
F_83 ( V_5 , V_683 ) ;
F_83 ( V_5 , V_1293 ) ;
if ( F_30 ( V_5 ) == V_501 )
V_5 -> V_1891 = V_2598 ;
else
V_5 -> V_1891 = V_2599 ;
}
if ( F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ||
F_23 ( V_5 , V_1300 ) ||
F_23 ( V_5 , V_683 ) ) {
F_83 ( V_5 , V_1600 ) ;
} else {
F_85 ( V_5 , V_1600 ) ;
F_85 ( V_5 , V_1293 ) ;
V_5 -> V_1891 = NULL ;
}
if ( F_76 ( V_5 ) == V_759 )
V_5 -> V_1891 = V_2600 ;
if ( F_30 ( V_5 ) == V_667 )
V_5 -> V_1891 = V_2601 ;
V_5 -> V_122 = 1 ;
if ( F_23 ( V_5 , 5750_PLUS ) ) {
F_83 ( V_5 , V_1901 ) ;
if ( F_145 ( V_5 ) == V_741 ||
F_145 ( V_5 ) == V_742 ||
( F_30 ( V_5 ) == V_548 &&
F_76 ( V_5 ) <= V_2602 &&
V_5 -> V_559 == V_5 -> V_12 ) )
F_85 ( V_5 , V_1901 ) ;
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 ) {
F_83 ( V_5 , 1SHOT_MSI ) ;
}
if ( F_23 ( V_5 , 57765_PLUS ) ) {
F_83 ( V_5 , V_1061 ) ;
V_5 -> V_122 = V_1895 ;
}
}
V_5 -> V_1900 = 1 ;
V_5 -> V_1898 = 1 ;
if ( V_5 -> V_122 > 1 ) {
V_5 -> V_1898 = V_2050 ;
F_456 ( V_5 , V_2050 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 )
V_5 -> V_1900 = V_5 -> V_122 - 1 ;
}
if ( F_23 ( V_5 , 5755_PLUS ) ||
F_30 ( V_5 ) == V_36 )
F_83 ( V_5 , V_1256 ) ;
if ( F_30 ( V_5 ) == V_477 )
V_5 -> V_1257 = V_2603 ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_767 )
F_83 ( V_5 , V_1719 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) &&
F_76 ( V_5 ) != V_1618 )
F_83 ( V_5 , V_1308 ) ;
if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ||
F_23 ( V_5 , V_1308 ) )
F_83 ( V_5 , V_521 ) ;
F_19 ( V_5 -> V_12 , V_1241 ,
& V_2573 ) ;
if ( F_429 ( V_5 -> V_12 ) ) {
T_3 V_2604 ;
F_83 ( V_5 , V_1079 ) ;
F_645 ( V_5 -> V_12 , V_700 , & V_2604 ) ;
if ( V_2604 & V_701 ) {
if ( F_30 ( V_5 ) == V_36 ) {
F_85 ( V_5 , V_1299 ) ;
F_85 ( V_5 , V_1600 ) ;
}
if ( F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_45 ||
F_76 ( V_5 ) == V_2605 ||
F_76 ( V_5 ) == V_2606 )
F_83 ( V_5 , V_699 ) ;
} else if ( F_76 ( V_5 ) == V_259 ) {
F_83 ( V_5 , V_1559 ) ;
}
} else if ( F_30 ( V_5 ) == V_257 ) {
F_83 ( V_5 , V_1079 ) ;
} else if ( ! F_23 ( V_5 , 5705_PLUS ) ||
F_23 ( V_5 , 5780_CLASS ) ) {
V_5 -> V_1397 = F_646 ( V_5 -> V_12 , V_2607 ) ;
if ( ! V_5 -> V_1397 ) {
F_116 ( & V_5 -> V_12 -> V_111 ,
L_111 ) ;
return - V_210 ;
}
if ( ! ( V_2573 & V_2608 ) )
F_83 ( V_5 , V_841 ) ;
}
if ( F_647 ( V_2609 ) &&
! F_23 ( V_5 , V_1079 ) )
F_83 ( V_5 , V_31 ) ;
F_648 ( V_5 -> V_12 , V_1392 ,
& V_5 -> V_1393 ) ;
F_648 ( V_5 -> V_12 , V_1394 ,
& V_5 -> V_1395 ) ;
if ( F_30 ( V_5 ) == V_499 &&
V_5 -> V_1395 < 64 ) {
V_5 -> V_1395 = 64 ;
F_424 ( V_5 -> V_12 , V_1394 ,
V_5 -> V_1395 ) ;
}
if ( F_145 ( V_5 ) == V_2610 ) {
F_83 ( V_5 , V_34 ) ;
if ( F_23 ( V_5 , V_841 ) ) {
T_1 V_2611 ;
F_83 ( V_5 , V_25 ) ;
F_19 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2612 + V_2613 ,
& V_2611 ) ;
V_2611 &= ~ V_2614 ;
V_2611 |= V_2615 | 0 ;
F_15 ( V_5 -> V_12 ,
V_5 -> V_12 -> V_2612 + V_2613 ,
V_2611 ) ;
F_421 ( V_5 -> V_12 , V_1384 , & V_1385 ) ;
V_1385 |= V_2616 | V_1890 ;
F_423 ( V_5 -> V_12 , V_1384 , V_1385 ) ;
}
}
if ( ( V_2573 & V_1647 ) != 0 )
F_83 ( V_5 , V_842 ) ;
if ( ( V_2573 & V_2617 ) != 0 )
F_83 ( V_5 , V_2618 ) ;
if ( ( F_76 ( V_5 ) == V_918 ) &&
( ! ( V_2573 & V_1388 ) ) ) {
V_2573 |= V_1388 ;
F_15 ( V_5 -> V_12 , V_1241 , V_2573 ) ;
}
V_5 -> V_28 = F_9 ;
V_5 -> V_27 = F_7 ;
V_5 -> V_32 = F_9 ;
V_5 -> V_29 = F_7 ;
V_5 -> V_1094 = F_7 ;
V_5 -> V_1883 = F_7 ;
if ( F_23 ( V_5 , V_25 ) )
V_5 -> V_27 = F_13 ;
else if ( F_30 ( V_5 ) == V_537 ||
( F_23 ( V_5 , V_1079 ) &&
F_76 ( V_5 ) == V_1419 ) ) {
V_5 -> V_27 = F_17 ;
}
if ( F_23 ( V_5 , V_34 ) || F_23 ( V_5 , V_31 ) ) {
V_5 -> V_1094 = F_26 ;
if ( F_23 ( V_5 , V_31 ) )
V_5 -> V_1883 = F_17 ;
}
if ( F_23 ( V_5 , V_26 ) ) {
V_5 -> V_28 = F_18 ;
V_5 -> V_27 = F_13 ;
V_5 -> V_32 = F_21 ;
V_5 -> V_29 = F_20 ;
V_5 -> V_1094 = F_20 ;
V_5 -> V_1883 = F_20 ;
F_649 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
F_421 ( V_5 -> V_12 , V_1384 , & V_1385 ) ;
V_1385 &= ~ V_2619 ;
F_423 ( V_5 -> V_12 , V_1384 , V_1385 ) ;
}
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_32 = F_27 ;
V_5 -> V_29 = F_28 ;
V_5 -> V_1094 = F_28 ;
V_5 -> V_1883 = F_28 ;
}
if ( V_5 -> V_27 == F_13 ||
( F_23 ( V_5 , V_841 ) &&
( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) ) )
F_83 ( V_5 , V_39 ) ;
V_7 = F_33 ( V_1063 ) ;
F_46 ( V_1063 , V_7 | V_1383 ) ;
V_5 -> V_54 = F_650 ( V_5 -> V_12 -> V_274 ) & 3 ;
if ( F_30 ( V_5 ) == V_500 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_23 ( V_5 , V_841 ) ) {
F_19 ( V_5 -> V_12 ,
V_5 -> V_1397 + V_2620 ,
& V_7 ) ;
V_5 -> V_54 = V_7 & 0x7 ;
}
} else if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ) {
F_32 ( V_5 , V_2621 , & V_7 ) ;
if ( ( V_7 & V_2622 ) != V_2623 )
V_7 = F_33 ( V_1868 ) ;
if ( F_30 ( V_5 ) == V_476 )
V_5 -> V_54 = ( V_7 & V_2624 ) ? 1 : 0 ;
else
V_5 -> V_54 = ( V_7 & V_2625 ) >>
V_2626 ;
}
if ( F_23 ( V_5 , V_30 ) ) {
V_5 -> V_1094 = F_17 ;
V_5 -> V_1883 = F_17 ;
}
F_617 ( V_5 ) ;
if ( F_23 ( V_5 , V_683 ) && F_23 ( V_5 , V_308 ) ) {
F_85 ( V_5 , V_1600 ) ;
F_85 ( V_5 , V_1293 ) ;
V_5 -> V_1891 = NULL ;
}
if ( F_23 ( V_5 , V_60 ) ) {
V_2573 |= V_1389 |
V_1390 |
V_1391 ;
F_15 ( V_5 -> V_12 , V_1241 ,
V_2573 ) ;
F_34 ( V_5 ) ;
}
V_5 -> V_22 = V_2627 | V_2376 ;
if ( F_30 ( V_5 ) == V_536 ||
F_23 ( V_5 , V_643 ) )
V_5 -> V_22 |= ( V_538 |
V_539 ) ;
else if ( F_30 ( V_5 ) == V_640 )
V_5 -> V_22 |= V_549 ;
if ( F_30 ( V_5 ) == V_1494 ||
F_30 ( V_5 ) == V_1411 ||
F_23 ( V_5 , 57765_CLASS ) )
V_5 -> V_22 |= V_1692 ;
if ( V_5 -> V_12 -> V_543 == V_544 ||
V_5 -> V_12 -> V_543 == V_545 ) {
V_5 -> V_22 |= V_1692 ;
if ( F_23 ( V_5 , V_532 ) )
V_5 -> V_22 |= V_540 |
V_542 ;
}
if ( F_30 ( V_5 ) == V_767 )
V_5 -> V_22 |=
F_33 ( V_136 ) & V_1692 ;
F_147 ( V_5 ) ;
if ( V_5 -> V_111 -> V_1198 > V_1333 && ! F_23 ( V_5 , 5780_CLASS ) )
F_83 ( V_5 , V_1345 ) ;
if ( F_30 ( V_5 ) == V_536 ||
F_76 ( V_5 ) == V_759 ||
F_76 ( V_5 ) == V_760 ||
F_76 ( V_5 ) == V_2628 ) {
F_85 ( V_5 , V_707 ) ;
} else {
F_83 ( V_5 , V_707 ) ;
}
if ( F_30 ( V_5 ) == V_36 )
V_5 -> V_178 |= V_179 ;
if ( F_30 ( V_5 ) == V_536 ||
( F_30 ( V_5 ) == V_501 &&
( F_76 ( V_5 ) != V_1434 ) &&
( F_76 ( V_5 ) != V_1704 ) ) ||
( V_5 -> V_178 & V_179 ) ||
( V_5 -> V_178 & V_359 ) )
V_5 -> V_178 |= V_423 ;
if ( F_145 ( V_5 ) == V_2629 ||
F_145 ( V_5 ) == V_2630 )
V_5 -> V_178 |= V_514 ;
if ( F_76 ( V_5 ) == V_918 )
V_5 -> V_178 |= V_515 ;
if ( F_23 ( V_5 , 5705_PLUS ) &&
! ( V_5 -> V_178 & V_179 ) &&
F_30 ( V_5 ) != V_257 &&
F_30 ( V_5 ) != V_1411 &&
! F_23 ( V_5 , 57765_PLUS ) ) {
if ( F_30 ( V_5 ) == V_1494 ||
F_30 ( V_5 ) == V_1507 ||
F_30 ( V_5 ) == V_413 ||
F_30 ( V_5 ) == V_45 ) {
if ( V_5 -> V_12 -> V_543 != V_2631 &&
V_5 -> V_12 -> V_543 != V_2632 )
V_5 -> V_178 |= V_517 ;
if ( V_5 -> V_12 -> V_543 == V_2633 )
V_5 -> V_178 |= V_518 ;
} else
V_5 -> V_178 |= V_516 ;
}
if ( F_30 ( V_5 ) == V_413 &&
F_145 ( V_5 ) != V_503 ) {
V_5 -> V_426 = F_621 ( V_5 ) ;
if ( V_5 -> V_426 == 0 )
V_5 -> V_426 = V_2634 ;
}
if ( F_23 ( V_5 , V_152 ) )
V_5 -> V_164 = V_2635 ;
else
V_5 -> V_164 = V_2636 ;
V_5 -> V_127 = 0 ;
if ( F_145 ( V_5 ) != V_2637 &&
F_145 ( V_5 ) != V_2610 )
V_5 -> V_127 |= V_2638 ;
if ( F_30 ( V_5 ) == V_476 ||
F_30 ( V_5 ) == V_767 ||
F_76 ( V_5 ) == V_1618 ||
F_76 ( V_5 ) == V_1619 ) {
V_5 -> V_127 |= V_2639 ;
V_5 -> V_644 |= V_2640 ;
}
if ( F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1411 )
F_83 ( V_5 , V_267 ) ;
V_75 = F_75 ( V_5 ) ;
if ( V_75 )
return V_75 ;
V_7 = F_33 ( V_646 ) ;
if ( F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_767 )
V_7 &= ( V_2641 |
V_2642 |
V_2643 |
V_2644 |
V_1586 ) ;
else
V_7 &= V_1586 ;
F_46 ( V_646 , V_7 | V_5 -> V_644 ) ;
F_54 ( V_5 ) ;
F_46 ( V_40 , 0 ) ;
F_46 ( V_13 , 0 ) ;
F_19 ( V_5 -> V_12 , V_1241 ,
& V_2573 ) ;
if ( ( V_2573 & V_2608 ) == 0 &&
! F_23 ( V_5 , V_25 ) ) {
if ( F_76 ( V_5 ) == V_759 ||
F_76 ( V_5 ) == V_760 ||
F_76 ( V_5 ) == V_2628 ||
F_76 ( V_5 ) == V_2645 ) {
void T_2 * V_2646 ;
V_2646 = V_5 -> V_8 + V_2647 + V_37 ;
F_8 ( 0x00000000 , V_2646 ) ;
F_8 ( 0x00000000 , V_2646 + 4 ) ;
F_8 ( 0xffffffff , V_2646 + 4 ) ;
if ( F_10 ( V_2646 ) != 0x00000000 )
F_83 ( V_5 , V_25 ) ;
}
}
F_24 ( 50 ) ;
F_615 ( V_5 ) ;
if ( F_30 ( V_5 ) == V_667 &&
! F_23 ( V_5 , V_681 ) )
V_5 -> V_1891 = NULL ;
V_2568 = F_33 ( V_497 ) ;
V_2568 &= V_2569 ;
if ( F_30 ( V_5 ) == V_501 &&
( V_2568 == V_2648 ||
V_2568 == V_2649 ) )
F_83 ( V_5 , V_1648 ) ;
if ( ! F_23 ( V_5 , V_1648 ) &&
F_30 ( V_5 ) != V_536 )
F_83 ( V_5 , V_133 ) ;
if ( F_23 ( V_5 , V_133 ) ) {
V_5 -> V_127 |= ( V_2650 |
V_2651 ) ;
V_5 -> V_120 |= V_2652 ;
F_15 ( V_5 -> V_12 , V_119 ,
V_5 -> V_120 ) ;
}
if ( F_23 ( V_5 , V_60 ) )
V_5 -> V_367 = V_730 | V_731 ;
else
V_5 -> V_367 = 0 ;
if ( F_642 ( V_5 , V_2567 ) )
V_5 -> V_178 |= V_392 ;
V_75 = F_623 ( V_5 ) ;
if ( V_75 ) {
F_116 ( & V_5 -> V_12 -> V_111 , L_112 , V_75 ) ;
F_84 ( V_5 ) ;
}
F_625 ( V_5 ) ;
F_636 ( V_5 ) ;
if ( V_5 -> V_178 & V_567 ) {
V_5 -> V_178 &= ~ V_818 ;
} else {
if ( F_30 ( V_5 ) == V_536 )
V_5 -> V_178 |= V_818 ;
else
V_5 -> V_178 &= ~ V_818 ;
}
if ( F_30 ( V_5 ) == V_536 )
F_83 ( V_5 , V_142 ) ;
else
F_85 ( V_5 , V_142 ) ;
if ( V_5 -> V_12 -> V_2380 == V_2424 &&
F_30 ( V_5 ) == V_537 &&
! ( V_5 -> V_178 & V_567 ) ) {
V_5 -> V_178 |= V_818 ;
F_83 ( V_5 , V_142 ) ;
}
if ( V_5 -> V_178 & V_567 )
F_83 ( V_5 , V_143 ) ;
else
F_85 ( V_5 , V_143 ) ;
if ( F_23 ( V_5 , V_60 ) && F_23 ( V_5 , V_308 ) )
F_83 ( V_5 , V_1866 ) ;
V_5 -> V_2653 = V_2654 + V_2655 ;
V_5 -> V_2656 = V_2657 ;
if ( F_30 ( V_5 ) == V_537 &&
F_23 ( V_5 , V_841 ) ) {
V_5 -> V_2653 = V_2654 ;
#ifndef F_651
V_5 -> V_2656 = ~ ( T_3 ) 0 ;
#endif
}
V_5 -> V_1138 = F_463 ( V_5 ) - 1 ;
V_5 -> V_1143 = F_462 ( V_5 ) - 1 ;
V_5 -> V_1206 = F_637 ( V_5 ) - 1 ;
V_5 -> V_1205 = V_5 -> V_1138 + 1 ;
if ( F_30 ( V_5 ) == V_1505 ||
F_30 ( V_5 ) == V_640 ||
F_30 ( V_5 ) == V_1494 )
V_5 -> V_1205 = 8 ;
if ( F_23 ( V_5 , V_974 ) )
V_5 -> V_977 = F_33 ( V_975 ) &
V_976 ;
return V_75 ;
}
static int F_652 ( struct V_4 * V_5 )
{
struct V_364 * V_111 = V_5 -> V_111 ;
struct V_1791 * V_12 = V_5 -> V_12 ;
struct V_2658 * V_2027 = F_653 ( V_12 ) ;
const unsigned char * V_184 ;
int V_74 ;
V_184 = F_654 ( V_2027 , L_113 , & V_74 ) ;
if ( V_184 && V_74 == V_1531 ) {
memcpy ( V_111 -> V_694 , V_184 , V_1531 ) ;
return 0 ;
}
return - V_82 ;
}
static int F_655 ( struct V_4 * V_5 )
{
struct V_364 * V_111 = V_5 -> V_111 ;
memcpy ( V_111 -> V_694 , V_2659 -> V_2660 , V_1531 ) ;
return 0 ;
}
static int F_656 ( struct V_4 * V_5 )
{
struct V_364 * V_111 = V_5 -> V_111 ;
T_1 V_2661 , V_2662 , V_2663 ;
int V_2664 = 0 ;
int V_75 ;
#ifdef F_657
if ( ! F_652 ( V_5 ) )
return 0 ;
#endif
if ( F_23 ( V_5 , V_264 ) ) {
V_75 = F_658 ( V_5 -> V_12 , & V_111 -> V_694 [ 0 ] ) ;
if ( ! V_75 && F_435 ( & V_111 -> V_694 [ 0 ] ) )
return 0 ;
}
V_2663 = 0x7c ;
if ( F_30 ( V_5 ) == V_500 ||
F_23 ( V_5 , 5780_CLASS ) ) {
if ( F_33 ( V_920 ) & V_921 )
V_2663 = 0xcc ;
if ( F_157 ( V_5 ) )
F_31 ( V_607 , V_2665 ) ;
else
F_158 ( V_5 ) ;
} else if ( F_23 ( V_5 , 5717_PLUS ) ) {
if ( V_5 -> V_54 & 1 )
V_2663 = 0xcc ;
if ( V_5 -> V_54 > 1 )
V_2663 += 0x18c ;
} else if ( F_30 ( V_5 ) == V_36 )
V_2663 = 0x10 ;
F_32 ( V_5 , V_2666 , & V_2661 ) ;
if ( ( V_2661 >> 16 ) == 0x484b ) {
V_111 -> V_694 [ 0 ] = ( V_2661 >> 8 ) & 0xff ;
V_111 -> V_694 [ 1 ] = ( V_2661 >> 0 ) & 0xff ;
F_32 ( V_5 , V_2667 , & V_2662 ) ;
V_111 -> V_694 [ 2 ] = ( V_2662 >> 24 ) & 0xff ;
V_111 -> V_694 [ 3 ] = ( V_2662 >> 16 ) & 0xff ;
V_111 -> V_694 [ 4 ] = ( V_2662 >> 8 ) & 0xff ;
V_111 -> V_694 [ 5 ] = ( V_2662 >> 0 ) & 0xff ;
V_2664 = F_435 ( & V_111 -> V_694 [ 0 ] ) ;
}
if ( ! V_2664 ) {
if ( ! F_23 ( V_5 , V_681 ) &&
! F_169 ( V_5 , V_2663 + 0 , & V_2661 ) &&
! F_169 ( V_5 , V_2663 + 4 , & V_2662 ) ) {
memcpy ( & V_111 -> V_694 [ 0 ] , ( ( char * ) & V_2661 ) + 2 , 2 ) ;
memcpy ( & V_111 -> V_694 [ 2 ] , ( char * ) & V_2662 , sizeof( V_2662 ) ) ;
}
else {
V_2661 = F_33 ( V_689 ) ;
V_2662 = F_33 ( V_690 ) ;
V_111 -> V_694 [ 5 ] = V_2662 & 0xff ;
V_111 -> V_694 [ 4 ] = ( V_2662 >> 8 ) & 0xff ;
V_111 -> V_694 [ 3 ] = ( V_2662 >> 16 ) & 0xff ;
V_111 -> V_694 [ 2 ] = ( V_2662 >> 24 ) & 0xff ;
V_111 -> V_694 [ 1 ] = V_2661 & 0xff ;
V_111 -> V_694 [ 0 ] = ( V_2661 >> 8 ) & 0xff ;
}
}
if ( ! F_435 ( & V_111 -> V_694 [ 0 ] ) ) {
#ifdef F_657
if ( ! F_655 ( V_5 ) )
return 0 ;
#endif
return - V_64 ;
}
return 0 ;
}
static T_1 F_659 ( struct V_4 * V_5 , T_1 V_7 )
{
int V_2668 ;
T_4 V_2669 ;
int V_2670 ;
F_648 ( V_5 -> V_12 , V_1392 , & V_2669 ) ;
if ( V_2669 == 0 )
V_2668 = 1024 ;
else
V_2668 = ( int ) V_2669 * 4 ;
if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 &&
! F_23 ( V_5 , V_1079 ) )
goto V_502;
#if F_359 ( V_2671 ) || F_359 ( V_2672 ) || F_359 ( V_2673 )
V_2670 = V_2674 ;
#else
#if F_359 ( V_2675 ) || F_359 ( V_2676 )
V_2670 = V_2677 ;
#else
V_2670 = 0 ;
#endif
#endif
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_7 = V_2670 ? 0 : V_1577 ;
goto V_502;
}
if ( ! V_2670 )
goto V_502;
if ( F_23 ( V_5 , V_841 ) && ! F_23 ( V_5 , V_1079 ) ) {
switch ( V_2668 ) {
case 16 :
case 32 :
case 64 :
case 128 :
if ( V_2670 == V_2677 ) {
V_7 |= ( V_2678 |
V_2679 ) ;
} else {
V_7 |= ( V_2680 |
V_2681 ) ;
}
break;
case 256 :
V_7 |= ( V_2682 |
V_2683 ) ;
break;
default:
V_7 |= ( V_2680 |
V_2681 ) ;
break;
}
} else if ( F_23 ( V_5 , V_1079 ) ) {
switch ( V_2668 ) {
case 16 :
case 32 :
case 64 :
if ( V_2670 == V_2677 ) {
V_7 &= ~ V_2684 ;
V_7 |= V_2685 ;
break;
}
case 128 :
default:
V_7 &= ~ V_2684 ;
V_7 |= V_2686 ;
break;
}
} else {
switch ( V_2668 ) {
case 16 :
if ( V_2670 == V_2677 ) {
V_7 |= ( V_2687 |
V_2688 ) ;
break;
}
case 32 :
if ( V_2670 == V_2677 ) {
V_7 |= ( V_2689 |
V_2690 ) ;
break;
}
case 64 :
if ( V_2670 == V_2677 ) {
V_7 |= ( V_2691 |
V_2692 ) ;
break;
}
case 128 :
if ( V_2670 == V_2677 ) {
V_7 |= ( V_2693 |
V_2694 ) ;
break;
}
case 256 :
V_7 |= ( V_2695 |
V_2696 ) ;
break;
case 512 :
V_7 |= ( V_2697 |
V_2698 ) ;
break;
case 1024 :
default:
V_7 |= ( V_2699 |
V_2700 ) ;
break;
}
}
V_502:
return V_7 ;
}
static int F_660 ( struct V_4 * V_5 , T_1 * V_626 , T_9 V_2701 ,
int V_634 , bool V_2702 )
{
struct V_2703 V_2704 ;
T_1 V_2705 ;
int V_42 , V_56 ;
V_2705 = V_1597 ;
F_46 ( V_2706 , 0 ) ;
F_46 ( V_2707 , 0 ) ;
F_46 ( V_1232 , 0 ) ;
F_46 ( V_1233 , 0 ) ;
F_46 ( V_1064 , 0 ) ;
F_46 ( V_1074 , 0 ) ;
V_2704 . V_1148 = ( ( T_6 ) V_2701 ) >> 32 ;
V_2704 . V_1149 = V_2701 & 0xffffffff ;
V_2704 . V_2708 = 0x00002100 ;
V_2704 . V_74 = V_634 ;
if ( V_2702 ) {
V_2704 . V_2709 = ( 13 << 8 ) | 2 ;
F_31 ( V_1065 , V_1376 ) ;
F_24 ( 40 ) ;
} else {
V_2704 . V_2709 = ( 16 << 8 ) | 7 ;
F_31 ( V_1066 , V_1380 ) ;
F_24 ( 40 ) ;
}
V_2704 . V_10 = 0x00000005 ;
for ( V_42 = 0 ; V_42 < ( sizeof( V_2704 ) / sizeof( T_1 ) ) ; V_42 ++ ) {
T_1 V_7 ;
V_7 = * ( ( ( T_1 * ) & V_2704 ) + V_42 ) ;
F_15 ( V_5 -> V_12 , V_40 ,
V_2705 + ( V_42 * sizeof( T_1 ) ) ) ;
F_15 ( V_5 -> V_12 , V_41 , V_7 ) ;
}
F_15 ( V_5 -> V_12 , V_40 , 0 ) ;
if ( V_2702 )
F_46 ( V_2710 , V_2705 ) ;
else
F_46 ( V_2711 , V_2705 ) ;
V_56 = - V_82 ;
for ( V_42 = 0 ; V_42 < 40 ; V_42 ++ ) {
T_1 V_7 ;
if ( V_2702 )
V_7 = F_33 ( V_2706 ) ;
else
V_7 = F_33 ( V_2707 ) ;
if ( ( V_7 & 0xffff ) == V_2705 ) {
V_56 = 0 ;
break;
}
F_24 ( 100 ) ;
}
return V_56 ;
}
static int F_661 ( struct V_4 * V_5 )
{
T_9 V_2701 ;
T_1 * V_626 , V_2712 ;
int V_56 = 0 ;
V_626 = F_406 ( & V_5 -> V_12 -> V_111 , V_2713 ,
& V_2701 , V_632 ) ;
if ( ! V_626 ) {
V_56 = - V_268 ;
goto V_2714;
}
V_5 -> V_1580 = ( ( 0x7 << V_2715 ) |
( 0x6 << V_2716 ) ) ;
V_5 -> V_1580 = F_659 ( V_5 , V_5 -> V_1580 ) ;
if ( F_23 ( V_5 , 57765_PLUS ) )
goto V_502;
if ( F_23 ( V_5 , V_1079 ) ) {
V_5 -> V_1580 |= 0x00180000 ;
} else if ( ! F_23 ( V_5 , V_841 ) ) {
if ( F_30 ( V_5 ) == V_501 ||
F_30 ( V_5 ) == V_1505 )
V_5 -> V_1580 |= 0x003f0000 ;
else
V_5 -> V_1580 |= 0x003f000f ;
} else {
if ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 ) {
T_1 V_2717 = ( F_33 ( V_153 ) & 0x1f ) ;
T_1 V_2718 = 0x7 ;
if ( F_23 ( V_5 , 40BIT_DMA_BUG ) &&
F_30 ( V_5 ) == V_500 )
V_5 -> V_1580 |= 0x8000 ;
else if ( V_2717 == 0x6 || V_2717 == 0x7 )
V_5 -> V_1580 |= V_2719 ;
if ( F_30 ( V_5 ) == V_499 )
V_2718 = 4 ;
V_5 -> V_1580 |=
( V_2718 << V_2720 ) |
( 0x3 << V_2721 ) |
( 1 << 23 ) ;
} else if ( F_30 ( V_5 ) == V_566 ) {
V_5 -> V_1580 |= 0x00144000 ;
} else if ( F_30 ( V_5 ) == V_548 ) {
V_5 -> V_1580 |= 0x00148000 ;
} else {
V_5 -> V_1580 |= 0x001b000f ;
}
}
if ( F_23 ( V_5 , V_2722 ) )
V_5 -> V_1580 |= V_2719 ;
if ( F_30 ( V_5 ) == V_499 ||
F_30 ( V_5 ) == V_500 )
V_5 -> V_1580 &= 0xfffffff0 ;
if ( F_30 ( V_5 ) == V_536 ||
F_30 ( V_5 ) == V_537 ) {
V_5 -> V_1580 |= V_2723 ;
V_5 -> V_1580 |= V_2724 ;
}
F_46 ( V_1576 , V_5 -> V_1580 ) ;
if ( F_30 ( V_5 ) != V_536 &&
F_30 ( V_5 ) != V_537 )
goto V_502;
V_2712 = V_5 -> V_1580 ;
V_5 -> V_1580 &= ~ V_2725 ;
F_46 ( V_1576 , V_5 -> V_1580 ) ;
while ( 1 ) {
T_1 * V_1446 = V_626 , V_42 ;
for ( V_42 = 0 ; V_42 < V_2713 / sizeof( T_1 ) ; V_42 ++ )
V_1446 [ V_42 ] = V_42 ;
V_56 = F_660 ( V_5 , V_626 , V_2701 , V_2713 , true ) ;
if ( V_56 ) {
F_116 ( & V_5 -> V_12 -> V_111 ,
L_114 ,
V_657 , V_56 ) ;
break;
}
V_56 = F_660 ( V_5 , V_626 , V_2701 , V_2713 , false ) ;
if ( V_56 ) {
F_116 ( & V_5 -> V_12 -> V_111 , L_115
L_116 , V_657 , V_56 ) ;
break;
}
for ( V_42 = 0 ; V_42 < V_2713 / sizeof( T_1 ) ; V_42 ++ ) {
if ( V_1446 [ V_42 ] == V_42 )
continue;
if ( ( V_5 -> V_1580 & V_2725 ) !=
V_2688 ) {
V_5 -> V_1580 &= ~ V_2725 ;
V_5 -> V_1580 |= V_2688 ;
F_46 ( V_1576 , V_5 -> V_1580 ) ;
break;
} else {
F_116 ( & V_5 -> V_12 -> V_111 ,
L_117
L_118 , V_657 , V_1446 [ V_42 ] , V_42 ) ;
V_56 = - V_82 ;
goto V_502;
}
}
if ( V_42 == ( V_2713 / sizeof( T_1 ) ) ) {
V_56 = 0 ;
break;
}
}
if ( ( V_5 -> V_1580 & V_2725 ) !=
V_2688 ) {
if ( F_647 ( V_2726 ) ) {
V_5 -> V_1580 &= ~ V_2725 ;
V_5 -> V_1580 |= V_2688 ;
} else {
V_5 -> V_1580 = V_2712 ;
}
F_46 ( V_1576 , V_5 -> V_1580 ) ;
}
V_502:
F_404 ( & V_5 -> V_12 -> V_111 , V_2713 , V_626 , V_2701 ) ;
V_2714:
return V_56 ;
}
static void F_662 ( struct V_4 * V_5 )
{
if ( F_23 ( V_5 , 57765_PLUS ) ) {
V_5 -> V_1603 . V_1604 =
V_2727 ;
V_5 -> V_1603 . V_1606 =
V_2728 ;
V_5 -> V_1603 . V_1608 =
V_2729 ;
V_5 -> V_1603 . V_1609 =
V_2727 ;
V_5 -> V_1603 . V_1610 =
V_2730 ;
V_5 -> V_1603 . V_1611 =
V_2731 ;
} else if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_5 -> V_1603 . V_1604 =
V_2727 ;
V_5 -> V_1603 . V_1606 =
V_2732 ;
V_5 -> V_1603 . V_1608 =
V_2733 ;
if ( F_30 ( V_5 ) == V_36 ) {
V_5 -> V_1603 . V_1606 =
V_2734 ;
V_5 -> V_1603 . V_1608 =
V_2735 ;
}
V_5 -> V_1603 . V_1609 =
V_2736 ;
V_5 -> V_1603 . V_1610 =
V_2737 ;
V_5 -> V_1603 . V_1611 =
V_2738 ;
} else {
V_5 -> V_1603 . V_1604 =
V_2739 ;
V_5 -> V_1603 . V_1606 =
V_2740 ;
V_5 -> V_1603 . V_1608 =
V_2741 ;
V_5 -> V_1603 . V_1609 =
V_2742 ;
V_5 -> V_1603 . V_1610 =
V_2743 ;
V_5 -> V_1603 . V_1611 =
V_2744 ;
}
V_5 -> V_1603 . V_1613 = V_2745 ;
V_5 -> V_1603 . V_1615 = V_2746 ;
}
static char * F_663 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_216 & V_400 ) {
case V_2747 : return L_119 ;
case V_401 : return L_120 ;
case V_565 : return L_121 ;
case V_2748 : return L_122 ;
case V_2749 : return L_123 ;
case V_2750 : return L_124 ;
case V_2751 : return L_125 ;
case V_2752 : return L_126 ;
case V_2753 : return L_127 ;
case V_2754 : return L_128 ;
case V_2755 : return L_129 ;
case V_2756 : return L_130 ;
case V_2757 : return L_131 ;
case V_2758 : return L_132 ;
case V_2759 : return L_133 ;
case V_2760 : return L_134 ;
case V_2761 : return L_135 ;
case V_2762 : return L_136 ;
case V_2763 : return L_137 ;
case V_2764 : return L_138 ;
case V_2765 : return L_139 ;
case V_2766 : return L_140 ;
case V_2767 : return L_141 ;
case V_941 : return L_142 ;
case 0 : return L_143 ;
default: return L_144 ;
}
}
static char * F_664 ( struct V_4 * V_5 , char * V_2768 )
{
if ( F_23 ( V_5 , V_1079 ) ) {
strcpy ( V_2768 , L_145 ) ;
return V_2768 ;
} else if ( F_23 ( V_5 , V_841 ) ) {
T_1 V_150 = F_33 ( V_153 ) & 0x1f ;
strcpy ( V_2768 , L_146 ) ;
if ( ( V_150 == 7 ) ||
( ( F_33 ( V_497 ) & V_2569 ) ==
V_2769 ) )
strcat ( V_2768 , L_147 ) ;
else if ( V_150 == 0 )
strcat ( V_2768 , L_148 ) ;
else if ( V_150 == 2 )
strcat ( V_2768 , L_149 ) ;
else if ( V_150 == 4 )
strcat ( V_2768 , L_150 ) ;
else if ( V_150 == 6 )
strcat ( V_2768 , L_151 ) ;
} else {
strcpy ( V_2768 , L_152 ) ;
if ( F_23 ( V_5 , V_842 ) )
strcat ( V_2768 , L_150 ) ;
else
strcat ( V_2768 , L_148 ) ;
}
if ( F_23 ( V_5 , V_2618 ) )
strcat ( V_2768 , L_153 ) ;
else
strcat ( V_2768 , L_154 ) ;
return V_2768 ;
}
static void F_665 ( struct V_4 * V_5 )
{
struct V_1464 * V_1465 = & V_5 -> V_972 ;
memset ( V_1465 , 0 , sizeof( * V_1465 ) ) ;
V_1465 -> V_642 = V_2770 ;
V_1465 -> V_1476 = V_2771 ;
V_1465 -> V_1467 = V_2772 ;
V_1465 -> V_1478 = V_2773 ;
V_1465 -> V_1469 = V_2774 ;
V_1465 -> V_1484 = V_2775 ;
V_1465 -> V_1486 = V_2776 ;
V_1465 -> V_1480 = V_2777 ;
V_1465 -> V_1471 = V_2778 ;
V_1465 -> V_973 = V_2779 ;
if ( V_5 -> V_127 & ( V_2650 |
V_2651 ) ) {
V_1465 -> V_1476 = V_2780 ;
V_1465 -> V_1484 = V_2781 ;
V_1465 -> V_1467 = V_2782 ;
V_1465 -> V_1486 = V_2783 ;
}
if ( F_23 ( V_5 , 5705_PLUS ) ) {
V_1465 -> V_1484 = 0 ;
V_1465 -> V_1486 = 0 ;
V_1465 -> V_973 = 0 ;
}
}
static int F_666 ( struct V_1791 * V_12 ,
const struct V_2566 * V_2567 )
{
struct V_364 * V_111 ;
struct V_4 * V_5 ;
int V_42 , V_75 ;
T_1 V_2784 , V_2785 , V_2786 ;
char V_2768 [ 40 ] ;
T_6 V_2787 , V_2788 ;
T_15 V_1189 = 0 ;
F_667 ( V_2789 L_155 , V_1974 ) ;
V_75 = F_668 ( V_12 ) ;
if ( V_75 ) {
F_116 ( & V_12 -> V_111 , L_156 ) ;
return V_75 ;
}
V_75 = F_669 ( V_12 , V_2017 ) ;
if ( V_75 ) {
F_116 ( & V_12 -> V_111 , L_157 ) ;
goto V_2790;
}
F_670 ( V_12 ) ;
V_111 = F_671 ( sizeof( * V_5 ) , V_1895 ) ;
if ( ! V_111 ) {
V_75 = - V_268 ;
goto V_2791;
}
F_672 ( V_111 , & V_12 -> V_111 ) ;
V_5 = F_110 ( V_111 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_111 = V_111 ;
V_5 -> V_354 = V_2792 ;
V_5 -> V_356 = V_2793 ;
V_5 -> V_125 = 1 ;
V_5 -> V_1911 = false ;
if ( V_2794 > 0 )
V_5 -> V_2028 = V_2794 ;
else
V_5 -> V_2028 = V_2795 ;
if ( F_673 ( V_12 ) ) {
F_83 ( V_5 , V_264 ) ;
if ( F_674 ( V_12 ) )
F_83 ( V_5 , V_30 ) ;
if ( F_675 ( V_12 ) )
F_83 ( V_5 , V_2722 ) ;
if ( F_676 ( V_12 ) ) {
F_83 ( V_5 , V_267 ) ;
F_83 ( V_5 , V_265 ) ;
}
if ( F_677 ( V_12 ) )
F_83 ( V_5 , V_835 ) ;
}
V_5 -> V_120 =
V_121 |
V_2796 |
V_2797 |
V_2798 ;
V_5 -> V_644 = ( V_2799 | V_2800 |
V_2801 ) ;
#ifdef F_678
V_5 -> V_644 |= V_2802 ;
#endif
F_679 ( & V_5 -> V_209 ) ;
F_679 ( & V_5 -> V_11 ) ;
F_680 ( & V_5 -> V_1222 , F_487 ) ;
V_5 -> V_8 = F_681 ( V_12 , V_2803 ) ;
if ( ! V_5 -> V_8 ) {
F_116 ( & V_12 -> V_111 , L_158 ) ;
V_75 = - V_268 ;
goto V_2804;
}
if ( V_5 -> V_12 -> V_543 == V_544 ||
V_5 -> V_12 -> V_543 == V_2805 ||
V_5 -> V_12 -> V_543 == V_545 ||
V_5 -> V_12 -> V_543 == V_2806 ||
V_5 -> V_12 -> V_543 == V_2481 ||
V_5 -> V_12 -> V_543 == V_2482 ||
V_5 -> V_12 -> V_543 == V_2483 ||
V_5 -> V_12 -> V_543 == V_2553 ||
V_5 -> V_12 -> V_543 == V_2554 ||
V_5 -> V_12 -> V_543 == V_2555 ||
V_5 -> V_12 -> V_543 == V_2556 ||
V_5 -> V_12 -> V_543 == V_2557 ||
V_5 -> V_12 -> V_543 == V_2532 ||
V_5 -> V_12 -> V_543 == V_2558 ||
V_5 -> V_12 -> V_543 == V_2559 ) {
F_83 ( V_5 , V_60 ) ;
V_5 -> V_9 = F_681 ( V_12 , V_2807 ) ;
if ( ! V_5 -> V_9 ) {
F_116 ( & V_12 -> V_111 ,
L_159 ) ;
V_75 = - V_268 ;
goto V_2808;
}
}
V_5 -> V_1343 = V_2809 ;
V_5 -> V_1347 = V_2810 ;
V_111 -> V_2811 = & V_2812 ;
V_111 -> V_2813 = V_2814 ;
V_111 -> V_2815 = & V_2816 ;
V_111 -> V_279 = V_12 -> V_279 ;
V_75 = F_643 ( V_5 , V_2567 ) ;
if ( V_75 ) {
F_116 ( & V_12 -> V_111 ,
L_160 ) ;
goto V_2817;
}
if ( F_23 ( V_5 , V_1648 ) )
V_2788 = V_2787 = F_360 ( 32 ) ;
else if ( F_23 ( V_5 , 40BIT_DMA_BUG ) ) {
V_2788 = V_2787 = F_360 ( 40 ) ;
#ifdef V_1245
V_2787 = F_360 ( 64 ) ;
#endif
} else
V_2788 = V_2787 = F_360 ( 64 ) ;
if ( V_2787 > F_360 ( 32 ) ) {
V_75 = F_682 ( V_12 , V_2787 ) ;
if ( ! V_75 ) {
V_1189 |= V_2818 ;
V_75 = F_683 ( V_12 ,
V_2788 ) ;
if ( V_75 < 0 ) {
F_116 ( & V_12 -> V_111 , L_161
L_162 ) ;
goto V_2817;
}
}
}
if ( V_75 || V_2787 == F_360 ( 32 ) ) {
V_75 = F_682 ( V_12 , F_360 ( 32 ) ) ;
if ( V_75 ) {
F_116 ( & V_12 -> V_111 ,
L_163 ) ;
goto V_2817;
}
}
F_662 ( V_5 ) ;
if ( F_76 ( V_5 ) != V_2819 ) {
V_1189 |= V_2820 | V_2821 | V_1190 ;
if ( F_23 ( V_5 , 5755_PLUS ) )
V_1189 |= V_2822 ;
}
if ( ( F_23 ( V_5 , V_1298 ) ||
F_23 ( V_5 , V_1299 ) ||
F_23 ( V_5 , V_1300 ) ) &&
( V_1189 & V_2821 ) )
V_1189 |= V_1276 ;
if ( F_23 ( V_5 , V_1299 ) || F_23 ( V_5 , V_1300 ) ) {
if ( V_1189 & V_2822 )
V_1189 |= V_1277 ;
if ( F_23 ( V_5 , V_1300 ) ||
F_30 ( V_5 ) == V_45 ||
( F_30 ( V_5 ) == V_413 &&
F_145 ( V_5 ) != V_503 ) ||
F_30 ( V_5 ) == V_257 ||
F_30 ( V_5 ) == V_1411 )
V_1189 |= V_2823 ;
}
V_111 -> V_1189 |= V_1189 | V_2824 |
V_2825 ;
V_111 -> V_2826 |= V_1189 ;
if ( F_30 ( V_5 ) != V_566 &&
! F_23 ( V_5 , V_152 ) )
V_1189 |= V_1332 ;
V_111 -> V_2827 |= V_1189 ;
V_111 -> V_2828 |= V_2829 ;
if ( F_76 ( V_5 ) == V_1704 &&
! F_23 ( V_5 , V_1600 ) &&
! ( F_33 ( V_1241 ) & V_1647 ) ) {
F_83 ( V_5 , V_2036 ) ;
V_5 -> V_1343 = 63 ;
}
V_75 = F_656 ( V_5 ) ;
if ( V_75 ) {
F_116 ( & V_12 -> V_111 ,
L_164 ) ;
goto V_2817;
}
V_2786 = V_20 + V_16 ;
V_2785 = V_15 + V_16 ;
V_2784 = V_2830 + V_16 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_122 ; V_42 ++ ) {
struct V_130 * V_131 = & V_5 -> V_123 [ V_42 ] ;
V_131 -> V_5 = V_5 ;
V_131 -> V_1088 = V_2831 ;
V_131 -> V_124 = V_2786 ;
if ( V_42 <= 4 )
V_2786 += 0x8 ;
else
V_2786 += 0x4 ;
V_131 -> V_1207 = V_2785 ;
V_131 -> V_1322 = V_2784 ;
if ( V_42 )
V_131 -> V_126 = V_2832 << ( V_42 - 1 ) ;
else
V_131 -> V_126 = V_1860 ;
if ( ! F_23 ( V_5 , V_1061 ) )
break;
if ( ! V_42 )
continue;
V_2785 += 0x8 ;
if ( V_2784 & 0x4 )
V_2784 -= 0x4 ;
else
V_2784 += 0xc ;
}
if ( ( F_33 ( V_138 ) & V_128 ) ||
( F_33 ( V_1066 ) & V_1380 ) ) {
F_241 ( V_5 , 0 ) ;
F_46 ( V_1063 , V_1383 ) ;
F_431 ( V_5 , V_110 , 1 ) ;
F_242 ( V_5 ) ;
}
V_75 = F_661 ( V_5 ) ;
if ( V_75 ) {
F_116 ( & V_12 -> V_111 , L_165 ) ;
goto V_2817;
}
F_665 ( V_5 ) ;
F_684 ( V_12 , V_111 ) ;
if ( F_30 ( V_5 ) == V_477 ||
F_30 ( V_5 ) == V_533 ||
F_30 ( V_5 ) == V_767 )
F_83 ( V_5 , V_992 ) ;
F_480 ( V_5 ) ;
F_139 ( V_5 ) ;
V_75 = F_685 ( V_111 ) ;
if ( V_75 ) {
F_116 ( & V_12 -> V_111 , L_166 ) ;
goto V_2817;
}
if ( F_23 ( V_5 , V_992 ) ) {
F_251 ( V_5 ) ;
V_5 -> V_996 = F_686 ( & V_5 -> V_1009 ,
& V_5 -> V_12 -> V_111 ) ;
if ( F_115 ( V_5 -> V_996 ) )
V_5 -> V_996 = NULL ;
}
F_97 ( V_111 , L_167 ,
V_5 -> V_2480 ,
F_76 ( V_5 ) ,
F_664 ( V_5 , V_2768 ) ,
V_111 -> V_694 ) ;
if ( V_5 -> V_178 & V_391 ) {
struct V_211 * V_212 ;
V_212 = V_5 -> V_213 -> V_214 [ V_5 -> V_160 ] ;
F_97 ( V_111 ,
L_168 ,
V_212 -> V_215 -> V_269 , F_114 ( & V_212 -> V_111 ) ) ;
} else {
char * V_2833 ;
if ( V_5 -> V_178 & V_392 )
V_2833 = L_169 ;
else if ( V_5 -> V_178 & V_359 )
V_2833 = L_170 ;
else
V_2833 = L_171 ;
F_97 ( V_111 , L_172
L_173 ,
F_663 ( V_5 ) , V_2833 ,
( V_5 -> V_178 & V_423 ) == 0 ,
( V_5 -> V_178 & V_338 ) != 0 ) ;
}
F_97 ( V_111 , L_174 ,
( V_111 -> V_1189 & V_1190 ) != 0 ,
F_23 ( V_5 , V_142 ) != 0 ,
( V_5 -> V_178 & V_818 ) != 0 ,
F_23 ( V_5 , V_308 ) != 0 ,
F_23 ( V_5 , V_1600 ) != 0 ) ;
F_97 ( V_111 , L_175 ,
V_5 -> V_1580 ,
V_12 -> V_2787 == F_360 ( 32 ) ? 32 :
( ( T_6 ) V_12 -> V_2787 ) == F_360 ( 40 ) ? 40 : 64 ) ;
F_687 ( V_12 ) ;
return 0 ;
V_2817:
if ( V_5 -> V_9 ) {
F_649 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
V_2808:
if ( V_5 -> V_8 ) {
F_649 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
V_2804:
F_688 ( V_111 ) ;
V_2791:
F_689 ( V_12 ) ;
V_2790:
if ( F_690 ( V_12 ) )
F_691 ( V_12 ) ;
return V_75 ;
}
static void F_692 ( struct V_1791 * V_12 )
{
struct V_364 * V_111 = F_152 ( V_12 ) ;
if ( V_111 ) {
struct V_4 * V_5 = F_110 ( V_111 ) ;
F_255 ( V_5 ) ;
F_499 ( V_5 -> V_662 ) ;
F_325 ( V_5 ) ;
if ( F_23 ( V_5 , V_267 ) ) {
F_124 ( V_5 ) ;
F_84 ( V_5 ) ;
}
F_693 ( V_111 ) ;
if ( V_5 -> V_9 ) {
F_649 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
if ( V_5 -> V_8 ) {
F_649 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
F_688 ( V_111 ) ;
F_689 ( V_12 ) ;
F_691 ( V_12 ) ;
}
}
static int F_694 ( struct V_543 * V_543 )
{
struct V_1791 * V_12 = F_695 ( V_543 ) ;
struct V_364 * V_111 = F_152 ( V_12 ) ;
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_75 = 0 ;
F_488 () ;
if ( ! F_144 ( V_111 ) )
goto V_2834;
F_325 ( V_5 ) ;
F_122 ( V_5 ) ;
F_341 ( V_5 ) ;
F_483 ( V_5 ) ;
F_241 ( V_5 , 1 ) ;
F_45 ( V_5 ) ;
F_242 ( V_5 ) ;
F_696 ( V_111 ) ;
F_241 ( V_5 , 0 ) ;
F_431 ( V_5 , V_110 , 1 ) ;
F_85 ( V_5 , V_562 ) ;
F_242 ( V_5 ) ;
V_75 = F_199 ( V_5 ) ;
if ( V_75 ) {
int V_761 ;
F_241 ( V_5 , 0 ) ;
F_83 ( V_5 , V_562 ) ;
V_761 = F_485 ( V_5 , true ) ;
if ( V_761 )
goto V_502;
F_482 ( V_5 ) ;
F_697 ( V_111 ) ;
F_343 ( V_5 ) ;
V_502:
F_242 ( V_5 ) ;
if ( ! V_761 )
F_119 ( V_5 ) ;
}
V_2834:
F_489 () ;
return V_75 ;
}
static int F_698 ( struct V_543 * V_543 )
{
struct V_1791 * V_12 = F_695 ( V_543 ) ;
struct V_364 * V_111 = F_152 ( V_12 ) ;
struct V_4 * V_5 = F_110 ( V_111 ) ;
int V_75 = 0 ;
F_488 () ;
if ( ! F_144 ( V_111 ) )
goto V_2834;
F_697 ( V_111 ) ;
F_241 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_83 ( V_5 , V_562 ) ;
V_75 = F_485 ( V_5 ,
! ( V_5 -> V_178 & V_569 ) ) ;
if ( V_75 )
goto V_502;
F_482 ( V_5 ) ;
F_343 ( V_5 ) ;
V_502:
F_242 ( V_5 ) ;
if ( ! V_75 )
F_119 ( V_5 ) ;
V_2834:
F_489 () ;
return V_75 ;
}
static void F_699 ( struct V_1791 * V_12 )
{
struct V_364 * V_111 = F_152 ( V_12 ) ;
struct V_4 * V_5 = F_110 ( V_111 ) ;
F_488 () ;
F_696 ( V_111 ) ;
if ( F_144 ( V_111 ) )
F_486 ( V_111 ) ;
if ( V_2835 == V_2836 )
F_202 ( V_5 ) ;
F_489 () ;
}
static T_21 F_700 ( struct V_1791 * V_12 ,
T_22 V_848 )
{
struct V_364 * V_2837 = F_152 ( V_12 ) ;
struct V_4 * V_5 = F_110 ( V_2837 ) ;
T_21 V_75 = V_2838 ;
F_97 ( V_2837 , L_176 ) ;
F_488 () ;
if ( V_848 == V_2839 )
V_5 -> V_1911 = true ;
if ( ! V_2837 || ! F_144 ( V_2837 ) )
goto V_186;
F_122 ( V_5 ) ;
F_341 ( V_5 ) ;
F_483 ( V_5 ) ;
F_325 ( V_5 ) ;
F_696 ( V_2837 ) ;
F_241 ( V_5 , 0 ) ;
F_431 ( V_5 , V_110 , 0 ) ;
F_242 ( V_5 ) ;
V_186:
if ( V_848 == V_2840 ) {
if ( V_2837 ) {
F_335 ( V_5 ) ;
F_486 ( V_2837 ) ;
}
V_75 = V_2841 ;
} else {
F_691 ( V_12 ) ;
}
F_489 () ;
return V_75 ;
}
static T_21 F_701 ( struct V_1791 * V_12 )
{
struct V_364 * V_2837 = F_152 ( V_12 ) ;
struct V_4 * V_5 = F_110 ( V_2837 ) ;
T_21 V_628 = V_2841 ;
int V_75 ;
F_488 () ;
if ( F_668 ( V_12 ) ) {
F_116 ( & V_12 -> V_111 ,
L_177 ) ;
goto V_186;
}
F_670 ( V_12 ) ;
F_702 ( V_12 ) ;
F_687 ( V_12 ) ;
if ( ! V_2837 || ! F_144 ( V_2837 ) ) {
V_628 = V_2842 ;
goto V_186;
}
V_75 = F_197 ( V_5 ) ;
if ( V_75 )
goto V_186;
V_628 = V_2842 ;
V_186:
if ( V_628 != V_2842 && V_2837 && F_144 ( V_2837 ) ) {
F_335 ( V_5 ) ;
F_486 ( V_2837 ) ;
}
F_489 () ;
return V_628 ;
}
static void F_703 ( struct V_1791 * V_12 )
{
struct V_364 * V_2837 = F_152 ( V_12 ) ;
struct V_4 * V_5 = F_110 ( V_2837 ) ;
int V_75 ;
F_488 () ;
if ( ! F_144 ( V_2837 ) )
goto V_186;
F_241 ( V_5 , 0 ) ;
F_42 ( V_5 , V_96 ) ;
F_83 ( V_5 , V_562 ) ;
V_75 = F_485 ( V_5 , true ) ;
if ( V_75 ) {
F_242 ( V_5 ) ;
F_185 ( V_2837 , L_178 ) ;
goto V_186;
}
F_697 ( V_2837 ) ;
F_482 ( V_5 ) ;
F_343 ( V_5 ) ;
F_242 ( V_5 ) ;
F_119 ( V_5 ) ;
V_186:
V_5 -> V_1911 = false ;
F_489 () ;
}
