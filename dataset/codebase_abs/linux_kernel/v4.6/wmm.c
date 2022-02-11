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
T_2 V_24 ;
V_24 = F_10 () ;
V_24 += ( V_24 >> 32 ) + ( V_24 >> 16 ) ;
return ( ( T_1 ) V_24 % V_25 ) + V_26 ;
}
void F_11 ( struct V_27 * V_28 , const T_1 * V_16 )
{
int V_29 ;
struct V_13 * V_17 ;
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_30 * V_31 ;
unsigned long V_32 ;
for ( V_29 = 0 ; V_29 < V_33 ; ++ V_29 ) {
V_17 = F_4 ( V_15 , V_16 ) ;
F_8 ( V_15 , V_23 ,
L_8 , V_17 ) ;
if ( ! V_17 )
break;
V_17 -> V_34 = 0 ;
V_17 -> V_35 = false ;
V_17 -> V_36 = V_37 ;
V_17 -> V_38 = false ;
if ( ! F_12 ( V_28 ) ) {
if ( F_13
( F_14 ( V_28 , V_16 ) ) ) {
V_17 -> V_35 = true ;
V_17 -> V_34 =
F_15 ( V_28 , V_16 ) ;
} else {
V_17 -> V_34 = F_16 ( V_28 ) ;
}
} else {
F_17 ( & V_28 -> V_39 , V_32 ) ;
V_31 = F_18 ( V_28 , V_16 ) ;
if ( V_31 )
V_17 -> V_40 = V_31 -> V_41 ;
V_17 -> V_34 =
F_19 ( V_28 , V_31 ) ;
if ( V_17 -> V_34 )
V_17 -> V_42 = V_31 -> V_42 ;
F_20 ( & V_28 -> V_39 , V_32 ) ;
}
F_8 ( V_15 , V_43 , L_9 ,
V_17 , V_17 -> V_34 ) ;
if ( V_17 -> V_34 ) {
V_17 -> V_44 = 0 ;
V_17 -> V_45 =
F_9 () ;
}
F_21 ( & V_17 -> V_19 ,
& V_28 -> V_46 . V_47 [ V_29 ] . V_17 ) ;
}
}
static void F_22 ( struct V_27 * V_28 )
{
V_28 -> V_46 . V_48 [ 0 ] = V_49 ;
V_28 -> V_46 . V_48 [ 1 ] = V_50 ;
V_28 -> V_46 . V_48 [ 2 ] = V_51 ;
V_28 -> V_46 . V_48 [ 3 ] = V_52 ;
}
static void
F_23 ( struct V_27 * V_28 )
{
struct V_53 * V_46 = & V_28 -> V_46 ;
T_1 * V_48 = V_46 -> V_48 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 4 ; ++ V_29 ) {
V_54 [ 7 - ( V_29 * 2 ) ] = V_55 [ V_48 [ V_29 ] ] [ 1 ] ;
V_54 [ 6 - ( V_29 * 2 ) ] = V_55 [ V_48 [ V_29 ] ] [ 0 ] ;
}
for ( V_29 = 0 ; V_29 < V_33 ; ++ V_29 )
V_28 -> V_56 [ V_54 [ V_29 ] ] = ( T_1 ) V_29 ;
F_24 ( & V_46 -> V_57 , V_58 ) ;
}
void
F_25 ( struct V_27 * V_28 ,
struct V_59 * V_60 )
{
T_3 V_61 , V_62 , V_63 [ 4 ] ;
T_4 V_29 , V_64 , V_65 ;
T_1 V_66 ;
if ( ! V_60 || ! V_28 -> V_67 ) {
F_22 ( V_28 ) ;
return;
}
F_8 ( V_28 -> V_15 , V_23 ,
L_10
L_11 ,
V_60 -> V_68 . V_69 , V_60 -> V_70 &
V_71 ,
V_60 -> V_72 ) ;
for ( V_65 = 0 ; V_65 < F_26 ( V_60 -> V_73 ) ; V_65 ++ ) {
T_1 V_74 = V_60 -> V_73 [ V_65 ] . V_9 ;
T_1 V_75 = V_60 -> V_73 [ V_65 ] . V_5 ;
V_61 = ( 1 << ( V_74 & V_10 ) ) - 1 ;
V_62 = ( V_61 >> 1 ) + ( V_75 & V_8 ) ;
V_66 = V_4 [ ( V_75 & V_6 ) >> 5 ] ;
V_28 -> V_46 . V_48 [ V_66 ] = V_66 ;
V_63 [ V_66 ] = V_62 ;
F_8 ( V_28 -> V_15 , V_23 ,
L_12 ,
( 1 << ( ( V_74 & V_11 ) >> 4 ) ) - 1 ,
V_61 , V_62 ) ;
F_1 ( & V_60 -> V_73 [ V_65 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_65 ; V_29 ++ ) {
for ( V_64 = 1 ; V_64 < V_65 - V_29 ; V_64 ++ ) {
if ( V_63 [ V_64 - 1 ] > V_63 [ V_64 ] ) {
F_27 ( V_63 [ V_64 - 1 ] , V_63 [ V_64 ] ) ;
F_27 ( V_28 -> V_46 . V_48 [ V_64 - 1 ] ,
V_28 -> V_46 . V_48 [ V_64 ] ) ;
} else if ( V_63 [ V_64 - 1 ] == V_63 [ V_64 ] ) {
if ( V_28 -> V_46 . V_48 [ V_64 - 1 ]
< V_28 -> V_46 . V_48 [ V_64 ] )
F_27 ( V_28 -> V_46 . V_48 [ V_64 - 1 ] ,
V_28 -> V_46 . V_48 [ V_64 ] ) ;
}
}
}
F_23 ( V_28 ) ;
}
static enum V_76
F_28 ( struct V_27 * V_28 ,
enum V_76 V_77 )
{
int V_78 ;
enum V_76 V_79 ;
struct V_80 * V_81 ;
V_81 = & V_28 -> V_46 . V_81 [ V_77 ] ;
if ( ! V_81 -> V_82 )
return V_77 ;
V_79 = V_52 ;
for ( V_78 = V_52 ; V_78 < V_77 ; V_78 ++ ) {
V_81 = & V_28 -> V_46 . V_81 [ V_78 ] ;
if ( ! V_81 -> V_82 && ! V_81 -> V_83 )
V_79 = (enum V_76 ) V_78 ;
}
return V_79 ;
}
void
F_29 ( struct V_27 * V_28 )
{
int V_84 ;
F_8 ( V_28 -> V_15 , V_23 , L_13
L_14 ) ;
if ( ! V_28 -> V_67 ) {
for ( V_84 = V_52 ; V_84 <= V_49 ; V_84 ++ )
V_28 -> V_46 . V_85 [ V_84 ] =
(enum V_76 ) V_84 ;
} else {
for ( V_84 = V_52 ; V_84 <= V_49 ; V_84 ++ ) {
V_28 -> V_46 . V_85 [ V_84 ]
= F_28 ( V_28 ,
(enum V_76 ) V_84 ) ;
F_8 ( V_28 -> V_15 , V_23 ,
L_15 ,
V_84 ,
V_28 -> V_46 . V_85 [ V_84 ] ) ;
}
}
}
static enum V_76
F_30 ( struct V_14 * V_15 , T_4 V_86 )
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
if ( V_86 >= F_26 ( V_87 ) )
return V_51 ;
return V_87 [ V_86 ] ;
}
T_1 F_31 ( struct V_27 * V_28 , T_4 V_88 )
{
enum V_76 V_89 , V_90 ;
T_1 V_91 ;
V_89 = F_30 ( V_28 -> V_15 , V_88 ) ;
V_90 = V_28 -> V_46 . V_85 [ V_89 ] ;
V_91 = V_55 [ V_90 ] [ V_88 % 2 ] ;
return V_91 ;
}
void
F_32 ( struct V_14 * V_15 )
{
int V_29 , V_64 ;
struct V_27 * V_28 ;
for ( V_64 = 0 ; V_64 < V_15 -> V_92 ; ++ V_64 ) {
V_28 = V_15 -> V_28 [ V_64 ] ;
if ( ! V_28 )
continue;
for ( V_29 = 0 ; V_29 < V_33 ; ++ V_29 ) {
if ( ! V_93 &&
V_15 -> V_94 > V_95 )
V_28 -> V_96 [ V_29 ] . V_97 =
V_28 -> V_56 [ V_29 ] ;
else
V_28 -> V_96 [ V_29 ] . V_97 =
V_98 ;
V_28 -> V_96 [ V_29 ] . V_99 =
V_28 -> V_56 [ V_29 ] ;
V_28 -> V_96 [ V_29 ] . V_100 =
V_28 -> V_56 [ V_29 ] ;
}
V_28 -> V_96 [ 6 ] . V_97
= V_28 -> V_96 [ 6 ] . V_99
= V_28 -> V_96 [ 6 ] . V_100
= V_98 ;
V_28 -> V_96 [ 7 ] . V_97 = V_28 -> V_96 [ 7 ] . V_99
= V_28 -> V_96 [ 7 ] . V_100
= V_98 ;
F_33 ( V_28 ) ;
F_34 ( V_28 ) ;
V_28 -> V_46 . V_101 = V_102 ;
F_24 ( & V_28 -> V_46 . V_103 , 0 ) ;
F_24 ( & V_28 -> V_46 . V_57 , V_58 ) ;
}
}
int F_35 ( struct V_14 * V_15 )
{
struct V_27 * V_28 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_15 -> V_92 ; V_29 ++ ) {
V_28 = V_15 -> V_28 [ V_29 ] ;
if ( ! V_28 )
continue;
if ( V_15 -> V_104 . V_105 &&
! V_15 -> V_104 . V_105 ( V_28 ) )
continue;
if ( ! F_36 ( & V_28 -> V_106 ) )
return false ;
}
return true ;
}
int
F_37 ( struct V_14 * V_15 )
{
int V_29 ;
struct V_27 * V_28 ;
for ( V_29 = 0 ; V_29 < V_15 -> V_92 ; ++ V_29 ) {
V_28 = V_15 -> V_28 [ V_29 ] ;
if ( ! V_28 )
continue;
if ( ! V_28 -> V_107 &&
( V_28 -> V_108 != V_109 ) )
continue;
if ( V_15 -> V_104 . V_105 &&
! V_15 -> V_104 . V_105 ( V_28 ) )
continue;
if ( F_38 ( & V_28 -> V_46 . V_103 ) )
return false ;
}
return true ;
}
static void
F_39 ( struct V_27 * V_28 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_110 * V_111 , * V_63 ;
F_40 (&ra_list->skb_head, skb, tmp)
F_41 ( V_15 , V_111 , 0 , - 1 ) ;
}
static void
F_42 ( struct V_27 * V_28 ,
struct V_112 * V_113 )
{
struct V_13 * V_17 ;
F_43 (ra_list, ra_list_head, list)
F_39 ( V_28 , V_17 ) ;
}
static void F_44 ( struct V_27 * V_28 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ )
F_42 ( V_28 , & V_28 -> V_46 . V_47 [ V_29 ] .
V_17 ) ;
F_24 ( & V_28 -> V_46 . V_103 , 0 ) ;
F_24 ( & V_28 -> V_46 . V_57 , V_58 ) ;
}
static void F_45 ( struct V_27 * V_28 )
{
struct V_13 * V_17 , * V_114 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_33 ; ++ V_29 ) {
F_8 ( V_28 -> V_15 , V_23 ,
L_16 , V_29 ) ;
F_46 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
F_47 ( & V_17 -> V_19 ) ;
F_48 ( V_17 ) ;
}
F_6 ( & V_28 -> V_46 . V_47 [ V_29 ] . V_17 ) ;
}
}
static int F_49 ( int V_115 , void * V_116 , void * V_117 )
{
F_50 ( L_17 ) ;
F_51 ( V_116 ) ;
return 0 ;
}
void
F_52 ( struct V_27 * V_28 )
{
unsigned long V_32 ;
struct V_110 * V_111 , * V_63 ;
F_53 ( V_28 ) ;
F_17 ( & V_28 -> V_46 . V_118 , V_32 ) ;
F_44 ( V_28 ) ;
F_54 ( V_28 ) ;
if ( V_28 -> V_15 -> V_104 . V_119 )
V_28 -> V_15 -> V_104 . V_119 ( V_28 -> V_15 ) ;
F_45 ( V_28 ) ;
memcpy ( V_54 , V_55 , sizeof( V_54 ) ) ;
if ( V_28 -> V_15 -> V_104 . V_120 &&
! V_28 -> V_15 -> V_121 )
V_28 -> V_15 -> V_104 . V_120 ( V_28 -> V_15 ) ;
F_20 ( & V_28 -> V_46 . V_118 , V_32 ) ;
F_40 (&priv->tdls_txq, skb, tmp)
F_41 ( V_28 -> V_15 , V_111 , 0 , - 1 ) ;
F_40 (&priv->bypass_txq, skb, tmp)
F_41 ( V_28 -> V_15 , V_111 , 0 , - 1 ) ;
F_24 ( & V_28 -> V_15 -> V_122 , 0 ) ;
F_55 ( & V_28 -> V_123 , F_49 , NULL ) ;
F_56 ( & V_28 -> V_123 ) ;
}
struct V_13 *
F_57 ( struct V_27 * V_28 , T_1 V_88 ,
const T_1 * V_124 )
{
struct V_13 * V_17 ;
F_43 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_124 , V_21 ) )
return V_17 ;
}
return NULL ;
}
void F_58 ( struct V_27 * V_28 , T_1 * V_125 ,
T_1 V_41 )
{
struct V_13 * V_17 ;
T_4 V_126 = 0 , V_103 ;
unsigned long V_32 ;
int V_29 ;
F_17 ( & V_28 -> V_46 . V_118 , V_32 ) ;
for ( V_29 = 0 ; V_29 < V_33 ; ++ V_29 ) {
V_17 = F_57 ( V_28 , V_29 , V_125 ) ;
if ( V_17 && V_17 -> V_40 != V_41 ) {
V_126 += V_17 -> V_22 ;
V_17 -> V_40 = V_41 ;
if ( V_41 )
V_28 -> V_46 . V_127 [ V_29 ] +=
V_17 -> V_22 ;
else
V_28 -> V_46 . V_127 [ V_29 ] -=
V_17 -> V_22 ;
}
}
if ( V_126 ) {
V_103 = F_38 ( & V_28 -> V_46 . V_103 ) ;
if ( V_41 )
V_103 -= V_126 ;
else
V_103 += V_126 ;
F_24 ( & V_28 -> V_46 . V_103 , V_103 ) ;
F_24 ( & V_28 -> V_46 . V_57 , V_58 ) ;
}
F_20 ( & V_28 -> V_46 . V_118 , V_32 ) ;
}
void F_59 ( struct V_27 * V_28 ,
T_1 * V_125 , T_1 V_41 )
{
struct V_13 * V_17 ;
T_4 V_126 = 0 , V_103 ;
unsigned long V_32 ;
int V_29 ;
F_17 ( & V_28 -> V_46 . V_118 , V_32 ) ;
for ( V_29 = 0 ; V_29 < V_33 ; ++ V_29 ) {
F_43 (ra_list, &priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_125 , V_21 ) )
continue;
if ( V_17 -> V_40 != V_41 ) {
V_126 += V_17 -> V_22 ;
V_17 -> V_40 = V_41 ;
if ( V_41 )
V_28 -> V_46 . V_127 [ V_29 ] +=
V_17 -> V_22 ;
else
V_28 -> V_46 . V_127 [ V_29 ] -=
V_17 -> V_22 ;
}
}
}
if ( V_126 ) {
V_103 = F_38 ( & V_28 -> V_46 . V_103 ) ;
if ( V_41 )
V_103 -= V_126 ;
else
V_103 += V_126 ;
F_24 ( & V_28 -> V_46 . V_103 , V_103 ) ;
F_24 ( & V_28 -> V_46 . V_57 , V_58 ) ;
}
F_20 ( & V_28 -> V_46 . V_118 , V_32 ) ;
}
struct V_13 *
F_60 ( struct V_27 * V_28 , T_1 V_88 ,
const T_1 * V_124 )
{
struct V_13 * V_17 ;
V_17 = F_57 ( V_28 , V_88 , V_124 ) ;
if ( V_17 )
return V_17 ;
F_11 ( V_28 , V_124 ) ;
return F_57 ( V_28 , V_88 , V_124 ) ;
}
void
F_61 ( struct V_27 * V_28 , const T_1 * V_124 )
{
struct V_13 * V_17 ;
unsigned long V_32 ;
int V_29 ;
F_17 ( & V_28 -> V_46 . V_118 , V_32 ) ;
for ( V_29 = 0 ; V_29 < V_33 ; ++ V_29 ) {
V_17 = F_57 ( V_28 , V_29 , V_124 ) ;
if ( ! V_17 )
continue;
F_39 ( V_28 , V_17 ) ;
if ( V_17 -> V_40 )
V_28 -> V_46 . V_127 [ V_29 ] -= V_17 -> V_22 ;
else
F_62 ( V_17 -> V_22 ,
& V_28 -> V_46 . V_103 ) ;
F_47 ( & V_17 -> V_19 ) ;
F_48 ( V_17 ) ;
}
F_20 ( & V_28 -> V_46 . V_118 , V_32 ) ;
}
int
F_63 ( struct V_27 * V_28 ,
struct V_13 * V_17 , int V_128 )
{
struct V_13 * V_129 ;
F_43 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_129 == V_17 )
return true ;
}
return false ;
}
void
F_64 ( struct V_27 * V_28 ,
struct V_110 * V_111 )
{
F_65 ( & V_28 -> V_106 , V_111 ) ;
}
void
F_66 ( struct V_27 * V_28 ,
struct V_110 * V_111 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
T_4 V_88 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_21 ] , V_130 ;
unsigned long V_32 ;
struct V_112 V_112 ;
int V_131 = V_132 ;
struct V_133 * V_134 = (struct V_133 * ) V_111 -> V_117 ;
struct V_135 * V_136 = F_67 ( V_111 ) ;
memcpy ( V_16 , V_134 -> V_137 , V_21 ) ;
if ( F_68 ( V_28 ) == V_138 &&
F_69 ( V_15 -> V_139 ) ) {
if ( F_70 ( V_134 -> V_140 ) == V_141 )
F_8 ( V_15 , V_43 ,
L_18
L_19 , V_16 ) ;
else if ( memcmp ( V_28 -> V_142 , V_16 , V_21 ) )
V_131 = F_14 ( V_28 , V_16 ) ;
}
if ( ! V_28 -> V_143 && ! F_71 ( V_111 ) ) {
F_8 ( V_15 , V_43 , L_20 ) ;
F_41 ( V_15 , V_111 , 0 , - 1 ) ;
return;
}
V_88 = V_111 -> V_144 ;
F_17 ( & V_28 -> V_46 . V_118 , V_32 ) ;
V_130 = F_31 ( V_28 , V_88 ) ;
if ( ! F_12 ( V_28 ) &&
! F_71 ( V_111 ) ) {
switch ( V_131 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_17 = F_60 ( V_28 , V_130 ,
V_16 ) ;
V_136 -> V_32 |= V_149 ;
break;
case V_150 :
F_65 ( & V_28 -> V_151 , V_111 ) ;
F_20 ( & V_28 -> V_46 . V_118 ,
V_32 ) ;
return;
default:
V_112 = V_28 -> V_46 . V_47 [ V_130 ] . V_17 ;
if ( ! F_72 ( & V_112 ) )
V_17 = F_73 (
& V_112 , struct V_13 ,
V_19 ) ;
else
V_17 = NULL ;
break;
}
} else {
memcpy ( V_16 , V_111 -> V_117 , V_21 ) ;
if ( V_16 [ 0 ] & 0x01 || F_71 ( V_111 ) )
F_74 ( V_16 ) ;
V_17 = F_60 ( V_28 , V_130 , V_16 ) ;
}
if ( ! V_17 ) {
F_20 ( & V_28 -> V_46 . V_118 , V_32 ) ;
F_41 ( V_15 , V_111 , 0 , - 1 ) ;
return;
}
F_65 ( & V_17 -> V_20 , V_111 ) ;
V_17 -> V_44 ++ ;
V_17 -> V_22 ++ ;
if ( F_38 ( & V_28 -> V_46 . V_57 ) <
V_28 -> V_56 [ V_130 ] )
F_24 ( & V_28 -> V_46 . V_57 ,
V_28 -> V_56 [ V_130 ] ) ;
if ( V_17 -> V_40 )
V_28 -> V_46 . V_127 [ V_130 ] ++ ;
else
F_75 ( & V_28 -> V_46 . V_103 ) ;
F_20 ( & V_28 -> V_46 . V_118 , V_32 ) ;
}
int F_76 ( struct V_27 * V_28 ,
const struct V_152 * V_153 )
{
T_1 * V_154 = ( T_1 * ) & V_153 -> V_155 . V_156 ;
T_5 V_157 = F_3 ( V_153 -> V_158 ) , V_159 ;
int V_160 = V_71 ;
bool V_161 = true ;
struct V_162 * V_163 ;
struct V_164 * V_165 ;
struct V_59 * V_166 = NULL ;
struct V_80 * V_81 ;
F_8 ( V_28 -> V_15 , V_23 ,
L_21 ,
V_157 ) ;
while ( ( V_157 >= sizeof( V_163 -> V_167 ) ) && V_161 ) {
V_163 = (struct V_162 * ) V_154 ;
V_159 = F_3 ( V_163 -> V_167 . V_168 ) ;
if ( V_157 < V_159 + sizeof( V_163 -> V_167 ) )
break;
switch ( F_3 ( V_163 -> V_167 . type ) ) {
case V_169 :
V_165 =
(struct V_164 * )
V_163 ;
F_8 ( V_28 -> V_15 , V_170 ,
L_22
L_23 ,
V_165 -> V_171 ,
V_165 -> V_83 ,
V_165 -> V_82 ) ;
V_81 = & V_28 -> V_46 . V_81 [ V_165 ->
V_171 ] ;
V_81 -> V_82 = V_165 -> V_82 ;
V_81 -> V_83 =
V_165 -> V_83 ;
V_81 -> V_172 = V_165 -> V_172 ;
break;
case V_173 :
V_166 =
(struct V_59 * ) ( V_154 +
2 ) ;
V_166 -> V_68 . V_168 = ( T_1 ) V_159 ;
V_166 -> V_68 . V_174 =
V_173 ;
F_8 ( V_28 -> V_15 , V_170 ,
L_22
L_24 ,
V_166 -> V_70 & V_160 ) ;
memcpy ( ( T_1 * ) & V_28 -> V_175 . V_176 .
V_60 , V_166 ,
V_166 -> V_68 . V_168 + 2 ) ;
break;
default:
V_161 = false ;
break;
}
V_154 += ( V_159 + sizeof( V_163 -> V_167 ) ) ;
V_157 -= ( V_159 + sizeof( V_163 -> V_167 ) ) ;
}
F_25 ( V_28 , V_166 ) ;
F_29 ( V_28 ) ;
return 0 ;
}
T_4
F_77 ( struct V_27 * V_28 ,
T_1 * * V_177 ,
struct V_59 * V_60 ,
struct V_178 * V_179 )
{
struct V_180 * V_181 ;
T_4 V_182 = 0 ;
if ( ! V_177 )
return 0 ;
if ( ! ( * V_177 ) )
return 0 ;
if ( ! V_60 )
return 0 ;
F_8 ( V_28 -> V_15 , V_23 ,
L_25 ,
V_60 -> V_68 . V_174 ) ;
if ( ( V_28 -> V_183 ||
( V_179 && ( V_28 -> V_15 -> V_184 & V_185 ||
V_28 -> V_15 -> V_184 & V_186 ) ) ) &&
V_60 -> V_68 . V_174 == V_173 ) {
V_181 = (struct V_180 * ) * V_177 ;
V_181 -> V_167 . type = F_78 ( ( T_3 ) V_187 [ 0 ] ) ;
V_181 -> V_167 . V_168 = F_78 ( ( T_3 ) V_187 [ 1 ] ) ;
memcpy ( V_181 -> V_60 , & V_187 [ 2 ] ,
F_3 ( V_181 -> V_167 . V_168 ) ) ;
if ( V_60 -> V_70 & V_188 )
memcpy ( ( T_1 * ) ( V_181 -> V_60
+ F_3 ( V_181 -> V_167 . V_168 )
- sizeof( V_28 -> V_189 ) ) ,
& V_28 -> V_189 , sizeof( V_28 -> V_189 ) ) ;
V_182 = sizeof( V_181 -> V_167 )
+ F_3 ( V_181 -> V_167 . V_168 ) ;
* V_177 += V_182 ;
}
return V_182 ;
}
T_1
F_79 ( struct V_27 * V_28 ,
const struct V_110 * V_111 )
{
T_4 V_190 = F_80 ( F_81 ( V_111 -> V_191 ) ) ;
T_1 V_192 ;
V_192 = ( T_1 ) ( F_82 ( V_190 , V_28 -> V_46 . V_101 ) >> 1 ) ;
F_8 ( V_28 -> V_15 , V_43 , L_26
L_27 , V_190 , V_192 ) ;
return V_192 ;
}
static struct V_13 *
F_83 ( struct V_14 * V_15 ,
struct V_27 * * V_28 , int * V_88 )
{
struct V_27 * V_193 ;
struct V_13 * V_194 ;
struct V_195 * V_196 ;
T_6 * V_197 ;
unsigned long V_198 ;
int V_29 , V_64 ;
for ( V_64 = V_15 -> V_92 - 1 ; V_64 >= 0 ; -- V_64 ) {
F_43 (adapter->bss_prio_tbl[j].bss_prio_cur,
&adapter->bss_prio_tbl[j].bss_prio_head,
list) {
V_193 = V_15 -> V_199 [ V_64 ] . V_200 -> V_28 ;
if ( ( ( V_193 -> V_108 != V_109 ) &&
! V_193 -> V_107 ) ||
( F_38 ( & V_193 -> V_46 . V_103 ) == 0 ) )
continue;
if ( V_15 -> V_104 . V_105 &&
! V_15 -> V_104 . V_105 ( V_193 ) )
continue;
V_197 = & V_193 -> V_46 . V_57 ;
for ( V_29 = F_38 ( V_197 ) ; V_29 >= V_201 ; -- V_29 ) {
F_17 ( & V_193 -> V_46 .
V_118 , V_198 ) ;
V_196 = & ( V_193 ) -> V_46 .
V_47 [ V_54 [ V_29 ] ] ;
F_43 (ptr, &tid_ptr->ra_list,
list) {
if ( ! V_194 -> V_40 &&
! F_36 ( & V_194 -> V_20 ) )
goto V_202;
}
F_20 ( & V_193 -> V_46 .
V_118 ,
V_198 ) ;
}
}
}
return NULL ;
V_202:
if ( F_38 ( V_197 ) > V_29 )
F_24 ( V_197 , V_29 ) ;
F_20 ( & V_193 -> V_46 . V_118 , V_198 ) ;
* V_28 = V_193 ;
* V_88 = V_54 [ V_29 ] ;
return V_194 ;
}
void F_84 ( struct V_27 * V_28 ,
struct V_13 * V_16 ,
int V_88 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_203 * V_204 = V_15 -> V_199 ;
struct V_195 * V_196 = & V_28 -> V_46 . V_47 [ V_88 ] ;
unsigned long V_32 ;
F_17 ( & V_204 [ V_28 -> V_205 ] . V_206 , V_32 ) ;
F_85 ( & V_204 [ V_28 -> V_205 ] . V_207 ,
& V_204 [ V_28 -> V_205 ] . V_200 -> V_19 ) ;
F_20 ( & V_204 [ V_28 -> V_205 ] . V_206 , V_32 ) ;
F_17 ( & V_28 -> V_46 . V_118 , V_32 ) ;
if ( F_63 ( V_28 , V_16 , V_88 ) ) {
V_28 -> V_46 . V_208 [ V_88 ] ++ ;
F_85 ( & V_196 -> V_17 , & V_16 -> V_19 ) ;
}
F_20 ( & V_28 -> V_46 . V_118 , V_32 ) ;
}
static int
F_86 ( struct V_27 * V_28 ,
struct V_13 * V_194 ,
int V_209 )
{
int V_210 = 0 , V_211 = 0 ;
struct V_110 * V_111 , * V_63 ;
int V_212 ;
if ( V_28 -> V_213 == V_214 && V_28 -> V_215 &&
V_194 -> V_34 )
V_212 = F_87 ( int , V_194 -> V_42 , V_209 ) ;
else
V_212 = V_209 ;
F_40 (&ptr->skb_head, skb, tmp) {
V_211 += V_111 -> V_168 ;
if ( V_211 >= V_212 )
break;
if ( ++ V_210 >= V_216 )
return true ;
}
return false ;
}
static void
F_88 ( struct V_27 * V_28 ,
struct V_13 * V_194 , int V_128 ,
unsigned long V_217 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_89 ( struct V_27 * V_28 ,
struct V_13 * V_194 )
{
struct V_110 * V_111 ;
struct V_135 * V_136 ;
if ( F_36 ( & V_194 -> V_20 ) )
return false ;
V_111 = F_90 ( & V_194 -> V_20 ) ;
V_136 = F_67 ( V_111 ) ;
if ( V_136 -> V_32 & V_218 )
return true ;
return false ;
}
static void
F_91 ( struct V_27 * V_28 ,
struct V_13 * V_194 , int V_128 ,
unsigned long V_217 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_92 ( struct V_14 * V_15 )
{
struct V_13 * V_194 ;
struct V_27 * V_28 = NULL ;
int V_128 = 0 ;
T_1 V_16 [ V_21 ] ;
int V_219 = 0 , V_88 = 0 ;
unsigned long V_32 ;
V_194 = F_83 ( V_15 , & V_28 , & V_128 ) ;
if ( ! V_194 )
return - 1 ;
V_88 = F_93 ( V_194 ) ;
F_8 ( V_15 , V_43 , L_28 , V_88 ) ;
F_17 ( & V_28 -> V_46 . V_118 , V_32 ) ;
if ( ! F_63 ( V_28 , V_194 , V_128 ) ) {
F_20 ( & V_28 -> V_46 . V_118 , V_32 ) ;
return - 1 ;
}
if ( F_89 ( V_28 , V_194 ) ) {
F_91 ( V_28 , V_194 , V_128 , V_32 ) ;
return 0 ;
}
if ( ! V_194 -> V_34 ||
V_194 -> V_36 ||
V_28 -> V_220 . V_221 ) {
if ( V_194 -> V_34 &&
V_194 -> V_36 &&
V_194 -> V_38 &&
F_94 ( V_28 , V_88 ) &&
F_86 ( V_28 , V_194 ,
V_15 -> V_94 ) )
F_95 ( V_28 , V_194 , V_128 , V_32 ) ;
else
F_88 ( V_28 , V_194 , V_128 , V_32 ) ;
} else {
if ( F_96 ( V_28 , V_194 , V_88 ) &&
V_194 -> V_44 > V_194 -> V_45 ) {
if ( F_97 ( V_15 ) ) {
F_98 ( V_28 , V_194 -> V_16 , V_88 ,
V_222 ) ;
F_99 ( V_28 , V_88 , V_194 -> V_16 ) ;
} else if ( F_100
( V_28 , V_88 , & V_219 , V_16 ) ) {
F_98 ( V_28 , V_194 -> V_16 , V_88 ,
V_222 ) ;
F_101 ( V_28 , V_219 , V_16 , 1 ) ;
}
}
if ( F_94 ( V_28 , V_88 ) &&
F_86 ( V_28 , V_194 ,
V_15 -> V_94 ) )
F_95 ( V_28 , V_194 , V_128 , V_32 ) ;
else
F_88 ( V_28 , V_194 , V_128 , V_32 ) ;
}
return 0 ;
}
void F_102 ( struct V_14 * V_15 )
{
struct V_223 V_224 ;
struct V_110 * V_111 ;
struct V_135 * V_136 ;
struct V_27 * V_28 ;
int V_29 ;
if ( V_15 -> V_225 || V_15 -> V_226 )
return;
for ( V_29 = 0 ; V_29 < V_15 -> V_92 ; ++ V_29 ) {
V_28 = V_15 -> V_28 [ V_29 ] ;
if ( ! V_28 )
continue;
if ( V_15 -> V_104 . V_105 &&
! V_15 -> V_104 . V_105 ( V_28 ) )
continue;
if ( F_36 ( & V_28 -> V_106 ) )
continue;
V_111 = F_103 ( & V_28 -> V_106 ) ;
V_136 = F_67 ( V_111 ) ;
V_224 . V_227 = 0 ;
if ( F_104 ( V_28 , V_111 , & V_224 ) == - V_228 ) {
F_105 ( & V_28 -> V_106 , V_111 ) ;
V_136 -> V_32 |= V_218 ;
} else {
F_106 ( & V_15 -> V_122 ) ;
}
}
}
void
F_107 ( struct V_14 * V_15 )
{
do {
if ( F_92 ( V_15 ) )
break;
if ( V_15 -> V_229 != V_230 ) {
if ( V_15 -> V_225 ||
V_15 -> V_226 )
break;
} else {
if ( F_38 ( & V_15 -> V_231 ) >=
V_232 )
break;
}
} while ( ! F_37 ( V_15 ) );
}
