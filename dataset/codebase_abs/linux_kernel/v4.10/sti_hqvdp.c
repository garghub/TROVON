static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
T_1 V_5 = V_2 -> V_6 ;
int V_7 ;
V_3 = F_2 ( V_2 -> V_8 + V_9 ) ;
V_4 = F_2 ( V_2 -> V_8 + V_10 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
if ( ( V_5 != V_3 ) && ( V_5 != V_4 ) )
return V_7 * sizeof( struct V_12 ) ;
V_5 += sizeof( struct V_12 ) ;
}
return - 1 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
V_3 = F_2 ( V_2 -> V_8 + V_9 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
if ( V_5 == V_3 )
return V_7 * sizeof( struct V_12 ) ;
V_5 += sizeof( struct V_12 ) ;
}
return - 1 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
V_4 = F_2 ( V_2 -> V_8 + V_10 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
if ( V_5 == V_4 )
return V_7 * sizeof( struct V_12 ) ;
V_5 += sizeof( struct V_12 ) ;
}
return - 1 ;
}
static const char * F_5 ( T_1 * V_13 )
{
if ( ! memcmp ( V_13 , V_14 , 16 ) )
return L_1 ;
if ( ! memcmp ( V_13 , V_15 , 16 ) )
return L_2 ;
if ( ! memcmp ( V_13 , V_16 , 16 ) )
return L_3 ;
if ( ! memcmp ( V_13 , V_17 , 16 ) )
return L_4 ;
if ( ! memcmp ( V_13 , V_18 , 16 ) )
return L_5 ;
if ( ! memcmp ( V_13 , V_19 , 16 ) )
return L_6 ;
if ( ! memcmp ( V_13 , V_20 , 16 ) )
return L_7 ;
if ( ! memcmp ( V_13 , V_21 , 16 ) )
return L_8 ;
if ( ! memcmp ( V_13 , V_22 , 16 ) )
return L_9 ;
if ( ! memcmp ( V_13 , V_23 , 16 ) )
return L_10 ;
return L_11 ;
}
static void F_6 ( struct V_24 * V_25 , struct V_12 * V_26 )
{
int V_27 , V_28 , V_29 , V_30 ;
F_7 ( V_25 , L_12 ) ;
F_8 ( V_25 , L_13 , L_14 , V_26 -> V_31 . V_32 ) ;
switch ( V_26 -> V_31 . V_32 ) {
case V_33 :
F_7 ( V_25 , L_15 ) ;
break;
case V_34 :
F_7 ( V_25 , L_16 ) ;
break;
case V_35 :
F_7 ( V_25 , L_17 ) ;
break;
default:
F_7 ( V_25 , L_18 ) ;
break;
}
F_8 ( V_25 , L_13 , L_19 , V_26 -> V_31 . V_36 ) ;
F_8 ( V_25 , L_13 , L_20 , V_26 -> V_31 . V_37 ) ;
F_8 ( V_25 , L_13 , L_21 , V_26 -> V_31 . V_38 ) ;
F_8 ( V_25 , L_13 , L_22 , V_26 -> V_31 . V_39 ) ;
F_8 ( V_25 , L_13 , L_23 ,
V_26 -> V_31 . V_40 ) ;
F_8 ( V_25 , L_13 , L_24 ,
V_26 -> V_31 . V_41 ) ;
F_8 ( V_25 , L_25 ,
V_26 -> V_31 . V_41 & 0x0000FFFF ,
V_26 -> V_31 . V_41 >> 16 ) ;
F_8 ( V_25 , L_13 , L_26 ,
V_26 -> V_31 . V_42 ) ;
V_27 = V_26 -> V_31 . V_42 & 0x0000FFFF ;
V_28 = V_26 -> V_31 . V_42 >> 16 ;
F_8 ( V_25 , L_25 , V_27 , V_28 ) ;
F_7 ( V_25 , L_27 ) ;
F_8 ( V_25 , L_13 , L_28 ,
V_26 -> V_43 . V_44 ) ;
V_29 = V_26 -> V_43 . V_44 & 0x0000FFFF ;
V_30 = V_26 -> V_43 . V_44 >> 16 ;
F_8 ( V_25 , L_25 , V_29 , V_30 ) ;
F_8 ( V_25 , L_13 , L_29 , V_26 -> V_43 . V_45 ) ;
F_8 ( V_25 , L_30 , L_31 ,
F_5 ( V_26 -> V_43 . V_46 ) ) ;
F_8 ( V_25 , L_30 , L_32 ,
F_5 ( V_26 -> V_43 . V_47 ) ) ;
F_8 ( V_25 , L_30 , L_33 ,
F_5 ( V_26 -> V_43 . V_48 ) ) ;
F_8 ( V_25 , L_30 , L_34 ,
F_5 ( V_26 -> V_43 . V_49 ) ) ;
F_8 ( V_25 , L_35 , L_36 ) ;
if ( V_29 > V_27 )
F_8 ( V_25 , L_37 , V_29 / V_27 ) ;
else
F_8 ( V_25 , L_38 , V_27 / V_29 ) ;
F_8 ( V_25 , L_35 , L_39 ) ;
if ( V_30 > V_28 )
F_8 ( V_25 , L_37 , V_30 / V_28 ) ;
else
F_8 ( V_25 , L_38 , V_28 / V_30 ) ;
F_7 ( V_25 , L_40 ) ;
F_8 ( V_25 , L_41 , L_14 , V_26 -> V_50 . V_32 ) ;
switch ( V_26 -> V_50 . V_32 ) {
case V_51 :
F_7 ( V_25 , L_42 ) ;
break;
case V_52 :
F_7 ( V_25 , L_43 ) ;
break;
default:
F_7 ( V_25 , L_11 ) ;
break;
}
F_8 ( V_25 , L_13 , L_44 , V_26 -> V_50 . V_53 ) ;
F_8 ( V_25 , L_13 , L_45 , V_26 -> V_50 . V_54 ) ;
}
static int F_9 ( struct V_24 * V_25 , void * V_55 )
{
struct V_56 * V_57 = V_25 -> V_58 ;
struct V_1 * V_2 = (struct V_1 * ) V_57 -> V_59 -> V_55 ;
int V_5 , V_60 , V_61 ;
void * V_62 ;
F_8 ( V_25 , L_46 ,
F_10 ( & V_2 -> V_63 ) , V_2 -> V_8 ) ;
F_11 ( V_64 ) ;
F_11 ( V_65 ) ;
F_11 ( V_66 ) ;
F_11 ( V_67 ) ;
V_61 = F_2 ( V_2 -> V_8 + V_67 ) ;
F_7 ( V_25 , L_47 ) ;
if ( V_61 & V_68 )
F_7 ( V_25 , L_48 ) ;
else if ( V_61 & V_69 )
F_7 ( V_25 , L_49 ) ;
else if ( V_61 & V_70 )
F_7 ( V_25 , L_50 ) ;
else
F_7 ( V_25 , L_51 ) ;
F_11 ( V_71 ) ;
F_11 ( V_72 ) ;
if ( F_2 ( V_2 -> V_8 + V_72 )
& V_73 )
F_7 ( V_25 , L_52 ) ;
else
F_7 ( V_25 , L_53 ) ;
F_11 ( V_74 ) ;
if ( F_2 ( V_2 -> V_8 + V_74 )
& V_75 )
F_7 ( V_25 , L_54 ) ;
else
F_7 ( V_25 , L_55 ) ;
F_11 ( V_76 ) ;
F_11 ( V_10 ) ;
F_11 ( V_9 ) ;
F_11 ( V_77 ) ;
if ( ! ( F_2 ( V_2 -> V_8 + V_77 ) & 3 ) )
F_7 ( V_25 , L_56 ) ;
else
F_7 ( V_25 , L_57 ) ;
V_5 = F_2 ( V_2 -> V_8 + V_9 ) ;
V_60 = F_3 ( V_2 ) ;
if ( V_60 == - 1 ) {
F_7 ( V_25 , L_58 ) ;
} else {
V_62 = V_2 -> V_78 + V_60 ;
F_8 ( V_25 , L_59 ,
V_5 , V_62 ) ;
F_6 ( V_25 , (struct V_12 * ) V_62 ) ;
}
V_5 = F_2 ( V_2 -> V_8 + V_10 ) ;
V_60 = F_4 ( V_2 ) ;
if ( V_60 == - 1 ) {
F_7 ( V_25 , L_60 ) ;
} else {
V_62 = V_2 -> V_78 + V_60 ;
F_8 ( V_25 , L_61 ,
V_5 , V_62 ) ;
F_6 ( V_25 , (struct V_12 * ) V_62 ) ;
}
F_7 ( V_25 , L_62 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < F_13 ( V_81 ) ; V_7 ++ )
V_81 [ V_7 ] . V_55 = V_2 ;
return F_14 ( V_81 ,
F_13 ( V_81 ) ,
V_80 -> V_82 , V_80 ) ;
}
static void F_15 ( enum V_83 V_84 , int V_85 ,
struct V_86 * V_43 )
{
const int * V_87 , * V_88 ;
int V_89 , V_90 ;
if ( V_85 < V_91 ) {
V_88 = V_22 ;
V_87 = V_23 ;
V_90 = V_92 ;
V_89 = V_93 ;
} else if ( V_85 < V_94 ) {
V_88 = V_20 ;
V_87 = V_21 ;
V_90 = V_95 ;
V_89 = V_96 ;
} else if ( V_85 < V_97 ) {
V_88 = V_18 ;
V_87 = V_19 ;
V_90 = V_98 ;
V_89 = V_99 ;
} else if ( V_85 < V_100 ) {
V_88 = V_16 ;
V_87 = V_17 ;
V_90 = V_101 ;
V_89 = V_102 ;
} else if ( V_85 == V_100 ) {
V_88 = V_87 = V_15 ;
V_90 = V_89 = V_103 ;
} else {
V_88 = V_87 = V_14 ;
V_90 = V_89 = V_104 ;
}
if ( V_84 == V_105 ) {
V_43 -> V_106 = ( V_89 << 16 ) | V_90 ;
memcpy ( V_43 -> V_46 , V_88 , sizeof( V_43 -> V_46 ) ) ;
memcpy ( V_43 -> V_47 , V_87 , sizeof( V_43 -> V_47 ) ) ;
} else {
V_43 -> V_107 = ( V_89 << 16 ) | V_90 ;
memcpy ( V_43 -> V_48 , V_88 , sizeof( V_43 -> V_48 ) ) ;
memcpy ( V_43 -> V_49 , V_87 , sizeof( V_43 -> V_49 ) ) ;
}
}
static bool F_16 ( struct V_1 * V_2 ,
struct V_108 * V_109 ,
int V_27 , int V_28 ,
int V_29 , int V_30 )
{
unsigned long V_110 ;
unsigned int V_111 ;
V_110 = V_109 -> V_112 * ( F_17 ( V_2 -> V_113 ) / 1000000 ) ;
V_110 /= F_18 ( V_27 , V_29 ) * V_109 -> clock / 1000 ;
V_111 = F_19 ( V_28 , V_30 ) ;
return ( V_111 <= V_110 ) ? true : false ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_7 ;
F_21 ( L_63 , F_10 ( & V_2 -> V_63 ) ) ;
if ( F_22 ( V_2 -> V_114 , & V_2 -> V_115 ) )
F_21 ( L_64 ) ;
F_23 ( 0 , V_2 -> V_8 + V_10 ) ;
for ( V_7 = 0 ; V_7 < V_116 ; V_7 ++ ) {
if ( F_2 ( V_2 -> V_8 + V_67 )
& V_68 )
break;
F_24 ( V_117 ) ;
}
F_25 ( V_2 -> V_118 ) ;
if ( V_7 == V_116 )
F_26 ( L_65 ) ;
V_2 -> V_63 . V_119 = V_120 ;
V_2 -> V_121 = false ;
}
static int F_27 ( struct V_122 * V_123 , unsigned long V_124 , void * V_55 )
{
struct V_1 * V_2 = F_28 ( V_123 , struct V_1 , V_115 ) ;
int V_125 , V_126 ;
struct V_12 * V_127 , * V_128 ;
if ( ( V_124 != V_129 ) && ( V_124 != V_130 ) ) {
F_21 ( L_66 ) ;
return 0 ;
}
if ( V_2 -> V_63 . V_119 == V_131 ) {
F_21 ( L_67 ,
F_10 ( & V_2 -> V_63 ) ) ;
F_20 ( V_2 ) ;
}
if ( V_2 -> V_132 ) {
V_125 = F_1 ( V_2 ) ;
V_126 = F_3 ( V_2 ) ;
if ( ( V_125 == - 1 ) || ( V_126 == - 1 ) ) {
F_21 ( L_68 ) ;
return - V_133 ;
}
V_127 = V_2 -> V_78 + V_125 ;
V_128 = V_2 -> V_78 + V_126 ;
memcpy ( V_127 , V_128 , sizeof( * V_127 ) ) ;
V_127 -> V_31 . V_32 = V_35 ;
V_127 -> V_31 . V_37 +=
V_127 -> V_31 . V_39 / 2 ;
V_127 -> V_31 . V_38 +=
V_127 -> V_31 . V_40 / 2 ;
F_23 ( V_2 -> V_6 + V_125 ,
V_2 -> V_8 + V_10 ) ;
V_2 -> V_132 = false ;
F_29 ( V_2 -> V_134 , L_69 ,
V_135 , V_2 -> V_6 ) ;
F_30 ( & V_2 -> V_63 , false , true ) ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
int V_136 ;
T_2 V_137 ;
V_2 -> V_115 . V_138 = F_27 ;
V_136 = V_11 * sizeof( struct V_12 ) ;
V_2 -> V_78 = F_32 ( V_2 -> V_134 , V_136 ,
& V_137 ,
V_139 | V_140 ) ;
if ( ! V_2 -> V_78 ) {
F_26 ( L_70 ) ;
return;
}
V_2 -> V_6 = ( T_1 ) V_137 ;
memset ( V_2 -> V_78 , 0 , V_136 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_23 ( V_141 , V_2 -> V_8 + V_142 ) ;
F_23 ( V_143 , V_2 -> V_8 + V_144 ) ;
F_23 ( V_145 , V_2 -> V_8 + V_146 ) ;
F_23 ( V_147 , V_2 -> V_8 + V_148 ) ;
F_23 ( V_149 , V_2 -> V_8 + V_150 ) ;
F_23 ( V_151 , V_2 -> V_8 + V_152 ) ;
F_23 ( V_153 , V_2 -> V_8 + V_154 ) ;
F_23 ( V_141 , V_2 -> V_8 + V_155 ) ;
F_23 ( V_143 , V_2 -> V_8 + V_156 ) ;
F_23 ( V_145 , V_2 -> V_8 + V_157 ) ;
F_23 ( V_147 , V_2 -> V_8 + V_158 ) ;
F_23 ( V_149 , V_2 -> V_8 + V_159 ) ;
F_23 ( V_151 , V_2 -> V_8 + V_160 ) ;
F_23 ( V_153 , V_2 -> V_8 + V_161 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
const struct V_162 * V_162 ;
T_1 * V_163 , * V_164 , * V_165 , * V_166 ;
T_3 * V_55 ;
int V_7 ;
struct V_167 {
int V_168 ;
int V_169 ;
int V_170 ;
int V_171 ;
} * V_172 ;
F_21 ( L_62 ) ;
if ( V_2 -> V_121 ) {
F_21 ( L_71 ) ;
return;
}
if ( F_35 ( & V_162 , V_173 , V_2 -> V_134 ) ) {
F_26 ( L_72 ) ;
return;
}
if ( ! V_162 ) {
F_26 ( L_73 ) ;
return;
}
V_172 = (struct V_167 * ) V_162 -> V_55 ;
if ( V_162 -> V_136 < sizeof( * V_172 ) ) {
F_26 ( L_74 , V_162 -> V_136 ) ;
goto V_174;
}
if ( ( sizeof( * V_172 ) + V_172 -> V_168 + V_172 -> V_169 +
V_172 -> V_170 + V_172 -> V_171 ) != V_162 -> V_136 ) {
F_26 ( L_75 ,
sizeof( * V_172 ) , V_172 -> V_168 , V_172 -> V_169 ,
V_172 -> V_170 , V_172 -> V_171 ,
V_162 -> V_136 ) ;
goto V_174;
}
V_55 = ( T_3 * ) V_162 -> V_55 ;
V_55 += sizeof( * V_172 ) ;
V_163 = ( void * ) V_55 ;
V_55 += V_172 -> V_168 ;
V_164 = ( void * ) V_55 ;
V_55 += V_172 -> V_169 ;
V_165 = ( void * ) V_55 ;
V_55 += V_172 -> V_170 ;
V_166 = ( void * ) V_55 ;
if ( F_36 ( V_2 -> V_113 ) )
F_26 ( L_76 ) ;
F_23 ( V_175 , V_2 -> V_8 + V_71 ) ;
for ( V_7 = 0 ; V_7 < V_116 ; V_7 ++ ) {
if ( F_2 ( V_2 -> V_8 + V_72 )
& V_73 )
break;
F_24 ( V_117 ) ;
}
if ( V_7 == V_116 ) {
F_26 ( L_77 ) ;
goto V_174;
}
for ( V_7 = 0 ; V_7 < V_172 -> V_168 / 4 ; V_7 ++ )
F_23 ( V_163 [ V_7 ] , V_2 -> V_8 + V_176 + V_7 * 4 ) ;
for ( V_7 = 0 ; V_7 < V_172 -> V_169 / 4 ; V_7 ++ )
F_23 ( V_164 [ V_7 ] , V_2 -> V_8 + V_177 + V_7 * 4 ) ;
F_33 ( V_2 ) ;
F_23 ( V_178 , V_2 -> V_8 + V_72 ) ;
F_23 ( V_179 , V_2 -> V_8 + V_77 ) ;
F_23 ( 0 , V_2 -> V_8 + V_10 ) ;
for ( V_7 = 0 ; V_7 < V_172 -> V_170 / 4 ; V_7 ++ )
F_23 ( V_165 [ V_7 ] , V_2 -> V_8 + V_180 + V_7 * 4 ) ;
for ( V_7 = 0 ; V_7 < V_172 -> V_171 / 4 ; V_7 ++ )
F_23 ( V_166 [ V_7 ] , V_2 -> V_8 + V_181 + V_7 * 4 ) ;
F_23 ( V_75 , V_2 -> V_8 + V_74 ) ;
for ( V_7 = 0 ; V_7 < V_116 ; V_7 ++ ) {
if ( F_2 ( V_2 -> V_8 + V_67 )
& V_68 )
break;
F_24 ( V_117 ) ;
}
if ( V_7 == V_116 ) {
F_26 ( L_78 ) ;
goto V_174;
}
F_23 ( V_182 , V_2 -> V_8 + V_77 ) ;
F_37 ( L_79 ) ;
V_2 -> V_121 = true ;
V_174:
F_38 ( V_162 ) ;
}
static int F_39 ( struct V_183 * V_183 ,
struct V_184 * V_185 )
{
struct V_186 * V_63 = F_40 ( V_183 ) ;
struct V_1 * V_2 = F_41 ( V_63 ) ;
struct V_187 * V_188 = V_185 -> V_188 ;
struct V_189 * V_190 = V_185 -> V_190 ;
struct V_191 * V_192 ;
struct V_108 * V_109 ;
int V_193 , V_194 , V_29 , V_30 ;
int V_195 , V_196 , V_27 , V_28 ;
if ( ! V_188 || ! V_190 )
return 0 ;
V_192 = F_42 ( V_185 -> V_185 , V_188 ) ;
V_109 = & V_192 -> V_109 ;
V_193 = V_185 -> V_197 ;
V_194 = V_185 -> V_198 ;
V_29 = F_43 ( V_185 -> V_199 , 0 , V_109 -> V_200 - V_193 ) ;
V_30 = F_43 ( V_185 -> V_201 , 0 , V_109 -> V_202 - V_194 ) ;
V_195 = V_185 -> V_195 >> 16 ;
V_196 = V_185 -> V_196 >> 16 ;
V_27 = V_185 -> V_27 >> 16 ;
V_28 = V_185 -> V_28 >> 16 ;
if ( ! F_16 ( V_2 , V_109 ,
V_27 , V_28 ,
V_29 , V_30 ) ) {
F_26 ( L_80 ) ;
return - V_203 ;
}
if ( ! F_44 ( V_190 , 0 ) ) {
F_26 ( L_81 ) ;
return - V_203 ;
}
V_29 = F_45 ( V_29 , 2 ) ;
V_30 = F_45 ( V_30 , 2 ) ;
if ( ( V_27 > V_204 ) || ( V_27 < V_205 ) ||
( V_28 > V_206 ) || ( V_28 < V_207 ) ||
( V_29 > V_204 ) || ( V_29 < V_205 ) ||
( V_30 > V_206 ) || ( V_30 < V_207 ) ) {
F_26 ( L_82 ,
V_27 , V_28 ,
V_29 , V_30 ) ;
return - V_203 ;
}
if ( ! V_2 -> V_121 ) {
F_34 ( V_2 ) ;
if ( F_36 ( V_2 -> V_118 ) ) {
F_26 ( L_83 ) ;
return - V_203 ;
}
if ( F_46 ( V_2 -> V_114 ,
& V_2 -> V_115 ,
V_188 ) ) {
F_26 ( L_84 ) ;
return - V_203 ;
}
}
F_47 ( L_85 ,
V_188 -> V_208 . V_209 , F_48 ( F_49 ( V_188 ) ) ,
V_183 -> V_208 . V_209 , F_10 ( V_63 ) ) ;
F_47 ( L_86 ,
F_10 ( V_63 ) ,
V_29 , V_30 , V_193 , V_194 ,
V_27 , V_28 , V_195 , V_196 ) ;
return 0 ;
}
static void F_50 ( struct V_183 * V_183 ,
struct V_184 * V_210 )
{
struct V_184 * V_185 = V_183 -> V_185 ;
struct V_186 * V_63 = F_40 ( V_183 ) ;
struct V_1 * V_2 = F_41 ( V_63 ) ;
struct V_187 * V_188 = V_185 -> V_188 ;
struct V_189 * V_190 = V_185 -> V_190 ;
struct V_108 * V_109 ;
int V_193 , V_194 , V_29 , V_30 ;
int V_195 , V_196 , V_27 , V_28 ;
struct V_211 * V_212 ;
struct V_12 * V_5 ;
int V_213 , V_214 ;
int V_60 ;
if ( ! V_188 || ! V_190 )
return;
V_109 = & V_188 -> V_109 ;
V_193 = V_185 -> V_197 ;
V_194 = V_185 -> V_198 ;
V_29 = F_43 ( V_185 -> V_199 , 0 , V_109 -> V_200 - V_193 ) ;
V_30 = F_43 ( V_185 -> V_201 , 0 , V_109 -> V_202 - V_194 ) ;
V_195 = V_185 -> V_195 >> 16 ;
V_196 = V_185 -> V_196 >> 16 ;
V_27 = V_185 -> V_27 >> 16 ;
V_28 = V_185 -> V_28 >> 16 ;
V_60 = F_1 ( V_2 ) ;
if ( V_60 == - 1 ) {
F_21 ( L_87 ) ;
return;
}
V_5 = V_2 -> V_78 + V_60 ;
V_5 -> V_31 . V_32 = V_33 ;
V_5 -> V_31 . V_36 = V_215 ;
V_5 -> V_43 . V_45 = V_216 ;
V_5 -> V_50 . V_32 = V_51 ;
V_5 -> V_217 . V_32 = V_218 ;
V_5 -> V_217 . V_219 = V_220 ;
V_5 -> V_217 . V_221 = V_222 ;
V_5 -> V_217 . V_223 = V_224 ;
V_212 = F_44 ( V_190 , 0 ) ;
F_21 ( L_88 , V_190 -> V_208 . V_209 ,
( char * ) & V_190 -> V_225 ,
( unsigned long ) V_212 -> V_226 ) ;
V_5 -> V_31 . V_37 = ( T_1 ) V_212 -> V_226 + V_190 -> V_227 [ 0 ] ;
V_5 -> V_31 . V_38 = ( T_1 ) V_212 -> V_226 + V_190 -> V_227 [ 1 ] ;
V_5 -> V_31 . V_228 = V_190 -> V_229 [ 0 ] ;
V_5 -> V_31 . V_39 = V_190 -> V_229 [ 0 ] ;
V_5 -> V_31 . V_230 = V_190 -> V_229 [ 1 ] ;
V_5 -> V_31 . V_40 = V_190 -> V_229 [ 1 ] ;
V_29 = F_45 ( V_29 , 2 ) ;
V_30 = F_45 ( V_30 , 2 ) ;
V_5 -> V_31 . V_42 = V_28 << 16 | V_27 ;
V_5 -> V_31 . V_41 = V_28 << 16 | V_27 ;
V_5 -> V_43 . V_44 = V_30 << 16 | V_29 ;
V_5 -> V_31 . V_231 = V_196 << 16 | V_195 ;
if ( V_190 -> V_232 & V_233 ) {
V_5 -> V_31 . V_32 = V_34 ;
V_5 -> V_31 . V_41 = ( V_28 / 2 ) << 16 | V_27 ;
V_5 -> V_31 . V_228 *= 2 ;
V_5 -> V_31 . V_39 *= 2 ;
V_5 -> V_31 . V_230 *= 2 ;
V_5 -> V_31 . V_40 *= 2 ;
V_5 -> V_50 . V_32 = V_52 ;
V_5 -> V_50 . V_53 = V_234 ;
V_5 -> V_50 . V_54 = V_235 ;
}
V_213 = V_236 * V_29 / V_27 ;
F_15 ( V_105 , V_213 , & V_5 -> V_43 ) ;
V_214 = V_236 * V_30 / V_28 ;
F_15 ( V_237 , V_214 , & V_5 -> V_43 ) ;
F_23 ( V_2 -> V_6 + V_60 ,
V_2 -> V_8 + V_10 ) ;
if ( V_190 -> V_232 & V_233 )
V_2 -> V_132 = true ;
F_29 ( V_2 -> V_134 , L_69 ,
V_135 , V_2 -> V_6 + V_60 ) ;
F_30 ( V_63 , true , true ) ;
V_63 -> V_119 = V_238 ;
}
static void F_51 ( struct V_183 * V_183 ,
struct V_184 * V_210 )
{
struct V_186 * V_63 = F_40 ( V_183 ) ;
if ( ! V_210 -> V_188 ) {
F_21 ( L_89 ,
V_183 -> V_208 . V_209 ) ;
return;
}
F_21 ( L_85 ,
V_210 -> V_188 -> V_208 . V_209 ,
F_48 ( F_49 ( V_210 -> V_188 ) ) ,
V_183 -> V_208 . V_209 , F_10 ( V_63 ) ) ;
V_63 -> V_119 = V_239 ;
}
static void F_52 ( struct V_183 * V_183 )
{
F_21 ( L_62 ) ;
F_53 ( V_183 ) ;
F_54 ( V_183 ) ;
}
static int F_55 ( struct V_183 * V_183 )
{
struct V_186 * V_63 = F_40 ( V_183 ) ;
struct V_1 * V_2 = F_41 ( V_63 ) ;
return F_12 ( V_2 , V_183 -> V_134 -> V_240 ) ;
}
static struct V_183 * F_56 ( struct V_241 * V_242 ,
struct V_243 * V_134 , int V_244 )
{
struct V_1 * V_2 = F_57 ( V_134 ) ;
int V_245 ;
V_2 -> V_63 . V_244 = V_244 ;
V_2 -> V_63 . V_119 = V_120 ;
F_31 ( V_2 ) ;
V_245 = F_58 ( V_242 , & V_2 -> V_63 . V_183 , 1 ,
& V_246 ,
V_247 ,
F_13 ( V_247 ) ,
V_248 , NULL ) ;
if ( V_245 ) {
F_26 ( L_90 ) ;
return NULL ;
}
F_59 ( & V_2 -> V_63 . V_183 , & V_249 ) ;
F_60 ( & V_2 -> V_63 , V_248 ) ;
return & V_2 -> V_63 . V_183 ;
}
static int F_61 ( struct V_243 * V_134 , struct V_243 * V_250 , void * V_55 )
{
struct V_1 * V_2 = F_57 ( V_134 ) ;
struct V_241 * V_242 = V_55 ;
struct V_183 * V_63 ;
F_21 ( L_62 ) ;
V_2 -> V_242 = V_242 ;
V_63 = F_56 ( V_242 , V_2 -> V_134 , V_251 ) ;
if ( ! V_63 )
F_26 ( L_91 ) ;
return 0 ;
}
static void F_62 ( struct V_243 * V_134 ,
struct V_243 * V_250 , void * V_55 )
{
}
static int F_63 ( struct V_252 * V_253 )
{
struct V_243 * V_134 = & V_253 -> V_134 ;
struct V_254 * V_255 ;
struct V_1 * V_2 ;
struct V_256 * V_245 ;
F_21 ( L_62 ) ;
V_2 = F_64 ( V_134 , sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 ) {
F_26 ( L_92 ) ;
return - V_257 ;
}
V_2 -> V_134 = V_134 ;
V_245 = F_65 ( V_253 , V_258 , 0 ) ;
if ( V_245 == NULL ) {
F_26 ( L_93 ) ;
return - V_259 ;
}
V_2 -> V_8 = F_66 ( V_134 , V_245 -> V_260 , F_67 ( V_245 ) ) ;
if ( V_2 -> V_8 == NULL ) {
F_26 ( L_94 ) ;
return - V_259 ;
}
V_2 -> V_113 = F_68 ( V_134 , L_95 ) ;
V_2 -> V_118 = F_68 ( V_134 , L_96 ) ;
if ( F_69 ( V_2 -> V_113 ) || F_69 ( V_2 -> V_118 ) ) {
F_26 ( L_97 ) ;
return - V_259 ;
}
V_2 -> V_261 = F_70 ( V_134 , L_95 ) ;
if ( ! F_69 ( V_2 -> V_261 ) )
F_71 ( V_2 -> V_261 ) ;
V_255 = F_72 ( V_253 -> V_134 . V_262 , L_98 , 0 ) ;
if ( V_255 )
V_2 -> V_114 = F_73 ( V_255 ) ;
F_74 ( V_255 ) ;
F_75 ( V_253 , V_2 ) ;
return F_76 ( & V_253 -> V_134 , & V_263 ) ;
}
static int F_77 ( struct V_252 * V_253 )
{
F_78 ( & V_253 -> V_134 , & V_263 ) ;
return 0 ;
}
