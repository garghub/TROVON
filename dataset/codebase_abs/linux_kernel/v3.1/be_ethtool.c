static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
strcpy ( V_4 -> V_7 , V_8 ) ;
strcpy ( V_4 -> V_9 , V_10 ) ;
strncpy ( V_4 -> V_11 , V_6 -> V_12 , V_13 ) ;
strcpy ( V_4 -> V_14 , F_3 ( V_6 -> V_15 ) ) ;
V_4 -> V_16 = 0 ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
}
static int
F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_19 = 0 ;
if ( F_5 ( V_6 ) )
F_6 ( V_6 , & V_19 ) ;
return V_19 ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_20 * V_21 , void * V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_5 ( V_6 ) ) {
memset ( V_22 , 0 , V_21 -> V_23 ) ;
F_8 ( V_6 , V_21 -> V_23 , V_22 ) ;
}
}
static int
F_9 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 = & V_6 -> V_28 [ 0 ] . V_27 ;
struct V_26 * V_29 = & V_6 -> V_29 ;
V_25 -> V_30 = V_27 -> V_31 ;
V_25 -> V_32 = V_27 -> V_33 ;
V_25 -> V_34 = V_27 -> V_35 ;
V_25 -> V_36 = V_29 -> V_31 ;
V_25 -> V_37 = V_29 -> V_33 ;
V_25 -> V_38 = V_29 -> V_35 ;
V_25 -> V_39 = V_27 -> V_40 ;
V_25 -> V_41 = V_29 -> V_40 ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_42 * V_43 ;
struct V_26 * V_27 ;
struct V_26 * V_29 = & V_6 -> V_29 ;
T_1 V_44 , V_45 , V_46 ;
int V_47 = 0 , V_48 ;
T_1 V_49 ;
if ( V_25 -> V_41 == 1 )
return - V_50 ;
F_11 (adapter, rxo, i) {
V_27 = & V_43 -> V_27 ;
if ( ! V_27 -> V_40 && V_25 -> V_39 )
V_27 -> V_31 = 0 ;
V_27 -> V_40 = V_25 -> V_39 ;
V_44 = V_25 -> V_32 ;
V_45 = V_25 -> V_34 ;
V_46 = V_25 -> V_30 ;
if ( V_27 -> V_40 ) {
if ( V_44 > V_51 )
V_44 = V_51 ;
if ( V_45 > V_44 )
V_45 = V_44 ;
V_27 -> V_33 = V_44 ;
V_27 -> V_35 = V_45 ;
if ( V_27 -> V_31 > V_44 )
V_27 -> V_31 = V_44 ;
if ( V_27 -> V_31 < V_45 )
V_27 -> V_31 = V_45 ;
} else {
if ( V_46 > V_51 )
V_46 = V_51 ;
if ( V_27 -> V_31 != V_46 ) {
V_47 = F_12 ( V_6 , V_27 -> V_52 . V_53 ,
V_46 ) ;
if ( ! V_47 )
V_27 -> V_31 = V_46 ;
}
}
}
V_49 = V_25 -> V_36 ;
if ( V_49 > V_51 )
V_49 = V_51 ;
if ( V_29 -> V_31 != V_49 ) {
V_47 = F_12 ( V_6 , V_29 -> V_52 . V_53 , V_49 ) ;
if ( ! V_47 )
V_29 -> V_31 = V_49 ;
}
return 0 ;
}
static void
F_13 ( struct V_1 * V_2 ,
struct V_54 * V_55 , T_2 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_42 * V_43 ;
struct V_57 * V_58 ;
void * V_59 = NULL ;
int V_48 , V_60 , V_61 ;
for ( V_48 = 0 ; V_48 < V_62 ; V_48 ++ ) {
switch ( V_63 [ V_48 ] . type ) {
case V_64 :
V_59 = & V_2 -> V_55 ;
break;
case V_65 :
V_59 = & V_6 -> V_66 ;
break;
}
V_59 = ( V_67 * ) V_59 + V_63 [ V_48 ] . V_68 ;
V_56 [ V_48 ] = ( V_63 [ V_48 ] . V_69 == sizeof( V_70 ) ) ?
* ( V_70 * ) V_59 : * ( T_1 * ) V_59 ;
}
V_61 = V_62 ;
F_11 (adapter, rxo, j) {
for ( V_48 = 0 ; V_48 < V_71 ; V_48 ++ ) {
switch ( V_72 [ V_48 ] . type ) {
case V_73 :
V_59 = ( V_67 * ) & V_43 -> V_55 + V_72 [ V_48 ] . V_68 ;
break;
case V_74 :
V_59 = ( T_1 * ) F_14 ( V_6 ) +
V_43 -> V_52 . V_53 ;
break;
}
V_56 [ V_61 + V_60 * V_71 + V_48 ] =
( V_72 [ V_48 ] . V_69 == sizeof( V_70 ) ) ?
* ( V_70 * ) V_59 : * ( T_1 * ) V_59 ;
}
}
V_61 = V_62 + V_6 -> V_75 * V_71 ;
F_15 (adapter, txo, j) {
for ( V_48 = 0 ; V_48 < V_76 ; V_48 ++ ) {
V_59 = ( V_67 * ) & V_58 -> V_55 + V_77 [ V_48 ] . V_68 ;
V_56 [ V_61 + V_60 * V_76 + V_48 ] =
( V_77 [ V_48 ] . V_69 == sizeof( V_70 ) ) ?
* ( V_70 * ) V_59 : * ( T_1 * ) V_59 ;
}
}
}
static void
F_16 ( struct V_1 * V_2 , T_3 V_78 ,
T_4 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_48 , V_60 ;
switch ( V_78 ) {
case V_79 :
for ( V_48 = 0 ; V_48 < V_62 ; V_48 ++ ) {
memcpy ( V_56 , V_63 [ V_48 ] . V_80 , V_81 ) ;
V_56 += V_81 ;
}
for ( V_48 = 0 ; V_48 < V_6 -> V_75 ; V_48 ++ ) {
for ( V_60 = 0 ; V_60 < V_71 ; V_60 ++ ) {
sprintf ( V_56 , L_1 , V_48 ,
V_72 [ V_60 ] . V_80 ) ;
V_56 += V_81 ;
}
}
for ( V_48 = 0 ; V_48 < V_6 -> V_82 ; V_48 ++ ) {
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
sprintf ( V_56 , L_2 , V_48 ,
V_77 [ V_60 ] . V_80 ) ;
V_56 += V_81 ;
}
}
break;
case V_83 :
for ( V_48 = 0 ; V_48 < V_84 ; V_48 ++ ) {
memcpy ( V_56 , V_85 [ V_48 ] , V_81 ) ;
V_56 += V_81 ;
}
break;
}
}
static int F_17 ( struct V_1 * V_2 , int V_78 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_78 ) {
case V_83 :
return V_84 ;
case V_79 :
return V_62 +
V_6 -> V_75 * V_71 +
V_6 -> V_82 * V_76 ;
default:
return - V_50 ;
}
}
static int F_18 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_88 V_89 ;
struct V_90 * V_91 ;
V_67 V_92 = 0 ;
T_5 V_93 = 0 ;
bool V_94 = false ;
int V_47 ;
T_5 V_95 ;
if ( ( V_6 -> V_93 < 0 ) || ( ! ( V_2 -> V_96 & V_97 ) ) ) {
V_47 = F_19 ( V_6 , & V_94 ,
& V_92 , & V_93 , 0 ) ;
F_20 ( V_6 , V_94 ) ;
if ( V_93 ) {
F_21 ( V_87 , V_93 * 10 ) ;
} else {
switch ( V_92 ) {
case V_98 :
F_21 ( V_87 , V_99 ) ;
break;
case V_100 :
F_21 ( V_87 , V_101 ) ;
break;
case V_102 :
F_21 ( V_87 , V_103 ) ;
break;
case V_104 :
F_21 ( V_87 , V_105 ) ;
break;
case V_106 :
F_21 ( V_87 , 0 ) ;
break;
}
}
V_89 . V_69 = sizeof( struct V_107 ) ;
V_89 . V_108 = F_22 ( & V_6 -> V_15 -> V_109 ,
V_89 . V_69 , & V_89 . V_110 ,
V_111 ) ;
if ( ! V_89 . V_108 ) {
F_23 ( & V_6 -> V_15 -> V_109 , L_3 ) ;
return - V_112 ;
}
V_47 = F_24 ( V_6 , & V_89 ) ;
if ( ! V_47 ) {
V_91 = V_89 . V_108 ;
V_95 = F_25 ( V_91 -> V_113 ) ;
switch ( V_95 ) {
case V_114 :
case V_115 :
case V_116 :
V_87 -> V_117 = V_118 ;
break;
default:
V_87 -> V_117 = V_119 ;
break;
}
switch ( V_95 ) {
case V_120 :
case V_121 :
V_87 -> V_122 = V_123 ;
V_87 -> V_124 = V_125 ;
break;
default:
V_87 -> V_122 = V_126 ;
V_87 -> V_124 = V_127 ;
break;
}
}
V_6 -> V_93 = F_26 ( V_87 ) ;
V_6 -> V_128 = V_87 -> V_117 ;
V_6 -> V_124 = V_87 -> V_124 ;
V_6 -> V_122 = V_87 -> V_122 ;
F_27 ( & V_6 -> V_15 -> V_109 , V_89 . V_69 , V_89 . V_108 ,
V_89 . V_110 ) ;
} else {
F_21 ( V_87 , V_6 -> V_93 ) ;
V_87 -> V_117 = V_6 -> V_128 ;
V_87 -> V_124 = V_6 -> V_124 ;
V_87 -> V_122 = V_6 -> V_122 ;
}
V_87 -> V_129 = V_130 ;
V_87 -> V_131 = V_6 -> V_132 ;
switch ( V_87 -> V_117 ) {
case V_118 :
V_87 -> V_133 = ( V_134 | V_135 ) ;
break;
case V_119 :
V_87 -> V_133 = ( V_134 | V_136 ) ;
break;
case V_137 :
V_87 -> V_133 = ( V_134 | V_138 ) ;
break;
}
if ( V_87 -> V_122 ) {
V_87 -> V_133 |= V_139 ;
V_87 -> V_133 |= V_140 ;
V_87 -> V_141 |= ( V_142 |
V_143 ) ;
}
return 0 ;
}
static void
F_28 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_145 -> V_146 = V_6 -> V_28 [ 0 ] . V_52 . V_23 ;
V_145 -> V_147 = V_6 -> V_148 [ 0 ] . V_52 . V_23 ;
V_145 -> V_149 = F_29 ( & V_6 -> V_28 [ 0 ] . V_52 . V_150 ) ;
V_145 -> V_151 = F_29 ( & V_6 -> V_148 [ 0 ] . V_52 . V_150 ) ;
}
static void
F_30 ( struct V_1 * V_2 , struct V_152 * V_87 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_31 ( V_6 , & V_87 -> V_153 , & V_87 -> V_154 ) ;
V_87 -> V_122 = 0 ;
}
static int
F_32 ( struct V_1 * V_2 , struct V_152 * V_87 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_47 ;
if ( V_87 -> V_122 != 0 )
return - V_50 ;
V_6 -> V_155 = V_87 -> V_153 ;
V_6 -> V_156 = V_87 -> V_154 ;
V_47 = F_33 ( V_6 ,
V_6 -> V_155 , V_6 -> V_156 ) ;
if ( V_47 )
F_34 ( & V_6 -> V_15 -> V_109 , L_4 ) ;
return V_47 ;
}
static int
F_35 ( struct V_1 * V_2 ,
enum V_157 V_158 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_158 ) {
case V_159 :
F_36 ( V_6 , V_6 -> V_160 ,
& V_6 -> V_161 ) ;
return 1 ;
case V_162 :
F_37 ( V_6 , V_6 -> V_160 , 0 , 0 ,
V_163 ) ;
break;
case V_164 :
F_37 ( V_6 , V_6 -> V_160 , 0 , 0 ,
V_165 ) ;
break;
case V_166 :
F_37 ( V_6 , V_6 -> V_160 , 0 , 0 ,
V_6 -> V_161 ) ;
}
return 0 ;
}
static bool
F_38 ( struct V_5 * V_6 )
{
if ( ! F_5 ( V_6 ) )
return false ;
else
return true ;
}
static void
F_39 ( struct V_1 * V_2 , struct V_167 * V_168 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_38 ( V_6 ) )
V_168 -> V_133 = V_169 ;
if ( V_6 -> V_168 )
V_168 -> V_170 = V_169 ;
else
V_168 -> V_170 = 0 ;
memset ( & V_168 -> V_171 , 0 , sizeof( V_168 -> V_171 ) ) ;
}
static int
F_40 ( struct V_1 * V_2 , struct V_167 * V_168 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_168 -> V_170 & ~ V_169 )
return - V_50 ;
if ( ( V_168 -> V_170 & V_169 ) && F_38 ( V_6 ) )
V_6 -> V_168 = true ;
else
V_6 -> V_168 = false ;
return 0 ;
}
static int
F_41 ( struct V_5 * V_6 )
{
int V_172 , V_48 ;
struct V_88 V_173 ;
static const V_70 V_174 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_173 . V_69 = sizeof( struct V_175 ) ;
V_173 . V_108 = F_22 ( & V_6 -> V_15 -> V_109 , V_173 . V_69 ,
& V_173 . V_110 , V_111 ) ;
if ( ! V_173 . V_108 ) {
F_23 ( & V_6 -> V_15 -> V_109 , L_5 ) ;
return - V_112 ;
}
for ( V_48 = 0 ; V_48 < 2 ; V_48 ++ ) {
V_172 = F_42 ( V_6 , V_174 [ V_48 ] ,
4096 , & V_173 ) ;
if ( V_172 != 0 )
goto V_176;
}
V_176:
F_27 ( & V_6 -> V_15 -> V_109 , V_173 . V_69 , V_173 . V_108 ,
V_173 . V_110 ) ;
return V_172 ;
}
static V_70 F_43 ( struct V_5 * V_6 , V_67 V_177 ,
V_70 * V_47 )
{
F_44 ( V_6 , V_6 -> V_160 ,
V_177 , 1 ) ;
* V_47 = F_45 ( V_6 , V_6 -> V_160 ,
V_177 , 1500 ,
2 , 0xabc ) ;
F_44 ( V_6 , V_6 -> V_160 ,
V_178 , 1 ) ;
return * V_47 ;
}
static void
F_46 ( struct V_1 * V_2 , struct V_179 * V_180 , V_70 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_94 ;
V_67 V_92 = 0 ;
T_5 V_181 = 0 ;
memset ( V_56 , 0 , sizeof( V_70 ) * V_84 ) ;
if ( V_180 -> V_96 & V_182 ) {
if ( F_43 ( V_6 , V_183 ,
& V_56 [ 0 ] ) != 0 ) {
V_180 -> V_96 |= V_184 ;
}
if ( F_43 ( V_6 , V_185 ,
& V_56 [ 1 ] ) != 0 ) {
V_180 -> V_96 |= V_184 ;
}
if ( F_43 ( V_6 , V_186 ,
& V_56 [ 2 ] ) != 0 ) {
V_180 -> V_96 |= V_184 ;
}
}
if ( F_41 ( V_6 ) != 0 ) {
V_56 [ 3 ] = 1 ;
V_180 -> V_96 |= V_184 ;
}
if ( F_19 ( V_6 , & V_94 , & V_92 ,
& V_181 , 0 ) != 0 ) {
V_180 -> V_96 |= V_184 ;
V_56 [ 4 ] = - 1 ;
} else if ( ! V_92 ) {
V_180 -> V_96 |= V_184 ;
V_56 [ 4 ] = 1 ;
}
}
static int
F_47 ( struct V_1 * V_2 , struct V_187 * V_188 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_189 [ V_190 ] ;
V_189 [ V_190 - 1 ] = 0 ;
strcpy ( V_189 , V_188 -> V_56 ) ;
return F_48 ( V_6 , V_189 ) ;
}
static int
F_49 ( struct V_1 * V_2 )
{
return V_191 ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_192 * V_193 ,
T_4 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_88 V_194 ;
struct V_195 * V_91 ;
int V_47 ;
if ( ! V_193 -> V_23 )
return - V_50 ;
V_193 -> V_196 = V_197 | ( V_6 -> V_15 -> V_198 << 16 ) ;
memset ( & V_194 , 0 , sizeof( struct V_88 ) ) ;
V_194 . V_69 = sizeof( struct V_199 ) ;
V_194 . V_108 = F_22 ( & V_6 -> V_15 -> V_109 , V_194 . V_69 ,
& V_194 . V_110 , V_111 ) ;
if ( ! V_194 . V_108 ) {
F_23 ( & V_6 -> V_15 -> V_109 ,
L_6 ) ;
return - V_112 ;
}
V_47 = F_51 ( V_6 , & V_194 ) ;
if ( ! V_47 ) {
V_91 = V_194 . V_108 ;
memcpy ( V_56 , V_91 -> V_200 + V_193 -> V_68 , V_193 -> V_23 ) ;
}
F_27 ( & V_6 -> V_15 -> V_109 , V_194 . V_69 , V_194 . V_108 ,
V_194 . V_110 ) ;
return V_47 ;
}
