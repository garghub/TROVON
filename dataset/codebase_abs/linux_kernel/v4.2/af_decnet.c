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
if ( ! F_55 ( V_52 , & V_154 ) )
return - V_155 ;
switch ( V_2 -> type ) {
case V_156 :
if ( V_153 != V_157 )
return - V_158 ;
break;
case V_159 :
break;
default:
return - V_160 ;
}
if ( ( V_3 = F_37 ( V_52 , V_2 , V_161 , V_55 ) ) == NULL )
return - V_162 ;
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
static int F_60 ( struct V_53 * V_2 , struct V_163 * V_164 , int V_165 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_21 * V_166 = (struct V_21 * ) V_164 ;
struct V_167 * V_168 , * V_169 ;
int V_16 ;
if ( V_165 != sizeof( struct V_21 ) )
return - V_170 ;
if ( V_166 -> V_97 != V_98 )
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
if ( ( V_5 -> V_99 . V_100 != 0 ) &&
( V_5 -> V_99 . V_100 <= 12 ) ) {
V_5 -> V_6 . V_25 = F_8 ( V_5 -> V_99 . V_100 ) ;
memcpy ( V_5 -> V_6 . V_26 , V_5 -> V_99 . V_101 , F_4 ( V_5 -> V_6 . V_25 ) ) ;
V_5 -> V_99 . V_100 = 0 ;
memset ( V_5 -> V_99 . V_101 , 0 , 40 ) ;
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
if ( V_5 -> V_71 != V_141 )
return - V_170 ;
V_5 -> V_71 = V_184 ;
V_5 -> V_185 = F_73 ( F_74 ( V_3 ) ) ;
F_75 ( V_3 , V_181 ) ;
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
for(; ; ) {
F_59 ( V_3 ) ;
if ( V_5 -> V_71 == V_184 )
* V_180 = F_78 ( * V_180 ) ;
F_58 ( V_3 ) ;
V_183 = 0 ;
if ( V_5 -> V_71 == V_143 )
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
V_3 -> V_135 -> V_71 = V_189 ;
} else if ( V_5 -> V_71 != V_184 ) {
V_3 -> V_135 -> V_71 = V_138 ;
}
return V_183 ;
}
static int F_83 ( struct V_2 * V_3 , long * V_180 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_72 ( V_182 ) ;
int V_183 = 0 ;
if ( V_5 -> V_71 == V_143 )
goto V_19;
if ( ! * V_180 )
return - V_190 ;
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
for(; ; ) {
F_59 ( V_3 ) ;
if ( V_5 -> V_71 == V_148 || V_5 -> V_71 == V_184 )
* V_180 = F_78 ( * V_180 ) ;
F_58 ( V_3 ) ;
V_183 = 0 ;
if ( V_5 -> V_71 == V_143 )
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
V_3 -> V_135 -> V_71 = V_189 ;
} else if ( V_5 -> V_71 != V_148 && V_5 -> V_71 != V_184 ) {
V_3 -> V_135 -> V_71 = V_138 ;
}
return V_183 ;
}
static int F_84 ( struct V_2 * V_3 , struct V_21 * V_6 , int V_192 , long * V_180 , int V_193 )
{
struct V_53 * V_2 = V_3 -> V_135 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_183 = - V_194 ;
struct V_195 V_196 ;
struct V_197 * V_198 ;
if ( V_2 -> V_71 == V_189 )
goto V_19;
if ( V_2 -> V_71 == V_199 ) {
V_183 = 0 ;
if ( V_5 -> V_71 == V_143 ) {
V_2 -> V_71 = V_189 ;
goto V_19;
}
V_183 = - V_200 ;
if ( V_5 -> V_71 != V_148 && V_5 -> V_71 != V_184 ) {
V_2 -> V_71 = V_138 ;
goto V_19;
}
return F_83 ( V_3 , V_180 ) ;
}
V_183 = - V_170 ;
if ( V_5 -> V_71 != V_72 )
goto V_19;
if ( V_6 == NULL || V_192 != sizeof( struct V_21 ) )
goto V_19;
if ( V_6 -> V_97 != V_98 )
goto V_19;
if ( V_6 -> V_7 & V_8 )
goto V_19;
if ( F_66 ( V_3 , V_176 ) ) {
V_183 = F_69 ( V_3 -> V_135 ) ;
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
V_2 -> V_71 = V_199 ;
V_5 -> V_71 = V_148 ;
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
switch ( V_5 -> V_71 ) {
case V_143 :
return 0 ;
case V_141 :
return F_71 ( V_3 , V_180 , V_3 -> V_66 ) ;
case V_148 :
case V_184 :
return F_83 ( V_3 , V_180 ) ;
case V_72 :
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
V_212 -> V_100 = * V_213 ++ ;
memcpy ( & V_212 -> V_101 , V_213 , V_212 -> V_100 ) ;
F_92 ( V_38 , V_212 -> V_100 + V_212 -> V_216 + V_212 -> V_214 + 3 ) ;
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
if ( V_3 -> V_35 != V_36 || F_2 ( V_3 ) -> V_71 != V_72 ) {
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
V_225 = F_37 ( F_101 ( V_3 ) , V_224 , V_3 -> V_66 , 0 ) ;
if ( V_225 == NULL ) {
F_59 ( V_3 ) ;
F_102 ( V_38 ) ;
return - V_162 ;
}
F_59 ( V_3 ) ;
V_198 = F_103 ( V_38 ) ;
F_104 ( V_225 , V_198 ) ;
F_105 ( V_38 , NULL ) ;
F_2 ( V_225 ) -> V_71 = V_141 ;
F_2 ( V_225 ) -> V_44 = V_40 -> V_45 ;
F_2 ( V_225 ) -> V_86 = V_40 -> V_228 ;
F_2 ( V_225 ) -> V_89 = V_40 -> V_229 ;
F_2 ( V_225 ) -> V_91 = V_40 -> V_230 ;
F_2 ( V_225 ) -> V_95 = F_2 ( V_3 ) -> V_95 ;
if ( F_2 ( V_225 ) -> V_91 < 230 )
F_2 ( V_225 ) -> V_91 = 230 ;
if ( ( F_2 ( V_225 ) -> V_86 & V_231 ) == V_88 )
F_2 ( V_225 ) -> V_102 = V_232 ;
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
F_91 ( V_38 , & ( F_2 ( V_225 ) -> V_99 ) ) ;
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
if ( F_2 ( V_225 ) -> V_95 == V_96 )
V_183 = F_71 ( V_225 , & V_180 ,
V_3 -> V_66 ) ;
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
if ( ( V_2 -> V_71 != V_189 &&
V_2 -> V_71 != V_199 ) &&
V_5 -> V_95 == V_96 ) {
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
if ( V_5 -> V_71 != V_143 )
V_252 = - V_244 ;
F_59 ( V_3 ) ;
return V_252 ;
case V_257 :
V_251 = V_3 -> V_67 - F_112 ( V_3 ) ;
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
if ( ( F_2 ( V_3 ) -> V_71 != V_72 ) || ( V_3 -> V_35 == V_36 ) )
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
if ( V_2 -> V_71 == V_138 )
goto V_19;
V_183 = 0 ;
if ( V_2 -> V_71 == V_139 )
goto V_19;
V_183 = - V_170 ;
if ( V_5 -> V_71 == V_72 )
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
if ( V_2 -> V_71 == V_189 )
return - V_194 ;
if ( ( V_5 -> V_71 != V_72 ) && ( V_5 -> V_71 != V_141 ) )
return - V_170 ;
if ( V_269 != sizeof( struct V_218 ) )
return - V_170 ;
if ( F_4 ( V_272 . V_219 . V_220 ) > 16 )
return - V_170 ;
memcpy ( & V_5 -> V_240 , & V_272 . V_219 , V_269 ) ;
break;
case V_275 :
if ( V_2 -> V_71 != V_189 &&
V_5 -> V_95 == V_96 )
return - V_244 ;
if ( V_269 != sizeof( struct V_218 ) )
return - V_170 ;
if ( F_4 ( V_272 . V_219 . V_220 ) > 16 )
return - V_170 ;
memcpy ( & V_5 -> V_241 , & V_272 . V_219 , V_269 ) ;
break;
case V_276 :
if ( V_2 -> V_71 == V_189 )
return - V_194 ;
if ( V_5 -> V_71 != V_72 )
return - V_170 ;
if ( V_269 != sizeof( struct V_211 ) )
return - V_170 ;
if ( ( V_272 . V_212 . V_100 > V_277 ) ||
( V_272 . V_212 . V_216 > V_277 ) ||
( V_272 . V_212 . V_214 > V_277 ) )
return - V_170 ;
memcpy ( & V_5 -> V_99 , & V_272 . V_212 , V_269 ) ;
break;
case V_278 :
if ( V_2 -> V_71 == V_189 )
return - V_194 ;
if ( V_5 -> V_71 != V_72 )
return - V_170 ;
if ( V_269 != sizeof( int ) )
return - V_170 ;
if ( ( V_272 . V_270 != V_96 ) && ( V_272 . V_270 != V_279 ) )
return - V_170 ;
V_5 -> V_95 = ( unsigned char ) V_272 . V_270 ;
break;
case V_280 :
if ( V_5 -> V_71 != V_141 )
return - V_170 ;
V_180 = F_98 ( V_3 , 0 ) ;
V_183 = F_71 ( V_3 , & V_180 , V_3 -> V_66 ) ;
return V_183 ;
case V_281 :
if ( V_5 -> V_71 != V_141 )
return - V_170 ;
V_5 -> V_71 = V_127 ;
V_3 -> V_264 = V_265 ;
F_47 ( V_3 , 0x38 , 0 , V_3 -> V_66 ) ;
break;
default:
#ifdef F_121
return F_122 ( V_3 , V_56 , V_267 , V_268 , V_269 ) ;
#endif
case V_282 :
case V_283 :
case V_284 :
return - V_285 ;
case V_286 :
if ( V_269 != sizeof( unsigned long ) )
return - V_170 ;
if ( V_272 . V_271 > V_103 )
V_272 . V_271 = V_103 ;
if ( V_272 . V_271 == 0 )
return - V_170 ;
V_5 -> V_102 = V_272 . V_271 ;
if ( V_5 -> V_104 > V_272 . V_271 )
V_5 -> V_104 = V_272 . V_271 ;
break;
case V_287 :
if ( V_269 != sizeof( int ) )
return - V_170 ;
if ( V_5 -> V_93 == 2 )
return - V_170 ;
V_5 -> V_93 = ( V_272 . V_252 == 0 ) ? 0 : 1 ;
break;
case V_288 :
if ( V_269 != sizeof( int ) )
return - V_170 ;
if ( V_5 -> V_93 == 1 )
return - V_170 ;
V_5 -> V_93 = ( V_272 . V_252 == 0 ) ? 0 : 2 ;
break;
case V_289 :
if ( V_269 != sizeof( unsigned char ) )
return - V_170 ;
if ( ( V_272 . V_228 & ~ V_231 ) != 0x01 )
return - V_170 ;
if ( ( V_272 . V_228 & V_231 ) == V_231 )
return - V_170 ;
V_5 -> V_87 = V_272 . V_228 ;
break;
case V_290 :
if ( V_269 != sizeof( unsigned char ) )
return - V_170 ;
if ( V_272 . V_229 & 0xfc )
return - V_170 ;
V_5 -> V_90 = V_272 . V_229 ;
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
V_294 = & V_5 -> V_99 ;
break;
case V_278 :
if ( V_293 > sizeof( unsigned char ) )
V_293 = sizeof( unsigned char ) ;
V_294 = & V_5 -> V_95 ;
break;
case V_282 :
if ( V_293 > sizeof( struct V_291 ) )
V_293 = sizeof( struct V_291 ) ;
memset ( & V_292 , 0 , sizeof( V_292 ) ) ;
switch ( V_2 -> V_71 ) {
case V_199 :
V_292 . V_296 = V_297 ;
break;
case V_139 :
V_292 . V_296 = V_298 ;
break;
case V_189 :
V_292 . V_296 = V_299 ;
break;
default:
V_292 . V_296 = V_300 ;
}
V_292 . V_301 = V_5 -> V_91 ;
V_294 = & V_292 ;
break;
default:
#ifdef F_121
{
int V_302 , V_29 ;
if ( F_125 ( V_29 , V_269 ) )
return - V_273 ;
V_302 = F_126 ( V_3 , V_56 , V_267 , V_268 , & V_29 ) ;
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
V_294 = & V_5 -> V_102 ;
break;
case V_287 :
if ( V_293 > sizeof( int ) )
V_293 = sizeof( int ) ;
V_252 = ( V_5 -> V_93 == 1 ) ;
V_294 = & V_252 ;
break;
case V_288 :
if ( V_293 > sizeof( int ) )
V_293 = sizeof( int ) ;
V_252 = ( V_5 -> V_93 == 2 ) ;
V_294 = & V_252 ;
break;
case V_289 :
if ( V_293 > sizeof( unsigned char ) )
V_293 = sizeof( unsigned char ) ;
V_294 = & V_5 -> V_86 ;
break;
case V_290 :
if ( V_293 > sizeof( unsigned char ) )
V_293 = sizeof( unsigned char ) ;
V_294 = & V_5 -> V_89 ;
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
static int F_129 ( struct V_53 * V_2 , struct V_310 * V_311 , T_6 V_32 ,
int V_193 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_303 * V_312 = & V_3 -> V_223 ;
T_6 V_305 = V_32 > 1 ? 1 : 0 ;
T_6 V_313 = 0 ;
int V_16 = 0 ;
struct V_37 * V_38 , * V_314 ;
struct V_39 * V_40 = NULL ;
unsigned char V_315 = 0 ;
long V_180 = F_98 ( V_3 , V_193 & V_316 ) ;
F_58 ( V_3 ) ;
if ( F_66 ( V_3 , V_176 ) ) {
V_16 = - V_175 ;
goto V_19;
}
if ( V_3 -> V_264 & V_317 ) {
V_16 = 0 ;
goto V_19;
}
V_16 = F_90 ( V_3 , NULL , 0 , & V_180 , V_193 ) ;
if ( V_16 )
goto V_19;
if ( V_193 & ~ ( V_318 | V_319 | V_306 | V_309 | V_316 | V_320 ) ) {
V_16 = - V_250 ;
goto V_19;
}
if ( V_193 & V_306 )
V_312 = & V_5 -> V_49 ;
if ( V_193 & V_309 )
V_305 = V_32 ;
for(; ; ) {
F_72 ( V_182 ) ;
if ( V_3 -> V_321 )
goto V_19;
if ( ! F_43 ( & V_5 -> V_49 ) ) {
if ( ! ( V_193 & V_306 ) ) {
V_311 -> V_322 |= V_306 ;
if ( ! V_5 -> V_323 ) {
V_5 -> V_323 = 1 ;
goto V_19;
}
}
}
if ( V_5 -> V_71 != V_143 )
goto V_19;
if ( F_81 ( V_187 ) ) {
V_16 = F_80 ( V_180 ) ;
goto V_19;
}
if ( F_128 ( V_3 , V_312 , V_193 , V_305 ) )
break;
if ( V_193 & V_316 ) {
V_16 = - V_324 ;
goto V_19;
}
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
F_130 ( V_325 , & V_3 -> V_135 -> V_193 ) ;
F_131 ( V_3 , & V_180 , F_128 ( V_3 , V_312 , V_193 , V_305 ) ) ;
F_132 ( V_325 , & V_3 -> V_135 -> V_193 ) ;
F_82 ( F_77 ( V_3 ) , & V_182 ) ;
}
F_133 (queue, skb, n) {
unsigned int V_326 = V_38 -> V_29 ;
V_40 = F_30 ( V_38 ) ;
if ( ( V_326 + V_313 ) > V_32 )
V_326 = V_32 - V_313 ;
if ( F_134 ( V_311 , V_38 -> V_30 , V_326 ) ) {
V_16 = - V_273 ;
break;
}
V_313 += V_326 ;
if ( ! ( V_193 & V_319 ) )
F_92 ( V_38 , V_326 ) ;
V_315 = V_40 -> V_307 & 0x40 ;
if ( V_38 -> V_29 == 0 ) {
F_135 ( V_38 , V_312 ) ;
F_102 ( V_38 ) ;
if ( ( V_5 -> V_81 == V_327 ) && ! F_136 ( V_3 ) ) {
V_5 -> V_81 = V_80 ;
F_44 ( V_3 , V_80 , 0 ) ;
}
}
if ( V_315 ) {
if ( V_3 -> V_308 == V_156 )
break;
if ( ! ( V_193 & V_309 ) )
break;
}
if ( V_193 & V_306 )
break;
if ( V_313 >= V_305 )
break;
}
V_16 = V_313 ;
if ( V_315 && ( V_3 -> V_308 == V_156 ) )
V_311 -> V_322 |= V_328 ;
V_19:
if ( V_16 == 0 )
V_16 = ( V_193 & V_319 ) ? - V_3 -> V_321 : F_79 ( V_3 ) ;
if ( ( V_16 >= 0 ) && V_311 -> V_329 ) {
F_137 ( sizeof( struct V_21 ) ) ;
memcpy ( V_311 -> V_329 , & V_5 -> V_42 , sizeof( struct V_21 ) ) ;
V_311 -> V_330 = sizeof( struct V_21 ) ;
}
F_59 ( V_3 ) ;
return V_16 ;
}
static inline int F_138 ( struct V_4 * V_5 , struct V_303 * V_312 , int V_193 )
{
unsigned char V_331 = V_5 -> V_86 & V_231 ;
if ( F_139 ( V_312 ) >= V_5 -> V_104 )
return 1 ;
if ( V_331 != V_88 ) {
if ( V_193 & V_306 ) {
if ( V_5 -> V_83 == 0 )
return 1 ;
} else {
if ( V_5 -> V_82 == 0 )
return 1 ;
}
}
return 0 ;
}
unsigned int F_140 ( struct V_167 * V_168 , int V_332 )
{
unsigned int V_333 = 230 - V_92 ;
if ( V_168 ) {
struct V_334 * V_335 = F_141 ( V_168 -> V_174 ) ;
V_332 -= F_142 ( V_168 ) ;
if ( V_335 -> V_336 )
V_332 -= 21 ;
else
V_332 -= 6 ;
V_332 -= V_92 ;
} else {
V_332 -= ( 21 + V_92 + 16 ) ;
}
if ( V_332 > V_333 )
V_333 = V_332 ;
return V_333 ;
}
static inline unsigned int F_143 ( struct V_2 * V_3 , int V_193 )
{
struct V_197 * V_198 = F_74 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_337 = F_144 ( int , V_5 -> V_185 , V_5 -> V_91 ) ;
if ( V_193 & V_306 )
return 16 ;
if ( V_198 ) {
T_7 V_332 = F_145 ( V_198 ) ;
V_337 = F_144 ( int , F_140 ( V_198 -> V_168 , V_332 ) , V_337 ) ;
}
return V_337 ;
}
static inline struct V_37 * F_146 ( struct V_2 * V_3 ,
unsigned long V_338 , int V_339 ,
int * V_340 )
{
struct V_37 * V_38 = F_147 ( V_3 , V_338 ,
V_339 , V_340 ) ;
if ( V_38 ) {
V_38 -> V_153 = F_148 ( V_341 ) ;
V_38 -> V_342 = V_343 ;
}
return V_38 ;
}
static int F_149 ( struct V_53 * V_2 , struct V_310 * V_311 , T_6 V_32 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_6 V_333 ;
struct V_303 * V_312 = & V_5 -> V_47 ;
int V_193 = V_311 -> V_322 ;
int V_183 = 0 ;
T_6 V_344 = 0 ;
int V_165 = V_311 -> V_330 ;
F_150 ( struct V_21 * , V_6 , V_311 -> V_329 ) ;
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
T_6 V_29 ;
unsigned char V_331 ;
long V_180 ;
if ( V_193 & ~ ( V_345 | V_306 | V_316 | V_328 | V_320 | V_346 | V_318 ) )
return - V_250 ;
if ( V_165 && ( V_165 != sizeof( struct V_21 ) ) )
return - V_170 ;
F_58 ( V_3 ) ;
V_180 = F_89 ( V_3 , V_193 & V_316 ) ;
if ( V_2 -> type == V_159 ) {
if ( V_193 & V_328 ) {
V_183 = - V_170 ;
goto V_19;
}
V_193 |= V_328 ;
}
V_183 = F_90 ( V_3 , V_6 , V_165 , & V_180 , V_193 ) ;
if ( V_183 )
goto V_347;
if ( V_3 -> V_264 & V_348 ) {
V_183 = - V_349 ;
if ( ! ( V_193 & V_320 ) )
F_151 ( V_350 , V_187 , 0 ) ;
goto V_347;
}
if ( ( V_193 & V_345 ) && V_3 -> V_50 )
F_152 ( V_3 ) ;
V_333 = V_5 -> V_91 ;
V_331 = V_5 -> V_86 & V_231 ;
V_333 = F_143 ( V_3 , V_193 ) ;
if ( V_193 & V_306 ) {
V_312 = & V_5 -> V_48 ;
if ( V_32 > V_333 ) {
V_183 = - V_351 ;
goto V_19;
}
}
V_5 -> V_112 = V_352 ;
while( V_344 < V_32 ) {
V_183 = F_79 ( V_3 ) ;
if ( V_183 )
goto V_19;
if ( F_81 ( V_187 ) ) {
V_183 = F_80 ( V_180 ) ;
goto V_19;
}
V_29 = V_32 - V_344 ;
if ( V_29 > V_333 )
V_29 = V_333 ;
if ( F_138 ( V_5 , V_312 , V_193 ) ) {
F_72 ( V_182 ) ;
if ( V_193 & V_316 ) {
V_183 = - V_324 ;
goto V_19;
}
F_76 ( F_77 ( V_3 ) , & V_182 , V_186 ) ;
F_130 ( V_325 , & V_3 -> V_135 -> V_193 ) ;
F_131 ( V_3 , & V_180 ,
! F_138 ( V_5 , V_312 , V_193 ) ) ;
F_132 ( V_325 , & V_3 -> V_135 -> V_193 ) ;
F_82 ( F_77 ( V_3 ) , & V_182 ) ;
continue;
}
V_38 = F_146 ( V_3 , V_29 + 64 + V_92 ,
V_193 & V_316 , & V_183 ) ;
if ( V_183 )
break;
if ( ! V_38 )
continue;
V_40 = F_30 ( V_38 ) ;
F_153 ( V_38 , 64 + V_92 ) ;
if ( F_154 ( F_155 ( V_38 , V_29 ) , V_311 , V_29 ) ) {
V_183 = - V_273 ;
goto V_19;
}
if ( V_193 & V_306 ) {
V_40 -> V_307 = 0x30 ;
if ( V_331 != V_88 )
V_5 -> V_83 -- ;
} else {
V_40 -> V_307 = 0x00 ;
if ( V_5 -> V_353 == 0 )
V_40 -> V_307 |= 0x20 ;
V_5 -> V_353 += V_29 ;
if ( ( ( V_344 + V_29 ) == V_32 ) && ( V_193 & V_328 ) ) {
V_40 -> V_307 |= 0x40 ;
V_5 -> V_353 = 0 ;
if ( V_331 == V_354 )
V_5 -> V_82 -- ;
}
if ( V_331 == V_355 )
V_5 -> V_82 -- ;
}
V_344 += V_29 ;
F_156 ( V_3 , V_38 , V_3 -> V_66 , V_193 & V_306 ) ;
V_38 = NULL ;
V_5 -> V_111 = F_46 ( V_3 ) ;
}
V_19:
F_102 ( V_38 ) ;
F_59 ( V_3 ) ;
return V_344 ? V_344 : V_183 ;
V_347:
V_183 = F_157 ( V_3 , V_193 , V_183 ) ;
F_59 ( V_3 ) ;
return V_183 ;
}
static int F_158 ( struct V_356 * V_357 , unsigned long V_358 ,
void * V_213 )
{
struct V_167 * V_168 = F_159 ( V_213 ) ;
if ( ! F_55 ( F_160 ( V_168 ) , & V_154 ) )
return V_359 ;
switch ( V_358 ) {
case V_360 :
F_161 ( V_168 ) ;
break;
case V_361 :
F_162 ( V_168 ) ;
break;
default:
break;
}
return V_359 ;
}
static struct V_2 * F_163 ( struct V_362 * V_363 )
{
struct V_364 * V_71 = V_363 -> V_365 ;
struct V_2 * V_314 = NULL ;
for( V_71 -> V_366 = 0 ;
V_71 -> V_366 < V_367 ;
++ V_71 -> V_366 ) {
V_314 = F_28 ( & V_10 [ V_71 -> V_366 ] ) ;
if ( V_314 )
break;
}
return V_314 ;
}
static struct V_2 * F_164 ( struct V_362 * V_363 ,
struct V_2 * V_314 )
{
struct V_364 * V_71 = V_363 -> V_365 ;
V_314 = F_165 ( V_314 ) ;
V_368:
if ( V_314 )
goto V_19;
if ( ++ V_71 -> V_366 >= V_367 )
goto V_19;
V_314 = F_28 ( & V_10 [ V_71 -> V_366 ] ) ;
goto V_368;
V_19:
return V_314 ;
}
static struct V_2 * F_166 ( struct V_362 * V_363 , T_8 * V_369 )
{
struct V_2 * V_3 = F_163 ( V_363 ) ;
if ( V_3 ) {
while( * V_369 && ( V_3 = F_164 ( V_363 , V_3 ) ) )
-- * V_369 ;
}
return * V_369 ? NULL : V_3 ;
}
static void * F_167 ( struct V_362 * V_363 , T_8 V_369 )
{
void * V_370 ;
F_168 ( & V_18 ) ;
V_370 = F_166 ( V_363 , & V_369 ) ;
if ( ! V_370 ) {
F_169 ( & V_18 ) ;
}
return V_370 ;
}
static void * F_170 ( struct V_362 * V_363 , T_8 * V_369 )
{
return * V_369 ? F_167 ( V_363 , * V_369 - 1 ) : V_371 ;
}
static void * F_171 ( struct V_362 * V_363 , void * V_372 , T_8 * V_369 )
{
void * V_370 ;
if ( V_372 == V_371 ) {
V_370 = F_167 ( V_363 , 0 ) ;
goto V_19;
}
V_370 = F_164 ( V_363 , V_372 ) ;
if ( V_370 )
goto V_19;
F_169 ( & V_18 ) ;
V_19:
++ * V_369 ;
return V_370 ;
}
static void F_172 ( struct V_362 * V_363 , void * V_372 )
{
if ( V_372 && V_372 != V_371 )
F_169 ( & V_18 ) ;
}
static void F_173 ( struct V_21 * V_373 , unsigned char * V_28 )
{
int V_22 ;
switch ( F_4 ( V_373 -> V_25 ) ) {
case 0 :
sprintf ( V_28 , L_4 , V_373 -> V_24 ) ;
break;
default:
for ( V_22 = 0 ; V_22 < F_4 ( V_373 -> V_25 ) ; V_22 ++ ) {
V_28 [ V_22 ] = V_373 -> V_26 [ V_22 ] ;
if ( F_174 ( V_28 [ V_22 ] ) )
V_28 [ V_22 ] = '.' ;
}
V_28 [ V_22 ] = 0 ;
}
}
static char * F_175 ( unsigned char V_71 )
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
case V_184 :
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
case V_374 :
return L_19 ;
case V_126 :
return L_20 ;
}
return L_21 ;
}
static inline void F_176 ( struct V_362 * V_363 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
char V_375 [ V_376 ] ;
char V_377 [ V_376 ] ;
char V_378 [ V_34 + 3 ] ;
char V_379 [ V_34 + 3 ] ;
F_173 ( & V_5 -> V_6 , V_378 ) ;
F_173 ( & V_5 -> V_42 , V_379 ) ;
F_177 ( V_363 ,
L_22
L_23 ,
F_53 ( F_4 ( F_31 ( & V_5 -> V_6 ) ) , V_375 ) ,
V_5 -> V_11 ,
V_5 -> V_73 ,
V_5 -> V_74 ,
V_5 -> V_75 ,
V_5 -> V_76 ,
V_5 -> V_81 ,
V_378 ,
F_53 ( F_4 ( F_31 ( & V_5 -> V_42 ) ) , V_377 ) ,
V_5 -> V_44 ,
V_5 -> V_380 ,
V_5 -> V_381 ,
V_5 -> V_77 ,
V_5 -> V_78 ,
V_5 -> V_79 ,
V_379 ,
F_175 ( V_5 -> V_71 ) ,
( ( V_5 -> V_95 == V_96 ) ? L_24 : L_25 ) ) ;
}
static int F_178 ( struct V_362 * V_363 , void * V_372 )
{
if ( V_372 == V_371 ) {
F_179 ( V_363 , L_26 ) ;
} else {
F_176 ( V_363 , V_372 ) ;
}
return 0 ;
}
static int F_180 ( struct V_382 * V_382 , struct V_245 * V_245 )
{
return F_181 ( V_245 , & V_383 ,
sizeof( struct V_364 ) ) ;
}
static int T_9 F_182 ( void )
{
int V_370 ;
F_51 ( V_384 ) ;
V_370 = F_183 ( & V_57 , 1 ) ;
if ( V_370 != 0 )
goto V_19;
F_184 () ;
F_185 () ;
F_186 () ;
F_187 () ;
F_188 ( & V_385 ) ;
F_189 ( & V_386 ) ;
F_190 ( & V_387 ) ;
F_191 ( L_27 , V_388 , V_154 . V_389 , & V_390 ) ;
F_192 () ;
V_19:
return V_370 ;
}
