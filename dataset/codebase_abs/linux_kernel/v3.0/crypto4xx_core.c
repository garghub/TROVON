static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
union V_5 V_6 ;
union V_7 V_8 ;
union V_9 V_10 ;
T_1 V_11 ;
union V_12 V_13 ;
F_2 ( V_14 , V_2 -> V_15 + V_16 ) ;
V_13 . V_17 = 0 ;
V_13 . V_18 . V_19 = 1 ;
V_13 . V_18 . V_20 = 0 ;
V_13 . V_18 . V_21 = 1 ;
V_13 . V_18 . V_22 = 1 ;
V_13 . V_18 . V_23 = 1 ;
V_13 . V_18 . V_24 = 1 ;
V_13 . V_18 . V_25 = 1 ;
V_13 . V_18 . V_26 = 1 ;
F_2 ( V_13 . V_17 , V_2 -> V_15 + V_27 ) ;
V_13 . V_18 . V_28 = 0 ;
V_13 . V_18 . V_24 = 0 ;
V_13 . V_18 . V_25 = 0 ;
V_13 . V_18 . V_26 = 0 ;
V_13 . V_18 . V_29 = 0 ;
F_2 ( V_13 . V_17 , V_2 -> V_15 + V_27 ) ;
F_2 ( V_2 -> V_30 , V_2 -> V_15 + V_31 ) ;
F_2 ( V_2 -> V_30 , V_2 -> V_15 + V_32 ) ;
F_2 ( V_33 , V_2 -> V_15 + V_34 ) ;
F_3 ( & V_11 , sizeof( V_11 ) ) ;
F_2 ( V_11 , V_2 -> V_15 + V_35 ) ;
F_3 ( & V_11 , sizeof( V_11 ) ) ;
F_2 ( V_11 , V_2 -> V_15 + V_36 ) ;
V_4 . V_17 = 0 ;
V_4 . V_18 . V_37 = V_38 ;
V_4 . V_18 . V_4 = V_39 ;
F_2 ( V_4 . V_17 , V_2 -> V_15 + V_40 ) ;
V_6 . V_17 = 0 ;
F_2 ( V_6 . V_17 , V_2 -> V_15 + V_41 ) ;
F_2 ( V_42 , V_2 -> V_15 + V_43 ) ;
F_2 ( V_2 -> V_44 , V_2 -> V_15 + V_45 ) ;
F_2 ( V_2 -> V_46 , V_2 -> V_15 + V_47 ) ;
V_8 . V_17 = 0 ;
V_8 . V_18 . V_48 = V_49 ;
V_8 . V_18 . V_50 = V_51 ;
F_2 ( V_8 . V_17 , V_2 -> V_15 + V_52 ) ;
F_2 ( V_53 , V_2 -> V_15 + V_54 ) ;
V_10 . V_17 = 0 ;
V_10 . V_18 . V_55 = V_56 ;
V_10 . V_18 . V_57 = V_58 ;
F_2 ( V_10 . V_17 , V_2 -> V_15 + V_59 ) ;
F_2 ( 0 , V_2 -> V_15 + V_60 ) ;
F_2 ( 0 , V_2 -> V_15 + V_61 ) ;
F_2 ( 0 , V_2 -> V_15 + V_62 ) ;
F_2 ( 0 , V_2 -> V_15 + V_63 ) ;
F_2 ( 0 , V_2 -> V_15 + V_64 ) ;
F_2 ( 0 , V_2 -> V_15 + V_65 ) ;
F_2 ( 0 , V_2 -> V_15 + V_66 ) ;
V_13 . V_18 . V_28 = 1 ;
V_13 . V_18 . V_24 = 0 ;
V_13 . V_18 . V_25 = 0 ;
V_13 . V_18 . V_26 = 0 ;
V_13 . V_18 . V_29 = 0 ;
F_2 ( V_13 . V_17 , V_2 -> V_15 + V_27 ) ;
F_2 ( V_67 , V_2 -> V_15 + V_68 ) ;
F_2 ( V_69 , V_2 -> V_15 + V_70 ) ;
F_2 ( V_69 , V_2 -> V_15 + V_70 ) ;
F_2 ( V_71 , V_2 -> V_15 + V_72 ) ;
F_2 ( V_73 , V_2 -> V_15 + V_74 ) ;
}
int F_4 ( struct V_75 * V_76 , T_1 V_77 )
{
V_76 -> V_78 = F_5 ( V_76 -> V_2 -> V_79 -> V_80 , V_77 * 4 ,
& V_76 -> V_81 , V_82 ) ;
if ( V_76 -> V_78 == NULL )
return - V_83 ;
V_76 -> V_84 = F_5 ( V_76 -> V_2 -> V_79 -> V_80 , V_77 * 4 ,
& V_76 -> V_85 , V_82 ) ;
if ( V_76 -> V_84 == NULL ) {
F_6 ( V_76 -> V_2 -> V_79 -> V_80 ,
V_76 -> V_86 * 4 ,
V_76 -> V_78 , V_76 -> V_81 ) ;
return - V_83 ;
}
memset ( V_76 -> V_78 , 0 , V_77 * 4 ) ;
memset ( V_76 -> V_84 , 0 , V_77 * 4 ) ;
V_76 -> V_86 = V_77 ;
return 0 ;
}
void F_7 ( struct V_75 * V_76 )
{
if ( V_76 -> V_78 != NULL )
F_6 ( V_76 -> V_2 -> V_79 -> V_80 , V_76 -> V_86 * 4 ,
V_76 -> V_78 , V_76 -> V_81 ) ;
if ( V_76 -> V_84 != NULL )
F_6 ( V_76 -> V_2 -> V_79 -> V_80 , V_76 -> V_86 * 4 ,
V_76 -> V_84 , V_76 -> V_85 ) ;
V_76 -> V_81 = 0 ;
V_76 -> V_85 = 0 ;
V_76 -> V_86 = 0 ;
}
T_1 F_8 ( struct V_75 * V_76 )
{
V_76 -> V_87 = F_5 ( V_76 -> V_2 -> V_79 -> V_80 ,
sizeof( struct V_88 ) ,
& V_76 -> V_89 , V_82 ) ;
if ( ! V_76 -> V_89 )
return - V_83 ;
memset ( V_76 -> V_87 , 0 , sizeof( struct V_88 ) ) ;
return 0 ;
}
void F_9 ( struct V_75 * V_76 )
{
if ( V_76 -> V_87 != NULL )
F_6 ( V_76 -> V_2 -> V_79 -> V_80 ,
sizeof( struct V_88 ) ,
V_76 -> V_87 ,
V_76 -> V_89 ) ;
V_76 -> V_89 = 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
int V_90 ;
struct V_91 * V_91 ;
V_2 -> V_92 = F_5 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_93 ) * V_39 ,
& V_2 -> V_30 , V_82 ) ;
if ( ! V_2 -> V_92 )
return - V_83 ;
V_2 -> V_94 = F_11 ( sizeof( struct V_91 ) * V_39 ,
V_95 ) ;
if ( ! V_2 -> V_94 ) {
F_6 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_93 ) * V_39 ,
V_2 -> V_92 ,
V_2 -> V_30 ) ;
return - V_83 ;
}
memset ( V_2 -> V_92 , 0 , sizeof( struct V_93 ) * V_39 ) ;
V_2 -> V_96 = F_5 ( V_2 -> V_79 -> V_80 ,
256 * V_39 ,
& V_2 -> V_97 ,
V_82 ) ;
if ( ! V_2 -> V_96 )
return - V_83 ;
V_2 -> V_98 = F_5 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_88 ) * V_39 ,
& V_2 -> V_99 , V_82 ) ;
if ( ! V_2 -> V_98 )
return - V_83 ;
for ( V_90 = 0 ; V_90 < V_39 ; V_90 ++ ) {
V_91 = (struct V_91 * ) ( V_2 -> V_94 +
sizeof( struct V_91 ) * V_90 ) ;
V_91 -> V_100 = V_2 -> V_96 + 256 * V_90 ;
V_91 -> V_101 = V_2 -> V_97 + 256 * V_90 ;
V_91 -> V_102 = V_2 -> V_98 +
sizeof( struct V_88 ) * V_90 ;
V_91 -> V_103 = V_2 -> V_99 +
sizeof( struct V_88 ) * V_90 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_92 != NULL )
F_6 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_93 ) * V_39 ,
V_2 -> V_92 , V_2 -> V_30 ) ;
if ( V_2 -> V_96 )
F_6 ( V_2 -> V_79 -> V_80 , 256 * V_39 ,
V_2 -> V_96 , V_2 -> V_97 ) ;
if ( V_2 -> V_98 )
F_6 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_88 ) * V_39 ,
V_2 -> V_98 , V_2 -> V_99 ) ;
F_13 ( V_2 -> V_94 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
T_1 V_104 ;
T_1 V_105 ;
V_104 = V_2 -> V_106 ;
V_105 = ( V_2 -> V_106 + 1 ) % V_39 ;
if ( V_105 == V_2 -> V_107 )
return V_108 ;
V_2 -> V_106 = V_105 ;
return V_104 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_1 V_109 )
{
struct V_91 * V_91 ;
unsigned long V_110 ;
V_91 = (struct V_91 * ) ( V_2 -> V_94 +
sizeof( struct V_91 ) * V_109 ) ;
F_16 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
if ( V_2 -> V_107 != V_112 )
V_2 -> V_107 ++ ;
else
V_2 -> V_107 = 0 ;
V_91 -> V_113 = V_114 ;
F_17 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
return 0 ;
}
static struct V_93 * F_18 ( struct V_1 * V_2 ,
T_2 * V_115 , T_1 V_109 )
{
* V_115 = V_2 -> V_30 + sizeof( struct V_93 ) * V_109 ;
return V_2 -> V_92 + sizeof( struct V_93 ) * V_109 ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
V_2 -> V_116 = F_5 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_117 ) * V_118 ,
& V_2 -> V_44 , V_82 ) ;
if ( ! V_2 -> V_116 )
return - V_83 ;
memset ( V_2 -> V_116 , 0 , sizeof( struct V_117 ) * V_118 ) ;
return 0 ;
}
static inline void F_20 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_117 ) * V_118 ,
V_2 -> V_116 , V_2 -> V_44 ) ;
}
T_1 F_21 ( struct V_1 * V_2 , int V_119 )
{
T_1 V_104 ;
T_1 V_105 ;
if ( V_119 >= V_118 )
return V_108 ;
V_104 = V_2 -> V_120 ;
V_105 = ( V_2 -> V_120 + V_119 ) % V_118 ;
if ( V_2 -> V_120 > V_2 -> V_121 ) {
if ( V_105 < V_2 -> V_120 && V_105 >= V_2 -> V_121 )
return V_108 ;
} else if ( V_2 -> V_120 < V_2 -> V_121 ) {
if ( V_105 < V_2 -> V_120 || V_105 >= V_2 -> V_121 )
return V_108 ;
}
V_2 -> V_120 = V_105 ;
return V_104 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
F_16 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
if ( V_2 -> V_121 == V_2 -> V_120 ) {
F_17 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
return 0 ;
}
if ( V_2 -> V_121 != V_122 )
V_2 -> V_121 ++ ;
else
V_2 -> V_121 = 0 ;
F_17 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
return 0 ;
}
static inline struct V_117 * F_23 ( struct V_1 * V_2 ,
T_2 * V_123 , T_1 V_109 )
{
* V_123 = V_2 -> V_44 + sizeof( struct V_117 ) * V_109 ;
return (struct V_117 * ) ( V_2 -> V_116 + sizeof( struct V_117 ) * V_109 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
int V_90 ;
struct V_124 * V_125 ;
V_2 -> V_126 = F_5 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_124 ) * V_127 ,
& V_2 -> V_46 , V_82 ) ;
if ( ! V_2 -> V_126 )
return - V_83 ;
V_2 -> V_128 = V_53 ;
V_2 -> V_129 =
F_5 ( V_2 -> V_79 -> V_80 ,
V_2 -> V_128 * V_127 ,
& V_2 -> V_130 , V_82 ) ;
if ( ! V_2 -> V_129 ) {
F_6 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_124 ) * V_127 ,
V_2 -> V_126 , V_2 -> V_46 ) ;
return - V_83 ;
}
V_125 = V_2 -> V_126 ;
for ( V_90 = 0 ; V_90 < V_127 ; V_90 ++ ) {
V_125 [ V_90 ] . V_131 = V_2 -> V_130 +
V_2 -> V_128 * V_90 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_126 != NULL )
F_6 ( V_2 -> V_79 -> V_80 ,
sizeof( struct V_124 ) * V_127 ,
V_2 -> V_126 , V_2 -> V_46 ) ;
if ( V_2 -> V_129 != NULL )
F_6 ( V_2 -> V_79 -> V_80 ,
V_2 -> V_128 * V_127 ,
V_2 -> V_129 ,
V_2 -> V_130 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , int V_119 )
{
T_1 V_104 ;
T_1 V_105 ;
if ( V_119 >= V_127 )
return V_108 ;
V_104 = V_2 -> V_132 ;
V_105 = ( V_2 -> V_132 + V_119 ) % V_127 ;
if ( V_2 -> V_132 > V_2 -> V_121 ) {
if ( V_105 < V_2 -> V_132 && V_105 >= V_2 -> V_133 )
return V_108 ;
} else if ( V_2 -> V_132 < V_2 -> V_133 ) {
if ( V_105 < V_2 -> V_132 || V_105 >= V_2 -> V_133 )
return V_108 ;
}
V_2 -> V_132 = V_105 ;
return V_104 ;
}
static T_1 F_27 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
F_16 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
if ( V_2 -> V_133 == V_2 -> V_132 ) {
F_17 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
return 0 ;
}
if ( V_2 -> V_133 != V_134 )
V_2 -> V_133 ++ ;
else
V_2 -> V_133 = 0 ;
F_17 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
return 0 ;
}
static inline struct V_124 * F_28 ( struct V_1 * V_2 ,
T_2 * V_135 , T_1 V_109 )
{
* V_135 = V_2 -> V_46 + sizeof( struct V_124 ) * V_109 ;
return (struct V_124 * ) ( V_2 -> V_126 + sizeof( struct V_124 ) * V_109 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
T_2 * V_136 , T_1 * V_137 ,
T_1 * V_109 , T_1 * V_138 , T_1 * V_139 )
{
T_1 V_140 ;
if ( * V_137 > V_2 -> V_128 ) {
memcpy ( F_30 ( * V_136 ) ,
V_2 -> V_129 +
* V_109 * V_2 -> V_128 + * V_138 ,
V_2 -> V_128 ) ;
* V_138 = 0 ;
* V_137 -= V_2 -> V_128 ;
* V_139 -= V_2 -> V_128 ;
if ( * V_109 == V_134 )
* V_109 = 0 ;
else
( * V_109 ) ++ ;
* V_136 = * V_136 + V_2 -> V_128 ;
return 1 ;
} else if ( * V_137 < V_2 -> V_128 ) {
memcpy ( F_30 ( * V_136 ) ,
V_2 -> V_129 +
* V_109 * V_2 -> V_128 + * V_138 , * V_137 ) ;
if ( ( * V_138 + * V_137 ) == V_2 -> V_128 ) {
if ( * V_109 == V_134 )
* V_109 = 0 ;
else
( * V_109 ) ++ ;
* V_139 -= * V_137 ;
* V_138 = 0 ;
} else {
* V_139 -= * V_137 ;
* V_138 += * V_137 ;
}
return 0 ;
} else {
V_140 = ( * V_139 <= V_2 -> V_128 ) ?
( * V_139 ) : V_2 -> V_128 ;
memcpy ( F_30 ( * V_136 ) ,
V_2 -> V_129 +
* V_109 * V_2 -> V_128 + * V_138 ,
V_140 ) ;
* V_138 = 0 ;
* V_139 -= V_140 ;
if ( * V_109 == V_134 )
* V_109 = 0 ;
else
( * V_109 ) ++ ;
return 0 ;
}
}
static void F_31 ( struct V_1 * V_2 ,
struct V_93 * V_141 ,
struct V_91 * V_91 ,
T_1 V_139 ,
struct V_142 * V_143 )
{
T_2 V_136 ;
T_1 V_144 ;
T_1 V_138 ;
T_1 V_140 ;
T_1 V_90 ;
T_1 V_145 ;
struct V_142 * V_146 ;
V_144 = V_91 -> V_147 ;
V_138 = 0 ;
V_90 = 0 ;
while ( V_139 ) {
V_146 = & V_143 [ V_90 ] ;
V_145 = V_146 -> V_137 ;
V_136 = F_32 ( V_2 -> V_79 -> V_80 , F_33 ( V_146 ) ,
V_146 -> V_138 , V_146 -> V_137 , V_148 ) ;
if ( V_138 == 0 ) {
V_140 = ( V_139 <= V_146 -> V_137 ) ? V_139 : V_146 -> V_137 ;
while ( F_29 ( V_2 , & V_136 , & V_140 ,
& V_144 , & V_138 , & V_139 ) )
;
if ( ! V_139 )
return;
V_90 ++ ;
} else {
V_140 = ( V_139 <= ( V_2 -> V_128 - V_138 ) ) ?
V_139 : ( V_2 -> V_128 - V_138 ) ;
V_140 = ( V_146 -> V_137 < V_140 ) ? V_146 -> V_137 : V_140 ;
while ( F_29 ( V_2 , & V_136 , & V_140 ,
& V_144 , & V_138 , & V_139 ) )
;
if ( ! V_139 )
return;
V_145 -= V_140 ;
if ( V_145 ) {
V_136 += V_140 ;
while ( F_29 ( V_2 , & V_136 ,
& V_145 , & V_144 , & V_138 , & V_139 ) )
;
}
V_90 ++ ;
}
}
}
static T_1 F_34 ( struct V_91 * V_91 ,
struct V_75 * V_76 )
{
struct V_149 * V_150 = (struct V_149 * ) V_76 -> V_78 ;
struct V_88 * V_87 =
(struct V_88 * ) V_91 -> V_102 ;
if ( V_150 -> V_151 . V_18 . V_152 == V_153 ) {
memcpy ( ( void * ) V_91 -> V_154 , V_87 -> V_155 ,
V_156 ) ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_91 * V_91 )
{
int V_90 ;
if ( V_91 -> V_157 ) {
for ( V_90 = 0 ; V_90 < V_91 -> V_157 ; V_90 ++ )
F_22 ( V_2 ) ;
V_91 -> V_158 = 0xffffffff ;
V_91 -> V_157 = 0 ;
}
if ( V_91 -> V_159 ) {
for ( V_90 = 0 ; V_90 < V_91 -> V_159 ; V_90 ++ )
F_27 ( V_2 ) ;
V_91 -> V_147 = 0xffffffff ;
V_91 -> V_159 = 0 ;
}
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_91 * V_91 ,
struct V_93 * V_141 )
{
struct V_75 * V_76 ;
struct V_160 * V_161 ;
struct V_142 * V_143 ;
T_2 V_136 ;
V_161 = F_37 ( V_91 -> V_162 ) ;
V_76 = F_38 ( V_161 -> V_163 . V_164 ) ;
if ( V_91 -> V_165 ) {
F_31 ( V_2 , V_141 , V_91 , V_161 -> V_139 ,
V_161 -> V_143 ) ;
} else {
V_143 = V_91 -> V_154 ;
V_136 = F_32 ( V_2 -> V_79 -> V_80 , F_33 ( V_143 ) ,
V_143 -> V_138 , V_143 -> V_137 , V_166 ) ;
}
F_35 ( V_2 , V_91 ) ;
if ( V_161 -> V_163 . V_167 != NULL )
V_161 -> V_163 . V_167 ( & V_161 -> V_163 , 0 ) ;
return 0 ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_91 * V_91 )
{
struct V_75 * V_76 ;
struct V_168 * V_169 ;
V_169 = F_40 ( V_91 -> V_162 ) ;
V_76 = F_38 ( V_169 -> V_163 . V_164 ) ;
F_34 ( V_91 ,
F_38 ( V_169 -> V_163 . V_164 ) ) ;
F_35 ( V_2 , V_91 ) ;
if ( V_169 -> V_163 . V_167 != NULL )
V_169 -> V_163 . V_167 ( & V_169 -> V_163 , 0 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_1 * V_2 , T_1 V_109 )
{
struct V_93 * V_141 ;
struct V_91 * V_91 ;
V_141 = V_2 -> V_92 + sizeof( struct V_93 ) * V_109 ;
V_91 = V_2 -> V_94 + sizeof( struct V_91 ) * V_109 ;
if ( F_42 ( V_91 -> V_162 -> V_164 ) ==
V_170 )
return F_36 ( V_2 , V_91 , V_141 ) ;
else
return F_39 ( V_2 , V_91 ) ;
}
void F_43 ( unsigned int * V_143 ,
const unsigned char * V_171 ,
int V_140 )
{
T_3 * V_105 ;
for (; V_140 >= 4 ; V_171 += 4 , V_140 -= 4 )
* V_143 ++ = F_44 ( * ( unsigned int * ) V_171 ) ;
V_105 = ( T_3 * ) V_143 ;
switch ( V_140 ) {
case 3 :
* V_105 ++ = 0 ;
* V_105 ++ = * ( V_171 + 2 ) ;
* V_105 ++ = * ( V_171 + 1 ) ;
* V_105 ++ = * V_171 ;
break;
case 2 :
* V_105 ++ = 0 ;
* V_105 ++ = 0 ;
* V_105 ++ = * ( V_171 + 1 ) ;
* V_105 ++ = * V_171 ;
break;
case 1 :
* V_105 ++ = 0 ;
* V_105 ++ = 0 ;
* V_105 ++ = 0 ;
* V_105 ++ = * V_171 ;
break;
default:
break;
}
}
static void F_45 ( struct V_172 * V_79 )
{
F_12 ( V_79 -> V_2 ) ;
F_20 ( V_79 -> V_2 ) ;
F_25 ( V_79 -> V_2 ) ;
F_46 ( V_79 -> V_80 , NULL ) ;
F_47 ( V_79 -> V_2 -> V_15 ) ;
F_13 ( V_79 -> V_2 ) ;
F_13 ( V_79 ) ;
}
void F_48 ( struct V_1 * V_2 ,
T_1 V_173 , struct V_93 * V_141 ,
struct V_91 * V_91 )
{
V_2 -> V_106 = V_173 ;
V_141 -> V_174 . V_17 = 0 ;
V_141 -> V_175 . V_17 = 0 ;
V_91 -> V_113 = V_114 ;
}
static int F_49 ( struct V_142 * V_176 , int V_139 )
{
struct V_142 * V_146 = V_176 ;
int V_177 = 0 ;
while ( V_139 ) {
V_177 ++ ;
if ( V_146 -> V_137 > V_139 )
break;
V_139 -= V_146 -> V_137 ;
V_146 = F_50 ( V_146 ) ;
}
return V_177 ;
}
static T_1 F_51 ( T_1 V_178 )
{
if ( V_178 != V_122 )
return V_178 + 1 ;
else
return 0 ;
}
static T_1 F_52 ( T_1 V_178 )
{
if ( V_178 != V_134 )
return V_178 + 1 ;
else
return 0 ;
}
T_1 F_53 ( struct V_179 * V_180 ,
struct V_75 * V_76 ,
struct V_142 * V_181 ,
struct V_142 * V_143 ,
unsigned int V_182 ,
void * V_183 , T_1 V_184 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
T_2 V_136 , V_115 , V_135 , V_123 ;
struct V_149 * V_150 ;
struct V_142 * V_146 ;
struct V_117 * V_185 ;
struct V_93 * V_141 ;
T_1 V_157 , V_159 ;
T_1 V_186 = 0xffffffff ;
T_1 V_187 = 0xffffffff ;
T_1 V_173 ;
unsigned long V_110 ;
struct V_91 * V_91 = NULL ;
unsigned int V_139 = V_182 , V_109 ;
unsigned int V_188 = 0 ;
T_1 V_189 = 0 ;
V_157 = F_49 ( V_181 , V_182 ) ;
if ( V_157 == 1 )
V_157 = 0 ;
if ( F_54 ( V_143 ) || V_76 -> V_190 ) {
V_159 = 0 ;
} else {
if ( V_182 > V_53 ) {
V_159 = V_182 / V_53 ;
if ( V_182 % V_53 )
V_159 ++ ;
} else {
V_159 = 1 ;
}
}
F_16 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
if ( V_157 ) {
V_186 = F_21 ( V_2 , V_157 ) ;
if ( V_186 == V_108 ) {
F_17 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
return - V_191 ;
}
}
if ( V_159 ) {
V_187 = F_26 ( V_2 , V_159 ) ;
if ( V_187 == V_108 ) {
if ( V_157 )
V_2 -> V_120 = V_186 ;
F_17 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
return - V_191 ;
}
}
V_173 = F_14 ( V_2 ) ;
if ( V_173 == V_108 ) {
if ( V_157 )
V_2 -> V_120 = V_186 ;
if ( V_159 )
V_2 -> V_132 = V_187 ;
F_17 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
return - V_191 ;
}
F_17 ( & V_2 -> V_79 -> V_111 , V_110 ) ;
V_91 = (struct V_91 * ) ( V_2 -> V_94 +
sizeof( struct V_91 ) * V_173 ) ;
V_141 = F_18 ( V_2 , & V_115 , V_173 ) ;
V_91 -> V_162 = V_180 ;
V_91 -> V_157 = V_157 ;
V_91 -> V_159 = V_159 ;
if ( V_184 || V_76 -> V_190 ) {
V_188 = V_184 ;
V_141 -> V_150 = V_91 -> V_101 ;
V_150 = (struct V_149 * ) V_91 -> V_100 ;
if ( V_76 -> V_192 == V_193 )
memcpy ( V_150 , V_76 -> V_78 , V_76 -> V_86 * 4 ) ;
else
memcpy ( V_150 , V_76 -> V_84 , V_76 -> V_86 * 4 ) ;
memcpy ( ( void * ) V_150 + V_76 -> V_194 ,
& V_91 -> V_103 , 4 ) ;
if ( V_184 )
F_43 ( V_91 -> V_102 , V_183 , V_184 ) ;
} else {
if ( V_76 -> V_192 == V_193 ) {
V_141 -> V_150 = V_76 -> V_81 ;
V_150 = (struct V_149 * ) V_76 -> V_78 ;
} else {
V_141 -> V_150 = V_76 -> V_85 ;
V_150 = (struct V_149 * ) V_76 -> V_84 ;
}
}
V_141 -> V_86 = V_76 -> V_86 ;
if ( V_157 ) {
V_189 = V_186 ;
V_91 -> V_158 = V_186 ;
V_91 -> V_157 = V_157 ;
V_185 = F_23 ( V_2 , & V_123 , V_189 ) ;
V_141 -> V_181 = V_123 ;
V_150 -> V_151 . V_18 . V_195 = 1 ;
V_109 = 0 ;
V_181 = & V_181 [ 0 ] ;
while ( V_139 ) {
V_146 = & V_181 [ V_109 ] ;
V_136 = F_32 ( V_2 -> V_79 -> V_80 , F_33 ( V_146 ) ,
V_146 -> V_138 , V_146 -> V_137 , V_148 ) ;
V_185 -> V_131 = V_136 ;
V_185 -> V_196 . V_140 = V_146 -> V_137 ;
V_185 -> V_196 . V_197 = 0 ;
V_185 -> V_196 . V_198 = 1 ;
if ( V_146 -> V_137 >= V_139 )
break;
V_139 -= V_146 -> V_137 ;
V_189 = F_51 ( V_189 ) ;
V_185 = F_23 ( V_2 , & V_123 , V_189 ) ;
V_109 ++ ;
}
} else {
V_141 -> V_181 = ( T_1 ) F_32 ( V_2 -> V_79 -> V_80 , F_33 ( V_181 ) ,
V_181 -> V_138 , V_181 -> V_137 , V_148 ) ;
V_150 -> V_151 . V_18 . V_195 = 0 ;
V_91 -> V_158 = 0xffffffff ;
V_91 -> V_157 = 0 ;
}
if ( V_76 -> V_190 || F_54 ( V_143 ) ) {
V_91 -> V_165 = 0 ;
V_91 -> V_147 = 0xffffffff ;
V_91 -> V_159 = 0 ;
V_91 -> V_154 = V_143 ;
V_150 -> V_151 . V_18 . V_199 = 0 ;
if ( V_76 -> V_190 )
V_141 -> V_200 = F_55 ( ( void * ) V_143 ) ;
else
V_141 -> V_200 = ( T_1 ) F_32 ( V_2 -> V_79 -> V_80 ,
F_33 ( V_143 ) , V_143 -> V_138 ,
V_143 -> V_137 , V_148 ) ;
} else {
struct V_124 * V_201 = NULL ;
T_1 V_202 = V_187 ;
V_139 = V_182 ;
V_150 -> V_151 . V_18 . V_199 = 1 ;
V_91 -> V_165 = 1 ;
V_91 -> V_154 = V_143 ;
V_91 -> V_147 = V_187 ;
V_91 -> V_159 = V_159 ;
V_201 = F_28 ( V_2 , & V_135 , V_202 ) ;
V_141 -> V_200 = V_135 ;
V_201 -> V_203 . V_197 = 0 ;
V_201 -> V_203 . V_204 = 1 ;
V_109 = 0 ;
if ( V_139 >= V_53 )
V_139 -= V_53 ;
else
V_139 = 0 ;
while ( V_139 ) {
V_202 = F_52 ( V_202 ) ;
V_201 = F_28 ( V_2 , & V_135 , V_202 ) ;
V_201 -> V_203 . V_197 = 0 ;
V_201 -> V_203 . V_204 = 1 ;
if ( V_139 >= V_53 )
V_139 -= V_53 ;
else
V_139 = 0 ;
}
}
V_150 -> V_205 . V_18 . V_206 = 0 ;
V_141 -> V_174 . V_17 = V_76 -> V_174 ;
V_141 -> V_175 . V_17 = 0x00400000 | ( V_76 -> V_207 << 24 ) | V_182 ;
V_91 -> V_113 = V_208 ;
F_56 () ;
F_2 ( 1 , V_2 -> V_15 + V_209 ) ;
return - V_210 ;
}
static int F_57 ( struct V_211 * V_164 )
{
struct V_212 * V_213 = V_164 -> V_214 ;
struct V_215 * V_216 = F_58 ( V_213 ) ;
struct V_75 * V_76 = F_38 ( V_164 ) ;
V_76 -> V_2 = V_216 -> V_2 ;
V_76 -> V_78 = NULL ;
V_76 -> V_84 = NULL ;
V_76 -> V_81 = 0 ;
V_76 -> V_85 = 0 ;
V_76 -> V_86 = 0 ;
switch ( V_213 -> V_217 & V_218 ) {
default:
V_164 -> V_219 . V_220 = sizeof( struct V_75 ) ;
break;
case V_221 :
F_59 ( F_60 ( V_164 ) ,
sizeof( struct V_75 ) ) ;
break;
}
return 0 ;
}
static void F_61 ( struct V_211 * V_164 )
{
struct V_75 * V_76 = F_38 ( V_164 ) ;
F_7 ( V_76 ) ;
F_9 ( V_76 ) ;
}
int F_62 ( struct V_1 * V_222 ,
struct V_223 * V_212 ,
int V_224 )
{
struct V_215 * V_213 ;
int V_90 ;
int V_225 = 0 ;
for ( V_90 = 0 ; V_90 < V_224 ; V_90 ++ ) {
V_213 = F_11 ( sizeof( struct V_215 ) , V_95 ) ;
if ( ! V_213 )
return - V_83 ;
V_213 -> V_213 = V_212 [ V_90 ] ;
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
F_13 ( V_213 ) ;
} else {
F_66 ( & V_213 -> V_229 , & V_222 -> V_230 ) ;
}
}
return 0 ;
}
static void F_67 ( struct V_1 * V_222 )
{
struct V_215 * V_213 , * V_105 ;
F_68 (alg, tmp, &sec_dev->alg_list, entry) {
F_65 ( & V_213 -> V_229 ) ;
switch ( V_213 -> V_213 . type ) {
case V_221 :
F_69 ( & V_213 -> V_213 . V_226 . V_227 ) ;
break;
default:
F_70 ( & V_213 -> V_213 . V_226 . V_228 ) ;
}
F_13 ( V_213 ) ;
}
}
static void F_71 ( unsigned long V_231 )
{
struct V_80 * V_2 = (struct V_80 * ) V_231 ;
struct V_172 * V_79 = F_72 ( V_2 ) ;
struct V_91 * V_91 ;
struct V_93 * V_141 ;
T_1 V_232 ;
while ( V_79 -> V_2 -> V_106 != V_79 -> V_2 -> V_107 ) {
V_232 = V_79 -> V_2 -> V_107 ;
V_91 = V_79 -> V_2 -> V_94 +
sizeof( struct V_91 ) * V_232 ;
V_141 = V_79 -> V_2 -> V_92 + sizeof( struct V_93 ) * V_232 ;
if ( ( V_91 -> V_113 == V_208 ) &&
V_141 -> V_174 . V_18 . V_233 &&
! V_141 -> V_174 . V_18 . V_234 ) {
V_141 -> V_174 . V_18 . V_233 = 0 ;
F_41 ( V_79 -> V_2 , V_232 ) ;
F_15 ( V_79 -> V_2 , V_232 ) ;
V_91 -> V_113 = V_114 ;
} else {
break;
}
}
}
static T_4 F_73 ( int V_235 , void * V_231 )
{
struct V_80 * V_2 = (struct V_80 * ) V_231 ;
struct V_172 * V_79 = F_72 ( V_2 ) ;
if ( V_79 -> V_2 -> V_15 == 0 )
return 0 ;
F_2 ( V_67 ,
V_79 -> V_2 -> V_15 + V_68 ) ;
F_74 ( & V_79 -> V_236 ) ;
return V_237 ;
}
static int T_5 F_75 ( struct V_238 * V_239 )
{
int V_225 ;
struct V_240 V_241 ;
struct V_80 * V_2 = & V_239 -> V_2 ;
struct V_172 * V_79 ;
V_225 = F_76 ( V_239 -> V_2 . V_242 , 0 , & V_241 ) ;
if ( V_225 )
return - V_243 ;
if ( F_77 ( NULL , NULL , L_1 ) ) {
F_78 ( V_244 , V_245 ,
F_79 ( V_244 , V_245 ) | V_246 ) ;
F_78 ( V_244 , V_245 ,
F_79 ( V_244 , V_245 ) & ~ V_246 ) ;
} else if ( F_77 ( NULL , NULL ,
L_2 ) ) {
F_78 ( V_244 , V_247 ,
F_79 ( V_244 , V_247 ) | V_248 ) ;
F_78 ( V_244 , V_247 ,
F_79 ( V_244 , V_247 ) & ~ V_248 ) ;
} else if ( F_77 ( NULL , NULL ,
L_3 ) ) {
F_78 ( V_244 , V_249 ,
F_79 ( V_244 , V_249 ) | V_250 ) ;
F_78 ( V_244 , V_249 ,
F_79 ( V_244 , V_249 ) & ~ V_250 ) ;
} else {
F_80 ( V_251 L_4 ) ;
return - V_252 ;
}
V_79 = F_11 ( sizeof( struct V_172 ) , V_95 ) ;
if ( ! V_79 )
return - V_83 ;
F_46 ( V_2 , V_79 ) ;
V_79 -> V_239 = V_239 ;
V_79 -> V_2 = F_11 ( sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_79 -> V_2 )
goto V_253;
V_79 -> V_2 -> V_79 = V_79 ;
V_79 -> V_80 = V_2 ;
F_81 ( & V_79 -> V_111 ) ;
F_82 ( & V_79 -> V_2 -> V_230 ) ;
V_225 = F_10 ( V_79 -> V_2 ) ;
if ( V_225 )
goto V_254;
V_225 = F_19 ( V_79 -> V_2 ) ;
if ( V_225 )
goto V_255;
V_225 = F_24 ( V_79 -> V_2 ) ;
if ( V_225 )
goto V_256;
F_83 ( & V_79 -> V_236 , F_71 ,
( unsigned long ) V_2 ) ;
V_79 -> V_235 = F_84 ( V_239 -> V_2 . V_242 , 0 ) ;
V_225 = F_85 ( V_79 -> V_235 , F_73 , 0 ,
V_79 -> V_2 -> V_257 , V_2 ) ;
if ( V_225 )
goto V_258;
V_79 -> V_2 -> V_15 = F_86 ( V_239 -> V_2 . V_242 , 0 ) ;
if ( ! V_79 -> V_2 -> V_15 ) {
F_87 ( V_2 , L_5 ) ;
goto V_259;
}
F_1 ( V_79 -> V_2 ) ;
V_225 = F_62 ( V_79 -> V_2 , V_215 ,
F_88 ( V_215 ) ) ;
if ( V_225 )
goto V_260;
return 0 ;
V_260:
F_47 ( V_79 -> V_2 -> V_15 ) ;
V_259:
F_89 ( V_79 -> V_235 , V_2 ) ;
F_90 ( V_79 -> V_235 ) ;
F_91 ( & V_79 -> V_236 ) ;
V_258:
F_25 ( V_79 -> V_2 ) ;
V_256:
F_20 ( V_79 -> V_2 ) ;
V_255:
F_12 ( V_79 -> V_2 ) ;
V_254:
F_13 ( V_79 -> V_2 ) ;
V_253:
F_13 ( V_79 ) ;
return V_225 ;
}
static int T_6 F_92 ( struct V_238 * V_239 )
{
struct V_80 * V_2 = & V_239 -> V_2 ;
struct V_172 * V_79 = F_72 ( V_2 ) ;
F_89 ( V_79 -> V_235 , V_2 ) ;
F_90 ( V_79 -> V_235 ) ;
F_91 ( & V_79 -> V_236 ) ;
F_67 ( V_79 -> V_2 ) ;
F_45 ( V_79 ) ;
return 0 ;
}
static int T_5 F_93 ( void )
{
return F_94 ( & V_261 ) ;
}
static void T_6 F_95 ( void )
{
F_96 ( & V_261 ) ;
}
