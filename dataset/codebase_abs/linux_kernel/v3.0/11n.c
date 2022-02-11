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
( V_9 -> V_5 . V_22 & V_23 ) )
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
F_10 ( V_2 , V_35 ,
V_38 -> V_44 , V_45 ,
F_11 ( V_40 ) ) ;
V_36 = F_5 ( V_2 ,
V_46 ) ;
if ( V_36 )
F_12 ( V_2 , V_36 -> V_35 ,
V_36 -> V_47 ) ;
} else {
if ( F_11 ( V_40 ) ) {
F_13 ( V_2 ,
V_38 -> V_44 , V_35 ,
V_46 ) ;
V_36 = F_5 ( V_2 ,
V_46 ) ;
if ( V_36 )
F_10 ( V_2 ,
V_36 -> V_35 , V_36 -> V_47 ,
V_45 , true ) ;
}
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
F_10 ( V_2 , V_35 ,
V_49 -> V_44 ,
V_45 , true ) ;
if ( V_49 -> V_59 != V_60 )
V_2 -> V_61 [ V_35 ] . V_62 =
V_63 ;
}
return 0 ;
}
int F_18 ( struct V_33 * V_34 , void * V_64 )
{
struct V_65 * V_66 ;
struct V_67 * V_68 = & V_34 -> V_39 . V_68 ;
if ( V_64 ) {
V_66 = (struct V_65 * ) V_64 ;
V_66 -> V_69 = F_2 ( V_68 -> V_70 ) ;
V_66 -> V_71 = F_2 ( V_68 -> V_72 ) ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_33 * V_73 , int V_74 ,
void * V_64 )
{
struct V_75 * V_76 = & V_73 -> V_39 . V_76 ;
T_3 V_77 = ( T_3 ) V_74 ;
T_3 V_78 = * ( ( T_3 * ) V_64 ) ;
V_73 -> V_79 = F_4 ( V_80 ) ;
V_73 -> V_81 =
F_4 ( sizeof( struct V_75 ) + V_82 ) ;
V_76 -> V_77 = F_4 ( V_77 ) ;
switch ( V_77 ) {
case V_83 :
F_16 ( V_2 -> V_56 -> V_57 , L_3 , V_78 ) ;
V_76 -> V_84 = F_4 ( V_78 ) ;
break;
case V_85 :
default:
V_76 -> V_84 = 0 ;
break;
}
return 0 ;
}
int F_20 ( struct V_33 * V_73 ,
int V_74 , void * V_64 )
{
struct V_86 * V_87 =
& V_73 -> V_39 . V_88 ;
T_3 V_77 = ( T_3 ) V_74 ;
struct V_89 * V_90 =
(struct V_89 * ) V_64 ;
V_73 -> V_79 = F_4 ( V_91 ) ;
V_73 -> V_81 = F_4 ( sizeof( struct V_86 )
+ V_82 ) ;
V_87 -> V_77 = F_4 ( V_77 ) ;
switch ( V_77 ) {
case V_83 :
V_87 -> V_92 = F_4 ( V_90 -> V_92 ) ;
V_87 -> V_93 = 0 ;
break;
case V_85 :
default:
V_87 -> V_93 = 0 ;
break;
}
return 0 ;
}
int F_21 ( struct V_33 * V_34 ,
void * V_64 )
{
struct V_89 * V_88 ;
struct V_86 * V_87 =
& V_34 -> V_39 . V_88 ;
if ( V_64 ) {
V_88 =
(struct V_89 * ) V_64 ;
V_88 -> V_92 = F_2 ( V_87 -> V_92 ) ;
V_88 -> V_93 =
F_2 ( V_87 -> V_93 ) ;
}
return 0 ;
}
int F_22 ( struct V_33 * V_73 ,
T_3 V_74 , void * V_64 )
{
struct V_67 * V_68 = & V_73 -> V_39 . V_68 ;
struct V_65 * V_94 =
(struct V_65 * ) V_64 ;
V_73 -> V_79 = F_4 ( V_95 ) ;
V_73 -> V_81 = F_4 ( sizeof( struct V_67 ) + V_82 ) ;
V_68 -> V_77 = F_4 ( V_74 ) ;
V_68 -> V_70 = F_4 ( V_94 -> V_69 ) ;
V_68 -> V_72 = F_4 ( V_94 -> V_71 ) ;
return 0 ;
}
int
F_23 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
T_1 * * V_98 )
{
struct V_4 * V_5 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_107 = 0 ;
struct V_8 * V_9 ;
T_1 V_3 ;
if ( ! V_98 || ! * V_98 )
return V_107 ;
V_3 = F_24 ( ( T_1 ) V_97 -> V_108 ) ;
V_9 = V_2 -> V_10 -> V_11 -> V_12 [ V_3 ] ;
if ( V_97 -> V_109 ) {
V_5 = (struct V_4 * ) * V_98 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_110 . type = F_4 ( V_111 ) ;
V_5 -> V_110 . V_112 =
F_4 ( sizeof( struct V_113 ) ) ;
memcpy ( ( T_1 * ) V_5 + sizeof( struct V_114 ) ,
( T_1 * ) V_97 -> V_109 +
sizeof( struct V_115 ) ,
F_2 ( V_5 -> V_110 . V_112 ) ) ;
F_1 ( V_2 , V_3 , V_5 ) ;
* V_98 += sizeof( struct V_4 ) ;
V_107 += sizeof( struct V_4 ) ;
}
if ( V_97 -> V_116 ) {
if ( V_2 -> V_20 == V_117 ) {
V_100 = (struct V_99 * ) * V_98 ;
memset ( V_100 , 0 ,
sizeof( struct V_99 ) ) ;
V_100 -> V_110 . type =
F_4 ( V_118 ) ;
V_100 -> V_110 . V_112 =
F_4 ( sizeof( struct V_119 ) ) ;
memcpy ( ( T_1 * ) V_100 +
sizeof( struct V_114 ) ,
( T_1 * ) V_97 -> V_116 +
sizeof( struct V_115 ) ,
F_2 ( V_100 -> V_110 . V_112 ) ) ;
if ( ! ( V_9 -> V_5 . V_22 &
V_23 ) )
V_100 -> V_100 . V_120 &=
~ ( V_121 |
V_122 ) ;
* V_98 += sizeof( struct V_99 ) ;
V_107 += sizeof( struct V_99 ) ;
}
V_102 =
(struct V_101 * ) * V_98 ;
memset ( V_102 , 0 ,
sizeof( struct V_101 ) ) ;
V_102 -> V_110 . type = F_4 ( V_123 ) ;
V_102 -> V_110 . V_112 = F_4 (
sizeof( struct V_101 ) -
sizeof( struct V_114 ) ) ;
V_102 -> V_124 [ 0 ] . V_125 =
V_97 -> V_116 -> V_126 ;
V_102 -> V_124 [ 0 ] . V_3 =
F_24 ( ( T_1 ) V_97 -> V_108 ) ;
if ( ( V_9 -> V_5 . V_22 & V_23 )
&& ( V_97 -> V_116 -> V_120 &
V_121 ) )
F_25 ( V_102 -> V_124 [ 0 ] .
V_3 ,
( V_97 -> V_116 -> V_120 &
V_122 ) ) ;
* V_98 += sizeof( struct V_101 ) ;
V_107 += sizeof( struct V_101 ) ;
}
if ( V_97 -> V_127 ) {
V_104 = (struct V_103 * ) * V_98 ;
memset ( V_104 , 0 ,
sizeof( struct V_103 ) ) ;
V_104 -> V_110 . type = F_4 ( V_128 ) ;
V_104 -> V_110 . V_112 =
F_4 ( sizeof( V_104 -> V_104 ) ) ;
memcpy ( ( T_1 * ) V_104 +
sizeof( struct V_114 ) ,
( T_1 * ) V_97 -> V_127 +
sizeof( struct V_115 ) ,
F_2 ( V_104 -> V_110 . V_112 ) ) ;
* V_98 += sizeof( struct V_103 ) ;
V_107 += sizeof( struct V_103 ) ;
}
if ( V_97 -> V_129 ) {
V_106 = (struct V_105 * ) * V_98 ;
memset ( V_106 , 0 , sizeof( struct V_105 ) ) ;
V_106 -> V_110 . type = F_4 ( V_130 ) ;
V_106 -> V_110 . V_112 = F_4 ( sizeof( V_106 -> V_106 ) ) ;
memcpy ( ( T_1 * ) V_106 +
sizeof( struct V_114 ) ,
( T_1 * ) V_97 -> V_129 +
sizeof( struct V_115 ) ,
F_2 ( V_106 -> V_110 . V_112 ) ) ;
* V_98 += sizeof( struct V_105 ) ;
V_107 += sizeof( struct V_105 ) ;
}
return V_107 ;
}
void
F_26 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
T_3 V_131 = V_132 ;
T_3 V_76 , V_133 = 0 ;
if ( V_97 -> V_109 ) {
if ( F_2 ( V_97 -> V_109 -> V_26 ) &
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
F_28 ( V_2 , V_80 ,
V_83 , 0 , & V_76 ) ;
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
F_15 ( struct V_1 * V_2 ,
int V_35 , T_1 * V_47 )
{
struct V_27 * V_30 ;
unsigned long V_31 ;
F_6 ( & V_2 -> V_32 , V_31 ) ;
F_7 (tx_ba_tsr_tbl, &priv->tx_ba_stream_tbl_ptr, list) {
if ( ( ! memcmp ( V_30 -> V_47 , V_47 , V_146 ) )
&& ( V_30 -> V_35 == V_35 ) ) {
F_8 ( & V_2 -> V_32 ,
V_31 ) ;
return V_30 ;
}
}
F_8 ( & V_2 -> V_32 , V_31 ) ;
return NULL ;
}
void F_13 ( struct V_1 * V_2 ,
T_1 * V_47 , int V_35 ,
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
V_83 , 0 , & V_164 ) ;
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
V_168 ,
F_11 ( V_40 ) ) ;
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
V_171 -> V_98 [ V_140 ] = true ;
else
V_171 -> V_98 [ V_140 ] = false ;
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
