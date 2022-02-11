int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 = F_2 ( V_5 -> V_7 ) ;
struct V_8 * V_9 =
V_2 -> V_10 . V_11 -> V_12 [ V_3 ] ;
if ( F_3 ( ! V_9 ) ) {
F_4 ( V_2 -> V_13 , ERROR , L_1 ) ;
return - V_14 ;
}
V_5 -> V_15 =
( V_9 -> V_5 . V_16 &
V_17 ) |
( ( V_9 -> V_5 . V_18 <<
V_19 ) &
V_20 ) ;
memcpy ( ( T_1 * ) & V_5 -> V_21 , & V_9 -> V_5 . V_21 ,
sizeof( V_9 -> V_5 . V_21 ) ) ;
if ( V_2 -> V_22 == V_23 ||
( V_9 -> V_5 . V_24 & V_25 &&
( V_2 -> V_13 -> V_26 !=
V_27 ) ) )
F_5 ( V_5 -> V_21 . V_28 ) ;
V_6 &= ~ V_29 ;
V_5 -> V_30 = F_6 ( V_9 -> V_5 . V_24 ) ;
V_5 -> V_7 = F_6 ( V_6 ) ;
if ( F_7 ( V_2 -> V_13 -> V_31 ) )
V_5 -> V_32 = F_8 ( V_33 ) ;
return 0 ;
}
static struct V_34 *
F_9 ( struct V_1 * V_2 ,
enum V_35 V_36 )
{
struct V_34 * V_37 ;
unsigned long V_38 ;
F_10 ( & V_2 -> V_39 , V_38 ) ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_37 -> V_36 == V_36 ) {
F_12 ( & V_2 -> V_39 ,
V_38 ) ;
return V_37 ;
}
}
F_12 ( & V_2 -> V_39 , V_38 ) ;
return NULL ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
int V_42 ;
struct V_34 * V_43 ;
struct V_44 * V_45 = & V_41 -> V_46 . V_45 ;
T_2 V_47 = F_2 ( V_45 -> V_47 ) ;
V_42 = V_47 >> V_48 ;
if ( V_45 -> V_49 == V_50 ) {
F_14 ( V_2 , V_42 , V_45 -> V_51 ,
V_52 ,
F_15 ( V_47 ) ) ;
V_43 = F_9 ( V_2 , V_53 ) ;
if ( V_43 )
F_16 ( V_2 , V_43 -> V_42 ,
V_43 -> V_54 ) ;
} else {
if ( ! F_15 ( V_47 ) )
return 0 ;
F_17 ( V_2 , V_45 -> V_51 , V_42 ,
V_53 ) ;
V_43 = F_9 ( V_2 , V_53 ) ;
if ( V_43 )
F_14 ( V_2 , V_43 -> V_42 , V_43 -> V_54 ,
V_52 , true ) ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
int V_42 , V_55 ;
struct V_56 * V_57 = & V_41 -> V_46 . V_57 ;
struct V_34 * V_43 ;
struct V_58 * V_59 ;
T_3 V_60 = F_2 ( V_57 -> V_60 ) ;
V_57 -> V_61 = F_6 ( ( F_2 ( V_57 -> V_61 ) )
& V_62 ) ;
V_42 = ( V_60 & V_63 )
>> V_64 ;
V_55 = F_19 ( V_2 , V_42 ) ;
V_59 = F_20 ( V_2 , V_55 , V_57 ->
V_51 ) ;
if ( F_2 ( V_57 -> V_65 ) != V_50 ) {
if ( V_59 ) {
V_59 -> V_36 = V_66 ;
V_59 -> V_67 = false ;
}
F_14 ( V_2 , V_42 , V_57 -> V_51 ,
V_52 , true ) ;
if ( V_57 -> V_68 != V_69 )
V_2 -> V_70 [ V_42 ] . V_71 =
V_72 ;
return 0 ;
}
V_43 = F_21 ( V_2 , V_42 , V_57 -> V_51 ) ;
if ( V_43 ) {
F_4 ( V_2 -> V_13 , V_73 , L_2 ) ;
V_43 -> V_36 = V_74 ;
if ( ( V_60 & V_75 ) &&
V_2 -> V_76 . V_77 &&
( V_2 -> V_70 [ V_42 ] . V_78 != V_72 ) )
V_43 -> V_78 = true ;
else
V_43 -> V_78 = false ;
if ( V_59 ) {
V_59 -> V_67 = V_43 -> V_78 ;
V_59 -> V_36 = V_74 ;
}
} else {
F_4 ( V_2 -> V_13 , ERROR , L_3 ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_40 * V_79 , int V_80 ,
T_3 * V_81 )
{
struct V_82 * V_83 = & V_79 -> V_46 . V_83 ;
T_3 V_84 = ( T_3 ) V_80 ;
V_79 -> V_85 = F_6 ( V_86 ) ;
V_79 -> V_87 =
F_6 ( sizeof( struct V_82 ) + V_88 ) ;
V_83 -> V_84 = F_6 ( V_84 ) ;
switch ( V_84 ) {
case V_89 :
F_4 ( V_2 -> V_13 , V_90 ,
L_4 , * V_81 ) ;
V_83 -> V_91 = F_6 ( * V_81 ) ;
break;
case V_92 :
default:
V_83 -> V_91 = 0 ;
break;
}
return 0 ;
}
int F_23 ( struct V_40 * V_79 ,
int V_80 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 =
& V_79 -> V_46 . V_97 ;
T_3 V_84 = ( T_3 ) V_80 ;
V_79 -> V_85 = F_6 ( V_98 ) ;
V_79 -> V_87 = F_6 ( sizeof( struct V_95 )
+ V_88 ) ;
V_96 -> V_84 = F_6 ( V_84 ) ;
switch ( V_84 ) {
case V_89 :
V_96 -> V_99 = F_6 ( V_94 -> V_99 ) ;
V_96 -> V_100 = 0 ;
break;
case V_92 :
default:
V_96 -> V_100 = 0 ;
break;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_40 * V_79 , T_3 V_80 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 = & V_79 -> V_46 . V_104 ;
V_79 -> V_85 = F_6 ( V_105 ) ;
V_79 -> V_87 = F_6 ( sizeof( struct V_103 ) + V_88 ) ;
V_104 -> V_84 = F_6 ( V_80 ) ;
V_104 -> V_106 = F_6 ( V_102 -> V_107 ) ;
V_104 -> V_108 = F_6 ( V_102 -> V_109 ) ;
if ( V_2 -> V_13 -> V_110 )
V_104 -> V_111 = F_6 ( V_102 -> V_111 ) ;
return 0 ;
}
int
F_25 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
T_1 * * V_114 )
{
struct V_115 * V_5 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
int V_124 = 0 ;
struct V_8 * V_9 ;
struct V_125 * V_126 ;
T_1 V_3 ;
if ( ! V_114 || ! * V_114 )
return V_124 ;
V_3 = F_26 ( ( T_1 ) V_113 -> V_127 ) ;
V_9 = V_2 -> V_10 . V_11 -> V_12 [ V_3 ] ;
if ( V_113 -> V_128 ) {
V_5 = (struct V_115 * ) * V_114 ;
memset ( V_5 , 0 , sizeof( struct V_115 ) ) ;
V_5 -> V_129 . type = F_6 ( V_130 ) ;
V_5 -> V_129 . V_131 =
F_6 ( sizeof( struct V_4 ) ) ;
memcpy ( ( T_1 * ) V_5 + sizeof( struct V_132 ) ,
( T_1 * ) V_113 -> V_128 ,
F_2 ( V_5 -> V_129 . V_131 ) ) ;
F_1 ( V_2 , V_3 , & V_5 -> V_5 ) ;
* V_114 += sizeof( struct V_115 ) ;
V_124 += sizeof( struct V_115 ) ;
}
if ( V_113 -> V_133 ) {
if ( V_2 -> V_22 == V_134 ) {
V_117 = (struct V_116 * ) * V_114 ;
memset ( V_117 , 0 ,
sizeof( struct V_116 ) ) ;
V_117 -> V_129 . type =
F_6 ( V_135 ) ;
V_117 -> V_129 . V_131 =
F_6 (
sizeof( struct V_136 ) ) ;
memcpy ( ( T_1 * ) V_117 +
sizeof( struct V_132 ) ,
( T_1 * ) V_113 -> V_133 ,
F_2 ( V_117 -> V_129 . V_131 ) ) ;
if ( ! ( V_9 -> V_5 . V_24 &
V_25 ) )
V_117 -> V_137 . V_138 &=
~ ( V_139 |
V_140 ) ;
* V_114 += sizeof( struct V_116 ) ;
V_124 += sizeof( struct V_116 ) ;
}
V_119 =
(struct V_118 * ) * V_114 ;
memset ( V_119 , 0 ,
sizeof( struct V_118 ) ) ;
V_119 -> V_129 . type = F_6 ( V_141 ) ;
V_119 -> V_129 . V_131 = F_6 (
sizeof( struct V_118 ) -
sizeof( struct V_132 ) ) ;
V_119 -> V_142 [ 0 ] . V_143 =
V_113 -> V_133 -> V_144 ;
V_119 -> V_142 [ 0 ] . V_3 =
F_26 ( ( T_1 ) V_113 -> V_127 ) ;
if ( V_9 -> V_5 . V_24 & V_25 &&
V_113 -> V_133 -> V_138 &
V_139 )
F_27 ( V_119 -> V_142 [ 0 ] .
V_3 ,
( V_113 -> V_133 -> V_138 &
V_140 ) ) ;
* V_114 += sizeof( struct V_118 ) ;
V_124 += sizeof( struct V_118 ) ;
}
if ( V_113 -> V_145 ) {
V_121 = (struct V_120 * ) * V_114 ;
memset ( V_121 , 0 ,
sizeof( struct V_120 ) ) ;
V_121 -> V_129 . type = F_6 ( V_146 ) ;
V_121 -> V_129 . V_131 =
F_6 ( sizeof( V_121 -> V_121 ) ) ;
memcpy ( ( T_1 * ) V_121 +
sizeof( struct V_132 ) ,
V_113 -> V_145 +
sizeof( struct V_125 ) ,
F_2 ( V_121 -> V_129 . V_131 ) ) ;
* V_114 += sizeof( struct V_120 ) ;
V_124 += sizeof( struct V_120 ) ;
}
if ( V_113 -> V_147 ) {
V_126 = ( void * ) V_113 -> V_147 ;
V_123 = (struct V_122 * ) * V_114 ;
memset ( V_123 , 0 , sizeof( struct V_122 ) ) ;
V_123 -> V_129 . type = F_6 ( V_148 ) ;
V_123 -> V_129 . V_131 = F_6 ( V_126 -> V_131 ) ;
memcpy ( ( T_1 * ) V_123 -> V_149 ,
V_113 -> V_147 + sizeof( struct V_125 ) ,
F_2 ( V_123 -> V_129 . V_131 ) ) ;
if ( V_126 -> V_131 > 3 &&
V_123 -> V_149 [ 3 ] & V_150 )
V_2 -> V_151 = true ;
else
V_2 -> V_151 = false ;
* V_114 += sizeof( struct V_122 ) + V_126 -> V_131 ;
V_124 += sizeof( struct V_122 ) + V_126 -> V_131 ;
}
return V_124 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_34 * V_152 )
{
struct V_34 * V_37 ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_37 == V_152 )
return true ;
}
return false ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_34 * V_37 )
{
if ( ! V_37 &&
F_28 ( V_2 , V_37 ) )
return;
F_4 ( V_2 -> V_13 , V_153 ,
L_5 , V_37 ) ;
F_30 ( & V_37 -> V_154 ) ;
F_31 ( V_37 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
int V_155 ;
struct V_34 * V_156 , * V_157 ;
unsigned long V_38 ;
F_10 ( & V_2 -> V_39 , V_38 ) ;
F_33 (del_tbl_ptr, tmp_node,
&priv->tx_ba_stream_tbl_ptr, list)
F_29 ( V_2 , V_156 ) ;
F_12 ( & V_2 -> V_39 , V_38 ) ;
F_34 ( & V_2 -> V_158 ) ;
for ( V_155 = 0 ; V_155 < V_159 ; ++ V_155 )
V_2 -> V_70 [ V_155 ] . V_71 =
V_2 -> V_70 [ V_155 ] . V_160 ;
}
struct V_34 *
F_21 ( struct V_1 * V_2 , int V_42 , T_1 * V_54 )
{
struct V_34 * V_37 ;
unsigned long V_38 ;
F_10 ( & V_2 -> V_39 , V_38 ) ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( F_35 ( V_37 -> V_54 , V_54 ) &&
V_37 -> V_42 == V_42 ) {
F_12 ( & V_2 -> V_39 ,
V_38 ) ;
return V_37 ;
}
}
F_12 ( & V_2 -> V_39 , V_38 ) ;
return NULL ;
}
void F_17 ( struct V_1 * V_2 , T_1 * V_54 , int V_42 ,
enum V_35 V_36 )
{
struct V_34 * V_161 ;
struct V_58 * V_59 ;
unsigned long V_38 ;
int V_55 ;
if ( ! F_21 ( V_2 , V_42 , V_54 ) ) {
V_161 = F_36 ( sizeof( struct V_34 ) ,
V_162 ) ;
if ( ! V_161 )
return;
V_55 = F_19 ( V_2 , V_42 ) ;
V_59 = F_20 ( V_2 , V_55 , V_54 ) ;
if ( V_59 ) {
V_59 -> V_36 = V_36 ;
V_59 -> V_67 = false ;
}
F_34 ( & V_161 -> V_154 ) ;
V_161 -> V_42 = V_42 ;
V_161 -> V_36 = V_36 ;
memcpy ( V_161 -> V_54 , V_54 , V_163 ) ;
F_10 ( & V_2 -> V_39 , V_38 ) ;
F_37 ( & V_161 -> V_154 , & V_2 -> V_158 ) ;
F_12 ( & V_2 -> V_39 , V_38 ) ;
}
}
int F_16 ( struct V_1 * V_2 , int V_42 , T_1 * V_164 )
{
struct V_165 V_166 ;
T_4 V_167 = V_2 -> V_76 . V_167 ;
static T_1 V_168 ;
int V_169 ;
unsigned long V_38 ;
T_3 V_60 ;
F_4 ( V_2 -> V_13 , V_90 , L_6 , V_170 , V_42 ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
if ( ( F_38 ( V_2 ) == V_171 ) &&
F_39 ( V_2 -> V_13 -> V_172 ) &&
V_2 -> V_13 -> V_110 &&
memcmp ( V_2 -> V_173 , V_164 , V_163 ) ) {
struct V_174 * V_175 ;
F_10 ( & V_2 -> V_176 , V_38 ) ;
V_175 = F_40 ( V_2 , V_164 ) ;
if ( ! V_175 ) {
F_12 ( & V_2 -> V_176 , V_38 ) ;
F_4 ( V_2 -> V_13 , ERROR ,
L_7 ,
V_164 ) ;
return - 1 ;
}
if ( V_175 -> V_177 )
V_167 = V_178 ;
F_12 ( & V_2 -> V_176 , V_38 ) ;
}
V_60 = ( T_3 ) ( ( V_42 << V_64 ) |
V_167 << V_179 |
V_180 ) ;
if ( V_2 -> V_76 . V_77 &&
( V_2 -> V_70 [ V_42 ] . V_78 != V_72 ) )
V_60 |= V_75 ;
V_166 . V_60 = F_6 ( V_60 ) ;
V_166 . V_181 = F_6 ( ( T_3 ) V_2 -> V_76 . V_182 ) ;
++ V_168 ;
if ( V_168 == 0 )
V_168 = 1 ;
V_166 . V_183 = V_168 ;
memcpy ( & V_166 . V_51 , V_164 , V_163 ) ;
V_169 = F_41 ( V_2 , V_184 ,
0 , 0 , & V_166 , false ) ;
return V_169 ;
}
int F_42 ( struct V_1 * V_2 , int V_42 , T_1 * V_164 ,
int V_185 )
{
struct V_44 V_186 ;
int V_169 ;
T_2 V_47 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_47 = F_6 ( V_42 << V_48 ) ;
V_47 = F_2 ( V_186 . V_47 ) ;
if ( V_185 )
V_47 |= V_187 ;
else
V_47 &= ~ V_187 ;
memcpy ( & V_186 . V_51 , V_164 , V_163 ) ;
V_169 = F_41 ( V_2 , V_188 ,
V_89 , 0 , & V_186 , false ) ;
return V_169 ;
}
void F_43 ( struct V_1 * V_2 , int V_42 )
{
struct V_189 * V_190 ;
unsigned long V_38 ;
F_10 ( & V_2 -> V_191 , V_38 ) ;
if ( F_44 ( & V_2 -> V_192 ) ) {
F_45 ( V_2 -> V_13 -> V_193 ,
L_8 ) ;
goto exit;
}
F_11 (rx_reor_tbl_ptr, &priv->rx_reorder_tbl_ptr, list) {
if ( V_190 -> V_42 == V_42 ) {
F_45 ( V_2 -> V_13 -> V_193 ,
L_9 ,
V_42 , V_190 -> V_194 ) ;
F_42 ( V_2 , V_42 , V_190 -> V_194 , 0 ) ;
goto exit;
}
}
exit:
F_12 ( & V_2 -> V_191 , V_38 ) ;
}
void F_46 ( struct V_1 * V_2 , T_1 * V_45 )
{
struct V_44 * V_195 =
(struct V_44 * ) V_45 ;
T_2 V_47 = F_2 ( V_195 -> V_47 ) ;
int V_42 ;
V_42 = V_47 >> V_48 ;
F_14 ( V_2 , V_42 , V_195 -> V_51 ,
V_196 , F_15 ( V_47 ) ) ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_197 * V_198 )
{
int V_155 ;
struct V_197 * V_199 = V_198 ;
struct V_189 * V_192 ;
int V_200 = 0 ;
unsigned long V_38 ;
F_10 ( & V_2 -> V_191 , V_38 ) ;
F_11 (rx_reorder_tbl_ptr, &priv->rx_reorder_tbl_ptr,
list) {
V_199 -> V_42 = ( T_3 ) V_192 -> V_42 ;
memcpy ( V_199 -> V_194 , V_192 -> V_194 , V_163 ) ;
V_199 -> V_201 = V_192 -> V_201 ;
V_199 -> V_202 = V_192 -> V_202 ;
for ( V_155 = 0 ; V_155 < V_192 -> V_202 ; ++ V_155 ) {
if ( V_192 -> V_203 [ V_155 ] )
V_199 -> V_114 [ V_155 ] = true ;
else
V_199 -> V_114 [ V_155 ] = false ;
}
V_199 ++ ;
V_200 ++ ;
if ( V_200 >= V_204 )
break;
}
F_12 ( & V_2 -> V_191 , V_38 ) ;
return V_200 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_205 * V_198 )
{
struct V_34 * V_37 ;
struct V_205 * V_199 = V_198 ;
int V_200 = 0 ;
unsigned long V_38 ;
F_10 ( & V_2 -> V_39 , V_38 ) ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
V_199 -> V_42 = ( T_3 ) V_37 -> V_42 ;
F_4 ( V_2 -> V_13 , V_206 , L_10 ,
V_170 , V_199 -> V_42 ) ;
memcpy ( V_199 -> V_54 , V_37 -> V_54 , V_163 ) ;
V_199 -> V_78 = V_37 -> V_78 ;
V_199 ++ ;
V_200 ++ ;
if ( V_200 >= V_207 )
break;
}
F_12 ( & V_2 -> V_39 , V_38 ) ;
return V_200 ;
}
void F_49 ( struct V_1 * V_2 , T_1 * V_54 )
{
struct V_34 * V_208 , * V_209 ;
unsigned long V_38 ;
if ( ! V_54 )
return;
F_10 ( & V_2 -> V_39 , V_38 ) ;
F_33 (tbl, tmp, &priv->tx_ba_stream_tbl_ptr, list)
if ( ! memcmp ( V_208 -> V_54 , V_54 , V_163 ) )
F_29 ( V_2 , V_208 ) ;
F_12 ( & V_2 -> V_39 , V_38 ) ;
return;
}
void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_76 . V_182 = V_210 ;
if ( F_38 ( V_2 ) == V_211 ) {
V_2 -> V_76 . V_167 =
V_212 ;
V_2 -> V_76 . V_213 =
V_214 ;
} else {
V_2 -> V_76 . V_167 =
V_215 ;
V_2 -> V_76 . V_213 =
V_216 ;
}
V_2 -> V_76 . V_77 = true ;
V_2 -> V_76 . V_217 = true ;
return;
}
T_1 F_51 ( int V_218 )
{
T_1 V_219 ;
switch ( V_218 ) {
case 36 :
case 44 :
case 52 :
case 60 :
case 100 :
case 108 :
case 116 :
case 124 :
case 132 :
case 140 :
case 149 :
case 157 :
V_219 = V_220 ;
break;
case 40 :
case 48 :
case 56 :
case 64 :
case 104 :
case 112 :
case 120 :
case 128 :
case 136 :
case 144 :
case 153 :
case 161 :
V_219 = V_221 ;
break;
case 165 :
default:
V_219 = V_27 ;
break;
}
return V_219 ;
}
static void
F_52 ( struct V_1 * V_2 , T_1 V_42 )
{
struct V_222 * V_13 = V_2 -> V_13 ;
struct V_34 * V_158 ;
if ( F_44 ( & V_2 -> V_158 ) )
return;
F_11 (tx_ba_stream_tbl_ptr,
&priv->tx_ba_stream_tbl_ptr, list) {
if ( V_158 -> V_36 == V_74 ) {
if ( V_42 == V_158 -> V_42 ) {
F_45 ( V_13 -> V_193 ,
L_11 , V_42 ,
V_158 -> V_54 ) ;
F_42 ( V_2 ,
V_158 -> V_42 ,
V_158 -> V_54 , 1 ) ;
return;
}
}
}
}
void F_53 ( struct V_222 * V_13 )
{
T_1 V_155 ;
T_4 V_167 ;
struct V_1 * V_2 ;
for ( V_155 = 0 ; V_155 < V_13 -> V_223 ; V_155 ++ ) {
if ( ! V_13 -> V_2 [ V_155 ] )
continue;
V_2 = V_13 -> V_2 [ V_155 ] ;
V_167 = V_2 -> V_76 . V_167 ;
if ( V_2 -> V_224 == V_225 )
V_2 -> V_76 . V_167 =
V_215 ;
if ( V_2 -> V_224 == V_226 )
V_2 -> V_76 . V_167 =
V_215 ;
if ( V_2 -> V_224 == V_227 )
V_2 -> V_76 . V_167 =
V_212 ;
if ( V_13 -> V_228 ) {
if ( V_13 -> V_229 )
V_2 -> V_76 . V_167 =
V_13 -> V_229 ;
}
if ( V_167 != V_2 -> V_76 . V_167 ) {
if ( ! V_2 -> V_230 )
continue;
for ( V_155 = 0 ; V_155 < V_159 ; V_155 ++ )
F_52 ( V_2 , V_155 ) ;
}
}
}
