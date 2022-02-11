static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 . V_7 & V_8 )
return F_3 ( & V_9 ) ? & V_9 : NULL ;
return & V_10 [ F_4 ( V_5 -> V_11 ) & V_12 ] ;
}
static int F_5 ( T_1 V_13 )
{
struct V_2 * V_3 ;
if ( V_13 == 0 )
return - 1 ;
F_6 (sk, &dn_sk_hash[le16_to_cpu(port) & DN_SK_HASH_MASK]) {
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_11 == V_13 )
return - 1 ;
}
return 0 ;
}
static unsigned short F_7 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
static unsigned short V_13 = 0x2000 ;
unsigned short V_14 = V_13 ;
while( F_5 ( F_8 ( ++ V_13 ) ) != 0 ) {
if ( V_13 == V_14 )
return 0 ;
}
V_5 -> V_11 = F_8 ( V_13 ) ;
return 1 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_15 ;
int V_16 = - V_17 ;
F_10 ( F_11 ( V_3 ) ) ;
F_12 ( & V_18 ) ;
if ( ! V_5 -> V_11 && ! F_7 ( V_3 ) )
goto V_19;
V_16 = - V_20 ;
if ( ( V_15 = F_1 ( V_3 ) ) == NULL )
goto V_19;
F_13 ( V_3 , V_15 ) ;
V_16 = 0 ;
V_19:
F_14 ( & V_18 ) ;
return V_16 ;
}
static void F_15 ( struct V_2 * V_3 )
{
F_16 ( & V_18 ) ;
F_17 ( V_3 ) ;
F_18 ( & V_18 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
F_12 ( & V_18 ) ;
F_17 ( V_3 ) ;
F_14 ( & V_18 ) ;
}
static struct V_1 * F_20 ( struct V_21 * V_6 )
{
int V_22 ;
unsigned int V_23 = V_6 -> V_24 ;
if ( V_23 == 0 ) {
V_23 = V_6 -> V_25 ;
for( V_22 = 0 ; V_22 < F_4 ( V_6 -> V_25 ) ; V_22 ++ ) {
V_23 ^= V_6 -> V_26 [ V_22 ] ;
V_23 ^= ( V_23 << 3 ) ;
}
}
return & V_10 [ V_23 & V_12 ] ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_15 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 . V_7 & V_8 )
return;
F_12 ( & V_18 ) ;
F_17 ( V_3 ) ;
F_2 ( V_3 ) -> V_11 = 0 ;
V_15 = F_20 ( & F_2 ( V_3 ) -> V_6 ) ;
F_13 ( V_3 , V_15 ) ;
F_14 ( & V_18 ) ;
}
int F_22 ( struct V_21 * V_27 , unsigned char * V_28 , unsigned char type )
{
int V_29 = 2 ;
* V_28 ++ = type ;
switch ( type ) {
case 0 :
* V_28 ++ = V_27 -> V_24 ;
break;
case 1 :
* V_28 ++ = 0 ;
* V_28 ++ = F_4 ( V_27 -> V_25 ) ;
memcpy ( V_28 , V_27 -> V_26 , F_4 ( V_27 -> V_25 ) ) ;
V_29 = 3 + F_4 ( V_27 -> V_25 ) ;
break;
case 2 :
memset ( V_28 , 0 , 5 ) ;
V_28 += 5 ;
* V_28 ++ = F_4 ( V_27 -> V_25 ) ;
memcpy ( V_28 , V_27 -> V_26 , F_4 ( V_27 -> V_25 ) ) ;
V_29 = 7 + F_4 ( V_27 -> V_25 ) ;
break;
}
return V_29 ;
}
int F_23 ( unsigned char * V_30 , int V_29 , struct V_21 * V_27 , unsigned char * V_31 )
{
unsigned char type ;
int V_32 = V_29 ;
int V_33 = 12 ;
V_27 -> V_24 = 0 ;
V_27 -> V_25 = F_8 ( 0 ) ;
memset ( V_27 -> V_26 , 0 , V_34 ) ;
if ( V_29 < 2 )
return - 1 ;
V_29 -= 2 ;
* V_31 = * V_30 ++ ;
type = * V_30 ++ ;
switch ( * V_31 ) {
case 0 :
V_27 -> V_24 = type ;
return 2 ;
case 1 :
V_33 = 16 ;
break;
case 2 :
V_29 -= 4 ;
V_30 += 4 ;
break;
case 4 :
V_29 -= 8 ;
V_30 += 8 ;
break;
default:
return - 1 ;
}
V_29 -= 1 ;
if ( V_29 < 0 )
return - 1 ;
V_27 -> V_25 = F_8 ( * V_30 ++ ) ;
V_29 -= F_4 ( V_27 -> V_25 ) ;
if ( ( V_29 < 0 ) || ( F_4 ( V_27 -> V_25 ) > V_33 ) )
return - 1 ;
memcpy ( V_27 -> V_26 , V_30 , F_4 ( V_27 -> V_25 ) ) ;
return V_32 - V_29 ;
}
struct V_2 * F_24 ( struct V_21 * V_6 )
{
struct V_1 * V_15 = F_20 ( V_6 ) ;
struct V_2 * V_3 ;
F_25 ( & V_18 ) ;
F_6 (sk, list) {
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_3 -> V_35 != V_36 )
continue;
if ( V_5 -> V_6 . V_24 ) {
if ( V_5 -> V_6 . V_24 != V_6 -> V_24 )
continue;
} else {
if ( V_6 -> V_24 )
continue;
if ( V_5 -> V_6 . V_25 != V_6 -> V_25 )
continue;
if ( memcmp ( V_5 -> V_6 . V_26 , V_6 -> V_26 , F_4 ( V_6 -> V_25 ) ) != 0 )
continue;
}
F_26 ( V_3 ) ;
F_27 ( & V_18 ) ;
return V_3 ;
}
V_3 = F_28 ( & V_9 ) ;
if ( V_3 ) {
if ( V_3 -> V_35 == V_36 )
F_26 ( V_3 ) ;
else
V_3 = NULL ;
}
F_27 ( & V_18 ) ;
return V_3 ;
}
struct V_2 * F_29 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_30 ( V_38 ) ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
F_25 ( & V_18 ) ;
F_6 (sk, &dn_sk_hash[le16_to_cpu(cb->dst_port) & DN_SK_HASH_MASK]) {
V_5 = F_2 ( V_3 ) ;
if ( V_40 -> V_41 != F_31 ( & V_5 -> V_42 ) )
continue;
if ( V_40 -> V_43 != V_5 -> V_11 )
continue;
if ( V_5 -> V_44 && ( V_40 -> V_45 != V_5 -> V_44 ) )
continue;
F_26 ( V_3 ) ;
goto V_46;
}
V_3 = NULL ;
V_46:
F_27 ( & V_18 ) ;
return V_3 ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_33 ( & V_5 -> V_47 ) ;
F_33 ( & V_5 -> V_48 ) ;
F_33 ( & V_5 -> V_49 ) ;
F_34 ( F_35 ( V_3 -> V_50 , 1 ) ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
if ( ! V_51 ) {
V_51 = 1 ;
}
}
static struct V_2 * F_37 ( struct V_52 * V_52 , struct V_53 * V_2 , T_2 V_54 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 = F_38 ( V_52 , V_55 , V_54 , & V_56 ) ;
if ( ! V_3 )
goto V_19;
if ( V_2 )
V_2 -> V_57 = & V_58 ;
F_39 ( V_2 , V_3 ) ;
V_3 -> V_59 = V_60 ;
V_3 -> V_61 = F_32 ;
V_3 -> V_62 = 1 ;
V_3 -> V_63 = V_55 ;
V_3 -> V_64 = 0 ;
V_3 -> V_65 = V_54 ;
V_3 -> V_66 = V_67 [ 1 ] ;
V_3 -> V_68 = V_69 [ 1 ] ;
V_5 = F_2 ( V_3 ) ;
V_5 -> V_70 = V_71 ;
V_5 -> V_72 = 1 ;
V_5 -> V_73 = 1 ;
V_5 -> V_74 = 0 ;
V_5 -> V_75 = 0 ;
V_5 -> V_76 = 0 ;
V_5 -> V_77 = 0 ;
V_5 -> V_78 = V_79 ;
V_5 -> V_80 = V_79 ;
V_5 -> V_81 = 0 ;
V_5 -> V_82 = 1 ;
V_5 -> V_83 = 0 ;
V_5 -> V_84 = 1 ;
V_5 -> V_85 = 0 ;
V_5 -> V_86 = 1 | V_87 ;
V_5 -> V_88 = 0 ;
V_5 -> V_89 = 0x03 ;
V_5 -> V_90 = 230 - V_91 ;
V_5 -> V_92 = 0 ;
V_5 -> V_93 = 1 ;
V_5 -> V_94 = V_95 ;
V_5 -> V_6 . V_96 = V_97 ;
V_5 -> V_42 . V_96 = V_97 ;
V_5 -> V_98 . V_99 = 5 ;
memcpy ( V_5 -> V_98 . V_100 , L_1 , 5 ) ;
V_5 -> V_101 = V_102 ;
V_5 -> V_103 = V_104 ;
V_5 -> V_105 = V_106 ;
V_5 -> V_107 = V_108 ;
V_5 -> V_109 = 0 ;
F_40 ( & V_5 -> V_47 ) ;
F_40 ( & V_5 -> V_48 ) ;
F_40 ( & V_5 -> V_49 ) ;
V_5 -> V_110 = 0 ;
V_5 -> V_111 = NULL ;
V_5 -> V_112 = 10 * V_113 ;
V_5 -> V_114 = V_115 ;
F_41 ( & V_5 -> V_116 ) ;
V_5 -> V_117 = 0 ;
V_5 -> V_118 = V_119 ;
F_42 ( V_3 ) ;
V_19:
return V_3 ;
}
static void V_115 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( F_43 ( & V_5 -> V_48 ) )
F_44 ( V_3 , V_120 , 0 ) ;
}
int F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_5 -> V_110 = F_46 ( V_3 ) ;
switch ( V_5 -> V_70 ) {
case V_121 :
F_47 ( V_3 , V_122 , 0 , V_123 ) ;
if ( V_5 -> V_109 >= V_124 )
V_5 -> V_70 = V_125 ;
return 0 ;
case V_126 :
F_47 ( V_3 , V_122 , 0 , V_123 ) ;
if ( V_5 -> V_109 >= V_127 )
V_5 -> V_70 = V_128 ;
return 0 ;
case V_129 :
if ( V_5 -> V_109 < V_130 ) {
F_47 ( V_3 , V_131 , V_132 ,
V_123 ) ;
return 0 ;
}
}
V_5 -> V_110 = ( V_113 * V_133 ) ;
if ( V_3 -> V_134 )
return 0 ;
if ( F_48 ( V_135 , V_5 -> V_136 + V_113 * V_133 ) ) {
F_15 ( V_3 ) ;
F_49 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_5 -> V_109 = 0 ;
if ( V_3 -> V_134 ) {
if ( V_3 -> V_134 -> V_70 != V_137 )
V_3 -> V_134 -> V_70 = V_138 ;
}
V_3 -> V_35 = V_139 ;
switch ( V_5 -> V_70 ) {
case V_129 :
F_47 ( V_3 , V_131 , V_132 ,
V_3 -> V_65 ) ;
V_5 -> V_111 = F_45 ;
V_5 -> V_110 = F_46 ( V_3 ) ;
break;
case V_140 :
V_5 -> V_70 = V_126 ;
goto V_141;
case V_142 :
V_5 -> V_70 = V_121 ;
case V_121 :
case V_126 :
V_141:
F_47 ( V_3 , V_122 , 0 , V_3 -> V_65 ) ;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_125 :
case V_128 :
case V_147 :
case V_148 :
V_5 -> V_111 = F_45 ;
V_5 -> V_110 = F_46 ( V_3 ) ;
break;
default:
F_51 ( V_149 L_2 ) ;
case V_71 :
F_52 ( V_3 ) ;
F_19 ( V_3 ) ;
F_49 ( V_3 ) ;
break;
}
}
char * F_53 ( T_3 V_6 , char * V_28 )
{
unsigned short V_150 , V_151 ;
V_150 = V_6 & 0x03ff ;
V_151 = V_6 >> 10 ;
sprintf ( V_28 , L_3 , V_151 , V_150 ) ;
return V_28 ;
}
static int F_54 ( struct V_52 * V_52 , struct V_53 * V_2 , int V_152 ,
int V_153 )
{
struct V_2 * V_3 ;
if ( ! F_55 ( V_52 , & V_154 ) )
return - V_155 ;
switch ( V_2 -> type ) {
case V_156 :
if ( V_152 != V_157 )
return - V_158 ;
break;
case V_159 :
break;
default:
return - V_160 ;
}
if ( ( V_3 = F_37 ( V_52 , V_2 , V_161 ) ) == NULL )
return - V_162 ;
V_3 -> V_64 = V_152 ;
return 0 ;
}
static int
F_56 ( struct V_53 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 ) {
F_57 ( V_3 ) ;
F_26 ( V_3 ) ;
F_58 ( V_3 ) ;
F_50 ( V_3 ) ;
F_59 ( V_3 ) ;
F_49 ( V_3 ) ;
}
return 0 ;
}
static int F_60 ( struct V_53 * V_2 , struct V_163 * V_164 , int V_165 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_21 * V_166 = (struct V_21 * ) V_164 ;
struct V_167 * V_168 , * V_169 ;
int V_16 ;
if ( V_165 != sizeof( struct V_21 ) )
return - V_170 ;
if ( V_166 -> V_96 != V_97 )
return - V_170 ;
if ( F_4 ( V_166 -> V_171 ) && ( F_4 ( V_166 -> V_171 ) != 2 ) )
return - V_170 ;
if ( F_4 ( V_166 -> V_25 ) > V_34 )
return - V_170 ;
if ( V_166 -> V_7 & ~ V_8 )
return - V_170 ;
if ( ! F_61 ( V_172 ) && ( V_166 -> V_24 ||
( V_166 -> V_7 & V_8 ) ) )
return - V_173 ;
if ( ! ( V_166 -> V_7 & V_8 ) ) {
if ( F_4 ( V_166 -> V_171 ) ) {
F_62 () ;
V_169 = NULL ;
F_63 (&init_net, dev) {
if ( ! V_168 -> V_174 )
continue;
if ( F_64 ( V_168 , F_31 ( V_166 ) ) ) {
V_169 = V_168 ;
break;
}
}
F_65 () ;
if ( V_169 == NULL )
return - V_175 ;
}
}
V_16 = - V_170 ;
F_58 ( V_3 ) ;
if ( F_66 ( V_3 , V_176 ) ) {
memcpy ( & V_5 -> V_6 , V_166 , V_165 ) ;
F_67 ( V_3 , V_176 ) ;
V_16 = F_9 ( V_3 ) ;
if ( V_16 )
F_68 ( V_3 , V_176 ) ;
}
F_59 ( V_3 ) ;
return V_16 ;
}
static int F_69 ( struct V_53 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_16 ;
F_67 ( V_3 , V_176 ) ;
V_5 -> V_6 . V_7 = 0 ;
V_5 -> V_6 . V_24 = 0 ;
if ( ( V_5 -> V_98 . V_99 != 0 ) &&
( V_5 -> V_98 . V_99 <= 12 ) ) {
V_5 -> V_6 . V_25 = F_8 ( V_5 -> V_98 . V_99 ) ;
memcpy ( V_5 -> V_6 . V_26 , V_5 -> V_98 . V_100 , F_4 ( V_5 -> V_6 . V_25 ) ) ;
V_5 -> V_98 . V_99 = 0 ;
memset ( V_5 -> V_98 . V_100 , 0 , 40 ) ;
}
V_5 -> V_6 . V_177 . V_178 = F_8 ( 2 ) ;
V_16 = F_70 ( ( T_1 * ) V_5 -> V_6 . V_177 . V_179 ) ;
if ( V_16 == 0 ) {
V_16 = F_9 ( V_3 ) ;
if ( V_16 )
F_68 ( V_3 , V_176 ) ;
}
return V_16 ;
}
static int F_71 ( struct V_2 * V_3 , long * V_180 , T_2 V_181 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_72 ( V_182 ) ;
int V_183 ;
if ( V_5 -> V_70 != V_140 )
return - V_170 ;
V_5 -> V_70 = V_184 ;
V_5 -> V_185 = F_73 ( F_74 ( V_3 ) ) ;
F_75 ( V_3 , V_181 ) ;
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
for(; ; ) {
F_59 ( V_3 ) ;
if ( V_5 -> V_70 == V_184 )
* V_180 = F_78 ( * V_180 ) ;
F_58 ( V_3 ) ;
V_183 = 0 ;
if ( V_5 -> V_70 == V_142 )
break;
V_183 = F_79 ( V_3 ) ;
if ( V_183 )
break;
V_183 = F_80 ( * V_180 ) ;
if ( F_81 ( V_187 ) )
break;
V_183 = - V_188 ;
if ( ! * V_180 )
break;
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
}
F_82 ( F_77 ( V_3 ) , & V_182 ) ;
if ( V_183 == 0 ) {
V_3 -> V_134 -> V_70 = V_189 ;
} else if ( V_5 -> V_70 != V_184 ) {
V_3 -> V_134 -> V_70 = V_137 ;
}
return V_183 ;
}
static int F_83 ( struct V_2 * V_3 , long * V_180 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_72 ( V_182 ) ;
int V_183 = 0 ;
if ( V_5 -> V_70 == V_142 )
goto V_19;
if ( ! * V_180 )
return - V_190 ;
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
for(; ; ) {
F_59 ( V_3 ) ;
if ( V_5 -> V_70 == V_147 || V_5 -> V_70 == V_184 )
* V_180 = F_78 ( * V_180 ) ;
F_58 ( V_3 ) ;
V_183 = 0 ;
if ( V_5 -> V_70 == V_142 )
break;
V_183 = F_79 ( V_3 ) ;
if ( V_183 )
break;
V_183 = F_80 ( * V_180 ) ;
if ( F_81 ( V_187 ) )
break;
V_183 = - V_191 ;
if ( ! * V_180 )
break;
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
}
F_82 ( F_77 ( V_3 ) , & V_182 ) ;
V_19:
if ( V_183 == 0 ) {
V_3 -> V_134 -> V_70 = V_189 ;
} else if ( V_5 -> V_70 != V_147 && V_5 -> V_70 != V_184 ) {
V_3 -> V_134 -> V_70 = V_137 ;
}
return V_183 ;
}
static int F_84 ( struct V_2 * V_3 , struct V_21 * V_6 , int V_192 , long * V_180 , int V_193 )
{
struct V_53 * V_2 = V_3 -> V_134 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_183 = - V_194 ;
struct V_195 V_196 ;
struct V_197 * V_198 ;
if ( V_2 -> V_70 == V_189 )
goto V_19;
if ( V_2 -> V_70 == V_199 ) {
V_183 = 0 ;
if ( V_5 -> V_70 == V_142 ) {
V_2 -> V_70 = V_189 ;
goto V_19;
}
V_183 = - V_200 ;
if ( V_5 -> V_70 != V_147 && V_5 -> V_70 != V_184 ) {
V_2 -> V_70 = V_137 ;
goto V_19;
}
return F_83 ( V_3 , V_180 ) ;
}
V_183 = - V_170 ;
if ( V_5 -> V_70 != V_71 )
goto V_19;
if ( V_6 == NULL || V_192 != sizeof( struct V_21 ) )
goto V_19;
if ( V_6 -> V_96 != V_97 )
goto V_19;
if ( V_6 -> V_7 & V_8 )
goto V_19;
if ( F_66 ( V_3 , V_176 ) ) {
V_183 = F_69 ( V_3 -> V_134 ) ;
if ( V_183 )
goto V_19;
}
memcpy ( & V_5 -> V_42 , V_6 , sizeof( struct V_21 ) ) ;
V_183 = - V_201 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_196 . V_202 = V_3 -> V_203 ;
V_196 . V_204 = F_31 ( & V_5 -> V_42 ) ;
V_196 . V_166 = F_31 ( & V_5 -> V_6 ) ;
F_85 ( & V_196 , V_5 ) ;
V_196 . V_205 = V_157 ;
if ( F_86 ( & V_3 -> V_50 , & V_196 , V_3 , V_193 ) < 0 )
goto V_19;
V_198 = F_74 ( V_3 ) ;
V_3 -> V_206 = V_198 -> V_168 -> V_207 ;
V_2 -> V_70 = V_199 ;
V_5 -> V_70 = V_147 ;
V_5 -> V_185 = F_73 ( V_198 ) ;
F_87 ( V_3 , V_208 ) ;
V_183 = - V_209 ;
if ( * V_180 ) {
V_183 = F_83 ( V_3 , V_180 ) ;
}
V_19:
return V_183 ;
}
static int F_88 ( struct V_53 * V_2 , struct V_163 * V_164 , int V_192 , int V_193 )
{
struct V_21 * V_6 = (struct V_21 * ) V_164 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_183 ;
long V_180 = F_89 ( V_3 , V_193 & V_210 ) ;
F_58 ( V_3 ) ;
V_183 = F_84 ( V_3 , V_6 , V_192 , & V_180 , 0 ) ;
F_59 ( V_3 ) ;
return V_183 ;
}
static inline int F_90 ( struct V_2 * V_3 , struct V_21 * V_6 , int V_192 , long * V_180 , int V_193 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
switch ( V_5 -> V_70 ) {
case V_142 :
return 0 ;
case V_140 :
return F_71 ( V_3 , V_180 , V_3 -> V_65 ) ;
case V_147 :
case V_184 :
return F_83 ( V_3 , V_180 ) ;
case V_71 :
return F_84 ( V_3 , V_6 , V_192 , V_180 , V_193 ) ;
}
return - V_170 ;
}
static void F_91 ( struct V_37 * V_38 , struct V_211 * V_212 )
{
unsigned char * V_213 = V_38 -> V_30 ;
V_212 -> V_214 = * V_213 ++ ;
memcpy ( & V_212 -> V_215 , V_213 , V_212 -> V_214 ) ;
V_213 += V_212 -> V_214 ;
V_212 -> V_216 = * V_213 ++ ;
memcpy ( & V_212 -> V_217 , V_213 , V_212 -> V_216 ) ;
V_213 += V_212 -> V_216 ;
V_212 -> V_99 = * V_213 ++ ;
memcpy ( & V_212 -> V_100 , V_213 , V_212 -> V_99 ) ;
F_92 ( V_38 , V_212 -> V_99 + V_212 -> V_216 + V_212 -> V_214 + 3 ) ;
}
static void F_93 ( struct V_37 * V_38 , struct V_218 * V_219 )
{
unsigned char * V_213 = V_38 -> V_30 ;
T_4 V_29 = * V_213 ++ ;
F_10 ( V_29 > 16 ) ;
V_219 -> V_220 = F_8 ( V_29 ) ;
V_219 -> V_221 = 0 ;
memcpy ( V_219 -> V_222 , V_213 , V_29 ) ;
F_92 ( V_38 , V_29 + 1 ) ;
}
static struct V_37 * F_94 ( struct V_2 * V_3 , long * V_180 )
{
F_72 ( V_182 ) ;
struct V_37 * V_38 = NULL ;
int V_183 = 0 ;
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
for(; ; ) {
F_59 ( V_3 ) ;
V_38 = F_95 ( & V_3 -> V_223 ) ;
if ( V_38 == NULL ) {
* V_180 = F_78 ( * V_180 ) ;
V_38 = F_95 ( & V_3 -> V_223 ) ;
}
F_58 ( V_3 ) ;
if ( V_38 != NULL )
break;
V_183 = - V_170 ;
if ( V_3 -> V_35 != V_36 )
break;
V_183 = F_80 ( * V_180 ) ;
if ( F_81 ( V_187 ) )
break;
V_183 = - V_188 ;
if ( ! * V_180 )
break;
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
}
F_82 ( F_77 ( V_3 ) , & V_182 ) ;
return V_38 == NULL ? F_96 ( V_183 ) : V_38 ;
}
static int F_97 ( struct V_53 * V_2 , struct V_53 * V_224 , int V_193 )
{
struct V_2 * V_3 = V_2 -> V_3 , * V_225 ;
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
unsigned char V_226 ;
int V_183 = 0 ;
unsigned char type ;
long V_180 = F_98 ( V_3 , V_193 & V_210 ) ;
struct V_197 * V_198 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_35 != V_36 || F_2 ( V_3 ) -> V_70 != V_71 ) {
F_59 ( V_3 ) ;
return - V_170 ;
}
V_38 = F_95 ( & V_3 -> V_223 ) ;
if ( V_38 == NULL ) {
V_38 = F_94 ( V_3 , & V_180 ) ;
if ( F_99 ( V_38 ) ) {
F_59 ( V_3 ) ;
return F_100 ( V_38 ) ;
}
}
V_40 = F_30 ( V_38 ) ;
V_3 -> V_227 -- ;
V_225 = F_37 ( F_101 ( V_3 ) , V_224 , V_3 -> V_65 ) ;
if ( V_225 == NULL ) {
F_59 ( V_3 ) ;
F_102 ( V_38 ) ;
return - V_162 ;
}
F_59 ( V_3 ) ;
V_198 = F_103 ( V_38 ) ;
F_104 ( V_225 , V_198 ) ;
F_105 ( V_38 , NULL ) ;
F_2 ( V_225 ) -> V_70 = V_140 ;
F_2 ( V_225 ) -> V_44 = V_40 -> V_45 ;
F_2 ( V_225 ) -> V_85 = V_40 -> V_228 ;
F_2 ( V_225 ) -> V_88 = V_40 -> V_229 ;
F_2 ( V_225 ) -> V_90 = V_40 -> V_230 ;
F_2 ( V_225 ) -> V_94 = F_2 ( V_3 ) -> V_94 ;
if ( F_2 ( V_225 ) -> V_90 < 230 )
F_2 ( V_225 ) -> V_90 = 230 ;
if ( ( F_2 ( V_225 ) -> V_85 & V_231 ) == V_87 )
F_2 ( V_225 ) -> V_101 = V_232 ;
V_225 -> V_35 = V_36 ;
memcpy ( & ( F_2 ( V_225 ) -> V_6 ) , & ( F_2 ( V_3 ) -> V_6 ) , sizeof( struct V_21 ) ) ;
F_2 ( V_225 ) -> V_6 . V_7 &= ~ V_8 ;
F_92 ( V_38 , F_23 ( V_38 -> V_30 , V_38 -> V_29 , & ( F_2 ( V_225 ) -> V_6 ) , & type ) ) ;
F_92 ( V_38 , F_23 ( V_38 -> V_30 , V_38 -> V_29 , & ( F_2 ( V_225 ) -> V_42 ) , & type ) ) ;
* ( T_1 * ) ( F_2 ( V_225 ) -> V_42 . V_177 . V_179 ) = V_40 -> V_41 ;
* ( T_1 * ) ( F_2 ( V_225 ) -> V_6 . V_177 . V_179 ) = V_40 -> V_198 ;
V_226 = * V_38 -> V_30 ;
F_92 ( V_38 , 1 ) ;
if ( V_226 & V_233 )
F_91 ( V_38 , & ( F_2 ( V_225 ) -> V_98 ) ) ;
if ( V_226 & V_234 )
F_93 ( V_38 , & ( F_2 ( V_225 ) -> V_235 ) ) ;
if ( V_226 & V_236 )
F_2 ( V_225 ) -> V_42 . V_7 |= V_237 ;
if ( V_226 & V_238 )
F_2 ( V_225 ) -> V_42 . V_7 |= V_239 ;
F_102 ( V_38 ) ;
memcpy ( & ( F_2 ( V_225 ) -> V_240 ) , & ( F_2 ( V_3 ) -> V_240 ) ,
sizeof( struct V_218 ) ) ;
memcpy ( & ( F_2 ( V_225 ) -> V_241 ) , & ( F_2 ( V_3 ) -> V_241 ) ,
sizeof( struct V_218 ) ) ;
F_58 ( V_225 ) ;
V_183 = F_9 ( V_225 ) ;
if ( V_183 == 0 ) {
F_67 ( V_225 , V_176 ) ;
F_106 ( V_225 ) ;
if ( F_2 ( V_225 ) -> V_94 == V_95 )
V_183 = F_71 ( V_225 , & V_180 ,
V_3 -> V_65 ) ;
}
F_59 ( V_225 ) ;
return V_183 ;
}
static int F_107 ( struct V_53 * V_2 , struct V_163 * V_164 , int * V_242 , int V_42 )
{
struct V_21 * V_243 = (struct V_21 * ) V_164 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
* V_242 = sizeof( struct V_21 ) ;
F_58 ( V_3 ) ;
if ( V_42 ) {
if ( ( V_2 -> V_70 != V_189 &&
V_2 -> V_70 != V_199 ) &&
V_5 -> V_94 == V_95 ) {
F_59 ( V_3 ) ;
return - V_244 ;
}
memcpy ( V_243 , & V_5 -> V_42 , sizeof( struct V_21 ) ) ;
} else {
memcpy ( V_243 , & V_5 -> V_6 , sizeof( struct V_21 ) ) ;
}
F_59 ( V_3 ) ;
return 0 ;
}
static unsigned int F_108 ( struct V_245 * V_245 , struct V_53 * V_2 , T_5 * V_182 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_246 = F_109 ( V_245 , V_2 , V_182 ) ;
if ( ! F_43 ( & V_5 -> V_49 ) )
V_246 |= V_247 ;
return V_246 ;
}
static int F_110 ( struct V_53 * V_2 , unsigned int V_248 , unsigned long V_249 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_183 = - V_250 ;
long V_251 = 0 ;
struct V_37 * V_38 ;
int V_252 ;
switch( V_248 )
{
case V_253 :
case V_254 :
return F_111 ( V_248 , ( void V_255 * ) V_249 ) ;
case V_256 :
F_58 ( V_3 ) ;
V_252 = ! F_43 ( & V_5 -> V_49 ) ;
if ( V_5 -> V_70 != V_142 )
V_252 = - V_244 ;
F_59 ( V_3 ) ;
return V_252 ;
case V_257 :
V_251 = V_3 -> V_66 - F_112 ( V_3 ) ;
if ( V_251 < 0 )
V_251 = 0 ;
V_183 = F_113 ( V_251 , ( int V_255 * ) V_249 ) ;
break;
case V_258 :
F_58 ( V_3 ) ;
V_38 = F_114 ( & V_5 -> V_49 ) ;
if ( V_38 ) {
V_251 = V_38 -> V_29 ;
} else {
F_115 (&sk->sk_receive_queue, skb)
V_251 += V_38 -> V_29 ;
}
F_59 ( V_3 ) ;
V_183 = F_113 ( V_251 , ( int V_255 * ) V_249 ) ;
break;
default:
V_183 = - V_259 ;
break;
}
return V_183 ;
}
static int F_116 ( struct V_53 * V_2 , int V_260 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_183 = - V_170 ;
F_58 ( V_3 ) ;
if ( F_66 ( V_3 , V_176 ) )
goto V_19;
if ( ( F_2 ( V_3 ) -> V_70 != V_71 ) || ( V_3 -> V_35 == V_36 ) )
goto V_19;
V_3 -> V_261 = V_260 ;
V_3 -> V_227 = 0 ;
V_3 -> V_35 = V_36 ;
V_183 = 0 ;
F_21 ( V_3 ) ;
V_19:
F_59 ( V_3 ) ;
return V_183 ;
}
static int F_117 ( struct V_53 * V_2 , int V_262 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_183 = - V_244 ;
F_58 ( V_3 ) ;
if ( V_2 -> V_70 == V_137 )
goto V_19;
V_183 = 0 ;
if ( V_2 -> V_70 == V_138 )
goto V_19;
V_183 = - V_170 ;
if ( V_5 -> V_70 == V_71 )
goto V_19;
if ( V_262 != V_263 )
goto V_19;
V_3 -> V_264 = V_265 ;
F_50 ( V_3 ) ;
V_183 = 0 ;
V_19:
F_59 ( V_3 ) ;
return V_183 ;
}
static int F_118 ( struct V_53 * V_2 , int V_266 , int V_267 , char V_255 * V_268 , unsigned int V_269 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_183 ;
F_58 ( V_3 ) ;
V_183 = F_119 ( V_2 , V_266 , V_267 , V_268 , V_269 , 0 ) ;
F_59 ( V_3 ) ;
return V_183 ;
}
static int F_119 ( struct V_53 * V_2 , int V_266 , int V_267 , char V_255 * V_268 , unsigned int V_269 , int V_193 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
long V_180 ;
union {
struct V_218 V_219 ;
struct V_211 V_212 ;
int V_270 ;
unsigned long V_271 ;
int V_252 ;
unsigned char V_228 ;
unsigned char V_229 ;
} V_272 ;
int V_183 ;
if ( V_269 && ! V_268 )
return - V_170 ;
if ( V_269 > sizeof( V_272 ) )
return - V_170 ;
if ( F_120 ( & V_272 , V_268 , V_269 ) )
return - V_273 ;
switch ( V_267 ) {
case V_274 :
if ( V_2 -> V_70 == V_189 )
return - V_194 ;
if ( ( V_5 -> V_70 != V_71 ) && ( V_5 -> V_70 != V_140 ) )
return - V_170 ;
if ( V_269 != sizeof( struct V_218 ) )
return - V_170 ;
if ( F_4 ( V_272 . V_219 . V_220 ) > 16 )
return - V_170 ;
memcpy ( & V_5 -> V_240 , & V_272 . V_219 , V_269 ) ;
break;
case V_275 :
if ( V_2 -> V_70 != V_189 &&
V_5 -> V_94 == V_95 )
return - V_244 ;
if ( V_269 != sizeof( struct V_218 ) )
return - V_170 ;
if ( F_4 ( V_272 . V_219 . V_220 ) > 16 )
return - V_170 ;
memcpy ( & V_5 -> V_241 , & V_272 . V_219 , V_269 ) ;
break;
case V_276 :
if ( V_2 -> V_70 == V_189 )
return - V_194 ;
if ( V_5 -> V_70 != V_71 )
return - V_170 ;
if ( V_269 != sizeof( struct V_211 ) )
return - V_170 ;
if ( ( V_272 . V_212 . V_99 > V_277 ) ||
( V_272 . V_212 . V_216 > V_277 ) ||
( V_272 . V_212 . V_214 > V_277 ) )
return - V_170 ;
memcpy ( & V_5 -> V_98 , & V_272 . V_212 , V_269 ) ;
break;
case V_278 :
if ( V_2 -> V_70 == V_189 )
return - V_194 ;
if ( V_5 -> V_70 != V_71 )
return - V_170 ;
if ( V_269 != sizeof( int ) )
return - V_170 ;
if ( ( V_272 . V_270 != V_95 ) && ( V_272 . V_270 != V_279 ) )
return - V_170 ;
V_5 -> V_94 = ( unsigned char ) V_272 . V_270 ;
break;
case V_280 :
if ( V_5 -> V_70 != V_140 )
return - V_170 ;
V_180 = F_98 ( V_3 , 0 ) ;
V_183 = F_71 ( V_3 , & V_180 , V_3 -> V_65 ) ;
return V_183 ;
case V_281 :
if ( V_5 -> V_70 != V_140 )
return - V_170 ;
V_5 -> V_70 = V_126 ;
V_3 -> V_264 = V_265 ;
F_47 ( V_3 , 0x38 , 0 , V_3 -> V_65 ) ;
break;
default:
#ifdef F_121
return F_122 ( V_3 , V_55 , V_267 , V_268 , V_269 ) ;
#endif
case V_282 :
case V_283 :
case V_284 :
return - V_285 ;
case V_286 :
if ( V_269 != sizeof( unsigned long ) )
return - V_170 ;
if ( V_272 . V_271 > V_102 )
V_272 . V_271 = V_102 ;
if ( V_272 . V_271 == 0 )
return - V_170 ;
V_5 -> V_101 = V_272 . V_271 ;
if ( V_5 -> V_103 > V_272 . V_271 )
V_5 -> V_103 = V_272 . V_271 ;
break;
case V_287 :
if ( V_269 != sizeof( int ) )
return - V_170 ;
if ( V_5 -> V_92 == 2 )
return - V_170 ;
V_5 -> V_92 = ( V_272 . V_252 == 0 ) ? 0 : 1 ;
break;
case V_288 :
if ( V_269 != sizeof( int ) )
return - V_170 ;
if ( V_5 -> V_92 == 1 )
return - V_170 ;
V_5 -> V_92 = ( V_272 . V_252 == 0 ) ? 0 : 2 ;
break;
case V_289 :
if ( V_269 != sizeof( unsigned char ) )
return - V_170 ;
if ( ( V_272 . V_228 & ~ V_231 ) != 0x01 )
return - V_170 ;
if ( ( V_272 . V_228 & V_231 ) == V_231 )
return - V_170 ;
V_5 -> V_86 = V_272 . V_228 ;
break;
case V_290 :
if ( V_269 != sizeof( unsigned char ) )
return - V_170 ;
if ( V_272 . V_229 & 0xfc )
return - V_170 ;
V_5 -> V_89 = V_272 . V_229 ;
break;
}
return 0 ;
}
static int F_123 ( struct V_53 * V_2 , int V_266 , int V_267 , char V_255 * V_268 , int V_255 * V_269 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_183 ;
F_58 ( V_3 ) ;
V_183 = F_124 ( V_2 , V_266 , V_267 , V_268 , V_269 , 0 ) ;
F_59 ( V_3 ) ;
return V_183 ;
}
static int F_124 ( struct V_53 * V_2 , int V_266 , int V_267 , char V_255 * V_268 , int V_255 * V_269 , int V_193 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_291 V_292 ;
unsigned int V_293 ;
void * V_294 = NULL ;
unsigned int V_252 ;
if( F_125 ( V_293 , V_269 ) )
return - V_273 ;
switch ( V_267 ) {
case V_274 :
if ( V_293 > sizeof( struct V_218 ) )
V_293 = sizeof( struct V_218 ) ;
V_294 = & V_5 -> V_235 ;
break;
case V_275 :
if ( V_293 > sizeof( struct V_218 ) )
V_293 = sizeof( struct V_218 ) ;
V_294 = & V_5 -> V_295 ;
break;
case V_276 :
if ( V_293 > sizeof( struct V_211 ) )
V_293 = sizeof( struct V_211 ) ;
V_294 = & V_5 -> V_98 ;
break;
case V_278 :
if ( V_293 > sizeof( unsigned char ) )
V_293 = sizeof( unsigned char ) ;
V_294 = & V_5 -> V_94 ;
break;
case V_282 :
if ( V_293 > sizeof( struct V_291 ) )
V_293 = sizeof( struct V_291 ) ;
memset ( & V_292 , 0 , sizeof( V_292 ) ) ;
switch ( V_2 -> V_70 ) {
case V_199 :
V_292 . V_296 = V_297 ;
break;
case V_138 :
V_292 . V_296 = V_298 ;
break;
case V_189 :
V_292 . V_296 = V_299 ;
break;
default:
V_292 . V_296 = V_300 ;
}
V_292 . V_301 = V_5 -> V_90 ;
V_294 = & V_292 ;
break;
default:
#ifdef F_121
{
int V_302 , V_29 ;
if ( F_125 ( V_29 , V_269 ) )
return - V_273 ;
V_302 = F_126 ( V_3 , V_55 , V_267 , V_268 , & V_29 ) ;
if ( V_302 >= 0 )
V_302 = F_113 ( V_29 , V_269 ) ;
return V_302 ;
}
#endif
case V_283 :
case V_284 :
case V_280 :
case V_281 :
return - V_285 ;
case V_286 :
if ( V_293 > sizeof( unsigned long ) )
V_293 = sizeof( unsigned long ) ;
V_294 = & V_5 -> V_101 ;
break;
case V_287 :
if ( V_293 > sizeof( int ) )
V_293 = sizeof( int ) ;
V_252 = ( V_5 -> V_92 == 1 ) ;
V_294 = & V_252 ;
break;
case V_288 :
if ( V_293 > sizeof( int ) )
V_293 = sizeof( int ) ;
V_252 = ( V_5 -> V_92 == 2 ) ;
V_294 = & V_252 ;
break;
case V_289 :
if ( V_293 > sizeof( unsigned char ) )
V_293 = sizeof( unsigned char ) ;
V_294 = & V_5 -> V_85 ;
break;
case V_290 :
if ( V_293 > sizeof( unsigned char ) )
V_293 = sizeof( unsigned char ) ;
V_294 = & V_5 -> V_88 ;
break;
}
if ( V_294 ) {
if ( F_127 ( V_268 , V_294 , V_293 ) )
return - V_273 ;
if ( F_113 ( V_293 , V_269 ) )
return - V_273 ;
}
return 0 ;
}
static int F_128 ( struct V_2 * V_3 , struct V_303 * V_304 , int V_193 , int V_305 )
{
struct V_37 * V_38 ;
int V_29 = 0 ;
if ( V_193 & V_306 )
return ! F_43 ( V_304 ) ? 1 : 0 ;
F_115 (q, skb) {
struct V_39 * V_40 = F_30 ( V_38 ) ;
V_29 += V_38 -> V_29 ;
if ( V_40 -> V_307 & 0x40 ) {
if ( V_3 -> V_308 == V_156 )
return 1 ;
if ( ! ( V_193 & V_309 ) )
return 1 ;
}
if ( V_29 >= V_305 )
return 1 ;
}
return 0 ;
}
static int F_129 ( struct V_310 * V_311 , struct V_53 * V_2 ,
struct V_312 * V_313 , T_6 V_32 , int V_193 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_303 * V_314 = & V_3 -> V_223 ;
T_6 V_305 = V_32 > 1 ? 1 : 0 ;
T_6 V_315 = 0 ;
int V_16 = 0 ;
struct V_37 * V_38 , * V_316 ;
struct V_39 * V_40 = NULL ;
unsigned char V_317 = 0 ;
long V_180 = F_98 ( V_3 , V_193 & V_318 ) ;
F_58 ( V_3 ) ;
if ( F_66 ( V_3 , V_176 ) ) {
V_16 = - V_175 ;
goto V_19;
}
if ( V_3 -> V_264 & V_319 ) {
V_16 = 0 ;
goto V_19;
}
V_16 = F_90 ( V_3 , NULL , 0 , & V_180 , V_193 ) ;
if ( V_16 )
goto V_19;
if ( V_193 & ~ ( V_320 | V_321 | V_306 | V_309 | V_318 | V_322 ) ) {
V_16 = - V_250 ;
goto V_19;
}
if ( V_193 & V_306 )
V_314 = & V_5 -> V_49 ;
if ( V_193 & V_309 )
V_305 = V_32 ;
for(; ; ) {
F_72 ( V_182 ) ;
if ( V_3 -> V_323 )
goto V_19;
if ( ! F_43 ( & V_5 -> V_49 ) ) {
if ( ! ( V_193 & V_306 ) ) {
V_313 -> V_324 |= V_306 ;
if ( ! V_5 -> V_325 ) {
V_5 -> V_325 = 1 ;
goto V_19;
}
}
}
if ( V_5 -> V_70 != V_142 )
goto V_19;
if ( F_81 ( V_187 ) ) {
V_16 = F_80 ( V_180 ) ;
goto V_19;
}
if ( F_128 ( V_3 , V_314 , V_193 , V_305 ) )
break;
if ( V_193 & V_318 ) {
V_16 = - V_326 ;
goto V_19;
}
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
F_130 ( V_327 , & V_3 -> V_134 -> V_193 ) ;
F_131 ( V_3 , & V_180 , F_128 ( V_3 , V_314 , V_193 , V_305 ) ) ;
F_132 ( V_327 , & V_3 -> V_134 -> V_193 ) ;
F_82 ( F_77 ( V_3 ) , & V_182 ) ;
}
F_133 (queue, skb, n) {
unsigned int V_328 = V_38 -> V_29 ;
V_40 = F_30 ( V_38 ) ;
if ( ( V_328 + V_315 ) > V_32 )
V_328 = V_32 - V_315 ;
if ( F_134 ( V_313 , V_38 -> V_30 , V_328 ) ) {
V_16 = - V_273 ;
break;
}
V_315 += V_328 ;
if ( ! ( V_193 & V_321 ) )
F_92 ( V_38 , V_328 ) ;
V_317 = V_40 -> V_307 & 0x40 ;
if ( V_38 -> V_29 == 0 ) {
F_135 ( V_38 , V_314 ) ;
F_102 ( V_38 ) ;
if ( ( V_5 -> V_80 == V_329 ) && ! F_136 ( V_3 ) ) {
V_5 -> V_80 = V_79 ;
F_44 ( V_3 , V_79 , 0 ) ;
}
}
if ( V_317 ) {
if ( V_3 -> V_308 == V_156 )
break;
if ( ! ( V_193 & V_309 ) )
break;
}
if ( V_193 & V_306 )
break;
if ( V_315 >= V_305 )
break;
}
V_16 = V_315 ;
if ( V_317 && ( V_3 -> V_308 == V_156 ) )
V_313 -> V_324 |= V_330 ;
V_19:
if ( V_16 == 0 )
V_16 = ( V_193 & V_321 ) ? - V_3 -> V_323 : F_79 ( V_3 ) ;
if ( ( V_16 >= 0 ) && V_313 -> V_331 ) {
F_137 ( sizeof( struct V_21 ) ) ;
memcpy ( V_313 -> V_331 , & V_5 -> V_42 , sizeof( struct V_21 ) ) ;
V_313 -> V_332 = sizeof( struct V_21 ) ;
}
F_59 ( V_3 ) ;
return V_16 ;
}
static inline int F_138 ( struct V_4 * V_5 , struct V_303 * V_314 , int V_193 )
{
unsigned char V_333 = V_5 -> V_85 & V_231 ;
if ( F_139 ( V_314 ) >= V_5 -> V_103 )
return 1 ;
if ( V_333 != V_87 ) {
if ( V_193 & V_306 ) {
if ( V_5 -> V_82 == 0 )
return 1 ;
} else {
if ( V_5 -> V_81 == 0 )
return 1 ;
}
}
return 0 ;
}
unsigned int F_140 ( struct V_167 * V_168 , int V_334 )
{
unsigned int V_335 = 230 - V_91 ;
if ( V_168 ) {
struct V_336 * V_337 = F_141 ( V_168 -> V_174 ) ;
V_334 -= F_142 ( V_168 ) ;
if ( V_337 -> V_338 )
V_334 -= 21 ;
else
V_334 -= 6 ;
V_334 -= V_91 ;
} else {
V_334 -= ( 21 + V_91 + 16 ) ;
}
if ( V_334 > V_335 )
V_335 = V_334 ;
return V_335 ;
}
static inline unsigned int F_143 ( struct V_2 * V_3 , int V_193 )
{
struct V_197 * V_198 = F_74 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_339 = F_144 ( int , V_5 -> V_185 , V_5 -> V_90 ) ;
if ( V_193 & V_306 )
return 16 ;
if ( V_198 ) {
T_7 V_334 = F_145 ( V_198 ) ;
V_339 = F_144 ( int , F_140 ( V_198 -> V_168 , V_334 ) , V_339 ) ;
}
return V_339 ;
}
static inline struct V_37 * F_146 ( struct V_2 * V_3 ,
unsigned long V_340 , int V_341 ,
int * V_342 )
{
struct V_37 * V_38 = F_147 ( V_3 , V_340 ,
V_341 , V_342 ) ;
if ( V_38 ) {
V_38 -> V_152 = F_148 ( V_343 ) ;
V_38 -> V_344 = V_345 ;
}
return V_38 ;
}
static int F_149 ( struct V_310 * V_311 , struct V_53 * V_2 ,
struct V_312 * V_313 , T_6 V_32 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_6 V_335 ;
struct V_303 * V_314 = & V_5 -> V_47 ;
int V_193 = V_313 -> V_324 ;
int V_183 = 0 ;
T_6 V_346 = 0 ;
int V_165 = V_313 -> V_332 ;
F_150 ( struct V_21 * , V_6 , V_313 -> V_331 ) ;
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
T_6 V_29 ;
unsigned char V_333 ;
long V_180 ;
if ( V_193 & ~ ( V_347 | V_306 | V_318 | V_330 | V_322 | V_348 | V_320 ) )
return - V_250 ;
if ( V_165 && ( V_165 != sizeof( struct V_21 ) ) )
return - V_170 ;
F_58 ( V_3 ) ;
V_180 = F_89 ( V_3 , V_193 & V_318 ) ;
if ( V_2 -> type == V_159 ) {
if ( V_193 & V_330 ) {
V_183 = - V_170 ;
goto V_19;
}
V_193 |= V_330 ;
}
V_183 = F_90 ( V_3 , V_6 , V_165 , & V_180 , V_193 ) ;
if ( V_183 )
goto V_349;
if ( V_3 -> V_264 & V_350 ) {
V_183 = - V_351 ;
if ( ! ( V_193 & V_322 ) )
F_151 ( V_352 , V_187 , 0 ) ;
goto V_349;
}
if ( ( V_193 & V_347 ) && V_3 -> V_50 )
F_152 ( V_3 ) ;
V_335 = V_5 -> V_90 ;
V_333 = V_5 -> V_85 & V_231 ;
V_335 = F_143 ( V_3 , V_193 ) ;
if ( V_193 & V_306 ) {
V_314 = & V_5 -> V_48 ;
if ( V_32 > V_335 ) {
V_183 = - V_353 ;
goto V_19;
}
}
V_5 -> V_111 = V_354 ;
while( V_346 < V_32 ) {
V_183 = F_79 ( V_3 ) ;
if ( V_183 )
goto V_19;
if ( F_81 ( V_187 ) ) {
V_183 = F_80 ( V_180 ) ;
goto V_19;
}
V_29 = V_32 - V_346 ;
if ( V_29 > V_335 )
V_29 = V_335 ;
if ( F_138 ( V_5 , V_314 , V_193 ) ) {
F_72 ( V_182 ) ;
if ( V_193 & V_318 ) {
V_183 = - V_326 ;
goto V_19;
}
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
F_130 ( V_327 , & V_3 -> V_134 -> V_193 ) ;
F_131 ( V_3 , & V_180 ,
! F_138 ( V_5 , V_314 , V_193 ) ) ;
F_132 ( V_327 , & V_3 -> V_134 -> V_193 ) ;
F_82 ( F_77 ( V_3 ) , & V_182 ) ;
continue;
}
V_38 = F_146 ( V_3 , V_29 + 64 + V_91 ,
V_193 & V_318 , & V_183 ) ;
if ( V_183 )
break;
if ( ! V_38 )
continue;
V_40 = F_30 ( V_38 ) ;
F_153 ( V_38 , 64 + V_91 ) ;
if ( F_154 ( F_155 ( V_38 , V_29 ) , V_313 , V_29 ) ) {
V_183 = - V_273 ;
goto V_19;
}
if ( V_193 & V_306 ) {
V_40 -> V_307 = 0x30 ;
if ( V_333 != V_87 )
V_5 -> V_82 -- ;
} else {
V_40 -> V_307 = 0x00 ;
if ( V_5 -> V_355 == 0 )
V_40 -> V_307 |= 0x20 ;
V_5 -> V_355 += V_29 ;
if ( ( ( V_346 + V_29 ) == V_32 ) && ( V_193 & V_330 ) ) {
V_40 -> V_307 |= 0x40 ;
V_5 -> V_355 = 0 ;
if ( V_333 == V_356 )
V_5 -> V_81 -- ;
}
if ( V_333 == V_357 )
V_5 -> V_81 -- ;
}
V_346 += V_29 ;
F_156 ( V_3 , V_38 , V_3 -> V_65 , V_193 & V_306 ) ;
V_38 = NULL ;
V_5 -> V_110 = F_46 ( V_3 ) ;
}
V_19:
F_102 ( V_38 ) ;
F_59 ( V_3 ) ;
return V_346 ? V_346 : V_183 ;
V_349:
V_183 = F_157 ( V_3 , V_193 , V_183 ) ;
F_59 ( V_3 ) ;
return V_183 ;
}
static int F_158 ( struct V_358 * V_359 , unsigned long V_360 ,
void * V_213 )
{
struct V_167 * V_168 = F_159 ( V_213 ) ;
if ( ! F_55 ( F_160 ( V_168 ) , & V_154 ) )
return V_361 ;
switch ( V_360 ) {
case V_362 :
F_161 ( V_168 ) ;
break;
case V_363 :
F_162 ( V_168 ) ;
break;
default:
break;
}
return V_361 ;
}
static struct V_2 * F_163 ( struct V_364 * V_365 )
{
struct V_366 * V_70 = V_365 -> V_367 ;
struct V_2 * V_316 = NULL ;
for( V_70 -> V_368 = 0 ;
V_70 -> V_368 < V_369 ;
++ V_70 -> V_368 ) {
V_316 = F_28 ( & V_10 [ V_70 -> V_368 ] ) ;
if ( V_316 )
break;
}
return V_316 ;
}
static struct V_2 * F_164 ( struct V_364 * V_365 ,
struct V_2 * V_316 )
{
struct V_366 * V_70 = V_365 -> V_367 ;
V_316 = F_165 ( V_316 ) ;
V_370:
if ( V_316 )
goto V_19;
if ( ++ V_70 -> V_368 >= V_369 )
goto V_19;
V_316 = F_28 ( & V_10 [ V_70 -> V_368 ] ) ;
goto V_370;
V_19:
return V_316 ;
}
static struct V_2 * F_166 ( struct V_364 * V_365 , T_8 * V_371 )
{
struct V_2 * V_3 = F_163 ( V_365 ) ;
if ( V_3 ) {
while( * V_371 && ( V_3 = F_164 ( V_365 , V_3 ) ) )
-- * V_371 ;
}
return * V_371 ? NULL : V_3 ;
}
static void * F_167 ( struct V_364 * V_365 , T_8 V_371 )
{
void * V_372 ;
F_168 ( & V_18 ) ;
V_372 = F_166 ( V_365 , & V_371 ) ;
if ( ! V_372 ) {
F_169 ( & V_18 ) ;
}
return V_372 ;
}
static void * F_170 ( struct V_364 * V_365 , T_8 * V_371 )
{
return * V_371 ? F_167 ( V_365 , * V_371 - 1 ) : V_373 ;
}
static void * F_171 ( struct V_364 * V_365 , void * V_374 , T_8 * V_371 )
{
void * V_372 ;
if ( V_374 == V_373 ) {
V_372 = F_167 ( V_365 , 0 ) ;
goto V_19;
}
V_372 = F_164 ( V_365 , V_374 ) ;
if ( V_372 )
goto V_19;
F_169 ( & V_18 ) ;
V_19:
++ * V_371 ;
return V_372 ;
}
static void F_172 ( struct V_364 * V_365 , void * V_374 )
{
if ( V_374 && V_374 != V_373 )
F_169 ( & V_18 ) ;
}
static void F_173 ( struct V_21 * V_375 , unsigned char * V_28 )
{
int V_22 ;
switch ( F_4 ( V_375 -> V_25 ) ) {
case 0 :
sprintf ( V_28 , L_4 , V_375 -> V_24 ) ;
break;
default:
for ( V_22 = 0 ; V_22 < F_4 ( V_375 -> V_25 ) ; V_22 ++ ) {
V_28 [ V_22 ] = V_375 -> V_26 [ V_22 ] ;
if ( F_174 ( V_28 [ V_22 ] ) )
V_28 [ V_22 ] = '.' ;
}
V_28 [ V_22 ] = 0 ;
}
}
static char * F_175 ( unsigned char V_70 )
{
switch ( V_70 ) {
case V_71 :
return L_5 ;
case V_140 :
return L_6 ;
case V_126 :
return L_7 ;
case V_128 :
return L_8 ;
case V_184 :
return L_9 ;
case V_147 :
return L_10 ;
case V_144 :
return L_11 ;
case V_143 :
return L_12 ;
case V_148 :
return L_13 ;
case V_145 :
return L_14 ;
case V_142 :
return L_15 ;
case V_121 :
return L_16 ;
case V_146 :
return L_17 ;
case V_129 :
return L_18 ;
case V_376 :
return L_19 ;
case V_125 :
return L_20 ;
}
return L_21 ;
}
static inline void F_176 ( struct V_364 * V_365 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
char V_377 [ V_378 ] ;
char V_379 [ V_378 ] ;
char V_380 [ V_34 + 3 ] ;
char V_381 [ V_34 + 3 ] ;
F_173 ( & V_5 -> V_6 , V_380 ) ;
F_173 ( & V_5 -> V_42 , V_381 ) ;
F_177 ( V_365 ,
L_22
L_23 ,
F_53 ( F_4 ( F_31 ( & V_5 -> V_6 ) ) , V_377 ) ,
V_5 -> V_11 ,
V_5 -> V_72 ,
V_5 -> V_73 ,
V_5 -> V_74 ,
V_5 -> V_75 ,
V_5 -> V_80 ,
V_380 ,
F_53 ( F_4 ( F_31 ( & V_5 -> V_42 ) ) , V_379 ) ,
V_5 -> V_44 ,
V_5 -> V_382 ,
V_5 -> V_383 ,
V_5 -> V_76 ,
V_5 -> V_77 ,
V_5 -> V_78 ,
V_381 ,
F_175 ( V_5 -> V_70 ) ,
( ( V_5 -> V_94 == V_95 ) ? L_24 : L_25 ) ) ;
}
static int F_178 ( struct V_364 * V_365 , void * V_374 )
{
if ( V_374 == V_373 ) {
F_179 ( V_365 , L_26 ) ;
} else {
F_176 ( V_365 , V_374 ) ;
}
return 0 ;
}
static int F_180 ( struct V_384 * V_384 , struct V_245 * V_245 )
{
return F_181 ( V_245 , & V_385 ,
sizeof( struct V_366 ) ) ;
}
static int T_9 F_182 ( void )
{
int V_372 ;
F_51 ( V_386 ) ;
V_372 = F_183 ( & V_56 , 1 ) ;
if ( V_372 != 0 )
goto V_19;
F_184 () ;
F_185 () ;
F_186 () ;
F_187 () ;
F_188 ( & V_387 ) ;
F_189 ( & V_388 ) ;
F_190 ( & V_389 ) ;
F_191 ( L_27 , V_390 , V_154 . V_391 , & V_392 ) ;
F_192 () ;
V_19:
return V_372 ;
}
