static inline void F_1 ( void )
{
F_2 ( sizeof( struct V_1 ) != 64 ) ;
F_2 ( sizeof( struct V_2 ) != 64 ) ;
F_2 ( sizeof( struct V_3 ) != 64 ) ;
F_2 ( sizeof( struct V_4 ) != 64 ) ;
F_2 ( sizeof( struct V_5 ) != 64 ) ;
F_2 ( sizeof( struct V_6 ) != 64 ) ;
F_2 ( sizeof( struct V_7 ) != 64 ) ;
F_2 ( sizeof( struct V_8 ) != 64 ) ;
F_2 ( sizeof( struct V_9 ) != 4096 ) ;
F_2 ( sizeof( struct V_10 ) != 4096 ) ;
F_2 ( sizeof( struct V_11 ) != 64 ) ;
F_2 ( sizeof( struct V_12 ) != 512 ) ;
}
static int F_3 ( unsigned V_13 , struct V_14 * V_15 )
{
unsigned V_16 = F_4 ( V_13 + V_15 -> V_17 , V_15 -> V_17 ) ;
return F_4 ( 8 * V_16 , V_18 - 8 ) ;
}
static unsigned int F_5 ( struct V_14 * V_15 )
{
unsigned int V_19 = sizeof( struct V_20 ) ;
V_19 += sizeof( struct V_21 ) ;
V_19 += sizeof( V_22 * ) * F_3 ( F_6 ( V_15 ) , V_15 ) ;
V_19 += sizeof( struct V_23 ) * V_24 ;
return V_19 ;
}
static int F_7 ( struct V_25 * V_26 , void * V_27 ,
unsigned int V_28 )
{
struct V_14 * V_15 = V_27 ;
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
F_8 ( V_30 -> V_26 ) ;
V_30 -> V_26 = V_26 ;
V_26 -> V_32 = V_30 ;
return 0 ;
}
static int F_9 ( void * V_27 , struct V_33 * V_34 ,
unsigned int V_28 , unsigned int V_35 ,
unsigned int V_36 )
{
struct V_14 * V_15 = V_27 ;
struct V_20 * V_37 = F_10 ( V_34 ) ;
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
F_11 ( ! V_30 ) ;
V_37 -> V_30 = V_30 ;
return 0 ;
}
static void F_12 ( struct V_25 * V_26 , unsigned int V_28 )
{
struct V_29 * V_30 = V_26 -> V_32 ;
V_30 -> V_26 = NULL ;
}
static int F_13 ( struct V_25 * V_26 , void * V_27 ,
unsigned int V_28 )
{
struct V_14 * V_15 = V_27 ;
struct V_29 * V_30 = V_15 -> V_31 [
( V_28 % V_15 -> V_38 ) + 1 ] ;
if ( ! V_30 -> V_26 )
V_30 -> V_26 = V_26 ;
F_8 ( V_30 -> V_26 -> V_39 != V_26 -> V_39 ) ;
V_26 -> V_32 = V_30 ;
return 0 ;
}
static int F_14 ( void * V_27 , struct V_33 * V_34 ,
unsigned int V_28 , unsigned int V_35 ,
unsigned int V_36 )
{
struct V_14 * V_15 = V_27 ;
struct V_20 * V_37 = F_10 ( V_34 ) ;
struct V_29 * V_30 = V_15 -> V_31 [ V_28 + 1 ] ;
F_11 ( ! V_30 ) ;
V_37 -> V_30 = V_30 ;
return 0 ;
}
static void F_15 ( struct V_20 * V_37 , void * V_40 ,
T_1 V_41 )
{
V_37 -> V_42 = V_41 ;
V_37 -> V_40 = V_40 ;
V_37 -> V_43 = 0 ;
F_16 ( F_17 ( V_37 ) ) ;
}
static void * F_18 ( struct V_21 * V_44 )
{
return ( void * ) ( V_44 -> V_45 & ~ 0x1UL ) ;
}
static bool F_19 ( struct V_21 * V_44 )
{
return ( V_44 -> V_45 & V_46 ) == 0 ;
}
static void F_20 ( struct V_29 * V_30 , void * V_40 ,
struct V_47 * V_48 )
{
if ( V_40 == V_49 )
return;
if ( V_40 == V_50 ) {
F_21 ( V_30 -> V_51 ,
L_1 ,
V_48 -> V_52 , F_22 ( & V_48 -> V_53 ) ) ;
return;
}
if ( V_40 == V_54 ) {
F_21 ( V_30 -> V_51 ,
L_2 ,
V_48 -> V_52 , F_22 ( & V_48 -> V_53 ) ) ;
return;
}
F_21 ( V_30 -> V_51 , L_3 , V_40 ) ;
}
static void * F_23 ( struct V_20 * V_37 , T_1 * V_42 )
{
void * V_40 ;
if ( V_42 )
* V_42 = V_37 -> V_42 ;
V_40 = V_37 -> V_40 ;
V_37 -> V_42 = F_20 ;
V_37 -> V_40 = V_49 ;
return V_40 ;
}
static void F_24 ( struct V_29 * V_30 , void * V_40 ,
struct V_47 * V_48 )
{
T_2 V_55 = F_25 ( & V_48 -> V_55 ) ;
T_3 V_56 = F_22 ( & V_48 -> V_56 ) >> 1 ;
if ( V_56 == V_57 || V_56 == V_58 )
++ V_30 -> V_15 -> V_59 ;
if ( V_56 == V_57 )
F_21 ( V_30 -> V_51 ,
L_4 , V_55 ) ;
}
static void F_26 ( struct V_29 * V_30 , void * V_40 ,
struct V_47 * V_48 )
{
struct V_33 * V_34 = V_40 ;
T_3 V_56 = F_22 ( & V_48 -> V_56 ) >> 1 ;
T_2 V_55 = F_25 ( & V_48 -> V_55 ) ;
F_27 ( V_30 -> V_26 , V_34 ) ;
F_21 ( V_30 -> V_51 , L_5 , V_56 , V_55 ) ;
++ V_30 -> V_15 -> V_60 ;
}
static void F_28 ( struct V_29 * V_30 , void * V_40 ,
struct V_47 * V_48 )
{
struct V_61 * V_62 = V_40 ;
V_62 -> V_55 = F_25 ( & V_48 -> V_55 ) ;
V_62 -> V_56 = F_22 ( & V_48 -> V_56 ) >> 1 ;
F_29 ( V_62 -> V_63 , & V_62 -> V_64 ) ;
F_27 ( V_30 -> V_26 , V_62 -> V_34 ) ;
}
static inline struct V_20 * F_30 ( struct V_29 * V_30 ,
unsigned int V_65 )
{
struct V_25 * V_26 = V_30 -> V_26 ;
struct V_33 * V_34 = F_31 ( V_26 -> V_39 , V_65 ) ;
return F_10 ( V_34 ) ;
}
static void * F_32 ( struct V_29 * V_30 , int V_65 ,
T_1 * V_42 )
{
struct V_20 * V_37 = F_30 ( V_30 , V_65 ) ;
void * V_40 ;
if ( V_65 >= V_30 -> V_66 ) {
* V_42 = F_20 ;
return V_54 ;
}
if ( V_42 )
* V_42 = V_37 -> V_42 ;
V_40 = V_37 -> V_40 ;
V_37 -> V_42 = F_20 ;
V_37 -> V_40 = V_50 ;
return V_40 ;
}
static int F_33 ( struct V_29 * V_30 , struct V_8 * V_37 )
{
T_3 V_67 = V_30 -> V_68 ;
memcpy ( & V_30 -> V_69 [ V_67 ] , V_37 , sizeof( * V_37 ) ) ;
if ( ++ V_67 == V_30 -> V_66 )
V_67 = 0 ;
F_34 ( V_67 , V_30 -> V_70 ) ;
V_30 -> V_68 = V_67 ;
return 0 ;
}
static int F_35 ( struct V_29 * V_30 , struct V_8 * V_37 )
{
unsigned long V_71 ;
int V_19 ;
F_36 ( & V_30 -> V_72 , V_71 ) ;
V_19 = F_33 ( V_30 , V_37 ) ;
F_37 ( & V_30 -> V_72 , V_71 ) ;
return V_19 ;
}
static V_22 * * F_38 ( struct V_21 * V_44 )
{
return ( ( void * ) V_44 ) + V_44 -> V_73 ;
}
static inline void F_39 ( struct V_21 * V_44 , unsigned V_74 ,
unsigned V_75 , unsigned long V_45 )
{
V_44 -> V_45 = V_45 ;
V_44 -> V_73 = F_40 ( struct V_21 , V_76 [ V_75 ] ) ;
V_44 -> V_77 = - 1 ;
V_44 -> V_78 = V_74 ;
V_44 -> V_79 = 0 ;
}
static struct V_21 *
F_41 ( unsigned V_75 , unsigned V_80 , struct V_14 * V_15 ,
unsigned long V_81 , T_4 V_82 )
{
struct V_21 * V_44 = F_42 ( sizeof( struct V_21 ) +
sizeof( V_22 * ) * F_3 ( V_80 , V_15 ) +
sizeof( struct V_23 ) * V_75 , V_82 ) ;
if ( V_44 )
F_39 ( V_44 , V_80 , V_75 , V_81 ) ;
return V_44 ;
}
static struct V_21 * F_43 ( struct V_33 * V_83 , struct V_14 * V_15 ,
T_4 V_82 )
{
unsigned V_13 = ! ( V_83 -> V_84 & V_85 ) ? F_44 ( V_83 ) :
sizeof( struct V_86 ) ;
struct V_21 * V_44 ;
if ( V_83 -> V_87 <= V_24 &&
V_13 <= F_6 ( V_15 ) ) {
struct V_20 * V_37 = F_10 ( V_83 ) ;
V_44 = V_37 -> V_44 ;
F_39 ( V_44 , V_13 , V_83 -> V_87 ,
( unsigned long ) V_83 | V_46 ) ;
return V_44 ;
}
return F_41 ( V_83 -> V_87 , V_13 , V_15 ,
( unsigned long ) V_83 , V_82 ) ;
}
void F_45 ( struct V_14 * V_15 , struct V_21 * V_44 )
{
const int V_88 = V_15 -> V_17 / 8 - 1 ;
int V_89 ;
V_22 * * V_90 = F_38 ( V_44 ) ;
T_5 V_91 = V_44 -> V_92 ;
if ( V_44 -> V_77 == 0 )
F_46 ( V_15 -> V_93 , V_90 [ 0 ] , V_91 ) ;
for ( V_89 = 0 ; V_89 < V_44 -> V_77 ; V_89 ++ ) {
V_22 * V_94 = V_90 [ V_89 ] ;
T_5 V_95 = F_47 ( V_94 [ V_88 ] ) ;
F_46 ( V_15 -> V_96 , V_94 , V_91 ) ;
V_91 = V_95 ;
}
if ( F_19 ( V_44 ) )
F_48 ( V_44 ) ;
}
static int F_49 ( T_3 V_56 )
{
switch ( V_56 & 0x7ff ) {
case V_57 :
return 0 ;
case V_97 :
return - V_98 ;
default:
return - V_99 ;
}
}
static void F_50 ( T_2 V_100 , T_2 V_101 , struct V_102 * V_103 )
{
if ( F_51 ( V_103 -> V_104 ) == V_101 )
V_103 -> V_104 = F_52 ( V_100 ) ;
}
static void F_53 ( T_2 V_100 , T_2 V_101 , struct V_102 * V_103 )
{
if ( F_51 ( V_103 -> V_104 ) == V_100 )
V_103 -> V_104 = F_52 ( V_101 ) ;
}
static void F_54 ( struct V_33 * V_34 ,
void (* F_55)( T_2 V_100 , T_2 V_101 , struct V_102 * V_103 ) )
{
struct V_105 * V_106 = V_34 -> V_107 -> V_108 ;
struct V_109 * V_110 ;
struct V_102 * V_103 ;
void * V_100 , * V_111 ;
T_2 V_89 , V_112 , V_113 , V_114 , V_115 ;
if ( ! V_106 -> V_116 || V_106 -> V_116 == V_117 )
return;
V_110 = F_56 ( V_34 -> V_118 ) ;
if ( ! V_110 )
return;
V_111 = F_57 ( V_110 -> V_119 -> V_120 ) + V_110 -> V_119 -> V_121 ;
V_100 = V_111 ;
V_115 = F_58 ( V_110 ) ;
V_114 = F_59 ( V_106 , F_60 ( V_34 ) ) ;
V_112 = ( F_44 ( V_34 ) >> V_106 -> V_122 ) ;
V_113 = V_106 -> V_123 -> V_124 -> V_125 ;
for ( V_89 = 0 ; V_89 < V_112 ; V_89 ++ , V_115 ++ , V_114 ++ ) {
V_103 = (struct V_102 * ) V_100 ;
F_55 ( V_114 , V_115 , V_103 ) ;
V_100 += V_113 ;
}
F_61 ( V_111 ) ;
}
static int F_62 ( struct V_126 * V_127 )
{
return 0 ;
}
static int F_63 ( struct V_126 * V_127 )
{
return 0 ;
}
static void F_64 ( struct V_105 * V_106 )
{
struct V_128 V_124 ;
switch ( V_106 -> V_116 ) {
case V_117 :
V_124 = V_129 ;
break;
case V_130 :
case V_131 :
V_124 = V_132 ;
break;
default:
V_124 = V_133 ;
break;
}
V_124 . V_125 = V_106 -> V_134 ;
F_65 ( V_106 -> V_123 , & V_124 ) ;
F_66 ( V_106 -> V_135 , 1 ) ;
}
static void F_54 ( struct V_33 * V_34 ,
void (* F_55)( T_2 V_100 , T_2 V_101 , struct V_102 * V_103 ) )
{
}
static void F_50 ( T_2 V_100 , T_2 V_101 , struct V_102 * V_103 )
{
}
static void F_53 ( T_2 V_100 , T_2 V_101 , struct V_102 * V_103 )
{
}
static void F_64 ( struct V_105 * V_106 )
{
}
static void F_67 ( struct V_29 * V_30 , void * V_40 ,
struct V_47 * V_48 )
{
struct V_21 * V_44 = V_40 ;
struct V_33 * V_34 = F_18 ( V_44 ) ;
struct V_20 * V_136 = F_10 ( V_34 ) ;
T_3 V_56 = F_22 ( & V_48 -> V_56 ) >> 1 ;
if ( F_68 ( V_56 ) ) {
if ( ! ( V_56 & V_137 || F_69 ( V_34 ) )
&& ( V_138 - V_34 -> V_139 ) < V_34 -> V_140 ) {
unsigned long V_71 ;
F_70 ( V_34 ) ;
F_36 ( V_34 -> V_141 -> V_142 , V_71 ) ;
if ( ! F_71 ( V_34 -> V_141 ) )
F_72 ( V_34 -> V_141 ) ;
F_37 ( V_34 -> V_141 -> V_142 , V_71 ) ;
return;
}
V_34 -> V_143 = F_49 ( V_56 ) ;
} else
V_34 -> V_143 = 0 ;
if ( V_136 -> V_43 )
F_21 ( & V_30 -> V_15 -> V_144 -> V_15 ,
L_6 ,
V_56 ) ;
if ( V_44 -> V_79 ) {
F_73 ( & V_30 -> V_15 -> V_144 -> V_15 , V_44 -> V_76 , V_44 -> V_79 ,
F_74 ( V_34 ) ? V_145 : V_146 ) ;
if ( F_75 ( V_34 ) ) {
if ( ! F_74 ( V_34 ) )
F_54 ( V_34 , F_53 ) ;
F_73 ( & V_30 -> V_15 -> V_144 -> V_15 , V_44 -> V_147 , 1 ,
F_74 ( V_34 ) ? V_145 : V_146 ) ;
}
}
F_45 ( V_30 -> V_15 , V_44 ) ;
F_76 ( V_34 ) ;
}
int F_77 ( struct V_14 * V_15 , struct V_21 * V_44 , int V_148 ,
T_4 V_82 )
{
struct V_149 * V_150 ;
int V_78 = V_148 ;
struct V_23 * V_76 = V_44 -> V_76 ;
int V_151 = F_78 ( V_76 ) ;
T_6 V_152 = F_79 ( V_76 ) ;
T_2 V_17 = V_15 -> V_17 ;
int V_73 = V_152 & ( V_17 - 1 ) ;
V_22 * V_94 ;
V_22 * * V_90 = F_38 ( V_44 ) ;
T_5 V_91 ;
int V_16 , V_89 ;
V_78 -= ( V_17 - V_73 ) ;
if ( V_78 <= 0 )
return V_148 ;
V_151 -= ( V_17 - V_73 ) ;
if ( V_151 ) {
V_152 += ( V_17 - V_73 ) ;
} else {
V_76 = F_80 ( V_76 ) ;
V_152 = F_79 ( V_76 ) ;
V_151 = F_78 ( V_76 ) ;
}
if ( V_78 <= V_17 ) {
V_44 -> V_92 = V_152 ;
return V_148 ;
}
V_16 = F_4 ( V_78 , V_17 ) ;
if ( V_16 <= ( 256 / 8 ) ) {
V_150 = V_15 -> V_93 ;
V_44 -> V_77 = 0 ;
} else {
V_150 = V_15 -> V_96 ;
V_44 -> V_77 = 1 ;
}
V_94 = F_81 ( V_150 , V_82 , & V_91 ) ;
if ( ! V_94 ) {
V_44 -> V_92 = V_152 ;
V_44 -> V_77 = - 1 ;
return ( V_148 - V_78 ) + V_17 ;
}
V_90 [ 0 ] = V_94 ;
V_44 -> V_92 = V_91 ;
V_89 = 0 ;
for (; ; ) {
if ( V_89 == V_17 >> 3 ) {
V_22 * V_153 = V_94 ;
V_94 = F_81 ( V_150 , V_82 , & V_91 ) ;
if ( ! V_94 )
return V_148 - V_78 ;
V_90 [ V_44 -> V_77 ++ ] = V_94 ;
V_94 [ 0 ] = V_153 [ V_89 - 1 ] ;
V_153 [ V_89 - 1 ] = F_82 ( V_91 ) ;
V_89 = 1 ;
}
V_94 [ V_89 ++ ] = F_82 ( V_152 ) ;
V_151 -= V_17 ;
V_152 += V_17 ;
V_78 -= V_17 ;
if ( V_78 <= 0 )
break;
if ( V_151 > 0 )
continue;
F_11 ( V_151 < 0 ) ;
V_76 = F_80 ( V_76 ) ;
V_152 = F_79 ( V_76 ) ;
V_151 = F_78 ( V_76 ) ;
}
return V_148 ;
}
static void F_83 ( struct V_29 * V_30 , struct V_105 * V_106 ,
struct V_33 * V_34 , struct V_21 * V_44 )
{
struct V_86 * V_154 =
(struct V_86 * ) F_38 ( V_44 ) [ 0 ] ;
struct V_8 * V_155 = & V_30 -> V_69 [ V_30 -> V_68 ] ;
V_154 -> V_156 = F_84 ( 0 ) ;
V_154 -> V_112 = F_84 ( F_44 ( V_34 ) >> V_106 -> V_122 ) ;
V_154 -> V_157 = F_82 ( F_59 ( V_106 , F_60 ( V_34 ) ) ) ;
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_158 . V_159 = V_160 ;
V_155 -> V_158 . V_52 = V_34 -> V_65 ;
V_155 -> V_158 . V_161 = F_84 ( V_106 -> V_162 ) ;
V_155 -> V_158 . V_163 = F_82 ( V_44 -> V_92 ) ;
V_155 -> V_158 . V_164 = 0 ;
V_155 -> V_158 . V_165 = F_84 ( V_166 ) ;
if ( ++ V_30 -> V_68 == V_30 -> V_66 )
V_30 -> V_68 = 0 ;
F_34 ( V_30 -> V_68 , V_30 -> V_70 ) ;
}
static void F_85 ( struct V_29 * V_30 , struct V_105 * V_106 ,
int V_167 )
{
struct V_8 * V_155 = & V_30 -> V_69 [ V_30 -> V_68 ] ;
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_168 . V_159 = V_169 ;
V_155 -> V_168 . V_52 = V_167 ;
V_155 -> V_168 . V_161 = F_84 ( V_106 -> V_162 ) ;
if ( ++ V_30 -> V_68 == V_30 -> V_66 )
V_30 -> V_68 = 0 ;
F_34 ( V_30 -> V_68 , V_30 -> V_70 ) ;
}
static int F_86 ( struct V_29 * V_30 , struct V_21 * V_44 ,
struct V_105 * V_106 )
{
struct V_33 * V_34 = F_18 ( V_44 ) ;
struct V_8 * V_155 ;
T_3 V_170 = 0 ;
T_2 V_171 = 0 ;
if ( V_34 -> V_84 & V_172 )
V_170 |= V_173 ;
if ( V_34 -> V_84 & ( V_174 | V_175 ) )
V_170 |= V_176 ;
if ( V_34 -> V_84 & V_175 )
V_171 |= V_177 ;
V_155 = & V_30 -> V_69 [ V_30 -> V_68 ] ;
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_178 . V_159 = ( F_74 ( V_34 ) ? V_179 : V_180 ) ;
V_155 -> V_178 . V_52 = V_34 -> V_65 ;
V_155 -> V_178 . V_161 = F_84 ( V_106 -> V_162 ) ;
V_155 -> V_178 . V_163 = F_82 ( F_79 ( V_44 -> V_76 ) ) ;
V_155 -> V_178 . V_181 = F_82 ( V_44 -> V_92 ) ;
V_155 -> V_178 . V_157 = F_82 ( F_59 ( V_106 , F_60 ( V_34 ) ) ) ;
V_155 -> V_178 . V_78 = F_87 ( ( F_44 ( V_34 ) >> V_106 -> V_122 ) - 1 ) ;
if ( F_75 ( V_34 ) ) {
V_155 -> V_178 . V_182 = F_82 ( F_79 ( V_44 -> V_147 ) ) ;
switch ( V_106 -> V_116 ) {
case V_117 :
V_170 |= V_183 ;
break;
case V_130 :
case V_131 :
V_170 |= V_183 |
V_184 ;
V_155 -> V_178 . V_185 = F_84 (
F_59 ( V_106 , F_60 ( V_34 ) ) ) ;
break;
}
} else if ( V_106 -> V_134 )
V_170 |= V_186 ;
V_155 -> V_178 . V_170 = F_87 ( V_170 ) ;
V_155 -> V_178 . V_171 = F_84 ( V_171 ) ;
if ( ++ V_30 -> V_68 == V_30 -> V_66 )
V_30 -> V_68 = 0 ;
F_34 ( V_30 -> V_68 , V_30 -> V_70 ) ;
return 0 ;
}
static int F_88 ( struct V_25 * V_26 ,
const struct V_187 * V_188 )
{
struct V_105 * V_106 = V_26 -> V_135 -> V_189 ;
struct V_29 * V_30 = V_26 -> V_32 ;
struct V_33 * V_34 = V_188 -> V_83 ;
struct V_20 * V_37 = F_10 ( V_34 ) ;
struct V_21 * V_44 ;
enum V_190 V_191 ;
if ( V_106 -> V_134 && ! F_75 ( V_34 ) ) {
if ( ! ( V_106 -> V_116 && V_106 -> V_134 == 8 ) ) {
V_34 -> V_143 = - V_192 ;
F_76 ( V_34 ) ;
return V_193 ;
}
}
V_44 = F_43 ( V_34 , V_106 -> V_15 , V_194 ) ;
if ( ! V_44 )
return V_195 ;
if ( V_34 -> V_84 & V_85 ) {
void * V_154 ;
V_154 = F_81 ( V_30 -> V_15 -> V_93 ,
V_194 ,
& V_44 -> V_92 ) ;
if ( ! V_154 )
goto V_196;
F_38 ( V_44 ) [ 0 ] = ( V_22 * ) V_154 ;
V_44 -> V_77 = 0 ;
} else if ( V_34 -> V_87 ) {
V_191 = F_74 ( V_34 ) ? V_145 : V_146 ;
F_89 ( V_44 -> V_76 , V_34 -> V_87 ) ;
V_44 -> V_79 = F_90 ( V_34 -> V_141 , V_34 , V_44 -> V_76 ) ;
if ( ! V_44 -> V_79 )
goto V_197;
if ( ! F_91 ( V_30 -> V_51 , V_44 -> V_76 , V_44 -> V_79 , V_191 ) )
goto V_196;
if ( F_44 ( V_34 ) !=
F_77 ( V_30 -> V_15 , V_44 , F_44 ( V_34 ) , V_194 ) ) {
F_73 ( & V_30 -> V_15 -> V_144 -> V_15 , V_44 -> V_76 ,
V_44 -> V_79 , V_191 ) ;
goto V_196;
}
if ( F_75 ( V_34 ) ) {
if ( F_92 ( V_34 -> V_141 , V_34 -> V_118 ) != 1 )
goto V_197;
F_89 ( V_44 -> V_147 , 1 ) ;
if ( F_93 (
V_34 -> V_141 , V_34 -> V_118 , V_44 -> V_147 ) != 1 )
goto V_197;
if ( F_74 ( V_34 ) )
F_54 ( V_34 , F_50 ) ;
if ( ! F_91 ( V_30 -> V_51 , V_44 -> V_147 , 1 , V_191 ) )
goto V_197;
}
}
F_15 ( V_37 , V_44 , F_67 ) ;
F_94 ( & V_30 -> V_72 ) ;
if ( V_34 -> V_84 & V_85 )
F_83 ( V_30 , V_106 , V_34 , V_44 ) ;
else if ( V_34 -> V_84 & V_198 )
F_85 ( V_30 , V_106 , V_34 -> V_65 ) ;
else
F_86 ( V_30 , V_44 , V_106 ) ;
F_95 ( V_30 ) ;
F_96 ( & V_30 -> V_72 ) ;
return V_193 ;
V_197:
F_45 ( V_30 -> V_15 , V_44 ) ;
return V_199 ;
V_196:
F_45 ( V_30 -> V_15 , V_44 ) ;
return V_195 ;
}
static int F_95 ( struct V_29 * V_30 )
{
T_3 V_200 , V_201 ;
V_200 = V_30 -> V_202 ;
V_201 = V_30 -> V_203 ;
for (; ; ) {
void * V_40 ;
T_1 V_42 ;
struct V_47 V_48 = V_30 -> V_204 [ V_200 ] ;
if ( ( F_97 ( V_48 . V_56 ) & 1 ) != V_201 )
break;
V_30 -> V_205 = F_97 ( V_48 . V_205 ) ;
if ( ++ V_200 == V_30 -> V_66 ) {
V_200 = 0 ;
V_201 = ! V_201 ;
}
V_40 = F_32 ( V_30 , V_48 . V_52 , & V_42 ) ;
V_42 ( V_30 , V_40 , & V_48 ) ;
}
if ( V_200 == V_30 -> V_202 && V_201 == V_30 -> V_203 )
return 0 ;
F_34 ( V_200 , V_30 -> V_70 + V_30 -> V_15 -> V_206 ) ;
V_30 -> V_202 = V_200 ;
V_30 -> V_203 = V_201 ;
V_30 -> V_207 = 1 ;
return 1 ;
}
static int F_98 ( struct V_25 * V_26 ,
const struct V_187 * V_188 )
{
F_99 ( 1 ) ;
return V_199 ;
}
static T_7 F_100 ( int V_208 , void * V_27 )
{
T_7 V_55 ;
struct V_29 * V_30 = V_27 ;
F_101 ( & V_30 -> V_72 ) ;
F_95 ( V_30 ) ;
V_55 = V_30 -> V_207 ? V_209 : V_210 ;
V_30 -> V_207 = 0 ;
F_102 ( & V_30 -> V_72 ) ;
return V_55 ;
}
static T_7 F_103 ( int V_208 , void * V_27 )
{
struct V_29 * V_30 = V_27 ;
struct V_47 V_48 = V_30 -> V_204 [ V_30 -> V_202 ] ;
if ( ( F_97 ( V_48 . V_56 ) & 1 ) != V_30 -> V_203 )
return V_210 ;
return V_211 ;
}
static void F_104 ( struct V_29 * V_30 , void * V_40 ,
struct V_47 * V_48 )
{
struct V_212 * V_62 = V_40 ;
V_62 -> V_55 = F_25 ( & V_48 -> V_55 ) ;
V_62 -> V_56 = F_22 ( & V_48 -> V_56 ) >> 1 ;
F_105 ( V_62 -> V_213 ) ;
}
static int F_106 ( struct V_33 * V_34 , struct V_8 * V_37 ,
T_2 * V_55 , unsigned V_140 )
{
struct V_212 V_62 ;
struct V_20 * V_136 = F_10 ( V_34 ) ;
struct V_29 * V_30 = V_136 -> V_30 ;
V_62 . V_213 = V_214 ;
V_62 . V_56 = - V_215 ;
V_37 -> V_168 . V_52 = V_34 -> V_65 ;
F_15 ( V_136 , & V_62 , F_104 ) ;
F_107 ( V_216 ) ;
F_35 ( V_30 , V_37 ) ;
F_108 () ;
if ( V_55 )
* V_55 = V_62 . V_55 ;
return V_62 . V_56 ;
}
static int F_109 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
struct V_8 V_217 ;
struct V_20 * V_218 ;
struct V_33 * V_34 ;
V_34 = F_110 ( V_15 -> V_219 , V_220 , V_194 , true ) ;
if ( F_111 ( V_34 ) )
return F_112 ( V_34 ) ;
V_34 -> V_84 |= V_221 ;
V_218 = F_10 ( V_34 ) ;
F_15 ( V_218 , NULL , F_24 ) ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_168 . V_159 = V_222 ;
V_217 . V_168 . V_52 = V_34 -> V_65 ;
F_27 ( V_30 -> V_26 , V_34 ) ;
return F_33 ( V_30 , & V_217 ) ;
}
static int F_113 ( struct V_14 * V_15 ,
struct V_8 * V_37 ,
struct V_61 * V_62 , unsigned V_140 )
{
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
struct V_33 * V_34 ;
struct V_20 * V_136 ;
V_34 = F_110 ( V_15 -> V_219 , V_220 , V_223 , false ) ;
if ( F_111 ( V_34 ) )
return F_112 ( V_34 ) ;
V_34 -> V_140 = V_140 ;
V_136 = F_10 ( V_34 ) ;
V_62 -> V_34 = V_34 ;
F_15 ( V_136 , V_62 , F_28 ) ;
V_62 -> V_56 = - V_215 ;
V_37 -> V_168 . V_52 = V_34 -> V_65 ;
return F_35 ( V_30 , V_37 ) ;
}
static int F_114 ( struct V_14 * V_15 , struct V_8 * V_37 ,
T_2 * V_55 , unsigned V_140 )
{
int V_224 ;
struct V_33 * V_34 ;
V_34 = F_110 ( V_15 -> V_219 , V_220 , V_223 , false ) ;
if ( F_111 ( V_34 ) )
return F_112 ( V_34 ) ;
V_224 = F_106 ( V_34 , V_37 , V_55 , V_140 ) ;
F_115 ( V_34 ) ;
return V_224 ;
}
int F_116 ( struct V_14 * V_15 , struct V_8 * V_37 ,
T_2 * V_55 )
{
return F_114 ( V_15 , V_37 , V_55 , V_225 ) ;
}
int F_117 ( struct V_14 * V_15 , struct V_105 * V_106 ,
struct V_8 * V_37 , T_2 * V_55 )
{
int V_224 ;
struct V_33 * V_34 ;
V_34 = F_110 ( V_106 -> V_135 , V_220 , ( V_223 | V_226 ) ,
false ) ;
if ( F_111 ( V_34 ) )
return F_112 ( V_34 ) ;
V_224 = F_106 ( V_34 , V_37 , V_55 , V_227 ) ;
F_115 ( V_34 ) ;
return V_224 ;
}
static int F_118 ( struct V_14 * V_15 , T_8 V_159 , T_3 V_228 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_229 . V_159 = V_159 ;
V_217 . V_229 . V_230 = F_87 ( V_228 ) ;
return F_116 ( V_15 , & V_217 , NULL ) ;
}
static int F_119 ( struct V_14 * V_15 , T_3 V_230 ,
struct V_29 * V_30 )
{
struct V_8 V_217 ;
int V_71 = V_231 | V_232 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_233 . V_159 = V_234 ;
V_217 . V_233 . V_163 = F_82 ( V_30 -> V_235 ) ;
V_217 . V_233 . V_236 = F_87 ( V_230 ) ;
V_217 . V_233 . V_237 = F_87 ( V_30 -> V_66 - 1 ) ;
V_217 . V_233 . V_238 = F_87 ( V_71 ) ;
V_217 . V_233 . V_239 = F_87 ( V_30 -> V_240 ) ;
return F_116 ( V_15 , & V_217 , NULL ) ;
}
static int F_120 ( struct V_14 * V_15 , T_3 V_230 ,
struct V_29 * V_30 )
{
struct V_8 V_217 ;
int V_71 = V_231 | V_241 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_242 . V_159 = V_243 ;
V_217 . V_242 . V_163 = F_82 ( V_30 -> V_244 ) ;
V_217 . V_242 . V_245 = F_87 ( V_230 ) ;
V_217 . V_242 . V_237 = F_87 ( V_30 -> V_66 - 1 ) ;
V_217 . V_242 . V_246 = F_87 ( V_71 ) ;
V_217 . V_242 . V_236 = F_87 ( V_230 ) ;
return F_116 ( V_15 , & V_217 , NULL ) ;
}
static int F_121 ( struct V_14 * V_15 , T_3 V_236 )
{
return F_118 ( V_15 , V_247 , V_236 ) ;
}
static int F_122 ( struct V_14 * V_15 , T_3 V_245 )
{
return F_118 ( V_15 , V_248 , V_245 ) ;
}
int F_123 ( struct V_14 * V_15 , unsigned V_161 , unsigned V_249 ,
T_5 V_152 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_250 . V_159 = V_251 ;
V_217 . V_250 . V_161 = F_84 ( V_161 ) ;
V_217 . V_250 . V_163 = F_82 ( V_152 ) ;
V_217 . V_250 . V_249 = F_84 ( V_249 ) ;
return F_116 ( V_15 , & V_217 , NULL ) ;
}
int F_124 ( struct V_14 * V_15 , unsigned V_252 , unsigned V_161 ,
T_5 V_152 , T_2 * V_55 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_253 . V_159 = V_254 ;
V_217 . V_253 . V_161 = F_84 ( V_161 ) ;
V_217 . V_253 . V_163 = F_82 ( V_152 ) ;
V_217 . V_253 . V_252 = F_84 ( V_252 ) ;
return F_116 ( V_15 , & V_217 , V_55 ) ;
}
int F_125 ( struct V_14 * V_15 , unsigned V_252 , unsigned V_255 ,
T_5 V_152 , T_2 * V_55 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_253 . V_159 = V_256 ;
V_217 . V_253 . V_163 = F_82 ( V_152 ) ;
V_217 . V_253 . V_252 = F_84 ( V_252 ) ;
V_217 . V_253 . V_255 = F_84 ( V_255 ) ;
return F_116 ( V_15 , & V_217 , V_55 ) ;
}
static void F_126 ( struct V_33 * V_34 )
{
struct V_20 * V_136 = F_10 ( V_34 ) ;
struct V_29 * V_30 = V_136 -> V_30 ;
struct V_14 * V_15 = V_30 -> V_15 ;
struct V_33 * V_257 ;
struct V_20 * V_258 ;
struct V_8 V_37 ;
if ( ! V_30 -> V_230 || V_136 -> V_43 ) {
unsigned long V_71 ;
F_36 ( & V_259 , V_71 ) ;
if ( F_127 ( & V_15 -> V_260 ) )
goto V_261;
F_128 ( & V_15 -> V_262 ) ;
F_21 ( & V_15 -> V_144 -> V_15 ,
L_7 ,
V_34 -> V_65 , V_30 -> V_230 ) ;
V_15 -> V_263 = V_264 ;
F_129 ( V_265 , & V_15 -> V_260 ) ;
V_261:
F_37 ( & V_259 , V_71 ) ;
return;
}
if ( ! V_15 -> V_60 )
return;
V_257 = F_110 ( V_15 -> V_219 , V_220 , V_194 ,
false ) ;
if ( F_111 ( V_257 ) )
return;
V_258 = F_10 ( V_257 ) ;
F_15 ( V_258 , V_257 , F_26 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . abort . V_159 = V_266 ;
V_37 . abort . V_267 = V_34 -> V_65 ;
V_37 . abort . V_245 = F_87 ( V_30 -> V_230 ) ;
V_37 . abort . V_52 = V_257 -> V_65 ;
-- V_15 -> V_60 ;
V_136 -> V_43 = 1 ;
F_21 ( V_30 -> V_51 , L_8 , V_34 -> V_65 ,
V_30 -> V_230 ) ;
if ( F_35 ( V_15 -> V_31 [ 0 ] , & V_37 ) < 0 ) {
F_21 ( V_30 -> V_51 ,
L_9 ,
V_34 -> V_65 , V_30 -> V_230 ) ;
F_115 ( V_257 ) ;
}
}
static void F_130 ( struct V_25 * V_26 ,
struct V_33 * V_34 , void * V_27 , bool V_268 )
{
struct V_29 * V_30 = V_27 ;
void * V_40 ;
T_1 V_42 ;
struct V_20 * V_37 ;
struct V_47 V_48 ;
if ( ! F_131 ( V_34 ) )
return;
V_37 = F_10 ( V_34 ) ;
if ( V_37 -> V_40 == V_49 )
return;
if ( F_132 ( V_34 -> V_141 ) )
V_48 . V_56 = F_87 ( ( V_58 | V_137 ) << 1 ) ;
else
V_48 . V_56 = F_87 ( V_58 << 1 ) ;
F_21 ( V_30 -> V_51 , L_10 ,
V_34 -> V_65 , V_30 -> V_230 ) ;
V_40 = F_23 ( V_37 , & V_42 ) ;
V_42 ( V_30 , V_40 , & V_48 ) ;
}
static enum V_269 F_133 ( struct V_33 * V_34 , bool V_268 )
{
struct V_20 * V_37 = F_10 ( V_34 ) ;
struct V_29 * V_30 = V_37 -> V_30 ;
F_21 ( V_30 -> V_51 , L_11 , V_34 -> V_65 ,
V_30 -> V_230 ) ;
F_94 ( & V_30 -> V_72 ) ;
F_126 ( V_34 ) ;
F_96 ( & V_30 -> V_72 ) ;
return V_270 ;
}
static void F_134 ( struct V_29 * V_30 )
{
F_135 ( V_30 -> V_51 , F_136 ( V_30 -> V_66 ) ,
( void * ) V_30 -> V_204 , V_30 -> V_235 ) ;
F_135 ( V_30 -> V_51 , F_137 ( V_30 -> V_66 ) ,
V_30 -> V_69 , V_30 -> V_244 ) ;
F_48 ( V_30 ) ;
}
static void F_138 ( struct V_14 * V_15 , int V_271 )
{
int V_89 ;
for ( V_89 = V_15 -> V_38 - 1 ; V_89 >= V_271 ; V_89 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_89 ] ;
V_15 -> V_38 -- ;
V_15 -> V_31 [ V_89 ] = NULL ;
F_134 ( V_30 ) ;
}
}
static int F_139 ( struct V_29 * V_30 )
{
int V_272 ;
F_94 ( & V_30 -> V_72 ) ;
if ( V_30 -> V_240 == - 1 ) {
F_96 ( & V_30 -> V_72 ) ;
return 1 ;
}
V_272 = V_30 -> V_15 -> V_273 [ V_30 -> V_240 ] . V_272 ;
V_30 -> V_15 -> V_274 -- ;
V_30 -> V_240 = - 1 ;
F_96 ( & V_30 -> V_72 ) ;
if ( ! V_30 -> V_230 && V_30 -> V_15 -> V_219 )
F_140 ( V_30 -> V_15 -> V_219 ) ;
F_141 ( V_272 , NULL ) ;
F_142 ( V_272 , V_30 ) ;
return 0 ;
}
static void F_143 ( struct V_29 * V_30 )
{
struct V_25 * V_26 = V_30 -> V_26 ;
F_94 ( & V_30 -> V_72 ) ;
if ( V_26 && V_26 -> V_39 )
F_144 ( V_26 , F_130 , V_30 ) ;
F_96 ( & V_30 -> V_72 ) ;
}
static void F_145 ( struct V_14 * V_15 , int V_230 )
{
struct V_29 * V_30 = V_15 -> V_31 [ V_230 ] ;
if ( ! V_30 )
return;
if ( F_139 ( V_30 ) )
return;
if ( V_230 && F_146 ( & V_15 -> V_275 -> V_276 ) != - 1 ) {
F_122 ( V_15 , V_230 ) ;
F_121 ( V_15 , V_230 ) ;
}
F_94 ( & V_30 -> V_72 ) ;
F_95 ( V_30 ) ;
F_96 ( & V_30 -> V_72 ) ;
}
static struct V_29 * F_147 ( struct V_14 * V_15 , int V_230 ,
int V_277 )
{
struct V_278 * V_279 = & V_15 -> V_144 -> V_15 ;
struct V_29 * V_30 = F_148 ( sizeof( * V_30 ) , V_223 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_204 = F_149 ( V_279 , F_136 ( V_277 ) ,
& V_30 -> V_235 , V_223 ) ;
if ( ! V_30 -> V_204 )
goto V_280;
V_30 -> V_69 = F_150 ( V_279 , F_137 ( V_277 ) ,
& V_30 -> V_244 , V_223 ) ;
if ( ! V_30 -> V_69 )
goto V_281;
V_30 -> V_51 = V_279 ;
V_30 -> V_15 = V_15 ;
snprintf ( V_30 -> V_282 , sizeof( V_30 -> V_282 ) , L_12 ,
V_15 -> V_283 , V_230 ) ;
F_151 ( & V_30 -> V_72 ) ;
V_30 -> V_202 = 0 ;
V_30 -> V_203 = 1 ;
V_30 -> V_70 = & V_15 -> V_284 [ V_230 * 2 * V_15 -> V_206 ] ;
V_30 -> V_66 = V_277 ;
V_30 -> V_230 = V_230 ;
V_15 -> V_38 ++ ;
V_15 -> V_31 [ V_230 ] = V_30 ;
return V_30 ;
V_281:
F_135 ( V_279 , F_136 ( V_277 ) , ( void * ) V_30 -> V_204 ,
V_30 -> V_235 ) ;
V_280:
F_48 ( V_30 ) ;
return NULL ;
}
static int F_152 ( struct V_14 * V_15 , struct V_29 * V_30 ,
const char * V_285 )
{
if ( V_286 )
return F_153 ( V_15 -> V_273 [ V_30 -> V_240 ] . V_272 ,
F_103 , F_100 , V_287 ,
V_285 , V_30 ) ;
return F_154 ( V_15 -> V_273 [ V_30 -> V_240 ] . V_272 , F_100 ,
V_287 , V_285 , V_30 ) ;
}
static void F_155 ( struct V_29 * V_30 , T_3 V_230 )
{
struct V_14 * V_15 = V_30 -> V_15 ;
F_94 ( & V_30 -> V_72 ) ;
V_30 -> V_68 = 0 ;
V_30 -> V_202 = 0 ;
V_30 -> V_203 = 1 ;
V_30 -> V_70 = & V_15 -> V_284 [ V_230 * 2 * V_15 -> V_206 ] ;
memset ( ( void * ) V_30 -> V_204 , 0 , F_136 ( V_30 -> V_66 ) ) ;
V_15 -> V_274 ++ ;
F_96 ( & V_30 -> V_72 ) ;
}
static int F_156 ( struct V_29 * V_30 , int V_230 )
{
struct V_14 * V_15 = V_30 -> V_15 ;
int V_55 ;
V_30 -> V_240 = V_230 - 1 ;
V_55 = F_119 ( V_15 , V_230 , V_30 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_120 ( V_15 , V_230 , V_30 ) ;
if ( V_55 < 0 )
goto V_288;
V_55 = F_152 ( V_15 , V_30 , V_30 -> V_282 ) ;
if ( V_55 < 0 )
goto V_289;
F_155 ( V_30 , V_230 ) ;
return V_55 ;
V_289:
F_122 ( V_15 , V_230 ) ;
V_288:
F_121 ( V_15 , V_230 ) ;
return V_55 ;
}
static int F_157 ( struct V_14 * V_15 , T_6 V_290 , bool V_291 )
{
unsigned long V_140 ;
T_2 V_292 = V_291 ? V_293 : 0 ;
V_140 = ( ( F_158 ( V_290 ) + 1 ) * V_294 / 2 ) + V_138 ;
while ( ( F_146 ( & V_15 -> V_275 -> V_276 ) & V_293 ) != V_292 ) {
F_159 ( 100 ) ;
if ( F_160 ( V_214 ) )
return - V_215 ;
if ( F_161 ( V_138 , V_140 ) ) {
F_162 ( & V_15 -> V_144 -> V_15 ,
L_13 , V_291 ?
L_14 : L_15 ) ;
return - V_295 ;
}
}
return 0 ;
}
static int F_163 ( struct V_14 * V_15 , T_6 V_290 )
{
V_15 -> V_296 &= ~ V_297 ;
V_15 -> V_296 &= ~ V_298 ;
F_34 ( V_15 -> V_296 , & V_15 -> V_275 -> V_299 ) ;
return F_157 ( V_15 , V_290 , false ) ;
}
static int F_164 ( struct V_14 * V_15 , T_6 V_290 )
{
V_15 -> V_296 &= ~ V_297 ;
V_15 -> V_296 |= V_298 ;
F_34 ( V_15 -> V_296 , & V_15 -> V_275 -> V_299 ) ;
return F_157 ( V_15 , V_290 , true ) ;
}
static int F_165 ( struct V_14 * V_15 )
{
unsigned long V_140 ;
V_15 -> V_296 &= ~ V_297 ;
V_15 -> V_296 |= V_300 ;
F_34 ( V_15 -> V_296 , & V_15 -> V_275 -> V_299 ) ;
V_140 = V_301 + V_138 ;
while ( ( F_146 ( & V_15 -> V_275 -> V_276 ) & V_302 ) !=
V_303 ) {
F_159 ( 100 ) ;
if ( F_160 ( V_214 ) )
return - V_215 ;
if ( F_161 ( V_138 , V_140 ) ) {
F_162 ( & V_15 -> V_144 -> V_15 ,
L_16 ) ;
return - V_295 ;
}
}
return 0 ;
}
static void F_166 ( struct V_14 * V_15 )
{
if ( V_15 -> V_219 && ! F_132 ( V_15 -> V_219 ) ) {
F_167 ( V_15 -> V_219 ) ;
F_168 ( & V_15 -> V_304 ) ;
}
}
static int F_169 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_219 ) {
V_15 -> V_304 . V_305 = & V_306 ;
V_15 -> V_304 . V_307 = 1 ;
V_15 -> V_304 . V_308 = V_309 - 1 ;
V_15 -> V_304 . V_310 = 1 ;
V_15 -> V_304 . V_140 = V_225 ;
V_15 -> V_304 . V_36 = F_170 ( & V_15 -> V_144 -> V_15 ) ;
V_15 -> V_304 . V_311 = F_5 ( V_15 ) ;
V_15 -> V_304 . V_32 = V_15 ;
if ( F_171 ( & V_15 -> V_304 ) )
return - V_312 ;
V_15 -> V_219 = F_172 ( & V_15 -> V_304 ) ;
if ( F_111 ( V_15 -> V_219 ) ) {
F_168 ( & V_15 -> V_304 ) ;
return - V_312 ;
}
if ( ! F_173 ( V_15 -> V_219 ) ) {
F_166 ( V_15 ) ;
return - V_295 ;
}
} else
F_174 ( V_15 -> V_219 ) ;
return 0 ;
}
static int F_175 ( struct V_14 * V_15 )
{
int V_55 ;
T_2 V_313 ;
T_6 V_290 = F_176 ( & V_15 -> V_275 -> V_290 ) ;
struct V_29 * V_30 ;
unsigned V_314 = V_315 ;
unsigned V_316 = F_177 ( V_290 ) + 12 ;
unsigned V_317 = F_178 ( V_290 ) + 12 ;
if ( V_314 < V_316 ) {
F_162 ( & V_15 -> V_144 -> V_15 ,
L_17
L_18 , 1 << V_316 ,
1 << V_314 ) ;
return - V_295 ;
}
if ( V_314 > V_317 ) {
F_179 ( & V_15 -> V_144 -> V_15 ,
L_19
L_20 ,
1 << V_317 , 1 << V_314 ) ;
V_314 = V_317 ;
}
V_55 = F_163 ( V_15 , V_290 ) ;
if ( V_55 < 0 )
return V_55 ;
V_30 = V_15 -> V_31 [ 0 ] ;
if ( ! V_30 ) {
V_30 = F_147 ( V_15 , 0 , V_309 ) ;
if ( ! V_30 )
return - V_312 ;
}
V_313 = V_30 -> V_66 - 1 ;
V_313 |= V_313 << 16 ;
V_15 -> V_17 = 1 << V_314 ;
V_15 -> V_296 = V_318 ;
V_15 -> V_296 |= ( V_314 - 12 ) << V_319 ;
V_15 -> V_296 |= V_320 | V_321 ;
V_15 -> V_296 |= V_322 | V_323 ;
F_34 ( V_313 , & V_15 -> V_275 -> V_313 ) ;
F_180 ( V_30 -> V_244 , & V_15 -> V_275 -> V_324 ) ;
F_180 ( V_30 -> V_235 , & V_15 -> V_275 -> V_325 ) ;
V_55 = F_164 ( V_15 , V_290 ) ;
if ( V_55 )
goto V_280;
V_30 -> V_240 = 0 ;
V_55 = F_152 ( V_15 , V_30 , V_30 -> V_282 ) ;
if ( V_55 )
goto V_280;
return V_55 ;
V_280:
F_138 ( V_15 , 0 ) ;
return V_55 ;
}
struct V_21 * F_181 ( struct V_14 * V_15 , int V_326 ,
unsigned long V_327 , unsigned V_78 )
{
int V_89 , V_328 , V_329 , V_79 , V_73 ;
struct V_23 * V_76 ;
struct V_330 * * V_331 ;
struct V_21 * V_44 ;
if ( V_327 & 3 )
return F_182 ( - V_332 ) ;
if ( ! V_78 || V_78 > V_333 - V_18 )
return F_182 ( - V_332 ) ;
V_73 = F_183 ( V_327 ) ;
V_329 = F_4 ( V_73 + V_78 , V_18 ) ;
V_331 = F_184 ( V_329 , sizeof( * V_331 ) , V_223 ) ;
if ( ! V_331 )
return F_182 ( - V_312 ) ;
V_328 = F_185 ( V_327 , V_329 , 1 , V_331 ) ;
if ( V_328 < V_329 ) {
V_329 = V_328 ;
V_328 = - V_192 ;
goto V_334;
}
V_328 = - V_312 ;
V_44 = F_41 ( V_329 , V_78 , V_15 , 0 , V_223 ) ;
if ( ! V_44 )
goto V_334;
V_76 = V_44 -> V_76 ;
F_89 ( V_76 , V_329 ) ;
for ( V_89 = 0 ; V_89 < V_329 ; V_89 ++ ) {
F_186 ( & V_76 [ V_89 ] , V_331 [ V_89 ] ,
F_187 ( unsigned , V_78 , V_18 - V_73 ) ,
V_73 ) ;
V_78 -= ( V_18 - V_73 ) ;
V_73 = 0 ;
}
F_188 ( & V_76 [ V_89 - 1 ] ) ;
V_44 -> V_79 = V_329 ;
V_79 = F_91 ( & V_15 -> V_144 -> V_15 , V_76 , V_329 ,
V_326 ? V_145 : V_146 ) ;
if ( ! V_79 )
goto V_335;
F_48 ( V_331 ) ;
return V_44 ;
V_335:
F_48 ( V_44 ) ;
V_334:
for ( V_89 = 0 ; V_89 < V_329 ; V_89 ++ )
F_189 ( V_331 [ V_89 ] ) ;
F_48 ( V_331 ) ;
return F_182 ( V_328 ) ;
}
void F_190 ( struct V_14 * V_15 , int V_326 ,
struct V_21 * V_44 )
{
int V_89 ;
F_73 ( & V_15 -> V_144 -> V_15 , V_44 -> V_76 , V_44 -> V_79 ,
V_326 ? V_145 : V_146 ) ;
for ( V_89 = 0 ; V_89 < V_44 -> V_79 ; V_89 ++ )
F_189 ( F_191 ( & V_44 -> V_76 [ V_89 ] ) ) ;
}
static int F_192 ( struct V_105 * V_106 , struct V_336 T_9 * V_337 )
{
struct V_14 * V_15 = V_106 -> V_15 ;
struct V_336 V_338 ;
struct V_8 V_217 ;
unsigned V_78 , V_339 , V_340 ;
int V_56 , V_326 ;
struct V_21 * V_44 ;
T_5 V_341 = 0 ;
void * V_342 = NULL ;
void T_9 * V_182 ;
if ( F_193 ( & V_338 , V_337 , sizeof( V_338 ) ) )
return - V_192 ;
V_78 = ( V_338 . V_343 + 1 ) << V_106 -> V_122 ;
V_339 = ( V_338 . V_343 + 1 ) * V_106 -> V_134 ;
if ( V_339 && ( ( V_338 . V_182 & 3 ) || ! V_338 . V_182 ) && ! V_106 -> V_344 )
return - V_332 ;
else if ( V_339 && V_106 -> V_344 ) {
V_78 += V_339 ;
V_339 = 0 ;
}
V_182 = ( void T_9 * ) ( unsigned long ) V_338 . V_182 ;
V_326 = V_338 . V_159 & 1 ;
switch ( V_338 . V_159 ) {
case V_179 :
case V_180 :
case V_345 :
V_44 = F_181 ( V_15 , V_326 , V_338 . V_327 , V_78 ) ;
break;
default:
return - V_332 ;
}
if ( F_111 ( V_44 ) )
return F_112 ( V_44 ) ;
V_340 = F_77 ( V_15 , V_44 , V_78 , V_223 ) ;
if ( V_78 != V_340 ) {
V_56 = - V_312 ;
goto V_346;
}
if ( V_339 ) {
V_342 = F_150 ( & V_15 -> V_144 -> V_15 , V_339 ,
& V_341 , V_223 ) ;
if ( ! V_342 ) {
V_56 = - V_312 ;
goto V_346;
}
if ( V_326 ) {
if ( F_193 ( V_342 , V_182 , V_339 ) ) {
V_56 = - V_192 ;
goto V_346;
}
}
}
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_178 . V_159 = V_338 . V_159 ;
V_217 . V_178 . V_71 = V_338 . V_71 ;
V_217 . V_178 . V_161 = F_84 ( V_106 -> V_162 ) ;
V_217 . V_178 . V_157 = F_82 ( V_338 . V_157 ) ;
V_217 . V_178 . V_78 = F_87 ( V_338 . V_343 ) ;
V_217 . V_178 . V_170 = F_87 ( V_338 . V_170 ) ;
V_217 . V_178 . V_171 = F_84 ( V_338 . V_171 ) ;
V_217 . V_178 . V_185 = F_84 ( V_338 . V_185 ) ;
V_217 . V_178 . V_347 = F_87 ( V_338 . V_347 ) ;
V_217 . V_178 . V_348 = F_87 ( V_338 . V_348 ) ;
V_217 . V_178 . V_163 = F_82 ( F_79 ( V_44 -> V_76 ) ) ;
V_217 . V_178 . V_181 = F_82 ( V_44 -> V_92 ) ;
V_217 . V_178 . V_182 = F_82 ( V_341 ) ;
V_56 = F_117 ( V_15 , V_106 , & V_217 , NULL ) ;
V_346:
F_190 ( V_15 , V_326 , V_44 ) ;
F_45 ( V_15 , V_44 ) ;
if ( V_342 ) {
if ( V_56 == V_57 && ! V_326 ) {
if ( F_194 ( V_182 , V_342 , V_339 ) )
V_56 = - V_192 ;
}
F_135 ( & V_15 -> V_144 -> V_15 , V_339 , V_342 , V_341 ) ;
}
return V_56 ;
}
static int F_195 ( struct V_14 * V_15 , struct V_105 * V_106 ,
struct V_349 T_9 * V_350 )
{
struct V_349 V_37 ;
struct V_8 V_217 ;
int V_56 , V_78 ;
struct V_21 * V_351 ( V_44 ) ;
unsigned V_140 ;
if ( ! F_196 ( V_352 ) )
return - V_353 ;
if ( F_193 ( & V_37 , V_350 , sizeof( V_37 ) ) )
return - V_192 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_168 . V_159 = V_37 . V_159 ;
V_217 . V_168 . V_71 = V_37 . V_71 ;
V_217 . V_168 . V_161 = F_84 ( V_37 . V_161 ) ;
V_217 . V_168 . V_354 [ 0 ] = F_84 ( V_37 . V_354 ) ;
V_217 . V_168 . V_354 [ 1 ] = F_84 ( V_37 . V_355 ) ;
V_217 . V_168 . V_356 [ 0 ] = F_84 ( V_37 . V_356 ) ;
V_217 . V_168 . V_356 [ 1 ] = F_84 ( V_37 . V_357 ) ;
V_217 . V_168 . V_356 [ 2 ] = F_84 ( V_37 . V_358 ) ;
V_217 . V_168 . V_356 [ 3 ] = F_84 ( V_37 . V_359 ) ;
V_217 . V_168 . V_356 [ 4 ] = F_84 ( V_37 . V_360 ) ;
V_217 . V_168 . V_356 [ 5 ] = F_84 ( V_37 . V_361 ) ;
V_78 = V_37 . V_362 ;
if ( V_37 . V_362 ) {
V_44 = F_181 ( V_15 , V_37 . V_159 & 1 , V_37 . V_327 ,
V_78 ) ;
if ( F_111 ( V_44 ) )
return F_112 ( V_44 ) ;
V_78 = F_77 ( V_15 , V_44 , V_78 , V_223 ) ;
V_217 . V_168 . V_163 = F_82 ( F_79 ( V_44 -> V_76 ) ) ;
V_217 . V_168 . V_181 = F_82 ( V_44 -> V_92 ) ;
}
V_140 = V_37 . V_363 ? F_197 ( V_37 . V_363 ) :
V_225 ;
if ( V_78 != V_37 . V_362 )
V_56 = - V_312 ;
else if ( V_106 ) {
struct V_33 * V_34 ;
V_34 = F_110 ( V_106 -> V_135 , V_220 ,
( V_223 | V_226 ) , false ) ;
if ( F_111 ( V_34 ) )
V_56 = F_112 ( V_34 ) ;
else {
V_56 = F_106 ( V_34 , & V_217 , & V_37 . V_55 ,
V_140 ) ;
F_115 ( V_34 ) ;
}
} else
V_56 = F_114 ( V_15 , & V_217 , & V_37 . V_55 , V_140 ) ;
if ( V_37 . V_362 ) {
F_190 ( V_15 , V_37 . V_159 & 1 , V_44 ) ;
F_45 ( V_15 , V_44 ) ;
}
if ( ( V_56 >= 0 ) && F_194 ( & V_350 -> V_55 , & V_37 . V_55 ,
sizeof( V_37 . V_55 ) ) )
V_56 = - V_192 ;
return V_56 ;
}
static int F_198 ( struct V_364 * V_365 , T_10 V_366 , unsigned int V_37 ,
unsigned long V_367 )
{
struct V_105 * V_106 = V_365 -> V_368 -> V_108 ;
switch ( V_37 ) {
case V_369 :
F_199 () ;
return V_106 -> V_162 ;
case V_370 :
return F_195 ( V_106 -> V_15 , NULL , ( void T_9 * ) V_367 ) ;
case V_371 :
return F_195 ( V_106 -> V_15 , V_106 , ( void T_9 * ) V_367 ) ;
case V_372 :
return F_192 ( V_106 , ( void T_9 * ) V_367 ) ;
case V_373 :
return F_200 ( ( void T_9 * ) V_367 ) ;
case V_374 :
return F_201 ( V_106 , ( void T_9 * ) V_367 ) ;
default:
return - V_375 ;
}
}
static int F_202 ( struct V_364 * V_365 , T_10 V_366 ,
unsigned int V_37 , unsigned long V_367 )
{
switch ( V_37 ) {
case V_374 :
return - V_376 ;
}
return F_198 ( V_365 , V_366 , V_37 , V_367 ) ;
}
static int F_203 ( struct V_364 * V_365 , T_10 V_366 )
{
int V_19 = 0 ;
struct V_105 * V_106 ;
F_101 ( & V_259 ) ;
V_106 = V_365 -> V_368 -> V_108 ;
if ( ! V_106 )
V_19 = - V_377 ;
else if ( ! F_204 ( & V_106 -> V_15 -> V_378 ) )
V_19 = - V_377 ;
F_102 ( & V_259 ) ;
return V_19 ;
}
static void F_205 ( struct V_379 * V_123 , T_10 V_366 )
{
struct V_105 * V_106 = V_123 -> V_108 ;
struct V_14 * V_15 = V_106 -> V_15 ;
F_206 ( & V_15 -> V_378 , V_380 ) ;
}
static int F_207 ( struct V_364 * V_188 , struct V_381 * V_382 )
{
V_382 -> V_383 = 1 << 6 ;
V_382 -> V_384 = 1 << 5 ;
V_382 -> V_385 = F_208 ( V_188 -> V_368 ) >> 11 ;
return 0 ;
}
static void F_209 ( struct V_105 * V_106 )
{
T_2 V_386 = F_210 ( V_106 -> V_135 ) ;
V_106 -> V_135 -> V_387 . V_388 = 0 ;
V_106 -> V_135 -> V_387 . V_389 = V_386 ;
V_106 -> V_135 -> V_387 . V_390 = V_386 ;
V_106 -> V_135 -> V_387 . V_391 = 0xffffffff ;
F_211 ( V_392 , V_106 -> V_135 ) ;
}
static int F_212 ( struct V_379 * V_123 )
{
struct V_105 * V_106 = V_123 -> V_108 ;
struct V_14 * V_15 = V_106 -> V_15 ;
struct V_10 * V_228 ;
T_5 V_152 ;
T_8 V_393 , V_116 ;
T_3 V_394 ;
unsigned short V_395 ;
V_228 = F_150 ( & V_15 -> V_144 -> V_15 , 4096 , & V_152 ,
V_223 ) ;
if ( ! V_228 ) {
F_21 ( & V_15 -> V_144 -> V_15 , L_21 ,
V_396 ) ;
return 0 ;
}
if ( F_123 ( V_15 , V_106 -> V_162 , 0 , V_152 ) ) {
F_21 ( & V_15 -> V_144 -> V_15 ,
L_22 ,
V_106 -> V_162 ) ;
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
}
V_394 = V_106 -> V_134 ;
V_393 = V_228 -> V_397 & V_398 ;
V_106 -> V_122 = V_228 -> V_393 [ V_393 ] . V_399 ;
V_106 -> V_134 = F_97 ( V_228 -> V_393 [ V_393 ] . V_134 ) ;
V_106 -> V_344 = V_106 -> V_134 && ( V_228 -> V_397 & V_400 ) ;
if ( V_106 -> V_122 == 0 )
V_106 -> V_122 = 9 ;
V_395 = 1 << V_106 -> V_122 ;
V_116 = V_106 -> V_134 == sizeof( struct V_102 ) ?
V_228 -> V_401 & V_402 : 0 ;
if ( F_213 ( V_123 ) && ( V_106 -> V_116 != V_116 ||
V_106 -> V_134 != V_394 ||
V_395 != F_210 ( V_123 -> V_135 ) ||
( V_106 -> V_134 && V_106 -> V_344 ) ) )
F_214 ( V_123 ) ;
V_106 -> V_116 = V_116 ;
F_215 ( V_106 -> V_135 , V_395 ) ;
if ( V_106 -> V_134 && ! F_213 ( V_123 ) && ( V_123 -> V_71 & V_403 ) &&
! V_106 -> V_344 )
F_64 ( V_106 ) ;
if ( V_228 -> V_404 == 0 || ( V_106 -> V_134 && ! F_213 ( V_123 ) ) )
F_216 ( V_123 , 0 ) ;
else
F_216 ( V_123 , F_217 ( & V_228 -> V_405 ) << ( V_106 -> V_122 - 9 ) ) ;
if ( V_15 -> V_406 & V_407 )
F_209 ( V_106 ) ;
F_135 ( & V_15 -> V_144 -> V_15 , 4096 , V_228 , V_152 ) ;
return 0 ;
}
static int F_218 ( void * V_27 )
{
struct V_14 * V_15 , * V_408 ;
while ( ! F_219 () ) {
F_107 ( V_409 ) ;
F_101 ( & V_259 ) ;
F_220 (dev, next, &dev_list, node) {
int V_89 ;
if ( F_146 ( & V_15 -> V_275 -> V_276 ) & V_410 ) {
if ( F_127 ( & V_15 -> V_260 ) )
continue;
F_128 ( & V_15 -> V_262 ) ;
F_21 ( & V_15 -> V_144 -> V_15 ,
L_23 ,
F_146 ( & V_15 -> V_275 -> V_276 ) ) ;
V_15 -> V_263 = V_264 ;
F_129 ( V_265 , & V_15 -> V_260 ) ;
continue;
}
for ( V_89 = 0 ; V_89 < V_15 -> V_38 ; V_89 ++ ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_89 ] ;
if ( ! V_30 )
continue;
F_94 ( & V_30 -> V_72 ) ;
F_95 ( V_30 ) ;
while ( ( V_89 == 0 ) && ( V_15 -> V_59 > 0 ) ) {
if ( F_109 ( V_15 ) )
break;
V_15 -> V_59 -- ;
}
F_96 ( & V_30 -> V_72 ) ;
}
}
F_102 ( & V_259 ) ;
F_221 ( F_222 ( V_294 ) ) ;
}
return 0 ;
}
static void F_223 ( struct V_14 * V_15 , unsigned V_161 )
{
struct V_105 * V_106 ;
struct V_379 * V_123 ;
int V_262 = F_170 ( & V_15 -> V_144 -> V_15 ) ;
V_106 = F_224 ( sizeof( * V_106 ) , V_223 , V_262 ) ;
if ( ! V_106 )
return;
V_106 -> V_135 = F_172 ( & V_15 -> V_411 ) ;
if ( F_111 ( V_106 -> V_135 ) )
goto V_412;
F_211 ( V_413 , V_106 -> V_135 ) ;
F_211 ( V_414 , V_106 -> V_135 ) ;
F_211 ( V_415 , V_106 -> V_135 ) ;
V_106 -> V_15 = V_15 ;
V_106 -> V_135 -> V_189 = V_106 ;
V_123 = F_225 ( 0 , V_262 ) ;
if ( ! V_123 )
goto V_416;
V_106 -> V_162 = V_161 ;
V_106 -> V_123 = V_123 ;
V_106 -> V_122 = 9 ;
F_226 ( & V_106 -> V_90 , & V_15 -> V_417 ) ;
F_215 ( V_106 -> V_135 , 1 << V_106 -> V_122 ) ;
if ( V_15 -> V_418 )
F_227 ( V_106 -> V_135 , V_15 -> V_418 ) ;
if ( V_15 -> V_419 )
F_228 ( V_106 -> V_135 , V_15 -> V_419 >> 9 ) ;
if ( V_15 -> V_420 & V_421 )
F_229 ( V_106 -> V_135 , V_198 | V_172 ) ;
V_123 -> V_422 = V_423 ;
V_123 -> V_424 = 0 ;
V_123 -> V_425 = & V_426 ;
V_123 -> V_108 = V_106 ;
V_123 -> V_135 = V_106 -> V_135 ;
V_123 -> V_427 = V_15 -> V_278 ;
V_123 -> V_71 = V_428 ;
sprintf ( V_123 -> V_429 , L_24 , V_15 -> V_283 , V_161 ) ;
F_216 ( V_123 , 0 ) ;
F_212 ( V_106 -> V_123 ) ;
F_230 ( V_106 -> V_123 ) ;
if ( V_106 -> V_134 )
F_231 ( V_106 -> V_123 ) ;
return;
V_416:
F_167 ( V_106 -> V_135 ) ;
V_412:
F_48 ( V_106 ) ;
}
static void F_232 ( struct V_14 * V_15 )
{
unsigned V_89 ;
for ( V_89 = V_15 -> V_38 ; V_89 <= V_15 -> V_430 ; V_89 ++ )
if ( ! F_147 ( V_15 , V_89 , V_15 -> V_66 ) )
break;
for ( V_89 = V_15 -> V_274 ; V_89 <= V_15 -> V_38 - 1 ; V_89 ++ )
if ( F_156 ( V_15 -> V_31 [ V_89 ] , V_89 ) )
break;
}
static int F_233 ( struct V_14 * V_15 , int V_329 )
{
int V_56 ;
T_2 V_55 ;
T_2 V_431 = ( V_329 - 1 ) | ( ( V_329 - 1 ) << 16 ) ;
V_56 = F_125 ( V_15 , V_432 , V_431 , 0 ,
& V_55 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 > 0 ) {
F_162 ( & V_15 -> V_144 -> V_15 , L_25 ,
V_56 ) ;
return 0 ;
}
return F_234 ( V_55 & 0xffff , V_55 >> 16 ) + 1 ;
}
static T_11 F_235 ( struct V_14 * V_15 , unsigned V_433 )
{
return 4096 + ( ( V_433 + 1 ) * 8 * V_15 -> V_206 ) ;
}
static int F_236 ( struct V_14 * V_15 )
{
struct V_29 * V_434 = V_15 -> V_31 [ 0 ] ;
struct V_144 * V_435 = V_15 -> V_144 ;
int V_55 , V_89 , V_436 , V_433 , V_13 ;
V_433 = F_237 () ;
V_55 = F_233 ( V_15 , V_433 ) ;
if ( V_55 <= 0 )
return V_55 ;
if ( V_55 < V_433 )
V_433 = V_55 ;
V_13 = F_235 ( V_15 , V_433 ) ;
if ( V_13 > 8192 ) {
F_238 ( V_15 -> V_275 ) ;
do {
V_15 -> V_275 = F_239 ( F_240 ( V_435 , 0 ) , V_13 ) ;
if ( V_15 -> V_275 )
break;
if ( ! -- V_433 )
return - V_312 ;
V_13 = F_235 ( V_15 , V_433 ) ;
} while ( 1 );
V_15 -> V_284 = ( ( void V_437 * ) V_15 -> V_275 ) + 4096 ;
V_434 -> V_70 = V_15 -> V_284 ;
}
F_142 ( V_15 -> V_273 [ 0 ] . V_272 , V_434 ) ;
if ( ! V_435 -> V_208 )
F_241 ( V_435 ) ;
for ( V_89 = 0 ; V_89 < V_433 ; V_89 ++ )
V_15 -> V_273 [ V_89 ] . V_273 = V_89 ;
V_436 = F_242 ( V_435 , V_15 -> V_273 , 1 , V_433 ) ;
if ( V_436 < 0 ) {
V_436 = F_243 ( V_435 , 1 , F_234 ( V_433 , 32 ) ) ;
if ( V_436 < 0 ) {
V_436 = 1 ;
} else {
for ( V_89 = 0 ; V_89 < V_436 ; V_89 ++ )
V_15 -> V_273 [ V_89 ] . V_272 = V_89 + V_435 -> V_208 ;
}
}
V_433 = V_436 ;
V_15 -> V_430 = V_433 ;
V_55 = F_152 ( V_15 , V_434 , V_434 -> V_282 ) ;
if ( V_55 )
goto V_438;
F_138 ( V_15 , V_433 + 1 ) ;
F_232 ( V_15 ) ;
return 0 ;
V_438:
F_138 ( V_15 , 1 ) ;
return V_55 ;
}
static int F_244 ( struct V_14 * V_15 )
{
struct V_144 * V_435 = V_15 -> V_144 ;
int V_224 ;
unsigned V_439 , V_89 ;
struct V_9 * V_440 ;
void * V_441 ;
T_5 V_152 ;
int V_442 = F_177 ( F_176 ( & V_15 -> V_275 -> V_290 ) ) + 12 ;
V_441 = F_150 ( & V_435 -> V_15 , 4096 , & V_152 , V_223 ) ;
if ( ! V_441 )
return - V_312 ;
V_224 = F_123 ( V_15 , 0 , 1 , V_152 ) ;
if ( V_224 ) {
F_162 ( & V_435 -> V_15 , L_26 , V_224 ) ;
F_135 ( & V_15 -> V_144 -> V_15 , 4096 , V_441 , V_152 ) ;
return - V_99 ;
}
V_440 = V_441 ;
V_439 = F_25 ( & V_440 -> V_439 ) ;
V_15 -> V_406 = F_22 ( & V_440 -> V_406 ) ;
V_15 -> V_60 = V_440 -> V_443 + 1 ;
V_15 -> V_420 = V_440 -> V_420 ;
memcpy ( V_15 -> V_444 , V_440 -> V_445 , sizeof( V_440 -> V_445 ) ) ;
memcpy ( V_15 -> V_446 , V_440 -> V_447 , sizeof( V_440 -> V_447 ) ) ;
memcpy ( V_15 -> V_448 , V_440 -> V_449 , sizeof( V_440 -> V_449 ) ) ;
if ( V_440 -> V_450 )
V_15 -> V_418 = 1 << ( V_440 -> V_450 + V_442 - 9 ) ;
if ( ( V_435 -> V_451 == V_452 ) &&
( V_435 -> V_278 == 0x0953 ) && V_440 -> V_453 [ 3 ] ) {
unsigned int V_418 ;
V_15 -> V_419 = 1 << ( V_440 -> V_453 [ 3 ] + V_442 ) ;
V_418 = V_15 -> V_419 >> ( V_442 - 9 ) ;
if ( V_15 -> V_418 ) {
V_15 -> V_418 = F_234 ( V_418 ,
V_15 -> V_418 ) ;
} else
V_15 -> V_418 = V_418 ;
}
F_135 ( & V_15 -> V_144 -> V_15 , 4096 , V_441 , V_152 ) ;
V_15 -> V_411 . V_305 = & V_454 ;
V_15 -> V_411 . V_307 = V_15 -> V_274 - 1 ;
V_15 -> V_411 . V_140 = V_227 ;
V_15 -> V_411 . V_36 = F_170 ( & V_15 -> V_144 -> V_15 ) ;
V_15 -> V_411 . V_308 =
F_187 ( int , V_15 -> V_66 , V_455 ) - 1 ;
V_15 -> V_411 . V_311 = F_5 ( V_15 ) ;
V_15 -> V_411 . V_71 = V_456 ;
V_15 -> V_411 . V_32 = V_15 ;
if ( F_171 ( & V_15 -> V_411 ) )
return 0 ;
for ( V_89 = 1 ; V_89 <= V_439 ; V_89 ++ )
F_223 ( V_15 , V_89 ) ;
return 0 ;
}
static int F_245 ( struct V_14 * V_15 )
{
T_6 V_290 ;
int V_457 , V_55 = - V_312 ;
struct V_144 * V_435 = V_15 -> V_144 ;
if ( F_246 ( V_435 ) )
return V_55 ;
V_15 -> V_273 [ 0 ] . V_272 = V_435 -> V_208 ;
F_247 ( V_435 ) ;
V_457 = F_248 ( V_435 , V_458 ) ;
if ( ! V_457 )
goto V_459;
if ( F_249 ( V_435 , V_457 , L_27 ) )
goto V_459;
if ( F_250 ( & V_435 -> V_15 , F_251 ( 64 ) ) &&
F_250 ( & V_435 -> V_15 , F_251 ( 32 ) ) )
goto V_460;
V_15 -> V_275 = F_239 ( F_240 ( V_435 , 0 ) , 8192 ) ;
if ( ! V_15 -> V_275 )
goto V_460;
if ( F_146 ( & V_15 -> V_275 -> V_276 ) == - 1 ) {
V_55 = - V_295 ;
goto V_346;
}
if ( ! V_435 -> V_208 ) {
V_55 = F_252 ( V_435 , V_15 -> V_273 , 1 ) ;
if ( V_55 < 0 )
goto V_346;
}
V_290 = F_176 ( & V_15 -> V_275 -> V_290 ) ;
V_15 -> V_66 = F_187 ( int , F_253 ( V_290 ) + 1 , V_461 ) ;
V_15 -> V_206 = 1 << F_254 ( V_290 ) ;
V_15 -> V_284 = ( ( void V_437 * ) V_15 -> V_275 ) + 4096 ;
return 0 ;
V_346:
F_238 ( V_15 -> V_275 ) ;
V_15 -> V_275 = NULL ;
V_460:
F_255 ( V_435 ) ;
V_459:
F_256 ( V_435 ) ;
return V_55 ;
}
static void F_257 ( struct V_14 * V_15 )
{
if ( V_15 -> V_144 -> V_462 )
F_258 ( V_15 -> V_144 ) ;
else if ( V_15 -> V_144 -> V_463 )
F_241 ( V_15 -> V_144 ) ;
if ( V_15 -> V_275 ) {
F_238 ( V_15 -> V_275 ) ;
V_15 -> V_275 = NULL ;
F_255 ( V_15 -> V_144 ) ;
}
if ( F_259 ( V_15 -> V_144 ) )
F_256 ( V_15 -> V_144 ) ;
}
static void F_260 ( struct V_464 * V_465 , struct V_14 * V_15 )
{
V_465 -> V_466 = V_214 ;
F_261 () ;
for (; ; ) {
F_107 ( V_467 ) ;
if ( ! F_262 ( & V_465 -> V_468 ) )
break;
if ( ! F_221 ( V_225 ) ||
F_160 ( V_214 ) ) {
F_107 ( V_469 ) ;
F_163 ( V_15 , F_176 ( & V_15 -> V_275 -> V_290 ) ) ;
F_143 ( V_15 -> V_31 [ 0 ] ) ;
F_263 ( V_465 -> V_63 ) ;
F_145 ( V_15 , 0 ) ;
return;
}
}
F_107 ( V_469 ) ;
}
static void F_264 ( struct V_464 * V_465 )
{
F_265 ( & V_465 -> V_468 ) ;
if ( V_465 -> V_466 )
F_105 ( V_465 -> V_466 ) ;
}
static struct V_464 * F_266 ( struct V_464 * V_465 )
{
F_267 ( & V_465 -> V_468 ) ;
return V_465 ;
}
static void F_268 ( struct V_29 * V_30 )
{
struct V_464 * V_465 = V_30 -> V_62 . V_40 ;
F_264 ( V_465 ) ;
}
static int F_269 ( struct V_29 * V_30 , T_8 V_159 ,
T_12 V_42 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_229 . V_159 = V_159 ;
V_217 . V_229 . V_230 = F_87 ( V_30 -> V_230 ) ;
F_270 ( & V_30 -> V_62 . V_64 , V_42 ) ;
return F_113 ( V_30 -> V_15 , & V_217 , & V_30 -> V_62 ,
V_225 ) ;
}
static void F_271 ( struct V_470 * V_64 )
{
struct V_29 * V_30 = F_272 ( V_64 , struct V_29 ,
V_62 . V_64 ) ;
F_268 ( V_30 ) ;
}
static int F_273 ( struct V_29 * V_30 )
{
return F_269 ( V_30 , V_247 ,
F_271 ) ;
}
static void F_274 ( struct V_470 * V_64 )
{
struct V_29 * V_30 = F_272 ( V_64 , struct V_29 ,
V_62 . V_64 ) ;
int V_56 = V_30 -> V_62 . V_56 ;
if ( ! V_56 )
V_56 = F_273 ( V_30 ) ;
if ( V_56 )
F_268 ( V_30 ) ;
}
static int F_275 ( struct V_29 * V_30 )
{
return F_269 ( V_30 , V_248 ,
F_274 ) ;
}
static void F_276 ( struct V_470 * V_64 )
{
struct V_29 * V_30 = F_272 ( V_64 , struct V_29 ,
V_62 . V_64 ) ;
if ( F_275 ( V_30 ) )
F_268 ( V_30 ) ;
}
static void F_277 ( struct V_14 * V_15 )
{
int V_89 ;
F_278 ( V_63 ) ;
struct V_464 V_465 ;
struct V_471 * V_472 = F_279 ( V_473 ,
& V_63 , L_28 , V_15 -> V_283 ) ;
if ( F_111 ( V_472 ) ) {
F_162 ( & V_15 -> V_144 -> V_15 ,
L_29 ) ;
for ( V_89 = V_15 -> V_38 - 1 ; V_89 > 0 ; V_89 -- )
F_145 ( V_15 , V_89 ) ;
return;
}
V_465 . V_466 = NULL ;
F_280 ( & V_465 . V_468 , 0 ) ;
V_465 . V_63 = & V_63 ;
for ( V_89 = V_15 -> V_38 - 1 ; V_89 > 0 ; V_89 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_89 ] ;
if ( F_139 ( V_30 ) )
continue;
V_30 -> V_62 . V_40 = F_266 ( & V_465 ) ;
V_30 -> V_62 . V_63 = V_465 . V_63 ;
F_270 ( & V_30 -> V_62 . V_64 , F_276 ) ;
F_29 ( V_465 . V_63 , & V_30 -> V_62 . V_64 ) ;
}
F_260 ( & V_465 , V_15 ) ;
F_281 ( V_472 ) ;
}
static void F_282 ( struct V_14 * V_15 )
{
struct V_471 * V_474 = NULL ;
F_101 ( & V_259 ) ;
F_128 ( & V_15 -> V_262 ) ;
if ( F_283 ( & V_475 ) && ! F_284 ( V_476 ) ) {
V_474 = V_476 ;
V_476 = NULL ;
}
F_102 ( & V_259 ) ;
if ( V_474 )
F_281 ( V_474 ) ;
}
static void F_285 ( struct V_14 * V_15 )
{
struct V_105 * V_106 ;
F_286 (ns, &dev->namespaces, list) {
F_140 ( V_106 -> V_135 ) ;
F_101 ( V_106 -> V_135 -> V_142 ) ;
F_287 ( V_477 , V_106 -> V_135 ) ;
F_102 ( V_106 -> V_135 -> V_142 ) ;
F_288 ( V_106 -> V_135 ) ;
F_289 ( V_106 -> V_135 ) ;
}
}
static void F_290 ( struct V_14 * V_15 )
{
struct V_105 * V_106 ;
F_286 (ns, &dev->namespaces, list) {
F_291 ( V_477 , V_106 -> V_135 ) ;
F_174 ( V_106 -> V_135 ) ;
F_292 ( V_106 -> V_135 , true ) ;
F_72 ( V_106 -> V_135 ) ;
}
}
static void F_293 ( struct V_14 * V_15 )
{
int V_89 ;
T_2 V_276 = - 1 ;
F_282 ( V_15 ) ;
if ( V_15 -> V_275 ) {
F_285 ( V_15 ) ;
V_276 = F_146 ( & V_15 -> V_275 -> V_276 ) ;
}
if ( V_276 & V_410 || ! ( V_276 & V_293 ) ) {
for ( V_89 = V_15 -> V_38 - 1 ; V_89 >= 0 ; V_89 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_89 ] ;
F_139 ( V_30 ) ;
}
} else {
F_277 ( V_15 ) ;
F_165 ( V_15 ) ;
F_145 ( V_15 , 0 ) ;
}
F_257 ( V_15 ) ;
for ( V_89 = V_15 -> V_38 - 1 ; V_89 >= 0 ; V_89 -- )
F_143 ( V_15 -> V_31 [ V_89 ] ) ;
}
static void F_294 ( struct V_14 * V_15 )
{
struct V_105 * V_106 ;
F_286 (ns, &dev->namespaces, list) {
if ( V_106 -> V_123 -> V_71 & V_403 ) {
if ( F_213 ( V_106 -> V_123 ) )
F_214 ( V_106 -> V_123 ) ;
F_295 ( V_106 -> V_123 ) ;
}
if ( ! F_132 ( V_106 -> V_135 ) ) {
F_296 ( V_106 -> V_135 ) ;
F_167 ( V_106 -> V_135 ) ;
}
}
}
static int F_297 ( struct V_14 * V_15 )
{
struct V_278 * V_279 = & V_15 -> V_144 -> V_15 ;
V_15 -> V_96 = F_298 ( L_30 , V_279 ,
V_18 , V_18 , 0 ) ;
if ( ! V_15 -> V_96 )
return - V_312 ;
V_15 -> V_93 = F_298 ( L_31 , V_279 ,
256 , 256 , 0 ) ;
if ( ! V_15 -> V_93 ) {
F_299 ( V_15 -> V_96 ) ;
return - V_312 ;
}
return 0 ;
}
static void F_300 ( struct V_14 * V_15 )
{
F_299 ( V_15 -> V_96 ) ;
F_299 ( V_15 -> V_93 ) ;
}
static int F_301 ( struct V_14 * V_15 )
{
int V_283 , error ;
do {
if ( ! F_302 ( & V_478 , V_223 ) )
return - V_295 ;
F_101 ( & V_259 ) ;
error = F_303 ( & V_478 , & V_283 ) ;
F_102 ( & V_259 ) ;
} while ( error == - V_479 );
if ( error )
return - V_295 ;
V_15 -> V_283 = V_283 ;
return 0 ;
}
static void F_304 ( struct V_14 * V_15 )
{
F_101 ( & V_259 ) ;
F_305 ( & V_478 , V_15 -> V_283 ) ;
F_102 ( & V_259 ) ;
}
static void F_306 ( struct V_14 * V_15 )
{
struct V_105 * V_106 , * V_408 ;
F_220 (ns, next, &dev->namespaces, list) {
F_307 ( & V_106 -> V_90 ) ;
F_101 ( & V_259 ) ;
V_106 -> V_123 -> V_108 = NULL ;
F_102 ( & V_259 ) ;
F_308 ( V_106 -> V_123 ) ;
F_48 ( V_106 ) ;
}
}
static void V_380 ( struct V_378 * V_378 )
{
struct V_14 * V_15 = F_272 ( V_378 , struct V_14 , V_378 ) ;
F_309 ( V_15 -> V_144 ) ;
F_310 ( V_15 -> V_278 ) ;
F_306 ( V_15 ) ;
F_304 ( V_15 ) ;
F_168 ( & V_15 -> V_411 ) ;
F_311 ( V_15 -> V_219 ) ;
F_48 ( V_15 -> V_31 ) ;
F_48 ( V_15 -> V_273 ) ;
F_48 ( V_15 ) ;
}
static int F_312 ( struct V_480 * V_480 , struct V_481 * V_482 )
{
struct V_14 * V_15 ;
int V_283 = F_313 ( V_480 ) ;
int V_19 = - V_295 ;
F_101 ( & V_259 ) ;
F_286 (dev, &dev_list, node) {
if ( V_15 -> V_283 == V_283 ) {
if ( ! V_15 -> V_219 ) {
V_19 = - V_483 ;
break;
}
if ( ! F_204 ( & V_15 -> V_378 ) )
break;
V_482 -> V_108 = V_15 ;
V_19 = 0 ;
break;
}
}
F_102 ( & V_259 ) ;
return V_19 ;
}
static int F_314 ( struct V_480 * V_480 , struct V_481 * V_482 )
{
struct V_14 * V_15 = V_482 -> V_108 ;
F_206 ( & V_15 -> V_378 , V_380 ) ;
return 0 ;
}
static long F_315 ( struct V_481 * V_482 , unsigned int V_37 , unsigned long V_367 )
{
struct V_14 * V_15 = V_482 -> V_108 ;
struct V_105 * V_106 ;
switch ( V_37 ) {
case V_370 :
return F_195 ( V_15 , NULL , ( void T_9 * ) V_367 ) ;
case V_371 :
if ( F_283 ( & V_15 -> V_417 ) )
return - V_375 ;
V_106 = F_316 ( & V_15 -> V_417 , struct V_105 , V_90 ) ;
return F_195 ( V_15 , V_106 , ( void T_9 * ) V_367 ) ;
default:
return - V_375 ;
}
}
static void F_317 ( struct V_14 * V_15 )
{
struct V_29 * V_30 ;
int V_89 ;
for ( V_89 = 0 ; V_89 < V_15 -> V_274 ; V_89 ++ ) {
V_30 = V_15 -> V_31 [ V_89 ] ;
if ( ! V_30 -> V_26 )
continue;
F_141 ( V_15 -> V_273 [ V_30 -> V_240 ] . V_272 ,
V_30 -> V_26 -> V_484 ) ;
}
}
static int F_318 ( struct V_14 * V_15 )
{
int V_55 ;
bool V_485 = false ;
V_55 = F_245 ( V_15 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_175 ( V_15 ) ;
if ( V_55 )
goto V_346;
F_101 ( & V_259 ) ;
if ( F_283 ( & V_475 ) && F_284 ( V_476 ) ) {
V_485 = true ;
V_476 = NULL ;
}
F_319 ( & V_15 -> V_262 , & V_475 ) ;
F_102 ( & V_259 ) ;
if ( V_485 ) {
V_476 = F_279 ( F_218 , NULL , L_27 ) ;
F_320 ( & V_486 ) ;
} else
F_321 ( V_486 , V_476 ) ;
if ( F_284 ( V_476 ) ) {
V_55 = V_476 ? F_112 ( V_476 ) : - V_215 ;
goto V_460;
}
F_155 ( V_15 -> V_31 [ 0 ] , 0 ) ;
V_55 = F_169 ( V_15 ) ;
if ( V_55 )
goto V_460;
V_55 = F_236 ( V_15 ) ;
if ( V_55 )
goto V_487;
F_317 ( V_15 ) ;
V_15 -> V_59 = 1 ;
return V_55 ;
V_487:
F_166 ( V_15 ) ;
V_460:
F_145 ( V_15 , 0 ) ;
F_282 ( V_15 ) ;
V_346:
F_257 ( V_15 ) ;
return V_55 ;
}
static int F_322 ( void * V_367 )
{
struct V_14 * V_15 = (struct V_14 * ) V_367 ;
struct V_144 * V_435 = V_15 -> V_144 ;
if ( F_323 ( V_435 ) )
F_324 ( V_435 ) ;
F_206 ( & V_15 -> V_378 , V_380 ) ;
return 0 ;
}
static void F_325 ( struct V_488 * V_489 )
{
struct V_14 * V_15 = F_272 ( V_489 , struct V_14 , V_260 ) ;
F_138 ( V_15 , 1 ) ;
F_294 ( V_15 ) ;
}
static int F_326 ( struct V_14 * V_15 )
{
int V_19 ;
V_19 = F_318 ( V_15 ) ;
if ( V_19 )
return V_19 ;
if ( V_15 -> V_274 < 2 ) {
F_101 ( & V_259 ) ;
V_15 -> V_263 = F_325 ;
F_129 ( V_265 , & V_15 -> V_260 ) ;
F_102 ( & V_259 ) ;
} else {
F_290 ( V_15 ) ;
F_317 ( V_15 ) ;
}
return 0 ;
}
static void F_327 ( struct V_14 * V_15 )
{
F_293 ( V_15 ) ;
if ( F_326 ( V_15 ) ) {
F_21 ( & V_15 -> V_144 -> V_15 , L_32 ) ;
F_328 ( & V_15 -> V_378 ) ;
if ( F_111 ( F_279 ( F_322 , V_15 , L_28 ,
V_15 -> V_283 ) ) ) {
F_162 ( & V_15 -> V_144 -> V_15 ,
L_33 ) ;
F_206 ( & V_15 -> V_378 , V_380 ) ;
}
}
}
static void V_264 ( struct V_488 * V_489 )
{
struct V_14 * V_15 = F_272 ( V_489 , struct V_14 , V_260 ) ;
F_327 ( V_15 ) ;
}
static void F_329 ( struct V_488 * V_64 )
{
struct V_14 * V_15 = F_272 ( V_64 , struct V_14 , V_260 ) ;
V_15 -> V_263 ( V_64 ) ;
}
static int F_330 ( struct V_144 * V_435 , const struct V_490 * V_228 )
{
int V_262 , V_55 = - V_312 ;
struct V_14 * V_15 ;
V_262 = F_170 ( & V_435 -> V_15 ) ;
if ( V_262 == V_491 )
F_331 ( & V_435 -> V_15 , 0 ) ;
V_15 = F_224 ( sizeof( * V_15 ) , V_223 , V_262 ) ;
if ( ! V_15 )
return - V_312 ;
V_15 -> V_273 = F_224 ( F_237 () * sizeof( * V_15 -> V_273 ) ,
V_223 , V_262 ) ;
if ( ! V_15 -> V_273 )
goto free;
V_15 -> V_31 = F_224 ( ( F_237 () + 1 ) * sizeof( void * ) ,
V_223 , V_262 ) ;
if ( ! V_15 -> V_31 )
goto free;
F_332 ( & V_15 -> V_417 ) ;
V_15 -> V_263 = V_264 ;
F_333 ( & V_15 -> V_260 , F_329 ) ;
V_15 -> V_144 = F_334 ( V_435 ) ;
F_335 ( V_435 , V_15 ) ;
V_55 = F_301 ( V_15 ) ;
if ( V_55 )
goto V_492;
V_55 = F_297 ( V_15 ) ;
if ( V_55 )
goto V_493;
F_336 ( & V_15 -> V_378 ) ;
V_15 -> V_278 = F_337 ( V_494 , & V_435 -> V_15 ,
F_338 ( V_495 , V_15 -> V_283 ) ,
V_15 , L_28 , V_15 -> V_283 ) ;
if ( F_111 ( V_15 -> V_278 ) ) {
V_55 = F_112 ( V_15 -> V_278 ) ;
goto V_496;
}
F_339 ( V_15 -> V_278 ) ;
F_332 ( & V_15 -> V_262 ) ;
F_333 ( & V_15 -> V_497 , V_498 ) ;
F_340 ( & V_15 -> V_497 ) ;
return 0 ;
V_496:
F_300 ( V_15 ) ;
V_493:
F_304 ( V_15 ) ;
V_492:
F_309 ( V_15 -> V_144 ) ;
free:
F_48 ( V_15 -> V_31 ) ;
F_48 ( V_15 -> V_273 ) ;
F_48 ( V_15 ) ;
return V_55 ;
}
static void V_498 ( struct V_488 * V_64 )
{
struct V_14 * V_15 = F_272 ( V_64 , struct V_14 , V_497 ) ;
int V_55 ;
V_55 = F_318 ( V_15 ) ;
if ( V_55 )
goto V_499;
if ( V_15 -> V_274 > 1 )
V_55 = F_244 ( V_15 ) ;
if ( V_55 )
goto V_499;
F_317 ( V_15 ) ;
return;
V_499:
if ( ! F_127 ( & V_15 -> V_260 ) ) {
V_15 -> V_263 = V_264 ;
F_129 ( V_265 , & V_15 -> V_260 ) ;
}
}
static void F_341 ( struct V_144 * V_435 , bool V_500 )
{
struct V_14 * V_15 = F_323 ( V_435 ) ;
if ( V_500 )
F_293 ( V_15 ) ;
else
F_326 ( V_15 ) ;
}
static void F_342 ( struct V_144 * V_435 )
{
struct V_14 * V_15 = F_323 ( V_435 ) ;
F_293 ( V_15 ) ;
}
static void F_343 ( struct V_144 * V_435 )
{
struct V_14 * V_15 = F_323 ( V_435 ) ;
F_101 ( & V_259 ) ;
F_128 ( & V_15 -> V_262 ) ;
F_102 ( & V_259 ) ;
F_335 ( V_435 , NULL ) ;
F_344 ( & V_15 -> V_497 ) ;
F_344 ( & V_15 -> V_260 ) ;
F_293 ( V_15 ) ;
F_294 ( V_15 ) ;
F_166 ( V_15 ) ;
F_345 ( V_494 , F_338 ( V_495 , V_15 -> V_283 ) ) ;
F_138 ( V_15 , 0 ) ;
F_300 ( V_15 ) ;
F_206 ( & V_15 -> V_378 , V_380 ) ;
}
static int F_346 ( struct V_278 * V_15 )
{
struct V_144 * V_435 = F_347 ( V_15 ) ;
struct V_14 * V_501 = F_323 ( V_435 ) ;
F_293 ( V_501 ) ;
return 0 ;
}
static int F_348 ( struct V_278 * V_15 )
{
struct V_144 * V_435 = F_347 ( V_15 ) ;
struct V_14 * V_501 = F_323 ( V_435 ) ;
if ( F_326 ( V_501 ) && ! F_127 ( & V_501 -> V_260 ) ) {
V_501 -> V_263 = V_264 ;
F_129 ( V_265 , & V_501 -> V_260 ) ;
}
return 0 ;
}
static int T_13 F_349 ( void )
{
int V_55 ;
F_350 ( & V_486 ) ;
V_265 = F_351 ( L_27 ) ;
if ( ! V_265 )
return - V_312 ;
V_55 = F_352 ( V_423 , L_27 ) ;
if ( V_55 < 0 )
goto V_502;
else if ( V_55 > 0 )
V_423 = V_55 ;
V_55 = F_353 ( V_495 , 0 , V_503 , L_27 ,
& V_504 ) ;
if ( V_55 < 0 )
goto V_505;
else if ( V_55 > 0 )
V_495 = V_55 ;
V_494 = F_354 ( V_506 , L_27 ) ;
if ( F_111 ( V_494 ) ) {
V_55 = F_112 ( V_494 ) ;
goto V_507;
}
V_55 = F_355 ( & V_508 ) ;
if ( V_55 )
goto V_509;
return 0 ;
V_509:
F_356 ( V_494 ) ;
V_507:
F_357 ( V_495 , 0 , V_503 , L_27 ) ;
V_505:
V_505 ( V_423 , L_27 ) ;
V_502:
F_358 ( V_265 ) ;
return V_55 ;
}
static void T_14 F_359 ( void )
{
F_360 ( & V_508 ) ;
V_505 ( V_423 , L_27 ) ;
F_358 ( V_265 ) ;
F_356 ( V_494 ) ;
F_357 ( V_495 , 0 , V_503 , L_27 ) ;
F_11 ( V_476 && ! F_111 ( V_476 ) ) ;
F_1 () ;
}
