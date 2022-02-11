void
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 = F_2 ( V_5 -> V_5 . V_7 ) ;
struct V_8 * V_9 =
V_2 -> V_10 -> V_11 -> V_12 [ V_3 ] ;
V_5 -> V_5 . V_13 =
( V_9 -> V_5 . V_14 &
V_15 ) |
( ( V_9 -> V_5 . V_16 <<
V_17 ) &
V_18 ) ;
memcpy ( ( T_1 * ) & V_5 -> V_5 . V_19 , & V_9 -> V_5 . V_19 ,
sizeof( V_9 -> V_5 . V_19 ) ) ;
if ( V_2 -> V_20 == V_21 ||
( V_9 -> V_5 . V_22 & V_23 &&
( V_2 -> V_24 -> V_25 !=
V_26 ) ) )
F_3 ( V_5 -> V_5 . V_19 . V_27 ) ;
V_6 &= ~ V_28 ;
V_5 -> V_5 . V_29 = F_4 ( V_9 -> V_5 . V_22 ) ;
V_5 -> V_5 . V_7 = F_4 ( V_6 ) ;
}
static struct V_30 *
F_5 ( struct V_1 * V_2 ,
enum V_31 V_32 )
{
struct V_30 * V_33 ;
unsigned long V_34 ;
F_6 ( & V_2 -> V_35 , V_34 ) ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_33 -> V_32 == V_32 ) {
F_8 ( & V_2 -> V_35 ,
V_34 ) ;
return V_33 ;
}
}
F_8 ( & V_2 -> V_35 , V_34 ) ;
return NULL ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_38 ;
struct V_30 * V_39 ;
struct V_40 * V_41 = & V_37 -> V_42 . V_41 ;
T_2 V_43 = F_2 ( V_41 -> V_43 ) ;
V_38 = V_43 >> V_44 ;
if ( V_41 -> V_45 == V_46 ) {
F_10 ( V_2 , V_38 , V_41 -> V_47 ,
V_48 ,
F_11 ( V_43 ) ) ;
V_39 = F_5 ( V_2 , V_49 ) ;
if ( V_39 )
F_12 ( V_2 , V_39 -> V_38 ,
V_39 -> V_50 ) ;
} else {
if ( ! F_11 ( V_43 ) )
return 0 ;
F_13 ( V_2 , V_41 -> V_47 , V_38 ,
V_49 ) ;
V_39 = F_5 ( V_2 , V_49 ) ;
if ( V_39 )
F_10 ( V_2 , V_39 -> V_38 , V_39 -> V_50 ,
V_48 , true ) ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_38 ;
struct V_51 * V_52 = & V_37 -> V_42 . V_52 ;
struct V_30 * V_39 ;
V_52 -> V_53 = F_4 ( ( F_2 ( V_52 -> V_53 ) )
& V_54 ) ;
V_38 = ( F_2 ( V_52 -> V_55 )
& V_56 )
>> V_57 ;
if ( F_2 ( V_52 -> V_58 ) == V_46 ) {
V_39 = F_15 ( V_2 , V_38 ,
V_52 -> V_47 ) ;
if ( V_39 ) {
F_16 ( V_2 -> V_24 -> V_59 , L_1 ) ;
V_39 -> V_32 = V_60 ;
} else {
F_17 ( V_2 -> V_24 -> V_59 , L_2 ) ;
}
} else {
F_10 ( V_2 , V_38 , V_52 -> V_47 ,
V_48 , true ) ;
if ( V_52 -> V_61 != V_62 )
V_2 -> V_63 [ V_38 ] . V_64 =
V_65 ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_36 * V_66 , int V_67 ,
T_3 * V_68 )
{
struct V_69 * V_70 = & V_66 -> V_42 . V_70 ;
T_3 V_71 = ( T_3 ) V_67 ;
V_66 -> V_72 = F_4 ( V_73 ) ;
V_66 -> V_74 =
F_4 ( sizeof( struct V_69 ) + V_75 ) ;
V_70 -> V_71 = F_4 ( V_71 ) ;
switch ( V_71 ) {
case V_76 :
F_16 ( V_2 -> V_24 -> V_59 , L_3 , * V_68 ) ;
V_70 -> V_77 = F_4 ( * V_68 ) ;
break;
case V_78 :
default:
V_70 -> V_77 = 0 ;
break;
}
return 0 ;
}
int F_19 ( struct V_36 * V_66 ,
int V_67 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 =
& V_66 -> V_42 . V_83 ;
T_3 V_71 = ( T_3 ) V_67 ;
V_66 -> V_72 = F_4 ( V_84 ) ;
V_66 -> V_74 = F_4 ( sizeof( struct V_81 )
+ V_75 ) ;
V_82 -> V_71 = F_4 ( V_71 ) ;
switch ( V_71 ) {
case V_76 :
V_82 -> V_85 = F_4 ( V_80 -> V_85 ) ;
V_82 -> V_86 = 0 ;
break;
case V_78 :
default:
V_82 -> V_86 = 0 ;
break;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_36 * V_66 , T_3 V_67 ,
struct V_87 * V_88 )
{
struct V_89 * V_90 = & V_66 -> V_42 . V_90 ;
V_66 -> V_72 = F_4 ( V_91 ) ;
V_66 -> V_74 = F_4 ( sizeof( struct V_89 ) + V_75 ) ;
V_90 -> V_71 = F_4 ( V_67 ) ;
V_90 -> V_92 = F_4 ( V_88 -> V_93 ) ;
V_90 -> V_94 = F_4 ( V_88 -> V_95 ) ;
if ( V_2 -> V_24 -> V_96 )
V_90 -> V_97 = F_4 ( V_88 -> V_97 ) ;
return 0 ;
}
int
F_21 ( struct V_1 * V_2 ,
struct V_98 * V_99 ,
T_1 * * V_100 )
{
struct V_4 * V_5 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
int V_109 = 0 ;
struct V_8 * V_9 ;
struct V_110 * V_111 ;
T_1 V_3 ;
if ( ! V_100 || ! * V_100 )
return V_109 ;
V_3 = F_22 ( ( T_1 ) V_99 -> V_112 ) ;
V_9 = V_2 -> V_10 -> V_11 -> V_12 [ V_3 ] ;
if ( V_99 -> V_113 ) {
V_5 = (struct V_4 * ) * V_100 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_114 . type = F_4 ( V_115 ) ;
V_5 -> V_114 . V_116 =
F_4 ( sizeof( struct V_117 ) ) ;
memcpy ( ( T_1 * ) V_5 + sizeof( struct V_118 ) ,
( T_1 * ) V_99 -> V_113 ,
F_2 ( V_5 -> V_114 . V_116 ) ) ;
F_1 ( V_2 , V_3 , V_5 ) ;
* V_100 += sizeof( struct V_4 ) ;
V_109 += sizeof( struct V_4 ) ;
}
if ( V_99 -> V_119 ) {
if ( V_2 -> V_20 == V_120 ) {
V_102 = (struct V_101 * ) * V_100 ;
memset ( V_102 , 0 ,
sizeof( struct V_101 ) ) ;
V_102 -> V_114 . type =
F_4 ( V_121 ) ;
V_102 -> V_114 . V_116 =
F_4 (
sizeof( struct V_122 ) ) ;
memcpy ( ( T_1 * ) V_102 +
sizeof( struct V_118 ) ,
( T_1 * ) V_99 -> V_119 +
sizeof( struct V_110 ) ,
F_2 ( V_102 -> V_114 . V_116 ) ) ;
if ( ! ( V_9 -> V_5 . V_22 &
V_23 ) )
V_102 -> V_123 . V_124 &=
~ ( V_125 |
V_126 ) ;
* V_100 += sizeof( struct V_101 ) ;
V_109 += sizeof( struct V_101 ) ;
}
V_104 =
(struct V_103 * ) * V_100 ;
memset ( V_104 , 0 ,
sizeof( struct V_103 ) ) ;
V_104 -> V_114 . type = F_4 ( V_127 ) ;
V_104 -> V_114 . V_116 = F_4 (
sizeof( struct V_103 ) -
sizeof( struct V_118 ) ) ;
V_104 -> V_128 [ 0 ] . V_129 =
V_99 -> V_119 -> V_130 ;
V_104 -> V_128 [ 0 ] . V_3 =
F_22 ( ( T_1 ) V_99 -> V_112 ) ;
if ( V_9 -> V_5 . V_22 & V_23 &&
V_99 -> V_119 -> V_124 &
V_125 )
F_23 ( V_104 -> V_128 [ 0 ] .
V_3 ,
( V_99 -> V_119 -> V_124 &
V_126 ) ) ;
* V_100 += sizeof( struct V_103 ) ;
V_109 += sizeof( struct V_103 ) ;
}
if ( V_99 -> V_131 ) {
V_106 = (struct V_105 * ) * V_100 ;
memset ( V_106 , 0 ,
sizeof( struct V_105 ) ) ;
V_106 -> V_114 . type = F_4 ( V_132 ) ;
V_106 -> V_114 . V_116 =
F_4 ( sizeof( V_106 -> V_106 ) ) ;
memcpy ( ( T_1 * ) V_106 +
sizeof( struct V_118 ) ,
V_99 -> V_131 +
sizeof( struct V_110 ) ,
F_2 ( V_106 -> V_114 . V_116 ) ) ;
* V_100 += sizeof( struct V_105 ) ;
V_109 += sizeof( struct V_105 ) ;
}
if ( V_99 -> V_133 ) {
V_111 = ( void * ) V_99 -> V_133 ;
V_108 = (struct V_107 * ) * V_100 ;
memset ( V_108 , 0 , sizeof( struct V_107 ) ) ;
V_108 -> V_114 . type = F_4 ( V_134 ) ;
V_108 -> V_114 . V_116 = F_4 ( V_111 -> V_116 ) ;
memcpy ( ( T_1 * ) V_108 -> V_135 ,
V_99 -> V_133 + sizeof( struct V_110 ) ,
F_2 ( V_108 -> V_114 . V_116 ) ) ;
if ( V_111 -> V_116 > 3 &&
V_108 -> V_135 [ 3 ] & V_136 )
V_2 -> V_137 = true ;
else
V_2 -> V_137 = false ;
* V_100 += sizeof( struct V_107 ) + V_111 -> V_116 ;
V_109 += sizeof( struct V_107 ) + V_111 -> V_116 ;
}
return V_109 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_30 * V_138 )
{
struct V_30 * V_33 ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_33 == V_138 )
return true ;
}
return false ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_30 * V_33 )
{
if ( ! V_33 &&
F_24 ( V_2 , V_33 ) )
return;
F_16 ( V_2 -> V_24 -> V_59 , L_4 , V_33 ) ;
F_26 ( & V_33 -> V_139 ) ;
F_27 ( V_33 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
int V_140 ;
struct V_30 * V_141 , * V_142 ;
unsigned long V_34 ;
F_6 ( & V_2 -> V_35 , V_34 ) ;
F_29 (del_tbl_ptr, tmp_node,
&priv->tx_ba_stream_tbl_ptr, list)
F_25 ( V_2 , V_141 ) ;
F_8 ( & V_2 -> V_35 , V_34 ) ;
F_30 ( & V_2 -> V_143 ) ;
for ( V_140 = 0 ; V_140 < V_144 ; ++ V_140 )
V_2 -> V_63 [ V_140 ] . V_64 =
V_2 -> V_63 [ V_140 ] . V_145 ;
}
struct V_30 *
F_15 ( struct V_1 * V_2 , int V_38 , T_1 * V_50 )
{
struct V_30 * V_33 ;
unsigned long V_34 ;
F_6 ( & V_2 -> V_35 , V_34 ) ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( F_31 ( V_33 -> V_50 , V_50 ) &&
V_33 -> V_38 == V_38 ) {
F_8 ( & V_2 -> V_35 ,
V_34 ) ;
return V_33 ;
}
}
F_8 ( & V_2 -> V_35 , V_34 ) ;
return NULL ;
}
void F_13 ( struct V_1 * V_2 , T_1 * V_50 , int V_38 ,
enum V_31 V_32 )
{
struct V_30 * V_146 ;
unsigned long V_34 ;
if ( ! F_15 ( V_2 , V_38 , V_50 ) ) {
V_146 = F_32 ( sizeof( struct V_30 ) ,
V_147 ) ;
if ( ! V_146 )
return;
F_30 ( & V_146 -> V_139 ) ;
V_146 -> V_38 = V_38 ;
V_146 -> V_32 = V_32 ;
memcpy ( V_146 -> V_50 , V_50 , V_148 ) ;
F_6 ( & V_2 -> V_35 , V_34 ) ;
F_33 ( & V_146 -> V_139 , & V_2 -> V_143 ) ;
F_8 ( & V_2 -> V_35 , V_34 ) ;
}
}
int F_12 ( struct V_1 * V_2 , int V_38 , T_1 * V_149 )
{
struct V_150 V_151 ;
static T_1 V_152 ;
int V_153 ;
F_16 ( V_2 -> V_24 -> V_59 , L_5 , V_154 , V_38 ) ;
V_151 . V_55 = F_4 (
( T_3 ) ( ( V_38 << V_57 ) |
( V_2 -> V_155 .
V_156 << V_157 ) |
V_158 ) ) ;
V_151 . V_159 = F_4 ( ( T_3 ) V_2 -> V_155 . V_160 ) ;
++ V_152 ;
if ( V_152 == 0 )
V_152 = 1 ;
V_151 . V_161 = V_152 ;
memcpy ( & V_151 . V_47 , V_149 , V_148 ) ;
V_153 = F_34 ( V_2 , V_162 ,
0 , 0 , & V_151 ) ;
return V_153 ;
}
int F_35 ( struct V_1 * V_2 , int V_38 , T_1 * V_149 ,
int V_163 )
{
struct V_40 V_164 ;
int V_153 ;
T_2 V_43 ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_43 = F_4 ( V_38 << V_44 ) ;
V_43 = F_2 ( V_164 . V_43 ) ;
if ( V_163 )
V_43 |= V_165 ;
else
V_43 &= ~ V_165 ;
memcpy ( & V_164 . V_47 , V_149 , V_148 ) ;
V_153 = F_34 ( V_2 , V_166 ,
V_76 , 0 , & V_164 ) ;
return V_153 ;
}
void F_36 ( struct V_1 * V_2 , T_1 * V_41 )
{
struct V_40 * V_167 =
(struct V_40 * ) V_41 ;
T_2 V_43 = F_2 ( V_167 -> V_43 ) ;
int V_38 ;
V_38 = V_43 >> V_44 ;
F_10 ( V_2 , V_38 , V_167 -> V_47 ,
V_168 , F_11 ( V_43 ) ) ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
int V_140 ;
struct V_169 * V_171 = V_170 ;
struct V_172 * V_173 ;
int V_174 = 0 ;
unsigned long V_34 ;
F_6 ( & V_2 -> V_175 , V_34 ) ;
F_7 (rx_reorder_tbl_ptr, &priv->rx_reorder_tbl_ptr,
list) {
V_171 -> V_38 = ( T_3 ) V_173 -> V_38 ;
memcpy ( V_171 -> V_176 , V_173 -> V_176 , V_148 ) ;
V_171 -> V_177 = V_173 -> V_177 ;
V_171 -> V_178 = V_173 -> V_178 ;
for ( V_140 = 0 ; V_140 < V_173 -> V_178 ; ++ V_140 ) {
if ( V_173 -> V_179 [ V_140 ] )
V_171 -> V_100 [ V_140 ] = true ;
else
V_171 -> V_100 [ V_140 ] = false ;
}
V_171 ++ ;
V_174 ++ ;
if ( V_174 >= V_180 )
break;
}
F_8 ( & V_2 -> V_175 , V_34 ) ;
return V_174 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_181 * V_170 )
{
struct V_30 * V_33 ;
struct V_181 * V_171 = V_170 ;
int V_174 = 0 ;
unsigned long V_34 ;
F_6 ( & V_2 -> V_35 , V_34 ) ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
V_171 -> V_38 = ( T_3 ) V_33 -> V_38 ;
F_16 ( V_2 -> V_24 -> V_59 , L_6 ,
V_154 , V_171 -> V_38 ) ;
memcpy ( V_171 -> V_50 , V_33 -> V_50 , V_148 ) ;
V_171 ++ ;
V_174 ++ ;
if ( V_174 >= V_182 )
break;
}
F_8 ( & V_2 -> V_35 , V_34 ) ;
return V_174 ;
}
void F_39 ( struct V_1 * V_2 , T_1 * V_50 )
{
struct V_30 * V_183 , * V_184 ;
unsigned long V_34 ;
if ( ! V_50 )
return;
F_6 ( & V_2 -> V_35 , V_34 ) ;
F_29 (tbl, tmp, &priv->tx_ba_stream_tbl_ptr, list) {
if ( ! memcmp ( V_183 -> V_50 , V_50 , V_148 ) ) {
F_8 ( & V_2 -> V_35 ,
V_34 ) ;
F_25 ( V_2 , V_183 ) ;
F_6 ( & V_2 -> V_35 , V_34 ) ;
}
}
F_8 ( & V_2 -> V_35 , V_34 ) ;
return;
}
void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_155 . V_160 = V_185 ;
if ( F_41 ( V_2 ) == V_186 ) {
V_2 -> V_155 . V_156 =
V_187 ;
V_2 -> V_155 . V_188 =
V_189 ;
} else {
V_2 -> V_155 . V_156 =
V_190 ;
V_2 -> V_155 . V_188 =
V_191 ;
}
return;
}
