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
static int F_50 ( struct V_1 * V_2 ,
const T_1 * V_122 , T_1 V_123 ,
T_1 V_124 ,
T_3 V_125 , struct V_9 * V_10 )
{
struct V_126 * V_127 ;
int V_128 ;
T_3 V_129 ;
struct V_130 * V_131 ;
T_1 V_132 , * V_41 ;
V_129 = V_2 -> V_57 . V_66 . V_133 ;
V_127 = ( void * ) F_26 ( V_10 , F_51 ( struct V_126 , V_134 ) ) ;
memcpy ( V_127 -> V_135 , V_122 , V_136 ) ;
memcpy ( V_127 -> V_137 , V_2 -> V_138 , V_136 ) ;
V_127 -> V_139 = F_52 ( V_140 ) ;
V_127 -> V_141 = V_142 ;
switch ( V_123 ) {
case V_143 :
V_127 -> V_144 = V_145 ;
V_127 -> V_123 = V_143 ;
F_26 ( V_10 , sizeof( V_127 -> V_134 . V_146 ) ) ;
V_127 -> V_134 . V_146 . V_124 = V_124 ;
V_127 -> V_134 . V_146 . V_147 = F_46 ( V_129 ) ;
V_128 = F_21 ( V_2 , V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_130 ) + 2 ) ;
* V_41 ++ = V_148 ;
* V_41 ++ = sizeof( struct V_130 ) ;
V_131 = ( void * ) V_41 ;
V_132 = F_54 ( V_2 -> V_57 . V_58 ) ;
V_128 = F_55 ( V_2 , V_132 , V_131 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
if ( V_2 -> V_17 -> V_119 ) {
V_128 = F_29 ( V_2 , V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_48 ( V_2 , V_10 ) ;
F_49 ( V_10 ) ;
break;
case V_149 :
V_127 -> V_144 = V_145 ;
V_127 -> V_123 = V_149 ;
F_26 ( V_10 , sizeof( V_127 -> V_134 . V_150 ) ) ;
V_127 -> V_134 . V_150 . V_125 = F_46 ( V_125 ) ;
V_127 -> V_134 . V_150 . V_124 = V_124 ;
V_127 -> V_134 . V_150 . V_147 = F_46 ( V_129 ) ;
V_128 = F_21 ( V_2 , V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_130 ) + 2 ) ;
* V_41 ++ = V_148 ;
* V_41 ++ = sizeof( struct V_130 ) ;
V_131 = ( void * ) V_41 ;
V_132 = F_54 ( V_2 -> V_57 . V_58 ) ;
V_128 = F_55 ( V_2 , V_132 , V_131 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
if ( V_2 -> V_17 -> V_119 ) {
V_128 = F_29 ( V_2 , V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_48 ( V_2 , V_10 ) ;
F_49 ( V_10 ) ;
break;
case V_151 :
V_127 -> V_144 = V_145 ;
V_127 -> V_123 = V_151 ;
F_26 ( V_10 , sizeof( V_127 -> V_134 . V_152 ) ) ;
V_127 -> V_134 . V_152 . V_125 = F_46 ( V_125 ) ;
V_127 -> V_134 . V_152 . V_124 = V_124 ;
if ( V_2 -> V_17 -> V_119 ) {
V_128 = F_39 ( V_2 , V_122 , V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
V_128 = F_31 ( V_2 , V_122 , 1 , V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
} else {
V_128 = F_31 ( V_2 , V_122 , 0 , V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
}
break;
case V_153 :
V_127 -> V_144 = V_145 ;
V_127 -> V_123 = V_153 ;
F_26 ( V_10 , sizeof( V_127 -> V_134 . V_154 ) ) ;
V_127 -> V_134 . V_154 . V_155 = F_46 ( V_125 ) ;
break;
case V_156 :
V_127 -> V_144 = V_145 ;
V_127 -> V_123 = V_156 ;
F_26 ( V_10 , sizeof( V_127 -> V_134 . V_157 ) ) ;
V_127 -> V_134 . V_157 . V_124 = V_124 ;
break;
default:
F_25 ( V_2 -> V_17 -> V_18 , L_5 ) ;
return - V_158 ;
}
return 0 ;
}
static void
F_56 ( struct V_9 * V_10 , const T_1 * V_159 ,
const T_1 * V_122 , const T_1 * V_160 )
{
struct V_161 * V_162 ;
V_162 = ( void * ) F_26 ( V_10 , sizeof( struct V_161 ) ) ;
V_162 -> V_163 = V_164 ;
V_162 -> V_165 = sizeof( struct V_161 ) -
sizeof( struct V_166 ) ;
memcpy ( V_162 -> V_160 , V_160 , V_136 ) ;
memcpy ( V_162 -> V_167 , V_159 , V_136 ) ;
memcpy ( V_162 -> V_168 , V_122 , V_136 ) ;
}
int F_57 ( struct V_1 * V_2 , const T_1 * V_122 ,
T_1 V_123 , T_1 V_124 ,
T_3 V_125 , const T_1 * V_169 ,
T_4 V_170 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
int V_128 ;
T_3 V_171 ;
V_171 = V_172 +
F_58 ( sizeof( struct V_173 ) ,
sizeof( struct V_126 ) ) +
V_174 +
V_40 +
3 +
sizeof( struct V_113 ) +
sizeof( struct V_130 ) +
sizeof( struct V_175 ) +
sizeof( struct V_60 ) +
sizeof( struct V_161 ) +
V_170 ;
if ( V_2 -> V_17 -> V_119 )
V_171 += sizeof( struct V_176 ) +
sizeof( struct V_177 ) +
sizeof( struct V_178 ) ;
V_10 = F_59 ( V_171 ) ;
if ( ! V_10 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_6 ) ;
return - V_46 ;
}
F_60 ( V_10 , V_172 ) ;
switch ( V_123 ) {
case V_143 :
case V_151 :
case V_153 :
case V_156 :
V_128 = F_50 ( V_2 , V_122 , V_123 ,
V_124 , V_125 ,
V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
if ( V_170 )
memcpy ( F_26 ( V_10 , V_170 ) , V_169 ,
V_170 ) ;
F_56 ( V_10 , V_2 -> V_138 , V_122 ,
V_2 -> V_179 ) ;
break;
case V_149 :
V_128 = F_50 ( V_2 , V_122 , V_123 ,
V_124 , V_125 ,
V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
if ( V_170 )
memcpy ( F_26 ( V_10 , V_170 ) , V_169 ,
V_170 ) ;
F_56 ( V_10 , V_122 , V_2 -> V_138 ,
V_2 -> V_179 ) ;
break;
}
switch ( V_123 ) {
case V_143 :
case V_149 :
V_10 -> V_24 = V_180 ;
break;
default:
V_10 -> V_24 = V_181 ;
break;
}
V_13 = F_7 ( V_10 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_182 = V_2 -> V_182 ;
V_13 -> V_183 = V_2 -> V_183 ;
F_61 ( V_10 ) ;
F_62 ( V_2 , V_10 ) ;
return 0 ;
}
static int
F_63 ( struct V_1 * V_2 ,
const T_1 * V_122 ,
T_1 V_123 , T_1 V_124 ,
T_3 V_125 , struct V_9 * V_10 )
{
struct V_173 * V_184 ;
T_1 V_185 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_128 ;
T_3 V_129 ;
struct V_130 * V_131 ;
T_1 V_132 , * V_41 ;
V_129 = V_2 -> V_57 . V_66 . V_133 ;
V_184 = ( void * ) F_26 ( V_10 , F_51 ( struct V_173 , V_134 ) ) ;
memset ( V_184 , 0 , 24 ) ;
memcpy ( V_184 -> V_135 , V_122 , V_136 ) ;
memcpy ( V_184 -> V_137 , V_2 -> V_138 , V_136 ) ;
memcpy ( V_184 -> V_160 , V_2 -> V_179 , V_136 ) ;
V_184 -> V_186 = F_46 ( V_187 |
V_188 ) ;
V_41 = F_26 ( V_10 , V_136 ) ;
switch ( V_123 ) {
case V_189 :
F_26 ( V_10 , sizeof( V_184 -> V_134 . V_190 . V_134 . V_191 ) + 1 ) ;
V_184 -> V_134 . V_190 . V_144 = V_192 ;
V_184 -> V_134 . V_190 . V_134 . V_191 . V_123 =
V_189 ;
V_184 -> V_134 . V_190 . V_134 . V_191 . V_124 =
V_124 ;
V_184 -> V_134 . V_190 . V_134 . V_191 . V_147 =
F_46 ( V_129 ) ;
memmove ( V_41 + V_136 , & V_184 -> V_134 . V_190 . V_144 ,
sizeof( V_184 -> V_134 . V_190 . V_134 . V_191 ) ) ;
memcpy ( V_41 , V_185 , V_136 ) ;
V_128 = F_21 ( V_2 , V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_130 ) + 2 ) ;
* V_41 ++ = V_148 ;
* V_41 ++ = sizeof( struct V_130 ) ;
V_131 = ( void * ) V_41 ;
V_132 = F_54 ( V_2 -> V_57 . V_58 ) ;
V_128 = F_55 ( V_2 , V_132 , V_131 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
if ( V_2 -> V_17 -> V_119 ) {
V_128 = F_29 ( V_2 , V_10 ) ;
if ( V_128 ) {
F_53 ( V_10 ) ;
return V_128 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_48 ( V_2 , V_10 ) ;
F_49 ( V_10 ) ;
break;
default:
F_25 ( V_2 -> V_17 -> V_18 , L_7 ) ;
return - V_158 ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 , const T_1 * V_122 ,
T_1 V_123 , T_1 V_124 ,
T_3 V_125 , const T_1 * V_169 ,
T_4 V_170 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
T_1 * V_41 ;
T_2 V_193 , V_194 ;
T_3 V_195 , V_171 ;
V_171 = V_172 +
F_58 ( sizeof( struct V_173 ) ,
sizeof( struct V_126 ) ) +
V_174 +
V_40 +
sizeof( struct V_113 ) +
sizeof( struct V_130 ) +
sizeof( struct V_175 ) +
sizeof( struct V_60 ) +
sizeof( struct V_161 ) +
V_170 +
3 +
V_136 ;
if ( V_2 -> V_17 -> V_119 )
V_171 += sizeof( struct V_176 ) +
sizeof( struct V_177 ) +
sizeof( struct V_178 ) ;
V_10 = F_59 ( V_171 ) ;
if ( ! V_10 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_6 ) ;
return - V_46 ;
}
F_60 ( V_10 , V_172 ) ;
V_193 = V_196 ;
V_194 = 0 ;
V_41 = F_26 ( V_10 , V_174 + sizeof( V_195 ) ) ;
memset ( V_41 , 0 , V_174 + sizeof( V_195 ) ) ;
memcpy ( V_41 , & V_193 , sizeof( V_193 ) ) ;
memcpy ( V_41 + sizeof( V_193 ) , & V_194 , sizeof( V_194 ) ) ;
if ( F_63 ( V_2 , V_122 , V_123 ,
V_124 , V_125 ,
V_10 ) ) {
F_53 ( V_10 ) ;
return - V_158 ;
}
if ( V_170 )
memcpy ( F_26 ( V_10 , V_170 ) , V_169 , V_170 ) ;
F_56 ( V_10 , V_122 , V_2 -> V_138 ,
V_2 -> V_179 ) ;
V_10 -> V_24 = V_181 ;
V_13 = F_7 ( V_10 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_182 = V_2 -> V_182 ;
V_13 -> V_183 = V_2 -> V_183 ;
V_13 -> V_14 |= V_27 ;
V_195 = V_10 -> V_117 - V_174 - sizeof( V_195 ) ;
memcpy ( V_10 -> V_22 + V_174 , & V_195 ,
sizeof( V_195 ) ) ;
F_61 ( V_10 ) ;
F_62 ( V_2 , V_10 ) ;
return 0 ;
}
void F_65 ( struct V_1 * V_2 ,
T_1 * V_197 , int V_117 )
{
struct V_62 * V_63 ;
T_1 * V_122 , * V_41 , * V_198 ;
T_1 V_37 , V_190 , V_199 ;
T_5 V_200 = 0 ;
int V_165 = 0 ;
if ( V_117 < ( sizeof( struct V_201 ) + 3 ) )
return;
if ( * ( V_197 + sizeof( struct V_201 ) ) != V_142 )
return;
if ( * ( V_197 + sizeof( struct V_201 ) + 1 ) != V_145 )
return;
V_122 = V_197 + V_136 ;
V_190 = * ( V_197 + sizeof( struct V_201 ) + 2 ) ;
F_2 ( V_2 -> V_17 -> V_18 ,
L_8 , V_122 , V_190 ) ;
switch ( V_190 ) {
case V_143 :
if ( V_117 < ( sizeof( struct V_201 ) + V_202 ) )
return;
V_41 = V_197 + sizeof( struct V_201 ) + 4 ;
V_200 = F_46 ( * ( T_3 * ) V_41 ) ;
V_165 = V_117 - sizeof( struct V_201 ) - V_202 ;
V_41 += 2 ;
break;
case V_149 :
if ( V_117 < ( sizeof( struct V_201 ) + V_203 ) )
return;
V_41 = V_197 + sizeof( struct V_201 ) + 6 ;
V_200 = F_46 ( * ( T_3 * ) V_41 ) ;
V_165 = V_117 - sizeof( struct V_201 ) - V_203 ;
V_41 += 2 ;
break;
case V_151 :
if ( V_117 < ( sizeof( struct V_201 ) + V_204 ) )
return;
V_41 = V_197 + sizeof( struct V_201 ) + V_204 ;
V_165 = V_117 - sizeof( struct V_201 ) - V_204 ;
break;
default:
F_2 ( V_2 -> V_17 -> V_18 , L_5 ) ;
return;
}
V_63 = F_66 ( V_2 , V_122 ) ;
if ( ! V_63 )
return;
V_63 -> V_74 . V_129 = V_200 ;
for ( V_198 = V_41 + V_165 ; V_41 + 1 < V_198 ; V_41 += 2 + V_41 [ 1 ] ) {
if ( V_41 + 2 + V_41 [ 1 ] > V_198 )
break;
switch ( * V_41 ) {
case V_47 :
V_63 -> V_74 . V_205 = V_41 [ 1 ] ;
for ( V_37 = 0 ; V_37 < V_41 [ 1 ] ; V_37 ++ )
V_63 -> V_74 . V_39 [ V_37 ] = V_41 [ V_37 + 2 ] ;
break;
case V_48 :
V_199 = V_63 -> V_74 . V_205 ;
for ( V_37 = 0 ; V_37 < V_41 [ 1 ] ; V_37 ++ )
V_63 -> V_74 . V_39 [ V_199 + V_37 ] = V_41 [ V_37 + 2 ] ;
V_63 -> V_74 . V_205 += V_41 [ 1 ] ;
break;
case V_148 :
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_206 , V_41 ,
sizeof( struct V_130 ) ) ;
V_63 -> V_207 = 1 ;
break;
case V_67 :
memcpy ( & V_63 -> V_74 . V_61 , V_41 ,
sizeof( struct V_60 ) ) ;
break;
case V_208 :
V_63 -> V_74 . V_209 = V_41 [ 2 ] ;
break;
case V_116 :
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_90 , V_41 ,
sizeof( struct V_166 ) +
F_23 ( T_1 , V_41 [ 1 ] , 8 ) ) ;
break;
case V_210 :
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_211 , V_41 ,
sizeof( struct V_166 ) +
F_23 ( T_1 , V_41 [ 1 ] , V_212 -
sizeof( struct V_166 ) ) ) ;
break;
case V_120 :
V_63 -> V_74 . V_213 = V_41 [ 2 ] ;
break;
case V_94 :
if ( V_2 -> V_17 -> V_119 )
memcpy ( & V_63 -> V_74 . V_214 , V_41 ,
sizeof( struct V_75 ) ) ;
break;
case V_56 :
if ( V_2 -> V_17 -> V_119 ) {
memcpy ( ( T_1 * ) & V_63 -> V_74 . V_99 , V_41 ,
sizeof( struct V_54 ) ) ;
V_63 -> V_215 = 1 ;
}
break;
case V_52 :
if ( V_2 -> V_17 -> V_119 )
V_63 -> V_74 . V_216 =
F_28 ( * ( T_5 * ) ( V_41 + 2 ) ) ;
default:
break;
}
}
return;
}
static int
F_67 ( struct V_1 * V_2 , const T_1 * V_122 )
{
struct V_62 * V_63 ;
struct V_217 V_218 ;
memset ( & V_218 , 0 , sizeof( struct V_217 ) ) ;
V_63 = F_32 ( V_2 , V_122 ) ;
if ( ! V_63 || V_63 -> V_219 == V_220 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_9 , V_122 ) ;
return - V_158 ;
}
memcpy ( & V_218 . V_221 , V_122 , V_136 ) ;
V_218 . V_222 = V_223 ;
return F_68 ( V_2 , V_224 ,
V_225 , 0 , & V_218 , true ) ;
}
static int
F_69 ( struct V_1 * V_2 , const T_1 * V_122 )
{
struct V_62 * V_63 ;
struct V_217 V_218 ;
memset ( & V_218 , 0 , sizeof( struct V_217 ) ) ;
V_63 = F_32 ( V_2 , V_122 ) ;
if ( V_63 && V_63 -> V_219 == V_226 ) {
F_2 ( V_2 -> V_17 -> V_18 ,
L_10 , V_122 ) ;
return 0 ;
}
V_63 = F_66 ( V_2 , V_122 ) ;
if ( ! V_63 )
return - V_46 ;
V_63 -> V_219 = V_226 ;
F_18 ( V_2 , V_122 ) ;
memcpy ( & V_218 . V_221 , V_122 , V_136 ) ;
V_218 . V_222 = V_227 ;
return F_68 ( V_2 , V_224 ,
V_225 , 0 , & V_218 , true ) ;
}
static int
F_70 ( struct V_1 * V_2 , const T_1 * V_122 )
{
struct V_62 * V_63 ;
struct V_217 V_218 ;
unsigned long V_14 ;
memset ( & V_218 , 0 , sizeof( struct V_217 ) ) ;
V_63 = F_32 ( V_2 , V_122 ) ;
if ( V_63 ) {
if ( V_63 -> V_207 ) {
F_71 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_72 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_73 ( V_2 , V_122 ) ;
}
F_1 ( V_2 , V_122 , V_228 ) ;
memcpy ( & V_218 . V_221 , V_122 , V_136 ) ;
V_218 . V_222 = V_229 ;
return F_68 ( V_2 , V_224 ,
V_225 , 0 , & V_218 , true ) ;
}
static int
F_74 ( struct V_1 * V_2 , const T_1 * V_122 )
{
struct V_62 * V_63 ;
struct V_230 V_231 ;
unsigned long V_14 ;
int V_37 ;
V_63 = F_32 ( V_2 , V_122 ) ;
if ( V_63 && ( V_63 -> V_219 != V_220 ) ) {
F_2 ( V_2 -> V_17 -> V_18 ,
L_11 , V_122 ) ;
V_63 -> V_219 = V_25 ;
V_231 = V_63 -> V_74 . V_206 . V_231 ;
if ( V_231 . V_232 [ 0 ] != 0xff )
V_63 -> V_207 = true ;
if ( V_63 -> V_207 ) {
if ( F_28 ( V_63 -> V_74 . V_206 . V_233 ) &
V_234 )
V_63 -> V_235 =
V_236 ;
else
V_63 -> V_235 =
V_237 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_63 -> V_238 [ V_37 ] =
V_2 -> V_239 [ V_37 ] . V_240 ;
} else {
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_63 -> V_238 [ V_37 ] = V_241 ;
}
memset ( V_63 -> V_242 , 0xff , sizeof( V_63 -> V_242 ) ) ;
F_1 ( V_2 , V_122 , V_25 ) ;
} else {
F_2 ( V_2 -> V_17 -> V_18 ,
L_12 , V_122 ) ;
if ( V_63 ) {
F_71 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_72 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_73 ( V_2 , V_122 ) ;
}
F_1 ( V_2 , V_122 , V_228 ) ;
return - 1 ;
}
return 0 ;
}
int F_75 ( struct V_1 * V_2 , const T_1 * V_122 , T_1 V_190 )
{
switch ( V_190 ) {
case V_243 :
return F_74 ( V_2 , V_122 ) ;
case V_229 :
return F_70 ( V_2 , V_122 ) ;
case V_227 :
return F_69 ( V_2 , V_122 ) ;
case V_223 :
return F_67 ( V_2 , V_122 ) ;
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_62 * V_63 ;
V_63 = F_32 ( V_2 , V_3 ) ;
if ( V_63 )
return V_63 -> V_219 ;
return V_244 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_217 V_218 ;
unsigned long V_14 ;
if ( F_10 ( & V_2 -> V_245 ) )
return;
F_19 (sta_ptr, &priv->sta_list, list) {
memset ( & V_218 , 0 , sizeof( struct V_217 ) ) ;
if ( V_63 -> V_207 ) {
F_71 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_72 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_1 ( V_2 , V_63 -> V_246 ,
V_228 ) ;
memcpy ( & V_218 . V_221 , V_63 -> V_246 , V_136 ) ;
V_218 . V_222 = V_229 ;
if ( F_68 ( V_2 , V_224 ,
V_225 , 0 , & V_218 , false ) )
F_34 ( V_2 -> V_17 -> V_18 ,
L_13 ,
V_63 -> V_246 ) ;
}
F_78 ( V_2 ) ;
}
