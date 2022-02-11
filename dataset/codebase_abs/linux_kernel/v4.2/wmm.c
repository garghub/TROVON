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
F_8 ( V_15 , V_23 , L_7 , V_17 ) ;
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
F_8 ( V_15 , V_23 ,
L_8 , V_17 ) ;
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
F_8 ( V_15 , V_48 , L_9 ,
V_17 , V_17 -> V_40 ) ;
if ( V_17 -> V_40 ) {
V_17 -> V_49 = 0 ;
V_17 -> V_50 =
F_9 () ;
}
F_20 ( & V_17 -> V_19 ,
& V_34 -> V_51 . V_52 [ V_35 ] . V_17 ) ;
}
}
static void F_21 ( struct V_33 * V_34 )
{
V_34 -> V_51 . V_53 [ 0 ] = V_54 ;
V_34 -> V_51 . V_53 [ 1 ] = V_55 ;
V_34 -> V_51 . V_53 [ 2 ] = V_56 ;
V_34 -> V_51 . V_53 [ 3 ] = V_57 ;
}
static void
F_22 ( struct V_33 * V_34 )
{
struct V_58 * V_51 = & V_34 -> V_51 ;
T_1 * V_53 = V_51 -> V_53 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 4 ; ++ V_35 ) {
V_59 [ 7 - ( V_35 * 2 ) ] = V_60 [ V_53 [ V_35 ] ] [ 1 ] ;
V_59 [ 6 - ( V_35 * 2 ) ] = V_60 [ V_53 [ V_35 ] ] [ 0 ] ;
}
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 )
V_34 -> V_61 [ V_59 [ V_35 ] ] = ( T_1 ) V_35 ;
F_23 ( & V_51 -> V_62 , V_63 ) ;
}
void
F_24 ( struct V_33 * V_34 ,
struct V_64 * V_65 )
{
T_3 V_66 , V_67 , V_68 [ 4 ] ;
T_2 V_35 , V_69 , V_70 ;
T_1 V_71 ;
if ( ! V_65 || ! V_34 -> V_72 ) {
F_21 ( V_34 ) ;
return;
}
F_8 ( V_34 -> V_15 , V_23 ,
L_10
L_11 ,
V_65 -> V_73 . V_74 , V_65 -> V_75 &
V_76 ,
V_65 -> V_77 ) ;
for ( V_70 = 0 ; V_70 < F_25 ( V_65 -> V_78 ) ; V_70 ++ ) {
T_1 V_79 = V_65 -> V_78 [ V_70 ] . V_9 ;
T_1 V_80 = V_65 -> V_78 [ V_70 ] . V_5 ;
V_66 = ( 1 << ( V_79 & V_10 ) ) - 1 ;
V_67 = ( V_66 >> 1 ) + ( V_80 & V_8 ) ;
V_71 = V_4 [ ( V_80 & V_6 ) >> 5 ] ;
V_34 -> V_51 . V_53 [ V_71 ] = V_71 ;
V_68 [ V_71 ] = V_67 ;
F_8 ( V_34 -> V_15 , V_23 ,
L_12 ,
( 1 << ( ( V_79 & V_11 ) >> 4 ) ) - 1 ,
V_66 , V_67 ) ;
F_1 ( & V_65 -> V_78 [ V_70 ] ) ;
}
for ( V_35 = 0 ; V_35 < V_70 ; V_35 ++ ) {
for ( V_69 = 1 ; V_69 < V_70 - V_35 ; V_69 ++ ) {
if ( V_68 [ V_69 - 1 ] > V_68 [ V_69 ] ) {
F_26 ( V_68 [ V_69 - 1 ] , V_68 [ V_69 ] ) ;
F_26 ( V_34 -> V_51 . V_53 [ V_69 - 1 ] ,
V_34 -> V_51 . V_53 [ V_69 ] ) ;
} else if ( V_68 [ V_69 - 1 ] == V_68 [ V_69 ] ) {
if ( V_34 -> V_51 . V_53 [ V_69 - 1 ]
< V_34 -> V_51 . V_53 [ V_69 ] )
F_26 ( V_34 -> V_51 . V_53 [ V_69 - 1 ] ,
V_34 -> V_51 . V_53 [ V_69 ] ) ;
}
}
}
F_22 ( V_34 ) ;
}
static enum V_81
F_27 ( struct V_33 * V_34 ,
enum V_81 V_82 )
{
int V_83 ;
enum V_81 V_84 ;
struct V_85 * V_86 ;
V_86 = & V_34 -> V_51 . V_86 [ V_82 ] ;
if ( ! V_86 -> V_87 )
return V_82 ;
V_84 = V_57 ;
for ( V_83 = V_57 ; V_83 < V_82 ; V_83 ++ ) {
V_86 = & V_34 -> V_51 . V_86 [ V_83 ] ;
if ( ! V_86 -> V_87 && ! V_86 -> V_88 )
V_84 = (enum V_81 ) V_83 ;
}
return V_84 ;
}
void
F_28 ( struct V_33 * V_34 )
{
int V_89 ;
F_8 ( V_34 -> V_15 , V_23 , L_13
L_14 ) ;
if ( ! V_34 -> V_72 ) {
for ( V_89 = V_57 ; V_89 <= V_54 ; V_89 ++ )
V_34 -> V_51 . V_90 [ V_89 ] =
(enum V_81 ) V_89 ;
} else {
for ( V_89 = V_57 ; V_89 <= V_54 ; V_89 ++ ) {
V_34 -> V_51 . V_90 [ V_89 ]
= F_27 ( V_34 ,
(enum V_81 ) V_89 ) ;
F_8 ( V_34 -> V_15 , V_23 ,
L_15 ,
V_89 ,
V_34 -> V_51 . V_90 [ V_89 ] ) ;
}
}
}
static enum V_81
F_29 ( struct V_14 * V_15 , T_2 V_91 )
{
const enum V_81 V_92 [] = { V_56 ,
V_57 ,
V_57 ,
V_56 ,
V_55 ,
V_55 ,
V_54 ,
V_54
} ;
if ( V_91 >= F_25 ( V_92 ) )
return V_56 ;
return V_92 [ V_91 ] ;
}
T_1 F_30 ( struct V_33 * V_34 , T_2 V_93 )
{
enum V_81 V_94 , V_95 ;
T_1 V_96 ;
V_94 = F_29 ( V_34 -> V_15 , V_93 ) ;
V_95 = V_34 -> V_51 . V_90 [ V_94 ] ;
V_96 = V_60 [ V_95 ] [ V_93 % 2 ] ;
return V_96 ;
}
void
F_31 ( struct V_14 * V_15 )
{
int V_35 , V_69 ;
struct V_33 * V_34 ;
for ( V_69 = 0 ; V_69 < V_15 -> V_97 ; ++ V_69 ) {
V_34 = V_15 -> V_34 [ V_69 ] ;
if ( ! V_34 )
continue;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
if ( ! V_98 &&
V_15 -> V_99 > V_100 )
V_34 -> V_101 [ V_35 ] . V_102 =
V_34 -> V_61 [ V_35 ] ;
else
V_34 -> V_101 [ V_35 ] . V_102 =
V_103 ;
V_34 -> V_101 [ V_35 ] . V_104 =
V_34 -> V_61 [ V_35 ] ;
V_34 -> V_101 [ V_35 ] . V_105 =
V_34 -> V_61 [ V_35 ] ;
}
V_34 -> V_101 [ 6 ] . V_102
= V_34 -> V_101 [ 6 ] . V_104
= V_34 -> V_101 [ 6 ] . V_105
= V_103 ;
V_34 -> V_101 [ 7 ] . V_102 = V_34 -> V_101 [ 7 ] . V_104
= V_34 -> V_101 [ 7 ] . V_105
= V_103 ;
F_32 ( V_34 ) ;
F_33 ( V_34 ) ;
F_23 ( & V_34 -> V_51 . V_106 , 0 ) ;
F_23 ( & V_34 -> V_51 . V_62 , V_63 ) ;
}
}
int
F_34 ( struct V_14 * V_15 )
{
int V_35 ;
struct V_33 * V_34 ;
for ( V_35 = 0 ; V_35 < V_15 -> V_97 ; ++ V_35 ) {
V_34 = V_15 -> V_34 [ V_35 ] ;
if ( V_34 && F_35 ( & V_34 -> V_51 . V_106 ) )
return false ;
}
return true ;
}
static void
F_36 ( struct V_33 * V_34 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_107 * V_108 , * V_68 ;
F_37 (&ra_list->skb_head, skb, tmp)
F_38 ( V_15 , V_108 , 0 , - 1 ) ;
}
static void
F_39 ( struct V_33 * V_34 ,
struct V_109 * V_110 )
{
struct V_13 * V_17 ;
F_40 (ra_list, ra_list_head, list)
F_36 ( V_34 , V_17 ) ;
}
static void F_41 ( struct V_33 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_39 ; V_35 ++ )
F_39 ( V_34 , & V_34 -> V_51 . V_52 [ V_35 ] .
V_17 ) ;
F_23 ( & V_34 -> V_51 . V_106 , 0 ) ;
F_23 ( & V_34 -> V_51 . V_62 , V_63 ) ;
}
static void F_42 ( struct V_33 * V_34 )
{
struct V_13 * V_17 , * V_111 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
F_8 ( V_34 -> V_15 , V_23 ,
L_16 , V_35 ) ;
F_43 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
F_44 ( & V_17 -> V_19 ) ;
F_45 ( V_17 ) ;
}
F_6 ( & V_34 -> V_51 . V_52 [ V_35 ] . V_17 ) ;
}
}
static int F_46 ( int V_112 , void * V_113 , void * V_114 )
{
F_47 ( L_17 ) ;
F_48 ( V_113 ) ;
return 0 ;
}
void
F_49 ( struct V_33 * V_34 )
{
unsigned long V_38 ;
struct V_107 * V_108 , * V_68 ;
F_50 ( V_34 ) ;
F_16 ( & V_34 -> V_51 . V_115 , V_38 ) ;
F_41 ( V_34 ) ;
F_51 ( V_34 ) ;
if ( V_34 -> V_15 -> V_116 . V_117 )
V_34 -> V_15 -> V_116 . V_117 ( V_34 -> V_15 ) ;
F_42 ( V_34 ) ;
memcpy ( V_59 , V_60 , sizeof( V_59 ) ) ;
if ( V_34 -> V_15 -> V_116 . V_118 &&
! V_34 -> V_15 -> V_119 )
V_34 -> V_15 -> V_116 . V_118 ( V_34 -> V_15 ) ;
F_19 ( & V_34 -> V_51 . V_115 , V_38 ) ;
F_37 (&priv->tdls_txq, skb, tmp)
F_38 ( V_34 -> V_15 , V_108 , 0 , - 1 ) ;
F_52 ( & V_34 -> V_120 , F_46 , NULL ) ;
F_53 ( & V_34 -> V_120 ) ;
}
struct V_13 *
F_54 ( struct V_33 * V_34 , T_1 V_93 ,
const T_1 * V_121 )
{
struct V_13 * V_17 ;
F_40 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_121 , V_21 ) )
return V_17 ;
}
return NULL ;
}
struct V_13 *
F_55 ( struct V_33 * V_34 , T_1 V_93 ,
const T_1 * V_121 )
{
struct V_13 * V_17 ;
V_17 = F_54 ( V_34 , V_93 , V_121 ) ;
if ( V_17 )
return V_17 ;
F_11 ( V_34 , V_121 ) ;
return F_54 ( V_34 , V_93 , V_121 ) ;
}
void
F_56 ( struct V_33 * V_34 , const T_1 * V_121 )
{
struct V_13 * V_17 ;
unsigned long V_38 ;
int V_35 ;
F_16 ( & V_34 -> V_51 . V_115 , V_38 ) ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
V_17 = F_54 ( V_34 , V_35 , V_121 ) ;
if ( ! V_17 )
continue;
F_36 ( V_34 , V_17 ) ;
F_57 ( V_17 -> V_22 , & V_34 -> V_51 . V_106 ) ;
F_44 ( & V_17 -> V_19 ) ;
F_45 ( V_17 ) ;
}
F_19 ( & V_34 -> V_51 . V_115 , V_38 ) ;
}
int
F_58 ( struct V_33 * V_34 ,
struct V_13 * V_17 , int V_122 )
{
struct V_13 * V_123 ;
F_40 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_123 == V_17 )
return true ;
}
return false ;
}
void
F_59 ( struct V_33 * V_34 ,
struct V_107 * V_108 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
T_2 V_93 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_21 ] , V_124 ;
unsigned long V_38 ;
struct V_109 V_109 ;
int V_125 = V_126 ;
struct V_127 * V_128 = (struct V_127 * ) V_108 -> V_114 ;
struct V_129 * V_130 = F_60 ( V_108 ) ;
memcpy ( V_16 , V_128 -> V_131 , V_21 ) ;
if ( F_61 ( V_34 ) == V_132 &&
F_62 ( V_15 -> V_133 ) ) {
if ( F_63 ( V_128 -> V_134 ) == V_135 )
F_8 ( V_15 , V_48 ,
L_18
L_19 , V_16 ) ;
else if ( memcmp ( V_34 -> V_136 , V_16 , V_21 ) )
V_125 = F_13 ( V_34 , V_16 ) ;
}
if ( ! V_34 -> V_137 && ! F_64 ( V_108 ) ) {
F_8 ( V_15 , V_48 , L_20 ) ;
F_38 ( V_15 , V_108 , 0 , - 1 ) ;
return;
}
V_93 = V_108 -> V_138 ;
F_16 ( & V_34 -> V_51 . V_115 , V_38 ) ;
V_124 = F_30 ( V_34 , V_93 ) ;
if ( ! F_12 ( V_34 ) &&
! F_64 ( V_108 ) ) {
switch ( V_125 ) {
case V_45 :
V_17 = F_55 ( V_34 , V_124 ,
V_16 ) ;
V_130 -> V_38 |= V_139 ;
break;
case V_140 :
F_65 ( & V_34 -> V_141 , V_108 ) ;
F_19 ( & V_34 -> V_51 . V_115 ,
V_38 ) ;
return;
default:
V_109 = V_34 -> V_51 . V_52 [ V_124 ] . V_17 ;
if ( ! F_66 ( & V_109 ) )
V_17 = F_67 (
& V_109 , struct V_13 ,
V_19 ) ;
else
V_17 = NULL ;
break;
}
} else {
memcpy ( V_16 , V_108 -> V_114 , V_21 ) ;
if ( V_16 [ 0 ] & 0x01 || F_64 ( V_108 ) )
F_68 ( V_16 ) ;
V_17 = F_55 ( V_34 , V_124 , V_16 ) ;
}
if ( ! V_17 ) {
F_19 ( & V_34 -> V_51 . V_115 , V_38 ) ;
F_38 ( V_15 , V_108 , 0 , - 1 ) ;
return;
}
F_65 ( & V_17 -> V_20 , V_108 ) ;
V_17 -> V_49 ++ ;
V_17 -> V_22 ++ ;
if ( F_35 ( & V_34 -> V_51 . V_62 ) <
V_34 -> V_61 [ V_124 ] )
F_23 ( & V_34 -> V_51 . V_62 ,
V_34 -> V_61 [ V_124 ] ) ;
F_69 ( & V_34 -> V_51 . V_106 ) ;
F_19 ( & V_34 -> V_51 . V_115 , V_38 ) ;
}
int F_70 ( struct V_33 * V_34 ,
const struct V_142 * V_143 )
{
T_1 * V_144 = ( T_1 * ) & V_143 -> V_145 . V_146 ;
T_4 V_147 = F_3 ( V_143 -> V_148 ) , V_149 ;
int V_150 = V_76 ;
bool V_151 = true ;
struct V_152 * V_153 ;
struct V_154 * V_155 ;
struct V_64 * V_156 = NULL ;
struct V_85 * V_86 ;
F_8 ( V_34 -> V_15 , V_23 ,
L_21 ,
V_147 ) ;
while ( ( V_147 >= sizeof( V_153 -> V_157 ) ) && V_151 ) {
V_153 = (struct V_152 * ) V_144 ;
V_149 = F_3 ( V_153 -> V_157 . V_158 ) ;
if ( V_147 < V_149 + sizeof( V_153 -> V_157 ) )
break;
switch ( F_3 ( V_153 -> V_157 . type ) ) {
case V_159 :
V_155 =
(struct V_154 * )
V_153 ;
F_8 ( V_34 -> V_15 , V_160 ,
L_22
L_23 ,
V_155 -> V_161 ,
V_155 -> V_88 ,
V_155 -> V_87 ) ;
V_86 = & V_34 -> V_51 . V_86 [ V_155 ->
V_161 ] ;
V_86 -> V_87 = V_155 -> V_87 ;
V_86 -> V_88 =
V_155 -> V_88 ;
V_86 -> V_162 = V_155 -> V_162 ;
break;
case V_163 :
V_156 =
(struct V_64 * ) ( V_144 +
2 ) ;
V_156 -> V_73 . V_158 = ( T_1 ) V_149 ;
V_156 -> V_73 . V_164 =
V_163 ;
F_8 ( V_34 -> V_15 , V_160 ,
L_22
L_24 ,
V_156 -> V_75 & V_150 ) ;
memcpy ( ( T_1 * ) & V_34 -> V_165 . V_166 .
V_65 , V_156 ,
V_156 -> V_73 . V_158 + 2 ) ;
break;
default:
V_151 = false ;
break;
}
V_144 += ( V_149 + sizeof( V_153 -> V_157 ) ) ;
V_147 -= ( V_149 + sizeof( V_153 -> V_157 ) ) ;
}
F_24 ( V_34 , V_156 ) ;
F_28 ( V_34 ) ;
return 0 ;
}
T_2
F_71 ( struct V_33 * V_34 ,
T_1 * * V_167 ,
struct V_64 * V_65 ,
struct V_168 * V_169 )
{
struct V_170 * V_171 ;
T_2 V_172 = 0 ;
if ( ! V_167 )
return 0 ;
if ( ! ( * V_167 ) )
return 0 ;
if ( ! V_65 )
return 0 ;
F_8 ( V_34 -> V_15 , V_23 ,
L_25 ,
V_65 -> V_73 . V_164 ) ;
if ( ( V_34 -> V_173 ||
( V_169 && ( V_34 -> V_15 -> V_174 & V_175 ||
V_34 -> V_15 -> V_174 & V_176 ) ) ) &&
V_65 -> V_73 . V_164 == V_163 ) {
V_171 = (struct V_170 * ) * V_167 ;
V_171 -> V_157 . type = F_72 ( ( T_3 ) V_177 [ 0 ] ) ;
V_171 -> V_157 . V_158 = F_72 ( ( T_3 ) V_177 [ 1 ] ) ;
memcpy ( V_171 -> V_65 , & V_177 [ 2 ] ,
F_3 ( V_171 -> V_157 . V_158 ) ) ;
if ( V_65 -> V_75 & V_178 )
memcpy ( ( T_1 * ) ( V_171 -> V_65
+ F_3 ( V_171 -> V_157 . V_158 )
- sizeof( V_34 -> V_179 ) ) ,
& V_34 -> V_179 , sizeof( V_34 -> V_179 ) ) ;
V_172 = sizeof( V_171 -> V_157 )
+ F_3 ( V_171 -> V_157 . V_158 ) ;
* V_167 += V_172 ;
}
return V_172 ;
}
T_1
F_73 ( struct V_33 * V_34 ,
const struct V_107 * V_108 )
{
T_2 V_180 = F_74 ( F_75 ( V_108 -> V_181 ) ) ;
T_1 V_182 ;
V_182 = ( T_1 ) ( F_76 ( V_180 , V_34 -> V_51 . V_183 ) >> 1 ) ;
F_8 ( V_34 -> V_15 , V_48 , L_26
L_27 , V_180 , V_182 ) ;
return V_182 ;
}
static struct V_13 *
F_77 ( struct V_14 * V_15 ,
struct V_33 * * V_34 , int * V_93 )
{
struct V_33 * V_184 ;
struct V_13 * V_185 ;
struct V_186 * V_187 ;
T_5 * V_188 ;
unsigned long V_189 ;
int V_35 , V_69 ;
for ( V_69 = V_15 -> V_97 - 1 ; V_69 >= 0 ; -- V_69 ) {
F_40 (adapter->bss_prio_tbl[j].bss_prio_cur,
&adapter->bss_prio_tbl[j].bss_prio_head,
list) {
V_184 = V_15 -> V_190 [ V_69 ] . V_191 -> V_34 ;
if ( F_35 ( & V_184 -> V_51 . V_106 ) == 0 )
continue;
V_188 = & V_184 -> V_51 . V_62 ;
for ( V_35 = F_35 ( V_188 ) ; V_35 >= V_192 ; -- V_35 ) {
F_16 ( & V_184 -> V_51 .
V_115 , V_189 ) ;
V_187 = & ( V_184 ) -> V_51 .
V_52 [ V_59 [ V_35 ] ] ;
F_40 (ptr, &tid_ptr->ra_list,
list) {
if ( ! F_78 ( & V_185 -> V_20 ) )
goto V_193;
}
F_19 ( & V_184 -> V_51 .
V_115 ,
V_189 ) ;
}
}
}
return NULL ;
V_193:
if ( F_35 ( V_188 ) > V_35 )
F_23 ( V_188 , V_35 ) ;
F_19 ( & V_184 -> V_51 . V_115 , V_189 ) ;
* V_34 = V_184 ;
* V_93 = V_59 [ V_35 ] ;
return V_185 ;
}
void F_79 ( struct V_33 * V_34 ,
struct V_13 * V_16 ,
int V_93 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_194 * V_195 = V_15 -> V_190 ;
struct V_186 * V_187 = & V_34 -> V_51 . V_52 [ V_93 ] ;
unsigned long V_38 ;
F_16 ( & V_195 [ V_34 -> V_196 ] . V_197 , V_38 ) ;
F_80 ( & V_195 [ V_34 -> V_196 ] . V_198 ,
& V_195 [ V_34 -> V_196 ] . V_191 -> V_19 ) ;
F_19 ( & V_195 [ V_34 -> V_196 ] . V_197 , V_38 ) ;
F_16 ( & V_34 -> V_51 . V_115 , V_38 ) ;
if ( F_58 ( V_34 , V_16 , V_93 ) ) {
V_34 -> V_51 . V_199 [ V_93 ] ++ ;
F_80 ( & V_187 -> V_17 , & V_16 -> V_19 ) ;
}
F_19 ( & V_34 -> V_51 . V_115 , V_38 ) ;
}
static int
F_81 ( struct V_33 * V_34 ,
struct V_13 * V_185 ,
int V_200 )
{
int V_201 = 0 , V_202 = 0 ;
struct V_107 * V_108 , * V_68 ;
int V_203 ;
if ( V_34 -> V_204 == V_205 && V_34 -> V_206 &&
V_185 -> V_40 )
V_203 = F_82 ( int , V_185 -> V_47 , V_200 ) ;
else
V_203 = V_200 ;
F_37 (&ptr->skb_head, skb, tmp) {
V_202 += V_108 -> V_158 ;
if ( V_202 >= V_203 )
break;
if ( ++ V_201 >= V_207 )
return true ;
}
return false ;
}
static void
F_83 ( struct V_33 * V_34 ,
struct V_13 * V_185 , int V_122 ,
unsigned long V_208 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_84 ( struct V_33 * V_34 ,
struct V_13 * V_185 )
{
struct V_107 * V_108 ;
struct V_129 * V_130 ;
if ( F_78 ( & V_185 -> V_20 ) )
return false ;
V_108 = F_85 ( & V_185 -> V_20 ) ;
V_130 = F_60 ( V_108 ) ;
if ( V_130 -> V_38 & V_209 )
return true ;
return false ;
}
static void
F_86 ( struct V_33 * V_34 ,
struct V_13 * V_185 , int V_122 ,
unsigned long V_208 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_87 ( struct V_14 * V_15 )
{
struct V_13 * V_185 ;
struct V_33 * V_34 = NULL ;
int V_122 = 0 ;
T_1 V_16 [ V_21 ] ;
int V_210 = 0 , V_93 = 0 ;
unsigned long V_38 ;
V_185 = F_77 ( V_15 , & V_34 , & V_122 ) ;
if ( ! V_185 )
return - 1 ;
V_93 = F_88 ( V_185 ) ;
F_8 ( V_15 , V_48 , L_28 , V_93 ) ;
F_16 ( & V_34 -> V_51 . V_115 , V_38 ) ;
if ( ! F_58 ( V_34 , V_185 , V_122 ) ) {
F_19 ( & V_34 -> V_51 . V_115 , V_38 ) ;
return - 1 ;
}
if ( F_84 ( V_34 , V_185 ) ) {
F_86 ( V_34 , V_185 , V_122 , V_38 ) ;
return 0 ;
}
if ( ! V_185 -> V_40 ||
V_185 -> V_42 ||
V_34 -> V_211 . V_212 ) {
if ( V_185 -> V_40 &&
V_185 -> V_42 &&
V_185 -> V_44 &&
F_89 ( V_34 , V_93 ) &&
F_81 ( V_34 , V_185 ,
V_15 -> V_99 ) )
F_90 ( V_34 , V_185 , V_122 , V_38 ) ;
else
F_83 ( V_34 , V_185 , V_122 , V_38 ) ;
} else {
if ( F_91 ( V_34 , V_185 , V_93 ) &&
V_185 -> V_49 > V_185 -> V_50 ) {
if ( F_92 ( V_15 ) ) {
F_93 ( V_34 , V_185 -> V_16 , V_93 ,
V_213 ) ;
F_94 ( V_34 , V_93 , V_185 -> V_16 ) ;
} else if ( F_95
( V_34 , V_93 , & V_210 , V_16 ) ) {
F_93 ( V_34 , V_185 -> V_16 , V_93 ,
V_213 ) ;
F_96 ( V_34 , V_210 , V_16 , 1 ) ;
}
}
if ( F_89 ( V_34 , V_93 ) &&
F_81 ( V_34 , V_185 ,
V_15 -> V_99 ) )
F_90 ( V_34 , V_185 , V_122 , V_38 ) ;
else
F_83 ( V_34 , V_185 , V_122 , V_38 ) ;
}
return 0 ;
}
void
F_97 ( struct V_14 * V_15 )
{
do {
if ( F_87 ( V_15 ) )
break;
if ( V_15 -> V_214 != V_215 ) {
if ( V_15 -> V_216 ||
V_15 -> V_217 )
break;
} else {
if ( F_35 ( & V_15 -> V_218 ) >=
V_219 )
break;
}
} while ( ! F_34 ( V_15 ) );
}
