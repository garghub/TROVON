int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 = F_2 ( V_5 -> V_7 ) ;
struct V_8 * V_9 =
V_2 -> V_10 . V_11 -> V_12 [ V_3 ] ;
if ( F_3 ( ! V_9 ) ) {
F_4 ( V_2 -> V_13 -> V_14 , L_1 ) ;
return - V_15 ;
}
V_5 -> V_16 =
( V_9 -> V_5 . V_17 &
V_18 ) |
( ( V_9 -> V_5 . V_19 <<
V_20 ) &
V_21 ) ;
memcpy ( ( T_1 * ) & V_5 -> V_22 , & V_9 -> V_5 . V_22 ,
sizeof( V_9 -> V_5 . V_22 ) ) ;
if ( V_2 -> V_23 == V_24 ||
( V_9 -> V_5 . V_25 & V_26 &&
( V_2 -> V_13 -> V_27 !=
V_28 ) ) )
F_5 ( V_5 -> V_22 . V_29 ) ;
V_6 &= ~ V_30 ;
V_5 -> V_31 = F_6 ( V_9 -> V_5 . V_25 ) ;
V_5 -> V_7 = F_6 ( V_6 ) ;
if ( F_7 ( V_2 -> V_13 -> V_32 ) )
V_5 -> V_33 = F_8 ( V_34 ) ;
return 0 ;
}
static struct V_35 *
F_9 ( struct V_1 * V_2 ,
enum V_36 V_37 )
{
struct V_35 * V_38 ;
unsigned long V_39 ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_38 -> V_37 == V_37 ) {
F_12 ( & V_2 -> V_40 ,
V_39 ) ;
return V_38 ;
}
}
F_12 ( & V_2 -> V_40 , V_39 ) ;
return NULL ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int V_43 ;
struct V_35 * V_44 ;
struct V_45 * V_46 = & V_42 -> V_47 . V_46 ;
T_2 V_48 = F_2 ( V_46 -> V_48 ) ;
V_43 = V_48 >> V_49 ;
if ( V_46 -> V_50 == V_51 ) {
F_14 ( V_2 , V_43 , V_46 -> V_52 ,
V_53 ,
F_15 ( V_48 ) ) ;
V_44 = F_9 ( V_2 , V_54 ) ;
if ( V_44 )
F_16 ( V_2 , V_44 -> V_43 ,
V_44 -> V_55 ) ;
} else {
if ( ! F_15 ( V_48 ) )
return 0 ;
F_17 ( V_2 , V_46 -> V_52 , V_43 ,
V_54 ) ;
V_44 = F_9 ( V_2 , V_54 ) ;
if ( V_44 )
F_14 ( V_2 , V_44 -> V_43 , V_44 -> V_55 ,
V_53 , true ) ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int V_43 ;
struct V_56 * V_57 = & V_42 -> V_47 . V_57 ;
struct V_35 * V_44 ;
struct V_58 * V_59 ;
T_3 V_60 = F_2 ( V_57 -> V_60 ) ;
V_57 -> V_61 = F_6 ( ( F_2 ( V_57 -> V_61 ) )
& V_62 ) ;
V_43 = ( V_60 & V_63 )
>> V_64 ;
V_59 = F_19 ( V_2 , V_43 , V_57 ->
V_52 ) ;
if ( F_2 ( V_57 -> V_65 ) != V_51 ) {
if ( V_59 ) {
V_59 -> V_37 = V_66 ;
V_59 -> V_67 = false ;
}
F_14 ( V_2 , V_43 , V_57 -> V_52 ,
V_53 , true ) ;
if ( V_57 -> V_68 != V_69 )
V_2 -> V_70 [ V_43 ] . V_71 =
V_72 ;
return 0 ;
}
V_44 = F_20 ( V_2 , V_43 , V_57 -> V_52 ) ;
if ( V_44 ) {
F_21 ( V_2 -> V_13 -> V_14 , L_2 ) ;
V_44 -> V_37 = V_73 ;
if ( ( V_60 & V_74 ) &&
V_2 -> V_75 . V_76 &&
( V_2 -> V_70 [ V_43 ] . V_77 != V_72 ) )
V_44 -> V_77 = true ;
else
V_44 -> V_77 = false ;
if ( V_59 ) {
V_59 -> V_67 = V_44 -> V_77 ;
V_59 -> V_37 = V_73 ;
}
} else {
F_4 ( V_2 -> V_13 -> V_14 , L_3 ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_41 * V_78 , int V_79 ,
T_3 * V_80 )
{
struct V_81 * V_82 = & V_78 -> V_47 . V_82 ;
T_3 V_83 = ( T_3 ) V_79 ;
V_78 -> V_84 = F_6 ( V_85 ) ;
V_78 -> V_86 =
F_6 ( sizeof( struct V_81 ) + V_87 ) ;
V_82 -> V_83 = F_6 ( V_83 ) ;
switch ( V_83 ) {
case V_88 :
F_21 ( V_2 -> V_13 -> V_14 , L_4 , * V_80 ) ;
V_82 -> V_89 = F_6 ( * V_80 ) ;
break;
case V_90 :
default:
V_82 -> V_89 = 0 ;
break;
}
return 0 ;
}
int F_23 ( struct V_41 * V_78 ,
int V_79 ,
struct V_91 * V_92 )
{
struct V_93 * V_94 =
& V_78 -> V_47 . V_95 ;
T_3 V_83 = ( T_3 ) V_79 ;
V_78 -> V_84 = F_6 ( V_96 ) ;
V_78 -> V_86 = F_6 ( sizeof( struct V_93 )
+ V_87 ) ;
V_94 -> V_83 = F_6 ( V_83 ) ;
switch ( V_83 ) {
case V_88 :
V_94 -> V_97 = F_6 ( V_92 -> V_97 ) ;
V_94 -> V_98 = 0 ;
break;
case V_90 :
default:
V_94 -> V_98 = 0 ;
break;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_41 * V_78 , T_3 V_79 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 = & V_78 -> V_47 . V_102 ;
V_78 -> V_84 = F_6 ( V_103 ) ;
V_78 -> V_86 = F_6 ( sizeof( struct V_101 ) + V_87 ) ;
V_102 -> V_83 = F_6 ( V_79 ) ;
V_102 -> V_104 = F_6 ( V_100 -> V_105 ) ;
V_102 -> V_106 = F_6 ( V_100 -> V_107 ) ;
if ( V_2 -> V_13 -> V_108 )
V_102 -> V_109 = F_6 ( V_100 -> V_109 ) ;
return 0 ;
}
int
F_25 ( struct V_1 * V_2 ,
struct V_110 * V_111 ,
T_1 * * V_112 )
{
struct V_113 * V_5 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
int V_122 = 0 ;
struct V_8 * V_9 ;
struct V_123 * V_124 ;
T_1 V_3 ;
if ( ! V_112 || ! * V_112 )
return V_122 ;
V_3 = F_26 ( ( T_1 ) V_111 -> V_125 ) ;
V_9 = V_2 -> V_10 . V_11 -> V_12 [ V_3 ] ;
if ( V_111 -> V_126 ) {
V_5 = (struct V_113 * ) * V_112 ;
memset ( V_5 , 0 , sizeof( struct V_113 ) ) ;
V_5 -> V_127 . type = F_6 ( V_128 ) ;
V_5 -> V_127 . V_129 =
F_6 ( sizeof( struct V_4 ) ) ;
memcpy ( ( T_1 * ) V_5 + sizeof( struct V_130 ) ,
( T_1 * ) V_111 -> V_126 ,
F_2 ( V_5 -> V_127 . V_129 ) ) ;
F_1 ( V_2 , V_3 , & V_5 -> V_5 ) ;
* V_112 += sizeof( struct V_113 ) ;
V_122 += sizeof( struct V_113 ) ;
}
if ( V_111 -> V_131 ) {
if ( V_2 -> V_23 == V_132 ) {
V_115 = (struct V_114 * ) * V_112 ;
memset ( V_115 , 0 ,
sizeof( struct V_114 ) ) ;
V_115 -> V_127 . type =
F_6 ( V_133 ) ;
V_115 -> V_127 . V_129 =
F_6 (
sizeof( struct V_134 ) ) ;
memcpy ( ( T_1 * ) V_115 +
sizeof( struct V_130 ) ,
( T_1 * ) V_111 -> V_131 ,
F_2 ( V_115 -> V_127 . V_129 ) ) ;
if ( ! ( V_9 -> V_5 . V_25 &
V_26 ) )
V_115 -> V_135 . V_136 &=
~ ( V_137 |
V_138 ) ;
* V_112 += sizeof( struct V_114 ) ;
V_122 += sizeof( struct V_114 ) ;
}
V_117 =
(struct V_116 * ) * V_112 ;
memset ( V_117 , 0 ,
sizeof( struct V_116 ) ) ;
V_117 -> V_127 . type = F_6 ( V_139 ) ;
V_117 -> V_127 . V_129 = F_6 (
sizeof( struct V_116 ) -
sizeof( struct V_130 ) ) ;
V_117 -> V_140 [ 0 ] . V_141 =
V_111 -> V_131 -> V_142 ;
V_117 -> V_140 [ 0 ] . V_3 =
F_26 ( ( T_1 ) V_111 -> V_125 ) ;
if ( V_9 -> V_5 . V_25 & V_26 &&
V_111 -> V_131 -> V_136 &
V_137 )
F_27 ( V_117 -> V_140 [ 0 ] .
V_3 ,
( V_111 -> V_131 -> V_136 &
V_138 ) ) ;
* V_112 += sizeof( struct V_116 ) ;
V_122 += sizeof( struct V_116 ) ;
}
if ( V_111 -> V_143 ) {
V_119 = (struct V_118 * ) * V_112 ;
memset ( V_119 , 0 ,
sizeof( struct V_118 ) ) ;
V_119 -> V_127 . type = F_6 ( V_144 ) ;
V_119 -> V_127 . V_129 =
F_6 ( sizeof( V_119 -> V_119 ) ) ;
memcpy ( ( T_1 * ) V_119 +
sizeof( struct V_130 ) ,
V_111 -> V_143 +
sizeof( struct V_123 ) ,
F_2 ( V_119 -> V_127 . V_129 ) ) ;
* V_112 += sizeof( struct V_118 ) ;
V_122 += sizeof( struct V_118 ) ;
}
if ( V_111 -> V_145 ) {
V_124 = ( void * ) V_111 -> V_145 ;
V_121 = (struct V_120 * ) * V_112 ;
memset ( V_121 , 0 , sizeof( struct V_120 ) ) ;
V_121 -> V_127 . type = F_6 ( V_146 ) ;
V_121 -> V_127 . V_129 = F_6 ( V_124 -> V_129 ) ;
memcpy ( ( T_1 * ) V_121 -> V_147 ,
V_111 -> V_145 + sizeof( struct V_123 ) ,
F_2 ( V_121 -> V_127 . V_129 ) ) ;
if ( V_124 -> V_129 > 3 &&
V_121 -> V_147 [ 3 ] & V_148 )
V_2 -> V_149 = true ;
else
V_2 -> V_149 = false ;
* V_112 += sizeof( struct V_120 ) + V_124 -> V_129 ;
V_122 += sizeof( struct V_120 ) + V_124 -> V_129 ;
}
return V_122 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_35 * V_150 )
{
struct V_35 * V_38 ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_38 == V_150 )
return true ;
}
return false ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_35 * V_38 )
{
if ( ! V_38 &&
F_28 ( V_2 , V_38 ) )
return;
F_21 ( V_2 -> V_13 -> V_14 , L_5 , V_38 ) ;
F_30 ( & V_38 -> V_151 ) ;
F_31 ( V_38 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
int V_152 ;
struct V_35 * V_153 , * V_154 ;
unsigned long V_39 ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_33 (del_tbl_ptr, tmp_node,
&priv->tx_ba_stream_tbl_ptr, list)
F_29 ( V_2 , V_153 ) ;
F_12 ( & V_2 -> V_40 , V_39 ) ;
F_34 ( & V_2 -> V_155 ) ;
for ( V_152 = 0 ; V_152 < V_156 ; ++ V_152 )
V_2 -> V_70 [ V_152 ] . V_71 =
V_2 -> V_70 [ V_152 ] . V_157 ;
}
struct V_35 *
F_20 ( struct V_1 * V_2 , int V_43 , T_1 * V_55 )
{
struct V_35 * V_38 ;
unsigned long V_39 ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( F_35 ( V_38 -> V_55 , V_55 ) &&
V_38 -> V_43 == V_43 ) {
F_12 ( & V_2 -> V_40 ,
V_39 ) ;
return V_38 ;
}
}
F_12 ( & V_2 -> V_40 , V_39 ) ;
return NULL ;
}
void F_17 ( struct V_1 * V_2 , T_1 * V_55 , int V_43 ,
enum V_36 V_37 )
{
struct V_35 * V_158 ;
struct V_58 * V_59 ;
unsigned long V_39 ;
if ( ! F_20 ( V_2 , V_43 , V_55 ) ) {
V_158 = F_36 ( sizeof( struct V_35 ) ,
V_159 ) ;
if ( ! V_158 )
return;
V_59 = F_19 ( V_2 , V_43 , V_55 ) ;
if ( V_59 ) {
V_59 -> V_37 = V_37 ;
V_59 -> V_67 = false ;
}
F_34 ( & V_158 -> V_151 ) ;
V_158 -> V_43 = V_43 ;
V_158 -> V_37 = V_37 ;
memcpy ( V_158 -> V_55 , V_55 , V_160 ) ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_37 ( & V_158 -> V_151 , & V_2 -> V_155 ) ;
F_12 ( & V_2 -> V_40 , V_39 ) ;
}
}
int F_16 ( struct V_1 * V_2 , int V_43 , T_1 * V_161 )
{
struct V_162 V_163 ;
T_4 V_164 = V_2 -> V_75 . V_164 ;
static T_1 V_165 ;
int V_166 ;
unsigned long V_39 ;
T_3 V_60 ;
F_21 ( V_2 -> V_13 -> V_14 , L_6 , V_167 , V_43 ) ;
if ( ( F_38 ( V_2 ) == V_168 ) &&
F_39 ( V_2 -> V_13 -> V_169 ) &&
V_2 -> V_13 -> V_108 &&
memcmp ( V_2 -> V_170 , V_161 , V_160 ) ) {
struct V_171 * V_172 ;
F_10 ( & V_2 -> V_173 , V_39 ) ;
V_172 = F_40 ( V_2 , V_161 ) ;
if ( ! V_172 ) {
F_12 ( & V_2 -> V_173 , V_39 ) ;
F_41 ( V_2 -> V_13 -> V_14 ,
L_7 ,
V_161 ) ;
return - 1 ;
}
if ( V_172 -> V_174 )
V_164 = V_175 ;
F_12 ( & V_2 -> V_173 , V_39 ) ;
}
V_60 = ( T_3 ) ( ( V_43 << V_64 ) |
V_164 << V_176 |
V_177 ) ;
if ( V_2 -> V_75 . V_76 &&
( V_2 -> V_70 [ V_43 ] . V_77 != V_72 ) )
V_60 |= V_74 ;
V_163 . V_60 = F_6 ( V_60 ) ;
V_163 . V_178 = F_6 ( ( T_3 ) V_2 -> V_75 . V_179 ) ;
++ V_165 ;
if ( V_165 == 0 )
V_165 = 1 ;
V_163 . V_180 = V_165 ;
memcpy ( & V_163 . V_52 , V_161 , V_160 ) ;
V_166 = F_42 ( V_2 , V_181 ,
0 , 0 , & V_163 , false ) ;
return V_166 ;
}
int F_43 ( struct V_1 * V_2 , int V_43 , T_1 * V_161 ,
int V_182 )
{
struct V_45 V_183 ;
int V_166 ;
T_2 V_48 ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
V_183 . V_48 = F_6 ( V_43 << V_49 ) ;
V_48 = F_2 ( V_183 . V_48 ) ;
if ( V_182 )
V_48 |= V_184 ;
else
V_48 &= ~ V_184 ;
memcpy ( & V_183 . V_52 , V_161 , V_160 ) ;
V_166 = F_42 ( V_2 , V_185 ,
V_88 , 0 , & V_183 , false ) ;
return V_166 ;
}
void F_44 ( struct V_1 * V_2 , T_1 * V_46 )
{
struct V_45 * V_186 =
(struct V_45 * ) V_46 ;
T_2 V_48 = F_2 ( V_186 -> V_48 ) ;
int V_43 ;
V_43 = V_48 >> V_49 ;
F_14 ( V_2 , V_43 , V_186 -> V_52 ,
V_187 , F_15 ( V_48 ) ) ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_188 * V_189 )
{
int V_152 ;
struct V_188 * V_190 = V_189 ;
struct V_191 * V_192 ;
int V_193 = 0 ;
unsigned long V_39 ;
F_10 ( & V_2 -> V_194 , V_39 ) ;
F_11 (rx_reorder_tbl_ptr, &priv->rx_reorder_tbl_ptr,
list) {
V_190 -> V_43 = ( T_3 ) V_192 -> V_43 ;
memcpy ( V_190 -> V_195 , V_192 -> V_195 , V_160 ) ;
V_190 -> V_196 = V_192 -> V_196 ;
V_190 -> V_197 = V_192 -> V_197 ;
for ( V_152 = 0 ; V_152 < V_192 -> V_197 ; ++ V_152 ) {
if ( V_192 -> V_198 [ V_152 ] )
V_190 -> V_112 [ V_152 ] = true ;
else
V_190 -> V_112 [ V_152 ] = false ;
}
V_190 ++ ;
V_193 ++ ;
if ( V_193 >= V_199 )
break;
}
F_12 ( & V_2 -> V_194 , V_39 ) ;
return V_193 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_200 * V_189 )
{
struct V_35 * V_38 ;
struct V_200 * V_190 = V_189 ;
int V_193 = 0 ;
unsigned long V_39 ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
V_190 -> V_43 = ( T_3 ) V_38 -> V_43 ;
F_21 ( V_2 -> V_13 -> V_14 , L_8 ,
V_167 , V_190 -> V_43 ) ;
memcpy ( V_190 -> V_55 , V_38 -> V_55 , V_160 ) ;
V_190 -> V_77 = V_38 -> V_77 ;
V_190 ++ ;
V_193 ++ ;
if ( V_193 >= V_201 )
break;
}
F_12 ( & V_2 -> V_40 , V_39 ) ;
return V_193 ;
}
void F_47 ( struct V_1 * V_2 , T_1 * V_55 )
{
struct V_35 * V_202 , * V_203 ;
unsigned long V_39 ;
if ( ! V_55 )
return;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_33 (tbl, tmp, &priv->tx_ba_stream_tbl_ptr, list) {
if ( ! memcmp ( V_202 -> V_55 , V_55 , V_160 ) ) {
F_12 ( & V_2 -> V_40 ,
V_39 ) ;
F_29 ( V_2 , V_202 ) ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
}
}
F_12 ( & V_2 -> V_40 , V_39 ) ;
return;
}
void F_48 ( struct V_1 * V_2 )
{
V_2 -> V_75 . V_179 = V_204 ;
if ( F_38 ( V_2 ) == V_205 ) {
V_2 -> V_75 . V_164 =
V_206 ;
V_2 -> V_75 . V_207 =
V_208 ;
} else {
V_2 -> V_75 . V_164 =
V_209 ;
V_2 -> V_75 . V_207 =
V_210 ;
}
V_2 -> V_75 . V_76 = true ;
V_2 -> V_75 . V_211 = true ;
return;
}
T_1 F_49 ( int V_212 )
{
T_1 V_213 ;
switch ( V_212 ) {
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
V_213 = V_214 ;
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
V_213 = V_215 ;
break;
case 165 :
default:
V_213 = V_28 ;
break;
}
return V_213 ;
}
