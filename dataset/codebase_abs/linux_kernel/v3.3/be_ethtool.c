static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_7 [ V_8 ] ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_6 , V_6 -> V_9 , V_7 ) ;
F_4 ( V_4 -> V_10 , V_11 , sizeof( V_4 -> V_10 ) ) ;
F_4 ( V_4 -> V_12 , V_13 , sizeof( V_4 -> V_12 ) ) ;
strncpy ( V_4 -> V_14 , V_6 -> V_9 , V_8 ) ;
if ( memcmp ( V_6 -> V_9 , V_7 , V_8 ) != 0 ) {
strcat ( V_4 -> V_14 , L_1 ) ;
strcat ( V_4 -> V_14 , V_7 ) ;
strcat ( V_4 -> V_14 , L_2 ) ;
}
F_4 ( V_4 -> V_15 , F_5 ( V_6 -> V_16 ) ,
sizeof( V_4 -> V_15 ) ) ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
V_4 -> V_19 = 0 ;
}
static T_1
F_6 ( struct V_5 * V_6 , T_2 * V_20 )
{
T_1 V_21 = 0 , V_22 ;
T_2 V_23 ;
struct V_24 V_25 ;
int V_26 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_26 = F_7 ( V_6 , & V_25 , 0 , 0 ,
V_20 , & V_21 , & V_22 , & V_23 ) ;
return V_21 ;
}
static int
F_8 ( struct V_5 * V_6 , T_2 * V_20 ,
T_1 V_27 , void * V_28 )
{
struct V_24 V_29 ;
T_1 V_30 = 0 , V_31 = 0 , V_32 ;
T_1 V_22 = 0 ;
T_2 V_23 ;
int V_26 = 0 ;
V_29 . V_33 = V_34 ;
V_29 . V_35 = F_9 ( V_6 -> V_16 , V_29 . V_33 ,
& V_29 . V_36 ) ;
if ( ! V_29 . V_35 ) {
F_10 ( & V_6 -> V_16 -> V_37 ,
L_3 ) ;
return - V_38 ;
}
while ( ( V_31 < V_27 ) && ! V_22 ) {
V_32 = F_11 ( T_1 , ( V_27 - V_31 ) ,
V_34 ) ;
V_32 = F_12 ( V_32 , 4 ) ;
V_26 = F_7 ( V_6 , & V_29 , V_32 ,
V_31 , V_20 , & V_30 ,
& V_22 , & V_23 ) ;
if ( ! V_26 ) {
memcpy ( V_28 + V_31 , V_29 . V_35 , V_30 ) ;
V_31 += V_30 ;
V_22 &= V_39 ;
} else {
V_26 = - V_40 ;
break;
}
}
F_13 ( V_6 -> V_16 , V_29 . V_33 , V_29 . V_35 ,
V_29 . V_36 ) ;
return V_26 ;
}
static int
F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_41 = 0 ;
if ( F_15 ( V_6 ) ) {
if ( F_16 ( V_6 ) )
V_41 = F_6 ( V_6 ,
V_42 ) ;
else
F_17 ( V_6 , & V_41 ) ;
}
return V_41 ;
}
static void
F_18 ( struct V_1 * V_2 , struct V_43 * V_44 , void * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_15 ( V_6 ) ) {
memset ( V_28 , 0 , V_44 -> V_45 ) ;
if ( F_16 ( V_6 ) )
F_8 ( V_6 , V_42 ,
V_44 -> V_45 , V_28 ) ;
else
F_19 ( V_6 , V_44 -> V_45 , V_28 ) ;
}
}
static int
F_20 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_48 * V_49 = & V_6 -> V_50 [ 0 ] . V_49 ;
struct V_48 * V_51 = & V_6 -> V_51 ;
V_47 -> V_52 = V_49 -> V_53 ;
V_47 -> V_54 = V_49 -> V_55 ;
V_47 -> V_56 = V_49 -> V_57 ;
V_47 -> V_58 = V_51 -> V_53 ;
V_47 -> V_59 = V_51 -> V_55 ;
V_47 -> V_60 = V_51 -> V_57 ;
V_47 -> V_61 = V_49 -> V_62 ;
V_47 -> V_63 = V_51 -> V_62 ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_64 * V_65 ;
struct V_48 * V_49 ;
struct V_48 * V_51 = & V_6 -> V_51 ;
T_1 V_66 , V_67 , V_68 ;
int V_26 = 0 , V_69 ;
T_1 V_70 ;
if ( V_47 -> V_63 == 1 )
return - V_71 ;
F_22 (adapter, rxo, i) {
V_49 = & V_65 -> V_49 ;
if ( ! V_49 -> V_62 && V_47 -> V_61 )
V_49 -> V_53 = 0 ;
V_49 -> V_62 = V_47 -> V_61 ;
V_66 = V_47 -> V_54 ;
V_67 = V_47 -> V_56 ;
V_68 = V_47 -> V_52 ;
if ( V_49 -> V_62 ) {
if ( V_66 > V_72 )
V_66 = V_72 ;
if ( V_67 > V_66 )
V_67 = V_66 ;
V_49 -> V_55 = V_66 ;
V_49 -> V_57 = V_67 ;
if ( V_49 -> V_53 > V_66 )
V_49 -> V_53 = V_66 ;
if ( V_49 -> V_53 < V_67 )
V_49 -> V_53 = V_67 ;
} else {
if ( V_68 > V_72 )
V_68 = V_72 ;
if ( V_49 -> V_53 != V_68 ) {
V_26 = F_23 ( V_6 , V_49 -> V_73 . V_74 ,
V_68 ) ;
if ( ! V_26 )
V_49 -> V_53 = V_68 ;
}
}
}
V_70 = V_47 -> V_58 ;
if ( V_70 > V_72 )
V_70 = V_72 ;
if ( V_51 -> V_53 != V_70 ) {
V_26 = F_23 ( V_6 , V_51 -> V_73 . V_74 , V_70 ) ;
if ( ! V_26 )
V_51 -> V_53 = V_70 ;
}
return 0 ;
}
static void
F_24 ( struct V_1 * V_2 ,
struct V_75 * V_76 , T_3 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_64 * V_65 ;
struct V_78 * V_79 ;
void * V_80 ;
unsigned int V_69 , V_81 , V_82 = 0 , V_83 ;
for ( V_69 = 0 ; V_69 < V_84 ; V_69 ++ ) {
V_80 = ( T_2 * ) & V_6 -> V_85 + V_86 [ V_69 ] . V_87 ;
V_77 [ V_69 ] = * ( T_1 * ) V_80 ;
}
V_82 += V_84 ;
F_22 (adapter, rxo, j) {
struct V_88 * V_76 = F_25 ( V_65 ) ;
do {
V_83 = F_26 ( & V_76 -> V_89 ) ;
V_77 [ V_82 ] = V_76 -> V_90 ;
V_77 [ V_82 + 1 ] = V_76 -> V_91 ;
} while ( F_27 ( & V_76 -> V_89 , V_83 ) );
for ( V_69 = 2 ; V_69 < V_92 ; V_69 ++ ) {
V_80 = ( T_2 * ) V_76 + V_93 [ V_69 ] . V_87 ;
V_77 [ V_82 + V_69 ] = * ( T_1 * ) V_80 ;
}
V_82 += V_92 ;
}
F_28 (adapter, txo, j) {
struct V_94 * V_76 = F_29 ( V_79 ) ;
do {
V_83 = F_26 ( & V_76 -> V_95 ) ;
V_77 [ V_82 ] = V_76 -> V_96 ;
} while ( F_27 ( & V_76 -> V_95 , V_83 ) );
do {
V_83 = F_26 ( & V_76 -> V_89 ) ;
for ( V_69 = 1 ; V_69 < V_97 ; V_69 ++ ) {
V_80 = ( T_2 * ) V_76 + V_98 [ V_69 ] . V_87 ;
V_77 [ V_82 + V_69 ] =
( V_98 [ V_69 ] . V_33 == sizeof( V_99 ) ) ?
* ( V_99 * ) V_80 : * ( T_1 * ) V_80 ;
}
} while ( F_27 ( & V_76 -> V_89 , V_83 ) );
V_82 += V_97 ;
}
}
static void
F_30 ( struct V_1 * V_2 , T_4 V_100 ,
T_5 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_69 , V_81 ;
switch ( V_100 ) {
case V_101 :
for ( V_69 = 0 ; V_69 < V_84 ; V_69 ++ ) {
memcpy ( V_77 , V_86 [ V_69 ] . V_102 , V_103 ) ;
V_77 += V_103 ;
}
for ( V_69 = 0 ; V_69 < V_6 -> V_104 ; V_69 ++ ) {
for ( V_81 = 0 ; V_81 < V_92 ; V_81 ++ ) {
sprintf ( V_77 , L_4 , V_69 ,
V_93 [ V_81 ] . V_102 ) ;
V_77 += V_103 ;
}
}
for ( V_69 = 0 ; V_69 < V_6 -> V_105 ; V_69 ++ ) {
for ( V_81 = 0 ; V_81 < V_97 ; V_81 ++ ) {
sprintf ( V_77 , L_5 , V_69 ,
V_98 [ V_81 ] . V_102 ) ;
V_77 += V_103 ;
}
}
break;
case V_106 :
for ( V_69 = 0 ; V_69 < V_107 ; V_69 ++ ) {
memcpy ( V_77 , V_108 [ V_69 ] , V_103 ) ;
V_77 += V_103 ;
}
break;
}
}
static int F_31 ( struct V_1 * V_2 , int V_100 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_100 ) {
case V_106 :
return V_107 ;
case V_101 :
return V_84 +
V_6 -> V_104 * V_92 +
V_6 -> V_105 * V_97 ;
default:
return - V_71 ;
}
}
static int F_32 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_111 V_112 ;
T_2 V_113 = 0 ;
T_6 V_114 = 0 ;
T_2 V_115 ;
int V_26 ;
if ( ( V_6 -> V_114 < 0 ) || ( ! ( V_2 -> V_116 & V_117 ) ) ) {
V_26 = F_33 ( V_6 , & V_113 ,
& V_114 , & V_115 , 0 ) ;
if ( ! V_26 )
F_34 ( V_6 , V_115 ) ;
if ( V_114 ) {
F_35 ( V_110 , V_114 * 10 ) ;
} else {
switch ( V_113 ) {
case V_118 :
F_35 ( V_110 , V_119 ) ;
break;
case V_120 :
F_35 ( V_110 , V_121 ) ;
break;
case V_122 :
F_35 ( V_110 , V_123 ) ;
break;
case V_124 :
F_35 ( V_110 , V_125 ) ;
break;
case V_126 :
F_35 ( V_110 , 0 ) ;
break;
}
}
V_26 = F_36 ( V_6 , & V_112 ) ;
if ( ! V_26 ) {
switch ( V_112 . V_127 ) {
case V_128 :
case V_129 :
case V_130 :
V_110 -> V_131 = V_132 ;
break;
default:
V_110 -> V_131 = V_133 ;
break;
}
switch ( V_112 . V_127 ) {
case V_134 :
case V_135 :
V_110 -> V_136 = V_137 ;
V_110 -> V_138 = V_139 ;
break;
default:
V_110 -> V_136 = V_140 ;
V_110 -> V_138 = V_141 ;
break;
}
}
V_6 -> V_114 = F_37 ( V_110 ) ;
V_6 -> V_142 = V_110 -> V_131 ;
V_6 -> V_138 = V_110 -> V_138 ;
V_6 -> V_136 = V_110 -> V_136 ;
} else {
F_35 ( V_110 , V_6 -> V_114 ) ;
V_110 -> V_131 = V_6 -> V_142 ;
V_110 -> V_138 = V_6 -> V_138 ;
V_110 -> V_136 = V_6 -> V_136 ;
}
V_110 -> V_143 = V_144 ;
V_110 -> V_145 = V_6 -> V_146 ;
switch ( V_110 -> V_131 ) {
case V_132 :
V_110 -> V_147 = ( V_148 | V_149 ) ;
break;
case V_133 :
V_110 -> V_147 = ( V_148 | V_150 ) ;
break;
case V_151 :
V_110 -> V_147 = ( V_148 | V_152 ) ;
break;
}
if ( V_110 -> V_136 ) {
V_110 -> V_147 |= V_153 ;
V_110 -> V_147 |= V_154 ;
V_110 -> V_155 |= ( V_156 |
V_157 ) ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_159 -> V_160 = V_159 -> V_161 = V_6 -> V_50 [ 0 ] . V_73 . V_45 ;
V_159 -> V_162 = V_159 -> V_163 = V_6 -> V_164 [ 0 ] . V_73 . V_45 ;
}
static void
F_39 ( struct V_1 * V_2 , struct V_165 * V_110 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_40 ( V_6 , & V_110 -> V_166 , & V_110 -> V_167 ) ;
V_110 -> V_136 = 0 ;
}
static int
F_41 ( struct V_1 * V_2 , struct V_165 * V_110 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( V_110 -> V_136 != 0 )
return - V_71 ;
V_6 -> V_168 = V_110 -> V_166 ;
V_6 -> V_169 = V_110 -> V_167 ;
V_26 = F_42 ( V_6 ,
V_6 -> V_168 , V_6 -> V_169 ) ;
if ( V_26 )
F_43 ( & V_6 -> V_16 -> V_37 , L_6 ) ;
return V_26 ;
}
static int
F_44 ( struct V_1 * V_2 ,
enum V_170 V_171 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_171 ) {
case V_172 :
F_45 ( V_6 , V_6 -> V_173 ,
& V_6 -> V_174 ) ;
return 1 ;
case V_175 :
F_46 ( V_6 , V_6 -> V_173 , 0 , 0 ,
V_176 ) ;
break;
case V_177 :
F_46 ( V_6 , V_6 -> V_173 , 0 , 0 ,
V_178 ) ;
break;
case V_179 :
F_46 ( V_6 , V_6 -> V_173 , 0 , 0 ,
V_6 -> V_174 ) ;
}
return 0 ;
}
static bool
F_47 ( struct V_5 * V_6 )
{
if ( ! F_15 ( V_6 ) )
return false ;
else
return true ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_47 ( V_6 ) )
V_181 -> V_147 = V_182 ;
if ( V_6 -> V_181 )
V_181 -> V_183 = V_182 ;
else
V_181 -> V_183 = 0 ;
memset ( & V_181 -> V_184 , 0 , sizeof( V_181 -> V_184 ) ) ;
}
static int
F_49 ( struct V_1 * V_2 , struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_181 -> V_183 & ~ V_182 )
return - V_71 ;
if ( ( V_181 -> V_183 & V_182 ) && F_47 ( V_6 ) )
V_6 -> V_181 = true ;
else
V_6 -> V_181 = false ;
return 0 ;
}
static int
F_50 ( struct V_5 * V_6 )
{
int V_185 , V_69 ;
struct V_24 V_186 ;
static const V_99 V_187 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_186 . V_33 = sizeof( struct V_188 ) ;
V_186 . V_35 = F_51 ( & V_6 -> V_16 -> V_37 , V_186 . V_33 ,
& V_186 . V_36 , V_189 ) ;
if ( ! V_186 . V_35 ) {
F_10 ( & V_6 -> V_16 -> V_37 , L_7 ) ;
return - V_38 ;
}
for ( V_69 = 0 ; V_69 < 2 ; V_69 ++ ) {
V_185 = F_52 ( V_6 , V_187 [ V_69 ] ,
4096 , & V_186 ) ;
if ( V_185 != 0 )
goto V_190;
}
V_190:
F_53 ( & V_6 -> V_16 -> V_37 , V_186 . V_33 , V_186 . V_35 ,
V_186 . V_36 ) ;
return V_185 ;
}
static V_99 F_54 ( struct V_5 * V_6 , T_2 V_191 ,
V_99 * V_26 )
{
F_55 ( V_6 , V_6 -> V_173 ,
V_191 , 1 ) ;
* V_26 = F_56 ( V_6 , V_6 -> V_173 ,
V_191 , 1500 ,
2 , 0xabc ) ;
F_55 ( V_6 , V_6 -> V_173 ,
V_192 , 1 ) ;
return * V_26 ;
}
static void
F_57 ( struct V_1 * V_2 , struct V_193 * V_194 , V_99 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_113 = 0 ;
T_6 V_195 = 0 ;
memset ( V_77 , 0 , sizeof( V_99 ) * V_107 ) ;
if ( V_194 -> V_116 & V_196 ) {
if ( F_54 ( V_6 , V_197 ,
& V_77 [ 0 ] ) != 0 ) {
V_194 -> V_116 |= V_198 ;
}
if ( F_54 ( V_6 , V_199 ,
& V_77 [ 1 ] ) != 0 ) {
V_194 -> V_116 |= V_198 ;
}
if ( F_54 ( V_6 , V_200 ,
& V_77 [ 2 ] ) != 0 ) {
V_194 -> V_116 |= V_198 ;
}
}
if ( F_50 ( V_6 ) != 0 ) {
V_77 [ 3 ] = 1 ;
V_194 -> V_116 |= V_198 ;
}
if ( F_33 ( V_6 , & V_113 ,
& V_195 , NULL , 0 ) != 0 ) {
V_194 -> V_116 |= V_198 ;
V_77 [ 4 ] = - 1 ;
} else if ( ! V_113 ) {
V_194 -> V_116 |= V_198 ;
V_77 [ 4 ] = 1 ;
}
}
static int
F_58 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_59 ( V_6 , V_202 -> V_77 ) ;
}
static int
F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_6 ( V_6 ,
V_203 ) ;
else
return F_6 ( V_6 ,
V_204 ) ;
} else {
return V_205 ;
}
}
static int
F_61 ( struct V_1 * V_2 , struct V_206 * V_207 ,
T_5 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 V_208 ;
struct V_209 * V_210 ;
int V_26 ;
if ( ! V_207 -> V_45 )
return - V_71 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_8 ( V_6 , V_203 ,
V_207 -> V_45 , V_77 ) ;
else
return F_8 ( V_6 , V_204 ,
V_207 -> V_45 , V_77 ) ;
}
V_207 -> V_211 = V_212 | ( V_6 -> V_16 -> V_213 << 16 ) ;
memset ( & V_208 , 0 , sizeof( struct V_24 ) ) ;
V_208 . V_33 = sizeof( struct V_214 ) ;
V_208 . V_35 = F_51 ( & V_6 -> V_16 -> V_37 , V_208 . V_33 ,
& V_208 . V_36 , V_189 ) ;
if ( ! V_208 . V_35 ) {
F_10 ( & V_6 -> V_16 -> V_37 ,
L_8 ) ;
return - V_38 ;
}
V_26 = F_62 ( V_6 , & V_208 ) ;
if ( ! V_26 ) {
V_210 = V_208 . V_35 ;
memcpy ( V_77 , V_210 -> V_215 + V_207 -> V_87 , V_207 -> V_45 ) ;
}
F_53 ( & V_6 -> V_16 -> V_37 , V_208 . V_33 , V_208 . V_35 ,
V_208 . V_36 ) ;
return V_26 ;
}
