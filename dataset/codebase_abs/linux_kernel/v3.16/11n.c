int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 = F_2 ( V_5 -> V_7 ) ;
struct V_8 * V_9 =
V_2 -> V_10 -> V_11 -> V_12 [ V_3 ] ;
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
T_3 V_58 = F_2 ( V_57 -> V_58 ) ;
V_57 -> V_59 = F_6 ( ( F_2 ( V_57 -> V_59 ) )
& V_60 ) ;
V_43 = ( V_58 & V_61 )
>> V_62 ;
if ( F_2 ( V_57 -> V_63 ) != V_51 ) {
F_14 ( V_2 , V_43 , V_57 -> V_52 ,
V_53 , true ) ;
if ( V_57 -> V_64 != V_65 )
V_2 -> V_66 [ V_43 ] . V_67 =
V_68 ;
return 0 ;
}
V_44 = F_19 ( V_2 , V_43 , V_57 -> V_52 ) ;
if ( V_44 ) {
F_20 ( V_2 -> V_13 -> V_14 , L_2 ) ;
V_44 -> V_37 = V_69 ;
if ( ( V_58 & V_70 ) &&
V_2 -> V_71 . V_72 &&
( V_2 -> V_66 [ V_43 ] . V_73 != V_68 ) )
V_44 -> V_73 = true ;
else
V_44 -> V_73 = false ;
} else {
F_4 ( V_2 -> V_13 -> V_14 , L_3 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_41 * V_74 , int V_75 ,
T_3 * V_76 )
{
struct V_77 * V_78 = & V_74 -> V_47 . V_78 ;
T_3 V_79 = ( T_3 ) V_75 ;
V_74 -> V_80 = F_6 ( V_81 ) ;
V_74 -> V_82 =
F_6 ( sizeof( struct V_77 ) + V_83 ) ;
V_78 -> V_79 = F_6 ( V_79 ) ;
switch ( V_79 ) {
case V_84 :
F_20 ( V_2 -> V_13 -> V_14 , L_4 , * V_76 ) ;
V_78 -> V_85 = F_6 ( * V_76 ) ;
break;
case V_86 :
default:
V_78 -> V_85 = 0 ;
break;
}
return 0 ;
}
int F_22 ( struct V_41 * V_74 ,
int V_75 ,
struct V_87 * V_88 )
{
struct V_89 * V_90 =
& V_74 -> V_47 . V_91 ;
T_3 V_79 = ( T_3 ) V_75 ;
V_74 -> V_80 = F_6 ( V_92 ) ;
V_74 -> V_82 = F_6 ( sizeof( struct V_89 )
+ V_83 ) ;
V_90 -> V_79 = F_6 ( V_79 ) ;
switch ( V_79 ) {
case V_84 :
V_90 -> V_93 = F_6 ( V_88 -> V_93 ) ;
V_90 -> V_94 = 0 ;
break;
case V_86 :
default:
V_90 -> V_94 = 0 ;
break;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_41 * V_74 , T_3 V_75 ,
struct V_95 * V_96 )
{
struct V_97 * V_98 = & V_74 -> V_47 . V_98 ;
V_74 -> V_80 = F_6 ( V_99 ) ;
V_74 -> V_82 = F_6 ( sizeof( struct V_97 ) + V_83 ) ;
V_98 -> V_79 = F_6 ( V_75 ) ;
V_98 -> V_100 = F_6 ( V_96 -> V_101 ) ;
V_98 -> V_102 = F_6 ( V_96 -> V_103 ) ;
if ( V_2 -> V_13 -> V_104 )
V_98 -> V_105 = F_6 ( V_96 -> V_105 ) ;
return 0 ;
}
int
F_24 ( struct V_1 * V_2 ,
struct V_106 * V_107 ,
T_1 * * V_108 )
{
struct V_109 * V_5 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
int V_118 = 0 ;
struct V_8 * V_9 ;
struct V_119 * V_120 ;
T_1 V_3 ;
if ( ! V_108 || ! * V_108 )
return V_118 ;
V_3 = F_25 ( ( T_1 ) V_107 -> V_121 ) ;
V_9 = V_2 -> V_10 -> V_11 -> V_12 [ V_3 ] ;
if ( V_107 -> V_122 ) {
V_5 = (struct V_109 * ) * V_108 ;
memset ( V_5 , 0 , sizeof( struct V_109 ) ) ;
V_5 -> V_123 . type = F_6 ( V_124 ) ;
V_5 -> V_123 . V_125 =
F_6 ( sizeof( struct V_4 ) ) ;
memcpy ( ( T_1 * ) V_5 + sizeof( struct V_126 ) ,
( T_1 * ) V_107 -> V_122 ,
F_2 ( V_5 -> V_123 . V_125 ) ) ;
F_1 ( V_2 , V_3 , & V_5 -> V_5 ) ;
* V_108 += sizeof( struct V_109 ) ;
V_118 += sizeof( struct V_109 ) ;
}
if ( V_107 -> V_127 ) {
if ( V_2 -> V_23 == V_128 ) {
V_111 = (struct V_110 * ) * V_108 ;
memset ( V_111 , 0 ,
sizeof( struct V_110 ) ) ;
V_111 -> V_123 . type =
F_6 ( V_129 ) ;
V_111 -> V_123 . V_125 =
F_6 (
sizeof( struct V_130 ) ) ;
memcpy ( ( T_1 * ) V_111 +
sizeof( struct V_126 ) ,
( T_1 * ) V_107 -> V_127 ,
F_2 ( V_111 -> V_123 . V_125 ) ) ;
if ( ! ( V_9 -> V_5 . V_25 &
V_26 ) )
V_111 -> V_131 . V_132 &=
~ ( V_133 |
V_134 ) ;
* V_108 += sizeof( struct V_110 ) ;
V_118 += sizeof( struct V_110 ) ;
}
V_113 =
(struct V_112 * ) * V_108 ;
memset ( V_113 , 0 ,
sizeof( struct V_112 ) ) ;
V_113 -> V_123 . type = F_6 ( V_135 ) ;
V_113 -> V_123 . V_125 = F_6 (
sizeof( struct V_112 ) -
sizeof( struct V_126 ) ) ;
V_113 -> V_136 [ 0 ] . V_137 =
V_107 -> V_127 -> V_138 ;
V_113 -> V_136 [ 0 ] . V_3 =
F_25 ( ( T_1 ) V_107 -> V_121 ) ;
if ( V_9 -> V_5 . V_25 & V_26 &&
V_107 -> V_127 -> V_132 &
V_133 )
F_26 ( V_113 -> V_136 [ 0 ] .
V_3 ,
( V_107 -> V_127 -> V_132 &
V_134 ) ) ;
* V_108 += sizeof( struct V_112 ) ;
V_118 += sizeof( struct V_112 ) ;
}
if ( V_107 -> V_139 ) {
V_115 = (struct V_114 * ) * V_108 ;
memset ( V_115 , 0 ,
sizeof( struct V_114 ) ) ;
V_115 -> V_123 . type = F_6 ( V_140 ) ;
V_115 -> V_123 . V_125 =
F_6 ( sizeof( V_115 -> V_115 ) ) ;
memcpy ( ( T_1 * ) V_115 +
sizeof( struct V_126 ) ,
V_107 -> V_139 +
sizeof( struct V_119 ) ,
F_2 ( V_115 -> V_123 . V_125 ) ) ;
* V_108 += sizeof( struct V_114 ) ;
V_118 += sizeof( struct V_114 ) ;
}
if ( V_107 -> V_141 ) {
V_120 = ( void * ) V_107 -> V_141 ;
V_117 = (struct V_116 * ) * V_108 ;
memset ( V_117 , 0 , sizeof( struct V_116 ) ) ;
V_117 -> V_123 . type = F_6 ( V_142 ) ;
V_117 -> V_123 . V_125 = F_6 ( V_120 -> V_125 ) ;
memcpy ( ( T_1 * ) V_117 -> V_143 ,
V_107 -> V_141 + sizeof( struct V_119 ) ,
F_2 ( V_117 -> V_123 . V_125 ) ) ;
if ( V_120 -> V_125 > 3 &&
V_117 -> V_143 [ 3 ] & V_144 )
V_2 -> V_145 = true ;
else
V_2 -> V_145 = false ;
* V_108 += sizeof( struct V_116 ) + V_120 -> V_125 ;
V_118 += sizeof( struct V_116 ) + V_120 -> V_125 ;
}
return V_118 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_35 * V_146 )
{
struct V_35 * V_38 ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_38 == V_146 )
return true ;
}
return false ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_35 * V_38 )
{
if ( ! V_38 &&
F_27 ( V_2 , V_38 ) )
return;
F_20 ( V_2 -> V_13 -> V_14 , L_5 , V_38 ) ;
F_29 ( & V_38 -> V_147 ) ;
F_30 ( V_38 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
int V_148 ;
struct V_35 * V_149 , * V_150 ;
unsigned long V_39 ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_32 (del_tbl_ptr, tmp_node,
&priv->tx_ba_stream_tbl_ptr, list)
F_28 ( V_2 , V_149 ) ;
F_12 ( & V_2 -> V_40 , V_39 ) ;
F_33 ( & V_2 -> V_151 ) ;
for ( V_148 = 0 ; V_148 < V_152 ; ++ V_148 )
V_2 -> V_66 [ V_148 ] . V_67 =
V_2 -> V_66 [ V_148 ] . V_153 ;
}
struct V_35 *
F_19 ( struct V_1 * V_2 , int V_43 , T_1 * V_55 )
{
struct V_35 * V_38 ;
unsigned long V_39 ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( F_34 ( V_38 -> V_55 , V_55 ) &&
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
struct V_35 * V_154 ;
unsigned long V_39 ;
if ( ! F_19 ( V_2 , V_43 , V_55 ) ) {
V_154 = F_35 ( sizeof( struct V_35 ) ,
V_155 ) ;
if ( ! V_154 )
return;
F_33 ( & V_154 -> V_147 ) ;
V_154 -> V_43 = V_43 ;
V_154 -> V_37 = V_37 ;
memcpy ( V_154 -> V_55 , V_55 , V_156 ) ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_36 ( & V_154 -> V_147 , & V_2 -> V_151 ) ;
F_12 ( & V_2 -> V_40 , V_39 ) ;
}
}
int F_16 ( struct V_1 * V_2 , int V_43 , T_1 * V_157 )
{
struct V_158 V_159 ;
struct V_160 * V_161 ;
T_4 V_162 = V_2 -> V_71 . V_162 ;
static T_1 V_163 ;
int V_164 ;
T_3 V_58 ;
F_20 ( V_2 -> V_13 -> V_14 , L_6 , V_165 , V_43 ) ;
if ( ( F_37 ( V_2 ) == V_166 ) &&
F_38 ( V_2 -> V_13 -> V_167 ) &&
V_2 -> V_13 -> V_104 &&
memcmp ( V_2 -> V_168 , V_157 , V_156 ) ) {
V_161 = F_39 ( V_2 , V_157 ) ;
if ( ! V_161 ) {
F_40 ( V_2 -> V_13 -> V_14 ,
L_7 ,
V_157 ) ;
return - 1 ;
}
if ( V_161 -> V_169 )
V_162 = V_170 ;
}
V_58 = ( T_3 ) ( ( V_43 << V_62 ) |
V_162 << V_171 |
V_172 ) ;
if ( V_2 -> V_71 . V_72 &&
( V_2 -> V_66 [ V_43 ] . V_73 != V_68 ) )
V_58 |= V_70 ;
V_159 . V_58 = F_6 ( V_58 ) ;
V_159 . V_173 = F_6 ( ( T_3 ) V_2 -> V_71 . V_174 ) ;
++ V_163 ;
if ( V_163 == 0 )
V_163 = 1 ;
V_159 . V_175 = V_163 ;
memcpy ( & V_159 . V_52 , V_157 , V_156 ) ;
V_164 = F_41 ( V_2 , V_176 ,
0 , 0 , & V_159 , false ) ;
return V_164 ;
}
int F_42 ( struct V_1 * V_2 , int V_43 , T_1 * V_157 ,
int V_177 )
{
struct V_45 V_178 ;
int V_164 ;
T_2 V_48 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_48 = F_6 ( V_43 << V_49 ) ;
V_48 = F_2 ( V_178 . V_48 ) ;
if ( V_177 )
V_48 |= V_179 ;
else
V_48 &= ~ V_179 ;
memcpy ( & V_178 . V_52 , V_157 , V_156 ) ;
V_164 = F_41 ( V_2 , V_180 ,
V_84 , 0 , & V_178 , false ) ;
return V_164 ;
}
void F_43 ( struct V_1 * V_2 , T_1 * V_46 )
{
struct V_45 * V_181 =
(struct V_45 * ) V_46 ;
T_2 V_48 = F_2 ( V_181 -> V_48 ) ;
int V_43 ;
V_43 = V_48 >> V_49 ;
F_14 ( V_2 , V_43 , V_181 -> V_52 ,
V_182 , F_15 ( V_48 ) ) ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_183 * V_184 )
{
int V_148 ;
struct V_183 * V_185 = V_184 ;
struct V_186 * V_187 ;
int V_188 = 0 ;
unsigned long V_39 ;
F_10 ( & V_2 -> V_189 , V_39 ) ;
F_11 (rx_reorder_tbl_ptr, &priv->rx_reorder_tbl_ptr,
list) {
V_185 -> V_43 = ( T_3 ) V_187 -> V_43 ;
memcpy ( V_185 -> V_190 , V_187 -> V_190 , V_156 ) ;
V_185 -> V_191 = V_187 -> V_191 ;
V_185 -> V_192 = V_187 -> V_192 ;
for ( V_148 = 0 ; V_148 < V_187 -> V_192 ; ++ V_148 ) {
if ( V_187 -> V_193 [ V_148 ] )
V_185 -> V_108 [ V_148 ] = true ;
else
V_185 -> V_108 [ V_148 ] = false ;
}
V_185 ++ ;
V_188 ++ ;
if ( V_188 >= V_194 )
break;
}
F_12 ( & V_2 -> V_189 , V_39 ) ;
return V_188 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_195 * V_184 )
{
struct V_35 * V_38 ;
struct V_195 * V_185 = V_184 ;
int V_188 = 0 ;
unsigned long V_39 ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_11 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
V_185 -> V_43 = ( T_3 ) V_38 -> V_43 ;
F_20 ( V_2 -> V_13 -> V_14 , L_8 ,
V_165 , V_185 -> V_43 ) ;
memcpy ( V_185 -> V_55 , V_38 -> V_55 , V_156 ) ;
V_185 -> V_73 = V_38 -> V_73 ;
V_185 ++ ;
V_188 ++ ;
if ( V_188 >= V_196 )
break;
}
F_12 ( & V_2 -> V_40 , V_39 ) ;
return V_188 ;
}
void F_46 ( struct V_1 * V_2 , T_1 * V_55 )
{
struct V_35 * V_197 , * V_198 ;
unsigned long V_39 ;
if ( ! V_55 )
return;
F_10 ( & V_2 -> V_40 , V_39 ) ;
F_32 (tbl, tmp, &priv->tx_ba_stream_tbl_ptr, list) {
if ( ! memcmp ( V_197 -> V_55 , V_55 , V_156 ) ) {
F_12 ( & V_2 -> V_40 ,
V_39 ) ;
F_28 ( V_2 , V_197 ) ;
F_10 ( & V_2 -> V_40 , V_39 ) ;
}
}
F_12 ( & V_2 -> V_40 , V_39 ) ;
return;
}
void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_71 . V_174 = V_199 ;
if ( F_37 ( V_2 ) == V_200 ) {
V_2 -> V_71 . V_162 =
V_201 ;
V_2 -> V_71 . V_202 =
V_203 ;
} else {
V_2 -> V_71 . V_162 =
V_204 ;
V_2 -> V_71 . V_202 =
V_205 ;
}
V_2 -> V_71 . V_72 = true ;
V_2 -> V_71 . V_206 = true ;
return;
}
T_1 F_48 ( int V_207 )
{
T_1 V_208 ;
switch ( V_207 ) {
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
V_208 = V_209 ;
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
V_208 = V_210 ;
break;
case 165 :
default:
V_208 = V_28 ;
break;
}
return V_208 ;
}
