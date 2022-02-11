static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_6 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_9 = V_4 -> V_10 ;
V_8 -> V_11 = V_4 -> V_12 / 2 ;
V_8 -> V_13 = V_4 -> V_14 ;
V_8 -> V_15 = V_4 -> V_16 / 2 ;
V_8 -> V_17 = V_4 -> V_18 ;
V_8 -> V_19 = V_4 -> V_20 ;
V_8 -> V_21 = V_4 -> V_22 ;
V_8 -> V_23 = V_4 -> V_24 ;
V_8 -> V_25 = V_4 -> V_26 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_27 = false ;
int V_28 = 0 ;
V_4 -> V_10 = V_8 -> V_9 ;
V_4 -> V_12 = V_8 -> V_11 * 2 ;
V_4 -> V_14 = V_8 -> V_13 ;
V_4 -> V_16 = V_8 -> V_15 * 2 ;
V_4 -> V_18 = V_8 -> V_17 ;
V_4 -> V_20 = V_8 -> V_19 ;
V_4 -> V_22 = V_8 -> V_21 ;
V_4 -> V_24 = V_8 -> V_23 ;
if ( V_4 -> V_26 != V_8 -> V_25 ) {
T_1 V_29 = V_8 -> V_25 ;
V_29 = F_6 ( T_1 , V_29 ,
V_30 ,
V_31 ) ;
V_29 = F_7 ( V_29 , V_30 ) ;
V_4 -> V_26 = V_29 ;
V_27 = true ;
}
if ( F_8 ( V_2 ) ) {
if ( V_27 ) {
V_28 = F_9 ( V_4 , true , false ) ;
if ( ! V_28 )
V_28 = F_10 ( V_4 , true , false ) ;
} else {
V_28 = F_11 ( V_4 ) ;
}
}
return V_28 ;
}
static int F_12 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_32 ) {
case V_33 : {
int V_34 = V_35 * V_4 -> V_36 ;
if ( V_4 -> V_37 & V_38 )
V_34 += V_39 ;
return V_34 ;
}
default:
return - V_40 ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_41 * V_42 , T_2 * V_43 )
{
T_1 V_44 , V_45 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_46 = sizeof( struct V_47 ) * V_4 -> V_36 ;
T_1 V_48 = sizeof( struct V_47 ) / 8 ;
memset ( V_43 , 0 , V_46 ) ;
if ( ! V_4 -> V_49 )
return;
for ( V_44 = 0 ; V_44 < V_4 -> V_36 ; V_44 ++ ) {
struct V_50 * V_49 = V_4 -> V_49 [ V_44 ] ;
struct V_51 * V_52 = & V_49 -> V_53 ;
T_3 * V_54 = ( T_3 * ) V_52 -> V_54 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_48 ; V_45 ++ , V_55 ++ )
V_43 [ V_45 ] = F_14 ( V_54 [ V_55 ] ) ;
V_43 [ V_45 ++ ] = V_52 -> V_56 ;
}
if ( V_4 -> V_37 & V_38 ) {
T_3 * V_57 = ( T_3 * ) V_4 -> V_58 ;
for ( V_44 = 0 ; V_44 < V_39 ; V_44 ++ , V_45 ++ ) {
V_43 [ V_45 ] = F_14 ( * ( V_57 +
V_59 [ V_44 ] . V_60 ) ) ;
}
}
}
static void F_15 ( struct V_1 * V_2 , T_1 V_61 , T_4 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_44 ;
switch ( V_61 ) {
case V_33 :
for ( V_44 = 0 ; V_44 < V_4 -> V_36 ; V_44 ++ ) {
sprintf ( V_43 , L_1 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_2 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_3 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_4 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_5 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_6 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_7 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_8 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_9 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_10 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_11 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_12 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_13 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_14 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_15 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_16 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_17 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_18 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_19 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_20 , V_44 ) ;
V_43 += V_62 ;
sprintf ( V_43 , L_21 , V_44 ) ;
V_43 += V_62 ;
}
if ( V_4 -> V_37 & V_38 ) {
for ( V_44 = 0 ; V_44 < V_39 ; V_44 ++ ) {
strcpy ( V_43 , V_59 [ V_44 ] . string ) ;
V_43 += V_62 ;
}
}
break;
default:
F_16 ( V_4 -> V_2 , L_22 ,
V_61 ) ;
break;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
V_64 -> V_69 = V_70 ;
V_64 -> V_71 = V_4 -> V_72 ;
V_64 -> V_73 = V_4 -> V_74 ;
V_64 -> V_75 = V_4 -> V_76 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_64 -> V_71 > V_66 ) ||
( V_64 -> V_75 > V_70 ) ||
( V_64 -> V_75 <= V_77 ) )
return - V_78 ;
if ( F_8 ( V_2 ) )
F_9 ( V_4 , false , false ) ;
V_4 -> V_72 = V_64 -> V_71 ;
V_4 -> V_76 = V_64 -> V_75 ;
F_19 ( V_4 ) ;
if ( F_8 ( V_2 ) )
return F_10 ( V_4 , false , false ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_81 , V_82 , V_83 ;
F_21 ( V_4 , & V_81 , & V_82 , true ) ;
V_80 -> V_84 = F_22 ( int , V_81 , V_82 ) ;
if ( F_21 ( V_4 , & V_81 , & V_82 , false ) ) {
V_81 = 0 ;
V_82 = 0 ;
}
V_83 = F_23 ( V_2 ) ;
if ( V_83 > 1 )
V_82 /= V_83 ;
V_80 -> V_85 = V_81 ;
V_80 -> V_86 = V_82 ;
V_80 -> V_87 = 0 ;
if ( V_4 -> V_37 & V_88 ) {
V_80 -> V_89 = V_4 -> V_90 ;
if ( F_24 ( V_4 ) )
V_80 -> V_89 -- ;
} else {
if ( ! F_24 ( V_4 ) ) {
V_80 -> V_91 = V_4 -> V_90 ;
V_80 -> V_92 = V_4 -> V_93 ;
}
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_94 , V_95 , V_83 ;
bool V_96 = false ;
int V_97 = 0 ;
int V_28 = 0 ;
if ( V_80 -> V_98 )
return - V_78 ;
if ( ! V_80 -> V_89 &&
( ! V_80 -> V_91 || ! V_80 -> V_92 ) )
return - V_78 ;
if ( V_80 -> V_89 &&
( V_80 -> V_91 || V_80 -> V_92 ) )
return - V_78 ;
if ( F_24 ( V_4 ) && ( V_80 -> V_91 ||
V_80 -> V_92 ) )
return - V_78 ;
if ( V_80 -> V_89 )
V_96 = true ;
V_83 = F_23 ( V_2 ) ;
V_94 = V_96 ? V_80 -> V_89 : V_80 -> V_92 ;
V_95 = V_96 ? V_80 -> V_89 : V_80 -> V_91 ;
if ( V_4 -> V_99 ) {
if ( ! V_96 ) {
F_16 ( V_2 , L_23 ) ;
return - V_78 ;
}
V_97 = V_95 ;
}
V_28 = F_26 ( V_4 , V_94 , V_95 , V_83 , V_97 ) ;
if ( V_28 ) {
F_27 ( V_2 , L_24 ) ;
return V_28 ;
}
if ( F_8 ( V_2 ) ) {
if ( F_28 ( V_4 ) ) {
}
V_28 = F_9 ( V_4 , true , false ) ;
if ( V_28 ) {
F_16 ( V_4 -> V_2 , L_25 ,
V_28 ) ;
return V_28 ;
}
}
if ( V_96 ) {
V_4 -> V_37 |= V_88 ;
V_4 -> V_90 = V_80 -> V_89 ;
V_4 -> V_93 = V_80 -> V_89 ;
} else {
V_4 -> V_37 &= ~ V_88 ;
V_4 -> V_90 = V_80 -> V_91 ;
V_4 -> V_93 = V_80 -> V_92 ;
}
V_4 -> V_99 = V_97 ;
V_4 -> V_100 = V_4 -> V_93 + V_97 ;
if ( V_83 > 1 )
V_4 -> V_100 = V_4 -> V_93 * V_83 + V_97 ;
V_4 -> V_36 = V_96 ? F_29 ( int , V_4 -> V_100 , V_4 -> V_90 ) :
V_4 -> V_100 + V_4 -> V_90 ;
V_4 -> V_101 = V_4 -> V_36 ;
F_30 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
V_28 = F_10 ( V_4 , true , false ) ;
if ( ( ! V_28 ) && F_28 ( V_4 ) ) {
}
}
return V_28 ;
}
static int F_31 ( struct V_3 * V_4 , struct V_102 * V_103 ,
T_1 * V_104 )
{
int V_44 , V_45 = 0 ;
V_103 -> V_105 = V_4 -> V_106 ;
for ( V_44 = 0 ; V_44 < V_107 ; V_44 ++ ) {
struct V_108 * V_109 ;
struct V_110 * V_111 ;
V_109 = & V_4 -> V_112 [ V_44 ] ;
F_32 () ;
F_33 (fltr, head, hash) {
if ( V_45 == V_103 -> V_113 )
break;
V_104 [ V_45 ++ ] = V_111 -> V_114 ;
}
F_34 () ;
if ( V_45 == V_103 -> V_113 )
break;
}
V_103 -> V_113 = V_45 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 , struct V_102 * V_103 )
{
struct V_115 * V_116 =
(struct V_115 * ) & V_103 -> V_116 ;
struct V_110 * V_111 ;
struct V_117 * V_118 ;
int V_44 , V_28 = - V_78 ;
if ( V_116 -> V_119 < 0 || V_116 -> V_119 >= V_120 )
return V_28 ;
for ( V_44 = 0 ; V_44 < V_107 ; V_44 ++ ) {
struct V_108 * V_109 ;
V_109 = & V_4 -> V_112 [ V_44 ] ;
F_32 () ;
F_33 (fltr, head, hash) {
if ( V_111 -> V_114 == V_116 -> V_119 )
goto V_121;
}
F_34 () ;
}
return V_28 ;
V_121:
V_118 = & V_111 -> V_118 ;
if ( V_118 -> V_122 . V_123 == F_36 ( V_124 ) ) {
if ( V_118 -> V_122 . V_125 == V_126 )
V_116 -> V_127 = V_128 ;
else if ( V_118 -> V_122 . V_125 == V_129 )
V_116 -> V_127 = V_130 ;
else
goto V_131;
V_116 -> V_132 . V_133 . V_134 = V_118 -> V_135 . V_136 . V_137 ;
V_116 -> V_138 . V_133 . V_134 = F_37 ( ~ 0 ) ;
V_116 -> V_132 . V_133 . V_139 = V_118 -> V_135 . V_136 . V_140 ;
V_116 -> V_138 . V_133 . V_139 = F_37 ( ~ 0 ) ;
V_116 -> V_132 . V_133 . V_141 = V_118 -> V_142 . V_137 ;
V_116 -> V_138 . V_133 . V_141 = F_38 ( ~ 0 ) ;
V_116 -> V_132 . V_133 . V_143 = V_118 -> V_142 . V_140 ;
V_116 -> V_138 . V_133 . V_143 = F_38 ( ~ 0 ) ;
} else {
int V_44 ;
if ( V_118 -> V_122 . V_125 == V_126 )
V_116 -> V_127 = V_144 ;
else if ( V_118 -> V_122 . V_125 == V_129 )
V_116 -> V_127 = V_145 ;
else
goto V_131;
* (struct V_146 * ) & V_116 -> V_132 . V_147 . V_148 [ 0 ] =
V_118 -> V_135 . V_149 . V_137 ;
* (struct V_146 * ) & V_116 -> V_132 . V_147 . V_150 [ 0 ] =
V_118 -> V_135 . V_149 . V_140 ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ ) {
V_116 -> V_138 . V_147 . V_148 [ V_44 ] = F_37 ( ~ 0 ) ;
V_116 -> V_138 . V_147 . V_150 [ V_44 ] = F_37 ( ~ 0 ) ;
}
V_116 -> V_132 . V_147 . V_141 = V_118 -> V_142 . V_137 ;
V_116 -> V_138 . V_147 . V_141 = F_38 ( ~ 0 ) ;
V_116 -> V_132 . V_147 . V_143 = V_118 -> V_142 . V_140 ;
V_116 -> V_138 . V_147 . V_143 = F_38 ( ~ 0 ) ;
}
V_116 -> V_151 = V_111 -> V_152 ;
V_28 = 0 ;
V_131:
F_34 () ;
return V_28 ;
}
static T_2 F_39 ( struct V_3 * V_4 )
{
if ( V_4 -> V_153 & V_154 )
return V_155 | V_156 ;
return 0 ;
}
static T_2 F_40 ( struct V_3 * V_4 )
{
if ( V_4 -> V_153 & V_157 )
return V_155 | V_156 ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , struct V_102 * V_103 )
{
V_103 -> V_105 = 0 ;
switch ( V_103 -> V_127 ) {
case V_128 :
if ( V_4 -> V_153 & V_158 )
V_103 -> V_105 |= V_155 | V_156 |
V_159 | V_160 ;
V_103 -> V_105 |= F_39 ( V_4 ) ;
break;
case V_130 :
if ( V_4 -> V_153 & V_161 )
V_103 -> V_105 |= V_155 | V_156 |
V_159 | V_160 ;
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
V_103 -> V_105 |= F_39 ( V_4 ) ;
break;
case V_144 :
if ( V_4 -> V_153 & V_167 )
V_103 -> V_105 |= V_155 | V_156 |
V_159 | V_160 ;
V_103 -> V_105 |= F_40 ( V_4 ) ;
break;
case V_145 :
if ( V_4 -> V_153 & V_168 )
V_103 -> V_105 |= V_155 | V_156 |
V_159 | V_160 ;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
V_103 -> V_105 |= F_40 ( V_4 ) ;
break;
}
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , struct V_102 * V_103 )
{
T_1 V_153 = V_4 -> V_153 ;
int V_174 , V_28 = 0 ;
if ( V_103 -> V_105 == V_175 )
V_174 = 4 ;
else if ( V_103 -> V_105 == V_176 )
V_174 = 2 ;
else if ( ! V_103 -> V_105 )
V_174 = 0 ;
else
return - V_78 ;
if ( V_103 -> V_127 == V_128 ) {
V_153 &= ~ V_158 ;
if ( V_174 == 4 )
V_153 |= V_158 ;
} else if ( V_103 -> V_127 == V_130 ) {
if ( V_174 == 4 && ! ( V_4 -> V_37 & V_177 ) )
return - V_78 ;
V_153 &= ~ V_161 ;
if ( V_174 == 4 )
V_153 |= V_161 ;
} else if ( V_103 -> V_127 == V_144 ) {
V_153 &= ~ V_167 ;
if ( V_174 == 4 )
V_153 |= V_167 ;
} else if ( V_103 -> V_127 == V_145 ) {
if ( V_174 == 4 && ! ( V_4 -> V_37 & V_177 ) )
return - V_78 ;
V_153 &= ~ V_168 ;
if ( V_174 == 4 )
V_153 |= V_168 ;
} else if ( V_174 == 4 ) {
return - V_78 ;
}
switch ( V_103 -> V_127 ) {
case V_128 :
case V_130 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
if ( V_174 == 2 )
V_153 |= V_154 ;
else if ( ! V_174 )
V_153 &= ~ V_154 ;
break;
case V_144 :
case V_145 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
if ( V_174 == 2 )
V_153 |= V_157 ;
else if ( ! V_174 )
V_153 &= ~ V_157 ;
break;
}
if ( V_4 -> V_153 == V_153 )
return 0 ;
V_4 -> V_153 = V_153 ;
if ( F_8 ( V_4 -> V_2 ) ) {
F_9 ( V_4 , false , false ) ;
V_28 = F_10 ( V_4 , false , false ) ;
}
return V_28 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_102 * V_103 ,
T_1 * V_104 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 = 0 ;
switch ( V_103 -> V_103 ) {
#ifdef F_44
case V_178 :
V_103 -> V_105 = V_4 -> V_90 ;
break;
case V_179 :
V_103 -> V_113 = V_4 -> V_106 ;
V_103 -> V_105 = V_120 ;
break;
case V_180 :
V_28 = F_31 ( V_4 , V_103 , ( T_1 * ) V_104 ) ;
break;
case V_181 :
V_28 = F_35 ( V_4 , V_103 ) ;
break;
#endif
case V_182 :
V_28 = F_41 ( V_4 , V_103 ) ;
break;
default:
V_28 = - V_40 ;
break;
}
return V_28 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
switch ( V_103 -> V_103 ) {
case V_183 :
V_28 = F_42 ( V_4 , V_103 ) ;
break;
default:
V_28 = - V_40 ;
break;
}
return V_28 ;
}
static T_1 F_46 ( struct V_1 * V_2 )
{
return V_184 ;
}
static T_1 F_47 ( struct V_1 * V_2 )
{
return V_185 ;
}
static int F_48 ( struct V_1 * V_2 , T_1 * V_186 , T_4 * V_187 ,
T_4 * V_188 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_189 * V_190 = & V_4 -> V_191 [ 0 ] ;
int V_44 = 0 ;
if ( V_188 )
* V_188 = V_192 ;
if ( V_186 )
for ( V_44 = 0 ; V_44 < V_184 ; V_44 ++ )
V_186 [ V_44 ] = F_49 ( V_190 -> V_193 [ V_44 ] ) ;
if ( V_187 )
memcpy ( V_187 , V_190 -> V_194 , V_185 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_195 * V_196 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char * V_197 ;
char * V_198 = NULL ;
V_197 = F_51 ( V_199 , V_200 ) ;
if ( V_197 )
V_198 = F_52 ( V_2 , V_197 , V_199 ) ;
F_53 ( V_196 -> V_201 , V_202 , sizeof( V_196 -> V_201 ) ) ;
F_53 ( V_196 -> V_203 , V_204 , sizeof( V_196 -> V_203 ) ) ;
if ( V_198 && * V_198 != 0 && isdigit ( * V_198 ) )
snprintf ( V_196 -> V_205 , sizeof( V_196 -> V_205 ) - 1 ,
L_26 , V_4 -> V_206 , V_198 ) ;
else
F_53 ( V_196 -> V_205 , V_4 -> V_206 ,
sizeof( V_196 -> V_205 ) ) ;
F_53 ( V_196 -> V_207 , F_54 ( V_4 -> V_208 ) , sizeof( V_196 -> V_207 ) ) ;
V_196 -> V_209 = V_35 * V_4 -> V_36 ;
V_196 -> V_210 = F_55 ( V_4 ) ;
V_196 -> V_211 = 0 ;
V_196 -> V_212 = 0 ;
F_56 ( V_197 ) ;
}
T_1 F_57 ( T_5 V_213 , T_4 V_214 )
{
T_1 V_215 = 0 ;
if ( V_213 & V_216 )
V_215 |= V_217 ;
if ( V_213 & V_218 )
V_215 |= V_219 ;
if ( V_213 & V_220 )
V_215 |= V_221 ;
if ( V_213 & V_222 )
V_215 |= V_223 ;
if ( V_213 & V_224 )
V_215 |= V_225 ;
if ( ( V_214 & V_226 ) == V_226 )
V_215 |= V_227 ;
else if ( V_214 & V_228 )
V_215 |= V_229 ;
else if ( V_214 & V_230 )
V_215 |= V_227 | V_229 ;
return V_215 ;
}
static void F_58 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
T_5 V_213 = V_232 -> V_235 ;
T_4 V_214 = 0 ;
if ( V_232 -> V_236 & V_237 )
V_214 = V_232 -> V_238 ;
F_59 ( V_213 , V_214 , V_234 , V_235 ) ;
}
static void F_60 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
T_5 V_213 = V_232 -> V_239 ;
T_4 V_214 = 0 ;
if ( V_232 -> V_236 & V_237 )
V_214 = V_232 -> V_240 ;
F_59 ( V_213 , V_214 , V_234 ,
V_241 ) ;
}
static void F_61 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
T_5 V_213 = V_232 -> V_242 ;
F_59 ( V_213 , 0 , V_234 , V_243 ) ;
F_62 ( V_234 , V_243 , V_244 ) ;
F_62 ( V_234 , V_243 ,
V_245 ) ;
if ( V_232 -> V_246 )
F_62 ( V_234 , V_243 ,
V_247 ) ;
}
T_1 F_63 ( T_5 V_248 )
{
switch ( V_248 ) {
case V_249 :
return V_250 ;
case V_251 :
return V_252 ;
case V_253 :
return V_254 ;
case V_255 :
return V_256 ;
case V_257 :
return V_258 ;
case V_259 :
return V_260 ;
case V_261 :
return V_262 ;
case V_263 :
return V_264 ;
default:
return V_265 ;
}
}
static int F_64 ( struct V_1 * V_2 ,
struct V_233 * V_234 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_231 * V_232 = & V_4 -> V_232 ;
struct V_266 * V_267 = & V_234 -> V_267 ;
T_1 V_268 ;
F_65 ( V_234 , V_243 ) ;
F_61 ( V_232 , V_234 ) ;
F_65 ( V_234 , V_235 ) ;
if ( V_232 -> V_236 ) {
F_58 ( V_232 , V_234 ) ;
F_62 ( V_234 ,
V_235 , V_247 ) ;
V_267 -> V_236 = V_269 ;
if ( V_232 -> V_270 == V_271 )
F_60 ( V_232 , V_234 ) ;
V_268 = F_63 ( V_232 -> V_272 ) ;
if ( ! F_66 ( V_2 ) )
V_267 -> V_273 = V_274 ;
else if ( V_232 -> V_273 & V_275 )
V_267 -> V_273 = V_276 ;
else
V_267 -> V_273 = V_277 ;
} else {
V_267 -> V_236 = V_278 ;
V_268 =
F_63 ( V_232 -> V_279 ) ;
V_267 -> V_273 = V_277 ;
if ( V_232 -> V_280 == V_275 )
V_267 -> V_273 = V_276 ;
}
V_267 -> V_281 = V_268 ;
V_267 -> V_282 = V_283 ;
if ( V_232 -> V_284 == V_285 ) {
V_267 -> V_282 = V_286 ;
F_62 ( V_234 , V_243 ,
V_287 ) ;
F_62 ( V_234 , V_235 ,
V_287 ) ;
} else {
F_62 ( V_234 , V_243 ,
V_288 ) ;
F_62 ( V_234 , V_235 ,
V_288 ) ;
if ( V_232 -> V_284 == V_289 )
V_267 -> V_282 = V_290 ;
else if ( V_232 -> V_284 ==
V_291 )
V_267 -> V_282 = V_292 ;
}
V_267 -> V_293 = V_232 -> V_294 ;
return 0 ;
}
static T_1 F_67 ( struct V_1 * V_2 , T_5 V_268 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_231 * V_232 = & V_4 -> V_232 ;
T_5 V_295 = V_232 -> V_242 ;
T_1 V_296 = 0 ;
switch ( V_268 ) {
case V_250 :
if ( V_295 & V_216 )
V_296 = V_297 ;
break;
case V_252 :
if ( V_295 & V_218 )
V_296 = V_298 ;
break;
case V_254 :
if ( V_295 & V_220 )
V_296 = V_299 ;
break;
case V_256 :
if ( V_295 & V_222 )
V_296 = V_300 ;
break;
case V_258 :
if ( V_295 & V_301 )
V_296 = V_302 ;
break;
case V_260 :
if ( V_295 & V_303 )
V_296 = V_304 ;
break;
case V_262 :
if ( V_295 & V_224 )
V_296 = V_305 ;
break;
case V_264 :
if ( V_295 & V_306 )
V_296 = V_307 ;
break;
default:
F_16 ( V_2 , L_27 ) ;
break;
}
return V_296 ;
}
T_5 F_68 ( T_1 V_235 )
{
T_5 V_308 = 0 ;
if ( V_235 & ( V_217 |
V_309 ) ) {
V_308 |= V_216 ;
}
if ( V_235 & ( V_219 |
V_310 ) ) {
V_308 |= V_218 ;
}
if ( V_235 & V_223 )
V_308 |= V_222 ;
if ( V_235 & V_225 )
V_308 |= V_224 ;
return V_308 ;
}
static int F_69 ( struct V_1 * V_2 ,
const struct V_233 * V_234 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_231 * V_232 = & V_4 -> V_232 ;
const struct V_266 * V_267 = & V_234 -> V_267 ;
bool V_311 = false ;
T_5 V_312 = 0 ;
T_1 V_281 ;
int V_28 = 0 ;
if ( ! F_70 ( V_4 ) )
return - V_40 ;
if ( V_267 -> V_236 == V_269 ) {
F_71 ( V_312 , V_234 ,
V_235 ) ;
V_232 -> V_236 |= V_313 ;
if ( ! V_312 )
V_232 -> V_235 = V_232 -> V_246 ;
else
V_232 -> V_235 = V_312 ;
V_311 = true ;
} else {
T_5 V_296 ;
T_4 V_314 = V_232 -> V_314 ;
if ( V_314 == V_315 ||
V_314 == V_316 ||
V_232 -> V_284 == V_285 ) {
F_16 ( V_2 , L_28 ) ;
V_28 = - V_78 ;
goto V_317;
}
if ( V_267 -> V_273 == V_277 ) {
F_16 ( V_2 , L_29 ) ;
V_28 = - V_78 ;
goto V_317;
}
V_281 = V_267 -> V_281 ;
V_296 = F_67 ( V_2 , V_281 ) ;
if ( ! V_296 ) {
V_28 = - V_78 ;
goto V_317;
}
V_232 -> V_279 = V_296 ;
V_232 -> V_280 = V_275 ;
V_232 -> V_236 = 0 ;
V_232 -> V_235 = 0 ;
}
if ( F_8 ( V_2 ) )
V_28 = F_72 ( V_4 , V_311 , false ) ;
V_317:
return V_28 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_318 * V_319 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_231 * V_232 = & V_4 -> V_232 ;
if ( F_74 ( V_4 ) )
return;
V_319 -> V_236 = ! ! ( V_232 -> V_236 & V_237 ) ;
V_319 -> V_320 = ! ! ( V_232 -> V_321 & V_230 ) ;
V_319 -> V_322 = ! ! ( V_232 -> V_321 & V_228 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_318 * V_319 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_231 * V_232 = & V_4 -> V_232 ;
if ( ! F_70 ( V_4 ) )
return - V_40 ;
if ( V_319 -> V_236 ) {
if ( ! ( V_232 -> V_236 & V_313 ) )
return - V_78 ;
V_232 -> V_236 |= V_237 ;
if ( V_4 -> V_323 >= 0x10201 )
V_232 -> V_321 =
V_324 ;
} else {
if ( V_232 -> V_236 & V_237 )
V_232 -> V_325 = true ;
V_232 -> V_236 &= ~ V_237 ;
V_232 -> V_321 = 0 ;
}
if ( V_319 -> V_320 )
V_232 -> V_321 |= V_230 ;
if ( V_319 -> V_322 )
V_232 -> V_321 |= V_228 ;
if ( F_8 ( V_2 ) )
V_28 = F_76 ( V_4 ) ;
return V_28 ;
}
static T_1 F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_232 . V_326 ;
}
static int F_78 ( struct V_1 * V_2 ,
T_5 V_327 ,
T_5 V_328 ,
T_5 V_329 ,
T_5 V_330 ,
const T_4 * V_105 ,
T_6 V_331 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_332 V_333 = { 0 } ;
T_7 V_334 ;
T_4 * V_335 ;
F_79 ( V_4 , & V_333 , V_336 , - 1 , - 1 ) ;
V_333 . V_327 = F_80 ( V_327 ) ;
V_333 . V_328 = F_80 ( V_328 ) ;
V_333 . V_329 = F_80 ( V_329 ) ;
V_333 . V_330 = F_80 ( V_330 ) ;
V_333 . V_337 = F_81 ( V_331 ) ;
V_335 = F_82 ( & V_4 -> V_208 -> V_2 , V_331 , & V_334 ,
V_200 ) ;
if ( ! V_335 ) {
F_16 ( V_2 , L_30 ,
( unsigned ) V_331 ) ;
return - V_338 ;
}
memcpy ( V_335 , V_105 , V_331 ) ;
V_333 . V_339 = F_83 ( V_334 ) ;
V_28 = F_84 ( V_4 , & V_333 , sizeof( V_333 ) , V_340 ) ;
F_85 ( & V_4 -> V_208 -> V_2 , V_331 , V_335 , V_334 ) ;
return V_28 ;
}
static int F_86 ( struct V_1 * V_2 ,
T_5 V_327 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_341 V_333 = { 0 } ;
F_79 ( V_4 , & V_333 , V_342 , - 1 , - 1 ) ;
switch ( V_327 ) {
case V_343 :
case V_344 :
case V_345 :
V_333 . V_346 = V_347 ;
V_333 . V_348 = V_349 ;
break;
case V_350 :
case V_351 :
V_333 . V_346 = V_352 ;
V_333 . V_348 = V_349 ;
break;
case V_353 :
case V_354 :
V_333 . V_346 =
V_355 ;
break;
case V_356 :
case V_357 :
V_333 . V_346 = V_358 ;
break;
default:
return - V_78 ;
}
return F_84 ( V_4 , & V_333 , sizeof( V_333 ) , V_359 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
T_5 V_327 ,
const T_4 * V_360 ,
T_6 V_361 )
{
int V_28 = 0 ;
T_5 V_362 ;
T_1 V_363 ;
T_1 V_364 ;
struct V_365 * V_366 = (struct V_365 * ) V_360 ;
switch ( V_327 ) {
case V_344 :
case V_345 :
V_362 = V_367 ;
break;
case V_343 :
V_362 = V_368 ;
break;
case V_350 :
V_362 = V_369 ;
break;
case V_351 :
V_362 = V_370 ;
break;
case V_353 :
V_362 = V_371 ;
break;
case V_354 :
V_362 = V_372 ;
break;
case V_356 :
V_362 = V_373 ;
break;
case V_357 :
V_362 = V_374 ;
break;
default:
F_16 ( V_2 , L_31 ,
V_327 ) ;
return - V_78 ;
}
if ( V_361 < sizeof( struct V_365 ) ) {
F_16 ( V_2 , L_32 ,
( unsigned int ) V_361 ) ;
return - V_78 ;
}
if ( V_366 -> V_375 != F_81 ( V_376 ) ) {
F_16 ( V_2 , L_33 ,
F_88 ( V_366 -> V_375 ) ) ;
return - V_78 ;
}
if ( V_366 -> V_362 != V_362 ) {
F_16 ( V_2 , L_34 ,
V_362 , V_366 -> V_362 ) ;
return - V_78 ;
}
if ( V_366 -> V_377 != V_378 ) {
F_16 ( V_2 , L_35 ,
V_378 , V_366 -> V_377 ) ;
return - V_78 ;
}
V_363 = F_88 ( * ( V_379 * ) ( V_360 + V_361 -
sizeof( V_363 ) ) ) ;
V_364 = ~ F_89 ( ~ 0 , V_360 , V_361 - sizeof( V_363 ) ) ;
if ( V_364 != V_363 ) {
F_16 ( V_2 , L_36 ,
( unsigned long ) V_363 ,
( unsigned long ) V_364 ) ;
return - V_78 ;
}
V_28 = F_78 ( V_2 , V_327 , V_380 ,
0 , 0 , V_360 , V_361 ) ;
if ( V_28 == 0 )
V_28 = F_86 ( V_2 , V_327 ) ;
return V_28 ;
}
static int F_90 ( struct V_1 * V_2 ,
T_5 V_327 ,
const T_4 * V_360 ,
T_6 V_361 )
{
struct V_381 * V_382 ;
T_1 V_364 ;
T_1 V_363 ;
int V_28 = 0 ;
if ( V_361 < sizeof( struct V_381 ) ) {
F_16 ( V_2 , L_37 ,
( unsigned int ) V_361 ) ;
return - V_78 ;
}
V_382 = (struct V_381 * ) ( V_360 + ( V_361 -
sizeof( * V_382 ) ) ) ;
if ( V_382 -> V_383 != F_81 ( V_384 ) ) {
F_16 ( V_2 , L_38 ,
F_88 ( V_382 -> V_383 ) ) ;
return - V_78 ;
}
if ( F_49 ( V_382 -> V_327 ) != V_327 ) {
F_16 ( V_2 , L_39 ,
V_327 , F_49 ( V_382 -> V_327 ) ) ;
return - V_78 ;
}
if ( F_49 ( V_382 -> V_385 ) <
sizeof( struct V_381 ) ) {
F_16 ( V_2 , L_40 ,
F_49 ( V_382 -> V_385 ) ) ;
return - V_78 ;
}
V_363 = F_88 ( * ( V_379 * ) ( V_360 + V_361 -
sizeof( V_363 ) ) ) ;
V_364 = ~ F_89 ( ~ 0 , V_360 , V_361 - sizeof( V_363 ) ) ;
if ( V_364 != V_363 ) {
F_16 ( V_2 ,
L_41 ,
( unsigned long ) V_363 ,
( unsigned long ) V_364 ) ;
return - V_78 ;
}
V_28 = F_78 ( V_2 , V_327 , V_380 ,
0 , 0 , V_360 , V_361 ) ;
return V_28 ;
}
static bool F_91 ( T_5 V_327 )
{
switch ( V_327 ) {
case V_343 :
case V_344 :
case V_345 :
case V_350 :
case V_351 :
case V_353 :
case V_354 :
case V_356 :
case V_357 :
return true ;
}
return false ;
}
static bool F_92 ( T_5 V_327 )
{
switch ( V_327 ) {
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
return true ;
}
return false ;
}
static bool F_93 ( T_5 V_327 )
{
return F_91 ( V_327 ) ||
F_92 ( V_327 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
T_5 V_327 ,
const char * V_395 )
{
const struct V_396 * V_397 ;
int V_28 ;
V_28 = F_95 ( & V_397 , V_395 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_16 ( V_2 , L_42 ,
V_28 , V_395 ) ;
return V_28 ;
}
if ( F_91 ( V_327 ) == true )
V_28 = F_87 ( V_2 , V_327 , V_397 -> V_105 , V_397 -> V_398 ) ;
else if ( F_92 ( V_327 ) == true )
V_28 = F_90 ( V_2 , V_327 , V_397 -> V_105 , V_397 -> V_398 ) ;
else
V_28 = F_78 ( V_2 , V_327 , V_380 ,
0 , 0 , V_397 -> V_105 , V_397 -> V_398 ) ;
F_96 ( V_397 ) ;
return V_28 ;
}
static int F_97 ( struct V_1 * V_2 ,
char * V_395 , T_1 V_399 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_400 * V_401 = V_4 -> V_402 ;
struct V_403 V_404 = { 0 } ;
const struct V_396 * V_397 ;
T_1 V_405 ;
T_5 V_406 ;
int V_28 ;
F_98 ( V_4 ) ;
if ( F_99 ( V_2 , V_407 ,
V_380 , V_408 ,
& V_406 , & V_405 , NULL ) != 0 ) {
F_16 ( V_2 , L_43 ) ;
return - V_409 ;
}
V_28 = F_95 ( & V_397 , V_395 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_16 ( V_2 , L_44 ,
V_28 , V_395 ) ;
return V_28 ;
}
if ( V_397 -> V_398 > V_405 ) {
F_16 ( V_2 , L_45 ,
( unsigned long ) V_397 -> V_398 ) ;
V_28 = - V_410 ;
} else {
T_7 V_334 ;
T_4 * V_335 ;
struct V_411 V_412 = { 0 } ;
F_79 ( V_4 , & V_412 , V_413 , - 1 , - 1 ) ;
V_412 . V_414 = F_80 ( V_406 ) ;
V_412 . V_415 = F_81 ( V_397 -> V_398 ) ;
V_335 = F_82 ( & V_4 -> V_208 -> V_2 , V_397 -> V_398 ,
& V_334 , V_200 ) ;
if ( ! V_335 ) {
F_16 ( V_2 ,
L_30 ,
( unsigned int ) V_397 -> V_398 ) ;
V_28 = - V_338 ;
} else {
memcpy ( V_335 , V_397 -> V_105 , V_397 -> V_398 ) ;
V_412 . V_339 = F_83 ( V_334 ) ;
V_28 = F_84 ( V_4 , & V_412 , sizeof( V_412 ) ,
V_416 ) ;
F_85 ( & V_4 -> V_208 -> V_2 , V_397 -> V_398 , V_335 ,
V_334 ) ;
}
}
F_96 ( V_397 ) ;
if ( V_28 )
return V_28 ;
if ( ( V_399 & 0xffff ) == 0 )
V_399 >>= 16 ;
F_79 ( V_4 , & V_404 , V_417 , - 1 , - 1 ) ;
V_404 . V_399 = F_81 ( V_399 ) ;
F_100 ( & V_4 -> V_418 ) ;
V_28 = F_101 ( V_4 , & V_404 , sizeof( V_404 ) ,
V_419 ) ;
if ( V_28 ) {
V_28 = - V_40 ;
goto V_420;
}
if ( V_401 -> V_421 ) {
T_4 V_421 = ( (struct V_422 * ) V_401 ) -> V_423 ;
if ( V_421 == V_424 ) {
V_404 . V_37 |= F_80 (
V_425 ) ;
V_28 = F_101 ( V_4 , & V_404 , sizeof( V_404 ) ,
V_419 ) ;
if ( V_28 ) {
V_28 = - V_40 ;
goto V_420;
}
}
}
if ( V_401 -> V_426 ) {
F_16 ( V_2 , L_46 ,
( V_427 ) V_401 -> V_426 , ( int ) V_401 -> V_428 ) ;
V_28 = - V_429 ;
}
V_420:
F_102 ( & V_4 -> V_418 ) ;
return V_28 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_430 * V_431 )
{
if ( ! F_28 ( (struct V_3 * ) F_2 ( V_2 ) ) ) {
F_16 ( V_2 , L_47 ) ;
return - V_78 ;
}
if ( V_431 -> V_432 == V_433 ||
V_431 -> V_432 > 0xffff )
return F_97 ( V_2 , V_431 -> V_105 ,
V_431 -> V_432 ) ;
return F_94 ( V_2 , V_431 -> V_432 , V_431 -> V_105 ) ;
}
static int F_104 ( struct V_1 * V_2 , T_1 * V_434 , T_1 * V_435 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_436 V_333 = { 0 } ;
struct V_437 * V_438 = V_4 -> V_402 ;
F_79 ( V_4 , & V_333 , V_439 , - 1 , - 1 ) ;
F_100 ( & V_4 -> V_418 ) ;
V_28 = F_101 ( V_4 , & V_333 , sizeof( V_333 ) , V_359 ) ;
if ( ! V_28 ) {
* V_434 = F_88 ( V_438 -> V_434 ) ;
* V_435 = F_88 ( V_438 -> V_440 ) ;
}
F_102 ( & V_4 -> V_418 ) ;
return V_28 ;
}
static int F_105 ( struct V_1 * V_2 )
{
return - 1 ;
}
static int F_106 ( struct V_1 * V_2 , T_1 V_415 , T_4 * V_105 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_1 V_441 ;
T_1 V_440 ;
T_4 * V_43 ;
T_6 V_442 ;
T_7 V_334 ;
struct V_443 V_333 = { 0 } ;
V_28 = F_104 ( V_2 , & V_441 , & V_440 ) ;
if ( V_28 != 0 )
return V_28 ;
if ( V_415 < 2 )
return - V_78 ;
* V_105 ++ = V_441 ;
* V_105 ++ = V_440 ;
V_415 -= 2 ;
memset ( V_105 , 0xff , V_415 ) ;
V_442 = V_441 * V_440 ;
V_43 = F_82 ( & V_4 -> V_208 -> V_2 , V_442 , & V_334 ,
V_200 ) ;
if ( ! V_43 ) {
F_16 ( V_2 , L_30 ,
( unsigned ) V_442 ) ;
return - V_338 ;
}
F_79 ( V_4 , & V_333 , V_444 , - 1 , - 1 ) ;
V_333 . V_445 = F_83 ( V_334 ) ;
V_28 = F_84 ( V_4 , & V_333 , sizeof( V_333 ) , V_359 ) ;
if ( V_28 == 0 )
memcpy ( V_105 , V_43 , V_415 > V_442 ? V_442 : V_415 ) ;
F_85 ( & V_4 -> V_208 -> V_2 , V_442 , V_43 , V_334 ) ;
return V_28 ;
}
static int F_107 ( struct V_1 * V_2 , T_1 V_406 , T_1 V_60 ,
T_1 V_435 , T_4 * V_105 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_4 * V_43 ;
T_7 V_334 ;
struct V_446 V_333 = { 0 } ;
V_43 = F_82 ( & V_4 -> V_208 -> V_2 , V_435 , & V_334 ,
V_200 ) ;
if ( ! V_43 ) {
F_16 ( V_2 , L_30 ,
( unsigned ) V_435 ) ;
return - V_338 ;
}
F_79 ( V_4 , & V_333 , V_447 , - 1 , - 1 ) ;
V_333 . V_445 = F_83 ( V_334 ) ;
V_333 . V_414 = F_80 ( V_406 ) ;
V_333 . V_60 = F_81 ( V_60 ) ;
V_333 . V_415 = F_81 ( V_435 ) ;
V_28 = F_84 ( V_4 , & V_333 , sizeof( V_333 ) , V_359 ) ;
if ( V_28 == 0 )
memcpy ( V_105 , V_43 , V_435 ) ;
F_85 ( & V_4 -> V_208 -> V_2 , V_435 , V_43 , V_334 ) ;
return V_28 ;
}
static int F_99 ( struct V_1 * V_2 , T_5 type , T_5 V_448 ,
T_5 V_449 , T_5 * V_406 , T_1 * V_450 ,
T_1 * V_451 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_452 V_333 = { 0 } ;
struct V_453 * V_438 = V_4 -> V_402 ;
F_79 ( V_4 , & V_333 , V_454 , - 1 , - 1 ) ;
V_333 . V_455 = 0 ;
V_333 . V_414 = 0 ;
V_333 . V_327 = F_80 ( type ) ;
V_333 . V_328 = F_80 ( V_448 ) ;
V_333 . V_329 = F_80 ( V_449 ) ;
V_333 . V_456 = V_457 ;
V_28 = F_108 ( V_4 , & V_333 , sizeof( V_333 ) , V_359 ) ;
if ( V_28 == 0 ) {
if ( V_406 )
* V_406 = F_49 ( V_438 -> V_414 ) ;
if ( V_450 )
* V_450 = F_88 ( V_438 -> V_458 ) ;
if ( V_451 )
* V_451 = F_88 ( V_438 -> V_337 ) ;
}
return V_28 ;
}
static char * F_109 ( int V_459 , T_4 * V_105 , T_6 V_460 )
{
char * V_461 = NULL ;
char * V_462 ;
char * V_6 ;
int V_463 = 0 ;
if ( V_460 < 1 )
return NULL ;
V_105 [ V_460 - 1 ] = 0 ;
for ( V_462 = V_105 ; * V_462 != 0 ; V_462 ++ ) {
V_463 = 0 ;
V_461 = NULL ;
while ( * V_462 != 0 && * V_462 != '\n' ) {
V_6 = V_462 ;
while ( * V_462 != 0 && * V_462 != '\t' && * V_462 != '\n' )
V_462 ++ ;
if ( V_463 == V_459 )
V_461 = V_6 ;
if ( * V_462 != '\t' )
break;
* V_462 = 0 ;
V_463 ++ ;
V_462 ++ ;
}
if ( * V_462 == 0 )
break;
* V_462 = 0 ;
}
return V_461 ;
}
static char * F_52 ( struct V_1 * V_2 , char * V_43 , T_6 V_442 )
{
T_5 V_406 = 0 ;
T_1 V_460 ;
if ( F_99 ( V_2 , V_464 ,
V_380 , V_408 ,
& V_406 , NULL , & V_460 ) != 0 )
return NULL ;
memset ( V_43 , 0 , V_442 ) ;
if ( F_107 ( V_2 , V_406 , 0 , V_460 , V_43 ) != 0 )
return NULL ;
return F_109 ( V_465 , V_43 ,
V_460 ) ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_466 * V_467 ,
T_4 * V_105 )
{
T_1 V_406 ;
T_1 V_60 ;
if ( V_467 -> V_60 == 0 )
return F_106 ( V_2 , V_467 -> V_415 , V_105 ) ;
V_406 = V_467 -> V_60 >> 24 ;
V_60 = V_467 -> V_60 & 0xffffff ;
if ( V_406 == 0 ) {
F_16 ( V_2 , L_48 , V_406 ) ;
return - V_78 ;
}
return F_107 ( V_2 , V_406 - 1 , V_60 , V_467 -> V_415 , V_105 ) ;
}
static int F_111 ( struct V_1 * V_2 , T_4 V_406 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_468 V_333 = { 0 } ;
F_79 ( V_4 , & V_333 , V_469 , - 1 , - 1 ) ;
V_333 . V_414 = F_80 ( V_406 ) ;
return F_84 ( V_4 , & V_333 , sizeof( V_333 ) , V_359 ) ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_466 * V_467 ,
T_4 * V_105 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_406 , V_470 ;
T_5 type , V_449 , V_448 , V_471 ;
if ( ! F_28 ( V_4 ) ) {
F_16 ( V_2 , L_49 ) ;
return - V_78 ;
}
type = V_467 -> V_472 >> 16 ;
if ( type == 0xffff ) {
V_406 = V_467 -> V_472 & 0xff ;
V_470 = V_467 -> V_472 >> 8 ;
if ( V_406 == 0 )
return - V_78 ;
switch ( V_470 ) {
case 0x0e :
if ( V_467 -> V_60 != ~ V_467 -> V_472 )
return - V_78 ;
return F_111 ( V_2 , V_406 - 1 ) ;
default:
return - V_78 ;
}
}
if ( F_93 ( type ) == true )
return - V_40 ;
V_449 = V_467 -> V_472 & 0xffff ;
V_448 = V_467 -> V_60 >> 16 ;
V_471 = V_467 -> V_60 & 0xffff ;
return F_78 ( V_2 , type , V_448 , V_449 , V_471 , V_105 ,
V_467 -> V_415 ) ;
}
static int F_113 ( struct V_1 * V_2 , struct V_473 * V_474 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_473 * V_475 = & V_4 -> V_475 ;
struct V_231 * V_232 = & V_4 -> V_232 ;
T_1 V_235 =
F_57 ( V_232 -> V_235 , 0 ) ;
int V_28 = 0 ;
if ( ! F_70 ( V_4 ) )
return - V_40 ;
if ( ! ( V_4 -> V_37 & V_476 ) )
return - V_40 ;
if ( ! V_474 -> V_477 )
goto V_478;
if ( ! ( V_232 -> V_236 & V_313 ) ) {
F_27 ( V_2 , L_50 ) ;
return - V_78 ;
}
if ( V_474 -> V_479 ) {
if ( V_4 -> V_480 && ( V_474 -> V_481 > V_4 -> V_480 ||
V_474 -> V_481 < V_4 -> V_482 ) ) {
F_27 ( V_2 , L_51 ,
V_4 -> V_482 , V_4 -> V_480 ) ;
return - V_78 ;
} else if ( ! V_4 -> V_480 ) {
V_474 -> V_481 = V_475 -> V_481 ;
}
}
if ( ! V_474 -> V_483 ) {
V_474 -> V_483 = V_235 & V_475 -> V_243 ;
} else if ( V_474 -> V_483 & ~ V_235 ) {
F_27 ( V_2 , L_52 ,
V_474 -> V_483 , V_235 ) ;
return - V_78 ;
}
V_475 -> V_483 = V_474 -> V_483 ;
V_475 -> V_479 = V_474 -> V_479 ;
V_475 -> V_481 = V_474 -> V_481 ;
V_478:
V_475 -> V_477 = V_474 -> V_477 ;
if ( F_8 ( V_2 ) )
V_28 = F_72 ( V_4 , false , true ) ;
return V_28 ;
}
static int F_114 ( struct V_1 * V_2 , struct V_473 * V_474 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_4 -> V_37 & V_476 ) )
return - V_40 ;
* V_474 = V_4 -> V_475 ;
if ( ! V_4 -> V_475 . V_477 ) {
V_474 -> V_483 = 0 ;
V_474 -> V_479 = 0 ;
}
if ( ! V_4 -> V_475 . V_484 )
V_474 -> V_485 = 0 ;
return 0 ;
}
static int F_115 ( struct V_3 * V_4 , T_5 V_486 ,
T_5 V_487 , T_5 V_488 ,
T_5 V_451 , T_4 * V_43 )
{
struct V_489 V_333 = { 0 } ;
struct V_490 * V_438 = V_4 -> V_402 ;
int V_28 , V_491 = 0 ;
F_79 ( V_4 , & V_333 , V_492 , - 1 , - 1 ) ;
V_333 . V_493 = V_486 ;
V_333 . V_487 = F_80 ( V_487 ) ;
V_333 . V_494 = F_80 ( V_4 -> V_495 . V_494 ) ;
do {
T_5 V_496 ;
V_496 = F_22 ( T_5 , V_451 , V_497 ) ;
V_451 -= V_496 ;
V_333 . V_498 = F_80 ( V_488 + V_491 ) ;
V_333 . V_451 = V_496 ;
V_333 . V_455 = F_81 ( V_488 + V_491 ?
V_499 : 0 ) ;
F_100 ( & V_4 -> V_418 ) ;
V_28 = F_101 ( V_4 , & V_333 , sizeof( V_333 ) ,
V_359 ) ;
if ( ! V_28 )
memcpy ( V_43 + V_491 , V_438 -> V_105 , V_496 ) ;
F_102 ( & V_4 -> V_418 ) ;
V_491 += V_496 ;
} while ( ! V_28 && V_451 > 0 );
return V_28 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_500 * V_501 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_489 V_333 = { 0 } ;
struct V_490 * V_438 = V_4 -> V_402 ;
int V_28 ;
if ( V_4 -> V_232 . V_502 >
V_503 )
return - V_40 ;
if ( V_4 -> V_323 < 0x10202 )
return - V_40 ;
F_79 ( V_4 , & V_333 , V_492 , - 1 , - 1 ) ;
V_333 . V_493 = V_504 ;
V_333 . V_487 = 0 ;
V_333 . V_498 = F_80 ( V_505 ) ;
V_333 . V_451 = V_506 ;
V_333 . V_494 = F_80 ( V_4 -> V_495 . V_494 ) ;
F_100 ( & V_4 -> V_418 ) ;
V_28 = F_101 ( V_4 , & V_333 , sizeof( V_333 ) , V_359 ) ;
if ( ! V_28 ) {
T_1 V_507 = F_88 ( V_438 -> V_105 [ 0 ] ) ;
switch ( V_507 ) {
case V_508 :
V_501 -> type = V_509 ;
V_501 -> V_510 = V_511 ;
break;
case V_512 :
case V_513 :
V_501 -> type = V_514 ;
V_501 -> V_510 = V_515 ;
break;
case V_516 :
V_501 -> type = V_517 ;
V_501 -> V_510 = V_518 ;
break;
default:
V_28 = - V_40 ;
break;
}
}
F_102 ( & V_4 -> V_418 ) ;
return V_28 ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_466 * V_467 ,
T_4 * V_105 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_5 V_519 = V_467 -> V_60 , V_435 = V_467 -> V_415 ;
int V_28 = 0 ;
memset ( V_105 , 0 , V_467 -> V_415 ) ;
if ( V_519 < V_515 ) {
if ( V_519 + V_467 -> V_415 > V_515 )
V_435 = V_515 - V_519 ;
V_28 = F_115 ( V_4 , V_504 , 0 ,
V_519 , V_435 , V_105 ) ;
if ( V_28 )
return V_28 ;
V_519 += V_435 ;
V_105 += V_435 ;
V_435 = V_467 -> V_415 - V_435 ;
}
if ( V_435 ) {
V_519 -= V_515 ;
F_115 ( V_4 , V_520 , 1 , V_519 ,
V_435 , V_105 ) ;
}
return V_28 ;
}
static int F_118 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_231 * V_232 = & V_4 -> V_232 ;
if ( ! F_70 ( V_4 ) )
return - V_40 ;
if ( ! ( V_232 -> V_236 & V_313 ) )
return - V_78 ;
if ( F_8 ( V_2 ) )
V_28 = F_72 ( V_4 , true , false ) ;
return V_28 ;
}
static int F_119 ( struct V_1 * V_2 ,
enum V_521 V_522 )
{
struct V_523 V_333 = { 0 } ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_524 * V_495 = & V_4 -> V_495 ;
struct V_525 * V_526 ;
T_4 V_527 ;
T_8 V_528 ;
int V_44 , V_28 ;
if ( ! V_4 -> V_529 || F_74 ( V_4 ) )
return - V_40 ;
if ( V_522 == V_530 ) {
V_527 = V_531 ;
V_528 = F_80 ( 500 ) ;
} else if ( V_522 == V_532 ) {
V_527 = V_533 ;
V_528 = F_80 ( 0 ) ;
} else {
return - V_78 ;
}
F_79 ( V_4 , & V_333 , V_534 , - 1 , - 1 ) ;
V_333 . V_494 = F_80 ( V_495 -> V_494 ) ;
V_333 . V_529 = V_4 -> V_529 ;
V_526 = (struct V_525 * ) & V_333 . V_535 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_529 ; V_44 ++ , V_526 ++ ) {
V_333 . V_455 |= F_120 ( V_44 ) ;
V_526 -> V_536 = V_4 -> V_537 [ V_44 ] . V_536 ;
V_526 -> V_527 = V_527 ;
V_526 -> V_538 = V_528 ;
V_526 -> V_539 = V_528 ;
V_526 -> V_540 = V_4 -> V_537 [ V_44 ] . V_540 ;
}
V_28 = F_84 ( V_4 , & V_333 , sizeof( V_333 ) , V_359 ) ;
if ( V_28 )
V_28 = - V_541 ;
return V_28 ;
}
