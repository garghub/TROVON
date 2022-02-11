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
F_12 ( & V_34 -> V_39 , V_38 ) ;
V_37 = F_13 ( V_34 , V_16 ) ;
F_14 ( & V_34 -> V_39 , V_38 ) ;
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 ) {
V_17 = F_4 ( V_15 , V_16 ) ;
F_8 ( V_15 -> V_23 , L_8 , V_17 ) ;
if ( ! V_17 )
break;
V_17 -> V_41 = 0 ;
V_17 -> V_42 = false ;
if ( ! F_15 ( V_34 ) ) {
if ( F_16 ( V_34 , V_16 ) ==
V_43 ) {
V_17 -> V_42 = true ;
V_17 -> V_41 =
F_17 ( V_34 , V_16 ) ;
} else {
V_17 -> V_41 = F_18 ( V_34 ) ;
}
} else {
V_17 -> V_41 =
F_19 ( V_34 , V_37 ) ;
if ( V_17 -> V_41 )
V_17 -> V_44 = V_37 -> V_44 ;
}
F_8 ( V_15 -> V_23 , L_9 ,
V_17 , V_17 -> V_41 ) ;
if ( V_17 -> V_41 ) {
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
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 )
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
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 ) {
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
for ( V_35 = 0 ; V_35 < V_40 ; V_35 ++ )
F_39 ( V_34 , & V_34 -> V_47 . V_48 [ V_35 ] .
V_17 ) ;
F_23 ( & V_34 -> V_47 . V_102 , 0 ) ;
F_23 ( & V_34 -> V_47 . V_58 , V_59 ) ;
}
static void F_42 ( struct V_33 * V_34 )
{
struct V_13 * V_17 , * V_107 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 ) {
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
void
F_46 ( struct V_33 * V_34 )
{
unsigned long V_38 ;
struct V_103 * V_104 , * V_64 ;
F_47 ( V_34 ) ;
F_12 ( & V_34 -> V_47 . V_108 , V_38 ) ;
F_41 ( V_34 ) ;
F_48 ( V_34 ) ;
if ( V_34 -> V_15 -> V_109 . V_110 )
V_34 -> V_15 -> V_109 . V_110 ( V_34 -> V_15 ) ;
F_42 ( V_34 ) ;
memcpy ( V_55 , V_56 , sizeof( V_55 ) ) ;
if ( V_34 -> V_15 -> V_109 . V_111 &&
! V_34 -> V_15 -> V_112 )
V_34 -> V_15 -> V_109 . V_111 ( V_34 -> V_15 ) ;
F_14 ( & V_34 -> V_47 . V_108 , V_38 ) ;
F_37 (&priv->tdls_txq, skb, tmp)
F_38 ( V_34 -> V_15 , V_104 , 0 , - 1 ) ;
}
static struct V_13 *
F_49 ( struct V_33 * V_34 , T_1 V_89 ,
const T_1 * V_113 )
{
struct V_13 * V_17 ;
F_40 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_113 , V_21 ) )
return V_17 ;
}
return NULL ;
}
struct V_13 *
F_50 ( struct V_33 * V_34 , T_1 V_89 ,
const T_1 * V_113 )
{
struct V_13 * V_17 ;
V_17 = F_49 ( V_34 , V_89 , V_113 ) ;
if ( V_17 )
return V_17 ;
F_11 ( V_34 , V_113 ) ;
return F_49 ( V_34 , V_89 , V_113 ) ;
}
int
F_51 ( struct V_33 * V_34 ,
struct V_13 * V_17 , int V_114 )
{
struct V_13 * V_115 ;
F_40 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_115 == V_17 )
return true ;
}
return false ;
}
void
F_52 ( struct V_33 * V_34 ,
struct V_103 * V_104 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
T_2 V_89 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_21 ] , V_116 ;
unsigned long V_38 ;
struct V_105 V_105 ;
int V_117 = V_118 ;
struct V_119 * V_120 = (struct V_119 * ) V_104 -> V_121 ;
struct V_122 * V_123 = F_53 ( V_104 ) ;
memcpy ( V_16 , V_120 -> V_124 , V_21 ) ;
if ( F_54 ( V_34 ) == V_125 &&
F_55 ( V_15 -> V_126 ) ) {
if ( F_56 ( V_120 -> V_127 ) == V_128 )
F_8 ( V_15 -> V_23 ,
L_17 , V_16 ) ;
else if ( memcmp ( V_34 -> V_129 , V_16 , V_21 ) )
V_117 = F_16 ( V_34 , V_16 ) ;
}
if ( ! V_34 -> V_130 && ! F_57 ( V_104 ) ) {
F_8 ( V_15 -> V_23 , L_18 ) ;
F_38 ( V_15 , V_104 , 0 , - 1 ) ;
return;
}
V_89 = V_104 -> V_131 ;
F_12 ( & V_34 -> V_47 . V_108 , V_38 ) ;
V_116 = F_30 ( V_34 , V_89 ) ;
if ( ! F_15 ( V_34 ) &&
! F_57 ( V_104 ) ) {
switch ( V_117 ) {
case V_43 :
V_17 = F_50 ( V_34 , V_116 ,
V_16 ) ;
V_123 -> V_38 |= V_132 ;
break;
case V_133 :
F_58 ( & V_34 -> V_134 , V_104 ) ;
F_14 ( & V_34 -> V_47 . V_108 ,
V_38 ) ;
return;
default:
V_105 = V_34 -> V_47 . V_48 [ V_116 ] . V_17 ;
if ( ! F_59 ( & V_105 ) )
V_17 = F_60 (
& V_105 , struct V_13 ,
V_19 ) ;
else
V_17 = NULL ;
break;
}
} else {
memcpy ( V_16 , V_104 -> V_121 , V_21 ) ;
if ( V_16 [ 0 ] & 0x01 || F_57 ( V_104 ) )
memset ( V_16 , 0xff , V_21 ) ;
V_17 = F_50 ( V_34 , V_116 , V_16 ) ;
}
if ( ! V_17 ) {
F_14 ( & V_34 -> V_47 . V_108 , V_38 ) ;
F_38 ( V_15 , V_104 , 0 , - 1 ) ;
return;
}
F_58 ( & V_17 -> V_20 , V_104 ) ;
V_17 -> V_45 ++ ;
V_17 -> V_22 ++ ;
if ( F_35 ( & V_34 -> V_47 . V_58 ) <
V_34 -> V_57 [ V_116 ] )
F_23 ( & V_34 -> V_47 . V_58 ,
V_34 -> V_57 [ V_116 ] ) ;
F_61 ( & V_34 -> V_47 . V_102 ) ;
F_14 ( & V_34 -> V_47 . V_108 , V_38 ) ;
}
int F_62 ( struct V_33 * V_34 ,
const struct V_135 * V_136 )
{
T_1 * V_137 = ( T_1 * ) & V_136 -> V_138 . V_139 ;
T_4 V_140 = F_3 ( V_136 -> V_141 ) , V_142 ;
bool V_143 = true ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_60 * V_148 = NULL ;
struct V_81 * V_82 ;
F_8 ( V_34 -> V_15 -> V_23 , L_19 ,
V_140 ) ;
while ( ( V_140 >= sizeof( V_145 -> V_149 ) ) && V_143 ) {
V_145 = (struct V_144 * ) V_137 ;
V_142 = F_3 ( V_145 -> V_149 . V_150 ) ;
if ( V_140 < V_142 + sizeof( V_145 -> V_149 ) )
break;
switch ( F_3 ( V_145 -> V_149 . type ) ) {
case V_151 :
V_147 =
(struct V_146 * )
V_145 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_20
L_21 ,
V_147 -> V_152 ,
V_147 -> V_84 ,
V_147 -> V_83 ) ;
V_82 = & V_34 -> V_47 . V_82 [ V_147 ->
V_152 ] ;
V_82 -> V_83 = V_147 -> V_83 ;
V_82 -> V_84 =
V_147 -> V_84 ;
V_82 -> V_153 = V_147 -> V_153 ;
break;
case V_154 :
V_148 =
(struct V_60 * ) ( V_137 +
2 ) ;
V_148 -> V_69 . V_150 = ( T_1 ) V_142 ;
V_148 -> V_69 . V_155 =
V_154 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_20
L_22 ,
V_148 -> V_71 &
V_72 ) ;
memcpy ( ( T_1 * ) & V_34 -> V_156 . V_157 .
V_61 , V_148 ,
V_148 -> V_69 . V_150 + 2 ) ;
break;
default:
V_143 = false ;
break;
}
V_137 += ( V_142 + sizeof( V_145 -> V_149 ) ) ;
V_140 -= ( V_142 + sizeof( V_145 -> V_149 ) ) ;
}
F_24 ( V_34 , V_148 ) ;
F_28 ( V_34 ) ;
return 0 ;
}
T_2
F_63 ( struct V_33 * V_34 ,
T_1 * * V_158 ,
struct V_60 * V_61 ,
struct V_159 * V_160 )
{
struct V_161 * V_162 ;
T_2 V_163 = 0 ;
if ( ! V_158 )
return 0 ;
if ( ! ( * V_158 ) )
return 0 ;
if ( ! V_61 )
return 0 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_23 ,
V_61 -> V_69 . V_155 ) ;
if ( ( V_34 -> V_164 ||
( V_160 && ( V_34 -> V_15 -> V_165 & V_166 ||
V_34 -> V_15 -> V_165 & V_167 ) ) ) &&
V_61 -> V_69 . V_155 == V_154 ) {
V_162 = (struct V_161 * ) * V_158 ;
V_162 -> V_149 . type = F_64 ( ( T_3 ) V_168 [ 0 ] ) ;
V_162 -> V_149 . V_150 = F_64 ( ( T_3 ) V_168 [ 1 ] ) ;
memcpy ( V_162 -> V_61 , & V_168 [ 2 ] ,
F_3 ( V_162 -> V_149 . V_150 ) ) ;
if ( V_61 -> V_71 & V_169 )
memcpy ( ( T_1 * ) ( V_162 -> V_61
+ F_3 ( V_162 -> V_149 . V_150 )
- sizeof( V_34 -> V_170 ) ) ,
& V_34 -> V_170 , sizeof( V_34 -> V_170 ) ) ;
V_163 = sizeof( V_162 -> V_149 )
+ F_3 ( V_162 -> V_149 . V_150 ) ;
* V_158 += V_163 ;
}
return V_163 ;
}
T_1
F_65 ( struct V_33 * V_34 ,
const struct V_103 * V_104 )
{
T_1 V_171 ;
struct V_26 V_172 , V_173 ;
T_2 V_174 ;
F_10 ( & V_172 ) ;
V_173 = F_66 ( V_104 -> V_175 ) ;
V_174 = ( V_172 . V_29 - V_173 . V_29 ) * 1000 ;
V_174 += ( V_172 . V_30 - V_173 . V_30 ) / 1000 ;
V_171 = ( T_1 ) ( F_67 ( V_174 , V_34 -> V_47 . V_176 ) >> 1 ) ;
F_8 ( V_34 -> V_15 -> V_23 , L_24
L_25 , V_174 , V_171 ) ;
return V_171 ;
}
static struct V_13 *
F_68 ( struct V_14 * V_15 ,
struct V_33 * * V_34 , int * V_89 )
{
struct V_33 * V_177 ;
struct V_13 * V_178 ;
struct V_179 * V_180 ;
T_5 * V_181 ;
unsigned long V_182 , V_183 ;
int V_35 , V_65 ;
for ( V_65 = V_15 -> V_93 - 1 ; V_65 >= 0 ; -- V_65 ) {
F_12 ( & V_15 -> V_184 [ V_65 ] . V_185 ,
V_182 ) ;
F_40 (adapter->bss_prio_tbl[j].bss_prio_cur,
&adapter->bss_prio_tbl[j].bss_prio_head,
list) {
V_177 = V_15 -> V_184 [ V_65 ] . V_186 -> V_34 ;
if ( F_35 ( & V_177 -> V_47 . V_102 ) == 0 )
continue;
V_181 = & V_177 -> V_47 . V_58 ;
for ( V_35 = F_35 ( V_181 ) ; V_35 >= V_187 ; -- V_35 ) {
F_12 ( & V_177 -> V_47 .
V_108 , V_183 ) ;
V_180 = & ( V_177 ) -> V_47 .
V_48 [ V_55 [ V_35 ] ] ;
F_40 (ptr, &tid_ptr->ra_list,
list) {
if ( ! F_69 ( & V_178 -> V_20 ) )
goto V_188;
}
F_14 ( & V_177 -> V_47 .
V_108 ,
V_183 ) ;
}
}
F_14 ( & V_15 -> V_184 [ V_65 ] . V_185 ,
V_182 ) ;
}
return NULL ;
V_188:
if ( F_35 ( V_181 ) > V_35 )
F_23 ( V_181 , V_35 ) ;
F_14 ( & V_177 -> V_47 . V_108 , V_183 ) ;
F_14 ( & V_15 -> V_184 [ V_65 ] . V_185 ,
V_182 ) ;
* V_34 = V_177 ;
* V_89 = V_55 [ V_35 ] ;
return V_178 ;
}
void F_70 ( struct V_33 * V_34 ,
struct V_13 * V_16 ,
int V_89 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_189 * V_190 = V_15 -> V_184 ;
struct V_179 * V_180 = & V_34 -> V_47 . V_48 [ V_89 ] ;
unsigned long V_38 ;
F_12 ( & V_190 [ V_34 -> V_191 ] . V_185 , V_38 ) ;
F_71 ( & V_190 [ V_34 -> V_191 ] . V_192 ,
& V_190 [ V_34 -> V_191 ] . V_186 -> V_19 ) ;
F_14 ( & V_190 [ V_34 -> V_191 ] . V_185 , V_38 ) ;
F_12 ( & V_34 -> V_47 . V_108 , V_38 ) ;
if ( F_51 ( V_34 , V_16 , V_89 ) ) {
V_34 -> V_47 . V_193 [ V_89 ] ++ ;
F_71 ( & V_180 -> V_17 , & V_16 -> V_19 ) ;
}
F_14 ( & V_34 -> V_47 . V_108 , V_38 ) ;
}
static int
F_72 ( struct V_33 * V_34 ,
struct V_13 * V_178 ,
int V_194 )
{
int V_195 = 0 , V_196 = 0 ;
struct V_103 * V_104 , * V_64 ;
int V_197 ;
if ( V_34 -> V_198 == V_199 && V_34 -> V_200 &&
V_178 -> V_41 )
V_197 = F_73 ( int , V_178 -> V_44 , V_194 ) ;
else
V_197 = V_194 ;
F_37 (&ptr->skb_head, skb, tmp) {
V_196 += V_104 -> V_150 ;
if ( V_196 >= V_197 )
break;
if ( ++ V_195 >= V_201 )
return true ;
}
return false ;
}
static void
F_74 ( struct V_33 * V_34 ,
struct V_13 * V_178 , int V_114 ,
unsigned long V_202 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_75 ( struct V_33 * V_34 ,
struct V_13 * V_178 )
{
struct V_103 * V_104 ;
struct V_122 * V_123 ;
if ( F_69 ( & V_178 -> V_20 ) )
return false ;
V_104 = F_76 ( & V_178 -> V_20 ) ;
V_123 = F_53 ( V_104 ) ;
if ( V_123 -> V_38 & V_203 )
return true ;
return false ;
}
static void
F_77 ( struct V_33 * V_34 ,
struct V_13 * V_178 , int V_114 ,
unsigned long V_202 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_78 ( struct V_14 * V_15 )
{
struct V_13 * V_178 ;
struct V_33 * V_34 = NULL ;
int V_114 = 0 ;
T_1 V_16 [ V_21 ] ;
int V_204 = 0 , V_89 = 0 ;
unsigned long V_38 ;
V_178 = F_68 ( V_15 , & V_34 , & V_114 ) ;
if ( ! V_178 )
return - 1 ;
V_89 = F_79 ( V_178 ) ;
F_8 ( V_15 -> V_23 , L_26 , V_89 ) ;
F_12 ( & V_34 -> V_47 . V_108 , V_38 ) ;
if ( ! F_51 ( V_34 , V_178 , V_114 ) ) {
F_14 ( & V_34 -> V_47 . V_108 , V_38 ) ;
return - 1 ;
}
if ( F_75 ( V_34 , V_178 ) ) {
F_77 ( V_34 , V_178 , V_114 , V_38 ) ;
return 0 ;
}
if ( ! V_178 -> V_41 ||
F_80 ( V_34 , V_178 , V_89 ) ||
V_34 -> V_205 . V_206 ) {
if ( V_178 -> V_41 &&
F_80 ( V_34 , V_178 , V_89 ) &&
F_81 ( V_34 , V_178 , V_89 ) &&
F_82 ( V_34 , V_89 ) &&
F_72 ( V_34 , V_178 ,
V_15 -> V_95 ) )
F_83 ( V_34 , V_178 , V_114 , V_38 ) ;
else
F_74 ( V_34 , V_178 , V_114 , V_38 ) ;
} else {
if ( F_84 ( V_34 , V_178 , V_89 ) &&
V_178 -> V_45 > V_178 -> V_46 ) {
if ( F_85 ( V_15 ) ) {
F_86 ( V_34 , V_178 -> V_16 , V_89 ,
V_207 ) ;
F_87 ( V_34 , V_89 , V_178 -> V_16 ) ;
} else if ( F_88
( V_34 , V_89 , & V_204 , V_16 ) ) {
F_86 ( V_34 , V_178 -> V_16 , V_89 ,
V_207 ) ;
F_89 ( V_34 , V_204 , V_16 , 1 ) ;
}
}
if ( F_82 ( V_34 , V_89 ) &&
F_72 ( V_34 , V_178 ,
V_15 -> V_95 ) )
F_83 ( V_34 , V_178 , V_114 , V_38 ) ;
else
F_74 ( V_34 , V_178 , V_114 , V_38 ) ;
}
return 0 ;
}
void
F_90 ( struct V_14 * V_15 )
{
do {
if ( V_15 -> V_208 || V_15 -> V_209 )
break;
if ( F_78 ( V_15 ) )
break;
} while ( ! F_34 ( V_15 ) );
}
