static void F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 , * V_11 ;
struct V_12 * V_13 ;
unsigned long V_14 ;
T_2 V_15 ;
T_1 V_16 ;
F_2 ( V_2 -> V_17 -> V_18 , L_1 , V_19 , V_3 ) ;
F_3 ( & V_2 -> V_20 . V_21 , V_14 ) ;
F_4 (&priv->tdls_txq, skb, tmp) {
if ( ! F_5 ( V_3 , V_10 -> V_22 ) )
continue;
F_6 ( V_10 , & V_2 -> V_23 ) ;
V_13 = F_7 ( V_10 ) ;
V_15 = V_10 -> V_24 ;
V_16 = F_8 ( V_2 , V_15 ) ;
if ( V_4 == V_25 ) {
V_6 = F_9 ( V_2 , V_15 , V_3 ) ;
V_6 -> V_26 = true ;
V_13 -> V_14 |= V_27 ;
} else {
V_8 = & V_2 -> V_20 . V_28 [ V_16 ] . V_6 ;
if ( ! F_10 ( V_8 ) )
V_6 = F_11 ( V_8 ,
struct V_5 , V_29 ) ;
else
V_6 = NULL ;
V_13 -> V_14 &= ~ V_27 ;
}
if ( ! V_6 ) {
F_12 ( V_2 -> V_17 , V_10 , 0 , - 1 ) ;
continue;
}
F_13 ( & V_6 -> V_30 , V_10 ) ;
V_6 -> V_31 ++ ;
V_6 -> V_32 ++ ;
if ( F_14 ( & V_2 -> V_20 . V_33 ) <
V_34 [ V_16 ] )
F_15 ( & V_2 -> V_20 . V_33 ,
V_34 [ V_16 ] ) ;
F_16 ( & V_2 -> V_20 . V_35 ) ;
}
F_17 ( & V_2 -> V_20 . V_21 , V_14 ) ;
return;
}
static void F_18 ( struct V_1 * V_2 ,
const T_1 * V_3 )
{
struct V_5 * V_6 ;
struct V_7 * V_36 ;
struct V_9 * V_10 , * V_11 ;
unsigned long V_14 ;
int V_37 ;
F_2 ( V_2 -> V_17 -> V_18 , L_1 , V_19 , V_3 ) ;
F_3 ( & V_2 -> V_20 . V_21 , V_14 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
if ( ! F_10 ( & V_2 -> V_20 . V_28 [ V_37 ] . V_6 ) ) {
V_36 = & V_2 -> V_20 . V_28 [ V_37 ] . V_6 ;
F_19 (ra_list, ra_list_head, list) {
F_4 (&ra_list->skb_head, skb,
tmp) {
if ( ! F_5 ( V_3 , V_10 -> V_22 ) )
continue;
F_6 ( V_10 , & V_6 -> V_30 ) ;
F_20 ( & V_2 -> V_20 . V_35 ) ;
V_6 -> V_32 -- ;
F_13 ( & V_2 -> V_23 , V_10 ) ;
}
}
}
}
F_17 ( & V_2 -> V_20 . V_21 , V_14 ) ;
return;
}
static int
F_21 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_39 [ V_40 ] , * V_41 ;
T_3 V_42 , V_43 , V_44 ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
V_42 = F_22 ( V_2 , V_39 ) ;
V_43 = F_23 ( T_3 , V_42 , V_45 ) ;
if ( F_24 ( V_10 ) < V_42 + 4 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_2 ) ;
return - V_46 ;
}
V_41 = F_26 ( V_10 , V_43 + 2 ) ;
* V_41 ++ = V_47 ;
* V_41 ++ = V_43 ;
memcpy ( V_41 , V_39 , V_43 ) ;
if ( V_42 > V_45 ) {
V_44 = V_42 - V_45 ;
V_41 = F_26 ( V_10 , V_44 + 2 ) ;
* V_41 ++ = V_48 ;
* V_41 ++ = V_44 ;
memcpy ( V_41 , V_39 + V_45 ,
V_44 ) ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_49 * V_50 ;
T_1 * V_41 ;
V_50 = (struct V_49 * ) & V_2 -> V_51 ;
V_41 = ( void * ) F_26 ( V_10 , 4 ) ;
* V_41 ++ = V_52 ;
* V_41 ++ = 2 ;
* V_41 ++ = F_28 ( V_50 -> V_53 ) ;
return;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_54 V_55 ;
T_1 * V_41 ;
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_54 ) + 2 ) ;
* V_41 ++ = V_56 ;
* V_41 ++ = sizeof( struct V_54 ) ;
memset ( & V_55 , 0 , sizeof( struct V_54 ) ) ;
F_30 ( V_2 , & V_55 , V_2 -> V_57 . V_58 ) ;
memcpy ( V_41 , & V_55 , sizeof( V_55 ) ) ;
return 0 ;
}
static int
F_31 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_1 V_59 , struct V_9 * V_10 )
{
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 =
& V_2 -> V_57 . V_66 ;
T_1 * V_41 ;
V_63 = F_32 ( V_2 , V_3 ) ;
if ( F_33 ( ! V_63 ) ) {
F_34 ( V_2 -> V_17 -> V_18 ,
L_3 ) ;
return - 1 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_60 ) + 2 ) ;
* V_41 ++ = V_67 ;
* V_41 ++ = sizeof( struct V_60 ) ;
V_61 = ( void * ) V_41 ;
V_61 -> V_68 = V_65 -> V_69 ;
if ( F_35 ( V_2 -> V_17 -> V_70 ) &&
V_65 -> V_71 &&
F_36 ( V_65 -> V_72 -> V_73 ) )
V_61 -> V_73 = V_65 -> V_72 -> V_73 ;
if ( V_59 ) {
V_61 -> V_73 =
F_37 ( V_65 -> V_69 ) ;
V_61 -> V_73 |= F_38 ( 2 ) ;
}
memcpy ( & V_63 -> V_74 . V_61 , V_61 ,
sizeof( struct V_60 ) ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
const T_1 * V_3 , struct V_9 * V_10 )
{
struct V_64 * V_65 ;
struct V_75 * V_76 ;
struct V_54 * V_55 , * V_77 = NULL ;
struct V_62 * V_63 ;
struct V_78 * V_17 = V_2 -> V_17 ;
T_1 V_79 , V_80 ;
T_1 * V_41 , V_81 , V_82 ;
T_3 V_83 , V_84 , V_85 ;
T_3 V_86 , V_87 , V_88 ;
T_2 V_89 ;
V_65 = & V_2 -> V_57 . V_66 ;
V_63 = F_32 ( V_2 , V_3 ) ;
if ( F_33 ( ! V_63 ) ) {
F_34 ( V_17 -> V_18 , L_3 ) ;
return - 1 ;
}
if ( ! F_40 ( V_2 ) ) {
if ( V_63 -> V_74 . V_90 . V_91 [ 7 ] &
V_92 ) {
F_2 ( V_17 -> V_18 ,
L_4 ) ;
return 0 ;
}
} else {
V_77 = V_65 -> V_93 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_75 ) + 2 ) ;
* V_41 ++ = V_94 ;
* V_41 ++ = sizeof( struct V_75 ) ;
V_76 = (struct V_75 * ) V_41 ;
if ( V_65 -> V_95 & V_96 )
V_89 = V_17 -> V_97 ;
else
V_89 = V_17 -> V_98 ;
V_55 = & V_63 -> V_74 . V_99 ;
V_79 = F_41 ( V_89 ) ;
V_80 =
F_41 ( F_42 ( V_55 -> V_100 ) ) ;
V_79 = F_23 ( T_1 , V_79 , V_80 ) ;
if ( V_77 && V_63 -> V_74 . V_90 . V_91 [ 7 ] &
V_92 ) {
V_81 =
F_41 ( F_42 ( V_77 -> V_100 ) ) ;
V_79 = F_23 ( T_1 , V_79 , V_81 ) ;
}
switch ( V_79 ) {
case V_101 :
V_76 -> V_102 = V_101 ;
break;
case V_103 :
V_76 -> V_102 = V_103 ;
break;
case V_104 :
V_76 -> V_102 = V_104 ;
break;
default:
V_76 -> V_102 = V_105 ;
break;
}
V_83 = F_43 ( V_17 -> V_106 ) ;
V_84 = F_28 ( V_55 -> V_107 . V_108 ) ;
V_85 = 0 ;
for ( V_88 = 1 ; V_88 <= 8 ; V_88 ++ ) {
V_86 = F_44 ( V_83 , V_88 ) ;
V_87 = F_44 ( V_84 , V_88 ) ;
if ( ( V_86 == V_109 ) ||
( V_87 == V_109 ) )
F_45 ( V_85 , V_88 ,
V_109 ) ;
else
F_45 ( V_85 , V_88 ,
F_23 ( T_3 , V_86 , V_87 ) ) ;
}
V_76 -> V_110 = F_46 ( V_85 ) ;
switch ( V_76 -> V_102 ) {
case V_101 :
V_82 = V_101 ;
break;
case V_103 :
V_82 = V_103 ;
break;
case V_104 :
V_82 = V_101 ;
break;
default:
V_82 = V_105 ;
break;
}
V_76 -> V_111 =
F_47 ( V_2 , V_112 ,
V_65 -> V_69 ,
V_82 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_113 * V_90 ;
V_90 = ( void * ) F_26 ( V_10 , sizeof( struct V_113 ) ) ;
V_90 -> V_114 . V_115 = V_116 ;
V_90 -> V_114 . V_117 = 8 ;
memset ( V_90 -> V_91 , 0 , 8 ) ;
V_90 -> V_91 [ 4 ] |= V_118 ;
if ( V_2 -> V_17 -> V_119 )
V_90 -> V_91 [ 7 ] |= V_92 ;
}
static void F_49 ( struct V_9 * V_10 )
{
T_1 * V_41 = ( void * ) F_26 ( V_10 , 3 ) ;
* V_41 ++ = V_120 ;
* V_41 ++ = 1 ;
* V_41 ++ = V_121 ;
}
static void
F_50 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_122 * V_20 ;
T_1 V_123 [] = { 0x42 , 0x43 , 0x5e , 0x00 } ;
T_1 V_124 [] = { 0x62 , 0x32 , 0x2f , 0x00 } ;
T_1 V_125 [] = { 0x03 , 0xa4 , 0x00 , 0x00 } ;
T_1 V_126 [] = { 0x27 , 0xa4 , 0x00 , 0x00 } ;
V_20 = ( void * ) F_26 ( V_10 , sizeof( * V_20 ) ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_115 = V_127 ;
V_20 -> V_117 = sizeof( * V_20 ) - 2 ;
V_20 -> V_128 [ 0 ] = 0x00 ;
V_20 -> V_128 [ 1 ] = 0x50 ;
V_20 -> V_128 [ 2 ] = 0xf2 ;
V_20 -> V_129 = 2 ;
V_20 -> V_130 = 1 ;
V_20 -> V_131 = 1 ;
V_20 -> V_132 = 0 ;
memcpy ( & V_20 -> V_133 [ 0 ] , V_125 , sizeof( V_125 ) ) ;
memcpy ( & V_20 -> V_133 [ 1 ] , V_126 , sizeof( V_126 ) ) ;
memcpy ( & V_20 -> V_133 [ 2 ] , V_123 , sizeof( V_123 ) ) ;
memcpy ( & V_20 -> V_133 [ 3 ] , V_124 , sizeof( V_124 ) ) ;
}
static void
F_51 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_1 V_134 )
{
T_1 * V_135 ;
V_135 = ( void * ) F_26 ( V_10 , V_136 +
sizeof( struct V_137 ) ) ;
* V_135 ++ = V_127 ;
* V_135 ++ = 7 ;
* V_135 ++ = 0x00 ;
* V_135 ++ = 0x50 ;
* V_135 ++ = 0xf2 ;
* V_135 ++ = 2 ;
* V_135 ++ = 0 ;
* V_135 ++ = 1 ;
* V_135 ++ = V_134 ;
}
static int F_52 ( struct V_1 * V_2 ,
const T_1 * V_138 , T_1 V_139 ,
T_1 V_140 ,
T_3 V_141 , struct V_9 * V_10 )
{
struct V_142 * V_143 ;
int V_144 ;
T_3 V_145 ;
struct V_146 * V_147 ;
T_1 V_148 , * V_41 ;
V_145 = V_2 -> V_57 . V_66 . V_149 ;
V_143 = ( void * ) F_26 ( V_10 , F_53 ( struct V_142 , V_150 ) ) ;
memcpy ( V_143 -> V_151 , V_138 , V_152 ) ;
memcpy ( V_143 -> V_153 , V_2 -> V_154 , V_152 ) ;
V_143 -> V_155 = F_54 ( V_156 ) ;
V_143 -> V_157 = V_158 ;
switch ( V_139 ) {
case V_159 :
V_143 -> V_160 = V_161 ;
V_143 -> V_139 = V_159 ;
F_26 ( V_10 , sizeof( V_143 -> V_150 . V_162 ) ) ;
V_143 -> V_150 . V_162 . V_140 = V_140 ;
V_143 -> V_150 . V_162 . V_163 = F_46 ( V_145 ) ;
V_144 = F_21 ( V_2 , V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_146 ) + 2 ) ;
* V_41 ++ = V_164 ;
* V_41 ++ = sizeof( struct V_146 ) ;
V_147 = ( void * ) V_41 ;
V_148 = F_56 ( V_2 -> V_57 . V_58 ) ;
V_144 = F_57 ( V_2 , V_148 , V_147 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
if ( V_2 -> V_17 -> V_119 ) {
V_144 = F_29 ( V_2 , V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_48 ( V_2 , V_10 ) ;
F_49 ( V_10 ) ;
F_51 ( V_2 , V_10 , 0 ) ;
break;
case V_165 :
V_143 -> V_160 = V_161 ;
V_143 -> V_139 = V_165 ;
F_26 ( V_10 , sizeof( V_143 -> V_150 . V_166 ) ) ;
V_143 -> V_150 . V_166 . V_141 = F_46 ( V_141 ) ;
V_143 -> V_150 . V_166 . V_140 = V_140 ;
V_143 -> V_150 . V_166 . V_163 = F_46 ( V_145 ) ;
V_144 = F_21 ( V_2 , V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_146 ) + 2 ) ;
* V_41 ++ = V_164 ;
* V_41 ++ = sizeof( struct V_146 ) ;
V_147 = ( void * ) V_41 ;
V_148 = F_56 ( V_2 -> V_57 . V_58 ) ;
V_144 = F_57 ( V_2 , V_148 , V_147 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
if ( V_2 -> V_17 -> V_119 ) {
V_144 = F_29 ( V_2 , V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_48 ( V_2 , V_10 ) ;
F_49 ( V_10 ) ;
F_51 ( V_2 , V_10 , 0 ) ;
break;
case V_167 :
V_143 -> V_160 = V_161 ;
V_143 -> V_139 = V_167 ;
F_26 ( V_10 , sizeof( V_143 -> V_150 . V_168 ) ) ;
V_143 -> V_150 . V_168 . V_141 = F_46 ( V_141 ) ;
V_143 -> V_150 . V_168 . V_140 = V_140 ;
F_50 ( V_2 , V_10 ) ;
if ( V_2 -> V_17 -> V_119 ) {
V_144 = F_39 ( V_2 , V_138 , V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
V_144 = F_31 ( V_2 , V_138 , 1 , V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
} else {
V_144 = F_31 ( V_2 , V_138 , 0 , V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
}
break;
case V_169 :
V_143 -> V_160 = V_161 ;
V_143 -> V_139 = V_169 ;
F_26 ( V_10 , sizeof( V_143 -> V_150 . V_170 ) ) ;
V_143 -> V_150 . V_170 . V_171 = F_46 ( V_141 ) ;
break;
case V_172 :
V_143 -> V_160 = V_161 ;
V_143 -> V_139 = V_172 ;
F_26 ( V_10 , sizeof( V_143 -> V_150 . V_173 ) ) ;
V_143 -> V_150 . V_173 . V_140 = V_140 ;
break;
default:
F_25 ( V_2 -> V_17 -> V_18 , L_5 ) ;
return - V_174 ;
}
return 0 ;
}
static void
F_58 ( struct V_9 * V_10 , const T_1 * V_175 ,
const T_1 * V_138 , const T_1 * V_176 )
{
struct V_177 * V_178 ;
V_178 = ( void * ) F_26 ( V_10 , sizeof( struct V_177 ) ) ;
V_178 -> V_179 = V_180 ;
V_178 -> V_181 = sizeof( struct V_177 ) -
sizeof( struct V_137 ) ;
memcpy ( V_178 -> V_176 , V_176 , V_152 ) ;
memcpy ( V_178 -> V_182 , V_175 , V_152 ) ;
memcpy ( V_178 -> V_183 , V_138 , V_152 ) ;
}
int F_59 ( struct V_1 * V_2 , const T_1 * V_138 ,
T_1 V_139 , T_1 V_140 ,
T_3 V_141 , const T_1 * V_184 ,
T_4 V_185 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
int V_144 ;
T_3 V_186 ;
V_186 = V_187 +
F_60 ( sizeof( struct V_188 ) ,
sizeof( struct V_142 ) ) +
V_189 +
V_40 +
3 +
sizeof( struct V_113 ) +
sizeof( struct V_146 ) +
sizeof( struct V_190 ) +
sizeof( struct V_60 ) +
sizeof( struct V_177 ) +
sizeof( struct V_122 ) +
V_185 ;
if ( V_2 -> V_17 -> V_119 )
V_186 += sizeof( struct V_191 ) +
sizeof( struct V_192 ) +
sizeof( struct V_193 ) ;
V_10 = F_61 ( V_186 ) ;
if ( ! V_10 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_6 ) ;
return - V_46 ;
}
F_62 ( V_10 , V_187 ) ;
switch ( V_139 ) {
case V_159 :
case V_167 :
case V_169 :
case V_172 :
V_144 = F_52 ( V_2 , V_138 , V_139 ,
V_140 , V_141 ,
V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
if ( V_185 )
memcpy ( F_26 ( V_10 , V_185 ) , V_184 ,
V_185 ) ;
F_58 ( V_10 , V_2 -> V_154 , V_138 ,
V_2 -> V_194 ) ;
break;
case V_165 :
V_144 = F_52 ( V_2 , V_138 , V_139 ,
V_140 , V_141 ,
V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
if ( V_185 )
memcpy ( F_26 ( V_10 , V_185 ) , V_184 ,
V_185 ) ;
F_58 ( V_10 , V_138 , V_2 -> V_154 ,
V_2 -> V_194 ) ;
break;
}
switch ( V_139 ) {
case V_159 :
case V_165 :
V_10 -> V_24 = V_195 ;
break;
default:
V_10 -> V_24 = V_196 ;
break;
}
V_13 = F_7 ( V_10 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_197 = V_2 -> V_197 ;
V_13 -> V_198 = V_2 -> V_198 ;
F_63 ( V_10 ) ;
F_64 ( V_2 , V_10 ) ;
return 0 ;
}
static int
F_65 ( struct V_1 * V_2 ,
const T_1 * V_138 ,
T_1 V_139 , T_1 V_140 ,
T_3 V_141 , struct V_9 * V_10 )
{
struct V_188 * V_199 ;
T_1 V_200 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_144 ;
T_3 V_145 ;
struct V_146 * V_147 ;
T_1 V_148 , * V_41 ;
V_145 = V_2 -> V_57 . V_66 . V_149 ;
V_199 = ( void * ) F_26 ( V_10 , F_53 ( struct V_188 , V_150 ) ) ;
memset ( V_199 , 0 , 24 ) ;
memcpy ( V_199 -> V_151 , V_138 , V_152 ) ;
memcpy ( V_199 -> V_153 , V_2 -> V_154 , V_152 ) ;
memcpy ( V_199 -> V_176 , V_2 -> V_194 , V_152 ) ;
V_199 -> V_201 = F_46 ( V_202 |
V_203 ) ;
V_41 = F_26 ( V_10 , V_152 ) ;
switch ( V_139 ) {
case V_204 :
F_26 ( V_10 , sizeof( V_199 -> V_150 . V_205 . V_150 . V_206 ) + 1 ) ;
V_199 -> V_150 . V_205 . V_160 = V_207 ;
V_199 -> V_150 . V_205 . V_150 . V_206 . V_139 =
V_204 ;
V_199 -> V_150 . V_205 . V_150 . V_206 . V_140 =
V_140 ;
V_199 -> V_150 . V_205 . V_150 . V_206 . V_163 =
F_46 ( V_145 ) ;
memmove ( V_41 + V_152 , & V_199 -> V_150 . V_205 . V_160 ,
sizeof( V_199 -> V_150 . V_205 . V_150 . V_206 ) ) ;
memcpy ( V_41 , V_200 , V_152 ) ;
V_144 = F_21 ( V_2 , V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_146 ) + 2 ) ;
* V_41 ++ = V_164 ;
* V_41 ++ = sizeof( struct V_146 ) ;
V_147 = ( void * ) V_41 ;
V_148 = F_56 ( V_2 -> V_57 . V_58 ) ;
V_144 = F_57 ( V_2 , V_148 , V_147 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
if ( V_2 -> V_17 -> V_119 ) {
V_144 = F_29 ( V_2 , V_10 ) ;
if ( V_144 ) {
F_55 ( V_10 ) ;
return V_144 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_48 ( V_2 , V_10 ) ;
F_49 ( V_10 ) ;
break;
default:
F_25 ( V_2 -> V_17 -> V_18 , L_7 ) ;
return - V_174 ;
}
return 0 ;
}
int F_66 ( struct V_1 * V_2 , const T_1 * V_138 ,
T_1 V_139 , T_1 V_140 ,
T_3 V_141 , const T_1 * V_184 ,
T_4 V_185 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
T_1 * V_41 ;
T_2 V_208 , V_209 ;
T_3 V_210 , V_186 ;
V_186 = V_187 +
F_60 ( sizeof( struct V_188 ) ,
sizeof( struct V_142 ) ) +
V_189 +
V_40 +
sizeof( struct V_113 ) +
sizeof( struct V_146 ) +
sizeof( struct V_190 ) +
sizeof( struct V_60 ) +
sizeof( struct V_177 ) +
V_185 +
3 +
V_152 ;
if ( V_2 -> V_17 -> V_119 )
V_186 += sizeof( struct V_191 ) +
sizeof( struct V_192 ) +
sizeof( struct V_193 ) ;
V_10 = F_61 ( V_186 ) ;
if ( ! V_10 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_6 ) ;
return - V_46 ;
}
F_62 ( V_10 , V_187 ) ;
V_208 = V_211 ;
V_209 = 0 ;
V_41 = F_26 ( V_10 , V_189 + sizeof( V_210 ) ) ;
memset ( V_41 , 0 , V_189 + sizeof( V_210 ) ) ;
memcpy ( V_41 , & V_208 , sizeof( V_208 ) ) ;
memcpy ( V_41 + sizeof( V_208 ) , & V_209 , sizeof( V_209 ) ) ;
if ( F_65 ( V_2 , V_138 , V_139 ,
V_140 , V_141 ,
V_10 ) ) {
F_55 ( V_10 ) ;
return - V_174 ;
}
if ( V_185 )
memcpy ( F_26 ( V_10 , V_185 ) , V_184 , V_185 ) ;
F_58 ( V_10 , V_138 , V_2 -> V_154 ,
V_2 -> V_194 ) ;
V_10 -> V_24 = V_196 ;
V_13 = F_7 ( V_10 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_197 = V_2 -> V_197 ;
V_13 -> V_198 = V_2 -> V_198 ;
V_13 -> V_14 |= V_27 ;
V_210 = V_10 -> V_117 - V_189 - sizeof( V_210 ) ;
memcpy ( V_10 -> V_22 + V_189 , & V_210 ,
sizeof( V_210 ) ) ;
F_63 ( V_10 ) ;
F_64 ( V_2 , V_10 ) ;
return 0 ;
}
void F_67 ( struct V_1 * V_2 ,
T_1 * V_135 , int V_117 )
{
struct V_62 * V_63 ;
T_1 * V_138 , * V_41 , * V_212 ;
T_1 V_37 , V_205 , V_213 ;
T_5 V_214 = 0 ;
int V_181 = 0 ;
if ( V_117 < ( sizeof( struct V_215 ) + 3 ) )
return;
if ( * ( V_135 + sizeof( struct V_215 ) ) != V_158 )
return;
if ( * ( V_135 + sizeof( struct V_215 ) + 1 ) != V_161 )
return;
V_138 = V_135 + V_152 ;
V_205 = * ( V_135 + sizeof( struct V_215 ) + 2 ) ;
F_2 ( V_2 -> V_17 -> V_18 ,
L_8 , V_138 , V_205 ) ;
switch ( V_205 ) {
case V_159 :
if ( V_117 < ( sizeof( struct V_215 ) + V_216 ) )
return;
V_41 = V_135 + sizeof( struct V_215 ) + 4 ;
V_214 = F_46 ( * ( T_3 * ) V_41 ) ;
V_181 = V_117 - sizeof( struct V_215 ) - V_216 ;
V_41 += 2 ;
break;
case V_165 :
if ( V_117 < ( sizeof( struct V_215 ) + V_217 ) )
return;
V_41 = V_135 + sizeof( struct V_215 ) + 6 ;
V_214 = F_46 ( * ( T_3 * ) V_41 ) ;
V_181 = V_117 - sizeof( struct V_215 ) - V_217 ;
V_41 += 2 ;
break;
case V_167 :
if ( V_117 < ( sizeof( struct V_215 ) + V_218 ) )
return;
V_41 = V_135 + sizeof( struct V_215 ) + V_218 ;
V_181 = V_117 - sizeof( struct V_215 ) - V_218 ;
break;
default:
F_2 ( V_2 -> V_17 -> V_18 , L_5 ) ;
return;
}
V_63 = F_68 ( V_2 , V_138 ) ;
if ( ! V_63 )
return;
V_63 -> V_74 . V_145 = V_214 ;
for ( V_212 = V_41 + V_181 ; V_41 + 1 < V_212 ; V_41 += 2 + V_41 [ 1 ] ) {
if ( V_41 + 2 + V_41 [ 1 ] > V_212 )
break;
switch ( * V_41 ) {
case V_47 :
V_63 -> V_74 . V_219 = V_41 [ 1 ] ;
for ( V_37 = 0 ; V_37 < V_41 [ 1 ] ; V_37 ++ )
V_63 -> V_74 . V_39 [ V_37 ] = V_41 [ V_37 + 2 ] ;
break;
case V_48 :
V_213 = V_63 -> V_74 . V_219 ;
for ( V_37 = 0 ; V_37 < V_41 [ 1 ] ; V_37 ++ )
V_63 -> V_74 . V_39 [ V_213 + V_37 ] = V_41 [ V_37 + 2 ] ;
V_63 -> V_74 . V_219 += V_41 [ 1 ] ;
break;
case V_164 :
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_220 , V_41 ,
sizeof( struct V_146 ) ) ;
V_63 -> V_221 = 1 ;
break;
case V_67 :
memcpy ( & V_63 -> V_74 . V_61 , V_41 ,
sizeof( struct V_60 ) ) ;
break;
case V_222 :
V_63 -> V_74 . V_223 = V_41 [ 2 ] ;
break;
case V_116 :
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_90 , V_41 ,
sizeof( struct V_137 ) +
F_23 ( T_1 , V_41 [ 1 ] , 8 ) ) ;
break;
case V_224 :
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_225 , V_41 ,
sizeof( struct V_137 ) +
F_23 ( T_1 , V_41 [ 1 ] , V_226 -
sizeof( struct V_137 ) ) ) ;
break;
case V_120 :
V_63 -> V_74 . V_132 = V_41 [ 2 ] ;
break;
case V_94 :
if ( V_2 -> V_17 -> V_119 )
memcpy ( & V_63 -> V_74 . V_227 , V_41 ,
sizeof( struct V_75 ) ) ;
break;
case V_56 :
if ( V_2 -> V_17 -> V_119 ) {
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_99 , V_41 ,
sizeof( struct V_54 ) ) ;
V_63 -> V_228 = 1 ;
}
break;
case V_52 :
if ( V_2 -> V_17 -> V_119 )
V_63 -> V_74 . V_229 =
F_28 ( * ( T_5 * ) ( V_41 + 2 ) ) ;
default:
break;
}
}
return;
}
static int
F_69 ( struct V_1 * V_2 , const T_1 * V_138 )
{
struct V_62 * V_63 ;
struct V_230 V_231 ;
memset ( & V_231 , 0 , sizeof( struct V_230 ) ) ;
V_63 = F_32 ( V_2 , V_138 ) ;
if ( ! V_63 || V_63 -> V_232 == V_233 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_9 , V_138 ) ;
return - V_174 ;
}
memcpy ( & V_231 . V_234 , V_138 , V_152 ) ;
V_231 . V_235 = V_236 ;
return F_70 ( V_2 , V_237 ,
V_238 , 0 , & V_231 , true ) ;
}
static int
F_71 ( struct V_1 * V_2 , const T_1 * V_138 )
{
struct V_62 * V_63 ;
struct V_230 V_231 ;
memset ( & V_231 , 0 , sizeof( struct V_230 ) ) ;
V_63 = F_32 ( V_2 , V_138 ) ;
if ( V_63 && V_63 -> V_232 == V_239 ) {
F_2 ( V_2 -> V_17 -> V_18 ,
L_10 , V_138 ) ;
return 0 ;
}
V_63 = F_68 ( V_2 , V_138 ) ;
if ( ! V_63 )
return - V_46 ;
V_63 -> V_232 = V_239 ;
F_18 ( V_2 , V_138 ) ;
memcpy ( & V_231 . V_234 , V_138 , V_152 ) ;
V_231 . V_235 = V_240 ;
return F_70 ( V_2 , V_237 ,
V_238 , 0 , & V_231 , true ) ;
}
static int
F_72 ( struct V_1 * V_2 , const T_1 * V_138 )
{
struct V_62 * V_63 ;
struct V_230 V_231 ;
unsigned long V_14 ;
memset ( & V_231 , 0 , sizeof( struct V_230 ) ) ;
V_63 = F_32 ( V_2 , V_138 ) ;
if ( V_63 ) {
if ( V_63 -> V_221 ) {
F_73 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_74 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_75 ( V_2 , V_138 ) ;
}
F_1 ( V_2 , V_138 , V_241 ) ;
F_76 ( V_2 , V_138 , V_242 ) ;
memcpy ( & V_231 . V_234 , V_138 , V_152 ) ;
V_231 . V_235 = V_243 ;
return F_70 ( V_2 , V_237 ,
V_238 , 0 , & V_231 , true ) ;
}
static int
F_77 ( struct V_1 * V_2 , const T_1 * V_138 )
{
struct V_62 * V_63 ;
struct V_244 V_245 ;
unsigned long V_14 ;
int V_37 ;
V_63 = F_32 ( V_2 , V_138 ) ;
if ( V_63 && ( V_63 -> V_232 != V_233 ) ) {
F_2 ( V_2 -> V_17 -> V_18 ,
L_11 , V_138 ) ;
V_63 -> V_232 = V_25 ;
V_245 = V_63 -> V_74 . V_220 . V_245 ;
if ( V_245 . V_246 [ 0 ] != 0xff )
V_63 -> V_221 = true ;
if ( V_63 -> V_221 ) {
if ( F_28 ( V_63 -> V_74 . V_220 . V_247 ) &
V_248 )
V_63 -> V_249 =
V_250 ;
else
V_63 -> V_249 =
V_251 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_63 -> V_252 [ V_37 ] =
V_2 -> V_253 [ V_37 ] . V_254 ;
} else {
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_63 -> V_252 [ V_37 ] = V_255 ;
}
memset ( V_63 -> V_256 , 0xff , sizeof( V_63 -> V_256 ) ) ;
F_1 ( V_2 , V_138 , V_25 ) ;
F_76 ( V_2 , V_138 ,
V_25 ) ;
} else {
F_2 ( V_2 -> V_17 -> V_18 ,
L_12 , V_138 ) ;
if ( V_63 ) {
F_73 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_74 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_75 ( V_2 , V_138 ) ;
}
F_1 ( V_2 , V_138 , V_241 ) ;
F_76 ( V_2 , V_138 ,
V_242 ) ;
return - 1 ;
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 , const T_1 * V_138 , T_1 V_205 )
{
switch ( V_205 ) {
case V_257 :
return F_77 ( V_2 , V_138 ) ;
case V_243 :
return F_72 ( V_2 , V_138 ) ;
case V_240 :
return F_71 ( V_2 , V_138 ) ;
case V_236 :
return F_69 ( V_2 , V_138 ) ;
}
return 0 ;
}
int F_79 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_62 * V_63 ;
V_63 = F_32 ( V_2 , V_3 ) ;
if ( V_63 )
return V_63 -> V_232 ;
return V_242 ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_230 V_231 ;
unsigned long V_14 ;
if ( F_10 ( & V_2 -> V_258 ) )
return;
F_19 (sta_ptr, &priv->sta_list, list) {
memset ( & V_231 , 0 , sizeof( struct V_230 ) ) ;
if ( V_63 -> V_221 ) {
F_73 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_74 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_1 ( V_2 , V_63 -> V_259 ,
V_241 ) ;
memcpy ( & V_231 . V_234 , V_63 -> V_259 , V_152 ) ;
V_231 . V_235 = V_243 ;
if ( F_70 ( V_2 , V_237 ,
V_238 , 0 , & V_231 , false ) )
F_34 ( V_2 -> V_17 -> V_18 ,
L_13 ,
V_63 -> V_259 ) ;
}
F_81 ( V_2 ) ;
}
int F_82 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_260 * V_138 ;
unsigned long V_14 ;
T_1 V_3 [ V_152 ] ;
F_83 ( V_3 , V_10 -> V_22 ) ;
F_3 ( & V_2 -> V_261 , V_14 ) ;
F_19 (peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_3 , V_138 -> V_259 , V_152 ) ) {
if ( V_138 -> V_262 <= V_263 &&
V_138 -> V_232 == V_242 &&
( V_138 -> V_264 <
V_265 ) ) {
V_138 -> V_232 = V_239 ;
F_2 ( V_2 -> V_17 -> V_18 ,
L_14 ,
V_138 -> V_259 , V_138 -> V_262 ) ;
F_84 ( V_2 -> V_266 ,
V_138 -> V_259 ,
V_267 ,
0 , V_268 ) ;
V_138 -> V_269 = false ;
V_2 -> V_270 = false ;
} else if ( V_138 -> V_264 <
V_265 &&
V_138 -> V_271 ) {
F_59 ( V_2 ,
V_138 -> V_259 ,
V_172 ,
1 , 0 , NULL , 0 ) ;
V_138 -> V_271 = false ;
}
}
}
F_17 ( & V_2 -> V_261 , V_14 ) ;
return 0 ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_260 * V_138 , * V_272 ;
unsigned long V_14 ;
F_3 ( & V_2 -> V_261 , V_14 ) ;
F_86 (peer, tmp_node, &priv->auto_tdls_list, list) {
F_87 ( & V_138 -> V_29 ) ;
F_88 ( V_138 ) ;
}
F_89 ( & V_2 -> V_273 ) ;
F_17 ( & V_2 -> V_261 , V_14 ) ;
V_2 -> V_270 = false ;
}
void F_90 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_260 * V_274 ;
unsigned long V_14 ;
if ( ! V_2 -> V_17 -> V_275 )
return;
F_3 ( & V_2 -> V_261 , V_14 ) ;
F_19 (tdls_peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_274 -> V_259 , V_3 , V_152 ) ) {
V_274 -> V_232 = V_239 ;
V_274 -> V_276 = V_277 ;
F_17 ( & V_2 -> V_261 , V_14 ) ;
return;
}
}
V_274 = F_91 ( sizeof( * V_274 ) , V_268 ) ;
if ( V_274 ) {
F_83 ( V_274 -> V_259 , V_3 ) ;
V_274 -> V_232 = V_239 ;
V_274 -> V_276 = V_277 ;
F_89 ( & V_274 -> V_29 ) ;
F_92 ( & V_274 -> V_29 , & V_2 -> V_273 ) ;
F_2 ( V_2 -> V_17 -> V_18 , L_15 ,
V_3 ) ;
}
F_17 ( & V_2 -> V_261 , V_14 ) ;
}
void F_76 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_1 V_278 )
{
struct V_260 * V_138 ;
unsigned long V_14 ;
if ( ! V_2 -> V_17 -> V_275 )
return;
F_3 ( & V_2 -> V_261 , V_14 ) ;
F_19 (peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_138 -> V_259 , V_3 , V_152 ) ) {
if ( ( V_278 == V_242 ) &&
( V_138 -> V_232 == V_239 ) )
V_138 -> V_264 ++ ;
else if ( V_278 == V_25 )
V_138 -> V_264 = 0 ;
V_138 -> V_232 = V_278 ;
break;
}
}
F_17 ( & V_2 -> V_261 , V_14 ) ;
}
void F_93 ( struct V_1 * V_2 ,
T_1 * V_3 , T_6 V_279 , T_6 V_280 )
{
struct V_260 * V_138 ;
unsigned long V_14 ;
if ( ! V_2 -> V_17 -> V_275 )
return;
F_3 ( & V_2 -> V_261 , V_14 ) ;
F_19 (peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_138 -> V_259 , V_3 , V_152 ) ) {
V_138 -> V_262 = V_280 - V_279 ;
V_138 -> V_276 = V_277 ;
break;
}
}
F_17 ( & V_2 -> V_261 , V_14 ) ;
}
void F_94 ( unsigned long V_281 )
{
struct V_1 * V_2 = (struct V_1 * ) V_281 ;
struct V_260 * V_274 ;
unsigned long V_14 ;
T_3 V_282 = V_283 ;
if ( F_95 ( ! V_2 || ! V_2 -> V_17 ) ) {
F_96 ( L_16 ,
V_19 ) ;
return;
}
if ( F_33 ( ! V_2 -> V_17 -> V_275 ) )
return;
if ( ! V_2 -> V_284 ) {
F_2 ( V_2 -> V_17 -> V_18 ,
L_17 ) ;
return;
}
V_2 -> V_270 = false ;
if ( F_10 ( & V_2 -> V_273 ) ) {
F_97 ( & V_2 -> V_285 ,
V_277 +
F_98 ( V_286 ) ) ;
return;
}
F_3 ( & V_2 -> V_261 , V_14 ) ;
F_19 (tdls_peer, &priv->auto_tdls_list, list) {
if ( ( V_277 - V_274 -> V_276 ) >
( V_287 * V_288 ) ) {
V_274 -> V_262 = 0 ;
V_274 -> V_271 = true ;
V_2 -> V_270 = true ;
}
if ( ( ( V_274 -> V_262 >= V_289 ) ||
! V_274 -> V_262 ) &&
V_274 -> V_232 == V_25 ) {
V_274 -> V_232 = V_241 ;
F_2 ( V_2 -> V_17 -> V_18 ,
L_18 ,
V_274 -> V_259 , - V_274 -> V_262 ) ;
V_274 -> V_271 = true ;
V_2 -> V_270 = true ;
F_84 ( V_2 -> V_266 ,
V_274 -> V_259 ,
V_290 ,
V_282 , V_268 ) ;
} else if ( V_274 -> V_262 &&
V_274 -> V_262 <= V_263 &&
V_274 -> V_232 == V_242 &&
V_274 -> V_264 <
V_265 ) {
V_2 -> V_270 = true ;
V_274 -> V_269 = true ;
F_2 ( V_2 -> V_17 -> V_18 ,
L_19 ,
V_274 -> V_259 , - V_274 -> V_262 ) ;
}
}
F_17 ( & V_2 -> V_261 , V_14 ) ;
F_97 ( & V_2 -> V_285 ,
V_277 + F_98 ( V_286 ) ) ;
}
void F_99 ( struct V_1 * V_2 )
{
F_100 ( & V_2 -> V_285 ) ;
V_2 -> V_285 . V_291 = F_94 ;
V_2 -> V_285 . V_22 = ( unsigned long ) V_2 ;
V_2 -> V_284 = true ;
F_97 ( & V_2 -> V_285 ,
V_277 + F_98 ( V_286 ) ) ;
}
void F_101 ( struct V_1 * V_2 )
{
if ( F_102 ( V_2 -> V_17 -> V_292 ) &&
V_2 -> V_17 -> V_275 &&
V_2 -> V_198 == V_293 ) {
V_2 -> V_284 = false ;
F_103 ( & V_2 -> V_285 ) ;
F_85 ( V_2 ) ;
}
}
