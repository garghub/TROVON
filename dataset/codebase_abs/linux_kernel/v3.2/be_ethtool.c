static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_7 [ V_8 ] ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_6 , V_6 -> V_9 , V_7 ) ;
strcpy ( V_4 -> V_10 , V_11 ) ;
strcpy ( V_4 -> V_12 , V_13 ) ;
strncpy ( V_4 -> V_14 , V_6 -> V_9 , V_8 ) ;
if ( memcmp ( V_6 -> V_9 , V_7 , V_8 ) != 0 ) {
strcat ( V_4 -> V_14 , L_1 ) ;
strcat ( V_4 -> V_14 , V_7 ) ;
strcat ( V_4 -> V_14 , L_2 ) ;
}
strcpy ( V_4 -> V_15 , F_4 ( V_6 -> V_16 ) ) ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
V_4 -> V_19 = 0 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_20 = 0 ;
if ( F_6 ( V_6 ) )
F_7 ( V_6 , & V_20 ) ;
return V_20 ;
}
static void
F_8 ( struct V_1 * V_2 , struct V_21 * V_22 , void * V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_6 ( V_6 ) ) {
memset ( V_23 , 0 , V_22 -> V_24 ) ;
F_9 ( V_6 , V_22 -> V_24 , V_23 ) ;
}
}
static int
F_10 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_6 -> V_29 [ 0 ] . V_28 ;
struct V_27 * V_30 = & V_6 -> V_30 ;
V_26 -> V_31 = V_28 -> V_32 ;
V_26 -> V_33 = V_28 -> V_34 ;
V_26 -> V_35 = V_28 -> V_36 ;
V_26 -> V_37 = V_30 -> V_32 ;
V_26 -> V_38 = V_30 -> V_34 ;
V_26 -> V_39 = V_30 -> V_36 ;
V_26 -> V_40 = V_28 -> V_41 ;
V_26 -> V_42 = V_30 -> V_41 ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_43 * V_44 ;
struct V_27 * V_28 ;
struct V_27 * V_30 = & V_6 -> V_30 ;
T_1 V_45 , V_46 , V_47 ;
int V_48 = 0 , V_49 ;
T_1 V_50 ;
if ( V_26 -> V_42 == 1 )
return - V_51 ;
F_12 (adapter, rxo, i) {
V_28 = & V_44 -> V_28 ;
if ( ! V_28 -> V_41 && V_26 -> V_40 )
V_28 -> V_32 = 0 ;
V_28 -> V_41 = V_26 -> V_40 ;
V_45 = V_26 -> V_33 ;
V_46 = V_26 -> V_35 ;
V_47 = V_26 -> V_31 ;
if ( V_28 -> V_41 ) {
if ( V_45 > V_52 )
V_45 = V_52 ;
if ( V_46 > V_45 )
V_46 = V_45 ;
V_28 -> V_34 = V_45 ;
V_28 -> V_36 = V_46 ;
if ( V_28 -> V_32 > V_45 )
V_28 -> V_32 = V_45 ;
if ( V_28 -> V_32 < V_46 )
V_28 -> V_32 = V_46 ;
} else {
if ( V_47 > V_52 )
V_47 = V_52 ;
if ( V_28 -> V_32 != V_47 ) {
V_48 = F_13 ( V_6 , V_28 -> V_53 . V_54 ,
V_47 ) ;
if ( ! V_48 )
V_28 -> V_32 = V_47 ;
}
}
}
V_50 = V_26 -> V_37 ;
if ( V_50 > V_52 )
V_50 = V_52 ;
if ( V_30 -> V_32 != V_50 ) {
V_48 = F_13 ( V_6 , V_30 -> V_53 . V_54 , V_50 ) ;
if ( ! V_48 )
V_30 -> V_32 = V_50 ;
}
return 0 ;
}
static void
F_14 ( struct V_1 * V_2 ,
struct V_55 * V_56 , T_2 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_43 * V_44 ;
struct V_58 * V_59 ;
void * V_60 ;
unsigned int V_49 , V_61 , V_62 = 0 , V_63 ;
for ( V_49 = 0 ; V_49 < V_64 ; V_49 ++ ) {
V_60 = ( V_65 * ) & V_6 -> V_66 + V_67 [ V_49 ] . V_68 ;
V_57 [ V_49 ] = * ( T_1 * ) V_60 ;
}
V_62 += V_64 ;
F_12 (adapter, rxo, j) {
struct V_69 * V_56 = F_15 ( V_44 ) ;
do {
V_63 = F_16 ( & V_56 -> V_70 ) ;
V_57 [ V_62 ] = V_56 -> V_71 ;
V_57 [ V_62 + 1 ] = V_56 -> V_72 ;
} while ( F_17 ( & V_56 -> V_70 , V_63 ) );
for ( V_49 = 2 ; V_49 < V_73 ; V_49 ++ ) {
V_60 = ( V_65 * ) V_56 + V_74 [ V_49 ] . V_68 ;
V_57 [ V_62 + V_49 ] = * ( T_1 * ) V_60 ;
}
V_62 += V_73 ;
}
F_18 (adapter, txo, j) {
struct V_75 * V_56 = F_19 ( V_59 ) ;
do {
V_63 = F_16 ( & V_56 -> V_76 ) ;
V_57 [ V_62 ] = V_56 -> V_77 ;
} while ( F_17 ( & V_56 -> V_76 , V_63 ) );
do {
V_63 = F_16 ( & V_56 -> V_70 ) ;
for ( V_49 = 1 ; V_49 < V_78 ; V_49 ++ ) {
V_60 = ( V_65 * ) V_56 + V_79 [ V_49 ] . V_68 ;
V_57 [ V_62 + V_49 ] =
( V_79 [ V_49 ] . V_80 == sizeof( V_81 ) ) ?
* ( V_81 * ) V_60 : * ( T_1 * ) V_60 ;
}
} while ( F_17 ( & V_56 -> V_70 , V_63 ) );
V_62 += V_78 ;
}
}
static void
F_20 ( struct V_1 * V_2 , T_3 V_82 ,
T_4 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_49 , V_61 ;
switch ( V_82 ) {
case V_83 :
for ( V_49 = 0 ; V_49 < V_64 ; V_49 ++ ) {
memcpy ( V_57 , V_67 [ V_49 ] . V_84 , V_85 ) ;
V_57 += V_85 ;
}
for ( V_49 = 0 ; V_49 < V_6 -> V_86 ; V_49 ++ ) {
for ( V_61 = 0 ; V_61 < V_73 ; V_61 ++ ) {
sprintf ( V_57 , L_3 , V_49 ,
V_74 [ V_61 ] . V_84 ) ;
V_57 += V_85 ;
}
}
for ( V_49 = 0 ; V_49 < V_6 -> V_87 ; V_49 ++ ) {
for ( V_61 = 0 ; V_61 < V_78 ; V_61 ++ ) {
sprintf ( V_57 , L_4 , V_49 ,
V_79 [ V_61 ] . V_84 ) ;
V_57 += V_85 ;
}
}
break;
case V_88 :
for ( V_49 = 0 ; V_49 < V_89 ; V_49 ++ ) {
memcpy ( V_57 , V_90 [ V_49 ] , V_85 ) ;
V_57 += V_85 ;
}
break;
}
}
static int F_21 ( struct V_1 * V_2 , int V_82 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_82 ) {
case V_88 :
return V_89 ;
case V_83 :
return V_64 +
V_6 -> V_86 * V_73 +
V_6 -> V_87 * V_78 ;
default:
return - V_51 ;
}
}
static int F_22 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_93 V_94 ;
V_65 V_95 = 0 ;
T_5 V_96 = 0 ;
int V_48 ;
if ( ( V_6 -> V_96 < 0 ) || ( ! ( V_2 -> V_97 & V_98 ) ) ) {
V_48 = F_23 ( V_6 , & V_95 ,
& V_96 , 0 ) ;
if ( V_96 ) {
F_24 ( V_92 , V_96 * 10 ) ;
} else {
switch ( V_95 ) {
case V_99 :
F_24 ( V_92 , V_100 ) ;
break;
case V_101 :
F_24 ( V_92 , V_102 ) ;
break;
case V_103 :
F_24 ( V_92 , V_104 ) ;
break;
case V_105 :
F_24 ( V_92 , V_106 ) ;
break;
case V_107 :
F_24 ( V_92 , 0 ) ;
break;
}
}
V_48 = F_25 ( V_6 , & V_94 ) ;
if ( ! V_48 ) {
switch ( V_94 . V_108 ) {
case V_109 :
case V_110 :
case V_111 :
V_92 -> V_112 = V_113 ;
break;
default:
V_92 -> V_112 = V_114 ;
break;
}
switch ( V_94 . V_108 ) {
case V_115 :
case V_116 :
V_92 -> V_117 = V_118 ;
V_92 -> V_119 = V_120 ;
break;
default:
V_92 -> V_117 = V_121 ;
V_92 -> V_119 = V_122 ;
break;
}
}
V_6 -> V_96 = F_26 ( V_92 ) ;
V_6 -> V_123 = V_92 -> V_112 ;
V_6 -> V_119 = V_92 -> V_119 ;
V_6 -> V_117 = V_92 -> V_117 ;
} else {
F_24 ( V_92 , V_6 -> V_96 ) ;
V_92 -> V_112 = V_6 -> V_123 ;
V_92 -> V_119 = V_6 -> V_119 ;
V_92 -> V_117 = V_6 -> V_117 ;
}
V_92 -> V_124 = V_125 ;
V_92 -> V_126 = V_6 -> V_127 ;
switch ( V_92 -> V_112 ) {
case V_113 :
V_92 -> V_128 = ( V_129 | V_130 ) ;
break;
case V_114 :
V_92 -> V_128 = ( V_129 | V_131 ) ;
break;
case V_132 :
V_92 -> V_128 = ( V_129 | V_133 ) ;
break;
}
if ( V_92 -> V_117 ) {
V_92 -> V_128 |= V_134 ;
V_92 -> V_128 |= V_135 ;
V_92 -> V_136 |= ( V_137 |
V_138 ) ;
}
return 0 ;
}
static void
F_27 ( struct V_1 * V_2 , struct V_139 * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_140 -> V_141 = V_6 -> V_29 [ 0 ] . V_53 . V_24 ;
V_140 -> V_142 = V_6 -> V_143 [ 0 ] . V_53 . V_24 ;
V_140 -> V_144 = F_28 ( & V_6 -> V_29 [ 0 ] . V_53 . V_145 ) ;
V_140 -> V_146 = F_28 ( & V_6 -> V_143 [ 0 ] . V_53 . V_145 ) ;
}
static void
F_29 ( struct V_1 * V_2 , struct V_147 * V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_30 ( V_6 , & V_92 -> V_148 , & V_92 -> V_149 ) ;
V_92 -> V_117 = 0 ;
}
static int
F_31 ( struct V_1 * V_2 , struct V_147 * V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_48 ;
if ( V_92 -> V_117 != 0 )
return - V_51 ;
V_6 -> V_150 = V_92 -> V_148 ;
V_6 -> V_151 = V_92 -> V_149 ;
V_48 = F_32 ( V_6 ,
V_6 -> V_150 , V_6 -> V_151 ) ;
if ( V_48 )
F_33 ( & V_6 -> V_16 -> V_152 , L_5 ) ;
return V_48 ;
}
static int
F_34 ( struct V_1 * V_2 ,
enum V_153 V_154 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_154 ) {
case V_155 :
F_35 ( V_6 , V_6 -> V_156 ,
& V_6 -> V_157 ) ;
return 1 ;
case V_158 :
F_36 ( V_6 , V_6 -> V_156 , 0 , 0 ,
V_159 ) ;
break;
case V_160 :
F_36 ( V_6 , V_6 -> V_156 , 0 , 0 ,
V_161 ) ;
break;
case V_162 :
F_36 ( V_6 , V_6 -> V_156 , 0 , 0 ,
V_6 -> V_157 ) ;
}
return 0 ;
}
static bool
F_37 ( struct V_5 * V_6 )
{
if ( ! F_6 ( V_6 ) )
return false ;
else
return true ;
}
static void
F_38 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_37 ( V_6 ) )
V_164 -> V_128 = V_165 ;
if ( V_6 -> V_164 )
V_164 -> V_166 = V_165 ;
else
V_164 -> V_166 = 0 ;
memset ( & V_164 -> V_167 , 0 , sizeof( V_164 -> V_167 ) ) ;
}
static int
F_39 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_164 -> V_166 & ~ V_165 )
return - V_51 ;
if ( ( V_164 -> V_166 & V_165 ) && F_37 ( V_6 ) )
V_6 -> V_164 = true ;
else
V_6 -> V_164 = false ;
return 0 ;
}
static int
F_40 ( struct V_5 * V_6 )
{
int V_168 , V_49 ;
struct V_169 V_170 ;
static const V_81 V_171 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_170 . V_80 = sizeof( struct V_172 ) ;
V_170 . V_173 = F_41 ( & V_6 -> V_16 -> V_152 , V_170 . V_80 ,
& V_170 . V_174 , V_175 ) ;
if ( ! V_170 . V_173 ) {
F_42 ( & V_6 -> V_16 -> V_152 , L_6 ) ;
return - V_176 ;
}
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
V_168 = F_43 ( V_6 , V_171 [ V_49 ] ,
4096 , & V_170 ) ;
if ( V_168 != 0 )
goto V_177;
}
V_177:
F_44 ( & V_6 -> V_16 -> V_152 , V_170 . V_80 , V_170 . V_173 ,
V_170 . V_174 ) ;
return V_168 ;
}
static V_81 F_45 ( struct V_5 * V_6 , V_65 V_178 ,
V_81 * V_48 )
{
F_46 ( V_6 , V_6 -> V_156 ,
V_178 , 1 ) ;
* V_48 = F_47 ( V_6 , V_6 -> V_156 ,
V_178 , 1500 ,
2 , 0xabc ) ;
F_46 ( V_6 , V_6 -> V_156 ,
V_179 , 1 ) ;
return * V_48 ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_180 * V_181 , V_81 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_65 V_95 = 0 ;
T_5 V_182 = 0 ;
memset ( V_57 , 0 , sizeof( V_81 ) * V_89 ) ;
if ( V_181 -> V_97 & V_183 ) {
if ( F_45 ( V_6 , V_184 ,
& V_57 [ 0 ] ) != 0 ) {
V_181 -> V_97 |= V_185 ;
}
if ( F_45 ( V_6 , V_186 ,
& V_57 [ 1 ] ) != 0 ) {
V_181 -> V_97 |= V_185 ;
}
if ( F_45 ( V_6 , V_187 ,
& V_57 [ 2 ] ) != 0 ) {
V_181 -> V_97 |= V_185 ;
}
}
if ( F_40 ( V_6 ) != 0 ) {
V_57 [ 3 ] = 1 ;
V_181 -> V_97 |= V_185 ;
}
if ( F_23 ( V_6 , & V_95 ,
& V_182 , 0 ) != 0 ) {
V_181 -> V_97 |= V_185 ;
V_57 [ 4 ] = - 1 ;
} else if ( ! V_95 ) {
V_181 -> V_97 |= V_185 ;
V_57 [ 4 ] = 1 ;
}
}
static int
F_49 ( struct V_1 * V_2 , struct V_188 * V_189 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_190 [ V_191 ] ;
V_190 [ V_191 - 1 ] = 0 ;
strcpy ( V_190 , V_189 -> V_57 ) ;
return F_50 ( V_6 , V_190 ) ;
}
static int
F_51 ( struct V_1 * V_2 )
{
return V_192 ;
}
static int
F_52 ( struct V_1 * V_2 , struct V_193 * V_194 ,
T_4 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_169 V_195 ;
struct V_196 * V_197 ;
int V_48 ;
if ( ! V_194 -> V_24 )
return - V_51 ;
V_194 -> V_198 = V_199 | ( V_6 -> V_16 -> V_200 << 16 ) ;
memset ( & V_195 , 0 , sizeof( struct V_169 ) ) ;
V_195 . V_80 = sizeof( struct V_201 ) ;
V_195 . V_173 = F_41 ( & V_6 -> V_16 -> V_152 , V_195 . V_80 ,
& V_195 . V_174 , V_175 ) ;
if ( ! V_195 . V_173 ) {
F_42 ( & V_6 -> V_16 -> V_152 ,
L_7 ) ;
return - V_176 ;
}
V_48 = F_53 ( V_6 , & V_195 ) ;
if ( ! V_48 ) {
V_197 = V_195 . V_173 ;
memcpy ( V_57 , V_197 -> V_202 + V_194 -> V_68 , V_194 -> V_24 ) ;
}
F_44 ( & V_6 -> V_16 -> V_152 , V_195 . V_80 , V_195 . V_173 ,
V_195 . V_174 ) ;
return V_48 ;
}
