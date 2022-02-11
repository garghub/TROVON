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
return ( V_44 -> V_45 & 0x01 ) == 0 ;
}
static void F_20 ( struct V_29 * V_30 , void * V_40 ,
struct V_46 * V_47 )
{
if ( V_40 == V_48 )
return;
if ( V_40 == V_49 ) {
F_21 ( V_30 -> V_50 ,
L_1 ,
V_47 -> V_51 , F_22 ( & V_47 -> V_52 ) ) ;
return;
}
if ( V_40 == V_53 ) {
F_21 ( V_30 -> V_50 ,
L_2 ,
V_47 -> V_51 , F_22 ( & V_47 -> V_52 ) ) ;
return;
}
F_21 ( V_30 -> V_50 , L_3 , V_40 ) ;
}
static void * F_23 ( struct V_20 * V_37 , T_1 * V_42 )
{
void * V_40 ;
if ( V_42 )
* V_42 = V_37 -> V_42 ;
V_40 = V_37 -> V_40 ;
V_37 -> V_42 = F_20 ;
V_37 -> V_40 = V_48 ;
return V_40 ;
}
static void F_24 ( struct V_29 * V_30 , void * V_40 ,
struct V_46 * V_47 )
{
struct V_33 * V_34 = V_40 ;
T_2 V_54 = F_25 ( & V_47 -> V_54 ) ;
T_3 V_55 = F_22 ( & V_47 -> V_55 ) >> 1 ;
if ( V_55 == V_56 || V_55 == V_57 )
++ V_30 -> V_15 -> V_58 ;
if ( V_55 == V_56 )
F_21 ( V_30 -> V_50 ,
L_4 , V_54 ) ;
F_26 ( V_30 -> V_26 , V_34 ) ;
}
static void F_27 ( struct V_29 * V_30 , void * V_40 ,
struct V_46 * V_47 )
{
struct V_33 * V_34 = V_40 ;
T_3 V_55 = F_22 ( & V_47 -> V_55 ) >> 1 ;
T_2 V_54 = F_25 ( & V_47 -> V_54 ) ;
F_26 ( V_30 -> V_26 , V_34 ) ;
F_21 ( V_30 -> V_50 , L_5 , V_55 , V_54 ) ;
++ V_30 -> V_15 -> V_59 ;
}
static void F_28 ( struct V_29 * V_30 , void * V_40 ,
struct V_46 * V_47 )
{
struct V_60 * V_61 = V_40 ;
V_61 -> V_54 = F_25 ( & V_47 -> V_54 ) ;
V_61 -> V_55 = F_22 ( & V_47 -> V_55 ) >> 1 ;
F_29 ( V_61 -> V_62 , & V_61 -> V_63 ) ;
F_26 ( V_30 -> V_26 , V_61 -> V_34 ) ;
}
static inline struct V_20 * F_30 ( struct V_29 * V_30 ,
unsigned int V_64 )
{
struct V_25 * V_26 = V_30 -> V_26 ;
struct V_33 * V_34 = F_31 ( V_26 -> V_39 , V_64 ) ;
return F_10 ( V_34 ) ;
}
static void * F_32 ( struct V_29 * V_30 , int V_64 ,
T_1 * V_42 )
{
struct V_20 * V_37 = F_30 ( V_30 , V_64 ) ;
void * V_40 ;
if ( V_64 >= V_30 -> V_65 ) {
* V_42 = F_20 ;
return V_53 ;
}
if ( V_42 )
* V_42 = V_37 -> V_42 ;
V_40 = V_37 -> V_40 ;
V_37 -> V_42 = F_20 ;
V_37 -> V_40 = V_49 ;
return V_40 ;
}
static int F_33 ( struct V_29 * V_30 , struct V_8 * V_37 )
{
T_3 V_66 = V_30 -> V_67 ;
memcpy ( & V_30 -> V_68 [ V_66 ] , V_37 , sizeof( * V_37 ) ) ;
if ( ++ V_66 == V_30 -> V_65 )
V_66 = 0 ;
F_34 ( V_66 , V_30 -> V_69 ) ;
V_30 -> V_67 = V_66 ;
return 0 ;
}
static int F_35 ( struct V_29 * V_30 , struct V_8 * V_37 )
{
unsigned long V_70 ;
int V_19 ;
F_36 ( & V_30 -> V_71 , V_70 ) ;
V_19 = F_33 ( V_30 , V_37 ) ;
F_37 ( & V_30 -> V_71 , V_70 ) ;
return V_19 ;
}
static V_22 * * F_38 ( struct V_21 * V_44 )
{
return ( ( void * ) V_44 ) + V_44 -> V_72 ;
}
static inline void F_39 ( struct V_21 * V_44 , unsigned V_73 ,
unsigned V_74 , unsigned long V_45 )
{
V_44 -> V_45 = V_45 ;
V_44 -> V_72 = F_40 ( struct V_21 , V_75 [ V_74 ] ) ;
V_44 -> V_76 = - 1 ;
V_44 -> V_77 = V_73 ;
V_44 -> V_78 = 0 ;
}
static struct V_21 *
F_41 ( unsigned V_74 , unsigned V_79 , struct V_14 * V_15 ,
unsigned long V_80 , T_4 V_81 )
{
struct V_21 * V_44 = F_42 ( sizeof( struct V_21 ) +
sizeof( V_22 * ) * F_3 ( V_79 , V_15 ) +
sizeof( struct V_23 ) * V_74 , V_81 ) ;
if ( V_44 )
F_39 ( V_44 , V_79 , V_74 , V_80 ) ;
return V_44 ;
}
static struct V_21 * F_43 ( struct V_33 * V_82 , struct V_14 * V_15 ,
T_4 V_81 )
{
unsigned V_13 = ! ( V_82 -> V_83 & V_84 ) ? F_44 ( V_82 ) :
sizeof( struct V_85 ) ;
unsigned long V_86 = 0 ;
struct V_21 * V_44 ;
if ( V_82 -> V_87 <= V_24 &&
V_13 <= F_6 ( V_15 ) ) {
struct V_20 * V_37 = F_10 ( V_82 ) ;
V_44 = V_37 -> V_44 ;
V_86 = 0x01 ;
F_39 ( V_44 , V_13 , V_82 -> V_87 ,
( unsigned long ) V_82 | 0x01 ) ;
return V_44 ;
}
return F_41 ( V_82 -> V_87 , V_13 , V_15 ,
( unsigned long ) V_82 , V_81 ) ;
}
void F_45 ( struct V_14 * V_15 , struct V_21 * V_44 )
{
const int V_88 = V_15 -> V_17 / 8 - 1 ;
int V_89 ;
V_22 * * V_90 = F_38 ( V_44 ) ;
T_5 V_91 = V_44 -> V_92 ;
if ( V_44 -> V_76 == 0 )
F_46 ( V_15 -> V_93 , V_90 [ 0 ] , V_91 ) ;
for ( V_89 = 0 ; V_89 < V_44 -> V_76 ; V_89 ++ ) {
V_22 * V_94 = V_90 [ V_89 ] ;
T_5 V_95 = F_47 ( V_94 [ V_88 ] ) ;
F_46 ( V_15 -> V_96 , V_94 , V_91 ) ;
V_91 = V_95 ;
}
if ( F_19 ( V_44 ) )
F_48 ( V_44 ) ;
}
static int F_49 ( T_3 V_55 )
{
switch ( V_55 & 0x7ff ) {
case V_56 :
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
if ( ! V_111 )
return;
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
struct V_46 * V_47 )
{
struct V_21 * V_44 = V_40 ;
struct V_33 * V_34 = F_18 ( V_44 ) ;
struct V_20 * V_136 = F_10 ( V_34 ) ;
T_3 V_55 = F_22 ( & V_47 -> V_55 ) >> 1 ;
if ( F_68 ( V_55 ) ) {
if ( ! ( V_55 & V_137 || F_69 ( V_34 ) )
&& ( V_138 - V_34 -> V_139 ) < V_34 -> V_140 ) {
unsigned long V_70 ;
F_70 ( V_34 ) ;
F_36 ( V_34 -> V_141 -> V_142 , V_70 ) ;
if ( ! F_71 ( V_34 -> V_141 ) )
F_72 ( V_34 -> V_141 ) ;
F_37 ( V_34 -> V_141 -> V_142 , V_70 ) ;
return;
}
V_34 -> V_143 = F_49 ( V_55 ) ;
} else
V_34 -> V_143 = 0 ;
if ( V_136 -> V_43 )
F_21 ( & V_30 -> V_15 -> V_144 -> V_15 ,
L_6 ,
V_55 ) ;
if ( V_44 -> V_78 ) {
F_73 ( & V_30 -> V_15 -> V_144 -> V_15 , V_44 -> V_75 , V_44 -> V_78 ,
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
T_4 V_81 )
{
struct V_149 * V_150 ;
int V_77 = V_148 ;
struct V_23 * V_75 = V_44 -> V_75 ;
int V_151 = F_78 ( V_75 ) ;
T_6 V_152 = F_79 ( V_75 ) ;
int V_72 = F_80 ( V_152 ) ;
V_22 * V_94 ;
V_22 * * V_90 = F_38 ( V_44 ) ;
T_5 V_91 ;
int V_16 , V_89 ;
T_2 V_17 = V_15 -> V_17 ;
V_77 -= ( V_17 - V_72 ) ;
if ( V_77 <= 0 )
return V_148 ;
V_151 -= ( V_17 - V_72 ) ;
if ( V_151 ) {
V_152 += ( V_17 - V_72 ) ;
} else {
V_75 = F_81 ( V_75 ) ;
V_152 = F_79 ( V_75 ) ;
V_151 = F_78 ( V_75 ) ;
}
if ( V_77 <= V_17 ) {
V_44 -> V_92 = V_152 ;
return V_148 ;
}
V_16 = F_4 ( V_77 , V_17 ) ;
if ( V_16 <= ( 256 / 8 ) ) {
V_150 = V_15 -> V_93 ;
V_44 -> V_76 = 0 ;
} else {
V_150 = V_15 -> V_96 ;
V_44 -> V_76 = 1 ;
}
V_94 = F_82 ( V_150 , V_81 , & V_91 ) ;
if ( ! V_94 ) {
V_44 -> V_92 = V_152 ;
V_44 -> V_76 = - 1 ;
return ( V_148 - V_77 ) + V_17 ;
}
V_90 [ 0 ] = V_94 ;
V_44 -> V_92 = V_91 ;
V_89 = 0 ;
for (; ; ) {
if ( V_89 == V_17 >> 3 ) {
V_22 * V_153 = V_94 ;
V_94 = F_82 ( V_150 , V_81 , & V_91 ) ;
if ( ! V_94 )
return V_148 - V_77 ;
V_90 [ V_44 -> V_76 ++ ] = V_94 ;
V_94 [ 0 ] = V_153 [ V_89 - 1 ] ;
V_153 [ V_89 - 1 ] = F_83 ( V_91 ) ;
V_89 = 1 ;
}
V_94 [ V_89 ++ ] = F_83 ( V_152 ) ;
V_151 -= V_17 ;
V_152 += V_17 ;
V_77 -= V_17 ;
if ( V_77 <= 0 )
break;
if ( V_151 > 0 )
continue;
F_11 ( V_151 < 0 ) ;
V_75 = F_81 ( V_75 ) ;
V_152 = F_79 ( V_75 ) ;
V_151 = F_78 ( V_75 ) ;
}
return V_148 ;
}
static void F_84 ( struct V_29 * V_30 , struct V_105 * V_106 ,
struct V_33 * V_34 , struct V_21 * V_44 )
{
struct V_85 * V_154 =
(struct V_85 * ) F_38 ( V_44 ) [ 0 ] ;
struct V_8 * V_155 = & V_30 -> V_68 [ V_30 -> V_67 ] ;
V_154 -> V_156 = F_85 ( 0 ) ;
V_154 -> V_112 = F_85 ( F_44 ( V_34 ) >> V_106 -> V_122 ) ;
V_154 -> V_157 = F_83 ( F_59 ( V_106 , F_60 ( V_34 ) ) ) ;
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_158 . V_159 = V_160 ;
V_155 -> V_158 . V_51 = V_34 -> V_64 ;
V_155 -> V_158 . V_161 = F_85 ( V_106 -> V_162 ) ;
V_155 -> V_158 . V_163 = F_83 ( V_44 -> V_92 ) ;
V_155 -> V_158 . V_164 = 0 ;
V_155 -> V_158 . V_165 = F_85 ( V_166 ) ;
if ( ++ V_30 -> V_67 == V_30 -> V_65 )
V_30 -> V_67 = 0 ;
F_34 ( V_30 -> V_67 , V_30 -> V_69 ) ;
}
static void F_86 ( struct V_29 * V_30 , struct V_105 * V_106 ,
int V_167 )
{
struct V_8 * V_155 = & V_30 -> V_68 [ V_30 -> V_67 ] ;
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_168 . V_159 = V_169 ;
V_155 -> V_168 . V_51 = V_167 ;
V_155 -> V_168 . V_161 = F_85 ( V_106 -> V_162 ) ;
if ( ++ V_30 -> V_67 == V_30 -> V_65 )
V_30 -> V_67 = 0 ;
F_34 ( V_30 -> V_67 , V_30 -> V_69 ) ;
}
static int F_87 ( struct V_29 * V_30 , struct V_21 * V_44 ,
struct V_105 * V_106 )
{
struct V_33 * V_34 = F_18 ( V_44 ) ;
struct V_8 * V_155 ;
T_3 V_170 = 0 ;
T_2 V_171 = 0 ;
if ( V_34 -> V_83 & V_172 )
V_170 |= V_173 ;
if ( V_34 -> V_83 & ( V_174 | V_175 ) )
V_170 |= V_176 ;
if ( V_34 -> V_83 & V_175 )
V_171 |= V_177 ;
V_155 = & V_30 -> V_68 [ V_30 -> V_67 ] ;
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_178 . V_159 = ( F_74 ( V_34 ) ? V_179 : V_180 ) ;
V_155 -> V_178 . V_51 = V_34 -> V_64 ;
V_155 -> V_178 . V_161 = F_85 ( V_106 -> V_162 ) ;
V_155 -> V_178 . V_163 = F_83 ( F_79 ( V_44 -> V_75 ) ) ;
V_155 -> V_178 . V_181 = F_83 ( V_44 -> V_92 ) ;
V_155 -> V_178 . V_157 = F_83 ( F_59 ( V_106 , F_60 ( V_34 ) ) ) ;
V_155 -> V_178 . V_77 = F_88 ( ( F_44 ( V_34 ) >> V_106 -> V_122 ) - 1 ) ;
if ( F_75 ( V_34 ) ) {
V_155 -> V_178 . V_182 = F_83 ( F_79 ( V_44 -> V_147 ) ) ;
switch ( V_106 -> V_116 ) {
case V_117 :
V_170 |= V_183 ;
break;
case V_130 :
case V_131 :
V_170 |= V_183 |
V_184 ;
V_155 -> V_178 . V_185 = F_85 (
F_59 ( V_106 , F_60 ( V_34 ) ) ) ;
break;
}
} else if ( V_106 -> V_134 )
V_170 |= V_186 ;
V_155 -> V_178 . V_170 = F_88 ( V_170 ) ;
V_155 -> V_178 . V_171 = F_85 ( V_171 ) ;
if ( ++ V_30 -> V_67 == V_30 -> V_65 )
V_30 -> V_67 = 0 ;
F_34 ( V_30 -> V_67 , V_30 -> V_69 ) ;
return 0 ;
}
static int F_89 ( struct V_25 * V_26 ,
const struct V_187 * V_188 )
{
struct V_105 * V_106 = V_26 -> V_135 -> V_189 ;
struct V_29 * V_30 = V_26 -> V_32 ;
struct V_33 * V_34 = V_188 -> V_82 ;
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
if ( V_34 -> V_83 & V_84 ) {
void * V_154 ;
V_154 = F_82 ( V_30 -> V_15 -> V_93 ,
V_194 ,
& V_44 -> V_92 ) ;
if ( ! V_154 )
goto V_196;
F_38 ( V_44 ) [ 0 ] = ( V_22 * ) V_154 ;
V_44 -> V_76 = 0 ;
} else if ( V_34 -> V_87 ) {
V_191 = F_74 ( V_34 ) ? V_145 : V_146 ;
F_90 ( V_44 -> V_75 , V_34 -> V_87 ) ;
V_44 -> V_78 = F_91 ( V_34 -> V_141 , V_34 , V_44 -> V_75 ) ;
if ( ! V_44 -> V_78 )
goto V_197;
if ( ! F_92 ( V_30 -> V_50 , V_44 -> V_75 , V_44 -> V_78 , V_191 ) )
goto V_196;
if ( F_44 ( V_34 ) !=
F_77 ( V_30 -> V_15 , V_44 , F_44 ( V_34 ) , V_194 ) ) {
F_73 ( & V_30 -> V_15 -> V_144 -> V_15 , V_44 -> V_75 ,
V_44 -> V_78 , V_191 ) ;
goto V_196;
}
if ( F_75 ( V_34 ) ) {
if ( F_93 ( V_34 -> V_141 , V_34 -> V_118 ) != 1 )
goto V_197;
F_90 ( V_44 -> V_147 , 1 ) ;
if ( F_94 (
V_34 -> V_141 , V_34 -> V_118 , V_44 -> V_147 ) != 1 )
goto V_197;
if ( F_74 ( V_34 ) )
F_54 ( V_34 , F_50 ) ;
if ( ! F_92 ( V_30 -> V_50 , V_44 -> V_147 , 1 , V_191 ) )
goto V_197;
}
}
F_15 ( V_37 , V_44 , F_67 ) ;
F_95 ( & V_30 -> V_71 ) ;
if ( V_34 -> V_83 & V_84 )
F_84 ( V_30 , V_106 , V_34 , V_44 ) ;
else if ( V_34 -> V_83 & V_198 )
F_86 ( V_30 , V_106 , V_34 -> V_64 ) ;
else
F_87 ( V_30 , V_44 , V_106 ) ;
F_96 ( V_30 ) ;
F_97 ( & V_30 -> V_71 ) ;
return V_193 ;
V_197:
F_45 ( V_30 -> V_15 , V_44 ) ;
return V_199 ;
V_196:
F_45 ( V_30 -> V_15 , V_44 ) ;
return V_195 ;
}
static int F_96 ( struct V_29 * V_30 )
{
T_3 V_200 , V_201 ;
V_200 = V_30 -> V_202 ;
V_201 = V_30 -> V_203 ;
for (; ; ) {
void * V_40 ;
T_1 V_42 ;
struct V_46 V_47 = V_30 -> V_204 [ V_200 ] ;
if ( ( F_98 ( V_47 . V_55 ) & 1 ) != V_201 )
break;
V_30 -> V_205 = F_98 ( V_47 . V_205 ) ;
if ( ++ V_200 == V_30 -> V_65 ) {
V_200 = 0 ;
V_201 = ! V_201 ;
}
V_40 = F_32 ( V_30 , V_47 . V_51 , & V_42 ) ;
V_42 ( V_30 , V_40 , & V_47 ) ;
}
if ( V_200 == V_30 -> V_202 && V_201 == V_30 -> V_203 )
return 0 ;
F_34 ( V_200 , V_30 -> V_69 + V_30 -> V_15 -> V_206 ) ;
V_30 -> V_202 = V_200 ;
V_30 -> V_203 = V_201 ;
V_30 -> V_207 = 1 ;
return 1 ;
}
static int F_99 ( struct V_25 * V_26 ,
const struct V_187 * V_188 )
{
F_100 ( 1 ) ;
return V_199 ;
}
static T_7 F_101 ( int V_208 , void * V_27 )
{
T_7 V_54 ;
struct V_29 * V_30 = V_27 ;
F_102 ( & V_30 -> V_71 ) ;
F_96 ( V_30 ) ;
V_54 = V_30 -> V_207 ? V_209 : V_210 ;
V_30 -> V_207 = 0 ;
F_103 ( & V_30 -> V_71 ) ;
return V_54 ;
}
static T_7 F_104 ( int V_208 , void * V_27 )
{
struct V_29 * V_30 = V_27 ;
struct V_46 V_47 = V_30 -> V_204 [ V_30 -> V_202 ] ;
if ( ( F_98 ( V_47 . V_55 ) & 1 ) != V_30 -> V_203 )
return V_210 ;
return V_211 ;
}
static void F_105 ( struct V_29 * V_30 , void * V_40 ,
struct V_46 * V_47 )
{
struct V_212 * V_61 = V_40 ;
V_61 -> V_54 = F_25 ( & V_47 -> V_54 ) ;
V_61 -> V_55 = F_22 ( & V_47 -> V_55 ) >> 1 ;
F_106 ( V_61 -> V_213 ) ;
}
static int F_107 ( struct V_33 * V_34 , struct V_8 * V_37 ,
T_2 * V_54 , unsigned V_140 )
{
struct V_212 V_61 ;
struct V_20 * V_136 = F_10 ( V_34 ) ;
struct V_29 * V_30 = V_136 -> V_30 ;
V_61 . V_213 = V_214 ;
V_61 . V_55 = - V_215 ;
V_37 -> V_168 . V_51 = V_34 -> V_64 ;
F_15 ( V_136 , & V_61 , F_105 ) ;
F_108 ( V_216 ) ;
F_35 ( V_30 , V_37 ) ;
F_109 () ;
if ( V_54 )
* V_54 = V_61 . V_54 ;
return V_61 . V_55 ;
}
static int F_110 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
struct V_8 V_217 ;
struct V_20 * V_218 ;
struct V_33 * V_34 ;
V_34 = F_111 ( V_15 -> V_219 , V_220 , V_194 , false ) ;
if ( F_112 ( V_34 ) )
return F_113 ( V_34 ) ;
V_34 -> V_83 |= V_221 ;
V_218 = F_10 ( V_34 ) ;
F_15 ( V_218 , V_34 , F_24 ) ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_168 . V_159 = V_222 ;
V_217 . V_168 . V_51 = V_34 -> V_64 ;
return F_33 ( V_30 , & V_217 ) ;
}
static int F_114 ( struct V_14 * V_15 ,
struct V_8 * V_37 ,
struct V_60 * V_61 , unsigned V_140 )
{
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
struct V_33 * V_34 ;
struct V_20 * V_136 ;
V_34 = F_111 ( V_15 -> V_219 , V_220 , V_223 , false ) ;
if ( F_112 ( V_34 ) )
return F_113 ( V_34 ) ;
V_34 -> V_140 = V_140 ;
V_136 = F_10 ( V_34 ) ;
V_61 -> V_34 = V_34 ;
F_15 ( V_136 , V_61 , F_28 ) ;
V_61 -> V_55 = - V_215 ;
V_37 -> V_168 . V_51 = V_34 -> V_64 ;
return F_35 ( V_30 , V_37 ) ;
}
static int F_115 ( struct V_14 * V_15 , struct V_8 * V_37 ,
T_2 * V_54 , unsigned V_140 )
{
int V_224 ;
struct V_33 * V_34 ;
V_34 = F_111 ( V_15 -> V_219 , V_220 , V_223 , false ) ;
if ( F_112 ( V_34 ) )
return F_113 ( V_34 ) ;
V_224 = F_107 ( V_34 , V_37 , V_54 , V_140 ) ;
F_116 ( V_34 ) ;
return V_224 ;
}
int F_117 ( struct V_14 * V_15 , struct V_8 * V_37 ,
T_2 * V_54 )
{
return F_115 ( V_15 , V_37 , V_54 , V_225 ) ;
}
int F_118 ( struct V_14 * V_15 , struct V_105 * V_106 ,
struct V_8 * V_37 , T_2 * V_54 )
{
int V_224 ;
struct V_33 * V_34 ;
V_34 = F_111 ( V_106 -> V_135 , V_220 , ( V_223 | V_226 ) ,
false ) ;
if ( F_112 ( V_34 ) )
return F_113 ( V_34 ) ;
V_224 = F_107 ( V_34 , V_37 , V_54 , V_227 ) ;
F_116 ( V_34 ) ;
return V_224 ;
}
static int F_119 ( struct V_14 * V_15 , T_8 V_159 , T_3 V_228 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_229 . V_159 = V_159 ;
V_217 . V_229 . V_230 = F_88 ( V_228 ) ;
return F_117 ( V_15 , & V_217 , NULL ) ;
}
static int F_120 ( struct V_14 * V_15 , T_3 V_230 ,
struct V_29 * V_30 )
{
struct V_8 V_217 ;
int V_70 = V_231 | V_232 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_233 . V_159 = V_234 ;
V_217 . V_233 . V_163 = F_83 ( V_30 -> V_235 ) ;
V_217 . V_233 . V_236 = F_88 ( V_230 ) ;
V_217 . V_233 . V_237 = F_88 ( V_30 -> V_65 - 1 ) ;
V_217 . V_233 . V_238 = F_88 ( V_70 ) ;
V_217 . V_233 . V_239 = F_88 ( V_30 -> V_240 ) ;
return F_117 ( V_15 , & V_217 , NULL ) ;
}
static int F_121 ( struct V_14 * V_15 , T_3 V_230 ,
struct V_29 * V_30 )
{
struct V_8 V_217 ;
int V_70 = V_231 | V_241 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_242 . V_159 = V_243 ;
V_217 . V_242 . V_163 = F_83 ( V_30 -> V_244 ) ;
V_217 . V_242 . V_245 = F_88 ( V_230 ) ;
V_217 . V_242 . V_237 = F_88 ( V_30 -> V_65 - 1 ) ;
V_217 . V_242 . V_246 = F_88 ( V_70 ) ;
V_217 . V_242 . V_236 = F_88 ( V_230 ) ;
return F_117 ( V_15 , & V_217 , NULL ) ;
}
static int F_122 ( struct V_14 * V_15 , T_3 V_236 )
{
return F_119 ( V_15 , V_247 , V_236 ) ;
}
static int F_123 ( struct V_14 * V_15 , T_3 V_245 )
{
return F_119 ( V_15 , V_248 , V_245 ) ;
}
int F_124 ( struct V_14 * V_15 , unsigned V_161 , unsigned V_249 ,
T_5 V_152 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_250 . V_159 = V_251 ;
V_217 . V_250 . V_161 = F_85 ( V_161 ) ;
V_217 . V_250 . V_163 = F_83 ( V_152 ) ;
V_217 . V_250 . V_249 = F_85 ( V_249 ) ;
return F_117 ( V_15 , & V_217 , NULL ) ;
}
int F_125 ( struct V_14 * V_15 , unsigned V_252 , unsigned V_161 ,
T_5 V_152 , T_2 * V_54 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_253 . V_159 = V_254 ;
V_217 . V_253 . V_161 = F_85 ( V_161 ) ;
V_217 . V_253 . V_163 = F_83 ( V_152 ) ;
V_217 . V_253 . V_252 = F_85 ( V_252 ) ;
return F_117 ( V_15 , & V_217 , V_54 ) ;
}
int F_126 ( struct V_14 * V_15 , unsigned V_252 , unsigned V_255 ,
T_5 V_152 , T_2 * V_54 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_253 . V_159 = V_256 ;
V_217 . V_253 . V_163 = F_83 ( V_152 ) ;
V_217 . V_253 . V_252 = F_85 ( V_252 ) ;
V_217 . V_253 . V_255 = F_85 ( V_255 ) ;
return F_117 ( V_15 , & V_217 , V_54 ) ;
}
static void F_127 ( struct V_33 * V_34 )
{
struct V_20 * V_136 = F_10 ( V_34 ) ;
struct V_29 * V_30 = V_136 -> V_30 ;
struct V_14 * V_15 = V_30 -> V_15 ;
struct V_33 * V_257 ;
struct V_20 * V_258 ;
struct V_8 V_37 ;
if ( ! V_30 -> V_230 || V_136 -> V_43 ) {
unsigned long V_70 ;
F_36 ( & V_259 , V_70 ) ;
if ( F_128 ( & V_15 -> V_260 ) )
goto V_261;
F_129 ( & V_15 -> V_262 ) ;
F_21 ( & V_15 -> V_144 -> V_15 ,
L_7 ,
V_34 -> V_64 , V_30 -> V_230 ) ;
V_15 -> V_263 = V_264 ;
F_130 ( V_265 , & V_15 -> V_260 ) ;
V_261:
F_37 ( & V_259 , V_70 ) ;
return;
}
if ( ! V_15 -> V_59 )
return;
V_257 = F_111 ( V_15 -> V_219 , V_220 , V_194 ,
false ) ;
if ( F_112 ( V_257 ) )
return;
V_258 = F_10 ( V_257 ) ;
F_15 ( V_258 , V_257 , F_27 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . abort . V_159 = V_266 ;
V_37 . abort . V_267 = V_34 -> V_64 ;
V_37 . abort . V_245 = F_88 ( V_30 -> V_230 ) ;
V_37 . abort . V_51 = V_257 -> V_64 ;
-- V_15 -> V_59 ;
V_136 -> V_43 = 1 ;
F_21 ( V_30 -> V_50 , L_8 , V_34 -> V_64 ,
V_30 -> V_230 ) ;
if ( F_35 ( V_15 -> V_31 [ 0 ] , & V_37 ) < 0 ) {
F_21 ( V_30 -> V_50 ,
L_9 ,
V_34 -> V_64 , V_30 -> V_230 ) ;
F_116 ( V_257 ) ;
}
}
static void F_131 ( struct V_25 * V_26 ,
struct V_33 * V_34 , void * V_27 , bool V_268 )
{
struct V_29 * V_30 = V_27 ;
void * V_40 ;
T_1 V_42 ;
struct V_20 * V_37 ;
struct V_46 V_47 ;
if ( ! F_132 ( V_34 ) )
return;
V_37 = F_10 ( V_34 ) ;
if ( V_37 -> V_40 == V_48 )
return;
if ( F_133 ( V_34 -> V_141 ) )
V_47 . V_55 = F_88 ( ( V_57 | V_137 ) << 1 ) ;
else
V_47 . V_55 = F_88 ( V_57 << 1 ) ;
F_21 ( V_30 -> V_50 , L_10 ,
V_34 -> V_64 , V_30 -> V_230 ) ;
V_40 = F_23 ( V_37 , & V_42 ) ;
V_42 ( V_30 , V_40 , & V_47 ) ;
}
static enum V_269 F_134 ( struct V_33 * V_34 , bool V_268 )
{
struct V_20 * V_37 = F_10 ( V_34 ) ;
struct V_29 * V_30 = V_37 -> V_30 ;
F_21 ( V_30 -> V_50 , L_11 , V_34 -> V_64 ,
V_30 -> V_230 ) ;
F_95 ( & V_30 -> V_71 ) ;
F_127 ( V_34 ) ;
F_97 ( & V_30 -> V_71 ) ;
return V_270 ;
}
static void F_135 ( struct V_29 * V_30 )
{
F_136 ( V_30 -> V_50 , F_137 ( V_30 -> V_65 ) ,
( void * ) V_30 -> V_204 , V_30 -> V_235 ) ;
F_136 ( V_30 -> V_50 , F_138 ( V_30 -> V_65 ) ,
V_30 -> V_68 , V_30 -> V_244 ) ;
F_48 ( V_30 ) ;
}
static void F_139 ( struct V_14 * V_15 , int V_271 )
{
int V_89 ;
for ( V_89 = V_15 -> V_38 - 1 ; V_89 >= V_271 ; V_89 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_89 ] ;
V_15 -> V_38 -- ;
V_15 -> V_31 [ V_89 ] = NULL ;
F_135 ( V_30 ) ;
}
}
static int F_140 ( struct V_29 * V_30 )
{
int V_272 ;
F_95 ( & V_30 -> V_71 ) ;
if ( V_30 -> V_240 == - 1 ) {
F_97 ( & V_30 -> V_71 ) ;
return 1 ;
}
V_272 = V_30 -> V_15 -> V_273 [ V_30 -> V_240 ] . V_272 ;
V_30 -> V_15 -> V_274 -- ;
V_30 -> V_240 = - 1 ;
F_97 ( & V_30 -> V_71 ) ;
F_141 ( V_272 , NULL ) ;
F_142 ( V_272 , V_30 ) ;
return 0 ;
}
static void F_143 ( struct V_29 * V_30 )
{
struct V_25 * V_26 = V_30 -> V_26 ;
F_95 ( & V_30 -> V_71 ) ;
if ( V_26 && V_26 -> V_39 )
F_144 ( V_26 , F_131 , V_30 ) ;
F_97 ( & V_30 -> V_71 ) ;
}
static void F_145 ( struct V_14 * V_15 , int V_230 )
{
struct V_29 * V_30 = V_15 -> V_31 [ V_230 ] ;
if ( ! V_30 )
return;
if ( F_140 ( V_30 ) )
return;
if ( V_230 && F_146 ( & V_15 -> V_275 -> V_276 ) != - 1 ) {
F_123 ( V_15 , V_230 ) ;
F_122 ( V_15 , V_230 ) ;
}
if ( ! V_230 && V_15 -> V_219 )
F_147 ( V_15 -> V_219 ) ;
F_95 ( & V_30 -> V_71 ) ;
F_96 ( V_30 ) ;
F_97 ( & V_30 -> V_71 ) ;
}
static struct V_29 * F_148 ( struct V_14 * V_15 , int V_230 ,
int V_277 )
{
struct V_278 * V_279 = & V_15 -> V_144 -> V_15 ;
struct V_29 * V_30 = F_149 ( sizeof( * V_30 ) , V_223 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_204 = F_150 ( V_279 , F_137 ( V_277 ) ,
& V_30 -> V_235 , V_223 ) ;
if ( ! V_30 -> V_204 )
goto V_280;
V_30 -> V_68 = F_151 ( V_279 , F_138 ( V_277 ) ,
& V_30 -> V_244 , V_223 ) ;
if ( ! V_30 -> V_68 )
goto V_281;
V_30 -> V_50 = V_279 ;
V_30 -> V_15 = V_15 ;
snprintf ( V_30 -> V_282 , sizeof( V_30 -> V_282 ) , L_12 ,
V_15 -> V_283 , V_230 ) ;
F_152 ( & V_30 -> V_71 ) ;
V_30 -> V_202 = 0 ;
V_30 -> V_203 = 1 ;
V_30 -> V_69 = & V_15 -> V_284 [ V_230 * 2 * V_15 -> V_206 ] ;
V_30 -> V_65 = V_277 ;
V_30 -> V_230 = V_230 ;
V_15 -> V_38 ++ ;
V_15 -> V_31 [ V_230 ] = V_30 ;
return V_30 ;
V_281:
F_136 ( V_279 , F_137 ( V_277 ) , ( void * ) V_30 -> V_204 ,
V_30 -> V_235 ) ;
V_280:
F_48 ( V_30 ) ;
return NULL ;
}
static int F_153 ( struct V_14 * V_15 , struct V_29 * V_30 ,
const char * V_285 )
{
if ( V_286 )
return F_154 ( V_15 -> V_273 [ V_30 -> V_240 ] . V_272 ,
F_104 , F_101 , V_287 ,
V_285 , V_30 ) ;
return F_155 ( V_15 -> V_273 [ V_30 -> V_240 ] . V_272 , F_101 ,
V_287 , V_285 , V_30 ) ;
}
static void F_156 ( struct V_29 * V_30 , T_3 V_230 )
{
struct V_14 * V_15 = V_30 -> V_15 ;
F_95 ( & V_30 -> V_71 ) ;
V_30 -> V_67 = 0 ;
V_30 -> V_202 = 0 ;
V_30 -> V_203 = 1 ;
V_30 -> V_69 = & V_15 -> V_284 [ V_230 * 2 * V_15 -> V_206 ] ;
memset ( ( void * ) V_30 -> V_204 , 0 , F_137 ( V_30 -> V_65 ) ) ;
V_15 -> V_274 ++ ;
F_97 ( & V_30 -> V_71 ) ;
}
static int F_157 ( struct V_29 * V_30 , int V_230 )
{
struct V_14 * V_15 = V_30 -> V_15 ;
int V_54 ;
V_30 -> V_240 = V_230 - 1 ;
V_54 = F_120 ( V_15 , V_230 , V_30 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_121 ( V_15 , V_230 , V_30 ) ;
if ( V_54 < 0 )
goto V_288;
V_54 = F_153 ( V_15 , V_30 , V_30 -> V_282 ) ;
if ( V_54 < 0 )
goto V_289;
F_156 ( V_30 , V_230 ) ;
return V_54 ;
V_289:
F_123 ( V_15 , V_230 ) ;
V_288:
F_122 ( V_15 , V_230 ) ;
return V_54 ;
}
static int F_158 ( struct V_14 * V_15 , T_6 V_290 , bool V_291 )
{
unsigned long V_140 ;
T_2 V_292 = V_291 ? V_293 : 0 ;
V_140 = ( ( F_159 ( V_290 ) + 1 ) * V_294 / 2 ) + V_138 ;
while ( ( F_146 ( & V_15 -> V_275 -> V_276 ) & V_293 ) != V_292 ) {
F_160 ( 100 ) ;
if ( F_161 ( V_214 ) )
return - V_215 ;
if ( F_162 ( V_138 , V_140 ) ) {
F_163 ( & V_15 -> V_144 -> V_15 ,
L_13 , V_291 ?
L_14 : L_15 ) ;
return - V_295 ;
}
}
return 0 ;
}
static int F_164 ( struct V_14 * V_15 , T_6 V_290 )
{
V_15 -> V_296 &= ~ V_297 ;
V_15 -> V_296 &= ~ V_298 ;
F_34 ( V_15 -> V_296 , & V_15 -> V_275 -> V_299 ) ;
return F_158 ( V_15 , V_290 , false ) ;
}
static int F_165 ( struct V_14 * V_15 , T_6 V_290 )
{
V_15 -> V_296 &= ~ V_297 ;
V_15 -> V_296 |= V_298 ;
F_34 ( V_15 -> V_296 , & V_15 -> V_275 -> V_299 ) ;
return F_158 ( V_15 , V_290 , true ) ;
}
static int F_166 ( struct V_14 * V_15 )
{
unsigned long V_140 ;
V_15 -> V_296 &= ~ V_297 ;
V_15 -> V_296 |= V_300 ;
F_34 ( V_15 -> V_296 , & V_15 -> V_275 -> V_299 ) ;
V_140 = V_301 + V_138 ;
while ( ( F_146 ( & V_15 -> V_275 -> V_276 ) & V_302 ) !=
V_303 ) {
F_160 ( 100 ) ;
if ( F_161 ( V_214 ) )
return - V_215 ;
if ( F_162 ( V_138 , V_140 ) ) {
F_163 ( & V_15 -> V_144 -> V_15 ,
L_16 ) ;
return - V_295 ;
}
}
return 0 ;
}
static void F_167 ( struct V_14 * V_15 )
{
if ( V_15 -> V_219 && ! F_133 ( V_15 -> V_219 ) ) {
F_168 ( V_15 -> V_219 ) ;
F_169 ( & V_15 -> V_304 ) ;
}
}
static int F_170 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_219 ) {
V_15 -> V_304 . V_305 = & V_306 ;
V_15 -> V_304 . V_307 = 1 ;
V_15 -> V_304 . V_308 = V_309 - 1 ;
V_15 -> V_304 . V_140 = V_225 ;
V_15 -> V_304 . V_36 = F_171 ( & V_15 -> V_144 -> V_15 ) ;
V_15 -> V_304 . V_310 = F_5 ( V_15 ) ;
V_15 -> V_304 . V_32 = V_15 ;
if ( F_172 ( & V_15 -> V_304 ) )
return - V_311 ;
V_15 -> V_219 = F_173 ( & V_15 -> V_304 ) ;
if ( F_112 ( V_15 -> V_219 ) ) {
F_169 ( & V_15 -> V_304 ) ;
return - V_311 ;
}
if ( ! F_174 ( V_15 -> V_219 ) ) {
F_167 ( V_15 ) ;
return - V_295 ;
}
} else
F_175 ( V_15 -> V_219 ) ;
return 0 ;
}
static int F_176 ( struct V_14 * V_15 )
{
int V_54 ;
T_2 V_312 ;
T_6 V_290 = F_177 ( & V_15 -> V_275 -> V_290 ) ;
struct V_29 * V_30 ;
unsigned V_313 = V_314 ;
unsigned V_315 = F_178 ( V_290 ) + 12 ;
unsigned V_316 = F_179 ( V_290 ) + 12 ;
if ( V_313 < V_315 ) {
F_163 ( & V_15 -> V_144 -> V_15 ,
L_17
L_18 , 1 << V_315 ,
1 << V_313 ) ;
return - V_295 ;
}
if ( V_313 > V_316 ) {
F_180 ( & V_15 -> V_144 -> V_15 ,
L_19
L_20 ,
1 << V_316 , 1 << V_313 ) ;
V_313 = V_316 ;
}
V_54 = F_164 ( V_15 , V_290 ) ;
if ( V_54 < 0 )
return V_54 ;
V_30 = V_15 -> V_31 [ 0 ] ;
if ( ! V_30 ) {
V_30 = F_148 ( V_15 , 0 , V_309 ) ;
if ( ! V_30 )
return - V_311 ;
}
V_312 = V_30 -> V_65 - 1 ;
V_312 |= V_312 << 16 ;
V_15 -> V_17 = 1 << V_313 ;
V_15 -> V_296 = V_317 ;
V_15 -> V_296 |= ( V_313 - 12 ) << V_318 ;
V_15 -> V_296 |= V_319 | V_320 ;
V_15 -> V_296 |= V_321 | V_322 ;
F_34 ( V_312 , & V_15 -> V_275 -> V_312 ) ;
F_181 ( V_30 -> V_244 , & V_15 -> V_275 -> V_323 ) ;
F_181 ( V_30 -> V_235 , & V_15 -> V_275 -> V_324 ) ;
V_54 = F_165 ( V_15 , V_290 ) ;
if ( V_54 )
goto V_280;
V_30 -> V_240 = 0 ;
V_54 = F_153 ( V_15 , V_30 , V_30 -> V_282 ) ;
if ( V_54 )
goto V_280;
return V_54 ;
V_280:
F_139 ( V_15 , 0 ) ;
return V_54 ;
}
struct V_21 * F_182 ( struct V_14 * V_15 , int V_325 ,
unsigned long V_326 , unsigned V_77 )
{
int V_89 , V_327 , V_328 , V_78 , V_72 ;
struct V_23 * V_75 ;
struct V_329 * * V_330 ;
struct V_21 * V_44 ;
if ( V_326 & 3 )
return F_183 ( - V_331 ) ;
if ( ! V_77 || V_77 > V_332 - V_18 )
return F_183 ( - V_331 ) ;
V_72 = F_80 ( V_326 ) ;
V_328 = F_4 ( V_72 + V_77 , V_18 ) ;
V_330 = F_184 ( V_328 , sizeof( * V_330 ) , V_223 ) ;
if ( ! V_330 )
return F_183 ( - V_311 ) ;
V_327 = F_185 ( V_326 , V_328 , 1 , V_330 ) ;
if ( V_327 < V_328 ) {
V_328 = V_327 ;
V_327 = - V_192 ;
goto V_333;
}
V_327 = - V_311 ;
V_44 = F_41 ( V_328 , V_77 , V_15 , 0 , V_223 ) ;
if ( ! V_44 )
goto V_333;
V_75 = V_44 -> V_75 ;
F_90 ( V_75 , V_328 ) ;
for ( V_89 = 0 ; V_89 < V_328 ; V_89 ++ ) {
F_186 ( & V_75 [ V_89 ] , V_330 [ V_89 ] ,
F_187 ( unsigned , V_77 , V_18 - V_72 ) ,
V_72 ) ;
V_77 -= ( V_18 - V_72 ) ;
V_72 = 0 ;
}
F_188 ( & V_75 [ V_89 - 1 ] ) ;
V_44 -> V_78 = V_328 ;
V_78 = F_92 ( & V_15 -> V_144 -> V_15 , V_75 , V_328 ,
V_325 ? V_145 : V_146 ) ;
if ( ! V_78 )
goto V_334;
F_48 ( V_330 ) ;
return V_44 ;
V_334:
F_48 ( V_44 ) ;
V_333:
for ( V_89 = 0 ; V_89 < V_328 ; V_89 ++ )
F_189 ( V_330 [ V_89 ] ) ;
F_48 ( V_330 ) ;
return F_183 ( V_327 ) ;
}
void F_190 ( struct V_14 * V_15 , int V_325 ,
struct V_21 * V_44 )
{
int V_89 ;
F_73 ( & V_15 -> V_144 -> V_15 , V_44 -> V_75 , V_44 -> V_78 ,
V_325 ? V_145 : V_146 ) ;
for ( V_89 = 0 ; V_89 < V_44 -> V_78 ; V_89 ++ )
F_189 ( F_191 ( & V_44 -> V_75 [ V_89 ] ) ) ;
}
static int F_192 ( struct V_105 * V_106 , struct V_335 T_9 * V_336 )
{
struct V_14 * V_15 = V_106 -> V_15 ;
struct V_335 V_337 ;
struct V_8 V_217 ;
unsigned V_77 , V_338 ;
int V_55 , V_89 ;
struct V_21 * V_44 , * V_339 = NULL ;
T_5 V_340 ;
void * V_341 , * V_342 ( V_343 ) ;
if ( F_193 ( & V_337 , V_336 , sizeof( V_337 ) ) )
return - V_192 ;
V_77 = ( V_337 . V_344 + 1 ) << V_106 -> V_122 ;
V_338 = ( V_337 . V_344 + 1 ) * V_106 -> V_134 ;
if ( V_338 && ( ( V_337 . V_182 & 3 ) || ! V_337 . V_182 ) )
return - V_331 ;
switch ( V_337 . V_159 ) {
case V_179 :
case V_180 :
case V_345 :
V_44 = F_182 ( V_15 , V_337 . V_159 & 1 , V_337 . V_326 , V_77 ) ;
break;
default:
return - V_331 ;
}
if ( F_112 ( V_44 ) )
return F_113 ( V_44 ) ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_178 . V_159 = V_337 . V_159 ;
V_217 . V_178 . V_70 = V_337 . V_70 ;
V_217 . V_178 . V_161 = F_85 ( V_106 -> V_162 ) ;
V_217 . V_178 . V_157 = F_83 ( V_337 . V_157 ) ;
V_217 . V_178 . V_77 = F_88 ( V_337 . V_344 ) ;
V_217 . V_178 . V_170 = F_88 ( V_337 . V_170 ) ;
V_217 . V_178 . V_171 = F_85 ( V_337 . V_171 ) ;
V_217 . V_178 . V_185 = F_85 ( V_337 . V_185 ) ;
V_217 . V_178 . V_346 = F_88 ( V_337 . V_346 ) ;
V_217 . V_178 . V_347 = F_88 ( V_337 . V_347 ) ;
if ( V_338 ) {
V_339 = F_182 ( V_15 , V_337 . V_159 & 1 , V_337 . V_182 ,
V_338 ) ;
if ( F_112 ( V_339 ) ) {
V_55 = F_113 ( V_339 ) ;
V_339 = NULL ;
goto V_348;
}
V_343 = F_151 ( & V_15 -> V_144 -> V_15 , V_338 ,
& V_340 , V_223 ) ;
if ( ! V_343 ) {
V_55 = - V_311 ;
goto V_348;
}
if ( V_337 . V_159 & 1 ) {
int V_349 = 0 ;
for ( V_89 = 0 ; V_89 < V_339 -> V_78 ; V_89 ++ ) {
V_341 = F_57 ( F_191 ( & V_339 -> V_75 [ V_89 ] ) ) +
V_339 -> V_75 [ V_89 ] . V_72 ;
memcpy ( V_343 + V_349 , V_341 ,
V_339 -> V_75 [ V_89 ] . V_77 ) ;
F_61 ( V_341 ) ;
V_349 += V_339 -> V_75 [ V_89 ] . V_77 ;
}
}
V_217 . V_178 . V_182 = F_83 ( V_340 ) ;
}
V_77 = F_77 ( V_15 , V_44 , V_77 , V_223 ) ;
V_217 . V_178 . V_163 = F_83 ( F_79 ( V_44 -> V_75 ) ) ;
V_217 . V_178 . V_181 = F_83 ( V_44 -> V_92 ) ;
if ( V_77 != ( V_337 . V_344 + 1 ) << V_106 -> V_122 )
V_55 = - V_311 ;
else
V_55 = F_118 ( V_15 , V_106 , & V_217 , NULL ) ;
if ( V_338 ) {
if ( V_55 == V_56 && ! ( V_337 . V_159 & 1 ) ) {
int V_349 = 0 ;
for ( V_89 = 0 ; V_89 < V_339 -> V_78 ; V_89 ++ ) {
V_341 = F_57 ( F_191 ( & V_339 -> V_75 [ V_89 ] ) ) +
V_339 -> V_75 [ V_89 ] . V_72 ;
memcpy ( V_341 , V_343 + V_349 ,
V_339 -> V_75 [ V_89 ] . V_77 ) ;
F_61 ( V_341 ) ;
V_349 += V_339 -> V_75 [ V_89 ] . V_77 ;
}
}
F_136 ( & V_15 -> V_144 -> V_15 , V_338 , V_343 ,
V_340 ) ;
}
V_348:
F_190 ( V_15 , V_337 . V_159 & 1 , V_44 ) ;
F_45 ( V_15 , V_44 ) ;
if ( V_339 ) {
F_190 ( V_15 , V_337 . V_159 & 1 , V_339 ) ;
F_45 ( V_15 , V_339 ) ;
}
return V_55 ;
}
static int F_194 ( struct V_14 * V_15 , struct V_105 * V_106 ,
struct V_350 T_9 * V_351 )
{
struct V_350 V_37 ;
struct V_8 V_217 ;
int V_55 , V_77 ;
struct V_21 * V_342 ( V_44 ) ;
unsigned V_140 ;
if ( ! F_195 ( V_352 ) )
return - V_353 ;
if ( F_193 ( & V_37 , V_351 , sizeof( V_37 ) ) )
return - V_192 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_168 . V_159 = V_37 . V_159 ;
V_217 . V_168 . V_70 = V_37 . V_70 ;
V_217 . V_168 . V_161 = F_85 ( V_37 . V_161 ) ;
V_217 . V_168 . V_354 [ 0 ] = F_85 ( V_37 . V_354 ) ;
V_217 . V_168 . V_354 [ 1 ] = F_85 ( V_37 . V_355 ) ;
V_217 . V_168 . V_356 [ 0 ] = F_85 ( V_37 . V_356 ) ;
V_217 . V_168 . V_356 [ 1 ] = F_85 ( V_37 . V_357 ) ;
V_217 . V_168 . V_356 [ 2 ] = F_85 ( V_37 . V_358 ) ;
V_217 . V_168 . V_356 [ 3 ] = F_85 ( V_37 . V_359 ) ;
V_217 . V_168 . V_356 [ 4 ] = F_85 ( V_37 . V_360 ) ;
V_217 . V_168 . V_356 [ 5 ] = F_85 ( V_37 . V_361 ) ;
V_77 = V_37 . V_362 ;
if ( V_37 . V_362 ) {
V_44 = F_182 ( V_15 , V_37 . V_159 & 1 , V_37 . V_326 ,
V_77 ) ;
if ( F_112 ( V_44 ) )
return F_113 ( V_44 ) ;
V_77 = F_77 ( V_15 , V_44 , V_77 , V_223 ) ;
V_217 . V_168 . V_163 = F_83 ( F_79 ( V_44 -> V_75 ) ) ;
V_217 . V_168 . V_181 = F_83 ( V_44 -> V_92 ) ;
}
V_140 = V_37 . V_363 ? F_196 ( V_37 . V_363 ) :
V_225 ;
if ( V_77 != V_37 . V_362 )
V_55 = - V_311 ;
else if ( V_106 ) {
struct V_33 * V_34 ;
V_34 = F_111 ( V_106 -> V_135 , V_220 ,
( V_223 | V_226 ) , false ) ;
if ( F_112 ( V_34 ) )
V_55 = F_113 ( V_34 ) ;
else {
V_55 = F_107 ( V_34 , & V_217 , & V_37 . V_54 ,
V_140 ) ;
F_116 ( V_34 ) ;
}
} else
V_55 = F_115 ( V_15 , & V_217 , & V_37 . V_54 , V_140 ) ;
if ( V_37 . V_362 ) {
F_190 ( V_15 , V_37 . V_159 & 1 , V_44 ) ;
F_45 ( V_15 , V_44 ) ;
}
if ( ( V_55 >= 0 ) && F_197 ( & V_351 -> V_54 , & V_37 . V_54 ,
sizeof( V_37 . V_54 ) ) )
V_55 = - V_192 ;
return V_55 ;
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
return F_194 ( V_106 -> V_15 , NULL , ( void T_9 * ) V_367 ) ;
case V_371 :
return F_194 ( V_106 -> V_15 , V_106 , ( void T_9 * ) V_367 ) ;
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
F_102 ( & V_259 ) ;
V_106 = V_365 -> V_368 -> V_108 ;
if ( ! V_106 )
V_19 = - V_377 ;
else if ( ! F_204 ( & V_106 -> V_15 -> V_378 ) )
V_19 = - V_377 ;
F_103 ( & V_259 ) ;
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
int V_393 , V_116 , V_394 ;
unsigned short V_395 ;
V_228 = F_151 ( & V_15 -> V_144 -> V_15 , 4096 , & V_152 ,
V_223 ) ;
if ( ! V_228 ) {
F_21 ( & V_15 -> V_144 -> V_15 , L_21 ,
V_396 ) ;
return 0 ;
}
if ( F_124 ( V_15 , V_106 -> V_162 , 0 , V_152 ) ) {
F_21 ( & V_15 -> V_144 -> V_15 ,
L_22 ,
V_106 -> V_162 ) ;
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
}
V_394 = V_106 -> V_134 ;
V_393 = V_228 -> V_397 & V_398 ;
V_106 -> V_122 = V_228 -> V_393 [ V_393 ] . V_399 ;
V_106 -> V_134 = F_98 ( V_228 -> V_393 [ V_393 ] . V_134 ) ;
if ( V_106 -> V_122 == 0 )
V_106 -> V_122 = 9 ;
V_395 = 1 << V_106 -> V_122 ;
V_116 = V_106 -> V_134 == sizeof( struct V_102 ) ?
V_228 -> V_400 & V_401 : 0 ;
if ( F_213 ( V_123 ) && ( V_106 -> V_116 != V_116 ||
V_106 -> V_134 != V_394 ||
V_395 != F_210 ( V_123 -> V_135 ) ||
( V_106 -> V_134 && V_228 -> V_397 & V_402 ) ) )
F_214 ( V_123 ) ;
V_106 -> V_116 = V_116 ;
F_215 ( V_106 -> V_135 , V_395 ) ;
if ( V_106 -> V_134 && ! F_213 ( V_123 ) && ( V_123 -> V_70 & V_403 ) &&
! ( V_228 -> V_397 & V_402 ) )
F_64 ( V_106 ) ;
if ( V_228 -> V_404 == 0 || ( V_106 -> V_134 && ! F_213 ( V_123 ) ) )
F_216 ( V_123 , 0 ) ;
else
F_216 ( V_123 , F_217 ( & V_228 -> V_405 ) << ( V_106 -> V_122 - 9 ) ) ;
if ( V_15 -> V_406 & V_407 )
F_209 ( V_106 ) ;
F_136 ( & V_15 -> V_144 -> V_15 , 4096 , V_228 , V_152 ) ;
return 0 ;
}
static int F_218 ( void * V_27 )
{
struct V_14 * V_15 , * V_408 ;
while ( ! F_219 () ) {
F_108 ( V_409 ) ;
F_102 ( & V_259 ) ;
F_220 (dev, next, &dev_list, node) {
int V_89 ;
if ( F_146 ( & V_15 -> V_275 -> V_276 ) & V_410 ) {
if ( F_128 ( & V_15 -> V_260 ) )
continue;
F_129 ( & V_15 -> V_262 ) ;
F_21 ( & V_15 -> V_144 -> V_15 ,
L_23 ,
F_146 ( & V_15 -> V_275 -> V_276 ) ) ;
V_15 -> V_263 = V_264 ;
F_130 ( V_265 , & V_15 -> V_260 ) ;
continue;
}
for ( V_89 = 0 ; V_89 < V_15 -> V_38 ; V_89 ++ ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_89 ] ;
if ( ! V_30 )
continue;
F_95 ( & V_30 -> V_71 ) ;
F_96 ( V_30 ) ;
while ( ( V_89 == 0 ) && ( V_15 -> V_58 > 0 ) ) {
if ( F_110 ( V_15 ) )
break;
V_15 -> V_58 -- ;
}
F_97 ( & V_30 -> V_71 ) ;
}
}
F_103 ( & V_259 ) ;
F_221 ( F_222 ( V_294 ) ) ;
}
return 0 ;
}
static void F_223 ( struct V_14 * V_15 , unsigned V_161 )
{
struct V_105 * V_106 ;
struct V_379 * V_123 ;
int V_262 = F_171 ( & V_15 -> V_144 -> V_15 ) ;
V_106 = F_224 ( sizeof( * V_106 ) , V_223 , V_262 ) ;
if ( ! V_106 )
return;
V_106 -> V_135 = F_173 ( & V_15 -> V_411 ) ;
if ( F_112 ( V_106 -> V_135 ) )
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
V_123 -> V_70 = V_428 ;
sprintf ( V_123 -> V_429 , L_24 , V_15 -> V_283 , V_161 ) ;
F_216 ( V_123 , 0 ) ;
F_212 ( V_106 -> V_123 ) ;
F_230 ( V_106 -> V_123 ) ;
if ( V_106 -> V_134 )
F_231 ( V_106 -> V_123 ) ;
return;
V_416:
F_168 ( V_106 -> V_135 ) ;
V_412:
F_48 ( V_106 ) ;
}
static void F_232 ( struct V_14 * V_15 )
{
unsigned V_89 ;
for ( V_89 = V_15 -> V_38 ; V_89 <= V_15 -> V_430 ; V_89 ++ )
if ( ! F_148 ( V_15 , V_89 , V_15 -> V_65 ) )
break;
for ( V_89 = V_15 -> V_274 ; V_89 <= V_15 -> V_38 - 1 ; V_89 ++ )
if ( F_157 ( V_15 -> V_31 [ V_89 ] , V_89 ) )
break;
}
static int F_233 ( struct V_14 * V_15 , int V_328 )
{
int V_55 ;
T_2 V_54 ;
T_2 V_431 = ( V_328 - 1 ) | ( ( V_328 - 1 ) << 16 ) ;
V_55 = F_126 ( V_15 , V_432 , V_431 , 0 ,
& V_54 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_55 > 0 ) {
F_163 ( & V_15 -> V_144 -> V_15 , L_25 ,
V_55 ) ;
return 0 ;
}
return F_234 ( V_54 & 0xffff , V_54 >> 16 ) + 1 ;
}
static T_11 F_235 ( struct V_14 * V_15 , unsigned V_433 )
{
return 4096 + ( ( V_433 + 1 ) * 8 * V_15 -> V_206 ) ;
}
static int F_236 ( struct V_14 * V_15 )
{
struct V_29 * V_434 = V_15 -> V_31 [ 0 ] ;
struct V_144 * V_435 = V_15 -> V_144 ;
int V_54 , V_89 , V_436 , V_433 , V_13 ;
V_433 = F_237 () ;
V_54 = F_233 ( V_15 , V_433 ) ;
if ( V_54 <= 0 )
return V_54 ;
if ( V_54 < V_433 )
V_433 = V_54 ;
V_13 = F_235 ( V_15 , V_433 ) ;
if ( V_13 > 8192 ) {
F_238 ( V_15 -> V_275 ) ;
do {
V_15 -> V_275 = F_239 ( F_240 ( V_435 , 0 ) , V_13 ) ;
if ( V_15 -> V_275 )
break;
if ( ! -- V_433 )
return - V_311 ;
V_13 = F_235 ( V_15 , V_433 ) ;
} while ( 1 );
V_15 -> V_284 = ( ( void V_437 * ) V_15 -> V_275 ) + 4096 ;
V_434 -> V_69 = V_15 -> V_284 ;
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
V_54 = F_153 ( V_15 , V_434 , V_434 -> V_282 ) ;
if ( V_54 )
goto V_438;
F_139 ( V_15 , V_433 + 1 ) ;
F_232 ( V_15 ) ;
return 0 ;
V_438:
F_139 ( V_15 , 1 ) ;
return V_54 ;
}
static int F_244 ( struct V_14 * V_15 )
{
struct V_144 * V_435 = V_15 -> V_144 ;
int V_224 ;
unsigned V_439 , V_89 ;
struct V_9 * V_440 ;
void * V_441 ;
T_5 V_152 ;
int V_442 = F_178 ( F_177 ( & V_15 -> V_275 -> V_290 ) ) + 12 ;
V_441 = F_151 ( & V_435 -> V_15 , 4096 , & V_152 , V_223 ) ;
if ( ! V_441 )
return - V_311 ;
V_224 = F_124 ( V_15 , 0 , 1 , V_152 ) ;
if ( V_224 ) {
F_163 ( & V_435 -> V_15 , L_26 , V_224 ) ;
F_136 ( & V_15 -> V_144 -> V_15 , 4096 , V_441 , V_152 ) ;
return - V_99 ;
}
V_440 = V_441 ;
V_439 = F_25 ( & V_440 -> V_439 ) ;
V_15 -> V_406 = F_22 ( & V_440 -> V_406 ) ;
V_15 -> V_59 = V_440 -> V_443 + 1 ;
V_15 -> V_420 = V_440 -> V_420 ;
V_15 -> V_58 = F_234 ( V_440 -> V_444 + 1 , 8 ) ;
memcpy ( V_15 -> V_445 , V_440 -> V_446 , sizeof( V_440 -> V_446 ) ) ;
memcpy ( V_15 -> V_447 , V_440 -> V_448 , sizeof( V_440 -> V_448 ) ) ;
memcpy ( V_15 -> V_449 , V_440 -> V_450 , sizeof( V_440 -> V_450 ) ) ;
if ( V_440 -> V_451 )
V_15 -> V_418 = 1 << ( V_440 -> V_451 + V_442 - 9 ) ;
if ( ( V_435 -> V_452 == V_453 ) &&
( V_435 -> V_278 == 0x0953 ) && V_440 -> V_454 [ 3 ] ) {
unsigned int V_418 ;
V_15 -> V_419 = 1 << ( V_440 -> V_454 [ 3 ] + V_442 ) ;
V_418 = V_15 -> V_419 >> ( V_442 - 9 ) ;
if ( V_15 -> V_418 ) {
V_15 -> V_418 = F_234 ( V_418 ,
V_15 -> V_418 ) ;
} else
V_15 -> V_418 = V_418 ;
}
F_136 ( & V_15 -> V_144 -> V_15 , 4096 , V_441 , V_152 ) ;
V_15 -> V_411 . V_305 = & V_455 ;
V_15 -> V_411 . V_307 = V_15 -> V_274 - 1 ;
V_15 -> V_411 . V_140 = V_227 ;
V_15 -> V_411 . V_36 = F_171 ( & V_15 -> V_144 -> V_15 ) ;
V_15 -> V_411 . V_308 =
F_187 ( int , V_15 -> V_65 , V_456 ) - 1 ;
V_15 -> V_411 . V_310 = F_5 ( V_15 ) ;
V_15 -> V_411 . V_70 = V_457 ;
V_15 -> V_411 . V_32 = V_15 ;
if ( F_172 ( & V_15 -> V_411 ) )
return 0 ;
for ( V_89 = 1 ; V_89 <= V_439 ; V_89 ++ )
F_223 ( V_15 , V_89 ) ;
return 0 ;
}
static int F_245 ( struct V_14 * V_15 )
{
T_6 V_290 ;
int V_458 , V_54 = - V_311 ;
struct V_144 * V_435 = V_15 -> V_144 ;
if ( F_246 ( V_435 ) )
return V_54 ;
V_15 -> V_273 [ 0 ] . V_272 = V_435 -> V_208 ;
F_247 ( V_435 ) ;
V_458 = F_248 ( V_435 , V_459 ) ;
if ( ! V_458 )
goto V_460;
if ( F_249 ( V_435 , V_458 , L_27 ) )
goto V_460;
if ( F_250 ( & V_435 -> V_15 , F_251 ( 64 ) ) &&
F_250 ( & V_435 -> V_15 , F_251 ( 32 ) ) )
goto V_461;
V_15 -> V_275 = F_239 ( F_240 ( V_435 , 0 ) , 8192 ) ;
if ( ! V_15 -> V_275 )
goto V_461;
if ( F_146 ( & V_15 -> V_275 -> V_276 ) == - 1 ) {
V_54 = - V_295 ;
goto V_348;
}
if ( ! V_435 -> V_208 ) {
V_54 = F_252 ( V_435 , V_15 -> V_273 , 1 ) ;
if ( V_54 < 0 )
goto V_348;
}
V_290 = F_177 ( & V_15 -> V_275 -> V_290 ) ;
V_15 -> V_65 = F_187 ( int , F_253 ( V_290 ) + 1 , V_462 ) ;
V_15 -> V_206 = 1 << F_254 ( V_290 ) ;
V_15 -> V_284 = ( ( void V_437 * ) V_15 -> V_275 ) + 4096 ;
return 0 ;
V_348:
F_238 ( V_15 -> V_275 ) ;
V_15 -> V_275 = NULL ;
V_461:
F_255 ( V_435 ) ;
V_460:
F_256 ( V_435 ) ;
return V_54 ;
}
static void F_257 ( struct V_14 * V_15 )
{
if ( V_15 -> V_144 -> V_463 )
F_258 ( V_15 -> V_144 ) ;
else if ( V_15 -> V_144 -> V_464 )
F_241 ( V_15 -> V_144 ) ;
if ( V_15 -> V_275 ) {
F_238 ( V_15 -> V_275 ) ;
V_15 -> V_275 = NULL ;
F_255 ( V_15 -> V_144 ) ;
}
if ( F_259 ( V_15 -> V_144 ) )
F_256 ( V_15 -> V_144 ) ;
}
static void F_260 ( struct V_465 * V_466 , struct V_14 * V_15 )
{
V_466 -> V_467 = V_214 ;
F_261 () ;
for (; ; ) {
F_108 ( V_468 ) ;
if ( ! F_262 ( & V_466 -> V_469 ) )
break;
if ( ! F_221 ( V_225 ) ||
F_161 ( V_214 ) ) {
F_108 ( V_470 ) ;
F_164 ( V_15 , F_177 ( & V_15 -> V_275 -> V_290 ) ) ;
F_143 ( V_15 -> V_31 [ 0 ] ) ;
F_263 ( V_466 -> V_62 ) ;
F_145 ( V_15 , 0 ) ;
return;
}
}
F_108 ( V_470 ) ;
}
static void F_264 ( struct V_465 * V_466 )
{
F_265 ( & V_466 -> V_469 ) ;
if ( V_466 -> V_467 )
F_106 ( V_466 -> V_467 ) ;
}
static struct V_465 * F_266 ( struct V_465 * V_466 )
{
F_267 ( & V_466 -> V_469 ) ;
return V_466 ;
}
static void F_268 ( struct V_29 * V_30 )
{
struct V_465 * V_466 = V_30 -> V_61 . V_40 ;
F_264 ( V_466 ) ;
}
static int F_269 ( struct V_29 * V_30 , T_8 V_159 ,
T_12 V_42 )
{
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_229 . V_159 = V_159 ;
V_217 . V_229 . V_230 = F_88 ( V_30 -> V_230 ) ;
F_270 ( & V_30 -> V_61 . V_63 , V_42 ) ;
return F_114 ( V_30 -> V_15 , & V_217 , & V_30 -> V_61 ,
V_225 ) ;
}
static void F_271 ( struct V_471 * V_63 )
{
struct V_29 * V_30 = F_272 ( V_63 , struct V_29 ,
V_61 . V_63 ) ;
F_268 ( V_30 ) ;
}
static int F_273 ( struct V_29 * V_30 )
{
return F_269 ( V_30 , V_247 ,
F_271 ) ;
}
static void F_274 ( struct V_471 * V_63 )
{
struct V_29 * V_30 = F_272 ( V_63 , struct V_29 ,
V_61 . V_63 ) ;
int V_55 = V_30 -> V_61 . V_55 ;
if ( ! V_55 )
V_55 = F_273 ( V_30 ) ;
if ( V_55 )
F_268 ( V_30 ) ;
}
static int F_275 ( struct V_29 * V_30 )
{
return F_269 ( V_30 , V_248 ,
F_274 ) ;
}
static void F_276 ( struct V_471 * V_63 )
{
struct V_29 * V_30 = F_272 ( V_63 , struct V_29 ,
V_61 . V_63 ) ;
if ( F_275 ( V_30 ) )
F_268 ( V_30 ) ;
}
static void F_277 ( struct V_14 * V_15 )
{
int V_89 ;
F_278 ( V_62 ) ;
struct V_465 V_466 ;
struct V_472 * V_473 = F_279 ( V_474 ,
& V_62 , L_28 , V_15 -> V_283 ) ;
if ( F_112 ( V_473 ) ) {
F_163 ( & V_15 -> V_144 -> V_15 ,
L_29 ) ;
for ( V_89 = V_15 -> V_38 - 1 ; V_89 > 0 ; V_89 -- )
F_145 ( V_15 , V_89 ) ;
return;
}
V_466 . V_467 = NULL ;
F_280 ( & V_466 . V_469 , 0 ) ;
V_466 . V_62 = & V_62 ;
for ( V_89 = V_15 -> V_38 - 1 ; V_89 > 0 ; V_89 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_89 ] ;
if ( F_140 ( V_30 ) )
continue;
V_30 -> V_61 . V_40 = F_266 ( & V_466 ) ;
V_30 -> V_61 . V_62 = V_466 . V_62 ;
F_270 ( & V_30 -> V_61 . V_63 , F_276 ) ;
F_29 ( V_466 . V_62 , & V_30 -> V_61 . V_63 ) ;
}
F_260 ( & V_466 , V_15 ) ;
F_281 ( V_473 ) ;
}
static void F_282 ( struct V_14 * V_15 )
{
struct V_472 * V_475 = NULL ;
F_102 ( & V_259 ) ;
F_129 ( & V_15 -> V_262 ) ;
if ( F_283 ( & V_476 ) && ! F_284 ( V_477 ) ) {
V_475 = V_477 ;
V_477 = NULL ;
}
F_103 ( & V_259 ) ;
if ( V_475 )
F_281 ( V_475 ) ;
}
static void F_285 ( struct V_14 * V_15 )
{
struct V_105 * V_106 ;
F_286 (ns, &dev->namespaces, list) {
F_147 ( V_106 -> V_135 ) ;
F_102 ( V_106 -> V_135 -> V_142 ) ;
F_287 ( V_478 , V_106 -> V_135 ) ;
F_103 ( V_106 -> V_135 -> V_142 ) ;
F_288 ( V_106 -> V_135 ) ;
F_289 ( V_106 -> V_135 ) ;
}
}
static void F_290 ( struct V_14 * V_15 )
{
struct V_105 * V_106 ;
F_286 (ns, &dev->namespaces, list) {
F_291 ( V_478 , V_106 -> V_135 ) ;
F_175 ( V_106 -> V_135 ) ;
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
F_140 ( V_30 ) ;
}
} else {
F_277 ( V_15 ) ;
F_166 ( V_15 ) ;
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
if ( V_106 -> V_123 -> V_70 & V_403 ) {
if ( F_213 ( V_106 -> V_123 ) )
F_214 ( V_106 -> V_123 ) ;
F_295 ( V_106 -> V_123 ) ;
}
if ( ! F_133 ( V_106 -> V_135 ) ) {
F_296 ( V_106 -> V_135 ) ;
F_168 ( V_106 -> V_135 ) ;
}
}
}
static int F_297 ( struct V_14 * V_15 )
{
struct V_278 * V_279 = & V_15 -> V_144 -> V_15 ;
V_15 -> V_96 = F_298 ( L_30 , V_279 ,
V_18 , V_18 , 0 ) ;
if ( ! V_15 -> V_96 )
return - V_311 ;
V_15 -> V_93 = F_298 ( L_31 , V_279 ,
256 , 256 , 0 ) ;
if ( ! V_15 -> V_93 ) {
F_299 ( V_15 -> V_96 ) ;
return - V_311 ;
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
if ( ! F_302 ( & V_479 , V_223 ) )
return - V_295 ;
F_102 ( & V_259 ) ;
error = F_303 ( & V_479 , & V_283 ) ;
F_103 ( & V_259 ) ;
} while ( error == - V_480 );
if ( error )
return - V_295 ;
V_15 -> V_283 = V_283 ;
return 0 ;
}
static void F_304 ( struct V_14 * V_15 )
{
F_102 ( & V_259 ) ;
F_305 ( & V_479 , V_15 -> V_283 ) ;
F_103 ( & V_259 ) ;
}
static void F_306 ( struct V_14 * V_15 )
{
struct V_105 * V_106 , * V_408 ;
F_220 (ns, next, &dev->namespaces, list) {
F_307 ( & V_106 -> V_90 ) ;
F_102 ( & V_259 ) ;
V_106 -> V_123 -> V_108 = NULL ;
F_103 ( & V_259 ) ;
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
F_169 ( & V_15 -> V_411 ) ;
F_311 ( V_15 -> V_219 ) ;
F_48 ( V_15 -> V_31 ) ;
F_48 ( V_15 -> V_273 ) ;
F_48 ( V_15 ) ;
}
static int F_312 ( struct V_481 * V_481 , struct V_482 * V_483 )
{
struct V_14 * V_15 ;
int V_283 = F_313 ( V_481 ) ;
int V_19 = - V_295 ;
F_102 ( & V_259 ) ;
F_286 (dev, &dev_list, node) {
if ( V_15 -> V_283 == V_283 ) {
if ( ! V_15 -> V_219 ) {
V_19 = - V_484 ;
break;
}
if ( ! F_204 ( & V_15 -> V_378 ) )
break;
V_483 -> V_108 = V_15 ;
V_19 = 0 ;
break;
}
}
F_103 ( & V_259 ) ;
return V_19 ;
}
static int F_314 ( struct V_481 * V_481 , struct V_482 * V_483 )
{
struct V_14 * V_15 = V_483 -> V_108 ;
F_206 ( & V_15 -> V_378 , V_380 ) ;
return 0 ;
}
static long F_315 ( struct V_482 * V_483 , unsigned int V_37 , unsigned long V_367 )
{
struct V_14 * V_15 = V_483 -> V_108 ;
struct V_105 * V_106 ;
switch ( V_37 ) {
case V_370 :
return F_194 ( V_15 , NULL , ( void T_9 * ) V_367 ) ;
case V_371 :
if ( F_283 ( & V_15 -> V_417 ) )
return - V_375 ;
V_106 = F_316 ( & V_15 -> V_417 , struct V_105 , V_90 ) ;
return F_194 ( V_15 , V_106 , ( void T_9 * ) V_367 ) ;
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
V_30 -> V_26 -> V_485 ) ;
}
}
static int F_318 ( struct V_14 * V_15 )
{
int V_54 ;
bool V_486 = false ;
V_54 = F_245 ( V_15 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_176 ( V_15 ) ;
if ( V_54 )
goto V_348;
F_102 ( & V_259 ) ;
if ( F_283 ( & V_476 ) && F_284 ( V_477 ) ) {
V_486 = true ;
V_477 = NULL ;
}
F_319 ( & V_15 -> V_262 , & V_476 ) ;
F_103 ( & V_259 ) ;
if ( V_486 ) {
V_477 = F_279 ( F_218 , NULL , L_27 ) ;
F_320 ( & V_487 ) ;
} else
F_321 ( V_487 , V_477 ) ;
if ( F_284 ( V_477 ) ) {
V_54 = V_477 ? F_113 ( V_477 ) : - V_215 ;
goto V_461;
}
F_156 ( V_15 -> V_31 [ 0 ] , 0 ) ;
V_54 = F_170 ( V_15 ) ;
if ( V_54 )
goto V_461;
V_54 = F_236 ( V_15 ) ;
if ( V_54 )
goto V_488;
F_317 ( V_15 ) ;
return V_54 ;
V_488:
F_167 ( V_15 ) ;
V_461:
F_145 ( V_15 , 0 ) ;
F_282 ( V_15 ) ;
V_348:
F_257 ( V_15 ) ;
return V_54 ;
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
static void F_325 ( struct V_489 * V_490 )
{
struct V_14 * V_15 = F_272 ( V_490 , struct V_14 , V_260 ) ;
F_139 ( V_15 , 1 ) ;
F_294 ( V_15 ) ;
}
static int F_326 ( struct V_14 * V_15 )
{
int V_19 ;
V_19 = F_318 ( V_15 ) ;
if ( V_19 )
return V_19 ;
if ( V_15 -> V_274 < 2 ) {
F_102 ( & V_259 ) ;
V_15 -> V_263 = F_325 ;
F_130 ( V_265 , & V_15 -> V_260 ) ;
F_103 ( & V_259 ) ;
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
if ( F_112 ( F_279 ( F_322 , V_15 , L_28 ,
V_15 -> V_283 ) ) ) {
F_163 ( & V_15 -> V_144 -> V_15 ,
L_33 ) ;
F_206 ( & V_15 -> V_378 , V_380 ) ;
}
}
}
static void V_264 ( struct V_489 * V_490 )
{
struct V_14 * V_15 = F_272 ( V_490 , struct V_14 , V_260 ) ;
F_327 ( V_15 ) ;
}
static void F_329 ( struct V_489 * V_63 )
{
struct V_14 * V_15 = F_272 ( V_63 , struct V_14 , V_260 ) ;
V_15 -> V_263 ( V_63 ) ;
}
static int F_330 ( struct V_144 * V_435 , const struct V_491 * V_228 )
{
int V_262 , V_54 = - V_311 ;
struct V_14 * V_15 ;
V_262 = F_171 ( & V_435 -> V_15 ) ;
if ( V_262 == V_492 )
F_331 ( & V_435 -> V_15 , 0 ) ;
V_15 = F_224 ( sizeof( * V_15 ) , V_223 , V_262 ) ;
if ( ! V_15 )
return - V_311 ;
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
V_54 = F_301 ( V_15 ) ;
if ( V_54 )
goto V_493;
V_54 = F_297 ( V_15 ) ;
if ( V_54 )
goto V_494;
F_336 ( & V_15 -> V_378 ) ;
V_15 -> V_278 = F_337 ( V_495 , & V_435 -> V_15 ,
F_338 ( V_496 , V_15 -> V_283 ) ,
V_15 , L_28 , V_15 -> V_283 ) ;
if ( F_112 ( V_15 -> V_278 ) ) {
V_54 = F_113 ( V_15 -> V_278 ) ;
goto V_497;
}
F_339 ( V_15 -> V_278 ) ;
F_332 ( & V_15 -> V_262 ) ;
F_333 ( & V_15 -> V_498 , V_499 ) ;
F_340 ( & V_15 -> V_498 ) ;
return 0 ;
V_497:
F_300 ( V_15 ) ;
V_494:
F_304 ( V_15 ) ;
V_493:
F_309 ( V_15 -> V_144 ) ;
free:
F_48 ( V_15 -> V_31 ) ;
F_48 ( V_15 -> V_273 ) ;
F_48 ( V_15 ) ;
return V_54 ;
}
static void V_499 ( struct V_489 * V_63 )
{
struct V_14 * V_15 = F_272 ( V_63 , struct V_14 , V_498 ) ;
int V_54 ;
V_54 = F_318 ( V_15 ) ;
if ( V_54 )
goto V_500;
if ( V_15 -> V_274 > 1 )
V_54 = F_244 ( V_15 ) ;
if ( V_54 )
goto V_500;
F_317 ( V_15 ) ;
return;
V_500:
if ( ! F_128 ( & V_15 -> V_260 ) ) {
V_15 -> V_263 = V_264 ;
F_130 ( V_265 , & V_15 -> V_260 ) ;
}
}
static void F_341 ( struct V_144 * V_435 , bool V_501 )
{
struct V_14 * V_15 = F_323 ( V_435 ) ;
if ( V_501 )
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
F_102 ( & V_259 ) ;
F_129 ( & V_15 -> V_262 ) ;
F_103 ( & V_259 ) ;
F_335 ( V_435 , NULL ) ;
F_344 ( & V_15 -> V_498 ) ;
F_344 ( & V_15 -> V_260 ) ;
F_293 ( V_15 ) ;
F_294 ( V_15 ) ;
F_167 ( V_15 ) ;
F_345 ( V_495 , F_338 ( V_496 , V_15 -> V_283 ) ) ;
F_139 ( V_15 , 0 ) ;
F_300 ( V_15 ) ;
F_206 ( & V_15 -> V_378 , V_380 ) ;
}
static int F_346 ( struct V_278 * V_15 )
{
struct V_144 * V_435 = F_347 ( V_15 ) ;
struct V_14 * V_502 = F_323 ( V_435 ) ;
F_293 ( V_502 ) ;
return 0 ;
}
static int F_348 ( struct V_278 * V_15 )
{
struct V_144 * V_435 = F_347 ( V_15 ) ;
struct V_14 * V_502 = F_323 ( V_435 ) ;
if ( F_326 ( V_502 ) && ! F_128 ( & V_502 -> V_260 ) ) {
V_502 -> V_263 = V_264 ;
F_130 ( V_265 , & V_502 -> V_260 ) ;
}
return 0 ;
}
static int T_13 F_349 ( void )
{
int V_54 ;
F_350 ( & V_487 ) ;
V_265 = F_351 ( L_27 ) ;
if ( ! V_265 )
return - V_311 ;
V_54 = F_352 ( V_423 , L_27 ) ;
if ( V_54 < 0 )
goto V_503;
else if ( V_54 > 0 )
V_423 = V_54 ;
V_54 = F_353 ( V_496 , 0 , V_504 , L_27 ,
& V_505 ) ;
if ( V_54 < 0 )
goto V_506;
else if ( V_54 > 0 )
V_496 = V_54 ;
V_495 = F_354 ( V_507 , L_27 ) ;
if ( ! V_495 )
goto V_508;
V_54 = F_355 ( & V_509 ) ;
if ( V_54 )
goto V_510;
return 0 ;
V_510:
F_356 ( V_495 ) ;
V_508:
F_357 ( V_496 , 0 , V_504 , L_27 ) ;
V_506:
V_506 ( V_423 , L_27 ) ;
V_503:
F_358 ( V_265 ) ;
return V_54 ;
}
static void T_14 F_359 ( void )
{
F_360 ( & V_509 ) ;
V_506 ( V_423 , L_27 ) ;
F_358 ( V_265 ) ;
F_356 ( V_495 ) ;
F_357 ( V_496 , 0 , V_504 , L_27 ) ;
F_11 ( V_477 && ! F_112 ( V_477 ) ) ;
F_1 () ;
}
