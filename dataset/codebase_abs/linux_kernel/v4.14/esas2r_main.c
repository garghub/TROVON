static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
return (struct V_1 * ) V_7 -> V_8 ;
}
static T_1 F_4 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
return F_5 ( V_15 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_6 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
return F_7 ( V_15 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_8 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
return F_9 ( V_15 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_10 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
int V_16 = F_11 ( sizeof( struct V_17 ) , V_14 ) ;
int V_18 = 0 ;
V_18 = F_12 ( V_15 , V_12 , V_13 , V_14 ) ;
if ( V_18 < 0 )
V_18 = 0 ;
return V_16 ;
}
static T_1 F_13 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
return F_14 ( V_15 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_15 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
return F_16 ( V_15 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_17 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
int V_16 = F_18 ( T_3 , sizeof( struct V_19 ) , V_20 ) ;
memcpy ( V_12 , V_15 -> V_21 , V_16 ) ;
return V_16 ;
}
static T_1 F_19 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_22 * V_23 ;
int V_18 = - V_24 ;
V_23 = F_20 ( V_15 ) ;
if ( V_23 == NULL )
return - V_25 ;
if ( F_21 ( V_15 , V_23 , (struct V_19 * ) V_12 ) )
V_18 = V_14 ;
F_22 ( V_15 , V_23 ) ;
return V_18 ;
}
static T_1 F_23 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
F_24 ( V_15 , (struct V_19 * ) V_12 ) ;
return sizeof( struct V_19 ) ;
}
static T_1 F_25 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
int V_16 = F_18 ( T_3 , sizeof( struct V_26 ) , V_20 ) ;
if ( ! V_15 -> V_27 )
return - V_25 ;
if ( F_26 ( V_15 , V_15 -> V_27 ) != V_28 )
return - V_25 ;
memcpy ( V_12 , V_15 -> V_27 , V_16 ) ;
return V_16 ;
}
static T_1 F_27 ( struct V_9 * V_9 , struct V_2 * V_3 ,
struct V_10 * V_11 ,
char * V_12 , T_2 V_13 , T_3 V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
int V_16 = F_11 ( sizeof( struct V_26 ) , V_14 ) ;
if ( ! V_15 -> V_27 ) {
V_15 -> V_27 = F_28 ( sizeof( struct V_26 ) ,
V_29 ) ;
if ( V_15 -> V_27 == NULL ) {
F_29 ( V_30 ,
L_1 ,
sizeof( struct V_26 ) ) ;
return - V_25 ;
}
}
memset ( V_15 -> V_27 , 0 , sizeof( struct V_26 ) ) ;
memcpy ( V_15 -> V_27 , V_12 , V_16 ) ;
return V_16 ;
}
static int F_30 ( struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
struct V_6 * V_7 = NULL ;
struct V_1 * V_15 ;
int V_35 ;
T_3 V_36 = sizeof( struct V_1 )
+ ( ( V_37 ) +
1 ) * sizeof( struct V_22 ) ;
F_31 ( V_38 , & ( V_32 -> V_5 ) ,
L_2 ,
V_32 -> V_39 ,
V_32 -> V_4 ,
V_32 -> V_40 ,
V_32 -> V_41 ) ;
F_31 ( V_42 , & ( V_32 -> V_5 ) ,
L_3
L_4 ,
V_32 -> V_43 . V_44 ) ;
V_35 = F_32 ( V_32 ) ;
if ( V_35 != 0 ) {
F_31 ( V_45 , & ( V_32 -> V_5 ) ,
L_5 ,
V_35 ) ;
return - V_46 ;
}
F_31 ( V_42 , & ( V_32 -> V_5 ) ,
L_6 ) ;
F_31 ( V_42 , & ( V_32 -> V_5 ) ,
L_7 ,
V_32 -> V_43 . V_44 ) ;
V_7 = F_33 ( & V_47 , V_36 ) ;
if ( V_7 == NULL ) {
F_29 ( V_45 , L_8 ) ;
return - V_46 ;
}
memset ( V_7 -> V_8 , 0 , V_36 ) ;
V_15 = (struct V_1 * ) V_7 -> V_8 ;
F_29 ( V_42 , L_9 , V_7 ) ;
V_7 -> V_48 = V_49 + 1 ;
V_7 -> V_50 = 255 ;
V_7 -> V_51 = 16 ;
V_7 -> V_52 = V_52 ;
V_7 -> V_53 = V_53 ;
V_7 -> V_54 = V_7 -> V_48 + 1 ;
V_7 -> V_55 = 0 ;
V_7 -> V_56 = V_57 ;
V_7 -> V_58 = V_58 ;
V_7 -> V_59 = V_60 ;
F_29 ( V_42 , L_10 ) ;
F_34 ( V_32 ) ;
if ( ! F_35 ( V_7 , V_32 , V_57 ) ) {
F_29 ( V_45 ,
L_11 ,
V_32 -> V_61 -> V_62 ,
V_32 -> V_63 ) ;
F_31 ( V_42 , & ( V_7 -> V_64 ) ,
L_12 ) ;
F_36 ( V_7 ) ;
return 0 ;
}
F_29 ( V_42 , L_13 , V_32 ,
V_7 -> V_8 ) ;
F_37 ( V_32 , V_7 ) ;
F_29 ( V_42 , L_14 ) ;
V_35 = F_38 ( V_7 , & V_32 -> V_5 ) ;
if ( V_35 ) {
F_29 ( V_45 , L_15 , V_35 ) ;
F_31 ( V_45 , & ( V_7 -> V_64 ) ,
L_16 ) ;
F_31 ( V_42 , & ( V_7 -> V_64 ) ,
L_12 ) ;
F_36 ( V_7 ) ;
F_31 ( V_42 , & ( V_7 -> V_64 ) ,
L_17 ,
V_32 ) ;
F_37 ( V_32 , NULL ) ;
return - V_46 ;
}
F_39 ( V_15 ) ;
F_31 ( V_42 , & ( V_7 -> V_64 ) ,
L_18 ) ;
F_40 ( V_7 ) ;
if ( F_41 ( & V_7 -> V_65 . V_3 , & V_66 ) )
F_31 ( V_30 , & ( V_7 -> V_64 ) ,
L_19 ) ;
else
V_15 -> V_67 = 1 ;
if ( F_41 ( & V_7 -> V_65 . V_3 , & V_68 ) )
F_31 ( V_30 , & ( V_7 -> V_64 ) ,
L_20 ) ;
else
V_15 -> V_69 = 1 ;
if ( F_41 ( & V_7 -> V_65 . V_3 , & V_70 ) )
F_31 ( V_30 , & ( V_7 -> V_64 ) ,
L_21 ) ;
else
V_15 -> V_71 = 1 ;
if ( F_41 ( & V_7 -> V_65 . V_3 , & V_72 ) )
F_31 ( V_30 , & ( V_7 -> V_64 ) ,
L_22 ) ;
else
V_15 -> V_73 = 1 ;
if ( F_41 ( & V_7 -> V_65 . V_3 , & V_74 ) )
F_31 ( V_30 , & ( V_7 -> V_64 ) ,
L_23 ) ;
else
V_15 -> V_75 = 1 ;
if ( F_41 ( & V_7 -> V_65 . V_3 ,
& V_76 ) )
F_31 ( V_30 , & ( V_7 -> V_64 ) ,
L_24 ) ;
else
V_15 -> V_77 = 1 ;
V_57 ++ ;
return 0 ;
}
static void F_42 ( struct V_31 * V_78 )
{
struct V_6 * V_7 ;
int V_79 ;
if ( V_78 == NULL ) {
F_29 ( V_30 , L_25 ) ;
return;
}
V_7 = F_43 ( V_78 ) ;
if ( V_7 == NULL ) {
return;
}
F_31 ( V_42 , & ( V_78 -> V_5 ) ,
L_26
L_27 , V_78 ,
V_7 ) ;
V_79 = F_44 ( V_7 ) ;
if ( V_79 < 0 )
F_31 ( V_30 , & ( V_78 -> V_5 ) ,
L_28 ,
V_80 ) ;
V_57 -- ;
if ( V_57 == 0 )
F_44 ( NULL ) ;
}
static int T_4 F_45 ( void )
{
int V_81 ;
F_29 ( V_42 , L_29 , V_80 ) ;
if ( V_52 < 1 ) {
F_29 ( V_30 ,
L_30
L_31 ) ;
V_52 = 1 ;
} else if ( V_52 > 2048 ) {
F_29 ( V_30 ,
L_32
L_33 ) ;
V_52 = 2048 ;
}
if ( V_53 < 1 ) {
F_29 ( V_30 ,
L_34
L_31 ) ;
V_53 = 1 ;
} else if ( V_53 > 2048 ) {
F_29 ( V_30 ,
L_35
L_36 ) ;
V_53 = 2048 ;
}
if ( V_58 < 32 ) {
F_29 ( V_30 ,
L_37
L_33 ) ;
V_58 = 32 ;
}
if ( V_60 < 1 ) {
F_29 ( V_30 ,
L_38
L_39 ) ;
V_60 = 1 ;
} else if ( V_60 > 0xffff ) {
F_29 ( V_30 ,
L_40
L_41 ) ;
V_60 = 0xffff ;
}
V_82 &= ~ ( V_83 - 1 ) ;
if ( V_82 < V_84 )
V_82 = V_84 ;
else if ( V_82 > V_85 )
V_82 = V_85 ;
if ( V_86 < V_87 )
V_86 = V_87 ;
else if ( V_86 > V_88 )
V_86 = V_88 ;
if ( V_37 < V_89 )
V_37 = V_89 ;
else if ( V_37 > V_90 )
V_37 = V_90 ;
if ( V_91 < V_92 )
V_91 = V_92 ;
else if ( V_91 > V_93 )
V_91 = V_93 ;
for ( V_81 = 0 ; V_81 < V_94 ; V_81 ++ )
V_95 [ V_81 ] = NULL ;
V_47 . V_96 = V_97 ;
if ( F_46 ( & V_98 ) != 0 )
F_29 ( V_45 , L_42 ) ;
else
F_29 ( V_42 , L_43 ) ;
if ( ! V_57 ) {
F_47 ( & V_98 ) ;
F_44 ( NULL ) ;
F_29 ( V_45 ,
L_44
L_45 ,
V_99 ) ;
return - 1 ;
} else {
F_29 ( V_42 , L_46 ,
V_57 ) ;
}
return 0 ;
}
long F_48 ( struct V_9 * V_100 , unsigned int V_101 , unsigned long V_102 )
{
return F_49 ( V_103 -> V_8 ,
( int ) V_101 , ( void V_104 * ) V_102 ) ;
}
static void T_5 F_50 ( void )
{
F_29 ( V_42 , L_29 , V_80 ) ;
if ( V_105 > 0 ) {
F_29 ( V_42 , L_47 ) ;
F_51 ( V_106 ,
V_103 -> V_107 -> V_108 ) ;
F_52 ( V_105 , V_99 ) ;
V_105 = 0 ;
}
F_29 ( V_42 , L_48 ) ;
F_47 ( & V_98 ) ;
}
int F_53 ( struct V_109 * V_110 , struct V_6 * V_111 )
{
struct V_1 * V_15 = (struct V_1 * ) V_111 -> V_8 ;
struct V_112 * V_113 ;
int V_114 = 0 ;
F_29 ( V_38 , L_49 , V_110 , V_111 -> V_115 ) ;
F_54 ( V_110 , V_116 L_50
L_51 V_117 L_50
L_52
L_53
L_54 V_118 L_50
L_55
L_50 ,
V_15 -> V_119 ,
V_15 -> V_120 [ 0 ] ? V_15 -> V_120 : L_56 ) ;
F_54 ( V_110 , L_57
L_58
L_59
L_60 ,
F_55 ( V_15 ) ,
V_15 -> V_21 -> V_121 [ 0 ] ,
V_15 -> V_21 -> V_121 [ 1 ] ,
V_15 -> V_21 -> V_121 [ 2 ] ,
V_15 -> V_21 -> V_121 [ 3 ] ,
V_15 -> V_21 -> V_121 [ 4 ] ,
V_15 -> V_21 -> V_121 [ 5 ] ,
V_15 -> V_21 -> V_121 [ 6 ] ,
V_15 -> V_21 -> V_121 [ 7 ] ) ;
F_56 ( V_110 , L_50
L_61
L_50
L_62
L_63 ) ;
for ( V_113 = V_15 -> V_122 ; V_113 < V_15 -> V_123 ; V_113 ++ )
if ( V_113 -> V_124 == V_125 ) {
F_54 ( V_110 , L_64 ,
++ V_114 ,
( V_126 ) ( V_127 ) ( V_113 - V_15 -> V_122 ) ) ;
}
if ( V_114 == 0 )
F_56 ( V_110 , L_65 ) ;
F_57 ( V_110 , '\n' ) ;
return 0 ;
}
int F_58 ( struct V_6 * V_111 )
{
F_31 ( V_42 , & ( V_111 -> V_64 ) ,
L_66 ) ;
F_44 ( V_111 ) ;
if ( V_111 -> V_128 )
F_59 ( V_111 -> V_128 , NULL ) ;
F_60 ( V_111 ) ;
return 0 ;
}
const char * F_61 ( struct V_6 * V_111 )
{
struct V_1 * V_15 = (struct V_1 * ) V_111 -> V_8 ;
static char V_129 [ 512 ] ;
F_31 ( V_42 , & ( V_111 -> V_64 ) ,
L_67 ) ;
if ( V_105 <= 0 ) {
V_103 = V_111 ;
V_105 = F_62 ( 0 , V_99 ,
& V_130 ) ;
F_31 ( V_38 , & ( V_111 -> V_64 ) ,
L_68 ,
V_105 ) ;
if ( V_105 > 0 ) {
struct V_131 * V_132 ;
V_132 = F_63 ( V_106 , 0 ,
V_111 -> V_107 -> V_108 ,
& V_130 ) ;
if ( ! V_132 ) {
F_31 ( V_30 ,
& ( V_111 -> V_64 ) ,
L_69 ) ;
V_105 = - 1 ;
}
}
}
sprintf ( V_129 ,
V_116 L_70
L_71 V_117 L_72
L_73 ,
V_15 -> V_32 -> V_61 -> V_62 , V_15 -> V_32 -> V_63 , V_15 -> V_32 -> V_128 ,
V_15 -> V_120 [ 0 ] ? V_15 -> V_120 : L_56 ) ;
return V_129 ;
}
static T_6 F_64 ( struct V_133 * V_134 , T_7 * V_135 )
{
T_6 V_136 ;
if ( F_65 ( V_134 -> V_137 == V_134 -> V_138 ) ) {
if ( V_134 -> V_139 < V_134 -> V_140 ) {
if ( V_134 -> V_138 > ( V_141 * ) 0 ) {
V_134 -> V_142 = F_66 ( V_134 -> V_142 ) ;
++ ( V_134 -> V_139 ) ;
}
V_136 = F_67 ( V_134 -> V_142 ) ;
( * V_135 ) = F_68 ( V_134 -> V_142 ) ;
V_134 -> V_138 += V_136 ;
} else {
V_136 = 0 ;
}
} else if ( V_134 -> V_137 < V_134 -> V_138 ) {
V_136 = F_67 ( V_134 -> V_142 ) ;
( * V_135 ) = F_68 ( V_134 -> V_142 ) ;
V_134 -> V_138 -= V_136 ;
* V_135 = * V_135 +
( V_134 -> V_137 - V_134 -> V_138 ) ;
V_134 -> V_138 += V_136 ;
V_136 = F_69 (
V_134 -> V_138 - V_134 -> V_137 ) ;
} else {
V_136 = 0 ;
}
return V_136 ;
}
int F_70 ( struct V_6 * V_7 , struct V_143 * V_101 )
{
struct V_1 * V_15 =
(struct V_1 * ) V_101 -> V_4 -> V_7 -> V_8 ;
struct V_22 * V_23 ;
struct V_133 V_134 ;
unsigned V_144 ;
V_101 -> V_18 = V_145 << 16 ;
if ( F_71 ( F_72 ( V_146 , & V_15 -> V_147 ) ) ) {
V_101 -> V_18 = V_148 << 16 ;
V_101 -> V_149 ( V_101 ) ;
return 0 ;
}
V_23 = F_20 ( V_15 ) ;
if ( F_71 ( V_23 == NULL ) ) {
F_73 ( L_74 ) ;
return V_150 ;
}
V_23 -> V_101 = V_101 ;
V_144 = F_74 ( V_101 ) ;
if ( F_65 ( V_144 != 0 ) ) {
if ( V_101 -> V_151 == V_152 )
V_23 -> V_153 -> V_154 . V_147 |= F_75 ( V_155 ) ;
else if ( V_101 -> V_151 == V_156 )
V_23 -> V_153 -> V_154 . V_147 |= F_75 ( V_157 ) ;
}
memcpy ( V_23 -> V_153 -> V_154 . V_158 , V_101 -> V_159 , V_101 -> V_160 ) ;
V_23 -> V_153 -> V_154 . V_16 = F_75 ( V_144 ) ;
V_23 -> V_161 = V_101 -> V_4 -> V_34 ;
V_23 -> V_153 -> V_154 . V_147 |= F_75 ( V_101 -> V_4 -> V_162 ) ;
V_23 -> V_163 = V_101 -> V_164 ;
V_23 -> V_165 = V_166 ;
F_76 ( & V_134 , V_15 , V_23 , NULL ) ;
V_134 . V_16 = V_144 ;
V_134 . V_137 = NULL ;
V_134 . V_142 = F_77 ( V_101 ) ;
V_134 . V_138 = NULL ;
V_134 . V_140 = F_78 ( V_101 ) ;
V_134 . V_139 = 0 ;
if ( F_71 ( V_134 . V_140 < 0 ) ) {
F_22 ( V_15 , V_23 ) ;
return V_150 ;
}
V_134 . V_167 = ( V_168 ) F_64 ;
if ( F_71 ( ! F_79 ( V_15 , V_23 , & V_134 ) ) ) {
F_80 ( V_101 ) ;
F_22 ( V_15 , V_23 ) ;
return V_150 ;
}
F_73 ( L_75 , V_23 , ( int ) V_101 -> V_4 -> V_34 ,
( int ) V_101 -> V_4 -> V_162 ) ;
F_81 ( V_15 , V_23 ) ;
return 0 ;
}
static void F_82 ( struct V_1 * V_15 ,
struct V_22 * V_23 )
{
( * V_23 -> V_169 ) = V_23 -> V_170 ;
F_22 ( V_15 , V_23 ) ;
}
static int F_83 ( struct V_1 * V_15 ,
struct V_22 * * V_171 ,
struct V_143 * V_101 ,
struct V_172 * V_173 )
{
bool V_174 = false ;
struct V_22 * V_175 = * V_171 ;
struct V_22 * V_23 ;
struct V_172 * V_176 , * V_177 ;
F_84 (element, next, queue) {
V_23 = F_85 ( V_176 , struct V_22 , V_178 ) ;
if ( V_23 -> V_101 == V_101 ) {
if ( V_173 == & V_15 -> V_179 ) {
V_175 = F_20 ( V_15 ) ;
if ( V_175 == NULL ) {
F_31 ( V_30 ,
& ( V_15 -> V_7 -> V_64 ) ,
L_76 ,
V_101 ) ;
return 0 ;
}
V_175 -> V_165 = 0 ;
V_175 -> V_153 -> V_154 . V_16 = 0 ;
V_175 -> V_161 = V_23 -> V_161 ;
V_175 -> V_153 -> V_154 . V_147 |= F_75 (
( V_141 ) F_86 ( V_23 -> V_153 -> V_154 . V_147 ) ) ;
memset ( V_175 -> V_153 -> V_154 . V_158 , 0 ,
sizeof( V_175 -> V_153 -> V_154 . V_158 ) ) ;
V_175 -> V_153 -> V_154 . V_147 |= F_75 (
V_180 ) ;
V_175 -> V_153 -> V_154 . V_181 . V_182 =
V_23 -> V_153 -> V_154 . V_183 ;
} else {
F_87 ( & V_23 -> V_178 ) ;
F_22 ( V_15 , V_23 ) ;
}
V_174 = true ;
break;
}
}
if ( ! V_174 )
return 1 ;
return 2 ;
}
int F_88 ( struct V_143 * V_101 )
{
struct V_1 * V_15 =
(struct V_1 * ) V_101 -> V_4 -> V_7 -> V_8 ;
struct V_22 * V_171 = NULL ;
unsigned long V_147 ;
struct V_172 * V_173 ;
int V_18 ;
F_29 ( V_42 , L_77 , V_101 ) ;
if ( F_72 ( V_146 , & V_15 -> V_147 ) ) {
V_101 -> V_18 = V_184 << 16 ;
F_89 ( V_101 , 0 ) ;
V_101 -> V_149 ( V_101 ) ;
return V_185 ;
}
F_90 ( & V_15 -> V_186 , V_147 ) ;
V_173 = & V_15 -> V_187 ;
V_188:
V_18 = F_83 ( V_15 , & V_171 , V_101 , V_173 ) ;
if ( ! V_18 ) {
F_91 ( & V_15 -> V_186 , V_147 ) ;
return V_189 ;
} else if ( V_18 == 2 && ( V_173 == & V_15 -> V_187 ) ) {
V_173 = & V_15 -> V_179 ;
goto V_188;
}
F_91 ( & V_15 -> V_186 , V_147 ) ;
if ( V_171 ) {
V_141 V_190 = V_191 ;
V_171 -> V_192 = F_82 ;
V_171 -> V_169 =
& V_190 ;
F_81 ( V_15 , V_171 ) ;
if ( F_92 ( & V_15 -> V_193 ) == 0 )
F_93 ( V_15 ) ;
while ( V_190 == V_191 )
F_94 ( 10 ) ;
return V_185 ;
}
V_101 -> V_18 = V_184 << 16 ;
F_89 ( V_101 , 0 ) ;
V_101 -> V_149 ( V_101 ) ;
return V_185 ;
}
static int F_95 ( struct V_143 * V_101 , bool V_194 )
{
struct V_1 * V_15 =
(struct V_1 * ) V_101 -> V_4 -> V_7 -> V_8 ;
if ( F_72 ( V_146 , & V_15 -> V_147 ) )
return V_189 ;
if ( V_194 )
F_96 ( V_15 ) ;
else
F_97 ( V_15 ) ;
while ( F_72 ( V_195 , & V_15 -> V_147 ) ) {
F_94 ( 10 ) ;
if ( F_72 ( V_146 , & V_15 -> V_147 ) )
return V_189 ;
}
if ( F_72 ( V_146 , & V_15 -> V_147 ) )
return V_189 ;
return V_185 ;
}
int F_98 ( struct V_143 * V_101 )
{
F_29 ( V_42 , L_78 , V_101 ) ;
return F_95 ( V_101 , true ) ;
}
int F_99 ( struct V_143 * V_101 )
{
F_29 ( V_42 , L_79 , V_101 ) ;
return F_95 ( V_101 , false ) ;
}
static int F_100 ( struct V_143 * V_101 , bool V_196 )
{
struct V_1 * V_15 =
(struct V_1 * ) V_101 -> V_4 -> V_7 -> V_8 ;
struct V_22 * V_23 ;
V_141 V_190 = V_191 ;
bool V_197 ;
if ( F_72 ( V_146 , & V_15 -> V_147 ) )
return V_189 ;
V_198:
V_23 = F_20 ( V_15 ) ;
if ( V_23 == NULL ) {
if ( V_196 ) {
F_29 ( V_45 ,
L_80
L_81 ,
V_101 -> V_4 -> V_34 ) ;
} else {
F_29 ( V_45 ,
L_80
L_82 ,
V_101 -> V_4 -> V_34 ,
V_101 -> V_4 -> V_162 ) ;
}
return V_189 ;
}
V_23 -> V_161 = V_101 -> V_4 -> V_34 ;
V_23 -> V_153 -> V_154 . V_147 |= F_75 ( V_101 -> V_4 -> V_162 ) ;
V_23 -> V_170 = V_191 ;
V_23 -> V_192 = F_82 ;
V_23 -> V_169 = & V_190 ;
if ( V_196 ) {
F_73 ( L_83 , V_23 ,
V_101 -> V_4 -> V_34 ) ;
V_197 = F_101 ( V_15 , V_23 , 0x20 ) ;
} else {
F_73 ( L_84 , V_23 ,
V_101 -> V_4 -> V_34 , V_101 -> V_4 -> V_162 ) ;
V_197 = F_101 ( V_15 , V_23 , 0x10 ) ;
}
if ( V_197 ) {
F_22 ( V_15 , V_23 ) ;
} else {
while ( V_190 == V_191 )
F_94 ( 10 ) ;
}
if ( F_72 ( V_146 , & V_15 -> V_147 ) )
return V_189 ;
if ( V_190 == V_199 ) {
F_94 ( 100 ) ;
goto V_198;
}
return V_185 ;
}
int F_102 ( struct V_143 * V_101 )
{
F_29 ( V_42 , L_85 , V_101 ) ;
return F_100 ( V_101 , false ) ;
}
int F_103 ( struct V_143 * V_101 )
{
F_29 ( V_42 , L_86 , V_101 ) ;
return F_100 ( V_101 , true ) ;
}
void F_104 ( struct V_1 * V_15 ,
struct V_22 * V_23 )
{
V_141 V_200 = V_23 -> V_170 ;
if ( V_200 == V_201 )
return;
if ( V_23 -> V_153 -> V_154 . V_202 == V_203 ) {
if ( V_200 == V_204 ) {
if ( V_23 -> V_205 . V_206 . V_165 >= 13 ) {
F_29 ( V_30 ,
L_87 ,
V_23 -> V_163 [ 2 ] , V_23 -> V_163 [ 12 ] ,
V_23 -> V_163 [ 13 ] ,
V_23 -> V_153 -> V_154 . V_158 [ 0 ] ) ;
} else {
F_29 ( V_30 ,
L_88 ,
V_23 -> V_153 -> V_154 . V_158 [ 0 ] ) ;
}
} else if ( ( V_23 -> V_153 -> V_154 . V_158 [ 0 ] != V_207
&& V_23 -> V_153 -> V_154 . V_158 [ 0 ] != V_208 )
|| ( V_200 != V_209
&& V_200 != V_210 ) ) {
if ( ( V_200 == V_211 ) &&
( V_23 -> V_153 -> V_154 . V_158 [ 0 ] == V_207 ) ) {
} else {
F_29 ( V_30 ,
L_89 ,
V_23 -> V_153 -> V_154 . V_158 [ 0 ] , V_200 ,
V_23 -> V_161 ) ;
}
}
}
}
void F_105 ( struct V_1 * V_15 , struct V_22 * V_23 )
{
T_6 V_212 ;
T_6 V_213 ;
V_212 = F_106 ( V_214 ) ;
V_213 = V_23 -> V_213 ? V_23 -> V_213 : 5000 ;
while ( true ) {
F_107 ( V_15 ) ;
if ( V_23 -> V_170 != V_215 )
break;
F_108 ( F_109 ( 100 ) ) ;
if ( ( F_106 ( V_214 ) - V_212 ) > V_213 ) {
F_110 ( L_90 ) ;
F_111 () ;
V_23 -> V_170 = V_216 ;
F_112 ( V_15 ) ;
return;
}
}
}
T_6 F_113 ( struct V_1 * V_15 , T_6 V_217 )
{
T_6 V_218 = V_217 & ( V_219 - 1 ) ;
T_6 V_220 = V_217 & - ( signed int ) V_219 ;
if ( V_15 -> V_221 != V_220 ) {
F_114 ( V_15 , V_222 ,
V_220 | V_223 ) ;
F_115 ( V_15 , V_222 ) ;
V_15 -> V_221 = V_220 ;
}
return V_218 ;
}
bool F_116 ( struct V_1 * V_15 ,
void * V_224 ,
T_6 V_225 ,
T_6 V_226 )
{
V_141 * V_227 = ( V_141 * ) V_224 ;
while ( V_226 ) {
T_6 V_136 ;
T_6 V_218 ;
T_6 V_228 ;
V_228 = ( V_225 & - ( signed int ) V_219 ) ;
F_113 ( V_15 , V_228 ) ;
V_218 = V_225 & ( V_219 - 1 ) ;
V_136 = V_226 ;
if ( V_136 > V_219 - V_218 )
V_136 = V_219 - V_218 ;
V_225 += V_136 ;
V_226 -= V_136 ;
while ( V_136 -- ) {
* V_227 ++ = F_117 ( V_15 , V_218 ) ;
V_218 ++ ;
}
}
return true ;
}
void F_118 ( V_141 V_202 , void * V_229 )
{
struct V_230 * V_231 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
struct V_236 * V_237 ;
struct V_238 * V_110 ;
struct V_239 * V_240 ;
struct V_241 * V_242 ;
V_141 V_81 ;
switch ( V_202 ) {
case V_243 :
case V_244 :
V_242 = (struct V_241 * ) V_229 ;
V_242 -> V_245 = F_86 ( V_242 -> V_245 ) ;
break;
case V_246 :
case V_247 :
V_240 = (struct V_239 * ) V_229 ;
V_240 -> V_34 = F_86 ( V_240 -> V_34 ) ;
break;
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
V_233 = (struct V_232 * ) V_229 ;
V_233 -> V_254 = F_119 ( V_233 -> V_254 ) ;
V_233 -> V_255 = F_86 ( V_233 -> V_255 ) ;
V_233 -> V_256 = F_120 ( V_233 -> V_256 ) ;
V_233 -> V_161 = F_120 ( V_233 -> V_161 ) ;
V_233 -> V_162 = F_120 ( V_233 -> V_162 ) ;
V_233 -> V_257 = F_120 ( V_233 -> V_257 ) ;
break;
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
V_231 = (struct V_230 * ) V_229 ;
V_231 -> V_254 = F_119 ( V_231 -> V_254 ) ;
V_231 -> V_255 = F_86 ( V_231 -> V_255 ) ;
V_231 -> V_275 = F_86 ( V_231 -> V_275 ) ;
V_231 -> V_257 = F_120 ( V_231 -> V_257 ) ;
for ( V_81 = 0 ; V_81 < 32 ; V_81 ++ )
V_231 -> V_276 [ V_81 ] = F_120 ( V_231 -> V_276 [ V_81 ] ) ;
break;
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
V_235 = (struct V_234 * ) V_229 ;
V_235 -> V_283 = F_119 ( V_235 -> V_283 ) ;
V_235 -> V_284 = F_86 ( V_235 -> V_284 ) ;
V_235 -> V_255 = F_86 ( V_235 -> V_255 ) ;
V_235 -> V_161 = F_120 ( V_235 -> V_161 ) ;
break;
case V_285 :
V_237 = (struct V_236 * ) V_229 ;
V_237 -> V_286 = F_86 ( V_237 -> V_286 ) ;
V_237 -> V_287 = F_86 ( V_237 -> V_287 ) ;
break;
case V_288 :
V_110 = (struct V_238 * ) V_229 ;
for ( V_81 = 0 ; V_81 < 32 ; V_81 ++ )
V_110 -> V_289 [ V_81 ] = F_120 ( V_110 -> V_289 [ V_81 ] ) ;
break;
default:
break;
}
}
void F_121 ( V_141 V_202 , void * V_229 )
{
struct V_290 * V_291 ;
switch ( V_202 ) {
case V_292 :
case V_293 :
case V_294 :
V_291 = (struct V_290 * ) V_229 ;
V_291 -> V_295 . V_296 = F_120 ( V_291 -> V_295 . V_296 ) ;
V_291 -> V_82 = F_86 ( V_291 -> V_82 ) ;
V_291 -> V_297 = F_86 ( V_291 -> V_297 ) ;
V_291 -> V_298 = F_86 ( V_291 -> V_298 ) ;
V_291 -> V_299 = F_86 ( V_291 -> V_299 ) ;
V_291 -> V_300 = F_86 ( V_291 -> V_300 ) ;
break;
default:
break;
}
}
void F_122 ( union V_301 * V_302 )
{
struct V_303 * V_304 = & V_302 -> V_305 ;
struct V_306 * V_307 = & V_302 -> V_308 ;
switch ( V_302 -> V_309 . V_310 ) {
case V_311 :
V_304 -> V_312 = F_86 ( V_304 -> V_312 ) ;
break;
case V_313 :
V_307 -> V_314 = F_86 ( V_307 -> V_314 ) ;
V_307 -> V_315 = F_120 ( V_307 -> V_315 ) ;
V_307 -> V_34 . V_316 . V_317 = F_120 ( V_307 -> V_34 . V_316 . V_317 ) ;
if ( V_307 -> V_309 . V_318 >= F_123 ( struct V_306 , V_34 )
+ sizeof( struct V_319 ) ) {
V_307 -> V_34 . V_320 . V_321
= F_86 ( V_307 -> V_34 . V_320 . V_321 ) ;
V_307 -> V_34 . V_320 . V_322
= F_86 ( V_307 -> V_34 . V_320 . V_322 ) ;
}
break;
case V_323 :
default:
break;
}
}
void F_22 ( struct V_1 * V_15 , struct V_22 * V_23 )
{
unsigned long V_147 ;
F_124 ( V_23 , V_15 ) ;
F_90 ( & V_15 -> V_324 , V_147 ) ;
F_125 ( & V_23 -> V_325 , & V_15 -> V_326 ) ;
F_91 ( & V_15 -> V_324 , V_147 ) ;
}
struct V_22 * F_20 ( struct V_1 * V_15 )
{
struct V_22 * V_23 ;
unsigned long V_147 ;
F_90 ( & V_15 -> V_324 , V_147 ) ;
if ( F_71 ( F_126 ( & V_15 -> V_326 ) ) ) {
F_91 ( & V_15 -> V_324 , V_147 ) ;
return NULL ;
}
V_23 = F_127 ( & V_15 -> V_326 , struct V_22 ,
V_325 ) ;
F_128 ( & V_23 -> V_325 ) ;
F_91 ( & V_15 -> V_324 , V_147 ) ;
F_129 ( V_23 , V_15 ) ;
return V_23 ;
}
void F_130 ( struct V_1 * V_15 ,
struct V_22 * V_23 )
{
F_73 ( L_91 , V_23 ) ;
F_80 ( V_23 -> V_101 ) ;
if ( F_71 ( V_23 -> V_170 != V_201 ) ) {
F_73 ( L_92 , V_23 -> V_161 ,
V_23 -> V_170 ,
V_23 -> V_205 . V_206 . V_327 ,
V_23 -> V_101 ) ;
V_23 -> V_101 -> V_18 =
( ( F_131 ( V_23 -> V_170 ) << 16 )
| ( V_23 -> V_205 . V_206 . V_327 & V_328 ) ) ;
if ( V_23 -> V_170 == V_211 )
F_89 ( V_23 -> V_101 ,
F_86 ( V_23 -> V_205 . V_206 .
V_329 ) ) ;
else
F_89 ( V_23 -> V_101 , 0 ) ;
}
V_23 -> V_101 -> V_149 ( V_23 -> V_101 ) ;
F_22 ( V_15 , V_23 ) ;
}
void F_132 ( unsigned long V_330 )
{
struct V_1 * V_15 = (struct V_1 * ) V_330 ;
if ( F_71 ( F_72 ( V_331 , & V_15 -> V_332 ) ) ) {
F_133 ( V_331 , & V_15 -> V_332 ) ;
F_134 ( V_15 ) ;
}
if ( F_65 ( F_72 ( V_333 , & V_15 -> V_332 ) ) ) {
F_133 ( V_333 , & V_15 -> V_332 ) ;
F_135 ( V_15 ) ;
}
if ( F_136 ( V_15 ) )
F_137 ( V_15 ) ;
if ( F_136 ( V_15 )
|| ( F_72 ( V_333 , & V_15 -> V_332 ) )
|| ( F_72 ( V_331 , & V_15 -> V_332 ) ) ) {
F_133 ( V_334 , & V_15 -> V_147 ) ;
F_138 ( V_15 ) ;
} else {
F_133 ( V_334 , & V_15 -> V_147 ) ;
}
}
void F_139 ( struct V_1 * V_15 )
{
F_140 ( & V_15 -> V_335 ) ;
V_15 -> V_335 . V_202 = V_336 ;
V_15 -> V_335 . V_229 = ( unsigned long ) V_15 ;
V_15 -> V_335 . V_337 = V_214 +
F_109 ( 100 ) ;
F_141 ( & V_15 -> V_335 ) ;
}
static void V_336 ( unsigned long V_330 )
{
struct V_1 * V_15 = (struct V_1 * ) V_330 ;
F_142 ( V_331 , & V_15 -> V_332 ) ;
F_138 ( V_15 ) ;
F_139 ( V_15 ) ;
}
static void
F_143 ( struct V_338 * V_339 )
{
unsigned long V_147 ;
struct V_1 * V_15 = V_339 -> V_15 ;
F_90 ( & V_15 -> V_340 , V_147 ) ;
F_128 ( & V_339 -> V_341 ) ;
F_144 ( V_339 ) ;
F_91 ( & V_15 -> V_340 , V_147 ) ;
}
void
F_145 ( struct V_1 * V_15 )
{
unsigned long V_147 ;
F_90 ( & V_15 -> V_340 , V_147 ) ;
V_15 -> V_342 = 1 ;
F_91 ( & V_15 -> V_340 , V_147 ) ;
}
void
F_39 ( struct V_1 * V_15 )
{
unsigned long V_147 ;
F_90 ( & V_15 -> V_340 , V_147 ) ;
V_15 -> V_342 = 0 ;
F_91 ( & V_15 -> V_340 , V_147 ) ;
}
static void F_146 ( struct V_1 * V_15 , V_126 V_161 )
{
int V_343 ;
struct V_344 * V_345 ;
V_345 = F_147 ( V_15 -> V_7 , 0 , V_161 , 0 ) ;
if ( V_345 ) {
F_31 (
V_30 ,
& ( V_345 ->
V_346 ) ,
L_93 , V_161 ) ;
F_148 ( V_345 ) ;
} else {
F_31 (
V_42 ,
& ( V_15 -> V_7 ->
V_64 ) ,
L_94 ,
V_161 ) ;
V_343 = F_149 ( V_15 -> V_7 , 0 , V_161 , 0 ) ;
if ( V_343 ) {
F_31 (
V_45 ,
& ( V_15 -> V_7 ->
V_64 ) ,
L_95 ,
V_343 , V_161 ) ;
}
}
}
static void F_150 ( struct V_1 * V_15 , V_126 V_161 )
{
struct V_344 * V_345 ;
V_345 = F_147 ( V_15 -> V_7 , 0 , V_161 , 0 ) ;
if ( V_345 ) {
F_151 ( V_345 , V_347 ) ;
F_31 (
V_42 ,
& ( V_345 ->
V_346 ) ,
L_96 ,
V_161 ) ;
F_152 ( V_345 ) ;
F_31 (
V_42 ,
& ( V_345 ->
V_346 ) ,
L_97 ) ;
F_148 ( V_345 ) ;
} else {
F_31 (
V_30 ,
& ( V_15 -> V_7 -> V_64 ) ,
L_98 ,
V_161 ) ;
}
}
static void F_153 ( struct V_338 * V_339 )
{
struct V_348 * V_302 = (struct V_348 * ) V_339 -> V_229 ;
char * type ;
switch ( V_302 -> V_349 . V_309 . V_310 ) {
case V_311 :
type = L_99 ;
break;
case V_313 :
type = L_100 ;
break;
case V_323 :
type = L_101 ;
break;
case V_350 :
type = L_102 ;
break;
case V_351 :
type = L_103 ;
break;
case V_352 :
type = L_104 ;
break;
case V_353 :
type = L_105 ;
break;
case V_354 :
type = L_106 ;
break;
case V_355 :
type = L_107 ;
break;
case V_356 :
type = L_108 ;
break;
case V_357 :
type = L_109 ;
break;
case V_358 :
type = L_110 ;
break;
case V_359 :
type = L_111 ;
break;
case V_360 :
type = L_112 ;
break;
case V_361 :
type = L_113 ;
break;
default:
type = L_114 ;
break;
}
F_29 ( V_30 ,
L_115 ,
type ) ;
F_154 ( V_30 , & V_302 -> V_349 ,
V_302 -> V_349 . V_309 . V_318 ) ;
}
static void
F_155 ( struct V_362 * V_363 )
{
struct V_338 * V_339 =
F_2 ( V_363 , struct V_338 , V_363 . V_363 ) ;
struct V_1 * V_15 = V_339 -> V_15 ;
V_126 V_161 = * ( V_126 * ) & V_339 -> V_229 [ 0 ] ;
if ( V_15 -> V_342 )
goto V_364;
switch ( V_339 -> type ) {
case V_365 :
break;
case V_366 :
F_150 ( V_15 , V_161 ) ;
F_146 ( V_15 , V_161 ) ;
break;
case V_367 :
F_146 ( V_15 , V_161 ) ;
break;
case V_368 :
F_150 ( V_15 , V_161 ) ;
break;
case V_369 :
F_153 ( V_339 ) ;
break;
}
V_364:
F_143 ( V_339 ) ;
}
void F_156 ( struct V_1 * V_15 ,
enum V_370 type ,
void * V_229 ,
int V_371 )
{
struct V_338 * V_339 ;
unsigned long V_147 ;
V_339 = F_157 ( sizeof( struct V_338 ) , V_372 ) ;
if ( ! V_339 ) {
F_29 ( V_30 ,
L_116 ) ;
return;
}
if ( type == V_369 ) {
struct V_348 * V_302 =
(struct V_348 * ) V_339 -> V_229 ;
V_302 -> V_373 = V_374 ;
V_302 -> V_375 = V_15 -> V_32 -> V_61 -> V_62 ;
V_302 -> V_63 = V_15 -> V_32 -> V_63 ;
memcpy ( & V_302 -> V_349 , V_229 , sizeof( V_302 -> V_349 ) ) ;
} else {
memcpy ( V_339 -> V_229 , V_229 , V_371 ) ;
}
V_339 -> type = type ;
V_339 -> V_15 = V_15 ;
F_90 ( & V_15 -> V_340 , V_147 ) ;
F_158 ( & V_339 -> V_341 , & V_15 -> V_376 ) ;
F_159 ( & V_339 -> V_363 , F_155 ) ;
F_160 (
F_161 () , V_15 -> V_377 , & V_339 -> V_363 ,
F_109 ( 1 ) ) ;
F_91 ( & V_15 -> V_340 , V_147 ) ;
}
void F_162 ( struct V_1 * V_15 , V_126 V_378 ,
V_141 V_379 )
{
if ( V_379 == V_380 )
F_156 ( V_15 , V_366 , & V_378 ,
sizeof( V_378 ) ) ;
else if ( V_379 == V_125 )
F_156 ( V_15 , V_367 , & V_378 ,
sizeof( V_378 ) ) ;
else if ( V_379 == V_381 )
F_156 ( V_15 , V_368 , & V_378 ,
sizeof( V_378 ) ) ;
}
int F_131 ( V_141 V_170 )
{
switch ( V_170 ) {
case V_382 :
case V_211 :
case V_201 :
case V_204 :
return V_145 ;
case V_209 :
case V_210 :
return V_148 ;
case V_383 :
return V_384 ;
case V_385 :
return V_184 ;
case V_199 :
return V_386 ;
}
return V_387 ;
}
