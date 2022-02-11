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
if ( F_9 ( V_4 ) ) {
V_6 = F_10 ( V_2 , V_15 , V_3 ) ;
V_6 -> V_25 = true ;
V_13 -> V_14 |= V_26 ;
} else {
V_8 = & V_2 -> V_20 . V_27 [ V_16 ] . V_6 ;
if ( ! F_11 ( V_8 ) )
V_6 = F_12 ( V_8 ,
struct V_5 , V_28 ) ;
else
V_6 = NULL ;
V_13 -> V_14 &= ~ V_26 ;
}
if ( ! V_6 ) {
F_13 ( V_2 -> V_17 , V_10 , 0 , - 1 ) ;
continue;
}
F_14 ( & V_6 -> V_29 , V_10 ) ;
V_6 -> V_30 ++ ;
V_6 -> V_31 ++ ;
if ( F_15 ( & V_2 -> V_20 . V_32 ) <
V_33 [ V_16 ] )
F_16 ( & V_2 -> V_20 . V_32 ,
V_33 [ V_16 ] ) ;
F_17 ( & V_2 -> V_20 . V_34 ) ;
}
F_18 ( & V_2 -> V_20 . V_21 , V_14 ) ;
return;
}
static void F_19 ( struct V_1 * V_2 ,
const T_1 * V_3 )
{
struct V_5 * V_6 ;
struct V_7 * V_35 ;
struct V_9 * V_10 , * V_11 ;
unsigned long V_14 ;
int V_36 ;
F_2 ( V_2 -> V_17 , V_18 , L_1 , V_19 , V_3 ) ;
F_3 ( & V_2 -> V_20 . V_21 , V_14 ) ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
if ( ! F_11 ( & V_2 -> V_20 . V_27 [ V_36 ] . V_6 ) ) {
V_35 = & V_2 -> V_20 . V_27 [ V_36 ] . V_6 ;
F_20 (ra_list, ra_list_head, list) {
F_4 (&ra_list->skb_head, skb,
tmp) {
if ( ! F_5 ( V_3 , V_10 -> V_22 ) )
continue;
F_6 ( V_10 , & V_6 -> V_29 ) ;
F_21 ( & V_2 -> V_20 . V_34 ) ;
V_6 -> V_31 -- ;
F_14 ( & V_2 -> V_23 , V_10 ) ;
}
}
}
}
F_18 ( & V_2 -> V_20 . V_21 , V_14 ) ;
return;
}
static int
F_22 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_38 [ V_39 ] , * V_40 ;
T_3 V_41 , V_42 , V_43 ;
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
V_41 = F_23 ( V_2 , V_38 ) ;
V_42 = F_24 ( T_3 , V_41 , V_44 ) ;
if ( F_25 ( V_10 ) < V_41 + 4 ) {
F_2 ( V_2 -> V_17 , ERROR ,
L_2 ) ;
return - V_45 ;
}
V_40 = F_26 ( V_10 , V_42 + 2 ) ;
* V_40 ++ = V_46 ;
* V_40 ++ = V_42 ;
memcpy ( V_40 , V_38 , V_42 ) ;
if ( V_41 > V_44 ) {
V_43 = V_41 - V_44 ;
V_40 = F_26 ( V_10 , V_43 + 2 ) ;
* V_40 ++ = V_47 ;
* V_40 ++ = V_43 ;
memcpy ( V_40 , V_38 + V_44 ,
V_43 ) ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_48 * V_49 ;
T_1 * V_40 ;
V_49 = (struct V_48 * ) & V_2 -> V_50 ;
V_40 = ( void * ) F_26 ( V_10 , 4 ) ;
* V_40 ++ = V_51 ;
* V_40 ++ = 2 ;
memcpy ( V_40 , & V_49 -> V_52 , sizeof( V_49 -> V_52 ) ) ;
return;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_53 V_54 ;
T_1 * V_40 ;
V_40 = ( void * ) F_26 ( V_10 , sizeof( struct V_53 ) + 2 ) ;
* V_40 ++ = V_55 ;
* V_40 ++ = sizeof( struct V_53 ) ;
memset ( & V_54 , 0 , sizeof( struct V_53 ) ) ;
F_29 ( V_2 , & V_54 , V_2 -> V_56 . V_57 ) ;
memcpy ( V_40 , & V_54 , sizeof( V_54 ) ) ;
return 0 ;
}
static int
F_30 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_1 V_58 , struct V_9 * V_10 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_63 * V_64 =
& V_2 -> V_56 . V_65 ;
T_1 * V_40 ;
V_62 = F_31 ( V_2 , V_3 ) ;
if ( F_32 ( ! V_62 ) ) {
F_2 ( V_2 -> V_17 , ERROR ,
L_3 ) ;
return - 1 ;
}
V_40 = ( void * ) F_26 ( V_10 , sizeof( struct V_59 ) + 2 ) ;
* V_40 ++ = V_66 ;
* V_40 ++ = sizeof( struct V_59 ) ;
V_60 = ( void * ) V_40 ;
V_60 -> V_67 = V_64 -> V_68 ;
if ( F_33 ( V_2 -> V_17 -> V_69 ) &&
V_64 -> V_70 &&
F_34 ( V_64 -> V_71 -> V_72 ) )
V_60 -> V_72 = V_64 -> V_71 -> V_72 ;
if ( V_58 ) {
V_60 -> V_72 =
F_35 ( V_64 -> V_68 ) ;
V_60 -> V_72 |= F_36 ( 2 ) ;
}
memcpy ( & V_62 -> V_73 . V_60 , V_60 ,
sizeof( struct V_59 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
const T_1 * V_3 , struct V_9 * V_10 )
{
struct V_63 * V_64 ;
struct V_74 * V_75 ;
struct V_53 * V_54 , * V_76 = NULL ;
struct V_61 * V_62 ;
struct V_77 * V_17 = V_2 -> V_17 ;
T_1 V_78 , V_79 ;
T_1 * V_40 , V_80 , V_81 ;
T_3 V_82 , V_83 , V_84 ;
T_3 V_85 , V_86 , V_87 ;
T_2 V_88 ;
V_64 = & V_2 -> V_56 . V_65 ;
V_62 = F_31 ( V_2 , V_3 ) ;
if ( F_32 ( ! V_62 ) ) {
F_2 ( V_17 , ERROR ,
L_3 ) ;
return - 1 ;
}
if ( ! F_38 ( V_2 ) ) {
if ( V_62 -> V_73 . V_89 . V_90 [ 7 ] &
V_91 ) {
F_2 ( V_17 , V_92 ,
L_4 ) ;
return 0 ;
}
} else {
V_76 = V_64 -> V_93 ;
}
V_40 = ( void * ) F_26 ( V_10 , sizeof( struct V_74 ) + 2 ) ;
* V_40 ++ = V_94 ;
* V_40 ++ = sizeof( struct V_74 ) ;
V_75 = (struct V_74 * ) V_40 ;
if ( V_64 -> V_95 & V_96 )
V_88 = V_17 -> V_97 ;
else
V_88 = V_17 -> V_98 ;
V_54 = & V_62 -> V_73 . V_99 ;
V_78 = F_39 ( V_88 ) ;
V_79 =
F_39 ( F_40 ( V_54 -> V_100 ) ) ;
V_78 = F_24 ( T_1 , V_78 , V_79 ) ;
if ( V_76 && V_62 -> V_73 . V_89 . V_90 [ 7 ] &
V_91 ) {
V_80 =
F_39 ( F_40 ( V_76 -> V_100 ) ) ;
V_78 = F_24 ( T_1 , V_78 , V_80 ) ;
}
switch ( V_78 ) {
case V_101 :
V_75 -> V_102 = V_101 ;
break;
case V_103 :
V_75 -> V_102 = V_103 ;
break;
case V_104 :
V_75 -> V_102 = V_104 ;
break;
default:
V_75 -> V_102 = V_105 ;
break;
}
V_82 = F_41 ( V_17 -> V_106 ) ;
V_83 = F_42 ( V_54 -> V_107 . V_108 ) ;
V_84 = 0 ;
for ( V_87 = 1 ; V_87 <= 8 ; V_87 ++ ) {
V_85 = F_43 ( V_82 , V_87 ) ;
V_86 = F_43 ( V_83 , V_87 ) ;
if ( ( V_85 == V_109 ) ||
( V_86 == V_109 ) )
F_44 ( V_84 , V_87 ,
V_109 ) ;
else
F_44 ( V_84 , V_87 ,
F_24 ( T_3 , V_85 , V_86 ) ) ;
}
V_75 -> V_110 = F_45 ( V_84 ) ;
switch ( V_75 -> V_102 ) {
case V_101 :
V_81 = V_101 ;
break;
case V_103 :
V_81 = V_103 ;
break;
case V_104 :
V_81 = V_101 ;
break;
default:
V_81 = V_105 ;
break;
}
V_75 -> V_111 =
F_46 ( V_2 , V_112 ,
V_64 -> V_68 ,
V_81 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_113 * V_89 ;
V_89 = ( void * ) F_26 ( V_10 , sizeof( struct V_113 ) ) ;
V_89 -> V_114 . V_115 = V_116 ;
V_89 -> V_114 . V_117 = 8 ;
memset ( V_89 -> V_90 , 0 , 8 ) ;
V_89 -> V_90 [ 4 ] |= V_118 ;
V_89 -> V_90 [ 3 ] |= V_119 ;
if ( V_2 -> V_17 -> V_120 )
V_89 -> V_90 [ 7 ] |= V_91 ;
}
static void F_48 ( struct V_9 * V_10 )
{
T_1 * V_40 = ( void * ) F_26 ( V_10 , 3 ) ;
* V_40 ++ = V_121 ;
* V_40 ++ = 1 ;
* V_40 ++ = V_122 ;
}
static void
F_49 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_123 * V_20 ;
T_1 V_124 [] = { 0x42 , 0x43 , 0x5e , 0x00 } ;
T_1 V_125 [] = { 0x62 , 0x32 , 0x2f , 0x00 } ;
T_1 V_126 [] = { 0x03 , 0xa4 , 0x00 , 0x00 } ;
T_1 V_127 [] = { 0x27 , 0xa4 , 0x00 , 0x00 } ;
V_20 = ( void * ) F_26 ( V_10 , sizeof( * V_20 ) ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_115 = V_128 ;
V_20 -> V_117 = sizeof( * V_20 ) - 2 ;
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
F_50 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_1 V_135 )
{
T_1 * V_136 ;
V_136 = ( void * ) F_26 ( V_10 , V_137 +
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
static int F_51 ( struct V_1 * V_2 ,
const T_1 * V_139 , T_1 V_140 ,
T_1 V_141 ,
T_3 V_142 , struct V_9 * V_10 )
{
struct V_143 * V_144 ;
int V_145 ;
T_3 V_146 ;
struct V_147 * V_148 ;
T_1 V_149 , * V_40 ;
V_146 = V_2 -> V_56 . V_65 . V_150 ;
V_144 = ( void * ) F_26 ( V_10 , F_52 ( struct V_143 , V_151 ) ) ;
memcpy ( V_144 -> V_152 , V_139 , V_153 ) ;
memcpy ( V_144 -> V_154 , V_2 -> V_155 , V_153 ) ;
V_144 -> V_156 = F_53 ( V_157 ) ;
V_144 -> V_158 = V_159 ;
switch ( V_140 ) {
case V_160 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_160 ;
F_26 ( V_10 , sizeof( V_144 -> V_151 . V_163 ) ) ;
V_144 -> V_151 . V_163 . V_141 = V_141 ;
V_144 -> V_151 . V_163 . V_164 = F_45 ( V_146 ) ;
V_145 = F_22 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
V_40 = ( void * ) F_26 ( V_10 , sizeof( struct V_147 ) + 2 ) ;
* V_40 ++ = V_165 ;
* V_40 ++ = sizeof( struct V_147 ) ;
V_148 = ( void * ) V_40 ;
V_149 = F_55 ( V_2 -> V_56 . V_57 ) ;
V_145 = F_56 ( V_2 , V_149 , V_148 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
if ( V_2 -> V_17 -> V_120 ) {
V_145 = F_28 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_47 ( V_2 , V_10 ) ;
F_48 ( V_10 ) ;
F_50 ( V_2 , V_10 , 0 ) ;
break;
case V_166 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_166 ;
F_26 ( V_10 , sizeof( V_144 -> V_151 . V_167 ) ) ;
V_144 -> V_151 . V_167 . V_142 = F_45 ( V_142 ) ;
V_144 -> V_151 . V_167 . V_141 = V_141 ;
V_144 -> V_151 . V_167 . V_164 = F_45 ( V_146 ) ;
V_145 = F_22 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
V_40 = ( void * ) F_26 ( V_10 , sizeof( struct V_147 ) + 2 ) ;
* V_40 ++ = V_165 ;
* V_40 ++ = sizeof( struct V_147 ) ;
V_148 = ( void * ) V_40 ;
V_149 = F_55 ( V_2 -> V_56 . V_57 ) ;
V_145 = F_56 ( V_2 , V_149 , V_148 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
if ( V_2 -> V_17 -> V_120 ) {
V_145 = F_28 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_47 ( V_2 , V_10 ) ;
F_48 ( V_10 ) ;
F_50 ( V_2 , V_10 , 0 ) ;
break;
case V_168 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_168 ;
F_26 ( V_10 , sizeof( V_144 -> V_151 . V_169 ) ) ;
V_144 -> V_151 . V_169 . V_142 = F_45 ( V_142 ) ;
V_144 -> V_151 . V_169 . V_141 = V_141 ;
F_49 ( V_2 , V_10 ) ;
if ( V_2 -> V_17 -> V_120 ) {
V_145 = F_37 ( V_2 , V_139 , V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
V_145 = F_30 ( V_2 , V_139 , 1 , V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
} else {
V_145 = F_30 ( V_2 , V_139 , 0 , V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
}
break;
case V_170 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_170 ;
F_26 ( V_10 , sizeof( V_144 -> V_151 . V_171 ) ) ;
V_144 -> V_151 . V_171 . V_172 = F_45 ( V_142 ) ;
break;
case V_173 :
V_144 -> V_161 = V_162 ;
V_144 -> V_140 = V_173 ;
F_26 ( V_10 , sizeof( V_144 -> V_151 . V_174 ) ) ;
V_144 -> V_151 . V_174 . V_141 = V_141 ;
break;
default:
F_2 ( V_2 -> V_17 , ERROR , L_5 ) ;
return - V_175 ;
}
return 0 ;
}
static void
F_57 ( struct V_9 * V_10 , const T_1 * V_176 ,
const T_1 * V_139 , const T_1 * V_177 )
{
struct V_178 * V_179 ;
V_179 = ( void * ) F_26 ( V_10 , sizeof( struct V_178 ) ) ;
V_179 -> V_180 = V_181 ;
V_179 -> V_182 = sizeof( struct V_178 ) -
sizeof( struct V_138 ) ;
memcpy ( V_179 -> V_177 , V_177 , V_153 ) ;
memcpy ( V_179 -> V_183 , V_176 , V_153 ) ;
memcpy ( V_179 -> V_184 , V_139 , V_153 ) ;
}
int F_58 ( struct V_1 * V_2 , const T_1 * V_139 ,
T_1 V_140 , T_1 V_141 ,
T_3 V_142 , const T_1 * V_185 ,
T_4 V_186 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
int V_145 ;
T_3 V_187 ;
V_187 = V_188 +
F_59 ( sizeof( struct V_189 ) ,
sizeof( struct V_143 ) ) +
V_190 +
V_39 +
3 +
sizeof( struct V_113 ) +
sizeof( struct V_147 ) +
sizeof( struct V_191 ) +
sizeof( struct V_59 ) +
sizeof( struct V_178 ) +
sizeof( struct V_123 ) +
V_186 ;
if ( V_2 -> V_17 -> V_120 )
V_187 += sizeof( struct V_192 ) +
sizeof( struct V_193 ) +
sizeof( struct V_194 ) ;
V_10 = F_60 ( V_187 ) ;
if ( ! V_10 ) {
F_2 ( V_2 -> V_17 , ERROR ,
L_6 ) ;
return - V_45 ;
}
F_61 ( V_10 , V_188 ) ;
switch ( V_140 ) {
case V_160 :
case V_168 :
case V_170 :
case V_173 :
V_145 = F_51 ( V_2 , V_139 , V_140 ,
V_141 , V_142 ,
V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
if ( V_186 )
memcpy ( F_26 ( V_10 , V_186 ) , V_185 ,
V_186 ) ;
F_57 ( V_10 , V_2 -> V_155 , V_139 ,
V_2 -> V_195 ) ;
break;
case V_166 :
V_145 = F_51 ( V_2 , V_139 , V_140 ,
V_141 , V_142 ,
V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
if ( V_186 )
memcpy ( F_26 ( V_10 , V_186 ) , V_185 ,
V_186 ) ;
F_57 ( V_10 , V_139 , V_2 -> V_155 ,
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
F_62 ( V_10 ) ;
F_63 ( V_2 , V_10 ) ;
return 0 ;
}
static int
F_64 ( struct V_1 * V_2 ,
const T_1 * V_139 ,
T_1 V_140 , T_1 V_141 ,
T_3 V_142 , struct V_9 * V_10 )
{
struct V_189 * V_200 ;
T_1 V_201 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_145 ;
T_3 V_146 ;
struct V_147 * V_148 ;
T_1 V_149 , * V_40 ;
V_146 = V_2 -> V_56 . V_65 . V_150 ;
V_200 = ( void * ) F_26 ( V_10 , F_52 ( struct V_189 , V_151 ) ) ;
memset ( V_200 , 0 , 24 ) ;
memcpy ( V_200 -> V_152 , V_139 , V_153 ) ;
memcpy ( V_200 -> V_154 , V_2 -> V_155 , V_153 ) ;
memcpy ( V_200 -> V_177 , V_2 -> V_195 , V_153 ) ;
V_200 -> V_202 = F_45 ( V_203 |
V_204 ) ;
V_40 = F_26 ( V_10 , V_153 ) ;
switch ( V_140 ) {
case V_205 :
F_26 ( V_10 , sizeof( V_200 -> V_151 . V_206 . V_151 . V_207 ) + 1 ) ;
V_200 -> V_151 . V_206 . V_161 = V_208 ;
V_200 -> V_151 . V_206 . V_151 . V_207 . V_140 =
V_205 ;
V_200 -> V_151 . V_206 . V_151 . V_207 . V_141 =
V_141 ;
V_200 -> V_151 . V_206 . V_151 . V_207 . V_164 =
F_45 ( V_146 ) ;
memmove ( V_40 + V_153 , & V_200 -> V_151 . V_206 . V_161 ,
sizeof( V_200 -> V_151 . V_206 . V_151 . V_207 ) ) ;
memcpy ( V_40 , V_201 , V_153 ) ;
V_145 = F_22 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
V_40 = ( void * ) F_26 ( V_10 , sizeof( struct V_147 ) + 2 ) ;
* V_40 ++ = V_165 ;
* V_40 ++ = sizeof( struct V_147 ) ;
V_148 = ( void * ) V_40 ;
V_149 = F_55 ( V_2 -> V_56 . V_57 ) ;
V_145 = F_56 ( V_2 , V_149 , V_148 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
if ( V_2 -> V_17 -> V_120 ) {
V_145 = F_28 ( V_2 , V_10 ) ;
if ( V_145 ) {
F_54 ( V_10 ) ;
return V_145 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_47 ( V_2 , V_10 ) ;
F_48 ( V_10 ) ;
break;
default:
F_2 ( V_2 -> V_17 , ERROR , L_7 ) ;
return - V_175 ;
}
return 0 ;
}
int F_65 ( struct V_1 * V_2 , const T_1 * V_139 ,
T_1 V_140 , T_1 V_141 ,
T_3 V_142 , const T_1 * V_185 ,
T_4 V_186 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
T_1 * V_40 ;
T_2 V_209 , V_210 ;
T_3 V_211 , V_187 ;
V_187 = V_188 +
F_59 ( sizeof( struct V_189 ) ,
sizeof( struct V_143 ) ) +
V_190 +
V_39 +
sizeof( struct V_113 ) +
sizeof( struct V_147 ) +
sizeof( struct V_191 ) +
sizeof( struct V_59 ) +
sizeof( struct V_178 ) +
V_186 +
3 +
V_153 ;
if ( V_2 -> V_17 -> V_120 )
V_187 += sizeof( struct V_192 ) +
sizeof( struct V_193 ) +
sizeof( struct V_194 ) ;
V_10 = F_60 ( V_187 ) ;
if ( ! V_10 ) {
F_2 ( V_2 -> V_17 , ERROR ,
L_6 ) ;
return - V_45 ;
}
F_61 ( V_10 , V_188 ) ;
V_209 = V_212 ;
V_210 = 0 ;
V_40 = F_26 ( V_10 , V_190 + sizeof( V_211 ) ) ;
memset ( V_40 , 0 , V_190 + sizeof( V_211 ) ) ;
memcpy ( V_40 , & V_209 , sizeof( V_209 ) ) ;
memcpy ( V_40 + sizeof( V_209 ) , & V_210 , sizeof( V_210 ) ) ;
if ( F_64 ( V_2 , V_139 , V_140 ,
V_141 , V_142 ,
V_10 ) ) {
F_54 ( V_10 ) ;
return - V_175 ;
}
if ( V_186 )
memcpy ( F_26 ( V_10 , V_186 ) , V_185 , V_186 ) ;
F_57 ( V_10 , V_139 , V_2 -> V_155 ,
V_2 -> V_195 ) ;
V_10 -> V_24 = V_197 ;
V_13 = F_7 ( V_10 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_198 = V_2 -> V_198 ;
V_13 -> V_199 = V_2 -> V_199 ;
V_13 -> V_14 |= V_26 ;
V_211 = V_10 -> V_117 - V_190 - sizeof( V_211 ) ;
memcpy ( V_10 -> V_22 + V_190 , & V_211 ,
sizeof( V_211 ) ) ;
F_62 ( V_10 ) ;
F_63 ( V_2 , V_10 ) ;
return 0 ;
}
void F_66 ( struct V_1 * V_2 ,
T_1 * V_136 , int V_117 )
{
struct V_61 * V_62 ;
T_1 * V_139 , * V_40 , * V_213 ;
T_1 V_36 , V_206 , V_214 ;
T_5 V_215 = 0 ;
int V_182 = 0 ;
if ( V_117 < ( sizeof( struct V_216 ) + 3 ) )
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
if ( V_117 < ( sizeof( struct V_216 ) + V_217 ) )
return;
V_40 = V_136 + sizeof( struct V_216 ) + 4 ;
V_215 = F_45 ( * ( T_3 * ) V_40 ) ;
V_182 = V_117 - sizeof( struct V_216 ) - V_217 ;
V_40 += 2 ;
break;
case V_166 :
if ( V_117 < ( sizeof( struct V_216 ) + V_218 ) )
return;
V_40 = V_136 + sizeof( struct V_216 ) + 6 ;
V_215 = F_45 ( * ( T_3 * ) V_40 ) ;
V_182 = V_117 - sizeof( struct V_216 ) - V_218 ;
V_40 += 2 ;
break;
case V_168 :
if ( V_117 < ( sizeof( struct V_216 ) + V_219 ) )
return;
V_40 = V_136 + sizeof( struct V_216 ) + V_219 ;
V_182 = V_117 - sizeof( struct V_216 ) - V_219 ;
break;
default:
F_2 ( V_2 -> V_17 , ERROR , L_5 ) ;
return;
}
V_62 = F_67 ( V_2 , V_139 ) ;
if ( ! V_62 )
return;
V_62 -> V_73 . V_146 = V_215 ;
for ( V_213 = V_40 + V_182 ; V_40 + 1 < V_213 ; V_40 += 2 + V_40 [ 1 ] ) {
if ( V_40 + 2 + V_40 [ 1 ] > V_213 )
break;
switch ( * V_40 ) {
case V_46 :
V_62 -> V_73 . V_220 = V_40 [ 1 ] ;
for ( V_36 = 0 ; V_36 < V_40 [ 1 ] ; V_36 ++ )
V_62 -> V_73 . V_38 [ V_36 ] = V_40 [ V_36 + 2 ] ;
break;
case V_47 :
V_214 = V_62 -> V_73 . V_220 ;
for ( V_36 = 0 ; V_36 < V_40 [ 1 ] ; V_36 ++ )
V_62 -> V_73 . V_38 [ V_214 + V_36 ] = V_40 [ V_36 + 2 ] ;
V_62 -> V_73 . V_220 += V_40 [ 1 ] ;
break;
case V_165 :
memcpy ( ( T_1 * ) & V_62 -> V_73 . V_221 , V_40 ,
sizeof( struct V_147 ) ) ;
V_62 -> V_222 = 1 ;
break;
case V_66 :
memcpy ( & V_62 -> V_73 . V_60 , V_40 ,
sizeof( struct V_59 ) ) ;
break;
case V_223 :
V_62 -> V_73 . V_224 = V_40 [ 2 ] ;
break;
case V_116 :
memcpy ( ( T_1 * ) & V_62 -> V_73 . V_89 , V_40 ,
sizeof( struct V_138 ) +
F_24 ( T_1 , V_40 [ 1 ] , 8 ) ) ;
break;
case V_225 :
memcpy ( ( T_1 * ) & V_62 -> V_73 . V_226 , V_40 ,
sizeof( struct V_138 ) +
F_24 ( T_1 , V_40 [ 1 ] , V_227 -
sizeof( struct V_138 ) ) ) ;
break;
case V_121 :
V_62 -> V_73 . V_133 = V_40 [ 2 ] ;
break;
case V_94 :
if ( V_2 -> V_17 -> V_120 )
memcpy ( & V_62 -> V_73 . V_228 , V_40 ,
sizeof( struct V_74 ) ) ;
break;
case V_55 :
if ( V_2 -> V_17 -> V_120 ) {
memcpy ( ( T_1 * ) & V_62 -> V_73 . V_99 , V_40 ,
sizeof( struct V_53 ) ) ;
V_62 -> V_229 = 1 ;
}
break;
case V_51 :
if ( V_2 -> V_17 -> V_120 )
V_62 -> V_73 . V_230 =
F_42 ( * ( T_5 * ) ( V_40 + 2 ) ) ;
default:
break;
}
}
return;
}
static int
F_68 ( struct V_1 * V_2 , const T_1 * V_139 )
{
struct V_61 * V_62 ;
struct V_231 V_232 ;
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
V_62 = F_31 ( V_2 , V_139 ) ;
if ( ! V_62 || V_62 -> V_233 == V_234 ) {
F_2 ( V_2 -> V_17 , ERROR ,
L_9 , V_139 ) ;
return - V_175 ;
}
memcpy ( & V_232 . V_235 , V_139 , V_153 ) ;
V_232 . V_236 = V_237 ;
return F_69 ( V_2 , V_238 ,
V_239 , 0 , & V_232 , true ) ;
}
static int
F_70 ( struct V_1 * V_2 , const T_1 * V_139 )
{
struct V_61 * V_62 ;
struct V_231 V_232 ;
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
V_62 = F_31 ( V_2 , V_139 ) ;
if ( V_62 && V_62 -> V_233 == V_240 ) {
F_2 ( V_2 -> V_17 , V_92 ,
L_10 , V_139 ) ;
return 0 ;
}
V_62 = F_67 ( V_2 , V_139 ) ;
if ( ! V_62 )
return - V_45 ;
V_62 -> V_233 = V_240 ;
F_19 ( V_2 , V_139 ) ;
memcpy ( & V_232 . V_235 , V_139 , V_153 ) ;
V_232 . V_236 = V_241 ;
return F_69 ( V_2 , V_238 ,
V_239 , 0 , & V_232 , true ) ;
}
static int
F_71 ( struct V_1 * V_2 , const T_1 * V_139 )
{
struct V_61 * V_62 ;
struct V_231 V_232 ;
unsigned long V_14 ;
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
V_62 = F_31 ( V_2 , V_139 ) ;
if ( V_62 ) {
if ( V_62 -> V_222 ) {
F_72 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_73 ( V_2 ) ;
F_18 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_74 ( V_2 , V_139 ) ;
}
F_1 ( V_2 , V_139 , V_242 ) ;
F_75 ( V_2 , V_139 , V_243 ) ;
memcpy ( & V_232 . V_235 , V_139 , V_153 ) ;
V_232 . V_236 = V_244 ;
return F_69 ( V_2 , V_238 ,
V_239 , 0 , & V_232 , true ) ;
}
static int
F_76 ( struct V_1 * V_2 , const T_1 * V_139 )
{
struct V_61 * V_62 ;
struct V_245 V_246 ;
unsigned long V_14 ;
int V_36 ;
V_62 = F_31 ( V_2 , V_139 ) ;
if ( V_62 && ( V_62 -> V_233 != V_234 ) ) {
F_2 ( V_2 -> V_17 , V_247 ,
L_11 , V_139 ) ;
V_62 -> V_233 = V_248 ;
V_246 = V_62 -> V_73 . V_221 . V_246 ;
if ( V_246 . V_249 [ 0 ] != 0xff )
V_62 -> V_222 = true ;
if ( V_62 -> V_222 ) {
if ( F_42 ( V_62 -> V_73 . V_221 . V_250 ) &
V_251 )
V_62 -> V_252 =
V_253 ;
else
V_62 -> V_252 =
V_254 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_62 -> V_255 [ V_36 ] =
V_2 -> V_256 [ V_36 ] . V_257 ;
} else {
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_62 -> V_255 [ V_36 ] = V_258 ;
}
if ( V_62 -> V_73 . V_89 . V_90 [ 3 ] &
V_119 ) {
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
}
memset ( V_62 -> V_259 , 0xff , sizeof( V_62 -> V_259 ) ) ;
F_1 ( V_2 , V_139 , V_248 ) ;
F_75 ( V_2 , V_139 ,
V_248 ) ;
} else {
F_2 ( V_2 -> V_17 , ERROR ,
L_12 , V_139 ) ;
if ( V_62 ) {
F_72 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_73 ( V_2 ) ;
F_18 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_74 ( V_2 , V_139 ) ;
}
F_1 ( V_2 , V_139 , V_242 ) ;
F_75 ( V_2 , V_139 ,
V_243 ) ;
return - 1 ;
}
return 0 ;
}
int F_79 ( struct V_1 * V_2 , const T_1 * V_139 , T_1 V_206 )
{
switch ( V_206 ) {
case V_260 :
return F_76 ( V_2 , V_139 ) ;
case V_244 :
return F_71 ( V_2 , V_139 ) ;
case V_241 :
return F_70 ( V_2 , V_139 ) ;
case V_237 :
return F_68 ( V_2 , V_139 ) ;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_61 * V_62 ;
V_62 = F_31 ( V_2 , V_3 ) ;
if ( V_62 )
return V_62 -> V_233 ;
return V_243 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_261 * V_136 )
{
struct V_61 * V_62 ;
struct V_261 * V_139 = V_136 ;
int V_262 = 0 ;
unsigned long V_14 ;
if ( ! F_82 ( V_2 -> V_17 -> V_263 ) )
return 0 ;
if ( ! ( V_2 -> V_199 == V_264 && V_2 -> V_265 ) )
return 0 ;
F_3 ( & V_2 -> V_266 , V_14 ) ;
F_20 (sta_ptr, &priv->sta_list, list) {
if ( F_9 ( V_62 -> V_233 ) ) {
F_83 ( V_139 -> V_267 , V_62 -> V_268 ) ;
V_139 ++ ;
V_262 ++ ;
if ( V_262 >= V_269 )
break;
}
}
F_18 ( & V_2 -> V_266 , V_14 ) ;
return V_262 ;
}
void F_84 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
struct V_231 V_232 ;
unsigned long V_14 ;
if ( F_11 ( & V_2 -> V_270 ) )
return;
F_20 (sta_ptr, &priv->sta_list, list) {
memset ( & V_232 , 0 , sizeof( struct V_231 ) ) ;
if ( V_62 -> V_222 ) {
F_72 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_73 ( V_2 ) ;
F_18 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_1 ( V_2 , V_62 -> V_268 ,
V_242 ) ;
memcpy ( & V_232 . V_235 , V_62 -> V_268 , V_153 ) ;
V_232 . V_236 = V_244 ;
if ( F_69 ( V_2 , V_238 ,
V_239 , 0 , & V_232 , false ) )
F_2 ( V_2 -> V_17 , ERROR ,
L_13 ,
V_62 -> V_268 ) ;
}
F_85 ( V_2 ) ;
}
int F_86 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_271 * V_139 ;
unsigned long V_14 ;
T_1 V_3 [ V_153 ] ;
F_83 ( V_3 , V_10 -> V_22 ) ;
F_3 ( & V_2 -> V_272 , V_14 ) ;
F_20 (peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_3 , V_139 -> V_268 , V_153 ) ) {
if ( V_139 -> V_273 <= V_274 &&
V_139 -> V_233 == V_243 &&
( V_139 -> V_275 <
V_276 ) ) {
V_139 -> V_233 = V_240 ;
F_2 ( V_2 -> V_17 , V_277 ,
L_14 ,
V_139 -> V_268 , V_139 -> V_273 ) ;
F_87 ( V_2 -> V_278 ,
V_139 -> V_268 ,
V_279 ,
0 , V_280 ) ;
V_139 -> V_281 = false ;
V_2 -> V_282 = false ;
} else if ( V_139 -> V_275 <
V_276 &&
V_139 -> V_283 ) {
F_58 ( V_2 ,
V_139 -> V_268 ,
V_173 ,
1 , 0 , NULL , 0 ) ;
V_139 -> V_283 = false ;
}
}
}
F_18 ( & V_2 -> V_272 , V_14 ) ;
return 0 ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_271 * V_139 , * V_284 ;
unsigned long V_14 ;
F_3 ( & V_2 -> V_272 , V_14 ) ;
F_89 (peer, tmp_node, &priv->auto_tdls_list, list) {
F_90 ( & V_139 -> V_28 ) ;
F_91 ( V_139 ) ;
}
F_92 ( & V_2 -> V_285 ) ;
F_18 ( & V_2 -> V_272 , V_14 ) ;
V_2 -> V_282 = false ;
}
void F_93 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_271 * V_286 ;
unsigned long V_14 ;
if ( ! V_2 -> V_17 -> V_287 )
return;
F_3 ( & V_2 -> V_272 , V_14 ) ;
F_20 (tdls_peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_286 -> V_268 , V_3 , V_153 ) ) {
V_286 -> V_233 = V_240 ;
V_286 -> V_288 = V_289 ;
F_18 ( & V_2 -> V_272 , V_14 ) ;
return;
}
}
V_286 = F_94 ( sizeof( * V_286 ) , V_280 ) ;
if ( V_286 ) {
F_83 ( V_286 -> V_268 , V_3 ) ;
V_286 -> V_233 = V_240 ;
V_286 -> V_288 = V_289 ;
F_92 ( & V_286 -> V_28 ) ;
F_95 ( & V_286 -> V_28 , & V_2 -> V_285 ) ;
F_2 ( V_2 -> V_17 , V_277 ,
L_15 , V_3 ) ;
}
F_18 ( & V_2 -> V_272 , V_14 ) ;
}
void F_75 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_1 V_290 )
{
struct V_271 * V_139 ;
unsigned long V_14 ;
if ( ! V_2 -> V_17 -> V_287 )
return;
F_3 ( & V_2 -> V_272 , V_14 ) ;
F_20 (peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_139 -> V_268 , V_3 , V_153 ) ) {
if ( ( V_290 == V_243 ) &&
( V_139 -> V_233 == V_240 ) )
V_139 -> V_275 ++ ;
else if ( F_9 ( V_290 ) )
V_139 -> V_275 = 0 ;
V_139 -> V_233 = V_290 ;
break;
}
}
F_18 ( & V_2 -> V_272 , V_14 ) ;
}
void F_96 ( struct V_1 * V_2 ,
T_1 * V_3 , T_6 V_291 , T_6 V_292 )
{
struct V_271 * V_139 ;
unsigned long V_14 ;
if ( ! V_2 -> V_17 -> V_287 )
return;
F_3 ( & V_2 -> V_272 , V_14 ) ;
F_20 (peer, &priv->auto_tdls_list, list) {
if ( ! memcmp ( V_139 -> V_268 , V_3 , V_153 ) ) {
V_139 -> V_273 = V_292 - V_291 ;
V_139 -> V_288 = V_289 ;
break;
}
}
F_18 ( & V_2 -> V_272 , V_14 ) ;
}
void F_97 ( unsigned long V_293 )
{
struct V_1 * V_2 = (struct V_1 * ) V_293 ;
struct V_271 * V_286 ;
unsigned long V_14 ;
T_3 V_294 = V_295 ;
if ( F_98 ( ! V_2 || ! V_2 -> V_17 ) ) {
F_99 ( L_16 ,
V_19 ) ;
return;
}
if ( F_32 ( ! V_2 -> V_17 -> V_287 ) )
return;
if ( ! V_2 -> V_296 ) {
F_2 ( V_2 -> V_17 , V_277 ,
L_17 ) ;
return;
}
V_2 -> V_282 = false ;
if ( F_11 ( & V_2 -> V_285 ) ) {
F_100 ( & V_2 -> V_297 ,
V_289 +
F_101 ( V_298 ) ) ;
return;
}
F_3 ( & V_2 -> V_272 , V_14 ) ;
F_20 (tdls_peer, &priv->auto_tdls_list, list) {
if ( ( V_289 - V_286 -> V_288 ) >
( V_299 * V_300 ) ) {
V_286 -> V_273 = 0 ;
V_286 -> V_283 = true ;
V_2 -> V_282 = true ;
}
if ( ( ( V_286 -> V_273 >= V_301 ) ||
! V_286 -> V_273 ) &&
F_9 ( V_286 -> V_233 ) ) {
V_286 -> V_233 = V_242 ;
F_2 ( V_2 -> V_17 , V_247 ,
L_18 ,
V_286 -> V_268 , - V_286 -> V_273 ) ;
V_286 -> V_283 = true ;
V_2 -> V_282 = true ;
F_87 ( V_2 -> V_278 ,
V_286 -> V_268 ,
V_302 ,
V_294 , V_280 ) ;
} else if ( V_286 -> V_273 &&
V_286 -> V_273 <= V_274 &&
V_286 -> V_233 == V_243 &&
V_286 -> V_275 <
V_276 ) {
V_2 -> V_282 = true ;
V_286 -> V_281 = true ;
F_2 ( V_2 -> V_17 , V_277 ,
L_19
L_20 , V_286 -> V_268 ,
V_286 -> V_273 ) ;
}
}
F_18 ( & V_2 -> V_272 , V_14 ) ;
F_100 ( & V_2 -> V_297 ,
V_289 + F_101 ( V_298 ) ) ;
}
void F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_297 , F_97 ,
( unsigned long ) V_2 ) ;
V_2 -> V_296 = true ;
F_100 ( & V_2 -> V_297 ,
V_289 + F_101 ( V_298 ) ) ;
}
void F_104 ( struct V_1 * V_2 )
{
if ( F_82 ( V_2 -> V_17 -> V_263 ) &&
V_2 -> V_17 -> V_287 &&
V_2 -> V_199 == V_264 ) {
V_2 -> V_296 = false ;
F_105 ( & V_2 -> V_297 ) ;
F_88 ( V_2 ) ;
}
}
static int F_106 ( struct V_1 * V_2 , T_1 V_303 )
{
struct V_304 V_305 ;
V_305 . V_303 = F_45 ( V_303 ) ;
return F_69 ( V_2 , V_306 ,
V_307 , 0 , & V_305 , true ) ;
}
int F_77 ( struct V_1 * V_2 )
{
return F_106 ( V_2 , true ) ;
}
int F_107 ( struct V_1 * V_2 )
{
return F_106 ( V_2 , false ) ;
}
int F_78 ( struct V_1 * V_2 )
{
struct V_308 V_309 ;
V_309 . V_310 = V_311 ;
V_309 . V_312 = V_313 ;
V_309 . V_314 = V_315 ;
return F_69 ( V_2 , V_306 ,
V_316 , 0 ,
& V_309 , true ) ;
}
int F_108 ( struct V_1 * V_2 , const T_1 * V_235 )
{
struct V_317 V_318 ;
F_83 ( V_318 . V_235 , V_235 ) ;
return F_69 ( V_2 , V_306 ,
V_319 , 0 ,
& V_318 , true ) ;
}
int F_109 ( struct V_1 * V_2 , const T_1 * V_235 ,
T_1 V_67 , T_1 V_320 , T_1 V_57 )
{
struct V_321 V_322 ;
F_83 ( V_322 . V_235 , V_235 ) ;
V_322 . V_67 = V_67 ;
V_322 . V_320 = V_320 ;
V_322 . V_57 = V_57 ;
V_322 . V_323 = F_45 ( V_324 ) ;
V_322 . V_325 =
F_45 ( V_326 ) ;
V_322 . V_327 = V_328 ;
V_322 . V_329 = V_330 ;
return F_69 ( V_2 , V_306 ,
V_331 , 0 ,
& V_322 , true ) ;
}
