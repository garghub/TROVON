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
F_2 ( V_2 -> V_17 , V_18 , L_1 , V_19 , V_3 ) ;
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
F_2 ( V_2 -> V_17 , V_18 , L_1 , V_19 , V_3 ) ;
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
F_2 ( V_2 -> V_17 , ERROR ,
L_2 ) ;
return - V_46 ;
}
V_41 = F_25 ( V_10 , V_43 + 2 ) ;
* V_41 ++ = V_47 ;
* V_41 ++ = V_43 ;
memcpy ( V_41 , V_39 , V_43 ) ;
if ( V_42 > V_45 ) {
V_44 = V_42 - V_45 ;
V_41 = F_25 ( V_10 , V_44 + 2 ) ;
* V_41 ++ = V_48 ;
* V_41 ++ = V_44 ;
memcpy ( V_41 , V_39 + V_45 ,
V_44 ) ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_49 * V_50 ;
T_1 * V_41 ;
V_50 = (struct V_49 * ) & V_2 -> V_51 ;
V_41 = ( void * ) F_25 ( V_10 , 4 ) ;
* V_41 ++ = V_52 ;
* V_41 ++ = 2 ;
* V_41 ++ = F_27 ( V_50 -> V_53 ) ;
return;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_54 V_55 ;
T_1 * V_41 ;
V_41 = ( void * ) F_25 ( V_10 , sizeof( struct V_54 ) + 2 ) ;
* V_41 ++ = V_56 ;
* V_41 ++ = sizeof( struct V_54 ) ;
memset ( & V_55 , 0 , sizeof( struct V_54 ) ) ;
F_29 ( V_2 , & V_55 , V_2 -> V_57 . V_58 ) ;
memcpy ( V_41 , & V_55 , sizeof( V_55 ) ) ;
return 0 ;
}
static int
F_30 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_1 V_59 , struct V_9 * V_10 )
{
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 =
& V_2 -> V_57 . V_66 ;
T_1 * V_41 ;
V_63 = F_31 ( V_2 , V_3 ) ;
if ( F_32 ( ! V_63 ) ) {
F_2 ( V_2 -> V_17 , ERROR ,
L_3 ) ;
return - 1 ;
}
V_41 = ( void * ) F_25 ( V_10 , sizeof( struct V_60 ) + 2 ) ;
* V_41 ++ = V_67 ;
* V_41 ++ = sizeof( struct V_60 ) ;
V_61 = ( void * ) V_41 ;
V_61 -> V_68 = V_65 -> V_69 ;
if ( F_33 ( V_2 -> V_17 -> V_70 ) &&
V_65 -> V_71 &&
F_34 ( V_65 -> V_72 -> V_73 ) )
V_61 -> V_73 = V_65 -> V_72 -> V_73 ;
if ( V_59 ) {
V_61 -> V_73 =
F_35 ( V_65 -> V_69 ) ;
V_61 -> V_73 |= F_36 ( 2 ) ;
}
memcpy ( & V_63 -> V_74 . V_61 , V_61 ,
sizeof( struct V_60 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
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
V_63 = F_31 ( V_2 , V_3 ) ;
if ( F_32 ( ! V_63 ) ) {
F_2 ( V_17 , ERROR ,
L_3 ) ;
return - 1 ;
}
if ( ! F_38 ( V_2 ) ) {
if ( V_63 -> V_74 . V_90 . V_91 [ 7 ] &
V_92 ) {
F_2 ( V_17 , V_93 ,
L_4 ) ;
return 0 ;
}
} else {
V_77 = V_65 -> V_94 ;
}
V_41 = ( void * ) F_25 ( V_10 , sizeof( struct V_75 ) + 2 ) ;
* V_41 ++ = V_95 ;
* V_41 ++ = sizeof( struct V_75 ) ;
V_76 = (struct V_75 * ) V_41 ;
if ( V_65 -> V_96 & V_97 )
V_89 = V_17 -> V_98 ;
else
V_89 = V_17 -> V_99 ;
V_55 = & V_63 -> V_74 . V_100 ;
V_79 = F_39 ( V_89 ) ;
V_80 =
F_39 ( F_40 ( V_55 -> V_101 ) ) ;
V_79 = F_23 ( T_1 , V_79 , V_80 ) ;
if ( V_77 && V_63 -> V_74 . V_90 . V_91 [ 7 ] &
V_92 ) {
V_81 =
F_39 ( F_40 ( V_77 -> V_101 ) ) ;
V_79 = F_23 ( T_1 , V_79 , V_81 ) ;
}
switch ( V_79 ) {
case V_102 :
V_76 -> V_103 = V_102 ;
break;
case V_104 :
V_76 -> V_103 = V_104 ;
break;
case V_105 :
V_76 -> V_103 = V_105 ;
break;
default:
V_76 -> V_103 = V_106 ;
break;
}
V_83 = F_41 ( V_17 -> V_107 ) ;
V_84 = F_27 ( V_55 -> V_108 . V_109 ) ;
V_85 = 0 ;
for ( V_88 = 1 ; V_88 <= 8 ; V_88 ++ ) {
V_86 = F_42 ( V_83 , V_88 ) ;
V_87 = F_42 ( V_84 , V_88 ) ;
if ( ( V_86 == V_110 ) ||
( V_87 == V_110 ) )
F_43 ( V_85 , V_88 ,
V_110 ) ;
else
F_43 ( V_85 , V_88 ,
F_23 ( T_3 , V_86 , V_87 ) ) ;
}
V_76 -> V_111 = F_44 ( V_85 ) ;
switch ( V_76 -> V_103 ) {
case V_102 :
V_82 = V_102 ;
break;
case V_104 :
V_82 = V_104 ;
break;
case V_105 :
V_82 = V_102 ;
break;
default:
V_82 = V_106 ;
break;
}
V_76 -> V_112 =
F_45 ( V_2 , V_113 ,
V_65 -> V_69 ,
V_82 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_114 * V_90 ;
V_90 = ( void * ) F_25 ( V_10 , sizeof( struct V_114 ) ) ;
V_90 -> V_115 . V_116 = V_117 ;
V_90 -> V_115 . V_118 = 8 ;
memset ( V_90 -> V_91 , 0 , 8 ) ;
V_90 -> V_91 [ 4 ] |= V_119 ;
if ( V_2 -> V_17 -> V_120 )
V_90 -> V_91 [ 7 ] |= V_92 ;
}
static void F_47 ( struct V_9 * V_10 )
{
T_1 * V_41 = ( void * ) F_25 ( V_10 , 3 ) ;
* V_41 ++ = V_121 ;
* V_41 ++ = 1 ;
* V_41 ++ = V_122 ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_123 * V_20 ;
T_1 V_124 [] = { 0x42 , 0x43 , 0x5e , 0x00 } ;
T_1 V_125 [] = { 0x62 , 0x32 , 0x2f , 0x00 } ;
T_1 V_126 [] = { 0x03 , 0xa4 , 0x00 , 0x00 } ;
T_1 V_127 [] = { 0x27 , 0xa4 , 0x00 , 0x00 } ;
V_20 = ( void * ) F_25 ( V_10 , sizeof( * V_20 ) ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_116 = V_128 ;
V_20 -> V_118 = sizeof( * V_20 ) - 2 ;
V_20 -> V_129 [ 0 ] = 0x00 ;
V_20 -> V_129 [ 1 ] = 0x50 ;
V_20 -> V_129 [ 2 ] = 0xf2 ;
V_20 -> V_130 = 2 ;
V_20 -> V_131 = 1 ;
V_20 -> V_132 = 1 ;
V_20 -> V_133 = 0 ;
memcpy ( & V_20 -> V_134 [ 0 ] , V_126 , sizeof( V_126 ) ) ;
memcpy ( & V_20 -> V_134 [ 1 ] , V_127 , sizeof( V_127 ) ) ;
memcpy ( & V_20 -> V_134 [ 2 ] , V_124 , sizeof( V_124 ) ) ;
memcpy ( & V_20 -> V_134 [ 3 ] , V_125 , sizeof( V_125 ) ) ;
}
static void
F_49 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_1 V_135 )
{
T_1 * V_136 ;
V_136 = ( void * ) F_25 ( V_10 , V_137 +
sizeof( struct V_138 ) ) ;
* V_136 ++ = V_128 ;
* V_136 ++ = 7 ;
* V_136 ++ = 0x00 ;
* V_136 ++ = 0x50 ;
* V_136 ++ = 0xf2 ;
* V_136 ++ = 2 ;
* V_136 ++ = 0 ;
* V_136 ++ = 1 ;
* V_136 ++ = V_135 ;
}
static int F_50 ( struct V_1 * V_2 ,
const T_1 * V_139 , T_1 V_140 ,
T_1 V_141 ,
T_3 V_142 , struct V_9 * V_10 )
{
struct V_143 * V_144 ;
int V_145 ;
T_3 V_146 ;
struct V_147 * V_148 ;
T_1 V_149 , * V_41 ;
V_146 = V_2 -> V_57 . V_66 . V_150 ;
V_144 = ( void * ) F_25 ( V_10 , F_51 ( struct V_143 , V_151 ) ) ;
memcpy ( V_144 -> V_152 , V_139 , V_153 ) ;
memcpy ( V_144 -> V_154 , V_2 -> V_155 , V_153 ) ;
V_144 -> V_156 = F_52 ( V_157 ) ;
V_144 -> V_158 = V_159 ;
switch ( V_140 ) {
case V_160 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_160 ;
F_25 ( V_10 , sizeof( V_144 -> V_151 . V_163 ) ) ;
V_144 -> V_151 . V_163 . V_141 = V_141 ;
V_144 -> V_151 . V_163 . V_164 = F_44 ( V_146 ) ;
V_145 = F_21 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
V_41 = ( void * ) F_25 ( V_10 , sizeof( struct V_147 ) + 2 ) ;
* V_41 ++ = V_165 ;
* V_41 ++ = sizeof( struct V_147 ) ;
V_148 = ( void * ) V_41 ;
V_149 = F_54 ( V_2 -> V_57 . V_58 ) ;
V_145 = F_55 ( V_2 , V_149 , V_148 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
if ( V_2 -> V_17 -> V_120 ) {
V_145 = F_28 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
F_26 ( V_2 , V_10 ) ;
}
F_46 ( V_2 , V_10 ) ;
F_47 ( V_10 ) ;
F_49 ( V_2 , V_10 , 0 ) ;
break;
case V_166 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_166 ;
F_25 ( V_10 , sizeof( V_144 -> V_151 . V_167 ) ) ;
V_144 -> V_151 . V_167 . V_142 = F_44 ( V_142 ) ;
V_144 -> V_151 . V_167 . V_141 = V_141 ;
V_144 -> V_151 . V_167 . V_164 = F_44 ( V_146 ) ;
V_145 = F_21 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
V_41 = ( void * ) F_25 ( V_10 , sizeof( struct V_147 ) + 2 ) ;
* V_41 ++ = V_165 ;
* V_41 ++ = sizeof( struct V_147 ) ;
V_148 = ( void * ) V_41 ;
V_149 = F_54 ( V_2 -> V_57 . V_58 ) ;
V_145 = F_55 ( V_2 , V_149 , V_148 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
if ( V_2 -> V_17 -> V_120 ) {
V_145 = F_28 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
F_26 ( V_2 , V_10 ) ;
}
F_46 ( V_2 , V_10 ) ;
F_47 ( V_10 ) ;
F_49 ( V_2 , V_10 , 0 ) ;
break;
case V_168 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_168 ;
F_25 ( V_10 , sizeof( V_144 -> V_151 . V_169 ) ) ;
V_144 -> V_151 . V_169 . V_142 = F_44 ( V_142 ) ;
V_144 -> V_151 . V_169 . V_141 = V_141 ;
F_48 ( V_2 , V_10 ) ;
if ( V_2 -> V_17 -> V_120 ) {
V_145 = F_37 ( V_2 , V_139 , V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
V_145 = F_30 ( V_2 , V_139 , 1 , V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
} else {
V_145 = F_30 ( V_2 , V_139 , 0 , V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
}
break;
case V_170 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_170 ;
F_25 ( V_10 , sizeof( V_144 -> V_151 . V_171 ) ) ;
V_144 -> V_151 . V_171 . V_172 = F_44 ( V_142 ) ;
break;
case V_173 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_173 ;
F_25 ( V_10 , sizeof( V_144 -> V_151 . V_174 ) ) ;
V_144 -> V_151 . V_174 . V_141 = V_141 ;
break;
default:
F_2 ( V_2 -> V_17 , ERROR , L_5 ) ;
return - V_175 ;
}
return 0 ;
}
static void
F_56 ( struct V_9 * V_10 , const T_1 * V_176 ,
const T_1 * V_139 , const T_1 * V_177 )
{
struct V_178 * V_179 ;
V_179 = ( void * ) F_25 ( V_10 , sizeof( struct V_178 ) ) ;
V_179 -> V_180 = V_181 ;
V_179 -> V_182 = sizeof( struct V_178 ) -
sizeof( struct V_138 ) ;
memcpy ( V_179 -> V_177 , V_177 , V_153 ) ;
memcpy ( V_179 -> V_183 , V_176 , V_153 ) ;
memcpy ( V_179 -> V_184 , V_139 , V_153 ) ;
}
int F_57 ( struct V_1 * V_2 , const T_1 * V_139 ,
T_1 V_140 , T_1 V_141 ,
T_3 V_142 , const T_1 * V_185 ,
T_4 V_186 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
int V_145 ;
T_3 V_187 ;
V_187 = V_188 +
F_58 ( sizeof( struct V_189 ) ,
sizeof( struct V_143 ) ) +
V_190 +
V_40 +
3 +
sizeof( struct V_114 ) +
sizeof( struct V_147 ) +
sizeof( struct V_191 ) +
sizeof( struct V_60 ) +
sizeof( struct V_178 ) +
sizeof( struct V_123 ) +
V_186 ;
if ( V_2 -> V_17 -> V_120 )
V_187 += sizeof( struct V_192 ) +
sizeof( struct V_193 ) +
sizeof( struct V_194 ) ;
V_10 = F_59 ( V_187 ) ;
if ( ! V_10 ) {
F_2 ( V_2 -> V_17 , ERROR ,
L_6 ) ;
return - V_46 ;
}
F_60 ( V_10 , V_188 ) ;
switch ( V_140 ) {
case V_160 :
case V_168 :
case V_170 :
case V_173 :
V_145 = F_50 ( V_2 , V_139 , V_140 ,
V_141 , V_142 ,
V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
if ( V_186 )
memcpy ( F_25 ( V_10 , V_186 ) , V_185 ,
V_186 ) ;
F_56 ( V_10 , V_2 -> V_155 , V_139 ,
V_2 -> V_195 ) ;
break;
case V_166 :
V_145 = F_50 ( V_2 , V_139 , V_140 ,
V_141 , V_142 ,
V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
if ( V_186 )
memcpy ( F_25 ( V_10 , V_186 ) , V_185 ,
V_186 ) ;
F_56 ( V_10 , V_139 , V_2 -> V_155 ,
V_2 -> V_195 ) ;
break;
}
switch ( V_140 ) {
case V_160 :
case V_166 :
V_10 -> V_24 = V_196 ;
break;
default:
V_10 -> V_24 = V_197 ;
break;
}
V_13 = F_7 ( V_10 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_198 = V_2 -> V_198 ;
V_13 -> V_199 = V_2 -> V_199 ;
F_61 ( V_10 ) ;
F_62 ( V_2 , V_10 ) ;
return 0 ;
}
static int
F_63 ( struct V_1 * V_2 ,
const T_1 * V_139 ,
T_1 V_140 , T_1 V_141 ,
T_3 V_142 , struct V_9 * V_10 )
{
struct V_189 * V_200 ;
T_1 V_201 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_145 ;
T_3 V_146 ;
struct V_147 * V_148 ;
T_1 V_149 , * V_41 ;
V_146 = V_2 -> V_57 . V_66 . V_150 ;
V_200 = ( void * ) F_25 ( V_10 , F_51 ( struct V_189 , V_151 ) ) ;
memset ( V_200 , 0 , 24 ) ;
memcpy ( V_200 -> V_152 , V_139 , V_153 ) ;
memcpy ( V_200 -> V_154 , V_2 -> V_155 , V_153 ) ;
memcpy ( V_200 -> V_177 , V_2 -> V_195 , V_153 ) ;
V_200 -> V_202 = F_44 ( V_203 |
V_204 ) ;
V_41 = F_25 ( V_10 , V_153 ) ;
switch ( V_140 ) {
case V_205 :
F_25 ( V_10 , sizeof( V_200 -> V_151 . V_206 . V_151 . V_207 ) + 1 ) ;
V_200 -> V_151 . V_206 . V_161 = V_208 ;
V_200 -> V_151 . V_206 . V_151 . V_207 . V_140 =
V_205 ;
V_200 -> V_151 . V_206 . V_151 . V_207 . V_141 =
V_141 ;
V_200 -> V_151 . V_206 . V_151 . V_207 . V_164 =
F_44 ( V_146 ) ;
memmove ( V_41 + V_153 , & V_200 -> V_151 . V_206 . V_161 ,
sizeof( V_200 -> V_151 . V_206 . V_151 . V_207 ) ) ;
memcpy ( V_41 , V_201 , V_153 ) ;
V_145 = F_21 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
V_41 = ( void * ) F_25 ( V_10 , sizeof( struct V_147 ) + 2 ) ;
* V_41 ++ = V_165 ;
* V_41 ++ = sizeof( struct V_147 ) ;
V_148 = ( void * ) V_41 ;
V_149 = F_54 ( V_2 -> V_57 . V_58 ) ;
V_145 = F_55 ( V_2 , V_149 , V_148 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
if ( V_2 -> V_17 -> V_120 ) {
V_145 = F_28 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_53 ( V_10 ) ;
return V_145 ;
}
F_26 ( V_2 , V_10 ) ;
}
F_46 ( V_2 , V_10 ) ;
F_47 ( V_10 ) ;
break;
default:
F_2 ( V_2 -> V_17 , ERROR , L_7 ) ;
return - V_175 ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 , const T_1 * V_139 ,
T_1 V_140 , T_1 V_141 ,
T_3 V_142 , const T_1 * V_185 ,
T_4 V_186 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
T_1 * V_41 ;
T_2 V_209 , V_210 ;
T_3 V_211 , V_187 ;
V_187 = V_188 +
F_58 ( sizeof( struct V_189 ) ,
sizeof( struct V_143 ) ) +
V_190 +
V_40 +
sizeof( struct V_114 ) +
sizeof( struct V_147 ) +
sizeof( struct V_191 ) +
sizeof( struct V_60 ) +
sizeof( struct V_178 ) +
V_186 +
3 +
V_153 ;
if ( V_2 -> V_17 -> V_120 )
V_187 += sizeof( struct V_192 ) +
sizeof( struct V_193 ) +
sizeof( struct V_194 ) ;
V_10 = F_59 ( V_187 ) ;
if ( ! V_10 ) {
F_2 ( V_2 -> V_17 , ERROR ,
L_6 ) ;
return - V_46 ;
}
F_60 ( V_10 , V_188 ) ;
V_209 = V_212 ;
V_210 = 0 ;
V_41 = F_25 ( V_10 , V_190 + sizeof( V_211 ) ) ;
memset ( V_41 , 0 , V_190 + sizeof( V_211 ) ) ;
memcpy ( V_41 , & V_209 , sizeof( V_209 ) ) ;
memcpy ( V_41 + sizeof( V_209 ) , & V_210 , sizeof( V_210 ) ) ;
if ( F_63 ( V_2 , V_139 , V_140 ,
V_141 , V_142 ,
V_10 ) ) {
F_53 ( V_10 ) ;
return - V_175 ;
}
if ( V_186 )
memcpy ( F_25 ( V_10 , V_186 ) , V_185 , V_186 ) ;
F_56 ( V_10 , V_139 , V_2 -> V_155 ,
V_2 -> V_195 ) ;
V_10 -> V_24 = V_197 ;
V_13 = F_7 ( V_10 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_198 = V_2 -> V_198 ;
V_13 -> V_199 = V_2 -> V_199 ;
V_13 -> V_14 |= V_27 ;
V_211 = V_10 -> V_118 - V_190 - sizeof( V_211 ) ;
memcpy ( V_10 -> V_22 + V_190 , & V_211 ,
sizeof( V_211 ) ) ;
F_61 ( V_10 ) ;
F_62 ( V_2 , V_10 ) ;
return 0 ;
}
void F_65 ( struct V_1 * V_2 ,
T_1 * V_136 , int V_118 )
{
struct V_62 * V_63 ;
T_1 * V_139 , * V_41 , * V_213 ;
T_1 V_37 , V_206 , V_214 ;
T_5 V_215 = 0 ;
int V_182 = 0 ;
if ( V_118 < ( sizeof( struct V_216 ) + 3 ) )
return;
if ( * ( V_136 + sizeof( struct V_216 ) ) != V_159 )
return;
if ( * ( V_136 + sizeof( struct V_216 ) + 1 ) != V_162 )
return;
V_139 = V_136 + V_153 ;
V_206 = * ( V_136 + sizeof( struct V_216 ) + 2 ) ;
F_2 ( V_2 -> V_17 , V_18 ,
L_8 , V_139 , V_206 ) ;
switch ( V_206 ) {
case V_160 :
if ( V_118 < ( sizeof( struct V_216 ) + V_217 ) )
return;
V_41 = V_136 + sizeof( struct V_216 ) + 4 ;
V_215 = F_44 ( * ( T_3 * ) V_41 ) ;
V_182 = V_118 - sizeof( struct V_216 ) - V_217 ;
V_41 += 2 ;
break;
case V_166 :
if ( V_118 < ( sizeof( struct V_216 ) + V_218 ) )
return;
V_41 = V_136 + sizeof( struct V_216 ) + 6 ;
V_215 = F_44 ( * ( T_3 * ) V_41 ) ;
V_182 = V_118 - sizeof( struct V_216 ) - V_218 ;
V_41 += 2 ;
break;
case V_168 :
if ( V_118 < ( sizeof( struct V_216 ) + V_219 ) )
return;
V_41 = V_136 + sizeof( struct V_216 ) + V_219 ;
V_182 = V_118 - sizeof( struct V_216 ) - V_219 ;
break;
default:
F_2 ( V_2 -> V_17 , ERROR , L_5 ) ;
return;
}
V_63 = F_66 ( V_2 , V_139 ) ;
if ( ! V_63 )
return;
V_63 -> V_74 . V_146 = V_215 ;
for ( V_213 = V_41 + V_182 ; V_41 + 1 < V_213 ; V_41 += 2 + V_41 [ 1 ] ) {
if ( V_41 + 2 + V_41 [ 1 ] > V_213 )
break;
switch ( * V_41 ) {
case V_47 :
V_63 -> V_74 . V_220 = V_41 [ 1 ] ;
for ( V_37 = 0 ; V_37 < V_41 [ 1 ] ; V_37 ++ )
V_63 -> V_74 . V_39 [ V_37 ] = V_41 [ V_37 + 2 ] ;
break;
case V_48 :
V_214 = V_63 -> V_74 . V_220 ;
for ( V_37 = 0 ; V_37 < V_41 [ 1 ] ; V_37 ++ )
V_63 -> V_74 . V_39 [ V_214 + V_37 ] = V_41 [ V_37 + 2 ] ;
V_63 -> V_74 . V_220 += V_41 [ 1 ] ;
break;
case V_165 :
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_221 , V_41 ,
sizeof( struct V_147 ) ) ;
V_63 -> V_222 = 1 ;
break;
case V_67 :
memcpy ( & V_63 -> V_74 . V_61 , V_41 ,
sizeof( struct V_60 ) ) ;
break;
case V_223 :
V_63 -> V_74 . V_224 = V_41 [ 2 ] ;
break;
case V_117 :
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_90 , V_41 ,
sizeof( struct V_138 ) +
F_23 ( T_1 , V_41 [ 1 ] , 8 ) ) ;
break;
case V_225 :
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_226 , V_41 ,
sizeof( struct V_138 ) +
F_23 ( T_1 , V_41 [ 1 ] , V_227 -
sizeof( struct V_138 ) ) ) ;
break;
case V_121 :
V_63 -> V_74 . V_133 = V_41 [ 2 ] ;
break;
case V_95 :
if ( V_2 -> V_17 -> V_120 )
memcpy ( & V_63 -> V_74 . V_228 , V_41 ,
sizeof( struct V_75 ) ) ;
break;
case V_56 :
if ( V_2 -> V_17 -> V_120 ) {
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_100 , V_41 ,
sizeof( struct V_54 ) ) ;
V_63 -> V_229 = 1 ;
}
break;
case V_52 :
if ( V_2 -> V_17 -> V_120 )
V_63 -> V_74 . V_230 =
F_27 ( * ( T_5 * ) ( V_41 + 2 ) ) ;
default:
break;
}
}
return;
}
static int
F_67 ( struct V_1 * V_2 , const T_1 * V_139 )
{
struct V_62 * V_63 ;
struct V_231 V_232 ;
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
V_63 = F_31 ( V_2 , V_139 ) ;
if ( ! V_63 || V_63 -> V_233 == V_234 ) {
F_2 ( V_2 -> V_17 , ERROR ,
L_9 , V_139 ) ;
return - V_175 ;
}
memcpy ( & V_232 . V_235 , V_139 , V_153 ) ;
V_232 . V_236 = V_237 ;
return F_68 ( V_2 , V_238 ,
V_239 , 0 , & V_232 , true ) ;
}
static int
F_69 ( struct V_1 * V_2 , const T_1 * V_139 )
{
struct V_62 * V_63 ;
struct V_231 V_232 ;
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
V_63 = F_31 ( V_2 , V_139 ) ;
if ( V_63 && V_63 -> V_233 == V_240 ) {
F_2 ( V_2 -> V_17 , V_93 ,
L_10 , V_139 ) ;
return 0 ;
}
V_63 = F_66 ( V_2 , V_139 ) ;
if ( ! V_63 )
return - V_46 ;
V_63 -> V_233 = V_240 ;
F_18 ( V_2 , V_139 ) ;
memcpy ( & V_232 . V_235 , V_139 , V_153 ) ;
V_232 . V_236 = V_241 ;
return F_68 ( V_2 , V_238 ,
V_239 , 0 , & V_232 , true ) ;
}
static int
F_70 ( struct V_1 * V_2 , const T_1 * V_139 )
{
struct V_62 * V_63 ;
struct V_231 V_232 ;
unsigned long V_14 ;
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
V_63 = F_31 ( V_2 , V_139 ) ;
if ( V_63 ) {
if ( V_63 -> V_222 ) {
F_71 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_72 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_73 ( V_2 , V_139 ) ;
}
F_1 ( V_2 , V_139 , V_242 ) ;
F_74 ( V_2 , V_139 , V_243 ) ;
memcpy ( & V_232 . V_235 , V_139 , V_153 ) ;
V_232 . V_236 = V_244 ;
return F_68 ( V_2 , V_238 ,
V_239 , 0 , & V_232 , true ) ;
}
static int
F_75 ( struct V_1 * V_2 , const T_1 * V_139 )
{
struct V_62 * V_63 ;
struct V_245 V_246 ;
unsigned long V_14 ;
int V_37 ;
V_63 = F_31 ( V_2 , V_139 ) ;
if ( V_63 && ( V_63 -> V_233 != V_234 ) ) {
F_2 ( V_2 -> V_17 , V_247 ,
L_11 , V_139 ) ;
V_63 -> V_233 = V_25 ;
V_246 = V_63 -> V_74 . V_221 . V_246 ;
if ( V_246 . V_248 [ 0 ] != 0xff )
V_63 -> V_222 = true ;
if ( V_63 -> V_222 ) {
if ( F_27 ( V_63 -> V_74 . V_221 . V_249 ) &
V_250 )
V_63 -> V_251 =
V_252 ;
else
V_63 -> V_251 =
V_253 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_63 -> V_254 [ V_37 ] =
V_2 -> V_255 [ V_37 ] . V_256 ;
} else {
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_63 -> V_254 [ V_37 ] = V_257 ;
}
memset ( V_63 -> V_258 , 0xff , sizeof( V_63 -> V_258 ) ) ;
F_1 ( V_2 , V_139 , V_25 ) ;
F_74 ( V_2 , V_139 ,
V_25 ) ;
} else {
F_2 ( V_2 -> V_17 , ERROR ,
L_12 , V_139 ) ;
if ( V_63 ) {
F_71 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_72 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_73 ( V_2 , V_139 ) ;
}
F_1 ( V_2 , V_139 , V_242 ) ;
F_74 ( V_2 , V_139 ,
V_243 ) ;
return - 1 ;
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 , const T_1 * V_139 , T_1 V_206 )
{
switch ( V_206 ) {
case V_259 :
return F_75 ( V_2 , V_139 ) ;
case V_244 :
return F_70 ( V_2 , V_139 ) ;
case V_241 :
return F_69 ( V_2 , V_139 ) ;
case V_237 :
return F_67 ( V_2 , V_139 ) ;
}
return 0 ;
}
int F_77 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_62 * V_63 ;
V_63 = F_31 ( V_2 , V_3 ) ;
if ( V_63 )
return V_63 -> V_233 ;
return V_243 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_260 * V_136 )
{
struct V_62 * V_63 ;
struct V_260 * V_139 = V_136 ;
int V_261 = 0 ;
unsigned long V_14 ;
if ( ! F_79 ( V_2 -> V_17 -> V_262 ) )
return 0 ;
if ( ! ( V_2 -> V_199 == V_263 && V_2 -> V_264 ) )
return 0 ;
F_3 ( & V_2 -> V_265 , V_14 ) ;
F_19 (sta_ptr, &priv->sta_list, list) {
if ( V_63 -> V_233 == V_25 ) {
F_80 ( V_139 -> V_266 , V_63 -> V_267 ) ;
V_139 ++ ;
V_261 ++ ;
if ( V_261 >= V_268 )
break;
}
}
F_17 ( & V_2 -> V_265 , V_14 ) ;
return V_261 ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_231 V_232 ;
unsigned long V_14 ;
if ( F_10 ( & V_2 -> V_269 ) )
return;
F_19 (sta_ptr, &priv->sta_list, list) {
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
if ( V_63 -> V_222 ) {
F_71 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_72 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_1 ( V_2 , V_63 -> V_267 ,
V_242 ) ;
memcpy ( & V_232 . V_235 , V_63 -> V_267 , V_153 ) ;
V_232 . V_236 = V_244 ;
if ( F_68 ( V_2 , V_238 ,
V_239 , 0 , & V_232 , false ) )
F_2 ( V_2 -> V_17 , ERROR ,
L_13 ,
V_63 -> V_267 ) ;
}
F_82 ( V_2 ) ;
}
int F_83 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_270 * V_139 ;
unsigned long V_14 ;
T_1 V_3 [ V_153 ] ;
F_80 ( V_3 , V_10 -> V_22 ) ;
F_3 ( & V_2 -> V_271 , V_14 ) ;
F_19 (peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_3 , V_139 -> V_267 , V_153 ) ) {
if ( V_139 -> V_272 <= V_273 &&
V_139 -> V_233 == V_243 &&
( V_139 -> V_274 <
V_275 ) ) {
V_139 -> V_233 = V_240 ;
F_2 ( V_2 -> V_17 , V_276 ,
L_14 ,
V_139 -> V_267 , V_139 -> V_272 ) ;
F_84 ( V_2 -> V_277 ,
V_139 -> V_267 ,
V_278 ,
0 , V_279 ) ;
V_139 -> V_280 = false ;
V_2 -> V_281 = false ;
} else if ( V_139 -> V_274 <
V_275 &&
V_139 -> V_282 ) {
F_57 ( V_2 ,
V_139 -> V_267 ,
V_173 ,
1 , 0 , NULL , 0 ) ;
V_139 -> V_282 = false ;
}
}
}
F_17 ( & V_2 -> V_271 , V_14 ) ;
return 0 ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_270 * V_139 , * V_283 ;
unsigned long V_14 ;
F_3 ( & V_2 -> V_271 , V_14 ) ;
F_86 (peer, tmp_node, &priv->auto_tdls_list, list) {
F_87 ( & V_139 -> V_29 ) ;
F_88 ( V_139 ) ;
}
F_89 ( & V_2 -> V_284 ) ;
F_17 ( & V_2 -> V_271 , V_14 ) ;
V_2 -> V_281 = false ;
}
void F_90 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_270 * V_285 ;
unsigned long V_14 ;
if ( ! V_2 -> V_17 -> V_286 )
return;
F_3 ( & V_2 -> V_271 , V_14 ) ;
F_19 (tdls_peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_285 -> V_267 , V_3 , V_153 ) ) {
V_285 -> V_233 = V_240 ;
V_285 -> V_287 = V_288 ;
F_17 ( & V_2 -> V_271 , V_14 ) ;
return;
}
}
V_285 = F_91 ( sizeof( * V_285 ) , V_279 ) ;
if ( V_285 ) {
F_80 ( V_285 -> V_267 , V_3 ) ;
V_285 -> V_233 = V_240 ;
V_285 -> V_287 = V_288 ;
F_89 ( & V_285 -> V_29 ) ;
F_92 ( & V_285 -> V_29 , & V_2 -> V_284 ) ;
F_2 ( V_2 -> V_17 , V_276 ,
L_15 , V_3 ) ;
}
F_17 ( & V_2 -> V_271 , V_14 ) ;
}
void F_74 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_1 V_289 )
{
struct V_270 * V_139 ;
unsigned long V_14 ;
if ( ! V_2 -> V_17 -> V_286 )
return;
F_3 ( & V_2 -> V_271 , V_14 ) ;
F_19 (peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_139 -> V_267 , V_3 , V_153 ) ) {
if ( ( V_289 == V_243 ) &&
( V_139 -> V_233 == V_240 ) )
V_139 -> V_274 ++ ;
else if ( V_289 == V_25 )
V_139 -> V_274 = 0 ;
V_139 -> V_233 = V_289 ;
break;
}
}
F_17 ( & V_2 -> V_271 , V_14 ) ;
}
void F_93 ( struct V_1 * V_2 ,
T_1 * V_3 , T_6 V_290 , T_6 V_291 )
{
struct V_270 * V_139 ;
unsigned long V_14 ;
if ( ! V_2 -> V_17 -> V_286 )
return;
F_3 ( & V_2 -> V_271 , V_14 ) ;
F_19 (peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_139 -> V_267 , V_3 , V_153 ) ) {
V_139 -> V_272 = V_291 - V_290 ;
V_139 -> V_287 = V_288 ;
break;
}
}
F_17 ( & V_2 -> V_271 , V_14 ) ;
}
void F_94 ( unsigned long V_292 )
{
struct V_1 * V_2 = (struct V_1 * ) V_292 ;
struct V_270 * V_285 ;
unsigned long V_14 ;
T_3 V_293 = V_294 ;
if ( F_95 ( ! V_2 || ! V_2 -> V_17 ) ) {
F_96 ( L_16 ,
V_19 ) ;
return;
}
if ( F_32 ( ! V_2 -> V_17 -> V_286 ) )
return;
if ( ! V_2 -> V_295 ) {
F_2 ( V_2 -> V_17 , V_276 ,
L_17 ) ;
return;
}
V_2 -> V_281 = false ;
if ( F_10 ( & V_2 -> V_284 ) ) {
F_97 ( & V_2 -> V_296 ,
V_288 +
F_98 ( V_297 ) ) ;
return;
}
F_3 ( & V_2 -> V_271 , V_14 ) ;
F_19 (tdls_peer, &priv->auto_tdls_list, list) {
if ( ( V_288 - V_285 -> V_287 ) >
( V_298 * V_299 ) ) {
V_285 -> V_272 = 0 ;
V_285 -> V_282 = true ;
V_2 -> V_281 = true ;
}
if ( ( ( V_285 -> V_272 >= V_300 ) ||
! V_285 -> V_272 ) &&
V_285 -> V_233 == V_25 ) {
V_285 -> V_233 = V_242 ;
F_2 ( V_2 -> V_17 , V_247 ,
L_18 ,
V_285 -> V_267 , - V_285 -> V_272 ) ;
V_285 -> V_282 = true ;
V_2 -> V_281 = true ;
F_84 ( V_2 -> V_277 ,
V_285 -> V_267 ,
V_301 ,
V_293 , V_279 ) ;
} else if ( V_285 -> V_272 &&
V_285 -> V_272 <= V_273 &&
V_285 -> V_233 == V_243 &&
V_285 -> V_274 <
V_275 ) {
V_2 -> V_281 = true ;
V_285 -> V_280 = true ;
F_2 ( V_2 -> V_17 , V_276 ,
L_19
L_20 , V_285 -> V_267 ,
V_285 -> V_272 ) ;
}
}
F_17 ( & V_2 -> V_271 , V_14 ) ;
F_97 ( & V_2 -> V_296 ,
V_288 + F_98 ( V_297 ) ) ;
}
void F_99 ( struct V_1 * V_2 )
{
F_100 ( & V_2 -> V_296 , F_94 ,
( unsigned long ) V_2 ) ;
V_2 -> V_295 = true ;
F_97 ( & V_2 -> V_296 ,
V_288 + F_98 ( V_297 ) ) ;
}
void F_101 ( struct V_1 * V_2 )
{
if ( F_79 ( V_2 -> V_17 -> V_262 ) &&
V_2 -> V_17 -> V_286 &&
V_2 -> V_199 == V_263 ) {
V_2 -> V_295 = false ;
F_102 ( & V_2 -> V_296 ) ;
F_85 ( V_2 ) ;
}
}
