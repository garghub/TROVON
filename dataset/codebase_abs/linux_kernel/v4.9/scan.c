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
struct V_149 * V_150 ;
T_1 * V_111 ;
T_2 V_151 ;
T_2 V_44 ;
T_2 V_77 ;
T_2 V_152 ;
T_2 V_153 ;
V_91 V_154 ;
T_1 V_155 ;
T_1 V_87 ;
int V_78 ;
T_1 V_156 ;
struct V_157 * V_158 ;
struct V_159 * V_54 ;
const T_1 V_160 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
V_105 -> V_114 = 0 ;
V_111 = V_105 -> V_113 ;
* V_70 = false ;
* V_140 = false ;
if ( V_67 ) {
V_156 = true ;
V_105 -> V_54 =
( T_1 ) ( V_67 -> V_54 ? : V_8 -> V_161 ) ;
V_151 = V_67 -> V_151 ? : V_8 -> V_162 ;
memcpy ( V_105 -> V_163 ,
V_67 -> V_163 ,
sizeof( V_105 -> V_163 ) ) ;
if ( V_8 -> V_134 &&
! F_33 ( V_105 -> V_163 ) ) {
V_150 =
(struct V_149 * ) V_111 ;
V_150 -> V_117 . type = F_21 ( V_164 ) ;
V_150 -> V_117 . V_119 = F_21 ( V_165 ) ;
memcpy ( V_150 -> V_166 , V_67 -> V_163 ,
V_165 ) ;
V_111 += sizeof( struct V_149 ) ;
}
for ( V_78 = 0 ; V_78 < V_67 -> V_167 ; V_78 ++ ) {
V_44 = V_67 -> V_168 [ V_78 ] . V_44 ;
V_148 =
(struct V_147 * )
V_111 ;
V_148 -> V_117 . type =
F_21 ( V_169 ) ;
V_148 -> V_117 . V_119 = F_21 (
( V_91 ) ( V_44 + sizeof( V_148 ->
V_170 ) ) ) ;
if ( V_44 )
V_148 -> V_170 = 0 ;
else
V_148 -> V_170 =
V_171 ;
if ( ! memcmp ( V_67 -> V_168 [ V_78 ] . V_45 ,
L_21 , 7 ) )
V_148 -> V_170 = 0xfe ;
memcpy ( V_148 -> V_45 ,
V_67 -> V_168 [ V_78 ] . V_45 , V_44 ) ;
V_111 += ( sizeof( V_148 -> V_117 )
+ F_28 ( V_148 -> V_117 . V_119 ) ) ;
F_19 ( V_8 , V_49 ,
L_22 ,
V_78 , V_148 -> V_45 ,
V_148 -> V_170 ) ;
if ( ! V_44 && V_148 -> V_170 )
V_156 = false ;
}
if ( ( V_78 && V_156 ) ||
! F_33 ( V_105 -> V_163 ) )
* V_70 = true ;
if ( V_67 -> V_172 ) {
F_19 ( V_8 , V_49 ,
L_23 ,
V_67 -> V_172 ) ;
* V_120 =
V_173 ;
V_144 = ( void * ) V_111 ;
V_144 -> V_117 . type =
F_21 ( V_174 ) ;
V_144 -> V_117 . V_119 =
F_21 ( sizeof( V_144 -> V_175 ) ) ;
V_144 -> V_175 =
F_21 ( ( V_67 -> V_172 ) ) ;
V_111 +=
sizeof( struct V_143 ) ;
}
if ( ! F_34 ( V_67 -> V_176 , V_160 ) ) {
V_146 = ( void * ) V_111 ;
V_146 -> V_117 . type =
F_21 ( V_177 ) ;
V_146 -> V_117 . V_119 =
F_21 ( sizeof( V_146 -> V_178 ) ) ;
F_35 ( V_146 -> V_178 ,
V_67 -> V_176 ) ;
V_111 +=
sizeof( struct V_145 ) ;
}
} else {
V_105 -> V_54 = ( T_1 ) V_8 -> V_161 ;
V_151 = V_8 -> V_162 ;
}
if ( * V_70 )
* V_120 = V_173 ;
else
* V_120 = V_179 ;
if ( V_8 -> V_134 ) {
V_54 = (struct V_159 * ) V_111 ;
V_54 -> V_117 . type = F_21 ( V_180 ) ;
V_54 -> V_117 . V_119 = F_21 ( sizeof( V_54 -> V_54 ) ) ;
V_54 -> V_54 = V_105 -> V_54 ;
V_111 += sizeof( V_54 -> V_117 ) +
F_28 ( V_54 -> V_117 . V_119 ) ;
}
if ( V_151 ) {
F_19 ( V_8 , V_49 ,
L_24 ,
V_151 ) ;
V_142 = (struct V_141 * ) V_111 ;
V_142 -> V_117 . type = F_21 ( V_181 ) ;
V_142 -> V_117 . V_119 =
F_21 ( sizeof( V_142 -> V_151 ) ) ;
V_142 -> V_151 = F_21 ( ( V_91 ) V_151 ) ;
V_111 += sizeof( V_142 -> V_117 ) +
F_28 ( V_142 -> V_117 . V_119 ) ;
}
if ( F_36 ( V_5 -> V_8 -> V_182 ) &&
( V_5 -> V_8 -> V_60 & V_61 ||
V_5 -> V_8 -> V_60 & V_62 ) ) {
V_158 = (struct V_157 * ) V_111 ;
memset ( V_158 , 0 , sizeof( struct V_157 ) ) ;
V_158 -> V_117 . type = F_21 ( V_183 ) ;
V_158 -> V_117 . V_119 =
F_21 ( sizeof( struct V_184 ) ) ;
V_87 =
F_37 ( V_5 -> V_8 -> V_60 ) ;
F_38 ( V_5 , V_87 , & V_158 -> V_158 ) ;
V_111 += sizeof( struct V_157 ) ;
}
F_39 ( V_5 , V_185 , & V_111 ) ;
* V_139 =
(struct V_121 * ) V_111 ;
if ( V_67 && V_67 -> V_88 [ 0 ] . V_98 ) {
F_19 ( V_8 , V_49 ,
L_25 ) ;
for ( V_77 = 0 ;
V_77 < V_186 &&
V_67 -> V_88 [ V_77 ] . V_98 ;
V_77 ++ ) {
V_155 = V_67 -> V_88 [ V_77 ] . V_98 ;
V_69 [ V_77 ] . V_98 = V_155 ;
V_87 =
V_67 -> V_88 [ V_77 ] . V_87 ;
V_69 [ V_77 ] . V_87 = V_87 ;
V_153 = V_67 -> V_88 [ V_77 ] . V_153 ;
if ( V_153 == V_187 )
V_69 [ V_77 ] . V_95
|= ( V_96 |
V_97 ) ;
else
V_69 [ V_77 ] . V_95
&= ~ V_96 ;
V_69 [ V_77 ] . V_95
|= V_100 ;
if ( V_67 -> V_88 [ V_77 ] . V_89 ) {
V_154 = ( V_91 ) V_67 ->
V_88 [ V_77 ] . V_89 ;
} else {
if ( V_153 == V_187 )
V_154 = V_8 -> V_93 ;
else if ( * V_70 )
V_154 = V_8 -> V_101 ;
else
V_154 = V_8 -> V_94 ;
}
V_69 [ V_77 ] . V_188 =
F_21 ( V_154 ) ;
V_69 [ V_77 ] . V_90 =
F_21 ( V_154 ) ;
}
if ( ( V_77 == 1 ) &&
( V_67 -> V_88 [ 0 ] . V_98 ==
V_5 -> V_189 . V_190 . V_155 ) ) {
* V_140 = true ;
F_19 ( V_8 , V_49 ,
L_26 ) ;
}
V_152 = V_77 ;
} else {
F_19 ( V_8 , V_49 ,
L_27 ) ;
V_152 = F_20 ( V_5 , V_67 ,
V_69 ,
* V_70 ) ;
}
}
static void
F_40 ( struct V_51 * V_8 ,
struct V_191 * V_192 ,
T_2 V_193 , T_2 V_194 ,
struct V_191 * * V_195 )
{
struct V_191 * V_196 ;
T_2 V_197 ;
T_2 V_198 ;
T_2 V_199 ;
V_196 = V_192 ;
V_197 = V_193 ;
* V_195 = NULL ;
F_19 ( V_8 , V_49 ,
L_28 ,
V_193 ) ;
while ( V_197 >= sizeof( struct V_138 ) ) {
V_198 = F_28 ( V_196 -> V_117 . type ) ;
V_199 = F_28 ( V_196 -> V_117 . V_119 ) ;
if ( sizeof( V_192 -> V_117 ) + V_199 > V_197 ) {
F_19 ( V_8 , ERROR ,
L_29 ) ;
break;
}
if ( V_194 == V_198 ) {
switch ( V_198 ) {
case V_200 :
F_19 ( V_8 , V_49 ,
L_30
L_31 ,
V_199 ) ;
* V_195 = V_196 ;
break;
case V_201 :
F_19 ( V_8 , V_49 ,
L_32
L_33 ,
V_199 ) ;
* V_195 = V_196 ;
break;
default:
F_19 ( V_8 , ERROR ,
L_34 ,
V_198 ) ;
return;
}
}
if ( * V_195 )
break;
V_197 -= ( sizeof( V_192 -> V_117 ) + V_199 ) ;
V_196 =
(struct V_191 * ) ( V_196 -> V_36 +
V_199 ) ;
}
}
int F_41 ( struct V_51 * V_8 ,
struct V_6 * V_202 )
{
int V_34 = 0 ;
T_1 V_11 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
struct V_209 * V_210 ;
T_1 * V_211 ;
T_1 * V_212 ;
T_1 V_213 ;
V_91 V_214 ;
T_1 V_215 ;
T_1 V_216 ;
T_1 V_217 ;
T_2 V_218 ;
struct V_23 * V_219 ;
const T_1 V_220 [ 4 ] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_1 V_221 [ 4 ] = { 0x00 , 0x50 , 0xf2 , 0x02 } ;
V_217 = false ;
V_216 = 0 ;
V_211 = V_202 -> V_222 ;
V_218 = V_202 -> V_223 ;
while ( V_218 >= 2 ) {
V_11 = * V_211 ;
V_213 = * ( V_211 + 1 ) ;
V_214 = V_213 + sizeof( struct V_224 ) ;
if ( V_218 < V_214 ) {
F_19 ( V_8 , ERROR ,
L_35
L_36 ) ;
return - 1 ;
}
switch ( V_11 ) {
case V_225 :
V_202 -> V_45 . V_44 = V_213 ;
memcpy ( V_202 -> V_45 . V_45 , ( V_211 + 2 ) ,
V_213 ) ;
F_19 ( V_8 , V_49 ,
L_37 ,
V_202 -> V_45 . V_45 ) ;
break;
case V_118 :
memcpy ( V_202 -> V_226 , V_211 + 2 ,
V_213 ) ;
memcpy ( V_202 -> V_227 , V_211 + 2 ,
V_213 ) ;
V_216 = V_213 ;
V_217 = true ;
break;
case V_228 :
V_204 =
(struct V_203 * ) V_211 ;
memcpy ( & V_202 -> V_229 . V_204 ,
V_204 ,
sizeof( struct V_203 ) ) ;
break;
case V_230 :
V_206 =
(struct V_205 * ) V_211 ;
V_202 -> V_155 = V_206 -> V_231 ;
memcpy ( & V_202 -> V_229 . V_206 ,
V_206 ,
sizeof( struct V_205 ) ) ;
break;
case V_232 :
V_208 =
(struct V_207 * ) V_211 ;
memcpy ( & V_202 -> V_233 . V_208 ,
V_208 ,
sizeof( struct V_207 ) ) ;
break;
case V_234 :
V_210 =
(struct V_209 * )
V_211 ;
memcpy ( & V_202 -> V_233 . V_210 ,
V_210 ,
sizeof( struct V_209 ) ) ;
break;
case V_235 :
V_202 -> V_236 = * ( V_211 + 2 ) ;
break;
case V_237 :
V_202 -> V_238 = * ( V_211 + 2 ) ;
V_202 -> V_239 = true ;
break;
case V_240 :
V_202 -> V_59 = true ;
case V_241 :
case V_242 :
case V_243 :
V_202 -> V_239 = true ;
break;
case V_244 :
if ( V_217 ) {
if ( ( V_213 + V_216 ) >
V_110 )
V_215 =
( V_110 -
V_216 ) ;
else
V_215 = V_213 ;
V_212 = ( T_1 * ) V_202 -> V_226 ;
V_212 += V_216 ;
memcpy ( V_212 , V_211 + 2 , V_215 ) ;
V_212 = ( T_1 * ) V_202 -> V_227 ;
V_212 += V_216 ;
memcpy ( V_212 , V_211 + 2 , V_215 ) ;
}
break;
case V_39 :
V_219 = (struct V_23 * )
V_211 ;
if ( ! memcmp
( V_219 -> V_10 . V_26 , V_220 ,
sizeof( V_220 ) ) ) {
V_202 -> V_9 =
(struct V_23 * )
V_211 ;
V_202 -> V_245 = ( V_91 )
( V_211 - V_202 -> V_222 ) ;
} else if ( ! memcmp ( V_219 -> V_10 . V_26 , V_221 ,
sizeof( V_221 ) ) ) {
if ( V_214 ==
sizeof( struct V_246 ) ||
V_214 ==
sizeof( struct V_247 ) )
memcpy ( ( T_1 * ) & V_202 -> V_248 ,
V_211 , V_214 ) ;
}
break;
case V_35 :
V_202 -> V_12 =
(struct V_20 * ) V_211 ;
V_202 -> V_249 = ( V_91 ) ( V_211 -
V_202 -> V_222 ) ;
break;
case V_48 :
V_202 -> V_47 =
(struct V_20 * ) V_211 ;
V_202 -> V_250 = ( V_91 ) ( V_211 -
V_202 -> V_222 ) ;
break;
case V_183 :
V_202 -> V_63 = (struct V_184 * )
( V_211 +
sizeof( struct V_224 ) ) ;
V_202 -> V_251 = ( V_91 ) ( V_211 +
sizeof( struct V_224 ) -
V_202 -> V_222 ) ;
break;
case V_252 :
V_202 -> V_253 =
(struct V_254 * ) ( V_211 +
sizeof( struct V_224 ) ) ;
V_202 -> V_255 = ( V_91 ) ( V_211 +
sizeof( struct V_224 ) -
V_202 -> V_222 ) ;
break;
case V_256 :
V_202 -> V_257 = false ;
V_202 -> V_258 =
( void * ) ( V_211 +
sizeof( struct V_224 ) ) ;
V_202 -> V_259 =
( V_91 ) ( ( T_1 * ) V_202 -> V_258 -
V_202 -> V_222 ) ;
break;
case V_260 :
V_202 -> V_261 =
( void * ) ( V_211 +
sizeof( struct V_224 ) ) ;
V_202 -> V_262 =
( V_91 ) ( ( T_1 * ) V_202 -> V_261 -
V_202 -> V_222 ) ;
break;
case V_263 :
V_202 -> V_264 = V_211 ;
V_202 -> V_265 =
( V_91 ) ( V_211 - V_202 -> V_222 ) ;
break;
case V_266 :
V_202 -> V_267 = V_211 ;
V_202 -> V_268 =
( V_91 ) ( V_211 - V_202 -> V_222 ) ;
break;
case V_269 :
V_202 -> V_270 = ( void * ) V_211 ;
V_202 -> V_271 =
( V_91 ) ( ( T_1 * ) V_202 -> V_270 -
V_202 -> V_222 ) ;
break;
default:
break;
}
V_211 += V_213 + 2 ;
V_218 -= ( V_213 + 2 ) ;
}
return V_34 ;
}
static T_1
F_42 ( T_1 V_87 )
{
switch ( V_87 ) {
case V_272 :
return V_273 ;
case V_274 :
default:
return V_275 ;
}
}
int F_43 ( struct V_4 * V_5 ,
const struct V_66 * V_67 )
{
int V_34 ;
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_276 * V_277 ;
union V_278 * V_105 ;
struct V_121 * V_139 ;
struct V_68 * V_69 ;
T_1 V_70 ;
T_1 V_279 ;
T_1 V_120 ;
unsigned long V_85 ;
if ( V_8 -> V_280 ) {
F_19 ( V_8 , V_281 ,
L_38 ) ;
return - V_282 ;
}
if ( V_5 -> V_283 ) {
F_19 ( V_8 , V_281 ,
L_39 ) ;
return - V_282 ;
}
if ( V_8 -> V_284 || V_8 -> V_285 ) {
F_19 ( V_8 , ERROR ,
L_40 ) ;
return - V_286 ;
}
F_44 ( & V_8 -> V_287 , V_85 ) ;
V_8 -> V_280 = true ;
F_45 ( & V_8 -> V_287 , V_85 ) ;
V_105 = F_46 ( sizeof( union V_278 ) ,
V_288 ) ;
if ( ! V_105 ) {
V_34 = - V_289 ;
goto V_290;
}
V_69 = F_47 ( V_186 ,
sizeof( struct V_68 ) ,
V_288 ) ;
if ( ! V_69 ) {
F_48 ( V_105 ) ;
V_34 = - V_289 ;
goto V_290;
}
F_32 ( V_5 , V_67 , & V_105 -> V_291 ,
& V_139 , V_69 , & V_120 ,
& V_70 , & V_279 ) ;
V_34 = F_26 ( V_5 , V_120 , V_70 ,
& V_105 -> V_291 , V_139 ,
V_69 ) ;
if ( ! V_34 ) {
F_44 ( & V_8 -> V_292 , V_85 ) ;
if ( ! F_49 ( & V_8 -> V_293 ) ) {
V_277 = F_50 ( & V_8 -> V_293 ,
struct V_276 , V_294 ) ;
F_51 ( & V_277 -> V_294 ) ;
F_45 ( & V_8 -> V_292 ,
V_85 ) ;
F_52 ( V_8 , V_277 ,
true ) ;
F_53 ( V_8 -> V_295 , & V_8 -> V_296 ) ;
if ( ! V_5 -> V_115 ) {
F_19 ( V_8 , V_49 ,
L_41 ) ;
F_54 ( V_8 , V_277 ) ;
}
} else {
F_45 ( & V_8 -> V_292 ,
V_85 ) ;
}
}
F_48 ( V_105 ) ;
F_48 ( V_69 ) ;
V_290:
if ( V_34 ) {
F_44 ( & V_8 -> V_287 , V_85 ) ;
V_8 -> V_280 = false ;
F_45 ( & V_8 -> V_287 , V_85 ) ;
}
return V_34 ;
}
int F_55 ( struct V_297 * V_298 ,
struct V_104 * V_299 )
{
struct V_300 * V_301 = & V_298 -> V_302 . V_303 ;
V_301 -> V_54 = V_299 -> V_54 ;
memcpy ( V_301 -> V_166 , V_299 -> V_163 ,
sizeof( V_301 -> V_166 ) ) ;
memcpy ( V_301 -> V_304 , V_299 -> V_113 , V_299 -> V_114 ) ;
V_298 -> V_305 = F_21 ( V_136 ) ;
V_298 -> V_306 = F_21 ( ( V_91 ) ( sizeof( V_301 -> V_54 )
+ sizeof( V_301 -> V_166 )
+ V_299 -> V_114 + V_307 ) ) ;
return 0 ;
}
int F_56 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
int V_34 = - 1 ;
if ( ! V_7 )
return - 1 ;
if ( ( F_57 ( V_5 , ( T_1 ) V_7 -> V_308 ,
( V_91 ) V_7 -> V_155 , 0 ) ) ) {
switch ( V_5 -> V_54 ) {
case V_55 :
case V_309 :
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
static bool F_58 ( struct V_41 * V_45 )
{
int V_310 ;
for ( V_310 = 0 ; V_310 < V_45 -> V_44 ; V_310 ++ ) {
if ( V_45 -> V_45 [ V_310 ] )
return false ;
}
return true ;
}
static int F_59 ( struct V_4 * V_5 ,
struct V_311 * V_312 )
{
struct V_6 * V_7 ;
int V_34 ;
int V_313 ;
V_7 = F_46 ( sizeof( * V_7 ) , V_288 ) ;
if ( ! V_7 )
return - V_289 ;
V_34 = F_60 ( V_5 , V_312 , V_7 ) ;
if ( V_34 )
goto V_290;
if ( F_58 ( & V_7 -> V_45 ) ) {
F_19 ( V_5 -> V_8 , V_49 , L_43 ) ;
for ( V_313 = 0 ; V_313 < V_186 ; V_313 ++ ) {
if ( V_5 -> V_314 [ V_313 ] . V_98 ==
V_312 -> V_155 -> V_99 )
break;
if ( ! V_5 -> V_314 [ V_313 ] . V_98 ) {
V_5 -> V_314 [ V_313 ] . V_98 =
V_312 -> V_155 -> V_99 ;
V_5 -> V_314 [ V_313 ] . V_87 =
V_312 -> V_155 -> V_72 ;
V_5 -> V_314 [ V_313 ] . V_153 =
V_315 ;
break;
}
}
}
V_290:
F_48 ( V_7 ) ;
return 0 ;
}
static int F_61 ( struct V_4 * V_5 ,
struct V_311 * V_312 )
{
struct V_6 * V_7 ;
int V_34 ;
unsigned long V_85 ;
V_7 = F_46 ( sizeof( struct V_6 ) , V_288 ) ;
if ( ! V_7 )
return - V_289 ;
V_34 = F_60 ( V_5 , V_312 , V_7 ) ;
if ( V_34 )
goto V_290;
V_34 = F_56 ( V_5 , V_7 ) ;
if ( V_34 )
goto V_290;
F_44 ( & V_5 -> V_316 , V_85 ) ;
memcpy ( & V_5 -> V_189 . V_190 , V_7 ,
sizeof( V_5 -> V_189 . V_190 ) ) ;
F_62 ( V_5 ) ;
F_45 ( & V_5 -> V_316 , V_85 ) ;
V_290:
F_48 ( V_7 -> V_222 ) ;
F_48 ( V_7 ) ;
return 0 ;
}
static int
F_63 ( struct V_4 * V_5 , T_1 * * V_317 ,
T_2 * V_218 , T_4 V_318 , T_1 * V_87 ,
bool V_134 , T_3 V_319 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_320 * V_321 ;
struct V_311 * V_312 ;
T_1 V_166 [ V_165 ] ;
T_3 V_322 ;
const T_1 * V_323 ;
T_5 V_324 ;
V_91 V_155 = 0 ;
V_91 V_325 = 0 ;
T_2 V_326 ;
T_2 V_327 ;
V_91 V_328 ;
V_91 V_329 ;
T_1 * V_211 ;
T_4 V_330 ;
struct V_331 * V_332 ;
struct V_333 * V_334 ;
if ( * V_218 >= sizeof( V_325 ) ) {
V_325 = F_28 ( * ( V_335 * ) ( * V_317 ) ) ;
* V_218 -= sizeof( V_325 ) ;
* V_317 += sizeof( V_325 ) ;
}
if ( ! V_325 || V_325 > * V_218 ) {
* V_317 += * V_218 ;
* V_218 = 0 ;
return - V_286 ;
}
V_211 = * V_317 ;
* V_317 += V_325 ;
* V_218 -= V_325 ;
V_326 = V_325 ;
if ( V_326 < V_165 + sizeof( T_1 ) +
sizeof( struct V_331 ) ) {
F_19 ( V_8 , ERROR ,
L_44 ) ;
return - V_286 ;
}
memcpy ( V_166 , V_211 , V_165 ) ;
V_211 += V_165 ;
V_326 -= V_165 ;
if ( ! V_134 ) {
V_322 = ( T_3 ) * V_211 ;
V_322 = ( - V_322 ) * 100 ;
V_211 += sizeof( T_1 ) ;
V_326 -= sizeof( T_1 ) ;
F_19 ( V_8 , V_49 ,
L_45 , V_322 ) ;
} else {
V_322 = V_319 ;
}
V_332 = (struct V_331 * ) V_211 ;
V_211 += sizeof( * V_332 ) ;
V_326 -= sizeof( * V_332 ) ;
V_330 = F_64 ( V_332 -> V_330 ) ;
V_328 = F_28 ( V_332 -> V_328 ) ;
V_329 = F_28 ( V_332 -> V_329 ) ;
F_19 ( V_8 , V_49 ,
L_46 ,
V_329 ) ;
V_323 = V_211 ;
V_324 = V_326 ;
F_19 ( V_8 , V_49 ,
L_47 ,
V_326 ) ;
while ( V_326 >= sizeof( struct V_224 ) ) {
T_1 V_11 , V_213 ;
V_11 = * V_211 ;
V_213 = * ( V_211 + 1 ) ;
if ( V_326 < V_213 +
sizeof( struct V_224 ) ) {
F_19 ( V_8 , ERROR ,
L_48 , V_31 ) ;
return - V_286 ;
}
if ( V_11 == V_230 ) {
V_155 = * ( V_211 +
sizeof( struct V_224 ) ) ;
break;
}
V_211 += V_213 + sizeof( struct V_224 ) ;
V_326 -= V_213 +
sizeof( struct V_224 ) ;
}
if ( V_155 ) {
struct V_75 * V_336 ;
T_1 V_72 ;
if ( V_155 == V_5 -> V_130 ) {
F_19 ( V_8 , V_281 ,
L_49 ) ;
return 0 ;
}
V_72 = V_275 ;
if ( V_87 )
V_72 = F_42 ( * V_87 &
( F_65 ( 0 ) | F_65 ( 1 ) ) ) ;
V_321 = F_57 ( V_5 , V_72 , V_155 , 0 ) ;
V_327 = V_321 ? V_321 -> V_327 : 0 ;
V_336 = F_66 ( V_5 -> V_80 . V_81 , V_327 ) ;
if ( V_336 && ! ( V_336 -> V_85 & V_86 ) ) {
V_312 = F_67 ( V_5 -> V_80 . V_81 ,
V_336 , V_337 ,
V_166 , V_330 ,
V_329 , V_328 ,
V_323 , V_324 , V_322 , V_288 ) ;
if ( V_312 ) {
V_334 = (struct V_333 * ) V_312 -> V_5 ;
V_334 -> V_72 = V_72 ;
V_334 -> V_318 = V_318 ;
if ( V_5 -> V_53 &&
! memcmp ( V_166 , V_5 -> V_189 .
V_190 . V_338 ,
V_165 ) )
F_61 ( V_5 ,
V_312 ) ;
F_68 ( V_5 -> V_80 . V_81 , V_312 ) ;
}
if ( ( V_336 -> V_85 & V_339 ) ||
( V_336 -> V_85 & V_92 ) ) {
F_19 ( V_8 , V_49 ,
L_50 ,
V_155 ) ;
F_59 ( V_5 , V_312 ) ;
}
}
} else {
F_19 ( V_8 , V_281 , L_51 ) ;
}
return 0 ;
}
static void F_69 ( struct V_4 * V_5 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
V_8 -> V_340 = 0 ;
if ( V_8 -> V_341 -> V_342 ) {
V_8 -> V_343 . V_344 = 0 ;
if ( ! V_5 -> V_115 ) {
F_19 ( V_8 , V_49 ,
L_52 ) ;
F_70 ( V_8 , V_8 -> V_341 ) ;
}
}
}
static int
F_71 ( struct V_4 * V_5 )
{
int V_34 ;
struct V_51 * V_8 = V_5 -> V_8 ;
T_1 V_345 = 0 ;
struct V_66 * V_346 ;
if ( V_8 -> V_347 || ! V_5 -> V_115 ||
V_5 -> V_348 ) {
V_8 -> V_347 = false ;
return 0 ;
}
if ( ! V_5 -> V_314 [ 0 ] . V_98 ) {
F_19 ( V_8 , V_49 , L_53 ) ;
return 0 ;
}
V_346 = F_46 ( sizeof( * V_346 ) , V_288 ) ;
if ( ! V_346 )
return - V_289 ;
memset ( V_346 , 0 , sizeof( * V_346 ) ) ;
for ( V_345 = 0 ; V_345 < V_186 ; V_345 ++ ) {
if ( ! V_5 -> V_314 [ V_345 ] . V_98 )
break;
memcpy ( & V_346 -> V_88 [ V_345 ] ,
& V_5 -> V_314 [ V_345 ] ,
sizeof( struct V_349 ) ) ;
}
V_8 -> V_347 = true ;
F_35 ( V_346 -> V_176 , V_5 -> V_176 ) ;
V_346 -> V_167 = V_5 -> V_115 -> V_350 ;
V_346 -> V_168 = V_5 -> V_115 -> V_351 ;
V_34 = F_43 ( V_5 , V_346 ) ;
F_48 ( V_346 ) ;
memset ( & V_5 -> V_314 , 0 , sizeof( V_5 -> V_314 ) ) ;
if ( V_34 ) {
F_72 ( V_5 -> V_8 -> V_352 , L_54 , V_34 ) ;
return V_34 ;
}
return 0 ;
}
static void F_73 ( struct V_4 * V_5 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_276 * V_277 ;
unsigned long V_85 ;
F_44 ( & V_8 -> V_292 , V_85 ) ;
if ( F_49 ( & V_8 -> V_293 ) ) {
F_45 ( & V_8 -> V_292 , V_85 ) ;
F_44 ( & V_8 -> V_287 , V_85 ) ;
V_8 -> V_280 = false ;
F_45 ( & V_8 -> V_287 , V_85 ) ;
F_71 ( V_5 ) ;
if ( ! V_8 -> V_134 )
F_69 ( V_5 ) ;
if ( V_5 -> V_115 ) {
struct V_353 V_354 = {
. V_355 = false ,
} ;
F_19 ( V_8 , V_49 ,
L_55 ) ;
F_74 ( V_5 -> V_115 , & V_354 ) ;
V_5 -> V_115 = NULL ;
V_5 -> V_348 = false ;
} else {
V_5 -> V_348 = false ;
F_19 ( V_8 , V_49 ,
L_56 ) ;
}
} else if ( ( V_5 -> V_348 && ! V_5 -> V_115 ) ||
V_5 -> V_283 ) {
F_45 ( & V_8 -> V_292 , V_85 ) ;
F_31 ( V_8 ) ;
F_44 ( & V_8 -> V_287 , V_85 ) ;
V_8 -> V_280 = false ;
F_45 ( & V_8 -> V_287 , V_85 ) ;
if ( ! V_8 -> V_347 ) {
if ( V_5 -> V_115 ) {
struct V_353 V_354 = {
. V_355 = true ,
} ;
F_19 ( V_8 , V_49 ,
L_57 ) ;
F_74 ( V_5 -> V_115 , & V_354 ) ;
V_5 -> V_115 = NULL ;
V_5 -> V_348 = false ;
} else {
V_5 -> V_348 = false ;
F_19 ( V_8 , V_49 ,
L_56 ) ;
}
}
} else {
V_277 = F_50 ( & V_8 -> V_293 ,
struct V_276 , V_294 ) ;
F_51 ( & V_277 -> V_294 ) ;
F_45 ( & V_8 -> V_292 , V_85 ) ;
F_52 ( V_8 , V_277 , true ) ;
}
return;
}
void F_75 ( struct V_51 * V_8 )
{
struct V_4 * V_5 ;
unsigned long V_356 ;
int V_78 ;
F_31 ( V_8 ) ;
if ( V_8 -> V_280 ) {
F_44 ( & V_8 -> V_287 , V_356 ) ;
V_8 -> V_280 = false ;
F_45 ( & V_8 -> V_287 , V_356 ) ;
for ( V_78 = 0 ; V_78 < V_8 -> V_357 ; V_78 ++ ) {
V_5 = V_8 -> V_5 [ V_78 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_115 ) {
struct V_353 V_354 = {
. V_355 = true ,
} ;
F_19 ( V_8 , V_49 ,
L_57 ) ;
F_74 ( V_5 -> V_115 , & V_354 ) ;
V_5 -> V_115 = NULL ;
V_5 -> V_348 = false ;
}
}
}
}
int F_76 ( struct V_4 * V_5 ,
struct V_297 * V_358 )
{
int V_34 = 0 ;
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_359 * V_360 ;
struct V_191 * V_195 ;
struct V_361 * V_362 ;
T_1 * V_317 ;
T_2 V_363 ;
T_2 V_218 ;
T_2 V_310 ;
T_2 V_193 ;
struct V_364 * V_365 ;
struct V_366 * V_367 ;
T_1 V_368 ;
T_6 V_318 = 0 ;
T_1 * V_87 ;
struct V_369 * V_370 ;
struct V_371 * V_372 = NULL ;
V_368 = ( F_28 ( V_358 -> V_305 )
== V_373 ) ;
if ( V_368 )
V_360 = & V_358 -> V_302 . V_374 . V_375 ;
else
V_360 = & V_358 -> V_302 . V_375 ;
if ( V_360 -> V_376 > V_377 ) {
F_19 ( V_8 , ERROR ,
L_58 ,
V_360 -> V_376 ) ;
V_34 = - 1 ;
goto V_378;
}
F_27 ( V_5 ) ;
V_218 = F_28 ( V_360 -> V_379 ) ;
F_19 ( V_8 , V_49 ,
L_59 ,
V_218 ) ;
V_363 = F_28 ( V_358 -> V_306 ) ;
F_19 ( V_8 , V_49 ,
L_60 ,
V_360 -> V_376 ) ;
V_317 = V_360 -> V_380 ;
V_193 = V_363 - ( V_218
+ sizeof( V_360 -> V_379 )
+ sizeof( V_360 -> V_376 )
+ V_307 ) ;
V_195 = (struct V_191 * ) ( V_360 ->
V_380 +
V_218 ) ;
F_40 ( V_8 , V_195 , V_193 ,
V_200 ,
(struct V_191 * * )
& V_362 ) ;
F_40 ( V_8 , V_195 , V_193 ,
V_201 ,
(struct V_191 * * )
& V_365 ) ;
#ifdef F_77
if ( V_5 -> V_80 . V_81 -> V_381 )
V_372 = V_5 -> V_80 . V_81 -> V_381 -> V_372 ;
#endif
if ( V_372 ) {
V_8 -> V_382 =
F_46 ( sizeof( struct V_369 ) +
sizeof( struct V_369 * ) *
V_360 -> V_376 , V_383 ) ;
if ( V_8 -> V_382 )
V_8 -> V_382 -> V_384 = V_360 -> V_376 ;
}
for ( V_310 = 0 ; V_310 < V_360 -> V_376 && V_218 ; V_310 ++ ) {
if ( V_362 )
memcpy ( & V_318 , & V_362 -> V_385 [ V_310 * V_386 ] ,
sizeof( V_318 ) ) ;
if ( V_365 ) {
V_367 = & V_365 -> V_387 [ V_310 ] ;
V_87 = & V_367 -> V_87 ;
} else {
V_87 = NULL ;
}
if ( V_365 && V_8 -> V_382 ) {
V_8 -> V_382 -> V_388 [ V_310 ] =
F_46 ( sizeof( * V_370 ) + sizeof( T_2 ) ,
V_383 ) ;
V_370 = V_8 -> V_382 -> V_388 [ V_310 ] ;
if ( V_370 ) {
V_370 -> V_83 = 1 ;
V_370 -> V_84 [ 0 ] = V_367 -> V_98 ;
}
}
V_34 = F_63 ( V_5 , & V_317 ,
& V_218 ,
F_64 ( V_318 ) ,
V_87 , false , 0 ) ;
if ( V_34 )
goto V_378;
}
V_378:
F_73 ( V_5 ) ;
return V_34 ;
}
int F_78 ( struct V_4 * V_5 ,
struct V_297 * V_298 ,
void * V_389 )
{
struct V_390 * V_134 = & V_298 -> V_302 . V_134 ;
struct V_104 * V_299 = V_389 ;
memcpy ( V_134 -> V_304 , V_299 -> V_113 , V_299 -> V_114 ) ;
V_298 -> V_305 = F_21 ( V_135 ) ;
V_298 -> V_306 = F_21 ( ( V_91 ) ( sizeof( V_134 -> V_391 )
+ V_299 -> V_114 + V_307 ) ) ;
return 0 ;
}
int F_79 ( struct V_4 * V_5 ,
struct V_297 * V_298 ,
void * V_389 )
{
struct V_392 * V_393 =
& V_298 -> V_302 . V_394 ;
struct V_102 * V_103 = V_389 ;
T_1 * V_111 = V_393 -> V_192 ;
T_1 V_151 ;
T_2 V_44 , V_77 , V_153 , V_154 , V_152 ;
int V_78 ;
struct V_141 * V_142 ;
struct V_395 * V_396 ;
struct V_397 * V_398 ;
struct V_399 * V_400 ;
struct V_147 * V_148 ;
struct V_121 * V_401 ;
struct V_68 * V_402 ;
V_298 -> V_305 = F_21 ( V_403 ) ;
V_298 -> V_306 = F_21 ( sizeof( * V_393 ) + V_307 ) ;
V_393 -> V_404 = F_21 ( V_103 -> V_404 ) ;
V_393 -> V_405 = V_103 -> V_405 ;
V_393 -> V_406 = V_103 -> V_406 ;
V_393 -> V_407 =
F_80 ( V_103 -> V_407 ) ;
V_393 -> V_408 =
F_80 ( V_103 -> V_408 ) ;
if ( ! V_393 -> V_405 )
return 0 ;
V_393 -> V_409 = V_103 -> V_409 ;
V_151 = ( V_103 -> V_151 ? V_103 ->
V_151 : V_5 -> V_8 -> V_162 ) ;
if ( V_151 ) {
V_142 = (struct V_141 * ) V_111 ;
V_142 -> V_117 . type = F_21 ( V_181 ) ;
V_142 -> V_117 . V_119 =
F_21 ( sizeof( V_142 -> V_151 ) ) ;
V_142 -> V_151 = F_21 ( ( V_91 ) V_151 ) ;
V_111 += sizeof( V_142 -> V_117 ) +
F_28 ( V_142 -> V_117 . V_119 ) ;
}
if ( V_103 -> V_410 ) {
V_396 =
(struct V_395 * ) V_111 ;
V_396 -> V_117 . type =
F_21 ( V_411 ) ;
V_396 -> V_117 . V_119 =
F_21 ( sizeof( V_396 -> V_410 ) ) ;
V_396 -> V_410 =
F_21 ( V_103 -> V_410 ) ;
V_111 += sizeof( V_396 -> V_117 ) +
F_28 ( V_396 -> V_117 . V_119 ) ;
}
if ( V_103 -> V_412 ) {
V_398 =
(struct V_397 * ) V_111 ;
V_398 -> V_117 . type =
F_21 ( V_413 ) ;
V_398 -> V_117 . V_119 =
F_21 ( sizeof( V_398 -> V_412 ) ) ;
V_398 -> V_412 =
F_21 ( V_103 -> V_412 ) ;
V_111 += sizeof( V_398 -> V_117 ) +
F_28 ( V_398 -> V_117 . V_119 ) ;
}
for ( V_78 = 0 ; V_78 < V_103 -> V_167 ; V_78 ++ ) {
V_44 = V_103 -> V_168 [ V_78 ] . V_45 . V_44 ;
V_148 =
(struct V_147 * ) V_111 ;
V_148 -> V_117 . type =
F_21 ( V_169 ) ;
V_148 -> V_117 . V_119 = F_21 (
( V_91 ) ( V_44 + sizeof( V_148 ->
V_170 ) ) ) ;
if ( V_44 )
V_148 -> V_170 = 0 ;
else
V_148 -> V_170 =
V_171 ;
memcpy ( V_148 -> V_45 ,
V_103 -> V_168 [ V_78 ] . V_45 . V_45 , V_44 ) ;
V_111 += ( sizeof( V_148 -> V_117 )
+ F_28 ( V_148 -> V_117 . V_119 ) ) ;
}
V_401 = (struct V_121 * ) V_111 ;
if ( V_103 -> V_88 [ 0 ] . V_98 ) {
F_81 ( V_5 -> V_8 -> V_352 , L_61 ) ;
V_401 -> V_117 . type = F_21 ( V_129 ) ;
for ( V_77 = 0 ;
V_77 < V_414 &&
V_103 -> V_88 [ V_77 ] . V_98 ;
V_77 ++ ) {
V_402 = V_401 -> V_131 + V_77 ;
F_29 ( & V_401 -> V_117 . V_119 ,
sizeof( V_401 -> V_131 ) ) ;
V_402 -> V_98 =
V_103 -> V_88 [ V_77 ] . V_98 ;
V_402 -> V_87 =
V_103 -> V_88 [ V_77 ] . V_87 ;
V_153 =
V_103 -> V_88 [ V_77 ] . V_153 ;
if ( V_153 == V_187 )
V_402 -> V_95
|= V_96 ;
else
V_402 -> V_95
&= ~ V_96 ;
if ( V_103 -> V_88 [ V_77 ] . V_89 ) {
V_154 = ( V_91 ) V_103 ->
V_88 [ V_77 ] . V_89 ;
} else {
V_154 = ( V_153 ==
V_187 ) ?
V_5 -> V_8 -> V_93 :
V_5 -> V_8 -> V_101 ;
}
V_402 -> V_188 = F_21 ( V_154 ) ;
V_402 -> V_90 = F_21 ( V_154 ) ;
}
} else {
F_81 ( V_5 -> V_8 -> V_352 ,
L_62 ) ;
V_152 =
F_22 ( V_5 , V_103 ,
V_401 ->
V_131 ) ;
F_29 ( & V_401 -> V_117 . V_119 ,
V_152 *
sizeof( V_401 -> V_131 [ 0 ] ) ) ;
}
V_111 += ( sizeof( V_401 -> V_117 )
+ F_28 ( V_401 -> V_117 . V_119 ) ) ;
if ( V_103 -> V_415 ) {
V_400 =
(struct V_399 * ) V_111 ;
V_400 -> V_117 . type =
F_21 ( V_416 ) ;
V_400 -> V_117 . V_119 =
F_21 ( sizeof( V_400 -> V_415 ) ) ;
V_400 -> V_415 =
F_21 ( V_103 -> V_415 ) ;
V_111 += sizeof( V_400 -> V_117 ) +
F_28 ( V_400 -> V_117 . V_119 ) ;
}
F_39 ( V_5 , V_417 , & V_111 ) ;
F_29 ( & V_298 -> V_306 , V_111 - V_393 -> V_192 ) ;
return 0 ;
}
int F_82 ( struct V_4 * V_5 )
{
struct V_102 * V_418 ;
if ( ! V_5 -> V_419 ) {
F_81 ( V_5 -> V_8 -> V_352 , L_63 ) ;
return 0 ;
}
V_418 = F_46 ( sizeof( * V_418 ) , V_288 ) ;
if ( ! V_418 )
return - V_289 ;
V_418 -> V_406 = V_420 ;
V_418 -> V_404 = V_421 ;
V_418 -> V_405 = false ;
if ( F_30 ( V_5 , V_403 ,
V_137 , 0 , V_418 , true ) ) {
F_48 ( V_418 ) ;
return - V_286 ;
}
F_48 ( V_418 ) ;
V_5 -> V_419 = false ;
return 0 ;
}
static void
F_83 ( struct V_4 * V_5 ,
struct V_422 * V_423 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
T_1 V_78 , V_424 ;
struct V_425 * V_426 ;
struct V_427 V_428 ;
V_426 = ( void * ) ( ( T_1 * ) V_423 +
sizeof( struct V_138 ) ) ;
V_424 = F_28 ( V_423 -> V_117 . V_119 ) /
sizeof( struct V_427 ) ;
for ( V_78 = 0 ; V_78 < V_424 ; V_78 ++ ) {
V_428 . V_152 = V_426 -> V_152 ;
V_428 . V_429 = V_426 -> V_429 ;
V_428 . V_85 = V_426 -> V_85 ;
V_428 . V_430 = V_426 -> V_430 ;
V_428 . V_431 = F_28 ( V_426 -> V_431 ) ;
V_428 . V_432 =
F_28 ( V_426 -> V_432 ) ;
V_428 . V_433 =
F_28 ( V_426 -> V_433 ) ;
F_19 ( V_8 , V_49 ,
L_64 ,
V_428 . V_152 ,
V_428 . V_430 ,
V_428 . V_431 ,
V_428 . V_432 ,
V_428 . V_433 ) ;
memcpy ( & V_8 -> V_428 [ V_8 -> V_340 ++ ] , & V_428 ,
sizeof( struct V_427 ) ) ;
V_426 ++ ;
}
}
int F_84 ( struct V_4 * V_5 ,
struct V_297 * V_358 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
struct V_390 * V_434 ;
struct V_138 * V_192 ;
struct V_422 * V_423 ;
V_91 V_435 , type , V_119 ;
struct V_297 * V_436 ;
struct V_276 * V_277 ;
unsigned long V_356 , V_437 ;
bool V_438 = false ;
F_19 ( V_8 , V_49 , L_65 ) ;
V_434 = & V_358 -> V_302 . V_134 ;
V_192 = ( void * ) V_434 -> V_304 ;
V_435 = F_28 ( V_358 -> V_306 ) - ( sizeof( * V_434 ) + V_307
- 1 ) ;
while ( V_435 >= sizeof( struct V_138 ) ) {
type = F_28 ( V_192 -> type ) ;
V_119 = F_28 ( V_192 -> V_119 ) ;
if ( V_435 < ( sizeof( struct V_138 ) + V_119 ) ) {
F_19 ( V_8 , ERROR ,
L_66 ) ;
break;
}
switch ( type ) {
case V_439 :
V_423 = ( void * ) V_192 ;
F_83 ( V_5 , V_423 ) ;
break;
default:
break;
}
V_435 -= V_119 + sizeof( struct V_138 ) ;
V_192 = ( void * ) ( ( T_1 * ) V_192 + V_119 +
sizeof( struct V_138 ) ) ;
}
F_44 ( & V_8 -> V_440 , V_356 ) ;
F_44 ( & V_8 -> V_292 , V_437 ) ;
if ( F_49 ( & V_8 -> V_293 ) ) {
V_438 = true ;
F_85 (cmd_node, &adapter->cmd_pending_q, list) {
V_436 = ( void * ) V_277 -> V_441 -> V_36 ;
if ( F_28 ( V_436 -> V_305 ) ==
V_135 ) {
F_19 ( V_8 , V_49 ,
L_67 ) ;
V_438 = false ;
break;
}
}
}
F_45 ( & V_8 -> V_292 , V_437 ) ;
F_45 ( & V_8 -> V_440 , V_356 ) ;
if ( V_438 )
F_69 ( V_5 ) ;
return 0 ;
}
int F_86 ( struct V_4 * V_5 ,
void * V_442 )
{
int V_34 = 0 ;
struct V_51 * V_8 = V_5 -> V_8 ;
T_1 * V_317 ;
T_2 V_218 , V_443 , V_310 ;
V_91 type , V_119 ;
struct V_191 * V_192 ;
struct V_444 * V_445 ;
struct V_446 * V_447 ;
T_1 * V_87 ;
T_4 V_318 = 0 ;
T_3 V_322 = 0 ;
struct V_448 * V_449 = V_442 ;
T_1 V_450 = V_449 -> V_450 ;
T_1 * V_375 = V_442 + sizeof( struct V_448 ) ;
V_91 V_363 = F_28 ( V_449 -> V_451 ) ;
if ( V_450 > V_377 ) {
F_19 ( V_8 , ERROR ,
L_68 ,
V_450 ) ;
V_34 = - 1 ;
goto V_378;
}
V_218 = V_363 ;
F_19 ( V_8 , V_49 ,
L_69 ,
V_363 , V_450 ) ;
F_87 ( V_8 , V_452 , L_70 , V_442 ,
V_363 +
sizeof( struct V_448 ) ) ;
V_192 = (struct V_191 * ) V_375 ;
for ( V_310 = 0 ; V_310 < V_450 && V_218 ; V_310 ++ ) {
type = F_28 ( V_192 -> V_117 . type ) ;
V_119 = F_28 ( V_192 -> V_117 . V_119 ) ;
if ( V_218 < sizeof( struct V_138 ) + V_119 ) {
F_19 ( V_8 , ERROR ,
L_71 ) ;
break;
}
V_445 = NULL ;
V_447 = NULL ;
V_443 = V_218 ;
if ( type != V_453 )
break;
V_317 = ( T_1 * ) V_192 ;
V_445 = (struct V_444 * ) V_192 ;
V_192 = (struct V_191 * ) ( V_192 -> V_36 + V_119 ) ;
V_443 -=
( V_119 + sizeof( struct V_138 ) ) ;
while ( V_443 >=
sizeof( struct V_138 ) &&
F_28 ( V_192 -> V_117 . type ) != V_453 ) {
type = F_28 ( V_192 -> V_117 . type ) ;
V_119 = F_28 ( V_192 -> V_117 . V_119 ) ;
if ( V_443 <
sizeof( struct V_138 ) + V_119 ) {
F_19 ( V_8 , ERROR ,
L_72
L_73 ) ;
V_445 = NULL ;
V_443 = 0 ;
continue;
}
switch ( type ) {
case V_454 :
V_447 =
(struct V_446 * ) V_192 ;
if ( V_119 !=
sizeof( struct V_446 ) -
sizeof( struct V_138 ) ) {
V_443 = 0 ;
continue;
}
break;
default:
break;
}
V_192 = (struct V_191 * ) ( V_192 -> V_36 + V_119 ) ;
V_218 -=
( V_119 + sizeof( struct V_138 ) ) ;
V_443 -=
( V_119 + sizeof( struct V_138 ) ) ;
}
if ( ! V_445 )
break;
V_317 += sizeof( V_91 ) ;
V_218 -= sizeof( V_91 ) ;
if ( V_447 ) {
V_322 = ( T_3 ) ( V_455 ) ( F_28 ( V_447 -> V_322 ) ) ;
V_322 *= 100 ;
F_19 ( V_8 , V_49 ,
L_45 , V_322 ) ;
V_318 = F_64 ( V_447 -> V_456 ) ;
V_87 = & V_447 -> V_87 ;
} else {
V_87 = NULL ;
}
V_34 = F_63 ( V_5 , & V_317 ,
& V_218 , V_318 ,
V_87 , true , V_322 ) ;
if ( V_34 )
goto V_378;
}
V_378:
if ( ! V_449 -> V_457 )
F_73 ( V_5 ) ;
return V_34 ;
}
int F_88 ( struct V_297 * V_298 )
{
struct V_458 * V_459 =
& V_298 -> V_302 . V_460 ;
V_298 -> V_305 = F_21 ( V_373 ) ;
V_298 -> V_306 = F_21 ( sizeof( struct V_458 )
+ V_307 ) ;
V_459 -> V_461 = 1 ;
return 0 ;
}
void
F_89 ( struct V_4 * V_5 ,
struct V_276 * V_277 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
unsigned long V_85 ;
V_277 -> V_342 = true ;
V_277 -> V_462 = & V_8 -> V_463 ;
F_44 ( & V_8 -> V_292 , V_85 ) ;
F_90 ( & V_277 -> V_294 , & V_8 -> V_293 ) ;
F_45 ( & V_8 -> V_292 , V_85 ) ;
}
static int F_91 ( struct V_4 * V_5 ,
struct V_41 * V_464 )
{
struct V_51 * V_8 = V_5 -> V_8 ;
int V_34 ;
struct V_66 * V_299 ;
if ( V_8 -> V_280 ) {
F_19 ( V_8 , V_281 ,
L_38 ) ;
return - V_282 ;
}
if ( V_5 -> V_283 ) {
F_19 ( V_8 , V_281 ,
L_39 ) ;
return - V_282 ;
}
V_299 = F_46 ( sizeof( struct V_66 ) , V_288 ) ;
if ( ! V_299 )
return - V_289 ;
F_35 ( V_299 -> V_176 , V_5 -> V_176 ) ;
V_299 -> V_168 = V_464 ;
V_299 -> V_167 = 1 ;
V_34 = F_43 ( V_5 , V_299 ) ;
F_48 ( V_299 ) ;
return V_34 ;
}
int F_92 ( struct V_4 * V_5 ,
struct V_41 * V_464 )
{
int V_34 ;
if ( F_93 ( & V_5 -> V_465 ) ) {
F_19 ( V_5 -> V_8 , ERROR ,
L_74 ,
V_31 ) ;
return - 1 ;
}
V_5 -> V_8 -> V_463 = false ;
if ( V_464 && V_464 -> V_44 != 0 )
V_34 = F_91 ( V_5 , V_464 ) ;
else
V_34 = F_43 ( V_5 , NULL ) ;
F_94 ( & V_5 -> V_465 ) ;
return V_34 ;
}
int
F_39 ( struct V_4 * V_5 ,
V_91 V_466 , T_1 * * V_467 )
{
int V_345 , V_468 = 0 ;
struct V_469 * V_470 ;
if ( ! V_467 )
return 0 ;
if ( ! ( * V_467 ) )
return 0 ;
for ( V_345 = 0 ; V_345 < V_471 ; V_345 ++ ) {
if ( V_5 -> V_472 [ V_345 ] . V_473 & V_466 ) {
V_470 =
(struct V_469 * )
* V_467 ;
V_470 -> V_117 . type =
F_21 ( V_474 ) ;
V_470 -> V_117 . V_119 =
F_21 ( ( ( ( V_91 ) V_5 -> V_472 [ V_345 ] . V_21 [ 1 ] )
& 0x00FF ) + 2 ) ;
memcpy ( V_470 -> V_21 , V_5 -> V_472 [ V_345 ] . V_21 ,
F_28 ( V_470 -> V_117 . V_119 ) ) ;
* V_467 += F_28 ( V_470 -> V_117 . V_119 ) +
sizeof( struct V_138 ) ;
V_468 += F_28 ( V_470 -> V_117 . V_119 ) +
sizeof( struct V_138 ) ;
}
}
return V_468 ;
}
void
F_62 ( struct V_4 * V_5 )
{
struct V_6 * V_475 =
& V_5 -> V_189 . V_190 ;
if ( ! V_475 -> V_223 )
return;
if ( ! V_5 -> V_476 ||
V_5 -> V_477 != V_475 -> V_223 ) {
V_5 -> V_477 = V_475 -> V_223 ;
F_48 ( V_5 -> V_476 ) ;
V_5 -> V_476 = F_95 ( V_475 -> V_223 ,
V_383 ) ;
if ( ! V_5 -> V_476 )
return;
}
memcpy ( V_5 -> V_476 , V_475 -> V_222 ,
V_475 -> V_223 ) ;
F_19 ( V_5 -> V_8 , V_49 ,
L_75 ,
V_5 -> V_477 ) ;
V_475 -> V_222 = V_5 -> V_476 ;
if ( V_475 -> V_9 )
V_475 -> V_9 =
(struct V_23 * )
( V_475 -> V_222 +
V_475 -> V_245 ) ;
if ( V_475 -> V_12 )
V_475 -> V_12 = (struct V_20 * )
( V_475 -> V_222 +
V_475 -> V_249 ) ;
if ( V_475 -> V_63 )
V_475 -> V_63 = (struct V_184 * )
( V_475 -> V_222 +
V_475 -> V_251 ) ;
if ( V_475 -> V_253 )
V_475 -> V_253 = (struct V_254 * )
( V_475 -> V_222 +
V_475 -> V_255 ) ;
if ( V_475 -> V_258 )
V_475 -> V_258 = ( void * ) ( V_475 -> V_222 +
V_475 -> V_259 ) ;
if ( V_475 -> V_261 )
V_475 -> V_261 = ( void * ) ( V_475 -> V_222 +
V_475 -> V_262 ) ;
if ( V_475 -> V_264 )
V_475 -> V_264 =
( V_475 -> V_222 + V_475 -> V_265 ) ;
if ( V_475 -> V_267 )
V_475 -> V_267 = V_475 -> V_222 +
V_475 -> V_268 ;
if ( V_475 -> V_270 )
V_475 -> V_270 = ( void * ) ( V_475 -> V_222 +
V_475 -> V_271 ) ;
}
void
F_96 ( struct V_4 * V_5 )
{
F_48 ( V_5 -> V_476 ) ;
V_5 -> V_476 = NULL ;
}
