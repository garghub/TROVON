static void
F_1 ( int V_1 , const char * V_2 , const char * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
F_2 ( V_5 -> V_8 , V_1 ,
L_1 ,
V_2 , V_3 ,
V_7 -> V_9 ?
V_7 -> V_9 -> V_10 . V_11 : 0 ,
V_7 -> V_12 ?
V_7 -> V_12 -> V_13 . V_11 : 0 ,
V_5 -> V_14 . V_15 ? L_2 : L_3 ,
V_5 -> V_14 . V_16 ? L_2 : L_3 ,
V_5 -> V_14 . V_17 ? L_2 : L_3 ,
V_5 -> V_14 . V_18 ,
V_7 -> V_19 ) ;
}
static bool
F_3 ( struct V_20 * V_21 , T_1 V_22 )
{
return ( V_21 && V_21 -> V_13 . V_11 == V_22 ) ;
}
static bool
F_4 ( struct V_23 * V_21 , T_1 V_22 )
{
return ( V_21 && V_21 -> V_10 . V_11 == V_22 ) ;
}
static T_1
F_5 ( struct V_24 * V_25 , T_1 * V_26 )
{
T_1 V_27 ;
V_27 = V_25 -> V_28 [ 0 ] ;
while ( V_27 ) {
if ( ! memcmp ( V_25 -> V_29 , V_26 , sizeof( V_25 -> V_29 ) ) )
return V_30 ;
-- V_27 ;
if ( V_27 )
V_25 = (struct V_24 * ) ( ( T_1 * ) V_25 +
sizeof( V_25 -> V_29 ) ) ;
}
F_6 ( L_4 , V_31 ) ;
return V_32 ;
}
static T_1
F_7 ( struct V_6 * V_7 , T_2 V_33 )
{
T_1 * V_26 ;
struct V_24 * V_25 ;
T_1 V_34 = V_32 ;
if ( F_3 ( V_7 -> V_12 , V_35 ) ) {
V_25 = (struct V_24 * )
( ( ( T_1 * ) V_7 -> V_12 -> V_36 ) +
V_37 ) ;
V_26 = & V_38 [ V_33 ] [ 0 ] ;
V_34 = F_5 ( V_25 , V_26 ) ;
if ( V_34 )
return V_34 ;
}
return V_34 ;
}
static T_1
F_8 ( struct V_6 * V_7 , T_2 V_33 )
{
T_1 * V_26 ;
struct V_24 * V_25 ;
T_1 V_34 = V_32 ;
if ( F_4 ( V_7 -> V_9 , V_39 ) ) {
V_25 = (struct V_24 * ) V_7 -> V_9 -> V_36 ;
V_26 = & V_40 [ V_33 ] [ 0 ] ;
V_34 = F_5 ( V_25 , V_26 ) ;
if ( V_34 )
return V_34 ;
}
return V_34 ;
}
T_3
F_9 ( struct V_41 * V_42 , struct V_41 * V_43 )
{
if ( ! V_42 || ! V_43 || ( V_42 -> V_44 != V_43 -> V_44 ) )
return - 1 ;
return memcmp ( V_42 -> V_45 , V_43 -> V_45 , V_42 -> V_44 ) ;
}
static bool
F_10 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( V_5 -> V_14 . V_46 &&
F_3 ( V_7 -> V_47 , V_48 ) )
return true ;
return false ;
}
static bool
F_11 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( ! V_5 -> V_14 . V_15 && ! V_5 -> V_14 . V_16 &&
! V_5 -> V_14 . V_17 &&
! F_4 ( V_7 -> V_9 , V_39 ) &&
! F_3 ( V_7 -> V_12 , V_35 ) &&
! V_5 -> V_14 . V_18 && ! V_7 -> V_19 ) {
return true ;
}
return false ;
}
static bool
F_12 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( V_5 -> V_14 . V_15 && ! V_5 -> V_14 . V_16 &&
! V_5 -> V_14 . V_17 && V_7 -> V_19 ) {
return true ;
}
return false ;
}
static bool
F_13 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( ! V_5 -> V_14 . V_15 && V_5 -> V_14 . V_16 &&
! V_5 -> V_14 . V_17 &&
F_4 ( V_7 -> V_9 , V_39 )
) {
F_14 ( V_49 , L_5 , V_5 , V_7 ) ;
return true ;
}
return false ;
}
static bool
F_15 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( ! V_5 -> V_14 . V_15 && ! V_5 -> V_14 . V_16 &&
V_5 -> V_14 . V_17 &&
F_3 ( V_7 -> V_12 , V_35 ) ) {
F_14 ( V_49 , L_6 , V_5 , V_7 ) ;
return true ;
}
return false ;
}
static bool
F_16 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( ! V_5 -> V_14 . V_15 && ! V_5 -> V_14 . V_16 &&
! V_5 -> V_14 . V_17 &&
! F_4 ( V_7 -> V_9 , V_39 ) &&
! F_3 ( V_7 -> V_12 , V_35 ) &&
! V_5 -> V_14 . V_18 && V_7 -> V_19 ) {
return true ;
}
return false ;
}
static bool
F_17 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( ! V_5 -> V_14 . V_15 && ! V_5 -> V_14 . V_16 &&
! V_5 -> V_14 . V_17 &&
! F_4 ( V_7 -> V_9 , V_39 ) &&
! F_3 ( V_7 -> V_12 , V_35 ) &&
V_5 -> V_14 . V_18 && V_7 -> V_19 ) {
F_14 ( V_49 , L_7 , V_5 , V_7 ) ;
return true ;
}
return false ;
}
static T_3
F_18 ( struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_50 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
V_7 -> V_52 = false ;
if ( V_5 -> V_53 &&
( V_5 -> V_54 == V_55 ) &&
( V_7 -> V_54 == V_55 ) )
return 0 ;
if ( V_5 -> V_56 . V_57 ) {
F_19 ( V_8 , V_58 ,
L_8 ) ;
return 0 ;
}
if ( V_7 -> V_59 ) {
F_19 ( V_8 , V_49 ,
L_9 ) ;
return - 1 ;
}
if ( F_10 ( V_5 , V_7 ) ) {
F_19 ( V_8 , V_49 ,
L_10 ) ;
return 0 ;
}
if ( V_7 -> V_54 == V_50 ) {
if ( F_11 ( V_5 , V_7 ) ) {
return 0 ;
} else if ( F_12 ( V_5 , V_7 ) ) {
F_19 ( V_8 , V_49 ,
L_11 ) ;
V_7 -> V_52 = true ;
return 0 ;
} else if ( F_13 ( V_5 , V_7 ) ) {
if ( ( ( V_5 -> V_8 -> V_60 & V_61 ||
V_5 -> V_8 -> V_60 & V_62 ) &&
V_7 -> V_63 ) &&
! F_8 ( V_7 ,
V_64 ) ) {
if ( F_8
( V_7 , V_65 ) ) {
F_19 ( V_8 , V_49 ,
L_12
L_13 ) ;
V_7 -> V_52 = true ;
} else {
return - 1 ;
}
}
return 0 ;
} else if ( F_15 ( V_5 , V_7 ) ) {
if ( ( ( V_5 -> V_8 -> V_60 & V_61 ||
V_5 -> V_8 -> V_60 & V_62 ) &&
V_7 -> V_63 ) &&
! F_7 ( V_7 ,
V_64 ) ) {
if ( F_7
( V_7 , V_65 ) ) {
F_19 ( V_8 , V_49 ,
L_12
L_13 ) ;
V_7 -> V_52 = true ;
} else {
return - 1 ;
}
}
return 0 ;
} else if ( F_16 ( V_5 , V_7 ) ) {
return 0 ;
} else if ( F_17 ( V_5 , V_7 ) ) {
return 0 ;
}
F_14 ( ERROR , L_14 , V_5 , V_7 ) ;
return - 1 ;
}
return - 1 ;
}
static int
F_20 ( struct V_4 * V_5 ,
const struct V_66
* V_67 ,
struct V_68
* V_69 ,
T_1 V_70 )
{
enum V_71 V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_51 * V_8 = V_5 -> V_8 ;
int V_77 = 0 , V_78 ;
for ( V_72 = 0 ; ( V_72 < V_79 ) ; V_72 ++ ) {
if ( ! V_5 -> V_80 . V_81 -> V_82 [ V_72 ] )
continue;
V_74 = V_5 -> V_80 . V_81 -> V_82 [ V_72 ] ;
for ( V_78 = 0 ; ( V_78 < V_74 -> V_83 ) ; V_78 ++ ) {
V_76 = & V_74 -> V_84 [ V_78 ] ;
if ( V_76 -> V_85 & V_86 )
continue;
V_69 [ V_77 ] . V_87 = V_72 ;
if ( V_67 &&
V_67 -> V_88 [ 0 ] . V_89 )
V_69 [ V_77 ] . V_90 =
F_21 ( ( V_91 ) V_67 ->
V_88 [ 0 ] . V_89 ) ;
else if ( V_76 -> V_85 & V_92 )
V_69 [ V_77 ] . V_90 =
F_21 ( V_8 -> V_93 ) ;
else
V_69 [ V_77 ] . V_90 =
F_21 ( V_8 -> V_94 ) ;
if ( V_76 -> V_85 & V_92 )
V_69 [ V_77 ] . V_95
|= ( V_96 |
V_97 ) ;
else
V_69 [ V_77 ] . V_95
&= ~ V_96 ;
V_69 [ V_77 ] . V_98 =
( T_2 ) V_76 -> V_99 ;
V_69 [ V_77 ] . V_95
|= V_100 ;
if ( V_70 ) {
V_69 [ V_77 ] . V_90 =
F_21 ( V_8 -> V_101 ) ;
}
V_77 ++ ;
}
}
return V_77 ;
}
static int
F_22 ( struct V_4 * V_5 ,
const struct V_102
* V_103 ,
struct V_68
* V_69 )
{
enum V_71 V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_51 * V_8 = V_5 -> V_8 ;
int V_77 = 0 , V_78 ;
for ( V_72 = 0 ; ( V_72 < V_79 ) ; V_72 ++ ) {
if ( ! V_5 -> V_80 . V_81 -> V_82 [ V_72 ] )
continue;
V_74 = V_5 -> V_80 . V_81 -> V_82 [ V_72 ] ;
for ( V_78 = 0 ; ( V_78 < V_74 -> V_83 ) ; V_78 ++ ) {
V_76 = & V_74 -> V_84 [ V_78 ] ;
if ( V_76 -> V_85 & V_86 )
continue;
V_69 [ V_77 ] . V_87 = V_72 ;
if ( V_103 -> V_88 [ 0 ] . V_89 )
V_69 [ V_77 ] . V_90 =
F_21 ( ( V_91 ) V_103 ->
V_88 [ 0 ] . V_89 ) ;
else if ( V_76 -> V_85 & V_92 )
V_69 [ V_77 ] . V_90 =
F_21 ( V_8 -> V_93 ) ;
else
V_69 [ V_77 ] . V_90 =
F_21 ( V_8 ->
V_101 ) ;
if ( V_76 -> V_85 & V_92 )
V_69 [ V_77 ] . V_95
|= V_96 ;
else
V_69 [ V_77 ] . V_95
&= ~ V_96 ;
V_69 [ V_77 ] . V_98 =
( T_2 ) V_76 -> V_99 ;
V_77 ++ ;
}
}
return V_77 ;
}
static int
F_23 ( struct V_4 * V_5 ,
struct V_104 * V_105 ,
T_1 V_106 )
{
struct V_107 * V_108 ;
T_1 V_109 [ V_110 ] , * V_111 ;
T_2 V_112 ;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
V_111 = ( T_1 * ) V_105 -> V_113 + V_105 -> V_114 ;
if ( V_5 -> V_115 )
V_112 = F_24 ( V_5 , V_109 ,
V_106 ) ;
else
V_112 = F_25 ( V_5 , V_109 ) ;
F_19 ( V_5 -> V_8 , V_116 ,
L_15 ,
V_112 ) ;
V_108 = (struct V_107 * ) V_111 ;
V_108 -> V_117 . type = F_21 ( V_118 ) ;
V_108 -> V_117 . V_119 = F_21 ( ( V_91 ) V_112 ) ;
memcpy ( V_108 -> V_109 , V_109 , V_112 ) ;
V_105 -> V_114 += sizeof( V_108 -> V_117 ) + V_112 ;
return V_112 ;
}
static int
F_26 ( struct V_4 * V_5 ,
T_2 V_120 , T_1 V_70 ,
struct V_104 * V_105 ,
struct V_121
* V_122 ,
struct V_68 * V_69 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
int V_34 = 0 ;
struct V_68 * V_123 ;
struct V_68 * V_124 ;
T_2 V_125 , V_112 , V_126 ;
T_2 V_127 ;
T_2 V_128 ;
T_1 V_87 ;
if ( ! V_105 || ! V_122 || ! V_69 ) {
F_19 ( V_5 -> V_8 , ERROR ,
L_16 ,
V_105 , V_122 , V_69 ) ;
return - 1 ;
}
F_27 ( V_5 ) ;
V_122 -> V_117 . type = F_21 ( V_129 ) ;
V_123 = V_69 ;
while ( V_123 -> V_98 ) {
V_125 = 0 ;
V_127 = 0 ;
V_87 = 0 ;
V_122 -> V_117 . V_119 = 0 ;
V_124 = V_123 ;
V_128 = false ;
while ( V_125 < V_120 &&
V_123 -> V_98 && ! V_128 ) {
if ( V_123 -> V_98 == V_5 -> V_130 ) {
V_123 ++ ;
continue;
}
V_87 = V_123 -> V_87 ;
F_19 ( V_5 -> V_8 , V_49 ,
L_17
L_18 ,
V_123 -> V_98 ,
V_123 -> V_87 ,
V_123 -> V_95
& V_96 ,
( V_123 -> V_95
& V_100 ) >> 1 ,
F_28 ( V_123 -> V_90 ) ) ;
memcpy ( V_122 -> V_131 + V_125 ,
V_123 ,
sizeof( V_122 -> V_131 ) ) ;
F_29 ( & V_122 -> V_117 . V_119 ,
sizeof( V_122 -> V_131 ) ) ;
V_105 -> V_114 = ( T_2 ) ( ( T_1 * ) V_122 -
V_105 -> V_113 ) ;
V_105 -> V_114 +=
( sizeof( V_122 -> V_117 )
+ F_28 ( V_122 -> V_117 . V_119 ) ) ;
V_125 ++ ;
V_127 +=
F_28 ( V_123 -> V_90 ) ;
V_128 = false ;
if ( ! V_70 &&
( V_123 -> V_98 == 1 ||
V_123 -> V_98 == 6 ||
V_123 -> V_98 == 11 ) )
V_128 = true ;
V_123 ++ ;
if ( ! V_70 &&
( V_123 -> V_98 == 1 ||
V_123 -> V_98 == 6 ||
V_123 -> V_98 == 11 ) )
V_128 = true ;
}
if ( V_127 > V_132 ) {
F_19 ( V_5 -> V_8 , ERROR ,
L_19
L_20 ,
V_127 ,
V_132 ) ;
V_34 = - 1 ;
break;
}
V_112 = F_23 ( V_5 , V_105 ,
V_87 ) ;
V_5 -> V_8 -> V_133 = V_124 ;
if ( V_5 -> V_8 -> V_134 )
V_126 = V_135 ;
else
V_126 = V_136 ;
V_34 = F_30 ( V_5 , V_126 , V_137 ,
0 , V_105 , false ) ;
V_105 -> V_114 -=
sizeof( struct V_138 ) + V_112 ;
if ( V_34 ) {
F_31 ( V_8 ) ;
break;
}
}
if ( V_34 )
return - 1 ;
return 0 ;
}
static void
F_32 ( struct V_4 * V_5 ,
const struct V_66 * V_67 ,
struct V_104 * V_105 ,
struct V_121 * * V_139 ,
struct V_68 * V_69 ,
T_1 * V_120 , T_1 * V_70 ,
T_1 * V_140 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
T_1 * V_111 ;
T_2 V_149 ;
T_2 V_44 ;
T_2 V_77 ;
T_2 V_150 ;
T_2 V_151 ;
V_91 V_152 ;
T_1 V_153 ;
T_1 V_87 ;
int V_78 ;
T_1 V_154 ;
struct V_155 * V_156 ;
struct V_157 * V_54 ;
V_105 -> V_114 = 0 ;
V_111 = V_105 -> V_113 ;
* V_70 = false ;
* V_140 = false ;
if ( V_67 ) {
V_154 = true ;
V_105 -> V_54 =
( T_1 ) ( V_67 -> V_54 ? : V_8 -> V_158 ) ;
V_149 = V_67 -> V_149 ? : V_8 -> V_159 ;
memcpy ( V_105 -> V_160 ,
V_67 -> V_160 ,
sizeof( V_105 -> V_160 ) ) ;
if ( V_8 -> V_134 &&
! F_33 ( V_105 -> V_160 ) ) {
V_148 =
(struct V_147 * ) V_111 ;
V_148 -> V_117 . type = F_21 ( V_161 ) ;
V_148 -> V_117 . V_119 = F_21 ( V_162 ) ;
memcpy ( V_148 -> V_163 , V_67 -> V_160 ,
V_162 ) ;
V_111 += sizeof( struct V_147 ) ;
}
for ( V_78 = 0 ; V_78 < V_67 -> V_164 ; V_78 ++ ) {
V_44 = V_67 -> V_165 [ V_78 ] . V_44 ;
V_146 =
(struct V_145 * )
V_111 ;
V_146 -> V_117 . type =
F_21 ( V_166 ) ;
V_146 -> V_117 . V_119 = F_21 (
( V_91 ) ( V_44 + sizeof( V_146 ->
V_167 ) ) ) ;
if ( V_44 )
V_146 -> V_167 = 0 ;
else
V_146 -> V_167 =
V_168 ;
if ( ! memcmp ( V_67 -> V_165 [ V_78 ] . V_45 ,
L_21 , 7 ) )
V_146 -> V_167 = 0xfe ;
memcpy ( V_146 -> V_45 ,
V_67 -> V_165 [ V_78 ] . V_45 , V_44 ) ;
V_111 += ( sizeof( V_146 -> V_117 )
+ F_28 ( V_146 -> V_117 . V_119 ) ) ;
F_19 ( V_8 , V_49 ,
L_22 ,
V_78 , V_146 -> V_45 ,
V_146 -> V_167 ) ;
if ( ! V_44 && V_146 -> V_167 )
V_154 = false ;
}
if ( ( V_78 && V_154 ) ||
! F_33 ( V_105 -> V_160 ) )
* V_70 = true ;
if ( V_67 -> V_169 ) {
F_19 ( V_8 , V_49 ,
L_23 ,
V_67 -> V_169 ) ;
* V_120 =
V_170 ;
V_144 = ( void * ) V_111 ;
V_144 -> V_117 . type =
F_21 ( V_171 ) ;
V_144 -> V_117 . V_119 =
F_21 ( sizeof( V_144 -> V_172 ) ) ;
V_144 -> V_172 =
F_21 ( ( V_67 -> V_169 ) ) ;
V_111 +=
sizeof( struct V_143 ) ;
}
} else {
V_105 -> V_54 = ( T_1 ) V_8 -> V_158 ;
V_149 = V_8 -> V_159 ;
}
if ( * V_70 )
* V_120 = V_170 ;
else
* V_120 = V_173 ;
if ( V_8 -> V_134 ) {
V_54 = (struct V_157 * ) V_111 ;
V_54 -> V_117 . type = F_21 ( V_174 ) ;
V_54 -> V_117 . V_119 = F_21 ( sizeof( V_54 -> V_54 ) ) ;
V_54 -> V_54 = V_105 -> V_54 ;
V_111 += sizeof( V_54 -> V_117 ) +
F_28 ( V_54 -> V_117 . V_119 ) ;
}
if ( V_149 ) {
F_19 ( V_8 , V_49 ,
L_24 ,
V_149 ) ;
V_142 = (struct V_141 * ) V_111 ;
V_142 -> V_117 . type = F_21 ( V_175 ) ;
V_142 -> V_117 . V_119 =
F_21 ( sizeof( V_142 -> V_149 ) ) ;
V_142 -> V_149 = F_21 ( ( V_91 ) V_149 ) ;
V_111 += sizeof( V_142 -> V_117 ) +
F_28 ( V_142 -> V_117 . V_119 ) ;
}
if ( F_34 ( V_5 -> V_8 -> V_176 ) &&
( V_5 -> V_8 -> V_60 & V_61 ||
V_5 -> V_8 -> V_60 & V_62 ) ) {
V_156 = (struct V_155 * ) V_111 ;
memset ( V_156 , 0 , sizeof( struct V_155 ) ) ;
V_156 -> V_117 . type = F_21 ( V_177 ) ;
V_156 -> V_117 . V_119 =
F_21 ( sizeof( struct V_178 ) ) ;
V_87 =
F_35 ( V_5 -> V_8 -> V_60 ) ;
F_36 ( V_5 , V_87 , & V_156 -> V_156 ) ;
V_111 += sizeof( struct V_155 ) ;
}
F_37 ( V_5 , V_179 , & V_111 ) ;
* V_139 =
(struct V_121 * ) V_111 ;
if ( V_67 && V_67 -> V_88 [ 0 ] . V_98 ) {
F_19 ( V_8 , V_49 ,
L_25 ) ;
for ( V_77 = 0 ;
V_77 < V_180 &&
V_67 -> V_88 [ V_77 ] . V_98 ;
V_77 ++ ) {
V_153 = V_67 -> V_88 [ V_77 ] . V_98 ;
V_69 [ V_77 ] . V_98 = V_153 ;
V_87 =
V_67 -> V_88 [ V_77 ] . V_87 ;
V_69 [ V_77 ] . V_87 = V_87 ;
V_151 = V_67 -> V_88 [ V_77 ] . V_151 ;
if ( V_151 == V_181 )
V_69 [ V_77 ] . V_95
|= ( V_96 |
V_97 ) ;
else
V_69 [ V_77 ] . V_95
&= ~ V_96 ;
V_69 [ V_77 ] . V_95
|= V_100 ;
if ( V_67 -> V_88 [ V_77 ] . V_89 ) {
V_152 = ( V_91 ) V_67 ->
V_88 [ V_77 ] . V_89 ;
} else {
if ( V_151 == V_181 )
V_152 = V_8 -> V_93 ;
else if ( * V_70 )
V_152 = V_8 -> V_101 ;
else
V_152 = V_8 -> V_94 ;
}
V_69 [ V_77 ] . V_182 =
F_21 ( V_152 ) ;
V_69 [ V_77 ] . V_90 =
F_21 ( V_152 ) ;
}
if ( ( V_77 == 1 ) &&
( V_67 -> V_88 [ 0 ] . V_98 ==
V_5 -> V_183 . V_184 . V_153 ) ) {
* V_140 = true ;
F_19 ( V_8 , V_49 ,
L_26 ) ;
}
V_150 = V_77 ;
} else {
F_19 ( V_8 , V_49 ,
L_27 ) ;
V_150 = F_20 ( V_5 , V_67 ,
V_69 ,
* V_70 ) ;
}
}
static void
F_38 ( struct V_51 * V_8 ,
struct V_185 * V_186 ,
T_2 V_187 , T_2 V_188 ,
struct V_185 * * V_189 )
{
struct V_185 * V_190 ;
T_2 V_191 ;
T_2 V_192 ;
T_2 V_193 ;
V_190 = V_186 ;
V_191 = V_187 ;
* V_189 = NULL ;
F_19 ( V_8 , V_49 ,
L_28 ,
V_187 ) ;
while ( V_191 >= sizeof( struct V_138 ) ) {
V_192 = F_28 ( V_190 -> V_117 . type ) ;
V_193 = F_28 ( V_190 -> V_117 . V_119 ) ;
if ( sizeof( V_186 -> V_117 ) + V_193 > V_191 ) {
F_19 ( V_8 , ERROR ,
L_29 ) ;
break;
}
if ( V_188 == V_192 ) {
switch ( V_192 ) {
case V_194 :
F_19 ( V_8 , V_49 ,
L_30
L_31 ,
V_193 ) ;
* V_189 = V_190 ;
break;
case V_195 :
F_19 ( V_8 , V_49 ,
L_32
L_33 ,
V_193 ) ;
* V_189 = V_190 ;
break;
default:
F_19 ( V_8 , ERROR ,
L_34 ,
V_192 ) ;
return;
}
}
if ( * V_189 )
break;
V_191 -= ( sizeof( V_186 -> V_117 ) + V_193 ) ;
V_190 =
(struct V_185 * ) ( V_190 -> V_36 +
V_193 ) ;
}
}
int F_39 ( struct V_51 * V_8 ,
struct V_6 * V_196 )
{
int V_34 = 0 ;
T_1 V_11 ;
struct V_197 * V_198 ;
struct V_199 * V_200 ;
struct V_201 * V_202 ;
struct V_203 * V_204 ;
T_1 * V_205 ;
T_1 * V_206 ;
T_1 V_207 ;
V_91 V_208 ;
T_1 V_209 ;
T_1 V_210 ;
T_1 V_211 ;
T_2 V_212 ;
struct V_23 * V_213 ;
const T_1 V_214 [ 4 ] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_1 V_215 [ 4 ] = { 0x00 , 0x50 , 0xf2 , 0x02 } ;
V_211 = false ;
V_210 = 0 ;
V_205 = V_196 -> V_216 ;
V_212 = V_196 -> V_217 ;
while ( V_212 >= 2 ) {
V_11 = * V_205 ;
V_207 = * ( V_205 + 1 ) ;
V_208 = V_207 + sizeof( struct V_218 ) ;
if ( V_212 < V_208 ) {
F_19 ( V_8 , ERROR ,
L_35
L_36 ) ;
return - 1 ;
}
switch ( V_11 ) {
case V_219 :
V_196 -> V_45 . V_44 = V_207 ;
memcpy ( V_196 -> V_45 . V_45 , ( V_205 + 2 ) ,
V_207 ) ;
F_19 ( V_8 , V_49 ,
L_37 ,
V_196 -> V_45 . V_45 ) ;
break;
case V_118 :
memcpy ( V_196 -> V_220 , V_205 + 2 ,
V_207 ) ;
memcpy ( V_196 -> V_221 , V_205 + 2 ,
V_207 ) ;
V_210 = V_207 ;
V_211 = true ;
break;
case V_222 :
V_198 =
(struct V_197 * ) V_205 ;
memcpy ( & V_196 -> V_223 . V_198 ,
V_198 ,
sizeof( struct V_197 ) ) ;
break;
case V_224 :
V_200 =
(struct V_199 * ) V_205 ;
V_196 -> V_153 = V_200 -> V_225 ;
memcpy ( & V_196 -> V_223 . V_200 ,
V_200 ,
sizeof( struct V_199 ) ) ;
break;
case V_226 :
V_202 =
(struct V_201 * ) V_205 ;
memcpy ( & V_196 -> V_227 . V_202 ,
V_202 ,
sizeof( struct V_201 ) ) ;
break;
case V_228 :
V_204 =
(struct V_203 * )
V_205 ;
memcpy ( & V_196 -> V_227 . V_204 ,
V_204 ,
sizeof( struct V_203 ) ) ;
break;
case V_229 :
V_196 -> V_230 = * ( V_205 + 2 ) ;
break;
case V_231 :
V_196 -> V_232 = * ( V_205 + 2 ) ;
V_196 -> V_233 = true ;
break;
case V_234 :
V_196 -> V_59 = true ;
case V_235 :
case V_236 :
case V_237 :
V_196 -> V_233 = true ;
break;
case V_238 :
if ( V_211 ) {
if ( ( V_207 + V_210 ) >
V_110 )
V_209 =
( V_110 -
V_210 ) ;
else
V_209 = V_207 ;
V_206 = ( T_1 * ) V_196 -> V_220 ;
V_206 += V_210 ;
memcpy ( V_206 , V_205 + 2 , V_209 ) ;
V_206 = ( T_1 * ) V_196 -> V_221 ;
V_206 += V_210 ;
memcpy ( V_206 , V_205 + 2 , V_209 ) ;
}
break;
case V_39 :
V_213 = (struct V_23 * )
V_205 ;
if ( ! memcmp
( V_213 -> V_10 . V_26 , V_214 ,
sizeof( V_214 ) ) ) {
V_196 -> V_9 =
(struct V_23 * )
V_205 ;
V_196 -> V_239 = ( V_91 )
( V_205 - V_196 -> V_216 ) ;
} else if ( ! memcmp ( V_213 -> V_10 . V_26 , V_215 ,
sizeof( V_215 ) ) ) {
if ( V_208 ==
sizeof( struct V_240 ) ||
V_208 ==
sizeof( struct V_241 ) )
memcpy ( ( T_1 * ) & V_196 -> V_242 ,
V_205 , V_208 ) ;
}
break;
case V_35 :
V_196 -> V_12 =
(struct V_20 * ) V_205 ;
V_196 -> V_243 = ( V_91 ) ( V_205 -
V_196 -> V_216 ) ;
break;
case V_48 :
V_196 -> V_47 =
(struct V_20 * ) V_205 ;
V_196 -> V_244 = ( V_91 ) ( V_205 -
V_196 -> V_216 ) ;
break;
case V_177 :
V_196 -> V_63 = (struct V_178 * )
( V_205 +
sizeof( struct V_218 ) ) ;
V_196 -> V_245 = ( V_91 ) ( V_205 +
sizeof( struct V_218 ) -
V_196 -> V_216 ) ;
break;
case V_246 :
V_196 -> V_247 =
(struct V_248 * ) ( V_205 +
sizeof( struct V_218 ) ) ;
V_196 -> V_249 = ( V_91 ) ( V_205 +
sizeof( struct V_218 ) -
V_196 -> V_216 ) ;
break;
case V_250 :
V_196 -> V_251 = false ;
V_196 -> V_252 =
( void * ) ( V_205 +
sizeof( struct V_218 ) ) ;
V_196 -> V_253 =
( V_91 ) ( ( T_1 * ) V_196 -> V_252 -
V_196 -> V_216 ) ;
break;
case V_254 :
V_196 -> V_255 =
( void * ) ( V_205 +
sizeof( struct V_218 ) ) ;
V_196 -> V_256 =
( V_91 ) ( ( T_1 * ) V_196 -> V_255 -
V_196 -> V_216 ) ;
break;
case V_257 :
V_196 -> V_258 = V_205 ;
V_196 -> V_259 =
( V_91 ) ( V_205 - V_196 -> V_216 ) ;
break;
case V_260 :
V_196 -> V_261 = V_205 ;
V_196 -> V_262 =
( V_91 ) ( V_205 - V_196 -> V_216 ) ;
break;
case V_263 :
V_196 -> V_264 = ( void * ) V_205 ;
V_196 -> V_265 =
( V_91 ) ( ( T_1 * ) V_196 -> V_264 -
V_196 -> V_216 ) ;
break;
default:
break;
}
V_205 += V_207 + 2 ;
V_212 -= ( V_207 + 2 ) ;
}
return V_34 ;
}
static T_1
F_40 ( T_1 V_87 )
{
switch ( V_87 ) {
case V_266 :
return V_267 ;
case V_268 :
default:
return V_269 ;
}
}
int F_41 ( struct V_4 * V_5 ,
const struct V_66 * V_67 )
{
int V_34 ;
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_270 * V_271 ;
union V_272 * V_105 ;
struct V_121 * V_139 ;
struct V_68 * V_69 ;
T_1 V_70 ;
T_1 V_273 ;
T_1 V_120 ;
unsigned long V_85 ;
if ( V_8 -> V_274 ) {
F_19 ( V_8 , V_275 ,
L_38 ) ;
return - V_276 ;
}
if ( V_5 -> V_277 ) {
F_19 ( V_8 , V_275 ,
L_39 ) ;
return - V_276 ;
}
if ( V_8 -> V_278 || V_8 -> V_279 ) {
F_19 ( V_8 , ERROR ,
L_40 ) ;
return - V_280 ;
}
F_42 ( & V_8 -> V_281 , V_85 ) ;
V_8 -> V_274 = true ;
F_43 ( & V_8 -> V_281 , V_85 ) ;
V_105 = F_44 ( sizeof( union V_272 ) ,
V_282 ) ;
if ( ! V_105 ) {
V_34 = - V_283 ;
goto V_284;
}
V_69 = F_45 ( V_180 ,
sizeof( struct V_68 ) ,
V_282 ) ;
if ( ! V_69 ) {
F_46 ( V_105 ) ;
V_34 = - V_283 ;
goto V_284;
}
F_32 ( V_5 , V_67 , & V_105 -> V_285 ,
& V_139 , V_69 , & V_120 ,
& V_70 , & V_273 ) ;
V_34 = F_26 ( V_5 , V_120 , V_70 ,
& V_105 -> V_285 , V_139 ,
V_69 ) ;
if ( ! V_34 ) {
F_42 ( & V_8 -> V_286 , V_85 ) ;
if ( ! F_47 ( & V_8 -> V_287 ) ) {
V_271 = F_48 ( & V_8 -> V_287 ,
struct V_270 , V_288 ) ;
F_49 ( & V_271 -> V_288 ) ;
F_43 ( & V_8 -> V_286 ,
V_85 ) ;
F_50 ( V_8 , V_271 ,
true ) ;
F_51 ( V_8 -> V_289 , & V_8 -> V_290 ) ;
if ( ! V_5 -> V_115 ) {
F_19 ( V_8 , V_49 ,
L_41 ) ;
F_52 ( V_8 , V_271 ) ;
}
} else {
F_43 ( & V_8 -> V_286 ,
V_85 ) ;
}
}
F_46 ( V_105 ) ;
F_46 ( V_69 ) ;
V_284:
if ( V_34 ) {
F_42 ( & V_8 -> V_281 , V_85 ) ;
V_8 -> V_274 = false ;
F_43 ( & V_8 -> V_281 , V_85 ) ;
}
return V_34 ;
}
int F_53 ( struct V_291 * V_292 ,
struct V_104 * V_293 )
{
struct V_294 * V_295 = & V_292 -> V_296 . V_297 ;
V_295 -> V_54 = V_293 -> V_54 ;
memcpy ( V_295 -> V_163 , V_293 -> V_160 ,
sizeof( V_295 -> V_163 ) ) ;
memcpy ( V_295 -> V_298 , V_293 -> V_113 , V_293 -> V_114 ) ;
V_292 -> V_299 = F_21 ( V_136 ) ;
V_292 -> V_300 = F_21 ( ( V_91 ) ( sizeof( V_295 -> V_54 )
+ sizeof( V_295 -> V_163 )
+ V_293 -> V_114 + V_301 ) ) ;
return 0 ;
}
int F_54 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
int V_34 = - 1 ;
if ( ! V_7 )
return - 1 ;
if ( ( F_55 ( V_5 , ( T_1 ) V_7 -> V_302 ,
( V_91 ) V_7 -> V_153 , 0 ) ) ) {
switch ( V_5 -> V_54 ) {
case V_55 :
case V_303 :
V_34 = F_18 ( V_5 , V_7 ,
V_5 -> V_54 ) ;
if ( V_34 )
F_19 ( V_5 -> V_8 , ERROR ,
L_42 ) ;
break;
default:
V_34 = 0 ;
}
}
return V_34 ;
}
static bool F_56 ( struct V_41 * V_45 )
{
int V_304 ;
for ( V_304 = 0 ; V_304 < V_45 -> V_44 ; V_304 ++ ) {
if ( V_45 -> V_45 [ V_304 ] )
return false ;
}
return true ;
}
static int F_57 ( struct V_4 * V_5 ,
struct V_305 * V_306 )
{
struct V_6 * V_7 ;
int V_34 ;
int V_307 ;
V_7 = F_44 ( sizeof( * V_7 ) , V_282 ) ;
if ( ! V_7 )
return - V_283 ;
V_34 = F_58 ( V_5 , V_306 , V_7 ) ;
if ( V_34 )
goto V_284;
if ( F_56 ( & V_7 -> V_45 ) ) {
F_19 ( V_5 -> V_8 , V_49 , L_43 ) ;
for ( V_307 = 0 ; V_307 < V_180 ; V_307 ++ ) {
if ( V_5 -> V_308 [ V_307 ] . V_98 ==
V_306 -> V_153 -> V_99 )
break;
if ( ! V_5 -> V_308 [ V_307 ] . V_98 ) {
V_5 -> V_308 [ V_307 ] . V_98 =
V_306 -> V_153 -> V_99 ;
V_5 -> V_308 [ V_307 ] . V_87 =
V_306 -> V_153 -> V_72 ;
V_5 -> V_308 [ V_307 ] . V_151 =
V_309 ;
break;
}
}
}
V_284:
F_46 ( V_7 ) ;
return 0 ;
}
static int F_59 ( struct V_4 * V_5 ,
struct V_305 * V_306 )
{
struct V_6 * V_7 ;
int V_34 ;
unsigned long V_85 ;
V_7 = F_44 ( sizeof( struct V_6 ) , V_282 ) ;
if ( ! V_7 )
return - V_283 ;
V_34 = F_58 ( V_5 , V_306 , V_7 ) ;
if ( V_34 )
goto V_284;
V_34 = F_54 ( V_5 , V_7 ) ;
if ( V_34 )
goto V_284;
F_42 ( & V_5 -> V_310 , V_85 ) ;
memcpy ( & V_5 -> V_183 . V_184 , V_7 ,
sizeof( V_5 -> V_183 . V_184 ) ) ;
F_60 ( V_5 ) ;
F_43 ( & V_5 -> V_310 , V_85 ) ;
V_284:
F_46 ( V_7 -> V_216 ) ;
F_46 ( V_7 ) ;
return 0 ;
}
static int
F_61 ( struct V_4 * V_5 , T_1 * * V_311 ,
T_2 * V_212 , T_4 V_312 , T_1 * V_87 ,
bool V_134 , T_3 V_313 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_314 * V_315 ;
struct V_305 * V_306 ;
T_1 V_163 [ V_162 ] ;
T_3 V_316 ;
const T_1 * V_317 ;
T_5 V_318 ;
V_91 V_153 = 0 ;
V_91 V_319 = 0 ;
T_2 V_320 ;
T_2 V_321 ;
V_91 V_322 ;
V_91 V_323 ;
T_1 * V_205 ;
T_4 V_324 ;
struct V_325 * V_326 ;
struct V_327 * V_328 ;
if ( * V_212 >= sizeof( V_319 ) ) {
V_319 = F_28 ( * ( V_329 * ) ( * V_311 ) ) ;
* V_212 -= sizeof( V_319 ) ;
* V_311 += sizeof( V_319 ) ;
}
if ( ! V_319 || V_319 > * V_212 ) {
* V_311 += * V_212 ;
* V_212 = 0 ;
return - V_280 ;
}
V_205 = * V_311 ;
* V_311 += V_319 ;
* V_212 -= V_319 ;
V_320 = V_319 ;
if ( V_320 < V_162 + sizeof( T_1 ) +
sizeof( struct V_325 ) ) {
F_19 ( V_8 , ERROR ,
L_44 ) ;
return - V_280 ;
}
memcpy ( V_163 , V_205 , V_162 ) ;
V_205 += V_162 ;
V_320 -= V_162 ;
if ( ! V_134 ) {
V_316 = ( T_3 ) * V_205 ;
V_316 = ( - V_316 ) * 100 ;
V_205 += sizeof( T_1 ) ;
V_320 -= sizeof( T_1 ) ;
F_19 ( V_8 , V_49 ,
L_45 , V_316 ) ;
} else {
V_316 = V_313 ;
}
V_326 = (struct V_325 * ) V_205 ;
V_205 += sizeof( * V_326 ) ;
V_320 -= sizeof( * V_326 ) ;
V_324 = F_62 ( V_326 -> V_324 ) ;
V_322 = F_28 ( V_326 -> V_322 ) ;
V_323 = F_28 ( V_326 -> V_323 ) ;
F_19 ( V_8 , V_49 ,
L_46 ,
V_323 ) ;
V_317 = V_205 ;
V_318 = V_320 ;
F_19 ( V_8 , V_49 ,
L_47 ,
V_320 ) ;
while ( V_320 >= sizeof( struct V_218 ) ) {
T_1 V_11 , V_207 ;
V_11 = * V_205 ;
V_207 = * ( V_205 + 1 ) ;
if ( V_320 < V_207 +
sizeof( struct V_218 ) ) {
F_19 ( V_8 , ERROR ,
L_48 , V_31 ) ;
return - V_280 ;
}
if ( V_11 == V_224 ) {
V_153 = * ( V_205 +
sizeof( struct V_218 ) ) ;
break;
}
V_205 += V_207 + sizeof( struct V_218 ) ;
V_320 -= V_207 +
sizeof( struct V_218 ) ;
}
if ( V_153 ) {
struct V_75 * V_330 ;
T_1 V_72 ;
if ( V_153 == V_5 -> V_130 ) {
F_19 ( V_8 , V_275 ,
L_49 ) ;
return 0 ;
}
V_72 = V_269 ;
if ( V_87 )
V_72 = F_40 ( * V_87 &
( F_63 ( 0 ) | F_63 ( 1 ) ) ) ;
V_315 = F_55 ( V_5 , V_72 , V_153 , 0 ) ;
V_321 = V_315 ? V_315 -> V_321 : 0 ;
V_330 = F_64 ( V_5 -> V_80 . V_81 , V_321 ) ;
if ( V_330 && ! ( V_330 -> V_85 & V_86 ) ) {
V_306 = F_65 ( V_5 -> V_80 . V_81 ,
V_330 , V_331 ,
V_163 , V_324 ,
V_323 , V_322 ,
V_317 , V_318 , V_316 , V_282 ) ;
if ( V_306 ) {
V_328 = (struct V_327 * ) V_306 -> V_5 ;
V_328 -> V_72 = V_72 ;
V_328 -> V_312 = V_312 ;
if ( V_5 -> V_53 &&
! memcmp ( V_163 , V_5 -> V_183 .
V_184 . V_332 ,
V_162 ) )
F_59 ( V_5 ,
V_306 ) ;
F_66 ( V_5 -> V_80 . V_81 , V_306 ) ;
}
if ( ( V_330 -> V_85 & V_333 ) ||
( V_330 -> V_85 & V_92 ) ) {
F_19 ( V_8 , V_49 ,
L_50 ,
V_153 ) ;
F_57 ( V_5 , V_306 ) ;
}
}
} else {
F_19 ( V_8 , V_275 , L_51 ) ;
}
return 0 ;
}
static void F_67 ( struct V_4 * V_5 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
V_8 -> V_334 = 0 ;
if ( V_8 -> V_335 -> V_336 ) {
V_8 -> V_337 . V_338 = 0 ;
if ( ! V_5 -> V_115 ) {
F_19 ( V_8 , V_49 ,
L_52 ) ;
F_68 ( V_8 , V_8 -> V_335 ) ;
}
}
}
static int
F_69 ( struct V_4 * V_5 )
{
int V_34 ;
struct V_51 * V_8 = V_5 -> V_8 ;
T_1 V_339 = 0 ;
struct V_66 * V_340 ;
if ( V_8 -> V_341 || ! V_5 -> V_115 ||
V_5 -> V_342 ) {
V_8 -> V_341 = false ;
return 0 ;
}
if ( ! V_5 -> V_308 [ 0 ] . V_98 ) {
F_19 ( V_8 , V_49 , L_53 ) ;
return 0 ;
}
V_340 = F_44 ( sizeof( * V_340 ) , V_282 ) ;
if ( ! V_340 )
return - V_283 ;
memset ( V_340 , 0 , sizeof( * V_340 ) ) ;
for ( V_339 = 0 ; V_339 < V_180 ; V_339 ++ ) {
if ( ! V_5 -> V_308 [ V_339 ] . V_98 )
break;
memcpy ( & V_340 -> V_88 [ V_339 ] ,
& V_5 -> V_308 [ V_339 ] ,
sizeof( struct V_343 ) ) ;
}
V_8 -> V_341 = true ;
V_340 -> V_164 = V_5 -> V_115 -> V_344 ;
V_340 -> V_165 = V_5 -> V_115 -> V_345 ;
V_34 = F_41 ( V_5 , V_340 ) ;
F_46 ( V_340 ) ;
memset ( & V_5 -> V_308 , 0 , sizeof( V_5 -> V_308 ) ) ;
if ( V_34 ) {
F_70 ( V_5 -> V_8 -> V_346 , L_54 , V_34 ) ;
return V_34 ;
}
return 0 ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_270 * V_271 ;
unsigned long V_85 ;
F_42 ( & V_8 -> V_286 , V_85 ) ;
if ( F_47 ( & V_8 -> V_287 ) ) {
F_43 ( & V_8 -> V_286 , V_85 ) ;
F_42 ( & V_8 -> V_281 , V_85 ) ;
V_8 -> V_274 = false ;
F_43 ( & V_8 -> V_281 , V_85 ) ;
F_69 ( V_5 ) ;
if ( ! V_8 -> V_134 )
F_67 ( V_5 ) ;
if ( V_5 -> V_115 ) {
struct V_347 V_348 = {
. V_349 = false ,
} ;
F_19 ( V_8 , V_49 ,
L_55 ) ;
F_72 ( V_5 -> V_115 , & V_348 ) ;
V_5 -> V_115 = NULL ;
V_5 -> V_342 = false ;
} else {
V_5 -> V_342 = false ;
F_19 ( V_8 , V_49 ,
L_56 ) ;
}
} else if ( ( V_5 -> V_342 && ! V_5 -> V_115 ) ||
V_5 -> V_277 ) {
F_43 ( & V_8 -> V_286 , V_85 ) ;
F_31 ( V_8 ) ;
F_42 ( & V_8 -> V_281 , V_85 ) ;
V_8 -> V_274 = false ;
F_43 ( & V_8 -> V_281 , V_85 ) ;
if ( ! V_8 -> V_341 ) {
if ( V_5 -> V_115 ) {
struct V_347 V_348 = {
. V_349 = true ,
} ;
F_19 ( V_8 , V_49 ,
L_57 ) ;
F_72 ( V_5 -> V_115 , & V_348 ) ;
V_5 -> V_115 = NULL ;
V_5 -> V_342 = false ;
} else {
V_5 -> V_342 = false ;
F_19 ( V_8 , V_49 ,
L_56 ) ;
}
}
} else {
V_271 = F_48 ( & V_8 -> V_287 ,
struct V_270 , V_288 ) ;
F_49 ( & V_271 -> V_288 ) ;
F_43 ( & V_8 -> V_286 , V_85 ) ;
F_50 ( V_8 , V_271 , true ) ;
}
return;
}
void F_73 ( struct V_51 * V_8 )
{
struct V_4 * V_5 ;
unsigned long V_350 ;
int V_78 ;
F_31 ( V_8 ) ;
if ( V_8 -> V_274 ) {
F_42 ( & V_8 -> V_281 , V_350 ) ;
V_8 -> V_274 = false ;
F_43 ( & V_8 -> V_281 , V_350 ) ;
for ( V_78 = 0 ; V_78 < V_8 -> V_351 ; V_78 ++ ) {
V_5 = V_8 -> V_5 [ V_78 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_115 ) {
struct V_347 V_348 = {
. V_349 = true ,
} ;
F_19 ( V_8 , V_49 ,
L_57 ) ;
F_72 ( V_5 -> V_115 , & V_348 ) ;
V_5 -> V_115 = NULL ;
V_5 -> V_342 = false ;
}
}
}
}
int F_74 ( struct V_4 * V_5 ,
struct V_291 * V_352 )
{
int V_34 = 0 ;
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_353 * V_354 ;
struct V_185 * V_189 ;
struct V_355 * V_356 ;
T_1 * V_311 ;
T_2 V_357 ;
T_2 V_212 ;
T_2 V_304 ;
T_2 V_187 ;
struct V_358 * V_359 ;
struct V_360 * V_361 ;
T_1 V_362 ;
T_6 V_312 = 0 ;
T_1 * V_87 ;
struct V_363 * V_364 ;
struct V_365 * V_366 = NULL ;
V_362 = ( F_28 ( V_352 -> V_299 )
== V_367 ) ;
if ( V_362 )
V_354 = & V_352 -> V_296 . V_368 . V_369 ;
else
V_354 = & V_352 -> V_296 . V_369 ;
if ( V_354 -> V_370 > V_371 ) {
F_19 ( V_8 , ERROR ,
L_58 ,
V_354 -> V_370 ) ;
V_34 = - 1 ;
goto V_372;
}
F_27 ( V_5 ) ;
V_212 = F_28 ( V_354 -> V_373 ) ;
F_19 ( V_8 , V_49 ,
L_59 ,
V_212 ) ;
V_357 = F_28 ( V_352 -> V_300 ) ;
F_19 ( V_8 , V_49 ,
L_60 ,
V_354 -> V_370 ) ;
V_311 = V_354 -> V_374 ;
V_187 = V_357 - ( V_212
+ sizeof( V_354 -> V_373 )
+ sizeof( V_354 -> V_370 )
+ V_301 ) ;
V_189 = (struct V_185 * ) ( V_354 ->
V_374 +
V_212 ) ;
F_38 ( V_8 , V_189 , V_187 ,
V_194 ,
(struct V_185 * * )
& V_356 ) ;
F_38 ( V_8 , V_189 , V_187 ,
V_195 ,
(struct V_185 * * )
& V_359 ) ;
#ifdef F_75
if ( V_5 -> V_80 . V_81 -> V_375 )
V_366 = V_5 -> V_80 . V_81 -> V_375 -> V_366 ;
#endif
if ( V_366 ) {
V_8 -> V_376 =
F_44 ( sizeof( struct V_363 ) +
sizeof( struct V_363 * ) *
V_354 -> V_370 , V_377 ) ;
if ( V_8 -> V_376 )
V_8 -> V_376 -> V_378 = V_354 -> V_370 ;
}
for ( V_304 = 0 ; V_304 < V_354 -> V_370 && V_212 ; V_304 ++ ) {
if ( V_356 )
memcpy ( & V_312 , & V_356 -> V_379 [ V_304 * V_380 ] ,
sizeof( V_312 ) ) ;
if ( V_359 ) {
V_361 = & V_359 -> V_381 [ V_304 ] ;
V_87 = & V_361 -> V_87 ;
} else {
V_87 = NULL ;
}
if ( V_359 && V_8 -> V_376 ) {
V_8 -> V_376 -> V_382 [ V_304 ] =
F_44 ( sizeof( * V_364 ) +
sizeof( T_2 ) , V_377 ) ;
V_364 = V_8 -> V_376 -> V_382 [ V_304 ] ;
if ( V_364 ) {
memset ( V_364 , 0 , sizeof( * V_364 ) ) ;
if ( V_359 ) {
V_364 -> V_83 = 1 ;
V_364 -> V_84 [ 0 ] =
V_361 -> V_98 ;
}
}
}
V_34 = F_61 ( V_5 , & V_311 ,
& V_212 ,
F_62 ( V_312 ) ,
V_87 , false , 0 ) ;
if ( V_34 )
goto V_372;
}
V_372:
F_71 ( V_5 ) ;
return V_34 ;
}
int F_76 ( struct V_4 * V_5 ,
struct V_291 * V_292 ,
void * V_383 )
{
struct V_384 * V_134 = & V_292 -> V_296 . V_134 ;
struct V_104 * V_293 = V_383 ;
memcpy ( V_134 -> V_298 , V_293 -> V_113 , V_293 -> V_114 ) ;
V_292 -> V_299 = F_21 ( V_135 ) ;
V_292 -> V_300 = F_21 ( ( V_91 ) ( sizeof( V_134 -> V_385 )
+ V_293 -> V_114 + V_301 ) ) ;
return 0 ;
}
int F_77 ( struct V_4 * V_5 ,
struct V_291 * V_292 ,
void * V_383 )
{
struct V_386 * V_387 =
& V_292 -> V_296 . V_388 ;
struct V_102 * V_103 = V_383 ;
T_1 * V_111 = V_387 -> V_186 ;
T_1 V_149 ;
T_2 V_44 , V_77 , V_151 , V_152 , V_150 ;
int V_78 ;
struct V_141 * V_142 ;
struct V_389 * V_390 ;
struct V_391 * V_392 ;
struct V_393 * V_394 ;
struct V_145 * V_146 ;
struct V_121 * V_395 ;
struct V_68 * V_396 ;
V_292 -> V_299 = F_21 ( V_397 ) ;
V_292 -> V_300 = F_21 ( sizeof( * V_387 ) + V_301 ) ;
V_387 -> V_398 = F_21 ( V_103 -> V_398 ) ;
V_387 -> V_399 = V_103 -> V_399 ;
V_387 -> V_400 = V_103 -> V_400 ;
V_387 -> V_401 =
F_78 ( V_103 -> V_401 ) ;
V_387 -> V_402 =
F_78 ( V_103 -> V_402 ) ;
if ( ! V_387 -> V_399 )
return 0 ;
V_387 -> V_403 = V_103 -> V_403 ;
V_149 = ( V_103 -> V_149 ? V_103 ->
V_149 : V_5 -> V_8 -> V_159 ) ;
if ( V_149 ) {
V_142 = (struct V_141 * ) V_111 ;
V_142 -> V_117 . type = F_21 ( V_175 ) ;
V_142 -> V_117 . V_119 =
F_21 ( sizeof( V_142 -> V_149 ) ) ;
V_142 -> V_149 = F_21 ( ( V_91 ) V_149 ) ;
V_111 += sizeof( V_142 -> V_117 ) +
F_28 ( V_142 -> V_117 . V_119 ) ;
}
if ( V_103 -> V_404 ) {
V_390 =
(struct V_389 * ) V_111 ;
V_390 -> V_117 . type =
F_21 ( V_405 ) ;
V_390 -> V_117 . V_119 =
F_21 ( sizeof( V_390 -> V_404 ) ) ;
V_390 -> V_404 =
F_21 ( V_103 -> V_404 ) ;
V_111 += sizeof( V_390 -> V_117 ) +
F_28 ( V_390 -> V_117 . V_119 ) ;
}
if ( V_103 -> V_406 ) {
V_392 =
(struct V_391 * ) V_111 ;
V_392 -> V_117 . type =
F_21 ( V_407 ) ;
V_392 -> V_117 . V_119 =
F_21 ( sizeof( V_392 -> V_406 ) ) ;
V_392 -> V_406 =
F_21 ( V_103 -> V_406 ) ;
V_111 += sizeof( V_392 -> V_117 ) +
F_28 ( V_392 -> V_117 . V_119 ) ;
}
for ( V_78 = 0 ; V_78 < V_103 -> V_164 ; V_78 ++ ) {
V_44 = V_103 -> V_165 [ V_78 ] . V_45 . V_44 ;
V_146 =
(struct V_145 * ) V_111 ;
V_146 -> V_117 . type =
F_21 ( V_166 ) ;
V_146 -> V_117 . V_119 = F_21 (
( V_91 ) ( V_44 + sizeof( V_146 ->
V_167 ) ) ) ;
if ( V_44 )
V_146 -> V_167 = 0 ;
else
V_146 -> V_167 =
V_168 ;
memcpy ( V_146 -> V_45 ,
V_103 -> V_165 [ V_78 ] . V_45 . V_45 , V_44 ) ;
V_111 += ( sizeof( V_146 -> V_117 )
+ F_28 ( V_146 -> V_117 . V_119 ) ) ;
}
V_395 = (struct V_121 * ) V_111 ;
if ( V_103 -> V_88 [ 0 ] . V_98 ) {
F_79 ( V_5 -> V_8 -> V_346 , L_61 ) ;
V_395 -> V_117 . type = F_21 ( V_129 ) ;
for ( V_77 = 0 ;
V_77 < V_408 &&
V_103 -> V_88 [ V_77 ] . V_98 ;
V_77 ++ ) {
V_396 = V_395 -> V_131 + V_77 ;
F_29 ( & V_395 -> V_117 . V_119 ,
sizeof( V_395 -> V_131 ) ) ;
V_396 -> V_98 =
V_103 -> V_88 [ V_77 ] . V_98 ;
V_396 -> V_87 =
V_103 -> V_88 [ V_77 ] . V_87 ;
V_151 =
V_103 -> V_88 [ V_77 ] . V_151 ;
if ( V_151 == V_181 )
V_396 -> V_95
|= V_96 ;
else
V_396 -> V_95
&= ~ V_96 ;
if ( V_103 -> V_88 [ V_77 ] . V_89 ) {
V_152 = ( V_91 ) V_103 ->
V_88 [ V_77 ] . V_89 ;
} else {
V_152 = ( V_151 ==
V_181 ) ?
V_5 -> V_8 -> V_93 :
V_5 -> V_8 -> V_101 ;
}
V_396 -> V_182 = F_21 ( V_152 ) ;
V_396 -> V_90 = F_21 ( V_152 ) ;
}
} else {
F_79 ( V_5 -> V_8 -> V_346 ,
L_62 ) ;
V_150 =
F_22 ( V_5 , V_103 ,
V_395 ->
V_131 ) ;
F_29 ( & V_395 -> V_117 . V_119 ,
V_150 *
sizeof( V_395 -> V_131 [ 0 ] ) ) ;
}
V_111 += ( sizeof( V_395 -> V_117 )
+ F_28 ( V_395 -> V_117 . V_119 ) ) ;
if ( V_103 -> V_409 ) {
V_394 =
(struct V_393 * ) V_111 ;
V_394 -> V_117 . type =
F_21 ( V_410 ) ;
V_394 -> V_117 . V_119 =
F_21 ( sizeof( V_394 -> V_409 ) ) ;
V_394 -> V_409 =
F_21 ( V_103 -> V_409 ) ;
V_111 += sizeof( V_394 -> V_117 ) +
F_28 ( V_394 -> V_117 . V_119 ) ;
}
F_37 ( V_5 , V_411 , & V_111 ) ;
F_29 ( & V_292 -> V_300 , V_111 - V_387 -> V_186 ) ;
return 0 ;
}
int F_80 ( struct V_4 * V_5 )
{
struct V_102 * V_412 ;
if ( ! V_5 -> V_413 ) {
F_79 ( V_5 -> V_8 -> V_346 , L_63 ) ;
return 0 ;
}
V_412 = F_44 ( sizeof( * V_412 ) , V_282 ) ;
if ( ! V_412 )
return - V_283 ;
V_412 -> V_400 = V_414 ;
V_412 -> V_398 = V_415 ;
V_412 -> V_399 = false ;
if ( F_30 ( V_5 , V_397 ,
V_137 , 0 , V_412 , true ) ) {
F_46 ( V_412 ) ;
return - V_280 ;
}
F_46 ( V_412 ) ;
V_5 -> V_413 = false ;
return 0 ;
}
static void
F_81 ( struct V_4 * V_5 ,
struct V_416 * V_417 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
T_1 V_78 , V_418 ;
struct V_419 * V_420 ;
struct V_421 V_422 ;
V_420 = ( void * ) ( ( T_1 * ) V_417 +
sizeof( struct V_138 ) ) ;
V_418 = F_28 ( V_417 -> V_117 . V_119 ) /
sizeof( struct V_421 ) ;
for ( V_78 = 0 ; V_78 < V_418 ; V_78 ++ ) {
V_422 . V_150 = V_420 -> V_150 ;
V_422 . V_423 = V_420 -> V_423 ;
V_422 . V_85 = V_420 -> V_85 ;
V_422 . V_424 = V_420 -> V_424 ;
V_422 . V_425 = F_28 ( V_420 -> V_425 ) ;
V_422 . V_426 =
F_28 ( V_420 -> V_426 ) ;
V_422 . V_427 =
F_28 ( V_420 -> V_427 ) ;
F_19 ( V_8 , V_49 ,
L_64 ,
V_422 . V_150 ,
V_422 . V_424 ,
V_422 . V_425 ,
V_422 . V_426 ,
V_422 . V_427 ) ;
memcpy ( & V_8 -> V_422 [ V_8 -> V_334 ++ ] , & V_422 ,
sizeof( struct V_421 ) ) ;
V_420 ++ ;
}
}
int F_82 ( struct V_4 * V_5 ,
struct V_291 * V_352 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_384 * V_428 ;
struct V_138 * V_186 ;
struct V_416 * V_417 ;
V_91 V_429 , type , V_119 ;
struct V_291 * V_430 ;
struct V_270 * V_271 ;
unsigned long V_350 , V_431 ;
bool V_432 = false ;
F_19 ( V_8 , V_49 , L_65 ) ;
V_428 = & V_352 -> V_296 . V_134 ;
V_186 = ( void * ) V_428 -> V_298 ;
V_429 = F_28 ( V_352 -> V_300 ) - ( sizeof( * V_428 ) + V_301
- 1 ) ;
while ( V_429 >= sizeof( struct V_138 ) ) {
type = F_28 ( V_186 -> type ) ;
V_119 = F_28 ( V_186 -> V_119 ) ;
if ( V_429 < ( sizeof( struct V_138 ) + V_119 ) ) {
F_19 ( V_8 , ERROR ,
L_66 ) ;
break;
}
switch ( type ) {
case V_433 :
V_417 = ( void * ) V_186 ;
F_81 ( V_5 , V_417 ) ;
break;
default:
break;
}
V_429 -= V_119 + sizeof( struct V_138 ) ;
V_186 = ( void * ) ( ( T_1 * ) V_186 + V_119 +
sizeof( struct V_138 ) ) ;
}
F_42 ( & V_8 -> V_434 , V_350 ) ;
F_42 ( & V_8 -> V_286 , V_431 ) ;
if ( F_47 ( & V_8 -> V_287 ) ) {
V_432 = true ;
F_83 (cmd_node, &adapter->cmd_pending_q, list) {
V_430 = ( void * ) V_271 -> V_435 -> V_36 ;
if ( F_28 ( V_430 -> V_299 ) ==
V_135 ) {
F_19 ( V_8 , V_49 ,
L_67 ) ;
V_432 = false ;
break;
}
}
}
F_43 ( & V_8 -> V_286 , V_431 ) ;
F_43 ( & V_8 -> V_434 , V_350 ) ;
if ( V_432 )
F_67 ( V_5 ) ;
return 0 ;
}
int F_84 ( struct V_4 * V_5 ,
void * V_436 )
{
int V_34 = 0 ;
struct V_51 * V_8 = V_5 -> V_8 ;
T_1 * V_311 ;
T_2 V_212 , V_437 , V_304 ;
V_91 type , V_119 ;
struct V_185 * V_186 ;
struct V_438 * V_439 ;
struct V_440 * V_441 ;
T_1 * V_87 ;
T_4 V_312 = 0 ;
T_3 V_316 = 0 ;
struct V_442 * V_443 = V_436 ;
T_1 V_444 = V_443 -> V_444 ;
T_1 * V_369 = V_436 + sizeof( struct V_442 ) ;
V_91 V_357 = F_28 ( V_443 -> V_445 ) ;
if ( V_444 > V_371 ) {
F_19 ( V_8 , ERROR ,
L_68 ,
V_444 ) ;
V_34 = - 1 ;
goto V_372;
}
V_212 = V_357 ;
F_19 ( V_8 , V_49 ,
L_69 ,
V_357 , V_444 ) ;
F_85 ( V_8 , V_446 , L_70 , V_436 ,
V_357 +
sizeof( struct V_442 ) ) ;
V_186 = (struct V_185 * ) V_369 ;
for ( V_304 = 0 ; V_304 < V_444 && V_212 ; V_304 ++ ) {
type = F_28 ( V_186 -> V_117 . type ) ;
V_119 = F_28 ( V_186 -> V_117 . V_119 ) ;
if ( V_212 < sizeof( struct V_138 ) + V_119 ) {
F_19 ( V_8 , ERROR ,
L_71 ) ;
break;
}
V_439 = NULL ;
V_441 = NULL ;
V_437 = V_212 ;
if ( type != V_447 )
break;
V_311 = ( T_1 * ) V_186 ;
V_439 = (struct V_438 * ) V_186 ;
V_186 = (struct V_185 * ) ( V_186 -> V_36 + V_119 ) ;
V_437 -=
( V_119 + sizeof( struct V_138 ) ) ;
while ( V_437 >=
sizeof( struct V_138 ) &&
F_28 ( V_186 -> V_117 . type ) != V_447 ) {
type = F_28 ( V_186 -> V_117 . type ) ;
V_119 = F_28 ( V_186 -> V_117 . V_119 ) ;
if ( V_437 <
sizeof( struct V_138 ) + V_119 ) {
F_19 ( V_8 , ERROR ,
L_72
L_73 ) ;
V_439 = NULL ;
V_437 = 0 ;
continue;
}
switch ( type ) {
case V_448 :
V_441 =
(struct V_440 * ) V_186 ;
if ( V_119 !=
sizeof( struct V_440 ) -
sizeof( struct V_138 ) ) {
V_437 = 0 ;
continue;
}
break;
default:
break;
}
V_186 = (struct V_185 * ) ( V_186 -> V_36 + V_119 ) ;
V_212 -=
( V_119 + sizeof( struct V_138 ) ) ;
V_437 -=
( V_119 + sizeof( struct V_138 ) ) ;
}
if ( ! V_439 )
break;
V_311 += sizeof( V_91 ) ;
V_212 -= sizeof( V_91 ) ;
if ( V_441 ) {
V_316 = ( T_3 ) ( V_449 ) ( F_28 ( V_441 -> V_316 ) ) ;
V_316 *= 100 ;
F_19 ( V_8 , V_49 ,
L_45 , V_316 ) ;
V_312 = F_62 ( V_441 -> V_450 ) ;
V_87 = & V_441 -> V_87 ;
} else {
V_87 = NULL ;
}
V_34 = F_61 ( V_5 , & V_311 ,
& V_212 , V_312 ,
V_87 , true , V_316 ) ;
if ( V_34 )
goto V_372;
}
V_372:
if ( ! V_443 -> V_451 )
F_71 ( V_5 ) ;
return V_34 ;
}
int F_86 ( struct V_291 * V_292 )
{
struct V_452 * V_453 =
& V_292 -> V_296 . V_454 ;
V_292 -> V_299 = F_21 ( V_367 ) ;
V_292 -> V_300 = F_21 ( sizeof( struct V_452 )
+ V_301 ) ;
V_453 -> V_455 = 1 ;
return 0 ;
}
void
F_87 ( struct V_4 * V_5 ,
struct V_270 * V_271 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
unsigned long V_85 ;
V_271 -> V_336 = true ;
V_271 -> V_456 = & V_8 -> V_457 ;
F_42 ( & V_8 -> V_286 , V_85 ) ;
F_88 ( & V_271 -> V_288 , & V_8 -> V_287 ) ;
F_43 ( & V_8 -> V_286 , V_85 ) ;
}
static int F_89 ( struct V_4 * V_5 ,
struct V_41 * V_458 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
int V_34 ;
struct V_66 * V_293 ;
if ( V_8 -> V_274 ) {
F_19 ( V_8 , V_275 ,
L_38 ) ;
return - V_276 ;
}
if ( V_5 -> V_277 ) {
F_19 ( V_8 , V_275 ,
L_39 ) ;
return - V_276 ;
}
V_293 = F_44 ( sizeof( struct V_66 ) , V_282 ) ;
if ( ! V_293 )
return - V_283 ;
V_293 -> V_165 = V_458 ;
V_293 -> V_164 = 1 ;
V_34 = F_41 ( V_5 , V_293 ) ;
F_46 ( V_293 ) ;
return V_34 ;
}
int F_90 ( struct V_4 * V_5 ,
struct V_41 * V_458 )
{
int V_34 ;
if ( F_91 ( & V_5 -> V_459 ) ) {
F_19 ( V_5 -> V_8 , ERROR ,
L_74 ,
V_31 ) ;
return - 1 ;
}
V_5 -> V_8 -> V_457 = false ;
if ( V_458 && V_458 -> V_44 != 0 )
V_34 = F_89 ( V_5 , V_458 ) ;
else
V_34 = F_41 ( V_5 , NULL ) ;
F_92 ( & V_5 -> V_459 ) ;
return V_34 ;
}
int
F_37 ( struct V_4 * V_5 ,
V_91 V_460 , T_1 * * V_461 )
{
int V_339 , V_462 = 0 ;
struct V_463 * V_464 ;
if ( ! V_461 )
return 0 ;
if ( ! ( * V_461 ) )
return 0 ;
for ( V_339 = 0 ; V_339 < V_465 ; V_339 ++ ) {
if ( V_5 -> V_466 [ V_339 ] . V_467 & V_460 ) {
V_464 =
(struct V_463 * )
* V_461 ;
V_464 -> V_117 . type =
F_21 ( V_468 ) ;
V_464 -> V_117 . V_119 =
F_21 ( ( ( ( V_91 ) V_5 -> V_466 [ V_339 ] . V_21 [ 1 ] )
& 0x00FF ) + 2 ) ;
memcpy ( V_464 -> V_21 , V_5 -> V_466 [ V_339 ] . V_21 ,
F_28 ( V_464 -> V_117 . V_119 ) ) ;
* V_461 += F_28 ( V_464 -> V_117 . V_119 ) +
sizeof( struct V_138 ) ;
V_462 += F_28 ( V_464 -> V_117 . V_119 ) +
sizeof( struct V_138 ) ;
}
}
return V_462 ;
}
void
F_60 ( struct V_4 * V_5 )
{
struct V_6 * V_469 =
& V_5 -> V_183 . V_184 ;
if ( ! V_469 -> V_217 )
return;
if ( ! V_5 -> V_470 ||
V_5 -> V_471 != V_469 -> V_217 ) {
V_5 -> V_471 = V_469 -> V_217 ;
F_46 ( V_5 -> V_470 ) ;
V_5 -> V_470 = F_93 ( V_469 -> V_217 ,
V_377 ) ;
if ( ! V_5 -> V_470 )
return;
}
memcpy ( V_5 -> V_470 , V_469 -> V_216 ,
V_469 -> V_217 ) ;
F_19 ( V_5 -> V_8 , V_49 ,
L_75 ,
V_5 -> V_471 ) ;
V_469 -> V_216 = V_5 -> V_470 ;
if ( V_469 -> V_9 )
V_469 -> V_9 =
(struct V_23 * )
( V_469 -> V_216 +
V_469 -> V_239 ) ;
if ( V_469 -> V_12 )
V_469 -> V_12 = (struct V_20 * )
( V_469 -> V_216 +
V_469 -> V_243 ) ;
if ( V_469 -> V_63 )
V_469 -> V_63 = (struct V_178 * )
( V_469 -> V_216 +
V_469 -> V_245 ) ;
if ( V_469 -> V_247 )
V_469 -> V_247 = (struct V_248 * )
( V_469 -> V_216 +
V_469 -> V_249 ) ;
if ( V_469 -> V_252 )
V_469 -> V_252 = ( void * ) ( V_469 -> V_216 +
V_469 -> V_253 ) ;
if ( V_469 -> V_255 )
V_469 -> V_255 = ( void * ) ( V_469 -> V_216 +
V_469 -> V_256 ) ;
if ( V_469 -> V_258 )
V_469 -> V_258 =
( V_469 -> V_216 + V_469 -> V_259 ) ;
if ( V_469 -> V_261 )
V_469 -> V_261 = V_469 -> V_216 +
V_469 -> V_262 ;
if ( V_469 -> V_264 )
V_469 -> V_264 = ( void * ) ( V_469 -> V_216 +
V_469 -> V_265 ) ;
}
void
F_94 ( struct V_4 * V_5 )
{
F_46 ( V_5 -> V_470 ) ;
V_5 -> V_470 = NULL ;
}
