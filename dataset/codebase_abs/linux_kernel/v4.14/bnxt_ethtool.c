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
if ( V_29 )
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
static int F_12 ( struct V_3 * V_4 )
{
int V_32 = V_33 * V_4 -> V_34 ;
if ( V_4 -> V_35 & V_36 )
V_32 += V_37 ;
return V_32 ;
}
static int F_13 ( struct V_1 * V_2 , int V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_38 ) {
case V_39 :
return F_12 ( V_4 ) ;
case V_40 :
if ( ! V_4 -> V_41 )
return - V_42 ;
return V_4 -> V_41 ;
default:
return - V_42 ;
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_43 * V_44 , T_2 * V_45 )
{
T_1 V_46 , V_47 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_48 = sizeof( struct V_49 ) / 8 ;
if ( ! V_4 -> V_50 )
return;
for ( V_46 = 0 ; V_46 < V_4 -> V_34 ; V_46 ++ ) {
struct V_51 * V_50 = V_4 -> V_50 [ V_46 ] ;
struct V_52 * V_53 = & V_50 -> V_54 ;
T_3 * V_55 = ( T_3 * ) V_53 -> V_55 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_48 ; V_47 ++ , V_56 ++ )
V_45 [ V_47 ] = F_15 ( V_55 [ V_56 ] ) ;
V_45 [ V_47 ++ ] = V_53 -> V_57 ;
}
if ( V_4 -> V_35 & V_36 ) {
T_3 * V_58 = ( T_3 * ) V_4 -> V_59 ;
for ( V_46 = 0 ; V_46 < V_37 ; V_46 ++ , V_47 ++ ) {
V_45 [ V_47 ] = F_15 ( * ( V_58 +
V_60 [ V_46 ] . V_61 ) ) ;
}
}
}
static void F_16 ( struct V_1 * V_2 , T_1 V_62 , T_4 * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_46 ;
switch ( V_62 ) {
case V_39 :
for ( V_46 = 0 ; V_46 < V_4 -> V_34 ; V_46 ++ ) {
sprintf ( V_45 , L_1 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_2 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_3 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_4 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_5 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_6 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_7 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_8 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_9 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_10 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_11 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_12 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_13 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_14 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_15 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_16 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_17 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_18 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_19 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_20 , V_46 ) ;
V_45 += V_63 ;
sprintf ( V_45 , L_21 , V_46 ) ;
V_45 += V_63 ;
}
if ( V_4 -> V_35 & V_36 ) {
for ( V_46 = 0 ; V_46 < V_37 ; V_46 ++ ) {
strcpy ( V_45 , V_60 [ V_46 ] . string ) ;
V_45 += V_63 ;
}
}
break;
case V_40 :
if ( V_4 -> V_41 )
memcpy ( V_45 , V_4 -> V_64 -> string ,
V_4 -> V_41 * V_63 ) ;
break;
default:
F_17 ( V_4 -> V_2 , L_22 ,
V_62 ) ;
break;
}
}
static void F_18 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_66 -> V_67 = V_68 ;
V_66 -> V_69 = V_70 ;
V_66 -> V_71 = V_72 ;
V_66 -> V_73 = V_4 -> V_74 ;
V_66 -> V_75 = V_4 -> V_76 ;
V_66 -> V_77 = V_4 -> V_78 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_66 -> V_73 > V_68 ) ||
( V_66 -> V_77 > V_72 ) ||
( V_66 -> V_77 <= V_79 ) )
return - V_80 ;
if ( F_8 ( V_2 ) )
F_9 ( V_4 , false , false ) ;
V_4 -> V_74 = V_66 -> V_73 ;
V_4 -> V_78 = V_66 -> V_77 ;
F_20 ( V_4 ) ;
if ( F_8 ( V_2 ) )
return F_10 ( V_4 , false , false ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_83 , V_84 , V_85 ;
F_22 ( V_4 , & V_83 , & V_84 , true ) ;
V_82 -> V_86 = F_23 ( int , V_83 , V_84 ) ;
if ( F_22 ( V_4 , & V_83 , & V_84 , false ) ) {
V_83 = 0 ;
V_84 = 0 ;
}
V_85 = F_24 ( V_2 ) ;
if ( V_85 > 1 )
V_84 /= V_85 ;
V_82 -> V_87 = V_83 ;
V_82 -> V_88 = V_84 ;
V_82 -> V_89 = 0 ;
if ( V_4 -> V_35 & V_90 ) {
V_82 -> V_91 = V_4 -> V_92 ;
if ( F_25 ( V_4 ) )
V_82 -> V_91 -- ;
} else {
if ( ! F_25 ( V_4 ) ) {
V_82 -> V_93 = V_4 -> V_92 ;
V_82 -> V_94 = V_4 -> V_95 ;
}
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_96 , V_97 , V_85 ;
bool V_98 = false ;
int V_99 = 0 ;
int V_28 = 0 ;
if ( V_82 -> V_100 )
return - V_80 ;
if ( ! V_82 -> V_91 &&
( ! V_82 -> V_93 || ! V_82 -> V_94 ) )
return - V_80 ;
if ( V_82 -> V_91 &&
( V_82 -> V_93 || V_82 -> V_94 ) )
return - V_80 ;
if ( F_25 ( V_4 ) && ( V_82 -> V_93 ||
V_82 -> V_94 ) )
return - V_80 ;
if ( V_82 -> V_91 )
V_98 = true ;
V_85 = F_24 ( V_2 ) ;
V_96 = V_98 ? V_82 -> V_91 : V_82 -> V_94 ;
V_97 = V_98 ? V_82 -> V_91 : V_82 -> V_93 ;
if ( V_4 -> V_101 ) {
if ( ! V_98 ) {
F_17 ( V_2 , L_23 ) ;
return - V_80 ;
}
V_99 = V_97 ;
}
V_28 = F_27 ( V_4 , V_96 , V_97 , V_98 , V_85 , V_99 ) ;
if ( V_28 ) {
F_28 ( V_2 , L_24 ) ;
return V_28 ;
}
if ( F_8 ( V_2 ) ) {
if ( F_29 ( V_4 ) ) {
}
V_28 = F_9 ( V_4 , true , false ) ;
if ( V_28 ) {
F_17 ( V_4 -> V_2 , L_25 ,
V_28 ) ;
return V_28 ;
}
}
if ( V_98 ) {
V_4 -> V_35 |= V_90 ;
V_4 -> V_92 = V_82 -> V_91 ;
V_4 -> V_95 = V_82 -> V_91 ;
} else {
V_4 -> V_35 &= ~ V_90 ;
V_4 -> V_92 = V_82 -> V_93 ;
V_4 -> V_95 = V_82 -> V_94 ;
}
V_4 -> V_101 = V_99 ;
V_4 -> V_102 = V_4 -> V_95 + V_99 ;
if ( V_85 > 1 )
V_4 -> V_102 = V_4 -> V_95 * V_85 + V_99 ;
V_4 -> V_34 = V_98 ? F_30 ( int , V_4 -> V_102 , V_4 -> V_92 ) :
V_4 -> V_102 + V_4 -> V_92 ;
V_4 -> V_103 = V_4 -> V_34 ;
F_31 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
V_28 = F_10 ( V_4 , true , false ) ;
if ( ( ! V_28 ) && F_29 ( V_4 ) ) {
}
}
return V_28 ;
}
static int F_32 ( struct V_3 * V_4 , struct V_104 * V_105 ,
T_1 * V_106 )
{
int V_46 , V_47 = 0 ;
V_105 -> V_107 = V_4 -> V_108 ;
for ( V_46 = 0 ; V_46 < V_109 ; V_46 ++ ) {
struct V_110 * V_111 ;
struct V_112 * V_113 ;
V_111 = & V_4 -> V_114 [ V_46 ] ;
F_33 () ;
F_34 (fltr, head, hash) {
if ( V_47 == V_105 -> V_115 )
break;
V_106 [ V_47 ++ ] = V_113 -> V_116 ;
}
F_35 () ;
if ( V_47 == V_105 -> V_115 )
break;
}
V_105 -> V_115 = V_47 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 , struct V_104 * V_105 )
{
struct V_117 * V_118 =
(struct V_117 * ) & V_105 -> V_118 ;
struct V_112 * V_113 ;
struct V_119 * V_120 ;
int V_46 , V_28 = - V_80 ;
if ( V_118 -> V_121 >= V_122 )
return V_28 ;
for ( V_46 = 0 ; V_46 < V_109 ; V_46 ++ ) {
struct V_110 * V_111 ;
V_111 = & V_4 -> V_114 [ V_46 ] ;
F_33 () ;
F_34 (fltr, head, hash) {
if ( V_113 -> V_116 == V_118 -> V_121 )
goto V_123;
}
F_35 () ;
}
return V_28 ;
V_123:
V_120 = & V_113 -> V_120 ;
if ( V_120 -> V_124 . V_125 == F_37 ( V_126 ) ) {
if ( V_120 -> V_124 . V_127 == V_128 )
V_118 -> V_129 = V_130 ;
else if ( V_120 -> V_124 . V_127 == V_131 )
V_118 -> V_129 = V_132 ;
else
goto V_133;
V_118 -> V_134 . V_135 . V_136 = V_120 -> V_137 . V_138 . V_139 ;
V_118 -> V_140 . V_135 . V_136 = F_38 ( ~ 0 ) ;
V_118 -> V_134 . V_135 . V_141 = V_120 -> V_137 . V_138 . V_142 ;
V_118 -> V_140 . V_135 . V_141 = F_38 ( ~ 0 ) ;
V_118 -> V_134 . V_135 . V_143 = V_120 -> V_144 . V_139 ;
V_118 -> V_140 . V_135 . V_143 = F_39 ( ~ 0 ) ;
V_118 -> V_134 . V_135 . V_145 = V_120 -> V_144 . V_142 ;
V_118 -> V_140 . V_135 . V_145 = F_39 ( ~ 0 ) ;
} else {
int V_46 ;
if ( V_120 -> V_124 . V_127 == V_128 )
V_118 -> V_129 = V_146 ;
else if ( V_120 -> V_124 . V_127 == V_131 )
V_118 -> V_129 = V_147 ;
else
goto V_133;
* (struct V_148 * ) & V_118 -> V_134 . V_149 . V_150 [ 0 ] =
V_120 -> V_137 . V_151 . V_139 ;
* (struct V_148 * ) & V_118 -> V_134 . V_149 . V_152 [ 0 ] =
V_120 -> V_137 . V_151 . V_142 ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_118 -> V_140 . V_149 . V_150 [ V_46 ] = F_38 ( ~ 0 ) ;
V_118 -> V_140 . V_149 . V_152 [ V_46 ] = F_38 ( ~ 0 ) ;
}
V_118 -> V_134 . V_149 . V_143 = V_120 -> V_144 . V_139 ;
V_118 -> V_140 . V_149 . V_143 = F_39 ( ~ 0 ) ;
V_118 -> V_134 . V_149 . V_145 = V_120 -> V_144 . V_142 ;
V_118 -> V_140 . V_149 . V_145 = F_39 ( ~ 0 ) ;
}
V_118 -> V_153 = V_113 -> V_154 ;
V_28 = 0 ;
V_133:
F_35 () ;
return V_28 ;
}
static T_2 F_40 ( struct V_3 * V_4 )
{
if ( V_4 -> V_155 & V_156 )
return V_157 | V_158 ;
return 0 ;
}
static T_2 F_41 ( struct V_3 * V_4 )
{
if ( V_4 -> V_155 & V_159 )
return V_157 | V_158 ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , struct V_104 * V_105 )
{
V_105 -> V_107 = 0 ;
switch ( V_105 -> V_129 ) {
case V_130 :
if ( V_4 -> V_155 & V_160 )
V_105 -> V_107 |= V_157 | V_158 |
V_161 | V_162 ;
V_105 -> V_107 |= F_40 ( V_4 ) ;
break;
case V_132 :
if ( V_4 -> V_155 & V_163 )
V_105 -> V_107 |= V_157 | V_158 |
V_161 | V_162 ;
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
V_105 -> V_107 |= F_40 ( V_4 ) ;
break;
case V_146 :
if ( V_4 -> V_155 & V_169 )
V_105 -> V_107 |= V_157 | V_158 |
V_161 | V_162 ;
V_105 -> V_107 |= F_41 ( V_4 ) ;
break;
case V_147 :
if ( V_4 -> V_155 & V_170 )
V_105 -> V_107 |= V_157 | V_158 |
V_161 | V_162 ;
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_105 -> V_107 |= F_41 ( V_4 ) ;
break;
}
return 0 ;
}
static int F_43 ( struct V_3 * V_4 , struct V_104 * V_105 )
{
T_1 V_155 = V_4 -> V_155 ;
int V_176 , V_28 = 0 ;
if ( V_105 -> V_107 == V_177 )
V_176 = 4 ;
else if ( V_105 -> V_107 == V_178 )
V_176 = 2 ;
else if ( ! V_105 -> V_107 )
V_176 = 0 ;
else
return - V_80 ;
if ( V_105 -> V_129 == V_130 ) {
V_155 &= ~ V_160 ;
if ( V_176 == 4 )
V_155 |= V_160 ;
} else if ( V_105 -> V_129 == V_132 ) {
if ( V_176 == 4 && ! ( V_4 -> V_35 & V_179 ) )
return - V_80 ;
V_155 &= ~ V_163 ;
if ( V_176 == 4 )
V_155 |= V_163 ;
} else if ( V_105 -> V_129 == V_146 ) {
V_155 &= ~ V_169 ;
if ( V_176 == 4 )
V_155 |= V_169 ;
} else if ( V_105 -> V_129 == V_147 ) {
if ( V_176 == 4 && ! ( V_4 -> V_35 & V_179 ) )
return - V_80 ;
V_155 &= ~ V_170 ;
if ( V_176 == 4 )
V_155 |= V_170 ;
} else if ( V_176 == 4 ) {
return - V_80 ;
}
switch ( V_105 -> V_129 ) {
case V_130 :
case V_132 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
if ( V_176 == 2 )
V_155 |= V_156 ;
else if ( ! V_176 )
V_155 &= ~ V_156 ;
break;
case V_146 :
case V_147 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
if ( V_176 == 2 )
V_155 |= V_159 ;
else if ( ! V_176 )
V_155 &= ~ V_159 ;
break;
}
if ( V_4 -> V_155 == V_155 )
return 0 ;
V_4 -> V_155 = V_155 ;
if ( F_8 ( V_4 -> V_2 ) ) {
F_9 ( V_4 , false , false ) ;
V_28 = F_10 ( V_4 , false , false ) ;
}
return V_28 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_104 * V_105 ,
T_1 * V_106 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 = 0 ;
switch ( V_105 -> V_105 ) {
#ifdef F_45
case V_180 :
V_105 -> V_107 = V_4 -> V_92 ;
break;
case V_181 :
V_105 -> V_115 = V_4 -> V_108 ;
V_105 -> V_107 = V_122 ;
break;
case V_182 :
V_28 = F_32 ( V_4 , V_105 , ( T_1 * ) V_106 ) ;
break;
case V_183 :
V_28 = F_36 ( V_4 , V_105 ) ;
break;
#endif
case V_184 :
V_28 = F_42 ( V_4 , V_105 ) ;
break;
default:
V_28 = - V_42 ;
break;
}
return V_28 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
switch ( V_105 -> V_105 ) {
case V_185 :
V_28 = F_43 ( V_4 , V_105 ) ;
break;
default:
V_28 = - V_42 ;
break;
}
return V_28 ;
}
static T_1 F_47 ( struct V_1 * V_2 )
{
return V_186 ;
}
static T_1 F_48 ( struct V_1 * V_2 )
{
return V_187 ;
}
static int F_49 ( struct V_1 * V_2 , T_1 * V_188 , T_4 * V_189 ,
T_4 * V_190 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_191 * V_192 = & V_4 -> V_193 [ 0 ] ;
int V_46 = 0 ;
if ( V_190 )
* V_190 = V_194 ;
if ( V_188 )
for ( V_46 = 0 ; V_46 < V_186 ; V_46 ++ )
V_188 [ V_46 ] = F_50 ( V_192 -> V_195 [ V_46 ] ) ;
if ( V_189 )
memcpy ( V_189 , V_192 -> V_196 , V_187 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_197 * V_198 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char * V_199 ;
char * V_200 = NULL ;
V_199 = F_52 ( V_201 , V_202 ) ;
if ( V_199 )
V_200 = F_53 ( V_2 , V_199 , V_201 ) ;
F_54 ( V_198 -> V_203 , V_204 , sizeof( V_198 -> V_203 ) ) ;
F_54 ( V_198 -> V_205 , V_206 , sizeof( V_198 -> V_205 ) ) ;
if ( V_200 && * V_200 != 0 && isdigit ( * V_200 ) )
snprintf ( V_198 -> V_207 , sizeof( V_198 -> V_207 ) - 1 ,
L_26 , V_4 -> V_208 , V_200 ) ;
else
F_54 ( V_198 -> V_207 , V_4 -> V_208 ,
sizeof( V_198 -> V_207 ) ) ;
F_54 ( V_198 -> V_209 , F_55 ( V_4 -> V_210 ) , sizeof( V_198 -> V_209 ) ) ;
V_198 -> V_211 = F_12 ( V_4 ) ;
V_198 -> V_212 = V_4 -> V_41 ;
V_198 -> V_213 = 0 ;
V_198 -> V_214 = 0 ;
F_56 ( V_199 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_215 * V_216 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_216 -> V_217 = 0 ;
V_216 -> V_218 = 0 ;
memset ( & V_216 -> V_219 , 0 , sizeof( V_216 -> V_219 ) ) ;
if ( V_4 -> V_35 & V_220 ) {
V_216 -> V_217 = V_221 ;
if ( V_4 -> V_216 )
V_216 -> V_218 = V_221 ;
}
}
static int F_58 ( struct V_1 * V_2 , struct V_215 * V_216 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_216 -> V_218 & ~ V_221 )
return - V_80 ;
if ( V_216 -> V_218 & V_221 ) {
if ( ! ( V_4 -> V_35 & V_220 ) )
return - V_80 ;
if ( ! V_4 -> V_216 ) {
if ( F_59 ( V_4 ) )
return - V_222 ;
V_4 -> V_216 = 1 ;
}
} else {
if ( V_4 -> V_216 ) {
if ( F_60 ( V_4 ) )
return - V_222 ;
V_4 -> V_216 = 0 ;
}
}
return 0 ;
}
T_1 F_61 ( T_5 V_223 , T_4 V_224 )
{
T_1 V_225 = 0 ;
if ( V_223 & V_226 )
V_225 |= V_227 ;
if ( V_223 & V_228 )
V_225 |= V_229 ;
if ( V_223 & V_230 )
V_225 |= V_231 ;
if ( V_223 & V_232 )
V_225 |= V_233 ;
if ( V_223 & V_234 )
V_225 |= V_235 ;
if ( ( V_224 & V_236 ) == V_236 )
V_225 |= V_237 ;
else if ( V_224 & V_238 )
V_225 |= V_239 ;
else if ( V_224 & V_240 )
V_225 |= V_237 | V_239 ;
return V_225 ;
}
static void F_62 ( struct V_241 * V_242 ,
struct V_243 * V_244 )
{
T_5 V_223 = V_242 -> V_245 ;
T_4 V_224 = 0 ;
if ( V_242 -> V_246 & V_247 )
V_224 = V_242 -> V_248 ;
F_63 ( V_223 , V_224 , V_244 , V_245 ) ;
}
static void F_64 ( struct V_241 * V_242 ,
struct V_243 * V_244 )
{
T_5 V_223 = V_242 -> V_249 ;
T_4 V_224 = 0 ;
if ( V_242 -> V_246 & V_247 )
V_224 = V_242 -> V_250 ;
F_63 ( V_223 , V_224 , V_244 ,
V_251 ) ;
}
static void F_65 ( struct V_241 * V_242 ,
struct V_243 * V_244 )
{
T_5 V_223 = V_242 -> V_252 ;
F_63 ( V_223 , 0 , V_244 , V_217 ) ;
F_66 ( V_244 , V_217 , V_253 ) ;
F_66 ( V_244 , V_217 ,
V_254 ) ;
if ( V_242 -> V_255 )
F_66 ( V_244 , V_217 ,
V_256 ) ;
}
T_1 F_67 ( T_5 V_257 )
{
switch ( V_257 ) {
case V_258 :
return V_259 ;
case V_260 :
return V_261 ;
case V_262 :
return V_263 ;
case V_264 :
return V_265 ;
case V_266 :
return V_267 ;
case V_268 :
return V_269 ;
case V_270 :
return V_271 ;
case V_272 :
return V_273 ;
case V_274 :
return V_275 ;
default:
return V_276 ;
}
}
static int F_68 ( struct V_1 * V_2 ,
struct V_243 * V_244 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_241 * V_242 = & V_4 -> V_242 ;
struct V_277 * V_278 = & V_244 -> V_278 ;
T_1 V_279 ;
F_69 ( V_244 , V_217 ) ;
F_70 ( & V_4 -> V_280 ) ;
F_65 ( V_242 , V_244 ) ;
F_69 ( V_244 , V_245 ) ;
if ( V_242 -> V_246 ) {
F_62 ( V_242 , V_244 ) ;
F_66 ( V_244 ,
V_245 , V_256 ) ;
V_278 -> V_246 = V_281 ;
if ( V_242 -> V_282 == V_283 )
F_64 ( V_242 , V_244 ) ;
V_279 = F_67 ( V_242 -> V_284 ) ;
if ( ! F_71 ( V_2 ) )
V_278 -> V_285 = V_286 ;
else if ( V_242 -> V_285 & V_287 )
V_278 -> V_285 = V_288 ;
else
V_278 -> V_285 = V_289 ;
} else {
V_278 -> V_246 = V_290 ;
V_279 =
F_67 ( V_242 -> V_291 ) ;
V_278 -> V_285 = V_289 ;
if ( V_242 -> V_292 == V_287 )
V_278 -> V_285 = V_288 ;
}
V_278 -> V_293 = V_279 ;
V_278 -> V_294 = V_295 ;
if ( V_242 -> V_296 == V_297 ) {
V_278 -> V_294 = V_298 ;
F_66 ( V_244 , V_217 ,
V_299 ) ;
F_66 ( V_244 , V_245 ,
V_299 ) ;
} else {
F_66 ( V_244 , V_217 ,
V_300 ) ;
F_66 ( V_244 , V_245 ,
V_300 ) ;
if ( V_242 -> V_296 == V_301 )
V_278 -> V_294 = V_302 ;
else if ( V_242 -> V_296 ==
V_303 )
V_278 -> V_294 = V_304 ;
}
V_278 -> V_305 = V_242 -> V_306 ;
F_72 ( & V_4 -> V_280 ) ;
return 0 ;
}
static T_1 F_73 ( struct V_1 * V_2 , T_1 V_279 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_241 * V_242 = & V_4 -> V_242 ;
T_5 V_307 = V_242 -> V_252 ;
T_1 V_308 = 0 ;
switch ( V_279 ) {
case V_259 :
if ( V_307 & V_226 )
V_308 = V_309 ;
break;
case V_261 :
if ( V_307 & V_228 )
V_308 = V_310 ;
break;
case V_263 :
if ( V_307 & V_230 )
V_308 = V_311 ;
break;
case V_265 :
if ( V_307 & V_232 )
V_308 = V_312 ;
break;
case V_267 :
if ( V_307 & V_313 )
V_308 = V_314 ;
break;
case V_269 :
if ( V_307 & V_315 )
V_308 = V_316 ;
break;
case V_271 :
if ( V_307 & V_234 )
V_308 = V_317 ;
break;
case V_273 :
if ( V_307 & V_318 )
V_308 = V_319 ;
break;
case V_275 :
if ( V_307 & V_320 )
V_308 = V_321 ;
break;
default:
F_17 ( V_2 , L_27 ) ;
break;
}
return V_308 ;
}
T_5 F_74 ( T_1 V_245 )
{
T_5 V_322 = 0 ;
if ( V_245 & ( V_227 |
V_323 ) ) {
V_322 |= V_226 ;
}
if ( V_245 & ( V_229 |
V_324 ) ) {
V_322 |= V_228 ;
}
if ( V_245 & V_233 )
V_322 |= V_232 ;
if ( V_245 & V_235 )
V_322 |= V_234 ;
return V_322 ;
}
static int F_75 ( struct V_1 * V_2 ,
const struct V_243 * V_244 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_241 * V_242 = & V_4 -> V_242 ;
const struct V_277 * V_278 = & V_244 -> V_278 ;
bool V_325 = false ;
T_5 V_326 = 0 ;
T_1 V_293 ;
int V_28 = 0 ;
if ( ! F_76 ( V_4 ) )
return - V_42 ;
F_70 ( & V_4 -> V_280 ) ;
if ( V_278 -> V_246 == V_281 ) {
F_77 ( V_326 , V_244 ,
V_245 ) ;
V_242 -> V_246 |= V_327 ;
if ( ! V_326 )
V_242 -> V_245 = V_242 -> V_255 ;
else
V_242 -> V_245 = V_326 ;
V_325 = true ;
} else {
T_5 V_308 ;
T_4 V_328 = V_242 -> V_328 ;
if ( V_328 == V_329 ||
V_328 == V_330 ||
V_242 -> V_296 == V_297 ) {
F_17 ( V_2 , L_28 ) ;
V_28 = - V_80 ;
goto V_331;
}
if ( V_278 -> V_285 == V_289 ) {
F_17 ( V_2 , L_29 ) ;
V_28 = - V_80 ;
goto V_331;
}
V_293 = V_278 -> V_293 ;
V_308 = F_73 ( V_2 , V_293 ) ;
if ( ! V_308 ) {
V_28 = - V_80 ;
goto V_331;
}
V_242 -> V_291 = V_308 ;
V_242 -> V_292 = V_287 ;
V_242 -> V_246 = 0 ;
V_242 -> V_245 = 0 ;
}
if ( F_8 ( V_2 ) )
V_28 = F_78 ( V_4 , V_325 , false ) ;
V_331:
F_72 ( & V_4 -> V_280 ) ;
return V_28 ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_332 * V_333 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_241 * V_242 = & V_4 -> V_242 ;
if ( F_80 ( V_4 ) )
return;
V_333 -> V_246 = ! ! ( V_242 -> V_246 & V_247 ) ;
V_333 -> V_334 = ! ! ( V_242 -> V_335 & V_240 ) ;
V_333 -> V_336 = ! ! ( V_242 -> V_335 & V_238 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_332 * V_333 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_241 * V_242 = & V_4 -> V_242 ;
if ( ! F_76 ( V_4 ) )
return - V_42 ;
if ( V_333 -> V_246 ) {
if ( ! ( V_242 -> V_246 & V_327 ) )
return - V_80 ;
V_242 -> V_246 |= V_247 ;
if ( V_4 -> V_337 >= 0x10201 )
V_242 -> V_335 =
V_338 ;
} else {
if ( V_242 -> V_246 & V_247 )
V_242 -> V_339 = true ;
V_242 -> V_246 &= ~ V_247 ;
V_242 -> V_335 = 0 ;
}
if ( V_333 -> V_334 )
V_242 -> V_335 |= V_240 ;
if ( V_333 -> V_336 )
V_242 -> V_335 |= V_238 ;
if ( F_8 ( V_2 ) )
V_28 = F_82 ( V_4 ) ;
return V_28 ;
}
static T_1 F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_242 . V_340 ;
}
static int F_84 ( struct V_1 * V_2 ,
T_5 V_341 ,
T_5 V_342 ,
T_5 V_343 ,
T_5 V_344 ,
const T_4 * V_107 ,
T_6 V_345 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_346 V_347 = { 0 } ;
T_7 V_348 ;
T_4 * V_349 ;
F_85 ( V_4 , & V_347 , V_350 , - 1 , - 1 ) ;
V_347 . V_341 = F_86 ( V_341 ) ;
V_347 . V_342 = F_86 ( V_342 ) ;
V_347 . V_343 = F_86 ( V_343 ) ;
V_347 . V_344 = F_86 ( V_344 ) ;
V_347 . V_351 = F_87 ( V_345 ) ;
V_349 = F_88 ( & V_4 -> V_210 -> V_2 , V_345 , & V_348 ,
V_202 ) ;
if ( ! V_349 ) {
F_17 ( V_2 , L_30 ,
( unsigned ) V_345 ) ;
return - V_352 ;
}
memcpy ( V_349 , V_107 , V_345 ) ;
V_347 . V_353 = F_89 ( V_348 ) ;
V_28 = F_90 ( V_4 , & V_347 , sizeof( V_347 ) , V_354 ) ;
F_91 ( & V_4 -> V_210 -> V_2 , V_345 , V_349 , V_348 ) ;
return V_28 ;
}
static int F_92 ( struct V_1 * V_2 ,
T_5 V_341 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_355 V_347 = { 0 } ;
F_85 ( V_4 , & V_347 , V_356 , - 1 , - 1 ) ;
switch ( V_341 ) {
case V_357 :
case V_358 :
case V_359 :
V_347 . V_360 = V_361 ;
V_347 . V_362 = V_363 ;
break;
case V_364 :
case V_365 :
V_347 . V_360 = V_366 ;
V_347 . V_362 = V_363 ;
break;
case V_367 :
case V_368 :
V_347 . V_360 =
V_369 ;
break;
case V_370 :
case V_371 :
V_347 . V_360 = V_372 ;
break;
default:
return - V_80 ;
}
return F_90 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
T_5 V_341 ,
const T_4 * V_374 ,
T_6 V_375 )
{
int V_28 = 0 ;
T_5 V_376 ;
T_1 V_377 ;
T_1 V_378 ;
struct V_379 * V_380 = (struct V_379 * ) V_374 ;
switch ( V_341 ) {
case V_358 :
case V_359 :
V_376 = V_381 ;
break;
case V_357 :
V_376 = V_382 ;
break;
case V_364 :
V_376 = V_383 ;
break;
case V_365 :
V_376 = V_384 ;
break;
case V_367 :
V_376 = V_385 ;
break;
case V_368 :
V_376 = V_386 ;
break;
case V_370 :
V_376 = V_387 ;
break;
case V_371 :
V_376 = V_388 ;
break;
default:
F_17 ( V_2 , L_31 ,
V_341 ) ;
return - V_80 ;
}
if ( V_375 < sizeof( struct V_379 ) ) {
F_17 ( V_2 , L_32 ,
( unsigned int ) V_375 ) ;
return - V_80 ;
}
if ( V_380 -> V_389 != F_87 ( V_390 ) ) {
F_17 ( V_2 , L_33 ,
F_94 ( V_380 -> V_389 ) ) ;
return - V_80 ;
}
if ( V_380 -> V_376 != V_376 ) {
F_17 ( V_2 , L_34 ,
V_376 , V_380 -> V_376 ) ;
return - V_80 ;
}
if ( V_380 -> V_391 != V_392 ) {
F_17 ( V_2 , L_35 ,
V_392 , V_380 -> V_391 ) ;
return - V_80 ;
}
V_377 = F_94 ( * ( V_393 * ) ( V_374 + V_375 -
sizeof( V_377 ) ) ) ;
V_378 = ~ F_95 ( ~ 0 , V_374 , V_375 - sizeof( V_377 ) ) ;
if ( V_378 != V_377 ) {
F_17 ( V_2 , L_36 ,
( unsigned long ) V_377 ,
( unsigned long ) V_378 ) ;
return - V_80 ;
}
V_28 = F_84 ( V_2 , V_341 , V_394 ,
0 , 0 , V_374 , V_375 ) ;
if ( V_28 == 0 )
V_28 = F_92 ( V_2 , V_341 ) ;
return V_28 ;
}
static int F_96 ( struct V_1 * V_2 ,
T_5 V_341 ,
const T_4 * V_374 ,
T_6 V_375 )
{
struct V_395 * V_396 ;
T_1 V_378 ;
T_1 V_377 ;
int V_28 = 0 ;
if ( V_375 < sizeof( struct V_395 ) ) {
F_17 ( V_2 , L_37 ,
( unsigned int ) V_375 ) ;
return - V_80 ;
}
V_396 = (struct V_395 * ) ( V_374 + ( V_375 -
sizeof( * V_396 ) ) ) ;
if ( V_396 -> V_397 != F_87 ( V_398 ) ) {
F_17 ( V_2 , L_38 ,
F_94 ( V_396 -> V_397 ) ) ;
return - V_80 ;
}
if ( F_50 ( V_396 -> V_341 ) != V_341 ) {
F_17 ( V_2 , L_39 ,
V_341 , F_50 ( V_396 -> V_341 ) ) ;
return - V_80 ;
}
if ( F_50 ( V_396 -> V_399 ) <
sizeof( struct V_395 ) ) {
F_17 ( V_2 , L_40 ,
F_50 ( V_396 -> V_399 ) ) ;
return - V_80 ;
}
V_377 = F_94 ( * ( V_393 * ) ( V_374 + V_375 -
sizeof( V_377 ) ) ) ;
V_378 = ~ F_95 ( ~ 0 , V_374 , V_375 - sizeof( V_377 ) ) ;
if ( V_378 != V_377 ) {
F_17 ( V_2 ,
L_41 ,
( unsigned long ) V_377 ,
( unsigned long ) V_378 ) ;
return - V_80 ;
}
V_28 = F_84 ( V_2 , V_341 , V_394 ,
0 , 0 , V_374 , V_375 ) ;
return V_28 ;
}
static bool F_97 ( T_5 V_341 )
{
switch ( V_341 ) {
case V_357 :
case V_358 :
case V_359 :
case V_364 :
case V_365 :
case V_367 :
case V_368 :
case V_370 :
case V_371 :
return true ;
}
return false ;
}
static bool F_98 ( T_5 V_341 )
{
switch ( V_341 ) {
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
return true ;
}
return false ;
}
static bool F_99 ( T_5 V_341 )
{
return F_97 ( V_341 ) ||
F_98 ( V_341 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
T_5 V_341 ,
const char * V_409 )
{
const struct V_410 * V_411 ;
int V_28 ;
V_28 = F_101 ( & V_411 , V_409 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_17 ( V_2 , L_42 ,
V_28 , V_409 ) ;
return V_28 ;
}
if ( F_97 ( V_341 ) == true )
V_28 = F_93 ( V_2 , V_341 , V_411 -> V_107 , V_411 -> V_412 ) ;
else if ( F_98 ( V_341 ) == true )
V_28 = F_96 ( V_2 , V_341 , V_411 -> V_107 , V_411 -> V_412 ) ;
else
V_28 = F_84 ( V_2 , V_341 , V_394 ,
0 , 0 , V_411 -> V_107 , V_411 -> V_412 ) ;
F_102 ( V_411 ) ;
return V_28 ;
}
static int F_103 ( struct V_1 * V_2 ,
char * V_409 , T_1 V_413 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_414 * V_415 = V_4 -> V_416 ;
struct V_417 V_418 = { 0 } ;
const struct V_410 * V_411 ;
T_1 V_419 ;
T_5 V_420 ;
int V_28 ;
F_104 ( V_4 ) ;
if ( F_105 ( V_2 , V_421 ,
V_394 , V_422 ,
& V_420 , & V_419 , NULL ) != 0 ) {
F_17 ( V_2 , L_43 ) ;
return - V_423 ;
}
V_28 = F_101 ( & V_411 , V_409 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_17 ( V_2 , L_44 ,
V_28 , V_409 ) ;
return V_28 ;
}
if ( V_411 -> V_412 > V_419 ) {
F_17 ( V_2 , L_45 ,
( unsigned long ) V_411 -> V_412 ) ;
V_28 = - V_424 ;
} else {
T_7 V_348 ;
T_4 * V_349 ;
struct V_425 V_426 = { 0 } ;
F_85 ( V_4 , & V_426 , V_427 , - 1 , - 1 ) ;
V_426 . V_428 = F_86 ( V_420 ) ;
V_426 . V_429 = F_87 ( V_411 -> V_412 ) ;
V_349 = F_88 ( & V_4 -> V_210 -> V_2 , V_411 -> V_412 ,
& V_348 , V_202 ) ;
if ( ! V_349 ) {
F_17 ( V_2 ,
L_30 ,
( unsigned int ) V_411 -> V_412 ) ;
V_28 = - V_352 ;
} else {
memcpy ( V_349 , V_411 -> V_107 , V_411 -> V_412 ) ;
V_426 . V_353 = F_89 ( V_348 ) ;
V_28 = F_90 ( V_4 , & V_426 , sizeof( V_426 ) ,
V_430 ) ;
F_91 ( & V_4 -> V_210 -> V_2 , V_411 -> V_412 , V_349 ,
V_348 ) ;
}
}
F_102 ( V_411 ) ;
if ( V_28 )
return V_28 ;
if ( ( V_413 & 0xffff ) == 0 )
V_413 >>= 16 ;
F_85 ( V_4 , & V_418 , V_431 , - 1 , - 1 ) ;
V_418 . V_413 = F_87 ( V_413 ) ;
F_70 ( & V_4 -> V_432 ) ;
V_28 = F_106 ( V_4 , & V_418 , sizeof( V_418 ) ,
V_433 ) ;
if ( V_28 ) {
V_28 = - V_42 ;
goto V_434;
}
if ( V_415 -> V_435 ) {
T_4 V_435 = ( (struct V_436 * ) V_415 ) -> V_437 ;
if ( V_435 == V_438 ) {
V_418 . V_35 |= F_86 (
V_439 ) ;
V_28 = F_106 ( V_4 , & V_418 , sizeof( V_418 ) ,
V_433 ) ;
if ( V_28 ) {
V_28 = - V_42 ;
goto V_434;
}
}
}
if ( V_415 -> V_440 ) {
F_17 ( V_2 , L_46 ,
( V_441 ) V_415 -> V_440 , ( int ) V_415 -> V_442 ) ;
V_28 = - V_443 ;
}
V_434:
F_72 ( & V_4 -> V_432 ) ;
return V_28 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_444 * V_445 )
{
if ( ! F_29 ( (struct V_3 * ) F_2 ( V_2 ) ) ) {
F_17 ( V_2 , L_47 ) ;
return - V_80 ;
}
if ( V_445 -> V_446 == V_447 ||
V_445 -> V_446 > 0xffff )
return F_103 ( V_2 , V_445 -> V_107 ,
V_445 -> V_446 ) ;
return F_100 ( V_2 , V_445 -> V_446 , V_445 -> V_107 ) ;
}
static int F_108 ( struct V_1 * V_2 , T_1 * V_448 , T_1 * V_449 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_450 V_347 = { 0 } ;
struct V_451 * V_452 = V_4 -> V_416 ;
F_85 ( V_4 , & V_347 , V_453 , - 1 , - 1 ) ;
F_70 ( & V_4 -> V_432 ) ;
V_28 = F_106 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( ! V_28 ) {
* V_448 = F_94 ( V_452 -> V_448 ) ;
* V_449 = F_94 ( V_452 -> V_454 ) ;
}
F_72 ( & V_4 -> V_432 ) ;
return V_28 ;
}
static int F_109 ( struct V_1 * V_2 )
{
return - 1 ;
}
static int F_110 ( struct V_1 * V_2 , T_1 V_429 , T_4 * V_107 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_1 V_455 ;
T_1 V_454 ;
T_4 * V_45 ;
T_6 V_456 ;
T_7 V_348 ;
struct V_457 V_347 = { 0 } ;
V_28 = F_108 ( V_2 , & V_455 , & V_454 ) ;
if ( V_28 != 0 )
return V_28 ;
if ( V_429 < 2 )
return - V_80 ;
* V_107 ++ = V_455 ;
* V_107 ++ = V_454 ;
V_429 -= 2 ;
memset ( V_107 , 0xff , V_429 ) ;
V_456 = V_455 * V_454 ;
V_45 = F_88 ( & V_4 -> V_210 -> V_2 , V_456 , & V_348 ,
V_202 ) ;
if ( ! V_45 ) {
F_17 ( V_2 , L_30 ,
( unsigned ) V_456 ) ;
return - V_352 ;
}
F_85 ( V_4 , & V_347 , V_458 , - 1 , - 1 ) ;
V_347 . V_459 = F_89 ( V_348 ) ;
V_28 = F_90 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 == 0 )
memcpy ( V_107 , V_45 , V_429 > V_456 ? V_456 : V_429 ) ;
F_91 ( & V_4 -> V_210 -> V_2 , V_456 , V_45 , V_348 ) ;
return V_28 ;
}
static int F_111 ( struct V_1 * V_2 , T_1 V_420 , T_1 V_61 ,
T_1 V_449 , T_4 * V_107 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_4 * V_45 ;
T_7 V_348 ;
struct V_460 V_347 = { 0 } ;
V_45 = F_88 ( & V_4 -> V_210 -> V_2 , V_449 , & V_348 ,
V_202 ) ;
if ( ! V_45 ) {
F_17 ( V_2 , L_30 ,
( unsigned ) V_449 ) ;
return - V_352 ;
}
F_85 ( V_4 , & V_347 , V_461 , - 1 , - 1 ) ;
V_347 . V_459 = F_89 ( V_348 ) ;
V_347 . V_428 = F_86 ( V_420 ) ;
V_347 . V_61 = F_87 ( V_61 ) ;
V_347 . V_429 = F_87 ( V_449 ) ;
V_28 = F_90 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 == 0 )
memcpy ( V_107 , V_45 , V_449 ) ;
F_91 ( & V_4 -> V_210 -> V_2 , V_449 , V_45 , V_348 ) ;
return V_28 ;
}
static int F_105 ( struct V_1 * V_2 , T_5 type , T_5 V_462 ,
T_5 V_463 , T_5 * V_420 , T_1 * V_464 ,
T_1 * V_465 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_466 V_347 = { 0 } ;
struct V_467 * V_452 = V_4 -> V_416 ;
F_85 ( V_4 , & V_347 , V_468 , - 1 , - 1 ) ;
V_347 . V_469 = 0 ;
V_347 . V_428 = 0 ;
V_347 . V_341 = F_86 ( type ) ;
V_347 . V_342 = F_86 ( V_462 ) ;
V_347 . V_343 = F_86 ( V_463 ) ;
V_347 . V_470 = V_471 ;
F_70 ( & V_4 -> V_432 ) ;
V_28 = F_112 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 == 0 ) {
if ( V_420 )
* V_420 = F_50 ( V_452 -> V_428 ) ;
if ( V_464 )
* V_464 = F_94 ( V_452 -> V_472 ) ;
if ( V_465 )
* V_465 = F_94 ( V_452 -> V_351 ) ;
}
F_72 ( & V_4 -> V_432 ) ;
return V_28 ;
}
static char * F_113 ( int V_473 , T_4 * V_107 , T_6 V_474 )
{
char * V_475 = NULL ;
char * V_476 ;
char * V_6 ;
int V_477 = 0 ;
if ( V_474 < 1 )
return NULL ;
V_107 [ V_474 - 1 ] = 0 ;
for ( V_476 = V_107 ; * V_476 != 0 ; V_476 ++ ) {
V_477 = 0 ;
V_475 = NULL ;
while ( * V_476 != 0 && * V_476 != '\n' ) {
V_6 = V_476 ;
while ( * V_476 != 0 && * V_476 != '\t' && * V_476 != '\n' )
V_476 ++ ;
if ( V_477 == V_473 )
V_475 = V_6 ;
if ( * V_476 != '\t' )
break;
* V_476 = 0 ;
V_477 ++ ;
V_476 ++ ;
}
if ( * V_476 == 0 )
break;
* V_476 = 0 ;
}
return V_475 ;
}
static char * F_53 ( struct V_1 * V_2 , char * V_45 , T_6 V_456 )
{
T_5 V_420 = 0 ;
T_1 V_474 ;
if ( F_105 ( V_2 , V_478 ,
V_394 , V_422 ,
& V_420 , NULL , & V_474 ) != 0 )
return NULL ;
memset ( V_45 , 0 , V_456 ) ;
if ( F_111 ( V_2 , V_420 , 0 , V_474 , V_45 ) != 0 )
return NULL ;
return F_113 ( V_479 , V_45 ,
V_474 ) ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_480 * V_481 ,
T_4 * V_107 )
{
T_1 V_420 ;
T_1 V_61 ;
if ( V_481 -> V_61 == 0 )
return F_110 ( V_2 , V_481 -> V_429 , V_107 ) ;
V_420 = V_481 -> V_61 >> 24 ;
V_61 = V_481 -> V_61 & 0xffffff ;
if ( V_420 == 0 ) {
F_17 ( V_2 , L_48 , V_420 ) ;
return - V_80 ;
}
return F_111 ( V_2 , V_420 - 1 , V_61 , V_481 -> V_429 , V_107 ) ;
}
static int F_115 ( struct V_1 * V_2 , T_4 V_420 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_482 V_347 = { 0 } ;
F_85 ( V_4 , & V_347 , V_483 , - 1 , - 1 ) ;
V_347 . V_428 = F_86 ( V_420 ) ;
return F_90 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_480 * V_481 ,
T_4 * V_107 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_420 , V_484 ;
T_5 type , V_463 , V_462 , V_485 ;
if ( ! F_29 ( V_4 ) ) {
F_17 ( V_2 , L_49 ) ;
return - V_80 ;
}
type = V_481 -> V_486 >> 16 ;
if ( type == 0xffff ) {
V_420 = V_481 -> V_486 & 0xff ;
V_484 = V_481 -> V_486 >> 8 ;
if ( V_420 == 0 )
return - V_80 ;
switch ( V_484 ) {
case 0x0e :
if ( V_481 -> V_61 != ~ V_481 -> V_486 )
return - V_80 ;
return F_115 ( V_2 , V_420 - 1 ) ;
default:
return - V_80 ;
}
}
if ( F_99 ( type ) == true )
return - V_42 ;
V_463 = V_481 -> V_486 & 0xffff ;
V_462 = V_481 -> V_61 >> 16 ;
V_485 = V_481 -> V_61 & 0xffff ;
return F_84 ( V_2 , type , V_462 , V_463 , V_485 , V_107 ,
V_481 -> V_429 ) ;
}
static int F_117 ( struct V_1 * V_2 , struct V_487 * V_488 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_487 * V_489 = & V_4 -> V_489 ;
struct V_241 * V_242 = & V_4 -> V_242 ;
T_1 V_245 =
F_61 ( V_242 -> V_245 , 0 ) ;
int V_28 = 0 ;
if ( ! F_76 ( V_4 ) )
return - V_42 ;
if ( ! ( V_4 -> V_35 & V_490 ) )
return - V_42 ;
if ( ! V_488 -> V_491 )
goto V_492;
if ( ! ( V_242 -> V_246 & V_327 ) ) {
F_28 ( V_2 , L_50 ) ;
return - V_80 ;
}
if ( V_488 -> V_493 ) {
if ( V_4 -> V_494 && ( V_488 -> V_495 > V_4 -> V_494 ||
V_488 -> V_495 < V_4 -> V_496 ) ) {
F_28 ( V_2 , L_51 ,
V_4 -> V_496 , V_4 -> V_494 ) ;
return - V_80 ;
} else if ( ! V_4 -> V_494 ) {
V_488 -> V_495 = V_489 -> V_495 ;
}
}
if ( ! V_488 -> V_497 ) {
V_488 -> V_497 = V_245 & V_489 -> V_217 ;
} else if ( V_488 -> V_497 & ~ V_245 ) {
F_28 ( V_2 , L_52 ,
V_488 -> V_497 , V_245 ) ;
return - V_80 ;
}
V_489 -> V_497 = V_488 -> V_497 ;
V_489 -> V_493 = V_488 -> V_493 ;
V_489 -> V_495 = V_488 -> V_495 ;
V_492:
V_489 -> V_491 = V_488 -> V_491 ;
if ( F_8 ( V_2 ) )
V_28 = F_78 ( V_4 , false , true ) ;
return V_28 ;
}
static int F_118 ( struct V_1 * V_2 , struct V_487 * V_488 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_4 -> V_35 & V_490 ) )
return - V_42 ;
* V_488 = V_4 -> V_489 ;
if ( ! V_4 -> V_489 . V_491 ) {
V_488 -> V_497 = 0 ;
V_488 -> V_493 = 0 ;
}
if ( ! V_4 -> V_489 . V_498 )
V_488 -> V_499 = 0 ;
return 0 ;
}
static int F_119 ( struct V_3 * V_4 , T_5 V_500 ,
T_5 V_501 , T_5 V_502 ,
T_5 V_465 , T_4 * V_45 )
{
struct V_503 V_347 = { 0 } ;
struct V_504 * V_452 = V_4 -> V_416 ;
int V_28 , V_505 = 0 ;
F_85 ( V_4 , & V_347 , V_506 , - 1 , - 1 ) ;
V_347 . V_507 = V_500 ;
V_347 . V_501 = F_86 ( V_501 ) ;
V_347 . V_508 = F_86 ( V_4 -> V_509 . V_508 ) ;
do {
T_5 V_510 ;
V_510 = F_23 ( T_5 , V_465 , V_511 ) ;
V_465 -= V_510 ;
V_347 . V_512 = F_86 ( V_502 + V_505 ) ;
V_347 . V_465 = V_510 ;
V_347 . V_469 = F_87 ( V_502 + V_505 ?
V_513 : 0 ) ;
F_70 ( & V_4 -> V_432 ) ;
V_28 = F_106 ( V_4 , & V_347 , sizeof( V_347 ) ,
V_373 ) ;
if ( ! V_28 )
memcpy ( V_45 + V_505 , V_452 -> V_107 , V_510 ) ;
F_72 ( & V_4 -> V_432 ) ;
V_505 += V_510 ;
} while ( ! V_28 && V_465 > 0 );
return V_28 ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_514 * V_515 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_503 V_347 = { 0 } ;
struct V_504 * V_452 = V_4 -> V_416 ;
int V_28 ;
if ( V_4 -> V_242 . V_516 >
V_517 )
return - V_42 ;
if ( V_4 -> V_337 < 0x10202 )
return - V_42 ;
F_85 ( V_4 , & V_347 , V_506 , - 1 , - 1 ) ;
V_347 . V_507 = V_518 ;
V_347 . V_501 = 0 ;
V_347 . V_512 = F_86 ( V_519 ) ;
V_347 . V_465 = V_520 ;
V_347 . V_508 = F_86 ( V_4 -> V_509 . V_508 ) ;
F_70 ( & V_4 -> V_432 ) ;
V_28 = F_106 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( ! V_28 ) {
T_1 V_521 = F_94 ( V_452 -> V_107 [ 0 ] ) ;
switch ( V_521 ) {
case V_522 :
V_515 -> type = V_523 ;
V_515 -> V_524 = V_525 ;
break;
case V_526 :
case V_527 :
V_515 -> type = V_528 ;
V_515 -> V_524 = V_529 ;
break;
case V_530 :
V_515 -> type = V_531 ;
V_515 -> V_524 = V_532 ;
break;
default:
V_28 = - V_42 ;
break;
}
}
F_72 ( & V_4 -> V_432 ) ;
return V_28 ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_480 * V_481 ,
T_4 * V_107 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_5 V_533 = V_481 -> V_61 , V_449 = V_481 -> V_429 ;
int V_28 = 0 ;
memset ( V_107 , 0 , V_481 -> V_429 ) ;
if ( V_533 < V_529 ) {
if ( V_533 + V_481 -> V_429 > V_529 )
V_449 = V_529 - V_533 ;
V_28 = F_119 ( V_4 , V_518 , 0 ,
V_533 , V_449 , V_107 ) ;
if ( V_28 )
return V_28 ;
V_533 += V_449 ;
V_107 += V_449 ;
V_449 = V_481 -> V_429 - V_449 ;
}
if ( V_449 ) {
V_533 -= V_529 ;
F_119 ( V_4 , V_534 , 1 , V_533 ,
V_449 , V_107 ) ;
}
return V_28 ;
}
static int F_122 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_241 * V_242 = & V_4 -> V_242 ;
if ( ! F_76 ( V_4 ) )
return - V_42 ;
if ( ! ( V_242 -> V_246 & V_327 ) )
return - V_80 ;
if ( F_8 ( V_2 ) )
V_28 = F_78 ( V_4 , true , false ) ;
return V_28 ;
}
static int F_123 ( struct V_1 * V_2 ,
enum V_535 V_536 )
{
struct V_537 V_347 = { 0 } ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_538 * V_509 = & V_4 -> V_509 ;
struct V_539 * V_540 ;
T_4 V_541 ;
T_8 V_542 ;
int V_46 , V_28 ;
if ( ! V_4 -> V_543 || F_80 ( V_4 ) )
return - V_42 ;
if ( V_536 == V_544 ) {
V_541 = V_545 ;
V_542 = F_86 ( 500 ) ;
} else if ( V_536 == V_546 ) {
V_541 = V_547 ;
V_542 = F_86 ( 0 ) ;
} else {
return - V_80 ;
}
F_85 ( V_4 , & V_347 , V_548 , - 1 , - 1 ) ;
V_347 . V_508 = F_86 ( V_509 -> V_508 ) ;
V_347 . V_543 = V_4 -> V_543 ;
V_540 = (struct V_539 * ) & V_347 . V_549 ;
for ( V_46 = 0 ; V_46 < V_4 -> V_543 ; V_46 ++ , V_540 ++ ) {
V_347 . V_469 |= F_124 ( V_46 ) ;
V_540 -> V_550 = V_4 -> V_551 [ V_46 ] . V_550 ;
V_540 -> V_541 = V_541 ;
V_540 -> V_552 = V_542 ;
V_540 -> V_553 = V_542 ;
V_540 -> V_554 = V_4 -> V_551 [ V_46 ] . V_554 ;
}
V_28 = F_90 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 )
V_28 = - V_555 ;
return V_28 ;
}
static int F_125 ( struct V_3 * V_4 , T_5 V_556 )
{
struct V_557 V_347 = { 0 } ;
F_85 ( V_4 , & V_347 , V_558 , V_556 , - 1 ) ;
return F_90 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_126 ( struct V_3 * V_4 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_4 -> V_34 ; V_46 ++ ) {
T_5 V_556 = V_4 -> V_559 [ V_46 ] . V_560 ;
int V_28 ;
V_28 = F_125 ( V_4 , V_556 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static int F_127 ( struct V_3 * V_4 , bool V_561 )
{
struct V_562 V_347 = { 0 } ;
F_85 ( V_4 , & V_347 , V_563 , - 1 , - 1 ) ;
V_347 . V_469 = F_87 ( V_564 ) ;
if ( V_561 )
V_347 . V_565 = V_566 ;
else
V_347 . V_565 = V_567 ;
return F_90 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_128 ( struct V_3 * V_4 ,
struct V_568 * V_347 )
{
struct V_241 * V_242 = & V_4 -> V_242 ;
T_5 V_326 = V_242 -> V_245 ;
T_5 V_308 ;
int V_28 ;
if ( ! V_242 -> V_246 )
return 0 ;
V_308 = V_569 ;
if ( F_71 ( V_4 -> V_2 ) )
V_308 = V_4 -> V_242 . V_284 ;
else if ( V_326 & V_232 )
V_308 = V_570 ;
else if ( V_326 & V_315 )
V_308 = V_571 ;
else if ( V_326 & V_234 )
V_308 = V_572 ;
else if ( V_326 & V_318 )
V_308 = V_573 ;
V_347 -> V_574 = F_86 ( V_308 ) ;
V_347 -> V_35 |= F_87 ( V_575 |
V_576 ) ;
V_28 = F_90 ( V_4 , V_347 , sizeof( * V_347 ) , V_373 ) ;
V_347 -> V_35 = 0 ;
V_347 -> V_574 = F_86 ( 0 ) ;
return V_28 ;
}
static int F_129 ( struct V_3 * V_4 , bool V_561 )
{
struct V_568 V_347 = { 0 } ;
F_85 ( V_4 , & V_347 , V_577 , - 1 , - 1 ) ;
if ( V_561 ) {
F_128 ( V_4 , & V_347 ) ;
V_347 . V_565 = V_578 ;
} else {
V_347 . V_565 = V_579 ;
}
V_347 . V_469 = F_87 ( V_580 ) ;
return F_90 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_130 ( struct V_3 * V_4 , struct V_51 * V_50 ,
T_1 V_581 , int V_582 )
{
struct V_52 * V_53 = & V_50 -> V_54 ;
struct V_583 * V_584 = V_50 -> V_585 ;
struct V_586 * V_587 ;
struct V_588 * V_589 ;
T_5 V_590 , V_591 ;
T_4 * V_107 ;
T_1 V_429 ;
int V_46 ;
V_590 = F_131 ( V_581 ) ;
V_589 = (struct V_588 * )
& V_53 -> V_592 [ F_132 ( V_590 ) ] [ F_133 ( V_590 ) ] ;
V_591 = V_589 -> V_593 ;
V_587 = & V_584 -> V_594 [ V_591 ] ;
V_107 = V_587 -> V_595 ;
V_429 = F_94 ( V_589 -> V_596 ) >> V_597 ;
if ( V_429 != V_582 )
return - V_555 ;
V_46 = V_598 ;
if ( ! F_134 ( V_107 + V_46 , V_50 -> V_4 -> V_2 -> V_599 ) )
return - V_555 ;
V_46 += V_598 ;
for ( ; V_46 < V_582 ; V_46 ++ ) {
if ( V_107 [ V_46 ] != ( T_4 ) ( V_46 & 0xff ) )
return - V_555 ;
}
return 0 ;
}
static int F_135 ( struct V_3 * V_4 , int V_582 )
{
struct V_51 * V_50 = V_4 -> V_50 [ 0 ] ;
struct V_52 * V_53 ;
struct V_600 * V_601 ;
int V_28 = - V_555 ;
T_1 V_581 ;
T_1 V_591 ;
int V_46 ;
V_53 = & V_50 -> V_54 ;
V_581 = V_53 -> V_602 ;
for ( V_46 = 0 ; V_46 < 200 ; V_46 ++ ) {
V_591 = F_131 ( V_581 ) ;
V_601 = & V_53 -> V_592 [ F_132 ( V_591 ) ] [ F_133 ( V_591 ) ] ;
if ( ! F_136 ( V_601 , V_581 ) ) {
F_137 ( 5 ) ;
continue;
}
F_138 () ;
if ( F_139 ( V_601 ) == V_603 ) {
V_28 = F_130 ( V_4 , V_50 , V_581 , V_582 ) ;
V_581 = F_140 ( V_581 ) ;
V_581 = F_140 ( V_581 ) ;
break;
}
V_581 = F_140 ( V_581 ) ;
}
V_53 -> V_602 = V_581 ;
return V_28 ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_604 * V_605 = & V_4 -> V_606 [ 0 ] ;
int V_582 , V_46 = 0 ;
struct V_607 * V_608 ;
T_7 V_609 ;
T_4 * V_107 ;
int V_28 ;
V_582 = F_142 ( V_4 -> V_2 -> V_610 + V_611 , V_4 -> V_612 ) ;
V_608 = F_143 ( V_4 -> V_2 , V_582 ) ;
if ( ! V_608 )
return - V_352 ;
V_107 = F_144 ( V_608 , V_582 ) ;
F_145 ( V_107 ) ;
V_46 += V_598 ;
F_146 ( & V_107 [ V_46 ] , V_4 -> V_2 -> V_599 ) ;
V_46 += V_598 ;
for ( ; V_46 < V_582 ; V_46 ++ )
V_107 [ V_46 ] = ( T_4 ) ( V_46 & 0xff ) ;
V_609 = F_147 ( & V_4 -> V_210 -> V_2 , V_608 -> V_107 , V_582 ,
V_613 ) ;
if ( F_148 ( & V_4 -> V_210 -> V_2 , V_609 ) ) {
F_149 ( V_608 ) ;
return - V_555 ;
}
F_150 ( V_4 , V_605 , V_609 , V_582 , 0 ) ;
F_151 () ;
F_152 ( V_4 , V_605 -> V_614 , V_615 | V_605 -> V_616 ) ;
V_28 = F_135 ( V_4 , V_582 ) ;
F_153 ( & V_4 -> V_210 -> V_2 , V_609 , V_582 , V_613 ) ;
F_149 ( V_608 ) ;
return V_28 ;
}
static int F_154 ( struct V_3 * V_4 , T_4 V_617 , T_4 * V_618 )
{
struct V_619 * V_415 = V_4 -> V_416 ;
struct V_620 V_347 = { 0 } ;
int V_28 ;
F_85 ( V_4 , & V_347 , V_621 , - 1 , - 1 ) ;
F_70 ( & V_4 -> V_432 ) ;
V_415 -> V_622 = 0 ;
V_347 . V_35 = V_617 ;
V_28 = F_106 ( V_4 , & V_347 , sizeof( V_347 ) , V_4 -> V_64 -> V_623 ) ;
* V_618 = V_415 -> V_622 ;
F_72 ( & V_4 -> V_432 ) ;
return V_28 ;
}
static void F_155 ( struct V_1 * V_2 , struct V_624 * V_625 ,
T_2 * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_626 = false ;
T_4 V_618 = 0 ;
T_4 V_617 = 0 ;
int V_28 , V_46 ;
if ( ! V_4 -> V_41 || ! F_76 ( V_4 ) )
return;
memset ( V_45 , 0 , sizeof( T_2 ) * V_4 -> V_41 ) ;
if ( ! F_8 ( V_2 ) ) {
V_625 -> V_35 |= V_627 ;
return;
}
if ( V_625 -> V_35 & V_628 ) {
if ( V_4 -> V_509 . V_629 ) {
V_625 -> V_35 |= V_627 ;
F_28 ( V_2 , L_53 ) ;
return;
}
V_626 = true ;
}
for ( V_46 = 0 ; V_46 < V_4 -> V_41 - V_630 ; V_46 ++ ) {
T_4 V_631 = 1 << V_46 ;
if ( ! ( V_4 -> V_64 -> V_632 & V_631 ) )
V_617 |= V_631 ;
else if ( V_626 )
V_617 |= V_631 ;
}
if ( ! V_626 ) {
F_154 ( V_4 , V_617 , & V_618 ) ;
} else {
V_28 = F_9 ( V_4 , false , false ) ;
if ( V_28 )
return;
F_154 ( V_4 , V_617 , & V_618 ) ;
V_45 [ V_633 ] = 1 ;
F_127 ( V_4 , true ) ;
F_156 ( 250 ) ;
V_28 = F_157 ( V_4 ) ;
if ( V_28 ) {
F_127 ( V_4 , false ) ;
V_625 -> V_35 |= V_627 ;
return;
}
if ( F_141 ( V_4 ) )
V_625 -> V_35 |= V_627 ;
else
V_45 [ V_633 ] = 0 ;
F_127 ( V_4 , false ) ;
F_129 ( V_4 , true ) ;
F_156 ( 1000 ) ;
if ( F_141 ( V_4 ) ) {
V_45 [ V_634 ] = 1 ;
V_625 -> V_35 |= V_627 ;
}
F_129 ( V_4 , false ) ;
F_158 ( V_4 ) ;
F_10 ( V_4 , false , true ) ;
}
if ( F_126 ( V_4 ) ) {
V_45 [ V_635 ] = 1 ;
V_625 -> V_35 |= V_627 ;
}
for ( V_46 = 0 ; V_46 < V_4 -> V_41 - V_630 ; V_46 ++ ) {
T_4 V_631 = 1 << V_46 ;
if ( ( V_617 & V_631 ) && ! ( V_618 & V_631 ) ) {
V_45 [ V_46 ] = 1 ;
V_625 -> V_35 |= V_627 ;
}
}
}
void F_159 ( struct V_3 * V_4 )
{
struct V_636 * V_415 = V_4 -> V_416 ;
struct V_637 V_347 = { 0 } ;
struct V_638 * V_64 ;
int V_46 , V_28 ;
if ( V_4 -> V_337 < 0x10704 || ! F_76 ( V_4 ) )
return;
F_85 ( V_4 , & V_347 , V_639 , - 1 , - 1 ) ;
F_70 ( & V_4 -> V_432 ) ;
V_28 = F_106 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 )
goto V_640;
V_64 = F_160 ( sizeof( * V_4 -> V_64 ) , V_202 ) ;
if ( ! V_64 )
goto V_640;
V_4 -> V_64 = V_64 ;
V_4 -> V_41 = V_415 -> V_41 + V_630 ;
if ( V_4 -> V_41 > V_641 )
V_4 -> V_41 = V_641 ;
V_64 -> V_632 = V_415 -> V_642 ;
V_64 -> V_623 = F_50 ( V_415 -> V_643 ) ;
if ( ! V_64 -> V_623 )
V_64 -> V_623 = V_373 ;
for ( V_46 = 0 ; V_46 < V_4 -> V_41 ; V_46 ++ ) {
char * V_644 = V_64 -> string [ V_46 ] ;
char * V_645 = V_415 -> V_646 + V_46 * 32 ;
if ( V_46 == V_633 ) {
strcpy ( V_644 , L_54 ) ;
} else if ( V_46 == V_634 ) {
strcpy ( V_644 , L_55 ) ;
} else if ( V_46 == V_635 ) {
strcpy ( V_644 , L_56 ) ;
} else {
F_54 ( V_644 , V_645 , V_63 ) ;
strncat ( V_644 , L_57 , V_63 - strlen ( V_644 ) ) ;
if ( V_64 -> V_632 & ( 1 << V_46 ) )
strncat ( V_644 , L_58 ,
V_63 - strlen ( V_644 ) ) ;
else
strncat ( V_644 , L_59 ,
V_63 - strlen ( V_644 ) ) ;
}
}
V_640:
F_72 ( & V_4 -> V_432 ) ;
}
void F_161 ( struct V_3 * V_4 )
{
F_56 ( V_4 -> V_64 ) ;
V_4 -> V_64 = NULL ;
}
