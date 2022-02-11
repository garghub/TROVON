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
struct V_37 * V_38 =
(struct V_37 * ) & V_34 -> V_39 . V_38 ;
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
struct V_48 * V_49 =
(struct V_48 * ) & V_34 -> V_39 . V_49 ;
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
int F_18 ( struct V_33 * V_34 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 = & V_34 -> V_39 . V_67 ;
if ( V_65 ) {
V_65 -> V_68 = F_2 ( V_67 -> V_69 ) ;
V_65 -> V_70 = F_2 ( V_67 -> V_71 ) ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_33 * V_72 , int V_73 ,
T_3 * V_74 )
{
struct V_75 * V_76 = & V_72 -> V_39 . V_76 ;
T_3 V_77 = ( T_3 ) V_73 ;
V_72 -> V_78 = F_4 ( V_79 ) ;
V_72 -> V_80 =
F_4 ( sizeof( struct V_75 ) + V_81 ) ;
V_76 -> V_77 = F_4 ( V_77 ) ;
switch ( V_77 ) {
case V_82 :
F_16 ( V_2 -> V_56 -> V_57 , L_3 , * V_74 ) ;
V_76 -> V_83 = F_4 ( * V_74 ) ;
break;
case V_84 :
default:
V_76 -> V_83 = 0 ;
break;
}
return 0 ;
}
int F_20 ( struct V_33 * V_72 ,
int V_73 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 =
& V_72 -> V_39 . V_89 ;
T_3 V_77 = ( T_3 ) V_73 ;
V_72 -> V_78 = F_4 ( V_90 ) ;
V_72 -> V_80 = F_4 ( sizeof( struct V_87 )
+ V_81 ) ;
V_88 -> V_77 = F_4 ( V_77 ) ;
switch ( V_77 ) {
case V_82 :
V_88 -> V_91 = F_4 ( V_86 -> V_91 ) ;
V_88 -> V_92 = 0 ;
break;
case V_84 :
default:
V_88 -> V_92 = 0 ;
break;
}
return 0 ;
}
int F_21 ( struct V_33 * V_34 ,
struct V_85
* V_89 )
{
struct V_87 * V_88 =
& V_34 -> V_39 . V_89 ;
if ( V_89 ) {
V_89 -> V_91 = F_2 ( V_88 -> V_91 ) ;
V_89 -> V_92 =
F_2 ( V_88 -> V_92 ) ;
}
return 0 ;
}
int F_22 ( struct V_33 * V_72 , T_3 V_73 ,
struct V_64 * V_93 )
{
struct V_66 * V_67 = & V_72 -> V_39 . V_67 ;
V_72 -> V_78 = F_4 ( V_94 ) ;
V_72 -> V_80 = F_4 ( sizeof( struct V_66 ) + V_81 ) ;
V_67 -> V_77 = F_4 ( V_73 ) ;
V_67 -> V_69 = F_4 ( V_93 -> V_68 ) ;
V_67 -> V_71 = F_4 ( V_93 -> V_70 ) ;
return 0 ;
}
int
F_23 ( struct V_1 * V_2 ,
struct V_95 * V_96 ,
T_1 * * V_97 )
{
struct V_4 * V_5 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
int V_106 = 0 ;
struct V_8 * V_9 ;
T_1 V_3 ;
if ( ! V_97 || ! * V_97 )
return V_106 ;
V_3 = F_24 ( ( T_1 ) V_96 -> V_107 ) ;
V_9 = V_2 -> V_10 -> V_11 -> V_12 [ V_3 ] ;
if ( V_96 -> V_108 ) {
V_5 = (struct V_4 * ) * V_97 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_109 . type = F_4 ( V_110 ) ;
V_5 -> V_109 . V_111 =
F_4 ( sizeof( struct V_112 ) ) ;
memcpy ( ( T_1 * ) V_5 + sizeof( struct V_113 ) ,
( T_1 * ) V_96 -> V_108 +
sizeof( struct V_114 ) ,
F_2 ( V_5 -> V_109 . V_111 ) ) ;
F_1 ( V_2 , V_3 , V_5 ) ;
* V_97 += sizeof( struct V_4 ) ;
V_106 += sizeof( struct V_4 ) ;
}
if ( V_96 -> V_115 ) {
if ( V_2 -> V_20 == V_116 ) {
V_99 = (struct V_98 * ) * V_97 ;
memset ( V_99 , 0 ,
sizeof( struct V_98 ) ) ;
V_99 -> V_109 . type =
F_4 ( V_117 ) ;
V_99 -> V_109 . V_111 =
F_4 (
sizeof( struct V_118 ) ) ;
memcpy ( ( T_1 * ) V_99 +
sizeof( struct V_113 ) ,
( T_1 * ) V_96 -> V_115 +
sizeof( struct V_114 ) ,
F_2 ( V_99 -> V_109 . V_111 ) ) ;
if ( ! ( V_9 -> V_5 . V_22 &
V_23 ) )
V_99 -> V_119 . V_120 &=
~ ( V_121 |
V_122 ) ;
* V_97 += sizeof( struct V_98 ) ;
V_106 += sizeof( struct V_98 ) ;
}
V_101 =
(struct V_100 * ) * V_97 ;
memset ( V_101 , 0 ,
sizeof( struct V_100 ) ) ;
V_101 -> V_109 . type = F_4 ( V_123 ) ;
V_101 -> V_109 . V_111 = F_4 (
sizeof( struct V_100 ) -
sizeof( struct V_113 ) ) ;
V_101 -> V_124 [ 0 ] . V_125 =
V_96 -> V_115 -> V_126 ;
V_101 -> V_124 [ 0 ] . V_3 =
F_24 ( ( T_1 ) V_96 -> V_107 ) ;
if ( V_9 -> V_5 . V_22 & V_23 &&
V_96 -> V_115 -> V_120 &
V_121 )
F_25 ( V_101 -> V_124 [ 0 ] .
V_3 ,
( V_96 -> V_115 -> V_120 &
V_122 ) ) ;
* V_97 += sizeof( struct V_100 ) ;
V_106 += sizeof( struct V_100 ) ;
}
if ( V_96 -> V_127 ) {
V_103 = (struct V_102 * ) * V_97 ;
memset ( V_103 , 0 ,
sizeof( struct V_102 ) ) ;
V_103 -> V_109 . type = F_4 ( V_128 ) ;
V_103 -> V_109 . V_111 =
F_4 ( sizeof( V_103 -> V_103 ) ) ;
memcpy ( ( T_1 * ) V_103 +
sizeof( struct V_113 ) ,
( T_1 * ) V_96 -> V_127 +
sizeof( struct V_114 ) ,
F_2 ( V_103 -> V_109 . V_111 ) ) ;
* V_97 += sizeof( struct V_102 ) ;
V_106 += sizeof( struct V_102 ) ;
}
if ( V_96 -> V_129 ) {
V_105 = (struct V_104 * ) * V_97 ;
memset ( V_105 , 0 , sizeof( struct V_104 ) ) ;
V_105 -> V_109 . type = F_4 ( V_130 ) ;
V_105 -> V_109 . V_111 = F_4 ( sizeof( V_105 -> V_105 ) ) ;
memcpy ( ( T_1 * ) V_105 +
sizeof( struct V_113 ) ,
( T_1 * ) V_96 -> V_129 +
sizeof( struct V_114 ) ,
F_2 ( V_105 -> V_109 . V_111 ) ) ;
* V_97 += sizeof( struct V_104 ) ;
V_106 += sizeof( struct V_104 ) ;
}
return V_106 ;
}
void
F_26 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
T_3 V_131 = V_132 ;
T_3 V_76 , V_133 = 0 ;
if ( V_96 -> V_108 ) {
if ( F_2 ( V_96 -> V_108 -> V_26 ) &
V_134 )
V_131 = V_135 ;
else
V_131 = V_136 ;
}
V_76 = F_27 ( V_2 -> V_56 -> V_137 , V_131 ) ;
F_16 ( V_2 -> V_56 -> V_57 , L_4 ,
V_131 , V_2 -> V_56 -> V_137 ) ;
if ( V_2 -> V_56 -> V_133 <= V_132 )
V_133 = V_132 ;
else if ( V_2 -> V_56 -> V_133 <= V_136 )
V_133 = V_136 ;
else if ( V_2 -> V_56 -> V_133 <= V_135 )
V_133 = V_135 ;
if ( V_133 != V_76 )
F_28 ( V_2 , V_79 ,
V_82 , 0 , & V_76 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_27 * V_138 )
{
struct V_27 * V_30 ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( V_30 == V_138 )
return true ;
}
return false ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_27 * V_30 )
{
if ( ! V_30 &&
F_29 ( V_2 , V_30 ) )
return;
F_16 ( V_2 -> V_56 -> V_57 , L_5 , V_30 ) ;
F_31 ( & V_30 -> V_139 ) ;
F_32 ( V_30 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
int V_140 ;
struct V_27 * V_141 , * V_142 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_34 (del_tbl_ptr, tmp_node,
&priv->tx_ba_stream_tbl_ptr, list)
F_30 ( V_2 , V_141 ) ;
F_8 ( & V_2 -> V_32 , V_31 ) ;
F_35 ( & V_2 -> V_143 ) ;
for ( V_140 = 0 ; V_140 < V_144 ; ++ V_140 )
V_2 -> V_61 [ V_140 ] . V_62 =
V_2 -> V_61 [ V_140 ] . V_145 ;
}
struct V_27 *
F_15 ( struct V_1 * V_2 , int V_35 , T_1 * V_47 )
{
struct V_27 * V_30 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( ! memcmp ( V_30 -> V_47 , V_47 , V_146 ) &&
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
struct V_27 * V_147 ;
unsigned long V_31 ;
if ( ! F_15 ( V_2 , V_35 , V_47 ) ) {
V_147 = F_36 ( sizeof( struct V_27 ) ,
V_148 ) ;
if ( ! V_147 ) {
F_17 ( V_2 -> V_56 -> V_57 ,
L_6 , V_149 ) ;
return;
}
F_35 ( & V_147 -> V_139 ) ;
V_147 -> V_35 = V_35 ;
V_147 -> V_29 = V_29 ;
memcpy ( V_147 -> V_47 , V_47 , V_146 ) ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_37 ( & V_147 -> V_139 , & V_2 -> V_143 ) ;
F_8 ( & V_2 -> V_32 , V_31 ) ;
}
}
int F_12 ( struct V_1 * V_2 , int V_35 , T_1 * V_150 )
{
struct V_151 V_152 ;
static T_1 V_153 ;
int V_154 ;
F_16 ( V_2 -> V_56 -> V_57 , L_7 , V_149 , V_35 ) ;
V_152 . V_52 = F_4 (
( T_3 ) ( ( V_35 << V_54 ) |
( V_2 -> V_155 .
V_156 << V_157 ) |
V_158 ) ) ;
V_152 . V_159 = F_4 ( ( T_3 ) V_2 -> V_155 . V_160 ) ;
++ V_153 ;
if ( V_153 == 0 )
V_153 = 1 ;
V_152 . V_161 = V_153 ;
memcpy ( & V_152 . V_44 , V_150 , V_146 ) ;
V_154 = F_28 ( V_2 , V_162 ,
0 , 0 , & V_152 ) ;
return V_154 ;
}
int F_38 ( struct V_1 * V_2 , int V_35 , T_1 * V_150 ,
int V_163 )
{
struct V_37 V_164 ;
int V_154 ;
T_2 V_40 ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_40 = F_4 ( V_35 << V_41 ) ;
V_40 = F_2 ( V_164 . V_40 ) ;
if ( V_163 )
V_40 |= V_165 ;
else
V_40 &= ~ V_165 ;
memcpy ( & V_164 . V_44 , V_150 , V_146 ) ;
V_154 = F_28 ( V_2 , V_166 ,
V_82 , 0 , & V_164 ) ;
return V_154 ;
}
void F_39 ( struct V_1 * V_2 , T_1 * V_38 )
{
struct V_37 * V_167 =
(struct V_37 * ) V_38 ;
T_2 V_40 = F_2 ( V_167 -> V_40 ) ;
int V_35 ;
V_35 = V_40 >> V_41 ;
F_10 ( V_2 , V_35 , V_167 -> V_44 ,
V_168 , F_11 ( V_40 ) ) ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
int V_140 ;
struct V_169 * V_171 = V_170 ;
struct V_172 * V_173 ;
int V_174 = 0 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_175 , V_31 ) ;
F_7 (rx_reorder_tbl_ptr, &priv->rx_reorder_tbl_ptr,
list) {
V_171 -> V_35 = ( T_3 ) V_173 -> V_35 ;
memcpy ( V_171 -> V_176 , V_173 -> V_176 , V_146 ) ;
V_171 -> V_177 = V_173 -> V_177 ;
V_171 -> V_178 = V_173 -> V_178 ;
for ( V_140 = 0 ; V_140 < V_173 -> V_178 ; ++ V_140 ) {
if ( V_173 -> V_179 [ V_140 ] )
V_171 -> V_97 [ V_140 ] = true ;
else
V_171 -> V_97 [ V_140 ] = false ;
}
V_171 ++ ;
V_174 ++ ;
if ( V_174 >= V_180 )
break;
}
F_8 ( & V_2 -> V_175 , V_31 ) ;
return V_174 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_181 * V_170 )
{
struct V_27 * V_30 ;
struct V_181 * V_171 = V_170 ;
int V_174 = 0 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
V_171 -> V_35 = ( T_3 ) V_30 -> V_35 ;
F_16 ( V_2 -> V_56 -> V_57 , L_8 ,
V_149 , V_171 -> V_35 ) ;
memcpy ( V_171 -> V_47 , V_30 -> V_47 , V_146 ) ;
V_171 ++ ;
V_174 ++ ;
if ( V_174 >= V_182 )
break;
}
F_8 ( & V_2 -> V_32 , V_31 ) ;
return V_174 ;
}
