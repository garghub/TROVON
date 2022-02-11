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
if ( ! F_12 ( V_34 ) ) {
if ( F_13 ( V_34 , V_16 ) ==
V_42 ) {
V_17 -> V_41 = true ;
V_17 -> V_40 =
F_14 ( V_34 , V_16 ) ;
} else {
V_17 -> V_40 = F_15 ( V_34 ) ;
}
} else {
F_16 ( & V_34 -> V_43 , V_38 ) ;
V_37 = F_17 ( V_34 , V_16 ) ;
V_17 -> V_40 =
F_18 ( V_34 , V_37 ) ;
if ( V_17 -> V_40 )
V_17 -> V_44 = V_37 -> V_44 ;
F_19 ( & V_34 -> V_43 , V_38 ) ;
}
F_8 ( V_15 -> V_23 , L_9 ,
V_17 , V_17 -> V_40 ) ;
if ( V_17 -> V_40 ) {
V_17 -> V_45 = 0 ;
V_17 -> V_46 =
F_9 () ;
}
F_20 ( & V_17 -> V_19 ,
& V_34 -> V_47 . V_48 [ V_35 ] . V_17 ) ;
}
}
static void F_21 ( struct V_33 * V_34 )
{
V_34 -> V_47 . V_49 [ 0 ] = V_50 ;
V_34 -> V_47 . V_49 [ 1 ] = V_51 ;
V_34 -> V_47 . V_49 [ 2 ] = V_52 ;
V_34 -> V_47 . V_49 [ 3 ] = V_53 ;
}
static void
F_22 ( struct V_33 * V_34 )
{
struct V_54 * V_47 = & V_34 -> V_47 ;
T_1 * V_49 = V_47 -> V_49 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 4 ; ++ V_35 ) {
V_55 [ 7 - ( V_35 * 2 ) ] = V_56 [ V_49 [ V_35 ] ] [ 1 ] ;
V_55 [ 6 - ( V_35 * 2 ) ] = V_56 [ V_49 [ V_35 ] ] [ 0 ] ;
}
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 )
V_34 -> V_57 [ V_55 [ V_35 ] ] = ( T_1 ) V_35 ;
F_23 ( & V_47 -> V_58 , V_59 ) ;
}
void
F_24 ( struct V_33 * V_34 ,
struct V_60 * V_61 )
{
T_3 V_62 , V_63 , V_64 [ 4 ] ;
T_2 V_35 , V_65 , V_66 ;
T_1 V_67 ;
if ( ! V_61 || ! V_34 -> V_68 ) {
F_21 ( V_34 ) ;
return;
}
F_8 ( V_34 -> V_15 -> V_23 , L_10
L_11 ,
V_61 -> V_69 . V_70 , V_61 -> V_71 &
V_72 ,
V_61 -> V_73 ) ;
for ( V_66 = 0 ; V_66 < F_25 ( V_61 -> V_74 ) ; V_66 ++ ) {
T_1 V_75 = V_61 -> V_74 [ V_66 ] . V_9 ;
T_1 V_76 = V_61 -> V_74 [ V_66 ] . V_5 ;
V_62 = ( 1 << ( V_75 & V_10 ) ) - 1 ;
V_63 = ( V_62 >> 1 ) + ( V_76 & V_8 ) ;
V_67 = V_4 [ ( V_76 & V_6 ) >> 5 ] ;
V_34 -> V_47 . V_49 [ V_67 ] = V_67 ;
V_64 [ V_67 ] = V_63 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_12 ,
( 1 << ( ( V_75 & V_11 ) >> 4 ) ) - 1 ,
V_62 , V_63 ) ;
F_1 ( & V_61 -> V_74 [ V_66 ] ) ;
}
for ( V_35 = 0 ; V_35 < V_66 ; V_35 ++ ) {
for ( V_65 = 1 ; V_65 < V_66 - V_35 ; V_65 ++ ) {
if ( V_64 [ V_65 - 1 ] > V_64 [ V_65 ] ) {
F_26 ( V_64 [ V_65 - 1 ] , V_64 [ V_65 ] ) ;
F_26 ( V_34 -> V_47 . V_49 [ V_65 - 1 ] ,
V_34 -> V_47 . V_49 [ V_65 ] ) ;
} else if ( V_64 [ V_65 - 1 ] == V_64 [ V_65 ] ) {
if ( V_34 -> V_47 . V_49 [ V_65 - 1 ]
< V_34 -> V_47 . V_49 [ V_65 ] )
F_26 ( V_34 -> V_47 . V_49 [ V_65 - 1 ] ,
V_34 -> V_47 . V_49 [ V_65 ] ) ;
}
}
}
F_22 ( V_34 ) ;
}
static enum V_77
F_27 ( struct V_33 * V_34 ,
enum V_77 V_78 )
{
int V_79 ;
enum V_77 V_80 ;
struct V_81 * V_82 ;
V_82 = & V_34 -> V_47 . V_82 [ V_78 ] ;
if ( ! V_82 -> V_83 )
return V_78 ;
V_80 = V_53 ;
for ( V_79 = V_53 ; V_79 < V_78 ; V_79 ++ ) {
V_82 = & V_34 -> V_47 . V_82 [ V_79 ] ;
if ( ! V_82 -> V_83 && ! V_82 -> V_84 )
V_80 = (enum V_77 ) V_79 ;
}
return V_80 ;
}
void
F_28 ( struct V_33 * V_34 )
{
int V_85 ;
F_8 ( V_34 -> V_15 -> V_23 , L_13
L_14 ) ;
if ( ! V_34 -> V_68 ) {
for ( V_85 = V_53 ; V_85 <= V_50 ; V_85 ++ )
V_34 -> V_47 . V_86 [ V_85 ] =
(enum V_77 ) V_85 ;
} else {
for ( V_85 = V_53 ; V_85 <= V_50 ; V_85 ++ ) {
V_34 -> V_47 . V_86 [ V_85 ]
= F_27 ( V_34 ,
(enum V_77 ) V_85 ) ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_15 ,
V_85 , V_34 -> V_47 . V_86 [ V_85 ] ) ;
}
}
}
static enum V_77
F_29 ( struct V_14 * V_15 , T_2 V_87 )
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
if ( V_87 >= F_25 ( V_88 ) )
return V_52 ;
return V_88 [ V_87 ] ;
}
T_1 F_30 ( struct V_33 * V_34 , T_2 V_89 )
{
enum V_77 V_90 , V_91 ;
T_1 V_92 ;
V_90 = F_29 ( V_34 -> V_15 , V_89 ) ;
V_91 = V_34 -> V_47 . V_86 [ V_90 ] ;
V_92 = V_56 [ V_91 ] [ V_89 % 2 ] ;
return V_92 ;
}
void
F_31 ( struct V_14 * V_15 )
{
int V_35 , V_65 ;
struct V_33 * V_34 ;
for ( V_65 = 0 ; V_65 < V_15 -> V_93 ; ++ V_65 ) {
V_34 = V_15 -> V_34 [ V_65 ] ;
if ( ! V_34 )
continue;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
if ( ! V_94 &&
V_15 -> V_95 > V_96 )
V_34 -> V_97 [ V_35 ] . V_98 =
V_34 -> V_57 [ V_35 ] ;
else
V_34 -> V_97 [ V_35 ] . V_98 =
V_99 ;
V_34 -> V_97 [ V_35 ] . V_100 =
V_34 -> V_57 [ V_35 ] ;
V_34 -> V_97 [ V_35 ] . V_101 =
V_34 -> V_57 [ V_35 ] ;
}
F_32 ( V_34 ) ;
F_33 ( V_34 ) ;
F_23 ( & V_34 -> V_47 . V_102 , 0 ) ;
F_23 ( & V_34 -> V_47 . V_58 , V_59 ) ;
}
}
int
F_34 ( struct V_14 * V_15 )
{
int V_35 ;
struct V_33 * V_34 ;
for ( V_35 = 0 ; V_35 < V_15 -> V_93 ; ++ V_35 ) {
V_34 = V_15 -> V_34 [ V_35 ] ;
if ( V_34 && F_35 ( & V_34 -> V_47 . V_102 ) )
return false ;
}
return true ;
}
static void
F_36 ( struct V_33 * V_34 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_103 * V_104 , * V_64 ;
F_37 (&ra_list->skb_head, skb, tmp)
F_38 ( V_15 , V_104 , 0 , - 1 ) ;
}
static void
F_39 ( struct V_33 * V_34 ,
struct V_105 * V_106 )
{
struct V_13 * V_17 ;
F_40 (ra_list, ra_list_head, list)
F_36 ( V_34 , V_17 ) ;
}
static void F_41 ( struct V_33 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_39 ; V_35 ++ )
F_39 ( V_34 , & V_34 -> V_47 . V_48 [ V_35 ] .
V_17 ) ;
F_23 ( & V_34 -> V_47 . V_102 , 0 ) ;
F_23 ( & V_34 -> V_47 . V_58 , V_59 ) ;
}
static void F_42 ( struct V_33 * V_34 )
{
struct V_13 * V_17 , * V_107 ;
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
F_6 ( & V_34 -> V_47 . V_48 [ V_35 ] . V_17 ) ;
}
}
static int F_46 ( int V_108 , void * V_109 , void * V_110 )
{
F_47 ( L_17 ) ;
F_48 ( V_109 ) ;
return 0 ;
}
void
F_49 ( struct V_33 * V_34 )
{
unsigned long V_38 ;
struct V_103 * V_104 , * V_64 ;
F_50 ( V_34 ) ;
F_16 ( & V_34 -> V_47 . V_111 , V_38 ) ;
F_41 ( V_34 ) ;
F_51 ( V_34 ) ;
if ( V_34 -> V_15 -> V_112 . V_113 )
V_34 -> V_15 -> V_112 . V_113 ( V_34 -> V_15 ) ;
F_42 ( V_34 ) ;
memcpy ( V_55 , V_56 , sizeof( V_55 ) ) ;
if ( V_34 -> V_15 -> V_112 . V_114 &&
! V_34 -> V_15 -> V_115 )
V_34 -> V_15 -> V_112 . V_114 ( V_34 -> V_15 ) ;
F_19 ( & V_34 -> V_47 . V_111 , V_38 ) ;
F_37 (&priv->tdls_txq, skb, tmp)
F_38 ( V_34 -> V_15 , V_104 , 0 , - 1 ) ;
F_52 ( & V_34 -> V_116 , F_46 , NULL ) ;
F_53 ( & V_34 -> V_116 ) ;
}
static struct V_13 *
F_54 ( struct V_33 * V_34 , T_1 V_89 ,
const T_1 * V_117 )
{
struct V_13 * V_17 ;
F_40 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_117 , V_21 ) )
return V_17 ;
}
return NULL ;
}
struct V_13 *
F_55 ( struct V_33 * V_34 , T_1 V_89 ,
const T_1 * V_117 )
{
struct V_13 * V_17 ;
V_17 = F_54 ( V_34 , V_89 , V_117 ) ;
if ( V_17 )
return V_17 ;
F_11 ( V_34 , V_117 ) ;
return F_54 ( V_34 , V_89 , V_117 ) ;
}
void
F_56 ( struct V_33 * V_34 , const T_1 * V_117 )
{
struct V_13 * V_17 ;
unsigned long V_38 ;
int V_35 ;
F_16 ( & V_34 -> V_47 . V_111 , V_38 ) ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
V_17 = F_54 ( V_34 , V_35 , V_117 ) ;
if ( ! V_17 )
continue;
F_36 ( V_34 , V_17 ) ;
F_57 ( V_17 -> V_22 , & V_34 -> V_47 . V_102 ) ;
F_44 ( & V_17 -> V_19 ) ;
F_45 ( V_17 ) ;
}
F_19 ( & V_34 -> V_47 . V_111 , V_38 ) ;
}
int
F_58 ( struct V_33 * V_34 ,
struct V_13 * V_17 , int V_118 )
{
struct V_13 * V_119 ;
F_40 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_119 == V_17 )
return true ;
}
return false ;
}
void
F_59 ( struct V_33 * V_34 ,
struct V_103 * V_104 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
T_2 V_89 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_21 ] , V_120 ;
unsigned long V_38 ;
struct V_105 V_105 ;
int V_121 = V_122 ;
struct V_123 * V_124 = (struct V_123 * ) V_104 -> V_110 ;
struct V_125 * V_126 = F_60 ( V_104 ) ;
memcpy ( V_16 , V_124 -> V_127 , V_21 ) ;
if ( F_61 ( V_34 ) == V_128 &&
F_62 ( V_15 -> V_129 ) ) {
if ( F_63 ( V_124 -> V_130 ) == V_131 )
F_8 ( V_15 -> V_23 ,
L_18 , V_16 ) ;
else if ( memcmp ( V_34 -> V_132 , V_16 , V_21 ) )
V_121 = F_13 ( V_34 , V_16 ) ;
}
if ( ! V_34 -> V_133 && ! F_64 ( V_104 ) ) {
F_8 ( V_15 -> V_23 , L_19 ) ;
F_38 ( V_15 , V_104 , 0 , - 1 ) ;
return;
}
V_89 = V_104 -> V_134 ;
F_16 ( & V_34 -> V_47 . V_111 , V_38 ) ;
V_120 = F_30 ( V_34 , V_89 ) ;
if ( ! F_12 ( V_34 ) &&
! F_64 ( V_104 ) ) {
switch ( V_121 ) {
case V_42 :
V_17 = F_55 ( V_34 , V_120 ,
V_16 ) ;
V_126 -> V_38 |= V_135 ;
break;
case V_136 :
F_65 ( & V_34 -> V_137 , V_104 ) ;
F_19 ( & V_34 -> V_47 . V_111 ,
V_38 ) ;
return;
default:
V_105 = V_34 -> V_47 . V_48 [ V_120 ] . V_17 ;
if ( ! F_66 ( & V_105 ) )
V_17 = F_67 (
& V_105 , struct V_13 ,
V_19 ) ;
else
V_17 = NULL ;
break;
}
} else {
memcpy ( V_16 , V_104 -> V_110 , V_21 ) ;
if ( V_16 [ 0 ] & 0x01 || F_64 ( V_104 ) )
memset ( V_16 , 0xff , V_21 ) ;
V_17 = F_55 ( V_34 , V_120 , V_16 ) ;
}
if ( ! V_17 ) {
F_19 ( & V_34 -> V_47 . V_111 , V_38 ) ;
F_38 ( V_15 , V_104 , 0 , - 1 ) ;
return;
}
F_65 ( & V_17 -> V_20 , V_104 ) ;
V_17 -> V_45 ++ ;
V_17 -> V_22 ++ ;
if ( F_35 ( & V_34 -> V_47 . V_58 ) <
V_34 -> V_57 [ V_120 ] )
F_23 ( & V_34 -> V_47 . V_58 ,
V_34 -> V_57 [ V_120 ] ) ;
F_68 ( & V_34 -> V_47 . V_102 ) ;
F_19 ( & V_34 -> V_47 . V_111 , V_38 ) ;
}
int F_69 ( struct V_33 * V_34 ,
const struct V_138 * V_139 )
{
T_1 * V_140 = ( T_1 * ) & V_139 -> V_141 . V_142 ;
T_4 V_143 = F_3 ( V_139 -> V_144 ) , V_145 ;
bool V_146 = true ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
struct V_60 * V_151 = NULL ;
struct V_81 * V_82 ;
F_8 ( V_34 -> V_15 -> V_23 , L_20 ,
V_143 ) ;
while ( ( V_143 >= sizeof( V_148 -> V_152 ) ) && V_146 ) {
V_148 = (struct V_147 * ) V_140 ;
V_145 = F_3 ( V_148 -> V_152 . V_153 ) ;
if ( V_143 < V_145 + sizeof( V_148 -> V_152 ) )
break;
switch ( F_3 ( V_148 -> V_152 . type ) ) {
case V_154 :
V_150 =
(struct V_149 * )
V_148 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_21
L_22 ,
V_150 -> V_155 ,
V_150 -> V_84 ,
V_150 -> V_83 ) ;
V_82 = & V_34 -> V_47 . V_82 [ V_150 ->
V_155 ] ;
V_82 -> V_83 = V_150 -> V_83 ;
V_82 -> V_84 =
V_150 -> V_84 ;
V_82 -> V_156 = V_150 -> V_156 ;
break;
case V_157 :
V_151 =
(struct V_60 * ) ( V_140 +
2 ) ;
V_151 -> V_69 . V_153 = ( T_1 ) V_145 ;
V_151 -> V_69 . V_158 =
V_157 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_21
L_23 ,
V_151 -> V_71 &
V_72 ) ;
memcpy ( ( T_1 * ) & V_34 -> V_159 . V_160 .
V_61 , V_151 ,
V_151 -> V_69 . V_153 + 2 ) ;
break;
default:
V_146 = false ;
break;
}
V_140 += ( V_145 + sizeof( V_148 -> V_152 ) ) ;
V_143 -= ( V_145 + sizeof( V_148 -> V_152 ) ) ;
}
F_24 ( V_34 , V_151 ) ;
F_28 ( V_34 ) ;
return 0 ;
}
T_2
F_70 ( struct V_33 * V_34 ,
T_1 * * V_161 ,
struct V_60 * V_61 ,
struct V_162 * V_163 )
{
struct V_164 * V_165 ;
T_2 V_166 = 0 ;
if ( ! V_161 )
return 0 ;
if ( ! ( * V_161 ) )
return 0 ;
if ( ! V_61 )
return 0 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_24 ,
V_61 -> V_69 . V_158 ) ;
if ( ( V_34 -> V_167 ||
( V_163 && ( V_34 -> V_15 -> V_168 & V_169 ||
V_34 -> V_15 -> V_168 & V_170 ) ) ) &&
V_61 -> V_69 . V_158 == V_157 ) {
V_165 = (struct V_164 * ) * V_161 ;
V_165 -> V_152 . type = F_71 ( ( T_3 ) V_171 [ 0 ] ) ;
V_165 -> V_152 . V_153 = F_71 ( ( T_3 ) V_171 [ 1 ] ) ;
memcpy ( V_165 -> V_61 , & V_171 [ 2 ] ,
F_3 ( V_165 -> V_152 . V_153 ) ) ;
if ( V_61 -> V_71 & V_172 )
memcpy ( ( T_1 * ) ( V_165 -> V_61
+ F_3 ( V_165 -> V_152 . V_153 )
- sizeof( V_34 -> V_173 ) ) ,
& V_34 -> V_173 , sizeof( V_34 -> V_173 ) ) ;
V_166 = sizeof( V_165 -> V_152 )
+ F_3 ( V_165 -> V_152 . V_153 ) ;
* V_161 += V_166 ;
}
return V_166 ;
}
T_1
F_72 ( struct V_33 * V_34 ,
const struct V_103 * V_104 )
{
T_2 V_174 = F_73 ( F_74 ( V_104 -> V_175 ) ) ;
T_1 V_176 ;
V_176 = ( T_1 ) ( F_75 ( V_174 , V_34 -> V_47 . V_177 ) >> 1 ) ;
F_8 ( V_34 -> V_15 -> V_23 , L_25
L_26 , V_174 , V_176 ) ;
return V_176 ;
}
static struct V_13 *
F_76 ( struct V_14 * V_15 ,
struct V_33 * * V_34 , int * V_89 )
{
struct V_33 * V_178 ;
struct V_13 * V_179 ;
struct V_180 * V_181 ;
T_5 * V_182 ;
unsigned long V_183 , V_184 ;
int V_35 , V_65 ;
for ( V_65 = V_15 -> V_93 - 1 ; V_65 >= 0 ; -- V_65 ) {
F_16 ( & V_15 -> V_185 [ V_65 ] . V_186 ,
V_183 ) ;
F_40 (adapter->bss_prio_tbl[j].bss_prio_cur,
&adapter->bss_prio_tbl[j].bss_prio_head,
list) {
V_178 = V_15 -> V_185 [ V_65 ] . V_187 -> V_34 ;
if ( F_35 ( & V_178 -> V_47 . V_102 ) == 0 )
continue;
V_182 = & V_178 -> V_47 . V_58 ;
for ( V_35 = F_35 ( V_182 ) ; V_35 >= V_188 ; -- V_35 ) {
F_16 ( & V_178 -> V_47 .
V_111 , V_184 ) ;
V_181 = & ( V_178 ) -> V_47 .
V_48 [ V_55 [ V_35 ] ] ;
F_40 (ptr, &tid_ptr->ra_list,
list) {
if ( ! F_77 ( & V_179 -> V_20 ) )
goto V_189;
}
F_19 ( & V_178 -> V_47 .
V_111 ,
V_184 ) ;
}
}
F_19 ( & V_15 -> V_185 [ V_65 ] . V_186 ,
V_183 ) ;
}
return NULL ;
V_189:
if ( F_35 ( V_182 ) > V_35 )
F_23 ( V_182 , V_35 ) ;
F_19 ( & V_178 -> V_47 . V_111 , V_184 ) ;
F_19 ( & V_15 -> V_185 [ V_65 ] . V_186 ,
V_183 ) ;
* V_34 = V_178 ;
* V_89 = V_55 [ V_35 ] ;
return V_179 ;
}
void F_78 ( struct V_33 * V_34 ,
struct V_13 * V_16 ,
int V_89 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_190 * V_191 = V_15 -> V_185 ;
struct V_180 * V_181 = & V_34 -> V_47 . V_48 [ V_89 ] ;
unsigned long V_38 ;
F_16 ( & V_191 [ V_34 -> V_192 ] . V_186 , V_38 ) ;
F_79 ( & V_191 [ V_34 -> V_192 ] . V_193 ,
& V_191 [ V_34 -> V_192 ] . V_187 -> V_19 ) ;
F_19 ( & V_191 [ V_34 -> V_192 ] . V_186 , V_38 ) ;
F_16 ( & V_34 -> V_47 . V_111 , V_38 ) ;
if ( F_58 ( V_34 , V_16 , V_89 ) ) {
V_34 -> V_47 . V_194 [ V_89 ] ++ ;
F_79 ( & V_181 -> V_17 , & V_16 -> V_19 ) ;
}
F_19 ( & V_34 -> V_47 . V_111 , V_38 ) ;
}
static int
F_80 ( struct V_33 * V_34 ,
struct V_13 * V_179 ,
int V_195 )
{
int V_196 = 0 , V_197 = 0 ;
struct V_103 * V_104 , * V_64 ;
int V_198 ;
if ( V_34 -> V_199 == V_200 && V_34 -> V_201 &&
V_179 -> V_40 )
V_198 = F_81 ( int , V_179 -> V_44 , V_195 ) ;
else
V_198 = V_195 ;
F_37 (&ptr->skb_head, skb, tmp) {
V_197 += V_104 -> V_153 ;
if ( V_197 >= V_198 )
break;
if ( ++ V_196 >= V_202 )
return true ;
}
return false ;
}
static void
F_82 ( struct V_33 * V_34 ,
struct V_13 * V_179 , int V_118 ,
unsigned long V_203 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_83 ( struct V_33 * V_34 ,
struct V_13 * V_179 )
{
struct V_103 * V_104 ;
struct V_125 * V_126 ;
if ( F_77 ( & V_179 -> V_20 ) )
return false ;
V_104 = F_84 ( & V_179 -> V_20 ) ;
V_126 = F_60 ( V_104 ) ;
if ( V_126 -> V_38 & V_204 )
return true ;
return false ;
}
static void
F_85 ( struct V_33 * V_34 ,
struct V_13 * V_179 , int V_118 ,
unsigned long V_203 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_86 ( struct V_14 * V_15 )
{
struct V_13 * V_179 ;
struct V_33 * V_34 = NULL ;
int V_118 = 0 ;
T_1 V_16 [ V_21 ] ;
int V_205 = 0 , V_89 = 0 ;
unsigned long V_38 ;
V_179 = F_76 ( V_15 , & V_34 , & V_118 ) ;
if ( ! V_179 )
return - 1 ;
V_89 = F_87 ( V_179 ) ;
F_8 ( V_15 -> V_23 , L_27 , V_89 ) ;
F_16 ( & V_34 -> V_47 . V_111 , V_38 ) ;
if ( ! F_58 ( V_34 , V_179 , V_118 ) ) {
F_19 ( & V_34 -> V_47 . V_111 , V_38 ) ;
return - 1 ;
}
if ( F_83 ( V_34 , V_179 ) ) {
F_85 ( V_34 , V_179 , V_118 , V_38 ) ;
return 0 ;
}
if ( ! V_179 -> V_40 ||
F_88 ( V_34 , V_179 , V_89 ) ||
V_34 -> V_206 . V_207 ) {
if ( V_179 -> V_40 &&
F_88 ( V_34 , V_179 , V_89 ) &&
F_89 ( V_34 , V_179 , V_89 ) &&
F_90 ( V_34 , V_89 ) &&
F_80 ( V_34 , V_179 ,
V_15 -> V_95 ) )
F_91 ( V_34 , V_179 , V_118 , V_38 ) ;
else
F_82 ( V_34 , V_179 , V_118 , V_38 ) ;
} else {
if ( F_92 ( V_34 , V_179 , V_89 ) &&
V_179 -> V_45 > V_179 -> V_46 ) {
if ( F_93 ( V_15 ) ) {
F_94 ( V_34 , V_179 -> V_16 , V_89 ,
V_208 ) ;
F_95 ( V_34 , V_89 , V_179 -> V_16 ) ;
} else if ( F_96
( V_34 , V_89 , & V_205 , V_16 ) ) {
F_94 ( V_34 , V_179 -> V_16 , V_89 ,
V_208 ) ;
F_97 ( V_34 , V_205 , V_16 , 1 ) ;
}
}
if ( F_90 ( V_34 , V_89 ) &&
F_80 ( V_34 , V_179 ,
V_15 -> V_95 ) )
F_91 ( V_34 , V_179 , V_118 , V_38 ) ;
else
F_82 ( V_34 , V_179 , V_118 , V_38 ) ;
}
return 0 ;
}
void
F_98 ( struct V_14 * V_15 )
{
do {
if ( V_15 -> V_209 || V_15 -> V_210 )
break;
if ( F_86 ( V_15 ) )
break;
} while ( ! F_34 ( V_15 ) );
}
