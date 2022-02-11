static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
memset ( & V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
F_2 ( & V_4 -> V_8 ) ;
F_3 ( & V_4 -> V_9 ) ;
F_3 ( & V_4 -> V_10 ) ;
if ( F_4 ( V_4 -> V_11 || V_4 -> V_12 ) )
return - V_13 ;
V_4 -> V_11 = F_5 ( V_6 , sizeof( V_14 ) * V_15 ,
& V_4 -> V_16 , V_17 ) ;
if ( ! V_4 -> V_11 )
goto V_18;
memset ( V_4 -> V_11 , 0 , sizeof( V_14 ) * V_15 ) ;
V_4 -> V_12 = F_5 ( V_6 , sizeof( * V_4 -> V_12 ) ,
& V_4 -> V_19 , V_17 ) ;
if ( ! V_4 -> V_12 )
goto V_20;
memset ( V_4 -> V_12 , 0 , sizeof( * V_4 -> V_12 ) ) ;
return 0 ;
V_20:
F_6 ( V_6 , sizeof( V_14 ) * V_15 ,
V_4 -> V_11 , V_4 -> V_16 ) ;
memset ( & V_4 -> V_16 , 0 , sizeof( V_4 -> V_16 ) ) ;
V_4 -> V_11 = NULL ;
V_18:
return - V_21 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 + V_15 ; V_22 ++ ) {
if ( V_4 -> V_24 [ V_22 ] . V_25 != NULL ) {
F_8 ( V_2 -> V_7 -> V_6 , V_4 -> V_24 [ V_22 ] . V_26 ,
V_27 << V_2 -> V_28 . V_29 ,
V_30 ) ;
F_9 ( V_2 , V_4 -> V_24 [ V_22 ] . V_25 ) ;
V_4 -> V_24 [ V_22 ] . V_25 = NULL ;
}
F_10 ( & V_4 -> V_24 [ V_22 ] . V_31 , & V_4 -> V_10 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_32 ;
const T_1 V_33 = V_34 ;
T_1 V_35 = 0 ;
V_35 = V_36 ;
if ( V_37 . V_38 )
V_32 = V_39 ;
else
V_32 = V_40 ;
F_12 ( V_2 , V_41 , 0 ) ;
F_12 ( V_2 , V_42 , 0 ) ;
F_12 ( V_2 , V_43 ,
( T_1 ) ( V_4 -> V_16 >> 8 ) ) ;
F_12 ( V_2 , V_44 ,
V_4 -> V_19 >> 4 ) ;
F_12 ( V_2 , V_41 ,
V_45 |
V_46 |
V_47 |
V_48 |
V_32 |
( V_35 << V_49 ) |
( V_33 << V_50 ) ) ;
F_13 ( V_2 , V_51 , V_52 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_22 , V_53 ;
unsigned long V_54 ;
if ( ! V_4 -> V_11 ) {
V_53 = F_1 ( V_2 ) ;
if ( V_53 )
return V_53 ;
}
F_15 ( & V_4 -> V_8 , V_54 ) ;
F_3 ( & V_4 -> V_9 ) ;
F_3 ( & V_4 -> V_10 ) ;
F_7 ( V_2 ) ;
for ( V_22 = 0 ; V_22 < V_15 ; V_22 ++ )
V_4 -> V_55 [ V_22 ] = NULL ;
V_4 -> V_56 = V_4 -> V_57 = 0 ;
V_4 -> V_58 = 0 ;
V_4 -> V_59 = 0 ;
F_16 ( & V_4 -> V_8 , V_54 ) ;
F_17 ( V_2 ) ;
F_11 ( V_2 , V_4 ) ;
F_15 ( & V_2 -> V_8 , V_54 ) ;
V_4 -> V_60 = 1 ;
F_18 ( V_2 , V_4 ) ;
F_16 ( & V_2 -> V_8 , V_54 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_54 ;
if ( ! V_4 -> V_11 ) {
F_20 ( V_2 , L_1 ) ;
return;
}
F_15 ( & V_4 -> V_8 , V_54 ) ;
F_7 ( V_2 ) ;
F_16 ( & V_4 -> V_8 , V_54 ) ;
F_6 ( V_2 -> V_7 -> V_6 , sizeof( V_14 ) * V_15 ,
V_4 -> V_11 , V_4 -> V_16 ) ;
memset ( & V_4 -> V_16 , 0 , sizeof( V_4 -> V_16 ) ) ;
V_4 -> V_11 = NULL ;
if ( V_4 -> V_12 )
F_6 ( V_2 -> V_7 -> V_6 ,
sizeof( struct V_61 ) ,
V_4 -> V_12 , V_4 -> V_19 ) ;
else
F_20 ( V_2 , L_2 ) ;
memset ( & V_4 -> V_19 , 0 , sizeof( V_4 -> V_19 ) ) ;
V_4 -> V_12 = NULL ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_41 , 0 ) ;
return F_22 ( V_2 , V_62 ,
V_63 , 1000 ) ;
}
static inline int F_23 ( struct V_1 * V_2 ,
struct V_64 * V_65 , T_2 V_66 )
{
if ( F_4 ( V_65 -> V_67 ) )
return - V_13 ;
V_65 -> V_67 = F_5 ( V_2 -> V_7 -> V_6 , V_66 ,
& V_65 -> V_68 , V_17 ) ;
if ( ! V_65 -> V_67 )
return - V_21 ;
V_65 -> V_66 = V_66 ;
return 0 ;
}
static inline void F_24 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
if ( F_25 ( ! V_65 -> V_67 ) )
return;
F_6 ( V_2 -> V_7 -> V_6 , V_65 -> V_66 , V_65 -> V_67 , V_65 -> V_68 ) ;
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
}
static int F_26 ( struct V_1 * V_2 , struct V_69 * V_70 ,
int V_71 , T_1 V_72 )
{
T_2 V_73 = V_2 -> V_28 . V_74 * V_75 ;
int V_22 ;
if ( F_4 ( V_70 -> V_76 || V_70 -> V_77 || V_70 -> V_78 || V_70 -> V_79 ) )
return - V_13 ;
V_70 -> V_80 . V_81 = V_71 ;
V_70 -> V_76 = F_27 ( sizeof( V_70 -> V_76 [ 0 ] ) * V_71 ,
V_17 ) ;
V_70 -> V_77 = F_27 ( sizeof( V_70 -> V_77 [ 0 ] ) * V_71 ,
V_17 ) ;
if ( ! V_70 -> V_76 || ! V_70 -> V_77 )
goto error;
for ( V_22 = 0 ; V_22 < V_71 ; V_22 ++ ) {
V_70 -> V_77 [ V_22 ] = F_28 ( sizeof( struct V_82 ) ,
V_17 ) ;
if ( ! V_70 -> V_77 [ V_22 ] )
goto error;
}
if ( V_72 != V_2 -> V_83 ) {
V_70 -> V_78 = F_27 ( sizeof( V_70 -> V_78 [ 0 ] ) *
V_75 , V_17 ) ;
if ( ! V_70 -> V_78 ) {
F_29 ( V_2 , L_3
L_4 ) ;
goto error;
}
} else {
V_70 -> V_78 = NULL ;
}
V_70 -> V_79 = F_5 ( V_2 -> V_7 -> V_6 , V_73 , & V_70 -> V_80 . V_84 ,
V_17 ) ;
if ( ! V_70 -> V_79 ) {
F_29 ( V_2 , L_5 , V_73 ) ;
goto error;
}
V_70 -> V_80 . V_85 = V_72 ;
return 0 ;
error:
F_30 ( V_70 -> V_78 ) ;
V_70 -> V_78 = NULL ;
if ( V_70 -> V_77 )
for ( V_22 = 0 ; V_22 < V_71 ; V_22 ++ )
F_30 ( V_70 -> V_77 [ V_22 ] ) ;
F_30 ( V_70 -> V_76 ) ;
F_30 ( V_70 -> V_77 ) ;
V_70 -> V_76 = NULL ;
V_70 -> V_77 = NULL ;
return - V_21 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_69 * V_70 ,
int V_71 , T_1 V_72 )
{
int V_86 ;
V_70 -> V_60 = 0 ;
memset ( V_70 -> V_76 , 0 , sizeof( V_70 -> V_76 [ 0 ] ) * V_71 ) ;
if ( V_72 < 4 )
F_32 ( V_70 , V_72 , V_72 ) ;
F_33 ( V_75 & ( V_75 - 1 ) ) ;
V_86 = F_34 ( V_2 , & V_70 -> V_80 , V_75 , V_71 ,
V_72 ) ;
if ( V_86 )
return V_86 ;
F_12 ( V_2 , F_35 ( V_72 ) ,
V_70 -> V_80 . V_84 >> 8 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , int V_72 )
{
struct V_69 * V_70 = & V_2 -> V_70 [ V_72 ] ;
struct V_87 * V_80 = & V_70 -> V_80 ;
if ( ! V_80 -> V_88 )
return;
while ( V_80 -> V_89 != V_80 -> V_90 ) {
F_37 ( V_2 , V_70 , F_38 ( V_80 , V_80 -> V_90 ) ) ;
V_80 -> V_90 = F_39 ( V_80 -> V_90 , V_80 -> V_88 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , int V_72 )
{
struct V_69 * V_70 = & V_2 -> V_70 [ V_72 ] ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
int V_22 ;
if ( F_4 ( ! V_70 ) )
return;
F_36 ( V_2 , V_72 ) ;
for ( V_22 = 0 ; V_22 < V_70 -> V_80 . V_81 ; V_22 ++ )
F_30 ( V_70 -> V_77 [ V_22 ] ) ;
if ( V_70 -> V_80 . V_88 ) {
F_6 ( V_6 , V_2 -> V_28 . V_74 *
V_70 -> V_80 . V_88 , V_70 -> V_79 , V_70 -> V_80 . V_84 ) ;
memset ( & V_70 -> V_80 . V_84 , 0 , sizeof( V_70 -> V_80 . V_84 ) ) ;
}
F_30 ( V_70 -> V_78 ) ;
V_70 -> V_78 = NULL ;
F_30 ( V_70 -> V_77 ) ;
F_30 ( V_70 -> V_76 ) ;
V_70 -> V_77 = NULL ;
V_70 -> V_76 = NULL ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_72 ;
if ( V_2 -> V_70 ) {
for ( V_72 = 0 ; V_72 < V_2 -> V_28 . V_91 ; V_72 ++ )
F_40 ( V_2 , V_72 ) ;
}
F_30 ( V_2 -> V_70 ) ;
V_2 -> V_70 = NULL ;
F_24 ( V_2 , & V_2 -> V_92 ) ;
F_24 ( V_2 , & V_2 -> V_93 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_86 ;
int V_72 , V_71 ;
if ( F_4 ( V_2 -> V_70 ) ) {
V_86 = - V_13 ;
goto error;
}
V_86 = F_23 ( V_2 , & V_2 -> V_93 ,
V_2 -> V_28 . V_94 ) ;
if ( V_86 ) {
F_29 ( V_2 , L_6 ) ;
goto error;
}
V_86 = F_23 ( V_2 , & V_2 -> V_92 , V_95 ) ;
if ( V_86 ) {
F_29 ( V_2 , L_7 ) ;
goto error;
}
V_2 -> V_70 = F_27 ( sizeof( struct V_69 ) *
V_2 -> V_96 -> V_97 -> V_98 , V_17 ) ;
if ( ! V_2 -> V_70 ) {
F_29 ( V_2 , L_8 ) ;
V_86 = V_21 ;
goto error;
}
for ( V_72 = 0 ; V_72 < V_2 -> V_28 . V_91 ; V_72 ++ ) {
V_71 = ( V_72 == V_2 -> V_83 ) ?
V_99 : V_100 ;
V_86 = F_26 ( V_2 , & V_2 -> V_70 [ V_72 ] , V_71 ,
V_72 ) ;
if ( V_86 ) {
F_29 ( V_2 , L_9 , V_72 ) ;
goto error;
}
}
return 0 ;
error:
F_43 ( & V_2 -> V_101 ) ;
return V_86 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_86 ;
int V_72 , V_71 ;
unsigned long V_54 ;
bool V_102 = false ;
if ( ! V_2 -> V_70 ) {
V_86 = F_42 ( V_2 ) ;
if ( V_86 )
goto error;
V_102 = true ;
}
F_15 ( & V_2 -> V_8 , V_54 ) ;
F_45 ( V_2 , V_103 , 0 ) ;
F_12 ( V_2 , V_104 , V_2 -> V_92 . V_68 >> 4 ) ;
F_16 ( & V_2 -> V_8 , V_54 ) ;
for ( V_72 = 0 ; V_72 < V_2 -> V_28 . V_91 ; V_72 ++ ) {
V_71 = ( V_72 == V_2 -> V_83 ) ?
V_99 : V_100 ;
V_86 = F_31 ( V_2 , & V_2 -> V_70 [ V_72 ] , V_71 ,
V_72 ) ;
if ( V_86 ) {
F_29 ( V_2 , L_10 , V_72 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_102 )
F_43 ( & V_2 -> V_101 ) ;
return V_86 ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 , V_105 ,
V_106 ,
~ V_107 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_15 ( & V_2 -> V_8 , V_54 ) ;
F_49 ( V_2 ) ;
F_13 ( V_2 , V_51 , V_108 ) ;
F_16 ( & V_2 -> V_8 , V_54 ) ;
F_46 ( V_2 ) ;
V_2 -> V_96 -> V_109 -> V_110 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( F_44 ( V_2 ) )
return - V_21 ;
if ( V_2 -> V_96 -> V_97 -> V_111 ) {
F_50 ( V_2 , V_112 ,
0x800FFFFF ) ;
}
F_51 ( V_113 , & V_2 -> V_114 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_86 ;
F_50 ( V_2 , V_115 ,
V_116 ) ;
V_86 = F_53 ( V_2 , V_115 ,
V_116 ,
V_116 ,
V_117 ) ;
F_20 ( V_2 , L_11 , V_86 < 0 ? L_12 : L_13 ) ;
return V_86 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_86 ;
F_20 ( V_2 , L_14 ) ;
V_86 = F_52 ( V_2 ) ;
if ( V_86 >= 0 )
return 0 ;
F_50 ( V_2 , V_115 ,
V_118 ) ;
V_86 = F_53 ( V_2 , V_115 ,
~ V_119 ,
V_119 , 150000 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_52 ( V_2 ) ;
if ( V_86 >= 0 )
return 0 ;
return V_86 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_86 ;
V_2 -> V_120 = V_121 ;
if ( ( V_2 -> V_96 -> V_122 & V_123 ) &&
F_54 ( V_2 ) ) {
F_56 ( V_2 , L_15 ) ;
return - V_124 ;
}
if ( F_57 ( V_2 , V_125 ) &
V_126 )
F_58 ( V_127 , & V_2 -> V_114 ) ;
else
F_51 ( V_127 , & V_2 -> V_114 ) ;
if ( F_59 ( V_2 ) ) {
F_60 ( V_2 -> V_128 -> V_129 , true ) ;
F_61 ( V_2 ) ;
return - V_130 ;
}
F_62 ( V_2 , V_131 , 0xFFFFFFFF ) ;
V_86 = F_48 ( V_2 ) ;
if ( V_86 ) {
F_29 ( V_2 , L_16 ) ;
return V_86 ;
}
F_62 ( V_2 , V_132 , V_133 ) ;
F_62 ( V_2 , V_132 ,
V_134 ) ;
F_62 ( V_2 , V_131 , 0xFFFFFFFF ) ;
F_61 ( V_2 ) ;
F_62 ( V_2 , V_132 , V_133 ) ;
F_62 ( V_2 , V_132 , V_133 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , T_1 V_135 )
{
F_45 ( V_2 , V_103 , V_135 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
const struct V_136 * V_137 ;
struct V_138 * V_139 ;
T_1 V_140 ;
unsigned long V_54 ;
int V_22 , V_141 ;
T_1 V_142 ;
F_15 ( & V_2 -> V_8 , V_54 ) ;
V_2 -> V_143 = F_65 ( V_2 , V_144 ) ;
V_140 = V_2 -> V_143 + V_145 ;
for (; V_140 < V_2 -> V_143 + V_146 ;
V_140 += 4 )
F_66 ( V_2 , V_140 , 0 ) ;
for (; V_140 < V_2 -> V_143 + V_147 ;
V_140 += 4 )
F_66 ( V_2 , V_140 , 0 ) ;
for (; V_140 < V_2 -> V_143 +
F_67 ( V_2 -> V_28 . V_91 ) ; V_140 += 4 )
F_66 ( V_2 , V_140 , 0 ) ;
F_45 ( V_2 , V_148 ,
V_2 -> V_93 . V_68 >> 10 ) ;
for ( V_141 = 0 ; V_141 < V_149 ; V_141 ++ )
F_12 ( V_2 , F_68 ( V_141 ) ,
V_150 |
V_151 ) ;
V_142 = F_69 ( V_2 , V_152 ) ;
F_12 ( V_2 , V_152 ,
V_142 | V_153 ) ;
F_45 ( V_2 , V_154 ,
F_70 ( V_2 ) ) ;
F_45 ( V_2 , V_155 , 0 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_28 . V_91 ; V_22 ++ ) {
F_45 ( V_2 , F_71 ( V_22 ) , 0 ) ;
F_12 ( V_2 , V_156 , 0 | ( V_22 << 8 ) ) ;
F_66 ( V_2 , V_2 -> V_143 +
F_72 ( V_22 ) , 0 ) ;
F_66 ( V_2 , V_2 -> V_143 +
F_72 ( V_22 ) +
sizeof( T_1 ) ,
( ( V_157 <<
V_158 ) &
V_159 ) |
( ( V_160 <<
V_161 ) &
V_162 ) ) ;
}
F_45 ( V_2 , V_163 ,
F_73 ( 0 , V_2 -> V_28 . V_91 ) ) ;
F_63 ( V_2 , F_73 ( 0 , 7 ) ) ;
if ( V_2 -> V_164 != F_74 ( V_165 ) )
V_137 = V_166 ;
else
V_137 = V_167 ;
F_75 ( V_2 , V_2 -> V_83 , 0 ) ;
memset ( & V_2 -> V_168 [ 0 ] , 0 , sizeof( V_2 -> V_168 ) ) ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ )
F_76 ( & V_2 -> V_169 [ V_22 ] , 0 ) ;
F_77 (priv, ctx)
V_139 -> V_170 = false ;
V_2 -> V_171 = 0 ;
F_33 ( F_78 ( V_167 ) != 10 ) ;
F_33 ( F_78 ( V_166 ) != 10 ) ;
for ( V_22 = 0 ; V_22 < 10 ; V_22 ++ ) {
int V_172 = V_137 [ V_22 ] . V_172 ;
int V_173 = V_137 [ V_22 ] . V_173 ;
F_79 ( V_2 , V_22 ) ;
if ( V_172 == V_174 )
continue;
if ( V_173 != V_175 )
F_32 ( & V_2 -> V_70 [ V_22 ] , V_173 , V_22 ) ;
F_80 ( V_2 , & V_2 -> V_70 [ V_22 ] , V_172 , 0 ) ;
}
F_16 ( & V_2 -> V_8 , V_54 ) ;
F_81 ( V_2 , V_176 ,
V_177 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_178 , V_72 ;
unsigned long V_54 ;
F_15 ( & V_2 -> V_8 , V_54 ) ;
F_63 ( V_2 , 0 ) ;
for ( V_178 = 0 ; V_178 < V_149 ; V_178 ++ ) {
F_12 ( V_2 , F_68 ( V_178 ) , 0x0 ) ;
if ( F_22 ( V_2 , V_179 ,
F_83 ( V_178 ) ,
1000 ) )
F_29 ( V_2 , L_17
L_18 , V_178 ,
F_69 ( V_2 , V_179 ) ) ;
}
F_16 ( & V_2 -> V_8 , V_54 ) ;
if ( ! V_2 -> V_70 ) {
F_56 ( V_2 , L_19 ) ;
return 0 ;
}
for ( V_72 = 0 ; V_72 < V_2 -> V_28 . V_91 ; V_72 ++ )
F_36 ( V_2 , V_72 ) ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_62 ( V_2 , V_180 , V_181 ) ;
F_15 ( & V_2 -> V_8 , V_54 ) ;
F_85 ( V_2 ) ;
F_16 ( & V_2 -> V_8 , V_54 ) ;
F_86 ( & V_2 -> V_101 ) ;
F_87 ( V_2 ) ;
if ( F_88 ( V_182 , & V_2 -> V_114 ) ) {
F_82 ( V_2 ) ;
F_21 ( V_2 ) ;
F_45 ( V_2 , V_183 ,
V_184 ) ;
F_89 ( 5 ) ;
}
F_90 ( V_2 , V_125 , V_185 ) ;
F_91 ( V_2 ) ;
}
static struct V_186 * F_92 ( struct V_1 * V_2 ,
int V_72 )
{
struct V_69 * V_70 = & V_2 -> V_70 [ V_72 ] ;
struct V_87 * V_80 = & V_70 -> V_80 ;
struct V_82 * V_187 ;
if ( F_25 ( F_93 ( V_80 ) < V_80 -> V_188 ) )
return NULL ;
V_187 = V_70 -> V_77 [ V_80 -> V_89 ] ;
memset ( V_187 , 0 , sizeof( * V_187 ) ) ;
V_187 -> V_189 . V_77 = V_190 ;
V_187 -> V_189 . V_191 = F_94 ( ( V_192 ) ( F_95 ( V_72 ) |
F_96 ( V_80 -> V_89 ) ) ) ;
return & V_187 -> V_77 . V_193 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_194 * V_195 ,
struct V_186 * V_196 , int V_72 , T_3 V_197 , bool V_198 ,
struct V_138 * V_139 )
{
struct V_69 * V_70 = & V_2 -> V_70 [ V_72 ] ;
struct V_87 * V_80 = & V_70 -> V_80 ;
struct V_82 * V_187 = V_70 -> V_77 [ V_80 -> V_89 ] ;
struct V_199 * V_200 ;
T_4 V_201 = 0 ;
T_4 V_202 ;
T_4 V_203 ;
V_192 V_204 , V_205 , V_206 ;
T_5 V_207 = 0 ;
T_5 V_208 = F_98 ( V_197 ) ;
memset ( & ( V_70 -> V_78 [ V_80 -> V_89 ] ) , 0 , sizeof( struct V_209 ) ) ;
V_70 -> V_78 [ V_80 -> V_89 ] . V_195 = V_195 ;
V_70 -> V_78 [ V_80 -> V_89 ] . V_139 = V_139 ;
V_200 = & V_70 -> V_76 [ V_80 -> V_89 ] ;
V_204 = sizeof( struct V_186 ) +
sizeof( struct V_210 ) + V_208 ;
V_205 = ( V_204 + 3 ) & ~ 3 ;
if ( V_205 != V_204 )
V_196 -> V_211 |= V_212 ;
V_202 = F_99 ( V_2 -> V_7 -> V_6 ,
& V_187 -> V_189 , V_205 ,
V_213 ) ;
if ( F_25 ( F_100 ( V_2 -> V_7 -> V_6 , V_202 ) ) )
return - 1 ;
F_101 ( V_200 , V_214 , V_202 ) ;
F_102 ( V_200 , V_204 , V_205 ) ;
if ( ! F_103 ( V_197 ) ) {
V_70 -> V_60 = 1 ;
} else {
V_207 = 1 ;
V_70 -> V_60 = 0 ;
}
V_206 = V_195 -> V_204 - V_208 ;
if ( V_206 > 0 ) {
V_201 = F_99 ( V_2 -> V_7 -> V_6 , V_195 -> V_215 + V_208 ,
V_206 , V_216 ) ;
if ( F_25 ( F_100 ( V_2 -> V_7 -> V_6 , V_201 ) ) ) {
F_104 ( V_2 -> V_7 -> V_6 ,
F_105 ( V_200 , V_214 ) ,
F_106 ( V_200 , V_204 ) ,
V_213 ) ;
return - 1 ;
}
}
F_107 ( V_2 , V_70 , V_202 , V_205 , 1 ) ;
if ( V_206 > 0 )
F_107 ( V_2 , V_70 , V_201 ,
V_206 , 0 ) ;
V_203 = V_202 + sizeof( struct V_210 ) +
F_108 ( struct V_186 , V_217 ) ;
F_109 ( V_2 -> V_7 -> V_6 , V_202 , V_205 ,
V_213 ) ;
V_196 -> V_218 = F_110 ( V_203 ) ;
V_196 -> V_219 = F_111 ( V_203 ) ;
F_112 ( V_2 , L_20 ,
F_113 ( V_187 -> V_189 . V_191 ) ) ;
F_112 ( V_2 , L_21 , F_114 ( V_196 -> V_211 ) ) ;
F_115 ( V_2 , V_220 , ( T_5 * ) V_196 , sizeof( * V_196 ) ) ;
F_115 ( V_2 , V_220 , ( T_5 * ) V_196 -> V_189 , V_208 ) ;
if ( V_198 )
F_116 ( V_2 , V_70 ,
F_113 ( V_196 -> V_204 ) ) ;
F_117 ( V_2 -> V_7 -> V_6 , V_202 , V_205 ,
V_213 ) ;
F_118 ( V_2 ,
& ( (struct V_221 * ) V_70 -> V_79 ) [ V_70 -> V_80 . V_89 ] ,
sizeof( struct V_221 ) ,
& V_187 -> V_189 , V_205 ,
V_195 -> V_215 + V_208 , V_206 ) ;
V_80 -> V_89 = F_39 ( V_80 -> V_89 , V_80 -> V_88 ) ;
F_119 ( V_2 , V_70 ) ;
if ( ( F_93 ( V_80 ) < V_80 -> V_188 ) && V_2 -> V_222 ) {
if ( V_207 ) {
V_70 -> V_60 = 1 ;
F_119 ( V_2 , V_70 ) ;
} else {
F_120 ( V_2 , V_70 ) ;
}
}
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_62 ( V_2 , V_180 , 0 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_123 ( V_2 -> V_7 -> V_223 ) ;
F_124 ( & V_2 -> V_224 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_126 ( V_2 -> V_7 -> V_223 , V_2 ) ;
F_127 ( V_2 ) ;
}
int F_128 ( struct V_225 * V_101 , struct V_1 * V_2 )
{
int V_53 ;
V_2 -> V_101 . V_226 = & V_227 ;
V_2 -> V_101 . V_2 = V_2 ;
F_129 ( & V_2 -> V_224 , ( void (*) ( unsigned long ) )
V_228 , ( unsigned long ) V_2 ) ;
F_130 ( V_2 ) ;
V_53 = F_131 ( V_2 -> V_7 -> V_223 , V_229 , V_230 ,
V_231 , V_2 ) ;
if ( V_53 ) {
F_29 ( V_2 , L_22 , V_2 -> V_7 -> V_223 ) ;
F_127 ( V_2 ) ;
return V_53 ;
}
F_132 ( & V_2 -> V_232 , V_233 ) ;
return 0 ;
}
