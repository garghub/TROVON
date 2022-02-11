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
struct V_14 * V_15 ;
if ( V_13 == 0 )
return - 1 ;
F_6 (sk, node, &dn_sk_hash[le16_to_cpu(port) & DN_SK_HASH_MASK]) {
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
unsigned short V_16 = V_13 ;
while( F_5 ( F_8 ( ++ V_13 ) ) != 0 ) {
if ( V_13 == V_16 )
return 0 ;
}
V_5 -> V_11 = F_8 ( V_13 ) ;
return 1 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_17 ;
int V_18 = - V_19 ;
F_10 ( F_11 ( V_3 ) ) ;
F_12 ( & V_20 ) ;
if ( ! V_5 -> V_11 && ! F_7 ( V_3 ) )
goto V_21;
V_18 = - V_22 ;
if ( ( V_17 = F_1 ( V_3 ) ) == NULL )
goto V_21;
F_13 ( V_3 , V_17 ) ;
V_18 = 0 ;
V_21:
F_14 ( & V_20 ) ;
return V_18 ;
}
static void F_15 ( struct V_2 * V_3 )
{
F_16 ( & V_20 ) ;
F_17 ( V_3 ) ;
F_18 ( & V_20 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
F_12 ( & V_20 ) ;
F_17 ( V_3 ) ;
F_14 ( & V_20 ) ;
}
static struct V_1 * F_20 ( struct V_23 * V_6 )
{
int V_24 ;
unsigned V_25 = V_6 -> V_26 ;
if ( V_25 == 0 ) {
V_25 = V_6 -> V_27 ;
for( V_24 = 0 ; V_24 < F_4 ( V_6 -> V_27 ) ; V_24 ++ ) {
V_25 ^= V_6 -> V_28 [ V_24 ] ;
V_25 ^= ( V_25 << 3 ) ;
}
}
return & V_10 [ V_25 & V_12 ] ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_17 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 . V_7 & V_8 )
return;
F_12 ( & V_20 ) ;
F_17 ( V_3 ) ;
F_2 ( V_3 ) -> V_11 = 0 ;
V_17 = F_20 ( & F_2 ( V_3 ) -> V_6 ) ;
F_13 ( V_3 , V_17 ) ;
F_14 ( & V_20 ) ;
}
int F_22 ( struct V_23 * V_29 , unsigned char * V_30 , unsigned char type )
{
int V_31 = 2 ;
* V_30 ++ = type ;
switch ( type ) {
case 0 :
* V_30 ++ = V_29 -> V_26 ;
break;
case 1 :
* V_30 ++ = 0 ;
* V_30 ++ = F_4 ( V_29 -> V_27 ) ;
memcpy ( V_30 , V_29 -> V_28 , F_4 ( V_29 -> V_27 ) ) ;
V_31 = 3 + F_4 ( V_29 -> V_27 ) ;
break;
case 2 :
memset ( V_30 , 0 , 5 ) ;
V_30 += 5 ;
* V_30 ++ = F_4 ( V_29 -> V_27 ) ;
memcpy ( V_30 , V_29 -> V_28 , F_4 ( V_29 -> V_27 ) ) ;
V_31 = 7 + F_4 ( V_29 -> V_27 ) ;
break;
}
return V_31 ;
}
int F_23 ( unsigned char * V_32 , int V_31 , struct V_23 * V_29 , unsigned char * V_33 )
{
unsigned char type ;
int V_34 = V_31 ;
int V_35 = 12 ;
V_29 -> V_26 = 0 ;
V_29 -> V_27 = F_8 ( 0 ) ;
memset ( V_29 -> V_28 , 0 , V_36 ) ;
if ( V_31 < 2 )
return - 1 ;
V_31 -= 2 ;
* V_33 = * V_32 ++ ;
type = * V_32 ++ ;
switch ( * V_33 ) {
case 0 :
V_29 -> V_26 = type ;
return 2 ;
case 1 :
V_35 = 16 ;
break;
case 2 :
V_31 -= 4 ;
V_32 += 4 ;
break;
case 4 :
V_31 -= 8 ;
V_32 += 8 ;
break;
default:
return - 1 ;
}
V_31 -= 1 ;
if ( V_31 < 0 )
return - 1 ;
V_29 -> V_27 = F_8 ( * V_32 ++ ) ;
V_31 -= F_4 ( V_29 -> V_27 ) ;
if ( ( V_31 < 0 ) || ( F_4 ( V_29 -> V_27 ) > V_35 ) )
return - 1 ;
memcpy ( V_29 -> V_28 , V_32 , F_4 ( V_29 -> V_27 ) ) ;
return V_34 - V_31 ;
}
struct V_2 * F_24 ( struct V_23 * V_6 )
{
struct V_1 * V_17 = F_20 ( V_6 ) ;
struct V_14 * V_15 ;
struct V_2 * V_3 ;
F_25 ( & V_20 ) ;
F_6 (sk, node, list) {
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_3 -> V_37 != V_38 )
continue;
if ( V_5 -> V_6 . V_26 ) {
if ( V_5 -> V_6 . V_26 != V_6 -> V_26 )
continue;
} else {
if ( V_6 -> V_26 )
continue;
if ( V_5 -> V_6 . V_27 != V_6 -> V_27 )
continue;
if ( memcmp ( V_5 -> V_6 . V_28 , V_6 -> V_28 , F_4 ( V_6 -> V_27 ) ) != 0 )
continue;
}
F_26 ( V_3 ) ;
F_27 ( & V_20 ) ;
return V_3 ;
}
V_3 = F_28 ( & V_9 ) ;
if ( V_3 ) {
if ( V_3 -> V_37 == V_38 )
F_26 ( V_3 ) ;
else
V_3 = NULL ;
}
F_27 ( & V_20 ) ;
return V_3 ;
}
struct V_2 * F_29 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_30 ( V_40 ) ;
struct V_2 * V_3 ;
struct V_14 * V_15 ;
struct V_4 * V_5 ;
F_25 ( & V_20 ) ;
F_6 (sk, node, &dn_sk_hash[le16_to_cpu(cb->dst_port) & DN_SK_HASH_MASK]) {
V_5 = F_2 ( V_3 ) ;
if ( V_42 -> V_43 != F_31 ( & V_5 -> V_44 ) )
continue;
if ( V_42 -> V_45 != V_5 -> V_11 )
continue;
if ( V_5 -> V_46 && ( V_42 -> V_47 != V_5 -> V_46 ) )
continue;
F_26 ( V_3 ) ;
goto V_48;
}
V_3 = NULL ;
V_48:
F_27 ( & V_20 ) ;
return V_3 ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_33 ( & V_5 -> V_49 ) ;
F_33 ( & V_5 -> V_50 ) ;
F_33 ( & V_5 -> V_51 ) ;
F_34 ( F_35 ( V_3 -> V_52 , 1 ) ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
if ( ! V_53 ) {
V_53 = 1 ;
}
}
static struct V_2 * F_37 ( struct V_54 * V_54 , struct V_55 * V_2 , T_2 V_56 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 = F_38 ( V_54 , V_57 , V_56 , & V_58 ) ;
if ( ! V_3 )
goto V_21;
if ( V_2 )
V_2 -> V_59 = & V_60 ;
F_39 ( V_2 , V_3 ) ;
V_3 -> V_61 = V_62 ;
V_3 -> V_63 = F_32 ;
V_3 -> V_64 = 1 ;
V_3 -> V_65 = V_57 ;
V_3 -> V_66 = 0 ;
V_3 -> V_67 = V_56 ;
V_3 -> V_68 = V_69 [ 1 ] ;
V_3 -> V_70 = V_71 [ 1 ] ;
V_5 = F_2 ( V_3 ) ;
V_5 -> V_72 = V_73 ;
V_5 -> V_74 = 1 ;
V_5 -> V_75 = 1 ;
V_5 -> V_76 = 0 ;
V_5 -> V_77 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_79 = 0 ;
V_5 -> V_80 = V_81 ;
V_5 -> V_82 = V_81 ;
V_5 -> V_83 = 0 ;
V_5 -> V_84 = 1 ;
V_5 -> V_85 = 0 ;
V_5 -> V_86 = 1 ;
V_5 -> V_87 = 0 ;
V_5 -> V_88 = 1 | V_89 ;
V_5 -> V_90 = 0 ;
V_5 -> V_91 = 0x03 ;
V_5 -> V_92 = 230 - V_93 ;
V_5 -> V_94 = 0 ;
V_5 -> V_95 = 1 ;
V_5 -> V_96 = V_97 ;
V_5 -> V_6 . V_98 = V_99 ;
V_5 -> V_44 . V_98 = V_99 ;
V_5 -> V_100 . V_101 = 5 ;
memcpy ( V_5 -> V_100 . V_102 , L_1 , 5 ) ;
V_5 -> V_103 = V_104 ;
V_5 -> V_105 = V_106 ;
V_5 -> V_107 = V_108 ;
V_5 -> V_109 = V_110 ;
V_5 -> V_111 = 0 ;
F_40 ( & V_5 -> V_49 ) ;
F_40 ( & V_5 -> V_50 ) ;
F_40 ( & V_5 -> V_51 ) ;
V_5 -> V_112 = 0 ;
V_5 -> V_113 = NULL ;
V_5 -> V_114 = 10 * V_115 ;
V_5 -> V_116 = V_117 ;
F_41 ( & V_5 -> V_118 ) ;
V_5 -> V_119 = 0 ;
V_5 -> V_120 = V_121 ;
F_42 ( V_3 ) ;
V_21:
return V_3 ;
}
static void V_117 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( F_43 ( & V_5 -> V_50 ) )
F_44 ( V_3 , V_122 , 0 ) ;
}
int F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_5 -> V_112 = F_46 ( V_3 ) ;
switch ( V_5 -> V_72 ) {
case V_123 :
F_47 ( V_3 , V_124 , 0 , V_125 ) ;
if ( V_5 -> V_111 >= V_126 )
V_5 -> V_72 = V_127 ;
return 0 ;
case V_128 :
F_47 ( V_3 , V_124 , 0 , V_125 ) ;
if ( V_5 -> V_111 >= V_129 )
V_5 -> V_72 = V_130 ;
return 0 ;
case V_131 :
if ( V_5 -> V_111 < V_132 ) {
F_47 ( V_3 , V_133 , V_134 ,
V_125 ) ;
return 0 ;
}
}
V_5 -> V_112 = ( V_115 * V_135 ) ;
if ( V_3 -> V_136 )
return 0 ;
if ( ( V_137 - V_5 -> V_138 ) >= ( V_115 * V_135 ) ) {
F_15 ( V_3 ) ;
F_48 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_5 -> V_111 = 0 ;
if ( V_3 -> V_136 ) {
if ( V_3 -> V_136 -> V_72 != V_139 )
V_3 -> V_136 -> V_72 = V_140 ;
}
V_3 -> V_37 = V_141 ;
switch ( V_5 -> V_72 ) {
case V_131 :
F_47 ( V_3 , V_133 , V_134 ,
V_3 -> V_67 ) ;
V_5 -> V_113 = F_45 ;
V_5 -> V_112 = F_46 ( V_3 ) ;
break;
case V_142 :
V_5 -> V_72 = V_128 ;
goto V_143;
case V_144 :
V_5 -> V_72 = V_123 ;
case V_123 :
case V_128 :
V_143:
F_47 ( V_3 , V_124 , 0 , V_3 -> V_67 ) ;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_127 :
case V_130 :
case V_149 :
case V_150 :
V_5 -> V_113 = F_45 ;
V_5 -> V_112 = F_46 ( V_3 ) ;
break;
default:
F_50 ( V_151 L_2 ) ;
case V_73 :
F_51 ( V_3 ) ;
F_19 ( V_3 ) ;
F_48 ( V_3 ) ;
break;
}
}
char * F_52 ( T_3 V_6 , char * V_30 )
{
unsigned short V_15 , V_152 ;
V_15 = V_6 & 0x03ff ;
V_152 = V_6 >> 10 ;
sprintf ( V_30 , L_3 , V_152 , V_15 ) ;
return V_30 ;
}
static int F_53 ( struct V_54 * V_54 , struct V_55 * V_2 , int V_153 ,
int V_154 )
{
struct V_2 * V_3 ;
if ( ! F_54 ( V_54 , & V_155 ) )
return - V_156 ;
switch ( V_2 -> type ) {
case V_157 :
if ( V_153 != V_158 )
return - V_159 ;
break;
case V_160 :
break;
default:
return - V_161 ;
}
if ( ( V_3 = F_37 ( V_54 , V_2 , V_162 ) ) == NULL )
return - V_163 ;
V_3 -> V_66 = V_153 ;
return 0 ;
}
static int
F_55 ( struct V_55 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 ) {
F_56 ( V_3 ) ;
F_26 ( V_3 ) ;
F_57 ( V_3 ) ;
F_49 ( V_3 ) ;
F_58 ( V_3 ) ;
F_48 ( V_3 ) ;
}
return 0 ;
}
static int F_59 ( struct V_55 * V_2 , struct V_164 * V_165 , int V_166 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_23 * V_167 = (struct V_23 * ) V_165 ;
struct V_168 * V_169 , * V_170 ;
int V_18 ;
if ( V_166 != sizeof( struct V_23 ) )
return - V_171 ;
if ( V_167 -> V_98 != V_99 )
return - V_171 ;
if ( F_4 ( V_167 -> V_172 ) && ( F_4 ( V_167 -> V_172 ) != 2 ) )
return - V_171 ;
if ( F_4 ( V_167 -> V_27 ) > V_36 )
return - V_171 ;
if ( V_167 -> V_7 & ~ V_8 )
return - V_171 ;
if ( ! F_60 ( V_173 ) && ( V_167 -> V_26 ||
( V_167 -> V_7 & V_8 ) ) )
return - V_174 ;
if ( ! ( V_167 -> V_7 & V_8 ) ) {
if ( F_4 ( V_167 -> V_172 ) ) {
F_61 () ;
V_170 = NULL ;
F_62 (&init_net, dev) {
if ( ! V_169 -> V_175 )
continue;
if ( F_63 ( V_169 , F_31 ( V_167 ) ) ) {
V_170 = V_169 ;
break;
}
}
F_64 () ;
if ( V_170 == NULL )
return - V_176 ;
}
}
V_18 = - V_171 ;
F_57 ( V_3 ) ;
if ( F_65 ( V_3 , V_177 ) ) {
memcpy ( & V_5 -> V_6 , V_167 , V_166 ) ;
F_66 ( V_3 , V_177 ) ;
V_18 = F_9 ( V_3 ) ;
if ( V_18 )
F_67 ( V_3 , V_177 ) ;
}
F_58 ( V_3 ) ;
return V_18 ;
}
static int F_68 ( struct V_55 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_18 ;
F_66 ( V_3 , V_177 ) ;
V_5 -> V_6 . V_7 = 0 ;
V_5 -> V_6 . V_26 = 0 ;
if ( ( V_5 -> V_100 . V_101 != 0 ) &&
( V_5 -> V_100 . V_101 <= 12 ) ) {
V_5 -> V_6 . V_27 = F_8 ( V_5 -> V_100 . V_101 ) ;
memcpy ( V_5 -> V_6 . V_28 , V_5 -> V_100 . V_102 , F_4 ( V_5 -> V_6 . V_27 ) ) ;
V_5 -> V_100 . V_101 = 0 ;
memset ( V_5 -> V_100 . V_102 , 0 , 40 ) ;
}
V_5 -> V_6 . V_178 . V_179 = F_8 ( 2 ) ;
V_18 = F_69 ( ( T_1 * ) V_5 -> V_6 . V_178 . V_180 ) ;
if ( V_18 == 0 ) {
V_18 = F_9 ( V_3 ) ;
if ( V_18 )
F_67 ( V_3 , V_177 ) ;
}
return V_18 ;
}
static int F_70 ( struct V_2 * V_3 , long * V_181 , T_2 V_182 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_71 ( V_183 ) ;
int V_184 ;
if ( V_5 -> V_72 != V_142 )
return - V_171 ;
V_5 -> V_72 = V_185 ;
V_5 -> V_186 = F_72 ( F_73 ( V_3 ) ) ;
F_74 ( V_3 , V_182 ) ;
F_75 ( F_76 ( V_3 ) , & V_183 , V_187 ) ;
for(; ; ) {
F_58 ( V_3 ) ;
if ( V_5 -> V_72 == V_185 )
* V_181 = F_77 ( * V_181 ) ;
F_57 ( V_3 ) ;
V_184 = 0 ;
if ( V_5 -> V_72 == V_144 )
break;
V_184 = F_78 ( V_3 ) ;
if ( V_184 )
break;
V_184 = F_79 ( * V_181 ) ;
if ( F_80 ( V_188 ) )
break;
V_184 = - V_189 ;
if ( ! * V_181 )
break;
F_75 ( F_76 ( V_3 ) , & V_183 , V_187 ) ;
}
F_81 ( F_76 ( V_3 ) , & V_183 ) ;
if ( V_184 == 0 ) {
V_3 -> V_136 -> V_72 = V_190 ;
} else if ( V_5 -> V_72 != V_185 ) {
V_3 -> V_136 -> V_72 = V_139 ;
}
return V_184 ;
}
static int F_82 ( struct V_2 * V_3 , long * V_181 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_71 ( V_183 ) ;
int V_184 = 0 ;
if ( V_5 -> V_72 == V_144 )
goto V_21;
if ( ! * V_181 )
return - V_191 ;
F_75 ( F_76 ( V_3 ) , & V_183 , V_187 ) ;
for(; ; ) {
F_58 ( V_3 ) ;
if ( V_5 -> V_72 == V_149 || V_5 -> V_72 == V_185 )
* V_181 = F_77 ( * V_181 ) ;
F_57 ( V_3 ) ;
V_184 = 0 ;
if ( V_5 -> V_72 == V_144 )
break;
V_184 = F_78 ( V_3 ) ;
if ( V_184 )
break;
V_184 = F_79 ( * V_181 ) ;
if ( F_80 ( V_188 ) )
break;
V_184 = - V_192 ;
if ( ! * V_181 )
break;
F_75 ( F_76 ( V_3 ) , & V_183 , V_187 ) ;
}
F_81 ( F_76 ( V_3 ) , & V_183 ) ;
V_21:
if ( V_184 == 0 ) {
V_3 -> V_136 -> V_72 = V_190 ;
} else if ( V_5 -> V_72 != V_149 && V_5 -> V_72 != V_185 ) {
V_3 -> V_136 -> V_72 = V_139 ;
}
return V_184 ;
}
static int F_83 ( struct V_2 * V_3 , struct V_23 * V_6 , int V_193 , long * V_181 , int V_194 )
{
struct V_55 * V_2 = V_3 -> V_136 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_184 = - V_195 ;
struct V_196 V_197 ;
if ( V_2 -> V_72 == V_190 )
goto V_21;
if ( V_2 -> V_72 == V_198 ) {
V_184 = 0 ;
if ( V_5 -> V_72 == V_144 ) {
V_2 -> V_72 = V_190 ;
goto V_21;
}
V_184 = - V_199 ;
if ( V_5 -> V_72 != V_149 && V_5 -> V_72 != V_185 ) {
V_2 -> V_72 = V_139 ;
goto V_21;
}
return F_82 ( V_3 , V_181 ) ;
}
V_184 = - V_171 ;
if ( V_5 -> V_72 != V_73 )
goto V_21;
if ( V_6 == NULL || V_193 != sizeof( struct V_23 ) )
goto V_21;
if ( V_6 -> V_98 != V_99 )
goto V_21;
if ( V_6 -> V_7 & V_8 )
goto V_21;
if ( F_65 ( V_3 , V_177 ) ) {
V_184 = F_68 ( V_3 -> V_136 ) ;
if ( V_184 )
goto V_21;
}
memcpy ( & V_5 -> V_44 , V_6 , sizeof( struct V_23 ) ) ;
V_184 = - V_200 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_201 = V_3 -> V_202 ;
V_197 . V_203 = F_31 ( & V_5 -> V_44 ) ;
V_197 . V_167 = F_31 ( & V_5 -> V_6 ) ;
F_84 ( & V_197 , V_5 ) ;
V_197 . V_204 = V_158 ;
if ( F_85 ( & V_3 -> V_52 , & V_197 , V_3 , V_194 ) < 0 )
goto V_21;
V_3 -> V_205 = V_3 -> V_52 -> V_169 -> V_206 ;
V_2 -> V_72 = V_198 ;
V_5 -> V_72 = V_149 ;
V_5 -> V_186 = F_72 ( V_3 -> V_52 ) ;
F_86 ( V_3 , V_207 ) ;
V_184 = - V_208 ;
if ( * V_181 ) {
V_184 = F_82 ( V_3 , V_181 ) ;
}
V_21:
return V_184 ;
}
static int F_87 ( struct V_55 * V_2 , struct V_164 * V_165 , int V_193 , int V_194 )
{
struct V_23 * V_6 = (struct V_23 * ) V_165 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_184 ;
long V_181 = F_88 ( V_3 , V_194 & V_209 ) ;
F_57 ( V_3 ) ;
V_184 = F_83 ( V_3 , V_6 , V_193 , & V_181 , 0 ) ;
F_58 ( V_3 ) ;
return V_184 ;
}
static inline int F_89 ( struct V_2 * V_3 , struct V_23 * V_6 , int V_193 , long * V_181 , int V_194 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
switch ( V_5 -> V_72 ) {
case V_144 :
return 0 ;
case V_142 :
return F_70 ( V_3 , V_181 , V_3 -> V_67 ) ;
case V_149 :
case V_185 :
return F_82 ( V_3 , V_181 ) ;
case V_73 :
return F_83 ( V_3 , V_6 , V_193 , V_181 , V_194 ) ;
}
return - V_171 ;
}
static void F_90 ( struct V_39 * V_40 , struct V_210 * V_211 )
{
unsigned char * V_212 = V_40 -> V_32 ;
V_211 -> V_213 = * V_212 ++ ;
memcpy ( & V_211 -> V_214 , V_212 , V_211 -> V_213 ) ;
V_212 += V_211 -> V_213 ;
V_211 -> V_215 = * V_212 ++ ;
memcpy ( & V_211 -> V_216 , V_212 , V_211 -> V_215 ) ;
V_212 += V_211 -> V_215 ;
V_211 -> V_101 = * V_212 ++ ;
memcpy ( & V_211 -> V_102 , V_212 , V_211 -> V_101 ) ;
F_91 ( V_40 , V_211 -> V_101 + V_211 -> V_215 + V_211 -> V_213 + 3 ) ;
}
static void F_92 ( struct V_39 * V_40 , struct V_217 * V_218 )
{
unsigned char * V_212 = V_40 -> V_32 ;
T_4 V_31 = * V_212 ++ ;
F_10 ( V_31 > 16 ) ;
V_218 -> V_219 = F_8 ( V_31 ) ;
V_218 -> V_220 = 0 ;
memcpy ( V_218 -> V_221 , V_212 , V_31 ) ;
F_91 ( V_40 , V_31 + 1 ) ;
}
static struct V_39 * F_93 ( struct V_2 * V_3 , long * V_181 )
{
F_71 ( V_183 ) ;
struct V_39 * V_40 = NULL ;
int V_184 = 0 ;
F_75 ( F_76 ( V_3 ) , & V_183 , V_187 ) ;
for(; ; ) {
F_58 ( V_3 ) ;
V_40 = F_94 ( & V_3 -> V_222 ) ;
if ( V_40 == NULL ) {
* V_181 = F_77 ( * V_181 ) ;
V_40 = F_94 ( & V_3 -> V_222 ) ;
}
F_57 ( V_3 ) ;
if ( V_40 != NULL )
break;
V_184 = - V_171 ;
if ( V_3 -> V_37 != V_38 )
break;
V_184 = F_79 ( * V_181 ) ;
if ( F_80 ( V_188 ) )
break;
V_184 = - V_189 ;
if ( ! * V_181 )
break;
F_75 ( F_76 ( V_3 ) , & V_183 , V_187 ) ;
}
F_81 ( F_76 ( V_3 ) , & V_183 ) ;
return V_40 == NULL ? F_95 ( V_184 ) : V_40 ;
}
static int F_96 ( struct V_55 * V_2 , struct V_55 * V_223 , int V_194 )
{
struct V_2 * V_3 = V_2 -> V_3 , * V_224 ;
struct V_39 * V_40 = NULL ;
struct V_41 * V_42 ;
unsigned char V_225 ;
int V_184 = 0 ;
unsigned char type ;
long V_181 = F_97 ( V_3 , V_194 & V_209 ) ;
struct V_226 * V_227 ;
F_57 ( V_3 ) ;
if ( V_3 -> V_37 != V_38 || F_2 ( V_3 ) -> V_72 != V_73 ) {
F_58 ( V_3 ) ;
return - V_171 ;
}
V_40 = F_94 ( & V_3 -> V_222 ) ;
if ( V_40 == NULL ) {
V_40 = F_93 ( V_3 , & V_181 ) ;
if ( F_98 ( V_40 ) ) {
F_58 ( V_3 ) ;
return F_99 ( V_40 ) ;
}
}
V_42 = F_30 ( V_40 ) ;
V_3 -> V_228 -- ;
V_224 = F_37 ( F_100 ( V_3 ) , V_223 , V_3 -> V_67 ) ;
if ( V_224 == NULL ) {
F_58 ( V_3 ) ;
F_101 ( V_40 ) ;
return - V_163 ;
}
F_58 ( V_3 ) ;
V_227 = F_102 ( V_40 ) ;
F_103 ( V_224 , V_227 ) ;
F_104 ( V_40 , NULL ) ;
F_2 ( V_224 ) -> V_72 = V_142 ;
F_2 ( V_224 ) -> V_46 = V_42 -> V_47 ;
F_2 ( V_224 ) -> V_87 = V_42 -> V_229 ;
F_2 ( V_224 ) -> V_90 = V_42 -> V_230 ;
F_2 ( V_224 ) -> V_92 = V_42 -> V_231 ;
F_2 ( V_224 ) -> V_96 = F_2 ( V_3 ) -> V_96 ;
if ( F_2 ( V_224 ) -> V_92 < 230 )
F_2 ( V_224 ) -> V_92 = 230 ;
if ( ( F_2 ( V_224 ) -> V_87 & V_232 ) == V_89 )
F_2 ( V_224 ) -> V_103 = V_233 ;
V_224 -> V_37 = V_38 ;
memcpy ( & ( F_2 ( V_224 ) -> V_6 ) , & ( F_2 ( V_3 ) -> V_6 ) , sizeof( struct V_23 ) ) ;
F_2 ( V_224 ) -> V_6 . V_7 &= ~ V_8 ;
F_91 ( V_40 , F_23 ( V_40 -> V_32 , V_40 -> V_31 , & ( F_2 ( V_224 ) -> V_6 ) , & type ) ) ;
F_91 ( V_40 , F_23 ( V_40 -> V_32 , V_40 -> V_31 , & ( F_2 ( V_224 ) -> V_44 ) , & type ) ) ;
* ( T_1 * ) ( F_2 ( V_224 ) -> V_44 . V_178 . V_180 ) = V_42 -> V_43 ;
* ( T_1 * ) ( F_2 ( V_224 ) -> V_6 . V_178 . V_180 ) = V_42 -> V_227 ;
V_225 = * V_40 -> V_32 ;
F_91 ( V_40 , 1 ) ;
if ( V_225 & V_234 )
F_90 ( V_40 , & ( F_2 ( V_224 ) -> V_100 ) ) ;
if ( V_225 & V_235 )
F_92 ( V_40 , & ( F_2 ( V_224 ) -> V_236 ) ) ;
if ( V_225 & V_237 )
F_2 ( V_224 ) -> V_44 . V_7 |= V_238 ;
if ( V_225 & V_239 )
F_2 ( V_224 ) -> V_44 . V_7 |= V_240 ;
F_101 ( V_40 ) ;
memcpy ( & ( F_2 ( V_224 ) -> V_241 ) , & ( F_2 ( V_3 ) -> V_241 ) ,
sizeof( struct V_217 ) ) ;
memcpy ( & ( F_2 ( V_224 ) -> V_242 ) , & ( F_2 ( V_3 ) -> V_242 ) ,
sizeof( struct V_217 ) ) ;
F_57 ( V_224 ) ;
V_184 = F_9 ( V_224 ) ;
if ( V_184 == 0 ) {
F_66 ( V_224 , V_177 ) ;
F_105 ( V_224 ) ;
if ( F_2 ( V_224 ) -> V_96 == V_97 )
V_184 = F_70 ( V_224 , & V_181 ,
V_3 -> V_67 ) ;
}
F_58 ( V_224 ) ;
return V_184 ;
}
static int F_106 ( struct V_55 * V_2 , struct V_164 * V_165 , int * V_243 , int V_44 )
{
struct V_23 * V_244 = (struct V_23 * ) V_165 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
* V_243 = sizeof( struct V_23 ) ;
F_57 ( V_3 ) ;
if ( V_44 ) {
if ( ( V_2 -> V_72 != V_190 &&
V_2 -> V_72 != V_198 ) &&
V_5 -> V_96 == V_97 ) {
F_58 ( V_3 ) ;
return - V_245 ;
}
memcpy ( V_244 , & V_5 -> V_44 , sizeof( struct V_23 ) ) ;
} else {
memcpy ( V_244 , & V_5 -> V_6 , sizeof( struct V_23 ) ) ;
}
F_58 ( V_3 ) ;
return 0 ;
}
static unsigned int F_107 ( struct V_246 * V_246 , struct V_55 * V_2 , T_5 * V_183 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_247 = F_108 ( V_246 , V_2 , V_183 ) ;
if ( ! F_43 ( & V_5 -> V_51 ) )
V_247 |= V_248 ;
return V_247 ;
}
static int F_109 ( struct V_55 * V_2 , unsigned int V_249 , unsigned long V_250 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_184 = - V_251 ;
long V_252 = 0 ;
struct V_39 * V_40 ;
int V_253 ;
switch( V_249 )
{
case V_254 :
case V_255 :
return F_110 ( V_249 , ( void V_256 * ) V_250 ) ;
case V_257 :
F_57 ( V_3 ) ;
V_253 = ! F_43 ( & V_5 -> V_51 ) ;
if ( V_5 -> V_72 != V_144 )
V_253 = - V_245 ;
F_58 ( V_3 ) ;
return V_253 ;
case V_258 :
V_252 = V_3 -> V_68 - F_111 ( V_3 ) ;
if ( V_252 < 0 )
V_252 = 0 ;
V_184 = F_112 ( V_252 , ( int V_256 * ) V_250 ) ;
break;
case V_259 :
F_57 ( V_3 ) ;
V_40 = F_113 ( & V_5 -> V_51 ) ;
if ( V_40 ) {
V_252 = V_40 -> V_31 ;
} else {
F_114 (&sk->sk_receive_queue, skb)
V_252 += V_40 -> V_31 ;
}
F_58 ( V_3 ) ;
V_184 = F_112 ( V_252 , ( int V_256 * ) V_250 ) ;
break;
default:
V_184 = - V_260 ;
break;
}
return V_184 ;
}
static int F_115 ( struct V_55 * V_2 , int V_261 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_184 = - V_171 ;
F_57 ( V_3 ) ;
if ( F_65 ( V_3 , V_177 ) )
goto V_21;
if ( ( F_2 ( V_3 ) -> V_72 != V_73 ) || ( V_3 -> V_37 == V_38 ) )
goto V_21;
V_3 -> V_262 = V_261 ;
V_3 -> V_228 = 0 ;
V_3 -> V_37 = V_38 ;
V_184 = 0 ;
F_21 ( V_3 ) ;
V_21:
F_58 ( V_3 ) ;
return V_184 ;
}
static int F_116 ( struct V_55 * V_2 , int V_263 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_184 = - V_245 ;
F_57 ( V_3 ) ;
if ( V_2 -> V_72 == V_139 )
goto V_21;
V_184 = 0 ;
if ( V_2 -> V_72 == V_140 )
goto V_21;
V_184 = - V_171 ;
if ( V_5 -> V_72 == V_73 )
goto V_21;
if ( V_263 != V_264 )
goto V_21;
V_3 -> V_265 = V_263 ;
F_49 ( V_3 ) ;
V_184 = 0 ;
V_21:
F_58 ( V_3 ) ;
return V_184 ;
}
static int F_117 ( struct V_55 * V_2 , int V_266 , int V_267 , char V_256 * V_268 , unsigned int V_269 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_184 ;
F_57 ( V_3 ) ;
V_184 = F_118 ( V_2 , V_266 , V_267 , V_268 , V_269 , 0 ) ;
F_58 ( V_3 ) ;
return V_184 ;
}
static int F_118 ( struct V_55 * V_2 , int V_266 , int V_267 , char V_256 * V_268 , unsigned int V_269 , int V_194 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
long V_181 ;
union {
struct V_217 V_218 ;
struct V_210 V_211 ;
int V_270 ;
unsigned long V_271 ;
int V_253 ;
unsigned char V_229 ;
unsigned char V_230 ;
} V_272 ;
int V_184 ;
if ( V_269 && ! V_268 )
return - V_171 ;
if ( V_269 > sizeof( V_272 ) )
return - V_171 ;
if ( F_119 ( & V_272 , V_268 , V_269 ) )
return - V_273 ;
switch ( V_267 ) {
case V_274 :
if ( V_2 -> V_72 == V_190 )
return - V_195 ;
if ( ( V_5 -> V_72 != V_73 ) && ( V_5 -> V_72 != V_142 ) )
return - V_171 ;
if ( V_269 != sizeof( struct V_217 ) )
return - V_171 ;
if ( F_4 ( V_272 . V_218 . V_219 ) > 16 )
return - V_171 ;
memcpy ( & V_5 -> V_241 , & V_272 . V_218 , V_269 ) ;
break;
case V_275 :
if ( V_2 -> V_72 != V_190 &&
V_5 -> V_96 == V_97 )
return - V_245 ;
if ( V_269 != sizeof( struct V_217 ) )
return - V_171 ;
if ( F_4 ( V_272 . V_218 . V_219 ) > 16 )
return - V_171 ;
memcpy ( & V_5 -> V_242 , & V_272 . V_218 , V_269 ) ;
break;
case V_276 :
if ( V_2 -> V_72 == V_190 )
return - V_195 ;
if ( V_5 -> V_72 != V_73 )
return - V_171 ;
if ( V_269 != sizeof( struct V_210 ) )
return - V_171 ;
if ( ( V_272 . V_211 . V_101 > V_277 ) ||
( V_272 . V_211 . V_215 > V_277 ) ||
( V_272 . V_211 . V_213 > V_277 ) )
return - V_171 ;
memcpy ( & V_5 -> V_100 , & V_272 . V_211 , V_269 ) ;
break;
case V_278 :
if ( V_2 -> V_72 == V_190 )
return - V_195 ;
if ( V_5 -> V_72 != V_73 )
return - V_171 ;
if ( V_269 != sizeof( int ) )
return - V_171 ;
if ( ( V_272 . V_270 != V_97 ) && ( V_272 . V_270 != V_279 ) )
return - V_171 ;
V_5 -> V_96 = ( unsigned char ) V_272 . V_270 ;
break;
case V_280 :
if ( V_5 -> V_72 != V_142 )
return - V_171 ;
V_181 = F_97 ( V_3 , 0 ) ;
V_184 = F_70 ( V_3 , & V_181 , V_3 -> V_67 ) ;
return V_184 ;
case V_281 :
if ( V_5 -> V_72 != V_142 )
return - V_171 ;
V_5 -> V_72 = V_128 ;
V_3 -> V_265 = V_264 ;
F_47 ( V_3 , 0x38 , 0 , V_3 -> V_67 ) ;
break;
default:
#ifdef F_120
return F_121 ( V_3 , V_57 , V_267 , V_268 , V_269 ) ;
#endif
case V_282 :
case V_283 :
case V_284 :
return - V_285 ;
case V_286 :
if ( V_269 != sizeof( unsigned long ) )
return - V_171 ;
if ( V_272 . V_271 > V_104 )
V_272 . V_271 = V_104 ;
if ( V_272 . V_271 == 0 )
return - V_171 ;
V_5 -> V_103 = V_272 . V_271 ;
if ( V_5 -> V_105 > V_272 . V_271 )
V_5 -> V_105 = V_272 . V_271 ;
break;
case V_287 :
if ( V_269 != sizeof( int ) )
return - V_171 ;
if ( V_5 -> V_94 == 2 )
return - V_171 ;
V_5 -> V_94 = ( V_272 . V_253 == 0 ) ? 0 : 1 ;
break;
case V_288 :
if ( V_269 != sizeof( int ) )
return - V_171 ;
if ( V_5 -> V_94 == 1 )
return - V_171 ;
V_5 -> V_94 = ( V_272 . V_253 == 0 ) ? 0 : 2 ;
break;
case V_289 :
if ( V_269 != sizeof( unsigned char ) )
return - V_171 ;
if ( ( V_272 . V_229 & ~ V_232 ) != 0x01 )
return - V_171 ;
if ( ( V_272 . V_229 & V_232 ) == V_232 )
return - V_171 ;
V_5 -> V_88 = V_272 . V_229 ;
break;
case V_290 :
if ( V_269 != sizeof( unsigned char ) )
return - V_171 ;
if ( V_272 . V_230 & 0xfc )
return - V_171 ;
V_5 -> V_91 = V_272 . V_230 ;
break;
}
return 0 ;
}
static int F_122 ( struct V_55 * V_2 , int V_266 , int V_267 , char V_256 * V_268 , int V_256 * V_269 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_184 ;
F_57 ( V_3 ) ;
V_184 = F_123 ( V_2 , V_266 , V_267 , V_268 , V_269 , 0 ) ;
F_58 ( V_3 ) ;
return V_184 ;
}
static int F_123 ( struct V_55 * V_2 , int V_266 , int V_267 , char V_256 * V_268 , int V_256 * V_269 , int V_194 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_291 V_292 ;
unsigned int V_293 ;
void * V_294 = NULL ;
unsigned int V_253 ;
if( F_124 ( V_293 , V_269 ) )
return - V_273 ;
switch ( V_267 ) {
case V_274 :
if ( V_293 > sizeof( struct V_217 ) )
V_293 = sizeof( struct V_217 ) ;
V_294 = & V_5 -> V_236 ;
break;
case V_275 :
if ( V_293 > sizeof( struct V_217 ) )
V_293 = sizeof( struct V_217 ) ;
V_294 = & V_5 -> V_295 ;
break;
case V_276 :
if ( V_293 > sizeof( struct V_210 ) )
V_293 = sizeof( struct V_210 ) ;
V_294 = & V_5 -> V_100 ;
break;
case V_278 :
if ( V_293 > sizeof( unsigned char ) )
V_293 = sizeof( unsigned char ) ;
V_294 = & V_5 -> V_96 ;
break;
case V_282 :
if ( V_293 > sizeof( struct V_291 ) )
V_293 = sizeof( struct V_291 ) ;
memset ( & V_292 , 0 , sizeof( V_292 ) ) ;
switch ( V_2 -> V_72 ) {
case V_198 :
V_292 . V_296 = V_297 ;
break;
case V_140 :
V_292 . V_296 = V_298 ;
break;
case V_190 :
V_292 . V_296 = V_299 ;
break;
default:
V_292 . V_296 = V_300 ;
}
V_292 . V_301 = V_5 -> V_92 ;
V_294 = & V_292 ;
break;
default:
#ifdef F_120
{
int V_302 , V_31 ;
if ( F_124 ( V_31 , V_269 ) )
return - V_273 ;
V_302 = F_125 ( V_3 , V_57 , V_267 , V_268 , & V_31 ) ;
if ( V_302 >= 0 )
V_302 = F_112 ( V_31 , V_269 ) ;
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
V_294 = & V_5 -> V_103 ;
break;
case V_287 :
if ( V_293 > sizeof( int ) )
V_293 = sizeof( int ) ;
V_253 = ( V_5 -> V_94 == 1 ) ;
V_294 = & V_253 ;
break;
case V_288 :
if ( V_293 > sizeof( int ) )
V_293 = sizeof( int ) ;
V_253 = ( V_5 -> V_94 == 2 ) ;
V_294 = & V_253 ;
break;
case V_289 :
if ( V_293 > sizeof( unsigned char ) )
V_293 = sizeof( unsigned char ) ;
V_294 = & V_5 -> V_87 ;
break;
case V_290 :
if ( V_293 > sizeof( unsigned char ) )
V_293 = sizeof( unsigned char ) ;
V_294 = & V_5 -> V_90 ;
break;
}
if ( V_294 ) {
if ( F_126 ( V_268 , V_294 , V_293 ) )
return - V_273 ;
if ( F_112 ( V_293 , V_269 ) )
return - V_273 ;
}
return 0 ;
}
static int F_127 ( struct V_2 * V_3 , struct V_303 * V_304 , int V_194 , int V_305 )
{
struct V_39 * V_40 ;
int V_31 = 0 ;
if ( V_194 & V_306 )
return ! F_43 ( V_304 ) ? 1 : 0 ;
F_114 (q, skb) {
struct V_41 * V_42 = F_30 ( V_40 ) ;
V_31 += V_40 -> V_31 ;
if ( V_42 -> V_307 & 0x40 ) {
if ( V_3 -> V_308 == V_157 )
return 1 ;
if ( ! ( V_194 & V_309 ) )
return 1 ;
}
if ( V_31 >= V_305 )
return 1 ;
}
return 0 ;
}
static int F_128 ( struct V_310 * V_311 , struct V_55 * V_2 ,
struct V_312 * V_313 , T_6 V_34 , int V_194 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_303 * V_314 = & V_3 -> V_222 ;
T_6 V_305 = V_34 > 1 ? 1 : 0 ;
T_6 V_315 = 0 ;
int V_18 = 0 ;
struct V_39 * V_40 , * V_316 ;
struct V_41 * V_42 = NULL ;
unsigned char V_317 = 0 ;
long V_181 = F_97 ( V_3 , V_194 & V_318 ) ;
F_57 ( V_3 ) ;
if ( F_65 ( V_3 , V_177 ) ) {
V_18 = - V_176 ;
goto V_21;
}
if ( V_3 -> V_265 & V_319 ) {
V_18 = 0 ;
goto V_21;
}
V_18 = F_89 ( V_3 , NULL , 0 , & V_181 , V_194 ) ;
if ( V_18 )
goto V_21;
if ( V_194 & ~ ( V_320 | V_321 | V_306 | V_309 | V_318 | V_322 ) ) {
V_18 = - V_251 ;
goto V_21;
}
if ( V_194 & V_306 )
V_314 = & V_5 -> V_51 ;
if ( V_194 & V_309 )
V_305 = V_34 ;
for(; ; ) {
F_71 ( V_183 ) ;
if ( V_3 -> V_323 )
goto V_21;
if ( ! F_43 ( & V_5 -> V_51 ) ) {
if ( ! ( V_194 & V_306 ) ) {
V_313 -> V_324 |= V_306 ;
if ( ! V_5 -> V_325 ) {
V_5 -> V_325 = 1 ;
goto V_21;
}
}
}
if ( V_5 -> V_72 != V_144 )
goto V_21;
if ( F_80 ( V_188 ) ) {
V_18 = F_79 ( V_181 ) ;
goto V_21;
}
if ( F_127 ( V_3 , V_314 , V_194 , V_305 ) )
break;
if ( V_194 & V_318 ) {
V_18 = - V_326 ;
goto V_21;
}
F_75 ( F_76 ( V_3 ) , & V_183 , V_187 ) ;
F_129 ( V_327 , & V_3 -> V_136 -> V_194 ) ;
F_130 ( V_3 , & V_181 , F_127 ( V_3 , V_314 , V_194 , V_305 ) ) ;
F_131 ( V_327 , & V_3 -> V_136 -> V_194 ) ;
F_81 ( F_76 ( V_3 ) , & V_183 ) ;
}
F_132 (queue, skb, n) {
unsigned int V_328 = V_40 -> V_31 ;
V_42 = F_30 ( V_40 ) ;
if ( ( V_328 + V_315 ) > V_34 )
V_328 = V_34 - V_315 ;
if ( F_133 ( V_313 -> V_329 , V_40 -> V_32 , V_328 ) ) {
V_18 = - V_273 ;
break;
}
V_315 += V_328 ;
if ( ! ( V_194 & V_321 ) )
F_91 ( V_40 , V_328 ) ;
V_317 = V_42 -> V_307 & 0x40 ;
if ( V_40 -> V_31 == 0 ) {
F_134 ( V_40 , V_314 ) ;
F_101 ( V_40 ) ;
if ( ( V_5 -> V_82 == V_330 ) && ! F_135 ( V_3 ) ) {
V_5 -> V_82 = V_81 ;
F_44 ( V_3 , V_81 , 0 ) ;
}
}
if ( V_317 ) {
if ( V_3 -> V_308 == V_157 )
break;
if ( ! ( V_194 & V_309 ) )
break;
}
if ( V_194 & V_306 )
break;
if ( V_315 >= V_305 )
break;
}
V_18 = V_315 ;
if ( V_317 && ( V_3 -> V_308 == V_157 ) )
V_313 -> V_324 |= V_331 ;
V_21:
if ( V_18 == 0 )
V_18 = ( V_194 & V_321 ) ? - V_3 -> V_323 : F_78 ( V_3 ) ;
if ( ( V_18 >= 0 ) && V_313 -> V_332 ) {
memcpy ( V_313 -> V_332 , & V_5 -> V_44 , sizeof( struct V_23 ) ) ;
V_313 -> V_333 = sizeof( struct V_23 ) ;
}
F_58 ( V_3 ) ;
return V_18 ;
}
static inline int F_136 ( struct V_4 * V_5 , struct V_303 * V_314 , int V_194 )
{
unsigned char V_334 = V_5 -> V_87 & V_232 ;
if ( F_137 ( V_314 ) >= V_5 -> V_105 )
return 1 ;
if ( V_334 != V_89 ) {
if ( V_194 & V_306 ) {
if ( V_5 -> V_84 == 0 )
return 1 ;
} else {
if ( V_5 -> V_83 == 0 )
return 1 ;
}
}
return 0 ;
}
unsigned F_138 ( struct V_168 * V_169 , int V_335 )
{
unsigned V_336 = 230 - V_93 ;
if ( V_169 ) {
struct V_337 * V_338 = F_139 ( V_169 -> V_175 ) ;
V_335 -= F_140 ( V_169 ) ;
if ( V_338 -> V_339 )
V_335 -= 21 ;
else
V_335 -= 6 ;
V_335 -= V_93 ;
} else {
V_335 -= ( 21 + V_93 + 16 ) ;
}
if ( V_335 > V_336 )
V_336 = V_335 ;
return V_336 ;
}
static inline unsigned int F_141 ( struct V_2 * V_3 , int V_194 )
{
struct V_226 * V_227 = F_73 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_340 = F_142 ( int , V_5 -> V_186 , V_5 -> V_92 ) ;
if ( V_194 & V_306 )
return 16 ;
if ( V_227 ) {
T_7 V_335 = F_143 ( V_227 ) ;
V_340 = F_142 ( int , F_138 ( V_227 -> V_169 , V_335 ) , V_340 ) ;
}
return V_340 ;
}
static inline struct V_39 * F_144 ( struct V_2 * V_3 ,
unsigned long V_341 , int V_342 ,
int * V_343 )
{
struct V_39 * V_40 = F_145 ( V_3 , V_341 ,
V_342 , V_343 ) ;
if ( V_40 ) {
V_40 -> V_153 = F_146 ( V_344 ) ;
V_40 -> V_345 = V_346 ;
}
return V_40 ;
}
static int F_147 ( struct V_310 * V_311 , struct V_55 * V_2 ,
struct V_312 * V_313 , T_6 V_34 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_6 V_336 ;
struct V_303 * V_314 = & V_5 -> V_49 ;
int V_194 = V_313 -> V_324 ;
int V_184 = 0 ;
T_6 V_347 = 0 ;
int V_166 = V_313 -> V_333 ;
struct V_23 * V_6 = (struct V_23 * ) V_313 -> V_332 ;
struct V_39 * V_40 = NULL ;
struct V_41 * V_42 ;
T_6 V_31 ;
unsigned char V_334 ;
long V_181 ;
if ( V_194 & ~ ( V_348 | V_306 | V_318 | V_331 | V_322 | V_349 | V_320 ) )
return - V_251 ;
if ( V_166 && ( V_166 != sizeof( struct V_23 ) ) )
return - V_171 ;
F_57 ( V_3 ) ;
V_181 = F_88 ( V_3 , V_194 & V_318 ) ;
if ( V_2 -> type == V_160 ) {
if ( V_194 & V_331 ) {
V_184 = - V_171 ;
goto V_21;
}
V_194 |= V_331 ;
}
V_184 = F_89 ( V_3 , V_6 , V_166 , & V_181 , V_194 ) ;
if ( V_184 )
goto V_350;
if ( V_3 -> V_265 & V_351 ) {
V_184 = - V_352 ;
if ( ! ( V_194 & V_322 ) )
F_148 ( V_353 , V_188 , 0 ) ;
goto V_350;
}
if ( ( V_194 & V_348 ) && V_3 -> V_52 )
F_149 ( V_3 ) ;
V_336 = V_5 -> V_92 ;
V_334 = V_5 -> V_87 & V_232 ;
V_336 = F_141 ( V_3 , V_194 ) ;
if ( V_194 & V_306 ) {
V_314 = & V_5 -> V_50 ;
if ( V_34 > V_336 ) {
V_184 = - V_354 ;
goto V_21;
}
}
V_5 -> V_113 = V_355 ;
while( V_347 < V_34 ) {
V_184 = F_78 ( V_3 ) ;
if ( V_184 )
goto V_21;
if ( F_80 ( V_188 ) ) {
V_184 = F_79 ( V_181 ) ;
goto V_21;
}
V_31 = V_34 - V_347 ;
if ( V_31 > V_336 )
V_31 = V_336 ;
if ( F_136 ( V_5 , V_314 , V_194 ) ) {
F_71 ( V_183 ) ;
if ( V_194 & V_318 ) {
V_184 = - V_326 ;
goto V_21;
}
F_75 ( F_76 ( V_3 ) , & V_183 , V_187 ) ;
F_129 ( V_327 , & V_3 -> V_136 -> V_194 ) ;
F_130 ( V_3 , & V_181 ,
! F_136 ( V_5 , V_314 , V_194 ) ) ;
F_131 ( V_327 , & V_3 -> V_136 -> V_194 ) ;
F_81 ( F_76 ( V_3 ) , & V_183 ) ;
continue;
}
V_40 = F_144 ( V_3 , V_31 + 64 + V_93 ,
V_194 & V_318 , & V_184 ) ;
if ( V_184 )
break;
if ( ! V_40 )
continue;
V_42 = F_30 ( V_40 ) ;
F_150 ( V_40 , 64 + V_93 ) ;
if ( F_151 ( F_152 ( V_40 , V_31 ) , V_313 -> V_329 , V_31 ) ) {
V_184 = - V_273 ;
goto V_21;
}
if ( V_194 & V_306 ) {
V_42 -> V_307 = 0x30 ;
if ( V_334 != V_89 )
V_5 -> V_84 -- ;
} else {
V_42 -> V_307 = 0x00 ;
if ( V_5 -> V_356 == 0 )
V_42 -> V_307 |= 0x20 ;
V_5 -> V_356 += V_31 ;
if ( ( ( V_347 + V_31 ) == V_34 ) && ( V_194 & V_331 ) ) {
V_42 -> V_307 |= 0x40 ;
V_5 -> V_356 = 0 ;
if ( V_334 == V_357 )
V_5 -> V_83 -- ;
}
if ( V_334 == V_358 )
V_5 -> V_83 -- ;
}
V_347 += V_31 ;
F_153 ( V_3 , V_40 , V_3 -> V_67 , V_194 & V_306 ) ;
V_40 = NULL ;
V_5 -> V_112 = F_46 ( V_3 ) ;
}
V_21:
F_101 ( V_40 ) ;
F_58 ( V_3 ) ;
return V_347 ? V_347 : V_184 ;
V_350:
V_184 = F_154 ( V_3 , V_194 , V_184 ) ;
F_58 ( V_3 ) ;
return V_184 ;
}
static int F_155 ( struct V_359 * V_360 , unsigned long V_361 ,
void * V_212 )
{
struct V_168 * V_169 = (struct V_168 * ) V_212 ;
if ( ! F_54 ( F_156 ( V_169 ) , & V_155 ) )
return V_362 ;
switch ( V_361 ) {
case V_363 :
F_157 ( V_169 ) ;
break;
case V_364 :
F_158 ( V_169 ) ;
break;
default:
break;
}
return V_362 ;
}
static struct V_2 * F_159 ( struct V_365 * V_366 )
{
struct V_367 * V_72 = V_366 -> V_368 ;
struct V_2 * V_316 = NULL ;
for( V_72 -> V_369 = 0 ;
V_72 -> V_369 < V_370 ;
++ V_72 -> V_369 ) {
V_316 = F_28 ( & V_10 [ V_72 -> V_369 ] ) ;
if ( V_316 )
break;
}
return V_316 ;
}
static struct V_2 * F_160 ( struct V_365 * V_366 ,
struct V_2 * V_316 )
{
struct V_367 * V_72 = V_366 -> V_368 ;
V_316 = F_161 ( V_316 ) ;
V_371:
if ( V_316 )
goto V_21;
if ( ++ V_72 -> V_369 >= V_370 )
goto V_21;
V_316 = F_28 ( & V_10 [ V_72 -> V_369 ] ) ;
goto V_371;
V_21:
return V_316 ;
}
static struct V_2 * F_162 ( struct V_365 * V_366 , T_8 * V_372 )
{
struct V_2 * V_3 = F_159 ( V_366 ) ;
if ( V_3 ) {
while( * V_372 && ( V_3 = F_160 ( V_366 , V_3 ) ) )
-- * V_372 ;
}
return * V_372 ? NULL : V_3 ;
}
static void * F_163 ( struct V_365 * V_366 , T_8 V_372 )
{
void * V_373 ;
F_164 ( & V_20 ) ;
V_373 = F_162 ( V_366 , & V_372 ) ;
if ( ! V_373 ) {
F_165 ( & V_20 ) ;
}
return V_373 ;
}
static void * F_166 ( struct V_365 * V_366 , T_8 * V_372 )
{
return * V_372 ? F_163 ( V_366 , * V_372 - 1 ) : V_374 ;
}
static void * F_167 ( struct V_365 * V_366 , void * V_375 , T_8 * V_372 )
{
void * V_373 ;
if ( V_375 == V_374 ) {
V_373 = F_163 ( V_366 , 0 ) ;
goto V_21;
}
V_373 = F_160 ( V_366 , V_375 ) ;
if ( V_373 )
goto V_21;
F_165 ( & V_20 ) ;
V_21:
++ * V_372 ;
return V_373 ;
}
static void F_168 ( struct V_365 * V_366 , void * V_375 )
{
if ( V_375 && V_375 != V_374 )
F_165 ( & V_20 ) ;
}
static void F_169 ( struct V_23 * V_376 , unsigned char * V_30 )
{
int V_24 ;
switch ( F_4 ( V_376 -> V_27 ) ) {
case 0 :
sprintf ( V_30 , L_4 , V_376 -> V_26 ) ;
break;
default:
for ( V_24 = 0 ; V_24 < F_4 ( V_376 -> V_27 ) ; V_24 ++ ) {
V_30 [ V_24 ] = V_376 -> V_28 [ V_24 ] ;
if ( F_170 ( V_30 [ V_24 ] ) )
V_30 [ V_24 ] = '.' ;
}
V_30 [ V_24 ] = 0 ;
}
}
static char * F_171 ( unsigned char V_72 )
{
switch ( V_72 ) {
case V_73 :
return L_5 ;
case V_142 :
return L_6 ;
case V_128 :
return L_7 ;
case V_130 :
return L_8 ;
case V_185 :
return L_9 ;
case V_149 :
return L_10 ;
case V_146 :
return L_11 ;
case V_145 :
return L_12 ;
case V_150 :
return L_13 ;
case V_147 :
return L_14 ;
case V_144 :
return L_15 ;
case V_123 :
return L_16 ;
case V_148 :
return L_17 ;
case V_131 :
return L_18 ;
case V_377 :
return L_19 ;
case V_127 :
return L_20 ;
}
return L_21 ;
}
static inline void F_172 ( struct V_365 * V_366 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
char V_378 [ V_379 ] ;
char V_380 [ V_379 ] ;
char V_381 [ V_36 + 3 ] ;
char V_382 [ V_36 + 3 ] ;
F_169 ( & V_5 -> V_6 , V_381 ) ;
F_169 ( & V_5 -> V_44 , V_382 ) ;
F_173 ( V_366 ,
L_22
L_23 ,
F_52 ( F_4 ( F_31 ( & V_5 -> V_6 ) ) , V_378 ) ,
V_5 -> V_11 ,
V_5 -> V_74 ,
V_5 -> V_75 ,
V_5 -> V_76 ,
V_5 -> V_77 ,
V_5 -> V_82 ,
V_381 ,
F_52 ( F_4 ( F_31 ( & V_5 -> V_44 ) ) , V_380 ) ,
V_5 -> V_46 ,
V_5 -> V_383 ,
V_5 -> V_384 ,
V_5 -> V_78 ,
V_5 -> V_79 ,
V_5 -> V_80 ,
V_382 ,
F_171 ( V_5 -> V_72 ) ,
( ( V_5 -> V_96 == V_97 ) ? L_24 : L_25 ) ) ;
}
static int F_174 ( struct V_365 * V_366 , void * V_375 )
{
if ( V_375 == V_374 ) {
F_175 ( V_366 , L_26 ) ;
} else {
F_172 ( V_366 , V_375 ) ;
}
return 0 ;
}
static int F_176 ( struct V_385 * V_385 , struct V_246 * V_246 )
{
return F_177 ( V_246 , & V_386 ,
sizeof( struct V_367 ) ) ;
}
static int T_9 F_178 ( void )
{
int V_373 ;
F_50 ( V_387 ) ;
V_373 = F_179 ( & V_58 , 1 ) ;
if ( V_373 != 0 )
goto V_21;
F_180 () ;
F_181 () ;
F_182 () ;
F_183 () ;
F_184 ( & V_388 ) ;
F_185 ( & V_389 ) ;
F_186 ( & V_390 ) ;
F_187 ( & V_155 , L_27 , V_391 , & V_392 ) ;
F_188 () ;
V_21:
return V_373 ;
}
