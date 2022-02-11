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
T_1 V_59 = V_45 -> V_58 [ V_50 ] . V_9 ;
T_1 V_60 = V_45 -> V_58 [ V_50 ] . V_5 ;
V_46 = ( 1 << ( V_59 & V_10 ) ) - 1 ;
V_47 = ( V_46 >> 1 ) + ( V_60 & V_8 ) ;
V_51 = V_4 [ ( V_60 & V_6 ) >> 5 ] ;
V_26 -> V_30 . V_33 [ V_51 ] = V_51 ;
V_48 [ V_51 ] = V_47 ;
F_9 ( V_26 -> V_15 -> V_19 ,
L_13 ,
( 1 << ( ( V_59 & V_11 ) >> 4 ) ) - 1 ,
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
static enum V_61
F_20 ( struct V_25 * V_26 ,
enum V_61 V_62 )
{
int V_63 ;
enum V_61 V_64 ;
struct V_65 * V_66 ;
V_66 = & V_26 -> V_30 . V_66 [ V_62 ] ;
if ( ! V_66 -> V_67 )
return V_62 ;
V_64 = V_37 ;
for ( V_63 = V_37 ; V_63 < V_62 ; V_63 ++ ) {
V_66 = & V_26 -> V_30 . V_66 [ V_63 ] ;
if ( ! V_66 -> V_67 && ! V_66 -> V_68 )
V_64 = (enum V_61 ) V_63 ;
}
return V_64 ;
}
void
F_21 ( struct V_25 * V_26 )
{
int V_69 ;
F_9 ( V_26 -> V_15 -> V_19 , L_14
L_15 ) ;
if ( ! V_26 -> V_52 ) {
for ( V_69 = V_37 ; V_69 <= V_34 ; V_69 ++ )
V_26 -> V_30 . V_70 [ V_69 ] =
(enum V_61 ) V_69 ;
} else {
for ( V_69 = V_37 ; V_69 <= V_34 ; V_69 ++ ) {
V_26 -> V_30 . V_70 [ V_69 ]
= F_20 ( V_26 ,
(enum V_61 ) V_69 ) ;
F_9 ( V_26 -> V_15 -> V_19 ,
L_16 ,
V_69 , V_26 -> V_30 . V_70 [ V_69 ] ) ;
}
}
}
static enum V_61
F_22 ( struct V_14 * V_15 , T_3 V_71 )
{
const enum V_61 V_72 [] = { V_36 ,
V_37 ,
V_37 ,
V_36 ,
V_35 ,
V_35 ,
V_34 ,
V_34
} ;
if ( V_71 >= F_18 ( V_72 ) )
return V_36 ;
return V_72 [ V_71 ] ;
}
static T_1
F_23 ( struct V_25 * V_26 , T_3 V_73 )
{
enum V_61 V_74 , V_75 ;
T_1 V_76 ;
V_74 = F_22 ( V_26 -> V_15 , V_73 ) ;
V_75 = V_26 -> V_30 . V_70 [ V_74 ] ;
V_76 = V_40 [ V_75 ] [ V_73 % 2 ] ;
return V_76 ;
}
void
F_24 ( struct V_14 * V_15 )
{
int V_27 , V_49 ;
struct V_25 * V_26 ;
for ( V_49 = 0 ; V_49 < V_15 -> V_77 ; ++ V_49 ) {
V_26 = V_15 -> V_26 [ V_49 ] ;
if ( ! V_26 )
continue;
for ( V_27 = 0 ; V_27 < V_28 ; ++ V_27 ) {
V_26 -> V_78 [ V_27 ] . V_79 = V_41 [ V_27 ] ;
V_26 -> V_78 [ V_27 ] . V_80 = V_41 [ V_27 ] ;
V_26 -> V_78 [ V_27 ] . V_81 = V_41 [ V_27 ] ;
V_26 -> V_30 . V_31 [ V_27 ] . V_32 = NULL ;
}
V_26 -> V_78 [ 6 ] . V_79
= V_26 -> V_78 [ 6 ] . V_80
= V_26 -> V_78 [ 6 ] . V_81
= V_82 ;
V_26 -> V_78 [ 7 ] . V_79 = V_26 -> V_78 [ 7 ] . V_80
= V_26 -> V_78 [ 7 ] . V_81
= V_82 ;
V_26 -> V_83 . V_84 = V_85 ;
V_26 -> V_83 . V_86 = V_87 ;
V_26 -> V_83 . V_88 = V_89 ;
F_16 ( & V_26 -> V_30 . V_90 , 0 ) ;
F_16 ( & V_26 -> V_30 . V_42 , V_43 ) ;
}
}
int
F_25 ( struct V_14 * V_15 )
{
int V_27 ;
struct V_25 * V_26 ;
for ( V_27 = 0 ; V_27 < V_15 -> V_77 ; ++ V_27 ) {
V_26 = V_15 -> V_26 [ V_27 ] ;
if ( V_26 && F_26 ( & V_26 -> V_30 . V_90 ) )
return false ;
}
return true ;
}
static void
F_27 ( struct V_25 * V_26 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_26 -> V_15 ;
struct V_91 * V_92 , * V_48 ;
F_28 (&ra_list->skb_head, skb, tmp)
F_29 ( V_15 , V_92 , - 1 ) ;
}
static void
F_30 ( struct V_25 * V_26 ,
struct V_93 * V_94 )
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
F_16 ( & V_26 -> V_30 . V_90 , 0 ) ;
F_16 ( & V_26 -> V_30 . V_42 , V_43 ) ;
}
static void F_33 ( struct V_25 * V_26 )
{
struct V_13 * V_17 , * V_95 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; ++ V_27 ) {
F_9 ( V_26 -> V_15 -> V_19 ,
L_17 , V_27 ) ;
F_34 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
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
unsigned long V_96 ;
F_38 ( V_26 ) ;
F_39 ( & V_26 -> V_30 . V_97 , V_96 ) ;
F_32 ( V_26 ) ;
F_40 ( V_26 ) ;
if ( V_26 -> V_15 -> V_98 . V_99 )
V_26 -> V_15 -> V_98 . V_99 ( V_26 -> V_15 ) ;
F_33 ( V_26 ) ;
memcpy ( V_39 , V_40 , sizeof( V_39 ) ) ;
F_41 ( & V_26 -> V_30 . V_97 , V_96 ) ;
}
static struct V_13 *
F_42 ( struct V_25 * V_26 , T_1 V_73 ,
T_1 * V_100 )
{
struct V_13 * V_17 ;
F_31 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_100 , V_23 ) )
return V_17 ;
}
return NULL ;
}
static struct V_13 *
F_43 ( struct V_25 * V_26 , T_1 V_73 , T_1 * V_100 )
{
struct V_13 * V_17 ;
V_17 = F_42 ( V_26 , V_73 , V_100 ) ;
if ( V_17 )
return V_17 ;
F_10 ( V_26 , V_100 ) ;
return F_42 ( V_26 , V_73 , V_100 ) ;
}
int
F_44 ( struct V_25 * V_26 ,
struct V_13 * V_17 , int V_101 )
{
struct V_13 * V_102 ;
F_31 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_102 == V_17 )
return true ;
}
return false ;
}
void
F_45 ( struct V_25 * V_26 ,
struct V_91 * V_92 )
{
struct V_14 * V_15 = V_26 -> V_15 ;
T_3 V_73 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_23 ] , V_103 ;
unsigned long V_96 ;
if ( ! V_26 -> V_104 ) {
F_9 ( V_15 -> V_19 , L_18 ) ;
F_29 ( V_15 , V_92 , - 1 ) ;
return;
}
V_73 = V_92 -> V_105 ;
F_39 ( & V_26 -> V_30 . V_97 , V_96 ) ;
V_103 = F_23 ( V_26 , V_73 ) ;
if ( ! F_11 ( V_26 ) ) {
if ( ! F_46 ( & V_26 -> V_30 . V_31 [ V_103 ] . V_17 ) )
V_17 = F_47 (
& V_26 -> V_30 . V_31 [ V_103 ] . V_17 ,
struct V_13 , V_21 ) ;
else
V_17 = NULL ;
} else {
memcpy ( V_16 , V_92 -> V_106 , V_23 ) ;
if ( V_16 [ 0 ] & 0x01 )
memset ( V_16 , 0xff , V_23 ) ;
V_17 = F_43 ( V_26 , V_103 , V_16 ) ;
}
if ( ! V_17 ) {
F_41 ( & V_26 -> V_30 . V_97 , V_96 ) ;
F_29 ( V_15 , V_92 , - 1 ) ;
return;
}
F_48 ( & V_17 -> V_22 , V_92 ) ;
V_17 -> V_24 += V_92 -> V_107 ;
F_49 ( & V_26 -> V_30 . V_90 ) ;
if ( F_26 ( & V_26 -> V_30 . V_42 ) <
V_41 [ V_103 ] )
F_16 ( & V_26 -> V_30 . V_42 ,
V_41 [ V_103 ] ) ;
F_41 ( & V_26 -> V_30 . V_97 , V_96 ) ;
}
int F_50 ( struct V_25 * V_26 ,
const struct V_108 * V_109 )
{
T_1 * V_110 = ( T_1 * ) & V_109 -> V_111 . V_112 ;
T_4 V_113 = F_3 ( V_109 -> V_114 ) , V_115 ;
int V_116 = true ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_44 * V_121 = NULL ;
struct V_65 * V_66 ;
F_9 ( V_26 -> V_15 -> V_19 , L_19 ,
V_113 ) ;
while ( ( V_113 >= sizeof( V_118 -> V_122 ) ) && V_116 ) {
V_118 = (struct V_117 * ) V_110 ;
V_115 = F_3 ( V_118 -> V_122 . V_107 ) ;
switch ( F_3 ( V_118 -> V_122 . type ) ) {
case V_123 :
V_120 =
(struct V_119 * )
V_118 ;
F_9 ( V_26 -> V_15 -> V_19 ,
L_20
L_21 ,
V_120 -> V_124 ,
V_120 -> V_68 ,
V_120 -> V_67 ) ;
V_66 = & V_26 -> V_30 . V_66 [ V_120 ->
V_124 ] ;
V_66 -> V_67 = V_120 -> V_67 ;
V_66 -> V_68 =
V_120 -> V_68 ;
V_66 -> V_125 = V_120 -> V_125 ;
break;
case V_126 :
V_121 =
(struct V_44 * ) ( V_110 +
2 ) ;
V_121 -> V_53 . V_107 = ( T_1 ) V_115 ;
V_121 -> V_53 . V_127 =
V_126 ;
F_9 ( V_26 -> V_15 -> V_19 ,
L_20
L_22 ,
V_121 -> V_55 &
V_56 ) ;
memcpy ( ( T_1 * ) & V_26 -> V_128 . V_129 .
V_45 , V_121 ,
V_121 -> V_53 . V_107 + 2 ) ;
break;
default:
V_116 = false ;
break;
}
V_110 += ( V_115 + sizeof( V_118 -> V_122 ) ) ;
V_113 -= ( V_115 + sizeof( V_118 -> V_122 ) ) ;
}
F_17 ( V_26 , V_121 ) ;
F_21 ( V_26 ) ;
return 0 ;
}
T_3
F_51 ( struct V_25 * V_26 ,
T_1 * * V_130 ,
struct V_44 * V_45 ,
struct V_131 * V_132 )
{
struct V_133 * V_134 ;
T_3 V_135 = 0 ;
if ( ! V_130 )
return 0 ;
if ( ! ( * V_130 ) )
return 0 ;
if ( ! V_45 )
return 0 ;
F_9 ( V_26 -> V_15 -> V_19 ,
L_23 ,
V_45 -> V_53 . V_127 ) ;
if ( ( V_26 -> V_136 ||
( V_132 && ( V_26 -> V_15 -> V_137 & V_138 ||
V_26 -> V_15 -> V_137 & V_139 ) ) ) &&
V_45 -> V_53 . V_127 == V_126 ) {
V_134 = (struct V_133 * ) * V_130 ;
V_134 -> V_122 . type = F_52 ( ( T_2 ) V_140 [ 0 ] ) ;
V_134 -> V_122 . V_107 = F_52 ( ( T_2 ) V_140 [ 1 ] ) ;
memcpy ( V_134 -> V_45 , & V_140 [ 2 ] ,
F_3 ( V_134 -> V_122 . V_107 ) ) ;
if ( V_45 -> V_55 & V_141 )
memcpy ( ( T_1 * ) ( V_134 -> V_45
+ F_3 ( V_134 -> V_122 . V_107 )
- sizeof( V_26 -> V_142 ) ) ,
& V_26 -> V_142 , sizeof( V_26 -> V_142 ) ) ;
V_135 = sizeof( V_134 -> V_122 )
+ F_3 ( V_134 -> V_122 . V_107 ) ;
* V_130 += V_135 ;
}
return V_135 ;
}
T_1
F_53 ( struct V_25 * V_26 ,
const struct V_91 * V_92 )
{
T_1 V_143 ;
struct V_144 V_145 , V_146 ;
T_3 V_147 ;
F_54 ( & V_145 ) ;
V_146 = F_55 ( V_92 -> V_148 ) ;
V_147 = ( V_145 . V_149 - V_146 . V_149 ) * 1000 ;
V_147 += ( V_145 . V_150 - V_146 . V_150 ) / 1000 ;
V_143 = ( T_1 ) ( F_56 ( V_147 , V_26 -> V_30 . V_151 ) >> 1 ) ;
F_9 ( V_26 -> V_15 -> V_19 , L_24
L_25 , V_147 , V_143 ) ;
return V_143 ;
}
static struct V_13 *
F_57 ( struct V_14 * V_15 ,
struct V_25 * * V_26 , int * V_73 )
{
struct V_25 * V_152 ;
struct V_13 * V_153 , * V_154 ;
struct V_155 * V_156 , * V_157 ;
struct V_158 * V_159 ;
T_5 * V_160 ;
int V_161 ;
unsigned long V_96 ;
int V_27 , V_49 ;
for ( V_49 = V_15 -> V_77 - 1 ; V_49 >= 0 ; -- V_49 ) {
F_39 ( & V_15 -> V_162 [ V_49 ] . V_163 ,
V_96 ) ;
V_161 = F_46 ( & V_15 -> V_162 [ V_49 ]
. V_164 ) ;
F_41 ( & V_15 -> V_162 [ V_49 ] . V_163 ,
V_96 ) ;
if ( V_161 )
continue;
if ( V_15 -> V_162 [ V_49 ] . V_165 ==
(struct V_155 * )
& V_15 -> V_162 [ V_49 ] . V_164 ) {
V_156 =
F_47 ( & V_15 -> V_162 [ V_49 ]
. V_164 ,
struct V_155 ,
V_21 ) ;
V_157 = V_156 ;
} else {
V_156 = V_15 -> V_162 [ V_49 ] . V_165 ;
V_157 = V_156 ;
}
do {
V_152 = V_156 -> V_26 ;
V_160 = & V_152 -> V_30 . V_42 ;
for ( V_27 = F_26 ( V_160 ) ; V_27 >= V_166 ; -- V_27 ) {
V_159 = & ( V_152 ) -> V_30 .
V_31 [ V_39 [ V_27 ] ] ;
F_39 ( & V_159 -> V_167 ,
V_96 ) ;
V_161 =
F_46 ( & V_15 -> V_162 [ V_49 ]
. V_164 ) ;
F_41 ( & V_159 -> V_167 ,
V_96 ) ;
if ( V_161 )
continue;
V_153 = F_47 (
& V_159 -> V_32 -> V_21 ,
struct V_13 ,
V_21 ) ;
V_154 = V_153 ;
if ( V_153 == (struct V_13 * )
& V_159 -> V_17 ) {
V_153 = F_47 ( & V_153 -> V_21 ,
struct V_13 , V_21 ) ;
V_154 = V_153 ;
}
do {
V_161 =
F_58 ( & V_153 -> V_22 ) ;
if ( ! V_161 )
goto V_168;
V_153 = F_47 ( & V_153 -> V_21 ,
struct V_13 ,
V_21 ) ;
if ( V_153 ==
(struct V_13 * )
& V_159 -> V_17 )
V_153 = F_47 (
& V_153 -> V_21 ,
struct V_13 ,
V_21 ) ;
} while ( V_153 != V_154 );
}
F_16 ( V_160 , V_169 ) ;
V_156 = F_47 ( & V_156 -> V_21 ,
struct V_155 ,
V_21 ) ;
if ( V_156 ==
(struct V_155 * )
& V_15 -> V_162 [ V_49 ] . V_164 )
V_156 = F_47 (
& V_156 -> V_21 ,
struct V_155 ,
V_21 ) ;
} while ( V_156 != V_157 );
}
return NULL ;
V_168:
F_39 ( & V_152 -> V_30 . V_97 , V_96 ) ;
if ( F_26 ( V_160 ) > V_27 )
F_16 ( V_160 , V_27 ) ;
F_41 ( & V_152 -> V_30 . V_97 , V_96 ) ;
* V_26 = V_152 ;
* V_73 = V_39 [ V_27 ] ;
return V_153 ;
}
static int
F_59 ( struct V_25 * V_26 ,
struct V_13 * V_153 ,
int V_170 )
{
int V_171 = 0 , V_172 = 0 ;
struct V_91 * V_92 , * V_48 ;
F_28 (&ptr->skb_head, skb, tmp) {
V_172 += V_92 -> V_107 ;
if ( V_172 >= V_170 )
break;
if ( ++ V_171 >= V_173 )
return true ;
}
return false ;
}
static void
F_60 ( struct V_25 * V_26 ,
struct V_13 * V_153 , int V_101 ,
unsigned long V_174 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_61 ( struct V_25 * V_26 ,
struct V_13 * V_153 )
{
struct V_91 * V_92 ;
struct V_175 * V_176 ;
if ( F_58 ( & V_153 -> V_22 ) )
return false ;
V_92 = F_62 ( & V_153 -> V_22 ) ;
V_176 = F_63 ( V_92 ) ;
if ( V_176 -> V_96 & V_177 )
return true ;
return false ;
}
static void
F_64 ( struct V_25 * V_26 ,
struct V_13 * V_153 , int V_101 ,
unsigned long V_174 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_65 ( struct V_14 * V_15 )
{
struct V_13 * V_153 ;
struct V_25 * V_26 = NULL ;
int V_101 = 0 ;
T_1 V_16 [ V_23 ] ;
int V_178 = 0 , V_73 = 0 ;
unsigned long V_96 ;
V_153 = F_57 ( V_15 , & V_26 , & V_101 ) ;
if ( ! V_153 )
return - 1 ;
V_73 = F_66 ( V_153 ) ;
F_9 ( V_15 -> V_19 , L_26 , V_73 ) ;
F_39 ( & V_26 -> V_30 . V_97 , V_96 ) ;
if ( ! F_44 ( V_26 , V_153 , V_101 ) ) {
F_41 ( & V_26 -> V_30 . V_97 , V_96 ) ;
return - 1 ;
}
if ( F_61 ( V_26 , V_153 ) ) {
F_64 ( V_26 , V_153 , V_101 , V_96 ) ;
return 0 ;
}
if ( ! V_153 -> V_29 ||
F_67 ( V_26 , V_153 , V_73 ) ||
( ( V_26 -> V_179 . V_180 ||
V_26 -> V_179 . V_181 ) &&
! V_26 -> V_182 ) ) {
F_60 ( V_26 , V_153 , V_101 , V_96 ) ;
} else {
if ( F_68 ( V_26 , V_73 ) ) {
if ( F_69 ( V_15 ) ) {
F_70 ( V_26 , V_153 -> V_16 , V_73 ,
V_183 ) ;
F_71 ( V_26 , V_73 , V_153 -> V_16 ) ;
} else if ( F_72
( V_26 , V_73 , & V_178 , V_16 ) ) {
F_70 ( V_26 , V_153 -> V_16 , V_73 ,
V_183 ) ;
F_73 ( V_26 , V_178 , V_16 , 1 ) ;
}
}
if ( F_74 ( V_26 , V_73 ) &&
F_59 ( V_26 , V_153 ,
V_15 -> V_184 ) )
F_75 ( V_26 , V_153 , V_185 ,
V_101 , V_96 ) ;
else
F_60 ( V_26 , V_153 , V_101 , V_96 ) ;
}
return 0 ;
}
void
F_76 ( struct V_14 * V_15 )
{
do {
if ( V_15 -> V_186 || V_15 -> V_187 )
break;
if ( F_65 ( V_15 ) )
break;
} while ( ! F_25 ( V_15 ) );
}
