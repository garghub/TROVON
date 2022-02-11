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
static unsigned F_61 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_67 || F_55 ( V_9 ) || F_34 ( V_9 ) )
return F_62 ( & V_9 -> V_11 ) ;
return V_9 -> V_136 ;
}
int F_63 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
struct V_141 * V_142 = & V_140 -> V_143 . V_144 ;
unsigned V_15 ;
V_142 -> V_84 = V_9 -> V_13 . V_84 ;
V_142 -> V_14 = V_9 -> V_13 . V_14 ;
V_142 -> V_125 = V_9 -> V_16 ;
V_142 -> V_145 = V_9 -> V_20 -> V_146 ;
V_142 -> V_114 = F_54 ( V_9 ) ;
V_142 -> V_147 = F_57 ( V_9 ) ;
V_142 -> V_148 = F_59 ( V_9 ) ;
V_142 -> V_149 = F_61 ( V_9 ) ;
V_142 -> V_150 = V_9 -> V_20 -> V_10 ;
for ( V_15 = 0 ; V_15 < V_142 -> V_150 ; V_15 ++ ) {
V_142 -> V_151 [ V_15 ] . V_152 = F_65 ( & V_9 -> V_11 , V_15 ) ;
V_142 -> V_151 [ V_15 ] . V_153 =
F_5 ( & V_9 -> V_11 , V_15 ) * V_142 -> V_14 +
V_9 -> V_20 -> V_21 [ V_15 ] ;
}
return 0 ;
}
int F_66 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_141 * V_142 = & V_140 -> V_143 . V_144 ;
struct V_154 * V_155 = V_142 -> V_151 ;
struct V_8 * V_9 = F_64 ( V_137 ) ;
const struct V_156 * V_143 ;
unsigned V_152 , V_157 ;
unsigned V_158 = 1 ;
unsigned V_159 , V_12 ;
unsigned V_15 ;
V_143 = F_67 ( V_9 , V_142 -> V_145 ) ;
if ( ! V_143 ) {
F_6 ( V_9 , 1 , L_5 ,
V_142 -> V_145 ) ;
V_142 -> V_145 = V_160 ;
V_143 = F_67 ( V_9 , V_142 -> V_145 ) ;
}
V_142 -> V_125 = F_53 ( V_9 , V_142 -> V_125 ) ;
if ( F_55 ( V_9 ) ) {
const struct V_161 * V_162 =
F_68 ( & V_163 , V_142 -> V_84 , V_142 -> V_14 ) ;
V_159 = V_162 -> V_84 ;
V_12 = V_162 -> V_14 ;
} else if ( F_13 ( V_9 ) ) {
V_159 = 720 ;
V_12 = ( V_9 -> V_39 & V_40 ) ? 480 : 576 ;
} else {
V_159 = V_9 -> V_83 . V_84 ;
V_12 = V_9 -> V_83 . V_14 ;
}
if ( F_49 ( V_142 -> V_125 ) )
V_158 = 2 ;
if ( F_55 ( V_9 ) ||
( ! V_9 -> V_164 && ! V_9 -> V_165 && ! V_9 -> V_166 ) ) {
V_142 -> V_84 = V_159 ;
V_142 -> V_14 = V_12 / V_158 ;
} else {
struct V_167 V_168 = { 0 , 0 , V_142 -> V_84 , V_142 -> V_14 * V_158 } ;
F_69 ( & V_168 , & V_169 ) ;
F_70 ( & V_168 , & V_170 ) ;
if ( V_9 -> V_164 && ! V_9 -> V_166 ) {
struct V_167 V_171 = { 0 , 0 , V_172 * V_159 , V_172 * V_12 } ;
F_70 ( & V_168 , & V_171 ) ;
} else if ( ! V_9 -> V_164 && V_9 -> V_165 && ! V_9 -> V_166 ) {
F_70 ( & V_168 , & V_9 -> V_83 ) ;
} else if ( ! V_9 -> V_164 && ! V_9 -> V_165 ) {
F_69 ( & V_168 , & V_9 -> V_83 ) ;
}
V_142 -> V_84 = V_168 . V_84 ;
V_142 -> V_14 = V_168 . V_14 / V_158 ;
}
V_142 -> V_150 = V_143 -> V_10 ;
for ( V_15 = 0 ; V_15 < V_142 -> V_150 ; V_15 ++ ) {
V_152 = ( V_142 -> V_84 * V_143 -> V_173 [ V_15 ] ) >> 3 ;
V_157 = ( V_172 * V_174 * V_143 -> V_173 [ V_15 ] ) >> 3 ;
if ( V_155 [ V_15 ] . V_152 > V_157 )
V_155 [ V_15 ] . V_152 = V_157 ;
if ( V_155 [ V_15 ] . V_152 < V_152 )
V_155 [ V_15 ] . V_152 = V_152 ;
V_155 [ V_15 ] . V_153 = F_71 ( & V_9 -> V_11 , V_15 , V_155 [ V_15 ] . V_152 ) *
V_142 -> V_14 + V_143 -> V_21 [ V_15 ] ;
memset ( V_155 [ V_15 ] . V_175 , 0 , sizeof( V_155 [ V_15 ] . V_175 ) ) ;
}
V_142 -> V_114 = F_54 ( V_9 ) ;
V_142 -> V_148 = F_59 ( V_9 ) ;
V_142 -> V_147 = F_57 ( V_9 ) ;
V_142 -> V_149 = F_61 ( V_9 ) ;
memset ( V_142 -> V_175 , 0 , sizeof( V_142 -> V_175 ) ) ;
return 0 ;
}
int F_72 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_141 * V_142 = & V_140 -> V_143 . V_144 ;
struct V_8 * V_9 = F_64 ( V_137 ) ;
struct V_167 * V_176 = & V_9 -> V_121 ;
struct V_167 * V_177 = & V_9 -> V_123 ;
struct V_1 * V_178 = & V_9 -> V_179 ;
int V_180 = F_66 ( V_137 , V_138 , V_140 ) ;
unsigned V_158 = 1 ;
unsigned V_15 ;
unsigned V_53 ;
if ( V_180 < 0 )
return V_180 ;
if ( F_73 ( V_178 ) ) {
F_6 ( V_9 , 1 , L_6 , V_23 ) ;
return - V_181 ;
}
if ( V_9 -> V_182 && V_9 -> V_183 . V_143 . V_145 != V_142 -> V_145 ) {
F_6 ( V_9 , 1 , L_7 ) ;
return - V_181 ;
}
V_9 -> V_20 = F_67 ( V_9 , V_142 -> V_145 ) ;
if ( F_49 ( V_142 -> V_125 ) )
V_158 = 2 ;
if ( ! F_55 ( V_9 ) &&
( V_9 -> V_164 || V_9 -> V_165 || V_9 -> V_166 ) ) {
struct V_167 V_168 = { 0 , 0 , V_142 -> V_84 , V_142 -> V_14 } ;
if ( V_9 -> V_164 ) {
if ( V_9 -> V_166 )
F_74 ( V_177 , & V_168 ) ;
else
* V_177 = V_168 ;
if ( V_9 -> V_165 && ! V_9 -> V_166 ) {
struct V_167 V_184 = {
0 , 0 ,
V_168 . V_84 / V_172 ,
V_158 * V_168 . V_14 / V_172
} ;
struct V_167 V_171 = {
0 , 0 ,
V_168 . V_84 * V_172 ,
V_158 * V_168 . V_14 * V_172
} ;
F_69 ( V_176 , & V_184 ) ;
F_70 ( V_176 , & V_171 ) ;
F_74 ( V_176 , & V_9 -> V_122 ) ;
} else if ( V_9 -> V_165 ) {
struct V_167 V_184 = {
0 , 0 ,
V_177 -> V_84 / V_172 ,
V_158 * V_177 -> V_14 / V_172
} ;
struct V_167 V_171 = {
0 , 0 ,
V_177 -> V_84 * V_172 ,
V_158 * V_177 -> V_14 * V_172
} ;
F_69 ( V_176 , & V_184 ) ;
F_70 ( V_176 , & V_171 ) ;
F_74 ( V_176 , & V_9 -> V_122 ) ;
}
} else if ( V_9 -> V_165 && ! V_9 -> V_166 ) {
V_168 . V_14 *= V_158 ;
F_75 ( V_176 , & V_168 ) ;
F_74 ( V_176 , & V_9 -> V_122 ) ;
V_168 = * V_176 ;
V_168 . V_14 /= V_158 ;
F_75 ( V_177 , & V_168 ) ;
} else if ( ! V_9 -> V_165 ) {
F_74 ( V_177 , & V_168 ) ;
} else {
V_168 . V_14 *= V_158 ;
F_70 ( V_176 , & V_168 ) ;
F_74 ( V_176 , & V_9 -> V_122 ) ;
V_177 -> V_185 *= V_158 ;
V_177 -> V_14 *= V_158 ;
F_75 ( V_177 , V_176 ) ;
F_74 ( V_177 , & V_168 ) ;
V_177 -> V_185 /= V_158 ;
V_177 -> V_14 /= V_158 ;
}
} else if ( F_55 ( V_9 ) ) {
for ( V_53 = 0 ; V_53 < F_76 ( V_94 ) ; V_53 ++ )
if ( V_94 [ V_53 ] . V_84 == V_142 -> V_84 &&
V_94 [ V_53 ] . V_14 == V_142 -> V_14 )
break;
V_9 -> V_95 = V_53 ;
if ( V_9 -> V_98 >= 2 * ( V_186 - V_53 ) )
V_9 -> V_98 = 2 * ( V_186 - V_53 ) - 1 ;
F_40 ( V_9 , false ) ;
} else {
struct V_167 V_168 = { 0 , 0 , V_142 -> V_84 , V_142 -> V_14 } ;
F_75 ( V_177 , & V_168 ) ;
V_168 . V_14 *= V_158 ;
F_75 ( V_176 , & V_168 ) ;
}
V_9 -> V_13 . V_84 = V_142 -> V_84 ;
V_9 -> V_13 . V_14 = V_142 -> V_14 ;
F_77 ( & V_9 -> V_11 , V_142 -> V_14 ) ;
F_78 ( & V_9 -> V_11 , V_9 -> V_20 -> V_146 ) ;
for ( V_15 = 0 ; V_15 < F_3 ( & V_9 -> V_11 ) ; V_15 ++ )
F_79 ( & V_9 -> V_11 , V_15 , V_142 -> V_151 [ V_15 ] . V_152 ) ;
V_9 -> V_16 = V_142 -> V_125 ;
if ( V_9 -> V_16 == V_17 )
F_80 ( & V_9 -> V_11 , V_130 , true ) ;
else
F_80 ( & V_9 -> V_11 , V_9 -> V_16 , false ) ;
F_81 ( & V_9 -> V_11 , & V_9 -> V_121 , & V_9 -> V_123 ) ;
if ( F_13 ( V_9 ) )
V_9 -> V_103 = V_142 -> V_125 ;
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
int F_82 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! V_9 -> V_187 )
return - V_188 ;
return F_63 ( V_137 , V_138 , V_140 ) ;
}
int F_83 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! V_9 -> V_187 )
return - V_188 ;
return F_66 ( V_137 , V_138 , V_140 ) ;
}
int F_84 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! V_9 -> V_187 )
return - V_188 ;
return F_72 ( V_137 , V_138 , V_140 ) ;
}
int F_85 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_9 -> V_187 )
return - V_188 ;
return F_86 ( V_137 , V_138 , V_140 , F_63 ) ;
}
int F_87 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_9 -> V_187 )
return - V_188 ;
return F_86 ( V_137 , V_138 , V_140 , F_66 ) ;
}
int F_88 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_9 -> V_187 )
return - V_188 ;
return F_86 ( V_137 , V_138 , V_140 , F_72 ) ;
}
int F_89 ( struct V_137 * V_137 , void * V_138 ,
struct V_189 * V_190 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! V_9 -> V_165 && ! V_9 -> V_166 )
return - V_188 ;
if ( V_190 -> type != V_191 )
return - V_18 ;
if ( F_55 ( V_9 ) )
return - V_18 ;
V_190 -> V_168 . V_192 = V_190 -> V_168 . V_185 = 0 ;
switch ( V_190 -> V_193 ) {
case V_194 :
if ( ! V_9 -> V_165 )
return - V_18 ;
V_190 -> V_168 = V_9 -> V_121 ;
break;
case V_195 :
case V_196 :
if ( ! V_9 -> V_165 )
return - V_18 ;
V_190 -> V_168 = V_9 -> V_83 ;
break;
case V_197 :
if ( ! V_9 -> V_166 )
return - V_18 ;
V_190 -> V_168 = V_170 ;
break;
case V_198 :
if ( ! V_9 -> V_166 )
return - V_18 ;
V_190 -> V_168 = V_9 -> V_123 ;
break;
case V_199 :
if ( ! V_9 -> V_166 )
return - V_18 ;
V_190 -> V_168 = V_9 -> V_13 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
int F_90 ( struct V_137 * V_137 , void * V_200 , struct V_189 * V_201 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
struct V_167 * V_176 = & V_9 -> V_121 ;
struct V_167 * V_177 = & V_9 -> V_123 ;
unsigned V_158 = F_49 ( V_9 -> V_16 ) ? 2 : 1 ;
int V_180 ;
if ( ! V_9 -> V_165 && ! V_9 -> V_166 )
return - V_188 ;
if ( V_201 -> type != V_191 )
return - V_18 ;
if ( F_55 ( V_9 ) )
return - V_18 ;
switch ( V_201 -> V_193 ) {
case V_194 :
if ( ! V_9 -> V_165 )
return - V_18 ;
V_180 = F_91 ( V_201 -> V_37 , & V_201 -> V_168 ) ;
if ( V_180 )
return V_180 ;
F_69 ( & V_201 -> V_168 , & V_169 ) ;
F_70 ( & V_201 -> V_168 , & V_9 -> V_83 ) ;
F_74 ( & V_201 -> V_168 , & V_9 -> V_122 ) ;
V_201 -> V_168 . V_185 /= V_158 ;
V_201 -> V_168 . V_14 /= V_158 ;
if ( V_9 -> V_164 ) {
struct V_167 V_143 = V_9 -> V_13 ;
struct V_167 V_202 = {
0 , 0 ,
V_201 -> V_168 . V_84 * V_172 ,
V_201 -> V_168 . V_14 * V_172
} ;
struct V_167 V_203 = {
0 , 0 ,
V_201 -> V_168 . V_84 / V_172 ,
V_201 -> V_168 . V_14 / V_172
} ;
F_69 ( & V_143 , & V_203 ) ;
if ( ! V_9 -> V_166 )
F_70 ( & V_143 , & V_202 ) ;
if ( ! F_92 ( & V_9 -> V_13 , & V_143 ) &&
F_73 ( & V_9 -> V_179 ) )
return - V_181 ;
if ( V_9 -> V_166 ) {
F_69 ( V_177 , & V_203 ) ;
F_70 ( V_177 , & V_202 ) ;
}
V_9 -> V_13 = V_143 ;
F_77 ( & V_9 -> V_11 , V_143 . V_14 ) ;
} else if ( V_9 -> V_166 ) {
struct V_167 V_143 = V_9 -> V_13 ;
F_69 ( & V_143 , & V_201 -> V_168 ) ;
if ( ! F_92 ( & V_9 -> V_13 , & V_143 ) &&
F_73 ( & V_9 -> V_179 ) )
return - V_181 ;
V_9 -> V_13 = V_143 ;
F_77 ( & V_9 -> V_11 , V_143 . V_14 ) ;
F_75 ( V_177 , & V_201 -> V_168 ) ;
F_74 ( V_177 , & V_9 -> V_13 ) ;
} else {
if ( ! F_92 ( & V_201 -> V_168 , & V_9 -> V_13 ) &&
F_73 ( & V_9 -> V_179 ) )
return - V_181 ;
F_75 ( & V_9 -> V_13 , & V_201 -> V_168 ) ;
F_75 ( V_177 , & V_201 -> V_168 ) ;
F_74 ( V_177 , & V_9 -> V_13 ) ;
F_77 ( & V_9 -> V_11 , V_9 -> V_13 . V_14 ) ;
}
V_201 -> V_168 . V_185 *= V_158 ;
V_201 -> V_168 . V_14 *= V_158 ;
* V_176 = V_201 -> V_168 ;
break;
case V_198 :
if ( ! V_9 -> V_166 )
return - V_18 ;
V_180 = F_91 ( V_201 -> V_37 , & V_201 -> V_168 ) ;
if ( V_180 )
return V_180 ;
F_69 ( & V_201 -> V_168 , & V_169 ) ;
F_70 ( & V_201 -> V_168 , & V_9 -> V_13 ) ;
if ( V_9 -> V_164 ) {
struct V_167 V_202 = {
0 , 0 ,
V_9 -> V_83 . V_84 * V_172 ,
( V_9 -> V_83 . V_14 / V_158 ) * V_172
} ;
F_70 ( & V_201 -> V_168 , & V_202 ) ;
if ( V_9 -> V_165 ) {
struct V_167 V_203 = {
0 , 0 ,
V_201 -> V_168 . V_84 / V_172 ,
( V_201 -> V_168 . V_14 * V_158 ) / V_172
} ;
struct V_167 V_202 = {
0 , 0 ,
V_201 -> V_168 . V_84 * V_172 ,
( V_201 -> V_168 . V_14 * V_158 ) * V_172
} ;
F_69 ( V_176 , & V_203 ) ;
F_70 ( V_176 , & V_202 ) ;
F_74 ( V_176 , & V_9 -> V_122 ) ;
}
} else if ( V_9 -> V_165 ) {
V_201 -> V_168 . V_185 *= V_158 ;
V_201 -> V_168 . V_14 *= V_158 ;
F_70 ( & V_201 -> V_168 , & V_9 -> V_83 ) ;
F_75 ( V_176 , & V_201 -> V_168 ) ;
F_74 ( V_176 , & V_9 -> V_122 ) ;
V_201 -> V_168 . V_185 /= V_158 ;
V_201 -> V_168 . V_14 /= V_158 ;
} else {
F_75 ( & V_201 -> V_168 , & V_9 -> V_83 ) ;
V_201 -> V_168 . V_14 /= V_158 ;
}
F_74 ( & V_201 -> V_168 , & V_9 -> V_13 ) ;
if ( V_9 -> V_204 && ( V_177 -> V_84 != V_201 -> V_168 . V_84 ||
V_177 -> V_14 != V_201 -> V_168 . V_14 ) ) {
F_93 ( V_9 -> V_204 ) ;
V_9 -> V_204 = NULL ;
}
* V_177 = V_201 -> V_168 ;
break;
default:
return - V_18 ;
}
F_81 ( & V_9 -> V_11 , V_176 , V_177 ) ;
return 0 ;
}
int F_94 ( struct V_137 * V_137 , void * V_138 ,
struct V_205 * V_206 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_206 -> type != V_191 )
return - V_18 ;
switch ( F_39 ( V_9 ) ) {
case V_81 :
V_206 -> V_207 . V_208 = 11 ;
V_206 -> V_207 . V_209 = 10 ;
break;
case V_82 :
V_206 -> V_207 . V_208 = 54 ;
V_206 -> V_207 . V_209 = 59 ;
break;
case V_85 :
V_206 -> V_207 . V_208 = 1 ;
V_206 -> V_207 . V_209 = 1 ;
break;
}
return 0 ;
}
int F_95 ( struct V_137 * V_137 , void * V_138 ,
struct V_210 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
const struct V_156 * V_143 ;
if ( V_9 -> V_187 )
return - V_188 ;
if ( V_140 -> V_211 >= F_76 ( V_212 ) )
return - V_18 ;
V_143 = & V_212 [ V_140 -> V_211 ] ;
V_140 -> V_145 = V_143 -> V_146 ;
return 0 ;
}
int F_96 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
const struct V_167 * V_177 = & V_9 -> V_123 ;
struct V_213 * V_214 = & V_140 -> V_143 . V_214 ;
unsigned V_215 = V_214 -> V_215 ;
if ( V_9 -> V_187 )
return - V_188 ;
V_214 -> V_159 . V_185 = V_9 -> V_216 ;
V_214 -> V_159 . V_192 = V_9 -> V_217 ;
V_214 -> V_159 . V_84 = V_177 -> V_84 ;
V_214 -> V_159 . V_14 = V_177 -> V_14 ;
V_214 -> V_125 = V_9 -> V_218 ;
V_214 -> V_215 = V_9 -> V_219 ;
if ( V_215 > V_9 -> V_219 )
V_215 = V_9 -> V_219 ;
if ( V_9 -> V_204 == NULL )
V_214 -> V_220 = NULL ;
else if ( V_214 -> V_220 ) {
if ( F_97 ( V_214 -> V_220 , V_9 -> V_204 ,
( ( V_177 -> V_84 + 7 ) / 8 ) * V_177 -> V_14 ) )
return - V_221 ;
}
if ( V_215 && V_214 -> V_222 ) {
if ( F_97 ( V_214 -> V_222 , V_9 -> V_223 ,
V_215 * sizeof( V_9 -> V_223 [ 0 ] ) ) )
return - V_221 ;
}
return 0 ;
}
int F_98 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
const struct V_167 * V_177 = & V_9 -> V_123 ;
struct V_213 * V_214 = & V_140 -> V_143 . V_214 ;
int V_53 , V_224 ;
if ( V_9 -> V_187 )
return - V_188 ;
V_214 -> V_159 . V_192 = F_99 ( int , V_214 -> V_159 . V_192 ,
- V_9 -> V_183 . V_143 . V_84 , V_9 -> V_183 . V_143 . V_84 ) ;
V_214 -> V_159 . V_185 = F_99 ( int , V_214 -> V_159 . V_185 ,
- V_9 -> V_183 . V_143 . V_14 , V_9 -> V_183 . V_143 . V_14 ) ;
V_214 -> V_159 . V_84 = V_177 -> V_84 ;
V_214 -> V_159 . V_14 = V_177 -> V_14 ;
if ( V_214 -> V_125 != V_131 && V_214 -> V_125 != V_130 )
V_214 -> V_125 = V_225 ;
V_214 -> V_226 = 0 ;
V_214 -> V_227 = 0 ;
if ( V_214 -> V_215 && ! V_214 -> V_222 )
V_214 -> V_215 = 0 ;
if ( V_214 -> V_215 > V_228 )
V_214 -> V_215 = V_228 ;
if ( V_214 -> V_215 ) {
if ( F_100 ( V_9 -> V_229 , V_214 -> V_222 ,
V_214 -> V_215 * sizeof( V_9 -> V_223 [ 0 ] ) ) )
return - V_221 ;
for ( V_53 = 0 ; V_53 < V_214 -> V_215 ; V_53 ++ ) {
struct V_167 * V_168 = & V_9 -> V_229 [ V_53 ] . V_230 ;
V_168 -> V_185 = F_99 ( T_1 , V_168 -> V_185 , 0 , V_9 -> V_183 . V_143 . V_14 - 1 ) ;
V_168 -> V_14 = F_99 ( T_1 , V_168 -> V_14 , 1 , V_9 -> V_183 . V_143 . V_14 - V_168 -> V_185 ) ;
V_168 -> V_192 = F_99 ( V_112 , V_168 -> V_192 , 0 , V_9 -> V_183 . V_143 . V_84 - 1 ) ;
V_168 -> V_84 = F_99 ( V_112 , V_168 -> V_84 , 1 , V_9 -> V_183 . V_143 . V_84 - V_168 -> V_192 ) ;
}
for ( V_53 = 0 ; V_53 < V_214 -> V_215 - 1 ; V_53 ++ ) {
struct V_167 * V_231 = & V_9 -> V_229 [ V_53 ] . V_230 ;
for ( V_224 = V_53 + 1 ; V_224 < V_214 -> V_215 ; V_224 ++ ) {
struct V_167 * V_232 = & V_9 -> V_229 [ V_224 ] . V_230 ;
if ( F_101 ( V_231 , V_232 ) )
return - V_18 ;
}
}
if ( F_97 ( V_214 -> V_222 , V_9 -> V_229 ,
V_214 -> V_215 * sizeof( V_9 -> V_223 [ 0 ] ) ) )
return - V_221 ;
}
return 0 ;
}
int F_102 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
const struct V_167 * V_177 = & V_9 -> V_123 ;
struct V_213 * V_214 = & V_140 -> V_143 . V_214 ;
int V_180 = F_98 ( V_137 , V_138 , V_140 ) ;
unsigned V_233 = ( ( V_177 -> V_84 + 7 ) / 8 ) * V_177 -> V_14 ;
unsigned V_234 = V_214 -> V_215 * sizeof( V_9 -> V_223 [ 0 ] ) ;
void * V_235 = NULL ;
if ( V_180 )
return V_180 ;
if ( V_214 -> V_220 ) {
V_235 = F_103 ( V_233 ) ;
if ( V_235 == NULL )
return - V_236 ;
if ( F_100 ( V_235 , V_214 -> V_220 , V_233 ) ) {
F_104 ( V_235 ) ;
return - V_221 ;
}
}
V_9 -> V_216 = V_214 -> V_159 . V_185 ;
V_9 -> V_217 = V_214 -> V_159 . V_192 ;
V_9 -> V_218 = V_214 -> V_125 ;
F_104 ( V_9 -> V_204 ) ;
V_9 -> V_204 = V_235 ;
V_9 -> V_219 = V_214 -> V_215 ;
if ( V_9 -> V_219 )
memcpy ( V_9 -> V_223 , V_9 -> V_229 , V_234 ) ;
return 0 ;
}
int F_105 ( struct V_137 * V_137 , void * V_200 , unsigned V_53 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_9 -> V_187 )
return - V_188 ;
if ( V_53 && V_9 -> V_237 == NULL )
return - V_18 ;
if ( V_53 && V_9 -> V_183 . V_143 . V_145 != V_9 -> V_20 -> V_146 ) {
F_6 ( V_9 , 1 , L_8 ) ;
return - V_18 ;
}
if ( V_9 -> V_182 && V_9 -> V_182 != V_200 )
return - V_181 ;
V_9 -> V_182 = V_53 ? V_200 : NULL ;
return 0 ;
}
int F_106 ( struct V_137 * V_137 , void * V_200 ,
struct V_238 * V_239 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_9 -> V_187 )
return - V_188 ;
* V_239 = V_9 -> V_183 ;
V_239 -> V_240 = V_241 |
V_242 ;
V_239 -> V_37 = V_243 ;
V_239 -> V_143 . V_125 = V_99 ;
V_239 -> V_143 . V_114 = V_244 ;
V_239 -> V_143 . V_138 = 0 ;
return 0 ;
}
int F_107 ( struct V_137 * V_137 , void * V_200 ,
const struct V_238 * V_239 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
const struct V_156 * V_143 ;
if ( V_9 -> V_187 )
return - V_188 ;
if ( ! F_108 ( V_245 ) && ! F_108 ( V_246 ) )
return - V_247 ;
if ( V_9 -> V_182 )
return - V_181 ;
if ( V_239 -> V_248 == NULL ) {
V_9 -> V_183 . V_248 = NULL ;
V_9 -> V_237 = NULL ;
return 0 ;
}
if ( V_239 -> V_143 . V_84 < 48 || V_239 -> V_143 . V_14 < 32 )
return - V_18 ;
V_143 = F_67 ( V_9 , V_239 -> V_143 . V_145 ) ;
if ( ! V_143 || ! V_143 -> V_249 )
return - V_18 ;
if ( V_239 -> V_143 . V_152 < ( V_239 -> V_143 . V_84 * V_143 -> V_173 [ 0 ] ) / 8 )
return - V_18 ;
if ( V_239 -> V_143 . V_14 * V_239 -> V_143 . V_152 < V_239 -> V_143 . V_153 )
return - V_18 ;
V_9 -> V_237 = F_109 ( ( unsigned long ) V_239 -> V_248 ) ;
V_9 -> V_183 = * V_239 ;
V_9 -> V_217 = F_99 ( int , V_9 -> V_217 ,
- V_9 -> V_183 . V_143 . V_84 , V_9 -> V_183 . V_143 . V_84 ) ;
V_9 -> V_216 = F_99 ( int , V_9 -> V_216 ,
- V_9 -> V_183 . V_143 . V_14 , V_9 -> V_183 . V_143 . V_14 ) ;
return 0 ;
}
int F_110 ( struct V_137 * V_137 , void * V_138 ,
struct V_250 * V_251 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_251 -> V_211 >= V_9 -> V_252 )
return - V_18 ;
V_251 -> type = V_253 ;
switch ( V_9 -> V_91 [ V_251 -> V_211 ] ) {
case V_93 :
snprintf ( V_251 -> V_254 , sizeof( V_251 -> V_254 ) , L_9 ,
V_9 -> V_255 [ V_251 -> V_211 ] ) ;
V_251 -> V_256 = 0 ;
break;
case V_101 :
snprintf ( V_251 -> V_254 , sizeof( V_251 -> V_254 ) , L_10 ,
V_9 -> V_255 [ V_251 -> V_211 ] ) ;
V_251 -> type = V_257 ;
V_251 -> V_258 = V_259 ;
if ( V_9 -> V_260 )
V_251 -> V_261 = ( 1 << F_76 ( V_262 ) ) - 1 ;
V_251 -> V_256 = V_263 ;
break;
case V_102 :
snprintf ( V_251 -> V_254 , sizeof( V_251 -> V_254 ) , L_11 ,
V_9 -> V_255 [ V_251 -> V_211 ] ) ;
V_251 -> V_258 = V_259 ;
if ( V_9 -> V_260 )
V_251 -> V_261 = ( 1 << F_76 ( V_262 ) ) - 1 ;
V_251 -> V_256 = V_263 ;
break;
case V_109 :
snprintf ( V_251 -> V_254 , sizeof( V_251 -> V_254 ) , L_12 ,
V_9 -> V_255 [ V_251 -> V_211 ] ) ;
V_251 -> V_256 = V_264 ;
if ( V_9 -> V_265 == 0 ||
V_9 -> V_69 == V_266 )
V_251 -> V_267 |= V_268 ;
else if ( V_9 -> V_69 == V_269 ||
V_9 -> V_69 == V_270 )
V_251 -> V_267 |= V_271 ;
break;
}
if ( V_9 -> V_272 )
V_251 -> V_267 |= V_273 ;
if ( V_9 -> V_274 )
V_251 -> V_267 |= V_275 ;
if ( V_9 -> V_92 == V_251 -> V_211 && F_13 ( V_9 ) ) {
if ( V_9 -> V_70 == V_266 ) {
V_251 -> V_267 |= V_268 ;
} else if ( V_9 -> V_70 == V_269 ) {
V_251 -> V_267 |= V_271 ;
} else if ( F_34 ( V_9 ) ) {
switch ( F_37 ( & V_9 -> V_11 ) ) {
case V_73 :
V_251 -> V_267 |= V_276 ;
break;
case V_68 :
V_251 -> V_267 |= V_271 ;
break;
default:
break;
}
}
}
return 0 ;
}
int F_111 ( struct V_137 * V_137 , void * V_138 , unsigned * V_53 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
* V_53 = V_9 -> V_92 ;
return 0 ;
}
int F_112 ( struct V_137 * V_137 , void * V_138 , unsigned V_53 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
struct V_87 * V_88 = & V_9 -> V_89 . V_88 ;
unsigned V_277 ;
if ( V_53 >= V_9 -> V_252 )
return - V_18 ;
if ( V_53 == V_9 -> V_92 )
return 0 ;
if ( F_73 ( & V_9 -> V_179 ) || F_73 ( & V_9 -> V_278 ) )
return - V_181 ;
V_9 -> V_92 = V_53 ;
V_9 -> V_279 . V_280 = 0 ;
if ( V_9 -> V_91 [ V_53 ] == V_101 || V_9 -> V_91 [ V_53 ] == V_102 ) {
V_9 -> V_281 = ( V_9 -> V_91 [ V_53 ] == V_101 ) ? 0 : 1 ;
V_9 -> V_279 . V_280 = V_259 ;
}
V_9 -> V_282 . V_280 = V_9 -> V_279 . V_280 ;
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
V_277 = 128 * V_53 + V_9 -> V_283 [ V_53 ] ;
F_113 ( V_9 -> V_277 ,
128 * V_53 , 255 + 128 * V_53 , 1 , 128 + 128 * V_53 ) ;
F_46 ( V_9 -> V_277 , V_277 ) ;
return 0 ;
}
int F_114 ( struct V_137 * V_137 , void * V_200 , struct V_284 * V_285 )
{
if ( V_285 -> V_211 >= F_76 ( V_262 ) )
return - V_18 ;
* V_285 = V_262 [ V_285 -> V_211 ] ;
return 0 ;
}
int F_115 ( struct V_137 * V_137 , void * V_200 , struct V_284 * V_285 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! F_13 ( V_9 ) )
return - V_18 ;
* V_285 = V_262 [ V_9 -> V_281 ] ;
return 0 ;
}
int F_116 ( struct V_137 * V_137 , void * V_200 , const struct V_284 * V_285 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! F_13 ( V_9 ) )
return - V_18 ;
if ( V_285 -> V_211 >= F_76 ( V_262 ) )
return - V_18 ;
V_9 -> V_281 = V_285 -> V_211 ;
return 0 ;
}
int F_117 ( struct V_137 * V_137 , void * V_200 , struct V_286 * V_287 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_287 -> V_288 != 0 )
return - V_18 ;
V_287 -> V_289 = V_9 -> V_72 ;
return 0 ;
}
int F_118 ( struct V_137 * V_137 , void * V_200 , const struct V_286 * V_287 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_287 -> V_288 != 0 )
return - V_18 ;
V_9 -> V_72 = F_99 ( unsigned , V_287 -> V_289 , V_290 , V_291 ) ;
if ( F_34 ( V_9 ) )
F_29 ( V_9 ) ;
return 0 ;
}
int F_119 ( struct V_137 * V_137 , void * V_200 , const struct V_292 * V_293 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_293 -> V_211 != 0 )
return - V_18 ;
if ( V_293 -> V_294 > V_295 )
return - V_18 ;
V_9 -> V_296 = V_293 -> V_294 ;
return 0 ;
}
int F_120 ( struct V_137 * V_137 , void * V_200 , struct V_292 * V_293 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
enum V_74 V_297 ;
if ( V_293 -> V_211 != 0 )
return - V_18 ;
V_293 -> V_240 = V_298 | V_299 |
V_300 | V_301 ;
V_293 -> V_294 = V_9 -> V_296 ;
V_293 -> V_302 = V_290 ;
V_293 -> V_303 = V_291 ;
V_297 = F_36 ( V_9 , & V_293 -> V_75 ) ;
if ( V_297 == V_71 )
V_293 -> signal = 0xffff ;
else if ( V_297 == V_73 )
V_293 -> signal = 0x8000 ;
else
V_293 -> signal = 0 ;
if ( V_297 == V_68 ) {
V_293 -> V_304 = 0 ;
} else if ( V_297 == V_73 ) {
V_293 -> V_304 = V_305 ;
} else {
unsigned V_306 = V_9 -> V_72 / ( 6 * 16 ) ;
unsigned V_307 = ( V_9 -> V_39 & V_308 ) ? 4 : 3 ;
switch ( V_306 % V_307 ) {
case 0 :
V_293 -> V_304 = V_305 ;
break;
case 1 :
V_293 -> V_304 = V_309 ;
break;
case 2 :
if ( V_9 -> V_39 & V_308 )
V_293 -> V_304 = V_305 | V_310 ;
else
V_293 -> V_304 = V_311 | V_312 ;
break;
case 3 :
V_293 -> V_304 = V_309 | V_310 ;
break;
}
}
F_121 ( V_293 -> V_254 , L_13 , sizeof( V_293 -> V_254 ) ) ;
return 0 ;
}
int F_122 ( struct V_137 * V_137 , void * V_138 , T_3 * V_313 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! F_13 ( V_9 ) )
return - V_314 ;
if ( V_9 -> V_70 == V_266 ||
V_9 -> V_70 == V_269 ) {
* V_313 = V_315 ;
return 0 ;
}
if ( F_34 ( V_9 ) && F_37 ( & V_9 -> V_11 ) == V_68 ) {
* V_313 = V_315 ;
} else if ( V_9 -> V_70 == V_316 ) {
* V_313 = V_9 -> V_39 ;
} else if ( V_9 -> V_70 == V_317 ) {
* V_313 = V_9 -> V_318 ;
} else {
* V_313 = V_319 [ V_9 -> V_320 ] ;
V_9 -> V_320 = ( V_9 -> V_320 + 1 ) % F_76 ( V_319 ) ;
}
return 0 ;
}
int F_123 ( struct V_137 * V_137 , void * V_138 , T_3 V_313 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! F_13 ( V_9 ) )
return - V_314 ;
if ( V_9 -> V_39 == V_313 )
return 0 ;
if ( F_73 ( & V_9 -> V_179 ) || F_73 ( & V_9 -> V_278 ) )
return - V_181 ;
V_9 -> V_39 = V_313 ;
F_40 ( V_9 , false ) ;
return 0 ;
}
static void F_124 ( V_112 V_84 , V_112 V_14 ,
V_112 * V_321 , V_112 * V_322 )
{
if ( ! ( V_14 % 3 ) && ( ( V_14 * 4 / 3 ) == V_84 ) ) {
* V_321 = 4 ;
* V_322 = 3 ;
} else if ( ! ( V_14 % 9 ) && ( ( V_14 * 16 / 9 ) == V_84 ) ) {
* V_321 = 16 ;
* V_322 = 9 ;
} else if ( ! ( V_14 % 10 ) && ( ( V_14 * 16 / 10 ) == V_84 ) ) {
* V_321 = 16 ;
* V_322 = 10 ;
} else if ( ! ( V_14 % 4 ) && ( ( V_14 * 5 / 4 ) == V_84 ) ) {
* V_321 = 5 ;
* V_322 = 4 ;
} else if ( ! ( V_14 % 9 ) && ( ( V_14 * 15 / 9 ) == V_84 ) ) {
* V_321 = 15 ;
* V_322 = 9 ;
} else {
* V_321 = 16 ;
* V_322 = 9 ;
}
}
static bool F_125 ( struct V_323 * V_324 )
{
struct V_87 * V_88 = & V_324 -> V_88 ;
V_112 V_325 ;
V_112 V_326 ;
V_112 V_327 ;
if ( ! F_126 ( V_324 , & V_328 ,
NULL , NULL ) )
return false ;
V_325 = F_42 ( V_88 ) ;
V_326 = F_43 ( V_88 ) ;
V_327 = ( V_112 ) V_88 -> V_90 / V_325 ;
if ( V_88 -> V_329 == 0 || ( V_88 -> V_329 & V_330 ) ) {
if ( F_127 ( V_326 , V_327 , V_88 -> V_331 , V_88 -> V_84 ,
V_88 -> V_332 , V_88 -> V_113 , V_324 ) )
return true ;
}
if ( V_88 -> V_329 == 0 || ( V_88 -> V_329 & V_333 ) ) {
struct V_104 V_334 ;
F_124 ( V_88 -> V_84 , V_88 -> V_14 ,
& V_334 . V_208 ,
& V_334 . V_209 ) ;
if ( F_128 ( V_326 , V_327 , V_88 -> V_331 ,
V_88 -> V_332 , V_88 -> V_113 ,
V_334 , V_324 ) )
return true ;
}
return false ;
}
int F_129 ( struct V_137 * V_137 , void * V_335 ,
struct V_323 * V_324 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! F_31 ( V_9 ) )
return - V_314 ;
if ( ! F_130 ( V_324 , & V_328 ,
0 , NULL , NULL ) &&
! F_125 ( V_324 ) )
return - V_18 ;
if ( F_131 ( V_324 , & V_9 -> V_89 , 0 , false ) )
return 0 ;
if ( F_73 ( & V_9 -> V_179 ) )
return - V_181 ;
V_9 -> V_89 = * V_324 ;
F_40 ( V_9 , false ) ;
return 0 ;
}
int F_132 ( struct V_137 * V_137 , void * V_335 ,
struct V_323 * V_324 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! F_31 ( V_9 ) )
return - V_314 ;
if ( V_9 -> V_69 == V_266 ||
V_9 -> V_265 == 0 )
return - V_336 ;
if ( V_9 -> V_69 == V_269 )
return - V_337 ;
if ( V_9 -> V_69 == V_270 ) {
V_324 -> V_88 . V_90 = V_328 . V_88 . V_338 * 2 ;
return - V_339 ;
}
if ( V_9 -> V_69 == V_340 ) {
* V_324 = V_9 -> V_89 ;
} else if ( V_9 -> V_69 == V_341 ) {
* V_324 = V_342 [ V_9 -> V_343 ] ;
} else {
* V_324 = V_342 [ V_9 -> V_344 ] ;
V_9 -> V_344 = ( V_9 -> V_344 + 1 ) %
V_9 -> V_345 ;
}
return 0 ;
}
int F_133 ( struct V_137 * V_137 , void * V_335 ,
struct V_346 * V_347 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
T_4 V_348 ;
unsigned int V_53 ;
int V_180 ;
memset ( V_347 -> V_175 , 0 , sizeof( V_347 -> V_175 ) ) ;
if ( V_347 -> V_349 >= V_9 -> V_252 )
return - V_18 ;
if ( V_9 -> V_91 [ V_347 -> V_349 ] != V_109 || V_347 -> V_350 )
return - V_18 ;
if ( V_347 -> V_351 == 0 ) {
V_9 -> V_265 = 0 ;
V_348 = V_352 ;
goto V_353;
}
if ( V_347 -> V_351 > V_9 -> V_354 ) {
V_347 -> V_351 = V_9 -> V_354 ;
return - V_355 ;
}
V_348 = F_134 ( V_347 -> V_347 , V_347 -> V_351 * 128 , NULL ) ;
V_180 = F_135 ( V_348 , & V_348 , NULL ) ;
if ( V_180 )
return V_180 ;
if ( F_73 ( & V_9 -> V_179 ) )
return - V_181 ;
V_9 -> V_265 = V_347 -> V_351 ;
memcpy ( V_9 -> V_347 , V_347 -> V_347 , V_347 -> V_351 * 128 ) ;
V_353:
F_136 ( V_9 -> V_356 , V_348 , false ) ;
for ( V_53 = 0 ; V_53 < V_357 && V_9 -> V_358 [ V_53 ] ; V_53 ++ )
F_136 ( V_9 -> V_358 [ V_53 ] ,
F_137 ( V_348 , V_53 + 1 ) ,
false ) ;
return 0 ;
}
int F_138 ( struct V_137 * V_137 , void * V_200 ,
struct V_359 * V_360 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( ! F_55 ( V_9 ) && ! V_9 -> V_164 )
return - V_18 ;
if ( F_67 ( V_9 , V_360 -> V_361 ) == NULL )
return - V_18 ;
if ( F_55 ( V_9 ) ) {
if ( V_360 -> V_211 >= F_76 ( V_94 ) )
return - V_18 ;
V_360 -> type = V_362 ;
V_360 -> V_363 = V_94 [ V_360 -> V_211 ] ;
return 0 ;
}
if ( V_360 -> V_211 )
return - V_18 ;
V_360 -> type = V_364 ;
V_360 -> V_365 . V_366 = V_367 ;
V_360 -> V_365 . V_368 = V_174 * V_172 ;
V_360 -> V_365 . V_369 = 2 ;
V_360 -> V_365 . V_370 = V_371 ;
V_360 -> V_365 . V_372 = V_373 * V_172 ;
V_360 -> V_365 . V_374 = 2 ;
return 0 ;
}
int F_139 ( struct V_137 * V_137 , void * V_138 ,
struct V_375 * V_376 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
const struct V_156 * V_143 ;
int V_53 ;
V_143 = F_67 ( V_9 , V_376 -> V_361 ) ;
if ( ! V_143 )
return - V_18 ;
if ( ! F_55 ( V_9 ) ) {
if ( V_376 -> V_211 )
return - V_18 ;
if ( V_376 -> V_84 < V_367 || V_376 -> V_84 > V_174 * V_172 )
return - V_18 ;
if ( V_376 -> V_14 < V_371 || V_376 -> V_14 > V_373 * V_172 )
return - V_18 ;
V_376 -> type = V_377 ;
V_376 -> V_363 = V_9 -> V_96 ;
return 0 ;
}
for ( V_53 = 0 ; V_53 < F_76 ( V_94 ) ; V_53 ++ )
if ( V_376 -> V_84 == V_94 [ V_53 ] . V_84 &&
V_376 -> V_14 == V_94 [ V_53 ] . V_14 )
break;
if ( V_53 == F_76 ( V_94 ) )
return - V_18 ;
if ( V_376 -> V_211 >= 2 * ( V_186 - V_53 ) )
return - V_18 ;
V_376 -> type = V_377 ;
V_376 -> V_363 = V_97 [ V_376 -> V_211 ] ;
return 0 ;
}
int F_140 ( struct V_137 * V_137 , void * V_138 ,
struct V_378 * V_379 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
if ( V_379 -> type != ( V_9 -> V_187 ?
V_380 :
V_191 ) )
return - V_18 ;
V_379 -> V_379 . V_381 . V_240 = V_382 ;
V_379 -> V_379 . V_381 . V_383 = V_9 -> V_96 ;
V_379 -> V_379 . V_381 . V_384 = 1 ;
return 0 ;
}
int F_141 ( struct V_137 * V_137 , void * V_138 ,
struct V_378 * V_379 )
{
struct V_8 * V_9 = F_64 ( V_137 ) ;
unsigned V_385 = 2 * ( V_186 - V_9 -> V_95 ) ;
struct V_104 V_386 ;
unsigned V_53 ;
if ( V_379 -> type != ( V_9 -> V_187 ?
V_380 :
V_191 ) )
return - V_18 ;
if ( ! F_55 ( V_9 ) )
return F_140 ( V_137 , V_138 , V_379 ) ;
V_386 = V_379 -> V_379 . V_381 . V_383 ;
if ( V_386 . V_209 == 0 )
V_386 = V_97 [ V_385 - 1 ] ;
for ( V_53 = 0 ; V_53 < V_385 ; V_53 ++ )
if ( F_142 ( V_386 , >= , V_97 [ V_53 ] ) )
break;
if ( V_53 == V_385 )
V_53 = V_385 - 1 ;
V_9 -> V_98 = V_53 ;
V_386 = V_97 [ V_9 -> V_98 ] ;
V_386 = F_142 ( V_386 , < , V_387 ) ? V_387 : V_386 ;
V_386 = F_142 ( V_386 , > , V_388 ) ? V_388 : V_386 ;
V_9 -> V_389 = true ;
V_9 -> V_96 = V_386 ;
V_379 -> V_379 . V_381 . V_240 = V_382 ;
V_379 -> V_379 . V_381 . V_383 = V_386 ;
V_379 -> V_379 . V_381 . V_384 = 1 ;
return 0 ;
}
