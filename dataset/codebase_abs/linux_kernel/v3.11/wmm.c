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
}
}
static void F_19 ( struct V_33 * V_34 )
{
V_34 -> V_45 . V_47 [ 0 ] = V_48 ;
V_34 -> V_45 . V_47 [ 1 ] = V_49 ;
V_34 -> V_45 . V_47 [ 2 ] = V_50 ;
V_34 -> V_45 . V_47 [ 3 ] = V_51 ;
}
static void
F_20 ( struct V_52 * V_45 )
{
T_1 * V_47 = V_45 -> V_47 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 4 ; ++ V_35 ) {
V_53 [ 7 - ( V_35 * 2 ) ] = V_54 [ V_47 [ V_35 ] ] [ 1 ] ;
V_53 [ 6 - ( V_35 * 2 ) ] = V_54 [ V_47 [ V_35 ] ] [ 0 ] ;
}
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 )
V_55 [ V_53 [ V_35 ] ] = ( T_1 ) V_35 ;
F_21 ( & V_45 -> V_56 , V_57 ) ;
}
void
F_22 ( struct V_33 * V_34 ,
struct V_58 * V_59 )
{
T_3 V_60 , V_61 , V_62 [ 4 ] ;
T_2 V_35 , V_63 , V_64 ;
T_1 V_65 ;
if ( ! V_59 || ! V_34 -> V_66 ) {
F_19 ( V_34 ) ;
return;
}
F_8 ( V_34 -> V_15 -> V_23 , L_10
L_11 ,
V_59 -> V_67 . V_68 , V_59 -> V_69 &
V_70 ,
V_59 -> V_71 ) ;
for ( V_64 = 0 ; V_64 < F_23 ( V_59 -> V_72 ) ; V_64 ++ ) {
T_1 V_73 = V_59 -> V_72 [ V_64 ] . V_9 ;
T_1 V_74 = V_59 -> V_72 [ V_64 ] . V_5 ;
V_60 = ( 1 << ( V_73 & V_10 ) ) - 1 ;
V_61 = ( V_60 >> 1 ) + ( V_74 & V_8 ) ;
V_65 = V_4 [ ( V_74 & V_6 ) >> 5 ] ;
V_34 -> V_45 . V_47 [ V_65 ] = V_65 ;
V_62 [ V_65 ] = V_61 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_12 ,
( 1 << ( ( V_73 & V_11 ) >> 4 ) ) - 1 ,
V_60 , V_61 ) ;
F_1 ( & V_59 -> V_72 [ V_64 ] ) ;
}
for ( V_35 = 0 ; V_35 < V_64 ; V_35 ++ ) {
for ( V_63 = 1 ; V_63 < V_64 - V_35 ; V_63 ++ ) {
if ( V_62 [ V_63 - 1 ] > V_62 [ V_63 ] ) {
F_24 ( V_62 [ V_63 - 1 ] , V_62 [ V_63 ] ) ;
F_24 ( V_34 -> V_45 . V_47 [ V_63 - 1 ] ,
V_34 -> V_45 . V_47 [ V_63 ] ) ;
} else if ( V_62 [ V_63 - 1 ] == V_62 [ V_63 ] ) {
if ( V_34 -> V_45 . V_47 [ V_63 - 1 ]
< V_34 -> V_45 . V_47 [ V_63 ] )
F_24 ( V_34 -> V_45 . V_47 [ V_63 - 1 ] ,
V_34 -> V_45 . V_47 [ V_63 ] ) ;
}
}
}
F_20 ( & V_34 -> V_45 ) ;
}
static enum V_75
F_25 ( struct V_33 * V_34 ,
enum V_75 V_76 )
{
int V_77 ;
enum V_75 V_78 ;
struct V_79 * V_80 ;
V_80 = & V_34 -> V_45 . V_80 [ V_76 ] ;
if ( ! V_80 -> V_81 )
return V_76 ;
V_78 = V_51 ;
for ( V_77 = V_51 ; V_77 < V_76 ; V_77 ++ ) {
V_80 = & V_34 -> V_45 . V_80 [ V_77 ] ;
if ( ! V_80 -> V_81 && ! V_80 -> V_82 )
V_78 = (enum V_75 ) V_77 ;
}
return V_78 ;
}
void
F_26 ( struct V_33 * V_34 )
{
int V_83 ;
F_8 ( V_34 -> V_15 -> V_23 , L_13
L_14 ) ;
if ( ! V_34 -> V_66 ) {
for ( V_83 = V_51 ; V_83 <= V_48 ; V_83 ++ )
V_34 -> V_45 . V_84 [ V_83 ] =
(enum V_75 ) V_83 ;
} else {
for ( V_83 = V_51 ; V_83 <= V_48 ; V_83 ++ ) {
V_34 -> V_45 . V_84 [ V_83 ]
= F_25 ( V_34 ,
(enum V_75 ) V_83 ) ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_15 ,
V_83 , V_34 -> V_45 . V_84 [ V_83 ] ) ;
}
}
}
static enum V_75
F_27 ( struct V_14 * V_15 , T_2 V_85 )
{
const enum V_75 V_86 [] = { V_50 ,
V_51 ,
V_51 ,
V_50 ,
V_49 ,
V_49 ,
V_48 ,
V_48
} ;
if ( V_85 >= F_23 ( V_86 ) )
return V_50 ;
return V_86 [ V_85 ] ;
}
static T_1
F_28 ( struct V_33 * V_34 , T_2 V_87 )
{
enum V_75 V_88 , V_89 ;
T_1 V_90 ;
V_88 = F_27 ( V_34 -> V_15 , V_87 ) ;
V_89 = V_34 -> V_45 . V_84 [ V_88 ] ;
V_90 = V_54 [ V_89 ] [ V_87 % 2 ] ;
return V_90 ;
}
void
F_29 ( struct V_14 * V_15 )
{
int V_35 , V_63 ;
struct V_33 * V_34 ;
for ( V_63 = 0 ; V_63 < V_15 -> V_91 ; ++ V_63 ) {
V_34 = V_15 -> V_34 [ V_63 ] ;
if ( ! V_34 )
continue;
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 ) {
V_34 -> V_92 [ V_35 ] . V_93 = V_55 [ V_35 ] ;
V_34 -> V_92 [ V_35 ] . V_94 = V_55 [ V_35 ] ;
V_34 -> V_92 [ V_35 ] . V_95 = V_55 [ V_35 ] ;
}
V_34 -> V_92 [ 6 ] . V_93
= V_34 -> V_92 [ 6 ] . V_94
= V_34 -> V_92 [ 6 ] . V_95
= V_96 ;
V_34 -> V_92 [ 7 ] . V_93 = V_34 -> V_92 [ 7 ] . V_94
= V_34 -> V_92 [ 7 ] . V_95
= V_96 ;
F_30 ( V_34 ) ;
F_31 ( V_34 ) ;
F_21 ( & V_34 -> V_45 . V_97 , 0 ) ;
F_21 ( & V_34 -> V_45 . V_56 , V_57 ) ;
}
}
int
F_32 ( struct V_14 * V_15 )
{
int V_35 ;
struct V_33 * V_34 ;
for ( V_35 = 0 ; V_35 < V_15 -> V_91 ; ++ V_35 ) {
V_34 = V_15 -> V_34 [ V_35 ] ;
if ( V_34 && F_33 ( & V_34 -> V_45 . V_97 ) )
return false ;
}
return true ;
}
static void
F_34 ( struct V_33 * V_34 ,
struct V_13 * V_17 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_98 * V_99 , * V_62 ;
F_35 (&ra_list->skb_head, skb, tmp)
F_36 ( V_15 , V_99 , 0 , - 1 ) ;
}
static void
F_37 ( struct V_33 * V_34 ,
struct V_100 * V_101 )
{
struct V_13 * V_17 ;
F_38 (ra_list, ra_list_head, list)
F_34 ( V_34 , V_17 ) ;
}
static void F_39 ( struct V_33 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_40 ; V_35 ++ )
F_37 ( V_34 , & V_34 -> V_45 . V_46 [ V_35 ] .
V_17 ) ;
F_21 ( & V_34 -> V_45 . V_97 , 0 ) ;
F_21 ( & V_34 -> V_45 . V_56 , V_57 ) ;
}
static void F_40 ( struct V_33 * V_34 )
{
struct V_13 * V_17 , * V_102 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_40 ; ++ V_35 ) {
F_8 ( V_34 -> V_15 -> V_23 ,
L_16 , V_35 ) ;
F_41 (ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list,
list) {
F_42 ( & V_17 -> V_19 ) ;
F_43 ( V_17 ) ;
}
F_6 ( & V_34 -> V_45 . V_46 [ V_35 ] . V_17 ) ;
}
}
void
F_44 ( struct V_33 * V_34 )
{
unsigned long V_38 ;
F_45 ( V_34 ) ;
F_12 ( & V_34 -> V_45 . V_103 , V_38 ) ;
F_39 ( V_34 ) ;
F_46 ( V_34 ) ;
if ( V_34 -> V_15 -> V_104 . V_105 )
V_34 -> V_15 -> V_104 . V_105 ( V_34 -> V_15 ) ;
F_40 ( V_34 ) ;
memcpy ( V_53 , V_54 , sizeof( V_53 ) ) ;
if ( V_34 -> V_15 -> V_104 . V_106 )
V_34 -> V_15 -> V_104 . V_106 ( V_34 -> V_15 ) ;
F_14 ( & V_34 -> V_45 . V_103 , V_38 ) ;
}
static struct V_13 *
F_47 ( struct V_33 * V_34 , T_1 V_87 ,
T_1 * V_107 )
{
struct V_13 * V_17 ;
F_38 (ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if ( ! memcmp ( V_17 -> V_16 , V_107 , V_21 ) )
return V_17 ;
}
return NULL ;
}
static struct V_13 *
F_48 ( struct V_33 * V_34 , T_1 V_87 , T_1 * V_107 )
{
struct V_13 * V_17 ;
V_17 = F_47 ( V_34 , V_87 , V_107 ) ;
if ( V_17 )
return V_17 ;
F_11 ( V_34 , V_107 ) ;
return F_47 ( V_34 , V_87 , V_107 ) ;
}
int
F_49 ( struct V_33 * V_34 ,
struct V_13 * V_17 , int V_108 )
{
struct V_13 * V_109 ;
F_38 (rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if ( V_109 == V_17 )
return true ;
}
return false ;
}
void
F_50 ( struct V_33 * V_34 ,
struct V_98 * V_99 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
T_2 V_87 ;
struct V_13 * V_17 ;
T_1 V_16 [ V_21 ] , V_110 ;
unsigned long V_38 ;
if ( ! V_34 -> V_111 && ! F_51 ( V_99 ) ) {
F_8 ( V_15 -> V_23 , L_17 ) ;
F_36 ( V_15 , V_99 , 0 , - 1 ) ;
return;
}
V_87 = V_99 -> V_112 ;
F_12 ( & V_34 -> V_45 . V_103 , V_38 ) ;
V_110 = F_28 ( V_34 , V_87 ) ;
if ( ! F_15 ( V_34 ) &&
! F_51 ( V_99 ) ) {
if ( ! F_52 ( & V_34 -> V_45 . V_46 [ V_110 ] . V_17 ) )
V_17 = F_53 (
& V_34 -> V_45 . V_46 [ V_110 ] . V_17 ,
struct V_13 , V_19 ) ;
else
V_17 = NULL ;
} else {
memcpy ( V_16 , V_99 -> V_113 , V_21 ) ;
if ( V_16 [ 0 ] & 0x01 || F_51 ( V_99 ) )
memset ( V_16 , 0xff , V_21 ) ;
V_17 = F_48 ( V_34 , V_110 , V_16 ) ;
}
if ( ! V_17 ) {
F_14 ( & V_34 -> V_45 . V_103 , V_38 ) ;
F_36 ( V_15 , V_99 , 0 , - 1 ) ;
return;
}
F_54 ( & V_17 -> V_20 , V_99 ) ;
V_17 -> V_22 += V_99 -> V_114 ;
V_17 -> V_43 ++ ;
if ( F_33 ( & V_34 -> V_45 . V_56 ) <
V_55 [ V_110 ] )
F_21 ( & V_34 -> V_45 . V_56 ,
V_55 [ V_110 ] ) ;
F_55 ( & V_34 -> V_45 . V_97 ) ;
F_14 ( & V_34 -> V_45 . V_103 , V_38 ) ;
}
int F_56 ( struct V_33 * V_34 ,
const struct V_115 * V_116 )
{
T_1 * V_117 = ( T_1 * ) & V_116 -> V_118 . V_119 ;
T_4 V_120 = F_3 ( V_116 -> V_121 ) , V_122 ;
int V_123 = true ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
struct V_58 * V_128 = NULL ;
struct V_79 * V_80 ;
F_8 ( V_34 -> V_15 -> V_23 , L_18 ,
V_120 ) ;
while ( ( V_120 >= sizeof( V_125 -> V_129 ) ) && V_123 ) {
V_125 = (struct V_124 * ) V_117 ;
V_122 = F_3 ( V_125 -> V_129 . V_114 ) ;
switch ( F_3 ( V_125 -> V_129 . type ) ) {
case V_130 :
V_127 =
(struct V_126 * )
V_125 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_19
L_20 ,
V_127 -> V_131 ,
V_127 -> V_82 ,
V_127 -> V_81 ) ;
V_80 = & V_34 -> V_45 . V_80 [ V_127 ->
V_131 ] ;
V_80 -> V_81 = V_127 -> V_81 ;
V_80 -> V_82 =
V_127 -> V_82 ;
V_80 -> V_132 = V_127 -> V_132 ;
break;
case V_133 :
V_128 =
(struct V_58 * ) ( V_117 +
2 ) ;
V_128 -> V_67 . V_114 = ( T_1 ) V_122 ;
V_128 -> V_67 . V_134 =
V_133 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_19
L_21 ,
V_128 -> V_69 &
V_70 ) ;
memcpy ( ( T_1 * ) & V_34 -> V_135 . V_136 .
V_59 , V_128 ,
V_128 -> V_67 . V_114 + 2 ) ;
break;
default:
V_123 = false ;
break;
}
V_117 += ( V_122 + sizeof( V_125 -> V_129 ) ) ;
V_120 -= ( V_122 + sizeof( V_125 -> V_129 ) ) ;
}
F_22 ( V_34 , V_128 ) ;
F_26 ( V_34 ) ;
return 0 ;
}
T_2
F_57 ( struct V_33 * V_34 ,
T_1 * * V_137 ,
struct V_58 * V_59 ,
struct V_138 * V_139 )
{
struct V_140 * V_141 ;
T_2 V_142 = 0 ;
if ( ! V_137 )
return 0 ;
if ( ! ( * V_137 ) )
return 0 ;
if ( ! V_59 )
return 0 ;
F_8 ( V_34 -> V_15 -> V_23 ,
L_22 ,
V_59 -> V_67 . V_134 ) ;
if ( ( V_34 -> V_143 ||
( V_139 && ( V_34 -> V_15 -> V_144 & V_145 ||
V_34 -> V_15 -> V_144 & V_146 ) ) ) &&
V_59 -> V_67 . V_134 == V_133 ) {
V_141 = (struct V_140 * ) * V_137 ;
V_141 -> V_129 . type = F_58 ( ( T_3 ) V_147 [ 0 ] ) ;
V_141 -> V_129 . V_114 = F_58 ( ( T_3 ) V_147 [ 1 ] ) ;
memcpy ( V_141 -> V_59 , & V_147 [ 2 ] ,
F_3 ( V_141 -> V_129 . V_114 ) ) ;
if ( V_59 -> V_69 & V_148 )
memcpy ( ( T_1 * ) ( V_141 -> V_59
+ F_3 ( V_141 -> V_129 . V_114 )
- sizeof( V_34 -> V_149 ) ) ,
& V_34 -> V_149 , sizeof( V_34 -> V_149 ) ) ;
V_142 = sizeof( V_141 -> V_129 )
+ F_3 ( V_141 -> V_129 . V_114 ) ;
* V_137 += V_142 ;
}
return V_142 ;
}
T_1
F_59 ( struct V_33 * V_34 ,
const struct V_98 * V_99 )
{
T_1 V_150 ;
struct V_26 V_151 , V_152 ;
T_2 V_153 ;
F_10 ( & V_151 ) ;
V_152 = F_60 ( V_99 -> V_154 ) ;
V_153 = ( V_151 . V_29 - V_152 . V_29 ) * 1000 ;
V_153 += ( V_151 . V_30 - V_152 . V_30 ) / 1000 ;
V_150 = ( T_1 ) ( F_61 ( V_153 , V_34 -> V_45 . V_155 ) >> 1 ) ;
F_8 ( V_34 -> V_15 -> V_23 , L_23
L_24 , V_153 , V_150 ) ;
return V_150 ;
}
static struct V_13 *
F_62 ( struct V_14 * V_15 ,
struct V_33 * * V_34 , int * V_87 )
{
struct V_33 * V_156 ;
struct V_13 * V_157 ;
struct V_158 * V_159 ;
T_5 * V_160 ;
unsigned long V_161 , V_162 ;
int V_35 , V_63 ;
for ( V_63 = V_15 -> V_91 - 1 ; V_63 >= 0 ; -- V_63 ) {
F_12 ( & V_15 -> V_163 [ V_63 ] . V_164 ,
V_161 ) ;
F_38 (adapter->bss_prio_tbl[j].bss_prio_cur,
&adapter->bss_prio_tbl[j].bss_prio_head,
list) {
V_156 = V_15 -> V_163 [ V_63 ] . V_165 -> V_34 ;
if ( F_33 ( & V_156 -> V_45 . V_97 ) == 0 )
continue;
V_160 = & V_156 -> V_45 . V_56 ;
for ( V_35 = F_33 ( V_160 ) ; V_35 >= V_166 ; -- V_35 ) {
F_12 ( & V_156 -> V_45 .
V_103 , V_162 ) ;
V_159 = & ( V_156 ) -> V_45 .
V_46 [ V_53 [ V_35 ] ] ;
F_38 (ptr, &tid_ptr->ra_list,
list) {
if ( ! F_63 ( & V_157 -> V_20 ) )
goto V_167;
}
F_14 ( & V_156 -> V_45 .
V_103 ,
V_162 ) ;
}
}
F_14 ( & V_15 -> V_163 [ V_63 ] . V_164 ,
V_161 ) ;
}
return NULL ;
V_167:
if ( F_33 ( V_160 ) > V_35 )
F_21 ( V_160 , V_35 ) ;
F_14 ( & V_156 -> V_45 . V_103 , V_162 ) ;
F_14 ( & V_15 -> V_163 [ V_63 ] . V_164 ,
V_161 ) ;
* V_34 = V_156 ;
* V_87 = V_53 [ V_35 ] ;
return V_157 ;
}
void F_64 ( struct V_33 * V_34 ,
struct V_13 * V_16 ,
int V_87 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_168 * V_169 = V_15 -> V_163 ;
struct V_158 * V_159 = & V_34 -> V_45 . V_46 [ V_87 ] ;
unsigned long V_38 ;
F_12 ( & V_169 [ V_34 -> V_170 ] . V_164 , V_38 ) ;
F_65 ( & V_169 [ V_34 -> V_170 ] . V_171 ,
& V_169 [ V_34 -> V_170 ] . V_165 -> V_19 ) ;
F_14 ( & V_169 [ V_34 -> V_170 ] . V_164 , V_38 ) ;
F_12 ( & V_34 -> V_45 . V_103 , V_38 ) ;
if ( F_49 ( V_34 , V_16 , V_87 ) ) {
V_34 -> V_45 . V_172 [ V_87 ] ++ ;
F_65 ( & V_159 -> V_17 , & V_16 -> V_19 ) ;
}
F_14 ( & V_34 -> V_45 . V_103 , V_38 ) ;
}
static int
F_66 ( struct V_33 * V_34 ,
struct V_13 * V_157 ,
int V_173 )
{
int V_174 = 0 , V_175 = 0 ;
struct V_98 * V_99 , * V_62 ;
int V_176 ;
if ( V_34 -> V_177 == V_178 && V_34 -> V_179 &&
V_157 -> V_41 )
V_176 = F_67 ( int , V_157 -> V_42 , V_173 ) ;
else
V_176 = V_173 ;
F_35 (&ptr->skb_head, skb, tmp) {
V_175 += V_99 -> V_114 ;
if ( V_175 >= V_176 )
break;
if ( ++ V_174 >= V_180 )
return true ;
}
return false ;
}
static void
F_68 ( struct V_33 * V_34 ,
struct V_13 * V_157 , int V_108 ,
unsigned long V_181 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_69 ( struct V_33 * V_34 ,
struct V_13 * V_157 )
{
struct V_98 * V_99 ;
struct V_182 * V_183 ;
if ( F_63 ( & V_157 -> V_20 ) )
return false ;
V_99 = F_70 ( & V_157 -> V_20 ) ;
V_183 = F_71 ( V_99 ) ;
if ( V_183 -> V_38 & V_184 )
return true ;
return false ;
}
static void
F_72 ( struct V_33 * V_34 ,
struct V_13 * V_157 , int V_108 ,
unsigned long V_181 )
__releases( &priv->wmm.ra_list_spinlock
static int
F_73 ( struct V_14 * V_15 )
{
struct V_13 * V_157 ;
struct V_33 * V_34 = NULL ;
int V_108 = 0 ;
T_1 V_16 [ V_21 ] ;
int V_185 = 0 , V_87 = 0 ;
unsigned long V_38 ;
V_157 = F_62 ( V_15 , & V_34 , & V_108 ) ;
if ( ! V_157 )
return - 1 ;
V_87 = F_74 ( V_157 ) ;
F_8 ( V_15 -> V_23 , L_25 , V_87 ) ;
F_12 ( & V_34 -> V_45 . V_103 , V_38 ) ;
if ( ! F_49 ( V_34 , V_157 , V_108 ) ) {
F_14 ( & V_34 -> V_45 . V_103 , V_38 ) ;
return - 1 ;
}
if ( F_69 ( V_34 , V_157 ) ) {
F_72 ( V_34 , V_157 , V_108 , V_38 ) ;
return 0 ;
}
if ( ! V_157 -> V_41 ||
F_75 ( V_34 , V_157 , V_87 ) ||
V_34 -> V_186 . V_187 ||
( ( V_34 -> V_188 . V_189 ||
V_34 -> V_188 . V_190 ) &&
! V_34 -> V_191 ) ) {
F_68 ( V_34 , V_157 , V_108 , V_38 ) ;
} else {
if ( F_76 ( V_34 , V_87 ) &&
V_157 -> V_43 > V_157 -> V_44 ) {
if ( F_77 ( V_15 ) ) {
F_78 ( V_34 , V_157 -> V_16 , V_87 ,
V_192 ) ;
F_79 ( V_34 , V_87 , V_157 -> V_16 ) ;
} else if ( F_80
( V_34 , V_87 , & V_185 , V_16 ) ) {
F_78 ( V_34 , V_157 -> V_16 , V_87 ,
V_192 ) ;
F_81 ( V_34 , V_185 , V_16 , 1 ) ;
}
}
if ( V_193 && F_82 ( V_34 , V_87 ) &&
F_66 ( V_34 , V_157 ,
V_15 -> V_194 ) )
F_83 ( V_34 , V_157 , V_195 ,
V_108 , V_38 ) ;
else
F_68 ( V_34 , V_157 , V_108 , V_38 ) ;
}
return 0 ;
}
void
F_84 ( struct V_14 * V_15 )
{
do {
if ( V_15 -> V_196 || V_15 -> V_197 )
break;
if ( F_73 ( V_15 ) )
break;
} while ( ! F_32 ( V_15 ) );
}
