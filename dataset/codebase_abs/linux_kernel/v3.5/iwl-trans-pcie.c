static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
memset ( & V_4 -> V_6 , 0 , sizeof( V_4 -> V_6 ) ) ;
F_3 ( & V_6 -> V_9 ) ;
if ( F_4 ( V_6 -> V_10 || V_6 -> V_11 ) )
return - V_12 ;
V_6 -> V_10 = F_5 ( V_8 , sizeof( V_13 ) * V_14 ,
& V_6 -> V_15 , V_16 ) ;
if ( ! V_6 -> V_10 )
goto V_17;
V_6 -> V_11 = F_5 ( V_8 , sizeof( * V_6 -> V_11 ) ,
& V_6 -> V_18 , V_16 ) ;
if ( ! V_6 -> V_11 )
goto V_19;
return 0 ;
V_19:
F_6 ( V_8 , sizeof( V_13 ) * V_14 ,
V_6 -> V_10 , V_6 -> V_15 ) ;
memset ( & V_6 -> V_15 , 0 , sizeof( V_6 -> V_15 ) ) ;
V_6 -> V_10 = NULL ;
V_17:
return - V_20 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 + V_14 ; V_21 ++ ) {
if ( V_6 -> V_23 [ V_21 ] . V_24 != NULL ) {
F_8 ( V_2 -> V_8 , V_6 -> V_23 [ V_21 ] . V_25 ,
V_26 << V_4 -> V_27 ,
V_28 ) ;
F_9 ( V_6 -> V_23 [ V_21 ] . V_24 ,
V_4 -> V_27 ) ;
V_6 -> V_23 [ V_21 ] . V_24 = NULL ;
}
F_10 ( & V_6 -> V_23 [ V_21 ] . V_29 , & V_6 -> V_30 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_31 ;
const T_1 V_32 = V_33 ;
T_1 V_34 = V_35 ;
if ( V_4 -> V_36 )
V_31 = V_37 ;
else
V_31 = V_38 ;
F_12 ( V_2 , V_39 , 0 ) ;
F_12 ( V_2 , V_40 , 0 ) ;
F_12 ( V_2 , V_41 ,
( T_1 ) ( V_6 -> V_15 >> 8 ) ) ;
F_12 ( V_2 , V_42 ,
V_6 -> V_18 >> 4 ) ;
F_12 ( V_2 , V_39 ,
V_43 |
V_44 |
V_45 |
V_31 |
( V_34 << V_46 ) |
( V_32 << V_47 ) ) ;
F_13 ( V_2 , V_48 , V_49 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_21 , V_50 ;
unsigned long V_51 ;
if ( ! V_6 -> V_10 ) {
V_50 = F_1 ( V_2 ) ;
if ( V_50 )
return V_50 ;
}
F_15 ( & V_6 -> V_9 , V_51 ) ;
F_16 ( & V_6 -> V_52 ) ;
F_16 ( & V_6 -> V_30 ) ;
F_7 ( V_2 ) ;
for ( V_21 = 0 ; V_21 < V_14 ; V_21 ++ )
V_6 -> V_53 [ V_21 ] = NULL ;
V_6 -> V_54 = V_6 -> V_55 = 0 ;
V_6 -> V_56 = 0 ;
V_6 -> V_57 = 0 ;
F_17 ( & V_6 -> V_9 , V_51 ) ;
F_18 ( V_2 ) ;
F_11 ( V_2 , V_6 ) ;
F_15 ( & V_4 -> V_58 , V_51 ) ;
V_6 -> V_59 = 1 ;
F_19 ( V_2 , V_6 ) ;
F_17 ( & V_4 -> V_58 , V_51 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_51 ;
if ( ! V_6 -> V_10 ) {
F_21 ( V_2 , L_1 ) ;
return;
}
F_15 ( & V_6 -> V_9 , V_51 ) ;
F_7 ( V_2 ) ;
F_17 ( & V_6 -> V_9 , V_51 ) ;
F_6 ( V_2 -> V_8 , sizeof( V_13 ) * V_14 ,
V_6 -> V_10 , V_6 -> V_15 ) ;
memset ( & V_6 -> V_15 , 0 , sizeof( V_6 -> V_15 ) ) ;
V_6 -> V_10 = NULL ;
if ( V_6 -> V_11 )
F_6 ( V_2 -> V_8 ,
sizeof( struct V_60 ) ,
V_6 -> V_11 , V_6 -> V_18 ) ;
else
F_21 ( V_2 , L_2 ) ;
memset ( & V_6 -> V_18 , 0 , sizeof( V_6 -> V_18 ) ) ;
V_6 -> V_11 = NULL ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_39 , 0 ) ;
return F_23 ( V_2 , V_61 ,
V_62 , 1000 ) ;
}
static inline int F_24 ( struct V_1 * V_2 ,
struct V_63 * V_64 , T_2 V_65 )
{
if ( F_4 ( V_64 -> V_66 ) )
return - V_12 ;
V_64 -> V_66 = F_25 ( V_2 -> V_8 , V_65 ,
& V_64 -> V_67 , V_16 ) ;
if ( ! V_64 -> V_66 )
return - V_20 ;
V_64 -> V_65 = V_65 ;
return 0 ;
}
static inline void F_26 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
if ( F_27 ( ! V_64 -> V_66 ) )
return;
F_6 ( V_2 -> V_8 , V_64 -> V_65 , V_64 -> V_66 , V_64 -> V_67 ) ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
}
static void F_28 ( unsigned long V_68 )
{
struct V_69 * V_70 = ( void * ) V_68 ;
struct V_3 * V_4 = V_70 -> V_4 ;
struct V_1 * V_2 = F_29 ( V_4 ) ;
F_30 ( & V_70 -> V_9 ) ;
if ( V_70 -> V_71 . V_72 == V_70 -> V_71 . V_73 ) {
F_31 ( & V_70 -> V_9 ) ;
return;
}
F_31 ( & V_70 -> V_9 ) ;
F_32 ( V_2 , L_3 , V_70 -> V_71 . V_74 ,
F_33 ( V_4 -> V_75 ) ) ;
F_32 ( V_2 , L_4 ,
V_70 -> V_71 . V_72 , V_70 -> V_71 . V_73 ) ;
F_32 ( V_2 , L_5 ,
F_34 ( V_2 , F_35 ( V_70 -> V_71 . V_74 ) )
& ( V_76 - 1 ) ,
F_34 ( V_2 , F_36 ( V_70 -> V_71 . V_74 ) ) ) ;
F_37 ( V_2 -> V_77 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_69 * V_70 , int V_78 ,
T_1 V_79 )
{
T_2 V_80 = sizeof( struct V_81 ) * V_76 ;
int V_21 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_4 ( V_70 -> V_82 || V_70 -> V_83 ) )
return - V_12 ;
F_39 ( & V_70 -> V_84 , F_28 ,
( unsigned long ) V_70 ) ;
V_70 -> V_4 = V_4 ;
V_70 -> V_71 . V_85 = V_78 ;
V_70 -> V_82 = F_40 ( V_78 ,
sizeof( struct V_86 ) ,
V_16 ) ;
if ( ! V_70 -> V_82 )
goto error;
if ( V_79 == V_4 -> V_87 )
for ( V_21 = 0 ; V_21 < V_78 ; V_21 ++ ) {
V_70 -> V_82 [ V_21 ] . V_88 =
F_41 ( sizeof( struct V_89 ) ,
V_16 ) ;
if ( ! V_70 -> V_82 [ V_21 ] . V_88 )
goto error;
}
V_70 -> V_83 = F_25 ( V_2 -> V_8 , V_80 ,
& V_70 -> V_71 . V_90 , V_16 ) ;
if ( ! V_70 -> V_83 ) {
F_32 ( V_2 , L_6 , V_80 ) ;
goto error;
}
V_70 -> V_71 . V_74 = V_79 ;
return 0 ;
error:
if ( V_70 -> V_82 && V_79 == V_4 -> V_87 )
for ( V_21 = 0 ; V_21 < V_78 ; V_21 ++ )
F_42 ( V_70 -> V_82 [ V_21 ] . V_88 ) ;
F_42 ( V_70 -> V_82 ) ;
V_70 -> V_82 = NULL ;
return - V_20 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_69 * V_70 ,
int V_78 , T_1 V_79 )
{
int V_91 ;
V_70 -> V_59 = 0 ;
F_44 ( V_76 & ( V_76 - 1 ) ) ;
V_91 = F_45 ( & V_70 -> V_71 , V_76 , V_78 ,
V_79 ) ;
if ( V_91 )
return V_91 ;
F_3 ( & V_70 -> V_9 ) ;
F_12 ( V_2 , F_46 ( V_79 ) ,
V_70 -> V_71 . V_90 >> 8 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , int V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_70 = & V_4 -> V_70 [ V_79 ] ;
struct V_92 * V_71 = & V_70 -> V_71 ;
enum V_93 V_94 ;
if ( ! V_71 -> V_95 )
return;
if ( V_79 == V_4 -> V_87 )
V_94 = V_96 ;
else
V_94 = V_97 ;
F_48 ( & V_70 -> V_9 ) ;
while ( V_71 -> V_73 != V_71 -> V_72 ) {
F_49 ( V_2 , V_70 , V_94 ) ;
V_71 -> V_72 = F_50 ( V_71 -> V_72 , V_71 -> V_95 ) ;
}
F_51 ( & V_70 -> V_9 ) ;
}
static void F_52 ( struct V_1 * V_2 , int V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_70 = & V_4 -> V_70 [ V_79 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
int V_21 ;
if ( F_4 ( ! V_70 ) )
return;
F_47 ( V_2 , V_79 ) ;
if ( V_79 == V_4 -> V_87 )
for ( V_21 = 0 ; V_21 < V_70 -> V_71 . V_85 ; V_21 ++ )
F_42 ( V_70 -> V_82 [ V_21 ] . V_88 ) ;
if ( V_70 -> V_71 . V_95 ) {
F_6 ( V_8 , sizeof( struct V_81 ) *
V_70 -> V_71 . V_95 , V_70 -> V_83 , V_70 -> V_71 . V_90 ) ;
memset ( & V_70 -> V_71 . V_90 , 0 , sizeof( V_70 -> V_71 . V_90 ) ) ;
}
F_42 ( V_70 -> V_82 ) ;
V_70 -> V_82 = NULL ;
F_53 ( & V_70 -> V_84 ) ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_79 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_70 ) {
for ( V_79 = 0 ;
V_79 < V_2 -> V_98 -> V_99 -> V_100 ; V_79 ++ )
F_52 ( V_2 , V_79 ) ;
}
F_42 ( V_4 -> V_70 ) ;
V_4 -> V_70 = NULL ;
F_26 ( V_2 , & V_4 -> V_101 ) ;
F_26 ( V_2 , & V_4 -> V_102 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_91 ;
int V_79 , V_78 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_103 = V_2 -> V_98 -> V_99 -> V_100 *
sizeof( struct V_104 ) ;
if ( F_4 ( V_4 -> V_70 ) ) {
V_91 = - V_12 ;
goto error;
}
V_91 = F_24 ( V_2 , & V_4 -> V_102 ,
V_103 ) ;
if ( V_91 ) {
F_32 ( V_2 , L_7 ) ;
goto error;
}
V_91 = F_24 ( V_2 , & V_4 -> V_101 , V_105 ) ;
if ( V_91 ) {
F_32 ( V_2 , L_8 ) ;
goto error;
}
V_4 -> V_70 = F_40 ( V_2 -> V_98 -> V_99 -> V_100 ,
sizeof( struct V_69 ) , V_16 ) ;
if ( ! V_4 -> V_70 ) {
F_32 ( V_2 , L_9 ) ;
V_91 = V_20 ;
goto error;
}
for ( V_79 = 0 ; V_79 < V_2 -> V_98 -> V_99 -> V_100 ;
V_79 ++ ) {
V_78 = ( V_79 == V_4 -> V_87 ) ?
V_106 : V_107 ;
V_91 = F_38 ( V_2 , & V_4 -> V_70 [ V_79 ] ,
V_78 , V_79 ) ;
if ( V_91 ) {
F_32 ( V_2 , L_10 , V_79 ) ;
goto error;
}
}
return 0 ;
error:
F_54 ( V_2 ) ;
return V_91 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_91 ;
int V_79 , V_78 ;
unsigned long V_51 ;
bool V_108 = false ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_70 ) {
V_91 = F_55 ( V_2 ) ;
if ( V_91 )
goto error;
V_108 = true ;
}
F_15 ( & V_4 -> V_58 , V_51 ) ;
F_57 ( V_2 , V_109 , 0 ) ;
F_12 ( V_2 , V_110 ,
V_4 -> V_101 . V_67 >> 4 ) ;
F_17 ( & V_4 -> V_58 , V_51 ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_98 -> V_99 -> V_100 ;
V_79 ++ ) {
V_78 = ( V_79 == V_4 -> V_87 ) ?
V_106 : V_107 ;
V_91 = F_43 ( V_2 , & V_4 -> V_70 [ V_79 ] ,
V_78 , V_79 ) ;
if ( V_91 ) {
F_32 ( V_2 , L_11 , V_79 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_108 )
F_54 ( V_2 ) ;
return V_91 ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_59 ( V_2 , V_111 ,
V_112 ,
~ V_113 ) ;
}
static T_3 F_60 ( struct V_1 * V_2 )
{
int V_114 ;
T_3 V_115 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_116 * V_116 = V_4 -> V_116 ;
V_114 = F_61 ( V_116 ) ;
F_62 ( V_116 , V_114 + V_117 , & V_115 ) ;
return V_115 ;
}
static void F_63 ( struct V_1 * V_2 )
{
T_3 V_118 = F_60 ( V_2 ) ;
if ( ( V_118 & V_119 ) ==
V_119 ) {
F_64 ( V_2 , V_120 , V_121 ) ;
F_65 ( V_122 , V_2 -> V_8 ,
L_12 ) ;
} else {
F_66 ( V_2 , V_120 , V_121 ) ;
F_65 ( V_122 , V_2 -> V_8 ,
L_13 ) ;
}
V_2 -> V_123 = ! ( V_118 & V_124 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_91 = 0 ;
F_21 ( V_2 , L_14 ) ;
F_64 ( V_2 , V_125 ,
V_126 ) ;
F_64 ( V_2 , V_125 ,
V_127 ) ;
F_64 ( V_2 , V_128 , V_129 ) ;
F_64 ( V_2 , V_130 ,
V_131 ) ;
F_63 ( V_2 ) ;
if ( V_2 -> V_98 -> V_99 -> V_132 )
F_64 ( V_2 , V_133 ,
V_2 -> V_98 -> V_99 -> V_132 ) ;
F_64 ( V_2 , V_134 , V_135 ) ;
V_91 = F_68 ( V_2 , V_134 ,
V_136 ,
V_136 , 25000 ) ;
if ( V_91 < 0 ) {
F_21 ( V_2 , L_15 ) ;
goto V_137;
}
F_57 ( V_2 , V_138 , V_139 ) ;
F_69 ( 20 ) ;
F_70 ( V_2 , V_140 ,
V_141 ) ;
F_71 ( V_142 , & V_4 -> V_143 ) ;
V_137:
return V_91 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_91 = 0 ;
F_64 ( V_2 , V_144 , V_145 ) ;
V_91 = F_68 ( V_2 , V_144 ,
V_146 ,
V_146 , 100 ) ;
if ( V_91 )
F_73 ( V_2 , L_16 ) ;
F_21 ( V_2 , L_17 ) ;
return V_91 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_21 ( V_2 , L_18 ) ;
F_75 ( V_142 , & V_4 -> V_143 ) ;
F_72 ( V_2 ) ;
F_64 ( V_2 , V_144 , V_147 ) ;
F_69 ( 10 ) ;
F_66 ( V_2 , V_134 ,
V_135 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_51 ;
F_15 ( & V_4 -> V_58 , V_51 ) ;
F_67 ( V_2 ) ;
F_13 ( V_2 , V_48 ,
V_148 ) ;
F_17 ( & V_4 -> V_58 , V_51 ) ;
F_58 ( V_2 ) ;
F_77 ( V_2 -> V_77 ) ;
#ifndef F_78
F_14 ( V_2 ) ;
#endif
if ( F_56 ( V_2 ) )
return - V_20 ;
if ( V_2 -> V_98 -> V_99 -> V_149 ) {
F_64 ( V_2 , V_150 ,
0x800FFFFF ) ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_91 ;
F_64 ( V_2 , V_130 ,
V_151 ) ;
V_91 = F_68 ( V_2 , V_130 ,
V_151 ,
V_151 ,
V_152 ) ;
F_21 ( V_2 , L_19 , V_91 < 0 ? L_20 : L_21 ) ;
return V_91 ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_91 ;
F_21 ( V_2 , L_22 ) ;
V_91 = F_79 ( V_2 ) ;
if ( V_91 >= 0 )
return 0 ;
F_64 ( V_2 , V_130 ,
V_153 ) ;
V_91 = F_68 ( V_2 , V_130 ,
~ V_154 ,
V_154 , 150000 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_79 ( V_2 ) ;
if ( V_91 >= 0 )
return 0 ;
return V_91 ;
}
static int F_81 ( struct V_1 * V_2 , T_4 V_155 ,
const struct V_156 * V_157 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_5 V_158 = V_157 -> V_159 ;
T_1 V_160 = V_157 -> V_161 ;
T_1 V_162 = V_157 -> V_163 ;
int V_91 ;
V_4 -> V_164 = false ;
F_12 ( V_2 ,
F_82 ( V_165 ) ,
V_166 ) ;
F_12 ( V_2 ,
F_83 ( V_165 ) , V_162 ) ;
F_12 ( V_2 ,
F_84 ( V_165 ) ,
V_158 & V_167 ) ;
F_12 ( V_2 ,
F_85 ( V_165 ) ,
( F_86 ( V_158 )
<< V_168 ) | V_160 ) ;
F_12 ( V_2 ,
F_87 ( V_165 ) ,
1 << V_169 |
1 << V_170 |
V_171 ) ;
F_12 ( V_2 ,
F_82 ( V_165 ) ,
V_172 |
V_173 |
V_174 ) ;
F_88 ( V_2 , L_23 ,
V_155 ) ;
V_91 = F_89 ( V_4 -> V_175 ,
V_4 -> V_164 , 5 * V_176 ) ;
if ( ! V_91 ) {
F_32 ( V_2 , L_24 ,
V_155 ) ;
return - V_177 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
const struct V_178 * V_179 )
{
int V_91 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_180 ; V_21 ++ ) {
if ( ! V_179 -> V_181 [ V_21 ] . V_159 )
break;
V_91 = F_81 ( V_2 , V_21 , & V_179 -> V_181 [ V_21 ] ) ;
if ( V_91 )
return V_91 ;
}
F_91 ( V_2 , V_144 , 0 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
const struct V_178 * V_182 )
{
int V_91 ;
bool V_183 ;
if ( F_80 ( V_2 ) ) {
F_73 ( V_2 , L_25 ) ;
return - V_184 ;
}
F_93 ( V_2 ) ;
V_183 = F_94 ( V_2 ) ;
F_95 ( V_2 -> V_77 , V_183 ) ;
if ( V_183 )
return - V_185 ;
F_91 ( V_2 , V_186 , 0xFFFFFFFF ) ;
V_91 = F_76 ( V_2 ) ;
if ( V_91 ) {
F_32 ( V_2 , L_26 ) ;
return V_91 ;
}
F_91 ( V_2 , V_187 , V_188 ) ;
F_91 ( V_2 , V_187 ,
V_189 ) ;
F_91 ( V_2 , V_186 , 0xFFFFFFFF ) ;
F_96 ( V_2 ) ;
F_91 ( V_2 , V_187 , V_188 ) ;
F_91 ( V_2 , V_187 , V_188 ) ;
return F_90 ( V_2 , V_182 ) ;
}
static void F_97 ( struct V_1 * V_2 , T_1 V_190 )
{
struct V_3 T_6 * V_4 =
F_2 ( V_2 ) ;
F_98 ( & V_4 -> V_58 ) ;
F_57 ( V_2 , V_109 , V_190 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_191 ;
unsigned long V_51 ;
int V_21 , V_192 ;
T_1 V_193 ;
F_15 ( & V_4 -> V_58 , V_51 ) ;
V_4 -> V_194 =
F_34 ( V_2 , V_195 ) ;
V_191 = V_4 -> V_194 + V_196 ;
for (; V_191 < V_4 -> V_194 + V_197 ;
V_191 += 4 )
F_100 ( V_2 , V_191 , 0 ) ;
for (; V_191 < V_4 -> V_194 + V_198 ;
V_191 += 4 )
F_100 ( V_2 , V_191 , 0 ) ;
for (; V_191 < V_4 -> V_194 +
F_101 (
V_2 -> V_98 -> V_99 -> V_100 ) ;
V_191 += 4 )
F_100 ( V_2 , V_191 , 0 ) ;
F_57 ( V_2 , V_199 ,
V_4 -> V_102 . V_67 >> 10 ) ;
F_57 ( V_2 , V_200 , 0 ) ;
for ( V_192 = 0 ; V_192 < V_201 ; V_192 ++ )
F_12 ( V_2 , F_82 ( V_192 ) ,
V_172 |
V_202 ) ;
V_193 = F_102 ( V_2 , V_203 ) ;
F_12 ( V_2 , V_203 ,
V_193 | V_204 ) ;
F_57 ( V_2 , V_205 ,
F_103 ( V_2 , V_4 ) ) ;
F_57 ( V_2 , V_206 , 0 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_98 -> V_99 -> V_100 ; V_21 ++ ) {
F_57 ( V_2 , F_35 ( V_21 ) , 0 ) ;
F_12 ( V_2 , V_207 , 0 | ( V_21 << 8 ) ) ;
F_100 ( V_2 , V_4 -> V_194 +
F_104 ( V_21 ) , 0 ) ;
F_100 ( V_2 , V_4 -> V_194 +
F_104 ( V_21 ) +
sizeof( T_1 ) ,
( ( V_208 <<
V_209 ) &
V_210 ) |
( ( V_211 <<
V_212 ) &
V_213 ) ) ;
}
F_57 ( V_2 , V_214 ,
F_105 ( 0 , V_2 -> V_98 -> V_99 -> V_100 ) ) ;
F_97 ( V_2 , F_105 ( 0 , 7 ) ) ;
F_106 ( V_2 , V_4 -> V_87 , 0 ) ;
memset ( V_4 -> V_215 , 0 , sizeof( V_4 -> V_215 ) ) ;
memset ( V_4 -> V_216 , 0 , sizeof( V_4 -> V_216 ) ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_217 ; V_21 ++ ) {
int V_218 = V_4 -> V_219 [ V_21 ] ;
F_71 ( V_21 , V_4 -> V_216 ) ;
F_107 ( V_2 , & V_4 -> V_70 [ V_21 ] ,
V_218 , true ) ;
}
F_17 ( & V_4 -> V_58 , V_51 ) ;
F_108 ( V_2 , V_140 ,
V_141 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
F_110 ( V_2 ) ;
F_99 ( V_2 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_220 , V_79 , V_91 ;
unsigned long V_51 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( & V_4 -> V_58 , V_51 ) ;
F_97 ( V_2 , 0 ) ;
for ( V_220 = 0 ; V_220 < V_201 ; V_220 ++ ) {
F_12 ( V_2 ,
F_82 ( V_220 ) , 0x0 ) ;
V_91 = F_23 ( V_2 , V_221 ,
F_112 ( V_220 ) ,
1000 ) ;
if ( V_91 < 0 )
F_32 ( V_2 , L_27
L_28 , V_220 ,
F_102 ( V_2 ,
V_221 ) ) ;
}
F_17 ( & V_4 -> V_58 , V_51 ) ;
if ( ! V_4 -> V_70 ) {
F_73 ( V_2 , L_29 ) ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_2 -> V_98 -> V_99 -> V_100 ;
V_79 ++ )
F_47 ( V_2 , V_79 ) ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( & V_4 -> V_58 , V_51 ) ;
F_114 ( V_2 ) ;
F_17 ( & V_4 -> V_58 , V_51 ) ;
F_115 ( V_2 ) ;
if ( F_116 ( V_142 , & V_4 -> V_143 ) ) {
F_111 ( V_2 ) ;
#ifndef F_78
F_22 ( V_2 ) ;
#endif
F_57 ( V_2 , V_222 ,
V_139 ) ;
F_69 ( 5 ) ;
}
F_66 ( V_2 , V_134 ,
V_223 ) ;
F_74 ( V_2 ) ;
F_15 ( & V_4 -> V_58 , V_51 ) ;
F_114 ( V_2 ) ;
F_17 ( & V_4 -> V_58 , V_51 ) ;
F_93 ( V_2 ) ;
F_117 ( V_4 -> V_224 ) ;
F_118 ( & V_4 -> V_225 ) ;
F_119 ( & V_4 -> V_226 ) ;
F_91 ( V_2 , V_144 , V_227 ) ;
F_75 ( V_228 , & V_4 -> V_143 ) ;
F_75 ( V_229 , & V_4 -> V_143 ) ;
F_75 ( V_142 , & V_4 -> V_143 ) ;
F_75 ( V_230 , & V_4 -> V_143 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_91 ( V_2 , V_231 ,
V_232 ) ;
F_114 ( V_2 ) ;
F_66 ( V_2 , V_134 ,
V_223 ) ;
}
static int F_121 ( struct V_1 * V_2 , struct V_233 * V_234 ,
struct V_89 * V_235 , int V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_236 * V_237 = (struct V_236 * ) V_234 -> V_68 ;
struct V_238 * V_239 = (struct V_238 * ) V_235 -> V_240 ;
struct V_241 * V_242 ;
struct V_69 * V_70 ;
struct V_92 * V_71 ;
T_5 V_243 = 0 ;
T_5 V_244 ;
T_5 V_245 ;
T_3 V_161 , V_246 , V_247 ;
T_4 V_248 = 0 ;
T_7 V_249 = V_237 -> V_250 ;
T_4 V_251 = F_122 ( V_249 ) ;
T_3 T_6 V_252 ;
V_70 = & V_4 -> V_70 [ V_79 ] ;
V_71 = & V_70 -> V_71 ;
if ( F_27 ( ! F_116 ( V_79 , V_4 -> V_216 ) ) ) {
F_123 ( 1 ) ;
return - V_12 ;
}
F_30 ( & V_70 -> V_9 ) ;
V_70 -> V_82 [ V_71 -> V_73 ] . V_234 = V_234 ;
V_70 -> V_82 [ V_71 -> V_73 ] . V_88 = V_235 ;
V_235 -> V_237 . V_88 = V_253 ;
V_235 -> V_237 . V_254 = F_124 ( ( T_3 ) ( F_125 ( V_79 ) |
F_126 ( V_71 -> V_73 ) ) ) ;
V_242 = & V_70 -> V_82 [ V_71 -> V_73 ] . V_255 ;
V_161 = sizeof( struct V_238 ) +
sizeof( struct V_256 ) + V_251 ;
V_246 = ( V_161 + 3 ) & ~ 3 ;
if ( V_246 != V_161 )
V_239 -> V_257 |= V_258 ;
V_244 = F_127 ( V_2 -> V_8 ,
& V_235 -> V_237 , V_246 ,
V_96 ) ;
if ( F_27 ( F_128 ( V_2 -> V_8 , V_244 ) ) )
goto V_259;
F_129 ( V_242 , V_260 , V_244 ) ;
F_130 ( V_242 , V_161 , V_246 ) ;
if ( ! F_131 ( V_249 ) ) {
V_70 -> V_59 = 1 ;
} else {
V_248 = 1 ;
V_70 -> V_59 = 0 ;
}
V_247 = V_234 -> V_161 - V_251 ;
if ( V_247 > 0 ) {
V_243 = F_127 ( V_2 -> V_8 , V_234 -> V_68 + V_251 ,
V_247 , V_97 ) ;
if ( F_27 ( F_128 ( V_2 -> V_8 , V_243 ) ) ) {
F_132 ( V_2 -> V_8 ,
F_133 ( V_242 , V_260 ) ,
F_134 ( V_242 , V_161 ) ,
V_96 ) ;
goto V_259;
}
}
F_135 ( V_2 , V_70 , V_244 , V_246 , 1 ) ;
if ( V_247 > 0 )
F_135 ( V_2 , V_70 , V_243 ,
V_247 , 0 ) ;
V_245 = V_244 + sizeof( struct V_256 ) +
F_136 ( struct V_238 , V_261 ) ;
F_137 ( V_2 -> V_8 , V_244 , V_246 ,
V_96 ) ;
V_239 -> V_262 = F_138 ( V_245 ) ;
V_239 -> V_263 = F_86 ( V_245 ) ;
F_139 ( V_2 , L_30 ,
F_140 ( V_235 -> V_237 . V_254 ) ) ;
F_139 ( V_2 , L_31 , F_141 ( V_239 -> V_257 ) ) ;
F_142 ( V_2 , V_70 , F_140 ( V_239 -> V_161 ) ) ;
F_143 ( V_2 -> V_8 , V_244 , V_246 ,
V_96 ) ;
F_144 ( V_2 -> V_8 ,
& ( (struct V_81 * ) V_70 -> V_83 ) [ V_70 -> V_71 . V_73 ] ,
sizeof( struct V_81 ) ,
& V_235 -> V_237 , V_246 ,
V_234 -> V_68 + V_251 , V_247 ) ;
if ( V_71 -> V_72 == V_71 -> V_73 && V_4 -> V_75 )
F_145 ( & V_70 -> V_84 , V_264 + V_4 -> V_75 ) ;
V_71 -> V_73 = F_50 ( V_71 -> V_73 , V_71 -> V_95 ) ;
F_146 ( V_2 , V_70 ) ;
if ( F_147 ( V_71 ) < V_71 -> V_265 ) {
if ( V_248 ) {
V_70 -> V_59 = 1 ;
F_146 ( V_2 , V_70 ) ;
} else {
F_148 ( V_2 , V_70 ) ;
}
}
F_31 ( & V_70 -> V_9 ) ;
return 0 ;
V_259:
F_31 ( & V_70 -> V_9 ) ;
return - 1 ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
int V_50 ;
bool V_183 ;
V_4 -> V_266 = V_267 ;
if ( ! V_4 -> V_268 ) {
F_150 ( & V_4 -> V_225 , ( void (*) ( unsigned long ) )
V_269 , ( unsigned long ) V_2 ) ;
F_151 ( V_2 ) ;
V_50 = F_152 ( V_4 -> V_224 , V_270 , V_271 ,
V_272 , V_2 ) ;
if ( V_50 ) {
F_32 ( V_2 , L_32 ,
V_4 -> V_224 ) ;
goto error;
}
F_153 ( & V_4 -> V_226 , V_273 ) ;
V_4 -> V_268 = true ;
}
V_50 = F_80 ( V_2 ) ;
if ( V_50 ) {
F_32 ( V_2 , L_33 , V_50 ) ;
goto V_274;
}
F_67 ( V_2 ) ;
F_93 ( V_2 ) ;
V_183 = F_94 ( V_2 ) ;
F_95 ( V_2 -> V_77 , V_183 ) ;
return V_50 ;
V_274:
F_154 ( V_4 -> V_224 , V_2 ) ;
error:
F_155 ( V_2 ) ;
F_118 ( & V_4 -> V_225 ) ;
return V_50 ;
}
static void F_156 ( struct V_1 * V_2 ,
bool V_275 )
{
bool V_183 ;
unsigned long V_51 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_74 ( V_2 ) ;
F_15 ( & V_4 -> V_58 , V_51 ) ;
F_114 ( V_2 ) ;
F_17 ( & V_4 -> V_58 , V_51 ) ;
F_91 ( V_2 , V_186 , 0xFFFFFFFF ) ;
if ( ! V_275 ) {
F_93 ( V_2 ) ;
V_183 = F_94 ( V_2 ) ;
F_95 ( V_2 -> V_77 , V_183 ) ;
}
}
static void F_157 ( struct V_1 * V_2 , int V_79 , int V_276 ,
struct V_277 * V_278 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_70 = & V_4 -> V_70 [ V_79 ] ;
int V_279 = V_276 & ( V_70 -> V_71 . V_95 - 1 ) ;
int V_280 = 0 ;
F_30 ( & V_70 -> V_9 ) ;
if ( V_70 -> V_71 . V_72 != V_279 ) {
F_158 ( V_2 , L_34 ,
V_79 , V_70 -> V_71 . V_72 , V_279 , V_276 ) ;
V_280 = F_159 ( V_2 , V_79 , V_279 , V_278 ) ;
if ( F_147 ( & V_70 -> V_71 ) > V_70 -> V_71 . V_281 )
F_160 ( V_2 , V_70 ) ;
}
F_31 ( & V_70 -> V_9 ) ;
}
static void F_161 ( struct V_1 * V_2 , T_1 V_282 , T_4 V_283 )
{
F_162 ( V_283 , F_2 ( V_2 ) -> V_284 + V_282 ) ;
}
static void F_163 ( struct V_1 * V_2 , T_1 V_282 , T_1 V_283 )
{
F_164 ( V_283 , F_2 ( V_2 ) -> V_284 + V_282 ) ;
}
static T_1 F_165 ( struct V_1 * V_2 , T_1 V_282 )
{
return F_166 ( F_2 ( V_2 ) -> V_284 + V_282 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
const struct V_285 * V_286 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_87 = V_286 -> V_87 ;
if ( F_4 ( V_286 -> V_287 > V_288 ) )
V_4 -> V_287 = 0 ;
else
V_4 -> V_287 = V_286 -> V_287 ;
if ( V_4 -> V_287 )
memcpy ( V_4 -> V_289 , V_286 -> V_289 ,
V_4 -> V_287 * sizeof( T_4 ) ) ;
V_4 -> V_217 = V_286 -> V_290 ;
if ( F_4 ( V_4 -> V_217 > V_291 ) )
V_4 -> V_217 = V_291 ;
F_4 ( ! V_4 -> V_217 ) ;
memcpy ( V_4 -> V_219 , V_286 -> V_292 ,
V_4 -> V_217 * sizeof( T_4 ) ) ;
V_4 -> V_36 = V_286 -> V_36 ;
if ( V_4 -> V_36 )
V_4 -> V_27 = F_168 ( 8 * 1024 ) ;
else
V_4 -> V_27 = F_168 ( 4 * 1024 ) ;
V_4 -> V_75 =
F_169 ( V_286 -> V_293 ) ;
V_4 -> V_294 = V_286 -> V_294 ;
}
void F_170 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
F_54 ( V_2 ) ;
#ifndef F_78
F_20 ( V_2 ) ;
#endif
if ( V_4 -> V_268 == true ) {
F_154 ( V_4 -> V_224 , V_2 ) ;
F_155 ( V_2 ) ;
}
F_171 ( V_4 -> V_116 ) ;
F_172 ( V_4 -> V_284 ) ;
F_173 ( V_4 -> V_116 ) ;
F_174 ( V_4 -> V_116 ) ;
F_42 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 , bool V_295 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_295 )
F_71 ( V_230 , & V_4 -> V_143 ) ;
else
F_75 ( V_230 , & V_4 -> V_143 ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_177 ( struct V_1 * V_2 )
{
bool V_183 ;
F_93 ( V_2 ) ;
V_183 = F_94 ( V_2 ) ;
F_95 ( V_2 -> V_77 , V_183 ) ;
if ( ! V_183 )
F_96 ( V_2 ) ;
return 0 ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_70 ;
struct V_92 * V_71 ;
int V_296 ;
unsigned long V_297 = V_264 ;
int V_91 = 0 ;
for ( V_296 = 0 ; V_296 < V_2 -> V_98 -> V_99 -> V_100 ; V_296 ++ ) {
if ( V_296 == V_4 -> V_87 )
continue;
V_70 = & V_4 -> V_70 [ V_296 ] ;
V_71 = & V_70 -> V_71 ;
while ( V_71 -> V_72 != V_71 -> V_73 && ! F_179 ( V_264 ,
V_297 + F_169 ( V_298 ) ) )
F_180 ( 1 ) ;
if ( V_71 -> V_72 != V_71 -> V_73 ) {
F_32 ( V_2 , L_35 ) ;
V_91 = - V_177 ;
break;
}
}
return V_91 ;
}
static const char * F_181 ( int V_88 )
{
#define F_182 ( T_8 ) case x: return #x
switch ( V_88 ) {
F_182 ( V_42 ) ;
F_182 ( V_41 ) ;
F_182 ( V_299 ) ;
F_182 ( V_39 ) ;
F_182 ( V_300 ) ;
F_182 ( V_61 ) ;
F_182 ( V_301 ) ;
F_182 ( V_221 ) ;
F_182 ( V_302 ) ;
default:
return L_36 ;
}
#undef F_182
}
int F_183 ( struct V_1 * V_2 , char * * V_303 , bool V_304 )
{
int V_21 ;
#ifdef F_184
int V_114 = 0 ;
T_2 V_305 = 0 ;
#endif
static const T_1 V_306 [] = {
V_42 ,
V_41 ,
V_299 ,
V_39 ,
V_300 ,
V_61 ,
V_301 ,
V_221 ,
V_302
} ;
#ifdef F_184
if ( V_304 ) {
V_305 = F_185 ( V_306 ) * 48 + 40 ;
* V_303 = F_41 ( V_305 , V_16 ) ;
if ( ! * V_303 )
return - V_20 ;
V_114 += F_186 ( * V_303 + V_114 , V_305 - V_114 ,
L_37 ) ;
for ( V_21 = 0 ; V_21 < F_185 ( V_306 ) ; V_21 ++ ) {
V_114 += F_186 ( * V_303 + V_114 , V_305 - V_114 ,
L_38 ,
F_181 ( V_306 [ V_21 ] ) ,
F_102 ( V_2 , V_306 [ V_21 ] ) ) ;
}
return V_114 ;
}
#endif
F_32 ( V_2 , L_37 ) ;
for ( V_21 = 0 ; V_21 < F_185 ( V_306 ) ; V_21 ++ ) {
F_32 ( V_2 , L_38 ,
F_181 ( V_306 [ V_21 ] ) ,
F_102 ( V_2 , V_306 [ V_21 ] ) ) ;
}
return 0 ;
}
static const char * F_187 ( int V_88 )
{
#define F_182 ( T_8 ) case x: return #x
switch ( V_88 ) {
F_182 ( V_130 ) ;
F_182 ( V_48 ) ;
F_182 ( V_186 ) ;
F_182 ( V_307 ) ;
F_182 ( V_308 ) ;
F_182 ( V_309 ) ;
F_182 ( V_144 ) ;
F_182 ( V_134 ) ;
F_182 ( V_310 ) ;
F_182 ( V_311 ) ;
F_182 ( V_312 ) ;
F_182 ( V_313 ) ;
F_182 ( V_120 ) ;
F_182 ( V_314 ) ;
F_182 ( V_315 ) ;
F_182 ( V_316 ) ;
F_182 ( V_317 ) ;
F_182 ( V_318 ) ;
F_182 ( V_319 ) ;
F_182 ( V_125 ) ;
F_182 ( V_133 ) ;
F_182 ( V_320 ) ;
F_182 ( V_128 ) ;
default:
return L_36 ;
}
#undef F_182
}
void F_188 ( struct V_1 * V_2 )
{
int V_21 ;
static const T_1 V_321 [] = {
V_130 ,
V_48 ,
V_186 ,
V_307 ,
V_308 ,
V_309 ,
V_144 ,
V_134 ,
V_310 ,
V_311 ,
V_312 ,
V_313 ,
V_120 ,
V_314 ,
V_315 ,
V_316 ,
V_317 ,
V_318 ,
V_319 ,
V_125 ,
V_133 ,
V_320 ,
V_128
} ;
F_32 ( V_2 , L_39 ) ;
F_32 ( V_2 , L_40
L_41 ) ;
for ( V_21 = 0 ; V_21 < F_185 ( V_321 ) ; V_21 ++ ) {
F_32 ( V_2 , L_42 ,
F_187 ( V_321 [ V_21 ] ) ,
F_189 ( V_2 , V_321 [ V_21 ] ) ) ;
}
}
static T_9 F_190 ( struct V_322 * V_322 ,
char T_10 * V_323 ,
T_2 V_324 , T_11 * V_325 )
{
struct V_1 * V_2 = V_322 -> V_326 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 * V_70 ;
struct V_92 * V_71 ;
char * V_303 ;
int V_114 = 0 ;
int V_296 ;
int V_91 ;
T_2 V_305 ;
V_305 = sizeof( char ) * 64 * V_2 -> V_98 -> V_99 -> V_100 ;
if ( ! V_4 -> V_70 )
return - V_327 ;
V_303 = F_191 ( V_305 , V_16 ) ;
if ( ! V_303 )
return - V_20 ;
for ( V_296 = 0 ; V_296 < V_2 -> V_98 -> V_99 -> V_100 ; V_296 ++ ) {
V_70 = & V_4 -> V_70 [ V_296 ] ;
V_71 = & V_70 -> V_71 ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 ,
L_43 ,
V_296 , V_71 -> V_72 , V_71 -> V_73 ,
! ! F_116 ( V_296 , V_4 -> V_216 ) ,
! ! F_116 ( V_296 , V_4 -> V_215 ) ) ;
}
V_91 = F_192 ( V_323 , V_324 , V_325 , V_303 , V_114 ) ;
F_42 ( V_303 ) ;
return V_91 ;
}
static T_9 F_193 ( struct V_322 * V_322 ,
char T_10 * V_323 ,
T_2 V_324 , T_11 * V_325 ) {
struct V_1 * V_2 = V_322 -> V_326 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
char V_303 [ 256 ] ;
int V_114 = 0 ;
const T_2 V_305 = sizeof( V_303 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_44 ,
V_6 -> V_54 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_45 ,
V_6 -> V_55 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_46 ,
V_6 -> V_57 ) ;
if ( V_6 -> V_11 ) {
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_47 ,
F_140 ( V_6 -> V_11 -> V_328 ) & 0x0FFF ) ;
} else {
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 ,
L_48 ) ;
}
return F_192 ( V_323 , V_324 , V_325 , V_303 , V_114 ) ;
}
static T_9 F_194 ( struct V_322 * V_322 ,
char T_10 * V_323 ,
T_2 V_324 , T_11 * V_325 ) {
struct V_1 * V_2 = V_322 -> V_326 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_329 * V_330 = & V_4 -> V_330 ;
int V_114 = 0 ;
char * V_303 ;
int V_305 = 24 * 64 ;
T_9 V_91 ;
V_303 = F_191 ( V_305 , V_16 ) ;
if ( ! V_303 )
return - V_20 ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 ,
L_49 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_50 ,
V_330 -> V_331 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_51 ,
V_330 -> V_332 ) ;
if ( V_330 -> V_332 || V_330 -> V_331 ) {
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 ,
L_52 ,
V_330 -> V_333 ) ;
}
#ifdef F_184
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_53 ,
V_330 -> V_334 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_54 ,
V_330 -> V_335 ) ;
#endif
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 ,
L_55 , V_330 -> V_336 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_56 ,
V_330 -> V_337 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_57 ,
V_330 -> V_338 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 ,
L_58 , V_330 -> V_339 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_59 ,
V_330 -> V_340 ) ;
V_114 += F_186 ( V_303 + V_114 , V_305 - V_114 , L_60 ,
V_330 -> V_341 ) ;
V_91 = F_192 ( V_323 , V_324 , V_325 , V_303 , V_114 ) ;
F_42 ( V_303 ) ;
return V_91 ;
}
static T_9 F_195 ( struct V_322 * V_322 ,
const char T_10 * V_323 ,
T_2 V_324 , T_11 * V_325 )
{
struct V_1 * V_2 = V_322 -> V_326 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_329 * V_330 = & V_4 -> V_330 ;
char V_303 [ 8 ] ;
int V_342 ;
T_1 V_343 ;
memset ( V_303 , 0 , sizeof( V_303 ) ) ;
V_342 = F_196 ( V_324 , sizeof( V_303 ) - 1 ) ;
if ( F_197 ( V_303 , V_323 , V_342 ) )
return - V_344 ;
if ( sscanf ( V_303 , L_61 , & V_343 ) != 1 )
return - V_344 ;
if ( V_343 == 0 )
memset ( V_330 , 0 , sizeof( * V_330 ) ) ;
return V_324 ;
}
static T_9 F_198 ( struct V_322 * V_322 ,
const char T_10 * V_323 ,
T_2 V_324 , T_11 * V_325 )
{
struct V_1 * V_2 = V_322 -> V_326 ;
char V_303 [ 8 ] ;
int V_342 ;
int V_345 ;
memset ( V_303 , 0 , sizeof( V_303 ) ) ;
V_342 = F_196 ( V_324 , sizeof( V_303 ) - 1 ) ;
if ( F_197 ( V_303 , V_323 , V_342 ) )
return - V_344 ;
if ( sscanf ( V_303 , L_62 , & V_345 ) != 1 )
return - V_344 ;
F_188 ( V_2 ) ;
return V_324 ;
}
static T_9 F_199 ( struct V_322 * V_322 ,
char T_10 * V_323 ,
T_2 V_324 , T_11 * V_325 )
{
struct V_1 * V_2 = V_322 -> V_326 ;
char * V_303 ;
int V_114 = 0 ;
T_9 V_91 = - V_344 ;
V_91 = V_114 = F_183 ( V_2 , & V_303 , true ) ;
if ( V_303 ) {
V_91 = F_192 ( V_323 ,
V_324 , V_325 , V_303 , V_114 ) ;
F_42 ( V_303 ) ;
}
return V_91 ;
}
static T_9 F_200 ( struct V_322 * V_322 ,
const char T_10 * V_323 ,
T_2 V_324 , T_11 * V_325 )
{
struct V_1 * V_2 = V_322 -> V_326 ;
if ( ! V_2 -> V_77 )
return - V_327 ;
F_37 ( V_2 -> V_77 ) ;
return V_324 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_346 * V_347 )
{
F_202 ( V_348 , V_347 , V_349 ) ;
F_202 ( V_350 , V_347 , V_349 ) ;
F_202 ( V_351 , V_347 , V_352 | V_349 ) ;
F_202 ( V_345 , V_347 , V_352 ) ;
F_202 ( V_353 , V_347 , V_349 ) ;
F_202 ( V_354 , V_347 , V_352 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_346 * V_347 )
{ return 0 ; }
struct V_1 * F_203 ( struct V_116 * V_355 ,
const struct V_356 * V_357 ,
const struct V_358 * V_98 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_3 V_359 ;
int V_50 ;
V_2 = F_191 ( sizeof( struct V_1 ) +
sizeof( struct V_3 ) , V_16 ) ;
if ( F_4 ( ! V_2 ) )
return NULL ;
V_4 = F_2 ( V_2 ) ;
V_2 -> V_360 = & V_361 ;
V_2 -> V_98 = V_98 ;
V_4 -> V_2 = V_2 ;
F_3 ( & V_4 -> V_58 ) ;
F_204 ( & V_4 -> V_175 ) ;
F_205 ( V_355 , V_362 | V_363 |
V_364 ) ;
if ( F_206 ( V_355 ) ) {
V_50 = - V_365 ;
goto V_366;
}
F_207 ( V_355 ) ;
V_50 = F_208 ( V_355 , F_209 ( 36 ) ) ;
if ( ! V_50 )
V_50 = F_210 ( V_355 , F_209 ( 36 ) ) ;
if ( V_50 ) {
V_50 = F_208 ( V_355 , F_209 ( 32 ) ) ;
if ( ! V_50 )
V_50 = F_210 ( V_355 ,
F_209 ( 32 ) ) ;
if ( V_50 ) {
F_65 ( V_367 , & V_355 -> V_8 ,
L_63 ) ;
goto V_368;
}
}
V_50 = F_211 ( V_355 , V_272 ) ;
if ( V_50 ) {
F_65 ( V_367 , & V_355 -> V_8 , L_64 ) ;
goto V_368;
}
V_4 -> V_284 = F_212 ( V_355 , 0 ) ;
if ( ! V_4 -> V_284 ) {
F_65 ( V_367 , & V_355 -> V_8 , L_65 ) ;
V_50 = - V_365 ;
goto V_369;
}
F_65 ( V_122 , & V_355 -> V_8 ,
L_66 ,
( unsigned long long ) F_213 ( V_355 , 0 ) ) ;
F_65 ( V_122 , & V_355 -> V_8 ,
L_67 , V_4 -> V_284 ) ;
F_65 ( V_122 , & V_355 -> V_8 ,
L_68 , V_355 -> V_370 ) ;
F_214 ( V_355 , V_371 , 0x00 ) ;
V_50 = F_215 ( V_355 ) ;
if ( V_50 )
F_65 ( V_367 , & V_355 -> V_8 ,
L_69 , V_50 ) ;
V_2 -> V_8 = & V_355 -> V_8 ;
V_4 -> V_224 = V_355 -> V_224 ;
V_4 -> V_116 = V_355 ;
V_2 -> V_372 = F_189 ( V_2 , V_310 ) ;
V_2 -> V_373 = ( V_355 -> V_7 << 16 ) + V_355 -> V_374 ;
snprintf ( V_2 -> V_375 , sizeof( V_2 -> V_375 ) ,
L_70 , V_355 -> V_7 , V_355 -> V_374 ) ;
F_62 ( V_355 , V_376 , & V_359 ) ;
if ( V_359 & V_377 ) {
V_359 &= ~ V_377 ;
F_216 ( V_355 , V_376 , V_359 ) ;
}
F_204 ( & V_2 -> V_378 ) ;
F_3 ( & V_2 -> V_379 ) ;
return V_2 ;
V_369:
F_173 ( V_355 ) ;
V_368:
F_174 ( V_355 ) ;
V_366:
F_42 ( V_2 ) ;
return NULL ;
}
