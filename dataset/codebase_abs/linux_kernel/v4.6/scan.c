static T_1
F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 ;
V_4 = V_2 -> V_5 [ 0 ] ;
while ( V_4 ) {
if ( ! memcmp ( V_2 -> V_6 , V_3 , sizeof( V_2 -> V_6 ) ) )
return V_7 ;
-- V_4 ;
if ( V_4 )
V_2 = (struct V_1 * ) ( ( T_1 * ) V_2 +
sizeof( V_2 -> V_6 ) ) ;
}
F_2 ( L_1 , V_8 ) ;
return V_9 ;
}
static T_1
F_3 ( struct V_10 * V_11 , T_2 V_12 )
{
T_1 * V_3 ;
struct V_1 * V_2 ;
T_1 V_13 = V_9 ;
if ( ( ( V_11 -> V_14 ) && ( ( * ( V_11 -> V_14 ) ) .
V_15 . V_16 == V_17 ) ) ) {
V_2 = (struct V_1 * )
( ( ( T_1 * ) V_11 -> V_14 -> V_18 ) +
V_19 ) ;
V_3 = & V_20 [ V_12 ] [ 0 ] ;
V_13 = F_1 ( V_2 , V_3 ) ;
if ( V_13 )
return V_13 ;
}
return V_13 ;
}
static T_1
F_4 ( struct V_10 * V_11 , T_2 V_12 )
{
T_1 * V_3 ;
struct V_1 * V_2 ;
T_1 V_13 = V_9 ;
if ( ( ( V_11 -> V_21 ) &&
( ( * ( V_11 -> V_21 ) ) . V_22 . V_16 ==
V_23 ) ) ) {
V_2 = (struct V_1 * ) V_11 -> V_21 -> V_18 ;
V_3 = & V_24 [ V_12 ] [ 0 ] ;
V_13 = F_1 ( V_2 , V_3 ) ;
if ( V_13 )
return V_13 ;
}
return V_13 ;
}
T_3
F_5 ( struct V_25 * V_26 , struct V_25 * V_27 )
{
if ( ! V_26 || ! V_27 || ( V_26 -> V_28 != V_27 -> V_28 ) )
return - 1 ;
return memcmp ( V_26 -> V_29 , V_27 -> V_29 , V_26 -> V_28 ) ;
}
static bool
F_6 ( struct V_30 * V_31 ,
struct V_10 * V_11 )
{
if ( V_31 -> V_32 . V_33 &&
( V_11 -> V_34 &&
( ( * ( V_11 -> V_34 ) ) . V_15 . V_16 ==
V_35 ) ) ) {
return true ;
}
return false ;
}
static bool
F_7 ( struct V_30 * V_31 ,
struct V_10 * V_11 )
{
if ( ! V_31 -> V_32 . V_36 && ! V_31 -> V_32 . V_37 &&
! V_31 -> V_32 . V_38 && ( ( ! V_11 -> V_21 ) ||
( ( * ( V_11 -> V_21 ) ) . V_22 . V_16 !=
V_23 ) ) &&
( ( ! V_11 -> V_14 ) ||
( ( * ( V_11 -> V_14 ) ) . V_15 . V_16 !=
V_17 ) ) &&
! V_31 -> V_32 . V_39 && ! V_11 -> V_40 ) {
return true ;
}
return false ;
}
static bool
F_8 ( struct V_30 * V_31 ,
struct V_10 * V_11 )
{
if ( V_31 -> V_32 . V_36 && ! V_31 -> V_32 . V_37 &&
! V_31 -> V_32 . V_38 && V_11 -> V_40 ) {
return true ;
}
return false ;
}
static bool
F_9 ( struct V_30 * V_31 ,
struct V_10 * V_11 )
{
if ( ! V_31 -> V_32 . V_36 && V_31 -> V_32 . V_37 &&
! V_31 -> V_32 . V_38 && ( ( V_11 -> V_21 ) &&
( ( * ( V_11 -> V_21 ) ) .
V_22 . V_16 == V_23 ) )
) {
F_10 ( V_31 -> V_41 , V_42 ,
L_2
L_3
L_4 , V_8 ,
( V_11 -> V_21 ) ?
( * V_11 -> V_21 ) .
V_22 . V_16 : 0 ,
( V_11 -> V_14 ) ?
( * V_11 -> V_14 ) .
V_15 . V_16 : 0 ,
( V_31 -> V_32 . V_36 ) ? L_5 : L_6 ,
( V_31 -> V_32 . V_37 ) ? L_5 : L_6 ,
( V_31 -> V_32 . V_38 ) ? L_5 : L_6 ,
V_31 -> V_32 . V_39 ,
V_11 -> V_40 ) ;
return true ;
}
return false ;
}
static bool
F_11 ( struct V_30 * V_31 ,
struct V_10 * V_11 )
{
if ( ! V_31 -> V_32 . V_36 &&
! V_31 -> V_32 . V_37 &&
V_31 -> V_32 . V_38 &&
( ( V_11 -> V_14 ) &&
( ( * ( V_11 -> V_14 ) ) . V_15 . V_16 == V_17 ) ) ) {
F_10 ( V_31 -> V_41 , V_42 ,
L_7
L_3
L_4 , V_8 ,
( V_11 -> V_21 ) ?
( * V_11 -> V_21 ) .
V_22 . V_16 : 0 ,
( V_11 -> V_14 ) ?
( * V_11 -> V_14 ) .
V_15 . V_16 : 0 ,
( V_31 -> V_32 . V_36 ) ? L_5 : L_6 ,
( V_31 -> V_32 . V_37 ) ? L_5 : L_6 ,
( V_31 -> V_32 . V_38 ) ? L_5 : L_6 ,
V_31 -> V_32 . V_39 ,
V_11 -> V_40 ) ;
return true ;
}
return false ;
}
static bool
F_12 ( struct V_30 * V_31 ,
struct V_10 * V_11 )
{
if ( ! V_31 -> V_32 . V_36 && ! V_31 -> V_32 . V_37 &&
! V_31 -> V_32 . V_38 &&
( ( ! V_11 -> V_21 ) ||
( ( * ( V_11 -> V_21 ) ) .
V_22 . V_16 != V_23 ) ) &&
( ( ! V_11 -> V_14 ) ||
( ( * ( V_11 -> V_14 ) ) . V_15 . V_16 != V_17 ) ) &&
! V_31 -> V_32 . V_39 && V_11 -> V_40 ) {
return true ;
}
return false ;
}
static bool
F_13 ( struct V_30 * V_31 ,
struct V_10 * V_11 )
{
if ( ! V_31 -> V_32 . V_36 && ! V_31 -> V_32 . V_37 &&
! V_31 -> V_32 . V_38 &&
( ( ! V_11 -> V_21 ) ||
( ( * ( V_11 -> V_21 ) ) .
V_22 . V_16 != V_23 ) ) &&
( ( ! V_11 -> V_14 ) ||
( ( * ( V_11 -> V_14 ) ) . V_15 . V_16 != V_17 ) ) &&
V_31 -> V_32 . V_39 && V_11 -> V_40 ) {
F_10 ( V_31 -> V_41 , V_42 ,
L_8
L_9
L_4 ,
V_8 ,
( V_11 -> V_21 ) ?
( * V_11 -> V_21 ) .
V_22 . V_16 : 0 ,
( V_11 -> V_14 ) ?
( * V_11 -> V_14 ) .
V_15 . V_16 : 0 ,
V_31 -> V_32 . V_39 ,
V_11 -> V_40 ) ;
return true ;
}
return false ;
}
static T_3
F_14 ( struct V_30 * V_31 ,
struct V_10 * V_11 , T_2 V_43 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
V_11 -> V_45 = false ;
if ( V_31 -> V_46 &&
( V_31 -> V_47 == V_48 ) &&
( V_11 -> V_47 == V_48 ) )
return 0 ;
if ( V_31 -> V_49 . V_50 ) {
F_10 ( V_41 , V_51 ,
L_10 ) ;
return 0 ;
}
if ( V_11 -> V_52 ) {
F_10 ( V_41 , V_42 ,
L_11 ) ;
return - 1 ;
}
if ( F_6 ( V_31 , V_11 ) ) {
F_10 ( V_41 , V_42 ,
L_12 ) ;
return 0 ;
}
if ( V_11 -> V_47 == V_43 ) {
if ( F_7 ( V_31 , V_11 ) ) {
return 0 ;
} else if ( F_8 ( V_31 , V_11 ) ) {
F_10 ( V_41 , V_42 ,
L_13 ) ;
V_11 -> V_45 = true ;
return 0 ;
} else if ( F_9 ( V_31 , V_11 ) ) {
if ( ( ( V_31 -> V_41 -> V_53 & V_54 ||
V_31 -> V_41 -> V_53 & V_55 ) &&
V_11 -> V_56 ) &&
! F_4 ( V_11 ,
V_57 ) ) {
if ( F_4
( V_11 , V_58 ) ) {
F_10 ( V_41 , V_42 ,
L_14
L_15 ) ;
V_11 -> V_45 = true ;
} else {
return - 1 ;
}
}
return 0 ;
} else if ( F_11 ( V_31 , V_11 ) ) {
if ( ( ( V_31 -> V_41 -> V_53 & V_54 ||
V_31 -> V_41 -> V_53 & V_55 ) &&
V_11 -> V_56 ) &&
! F_3 ( V_11 ,
V_57 ) ) {
if ( F_3
( V_11 , V_58 ) ) {
F_10 ( V_41 , V_42 ,
L_14
L_15 ) ;
V_11 -> V_45 = true ;
} else {
return - 1 ;
}
}
return 0 ;
} else if ( F_12 ( V_31 , V_11 ) ) {
return 0 ;
} else if ( F_13 ( V_31 , V_11 ) ) {
return 0 ;
}
F_10 ( V_41 , ERROR ,
L_16
L_17 ,
V_8 ,
( V_11 -> V_21 ) ?
( * V_11 -> V_21 ) . V_22 . V_16 : 0 ,
( V_11 -> V_14 ) ?
( * V_11 -> V_14 ) . V_15 . V_16 : 0 ,
( V_31 -> V_32 . V_36 ) ? L_5 : L_6 ,
( V_31 -> V_32 . V_37 ) ? L_5 : L_6 ,
( V_31 -> V_32 . V_38 ) ? L_5 : L_6 ,
V_31 -> V_32 . V_39 , V_11 -> V_40 ) ;
return - 1 ;
}
return - 1 ;
}
static int
F_15 ( struct V_30 * V_31 ,
const struct V_59
* V_60 ,
struct V_61
* V_62 ,
T_1 V_63 )
{
enum V_64 V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_44 * V_41 = V_31 -> V_41 ;
int V_70 = 0 , V_71 ;
for ( V_65 = 0 ; ( V_65 < V_72 ) ; V_65 ++ ) {
if ( ! V_31 -> V_73 . V_74 -> V_75 [ V_65 ] )
continue;
V_67 = V_31 -> V_73 . V_74 -> V_75 [ V_65 ] ;
for ( V_71 = 0 ; ( V_71 < V_67 -> V_76 ) ; V_71 ++ ) {
V_69 = & V_67 -> V_77 [ V_71 ] ;
if ( V_69 -> V_78 & V_79 )
continue;
V_62 [ V_70 ] . V_80 = V_65 ;
if ( V_60 &&
V_60 -> V_81 [ 0 ] . V_82 )
V_62 [ V_70 ] . V_83 =
F_16 ( ( V_84 ) V_60 ->
V_81 [ 0 ] . V_82 ) ;
else if ( V_69 -> V_78 & V_85 )
V_62 [ V_70 ] . V_83 =
F_16 ( V_41 -> V_86 ) ;
else
V_62 [ V_70 ] . V_83 =
F_16 ( V_41 -> V_87 ) ;
if ( V_69 -> V_78 & V_85 )
V_62 [ V_70 ] . V_88
|= ( V_89 |
V_90 ) ;
else
V_62 [ V_70 ] . V_88
&= ~ V_89 ;
V_62 [ V_70 ] . V_91 =
( T_2 ) V_69 -> V_92 ;
if ( V_63 ) {
V_62 [ V_70 ] . V_83 =
F_16 ( V_41 -> V_93 ) ;
V_62 [ V_70 ] . V_88
|= V_94 ;
}
V_70 ++ ;
}
}
return V_70 ;
}
static int
F_17 ( struct V_30 * V_31 ,
const struct V_95
* V_96 ,
struct V_61
* V_62 )
{
enum V_64 V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_44 * V_41 = V_31 -> V_41 ;
int V_70 = 0 , V_71 ;
for ( V_65 = 0 ; ( V_65 < V_72 ) ; V_65 ++ ) {
if ( ! V_31 -> V_73 . V_74 -> V_75 [ V_65 ] )
continue;
V_67 = V_31 -> V_73 . V_74 -> V_75 [ V_65 ] ;
for ( V_71 = 0 ; ( V_71 < V_67 -> V_76 ) ; V_71 ++ ) {
V_69 = & V_67 -> V_77 [ V_71 ] ;
if ( V_69 -> V_78 & V_79 )
continue;
V_62 [ V_70 ] . V_80 = V_65 ;
if ( V_96 -> V_81 [ 0 ] . V_82 )
V_62 [ V_70 ] . V_83 =
F_16 ( ( V_84 ) V_96 ->
V_81 [ 0 ] . V_82 ) ;
else if ( V_69 -> V_78 & V_85 )
V_62 [ V_70 ] . V_83 =
F_16 ( V_41 -> V_86 ) ;
else
V_62 [ V_70 ] . V_83 =
F_16 ( V_41 ->
V_93 ) ;
if ( V_69 -> V_78 & V_85 )
V_62 [ V_70 ] . V_88
|= V_89 ;
else
V_62 [ V_70 ] . V_88
&= ~ V_89 ;
V_62 [ V_70 ] . V_91 =
( T_2 ) V_69 -> V_92 ;
V_70 ++ ;
}
}
return V_70 ;
}
static int
F_18 ( struct V_30 * V_31 ,
struct V_97 * V_98 ,
T_1 V_99 )
{
struct V_100 * V_101 ;
T_1 V_102 [ V_103 ] , * V_104 ;
T_2 V_105 ;
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
V_104 = ( T_1 * ) V_98 -> V_106 + V_98 -> V_107 ;
if ( V_31 -> V_108 )
V_105 = F_19 ( V_31 , V_102 ,
V_99 ) ;
else
V_105 = F_20 ( V_31 , V_102 ) ;
F_10 ( V_31 -> V_41 , V_109 ,
L_18 ,
V_105 ) ;
V_101 = (struct V_100 * ) V_104 ;
V_101 -> V_110 . type = F_16 ( V_111 ) ;
V_101 -> V_110 . V_112 = F_16 ( ( V_84 ) V_105 ) ;
memcpy ( V_101 -> V_102 , V_102 , V_105 ) ;
V_98 -> V_107 += sizeof( V_101 -> V_110 ) + V_105 ;
return V_105 ;
}
static int
F_21 ( struct V_30 * V_31 ,
T_2 V_113 , T_1 V_63 ,
struct V_97 * V_98 ,
struct V_114
* V_115 ,
struct V_61 * V_62 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
int V_13 = 0 ;
struct V_61 * V_116 ;
struct V_61 * V_117 ;
struct V_118 * V_119 , * V_120 ;
unsigned long V_78 ;
T_2 V_121 , V_105 , V_122 ;
T_2 V_123 ;
T_2 V_124 ;
T_1 V_80 ;
if ( ! V_98 || ! V_115 || ! V_62 ) {
F_10 ( V_31 -> V_41 , ERROR ,
L_19 ,
V_98 , V_115 , V_62 ) ;
return - 1 ;
}
F_22 ( V_31 ) ;
V_115 -> V_110 . type = F_16 ( V_125 ) ;
V_116 = V_62 ;
while ( V_116 -> V_91 ) {
V_121 = 0 ;
V_123 = 0 ;
V_80 = 0 ;
V_115 -> V_110 . V_112 = 0 ;
V_117 = V_116 ;
V_124 = false ;
while ( V_121 < V_113 &&
V_116 -> V_91 && ! V_124 ) {
if ( V_116 -> V_91 == V_31 -> V_126 ) {
V_116 ++ ;
continue;
}
V_80 = V_116 -> V_80 ;
F_10 ( V_31 -> V_41 , V_42 ,
L_20
L_21 ,
V_116 -> V_91 ,
V_116 -> V_80 ,
V_116 -> V_88
& V_89 ,
( V_116 -> V_88
& V_94 ) >> 1 ,
F_23 ( V_116 -> V_83 ) ) ;
memcpy ( V_115 -> V_127 + V_121 ,
V_116 ,
sizeof( V_115 -> V_127 ) ) ;
F_24 ( & V_115 -> V_110 . V_112 ,
sizeof( V_115 -> V_127 ) ) ;
V_98 -> V_107 = ( T_2 ) ( ( T_1 * ) V_115 -
V_98 -> V_106 ) ;
V_98 -> V_107 +=
( sizeof( V_115 -> V_110 )
+ F_23 ( V_115 -> V_110 . V_112 ) ) ;
V_121 ++ ;
V_123 +=
F_23 ( V_116 -> V_83 ) ;
V_124 = false ;
if ( ! V_63 &&
( V_116 -> V_91 == 1 ||
V_116 -> V_91 == 6 ||
V_116 -> V_91 == 11 ) )
V_124 = true ;
V_116 ++ ;
if ( ! V_63 &&
( V_116 -> V_91 == 1 ||
V_116 -> V_91 == 6 ||
V_116 -> V_91 == 11 ) )
V_124 = true ;
}
if ( V_123 > V_128 ) {
F_10 ( V_31 -> V_41 , ERROR ,
L_22
L_23 ,
V_123 ,
V_128 ) ;
V_13 = - 1 ;
break;
}
V_105 = F_18 ( V_31 , V_98 ,
V_80 ) ;
V_31 -> V_41 -> V_129 = V_117 ;
if ( V_31 -> V_41 -> V_130 )
V_122 = V_131 ;
else
V_122 = V_132 ;
V_13 = F_25 ( V_31 , V_122 , V_133 ,
0 , V_98 , false ) ;
V_98 -> V_107 -=
sizeof( struct V_134 ) + V_105 ;
if ( V_13 ) {
F_26 ( & V_41 -> V_135 , V_78 ) ;
F_27 (cmd_node, tmp_node,
&adapter->scan_pending_q,
list) {
F_28 ( & V_119 -> V_136 ) ;
V_119 -> V_137 = false ;
F_29 ( V_41 , V_119 ) ;
}
F_30 ( & V_41 -> V_135 ,
V_78 ) ;
break;
}
}
if ( V_13 )
return - 1 ;
return 0 ;
}
static void
F_31 ( struct V_30 * V_31 ,
const struct V_59 * V_60 ,
struct V_97 * V_98 ,
struct V_114 * * V_138 ,
struct V_61 * V_62 ,
T_1 * V_113 , T_1 * V_63 ,
T_1 * V_139 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
T_1 * V_104 ;
T_2 V_148 ;
T_2 V_28 ;
T_2 V_70 ;
T_2 V_149 ;
T_2 V_150 ;
V_84 V_151 ;
T_1 V_152 ;
T_1 V_80 ;
int V_71 ;
T_1 V_153 ;
struct V_154 * V_155 ;
struct V_156 * V_47 ;
V_98 -> V_107 = 0 ;
V_104 = V_98 -> V_106 ;
* V_63 = false ;
* V_139 = false ;
if ( V_60 ) {
V_153 = true ;
V_98 -> V_47 =
( V_60 -> V_47 ? ( T_1 ) V_60 ->
V_47 : ( T_1 ) V_41 -> V_157 ) ;
V_148 =
( V_60 -> V_148 ? V_60 ->
V_148 : V_41 -> V_158 ) ;
memcpy ( V_98 -> V_159 ,
V_60 -> V_159 ,
sizeof( V_98 -> V_159 ) ) ;
if ( V_41 -> V_130 &&
! F_32 ( V_98 -> V_159 ) ) {
V_147 =
(struct V_146 * ) V_104 ;
V_147 -> V_110 . type = F_16 ( V_160 ) ;
V_147 -> V_110 . V_112 = F_16 ( V_161 ) ;
memcpy ( V_147 -> V_162 , V_60 -> V_159 ,
V_161 ) ;
V_104 += sizeof( struct V_146 ) ;
}
for ( V_71 = 0 ; V_71 < V_60 -> V_163 ; V_71 ++ ) {
V_28 = V_60 -> V_164 [ V_71 ] . V_28 ;
V_145 =
(struct V_144 * )
V_104 ;
V_145 -> V_110 . type =
F_16 ( V_165 ) ;
V_145 -> V_110 . V_112 = F_16 (
( V_84 ) ( V_28 + sizeof( V_145 ->
V_166 ) ) ) ;
if ( V_28 )
V_145 -> V_166 = 0 ;
else
V_145 -> V_166 =
V_167 ;
if ( ! memcmp ( V_60 -> V_164 [ V_71 ] . V_29 ,
L_24 , 7 ) )
V_145 -> V_166 = 0xfe ;
memcpy ( V_145 -> V_29 ,
V_60 -> V_164 [ V_71 ] . V_29 , V_28 ) ;
V_104 += ( sizeof( V_145 -> V_110 )
+ F_23 ( V_145 -> V_110 . V_112 ) ) ;
F_10 ( V_41 , V_42 ,
L_25 ,
V_71 , V_145 -> V_29 ,
V_145 -> V_166 ) ;
if ( ! V_28 && V_145 -> V_166 )
V_153 = false ;
}
if ( ( V_71 && V_153 ) ||
! F_32 ( V_98 -> V_159 ) )
* V_63 = true ;
if ( V_60 -> V_168 ) {
F_10 ( V_41 , V_42 ,
L_26 ,
V_60 -> V_168 ) ;
* V_113 =
V_169 ;
V_143 = ( void * ) V_104 ;
V_143 -> V_110 . type =
F_16 ( V_170 ) ;
V_143 -> V_110 . V_112 =
F_16 ( sizeof( V_143 -> V_171 ) ) ;
V_143 -> V_171 =
F_16 ( ( V_60 -> V_168 ) ) ;
V_104 +=
sizeof( struct V_142 ) ;
}
} else {
V_98 -> V_47 = ( T_1 ) V_41 -> V_157 ;
V_148 = V_41 -> V_158 ;
}
if ( * V_63 )
* V_113 = V_169 ;
else
* V_113 = V_172 ;
if ( V_41 -> V_130 ) {
V_47 = (struct V_156 * ) V_104 ;
V_47 -> V_110 . type = F_16 ( V_173 ) ;
V_47 -> V_110 . V_112 = F_16 ( sizeof( V_47 -> V_47 ) ) ;
V_47 -> V_47 = V_98 -> V_47 ;
V_104 += sizeof( V_47 -> V_110 ) +
F_23 ( V_47 -> V_110 . V_112 ) ;
}
if ( V_148 ) {
F_10 ( V_41 , V_42 ,
L_27 ,
V_148 ) ;
V_141 = (struct V_140 * ) V_104 ;
V_141 -> V_110 . type = F_16 ( V_174 ) ;
V_141 -> V_110 . V_112 =
F_16 ( sizeof( V_141 -> V_148 ) ) ;
V_141 -> V_148 = F_16 ( ( V_84 ) V_148 ) ;
V_104 += sizeof( V_141 -> V_110 ) +
F_23 ( V_141 -> V_110 . V_112 ) ;
}
if ( F_33 ( V_31 -> V_41 -> V_175 ) &&
( V_31 -> V_41 -> V_53 & V_54 ||
V_31 -> V_41 -> V_53 & V_55 ) ) {
V_155 = (struct V_154 * ) V_104 ;
memset ( V_155 , 0 , sizeof( struct V_154 ) ) ;
V_155 -> V_110 . type = F_16 ( V_176 ) ;
V_155 -> V_110 . V_112 =
F_16 ( sizeof( struct V_177 ) ) ;
V_80 =
F_34 ( V_31 -> V_41 -> V_53 ) ;
F_35 ( V_31 , V_80 , & V_155 -> V_155 ) ;
V_104 += sizeof( struct V_154 ) ;
}
F_36 ( V_31 , V_178 , & V_104 ) ;
* V_138 =
(struct V_114 * ) V_104 ;
if ( V_60 && V_60 -> V_81 [ 0 ] . V_91 ) {
F_10 ( V_41 , V_42 ,
L_28 ) ;
for ( V_70 = 0 ;
V_70 < V_179 &&
V_60 -> V_81 [ V_70 ] . V_91 ;
V_70 ++ ) {
V_152 = V_60 -> V_81 [ V_70 ] . V_91 ;
( V_62 + V_70 ) -> V_91 = V_152 ;
V_80 =
V_60 -> V_81 [ V_70 ] . V_80 ;
( V_62 + V_70 ) -> V_80 = V_80 ;
V_150 = V_60 -> V_81 [ V_70 ] . V_150 ;
if ( V_150 == V_180 )
( V_62 +
V_70 ) -> V_88
|= ( V_89 |
V_90 ) ;
else
( V_62 +
V_70 ) -> V_88
&= ~ V_89 ;
if ( * V_63 )
( V_62 +
V_70 ) -> V_88
|= V_94 ;
if ( V_60 -> V_81 [ V_70 ] . V_82 ) {
V_151 = ( V_84 ) V_60 ->
V_81 [ V_70 ] . V_82 ;
} else {
if ( V_150 == V_180 )
V_151 = V_41 -> V_86 ;
else if ( * V_63 )
V_151 = V_41 -> V_93 ;
else
V_151 = V_41 -> V_87 ;
}
( V_62 + V_70 ) -> V_181 =
F_16 ( V_151 ) ;
( V_62 + V_70 ) -> V_83 =
F_16 ( V_151 ) ;
}
if ( ( V_70 == 1 ) &&
( V_60 -> V_81 [ 0 ] . V_91 ==
V_31 -> V_182 . V_183 . V_152 ) ) {
* V_139 = true ;
F_10 ( V_41 , V_42 ,
L_29 ) ;
}
V_149 = V_70 ;
} else {
F_10 ( V_41 , V_42 ,
L_30 ) ;
V_149 = F_15 ( V_31 , V_60 ,
V_62 ,
* V_63 ) ;
}
}
static void
F_37 ( struct V_44 * V_41 ,
struct V_184 * V_185 ,
T_2 V_186 , T_2 V_187 ,
struct V_184 * * V_188 )
{
struct V_184 * V_189 ;
T_2 V_190 ;
T_2 V_191 ;
T_2 V_192 ;
V_189 = V_185 ;
V_190 = V_186 ;
* V_188 = NULL ;
F_10 ( V_41 , V_42 ,
L_31 ,
V_186 ) ;
while ( V_190 >= sizeof( struct V_134 ) ) {
V_191 = F_23 ( V_189 -> V_110 . type ) ;
V_192 = F_23 ( V_189 -> V_110 . V_112 ) ;
if ( sizeof( V_185 -> V_110 ) + V_192 > V_190 ) {
F_10 ( V_41 , ERROR ,
L_32 ) ;
break;
}
if ( V_187 == V_191 ) {
switch ( V_191 ) {
case V_193 :
F_10 ( V_41 , V_42 ,
L_33
L_34 ,
V_192 ) ;
* V_188 = V_189 ;
break;
case V_194 :
F_10 ( V_41 , V_42 ,
L_35
L_36 ,
V_192 ) ;
* V_188 = V_189 ;
break;
default:
F_10 ( V_41 , ERROR ,
L_37 ,
V_191 ) ;
return;
}
}
if ( * V_188 )
break;
V_190 -= ( sizeof( V_185 -> V_110 ) + V_192 ) ;
V_189 =
(struct V_184 * ) ( V_189 -> V_18 +
V_192 ) ;
}
}
int F_38 ( struct V_44 * V_41 ,
struct V_10 * V_195 )
{
int V_13 = 0 ;
T_1 V_16 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
struct V_202 * V_203 ;
T_1 * V_204 ;
T_1 * V_205 ;
T_1 V_206 ;
V_84 V_207 ;
T_1 V_208 ;
T_1 V_209 ;
T_1 V_210 ;
T_2 V_211 ;
struct V_212 * V_213 ;
const T_1 V_214 [ 4 ] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_1 V_215 [ 4 ] = { 0x00 , 0x50 , 0xf2 , 0x02 } ;
V_210 = false ;
V_209 = 0 ;
V_204 = V_195 -> V_216 ;
V_211 = V_195 -> V_217 ;
while ( V_211 >= 2 ) {
V_16 = * V_204 ;
V_206 = * ( V_204 + 1 ) ;
V_207 = V_206 + sizeof( struct V_218 ) ;
if ( V_211 < V_207 ) {
F_10 ( V_41 , ERROR ,
L_38
L_39 ) ;
return - 1 ;
}
switch ( V_16 ) {
case V_219 :
V_195 -> V_29 . V_28 = V_206 ;
memcpy ( V_195 -> V_29 . V_29 , ( V_204 + 2 ) ,
V_206 ) ;
F_10 ( V_41 , V_42 ,
L_40 ,
V_195 -> V_29 . V_29 ) ;
break;
case V_111 :
memcpy ( V_195 -> V_220 , V_204 + 2 ,
V_206 ) ;
memcpy ( V_195 -> V_221 , V_204 + 2 ,
V_206 ) ;
V_209 = V_206 ;
V_210 = true ;
break;
case V_222 :
V_197 =
(struct V_196 * ) V_204 ;
memcpy ( & V_195 -> V_223 . V_197 ,
V_197 ,
sizeof( struct V_196 ) ) ;
break;
case V_224 :
V_199 =
(struct V_198 * ) V_204 ;
V_195 -> V_152 = V_199 -> V_225 ;
memcpy ( & V_195 -> V_223 . V_199 ,
V_199 ,
sizeof( struct V_198 ) ) ;
break;
case V_226 :
V_201 =
(struct V_200 * ) V_204 ;
memcpy ( & V_195 -> V_227 . V_201 ,
V_201 ,
sizeof( struct V_200 ) ) ;
break;
case V_228 :
V_203 =
(struct V_202 * )
V_204 ;
memcpy ( & V_195 -> V_227 . V_203 ,
V_203 ,
sizeof( struct V_202 ) ) ;
break;
case V_229 :
V_195 -> V_230 = * ( V_204 + 2 ) ;
break;
case V_231 :
V_195 -> V_232 = * ( V_204 + 2 ) ;
V_195 -> V_233 = true ;
break;
case V_234 :
V_195 -> V_52 = true ;
case V_235 :
case V_236 :
case V_237 :
V_195 -> V_233 = true ;
break;
case V_238 :
if ( V_210 ) {
if ( ( V_206 + V_209 ) >
V_103 )
V_208 =
( V_103 -
V_209 ) ;
else
V_208 = V_206 ;
V_205 = ( T_1 * ) V_195 -> V_220 ;
V_205 += V_209 ;
memcpy ( V_205 , V_204 + 2 , V_208 ) ;
V_205 = ( T_1 * ) V_195 -> V_221 ;
V_205 += V_209 ;
memcpy ( V_205 , V_204 + 2 , V_208 ) ;
}
break;
case V_23 :
V_213 = (struct V_212 * )
V_204 ;
if ( ! memcmp
( V_213 -> V_22 . V_3 , V_214 ,
sizeof( V_214 ) ) ) {
V_195 -> V_21 =
(struct V_212 * )
V_204 ;
V_195 -> V_239 = ( V_84 )
( V_204 - V_195 -> V_216 ) ;
} else if ( ! memcmp ( V_213 -> V_22 . V_3 , V_215 ,
sizeof( V_215 ) ) ) {
if ( V_207 ==
sizeof( struct V_240 ) ||
V_207 ==
sizeof( struct V_241 ) )
memcpy ( ( T_1 * ) & V_195 -> V_242 ,
V_204 , V_207 ) ;
}
break;
case V_17 :
V_195 -> V_14 =
(struct V_243 * ) V_204 ;
V_195 -> V_244 = ( V_84 ) ( V_204 -
V_195 -> V_216 ) ;
break;
case V_35 :
V_195 -> V_34 =
(struct V_243 * ) V_204 ;
V_195 -> V_245 = ( V_84 ) ( V_204 -
V_195 -> V_216 ) ;
break;
case V_176 :
V_195 -> V_56 = (struct V_177 * )
( V_204 +
sizeof( struct V_218 ) ) ;
V_195 -> V_246 = ( V_84 ) ( V_204 +
sizeof( struct V_218 ) -
V_195 -> V_216 ) ;
break;
case V_247 :
V_195 -> V_248 =
(struct V_249 * ) ( V_204 +
sizeof( struct V_218 ) ) ;
V_195 -> V_250 = ( V_84 ) ( V_204 +
sizeof( struct V_218 ) -
V_195 -> V_216 ) ;
break;
case V_251 :
V_195 -> V_252 = false ;
V_195 -> V_253 =
( void * ) ( V_204 +
sizeof( struct V_218 ) ) ;
V_195 -> V_254 =
( V_84 ) ( ( T_1 * ) V_195 -> V_253 -
V_195 -> V_216 ) ;
break;
case V_255 :
V_195 -> V_256 =
( void * ) ( V_204 +
sizeof( struct V_218 ) ) ;
V_195 -> V_257 =
( V_84 ) ( ( T_1 * ) V_195 -> V_256 -
V_195 -> V_216 ) ;
break;
case V_258 :
V_195 -> V_259 = V_204 ;
V_195 -> V_260 =
( V_84 ) ( V_204 - V_195 -> V_216 ) ;
break;
case V_261 :
V_195 -> V_262 = V_204 ;
V_195 -> V_263 =
( V_84 ) ( V_204 - V_195 -> V_216 ) ;
break;
case V_264 :
V_195 -> V_265 = ( void * ) V_204 ;
V_195 -> V_266 =
( V_84 ) ( ( T_1 * ) V_195 -> V_265 -
V_195 -> V_216 ) ;
break;
default:
break;
}
V_204 += V_206 + 2 ;
V_211 -= ( V_206 + 2 ) ;
}
return V_13 ;
}
static T_1
F_39 ( T_1 V_80 )
{
switch ( V_80 ) {
case V_267 :
return V_268 ;
case V_269 :
default:
return V_270 ;
}
}
int F_40 ( struct V_30 * V_31 ,
const struct V_59 * V_60 )
{
int V_13 ;
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_118 * V_119 ;
union V_271 * V_98 ;
struct V_114 * V_138 ;
struct V_61 * V_62 ;
T_1 V_63 ;
T_1 V_272 ;
T_1 V_113 ;
unsigned long V_78 ;
if ( V_41 -> V_273 ) {
F_10 ( V_41 , V_274 ,
L_41 ) ;
return - V_275 ;
}
if ( V_31 -> V_276 ) {
F_10 ( V_41 , V_274 ,
L_42 ) ;
return - V_275 ;
}
if ( V_41 -> V_277 || V_41 -> V_278 ) {
F_10 ( V_41 , ERROR ,
L_43 ) ;
return - V_279 ;
}
F_26 ( & V_41 -> V_280 , V_78 ) ;
V_41 -> V_273 = true ;
F_30 ( & V_41 -> V_280 , V_78 ) ;
V_98 = F_41 ( sizeof( union V_271 ) ,
V_281 ) ;
if ( ! V_98 ) {
V_13 = - V_282 ;
goto V_283;
}
V_62 = F_42 ( V_179 ,
sizeof( struct V_61 ) ,
V_281 ) ;
if ( ! V_62 ) {
F_43 ( V_98 ) ;
V_13 = - V_282 ;
goto V_283;
}
F_31 ( V_31 , V_60 , & V_98 -> V_284 ,
& V_138 , V_62 , & V_113 ,
& V_63 , & V_272 ) ;
V_13 = F_21 ( V_31 , V_113 , V_63 ,
& V_98 -> V_284 , V_138 ,
V_62 ) ;
if ( ! V_13 ) {
F_26 ( & V_41 -> V_135 , V_78 ) ;
if ( ! F_44 ( & V_41 -> V_285 ) ) {
V_119 = F_45 ( & V_41 -> V_285 ,
struct V_118 , V_136 ) ;
F_28 ( & V_119 -> V_136 ) ;
F_30 ( & V_41 -> V_135 ,
V_78 ) ;
F_46 ( V_41 , V_119 ,
true ) ;
F_47 ( V_41 -> V_286 , & V_41 -> V_287 ) ;
if ( ! V_31 -> V_108 ) {
F_10 ( V_41 , V_42 ,
L_44 ) ;
F_48 ( V_41 , V_119 ) ;
}
} else {
F_30 ( & V_41 -> V_135 ,
V_78 ) ;
}
}
F_43 ( V_98 ) ;
F_43 ( V_62 ) ;
V_283:
if ( V_13 ) {
F_26 ( & V_41 -> V_280 , V_78 ) ;
V_41 -> V_273 = false ;
F_30 ( & V_41 -> V_280 , V_78 ) ;
}
return V_13 ;
}
int F_49 ( struct V_288 * V_289 ,
struct V_97 * V_290 )
{
struct V_291 * V_292 = & V_289 -> V_293 . V_294 ;
V_292 -> V_47 = V_290 -> V_47 ;
memcpy ( V_292 -> V_162 , V_290 -> V_159 ,
sizeof( V_292 -> V_162 ) ) ;
memcpy ( V_292 -> V_295 , V_290 -> V_106 , V_290 -> V_107 ) ;
V_289 -> V_296 = F_16 ( V_132 ) ;
V_289 -> V_297 = F_16 ( ( V_84 ) ( sizeof( V_292 -> V_47 )
+ sizeof( V_292 -> V_162 )
+ V_290 -> V_107 + V_298 ) ) ;
return 0 ;
}
int F_50 ( struct V_30 * V_31 ,
struct V_10 * V_11 )
{
int V_13 = - 1 ;
if ( ! V_11 )
return - 1 ;
if ( ( F_51 ( V_31 , ( T_1 ) V_11 -> V_299 ,
( V_84 ) V_11 -> V_152 , 0 ) ) ) {
switch ( V_31 -> V_47 ) {
case V_48 :
case V_300 :
V_13 = F_14 ( V_31 , V_11 ,
V_31 -> V_47 ) ;
if ( V_13 )
F_10 ( V_31 -> V_41 , ERROR ,
L_45 ) ;
break;
default:
V_13 = 0 ;
}
}
return V_13 ;
}
static bool F_52 ( struct V_25 * V_29 )
{
int V_301 ;
for ( V_301 = 0 ; V_301 < V_29 -> V_28 ; V_301 ++ ) {
if ( V_29 -> V_29 [ V_301 ] )
return false ;
}
return true ;
}
static int F_53 ( struct V_30 * V_31 ,
struct V_302 * V_303 )
{
struct V_10 * V_11 ;
int V_13 ;
int V_304 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_281 ) ;
if ( ! V_11 )
return - V_282 ;
V_13 = F_54 ( V_31 , V_303 , V_11 ) ;
if ( V_13 )
goto V_283;
if ( F_52 ( & V_11 -> V_29 ) ) {
F_10 ( V_31 -> V_41 , V_42 , L_46 ) ;
for ( V_304 = 0 ; V_304 < V_179 ; V_304 ++ ) {
if ( V_31 -> V_305 [ V_304 ] . V_91 ==
V_303 -> V_152 -> V_92 )
break;
if ( ! V_31 -> V_305 [ V_304 ] . V_91 ) {
V_31 -> V_305 [ V_304 ] . V_91 =
V_303 -> V_152 -> V_92 ;
V_31 -> V_305 [ V_304 ] . V_80 =
V_303 -> V_152 -> V_65 ;
V_31 -> V_305 [ V_304 ] . V_150 =
V_306 ;
break;
}
}
}
V_283:
F_43 ( V_11 ) ;
return 0 ;
}
static int F_55 ( struct V_30 * V_31 ,
struct V_302 * V_303 )
{
struct V_10 * V_11 ;
int V_13 ;
unsigned long V_78 ;
V_11 = F_41 ( sizeof( struct V_10 ) , V_281 ) ;
if ( ! V_11 )
return - V_282 ;
V_13 = F_54 ( V_31 , V_303 , V_11 ) ;
if ( V_13 )
goto V_283;
V_13 = F_50 ( V_31 , V_11 ) ;
if ( V_13 )
goto V_283;
F_26 ( & V_31 -> V_307 , V_78 ) ;
memcpy ( & V_31 -> V_182 . V_183 , V_11 ,
sizeof( V_31 -> V_182 . V_183 ) ) ;
F_56 ( V_31 ) ;
F_30 ( & V_31 -> V_307 , V_78 ) ;
V_283:
F_43 ( V_11 -> V_216 ) ;
F_43 ( V_11 ) ;
return 0 ;
}
static int
F_57 ( struct V_30 * V_31 , T_1 * * V_308 ,
T_2 * V_211 , T_4 V_309 , T_1 * V_80 ,
bool V_130 , T_3 V_310 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_311 * V_312 ;
struct V_302 * V_303 ;
T_1 V_162 [ V_161 ] ;
T_3 V_313 ;
const T_1 * V_314 ;
T_5 V_315 ;
V_84 V_152 = 0 ;
V_84 V_316 = 0 ;
T_2 V_317 ;
T_2 V_318 ;
V_84 V_319 ;
V_84 V_320 ;
T_1 * V_204 ;
T_4 V_321 ;
struct V_322 * V_323 ;
struct V_324 * V_325 ;
if ( * V_211 >= sizeof( V_316 ) ) {
V_316 = F_23 ( * ( V_326 * ) ( * V_308 ) ) ;
* V_211 -= sizeof( V_316 ) ;
* V_308 += sizeof( V_316 ) ;
}
if ( ! V_316 || V_316 > * V_211 ) {
* V_308 += * V_211 ;
* V_211 = 0 ;
return - V_279 ;
}
V_204 = * V_308 ;
* V_308 += V_316 ;
* V_211 -= V_316 ;
V_317 = V_316 ;
if ( V_317 < V_161 + sizeof( T_1 ) +
sizeof( struct V_322 ) ) {
F_10 ( V_41 , ERROR ,
L_47 ) ;
return - V_279 ;
}
memcpy ( V_162 , V_204 , V_161 ) ;
V_204 += V_161 ;
V_317 -= V_161 ;
if ( ! V_130 ) {
V_313 = ( T_3 ) * V_204 ;
V_313 = ( - V_313 ) * 100 ;
V_204 += sizeof( T_1 ) ;
V_317 -= sizeof( T_1 ) ;
F_10 ( V_41 , V_42 ,
L_48 , V_313 ) ;
} else {
V_313 = V_310 ;
}
V_323 = (struct V_322 * ) V_204 ;
V_204 += sizeof( * V_323 ) ;
V_317 -= sizeof( * V_323 ) ;
V_321 = F_58 ( V_323 -> V_321 ) ;
V_319 = F_23 ( V_323 -> V_319 ) ;
V_320 = F_23 ( V_323 -> V_320 ) ;
F_10 ( V_41 , V_42 ,
L_49 ,
V_320 ) ;
V_314 = V_204 ;
V_315 = V_317 ;
F_10 ( V_41 , V_42 ,
L_50 ,
V_317 ) ;
while ( V_317 >= sizeof( struct V_218 ) ) {
T_1 V_16 , V_206 ;
V_16 = * V_204 ;
V_206 = * ( V_204 + 1 ) ;
if ( V_317 < V_206 +
sizeof( struct V_218 ) ) {
F_10 ( V_41 , ERROR ,
L_51 , V_8 ) ;
return - V_279 ;
}
if ( V_16 == V_224 ) {
V_152 = * ( V_204 +
sizeof( struct V_218 ) ) ;
break;
}
V_204 += V_206 + sizeof( struct V_218 ) ;
V_317 -= V_206 +
sizeof( struct V_218 ) ;
}
if ( V_152 ) {
struct V_68 * V_327 ;
T_1 V_65 ;
if ( V_152 == V_31 -> V_126 ) {
F_10 ( V_41 , V_274 ,
L_52 ) ;
return 0 ;
}
V_65 = V_270 ;
if ( V_80 )
V_65 = F_39 ( * V_80 &
( F_59 ( 0 ) | F_59 ( 1 ) ) ) ;
V_312 = F_51 ( V_31 , V_65 , V_152 , 0 ) ;
V_318 = V_312 ? V_312 -> V_318 : 0 ;
V_327 = F_60 ( V_31 -> V_73 . V_74 , V_318 ) ;
if ( V_327 && ! ( V_327 -> V_78 & V_79 ) ) {
V_303 = F_61 ( V_31 -> V_73 . V_74 ,
V_327 , V_328 ,
V_162 , V_321 ,
V_320 , V_319 ,
V_314 , V_315 , V_313 , V_281 ) ;
if ( V_303 ) {
V_325 = (struct V_324 * ) V_303 -> V_31 ;
V_325 -> V_65 = V_65 ;
V_325 -> V_309 = V_309 ;
if ( V_31 -> V_46 &&
! memcmp ( V_162 , V_31 -> V_182 .
V_183 . V_329 ,
V_161 ) )
F_55 ( V_31 ,
V_303 ) ;
F_62 ( V_31 -> V_73 . V_74 , V_303 ) ;
}
if ( ( V_327 -> V_78 & V_330 ) ||
( V_327 -> V_78 & V_85 ) ) {
F_10 ( V_41 , V_42 ,
L_53 ,
V_152 ) ;
F_53 ( V_31 , V_303 ) ;
}
}
} else {
F_10 ( V_41 , V_274 , L_54 ) ;
}
return 0 ;
}
static void F_63 ( struct V_30 * V_31 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
V_41 -> V_331 = 0 ;
if ( V_41 -> V_332 -> V_137 ) {
V_41 -> V_333 . V_334 = 0 ;
if ( ! V_31 -> V_108 ) {
F_10 ( V_41 , V_42 ,
L_55 ) ;
F_64 ( V_41 , V_41 -> V_332 ) ;
}
}
}
static int
F_65 ( struct V_30 * V_31 )
{
int V_13 ;
struct V_44 * V_41 = V_31 -> V_41 ;
T_1 V_335 = 0 ;
struct V_59 * V_336 ;
if ( V_41 -> V_337 || ! V_31 -> V_108 ) {
V_41 -> V_337 = false ;
return 0 ;
}
if ( ! V_31 -> V_305 [ 0 ] . V_91 ) {
F_10 ( V_41 , V_42 , L_56 ) ;
return 0 ;
}
V_336 = F_41 ( sizeof( * V_336 ) , V_281 ) ;
if ( ! V_336 )
return - V_282 ;
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
for ( V_335 = 0 ; V_335 < V_179 ; V_335 ++ ) {
if ( ! V_31 -> V_305 [ V_335 ] . V_91 )
break;
memcpy ( & V_336 -> V_81 [ V_335 ] ,
& V_31 -> V_305 [ V_335 ] ,
sizeof( struct V_338 ) ) ;
}
V_41 -> V_337 = true ;
V_336 -> V_163 = V_31 -> V_108 -> V_339 ;
V_336 -> V_164 = V_31 -> V_108 -> V_340 ;
V_13 = F_40 ( V_31 , V_336 ) ;
F_43 ( V_336 ) ;
memset ( & V_31 -> V_305 , 0 , sizeof( V_31 -> V_305 ) ) ;
if ( V_13 ) {
F_66 ( V_31 -> V_41 -> V_341 , L_57 , V_13 ) ;
return V_13 ;
}
return 0 ;
}
static void F_67 ( struct V_30 * V_31 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_118 * V_119 , * V_120 ;
unsigned long V_78 ;
F_26 ( & V_41 -> V_135 , V_78 ) ;
if ( F_44 ( & V_41 -> V_285 ) ) {
F_30 ( & V_41 -> V_135 , V_78 ) ;
F_26 ( & V_41 -> V_280 , V_78 ) ;
V_41 -> V_273 = false ;
F_30 ( & V_41 -> V_280 , V_78 ) ;
F_65 ( V_31 ) ;
if ( ! V_41 -> V_130 )
F_63 ( V_31 ) ;
if ( V_31 -> V_108 ) {
F_10 ( V_41 , V_42 ,
L_58 ) ;
F_68 ( V_31 -> V_108 , 0 ) ;
V_31 -> V_108 = NULL ;
} else {
V_31 -> V_342 = false ;
F_10 ( V_41 , V_42 ,
L_59 ) ;
}
} else if ( ( V_31 -> V_342 && ! V_31 -> V_108 ) ||
V_31 -> V_276 ) {
F_27 (cmd_node, tmp_node,
&adapter->scan_pending_q, list) {
F_28 ( & V_119 -> V_136 ) ;
F_29 ( V_41 , V_119 ) ;
}
F_30 ( & V_41 -> V_135 , V_78 ) ;
F_26 ( & V_41 -> V_280 , V_78 ) ;
V_41 -> V_273 = false ;
F_30 ( & V_41 -> V_280 , V_78 ) ;
if ( ! V_41 -> V_337 ) {
if ( V_31 -> V_108 ) {
F_10 ( V_41 , V_42 ,
L_60 ) ;
F_68 ( V_31 -> V_108 , 1 ) ;
V_31 -> V_108 = NULL ;
} else {
V_31 -> V_342 = false ;
F_10 ( V_41 , V_42 ,
L_59 ) ;
}
}
} else {
V_119 = F_45 ( & V_41 -> V_285 ,
struct V_118 , V_136 ) ;
F_28 ( & V_119 -> V_136 ) ;
F_30 ( & V_41 -> V_135 , V_78 ) ;
F_46 ( V_41 , V_119 , true ) ;
}
return;
}
int F_69 ( struct V_30 * V_31 ,
struct V_288 * V_343 )
{
int V_13 = 0 ;
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_344 * V_345 ;
struct V_184 * V_188 ;
struct V_346 * V_347 ;
T_1 * V_308 ;
T_2 V_348 ;
T_2 V_211 ;
T_2 V_301 ;
T_2 V_186 ;
struct V_349 * V_350 ;
struct V_351 * V_352 ;
T_1 V_353 ;
T_6 V_309 = 0 ;
T_1 * V_80 ;
struct V_354 * V_355 ;
struct V_356 * V_357 = NULL ;
V_353 = ( F_23 ( V_343 -> V_296 )
== V_358 ) ;
if ( V_353 )
V_345 = & V_343 -> V_293 . V_359 . V_360 ;
else
V_345 = & V_343 -> V_293 . V_360 ;
if ( V_345 -> V_361 > V_362 ) {
F_10 ( V_41 , ERROR ,
L_61 ,
V_345 -> V_361 ) ;
V_13 = - 1 ;
goto V_363;
}
F_22 ( V_31 ) ;
V_211 = F_23 ( V_345 -> V_364 ) ;
F_10 ( V_41 , V_42 ,
L_62 ,
V_211 ) ;
V_348 = F_23 ( V_343 -> V_297 ) ;
F_10 ( V_41 , V_42 ,
L_63 ,
V_345 -> V_361 ) ;
V_308 = V_345 -> V_365 ;
V_186 = V_348 - ( V_211
+ sizeof( V_345 -> V_364 )
+ sizeof( V_345 -> V_361 )
+ V_298 ) ;
V_188 = (struct V_184 * ) ( V_345 ->
V_365 +
V_211 ) ;
F_37 ( V_41 , V_188 , V_186 ,
V_193 ,
(struct V_184 * * )
& V_347 ) ;
F_37 ( V_41 , V_188 , V_186 ,
V_194 ,
(struct V_184 * * )
& V_350 ) ;
#ifdef F_70
if ( V_31 -> V_73 . V_74 -> V_366 )
V_357 = V_31 -> V_73 . V_74 -> V_366 -> V_357 ;
#endif
if ( V_357 ) {
V_41 -> V_367 =
F_41 ( sizeof( struct V_354 ) +
sizeof( struct V_354 * ) *
V_345 -> V_361 , V_368 ) ;
if ( V_41 -> V_367 )
V_41 -> V_367 -> V_369 = V_345 -> V_361 ;
}
for ( V_301 = 0 ; V_301 < V_345 -> V_361 && V_211 ; V_301 ++ ) {
if ( V_347 )
memcpy ( & V_309 , & V_347 -> V_370 [ V_301 * V_371 ] ,
sizeof( V_309 ) ) ;
if ( V_350 ) {
V_352 = & V_350 -> V_372 [ V_301 ] ;
V_80 = & V_352 -> V_80 ;
} else {
V_80 = NULL ;
}
if ( V_350 && V_41 -> V_367 ) {
V_41 -> V_367 -> V_373 [ V_301 ] =
F_41 ( sizeof( * V_355 ) +
sizeof( T_2 ) , V_368 ) ;
V_355 = V_41 -> V_367 -> V_373 [ V_301 ] ;
if ( V_355 ) {
memset ( V_355 , 0 , sizeof( * V_355 ) ) ;
if ( V_350 ) {
V_355 -> V_76 = 1 ;
V_355 -> V_77 [ 0 ] =
V_352 -> V_91 ;
}
}
}
V_13 = F_57 ( V_31 , & V_308 ,
& V_211 ,
F_58 ( V_309 ) ,
V_80 , false , 0 ) ;
if ( V_13 )
goto V_363;
}
V_363:
F_67 ( V_31 ) ;
return V_13 ;
}
int F_71 ( struct V_30 * V_31 ,
struct V_288 * V_289 ,
void * V_374 )
{
struct V_375 * V_130 = & V_289 -> V_293 . V_130 ;
struct V_97 * V_290 = V_374 ;
memcpy ( V_130 -> V_295 , V_290 -> V_106 , V_290 -> V_107 ) ;
V_289 -> V_296 = F_16 ( V_131 ) ;
V_289 -> V_297 = F_16 ( ( V_84 ) ( sizeof( V_130 -> V_376 )
+ V_290 -> V_107 + V_298 ) ) ;
return 0 ;
}
int F_72 ( struct V_30 * V_31 ,
struct V_288 * V_289 ,
void * V_374 )
{
struct V_377 * V_378 =
& V_289 -> V_293 . V_379 ;
struct V_95 * V_96 = V_374 ;
T_1 * V_104 = V_378 -> V_185 ;
T_1 V_148 ;
T_2 V_28 , V_70 , V_150 , V_151 , V_149 ;
int V_71 ;
struct V_140 * V_141 ;
struct V_380 * V_381 ;
struct V_382 * V_383 ;
struct V_384 * V_385 ;
struct V_144 * V_145 ;
struct V_114 * V_386 ;
struct V_61 * V_387 ;
V_289 -> V_296 = F_16 ( V_388 ) ;
V_289 -> V_297 = F_16 ( sizeof( * V_378 ) + V_298 ) ;
V_378 -> V_389 = F_16 ( V_96 -> V_389 ) ;
V_378 -> V_390 = V_96 -> V_390 ;
V_378 -> V_391 = V_96 -> V_391 ;
V_378 -> V_392 =
F_73 ( V_96 -> V_392 ) ;
V_378 -> V_393 =
F_73 ( V_96 -> V_393 ) ;
if ( ! V_378 -> V_390 )
return 0 ;
V_378 -> V_394 = V_96 -> V_394 ;
V_148 = ( V_96 -> V_148 ? V_96 ->
V_148 : V_31 -> V_41 -> V_158 ) ;
if ( V_148 ) {
V_141 = (struct V_140 * ) V_104 ;
V_141 -> V_110 . type = F_16 ( V_174 ) ;
V_141 -> V_110 . V_112 =
F_16 ( sizeof( V_141 -> V_148 ) ) ;
V_141 -> V_148 = F_16 ( ( V_84 ) V_148 ) ;
V_104 += sizeof( V_141 -> V_110 ) +
F_23 ( V_141 -> V_110 . V_112 ) ;
}
if ( V_96 -> V_395 ) {
V_381 =
(struct V_380 * ) V_104 ;
V_381 -> V_110 . type =
F_16 ( V_396 ) ;
V_381 -> V_110 . V_112 =
F_16 ( sizeof( V_381 -> V_395 ) ) ;
V_381 -> V_395 =
F_16 ( V_96 -> V_395 ) ;
V_104 += sizeof( V_381 -> V_110 ) +
F_23 ( V_381 -> V_110 . V_112 ) ;
}
if ( V_96 -> V_397 ) {
V_383 =
(struct V_382 * ) V_104 ;
V_383 -> V_110 . type =
F_16 ( V_398 ) ;
V_383 -> V_110 . V_112 =
F_16 ( sizeof( V_383 -> V_397 ) ) ;
V_383 -> V_397 =
F_16 ( V_96 -> V_397 ) ;
V_104 += sizeof( V_383 -> V_110 ) +
F_23 ( V_383 -> V_110 . V_112 ) ;
}
for ( V_71 = 0 ; V_71 < V_96 -> V_163 ; V_71 ++ ) {
V_28 = V_96 -> V_164 [ V_71 ] . V_29 . V_28 ;
V_145 =
(struct V_144 * ) V_104 ;
V_145 -> V_110 . type =
F_16 ( V_165 ) ;
V_145 -> V_110 . V_112 = F_16 (
( V_84 ) ( V_28 + sizeof( V_145 ->
V_166 ) ) ) ;
if ( V_28 )
V_145 -> V_166 = 0 ;
else
V_145 -> V_166 =
V_167 ;
memcpy ( V_145 -> V_29 ,
V_96 -> V_164 [ V_71 ] . V_29 . V_29 , V_28 ) ;
V_104 += ( sizeof( V_145 -> V_110 )
+ F_23 ( V_145 -> V_110 . V_112 ) ) ;
}
V_386 = (struct V_114 * ) V_104 ;
if ( V_96 -> V_81 [ 0 ] . V_91 ) {
F_74 ( V_31 -> V_41 -> V_341 , L_64 ) ;
V_386 -> V_110 . type = F_16 ( V_125 ) ;
for ( V_70 = 0 ;
V_70 < V_399 &&
V_96 -> V_81 [ V_70 ] . V_91 ;
V_70 ++ ) {
V_387 = V_386 -> V_127 + V_70 ;
F_24 ( & V_386 -> V_110 . V_112 ,
sizeof( V_386 -> V_127 ) ) ;
V_387 -> V_91 =
V_96 -> V_81 [ V_70 ] . V_91 ;
V_387 -> V_80 =
V_96 -> V_81 [ V_70 ] . V_80 ;
V_150 =
V_96 -> V_81 [ V_70 ] . V_150 ;
if ( V_150 == V_180 )
V_387 -> V_88
|= V_89 ;
else
V_387 -> V_88
&= ~ V_89 ;
if ( V_96 -> V_81 [ V_70 ] . V_82 ) {
V_151 = ( V_84 ) V_96 ->
V_81 [ V_70 ] . V_82 ;
} else {
V_151 = ( V_150 ==
V_180 ) ?
V_31 -> V_41 -> V_86 :
V_31 -> V_41 -> V_93 ;
}
V_387 -> V_181 = F_16 ( V_151 ) ;
V_387 -> V_83 = F_16 ( V_151 ) ;
}
} else {
F_74 ( V_31 -> V_41 -> V_341 ,
L_65 ) ;
V_149 =
F_17 ( V_31 , V_96 ,
V_386 ->
V_127 ) ;
F_24 ( & V_386 -> V_110 . V_112 ,
V_149 *
sizeof( V_386 -> V_127 [ 0 ] ) ) ;
}
V_104 += ( sizeof( V_386 -> V_110 )
+ F_23 ( V_386 -> V_110 . V_112 ) ) ;
if ( V_96 -> V_400 ) {
V_385 =
(struct V_384 * ) V_104 ;
V_385 -> V_110 . type =
F_16 ( V_401 ) ;
V_385 -> V_110 . V_112 =
F_16 ( sizeof( V_385 -> V_400 ) ) ;
V_385 -> V_400 =
F_16 ( V_96 -> V_400 ) ;
V_104 += sizeof( V_385 -> V_110 ) +
F_23 ( V_385 -> V_110 . V_112 ) ;
}
F_36 ( V_31 , V_402 , & V_104 ) ;
F_24 ( & V_289 -> V_297 , V_104 - V_378 -> V_185 ) ;
return 0 ;
}
int F_75 ( struct V_30 * V_31 )
{
struct V_95 * V_403 ;
if ( ! V_31 -> V_404 ) {
F_74 ( V_31 -> V_41 -> V_341 , L_66 ) ;
return 0 ;
}
V_403 = F_41 ( sizeof( * V_403 ) , V_281 ) ;
if ( ! V_403 )
return - V_282 ;
V_403 -> V_391 = V_405 ;
V_403 -> V_389 = V_406 ;
V_403 -> V_390 = false ;
if ( F_25 ( V_31 , V_388 ,
V_133 , 0 , V_403 , true ) ) {
F_43 ( V_403 ) ;
return - V_279 ;
}
F_43 ( V_403 ) ;
V_31 -> V_404 = false ;
return 0 ;
}
static void
F_76 ( struct V_30 * V_31 ,
struct V_407 * V_408 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
T_1 V_71 , V_409 ;
struct V_410 * V_411 ;
struct V_412 V_413 ;
V_411 = ( void * ) ( ( T_1 * ) V_408 +
sizeof( struct V_134 ) ) ;
V_409 = F_23 ( V_408 -> V_110 . V_112 ) /
sizeof( struct V_412 ) ;
for ( V_71 = 0 ; V_71 < V_409 ; V_71 ++ ) {
V_413 . V_149 = V_411 -> V_149 ;
V_413 . V_414 = V_411 -> V_414 ;
V_413 . V_78 = V_411 -> V_78 ;
V_413 . V_415 = V_411 -> V_415 ;
V_413 . V_416 = F_23 ( V_411 -> V_416 ) ;
V_413 . V_417 =
F_23 ( V_411 -> V_417 ) ;
V_413 . V_418 =
F_23 ( V_411 -> V_418 ) ;
F_10 ( V_41 , V_42 ,
L_67 ,
V_413 . V_149 ,
V_413 . V_415 ,
V_413 . V_416 ,
V_413 . V_417 ,
V_413 . V_418 ) ;
memcpy ( & V_41 -> V_413 [ V_41 -> V_331 ++ ] , & V_413 ,
sizeof( struct V_412 ) ) ;
V_411 ++ ;
}
}
int F_77 ( struct V_30 * V_31 ,
struct V_288 * V_343 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_375 * V_419 ;
struct V_134 * V_185 ;
struct V_407 * V_408 ;
V_84 V_420 , type , V_112 ;
struct V_288 * V_421 ;
struct V_118 * V_119 ;
unsigned long V_422 , V_423 ;
bool V_424 = false ;
F_10 ( V_41 , V_42 , L_68 ) ;
V_419 = & V_343 -> V_293 . V_130 ;
V_185 = ( void * ) V_419 -> V_295 ;
V_420 = F_23 ( V_343 -> V_297 ) - ( sizeof( * V_419 ) + V_298
- 1 ) ;
while ( V_420 >= sizeof( struct V_134 ) ) {
type = F_23 ( V_185 -> type ) ;
V_112 = F_23 ( V_185 -> V_112 ) ;
if ( V_420 < ( sizeof( struct V_134 ) + V_112 ) ) {
F_10 ( V_41 , ERROR ,
L_69 ) ;
break;
}
switch ( type ) {
case V_425 :
V_408 = ( void * ) V_185 ;
F_76 ( V_31 , V_408 ) ;
break;
default:
break;
}
V_420 -= V_112 + sizeof( struct V_134 ) ;
V_185 = ( void * ) ( ( T_1 * ) V_185 + V_112 +
sizeof( struct V_134 ) ) ;
}
F_26 ( & V_41 -> V_426 , V_422 ) ;
F_26 ( & V_41 -> V_135 , V_423 ) ;
if ( F_44 ( & V_41 -> V_285 ) ) {
V_424 = true ;
F_78 (cmd_node, &adapter->cmd_pending_q, list) {
V_421 = ( void * ) V_119 -> V_427 -> V_18 ;
if ( F_23 ( V_421 -> V_296 ) ==
V_131 ) {
F_10 ( V_41 , V_42 ,
L_70 ) ;
V_424 = false ;
break;
}
}
}
F_30 ( & V_41 -> V_135 , V_423 ) ;
F_30 ( & V_41 -> V_426 , V_422 ) ;
if ( V_424 )
F_63 ( V_31 ) ;
return 0 ;
}
int F_79 ( struct V_30 * V_31 ,
void * V_428 )
{
int V_13 = 0 ;
struct V_44 * V_41 = V_31 -> V_41 ;
T_1 * V_308 ;
T_2 V_211 , V_429 , V_301 ;
V_84 type , V_112 ;
struct V_184 * V_185 ;
struct V_430 * V_431 ;
struct V_432 * V_433 ;
T_1 * V_80 ;
T_4 V_309 = 0 ;
T_3 V_313 = 0 ;
struct V_434 * V_435 = V_428 ;
T_1 V_436 = V_435 -> V_436 ;
T_1 * V_360 = V_428 + sizeof( struct V_434 ) ;
V_84 V_348 = F_23 ( V_435 -> V_437 ) ;
if ( V_436 > V_362 ) {
F_10 ( V_41 , ERROR ,
L_71 ,
V_436 ) ;
V_13 = - 1 ;
goto V_363;
}
V_211 = V_348 ;
F_10 ( V_41 , V_42 ,
L_72 ,
V_348 , V_436 ) ;
F_80 ( V_41 , V_438 , L_73 , V_428 ,
V_348 +
sizeof( struct V_434 ) ) ;
V_185 = (struct V_184 * ) V_360 ;
for ( V_301 = 0 ; V_301 < V_436 && V_211 ; V_301 ++ ) {
type = F_23 ( V_185 -> V_110 . type ) ;
V_112 = F_23 ( V_185 -> V_110 . V_112 ) ;
if ( V_211 < sizeof( struct V_134 ) + V_112 ) {
F_10 ( V_41 , ERROR ,
L_74 ) ;
break;
}
V_431 = NULL ;
V_433 = NULL ;
V_429 = V_211 ;
if ( type != V_439 )
break;
V_308 = ( T_1 * ) V_185 ;
V_431 = (struct V_430 * ) V_185 ;
V_185 = (struct V_184 * ) ( V_185 -> V_18 + V_112 ) ;
V_429 -=
( V_112 + sizeof( struct V_134 ) ) ;
while ( V_429 >=
sizeof( struct V_134 ) &&
F_23 ( V_185 -> V_110 . type ) != V_439 ) {
type = F_23 ( V_185 -> V_110 . type ) ;
V_112 = F_23 ( V_185 -> V_110 . V_112 ) ;
if ( V_429 <
sizeof( struct V_134 ) + V_112 ) {
F_10 ( V_41 , ERROR ,
L_75
L_76 ) ;
V_431 = NULL ;
V_429 = 0 ;
continue;
}
switch ( type ) {
case V_440 :
V_433 =
(struct V_432 * ) V_185 ;
if ( V_112 !=
sizeof( struct V_432 ) -
sizeof( struct V_134 ) ) {
V_429 = 0 ;
continue;
}
break;
default:
break;
}
V_185 = (struct V_184 * ) ( V_185 -> V_18 + V_112 ) ;
V_211 -=
( V_112 + sizeof( struct V_134 ) ) ;
V_429 -=
( V_112 + sizeof( struct V_134 ) ) ;
}
if ( ! V_431 )
break;
V_308 += sizeof( V_84 ) ;
V_211 -= sizeof( V_84 ) ;
if ( V_433 ) {
V_313 = ( T_3 ) ( V_441 ) ( F_23 ( V_433 -> V_313 ) ) ;
V_313 *= 100 ;
F_10 ( V_41 , V_42 ,
L_48 , V_313 ) ;
V_309 = F_58 ( V_433 -> V_442 ) ;
V_80 = & V_433 -> V_80 ;
} else {
V_80 = NULL ;
}
V_13 = F_57 ( V_31 , & V_308 ,
& V_211 , V_309 ,
V_80 , true , V_313 ) ;
if ( V_13 )
goto V_363;
}
V_363:
if ( ! V_435 -> V_443 )
F_67 ( V_31 ) ;
return V_13 ;
}
int F_81 ( struct V_288 * V_289 )
{
struct V_444 * V_445 =
& V_289 -> V_293 . V_446 ;
V_289 -> V_296 = F_16 ( V_358 ) ;
V_289 -> V_297 = F_16 ( sizeof( struct V_444 )
+ V_298 ) ;
V_445 -> V_447 = 1 ;
return 0 ;
}
void
F_82 ( struct V_30 * V_31 ,
struct V_118 * V_119 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
unsigned long V_78 ;
V_119 -> V_137 = true ;
V_119 -> V_448 = & V_41 -> V_449 ;
F_26 ( & V_41 -> V_135 , V_78 ) ;
F_83 ( & V_119 -> V_136 , & V_41 -> V_285 ) ;
F_30 ( & V_41 -> V_135 , V_78 ) ;
}
static int F_84 ( struct V_30 * V_31 ,
struct V_25 * V_450 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
int V_13 ;
struct V_59 * V_290 ;
if ( V_41 -> V_273 ) {
F_10 ( V_41 , V_274 ,
L_41 ) ;
return - V_275 ;
}
if ( V_31 -> V_276 ) {
F_10 ( V_41 , V_274 ,
L_42 ) ;
return - V_275 ;
}
V_290 = F_41 ( sizeof( struct V_59 ) , V_281 ) ;
if ( ! V_290 )
return - V_282 ;
V_290 -> V_164 = V_450 ;
V_290 -> V_163 = 1 ;
V_13 = F_40 ( V_31 , V_290 ) ;
F_43 ( V_290 ) ;
return V_13 ;
}
int F_85 ( struct V_30 * V_31 ,
struct V_25 * V_450 )
{
int V_13 ;
if ( F_86 ( & V_31 -> V_451 ) ) {
F_10 ( V_31 -> V_41 , ERROR ,
L_77 ,
V_8 ) ;
return - 1 ;
}
V_31 -> V_41 -> V_449 = false ;
if ( V_450 && V_450 -> V_28 != 0 )
V_13 = F_84 ( V_31 , V_450 ) ;
else
V_13 = F_40 ( V_31 , NULL ) ;
F_87 ( & V_31 -> V_451 ) ;
return V_13 ;
}
int
F_36 ( struct V_30 * V_31 ,
V_84 V_452 , T_1 * * V_453 )
{
int V_335 , V_454 = 0 ;
struct V_455 * V_456 ;
if ( ! V_453 )
return 0 ;
if ( ! ( * V_453 ) )
return 0 ;
for ( V_335 = 0 ; V_335 < V_457 ; V_335 ++ ) {
if ( V_31 -> V_458 [ V_335 ] . V_459 & V_452 ) {
V_456 =
(struct V_455 * )
* V_453 ;
V_456 -> V_110 . type =
F_16 ( V_460 ) ;
V_456 -> V_110 . V_112 =
F_16 ( ( ( ( V_84 ) V_31 -> V_458 [ V_335 ] . V_461 [ 1 ] )
& 0x00FF ) + 2 ) ;
memcpy ( V_456 -> V_461 , V_31 -> V_458 [ V_335 ] . V_461 ,
F_23 ( V_456 -> V_110 . V_112 ) ) ;
* V_453 += F_23 ( V_456 -> V_110 . V_112 ) +
sizeof( struct V_134 ) ;
V_454 += F_23 ( V_456 -> V_110 . V_112 ) +
sizeof( struct V_134 ) ;
}
}
return V_454 ;
}
void
F_56 ( struct V_30 * V_31 )
{
struct V_10 * V_462 =
& V_31 -> V_182 . V_183 ;
if ( ! V_462 -> V_217 )
return;
if ( ! V_31 -> V_463 ||
V_31 -> V_464 != V_462 -> V_217 ) {
V_31 -> V_464 = V_462 -> V_217 ;
F_43 ( V_31 -> V_463 ) ;
V_31 -> V_463 = F_88 ( V_462 -> V_217 ,
V_368 ) ;
if ( ! V_31 -> V_463 )
return;
}
memcpy ( V_31 -> V_463 , V_462 -> V_216 ,
V_462 -> V_217 ) ;
F_10 ( V_31 -> V_41 , V_42 ,
L_78 ,
V_31 -> V_464 ) ;
V_462 -> V_216 = V_31 -> V_463 ;
if ( V_462 -> V_21 )
V_462 -> V_21 =
(struct V_212 * )
( V_462 -> V_216 +
V_462 -> V_239 ) ;
if ( V_462 -> V_14 )
V_462 -> V_14 = (struct V_243 * )
( V_462 -> V_216 +
V_462 -> V_244 ) ;
if ( V_462 -> V_56 )
V_462 -> V_56 = (struct V_177 * )
( V_462 -> V_216 +
V_462 -> V_246 ) ;
if ( V_462 -> V_248 )
V_462 -> V_248 = (struct V_249 * )
( V_462 -> V_216 +
V_462 -> V_250 ) ;
if ( V_462 -> V_253 )
V_462 -> V_253 = ( void * ) ( V_462 -> V_216 +
V_462 -> V_254 ) ;
if ( V_462 -> V_256 )
V_462 -> V_256 = ( void * ) ( V_462 -> V_216 +
V_462 -> V_257 ) ;
if ( V_462 -> V_259 )
V_462 -> V_259 =
( V_462 -> V_216 + V_462 -> V_260 ) ;
if ( V_462 -> V_262 )
V_462 -> V_262 = V_462 -> V_216 +
V_462 -> V_263 ;
if ( V_462 -> V_265 )
V_462 -> V_265 = ( void * ) ( V_462 -> V_216 +
V_462 -> V_266 ) ;
}
void
F_89 ( struct V_30 * V_31 )
{
F_43 ( V_31 -> V_463 ) ;
V_31 -> V_463 = NULL ;
}
