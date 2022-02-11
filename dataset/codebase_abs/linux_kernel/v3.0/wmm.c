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
void
F_10 ( struct V_25 * V_26 , T_1 * V_16 )
{
int V_27 ;
struct V_13 * V_17 ;
struct V_14 * V_15 = V_26 -> V_15 ;
for ( V_27 = 0 ; V_27 < V_28 ; ++ V_27 ) {
V_17 = F_4 ( V_15 , V_16 ) ;
F_9 ( V_15 -> V_19 , L_9 , V_17 ) ;
if ( ! V_17 )
break;
if ( ! F_11 ( V_26 ) )
V_17 -> V_29 = F_12 ( V_26 ) ;
else
V_17 -> V_29 = false ;
F_9 ( V_15 -> V_19 , L_10 ,
V_17 , V_17 -> V_29 ) ;
F_13 ( & V_17 -> V_21 ,
& V_26 -> V_30 . V_31 [ V_27 ] . V_17 ) ;
if ( ! V_26 -> V_30 . V_31 [ V_27 ] . V_32 )
V_26 -> V_30 . V_31 [ V_27 ] . V_32 = V_17 ;
}
}
static void F_14 ( struct V_25 * V_26 )
{
V_26 -> V_30 . V_33 [ 0 ] = V_34 ;
V_26 -> V_30 . V_33 [ 1 ] = V_35 ;
V_26 -> V_30 . V_33 [ 2 ] = V_36 ;
V_26 -> V_30 . V_33 [ 3 ] = V_37 ;
}
static void
F_15 ( struct V_38 * V_30 )
{
T_1 * V_33 = V_30 -> V_33 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 4 ; ++ V_27 ) {
V_39 [ 7 - ( V_27 * 2 ) ] = V_40 [ V_33 [ V_27 ] ] [ 1 ] ;
V_39 [ 6 - ( V_27 * 2 ) ] = V_40 [ V_33 [ V_27 ] ] [ 0 ] ;
}
for ( V_27 = 0 ; V_27 < V_28 ; ++ V_27 )
V_41 [ V_39 [ V_27 ] ] = ( T_1 ) V_27 ;
F_16 ( & V_30 -> V_42 , V_43 ) ;
}
void
F_17 ( struct V_25 * V_26 ,
struct V_44 * V_45 )
{
T_2 V_46 , V_47 , V_48 [ 4 ] ;
T_3 V_27 , V_49 , V_50 ;
T_1 V_51 ;
if ( ! V_45 || ! V_26 -> V_52 ) {
F_14 ( V_26 ) ;
return;
}
F_9 ( V_26 -> V_15 -> V_19 , L_11
L_12 ,
V_45 -> V_53 . V_54 , V_45 -> V_55 &
V_56 ,
V_45 -> V_57 ) ;
for ( V_50 = 0 ; V_50 < F_18 ( V_45 -> V_58 ) ; V_50 ++ ) {
V_46 = ( 1 << ( V_45 -> V_58 [ V_50 ] . V_9 &
V_10 ) ) - 1 ;
V_47 = ( V_46 >> 1 ) +
( V_45 -> V_58 [ V_50 ] . V_5 &
V_8 ) ;
V_51 = V_4 [ ( V_45 -> V_58 [ V_50 ] .
V_5 &
V_6 ) >> 5 ] ;
V_26 -> V_30 . V_33 [ V_51 ] = V_51 ;
V_48 [ V_51 ] = V_47 ;
F_9 ( V_26 -> V_15 -> V_19 , L_13 ,
( 1 << ( ( V_45 -> V_58 [ V_50 ] . V_9 &
V_11 ) >> 4 ) ) - 1 ,
V_46 , V_47 ) ;
F_1 ( & V_45 -> V_58 [ V_50 ] ) ;
}
for ( V_27 = 0 ; V_27 < V_50 ; V_27 ++ ) {
for ( V_49 = 1 ; V_49 < V_50 - V_27 ; V_49 ++ ) {
if ( V_48 [ V_49 - 1 ] > V_48 [ V_49 ] ) {
F_19 ( V_48 [ V_49 - 1 ] , V_48 [ V_49 ] ) ;
F_19 ( V_26 -> V_30 . V_33 [ V_49 - 1 ] ,
V_26 -> V_30 . V_33 [ V_49 ] ) ;
} else if ( V_48 [ V_49 - 1 ] == V_48 [ V_49 ] ) {
if ( V_26 -> V_30 . V_33 [ V_49 - 1 ]
< V_26 -> V_30 . V_33 [ V_49 ] )
F_19 ( V_26 -> V_30 . V_33 [ V_49 - 1 ] ,
V_26 -> V_30 . V_33 [ V_49 ] ) ;
}
}
}
F_15 ( & V_26 -> V_30 ) ;
}
static enum V_59
F_20 ( struct V_25 * V_26 ,
enum V_59 V_60 )
{
int V_61 ;
enum V_59 V_62 ;
struct V_63 * V_64 ;
V_64 = & V_26 -> V_30 . V_64 [ V_60 ] ;
if ( ! V_64 -> V_65 )
return V_60 ;
V_62 = V_37 ;
for ( V_61 = V_37 ; V_61 < V_60 ; V_61 ++ ) {
V_64 = & V_26 -> V_30 . V_64 [ V_61 ] ;
if ( ! V_64 -> V_65 && ! V_64 -> V_66 )
V_62 = (enum V_59 ) V_61 ;
}
return V_62 ;
}
void
F_21 ( struct V_25 * V_26 )
{
int V_67 ;
F_9 ( V_26 -> V_15 -> V_19 , L_14
L_15 ) ;
if ( ! V_26 -> V_52 ) {
for ( V_67 = V_37 ; V_67 <= V_34 ; V_67 ++ )
V_26 -> V_30 . V_68 [ V_67 ] =
(enum V_59 ) V_67 ;
} else {
for ( V_67 = V_37 ; V_67 <= V_34 ; V_67 ++ ) {
V_26 -> V_30 . V_68 [ V_67 ]
= F_20 ( V_26 ,
(enum V_59 ) V_67 ) ;
F_9 ( V_26 -> V_15 -> V_19 , L_16 ,
V_67 , V_26 -> V_30 . V_68 [ V_67 ] ) ;
}
}
}
static enum V_59
F_22 ( struct V_14 * V_15 , T_3 V_69 )
{
const enum V_59 V_70 [] = { V_36 ,
V_37 ,
V_37 ,
V_36 ,
V_35 ,
V_35 ,
V_34 ,
V_34
} ;
if ( V_69 >= F_18 ( V_70 ) )
return V_36 ;
return V_70 [ V_69 ] ;
}
static T_1
F_23 ( struct V_25 * V_26 , T_3 V_71 )
{
enum V_59 V_72 , V_73 ;
T_1 V_74 ;
V_72 = F_22 ( V_26 -> V_15 , V_71 ) ;
V_73 = V_26 -> V_30 . V_68 [ V_72 ] ;
V_74 = V_40 [ V_73 ] [ V_71 % 2 ] ;
return V_74 ;
}
void
F_24 ( struct V_14 * V_15 )
{
int V_27 , V_49 ;
struct V_25 * V_26 ;
for ( V_49 = 0 ; V_49 < V_15 -> V_75 ; ++ V_49 ) {
V_26 = V_15 -> V_26 [ V_49 ] ;
if ( ! V_26 )
continue;
for ( V_27 = 0 ; V_27 < V_28 ; ++ V_27 ) {
V_26 -> V_76 [ V_27 ] . V_77 = V_41 [ V_27 ] ;
V_26 -> V_76 [ V_27 ] . V_78 = V_41 [ V_27 ] ;
V_26 -> V_76 [ V_27 ] . V_79 = V_41 [ V_27 ] ;
V_26 -> V_30 . V_31 [ V_27 ] . V_32 = NULL ;
}
V_26 -> V_76 [ 6 ] . V_77
= V_26 -> V_76 [ 6 ] . V_78
= V_26 -> V_76 [ 6 ] . V_79
= V_80 ;
V_26 -> V_76 [ 7 ] . V_77 = V_26 -> V_76 [ 7 ] . V_78
= V_26 -> V_76 [ 7 ] . V_79
= V_80 ;
V_26 -> V_81 . V_82 = V_83 ;
V_26 -> V_81 . V_84 = V_85 ;
V_26 -> V_81 . V_86 = V_87 ;
F_16 ( & V_26 -> V_30 . V_88 , 0 ) ;
F_16 ( & V_26 -> V_30 . V_42 , V_43 ) ;
}
}
int
F_25 ( struct V_14 * V_15 )
{
int V_27 ;
struct V_25 * V_26 ;
for ( V_27 = 0 ; V_27 < V_15 -> V_75 ; ++ V_27 ) {
V_26 = V_15 -> V_26 [ V_27 ] ;
if ( V_26 && F_26 ( & V_26 -> V_30 . V_88 ) )
return false ;
}
return true ;
}
static void
F_27 ( struct V_25 * V_26 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_26 -> V_15 ;
struct V_89 * V_90 , * V_48 ;
F_28 (&ra_list->skb_head, skb, tmp)
F_29 ( V_15 , V_90 , - 1 ) ;
}
static void
F_30 ( struct V_25 * V_26 ,
struct V_91 * V_92 )
{
struct V_13 * V_17 ;
F_31 (ra_list, ra_list_head, list)
F_27 ( V_26 , V_17 ) ;
}
static void F_32 ( struct V_25 * V_26 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ )
F_30 ( V_26 , & V_26 -> V_30 . V_31 [ V_27 ] .
V_17 ) ;
F_16 ( & V_26 -> V_30 . V_88 , 0 ) ;
F_16 ( & V_26 -> V_30 . V_42 , V_43 ) ;
}
static void F_33 ( struct V_25 * V_26 )
{
struct V_13 * V_17 , * V_93 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; ++ V_27 ) {
F_9 ( V_26 -> V_15 -> V_19 ,
L_17 , V_27 ) ;
F_34 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list, list) {
F_35 ( & V_17 -> V_21 ) ;
F_36 ( V_17 ) ;
}
F_7 ( & V_26 -> V_30 . V_31 [ V_27 ] . V_17 ) ;
V_26 -> V_30 . V_31 [ V_27 ] . V_32 = NULL ;
}
}
void
F_37 ( struct V_25 * V_26 )
{
unsigned long V_94 ;
F_38 ( V_26 ) ;
F_39 ( & V_26 -> V_30 . V_95 , V_94 ) ;
F_32 ( V_26 ) ;
F_40 ( V_26 ) ;
if ( V_26 -> V_15 -> V_96 . V_97 )
V_26 -> V_15 -> V_96 . V_97 ( V_26 -> V_15 ) ;
F_33 ( V_26 ) ;
memcpy ( V_39 , V_40 , sizeof( V_39 ) ) ;
F_41 ( & V_26 -> V_30 . V_95 , V_94 ) ;
}
static struct V_13 *
F_42 ( struct V_25 * V_26 , T_1 V_71 ,
T_1 * V_98 )
{
struct V_13 * V_17 ;
F_31 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_98 , V_23 ) )
return V_17 ;
}
return NULL ;
}
static struct V_13 *
F_43 ( struct V_25 * V_26 , T_1 V_71 , T_1 * V_98 )
{
struct V_13 * V_17 ;
V_17 = F_42 ( V_26 , V_71 , V_98 ) ;
if ( V_17 )
return V_17 ;
F_10 ( V_26 , V_98 ) ;
return F_42 ( V_26 , V_71 , V_98 ) ;
}
int
F_44 ( struct V_25 * V_26 ,
struct V_13 * V_17 , int V_99 )
{
struct V_13 * V_100 ;
F_31 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_100 == V_17 )
return true ;
}
return false ;
}
void
F_45 ( struct V_14 * V_15 ,
struct V_89 * V_90 )
{
struct V_101 * V_102 = F_46 ( V_90 ) ;
struct V_25 * V_26 = V_15 -> V_26 [ V_102 -> V_103 ] ;
T_3 V_71 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_23 ] , V_104 ;
unsigned long V_94 ;
if ( ! V_26 -> V_105 ) {
F_9 ( V_15 -> V_19 , L_18 ) ;
F_29 ( V_15 , V_90 , - 1 ) ;
return;
}
V_71 = V_90 -> V_106 ;
F_39 ( & V_26 -> V_30 . V_95 , V_94 ) ;
V_104 = F_23 ( V_26 , V_71 ) ;
if ( ! F_11 ( V_26 ) ) {
if ( ! F_47 ( & V_26 -> V_30 . V_31 [ V_104 ] . V_17 ) )
V_17 = F_48 (
& V_26 -> V_30 . V_31 [ V_104 ] . V_17 ,
struct V_13 , V_21 ) ;
else
V_17 = NULL ;
} else {
memcpy ( V_16 , V_90 -> V_107 , V_23 ) ;
V_17 = F_43 ( V_26 , V_104 , V_16 ) ;
}
if ( ! V_17 ) {
F_41 ( & V_26 -> V_30 . V_95 , V_94 ) ;
F_29 ( V_15 , V_90 , - 1 ) ;
return;
}
F_49 ( & V_17 -> V_22 , V_90 ) ;
V_17 -> V_24 += V_90 -> V_108 ;
F_50 ( & V_26 -> V_30 . V_88 ) ;
if ( F_26 ( & V_26 -> V_30 . V_42 ) <
V_41 [ V_104 ] )
F_16 ( & V_26 -> V_30 . V_42 ,
V_41 [ V_104 ] ) ;
F_41 ( & V_26 -> V_30 . V_95 , V_94 ) ;
}
int F_51 ( struct V_25 * V_26 ,
const struct V_109 * V_110 )
{
T_1 * V_111 = ( T_1 * ) & V_110 -> V_112 . V_113 ;
T_4 V_114 = F_3 ( V_110 -> V_115 ) , V_116 ;
int V_117 = true ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
struct V_44 * V_122 = NULL ;
struct V_63 * V_64 ;
F_9 ( V_26 -> V_15 -> V_19 , L_19 ,
V_114 ) ;
while ( ( V_114 >= sizeof( V_119 -> V_123 ) ) && V_117 ) {
V_119 = (struct V_118 * ) V_111 ;
V_116 = F_3 ( V_119 -> V_123 . V_108 ) ;
switch ( F_3 ( V_119 -> V_123 . type ) ) {
case V_124 :
V_121 =
(struct V_120 * )
V_119 ;
F_9 ( V_26 -> V_15 -> V_19 ,
L_20
L_21 ,
V_121 -> V_125 ,
V_121 -> V_66 ,
V_121 -> V_65 ) ;
V_64 = & V_26 -> V_30 . V_64 [ V_121 ->
V_125 ] ;
V_64 -> V_65 = V_121 -> V_65 ;
V_64 -> V_66 =
V_121 -> V_66 ;
V_64 -> V_126 = V_121 -> V_126 ;
break;
case V_127 :
V_122 =
(struct V_44 * ) ( V_111 +
2 ) ;
V_122 -> V_53 . V_108 = ( T_1 ) V_116 ;
V_122 -> V_53 . V_128 =
V_127 ;
F_9 ( V_26 -> V_15 -> V_19 ,
L_20
L_22 ,
V_122 -> V_55 &
V_56 ) ;
memcpy ( ( T_1 * ) & V_26 -> V_129 . V_130 .
V_45 , V_122 ,
V_122 -> V_53 . V_108 + 2 ) ;
break;
default:
V_117 = false ;
break;
}
V_111 += ( V_116 + sizeof( V_119 -> V_123 ) ) ;
V_114 -= ( V_116 + sizeof( V_119 -> V_123 ) ) ;
}
F_17 ( V_26 , V_122 ) ;
F_21 ( V_26 ) ;
return 0 ;
}
T_3
F_52 ( struct V_25 * V_26 ,
T_1 * * V_131 ,
struct V_44 * V_45 ,
struct V_132 * V_133 )
{
struct V_134 * V_135 ;
T_3 V_136 = 0 ;
if ( ! V_131 )
return 0 ;
if ( ! ( * V_131 ) )
return 0 ;
if ( ! V_45 )
return 0 ;
F_9 ( V_26 -> V_15 -> V_19 , L_23
L_24 ,
V_45 -> V_53 . V_128 ) ;
if ( ( V_26 -> V_137
|| ( V_133 && ( V_26 -> V_15 -> V_138 & V_139
|| V_26 -> V_15 -> V_138 & V_140 ) )
)
&& V_45 -> V_53 . V_128 == V_127 ) {
V_135 = (struct V_134 * ) * V_131 ;
V_135 -> V_123 . type = F_53 ( ( T_2 ) V_141 [ 0 ] ) ;
V_135 -> V_123 . V_108 = F_53 ( ( T_2 ) V_141 [ 1 ] ) ;
memcpy ( V_135 -> V_45 , & V_141 [ 2 ] ,
F_3 ( V_135 -> V_123 . V_108 ) ) ;
if ( V_45 -> V_55 & V_142 )
memcpy ( ( T_1 * ) ( V_135 -> V_45
+ F_3 ( V_135 -> V_123 . V_108 )
- sizeof( V_26 -> V_143 ) ) ,
& V_26 -> V_143 ,
sizeof( V_26 -> V_143 ) ) ;
V_136 = sizeof( V_135 -> V_123 )
+ F_3 ( V_135 -> V_123 . V_108 ) ;
* V_131 += V_136 ;
}
return V_136 ;
}
T_1
F_54 ( struct V_25 * V_26 ,
const struct V_89 * V_90 )
{
T_1 V_144 ;
struct V_145 V_146 , V_147 ;
T_3 V_148 ;
F_55 ( & V_146 ) ;
V_147 = F_56 ( V_90 -> V_149 ) ;
V_148 = ( V_146 . V_150 - V_147 . V_150 ) * 1000 ;
V_148 += ( V_146 . V_151 - V_147 . V_151 ) / 1000 ;
V_144 = ( T_1 ) ( F_57 ( V_148 , V_26 -> V_30 . V_152 ) >> 1 ) ;
F_9 ( V_26 -> V_15 -> V_19 , L_25
L_26 , V_148 , V_144 ) ;
return V_144 ;
}
static struct V_13 *
F_58 ( struct V_14 * V_15 ,
struct V_25 * * V_26 , int * V_71 )
{
struct V_25 * V_153 ;
struct V_13 * V_154 , * V_155 ;
struct V_156 * V_157 , * V_158 ;
struct V_159 * V_160 ;
int V_161 ;
unsigned long V_94 ;
int V_27 , V_49 ;
for ( V_49 = V_15 -> V_75 - 1 ; V_49 >= 0 ; -- V_49 ) {
F_39 ( & V_15 -> V_162 [ V_49 ] . V_163 ,
V_94 ) ;
V_161 = F_47 ( & V_15 -> V_162 [ V_49 ]
. V_164 ) ;
F_41 ( & V_15 -> V_162 [ V_49 ] . V_163 ,
V_94 ) ;
if ( V_161 )
continue;
if ( V_15 -> V_162 [ V_49 ] . V_165 ==
(struct V_156 * )
& V_15 -> V_162 [ V_49 ] . V_164 ) {
V_157 =
F_48 ( & V_15 -> V_162 [ V_49 ]
. V_164 ,
struct V_156 ,
V_21 ) ;
V_158 = V_157 ;
} else {
V_157 = V_15 -> V_162 [ V_49 ] . V_165 ;
V_158 = V_157 ;
}
do {
T_5 * V_166 ;
T_6 * V_167 ;
V_153 = V_157 -> V_26 ;
V_166 = & V_153 -> V_30 . V_42 ;
V_167 = & V_153 -> V_30 . V_95 ;
for ( V_27 = F_26 ( V_166 ) ; V_27 >= V_168 ; -- V_27 ) {
V_160 = & ( V_153 ) -> V_30 .
V_31 [ V_39 [ V_27 ] ] ;
F_39 ( & V_160 -> V_169 ,
V_94 ) ;
V_161 =
F_47 ( & V_15 -> V_162 [ V_49 ]
. V_164 ) ;
F_41 ( & V_160 -> V_169 ,
V_94 ) ;
if ( V_161 )
continue;
V_154 = F_48 (
& V_160 -> V_32 -> V_21 ,
struct V_13 ,
V_21 ) ;
V_155 = V_154 ;
if ( V_154 == (struct V_13 * )
& V_160 -> V_17 ) {
V_154 = F_48 ( & V_154 -> V_21 ,
struct V_13 , V_21 ) ;
V_155 = V_154 ;
}
do {
V_161 =
F_59 ( & V_154 -> V_22 ) ;
if ( ! V_161 ) {
F_39 ( V_167 , V_94 ) ;
if ( F_26 ( V_166 ) > V_27 )
F_16 ( V_166 , V_27 ) ;
F_41 ( V_167 ,
V_94 ) ;
* V_26 = V_153 ;
* V_71 = V_39 [ V_27 ] ;
return V_154 ;
}
V_154 = F_48 ( & V_154 -> V_21 ,
struct V_13 ,
V_21 ) ;
if ( V_154 ==
(struct V_13 * )
& V_160 -> V_17 )
V_154 = F_48 (
& V_154 -> V_21 ,
struct V_13 ,
V_21 ) ;
} while ( V_154 != V_155 );
}
F_16 ( V_166 , V_170 ) ;
V_157 = F_48 ( & V_157 -> V_21 ,
struct V_156 ,
V_21 ) ;
if ( V_157 ==
(struct V_156 * )
& V_15 -> V_162 [ V_49 ] . V_164 )
V_157 = F_48 (
& V_157 -> V_21 ,
struct V_156 ,
V_21 ) ;
} while ( V_157 != V_158 );
}
return NULL ;
}
static int
F_60 ( struct V_25 * V_26 ,
struct V_13 * V_154 , int V_171 )
{
int V_172 = 0 , V_173 = 0 ;
struct V_89 * V_90 , * V_48 ;
F_28 (&ptr->skb_head, skb, tmp) {
V_173 += V_90 -> V_108 ;
if ( V_173 < V_171 )
++ V_172 ;
else
break;
}
return V_172 ;
}
static void
F_61 ( struct V_25 * V_26 ,
struct V_13 * V_154 , int V_99 ,
unsigned long V_174 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_62 ( struct V_25 * V_26 ,
struct V_13 * V_154 )
{
struct V_89 * V_90 ;
struct V_101 * V_102 ;
if ( F_59 ( & V_154 -> V_22 ) )
return false ;
V_90 = F_63 ( & V_154 -> V_22 ) ;
V_102 = F_46 ( V_90 ) ;
if ( V_102 -> V_94 & V_175 )
return true ;
return false ;
}
static void
F_64 ( struct V_25 * V_26 ,
struct V_13 * V_154 , int V_99 ,
unsigned long V_174 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_65 ( struct V_14 * V_15 )
{
struct V_13 * V_154 ;
struct V_25 * V_26 = NULL ;
int V_99 = 0 ;
T_1 V_16 [ V_23 ] ;
int V_176 = 0 , V_71 = 0 ;
unsigned long V_94 ;
V_154 = F_58 ( V_15 , & V_26 , & V_99 ) ;
if ( ! V_154 )
return - 1 ;
V_71 = F_66 ( V_154 ) ;
F_9 ( V_15 -> V_19 , L_27 , V_71 ) ;
F_39 ( & V_26 -> V_30 . V_95 , V_94 ) ;
if ( ! F_44 ( V_26 , V_154 , V_99 ) ) {
F_41 ( & V_26 -> V_30 . V_95 , V_94 ) ;
return - 1 ;
}
if ( F_62 ( V_26 , V_154 ) ) {
F_64 ( V_26 , V_154 , V_99 , V_94 ) ;
return 0 ;
}
if ( ! V_154 -> V_29 || F_67 ( V_26 , V_154 , V_71 )
|| ( ( V_26 -> V_177 . V_178
|| V_26 -> V_177 . V_179 ) && ! V_26 -> V_180 )
) {
F_61 ( V_26 , V_154 , V_99 , V_94 ) ;
} else {
if ( F_68 ( V_26 , V_71 ) ) {
if ( F_69 ( V_15 ) ) {
F_70 ( V_26 ,
V_154 -> V_16 , V_71 ,
V_181 ) ;
F_71 ( V_26 , V_71 , V_154 -> V_16 ) ;
} else if ( F_72
( V_26 , V_71 , & V_176 , V_16 ) ) {
F_70 ( V_26 ,
V_154 -> V_16 , V_71 ,
V_181 ) ;
F_73 ( V_26 , V_176 , V_16 , 1 ) ;
}
}
#define F_74 2
if ( F_75 ( V_26 , V_71 ) &&
( F_60 ( V_26 , V_154 , V_15 -> V_182 ) >=
F_74 ) )
F_76 ( V_26 , V_154 , V_183 ,
V_99 , V_94 ) ;
else
F_61 ( V_26 , V_154 , V_99 , V_94 ) ;
}
return 0 ;
}
void
F_77 ( struct V_14 * V_15 )
{
do {
if ( V_15 -> V_184 || V_15 -> V_185 )
break;
if ( F_65 ( V_15 ) )
break;
} while ( ! F_25 ( V_15 ) );
}
