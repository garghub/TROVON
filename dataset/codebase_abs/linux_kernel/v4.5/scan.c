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
struct V_95 * V_96 ,
T_1 V_97 )
{
struct V_98 * V_99 ;
T_1 V_100 [ V_101 ] , * V_102 ;
T_2 V_103 ;
memset ( V_100 , 0 , sizeof( V_100 ) ) ;
V_102 = ( T_1 * ) V_96 -> V_104 + V_96 -> V_105 ;
if ( V_31 -> V_106 )
V_103 = F_18 ( V_31 , V_100 ,
V_97 ) ;
else
V_103 = F_19 ( V_31 , V_100 ) ;
F_10 ( V_31 -> V_41 , V_107 ,
L_18 ,
V_103 ) ;
V_99 = (struct V_98 * ) V_102 ;
V_99 -> V_108 . type = F_16 ( V_109 ) ;
V_99 -> V_108 . V_110 = F_16 ( ( V_84 ) V_103 ) ;
memcpy ( V_99 -> V_100 , V_100 , V_103 ) ;
V_96 -> V_105 += sizeof( V_99 -> V_108 ) + V_103 ;
return V_103 ;
}
static int
F_20 ( struct V_30 * V_31 ,
T_2 V_111 , T_1 V_63 ,
struct V_95 * V_96 ,
struct V_112
* V_113 ,
struct V_61 * V_62 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
int V_13 = 0 ;
struct V_61 * V_114 ;
struct V_61 * V_115 ;
struct V_116 * V_117 , * V_118 ;
unsigned long V_78 ;
T_2 V_119 , V_103 , V_120 ;
T_2 V_121 ;
T_2 V_122 ;
T_1 V_80 ;
if ( ! V_96 || ! V_113 || ! V_62 ) {
F_10 ( V_31 -> V_41 , ERROR ,
L_19 ,
V_96 , V_113 , V_62 ) ;
return - 1 ;
}
F_21 ( V_31 ) ;
V_113 -> V_108 . type = F_16 ( V_123 ) ;
V_114 = V_62 ;
while ( V_114 -> V_91 ) {
V_119 = 0 ;
V_121 = 0 ;
V_80 = 0 ;
V_113 -> V_108 . V_110 = 0 ;
V_115 = V_114 ;
V_122 = false ;
while ( V_119 < V_111 &&
V_114 -> V_91 && ! V_122 ) {
if ( V_114 -> V_91 == V_31 -> V_124 ) {
V_114 ++ ;
continue;
}
V_80 = V_114 -> V_80 ;
F_10 ( V_31 -> V_41 , V_42 ,
L_20
L_21 ,
V_114 -> V_91 ,
V_114 -> V_80 ,
V_114 -> V_88
& V_89 ,
( V_114 -> V_88
& V_94 ) >> 1 ,
F_22 ( V_114 -> V_83 ) ) ;
memcpy ( V_113 -> V_125 + V_119 ,
V_114 ,
sizeof( V_113 -> V_125 ) ) ;
F_23 ( & V_113 -> V_108 . V_110 ,
sizeof( V_113 -> V_125 ) ) ;
V_96 -> V_105 = ( T_2 ) ( ( T_1 * ) V_113 -
V_96 -> V_104 ) ;
V_96 -> V_105 +=
( sizeof( V_113 -> V_108 )
+ F_22 ( V_113 -> V_108 . V_110 ) ) ;
V_119 ++ ;
V_121 +=
F_22 ( V_114 -> V_83 ) ;
V_122 = false ;
if ( ! V_63 &&
( V_114 -> V_91 == 1 ||
V_114 -> V_91 == 6 ||
V_114 -> V_91 == 11 ) )
V_122 = true ;
V_114 ++ ;
if ( ! V_63 &&
( V_114 -> V_91 == 1 ||
V_114 -> V_91 == 6 ||
V_114 -> V_91 == 11 ) )
V_122 = true ;
}
if ( V_121 > V_126 ) {
F_10 ( V_31 -> V_41 , ERROR ,
L_22
L_23 ,
V_121 ,
V_126 ) ;
V_13 = - 1 ;
break;
}
V_103 = F_17 ( V_31 , V_96 ,
V_80 ) ;
V_31 -> V_41 -> V_127 = V_115 ;
if ( V_31 -> V_41 -> V_128 )
V_120 = V_129 ;
else
V_120 = V_130 ;
V_13 = F_24 ( V_31 , V_120 , V_131 ,
0 , V_96 , false ) ;
V_96 -> V_105 -=
sizeof( struct V_132 ) + V_103 ;
if ( V_13 ) {
F_25 ( & V_41 -> V_133 , V_78 ) ;
F_26 (cmd_node, tmp_node,
&adapter->scan_pending_q,
list) {
F_27 ( & V_117 -> V_134 ) ;
V_117 -> V_135 = false ;
F_28 ( V_41 , V_117 ) ;
}
F_29 ( & V_41 -> V_133 ,
V_78 ) ;
break;
}
}
if ( V_13 )
return - 1 ;
return 0 ;
}
static void
F_30 ( struct V_30 * V_31 ,
const struct V_59 * V_60 ,
struct V_95 * V_96 ,
struct V_112 * * V_136 ,
struct V_61 * V_62 ,
T_1 * V_111 , T_1 * V_63 ,
T_1 * V_137 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
T_1 * V_102 ;
T_2 V_146 ;
T_2 V_28 ;
T_2 V_70 ;
T_2 V_147 ;
T_2 V_148 ;
V_84 V_149 ;
T_1 V_150 ;
T_1 V_80 ;
int V_71 ;
T_1 V_151 ;
struct V_152 * V_153 ;
struct V_154 * V_47 ;
V_96 -> V_105 = 0 ;
V_102 = V_96 -> V_104 ;
* V_63 = false ;
* V_137 = false ;
if ( V_60 ) {
V_151 = true ;
V_96 -> V_47 =
( V_60 -> V_47 ? ( T_1 ) V_60 ->
V_47 : ( T_1 ) V_41 -> V_155 ) ;
V_146 =
( V_60 -> V_146 ? V_60 ->
V_146 : V_41 -> V_156 ) ;
memcpy ( V_96 -> V_157 ,
V_60 -> V_157 ,
sizeof( V_96 -> V_157 ) ) ;
if ( V_41 -> V_128 &&
! F_31 ( V_96 -> V_157 ) ) {
V_145 =
(struct V_144 * ) V_102 ;
V_145 -> V_108 . type = F_16 ( V_158 ) ;
V_145 -> V_108 . V_110 = F_16 ( V_159 ) ;
memcpy ( V_145 -> V_160 , V_60 -> V_157 ,
V_159 ) ;
V_102 += sizeof( struct V_144 ) ;
}
for ( V_71 = 0 ; V_71 < V_60 -> V_161 ; V_71 ++ ) {
V_28 = V_60 -> V_162 [ V_71 ] . V_28 ;
V_143 =
(struct V_142 * )
V_102 ;
V_143 -> V_108 . type =
F_16 ( V_163 ) ;
V_143 -> V_108 . V_110 = F_16 (
( V_84 ) ( V_28 + sizeof( V_143 ->
V_164 ) ) ) ;
if ( V_28 )
V_143 -> V_164 = 0 ;
else
V_143 -> V_164 =
V_165 ;
if ( ! memcmp ( V_60 -> V_162 [ V_71 ] . V_29 ,
L_24 , 7 ) )
V_143 -> V_164 = 0xfe ;
memcpy ( V_143 -> V_29 ,
V_60 -> V_162 [ V_71 ] . V_29 , V_28 ) ;
V_102 += ( sizeof( V_143 -> V_108 )
+ F_22 ( V_143 -> V_108 . V_110 ) ) ;
F_10 ( V_41 , V_42 ,
L_25 ,
V_71 , V_143 -> V_29 ,
V_143 -> V_164 ) ;
if ( ! V_28 && V_143 -> V_164 )
V_151 = false ;
}
if ( ( V_71 && V_151 ) ||
! F_31 ( V_96 -> V_157 ) )
* V_63 = true ;
if ( V_60 -> V_166 ) {
F_10 ( V_41 , V_42 ,
L_26 ,
V_60 -> V_166 ) ;
* V_111 =
V_167 ;
V_141 = ( void * ) V_102 ;
V_141 -> V_108 . type =
F_16 ( V_168 ) ;
V_141 -> V_108 . V_110 =
F_16 ( sizeof( V_141 -> V_169 ) ) ;
V_141 -> V_169 =
F_16 ( ( V_60 -> V_166 ) ) ;
V_102 +=
sizeof( struct V_140 ) ;
}
} else {
V_96 -> V_47 = ( T_1 ) V_41 -> V_155 ;
V_146 = V_41 -> V_156 ;
}
if ( * V_63 )
* V_111 = V_167 ;
else
* V_111 = V_170 ;
if ( V_41 -> V_128 ) {
V_47 = (struct V_154 * ) V_102 ;
V_47 -> V_108 . type = F_16 ( V_171 ) ;
V_47 -> V_108 . V_110 = F_16 ( sizeof( V_47 -> V_47 ) ) ;
V_47 -> V_47 = V_96 -> V_47 ;
V_102 += sizeof( V_47 -> V_108 ) +
F_22 ( V_47 -> V_108 . V_110 ) ;
}
if ( V_146 ) {
F_10 ( V_41 , V_42 ,
L_27 ,
V_146 ) ;
V_139 = (struct V_138 * ) V_102 ;
V_139 -> V_108 . type = F_16 ( V_172 ) ;
V_139 -> V_108 . V_110 =
F_16 ( sizeof( V_139 -> V_146 ) ) ;
V_139 -> V_146 = F_16 ( ( V_84 ) V_146 ) ;
V_102 += sizeof( V_139 -> V_108 ) +
F_22 ( V_139 -> V_108 . V_110 ) ;
}
if ( F_32 ( V_31 -> V_41 -> V_173 ) &&
( V_31 -> V_41 -> V_53 & V_54 ||
V_31 -> V_41 -> V_53 & V_55 ) ) {
V_153 = (struct V_152 * ) V_102 ;
memset ( V_153 , 0 , sizeof( struct V_152 ) ) ;
V_153 -> V_108 . type = F_16 ( V_174 ) ;
V_153 -> V_108 . V_110 =
F_16 ( sizeof( struct V_175 ) ) ;
V_80 =
F_33 ( V_31 -> V_41 -> V_53 ) ;
F_34 ( V_31 , V_80 , & V_153 -> V_153 ) ;
V_102 += sizeof( struct V_152 ) ;
}
F_35 ( V_31 , V_176 , & V_102 ) ;
* V_136 =
(struct V_112 * ) V_102 ;
if ( V_60 && V_60 -> V_81 [ 0 ] . V_91 ) {
F_10 ( V_41 , V_42 ,
L_28 ) ;
for ( V_70 = 0 ;
V_70 < V_177 &&
V_60 -> V_81 [ V_70 ] . V_91 ;
V_70 ++ ) {
V_150 = V_60 -> V_81 [ V_70 ] . V_91 ;
( V_62 + V_70 ) -> V_91 = V_150 ;
V_80 =
V_60 -> V_81 [ V_70 ] . V_80 ;
( V_62 + V_70 ) -> V_80 = V_80 ;
V_148 = V_60 -> V_81 [ V_70 ] . V_148 ;
if ( V_148 == V_178 )
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
V_149 = ( V_84 ) V_60 ->
V_81 [ V_70 ] . V_82 ;
} else {
if ( V_148 == V_178 )
V_149 = V_41 -> V_86 ;
else if ( * V_63 )
V_149 = V_41 -> V_93 ;
else
V_149 = V_41 -> V_87 ;
}
( V_62 + V_70 ) -> V_179 =
F_16 ( V_149 ) ;
( V_62 + V_70 ) -> V_83 =
F_16 ( V_149 ) ;
}
if ( ( V_70 == 1 ) &&
( V_60 -> V_81 [ 0 ] . V_91 ==
V_31 -> V_180 . V_181 . V_150 ) ) {
* V_137 = true ;
F_10 ( V_41 , V_42 ,
L_29 ) ;
}
V_147 = V_70 ;
} else {
F_10 ( V_41 , V_42 ,
L_30 ) ;
V_147 = F_15 ( V_31 , V_60 ,
V_62 ,
* V_63 ) ;
}
}
static void
F_36 ( struct V_44 * V_41 ,
struct V_182 * V_183 ,
T_2 V_184 , T_2 V_185 ,
struct V_182 * * V_186 )
{
struct V_182 * V_187 ;
T_2 V_188 ;
T_2 V_189 ;
T_2 V_190 ;
V_187 = V_183 ;
V_188 = V_184 ;
* V_186 = NULL ;
F_10 ( V_41 , V_42 ,
L_31 ,
V_184 ) ;
while ( V_188 >= sizeof( struct V_132 ) ) {
V_189 = F_22 ( V_187 -> V_108 . type ) ;
V_190 = F_22 ( V_187 -> V_108 . V_110 ) ;
if ( sizeof( V_183 -> V_108 ) + V_190 > V_188 ) {
F_10 ( V_41 , ERROR ,
L_32 ) ;
break;
}
if ( V_185 == V_189 ) {
switch ( V_189 ) {
case V_191 :
F_10 ( V_41 , V_42 ,
L_33
L_34 ,
V_190 ) ;
* V_186 = V_187 ;
break;
case V_192 :
F_10 ( V_41 , V_42 ,
L_35
L_36 ,
V_190 ) ;
* V_186 = V_187 ;
break;
default:
F_10 ( V_41 , ERROR ,
L_37 ,
V_189 ) ;
return;
}
}
if ( * V_186 )
break;
V_188 -= ( sizeof( V_183 -> V_108 ) + V_190 ) ;
V_187 =
(struct V_182 * ) ( V_187 -> V_18 +
V_190 ) ;
}
}
int F_37 ( struct V_44 * V_41 ,
struct V_10 * V_193 )
{
int V_13 = 0 ;
T_1 V_16 ;
struct V_194 * V_195 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
T_1 * V_202 ;
T_1 * V_203 ;
T_1 V_204 ;
V_84 V_205 ;
T_1 V_206 ;
T_1 V_207 ;
T_1 V_208 ;
T_2 V_209 ;
struct V_210 * V_211 ;
const T_1 V_212 [ 4 ] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_1 V_213 [ 4 ] = { 0x00 , 0x50 , 0xf2 , 0x02 } ;
V_208 = false ;
V_207 = 0 ;
V_202 = V_193 -> V_214 ;
V_209 = V_193 -> V_215 ;
while ( V_209 >= 2 ) {
V_16 = * V_202 ;
V_204 = * ( V_202 + 1 ) ;
V_205 = V_204 + sizeof( struct V_216 ) ;
if ( V_209 < V_205 ) {
F_10 ( V_41 , ERROR ,
L_38
L_39 ) ;
return - 1 ;
}
switch ( V_16 ) {
case V_217 :
V_193 -> V_29 . V_28 = V_204 ;
memcpy ( V_193 -> V_29 . V_29 , ( V_202 + 2 ) ,
V_204 ) ;
F_10 ( V_41 , V_42 ,
L_40 ,
V_193 -> V_29 . V_29 ) ;
break;
case V_109 :
memcpy ( V_193 -> V_218 , V_202 + 2 ,
V_204 ) ;
memcpy ( V_193 -> V_219 , V_202 + 2 ,
V_204 ) ;
V_207 = V_204 ;
V_208 = true ;
break;
case V_220 :
V_195 =
(struct V_194 * ) V_202 ;
memcpy ( & V_193 -> V_221 . V_195 ,
V_195 ,
sizeof( struct V_194 ) ) ;
break;
case V_222 :
V_197 =
(struct V_196 * ) V_202 ;
V_193 -> V_150 = V_197 -> V_223 ;
memcpy ( & V_193 -> V_221 . V_197 ,
V_197 ,
sizeof( struct V_196 ) ) ;
break;
case V_224 :
V_199 =
(struct V_198 * ) V_202 ;
memcpy ( & V_193 -> V_225 . V_199 ,
V_199 ,
sizeof( struct V_198 ) ) ;
break;
case V_226 :
V_201 =
(struct V_200 * )
V_202 ;
memcpy ( & V_193 -> V_225 . V_201 ,
V_201 ,
sizeof( struct V_200 ) ) ;
break;
case V_227 :
V_193 -> V_228 = * ( V_202 + 2 ) ;
break;
case V_229 :
V_193 -> V_230 = * ( V_202 + 2 ) ;
V_193 -> V_231 = true ;
break;
case V_232 :
V_193 -> V_52 = true ;
case V_233 :
case V_234 :
case V_235 :
V_193 -> V_231 = true ;
break;
case V_236 :
if ( V_208 ) {
if ( ( V_204 + V_207 ) >
V_101 )
V_206 =
( V_101 -
V_207 ) ;
else
V_206 = V_204 ;
V_203 = ( T_1 * ) V_193 -> V_218 ;
V_203 += V_207 ;
memcpy ( V_203 , V_202 + 2 , V_206 ) ;
V_203 = ( T_1 * ) V_193 -> V_219 ;
V_203 += V_207 ;
memcpy ( V_203 , V_202 + 2 , V_206 ) ;
}
break;
case V_23 :
V_211 = (struct V_210 * )
V_202 ;
if ( ! memcmp
( V_211 -> V_22 . V_3 , V_212 ,
sizeof( V_212 ) ) ) {
V_193 -> V_21 =
(struct V_210 * )
V_202 ;
V_193 -> V_237 = ( V_84 )
( V_202 - V_193 -> V_214 ) ;
} else if ( ! memcmp ( V_211 -> V_22 . V_3 , V_213 ,
sizeof( V_213 ) ) ) {
if ( V_205 ==
sizeof( struct V_238 ) ||
V_205 ==
sizeof( struct V_239 ) )
memcpy ( ( T_1 * ) & V_193 -> V_240 ,
V_202 , V_205 ) ;
}
break;
case V_17 :
V_193 -> V_14 =
(struct V_241 * ) V_202 ;
V_193 -> V_242 = ( V_84 ) ( V_202 -
V_193 -> V_214 ) ;
break;
case V_35 :
V_193 -> V_34 =
(struct V_241 * ) V_202 ;
V_193 -> V_243 = ( V_84 ) ( V_202 -
V_193 -> V_214 ) ;
break;
case V_174 :
V_193 -> V_56 = (struct V_175 * )
( V_202 +
sizeof( struct V_216 ) ) ;
V_193 -> V_244 = ( V_84 ) ( V_202 +
sizeof( struct V_216 ) -
V_193 -> V_214 ) ;
break;
case V_245 :
V_193 -> V_246 =
(struct V_247 * ) ( V_202 +
sizeof( struct V_216 ) ) ;
V_193 -> V_248 = ( V_84 ) ( V_202 +
sizeof( struct V_216 ) -
V_193 -> V_214 ) ;
break;
case V_249 :
V_193 -> V_250 = false ;
V_193 -> V_251 =
( void * ) ( V_202 +
sizeof( struct V_216 ) ) ;
V_193 -> V_252 =
( V_84 ) ( ( T_1 * ) V_193 -> V_251 -
V_193 -> V_214 ) ;
break;
case V_253 :
V_193 -> V_254 =
( void * ) ( V_202 +
sizeof( struct V_216 ) ) ;
V_193 -> V_255 =
( V_84 ) ( ( T_1 * ) V_193 -> V_254 -
V_193 -> V_214 ) ;
break;
case V_256 :
V_193 -> V_257 = V_202 ;
V_193 -> V_258 =
( V_84 ) ( V_202 - V_193 -> V_214 ) ;
break;
case V_259 :
V_193 -> V_260 = V_202 ;
V_193 -> V_261 =
( V_84 ) ( V_202 - V_193 -> V_214 ) ;
break;
case V_262 :
V_193 -> V_263 = ( void * ) V_202 ;
V_193 -> V_264 =
( V_84 ) ( ( T_1 * ) V_193 -> V_263 -
V_193 -> V_214 ) ;
break;
default:
break;
}
V_202 += V_204 + 2 ;
V_209 -= ( V_204 + 2 ) ;
}
return V_13 ;
}
static T_1
F_38 ( T_1 V_80 )
{
switch ( V_80 ) {
case V_265 :
return V_266 ;
case V_267 :
default:
return V_268 ;
}
}
int F_39 ( struct V_30 * V_31 ,
const struct V_59 * V_60 )
{
int V_13 ;
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_116 * V_117 ;
union V_269 * V_96 ;
struct V_112 * V_136 ;
struct V_61 * V_62 ;
T_1 V_63 ;
T_1 V_270 ;
T_1 V_111 ;
unsigned long V_78 ;
if ( V_41 -> V_271 ) {
F_10 ( V_41 , V_272 ,
L_41 ) ;
return - V_273 ;
}
if ( V_31 -> V_274 ) {
F_10 ( V_41 , V_272 ,
L_42 ) ;
return - V_273 ;
}
if ( V_41 -> V_275 || V_41 -> V_276 ) {
F_10 ( V_41 , ERROR ,
L_43 ) ;
return - V_277 ;
}
F_25 ( & V_41 -> V_278 , V_78 ) ;
V_41 -> V_271 = true ;
F_29 ( & V_41 -> V_278 , V_78 ) ;
V_96 = F_40 ( sizeof( union V_269 ) ,
V_279 ) ;
if ( ! V_96 ) {
V_13 = - V_280 ;
goto V_281;
}
V_62 = F_41 ( V_177 ,
sizeof( struct V_61 ) ,
V_279 ) ;
if ( ! V_62 ) {
F_42 ( V_96 ) ;
V_13 = - V_280 ;
goto V_281;
}
F_30 ( V_31 , V_60 , & V_96 -> V_282 ,
& V_136 , V_62 , & V_111 ,
& V_63 , & V_270 ) ;
V_13 = F_20 ( V_31 , V_111 , V_63 ,
& V_96 -> V_282 , V_136 ,
V_62 ) ;
if ( ! V_13 ) {
F_25 ( & V_41 -> V_133 , V_78 ) ;
if ( ! F_43 ( & V_41 -> V_283 ) ) {
V_117 = F_44 ( & V_41 -> V_283 ,
struct V_116 , V_134 ) ;
F_27 ( & V_117 -> V_134 ) ;
F_29 ( & V_41 -> V_133 ,
V_78 ) ;
F_45 ( V_41 , V_117 ,
true ) ;
F_46 ( V_41 -> V_284 , & V_41 -> V_285 ) ;
if ( ! V_31 -> V_106 ) {
F_10 ( V_41 , V_42 ,
L_44 ) ;
F_47 ( V_41 , V_117 ) ;
}
} else {
F_29 ( & V_41 -> V_133 ,
V_78 ) ;
}
}
F_42 ( V_96 ) ;
F_42 ( V_62 ) ;
V_281:
if ( V_13 ) {
F_25 ( & V_41 -> V_278 , V_78 ) ;
V_41 -> V_271 = false ;
F_29 ( & V_41 -> V_278 , V_78 ) ;
}
return V_13 ;
}
int F_48 ( struct V_286 * V_287 ,
struct V_95 * V_288 )
{
struct V_289 * V_290 = & V_287 -> V_291 . V_292 ;
V_290 -> V_47 = V_288 -> V_47 ;
memcpy ( V_290 -> V_160 , V_288 -> V_157 ,
sizeof( V_290 -> V_160 ) ) ;
memcpy ( V_290 -> V_293 , V_288 -> V_104 , V_288 -> V_105 ) ;
V_287 -> V_294 = F_16 ( V_130 ) ;
V_287 -> V_295 = F_16 ( ( V_84 ) ( sizeof( V_290 -> V_47 )
+ sizeof( V_290 -> V_160 )
+ V_288 -> V_105 + V_296 ) ) ;
return 0 ;
}
int F_49 ( struct V_30 * V_31 ,
struct V_10 * V_11 )
{
int V_13 = - 1 ;
if ( ! V_11 )
return - 1 ;
if ( ( F_50 ( V_31 , ( T_1 ) V_11 -> V_297 ,
( V_84 ) V_11 -> V_150 , 0 ) ) ) {
switch ( V_31 -> V_47 ) {
case V_48 :
case V_298 :
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
static bool F_51 ( struct V_25 * V_29 )
{
int V_299 ;
for ( V_299 = 0 ; V_299 < V_29 -> V_28 ; V_299 ++ ) {
if ( V_29 -> V_29 [ V_299 ] )
return false ;
}
return true ;
}
static int F_52 ( struct V_30 * V_31 ,
struct V_300 * V_301 )
{
struct V_10 * V_11 ;
int V_13 ;
int V_302 ;
V_11 = F_40 ( sizeof( * V_11 ) , V_279 ) ;
if ( ! V_11 )
return - V_280 ;
V_13 = F_53 ( V_31 , V_301 , V_11 ) ;
if ( V_13 )
goto V_281;
if ( F_51 ( & V_11 -> V_29 ) ) {
F_10 ( V_31 -> V_41 , V_42 , L_46 ) ;
for ( V_302 = 0 ; V_302 < V_177 ; V_302 ++ ) {
if ( V_31 -> V_303 [ V_302 ] . V_91 ==
V_301 -> V_150 -> V_92 )
break;
if ( ! V_31 -> V_303 [ V_302 ] . V_91 ) {
V_31 -> V_303 [ V_302 ] . V_91 =
V_301 -> V_150 -> V_92 ;
V_31 -> V_303 [ V_302 ] . V_80 =
V_301 -> V_150 -> V_65 ;
V_31 -> V_303 [ V_302 ] . V_148 =
V_304 ;
break;
}
}
}
V_281:
F_42 ( V_11 ) ;
return 0 ;
}
static int F_54 ( struct V_30 * V_31 ,
struct V_300 * V_301 )
{
struct V_10 * V_11 ;
int V_13 ;
unsigned long V_78 ;
V_11 = F_40 ( sizeof( struct V_10 ) , V_279 ) ;
if ( ! V_11 )
return - V_280 ;
V_13 = F_53 ( V_31 , V_301 , V_11 ) ;
if ( V_13 )
goto V_281;
V_13 = F_49 ( V_31 , V_11 ) ;
if ( V_13 )
goto V_281;
F_25 ( & V_31 -> V_305 , V_78 ) ;
memcpy ( & V_31 -> V_180 . V_181 , V_11 ,
sizeof( V_31 -> V_180 . V_181 ) ) ;
F_55 ( V_31 ) ;
F_29 ( & V_31 -> V_305 , V_78 ) ;
V_281:
F_42 ( V_11 -> V_214 ) ;
F_42 ( V_11 ) ;
return 0 ;
}
static int
F_56 ( struct V_30 * V_31 , T_1 * * V_306 ,
T_2 * V_209 , T_4 V_307 , T_1 * V_80 ,
bool V_128 , T_3 V_308 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_309 * V_310 ;
struct V_300 * V_301 ;
T_1 V_160 [ V_159 ] ;
T_3 V_311 ;
const T_1 * V_312 ;
T_5 V_313 ;
V_84 V_150 = 0 ;
V_84 V_314 = 0 ;
T_2 V_315 ;
T_2 V_316 ;
V_84 V_317 ;
V_84 V_318 ;
T_1 * V_202 ;
T_4 V_319 ;
struct V_320 * V_321 ;
struct V_322 * V_323 ;
if ( * V_209 >= sizeof( V_314 ) ) {
V_314 = F_22 ( * ( V_324 * ) ( * V_306 ) ) ;
* V_209 -= sizeof( V_314 ) ;
* V_306 += sizeof( V_314 ) ;
}
if ( ! V_314 || V_314 > * V_209 ) {
* V_306 += * V_209 ;
* V_209 = 0 ;
return - V_277 ;
}
V_202 = * V_306 ;
* V_306 += V_314 ;
* V_209 -= V_314 ;
V_315 = V_314 ;
if ( V_315 < V_159 + sizeof( T_1 ) +
sizeof( struct V_320 ) ) {
F_10 ( V_41 , ERROR ,
L_47 ) ;
return - V_277 ;
}
memcpy ( V_160 , V_202 , V_159 ) ;
V_202 += V_159 ;
V_315 -= V_159 ;
if ( ! V_128 ) {
V_311 = ( T_3 ) * V_202 ;
V_311 = ( - V_311 ) * 100 ;
V_202 += sizeof( T_1 ) ;
V_315 -= sizeof( T_1 ) ;
F_10 ( V_41 , V_42 ,
L_48 , V_311 ) ;
} else {
V_311 = V_308 ;
}
V_321 = (struct V_320 * ) V_202 ;
V_202 += sizeof( * V_321 ) ;
V_315 -= sizeof( * V_321 ) ;
V_319 = F_57 ( V_321 -> V_319 ) ;
V_317 = F_22 ( V_321 -> V_317 ) ;
V_318 = F_22 ( V_321 -> V_318 ) ;
F_10 ( V_41 , V_42 ,
L_49 ,
V_318 ) ;
V_312 = V_202 ;
V_313 = V_315 ;
F_10 ( V_41 , V_42 ,
L_50 ,
V_315 ) ;
while ( V_315 >= sizeof( struct V_216 ) ) {
T_1 V_16 , V_204 ;
V_16 = * V_202 ;
V_204 = * ( V_202 + 1 ) ;
if ( V_315 < V_204 +
sizeof( struct V_216 ) ) {
F_10 ( V_41 , ERROR ,
L_51 , V_8 ) ;
return - V_277 ;
}
if ( V_16 == V_222 ) {
V_150 = * ( V_202 +
sizeof( struct V_216 ) ) ;
break;
}
V_202 += V_204 + sizeof( struct V_216 ) ;
V_315 -= V_204 +
sizeof( struct V_216 ) ;
}
if ( V_150 ) {
struct V_68 * V_325 ;
T_1 V_65 ;
if ( V_150 == V_31 -> V_124 ) {
F_10 ( V_41 , V_272 ,
L_52 ) ;
return 0 ;
}
V_65 = V_268 ;
if ( V_80 )
V_65 = F_38 ( * V_80 &
( F_58 ( 0 ) | F_58 ( 1 ) ) ) ;
V_310 = F_50 ( V_31 , V_65 , V_150 , 0 ) ;
V_316 = V_310 ? V_310 -> V_316 : 0 ;
V_325 = F_59 ( V_31 -> V_73 . V_74 , V_316 ) ;
if ( V_325 && ! ( V_325 -> V_78 & V_79 ) ) {
V_301 = F_60 ( V_31 -> V_73 . V_74 ,
V_325 , V_326 ,
V_160 , V_319 ,
V_318 , V_317 ,
V_312 , V_313 , V_311 , V_279 ) ;
if ( V_301 ) {
V_323 = (struct V_322 * ) V_301 -> V_31 ;
V_323 -> V_65 = V_65 ;
V_323 -> V_307 = V_307 ;
if ( V_31 -> V_46 &&
! memcmp ( V_160 , V_31 -> V_180 .
V_181 . V_327 ,
V_159 ) )
F_54 ( V_31 ,
V_301 ) ;
F_61 ( V_31 -> V_73 . V_74 , V_301 ) ;
}
if ( ( V_325 -> V_78 & V_328 ) ||
( V_325 -> V_78 & V_85 ) ) {
F_10 ( V_41 , V_42 ,
L_53 ,
V_150 ) ;
F_52 ( V_31 , V_301 ) ;
}
}
} else {
F_10 ( V_41 , V_272 , L_54 ) ;
}
return 0 ;
}
static void F_62 ( struct V_30 * V_31 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
V_41 -> V_329 = 0 ;
if ( V_41 -> V_330 -> V_135 ) {
V_41 -> V_331 . V_332 = 0 ;
if ( ! V_31 -> V_106 ) {
F_10 ( V_41 , V_42 ,
L_55 ) ;
F_63 ( V_41 , V_41 -> V_330 ) ;
}
}
}
static int
F_64 ( struct V_30 * V_31 )
{
int V_13 ;
struct V_44 * V_41 = V_31 -> V_41 ;
T_1 V_333 = 0 ;
struct V_59 * V_334 ;
if ( V_41 -> V_335 || ! V_31 -> V_106 ) {
V_41 -> V_335 = false ;
return 0 ;
}
if ( ! V_31 -> V_303 [ 0 ] . V_91 ) {
F_10 ( V_41 , V_42 , L_56 ) ;
return 0 ;
}
V_334 = F_40 ( sizeof( * V_334 ) , V_279 ) ;
if ( ! V_334 )
return - V_280 ;
memset ( V_334 , 0 , sizeof( * V_334 ) ) ;
for ( V_333 = 0 ; V_333 < V_177 ; V_333 ++ ) {
if ( ! V_31 -> V_303 [ V_333 ] . V_91 )
break;
memcpy ( & V_334 -> V_81 [ V_333 ] ,
& V_31 -> V_303 [ V_333 ] ,
sizeof( struct V_336 ) ) ;
}
V_41 -> V_335 = true ;
V_334 -> V_161 = V_31 -> V_106 -> V_337 ;
V_334 -> V_162 = V_31 -> V_106 -> V_338 ;
V_13 = F_39 ( V_31 , V_334 ) ;
F_42 ( V_334 ) ;
memset ( & V_31 -> V_303 , 0 , sizeof( V_31 -> V_303 ) ) ;
if ( V_13 ) {
F_65 ( V_31 -> V_41 -> V_339 , L_57 , V_13 ) ;
return V_13 ;
}
return 0 ;
}
static void F_66 ( struct V_30 * V_31 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_116 * V_117 , * V_118 ;
unsigned long V_78 ;
F_25 ( & V_41 -> V_133 , V_78 ) ;
if ( F_43 ( & V_41 -> V_283 ) ) {
F_29 ( & V_41 -> V_133 , V_78 ) ;
F_25 ( & V_41 -> V_278 , V_78 ) ;
V_41 -> V_271 = false ;
F_29 ( & V_41 -> V_278 , V_78 ) ;
F_64 ( V_31 ) ;
if ( ! V_41 -> V_128 )
F_62 ( V_31 ) ;
if ( V_31 -> V_106 ) {
F_10 ( V_41 , V_42 ,
L_58 ) ;
F_67 ( V_31 -> V_106 , 0 ) ;
V_31 -> V_106 = NULL ;
} else {
V_31 -> V_340 = false ;
F_10 ( V_41 , V_42 ,
L_59 ) ;
}
} else if ( ( V_31 -> V_340 && ! V_31 -> V_106 ) ||
V_31 -> V_274 ) {
F_26 (cmd_node, tmp_node,
&adapter->scan_pending_q, list) {
F_27 ( & V_117 -> V_134 ) ;
F_28 ( V_41 , V_117 ) ;
}
F_29 ( & V_41 -> V_133 , V_78 ) ;
F_25 ( & V_41 -> V_278 , V_78 ) ;
V_41 -> V_271 = false ;
F_29 ( & V_41 -> V_278 , V_78 ) ;
if ( ! V_41 -> V_335 ) {
if ( V_31 -> V_106 ) {
F_10 ( V_41 , V_42 ,
L_60 ) ;
F_67 ( V_31 -> V_106 , 1 ) ;
V_31 -> V_106 = NULL ;
} else {
V_31 -> V_340 = false ;
F_10 ( V_41 , V_42 ,
L_59 ) ;
}
}
} else {
V_117 = F_44 ( & V_41 -> V_283 ,
struct V_116 , V_134 ) ;
F_27 ( & V_117 -> V_134 ) ;
F_29 ( & V_41 -> V_133 , V_78 ) ;
F_45 ( V_41 , V_117 , true ) ;
}
return;
}
int F_68 ( struct V_30 * V_31 ,
struct V_286 * V_341 )
{
int V_13 = 0 ;
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_342 * V_343 ;
struct V_182 * V_186 ;
struct V_344 * V_345 ;
T_1 * V_306 ;
T_2 V_346 ;
T_2 V_209 ;
T_2 V_299 ;
T_2 V_184 ;
struct V_347 * V_348 ;
struct V_349 * V_350 ;
T_1 V_351 ;
T_6 V_307 = 0 ;
T_1 * V_80 ;
V_351 = ( F_22 ( V_341 -> V_294 )
== V_352 ) ;
if ( V_351 )
V_343 = & V_341 -> V_291 . V_353 . V_354 ;
else
V_343 = & V_341 -> V_291 . V_354 ;
if ( V_343 -> V_355 > V_356 ) {
F_10 ( V_41 , ERROR ,
L_61 ,
V_343 -> V_355 ) ;
V_13 = - 1 ;
goto V_357;
}
F_21 ( V_31 ) ;
V_209 = F_22 ( V_343 -> V_358 ) ;
F_10 ( V_41 , V_42 ,
L_62 ,
V_209 ) ;
V_346 = F_22 ( V_341 -> V_295 ) ;
F_10 ( V_41 , V_42 ,
L_63 ,
V_343 -> V_355 ) ;
V_306 = V_343 -> V_359 ;
V_184 = V_346 - ( V_209
+ sizeof( V_343 -> V_358 )
+ sizeof( V_343 -> V_355 )
+ V_296 ) ;
V_186 = (struct V_182 * ) ( V_343 ->
V_359 +
V_209 ) ;
F_36 ( V_41 , V_186 , V_184 ,
V_191 ,
(struct V_182 * * )
& V_345 ) ;
F_36 ( V_41 , V_186 , V_184 ,
V_192 ,
(struct V_182 * * )
& V_348 ) ;
for ( V_299 = 0 ; V_299 < V_343 -> V_355 && V_209 ; V_299 ++ ) {
if ( V_345 )
memcpy ( & V_307 , & V_345 -> V_360 [ V_299 * V_361 ] ,
sizeof( V_307 ) ) ;
if ( V_348 ) {
V_350 = & V_348 -> V_362 [ V_299 ] ;
V_80 = & V_350 -> V_80 ;
} else {
V_80 = NULL ;
}
V_13 = F_56 ( V_31 , & V_306 ,
& V_209 ,
F_57 ( V_307 ) ,
V_80 , false , 0 ) ;
if ( V_13 )
goto V_357;
}
V_357:
F_66 ( V_31 ) ;
return V_13 ;
}
int F_69 ( struct V_30 * V_31 ,
struct V_286 * V_287 ,
void * V_363 )
{
struct V_364 * V_128 = & V_287 -> V_291 . V_128 ;
struct V_95 * V_288 = V_363 ;
memcpy ( V_128 -> V_293 , V_288 -> V_104 , V_288 -> V_105 ) ;
V_287 -> V_294 = F_16 ( V_129 ) ;
V_287 -> V_295 = F_16 ( ( V_84 ) ( sizeof( V_128 -> V_365 )
+ V_288 -> V_105 + V_296 ) ) ;
return 0 ;
}
static void
F_70 ( struct V_30 * V_31 ,
struct V_366 * V_367 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
T_1 V_71 , V_368 ;
struct V_369 * V_370 ;
struct V_371 V_372 ;
V_370 = ( void * ) ( ( T_1 * ) V_367 +
sizeof( struct V_132 ) ) ;
V_368 = F_22 ( V_367 -> V_108 . V_110 ) /
sizeof( struct V_371 ) ;
for ( V_71 = 0 ; V_71 < V_368 ; V_71 ++ ) {
V_372 . V_147 = V_370 -> V_147 ;
V_372 . V_373 = V_370 -> V_373 ;
V_372 . V_78 = V_370 -> V_78 ;
V_372 . V_374 = V_370 -> V_374 ;
V_372 . V_375 = F_22 ( V_370 -> V_375 ) ;
V_372 . V_376 =
F_22 ( V_370 -> V_376 ) ;
V_372 . V_377 =
F_22 ( V_370 -> V_377 ) ;
F_10 ( V_41 , V_42 ,
L_64 ,
V_372 . V_147 ,
V_372 . V_374 ,
V_372 . V_375 ,
V_372 . V_376 ,
V_372 . V_377 ) ;
memcpy ( & V_41 -> V_372 [ V_41 -> V_329 ++ ] , & V_372 ,
sizeof( struct V_371 ) ) ;
V_370 ++ ;
}
}
int F_71 ( struct V_30 * V_31 ,
struct V_286 * V_341 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
struct V_364 * V_378 ;
struct V_132 * V_183 ;
struct V_366 * V_367 ;
V_84 V_379 , type , V_110 ;
struct V_286 * V_380 ;
struct V_116 * V_117 ;
unsigned long V_381 , V_382 ;
bool V_383 = false ;
F_10 ( V_41 , V_42 , L_65 ) ;
V_378 = & V_341 -> V_291 . V_128 ;
V_183 = ( void * ) V_378 -> V_293 ;
V_379 = F_22 ( V_341 -> V_295 ) - ( sizeof( * V_378 ) + V_296
- 1 ) ;
while ( V_379 >= sizeof( struct V_132 ) ) {
type = F_22 ( V_183 -> type ) ;
V_110 = F_22 ( V_183 -> V_110 ) ;
if ( V_379 < ( sizeof( struct V_132 ) + V_110 ) ) {
F_10 ( V_41 , ERROR ,
L_66 ) ;
break;
}
switch ( type ) {
case V_384 :
V_367 = ( void * ) V_183 ;
F_70 ( V_31 , V_367 ) ;
break;
default:
break;
}
V_379 -= V_110 + sizeof( struct V_132 ) ;
V_183 = ( void * ) ( ( T_1 * ) V_183 + V_110 +
sizeof( struct V_132 ) ) ;
}
F_25 ( & V_41 -> V_385 , V_381 ) ;
F_25 ( & V_41 -> V_133 , V_382 ) ;
if ( F_43 ( & V_41 -> V_283 ) ) {
V_383 = true ;
F_72 (cmd_node, &adapter->cmd_pending_q, list) {
V_380 = ( void * ) V_117 -> V_386 -> V_18 ;
if ( F_22 ( V_380 -> V_294 ) ==
V_129 ) {
F_10 ( V_41 , V_42 ,
L_67 ) ;
V_383 = false ;
break;
}
}
}
F_29 ( & V_41 -> V_133 , V_382 ) ;
F_29 ( & V_41 -> V_385 , V_381 ) ;
if ( V_383 )
F_62 ( V_31 ) ;
return 0 ;
}
int F_73 ( struct V_30 * V_31 ,
void * V_387 )
{
int V_13 = 0 ;
struct V_44 * V_41 = V_31 -> V_41 ;
T_1 * V_306 ;
T_2 V_209 , V_388 , V_299 ;
V_84 type , V_110 ;
struct V_182 * V_183 ;
struct V_389 * V_390 ;
struct V_391 * V_392 ;
T_1 * V_80 ;
T_4 V_307 = 0 ;
T_3 V_311 = 0 ;
struct V_393 * V_394 = V_387 ;
T_1 V_395 = V_394 -> V_395 ;
T_1 * V_354 = V_387 + sizeof( struct V_393 ) ;
V_84 V_346 = F_22 ( V_394 -> V_396 ) ;
if ( V_395 > V_356 ) {
F_10 ( V_41 , ERROR ,
L_68 ,
V_395 ) ;
V_13 = - 1 ;
goto V_357;
}
V_209 = V_346 ;
F_10 ( V_41 , V_42 ,
L_69 ,
V_346 , V_395 ) ;
F_74 ( V_41 , V_397 , L_70 , V_387 ,
V_346 +
sizeof( struct V_393 ) ) ;
V_183 = (struct V_182 * ) V_354 ;
for ( V_299 = 0 ; V_299 < V_395 && V_209 ; V_299 ++ ) {
type = F_22 ( V_183 -> V_108 . type ) ;
V_110 = F_22 ( V_183 -> V_108 . V_110 ) ;
if ( V_209 < sizeof( struct V_132 ) + V_110 ) {
F_10 ( V_41 , ERROR ,
L_71 ) ;
break;
}
V_390 = NULL ;
V_392 = NULL ;
V_388 = V_209 ;
if ( type != V_398 )
break;
V_306 = ( T_1 * ) V_183 ;
V_390 = (struct V_389 * ) V_183 ;
V_183 = (struct V_182 * ) ( V_183 -> V_18 + V_110 ) ;
V_388 -=
( V_110 + sizeof( struct V_132 ) ) ;
while ( V_388 >=
sizeof( struct V_132 ) &&
F_22 ( V_183 -> V_108 . type ) != V_398 ) {
type = F_22 ( V_183 -> V_108 . type ) ;
V_110 = F_22 ( V_183 -> V_108 . V_110 ) ;
if ( V_388 <
sizeof( struct V_132 ) + V_110 ) {
F_10 ( V_41 , ERROR ,
L_72
L_73 ) ;
V_390 = NULL ;
V_388 = 0 ;
continue;
}
switch ( type ) {
case V_399 :
V_392 =
(struct V_391 * ) V_183 ;
if ( V_110 !=
sizeof( struct V_391 ) -
sizeof( struct V_132 ) ) {
V_388 = 0 ;
continue;
}
break;
default:
break;
}
V_183 = (struct V_182 * ) ( V_183 -> V_18 + V_110 ) ;
V_209 -=
( V_110 + sizeof( struct V_132 ) ) ;
V_388 -=
( V_110 + sizeof( struct V_132 ) ) ;
}
if ( ! V_390 )
break;
V_306 += sizeof( V_84 ) ;
V_209 -= sizeof( V_84 ) ;
if ( V_392 ) {
V_311 = ( T_3 ) ( V_400 ) ( F_22 ( V_392 -> V_311 ) ) ;
V_311 *= 100 ;
F_10 ( V_41 , V_42 ,
L_48 , V_311 ) ;
V_307 = F_57 ( V_392 -> V_401 ) ;
V_80 = & V_392 -> V_80 ;
} else {
V_80 = NULL ;
}
V_13 = F_56 ( V_31 , & V_306 ,
& V_209 , V_307 ,
V_80 , true , V_311 ) ;
if ( V_13 )
goto V_357;
}
V_357:
if ( ! V_394 -> V_402 )
F_66 ( V_31 ) ;
return V_13 ;
}
int F_75 ( struct V_286 * V_287 )
{
struct V_403 * V_404 =
& V_287 -> V_291 . V_405 ;
V_287 -> V_294 = F_16 ( V_352 ) ;
V_287 -> V_295 = F_16 ( sizeof( struct V_403 )
+ V_296 ) ;
V_404 -> V_406 = 1 ;
return 0 ;
}
void
F_76 ( struct V_30 * V_31 ,
struct V_116 * V_117 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
unsigned long V_78 ;
V_117 -> V_135 = true ;
V_117 -> V_407 = & V_41 -> V_408 ;
F_25 ( & V_41 -> V_133 , V_78 ) ;
F_77 ( & V_117 -> V_134 , & V_41 -> V_283 ) ;
F_29 ( & V_41 -> V_133 , V_78 ) ;
}
static int F_78 ( struct V_30 * V_31 ,
struct V_25 * V_409 )
{
struct V_44 * V_41 = V_31 -> V_41 ;
int V_13 ;
struct V_59 * V_288 ;
if ( V_41 -> V_271 ) {
F_10 ( V_41 , V_272 ,
L_41 ) ;
return - V_273 ;
}
if ( V_31 -> V_274 ) {
F_10 ( V_41 , V_272 ,
L_42 ) ;
return - V_273 ;
}
V_288 = F_40 ( sizeof( struct V_59 ) , V_279 ) ;
if ( ! V_288 )
return - V_280 ;
V_288 -> V_162 = V_409 ;
V_288 -> V_161 = 1 ;
V_13 = F_39 ( V_31 , V_288 ) ;
F_42 ( V_288 ) ;
return V_13 ;
}
int F_79 ( struct V_30 * V_31 ,
struct V_25 * V_409 )
{
int V_13 ;
if ( F_80 ( & V_31 -> V_410 ) ) {
F_10 ( V_31 -> V_41 , ERROR ,
L_74 ,
V_8 ) ;
return - 1 ;
}
V_31 -> V_41 -> V_408 = false ;
if ( V_409 && V_409 -> V_28 != 0 )
V_13 = F_78 ( V_31 , V_409 ) ;
else
V_13 = F_39 ( V_31 , NULL ) ;
F_81 ( & V_31 -> V_410 ) ;
return V_13 ;
}
int
F_35 ( struct V_30 * V_31 ,
V_84 V_411 , T_1 * * V_412 )
{
int V_333 , V_413 = 0 ;
struct V_414 * V_415 ;
if ( ! V_412 )
return 0 ;
if ( ! ( * V_412 ) )
return 0 ;
for ( V_333 = 0 ; V_333 < V_416 ; V_333 ++ ) {
if ( V_31 -> V_417 [ V_333 ] . V_418 & V_411 ) {
V_415 =
(struct V_414 * )
* V_412 ;
V_415 -> V_108 . type =
F_16 ( V_419 ) ;
V_415 -> V_108 . V_110 =
F_16 ( ( ( ( V_84 ) V_31 -> V_417 [ V_333 ] . V_420 [ 1 ] )
& 0x00FF ) + 2 ) ;
memcpy ( V_415 -> V_420 , V_31 -> V_417 [ V_333 ] . V_420 ,
F_22 ( V_415 -> V_108 . V_110 ) ) ;
* V_412 += F_22 ( V_415 -> V_108 . V_110 ) +
sizeof( struct V_132 ) ;
V_413 += F_22 ( V_415 -> V_108 . V_110 ) +
sizeof( struct V_132 ) ;
}
}
return V_413 ;
}
void
F_55 ( struct V_30 * V_31 )
{
struct V_10 * V_421 =
& V_31 -> V_180 . V_181 ;
if ( ! V_421 -> V_215 )
return;
if ( ! V_31 -> V_422 ||
V_31 -> V_423 != V_421 -> V_215 ) {
V_31 -> V_423 = V_421 -> V_215 ;
F_42 ( V_31 -> V_422 ) ;
V_31 -> V_422 = F_82 ( V_421 -> V_215 ,
V_424 ) ;
if ( ! V_31 -> V_422 )
return;
}
memcpy ( V_31 -> V_422 , V_421 -> V_214 ,
V_421 -> V_215 ) ;
F_10 ( V_31 -> V_41 , V_42 ,
L_75 ,
V_31 -> V_423 ) ;
V_421 -> V_214 = V_31 -> V_422 ;
if ( V_421 -> V_21 )
V_421 -> V_21 =
(struct V_210 * )
( V_421 -> V_214 +
V_421 -> V_237 ) ;
if ( V_421 -> V_14 )
V_421 -> V_14 = (struct V_241 * )
( V_421 -> V_214 +
V_421 -> V_242 ) ;
if ( V_421 -> V_56 )
V_421 -> V_56 = (struct V_175 * )
( V_421 -> V_214 +
V_421 -> V_244 ) ;
if ( V_421 -> V_246 )
V_421 -> V_246 = (struct V_247 * )
( V_421 -> V_214 +
V_421 -> V_248 ) ;
if ( V_421 -> V_251 )
V_421 -> V_251 = ( void * ) ( V_421 -> V_214 +
V_421 -> V_252 ) ;
if ( V_421 -> V_254 )
V_421 -> V_254 = ( void * ) ( V_421 -> V_214 +
V_421 -> V_255 ) ;
if ( V_421 -> V_257 )
V_421 -> V_257 =
( V_421 -> V_214 + V_421 -> V_258 ) ;
if ( V_421 -> V_260 )
V_421 -> V_260 = V_421 -> V_214 +
V_421 -> V_261 ;
if ( V_421 -> V_263 )
V_421 -> V_263 = ( void * ) ( V_421 -> V_214 +
V_421 -> V_264 ) ;
}
void
F_83 ( struct V_30 * V_31 )
{
F_42 ( V_31 -> V_422 ) ;
V_31 -> V_422 = NULL ;
}
