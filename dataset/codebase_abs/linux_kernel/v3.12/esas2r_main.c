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
F_56 ( V_110 , L_50 ) ;
return 0 ;
}
int F_57 ( struct V_6 * V_111 )
{
F_31 ( V_42 , & ( V_111 -> V_64 ) ,
L_66 ) ;
F_44 ( V_111 ) ;
if ( V_111 -> V_128 )
F_58 ( V_111 -> V_128 , NULL ) ;
F_59 ( V_111 ) ;
return 0 ;
}
const char * F_60 ( struct V_6 * V_111 )
{
struct V_1 * V_15 = (struct V_1 * ) V_111 -> V_8 ;
static char V_129 [ 512 ] ;
F_31 ( V_42 , & ( V_111 -> V_64 ) ,
L_67 ) ;
if ( V_105 <= 0 ) {
V_103 = V_111 ;
V_105 = F_61 ( 0 , V_99 ,
& V_130 ) ;
F_31 ( V_38 , & ( V_111 -> V_64 ) ,
L_68 ,
V_105 ) ;
if ( V_105 > 0 ) {
struct V_131 * V_132 ;
V_132 = F_62 ( V_106 , 0 ,
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
static T_6 F_63 ( struct V_133 * V_134 , T_7 * V_135 )
{
T_6 V_136 ;
if ( F_64 ( V_134 -> V_137 == V_134 -> V_138 ) ) {
if ( V_134 -> V_139 < V_134 -> V_140 ) {
if ( V_134 -> V_138 > ( V_141 * ) 0 ) {
V_134 -> V_142 = F_65 ( V_134 -> V_142 ) ;
++ ( V_134 -> V_139 ) ;
}
V_136 = F_66 ( V_134 -> V_142 ) ;
( * V_135 ) = F_67 ( V_134 -> V_142 ) ;
V_134 -> V_138 += V_136 ;
} else {
V_136 = 0 ;
}
} else if ( V_134 -> V_137 < V_134 -> V_138 ) {
V_136 = F_66 ( V_134 -> V_142 ) ;
( * V_135 ) = F_67 ( V_134 -> V_142 ) ;
V_134 -> V_138 -= V_136 ;
* V_135 = * V_135 +
( V_134 -> V_137 - V_134 -> V_138 ) ;
V_134 -> V_138 += V_136 ;
V_136 = F_68 (
V_134 -> V_138 - V_134 -> V_137 ) ;
} else {
V_136 = 0 ;
}
return V_136 ;
}
int F_69 ( struct V_6 * V_7 , struct V_143 * V_101 )
{
struct V_1 * V_15 =
(struct V_1 * ) V_101 -> V_4 -> V_7 -> V_8 ;
struct V_22 * V_23 ;
struct V_133 V_134 ;
unsigned V_144 ;
V_101 -> V_18 = V_145 << 16 ;
if ( F_70 ( V_15 -> V_146 & V_147 ) ) {
V_101 -> V_18 = V_148 << 16 ;
V_101 -> V_149 ( V_101 ) ;
return 0 ;
}
V_23 = F_20 ( V_15 ) ;
if ( F_70 ( V_23 == NULL ) ) {
F_71 ( L_74 ) ;
return V_150 ;
}
V_23 -> V_101 = V_101 ;
V_144 = F_72 ( V_101 ) ;
if ( F_64 ( V_144 != 0 ) ) {
if ( V_101 -> V_151 == V_152 )
V_23 -> V_153 -> V_154 . V_146 |= F_73 ( V_155 ) ;
else if ( V_101 -> V_151 == V_156 )
V_23 -> V_153 -> V_154 . V_146 |= F_73 ( V_157 ) ;
}
memcpy ( V_23 -> V_153 -> V_154 . V_158 , V_101 -> V_159 , V_101 -> V_160 ) ;
V_23 -> V_153 -> V_154 . V_16 = F_73 ( V_144 ) ;
V_23 -> V_161 = V_101 -> V_4 -> V_34 ;
V_23 -> V_153 -> V_154 . V_146 |= F_73 ( V_101 -> V_4 -> V_162 ) ;
V_23 -> V_163 = V_101 -> V_164 ;
V_23 -> V_165 = V_166 ;
F_74 ( & V_134 , V_15 , V_23 , NULL ) ;
V_134 . V_16 = V_144 ;
V_134 . V_137 = NULL ;
V_134 . V_142 = F_75 ( V_101 ) ;
V_134 . V_138 = NULL ;
V_134 . V_140 = F_76 ( V_101 ) ;
V_134 . V_139 = 0 ;
if ( F_70 ( V_134 . V_140 < 0 ) ) {
F_22 ( V_15 , V_23 ) ;
return V_150 ;
}
V_134 . V_167 = ( V_168 ) F_63 ;
if ( F_70 ( ! F_77 ( V_15 , V_23 , & V_134 ) ) ) {
F_78 ( V_101 ) ;
F_22 ( V_15 , V_23 ) ;
return V_150 ;
}
F_71 ( L_75 , V_23 , ( int ) V_101 -> V_4 -> V_34 ,
( int ) V_101 -> V_4 -> V_162 ) ;
F_79 ( V_15 , V_23 ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_15 ,
struct V_22 * V_23 )
{
( * V_23 -> V_169 ) = V_23 -> V_170 ;
F_22 ( V_15 , V_23 ) ;
}
static int F_81 ( struct V_1 * V_15 ,
struct V_22 * * V_171 ,
struct V_143 * V_101 ,
struct V_172 * V_173 )
{
bool V_174 = false ;
struct V_22 * V_175 = * V_171 ;
struct V_22 * V_23 ;
struct V_172 * V_176 , * V_177 ;
F_82 (element, next, queue) {
V_23 = F_83 ( V_176 , struct V_22 , V_178 ) ;
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
V_175 -> V_153 -> V_154 . V_146 |= F_73 (
( V_141 ) F_84 ( V_23 -> V_153 -> V_154 . V_146 ) ) ;
memset ( V_175 -> V_153 -> V_154 . V_158 , 0 ,
sizeof( V_175 -> V_153 -> V_154 . V_158 ) ) ;
V_175 -> V_153 -> V_154 . V_146 |= F_73 (
V_180 ) ;
V_175 -> V_153 -> V_154 . V_181 . V_182 =
V_23 -> V_153 -> V_154 . V_183 ;
} else {
F_85 ( & V_23 -> V_178 ) ;
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
int F_86 ( struct V_143 * V_101 )
{
struct V_1 * V_15 =
(struct V_1 * ) V_101 -> V_4 -> V_7 -> V_8 ;
struct V_22 * V_171 = NULL ;
unsigned long V_146 ;
struct V_172 * V_173 ;
int V_18 ;
F_29 ( V_42 , L_77 , V_101 ) ;
if ( V_15 -> V_146 & V_147 ) {
V_101 -> V_18 = V_184 << 16 ;
F_87 ( V_101 , 0 ) ;
V_101 -> V_149 ( V_101 ) ;
return 0 ;
}
F_88 ( & V_15 -> V_185 , V_146 ) ;
V_173 = & V_15 -> V_186 ;
V_187:
V_18 = F_81 ( V_15 , & V_171 , V_101 , V_173 ) ;
if ( ! V_18 ) {
F_89 ( & V_15 -> V_185 , V_146 ) ;
return V_188 ;
} else if ( V_18 == 2 && ( V_173 == & V_15 -> V_186 ) ) {
V_173 = & V_15 -> V_179 ;
goto V_187;
}
F_89 ( & V_15 -> V_185 , V_146 ) ;
if ( V_171 ) {
V_141 V_189 = V_190 ;
V_171 -> V_191 = F_80 ;
V_171 -> V_169 =
& V_189 ;
F_79 ( V_15 , V_171 ) ;
if ( F_90 ( & V_15 -> V_192 ) == 0 )
F_91 ( V_15 ) ;
while ( V_189 == V_190 )
F_92 ( 10 ) ;
return V_193 ;
}
V_101 -> V_18 = V_184 << 16 ;
F_87 ( V_101 , 0 ) ;
V_101 -> V_149 ( V_101 ) ;
return V_193 ;
}
static int F_93 ( struct V_143 * V_101 , bool V_194 )
{
struct V_1 * V_15 =
(struct V_1 * ) V_101 -> V_4 -> V_7 -> V_8 ;
if ( V_15 -> V_146 & V_147 )
return V_188 ;
if ( V_194 )
F_94 ( V_15 ) ;
else
F_95 ( V_15 ) ;
while ( V_15 -> V_146 & V_195 ) {
F_92 ( 10 ) ;
if ( V_15 -> V_146 & V_147 )
return V_188 ;
}
if ( V_15 -> V_146 & V_147 )
return V_188 ;
return V_193 ;
}
int F_96 ( struct V_143 * V_101 )
{
F_29 ( V_42 , L_78 , V_101 ) ;
return F_93 ( V_101 , true ) ;
}
int F_97 ( struct V_143 * V_101 )
{
F_29 ( V_42 , L_79 , V_101 ) ;
return F_93 ( V_101 , false ) ;
}
static int F_98 ( struct V_143 * V_101 , bool V_196 )
{
struct V_1 * V_15 =
(struct V_1 * ) V_101 -> V_4 -> V_7 -> V_8 ;
struct V_22 * V_23 ;
V_141 V_189 = V_190 ;
bool V_197 ;
if ( V_15 -> V_146 & V_147 )
return V_188 ;
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
return V_188 ;
}
V_23 -> V_161 = V_101 -> V_4 -> V_34 ;
V_23 -> V_153 -> V_154 . V_146 |= F_73 ( V_101 -> V_4 -> V_162 ) ;
V_23 -> V_170 = V_190 ;
V_23 -> V_191 = F_80 ;
V_23 -> V_169 = & V_189 ;
if ( V_196 ) {
F_71 ( L_83 , V_23 ,
V_101 -> V_4 -> V_34 ) ;
V_197 = F_99 ( V_15 , V_23 , 0x20 ) ;
} else {
F_71 ( L_84 , V_23 ,
V_101 -> V_4 -> V_34 , V_101 -> V_4 -> V_162 ) ;
V_197 = F_99 ( V_15 , V_23 , 0x10 ) ;
}
if ( V_197 ) {
F_22 ( V_15 , V_23 ) ;
} else {
while ( V_189 == V_190 )
F_92 ( 10 ) ;
}
if ( V_15 -> V_146 & V_147 )
return V_188 ;
if ( V_189 == V_199 ) {
F_92 ( 100 ) ;
goto V_198;
}
return V_193 ;
}
int F_100 ( struct V_143 * V_101 )
{
F_29 ( V_42 , L_85 , V_101 ) ;
return F_98 ( V_101 , false ) ;
}
int F_101 ( struct V_143 * V_101 )
{
F_29 ( V_42 , L_86 , V_101 ) ;
return F_98 ( V_101 , true ) ;
}
int F_102 ( struct V_200 * V_5 , int V_201 , int V_202 )
{
F_29 ( V_42 , L_87 , V_5 , V_201 ) ;
F_103 ( V_5 , F_104 ( V_5 ) , V_201 ) ;
return V_5 -> V_203 ;
}
int F_105 ( struct V_200 * V_5 , int type )
{
F_29 ( V_42 , L_88 , V_5 , type ) ;
if ( V_5 -> V_204 ) {
F_106 ( V_5 , type ) ;
if ( type )
F_107 ( V_5 , V_5 -> V_203 ) ;
else
F_108 ( V_5 , V_5 -> V_203 ) ;
} else {
type = 0 ;
}
return type ;
}
int F_109 ( struct V_200 * V_5 )
{
return 0 ;
}
int F_110 ( struct V_200 * V_5 )
{
F_31 ( V_42 , & ( V_5 -> V_205 ) ,
L_89 ) ;
if ( V_5 -> V_204 ) {
F_106 ( V_5 , V_206 ) ;
F_107 ( V_5 , V_53 ) ;
} else {
F_106 ( V_5 , 0 ) ;
F_108 ( V_5 , V_53 ) ;
}
return 0 ;
}
void F_111 ( struct V_200 * V_5 )
{
F_31 ( V_42 , & ( V_5 -> V_205 ) ,
L_90 ) ;
}
void F_112 ( struct V_1 * V_15 ,
struct V_22 * V_23 )
{
V_141 V_207 = V_23 -> V_170 ;
if ( V_207 == V_208 )
return;
if ( V_23 -> V_153 -> V_154 . V_209 == V_210 ) {
if ( V_207 == V_211 ) {
if ( V_23 -> V_212 . V_213 . V_165 >= 13 ) {
F_29 ( V_30 ,
L_91 ,
V_23 -> V_163 [ 2 ] , V_23 -> V_163 [ 12 ] ,
V_23 -> V_163 [ 13 ] ,
V_23 -> V_153 -> V_154 . V_158 [ 0 ] ) ;
} else {
F_29 ( V_30 ,
L_92 ,
V_23 -> V_153 -> V_154 . V_158 [ 0 ] ) ;
}
} else if ( ( V_23 -> V_153 -> V_154 . V_158 [ 0 ] != V_214
&& V_23 -> V_153 -> V_154 . V_158 [ 0 ] != V_215 )
|| ( V_207 != V_216
&& V_207 != V_217 ) ) {
if ( ( V_207 == V_218 ) &&
( V_23 -> V_153 -> V_154 . V_158 [ 0 ] == V_214 ) ) {
} else {
F_29 ( V_30 ,
L_93 ,
V_23 -> V_153 -> V_154 . V_158 [ 0 ] , V_207 ,
V_23 -> V_161 ) ;
}
}
}
}
void F_113 ( struct V_1 * V_15 , struct V_22 * V_23 )
{
T_6 V_219 ;
T_6 V_220 ;
V_219 = F_114 ( V_221 ) ;
V_220 = V_23 -> V_220 ? V_23 -> V_220 : 5000 ;
while ( true ) {
F_115 ( V_15 ) ;
if ( V_23 -> V_170 != V_222 )
break;
F_116 ( F_117 ( 100 ) ) ;
if ( ( F_114 ( V_221 ) - V_219 ) > V_220 ) {
F_118 ( L_94 ) ;
F_119 () ;
V_23 -> V_170 = V_223 ;
F_120 ( V_15 ) ;
return;
}
}
}
T_6 F_121 ( struct V_1 * V_15 , T_6 V_224 )
{
T_6 V_225 = V_224 & ( V_226 - 1 ) ;
T_6 V_227 = V_224 & - ( signed int ) V_226 ;
if ( V_15 -> V_228 != V_227 ) {
F_122 ( V_15 , V_229 ,
V_227 | V_230 ) ;
F_123 ( V_15 , V_229 ) ;
V_15 -> V_228 = V_227 ;
}
return V_225 ;
}
bool F_124 ( struct V_1 * V_15 ,
void * V_231 ,
T_6 V_232 ,
T_6 V_233 )
{
V_141 * V_234 = ( V_141 * ) V_231 ;
while ( V_233 ) {
T_6 V_136 ;
T_6 V_225 ;
T_6 V_235 ;
V_235 = ( V_232 & - ( signed int ) V_226 ) ;
F_121 ( V_15 , V_235 ) ;
V_225 = V_232 & ( V_226 - 1 ) ;
V_136 = V_233 ;
if ( V_136 > V_226 - V_225 )
V_136 = V_226 - V_225 ;
V_232 += V_136 ;
V_233 -= V_136 ;
while ( V_136 -- ) {
* V_234 ++ = F_125 ( V_15 , V_225 ) ;
V_225 ++ ;
}
}
return true ;
}
void F_126 ( V_141 V_209 , void * V_236 )
{
struct V_237 * V_238 ;
struct V_239 * V_240 ;
struct V_241 * V_242 ;
struct V_243 * V_244 ;
struct V_245 * V_110 ;
struct V_246 * V_247 ;
struct V_248 * V_249 ;
V_141 V_81 ;
switch ( V_209 ) {
case V_250 :
case V_251 :
V_249 = (struct V_248 * ) V_236 ;
V_249 -> V_252 = F_84 ( V_249 -> V_252 ) ;
break;
case V_253 :
case V_254 :
V_247 = (struct V_246 * ) V_236 ;
V_247 -> V_34 = F_84 ( V_247 -> V_34 ) ;
break;
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
V_240 = (struct V_239 * ) V_236 ;
V_240 -> V_261 = F_127 ( V_240 -> V_261 ) ;
V_240 -> V_262 = F_84 ( V_240 -> V_262 ) ;
V_240 -> V_263 = F_128 ( V_240 -> V_263 ) ;
V_240 -> V_161 = F_128 ( V_240 -> V_161 ) ;
V_240 -> V_162 = F_128 ( V_240 -> V_162 ) ;
V_240 -> V_264 = F_128 ( V_240 -> V_264 ) ;
break;
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
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
V_238 = (struct V_237 * ) V_236 ;
V_238 -> V_261 = F_127 ( V_238 -> V_261 ) ;
V_238 -> V_262 = F_84 ( V_238 -> V_262 ) ;
V_238 -> V_282 = F_84 ( V_238 -> V_282 ) ;
V_238 -> V_264 = F_128 ( V_238 -> V_264 ) ;
for ( V_81 = 0 ; V_81 < 32 ; V_81 ++ )
V_238 -> V_283 [ V_81 ] = F_128 ( V_238 -> V_283 [ V_81 ] ) ;
break;
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
V_242 = (struct V_241 * ) V_236 ;
V_242 -> V_290 = F_127 ( V_242 -> V_290 ) ;
V_242 -> V_291 = F_84 ( V_242 -> V_291 ) ;
V_242 -> V_262 = F_84 ( V_242 -> V_262 ) ;
V_242 -> V_161 = F_128 ( V_242 -> V_161 ) ;
break;
case V_292 :
V_244 = (struct V_243 * ) V_236 ;
V_244 -> V_293 = F_84 ( V_244 -> V_293 ) ;
V_244 -> V_294 = F_84 ( V_244 -> V_294 ) ;
break;
case V_295 :
V_110 = (struct V_245 * ) V_236 ;
for ( V_81 = 0 ; V_81 < 32 ; V_81 ++ )
V_110 -> V_296 [ V_81 ] = F_128 ( V_110 -> V_296 [ V_81 ] ) ;
break;
default:
break;
}
}
void F_129 ( V_141 V_209 , void * V_236 )
{
struct V_297 * V_298 ;
switch ( V_209 ) {
case V_299 :
case V_300 :
case V_301 :
V_298 = (struct V_297 * ) V_236 ;
V_298 -> V_302 . V_303 = F_128 ( V_298 -> V_302 . V_303 ) ;
V_298 -> V_82 = F_84 ( V_298 -> V_82 ) ;
V_298 -> V_304 = F_84 ( V_298 -> V_304 ) ;
V_298 -> V_305 = F_84 ( V_298 -> V_305 ) ;
V_298 -> V_306 = F_84 ( V_298 -> V_306 ) ;
V_298 -> V_307 = F_84 ( V_298 -> V_307 ) ;
break;
default:
break;
}
}
void F_130 ( union V_308 * V_309 )
{
struct V_310 * V_311 = & V_309 -> V_312 ;
struct V_313 * V_314 = & V_309 -> V_315 ;
switch ( V_309 -> V_316 . V_317 ) {
case V_318 :
V_311 -> V_319 = F_84 ( V_311 -> V_319 ) ;
break;
case V_320 :
V_314 -> V_321 = F_84 ( V_314 -> V_321 ) ;
V_314 -> V_322 = F_128 ( V_314 -> V_322 ) ;
V_314 -> V_34 . V_323 . V_324 = F_128 ( V_314 -> V_34 . V_323 . V_324 ) ;
if ( V_314 -> V_316 . V_325 >= F_131 ( struct V_313 , V_34 )
+ sizeof( struct V_326 ) ) {
V_314 -> V_34 . V_327 . V_328
= F_84 ( V_314 -> V_34 . V_327 . V_328 ) ;
V_314 -> V_34 . V_327 . V_329
= F_84 ( V_314 -> V_34 . V_327 . V_329 ) ;
}
break;
case V_330 :
default:
break;
}
}
void F_22 ( struct V_1 * V_15 , struct V_22 * V_23 )
{
unsigned long V_146 ;
F_132 ( V_23 , V_15 ) ;
F_88 ( & V_15 -> V_331 , V_146 ) ;
F_133 ( & V_23 -> V_332 , & V_15 -> V_333 ) ;
F_89 ( & V_15 -> V_331 , V_146 ) ;
}
struct V_22 * F_20 ( struct V_1 * V_15 )
{
struct V_22 * V_23 ;
unsigned long V_146 ;
F_88 ( & V_15 -> V_331 , V_146 ) ;
if ( F_70 ( F_134 ( & V_15 -> V_333 ) ) ) {
F_89 ( & V_15 -> V_331 , V_146 ) ;
return NULL ;
}
V_23 = F_135 ( & V_15 -> V_333 , struct V_22 ,
V_332 ) ;
F_136 ( & V_23 -> V_332 ) ;
F_89 ( & V_15 -> V_331 , V_146 ) ;
F_137 ( V_23 , V_15 ) ;
return V_23 ;
}
void F_138 ( struct V_1 * V_15 ,
struct V_22 * V_23 )
{
F_71 ( L_95 , V_23 ) ;
F_78 ( V_23 -> V_101 ) ;
if ( F_70 ( V_23 -> V_170 != V_208 ) ) {
F_71 ( L_96 , V_23 -> V_161 ,
V_23 -> V_170 ,
V_23 -> V_212 . V_213 . V_334 ,
V_23 -> V_101 ) ;
V_23 -> V_101 -> V_18 =
( ( F_139 ( V_23 -> V_170 ) << 16 )
| ( V_23 -> V_212 . V_213 . V_334 & V_335 ) ) ;
if ( V_23 -> V_170 == V_218 )
F_87 ( V_23 -> V_101 ,
F_84 ( V_23 -> V_212 . V_213 .
V_336 ) ) ;
else
F_87 ( V_23 -> V_101 , 0 ) ;
}
V_23 -> V_101 -> V_149 ( V_23 -> V_101 ) ;
F_22 ( V_15 , V_23 ) ;
}
void F_140 ( unsigned long V_337 )
{
struct V_1 * V_15 = (struct V_1 * ) V_337 ;
if ( F_70 ( V_15 -> V_338 & V_339 ) ) {
F_141 ( & V_15 -> V_338 , V_339 ) ;
F_142 ( V_15 ) ;
}
if ( F_64 ( V_15 -> V_338 & V_340 ) ) {
F_141 ( & V_15 -> V_338 , V_340 ) ;
F_143 ( V_15 ) ;
}
if ( F_144 ( V_15 ) )
F_145 ( V_15 ) ;
if ( F_144 ( V_15 )
|| ( V_15 -> V_338 & V_340 )
|| ( V_15 -> V_338 & V_339 ) ) {
F_141 ( & V_15 -> V_146 , V_341 ) ;
F_146 ( V_15 ) ;
} else {
F_141 ( & V_15 -> V_146 , V_341 ) ;
}
}
void F_147 ( struct V_1 * V_15 )
{
F_148 ( & V_15 -> V_342 ) ;
V_15 -> V_342 . V_209 = V_343 ;
V_15 -> V_342 . V_236 = ( unsigned long ) V_15 ;
V_15 -> V_342 . V_344 = V_221 +
F_117 ( 100 ) ;
F_149 ( & V_15 -> V_342 ) ;
}
static void V_343 ( unsigned long V_337 )
{
struct V_1 * V_15 = (struct V_1 * ) V_337 ;
F_150 ( & V_15 -> V_338 , V_339 ) ;
F_146 ( V_15 ) ;
F_147 ( V_15 ) ;
}
static void
F_151 ( struct V_345 * V_346 )
{
unsigned long V_146 ;
struct V_1 * V_15 = V_346 -> V_15 ;
F_88 ( & V_15 -> V_347 , V_146 ) ;
F_136 ( & V_346 -> V_348 ) ;
F_152 ( V_346 ) ;
F_89 ( & V_15 -> V_347 , V_146 ) ;
}
void
F_153 ( struct V_1 * V_15 )
{
unsigned long V_146 ;
F_88 ( & V_15 -> V_347 , V_146 ) ;
V_15 -> V_349 = 1 ;
F_89 ( & V_15 -> V_347 , V_146 ) ;
}
void
F_39 ( struct V_1 * V_15 )
{
unsigned long V_146 ;
F_88 ( & V_15 -> V_347 , V_146 ) ;
V_15 -> V_349 = 0 ;
F_89 ( & V_15 -> V_347 , V_146 ) ;
}
static void F_154 ( struct V_1 * V_15 , V_126 V_161 )
{
int V_350 ;
struct V_200 * V_351 ;
V_351 = F_155 ( V_15 -> V_7 , 0 , V_161 , 0 ) ;
if ( V_351 ) {
F_31 (
V_30 ,
& ( V_351 ->
V_205 ) ,
L_97 , V_161 ) ;
F_156 ( V_351 ) ;
} else {
F_31 (
V_42 ,
& ( V_15 -> V_7 ->
V_64 ) ,
L_98 ,
V_161 ) ;
V_350 = F_157 ( V_15 -> V_7 , 0 , V_161 , 0 ) ;
if ( V_350 ) {
F_31 (
V_45 ,
& ( V_15 -> V_7 ->
V_64 ) ,
L_99 ,
V_350 , V_161 ) ;
}
}
}
static void F_158 ( struct V_1 * V_15 , V_126 V_161 )
{
struct V_200 * V_351 ;
V_351 = F_155 ( V_15 -> V_7 , 0 , V_161 , 0 ) ;
if ( V_351 ) {
F_159 ( V_351 , V_352 ) ;
F_31 (
V_42 ,
& ( V_351 ->
V_205 ) ,
L_100 ,
V_161 ) ;
F_160 ( V_351 ) ;
F_31 (
V_42 ,
& ( V_351 ->
V_205 ) ,
L_101 ) ;
F_156 ( V_351 ) ;
} else {
F_31 (
V_30 ,
& ( V_15 -> V_7 -> V_64 ) ,
L_102 ,
V_161 ) ;
}
}
static void F_161 ( struct V_345 * V_346 )
{
struct V_353 * V_309 = (struct V_353 * ) V_346 -> V_236 ;
char * type ;
switch ( V_309 -> V_354 . V_316 . V_317 ) {
case V_318 :
type = L_103 ;
break;
case V_320 :
type = L_104 ;
break;
case V_330 :
type = L_105 ;
break;
case V_355 :
type = L_106 ;
break;
case V_356 :
type = L_107 ;
break;
case V_357 :
type = L_108 ;
break;
case V_358 :
type = L_109 ;
break;
case V_359 :
type = L_110 ;
break;
case V_360 :
type = L_111 ;
break;
case V_361 :
type = L_112 ;
break;
case V_362 :
type = L_113 ;
break;
case V_363 :
type = L_114 ;
break;
case V_364 :
type = L_115 ;
break;
case V_365 :
type = L_116 ;
break;
case V_366 :
type = L_117 ;
break;
default:
type = L_118 ;
break;
}
F_29 ( V_30 ,
L_119 ,
type ) ;
F_162 ( V_30 , & V_309 -> V_354 ,
V_309 -> V_354 . V_316 . V_325 ) ;
}
static void
F_163 ( struct V_367 * V_368 )
{
struct V_345 * V_346 =
F_2 ( V_368 , struct V_345 , V_368 . V_368 ) ;
struct V_1 * V_15 = V_346 -> V_15 ;
V_126 V_161 = * ( V_126 * ) & V_346 -> V_236 [ 0 ] ;
if ( V_15 -> V_349 )
goto V_369;
switch ( V_346 -> type ) {
case V_370 :
break;
case V_371 :
F_158 ( V_15 , V_161 ) ;
F_154 ( V_15 , V_161 ) ;
break;
case V_372 :
F_154 ( V_15 , V_161 ) ;
break;
case V_373 :
F_158 ( V_15 , V_161 ) ;
break;
case V_374 :
F_161 ( V_346 ) ;
break;
}
V_369:
F_151 ( V_346 ) ;
}
void F_164 ( struct V_1 * V_15 ,
enum V_375 type ,
void * V_236 ,
int V_376 )
{
struct V_345 * V_346 ;
unsigned long V_146 ;
V_346 = F_28 ( sizeof( struct V_345 ) , V_377 ) ;
if ( ! V_346 ) {
F_29 ( V_30 ,
L_120 ) ;
return;
}
if ( type == V_374 ) {
struct V_353 * V_309 =
(struct V_353 * ) V_346 -> V_236 ;
V_309 -> V_378 = V_379 ;
V_309 -> V_380 = V_15 -> V_32 -> V_61 -> V_62 ;
V_309 -> V_63 = V_15 -> V_32 -> V_63 ;
memcpy ( & V_309 -> V_354 , V_236 , sizeof( V_309 -> V_354 ) ) ;
} else {
memcpy ( V_346 -> V_236 , V_236 , V_376 ) ;
}
V_346 -> type = type ;
V_346 -> V_15 = V_15 ;
F_88 ( & V_15 -> V_347 , V_146 ) ;
F_165 ( & V_346 -> V_348 , & V_15 -> V_381 ) ;
F_166 ( & V_346 -> V_368 , F_163 ) ;
F_167 (
F_168 () , V_15 -> V_382 , & V_346 -> V_368 ,
F_117 ( 1 ) ) ;
F_89 ( & V_15 -> V_347 , V_146 ) ;
}
void F_169 ( struct V_1 * V_15 , V_126 V_383 ,
V_141 V_384 )
{
if ( V_384 == V_385 )
F_164 ( V_15 , V_371 , & V_383 ,
sizeof( V_383 ) ) ;
else if ( V_384 == V_125 )
F_164 ( V_15 , V_372 , & V_383 ,
sizeof( V_383 ) ) ;
else if ( V_384 == V_386 )
F_164 ( V_15 , V_373 , & V_383 ,
sizeof( V_383 ) ) ;
}
int F_139 ( V_141 V_170 )
{
switch ( V_170 ) {
case V_387 :
case V_218 :
case V_208 :
case V_211 :
return V_145 ;
case V_216 :
case V_217 :
return V_148 ;
case V_388 :
return V_389 ;
case V_390 :
return V_184 ;
case V_199 :
return V_391 ;
}
return V_392 ;
}
