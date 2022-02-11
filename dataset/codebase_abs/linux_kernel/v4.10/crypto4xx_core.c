static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
union V_5 V_6 ;
union V_7 V_8 ;
union V_9 V_10 ;
T_1 V_11 ;
union V_12 V_13 ;
T_1 V_14 ;
F_2 ( V_15 , V_2 -> V_16 + V_17 ) ;
V_13 . V_18 = 0 ;
V_13 . V_19 . V_20 = 1 ;
V_13 . V_19 . V_21 = 0 ;
V_13 . V_19 . V_22 = 1 ;
V_13 . V_19 . V_23 = 1 ;
V_13 . V_19 . V_24 = 1 ;
V_13 . V_19 . V_25 = 1 ;
V_13 . V_19 . V_26 = 1 ;
V_13 . V_19 . V_27 = 1 ;
F_2 ( V_13 . V_18 , V_2 -> V_16 + V_28 ) ;
V_13 . V_19 . V_29 = 0 ;
V_13 . V_19 . V_25 = 0 ;
V_13 . V_19 . V_26 = 0 ;
V_13 . V_19 . V_27 = 0 ;
V_13 . V_19 . V_30 = 0 ;
F_2 ( V_13 . V_18 , V_2 -> V_16 + V_28 ) ;
F_2 ( V_2 -> V_31 , V_2 -> V_16 + V_32 ) ;
F_2 ( V_2 -> V_31 , V_2 -> V_16 + V_33 ) ;
F_2 ( V_34 , V_2 -> V_16 + V_35 ) ;
F_3 ( & V_11 , sizeof( V_11 ) ) ;
F_2 ( V_11 , V_2 -> V_16 + V_36 ) ;
F_3 ( & V_11 , sizeof( V_11 ) ) ;
F_2 ( V_11 , V_2 -> V_16 + V_37 ) ;
V_4 . V_18 = 0 ;
V_4 . V_19 . V_38 = V_39 ;
V_4 . V_19 . V_4 = V_40 ;
F_2 ( V_4 . V_18 , V_2 -> V_16 + V_41 ) ;
V_6 . V_18 = 0 ;
F_2 ( V_6 . V_18 , V_2 -> V_16 + V_42 ) ;
V_14 = F_4 ( V_2 -> V_16 + V_43 ) ;
V_14 |= V_44 ;
F_2 ( V_14 , V_2 -> V_16 + V_43 ) ;
F_2 ( V_2 -> V_45 , V_2 -> V_16 + V_46 ) ;
F_2 ( V_2 -> V_47 , V_2 -> V_16 + V_48 ) ;
V_8 . V_18 = 0 ;
V_8 . V_19 . V_49 = V_50 ;
V_8 . V_19 . V_51 = V_52 ;
F_2 ( V_8 . V_18 , V_2 -> V_16 + V_53 ) ;
F_2 ( V_54 , V_2 -> V_16 + V_55 ) ;
V_10 . V_18 = 0 ;
V_10 . V_19 . V_56 = V_57 ;
V_10 . V_19 . V_58 = V_59 ;
F_2 ( V_10 . V_18 , V_2 -> V_16 + V_60 ) ;
F_2 ( 0 , V_2 -> V_16 + V_61 ) ;
F_2 ( 0 , V_2 -> V_16 + V_62 ) ;
F_2 ( 0 , V_2 -> V_16 + V_63 ) ;
F_2 ( 0 , V_2 -> V_16 + V_64 ) ;
F_2 ( 0 , V_2 -> V_16 + V_65 ) ;
F_2 ( 0 , V_2 -> V_16 + V_66 ) ;
F_2 ( 0 , V_2 -> V_16 + V_67 ) ;
V_13 . V_19 . V_29 = 1 ;
V_13 . V_19 . V_25 = 0 ;
V_13 . V_19 . V_26 = 0 ;
V_13 . V_19 . V_27 = 0 ;
V_13 . V_19 . V_30 = 0 ;
F_2 ( V_13 . V_18 , V_2 -> V_16 + V_28 ) ;
F_2 ( V_68 , V_2 -> V_16 + V_69 ) ;
F_2 ( V_70 , V_2 -> V_16 + V_71 ) ;
F_2 ( V_70 , V_2 -> V_16 + V_71 ) ;
F_2 ( V_72 , V_2 -> V_16 + V_73 ) ;
F_2 ( V_74 , V_2 -> V_16 + V_75 ) ;
}
int F_5 ( struct V_76 * V_77 , T_1 V_78 )
{
V_77 -> V_79 = F_6 ( V_77 -> V_2 -> V_80 -> V_81 , V_78 * 4 ,
& V_77 -> V_82 , V_83 ) ;
if ( V_77 -> V_79 == NULL )
return - V_84 ;
V_77 -> V_85 = F_6 ( V_77 -> V_2 -> V_80 -> V_81 , V_78 * 4 ,
& V_77 -> V_86 , V_83 ) ;
if ( V_77 -> V_85 == NULL ) {
F_7 ( V_77 -> V_2 -> V_80 -> V_81 , V_78 * 4 ,
V_77 -> V_79 , V_77 -> V_82 ) ;
return - V_84 ;
}
memset ( V_77 -> V_79 , 0 , V_78 * 4 ) ;
memset ( V_77 -> V_85 , 0 , V_78 * 4 ) ;
V_77 -> V_87 = V_78 ;
return 0 ;
}
void F_8 ( struct V_76 * V_77 )
{
if ( V_77 -> V_79 != NULL )
F_7 ( V_77 -> V_2 -> V_80 -> V_81 , V_77 -> V_87 * 4 ,
V_77 -> V_79 , V_77 -> V_82 ) ;
if ( V_77 -> V_85 != NULL )
F_7 ( V_77 -> V_2 -> V_80 -> V_81 , V_77 -> V_87 * 4 ,
V_77 -> V_85 , V_77 -> V_86 ) ;
V_77 -> V_82 = 0 ;
V_77 -> V_86 = 0 ;
V_77 -> V_87 = 0 ;
}
T_1 F_9 ( struct V_76 * V_77 )
{
V_77 -> V_88 = F_6 ( V_77 -> V_2 -> V_80 -> V_81 ,
sizeof( struct V_89 ) ,
& V_77 -> V_90 , V_83 ) ;
if ( ! V_77 -> V_90 )
return - V_84 ;
memset ( V_77 -> V_88 , 0 , sizeof( struct V_89 ) ) ;
return 0 ;
}
void F_10 ( struct V_76 * V_77 )
{
if ( V_77 -> V_88 != NULL )
F_7 ( V_77 -> V_2 -> V_80 -> V_81 ,
sizeof( struct V_89 ) ,
V_77 -> V_88 ,
V_77 -> V_90 ) ;
V_77 -> V_90 = 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
int V_91 ;
struct V_92 * V_92 ;
V_2 -> V_93 = F_6 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_94 ) * V_40 ,
& V_2 -> V_31 , V_83 ) ;
if ( ! V_2 -> V_93 )
return - V_84 ;
V_2 -> V_95 = F_12 ( sizeof( struct V_92 ) * V_40 ,
V_96 ) ;
if ( ! V_2 -> V_95 ) {
F_7 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_94 ) * V_40 ,
V_2 -> V_93 ,
V_2 -> V_31 ) ;
return - V_84 ;
}
memset ( V_2 -> V_93 , 0 , sizeof( struct V_94 ) * V_40 ) ;
V_2 -> V_97 = F_6 ( V_2 -> V_80 -> V_81 ,
256 * V_40 ,
& V_2 -> V_98 ,
V_83 ) ;
if ( ! V_2 -> V_97 )
return - V_84 ;
V_2 -> V_99 = F_6 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_89 ) * V_40 ,
& V_2 -> V_100 , V_83 ) ;
if ( ! V_2 -> V_99 )
return - V_84 ;
for ( V_91 = 0 ; V_91 < V_40 ; V_91 ++ ) {
V_92 = (struct V_92 * ) ( V_2 -> V_95 +
sizeof( struct V_92 ) * V_91 ) ;
V_92 -> V_101 = V_2 -> V_97 + 256 * V_91 ;
V_92 -> V_102 = V_2 -> V_98 + 256 * V_91 ;
V_92 -> V_103 = V_2 -> V_99 +
sizeof( struct V_89 ) * V_91 ;
V_92 -> V_104 = V_2 -> V_100 +
sizeof( struct V_89 ) * V_91 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_93 != NULL )
F_7 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_94 ) * V_40 ,
V_2 -> V_93 , V_2 -> V_31 ) ;
if ( V_2 -> V_97 )
F_7 ( V_2 -> V_80 -> V_81 , 256 * V_40 ,
V_2 -> V_97 , V_2 -> V_98 ) ;
if ( V_2 -> V_99 )
F_7 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_89 ) * V_40 ,
V_2 -> V_99 , V_2 -> V_100 ) ;
F_14 ( V_2 -> V_95 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 )
{
T_1 V_105 ;
T_1 V_106 ;
V_105 = V_2 -> V_107 ;
V_106 = ( V_2 -> V_107 + 1 ) % V_40 ;
if ( V_106 == V_2 -> V_108 )
return V_109 ;
V_2 -> V_107 = V_106 ;
return V_105 ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_1 V_110 )
{
struct V_92 * V_92 ;
unsigned long V_111 ;
V_92 = (struct V_92 * ) ( V_2 -> V_95 +
sizeof( struct V_92 ) * V_110 ) ;
F_17 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
if ( V_2 -> V_108 != V_113 )
V_2 -> V_108 ++ ;
else
V_2 -> V_108 = 0 ;
V_92 -> V_114 = V_115 ;
F_18 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
return 0 ;
}
static struct V_94 * F_19 ( struct V_1 * V_2 ,
T_2 * V_116 , T_1 V_110 )
{
* V_116 = V_2 -> V_31 + sizeof( struct V_94 ) * V_110 ;
return V_2 -> V_93 + sizeof( struct V_94 ) * V_110 ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
V_2 -> V_117 = F_6 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_118 ) * V_119 ,
& V_2 -> V_45 , V_83 ) ;
if ( ! V_2 -> V_117 )
return - V_84 ;
memset ( V_2 -> V_117 , 0 , sizeof( struct V_118 ) * V_119 ) ;
return 0 ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_118 ) * V_119 ,
V_2 -> V_117 , V_2 -> V_45 ) ;
}
T_1 F_22 ( struct V_1 * V_2 , int V_120 )
{
T_1 V_105 ;
T_1 V_106 ;
if ( V_120 >= V_119 )
return V_109 ;
V_105 = V_2 -> V_121 ;
V_106 = ( V_2 -> V_121 + V_120 ) % V_119 ;
if ( V_2 -> V_121 > V_2 -> V_122 ) {
if ( V_106 < V_2 -> V_121 && V_106 >= V_2 -> V_122 )
return V_109 ;
} else if ( V_2 -> V_121 < V_2 -> V_122 ) {
if ( V_106 < V_2 -> V_121 || V_106 >= V_2 -> V_122 )
return V_109 ;
}
V_2 -> V_121 = V_106 ;
return V_105 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
unsigned long V_111 ;
F_17 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
if ( V_2 -> V_122 == V_2 -> V_121 ) {
F_18 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
return 0 ;
}
if ( V_2 -> V_122 != V_123 )
V_2 -> V_122 ++ ;
else
V_2 -> V_122 = 0 ;
F_18 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
return 0 ;
}
static inline struct V_118 * F_24 ( struct V_1 * V_2 ,
T_2 * V_124 , T_1 V_110 )
{
* V_124 = V_2 -> V_45 + sizeof( struct V_118 ) * V_110 ;
return (struct V_118 * ) ( V_2 -> V_117 + sizeof( struct V_118 ) * V_110 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
int V_91 ;
struct V_125 * V_126 ;
V_2 -> V_127 = F_6 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_125 ) * V_128 ,
& V_2 -> V_47 , V_83 ) ;
if ( ! V_2 -> V_127 )
return - V_84 ;
V_2 -> V_129 = V_54 ;
V_2 -> V_130 =
F_6 ( V_2 -> V_80 -> V_81 ,
V_2 -> V_129 * V_128 ,
& V_2 -> V_131 , V_83 ) ;
if ( ! V_2 -> V_130 ) {
F_7 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_125 ) * V_128 ,
V_2 -> V_127 , V_2 -> V_47 ) ;
return - V_84 ;
}
V_126 = V_2 -> V_127 ;
for ( V_91 = 0 ; V_91 < V_128 ; V_91 ++ ) {
V_126 [ V_91 ] . V_132 = V_2 -> V_131 +
V_2 -> V_129 * V_91 ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_127 != NULL )
F_7 ( V_2 -> V_80 -> V_81 ,
sizeof( struct V_125 ) * V_128 ,
V_2 -> V_127 , V_2 -> V_47 ) ;
if ( V_2 -> V_130 != NULL )
F_7 ( V_2 -> V_80 -> V_81 ,
V_2 -> V_129 * V_128 ,
V_2 -> V_130 ,
V_2 -> V_131 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , int V_120 )
{
T_1 V_105 ;
T_1 V_106 ;
if ( V_120 >= V_128 )
return V_109 ;
V_105 = V_2 -> V_133 ;
V_106 = ( V_2 -> V_133 + V_120 ) % V_128 ;
if ( V_2 -> V_133 > V_2 -> V_122 ) {
if ( V_106 < V_2 -> V_133 && V_106 >= V_2 -> V_134 )
return V_109 ;
} else if ( V_2 -> V_133 < V_2 -> V_134 ) {
if ( V_106 < V_2 -> V_133 || V_106 >= V_2 -> V_134 )
return V_109 ;
}
V_2 -> V_133 = V_106 ;
return V_105 ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
unsigned long V_111 ;
F_17 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
if ( V_2 -> V_134 == V_2 -> V_133 ) {
F_18 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
return 0 ;
}
if ( V_2 -> V_134 != V_135 )
V_2 -> V_134 ++ ;
else
V_2 -> V_134 = 0 ;
F_18 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
return 0 ;
}
static inline struct V_125 * F_29 ( struct V_1 * V_2 ,
T_2 * V_136 , T_1 V_110 )
{
* V_136 = V_2 -> V_47 + sizeof( struct V_125 ) * V_110 ;
return (struct V_125 * ) ( V_2 -> V_127 + sizeof( struct V_125 ) * V_110 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
T_2 * V_137 , T_1 * V_138 ,
T_1 * V_110 , T_1 * V_139 , T_1 * V_140 )
{
T_1 V_141 ;
if ( * V_138 > V_2 -> V_129 ) {
memcpy ( F_31 ( * V_137 ) ,
V_2 -> V_130 +
* V_110 * V_2 -> V_129 + * V_139 ,
V_2 -> V_129 ) ;
* V_139 = 0 ;
* V_138 -= V_2 -> V_129 ;
* V_140 -= V_2 -> V_129 ;
if ( * V_110 == V_135 )
* V_110 = 0 ;
else
( * V_110 ) ++ ;
* V_137 = * V_137 + V_2 -> V_129 ;
return 1 ;
} else if ( * V_138 < V_2 -> V_129 ) {
memcpy ( F_31 ( * V_137 ) ,
V_2 -> V_130 +
* V_110 * V_2 -> V_129 + * V_139 , * V_138 ) ;
if ( ( * V_139 + * V_138 ) == V_2 -> V_129 ) {
if ( * V_110 == V_135 )
* V_110 = 0 ;
else
( * V_110 ) ++ ;
* V_140 -= * V_138 ;
* V_139 = 0 ;
} else {
* V_140 -= * V_138 ;
* V_139 += * V_138 ;
}
return 0 ;
} else {
V_141 = ( * V_140 <= V_2 -> V_129 ) ?
( * V_140 ) : V_2 -> V_129 ;
memcpy ( F_31 ( * V_137 ) ,
V_2 -> V_130 +
* V_110 * V_2 -> V_129 + * V_139 ,
V_141 ) ;
* V_139 = 0 ;
* V_140 -= V_141 ;
if ( * V_110 == V_135 )
* V_110 = 0 ;
else
( * V_110 ) ++ ;
return 0 ;
}
}
static void F_32 ( struct V_1 * V_2 ,
struct V_94 * V_142 ,
struct V_92 * V_92 ,
T_1 V_140 ,
struct V_143 * V_144 )
{
T_2 V_137 ;
T_1 V_145 ;
T_1 V_139 ;
T_1 V_141 ;
T_1 V_91 ;
T_1 V_146 ;
struct V_143 * V_147 ;
V_145 = V_92 -> V_148 ;
V_139 = 0 ;
V_91 = 0 ;
while ( V_140 ) {
V_147 = & V_144 [ V_91 ] ;
V_146 = V_147 -> V_138 ;
V_137 = F_33 ( V_2 -> V_80 -> V_81 , F_34 ( V_147 ) ,
V_147 -> V_139 , V_147 -> V_138 , V_149 ) ;
if ( V_139 == 0 ) {
V_141 = ( V_140 <= V_147 -> V_138 ) ? V_140 : V_147 -> V_138 ;
while ( F_30 ( V_2 , & V_137 , & V_141 ,
& V_145 , & V_139 , & V_140 ) )
;
if ( ! V_140 )
return;
V_91 ++ ;
} else {
V_141 = ( V_140 <= ( V_2 -> V_129 - V_139 ) ) ?
V_140 : ( V_2 -> V_129 - V_139 ) ;
V_141 = ( V_147 -> V_138 < V_141 ) ? V_147 -> V_138 : V_141 ;
while ( F_30 ( V_2 , & V_137 , & V_141 ,
& V_145 , & V_139 , & V_140 ) )
;
if ( ! V_140 )
return;
V_146 -= V_141 ;
if ( V_146 ) {
V_137 += V_141 ;
while ( F_30 ( V_2 , & V_137 ,
& V_146 , & V_145 , & V_139 , & V_140 ) )
;
}
V_91 ++ ;
}
}
}
static T_1 F_35 ( struct V_92 * V_92 ,
struct V_76 * V_77 )
{
struct V_150 * V_151 = (struct V_150 * ) V_77 -> V_79 ;
struct V_89 * V_88 =
(struct V_89 * ) V_92 -> V_103 ;
if ( V_151 -> V_152 . V_19 . V_153 == V_154 ) {
memcpy ( ( void * ) V_92 -> V_155 , V_88 -> V_156 ,
V_157 ) ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_92 * V_92 )
{
int V_91 ;
if ( V_92 -> V_158 ) {
for ( V_91 = 0 ; V_91 < V_92 -> V_158 ; V_91 ++ )
F_23 ( V_2 ) ;
V_92 -> V_159 = 0xffffffff ;
V_92 -> V_158 = 0 ;
}
if ( V_92 -> V_160 ) {
for ( V_91 = 0 ; V_91 < V_92 -> V_160 ; V_91 ++ )
F_28 ( V_2 ) ;
V_92 -> V_148 = 0xffffffff ;
V_92 -> V_160 = 0 ;
}
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_92 * V_92 ,
struct V_94 * V_142 )
{
struct V_76 * V_77 ;
struct V_161 * V_162 ;
struct V_143 * V_144 ;
T_2 V_137 ;
V_162 = F_38 ( V_92 -> V_163 ) ;
V_77 = F_39 ( V_162 -> V_164 . V_165 ) ;
if ( V_92 -> V_166 ) {
F_32 ( V_2 , V_142 , V_92 , V_162 -> V_140 ,
V_162 -> V_144 ) ;
} else {
V_144 = V_92 -> V_155 ;
V_137 = F_33 ( V_2 -> V_80 -> V_81 , F_34 ( V_144 ) ,
V_144 -> V_139 , V_144 -> V_138 , V_167 ) ;
}
F_36 ( V_2 , V_92 ) ;
if ( V_162 -> V_164 . V_168 != NULL )
V_162 -> V_164 . V_168 ( & V_162 -> V_164 , 0 ) ;
return 0 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_92 * V_92 )
{
struct V_76 * V_77 ;
struct V_169 * V_170 ;
V_170 = F_41 ( V_92 -> V_163 ) ;
V_77 = F_39 ( V_170 -> V_164 . V_165 ) ;
F_35 ( V_92 ,
F_39 ( V_170 -> V_164 . V_165 ) ) ;
F_36 ( V_2 , V_92 ) ;
if ( V_170 -> V_164 . V_168 != NULL )
V_170 -> V_164 . V_168 ( & V_170 -> V_164 , 0 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_1 * V_2 , T_1 V_110 )
{
struct V_94 * V_142 ;
struct V_92 * V_92 ;
V_142 = V_2 -> V_93 + sizeof( struct V_94 ) * V_110 ;
V_92 = V_2 -> V_95 + sizeof( struct V_92 ) * V_110 ;
if ( F_43 ( V_92 -> V_163 -> V_165 ) ==
V_171 )
return F_37 ( V_2 , V_92 , V_142 ) ;
else
return F_40 ( V_2 , V_92 ) ;
}
void F_44 ( unsigned int * V_144 ,
const unsigned char * V_172 ,
int V_141 )
{
T_3 * V_106 ;
for (; V_141 >= 4 ; V_172 += 4 , V_141 -= 4 )
* V_144 ++ = F_45 ( * ( unsigned int * ) V_172 ) ;
V_106 = ( T_3 * ) V_144 ;
switch ( V_141 ) {
case 3 :
* V_106 ++ = 0 ;
* V_106 ++ = * ( V_172 + 2 ) ;
* V_106 ++ = * ( V_172 + 1 ) ;
* V_106 ++ = * V_172 ;
break;
case 2 :
* V_106 ++ = 0 ;
* V_106 ++ = 0 ;
* V_106 ++ = * ( V_172 + 1 ) ;
* V_106 ++ = * V_172 ;
break;
case 1 :
* V_106 ++ = 0 ;
* V_106 ++ = 0 ;
* V_106 ++ = 0 ;
* V_106 ++ = * V_172 ;
break;
default:
break;
}
}
static void F_46 ( struct V_173 * V_80 )
{
F_13 ( V_80 -> V_2 ) ;
F_21 ( V_80 -> V_2 ) ;
F_26 ( V_80 -> V_2 ) ;
F_47 ( V_80 -> V_2 -> V_16 ) ;
F_14 ( V_80 -> V_2 ) ;
F_14 ( V_80 ) ;
}
void F_48 ( struct V_1 * V_2 ,
T_1 V_174 , struct V_94 * V_142 ,
struct V_92 * V_92 )
{
V_2 -> V_107 = V_174 ;
V_142 -> V_175 . V_18 = 0 ;
V_142 -> V_176 . V_18 = 0 ;
V_92 -> V_114 = V_115 ;
}
static T_1 F_49 ( T_1 V_177 )
{
if ( V_177 != V_123 )
return V_177 + 1 ;
else
return 0 ;
}
static T_1 F_50 ( T_1 V_177 )
{
if ( V_177 != V_135 )
return V_177 + 1 ;
else
return 0 ;
}
T_1 F_51 ( struct V_178 * V_179 ,
struct V_76 * V_77 ,
struct V_143 * V_180 ,
struct V_143 * V_144 ,
unsigned int V_181 ,
void * V_182 , T_1 V_183 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
T_2 V_137 , V_116 , V_136 , V_124 ;
struct V_150 * V_151 ;
struct V_143 * V_147 ;
struct V_118 * V_184 ;
struct V_94 * V_142 ;
T_1 V_158 , V_160 ;
T_1 V_185 = 0xffffffff ;
T_1 V_186 = 0xffffffff ;
T_1 V_174 ;
unsigned long V_111 ;
struct V_92 * V_92 = NULL ;
unsigned int V_140 = V_181 , V_110 ;
unsigned int V_187 = 0 ;
T_1 V_188 = 0 ;
V_158 = F_52 ( V_180 , V_181 ) ;
if ( ( int ) V_158 < 0 ) {
F_53 ( V_2 -> V_80 -> V_81 , L_1 ) ;
return - V_189 ;
}
if ( V_158 == 1 )
V_158 = 0 ;
if ( F_54 ( V_144 ) || V_77 -> V_190 ) {
V_160 = 0 ;
} else {
if ( V_181 > V_54 ) {
V_160 = V_181 / V_54 ;
if ( V_181 % V_54 )
V_160 ++ ;
} else {
V_160 = 1 ;
}
}
F_17 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
if ( V_158 ) {
V_185 = F_22 ( V_2 , V_158 ) ;
if ( V_185 == V_109 ) {
F_18 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
return - V_191 ;
}
}
if ( V_160 ) {
V_186 = F_27 ( V_2 , V_160 ) ;
if ( V_186 == V_109 ) {
if ( V_158 )
V_2 -> V_121 = V_185 ;
F_18 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
return - V_191 ;
}
}
V_174 = F_15 ( V_2 ) ;
if ( V_174 == V_109 ) {
if ( V_158 )
V_2 -> V_121 = V_185 ;
if ( V_160 )
V_2 -> V_133 = V_186 ;
F_18 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
return - V_191 ;
}
F_18 ( & V_2 -> V_80 -> V_112 , V_111 ) ;
V_92 = (struct V_92 * ) ( V_2 -> V_95 +
sizeof( struct V_92 ) * V_174 ) ;
V_142 = F_19 ( V_2 , & V_116 , V_174 ) ;
V_92 -> V_163 = V_179 ;
V_92 -> V_158 = V_158 ;
V_92 -> V_160 = V_160 ;
if ( V_183 || V_77 -> V_190 ) {
V_187 = V_183 ;
V_142 -> V_151 = V_92 -> V_102 ;
V_151 = (struct V_150 * ) V_92 -> V_101 ;
if ( V_77 -> V_192 == V_193 )
memcpy ( V_151 , V_77 -> V_79 , V_77 -> V_87 * 4 ) ;
else
memcpy ( V_151 , V_77 -> V_85 , V_77 -> V_87 * 4 ) ;
memcpy ( ( void * ) V_151 + V_77 -> V_194 ,
& V_92 -> V_104 , 4 ) ;
if ( V_183 )
F_44 ( V_92 -> V_103 , V_182 , V_183 ) ;
} else {
if ( V_77 -> V_192 == V_193 ) {
V_142 -> V_151 = V_77 -> V_82 ;
V_151 = (struct V_150 * ) V_77 -> V_79 ;
} else {
V_142 -> V_151 = V_77 -> V_86 ;
V_151 = (struct V_150 * ) V_77 -> V_85 ;
}
}
V_142 -> V_87 = V_77 -> V_87 ;
if ( V_158 ) {
V_188 = V_185 ;
V_92 -> V_159 = V_185 ;
V_92 -> V_158 = V_158 ;
V_184 = F_24 ( V_2 , & V_124 , V_188 ) ;
V_142 -> V_180 = V_124 ;
V_151 -> V_152 . V_19 . V_195 = 1 ;
V_110 = 0 ;
V_180 = & V_180 [ 0 ] ;
while ( V_140 ) {
V_147 = & V_180 [ V_110 ] ;
V_137 = F_33 ( V_2 -> V_80 -> V_81 , F_34 ( V_147 ) ,
V_147 -> V_139 , V_147 -> V_138 , V_149 ) ;
V_184 -> V_132 = V_137 ;
V_184 -> V_196 . V_141 = V_147 -> V_138 ;
V_184 -> V_196 . V_197 = 0 ;
V_184 -> V_196 . V_198 = 1 ;
if ( V_147 -> V_138 >= V_140 )
break;
V_140 -= V_147 -> V_138 ;
V_188 = F_49 ( V_188 ) ;
V_184 = F_24 ( V_2 , & V_124 , V_188 ) ;
V_110 ++ ;
}
} else {
V_142 -> V_180 = ( T_1 ) F_33 ( V_2 -> V_80 -> V_81 , F_34 ( V_180 ) ,
V_180 -> V_139 , V_180 -> V_138 , V_149 ) ;
V_151 -> V_152 . V_19 . V_195 = 0 ;
V_92 -> V_159 = 0xffffffff ;
V_92 -> V_158 = 0 ;
}
if ( V_77 -> V_190 || F_54 ( V_144 ) ) {
V_92 -> V_166 = 0 ;
V_92 -> V_148 = 0xffffffff ;
V_92 -> V_160 = 0 ;
V_92 -> V_155 = V_144 ;
V_151 -> V_152 . V_19 . V_199 = 0 ;
if ( V_77 -> V_190 )
V_142 -> V_200 = F_55 ( ( void * ) V_144 ) ;
else
V_142 -> V_200 = ( T_1 ) F_33 ( V_2 -> V_80 -> V_81 ,
F_34 ( V_144 ) , V_144 -> V_139 ,
V_144 -> V_138 , V_149 ) ;
} else {
struct V_125 * V_201 = NULL ;
T_1 V_202 = V_186 ;
V_140 = V_181 ;
V_151 -> V_152 . V_19 . V_199 = 1 ;
V_92 -> V_166 = 1 ;
V_92 -> V_155 = V_144 ;
V_92 -> V_148 = V_186 ;
V_92 -> V_160 = V_160 ;
V_201 = F_29 ( V_2 , & V_136 , V_202 ) ;
V_142 -> V_200 = V_136 ;
V_201 -> V_203 . V_197 = 0 ;
V_201 -> V_203 . V_204 = 1 ;
V_110 = 0 ;
if ( V_140 >= V_54 )
V_140 -= V_54 ;
else
V_140 = 0 ;
while ( V_140 ) {
V_202 = F_50 ( V_202 ) ;
V_201 = F_29 ( V_2 , & V_136 , V_202 ) ;
V_201 -> V_203 . V_197 = 0 ;
V_201 -> V_203 . V_204 = 1 ;
if ( V_140 >= V_54 )
V_140 -= V_54 ;
else
V_140 = 0 ;
}
}
V_151 -> V_205 . V_19 . V_206 = 0 ;
V_142 -> V_175 . V_18 = V_77 -> V_175 ;
V_142 -> V_176 . V_18 = 0x00400000 | ( V_77 -> V_207 << 24 ) | V_181 ;
V_92 -> V_114 = V_208 ;
F_56 () ;
F_2 ( 1 , V_2 -> V_16 + V_209 ) ;
return - V_210 ;
}
static int F_57 ( struct V_211 * V_165 )
{
struct V_212 * V_213 = V_165 -> V_214 ;
struct V_215 * V_216 = F_58 ( V_213 ) ;
struct V_76 * V_77 = F_39 ( V_165 ) ;
V_77 -> V_2 = V_216 -> V_2 ;
V_77 -> V_79 = NULL ;
V_77 -> V_85 = NULL ;
V_77 -> V_82 = 0 ;
V_77 -> V_86 = 0 ;
V_77 -> V_87 = 0 ;
switch ( V_213 -> V_217 & V_218 ) {
default:
V_165 -> V_219 . V_220 = sizeof( struct V_76 ) ;
break;
case V_221 :
F_59 ( F_60 ( V_165 ) ,
sizeof( struct V_76 ) ) ;
break;
}
return 0 ;
}
static void F_61 ( struct V_211 * V_165 )
{
struct V_76 * V_77 = F_39 ( V_165 ) ;
F_8 ( V_77 ) ;
F_10 ( V_77 ) ;
}
int F_62 ( struct V_1 * V_222 ,
struct V_223 * V_212 ,
int V_224 )
{
struct V_215 * V_213 ;
int V_91 ;
int V_225 = 0 ;
for ( V_91 = 0 ; V_91 < V_224 ; V_91 ++ ) {
V_213 = F_12 ( sizeof( struct V_215 ) , V_96 ) ;
if ( ! V_213 )
return - V_84 ;
V_213 -> V_213 = V_212 [ V_91 ] ;
V_213 -> V_2 = V_222 ;
switch ( V_213 -> V_213 . type ) {
case V_221 :
V_225 = F_63 ( & V_213 -> V_213 . V_226 . V_227 ) ;
break;
default:
V_225 = F_64 ( & V_213 -> V_213 . V_226 . V_228 ) ;
break;
}
if ( V_225 ) {
F_65 ( & V_213 -> V_229 ) ;
F_14 ( V_213 ) ;
} else {
F_66 ( & V_213 -> V_229 , & V_222 -> V_230 ) ;
}
}
return 0 ;
}
static void F_67 ( struct V_1 * V_222 )
{
struct V_215 * V_213 , * V_106 ;
F_68 (alg, tmp, &sec_dev->alg_list, entry) {
F_65 ( & V_213 -> V_229 ) ;
switch ( V_213 -> V_213 . type ) {
case V_221 :
F_69 ( & V_213 -> V_213 . V_226 . V_227 ) ;
break;
default:
F_70 ( & V_213 -> V_213 . V_226 . V_228 ) ;
}
F_14 ( V_213 ) ;
}
}
static void F_71 ( unsigned long V_231 )
{
struct V_81 * V_2 = (struct V_81 * ) V_231 ;
struct V_173 * V_80 = F_72 ( V_2 ) ;
struct V_92 * V_92 ;
struct V_94 * V_142 ;
T_1 V_232 ;
while ( V_80 -> V_2 -> V_107 != V_80 -> V_2 -> V_108 ) {
V_232 = V_80 -> V_2 -> V_108 ;
V_92 = V_80 -> V_2 -> V_95 +
sizeof( struct V_92 ) * V_232 ;
V_142 = V_80 -> V_2 -> V_93 + sizeof( struct V_94 ) * V_232 ;
if ( ( V_92 -> V_114 == V_208 ) &&
V_142 -> V_175 . V_19 . V_233 &&
! V_142 -> V_175 . V_19 . V_234 ) {
V_142 -> V_175 . V_19 . V_233 = 0 ;
F_42 ( V_80 -> V_2 , V_232 ) ;
F_16 ( V_80 -> V_2 , V_232 ) ;
V_92 -> V_114 = V_115 ;
} else {
break;
}
}
}
static T_4 F_73 ( int V_235 , void * V_231 )
{
struct V_81 * V_2 = (struct V_81 * ) V_231 ;
struct V_173 * V_80 = F_72 ( V_2 ) ;
if ( ! V_80 -> V_2 -> V_16 )
return 0 ;
F_2 ( V_68 ,
V_80 -> V_2 -> V_16 + V_69 ) ;
F_74 ( & V_80 -> V_236 ) ;
return V_237 ;
}
static int F_75 ( struct V_238 * V_239 )
{
int V_225 ;
struct V_240 V_241 ;
struct V_81 * V_2 = & V_239 -> V_2 ;
struct V_173 * V_80 ;
V_225 = F_76 ( V_239 -> V_2 . V_242 , 0 , & V_241 ) ;
if ( V_225 )
return - V_243 ;
if ( F_77 ( NULL , NULL , L_2 ) ) {
F_78 ( V_244 , V_245 ,
F_79 ( V_244 , V_245 ) | V_246 ) ;
F_78 ( V_244 , V_245 ,
F_79 ( V_244 , V_245 ) & ~ V_246 ) ;
} else if ( F_77 ( NULL , NULL ,
L_3 ) ) {
F_78 ( V_244 , V_247 ,
F_79 ( V_244 , V_247 ) | V_248 ) ;
F_78 ( V_244 , V_247 ,
F_79 ( V_244 , V_247 ) & ~ V_248 ) ;
} else if ( F_77 ( NULL , NULL ,
L_4 ) ) {
F_78 ( V_244 , V_249 ,
F_79 ( V_244 , V_249 ) | V_250 ) ;
F_78 ( V_244 , V_249 ,
F_79 ( V_244 , V_249 ) & ~ V_250 ) ;
} else {
F_80 ( V_251 L_5 ) ;
return - V_189 ;
}
V_80 = F_12 ( sizeof( struct V_173 ) , V_96 ) ;
if ( ! V_80 )
return - V_84 ;
F_81 ( V_2 , V_80 ) ;
V_80 -> V_239 = V_239 ;
V_80 -> V_2 = F_12 ( sizeof( struct V_1 ) , V_96 ) ;
if ( ! V_80 -> V_2 )
goto V_252;
V_80 -> V_2 -> V_80 = V_80 ;
V_80 -> V_81 = V_2 ;
F_82 ( & V_80 -> V_112 ) ;
F_83 ( & V_80 -> V_2 -> V_230 ) ;
V_225 = F_11 ( V_80 -> V_2 ) ;
if ( V_225 )
goto V_253;
V_225 = F_20 ( V_80 -> V_2 ) ;
if ( V_225 )
goto V_254;
V_225 = F_25 ( V_80 -> V_2 ) ;
if ( V_225 )
goto V_255;
F_84 ( & V_80 -> V_236 , F_71 ,
( unsigned long ) V_2 ) ;
V_80 -> V_235 = F_85 ( V_239 -> V_2 . V_242 , 0 ) ;
V_225 = F_86 ( V_80 -> V_235 , F_73 , 0 ,
V_80 -> V_2 -> V_256 , V_2 ) ;
if ( V_225 )
goto V_257;
V_80 -> V_2 -> V_16 = F_87 ( V_239 -> V_2 . V_242 , 0 ) ;
if ( ! V_80 -> V_2 -> V_16 ) {
F_53 ( V_2 , L_6 ) ;
V_225 = - V_84 ;
goto V_258;
}
F_1 ( V_80 -> V_2 ) ;
V_225 = F_62 ( V_80 -> V_2 , V_215 ,
F_88 ( V_215 ) ) ;
if ( V_225 )
goto V_259;
F_89 ( V_80 ) ;
return 0 ;
V_259:
F_47 ( V_80 -> V_2 -> V_16 ) ;
V_258:
F_90 ( V_80 -> V_235 , V_2 ) ;
V_257:
F_91 ( V_80 -> V_235 ) ;
F_92 ( & V_80 -> V_236 ) ;
F_26 ( V_80 -> V_2 ) ;
V_255:
F_21 ( V_80 -> V_2 ) ;
V_254:
F_13 ( V_80 -> V_2 ) ;
V_253:
F_14 ( V_80 -> V_2 ) ;
V_252:
F_14 ( V_80 ) ;
return V_225 ;
}
static int F_93 ( struct V_238 * V_239 )
{
struct V_81 * V_2 = & V_239 -> V_2 ;
struct V_173 * V_80 = F_72 ( V_2 ) ;
F_94 ( V_80 ) ;
F_90 ( V_80 -> V_235 , V_2 ) ;
F_91 ( V_80 -> V_235 ) ;
F_92 ( & V_80 -> V_236 ) ;
F_67 ( V_80 -> V_2 ) ;
F_46 ( V_80 ) ;
return 0 ;
}
