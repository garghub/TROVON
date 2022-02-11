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
case V_40 :
if ( ! V_4 -> V_41 )
return - V_42 ;
return V_4 -> V_41 ;
default:
return - V_42 ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_43 * V_44 , T_2 * V_45 )
{
T_1 V_46 , V_47 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_48 = sizeof( struct V_49 ) * V_4 -> V_36 ;
T_1 V_50 = sizeof( struct V_49 ) / 8 ;
memset ( V_45 , 0 , V_48 ) ;
if ( ! V_4 -> V_51 )
return;
for ( V_46 = 0 ; V_46 < V_4 -> V_36 ; V_46 ++ ) {
struct V_52 * V_51 = V_4 -> V_51 [ V_46 ] ;
struct V_53 * V_54 = & V_51 -> V_55 ;
T_3 * V_56 = ( T_3 * ) V_54 -> V_56 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_50 ; V_47 ++ , V_57 ++ )
V_45 [ V_47 ] = F_14 ( V_56 [ V_57 ] ) ;
V_45 [ V_47 ++ ] = V_54 -> V_58 ;
}
if ( V_4 -> V_37 & V_38 ) {
T_3 * V_59 = ( T_3 * ) V_4 -> V_60 ;
for ( V_46 = 0 ; V_46 < V_39 ; V_46 ++ , V_47 ++ ) {
V_45 [ V_47 ] = F_14 ( * ( V_59 +
V_61 [ V_46 ] . V_62 ) ) ;
}
}
}
static void F_15 ( struct V_1 * V_2 , T_1 V_63 , T_4 * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_46 ;
switch ( V_63 ) {
case V_33 :
for ( V_46 = 0 ; V_46 < V_4 -> V_36 ; V_46 ++ ) {
sprintf ( V_45 , L_1 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_2 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_3 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_4 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_5 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_6 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_7 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_8 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_9 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_10 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_11 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_12 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_13 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_14 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_15 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_16 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_17 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_18 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_19 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_20 , V_46 ) ;
V_45 += V_64 ;
sprintf ( V_45 , L_21 , V_46 ) ;
V_45 += V_64 ;
}
if ( V_4 -> V_37 & V_38 ) {
for ( V_46 = 0 ; V_46 < V_39 ; V_46 ++ ) {
strcpy ( V_45 , V_61 [ V_46 ] . string ) ;
V_45 += V_64 ;
}
}
break;
case V_40 :
if ( V_4 -> V_41 )
memcpy ( V_45 , V_4 -> V_65 -> string ,
V_4 -> V_41 * V_64 ) ;
break;
default:
F_16 ( V_4 -> V_2 , L_22 ,
V_63 ) ;
break;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_67 -> V_68 = V_69 ;
V_67 -> V_70 = V_71 ;
V_67 -> V_72 = V_73 ;
V_67 -> V_74 = V_4 -> V_75 ;
V_67 -> V_76 = V_4 -> V_77 ;
V_67 -> V_78 = V_4 -> V_79 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_67 -> V_74 > V_69 ) ||
( V_67 -> V_78 > V_73 ) ||
( V_67 -> V_78 <= V_80 ) )
return - V_81 ;
if ( F_8 ( V_2 ) )
F_9 ( V_4 , false , false ) ;
V_4 -> V_75 = V_67 -> V_74 ;
V_4 -> V_79 = V_67 -> V_78 ;
F_19 ( V_4 ) ;
if ( F_8 ( V_2 ) )
return F_10 ( V_4 , false , false ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_84 , V_85 , V_86 ;
F_21 ( V_4 , & V_84 , & V_85 , true ) ;
V_83 -> V_87 = F_22 ( int , V_84 , V_85 ) ;
if ( F_21 ( V_4 , & V_84 , & V_85 , false ) ) {
V_84 = 0 ;
V_85 = 0 ;
}
V_86 = F_23 ( V_2 ) ;
if ( V_86 > 1 )
V_85 /= V_86 ;
V_83 -> V_88 = V_84 ;
V_83 -> V_89 = V_85 ;
V_83 -> V_90 = 0 ;
if ( V_4 -> V_37 & V_91 ) {
V_83 -> V_92 = V_4 -> V_93 ;
if ( F_24 ( V_4 ) )
V_83 -> V_92 -- ;
} else {
if ( ! F_24 ( V_4 ) ) {
V_83 -> V_94 = V_4 -> V_93 ;
V_83 -> V_95 = V_4 -> V_96 ;
}
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_97 , V_98 , V_86 ;
bool V_99 = false ;
int V_100 = 0 ;
int V_28 = 0 ;
if ( V_83 -> V_101 )
return - V_81 ;
if ( ! V_83 -> V_92 &&
( ! V_83 -> V_94 || ! V_83 -> V_95 ) )
return - V_81 ;
if ( V_83 -> V_92 &&
( V_83 -> V_94 || V_83 -> V_95 ) )
return - V_81 ;
if ( F_24 ( V_4 ) && ( V_83 -> V_94 ||
V_83 -> V_95 ) )
return - V_81 ;
if ( V_83 -> V_92 )
V_99 = true ;
V_86 = F_23 ( V_2 ) ;
V_97 = V_99 ? V_83 -> V_92 : V_83 -> V_95 ;
V_98 = V_99 ? V_83 -> V_92 : V_83 -> V_94 ;
if ( V_4 -> V_102 ) {
if ( ! V_99 ) {
F_16 ( V_2 , L_23 ) ;
return - V_81 ;
}
V_100 = V_98 ;
}
V_28 = F_26 ( V_4 , V_97 , V_98 , V_86 , V_100 ) ;
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
if ( V_99 ) {
V_4 -> V_37 |= V_91 ;
V_4 -> V_93 = V_83 -> V_92 ;
V_4 -> V_96 = V_83 -> V_92 ;
} else {
V_4 -> V_37 &= ~ V_91 ;
V_4 -> V_93 = V_83 -> V_94 ;
V_4 -> V_96 = V_83 -> V_95 ;
}
V_4 -> V_102 = V_100 ;
V_4 -> V_103 = V_4 -> V_96 + V_100 ;
if ( V_86 > 1 )
V_4 -> V_103 = V_4 -> V_96 * V_86 + V_100 ;
V_4 -> V_36 = V_99 ? F_29 ( int , V_4 -> V_103 , V_4 -> V_93 ) :
V_4 -> V_103 + V_4 -> V_93 ;
V_4 -> V_104 = V_4 -> V_36 ;
F_30 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
V_28 = F_10 ( V_4 , true , false ) ;
if ( ( ! V_28 ) && F_28 ( V_4 ) ) {
}
}
return V_28 ;
}
static int F_31 ( struct V_3 * V_4 , struct V_105 * V_106 ,
T_1 * V_107 )
{
int V_46 , V_47 = 0 ;
V_106 -> V_108 = V_4 -> V_109 ;
for ( V_46 = 0 ; V_46 < V_110 ; V_46 ++ ) {
struct V_111 * V_112 ;
struct V_113 * V_114 ;
V_112 = & V_4 -> V_115 [ V_46 ] ;
F_32 () ;
F_33 (fltr, head, hash) {
if ( V_47 == V_106 -> V_116 )
break;
V_107 [ V_47 ++ ] = V_114 -> V_117 ;
}
F_34 () ;
if ( V_47 == V_106 -> V_116 )
break;
}
V_106 -> V_116 = V_47 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 , struct V_105 * V_106 )
{
struct V_118 * V_119 =
(struct V_118 * ) & V_106 -> V_119 ;
struct V_113 * V_114 ;
struct V_120 * V_121 ;
int V_46 , V_28 = - V_81 ;
if ( V_119 -> V_122 < 0 || V_119 -> V_122 >= V_123 )
return V_28 ;
for ( V_46 = 0 ; V_46 < V_110 ; V_46 ++ ) {
struct V_111 * V_112 ;
V_112 = & V_4 -> V_115 [ V_46 ] ;
F_32 () ;
F_33 (fltr, head, hash) {
if ( V_114 -> V_117 == V_119 -> V_122 )
goto V_124;
}
F_34 () ;
}
return V_28 ;
V_124:
V_121 = & V_114 -> V_121 ;
if ( V_121 -> V_125 . V_126 == F_36 ( V_127 ) ) {
if ( V_121 -> V_125 . V_128 == V_129 )
V_119 -> V_130 = V_131 ;
else if ( V_121 -> V_125 . V_128 == V_132 )
V_119 -> V_130 = V_133 ;
else
goto V_134;
V_119 -> V_135 . V_136 . V_137 = V_121 -> V_138 . V_139 . V_140 ;
V_119 -> V_141 . V_136 . V_137 = F_37 ( ~ 0 ) ;
V_119 -> V_135 . V_136 . V_142 = V_121 -> V_138 . V_139 . V_143 ;
V_119 -> V_141 . V_136 . V_142 = F_37 ( ~ 0 ) ;
V_119 -> V_135 . V_136 . V_144 = V_121 -> V_145 . V_140 ;
V_119 -> V_141 . V_136 . V_144 = F_38 ( ~ 0 ) ;
V_119 -> V_135 . V_136 . V_146 = V_121 -> V_145 . V_143 ;
V_119 -> V_141 . V_136 . V_146 = F_38 ( ~ 0 ) ;
} else {
int V_46 ;
if ( V_121 -> V_125 . V_128 == V_129 )
V_119 -> V_130 = V_147 ;
else if ( V_121 -> V_125 . V_128 == V_132 )
V_119 -> V_130 = V_148 ;
else
goto V_134;
* (struct V_149 * ) & V_119 -> V_135 . V_150 . V_151 [ 0 ] =
V_121 -> V_138 . V_152 . V_140 ;
* (struct V_149 * ) & V_119 -> V_135 . V_150 . V_153 [ 0 ] =
V_121 -> V_138 . V_152 . V_143 ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_119 -> V_141 . V_150 . V_151 [ V_46 ] = F_37 ( ~ 0 ) ;
V_119 -> V_141 . V_150 . V_153 [ V_46 ] = F_37 ( ~ 0 ) ;
}
V_119 -> V_135 . V_150 . V_144 = V_121 -> V_145 . V_140 ;
V_119 -> V_141 . V_150 . V_144 = F_38 ( ~ 0 ) ;
V_119 -> V_135 . V_150 . V_146 = V_121 -> V_145 . V_143 ;
V_119 -> V_141 . V_150 . V_146 = F_38 ( ~ 0 ) ;
}
V_119 -> V_154 = V_114 -> V_155 ;
V_28 = 0 ;
V_134:
F_34 () ;
return V_28 ;
}
static T_2 F_39 ( struct V_3 * V_4 )
{
if ( V_4 -> V_156 & V_157 )
return V_158 | V_159 ;
return 0 ;
}
static T_2 F_40 ( struct V_3 * V_4 )
{
if ( V_4 -> V_156 & V_160 )
return V_158 | V_159 ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , struct V_105 * V_106 )
{
V_106 -> V_108 = 0 ;
switch ( V_106 -> V_130 ) {
case V_131 :
if ( V_4 -> V_156 & V_161 )
V_106 -> V_108 |= V_158 | V_159 |
V_162 | V_163 ;
V_106 -> V_108 |= F_39 ( V_4 ) ;
break;
case V_133 :
if ( V_4 -> V_156 & V_164 )
V_106 -> V_108 |= V_158 | V_159 |
V_162 | V_163 ;
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
V_106 -> V_108 |= F_39 ( V_4 ) ;
break;
case V_147 :
if ( V_4 -> V_156 & V_170 )
V_106 -> V_108 |= V_158 | V_159 |
V_162 | V_163 ;
V_106 -> V_108 |= F_40 ( V_4 ) ;
break;
case V_148 :
if ( V_4 -> V_156 & V_171 )
V_106 -> V_108 |= V_158 | V_159 |
V_162 | V_163 ;
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
V_106 -> V_108 |= F_40 ( V_4 ) ;
break;
}
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , struct V_105 * V_106 )
{
T_1 V_156 = V_4 -> V_156 ;
int V_177 , V_28 = 0 ;
if ( V_106 -> V_108 == V_178 )
V_177 = 4 ;
else if ( V_106 -> V_108 == V_179 )
V_177 = 2 ;
else if ( ! V_106 -> V_108 )
V_177 = 0 ;
else
return - V_81 ;
if ( V_106 -> V_130 == V_131 ) {
V_156 &= ~ V_161 ;
if ( V_177 == 4 )
V_156 |= V_161 ;
} else if ( V_106 -> V_130 == V_133 ) {
if ( V_177 == 4 && ! ( V_4 -> V_37 & V_180 ) )
return - V_81 ;
V_156 &= ~ V_164 ;
if ( V_177 == 4 )
V_156 |= V_164 ;
} else if ( V_106 -> V_130 == V_147 ) {
V_156 &= ~ V_170 ;
if ( V_177 == 4 )
V_156 |= V_170 ;
} else if ( V_106 -> V_130 == V_148 ) {
if ( V_177 == 4 && ! ( V_4 -> V_37 & V_180 ) )
return - V_81 ;
V_156 &= ~ V_171 ;
if ( V_177 == 4 )
V_156 |= V_171 ;
} else if ( V_177 == 4 ) {
return - V_81 ;
}
switch ( V_106 -> V_130 ) {
case V_131 :
case V_133 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
if ( V_177 == 2 )
V_156 |= V_157 ;
else if ( ! V_177 )
V_156 &= ~ V_157 ;
break;
case V_147 :
case V_148 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
if ( V_177 == 2 )
V_156 |= V_160 ;
else if ( ! V_177 )
V_156 &= ~ V_160 ;
break;
}
if ( V_4 -> V_156 == V_156 )
return 0 ;
V_4 -> V_156 = V_156 ;
if ( F_8 ( V_4 -> V_2 ) ) {
F_9 ( V_4 , false , false ) ;
V_28 = F_10 ( V_4 , false , false ) ;
}
return V_28 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_105 * V_106 ,
T_1 * V_107 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 = 0 ;
switch ( V_106 -> V_106 ) {
#ifdef F_44
case V_181 :
V_106 -> V_108 = V_4 -> V_93 ;
break;
case V_182 :
V_106 -> V_116 = V_4 -> V_109 ;
V_106 -> V_108 = V_123 ;
break;
case V_183 :
V_28 = F_31 ( V_4 , V_106 , ( T_1 * ) V_107 ) ;
break;
case V_184 :
V_28 = F_35 ( V_4 , V_106 ) ;
break;
#endif
case V_185 :
V_28 = F_41 ( V_4 , V_106 ) ;
break;
default:
V_28 = - V_42 ;
break;
}
return V_28 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_105 * V_106 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
switch ( V_106 -> V_106 ) {
case V_186 :
V_28 = F_42 ( V_4 , V_106 ) ;
break;
default:
V_28 = - V_42 ;
break;
}
return V_28 ;
}
static T_1 F_46 ( struct V_1 * V_2 )
{
return V_187 ;
}
static T_1 F_47 ( struct V_1 * V_2 )
{
return V_188 ;
}
static int F_48 ( struct V_1 * V_2 , T_1 * V_189 , T_4 * V_190 ,
T_4 * V_191 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_192 * V_193 = & V_4 -> V_194 [ 0 ] ;
int V_46 = 0 ;
if ( V_191 )
* V_191 = V_195 ;
if ( V_189 )
for ( V_46 = 0 ; V_46 < V_187 ; V_46 ++ )
V_189 [ V_46 ] = F_49 ( V_193 -> V_196 [ V_46 ] ) ;
if ( V_190 )
memcpy ( V_190 , V_193 -> V_197 , V_188 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_198 * V_199 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
char * V_200 ;
char * V_201 = NULL ;
V_200 = F_51 ( V_202 , V_203 ) ;
if ( V_200 )
V_201 = F_52 ( V_2 , V_200 , V_202 ) ;
F_53 ( V_199 -> V_204 , V_205 , sizeof( V_199 -> V_204 ) ) ;
F_53 ( V_199 -> V_206 , V_207 , sizeof( V_199 -> V_206 ) ) ;
if ( V_201 && * V_201 != 0 && isdigit ( * V_201 ) )
snprintf ( V_199 -> V_208 , sizeof( V_199 -> V_208 ) - 1 ,
L_26 , V_4 -> V_209 , V_201 ) ;
else
F_53 ( V_199 -> V_208 , V_4 -> V_209 ,
sizeof( V_199 -> V_208 ) ) ;
F_53 ( V_199 -> V_210 , F_54 ( V_4 -> V_211 ) , sizeof( V_199 -> V_210 ) ) ;
V_199 -> V_212 = V_35 * V_4 -> V_36 ;
V_199 -> V_213 = V_4 -> V_41 ;
V_199 -> V_214 = 0 ;
V_199 -> V_215 = 0 ;
F_55 ( V_200 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_216 * V_217 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_217 -> V_218 = 0 ;
V_217 -> V_219 = 0 ;
memset ( & V_217 -> V_220 , 0 , sizeof( V_217 -> V_220 ) ) ;
if ( V_4 -> V_37 & V_221 ) {
V_217 -> V_218 = V_222 ;
if ( V_4 -> V_217 )
V_217 -> V_219 = V_222 ;
}
}
static int F_57 ( struct V_1 * V_2 , struct V_216 * V_217 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_217 -> V_219 & ~ V_222 )
return - V_81 ;
if ( V_217 -> V_219 & V_222 ) {
if ( ! ( V_4 -> V_37 & V_221 ) )
return - V_81 ;
if ( ! V_4 -> V_217 ) {
if ( F_58 ( V_4 ) )
return - V_223 ;
V_4 -> V_217 = 1 ;
}
} else {
if ( V_4 -> V_217 ) {
if ( F_59 ( V_4 ) )
return - V_223 ;
V_4 -> V_217 = 0 ;
}
}
return 0 ;
}
T_1 F_60 ( T_5 V_224 , T_4 V_225 )
{
T_1 V_226 = 0 ;
if ( V_224 & V_227 )
V_226 |= V_228 ;
if ( V_224 & V_229 )
V_226 |= V_230 ;
if ( V_224 & V_231 )
V_226 |= V_232 ;
if ( V_224 & V_233 )
V_226 |= V_234 ;
if ( V_224 & V_235 )
V_226 |= V_236 ;
if ( ( V_225 & V_237 ) == V_237 )
V_226 |= V_238 ;
else if ( V_225 & V_239 )
V_226 |= V_240 ;
else if ( V_225 & V_241 )
V_226 |= V_238 | V_240 ;
return V_226 ;
}
static void F_61 ( struct V_242 * V_243 ,
struct V_244 * V_245 )
{
T_5 V_224 = V_243 -> V_246 ;
T_4 V_225 = 0 ;
if ( V_243 -> V_247 & V_248 )
V_225 = V_243 -> V_249 ;
F_62 ( V_224 , V_225 , V_245 , V_246 ) ;
}
static void F_63 ( struct V_242 * V_243 ,
struct V_244 * V_245 )
{
T_5 V_224 = V_243 -> V_250 ;
T_4 V_225 = 0 ;
if ( V_243 -> V_247 & V_248 )
V_225 = V_243 -> V_251 ;
F_62 ( V_224 , V_225 , V_245 ,
V_252 ) ;
}
static void F_64 ( struct V_242 * V_243 ,
struct V_244 * V_245 )
{
T_5 V_224 = V_243 -> V_253 ;
F_62 ( V_224 , 0 , V_245 , V_218 ) ;
F_65 ( V_245 , V_218 , V_254 ) ;
F_65 ( V_245 , V_218 ,
V_255 ) ;
if ( V_243 -> V_256 )
F_65 ( V_245 , V_218 ,
V_257 ) ;
}
T_1 F_66 ( T_5 V_258 )
{
switch ( V_258 ) {
case V_259 :
return V_260 ;
case V_261 :
return V_262 ;
case V_263 :
return V_264 ;
case V_265 :
return V_266 ;
case V_267 :
return V_268 ;
case V_269 :
return V_270 ;
case V_271 :
return V_272 ;
case V_273 :
return V_274 ;
case V_275 :
return V_276 ;
default:
return V_277 ;
}
}
static int F_67 ( struct V_1 * V_2 ,
struct V_244 * V_245 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_242 * V_243 = & V_4 -> V_243 ;
struct V_278 * V_279 = & V_245 -> V_279 ;
T_1 V_280 ;
F_68 ( V_245 , V_218 ) ;
F_64 ( V_243 , V_245 ) ;
F_68 ( V_245 , V_246 ) ;
if ( V_243 -> V_247 ) {
F_61 ( V_243 , V_245 ) ;
F_65 ( V_245 ,
V_246 , V_257 ) ;
V_279 -> V_247 = V_281 ;
if ( V_243 -> V_282 == V_283 )
F_63 ( V_243 , V_245 ) ;
V_280 = F_66 ( V_243 -> V_284 ) ;
if ( ! F_69 ( V_2 ) )
V_279 -> V_285 = V_286 ;
else if ( V_243 -> V_285 & V_287 )
V_279 -> V_285 = V_288 ;
else
V_279 -> V_285 = V_289 ;
} else {
V_279 -> V_247 = V_290 ;
V_280 =
F_66 ( V_243 -> V_291 ) ;
V_279 -> V_285 = V_289 ;
if ( V_243 -> V_292 == V_287 )
V_279 -> V_285 = V_288 ;
}
V_279 -> V_293 = V_280 ;
V_279 -> V_294 = V_295 ;
if ( V_243 -> V_296 == V_297 ) {
V_279 -> V_294 = V_298 ;
F_65 ( V_245 , V_218 ,
V_299 ) ;
F_65 ( V_245 , V_246 ,
V_299 ) ;
} else {
F_65 ( V_245 , V_218 ,
V_300 ) ;
F_65 ( V_245 , V_246 ,
V_300 ) ;
if ( V_243 -> V_296 == V_301 )
V_279 -> V_294 = V_302 ;
else if ( V_243 -> V_296 ==
V_303 )
V_279 -> V_294 = V_304 ;
}
V_279 -> V_305 = V_243 -> V_306 ;
return 0 ;
}
static T_1 F_70 ( struct V_1 * V_2 , T_1 V_280 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_242 * V_243 = & V_4 -> V_243 ;
T_5 V_307 = V_243 -> V_253 ;
T_1 V_308 = 0 ;
switch ( V_280 ) {
case V_260 :
if ( V_307 & V_227 )
V_308 = V_309 ;
break;
case V_262 :
if ( V_307 & V_229 )
V_308 = V_310 ;
break;
case V_264 :
if ( V_307 & V_231 )
V_308 = V_311 ;
break;
case V_266 :
if ( V_307 & V_233 )
V_308 = V_312 ;
break;
case V_268 :
if ( V_307 & V_313 )
V_308 = V_314 ;
break;
case V_270 :
if ( V_307 & V_315 )
V_308 = V_316 ;
break;
case V_272 :
if ( V_307 & V_235 )
V_308 = V_317 ;
break;
case V_274 :
if ( V_307 & V_318 )
V_308 = V_319 ;
break;
case V_276 :
if ( V_307 & V_320 )
V_308 = V_321 ;
break;
default:
F_16 ( V_2 , L_27 ) ;
break;
}
return V_308 ;
}
T_5 F_71 ( T_1 V_246 )
{
T_5 V_322 = 0 ;
if ( V_246 & ( V_228 |
V_323 ) ) {
V_322 |= V_227 ;
}
if ( V_246 & ( V_230 |
V_324 ) ) {
V_322 |= V_229 ;
}
if ( V_246 & V_234 )
V_322 |= V_233 ;
if ( V_246 & V_236 )
V_322 |= V_235 ;
return V_322 ;
}
static int F_72 ( struct V_1 * V_2 ,
const struct V_244 * V_245 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_242 * V_243 = & V_4 -> V_243 ;
const struct V_278 * V_279 = & V_245 -> V_279 ;
bool V_325 = false ;
T_5 V_326 = 0 ;
T_1 V_293 ;
int V_28 = 0 ;
if ( ! F_73 ( V_4 ) )
return - V_42 ;
if ( V_279 -> V_247 == V_281 ) {
F_74 ( V_326 , V_245 ,
V_246 ) ;
V_243 -> V_247 |= V_327 ;
if ( ! V_326 )
V_243 -> V_246 = V_243 -> V_256 ;
else
V_243 -> V_246 = V_326 ;
V_325 = true ;
} else {
T_5 V_308 ;
T_4 V_328 = V_243 -> V_328 ;
if ( V_328 == V_329 ||
V_328 == V_330 ||
V_243 -> V_296 == V_297 ) {
F_16 ( V_2 , L_28 ) ;
V_28 = - V_81 ;
goto V_331;
}
if ( V_279 -> V_285 == V_289 ) {
F_16 ( V_2 , L_29 ) ;
V_28 = - V_81 ;
goto V_331;
}
V_293 = V_279 -> V_293 ;
V_308 = F_70 ( V_2 , V_293 ) ;
if ( ! V_308 ) {
V_28 = - V_81 ;
goto V_331;
}
V_243 -> V_291 = V_308 ;
V_243 -> V_292 = V_287 ;
V_243 -> V_247 = 0 ;
V_243 -> V_246 = 0 ;
}
if ( F_8 ( V_2 ) )
V_28 = F_75 ( V_4 , V_325 , false ) ;
V_331:
return V_28 ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_332 * V_333 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_242 * V_243 = & V_4 -> V_243 ;
if ( F_77 ( V_4 ) )
return;
V_333 -> V_247 = ! ! ( V_243 -> V_247 & V_248 ) ;
V_333 -> V_334 = ! ! ( V_243 -> V_335 & V_241 ) ;
V_333 -> V_336 = ! ! ( V_243 -> V_335 & V_239 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_332 * V_333 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_242 * V_243 = & V_4 -> V_243 ;
if ( ! F_73 ( V_4 ) )
return - V_42 ;
if ( V_333 -> V_247 ) {
if ( ! ( V_243 -> V_247 & V_327 ) )
return - V_81 ;
V_243 -> V_247 |= V_248 ;
if ( V_4 -> V_337 >= 0x10201 )
V_243 -> V_335 =
V_338 ;
} else {
if ( V_243 -> V_247 & V_248 )
V_243 -> V_339 = true ;
V_243 -> V_247 &= ~ V_248 ;
V_243 -> V_335 = 0 ;
}
if ( V_333 -> V_334 )
V_243 -> V_335 |= V_241 ;
if ( V_333 -> V_336 )
V_243 -> V_335 |= V_239 ;
if ( F_8 ( V_2 ) )
V_28 = F_79 ( V_4 ) ;
return V_28 ;
}
static T_1 F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_243 . V_340 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_5 V_341 ,
T_5 V_342 ,
T_5 V_343 ,
T_5 V_344 ,
const T_4 * V_108 ,
T_6 V_345 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_346 V_347 = { 0 } ;
T_7 V_348 ;
T_4 * V_349 ;
F_82 ( V_4 , & V_347 , V_350 , - 1 , - 1 ) ;
V_347 . V_341 = F_83 ( V_341 ) ;
V_347 . V_342 = F_83 ( V_342 ) ;
V_347 . V_343 = F_83 ( V_343 ) ;
V_347 . V_344 = F_83 ( V_344 ) ;
V_347 . V_351 = F_84 ( V_345 ) ;
V_349 = F_85 ( & V_4 -> V_211 -> V_2 , V_345 , & V_348 ,
V_203 ) ;
if ( ! V_349 ) {
F_16 ( V_2 , L_30 ,
( unsigned ) V_345 ) ;
return - V_352 ;
}
memcpy ( V_349 , V_108 , V_345 ) ;
V_347 . V_353 = F_86 ( V_348 ) ;
V_28 = F_87 ( V_4 , & V_347 , sizeof( V_347 ) , V_354 ) ;
F_88 ( & V_4 -> V_211 -> V_2 , V_345 , V_349 , V_348 ) ;
return V_28 ;
}
static int F_89 ( struct V_1 * V_2 ,
T_5 V_341 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_355 V_347 = { 0 } ;
F_82 ( V_4 , & V_347 , V_356 , - 1 , - 1 ) ;
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
return - V_81 ;
}
return F_87 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
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
F_16 ( V_2 , L_31 ,
V_341 ) ;
return - V_81 ;
}
if ( V_375 < sizeof( struct V_379 ) ) {
F_16 ( V_2 , L_32 ,
( unsigned int ) V_375 ) ;
return - V_81 ;
}
if ( V_380 -> V_389 != F_84 ( V_390 ) ) {
F_16 ( V_2 , L_33 ,
F_91 ( V_380 -> V_389 ) ) ;
return - V_81 ;
}
if ( V_380 -> V_376 != V_376 ) {
F_16 ( V_2 , L_34 ,
V_376 , V_380 -> V_376 ) ;
return - V_81 ;
}
if ( V_380 -> V_391 != V_392 ) {
F_16 ( V_2 , L_35 ,
V_392 , V_380 -> V_391 ) ;
return - V_81 ;
}
V_377 = F_91 ( * ( V_393 * ) ( V_374 + V_375 -
sizeof( V_377 ) ) ) ;
V_378 = ~ F_92 ( ~ 0 , V_374 , V_375 - sizeof( V_377 ) ) ;
if ( V_378 != V_377 ) {
F_16 ( V_2 , L_36 ,
( unsigned long ) V_377 ,
( unsigned long ) V_378 ) ;
return - V_81 ;
}
V_28 = F_81 ( V_2 , V_341 , V_394 ,
0 , 0 , V_374 , V_375 ) ;
if ( V_28 == 0 )
V_28 = F_89 ( V_2 , V_341 ) ;
return V_28 ;
}
static int F_93 ( struct V_1 * V_2 ,
T_5 V_341 ,
const T_4 * V_374 ,
T_6 V_375 )
{
struct V_395 * V_396 ;
T_1 V_378 ;
T_1 V_377 ;
int V_28 = 0 ;
if ( V_375 < sizeof( struct V_395 ) ) {
F_16 ( V_2 , L_37 ,
( unsigned int ) V_375 ) ;
return - V_81 ;
}
V_396 = (struct V_395 * ) ( V_374 + ( V_375 -
sizeof( * V_396 ) ) ) ;
if ( V_396 -> V_397 != F_84 ( V_398 ) ) {
F_16 ( V_2 , L_38 ,
F_91 ( V_396 -> V_397 ) ) ;
return - V_81 ;
}
if ( F_49 ( V_396 -> V_341 ) != V_341 ) {
F_16 ( V_2 , L_39 ,
V_341 , F_49 ( V_396 -> V_341 ) ) ;
return - V_81 ;
}
if ( F_49 ( V_396 -> V_399 ) <
sizeof( struct V_395 ) ) {
F_16 ( V_2 , L_40 ,
F_49 ( V_396 -> V_399 ) ) ;
return - V_81 ;
}
V_377 = F_91 ( * ( V_393 * ) ( V_374 + V_375 -
sizeof( V_377 ) ) ) ;
V_378 = ~ F_92 ( ~ 0 , V_374 , V_375 - sizeof( V_377 ) ) ;
if ( V_378 != V_377 ) {
F_16 ( V_2 ,
L_41 ,
( unsigned long ) V_377 ,
( unsigned long ) V_378 ) ;
return - V_81 ;
}
V_28 = F_81 ( V_2 , V_341 , V_394 ,
0 , 0 , V_374 , V_375 ) ;
return V_28 ;
}
static bool F_94 ( T_5 V_341 )
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
static bool F_95 ( T_5 V_341 )
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
static bool F_96 ( T_5 V_341 )
{
return F_94 ( V_341 ) ||
F_95 ( V_341 ) ;
}
static int F_97 ( struct V_1 * V_2 ,
T_5 V_341 ,
const char * V_409 )
{
const struct V_410 * V_411 ;
int V_28 ;
V_28 = F_98 ( & V_411 , V_409 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_16 ( V_2 , L_42 ,
V_28 , V_409 ) ;
return V_28 ;
}
if ( F_94 ( V_341 ) == true )
V_28 = F_90 ( V_2 , V_341 , V_411 -> V_108 , V_411 -> V_412 ) ;
else if ( F_95 ( V_341 ) == true )
V_28 = F_93 ( V_2 , V_341 , V_411 -> V_108 , V_411 -> V_412 ) ;
else
V_28 = F_81 ( V_2 , V_341 , V_394 ,
0 , 0 , V_411 -> V_108 , V_411 -> V_412 ) ;
F_99 ( V_411 ) ;
return V_28 ;
}
static int F_100 ( struct V_1 * V_2 ,
char * V_409 , T_1 V_413 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_414 * V_415 = V_4 -> V_416 ;
struct V_417 V_418 = { 0 } ;
const struct V_410 * V_411 ;
T_1 V_419 ;
T_5 V_420 ;
int V_28 ;
F_101 ( V_4 ) ;
if ( F_102 ( V_2 , V_421 ,
V_394 , V_422 ,
& V_420 , & V_419 , NULL ) != 0 ) {
F_16 ( V_2 , L_43 ) ;
return - V_423 ;
}
V_28 = F_98 ( & V_411 , V_409 , & V_2 -> V_2 ) ;
if ( V_28 != 0 ) {
F_16 ( V_2 , L_44 ,
V_28 , V_409 ) ;
return V_28 ;
}
if ( V_411 -> V_412 > V_419 ) {
F_16 ( V_2 , L_45 ,
( unsigned long ) V_411 -> V_412 ) ;
V_28 = - V_424 ;
} else {
T_7 V_348 ;
T_4 * V_349 ;
struct V_425 V_426 = { 0 } ;
F_82 ( V_4 , & V_426 , V_427 , - 1 , - 1 ) ;
V_426 . V_428 = F_83 ( V_420 ) ;
V_426 . V_429 = F_84 ( V_411 -> V_412 ) ;
V_349 = F_85 ( & V_4 -> V_211 -> V_2 , V_411 -> V_412 ,
& V_348 , V_203 ) ;
if ( ! V_349 ) {
F_16 ( V_2 ,
L_30 ,
( unsigned int ) V_411 -> V_412 ) ;
V_28 = - V_352 ;
} else {
memcpy ( V_349 , V_411 -> V_108 , V_411 -> V_412 ) ;
V_426 . V_353 = F_86 ( V_348 ) ;
V_28 = F_87 ( V_4 , & V_426 , sizeof( V_426 ) ,
V_430 ) ;
F_88 ( & V_4 -> V_211 -> V_2 , V_411 -> V_412 , V_349 ,
V_348 ) ;
}
}
F_99 ( V_411 ) ;
if ( V_28 )
return V_28 ;
if ( ( V_413 & 0xffff ) == 0 )
V_413 >>= 16 ;
F_82 ( V_4 , & V_418 , V_431 , - 1 , - 1 ) ;
V_418 . V_413 = F_84 ( V_413 ) ;
F_103 ( & V_4 -> V_432 ) ;
V_28 = F_104 ( V_4 , & V_418 , sizeof( V_418 ) ,
V_433 ) ;
if ( V_28 ) {
V_28 = - V_42 ;
goto V_434;
}
if ( V_415 -> V_435 ) {
T_4 V_435 = ( (struct V_436 * ) V_415 ) -> V_437 ;
if ( V_435 == V_438 ) {
V_418 . V_37 |= F_83 (
V_439 ) ;
V_28 = F_104 ( V_4 , & V_418 , sizeof( V_418 ) ,
V_433 ) ;
if ( V_28 ) {
V_28 = - V_42 ;
goto V_434;
}
}
}
if ( V_415 -> V_440 ) {
F_16 ( V_2 , L_46 ,
( V_441 ) V_415 -> V_440 , ( int ) V_415 -> V_442 ) ;
V_28 = - V_443 ;
}
V_434:
F_105 ( & V_4 -> V_432 ) ;
return V_28 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_444 * V_445 )
{
if ( ! F_28 ( (struct V_3 * ) F_2 ( V_2 ) ) ) {
F_16 ( V_2 , L_47 ) ;
return - V_81 ;
}
if ( V_445 -> V_446 == V_447 ||
V_445 -> V_446 > 0xffff )
return F_100 ( V_2 , V_445 -> V_108 ,
V_445 -> V_446 ) ;
return F_97 ( V_2 , V_445 -> V_446 , V_445 -> V_108 ) ;
}
static int F_107 ( struct V_1 * V_2 , T_1 * V_448 , T_1 * V_449 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_450 V_347 = { 0 } ;
struct V_451 * V_452 = V_4 -> V_416 ;
F_82 ( V_4 , & V_347 , V_453 , - 1 , - 1 ) ;
F_103 ( & V_4 -> V_432 ) ;
V_28 = F_104 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( ! V_28 ) {
* V_448 = F_91 ( V_452 -> V_448 ) ;
* V_449 = F_91 ( V_452 -> V_454 ) ;
}
F_105 ( & V_4 -> V_432 ) ;
return V_28 ;
}
static int F_108 ( struct V_1 * V_2 )
{
return - 1 ;
}
static int F_109 ( struct V_1 * V_2 , T_1 V_429 , T_4 * V_108 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_1 V_455 ;
T_1 V_454 ;
T_4 * V_45 ;
T_6 V_456 ;
T_7 V_348 ;
struct V_457 V_347 = { 0 } ;
V_28 = F_107 ( V_2 , & V_455 , & V_454 ) ;
if ( V_28 != 0 )
return V_28 ;
if ( V_429 < 2 )
return - V_81 ;
* V_108 ++ = V_455 ;
* V_108 ++ = V_454 ;
V_429 -= 2 ;
memset ( V_108 , 0xff , V_429 ) ;
V_456 = V_455 * V_454 ;
V_45 = F_85 ( & V_4 -> V_211 -> V_2 , V_456 , & V_348 ,
V_203 ) ;
if ( ! V_45 ) {
F_16 ( V_2 , L_30 ,
( unsigned ) V_456 ) ;
return - V_352 ;
}
F_82 ( V_4 , & V_347 , V_458 , - 1 , - 1 ) ;
V_347 . V_459 = F_86 ( V_348 ) ;
V_28 = F_87 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 == 0 )
memcpy ( V_108 , V_45 , V_429 > V_456 ? V_456 : V_429 ) ;
F_88 ( & V_4 -> V_211 -> V_2 , V_456 , V_45 , V_348 ) ;
return V_28 ;
}
static int F_110 ( struct V_1 * V_2 , T_1 V_420 , T_1 V_62 ,
T_1 V_449 , T_4 * V_108 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
T_4 * V_45 ;
T_7 V_348 ;
struct V_460 V_347 = { 0 } ;
V_45 = F_85 ( & V_4 -> V_211 -> V_2 , V_449 , & V_348 ,
V_203 ) ;
if ( ! V_45 ) {
F_16 ( V_2 , L_30 ,
( unsigned ) V_449 ) ;
return - V_352 ;
}
F_82 ( V_4 , & V_347 , V_461 , - 1 , - 1 ) ;
V_347 . V_459 = F_86 ( V_348 ) ;
V_347 . V_428 = F_83 ( V_420 ) ;
V_347 . V_62 = F_84 ( V_62 ) ;
V_347 . V_429 = F_84 ( V_449 ) ;
V_28 = F_87 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 == 0 )
memcpy ( V_108 , V_45 , V_449 ) ;
F_88 ( & V_4 -> V_211 -> V_2 , V_449 , V_45 , V_348 ) ;
return V_28 ;
}
static int F_102 ( struct V_1 * V_2 , T_5 type , T_5 V_462 ,
T_5 V_463 , T_5 * V_420 , T_1 * V_464 ,
T_1 * V_465 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
struct V_466 V_347 = { 0 } ;
struct V_467 * V_452 = V_4 -> V_416 ;
F_82 ( V_4 , & V_347 , V_468 , - 1 , - 1 ) ;
V_347 . V_469 = 0 ;
V_347 . V_428 = 0 ;
V_347 . V_341 = F_83 ( type ) ;
V_347 . V_342 = F_83 ( V_462 ) ;
V_347 . V_343 = F_83 ( V_463 ) ;
V_347 . V_470 = V_471 ;
V_28 = F_111 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 == 0 ) {
if ( V_420 )
* V_420 = F_49 ( V_452 -> V_428 ) ;
if ( V_464 )
* V_464 = F_91 ( V_452 -> V_472 ) ;
if ( V_465 )
* V_465 = F_91 ( V_452 -> V_351 ) ;
}
return V_28 ;
}
static char * F_112 ( int V_473 , T_4 * V_108 , T_6 V_474 )
{
char * V_475 = NULL ;
char * V_476 ;
char * V_6 ;
int V_477 = 0 ;
if ( V_474 < 1 )
return NULL ;
V_108 [ V_474 - 1 ] = 0 ;
for ( V_476 = V_108 ; * V_476 != 0 ; V_476 ++ ) {
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
static char * F_52 ( struct V_1 * V_2 , char * V_45 , T_6 V_456 )
{
T_5 V_420 = 0 ;
T_1 V_474 ;
if ( F_102 ( V_2 , V_478 ,
V_394 , V_422 ,
& V_420 , NULL , & V_474 ) != 0 )
return NULL ;
memset ( V_45 , 0 , V_456 ) ;
if ( F_110 ( V_2 , V_420 , 0 , V_474 , V_45 ) != 0 )
return NULL ;
return F_112 ( V_479 , V_45 ,
V_474 ) ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_480 * V_481 ,
T_4 * V_108 )
{
T_1 V_420 ;
T_1 V_62 ;
if ( V_481 -> V_62 == 0 )
return F_109 ( V_2 , V_481 -> V_429 , V_108 ) ;
V_420 = V_481 -> V_62 >> 24 ;
V_62 = V_481 -> V_62 & 0xffffff ;
if ( V_420 == 0 ) {
F_16 ( V_2 , L_48 , V_420 ) ;
return - V_81 ;
}
return F_110 ( V_2 , V_420 - 1 , V_62 , V_481 -> V_429 , V_108 ) ;
}
static int F_114 ( struct V_1 * V_2 , T_4 V_420 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_482 V_347 = { 0 } ;
F_82 ( V_4 , & V_347 , V_483 , - 1 , - 1 ) ;
V_347 . V_428 = F_83 ( V_420 ) ;
return F_87 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_480 * V_481 ,
T_4 * V_108 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_420 , V_484 ;
T_5 type , V_463 , V_462 , V_485 ;
if ( ! F_28 ( V_4 ) ) {
F_16 ( V_2 , L_49 ) ;
return - V_81 ;
}
type = V_481 -> V_486 >> 16 ;
if ( type == 0xffff ) {
V_420 = V_481 -> V_486 & 0xff ;
V_484 = V_481 -> V_486 >> 8 ;
if ( V_420 == 0 )
return - V_81 ;
switch ( V_484 ) {
case 0x0e :
if ( V_481 -> V_62 != ~ V_481 -> V_486 )
return - V_81 ;
return F_114 ( V_2 , V_420 - 1 ) ;
default:
return - V_81 ;
}
}
if ( F_96 ( type ) == true )
return - V_42 ;
V_463 = V_481 -> V_486 & 0xffff ;
V_462 = V_481 -> V_62 >> 16 ;
V_485 = V_481 -> V_62 & 0xffff ;
return F_81 ( V_2 , type , V_462 , V_463 , V_485 , V_108 ,
V_481 -> V_429 ) ;
}
static int F_116 ( struct V_1 * V_2 , struct V_487 * V_488 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_487 * V_489 = & V_4 -> V_489 ;
struct V_242 * V_243 = & V_4 -> V_243 ;
T_1 V_246 =
F_60 ( V_243 -> V_246 , 0 ) ;
int V_28 = 0 ;
if ( ! F_73 ( V_4 ) )
return - V_42 ;
if ( ! ( V_4 -> V_37 & V_490 ) )
return - V_42 ;
if ( ! V_488 -> V_491 )
goto V_492;
if ( ! ( V_243 -> V_247 & V_327 ) ) {
F_27 ( V_2 , L_50 ) ;
return - V_81 ;
}
if ( V_488 -> V_493 ) {
if ( V_4 -> V_494 && ( V_488 -> V_495 > V_4 -> V_494 ||
V_488 -> V_495 < V_4 -> V_496 ) ) {
F_27 ( V_2 , L_51 ,
V_4 -> V_496 , V_4 -> V_494 ) ;
return - V_81 ;
} else if ( ! V_4 -> V_494 ) {
V_488 -> V_495 = V_489 -> V_495 ;
}
}
if ( ! V_488 -> V_497 ) {
V_488 -> V_497 = V_246 & V_489 -> V_218 ;
} else if ( V_488 -> V_497 & ~ V_246 ) {
F_27 ( V_2 , L_52 ,
V_488 -> V_497 , V_246 ) ;
return - V_81 ;
}
V_489 -> V_497 = V_488 -> V_497 ;
V_489 -> V_493 = V_488 -> V_493 ;
V_489 -> V_495 = V_488 -> V_495 ;
V_492:
V_489 -> V_491 = V_488 -> V_491 ;
if ( F_8 ( V_2 ) )
V_28 = F_75 ( V_4 , false , true ) ;
return V_28 ;
}
static int F_117 ( struct V_1 * V_2 , struct V_487 * V_488 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_4 -> V_37 & V_490 ) )
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
static int F_118 ( struct V_3 * V_4 , T_5 V_500 ,
T_5 V_501 , T_5 V_502 ,
T_5 V_465 , T_4 * V_45 )
{
struct V_503 V_347 = { 0 } ;
struct V_504 * V_452 = V_4 -> V_416 ;
int V_28 , V_505 = 0 ;
F_82 ( V_4 , & V_347 , V_506 , - 1 , - 1 ) ;
V_347 . V_507 = V_500 ;
V_347 . V_501 = F_83 ( V_501 ) ;
V_347 . V_508 = F_83 ( V_4 -> V_509 . V_508 ) ;
do {
T_5 V_510 ;
V_510 = F_22 ( T_5 , V_465 , V_511 ) ;
V_465 -= V_510 ;
V_347 . V_512 = F_83 ( V_502 + V_505 ) ;
V_347 . V_465 = V_510 ;
V_347 . V_469 = F_84 ( V_502 + V_505 ?
V_513 : 0 ) ;
F_103 ( & V_4 -> V_432 ) ;
V_28 = F_104 ( V_4 , & V_347 , sizeof( V_347 ) ,
V_373 ) ;
if ( ! V_28 )
memcpy ( V_45 + V_505 , V_452 -> V_108 , V_510 ) ;
F_105 ( & V_4 -> V_432 ) ;
V_505 += V_510 ;
} while ( ! V_28 && V_465 > 0 );
return V_28 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_514 * V_515 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_503 V_347 = { 0 } ;
struct V_504 * V_452 = V_4 -> V_416 ;
int V_28 ;
if ( V_4 -> V_243 . V_516 >
V_517 )
return - V_42 ;
if ( V_4 -> V_337 < 0x10202 )
return - V_42 ;
F_82 ( V_4 , & V_347 , V_506 , - 1 , - 1 ) ;
V_347 . V_507 = V_518 ;
V_347 . V_501 = 0 ;
V_347 . V_512 = F_83 ( V_519 ) ;
V_347 . V_465 = V_520 ;
V_347 . V_508 = F_83 ( V_4 -> V_509 . V_508 ) ;
F_103 ( & V_4 -> V_432 ) ;
V_28 = F_104 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( ! V_28 ) {
T_1 V_521 = F_91 ( V_452 -> V_108 [ 0 ] ) ;
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
F_105 ( & V_4 -> V_432 ) ;
return V_28 ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_480 * V_481 ,
T_4 * V_108 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_5 V_533 = V_481 -> V_62 , V_449 = V_481 -> V_429 ;
int V_28 = 0 ;
memset ( V_108 , 0 , V_481 -> V_429 ) ;
if ( V_533 < V_529 ) {
if ( V_533 + V_481 -> V_429 > V_529 )
V_449 = V_529 - V_533 ;
V_28 = F_118 ( V_4 , V_518 , 0 ,
V_533 , V_449 , V_108 ) ;
if ( V_28 )
return V_28 ;
V_533 += V_449 ;
V_108 += V_449 ;
V_449 = V_481 -> V_429 - V_449 ;
}
if ( V_449 ) {
V_533 -= V_529 ;
F_118 ( V_4 , V_534 , 1 , V_533 ,
V_449 , V_108 ) ;
}
return V_28 ;
}
static int F_121 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_242 * V_243 = & V_4 -> V_243 ;
if ( ! F_73 ( V_4 ) )
return - V_42 ;
if ( ! ( V_243 -> V_247 & V_327 ) )
return - V_81 ;
if ( F_8 ( V_2 ) )
V_28 = F_75 ( V_4 , true , false ) ;
return V_28 ;
}
static int F_122 ( struct V_1 * V_2 ,
enum V_535 V_536 )
{
struct V_537 V_347 = { 0 } ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_538 * V_509 = & V_4 -> V_509 ;
struct V_539 * V_540 ;
T_4 V_541 ;
T_8 V_542 ;
int V_46 , V_28 ;
if ( ! V_4 -> V_543 || F_77 ( V_4 ) )
return - V_42 ;
if ( V_536 == V_544 ) {
V_541 = V_545 ;
V_542 = F_83 ( 500 ) ;
} else if ( V_536 == V_546 ) {
V_541 = V_547 ;
V_542 = F_83 ( 0 ) ;
} else {
return - V_81 ;
}
F_82 ( V_4 , & V_347 , V_548 , - 1 , - 1 ) ;
V_347 . V_508 = F_83 ( V_509 -> V_508 ) ;
V_347 . V_543 = V_4 -> V_543 ;
V_540 = (struct V_539 * ) & V_347 . V_549 ;
for ( V_46 = 0 ; V_46 < V_4 -> V_543 ; V_46 ++ , V_540 ++ ) {
V_347 . V_469 |= F_123 ( V_46 ) ;
V_540 -> V_550 = V_4 -> V_551 [ V_46 ] . V_550 ;
V_540 -> V_541 = V_541 ;
V_540 -> V_552 = V_542 ;
V_540 -> V_553 = V_542 ;
V_540 -> V_554 = V_4 -> V_551 [ V_46 ] . V_554 ;
}
V_28 = F_87 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 )
V_28 = - V_555 ;
return V_28 ;
}
static int F_124 ( struct V_3 * V_4 , T_5 V_556 )
{
struct V_557 V_347 = { 0 } ;
F_82 ( V_4 , & V_347 , V_558 , V_556 , - 1 ) ;
return F_87 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_125 ( struct V_3 * V_4 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_4 -> V_36 ; V_46 ++ ) {
T_5 V_556 = V_4 -> V_559 [ V_46 ] . V_560 ;
int V_28 ;
V_28 = F_124 ( V_4 , V_556 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static int F_126 ( struct V_3 * V_4 , bool V_561 )
{
struct V_562 V_347 = { 0 } ;
F_82 ( V_4 , & V_347 , V_563 , - 1 , - 1 ) ;
V_347 . V_469 = F_84 ( V_564 ) ;
if ( V_561 )
V_347 . V_565 = V_566 ;
else
V_347 . V_565 = V_567 ;
return F_87 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_127 ( struct V_3 * V_4 ,
struct V_568 * V_347 )
{
struct V_242 * V_243 = & V_4 -> V_243 ;
T_5 V_326 = V_243 -> V_246 ;
T_5 V_308 ;
int V_28 ;
if ( ! V_243 -> V_247 )
return 0 ;
V_308 = V_569 ;
if ( F_69 ( V_4 -> V_2 ) )
V_308 = V_4 -> V_243 . V_284 ;
else if ( V_326 & V_233 )
V_308 = V_570 ;
else if ( V_326 & V_315 )
V_308 = V_571 ;
else if ( V_326 & V_235 )
V_308 = V_572 ;
else if ( V_326 & V_318 )
V_308 = V_573 ;
V_347 -> V_574 = F_83 ( V_308 ) ;
V_347 -> V_37 |= F_84 ( V_575 |
V_576 ) ;
V_28 = F_87 ( V_4 , V_347 , sizeof( * V_347 ) , V_373 ) ;
V_347 -> V_37 = 0 ;
V_347 -> V_574 = F_83 ( 0 ) ;
return V_28 ;
}
static int F_128 ( struct V_3 * V_4 , bool V_561 )
{
struct V_568 V_347 = { 0 } ;
F_82 ( V_4 , & V_347 , V_577 , - 1 , - 1 ) ;
if ( V_561 ) {
F_127 ( V_4 , & V_347 ) ;
V_347 . V_565 = V_578 ;
} else {
V_347 . V_565 = V_579 ;
}
V_347 . V_469 = F_84 ( V_580 ) ;
return F_87 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
}
static int F_129 ( struct V_3 * V_4 , struct V_52 * V_51 ,
T_1 V_581 , int V_582 )
{
struct V_53 * V_54 = & V_51 -> V_55 ;
struct V_583 * V_584 = V_51 -> V_585 ;
struct V_586 * V_587 ;
struct V_588 * V_589 ;
T_5 V_590 , V_591 ;
T_4 * V_108 ;
T_1 V_429 ;
int V_46 ;
V_590 = F_130 ( V_581 ) ;
V_589 = (struct V_588 * )
& V_54 -> V_592 [ F_131 ( V_590 ) ] [ F_132 ( V_590 ) ] ;
V_591 = V_589 -> V_593 ;
V_587 = & V_584 -> V_594 [ V_591 ] ;
V_108 = V_587 -> V_595 ;
V_429 = F_91 ( V_589 -> V_596 ) >> V_597 ;
if ( V_429 != V_582 )
return - V_555 ;
V_46 = V_598 ;
if ( ! F_133 ( V_108 + V_46 , V_51 -> V_4 -> V_2 -> V_599 ) )
return - V_555 ;
V_46 += V_598 ;
for ( ; V_46 < V_582 ; V_46 ++ ) {
if ( V_108 [ V_46 ] != ( T_4 ) ( V_46 & 0xff ) )
return - V_555 ;
}
return 0 ;
}
static int F_134 ( struct V_3 * V_4 , int V_582 )
{
struct V_52 * V_51 = V_4 -> V_51 [ 0 ] ;
struct V_53 * V_54 ;
struct V_600 * V_601 ;
int V_28 = - V_555 ;
T_1 V_581 ;
T_1 V_591 ;
int V_46 ;
V_54 = & V_51 -> V_55 ;
V_581 = V_54 -> V_602 ;
for ( V_46 = 0 ; V_46 < 200 ; V_46 ++ ) {
V_591 = F_130 ( V_581 ) ;
V_601 = & V_54 -> V_592 [ F_131 ( V_591 ) ] [ F_132 ( V_591 ) ] ;
if ( ! F_135 ( V_601 , V_581 ) ) {
F_136 ( 5 ) ;
continue;
}
F_137 () ;
if ( F_138 ( V_601 ) == V_603 ) {
V_28 = F_129 ( V_4 , V_51 , V_581 , V_582 ) ;
V_581 = F_139 ( V_581 ) ;
V_581 = F_139 ( V_581 ) ;
break;
}
V_581 = F_139 ( V_581 ) ;
}
V_54 -> V_602 = V_581 ;
return V_28 ;
}
static int F_140 ( struct V_3 * V_4 )
{
struct V_604 * V_605 = & V_4 -> V_606 [ 0 ] ;
int V_582 , V_46 = 0 ;
struct V_607 * V_608 ;
T_7 V_609 ;
T_4 * V_108 ;
int V_28 ;
V_582 = F_141 ( V_4 -> V_2 -> V_610 + V_611 , V_4 -> V_612 ) ;
V_608 = F_142 ( V_4 -> V_2 , V_582 ) ;
if ( ! V_608 )
return - V_352 ;
V_108 = F_143 ( V_608 , V_582 ) ;
F_144 ( V_108 ) ;
V_46 += V_598 ;
F_145 ( & V_108 [ V_46 ] , V_4 -> V_2 -> V_599 ) ;
V_46 += V_598 ;
for ( ; V_46 < V_582 ; V_46 ++ )
V_108 [ V_46 ] = ( T_4 ) ( V_46 & 0xff ) ;
V_609 = F_146 ( & V_4 -> V_211 -> V_2 , V_608 -> V_108 , V_582 ,
V_613 ) ;
if ( F_147 ( & V_4 -> V_211 -> V_2 , V_609 ) ) {
F_148 ( V_608 ) ;
return - V_555 ;
}
F_149 ( V_4 , V_605 , V_609 , V_582 , 0 ) ;
F_150 () ;
F_151 ( V_614 | V_605 -> V_615 , V_605 -> V_616 ) ;
F_151 ( V_614 | V_605 -> V_615 , V_605 -> V_616 ) ;
V_28 = F_134 ( V_4 , V_582 ) ;
F_152 ( & V_4 -> V_211 -> V_2 , V_609 , V_582 , V_613 ) ;
F_148 ( V_608 ) ;
return V_28 ;
}
static int F_153 ( struct V_3 * V_4 , T_4 V_617 , T_4 * V_618 )
{
struct V_619 * V_415 = V_4 -> V_416 ;
struct V_620 V_347 = { 0 } ;
int V_28 ;
F_82 ( V_4 , & V_347 , V_621 , - 1 , - 1 ) ;
F_103 ( & V_4 -> V_432 ) ;
V_415 -> V_622 = 0 ;
V_347 . V_37 = V_617 ;
V_28 = F_104 ( V_4 , & V_347 , sizeof( V_347 ) , V_4 -> V_65 -> V_623 ) ;
* V_618 = V_415 -> V_622 ;
F_105 ( & V_4 -> V_432 ) ;
return V_28 ;
}
static void F_154 ( struct V_1 * V_2 , struct V_624 * V_625 ,
T_2 * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_626 = false ;
T_4 V_618 = 0 ;
T_4 V_617 = 0 ;
int V_28 , V_46 ;
if ( ! V_4 -> V_41 || ! F_73 ( V_4 ) )
return;
memset ( V_45 , 0 , sizeof( T_2 ) * V_4 -> V_41 ) ;
if ( ! F_8 ( V_2 ) ) {
V_625 -> V_37 |= V_627 ;
return;
}
if ( V_625 -> V_37 & V_628 ) {
if ( V_4 -> V_509 . V_629 ) {
V_625 -> V_37 |= V_627 ;
F_27 ( V_2 , L_53 ) ;
return;
}
V_626 = true ;
}
for ( V_46 = 0 ; V_46 < V_4 -> V_41 - V_630 ; V_46 ++ ) {
T_4 V_631 = 1 << V_46 ;
if ( ! ( V_4 -> V_65 -> V_632 & V_631 ) )
V_617 |= V_631 ;
else if ( V_626 )
V_617 |= V_631 ;
}
if ( ! V_626 ) {
F_153 ( V_4 , V_617 , & V_618 ) ;
} else {
V_28 = F_9 ( V_4 , false , false ) ;
if ( V_28 )
return;
F_153 ( V_4 , V_617 , & V_618 ) ;
V_45 [ V_633 ] = 1 ;
F_126 ( V_4 , true ) ;
F_155 ( 250 ) ;
V_28 = F_156 ( V_4 ) ;
if ( V_28 ) {
F_126 ( V_4 , false ) ;
V_625 -> V_37 |= V_627 ;
return;
}
if ( F_140 ( V_4 ) )
V_625 -> V_37 |= V_627 ;
else
V_45 [ V_633 ] = 0 ;
F_126 ( V_4 , false ) ;
F_128 ( V_4 , true ) ;
F_155 ( 1000 ) ;
if ( F_140 ( V_4 ) ) {
V_45 [ V_634 ] = 1 ;
V_625 -> V_37 |= V_627 ;
}
F_128 ( V_4 , false ) ;
F_157 ( V_4 ) ;
F_10 ( V_4 , false , true ) ;
}
if ( F_125 ( V_4 ) ) {
V_45 [ V_635 ] = 1 ;
V_625 -> V_37 |= V_627 ;
}
for ( V_46 = 0 ; V_46 < V_4 -> V_41 - V_630 ; V_46 ++ ) {
T_4 V_631 = 1 << V_46 ;
if ( ( V_617 & V_631 ) && ! ( V_618 & V_631 ) ) {
V_45 [ V_46 ] = 1 ;
V_625 -> V_37 |= V_627 ;
}
}
}
void F_158 ( struct V_3 * V_4 )
{
struct V_636 * V_415 = V_4 -> V_416 ;
struct V_637 V_347 = { 0 } ;
struct V_638 * V_65 ;
int V_46 , V_28 ;
if ( V_4 -> V_337 < 0x10704 || ! F_73 ( V_4 ) )
return;
F_82 ( V_4 , & V_347 , V_639 , - 1 , - 1 ) ;
F_103 ( & V_4 -> V_432 ) ;
V_28 = F_104 ( V_4 , & V_347 , sizeof( V_347 ) , V_373 ) ;
if ( V_28 )
goto V_640;
V_65 = F_159 ( sizeof( * V_4 -> V_65 ) , V_203 ) ;
if ( ! V_65 )
goto V_640;
V_4 -> V_65 = V_65 ;
V_4 -> V_41 = V_415 -> V_41 + V_630 ;
if ( V_4 -> V_41 > V_641 )
V_4 -> V_41 = V_641 ;
V_65 -> V_632 = V_415 -> V_642 ;
V_65 -> V_623 = F_49 ( V_415 -> V_643 ) ;
if ( ! V_65 -> V_623 )
V_65 -> V_623 = V_373 ;
for ( V_46 = 0 ; V_46 < V_4 -> V_41 ; V_46 ++ ) {
char * V_644 = V_65 -> string [ V_46 ] ;
char * V_645 = V_415 -> V_646 + V_46 * 32 ;
if ( V_46 == V_633 ) {
strcpy ( V_644 , L_54 ) ;
} else if ( V_46 == V_634 ) {
strcpy ( V_644 , L_55 ) ;
} else if ( V_46 == V_635 ) {
strcpy ( V_644 , L_56 ) ;
} else {
F_53 ( V_644 , V_645 , V_64 ) ;
strncat ( V_644 , L_57 , V_64 - strlen ( V_644 ) ) ;
if ( V_65 -> V_632 & ( 1 << V_46 ) )
strncat ( V_644 , L_58 ,
V_64 - strlen ( V_644 ) ) ;
else
strncat ( V_644 , L_59 ,
V_64 - strlen ( V_644 ) ) ;
}
}
V_640:
F_105 ( & V_4 -> V_432 ) ;
}
void F_160 ( struct V_3 * V_4 )
{
F_55 ( V_4 -> V_65 ) ;
V_4 -> V_65 = NULL ;
}
