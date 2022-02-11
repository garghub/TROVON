static int F_1 ( struct V_1 * V_2 ,
unsigned * V_3 , unsigned * V_4 ,
unsigned V_5 [] , void * V_6 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned V_9 = F_3 ( & V_8 -> V_10 ) ;
unsigned V_11 = V_8 -> V_12 . V_13 ;
unsigned V_14 ;
if ( V_8 -> V_15 == V_16 ) {
if ( F_4 ( V_2 ) )
return - V_17 ;
}
if ( V_8 -> V_18 ) {
V_8 -> V_18 = false ;
return - V_17 ;
}
if ( * V_4 ) {
if ( * V_4 != V_9 )
return - V_17 ;
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
if ( V_5 [ V_14 ] < F_5 ( & V_8 -> V_10 , V_14 ) * V_11 +
V_8 -> V_19 -> V_20 [ V_14 ] )
return - V_17 ;
}
} else {
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ )
V_5 [ V_14 ] = F_5 ( & V_8 -> V_10 , V_14 ) * V_11 +
V_8 -> V_19 -> V_20 [ V_14 ] ;
}
if ( V_2 -> V_21 + * V_3 < 2 )
* V_3 = 2 - V_2 -> V_21 ;
* V_4 = V_9 ;
F_6 ( V_8 , 1 , L_1 , V_22 , * V_3 ) ;
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ )
F_6 ( V_8 , 1 , L_2 , V_22 , V_14 , V_5 [ V_14 ] ) ;
return 0 ;
}
static int F_7 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_2 ( V_24 -> V_1 ) ;
unsigned long V_25 ;
unsigned V_9 = F_3 ( & V_8 -> V_10 ) ;
unsigned V_14 ;
F_6 ( V_8 , 1 , L_3 , V_22 ) ;
if ( F_8 ( NULL == V_8 -> V_19 ) )
return - V_17 ;
if ( V_8 -> V_26 ) {
V_8 -> V_26 = false ;
return - V_17 ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_25 = F_5 ( & V_8 -> V_10 , V_14 ) * V_8 -> V_12 . V_13 +
V_8 -> V_19 -> V_20 [ V_14 ] ;
if ( F_9 ( V_24 , V_14 ) < V_25 ) {
F_6 ( V_8 , 1 , L_4 ,
V_22 , V_14 , F_9 ( V_24 , V_14 ) , V_25 ) ;
return - V_17 ;
}
F_10 ( V_24 , V_14 , V_25 ) ;
V_24 -> V_27 [ V_14 ] . V_20 = V_8 -> V_19 -> V_20 [ V_14 ] ;
}
return 0 ;
}
static void F_11 ( struct V_23 * V_24 )
{
struct V_28 * V_29 = F_12 ( V_24 ) ;
struct V_7 * V_8 = F_2 ( V_24 -> V_1 ) ;
struct V_30 * V_31 = & V_29 -> V_32 ;
unsigned V_33 = 25 ;
unsigned V_34 = V_29 -> V_35 ;
if ( ! F_13 ( V_8 ) )
return;
V_29 -> V_36 |= V_37 ;
if ( V_8 -> V_38 & V_39 )
V_33 = 30 ;
V_31 -> type = ( V_33 == 30 ) ? V_40 : V_41 ;
V_31 -> V_36 = 0 ;
V_31 -> V_42 = V_34 % V_33 ;
V_31 -> V_43 = ( V_34 / V_33 ) % 60 ;
V_31 -> V_44 = ( V_34 / ( 60 * V_33 ) ) % 60 ;
V_31 -> V_45 = ( V_34 / ( 60 * 60 * V_33 ) ) % 24 ;
}
static void F_14 ( struct V_23 * V_24 )
{
struct V_28 * V_29 = F_12 ( V_24 ) ;
struct V_7 * V_8 = F_2 ( V_24 -> V_1 ) ;
struct V_46 * V_47 = F_15 ( V_29 , struct V_46 , V_24 ) ;
F_6 ( V_8 , 1 , L_3 , V_22 ) ;
F_16 ( & V_8 -> V_48 ) ;
F_17 ( & V_47 -> V_49 , & V_8 -> V_50 ) ;
F_18 ( & V_8 -> V_48 ) ;
}
static int F_19 ( struct V_1 * V_2 , unsigned V_51 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned V_52 ;
int V_53 ;
if ( F_20 ( & V_8 -> V_54 ) )
V_8 -> V_55 = F_21 ( V_8 ) ;
if ( V_8 -> V_56 )
return 0 ;
V_8 -> V_57 = 0 ;
F_6 ( V_8 , 1 , L_3 , V_22 ) ;
for ( V_52 = 0 ; V_52 < V_58 ; V_52 ++ )
V_8 -> V_59 [ V_52 ] = F_22 ( & V_8 -> V_10 ) < 100 ;
if ( V_8 -> V_60 ) {
V_8 -> V_60 = false ;
V_53 = - V_17 ;
} else {
V_53 = F_23 ( V_8 , & V_8 -> V_61 ) ;
}
if ( V_53 ) {
struct V_46 * V_47 , * V_62 ;
F_24 (buf, tmp, &dev->vid_cap_active, list) {
F_25 ( & V_47 -> V_49 ) ;
F_26 ( & V_47 -> V_24 . V_63 ,
V_64 ) ;
}
}
return V_53 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_6 ( V_8 , 1 , L_3 , V_22 ) ;
F_28 ( V_8 , & V_8 -> V_61 ) ;
V_8 -> V_55 = false ;
}
void F_29 ( struct V_7 * V_8 )
{
unsigned V_65 ;
if ( V_8 -> V_66 && ( F_30 ( V_8 ) || F_31 ( V_8 ) ) ) {
F_32 ( & V_8 -> V_10 , V_67 , 0 ) ;
return;
}
if ( F_31 ( V_8 ) && F_33 ( V_8 -> V_68 ) ) {
F_32 ( & V_8 -> V_10 , V_67 , 0 ) ;
return;
}
if ( F_13 ( V_8 ) && F_33 ( V_8 -> V_69 ) ) {
F_32 ( & V_8 -> V_10 , V_67 , 0 ) ;
return;
}
if ( ! F_34 ( V_8 ) ) {
F_32 ( & V_8 -> V_10 , V_70 , 0 ) ;
return;
}
V_65 = ( V_8 -> V_71 - 676 ) % ( 6 * 16 ) ;
if ( V_65 > 2 * 16 ) {
F_32 ( & V_8 -> V_10 , V_67 ,
F_35 ( V_8 -> V_71 ^ 0x55 ) & 0x3f ) ;
return;
}
if ( V_65 < 12 || V_65 > 20 )
F_32 ( & V_8 -> V_10 , V_72 , 0 ) ;
else
F_32 ( & V_8 -> V_10 , V_70 , 0 ) ;
}
static enum V_73 F_36 ( struct V_7 * V_8 , T_1 * V_74 )
{
unsigned V_65 ;
if ( V_74 )
* V_74 = 0 ;
if ( F_37 ( & V_8 -> V_10 ) == V_70 ||
F_37 ( & V_8 -> V_10 ) == V_67 )
return F_37 ( & V_8 -> V_10 ) ;
V_65 = ( V_8 -> V_71 - 676 ) % ( 6 * 16 ) ;
if ( V_74 )
* V_74 = V_65 - 1 * 16 ;
return V_72 ;
}
enum V_75 F_38 ( const struct V_7 * V_8 )
{
if ( F_13 ( V_8 ) )
return V_8 -> V_76 ;
if ( F_31 ( V_8 ) )
return V_8 -> V_77 ;
return V_78 ;
}
static enum V_79 F_39 ( const struct V_7 * V_8 )
{
if ( F_13 ( V_8 ) )
return ( V_8 -> V_38 & V_39 ) ?
V_80 : V_81 ;
if ( F_31 ( V_8 ) &&
V_8 -> V_82 . V_83 == 720 && V_8 -> V_82 . V_13 <= 576 )
return V_8 -> V_82 . V_13 == 480 ?
V_80 : V_81 ;
return V_84 ;
}
void F_40 ( struct V_7 * V_8 , bool V_85 )
{
struct V_86 * V_87 = & V_8 -> V_88 . V_87 ;
unsigned V_25 ;
T_2 V_89 ;
switch ( V_8 -> V_90 [ V_8 -> V_91 ] ) {
case V_92 :
default:
V_8 -> V_82 . V_83 = V_93 [ V_8 -> V_94 ] . V_83 ;
V_8 -> V_82 . V_13 = V_93 [ V_8 -> V_94 ] . V_13 ;
V_8 -> V_95 = V_96 [ V_8 -> V_97 ] ;
V_8 -> V_15 = V_98 ;
F_41 ( & V_8 -> V_10 , V_99 ) ;
break;
case V_100 :
case V_101 :
V_8 -> V_15 = V_8 -> V_102 ;
V_8 -> V_82 . V_83 = 720 ;
if ( V_8 -> V_38 & V_39 ) {
V_8 -> V_82 . V_13 = 480 ;
V_8 -> V_95 = (struct V_103 ) { 1001 , 30000 } ;
V_8 -> V_104 = V_105 ;
} else {
V_8 -> V_82 . V_13 = 576 ;
V_8 -> V_95 = (struct V_103 ) { 1000 , 25000 } ;
V_8 -> V_104 = V_106 | V_107 ;
}
F_41 ( & V_8 -> V_10 , V_99 ) ;
break;
case V_108 :
V_8 -> V_82 . V_83 = V_87 -> V_83 ;
V_8 -> V_82 . V_13 = V_87 -> V_13 ;
V_25 = F_42 ( V_87 ) * F_43 ( V_87 ) ;
if ( V_8 -> V_109 && F_44 ( V_87 ) ) {
V_89 = F_45 ( V_87 -> V_89 * 1000 , 1001 ) ;
V_87 -> V_36 |= V_110 ;
} else {
V_89 = V_87 -> V_89 ;
V_87 -> V_36 &= ~ V_110 ;
}
V_8 -> V_95 = (struct V_103 ) {
V_25 / 100 , ( V_111 ) V_89 / 100
} ;
if ( V_87 -> V_112 )
V_8 -> V_15 = V_16 ;
else
V_8 -> V_15 = V_98 ;
if ( V_85 || ! V_8 -> V_113 )
break;
if ( V_87 -> V_36 & V_114 ) {
if ( V_87 -> V_83 == 720 && V_87 -> V_13 <= 576 )
F_46 ( V_8 -> V_113 , V_115 ) ;
else
F_46 ( V_8 -> V_113 , V_116 ) ;
F_46 ( V_8 -> V_117 , 1 ) ;
} else {
F_46 ( V_8 -> V_113 , V_118 ) ;
F_46 ( V_8 -> V_117 , 0 ) ;
}
F_41 ( & V_8 -> V_10 , F_47 ( V_8 -> V_119 ) ) ;
break;
}
F_29 ( V_8 ) ;
F_48 ( & V_8 -> V_10 , V_8 -> V_82 . V_83 , V_8 -> V_82 . V_13 , V_8 -> V_15 ) ;
V_8 -> V_120 = V_8 -> V_82 ;
V_8 -> V_121 = V_8 -> V_82 ;
V_8 -> V_122 = V_8 -> V_120 ;
if ( F_49 ( V_8 -> V_15 ) )
V_8 -> V_122 . V_13 /= 2 ;
V_8 -> V_12 = V_8 -> V_122 ;
F_50 ( & V_8 -> V_10 , F_38 ( V_8 ) ) ;
F_51 ( & V_8 -> V_10 , F_39 ( V_8 ) ) ;
F_52 ( & V_8 -> V_10 ) ;
}
static enum V_123 F_53 ( struct V_7 * V_8 , enum V_123 V_124 )
{
if ( F_13 ( V_8 ) ) {
switch ( V_124 ) {
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_16 :
return V_124 ;
case V_131 :
default:
return V_131 ;
}
}
if ( F_31 ( V_8 ) )
return V_8 -> V_88 . V_87 . V_112 ? V_16 :
V_98 ;
return V_98 ;
}
static unsigned F_54 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_66 || F_55 ( V_8 ) || F_34 ( V_8 ) )
return F_56 ( & V_8 -> V_10 ) ;
return V_8 -> V_132 ;
}
static unsigned F_57 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_66 || F_55 ( V_8 ) || F_34 ( V_8 ) )
return F_58 ( & V_8 -> V_10 ) ;
return V_8 -> V_133 ;
}
static unsigned F_59 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_66 || F_55 ( V_8 ) || F_34 ( V_8 ) )
return F_60 ( & V_8 -> V_10 ) ;
return V_8 -> V_134 ;
}
static unsigned F_61 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_66 || F_55 ( V_8 ) || F_34 ( V_8 ) )
return F_62 ( & V_8 -> V_10 ) ;
return V_8 -> V_135 ;
}
int F_63 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
struct V_140 * V_141 = & V_139 -> V_142 . V_143 ;
unsigned V_14 ;
V_141 -> V_83 = V_8 -> V_12 . V_83 ;
V_141 -> V_13 = V_8 -> V_12 . V_13 ;
V_141 -> V_124 = V_8 -> V_15 ;
V_141 -> V_144 = V_8 -> V_19 -> V_145 ;
V_141 -> V_113 = F_54 ( V_8 ) ;
V_141 -> V_146 = F_57 ( V_8 ) ;
V_141 -> V_147 = F_59 ( V_8 ) ;
V_141 -> V_148 = F_61 ( V_8 ) ;
V_141 -> V_149 = V_8 -> V_19 -> V_9 ;
for ( V_14 = 0 ; V_14 < V_141 -> V_149 ; V_14 ++ ) {
V_141 -> V_150 [ V_14 ] . V_151 = F_65 ( & V_8 -> V_10 , V_14 ) ;
V_141 -> V_150 [ V_14 ] . V_152 =
F_5 ( & V_8 -> V_10 , V_14 ) * V_141 -> V_13 +
V_8 -> V_19 -> V_20 [ V_14 ] ;
}
return 0 ;
}
int F_66 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_140 * V_141 = & V_139 -> V_142 . V_143 ;
struct V_153 * V_154 = V_141 -> V_150 ;
struct V_7 * V_8 = F_64 ( V_136 ) ;
const struct V_155 * V_142 ;
unsigned V_151 , V_156 ;
unsigned V_157 = 1 ;
unsigned V_158 , V_11 ;
unsigned V_14 ;
V_142 = F_67 ( V_8 , V_141 -> V_144 ) ;
if ( ! V_142 ) {
F_6 ( V_8 , 1 , L_5 ,
V_141 -> V_144 ) ;
V_141 -> V_144 = V_159 ;
V_142 = F_67 ( V_8 , V_141 -> V_144 ) ;
}
V_141 -> V_124 = F_53 ( V_8 , V_141 -> V_124 ) ;
if ( F_55 ( V_8 ) ) {
const struct V_160 * V_161 =
F_68 ( & V_162 , V_141 -> V_83 , V_141 -> V_13 ) ;
V_158 = V_161 -> V_83 ;
V_11 = V_161 -> V_13 ;
} else if ( F_13 ( V_8 ) ) {
V_158 = 720 ;
V_11 = ( V_8 -> V_38 & V_39 ) ? 480 : 576 ;
} else {
V_158 = V_8 -> V_82 . V_83 ;
V_11 = V_8 -> V_82 . V_13 ;
}
if ( F_49 ( V_141 -> V_124 ) )
V_157 = 2 ;
if ( F_55 ( V_8 ) ||
( ! V_8 -> V_163 && ! V_8 -> V_164 && ! V_8 -> V_165 ) ) {
V_141 -> V_83 = V_158 ;
V_141 -> V_13 = V_11 / V_157 ;
} else {
struct V_166 V_167 = { 0 , 0 , V_141 -> V_83 , V_141 -> V_13 * V_157 } ;
F_69 ( & V_167 , & V_168 ) ;
F_70 ( & V_167 , & V_169 ) ;
if ( V_8 -> V_163 && ! V_8 -> V_165 ) {
struct V_166 V_170 = { 0 , 0 , V_171 * V_158 , V_171 * V_11 } ;
F_70 ( & V_167 , & V_170 ) ;
} else if ( ! V_8 -> V_163 && V_8 -> V_164 && ! V_8 -> V_165 ) {
F_70 ( & V_167 , & V_8 -> V_82 ) ;
} else if ( ! V_8 -> V_163 && ! V_8 -> V_164 ) {
F_69 ( & V_167 , & V_8 -> V_82 ) ;
}
V_141 -> V_83 = V_167 . V_83 ;
V_141 -> V_13 = V_167 . V_13 / V_157 ;
}
V_141 -> V_149 = V_142 -> V_9 ;
for ( V_14 = 0 ; V_14 < V_141 -> V_149 ; V_14 ++ ) {
V_151 = ( V_141 -> V_83 * V_142 -> V_172 [ V_14 ] ) >> 3 ;
V_156 = ( V_171 * V_173 * V_142 -> V_172 [ V_14 ] ) >> 3 ;
if ( V_154 [ V_14 ] . V_151 > V_156 )
V_154 [ V_14 ] . V_151 = V_156 ;
if ( V_154 [ V_14 ] . V_151 < V_151 )
V_154 [ V_14 ] . V_151 = V_151 ;
V_154 [ V_14 ] . V_152 = F_71 ( & V_8 -> V_10 , V_14 , V_154 [ V_14 ] . V_151 ) *
V_141 -> V_13 + V_142 -> V_20 [ V_14 ] ;
memset ( V_154 [ V_14 ] . V_174 , 0 , sizeof( V_154 [ V_14 ] . V_174 ) ) ;
}
V_141 -> V_113 = F_54 ( V_8 ) ;
V_141 -> V_147 = F_59 ( V_8 ) ;
V_141 -> V_146 = F_57 ( V_8 ) ;
V_141 -> V_148 = F_61 ( V_8 ) ;
memset ( V_141 -> V_174 , 0 , sizeof( V_141 -> V_174 ) ) ;
return 0 ;
}
int F_72 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_140 * V_141 = & V_139 -> V_142 . V_143 ;
struct V_7 * V_8 = F_64 ( V_136 ) ;
struct V_166 * V_175 = & V_8 -> V_120 ;
struct V_166 * V_176 = & V_8 -> V_122 ;
struct V_1 * V_177 = & V_8 -> V_178 ;
int V_179 = F_66 ( V_136 , V_137 , V_139 ) ;
unsigned V_157 = 1 ;
unsigned V_14 ;
unsigned V_52 ;
if ( V_179 < 0 )
return V_179 ;
if ( F_73 ( V_177 ) ) {
F_6 ( V_8 , 1 , L_6 , V_22 ) ;
return - V_180 ;
}
if ( V_8 -> V_181 && V_8 -> V_182 . V_142 . V_144 != V_141 -> V_144 ) {
F_6 ( V_8 , 1 , L_7 ) ;
return - V_180 ;
}
V_8 -> V_19 = F_67 ( V_8 , V_141 -> V_144 ) ;
if ( F_49 ( V_141 -> V_124 ) )
V_157 = 2 ;
if ( ! F_55 ( V_8 ) &&
( V_8 -> V_163 || V_8 -> V_164 || V_8 -> V_165 ) ) {
struct V_166 V_167 = { 0 , 0 , V_141 -> V_83 , V_141 -> V_13 } ;
if ( V_8 -> V_163 ) {
if ( V_8 -> V_165 )
F_74 ( V_176 , & V_167 ) ;
else
* V_176 = V_167 ;
if ( V_8 -> V_164 && ! V_8 -> V_165 ) {
struct V_166 V_183 = {
0 , 0 ,
V_167 . V_83 / V_171 ,
V_157 * V_167 . V_13 / V_171
} ;
struct V_166 V_170 = {
0 , 0 ,
V_167 . V_83 * V_171 ,
V_157 * V_167 . V_13 * V_171
} ;
F_69 ( V_175 , & V_183 ) ;
F_70 ( V_175 , & V_170 ) ;
F_74 ( V_175 , & V_8 -> V_121 ) ;
} else if ( V_8 -> V_164 ) {
struct V_166 V_183 = {
0 , 0 ,
V_176 -> V_83 / V_171 ,
V_157 * V_176 -> V_13 / V_171
} ;
struct V_166 V_170 = {
0 , 0 ,
V_176 -> V_83 * V_171 ,
V_157 * V_176 -> V_13 * V_171
} ;
F_69 ( V_175 , & V_183 ) ;
F_70 ( V_175 , & V_170 ) ;
F_74 ( V_175 , & V_8 -> V_121 ) ;
}
} else if ( V_8 -> V_164 && ! V_8 -> V_165 ) {
V_167 . V_13 *= V_157 ;
F_75 ( V_175 , & V_167 ) ;
F_74 ( V_175 , & V_8 -> V_121 ) ;
V_167 = * V_175 ;
V_167 . V_13 /= V_157 ;
F_75 ( V_176 , & V_167 ) ;
} else if ( ! V_8 -> V_164 ) {
F_74 ( V_176 , & V_167 ) ;
} else {
V_167 . V_13 *= V_157 ;
F_70 ( V_175 , & V_167 ) ;
F_74 ( V_175 , & V_8 -> V_121 ) ;
V_176 -> V_184 *= V_157 ;
V_176 -> V_13 *= V_157 ;
F_75 ( V_176 , V_175 ) ;
F_74 ( V_176 , & V_167 ) ;
V_176 -> V_184 /= V_157 ;
V_176 -> V_13 /= V_157 ;
}
} else if ( F_55 ( V_8 ) ) {
for ( V_52 = 0 ; V_52 < F_76 ( V_93 ) ; V_52 ++ )
if ( V_93 [ V_52 ] . V_83 == V_141 -> V_83 &&
V_93 [ V_52 ] . V_13 == V_141 -> V_13 )
break;
V_8 -> V_94 = V_52 ;
if ( V_8 -> V_97 >= 2 * ( V_185 - V_52 ) )
V_8 -> V_97 = 2 * ( V_185 - V_52 ) - 1 ;
F_40 ( V_8 , false ) ;
} else {
struct V_166 V_167 = { 0 , 0 , V_141 -> V_83 , V_141 -> V_13 } ;
F_75 ( V_176 , & V_167 ) ;
V_167 . V_13 *= V_157 ;
F_75 ( V_175 , & V_167 ) ;
}
V_8 -> V_12 . V_83 = V_141 -> V_83 ;
V_8 -> V_12 . V_13 = V_141 -> V_13 ;
F_77 ( & V_8 -> V_10 , V_141 -> V_13 ) ;
F_78 ( & V_8 -> V_10 , V_8 -> V_19 -> V_145 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( & V_8 -> V_10 ) ; V_14 ++ )
F_79 ( & V_8 -> V_10 , V_14 , V_141 -> V_150 [ V_14 ] . V_151 ) ;
V_8 -> V_15 = V_141 -> V_124 ;
if ( V_8 -> V_15 == V_16 )
F_80 ( & V_8 -> V_10 , V_129 , true ) ;
else
F_80 ( & V_8 -> V_10 , V_8 -> V_15 , false ) ;
F_81 ( & V_8 -> V_10 , & V_8 -> V_120 , & V_8 -> V_122 ) ;
if ( F_13 ( V_8 ) )
V_8 -> V_102 = V_141 -> V_124 ;
F_52 ( & V_8 -> V_10 ) ;
return 0 ;
}
int F_82 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! V_8 -> V_186 )
return - V_187 ;
return F_63 ( V_136 , V_137 , V_139 ) ;
}
int F_83 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! V_8 -> V_186 )
return - V_187 ;
return F_66 ( V_136 , V_137 , V_139 ) ;
}
int F_84 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! V_8 -> V_186 )
return - V_187 ;
return F_72 ( V_136 , V_137 , V_139 ) ;
}
int F_85 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_8 -> V_186 )
return - V_187 ;
return F_86 ( V_136 , V_137 , V_139 , F_63 ) ;
}
int F_87 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_8 -> V_186 )
return - V_187 ;
return F_86 ( V_136 , V_137 , V_139 , F_66 ) ;
}
int F_88 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_8 -> V_186 )
return - V_187 ;
return F_86 ( V_136 , V_137 , V_139 , F_72 ) ;
}
int F_89 ( struct V_136 * V_136 , void * V_137 ,
struct V_188 * V_189 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! V_8 -> V_164 && ! V_8 -> V_165 )
return - V_187 ;
if ( V_189 -> type != V_190 )
return - V_17 ;
if ( F_55 ( V_8 ) )
return - V_17 ;
V_189 -> V_167 . V_191 = V_189 -> V_167 . V_184 = 0 ;
switch ( V_189 -> V_192 ) {
case V_193 :
if ( ! V_8 -> V_164 )
return - V_17 ;
V_189 -> V_167 = V_8 -> V_120 ;
break;
case V_194 :
case V_195 :
if ( ! V_8 -> V_164 )
return - V_17 ;
V_189 -> V_167 = V_8 -> V_82 ;
break;
case V_196 :
if ( ! V_8 -> V_165 )
return - V_17 ;
V_189 -> V_167 = V_169 ;
break;
case V_197 :
if ( ! V_8 -> V_165 )
return - V_17 ;
V_189 -> V_167 = V_8 -> V_122 ;
break;
case V_198 :
if ( ! V_8 -> V_165 )
return - V_17 ;
V_189 -> V_167 = V_8 -> V_12 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
int F_90 ( struct V_136 * V_136 , void * V_199 , struct V_188 * V_200 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
struct V_166 * V_175 = & V_8 -> V_120 ;
struct V_166 * V_176 = & V_8 -> V_122 ;
unsigned V_157 = F_49 ( V_8 -> V_15 ) ? 2 : 1 ;
int V_179 ;
if ( ! V_8 -> V_164 && ! V_8 -> V_165 )
return - V_187 ;
if ( V_200 -> type != V_190 )
return - V_17 ;
if ( F_55 ( V_8 ) )
return - V_17 ;
switch ( V_200 -> V_192 ) {
case V_193 :
if ( ! V_8 -> V_164 )
return - V_17 ;
V_179 = F_91 ( V_200 -> V_36 , & V_200 -> V_167 ) ;
if ( V_179 )
return V_179 ;
F_69 ( & V_200 -> V_167 , & V_168 ) ;
F_70 ( & V_200 -> V_167 , & V_8 -> V_82 ) ;
F_74 ( & V_200 -> V_167 , & V_8 -> V_121 ) ;
V_200 -> V_167 . V_184 /= V_157 ;
V_200 -> V_167 . V_13 /= V_157 ;
if ( V_8 -> V_163 ) {
struct V_166 V_142 = V_8 -> V_12 ;
struct V_166 V_201 = {
0 , 0 ,
V_200 -> V_167 . V_83 * V_171 ,
V_200 -> V_167 . V_13 * V_171
} ;
struct V_166 V_202 = {
0 , 0 ,
V_200 -> V_167 . V_83 / V_171 ,
V_200 -> V_167 . V_13 / V_171
} ;
F_69 ( & V_142 , & V_202 ) ;
if ( ! V_8 -> V_165 )
F_70 ( & V_142 , & V_201 ) ;
if ( ! F_92 ( & V_8 -> V_12 , & V_142 ) &&
F_73 ( & V_8 -> V_178 ) )
return - V_180 ;
if ( V_8 -> V_165 ) {
F_69 ( V_176 , & V_202 ) ;
F_70 ( V_176 , & V_201 ) ;
}
V_8 -> V_12 = V_142 ;
F_77 ( & V_8 -> V_10 , V_142 . V_13 ) ;
} else if ( V_8 -> V_165 ) {
struct V_166 V_142 = V_8 -> V_12 ;
F_69 ( & V_142 , & V_200 -> V_167 ) ;
if ( ! F_92 ( & V_8 -> V_12 , & V_142 ) &&
F_73 ( & V_8 -> V_178 ) )
return - V_180 ;
V_8 -> V_12 = V_142 ;
F_77 ( & V_8 -> V_10 , V_142 . V_13 ) ;
F_75 ( V_176 , & V_200 -> V_167 ) ;
F_74 ( V_176 , & V_8 -> V_12 ) ;
} else {
if ( ! F_92 ( & V_200 -> V_167 , & V_8 -> V_12 ) &&
F_73 ( & V_8 -> V_178 ) )
return - V_180 ;
F_75 ( & V_8 -> V_12 , & V_200 -> V_167 ) ;
F_75 ( V_176 , & V_200 -> V_167 ) ;
F_74 ( V_176 , & V_8 -> V_12 ) ;
F_77 ( & V_8 -> V_10 , V_8 -> V_12 . V_13 ) ;
}
V_200 -> V_167 . V_184 *= V_157 ;
V_200 -> V_167 . V_13 *= V_157 ;
* V_175 = V_200 -> V_167 ;
break;
case V_197 :
if ( ! V_8 -> V_165 )
return - V_17 ;
V_179 = F_91 ( V_200 -> V_36 , & V_200 -> V_167 ) ;
if ( V_179 )
return V_179 ;
F_69 ( & V_200 -> V_167 , & V_168 ) ;
F_70 ( & V_200 -> V_167 , & V_8 -> V_12 ) ;
if ( V_8 -> V_163 ) {
struct V_166 V_201 = {
0 , 0 ,
V_8 -> V_82 . V_83 * V_171 ,
( V_8 -> V_82 . V_13 / V_157 ) * V_171
} ;
F_70 ( & V_200 -> V_167 , & V_201 ) ;
if ( V_8 -> V_164 ) {
struct V_166 V_202 = {
0 , 0 ,
V_200 -> V_167 . V_83 / V_171 ,
( V_200 -> V_167 . V_13 * V_157 ) / V_171
} ;
struct V_166 V_201 = {
0 , 0 ,
V_200 -> V_167 . V_83 * V_171 ,
( V_200 -> V_167 . V_13 * V_157 ) * V_171
} ;
F_69 ( V_175 , & V_202 ) ;
F_70 ( V_175 , & V_201 ) ;
F_74 ( V_175 , & V_8 -> V_121 ) ;
}
} else if ( V_8 -> V_164 ) {
V_200 -> V_167 . V_184 *= V_157 ;
V_200 -> V_167 . V_13 *= V_157 ;
F_70 ( & V_200 -> V_167 , & V_8 -> V_82 ) ;
F_75 ( V_175 , & V_200 -> V_167 ) ;
F_74 ( V_175 , & V_8 -> V_121 ) ;
V_200 -> V_167 . V_184 /= V_157 ;
V_200 -> V_167 . V_13 /= V_157 ;
} else {
F_75 ( & V_200 -> V_167 , & V_8 -> V_82 ) ;
V_200 -> V_167 . V_13 /= V_157 ;
}
F_74 ( & V_200 -> V_167 , & V_8 -> V_12 ) ;
if ( V_8 -> V_203 && ( V_176 -> V_83 != V_200 -> V_167 . V_83 ||
V_176 -> V_13 != V_200 -> V_167 . V_13 ) ) {
F_93 ( V_8 -> V_203 ) ;
V_8 -> V_203 = NULL ;
}
* V_176 = V_200 -> V_167 ;
break;
default:
return - V_17 ;
}
F_81 ( & V_8 -> V_10 , V_175 , V_176 ) ;
return 0 ;
}
int F_94 ( struct V_136 * V_136 , void * V_137 ,
struct V_204 * V_205 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_205 -> type != V_190 )
return - V_17 ;
switch ( F_39 ( V_8 ) ) {
case V_80 :
V_205 -> V_206 . V_207 = 11 ;
V_205 -> V_206 . V_208 = 10 ;
break;
case V_81 :
V_205 -> V_206 . V_207 = 54 ;
V_205 -> V_206 . V_208 = 59 ;
break;
case V_84 :
V_205 -> V_206 . V_207 = 1 ;
V_205 -> V_206 . V_208 = 1 ;
break;
}
return 0 ;
}
int F_95 ( struct V_136 * V_136 , void * V_137 ,
struct V_209 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
const struct V_155 * V_142 ;
if ( V_8 -> V_186 )
return - V_187 ;
if ( V_139 -> V_210 >= F_76 ( V_211 ) )
return - V_17 ;
V_142 = & V_211 [ V_139 -> V_210 ] ;
V_139 -> V_144 = V_142 -> V_145 ;
return 0 ;
}
int F_96 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
const struct V_166 * V_176 = & V_8 -> V_122 ;
struct V_212 * V_213 = & V_139 -> V_142 . V_213 ;
unsigned V_214 = V_213 -> V_214 ;
if ( V_8 -> V_186 )
return - V_187 ;
V_213 -> V_158 . V_184 = V_8 -> V_215 ;
V_213 -> V_158 . V_191 = V_8 -> V_216 ;
V_213 -> V_158 . V_83 = V_176 -> V_83 ;
V_213 -> V_158 . V_13 = V_176 -> V_13 ;
V_213 -> V_124 = V_8 -> V_217 ;
V_213 -> V_214 = V_8 -> V_218 ;
if ( V_214 > V_8 -> V_218 )
V_214 = V_8 -> V_218 ;
if ( V_8 -> V_203 == NULL )
V_213 -> V_219 = NULL ;
else if ( V_213 -> V_219 ) {
if ( F_97 ( V_213 -> V_219 , V_8 -> V_203 ,
( ( V_176 -> V_83 + 7 ) / 8 ) * V_176 -> V_13 ) )
return - V_220 ;
}
if ( V_214 && V_213 -> V_221 ) {
if ( F_97 ( V_213 -> V_221 , V_8 -> V_222 ,
V_214 * sizeof( V_8 -> V_222 [ 0 ] ) ) )
return - V_220 ;
}
return 0 ;
}
int F_98 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
const struct V_166 * V_176 = & V_8 -> V_122 ;
struct V_212 * V_213 = & V_139 -> V_142 . V_213 ;
int V_52 , V_223 ;
if ( V_8 -> V_186 )
return - V_187 ;
V_213 -> V_158 . V_191 = F_99 ( int , V_213 -> V_158 . V_191 ,
- V_8 -> V_182 . V_142 . V_83 , V_8 -> V_182 . V_142 . V_83 ) ;
V_213 -> V_158 . V_184 = F_99 ( int , V_213 -> V_158 . V_184 ,
- V_8 -> V_182 . V_142 . V_13 , V_8 -> V_182 . V_142 . V_13 ) ;
V_213 -> V_158 . V_83 = V_176 -> V_83 ;
V_213 -> V_158 . V_13 = V_176 -> V_13 ;
if ( V_213 -> V_124 != V_130 && V_213 -> V_124 != V_129 )
V_213 -> V_124 = V_224 ;
V_213 -> V_225 = 0 ;
V_213 -> V_226 = 0 ;
if ( V_213 -> V_214 && ! V_213 -> V_221 )
V_213 -> V_214 = 0 ;
if ( V_213 -> V_214 > V_227 )
V_213 -> V_214 = V_227 ;
if ( V_213 -> V_214 ) {
if ( F_100 ( V_8 -> V_228 , V_213 -> V_221 ,
V_213 -> V_214 * sizeof( V_8 -> V_222 [ 0 ] ) ) )
return - V_220 ;
for ( V_52 = 0 ; V_52 < V_213 -> V_214 ; V_52 ++ ) {
struct V_166 * V_167 = & V_8 -> V_228 [ V_52 ] . V_229 ;
V_167 -> V_184 = F_99 ( T_1 , V_167 -> V_184 , 0 , V_8 -> V_182 . V_142 . V_13 - 1 ) ;
V_167 -> V_13 = F_99 ( T_1 , V_167 -> V_13 , 1 , V_8 -> V_182 . V_142 . V_13 - V_167 -> V_184 ) ;
V_167 -> V_191 = F_99 ( V_111 , V_167 -> V_191 , 0 , V_8 -> V_182 . V_142 . V_83 - 1 ) ;
V_167 -> V_83 = F_99 ( V_111 , V_167 -> V_83 , 1 , V_8 -> V_182 . V_142 . V_83 - V_167 -> V_191 ) ;
}
for ( V_52 = 0 ; V_52 < V_213 -> V_214 - 1 ; V_52 ++ ) {
struct V_166 * V_230 = & V_8 -> V_228 [ V_52 ] . V_229 ;
for ( V_223 = V_52 + 1 ; V_223 < V_213 -> V_214 ; V_223 ++ ) {
struct V_166 * V_231 = & V_8 -> V_228 [ V_223 ] . V_229 ;
if ( F_101 ( V_230 , V_231 ) )
return - V_17 ;
}
}
if ( F_97 ( V_213 -> V_221 , V_8 -> V_228 ,
V_213 -> V_214 * sizeof( V_8 -> V_222 [ 0 ] ) ) )
return - V_220 ;
}
return 0 ;
}
int F_102 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
const struct V_166 * V_176 = & V_8 -> V_122 ;
struct V_212 * V_213 = & V_139 -> V_142 . V_213 ;
int V_179 = F_98 ( V_136 , V_137 , V_139 ) ;
unsigned V_232 = ( ( V_176 -> V_83 + 7 ) / 8 ) * V_176 -> V_13 ;
unsigned V_233 = V_213 -> V_214 * sizeof( V_8 -> V_222 [ 0 ] ) ;
void * V_234 = NULL ;
if ( V_179 )
return V_179 ;
if ( V_213 -> V_219 ) {
V_234 = F_103 ( V_232 ) ;
if ( V_234 == NULL )
return - V_235 ;
if ( F_100 ( V_234 , V_213 -> V_219 , V_232 ) ) {
F_104 ( V_234 ) ;
return - V_220 ;
}
}
V_8 -> V_215 = V_213 -> V_158 . V_184 ;
V_8 -> V_216 = V_213 -> V_158 . V_191 ;
V_8 -> V_217 = V_213 -> V_124 ;
F_104 ( V_8 -> V_203 ) ;
V_8 -> V_203 = V_234 ;
V_8 -> V_218 = V_213 -> V_214 ;
if ( V_8 -> V_218 )
memcpy ( V_8 -> V_222 , V_8 -> V_228 , V_233 ) ;
return 0 ;
}
int F_105 ( struct V_136 * V_136 , void * V_199 , unsigned V_52 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_8 -> V_186 )
return - V_187 ;
if ( V_52 && V_8 -> V_236 == NULL )
return - V_17 ;
if ( V_52 && V_8 -> V_182 . V_142 . V_144 != V_8 -> V_19 -> V_145 ) {
F_6 ( V_8 , 1 , L_8 ) ;
return - V_17 ;
}
if ( V_8 -> V_181 && V_8 -> V_181 != V_199 )
return - V_180 ;
V_8 -> V_181 = V_52 ? V_199 : NULL ;
return 0 ;
}
int F_106 ( struct V_136 * V_136 , void * V_199 ,
struct V_237 * V_238 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_8 -> V_186 )
return - V_187 ;
* V_238 = V_8 -> V_182 ;
V_238 -> V_239 = V_240 |
V_241 ;
V_238 -> V_36 = V_242 ;
V_238 -> V_142 . V_124 = V_98 ;
V_238 -> V_142 . V_113 = V_243 ;
V_238 -> V_142 . V_137 = 0 ;
return 0 ;
}
int F_107 ( struct V_136 * V_136 , void * V_199 ,
const struct V_237 * V_238 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
const struct V_155 * V_142 ;
if ( V_8 -> V_186 )
return - V_187 ;
if ( ! F_108 ( V_244 ) && ! F_108 ( V_245 ) )
return - V_246 ;
if ( V_8 -> V_181 )
return - V_180 ;
if ( V_238 -> V_247 == NULL ) {
V_8 -> V_182 . V_247 = NULL ;
V_8 -> V_236 = NULL ;
return 0 ;
}
if ( V_238 -> V_142 . V_83 < 48 || V_238 -> V_142 . V_13 < 32 )
return - V_17 ;
V_142 = F_67 ( V_8 , V_238 -> V_142 . V_144 ) ;
if ( ! V_142 || ! V_142 -> V_248 )
return - V_17 ;
if ( V_238 -> V_142 . V_151 < ( V_238 -> V_142 . V_83 * V_142 -> V_172 [ 0 ] ) / 8 )
return - V_17 ;
if ( V_238 -> V_142 . V_13 * V_238 -> V_142 . V_151 < V_238 -> V_142 . V_152 )
return - V_17 ;
V_8 -> V_236 = F_109 ( ( unsigned long ) V_238 -> V_247 ) ;
V_8 -> V_182 = * V_238 ;
V_8 -> V_216 = F_99 ( int , V_8 -> V_216 ,
- V_8 -> V_182 . V_142 . V_83 , V_8 -> V_182 . V_142 . V_83 ) ;
V_8 -> V_215 = F_99 ( int , V_8 -> V_215 ,
- V_8 -> V_182 . V_142 . V_13 , V_8 -> V_182 . V_142 . V_13 ) ;
return 0 ;
}
int F_110 ( struct V_136 * V_136 , void * V_137 ,
struct V_249 * V_250 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_250 -> V_210 >= V_8 -> V_251 )
return - V_17 ;
V_250 -> type = V_252 ;
switch ( V_8 -> V_90 [ V_250 -> V_210 ] ) {
case V_92 :
snprintf ( V_250 -> V_253 , sizeof( V_250 -> V_253 ) , L_9 ,
V_8 -> V_254 [ V_250 -> V_210 ] ) ;
V_250 -> V_255 = 0 ;
break;
case V_100 :
snprintf ( V_250 -> V_253 , sizeof( V_250 -> V_253 ) , L_10 ,
V_8 -> V_254 [ V_250 -> V_210 ] ) ;
V_250 -> type = V_256 ;
V_250 -> V_257 = V_258 ;
if ( V_8 -> V_259 )
V_250 -> V_260 = ( 1 << F_76 ( V_261 ) ) - 1 ;
V_250 -> V_255 = V_262 ;
break;
case V_101 :
snprintf ( V_250 -> V_253 , sizeof( V_250 -> V_253 ) , L_11 ,
V_8 -> V_254 [ V_250 -> V_210 ] ) ;
V_250 -> V_257 = V_258 ;
if ( V_8 -> V_259 )
V_250 -> V_260 = ( 1 << F_76 ( V_261 ) ) - 1 ;
V_250 -> V_255 = V_262 ;
break;
case V_108 :
snprintf ( V_250 -> V_253 , sizeof( V_250 -> V_253 ) , L_12 ,
V_8 -> V_254 [ V_250 -> V_210 ] ) ;
V_250 -> V_255 = V_263 ;
if ( V_8 -> V_264 == 0 ||
V_8 -> V_68 == V_265 )
V_250 -> V_266 |= V_267 ;
else if ( V_8 -> V_68 == V_268 ||
V_8 -> V_68 == V_269 )
V_250 -> V_266 |= V_270 ;
break;
}
if ( V_8 -> V_271 )
V_250 -> V_266 |= V_272 ;
if ( V_8 -> V_273 )
V_250 -> V_266 |= V_274 ;
if ( V_8 -> V_91 == V_250 -> V_210 && F_13 ( V_8 ) ) {
if ( V_8 -> V_69 == V_265 ) {
V_250 -> V_266 |= V_267 ;
} else if ( V_8 -> V_69 == V_268 ) {
V_250 -> V_266 |= V_270 ;
} else if ( F_34 ( V_8 ) ) {
switch ( F_37 ( & V_8 -> V_10 ) ) {
case V_72 :
V_250 -> V_266 |= V_275 ;
break;
case V_67 :
V_250 -> V_266 |= V_270 ;
break;
default:
break;
}
}
}
return 0 ;
}
int F_111 ( struct V_136 * V_136 , void * V_137 , unsigned * V_52 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
* V_52 = V_8 -> V_91 ;
return 0 ;
}
int F_112 ( struct V_136 * V_136 , void * V_137 , unsigned V_52 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
struct V_86 * V_87 = & V_8 -> V_88 . V_87 ;
unsigned V_276 ;
if ( V_52 >= V_8 -> V_251 )
return - V_17 ;
if ( V_52 == V_8 -> V_91 )
return 0 ;
if ( F_73 ( & V_8 -> V_178 ) || F_73 ( & V_8 -> V_277 ) )
return - V_180 ;
V_8 -> V_91 = V_52 ;
V_8 -> V_278 . V_279 = 0 ;
if ( V_8 -> V_90 [ V_52 ] == V_100 || V_8 -> V_90 [ V_52 ] == V_101 ) {
V_8 -> V_280 = ( V_8 -> V_90 [ V_52 ] == V_100 ) ? 0 : 1 ;
V_8 -> V_278 . V_279 = V_258 ;
}
V_8 -> V_281 . V_279 = V_8 -> V_278 . V_279 ;
F_40 ( V_8 , false ) ;
if ( V_8 -> V_113 ) {
switch ( V_8 -> V_90 [ V_52 ] ) {
case V_92 :
F_46 ( V_8 -> V_113 , V_118 ) ;
break;
case V_100 :
case V_101 :
F_46 ( V_8 -> V_113 , V_115 ) ;
break;
case V_108 :
if ( V_87 -> V_36 & V_114 ) {
if ( V_8 -> V_82 . V_83 == 720 && V_8 -> V_82 . V_13 <= 576 )
F_46 ( V_8 -> V_113 , V_115 ) ;
else
F_46 ( V_8 -> V_113 , V_116 ) ;
} else {
F_46 ( V_8 -> V_113 , V_118 ) ;
}
break;
}
}
V_276 = 128 * V_52 + V_8 -> V_282 [ V_52 ] ;
F_113 ( V_8 -> V_276 ,
128 * V_52 , 255 + 128 * V_52 , 1 , 128 + 128 * V_52 ) ;
F_46 ( V_8 -> V_276 , V_276 ) ;
return 0 ;
}
int F_114 ( struct V_136 * V_136 , void * V_199 , struct V_283 * V_284 )
{
if ( V_284 -> V_210 >= F_76 ( V_261 ) )
return - V_17 ;
* V_284 = V_261 [ V_284 -> V_210 ] ;
return 0 ;
}
int F_115 ( struct V_136 * V_136 , void * V_199 , struct V_283 * V_284 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! F_13 ( V_8 ) )
return - V_17 ;
* V_284 = V_261 [ V_8 -> V_280 ] ;
return 0 ;
}
int F_116 ( struct V_136 * V_136 , void * V_199 , const struct V_283 * V_284 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! F_13 ( V_8 ) )
return - V_17 ;
if ( V_284 -> V_210 >= F_76 ( V_261 ) )
return - V_17 ;
V_8 -> V_280 = V_284 -> V_210 ;
return 0 ;
}
int F_117 ( struct V_136 * V_136 , void * V_199 , struct V_285 * V_286 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_286 -> V_287 != 0 )
return - V_17 ;
V_286 -> V_288 = V_8 -> V_71 ;
return 0 ;
}
int F_118 ( struct V_136 * V_136 , void * V_199 , const struct V_285 * V_286 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_286 -> V_287 != 0 )
return - V_17 ;
V_8 -> V_71 = F_99 ( unsigned , V_286 -> V_288 , V_289 , V_290 ) ;
if ( F_34 ( V_8 ) )
F_29 ( V_8 ) ;
return 0 ;
}
int F_119 ( struct V_136 * V_136 , void * V_199 , const struct V_291 * V_292 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_292 -> V_210 != 0 )
return - V_17 ;
if ( V_292 -> V_293 > V_294 )
return - V_17 ;
V_8 -> V_295 = V_292 -> V_293 ;
return 0 ;
}
int F_120 ( struct V_136 * V_136 , void * V_199 , struct V_291 * V_292 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
enum V_73 V_296 ;
if ( V_292 -> V_210 != 0 )
return - V_17 ;
V_292 -> V_239 = V_297 | V_298 |
V_299 | V_300 ;
V_292 -> V_293 = V_8 -> V_295 ;
V_292 -> V_301 = V_289 ;
V_292 -> V_302 = V_290 ;
V_296 = F_36 ( V_8 , & V_292 -> V_74 ) ;
if ( V_296 == V_70 )
V_292 -> signal = 0xffff ;
else if ( V_296 == V_72 )
V_292 -> signal = 0x8000 ;
else
V_292 -> signal = 0 ;
if ( V_296 == V_67 ) {
V_292 -> V_303 = 0 ;
} else if ( V_296 == V_72 ) {
V_292 -> V_303 = V_304 ;
} else {
unsigned V_305 = V_8 -> V_71 / ( 6 * 16 ) ;
unsigned V_306 = ( V_8 -> V_38 & V_307 ) ? 4 : 3 ;
switch ( V_305 % V_306 ) {
case 0 :
V_292 -> V_303 = V_304 ;
break;
case 1 :
V_292 -> V_303 = V_308 ;
break;
case 2 :
if ( V_8 -> V_38 & V_307 )
V_292 -> V_303 = V_304 | V_309 ;
else
V_292 -> V_303 = V_310 | V_311 ;
break;
case 3 :
V_292 -> V_303 = V_308 | V_309 ;
break;
}
}
F_121 ( V_292 -> V_253 , L_13 , sizeof( V_292 -> V_253 ) ) ;
return 0 ;
}
int F_122 ( struct V_136 * V_136 , void * V_137 , T_3 * V_312 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! F_13 ( V_8 ) )
return - V_313 ;
if ( V_8 -> V_69 == V_265 ||
V_8 -> V_69 == V_268 ) {
* V_312 = V_314 ;
return 0 ;
}
if ( F_34 ( V_8 ) && F_37 ( & V_8 -> V_10 ) == V_67 ) {
* V_312 = V_314 ;
} else if ( V_8 -> V_69 == V_315 ) {
* V_312 = V_8 -> V_38 ;
} else if ( V_8 -> V_69 == V_316 ) {
* V_312 = V_8 -> V_317 ;
} else {
* V_312 = V_318 [ V_8 -> V_319 ] ;
V_8 -> V_319 = ( V_8 -> V_319 + 1 ) % F_76 ( V_318 ) ;
}
return 0 ;
}
int F_123 ( struct V_136 * V_136 , void * V_137 , T_3 V_312 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! F_13 ( V_8 ) )
return - V_313 ;
if ( V_8 -> V_38 == V_312 )
return 0 ;
if ( F_73 ( & V_8 -> V_178 ) || F_73 ( & V_8 -> V_277 ) )
return - V_180 ;
V_8 -> V_38 = V_312 ;
F_40 ( V_8 , false ) ;
return 0 ;
}
static void F_124 ( V_111 V_83 , V_111 V_13 ,
V_111 * V_320 , V_111 * V_321 )
{
if ( ! ( V_13 % 3 ) && ( ( V_13 * 4 / 3 ) == V_83 ) ) {
* V_320 = 4 ;
* V_321 = 3 ;
} else if ( ! ( V_13 % 9 ) && ( ( V_13 * 16 / 9 ) == V_83 ) ) {
* V_320 = 16 ;
* V_321 = 9 ;
} else if ( ! ( V_13 % 10 ) && ( ( V_13 * 16 / 10 ) == V_83 ) ) {
* V_320 = 16 ;
* V_321 = 10 ;
} else if ( ! ( V_13 % 4 ) && ( ( V_13 * 5 / 4 ) == V_83 ) ) {
* V_320 = 5 ;
* V_321 = 4 ;
} else if ( ! ( V_13 % 9 ) && ( ( V_13 * 15 / 9 ) == V_83 ) ) {
* V_320 = 15 ;
* V_321 = 9 ;
} else {
* V_320 = 16 ;
* V_321 = 9 ;
}
}
static bool F_125 ( struct V_322 * V_323 )
{
struct V_86 * V_87 = & V_323 -> V_87 ;
V_111 V_324 ;
V_111 V_325 ;
V_111 V_326 ;
if ( ! F_126 ( V_323 , & V_327 ,
NULL , NULL ) )
return false ;
V_324 = F_42 ( V_87 ) ;
V_325 = F_43 ( V_87 ) ;
V_326 = ( V_111 ) V_87 -> V_89 / V_324 ;
if ( V_87 -> V_328 == 0 || ( V_87 -> V_328 & V_329 ) ) {
if ( F_127 ( V_325 , V_326 , V_87 -> V_330 , V_87 -> V_83 ,
V_87 -> V_331 , V_87 -> V_112 , V_323 ) )
return true ;
}
if ( V_87 -> V_328 == 0 || ( V_87 -> V_328 & V_332 ) ) {
struct V_103 V_333 ;
F_124 ( V_87 -> V_83 , V_87 -> V_13 ,
& V_333 . V_207 ,
& V_333 . V_208 ) ;
if ( F_128 ( V_325 , V_326 , V_87 -> V_330 ,
V_87 -> V_331 , V_87 -> V_112 ,
V_333 , V_323 ) )
return true ;
}
return false ;
}
int F_129 ( struct V_136 * V_136 , void * V_334 ,
struct V_322 * V_323 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! F_31 ( V_8 ) )
return - V_313 ;
if ( ! F_130 ( V_323 , & V_327 ,
0 , NULL , NULL ) &&
! F_125 ( V_323 ) )
return - V_17 ;
if ( F_131 ( V_323 , & V_8 -> V_88 , 0 , false ) )
return 0 ;
if ( F_73 ( & V_8 -> V_178 ) )
return - V_180 ;
V_8 -> V_88 = * V_323 ;
F_40 ( V_8 , false ) ;
return 0 ;
}
int F_132 ( struct V_136 * V_136 , void * V_334 ,
struct V_322 * V_323 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! F_31 ( V_8 ) )
return - V_313 ;
if ( V_8 -> V_68 == V_265 ||
V_8 -> V_264 == 0 )
return - V_335 ;
if ( V_8 -> V_68 == V_268 )
return - V_336 ;
if ( V_8 -> V_68 == V_269 ) {
V_323 -> V_87 . V_89 = V_327 . V_87 . V_337 * 2 ;
return - V_338 ;
}
if ( V_8 -> V_68 == V_339 ) {
* V_323 = V_8 -> V_88 ;
} else if ( V_8 -> V_68 == V_340 ) {
* V_323 = V_341 [ V_8 -> V_342 ] ;
} else {
* V_323 = V_341 [ V_8 -> V_343 ] ;
V_8 -> V_343 = ( V_8 -> V_343 + 1 ) %
V_8 -> V_344 ;
}
return 0 ;
}
int F_133 ( struct V_136 * V_136 , void * V_334 ,
struct V_345 * V_346 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
memset ( V_346 -> V_174 , 0 , sizeof( V_346 -> V_174 ) ) ;
if ( V_346 -> V_347 >= V_8 -> V_251 )
return - V_17 ;
if ( V_8 -> V_90 [ V_346 -> V_347 ] != V_108 || V_346 -> V_348 )
return - V_17 ;
if ( V_346 -> V_349 == 0 ) {
V_8 -> V_264 = 0 ;
return 0 ;
}
if ( V_346 -> V_349 > V_8 -> V_350 ) {
V_346 -> V_349 = V_8 -> V_350 ;
return - V_351 ;
}
V_8 -> V_264 = V_346 -> V_349 ;
memcpy ( V_8 -> V_346 , V_346 -> V_346 , V_346 -> V_349 * 128 ) ;
return 0 ;
}
int F_134 ( struct V_136 * V_136 , void * V_199 ,
struct V_352 * V_353 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( ! F_55 ( V_8 ) && ! V_8 -> V_163 )
return - V_17 ;
if ( F_67 ( V_8 , V_353 -> V_354 ) == NULL )
return - V_17 ;
if ( F_55 ( V_8 ) ) {
if ( V_353 -> V_210 >= F_76 ( V_93 ) )
return - V_17 ;
V_353 -> type = V_355 ;
V_353 -> V_356 = V_93 [ V_353 -> V_210 ] ;
return 0 ;
}
if ( V_353 -> V_210 )
return - V_17 ;
V_353 -> type = V_357 ;
V_353 -> V_358 . V_359 = V_360 ;
V_353 -> V_358 . V_361 = V_173 * V_171 ;
V_353 -> V_358 . V_362 = 2 ;
V_353 -> V_358 . V_363 = V_364 ;
V_353 -> V_358 . V_365 = V_366 * V_171 ;
V_353 -> V_358 . V_367 = 2 ;
return 0 ;
}
int F_135 ( struct V_136 * V_136 , void * V_137 ,
struct V_368 * V_369 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
const struct V_155 * V_142 ;
int V_52 ;
V_142 = F_67 ( V_8 , V_369 -> V_354 ) ;
if ( ! V_142 )
return - V_17 ;
if ( ! F_55 ( V_8 ) ) {
if ( V_369 -> V_210 )
return - V_17 ;
if ( V_369 -> V_83 < V_360 || V_369 -> V_83 > V_173 * V_171 )
return - V_17 ;
if ( V_369 -> V_13 < V_364 || V_369 -> V_13 > V_366 * V_171 )
return - V_17 ;
V_369 -> type = V_370 ;
V_369 -> V_356 = V_8 -> V_95 ;
return 0 ;
}
for ( V_52 = 0 ; V_52 < F_76 ( V_93 ) ; V_52 ++ )
if ( V_369 -> V_83 == V_93 [ V_52 ] . V_83 &&
V_369 -> V_13 == V_93 [ V_52 ] . V_13 )
break;
if ( V_52 == F_76 ( V_93 ) )
return - V_17 ;
if ( V_369 -> V_210 >= 2 * ( V_185 - V_52 ) )
return - V_17 ;
V_369 -> type = V_370 ;
V_369 -> V_356 = V_96 [ V_369 -> V_210 ] ;
return 0 ;
}
int F_136 ( struct V_136 * V_136 , void * V_137 ,
struct V_371 * V_372 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
if ( V_372 -> type != ( V_8 -> V_186 ?
V_373 :
V_190 ) )
return - V_17 ;
V_372 -> V_372 . V_374 . V_239 = V_375 ;
V_372 -> V_372 . V_374 . V_376 = V_8 -> V_95 ;
V_372 -> V_372 . V_374 . V_377 = 1 ;
return 0 ;
}
int F_137 ( struct V_136 * V_136 , void * V_137 ,
struct V_371 * V_372 )
{
struct V_7 * V_8 = F_64 ( V_136 ) ;
unsigned V_378 = 2 * ( V_185 - V_8 -> V_94 ) ;
struct V_103 V_379 ;
unsigned V_52 ;
if ( V_372 -> type != ( V_8 -> V_186 ?
V_373 :
V_190 ) )
return - V_17 ;
if ( ! F_55 ( V_8 ) )
return F_136 ( V_136 , V_137 , V_372 ) ;
V_379 = V_372 -> V_372 . V_374 . V_376 ;
if ( V_379 . V_208 == 0 )
V_379 = V_96 [ V_378 - 1 ] ;
for ( V_52 = 0 ; V_52 < V_378 ; V_52 ++ )
if ( F_138 ( V_379 , >= , V_96 [ V_52 ] ) )
break;
if ( V_52 == V_378 )
V_52 = V_378 - 1 ;
V_8 -> V_97 = V_52 ;
V_379 = V_96 [ V_8 -> V_97 ] ;
V_379 = F_138 ( V_379 , < , V_380 ) ? V_380 : V_379 ;
V_379 = F_138 ( V_379 , > , V_381 ) ? V_381 : V_379 ;
V_8 -> V_382 = true ;
V_8 -> V_95 = V_379 ;
V_372 -> V_372 . V_374 . V_376 = V_379 ;
V_372 -> V_372 . V_374 . V_377 = 1 ;
return 0 ;
}
