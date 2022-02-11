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
static struct V_2 * F_37 ( struct V_52 * V_52 , struct V_53 * V_2 , T_2 V_54 , int V_55 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 = F_38 ( V_52 , V_56 , V_54 , & V_57 , V_55 ) ;
if ( ! V_3 )
goto V_19;
if ( V_2 )
V_2 -> V_58 = & V_59 ;
F_39 ( V_2 , V_3 ) ;
V_3 -> V_60 = V_61 ;
V_3 -> V_62 = F_32 ;
V_3 -> V_63 = 1 ;
V_3 -> V_64 = V_56 ;
V_3 -> V_65 = 0 ;
V_3 -> V_66 = V_54 ;
V_3 -> V_67 = V_68 [ 1 ] ;
V_3 -> V_69 = V_70 [ 1 ] ;
V_5 = F_2 ( V_3 ) ;
V_5 -> V_71 = V_72 ;
V_5 -> V_73 = 1 ;
V_5 -> V_74 = 1 ;
V_5 -> V_75 = 0 ;
V_5 -> V_76 = 0 ;
V_5 -> V_77 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_79 = V_80 ;
V_5 -> V_81 = V_80 ;
V_5 -> V_82 = 0 ;
V_5 -> V_83 = 1 ;
V_5 -> V_84 = 0 ;
V_5 -> V_85 = 1 ;
V_5 -> V_86 = 0 ;
V_5 -> V_87 = 1 | V_88 ;
V_5 -> V_89 = 0 ;
V_5 -> V_90 = 0x03 ;
V_5 -> V_91 = 230 - V_92 ;
V_5 -> V_93 = 0 ;
V_5 -> V_94 = 1 ;
V_5 -> V_95 = V_96 ;
V_5 -> V_6 . V_97 = V_98 ;
V_5 -> V_42 . V_97 = V_98 ;
V_5 -> V_99 . V_100 = 5 ;
memcpy ( V_5 -> V_99 . V_101 , L_1 , 5 ) ;
V_5 -> V_102 = V_103 ;
V_5 -> V_104 = V_105 ;
V_5 -> V_106 = V_107 ;
V_5 -> V_108 = V_109 ;
V_5 -> V_110 = 0 ;
F_40 ( & V_5 -> V_47 ) ;
F_40 ( & V_5 -> V_48 ) ;
F_40 ( & V_5 -> V_49 ) ;
V_5 -> V_111 = 0 ;
V_5 -> V_112 = NULL ;
V_5 -> V_113 = 10 * V_114 ;
V_5 -> V_115 = V_116 ;
F_41 ( & V_5 -> V_117 ) ;
V_5 -> V_118 = 0 ;
V_5 -> V_119 = V_120 ;
F_42 ( V_3 ) ;
V_19:
return V_3 ;
}
static void V_116 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( F_43 ( & V_5 -> V_48 ) )
F_44 ( V_3 , V_121 , 0 ) ;
}
int F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_5 -> V_111 = F_46 ( V_3 ) ;
switch ( V_5 -> V_71 ) {
case V_122 :
F_47 ( V_3 , V_123 , 0 , V_124 ) ;
if ( V_5 -> V_110 >= V_125 )
V_5 -> V_71 = V_126 ;
return 0 ;
case V_127 :
F_47 ( V_3 , V_123 , 0 , V_124 ) ;
if ( V_5 -> V_110 >= V_128 )
V_5 -> V_71 = V_129 ;
return 0 ;
case V_130 :
if ( V_5 -> V_110 < V_131 ) {
F_47 ( V_3 , V_132 , V_133 ,
V_124 ) ;
return 0 ;
}
}
V_5 -> V_111 = ( V_114 * V_134 ) ;
if ( V_3 -> V_135 )
return 0 ;
if ( F_48 ( V_136 , V_5 -> V_137 + V_114 * V_134 ) ) {
F_15 ( V_3 ) ;
F_49 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_5 -> V_110 = 0 ;
if ( V_3 -> V_135 ) {
if ( V_3 -> V_135 -> V_71 != V_138 )
V_3 -> V_135 -> V_71 = V_139 ;
}
V_3 -> V_35 = V_140 ;
switch ( V_5 -> V_71 ) {
case V_130 :
F_47 ( V_3 , V_132 , V_133 ,
V_3 -> V_66 ) ;
V_5 -> V_112 = F_45 ;
V_5 -> V_111 = F_46 ( V_3 ) ;
break;
case V_141 :
V_5 -> V_71 = V_127 ;
goto V_142;
case V_143 :
V_5 -> V_71 = V_122 ;
case V_122 :
case V_127 :
V_142:
F_47 ( V_3 , V_123 , 0 , V_3 -> V_66 ) ;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_126 :
case V_129 :
case V_148 :
case V_149 :
V_5 -> V_112 = F_45 ;
V_5 -> V_111 = F_46 ( V_3 ) ;
break;
default:
F_51 ( V_150 L_2 ) ;
case V_72 :
F_52 ( V_3 ) ;
F_19 ( V_3 ) ;
F_49 ( V_3 ) ;
break;
}
}
char * F_53 ( T_3 V_6 , char * V_28 )
{
unsigned short V_151 , V_152 ;
V_151 = V_6 & 0x03ff ;
V_152 = V_6 >> 10 ;
sprintf ( V_28 , L_3 , V_152 , V_151 ) ;
return V_28 ;
}
static int F_54 ( struct V_52 * V_52 , struct V_53 * V_2 , int V_153 ,
int V_55 )
{
struct V_2 * V_3 ;
if ( V_153 < 0 || V_153 > V_154 )
return - V_155 ;
if ( ! F_55 ( V_52 , & V_156 ) )
return - V_157 ;
switch ( V_2 -> type ) {
case V_158 :
if ( V_153 != V_159 )
return - V_160 ;
break;
case V_161 :
break;
default:
return - V_162 ;
}
if ( ( V_3 = F_37 ( V_52 , V_2 , V_163 , V_55 ) ) == NULL )
return - V_164 ;
V_3 -> V_65 = V_153 ;
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
static int F_60 ( struct V_53 * V_2 , struct V_165 * V_166 , int V_167 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_21 * V_168 = (struct V_21 * ) V_166 ;
struct V_169 * V_170 , * V_171 ;
int V_16 ;
if ( V_167 != sizeof( struct V_21 ) )
return - V_155 ;
if ( V_168 -> V_97 != V_98 )
return - V_155 ;
if ( F_4 ( V_168 -> V_172 ) && ( F_4 ( V_168 -> V_172 ) != 2 ) )
return - V_155 ;
if ( F_4 ( V_168 -> V_25 ) > V_34 )
return - V_155 ;
if ( V_168 -> V_7 & ~ V_8 )
return - V_155 ;
if ( ! F_61 ( V_173 ) && ( V_168 -> V_24 ||
( V_168 -> V_7 & V_8 ) ) )
return - V_174 ;
if ( ! ( V_168 -> V_7 & V_8 ) ) {
if ( F_4 ( V_168 -> V_172 ) ) {
F_62 () ;
V_171 = NULL ;
F_63 (&init_net, dev) {
if ( ! V_170 -> V_175 )
continue;
if ( F_64 ( V_170 , F_31 ( V_168 ) ) ) {
V_171 = V_170 ;
break;
}
}
F_65 () ;
if ( V_171 == NULL )
return - V_176 ;
}
}
V_16 = - V_155 ;
F_58 ( V_3 ) ;
if ( F_66 ( V_3 , V_177 ) ) {
memcpy ( & V_5 -> V_6 , V_168 , V_167 ) ;
F_67 ( V_3 , V_177 ) ;
V_16 = F_9 ( V_3 ) ;
if ( V_16 )
F_68 ( V_3 , V_177 ) ;
}
F_59 ( V_3 ) ;
return V_16 ;
}
static int F_69 ( struct V_53 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_16 ;
F_67 ( V_3 , V_177 ) ;
V_5 -> V_6 . V_7 = 0 ;
V_5 -> V_6 . V_24 = 0 ;
if ( ( V_5 -> V_99 . V_100 != 0 ) &&
( V_5 -> V_99 . V_100 <= 12 ) ) {
V_5 -> V_6 . V_25 = F_8 ( V_5 -> V_99 . V_100 ) ;
memcpy ( V_5 -> V_6 . V_26 , V_5 -> V_99 . V_101 , F_4 ( V_5 -> V_6 . V_25 ) ) ;
V_5 -> V_99 . V_100 = 0 ;
memset ( V_5 -> V_99 . V_101 , 0 , 40 ) ;
}
V_5 -> V_6 . V_178 . V_179 = F_8 ( 2 ) ;
V_16 = F_70 ( ( T_1 * ) V_5 -> V_6 . V_178 . V_180 ) ;
if ( V_16 == 0 ) {
V_16 = F_9 ( V_3 ) ;
if ( V_16 )
F_68 ( V_3 , V_177 ) ;
}
return V_16 ;
}
static int F_71 ( struct V_2 * V_3 , long * V_181 , T_2 V_182 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_72 ( V_183 ) ;
int V_184 ;
if ( V_5 -> V_71 != V_141 )
return - V_155 ;
V_5 -> V_71 = V_185 ;
V_5 -> V_186 = F_73 ( F_74 ( V_3 ) ) ;
F_75 ( V_3 , V_182 ) ;
F_76 ( F_77 ( V_3 ) , & V_183 , V_187 ) ;
for(; ; ) {
F_59 ( V_3 ) ;
if ( V_5 -> V_71 == V_185 )
* V_181 = F_78 ( * V_181 ) ;
F_58 ( V_3 ) ;
V_184 = 0 ;
if ( V_5 -> V_71 == V_143 )
break;
V_184 = F_79 ( V_3 ) ;
if ( V_184 )
break;
V_184 = F_80 ( * V_181 ) ;
if ( F_81 ( V_188 ) )
break;
V_184 = - V_189 ;
if ( ! * V_181 )
break;
F_76 ( F_77 ( V_3 ) , & V_183 , V_187 ) ;
}
F_82 ( F_77 ( V_3 ) , & V_183 ) ;
if ( V_184 == 0 ) {
V_3 -> V_135 -> V_71 = V_190 ;
} else if ( V_5 -> V_71 != V_185 ) {
V_3 -> V_135 -> V_71 = V_138 ;
}
return V_184 ;
}
static int F_83 ( struct V_2 * V_3 , long * V_181 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_72 ( V_183 ) ;
int V_184 = 0 ;
if ( V_5 -> V_71 == V_143 )
goto V_19;
if ( ! * V_181 )
return - V_191 ;
F_76 ( F_77 ( V_3 ) , & V_183 , V_187 ) ;
for(; ; ) {
F_59 ( V_3 ) ;
if ( V_5 -> V_71 == V_148 || V_5 -> V_71 == V_185 )
* V_181 = F_78 ( * V_181 ) ;
F_58 ( V_3 ) ;
V_184 = 0 ;
if ( V_5 -> V_71 == V_143 )
break;
V_184 = F_79 ( V_3 ) ;
if ( V_184 )
break;
V_184 = F_80 ( * V_181 ) ;
if ( F_81 ( V_188 ) )
break;
V_184 = - V_192 ;
if ( ! * V_181 )
break;
F_76 ( F_77 ( V_3 ) , & V_183 , V_187 ) ;
}
F_82 ( F_77 ( V_3 ) , & V_183 ) ;
V_19:
if ( V_184 == 0 ) {
V_3 -> V_135 -> V_71 = V_190 ;
} else if ( V_5 -> V_71 != V_148 && V_5 -> V_71 != V_185 ) {
V_3 -> V_135 -> V_71 = V_138 ;
}
return V_184 ;
}
static int F_84 ( struct V_2 * V_3 , struct V_21 * V_6 , int V_193 , long * V_181 , int V_194 )
{
struct V_53 * V_2 = V_3 -> V_135 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_184 = - V_195 ;
struct V_196 V_197 ;
struct V_198 * V_199 ;
if ( V_2 -> V_71 == V_190 )
goto V_19;
if ( V_2 -> V_71 == V_200 ) {
V_184 = 0 ;
if ( V_5 -> V_71 == V_143 ) {
V_2 -> V_71 = V_190 ;
goto V_19;
}
V_184 = - V_201 ;
if ( V_5 -> V_71 != V_148 && V_5 -> V_71 != V_185 ) {
V_2 -> V_71 = V_138 ;
goto V_19;
}
return F_83 ( V_3 , V_181 ) ;
}
V_184 = - V_155 ;
if ( V_5 -> V_71 != V_72 )
goto V_19;
if ( V_6 == NULL || V_193 != sizeof( struct V_21 ) )
goto V_19;
if ( V_6 -> V_97 != V_98 )
goto V_19;
if ( V_6 -> V_7 & V_8 )
goto V_19;
if ( F_66 ( V_3 , V_177 ) ) {
V_184 = F_69 ( V_3 -> V_135 ) ;
if ( V_184 )
goto V_19;
}
memcpy ( & V_5 -> V_42 , V_6 , sizeof( struct V_21 ) ) ;
V_184 = - V_202 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_203 = V_3 -> V_204 ;
V_197 . V_205 = F_31 ( & V_5 -> V_42 ) ;
V_197 . V_168 = F_31 ( & V_5 -> V_6 ) ;
F_85 ( & V_197 , V_5 ) ;
V_197 . V_206 = V_159 ;
if ( F_86 ( & V_3 -> V_50 , & V_197 , V_3 , V_194 ) < 0 )
goto V_19;
V_199 = F_74 ( V_3 ) ;
V_3 -> V_207 = V_199 -> V_170 -> V_208 ;
V_2 -> V_71 = V_200 ;
V_5 -> V_71 = V_148 ;
V_5 -> V_186 = F_73 ( V_199 ) ;
F_87 ( V_3 , V_209 ) ;
V_184 = - V_210 ;
if ( * V_181 ) {
V_184 = F_83 ( V_3 , V_181 ) ;
}
V_19:
return V_184 ;
}
static int F_88 ( struct V_53 * V_2 , struct V_165 * V_166 , int V_193 , int V_194 )
{
struct V_21 * V_6 = (struct V_21 * ) V_166 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_184 ;
long V_181 = F_89 ( V_3 , V_194 & V_211 ) ;
F_58 ( V_3 ) ;
V_184 = F_84 ( V_3 , V_6 , V_193 , & V_181 , 0 ) ;
F_59 ( V_3 ) ;
return V_184 ;
}
static inline int F_90 ( struct V_2 * V_3 , struct V_21 * V_6 , int V_193 , long * V_181 , int V_194 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
switch ( V_5 -> V_71 ) {
case V_143 :
return 0 ;
case V_141 :
return F_71 ( V_3 , V_181 , V_3 -> V_66 ) ;
case V_148 :
case V_185 :
return F_83 ( V_3 , V_181 ) ;
case V_72 :
return F_84 ( V_3 , V_6 , V_193 , V_181 , V_194 ) ;
}
return - V_155 ;
}
static void F_91 ( struct V_37 * V_38 , struct V_212 * V_213 )
{
unsigned char * V_214 = V_38 -> V_30 ;
V_213 -> V_215 = * V_214 ++ ;
memcpy ( & V_213 -> V_216 , V_214 , V_213 -> V_215 ) ;
V_214 += V_213 -> V_215 ;
V_213 -> V_217 = * V_214 ++ ;
memcpy ( & V_213 -> V_218 , V_214 , V_213 -> V_217 ) ;
V_214 += V_213 -> V_217 ;
V_213 -> V_100 = * V_214 ++ ;
memcpy ( & V_213 -> V_101 , V_214 , V_213 -> V_100 ) ;
F_92 ( V_38 , V_213 -> V_100 + V_213 -> V_217 + V_213 -> V_215 + 3 ) ;
}
static void F_93 ( struct V_37 * V_38 , struct V_219 * V_220 )
{
unsigned char * V_214 = V_38 -> V_30 ;
T_4 V_29 = * V_214 ++ ;
F_10 ( V_29 > 16 ) ;
V_220 -> V_221 = F_8 ( V_29 ) ;
V_220 -> V_222 = 0 ;
memcpy ( V_220 -> V_223 , V_214 , V_29 ) ;
F_92 ( V_38 , V_29 + 1 ) ;
}
static struct V_37 * F_94 ( struct V_2 * V_3 , long * V_181 )
{
F_72 ( V_183 ) ;
struct V_37 * V_38 = NULL ;
int V_184 = 0 ;
F_76 ( F_77 ( V_3 ) , & V_183 , V_187 ) ;
for(; ; ) {
F_59 ( V_3 ) ;
V_38 = F_95 ( & V_3 -> V_224 ) ;
if ( V_38 == NULL ) {
* V_181 = F_78 ( * V_181 ) ;
V_38 = F_95 ( & V_3 -> V_224 ) ;
}
F_58 ( V_3 ) ;
if ( V_38 != NULL )
break;
V_184 = - V_155 ;
if ( V_3 -> V_35 != V_36 )
break;
V_184 = F_80 ( * V_181 ) ;
if ( F_81 ( V_188 ) )
break;
V_184 = - V_189 ;
if ( ! * V_181 )
break;
F_76 ( F_77 ( V_3 ) , & V_183 , V_187 ) ;
}
F_82 ( F_77 ( V_3 ) , & V_183 ) ;
return V_38 == NULL ? F_96 ( V_184 ) : V_38 ;
}
static int F_97 ( struct V_53 * V_2 , struct V_53 * V_225 , int V_194 )
{
struct V_2 * V_3 = V_2 -> V_3 , * V_226 ;
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
unsigned char V_227 ;
int V_184 = 0 ;
unsigned char type ;
long V_181 = F_98 ( V_3 , V_194 & V_211 ) ;
struct V_198 * V_199 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_35 != V_36 || F_2 ( V_3 ) -> V_71 != V_72 ) {
F_59 ( V_3 ) ;
return - V_155 ;
}
V_38 = F_95 ( & V_3 -> V_224 ) ;
if ( V_38 == NULL ) {
V_38 = F_94 ( V_3 , & V_181 ) ;
if ( F_99 ( V_38 ) ) {
F_59 ( V_3 ) ;
return F_100 ( V_38 ) ;
}
}
V_40 = F_30 ( V_38 ) ;
V_3 -> V_228 -- ;
V_226 = F_37 ( F_101 ( V_3 ) , V_225 , V_3 -> V_66 , 0 ) ;
if ( V_226 == NULL ) {
F_59 ( V_3 ) ;
F_102 ( V_38 ) ;
return - V_164 ;
}
F_59 ( V_3 ) ;
V_199 = F_103 ( V_38 ) ;
F_104 ( V_226 , V_199 ) ;
F_105 ( V_38 , NULL ) ;
F_2 ( V_226 ) -> V_71 = V_141 ;
F_2 ( V_226 ) -> V_44 = V_40 -> V_45 ;
F_2 ( V_226 ) -> V_86 = V_40 -> V_229 ;
F_2 ( V_226 ) -> V_89 = V_40 -> V_230 ;
F_2 ( V_226 ) -> V_91 = V_40 -> V_231 ;
F_2 ( V_226 ) -> V_95 = F_2 ( V_3 ) -> V_95 ;
if ( F_2 ( V_226 ) -> V_91 < 230 )
F_2 ( V_226 ) -> V_91 = 230 ;
if ( ( F_2 ( V_226 ) -> V_86 & V_232 ) == V_88 )
F_2 ( V_226 ) -> V_102 = V_233 ;
V_226 -> V_35 = V_36 ;
memcpy ( & ( F_2 ( V_226 ) -> V_6 ) , & ( F_2 ( V_3 ) -> V_6 ) , sizeof( struct V_21 ) ) ;
F_2 ( V_226 ) -> V_6 . V_7 &= ~ V_8 ;
F_92 ( V_38 , F_23 ( V_38 -> V_30 , V_38 -> V_29 , & ( F_2 ( V_226 ) -> V_6 ) , & type ) ) ;
F_92 ( V_38 , F_23 ( V_38 -> V_30 , V_38 -> V_29 , & ( F_2 ( V_226 ) -> V_42 ) , & type ) ) ;
* ( T_1 * ) ( F_2 ( V_226 ) -> V_42 . V_178 . V_180 ) = V_40 -> V_41 ;
* ( T_1 * ) ( F_2 ( V_226 ) -> V_6 . V_178 . V_180 ) = V_40 -> V_199 ;
V_227 = * V_38 -> V_30 ;
F_92 ( V_38 , 1 ) ;
if ( V_227 & V_234 )
F_91 ( V_38 , & ( F_2 ( V_226 ) -> V_99 ) ) ;
if ( V_227 & V_235 )
F_93 ( V_38 , & ( F_2 ( V_226 ) -> V_236 ) ) ;
if ( V_227 & V_237 )
F_2 ( V_226 ) -> V_42 . V_7 |= V_238 ;
if ( V_227 & V_239 )
F_2 ( V_226 ) -> V_42 . V_7 |= V_240 ;
F_102 ( V_38 ) ;
memcpy ( & ( F_2 ( V_226 ) -> V_241 ) , & ( F_2 ( V_3 ) -> V_241 ) ,
sizeof( struct V_219 ) ) ;
memcpy ( & ( F_2 ( V_226 ) -> V_242 ) , & ( F_2 ( V_3 ) -> V_242 ) ,
sizeof( struct V_219 ) ) ;
F_58 ( V_226 ) ;
V_184 = F_9 ( V_226 ) ;
if ( V_184 == 0 ) {
F_67 ( V_226 , V_177 ) ;
F_106 ( V_226 ) ;
if ( F_2 ( V_226 ) -> V_95 == V_96 )
V_184 = F_71 ( V_226 , & V_181 ,
V_3 -> V_66 ) ;
}
F_59 ( V_226 ) ;
return V_184 ;
}
static int F_107 ( struct V_53 * V_2 , struct V_165 * V_166 , int * V_243 , int V_42 )
{
struct V_21 * V_244 = (struct V_21 * ) V_166 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
* V_243 = sizeof( struct V_21 ) ;
F_58 ( V_3 ) ;
if ( V_42 ) {
if ( ( V_2 -> V_71 != V_190 &&
V_2 -> V_71 != V_200 ) &&
V_5 -> V_95 == V_96 ) {
F_59 ( V_3 ) ;
return - V_245 ;
}
memcpy ( V_244 , & V_5 -> V_42 , sizeof( struct V_21 ) ) ;
} else {
memcpy ( V_244 , & V_5 -> V_6 , sizeof( struct V_21 ) ) ;
}
F_59 ( V_3 ) ;
return 0 ;
}
static unsigned int F_108 ( struct V_246 * V_246 , struct V_53 * V_2 , T_5 * V_183 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_247 = F_109 ( V_246 , V_2 , V_183 ) ;
if ( ! F_43 ( & V_5 -> V_49 ) )
V_247 |= V_248 ;
return V_247 ;
}
static int F_110 ( struct V_53 * V_2 , unsigned int V_249 , unsigned long V_250 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_184 = - V_251 ;
long V_252 = 0 ;
struct V_37 * V_38 ;
int V_253 ;
switch( V_249 )
{
case V_254 :
case V_255 :
return F_111 ( V_249 , ( void V_256 * ) V_250 ) ;
case V_257 :
F_58 ( V_3 ) ;
V_253 = ! F_43 ( & V_5 -> V_49 ) ;
if ( V_5 -> V_71 != V_143 )
V_253 = - V_245 ;
F_59 ( V_3 ) ;
return V_253 ;
case V_258 :
V_252 = V_3 -> V_67 - F_112 ( V_3 ) ;
if ( V_252 < 0 )
V_252 = 0 ;
V_184 = F_113 ( V_252 , ( int V_256 * ) V_250 ) ;
break;
case V_259 :
F_58 ( V_3 ) ;
V_38 = F_114 ( & V_5 -> V_49 ) ;
if ( V_38 ) {
V_252 = V_38 -> V_29 ;
} else {
F_115 (&sk->sk_receive_queue, skb)
V_252 += V_38 -> V_29 ;
}
F_59 ( V_3 ) ;
V_184 = F_113 ( V_252 , ( int V_256 * ) V_250 ) ;
break;
default:
V_184 = - V_260 ;
break;
}
return V_184 ;
}
static int F_116 ( struct V_53 * V_2 , int V_261 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_184 = - V_155 ;
F_58 ( V_3 ) ;
if ( F_66 ( V_3 , V_177 ) )
goto V_19;
if ( ( F_2 ( V_3 ) -> V_71 != V_72 ) || ( V_3 -> V_35 == V_36 ) )
goto V_19;
V_3 -> V_262 = V_261 ;
V_3 -> V_228 = 0 ;
V_3 -> V_35 = V_36 ;
V_184 = 0 ;
F_21 ( V_3 ) ;
V_19:
F_59 ( V_3 ) ;
return V_184 ;
}
static int F_117 ( struct V_53 * V_2 , int V_263 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_184 = - V_245 ;
F_58 ( V_3 ) ;
if ( V_2 -> V_71 == V_138 )
goto V_19;
V_184 = 0 ;
if ( V_2 -> V_71 == V_139 )
goto V_19;
V_184 = - V_155 ;
if ( V_5 -> V_71 == V_72 )
goto V_19;
if ( V_263 != V_264 )
goto V_19;
V_3 -> V_265 = V_266 ;
F_50 ( V_3 ) ;
V_184 = 0 ;
V_19:
F_59 ( V_3 ) ;
return V_184 ;
}
static int F_118 ( struct V_53 * V_2 , int V_267 , int V_268 , char V_256 * V_269 , unsigned int V_270 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_184 ;
F_58 ( V_3 ) ;
V_184 = F_119 ( V_2 , V_267 , V_268 , V_269 , V_270 , 0 ) ;
F_59 ( V_3 ) ;
return V_184 ;
}
static int F_119 ( struct V_53 * V_2 , int V_267 , int V_268 , char V_256 * V_269 , unsigned int V_270 , int V_194 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
long V_181 ;
union {
struct V_219 V_220 ;
struct V_212 V_213 ;
int V_271 ;
unsigned long V_272 ;
int V_253 ;
unsigned char V_229 ;
unsigned char V_230 ;
} V_273 ;
int V_184 ;
if ( V_270 && ! V_269 )
return - V_155 ;
if ( V_270 > sizeof( V_273 ) )
return - V_155 ;
if ( F_120 ( & V_273 , V_269 , V_270 ) )
return - V_274 ;
switch ( V_268 ) {
case V_275 :
if ( V_2 -> V_71 == V_190 )
return - V_195 ;
if ( ( V_5 -> V_71 != V_72 ) && ( V_5 -> V_71 != V_141 ) )
return - V_155 ;
if ( V_270 != sizeof( struct V_219 ) )
return - V_155 ;
if ( F_4 ( V_273 . V_220 . V_221 ) > 16 )
return - V_155 ;
memcpy ( & V_5 -> V_241 , & V_273 . V_220 , V_270 ) ;
break;
case V_276 :
if ( V_2 -> V_71 != V_190 &&
V_5 -> V_95 == V_96 )
return - V_245 ;
if ( V_270 != sizeof( struct V_219 ) )
return - V_155 ;
if ( F_4 ( V_273 . V_220 . V_221 ) > 16 )
return - V_155 ;
memcpy ( & V_5 -> V_242 , & V_273 . V_220 , V_270 ) ;
break;
case V_277 :
if ( V_2 -> V_71 == V_190 )
return - V_195 ;
if ( V_5 -> V_71 != V_72 )
return - V_155 ;
if ( V_270 != sizeof( struct V_212 ) )
return - V_155 ;
if ( ( V_273 . V_213 . V_100 > V_278 ) ||
( V_273 . V_213 . V_217 > V_278 ) ||
( V_273 . V_213 . V_215 > V_278 ) )
return - V_155 ;
memcpy ( & V_5 -> V_99 , & V_273 . V_213 , V_270 ) ;
break;
case V_279 :
if ( V_2 -> V_71 == V_190 )
return - V_195 ;
if ( V_5 -> V_71 != V_72 )
return - V_155 ;
if ( V_270 != sizeof( int ) )
return - V_155 ;
if ( ( V_273 . V_271 != V_96 ) && ( V_273 . V_271 != V_280 ) )
return - V_155 ;
V_5 -> V_95 = ( unsigned char ) V_273 . V_271 ;
break;
case V_281 :
if ( V_5 -> V_71 != V_141 )
return - V_155 ;
V_181 = F_98 ( V_3 , 0 ) ;
V_184 = F_71 ( V_3 , & V_181 , V_3 -> V_66 ) ;
return V_184 ;
case V_282 :
if ( V_5 -> V_71 != V_141 )
return - V_155 ;
V_5 -> V_71 = V_127 ;
V_3 -> V_265 = V_266 ;
F_47 ( V_3 , 0x38 , 0 , V_3 -> V_66 ) ;
break;
default:
#ifdef F_121
return F_122 ( V_3 , V_56 , V_268 , V_269 , V_270 ) ;
#endif
case V_283 :
case V_284 :
case V_285 :
return - V_286 ;
case V_287 :
if ( V_270 != sizeof( unsigned long ) )
return - V_155 ;
if ( V_273 . V_272 > V_103 )
V_273 . V_272 = V_103 ;
if ( V_273 . V_272 == 0 )
return - V_155 ;
V_5 -> V_102 = V_273 . V_272 ;
if ( V_5 -> V_104 > V_273 . V_272 )
V_5 -> V_104 = V_273 . V_272 ;
break;
case V_288 :
if ( V_270 != sizeof( int ) )
return - V_155 ;
if ( V_5 -> V_93 == 2 )
return - V_155 ;
V_5 -> V_93 = ( V_273 . V_253 == 0 ) ? 0 : 1 ;
break;
case V_289 :
if ( V_270 != sizeof( int ) )
return - V_155 ;
if ( V_5 -> V_93 == 1 )
return - V_155 ;
V_5 -> V_93 = ( V_273 . V_253 == 0 ) ? 0 : 2 ;
break;
case V_290 :
if ( V_270 != sizeof( unsigned char ) )
return - V_155 ;
if ( ( V_273 . V_229 & ~ V_232 ) != 0x01 )
return - V_155 ;
if ( ( V_273 . V_229 & V_232 ) == V_232 )
return - V_155 ;
V_5 -> V_87 = V_273 . V_229 ;
break;
case V_291 :
if ( V_270 != sizeof( unsigned char ) )
return - V_155 ;
if ( V_273 . V_230 & 0xfc )
return - V_155 ;
V_5 -> V_90 = V_273 . V_230 ;
break;
}
return 0 ;
}
static int F_123 ( struct V_53 * V_2 , int V_267 , int V_268 , char V_256 * V_269 , int V_256 * V_270 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_184 ;
F_58 ( V_3 ) ;
V_184 = F_124 ( V_2 , V_267 , V_268 , V_269 , V_270 , 0 ) ;
F_59 ( V_3 ) ;
return V_184 ;
}
static int F_124 ( struct V_53 * V_2 , int V_267 , int V_268 , char V_256 * V_269 , int V_256 * V_270 , int V_194 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_292 V_293 ;
unsigned int V_294 ;
void * V_295 = NULL ;
unsigned int V_253 ;
if( F_125 ( V_294 , V_270 ) )
return - V_274 ;
switch ( V_268 ) {
case V_275 :
if ( V_294 > sizeof( struct V_219 ) )
V_294 = sizeof( struct V_219 ) ;
V_295 = & V_5 -> V_236 ;
break;
case V_276 :
if ( V_294 > sizeof( struct V_219 ) )
V_294 = sizeof( struct V_219 ) ;
V_295 = & V_5 -> V_296 ;
break;
case V_277 :
if ( V_294 > sizeof( struct V_212 ) )
V_294 = sizeof( struct V_212 ) ;
V_295 = & V_5 -> V_99 ;
break;
case V_279 :
if ( V_294 > sizeof( unsigned char ) )
V_294 = sizeof( unsigned char ) ;
V_295 = & V_5 -> V_95 ;
break;
case V_283 :
if ( V_294 > sizeof( struct V_292 ) )
V_294 = sizeof( struct V_292 ) ;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
switch ( V_2 -> V_71 ) {
case V_200 :
V_293 . V_297 = V_298 ;
break;
case V_139 :
V_293 . V_297 = V_299 ;
break;
case V_190 :
V_293 . V_297 = V_300 ;
break;
default:
V_293 . V_297 = V_301 ;
}
V_293 . V_302 = V_5 -> V_91 ;
V_295 = & V_293 ;
break;
default:
#ifdef F_121
{
int V_303 , V_29 ;
if ( F_125 ( V_29 , V_270 ) )
return - V_274 ;
V_303 = F_126 ( V_3 , V_56 , V_268 , V_269 , & V_29 ) ;
if ( V_303 >= 0 )
V_303 = F_113 ( V_29 , V_270 ) ;
return V_303 ;
}
#endif
case V_284 :
case V_285 :
case V_281 :
case V_282 :
return - V_286 ;
case V_287 :
if ( V_294 > sizeof( unsigned long ) )
V_294 = sizeof( unsigned long ) ;
V_295 = & V_5 -> V_102 ;
break;
case V_288 :
if ( V_294 > sizeof( int ) )
V_294 = sizeof( int ) ;
V_253 = ( V_5 -> V_93 == 1 ) ;
V_295 = & V_253 ;
break;
case V_289 :
if ( V_294 > sizeof( int ) )
V_294 = sizeof( int ) ;
V_253 = ( V_5 -> V_93 == 2 ) ;
V_295 = & V_253 ;
break;
case V_290 :
if ( V_294 > sizeof( unsigned char ) )
V_294 = sizeof( unsigned char ) ;
V_295 = & V_5 -> V_86 ;
break;
case V_291 :
if ( V_294 > sizeof( unsigned char ) )
V_294 = sizeof( unsigned char ) ;
V_295 = & V_5 -> V_89 ;
break;
}
if ( V_295 ) {
if ( F_127 ( V_269 , V_295 , V_294 ) )
return - V_274 ;
if ( F_113 ( V_294 , V_270 ) )
return - V_274 ;
}
return 0 ;
}
static int F_128 ( struct V_2 * V_3 , struct V_304 * V_305 , int V_194 , int V_306 )
{
struct V_37 * V_38 ;
int V_29 = 0 ;
if ( V_194 & V_307 )
return ! F_43 ( V_305 ) ? 1 : 0 ;
F_115 (q, skb) {
struct V_39 * V_40 = F_30 ( V_38 ) ;
V_29 += V_38 -> V_29 ;
if ( V_40 -> V_308 & 0x40 ) {
if ( V_3 -> V_309 == V_158 )
return 1 ;
if ( ! ( V_194 & V_310 ) )
return 1 ;
}
if ( V_29 >= V_306 )
return 1 ;
}
return 0 ;
}
static int F_129 ( struct V_53 * V_2 , struct V_311 * V_312 , T_6 V_32 ,
int V_194 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_304 * V_313 = & V_3 -> V_224 ;
T_6 V_306 = V_32 > 1 ? 1 : 0 ;
T_6 V_314 = 0 ;
int V_16 = 0 ;
struct V_37 * V_38 , * V_315 ;
struct V_39 * V_40 = NULL ;
unsigned char V_316 = 0 ;
long V_181 = F_98 ( V_3 , V_194 & V_317 ) ;
F_58 ( V_3 ) ;
if ( F_66 ( V_3 , V_177 ) ) {
V_16 = - V_176 ;
goto V_19;
}
if ( V_3 -> V_265 & V_318 ) {
V_16 = 0 ;
goto V_19;
}
V_16 = F_90 ( V_3 , NULL , 0 , & V_181 , V_194 ) ;
if ( V_16 )
goto V_19;
if ( V_194 & ~ ( V_319 | V_320 | V_307 | V_310 | V_317 | V_321 ) ) {
V_16 = - V_251 ;
goto V_19;
}
if ( V_194 & V_307 )
V_313 = & V_5 -> V_49 ;
if ( V_194 & V_310 )
V_306 = V_32 ;
for(; ; ) {
F_130 ( V_183 , V_322 ) ;
if ( V_3 -> V_323 )
goto V_19;
if ( ! F_43 ( & V_5 -> V_49 ) ) {
if ( ! ( V_194 & V_307 ) ) {
V_312 -> V_324 |= V_307 ;
if ( ! V_5 -> V_325 ) {
V_5 -> V_325 = 1 ;
goto V_19;
}
}
}
if ( V_5 -> V_71 != V_143 )
goto V_19;
if ( F_81 ( V_188 ) ) {
V_16 = F_80 ( V_181 ) ;
goto V_19;
}
if ( F_128 ( V_3 , V_313 , V_194 , V_306 ) )
break;
if ( V_194 & V_317 ) {
V_16 = - V_326 ;
goto V_19;
}
F_131 ( F_77 ( V_3 ) , & V_183 ) ;
F_132 ( V_327 , V_3 ) ;
F_133 ( V_3 , & V_181 , F_128 ( V_3 , V_313 , V_194 , V_306 ) , & V_183 ) ;
F_134 ( V_327 , V_3 ) ;
F_135 ( F_77 ( V_3 ) , & V_183 ) ;
}
F_136 (queue, skb, n) {
unsigned int V_328 = V_38 -> V_29 ;
V_40 = F_30 ( V_38 ) ;
if ( ( V_328 + V_314 ) > V_32 )
V_328 = V_32 - V_314 ;
if ( F_137 ( V_312 , V_38 -> V_30 , V_328 ) ) {
V_16 = - V_274 ;
break;
}
V_314 += V_328 ;
if ( ! ( V_194 & V_320 ) )
F_92 ( V_38 , V_328 ) ;
V_316 = V_40 -> V_308 & 0x40 ;
if ( V_38 -> V_29 == 0 ) {
F_138 ( V_38 , V_313 ) ;
F_102 ( V_38 ) ;
if ( ( V_5 -> V_81 == V_329 ) && ! F_139 ( V_3 ) ) {
V_5 -> V_81 = V_80 ;
F_44 ( V_3 , V_80 , 0 ) ;
}
}
if ( V_316 ) {
if ( V_3 -> V_309 == V_158 )
break;
if ( ! ( V_194 & V_310 ) )
break;
}
if ( V_194 & V_307 )
break;
if ( V_314 >= V_306 )
break;
}
V_16 = V_314 ;
if ( V_316 && ( V_3 -> V_309 == V_158 ) )
V_312 -> V_324 |= V_330 ;
V_19:
if ( V_16 == 0 )
V_16 = ( V_194 & V_320 ) ? - V_3 -> V_323 : F_79 ( V_3 ) ;
if ( ( V_16 >= 0 ) && V_312 -> V_331 ) {
F_140 ( sizeof( struct V_21 ) ) ;
memcpy ( V_312 -> V_331 , & V_5 -> V_42 , sizeof( struct V_21 ) ) ;
V_312 -> V_332 = sizeof( struct V_21 ) ;
}
F_59 ( V_3 ) ;
return V_16 ;
}
static inline int F_141 ( struct V_4 * V_5 , struct V_304 * V_313 , int V_194 )
{
unsigned char V_333 = V_5 -> V_86 & V_232 ;
if ( F_142 ( V_313 ) >= V_5 -> V_104 )
return 1 ;
if ( V_333 != V_88 ) {
if ( V_194 & V_307 ) {
if ( V_5 -> V_83 == 0 )
return 1 ;
} else {
if ( V_5 -> V_82 == 0 )
return 1 ;
}
}
return 0 ;
}
unsigned int F_143 ( struct V_169 * V_170 , int V_334 )
{
unsigned int V_335 = 230 - V_92 ;
if ( V_170 ) {
struct V_336 * V_337 = F_144 ( V_170 -> V_175 ) ;
V_334 -= F_145 ( V_170 ) ;
if ( V_337 -> V_338 )
V_334 -= 21 ;
else
V_334 -= 6 ;
V_334 -= V_92 ;
} else {
V_334 -= ( 21 + V_92 + 16 ) ;
}
if ( V_334 > V_335 )
V_335 = V_334 ;
return V_335 ;
}
static inline unsigned int F_146 ( struct V_2 * V_3 , int V_194 )
{
struct V_198 * V_199 = F_74 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_339 = F_147 ( int , V_5 -> V_186 , V_5 -> V_91 ) ;
if ( V_194 & V_307 )
return 16 ;
if ( V_199 ) {
T_7 V_334 = F_148 ( V_199 ) ;
V_339 = F_147 ( int , F_143 ( V_199 -> V_170 , V_334 ) , V_339 ) ;
}
return V_339 ;
}
static inline struct V_37 * F_149 ( struct V_2 * V_3 ,
unsigned long V_340 , int V_341 ,
int * V_342 )
{
struct V_37 * V_38 = F_150 ( V_3 , V_340 ,
V_341 , V_342 ) ;
if ( V_38 ) {
V_38 -> V_153 = F_151 ( V_343 ) ;
V_38 -> V_344 = V_345 ;
}
return V_38 ;
}
static int F_152 ( struct V_53 * V_2 , struct V_311 * V_312 , T_6 V_32 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_6 V_335 ;
struct V_304 * V_313 = & V_5 -> V_47 ;
int V_194 = V_312 -> V_324 ;
int V_184 = 0 ;
T_6 V_346 = 0 ;
int V_167 = V_312 -> V_332 ;
F_153 ( struct V_21 * , V_6 , V_312 -> V_331 ) ;
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
T_6 V_29 ;
unsigned char V_333 ;
long V_181 ;
if ( V_194 & ~ ( V_347 | V_307 | V_317 | V_330 | V_321 | V_348 | V_319 ) )
return - V_251 ;
if ( V_167 && ( V_167 != sizeof( struct V_21 ) ) )
return - V_155 ;
F_58 ( V_3 ) ;
V_181 = F_89 ( V_3 , V_194 & V_317 ) ;
if ( V_2 -> type == V_161 ) {
if ( V_194 & V_330 ) {
V_184 = - V_155 ;
goto V_19;
}
V_194 |= V_330 ;
}
V_184 = F_90 ( V_3 , V_6 , V_167 , & V_181 , V_194 ) ;
if ( V_184 )
goto V_349;
if ( V_3 -> V_265 & V_350 ) {
V_184 = - V_351 ;
if ( ! ( V_194 & V_321 ) )
F_154 ( V_352 , V_188 , 0 ) ;
goto V_349;
}
if ( ( V_194 & V_347 ) && V_3 -> V_50 )
F_155 ( V_3 ) ;
V_335 = V_5 -> V_91 ;
V_333 = V_5 -> V_86 & V_232 ;
V_335 = F_146 ( V_3 , V_194 ) ;
if ( V_194 & V_307 ) {
V_313 = & V_5 -> V_48 ;
if ( V_32 > V_335 ) {
V_184 = - V_353 ;
goto V_19;
}
}
V_5 -> V_112 = V_354 ;
while( V_346 < V_32 ) {
V_184 = F_79 ( V_3 ) ;
if ( V_184 )
goto V_19;
if ( F_81 ( V_188 ) ) {
V_184 = F_80 ( V_181 ) ;
goto V_19;
}
V_29 = V_32 - V_346 ;
if ( V_29 > V_335 )
V_29 = V_335 ;
if ( F_141 ( V_5 , V_313 , V_194 ) ) {
F_130 ( V_183 , V_322 ) ;
if ( V_194 & V_317 ) {
V_184 = - V_326 ;
goto V_19;
}
F_131 ( F_77 ( V_3 ) , & V_183 ) ;
F_132 ( V_327 , V_3 ) ;
F_133 ( V_3 , & V_181 ,
! F_141 ( V_5 , V_313 , V_194 ) , & V_183 ) ;
F_134 ( V_327 , V_3 ) ;
F_135 ( F_77 ( V_3 ) , & V_183 ) ;
continue;
}
V_38 = F_149 ( V_3 , V_29 + 64 + V_92 ,
V_194 & V_317 , & V_184 ) ;
if ( V_184 )
break;
if ( ! V_38 )
continue;
V_40 = F_30 ( V_38 ) ;
F_156 ( V_38 , 64 + V_92 ) ;
if ( F_157 ( F_158 ( V_38 , V_29 ) , V_312 , V_29 ) ) {
V_184 = - V_274 ;
goto V_19;
}
if ( V_194 & V_307 ) {
V_40 -> V_308 = 0x30 ;
if ( V_333 != V_88 )
V_5 -> V_83 -- ;
} else {
V_40 -> V_308 = 0x00 ;
if ( V_5 -> V_355 == 0 )
V_40 -> V_308 |= 0x20 ;
V_5 -> V_355 += V_29 ;
if ( ( ( V_346 + V_29 ) == V_32 ) && ( V_194 & V_330 ) ) {
V_40 -> V_308 |= 0x40 ;
V_5 -> V_355 = 0 ;
if ( V_333 == V_356 )
V_5 -> V_82 -- ;
}
if ( V_333 == V_357 )
V_5 -> V_82 -- ;
}
V_346 += V_29 ;
F_159 ( V_3 , V_38 , V_3 -> V_66 , V_194 & V_307 ) ;
V_38 = NULL ;
V_5 -> V_111 = F_46 ( V_3 ) ;
}
V_19:
F_102 ( V_38 ) ;
F_59 ( V_3 ) ;
return V_346 ? V_346 : V_184 ;
V_349:
V_184 = F_160 ( V_3 , V_194 , V_184 ) ;
F_59 ( V_3 ) ;
return V_184 ;
}
static int F_161 ( struct V_358 * V_359 , unsigned long V_360 ,
void * V_214 )
{
struct V_169 * V_170 = F_162 ( V_214 ) ;
if ( ! F_55 ( F_163 ( V_170 ) , & V_156 ) )
return V_361 ;
switch ( V_360 ) {
case V_362 :
F_164 ( V_170 ) ;
break;
case V_363 :
F_165 ( V_170 ) ;
break;
default:
break;
}
return V_361 ;
}
static struct V_2 * F_166 ( struct V_364 * V_365 )
{
struct V_366 * V_71 = V_365 -> V_367 ;
struct V_2 * V_315 = NULL ;
for( V_71 -> V_368 = 0 ;
V_71 -> V_368 < V_369 ;
++ V_71 -> V_368 ) {
V_315 = F_28 ( & V_10 [ V_71 -> V_368 ] ) ;
if ( V_315 )
break;
}
return V_315 ;
}
static struct V_2 * F_167 ( struct V_364 * V_365 ,
struct V_2 * V_315 )
{
struct V_366 * V_71 = V_365 -> V_367 ;
V_315 = F_168 ( V_315 ) ;
V_370:
if ( V_315 )
goto V_19;
if ( ++ V_71 -> V_368 >= V_369 )
goto V_19;
V_315 = F_28 ( & V_10 [ V_71 -> V_368 ] ) ;
goto V_370;
V_19:
return V_315 ;
}
static struct V_2 * F_169 ( struct V_364 * V_365 , T_8 * V_371 )
{
struct V_2 * V_3 = F_166 ( V_365 ) ;
if ( V_3 ) {
while( * V_371 && ( V_3 = F_167 ( V_365 , V_3 ) ) )
-- * V_371 ;
}
return * V_371 ? NULL : V_3 ;
}
static void * F_170 ( struct V_364 * V_365 , T_8 V_371 )
{
void * V_372 ;
F_171 ( & V_18 ) ;
V_372 = F_169 ( V_365 , & V_371 ) ;
if ( ! V_372 ) {
F_172 ( & V_18 ) ;
}
return V_372 ;
}
static void * F_173 ( struct V_364 * V_365 , T_8 * V_371 )
{
return * V_371 ? F_170 ( V_365 , * V_371 - 1 ) : V_373 ;
}
static void * F_174 ( struct V_364 * V_365 , void * V_374 , T_8 * V_371 )
{
void * V_372 ;
if ( V_374 == V_373 ) {
V_372 = F_170 ( V_365 , 0 ) ;
goto V_19;
}
V_372 = F_167 ( V_365 , V_374 ) ;
if ( V_372 )
goto V_19;
F_172 ( & V_18 ) ;
V_19:
++ * V_371 ;
return V_372 ;
}
static void F_175 ( struct V_364 * V_365 , void * V_374 )
{
if ( V_374 && V_374 != V_373 )
F_172 ( & V_18 ) ;
}
static void F_176 ( struct V_21 * V_375 , unsigned char * V_28 )
{
int V_22 ;
switch ( F_4 ( V_375 -> V_25 ) ) {
case 0 :
sprintf ( V_28 , L_4 , V_375 -> V_24 ) ;
break;
default:
for ( V_22 = 0 ; V_22 < F_4 ( V_375 -> V_25 ) ; V_22 ++ ) {
V_28 [ V_22 ] = V_375 -> V_26 [ V_22 ] ;
if ( F_177 ( V_28 [ V_22 ] ) )
V_28 [ V_22 ] = '.' ;
}
V_28 [ V_22 ] = 0 ;
}
}
static char * F_178 ( unsigned char V_71 )
{
switch ( V_71 ) {
case V_72 :
return L_5 ;
case V_141 :
return L_6 ;
case V_127 :
return L_7 ;
case V_129 :
return L_8 ;
case V_185 :
return L_9 ;
case V_148 :
return L_10 ;
case V_145 :
return L_11 ;
case V_144 :
return L_12 ;
case V_149 :
return L_13 ;
case V_146 :
return L_14 ;
case V_143 :
return L_15 ;
case V_122 :
return L_16 ;
case V_147 :
return L_17 ;
case V_130 :
return L_18 ;
case V_376 :
return L_19 ;
case V_126 :
return L_20 ;
}
return L_21 ;
}
static inline void F_179 ( struct V_364 * V_365 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
char V_377 [ V_378 ] ;
char V_379 [ V_378 ] ;
char V_380 [ V_34 + 3 ] ;
char V_381 [ V_34 + 3 ] ;
F_176 ( & V_5 -> V_6 , V_380 ) ;
F_176 ( & V_5 -> V_42 , V_381 ) ;
F_180 ( V_365 ,
L_22
L_23 ,
F_53 ( F_4 ( F_31 ( & V_5 -> V_6 ) ) , V_377 ) ,
V_5 -> V_11 ,
V_5 -> V_73 ,
V_5 -> V_74 ,
V_5 -> V_75 ,
V_5 -> V_76 ,
V_5 -> V_81 ,
V_380 ,
F_53 ( F_4 ( F_31 ( & V_5 -> V_42 ) ) , V_379 ) ,
V_5 -> V_44 ,
V_5 -> V_382 ,
V_5 -> V_383 ,
V_5 -> V_77 ,
V_5 -> V_78 ,
V_5 -> V_79 ,
V_381 ,
F_178 ( V_5 -> V_71 ) ,
( ( V_5 -> V_95 == V_96 ) ? L_24 : L_25 ) ) ;
}
static int F_181 ( struct V_364 * V_365 , void * V_374 )
{
if ( V_374 == V_373 ) {
F_182 ( V_365 , L_26 ) ;
} else {
F_179 ( V_365 , V_374 ) ;
}
return 0 ;
}
static int F_183 ( struct V_384 * V_384 , struct V_246 * V_246 )
{
return F_184 ( V_246 , & V_385 ,
sizeof( struct V_366 ) ) ;
}
static int T_9 F_185 ( void )
{
int V_372 ;
F_51 ( V_386 ) ;
V_372 = F_186 ( & V_57 , 1 ) ;
if ( V_372 != 0 )
goto V_19;
F_187 () ;
F_188 () ;
F_189 () ;
F_190 () ;
F_191 ( & V_387 ) ;
F_192 ( & V_388 ) ;
F_193 ( & V_389 ) ;
F_194 ( L_27 , V_390 , V_156 . V_391 , & V_392 ) ;
F_195 () ;
V_19:
return V_372 ;
}
