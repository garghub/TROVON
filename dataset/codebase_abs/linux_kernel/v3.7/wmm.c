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
F_4 ( struct V_14 * V_15 , T_1 * V_16 )
{
struct V_13 * V_17 ;
V_17 = F_5 ( sizeof( struct V_13 ) , V_18 ) ;
if ( ! V_17 ) {
F_6 ( V_15 -> V_19 , L_7 ,
V_20 ) ;
return NULL ;
}
F_7 ( & V_17 -> V_21 ) ;
F_8 ( & V_17 -> V_22 ) ;
memcpy ( V_17 -> V_16 , V_16 , V_23 ) ;
V_17 -> V_24 = 0 ;
F_9 ( V_15 -> V_19 , L_8 , V_17 ) ;
return V_17 ;
}
static T_1 F_10 ( void )
{
T_2 V_25 , V_26 ;
struct V_27 V_28 ;
T_1 V_29 ;
F_11 ( & V_28 ) ;
V_25 = ( V_28 . V_30 & 0xFFFF ) + ( V_28 . V_30 >> 16 ) ;
V_26 = ( V_28 . V_31 & 0xFFFF ) + ( V_28 . V_31 >> 16 ) ;
V_29 = ( ( ( V_25 << 16 ) + V_26 ) % V_32 )
+ V_33 ;
return V_29 ;
}
void
F_12 ( struct V_34 * V_35 , T_1 * V_16 )
{
int V_36 ;
struct V_13 * V_17 ;
struct V_14 * V_15 = V_35 -> V_15 ;
struct V_37 * V_38 ;
unsigned long V_39 ;
F_13 ( & V_35 -> V_40 , V_39 ) ;
V_38 = F_14 ( V_35 , V_16 ) ;
F_15 ( & V_35 -> V_40 , V_39 ) ;
for ( V_36 = 0 ; V_36 < V_41 ; ++ V_36 ) {
V_17 = F_4 ( V_15 , V_16 ) ;
F_9 ( V_15 -> V_19 , L_9 , V_17 ) ;
if ( ! V_17 )
break;
V_17 -> V_42 = 0 ;
if ( ! F_16 ( V_35 ) ) {
V_17 -> V_42 = F_17 ( V_35 ) ;
} else {
V_17 -> V_42 =
F_18 ( V_35 , V_38 ) ;
if ( V_17 -> V_42 )
V_17 -> V_43 = V_38 -> V_43 ;
}
F_9 ( V_15 -> V_19 , L_10 ,
V_17 , V_17 -> V_42 ) ;
if ( V_17 -> V_42 ) {
V_17 -> V_44 = 0 ;
V_17 -> V_45 =
F_10 () ;
}
F_19 ( & V_17 -> V_21 ,
& V_35 -> V_46 . V_47 [ V_36 ] . V_17 ) ;
if ( ! V_35 -> V_46 . V_47 [ V_36 ] . V_48 )
V_35 -> V_46 . V_47 [ V_36 ] . V_48 = V_17 ;
}
}
static void F_20 ( struct V_34 * V_35 )
{
V_35 -> V_46 . V_49 [ 0 ] = V_50 ;
V_35 -> V_46 . V_49 [ 1 ] = V_51 ;
V_35 -> V_46 . V_49 [ 2 ] = V_52 ;
V_35 -> V_46 . V_49 [ 3 ] = V_53 ;
}
static void
F_21 ( struct V_54 * V_46 )
{
T_1 * V_49 = V_46 -> V_49 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < 4 ; ++ V_36 ) {
V_55 [ 7 - ( V_36 * 2 ) ] = V_56 [ V_49 [ V_36 ] ] [ 1 ] ;
V_55 [ 6 - ( V_36 * 2 ) ] = V_56 [ V_49 [ V_36 ] ] [ 0 ] ;
}
for ( V_36 = 0 ; V_36 < V_41 ; ++ V_36 )
V_57 [ V_55 [ V_36 ] ] = ( T_1 ) V_36 ;
F_22 ( & V_46 -> V_58 , V_59 ) ;
}
void
F_23 ( struct V_34 * V_35 ,
struct V_60 * V_61 )
{
T_3 V_62 , V_63 , V_64 [ 4 ] ;
T_2 V_36 , V_65 , V_66 ;
T_1 V_67 ;
if ( ! V_61 || ! V_35 -> V_68 ) {
F_20 ( V_35 ) ;
return;
}
F_9 ( V_35 -> V_15 -> V_19 , L_11
L_12 ,
V_61 -> V_69 . V_70 , V_61 -> V_71 &
V_72 ,
V_61 -> V_73 ) ;
for ( V_66 = 0 ; V_66 < F_24 ( V_61 -> V_74 ) ; V_66 ++ ) {
T_1 V_75 = V_61 -> V_74 [ V_66 ] . V_9 ;
T_1 V_76 = V_61 -> V_74 [ V_66 ] . V_5 ;
V_62 = ( 1 << ( V_75 & V_10 ) ) - 1 ;
V_63 = ( V_62 >> 1 ) + ( V_76 & V_8 ) ;
V_67 = V_4 [ ( V_76 & V_6 ) >> 5 ] ;
V_35 -> V_46 . V_49 [ V_67 ] = V_67 ;
V_64 [ V_67 ] = V_63 ;
F_9 ( V_35 -> V_15 -> V_19 ,
L_13 ,
( 1 << ( ( V_75 & V_11 ) >> 4 ) ) - 1 ,
V_62 , V_63 ) ;
F_1 ( & V_61 -> V_74 [ V_66 ] ) ;
}
for ( V_36 = 0 ; V_36 < V_66 ; V_36 ++ ) {
for ( V_65 = 1 ; V_65 < V_66 - V_36 ; V_65 ++ ) {
if ( V_64 [ V_65 - 1 ] > V_64 [ V_65 ] ) {
F_25 ( V_64 [ V_65 - 1 ] , V_64 [ V_65 ] ) ;
F_25 ( V_35 -> V_46 . V_49 [ V_65 - 1 ] ,
V_35 -> V_46 . V_49 [ V_65 ] ) ;
} else if ( V_64 [ V_65 - 1 ] == V_64 [ V_65 ] ) {
if ( V_35 -> V_46 . V_49 [ V_65 - 1 ]
< V_35 -> V_46 . V_49 [ V_65 ] )
F_25 ( V_35 -> V_46 . V_49 [ V_65 - 1 ] ,
V_35 -> V_46 . V_49 [ V_65 ] ) ;
}
}
}
F_21 ( & V_35 -> V_46 ) ;
}
static enum V_77
F_26 ( struct V_34 * V_35 ,
enum V_77 V_78 )
{
int V_79 ;
enum V_77 V_80 ;
struct V_81 * V_82 ;
V_82 = & V_35 -> V_46 . V_82 [ V_78 ] ;
if ( ! V_82 -> V_83 )
return V_78 ;
V_80 = V_53 ;
for ( V_79 = V_53 ; V_79 < V_78 ; V_79 ++ ) {
V_82 = & V_35 -> V_46 . V_82 [ V_79 ] ;
if ( ! V_82 -> V_83 && ! V_82 -> V_84 )
V_80 = (enum V_77 ) V_79 ;
}
return V_80 ;
}
void
F_27 ( struct V_34 * V_35 )
{
int V_85 ;
F_9 ( V_35 -> V_15 -> V_19 , L_14
L_15 ) ;
if ( ! V_35 -> V_68 ) {
for ( V_85 = V_53 ; V_85 <= V_50 ; V_85 ++ )
V_35 -> V_46 . V_86 [ V_85 ] =
(enum V_77 ) V_85 ;
} else {
for ( V_85 = V_53 ; V_85 <= V_50 ; V_85 ++ ) {
V_35 -> V_46 . V_86 [ V_85 ]
= F_26 ( V_35 ,
(enum V_77 ) V_85 ) ;
F_9 ( V_35 -> V_15 -> V_19 ,
L_16 ,
V_85 , V_35 -> V_46 . V_86 [ V_85 ] ) ;
}
}
}
static enum V_77
F_28 ( struct V_14 * V_15 , T_2 V_87 )
{
const enum V_77 V_88 [] = { V_52 ,
V_53 ,
V_53 ,
V_52 ,
V_51 ,
V_51 ,
V_50 ,
V_50
} ;
if ( V_87 >= F_24 ( V_88 ) )
return V_52 ;
return V_88 [ V_87 ] ;
}
static T_1
F_29 ( struct V_34 * V_35 , T_2 V_89 )
{
enum V_77 V_90 , V_91 ;
T_1 V_92 ;
V_90 = F_28 ( V_35 -> V_15 , V_89 ) ;
V_91 = V_35 -> V_46 . V_86 [ V_90 ] ;
V_92 = V_56 [ V_91 ] [ V_89 % 2 ] ;
return V_92 ;
}
void
F_30 ( struct V_14 * V_15 )
{
int V_36 , V_65 ;
struct V_34 * V_35 ;
for ( V_65 = 0 ; V_65 < V_15 -> V_93 ; ++ V_65 ) {
V_35 = V_15 -> V_35 [ V_65 ] ;
if ( ! V_35 )
continue;
for ( V_36 = 0 ; V_36 < V_41 ; ++ V_36 ) {
V_35 -> V_94 [ V_36 ] . V_95 = V_57 [ V_36 ] ;
V_35 -> V_94 [ V_36 ] . V_96 = V_57 [ V_36 ] ;
V_35 -> V_94 [ V_36 ] . V_97 = V_57 [ V_36 ] ;
V_35 -> V_46 . V_47 [ V_36 ] . V_48 = NULL ;
}
V_35 -> V_94 [ 6 ] . V_95
= V_35 -> V_94 [ 6 ] . V_96
= V_35 -> V_94 [ 6 ] . V_97
= V_98 ;
V_35 -> V_94 [ 7 ] . V_95 = V_35 -> V_94 [ 7 ] . V_96
= V_35 -> V_94 [ 7 ] . V_97
= V_98 ;
V_35 -> V_99 . V_100 = V_101 ;
V_35 -> V_99 . V_102 = V_103 ;
V_35 -> V_99 . V_104 = V_105 ;
F_31 ( V_35 ) ;
F_22 ( & V_35 -> V_46 . V_106 , 0 ) ;
F_22 ( & V_35 -> V_46 . V_58 , V_59 ) ;
}
}
int
F_32 ( struct V_14 * V_15 )
{
int V_36 ;
struct V_34 * V_35 ;
for ( V_36 = 0 ; V_36 < V_15 -> V_93 ; ++ V_36 ) {
V_35 = V_15 -> V_35 [ V_36 ] ;
if ( V_35 && F_33 ( & V_35 -> V_46 . V_106 ) )
return false ;
}
return true ;
}
static void
F_34 ( struct V_34 * V_35 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_35 -> V_15 ;
struct V_107 * V_108 , * V_64 ;
F_35 (&ra_list->skb_head, skb, tmp)
F_36 ( V_15 , V_108 , - 1 ) ;
}
static void
F_37 ( struct V_34 * V_35 ,
struct V_109 * V_110 )
{
struct V_13 * V_17 ;
F_38 (ra_list, ra_list_head, list)
F_34 ( V_35 , V_17 ) ;
}
static void F_39 ( struct V_34 * V_35 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_41 ; V_36 ++ )
F_37 ( V_35 , & V_35 -> V_46 . V_47 [ V_36 ] .
V_17 ) ;
F_22 ( & V_35 -> V_46 . V_106 , 0 ) ;
F_22 ( & V_35 -> V_46 . V_58 , V_59 ) ;
}
static void F_40 ( struct V_34 * V_35 )
{
struct V_13 * V_17 , * V_111 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_41 ; ++ V_36 ) {
F_9 ( V_35 -> V_15 -> V_19 ,
L_17 , V_36 ) ;
F_41 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
F_42 ( & V_17 -> V_21 ) ;
F_43 ( V_17 ) ;
}
F_7 ( & V_35 -> V_46 . V_47 [ V_36 ] . V_17 ) ;
V_35 -> V_46 . V_47 [ V_36 ] . V_48 = NULL ;
}
}
void
F_44 ( struct V_34 * V_35 )
{
unsigned long V_39 ;
F_45 ( V_35 ) ;
F_13 ( & V_35 -> V_46 . V_112 , V_39 ) ;
F_39 ( V_35 ) ;
F_46 ( V_35 ) ;
if ( V_35 -> V_15 -> V_113 . V_114 )
V_35 -> V_15 -> V_113 . V_114 ( V_35 -> V_15 ) ;
F_40 ( V_35 ) ;
memcpy ( V_55 , V_56 , sizeof( V_55 ) ) ;
F_15 ( & V_35 -> V_46 . V_112 , V_39 ) ;
}
static struct V_13 *
F_47 ( struct V_34 * V_35 , T_1 V_89 ,
T_1 * V_115 )
{
struct V_13 * V_17 ;
F_38 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_115 , V_23 ) )
return V_17 ;
}
return NULL ;
}
static struct V_13 *
F_48 ( struct V_34 * V_35 , T_1 V_89 , T_1 * V_115 )
{
struct V_13 * V_17 ;
V_17 = F_47 ( V_35 , V_89 , V_115 ) ;
if ( V_17 )
return V_17 ;
F_12 ( V_35 , V_115 ) ;
return F_47 ( V_35 , V_89 , V_115 ) ;
}
int
F_49 ( struct V_34 * V_35 ,
struct V_13 * V_17 , int V_116 )
{
struct V_13 * V_117 ;
F_38 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_117 == V_17 )
return true ;
}
return false ;
}
void
F_50 ( struct V_34 * V_35 ,
struct V_107 * V_108 )
{
struct V_14 * V_15 = V_35 -> V_15 ;
T_2 V_89 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_23 ] , V_118 ;
unsigned long V_39 ;
if ( ! V_35 -> V_119 && ! F_51 ( V_108 ) ) {
F_9 ( V_15 -> V_19 , L_18 ) ;
F_36 ( V_15 , V_108 , - 1 ) ;
return;
}
V_89 = V_108 -> V_120 ;
F_13 ( & V_35 -> V_46 . V_112 , V_39 ) ;
V_118 = F_29 ( V_35 , V_89 ) ;
if ( ! F_16 ( V_35 ) &&
! F_51 ( V_108 ) ) {
if ( ! F_52 ( & V_35 -> V_46 . V_47 [ V_118 ] . V_17 ) )
V_17 = F_53 (
& V_35 -> V_46 . V_47 [ V_118 ] . V_17 ,
struct V_13 , V_21 ) ;
else
V_17 = NULL ;
} else {
memcpy ( V_16 , V_108 -> V_121 , V_23 ) ;
if ( V_16 [ 0 ] & 0x01 || F_51 ( V_108 ) )
memset ( V_16 , 0xff , V_23 ) ;
V_17 = F_48 ( V_35 , V_118 , V_16 ) ;
}
if ( ! V_17 ) {
F_15 ( & V_35 -> V_46 . V_112 , V_39 ) ;
F_36 ( V_15 , V_108 , - 1 ) ;
return;
}
F_54 ( & V_17 -> V_22 , V_108 ) ;
V_17 -> V_24 += V_108 -> V_122 ;
V_17 -> V_44 ++ ;
F_55 ( & V_35 -> V_46 . V_106 ) ;
if ( F_33 ( & V_35 -> V_46 . V_58 ) <
V_57 [ V_118 ] )
F_22 ( & V_35 -> V_46 . V_58 ,
V_57 [ V_118 ] ) ;
F_15 ( & V_35 -> V_46 . V_112 , V_39 ) ;
}
int F_56 ( struct V_34 * V_35 ,
const struct V_123 * V_124 )
{
T_1 * V_125 = ( T_1 * ) & V_124 -> V_126 . V_127 ;
T_4 V_128 = F_3 ( V_124 -> V_129 ) , V_130 ;
int V_131 = true ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
struct V_60 * V_136 = NULL ;
struct V_81 * V_82 ;
F_9 ( V_35 -> V_15 -> V_19 , L_19 ,
V_128 ) ;
while ( ( V_128 >= sizeof( V_133 -> V_137 ) ) && V_131 ) {
V_133 = (struct V_132 * ) V_125 ;
V_130 = F_3 ( V_133 -> V_137 . V_122 ) ;
switch ( F_3 ( V_133 -> V_137 . type ) ) {
case V_138 :
V_135 =
(struct V_134 * )
V_133 ;
F_9 ( V_35 -> V_15 -> V_19 ,
L_20
L_21 ,
V_135 -> V_139 ,
V_135 -> V_84 ,
V_135 -> V_83 ) ;
V_82 = & V_35 -> V_46 . V_82 [ V_135 ->
V_139 ] ;
V_82 -> V_83 = V_135 -> V_83 ;
V_82 -> V_84 =
V_135 -> V_84 ;
V_82 -> V_140 = V_135 -> V_140 ;
break;
case V_141 :
V_136 =
(struct V_60 * ) ( V_125 +
2 ) ;
V_136 -> V_69 . V_122 = ( T_1 ) V_130 ;
V_136 -> V_69 . V_142 =
V_141 ;
F_9 ( V_35 -> V_15 -> V_19 ,
L_20
L_22 ,
V_136 -> V_71 &
V_72 ) ;
memcpy ( ( T_1 * ) & V_35 -> V_143 . V_144 .
V_61 , V_136 ,
V_136 -> V_69 . V_122 + 2 ) ;
break;
default:
V_131 = false ;
break;
}
V_125 += ( V_130 + sizeof( V_133 -> V_137 ) ) ;
V_128 -= ( V_130 + sizeof( V_133 -> V_137 ) ) ;
}
F_23 ( V_35 , V_136 ) ;
F_27 ( V_35 ) ;
return 0 ;
}
T_2
F_57 ( struct V_34 * V_35 ,
T_1 * * V_145 ,
struct V_60 * V_61 ,
struct V_146 * V_147 )
{
struct V_148 * V_149 ;
T_2 V_150 = 0 ;
if ( ! V_145 )
return 0 ;
if ( ! ( * V_145 ) )
return 0 ;
if ( ! V_61 )
return 0 ;
F_9 ( V_35 -> V_15 -> V_19 ,
L_23 ,
V_61 -> V_69 . V_142 ) ;
if ( ( V_35 -> V_151 ||
( V_147 && ( V_35 -> V_15 -> V_152 & V_153 ||
V_35 -> V_15 -> V_152 & V_154 ) ) ) &&
V_61 -> V_69 . V_142 == V_141 ) {
V_149 = (struct V_148 * ) * V_145 ;
V_149 -> V_137 . type = F_58 ( ( T_3 ) V_155 [ 0 ] ) ;
V_149 -> V_137 . V_122 = F_58 ( ( T_3 ) V_155 [ 1 ] ) ;
memcpy ( V_149 -> V_61 , & V_155 [ 2 ] ,
F_3 ( V_149 -> V_137 . V_122 ) ) ;
if ( V_61 -> V_71 & V_156 )
memcpy ( ( T_1 * ) ( V_149 -> V_61
+ F_3 ( V_149 -> V_137 . V_122 )
- sizeof( V_35 -> V_157 ) ) ,
& V_35 -> V_157 , sizeof( V_35 -> V_157 ) ) ;
V_150 = sizeof( V_149 -> V_137 )
+ F_3 ( V_149 -> V_137 . V_122 ) ;
* V_145 += V_150 ;
}
return V_150 ;
}
T_1
F_59 ( struct V_34 * V_35 ,
const struct V_107 * V_108 )
{
T_1 V_158 ;
struct V_27 V_159 , V_160 ;
T_2 V_161 ;
F_11 ( & V_159 ) ;
V_160 = F_60 ( V_108 -> V_162 ) ;
V_161 = ( V_159 . V_30 - V_160 . V_30 ) * 1000 ;
V_161 += ( V_159 . V_31 - V_160 . V_31 ) / 1000 ;
V_158 = ( T_1 ) ( F_61 ( V_161 , V_35 -> V_46 . V_163 ) >> 1 ) ;
F_9 ( V_35 -> V_15 -> V_19 , L_24
L_25 , V_161 , V_158 ) ;
return V_158 ;
}
static struct V_13 *
F_62 ( struct V_14 * V_15 ,
struct V_34 * * V_35 , int * V_89 )
{
struct V_34 * V_164 ;
struct V_13 * V_165 , * V_166 ;
struct V_167 * V_168 , * V_169 ;
struct V_170 * V_171 ;
T_5 * V_172 ;
int V_173 ;
unsigned long V_39 ;
int V_36 , V_65 ;
for ( V_65 = V_15 -> V_93 - 1 ; V_65 >= 0 ; -- V_65 ) {
F_13 ( & V_15 -> V_174 [ V_65 ] . V_175 ,
V_39 ) ;
V_173 = F_52 ( & V_15 -> V_174 [ V_65 ]
. V_176 ) ;
F_15 ( & V_15 -> V_174 [ V_65 ] . V_175 ,
V_39 ) ;
if ( V_173 )
continue;
if ( V_15 -> V_174 [ V_65 ] . V_177 ==
(struct V_167 * )
& V_15 -> V_174 [ V_65 ] . V_176 ) {
V_15 -> V_174 [ V_65 ] . V_177 =
F_53 ( & V_15 -> V_174 [ V_65 ]
. V_176 ,
struct V_167 ,
V_21 ) ;
}
V_168 = V_15 -> V_174 [ V_65 ] . V_177 ;
V_169 = V_168 ;
do {
V_164 = V_168 -> V_35 ;
V_172 = & V_164 -> V_46 . V_58 ;
for ( V_36 = F_33 ( V_172 ) ; V_36 >= V_178 ; -- V_36 ) {
V_171 = & ( V_164 ) -> V_46 .
V_47 [ V_55 [ V_36 ] ] ;
if ( ! V_171 -> V_48 )
continue;
F_13 ( & V_171 -> V_179 ,
V_39 ) ;
V_173 =
F_52 ( & V_15 -> V_174 [ V_65 ]
. V_176 ) ;
F_15 ( & V_171 -> V_179 ,
V_39 ) ;
if ( V_173 )
continue;
V_165 = F_53 (
& V_171 -> V_48 -> V_21 ,
struct V_13 ,
V_21 ) ;
V_166 = V_165 ;
if ( V_165 == (struct V_13 * )
& V_171 -> V_17 ) {
V_165 = F_53 ( & V_165 -> V_21 ,
struct V_13 , V_21 ) ;
V_166 = V_165 ;
}
do {
V_173 =
F_63 ( & V_165 -> V_22 ) ;
if ( ! V_173 )
goto V_180;
V_165 = F_53 ( & V_165 -> V_21 ,
struct V_13 ,
V_21 ) ;
if ( V_165 ==
(struct V_13 * )
& V_171 -> V_17 )
V_165 = F_53 (
& V_165 -> V_21 ,
struct V_13 ,
V_21 ) ;
} while ( V_165 != V_166 );
}
F_22 ( V_172 , V_181 ) ;
V_168 = F_53 ( & V_168 -> V_21 ,
struct V_167 ,
V_21 ) ;
if ( V_168 ==
(struct V_167 * )
& V_15 -> V_174 [ V_65 ] . V_176 )
V_168 = F_53 (
& V_168 -> V_21 ,
struct V_167 ,
V_21 ) ;
} while ( V_168 != V_169 );
}
return NULL ;
V_180:
F_13 ( & V_164 -> V_46 . V_112 , V_39 ) ;
if ( F_33 ( V_172 ) > V_36 )
F_22 ( V_172 , V_36 ) ;
F_15 ( & V_164 -> V_46 . V_112 , V_39 ) ;
* V_35 = V_164 ;
* V_89 = V_55 [ V_36 ] ;
return V_165 ;
}
static int
F_64 ( struct V_34 * V_35 ,
struct V_13 * V_165 ,
int V_182 )
{
int V_183 = 0 , V_184 = 0 ;
struct V_107 * V_108 , * V_64 ;
int V_185 ;
if ( V_35 -> V_186 == V_187 && V_35 -> V_188 &&
V_165 -> V_42 )
V_185 = F_65 ( int , V_165 -> V_43 , V_182 ) ;
else
V_185 = V_182 ;
F_35 (&ptr->skb_head, skb, tmp) {
V_184 += V_108 -> V_122 ;
if ( V_184 >= V_185 )
break;
if ( ++ V_183 >= V_189 )
return true ;
}
return false ;
}
static void
F_66 ( struct V_34 * V_35 ,
struct V_13 * V_165 , int V_116 ,
unsigned long V_190 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_67 ( struct V_34 * V_35 ,
struct V_13 * V_165 )
{
struct V_107 * V_108 ;
struct V_191 * V_192 ;
if ( F_63 ( & V_165 -> V_22 ) )
return false ;
V_108 = F_68 ( & V_165 -> V_22 ) ;
V_192 = F_69 ( V_108 ) ;
if ( V_192 -> V_39 & V_193 )
return true ;
return false ;
}
static void
F_70 ( struct V_34 * V_35 ,
struct V_13 * V_165 , int V_116 ,
unsigned long V_190 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_71 ( struct V_14 * V_15 )
{
struct V_13 * V_165 ;
struct V_34 * V_35 = NULL ;
int V_116 = 0 ;
T_1 V_16 [ V_23 ] ;
int V_194 = 0 , V_89 = 0 ;
unsigned long V_39 ;
V_165 = F_62 ( V_15 , & V_35 , & V_116 ) ;
if ( ! V_165 )
return - 1 ;
V_89 = F_72 ( V_165 ) ;
F_9 ( V_15 -> V_19 , L_26 , V_89 ) ;
F_13 ( & V_35 -> V_46 . V_112 , V_39 ) ;
if ( ! F_49 ( V_35 , V_165 , V_116 ) ) {
F_15 ( & V_35 -> V_46 . V_112 , V_39 ) ;
return - 1 ;
}
if ( F_67 ( V_35 , V_165 ) ) {
F_70 ( V_35 , V_165 , V_116 , V_39 ) ;
return 0 ;
}
if ( ! V_165 -> V_42 ||
F_73 ( V_35 , V_165 , V_89 ) ||
V_35 -> V_195 . V_196 ||
( ( V_35 -> V_197 . V_198 ||
V_35 -> V_197 . V_199 ) &&
! V_35 -> V_200 ) ) {
F_66 ( V_35 , V_165 , V_116 , V_39 ) ;
} else {
if ( F_74 ( V_35 , V_89 ) &&
V_165 -> V_44 > V_165 -> V_45 ) {
if ( F_75 ( V_15 ) ) {
F_76 ( V_35 , V_165 -> V_16 , V_89 ,
V_201 ) ;
F_77 ( V_35 , V_89 , V_165 -> V_16 ) ;
} else if ( F_78
( V_35 , V_89 , & V_194 , V_16 ) ) {
F_76 ( V_35 , V_165 -> V_16 , V_89 ,
V_201 ) ;
F_79 ( V_35 , V_194 , V_16 , 1 ) ;
}
}
if ( F_80 ( V_35 , V_89 ) &&
F_64 ( V_35 , V_165 ,
V_15 -> V_202 ) )
F_81 ( V_35 , V_165 , V_203 ,
V_116 , V_39 ) ;
else
F_66 ( V_35 , V_165 , V_116 , V_39 ) ;
}
return 0 ;
}
void
F_82 ( struct V_14 * V_15 )
{
do {
if ( V_15 -> V_204 || V_15 -> V_205 )
break;
if ( F_71 ( V_15 ) )
break;
} while ( ! F_32 ( V_15 ) );
}
