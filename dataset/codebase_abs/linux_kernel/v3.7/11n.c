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
V_9 -> V_5 . V_22 & V_23 )
F_3 ( V_5 -> V_5 . V_19 . V_24 ) ;
V_6 &= ~ V_25 ;
V_5 -> V_5 . V_26 = F_4 ( V_9 -> V_5 . V_22 ) ;
V_5 -> V_5 . V_7 = F_4 ( V_6 ) ;
}
static struct V_27 *
F_5 ( struct V_1 * V_2 ,
enum V_28 V_29 )
{
struct V_27 * V_30 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_30 -> V_29 == V_29 ) {
F_8 ( & V_2 -> V_32 ,
V_31 ) ;
return V_30 ;
}
}
F_8 ( & V_2 -> V_32 , V_31 ) ;
return NULL ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_35 ;
struct V_27 * V_36 ;
struct V_37 * V_38 = & V_34 -> V_39 . V_38 ;
T_2 V_40 = F_2 ( V_38 -> V_40 ) ;
V_35 = V_40 >> V_41 ;
if ( V_38 -> V_42 == V_43 ) {
F_10 ( V_2 , V_35 , V_38 -> V_44 ,
V_45 ,
F_11 ( V_40 ) ) ;
V_36 = F_5 ( V_2 , V_46 ) ;
if ( V_36 )
F_12 ( V_2 , V_36 -> V_35 ,
V_36 -> V_47 ) ;
} else {
if ( ! F_11 ( V_40 ) )
return 0 ;
F_13 ( V_2 , V_38 -> V_44 , V_35 ,
V_46 ) ;
V_36 = F_5 ( V_2 , V_46 ) ;
if ( V_36 )
F_10 ( V_2 , V_36 -> V_35 , V_36 -> V_47 ,
V_45 , true ) ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_35 ;
struct V_48 * V_49 = & V_34 -> V_39 . V_49 ;
struct V_27 * V_36 ;
V_49 -> V_50 = F_4 ( ( F_2 ( V_49 -> V_50 ) )
& V_51 ) ;
V_35 = ( F_2 ( V_49 -> V_52 )
& V_53 )
>> V_54 ;
if ( F_2 ( V_49 -> V_55 ) == V_43 ) {
V_36 = F_15 ( V_2 , V_35 ,
V_49 -> V_44 ) ;
if ( V_36 ) {
F_16 ( V_2 -> V_56 -> V_57 , L_1 ) ;
V_36 -> V_29 = V_58 ;
} else {
F_17 ( V_2 -> V_56 -> V_57 , L_2 ) ;
}
} else {
F_10 ( V_2 , V_35 , V_49 -> V_44 ,
V_45 , true ) ;
if ( V_49 -> V_59 != V_60 )
V_2 -> V_61 [ V_35 ] . V_62 =
V_63 ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_33 * V_64 , int V_65 ,
T_3 * V_66 )
{
struct V_67 * V_68 = & V_64 -> V_39 . V_68 ;
T_3 V_69 = ( T_3 ) V_65 ;
V_64 -> V_70 = F_4 ( V_71 ) ;
V_64 -> V_72 =
F_4 ( sizeof( struct V_67 ) + V_73 ) ;
V_68 -> V_69 = F_4 ( V_69 ) ;
switch ( V_69 ) {
case V_74 :
F_16 ( V_2 -> V_56 -> V_57 , L_3 , * V_66 ) ;
V_68 -> V_75 = F_4 ( * V_66 ) ;
break;
case V_76 :
default:
V_68 -> V_75 = 0 ;
break;
}
return 0 ;
}
int F_19 ( struct V_33 * V_64 ,
int V_65 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 =
& V_64 -> V_39 . V_81 ;
T_3 V_69 = ( T_3 ) V_65 ;
V_64 -> V_70 = F_4 ( V_82 ) ;
V_64 -> V_72 = F_4 ( sizeof( struct V_79 )
+ V_73 ) ;
V_80 -> V_69 = F_4 ( V_69 ) ;
switch ( V_69 ) {
case V_74 :
V_80 -> V_83 = F_4 ( V_78 -> V_83 ) ;
V_80 -> V_84 = 0 ;
break;
case V_76 :
default:
V_80 -> V_84 = 0 ;
break;
}
return 0 ;
}
int F_20 ( struct V_33 * V_64 , T_3 V_65 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 = & V_64 -> V_39 . V_88 ;
V_64 -> V_70 = F_4 ( V_89 ) ;
V_64 -> V_72 = F_4 ( sizeof( struct V_87 ) + V_73 ) ;
V_88 -> V_69 = F_4 ( V_65 ) ;
V_88 -> V_90 = F_4 ( V_86 -> V_91 ) ;
V_88 -> V_92 = F_4 ( V_86 -> V_93 ) ;
return 0 ;
}
int
F_21 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
T_1 * * V_96 )
{
struct V_4 * V_5 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
int V_105 = 0 ;
struct V_8 * V_9 ;
T_1 V_3 ;
if ( ! V_96 || ! * V_96 )
return V_105 ;
V_3 = F_22 ( ( T_1 ) V_95 -> V_106 ) ;
V_9 = V_2 -> V_10 -> V_11 -> V_12 [ V_3 ] ;
if ( V_95 -> V_107 ) {
V_5 = (struct V_4 * ) * V_96 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_108 . type = F_4 ( V_109 ) ;
V_5 -> V_108 . V_110 =
F_4 ( sizeof( struct V_111 ) ) ;
memcpy ( ( T_1 * ) V_5 + sizeof( struct V_112 ) ,
( T_1 * ) V_95 -> V_107 +
sizeof( struct V_113 ) ,
F_2 ( V_5 -> V_108 . V_110 ) ) ;
F_1 ( V_2 , V_3 , V_5 ) ;
* V_96 += sizeof( struct V_4 ) ;
V_105 += sizeof( struct V_4 ) ;
}
if ( V_95 -> V_114 ) {
if ( V_2 -> V_20 == V_115 ) {
V_98 = (struct V_97 * ) * V_96 ;
memset ( V_98 , 0 ,
sizeof( struct V_97 ) ) ;
V_98 -> V_108 . type =
F_4 ( V_116 ) ;
V_98 -> V_108 . V_110 =
F_4 (
sizeof( struct V_117 ) ) ;
memcpy ( ( T_1 * ) V_98 +
sizeof( struct V_112 ) ,
( T_1 * ) V_95 -> V_114 +
sizeof( struct V_113 ) ,
F_2 ( V_98 -> V_108 . V_110 ) ) ;
if ( ! ( V_9 -> V_5 . V_22 &
V_23 ) )
V_98 -> V_118 . V_119 &=
~ ( V_120 |
V_121 ) ;
* V_96 += sizeof( struct V_97 ) ;
V_105 += sizeof( struct V_97 ) ;
}
V_100 =
(struct V_99 * ) * V_96 ;
memset ( V_100 , 0 ,
sizeof( struct V_99 ) ) ;
V_100 -> V_108 . type = F_4 ( V_122 ) ;
V_100 -> V_108 . V_110 = F_4 (
sizeof( struct V_99 ) -
sizeof( struct V_112 ) ) ;
V_100 -> V_123 [ 0 ] . V_124 =
V_95 -> V_114 -> V_125 ;
V_100 -> V_123 [ 0 ] . V_3 =
F_22 ( ( T_1 ) V_95 -> V_106 ) ;
if ( V_9 -> V_5 . V_22 & V_23 &&
V_95 -> V_114 -> V_119 &
V_120 )
F_23 ( V_100 -> V_123 [ 0 ] .
V_3 ,
( V_95 -> V_114 -> V_119 &
V_121 ) ) ;
* V_96 += sizeof( struct V_99 ) ;
V_105 += sizeof( struct V_99 ) ;
}
if ( V_95 -> V_126 ) {
V_102 = (struct V_101 * ) * V_96 ;
memset ( V_102 , 0 ,
sizeof( struct V_101 ) ) ;
V_102 -> V_108 . type = F_4 ( V_127 ) ;
V_102 -> V_108 . V_110 =
F_4 ( sizeof( V_102 -> V_102 ) ) ;
memcpy ( ( T_1 * ) V_102 +
sizeof( struct V_112 ) ,
V_95 -> V_126 +
sizeof( struct V_113 ) ,
F_2 ( V_102 -> V_108 . V_110 ) ) ;
* V_96 += sizeof( struct V_101 ) ;
V_105 += sizeof( struct V_101 ) ;
}
if ( V_95 -> V_128 ) {
V_104 = (struct V_103 * ) * V_96 ;
memset ( V_104 , 0 , sizeof( struct V_103 ) ) ;
V_104 -> V_108 . type = F_4 ( V_129 ) ;
V_104 -> V_108 . V_110 = F_4 ( sizeof( V_104 -> V_104 ) ) ;
memcpy ( ( T_1 * ) V_104 + sizeof( struct V_112 ) ,
V_95 -> V_128 + sizeof( struct V_113 ) ,
F_2 ( V_104 -> V_108 . V_110 ) ) ;
* V_96 += sizeof( struct V_103 ) ;
V_105 += sizeof( struct V_103 ) ;
}
return V_105 ;
}
void
F_24 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
T_3 V_130 = V_131 ;
T_3 V_68 , V_132 = 0 ;
if ( V_95 -> V_107 ) {
if ( F_2 ( V_95 -> V_107 -> V_26 ) &
V_133 )
V_130 = V_134 ;
else
V_130 = V_135 ;
}
V_68 = F_25 ( V_2 -> V_56 -> V_136 , V_130 ) ;
F_16 ( V_2 -> V_56 -> V_57 , L_4 ,
V_130 , V_2 -> V_56 -> V_136 ) ;
if ( V_2 -> V_56 -> V_132 <= V_131 )
V_132 = V_131 ;
else if ( V_2 -> V_56 -> V_132 <= V_135 )
V_132 = V_135 ;
else if ( V_2 -> V_56 -> V_132 <= V_134 )
V_132 = V_134 ;
if ( V_132 != V_68 )
F_26 ( V_2 , V_71 ,
V_74 , 0 , & V_68 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_27 * V_137 )
{
struct V_27 * V_30 ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_30 == V_137 )
return true ;
}
return false ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_27 * V_30 )
{
if ( ! V_30 &&
F_27 ( V_2 , V_30 ) )
return;
F_16 ( V_2 -> V_56 -> V_57 , L_5 , V_30 ) ;
F_29 ( & V_30 -> V_138 ) ;
F_30 ( V_30 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
int V_139 ;
struct V_27 * V_140 , * V_141 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_32 (del_tbl_ptr, tmp_node,
&priv->tx_ba_stream_tbl_ptr, list)
F_28 ( V_2 , V_140 ) ;
F_8 ( & V_2 -> V_32 , V_31 ) ;
F_33 ( & V_2 -> V_142 ) ;
for ( V_139 = 0 ; V_139 < V_143 ; ++ V_139 )
V_2 -> V_61 [ V_139 ] . V_62 =
V_2 -> V_61 [ V_139 ] . V_144 ;
}
struct V_27 *
F_15 ( struct V_1 * V_2 , int V_35 , T_1 * V_47 )
{
struct V_27 * V_30 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( ! memcmp ( V_30 -> V_47 , V_47 , V_145 ) &&
V_30 -> V_35 == V_35 ) {
F_8 ( & V_2 -> V_32 ,
V_31 ) ;
return V_30 ;
}
}
F_8 ( & V_2 -> V_32 , V_31 ) ;
return NULL ;
}
void F_13 ( struct V_1 * V_2 , T_1 * V_47 , int V_35 ,
enum V_28 V_29 )
{
struct V_27 * V_146 ;
unsigned long V_31 ;
if ( ! F_15 ( V_2 , V_35 , V_47 ) ) {
V_146 = F_34 ( sizeof( struct V_27 ) ,
V_147 ) ;
if ( ! V_146 ) {
F_17 ( V_2 -> V_56 -> V_57 ,
L_6 , V_148 ) ;
return;
}
F_33 ( & V_146 -> V_138 ) ;
V_146 -> V_35 = V_35 ;
V_146 -> V_29 = V_29 ;
memcpy ( V_146 -> V_47 , V_47 , V_145 ) ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_35 ( & V_146 -> V_138 , & V_2 -> V_142 ) ;
F_8 ( & V_2 -> V_32 , V_31 ) ;
}
}
int F_12 ( struct V_1 * V_2 , int V_35 , T_1 * V_149 )
{
struct V_150 V_151 ;
static T_1 V_152 ;
int V_153 ;
F_16 ( V_2 -> V_56 -> V_57 , L_7 , V_148 , V_35 ) ;
V_151 . V_52 = F_4 (
( T_3 ) ( ( V_35 << V_54 ) |
( V_2 -> V_154 .
V_155 << V_156 ) |
V_157 ) ) ;
V_151 . V_158 = F_4 ( ( T_3 ) V_2 -> V_154 . V_159 ) ;
++ V_152 ;
if ( V_152 == 0 )
V_152 = 1 ;
V_151 . V_160 = V_152 ;
memcpy ( & V_151 . V_44 , V_149 , V_145 ) ;
V_153 = F_26 ( V_2 , V_161 ,
0 , 0 , & V_151 ) ;
return V_153 ;
}
int F_36 ( struct V_1 * V_2 , int V_35 , T_1 * V_149 ,
int V_162 )
{
struct V_37 V_163 ;
int V_153 ;
T_2 V_40 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_40 = F_4 ( V_35 << V_41 ) ;
V_40 = F_2 ( V_163 . V_40 ) ;
if ( V_162 )
V_40 |= V_164 ;
else
V_40 &= ~ V_164 ;
memcpy ( & V_163 . V_44 , V_149 , V_145 ) ;
V_153 = F_26 ( V_2 , V_165 ,
V_74 , 0 , & V_163 ) ;
return V_153 ;
}
void F_37 ( struct V_1 * V_2 , T_1 * V_38 )
{
struct V_37 * V_166 =
(struct V_37 * ) V_38 ;
T_2 V_40 = F_2 ( V_166 -> V_40 ) ;
int V_35 ;
V_35 = V_40 >> V_41 ;
F_10 ( V_2 , V_35 , V_166 -> V_44 ,
V_167 , F_11 ( V_40 ) ) ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
int V_139 ;
struct V_168 * V_170 = V_169 ;
struct V_171 * V_172 ;
int V_173 = 0 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_174 , V_31 ) ;
F_7 (rx_reorder_tbl_ptr, &priv->rx_reorder_tbl_ptr,
list) {
V_170 -> V_35 = ( T_3 ) V_172 -> V_35 ;
memcpy ( V_170 -> V_175 , V_172 -> V_175 , V_145 ) ;
V_170 -> V_176 = V_172 -> V_176 ;
V_170 -> V_177 = V_172 -> V_177 ;
for ( V_139 = 0 ; V_139 < V_172 -> V_177 ; ++ V_139 ) {
if ( V_172 -> V_178 [ V_139 ] )
V_170 -> V_96 [ V_139 ] = true ;
else
V_170 -> V_96 [ V_139 ] = false ;
}
V_170 ++ ;
V_173 ++ ;
if ( V_173 >= V_179 )
break;
}
F_8 ( & V_2 -> V_174 , V_31 ) ;
return V_173 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_180 * V_169 )
{
struct V_27 * V_30 ;
struct V_180 * V_170 = V_169 ;
int V_173 = 0 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
V_170 -> V_35 = ( T_3 ) V_30 -> V_35 ;
F_16 ( V_2 -> V_56 -> V_57 , L_8 ,
V_148 , V_170 -> V_35 ) ;
memcpy ( V_170 -> V_47 , V_30 -> V_47 , V_145 ) ;
V_170 ++ ;
V_173 ++ ;
if ( V_173 >= V_181 )
break;
}
F_8 ( & V_2 -> V_32 , V_31 ) ;
return V_173 ;
}
void F_40 ( struct V_1 * V_2 , T_1 * V_47 )
{
struct V_27 * V_182 , * V_183 ;
unsigned long V_31 ;
if ( ! V_47 )
return;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_32 (tbl, tmp, &priv->tx_ba_stream_tbl_ptr, list) {
if ( ! memcmp ( V_182 -> V_47 , V_47 , V_145 ) ) {
F_8 ( & V_2 -> V_32 ,
V_31 ) ;
F_28 ( V_2 , V_182 ) ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
}
}
F_8 ( & V_2 -> V_32 , V_31 ) ;
return;
}
