static char * F_1 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 != NULL ; V_2 ++ )
if ( V_3 [ V_2 ] . V_1 == V_1 )
break;
return V_3 [ V_2 ] . V_4 ;
}
static void F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 == NULL )
return;
F_4 ( V_8 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
T_1 V_9 = & ( V_8 -> V_10 ) ;
V_9 -> V_11 = V_12 ;
V_9 -> V_13 = V_14 ;
V_9 -> V_15 [ 0 ] = V_16 ;
V_9 -> V_15 [ 1 ] = V_17 ;
V_9 -> V_18 = V_19 ;
V_9 -> V_20 = V_21 ;
V_9 -> V_22 = V_23 ;
V_9 -> V_24 = V_25 ;
}
static void
F_6 ( struct V_7 * V_8 )
{
V_8 -> V_26 = V_8 -> V_10 . V_20 ;
V_8 -> V_27 = V_8 -> V_10 . V_22 ;
V_8 -> V_28 = V_8 -> V_10 . V_24 ;
V_8 -> V_29 = V_8 -> V_28 ;
V_8 -> V_30 = V_31 ;
V_8 -> V_32 = true ;
V_8 -> V_33 = 0 ;
F_7 ( L_1 , ( int ) V_8 -> V_26 ) ;
F_7 ( L_2 , ( int ) V_8 -> V_27 ) ;
F_7 ( L_3 , ( int ) V_8 -> V_33 ) ;
F_7 ( L_4 , ( int ) V_8 -> V_34 ) ;
F_7 ( L_5 , ( int ) V_8 -> V_28 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
unsigned long V_35 ;
unsigned int V_36 ;
unsigned char V_37 ;
unsigned char V_38 = 0 ;
unsigned char V_39 = 0 ;
F_9 ( V_8 -> V_40 ) ;
F_10 ( V_8 ) ;
F_11 ( V_8 -> V_40 ) ;
V_8 -> V_41 = false ;
V_8 -> V_42 = false ;
V_8 -> V_43 = false ;
V_8 -> V_44 = false ;
V_8 -> V_45 = V_46 ;
V_8 -> V_47 = V_48 ;
V_8 -> V_49 = V_46 ;
V_8 -> V_50 = 0 ;
F_12 ( V_8 -> V_40 ) ;
F_13 ( V_8 -> V_40 + V_51 , & V_8 -> V_52 ) ;
F_14 ( & V_8 -> V_53 , V_35 ) ;
F_15 ( V_8 -> V_40 , V_8 -> V_54 ) ;
F_16 ( & V_8 -> V_53 , V_35 ) ;
V_8 -> V_55 = 1 ;
V_8 -> V_56 = V_57 ;
V_37 = F_17 ( V_8 -> V_40 , V_58 ) ;
if ( V_37 & V_59 )
V_8 -> V_60 = true ;
else
V_8 -> V_60 = false ;
V_37 &= ( V_61 | V_62 ) ;
if ( V_37 == 0 )
V_37 = ( V_61 | V_62 ) ;
if ( V_37 == ( V_61 | V_62 ) ) {
V_8 -> V_63 = 2 ;
V_8 -> V_64 = V_65 ;
V_8 -> V_66 = 1 ;
V_8 -> V_67 = 1 ;
if ( V_8 -> V_60 )
V_8 -> V_68 = V_69 ;
else
V_8 -> V_68 = V_65 ;
} else {
V_8 -> V_63 = 1 ;
V_8 -> V_66 = 0 ;
V_8 -> V_67 = 0 ;
if ( V_37 & V_61 ) {
V_8 -> V_64 = V_69 ;
if ( V_8 -> V_60 )
V_8 -> V_68 = V_65 ;
else
V_8 -> V_68 = V_69 ;
} else {
V_8 -> V_64 = V_65 ;
if ( V_8 -> V_60 )
V_8 -> V_68 = V_69 ;
else
V_8 -> V_68 = V_65 ;
}
}
F_18 ( V_8 , V_8 -> V_64 ) ;
F_19 ( V_8 , V_8 -> V_68 ) ;
V_8 -> V_70 = V_8 -> V_54 [ V_71 ] ;
if ( ! V_8 -> V_72 )
V_8 -> V_73 = V_8 -> V_54 [ V_71 ] ;
F_7 ( L_6 , V_8 -> V_73 ) ;
F_20 ( V_8 ) ;
V_8 -> V_74 = 0xFF ;
V_8 -> V_75 = F_17 ( V_8 -> V_40 , V_76 ) ;
V_8 -> V_77 = F_17 ( V_8 -> V_40 , V_78 ) ;
for ( V_36 = 0 ; V_36 < V_79 ; V_36 ++ ) {
V_8 -> V_80 [ V_36 + 1 ] =
F_17 ( V_8 -> V_40 ,
( unsigned char ) ( V_36 + V_81 ) ) ;
if ( V_8 -> V_80 [ V_36 + 1 ] == 0 )
V_8 -> V_80 [ V_36 + 1 ] = V_8 -> V_75 ;
V_8 -> V_82 [ V_36 + 1 ] =
F_17 ( V_8 -> V_40 ,
( unsigned char ) ( V_36 + V_83 ) ) ;
if ( V_8 -> V_82 [ V_36 + 1 ] == 0 )
V_8 -> V_82 [ V_36 + 1 ] = V_8 -> V_77 ;
V_8 -> V_84 [ V_36 + 1 ] = V_38 ;
V_8 -> V_85 [ V_36 + 1 ] = V_39 ;
}
for ( V_36 = 11 ; V_36 < 14 ; V_36 ++ ) {
V_8 -> V_80 [ V_36 ] = V_8 -> V_80 [ 10 ] ;
V_8 -> V_82 [ V_36 ] = V_8 -> V_82 [ 10 ] ;
}
for ( V_36 = 0 ; V_36 < V_86 ; V_36 ++ ) {
V_8 -> V_82 [ V_36 + V_79 + 1 ] =
F_17 ( V_8 -> V_40 ,
( unsigned char ) ( V_36 + V_87 ) ) ;
V_8 -> V_85 [ V_36 + V_79 + 1 ] =
F_17 ( V_8 -> V_40 ,
( unsigned char ) ( V_36 + V_88 ) ) ;
}
if ( V_8 -> V_52 > V_89 ) {
F_21 ( V_8 -> V_40 ) ;
F_22 ( V_8 -> V_40 + V_90 + 1 ,
( V_91 | V_92 ) ) ;
F_23 ( V_8 -> V_40 ) ;
}
F_24 ( V_8 -> V_40 ,
V_93 , ( V_94 | V_95 ) ) ;
F_25 ( V_8 -> V_40 , V_8 -> V_26 ) ;
F_26 ( V_8 -> V_40 , V_8 -> V_27 ) ;
F_22 ( V_8 -> V_40 + V_96 , V_97 ) ;
F_22 ( V_8 -> V_40 + V_96 , V_98 ) ;
F_27 ( V_8 ) ;
if ( V_8 -> V_32 ) {
V_8 -> V_99 = V_8 -> V_100 [ 0 ] ;
V_8 -> V_101 = V_8 -> V_99 ;
F_28 ( V_8 , V_8 -> V_100 [ 0 ] ) ;
}
F_19 ( V_8 , V_8 -> V_68 ) ;
F_18 ( V_8 , V_8 -> V_64 ) ;
V_8 -> V_45 = V_102 ;
V_8 -> V_103 = false ;
V_8 -> V_104 = F_17 ( V_8 -> V_40 ,
V_105 ) ;
V_8 -> V_106 = false ;
if ( V_8 -> V_104 & V_107 ) {
F_29 ( V_8 -> V_40 , & V_8 -> V_108 ) ;
if ( ( ( V_8 -> V_108 & V_109 ) &&
! ( V_8 -> V_104 & V_110 ) ) ||
( ! ( V_8 -> V_108 & V_109 ) &&
( V_8 -> V_104 & V_110 ) ) )
V_8 -> V_106 = true ;
}
if ( V_8 -> V_106 || V_8 -> V_111 )
F_30 ( V_8 ) ;
F_31 ( V_8 -> V_40 , V_8 -> V_112 ) ;
F_7 ( L_7 , V_8 -> V_112 ) ;
F_32 ( V_8 ) ;
F_33 ( V_8 ) ;
if ( V_8 -> V_52 <= V_113 )
F_34 ( V_8 -> V_40 , V_114 , V_115 ) ;
F_35 ( V_8 -> V_40 ) ;
F_36 ( V_8 -> V_40 ) ;
F_37 ( V_8 -> V_40 ) ;
}
static void F_38 ( struct V_7 * V_8 )
{
F_39 ( & V_8 -> V_6 -> V_116 , L_8 , F_1 ( V_8 -> V_1 ) ) ;
F_39 ( & V_8 -> V_6 -> V_116 , L_9 ,
V_8 -> V_112 , ( unsigned long ) V_8 -> V_117 ,
( unsigned long ) V_8 -> V_40 , V_8 -> V_6 -> V_118 ) ;
}
static void F_40 ( struct V_5 * V_6 ,
struct V_7 * * V_119 ,
T_2 V_120 )
{
memset ( * V_119 , 0 , sizeof( * * V_119 ) ) ;
( * V_119 ) -> V_6 = V_6 ;
( * V_119 ) -> V_1 = V_120 -> V_1 ;
( * V_119 ) -> V_121 = V_120 -> V_121 ;
( * V_119 ) -> V_122 = V_120 -> V_123 ;
( * V_119 ) -> V_124 = 32 ;
F_41 ( & ( ( * V_119 ) -> V_53 ) ) ;
}
static bool F_42 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
T_3 V_125 ;
T_4 V_126 ;
unsigned int V_127 ;
F_43 ( V_6 , V_128 , & V_8 -> V_50 ) ;
F_44 ( V_6 , V_129 , & V_8 -> V_130 ) ;
F_44 ( V_6 , V_131 , & V_8 -> V_132 ) ;
F_44 ( V_6 , V_133 , ( T_3 * ) & ( V_125 ) ) ;
F_45 ( V_6 ) ;
V_8 -> V_134 = F_46 ( V_6 , 0 ) ;
V_8 -> V_117 = F_46 ( V_6 , 1 ) ;
V_127 = F_46 ( V_6 , 2 ) ;
V_8 -> V_6 = V_6 ;
F_43 ( V_6 , V_133 , & V_126 ) ;
F_47 ( V_6 , V_133 , ( V_126 | V_135 ) ) ;
return true ;
}
static void F_4 ( struct V_7 * V_8 )
{
if ( ! V_8 )
return;
if ( V_8 -> V_136 )
F_48 ( V_8 -> V_137 ) ;
if ( V_8 -> V_40 )
F_49 ( V_8 -> V_40 ) ;
if ( V_8 -> V_6 )
F_50 ( V_8 -> V_6 ) ;
if ( V_8 -> V_137 )
F_51 ( V_8 -> V_137 ) ;
}
static bool F_52 ( struct V_7 * V_8 )
{
void * V_138 ;
V_138 = F_53 ( & V_8 -> V_6 -> V_116 ,
V_8 -> V_10 . V_11 * sizeof( V_139 ) +
V_8 -> V_10 . V_13 * sizeof( V_139 ) +
V_8 -> V_10 . V_15 [ 0 ] * sizeof( V_140 ) +
V_8 -> V_10 . V_15 [ 1 ] * sizeof( V_140 ) ,
& V_8 -> V_141 , V_142 ) ;
if ( V_138 == NULL ) {
F_54 ( & V_8 -> V_6 -> V_116 , L_10 ) ;
return false ;
}
V_8 -> V_143 = V_138 ;
V_8 -> V_144 = V_138 +
V_8 -> V_10 . V_11 * sizeof( V_139 ) ;
V_8 -> V_145 = V_8 -> V_141 ;
V_8 -> V_146 = V_8 -> V_145 +
V_8 -> V_10 . V_11 * sizeof( V_139 ) ;
V_8 -> V_147 = F_53 ( & V_8 -> V_6 -> V_116 ,
V_8 -> V_10 . V_15 [ 0 ] * V_148 +
V_8 -> V_10 . V_15 [ 1 ] * V_148 +
V_149 +
V_150 ,
& V_8 -> V_151 ,
V_142 ) ;
if ( V_8 -> V_147 == NULL ) {
F_54 ( & V_8 -> V_6 -> V_116 , L_11 ) ;
F_55 ( & V_8 -> V_6 -> V_116 ,
V_8 -> V_10 . V_11 * sizeof( V_139 ) +
V_8 -> V_10 . V_13 * sizeof( V_139 ) +
V_8 -> V_10 . V_15 [ 0 ] * sizeof( V_140 ) +
V_8 -> V_10 . V_15 [ 1 ] * sizeof( V_140 ) ,
V_138 , V_8 -> V_141
) ;
return false ;
}
V_8 -> V_152 = V_8 -> V_146 +
V_8 -> V_10 . V_13 * sizeof( V_139 ) ;
V_8 -> V_153 = V_8 -> V_152 +
V_8 -> V_10 . V_15 [ 0 ] * sizeof( V_140 ) ;
V_8 -> V_154 = V_138
+ V_8 -> V_10 . V_11 * sizeof( V_139 )
+ V_8 -> V_10 . V_13 * sizeof( V_139 ) ;
V_8 -> V_155 = V_138
+ V_8 -> V_10 . V_11 * sizeof( V_139 )
+ V_8 -> V_10 . V_13 * sizeof( V_139 )
+ V_8 -> V_10 . V_15 [ 0 ] * sizeof( V_140 ) ;
V_8 -> V_156 = V_8 -> V_147 +
V_8 -> V_10 . V_15 [ 0 ] * V_148 ;
V_8 -> V_157 = V_8 -> V_156 +
V_8 -> V_10 . V_15 [ 1 ] * V_148 ;
V_8 -> V_158 = V_8 -> V_157 +
V_149 ;
V_8 -> V_159 = V_8 -> V_151 +
V_8 -> V_10 . V_15 [ 0 ] * V_148 ;
V_8 -> V_160 = V_8 -> V_159 +
V_8 -> V_10 . V_15 [ 1 ] * V_148 ;
return true ;
}
static void F_56 ( struct V_7 * V_8 )
{
F_55 ( & V_8 -> V_6 -> V_116 ,
V_8 -> V_10 . V_11 * sizeof( V_139 ) +
V_8 -> V_10 . V_13 * sizeof( V_139 ) +
V_8 -> V_10 . V_15 [ 0 ] * sizeof( V_140 ) +
V_8 -> V_10 . V_15 [ 1 ] * sizeof( V_140 )
,
V_8 -> V_143 , V_8 -> V_141
) ;
if ( V_8 -> V_147 )
F_55 ( & V_8 -> V_6 -> V_116 ,
V_8 -> V_10 . V_15 [ 0 ] * V_148 +
V_8 -> V_10 . V_15 [ 1 ] * V_148 +
V_149 +
V_150 ,
V_8 -> V_147 , V_8 -> V_151
) ;
}
static void F_57 ( struct V_7 * V_8 )
{
int V_2 ;
T_5 V_161 = V_8 -> V_145 ;
T_6 V_162 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_10 . V_11 ; V_2 ++ , V_161 += sizeof( V_139 ) ) {
V_162 = & ( V_8 -> V_143 [ V_2 ] ) ;
V_162 -> V_163 = F_58 () ;
ASSERT ( V_162 -> V_163 ) ;
if ( ! F_59 ( V_8 , V_162 ) )
F_54 ( & V_8 -> V_6 -> V_116 , L_12 ) ;
V_162 -> V_164 = & ( V_8 -> V_143 [ ( V_2 + 1 ) % V_8 -> V_10 . V_11 ] ) ;
V_162 -> V_163 -> V_165 = F_60 ( V_161 ) ;
V_162 -> V_166 = F_60 ( V_161 + sizeof( V_139 ) ) ;
}
if ( V_2 > 0 )
V_8 -> V_143 [ V_2 - 1 ] . V_166 = F_60 ( V_8 -> V_145 ) ;
V_8 -> V_167 [ 0 ] = & ( V_8 -> V_143 [ 0 ] ) ;
}
static void F_61 ( struct V_7 * V_8 )
{
int V_2 ;
T_5 V_161 = V_8 -> V_146 ;
T_6 V_162 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_10 . V_13 ; V_2 ++ , V_161 += sizeof( V_139 ) ) {
V_162 = & ( V_8 -> V_144 [ V_2 ] ) ;
V_162 -> V_163 = F_58 () ;
ASSERT ( V_162 -> V_163 ) ;
if ( ! F_59 ( V_8 , V_162 ) )
F_54 ( & V_8 -> V_6 -> V_116 , L_12 ) ;
V_162 -> V_164 = & ( V_8 -> V_144 [ ( V_2 + 1 ) % V_8 -> V_10 . V_13 ] ) ;
V_162 -> V_163 -> V_165 = F_60 ( V_161 ) ;
V_162 -> V_166 = F_60 ( V_161 + sizeof( V_139 ) ) ;
}
if ( V_2 > 0 )
V_8 -> V_144 [ V_2 - 1 ] . V_166 = F_60 ( V_8 -> V_146 ) ;
V_8 -> V_167 [ 1 ] = & ( V_8 -> V_144 [ 0 ] ) ;
}
static void F_62 ( struct V_7 * V_8 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_10 . V_11 ; V_2 ++ ) {
T_6 V_162 = & ( V_8 -> V_143 [ V_2 ] ) ;
T_7 V_163 = V_162 -> V_163 ;
F_63 ( & V_8 -> V_6 -> V_116 , V_163 -> V_168 ,
V_8 -> V_169 , V_170 ) ;
F_64 ( V_163 -> V_171 ) ;
F_65 ( V_162 -> V_163 ) ;
}
}
static void F_66 ( struct V_7 * V_8 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_10 . V_13 ; V_2 ++ ) {
T_6 V_162 = & ( V_8 -> V_144 [ V_2 ] ) ;
T_7 V_163 = V_162 -> V_163 ;
F_63 ( & V_8 -> V_6 -> V_116 , V_163 -> V_168 ,
V_8 -> V_169 , V_170 ) ;
F_64 ( V_163 -> V_171 ) ;
F_65 ( V_162 -> V_163 ) ;
}
}
static void F_67 ( struct V_7 * V_8 )
{
int V_2 ;
T_5 V_161 ;
T_8 V_162 ;
V_161 = V_8 -> V_152 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_10 . V_15 [ 0 ] ; V_2 ++ , V_161 += sizeof( V_140 ) ) {
V_162 = & ( V_8 -> V_154 [ V_2 ] ) ;
V_162 -> V_172 = F_68 () ;
ASSERT ( V_162 -> V_172 ) ;
if ( V_8 -> V_35 & V_173 ) {
V_162 -> V_172 -> V_174 = V_8 -> V_147 + ( V_2 ) * V_148 ;
V_162 -> V_172 -> V_175 = V_8 -> V_151 + ( V_2 ) * V_148 ;
}
V_162 -> V_164 = & ( V_8 -> V_154 [ ( V_2 + 1 ) % V_8 -> V_10 . V_15 [ 0 ] ] ) ;
V_162 -> V_172 -> V_165 = F_60 ( V_161 ) ;
V_162 -> V_166 = F_60 ( V_161 + sizeof( V_140 ) ) ;
}
if ( V_2 > 0 )
V_8 -> V_154 [ V_2 - 1 ] . V_166 = F_60 ( V_8 -> V_152 ) ;
V_8 -> V_176 [ 0 ] = V_8 -> V_177 [ 0 ] = & ( V_8 -> V_154 [ 0 ] ) ;
}
static void F_69 ( struct V_7 * V_8 )
{
int V_2 ;
T_5 V_161 ;
T_8 V_162 ;
V_161 = V_8 -> V_153 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_10 . V_15 [ 1 ] ; V_2 ++ , V_161 += sizeof( V_140 ) ) {
V_162 = & ( V_8 -> V_155 [ V_2 ] ) ;
V_162 -> V_172 = F_68 () ;
ASSERT ( V_162 -> V_172 ) ;
if ( V_8 -> V_35 & V_173 ) {
V_162 -> V_172 -> V_174 = V_8 -> V_156 + ( V_2 ) * V_148 ;
V_162 -> V_172 -> V_175 = V_8 -> V_159 + ( V_2 ) * V_148 ;
}
V_162 -> V_164 = & ( V_8 -> V_155 [ ( V_2 + 1 ) % V_8 -> V_10 . V_15 [ 1 ] ] ) ;
V_162 -> V_172 -> V_165 = F_60 ( V_161 ) ;
V_162 -> V_166 = F_60 ( V_161 + sizeof( V_140 ) ) ;
}
if ( V_2 > 0 )
V_8 -> V_155 [ V_2 - 1 ] . V_166 = F_60 ( V_8 -> V_153 ) ;
V_8 -> V_176 [ 1 ] = V_8 -> V_177 [ 1 ] = & ( V_8 -> V_155 [ 0 ] ) ;
}
static void F_70 ( struct V_7 * V_8 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_10 . V_15 [ 0 ] ; V_2 ++ ) {
T_8 V_162 = & ( V_8 -> V_154 [ V_2 ] ) ;
T_9 V_172 = V_162 -> V_172 ;
if ( V_172 -> V_168 && ( V_172 -> V_168 != V_172 -> V_175 ) )
F_63 ( & V_8 -> V_6 -> V_116 , V_172 -> V_168 ,
V_172 -> V_171 -> V_178 , V_179 ) ;
if ( V_172 -> V_171 )
F_64 ( V_172 -> V_171 ) ;
F_65 ( V_162 -> V_172 ) ;
}
}
static void F_71 ( struct V_7 * V_8 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_10 . V_15 [ 1 ] ; V_2 ++ ) {
T_8 V_162 = & ( V_8 -> V_155 [ V_2 ] ) ;
T_9 V_172 = V_162 -> V_172 ;
if ( V_172 -> V_168 && ( V_172 -> V_168 != V_172 -> V_175 ) )
F_63 ( & V_8 -> V_6 -> V_116 , V_172 -> V_168 ,
V_172 -> V_171 -> V_178 , V_179 ) ;
if ( V_172 -> V_171 )
F_64 ( V_172 -> V_171 ) ;
F_65 ( V_162 -> V_172 ) ;
}
}
static int F_72 ( struct V_7 * V_8 , unsigned int V_180 )
{
T_6 V_181 ;
int V_182 = 0 ;
for ( V_181 = V_8 -> V_167 [ V_180 ] ;
V_181 -> V_183 . V_184 == V_185 ;
V_181 = V_181 -> V_164 ) {
if ( V_182 ++ > 15 )
break;
if ( F_73 ( V_8 , V_181 ) ) {
if ( ! F_59 ( V_8 , V_181 ) ) {
F_54 ( & V_8 -> V_6 -> V_116 ,
L_13 ) ;
break;
}
}
V_181 -> V_183 . V_184 = V_186 ;
}
V_8 -> V_167 [ V_180 ] = V_181 ;
return V_182 ;
}
static bool F_59 ( struct V_7 * V_8 , T_6 V_181 )
{
T_7 V_163 = V_181 -> V_163 ;
V_163 -> V_171 = F_74 ( ( int ) V_8 -> V_169 ) ;
if ( V_163 -> V_171 == NULL )
return false ;
ASSERT ( V_163 -> V_171 ) ;
V_163 -> V_168 =
F_75 ( & V_8 -> V_6 -> V_116 ,
F_76 ( V_163 -> V_171 , F_77 ( V_163 -> V_171 ) ) ,
V_8 -> V_169 , V_170 ) ;
* ( ( unsigned int * ) & ( V_181 -> V_183 ) ) = 0 ;
V_181 -> V_183 . V_187 = F_78 ( V_8 -> V_169 ) ;
V_181 -> V_183 . V_184 = V_186 ;
V_181 -> V_188 . V_189 = F_78 ( V_8 -> V_169 ) ;
V_181 -> V_190 = F_60 ( V_163 -> V_168 ) ;
return true ;
}
static int F_79 ( struct V_7 * V_191 ,
T_9 V_192 , T_4 V_193 , T_4 V_194 )
{
struct V_195 * V_196 ;
struct V_197 * V_198 ;
struct V_199 * V_200 ;
T_3 V_201 ;
T_4 V_202 = ( V_193 & V_203 ) ;
T_10 V_204 ;
if ( ! V_192 )
return - V_205 ;
if ( ! V_192 -> V_171 )
return - V_206 ;
V_196 = (struct V_195 * ) V_192 -> V_174 ;
V_201 = ( F_80 ( V_196 -> V_207 ) &
( V_208 | V_209 ) ) ;
V_198 = F_81 ( V_192 -> V_171 ) ;
V_204 = V_198 -> V_210 . V_211 [ 0 ] . V_204 ;
if ( V_201 && ! ( V_194 & V_212 ) ) {
T_4 V_213 ;
T_4 V_214 = V_202 ;
V_200 = F_82 ( V_191 -> V_137 , V_198 ) ;
V_213 = V_200 -> V_215 - V_216 ;
if ( V_214 > 4 )
V_214 = 4 ;
if ( V_201 & V_208 )
V_213 = V_217 [ V_213 ] [ V_214 ] ;
else if ( V_201 & V_209 )
V_213 = V_218 [ V_213 ] [ V_214 ] ;
if ( V_198 -> V_219 == V_220 )
V_204 = V_213 - V_221 ;
else
V_204 = V_213 ;
}
F_83 ( V_198 ) ;
V_198 -> V_222 . V_211 [ 0 ] . V_223 = V_202 ;
if ( ! ( V_194 & V_212 ) ) {
V_198 -> V_222 . V_211 [ 0 ] . V_204 = V_204 ;
if ( V_198 -> V_35 & V_224 )
V_198 -> V_35 |= V_225 ;
else
V_198 -> V_35 |= V_226 ;
}
return 0 ;
}
static int F_84 ( struct V_7 * V_8 , unsigned int V_180 )
{
T_8 V_227 ;
int V_182 = 0 ;
unsigned char V_228 ;
unsigned char V_229 ;
for ( V_227 = V_8 -> V_176 [ V_180 ] ; V_8 -> V_230 [ V_180 ] > 0 ; V_227 = V_227 -> V_164 ) {
if ( V_227 -> V_231 . V_184 == V_186 )
break;
if ( V_182 ++ > 15 )
break;
V_228 = V_227 -> V_231 . V_232 ;
V_229 = V_227 -> V_231 . V_233 ;
if ( V_227 -> V_234 . V_235 & V_236 ) {
if ( ( V_227 -> V_172 -> V_237 & V_238 ) != 0 ) {
if ( ! ( V_229 & V_212 ) ) {
if ( V_228 != 0 ) {
F_7 ( L_14 ,
( int ) V_180 , V_229 ,
V_228 ) ;
}
} else {
F_7 ( L_15 ,
( int ) V_180 , V_229 , V_228 ) ;
}
}
if ( V_229 & V_212 ) {
if ( ( V_227 -> V_172 -> V_237 & V_239 ) != 0 ) {
F_7 ( L_16 ,
( int ) V_180 , V_229 , V_228 ) ;
}
}
F_79 ( V_8 , V_227 -> V_172 , V_228 , V_229 ) ;
F_85 ( V_8 , V_227 ) ;
V_8 -> V_230 [ V_180 ] -- ;
}
}
V_8 -> V_176 [ V_180 ] = V_227 ;
return V_182 ;
}
static void F_86 ( struct V_7 * V_8 , unsigned short V_222 )
{
if ( V_222 & V_240 ) {
F_54 ( & V_8 -> V_6 -> V_116 , L_17 ) ;
F_9 ( V_8 -> V_40 ) ;
return;
}
}
static void F_85 ( struct V_7 * V_8 , T_8 V_162 )
{
T_9 V_172 = V_162 -> V_172 ;
struct V_241 * V_171 = V_172 -> V_171 ;
if ( V_172 -> V_168 && ( V_172 -> V_168 != V_172 -> V_175 ) ) {
F_63 ( & V_8 -> V_6 -> V_116 , V_172 -> V_168 ,
V_171 -> V_178 , V_179 ) ;
}
if ( V_171 )
F_87 ( V_8 -> V_137 , V_171 ) ;
V_172 -> V_168 = 0 ;
V_172 -> V_171 = NULL ;
V_172 -> V_237 = 0 ;
}
static void F_88 ( struct V_7 * V_191 )
{
long V_242 ;
int V_2 ;
if ( ! V_191 -> V_32 )
return;
if ( V_191 -> V_137 -> V_243 . V_35 & V_244 )
return;
if ( ! ( V_191 -> V_245 -> V_246 . V_247 && V_191 -> V_248 ) )
return;
F_89 ( V_191 , ( T_4 ) V_191 -> V_248 , & V_242 ) ;
for ( V_2 = 0 ; V_2 < V_249 ; V_2 ++ ) {
if ( V_242 < V_191 -> V_250 [ V_2 ] ) {
V_191 -> V_101 = V_191 -> V_100 [ V_2 ] ;
break;
}
}
if ( V_191 -> V_101 == V_191 -> V_99 ) {
V_191 -> V_251 = 1 ;
return;
}
V_191 -> V_251 ++ ;
if ( V_191 -> V_251 == 1 ) {
F_28 ( V_191 , V_191 -> V_101 ) ;
F_90 ( & V_191 -> V_6 -> V_116 ,
L_18 ,
( int ) V_242 , V_191 -> V_101 ,
V_191 -> V_99 ,
( int ) V_191 -> V_251 ) ;
}
if ( V_191 -> V_251 >= V_252 ) {
F_90 ( & V_191 -> V_6 -> V_116 ,
L_19 ,
( int ) V_242 , V_191 -> V_101 ,
V_191 -> V_99 ,
( int ) V_191 -> V_251 ) ;
F_28 ( V_191 , V_191 -> V_101 ) ;
}
}
static T_11 F_91 ( int V_118 , void * V_253 )
{
struct V_7 * V_8 = V_253 ;
int V_254 = 0 ;
unsigned long V_255 = 0 ;
unsigned char V_256 = 0 ;
int V_257 = 0 ;
unsigned long V_35 ;
F_92 ( V_8 -> V_40 , & V_8 -> V_258 ) ;
if ( V_8 -> V_258 == 0 )
return F_93 ( V_257 ) ;
if ( V_8 -> V_258 == 0xffffffff ) {
F_7 ( L_20 ) ;
return F_93 ( V_257 ) ;
}
V_257 = 1 ;
F_94 ( V_8 -> V_40 ) ;
F_14 ( & V_8 -> V_53 , V_35 ) ;
F_13 ( V_8 -> V_40 + V_259 , & V_256 ) ;
if ( V_256 == 1 )
F_23 ( V_8 -> V_40 ) ;
else
V_256 = 0 ;
F_95 ( V_8 -> V_40 , & V_255 ) ;
F_96 ( & V_8 -> V_260 , & V_8 -> V_261 , V_255 ) ;
while ( V_8 -> V_258 != 0 ) {
F_97 ( & V_8 -> V_261 , V_8 -> V_258 ) ;
F_98 ( V_8 -> V_40 , V_8 -> V_258 ) ;
if ( V_8 -> V_258 & V_240 ) {
F_7 ( L_21 ) ;
F_22 ( V_8 -> V_40 + V_262 , 0 ) ;
F_99 ( V_8 -> V_40 + V_262 , V_263 ) ;
F_86 ( V_8 , V_8 -> V_258 ) ;
}
if ( V_8 -> V_258 & V_264 ) {
if ( V_8 -> V_245 &&
V_8 -> V_265 != V_266 )
F_88 ( V_8 ) ;
V_8 -> V_267 = false ;
if ( V_8 -> V_268 )
F_100 ( ( void * ) V_8 ) ;
if ( ( V_8 -> V_265 == V_269 ||
V_8 -> V_265 == V_266 ) &&
V_8 -> V_245 -> V_246 . V_270 ) {
F_101 ( V_8 -> V_40 ,
( V_8 -> V_245 -> V_246 . V_271 - V_272 ) << 10 ) ;
}
}
if ( V_8 -> V_258 & V_273 ) {
if ( V_8 -> V_265 == V_266 ) {
V_8 -> V_274 = false ;
V_8 -> V_275 = 0 ;
}
V_8 -> V_267 = true ;
}
if ( V_8 -> V_258 & V_276 )
V_254 += F_72 ( V_8 , V_277 ) ;
if ( V_8 -> V_258 & V_278 )
V_254 += F_72 ( V_8 , V_279 ) ;
if ( V_8 -> V_258 & V_280 )
V_254 += F_84 ( V_8 , V_281 ) ;
if ( V_8 -> V_258 & V_282 )
V_254 += F_84 ( V_8 , V_283 ) ;
if ( V_8 -> V_258 & V_284 ) {
if ( V_8 -> V_245 ) {
if ( V_8 -> V_245 -> V_246 . V_270 )
F_102 ( V_8 , V_8 -> V_245 ) ;
}
}
if ( V_8 -> V_245 ) {
if ( F_103 ( V_8 , V_281 ) &&
F_103 ( V_8 , V_283 ) &&
F_104 ( V_8 -> V_137 , 0 ) )
F_105 ( V_8 -> V_137 ) ;
}
F_92 ( V_8 -> V_40 , & V_8 -> V_258 ) ;
F_35 ( V_8 -> V_40 ) ;
F_36 ( V_8 -> V_40 ) ;
if ( V_254 > V_8 -> V_10 . V_18 )
break;
}
if ( V_256 == 1 )
F_21 ( V_8 -> V_40 ) ;
F_16 ( & V_8 -> V_53 , V_35 ) ;
F_106 ( V_8 -> V_40 , V_285 ) ;
return F_93 ( V_257 ) ;
}
static int F_107 ( struct V_7 * V_191 , struct V_241 * V_171 )
{
struct V_286 * V_287 = (struct V_286 * ) V_171 -> V_288 ;
T_8 V_289 ;
T_12 V_290 ;
unsigned long V_35 ;
F_14 ( & V_191 -> V_53 , V_35 ) ;
if ( F_108 ( V_287 -> V_291 ) )
V_290 = V_283 ;
else
V_290 = V_281 ;
if ( F_103 ( V_191 , V_290 ) < 1 ) {
F_16 ( & V_191 -> V_53 , V_35 ) ;
return - V_205 ;
}
V_289 = V_191 -> V_177 [ V_290 ] ;
V_289 -> V_234 . V_235 = 0 ;
V_289 -> V_172 -> V_171 = V_171 ;
if ( V_290 == V_283 )
V_289 -> V_172 -> V_237 = V_238 ;
V_191 -> V_177 [ V_290 ] = V_289 -> V_164 ;
F_16 ( & V_191 -> V_53 , V_35 ) ;
F_109 ( V_191 , V_290 , V_289 , V_171 ) ;
if ( F_110 ( V_191 -> V_40 , V_292 , V_293 ) )
F_111 ( V_191 -> V_40 ) ;
F_14 ( & V_191 -> V_53 , V_35 ) ;
V_191 -> V_294 = false ;
V_289 -> V_234 . V_235 |= ( V_236 | V_295 | V_296 ) ;
V_289 -> V_234 . V_189 =
F_78 ( ( T_3 ) V_289 -> V_172 -> V_297 ) ;
V_289 -> V_190 = F_60 ( V_289 -> V_172 -> V_168 ) ;
F_112 () ;
V_289 -> V_231 . V_184 = V_186 ;
F_112 () ;
if ( V_289 -> V_172 -> V_237 & V_238 )
F_113 ( V_191 -> V_40 ) ;
else
F_114 ( V_191 -> V_40 ) ;
V_191 -> V_230 [ V_290 ] ++ ;
F_16 ( & V_191 -> V_53 , V_35 ) ;
return 0 ;
}
static void F_115 ( struct V_298 * V_137 ,
struct V_299 * V_210 ,
struct V_241 * V_171 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
F_116 ( V_137 ) ;
if ( F_107 ( V_191 , V_171 ) ) {
F_117 ( V_137 , V_171 ) ;
F_105 ( V_137 ) ;
}
}
static int F_118 ( struct V_298 * V_137 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
int V_300 ;
V_191 -> V_169 = V_148 ;
if ( ! F_52 ( V_191 ) )
return - V_205 ;
V_300 = F_119 ( V_191 -> V_6 -> V_118 , & F_91 ,
V_301 , L_22 , V_191 ) ;
if ( V_300 ) {
F_90 ( & V_191 -> V_6 -> V_116 , L_23 ) ;
return V_300 ;
}
F_90 ( & V_191 -> V_6 -> V_116 , L_24 ) ;
F_57 ( V_191 ) ;
F_61 ( V_191 ) ;
F_67 ( V_191 ) ;
F_69 ( V_191 ) ;
F_8 ( V_191 ) ;
F_90 ( & V_191 -> V_6 -> V_116 , L_25 ) ;
F_106 ( V_191 -> V_40 , V_285 ) ;
F_105 ( V_137 ) ;
return 0 ;
}
static void F_120 ( struct V_298 * V_137 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
F_116 ( V_137 ) ;
F_9 ( V_191 -> V_40 ) ;
F_11 ( V_191 -> V_40 ) ;
F_30 ( V_191 ) ;
F_70 ( V_191 ) ;
F_71 ( V_191 ) ;
F_62 ( V_191 ) ;
F_66 ( V_191 ) ;
F_56 ( V_191 ) ;
F_121 ( V_191 -> V_6 -> V_118 , V_191 ) ;
}
static int F_122 ( struct V_298 * V_137 , struct V_302 * V_245 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
V_191 -> V_245 = V_245 ;
switch ( V_245 -> type ) {
case V_303 :
break;
case V_266 :
F_123 ( V_191 -> V_40 , V_114 , V_304 ) ;
F_34 ( V_191 -> V_40 , V_305 , V_306 ) ;
break;
case V_269 :
F_123 ( V_191 -> V_40 , V_114 , V_304 ) ;
F_34 ( V_191 -> V_40 , V_305 , V_307 ) ;
break;
default:
return - V_308 ;
}
V_191 -> V_265 = V_245 -> type ;
return 0 ;
}
static void F_124 ( struct V_298 * V_137 ,
struct V_302 * V_245 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
switch ( V_245 -> type ) {
case V_303 :
break;
case V_266 :
F_123 ( V_191 -> V_40 , V_309 , V_310 ) ;
F_123 ( V_191 -> V_40 ,
V_96 , V_98 ) ;
F_123 ( V_191 -> V_40 , V_305 , V_306 ) ;
break;
case V_269 :
F_123 ( V_191 -> V_40 , V_309 , V_310 ) ;
F_123 ( V_191 -> V_40 ,
V_96 , V_98 ) ;
F_123 ( V_191 -> V_40 , V_305 , V_307 ) ;
break;
default:
break;
}
V_191 -> V_265 = V_311 ;
}
static int F_125 ( struct V_298 * V_137 , T_12 V_312 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
struct V_313 * V_243 = & V_137 -> V_243 ;
T_4 V_314 ;
if ( V_312 & V_315 ) {
if ( V_243 -> V_35 & V_316 )
F_126 ( V_191 , V_243 -> V_317 ) ;
else
F_127 ( V_191 ) ;
}
if ( ( V_312 & V_318 ) ||
( V_243 -> V_35 & V_244 ) ) {
F_128 ( V_191 , V_243 -> V_319 . V_320 ) ;
if ( V_243 -> V_319 . V_320 -> V_219 == V_220 )
V_314 = V_321 ;
else
V_314 = V_322 ;
if ( V_191 -> V_28 != V_314 ) {
V_191 -> V_28 = V_314 ;
F_129 ( V_191 , V_191 -> V_28 ) ;
}
}
if ( V_312 & V_323 ) {
if ( V_191 -> V_28 == V_324 )
V_191 -> V_45 = V_46 ;
else
V_191 -> V_45 = V_102 ;
F_130 ( V_191 , V_191 -> V_45 ,
V_243 -> V_319 . V_320 -> V_215 ) ;
}
return 0 ;
}
static void F_131 ( struct V_298 * V_137 ,
struct V_302 * V_245 , struct V_325 * V_243 ,
T_12 V_312 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
V_191 -> V_326 = V_243 -> V_327 ;
if ( V_312 & V_328 ) {
unsigned long V_35 ;
F_14 ( & V_191 -> V_53 , V_35 ) ;
F_132 ( V_191 -> V_40 , ( T_4 * ) V_243 -> V_329 ) ;
F_16 ( & V_191 -> V_53 , V_35 ) ;
}
if ( V_312 & V_330 ) {
V_191 -> V_331 = V_243 -> V_331 ;
F_133 ( V_191 ) ;
F_90 ( & V_191 -> V_6 -> V_116 ,
L_26 , V_243 -> V_331 ) ;
}
if ( V_312 & V_332 ) {
if ( V_243 -> V_333 ) {
F_134 ( V_191 -> V_40 ) ;
V_191 -> V_33 = true ;
} else {
F_135 ( V_191 -> V_40 ) ;
V_191 -> V_33 = false ;
}
}
if ( V_312 & V_334 ) {
if ( V_243 -> V_335 )
F_136 ( V_191 -> V_40 ) ;
else
F_137 ( V_191 -> V_40 ) ;
}
if ( V_312 & V_336 ) {
if ( V_243 -> V_337 )
V_191 -> V_338 = true ;
else
V_191 -> V_338 = false ;
F_129 ( V_191 , V_191 -> V_28 ) ;
F_28 ( V_191 , V_191 -> V_100 [ 0 ] ) ;
}
if ( V_312 & V_339 )
F_130 ( V_191 , V_191 -> V_45 ,
V_243 -> V_319 . V_320 -> V_215 ) ;
if ( V_312 & V_340 ) {
F_90 ( & V_191 -> V_6 -> V_116 ,
L_27 , V_243 -> V_270 ) ;
if ( V_243 -> V_270 ) {
F_138 ( V_191 , V_245 , V_243 ) ;
F_34 ( V_191 -> V_40 , V_309 ,
V_310 ) ;
} else {
F_123 ( V_191 -> V_40 , V_309 ,
V_310 ) ;
}
}
if ( V_312 & V_341 && V_191 -> V_265 != V_269 ) {
if ( V_243 -> V_247 ) {
F_139 ( V_191 , V_243 -> V_342 -> V_215 ,
V_243 -> V_343 ) ;
F_140 ( V_191 , V_243 -> V_271 ) ;
F_141 ( V_191 , V_243 -> V_271 ) ;
} else {
F_22 ( V_191 -> V_40 + V_96 ,
V_97 ) ;
F_22 ( V_191 -> V_40 + V_96 ,
V_98 ) ;
}
}
}
static T_13 F_142 ( struct V_298 * V_137 ,
struct V_344 * V_345 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
struct V_346 * V_347 ;
T_13 V_348 = 0 ;
T_12 V_349 = 0 ;
F_143 (ha, mc_list) {
V_349 = F_144 ( V_350 , V_347 -> V_351 ) >> 26 ;
V_348 |= 1ULL << ( V_349 & 0x3f ) ;
}
V_191 -> V_352 = V_345 -> V_223 ;
return V_348 ;
}
static void F_145 ( struct V_298 * V_137 ,
unsigned int V_353 , unsigned int * V_354 , T_13 V_355 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
T_4 V_356 = 0 ;
* V_354 &= V_357 | V_358 | V_359 |
V_360 ;
F_13 ( V_191 -> V_40 + V_114 , & V_356 ) ;
F_90 ( & V_191 -> V_6 -> V_116 , L_28 , V_356 ) ;
if ( V_353 & V_359 ) {
if ( * V_354 & V_359 )
V_356 |= V_304 ;
else
V_356 &= ~ V_304 ;
}
if ( V_353 & V_357 ) {
if ( * V_354 & V_357 ) {
unsigned long V_35 ;
F_14 ( & V_191 -> V_53 , V_35 ) ;
if ( V_191 -> V_352 > 2 ) {
F_21 ( V_191 -> V_40 ) ;
F_146 ( V_191 -> V_40 +
V_361 , 0xffffffff ) ;
F_146 ( V_191 -> V_40 +
V_361 + 4 , 0xffffffff ) ;
F_23 ( V_191 -> V_40 ) ;
} else {
F_21 ( V_191 -> V_40 ) ;
F_146 ( V_191 -> V_40 +
V_361 , ( T_12 ) V_355 ) ;
F_146 ( V_191 -> V_40 +
V_361 + 4 ,
( T_12 ) ( V_355 >> 32 ) ) ;
F_23 ( V_191 -> V_40 ) ;
}
F_16 ( & V_191 -> V_53 , V_35 ) ;
V_356 |= V_362 | V_363 ;
} else {
V_356 &= ~ ( V_362 | V_363 ) ;
}
}
if ( V_353 & ( V_358 | V_360 ) ) {
V_356 |= V_362 | V_363 ;
if ( * V_354 & ( V_358 | V_360 ) )
V_356 &= ~ V_364 ;
else
V_356 |= V_364 ;
}
F_22 ( V_191 -> V_40 + V_114 , V_356 ) ;
F_90 ( & V_191 -> V_6 -> V_116 , L_29 , V_356 ) ;
}
static int F_147 ( struct V_298 * V_137 , enum V_365 V_366 ,
struct V_302 * V_245 , struct V_367 * V_368 ,
struct V_369 * V_370 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
switch ( V_366 ) {
case V_371 :
if ( F_148 ( V_137 , V_368 , V_245 , V_370 ) )
return - V_308 ;
break;
case V_372 :
if ( F_149 ( V_370 -> V_373 , & V_191 -> V_374 ) )
F_150 ( V_370 -> V_373 , & V_191 -> V_374 ) ;
default:
break;
}
return 0 ;
}
static T_13 F_151 ( struct V_298 * V_137 , struct V_302 * V_245 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
T_13 V_375 ;
F_152 ( V_191 , & V_375 ) ;
return V_375 ;
}
static void F_153 ( struct V_298 * V_137 , struct V_302 * V_245 ,
T_13 V_375 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
F_154 ( V_191 , V_375 , V_245 -> V_246 . V_271 ) ;
}
static void F_155 ( struct V_298 * V_137 , struct V_302 * V_245 )
{
struct V_7 * V_191 = V_137 -> V_191 ;
F_22 ( V_191 -> V_40 + V_96 , V_97 ) ;
}
static int F_156 ( struct V_7 * V_191 )
{
F_157 ( V_191 -> V_137 , V_191 -> V_112 ) ;
F_158 ( V_191 ) ;
if ( F_159 ( V_191 -> V_137 ) )
return - V_376 ;
V_191 -> V_136 = true ;
F_30 ( V_191 ) ;
return 0 ;
}
static int
F_160 ( struct V_5 * V_6 , const struct V_377 * V_378 )
{
T_2 V_120 = ( T_2 ) V_378 -> V_379 ;
struct V_7 * V_191 ;
struct V_298 * V_137 ;
struct V_380 * V_380 ;
int V_381 ;
F_161 ( & V_6 -> V_116 ,
L_30 , V_382 , V_383 ) ;
F_161 ( & V_6 -> V_116 ,
L_31 ) ;
V_137 = F_162 ( sizeof( * V_191 ) , & V_384 ) ;
if ( ! V_137 ) {
F_54 ( & V_6 -> V_116 , L_32 ) ;
return - V_205 ;
}
V_191 = V_137 -> V_191 ;
F_40 ( V_6 , & V_191 , V_120 ) ;
V_191 -> V_137 = V_137 ;
F_163 ( V_191 -> V_137 , & V_6 -> V_116 ) ;
if ( F_164 ( V_6 ) ) {
F_4 ( V_191 ) ;
return - V_376 ;
}
F_90 ( & V_6 -> V_116 ,
L_33 , V_191 -> V_134 ) ;
if ( ! F_42 ( V_191 , V_6 ) ) {
F_54 ( & V_6 -> V_116 , L_34 ) ;
F_4 ( V_191 ) ;
return - V_376 ;
}
#ifdef F_165
F_90 ( & V_6 -> V_116 ,
L_35 ,
V_191 -> V_134 , V_191 -> V_117 , V_191 -> V_121 ) ;
{
int V_2 ;
T_12 V_385 , V_178 ;
T_12 V_386 [] = {
V_387 ,
V_388 ,
V_389 ,
V_390 ,
V_391 ,
V_392 ,
0 } ;
for ( V_2 = 0 ; V_386 [ V_2 ] ; V_2 ++ ) {
F_166 ( V_6 , V_386 [ V_2 ] , & V_385 ) ;
F_90 ( & V_6 -> V_116 , L_36 , V_2 , V_385 ) ;
if ( ! V_385 ) {
F_90 ( & V_6 -> V_116 ,
L_37 , V_2 ) ;
continue;
}
if ( V_385 & V_393 ) {
V_178 = V_385 & ( V_394 & 0xffff ) ;
V_178 = V_178 & ~ ( V_178 - 1 ) ;
F_90 ( & V_6 -> V_116 ,
L_38 ,
V_178 , V_2 ) ;
} else {
V_178 = V_385 & 0xfffffff0 ;
V_178 = ~ V_178 + 1 ;
F_90 ( & V_6 -> V_116 ,
L_39 , V_178 , V_2 ) ;
}
}
}
#endif
V_191 -> V_40 = F_167 ( V_191 -> V_134 & V_395 ,
V_191 -> V_121 ) ;
if ( ! V_191 -> V_40 ) {
F_54 ( & V_6 -> V_116 , L_40 ) ;
F_4 ( V_191 ) ;
return - V_376 ;
}
V_381 = F_168 ( V_6 , V_396 ) ;
if ( V_381 ) {
F_54 ( & V_6 -> V_116 , L_41 ) ;
F_4 ( V_191 ) ;
return - V_376 ;
}
if ( ! F_11 ( V_191 -> V_40 ) ) {
F_54 ( & V_6 -> V_116 , L_42 ) ;
F_4 ( V_191 ) ;
return - V_376 ;
}
F_12 ( V_191 -> V_40 ) ;
F_169 ( V_191 -> V_40 , V_191 -> V_112 ) ;
V_191 -> V_397 = F_17 ( V_191 -> V_40 , V_398 ) ;
V_191 -> V_397 &= V_399 ;
F_90 ( & V_6 -> V_116 , L_43 , V_191 -> V_397 ) ;
F_5 ( V_191 ) ;
F_6 ( V_191 ) ;
V_191 -> V_10 . V_35 &= V_120 -> V_35 ;
V_191 -> V_35 = V_191 -> V_10 . V_35 | ( V_120 -> V_35 & 0xff000000UL ) ;
V_380 = V_191 -> V_137 -> V_380 ;
V_380 -> V_400 = V_401 ;
V_380 -> V_402 = V_403 ;
V_380 -> V_404 = F_170 ( V_303 ) |
F_170 ( V_266 ) | F_170 ( V_269 ) ;
V_191 -> V_137 -> V_35 = V_405 |
V_406 |
V_407 |
V_408 ;
V_191 -> V_137 -> V_409 = 100 ;
if ( F_156 ( V_191 ) )
return - V_376 ;
F_38 ( V_191 ) ;
F_171 ( V_6 , V_191 ) ;
return 0 ;
}
static int F_172 ( struct V_5 * V_6 , T_14 V_410 )
{
struct V_7 * V_191 = F_3 ( V_6 ) ;
unsigned long V_35 ;
F_14 ( & V_191 -> V_53 , V_35 ) ;
F_173 ( V_6 ) ;
F_9 ( V_191 -> V_40 ) ;
F_174 ( V_6 ) ;
F_175 ( V_6 , F_176 ( V_6 , V_410 ) ) ;
F_16 ( & V_191 -> V_53 , V_35 ) ;
return 0 ;
}
static int F_177 ( struct V_5 * V_6 )
{
F_175 ( V_6 , V_411 ) ;
F_178 ( V_6 , V_411 , 0 ) ;
F_179 ( V_6 ) ;
return 0 ;
}
static int T_15 F_180 ( void )
{
int V_300 ;
V_300 = F_181 ( & V_412 ) ;
#ifdef F_182
if ( V_300 >= 0 )
F_183 ( & V_413 ) ;
#endif
return V_300 ;
}
static void T_16 F_184 ( void )
{
#ifdef F_182
F_185 ( & V_413 ) ;
#endif
F_186 ( & V_412 ) ;
}
static int
F_187 ( struct V_414 * V_415 , unsigned long V_416 , void * V_417 )
{
struct V_5 * V_418 = NULL ;
switch ( V_416 ) {
case V_419 :
case V_420 :
case V_421 :
F_188 (pdev) {
if ( F_189 ( V_418 ) == & V_412 ) {
if ( F_3 ( V_418 ) )
F_172 ( V_418 , V_422 ) ;
}
}
}
return V_423 ;
}
