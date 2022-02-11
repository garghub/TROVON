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
V_17 -> V_45 = false ;
if ( ! F_12 ( V_34 ) ) {
if ( F_13
( F_14 ( V_34 , V_16 ) ) ) {
V_17 -> V_41 = true ;
V_17 -> V_40 =
F_15 ( V_34 , V_16 ) ;
} else {
V_17 -> V_40 = F_16 ( V_34 ) ;
}
} else {
F_17 ( & V_34 -> V_46 , V_38 ) ;
V_37 = F_18 ( V_34 , V_16 ) ;
V_17 -> V_40 =
F_19 ( V_34 , V_37 ) ;
if ( V_17 -> V_40 )
V_17 -> V_47 = V_37 -> V_47 ;
F_20 ( & V_34 -> V_46 , V_38 ) ;
}
F_8 ( V_15 , V_48 , L_9 ,
V_17 , V_17 -> V_40 ) ;
if ( V_17 -> V_40 ) {
V_17 -> V_49 = 0 ;
V_17 -> V_50 =
F_9 () ;
}
F_21 ( & V_17 -> V_19 ,
& V_34 -> V_51 . V_52 [ V_35 ] . V_17 ) ;
}
}
static void F_22 ( struct V_33 * V_34 )
{
V_34 -> V_51 . V_53 [ 0 ] = V_54 ;
V_34 -> V_51 . V_53 [ 1 ] = V_55 ;
V_34 -> V_51 . V_53 [ 2 ] = V_56 ;
V_34 -> V_51 . V_53 [ 3 ] = V_57 ;
}
static void
F_23 ( struct V_33 * V_34 )
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
F_24 ( & V_51 -> V_62 , V_63 ) ;
}
void
F_25 ( struct V_33 * V_34 ,
struct V_64 * V_65 )
{
T_3 V_66 , V_67 , V_68 [ 4 ] ;
T_2 V_35 , V_69 , V_70 ;
T_1 V_71 ;
if ( ! V_65 || ! V_34 -> V_72 ) {
F_22 ( V_34 ) ;
return;
}
F_8 ( V_34 -> V_15 , V_23 ,
L_10
L_11 ,
V_65 -> V_73 . V_74 , V_65 -> V_75 &
V_76 ,
V_65 -> V_77 ) ;
for ( V_70 = 0 ; V_70 < F_26 ( V_65 -> V_78 ) ; V_70 ++ ) {
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
F_27 ( V_68 [ V_69 - 1 ] , V_68 [ V_69 ] ) ;
F_27 ( V_34 -> V_51 . V_53 [ V_69 - 1 ] ,
V_34 -> V_51 . V_53 [ V_69 ] ) ;
} else if ( V_68 [ V_69 - 1 ] == V_68 [ V_69 ] ) {
if ( V_34 -> V_51 . V_53 [ V_69 - 1 ]
< V_34 -> V_51 . V_53 [ V_69 ] )
F_27 ( V_34 -> V_51 . V_53 [ V_69 - 1 ] ,
V_34 -> V_51 . V_53 [ V_69 ] ) ;
}
}
}
F_23 ( V_34 ) ;
}
static enum V_81
F_28 ( struct V_33 * V_34 ,
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
F_29 ( struct V_33 * V_34 )
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
= F_28 ( V_34 ,
(enum V_81 ) V_89 ) ;
F_8 ( V_34 -> V_15 , V_23 ,
L_15 ,
V_89 ,
V_34 -> V_51 . V_90 [ V_89 ] ) ;
}
}
}
static enum V_81
F_30 ( struct V_14 * V_15 , T_2 V_91 )
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
if ( V_91 >= F_26 ( V_92 ) )
return V_56 ;
return V_92 [ V_91 ] ;
}
T_1 F_31 ( struct V_33 * V_34 , T_2 V_93 )
{
enum V_81 V_94 , V_95 ;
T_1 V_96 ;
V_94 = F_30 ( V_34 -> V_15 , V_93 ) ;
V_95 = V_34 -> V_51 . V_90 [ V_94 ] ;
V_96 = V_60 [ V_95 ] [ V_93 % 2 ] ;
return V_96 ;
}
void
F_32 ( struct V_14 * V_15 )
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
F_33 ( V_34 ) ;
F_34 ( V_34 ) ;
F_24 ( & V_34 -> V_51 . V_106 , 0 ) ;
F_24 ( & V_34 -> V_51 . V_62 , V_63 ) ;
}
}
int F_35 ( struct V_14 * V_15 )
{
return F_36 ( & V_15 -> V_107 ) ? false : true ;
}
int
F_37 ( struct V_14 * V_15 )
{
int V_35 ;
struct V_33 * V_34 ;
for ( V_35 = 0 ; V_35 < V_15 -> V_97 ; ++ V_35 ) {
V_34 = V_15 -> V_34 [ V_35 ] ;
if ( V_34 && ! V_34 -> V_108 )
continue;
if ( V_34 && F_36 ( & V_34 -> V_51 . V_106 ) )
return false ;
}
return true ;
}
static void
F_38 ( struct V_33 * V_34 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_109 * V_110 , * V_68 ;
F_39 (&ra_list->skb_head, skb, tmp)
F_40 ( V_15 , V_110 , 0 , - 1 ) ;
}
static void
F_41 ( struct V_33 * V_34 ,
struct V_111 * V_112 )
{
struct V_13 * V_17 ;
F_42 (ra_list, ra_list_head, list)
F_38 ( V_34 , V_17 ) ;
}
static void F_43 ( struct V_33 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_39 ; V_35 ++ )
F_41 ( V_34 , & V_34 -> V_51 . V_52 [ V_35 ] .
V_17 ) ;
F_24 ( & V_34 -> V_51 . V_106 , 0 ) ;
F_24 ( & V_34 -> V_51 . V_62 , V_63 ) ;
}
static void F_44 ( struct V_33 * V_34 )
{
struct V_13 * V_17 , * V_113 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
F_8 ( V_34 -> V_15 , V_23 ,
L_16 , V_35 ) ;
F_45 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
F_46 ( & V_17 -> V_19 ) ;
F_47 ( V_17 ) ;
}
F_6 ( & V_34 -> V_51 . V_52 [ V_35 ] . V_17 ) ;
}
}
static int F_48 ( int V_114 , void * V_115 , void * V_116 )
{
F_49 ( L_17 ) ;
F_50 ( V_115 ) ;
return 0 ;
}
void
F_51 ( struct V_33 * V_34 )
{
unsigned long V_38 ;
struct V_109 * V_110 , * V_68 ;
F_52 ( V_34 ) ;
F_17 ( & V_34 -> V_51 . V_117 , V_38 ) ;
F_43 ( V_34 ) ;
F_53 ( V_34 ) ;
if ( V_34 -> V_15 -> V_118 . V_119 )
V_34 -> V_15 -> V_118 . V_119 ( V_34 -> V_15 ) ;
F_44 ( V_34 ) ;
memcpy ( V_59 , V_60 , sizeof( V_59 ) ) ;
if ( V_34 -> V_15 -> V_118 . V_120 &&
! V_34 -> V_15 -> V_121 )
V_34 -> V_15 -> V_118 . V_120 ( V_34 -> V_15 ) ;
F_20 ( & V_34 -> V_51 . V_117 , V_38 ) ;
F_39 (&priv->tdls_txq, skb, tmp)
F_40 ( V_34 -> V_15 , V_110 , 0 , - 1 ) ;
F_39 (&priv->bypass_txq, skb, tmp)
F_40 ( V_34 -> V_15 , V_110 , 0 , - 1 ) ;
F_24 ( & V_34 -> V_15 -> V_107 , 0 ) ;
F_54 ( & V_34 -> V_122 , F_48 , NULL ) ;
F_55 ( & V_34 -> V_122 ) ;
}
struct V_13 *
F_56 ( struct V_33 * V_34 , T_1 V_93 ,
const T_1 * V_123 )
{
struct V_13 * V_17 ;
F_42 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_123 , V_21 ) )
return V_17 ;
}
return NULL ;
}
void F_57 ( struct V_33 * V_34 , T_1 * V_124 ,
T_1 V_125 )
{
struct V_13 * V_17 ;
T_2 V_126 = 0 , V_106 ;
unsigned long V_38 ;
int V_35 ;
F_17 ( & V_34 -> V_51 . V_117 , V_38 ) ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
V_17 = F_56 ( V_34 , V_35 , V_124 ) ;
if ( V_17 && V_17 -> V_45 != V_125 ) {
V_126 += V_17 -> V_22 ;
V_17 -> V_45 = V_125 ;
if ( V_125 )
V_34 -> V_51 . V_127 [ V_35 ] +=
V_17 -> V_22 ;
else
V_34 -> V_51 . V_127 [ V_35 ] -=
V_17 -> V_22 ;
}
}
if ( V_126 ) {
V_106 = F_36 ( & V_34 -> V_51 . V_106 ) ;
if ( V_125 )
V_106 -= V_126 ;
else
V_106 += V_126 ;
F_24 ( & V_34 -> V_51 . V_106 , V_106 ) ;
F_24 ( & V_34 -> V_51 . V_62 , V_63 ) ;
}
F_20 ( & V_34 -> V_51 . V_117 , V_38 ) ;
}
void F_58 ( struct V_33 * V_34 ,
T_1 * V_124 , T_1 V_125 )
{
struct V_13 * V_17 ;
T_2 V_126 = 0 , V_106 ;
unsigned long V_38 ;
int V_35 ;
F_17 ( & V_34 -> V_51 . V_117 , V_38 ) ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
F_42 (ra_list, &priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_124 , V_21 ) )
continue;
if ( V_17 && V_17 -> V_45 != V_125 ) {
V_126 += V_17 -> V_22 ;
V_17 -> V_45 = V_125 ;
if ( V_125 )
V_34 -> V_51 . V_127 [ V_35 ] +=
V_17 -> V_22 ;
else
V_34 -> V_51 . V_127 [ V_35 ] -=
V_17 -> V_22 ;
}
}
}
if ( V_126 ) {
V_106 = F_36 ( & V_34 -> V_51 . V_106 ) ;
if ( V_125 )
V_106 -= V_126 ;
else
V_106 += V_126 ;
F_24 ( & V_34 -> V_51 . V_106 , V_106 ) ;
F_24 ( & V_34 -> V_51 . V_62 , V_63 ) ;
}
F_20 ( & V_34 -> V_51 . V_117 , V_38 ) ;
}
struct V_13 *
F_59 ( struct V_33 * V_34 , T_1 V_93 ,
const T_1 * V_123 )
{
struct V_13 * V_17 ;
V_17 = F_56 ( V_34 , V_93 , V_123 ) ;
if ( V_17 )
return V_17 ;
F_11 ( V_34 , V_123 ) ;
return F_56 ( V_34 , V_93 , V_123 ) ;
}
void
F_60 ( struct V_33 * V_34 , const T_1 * V_123 )
{
struct V_13 * V_17 ;
unsigned long V_38 ;
int V_35 ;
F_17 ( & V_34 -> V_51 . V_117 , V_38 ) ;
for ( V_35 = 0 ; V_35 < V_39 ; ++ V_35 ) {
V_17 = F_56 ( V_34 , V_35 , V_123 ) ;
if ( ! V_17 )
continue;
F_38 ( V_34 , V_17 ) ;
F_61 ( V_17 -> V_22 , & V_34 -> V_51 . V_106 ) ;
F_46 ( & V_17 -> V_19 ) ;
F_47 ( V_17 ) ;
}
F_20 ( & V_34 -> V_51 . V_117 , V_38 ) ;
}
int
F_62 ( struct V_33 * V_34 ,
struct V_13 * V_17 , int V_128 )
{
struct V_13 * V_129 ;
F_42 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_129 == V_17 )
return true ;
}
return false ;
}
void
F_63 ( struct V_33 * V_34 ,
struct V_109 * V_110 )
{
F_64 ( & V_34 -> V_130 , V_110 ) ;
}
void
F_65 ( struct V_33 * V_34 ,
struct V_109 * V_110 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
T_2 V_93 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_21 ] , V_131 ;
unsigned long V_38 ;
struct V_111 V_111 ;
int V_132 = V_133 ;
struct V_134 * V_135 = (struct V_134 * ) V_110 -> V_116 ;
struct V_136 * V_137 = F_66 ( V_110 ) ;
memcpy ( V_16 , V_135 -> V_138 , V_21 ) ;
if ( F_67 ( V_34 ) == V_139 &&
F_68 ( V_15 -> V_140 ) ) {
if ( F_69 ( V_135 -> V_141 ) == V_142 )
F_8 ( V_15 , V_48 ,
L_18
L_19 , V_16 ) ;
else if ( memcmp ( V_34 -> V_143 , V_16 , V_21 ) )
V_132 = F_14 ( V_34 , V_16 ) ;
}
if ( ! V_34 -> V_144 && ! F_70 ( V_110 ) ) {
F_8 ( V_15 , V_48 , L_20 ) ;
F_40 ( V_15 , V_110 , 0 , - 1 ) ;
return;
}
V_93 = V_110 -> V_145 ;
F_17 ( & V_34 -> V_51 . V_117 , V_38 ) ;
V_131 = F_31 ( V_34 , V_93 ) ;
if ( ! F_12 ( V_34 ) &&
! F_70 ( V_110 ) ) {
switch ( V_132 ) {
case V_146 :
case V_147 :
case V_148 :
case V_149 :
V_17 = F_59 ( V_34 , V_131 ,
V_16 ) ;
V_137 -> V_38 |= V_150 ;
break;
case V_151 :
F_64 ( & V_34 -> V_152 , V_110 ) ;
F_20 ( & V_34 -> V_51 . V_117 ,
V_38 ) ;
return;
default:
V_111 = V_34 -> V_51 . V_52 [ V_131 ] . V_17 ;
if ( ! F_71 ( & V_111 ) )
V_17 = F_72 (
& V_111 , struct V_13 ,
V_19 ) ;
else
V_17 = NULL ;
break;
}
} else {
memcpy ( V_16 , V_110 -> V_116 , V_21 ) ;
if ( V_16 [ 0 ] & 0x01 || F_70 ( V_110 ) )
F_73 ( V_16 ) ;
V_17 = F_59 ( V_34 , V_131 , V_16 ) ;
}
if ( ! V_17 ) {
F_20 ( & V_34 -> V_51 . V_117 , V_38 ) ;
F_40 ( V_15 , V_110 , 0 , - 1 ) ;
return;
}
F_64 ( & V_17 -> V_20 , V_110 ) ;
V_17 -> V_49 ++ ;
V_17 -> V_22 ++ ;
if ( F_36 ( & V_34 -> V_51 . V_62 ) <
V_34 -> V_61 [ V_131 ] )
F_24 ( & V_34 -> V_51 . V_62 ,
V_34 -> V_61 [ V_131 ] ) ;
if ( V_17 -> V_45 )
V_34 -> V_51 . V_127 [ V_131 ] ++ ;
else
F_74 ( & V_34 -> V_51 . V_106 ) ;
F_20 ( & V_34 -> V_51 . V_117 , V_38 ) ;
}
int F_75 ( struct V_33 * V_34 ,
const struct V_153 * V_154 )
{
T_1 * V_155 = ( T_1 * ) & V_154 -> V_156 . V_157 ;
T_4 V_158 = F_3 ( V_154 -> V_159 ) , V_160 ;
int V_161 = V_76 ;
bool V_162 = true ;
struct V_163 * V_164 ;
struct V_165 * V_166 ;
struct V_64 * V_167 = NULL ;
struct V_85 * V_86 ;
F_8 ( V_34 -> V_15 , V_23 ,
L_21 ,
V_158 ) ;
while ( ( V_158 >= sizeof( V_164 -> V_168 ) ) && V_162 ) {
V_164 = (struct V_163 * ) V_155 ;
V_160 = F_3 ( V_164 -> V_168 . V_169 ) ;
if ( V_158 < V_160 + sizeof( V_164 -> V_168 ) )
break;
switch ( F_3 ( V_164 -> V_168 . type ) ) {
case V_170 :
V_166 =
(struct V_165 * )
V_164 ;
F_8 ( V_34 -> V_15 , V_171 ,
L_22
L_23 ,
V_166 -> V_172 ,
V_166 -> V_88 ,
V_166 -> V_87 ) ;
V_86 = & V_34 -> V_51 . V_86 [ V_166 ->
V_172 ] ;
V_86 -> V_87 = V_166 -> V_87 ;
V_86 -> V_88 =
V_166 -> V_88 ;
V_86 -> V_173 = V_166 -> V_173 ;
break;
case V_174 :
V_167 =
(struct V_64 * ) ( V_155 +
2 ) ;
V_167 -> V_73 . V_169 = ( T_1 ) V_160 ;
V_167 -> V_73 . V_175 =
V_174 ;
F_8 ( V_34 -> V_15 , V_171 ,
L_22
L_24 ,
V_167 -> V_75 & V_161 ) ;
memcpy ( ( T_1 * ) & V_34 -> V_176 . V_177 .
V_65 , V_167 ,
V_167 -> V_73 . V_169 + 2 ) ;
break;
default:
V_162 = false ;
break;
}
V_155 += ( V_160 + sizeof( V_164 -> V_168 ) ) ;
V_158 -= ( V_160 + sizeof( V_164 -> V_168 ) ) ;
}
F_25 ( V_34 , V_167 ) ;
F_29 ( V_34 ) ;
return 0 ;
}
T_2
F_76 ( struct V_33 * V_34 ,
T_1 * * V_178 ,
struct V_64 * V_65 ,
struct V_179 * V_180 )
{
struct V_181 * V_182 ;
T_2 V_183 = 0 ;
if ( ! V_178 )
return 0 ;
if ( ! ( * V_178 ) )
return 0 ;
if ( ! V_65 )
return 0 ;
F_8 ( V_34 -> V_15 , V_23 ,
L_25 ,
V_65 -> V_73 . V_175 ) ;
if ( ( V_34 -> V_184 ||
( V_180 && ( V_34 -> V_15 -> V_185 & V_186 ||
V_34 -> V_15 -> V_185 & V_187 ) ) ) &&
V_65 -> V_73 . V_175 == V_174 ) {
V_182 = (struct V_181 * ) * V_178 ;
V_182 -> V_168 . type = F_77 ( ( T_3 ) V_188 [ 0 ] ) ;
V_182 -> V_168 . V_169 = F_77 ( ( T_3 ) V_188 [ 1 ] ) ;
memcpy ( V_182 -> V_65 , & V_188 [ 2 ] ,
F_3 ( V_182 -> V_168 . V_169 ) ) ;
if ( V_65 -> V_75 & V_189 )
memcpy ( ( T_1 * ) ( V_182 -> V_65
+ F_3 ( V_182 -> V_168 . V_169 )
- sizeof( V_34 -> V_190 ) ) ,
& V_34 -> V_190 , sizeof( V_34 -> V_190 ) ) ;
V_183 = sizeof( V_182 -> V_168 )
+ F_3 ( V_182 -> V_168 . V_169 ) ;
* V_178 += V_183 ;
}
return V_183 ;
}
T_1
F_78 ( struct V_33 * V_34 ,
const struct V_109 * V_110 )
{
T_2 V_191 = F_79 ( F_80 ( V_110 -> V_192 ) ) ;
T_1 V_193 ;
V_193 = ( T_1 ) ( F_81 ( V_191 , V_34 -> V_51 . V_194 ) >> 1 ) ;
F_8 ( V_34 -> V_15 , V_48 , L_26
L_27 , V_191 , V_193 ) ;
return V_193 ;
}
static struct V_13 *
F_82 ( struct V_14 * V_15 ,
struct V_33 * * V_34 , int * V_93 )
{
struct V_33 * V_195 ;
struct V_13 * V_196 ;
struct V_197 * V_198 ;
T_5 * V_199 ;
unsigned long V_200 ;
int V_35 , V_69 ;
for ( V_69 = V_15 -> V_97 - 1 ; V_69 >= 0 ; -- V_69 ) {
F_42 (adapter->bss_prio_tbl[j].bss_prio_cur,
&adapter->bss_prio_tbl[j].bss_prio_head,
list) {
V_195 = V_15 -> V_201 [ V_69 ] . V_202 -> V_34 ;
if ( ! V_195 -> V_108 ||
( F_36 ( & V_195 -> V_51 . V_106 ) == 0 ) )
continue;
V_199 = & V_195 -> V_51 . V_62 ;
for ( V_35 = F_36 ( V_199 ) ; V_35 >= V_203 ; -- V_35 ) {
F_17 ( & V_195 -> V_51 .
V_117 , V_200 ) ;
V_198 = & ( V_195 ) -> V_51 .
V_52 [ V_59 [ V_35 ] ] ;
F_42 (ptr, &tid_ptr->ra_list,
list) {
if ( ! V_196 -> V_45 &&
! F_83 ( & V_196 -> V_20 ) )
goto V_204;
}
F_20 ( & V_195 -> V_51 .
V_117 ,
V_200 ) ;
}
}
}
return NULL ;
V_204:
if ( F_36 ( V_199 ) > V_35 )
F_24 ( V_199 , V_35 ) ;
F_20 ( & V_195 -> V_51 . V_117 , V_200 ) ;
* V_34 = V_195 ;
* V_93 = V_59 [ V_35 ] ;
return V_196 ;
}
void F_84 ( struct V_33 * V_34 ,
struct V_13 * V_16 ,
int V_93 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_205 * V_206 = V_15 -> V_201 ;
struct V_197 * V_198 = & V_34 -> V_51 . V_52 [ V_93 ] ;
unsigned long V_38 ;
F_17 ( & V_206 [ V_34 -> V_207 ] . V_208 , V_38 ) ;
F_85 ( & V_206 [ V_34 -> V_207 ] . V_209 ,
& V_206 [ V_34 -> V_207 ] . V_202 -> V_19 ) ;
F_20 ( & V_206 [ V_34 -> V_207 ] . V_208 , V_38 ) ;
F_17 ( & V_34 -> V_51 . V_117 , V_38 ) ;
if ( F_62 ( V_34 , V_16 , V_93 ) ) {
V_34 -> V_51 . V_210 [ V_93 ] ++ ;
F_85 ( & V_198 -> V_17 , & V_16 -> V_19 ) ;
}
F_20 ( & V_34 -> V_51 . V_117 , V_38 ) ;
}
static int
F_86 ( struct V_33 * V_34 ,
struct V_13 * V_196 ,
int V_211 )
{
int V_212 = 0 , V_213 = 0 ;
struct V_109 * V_110 , * V_68 ;
int V_214 ;
if ( V_34 -> V_215 == V_216 && V_34 -> V_217 &&
V_196 -> V_40 )
V_214 = F_87 ( int , V_196 -> V_47 , V_211 ) ;
else
V_214 = V_211 ;
F_39 (&ptr->skb_head, skb, tmp) {
V_213 += V_110 -> V_169 ;
if ( V_213 >= V_214 )
break;
if ( ++ V_212 >= V_218 )
return true ;
}
return false ;
}
static void
F_88 ( struct V_33 * V_34 ,
struct V_13 * V_196 , int V_128 ,
unsigned long V_219 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_89 ( struct V_33 * V_34 ,
struct V_13 * V_196 )
{
struct V_109 * V_110 ;
struct V_136 * V_137 ;
if ( F_83 ( & V_196 -> V_20 ) )
return false ;
V_110 = F_90 ( & V_196 -> V_20 ) ;
V_137 = F_66 ( V_110 ) ;
if ( V_137 -> V_38 & V_220 )
return true ;
return false ;
}
static void
F_91 ( struct V_33 * V_34 ,
struct V_13 * V_196 , int V_128 ,
unsigned long V_219 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_92 ( struct V_14 * V_15 )
{
struct V_13 * V_196 ;
struct V_33 * V_34 = NULL ;
int V_128 = 0 ;
T_1 V_16 [ V_21 ] ;
int V_221 = 0 , V_93 = 0 ;
unsigned long V_38 ;
V_196 = F_82 ( V_15 , & V_34 , & V_128 ) ;
if ( ! V_196 )
return - 1 ;
V_93 = F_93 ( V_196 ) ;
F_8 ( V_15 , V_48 , L_28 , V_93 ) ;
F_17 ( & V_34 -> V_51 . V_117 , V_38 ) ;
if ( ! F_62 ( V_34 , V_196 , V_128 ) ) {
F_20 ( & V_34 -> V_51 . V_117 , V_38 ) ;
return - 1 ;
}
if ( F_89 ( V_34 , V_196 ) ) {
F_91 ( V_34 , V_196 , V_128 , V_38 ) ;
return 0 ;
}
if ( ! V_196 -> V_40 ||
V_196 -> V_42 ||
V_34 -> V_222 . V_223 ) {
if ( V_196 -> V_40 &&
V_196 -> V_42 &&
V_196 -> V_44 &&
F_94 ( V_34 , V_93 ) &&
F_86 ( V_34 , V_196 ,
V_15 -> V_99 ) )
F_95 ( V_34 , V_196 , V_128 , V_38 ) ;
else
F_88 ( V_34 , V_196 , V_128 , V_38 ) ;
} else {
if ( F_96 ( V_34 , V_196 , V_93 ) &&
V_196 -> V_49 > V_196 -> V_50 ) {
if ( F_97 ( V_15 ) ) {
F_98 ( V_34 , V_196 -> V_16 , V_93 ,
V_224 ) ;
F_99 ( V_34 , V_93 , V_196 -> V_16 ) ;
} else if ( F_100
( V_34 , V_93 , & V_221 , V_16 ) ) {
F_98 ( V_34 , V_196 -> V_16 , V_93 ,
V_224 ) ;
F_101 ( V_34 , V_221 , V_16 , 1 ) ;
}
}
if ( F_94 ( V_34 , V_93 ) &&
F_86 ( V_34 , V_196 ,
V_15 -> V_99 ) )
F_95 ( V_34 , V_196 , V_128 , V_38 ) ;
else
F_88 ( V_34 , V_196 , V_128 , V_38 ) ;
}
return 0 ;
}
void F_102 ( struct V_14 * V_15 )
{
struct V_225 V_226 ;
struct V_109 * V_110 ;
struct V_136 * V_137 ;
struct V_33 * V_34 ;
int V_35 ;
if ( V_15 -> V_227 || V_15 -> V_228 )
return;
for ( V_35 = 0 ; V_35 < V_15 -> V_97 ; ++ V_35 ) {
V_34 = V_15 -> V_34 [ V_35 ] ;
if ( F_83 ( & V_34 -> V_130 ) )
continue;
V_110 = F_103 ( & V_34 -> V_130 ) ;
V_137 = F_66 ( V_110 ) ;
V_226 . V_229 = 0 ;
if ( F_104 ( V_34 , V_110 , & V_226 ) == - V_230 ) {
F_105 ( & V_34 -> V_130 , V_110 ) ;
V_137 -> V_38 |= V_220 ;
} else {
F_106 ( & V_15 -> V_107 ) ;
}
}
}
void
F_107 ( struct V_14 * V_15 )
{
do {
if ( F_92 ( V_15 ) )
break;
if ( V_15 -> V_231 != V_232 ) {
if ( V_15 -> V_227 ||
V_15 -> V_228 )
break;
} else {
if ( F_36 ( & V_15 -> V_233 ) >=
V_234 )
break;
}
} while ( ! F_37 ( V_15 ) );
}
