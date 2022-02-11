static void
F_1 ( const struct V_1 * V_2 )
{
const char * V_3 [] = { L_1 , L_2 , L_3 , L_4 } ;
F_2 ( L_5
L_6 ,
V_3 [ V_4 [ ( V_2 -> V_5
& V_6 ) >> 5 ] ] ,
( V_2 -> V_5 & V_6 ) >> 5 ,
( V_2 -> V_5 & V_7 ) >> 4 ,
V_2 -> V_5 & V_8 ,
V_2 -> V_9 & V_10 ,
( V_2 -> V_9 & V_11 ) >> 4 ,
F_3 ( V_2 -> V_12 ) ) ;
}
static struct V_13 *
F_4 ( struct V_14 * V_15 , const T_1 * V_16 )
{
struct V_13 * V_17 ;
V_17 = F_5 ( sizeof( struct V_13 ) , V_18 ) ;
if ( ! V_17 )
return NULL ;
F_6 ( & V_17 -> V_19 ) ;
F_7 ( & V_17 -> V_20 ) ;
memcpy ( V_17 -> V_16 , V_16 , V_21 ) ;
V_17 -> V_22 = 0 ;
F_8 ( V_15 -> V_23 , L_7 , V_17 ) ;
return V_17 ;
}
static T_1 F_9 ( void )
{
T_2 V_24 , V_25 ;
struct V_26 V_27 ;
T_1 V_28 ;
F_10 ( & V_27 ) ;
V_24 = ( V_27 . V_29 & 0xFFFF ) + ( V_27 . V_29 >> 16 ) ;
V_25 = ( V_27 . V_30 & 0xFFFF ) + ( V_27 . V_30 >> 16 ) ;
V_28 = ( ( ( V_24 << 16 ) + V_25 ) % V_31 )
+ V_32 ;
return V_28 ;
}
void F_11 ( struct V_33 * V_34 , const T_1 * V_16 )
{
int V_35 ;
struct V_13 * V_17 ;
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_36 * V_37 ;
unsigned long V_38 ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
V_17 = F_4 ( V_15 , V_16 ) ;
F_8 ( V_15 -> V_23 , L_8 , V_17 ) ;
if ( ! V_17 )
break;
V_17 -> V_40 = 0 ;
V_17 -> V_41 = false ;
V_17 -> V_42 = V_43 ;
V_17 -> V_44 = false ;
if ( ! F_12 ( V_34 ) ) {
if ( F_13 ( V_34 , V_16 ) ==
V_45 ) {
V_17 -> V_41 = true ;
V_17 -> V_40 =
F_14 ( V_34 , V_16 ) ;
} else {
V_17 -> V_40 = F_15 ( V_34 ) ;
}
} else {
F_16 ( & V_34 -> V_46 , V_38 ) ;
V_37 = F_17 ( V_34 , V_16 ) ;
V_17 -> V_40 =
F_18 ( V_34 , V_37 ) ;
if ( V_17 -> V_40 )
V_17 -> V_47 = V_37 -> V_47 ;
F_19 ( & V_34 -> V_46 , V_38 ) ;
}
F_8 ( V_15 -> V_23 , L_9 ,
V_17 , V_17 -> V_40 ) ;
if ( V_17 -> V_40 ) {
V_17 -> V_48 = 0 ;
V_17 -> V_49 =
F_9 () ;
}
F_20 ( & V_17 -> V_19 ,
& V_34 -> V_50 . V_51 [ V_35 ] . V_17 ) ;
}
}
static void F_21 ( struct V_33 * V_34 )
{
V_34 -> V_50 . V_52 [ 0 ] = V_53 ;
V_34 -> V_50 . V_52 [ 1 ] = V_54 ;
V_34 -> V_50 . V_52 [ 2 ] = V_55 ;
V_34 -> V_50 . V_52 [ 3 ] = V_56 ;
}
static void
F_22 ( struct V_33 * V_34 )
{
struct V_57 * V_50 = & V_34 -> V_50 ;
T_1 * V_52 = V_50 -> V_52 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 4 ; ++ V_35 ) {
V_58 [ 7 - ( V_35 * 2 ) ] = V_59 [ V_52 [ V_35 ] ] [ 1 ] ;
V_58 [ 6 - ( V_35 * 2 ) ] = V_59 [ V_52 [ V_35 ] ] [ 0 ] ;
}
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 )
V_34 -> V_60 [ V_58 [ V_35 ] ] = ( T_1 ) V_35 ;
F_23 ( & V_50 -> V_61 , V_62 ) ;
}
void
F_24 ( struct V_33 * V_34 ,
struct V_63 * V_64 )
{
T_3 V_65 , V_66 , V_67 [ 4 ] ;
T_2 V_35 , V_68 , V_69 ;
T_1 V_70 ;
if ( ! V_64 || ! V_34 -> V_71 ) {
F_21 ( V_34 ) ;
return;
}
F_8 ( V_34 -> V_15 -> V_23 , L_10
L_11 ,
V_64 -> V_72 . V_73 , V_64 -> V_74 &
V_75 ,
V_64 -> V_76 ) ;
for ( V_69 = 0 ; V_69 < F_25 ( V_64 -> V_77 ) ; V_69 ++ ) {
T_1 V_78 = V_64 -> V_77 [ V_69 ] . V_9 ;
T_1 V_79 = V_64 -> V_77 [ V_69 ] . V_5 ;
V_65 = ( 1 << ( V_78 & V_10 ) ) - 1 ;
V_66 = ( V_65 >> 1 ) + ( V_79 & V_8 ) ;
V_70 = V_4 [ ( V_79 & V_6 ) >> 5 ] ;
V_34 -> V_50 . V_52 [ V_70 ] = V_70 ;
V_67 [ V_70 ] = V_66 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_12 ,
( 1 << ( ( V_78 & V_11 ) >> 4 ) ) - 1 ,
V_65 , V_66 ) ;
F_1 ( & V_64 -> V_77 [ V_69 ] ) ;
}
for ( V_35 = 0 ; V_35 < V_69 ; V_35 ++ ) {
for ( V_68 = 1 ; V_68 < V_69 - V_35 ; V_68 ++ ) {
if ( V_67 [ V_68 - 1 ] > V_67 [ V_68 ] ) {
F_26 ( V_67 [ V_68 - 1 ] , V_67 [ V_68 ] ) ;
F_26 ( V_34 -> V_50 . V_52 [ V_68 - 1 ] ,
V_34 -> V_50 . V_52 [ V_68 ] ) ;
} else if ( V_67 [ V_68 - 1 ] == V_67 [ V_68 ] ) {
if ( V_34 -> V_50 . V_52 [ V_68 - 1 ]
< V_34 -> V_50 . V_52 [ V_68 ] )
F_26 ( V_34 -> V_50 . V_52 [ V_68 - 1 ] ,
V_34 -> V_50 . V_52 [ V_68 ] ) ;
}
}
}
F_22 ( V_34 ) ;
}
static enum V_80
F_27 ( struct V_33 * V_34 ,
enum V_80 V_81 )
{
int V_82 ;
enum V_80 V_83 ;
struct V_84 * V_85 ;
V_85 = & V_34 -> V_50 . V_85 [ V_81 ] ;
if ( ! V_85 -> V_86 )
return V_81 ;
V_83 = V_56 ;
for ( V_82 = V_56 ; V_82 < V_81 ; V_82 ++ ) {
V_85 = & V_34 -> V_50 . V_85 [ V_82 ] ;
if ( ! V_85 -> V_86 && ! V_85 -> V_87 )
V_83 = (enum V_80 ) V_82 ;
}
return V_83 ;
}
void
F_28 ( struct V_33 * V_34 )
{
int V_88 ;
F_8 ( V_34 -> V_15 -> V_23 , L_13
L_14 ) ;
if ( ! V_34 -> V_71 ) {
for ( V_88 = V_56 ; V_88 <= V_53 ; V_88 ++ )
V_34 -> V_50 . V_89 [ V_88 ] =
(enum V_80 ) V_88 ;
} else {
for ( V_88 = V_56 ; V_88 <= V_53 ; V_88 ++ ) {
V_34 -> V_50 . V_89 [ V_88 ]
= F_27 ( V_34 ,
(enum V_80 ) V_88 ) ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_15 ,
V_88 , V_34 -> V_50 . V_89 [ V_88 ] ) ;
}
}
}
static enum V_80
F_29 ( struct V_14 * V_15 , T_2 V_90 )
{
const enum V_80 V_91 [] = { V_55 ,
V_56 ,
V_56 ,
V_55 ,
V_54 ,
V_54 ,
V_53 ,
V_53
} ;
if ( V_90 >= F_25 ( V_91 ) )
return V_55 ;
return V_91 [ V_90 ] ;
}
T_1 F_30 ( struct V_33 * V_34 , T_2 V_92 )
{
enum V_80 V_93 , V_94 ;
T_1 V_95 ;
V_93 = F_29 ( V_34 -> V_15 , V_92 ) ;
V_94 = V_34 -> V_50 . V_89 [ V_93 ] ;
V_95 = V_59 [ V_94 ] [ V_92 % 2 ] ;
return V_95 ;
}
void
F_31 ( struct V_14 * V_15 )
{
int V_35 , V_68 ;
struct V_33 * V_34 ;
for ( V_68 = 0 ; V_68 < V_15 -> V_96 ; ++ V_68 ) {
V_34 = V_15 -> V_34 [ V_68 ] ;
if ( ! V_34 )
continue;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
if ( ! V_97 &&
V_15 -> V_98 > V_99 )
V_34 -> V_100 [ V_35 ] . V_101 =
V_34 -> V_60 [ V_35 ] ;
else
V_34 -> V_100 [ V_35 ] . V_101 =
V_102 ;
V_34 -> V_100 [ V_35 ] . V_103 =
V_34 -> V_60 [ V_35 ] ;
V_34 -> V_100 [ V_35 ] . V_104 =
V_34 -> V_60 [ V_35 ] ;
}
F_32 ( V_34 ) ;
F_33 ( V_34 ) ;
F_23 ( & V_34 -> V_50 . V_105 , 0 ) ;
F_23 ( & V_34 -> V_50 . V_61 , V_62 ) ;
}
}
int
F_34 ( struct V_14 * V_15 )
{
int V_35 ;
struct V_33 * V_34 ;
for ( V_35 = 0 ; V_35 < V_15 -> V_96 ; ++ V_35 ) {
V_34 = V_15 -> V_34 [ V_35 ] ;
if ( V_34 && F_35 ( & V_34 -> V_50 . V_105 ) )
return false ;
}
return true ;
}
static void
F_36 ( struct V_33 * V_34 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_106 * V_107 , * V_67 ;
F_37 (&ra_list->skb_head, skb, tmp)
F_38 ( V_15 , V_107 , 0 , - 1 ) ;
}
static void
F_39 ( struct V_33 * V_34 ,
struct V_108 * V_109 )
{
struct V_13 * V_17 ;
F_40 (ra_list, ra_list_head, list)
F_36 ( V_34 , V_17 ) ;
}
static void F_41 ( struct V_33 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_39 ; V_35 ++ )
F_39 ( V_34 , & V_34 -> V_50 . V_51 [ V_35 ] .
V_17 ) ;
F_23 ( & V_34 -> V_50 . V_105 , 0 ) ;
F_23 ( & V_34 -> V_50 . V_61 , V_62 ) ;
}
static void F_42 ( struct V_33 * V_34 )
{
struct V_13 * V_17 , * V_110 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
F_8 ( V_34 -> V_15 -> V_23 ,
L_16 , V_35 ) ;
F_43 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
F_44 ( & V_17 -> V_19 ) ;
F_45 ( V_17 ) ;
}
F_6 ( & V_34 -> V_50 . V_51 [ V_35 ] . V_17 ) ;
}
}
static int F_46 ( int V_111 , void * V_112 , void * V_113 )
{
F_47 ( L_17 ) ;
F_48 ( V_112 ) ;
return 0 ;
}
void
F_49 ( struct V_33 * V_34 )
{
unsigned long V_38 ;
struct V_106 * V_107 , * V_67 ;
F_50 ( V_34 ) ;
F_16 ( & V_34 -> V_50 . V_114 , V_38 ) ;
F_41 ( V_34 ) ;
F_51 ( V_34 ) ;
if ( V_34 -> V_15 -> V_115 . V_116 )
V_34 -> V_15 -> V_115 . V_116 ( V_34 -> V_15 ) ;
F_42 ( V_34 ) ;
memcpy ( V_58 , V_59 , sizeof( V_58 ) ) ;
if ( V_34 -> V_15 -> V_115 . V_117 &&
! V_34 -> V_15 -> V_118 )
V_34 -> V_15 -> V_115 . V_117 ( V_34 -> V_15 ) ;
F_19 ( & V_34 -> V_50 . V_114 , V_38 ) ;
F_37 (&priv->tdls_txq, skb, tmp)
F_38 ( V_34 -> V_15 , V_107 , 0 , - 1 ) ;
F_52 ( & V_34 -> V_119 , F_46 , NULL ) ;
F_53 ( & V_34 -> V_119 ) ;
}
struct V_13 *
F_54 ( struct V_33 * V_34 , T_1 V_92 ,
const T_1 * V_120 )
{
struct V_13 * V_17 ;
F_40 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_120 , V_21 ) )
return V_17 ;
}
return NULL ;
}
struct V_13 *
F_55 ( struct V_33 * V_34 , T_1 V_92 ,
const T_1 * V_120 )
{
struct V_13 * V_17 ;
V_17 = F_54 ( V_34 , V_92 , V_120 ) ;
if ( V_17 )
return V_17 ;
F_11 ( V_34 , V_120 ) ;
return F_54 ( V_34 , V_92 , V_120 ) ;
}
void
F_56 ( struct V_33 * V_34 , const T_1 * V_120 )
{
struct V_13 * V_17 ;
unsigned long V_38 ;
int V_35 ;
F_16 ( & V_34 -> V_50 . V_114 , V_38 ) ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
V_17 = F_54 ( V_34 , V_35 , V_120 ) ;
if ( ! V_17 )
continue;
F_36 ( V_34 , V_17 ) ;
F_57 ( V_17 -> V_22 , & V_34 -> V_50 . V_105 ) ;
F_44 ( & V_17 -> V_19 ) ;
F_45 ( V_17 ) ;
}
F_19 ( & V_34 -> V_50 . V_114 , V_38 ) ;
}
int
F_58 ( struct V_33 * V_34 ,
struct V_13 * V_17 , int V_121 )
{
struct V_13 * V_122 ;
F_40 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_122 == V_17 )
return true ;
}
return false ;
}
void
F_59 ( struct V_33 * V_34 ,
struct V_106 * V_107 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
T_2 V_92 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_21 ] , V_123 ;
unsigned long V_38 ;
struct V_108 V_108 ;
int V_124 = V_125 ;
struct V_126 * V_127 = (struct V_126 * ) V_107 -> V_113 ;
struct V_128 * V_129 = F_60 ( V_107 ) ;
memcpy ( V_16 , V_127 -> V_130 , V_21 ) ;
if ( F_61 ( V_34 ) == V_131 &&
F_62 ( V_15 -> V_132 ) ) {
if ( F_63 ( V_127 -> V_133 ) == V_134 )
F_8 ( V_15 -> V_23 ,
L_18 , V_16 ) ;
else if ( memcmp ( V_34 -> V_135 , V_16 , V_21 ) )
V_124 = F_13 ( V_34 , V_16 ) ;
}
if ( ! V_34 -> V_136 && ! F_64 ( V_107 ) ) {
F_8 ( V_15 -> V_23 , L_19 ) ;
F_38 ( V_15 , V_107 , 0 , - 1 ) ;
return;
}
V_92 = V_107 -> V_137 ;
F_16 ( & V_34 -> V_50 . V_114 , V_38 ) ;
V_123 = F_30 ( V_34 , V_92 ) ;
if ( ! F_12 ( V_34 ) &&
! F_64 ( V_107 ) ) {
switch ( V_124 ) {
case V_45 :
V_17 = F_55 ( V_34 , V_123 ,
V_16 ) ;
V_129 -> V_38 |= V_138 ;
break;
case V_139 :
F_65 ( & V_34 -> V_140 , V_107 ) ;
F_19 ( & V_34 -> V_50 . V_114 ,
V_38 ) ;
return;
default:
V_108 = V_34 -> V_50 . V_51 [ V_123 ] . V_17 ;
if ( ! F_66 ( & V_108 ) )
V_17 = F_67 (
& V_108 , struct V_13 ,
V_19 ) ;
else
V_17 = NULL ;
break;
}
} else {
memcpy ( V_16 , V_107 -> V_113 , V_21 ) ;
if ( V_16 [ 0 ] & 0x01 || F_64 ( V_107 ) )
F_68 ( V_16 ) ;
V_17 = F_55 ( V_34 , V_123 , V_16 ) ;
}
if ( ! V_17 ) {
F_19 ( & V_34 -> V_50 . V_114 , V_38 ) ;
F_38 ( V_15 , V_107 , 0 , - 1 ) ;
return;
}
F_65 ( & V_17 -> V_20 , V_107 ) ;
V_17 -> V_48 ++ ;
V_17 -> V_22 ++ ;
if ( F_35 ( & V_34 -> V_50 . V_61 ) <
V_34 -> V_60 [ V_123 ] )
F_23 ( & V_34 -> V_50 . V_61 ,
V_34 -> V_60 [ V_123 ] ) ;
F_69 ( & V_34 -> V_50 . V_105 ) ;
F_19 ( & V_34 -> V_50 . V_114 , V_38 ) ;
}
int F_70 ( struct V_33 * V_34 ,
const struct V_141 * V_142 )
{
T_1 * V_143 = ( T_1 * ) & V_142 -> V_144 . V_145 ;
T_4 V_146 = F_3 ( V_142 -> V_147 ) , V_148 ;
bool V_149 = true ;
struct V_150 * V_151 ;
struct V_152 * V_153 ;
struct V_63 * V_154 = NULL ;
struct V_84 * V_85 ;
F_8 ( V_34 -> V_15 -> V_23 , L_20 ,
V_146 ) ;
while ( ( V_146 >= sizeof( V_151 -> V_155 ) ) && V_149 ) {
V_151 = (struct V_150 * ) V_143 ;
V_148 = F_3 ( V_151 -> V_155 . V_156 ) ;
if ( V_146 < V_148 + sizeof( V_151 -> V_155 ) )
break;
switch ( F_3 ( V_151 -> V_155 . type ) ) {
case V_157 :
V_153 =
(struct V_152 * )
V_151 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_21
L_22 ,
V_153 -> V_158 ,
V_153 -> V_87 ,
V_153 -> V_86 ) ;
V_85 = & V_34 -> V_50 . V_85 [ V_153 ->
V_158 ] ;
V_85 -> V_86 = V_153 -> V_86 ;
V_85 -> V_87 =
V_153 -> V_87 ;
V_85 -> V_159 = V_153 -> V_159 ;
break;
case V_160 :
V_154 =
(struct V_63 * ) ( V_143 +
2 ) ;
V_154 -> V_72 . V_156 = ( T_1 ) V_148 ;
V_154 -> V_72 . V_161 =
V_160 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_21
L_23 ,
V_154 -> V_74 &
V_75 ) ;
memcpy ( ( T_1 * ) & V_34 -> V_162 . V_163 .
V_64 , V_154 ,
V_154 -> V_72 . V_156 + 2 ) ;
break;
default:
V_149 = false ;
break;
}
V_143 += ( V_148 + sizeof( V_151 -> V_155 ) ) ;
V_146 -= ( V_148 + sizeof( V_151 -> V_155 ) ) ;
}
F_24 ( V_34 , V_154 ) ;
F_28 ( V_34 ) ;
return 0 ;
}
T_2
F_71 ( struct V_33 * V_34 ,
T_1 * * V_164 ,
struct V_63 * V_64 ,
struct V_165 * V_166 )
{
struct V_167 * V_168 ;
T_2 V_169 = 0 ;
if ( ! V_164 )
return 0 ;
if ( ! ( * V_164 ) )
return 0 ;
if ( ! V_64 )
return 0 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_24 ,
V_64 -> V_72 . V_161 ) ;
if ( ( V_34 -> V_170 ||
( V_166 && ( V_34 -> V_15 -> V_171 & V_172 ||
V_34 -> V_15 -> V_171 & V_173 ) ) ) &&
V_64 -> V_72 . V_161 == V_160 ) {
V_168 = (struct V_167 * ) * V_164 ;
V_168 -> V_155 . type = F_72 ( ( T_3 ) V_174 [ 0 ] ) ;
V_168 -> V_155 . V_156 = F_72 ( ( T_3 ) V_174 [ 1 ] ) ;
memcpy ( V_168 -> V_64 , & V_174 [ 2 ] ,
F_3 ( V_168 -> V_155 . V_156 ) ) ;
if ( V_64 -> V_74 & V_175 )
memcpy ( ( T_1 * ) ( V_168 -> V_64
+ F_3 ( V_168 -> V_155 . V_156 )
- sizeof( V_34 -> V_176 ) ) ,
& V_34 -> V_176 , sizeof( V_34 -> V_176 ) ) ;
V_169 = sizeof( V_168 -> V_155 )
+ F_3 ( V_168 -> V_155 . V_156 ) ;
* V_164 += V_169 ;
}
return V_169 ;
}
T_1
F_73 ( struct V_33 * V_34 ,
const struct V_106 * V_107 )
{
T_2 V_177 = F_74 ( F_75 ( V_107 -> V_178 ) ) ;
T_1 V_179 ;
V_179 = ( T_1 ) ( F_76 ( V_177 , V_34 -> V_50 . V_180 ) >> 1 ) ;
F_8 ( V_34 -> V_15 -> V_23 , L_25
L_26 , V_177 , V_179 ) ;
return V_179 ;
}
static struct V_13 *
F_77 ( struct V_14 * V_15 ,
struct V_33 * * V_34 , int * V_92 )
{
struct V_33 * V_181 ;
struct V_13 * V_182 ;
struct V_183 * V_184 ;
T_5 * V_185 ;
unsigned long V_186 ;
int V_35 , V_68 ;
for ( V_68 = V_15 -> V_96 - 1 ; V_68 >= 0 ; -- V_68 ) {
F_40 (adapter->bss_prio_tbl[j].bss_prio_cur,
&adapter->bss_prio_tbl[j].bss_prio_head,
list) {
V_181 = V_15 -> V_187 [ V_68 ] . V_188 -> V_34 ;
if ( F_35 ( & V_181 -> V_50 . V_105 ) == 0 )
continue;
V_185 = & V_181 -> V_50 . V_61 ;
for ( V_35 = F_35 ( V_185 ) ; V_35 >= V_189 ; -- V_35 ) {
F_16 ( & V_181 -> V_50 .
V_114 , V_186 ) ;
V_184 = & ( V_181 ) -> V_50 .
V_51 [ V_58 [ V_35 ] ] ;
F_40 (ptr, &tid_ptr->ra_list,
list) {
if ( ! F_78 ( & V_182 -> V_20 ) )
goto V_190;
}
F_19 ( & V_181 -> V_50 .
V_114 ,
V_186 ) ;
}
}
}
return NULL ;
V_190:
if ( F_35 ( V_185 ) > V_35 )
F_23 ( V_185 , V_35 ) ;
F_19 ( & V_181 -> V_50 . V_114 , V_186 ) ;
* V_34 = V_181 ;
* V_92 = V_58 [ V_35 ] ;
return V_182 ;
}
void F_79 ( struct V_33 * V_34 ,
struct V_13 * V_16 ,
int V_92 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_191 * V_192 = V_15 -> V_187 ;
struct V_183 * V_184 = & V_34 -> V_50 . V_51 [ V_92 ] ;
unsigned long V_38 ;
F_16 ( & V_192 [ V_34 -> V_193 ] . V_194 , V_38 ) ;
F_80 ( & V_192 [ V_34 -> V_193 ] . V_195 ,
& V_192 [ V_34 -> V_193 ] . V_188 -> V_19 ) ;
F_19 ( & V_192 [ V_34 -> V_193 ] . V_194 , V_38 ) ;
F_16 ( & V_34 -> V_50 . V_114 , V_38 ) ;
if ( F_58 ( V_34 , V_16 , V_92 ) ) {
V_34 -> V_50 . V_196 [ V_92 ] ++ ;
F_80 ( & V_184 -> V_17 , & V_16 -> V_19 ) ;
}
F_19 ( & V_34 -> V_50 . V_114 , V_38 ) ;
}
static int
F_81 ( struct V_33 * V_34 ,
struct V_13 * V_182 ,
int V_197 )
{
int V_198 = 0 , V_199 = 0 ;
struct V_106 * V_107 , * V_67 ;
int V_200 ;
if ( V_34 -> V_201 == V_202 && V_34 -> V_203 &&
V_182 -> V_40 )
V_200 = F_82 ( int , V_182 -> V_47 , V_197 ) ;
else
V_200 = V_197 ;
F_37 (&ptr->skb_head, skb, tmp) {
V_199 += V_107 -> V_156 ;
if ( V_199 >= V_200 )
break;
if ( ++ V_198 >= V_204 )
return true ;
}
return false ;
}
static void
F_83 ( struct V_33 * V_34 ,
struct V_13 * V_182 , int V_121 ,
unsigned long V_205 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_84 ( struct V_33 * V_34 ,
struct V_13 * V_182 )
{
struct V_106 * V_107 ;
struct V_128 * V_129 ;
if ( F_78 ( & V_182 -> V_20 ) )
return false ;
V_107 = F_85 ( & V_182 -> V_20 ) ;
V_129 = F_60 ( V_107 ) ;
if ( V_129 -> V_38 & V_206 )
return true ;
return false ;
}
static void
F_86 ( struct V_33 * V_34 ,
struct V_13 * V_182 , int V_121 ,
unsigned long V_205 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_87 ( struct V_14 * V_15 )
{
struct V_13 * V_182 ;
struct V_33 * V_34 = NULL ;
int V_121 = 0 ;
T_1 V_16 [ V_21 ] ;
int V_207 = 0 , V_92 = 0 ;
unsigned long V_38 ;
V_182 = F_77 ( V_15 , & V_34 , & V_121 ) ;
if ( ! V_182 )
return - 1 ;
V_92 = F_88 ( V_182 ) ;
F_8 ( V_15 -> V_23 , L_27 , V_92 ) ;
F_16 ( & V_34 -> V_50 . V_114 , V_38 ) ;
if ( ! F_58 ( V_34 , V_182 , V_121 ) ) {
F_19 ( & V_34 -> V_50 . V_114 , V_38 ) ;
return - 1 ;
}
if ( F_84 ( V_34 , V_182 ) ) {
F_86 ( V_34 , V_182 , V_121 , V_38 ) ;
return 0 ;
}
if ( ! V_182 -> V_40 ||
V_182 -> V_42 ||
V_34 -> V_208 . V_209 ) {
if ( V_182 -> V_40 &&
V_182 -> V_42 &&
V_182 -> V_44 &&
F_89 ( V_34 , V_92 ) &&
F_81 ( V_34 , V_182 ,
V_15 -> V_98 ) )
F_90 ( V_34 , V_182 , V_121 , V_38 ) ;
else
F_83 ( V_34 , V_182 , V_121 , V_38 ) ;
} else {
if ( F_91 ( V_34 , V_182 , V_92 ) &&
V_182 -> V_48 > V_182 -> V_49 ) {
if ( F_92 ( V_15 ) ) {
F_93 ( V_34 , V_182 -> V_16 , V_92 ,
V_210 ) ;
F_94 ( V_34 , V_92 , V_182 -> V_16 ) ;
} else if ( F_95
( V_34 , V_92 , & V_207 , V_16 ) ) {
F_93 ( V_34 , V_182 -> V_16 , V_92 ,
V_210 ) ;
F_96 ( V_34 , V_207 , V_16 , 1 ) ;
}
}
if ( F_89 ( V_34 , V_92 ) &&
F_81 ( V_34 , V_182 ,
V_15 -> V_98 ) )
F_90 ( V_34 , V_182 , V_121 , V_38 ) ;
else
F_83 ( V_34 , V_182 , V_121 , V_38 ) ;
}
return 0 ;
}
void
F_97 ( struct V_14 * V_15 )
{
do {
if ( F_87 ( V_15 ) )
break;
if ( V_15 -> V_211 != V_212 ) {
if ( V_15 -> V_213 ||
V_15 -> V_214 )
break;
} else {
if ( F_35 ( & V_15 -> V_215 ) >=
V_216 )
break;
}
} while ( ! F_34 ( V_15 ) );
}
