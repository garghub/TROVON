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
void
F_11 ( struct V_33 * V_34 , T_1 * V_16 )
{
int V_35 ;
struct V_13 * V_17 ;
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_36 * V_37 ;
unsigned long V_38 ;
F_12 ( & V_34 -> V_39 , V_38 ) ;
V_37 = F_13 ( V_34 , V_16 ) ;
F_14 ( & V_34 -> V_39 , V_38 ) ;
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 ) {
V_17 = F_4 ( V_15 , V_16 ) ;
F_8 ( V_15 -> V_23 , L_8 , V_17 ) ;
if ( ! V_17 )
break;
V_17 -> V_41 = 0 ;
if ( ! F_15 ( V_34 ) ) {
V_17 -> V_41 = F_16 ( V_34 ) ;
} else {
V_17 -> V_41 =
F_17 ( V_34 , V_37 ) ;
if ( V_17 -> V_41 )
V_17 -> V_42 = V_37 -> V_42 ;
}
F_8 ( V_15 -> V_23 , L_9 ,
V_17 , V_17 -> V_41 ) ;
if ( V_17 -> V_41 ) {
V_17 -> V_43 = 0 ;
V_17 -> V_44 =
F_9 () ;
}
F_18 ( & V_17 -> V_19 ,
& V_34 -> V_45 . V_46 [ V_35 ] . V_17 ) ;
if ( ! V_34 -> V_45 . V_46 [ V_35 ] . V_47 )
V_34 -> V_45 . V_46 [ V_35 ] . V_47 = V_17 ;
}
}
static void F_19 ( struct V_33 * V_34 )
{
V_34 -> V_45 . V_48 [ 0 ] = V_49 ;
V_34 -> V_45 . V_48 [ 1 ] = V_50 ;
V_34 -> V_45 . V_48 [ 2 ] = V_51 ;
V_34 -> V_45 . V_48 [ 3 ] = V_52 ;
}
static void
F_20 ( struct V_53 * V_45 )
{
T_1 * V_48 = V_45 -> V_48 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 4 ; ++ V_35 ) {
V_54 [ 7 - ( V_35 * 2 ) ] = V_55 [ V_48 [ V_35 ] ] [ 1 ] ;
V_54 [ 6 - ( V_35 * 2 ) ] = V_55 [ V_48 [ V_35 ] ] [ 0 ] ;
}
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 )
V_56 [ V_54 [ V_35 ] ] = ( T_1 ) V_35 ;
F_21 ( & V_45 -> V_57 , V_58 ) ;
}
void
F_22 ( struct V_33 * V_34 ,
struct V_59 * V_60 )
{
T_3 V_61 , V_62 , V_63 [ 4 ] ;
T_2 V_35 , V_64 , V_65 ;
T_1 V_66 ;
if ( ! V_60 || ! V_34 -> V_67 ) {
F_19 ( V_34 ) ;
return;
}
F_8 ( V_34 -> V_15 -> V_23 , L_10
L_11 ,
V_60 -> V_68 . V_69 , V_60 -> V_70 &
V_71 ,
V_60 -> V_72 ) ;
for ( V_65 = 0 ; V_65 < F_23 ( V_60 -> V_73 ) ; V_65 ++ ) {
T_1 V_74 = V_60 -> V_73 [ V_65 ] . V_9 ;
T_1 V_75 = V_60 -> V_73 [ V_65 ] . V_5 ;
V_61 = ( 1 << ( V_74 & V_10 ) ) - 1 ;
V_62 = ( V_61 >> 1 ) + ( V_75 & V_8 ) ;
V_66 = V_4 [ ( V_75 & V_6 ) >> 5 ] ;
V_34 -> V_45 . V_48 [ V_66 ] = V_66 ;
V_63 [ V_66 ] = V_62 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_12 ,
( 1 << ( ( V_74 & V_11 ) >> 4 ) ) - 1 ,
V_61 , V_62 ) ;
F_1 ( & V_60 -> V_73 [ V_65 ] ) ;
}
for ( V_35 = 0 ; V_35 < V_65 ; V_35 ++ ) {
for ( V_64 = 1 ; V_64 < V_65 - V_35 ; V_64 ++ ) {
if ( V_63 [ V_64 - 1 ] > V_63 [ V_64 ] ) {
F_24 ( V_63 [ V_64 - 1 ] , V_63 [ V_64 ] ) ;
F_24 ( V_34 -> V_45 . V_48 [ V_64 - 1 ] ,
V_34 -> V_45 . V_48 [ V_64 ] ) ;
} else if ( V_63 [ V_64 - 1 ] == V_63 [ V_64 ] ) {
if ( V_34 -> V_45 . V_48 [ V_64 - 1 ]
< V_34 -> V_45 . V_48 [ V_64 ] )
F_24 ( V_34 -> V_45 . V_48 [ V_64 - 1 ] ,
V_34 -> V_45 . V_48 [ V_64 ] ) ;
}
}
}
F_20 ( & V_34 -> V_45 ) ;
}
static enum V_76
F_25 ( struct V_33 * V_34 ,
enum V_76 V_77 )
{
int V_78 ;
enum V_76 V_79 ;
struct V_80 * V_81 ;
V_81 = & V_34 -> V_45 . V_81 [ V_77 ] ;
if ( ! V_81 -> V_82 )
return V_77 ;
V_79 = V_52 ;
for ( V_78 = V_52 ; V_78 < V_77 ; V_78 ++ ) {
V_81 = & V_34 -> V_45 . V_81 [ V_78 ] ;
if ( ! V_81 -> V_82 && ! V_81 -> V_83 )
V_79 = (enum V_76 ) V_78 ;
}
return V_79 ;
}
void
F_26 ( struct V_33 * V_34 )
{
int V_84 ;
F_8 ( V_34 -> V_15 -> V_23 , L_13
L_14 ) ;
if ( ! V_34 -> V_67 ) {
for ( V_84 = V_52 ; V_84 <= V_49 ; V_84 ++ )
V_34 -> V_45 . V_85 [ V_84 ] =
(enum V_76 ) V_84 ;
} else {
for ( V_84 = V_52 ; V_84 <= V_49 ; V_84 ++ ) {
V_34 -> V_45 . V_85 [ V_84 ]
= F_25 ( V_34 ,
(enum V_76 ) V_84 ) ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_15 ,
V_84 , V_34 -> V_45 . V_85 [ V_84 ] ) ;
}
}
}
static enum V_76
F_27 ( struct V_14 * V_15 , T_2 V_86 )
{
const enum V_76 V_87 [] = { V_51 ,
V_52 ,
V_52 ,
V_51 ,
V_50 ,
V_50 ,
V_49 ,
V_49
} ;
if ( V_86 >= F_23 ( V_87 ) )
return V_51 ;
return V_87 [ V_86 ] ;
}
static T_1
F_28 ( struct V_33 * V_34 , T_2 V_88 )
{
enum V_76 V_89 , V_90 ;
T_1 V_91 ;
V_89 = F_27 ( V_34 -> V_15 , V_88 ) ;
V_90 = V_34 -> V_45 . V_85 [ V_89 ] ;
V_91 = V_55 [ V_90 ] [ V_88 % 2 ] ;
return V_91 ;
}
void
F_29 ( struct V_14 * V_15 )
{
int V_35 , V_64 ;
struct V_33 * V_34 ;
for ( V_64 = 0 ; V_64 < V_15 -> V_92 ; ++ V_64 ) {
V_34 = V_15 -> V_34 [ V_64 ] ;
if ( ! V_34 )
continue;
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 ) {
V_34 -> V_93 [ V_35 ] . V_94 = V_56 [ V_35 ] ;
V_34 -> V_93 [ V_35 ] . V_95 = V_56 [ V_35 ] ;
V_34 -> V_93 [ V_35 ] . V_96 = V_56 [ V_35 ] ;
V_34 -> V_45 . V_46 [ V_35 ] . V_47 = NULL ;
}
V_34 -> V_93 [ 6 ] . V_94
= V_34 -> V_93 [ 6 ] . V_95
= V_34 -> V_93 [ 6 ] . V_96
= V_97 ;
V_34 -> V_93 [ 7 ] . V_94 = V_34 -> V_93 [ 7 ] . V_95
= V_34 -> V_93 [ 7 ] . V_96
= V_97 ;
V_34 -> V_98 . V_99 = V_100 ;
V_34 -> V_98 . V_101 = V_102 ;
V_34 -> V_98 . V_103 = V_104 ;
F_30 ( V_34 ) ;
F_21 ( & V_34 -> V_45 . V_105 , 0 ) ;
F_21 ( & V_34 -> V_45 . V_57 , V_58 ) ;
}
}
int
F_31 ( struct V_14 * V_15 )
{
int V_35 ;
struct V_33 * V_34 ;
for ( V_35 = 0 ; V_35 < V_15 -> V_92 ; ++ V_35 ) {
V_34 = V_15 -> V_34 [ V_35 ] ;
if ( V_34 && F_32 ( & V_34 -> V_45 . V_105 ) )
return false ;
}
return true ;
}
static void
F_33 ( struct V_33 * V_34 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_106 * V_107 , * V_63 ;
F_34 (&ra_list->skb_head, skb, tmp)
F_35 ( V_15 , V_107 , 0 , - 1 ) ;
}
static void
F_36 ( struct V_33 * V_34 ,
struct V_108 * V_109 )
{
struct V_13 * V_17 ;
F_37 (ra_list, ra_list_head, list)
F_33 ( V_34 , V_17 ) ;
}
static void F_38 ( struct V_33 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_40 ; V_35 ++ )
F_36 ( V_34 , & V_34 -> V_45 . V_46 [ V_35 ] .
V_17 ) ;
F_21 ( & V_34 -> V_45 . V_105 , 0 ) ;
F_21 ( & V_34 -> V_45 . V_57 , V_58 ) ;
}
static void F_39 ( struct V_33 * V_34 )
{
struct V_13 * V_17 , * V_110 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 ) {
F_8 ( V_34 -> V_15 -> V_23 ,
L_16 , V_35 ) ;
F_40 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
F_41 ( & V_17 -> V_19 ) ;
F_42 ( V_17 ) ;
}
F_6 ( & V_34 -> V_45 . V_46 [ V_35 ] . V_17 ) ;
V_34 -> V_45 . V_46 [ V_35 ] . V_47 = NULL ;
}
}
void
F_43 ( struct V_33 * V_34 )
{
unsigned long V_38 ;
F_44 ( V_34 ) ;
F_12 ( & V_34 -> V_45 . V_111 , V_38 ) ;
F_38 ( V_34 ) ;
F_45 ( V_34 ) ;
if ( V_34 -> V_15 -> V_112 . V_113 )
V_34 -> V_15 -> V_112 . V_113 ( V_34 -> V_15 ) ;
F_39 ( V_34 ) ;
memcpy ( V_54 , V_55 , sizeof( V_54 ) ) ;
if ( V_34 -> V_15 -> V_112 . V_114 )
V_34 -> V_15 -> V_112 . V_114 ( V_34 -> V_15 ) ;
F_14 ( & V_34 -> V_45 . V_111 , V_38 ) ;
}
static struct V_13 *
F_46 ( struct V_33 * V_34 , T_1 V_88 ,
T_1 * V_115 )
{
struct V_13 * V_17 ;
F_37 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_115 , V_21 ) )
return V_17 ;
}
return NULL ;
}
static struct V_13 *
F_47 ( struct V_33 * V_34 , T_1 V_88 , T_1 * V_115 )
{
struct V_13 * V_17 ;
V_17 = F_46 ( V_34 , V_88 , V_115 ) ;
if ( V_17 )
return V_17 ;
F_11 ( V_34 , V_115 ) ;
return F_46 ( V_34 , V_88 , V_115 ) ;
}
int
F_48 ( struct V_33 * V_34 ,
struct V_13 * V_17 , int V_116 )
{
struct V_13 * V_117 ;
F_37 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_117 == V_17 )
return true ;
}
return false ;
}
void
F_49 ( struct V_33 * V_34 ,
struct V_106 * V_107 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
T_2 V_88 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_21 ] , V_118 ;
unsigned long V_38 ;
if ( ! V_34 -> V_119 && ! F_50 ( V_107 ) ) {
F_8 ( V_15 -> V_23 , L_17 ) ;
F_35 ( V_15 , V_107 , 0 , - 1 ) ;
return;
}
V_88 = V_107 -> V_120 ;
F_12 ( & V_34 -> V_45 . V_111 , V_38 ) ;
V_118 = F_28 ( V_34 , V_88 ) ;
if ( ! F_15 ( V_34 ) &&
! F_50 ( V_107 ) ) {
if ( ! F_51 ( & V_34 -> V_45 . V_46 [ V_118 ] . V_17 ) )
V_17 = F_52 (
& V_34 -> V_45 . V_46 [ V_118 ] . V_17 ,
struct V_13 , V_19 ) ;
else
V_17 = NULL ;
} else {
memcpy ( V_16 , V_107 -> V_121 , V_21 ) ;
if ( V_16 [ 0 ] & 0x01 || F_50 ( V_107 ) )
memset ( V_16 , 0xff , V_21 ) ;
V_17 = F_47 ( V_34 , V_118 , V_16 ) ;
}
if ( ! V_17 ) {
F_14 ( & V_34 -> V_45 . V_111 , V_38 ) ;
F_35 ( V_15 , V_107 , 0 , - 1 ) ;
return;
}
F_53 ( & V_17 -> V_20 , V_107 ) ;
V_17 -> V_22 += V_107 -> V_122 ;
V_17 -> V_43 ++ ;
F_54 ( & V_34 -> V_45 . V_105 ) ;
if ( F_32 ( & V_34 -> V_45 . V_57 ) <
V_56 [ V_118 ] )
F_21 ( & V_34 -> V_45 . V_57 ,
V_56 [ V_118 ] ) ;
F_14 ( & V_34 -> V_45 . V_111 , V_38 ) ;
}
int F_55 ( struct V_33 * V_34 ,
const struct V_123 * V_124 )
{
T_1 * V_125 = ( T_1 * ) & V_124 -> V_126 . V_127 ;
T_4 V_128 = F_3 ( V_124 -> V_129 ) , V_130 ;
int V_131 = true ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
struct V_59 * V_136 = NULL ;
struct V_80 * V_81 ;
F_8 ( V_34 -> V_15 -> V_23 , L_18 ,
V_128 ) ;
while ( ( V_128 >= sizeof( V_133 -> V_137 ) ) && V_131 ) {
V_133 = (struct V_132 * ) V_125 ;
V_130 = F_3 ( V_133 -> V_137 . V_122 ) ;
switch ( F_3 ( V_133 -> V_137 . type ) ) {
case V_138 :
V_135 =
(struct V_134 * )
V_133 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_19
L_20 ,
V_135 -> V_139 ,
V_135 -> V_83 ,
V_135 -> V_82 ) ;
V_81 = & V_34 -> V_45 . V_81 [ V_135 ->
V_139 ] ;
V_81 -> V_82 = V_135 -> V_82 ;
V_81 -> V_83 =
V_135 -> V_83 ;
V_81 -> V_140 = V_135 -> V_140 ;
break;
case V_141 :
V_136 =
(struct V_59 * ) ( V_125 +
2 ) ;
V_136 -> V_68 . V_122 = ( T_1 ) V_130 ;
V_136 -> V_68 . V_142 =
V_141 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_19
L_21 ,
V_136 -> V_70 &
V_71 ) ;
memcpy ( ( T_1 * ) & V_34 -> V_143 . V_144 .
V_60 , V_136 ,
V_136 -> V_68 . V_122 + 2 ) ;
break;
default:
V_131 = false ;
break;
}
V_125 += ( V_130 + sizeof( V_133 -> V_137 ) ) ;
V_128 -= ( V_130 + sizeof( V_133 -> V_137 ) ) ;
}
F_22 ( V_34 , V_136 ) ;
F_26 ( V_34 ) ;
return 0 ;
}
T_2
F_56 ( struct V_33 * V_34 ,
T_1 * * V_145 ,
struct V_59 * V_60 ,
struct V_146 * V_147 )
{
struct V_148 * V_149 ;
T_2 V_150 = 0 ;
if ( ! V_145 )
return 0 ;
if ( ! ( * V_145 ) )
return 0 ;
if ( ! V_60 )
return 0 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_22 ,
V_60 -> V_68 . V_142 ) ;
if ( ( V_34 -> V_151 ||
( V_147 && ( V_34 -> V_15 -> V_152 & V_153 ||
V_34 -> V_15 -> V_152 & V_154 ) ) ) &&
V_60 -> V_68 . V_142 == V_141 ) {
V_149 = (struct V_148 * ) * V_145 ;
V_149 -> V_137 . type = F_57 ( ( T_3 ) V_155 [ 0 ] ) ;
V_149 -> V_137 . V_122 = F_57 ( ( T_3 ) V_155 [ 1 ] ) ;
memcpy ( V_149 -> V_60 , & V_155 [ 2 ] ,
F_3 ( V_149 -> V_137 . V_122 ) ) ;
if ( V_60 -> V_70 & V_156 )
memcpy ( ( T_1 * ) ( V_149 -> V_60
+ F_3 ( V_149 -> V_137 . V_122 )
- sizeof( V_34 -> V_157 ) ) ,
& V_34 -> V_157 , sizeof( V_34 -> V_157 ) ) ;
V_150 = sizeof( V_149 -> V_137 )
+ F_3 ( V_149 -> V_137 . V_122 ) ;
* V_145 += V_150 ;
}
return V_150 ;
}
T_1
F_58 ( struct V_33 * V_34 ,
const struct V_106 * V_107 )
{
T_1 V_158 ;
struct V_26 V_159 , V_160 ;
T_2 V_161 ;
F_10 ( & V_159 ) ;
V_160 = F_59 ( V_107 -> V_162 ) ;
V_161 = ( V_159 . V_29 - V_160 . V_29 ) * 1000 ;
V_161 += ( V_159 . V_30 - V_160 . V_30 ) / 1000 ;
V_158 = ( T_1 ) ( F_60 ( V_161 , V_34 -> V_45 . V_163 ) >> 1 ) ;
F_8 ( V_34 -> V_15 -> V_23 , L_23
L_24 , V_161 , V_158 ) ;
return V_158 ;
}
static struct V_13 *
F_61 ( struct V_14 * V_15 ,
struct V_33 * * V_34 , int * V_88 )
{
struct V_33 * V_164 ;
struct V_13 * V_165 , * V_166 ;
struct V_167 * V_168 , * V_169 ;
struct V_170 * V_171 ;
T_5 * V_172 ;
int V_173 ;
unsigned long V_38 ;
int V_35 , V_64 ;
for ( V_64 = V_15 -> V_92 - 1 ; V_64 >= 0 ; -- V_64 ) {
F_12 ( & V_15 -> V_174 [ V_64 ] . V_175 ,
V_38 ) ;
V_173 = F_51 ( & V_15 -> V_174 [ V_64 ]
. V_176 ) ;
F_14 ( & V_15 -> V_174 [ V_64 ] . V_175 ,
V_38 ) ;
if ( V_173 )
continue;
if ( V_15 -> V_174 [ V_64 ] . V_177 ==
(struct V_167 * )
& V_15 -> V_174 [ V_64 ] . V_176 ) {
V_15 -> V_174 [ V_64 ] . V_177 =
F_52 ( & V_15 -> V_174 [ V_64 ]
. V_176 ,
struct V_167 ,
V_19 ) ;
}
V_168 = V_15 -> V_174 [ V_64 ] . V_177 ;
V_169 = V_168 ;
do {
V_164 = V_168 -> V_34 ;
V_172 = & V_164 -> V_45 . V_57 ;
for ( V_35 = F_32 ( V_172 ) ; V_35 >= V_178 ; -- V_35 ) {
V_171 = & ( V_164 ) -> V_45 .
V_46 [ V_54 [ V_35 ] ] ;
if ( ! V_171 -> V_47 )
continue;
F_12 ( & V_171 -> V_179 ,
V_38 ) ;
V_173 =
F_51 ( & V_15 -> V_174 [ V_64 ]
. V_176 ) ;
F_14 ( & V_171 -> V_179 ,
V_38 ) ;
if ( V_173 )
continue;
V_165 = F_52 (
& V_171 -> V_47 -> V_19 ,
struct V_13 ,
V_19 ) ;
V_166 = V_165 ;
if ( V_165 == (struct V_13 * )
& V_171 -> V_17 ) {
V_165 = F_52 ( & V_165 -> V_19 ,
struct V_13 , V_19 ) ;
V_166 = V_165 ;
}
do {
V_173 =
F_62 ( & V_165 -> V_20 ) ;
if ( ! V_173 )
goto V_180;
V_165 = F_52 ( & V_165 -> V_19 ,
struct V_13 ,
V_19 ) ;
if ( V_165 ==
(struct V_13 * )
& V_171 -> V_17 )
V_165 = F_52 (
& V_165 -> V_19 ,
struct V_13 ,
V_19 ) ;
} while ( V_165 != V_166 );
}
F_21 ( V_172 , V_181 ) ;
V_168 = F_52 ( & V_168 -> V_19 ,
struct V_167 ,
V_19 ) ;
if ( V_168 ==
(struct V_167 * )
& V_15 -> V_174 [ V_64 ] . V_176 )
V_168 = F_52 (
& V_168 -> V_19 ,
struct V_167 ,
V_19 ) ;
} while ( V_168 != V_169 );
}
return NULL ;
V_180:
F_12 ( & V_164 -> V_45 . V_111 , V_38 ) ;
if ( F_32 ( V_172 ) > V_35 )
F_21 ( V_172 , V_35 ) ;
F_14 ( & V_164 -> V_45 . V_111 , V_38 ) ;
* V_34 = V_164 ;
* V_88 = V_54 [ V_35 ] ;
return V_165 ;
}
static int
F_63 ( struct V_33 * V_34 ,
struct V_13 * V_165 ,
int V_182 )
{
int V_183 = 0 , V_184 = 0 ;
struct V_106 * V_107 , * V_63 ;
int V_185 ;
if ( V_34 -> V_186 == V_187 && V_34 -> V_188 &&
V_165 -> V_41 )
V_185 = F_64 ( int , V_165 -> V_42 , V_182 ) ;
else
V_185 = V_182 ;
F_34 (&ptr->skb_head, skb, tmp) {
V_184 += V_107 -> V_122 ;
if ( V_184 >= V_185 )
break;
if ( ++ V_183 >= V_189 )
return true ;
}
return false ;
}
static void
F_65 ( struct V_33 * V_34 ,
struct V_13 * V_165 , int V_116 ,
unsigned long V_190 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_66 ( struct V_33 * V_34 ,
struct V_13 * V_165 )
{
struct V_106 * V_107 ;
struct V_191 * V_192 ;
if ( F_62 ( & V_165 -> V_20 ) )
return false ;
V_107 = F_67 ( & V_165 -> V_20 ) ;
V_192 = F_68 ( V_107 ) ;
if ( V_192 -> V_38 & V_193 )
return true ;
return false ;
}
static void
F_69 ( struct V_33 * V_34 ,
struct V_13 * V_165 , int V_116 ,
unsigned long V_190 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_70 ( struct V_14 * V_15 )
{
struct V_13 * V_165 ;
struct V_33 * V_34 = NULL ;
int V_116 = 0 ;
T_1 V_16 [ V_21 ] ;
int V_194 = 0 , V_88 = 0 ;
unsigned long V_38 ;
V_165 = F_61 ( V_15 , & V_34 , & V_116 ) ;
if ( ! V_165 )
return - 1 ;
V_88 = F_71 ( V_165 ) ;
F_8 ( V_15 -> V_23 , L_25 , V_88 ) ;
F_12 ( & V_34 -> V_45 . V_111 , V_38 ) ;
if ( ! F_48 ( V_34 , V_165 , V_116 ) ) {
F_14 ( & V_34 -> V_45 . V_111 , V_38 ) ;
return - 1 ;
}
if ( F_66 ( V_34 , V_165 ) ) {
F_69 ( V_34 , V_165 , V_116 , V_38 ) ;
return 0 ;
}
if ( ! V_165 -> V_41 ||
F_72 ( V_34 , V_165 , V_88 ) ||
V_34 -> V_195 . V_196 ||
( ( V_34 -> V_197 . V_198 ||
V_34 -> V_197 . V_199 ) &&
! V_34 -> V_200 ) ) {
F_65 ( V_34 , V_165 , V_116 , V_38 ) ;
} else {
if ( F_73 ( V_34 , V_88 ) &&
V_165 -> V_43 > V_165 -> V_44 ) {
if ( F_74 ( V_15 ) ) {
F_75 ( V_34 , V_165 -> V_16 , V_88 ,
V_201 ) ;
F_76 ( V_34 , V_88 , V_165 -> V_16 ) ;
} else if ( F_77
( V_34 , V_88 , & V_194 , V_16 ) ) {
F_75 ( V_34 , V_165 -> V_16 , V_88 ,
V_201 ) ;
F_78 ( V_34 , V_194 , V_16 , 1 ) ;
}
}
if ( F_79 ( V_34 , V_88 ) &&
F_63 ( V_34 , V_165 ,
V_15 -> V_202 ) )
F_80 ( V_34 , V_165 , V_203 ,
V_116 , V_38 ) ;
else
F_65 ( V_34 , V_165 , V_116 , V_38 ) ;
}
return 0 ;
}
void
F_81 ( struct V_14 * V_15 )
{
do {
if ( V_15 -> V_204 || V_15 -> V_205 )
break;
if ( F_70 ( V_15 ) )
break;
} while ( ! F_31 ( V_15 ) );
}
