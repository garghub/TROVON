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
F_8 ( V_28 != 0 ) ;
F_8 ( V_15 -> V_32 . V_33 [ 0 ] != V_26 -> V_33 ) ;
F_8 ( V_30 -> V_33 ) ;
V_26 -> V_34 = V_30 ;
V_30 -> V_33 = & V_15 -> V_32 . V_33 [ 0 ] ;
return 0 ;
}
static void F_9 ( struct V_25 * V_26 , unsigned int V_28 )
{
struct V_29 * V_30 = V_26 -> V_34 ;
V_30 -> V_33 = NULL ;
}
static int F_10 ( void * V_27 , struct V_35 * V_36 ,
unsigned int V_28 , unsigned int V_37 ,
unsigned int V_38 )
{
struct V_14 * V_15 = V_27 ;
struct V_20 * V_39 = F_11 ( V_36 ) ;
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
F_12 ( ! V_30 ) ;
V_39 -> V_30 = V_30 ;
return 0 ;
}
static int F_13 ( struct V_25 * V_26 , void * V_27 ,
unsigned int V_28 )
{
struct V_14 * V_15 = V_27 ;
struct V_29 * V_30 = V_15 -> V_31 [ V_28 + 1 ] ;
if ( ! V_30 -> V_33 )
V_30 -> V_33 = & V_15 -> V_40 . V_33 [ V_28 ] ;
F_8 ( V_15 -> V_40 . V_33 [ V_28 ] != V_26 -> V_33 ) ;
V_26 -> V_34 = V_30 ;
return 0 ;
}
static int F_14 ( void * V_27 , struct V_35 * V_36 ,
unsigned int V_28 , unsigned int V_37 ,
unsigned int V_38 )
{
struct V_14 * V_15 = V_27 ;
struct V_20 * V_39 = F_11 ( V_36 ) ;
struct V_29 * V_30 = V_15 -> V_31 [ V_28 + 1 ] ;
F_12 ( ! V_30 ) ;
V_39 -> V_30 = V_30 ;
return 0 ;
}
static void F_15 ( struct V_20 * V_39 , void * V_41 ,
T_1 V_42 )
{
V_39 -> V_43 = V_42 ;
V_39 -> V_41 = V_41 ;
V_39 -> V_44 = 0 ;
F_16 ( F_17 ( V_39 ) ) ;
}
static void * F_18 ( struct V_21 * V_45 )
{
return ( void * ) ( V_45 -> V_46 & ~ 0x1UL ) ;
}
static bool F_19 ( struct V_21 * V_45 )
{
return ( V_45 -> V_46 & V_47 ) == 0 ;
}
static void F_20 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
if ( V_41 == V_50 )
return;
if ( V_41 == V_51 ) {
F_21 ( V_30 -> V_52 ,
L_1 ,
V_49 -> V_53 , F_22 ( & V_49 -> V_54 ) ) ;
return;
}
if ( V_41 == V_55 ) {
F_21 ( V_30 -> V_52 ,
L_2 ,
V_49 -> V_53 , F_22 ( & V_49 -> V_54 ) ) ;
return;
}
F_21 ( V_30 -> V_52 , L_3 , V_41 ) ;
}
static void * F_23 ( struct V_20 * V_39 , T_1 * V_43 )
{
void * V_41 ;
if ( V_43 )
* V_43 = V_39 -> V_43 ;
V_41 = V_39 -> V_41 ;
V_39 -> V_43 = F_20 ;
V_39 -> V_41 = V_50 ;
return V_41 ;
}
static void F_24 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
T_2 V_56 = F_25 ( & V_49 -> V_56 ) ;
T_3 V_57 = F_22 ( & V_49 -> V_57 ) >> 1 ;
if ( V_57 == V_58 || V_57 == V_59 )
++ V_30 -> V_15 -> V_60 ;
if ( V_57 != V_58 )
return;
switch ( V_56 & 0xff07 ) {
case V_61 :
F_26 ( V_30 -> V_52 , L_4 ) ;
F_27 ( & V_30 -> V_15 -> V_62 ) ;
default:
F_21 ( V_30 -> V_52 , L_5 , V_56 ) ;
}
}
static void F_28 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
struct V_35 * V_36 = V_41 ;
T_3 V_57 = F_22 ( & V_49 -> V_57 ) >> 1 ;
T_2 V_56 = F_25 ( & V_49 -> V_56 ) ;
F_29 ( V_36 ) ;
F_21 ( V_30 -> V_52 , L_6 , V_57 , V_56 ) ;
++ V_30 -> V_15 -> V_63 ;
}
static void F_30 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
struct V_64 * V_65 = V_41 ;
V_65 -> V_56 = F_25 ( & V_49 -> V_56 ) ;
V_65 -> V_57 = F_22 ( & V_49 -> V_57 ) >> 1 ;
F_31 ( V_65 -> V_66 , & V_65 -> V_67 ) ;
F_29 ( V_65 -> V_36 ) ;
}
static inline struct V_20 * F_32 ( struct V_29 * V_30 ,
unsigned int V_68 )
{
struct V_35 * V_36 = F_33 ( * V_30 -> V_33 , V_68 ) ;
return F_11 ( V_36 ) ;
}
static void * F_34 ( struct V_29 * V_30 , int V_68 ,
T_1 * V_43 )
{
struct V_20 * V_39 = F_32 ( V_30 , V_68 ) ;
void * V_41 ;
if ( V_68 >= V_30 -> V_69 ) {
* V_43 = F_20 ;
return V_55 ;
}
if ( V_43 )
* V_43 = V_39 -> V_43 ;
V_41 = V_39 -> V_41 ;
V_39 -> V_43 = F_20 ;
V_39 -> V_41 = V_51 ;
return V_41 ;
}
static int F_35 ( struct V_29 * V_30 , struct V_8 * V_39 )
{
T_3 V_70 = V_30 -> V_71 ;
memcpy ( & V_30 -> V_72 [ V_70 ] , V_39 , sizeof( * V_39 ) ) ;
if ( ++ V_70 == V_30 -> V_69 )
V_70 = 0 ;
F_36 ( V_70 , V_30 -> V_73 ) ;
V_30 -> V_71 = V_70 ;
return 0 ;
}
static int F_37 ( struct V_29 * V_30 , struct V_8 * V_39 )
{
unsigned long V_74 ;
int V_19 ;
F_38 ( & V_30 -> V_75 , V_74 ) ;
V_19 = F_35 ( V_30 , V_39 ) ;
F_39 ( & V_30 -> V_75 , V_74 ) ;
return V_19 ;
}
static V_22 * * F_40 ( struct V_21 * V_45 )
{
return ( ( void * ) V_45 ) + V_45 -> V_76 ;
}
static inline void F_41 ( struct V_21 * V_45 , unsigned V_77 ,
unsigned V_78 , unsigned long V_46 )
{
V_45 -> V_46 = V_46 ;
V_45 -> V_76 = F_42 ( struct V_21 , V_79 [ V_78 ] ) ;
V_45 -> V_80 = - 1 ;
V_45 -> V_81 = V_77 ;
V_45 -> V_82 = 0 ;
}
static struct V_21 *
F_43 ( unsigned V_78 , unsigned V_83 , struct V_14 * V_15 ,
unsigned long V_84 , T_4 V_85 )
{
struct V_21 * V_45 = F_44 ( sizeof( struct V_21 ) +
sizeof( V_22 * ) * F_3 ( V_83 , V_15 ) +
sizeof( struct V_23 ) * V_78 , V_85 ) ;
if ( V_45 )
F_41 ( V_45 , V_83 , V_78 , V_84 ) ;
return V_45 ;
}
static struct V_21 * F_45 ( struct V_35 * V_86 , struct V_14 * V_15 ,
T_4 V_85 )
{
unsigned V_13 = ! ( V_86 -> V_87 & V_88 ) ? F_46 ( V_86 ) :
sizeof( struct V_89 ) ;
struct V_21 * V_45 ;
if ( V_86 -> V_90 <= V_24 &&
V_13 <= F_6 ( V_15 ) ) {
struct V_20 * V_39 = F_11 ( V_86 ) ;
V_45 = V_39 -> V_45 ;
F_41 ( V_45 , V_13 , V_86 -> V_90 ,
( unsigned long ) V_86 | V_47 ) ;
return V_45 ;
}
return F_43 ( V_86 -> V_90 , V_13 , V_15 ,
( unsigned long ) V_86 , V_85 ) ;
}
static void F_47 ( struct V_14 * V_15 , struct V_21 * V_45 )
{
const int V_91 = V_15 -> V_17 / 8 - 1 ;
int V_92 ;
V_22 * * V_93 = F_40 ( V_45 ) ;
T_5 V_94 = V_45 -> V_95 ;
if ( V_45 -> V_80 == 0 )
F_48 ( V_15 -> V_96 , V_93 [ 0 ] , V_94 ) ;
for ( V_92 = 0 ; V_92 < V_45 -> V_80 ; V_92 ++ ) {
V_22 * V_97 = V_93 [ V_92 ] ;
T_5 V_98 = F_49 ( V_97 [ V_91 ] ) ;
F_48 ( V_15 -> V_99 , V_97 , V_94 ) ;
V_94 = V_98 ;
}
if ( F_19 ( V_45 ) )
F_50 ( V_45 ) ;
}
static int F_51 ( T_3 V_57 )
{
switch ( V_57 & 0x7ff ) {
case V_58 :
return 0 ;
case V_100 :
return - V_101 ;
default:
return - V_102 ;
}
}
static void F_52 ( T_2 V_103 , T_2 V_104 , struct V_105 * V_106 )
{
if ( F_53 ( V_106 -> V_107 ) == V_104 )
V_106 -> V_107 = F_54 ( V_103 ) ;
}
static void F_55 ( T_2 V_103 , T_2 V_104 , struct V_105 * V_106 )
{
if ( F_53 ( V_106 -> V_107 ) == V_103 )
V_106 -> V_107 = F_54 ( V_104 ) ;
}
static void F_56 ( struct V_35 * V_36 ,
void (* F_57)( T_2 V_103 , T_2 V_104 , struct V_105 * V_106 ) )
{
struct V_108 * V_109 = V_36 -> V_110 -> V_111 ;
struct V_112 * V_113 ;
struct V_105 * V_106 ;
void * V_103 , * V_114 ;
T_2 V_92 , V_115 , V_116 , V_117 , V_118 ;
if ( ! V_109 -> V_119 || V_109 -> V_119 == V_120 )
return;
V_113 = F_58 ( V_36 -> V_121 ) ;
if ( ! V_113 )
return;
V_114 = F_59 ( V_113 -> V_122 -> V_123 ) + V_113 -> V_122 -> V_124 ;
V_103 = V_114 ;
V_118 = F_60 ( V_113 ) ;
V_117 = F_61 ( V_109 , F_62 ( V_36 ) ) ;
V_115 = ( F_46 ( V_36 ) >> V_109 -> V_125 ) ;
V_116 = V_109 -> V_126 -> V_127 -> V_128 ;
for ( V_92 = 0 ; V_92 < V_115 ; V_92 ++ , V_118 ++ , V_117 ++ ) {
V_106 = (struct V_105 * ) V_103 ;
F_57 ( V_117 , V_118 , V_106 ) ;
V_103 += V_116 ;
}
F_63 ( V_114 ) ;
}
static int F_64 ( struct V_129 * V_130 )
{
return 0 ;
}
static int F_65 ( struct V_129 * V_130 )
{
return 0 ;
}
static void F_66 ( struct V_108 * V_109 )
{
struct V_131 V_127 ;
switch ( V_109 -> V_119 ) {
case V_120 :
V_127 = V_132 ;
break;
case V_133 :
case V_134 :
V_127 = V_135 ;
break;
default:
V_127 = V_136 ;
break;
}
V_127 . V_128 = V_109 -> V_137 ;
F_67 ( V_109 -> V_126 , & V_127 ) ;
F_68 ( V_109 -> V_138 , 1 ) ;
}
static void F_56 ( struct V_35 * V_36 ,
void (* F_57)( T_2 V_103 , T_2 V_104 , struct V_105 * V_106 ) )
{
}
static void F_52 ( T_2 V_103 , T_2 V_104 , struct V_105 * V_106 )
{
}
static void F_55 ( T_2 V_103 , T_2 V_104 , struct V_105 * V_106 )
{
}
static void F_66 ( struct V_108 * V_109 )
{
}
static void F_69 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
struct V_21 * V_45 = V_41 ;
struct V_35 * V_36 = F_18 ( V_45 ) ;
struct V_20 * V_139 = F_11 ( V_36 ) ;
T_3 V_57 = F_22 ( & V_49 -> V_57 ) >> 1 ;
if ( F_70 ( V_57 ) ) {
if ( ! ( V_57 & V_140 || F_71 ( V_36 ) )
&& ( V_141 - V_36 -> V_142 ) < V_36 -> V_143 ) {
unsigned long V_74 ;
F_72 ( V_36 ) ;
F_38 ( V_36 -> V_144 -> V_145 , V_74 ) ;
if ( ! F_73 ( V_36 -> V_144 ) )
F_74 ( V_36 -> V_144 ) ;
F_39 ( V_36 -> V_144 -> V_145 , V_74 ) ;
return;
}
if ( V_36 -> V_146 == V_147 ) {
if ( V_139 -> V_41 == V_50 )
V_36 -> V_148 = - V_149 ;
else
V_36 -> V_148 = V_57 ;
} else {
V_36 -> V_148 = F_51 ( V_57 ) ;
}
} else
V_36 -> V_148 = 0 ;
if ( V_36 -> V_146 == V_147 ) {
T_2 V_56 = F_25 ( & V_49 -> V_56 ) ;
V_36 -> V_150 = ( void * ) ( V_151 ) V_56 ;
}
if ( V_139 -> V_44 )
F_21 ( V_30 -> V_15 -> V_15 ,
L_7 ,
V_57 ) ;
if ( V_45 -> V_82 ) {
F_75 ( V_30 -> V_15 -> V_15 , V_45 -> V_79 , V_45 -> V_82 ,
F_76 ( V_36 ) ? V_152 : V_153 ) ;
if ( F_77 ( V_36 ) ) {
if ( ! F_76 ( V_36 ) )
F_56 ( V_36 , F_55 ) ;
F_75 ( V_30 -> V_15 -> V_15 , V_45 -> V_154 , 1 ,
F_76 ( V_36 ) ? V_152 : V_153 ) ;
}
}
F_47 ( V_30 -> V_15 , V_45 ) ;
F_78 ( V_36 ) ;
}
static int F_79 ( struct V_14 * V_15 , struct V_21 * V_45 ,
int V_155 , T_4 V_85 )
{
struct V_156 * V_157 ;
int V_81 = V_155 ;
struct V_23 * V_79 = V_45 -> V_79 ;
int V_158 = F_80 ( V_79 ) ;
T_6 V_159 = F_81 ( V_79 ) ;
T_2 V_17 = V_15 -> V_17 ;
int V_76 = V_159 & ( V_17 - 1 ) ;
V_22 * V_97 ;
V_22 * * V_93 = F_40 ( V_45 ) ;
T_5 V_94 ;
int V_16 , V_92 ;
V_81 -= ( V_17 - V_76 ) ;
if ( V_81 <= 0 )
return V_155 ;
V_158 -= ( V_17 - V_76 ) ;
if ( V_158 ) {
V_159 += ( V_17 - V_76 ) ;
} else {
V_79 = F_82 ( V_79 ) ;
V_159 = F_81 ( V_79 ) ;
V_158 = F_80 ( V_79 ) ;
}
if ( V_81 <= V_17 ) {
V_45 -> V_95 = V_159 ;
return V_155 ;
}
V_16 = F_4 ( V_81 , V_17 ) ;
if ( V_16 <= ( 256 / 8 ) ) {
V_157 = V_15 -> V_96 ;
V_45 -> V_80 = 0 ;
} else {
V_157 = V_15 -> V_99 ;
V_45 -> V_80 = 1 ;
}
V_97 = F_83 ( V_157 , V_85 , & V_94 ) ;
if ( ! V_97 ) {
V_45 -> V_95 = V_159 ;
V_45 -> V_80 = - 1 ;
return ( V_155 - V_81 ) + V_17 ;
}
V_93 [ 0 ] = V_97 ;
V_45 -> V_95 = V_94 ;
V_92 = 0 ;
for (; ; ) {
if ( V_92 == V_17 >> 3 ) {
V_22 * V_160 = V_97 ;
V_97 = F_83 ( V_157 , V_85 , & V_94 ) ;
if ( ! V_97 )
return V_155 - V_81 ;
V_93 [ V_45 -> V_80 ++ ] = V_97 ;
V_97 [ 0 ] = V_160 [ V_92 - 1 ] ;
V_160 [ V_92 - 1 ] = F_84 ( V_94 ) ;
V_92 = 1 ;
}
V_97 [ V_92 ++ ] = F_84 ( V_159 ) ;
V_158 -= V_17 ;
V_159 += V_17 ;
V_81 -= V_17 ;
if ( V_81 <= 0 )
break;
if ( V_158 > 0 )
continue;
F_12 ( V_158 < 0 ) ;
V_79 = F_82 ( V_79 ) ;
V_159 = F_81 ( V_79 ) ;
V_158 = F_80 ( V_79 ) ;
}
return V_155 ;
}
static void F_85 ( struct V_29 * V_30 , struct V_35 * V_36 ,
struct V_21 * V_45 )
{
struct V_8 * V_161 = & V_30 -> V_72 [ V_30 -> V_71 ] ;
memcpy ( V_161 , V_36 -> V_39 , sizeof( struct V_8 ) ) ;
V_161 -> V_162 . V_53 = V_36 -> V_68 ;
if ( V_36 -> V_90 ) {
V_161 -> V_162 . V_163 = F_84 ( F_81 ( V_45 -> V_79 ) ) ;
V_161 -> V_162 . V_164 = F_84 ( V_45 -> V_95 ) ;
}
if ( ++ V_30 -> V_71 == V_30 -> V_69 )
V_30 -> V_71 = 0 ;
F_36 ( V_30 -> V_71 , V_30 -> V_73 ) ;
}
static void F_86 ( struct V_29 * V_30 , struct V_108 * V_109 ,
struct V_35 * V_36 , struct V_21 * V_45 )
{
struct V_89 * V_165 =
(struct V_89 * ) F_40 ( V_45 ) [ 0 ] ;
struct V_8 * V_161 = & V_30 -> V_72 [ V_30 -> V_71 ] ;
V_165 -> V_166 = F_87 ( 0 ) ;
V_165 -> V_115 = F_87 ( F_46 ( V_36 ) >> V_109 -> V_125 ) ;
V_165 -> V_167 = F_84 ( F_61 ( V_109 , F_62 ( V_36 ) ) ) ;
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
V_161 -> V_168 . V_169 = V_170 ;
V_161 -> V_168 . V_53 = V_36 -> V_68 ;
V_161 -> V_168 . V_171 = F_87 ( V_109 -> V_172 ) ;
V_161 -> V_168 . V_163 = F_84 ( V_45 -> V_95 ) ;
V_161 -> V_168 . V_173 = 0 ;
V_161 -> V_168 . V_174 = F_87 ( V_175 ) ;
if ( ++ V_30 -> V_71 == V_30 -> V_69 )
V_30 -> V_71 = 0 ;
F_36 ( V_30 -> V_71 , V_30 -> V_73 ) ;
}
static void F_88 ( struct V_29 * V_30 , struct V_108 * V_109 ,
int V_176 )
{
struct V_8 * V_161 = & V_30 -> V_72 [ V_30 -> V_71 ] ;
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
V_161 -> V_177 . V_169 = V_178 ;
V_161 -> V_177 . V_53 = V_176 ;
V_161 -> V_177 . V_171 = F_87 ( V_109 -> V_172 ) ;
if ( ++ V_30 -> V_71 == V_30 -> V_69 )
V_30 -> V_71 = 0 ;
F_36 ( V_30 -> V_71 , V_30 -> V_73 ) ;
}
static int F_89 ( struct V_29 * V_30 , struct V_21 * V_45 ,
struct V_108 * V_109 )
{
struct V_35 * V_36 = F_18 ( V_45 ) ;
struct V_8 * V_161 ;
T_3 V_179 = 0 ;
T_2 V_180 = 0 ;
if ( V_36 -> V_87 & V_181 )
V_179 |= V_182 ;
if ( V_36 -> V_87 & ( V_183 | V_184 ) )
V_179 |= V_185 ;
if ( V_36 -> V_87 & V_184 )
V_180 |= V_186 ;
V_161 = & V_30 -> V_72 [ V_30 -> V_71 ] ;
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
V_161 -> V_162 . V_169 = ( F_76 ( V_36 ) ? V_187 : V_188 ) ;
V_161 -> V_162 . V_53 = V_36 -> V_68 ;
V_161 -> V_162 . V_171 = F_87 ( V_109 -> V_172 ) ;
V_161 -> V_162 . V_163 = F_84 ( F_81 ( V_45 -> V_79 ) ) ;
V_161 -> V_162 . V_164 = F_84 ( V_45 -> V_95 ) ;
V_161 -> V_162 . V_167 = F_84 ( F_61 ( V_109 , F_62 ( V_36 ) ) ) ;
V_161 -> V_162 . V_81 = F_90 ( ( F_46 ( V_36 ) >> V_109 -> V_125 ) - 1 ) ;
if ( F_77 ( V_36 ) ) {
V_161 -> V_162 . V_189 = F_84 ( F_81 ( V_45 -> V_154 ) ) ;
switch ( V_109 -> V_119 ) {
case V_120 :
V_179 |= V_190 ;
break;
case V_133 :
case V_134 :
V_179 |= V_190 |
V_191 ;
V_161 -> V_162 . V_192 = F_87 (
F_61 ( V_109 , F_62 ( V_36 ) ) ) ;
break;
}
} else if ( V_109 -> V_137 )
V_179 |= V_193 ;
V_161 -> V_162 . V_179 = F_90 ( V_179 ) ;
V_161 -> V_162 . V_180 = F_87 ( V_180 ) ;
if ( ++ V_30 -> V_71 == V_30 -> V_69 )
V_30 -> V_71 = 0 ;
F_36 ( V_30 -> V_71 , V_30 -> V_73 ) ;
return 0 ;
}
static int F_91 ( struct V_25 * V_26 ,
const struct V_194 * V_195 )
{
struct V_108 * V_109 = V_26 -> V_138 -> V_196 ;
struct V_29 * V_30 = V_26 -> V_34 ;
struct V_14 * V_15 = V_30 -> V_15 ;
struct V_35 * V_36 = V_195 -> V_86 ;
struct V_20 * V_39 = F_11 ( V_36 ) ;
struct V_21 * V_45 ;
enum V_197 V_198 ;
if ( V_109 && V_109 -> V_137 && ! F_77 ( V_36 ) ) {
if ( ! ( V_109 -> V_119 && V_109 -> V_137 == 8 ) &&
V_36 -> V_146 != V_147 ) {
V_36 -> V_148 = - V_199 ;
F_78 ( V_36 ) ;
return V_200 ;
}
}
V_45 = F_45 ( V_36 , V_15 , V_201 ) ;
if ( ! V_45 )
return V_202 ;
if ( V_36 -> V_87 & V_88 ) {
void * V_165 ;
V_165 = F_83 ( V_15 -> V_96 , V_201 ,
& V_45 -> V_95 ) ;
if ( ! V_165 )
goto V_203;
F_40 ( V_45 ) [ 0 ] = ( V_22 * ) V_165 ;
V_45 -> V_80 = 0 ;
} else if ( V_36 -> V_90 ) {
V_198 = F_76 ( V_36 ) ? V_152 : V_153 ;
F_92 ( V_45 -> V_79 , V_36 -> V_90 ) ;
V_45 -> V_82 = F_93 ( V_36 -> V_144 , V_36 , V_45 -> V_79 ) ;
if ( ! V_45 -> V_82 )
goto V_204;
if ( ! F_94 ( V_30 -> V_52 , V_45 -> V_79 , V_45 -> V_82 , V_198 ) )
goto V_203;
if ( F_46 ( V_36 ) !=
F_79 ( V_15 , V_45 , F_46 ( V_36 ) , V_201 ) ) {
F_75 ( V_15 -> V_15 , V_45 -> V_79 , V_45 -> V_82 , V_198 ) ;
goto V_203;
}
if ( F_77 ( V_36 ) ) {
if ( F_95 ( V_36 -> V_144 , V_36 -> V_121 ) != 1 )
goto V_204;
F_92 ( V_45 -> V_154 , 1 ) ;
if ( F_96 (
V_36 -> V_144 , V_36 -> V_121 , V_45 -> V_154 ) != 1 )
goto V_204;
if ( F_76 ( V_36 ) )
F_56 ( V_36 , F_52 ) ;
if ( ! F_94 ( V_30 -> V_52 , V_45 -> V_154 , 1 , V_198 ) )
goto V_204;
}
}
F_15 ( V_39 , V_45 , F_69 ) ;
F_97 ( & V_30 -> V_75 ) ;
if ( V_36 -> V_146 == V_147 )
F_85 ( V_30 , V_36 , V_45 ) ;
else if ( V_36 -> V_87 & V_88 )
F_86 ( V_30 , V_109 , V_36 , V_45 ) ;
else if ( V_36 -> V_87 & V_205 )
F_88 ( V_30 , V_109 , V_36 -> V_68 ) ;
else
F_89 ( V_30 , V_45 , V_109 ) ;
F_98 ( V_30 ) ;
F_99 ( & V_30 -> V_75 ) ;
return V_200 ;
V_204:
F_47 ( V_15 , V_45 ) ;
return V_206 ;
V_203:
F_47 ( V_15 , V_45 ) ;
return V_202 ;
}
static int F_98 ( struct V_29 * V_30 )
{
T_3 V_207 , V_208 ;
V_207 = V_30 -> V_209 ;
V_208 = V_30 -> V_210 ;
for (; ; ) {
void * V_41 ;
T_1 V_43 ;
struct V_48 V_49 = V_30 -> V_211 [ V_207 ] ;
if ( ( F_100 ( V_49 . V_57 ) & 1 ) != V_208 )
break;
V_30 -> V_212 = F_100 ( V_49 . V_212 ) ;
if ( ++ V_207 == V_30 -> V_69 ) {
V_207 = 0 ;
V_208 = ! V_208 ;
}
V_41 = F_34 ( V_30 , V_49 . V_53 , & V_43 ) ;
V_43 ( V_30 , V_41 , & V_49 ) ;
}
if ( V_207 == V_30 -> V_209 && V_208 == V_30 -> V_210 )
return 0 ;
F_36 ( V_207 , V_30 -> V_73 + V_30 -> V_15 -> V_213 ) ;
V_30 -> V_209 = V_207 ;
V_30 -> V_210 = V_208 ;
V_30 -> V_214 = 1 ;
return 1 ;
}
static T_7 F_101 ( int V_215 , void * V_27 )
{
T_7 V_56 ;
struct V_29 * V_30 = V_27 ;
F_102 ( & V_30 -> V_75 ) ;
F_98 ( V_30 ) ;
V_56 = V_30 -> V_214 ? V_216 : V_217 ;
V_30 -> V_214 = 0 ;
F_103 ( & V_30 -> V_75 ) ;
return V_56 ;
}
static T_7 F_104 ( int V_215 , void * V_27 )
{
struct V_29 * V_30 = V_27 ;
struct V_48 V_49 = V_30 -> V_211 [ V_30 -> V_209 ] ;
if ( ( F_100 ( V_49 . V_57 ) & 1 ) != V_30 -> V_210 )
return V_217 ;
return V_218 ;
}
int F_105 ( struct V_219 * V_144 , struct V_8 * V_39 ,
void * V_220 , void T_8 * V_221 , unsigned V_222 ,
T_2 * V_56 , unsigned V_143 )
{
bool V_223 = V_39 -> V_177 . V_169 & 1 ;
struct V_121 * V_121 = NULL ;
struct V_35 * V_36 ;
int V_19 ;
V_36 = F_106 ( V_144 , V_223 , V_224 , false ) ;
if ( F_107 ( V_36 ) )
return F_108 ( V_36 ) ;
V_36 -> V_146 = V_147 ;
V_36 -> V_87 |= V_225 ;
V_36 -> V_226 = 0 ;
V_36 -> V_227 = ( V_228 ) - 1 ;
V_36 -> V_121 = V_36 -> V_229 = NULL ;
V_36 -> V_143 = V_143 ? V_143 : V_230 ;
V_36 -> V_39 = ( unsigned char * ) V_39 ;
V_36 -> V_231 = sizeof( struct V_8 ) ;
V_36 -> V_150 = ( void * ) 0 ;
if ( V_220 && V_222 ) {
V_19 = F_109 ( V_144 , V_36 , V_220 , V_222 , V_232 ) ;
if ( V_19 )
goto V_233;
} else if ( V_221 && V_222 ) {
V_19 = F_110 ( V_144 , V_36 , NULL , V_221 , V_222 , V_232 ) ;
if ( V_19 )
goto V_233;
V_121 = V_36 -> V_121 ;
}
F_111 ( V_36 -> V_144 , NULL , V_36 , 0 ) ;
if ( V_121 )
F_112 ( V_121 ) ;
if ( V_56 )
* V_56 = ( T_2 ) ( V_151 ) V_36 -> V_150 ;
V_19 = V_36 -> V_148 ;
V_233:
F_29 ( V_36 ) ;
return V_19 ;
}
int F_113 ( struct V_219 * V_144 , struct V_8 * V_39 ,
void * V_220 , unsigned V_222 )
{
return F_105 ( V_144 , V_39 , V_220 , NULL , V_222 , NULL , 0 ) ;
}
static int F_114 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
struct V_8 V_234 ;
struct V_20 * V_235 ;
struct V_35 * V_36 ;
V_36 = F_106 ( V_15 -> V_236 , V_237 , V_201 , true ) ;
if ( F_107 ( V_36 ) )
return F_108 ( V_36 ) ;
V_36 -> V_87 |= V_238 ;
V_235 = F_11 ( V_36 ) ;
F_15 ( V_235 , NULL , F_24 ) ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_177 . V_169 = V_239 ;
V_234 . V_177 . V_53 = V_36 -> V_68 ;
F_29 ( V_36 ) ;
return F_35 ( V_30 , & V_234 ) ;
}
static int F_115 ( struct V_14 * V_15 ,
struct V_8 * V_39 ,
struct V_64 * V_65 , unsigned V_143 )
{
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
struct V_35 * V_36 ;
struct V_20 * V_139 ;
V_36 = F_106 ( V_15 -> V_236 , V_237 , V_224 , false ) ;
if ( F_107 ( V_36 ) )
return F_108 ( V_36 ) ;
V_36 -> V_143 = V_143 ;
V_139 = F_11 ( V_36 ) ;
V_65 -> V_36 = V_36 ;
F_15 ( V_139 , V_65 , F_30 ) ;
V_65 -> V_57 = - V_149 ;
V_39 -> V_177 . V_53 = V_36 -> V_68 ;
return F_37 ( V_30 , V_39 ) ;
}
static int F_116 ( struct V_14 * V_15 , T_9 V_169 , T_3 V_240 )
{
struct V_8 V_234 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_241 . V_169 = V_169 ;
V_234 . V_241 . V_242 = F_90 ( V_240 ) ;
return F_113 ( V_15 -> V_236 , & V_234 , NULL , 0 ) ;
}
static int F_117 ( struct V_14 * V_15 , T_3 V_242 ,
struct V_29 * V_30 )
{
struct V_8 V_234 ;
int V_74 = V_243 | V_244 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_245 . V_169 = V_246 ;
V_234 . V_245 . V_163 = F_84 ( V_30 -> V_247 ) ;
V_234 . V_245 . V_248 = F_90 ( V_242 ) ;
V_234 . V_245 . V_249 = F_90 ( V_30 -> V_69 - 1 ) ;
V_234 . V_245 . V_250 = F_90 ( V_74 ) ;
V_234 . V_245 . V_251 = F_90 ( V_30 -> V_252 ) ;
return F_113 ( V_15 -> V_236 , & V_234 , NULL , 0 ) ;
}
static int F_118 ( struct V_14 * V_15 , T_3 V_242 ,
struct V_29 * V_30 )
{
struct V_8 V_234 ;
int V_74 = V_243 | V_253 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_254 . V_169 = V_255 ;
V_234 . V_254 . V_163 = F_84 ( V_30 -> V_256 ) ;
V_234 . V_254 . V_257 = F_90 ( V_242 ) ;
V_234 . V_254 . V_249 = F_90 ( V_30 -> V_69 - 1 ) ;
V_234 . V_254 . V_258 = F_90 ( V_74 ) ;
V_234 . V_254 . V_248 = F_90 ( V_242 ) ;
return F_113 ( V_15 -> V_236 , & V_234 , NULL , 0 ) ;
}
static int F_119 ( struct V_14 * V_15 , T_3 V_248 )
{
return F_116 ( V_15 , V_259 , V_248 ) ;
}
static int F_120 ( struct V_14 * V_15 , T_3 V_257 )
{
return F_116 ( V_15 , V_260 , V_257 ) ;
}
int F_121 ( struct V_14 * V_15 , struct V_9 * * V_240 )
{
struct V_8 V_234 = { } ;
int error ;
V_234 . V_261 . V_169 = V_262 ;
V_234 . V_261 . V_263 = F_87 ( 1 ) ;
* V_240 = F_44 ( sizeof( struct V_9 ) , V_224 ) ;
if ( ! * V_240 )
return - V_264 ;
error = F_113 ( V_15 -> V_236 , & V_234 , * V_240 ,
sizeof( struct V_9 ) ) ;
if ( error )
F_50 ( * V_240 ) ;
return error ;
}
int F_122 ( struct V_14 * V_15 , unsigned V_171 ,
struct V_10 * * V_240 )
{
struct V_8 V_234 = { } ;
int error ;
V_234 . V_261 . V_169 = V_262 ,
V_234 . V_261 . V_171 = F_87 ( V_171 ) ,
* V_240 = F_44 ( sizeof( struct V_10 ) , V_224 ) ;
if ( ! * V_240 )
return - V_264 ;
error = F_113 ( V_15 -> V_236 , & V_234 , * V_240 ,
sizeof( struct V_10 ) ) ;
if ( error )
F_50 ( * V_240 ) ;
return error ;
}
int F_123 ( struct V_14 * V_15 , unsigned V_265 , unsigned V_171 ,
T_5 V_159 , T_2 * V_56 )
{
struct V_8 V_234 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_266 . V_169 = V_267 ;
V_234 . V_266 . V_171 = F_87 ( V_171 ) ;
V_234 . V_266 . V_163 = F_84 ( V_159 ) ;
V_234 . V_266 . V_265 = F_87 ( V_265 ) ;
return F_105 ( V_15 -> V_236 , & V_234 , NULL , NULL , 0 ,
V_56 , 0 ) ;
}
int F_124 ( struct V_14 * V_15 , unsigned V_265 , unsigned V_268 ,
T_5 V_159 , T_2 * V_56 )
{
struct V_8 V_234 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_266 . V_169 = V_269 ;
V_234 . V_266 . V_163 = F_84 ( V_159 ) ;
V_234 . V_266 . V_265 = F_87 ( V_265 ) ;
V_234 . V_266 . V_268 = F_87 ( V_268 ) ;
return F_105 ( V_15 -> V_236 , & V_234 , NULL , NULL , 0 ,
V_56 , 0 ) ;
}
int F_125 ( struct V_14 * V_15 , struct V_12 * * log )
{
struct V_8 V_234 = { } ;
int error ;
V_234 . V_177 . V_169 = V_270 ,
V_234 . V_177 . V_171 = F_87 ( 0xFFFFFFFF ) ,
V_234 . V_177 . V_271 [ 0 ] = F_87 (
( ( ( sizeof( struct V_12 ) / 4 ) - 1 ) << 16 ) |
V_272 ) ,
* log = F_44 ( sizeof( struct V_12 ) , V_224 ) ;
if ( ! * log )
return - V_264 ;
error = F_113 ( V_15 -> V_236 , & V_234 , * log ,
sizeof( struct V_12 ) ) ;
if ( error )
F_50 ( * log ) ;
return error ;
}
static void F_126 ( struct V_35 * V_36 )
{
struct V_20 * V_139 = F_11 ( V_36 ) ;
struct V_29 * V_30 = V_139 -> V_30 ;
struct V_14 * V_15 = V_30 -> V_15 ;
struct V_35 * V_273 ;
struct V_20 * V_274 ;
struct V_8 V_39 ;
if ( ! V_30 -> V_242 || V_139 -> V_44 ) {
unsigned long V_74 ;
F_38 ( & V_275 , V_74 ) ;
if ( F_127 ( & V_15 -> V_276 ) )
goto V_233;
F_128 ( & V_15 -> V_277 ) ;
F_21 ( V_15 -> V_15 , L_8 ,
V_36 -> V_68 , V_30 -> V_242 ) ;
V_15 -> V_278 = V_279 ;
F_129 ( V_280 , & V_15 -> V_276 ) ;
V_233:
F_39 ( & V_275 , V_74 ) ;
return;
}
if ( ! V_15 -> V_63 )
return;
V_273 = F_106 ( V_15 -> V_236 , V_237 , V_201 ,
false ) ;
if ( F_107 ( V_273 ) )
return;
V_274 = F_11 ( V_273 ) ;
F_15 ( V_274 , V_273 , F_28 ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . abort . V_169 = V_281 ;
V_39 . abort . V_282 = V_36 -> V_68 ;
V_39 . abort . V_257 = F_90 ( V_30 -> V_242 ) ;
V_39 . abort . V_53 = V_273 -> V_68 ;
-- V_15 -> V_63 ;
V_139 -> V_44 = 1 ;
F_21 ( V_30 -> V_52 , L_9 , V_36 -> V_68 ,
V_30 -> V_242 ) ;
if ( F_37 ( V_15 -> V_31 [ 0 ] , & V_39 ) < 0 ) {
F_21 ( V_30 -> V_52 ,
L_10 ,
V_36 -> V_68 , V_30 -> V_242 ) ;
F_29 ( V_273 ) ;
}
}
static void F_130 ( struct V_35 * V_36 , void * V_27 , bool V_283 )
{
struct V_29 * V_30 = V_27 ;
void * V_41 ;
T_1 V_43 ;
struct V_20 * V_39 ;
struct V_48 V_49 ;
if ( ! F_131 ( V_36 ) )
return;
V_39 = F_11 ( V_36 ) ;
if ( V_39 -> V_41 == V_50 )
return;
if ( F_132 ( V_36 -> V_144 ) )
V_49 . V_57 = F_90 ( ( V_59 | V_140 ) << 1 ) ;
else
V_49 . V_57 = F_90 ( V_59 << 1 ) ;
F_21 ( V_30 -> V_52 , L_11 ,
V_36 -> V_68 , V_30 -> V_242 ) ;
V_41 = F_23 ( V_39 , & V_43 ) ;
V_43 ( V_30 , V_41 , & V_49 ) ;
}
static enum V_284 F_133 ( struct V_35 * V_36 , bool V_283 )
{
struct V_20 * V_39 = F_11 ( V_36 ) ;
struct V_29 * V_30 = V_39 -> V_30 ;
F_21 ( V_30 -> V_52 , L_12 , V_36 -> V_68 ,
V_30 -> V_242 ) ;
F_97 ( & V_30 -> V_75 ) ;
F_126 ( V_36 ) ;
F_99 ( & V_30 -> V_75 ) ;
return V_285 ;
}
static void F_134 ( struct V_29 * V_30 )
{
F_135 ( V_30 -> V_52 , F_136 ( V_30 -> V_69 ) ,
( void * ) V_30 -> V_211 , V_30 -> V_247 ) ;
F_135 ( V_30 -> V_52 , F_137 ( V_30 -> V_69 ) ,
V_30 -> V_72 , V_30 -> V_256 ) ;
F_50 ( V_30 ) ;
}
static void F_138 ( struct V_14 * V_15 , int V_286 )
{
int V_92 ;
for ( V_92 = V_15 -> V_287 - 1 ; V_92 >= V_286 ; V_92 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_92 ] ;
V_15 -> V_287 -- ;
V_15 -> V_31 [ V_92 ] = NULL ;
F_134 ( V_30 ) ;
}
}
static int F_139 ( struct V_29 * V_30 )
{
int V_288 ;
F_97 ( & V_30 -> V_75 ) ;
if ( V_30 -> V_252 == - 1 ) {
F_99 ( & V_30 -> V_75 ) ;
return 1 ;
}
V_288 = V_30 -> V_15 -> V_289 [ V_30 -> V_252 ] . V_288 ;
V_30 -> V_15 -> V_290 -- ;
V_30 -> V_252 = - 1 ;
F_99 ( & V_30 -> V_75 ) ;
if ( ! V_30 -> V_242 && V_30 -> V_15 -> V_236 )
F_140 ( V_30 -> V_15 -> V_236 ) ;
F_141 ( V_288 , NULL ) ;
F_142 ( V_288 , V_30 ) ;
return 0 ;
}
static void F_143 ( struct V_29 * V_30 )
{
F_97 ( & V_30 -> V_75 ) ;
if ( V_30 -> V_33 && * V_30 -> V_33 )
F_144 ( * V_30 -> V_33 , F_130 , V_30 ) ;
F_99 ( & V_30 -> V_75 ) ;
}
static void F_145 ( struct V_14 * V_15 , int V_242 )
{
struct V_29 * V_30 = V_15 -> V_31 [ V_242 ] ;
if ( ! V_30 )
return;
if ( F_139 ( V_30 ) )
return;
if ( V_242 && F_146 ( & V_15 -> V_291 -> V_292 ) != - 1 ) {
F_120 ( V_15 , V_242 ) ;
F_119 ( V_15 , V_242 ) ;
}
F_97 ( & V_30 -> V_75 ) ;
F_98 ( V_30 ) ;
F_99 ( & V_30 -> V_75 ) ;
}
static struct V_29 * F_147 ( struct V_14 * V_15 , int V_242 ,
int V_293 )
{
struct V_29 * V_30 = F_148 ( sizeof( * V_30 ) , V_224 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_211 = F_149 ( V_15 -> V_15 , F_136 ( V_293 ) ,
& V_30 -> V_247 , V_224 ) ;
if ( ! V_30 -> V_211 )
goto V_294;
V_30 -> V_72 = F_150 ( V_15 -> V_15 , F_137 ( V_293 ) ,
& V_30 -> V_256 , V_224 ) ;
if ( ! V_30 -> V_72 )
goto V_295;
V_30 -> V_52 = V_15 -> V_15 ;
V_30 -> V_15 = V_15 ;
snprintf ( V_30 -> V_296 , sizeof( V_30 -> V_296 ) , L_13 ,
V_15 -> V_297 , V_242 ) ;
F_151 ( & V_30 -> V_75 ) ;
V_30 -> V_209 = 0 ;
V_30 -> V_210 = 1 ;
V_30 -> V_73 = & V_15 -> V_298 [ V_242 * 2 * V_15 -> V_213 ] ;
V_30 -> V_69 = V_293 ;
V_30 -> V_242 = V_242 ;
V_30 -> V_252 = - 1 ;
V_15 -> V_31 [ V_242 ] = V_30 ;
F_152 () ;
V_15 -> V_287 ++ ;
return V_30 ;
V_295:
F_135 ( V_15 -> V_15 , F_136 ( V_293 ) , ( void * ) V_30 -> V_211 ,
V_30 -> V_247 ) ;
V_294:
F_50 ( V_30 ) ;
return NULL ;
}
static int F_153 ( struct V_14 * V_15 , struct V_29 * V_30 ,
const char * V_299 )
{
if ( V_300 )
return F_154 ( V_15 -> V_289 [ V_30 -> V_252 ] . V_288 ,
F_104 , F_101 , V_301 ,
V_299 , V_30 ) ;
return F_155 ( V_15 -> V_289 [ V_30 -> V_252 ] . V_288 , F_101 ,
V_301 , V_299 , V_30 ) ;
}
static void F_156 ( struct V_29 * V_30 , T_3 V_242 )
{
struct V_14 * V_15 = V_30 -> V_15 ;
F_97 ( & V_30 -> V_75 ) ;
V_30 -> V_71 = 0 ;
V_30 -> V_209 = 0 ;
V_30 -> V_210 = 1 ;
V_30 -> V_73 = & V_15 -> V_298 [ V_242 * 2 * V_15 -> V_213 ] ;
memset ( ( void * ) V_30 -> V_211 , 0 , F_136 ( V_30 -> V_69 ) ) ;
V_15 -> V_290 ++ ;
F_99 ( & V_30 -> V_75 ) ;
}
static int F_157 ( struct V_29 * V_30 , int V_242 )
{
struct V_14 * V_15 = V_30 -> V_15 ;
int V_56 ;
V_30 -> V_252 = V_242 - 1 ;
V_56 = F_117 ( V_15 , V_242 , V_30 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_118 ( V_15 , V_242 , V_30 ) ;
if ( V_56 < 0 )
goto V_302;
V_56 = F_153 ( V_15 , V_30 , V_30 -> V_296 ) ;
if ( V_56 < 0 )
goto V_303;
F_156 ( V_30 , V_242 ) ;
return V_56 ;
V_303:
F_120 ( V_15 , V_242 ) ;
V_302:
F_119 ( V_15 , V_242 ) ;
return V_56 ;
}
static int F_158 ( struct V_14 * V_15 , T_6 V_304 , bool V_305 )
{
unsigned long V_143 ;
T_2 V_306 = V_305 ? V_307 : 0 ;
V_143 = ( ( F_159 ( V_304 ) + 1 ) * V_308 / 2 ) + V_141 ;
while ( ( F_146 ( & V_15 -> V_291 -> V_292 ) & V_307 ) != V_306 ) {
F_160 ( 100 ) ;
if ( F_161 ( V_309 ) )
return - V_149 ;
if ( F_162 ( V_141 , V_143 ) ) {
F_163 ( V_15 -> V_15 ,
L_14 , V_305 ?
L_15 : L_16 ) ;
return - V_310 ;
}
}
return 0 ;
}
static int F_164 ( struct V_14 * V_15 , T_6 V_304 )
{
V_15 -> V_311 &= ~ V_312 ;
V_15 -> V_311 &= ~ V_313 ;
F_36 ( V_15 -> V_311 , & V_15 -> V_291 -> V_314 ) ;
return F_158 ( V_15 , V_304 , false ) ;
}
static int F_165 ( struct V_14 * V_15 , T_6 V_304 )
{
V_15 -> V_311 &= ~ V_312 ;
V_15 -> V_311 |= V_313 ;
F_36 ( V_15 -> V_311 , & V_15 -> V_291 -> V_314 ) ;
return F_158 ( V_15 , V_304 , true ) ;
}
static int F_166 ( struct V_14 * V_15 )
{
unsigned long V_143 ;
V_15 -> V_311 &= ~ V_312 ;
V_15 -> V_311 |= V_315 ;
F_36 ( V_15 -> V_311 , & V_15 -> V_291 -> V_314 ) ;
V_143 = V_316 + V_141 ;
while ( ( F_146 ( & V_15 -> V_291 -> V_292 ) & V_317 ) !=
V_318 ) {
F_160 ( 100 ) ;
if ( F_161 ( V_309 ) )
return - V_149 ;
if ( F_162 ( V_141 , V_143 ) ) {
F_163 ( V_15 -> V_15 ,
L_17 ) ;
return - V_310 ;
}
}
return 0 ;
}
static void F_167 ( struct V_14 * V_15 )
{
if ( V_15 -> V_236 && ! F_132 ( V_15 -> V_236 ) ) {
F_168 ( V_15 -> V_236 ) ;
F_169 ( & V_15 -> V_32 ) ;
}
}
static int F_170 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_236 ) {
V_15 -> V_32 . V_319 = & V_320 ;
V_15 -> V_32 . V_321 = 1 ;
V_15 -> V_32 . V_322 = V_323 - 1 ;
V_15 -> V_32 . V_324 = 1 ;
V_15 -> V_32 . V_143 = V_230 ;
V_15 -> V_32 . V_38 = F_171 ( V_15 -> V_15 ) ;
V_15 -> V_32 . V_325 = F_5 ( V_15 ) ;
V_15 -> V_32 . V_34 = V_15 ;
if ( F_172 ( & V_15 -> V_32 ) )
return - V_264 ;
V_15 -> V_236 = F_173 ( & V_15 -> V_32 ) ;
if ( F_107 ( V_15 -> V_236 ) ) {
F_169 ( & V_15 -> V_32 ) ;
return - V_264 ;
}
if ( ! F_174 ( V_15 -> V_236 ) ) {
F_167 ( V_15 ) ;
V_15 -> V_236 = NULL ;
return - V_310 ;
}
} else
F_175 ( V_15 -> V_236 ) ;
return 0 ;
}
static int F_176 ( struct V_14 * V_15 )
{
int V_56 ;
T_2 V_326 ;
T_6 V_304 = F_177 ( & V_15 -> V_291 -> V_304 ) ;
struct V_29 * V_30 ;
unsigned V_327 = V_328 ;
unsigned V_329 = F_178 ( V_304 ) + 12 ;
unsigned V_330 = F_179 ( V_304 ) + 12 ;
if ( V_327 < V_329 ) {
F_163 ( V_15 -> V_15 ,
L_18
L_19 , 1 << V_329 ,
1 << V_327 ) ;
return - V_310 ;
}
if ( V_327 > V_330 ) {
F_26 ( V_15 -> V_15 ,
L_20
L_21 ,
1 << V_330 , 1 << V_327 ) ;
V_327 = V_330 ;
}
V_56 = F_164 ( V_15 , V_304 ) ;
if ( V_56 < 0 )
return V_56 ;
V_30 = V_15 -> V_31 [ 0 ] ;
if ( ! V_30 ) {
V_30 = F_147 ( V_15 , 0 , V_323 ) ;
if ( ! V_30 )
return - V_264 ;
}
V_326 = V_30 -> V_69 - 1 ;
V_326 |= V_326 << 16 ;
V_15 -> V_17 = 1 << V_327 ;
V_15 -> V_311 = V_331 ;
V_15 -> V_311 |= ( V_327 - 12 ) << V_332 ;
V_15 -> V_311 |= V_333 | V_334 ;
V_15 -> V_311 |= V_335 | V_336 ;
F_36 ( V_326 , & V_15 -> V_291 -> V_326 ) ;
F_180 ( V_30 -> V_256 , & V_15 -> V_291 -> V_337 ) ;
F_180 ( V_30 -> V_247 , & V_15 -> V_291 -> V_338 ) ;
V_56 = F_165 ( V_15 , V_304 ) ;
if ( V_56 )
goto V_294;
V_30 -> V_252 = 0 ;
V_56 = F_153 ( V_15 , V_30 , V_30 -> V_296 ) ;
if ( V_56 ) {
V_30 -> V_252 = - 1 ;
goto V_294;
}
return V_56 ;
V_294:
F_138 ( V_15 , 0 ) ;
return V_56 ;
}
static int F_181 ( struct V_108 * V_109 , struct V_339 T_8 * V_340 )
{
struct V_14 * V_15 = V_109 -> V_15 ;
struct V_339 V_341 ;
struct V_8 V_234 ;
unsigned V_81 , V_342 ;
int V_57 , V_223 ;
T_5 V_343 = 0 ;
void * V_344 = NULL ;
void T_8 * V_189 ;
if ( F_182 ( & V_341 , V_340 , sizeof( V_341 ) ) )
return - V_199 ;
switch ( V_341 . V_169 ) {
case V_187 :
case V_188 :
case V_345 :
break;
default:
return - V_346 ;
}
V_81 = ( V_341 . V_347 + 1 ) << V_109 -> V_125 ;
V_342 = ( V_341 . V_347 + 1 ) * V_109 -> V_137 ;
V_189 = ( void T_8 * ) ( unsigned long ) V_341 . V_189 ;
V_223 = V_341 . V_169 & 1 ;
if ( V_109 -> V_348 ) {
V_81 += V_342 ;
V_342 = 0 ;
}
if ( V_342 ) {
if ( ( ( V_341 . V_189 & 3 ) || ! V_341 . V_189 ) && ! V_109 -> V_348 )
return - V_346 ;
V_344 = F_150 ( V_15 -> V_15 , V_342 ,
& V_343 , V_224 ) ;
if ( ! V_344 ) {
V_57 = - V_264 ;
goto V_349;
}
if ( V_223 ) {
if ( F_182 ( V_344 , V_189 , V_342 ) ) {
V_57 = - V_199 ;
goto V_349;
}
}
}
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_162 . V_169 = V_341 . V_169 ;
V_234 . V_162 . V_74 = V_341 . V_74 ;
V_234 . V_162 . V_171 = F_87 ( V_109 -> V_172 ) ;
V_234 . V_162 . V_167 = F_84 ( V_341 . V_167 ) ;
V_234 . V_162 . V_81 = F_90 ( V_341 . V_347 ) ;
V_234 . V_162 . V_179 = F_90 ( V_341 . V_179 ) ;
V_234 . V_162 . V_180 = F_87 ( V_341 . V_180 ) ;
V_234 . V_162 . V_192 = F_87 ( V_341 . V_192 ) ;
V_234 . V_162 . V_350 = F_90 ( V_341 . V_350 ) ;
V_234 . V_162 . V_351 = F_90 ( V_341 . V_351 ) ;
V_234 . V_162 . V_189 = F_84 ( V_343 ) ;
V_57 = F_105 ( V_109 -> V_138 , & V_234 , NULL ,
( void T_8 * ) V_341 . V_352 , V_81 , NULL , 0 ) ;
V_349:
if ( V_344 ) {
if ( V_57 == V_58 && ! V_223 ) {
if ( F_183 ( V_189 , V_344 , V_342 ) )
V_57 = - V_199 ;
}
F_135 ( V_15 -> V_15 , V_342 , V_344 , V_343 ) ;
}
return V_57 ;
}
static int F_184 ( struct V_14 * V_15 , struct V_108 * V_109 ,
struct V_353 T_8 * V_354 )
{
struct V_353 V_39 ;
struct V_8 V_234 ;
unsigned V_143 = 0 ;
int V_57 ;
if ( ! F_185 ( V_355 ) )
return - V_356 ;
if ( F_182 ( & V_39 , V_354 , sizeof( V_39 ) ) )
return - V_199 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_177 . V_169 = V_39 . V_169 ;
V_234 . V_177 . V_74 = V_39 . V_74 ;
V_234 . V_177 . V_171 = F_87 ( V_39 . V_171 ) ;
V_234 . V_177 . V_357 [ 0 ] = F_87 ( V_39 . V_357 ) ;
V_234 . V_177 . V_357 [ 1 ] = F_87 ( V_39 . V_358 ) ;
V_234 . V_177 . V_271 [ 0 ] = F_87 ( V_39 . V_271 ) ;
V_234 . V_177 . V_271 [ 1 ] = F_87 ( V_39 . V_359 ) ;
V_234 . V_177 . V_271 [ 2 ] = F_87 ( V_39 . V_360 ) ;
V_234 . V_177 . V_271 [ 3 ] = F_87 ( V_39 . V_361 ) ;
V_234 . V_177 . V_271 [ 4 ] = F_87 ( V_39 . V_362 ) ;
V_234 . V_177 . V_271 [ 5 ] = F_87 ( V_39 . V_363 ) ;
if ( V_39 . V_364 )
V_143 = F_186 ( V_39 . V_364 ) ;
V_57 = F_105 ( V_109 ? V_109 -> V_138 : V_15 -> V_236 , & V_234 ,
NULL , ( void T_8 * ) V_39 . V_352 , V_39 . V_365 ,
& V_39 . V_56 , V_143 ) ;
if ( V_57 >= 0 ) {
if ( F_187 ( V_39 . V_56 , & V_354 -> V_56 ) )
return - V_199 ;
}
return V_57 ;
}
static int F_188 ( struct V_366 * V_367 , T_10 V_368 , unsigned int V_39 ,
unsigned long V_369 )
{
struct V_108 * V_109 = V_367 -> V_370 -> V_111 ;
switch ( V_39 ) {
case V_371 :
F_189 () ;
return V_109 -> V_172 ;
case V_372 :
return F_184 ( V_109 -> V_15 , NULL , ( void T_8 * ) V_369 ) ;
case V_373 :
return F_184 ( V_109 -> V_15 , V_109 , ( void T_8 * ) V_369 ) ;
case V_374 :
return F_181 ( V_109 , ( void T_8 * ) V_369 ) ;
case V_375 :
return F_190 ( ( void T_8 * ) V_369 ) ;
case V_376 :
return F_191 ( V_109 , ( void T_8 * ) V_369 ) ;
default:
return - V_377 ;
}
}
static int F_192 ( struct V_366 * V_367 , T_10 V_368 ,
unsigned int V_39 , unsigned long V_369 )
{
switch ( V_39 ) {
case V_376 :
return - V_378 ;
}
return F_188 ( V_367 , V_368 , V_39 , V_369 ) ;
}
static int F_193 ( struct V_366 * V_367 , T_10 V_368 )
{
int V_19 = 0 ;
struct V_108 * V_109 ;
F_102 ( & V_275 ) ;
V_109 = V_367 -> V_370 -> V_111 ;
if ( ! V_109 )
V_19 = - V_379 ;
else if ( ! F_194 ( & V_109 -> V_15 -> V_380 ) )
V_19 = - V_379 ;
F_103 ( & V_275 ) ;
return V_19 ;
}
static void F_195 ( struct V_381 * V_126 , T_10 V_368 )
{
struct V_108 * V_109 = V_126 -> V_111 ;
struct V_14 * V_15 = V_109 -> V_15 ;
F_196 ( & V_15 -> V_380 , V_382 ) ;
}
static int F_197 ( struct V_366 * V_195 , struct V_383 * V_384 )
{
V_384 -> V_385 = 1 << 6 ;
V_384 -> V_386 = 1 << 5 ;
V_384 -> V_387 = F_198 ( V_195 -> V_370 ) >> 11 ;
return 0 ;
}
static void F_199 ( struct V_108 * V_109 )
{
T_2 V_388 = F_200 ( V_109 -> V_138 ) ;
V_109 -> V_138 -> V_389 . V_390 = 0 ;
V_109 -> V_138 -> V_389 . V_391 = V_388 ;
V_109 -> V_138 -> V_389 . V_392 = V_388 ;
V_109 -> V_138 -> V_389 . V_393 = 0xffffffff ;
F_201 ( V_394 , V_109 -> V_138 ) ;
}
static int F_202 ( struct V_381 * V_126 )
{
struct V_108 * V_109 = V_126 -> V_111 ;
struct V_14 * V_15 = V_109 -> V_15 ;
struct V_10 * V_240 ;
T_9 V_395 , V_119 ;
T_3 V_396 ;
unsigned short V_397 ;
if ( F_122 ( V_15 , V_109 -> V_172 , & V_240 ) ) {
F_21 ( V_15 -> V_15 , L_22 , V_398 ,
V_15 -> V_297 , V_109 -> V_172 ) ;
return - V_310 ;
}
if ( V_240 -> V_399 == 0 ) {
F_50 ( V_240 ) ;
return - V_310 ;
}
V_396 = V_109 -> V_137 ;
V_395 = V_240 -> V_400 & V_401 ;
V_109 -> V_125 = V_240 -> V_395 [ V_395 ] . V_402 ;
V_109 -> V_137 = F_100 ( V_240 -> V_395 [ V_395 ] . V_137 ) ;
V_109 -> V_348 = V_109 -> V_137 && ( V_240 -> V_400 & V_403 ) ;
if ( V_109 -> V_125 == 0 )
V_109 -> V_125 = 9 ;
V_397 = 1 << V_109 -> V_125 ;
V_119 = V_109 -> V_137 == sizeof( struct V_105 ) ?
V_240 -> V_404 & V_405 : 0 ;
if ( F_203 ( V_126 ) && ( V_109 -> V_119 != V_119 ||
V_109 -> V_137 != V_396 ||
V_397 != F_200 ( V_126 -> V_138 ) ||
( V_109 -> V_137 && V_109 -> V_348 ) ) )
F_204 ( V_126 ) ;
V_109 -> V_119 = V_119 ;
F_205 ( V_109 -> V_138 , V_397 ) ;
if ( V_109 -> V_137 && ! F_203 ( V_126 ) && ( V_126 -> V_74 & V_406 ) &&
! V_109 -> V_348 )
F_66 ( V_109 ) ;
if ( V_109 -> V_137 && ! F_203 ( V_126 ) )
F_206 ( V_126 , 0 ) ;
else
F_206 ( V_126 , F_207 ( & V_240 -> V_407 ) << ( V_109 -> V_125 - 9 ) ) ;
if ( V_15 -> V_408 & V_409 )
F_199 ( V_109 ) ;
F_50 ( V_240 ) ;
return 0 ;
}
static int F_208 ( void * V_27 )
{
struct V_14 * V_15 , * V_410 ;
while ( ! F_209 () ) {
F_210 ( V_411 ) ;
F_102 ( & V_275 ) ;
F_211 (dev, next, &dev_list, node) {
int V_92 ;
if ( F_146 ( & V_15 -> V_291 -> V_292 ) & V_412 ) {
if ( F_127 ( & V_15 -> V_276 ) )
continue;
F_128 ( & V_15 -> V_277 ) ;
F_21 ( V_15 -> V_15 ,
L_23 ,
F_146 ( & V_15 -> V_291 -> V_292 ) ) ;
V_15 -> V_278 = V_279 ;
F_129 ( V_280 , & V_15 -> V_276 ) ;
continue;
}
for ( V_92 = 0 ; V_92 < V_15 -> V_287 ; V_92 ++ ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_92 ] ;
if ( ! V_30 )
continue;
F_97 ( & V_30 -> V_75 ) ;
F_98 ( V_30 ) ;
while ( ( V_92 == 0 ) && ( V_15 -> V_60 > 0 ) ) {
if ( F_114 ( V_15 ) )
break;
V_15 -> V_60 -- ;
}
F_99 ( & V_30 -> V_75 ) ;
}
}
F_103 ( & V_275 ) ;
F_212 ( F_213 ( V_308 ) ) ;
}
return 0 ;
}
static void F_214 ( struct V_14 * V_15 , unsigned V_171 )
{
struct V_108 * V_109 ;
struct V_381 * V_126 ;
int V_277 = F_171 ( V_15 -> V_15 ) ;
V_109 = F_215 ( sizeof( * V_109 ) , V_224 , V_277 ) ;
if ( ! V_109 )
return;
V_109 -> V_138 = F_173 ( & V_15 -> V_40 ) ;
if ( F_107 ( V_109 -> V_138 ) )
goto V_413;
F_201 ( V_414 , V_109 -> V_138 ) ;
F_201 ( V_415 , V_109 -> V_138 ) ;
F_201 ( V_416 , V_109 -> V_138 ) ;
V_109 -> V_15 = V_15 ;
V_109 -> V_138 -> V_196 = V_109 ;
V_126 = F_216 ( 0 , V_277 ) ;
if ( ! V_126 )
goto V_417;
V_109 -> V_172 = V_171 ;
V_109 -> V_126 = V_126 ;
V_109 -> V_125 = 9 ;
F_217 ( & V_109 -> V_93 , & V_15 -> V_418 ) ;
F_205 ( V_109 -> V_138 , 1 << V_109 -> V_125 ) ;
if ( V_15 -> V_419 )
F_218 ( V_109 -> V_138 , V_15 -> V_419 ) ;
if ( V_15 -> V_420 )
F_219 ( V_109 -> V_138 , V_15 -> V_420 >> 9 ) ;
if ( V_15 -> V_421 & V_422 )
F_220 ( V_109 -> V_138 , V_205 | V_181 ) ;
V_126 -> V_423 = V_424 ;
V_126 -> V_425 = 0 ;
V_126 -> V_426 = & V_427 ;
V_126 -> V_111 = V_109 ;
V_126 -> V_138 = V_109 -> V_138 ;
V_126 -> V_428 = V_15 -> V_429 ;
V_126 -> V_74 = V_430 ;
sprintf ( V_126 -> V_431 , L_24 , V_15 -> V_297 , V_171 ) ;
F_206 ( V_126 , 0 ) ;
if ( F_202 ( V_109 -> V_126 ) )
goto V_432;
F_221 ( V_109 -> V_126 ) ;
if ( V_109 -> V_137 ) {
struct V_366 * V_195 = F_222 ( V_109 -> V_126 , 0 ) ;
if ( ! V_195 )
return;
if ( F_223 ( V_195 , V_433 , NULL ) ) {
F_224 ( V_195 ) ;
return;
}
F_225 ( V_195 ) ;
F_226 ( V_195 , V_433 ) ;
}
return;
V_432:
F_50 ( V_126 ) ;
F_227 ( & V_109 -> V_93 ) ;
V_417:
F_168 ( V_109 -> V_138 ) ;
V_413:
F_50 ( V_109 ) ;
}
static void F_228 ( struct V_14 * V_15 )
{
unsigned V_92 ;
for ( V_92 = V_15 -> V_287 ; V_92 <= V_15 -> V_434 ; V_92 ++ )
if ( ! F_147 ( V_15 , V_92 , V_15 -> V_69 ) )
break;
for ( V_92 = V_15 -> V_290 ; V_92 <= V_15 -> V_287 - 1 ; V_92 ++ )
if ( F_157 ( V_15 -> V_31 [ V_92 ] , V_92 ) )
break;
}
static int F_229 ( struct V_14 * V_15 , int V_435 )
{
int V_57 ;
T_2 V_56 ;
T_2 V_436 = ( V_435 - 1 ) | ( ( V_435 - 1 ) << 16 ) ;
V_57 = F_124 ( V_15 , V_437 , V_436 , 0 ,
& V_56 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 > 0 ) {
F_163 ( V_15 -> V_15 , L_25 , V_57 ) ;
return 0 ;
}
return F_230 ( V_56 & 0xffff , V_56 >> 16 ) + 1 ;
}
static T_11 F_231 ( struct V_14 * V_15 , unsigned V_438 )
{
return 4096 + ( ( V_438 + 1 ) * 8 * V_15 -> V_213 ) ;
}
static int F_232 ( struct V_14 * V_15 )
{
struct V_29 * V_439 = V_15 -> V_31 [ 0 ] ;
struct V_440 * V_441 = F_233 ( V_15 -> V_15 ) ;
int V_56 , V_92 , V_442 , V_438 , V_13 ;
V_438 = F_234 () ;
V_56 = F_229 ( V_15 , V_438 ) ;
if ( V_56 <= 0 )
return V_56 ;
if ( V_56 < V_438 )
V_438 = V_56 ;
V_13 = F_231 ( V_15 , V_438 ) ;
if ( V_13 > 8192 ) {
F_235 ( V_15 -> V_291 ) ;
do {
V_15 -> V_291 = F_236 ( F_237 ( V_441 , 0 ) , V_13 ) ;
if ( V_15 -> V_291 )
break;
if ( ! -- V_438 )
return - V_264 ;
V_13 = F_231 ( V_15 , V_438 ) ;
} while ( 1 );
V_15 -> V_298 = ( ( void V_443 * ) V_15 -> V_291 ) + 4096 ;
V_439 -> V_73 = V_15 -> V_298 ;
}
F_142 ( V_15 -> V_289 [ 0 ] . V_288 , V_439 ) ;
if ( ! V_441 -> V_215 )
F_238 ( V_441 ) ;
for ( V_92 = 0 ; V_92 < V_438 ; V_92 ++ )
V_15 -> V_289 [ V_92 ] . V_289 = V_92 ;
V_442 = F_239 ( V_441 , V_15 -> V_289 , 1 , V_438 ) ;
if ( V_442 < 0 ) {
V_442 = F_240 ( V_441 , 1 , F_230 ( V_438 , 32 ) ) ;
if ( V_442 < 0 ) {
V_442 = 1 ;
} else {
for ( V_92 = 0 ; V_92 < V_442 ; V_92 ++ )
V_15 -> V_289 [ V_92 ] . V_288 = V_92 + V_441 -> V_215 ;
}
}
V_438 = V_442 ;
V_15 -> V_434 = V_438 ;
V_56 = F_153 ( V_15 , V_439 , V_439 -> V_296 ) ;
if ( V_56 ) {
V_439 -> V_252 = - 1 ;
goto V_444;
}
F_138 ( V_15 , V_438 + 1 ) ;
F_228 ( V_15 ) ;
return 0 ;
V_444:
F_138 ( V_15 , 1 ) ;
return V_56 ;
}
static void F_241 ( struct V_108 * V_109 )
{
F_227 ( & V_109 -> V_93 ) ;
F_102 ( & V_275 ) ;
V_109 -> V_126 -> V_111 = NULL ;
F_103 ( & V_275 ) ;
F_242 ( V_109 -> V_126 ) ;
F_50 ( V_109 ) ;
}
static int F_243 ( void * V_84 , struct V_445 * V_446 , struct V_445 * V_447 )
{
struct V_108 * V_448 = F_244 ( V_446 , struct V_108 , V_93 ) ;
struct V_108 * V_449 = F_244 ( V_447 , struct V_108 , V_93 ) ;
return V_448 -> V_172 - V_449 -> V_172 ;
}
static struct V_108 * F_245 ( struct V_14 * V_15 , unsigned V_171 )
{
struct V_108 * V_109 ;
F_246 (ns, &dev->namespaces, list) {
if ( V_109 -> V_172 == V_171 )
return V_109 ;
if ( V_109 -> V_172 > V_171 )
break;
}
return NULL ;
}
static inline bool F_247 ( struct V_14 * V_15 )
{
return ( ! V_15 -> V_291 || F_146 ( & V_15 -> V_291 -> V_292 ) & V_412 ||
V_15 -> V_290 < 2 ) ;
}
static void F_248 ( struct V_108 * V_109 )
{
bool V_450 = F_247 ( V_109 -> V_15 ) && ! F_132 ( V_109 -> V_138 ) ;
if ( V_450 )
F_249 ( V_109 -> V_138 ) ;
if ( V_109 -> V_126 -> V_74 & V_406 ) {
if ( F_203 ( V_109 -> V_126 ) )
F_204 ( V_109 -> V_126 ) ;
F_250 ( V_109 -> V_126 ) ;
}
if ( V_450 || ! F_132 ( V_109 -> V_138 ) ) {
F_251 ( V_109 -> V_138 ) ;
F_168 ( V_109 -> V_138 ) ;
}
}
static void F_252 ( struct V_14 * V_15 , unsigned V_451 )
{
struct V_108 * V_109 , * V_410 ;
unsigned V_92 ;
for ( V_92 = 1 ; V_92 <= V_451 ; V_92 ++ ) {
V_109 = F_245 ( V_15 , V_92 ) ;
if ( V_109 ) {
if ( F_253 ( V_109 -> V_126 ) ) {
F_248 ( V_109 ) ;
F_241 ( V_109 ) ;
}
} else
F_214 ( V_15 , V_92 ) ;
}
F_211 (ns, next, &dev->namespaces, list) {
if ( V_109 -> V_172 > V_451 ) {
F_248 ( V_109 ) ;
F_241 ( V_109 ) ;
}
}
F_254 ( NULL , & V_15 -> V_418 , F_243 ) ;
}
static void F_255 ( struct V_452 * V_67 )
{
struct V_14 * V_15 = F_244 ( V_67 , struct V_14 , V_62 ) ;
struct V_9 * V_453 ;
if ( ! V_15 -> V_40 . V_33 )
return;
if ( F_121 ( V_15 , & V_453 ) )
return;
F_252 ( V_15 , F_25 ( & V_453 -> V_451 ) ) ;
F_50 ( V_453 ) ;
}
static int F_256 ( struct V_14 * V_15 )
{
struct V_440 * V_441 = F_233 ( V_15 -> V_15 ) ;
int V_454 ;
unsigned V_451 ;
struct V_9 * V_453 ;
int V_455 = F_178 ( F_177 ( & V_15 -> V_291 -> V_304 ) ) + 12 ;
V_454 = F_121 ( V_15 , & V_453 ) ;
if ( V_454 ) {
F_163 ( V_15 -> V_15 , L_26 , V_454 ) ;
return - V_102 ;
}
V_451 = F_25 ( & V_453 -> V_451 ) ;
V_15 -> V_408 = F_22 ( & V_453 -> V_408 ) ;
V_15 -> V_63 = V_453 -> V_456 + 1 ;
V_15 -> V_421 = V_453 -> V_421 ;
memcpy ( V_15 -> V_457 , V_453 -> V_458 , sizeof( V_453 -> V_458 ) ) ;
memcpy ( V_15 -> V_459 , V_453 -> V_460 , sizeof( V_453 -> V_460 ) ) ;
memcpy ( V_15 -> V_461 , V_453 -> V_462 , sizeof( V_453 -> V_462 ) ) ;
if ( V_453 -> V_463 )
V_15 -> V_419 = 1 << ( V_453 -> V_463 + V_455 - 9 ) ;
if ( ( V_441 -> V_464 == V_465 ) &&
( V_441 -> V_429 == 0x0953 ) && V_453 -> V_466 [ 3 ] ) {
unsigned int V_419 ;
V_15 -> V_420 = 1 << ( V_453 -> V_466 [ 3 ] + V_455 ) ;
V_419 = V_15 -> V_420 >> ( V_455 - 9 ) ;
if ( V_15 -> V_419 ) {
V_15 -> V_419 = F_230 ( V_419 ,
V_15 -> V_419 ) ;
} else
V_15 -> V_419 = V_419 ;
}
F_50 ( V_453 ) ;
if ( ! V_15 -> V_40 . V_33 ) {
V_15 -> V_40 . V_319 = & V_467 ;
V_15 -> V_40 . V_321 = V_15 -> V_290 - 1 ;
V_15 -> V_40 . V_143 = V_468 ;
V_15 -> V_40 . V_38 = F_171 ( V_15 -> V_15 ) ;
V_15 -> V_40 . V_322 =
F_257 ( int , V_15 -> V_69 , V_469 ) - 1 ;
V_15 -> V_40 . V_325 = F_5 ( V_15 ) ;
V_15 -> V_40 . V_74 = V_470 ;
V_15 -> V_40 . V_34 = V_15 ;
if ( F_172 ( & V_15 -> V_40 ) )
return 0 ;
}
F_27 ( & V_15 -> V_62 ) ;
return 0 ;
}
static int F_258 ( struct V_14 * V_15 )
{
T_6 V_304 ;
int V_471 , V_56 = - V_264 ;
struct V_440 * V_441 = F_233 ( V_15 -> V_15 ) ;
if ( F_259 ( V_441 ) )
return V_56 ;
V_15 -> V_289 [ 0 ] . V_288 = V_441 -> V_215 ;
F_260 ( V_441 ) ;
V_471 = F_261 ( V_441 , V_472 ) ;
if ( ! V_471 )
goto V_473;
if ( F_262 ( V_441 , V_471 , L_27 ) )
goto V_473;
if ( F_263 ( V_15 -> V_15 , F_264 ( 64 ) ) &&
F_263 ( V_15 -> V_15 , F_264 ( 32 ) ) )
goto V_474;
V_15 -> V_291 = F_236 ( F_237 ( V_441 , 0 ) , 8192 ) ;
if ( ! V_15 -> V_291 )
goto V_474;
if ( F_146 ( & V_15 -> V_291 -> V_292 ) == - 1 ) {
V_56 = - V_310 ;
goto V_349;
}
if ( ! V_441 -> V_215 ) {
V_56 = F_265 ( V_441 , V_15 -> V_289 , 1 ) ;
if ( V_56 < 0 )
goto V_349;
}
V_304 = F_177 ( & V_15 -> V_291 -> V_304 ) ;
V_15 -> V_69 = F_257 ( int , F_266 ( V_304 ) + 1 , V_475 ) ;
V_15 -> V_213 = 1 << F_267 ( V_304 ) ;
V_15 -> V_298 = ( ( void V_443 * ) V_15 -> V_291 ) + 4096 ;
return 0 ;
V_349:
F_235 ( V_15 -> V_291 ) ;
V_15 -> V_291 = NULL ;
V_474:
F_268 ( V_441 ) ;
V_473:
F_269 ( V_441 ) ;
return V_56 ;
}
static void F_270 ( struct V_14 * V_15 )
{
struct V_440 * V_441 = F_233 ( V_15 -> V_15 ) ;
if ( V_441 -> V_476 )
F_271 ( V_441 ) ;
else if ( V_441 -> V_477 )
F_238 ( V_441 ) ;
if ( V_15 -> V_291 ) {
F_235 ( V_15 -> V_291 ) ;
V_15 -> V_291 = NULL ;
F_268 ( V_441 ) ;
}
if ( F_272 ( V_441 ) )
F_269 ( V_441 ) ;
}
static void F_273 ( struct V_478 * V_479 , struct V_14 * V_15 )
{
V_479 -> V_480 = V_309 ;
F_152 () ;
for (; ; ) {
F_210 ( V_481 ) ;
if ( ! F_274 ( & V_479 -> V_482 ) )
break;
if ( ! F_212 ( V_230 ) ||
F_161 ( V_309 ) ) {
F_210 ( V_483 ) ;
F_164 ( V_15 , F_177 ( & V_15 -> V_291 -> V_304 ) ) ;
F_143 ( V_15 -> V_31 [ 0 ] ) ;
F_275 ( V_479 -> V_66 ) ;
F_145 ( V_15 , 0 ) ;
return;
}
}
F_210 ( V_483 ) ;
}
static void F_276 ( struct V_478 * V_479 )
{
F_277 ( & V_479 -> V_482 ) ;
if ( V_479 -> V_480 )
F_278 ( V_479 -> V_480 ) ;
}
static struct V_478 * F_279 ( struct V_478 * V_479 )
{
F_280 ( & V_479 -> V_482 ) ;
return V_479 ;
}
static void F_281 ( struct V_29 * V_30 )
{
struct V_478 * V_479 = V_30 -> V_65 . V_41 ;
F_276 ( V_479 ) ;
}
static int F_282 ( struct V_29 * V_30 , T_9 V_169 ,
T_12 V_43 )
{
struct V_8 V_234 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_241 . V_169 = V_169 ;
V_234 . V_241 . V_242 = F_90 ( V_30 -> V_242 ) ;
F_283 ( & V_30 -> V_65 . V_67 , V_43 ) ;
return F_115 ( V_30 -> V_15 , & V_234 , & V_30 -> V_65 ,
V_230 ) ;
}
static void F_284 ( struct V_484 * V_67 )
{
struct V_29 * V_30 = F_244 ( V_67 , struct V_29 ,
V_65 . V_67 ) ;
F_281 ( V_30 ) ;
}
static int F_285 ( struct V_29 * V_30 )
{
return F_282 ( V_30 , V_259 ,
F_284 ) ;
}
static void F_286 ( struct V_484 * V_67 )
{
struct V_29 * V_30 = F_244 ( V_67 , struct V_29 ,
V_65 . V_67 ) ;
int V_57 = V_30 -> V_65 . V_57 ;
if ( ! V_57 )
V_57 = F_285 ( V_30 ) ;
if ( V_57 )
F_281 ( V_30 ) ;
}
static int F_287 ( struct V_29 * V_30 )
{
return F_282 ( V_30 , V_260 ,
F_286 ) ;
}
static void F_288 ( struct V_484 * V_67 )
{
struct V_29 * V_30 = F_244 ( V_67 , struct V_29 ,
V_65 . V_67 ) ;
if ( F_287 ( V_30 ) )
F_281 ( V_30 ) ;
}
static void F_289 ( struct V_14 * V_15 )
{
int V_92 ;
F_290 ( V_66 ) ;
struct V_478 V_479 ;
struct V_485 * V_486 = F_291 ( V_487 ,
& V_66 , L_28 , V_15 -> V_297 ) ;
if ( F_107 ( V_486 ) ) {
F_163 ( V_15 -> V_15 ,
L_29 ) ;
for ( V_92 = V_15 -> V_287 - 1 ; V_92 > 0 ; V_92 -- )
F_145 ( V_15 , V_92 ) ;
return;
}
V_479 . V_480 = NULL ;
F_292 ( & V_479 . V_482 , 0 ) ;
V_479 . V_66 = & V_66 ;
for ( V_92 = V_15 -> V_287 - 1 ; V_92 > 0 ; V_92 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_92 ] ;
if ( F_139 ( V_30 ) )
continue;
V_30 -> V_65 . V_41 = F_279 ( & V_479 ) ;
V_30 -> V_65 . V_66 = V_479 . V_66 ;
F_283 ( & V_30 -> V_65 . V_67 , F_288 ) ;
F_31 ( V_479 . V_66 , & V_30 -> V_65 . V_67 ) ;
}
F_273 ( & V_479 , V_15 ) ;
F_293 ( V_486 ) ;
}
static void F_294 ( struct V_14 * V_15 )
{
struct V_485 * V_488 = NULL ;
F_102 ( & V_275 ) ;
F_128 ( & V_15 -> V_277 ) ;
if ( F_295 ( & V_489 ) && ! F_296 ( V_490 ) ) {
V_488 = V_490 ;
V_490 = NULL ;
}
F_103 ( & V_275 ) ;
if ( V_488 )
F_293 ( V_488 ) ;
}
static void F_297 ( struct V_14 * V_15 )
{
struct V_108 * V_109 ;
F_246 (ns, &dev->namespaces, list) {
F_140 ( V_109 -> V_138 ) ;
F_97 ( V_109 -> V_138 -> V_145 ) ;
F_298 ( V_491 , V_109 -> V_138 ) ;
F_99 ( V_109 -> V_138 -> V_145 ) ;
F_299 ( V_109 -> V_138 ) ;
F_300 ( V_109 -> V_138 ) ;
}
}
static void F_301 ( struct V_14 * V_15 )
{
struct V_108 * V_109 ;
F_246 (ns, &dev->namespaces, list) {
F_302 ( V_491 , V_109 -> V_138 ) ;
F_175 ( V_109 -> V_138 ) ;
F_303 ( V_109 -> V_138 , true ) ;
F_74 ( V_109 -> V_138 ) ;
}
}
static void F_304 ( struct V_14 * V_15 )
{
int V_92 ;
T_2 V_292 = - 1 ;
F_294 ( V_15 ) ;
if ( V_15 -> V_291 ) {
F_297 ( V_15 ) ;
V_292 = F_146 ( & V_15 -> V_291 -> V_292 ) ;
}
if ( V_292 & V_412 || ! ( V_292 & V_307 ) ) {
for ( V_92 = V_15 -> V_287 - 1 ; V_92 >= 0 ; V_92 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_92 ] ;
F_139 ( V_30 ) ;
}
} else {
F_289 ( V_15 ) ;
F_166 ( V_15 ) ;
F_145 ( V_15 , 0 ) ;
}
F_270 ( V_15 ) ;
for ( V_92 = V_15 -> V_287 - 1 ; V_92 >= 0 ; V_92 -- )
F_143 ( V_15 -> V_31 [ V_92 ] ) ;
}
static void F_305 ( struct V_14 * V_15 )
{
struct V_108 * V_109 ;
F_246 (ns, &dev->namespaces, list)
F_248 ( V_109 ) ;
}
static int F_306 ( struct V_14 * V_15 )
{
V_15 -> V_99 = F_307 ( L_30 , V_15 -> V_15 ,
V_18 , V_18 , 0 ) ;
if ( ! V_15 -> V_99 )
return - V_264 ;
V_15 -> V_96 = F_307 ( L_31 , V_15 -> V_15 ,
256 , 256 , 0 ) ;
if ( ! V_15 -> V_96 ) {
F_308 ( V_15 -> V_99 ) ;
return - V_264 ;
}
return 0 ;
}
static void F_309 ( struct V_14 * V_15 )
{
F_308 ( V_15 -> V_99 ) ;
F_308 ( V_15 -> V_96 ) ;
}
static int F_310 ( struct V_14 * V_15 )
{
int V_297 , error ;
do {
if ( ! F_311 ( & V_492 , V_224 ) )
return - V_310 ;
F_102 ( & V_275 ) ;
error = F_312 ( & V_492 , & V_297 ) ;
F_103 ( & V_275 ) ;
} while ( error == - V_493 );
if ( error )
return - V_310 ;
V_15 -> V_297 = V_297 ;
return 0 ;
}
static void F_313 ( struct V_14 * V_15 )
{
F_102 ( & V_275 ) ;
F_314 ( & V_492 , V_15 -> V_297 ) ;
F_103 ( & V_275 ) ;
}
static void F_315 ( struct V_14 * V_15 )
{
struct V_108 * V_109 , * V_410 ;
F_211 (ns, next, &dev->namespaces, list)
F_241 ( V_109 ) ;
}
static void V_382 ( struct V_380 * V_380 )
{
struct V_14 * V_15 = F_244 ( V_380 , struct V_14 , V_380 ) ;
F_316 ( V_15 -> V_15 ) ;
F_316 ( V_15 -> V_429 ) ;
F_315 ( V_15 ) ;
F_313 ( V_15 ) ;
if ( V_15 -> V_40 . V_33 )
F_169 ( & V_15 -> V_40 ) ;
if ( V_15 -> V_236 )
F_317 ( V_15 -> V_236 ) ;
F_50 ( V_15 -> V_31 ) ;
F_50 ( V_15 -> V_289 ) ;
F_50 ( V_15 ) ;
}
static int F_318 ( struct V_494 * V_494 , struct V_495 * V_496 )
{
struct V_14 * V_15 ;
int V_297 = F_319 ( V_494 ) ;
int V_19 = - V_310 ;
F_102 ( & V_275 ) ;
F_246 (dev, &dev_list, node) {
if ( V_15 -> V_297 == V_297 ) {
if ( ! V_15 -> V_236 ) {
V_19 = - V_497 ;
break;
}
if ( ! F_194 ( & V_15 -> V_380 ) )
break;
V_496 -> V_111 = V_15 ;
V_19 = 0 ;
break;
}
}
F_103 ( & V_275 ) ;
return V_19 ;
}
static int F_320 ( struct V_494 * V_494 , struct V_495 * V_496 )
{
struct V_14 * V_15 = V_496 -> V_111 ;
F_196 ( & V_15 -> V_380 , V_382 ) ;
return 0 ;
}
static long F_321 ( struct V_495 * V_496 , unsigned int V_39 , unsigned long V_369 )
{
struct V_14 * V_15 = V_496 -> V_111 ;
struct V_108 * V_109 ;
switch ( V_39 ) {
case V_372 :
return F_184 ( V_15 , NULL , ( void T_8 * ) V_369 ) ;
case V_373 :
if ( F_295 ( & V_15 -> V_418 ) )
return - V_377 ;
V_109 = F_322 ( & V_15 -> V_418 , struct V_108 , V_93 ) ;
return F_184 ( V_15 , V_109 , ( void T_8 * ) V_369 ) ;
case V_498 :
F_21 ( V_15 -> V_15 , L_32 ) ;
return F_323 ( V_15 ) ;
default:
return - V_377 ;
}
}
static void F_324 ( struct V_14 * V_15 )
{
struct V_29 * V_30 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_15 -> V_290 ; V_92 ++ ) {
V_30 = V_15 -> V_31 [ V_92 ] ;
if ( ! V_30 -> V_33 || ! ( * V_30 -> V_33 ) )
continue;
F_141 ( V_15 -> V_289 [ V_30 -> V_252 ] . V_288 ,
F_325 ( * V_30 -> V_33 ) ) ;
}
}
static int F_326 ( struct V_14 * V_15 )
{
int V_56 ;
bool V_499 = false ;
V_56 = F_258 ( V_15 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_176 ( V_15 ) ;
if ( V_56 )
goto V_349;
F_102 ( & V_275 ) ;
if ( F_295 ( & V_489 ) && F_296 ( V_490 ) ) {
V_499 = true ;
V_490 = NULL ;
}
F_327 ( & V_15 -> V_277 , & V_489 ) ;
F_103 ( & V_275 ) ;
if ( V_499 ) {
V_490 = F_291 ( F_208 , NULL , L_27 ) ;
F_328 ( & V_500 ) ;
} else
F_329 ( V_500 , V_490 ) ;
if ( F_296 ( V_490 ) ) {
V_56 = V_490 ? F_108 ( V_490 ) : - V_149 ;
goto V_474;
}
F_156 ( V_15 -> V_31 [ 0 ] , 0 ) ;
V_56 = F_170 ( V_15 ) ;
if ( V_56 )
goto V_474;
V_56 = F_232 ( V_15 ) ;
if ( V_56 )
goto V_501;
F_324 ( V_15 ) ;
V_15 -> V_60 = 1 ;
return V_56 ;
V_501:
F_167 ( V_15 ) ;
F_317 ( V_15 -> V_236 ) ;
V_15 -> V_236 = NULL ;
V_15 -> V_31 [ 0 ] -> V_33 = NULL ;
V_474:
F_145 ( V_15 , 0 ) ;
F_294 ( V_15 ) ;
V_349:
F_270 ( V_15 ) ;
return V_56 ;
}
static int F_330 ( void * V_369 )
{
struct V_14 * V_15 = (struct V_14 * ) V_369 ;
struct V_440 * V_441 = F_233 ( V_15 -> V_15 ) ;
if ( F_331 ( V_441 ) )
F_332 ( V_441 ) ;
F_196 ( & V_15 -> V_380 , V_382 ) ;
return 0 ;
}
static void F_333 ( struct V_452 * V_502 )
{
struct V_14 * V_15 = F_244 ( V_502 , struct V_14 , V_276 ) ;
F_138 ( V_15 , 1 ) ;
F_305 ( V_15 ) ;
}
static int F_334 ( struct V_14 * V_15 )
{
int V_19 ;
V_19 = F_326 ( V_15 ) ;
if ( V_19 )
return V_19 ;
if ( V_15 -> V_290 < 2 ) {
F_102 ( & V_275 ) ;
V_15 -> V_278 = F_333 ;
F_129 ( V_280 , & V_15 -> V_276 ) ;
F_103 ( & V_275 ) ;
} else {
F_301 ( V_15 ) ;
F_256 ( V_15 ) ;
F_324 ( V_15 ) ;
}
return 0 ;
}
static void F_335 ( struct V_14 * V_15 )
{
F_21 ( V_15 -> V_15 , L_33 ) ;
F_336 ( & V_15 -> V_380 ) ;
if ( F_107 ( F_291 ( F_330 , V_15 , L_28 ,
V_15 -> V_297 ) ) ) {
F_163 ( V_15 -> V_15 ,
L_34 ) ;
F_196 ( & V_15 -> V_380 , V_382 ) ;
}
}
static void F_337 ( struct V_14 * V_15 )
{
bool V_503 = F_127 ( & V_15 -> V_504 ) ;
F_304 ( V_15 ) ;
F_338 ( & V_15 -> V_504 ) ;
if ( V_503 ) {
F_335 ( V_15 ) ;
return;
}
F_27 ( & V_15 -> V_504 ) ;
}
static void V_279 ( struct V_452 * V_502 )
{
struct V_14 * V_15 = F_244 ( V_502 , struct V_14 , V_276 ) ;
F_337 ( V_15 ) ;
}
static void F_339 ( struct V_452 * V_67 )
{
struct V_14 * V_15 = F_244 ( V_67 , struct V_14 , V_276 ) ;
V_15 -> V_278 ( V_67 ) ;
}
static int F_323 ( struct V_14 * V_15 )
{
int V_19 = - V_505 ;
if ( ! V_15 -> V_236 || F_132 ( V_15 -> V_236 ) )
return - V_310 ;
F_102 ( & V_275 ) ;
if ( ! F_340 ( & V_15 -> V_276 ) ) {
V_15 -> V_278 = V_279 ;
F_129 ( V_280 , & V_15 -> V_276 ) ;
V_19 = 0 ;
}
F_103 ( & V_275 ) ;
if ( ! V_19 ) {
F_338 ( & V_15 -> V_276 ) ;
F_338 ( & V_15 -> V_504 ) ;
return 0 ;
}
return V_19 ;
}
static T_13 F_341 ( struct V_429 * V_15 ,
struct V_506 * V_507 , const char * V_508 ,
T_11 V_435 )
{
struct V_14 * V_509 = F_342 ( V_15 ) ;
int V_19 ;
V_19 = F_323 ( V_509 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_435 ;
}
static int F_343 ( struct V_440 * V_441 , const struct V_510 * V_240 )
{
int V_277 , V_56 = - V_264 ;
struct V_14 * V_15 ;
V_277 = F_171 ( & V_441 -> V_15 ) ;
if ( V_277 == V_511 )
F_344 ( & V_441 -> V_15 , 0 ) ;
V_15 = F_215 ( sizeof( * V_15 ) , V_224 , V_277 ) ;
if ( ! V_15 )
return - V_264 ;
V_15 -> V_289 = F_215 ( F_234 () * sizeof( * V_15 -> V_289 ) ,
V_224 , V_277 ) ;
if ( ! V_15 -> V_289 )
goto free;
V_15 -> V_31 = F_215 ( ( F_234 () + 1 ) * sizeof( void * ) ,
V_224 , V_277 ) ;
if ( ! V_15 -> V_31 )
goto free;
F_345 ( & V_15 -> V_418 ) ;
V_15 -> V_278 = V_279 ;
F_346 ( & V_15 -> V_276 , F_339 ) ;
V_15 -> V_15 = F_347 ( & V_441 -> V_15 ) ;
F_348 ( V_441 , V_15 ) ;
V_56 = F_310 ( V_15 ) ;
if ( V_56 )
goto V_512;
V_56 = F_306 ( V_15 ) ;
if ( V_56 )
goto V_513;
F_349 ( & V_15 -> V_380 ) ;
V_15 -> V_429 = F_350 ( V_514 , & V_441 -> V_15 ,
F_351 ( V_515 , V_15 -> V_297 ) ,
V_15 , L_28 , V_15 -> V_297 ) ;
if ( F_107 ( V_15 -> V_429 ) ) {
V_56 = F_108 ( V_15 -> V_429 ) ;
goto V_516;
}
F_347 ( V_15 -> V_429 ) ;
F_352 ( V_15 -> V_429 , V_15 ) ;
V_56 = F_353 ( V_15 -> V_429 , & V_517 ) ;
if ( V_56 )
goto V_518;
F_345 ( & V_15 -> V_277 ) ;
F_346 ( & V_15 -> V_62 , F_255 ) ;
F_346 ( & V_15 -> V_504 , V_519 ) ;
F_27 ( & V_15 -> V_504 ) ;
return 0 ;
V_518:
F_354 ( V_514 , F_351 ( V_515 , V_15 -> V_297 ) ) ;
F_316 ( V_15 -> V_429 ) ;
V_516:
F_309 ( V_15 ) ;
V_513:
F_313 ( V_15 ) ;
V_512:
F_316 ( V_15 -> V_15 ) ;
free:
F_50 ( V_15 -> V_31 ) ;
F_50 ( V_15 -> V_289 ) ;
F_50 ( V_15 ) ;
return V_56 ;
}
static void V_519 ( struct V_452 * V_67 )
{
struct V_14 * V_15 = F_244 ( V_67 , struct V_14 , V_504 ) ;
if ( F_334 ( V_15 ) && ! F_127 ( & V_15 -> V_276 ) )
F_335 ( V_15 ) ;
}
static void F_355 ( struct V_440 * V_441 , bool V_520 )
{
struct V_14 * V_15 = F_331 ( V_441 ) ;
if ( V_520 )
F_304 ( V_15 ) ;
else
F_334 ( V_15 ) ;
}
static void F_356 ( struct V_440 * V_441 )
{
struct V_14 * V_15 = F_331 ( V_441 ) ;
F_304 ( V_15 ) ;
}
static void F_357 ( struct V_440 * V_441 )
{
struct V_14 * V_15 = F_331 ( V_441 ) ;
F_102 ( & V_275 ) ;
F_128 ( & V_15 -> V_277 ) ;
F_103 ( & V_275 ) ;
F_348 ( V_441 , NULL ) ;
F_338 ( & V_15 -> V_504 ) ;
F_338 ( & V_15 -> V_276 ) ;
F_338 ( & V_15 -> V_62 ) ;
F_358 ( V_15 -> V_429 , & V_517 ) ;
F_305 ( V_15 ) ;
F_304 ( V_15 ) ;
F_167 ( V_15 ) ;
F_354 ( V_514 , F_351 ( V_515 , V_15 -> V_297 ) ) ;
F_138 ( V_15 , 0 ) ;
F_309 ( V_15 ) ;
F_196 ( & V_15 -> V_380 , V_382 ) ;
}
static int F_359 ( struct V_429 * V_15 )
{
struct V_440 * V_441 = F_233 ( V_15 ) ;
struct V_14 * V_509 = F_331 ( V_441 ) ;
F_304 ( V_509 ) ;
return 0 ;
}
static int F_360 ( struct V_429 * V_15 )
{
struct V_440 * V_441 = F_233 ( V_15 ) ;
struct V_14 * V_509 = F_331 ( V_441 ) ;
if ( F_334 ( V_509 ) && ! F_127 ( & V_509 -> V_276 ) ) {
V_509 -> V_278 = V_279 ;
F_129 ( V_280 , & V_509 -> V_276 ) ;
}
return 0 ;
}
static int T_14 F_361 ( void )
{
int V_56 ;
F_362 ( & V_500 ) ;
V_280 = F_363 ( L_27 ) ;
if ( ! V_280 )
return - V_264 ;
V_56 = F_364 ( V_424 , L_27 ) ;
if ( V_56 < 0 )
goto V_521;
else if ( V_56 > 0 )
V_424 = V_56 ;
V_56 = F_365 ( V_515 , 0 , V_522 , L_27 ,
& V_523 ) ;
if ( V_56 < 0 )
goto V_524;
else if ( V_56 > 0 )
V_515 = V_56 ;
V_514 = F_366 ( V_525 , L_27 ) ;
if ( F_107 ( V_514 ) ) {
V_56 = F_108 ( V_514 ) ;
goto V_526;
}
V_56 = F_367 ( & V_527 ) ;
if ( V_56 )
goto V_528;
return 0 ;
V_528:
F_368 ( V_514 ) ;
V_526:
F_369 ( V_515 , 0 , V_522 , L_27 ) ;
V_524:
V_524 ( V_424 , L_27 ) ;
V_521:
F_370 ( V_280 ) ;
return V_56 ;
}
static void T_15 F_371 ( void )
{
F_372 ( & V_527 ) ;
V_524 ( V_424 , L_27 ) ;
F_370 ( V_280 ) ;
F_368 ( V_514 ) ;
F_369 ( V_515 , 0 , V_522 , L_27 ) ;
F_12 ( V_490 && ! F_107 ( V_490 ) ) ;
F_1 () ;
}
