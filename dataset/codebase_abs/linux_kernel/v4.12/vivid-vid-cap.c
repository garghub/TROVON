static int F_1 ( struct V_1 * V_2 ,
unsigned * V_3 , unsigned * V_4 ,
unsigned V_5 [] , struct V_6 * V_7 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned V_10 = F_3 ( & V_9 -> V_11 ) ;
unsigned V_12 = V_9 -> V_13 . V_14 ;
unsigned V_15 ;
if ( V_9 -> V_16 == V_17 ) {
if ( F_4 ( V_2 ) )
return - V_18 ;
}
if ( V_9 -> V_19 ) {
V_9 -> V_19 = false ;
return - V_18 ;
}
if ( * V_4 ) {
if ( * V_4 != V_10 )
return - V_18 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
if ( V_5 [ V_15 ] < F_5 ( & V_9 -> V_11 , V_15 ) * V_12 +
V_9 -> V_20 -> V_21 [ V_15 ] )
return - V_18 ;
}
} else {
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ )
V_5 [ V_15 ] = F_5 ( & V_9 -> V_11 , V_15 ) * V_12 +
V_9 -> V_20 -> V_21 [ V_15 ] ;
}
if ( V_2 -> V_22 + * V_3 < 2 )
* V_3 = 2 - V_2 -> V_22 ;
* V_4 = V_10 ;
F_6 ( V_9 , 1 , L_1 , V_23 , * V_3 ) ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ )
F_6 ( V_9 , 1 , L_2 , V_23 , V_15 , V_5 [ V_15 ] ) ;
return 0 ;
}
static int F_7 ( struct V_24 * V_25 )
{
struct V_8 * V_9 = F_2 ( V_25 -> V_1 ) ;
unsigned long V_26 ;
unsigned V_10 = F_3 ( & V_9 -> V_11 ) ;
unsigned V_15 ;
F_6 ( V_9 , 1 , L_3 , V_23 ) ;
if ( F_8 ( NULL == V_9 -> V_20 ) )
return - V_18 ;
if ( V_9 -> V_27 ) {
V_9 -> V_27 = false ;
return - V_18 ;
}
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
V_26 = F_5 ( & V_9 -> V_11 , V_15 ) * V_9 -> V_13 . V_14 +
V_9 -> V_20 -> V_21 [ V_15 ] ;
if ( F_9 ( V_25 , V_15 ) < V_26 ) {
F_6 ( V_9 , 1 , L_4 ,
V_23 , V_15 , F_9 ( V_25 , V_15 ) , V_26 ) ;
return - V_18 ;
}
F_10 ( V_25 , V_15 , V_26 ) ;
V_25 -> V_28 [ V_15 ] . V_21 = V_9 -> V_20 -> V_21 [ V_15 ] ;
}
return 0 ;
}
static void F_11 ( struct V_24 * V_25 )
{
struct V_29 * V_30 = F_12 ( V_25 ) ;
struct V_8 * V_9 = F_2 ( V_25 -> V_1 ) ;
struct V_31 * V_32 = & V_30 -> V_33 ;
unsigned V_34 = 25 ;
unsigned V_35 = V_30 -> V_36 ;
if ( ! F_13 ( V_9 ) )
return;
V_30 -> V_37 |= V_38 ;
if ( V_9 -> V_39 & V_40 )
V_34 = 30 ;
V_32 -> type = ( V_34 == 30 ) ? V_41 : V_42 ;
V_32 -> V_37 = 0 ;
V_32 -> V_43 = V_35 % V_34 ;
V_32 -> V_44 = ( V_35 / V_34 ) % 60 ;
V_32 -> V_45 = ( V_35 / ( 60 * V_34 ) ) % 60 ;
V_32 -> V_46 = ( V_35 / ( 60 * 60 * V_34 ) ) % 24 ;
}
static void F_14 ( struct V_24 * V_25 )
{
struct V_29 * V_30 = F_12 ( V_25 ) ;
struct V_8 * V_9 = F_2 ( V_25 -> V_1 ) ;
struct V_47 * V_48 = F_15 ( V_30 , struct V_47 , V_25 ) ;
F_6 ( V_9 , 1 , L_3 , V_23 ) ;
F_16 ( & V_9 -> V_49 ) ;
F_17 ( & V_48 -> V_50 , & V_9 -> V_51 ) ;
F_18 ( & V_9 -> V_49 ) ;
}
static int F_19 ( struct V_1 * V_2 , unsigned V_52 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned V_53 ;
int V_54 ;
if ( F_20 ( & V_9 -> V_55 ) )
V_9 -> V_56 = F_21 ( V_9 ) ;
if ( V_9 -> V_57 )
return 0 ;
V_9 -> V_58 = 0 ;
F_6 ( V_9 , 1 , L_3 , V_23 ) ;
for ( V_53 = 0 ; V_53 < V_59 ; V_53 ++ )
V_9 -> V_60 [ V_53 ] = F_22 ( & V_9 -> V_11 ) < 100 ;
if ( V_9 -> V_61 ) {
V_9 -> V_61 = false ;
V_54 = - V_18 ;
} else {
V_54 = F_23 ( V_9 , & V_9 -> V_62 ) ;
}
if ( V_54 ) {
struct V_47 * V_48 , * V_63 ;
F_24 (buf, tmp, &dev->vid_cap_active, list) {
F_25 ( & V_48 -> V_50 ) ;
F_26 ( & V_48 -> V_25 . V_64 ,
V_65 ) ;
}
}
return V_54 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_6 ( V_9 , 1 , L_3 , V_23 ) ;
F_28 ( V_9 , & V_9 -> V_62 ) ;
V_9 -> V_56 = false ;
}
void F_29 ( struct V_8 * V_9 )
{
unsigned V_66 ;
if ( V_9 -> V_67 && ( F_30 ( V_9 ) || F_31 ( V_9 ) ) ) {
F_32 ( & V_9 -> V_11 , V_68 , 0 ) ;
return;
}
if ( F_31 ( V_9 ) && F_33 ( V_9 -> V_69 ) ) {
F_32 ( & V_9 -> V_11 , V_68 , 0 ) ;
return;
}
if ( F_13 ( V_9 ) && F_33 ( V_9 -> V_70 ) ) {
F_32 ( & V_9 -> V_11 , V_68 , 0 ) ;
return;
}
if ( ! F_34 ( V_9 ) ) {
F_32 ( & V_9 -> V_11 , V_71 , 0 ) ;
return;
}
V_66 = ( V_9 -> V_72 - 676 ) % ( 6 * 16 ) ;
if ( V_66 > 2 * 16 ) {
F_32 ( & V_9 -> V_11 , V_68 ,
F_35 ( V_9 -> V_72 ^ 0x55 ) & 0x3f ) ;
return;
}
if ( V_66 < 12 || V_66 > 20 )
F_32 ( & V_9 -> V_11 , V_73 , 0 ) ;
else
F_32 ( & V_9 -> V_11 , V_71 , 0 ) ;
}
static enum V_74 F_36 ( struct V_8 * V_9 , T_1 * V_75 )
{
unsigned V_66 ;
if ( V_75 )
* V_75 = 0 ;
if ( F_37 ( & V_9 -> V_11 ) == V_71 ||
F_37 ( & V_9 -> V_11 ) == V_68 )
return F_37 ( & V_9 -> V_11 ) ;
V_66 = ( V_9 -> V_72 - 676 ) % ( 6 * 16 ) ;
if ( V_75 )
* V_75 = V_66 - 1 * 16 ;
return V_73 ;
}
enum V_76 F_38 ( const struct V_8 * V_9 )
{
if ( F_13 ( V_9 ) )
return V_9 -> V_77 ;
if ( F_31 ( V_9 ) )
return V_9 -> V_78 ;
return V_79 ;
}
static enum V_80 F_39 ( const struct V_8 * V_9 )
{
if ( F_13 ( V_9 ) )
return ( V_9 -> V_39 & V_40 ) ?
V_81 : V_82 ;
if ( F_31 ( V_9 ) &&
V_9 -> V_83 . V_84 == 720 && V_9 -> V_83 . V_14 <= 576 )
return V_9 -> V_83 . V_14 == 480 ?
V_81 : V_82 ;
return V_85 ;
}
void F_40 ( struct V_8 * V_9 , bool V_86 )
{
struct V_87 * V_88 = & V_9 -> V_89 . V_88 ;
unsigned V_26 ;
T_2 V_90 ;
switch ( V_9 -> V_91 [ V_9 -> V_92 ] ) {
case V_93 :
default:
V_9 -> V_83 . V_84 = V_94 [ V_9 -> V_95 ] . V_84 ;
V_9 -> V_83 . V_14 = V_94 [ V_9 -> V_95 ] . V_14 ;
V_9 -> V_96 = V_97 [ V_9 -> V_98 ] ;
V_9 -> V_16 = V_99 ;
F_41 ( & V_9 -> V_11 , V_100 ) ;
break;
case V_101 :
case V_102 :
V_9 -> V_16 = V_9 -> V_103 ;
V_9 -> V_83 . V_84 = 720 ;
if ( V_9 -> V_39 & V_40 ) {
V_9 -> V_83 . V_14 = 480 ;
V_9 -> V_96 = (struct V_104 ) { 1001 , 30000 } ;
V_9 -> V_105 = V_106 ;
} else {
V_9 -> V_83 . V_14 = 576 ;
V_9 -> V_96 = (struct V_104 ) { 1000 , 25000 } ;
V_9 -> V_105 = V_107 | V_108 ;
}
F_41 ( & V_9 -> V_11 , V_100 ) ;
break;
case V_109 :
V_9 -> V_83 . V_84 = V_88 -> V_84 ;
V_9 -> V_83 . V_14 = V_88 -> V_14 ;
V_26 = F_42 ( V_88 ) * F_43 ( V_88 ) ;
if ( V_9 -> V_110 && F_44 ( V_88 ) ) {
V_90 = F_45 ( V_88 -> V_90 * 1000 , 1001 ) ;
V_88 -> V_37 |= V_111 ;
} else {
V_90 = V_88 -> V_90 ;
V_88 -> V_37 &= ~ V_111 ;
}
V_9 -> V_96 = (struct V_104 ) {
V_26 / 100 , ( V_112 ) V_90 / 100
} ;
if ( V_88 -> V_113 )
V_9 -> V_16 = V_17 ;
else
V_9 -> V_16 = V_99 ;
if ( V_86 || ! V_9 -> V_114 )
break;
if ( V_88 -> V_37 & V_115 ) {
if ( V_88 -> V_84 == 720 && V_88 -> V_14 <= 576 )
F_46 ( V_9 -> V_114 , V_116 ) ;
else
F_46 ( V_9 -> V_114 , V_117 ) ;
F_46 ( V_9 -> V_118 , 1 ) ;
} else {
F_46 ( V_9 -> V_114 , V_119 ) ;
F_46 ( V_9 -> V_118 , 0 ) ;
}
F_41 ( & V_9 -> V_11 , F_47 ( V_9 -> V_120 ) ) ;
break;
}
F_29 ( V_9 ) ;
F_48 ( & V_9 -> V_11 , V_9 -> V_83 . V_84 , V_9 -> V_83 . V_14 , V_9 -> V_16 ) ;
V_9 -> V_121 = V_9 -> V_83 ;
V_9 -> V_122 = V_9 -> V_83 ;
V_9 -> V_123 = V_9 -> V_121 ;
if ( F_49 ( V_9 -> V_16 ) )
V_9 -> V_123 . V_14 /= 2 ;
V_9 -> V_13 = V_9 -> V_123 ;
F_50 ( & V_9 -> V_11 , F_38 ( V_9 ) ) ;
F_51 ( & V_9 -> V_11 , F_39 ( V_9 ) ) ;
F_52 ( & V_9 -> V_11 ) ;
}
static enum V_124 F_53 ( struct V_8 * V_9 , enum V_124 V_125 )
{
if ( F_13 ( V_9 ) ) {
switch ( V_125 ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_17 :
return V_125 ;
case V_132 :
default:
return V_132 ;
}
}
if ( F_31 ( V_9 ) )
return V_9 -> V_89 . V_88 . V_113 ? V_17 :
V_99 ;
return V_99 ;
}
static unsigned F_54 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_67 || F_55 ( V_9 ) || F_34 ( V_9 ) )
return F_56 ( & V_9 -> V_11 ) ;
return V_9 -> V_133 ;
}
static unsigned F_57 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_67 || F_55 ( V_9 ) || F_34 ( V_9 ) )
return F_58 ( & V_9 -> V_11 ) ;
return V_9 -> V_134 ;
}
static unsigned F_59 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_67 || F_55 ( V_9 ) || F_34 ( V_9 ) )
return F_60 ( & V_9 -> V_11 ) ;
return V_9 -> V_135 ;
}
static unsigned int F_61 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_67 || F_55 ( V_9 ) || F_34 ( V_9 ) )
return F_62 ( & V_9 -> V_11 ) ;
return V_9 -> V_136 ;
}
static unsigned F_63 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_67 || F_55 ( V_9 ) || F_34 ( V_9 ) )
return F_64 ( & V_9 -> V_11 ) ;
return V_9 -> V_137 ;
}
int F_65 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
struct V_142 * V_143 = & V_141 -> V_144 . V_145 ;
unsigned V_15 ;
V_143 -> V_84 = V_9 -> V_13 . V_84 ;
V_143 -> V_14 = V_9 -> V_13 . V_14 ;
V_143 -> V_125 = V_9 -> V_16 ;
V_143 -> V_146 = V_9 -> V_20 -> V_147 ;
V_143 -> V_114 = F_54 ( V_9 ) ;
V_143 -> V_148 = F_57 ( V_9 ) ;
if ( V_9 -> V_20 -> V_149 == V_150 )
V_143 -> V_151 = F_61 ( V_9 ) ;
else
V_143 -> V_152 = F_59 ( V_9 ) ;
V_143 -> V_153 = F_63 ( V_9 ) ;
V_143 -> V_154 = V_9 -> V_20 -> V_10 ;
for ( V_15 = 0 ; V_15 < V_143 -> V_154 ; V_15 ++ ) {
V_143 -> V_155 [ V_15 ] . V_156 = F_67 ( & V_9 -> V_11 , V_15 ) ;
V_143 -> V_155 [ V_15 ] . V_157 =
F_5 ( & V_9 -> V_11 , V_15 ) * V_143 -> V_14 +
V_9 -> V_20 -> V_21 [ V_15 ] ;
}
return 0 ;
}
int F_68 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_142 * V_143 = & V_141 -> V_144 . V_145 ;
struct V_158 * V_159 = V_143 -> V_155 ;
struct V_8 * V_9 = F_66 ( V_138 ) ;
const struct V_160 * V_144 ;
unsigned V_156 , V_161 ;
unsigned V_162 = 1 ;
unsigned V_163 , V_12 ;
unsigned V_15 ;
V_144 = F_69 ( V_9 , V_143 -> V_146 ) ;
if ( ! V_144 ) {
F_6 ( V_9 , 1 , L_5 ,
V_143 -> V_146 ) ;
V_143 -> V_146 = V_164 ;
V_144 = F_69 ( V_9 , V_143 -> V_146 ) ;
}
V_143 -> V_125 = F_53 ( V_9 , V_143 -> V_125 ) ;
if ( F_55 ( V_9 ) ) {
const struct V_165 * V_166 =
F_70 ( & V_167 , V_143 -> V_84 , V_143 -> V_14 ) ;
V_163 = V_166 -> V_84 ;
V_12 = V_166 -> V_14 ;
} else if ( F_13 ( V_9 ) ) {
V_163 = 720 ;
V_12 = ( V_9 -> V_39 & V_40 ) ? 480 : 576 ;
} else {
V_163 = V_9 -> V_83 . V_84 ;
V_12 = V_9 -> V_83 . V_14 ;
}
if ( F_49 ( V_143 -> V_125 ) )
V_162 = 2 ;
if ( F_55 ( V_9 ) ||
( ! V_9 -> V_168 && ! V_9 -> V_169 && ! V_9 -> V_170 ) ) {
V_143 -> V_84 = V_163 ;
V_143 -> V_14 = V_12 / V_162 ;
} else {
struct V_171 V_172 = { 0 , 0 , V_143 -> V_84 , V_143 -> V_14 * V_162 } ;
F_71 ( & V_172 , & V_173 ) ;
F_72 ( & V_172 , & V_174 ) ;
if ( V_9 -> V_168 && ! V_9 -> V_170 ) {
struct V_171 V_175 = { 0 , 0 , V_176 * V_163 , V_176 * V_12 } ;
F_72 ( & V_172 , & V_175 ) ;
} else if ( ! V_9 -> V_168 && V_9 -> V_169 && ! V_9 -> V_170 ) {
F_72 ( & V_172 , & V_9 -> V_83 ) ;
} else if ( ! V_9 -> V_168 && ! V_9 -> V_169 ) {
F_71 ( & V_172 , & V_9 -> V_83 ) ;
}
V_143 -> V_84 = V_172 . V_84 ;
V_143 -> V_14 = V_172 . V_14 / V_162 ;
}
V_143 -> V_154 = V_144 -> V_10 ;
for ( V_15 = 0 ; V_15 < V_144 -> V_10 ; V_15 ++ ) {
V_156 = ( V_143 -> V_84 * V_144 -> V_177 [ V_15 ] ) >> 3 ;
V_161 = ( V_176 * V_178 * V_144 -> V_177 [ V_15 ] ) >> 3 ;
if ( V_159 [ V_15 ] . V_156 > V_161 )
V_159 [ V_15 ] . V_156 = V_161 ;
if ( V_159 [ V_15 ] . V_156 < V_156 )
V_159 [ V_15 ] . V_156 = V_156 ;
V_159 [ V_15 ] . V_157 = ( V_159 [ V_15 ] . V_156 * V_143 -> V_14 ) /
V_144 -> V_179 [ V_15 ] + V_144 -> V_21 [ V_15 ] ;
memset ( V_159 [ V_15 ] . V_180 , 0 , sizeof( V_159 [ V_15 ] . V_180 ) ) ;
}
for ( V_15 = V_144 -> V_10 ; V_15 < V_144 -> V_28 ; V_15 ++ )
V_159 [ 0 ] . V_157 += ( V_159 [ 0 ] . V_156 * V_143 -> V_14 *
( V_144 -> V_177 [ V_15 ] / V_144 -> V_179 [ V_15 ] ) ) /
( V_144 -> V_177 [ 0 ] / V_144 -> V_179 [ 0 ] ) ;
V_143 -> V_114 = F_54 ( V_9 ) ;
if ( V_144 -> V_149 == V_150 )
V_143 -> V_151 = F_61 ( V_9 ) ;
else
V_143 -> V_152 = F_59 ( V_9 ) ;
V_143 -> V_148 = F_57 ( V_9 ) ;
V_143 -> V_153 = F_63 ( V_9 ) ;
memset ( V_143 -> V_180 , 0 , sizeof( V_143 -> V_180 ) ) ;
return 0 ;
}
int F_73 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_142 * V_143 = & V_141 -> V_144 . V_145 ;
struct V_8 * V_9 = F_66 ( V_138 ) ;
struct V_171 * V_181 = & V_9 -> V_121 ;
struct V_171 * V_182 = & V_9 -> V_123 ;
struct V_1 * V_183 = & V_9 -> V_184 ;
int V_185 = F_68 ( V_138 , V_139 , V_141 ) ;
unsigned V_162 = 1 ;
unsigned V_15 ;
unsigned V_53 ;
if ( V_185 < 0 )
return V_185 ;
if ( F_74 ( V_183 ) ) {
F_6 ( V_9 , 1 , L_6 , V_23 ) ;
return - V_186 ;
}
if ( V_9 -> V_187 && V_9 -> V_188 . V_144 . V_146 != V_143 -> V_146 ) {
F_6 ( V_9 , 1 , L_7 ) ;
return - V_186 ;
}
V_9 -> V_20 = F_69 ( V_9 , V_143 -> V_146 ) ;
if ( F_49 ( V_143 -> V_125 ) )
V_162 = 2 ;
if ( ! F_55 ( V_9 ) &&
( V_9 -> V_168 || V_9 -> V_169 || V_9 -> V_170 ) ) {
struct V_171 V_172 = { 0 , 0 , V_143 -> V_84 , V_143 -> V_14 } ;
if ( V_9 -> V_168 ) {
if ( V_9 -> V_170 )
F_75 ( V_182 , & V_172 ) ;
else
* V_182 = V_172 ;
if ( V_9 -> V_169 && ! V_9 -> V_170 ) {
struct V_171 V_189 = {
0 , 0 ,
V_172 . V_84 / V_176 ,
V_162 * V_172 . V_14 / V_176
} ;
struct V_171 V_175 = {
0 , 0 ,
V_172 . V_84 * V_176 ,
V_162 * V_172 . V_14 * V_176
} ;
F_71 ( V_181 , & V_189 ) ;
F_72 ( V_181 , & V_175 ) ;
F_75 ( V_181 , & V_9 -> V_122 ) ;
} else if ( V_9 -> V_169 ) {
struct V_171 V_189 = {
0 , 0 ,
V_182 -> V_84 / V_176 ,
V_162 * V_182 -> V_14 / V_176
} ;
struct V_171 V_175 = {
0 , 0 ,
V_182 -> V_84 * V_176 ,
V_162 * V_182 -> V_14 * V_176
} ;
F_71 ( V_181 , & V_189 ) ;
F_72 ( V_181 , & V_175 ) ;
F_75 ( V_181 , & V_9 -> V_122 ) ;
}
} else if ( V_9 -> V_169 && ! V_9 -> V_170 ) {
V_172 . V_14 *= V_162 ;
F_76 ( V_181 , & V_172 ) ;
F_75 ( V_181 , & V_9 -> V_122 ) ;
V_172 = * V_181 ;
V_172 . V_14 /= V_162 ;
F_76 ( V_182 , & V_172 ) ;
} else if ( ! V_9 -> V_169 ) {
F_75 ( V_182 , & V_172 ) ;
} else {
V_172 . V_14 *= V_162 ;
F_72 ( V_181 , & V_172 ) ;
F_75 ( V_181 , & V_9 -> V_122 ) ;
V_182 -> V_190 *= V_162 ;
V_182 -> V_14 *= V_162 ;
F_76 ( V_182 , V_181 ) ;
F_75 ( V_182 , & V_172 ) ;
V_182 -> V_190 /= V_162 ;
V_182 -> V_14 /= V_162 ;
}
} else if ( F_55 ( V_9 ) ) {
for ( V_53 = 0 ; V_53 < F_77 ( V_94 ) ; V_53 ++ )
if ( V_94 [ V_53 ] . V_84 == V_143 -> V_84 &&
V_94 [ V_53 ] . V_14 == V_143 -> V_14 )
break;
V_9 -> V_95 = V_53 ;
if ( V_9 -> V_98 >= 2 * ( V_191 - V_53 ) )
V_9 -> V_98 = 2 * ( V_191 - V_53 ) - 1 ;
F_40 ( V_9 , false ) ;
} else {
struct V_171 V_172 = { 0 , 0 , V_143 -> V_84 , V_143 -> V_14 } ;
F_76 ( V_182 , & V_172 ) ;
V_172 . V_14 *= V_162 ;
F_76 ( V_181 , & V_172 ) ;
}
V_9 -> V_13 . V_84 = V_143 -> V_84 ;
V_9 -> V_13 . V_14 = V_143 -> V_14 ;
F_78 ( & V_9 -> V_11 , V_143 -> V_14 ) ;
F_79 ( & V_9 -> V_11 , V_9 -> V_20 -> V_147 ) ;
for ( V_15 = 0 ; V_15 < F_3 ( & V_9 -> V_11 ) ; V_15 ++ )
F_80 ( & V_9 -> V_11 , V_15 , V_143 -> V_155 [ V_15 ] . V_156 ) ;
V_9 -> V_16 = V_143 -> V_125 ;
if ( V_9 -> V_16 == V_17 )
F_81 ( & V_9 -> V_11 , V_130 , true ) ;
else
F_81 ( & V_9 -> V_11 , V_9 -> V_16 , false ) ;
F_82 ( & V_9 -> V_11 , & V_9 -> V_121 , & V_9 -> V_123 ) ;
if ( F_13 ( V_9 ) )
V_9 -> V_103 = V_143 -> V_125 ;
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
int F_83 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! V_9 -> V_192 )
return - V_193 ;
return F_65 ( V_138 , V_139 , V_141 ) ;
}
int F_84 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! V_9 -> V_192 )
return - V_193 ;
return F_68 ( V_138 , V_139 , V_141 ) ;
}
int F_85 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! V_9 -> V_192 )
return - V_193 ;
return F_73 ( V_138 , V_139 , V_141 ) ;
}
int F_86 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_9 -> V_192 )
return - V_193 ;
return F_87 ( V_138 , V_139 , V_141 , F_65 ) ;
}
int F_88 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_9 -> V_192 )
return - V_193 ;
return F_87 ( V_138 , V_139 , V_141 , F_68 ) ;
}
int F_89 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_9 -> V_192 )
return - V_193 ;
return F_87 ( V_138 , V_139 , V_141 , F_73 ) ;
}
int F_90 ( struct V_138 * V_138 , void * V_139 ,
struct V_194 * V_195 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! V_9 -> V_169 && ! V_9 -> V_170 )
return - V_193 ;
if ( V_195 -> type != V_196 )
return - V_18 ;
if ( F_55 ( V_9 ) )
return - V_197 ;
V_195 -> V_172 . V_198 = V_195 -> V_172 . V_190 = 0 ;
switch ( V_195 -> V_199 ) {
case V_200 :
if ( ! V_9 -> V_169 )
return - V_18 ;
V_195 -> V_172 = V_9 -> V_121 ;
break;
case V_201 :
case V_202 :
if ( ! V_9 -> V_169 )
return - V_18 ;
V_195 -> V_172 = V_9 -> V_83 ;
break;
case V_203 :
if ( ! V_9 -> V_170 )
return - V_18 ;
V_195 -> V_172 = V_174 ;
break;
case V_204 :
if ( ! V_9 -> V_170 )
return - V_18 ;
V_195 -> V_172 = V_9 -> V_123 ;
break;
case V_205 :
if ( ! V_9 -> V_170 )
return - V_18 ;
V_195 -> V_172 = V_9 -> V_13 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
int F_91 ( struct V_138 * V_138 , void * V_206 , struct V_194 * V_207 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
struct V_171 * V_181 = & V_9 -> V_121 ;
struct V_171 * V_182 = & V_9 -> V_123 ;
unsigned V_162 = F_49 ( V_9 -> V_16 ) ? 2 : 1 ;
int V_185 ;
if ( ! V_9 -> V_169 && ! V_9 -> V_170 )
return - V_193 ;
if ( V_207 -> type != V_196 )
return - V_18 ;
if ( F_55 ( V_9 ) )
return - V_197 ;
switch ( V_207 -> V_199 ) {
case V_200 :
if ( ! V_9 -> V_169 )
return - V_18 ;
V_185 = F_92 ( V_207 -> V_37 , & V_207 -> V_172 ) ;
if ( V_185 )
return V_185 ;
F_71 ( & V_207 -> V_172 , & V_173 ) ;
F_72 ( & V_207 -> V_172 , & V_9 -> V_83 ) ;
F_75 ( & V_207 -> V_172 , & V_9 -> V_122 ) ;
V_207 -> V_172 . V_190 /= V_162 ;
V_207 -> V_172 . V_14 /= V_162 ;
if ( V_9 -> V_168 ) {
struct V_171 V_144 = V_9 -> V_13 ;
struct V_171 V_208 = {
0 , 0 ,
V_207 -> V_172 . V_84 * V_176 ,
V_207 -> V_172 . V_14 * V_176
} ;
struct V_171 V_209 = {
0 , 0 ,
V_207 -> V_172 . V_84 / V_176 ,
V_207 -> V_172 . V_14 / V_176
} ;
F_71 ( & V_144 , & V_209 ) ;
if ( ! V_9 -> V_170 )
F_72 ( & V_144 , & V_208 ) ;
if ( ! F_93 ( & V_9 -> V_13 , & V_144 ) &&
F_74 ( & V_9 -> V_184 ) )
return - V_186 ;
if ( V_9 -> V_170 ) {
F_71 ( V_182 , & V_209 ) ;
F_72 ( V_182 , & V_208 ) ;
}
V_9 -> V_13 = V_144 ;
F_78 ( & V_9 -> V_11 , V_144 . V_14 ) ;
} else if ( V_9 -> V_170 ) {
struct V_171 V_144 = V_9 -> V_13 ;
F_71 ( & V_144 , & V_207 -> V_172 ) ;
if ( ! F_93 ( & V_9 -> V_13 , & V_144 ) &&
F_74 ( & V_9 -> V_184 ) )
return - V_186 ;
V_9 -> V_13 = V_144 ;
F_78 ( & V_9 -> V_11 , V_144 . V_14 ) ;
F_76 ( V_182 , & V_207 -> V_172 ) ;
F_75 ( V_182 , & V_9 -> V_13 ) ;
} else {
if ( ! F_93 ( & V_207 -> V_172 , & V_9 -> V_13 ) &&
F_74 ( & V_9 -> V_184 ) )
return - V_186 ;
F_76 ( & V_9 -> V_13 , & V_207 -> V_172 ) ;
F_76 ( V_182 , & V_207 -> V_172 ) ;
F_75 ( V_182 , & V_9 -> V_13 ) ;
F_78 ( & V_9 -> V_11 , V_9 -> V_13 . V_14 ) ;
}
V_207 -> V_172 . V_190 *= V_162 ;
V_207 -> V_172 . V_14 *= V_162 ;
* V_181 = V_207 -> V_172 ;
break;
case V_204 :
if ( ! V_9 -> V_170 )
return - V_18 ;
V_185 = F_92 ( V_207 -> V_37 , & V_207 -> V_172 ) ;
if ( V_185 )
return V_185 ;
F_71 ( & V_207 -> V_172 , & V_173 ) ;
F_72 ( & V_207 -> V_172 , & V_9 -> V_13 ) ;
if ( V_9 -> V_168 ) {
struct V_171 V_208 = {
0 , 0 ,
V_9 -> V_83 . V_84 * V_176 ,
( V_9 -> V_83 . V_14 / V_162 ) * V_176
} ;
F_72 ( & V_207 -> V_172 , & V_208 ) ;
if ( V_9 -> V_169 ) {
struct V_171 V_209 = {
0 , 0 ,
V_207 -> V_172 . V_84 / V_176 ,
( V_207 -> V_172 . V_14 * V_162 ) / V_176
} ;
struct V_171 V_208 = {
0 , 0 ,
V_207 -> V_172 . V_84 * V_176 ,
( V_207 -> V_172 . V_14 * V_162 ) * V_176
} ;
F_71 ( V_181 , & V_209 ) ;
F_72 ( V_181 , & V_208 ) ;
F_75 ( V_181 , & V_9 -> V_122 ) ;
}
} else if ( V_9 -> V_169 ) {
V_207 -> V_172 . V_190 *= V_162 ;
V_207 -> V_172 . V_14 *= V_162 ;
F_72 ( & V_207 -> V_172 , & V_9 -> V_83 ) ;
F_76 ( V_181 , & V_207 -> V_172 ) ;
F_75 ( V_181 , & V_9 -> V_122 ) ;
V_207 -> V_172 . V_190 /= V_162 ;
V_207 -> V_172 . V_14 /= V_162 ;
} else {
F_76 ( & V_207 -> V_172 , & V_9 -> V_83 ) ;
V_207 -> V_172 . V_14 /= V_162 ;
}
F_75 ( & V_207 -> V_172 , & V_9 -> V_13 ) ;
if ( V_9 -> V_210 && ( V_182 -> V_84 != V_207 -> V_172 . V_84 ||
V_182 -> V_14 != V_207 -> V_172 . V_14 ) ) {
F_94 ( V_9 -> V_210 ) ;
V_9 -> V_210 = NULL ;
}
* V_182 = V_207 -> V_172 ;
break;
default:
return - V_18 ;
}
F_82 ( & V_9 -> V_11 , V_181 , V_182 ) ;
return 0 ;
}
int F_95 ( struct V_138 * V_138 , void * V_139 ,
struct V_211 * V_212 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_212 -> type != V_196 )
return - V_18 ;
switch ( F_39 ( V_9 ) ) {
case V_81 :
V_212 -> V_213 . V_214 = 11 ;
V_212 -> V_213 . V_215 = 10 ;
break;
case V_82 :
V_212 -> V_213 . V_214 = 54 ;
V_212 -> V_213 . V_215 = 59 ;
break;
case V_85 :
V_212 -> V_213 . V_214 = 1 ;
V_212 -> V_213 . V_215 = 1 ;
break;
}
return 0 ;
}
int F_96 ( struct V_138 * V_138 , void * V_139 ,
struct V_216 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
const struct V_160 * V_144 ;
if ( V_9 -> V_192 )
return - V_193 ;
if ( V_141 -> V_217 >= F_77 ( V_218 ) )
return - V_18 ;
V_144 = & V_218 [ V_141 -> V_217 ] ;
V_141 -> V_146 = V_144 -> V_147 ;
return 0 ;
}
int F_97 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
const struct V_171 * V_182 = & V_9 -> V_123 ;
struct V_219 * V_220 = & V_141 -> V_144 . V_220 ;
unsigned V_221 = V_220 -> V_221 ;
if ( V_9 -> V_192 )
return - V_193 ;
V_220 -> V_163 . V_190 = V_9 -> V_222 ;
V_220 -> V_163 . V_198 = V_9 -> V_223 ;
V_220 -> V_163 . V_84 = V_182 -> V_84 ;
V_220 -> V_163 . V_14 = V_182 -> V_14 ;
V_220 -> V_125 = V_9 -> V_224 ;
V_220 -> V_221 = V_9 -> V_225 ;
if ( V_221 > V_9 -> V_225 )
V_221 = V_9 -> V_225 ;
if ( V_9 -> V_210 == NULL )
V_220 -> V_226 = NULL ;
else if ( V_220 -> V_226 ) {
if ( F_98 ( V_220 -> V_226 , V_9 -> V_210 ,
( ( V_182 -> V_84 + 7 ) / 8 ) * V_182 -> V_14 ) )
return - V_227 ;
}
if ( V_221 && V_220 -> V_228 ) {
if ( F_98 ( V_220 -> V_228 , V_9 -> V_229 ,
V_221 * sizeof( V_9 -> V_229 [ 0 ] ) ) )
return - V_227 ;
}
return 0 ;
}
int F_99 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
const struct V_171 * V_182 = & V_9 -> V_123 ;
struct V_219 * V_220 = & V_141 -> V_144 . V_220 ;
int V_53 , V_230 ;
if ( V_9 -> V_192 )
return - V_193 ;
V_220 -> V_163 . V_198 = F_100 ( int , V_220 -> V_163 . V_198 ,
- V_9 -> V_188 . V_144 . V_84 , V_9 -> V_188 . V_144 . V_84 ) ;
V_220 -> V_163 . V_190 = F_100 ( int , V_220 -> V_163 . V_190 ,
- V_9 -> V_188 . V_144 . V_14 , V_9 -> V_188 . V_144 . V_14 ) ;
V_220 -> V_163 . V_84 = V_182 -> V_84 ;
V_220 -> V_163 . V_14 = V_182 -> V_14 ;
if ( V_220 -> V_125 != V_131 && V_220 -> V_125 != V_130 )
V_220 -> V_125 = V_231 ;
V_220 -> V_232 = 0 ;
V_220 -> V_233 = 0 ;
if ( V_220 -> V_221 && ! V_220 -> V_228 )
V_220 -> V_221 = 0 ;
if ( V_220 -> V_221 > V_234 )
V_220 -> V_221 = V_234 ;
if ( V_220 -> V_221 ) {
if ( F_101 ( V_9 -> V_235 , V_220 -> V_228 ,
V_220 -> V_221 * sizeof( V_9 -> V_229 [ 0 ] ) ) )
return - V_227 ;
for ( V_53 = 0 ; V_53 < V_220 -> V_221 ; V_53 ++ ) {
struct V_171 * V_172 = & V_9 -> V_235 [ V_53 ] . V_236 ;
V_172 -> V_190 = F_100 ( T_1 , V_172 -> V_190 , 0 , V_9 -> V_188 . V_144 . V_14 - 1 ) ;
V_172 -> V_14 = F_100 ( T_1 , V_172 -> V_14 , 1 , V_9 -> V_188 . V_144 . V_14 - V_172 -> V_190 ) ;
V_172 -> V_198 = F_100 ( V_112 , V_172 -> V_198 , 0 , V_9 -> V_188 . V_144 . V_84 - 1 ) ;
V_172 -> V_84 = F_100 ( V_112 , V_172 -> V_84 , 1 , V_9 -> V_188 . V_144 . V_84 - V_172 -> V_198 ) ;
}
for ( V_53 = 0 ; V_53 < V_220 -> V_221 - 1 ; V_53 ++ ) {
struct V_171 * V_237 = & V_9 -> V_235 [ V_53 ] . V_236 ;
for ( V_230 = V_53 + 1 ; V_230 < V_220 -> V_221 ; V_230 ++ ) {
struct V_171 * V_238 = & V_9 -> V_235 [ V_230 ] . V_236 ;
if ( F_102 ( V_237 , V_238 ) )
return - V_18 ;
}
}
if ( F_98 ( V_220 -> V_228 , V_9 -> V_235 ,
V_220 -> V_221 * sizeof( V_9 -> V_229 [ 0 ] ) ) )
return - V_227 ;
}
return 0 ;
}
int F_103 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
const struct V_171 * V_182 = & V_9 -> V_123 ;
struct V_219 * V_220 = & V_141 -> V_144 . V_220 ;
int V_185 = F_99 ( V_138 , V_139 , V_141 ) ;
unsigned V_239 = ( ( V_182 -> V_84 + 7 ) / 8 ) * V_182 -> V_14 ;
unsigned V_240 = V_220 -> V_221 * sizeof( V_9 -> V_229 [ 0 ] ) ;
void * V_241 = NULL ;
if ( V_185 )
return V_185 ;
if ( V_220 -> V_226 ) {
V_241 = F_104 ( V_239 ) ;
if ( V_241 == NULL )
return - V_242 ;
if ( F_101 ( V_241 , V_220 -> V_226 , V_239 ) ) {
F_105 ( V_241 ) ;
return - V_227 ;
}
}
V_9 -> V_222 = V_220 -> V_163 . V_190 ;
V_9 -> V_223 = V_220 -> V_163 . V_198 ;
V_9 -> V_224 = V_220 -> V_125 ;
F_105 ( V_9 -> V_210 ) ;
V_9 -> V_210 = V_241 ;
V_9 -> V_225 = V_220 -> V_221 ;
if ( V_9 -> V_225 )
memcpy ( V_9 -> V_229 , V_9 -> V_235 , V_240 ) ;
return 0 ;
}
int F_106 ( struct V_138 * V_138 , void * V_206 , unsigned V_53 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_9 -> V_192 )
return - V_193 ;
if ( V_53 && V_9 -> V_243 == NULL )
return - V_18 ;
if ( V_53 && V_9 -> V_188 . V_144 . V_146 != V_9 -> V_20 -> V_147 ) {
F_6 ( V_9 , 1 , L_8 ) ;
return - V_18 ;
}
if ( V_9 -> V_187 && V_9 -> V_187 != V_206 )
return - V_186 ;
V_9 -> V_187 = V_53 ? V_206 : NULL ;
return 0 ;
}
int F_107 ( struct V_138 * V_138 , void * V_206 ,
struct V_244 * V_245 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_9 -> V_192 )
return - V_193 ;
* V_245 = V_9 -> V_188 ;
V_245 -> V_246 = V_247 |
V_248 ;
V_245 -> V_37 = V_249 ;
V_245 -> V_144 . V_125 = V_99 ;
V_245 -> V_144 . V_114 = V_250 ;
V_245 -> V_144 . V_139 = 0 ;
return 0 ;
}
int F_108 ( struct V_138 * V_138 , void * V_206 ,
const struct V_244 * V_245 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
const struct V_160 * V_144 ;
if ( V_9 -> V_192 )
return - V_193 ;
if ( ! F_109 ( V_251 ) && ! F_109 ( V_252 ) )
return - V_253 ;
if ( V_9 -> V_187 )
return - V_186 ;
if ( V_245 -> V_254 == NULL ) {
V_9 -> V_188 . V_254 = NULL ;
V_9 -> V_243 = NULL ;
return 0 ;
}
if ( V_245 -> V_144 . V_84 < 48 || V_245 -> V_144 . V_14 < 32 )
return - V_18 ;
V_144 = F_69 ( V_9 , V_245 -> V_144 . V_146 ) ;
if ( ! V_144 || ! V_144 -> V_255 )
return - V_18 ;
if ( V_245 -> V_144 . V_156 < ( V_245 -> V_144 . V_84 * V_144 -> V_177 [ 0 ] ) / 8 )
return - V_18 ;
if ( V_245 -> V_144 . V_14 * V_245 -> V_144 . V_156 < V_245 -> V_144 . V_157 )
return - V_18 ;
V_9 -> V_243 = F_110 ( ( unsigned long ) V_245 -> V_254 ) ;
V_9 -> V_188 = * V_245 ;
V_9 -> V_223 = F_100 ( int , V_9 -> V_223 ,
- V_9 -> V_188 . V_144 . V_84 , V_9 -> V_188 . V_144 . V_84 ) ;
V_9 -> V_222 = F_100 ( int , V_9 -> V_222 ,
- V_9 -> V_188 . V_144 . V_14 , V_9 -> V_188 . V_144 . V_14 ) ;
return 0 ;
}
int F_111 ( struct V_138 * V_138 , void * V_139 ,
struct V_256 * V_257 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_257 -> V_217 >= V_9 -> V_258 )
return - V_18 ;
V_257 -> type = V_259 ;
switch ( V_9 -> V_91 [ V_257 -> V_217 ] ) {
case V_93 :
snprintf ( V_257 -> V_260 , sizeof( V_257 -> V_260 ) , L_9 ,
V_9 -> V_261 [ V_257 -> V_217 ] ) ;
V_257 -> V_262 = 0 ;
break;
case V_101 :
snprintf ( V_257 -> V_260 , sizeof( V_257 -> V_260 ) , L_10 ,
V_9 -> V_261 [ V_257 -> V_217 ] ) ;
V_257 -> type = V_263 ;
V_257 -> V_264 = V_265 ;
if ( V_9 -> V_266 )
V_257 -> V_267 = ( 1 << F_77 ( V_268 ) ) - 1 ;
V_257 -> V_262 = V_269 ;
break;
case V_102 :
snprintf ( V_257 -> V_260 , sizeof( V_257 -> V_260 ) , L_11 ,
V_9 -> V_261 [ V_257 -> V_217 ] ) ;
V_257 -> V_264 = V_265 ;
if ( V_9 -> V_266 )
V_257 -> V_267 = ( 1 << F_77 ( V_268 ) ) - 1 ;
V_257 -> V_262 = V_269 ;
break;
case V_109 :
snprintf ( V_257 -> V_260 , sizeof( V_257 -> V_260 ) , L_12 ,
V_9 -> V_261 [ V_257 -> V_217 ] ) ;
V_257 -> V_262 = V_270 ;
if ( V_9 -> V_271 == 0 ||
V_9 -> V_69 == V_272 )
V_257 -> V_273 |= V_274 ;
else if ( V_9 -> V_69 == V_275 ||
V_9 -> V_69 == V_276 )
V_257 -> V_273 |= V_277 ;
break;
}
if ( V_9 -> V_278 )
V_257 -> V_273 |= V_279 ;
if ( V_9 -> V_280 )
V_257 -> V_273 |= V_281 ;
if ( V_9 -> V_92 == V_257 -> V_217 && F_13 ( V_9 ) ) {
if ( V_9 -> V_70 == V_272 ) {
V_257 -> V_273 |= V_274 ;
} else if ( V_9 -> V_70 == V_275 ) {
V_257 -> V_273 |= V_277 ;
} else if ( F_34 ( V_9 ) ) {
switch ( F_37 ( & V_9 -> V_11 ) ) {
case V_73 :
V_257 -> V_273 |= V_282 ;
break;
case V_68 :
V_257 -> V_273 |= V_277 ;
break;
default:
break;
}
}
}
return 0 ;
}
int F_112 ( struct V_138 * V_138 , void * V_139 , unsigned * V_53 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
* V_53 = V_9 -> V_92 ;
return 0 ;
}
int F_113 ( struct V_138 * V_138 , void * V_139 , unsigned V_53 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
struct V_87 * V_88 = & V_9 -> V_89 . V_88 ;
unsigned V_283 ;
if ( V_53 >= V_9 -> V_258 )
return - V_18 ;
if ( V_53 == V_9 -> V_92 )
return 0 ;
if ( F_74 ( & V_9 -> V_184 ) || F_74 ( & V_9 -> V_284 ) )
return - V_186 ;
V_9 -> V_92 = V_53 ;
V_9 -> V_285 . V_286 = 0 ;
if ( V_9 -> V_91 [ V_53 ] == V_101 || V_9 -> V_91 [ V_53 ] == V_102 ) {
V_9 -> V_287 = ( V_9 -> V_91 [ V_53 ] == V_101 ) ? 0 : 1 ;
V_9 -> V_285 . V_286 = V_265 ;
}
V_9 -> V_288 . V_286 = V_9 -> V_285 . V_286 ;
F_40 ( V_9 , false ) ;
if ( V_9 -> V_114 ) {
switch ( V_9 -> V_91 [ V_53 ] ) {
case V_93 :
F_46 ( V_9 -> V_114 , V_119 ) ;
break;
case V_101 :
case V_102 :
F_46 ( V_9 -> V_114 , V_116 ) ;
break;
case V_109 :
if ( V_88 -> V_37 & V_115 ) {
if ( V_9 -> V_83 . V_84 == 720 && V_9 -> V_83 . V_14 <= 576 )
F_46 ( V_9 -> V_114 , V_116 ) ;
else
F_46 ( V_9 -> V_114 , V_117 ) ;
} else {
F_46 ( V_9 -> V_114 , V_119 ) ;
}
break;
}
}
V_283 = 128 * V_53 + V_9 -> V_289 [ V_53 ] ;
F_114 ( V_9 -> V_283 ,
128 * V_53 , 255 + 128 * V_53 , 1 , 128 + 128 * V_53 ) ;
F_46 ( V_9 -> V_283 , V_283 ) ;
return 0 ;
}
int F_115 ( struct V_138 * V_138 , void * V_206 , struct V_290 * V_291 )
{
if ( V_291 -> V_217 >= F_77 ( V_268 ) )
return - V_18 ;
* V_291 = V_268 [ V_291 -> V_217 ] ;
return 0 ;
}
int F_116 ( struct V_138 * V_138 , void * V_206 , struct V_290 * V_291 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! F_13 ( V_9 ) )
return - V_18 ;
* V_291 = V_268 [ V_9 -> V_287 ] ;
return 0 ;
}
int F_117 ( struct V_138 * V_138 , void * V_206 , const struct V_290 * V_291 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! F_13 ( V_9 ) )
return - V_18 ;
if ( V_291 -> V_217 >= F_77 ( V_268 ) )
return - V_18 ;
V_9 -> V_287 = V_291 -> V_217 ;
return 0 ;
}
int F_118 ( struct V_138 * V_138 , void * V_206 , struct V_292 * V_293 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_293 -> V_294 != 0 )
return - V_18 ;
V_293 -> V_295 = V_9 -> V_72 ;
return 0 ;
}
int F_119 ( struct V_138 * V_138 , void * V_206 , const struct V_292 * V_293 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_293 -> V_294 != 0 )
return - V_18 ;
V_9 -> V_72 = F_100 ( unsigned , V_293 -> V_295 , V_296 , V_297 ) ;
if ( F_34 ( V_9 ) )
F_29 ( V_9 ) ;
return 0 ;
}
int F_120 ( struct V_138 * V_138 , void * V_206 , const struct V_298 * V_299 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_299 -> V_217 != 0 )
return - V_18 ;
if ( V_299 -> V_300 > V_301 )
return - V_18 ;
V_9 -> V_302 = V_299 -> V_300 ;
return 0 ;
}
int F_121 ( struct V_138 * V_138 , void * V_206 , struct V_298 * V_299 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
enum V_74 V_303 ;
if ( V_299 -> V_217 != 0 )
return - V_18 ;
V_299 -> V_246 = V_304 | V_305 |
V_306 | V_307 ;
V_299 -> V_300 = V_9 -> V_302 ;
V_299 -> V_308 = V_296 ;
V_299 -> V_309 = V_297 ;
V_303 = F_36 ( V_9 , & V_299 -> V_75 ) ;
if ( V_303 == V_71 )
V_299 -> signal = 0xffff ;
else if ( V_303 == V_73 )
V_299 -> signal = 0x8000 ;
else
V_299 -> signal = 0 ;
if ( V_303 == V_68 ) {
V_299 -> V_310 = 0 ;
} else if ( V_303 == V_73 ) {
V_299 -> V_310 = V_311 ;
} else {
unsigned V_312 = V_9 -> V_72 / ( 6 * 16 ) ;
unsigned V_313 = ( V_9 -> V_39 & V_314 ) ? 4 : 3 ;
switch ( V_312 % V_313 ) {
case 0 :
V_299 -> V_310 = V_311 ;
break;
case 1 :
V_299 -> V_310 = V_315 ;
break;
case 2 :
if ( V_9 -> V_39 & V_314 )
V_299 -> V_310 = V_311 | V_316 ;
else
V_299 -> V_310 = V_317 | V_318 ;
break;
case 3 :
V_299 -> V_310 = V_315 | V_316 ;
break;
}
}
F_122 ( V_299 -> V_260 , L_13 , sizeof( V_299 -> V_260 ) ) ;
return 0 ;
}
int F_123 ( struct V_138 * V_138 , void * V_139 , T_3 * V_319 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! F_13 ( V_9 ) )
return - V_197 ;
if ( V_9 -> V_70 == V_272 ||
V_9 -> V_70 == V_275 ) {
* V_319 = V_320 ;
return 0 ;
}
if ( F_34 ( V_9 ) && F_37 ( & V_9 -> V_11 ) == V_68 ) {
* V_319 = V_320 ;
} else if ( V_9 -> V_70 == V_321 ) {
* V_319 = V_9 -> V_39 ;
} else if ( V_9 -> V_70 == V_322 ) {
* V_319 = V_9 -> V_323 ;
} else {
* V_319 = V_324 [ V_9 -> V_325 ] ;
V_9 -> V_325 = ( V_9 -> V_325 + 1 ) % F_77 ( V_324 ) ;
}
return 0 ;
}
int F_124 ( struct V_138 * V_138 , void * V_139 , T_3 V_319 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! F_13 ( V_9 ) )
return - V_197 ;
if ( V_9 -> V_39 == V_319 )
return 0 ;
if ( F_74 ( & V_9 -> V_184 ) || F_74 ( & V_9 -> V_284 ) )
return - V_186 ;
V_9 -> V_39 = V_319 ;
F_40 ( V_9 , false ) ;
return 0 ;
}
static void F_125 ( V_112 V_84 , V_112 V_14 ,
V_112 * V_326 , V_112 * V_327 )
{
if ( ! ( V_14 % 3 ) && ( ( V_14 * 4 / 3 ) == V_84 ) ) {
* V_326 = 4 ;
* V_327 = 3 ;
} else if ( ! ( V_14 % 9 ) && ( ( V_14 * 16 / 9 ) == V_84 ) ) {
* V_326 = 16 ;
* V_327 = 9 ;
} else if ( ! ( V_14 % 10 ) && ( ( V_14 * 16 / 10 ) == V_84 ) ) {
* V_326 = 16 ;
* V_327 = 10 ;
} else if ( ! ( V_14 % 4 ) && ( ( V_14 * 5 / 4 ) == V_84 ) ) {
* V_326 = 5 ;
* V_327 = 4 ;
} else if ( ! ( V_14 % 9 ) && ( ( V_14 * 15 / 9 ) == V_84 ) ) {
* V_326 = 15 ;
* V_327 = 9 ;
} else {
* V_326 = 16 ;
* V_327 = 9 ;
}
}
static bool F_126 ( struct V_328 * V_329 )
{
struct V_87 * V_88 = & V_329 -> V_88 ;
V_112 V_330 ;
V_112 V_331 ;
V_112 V_332 ;
if ( ! F_127 ( V_329 , & V_333 ,
NULL , NULL ) )
return false ;
V_330 = F_42 ( V_88 ) ;
V_331 = F_43 ( V_88 ) ;
V_332 = ( V_112 ) V_88 -> V_90 / V_330 ;
if ( V_88 -> V_334 == 0 || ( V_88 -> V_334 & V_335 ) ) {
if ( F_128 ( V_331 , V_332 , V_88 -> V_336 , V_88 -> V_84 ,
V_88 -> V_337 , V_88 -> V_113 , V_329 ) )
return true ;
}
if ( V_88 -> V_334 == 0 || ( V_88 -> V_334 & V_338 ) ) {
struct V_104 V_339 ;
F_125 ( V_88 -> V_84 , V_88 -> V_14 ,
& V_339 . V_214 ,
& V_339 . V_215 ) ;
if ( F_129 ( V_331 , V_332 , V_88 -> V_336 ,
V_88 -> V_337 , V_88 -> V_113 ,
V_339 , V_329 ) )
return true ;
}
return false ;
}
int F_130 ( struct V_138 * V_138 , void * V_340 ,
struct V_328 * V_329 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! F_31 ( V_9 ) )
return - V_197 ;
if ( ! F_131 ( V_329 , & V_333 ,
0 , NULL , NULL ) &&
! F_126 ( V_329 ) )
return - V_18 ;
if ( F_132 ( V_329 , & V_9 -> V_89 , 0 , false ) )
return 0 ;
if ( F_74 ( & V_9 -> V_184 ) )
return - V_186 ;
V_9 -> V_89 = * V_329 ;
F_40 ( V_9 , false ) ;
return 0 ;
}
int F_133 ( struct V_138 * V_138 , void * V_340 ,
struct V_328 * V_329 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! F_31 ( V_9 ) )
return - V_197 ;
if ( V_9 -> V_69 == V_272 ||
V_9 -> V_271 == 0 )
return - V_341 ;
if ( V_9 -> V_69 == V_275 )
return - V_342 ;
if ( V_9 -> V_69 == V_276 ) {
V_329 -> V_88 . V_90 = V_333 . V_88 . V_343 * 2 ;
return - V_344 ;
}
if ( V_9 -> V_69 == V_345 ) {
* V_329 = V_9 -> V_89 ;
} else if ( V_9 -> V_69 == V_346 ) {
* V_329 = V_347 [ V_9 -> V_348 ] ;
} else {
* V_329 = V_347 [ V_9 -> V_349 ] ;
V_9 -> V_349 = ( V_9 -> V_349 + 1 ) %
V_9 -> V_350 ;
}
return 0 ;
}
int F_134 ( struct V_138 * V_138 , void * V_340 ,
struct V_351 * V_352 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
T_4 V_353 ;
unsigned int V_53 ;
int V_185 ;
memset ( V_352 -> V_180 , 0 , sizeof( V_352 -> V_180 ) ) ;
if ( V_352 -> V_354 >= V_9 -> V_258 )
return - V_18 ;
if ( V_9 -> V_91 [ V_352 -> V_354 ] != V_109 || V_352 -> V_355 )
return - V_18 ;
if ( V_352 -> V_356 == 0 ) {
V_9 -> V_271 = 0 ;
V_353 = V_357 ;
goto V_358;
}
if ( V_352 -> V_356 > V_9 -> V_359 ) {
V_352 -> V_356 = V_9 -> V_359 ;
return - V_360 ;
}
V_353 = F_135 ( V_352 -> V_352 , V_352 -> V_356 * 128 , NULL ) ;
V_185 = F_136 ( V_353 , & V_353 , NULL ) ;
if ( V_185 )
return V_185 ;
if ( F_74 ( & V_9 -> V_184 ) )
return - V_186 ;
V_9 -> V_271 = V_352 -> V_356 ;
memcpy ( V_9 -> V_352 , V_352 -> V_352 , V_352 -> V_356 * 128 ) ;
V_358:
F_137 ( V_9 -> V_361 , V_353 , false ) ;
for ( V_53 = 0 ; V_53 < V_362 && V_9 -> V_363 [ V_53 ] ; V_53 ++ )
F_137 ( V_9 -> V_363 [ V_53 ] ,
F_138 ( V_353 , V_53 + 1 ) ,
false ) ;
return 0 ;
}
int F_139 ( struct V_138 * V_138 , void * V_206 ,
struct V_364 * V_365 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( ! F_55 ( V_9 ) && ! V_9 -> V_168 )
return - V_18 ;
if ( F_69 ( V_9 , V_365 -> V_366 ) == NULL )
return - V_18 ;
if ( F_55 ( V_9 ) ) {
if ( V_365 -> V_217 >= F_77 ( V_94 ) )
return - V_18 ;
V_365 -> type = V_367 ;
V_365 -> V_368 = V_94 [ V_365 -> V_217 ] ;
return 0 ;
}
if ( V_365 -> V_217 )
return - V_18 ;
V_365 -> type = V_369 ;
V_365 -> V_370 . V_371 = V_372 ;
V_365 -> V_370 . V_373 = V_178 * V_176 ;
V_365 -> V_370 . V_374 = 2 ;
V_365 -> V_370 . V_375 = V_376 ;
V_365 -> V_370 . V_377 = V_378 * V_176 ;
V_365 -> V_370 . V_379 = 2 ;
return 0 ;
}
int F_140 ( struct V_138 * V_138 , void * V_139 ,
struct V_380 * V_381 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
const struct V_160 * V_144 ;
int V_53 ;
V_144 = F_69 ( V_9 , V_381 -> V_366 ) ;
if ( ! V_144 )
return - V_18 ;
if ( ! F_55 ( V_9 ) ) {
if ( V_381 -> V_217 )
return - V_18 ;
if ( V_381 -> V_84 < V_372 || V_381 -> V_84 > V_178 * V_176 )
return - V_18 ;
if ( V_381 -> V_14 < V_376 || V_381 -> V_14 > V_378 * V_176 )
return - V_18 ;
V_381 -> type = V_382 ;
V_381 -> V_368 = V_9 -> V_96 ;
return 0 ;
}
for ( V_53 = 0 ; V_53 < F_77 ( V_94 ) ; V_53 ++ )
if ( V_381 -> V_84 == V_94 [ V_53 ] . V_84 &&
V_381 -> V_14 == V_94 [ V_53 ] . V_14 )
break;
if ( V_53 == F_77 ( V_94 ) )
return - V_18 ;
if ( V_381 -> V_217 >= 2 * ( V_191 - V_53 ) )
return - V_18 ;
V_381 -> type = V_382 ;
V_381 -> V_368 = V_97 [ V_381 -> V_217 ] ;
return 0 ;
}
int F_141 ( struct V_138 * V_138 , void * V_139 ,
struct V_383 * V_384 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
if ( V_384 -> type != ( V_9 -> V_192 ?
V_385 :
V_196 ) )
return - V_18 ;
V_384 -> V_384 . V_386 . V_246 = V_387 ;
V_384 -> V_384 . V_386 . V_388 = V_9 -> V_96 ;
V_384 -> V_384 . V_386 . V_389 = 1 ;
return 0 ;
}
int F_142 ( struct V_138 * V_138 , void * V_139 ,
struct V_383 * V_384 )
{
struct V_8 * V_9 = F_66 ( V_138 ) ;
unsigned V_390 = 2 * ( V_191 - V_9 -> V_95 ) ;
struct V_104 V_391 ;
unsigned V_53 ;
if ( V_384 -> type != ( V_9 -> V_192 ?
V_385 :
V_196 ) )
return - V_18 ;
if ( ! F_55 ( V_9 ) )
return F_141 ( V_138 , V_139 , V_384 ) ;
V_391 = V_384 -> V_384 . V_386 . V_388 ;
if ( V_391 . V_215 == 0 )
V_391 = V_97 [ V_390 - 1 ] ;
for ( V_53 = 0 ; V_53 < V_390 ; V_53 ++ )
if ( F_143 ( V_391 , >= , V_97 [ V_53 ] ) )
break;
if ( V_53 == V_390 )
V_53 = V_390 - 1 ;
V_9 -> V_98 = V_53 ;
V_391 = V_97 [ V_9 -> V_98 ] ;
V_391 = F_143 ( V_391 , < , V_392 ) ? V_392 : V_391 ;
V_391 = F_143 ( V_391 , > , V_393 ) ? V_393 : V_391 ;
V_9 -> V_394 = true ;
V_9 -> V_96 = V_391 ;
V_384 -> V_384 . V_386 . V_246 = V_387 ;
V_384 -> V_384 . V_386 . V_388 = V_391 ;
V_384 -> V_384 . V_386 . V_389 = 1 ;
return 0 ;
}
