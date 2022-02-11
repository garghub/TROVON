static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , unsigned int V_4 ,
unsigned int V_5 )
{
unsigned long V_6 ;
if ( V_3 -> V_7 && V_4 ) {
switch ( ( V_4 & 0x7 ) | ( V_5 << 4 ) ) {
case 0x5 :
V_8 -> V_9 |= V_10 ;
break;
case 0x6 :
V_8 -> V_9 |= V_11 ;
break;
case 0x7 :
V_8 -> V_9 |= V_12 ;
break;
case 0x65 :
V_8 -> V_9 |= V_13 ;
break;
case 0x76 :
V_8 -> V_9 |= V_14 ;
break;
case 0x57 :
V_8 -> V_9 |= V_15 ;
break;
default:
F_6 ( L_1
L_2
L_3 ) ;
return - V_16 ;
break;
}
if ( F_7 ( V_4 , V_1 . V_17 ) ) {
F_6 ( L_4 , V_4 ) ;
return - V_16 ;
}
V_8 -> V_4 = V_4 ;
V_8 -> V_18 = V_4 ;
if ( V_5 ) {
if ( F_7 ( V_5 , V_1 . V_17 ) ) {
F_6 ( L_4 ,
V_5 ) ;
return - V_16 ;
}
V_8 -> V_5 = V_5 ;
}
V_8 -> V_19 = F_8 ( V_20 , V_21 | V_22 ) ;
if ( V_8 -> V_19 == NULL )
return - V_23 ;
V_8 -> V_24 = V_8 -> V_19 ;
if ( V_5 ) {
V_8 -> V_25 =
F_8 ( V_20 , V_21 | V_22 ) ;
if ( V_8 -> V_25 == NULL )
return - V_23 ;
}
V_6 = F_9 () ;
F_10 ( V_8 -> V_4 ) ;
F_11 ( V_8 -> V_4 , V_26 ) ;
if ( V_5 ) {
F_10 ( V_8 -> V_5 ) ;
F_11 ( V_8 -> V_5 , V_26 ) ;
}
F_12 ( V_6 ) ;
}
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 ;
unsigned long V_31 = V_28 -> V_32 [ 0 ] ;
unsigned int V_7 = V_28 -> V_32 [ 1 ] ;
unsigned int V_4 = V_28 -> V_32 [ 2 ] ;
unsigned int V_5 = V_28 -> V_32 [ 3 ] ;
unsigned long V_33 ;
int V_34 ;
int V_35 ;
if ( F_14 ( V_3 , sizeof( struct V_36 ) ) < 0 )
return - V_23 ;
F_6 ( L_5 , V_3 -> V_37 , V_1 . V_17 ,
V_31 ) ;
if ( V_7 ) {
F_6 ( L_6 , V_7 ) ;
if ( V_4 ) {
F_6 ( L_7 , V_4 ) ;
if ( V_5 )
F_6 ( L_8 , V_5 ) ;
}
}
F_6 ( L_9 ) ;
if ( V_31 == 0 ) {
F_6 ( L_10 ) ;
return - V_16 ;
}
if ( ! F_15 ( V_31 , V_38 , V_1 . V_17 ) ) {
F_6
( L_11 ,
V_31 , V_31 + V_38 - 1 ) ;
return - V_39 ;
}
V_3 -> V_31 = V_31 ;
V_34 = F_16 ( V_3 ) ;
if ( V_34 < 0 ) {
F_6 ( L_12 ) ;
return - V_40 ;
}
V_3 -> V_41 = V_42 + V_34 ;
V_3 -> V_43 = V_44 -> V_45 ;
if ( V_44 -> V_46 == 2 ) {
V_33 = V_31 + V_47 ;
if ( ! F_15 ( V_33 , V_38 ,
V_1 . V_17 ) ) {
F_6
( L_11 ,
V_33 , V_33 + V_38 - 1 ) ;
return - V_39 ;
}
V_8 -> V_33 = V_33 ;
}
if ( V_7 ) {
if ( F_17 ( V_7 , V_48 , 0 ,
V_1 . V_17 , V_3 ) ) {
F_6 ( L_13 , V_7 ) ;
return - V_16 ;
}
}
V_3 -> V_7 = V_7 ;
switch ( V_7 ) {
case 0 :
break;
case 3 :
V_8 -> V_49 |= 0x8 ;
break;
case 5 :
V_8 -> V_49 |= 0x10 ;
break;
case 7 :
V_8 -> V_49 |= 0x18 ;
break;
case 10 :
V_8 -> V_49 |= 0x28 ;
break;
case 11 :
V_8 -> V_49 |= 0x30 ;
break;
case 15 :
V_8 -> V_49 |= 0x38 ;
break;
default:
F_6 ( L_14 ) ;
return - V_16 ;
break;
}
V_35 = F_5 ( V_3 , V_4 , V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_8 -> V_19 == NULL ) {
V_8 -> V_19 =
F_8 ( V_50 * sizeof( V_51 ) , V_21 ) ;
if ( V_8 -> V_19 == NULL )
return - V_23 ;
}
if ( F_18 ( V_3 , 4 ) < 0 )
return - V_23 ;
V_30 = V_3 -> V_52 + 0 ;
V_3 -> V_53 = V_30 ;
V_30 -> type = V_54 ;
V_30 -> V_55 = V_56 | V_57 | V_58 | V_59 ;
if ( V_44 -> V_60 )
V_30 -> V_55 |= V_61 ;
V_30 -> V_62 = V_44 -> V_63 ;
V_30 -> V_64 = V_44 -> V_63 ;
V_30 -> V_65 = ( 1 << V_44 -> V_66 ) - 1 ;
V_30 -> V_67 = V_44 -> V_68 ;
V_30 -> V_69 = V_70 ;
V_30 -> V_71 = V_72 ;
V_30 -> V_73 = V_74 ;
V_30 -> V_75 = V_76 ;
V_30 -> V_77 = V_78 ;
V_30 = V_3 -> V_52 + 1 ;
if ( V_44 -> V_46 == 1 ) {
V_30 -> type = V_79 ;
V_30 -> V_55 = V_80 ;
V_30 -> V_62 = V_44 -> V_81 ;
V_30 -> V_65 = ( 1 << V_44 -> V_66 ) - 1 ;
V_30 -> V_67 = & V_82 ;
V_30 -> V_83 = V_84 ;
} else {
V_30 -> type = V_85 ;
}
V_30 = V_3 -> V_52 + 2 ;
V_30 -> type = V_86 ;
V_30 -> V_55 = V_56 ;
V_30 -> V_62 = 4 ;
V_30 -> V_65 = 1 ;
V_30 -> V_67 = & V_87 ;
V_30 -> V_88 = V_89 ;
V_30 = V_3 -> V_52 + 3 ;
V_30 -> type = V_90 ;
V_30 -> V_55 = V_80 | V_56 ;
V_30 -> V_62 = V_44 -> V_91 ;
V_30 -> V_65 = 1 ;
V_30 -> V_67 = & V_87 ;
V_30 -> V_88 = V_92 ;
V_78 ( V_3 , V_3 -> V_53 ) ;
F_19 ( V_8 -> V_93 , V_3 -> V_31 + V_94 ) ;
if ( V_44 -> V_46 == 1 ) {
F_19 ( F_20 ( V_44 -> V_81 - 1 ) ,
V_3 -> V_31 + V_95 ) ;
F_21 ( V_8 -> V_96 , V_3 -> V_31 + V_97 ) ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
if ( V_3 -> V_31 )
F_23 ( V_3 -> V_31 , V_38 ) ;
if ( V_3 -> V_7 )
F_24 ( V_3 -> V_7 , V_3 ) ;
if ( V_3 -> V_98 ) {
if ( V_8 -> V_33 )
F_23 ( V_8 -> V_33 , V_38 ) ;
if ( V_8 -> V_4 )
F_25 ( V_8 -> V_4 ) ;
if ( V_8 -> V_5 )
F_25 ( V_8 -> V_5 ) ;
F_26 ( V_8 -> V_19 ) ;
F_26 ( V_8 -> V_25 ) ;
}
F_6 ( L_15 , V_3 -> V_37 ,
V_1 . V_17 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
int V_99 ;
int V_34 ;
V_99 = ( F_27 ( V_3 -> V_31 + V_94 ) >> 4 ) & 0xf ;
V_34 = ( (struct V_100 * ) V_3 -> V_41 ) - V_42 ;
switch ( V_99 ) {
case 0x3 :
if ( V_34 == V_101 || V_34 == V_102 ||
V_34 == V_103 || V_34 == V_104 ) {
F_6 ( L_16 ,
V_42 [ V_34 ] . V_45 ) ;
return V_34 ;
}
F_6
( L_17 ) ;
return V_105 ;
break;
case 0x4 :
if ( V_34 == V_106 || V_34 == V_107 ) {
F_6 ( L_16 ,
V_42 [ V_34 ] . V_45 ) ;
return V_34 ;
}
F_6
( L_18 ) ;
return V_108 ;
break;
case 0x5 :
if ( V_34 == V_109 || V_34 == V_110 ||
V_34 == V_111 || V_34 == V_112 ) {
F_6 ( L_16 ,
V_42 [ V_34 ] . V_45 ) ;
return V_34 ;
}
F_6
( L_19 ) ;
return V_109 ;
break;
case 0x6 :
if ( V_34 == V_108 || V_34 == V_113 ) {
F_6 ( L_16 ,
V_42 [ V_34 ] . V_45 ) ;
return V_34 ;
}
F_6 ( L_20 ) ;
return V_108 ;
break;
case 0x7 :
if ( V_34 == V_105 || V_34 == V_114 ||
V_34 == V_115 || V_34 == V_116 ) {
F_6 ( L_16 ,
V_42 [ V_34 ] . V_45 ) ;
return V_34 ;
}
F_6
( L_21 ) ;
return V_105 ;
break;
case 0x8 :
if ( V_34 == V_117 || V_34 == V_118 ) {
F_6 ( L_16 ,
V_42 [ V_34 ] . V_45 ) ;
return V_34 ;
}
F_6
( L_22 ) ;
return V_117 ;
break;
default:
F_6
( L_23 ,
V_99 ) ;
return V_34 ;
break;
}
return - 1 ;
}
static int V_76 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
unsigned long V_6 ;
F_28 ( & V_3 -> V_119 , V_6 ) ;
F_29 ( V_3 ) ;
F_30 ( & V_3 -> V_119 , V_6 ) ;
return V_30 -> V_120 -> V_121 - V_30 -> V_120 -> V_122 ;
}
static T_3 V_48 ( int V_7 , void * V_123 )
{
struct V_2 * V_3 = V_123 ;
unsigned int V_124 ;
if ( V_3 -> V_125 == 0 ) {
F_31 ( V_3 , L_24 ) ;
return V_126 ;
}
F_32 ( & V_3 -> V_119 ) ;
V_124 = F_27 ( V_3 -> V_31 + V_127 ) ;
if ( ! ( V_124 & INT ) ) {
F_33 ( & V_3 -> V_119 ) ;
return V_128 ;
}
F_19 ( V_129 & ~ INT , V_3 -> V_31 + V_127 ) ;
F_29 ( V_3 ) ;
F_33 ( & V_3 -> V_119 ) ;
return V_126 ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_29 * V_30 = V_3 -> V_52 + 0 ;
struct V_130 * V_120 = V_30 -> V_120 ;
struct V_131 * V_132 = & V_120 -> V_132 ;
unsigned int V_124 = F_27 ( V_3 -> V_31 + V_127 ) ;
V_120 -> V_133 = 0 ;
F_19 ( V_134 , V_3 -> V_31 + V_95 ) ;
if ( V_8 -> V_49 & V_135 ) {
F_34 ( V_3 , V_30 , V_124 ) ;
} else if ( V_124 & V_136 ) {
F_35 ( V_3 , V_30 ) ;
} else if ( V_124 & V_137 ) {
F_36 ( V_3 , V_30 ) ;
}
V_120 -> V_133 |= V_138 ;
if ( V_124 & V_139 ) {
F_19 ( V_129 & ~ V_139 , V_3 -> V_31 + V_127 ) ;
F_31 ( V_3 , L_25 ) ;
V_78 ( V_3 , V_30 ) ;
V_120 -> V_133 |= V_140 | V_141 ;
F_37 ( V_3 , V_30 ) ;
return;
}
if ( V_124 & V_142 ) {
F_19 ( V_129 & ~ V_142 , V_3 -> V_31 + V_127 ) ;
if ( V_8 -> V_49 & V_135 )
F_38 ( V_3 , V_30 ) ;
else
F_36 ( V_3 , V_30 ) ;
V_78 ( V_3 , V_30 ) ;
V_120 -> V_133 |= V_141 ;
} else if ( V_132 -> V_143 == V_144 && V_8 -> V_145 == 0 ) {
V_78 ( V_3 , V_30 ) ;
V_120 -> V_133 |= V_141 ;
}
F_37 ( V_3 , V_30 ) ;
return;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_29 * V_30 , unsigned int V_124 )
{
unsigned long V_6 ;
const int V_146 = V_8 -> V_49 & V_147 ;
V_6 = F_9 () ;
F_39 ( V_3 , V_30 , V_8 -> V_18 ,
V_8 -> V_24 ) ;
F_40 ( V_8 -> V_18 ,
F_41 ( V_8 -> V_24 ) ) ;
F_42 ( V_8 -> V_18 , V_8 -> V_148 ) ;
F_43 ( V_8 -> V_18 ) ;
F_12 ( V_6 ) ;
if ( V_124 & V_149 ) {
F_19 ( V_129 & ~ V_149 , V_3 -> V_31 + V_127 ) ;
if ( V_146 ) {
if ( V_8 -> V_18 == V_8 -> V_4 ) {
V_8 -> V_18 = V_8 -> V_5 ;
V_8 -> V_24 = V_8 -> V_25 ;
} else {
V_8 -> V_18 = V_8 -> V_4 ;
V_8 -> V_24 = V_8 -> V_19 ;
}
}
}
return;
}
static inline V_51 F_44 ( const struct V_2 * V_3 ,
V_51 V_150 )
{
V_150 += 1 << ( V_44 -> V_66 - 1 ) ;
return V_150 ;
}
static void F_45 ( struct V_2 * V_3 , V_51 * V_151 ,
unsigned int V_152 )
{
unsigned int V_153 ;
int V_154 ;
V_154 = F_27 ( V_3 -> V_31 + V_155 ) & V_156 ;
if ( ! V_154 ) {
for ( V_153 = 0 ; V_153 < V_152 ; V_153 ++ )
V_151 [ V_153 ] = F_44 ( V_3 , V_151 [ V_153 ] ) ;
}
}
static void F_39 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
unsigned int V_157 , V_51 * V_158 )
{
unsigned int V_159 , V_160 ;
struct V_131 * V_132 = & V_30 -> V_120 -> V_132 ;
F_10 ( V_157 ) ;
F_46 ( V_157 ) ;
V_159 = V_8 -> V_148 - F_47 ( V_157 ) ;
V_160 = V_159 / sizeof( short ) ;
if ( V_132 -> V_143 == V_144 && V_8 -> V_145 < V_160 )
V_160 = V_8 -> V_145 ;
F_45 ( V_3 , V_158 , V_160 ) ;
F_48 ( V_30 , V_158 , V_159 ) ;
if ( V_30 -> V_120 -> V_132 . V_143 == V_144 )
V_8 -> V_145 -= V_160 ;
return;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
unsigned long V_6 ;
const int V_146 = V_8 -> V_49 & V_147 ;
V_6 = F_9 () ;
F_39 ( V_3 , V_30 , V_8 -> V_18 ,
V_8 -> V_24 ) ;
if ( V_146 ) {
if ( V_8 -> V_18 == V_8 -> V_4 ) {
V_8 -> V_18 = V_8 -> V_5 ;
V_8 -> V_24 = V_8 -> V_25 ;
} else {
V_8 -> V_18 = V_8 -> V_4 ;
V_8 -> V_24 = V_8 -> V_19 ;
}
F_39 ( V_3 , V_30 , V_8 -> V_18 ,
V_8 -> V_24 ) ;
}
F_12 ( V_6 ) ;
F_36 ( V_3 , V_30 ) ;
return;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
int V_161 = 0 ;
struct V_131 * V_132 = & V_30 -> V_120 -> V_132 ;
V_161 = V_50 / 2 ;
if ( V_132 -> V_143 == V_144 && V_8 -> V_145 < V_161 )
V_161 = V_8 -> V_145 ;
F_49 ( V_3 -> V_31 + V_162 , V_8 -> V_19 , V_161 ) ;
F_45 ( V_3 , V_8 -> V_19 , V_161 ) ;
F_48 ( V_30 , V_8 -> V_19 ,
V_161 * sizeof( V_8 -> V_19 [ 0 ] ) ) ;
if ( V_132 -> V_143 == V_144 )
V_8 -> V_145 -= V_161 ;
return;
}
static void F_36 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
short V_163 ;
int V_154 ;
struct V_131 * V_132 = & V_30 -> V_120 -> V_132 ;
V_154 = F_27 ( V_3 -> V_31 + V_155 ) & V_156 ;
while ( F_27 ( V_3 -> V_31 + V_127 ) & V_137 ) {
if ( V_132 -> V_143 == V_144 && V_8 -> V_145 == 0 )
break;
V_163 = F_50 ( V_3 -> V_31 + V_162 ) ;
if ( ! V_154 )
;
V_163 = F_44 ( V_3 , V_163 ) ;
F_51 ( V_30 , V_163 ) ;
if ( V_132 -> V_143 == V_144 )
V_8 -> V_145 -- ;
}
return;
}
static int V_78 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
F_19 ( 0x0 , V_3 -> V_31 + V_127 ) ;
F_19 ( 0x0 , V_3 -> V_31 + V_164 ) ;
F_19 ( 0x0 , V_3 -> V_31 + V_165 ) ;
if ( V_8 -> V_4 )
F_10 ( V_8 -> V_4 ) ;
if ( V_8 -> V_5 )
F_10 ( V_8 -> V_5 ) ;
return 0 ;
}
static int V_72 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
struct V_131 * V_132 )
{
int V_166 = 0 ;
int V_167 ;
unsigned int V_168 ;
int V_153 ;
int V_154 ;
V_167 = V_132 -> V_169 ;
V_132 -> V_169 &= V_170 | V_171 ;
if ( ! V_132 -> V_169 || V_167 != V_132 -> V_169 )
V_166 ++ ;
V_167 = V_132 -> V_172 ;
V_132 -> V_172 &= V_173 | V_174 | V_171 ;
if ( ! V_132 -> V_172 || V_167 != V_132 -> V_172 )
V_166 ++ ;
V_167 = V_132 -> V_175 ;
V_132 -> V_175 &= V_174 | V_171 ;
if ( ! V_132 -> V_175 || V_167 != V_132 -> V_175 )
V_166 ++ ;
V_167 = V_132 -> V_176 ;
V_132 -> V_176 &= V_144 ;
if ( ! V_132 -> V_176 || V_167 != V_132 -> V_176 )
V_166 ++ ;
V_167 = V_132 -> V_143 ;
V_132 -> V_143 &= V_144 | V_171 | V_177 ;
if ( ! V_132 -> V_143 || V_167 != V_132 -> V_143 )
V_166 ++ ;
if ( V_166 )
return 1 ;
if ( V_132 -> V_169 != V_170 && V_132 -> V_169 != V_171 )
V_166 ++ ;
if ( V_132 -> V_172 != V_173 &&
V_132 -> V_172 != V_174 &&
V_132 -> V_172 != V_171 )
V_166 ++ ;
if ( V_132 -> V_175 != V_174 && V_132 -> V_175 != V_171 )
V_166 ++ ;
if ( V_132 -> V_143 != V_144 &&
V_132 -> V_143 != V_177 && V_132 -> V_143 != V_171 )
V_166 ++ ;
if ( V_132 -> V_172 != V_173 &&
V_132 -> V_175 != V_174 )
V_166 ++ ;
if ( V_166 )
return 2 ;
if ( V_132 -> V_178 != 0 ) {
V_132 -> V_178 = 0 ;
V_166 ++ ;
}
if ( V_132 -> V_175 == V_174 ) {
if ( V_132 -> V_179 < V_44 -> V_180 ) {
V_132 -> V_179 = V_44 -> V_180 ;
V_166 ++ ;
}
}
if ( ! V_132 -> V_181 ) {
V_132 -> V_181 = 1 ;
V_166 ++ ;
}
if ( V_132 -> V_182 != V_132 -> V_181 ) {
V_132 -> V_182 = V_132 -> V_181 ;
V_166 ++ ;
}
switch ( V_132 -> V_143 ) {
case V_144 :
if ( ! V_132 -> V_183 ) {
V_132 -> V_183 = 1 ;
V_166 ++ ;
}
break;
case V_177 :
if ( V_132 -> V_183 != 0 ) {
V_132 -> V_183 = 0 ;
V_166 ++ ;
}
break;
default:
break;
}
if ( V_166 )
return 3 ;
if ( V_132 -> V_175 == V_174 ) {
if ( V_132 -> V_172 == V_173 ) {
V_168 = V_132 -> V_179 ;
F_52 ( V_184 ,
& ( V_8 -> V_185 ) ,
& ( V_8 -> V_186 ) ,
& ( V_132 -> V_179 ) ,
V_132 ->
V_6 & V_187 ) ;
if ( V_168 != V_132 -> V_179 )
V_166 ++ ;
}
else {
V_168 = V_132 -> V_179 ;
V_132 -> V_179 =
F_53 ( V_132 -> V_179 ,
V_132 -> V_6 & V_187 ) ;
if ( V_168 != V_132 -> V_179 )
V_166 ++ ;
if ( V_132 -> V_172 == V_174 ) {
if ( V_132 -> V_179 * V_132 -> V_181 >
V_132 -> V_188 ) {
V_132 -> V_188 =
V_132 -> V_179 *
V_132 -> V_181 ;
V_166 ++ ;
}
V_168 = V_132 -> V_188 ;
F_52 ( V_184 ,
& ( V_8 ->
V_185 ) ,
& ( V_8 ->
V_186 ) ,
& ( V_132 ->
V_188 ) ,
V_132 ->
V_6 &
V_187 ) ;
if ( V_168 != V_132 -> V_188 )
V_166 ++ ;
}
}
}
if ( V_166 )
return 4 ;
if ( V_132 -> V_189 ) {
V_154 = F_54 ( V_132 -> V_189 [ 0 ] ) & V_190 ;
for ( V_153 = 1 ; V_153 < V_132 -> V_181 ; V_153 ++ ) {
if ( V_154 != ( F_54 ( V_132 -> V_189 [ V_153 ] ) & V_190 ) ) {
F_31 ( V_3 ,
L_26 ) ;
V_166 ++ ;
break;
}
}
}
if ( V_166 )
return 5 ;
return 0 ;
}
static int F_55 ( struct V_131 V_132 )
{
int V_191 ;
V_191 = V_192 ;
if ( V_132 . V_143 == V_171 )
V_191 |= V_193 ;
switch ( V_132 . V_169 ) {
case V_171 :
V_191 |= V_194 | V_195 ;
break;
case V_170 :
V_191 |= V_196 ;
break;
default:
break;
}
return V_191 ;
}
static int F_56 ( struct V_131 V_132 )
{
int V_197 ;
int V_198 ;
V_198 = F_57 ( V_132 . V_189 [ 0 ] ) ;
V_197 = V_199 ;
if ( V_198 != V_200 )
V_197 |= V_201 ;
if ( V_198 == V_202 )
V_197 |= V_203 ;
if ( F_54 ( V_132 . V_189 [ 0 ] ) & V_190 )
V_197 |= V_156 ;
switch ( V_132 . V_172 ) {
case V_173 :
switch ( V_132 . V_175 ) {
case V_174 :
V_197 |= V_204 ;
break;
case V_171 :
V_197 |= V_205 ;
break;
default:
break;
}
break;
case V_174 :
V_197 |= V_206 | V_204 ;
break;
case V_171 :
V_197 |= V_206 | V_205 ;
break;
default:
break;
}
return V_197 ;
}
static int F_58 ( struct V_2 * V_3 , struct V_131 V_132 )
{
switch ( V_132 . V_172 ) {
case V_173 :
if ( V_132 . V_175 == V_174 ) {
F_52 ( V_184 ,
& ( V_8 -> V_185 ) ,
& ( V_8 -> V_186 ) ,
& ( V_132 . V_179 ) ,
V_132 .
V_6 & V_187 ) ;
if ( F_59 ( V_3 ) < 0 )
return - 1 ;
}
break;
case V_174 :
F_52 ( V_184 , & ( V_8 -> V_185 ) ,
& ( V_8 -> V_186 ) ,
& ( V_132 . V_188 ) ,
V_132 . V_6 & V_187 ) ;
if ( F_59 ( V_3 ) < 0 )
return - 1 ;
break;
default:
break;
}
if ( V_132 . V_143 == V_171 ) {
F_60 ( V_3 -> V_31 + V_207 , 0 , 0 , 1 , 0 ) ;
}
return 0 ;
}
static void F_61 ( struct V_2 * V_3 , struct V_131 V_132 )
{
unsigned long V_208 ;
const int V_146 = V_8 -> V_49 & V_147 ;
if ( ( V_8 -> V_49 & V_135 ) == 0 )
return;
V_8 -> V_148 = F_62 ( & V_132 ) ;
V_208 = F_9 () ;
F_10 ( V_8 -> V_4 ) ;
F_46 ( V_8 -> V_4 ) ;
F_40 ( V_8 -> V_4 , F_41 ( V_8 -> V_19 ) ) ;
F_42 ( V_8 -> V_4 , V_8 -> V_148 ) ;
V_8 -> V_18 = V_8 -> V_4 ;
V_8 -> V_24 = V_8 -> V_19 ;
F_43 ( V_8 -> V_4 ) ;
if ( V_146 ) {
F_10 ( V_8 -> V_5 ) ;
F_46 ( V_8 -> V_5 ) ;
F_40 ( V_8 -> V_5 , F_41 ( V_8 -> V_25 ) ) ;
F_42 ( V_8 -> V_5 , V_8 -> V_148 ) ;
F_43 ( V_8 -> V_5 ) ;
}
F_12 ( V_208 ) ;
return;
}
static void F_63 ( struct V_2 * V_3 , struct V_131 V_132 )
{
int V_153 , V_209 , V_210 ;
unsigned long V_211 ;
const int V_212 = 0x3 ;
const int V_213 = 8 ;
V_209 = V_132 . V_181 ;
F_28 ( & V_3 -> V_119 , V_211 ) ;
F_19 ( V_214 , V_3 -> V_31 + V_95 ) ;
F_19 ( V_209 - 1 , V_3 -> V_31 + V_215 ) ;
for ( V_153 = 0 ; V_153 < V_209 ; V_153 ++ ) {
V_210 =
F_64 ( V_132 .
V_189 [ V_153 ] ) | ( ( F_54 ( V_132 . V_189 [ V_153 ] ) &
V_212 ) << V_213 ) ;
F_21 ( V_210 , V_3 -> V_31 + V_216 ) ;
}
F_19 ( V_209 - 1 , V_3 -> V_31 + V_215 ) ;
F_30 ( & V_3 -> V_119 , V_211 ) ;
return;
}
static int V_70 ( struct V_2 * V_3 ,
struct V_29 * V_30 )
{
int V_217 ;
int V_191 , V_197 ;
struct V_130 * V_120 = V_30 -> V_120 ;
struct V_131 V_132 = V_120 -> V_132 ;
if ( ! V_3 -> V_7 ) {
F_31 ( V_3 ,
L_27 ) ;
return - 1 ;
}
if ( V_132 . V_6 & ( V_218 | V_219 ) )
V_8 -> V_49 &= ~ V_135 ;
else
V_8 -> V_49 |= V_8 -> V_9 ;
if ( V_132 . V_6 & V_218 ) {
V_8 -> V_49 &= ~ V_220 ;
} else {
V_8 -> V_49 |= V_220 ;
}
if ( V_132 . V_143 == V_144 )
V_8 -> V_145 = V_132 . V_183 * V_132 . V_181 ;
V_78 ( V_3 , V_30 ) ;
V_191 = F_55 ( V_132 ) ;
V_197 = F_56 ( V_132 ) ;
F_63 ( V_3 , V_132 ) ;
V_217 = F_58 ( V_3 , V_132 ) ;
if ( V_217 < 0 ) {
F_31 ( V_3 , L_28 ) ;
return V_217 ;
}
F_61 ( V_3 , V_132 ) ;
F_19 ( V_197 , V_3 -> V_31 + V_155 ) ;
if ( V_197 & V_206 ) {
F_19 ( V_132 . V_179 / 1000 - 1 ,
V_3 -> V_31 + V_221 ) ;
F_19 ( V_132 . V_181 - 1 , V_3 -> V_31 + V_222 ) ;
}
F_19 ( V_8 -> V_49 , V_3 -> V_31 + V_164 ) ;
F_19 ( V_191 , V_3 -> V_31 + V_165 ) ;
F_19 ( V_223 , V_3 -> V_31 + V_127 ) ;
return 0 ;
}
static int V_74 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
struct V_224 * V_225 , unsigned int * V_226 )
{
int V_153 , V_209 ;
int V_227 , V_228 , V_198 , V_210 ;
int V_229 = 1000 ;
short V_163 ;
int V_230 = 0 ;
unsigned long V_211 ;
V_198 = F_57 ( V_225 -> V_231 ) ;
V_230 |= V_199 ;
if ( V_198 != V_200 )
V_230 |= V_201 ;
if ( V_198 == V_202 )
V_230 |= V_203 ;
if ( F_54 ( V_225 -> V_231 ) & V_190 )
V_230 |= V_156 ;
F_19 ( V_230 , V_3 -> V_31 + V_155 ) ;
F_19 ( V_223 , V_3 -> V_31 + V_127 ) ;
F_19 ( 0x0 , V_3 -> V_31 + V_165 ) ;
F_19 ( V_192 , V_3 -> V_31 + V_165 ) ;
V_227 = F_64 ( V_225 -> V_231 ) ;
V_228 = F_54 ( V_225 -> V_231 ) & 0x3 ;
V_210 = V_227 | ( V_228 << 8 ) ;
F_28 ( & V_3 -> V_119 , V_211 ) ;
F_19 ( V_214 , V_3 -> V_31 + V_95 ) ;
F_19 ( 0x0 , V_3 -> V_31 + V_215 ) ;
F_21 ( V_210 , V_3 -> V_31 + V_216 ) ;
F_19 ( 0x0 , V_3 -> V_31 + V_215 ) ;
F_19 ( V_134 , V_3 -> V_31 + V_95 ) ;
for ( V_209 = 0 ; V_209 < V_225 -> V_209 ; V_209 ++ ) {
F_19 ( 0 , V_3 -> V_31 + V_162 ) ;
for ( V_153 = 0 ; V_153 < V_229 ; V_153 ++ ) {
if ( F_27 ( V_3 -> V_31 + V_127 ) & V_137 )
break;
}
if ( V_153 == V_229 ) {
F_31 ( V_3 , L_29 ) ;
V_209 = - V_232 ;
goto exit;
}
V_163 = F_50 ( V_3 -> V_31 + V_162 ) ;
if ( ( V_230 & V_156 ) == 0 )
V_163 += 1 << ( V_44 -> V_66 - 1 ) ;
V_226 [ V_209 ] = V_163 ;
}
exit:
F_30 ( & V_3 -> V_119 , V_211 ) ;
return V_209 ;
}
static int V_84 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
struct V_224 * V_225 , unsigned int * V_226 )
{
int V_227 = F_64 ( V_225 -> V_231 ) ;
int V_233 = V_44 -> V_81 - 1 ;
short V_234 ;
unsigned long V_211 ;
V_234 = V_226 [ 0 ] - ( 1 << ( V_44 -> V_66 - 1 ) ) ;
if ( V_227 == V_233 )
V_8 -> V_96 = V_234 ;
F_28 ( & V_3 -> V_119 , V_211 ) ;
F_19 ( F_20 ( V_227 ) , V_3 -> V_31 + V_95 ) ;
F_21 ( V_234 , V_3 -> V_31 + V_97 ) ;
if ( V_227 != V_233 ) {
F_19 ( F_20 ( V_233 ) , V_3 -> V_31 + V_95 ) ;
F_21 ( V_8 -> V_96 , V_3 -> V_31 + V_97 ) ;
}
F_30 ( & V_3 -> V_119 , V_211 ) ;
return 1 ;
}
static int V_89 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
struct V_224 * V_225 , unsigned int * V_226 )
{
V_226 [ 1 ] = F_27 ( V_3 -> V_31 + V_94 ) & 0xf ;
V_226 [ 0 ] = 0 ;
return 2 ;
}
static int V_92 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
struct V_224 * V_225 , unsigned int * V_226 )
{
unsigned int V_235 ;
V_226 [ 0 ] &= ( 1 << V_30 -> V_62 ) - 1 ;
V_235 = V_8 -> V_93 ;
V_235 &= ~ V_226 [ 0 ] ;
V_235 |= V_226 [ 0 ] & V_226 [ 1 ] ;
V_8 -> V_93 = V_235 ;
F_19 ( V_8 -> V_93 , V_3 -> V_31 + V_94 ) ;
V_226 [ 1 ] = V_8 -> V_93 ;
return 2 ;
}
static int F_59 ( struct V_2 * V_3 )
{
int V_166 = 0 ;
if ( F_60 ( V_3 -> V_31 + V_207 , 0 , 1 , V_8 -> V_185 ,
2 ) )
V_166 ++ ;
if ( F_60 ( V_3 -> V_31 + V_207 , 0 , 2 , V_8 -> V_186 ,
2 ) )
V_166 ++ ;
if ( V_166 )
return - 1 ;
return 0 ;
}
static unsigned int F_53 ( unsigned int V_179 , int V_236 )
{
unsigned int V_237 ;
if ( V_179 > 64000 )
V_179 = 64000 ;
switch ( V_236 ) {
case V_238 :
default:
V_237 = ( V_179 + 500 ) / 1000 ;
break;
case V_239 :
V_237 = V_179 / 1000 ;
break;
case V_240 :
V_237 = ( V_179 - 1 ) / 1000 + 1 ;
break;
}
return V_237 * 1000 ;
}
static unsigned int F_62 ( struct V_131 * V_132 )
{
unsigned int V_241 = V_20 ;
static const int V_242 = 2 ;
unsigned int V_243 = 300000000 ;
unsigned int V_244 ;
switch ( V_132 -> V_172 ) {
case V_173 :
if ( V_132 -> V_175 == V_174 )
V_241 = ( V_243 / V_132 -> V_179 ) * V_242 ;
break;
case V_174 :
V_241 = ( V_243 / ( V_132 -> V_188 * V_132 -> V_181 ) ) *
V_242 ;
break;
default:
V_241 = V_20 ;
break;
}
V_244 = V_20 ;
if ( V_132 -> V_143 == V_144 &&
V_132 -> V_183 * V_132 -> V_181 * V_242 < V_244 )
V_244 = V_132 -> V_183 * V_132 -> V_181 * V_242 ;
if ( V_241 > V_244 )
V_241 = V_244 ;
if ( V_241 < V_242 )
V_241 = V_242 ;
return V_241 ;
}
