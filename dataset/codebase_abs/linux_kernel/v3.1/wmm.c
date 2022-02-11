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
V_17 -> V_25 = 0 ;
F_9 ( V_15 -> V_19 , L_8 , V_17 ) ;
return V_17 ;
}
void
F_10 ( struct V_26 * V_27 , T_1 * V_16 )
{
int V_28 ;
struct V_13 * V_17 ;
struct V_14 * V_15 = V_27 -> V_15 ;
for ( V_28 = 0 ; V_28 < V_29 ; ++ V_28 ) {
V_17 = F_4 ( V_15 , V_16 ) ;
F_9 ( V_15 -> V_19 , L_9 , V_17 ) ;
if ( ! V_17 )
break;
if ( ! F_11 ( V_27 ) )
V_17 -> V_30 = F_12 ( V_27 ) ;
else
V_17 -> V_30 = false ;
F_9 ( V_15 -> V_19 , L_10 ,
V_17 , V_17 -> V_30 ) ;
F_13 ( & V_17 -> V_21 ,
& V_27 -> V_31 . V_32 [ V_28 ] . V_17 ) ;
if ( ! V_27 -> V_31 . V_32 [ V_28 ] . V_33 )
V_27 -> V_31 . V_32 [ V_28 ] . V_33 = V_17 ;
}
}
static void F_14 ( struct V_26 * V_27 )
{
V_27 -> V_31 . V_34 [ 0 ] = V_35 ;
V_27 -> V_31 . V_34 [ 1 ] = V_36 ;
V_27 -> V_31 . V_34 [ 2 ] = V_37 ;
V_27 -> V_31 . V_34 [ 3 ] = V_38 ;
}
static void
F_15 ( struct V_39 * V_31 )
{
T_1 * V_34 = V_31 -> V_34 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < 4 ; ++ V_28 ) {
V_40 [ 7 - ( V_28 * 2 ) ] = V_41 [ V_34 [ V_28 ] ] [ 1 ] ;
V_40 [ 6 - ( V_28 * 2 ) ] = V_41 [ V_34 [ V_28 ] ] [ 0 ] ;
}
for ( V_28 = 0 ; V_28 < V_29 ; ++ V_28 )
V_42 [ V_40 [ V_28 ] ] = ( T_1 ) V_28 ;
F_16 ( & V_31 -> V_43 , V_44 ) ;
}
void
F_17 ( struct V_26 * V_27 ,
struct V_45 * V_46 )
{
T_2 V_47 , V_48 , V_49 [ 4 ] ;
T_3 V_28 , V_50 , V_51 ;
T_1 V_52 ;
if ( ! V_46 || ! V_27 -> V_53 ) {
F_14 ( V_27 ) ;
return;
}
F_9 ( V_27 -> V_15 -> V_19 , L_11
L_12 ,
V_46 -> V_54 . V_55 , V_46 -> V_56 &
V_57 ,
V_46 -> V_58 ) ;
for ( V_51 = 0 ; V_51 < F_18 ( V_46 -> V_59 ) ; V_51 ++ ) {
V_47 = ( 1 << ( V_46 -> V_59 [ V_51 ] . V_9 &
V_10 ) ) - 1 ;
V_48 = ( V_47 >> 1 ) +
( V_46 -> V_59 [ V_51 ] . V_5 &
V_8 ) ;
V_52 = V_4 [ ( V_46 -> V_59 [ V_51 ] .
V_5 &
V_6 ) >> 5 ] ;
V_27 -> V_31 . V_34 [ V_52 ] = V_52 ;
V_49 [ V_52 ] = V_48 ;
F_9 ( V_27 -> V_15 -> V_19 , L_13 ,
( 1 << ( ( V_46 -> V_59 [ V_51 ] . V_9 &
V_11 ) >> 4 ) ) - 1 ,
V_47 , V_48 ) ;
F_1 ( & V_46 -> V_59 [ V_51 ] ) ;
}
for ( V_28 = 0 ; V_28 < V_51 ; V_28 ++ ) {
for ( V_50 = 1 ; V_50 < V_51 - V_28 ; V_50 ++ ) {
if ( V_49 [ V_50 - 1 ] > V_49 [ V_50 ] ) {
F_19 ( V_49 [ V_50 - 1 ] , V_49 [ V_50 ] ) ;
F_19 ( V_27 -> V_31 . V_34 [ V_50 - 1 ] ,
V_27 -> V_31 . V_34 [ V_50 ] ) ;
} else if ( V_49 [ V_50 - 1 ] == V_49 [ V_50 ] ) {
if ( V_27 -> V_31 . V_34 [ V_50 - 1 ]
< V_27 -> V_31 . V_34 [ V_50 ] )
F_19 ( V_27 -> V_31 . V_34 [ V_50 - 1 ] ,
V_27 -> V_31 . V_34 [ V_50 ] ) ;
}
}
}
F_15 ( & V_27 -> V_31 ) ;
}
static enum V_60
F_20 ( struct V_26 * V_27 ,
enum V_60 V_61 )
{
int V_62 ;
enum V_60 V_63 ;
struct V_64 * V_65 ;
V_65 = & V_27 -> V_31 . V_65 [ V_61 ] ;
if ( ! V_65 -> V_66 )
return V_61 ;
V_63 = V_38 ;
for ( V_62 = V_38 ; V_62 < V_61 ; V_62 ++ ) {
V_65 = & V_27 -> V_31 . V_65 [ V_62 ] ;
if ( ! V_65 -> V_66 && ! V_65 -> V_67 )
V_63 = (enum V_60 ) V_62 ;
}
return V_63 ;
}
void
F_21 ( struct V_26 * V_27 )
{
int V_68 ;
F_9 ( V_27 -> V_15 -> V_19 , L_14
L_15 ) ;
if ( ! V_27 -> V_53 ) {
for ( V_68 = V_38 ; V_68 <= V_35 ; V_68 ++ )
V_27 -> V_31 . V_69 [ V_68 ] =
(enum V_60 ) V_68 ;
} else {
for ( V_68 = V_38 ; V_68 <= V_35 ; V_68 ++ ) {
V_27 -> V_31 . V_69 [ V_68 ]
= F_20 ( V_27 ,
(enum V_60 ) V_68 ) ;
F_9 ( V_27 -> V_15 -> V_19 , L_16 ,
V_68 , V_27 -> V_31 . V_69 [ V_68 ] ) ;
}
}
}
static enum V_60
F_22 ( struct V_14 * V_15 , T_3 V_70 )
{
const enum V_60 V_71 [] = { V_37 ,
V_38 ,
V_38 ,
V_37 ,
V_36 ,
V_36 ,
V_35 ,
V_35
} ;
if ( V_70 >= F_18 ( V_71 ) )
return V_37 ;
return V_71 [ V_70 ] ;
}
static T_1
F_23 ( struct V_26 * V_27 , T_3 V_72 )
{
enum V_60 V_73 , V_74 ;
T_1 V_75 ;
V_73 = F_22 ( V_27 -> V_15 , V_72 ) ;
V_74 = V_27 -> V_31 . V_69 [ V_73 ] ;
V_75 = V_41 [ V_74 ] [ V_72 % 2 ] ;
return V_75 ;
}
void
F_24 ( struct V_14 * V_15 )
{
int V_28 , V_50 ;
struct V_26 * V_27 ;
for ( V_50 = 0 ; V_50 < V_15 -> V_76 ; ++ V_50 ) {
V_27 = V_15 -> V_27 [ V_50 ] ;
if ( ! V_27 )
continue;
for ( V_28 = 0 ; V_28 < V_29 ; ++ V_28 ) {
V_27 -> V_77 [ V_28 ] . V_78 = V_42 [ V_28 ] ;
V_27 -> V_77 [ V_28 ] . V_79 = V_42 [ V_28 ] ;
V_27 -> V_77 [ V_28 ] . V_80 = V_42 [ V_28 ] ;
V_27 -> V_31 . V_32 [ V_28 ] . V_33 = NULL ;
}
V_27 -> V_77 [ 6 ] . V_78
= V_27 -> V_77 [ 6 ] . V_79
= V_27 -> V_77 [ 6 ] . V_80
= V_81 ;
V_27 -> V_77 [ 7 ] . V_78 = V_27 -> V_77 [ 7 ] . V_79
= V_27 -> V_77 [ 7 ] . V_80
= V_81 ;
V_27 -> V_82 . V_83 = V_84 ;
V_27 -> V_82 . V_85 = V_86 ;
V_27 -> V_82 . V_87 = V_88 ;
F_16 ( & V_27 -> V_31 . V_89 , 0 ) ;
F_16 ( & V_27 -> V_31 . V_43 , V_44 ) ;
}
}
int
F_25 ( struct V_14 * V_15 )
{
int V_28 ;
struct V_26 * V_27 ;
for ( V_28 = 0 ; V_28 < V_15 -> V_76 ; ++ V_28 ) {
V_27 = V_15 -> V_27 [ V_28 ] ;
if ( V_27 && F_26 ( & V_27 -> V_31 . V_89 ) )
return false ;
}
return true ;
}
static void
F_27 ( struct V_26 * V_27 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_27 -> V_15 ;
struct V_90 * V_91 , * V_49 ;
F_28 (&ra_list->skb_head, skb, tmp)
F_29 ( V_15 , V_91 , - 1 ) ;
}
static void
F_30 ( struct V_26 * V_27 ,
struct V_92 * V_93 )
{
struct V_13 * V_17 ;
F_31 (ra_list, ra_list_head, list)
F_27 ( V_27 , V_17 ) ;
}
static void F_32 ( struct V_26 * V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ )
F_30 ( V_27 , & V_27 -> V_31 . V_32 [ V_28 ] .
V_17 ) ;
F_16 ( & V_27 -> V_31 . V_89 , 0 ) ;
F_16 ( & V_27 -> V_31 . V_43 , V_44 ) ;
}
static void F_33 ( struct V_26 * V_27 )
{
struct V_13 * V_17 , * V_94 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; ++ V_28 ) {
F_9 ( V_27 -> V_15 -> V_19 ,
L_17 , V_28 ) ;
F_34 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list, list) {
F_35 ( & V_17 -> V_21 ) ;
F_36 ( V_17 ) ;
}
F_7 ( & V_27 -> V_31 . V_32 [ V_28 ] . V_17 ) ;
V_27 -> V_31 . V_32 [ V_28 ] . V_33 = NULL ;
}
}
void
F_37 ( struct V_26 * V_27 )
{
unsigned long V_95 ;
F_38 ( V_27 ) ;
F_39 ( & V_27 -> V_31 . V_96 , V_95 ) ;
F_32 ( V_27 ) ;
F_40 ( V_27 ) ;
if ( V_27 -> V_15 -> V_97 . V_98 )
V_27 -> V_15 -> V_97 . V_98 ( V_27 -> V_15 ) ;
F_33 ( V_27 ) ;
memcpy ( V_40 , V_41 , sizeof( V_40 ) ) ;
F_41 ( & V_27 -> V_31 . V_96 , V_95 ) ;
}
static struct V_13 *
F_42 ( struct V_26 * V_27 , T_1 V_72 ,
T_1 * V_99 )
{
struct V_13 * V_17 ;
F_31 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_99 , V_23 ) )
return V_17 ;
}
return NULL ;
}
static struct V_13 *
F_43 ( struct V_26 * V_27 , T_1 V_72 , T_1 * V_99 )
{
struct V_13 * V_17 ;
V_17 = F_42 ( V_27 , V_72 , V_99 ) ;
if ( V_17 )
return V_17 ;
F_10 ( V_27 , V_99 ) ;
return F_42 ( V_27 , V_72 , V_99 ) ;
}
int
F_44 ( struct V_26 * V_27 ,
struct V_13 * V_17 , int V_100 )
{
struct V_13 * V_101 ;
F_31 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_101 == V_17 )
return true ;
}
return false ;
}
void
F_45 ( struct V_14 * V_15 ,
struct V_90 * V_91 )
{
struct V_102 * V_103 = F_46 ( V_91 ) ;
struct V_26 * V_27 = V_15 -> V_27 [ V_103 -> V_104 ] ;
T_3 V_72 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_23 ] , V_105 ;
unsigned long V_95 ;
if ( ! V_27 -> V_106 ) {
F_9 ( V_15 -> V_19 , L_18 ) ;
F_29 ( V_15 , V_91 , - 1 ) ;
return;
}
V_72 = V_91 -> V_107 ;
F_39 ( & V_27 -> V_31 . V_96 , V_95 ) ;
V_105 = F_23 ( V_27 , V_72 ) ;
if ( ! F_11 ( V_27 ) ) {
if ( ! F_47 ( & V_27 -> V_31 . V_32 [ V_105 ] . V_17 ) )
V_17 = F_48 (
& V_27 -> V_31 . V_32 [ V_105 ] . V_17 ,
struct V_13 , V_21 ) ;
else
V_17 = NULL ;
} else {
memcpy ( V_16 , V_91 -> V_108 , V_23 ) ;
if ( V_16 [ 0 ] & 0x01 )
memset ( V_16 , 0xff , V_23 ) ;
V_17 = F_43 ( V_27 , V_105 , V_16 ) ;
}
if ( ! V_17 ) {
F_41 ( & V_27 -> V_31 . V_96 , V_95 ) ;
F_29 ( V_15 , V_91 , - 1 ) ;
return;
}
F_49 ( & V_17 -> V_22 , V_91 ) ;
V_17 -> V_24 += V_91 -> V_109 ;
V_17 -> V_25 ++ ;
F_50 ( & V_27 -> V_31 . V_89 ) ;
if ( F_26 ( & V_27 -> V_31 . V_43 ) <
V_42 [ V_105 ] )
F_16 ( & V_27 -> V_31 . V_43 ,
V_42 [ V_105 ] ) ;
F_41 ( & V_27 -> V_31 . V_96 , V_95 ) ;
}
int F_51 ( struct V_26 * V_27 ,
const struct V_110 * V_111 )
{
T_1 * V_112 = ( T_1 * ) & V_111 -> V_113 . V_114 ;
T_4 V_115 = F_3 ( V_111 -> V_116 ) , V_117 ;
int V_118 = true ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_45 * V_123 = NULL ;
struct V_64 * V_65 ;
F_9 ( V_27 -> V_15 -> V_19 , L_19 ,
V_115 ) ;
while ( ( V_115 >= sizeof( V_120 -> V_124 ) ) && V_118 ) {
V_120 = (struct V_119 * ) V_112 ;
V_117 = F_3 ( V_120 -> V_124 . V_109 ) ;
switch ( F_3 ( V_120 -> V_124 . type ) ) {
case V_125 :
V_122 =
(struct V_121 * )
V_120 ;
F_9 ( V_27 -> V_15 -> V_19 ,
L_20
L_21 ,
V_122 -> V_126 ,
V_122 -> V_67 ,
V_122 -> V_66 ) ;
V_65 = & V_27 -> V_31 . V_65 [ V_122 ->
V_126 ] ;
V_65 -> V_66 = V_122 -> V_66 ;
V_65 -> V_67 =
V_122 -> V_67 ;
V_65 -> V_127 = V_122 -> V_127 ;
break;
case V_128 :
V_123 =
(struct V_45 * ) ( V_112 +
2 ) ;
V_123 -> V_54 . V_109 = ( T_1 ) V_117 ;
V_123 -> V_54 . V_129 =
V_128 ;
F_9 ( V_27 -> V_15 -> V_19 ,
L_20
L_22 ,
V_123 -> V_56 &
V_57 ) ;
memcpy ( ( T_1 * ) & V_27 -> V_130 . V_131 .
V_46 , V_123 ,
V_123 -> V_54 . V_109 + 2 ) ;
break;
default:
V_118 = false ;
break;
}
V_112 += ( V_117 + sizeof( V_120 -> V_124 ) ) ;
V_115 -= ( V_117 + sizeof( V_120 -> V_124 ) ) ;
}
F_17 ( V_27 , V_123 ) ;
F_21 ( V_27 ) ;
return 0 ;
}
T_3
F_52 ( struct V_26 * V_27 ,
T_1 * * V_132 ,
struct V_45 * V_46 ,
struct V_133 * V_134 )
{
struct V_135 * V_136 ;
T_3 V_137 = 0 ;
if ( ! V_132 )
return 0 ;
if ( ! ( * V_132 ) )
return 0 ;
if ( ! V_46 )
return 0 ;
F_9 ( V_27 -> V_15 -> V_19 , L_23
L_24 ,
V_46 -> V_54 . V_129 ) ;
if ( ( V_27 -> V_138
|| ( V_134 && ( V_27 -> V_15 -> V_139 & V_140
|| V_27 -> V_15 -> V_139 & V_141 ) )
)
&& V_46 -> V_54 . V_129 == V_128 ) {
V_136 = (struct V_135 * ) * V_132 ;
V_136 -> V_124 . type = F_53 ( ( T_2 ) V_142 [ 0 ] ) ;
V_136 -> V_124 . V_109 = F_53 ( ( T_2 ) V_142 [ 1 ] ) ;
memcpy ( V_136 -> V_46 , & V_142 [ 2 ] ,
F_3 ( V_136 -> V_124 . V_109 ) ) ;
if ( V_46 -> V_56 & V_143 )
memcpy ( ( T_1 * ) ( V_136 -> V_46
+ F_3 ( V_136 -> V_124 . V_109 )
- sizeof( V_27 -> V_144 ) ) ,
& V_27 -> V_144 ,
sizeof( V_27 -> V_144 ) ) ;
V_137 = sizeof( V_136 -> V_124 )
+ F_3 ( V_136 -> V_124 . V_109 ) ;
* V_132 += V_137 ;
}
return V_137 ;
}
T_1
F_54 ( struct V_26 * V_27 ,
const struct V_90 * V_91 )
{
T_1 V_145 ;
struct V_146 V_147 , V_148 ;
T_3 V_149 ;
F_55 ( & V_147 ) ;
V_148 = F_56 ( V_91 -> V_150 ) ;
V_149 = ( V_147 . V_151 - V_148 . V_151 ) * 1000 ;
V_149 += ( V_147 . V_152 - V_148 . V_152 ) / 1000 ;
V_145 = ( T_1 ) ( F_57 ( V_149 , V_27 -> V_31 . V_153 ) >> 1 ) ;
F_9 ( V_27 -> V_15 -> V_19 , L_25
L_26 , V_149 , V_145 ) ;
return V_145 ;
}
static struct V_13 *
F_58 ( struct V_14 * V_15 ,
struct V_26 * * V_27 , int * V_72 )
{
struct V_26 * V_154 ;
struct V_13 * V_155 , * V_156 ;
struct V_157 * V_158 , * V_159 ;
struct V_160 * V_161 ;
int V_162 ;
unsigned long V_95 ;
int V_28 , V_50 ;
for ( V_50 = V_15 -> V_76 - 1 ; V_50 >= 0 ; -- V_50 ) {
F_39 ( & V_15 -> V_163 [ V_50 ] . V_164 ,
V_95 ) ;
V_162 = F_47 ( & V_15 -> V_163 [ V_50 ]
. V_165 ) ;
F_41 ( & V_15 -> V_163 [ V_50 ] . V_164 ,
V_95 ) ;
if ( V_162 )
continue;
if ( V_15 -> V_163 [ V_50 ] . V_166 ==
(struct V_157 * )
& V_15 -> V_163 [ V_50 ] . V_165 ) {
V_158 =
F_48 ( & V_15 -> V_163 [ V_50 ]
. V_165 ,
struct V_157 ,
V_21 ) ;
V_159 = V_158 ;
} else {
V_158 = V_15 -> V_163 [ V_50 ] . V_166 ;
V_159 = V_158 ;
}
do {
T_5 * V_167 ;
T_6 * V_168 ;
V_154 = V_158 -> V_27 ;
V_167 = & V_154 -> V_31 . V_43 ;
V_168 = & V_154 -> V_31 . V_96 ;
for ( V_28 = F_26 ( V_167 ) ; V_28 >= V_169 ; -- V_28 ) {
V_161 = & ( V_154 ) -> V_31 .
V_32 [ V_40 [ V_28 ] ] ;
F_39 ( & V_161 -> V_170 ,
V_95 ) ;
V_162 =
F_47 ( & V_15 -> V_163 [ V_50 ]
. V_165 ) ;
F_41 ( & V_161 -> V_170 ,
V_95 ) ;
if ( V_162 )
continue;
V_155 = F_48 (
& V_161 -> V_33 -> V_21 ,
struct V_13 ,
V_21 ) ;
V_156 = V_155 ;
if ( V_155 == (struct V_13 * )
& V_161 -> V_17 ) {
V_155 = F_48 ( & V_155 -> V_21 ,
struct V_13 , V_21 ) ;
V_156 = V_155 ;
}
do {
V_162 =
F_59 ( & V_155 -> V_22 ) ;
if ( ! V_162 ) {
F_39 ( V_168 , V_95 ) ;
if ( F_26 ( V_167 ) > V_28 )
F_16 ( V_167 , V_28 ) ;
F_41 ( V_168 ,
V_95 ) ;
* V_27 = V_154 ;
* V_72 = V_40 [ V_28 ] ;
return V_155 ;
}
V_155 = F_48 ( & V_155 -> V_21 ,
struct V_13 ,
V_21 ) ;
if ( V_155 ==
(struct V_13 * )
& V_161 -> V_17 )
V_155 = F_48 (
& V_155 -> V_21 ,
struct V_13 ,
V_21 ) ;
} while ( V_155 != V_156 );
}
F_16 ( V_167 , V_171 ) ;
V_158 = F_48 ( & V_158 -> V_21 ,
struct V_157 ,
V_21 ) ;
if ( V_158 ==
(struct V_157 * )
& V_15 -> V_163 [ V_50 ] . V_165 )
V_158 = F_48 (
& V_158 -> V_21 ,
struct V_157 ,
V_21 ) ;
} while ( V_158 != V_159 );
}
return NULL ;
}
static void
F_60 ( struct V_26 * V_27 ,
struct V_13 * V_155 , int V_100 ,
unsigned long V_172 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_61 ( struct V_26 * V_27 ,
struct V_13 * V_155 )
{
struct V_90 * V_91 ;
struct V_102 * V_103 ;
if ( F_59 ( & V_155 -> V_22 ) )
return false ;
V_91 = F_62 ( & V_155 -> V_22 ) ;
V_103 = F_46 ( V_91 ) ;
if ( V_103 -> V_95 & V_173 )
return true ;
return false ;
}
static void
F_63 ( struct V_26 * V_27 ,
struct V_13 * V_155 , int V_100 ,
unsigned long V_172 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_64 ( struct V_14 * V_15 )
{
struct V_13 * V_155 ;
struct V_26 * V_27 = NULL ;
int V_100 = 0 ;
T_1 V_16 [ V_23 ] ;
int V_174 = 0 , V_72 = 0 ;
unsigned long V_95 ;
V_155 = F_58 ( V_15 , & V_27 , & V_100 ) ;
if ( ! V_155 )
return - 1 ;
V_72 = F_65 ( V_155 ) ;
F_9 ( V_15 -> V_19 , L_27 , V_72 ) ;
F_39 ( & V_27 -> V_31 . V_96 , V_95 ) ;
if ( ! F_44 ( V_27 , V_155 , V_100 ) ) {
F_41 ( & V_27 -> V_31 . V_96 , V_95 ) ;
return - 1 ;
}
if ( F_61 ( V_27 , V_155 ) ) {
F_63 ( V_27 , V_155 , V_100 , V_95 ) ;
return 0 ;
}
if ( ! V_155 -> V_30 || F_66 ( V_27 , V_155 , V_72 )
|| ( ( V_27 -> V_175 . V_176
|| V_27 -> V_175 . V_177 ) && ! V_27 -> V_178 )
) {
F_60 ( V_27 , V_155 , V_100 , V_95 ) ;
} else {
if ( F_67 ( V_27 , V_72 ) ) {
if ( F_68 ( V_15 ) ) {
F_69 ( V_27 ,
V_155 -> V_16 , V_72 ,
V_179 ) ;
F_70 ( V_27 , V_72 , V_155 -> V_16 ) ;
} else if ( F_71
( V_27 , V_72 , & V_174 , V_16 ) ) {
F_69 ( V_27 ,
V_155 -> V_16 , V_72 ,
V_179 ) ;
F_72 ( V_27 , V_174 , V_16 , 1 ) ;
}
}
#define F_73 2
if ( F_74 ( V_27 , V_72 ) &&
( V_155 -> V_25 >= F_73 ) )
F_75 ( V_27 , V_155 , V_180 ,
V_100 , V_95 ) ;
else
F_60 ( V_27 , V_155 , V_100 , V_95 ) ;
}
return 0 ;
}
void
F_76 ( struct V_14 * V_15 )
{
do {
if ( V_15 -> V_181 || V_15 -> V_182 )
break;
if ( F_64 ( V_15 ) )
break;
} while ( ! F_25 ( V_15 ) );
}
