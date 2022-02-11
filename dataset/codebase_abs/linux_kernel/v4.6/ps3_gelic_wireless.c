static inline int F_1 ( void )
{
return 0 <= F_2 ( 2 , 0 , 0 ) ;
}
static inline int F_3 ( void )
{
return 0 <= F_2 ( 2 , 2 , 0 ) ;
}
static const char * F_4 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
case V_8 :
return L_6 ;
case V_9 :
return L_7 ;
case V_10 :
return L_8 ;
case V_11 :
return L_9 ;
case V_12 :
return L_10 ;
case V_13 :
return L_11 ;
default:
break;
}
return L_12 ;
}
static inline const char * F_4 ( enum V_1 V_2 )
{
return L_12 ;
}
static void F_5 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
T_1 V_22 , V_23 ;
F_6 ( L_13 , V_24 ) ;
V_17 = F_7 ( V_15 , struct V_16 , V_15 ) ;
F_8 ( V_25 [ V_17 -> V_17 ] . V_26 &&
V_25 [ V_17 -> V_17 ] . V_27 ) ;
V_21 = V_17 -> V_21 ;
V_19 = F_9 ( F_10 ( V_21 ) ) ;
if ( V_25 [ V_17 -> V_17 ] . V_26 ) {
V_22 = ( V_17 -> V_28 ) ?
F_11 ( F_12 ( V_17 -> V_28 ) ) :
0 ;
V_23 = V_17 -> V_29 ;
} else {
V_22 = 0 ;
V_23 = 0 ;
}
F_13 ( & V_21 -> V_30 ) ;
F_6 ( L_14 , V_24 , F_4 ( V_17 -> V_17 ) ) ;
V_17 -> V_31 = F_14 ( F_15 ( V_19 ) , F_16 ( V_19 ) ,
V_32 ,
V_17 -> V_17 , V_22 , V_23 ,
& V_17 -> V_33 , & V_17 -> V_34 ) ;
if ( V_17 -> V_31 ) {
F_17 ( & V_17 -> V_35 ) ;
F_18 ( L_15 , V_24 ) ;
return;
}
F_19 ( & V_21 -> V_30 ) ;
if ( V_25 [ V_17 -> V_17 ] . V_27 ) {
V_22 = F_11 ( F_12 ( V_17 -> V_28 ) ) ;
V_23 = V_17 -> V_29 ;
} else {
V_22 = 0 ;
V_23 = 0 ;
}
V_17 -> V_31 = F_14 ( F_15 ( V_19 ) , F_16 ( V_19 ) ,
V_36 ,
V_17 -> V_33 , V_22 , V_23 ,
& V_17 -> V_37 , & V_17 -> V_34 ) ;
#ifdef F_20
if ( V_17 -> V_31 || V_17 -> V_37 ) {
F_6 ( L_16 , V_24 ,
V_17 -> V_33 , V_22 , V_23 ) ;
F_6 ( L_17 ,
V_24 , V_17 -> V_31 , V_17 -> V_37 , V_17 -> V_34 ) ;
}
#endif
F_17 ( & V_17 -> V_35 ) ;
F_6 ( L_18 , V_24 , F_4 ( V_17 -> V_17 ) ) ;
}
static struct V_16 * F_21 ( struct V_20 * V_21 ,
unsigned int V_38 ,
void * V_28 ,
unsigned int V_29 )
{
struct V_16 * V_17 ;
V_17 = F_22 ( sizeof( * V_17 ) , V_39 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_17 = V_38 ;
V_17 -> V_28 = V_28 ;
V_17 -> V_29 = V_29 ;
V_17 -> V_21 = V_21 ;
F_23 ( & V_17 -> V_15 , F_5 ) ;
F_13 ( & V_17 -> V_35 ) ;
F_24 ( V_21 -> V_40 , & V_17 -> V_15 ) ;
F_19 ( & V_17 -> V_35 ) ;
return V_17 ;
}
static T_2 F_25 ( struct V_41 * V_42 )
{
struct V_20 * V_21 = F_26 ( F_27 ( V_42 ) ) ;
T_2 V_43 ;
F_6 ( L_13 , V_24 ) ;
F_28 ( & V_21 -> V_44 ) ;
if ( V_21 -> V_45 == V_46 )
V_43 = 1 ;
else
V_43 = 0 ;
F_29 ( & V_21 -> V_44 ) ;
F_6 ( L_19 , V_24 ) ;
return V_43 ;
}
static void F_30 ( struct V_20 * V_21 , T_3 * V_47 )
{
union V_48 V_49 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
if ( V_47 )
memcpy ( V_49 . V_50 . V_51 , V_47 , V_52 ) ;
V_49 . V_50 . V_53 = V_54 ;
F_31 ( F_32 ( F_10 ( V_21 ) ) , V_55 ,
& V_49 , NULL ) ;
}
static int F_33 ( struct V_41 * V_56 ,
struct V_57 * V_58 ,
union V_48 * V_59 , char * V_60 )
{
strcpy ( V_59 -> V_61 , L_20 ) ;
return 0 ;
}
static void F_34 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = F_9 ( F_10 ( V_21 ) ) ;
T_1 V_62 , V_63 ;
int V_31 ;
if ( ! F_35 ( V_64 , & V_21 -> V_65 ) ) {
V_31 = F_14 ( F_15 ( V_19 ) , F_16 ( V_19 ) ,
V_66 , 0 , 0 , 0 ,
& V_62 ,
& V_63 ) ;
if ( V_31 ) {
if ( V_31 != V_67 )
F_18 ( L_21 , V_24 ) ;
V_21 -> V_68 = 0x07ff ;
} else
V_21 -> V_68 = V_62 >> 48 ;
}
}
static int F_36 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_59 , char * V_60 )
{
struct V_69 * V_70 = & V_59 -> V_49 ;
struct V_71 * V_72 = (struct V_71 * ) V_60 ;
struct V_20 * V_21 = F_26 ( F_27 ( V_42 ) ) ;
unsigned int V_73 , V_74 ;
F_6 ( L_13 , V_24 ) ;
V_70 -> V_75 = sizeof( struct V_71 ) ;
memset ( V_72 , 0 , sizeof( struct V_71 ) ) ;
V_72 -> V_76 = V_77 ;
V_72 -> V_78 = 22 ;
F_34 ( V_21 ) ;
for ( V_73 = 0 , V_74 = 0 ;
V_73 < V_79 && V_74 < V_80 ; V_73 ++ )
if ( V_21 -> V_68 & ( 1 << V_73 ) ) {
V_72 -> V_81 [ V_74 ] . V_73 = V_73 + 1 ;
V_72 -> V_81 [ V_74 ] . V_82 = V_83 [ V_73 ] ;
V_72 -> V_81 [ V_74 ] . V_84 = 6 ;
V_74 ++ ;
}
V_72 -> V_85 = V_74 ;
V_72 -> V_86 = V_74 ;
V_72 -> V_87 = V_74 ;
V_72 -> V_88 = V_74 ;
for ( V_73 = 0 ; V_73 < V_89 ; V_73 ++ )
V_72 -> V_90 [ V_73 ] = V_91 [ V_73 ] ;
V_72 -> V_92 = V_73 ;
V_72 -> V_93 . V_94 = 100 ;
V_72 -> V_93 . V_95 = 100 ;
V_72 -> V_96 . V_94 = 50 ;
V_72 -> V_96 . V_95 = 50 ;
V_72 -> V_97 = 0 ;
F_37 ( V_72 -> V_98 ) ;
F_38 ( V_72 -> V_98 , V_55 ) ;
F_38 ( V_72 -> V_98 , V_99 ) ;
V_72 -> V_100 = V_101 |
V_102 | V_103 |
V_104 ;
if ( F_1 () )
V_72 -> V_100 |= V_105 ;
V_72 -> V_106 [ 0 ] = 5 ;
V_72 -> V_106 [ 1 ] = 13 ;
V_72 -> V_106 [ 2 ] = 32 ;
V_72 -> V_107 = 3 ;
V_72 -> V_108 = V_109 ;
V_72 -> V_110 = V_111 ;
F_6 ( L_19 , V_24 ) ;
return 0 ;
}
static int F_39 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_112 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
struct V_113 * V_114 ;
T_3 * V_115 = NULL ;
T_4 V_116 = 0 ;
if ( V_112 -> V_49 . V_75 == sizeof( struct V_113 ) &&
V_112 -> V_49 . V_117 & V_118 ) {
V_114 = (struct V_113 * ) V_60 ;
V_115 = V_114 -> V_115 ;
V_116 = V_114 -> V_116 ;
F_6 ( L_22 , V_24 , V_115 ) ;
}
return F_41 ( V_21 , 1 , V_115 , V_116 ) ;
}
static T_4 F_42 ( T_3 * V_119 ,
struct V_120 * V_121 )
{
const T_3 * V_122 ;
T_3 * V_123 = V_119 ;
int V_124 ;
int V_125 ;
F_6 ( L_23 , V_24 , V_121 -> V_126 ) ;
switch ( F_43 ( V_121 -> V_126 ) & V_127 ) {
case V_128 :
V_124 = 0 ;
break;
case V_129 :
V_124 = 1 ;
break;
default:
return 0 ;
}
switch ( F_43 ( V_121 -> V_126 ) & V_130 ) {
case V_131 :
V_125 = 0 ;
break;
case V_132 :
V_125 = 1 ;
break;
default:
if ( V_124 ) {
V_125 = 1 ;
F_18 ( L_24 ,
V_24 ) ;
} else {
V_125 = 0 ;
F_18 ( L_25 ,
V_24 ) ;
}
}
if ( V_124 )
V_122 = V_133 ;
else
V_122 = V_134 ;
if ( V_124 )
* V_119 ++ = V_135 ;
else
* V_119 ++ = V_136 ;
V_119 ++ ;
if ( ! V_124 ) {
memcpy ( V_119 , V_134 , V_137 ) ;
V_119 += V_137 ;
* V_119 ++ = 0x01 ;
}
* V_119 ++ = 0x01 ;
* V_119 ++ = 0x00 ;
memcpy ( V_119 , V_122 , V_137 ) ;
V_119 += V_137 ;
if ( V_125 )
* V_119 ++ = 0x04 ;
else
* V_119 ++ = 0x02 ;
* V_119 ++ = 0x01 ;
* V_119 ++ = 0x00 ;
memcpy ( V_119 , V_122 , V_137 ) ;
V_119 += V_137 ;
if ( V_125 )
* V_119 ++ = 0x04 ;
else
* V_119 ++ = 0x02 ;
* V_119 ++ = 0x01 ;
* V_119 ++ = 0x00 ;
memcpy ( V_119 , V_122 , V_137 ) ;
V_119 += V_137 ;
* V_119 ++ = 0x02 ;
* V_119 ++ = 0x00 ;
* V_119 ++ = 0x00 ;
V_123 [ 1 ] = ( V_119 - V_123 - 2 ) ;
F_6 ( L_19 , V_24 ) ;
return V_119 - V_123 ;
}
static void F_44 ( T_3 * V_49 , T_4 V_138 ,
struct V_139 * V_139 )
{
T_4 V_140 = V_138 ;
T_3 * V_141 = V_49 ;
T_3 V_142 ;
T_3 V_143 ;
F_6 ( L_26 , V_24 ,
V_49 , V_138 ) ;
memset ( V_139 , 0 , sizeof( struct V_139 ) ) ;
while ( 2 <= V_140 ) {
V_143 = * V_141 ++ ;
V_142 = * V_141 ++ ;
V_140 -= 2 ;
if ( V_140 < V_142 )
break;
switch ( V_143 ) {
case V_136 :
if ( ( V_137 + 1 <= V_142 ) &&
! memcmp ( V_141 , V_134 , V_137 ) &&
V_141 [ V_137 ] == 0x01 ) {
V_139 -> V_144 . V_49 = V_141 - 2 ;
V_139 -> V_144 . V_138 = V_142 + 2 ;
}
break;
case V_135 :
V_139 -> V_124 . V_49 = V_141 - 2 ;
V_139 -> V_124 . V_138 = V_142 + 2 ;
break;
default:
F_6 ( L_27 , V_24 ,
V_143 , V_142 ) ;
break;
}
V_141 += V_142 ;
V_140 -= V_142 ;
}
F_6 ( L_28 , V_24 ,
V_139 -> V_144 . V_49 , V_139 -> V_144 . V_138 ,
V_139 -> V_124 . V_49 , V_139 -> V_124 . V_138 ) ;
}
static char * F_45 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
char * V_145 ,
char * V_146 ,
struct V_147 * V_148 )
{
struct V_149 V_150 ;
struct V_120 * V_121 = V_148 -> V_151 ;
char * V_63 ;
T_3 V_152 ;
unsigned int V_73 , V_153 , V_138 ;
T_3 V_119 [ 64 ] ;
F_6 ( L_13 , V_24 ) ;
V_150 . V_17 = V_55 ;
V_150 . V_154 . V_50 . V_53 = V_54 ;
memcpy ( V_150 . V_154 . V_50 . V_51 , & V_121 -> V_47 [ 2 ] , V_52 ) ;
V_145 = F_46 ( V_58 , V_145 , V_146 , & V_150 , V_155 ) ;
V_150 . V_17 = V_156 ;
V_150 . V_154 . V_49 . V_117 = 1 ;
V_150 . V_154 . V_49 . V_75 = F_47 ( V_121 -> V_115 , 32 ) ;
V_145 = F_48 ( V_58 , V_145 , V_146 , & V_150 , V_121 -> V_115 ) ;
V_150 . V_17 = V_157 ;
V_150 . V_154 . V_81 . V_82 = F_43 ( V_121 -> V_158 ) ;
V_150 . V_154 . V_81 . V_84 = 0 ;
V_150 . V_154 . V_81 . V_73 = 0 ;
V_145 = F_46 ( V_58 , V_145 , V_146 , & V_150 , V_159 ) ;
V_150 . V_17 = V_160 ;
V_150 . V_154 . V_90 . V_161 = V_150 . V_154 . V_90 . V_162 = 0 ;
V_63 = V_145 + F_49 ( V_58 ) ;
V_73 = 0 ;
V_153 = 0 ;
F_6 ( L_29 , V_24 ,
V_148 -> V_163 , V_148 -> V_164 ) ;
while ( V_73 < V_148 -> V_163 ) {
if ( V_153 < V_148 -> V_164 &&
( ( V_121 -> V_165 [ V_153 ] & 0x7f ) < ( V_121 -> V_152 [ V_73 ] & 0x7f ) ) )
V_152 = V_121 -> V_165 [ V_153 ++ ] & 0x7f ;
else
V_152 = V_121 -> V_152 [ V_73 ++ ] & 0x7f ;
V_150 . V_154 . V_90 . V_166 = V_152 * 500000 ;
V_63 = F_50 ( V_58 , V_145 , V_63 , V_146 , & V_150 ,
V_167 ) ;
}
while ( V_153 < V_148 -> V_164 ) {
V_150 . V_154 . V_90 . V_166 = ( V_121 -> V_165 [ V_153 ++ ] & 0x7f ) * 500000 ;
V_63 = F_50 ( V_58 , V_145 , V_63 , V_146 , & V_150 ,
V_167 ) ;
}
if ( F_49 ( V_58 ) < ( V_63 - V_145 ) )
V_145 = V_63 ;
V_150 . V_17 = V_168 ;
if ( F_43 ( V_121 -> V_169 ) & V_170 )
V_150 . V_154 . V_49 . V_117 = V_171 | V_172 ;
else
V_150 . V_154 . V_49 . V_117 = V_173 ;
V_150 . V_154 . V_49 . V_75 = 0 ;
V_145 = F_48 ( V_58 , V_145 , V_146 , & V_150 , V_121 -> V_115 ) ;
V_150 . V_17 = V_174 ;
if ( F_43 ( V_121 -> V_169 ) &
( V_175 | V_176 ) ) {
if ( F_43 ( V_121 -> V_169 ) & V_175 )
V_150 . V_154 . V_177 = V_178 ;
else
V_150 . V_154 . V_177 = V_179 ;
V_145 = F_46 ( V_58 , V_145 , V_146 , & V_150 , V_180 ) ;
}
V_150 . V_17 = V_181 ;
V_150 . V_154 . V_94 . V_182 = V_183 |
V_184 | V_185 ;
V_150 . V_154 . V_94 . V_95 = F_43 ( V_121 -> V_186 ) ;
V_150 . V_154 . V_94 . V_94 = F_43 ( V_121 -> V_186 ) ;
V_150 . V_154 . V_94 . V_187 = 0 ;
V_145 = F_46 ( V_58 , V_145 , V_146 , & V_150 , V_188 ) ;
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
if ( F_43 ( V_121 -> V_34 ) <= sizeof( * V_121 ) ) {
V_138 = F_42 ( V_119 , V_121 ) ;
if ( V_138 ) {
V_150 . V_17 = V_189 ;
V_150 . V_154 . V_49 . V_75 = V_138 ;
V_145 = F_48 ( V_58 , V_145 , V_146 , & V_150 , V_119 ) ;
}
} else {
struct V_139 V_139 ;
T_4 V_190 ;
V_190 = F_43 ( V_121 -> V_34 ) - sizeof( * V_121 ) ;
F_44 ( V_121 -> V_191 , V_190 , & V_139 ) ;
if ( V_139 . V_144 . V_138 && ( V_139 . V_144 . V_138 <= sizeof( V_119 ) ) ) {
memcpy ( V_119 , V_139 . V_144 . V_49 , V_139 . V_144 . V_138 ) ;
V_150 . V_17 = V_189 ;
V_150 . V_154 . V_49 . V_75 = V_139 . V_144 . V_138 ;
V_145 = F_48 ( V_58 , V_145 , V_146 , & V_150 , V_119 ) ;
}
if ( V_139 . V_124 . V_138 && ( V_139 . V_124 . V_138 <= sizeof( V_119 ) ) ) {
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
memcpy ( V_119 , V_139 . V_124 . V_49 , V_139 . V_124 . V_138 ) ;
V_150 . V_17 = V_189 ;
V_150 . V_154 . V_49 . V_75 = V_139 . V_124 . V_138 ;
V_145 = F_48 ( V_58 , V_145 , V_146 , & V_150 , V_119 ) ;
}
}
F_6 ( L_19 , V_24 ) ;
return V_145 ;
}
static int F_51 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_112 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
struct V_147 * V_192 ;
char * V_145 = V_60 ;
char * V_146 = V_145 + V_112 -> V_49 . V_75 ;
int V_43 = 0 ;
unsigned long V_193 = V_194 ;
F_6 ( L_13 , V_24 ) ;
if ( F_52 ( & V_21 -> V_195 ) )
return - V_196 ;
switch ( V_21 -> V_197 ) {
case V_198 :
V_43 = - V_196 ;
goto V_199;
case V_200 :
V_43 = - V_201 ;
goto V_199;
case V_202 :
break;
}
F_53 (scan_info, &wl->network_list, list) {
if ( V_21 -> V_203 == 0 ||
F_54 ( V_192 -> V_204 + V_21 -> V_203 ,
V_193 ) )
V_145 = F_45 ( V_42 , V_58 ,
V_145 , V_146 ,
V_192 ) ;
else
F_6 ( L_30 , V_24 ) ;
if ( V_146 - V_145 <= V_155 ) {
V_43 = - V_205 ;
goto V_199;
}
}
V_112 -> V_49 . V_75 = V_145 - V_60 ;
V_112 -> V_49 . V_117 = 0 ;
V_199:
F_29 ( & V_21 -> V_195 ) ;
F_6 ( L_31 , V_24 , V_43 , V_112 -> V_49 . V_75 ) ;
return V_43 ;
}
static void F_55 ( struct V_20 * V_21 )
{
struct V_147 * V_192 ;
int V_73 ;
V_73 = 0 ;
F_53 (scan_info, &wl->network_list, list) {
F_6 ( L_32 , V_24 , V_73 ++ ) ;
F_6 ( L_33 ,
V_192 -> V_206 , V_192 -> V_207 ,
V_192 -> V_204 ) ;
F_6 ( L_34 ,
V_192 -> V_163 , V_192 -> V_164 ,
V_192 -> V_116 ) ;
F_6 ( L_35 , & V_192 -> V_151 -> V_47 [ 2 ] ) ;
F_6 ( L_36 , V_192 -> V_151 -> V_115 ) ;
}
}
static int F_56 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
struct V_208 * V_209 = & V_49 -> V_209 ;
struct V_20 * V_21 = F_26 ( F_27 ( V_42 ) ) ;
unsigned long V_210 ;
int V_43 = 0 ;
F_6 ( L_37 , V_24 , V_209 -> V_117 & V_211 ) ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
switch ( V_209 -> V_117 & V_211 ) {
case V_213 :
if ( V_209 -> V_166 & V_214 ) {
F_6 ( L_38 , V_24 ) ;
V_21 -> V_215 = V_216 ;
V_21 -> V_217 = V_218 ;
V_21 -> V_219 = V_218 ;
}
if ( V_209 -> V_166 & V_220 ) {
F_6 ( L_39 , V_24 ) ;
V_21 -> V_215 = V_221 ;
V_21 -> V_217 = V_222 ;
V_21 -> V_219 = V_222 ;
V_21 -> V_223 = V_224 ;
}
if ( V_209 -> V_166 & V_225 ) {
if ( ! F_3 () )
F_18 ( L_40 , V_24 ) ;
if ( F_1 () ) {
V_21 -> V_215 = V_226 ;
V_21 -> V_217 = V_227 ;
V_21 -> V_219 =
V_227 ;
V_21 -> V_223 = V_224 ;
} else
V_43 = - V_228 ;
}
break;
case V_229 :
if ( V_209 -> V_166 &
( V_230 | V_231 ) ) {
F_6 ( L_41 , V_24 ) ;
V_21 -> V_219 = V_218 ;
}
if ( V_209 -> V_166 & V_232 ) {
F_6 ( L_42 , V_24 ) ;
V_21 -> V_219 = V_222 ;
}
if ( V_209 -> V_166 & V_233 ) {
F_6 ( L_43 , V_24 ) ;
V_21 -> V_219 = V_227 ;
}
if ( V_209 -> V_166 & V_234 ) {
F_6 ( L_44 , V_24 ) ;
V_21 -> V_219 = V_235 ;
}
break;
case V_236 :
if ( V_209 -> V_166 &
( V_230 | V_231 ) ) {
F_6 ( L_41 , V_24 ) ;
V_21 -> V_217 = V_218 ;
}
if ( V_209 -> V_166 & V_232 ) {
F_6 ( L_42 , V_24 ) ;
V_21 -> V_217 = V_222 ;
}
if ( V_209 -> V_166 & V_233 ) {
F_6 ( L_43 , V_24 ) ;
V_21 -> V_217 = V_227 ;
}
if ( V_209 -> V_166 & V_234 ) {
F_6 ( L_44 , V_24 ) ;
V_21 -> V_217 = V_235 ;
}
break;
case V_237 :
if ( V_209 -> V_166 & V_238 ) {
F_6 ( L_45 , V_24 ) ;
V_21 -> V_223 = V_239 ;
} else if ( V_209 -> V_166 & V_240 ) {
F_6 ( L_46 , V_24 ) ;
V_21 -> V_223 = V_224 ;
} else
V_43 = - V_228 ;
break;
case V_241 :
if ( V_209 -> V_166 ) {
F_6 ( L_47 , V_24 ) ;
V_21 -> V_215 = V_221 ;
} else {
F_6 ( L_48 , V_24 ) ;
V_21 -> V_215 = V_216 ;
}
break;
case V_242 :
if ( V_209 -> V_166 & V_243 )
break;
default:
V_43 = - V_244 ;
break;
}
if ( ! V_43 )
F_58 ( V_245 , & V_21 -> V_65 ) ;
F_59 ( & V_21 -> V_212 , V_210 ) ;
F_6 ( L_49 , V_24 , V_43 ) ;
return V_43 ;
}
static int F_60 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_59 , char * V_60 )
{
struct V_208 * V_209 = & V_59 -> V_209 ;
struct V_20 * V_21 = F_26 ( F_27 ( V_42 ) ) ;
unsigned long V_210 ;
int V_43 = 0 ;
F_6 ( L_37 , V_24 , V_209 -> V_117 & V_211 ) ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
switch ( V_209 -> V_117 & V_211 ) {
case V_213 :
switch ( V_21 -> V_215 ) {
case V_221 :
V_209 -> V_166 |= V_220 ;
break;
case V_226 :
V_209 -> V_166 |= V_225 ;
break;
default:
V_209 -> V_166 |= V_214 ;
}
break;
case V_237 :
if ( V_21 -> V_223 == V_239 )
V_209 -> V_166 = V_238 ;
else if ( V_21 -> V_223 == V_224 )
V_209 -> V_166 = V_240 ;
break;
case V_241 :
switch ( V_21 -> V_215 ) {
case V_221 :
case V_226 :
V_209 -> V_166 = 1 ;
break;
default:
V_209 -> V_166 = 0 ;
break;
}
break;
default:
V_43 = - V_244 ;
}
F_59 ( & V_21 -> V_212 , V_210 ) ;
F_6 ( L_49 , V_24 , V_43 ) ;
return V_43 ;
}
static int F_61 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
unsigned long V_210 ;
F_6 ( L_50 , V_24 ,
V_49 -> V_115 . V_75 , V_49 -> V_115 . V_117 ) ;
if ( V_246 < V_49 -> V_115 . V_75 )
return - V_228 ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
if ( V_49 -> V_115 . V_117 ) {
V_21 -> V_116 = V_49 -> V_115 . V_75 ;
memcpy ( V_21 -> V_115 , V_60 , V_21 -> V_116 ) ;
F_6 ( L_51 , V_24 , V_60 ) ;
F_58 ( V_247 , & V_21 -> V_65 ) ;
} else {
F_6 ( L_52 , V_24 ) ;
F_62 ( V_247 , & V_21 -> V_65 ) ;
}
F_58 ( V_245 , & V_21 -> V_65 ) ;
F_59 ( & V_21 -> V_212 , V_210 ) ;
F_63 ( V_42 ) ;
F_6 ( L_19 , V_24 ) ;
return 0 ;
}
static int F_64 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
unsigned long V_210 ;
F_6 ( L_13 , V_24 ) ;
F_28 ( & V_21 -> V_44 ) ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
if ( F_65 ( V_247 , & V_21 -> V_65 ) ||
V_21 -> V_45 == V_46 ) {
memcpy ( V_60 , V_21 -> V_115 , V_21 -> V_116 ) ;
V_49 -> V_115 . V_75 = V_21 -> V_116 ;
V_49 -> V_115 . V_117 = 1 ;
} else
V_49 -> V_115 . V_117 = 0 ;
F_29 ( & V_21 -> V_44 ) ;
F_59 ( & V_21 -> V_212 , V_210 ) ;
F_6 ( L_53 , V_24 , V_49 -> V_115 . V_75 ) ;
return 0 ;
}
static int F_66 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
struct V_69 * V_248 = & V_49 -> V_249 ;
T_5 V_117 ;
unsigned long V_210 ;
int V_250 , V_251 ;
int V_43 = 0 ;
F_6 ( L_13 , V_24 ) ;
V_117 = V_248 -> V_117 & V_252 ;
V_250 = V_248 -> V_117 & V_253 ;
F_6 ( L_54 , V_24 , V_250 ) ;
F_6 ( L_55 , V_24 , V_248 -> V_75 ) ;
F_6 ( L_56 , V_24 , V_248 -> V_117 & V_252 ) ;
if ( V_109 < V_250 )
return - V_228 ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
if ( V_250 ) {
V_251 = 1 ;
V_250 -- ;
} else {
V_251 = 0 ;
V_250 = V_21 -> V_254 ;
}
if ( V_117 & V_172 ) {
if ( ! V_117 && V_251 ) {
V_21 -> V_254 = V_250 ;
goto V_35;
}
if ( V_117 & V_173 ) {
if ( ! V_251 ) {
V_21 -> V_217 = V_235 ;
V_21 -> V_219 =
V_235 ;
V_21 -> V_255 = 0 ;
} else
F_62 ( V_250 , & V_21 -> V_255 ) ;
}
if ( V_117 & V_256 )
V_21 -> V_223 = V_224 ;
if ( V_117 & V_257 ) {
F_18 ( L_57 , V_24 ) ;
V_21 -> V_223 = V_239 ;
}
} else {
if ( V_258 < V_248 -> V_75 ) {
V_43 = - V_228 ;
goto V_35;
}
V_21 -> V_259 [ V_250 ] = V_248 -> V_75 ;
memcpy ( V_21 -> V_260 [ V_250 ] , V_60 , V_248 -> V_75 ) ;
F_58 ( V_250 , & V_21 -> V_255 ) ;
V_21 -> V_219 = V_218 ;
V_21 -> V_217 = V_218 ;
}
F_58 ( V_245 , & V_21 -> V_65 ) ;
V_35:
F_59 ( & V_21 -> V_212 , V_210 ) ;
F_6 ( L_19 , V_24 ) ;
return V_43 ;
}
static int F_67 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
struct V_69 * V_248 = & V_49 -> V_249 ;
unsigned long V_210 ;
unsigned int V_250 , V_251 ;
int V_43 = 0 ;
F_6 ( L_13 , V_24 ) ;
V_250 = V_248 -> V_117 & V_253 ;
F_6 ( L_58 , V_24 ,
V_248 -> V_117 , V_248 -> V_261 , V_248 -> V_75 , V_60 ) ;
if ( V_109 < V_250 )
return - V_228 ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
if ( V_250 ) {
V_251 = 1 ;
V_250 -- ;
} else {
V_251 = 0 ;
V_250 = V_21 -> V_254 ;
}
if ( V_21 -> V_217 == V_218 ) {
switch ( V_21 -> V_223 ) {
case V_224 :
V_248 -> V_117 = V_256 ;
break;
case V_239 :
V_248 -> V_117 = V_257 ;
break;
}
} else
V_248 -> V_117 = V_173 ;
if ( F_65 ( V_250 , & V_21 -> V_255 ) ) {
if ( V_248 -> V_75 < V_21 -> V_259 [ V_250 ] ) {
V_43 = - V_228 ;
goto V_35;
}
V_248 -> V_75 = V_21 -> V_259 [ V_250 ] ;
memcpy ( V_60 , V_21 -> V_260 [ V_250 ] , V_21 -> V_259 [ V_250 ] ) ;
} else {
V_248 -> V_75 = 0 ;
V_248 -> V_117 |= V_172 ;
}
V_248 -> V_117 |= V_250 + 1 ;
F_6 ( L_59 , V_24 ,
V_248 -> V_117 , V_248 -> V_75 ) ;
V_35:
F_59 ( & V_21 -> V_212 , V_210 ) ;
return V_43 ;
}
static int F_68 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
unsigned long V_210 ;
F_6 ( L_13 , V_24 ) ;
if ( V_49 -> V_50 . V_53 != V_54 )
return - V_228 ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
if ( F_69 ( V_49 -> V_50 . V_51 ) ) {
memcpy ( V_21 -> V_47 , V_49 -> V_50 . V_51 ,
V_52 ) ;
F_58 ( V_262 , & V_21 -> V_65 ) ;
F_58 ( V_245 , & V_21 -> V_65 ) ;
F_6 ( L_60 , V_24 , V_21 -> V_47 ) ;
} else {
F_6 ( L_61 , V_24 ) ;
F_62 ( V_262 , & V_21 -> V_65 ) ;
F_70 ( V_21 -> V_47 ) ;
}
F_59 ( & V_21 -> V_212 , V_210 ) ;
F_6 ( L_19 , V_24 ) ;
return 0 ;
}
static int F_71 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
unsigned long V_210 ;
F_6 ( L_13 , V_24 ) ;
F_28 ( & V_21 -> V_44 ) ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
if ( V_21 -> V_45 == V_46 ) {
V_49 -> V_50 . V_53 = V_54 ;
memcpy ( V_49 -> V_50 . V_51 , V_21 -> V_263 ,
V_52 ) ;
} else
F_70 ( V_49 -> V_50 . V_51 ) ;
F_59 ( & V_21 -> V_212 , V_210 ) ;
F_29 ( & V_21 -> V_44 ) ;
F_6 ( L_19 , V_24 ) ;
return 0 ;
}
static int F_72 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
struct V_69 * V_248 = & V_49 -> V_249 ;
struct V_264 * V_265 = (struct V_264 * ) V_60 ;
T_5 V_266 ;
T_5 V_117 ;
unsigned long V_210 ;
int V_250 ;
int V_43 = 0 ;
F_6 ( L_13 , V_24 ) ;
V_117 = V_248 -> V_117 & V_252 ;
V_266 = V_265 -> V_266 ;
V_250 = V_248 -> V_117 & V_253 ;
F_6 ( L_54 , V_24 , V_250 ) ;
F_6 ( L_55 , V_24 , V_248 -> V_75 ) ;
F_6 ( L_56 , V_24 , V_248 -> V_117 & V_252 ) ;
F_6 ( L_62 , V_24 , V_265 -> V_267 ) ;
F_6 ( L_63 , V_24 , V_265 -> V_259 ) ;
if ( V_109 < V_250 )
return - V_228 ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
if ( V_250 )
V_250 -- ;
else
V_250 = V_21 -> V_254 ;
if ( ! V_248 -> V_75 && ( V_265 -> V_267 & V_268 ) ) {
F_6 ( L_64 ,
V_24 , V_250 ) ;
V_21 -> V_254 = V_250 ;
goto V_35;
}
if ( V_266 == V_269 || ( V_117 & V_173 ) ) {
F_6 ( L_65 , V_24 ) ;
V_21 -> V_215 = V_216 ;
V_21 -> V_217 = V_235 ;
V_21 -> V_219 = V_235 ;
V_21 -> V_223 = V_224 ;
} else if ( V_266 == V_270 ) {
F_6 ( L_66 , V_24 ) ;
if ( V_117 & V_256 ) {
F_6 ( L_67 , V_24 ) ;
V_21 -> V_223 = V_224 ;
}
if ( V_117 & V_257 ) {
F_6 ( L_68 , V_24 ) ;
V_21 -> V_223 = V_239 ;
}
if ( V_258 < V_265 -> V_259 ) {
F_18 ( L_69 , V_24 ,
V_265 -> V_259 ) ;
V_43 = - V_228 ;
goto V_35;
}
V_21 -> V_259 [ V_250 ] = V_265 -> V_259 ;
memset ( V_21 -> V_260 [ V_250 ] , 0 , V_258 ) ;
memcpy ( V_21 -> V_260 [ V_250 ] , V_265 -> V_260 , V_265 -> V_259 ) ;
F_58 ( V_250 , & V_21 -> V_255 ) ;
F_58 ( V_245 , & V_21 -> V_65 ) ;
} else if ( V_266 == V_271 ) {
if ( V_265 -> V_259 != V_272 ) {
F_73 ( L_70 , V_24 ,
V_265 -> V_259 ) ;
V_43 = - V_228 ;
goto V_35;
}
memset ( V_21 -> V_273 , 0 , sizeof( V_21 -> V_273 ) ) ;
memcpy ( V_21 -> V_273 , V_265 -> V_260 , V_265 -> V_259 ) ;
V_21 -> V_274 = V_265 -> V_259 ;
V_21 -> V_275 = V_276 ;
F_58 ( V_277 , & V_21 -> V_65 ) ;
}
V_35:
F_59 ( & V_21 -> V_212 , V_210 ) ;
F_6 ( L_19 , V_24 ) ;
return V_43 ;
}
static int F_74 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
struct V_69 * V_248 = & V_49 -> V_249 ;
struct V_264 * V_265 = (struct V_264 * ) V_60 ;
unsigned long V_210 ;
int V_250 ;
int V_43 = 0 ;
int V_278 ;
F_6 ( L_13 , V_24 ) ;
V_278 = V_248 -> V_75 - sizeof( struct V_264 ) ;
if ( V_278 < 0 )
return - V_228 ;
V_250 = V_248 -> V_117 & V_253 ;
F_6 ( L_54 , V_24 , V_250 ) ;
F_6 ( L_55 , V_24 , V_248 -> V_75 ) ;
F_6 ( L_56 , V_24 , V_248 -> V_117 & V_252 ) ;
if ( V_109 < V_250 )
return - V_228 ;
F_57 ( & V_21 -> V_212 , V_210 ) ;
if ( V_250 )
V_250 -- ;
else
V_250 = V_21 -> V_254 ;
memset ( V_265 , 0 , sizeof( struct V_264 ) ) ;
switch ( V_21 -> V_217 ) {
case V_218 :
V_265 -> V_266 = V_270 ;
V_248 -> V_117 |= V_171 ;
break;
case V_222 :
V_265 -> V_266 = V_279 ;
V_248 -> V_117 |= V_171 ;
break;
case V_227 :
V_265 -> V_266 = V_280 ;
V_248 -> V_117 |= V_171 ;
break;
case V_235 :
default:
V_265 -> V_266 = V_269 ;
V_248 -> V_117 |= V_172 ;
break;
}
if ( ! ( V_248 -> V_117 & V_172 ) ) {
if ( V_278 < V_21 -> V_259 [ V_250 ] ) {
V_43 = - V_205 ;
goto V_199;
}
if ( F_65 ( V_250 , & V_21 -> V_255 ) )
memcpy ( V_265 -> V_260 , V_21 -> V_260 [ V_250 ] ,
V_21 -> V_259 [ V_250 ] ) ;
else
F_6 ( L_71 ,
V_24 , V_250 ) ;
}
V_199:
F_59 ( & V_21 -> V_212 , V_210 ) ;
F_6 ( L_19 , V_24 ) ;
return V_43 ;
}
static int F_75 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
T_6 V_177 = V_49 -> V_177 ;
int V_43 ;
F_6 ( L_13 , V_24 ) ;
if ( V_177 == V_281 )
V_43 = 0 ;
else
V_43 = - V_244 ;
F_6 ( L_49 , V_24 , V_43 ) ;
return V_43 ;
}
static int F_76 ( struct V_41 * V_42 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
T_6 * V_177 = & V_49 -> V_177 ;
F_6 ( L_13 , V_24 ) ;
* V_177 = V_281 ;
F_6 ( L_19 , V_24 ) ;
return 0 ;
}
static int F_77 ( struct V_41 * V_282 ,
struct V_57 * V_58 ,
union V_48 * V_49 , char * V_60 )
{
strcpy ( V_60 , L_72 ) ;
V_49 -> V_49 . V_75 = strlen ( V_60 ) ;
V_49 -> V_49 . V_117 = 1 ;
return 0 ;
}
static struct V_283 * F_78 (
struct V_41 * V_42 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
struct V_16 * V_17 ;
struct V_283 * V_284 ;
struct V_285 * V_186 ;
void * V_119 ;
F_6 ( L_13 , V_24 ) ;
V_119 = ( void * ) F_79 ( V_39 ) ;
if ( ! V_119 )
return NULL ;
V_284 = & V_21 -> V_286 ;
memset ( V_284 , 0 , sizeof( * V_284 ) ) ;
V_17 = F_21 ( V_21 , V_13 ,
V_119 , sizeof( * V_186 ) ) ;
if ( V_17 && ! V_17 -> V_31 && ! V_17 -> V_37 ) {
V_186 = V_119 ;
V_284 -> V_94 . V_95 = F_43 ( V_186 -> V_186 ) ;
V_284 -> V_94 . V_182 = V_287 |
V_184 | V_185 ;
} else
V_284 -> V_94 . V_182 = V_288 ;
F_80 ( V_17 ) ;
F_81 ( ( unsigned long ) V_119 ) ;
F_6 ( L_19 , V_24 ) ;
return V_284 ;
}
static int F_41 ( struct V_20 * V_21 , int V_289 ,
T_3 * V_115 , T_4 V_116 )
{
struct V_16 * V_17 ;
int V_43 = 0 ;
void * V_119 = NULL ;
T_4 V_138 ;
F_6 ( L_73 , V_24 , V_289 ) ;
if ( F_52 ( & V_21 -> V_195 ) )
return - V_290 ;
if ( V_21 -> V_197 == V_198 ) {
F_6 ( L_74 , V_24 ) ;
goto V_199;
}
F_13 ( & V_21 -> V_291 ) ;
if ( ( ! V_116 && ! V_289 )
&& V_21 -> V_197 == V_202 ) {
F_6 ( L_75 , V_24 ) ;
F_17 ( & V_21 -> V_291 ) ;
goto V_199;
}
if ( V_116 && V_115 ) {
V_119 = ( void * ) F_79 ( V_39 ) ;
if ( ! V_119 ) {
V_43 = - V_292 ;
goto V_199;
}
V_138 = V_246 ;
memset ( V_119 , 0 , V_138 ) ;
memcpy ( V_119 , V_115 , V_116 ) ;
F_6 ( L_76 , V_24 , ( char * ) V_119 ) ;
} else
V_138 = 0 ;
V_21 -> V_197 = V_198 ;
V_17 = F_21 ( V_21 , V_5 ,
V_119 , V_138 ) ;
if ( ! V_17 || V_17 -> V_31 || V_17 -> V_37 ) {
V_21 -> V_197 = V_200 ;
F_17 ( & V_21 -> V_291 ) ;
V_43 = - V_292 ;
goto V_199;
}
F_80 ( V_17 ) ;
V_199:
F_81 ( ( unsigned long ) V_119 ) ;
F_29 ( & V_21 -> V_195 ) ;
F_6 ( L_19 , V_24 ) ;
return V_43 ;
}
static void F_82 ( struct V_20 * V_21 )
{
struct V_16 * V_17 = NULL ;
struct V_147 * V_293 , * V_63 ;
struct V_147 * V_294 = NULL ;
struct V_120 * V_192 ;
unsigned int V_295 ;
union V_48 V_49 ;
unsigned long V_193 = V_194 ;
unsigned int V_190 , V_73 , V_296 , V_297 ;
void * V_119 ;
F_6 ( L_77 , V_24 ) ;
F_28 ( & V_21 -> V_195 ) ;
V_119 = ( void * ) F_79 ( V_39 ) ;
if ( ! V_119 ) {
F_18 ( L_78 , V_24 ) ;
goto V_199;
}
if ( V_21 -> V_197 != V_198 ) {
F_6 ( L_79 ,
V_24 , V_21 -> V_197 ) ;
goto V_199;
}
V_17 = F_21 ( V_21 , V_6 ,
V_119 , V_298 ) ;
if ( ! V_17 || V_17 -> V_31 || V_17 -> V_37 ) {
V_21 -> V_197 = V_200 ;
F_18 ( L_80 , V_24 ) ;
F_80 ( V_17 ) ;
goto V_199;
}
V_190 = V_17 -> V_34 ;
F_6 ( L_81 , V_24 , V_190 ) ;
F_80 ( V_17 ) ;
V_21 -> V_197 = V_202 ;
F_83 (target, tmp, &wl->network_list, list) {
V_293 -> V_206 = 0 ;
if ( F_84 ( V_293 -> V_204 + V_21 -> V_203 ,
V_193 ) ) {
F_80 ( V_293 -> V_151 ) ;
V_293 -> V_151 = NULL ;
F_85 ( & V_293 -> V_299 , & V_21 -> V_300 ) ;
}
}
for ( V_73 = 0 , V_295 = 0 , V_192 = V_119 ;
V_295 < V_190 ;
V_73 ++ , V_295 += F_43 ( V_192 -> V_34 ) ,
V_192 = ( void * ) V_192 + F_43 ( V_192 -> V_34 ) ) {
F_6 ( L_82 , V_24 ,
F_43 ( V_192 -> V_34 ) ,
& V_192 -> V_47 [ 2 ] , V_192 ) ;
if ( ! F_43 ( V_192 -> V_158 ) || ! V_192 -> V_152 [ 0 ] ) {
F_6 ( L_83 , V_24 ) ;
continue;
}
V_296 = 0 ;
V_294 = NULL ;
F_53 (target, &wl->network_list, list) {
if ( F_86 ( & V_293 -> V_151 -> V_47 [ 2 ] ,
& V_192 -> V_47 [ 2 ] ) ) {
V_296 = 1 ;
F_6 ( L_84 ,
V_24 ) ;
break;
}
if ( ! V_294 ||
( V_293 -> V_204 < V_294 -> V_204 ) )
V_294 = V_293 ;
}
if ( ! V_296 ) {
if ( F_87 ( & V_21 -> V_300 ) ) {
V_293 = V_294 ;
} else {
V_293 = F_88 ( V_21 -> V_300 . V_301 ,
struct V_147 ,
V_299 ) ;
}
}
V_293 -> V_204 = V_193 ;
V_293 -> V_206 = 1 ;
V_293 -> V_207 = V_73 ;
F_80 ( V_293 -> V_151 ) ;
V_293 -> V_151 = F_22 ( F_43 ( V_192 -> V_34 ) ,
V_39 ) ;
if ( ! V_293 -> V_151 )
continue;
memcpy ( V_293 -> V_151 , V_192 , F_43 ( V_192 -> V_34 ) ) ;
V_293 -> V_116 = F_47 ( V_192 -> V_115 ,
sizeof( V_192 -> V_115 ) ) ;
V_293 -> V_163 = 0 ;
for ( V_297 = 0 ; V_297 < 12 ; V_297 ++ )
if ( V_192 -> V_152 [ V_297 ] )
V_293 -> V_163 ++ ;
if ( 8 < V_293 -> V_163 )
F_18 ( L_85 , V_24 ,
V_293 -> V_163 ) ;
V_293 -> V_164 = 0 ;
for ( V_297 = 0 ; V_297 < 16 ; V_297 ++ )
if ( V_192 -> V_165 [ V_297 ] )
V_293 -> V_164 ++ ;
F_85 ( & V_293 -> V_299 , & V_21 -> V_302 ) ;
}
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
F_31 ( F_32 ( F_10 ( V_21 ) ) , V_99 , & V_49 ,
NULL ) ;
V_199:
F_81 ( ( unsigned long ) V_119 ) ;
F_17 ( & V_21 -> V_291 ) ;
F_29 ( & V_21 -> V_195 ) ;
F_6 ( L_86 , V_24 ) ;
}
static void F_89 ( struct V_147 * * V_303 ,
struct V_147 * V_304 ,
int * V_305 ,
int * V_306 )
{
if ( * V_305 < ++ ( * V_306 ) ) {
* V_305 = * V_306 ;
* V_303 = V_304 ;
}
}
static
struct V_147 * F_90 ( struct V_20 * V_21 )
{
struct V_147 * V_192 ;
struct V_147 * V_307 ;
int V_306 , V_305 ;
T_7 V_126 ;
F_6 ( L_13 , V_24 ) ;
V_307 = NULL ;
V_305 = 0 ;
F_53 (scan_info, &wl->network_list, list) {
F_6 ( L_87 , V_24 , V_192 ) ;
if ( ! V_192 -> V_206 ) {
F_6 ( L_88 , V_24 ) ;
continue;
}
if ( F_65 ( V_262 , & V_21 -> V_65 ) ) {
if ( F_86 ( & V_192 -> V_151 -> V_47 [ 2 ] ,
V_21 -> V_47 ) ) {
V_307 = V_192 ;
F_6 ( L_89 , V_24 ) ;
break;
} else {
F_6 ( L_90 , V_24 ) ;
continue;
}
}
V_306 = 0 ;
V_126 = F_43 ( V_192 -> V_151 -> V_126 ) &
V_127 ;
if ( V_21 -> V_215 == V_226 ) {
if ( V_126 == V_129 )
F_89 ( & V_307 , V_192 ,
& V_305 , & V_306 ) ;
else
continue;
} else if ( V_21 -> V_215 == V_221 ) {
if ( V_126 == V_128 )
F_89 ( & V_307 , V_192 ,
& V_305 , & V_306 ) ;
else
continue;
} else if ( V_21 -> V_215 == V_216 &&
V_21 -> V_217 == V_218 ) {
if ( V_126 == V_308 )
F_89 ( & V_307 , V_192 ,
& V_305 , & V_306 ) ;
else
continue;
}
if ( F_65 ( V_247 , & V_21 -> V_65 ) ) {
if ( ( V_192 -> V_116 == V_21 -> V_116 ) &&
! strncmp ( V_21 -> V_115 ,
V_192 -> V_151 -> V_115 ,
V_192 -> V_116 ) )
F_89 ( & V_307 , V_192 ,
& V_305 , & V_306 ) ;
else
continue;
}
}
#ifdef F_20
F_6 ( L_91 , V_24 , V_307 ) ;
if ( V_307 ) {
F_6 ( L_92 , V_24 ,
& V_307 -> V_151 -> V_47 [ 2 ] ) ;
}
#endif
return V_307 ;
}
static int F_91 ( struct V_20 * V_21 )
{
unsigned int V_73 ;
struct V_309 * V_310 ;
struct V_16 * V_17 ;
int V_311 = 0 ;
int V_312 = 0 ;
int V_43 = 0 ;
F_6 ( L_13 , V_24 ) ;
V_310 = (struct V_309 * ) F_79 ( V_39 ) ;
if ( ! V_310 )
return - V_292 ;
memset ( V_310 , 0 , sizeof( * V_310 ) ) ;
if ( V_21 -> V_217 == V_218 ) {
F_6 ( L_93 , V_24 ) ;
for ( V_73 = 0 ; V_73 < V_109 ; V_73 ++ ) {
if ( ! F_65 ( V_73 , & V_21 -> V_255 ) )
continue;
F_6 ( L_94 , V_24 , V_73 ) ;
V_312 = 1 ;
if ( V_21 -> V_259 [ V_73 ] == 13 )
V_311 = 1 ;
else if ( V_21 -> V_259 [ V_73 ] != 5 ) {
F_18 ( L_95 ,
V_24 , V_73 , V_21 -> V_259 [ V_73 ] ) ;
V_43 = - V_228 ;
goto V_199;
}
memcpy ( V_310 -> V_260 [ V_73 ] , V_21 -> V_260 [ V_73 ] , V_21 -> V_259 [ V_73 ] ) ;
}
if ( ! V_312 ) {
F_18 ( L_96 , V_24 ) ;
V_43 = - V_228 ;
goto V_199;
}
if ( V_311 ) {
F_6 ( L_97 , V_24 ) ;
V_310 -> V_126 = F_92 ( V_313 ) ;
} else {
F_6 ( L_98 , V_24 ) ;
V_310 -> V_126 = F_92 ( V_314 ) ;
}
} else {
F_6 ( L_99 , V_24 ) ;
V_310 -> V_126 = F_92 ( V_315 ) ;
}
V_17 = F_21 ( V_21 , V_9 ,
V_310 , sizeof( * V_310 ) ) ;
if ( ! V_17 )
V_43 = - V_292 ;
else if ( V_17 -> V_31 || V_17 -> V_37 )
V_43 = - V_316 ;
F_80 ( V_17 ) ;
V_199:
F_81 ( ( unsigned long ) V_310 ) ;
F_6 ( L_19 , V_24 ) ;
return V_43 ;
}
static const char * F_93 ( enum V_317 V_318 )
{
switch ( V_318 ) {
case V_319 :
return L_100 ;
case V_320 :
return L_101 ;
case V_321 :
return L_102 ;
case V_322 :
return L_103 ;
case V_323 :
return L_104 ;
case V_324 :
return L_105 ;
case V_325 :
return L_106 ;
}
return L_12 ;
}
static int F_94 ( struct V_20 * V_21 )
{
struct V_326 * V_144 ;
struct V_16 * V_17 ;
T_7 V_126 ;
int V_43 = 0 ;
F_6 ( L_13 , V_24 ) ;
V_144 = (struct V_326 * ) F_79 ( V_39 ) ;
if ( ! V_144 )
return - V_292 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
if ( ! F_65 ( V_277 , & V_21 -> V_65 ) )
F_18 ( L_107 , V_24 ) ;
memcpy ( V_144 -> V_273 , V_21 -> V_273 , V_21 -> V_274 ) ;
if ( V_21 -> V_215 == V_226 ) {
if ( V_21 -> V_217 == V_227 ) {
V_126 = V_325 ;
} else {
if ( V_21 -> V_219 == V_227 &&
F_3 () )
V_126 = V_324 ;
else
V_126 = V_323 ;
}
} else {
if ( V_21 -> V_217 == V_227 ) {
V_126 = V_322 ;
} else {
if ( V_21 -> V_219 == V_227 &&
F_3 () )
V_126 = V_321 ;
else
V_126 = V_320 ;
}
}
V_144 -> V_126 = F_92 ( V_126 ) ;
V_144 -> V_275 = F_92 ( V_21 -> V_275 ) ;
#ifdef F_20
F_6 ( L_108 , V_24 ,
F_93 ( V_144 -> V_126 ) ,
( V_144 -> V_275 == V_276 ) ?
L_109 : L_110 ) ;
#if 0
pr_debug("%s: psk=%s\n", __func__,
(wpa->psk_type == GELIC_EURUS_WPA_PSK_BIN) ?
"N/A" : wpa->psk);
#endif
#endif
V_17 = F_21 ( V_21 , V_11 ,
V_144 , sizeof( * V_144 ) ) ;
if ( ! V_17 )
V_43 = - V_292 ;
else if ( V_17 -> V_31 || V_17 -> V_37 )
V_43 = - V_316 ;
F_80 ( V_17 ) ;
F_81 ( ( unsigned long ) V_144 ) ;
F_6 ( L_111 , V_24 , V_43 ) ;
return V_43 ;
}
static int F_95 ( struct V_20 * V_21 ,
struct V_147 * V_327 )
{
struct V_16 * V_17 ;
struct V_328 * V_329 ;
int V_43 = 0 ;
unsigned long V_330 ;
F_6 ( L_13 , V_24 ) ;
V_329 = (struct V_328 * ) F_79 ( V_39 ) ;
if ( ! V_329 )
return - V_292 ;
memset ( V_329 , 0 , sizeof( * V_329 ) ) ;
V_329 -> V_331 = F_92 ( V_332 ) ;
V_329 -> V_333 = F_92 ( V_334 ) ;
V_329 -> V_335 = F_92 ( V_327 -> V_207 ) ;
switch ( V_21 -> V_223 ) {
case V_224 :
V_329 -> V_223 = F_92 ( V_224 ) ;
break;
case V_239 :
V_329 -> V_223 = F_92 ( V_239 ) ;
break;
}
#ifdef F_20
F_55 ( V_21 ) ;
#endif
F_6 ( L_112 , V_24 ,
F_43 ( V_329 -> V_335 ) ,
F_43 ( V_329 -> V_331 ) ,
F_43 ( V_329 -> V_223 ) ) ;
V_17 = F_21 ( V_21 , V_7 ,
V_329 , sizeof( * V_329 ) ) ;
if ( ! V_17 || V_17 -> V_31 || V_17 -> V_37 ) {
V_43 = - V_292 ;
F_80 ( V_17 ) ;
goto V_199;
}
F_80 ( V_17 ) ;
switch ( V_21 -> V_215 ) {
case V_216 :
V_43 = F_91 ( V_21 ) ;
break;
case V_221 :
case V_226 :
V_43 = F_94 ( V_21 ) ;
break;
}
if ( V_43 ) {
F_6 ( L_113 , V_24 ,
V_43 ) ;
V_43 = - V_336 ;
F_30 ( V_21 , NULL ) ;
goto V_199;
}
F_13 ( & V_21 -> V_337 ) ;
V_21 -> V_45 = V_338 ;
V_17 = F_21 ( V_21 , V_3 ,
NULL , 0 ) ;
if ( ! V_17 || V_17 -> V_31 || V_17 -> V_37 ) {
F_6 ( L_114 , V_24 ) ;
V_21 -> V_45 = V_339 ;
F_80 ( V_17 ) ;
V_43 = - V_292 ;
F_30 ( V_21 , NULL ) ;
goto V_199;
}
F_80 ( V_17 ) ;
V_330 = F_96 ( & V_21 -> V_337 , V_340 * 4 ) ;
if ( ! V_330 ) {
F_18 ( L_115 , V_24 ) ;
V_17 = F_21 ( V_21 , V_4 ,
NULL , 0 ) ;
F_80 ( V_17 ) ;
V_21 -> V_45 = V_339 ;
F_30 ( V_21 , NULL ) ;
V_43 = - V_316 ;
} else {
V_21 -> V_45 = V_46 ;
memcpy ( V_21 -> V_263 , & V_327 -> V_151 -> V_47 [ 2 ] , V_52 ) ;
F_30 ( V_21 , V_21 -> V_263 ) ;
F_18 ( L_116 , V_24 ) ;
}
V_199:
F_81 ( ( unsigned long ) V_329 ) ;
F_6 ( L_19 , V_24 ) ;
return V_43 ;
}
static void F_97 ( struct V_20 * V_21 ,
T_1 V_341 )
{
T_1 V_342 = 0 ;
switch ( V_21 -> V_215 ) {
case V_216 :
V_342 = V_343 ;
break;
case V_221 :
case V_226 :
V_342 = V_344 ;
break;
}
if ( V_342 == V_341 ) {
F_6 ( L_117 , V_24 ) ;
F_17 ( & V_21 -> V_337 ) ;
F_98 ( F_32 ( F_10 ( V_21 ) ) ) ;
} else
F_6 ( L_118 ,
V_24 , V_341 ) ;
}
static void F_99 ( struct V_20 * V_21 ,
T_1 V_341 )
{
struct V_16 * V_17 ;
int V_212 ;
if ( ! F_100 ( & V_21 -> V_44 ) ) {
F_6 ( L_119 , V_24 ) ;
V_212 = 0 ;
} else {
F_6 ( L_120 , V_24 ) ;
V_212 = 1 ;
}
V_17 = F_21 ( V_21 , V_4 , NULL , 0 ) ;
F_80 ( V_17 ) ;
if ( V_21 -> V_45 == V_46 )
F_30 ( V_21 , NULL ) ;
V_21 -> V_45 = V_339 ;
F_101 ( F_32 ( F_10 ( V_21 ) ) ) ;
if ( V_212 )
F_29 ( & V_21 -> V_44 ) ;
}
static const char * F_102 ( enum V_345 V_341 )
{
static char V_119 [ 32 ] ;
char * V_43 ;
if ( V_341 & V_346 )
V_43 = L_121 ;
else if ( V_341 & V_347 )
V_43 = L_122 ;
else if ( V_341 & V_348 )
V_43 = L_123 ;
else if ( V_341 & V_349 )
V_43 = L_124 ;
else if ( V_341 & V_343 )
V_43 = L_125 ;
else if ( V_341 & V_344 )
V_43 = L_126 ;
else if ( V_341 & V_350 )
V_43 = L_127 ;
else {
sprintf ( V_119 , L_128 , V_341 ) ;
V_43 = V_119 ;
}
return V_43 ;
}
static const char * F_102 ( enum V_345 V_341 )
{
return NULL ;
}
static void F_103 ( struct V_14 * V_15 )
{
struct V_20 * V_21 ;
struct V_351 * V_352 ;
T_1 V_341 , V_63 ;
int V_31 ;
F_6 ( L_77 , V_24 ) ;
V_21 = F_7 ( V_15 , struct V_20 , V_353 . V_15 ) ;
V_352 = F_10 ( V_21 ) ;
while ( 1 ) {
V_31 = F_14 ( F_15 ( V_352 -> V_19 ) , F_16 ( V_352 -> V_19 ) ,
V_354 , 0 , 0 , 0 ,
& V_341 , & V_63 ) ;
if ( V_31 ) {
if ( V_31 != V_67 )
F_6 ( L_129 ,
V_24 , V_31 ) ;
F_6 ( L_86 , V_24 ) ;
return;
}
F_6 ( L_130 , V_24 , F_102 ( V_341 ) ) ;
switch ( V_341 ) {
case V_347 :
F_82 ( V_21 ) ;
break;
case V_349 :
case V_348 :
F_99 ( V_21 , V_341 ) ;
break;
case V_343 :
case V_344 :
F_97 ( V_21 , V_341 ) ;
break;
default:
break;
}
}
}
static void F_104 ( struct V_14 * V_15 )
{
struct V_20 * V_21 ;
struct V_147 * V_307 ;
int V_43 ;
unsigned long V_210 ;
T_3 * V_115 ;
T_4 V_116 ;
V_21 = F_7 ( V_15 , struct V_20 , V_355 . V_15 ) ;
F_28 ( & V_21 -> V_44 ) ;
if ( V_21 -> V_45 != V_339 )
goto V_199;
F_57 ( & V_21 -> V_212 , V_210 ) ;
if ( F_65 ( V_247 , & V_21 -> V_65 ) ) {
F_6 ( L_131 , V_24 ,
V_21 -> V_115 ) ;
V_115 = V_21 -> V_115 ;
V_116 = V_21 -> V_116 ;
} else {
V_115 = NULL ;
V_116 = 0 ;
}
F_59 ( & V_21 -> V_212 , V_210 ) ;
V_43 = F_41 ( V_21 , 0 , V_115 , V_116 ) ;
if ( V_43 == - V_290 ) {
F_6 ( L_132 , V_24 ) ;
F_105 ( & V_21 -> V_355 , V_340 / 10 ) ;
goto V_199;
} else if ( V_43 ) {
F_18 ( L_133 , V_24 ) ;
goto V_199;
}
F_19 ( & V_21 -> V_291 ) ;
F_6 ( L_134 , V_24 ) ;
F_28 ( & V_21 -> V_195 ) ;
if ( V_21 -> V_197 != V_202 ) {
F_30 ( V_21 , NULL ) ;
F_18 ( L_135 , V_24 ) ;
goto V_356;
}
V_307 = F_90 ( V_21 ) ;
if ( ! V_307 ) {
F_30 ( V_21 , NULL ) ;
F_18 ( L_136 , V_24 ) ;
goto V_356;
}
V_43 = F_95 ( V_21 , V_307 ) ;
if ( V_43 )
F_18 ( L_137 , V_24 , V_43 ) ;
V_356:
F_29 ( & V_21 -> V_195 ) ;
V_199:
F_29 ( & V_21 -> V_44 ) ;
}
void F_106 ( struct V_41 * V_42 , T_1 V_31 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
if ( V_31 & V_357 ) {
F_6 ( L_138 , V_24 ) ;
F_17 ( & V_21 -> V_30 ) ;
}
if ( V_31 & V_358 ) {
F_6 ( L_139 , V_24 ) ;
F_107 ( V_21 -> V_359 , & V_21 -> V_353 , 0 ) ;
}
}
static struct V_41 * F_108 ( struct V_18 * V_19 )
{
struct V_41 * V_42 ;
struct V_351 * V_352 ;
struct V_20 * V_21 ;
unsigned int V_73 ;
F_6 ( L_77 , V_24 ) ;
V_42 = F_109 ( sizeof( struct V_351 ) +
sizeof( struct V_20 ) ) ;
F_6 ( L_140 , V_24 , V_42 , V_19 ) ;
if ( ! V_42 )
return NULL ;
strcpy ( V_42 -> V_61 , L_141 ) ;
V_352 = F_40 ( V_42 ) ;
V_352 -> V_42 = V_42 ;
V_352 -> V_19 = V_19 ;
V_352 -> type = V_360 ;
V_21 = F_26 ( V_352 ) ;
F_6 ( L_142 , V_24 , V_21 , V_352 ) ;
V_21 -> V_361 = F_22 ( sizeof( struct V_147 ) *
V_362 , V_39 ) ;
if ( ! V_21 -> V_361 )
goto V_363;
V_21 -> V_40 = F_110 ( L_143 ) ;
if ( ! V_21 -> V_40 )
goto V_364;
V_21 -> V_359 = F_110 ( L_144 ) ;
if ( ! V_21 -> V_359 )
goto V_365;
F_111 ( & V_21 -> V_300 ) ;
F_111 ( & V_21 -> V_302 ) ;
for ( V_73 = 0 ; V_73 < V_362 ; V_73 ++ )
F_112 ( & V_21 -> V_361 [ V_73 ] . V_299 ,
& V_21 -> V_300 ) ;
F_13 ( & V_21 -> V_30 ) ;
F_113 ( & V_21 -> V_353 , F_103 ) ;
F_113 ( & V_21 -> V_355 , F_104 ) ;
F_114 ( & V_21 -> V_195 ) ;
F_114 ( & V_21 -> V_44 ) ;
F_13 ( & V_21 -> V_291 ) ;
F_17 ( & V_21 -> V_291 ) ;
F_115 ( & V_21 -> V_212 ) ;
V_21 -> V_203 = 5 * V_340 ;
F_116 ( V_298 <
sizeof( struct V_120 ) *
V_366 ) ;
F_6 ( L_86 , V_24 ) ;
return V_42 ;
V_365:
F_117 ( V_21 -> V_40 ) ;
V_364:
F_80 ( V_21 -> V_361 ) ;
V_363:
F_118 ( V_42 ) ;
F_6 ( L_145 , V_24 ) ;
return NULL ;
}
static void F_119 ( struct V_20 * V_21 )
{
struct V_147 * V_192 ;
unsigned int V_73 ;
F_6 ( L_13 , V_24 ) ;
F_6 ( L_146 , V_24 ) ;
F_117 ( V_21 -> V_40 ) ;
F_117 ( V_21 -> V_359 ) ;
V_192 = V_21 -> V_361 ;
for ( V_73 = 0 ; V_73 < V_362 ; V_73 ++ , V_192 ++ )
F_80 ( V_192 -> V_151 ) ;
F_80 ( V_21 -> V_361 ) ;
F_118 ( F_32 ( F_10 ( V_21 ) ) ) ;
F_6 ( L_19 , V_24 ) ;
}
static int F_63 ( struct V_41 * V_42 )
{
struct V_20 * V_21 = F_26 ( F_40 ( V_42 ) ) ;
int V_43 = - 1 ;
unsigned int V_73 ;
F_6 ( L_13 , V_24 ) ;
if ( V_21 -> V_217 == V_235 ) {
if ( F_65 ( V_245 ,
& V_21 -> V_65 ) )
goto V_367;
else {
F_6 ( L_147 , V_24 ) ;
return V_43 ;
}
}
if ( V_21 -> V_217 == V_218 ) {
for ( V_73 = 0 ; V_73 < V_109 ; V_73 ++ ) {
if ( F_65 ( V_73 , & V_21 -> V_255 ) )
goto V_367;
}
F_6 ( L_148 , V_24 ) ;
return V_43 ;
}
if ( ( V_21 -> V_217 == V_222 ) ||
( V_21 -> V_217 == V_227 ) ) {
if ( F_65 ( V_277 ,
& V_21 -> V_65 ) )
goto V_367;
else {
F_6 ( L_149 ,
V_24 ) ;
return V_43 ;
}
}
V_367:
V_43 = F_105 ( & V_21 -> V_355 , 0 ) ;
F_6 ( L_150 , V_24 , V_43 ) ;
return V_43 ;
}
static int F_120 ( struct V_41 * V_42 )
{
struct V_18 * V_19 = F_121 ( V_42 ) ;
F_6 ( L_151 , V_24 , V_42 ) ;
F_122 ( V_19 ) ;
F_63 ( V_42 ) ;
F_123 ( V_42 ) ;
F_6 ( L_152 , V_24 ) ;
return 0 ;
}
static int F_124 ( struct V_20 * V_21 )
{
struct V_147 * V_293 ;
struct V_147 * V_63 ;
F_83 (target, tmp, &wl->network_list, list) {
F_85 ( & V_293 -> V_299 , & V_21 -> V_300 ) ;
}
V_21 -> V_197 = V_200 ;
V_21 -> V_223 = V_224 ;
V_21 -> V_217 = V_235 ;
V_21 -> V_219 = V_235 ;
V_21 -> V_215 = V_216 ;
V_21 -> V_255 = 0 ;
V_21 -> V_254 = 0 ;
V_21 -> V_275 = V_368 ;
V_21 -> V_274 = 0 ;
V_21 -> V_116 = 0 ;
memset ( V_21 -> V_115 , 0 , sizeof( V_21 -> V_115 ) ) ;
memset ( V_21 -> V_47 , 0 , sizeof( V_21 -> V_47 ) ) ;
memset ( V_21 -> V_263 , 0 , sizeof( V_21 -> V_263 ) ) ;
V_21 -> V_45 = V_339 ;
memset ( & V_21 -> V_286 , 0 , sizeof( V_21 -> V_286 ) ) ;
V_21 -> V_65 = 0 ;
return 0 ;
}
static void F_125 ( struct V_41 * V_42 )
{
struct V_351 * V_352 = F_40 ( V_42 ) ;
struct V_20 * V_21 = F_26 ( V_352 ) ;
struct V_16 * V_17 ;
if ( V_21 -> V_197 == V_198 )
F_96 ( & V_21 -> V_291 , V_340 ) ;
V_17 = F_21 ( V_21 , V_4 , NULL , 0 ) ;
F_80 ( V_17 ) ;
F_30 ( V_21 , NULL ) ;
}
static int F_126 ( struct V_41 * V_42 )
{
struct V_351 * V_352 = F_40 ( V_42 ) ;
struct V_20 * V_21 = F_26 ( V_352 ) ;
struct V_18 * V_19 = F_121 ( V_42 ) ;
F_6 ( L_152 , V_24 ) ;
F_127 ( & V_21 -> V_355 ) ;
if ( V_21 -> V_45 == V_46 )
F_125 ( V_42 ) ;
F_124 ( V_21 ) ;
F_128 ( V_42 ) ;
F_129 ( V_19 ) ;
F_6 ( L_153 , V_24 ) ;
return 0 ;
}
static void F_130 ( struct V_41 * V_42 )
{
struct V_20 * V_21 ;
V_21 = F_26 ( F_40 ( V_42 ) ) ;
F_8 ( ! V_21 ) ;
V_42 -> V_369 = V_370 ;
V_42 -> V_371 = & V_372 ;
V_42 -> V_373 = & V_374 ;
V_42 -> V_375 = & V_21 -> V_375 ;
V_42 -> V_376 = & V_377 ;
}
int F_131 ( struct V_18 * V_19 )
{
int V_43 ;
struct V_41 * V_42 ;
F_6 ( L_77 , V_24 ) ;
if ( F_2 ( 1 , 6 , 0 ) < 0 )
return 0 ;
if ( ! V_19 -> V_378 [ V_360 ] . V_379 )
return 0 ;
V_42 = F_108 ( V_19 ) ;
if ( ! V_42 )
return - V_292 ;
F_132 ( V_42 , & V_19 -> V_56 -> V_380 ) ;
F_130 ( V_42 ) ;
V_43 = F_133 ( V_42 , V_19 ) ;
if ( V_43 )
goto V_381;
V_19 -> V_42 [ V_360 ] = V_42 ;
V_19 -> V_382 |= V_358 |
V_357 ;
F_134 ( V_19 , V_358 |
V_357 ) ;
F_6 ( L_86 , V_24 ) ;
return 0 ;
V_381:
F_119 ( F_26 ( F_27 ( V_42 ) ) ) ;
return V_43 ;
}
int F_135 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_41 * V_42 ;
F_6 ( L_77 , V_24 ) ;
if ( F_2 ( 1 , 6 , 0 ) < 0 )
return 0 ;
if ( ! V_19 -> V_378 [ V_360 ] . V_379 )
return 0 ;
V_42 = V_19 -> V_42 [ V_360 ] ;
V_21 = F_26 ( F_40 ( V_42 ) ) ;
if ( V_21 -> V_45 == V_46 )
F_125 ( V_42 ) ;
F_17 ( & V_21 -> V_30 ) ;
F_127 ( & V_21 -> V_355 ) ;
F_127 ( & V_21 -> V_353 ) ;
F_136 ( V_21 -> V_40 ) ;
F_136 ( V_21 -> V_359 ) ;
F_137 ( V_42 ) ;
F_6 ( L_154 , V_24 ) ;
V_19 -> V_382 &= ~ ( V_358 |
V_357 ) ;
F_119 ( V_21 ) ;
F_6 ( L_86 , V_24 ) ;
return 0 ;
}
