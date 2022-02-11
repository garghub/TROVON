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
static int F_20 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_48 * V_49 = & V_6 -> V_50 [ 0 ] ;
V_47 -> V_51 = V_49 -> V_52 ;
V_47 -> V_53 = V_49 -> V_54 ;
V_47 -> V_55 = V_49 -> V_56 ;
V_47 -> V_57 = V_49 -> V_52 ;
V_47 -> V_58 = V_49 -> V_54 ;
V_47 -> V_59 = V_49 -> V_56 ;
V_47 -> V_60 = V_49 -> V_61 ;
V_47 -> V_62 = V_49 -> V_61 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
int V_63 ;
F_22 (adapter, eqo, i) {
V_49 -> V_61 = V_47 -> V_60 ;
V_49 -> V_54 = F_23 ( V_47 -> V_53 , V_64 ) ;
V_49 -> V_56 = F_23 ( V_47 -> V_55 , V_49 -> V_54 ) ;
V_49 -> V_65 = V_47 -> V_51 ;
}
return 0 ;
}
static void
F_24 ( struct V_1 * V_2 ,
struct V_66 * V_67 , T_3 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
void * V_73 ;
unsigned int V_63 , V_74 , V_75 = 0 , V_76 ;
for ( V_63 = 0 ; V_63 < V_77 ; V_63 ++ ) {
V_73 = ( T_2 * ) & V_6 -> V_78 + V_79 [ V_63 ] . V_80 ;
V_68 [ V_63 ] = * ( T_1 * ) V_73 ;
}
V_75 += V_77 ;
F_25 (adapter, rxo, j) {
struct V_81 * V_67 = F_26 ( V_70 ) ;
do {
V_76 = F_27 ( & V_67 -> V_82 ) ;
V_68 [ V_75 ] = V_67 -> V_83 ;
V_68 [ V_75 + 1 ] = V_67 -> V_84 ;
} while ( F_28 ( & V_67 -> V_82 , V_76 ) );
for ( V_63 = 2 ; V_63 < V_85 ; V_63 ++ ) {
V_73 = ( T_2 * ) V_67 + V_86 [ V_63 ] . V_80 ;
V_68 [ V_75 + V_63 ] = * ( T_1 * ) V_73 ;
}
V_75 += V_85 ;
}
F_29 (adapter, txo, j) {
struct V_87 * V_67 = F_30 ( V_72 ) ;
do {
V_76 = F_27 ( & V_67 -> V_88 ) ;
V_68 [ V_75 ] = V_67 -> V_89 ;
} while ( F_28 ( & V_67 -> V_88 , V_76 ) );
do {
V_76 = F_27 ( & V_67 -> V_82 ) ;
for ( V_63 = 1 ; V_63 < V_90 ; V_63 ++ ) {
V_73 = ( T_2 * ) V_67 + V_91 [ V_63 ] . V_80 ;
V_68 [ V_75 + V_63 ] =
( V_91 [ V_63 ] . V_33 == sizeof( V_92 ) ) ?
* ( V_92 * ) V_73 : * ( T_1 * ) V_73 ;
}
} while ( F_28 ( & V_67 -> V_82 , V_76 ) );
V_75 += V_90 ;
}
}
static void
F_31 ( struct V_1 * V_2 , T_4 V_93 ,
T_5 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 , V_74 ;
switch ( V_93 ) {
case V_94 :
for ( V_63 = 0 ; V_63 < V_77 ; V_63 ++ ) {
memcpy ( V_68 , V_79 [ V_63 ] . V_95 , V_96 ) ;
V_68 += V_96 ;
}
for ( V_63 = 0 ; V_63 < V_6 -> V_97 ; V_63 ++ ) {
for ( V_74 = 0 ; V_74 < V_85 ; V_74 ++ ) {
sprintf ( V_68 , L_4 , V_63 ,
V_86 [ V_74 ] . V_95 ) ;
V_68 += V_96 ;
}
}
for ( V_63 = 0 ; V_63 < V_6 -> V_98 ; V_63 ++ ) {
for ( V_74 = 0 ; V_74 < V_90 ; V_74 ++ ) {
sprintf ( V_68 , L_5 , V_63 ,
V_91 [ V_74 ] . V_95 ) ;
V_68 += V_96 ;
}
}
break;
case V_99 :
for ( V_63 = 0 ; V_63 < V_100 ; V_63 ++ ) {
memcpy ( V_68 , V_101 [ V_63 ] , V_96 ) ;
V_68 += V_96 ;
}
break;
}
}
static int F_32 ( struct V_1 * V_2 , int V_93 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_93 ) {
case V_99 :
return V_100 ;
case V_94 :
return V_77 +
V_6 -> V_97 * V_85 +
V_6 -> V_98 * V_90 ;
default:
return - V_102 ;
}
}
static int F_33 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_105 V_106 ;
T_2 V_107 = 0 ;
T_6 V_108 = 0 ;
T_2 V_109 ;
int V_26 ;
if ( ( V_6 -> V_108 < 0 ) || ( ! ( V_2 -> V_110 & V_111 ) ) ) {
V_26 = F_34 ( V_6 , & V_107 ,
& V_108 , & V_109 , 0 ) ;
if ( ! V_26 )
F_35 ( V_6 , V_109 ) ;
if ( V_108 ) {
F_36 ( V_104 , V_108 * 10 ) ;
} else {
switch ( V_107 ) {
case V_112 :
F_36 ( V_104 , V_113 ) ;
break;
case V_114 :
F_36 ( V_104 , V_115 ) ;
break;
case V_116 :
F_36 ( V_104 , V_117 ) ;
break;
case V_118 :
F_36 ( V_104 , V_119 ) ;
break;
case V_120 :
F_36 ( V_104 , 0 ) ;
break;
}
}
V_26 = F_37 ( V_6 , & V_106 ) ;
if ( ! V_26 ) {
switch ( V_106 . V_121 ) {
case V_122 :
case V_123 :
case V_124 :
V_104 -> V_125 = V_126 ;
break;
default:
V_104 -> V_125 = V_127 ;
break;
}
switch ( V_106 . V_121 ) {
case V_128 :
case V_129 :
V_104 -> V_130 = V_131 ;
V_104 -> V_132 = V_133 ;
break;
default:
V_104 -> V_130 = V_134 ;
V_104 -> V_132 = V_135 ;
break;
}
}
V_6 -> V_108 = F_38 ( V_104 ) ;
V_6 -> V_136 = V_104 -> V_125 ;
V_6 -> V_132 = V_104 -> V_132 ;
V_6 -> V_130 = V_104 -> V_130 ;
} else {
F_36 ( V_104 , V_6 -> V_108 ) ;
V_104 -> V_125 = V_6 -> V_136 ;
V_104 -> V_132 = V_6 -> V_132 ;
V_104 -> V_130 = V_6 -> V_130 ;
}
V_104 -> V_137 = V_138 ;
V_104 -> V_139 = V_6 -> V_140 ;
switch ( V_104 -> V_125 ) {
case V_126 :
V_104 -> V_141 = ( V_142 | V_143 ) ;
break;
case V_127 :
V_104 -> V_141 = ( V_142 | V_144 ) ;
break;
case V_145 :
V_104 -> V_141 = ( V_142 | V_146 ) ;
break;
}
if ( V_104 -> V_130 ) {
V_104 -> V_141 |= V_147 ;
V_104 -> V_141 |= V_148 ;
V_104 -> V_149 |= ( V_150 |
V_151 ) ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_153 -> V_154 = V_153 -> V_155 = V_6 -> V_156 [ 0 ] . V_157 . V_45 ;
V_153 -> V_158 = V_153 -> V_159 = V_6 -> V_160 [ 0 ] . V_157 . V_45 ;
}
static void
F_40 ( struct V_1 * V_2 , struct V_161 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_41 ( V_6 , & V_104 -> V_162 , & V_104 -> V_163 ) ;
V_104 -> V_130 = 0 ;
}
static int
F_42 ( struct V_1 * V_2 , struct V_161 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
if ( V_104 -> V_130 != 0 )
return - V_102 ;
V_6 -> V_164 = V_104 -> V_162 ;
V_6 -> V_165 = V_104 -> V_163 ;
V_26 = F_43 ( V_6 ,
V_6 -> V_164 , V_6 -> V_165 ) ;
if ( V_26 )
F_44 ( & V_6 -> V_16 -> V_37 , L_6 ) ;
return V_26 ;
}
static int
F_45 ( struct V_1 * V_2 ,
enum V_166 V_167 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_167 ) {
case V_168 :
F_46 ( V_6 , V_6 -> V_169 ,
& V_6 -> V_170 ) ;
return 1 ;
case V_171 :
F_47 ( V_6 , V_6 -> V_169 , 0 , 0 ,
V_172 ) ;
break;
case V_173 :
F_47 ( V_6 , V_6 -> V_169 , 0 , 0 ,
V_174 ) ;
break;
case V_175 :
F_47 ( V_6 , V_6 -> V_169 , 0 , 0 ,
V_6 -> V_170 ) ;
}
return 0 ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_176 * V_177 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_49 ( V_6 ) ) {
V_177 -> V_141 |= V_178 ;
V_177 -> V_179 |= V_178 ;
} else
V_177 -> V_179 = 0 ;
memset ( & V_177 -> V_180 , 0 , sizeof( V_177 -> V_180 ) ) ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_176 * V_177 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_177 -> V_179 & ~ V_178 )
return - V_181 ;
if ( ! F_49 ( V_6 ) ) {
F_44 ( & V_6 -> V_16 -> V_37 , L_7 ) ;
return - V_181 ;
}
if ( V_177 -> V_179 & V_178 )
V_6 -> V_177 = true ;
else
V_6 -> V_177 = false ;
return 0 ;
}
static int
F_51 ( struct V_5 * V_6 )
{
int V_182 , V_63 ;
struct V_24 V_183 ;
static const V_92 V_184 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_183 . V_33 = sizeof( struct V_185 ) ;
V_183 . V_35 = F_52 ( & V_6 -> V_16 -> V_37 , V_183 . V_33 ,
& V_183 . V_36 , V_186 ) ;
if ( ! V_183 . V_35 ) {
F_10 ( & V_6 -> V_16 -> V_37 , L_8 ) ;
return - V_38 ;
}
for ( V_63 = 0 ; V_63 < 2 ; V_63 ++ ) {
V_182 = F_53 ( V_6 , V_184 [ V_63 ] ,
4096 , & V_183 ) ;
if ( V_182 != 0 )
goto V_187;
}
V_187:
F_54 ( & V_6 -> V_16 -> V_37 , V_183 . V_33 , V_183 . V_35 ,
V_183 . V_36 ) ;
return V_182 ;
}
static V_92 F_55 ( struct V_5 * V_6 , T_2 V_188 ,
V_92 * V_26 )
{
F_56 ( V_6 , V_6 -> V_169 ,
V_188 , 1 ) ;
* V_26 = F_57 ( V_6 , V_6 -> V_169 ,
V_188 , 1500 ,
2 , 0xabc ) ;
F_56 ( V_6 , V_6 -> V_169 ,
V_189 , 1 ) ;
return * V_26 ;
}
static void
F_58 ( struct V_1 * V_2 , struct V_190 * V_191 , V_92 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_107 = 0 ;
T_6 V_192 = 0 ;
memset ( V_68 , 0 , sizeof( V_92 ) * V_100 ) ;
if ( V_191 -> V_110 & V_193 ) {
if ( F_55 ( V_6 , V_194 ,
& V_68 [ 0 ] ) != 0 ) {
V_191 -> V_110 |= V_195 ;
}
if ( F_55 ( V_6 , V_196 ,
& V_68 [ 1 ] ) != 0 ) {
V_191 -> V_110 |= V_195 ;
}
if ( F_55 ( V_6 , V_197 ,
& V_68 [ 2 ] ) != 0 ) {
V_191 -> V_110 |= V_195 ;
}
}
if ( F_51 ( V_6 ) != 0 ) {
V_68 [ 3 ] = 1 ;
V_191 -> V_110 |= V_195 ;
}
if ( F_34 ( V_6 , & V_107 ,
& V_192 , NULL , 0 ) != 0 ) {
V_191 -> V_110 |= V_195 ;
V_68 [ 4 ] = - 1 ;
} else if ( ! V_107 ) {
V_191 -> V_110 |= V_195 ;
V_68 [ 4 ] = 1 ;
}
}
static int
F_59 ( struct V_1 * V_2 , struct V_198 * V_199 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_60 ( V_6 , V_199 -> V_68 ) ;
}
static int
F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_6 ( V_6 ,
V_200 ) ;
else
return F_6 ( V_6 ,
V_201 ) ;
} else {
return V_202 ;
}
}
static int
F_62 ( struct V_1 * V_2 , struct V_203 * V_204 ,
T_5 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 V_205 ;
struct V_206 * V_207 ;
int V_26 ;
if ( ! V_204 -> V_45 )
return - V_102 ;
if ( F_16 ( V_6 ) ) {
if ( F_15 ( V_6 ) )
return F_8 ( V_6 , V_200 ,
V_204 -> V_45 , V_68 ) ;
else
return F_8 ( V_6 , V_201 ,
V_204 -> V_45 , V_68 ) ;
}
V_204 -> V_208 = V_209 | ( V_6 -> V_16 -> V_210 << 16 ) ;
memset ( & V_205 , 0 , sizeof( struct V_24 ) ) ;
V_205 . V_33 = sizeof( struct V_211 ) ;
V_205 . V_35 = F_52 ( & V_6 -> V_16 -> V_37 , V_205 . V_33 ,
& V_205 . V_36 , V_186 ) ;
if ( ! V_205 . V_35 ) {
F_10 ( & V_6 -> V_16 -> V_37 ,
L_9 ) ;
return - V_38 ;
}
V_26 = F_63 ( V_6 , & V_205 ) ;
if ( ! V_26 ) {
V_207 = V_205 . V_35 ;
memcpy ( V_68 , V_207 -> V_212 + V_204 -> V_80 , V_204 -> V_45 ) ;
}
F_54 ( & V_6 -> V_16 -> V_37 , V_205 . V_33 , V_205 . V_35 ,
V_205 . V_36 ) ;
return V_26 ;
}
