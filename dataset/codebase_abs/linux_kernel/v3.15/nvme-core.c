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
static struct V_13 * V_13 ( struct V_14 * V_15 )
{
return ( void * ) & V_15 -> V_16 [ F_3 ( V_15 -> V_17 ) ] ;
}
static unsigned F_4 ( int V_18 )
{
return F_5 ( V_18 , 8 ) + ( V_18 * sizeof( struct V_13 ) ) ;
}
static int F_6 ( struct V_14 * V_15 , void * V_19 ,
T_1 V_20 , unsigned V_21 )
{
int V_18 = V_15 -> V_17 - 1 ;
struct V_13 * V_22 = V_13 ( V_15 ) ;
int V_23 ;
do {
V_23 = F_7 ( V_15 -> V_16 , V_18 ) ;
if ( V_23 >= V_18 )
return - V_24 ;
} while ( F_8 ( V_23 , V_15 -> V_16 ) );
V_22 [ V_23 ] . V_25 = V_20 ;
V_22 [ V_23 ] . V_19 = V_19 ;
V_22 [ V_23 ] . V_21 = V_26 + V_21 ;
V_22 [ V_23 ] . V_27 = 0 ;
return V_23 ;
}
static int F_9 ( struct V_14 * V_15 , void * V_19 ,
T_1 V_20 , unsigned V_21 )
{
int V_23 ;
F_10 ( V_15 -> V_28 ,
( V_23 = F_6 ( V_15 , V_19 , V_20 , V_21 ) ) >= 0 ) ;
return ( V_23 < 0 ) ? - V_29 : V_23 ;
}
static void F_11 ( struct V_14 * V_15 , void * V_19 ,
struct V_30 * V_31 )
{
if ( V_19 == V_32 )
return;
if ( V_19 == V_33 )
return;
if ( V_19 == V_34 ) {
++ V_15 -> V_35 -> V_36 ;
return;
}
if ( V_19 == V_37 ) {
F_12 ( V_15 -> V_38 ,
L_1 ,
V_31 -> V_39 , F_13 ( & V_31 -> V_40 ) ) ;
return;
}
if ( V_19 == V_41 ) {
F_12 ( V_15 -> V_38 ,
L_2 ,
V_31 -> V_39 , F_13 ( & V_31 -> V_40 ) ) ;
return;
}
F_12 ( V_15 -> V_38 , L_3 , V_19 ) ;
}
static void F_14 ( struct V_14 * V_15 , void * V_19 ,
struct V_30 * V_31 )
{
struct V_42 * V_43 = V_19 ;
V_43 -> V_44 = F_15 ( & V_31 -> V_44 ) ;
V_43 -> V_45 = F_13 ( & V_31 -> V_45 ) >> 1 ;
F_16 ( V_43 -> V_46 , & V_43 -> V_47 ) ;
}
static void * F_17 ( struct V_14 * V_15 , int V_23 ,
T_1 * V_25 )
{
void * V_19 ;
struct V_13 * V_22 = V_13 ( V_15 ) ;
if ( V_23 >= V_15 -> V_17 ) {
* V_25 = F_11 ;
return V_41 ;
}
if ( V_25 )
* V_25 = V_22 [ V_23 ] . V_25 ;
V_19 = V_22 [ V_23 ] . V_19 ;
V_22 [ V_23 ] . V_25 = F_11 ;
V_22 [ V_23 ] . V_19 = V_37 ;
F_18 ( V_23 , V_15 -> V_16 ) ;
F_19 ( & V_15 -> V_28 ) ;
return V_19 ;
}
static void * F_20 ( struct V_14 * V_15 , int V_23 ,
T_1 * V_25 )
{
void * V_19 ;
struct V_13 * V_22 = V_13 ( V_15 ) ;
if ( V_25 )
* V_25 = V_22 [ V_23 ] . V_25 ;
V_19 = V_22 [ V_23 ] . V_19 ;
V_22 [ V_23 ] . V_25 = F_11 ;
V_22 [ V_23 ] . V_19 = V_32 ;
return V_19 ;
}
static struct V_14 * F_21 ( struct V_48 * V_35 , int V_49 )
{
return F_22 ( V_35 -> V_50 [ V_49 ] ) ;
}
static struct V_14 * F_23 ( struct V_48 * V_35 ) __acquires( T_2 )
{
unsigned V_51 = F_24 ( * V_35 -> V_52 ) ;
F_25 () ;
return F_26 ( V_35 -> V_50 [ V_51 ] ) ;
}
static void F_27 ( struct V_14 * V_15 ) __releases( T_2 )
{
F_28 () ;
F_29 ( V_15 -> V_35 -> V_52 ) ;
}
static struct V_14 * F_30 ( struct V_48 * V_35 , int V_53 )
__acquires( T_2 )
{
F_25 () ;
return F_26 ( V_35 -> V_50 [ V_53 ] ) ;
}
static void F_31 ( struct V_14 * V_15 ) __releases( T_2 )
{
F_28 () ;
}
static int F_32 ( struct V_14 * V_15 , struct V_8 * V_54 )
{
unsigned long V_55 ;
T_3 V_56 ;
F_33 ( & V_15 -> V_57 , V_55 ) ;
if ( V_15 -> V_58 ) {
F_34 ( & V_15 -> V_57 , V_55 ) ;
return - V_24 ;
}
V_56 = V_15 -> V_59 ;
memcpy ( & V_15 -> V_60 [ V_56 ] , V_54 , sizeof( * V_54 ) ) ;
if ( ++ V_56 == V_15 -> V_17 )
V_56 = 0 ;
F_35 ( V_56 , V_15 -> V_61 ) ;
V_15 -> V_59 = V_56 ;
F_34 ( & V_15 -> V_57 , V_55 ) ;
return 0 ;
}
static T_4 * * F_36 ( struct V_62 * V_63 )
{
return ( ( void * ) V_63 ) + V_63 -> V_64 ;
}
static int F_37 ( unsigned V_65 )
{
unsigned V_66 = F_5 ( V_65 + V_67 , V_67 ) ;
return F_5 ( 8 * V_66 , V_67 - 8 ) ;
}
static struct V_62 *
F_38 ( unsigned V_68 , unsigned V_69 , T_5 V_70 )
{
struct V_62 * V_63 = F_39 ( sizeof( struct V_62 ) +
sizeof( T_4 * ) * F_37 ( V_69 ) +
sizeof( struct V_71 ) * V_68 , V_70 ) ;
if ( V_63 ) {
V_63 -> V_64 = F_40 ( struct V_62 , V_72 [ V_68 ] ) ;
V_63 -> V_73 = - 1 ;
V_63 -> V_74 = V_69 ;
V_63 -> V_75 = 0 ;
V_63 -> V_76 = 0ULL ;
V_63 -> V_77 = V_26 ;
}
return V_63 ;
}
void F_41 ( struct V_48 * V_35 , struct V_62 * V_63 )
{
const int V_78 = V_67 / 8 - 1 ;
int V_79 ;
T_4 * * V_80 = F_36 ( V_63 ) ;
T_6 V_81 = V_63 -> V_76 ;
if ( V_63 -> V_73 == 0 )
F_42 ( V_35 -> V_82 , V_80 [ 0 ] , V_81 ) ;
for ( V_79 = 0 ; V_79 < V_63 -> V_73 ; V_79 ++ ) {
T_4 * V_83 = V_80 [ V_79 ] ;
T_6 V_84 = F_43 ( V_83 [ V_78 ] ) ;
F_42 ( V_35 -> V_85 , V_83 , V_81 ) ;
V_81 = V_84 ;
}
F_44 ( V_63 ) ;
}
static void F_45 ( struct V_86 * V_86 )
{
struct V_87 * V_88 = V_86 -> V_89 -> V_90 ;
const int V_91 = F_46 ( V_86 ) ;
int V_92 = F_47 () ;
F_48 ( V_92 , & V_88 -> V_93 ) ;
F_49 ( V_92 , & V_88 -> V_93 , V_94 [ V_91 ] ) ;
F_50 ( V_92 , & V_88 -> V_93 , V_95 [ V_91 ] , F_51 ( V_86 ) ) ;
F_52 ( & V_88 -> V_93 , V_91 ) ;
F_53 () ;
}
static void F_54 ( struct V_86 * V_86 , unsigned long V_77 )
{
struct V_87 * V_88 = V_86 -> V_89 -> V_90 ;
const int V_91 = F_46 ( V_86 ) ;
unsigned long V_96 = V_26 - V_77 ;
int V_92 = F_47 () ;
F_50 ( V_92 , & V_88 -> V_93 , V_97 [ V_91 ] , V_96 ) ;
F_48 ( V_92 , & V_88 -> V_93 ) ;
F_55 ( & V_88 -> V_93 , V_91 ) ;
F_53 () ;
}
static void F_56 ( struct V_14 * V_15 , void * V_19 ,
struct V_30 * V_31 )
{
struct V_62 * V_63 = V_19 ;
struct V_86 * V_86 = V_63 -> V_98 ;
T_3 V_45 = F_13 ( & V_31 -> V_45 ) >> 1 ;
if ( F_57 ( V_45 ) ) {
if ( ! ( V_45 & V_99 ||
V_86 -> V_100 & V_101 ) &&
( V_26 - V_63 -> V_77 ) < V_102 ) {
if ( ! F_58 ( & V_15 -> V_28 ) )
F_59 ( & V_15 -> V_28 ,
& V_15 -> V_103 ) ;
F_60 ( & V_63 -> V_104 , & V_15 -> V_105 ) ;
F_19 ( & V_15 -> V_28 ) ;
return;
}
}
if ( V_63 -> V_75 ) {
F_61 ( V_15 -> V_38 , V_63 -> V_72 , V_63 -> V_75 ,
F_46 ( V_86 ) ? V_106 : V_107 ) ;
F_54 ( V_86 , V_63 -> V_77 ) ;
}
F_41 ( V_15 -> V_35 , V_63 ) ;
if ( V_45 )
F_62 ( V_86 , - V_108 ) ;
else
F_62 ( V_86 , 0 ) ;
}
int F_63 ( struct V_48 * V_35 , struct V_62 * V_63 , int V_109 ,
T_5 V_70 )
{
struct V_110 * V_111 ;
int V_74 = V_109 ;
struct V_71 * V_72 = V_63 -> V_72 ;
int V_112 = F_64 ( V_72 ) ;
T_7 V_113 = F_65 ( V_72 ) ;
int V_64 = F_66 ( V_113 ) ;
T_4 * V_83 ;
T_4 * * V_80 = F_36 ( V_63 ) ;
T_6 V_81 ;
int V_66 , V_79 ;
V_74 -= ( V_67 - V_64 ) ;
if ( V_74 <= 0 )
return V_109 ;
V_112 -= ( V_67 - V_64 ) ;
if ( V_112 ) {
V_113 += ( V_67 - V_64 ) ;
} else {
V_72 = F_67 ( V_72 ) ;
V_113 = F_65 ( V_72 ) ;
V_112 = F_64 ( V_72 ) ;
}
if ( V_74 <= V_67 ) {
V_63 -> V_76 = V_113 ;
return V_109 ;
}
V_66 = F_5 ( V_74 , V_67 ) ;
if ( V_66 <= ( 256 / 8 ) ) {
V_111 = V_35 -> V_82 ;
V_63 -> V_73 = 0 ;
} else {
V_111 = V_35 -> V_85 ;
V_63 -> V_73 = 1 ;
}
V_83 = F_68 ( V_111 , V_70 , & V_81 ) ;
if ( ! V_83 ) {
V_63 -> V_76 = V_113 ;
V_63 -> V_73 = - 1 ;
return ( V_109 - V_74 ) + V_67 ;
}
V_80 [ 0 ] = V_83 ;
V_63 -> V_76 = V_81 ;
V_79 = 0 ;
for (; ; ) {
if ( V_79 == V_67 / 8 ) {
T_4 * V_114 = V_83 ;
V_83 = F_68 ( V_111 , V_70 , & V_81 ) ;
if ( ! V_83 )
return V_109 - V_74 ;
V_80 [ V_63 -> V_73 ++ ] = V_83 ;
V_83 [ 0 ] = V_114 [ V_79 - 1 ] ;
V_114 [ V_79 - 1 ] = F_69 ( V_81 ) ;
V_79 = 1 ;
}
V_83 [ V_79 ++ ] = F_69 ( V_113 ) ;
V_112 -= V_67 ;
V_113 += V_67 ;
V_74 -= V_67 ;
if ( V_74 <= 0 )
break;
if ( V_112 > 0 )
continue;
F_70 ( V_112 < 0 ) ;
V_72 = F_67 ( V_72 ) ;
V_113 = F_65 ( V_72 ) ;
V_112 = F_64 ( V_72 ) ;
}
return V_109 ;
}
static int F_71 ( struct V_86 * V_86 , struct V_14 * V_15 ,
int V_115 )
{
struct V_86 * V_116 = F_72 ( V_86 , V_115 >> 9 , V_117 , NULL ) ;
if ( ! V_116 )
return - V_118 ;
F_73 ( V_116 , V_86 ) ;
if ( ! F_58 ( & V_15 -> V_28 ) )
F_59 ( & V_15 -> V_28 , & V_15 -> V_103 ) ;
F_74 ( & V_15 -> V_119 , V_116 ) ;
F_74 ( & V_15 -> V_119 , V_86 ) ;
F_19 ( & V_15 -> V_28 ) ;
return 0 ;
}
static int F_75 ( struct V_14 * V_15 , struct V_62 * V_63 ,
struct V_86 * V_86 , enum V_120 V_121 , int V_122 )
{
struct V_123 V_124 , V_125 ;
struct V_126 V_127 ;
struct V_71 * V_72 = NULL ;
int V_74 = 0 , V_128 = 0 , V_129 = V_86 -> V_130 . V_131 ;
int V_132 = 1 ;
if ( V_15 -> V_35 -> V_133 )
V_129 = V_15 -> V_35 -> V_133 -
( ( V_86 -> V_130 . V_134 << 9 ) &
( V_15 -> V_35 -> V_133 - 1 ) ) ;
F_76 ( V_63 -> V_72 , V_122 ) ;
F_77 (bvec, bio, iter) {
if ( ! V_132 && F_78 ( & V_125 , & V_124 ) ) {
V_72 -> V_74 += V_124 . V_135 ;
} else {
if ( ! V_132 && F_79 ( & V_125 , & V_124 ) )
return F_71 ( V_86 , V_15 ,
V_74 ) ;
V_72 = V_72 ? V_72 + 1 : V_63 -> V_72 ;
F_80 ( V_72 , V_124 . V_136 ,
V_124 . V_135 , V_124 . V_137 ) ;
V_128 ++ ;
}
if ( V_129 - V_74 < V_124 . V_135 )
return F_71 ( V_86 , V_15 , V_129 ) ;
V_74 += V_124 . V_135 ;
V_125 = V_124 ;
V_132 = 0 ;
}
V_63 -> V_75 = V_128 ;
F_81 ( V_72 ) ;
if ( F_82 ( V_15 -> V_38 , V_63 -> V_72 , V_63 -> V_75 , V_121 ) == 0 )
return - V_118 ;
F_70 ( V_74 != V_86 -> V_130 . V_131 ) ;
return V_74 ;
}
static int F_83 ( struct V_14 * V_15 , struct V_138 * V_139 ,
struct V_86 * V_86 , struct V_62 * V_63 , int V_23 )
{
struct V_140 * V_141 =
(struct V_140 * ) F_36 ( V_63 ) [ 0 ] ;
struct V_8 * V_142 = & V_15 -> V_60 [ V_15 -> V_59 ] ;
V_141 -> V_143 = F_84 ( 0 ) ;
V_141 -> V_144 = F_84 ( V_86 -> V_130 . V_131 >> V_139 -> V_145 ) ;
V_141 -> V_146 = F_69 ( F_85 ( V_139 , V_86 -> V_130 . V_134 ) ) ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_147 . V_148 = V_149 ;
V_142 -> V_147 . V_39 = V_23 ;
V_142 -> V_147 . V_150 = F_84 ( V_139 -> V_151 ) ;
V_142 -> V_147 . V_152 = F_69 ( V_63 -> V_76 ) ;
V_142 -> V_147 . V_153 = 0 ;
V_142 -> V_147 . V_154 = F_84 ( V_155 ) ;
if ( ++ V_15 -> V_59 == V_15 -> V_17 )
V_15 -> V_59 = 0 ;
F_35 ( V_15 -> V_59 , V_15 -> V_61 ) ;
return 0 ;
}
static int F_86 ( struct V_14 * V_15 , struct V_138 * V_139 ,
int V_23 )
{
struct V_8 * V_142 = & V_15 -> V_60 [ V_15 -> V_59 ] ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_156 . V_148 = V_157 ;
V_142 -> V_156 . V_39 = V_23 ;
V_142 -> V_156 . V_150 = F_84 ( V_139 -> V_151 ) ;
if ( ++ V_15 -> V_59 == V_15 -> V_17 )
V_15 -> V_59 = 0 ;
F_35 ( V_15 -> V_59 , V_15 -> V_61 ) ;
return 0 ;
}
int F_87 ( struct V_14 * V_15 , struct V_138 * V_139 )
{
int V_23 = F_6 ( V_15 , ( void * ) V_33 ,
F_11 , V_158 ) ;
if ( F_57 ( V_23 < 0 ) )
return V_23 ;
return F_86 ( V_15 , V_139 , V_23 ) ;
}
static int F_88 ( struct V_14 * V_15 , struct V_62 * V_63 )
{
struct V_86 * V_86 = V_63 -> V_98 ;
struct V_138 * V_139 = V_86 -> V_89 -> V_90 -> V_159 ;
struct V_8 * V_142 ;
int V_23 ;
T_3 V_160 ;
T_8 V_161 ;
V_23 = F_6 ( V_15 , V_63 , F_56 , V_158 ) ;
if ( F_57 ( V_23 < 0 ) )
return V_23 ;
if ( V_86 -> V_100 & V_162 )
return F_83 ( V_15 , V_139 , V_86 , V_63 , V_23 ) ;
if ( ( V_86 -> V_100 & V_163 ) && ! V_63 -> V_75 )
return F_86 ( V_15 , V_139 , V_23 ) ;
V_160 = 0 ;
if ( V_86 -> V_100 & V_164 )
V_160 |= V_165 ;
if ( V_86 -> V_100 & ( V_166 | V_167 ) )
V_160 |= V_168 ;
V_161 = 0 ;
if ( V_86 -> V_100 & V_167 )
V_161 |= V_169 ;
V_142 = & V_15 -> V_60 [ V_15 -> V_59 ] ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_91 . V_148 = F_46 ( V_86 ) ? V_170 : V_171 ;
V_142 -> V_91 . V_39 = V_23 ;
V_142 -> V_91 . V_150 = F_84 ( V_139 -> V_151 ) ;
V_142 -> V_91 . V_152 = F_69 ( F_65 ( V_63 -> V_72 ) ) ;
V_142 -> V_91 . V_172 = F_69 ( V_63 -> V_76 ) ;
V_142 -> V_91 . V_146 = F_69 ( F_85 ( V_139 , V_86 -> V_130 . V_134 ) ) ;
V_142 -> V_91 . V_74 =
F_89 ( ( V_86 -> V_130 . V_131 >> V_139 -> V_145 ) - 1 ) ;
V_142 -> V_91 . V_160 = F_89 ( V_160 ) ;
V_142 -> V_91 . V_161 = F_84 ( V_161 ) ;
if ( ++ V_15 -> V_59 == V_15 -> V_17 )
V_15 -> V_59 = 0 ;
F_35 ( V_15 -> V_59 , V_15 -> V_61 ) ;
return 0 ;
}
static int F_90 ( struct V_14 * V_15 , struct V_138 * V_139 ,
struct V_86 * V_86 )
{
struct V_62 * V_63 ;
int V_122 = F_91 ( V_139 -> V_173 , V_86 ) ;
int V_44 ;
if ( ( V_86 -> V_100 & V_163 ) && V_122 ) {
V_44 = F_87 ( V_15 , V_139 ) ;
if ( V_44 )
return V_44 ;
}
V_63 = F_38 ( V_122 , V_86 -> V_130 . V_131 , V_117 ) ;
if ( ! V_63 )
return - V_118 ;
V_63 -> V_98 = V_86 ;
if ( V_86 -> V_100 & V_162 ) {
void * V_141 ;
V_141 = F_68 ( V_15 -> V_35 -> V_82 ,
V_117 ,
& V_63 -> V_76 ) ;
if ( ! V_141 ) {
V_44 = - V_118 ;
goto V_174;
}
F_36 ( V_63 ) [ 0 ] = ( T_4 * ) V_141 ;
V_63 -> V_73 = 0 ;
} else if ( V_122 ) {
V_44 = F_75 ( V_15 , V_63 , V_86 ,
F_46 ( V_86 ) ? V_106 : V_107 ,
V_122 ) ;
if ( V_44 <= 0 )
goto V_174;
if ( F_63 ( V_15 -> V_35 , V_63 , V_44 , V_117 ) !=
V_44 ) {
V_44 = - V_118 ;
goto V_174;
}
F_45 ( V_86 ) ;
}
if ( F_57 ( F_88 ( V_15 , V_63 ) ) ) {
if ( ! F_58 ( & V_15 -> V_28 ) )
F_59 ( & V_15 -> V_28 , & V_15 -> V_103 ) ;
F_60 ( & V_63 -> V_104 , & V_15 -> V_105 ) ;
}
return 0 ;
V_174:
F_41 ( V_15 -> V_35 , V_63 ) ;
return V_44 ;
}
static int F_92 ( struct V_14 * V_15 )
{
T_3 V_175 , V_176 ;
V_175 = V_15 -> V_177 ;
V_176 = V_15 -> V_178 ;
for (; ; ) {
void * V_19 ;
T_1 V_25 ;
struct V_30 V_31 = V_15 -> V_179 [ V_175 ] ;
if ( ( F_93 ( V_31 . V_45 ) & 1 ) != V_176 )
break;
V_15 -> V_180 = F_93 ( V_31 . V_180 ) ;
if ( ++ V_175 == V_15 -> V_17 ) {
V_175 = 0 ;
V_176 = ! V_176 ;
}
V_19 = F_17 ( V_15 , V_31 . V_39 , & V_25 ) ;
V_25 ( V_15 , V_19 , & V_31 ) ;
}
if ( V_175 == V_15 -> V_177 && V_176 == V_15 -> V_178 )
return 0 ;
F_35 ( V_175 , V_15 -> V_61 + V_15 -> V_35 -> V_181 ) ;
V_15 -> V_177 = V_175 ;
V_15 -> V_178 = V_176 ;
V_15 -> V_182 = 1 ;
return 1 ;
}
static void F_94 ( struct V_183 * V_184 , struct V_86 * V_86 )
{
struct V_138 * V_139 = V_184 -> V_185 ;
struct V_14 * V_15 = F_23 ( V_139 -> V_35 ) ;
int V_44 = - V_24 ;
if ( ! V_15 ) {
F_27 ( NULL ) ;
F_62 ( V_86 , - V_108 ) ;
return;
}
F_95 ( & V_15 -> V_57 ) ;
if ( ! V_15 -> V_58 && F_96 ( & V_15 -> V_119 ) )
V_44 = F_90 ( V_15 , V_139 , V_86 ) ;
if ( F_57 ( V_44 ) ) {
if ( ! F_58 ( & V_15 -> V_28 ) )
F_59 ( & V_15 -> V_28 , & V_15 -> V_103 ) ;
F_74 ( & V_15 -> V_119 , V_86 ) ;
}
F_92 ( V_15 ) ;
F_97 ( & V_15 -> V_57 ) ;
F_27 ( V_15 ) ;
}
static T_9 F_98 ( int V_186 , void * V_187 )
{
T_9 V_44 ;
struct V_14 * V_15 = V_187 ;
F_99 ( & V_15 -> V_57 ) ;
F_92 ( V_15 ) ;
V_44 = V_15 -> V_182 ? V_188 : V_189 ;
V_15 -> V_182 = 0 ;
F_100 ( & V_15 -> V_57 ) ;
return V_44 ;
}
static T_9 F_101 ( int V_186 , void * V_187 )
{
struct V_14 * V_15 = V_187 ;
struct V_30 V_31 = V_15 -> V_179 [ V_15 -> V_177 ] ;
if ( ( F_93 ( V_31 . V_45 ) & 1 ) != V_15 -> V_178 )
return V_189 ;
return V_190 ;
}
static void F_102 ( struct V_14 * V_15 , int V_23 )
{
F_95 ( & V_15 -> V_57 ) ;
F_20 ( V_15 , V_23 , NULL ) ;
F_97 ( & V_15 -> V_57 ) ;
}
static void F_103 ( struct V_14 * V_15 , void * V_19 ,
struct V_30 * V_31 )
{
struct V_191 * V_43 = V_19 ;
V_43 -> V_44 = F_15 ( & V_31 -> V_44 ) ;
V_43 -> V_45 = F_13 ( & V_31 -> V_45 ) >> 1 ;
F_104 ( V_43 -> V_192 ) ;
}
static int F_105 ( struct V_48 * V_35 , int V_53 ,
struct V_8 * V_54 ,
T_8 * V_44 , unsigned V_21 )
{
int V_23 , V_193 ;
struct V_191 V_43 ;
struct V_14 * V_15 ;
V_15 = F_30 ( V_35 , V_53 ) ;
if ( ! V_15 ) {
F_31 ( V_15 ) ;
return - V_194 ;
}
V_43 . V_192 = V_195 ;
V_43 . V_45 = - V_29 ;
V_23 = F_6 ( V_15 , & V_43 , F_103 , V_21 ) ;
if ( V_23 < 0 ) {
F_31 ( V_15 ) ;
return V_23 ;
}
V_54 -> V_156 . V_39 = V_23 ;
F_106 ( V_196 ) ;
V_193 = F_32 ( V_15 , V_54 ) ;
if ( V_193 ) {
F_17 ( V_15 , V_23 , NULL ) ;
F_31 ( V_15 ) ;
F_106 ( V_197 ) ;
return V_193 ;
}
F_31 ( V_15 ) ;
F_107 ( V_21 ) ;
if ( V_43 . V_45 == - V_29 ) {
V_15 = F_30 ( V_35 , V_53 ) ;
if ( V_15 )
F_102 ( V_15 , V_23 ) ;
F_31 ( V_15 ) ;
return - V_29 ;
}
if ( V_44 )
* V_44 = V_43 . V_44 ;
return V_43 . V_45 ;
}
static int F_108 ( struct V_14 * V_15 ,
struct V_8 * V_54 ,
struct V_42 * V_43 , unsigned V_21 )
{
int V_23 ;
V_23 = F_9 ( V_15 , V_43 , F_14 , V_21 ) ;
if ( V_23 < 0 )
return V_23 ;
V_43 -> V_45 = - V_29 ;
V_54 -> V_156 . V_39 = V_23 ;
return F_32 ( V_15 , V_54 ) ;
}
int F_109 ( struct V_48 * V_35 , struct V_8 * V_54 ,
T_8 * V_44 )
{
return F_105 ( V_35 , 0 , V_54 , V_44 , V_198 ) ;
}
int F_110 ( struct V_48 * V_35 , struct V_8 * V_54 ,
T_8 * V_44 )
{
return F_105 ( V_35 , F_111 () + 1 , V_54 , V_44 ,
V_158 ) ;
}
static int F_112 ( struct V_48 * V_35 ,
struct V_8 * V_54 , struct V_42 * V_43 )
{
return F_108 ( F_21 ( V_35 , 0 ) , V_54 , V_43 ,
V_198 ) ;
}
static int F_113 ( struct V_48 * V_35 , T_10 V_148 , T_3 V_199 )
{
int V_45 ;
struct V_8 V_200 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_201 . V_148 = V_148 ;
V_200 . V_201 . V_49 = F_89 ( V_199 ) ;
V_45 = F_109 ( V_35 , & V_200 , NULL ) ;
if ( V_45 )
return - V_108 ;
return 0 ;
}
static int F_114 ( struct V_48 * V_35 , T_3 V_49 ,
struct V_14 * V_15 )
{
int V_45 ;
struct V_8 V_200 ;
int V_55 = V_202 | V_203 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_204 . V_148 = V_205 ;
V_200 . V_204 . V_152 = F_69 ( V_15 -> V_206 ) ;
V_200 . V_204 . V_207 = F_89 ( V_49 ) ;
V_200 . V_204 . V_208 = F_89 ( V_15 -> V_17 - 1 ) ;
V_200 . V_204 . V_209 = F_89 ( V_55 ) ;
V_200 . V_204 . V_210 = F_89 ( V_15 -> V_211 ) ;
V_45 = F_109 ( V_35 , & V_200 , NULL ) ;
if ( V_45 )
return - V_108 ;
return 0 ;
}
static int F_115 ( struct V_48 * V_35 , T_3 V_49 ,
struct V_14 * V_15 )
{
int V_45 ;
struct V_8 V_200 ;
int V_55 = V_202 | V_212 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_213 . V_148 = V_214 ;
V_200 . V_213 . V_152 = F_69 ( V_15 -> V_215 ) ;
V_200 . V_213 . V_216 = F_89 ( V_49 ) ;
V_200 . V_213 . V_208 = F_89 ( V_15 -> V_17 - 1 ) ;
V_200 . V_213 . V_217 = F_89 ( V_55 ) ;
V_200 . V_213 . V_207 = F_89 ( V_49 ) ;
V_45 = F_109 ( V_35 , & V_200 , NULL ) ;
if ( V_45 )
return - V_108 ;
return 0 ;
}
static int F_116 ( struct V_48 * V_35 , T_3 V_207 )
{
return F_113 ( V_35 , V_218 , V_207 ) ;
}
static int F_117 ( struct V_48 * V_35 , T_3 V_216 )
{
return F_113 ( V_35 , V_219 , V_216 ) ;
}
int F_118 ( struct V_48 * V_35 , unsigned V_150 , unsigned V_220 ,
T_6 V_113 )
{
struct V_8 V_200 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_221 . V_148 = V_222 ;
V_200 . V_221 . V_150 = F_84 ( V_150 ) ;
V_200 . V_221 . V_152 = F_69 ( V_113 ) ;
V_200 . V_221 . V_220 = F_84 ( V_220 ) ;
return F_109 ( V_35 , & V_200 , NULL ) ;
}
int F_119 ( struct V_48 * V_35 , unsigned V_223 , unsigned V_150 ,
T_6 V_113 , T_8 * V_44 )
{
struct V_8 V_200 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_224 . V_148 = V_225 ;
V_200 . V_224 . V_150 = F_84 ( V_150 ) ;
V_200 . V_224 . V_152 = F_69 ( V_113 ) ;
V_200 . V_224 . V_223 = F_84 ( V_223 ) ;
return F_109 ( V_35 , & V_200 , V_44 ) ;
}
int F_120 ( struct V_48 * V_35 , unsigned V_223 , unsigned V_226 ,
T_6 V_113 , T_8 * V_44 )
{
struct V_8 V_200 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_224 . V_148 = V_227 ;
V_200 . V_224 . V_152 = F_69 ( V_113 ) ;
V_200 . V_224 . V_223 = F_84 ( V_223 ) ;
V_200 . V_224 . V_226 = F_84 ( V_226 ) ;
return F_109 ( V_35 , & V_200 , V_44 ) ;
}
static void V_7 ( int V_23 , struct V_14 * V_15 )
{
int V_228 ;
struct V_8 V_54 ;
struct V_48 * V_35 = V_15 -> V_35 ;
struct V_13 * V_22 = V_13 ( V_15 ) ;
struct V_14 * V_229 ;
if ( ! V_15 -> V_49 || V_22 [ V_23 ] . V_27 ) {
if ( F_121 ( & V_35 -> V_230 ) )
return;
F_122 ( & V_35 -> V_104 ) ;
F_12 ( & V_35 -> V_231 -> V_35 ,
L_4 , V_23 ,
V_15 -> V_49 ) ;
V_35 -> V_232 = V_233 ;
F_123 ( V_234 , & V_35 -> V_230 ) ;
return;
}
if ( ! V_35 -> V_36 )
return;
V_229 = F_26 ( V_35 -> V_50 [ 0 ] ) ;
V_228 = F_6 ( V_229 , V_34 , F_11 ,
V_198 ) ;
if ( V_228 < 0 )
return;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . abort . V_148 = V_235 ;
V_54 . abort . V_236 = V_23 ;
V_54 . abort . V_216 = F_89 ( V_15 -> V_49 ) ;
V_54 . abort . V_39 = V_228 ;
-- V_35 -> V_36 ;
V_22 [ V_23 ] . V_27 = 1 ;
V_22 [ V_23 ] . V_21 = V_26 + V_198 ;
F_12 ( V_15 -> V_38 , L_5 , V_23 ,
V_15 -> V_49 ) ;
F_32 ( V_229 , & V_54 ) ;
}
static void F_124 ( struct V_14 * V_15 , bool V_21 )
{
int V_18 = V_15 -> V_17 - 1 ;
struct V_13 * V_22 = V_13 ( V_15 ) ;
unsigned long V_237 = V_26 ;
int V_23 ;
F_125 (cmdid, nvmeq->cmdid_data, depth) {
void * V_19 ;
T_1 V_25 ;
static struct V_30 V_31 = {
. V_45 = F_89 ( V_238 << 1 ) ,
} ;
if ( V_21 && ! F_126 ( V_237 , V_22 [ V_23 ] . V_21 ) )
continue;
if ( V_22 [ V_23 ] . V_19 == V_32 )
continue;
if ( V_21 && V_15 -> V_35 -> V_239 ) {
V_7 ( V_23 , V_15 ) ;
continue;
}
F_12 ( V_15 -> V_38 , L_6 , V_23 ,
V_15 -> V_49 ) ;
V_19 = F_20 ( V_15 , V_23 , & V_25 ) ;
V_25 ( V_15 , V_19 , & V_31 ) ;
}
}
static void F_127 ( struct V_240 * V_241 )
{
struct V_14 * V_15 = F_128 ( V_241 , struct V_14 , V_242 ) ;
F_95 ( & V_15 -> V_57 ) ;
while ( F_129 ( & V_15 -> V_119 ) ) {
struct V_86 * V_86 = F_130 ( & V_15 -> V_119 ) ;
F_62 ( V_86 , - V_108 ) ;
}
while ( ! F_131 ( & V_15 -> V_105 ) ) {
static struct V_30 V_31 = {
. V_45 = F_89 (
( V_238 | V_99 ) << 1 ) ,
} ;
struct V_62 * V_63 = F_132 ( & V_15 -> V_105 ,
struct V_62 ,
V_104 ) ;
F_133 ( & V_63 -> V_104 ) ;
F_56 ( V_15 , V_63 , & V_31 ) ;
}
F_97 ( & V_15 -> V_57 ) ;
F_134 ( V_15 -> V_38 , F_135 ( V_15 -> V_17 ) ,
( void * ) V_15 -> V_179 , V_15 -> V_206 ) ;
F_134 ( V_15 -> V_38 , F_136 ( V_15 -> V_17 ) ,
V_15 -> V_60 , V_15 -> V_215 ) ;
if ( V_15 -> V_49 )
F_137 ( V_15 -> V_243 ) ;
F_44 ( V_15 ) ;
}
static void F_138 ( struct V_48 * V_35 , int V_244 )
{
int V_79 ;
for ( V_79 = V_35 -> V_245 - 1 ; V_79 >= V_244 ; V_79 -- ) {
struct V_14 * V_15 = F_21 ( V_35 , V_79 ) ;
F_139 ( V_35 -> V_50 [ V_79 ] , NULL ) ;
F_140 ( & V_15 -> V_242 , F_127 ) ;
V_35 -> V_245 -- ;
}
}
static int F_141 ( struct V_14 * V_15 )
{
int V_246 = V_15 -> V_35 -> V_247 [ V_15 -> V_211 ] . V_246 ;
F_95 ( & V_15 -> V_57 ) ;
if ( V_15 -> V_58 ) {
F_97 ( & V_15 -> V_57 ) ;
return 1 ;
}
V_15 -> V_58 = 1 ;
V_15 -> V_35 -> V_248 -- ;
F_97 ( & V_15 -> V_57 ) ;
F_142 ( V_246 , NULL ) ;
F_143 ( V_246 , V_15 ) ;
return 0 ;
}
static void F_144 ( struct V_14 * V_15 )
{
F_95 ( & V_15 -> V_57 ) ;
F_92 ( V_15 ) ;
F_124 ( V_15 , false ) ;
F_97 ( & V_15 -> V_57 ) ;
}
static void F_145 ( struct V_48 * V_35 , int V_49 )
{
struct V_14 * V_15 = F_21 ( V_35 , V_49 ) ;
if ( ! V_15 )
return;
if ( F_141 ( V_15 ) )
return;
if ( V_49 && F_146 ( & V_35 -> V_249 -> V_250 ) != - 1 ) {
F_117 ( V_35 , V_49 ) ;
F_116 ( V_35 , V_49 ) ;
}
F_144 ( V_15 ) ;
}
static struct V_14 * F_147 ( struct V_48 * V_35 , int V_49 ,
int V_18 , int V_246 )
{
struct V_251 * V_252 = & V_35 -> V_231 -> V_35 ;
unsigned V_253 = F_4 ( V_18 ) ;
struct V_14 * V_15 = F_148 ( sizeof( * V_15 ) + V_253 , V_254 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_179 = F_149 ( V_252 , F_135 ( V_18 ) ,
& V_15 -> V_206 , V_254 ) ;
if ( ! V_15 -> V_179 )
goto V_255;
memset ( ( void * ) V_15 -> V_179 , 0 , F_135 ( V_18 ) ) ;
V_15 -> V_60 = F_149 ( V_252 , F_136 ( V_18 ) ,
& V_15 -> V_215 , V_254 ) ;
if ( ! V_15 -> V_60 )
goto V_256;
if ( V_49 && ! F_150 ( & V_15 -> V_243 , V_254 ) )
goto V_257;
V_15 -> V_38 = V_252 ;
V_15 -> V_35 = V_35 ;
snprintf ( V_15 -> V_258 , sizeof( V_15 -> V_258 ) , L_7 ,
V_35 -> V_259 , V_49 ) ;
F_151 ( & V_15 -> V_57 ) ;
V_15 -> V_177 = 0 ;
V_15 -> V_178 = 1 ;
F_152 ( & V_15 -> V_28 ) ;
F_153 ( & V_15 -> V_103 , V_260 ) ;
F_154 ( & V_15 -> V_119 ) ;
F_155 ( & V_15 -> V_105 ) ;
V_15 -> V_61 = & V_35 -> V_261 [ V_49 * 2 * V_35 -> V_181 ] ;
V_15 -> V_17 = V_18 ;
V_15 -> V_211 = V_246 ;
V_15 -> V_49 = V_49 ;
V_15 -> V_58 = 1 ;
V_35 -> V_245 ++ ;
F_139 ( V_35 -> V_50 [ V_49 ] , V_15 ) ;
return V_15 ;
V_257:
F_134 ( V_252 , F_136 ( V_18 ) , ( void * ) V_15 -> V_60 ,
V_15 -> V_215 ) ;
V_256:
F_134 ( V_252 , F_135 ( V_18 ) , ( void * ) V_15 -> V_179 ,
V_15 -> V_206 ) ;
V_255:
F_44 ( V_15 ) ;
return NULL ;
}
static int F_156 ( struct V_48 * V_35 , struct V_14 * V_15 ,
const char * V_262 )
{
if ( V_263 )
return F_157 ( V_35 -> V_247 [ V_15 -> V_211 ] . V_246 ,
F_101 , F_98 , V_264 ,
V_262 , V_15 ) ;
return F_158 ( V_35 -> V_247 [ V_15 -> V_211 ] . V_246 , F_98 ,
V_264 , V_262 , V_15 ) ;
}
static void F_159 ( struct V_14 * V_15 , T_3 V_49 )
{
struct V_48 * V_35 = V_15 -> V_35 ;
unsigned V_253 = F_4 ( V_15 -> V_17 ) ;
V_15 -> V_59 = 0 ;
V_15 -> V_177 = 0 ;
V_15 -> V_178 = 1 ;
V_15 -> V_61 = & V_35 -> V_261 [ V_49 * 2 * V_35 -> V_181 ] ;
memset ( V_15 -> V_16 , 0 , V_253 ) ;
memset ( ( void * ) V_15 -> V_179 , 0 , F_135 ( V_15 -> V_17 ) ) ;
F_124 ( V_15 , false ) ;
V_15 -> V_58 = 0 ;
V_35 -> V_248 ++ ;
}
static int F_160 ( struct V_14 * V_15 , int V_49 )
{
struct V_48 * V_35 = V_15 -> V_35 ;
int V_44 ;
V_44 = F_114 ( V_35 , V_49 , V_15 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_115 ( V_35 , V_49 , V_15 ) ;
if ( V_44 < 0 )
goto V_265;
V_44 = F_156 ( V_35 , V_15 , V_15 -> V_258 ) ;
if ( V_44 < 0 )
goto V_266;
F_95 ( & V_15 -> V_57 ) ;
F_159 ( V_15 , V_49 ) ;
F_97 ( & V_15 -> V_57 ) ;
return V_44 ;
V_266:
F_117 ( V_35 , V_49 ) ;
V_265:
F_116 ( V_35 , V_49 ) ;
return V_44 ;
}
static int F_161 ( struct V_48 * V_35 , T_7 V_267 , bool V_268 )
{
unsigned long V_21 ;
T_8 V_269 = V_268 ? V_270 : 0 ;
V_21 = ( ( F_162 ( V_267 ) + 1 ) * V_271 / 2 ) + V_26 ;
while ( ( F_146 ( & V_35 -> V_249 -> V_250 ) & V_270 ) != V_269 ) {
F_163 ( 100 ) ;
if ( F_164 ( V_195 ) )
return - V_29 ;
if ( F_126 ( V_26 , V_21 ) ) {
F_165 ( & V_35 -> V_231 -> V_35 ,
L_8 ) ;
return - V_194 ;
}
}
return 0 ;
}
static int F_166 ( struct V_48 * V_35 , T_7 V_267 )
{
T_8 V_272 = F_146 ( & V_35 -> V_249 -> V_272 ) ;
if ( V_272 & V_273 )
F_35 ( V_272 & ~ V_273 , & V_35 -> V_249 -> V_272 ) ;
return F_161 ( V_35 , V_267 , false ) ;
}
static int F_167 ( struct V_48 * V_35 , T_7 V_267 )
{
return F_161 ( V_35 , V_267 , true ) ;
}
static int F_168 ( struct V_48 * V_35 )
{
unsigned long V_21 ;
T_8 V_272 ;
V_272 = ( F_146 ( & V_35 -> V_249 -> V_272 ) & ~ V_274 ) | V_275 ;
F_35 ( V_272 , & V_35 -> V_249 -> V_272 ) ;
V_21 = 2 * V_271 + V_26 ;
while ( ( F_146 ( & V_35 -> V_249 -> V_250 ) & V_276 ) !=
V_277 ) {
F_163 ( 100 ) ;
if ( F_164 ( V_195 ) )
return - V_29 ;
if ( F_126 ( V_26 , V_21 ) ) {
F_165 ( & V_35 -> V_231 -> V_35 ,
L_9 ) ;
return - V_194 ;
}
}
return 0 ;
}
static int F_169 ( struct V_48 * V_35 )
{
int V_44 ;
T_8 V_278 ;
T_7 V_267 = F_170 ( & V_35 -> V_249 -> V_267 ) ;
struct V_14 * V_15 ;
V_44 = F_166 ( V_35 , V_267 ) ;
if ( V_44 < 0 )
return V_44 ;
V_15 = F_21 ( V_35 , 0 ) ;
if ( ! V_15 ) {
V_15 = F_147 ( V_35 , 0 , 64 , 0 ) ;
if ( ! V_15 )
return - V_118 ;
}
V_278 = V_15 -> V_17 - 1 ;
V_278 |= V_278 << 16 ;
V_35 -> V_279 = V_273 | V_280 ;
V_35 -> V_279 |= ( V_281 - 12 ) << V_282 ;
V_35 -> V_279 |= V_283 | V_284 ;
V_35 -> V_279 |= V_285 | V_286 ;
F_35 ( V_278 , & V_35 -> V_249 -> V_278 ) ;
F_171 ( V_15 -> V_215 , & V_35 -> V_249 -> V_287 ) ;
F_171 ( V_15 -> V_206 , & V_35 -> V_249 -> V_288 ) ;
F_35 ( V_35 -> V_279 , & V_35 -> V_249 -> V_272 ) ;
V_44 = F_167 ( V_35 , V_267 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_156 ( V_35 , V_15 , V_15 -> V_258 ) ;
if ( V_44 )
return V_44 ;
F_95 ( & V_15 -> V_57 ) ;
F_159 ( V_15 , 0 ) ;
F_97 ( & V_15 -> V_57 ) ;
return V_44 ;
}
struct V_62 * F_172 ( struct V_48 * V_35 , int V_289 ,
unsigned long V_290 , unsigned V_74 )
{
int V_79 , V_291 , V_292 , V_75 , V_64 ;
struct V_71 * V_72 ;
struct V_293 * * V_294 ;
struct V_62 * V_63 ;
if ( V_290 & 3 )
return F_173 ( - V_295 ) ;
if ( ! V_74 || V_74 > V_296 - V_67 )
return F_173 ( - V_295 ) ;
V_64 = F_66 ( V_290 ) ;
V_292 = F_5 ( V_64 + V_74 , V_67 ) ;
V_294 = F_174 ( V_292 , sizeof( * V_294 ) , V_254 ) ;
if ( ! V_294 )
return F_173 ( - V_118 ) ;
V_291 = F_175 ( V_290 , V_292 , 1 , V_294 ) ;
if ( V_291 < V_292 ) {
V_292 = V_291 ;
V_291 = - V_297 ;
goto V_298;
}
V_63 = F_38 ( V_292 , V_74 , V_254 ) ;
V_72 = V_63 -> V_72 ;
F_76 ( V_72 , V_292 ) ;
for ( V_79 = 0 ; V_79 < V_292 ; V_79 ++ ) {
F_80 ( & V_72 [ V_79 ] , V_294 [ V_79 ] ,
F_176 ( unsigned , V_74 , V_67 - V_64 ) ,
V_64 ) ;
V_74 -= ( V_67 - V_64 ) ;
V_64 = 0 ;
}
F_81 ( & V_72 [ V_79 - 1 ] ) ;
V_63 -> V_75 = V_292 ;
V_291 = - V_118 ;
V_75 = F_82 ( & V_35 -> V_231 -> V_35 , V_72 , V_292 ,
V_289 ? V_106 : V_107 ) ;
if ( ! V_75 )
goto V_174;
F_44 ( V_294 ) ;
return V_63 ;
V_174:
F_44 ( V_63 ) ;
V_298:
for ( V_79 = 0 ; V_79 < V_292 ; V_79 ++ )
F_177 ( V_294 [ V_79 ] ) ;
F_44 ( V_294 ) ;
return F_173 ( V_291 ) ;
}
void F_178 ( struct V_48 * V_35 , int V_289 ,
struct V_62 * V_63 )
{
int V_79 ;
F_61 ( & V_35 -> V_231 -> V_35 , V_63 -> V_72 , V_63 -> V_75 ,
V_289 ? V_106 : V_107 ) ;
for ( V_79 = 0 ; V_79 < V_63 -> V_75 ; V_79 ++ )
F_177 ( F_179 ( & V_63 -> V_72 [ V_79 ] ) ) ;
}
static int F_180 ( struct V_138 * V_139 , struct V_299 T_11 * V_300 )
{
struct V_48 * V_35 = V_139 -> V_35 ;
struct V_299 V_301 ;
struct V_8 V_200 ;
unsigned V_74 , V_302 ;
int V_45 , V_79 ;
struct V_62 * V_63 , * V_303 = NULL ;
T_6 V_304 ;
void * V_305 , * V_306 ( V_307 ) ;
if ( F_181 ( & V_301 , V_300 , sizeof( V_301 ) ) )
return - V_297 ;
V_74 = ( V_301 . V_308 + 1 ) << V_139 -> V_145 ;
V_302 = ( V_301 . V_308 + 1 ) * V_139 -> V_309 ;
if ( V_302 && ( ( V_301 . V_310 & 3 ) || ! V_301 . V_310 ) )
return - V_295 ;
switch ( V_301 . V_148 ) {
case V_170 :
case V_171 :
case V_311 :
V_63 = F_172 ( V_35 , V_301 . V_148 & 1 , V_301 . V_290 , V_74 ) ;
break;
default:
return - V_295 ;
}
if ( F_182 ( V_63 ) )
return F_183 ( V_63 ) ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_91 . V_148 = V_301 . V_148 ;
V_200 . V_91 . V_55 = V_301 . V_55 ;
V_200 . V_91 . V_150 = F_84 ( V_139 -> V_151 ) ;
V_200 . V_91 . V_146 = F_69 ( V_301 . V_146 ) ;
V_200 . V_91 . V_74 = F_89 ( V_301 . V_308 ) ;
V_200 . V_91 . V_160 = F_89 ( V_301 . V_160 ) ;
V_200 . V_91 . V_161 = F_84 ( V_301 . V_161 ) ;
V_200 . V_91 . V_312 = F_84 ( V_301 . V_312 ) ;
V_200 . V_91 . V_313 = F_89 ( V_301 . V_313 ) ;
V_200 . V_91 . V_314 = F_89 ( V_301 . V_314 ) ;
if ( V_302 ) {
V_303 = F_172 ( V_35 , V_301 . V_148 & 1 , V_301 . V_310 ,
V_302 ) ;
if ( F_182 ( V_303 ) ) {
V_45 = F_183 ( V_303 ) ;
V_303 = NULL ;
goto V_315;
}
V_307 = F_149 ( & V_35 -> V_231 -> V_35 , V_302 ,
& V_304 , V_254 ) ;
if ( ! V_307 ) {
V_45 = - V_118 ;
goto V_315;
}
if ( V_301 . V_148 & 1 ) {
int V_316 = 0 ;
for ( V_79 = 0 ; V_79 < V_303 -> V_75 ; V_79 ++ ) {
V_305 = F_184 ( F_179 ( & V_303 -> V_72 [ V_79 ] ) ) +
V_303 -> V_72 [ V_79 ] . V_64 ;
memcpy ( V_307 + V_316 , V_305 ,
V_303 -> V_72 [ V_79 ] . V_74 ) ;
F_185 ( V_305 ) ;
V_316 += V_303 -> V_72 [ V_79 ] . V_74 ;
}
}
V_200 . V_91 . V_310 = F_69 ( V_304 ) ;
}
V_74 = F_63 ( V_35 , V_63 , V_74 , V_254 ) ;
V_200 . V_91 . V_152 = F_69 ( F_65 ( V_63 -> V_72 ) ) ;
V_200 . V_91 . V_172 = F_69 ( V_63 -> V_76 ) ;
if ( V_74 != ( V_301 . V_308 + 1 ) << V_139 -> V_145 )
V_45 = - V_118 ;
else
V_45 = F_110 ( V_35 , & V_200 , NULL ) ;
if ( V_302 ) {
if ( V_45 == V_317 && ! ( V_301 . V_148 & 1 ) ) {
int V_316 = 0 ;
for ( V_79 = 0 ; V_79 < V_303 -> V_75 ; V_79 ++ ) {
V_305 = F_184 ( F_179 ( & V_303 -> V_72 [ V_79 ] ) ) +
V_303 -> V_72 [ V_79 ] . V_64 ;
memcpy ( V_305 , V_307 + V_316 ,
V_303 -> V_72 [ V_79 ] . V_74 ) ;
F_185 ( V_305 ) ;
V_316 += V_303 -> V_72 [ V_79 ] . V_74 ;
}
}
F_134 ( & V_35 -> V_231 -> V_35 , V_302 , V_307 ,
V_304 ) ;
}
V_315:
F_178 ( V_35 , V_301 . V_148 & 1 , V_63 ) ;
F_41 ( V_35 , V_63 ) ;
if ( V_303 ) {
F_178 ( V_35 , V_301 . V_148 & 1 , V_303 ) ;
F_41 ( V_35 , V_303 ) ;
}
return V_45 ;
}
static int F_186 ( struct V_48 * V_35 ,
struct V_318 T_11 * V_319 )
{
struct V_318 V_54 ;
struct V_8 V_200 ;
int V_45 , V_74 ;
struct V_62 * V_306 ( V_63 ) ;
unsigned V_21 ;
if ( ! F_187 ( V_320 ) )
return - V_321 ;
if ( F_181 ( & V_54 , V_319 , sizeof( V_54 ) ) )
return - V_297 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_156 . V_148 = V_54 . V_148 ;
V_200 . V_156 . V_55 = V_54 . V_55 ;
V_200 . V_156 . V_150 = F_84 ( V_54 . V_150 ) ;
V_200 . V_156 . V_322 [ 0 ] = F_84 ( V_54 . V_322 ) ;
V_200 . V_156 . V_322 [ 1 ] = F_84 ( V_54 . V_323 ) ;
V_200 . V_156 . V_324 [ 0 ] = F_84 ( V_54 . V_324 ) ;
V_200 . V_156 . V_324 [ 1 ] = F_84 ( V_54 . V_325 ) ;
V_200 . V_156 . V_324 [ 2 ] = F_84 ( V_54 . V_326 ) ;
V_200 . V_156 . V_324 [ 3 ] = F_84 ( V_54 . V_327 ) ;
V_200 . V_156 . V_324 [ 4 ] = F_84 ( V_54 . V_328 ) ;
V_200 . V_156 . V_324 [ 5 ] = F_84 ( V_54 . V_329 ) ;
V_74 = V_54 . V_330 ;
if ( V_54 . V_330 ) {
V_63 = F_172 ( V_35 , V_54 . V_148 & 1 , V_54 . V_290 ,
V_74 ) ;
if ( F_182 ( V_63 ) )
return F_183 ( V_63 ) ;
V_74 = F_63 ( V_35 , V_63 , V_74 , V_254 ) ;
V_200 . V_156 . V_152 = F_69 ( F_65 ( V_63 -> V_72 ) ) ;
V_200 . V_156 . V_172 = F_69 ( V_63 -> V_76 ) ;
}
V_21 = V_54 . V_331 ? F_188 ( V_54 . V_331 ) :
V_198 ;
if ( V_74 != V_54 . V_330 )
V_45 = - V_118 ;
else
V_45 = F_105 ( V_35 , 0 , & V_200 , & V_54 . V_44 , V_21 ) ;
if ( V_54 . V_330 ) {
F_178 ( V_35 , V_54 . V_148 & 1 , V_63 ) ;
F_41 ( V_35 , V_63 ) ;
}
if ( ( V_45 >= 0 ) && F_189 ( & V_319 -> V_44 , & V_54 . V_44 ,
sizeof( V_54 . V_44 ) ) )
V_45 = - V_297 ;
return V_45 ;
}
static int F_190 ( struct V_332 * V_333 , T_12 V_334 , unsigned int V_54 ,
unsigned long V_335 )
{
struct V_138 * V_139 = V_333 -> V_90 -> V_159 ;
switch ( V_54 ) {
case V_336 :
F_191 () ;
return V_139 -> V_151 ;
case V_337 :
return F_186 ( V_139 -> V_35 , ( void T_11 * ) V_335 ) ;
case V_338 :
return F_180 ( V_139 , ( void T_11 * ) V_335 ) ;
case V_339 :
return F_192 ( ( void T_11 * ) V_335 ) ;
case V_340 :
return F_193 ( V_139 , ( void T_11 * ) V_335 ) ;
default:
return - V_341 ;
}
}
static int F_194 ( struct V_332 * V_333 , T_12 V_334 ,
unsigned int V_54 , unsigned long V_335 )
{
struct V_138 * V_139 = V_333 -> V_90 -> V_159 ;
switch ( V_54 ) {
case V_340 :
return F_195 ( V_139 , V_335 ) ;
}
return F_190 ( V_333 , V_334 , V_54 , V_335 ) ;
}
static int F_196 ( struct V_332 * V_333 , T_12 V_334 )
{
struct V_138 * V_139 = V_333 -> V_90 -> V_159 ;
struct V_48 * V_35 = V_139 -> V_35 ;
F_197 ( & V_35 -> V_342 ) ;
return 0 ;
}
static void F_198 ( struct V_87 * V_88 , T_12 V_334 )
{
struct V_138 * V_139 = V_88 -> V_159 ;
struct V_48 * V_35 = V_139 -> V_35 ;
F_199 ( & V_35 -> V_342 , V_343 ) ;
}
static int F_200 ( struct V_332 * V_344 , struct V_345 * V_346 )
{
V_346 -> V_347 = 1 << 6 ;
V_346 -> V_95 = 1 << 5 ;
V_346 -> V_348 = F_201 ( V_344 -> V_90 ) >> 11 ;
return 0 ;
}
static void F_202 ( struct V_14 * V_15 )
{
struct V_62 * V_63 , * V_349 ;
F_203 (iod, next, &nvmeq->iod_bio, node) {
if ( F_57 ( F_88 ( V_15 , V_63 ) ) )
break;
F_133 ( & V_63 -> V_104 ) ;
if ( F_96 ( & V_15 -> V_119 ) &&
F_131 ( & V_15 -> V_105 ) )
F_204 ( & V_15 -> V_28 ,
& V_15 -> V_103 ) ;
}
}
static void F_205 ( struct V_14 * V_15 )
{
while ( F_129 ( & V_15 -> V_119 ) ) {
struct V_86 * V_86 = F_130 ( & V_15 -> V_119 ) ;
struct V_138 * V_139 = V_86 -> V_89 -> V_90 -> V_159 ;
if ( F_96 ( & V_15 -> V_119 ) &&
F_131 ( & V_15 -> V_105 ) )
F_204 ( & V_15 -> V_28 ,
& V_15 -> V_103 ) ;
if ( F_90 ( V_15 , V_139 , V_86 ) ) {
if ( ! F_58 ( & V_15 -> V_28 ) )
F_59 ( & V_15 -> V_28 ,
& V_15 -> V_103 ) ;
F_206 ( & V_15 -> V_119 , V_86 ) ;
break;
}
}
}
static int F_207 ( void * V_187 )
{
struct V_48 * V_35 , * V_349 ;
while ( ! F_208 () ) {
F_106 ( V_350 ) ;
F_99 ( & V_351 ) ;
F_203 (dev, next, &dev_list, node) {
int V_79 ;
if ( F_146 ( & V_35 -> V_249 -> V_250 ) & V_352 &&
V_35 -> V_239 ) {
if ( F_121 ( & V_35 -> V_230 ) )
continue;
F_122 ( & V_35 -> V_104 ) ;
F_12 ( & V_35 -> V_231 -> V_35 ,
L_10 ) ;
V_35 -> V_232 = V_233 ;
F_123 ( V_234 , & V_35 -> V_230 ) ;
continue;
}
F_25 () ;
for ( V_79 = 0 ; V_79 < V_35 -> V_245 ; V_79 ++ ) {
struct V_14 * V_15 =
F_26 ( V_35 -> V_50 [ V_79 ] ) ;
if ( ! V_15 )
continue;
F_95 ( & V_15 -> V_57 ) ;
if ( V_15 -> V_58 )
goto V_353;
F_92 ( V_15 ) ;
F_124 ( V_15 , true ) ;
F_205 ( V_15 ) ;
F_202 ( V_15 ) ;
V_353:
F_97 ( & V_15 -> V_57 ) ;
}
F_28 () ;
}
F_100 ( & V_351 ) ;
F_107 ( F_209 ( V_271 ) ) ;
}
return 0 ;
}
static void F_210 ( struct V_138 * V_139 )
{
T_8 V_354 = F_211 ( V_139 -> V_173 ) ;
V_139 -> V_173 -> V_355 . V_356 = 0 ;
V_139 -> V_173 -> V_355 . V_357 = V_354 ;
V_139 -> V_173 -> V_355 . V_358 = V_354 ;
V_139 -> V_173 -> V_355 . V_359 = 0xffffffff ;
F_212 ( V_360 , V_139 -> V_173 ) ;
}
static struct V_138 * F_213 ( struct V_48 * V_35 , unsigned V_150 ,
struct V_10 * V_199 , struct V_11 * V_361 )
{
struct V_138 * V_139 ;
struct V_87 * V_88 ;
int V_362 ;
if ( V_361 -> V_154 & V_363 )
return NULL ;
V_139 = F_148 ( sizeof( * V_139 ) , V_254 ) ;
if ( ! V_139 )
return NULL ;
V_139 -> V_173 = F_214 ( V_254 ) ;
if ( ! V_139 -> V_173 )
goto V_364;
V_139 -> V_173 -> V_365 = V_366 ;
F_212 ( V_367 , V_139 -> V_173 ) ;
F_212 ( V_368 , V_139 -> V_173 ) ;
F_215 ( V_139 -> V_173 , F_94 ) ;
V_139 -> V_35 = V_35 ;
V_139 -> V_173 -> V_185 = V_139 ;
V_88 = F_216 ( 0 ) ;
if ( ! V_88 )
goto V_369;
V_139 -> V_151 = V_150 ;
V_139 -> V_88 = V_88 ;
V_362 = V_199 -> V_370 & 0xf ;
V_139 -> V_145 = V_199 -> V_362 [ V_362 ] . V_371 ;
V_139 -> V_309 = F_93 ( V_199 -> V_362 [ V_362 ] . V_309 ) ;
F_217 ( V_139 -> V_173 , 1 << V_139 -> V_145 ) ;
if ( V_35 -> V_372 )
F_218 ( V_139 -> V_173 , V_35 -> V_372 ) ;
V_88 -> V_373 = V_374 ;
V_88 -> V_375 = 0 ;
V_88 -> V_376 = & V_377 ;
V_88 -> V_159 = V_139 ;
V_88 -> V_173 = V_139 -> V_173 ;
V_88 -> V_378 = & V_35 -> V_231 -> V_35 ;
V_88 -> V_55 = V_379 ;
sprintf ( V_88 -> V_380 , L_11 , V_35 -> V_259 , V_150 ) ;
F_219 ( V_88 , F_220 ( & V_199 -> V_381 ) << ( V_139 -> V_145 - 9 ) ) ;
if ( V_35 -> V_382 & V_383 )
F_210 ( V_139 ) ;
return V_139 ;
V_369:
F_221 ( V_139 -> V_173 ) ;
V_364:
F_44 ( V_139 ) ;
return NULL ;
}
static int F_222 ( int V_104 )
{
int V_384 , V_385 , V_386 = V_296 , V_387 = V_104 ;
F_223 (n) {
if ( V_384 == V_104 )
continue;
V_385 = F_224 ( V_104 , V_384 ) ;
if ( V_385 < V_386 ) {
V_386 = V_385 ;
V_387 = V_384 ;
}
}
return V_387 ;
}
static void F_225 ( T_13 * V_388 , struct V_14 * V_15 ,
int V_292 )
{
int V_92 ;
F_226 (cpu, qmask) {
if ( F_227 ( V_15 -> V_243 ) >= V_292 )
break;
if ( ! F_228 ( V_92 , V_15 -> V_243 ) )
* F_229 ( V_15 -> V_35 -> V_52 , V_92 ) = V_15 -> V_49 ;
}
}
static void F_230 ( T_13 * V_389 , const T_13 * V_390 ,
const T_13 * V_391 , struct V_14 * V_15 , int V_392 )
{
int V_393 ;
F_226 (next_cpu, new_mask) {
F_231 ( V_389 , V_389 , F_232 ( V_393 ) ) ;
F_231 ( V_389 , V_389 , F_233 ( V_393 ) ) ;
F_234 ( V_389 , V_389 , V_390 ) ;
F_225 ( V_389 , V_15 , V_392 ) ;
}
}
static void F_235 ( struct V_48 * V_35 )
{
unsigned V_79 , V_394 ;
V_394 = F_236 ( V_35 -> V_395 , F_237 () ) ;
for ( V_79 = V_35 -> V_245 ; V_79 <= V_394 ; V_79 ++ )
if ( ! F_147 ( V_35 , V_79 , V_35 -> V_17 , V_79 - 1 ) )
break;
V_394 = F_236 ( V_35 -> V_245 - 1 , F_237 () ) ;
for ( V_79 = V_35 -> V_248 ; V_79 <= V_394 ; V_79 ++ )
if ( F_160 ( F_21 ( V_35 , V_79 ) , V_79 ) )
break;
}
static void F_238 ( struct V_48 * V_35 )
{
unsigned V_92 , V_392 , V_50 , V_396 , V_79 ;
T_14 V_390 ;
F_235 ( V_35 ) ;
V_50 = F_236 ( V_35 -> V_248 - 1 , F_237 () ) ;
if ( ! V_50 )
return;
V_392 = F_237 () / V_50 ;
V_396 = V_50 - ( F_237 () - V_50 * V_392 ) ;
if ( ! F_239 ( & V_390 , V_254 ) )
return;
F_240 ( V_390 , V_397 ) ;
V_92 = F_241 ( V_390 ) ;
for ( V_79 = 1 ; V_79 <= V_50 ; V_79 ++ ) {
struct V_14 * V_15 = F_30 ( V_35 , V_79 ) ;
T_13 V_389 ;
F_242 ( V_15 -> V_243 ) ;
if ( ! F_227 ( V_390 ) ) {
F_31 ( V_15 ) ;
break;
}
V_389 = * F_232 ( V_92 ) ;
F_225 ( & V_389 , V_15 , V_392 ) ;
if ( F_243 ( V_389 ) < V_392 )
F_230 ( & V_389 , V_390 ,
F_233 ( V_92 ) ,
V_15 , V_392 ) ;
if ( F_243 ( V_389 ) < V_392 )
F_230 ( & V_389 , V_390 ,
F_244 ( V_92 ) ,
V_15 , V_392 ) ;
if ( F_243 ( V_389 ) < V_392 )
F_230 ( & V_389 , V_390 ,
F_245 ( F_246 ( V_92 ) ) ,
V_15 , V_392 ) ;
if ( F_243 ( V_389 ) < V_392 )
F_230 ( & V_389 , V_390 ,
F_245 (
F_222 (
F_246 ( V_92 ) ) ) ,
V_15 , V_392 ) ;
if ( F_243 ( V_389 ) < V_392 )
F_230 ( & V_389 , V_390 ,
V_390 ,
V_15 , V_392 ) ;
F_247 ( F_227 ( V_15 -> V_243 ) != V_392 ,
L_12 ,
V_35 -> V_259 , V_79 ) ;
F_142 ( V_35 -> V_247 [ V_15 -> V_211 ] . V_246 ,
V_15 -> V_243 ) ;
F_248 ( V_390 , V_390 ,
V_15 -> V_243 ) ;
V_92 = F_249 ( V_92 , V_390 ) ;
if ( V_396 && ! -- V_396 )
V_392 ++ ;
F_31 ( V_15 ) ;
}
F_247 ( F_227 ( V_390 ) , L_13 ,
V_35 -> V_259 ) ;
V_79 = 0 ;
F_248 ( V_390 , V_398 , V_397 ) ;
F_226 ( V_92 , V_390 )
* F_229 ( V_35 -> V_52 , V_92 ) = ( V_79 ++ % V_50 ) + 1 ;
F_137 ( V_390 ) ;
}
static int F_250 ( struct V_48 * V_35 , int V_292 )
{
int V_45 ;
T_8 V_44 ;
T_8 V_399 = ( V_292 - 1 ) | ( ( V_292 - 1 ) << 16 ) ;
V_45 = F_120 ( V_35 , V_400 , V_399 , 0 ,
& V_44 ) ;
if ( V_45 )
return V_45 < 0 ? - V_108 : - V_24 ;
return F_236 ( V_44 & 0xffff , V_44 >> 16 ) + 1 ;
}
static T_15 F_251 ( struct V_48 * V_35 , unsigned V_401 )
{
return 4096 + ( ( V_401 + 1 ) * 8 * V_35 -> V_181 ) ;
}
static int F_252 ( struct V_402 * V_403 ,
unsigned long V_404 , void * V_405 )
{
struct V_48 * V_35 = F_128 ( V_403 , struct V_48 , V_406 ) ;
switch ( V_404 ) {
case V_407 :
case V_408 :
F_238 ( V_35 ) ;
break;
}
return V_409 ;
}
static int F_253 ( struct V_48 * V_35 )
{
struct V_14 * V_229 = F_21 ( V_35 , 0 ) ;
struct V_231 * V_410 = V_35 -> V_231 ;
int V_44 , V_79 , V_411 , V_401 , V_65 ;
V_401 = F_254 () ;
V_44 = F_250 ( V_35 , V_401 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_44 < V_401 )
V_401 = V_44 ;
V_65 = F_251 ( V_35 , V_401 ) ;
if ( V_65 > 8192 ) {
F_255 ( V_35 -> V_249 ) ;
do {
V_35 -> V_249 = F_256 ( F_257 ( V_410 , 0 ) , V_65 ) ;
if ( V_35 -> V_249 )
break;
if ( ! -- V_401 )
return - V_118 ;
V_65 = F_251 ( V_35 , V_401 ) ;
} while ( 1 );
V_35 -> V_261 = ( ( void V_412 * ) V_35 -> V_249 ) + 4096 ;
V_229 -> V_61 = V_35 -> V_261 ;
}
F_143 ( V_35 -> V_247 [ 0 ] . V_246 , V_229 ) ;
for ( V_79 = 0 ; V_79 < V_401 ; V_79 ++ )
V_35 -> V_247 [ V_79 ] . V_247 = V_79 ;
V_411 = F_258 ( V_410 , V_35 -> V_247 , 1 , V_401 ) ;
if ( V_411 < 0 ) {
V_411 = F_259 ( V_410 , 1 , F_236 ( V_401 , 32 ) ) ;
if ( V_411 < 0 ) {
V_411 = 1 ;
} else {
for ( V_79 = 0 ; V_79 < V_411 ; V_79 ++ )
V_35 -> V_247 [ V_79 ] . V_246 = V_79 + V_410 -> V_186 ;
}
}
V_401 = V_411 ;
V_35 -> V_395 = V_401 ;
V_44 = F_156 ( V_35 , V_229 , V_229 -> V_258 ) ;
if ( V_44 ) {
V_229 -> V_58 = 1 ;
goto V_413;
}
F_138 ( V_35 , V_401 + 1 ) ;
F_238 ( V_35 ) ;
V_35 -> V_406 . V_414 = & F_252 ;
V_44 = F_260 ( & V_35 -> V_406 ) ;
if ( V_44 )
goto V_413;
return 0 ;
V_413:
F_138 ( V_35 , 1 ) ;
return V_44 ;
}
static int F_261 ( struct V_48 * V_35 )
{
struct V_231 * V_410 = V_35 -> V_231 ;
int V_415 ;
unsigned V_416 , V_79 ;
struct V_138 * V_139 ;
struct V_9 * V_417 ;
struct V_10 * V_418 ;
void * V_419 ;
T_6 V_113 ;
int V_420 = F_262 ( F_170 ( & V_35 -> V_249 -> V_267 ) ) + 12 ;
V_419 = F_149 ( & V_410 -> V_35 , 8192 , & V_113 , V_254 ) ;
if ( ! V_419 )
return - V_118 ;
V_415 = F_118 ( V_35 , 0 , 1 , V_113 ) ;
if ( V_415 ) {
V_415 = - V_108 ;
goto V_421;
}
V_417 = V_419 ;
V_416 = F_15 ( & V_417 -> V_416 ) ;
V_35 -> V_382 = F_13 ( & V_417 -> V_382 ) ;
V_35 -> V_36 = V_417 -> V_422 + 1 ;
memcpy ( V_35 -> V_423 , V_417 -> V_424 , sizeof( V_417 -> V_424 ) ) ;
memcpy ( V_35 -> V_425 , V_417 -> V_426 , sizeof( V_417 -> V_426 ) ) ;
memcpy ( V_35 -> V_427 , V_417 -> V_428 , sizeof( V_417 -> V_428 ) ) ;
if ( V_417 -> V_429 )
V_35 -> V_372 = 1 << ( V_417 -> V_429 + V_420 - 9 ) ;
if ( ( V_410 -> V_430 == V_431 ) &&
( V_410 -> V_251 == 0x0953 ) && V_417 -> V_432 [ 3 ] )
V_35 -> V_133 = 1 << ( V_417 -> V_432 [ 3 ] + V_420 ) ;
V_418 = V_419 ;
for ( V_79 = 1 ; V_79 <= V_416 ; V_79 ++ ) {
V_415 = F_118 ( V_35 , V_79 , 0 , V_113 ) ;
if ( V_415 )
continue;
if ( V_418 -> V_433 == 0 )
continue;
V_415 = F_119 ( V_35 , V_434 , V_79 ,
V_113 + 4096 , NULL ) ;
if ( V_415 )
memset ( V_419 + 4096 , 0 , 4096 ) ;
V_139 = F_213 ( V_35 , V_79 , V_419 , V_419 + 4096 ) ;
if ( V_139 )
F_60 ( & V_139 -> V_80 , & V_35 -> V_435 ) ;
}
F_263 (ns, &dev->namespaces, list)
F_264 ( V_139 -> V_88 ) ;
V_415 = 0 ;
V_421:
F_134 ( & V_35 -> V_231 -> V_35 , 8192 , V_419 , V_113 ) ;
return V_415 ;
}
static int F_265 ( struct V_48 * V_35 )
{
T_7 V_267 ;
int V_436 , V_44 = - V_118 ;
struct V_231 * V_410 = V_35 -> V_231 ;
if ( F_266 ( V_410 ) )
return V_44 ;
V_35 -> V_247 [ 0 ] . V_246 = V_410 -> V_186 ;
F_267 ( V_410 ) ;
V_436 = F_268 ( V_410 , V_437 ) ;
if ( F_269 ( V_410 , V_436 , L_14 ) )
goto V_438;
if ( F_270 ( & V_410 -> V_35 , F_271 ( 64 ) ) &&
F_270 ( & V_410 -> V_35 , F_271 ( 32 ) ) )
goto V_439;
V_35 -> V_249 = F_256 ( F_257 ( V_410 , 0 ) , 8192 ) ;
if ( ! V_35 -> V_249 )
goto V_439;
if ( F_146 ( & V_35 -> V_249 -> V_250 ) == - 1 ) {
V_44 = - V_194 ;
goto V_315;
}
V_267 = F_170 ( & V_35 -> V_249 -> V_267 ) ;
V_35 -> V_17 = F_176 ( int , F_272 ( V_267 ) + 1 , V_440 ) ;
V_35 -> V_181 = 1 << F_273 ( V_267 ) ;
V_35 -> V_261 = ( ( void V_412 * ) V_35 -> V_249 ) + 4096 ;
return 0 ;
V_315:
F_255 ( V_35 -> V_249 ) ;
V_35 -> V_249 = NULL ;
V_439:
F_274 ( V_410 ) ;
V_438:
F_275 ( V_410 ) ;
return V_44 ;
}
static void F_276 ( struct V_48 * V_35 )
{
if ( V_35 -> V_231 -> V_441 )
F_277 ( V_35 -> V_231 ) ;
else if ( V_35 -> V_231 -> V_442 )
F_278 ( V_35 -> V_231 ) ;
if ( V_35 -> V_249 ) {
F_255 ( V_35 -> V_249 ) ;
V_35 -> V_249 = NULL ;
F_274 ( V_35 -> V_231 ) ;
}
if ( F_279 ( V_35 -> V_231 ) )
F_275 ( V_35 -> V_231 ) ;
}
static void F_280 ( struct V_443 * V_444 , struct V_48 * V_35 )
{
V_444 -> V_445 = V_195 ;
F_281 () ;
for (; ; ) {
F_106 ( V_196 ) ;
if ( ! F_282 ( & V_444 -> V_446 ) )
break;
if ( ! F_107 ( V_198 ) ||
F_164 ( V_195 ) ) {
F_106 ( V_197 ) ;
F_166 ( V_35 , F_170 ( & V_35 -> V_249 -> V_267 ) ) ;
F_145 ( V_35 , 0 ) ;
F_283 ( V_447 , V_444 -> V_46 -> V_192 , 1 ) ;
F_284 ( V_444 -> V_46 ) ;
return;
}
}
F_106 ( V_197 ) ;
}
static void F_285 ( struct V_443 * V_444 )
{
F_286 ( & V_444 -> V_446 ) ;
if ( V_444 -> V_445 )
F_104 ( V_444 -> V_445 ) ;
}
static struct V_443 * F_287 ( struct V_443 * V_444 )
{
F_288 ( & V_444 -> V_446 ) ;
return V_444 ;
}
static void F_289 ( struct V_14 * V_15 )
{
struct V_443 * V_444 = V_15 -> V_43 . V_19 ;
F_144 ( V_15 ) ;
F_285 ( V_444 ) ;
}
static int F_290 ( struct V_14 * V_15 , T_10 V_148 ,
T_16 V_25 )
{
struct V_8 V_200 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_201 . V_148 = V_148 ;
V_200 . V_201 . V_49 = F_89 ( V_15 -> V_49 ) ;
F_291 ( & V_15 -> V_43 . V_47 , V_25 ) ;
return F_112 ( V_15 -> V_35 , & V_200 , & V_15 -> V_43 ) ;
}
static void F_292 ( struct V_448 * V_47 )
{
struct V_14 * V_15 = F_128 ( V_47 , struct V_14 ,
V_43 . V_47 ) ;
F_289 ( V_15 ) ;
}
static int F_293 ( struct V_14 * V_15 )
{
return F_290 ( V_15 , V_218 ,
F_292 ) ;
}
static void F_294 ( struct V_448 * V_47 )
{
struct V_14 * V_15 = F_128 ( V_47 , struct V_14 ,
V_43 . V_47 ) ;
int V_45 = V_15 -> V_43 . V_45 ;
if ( ! V_45 )
V_45 = F_293 ( V_15 ) ;
if ( V_45 )
F_289 ( V_15 ) ;
}
static int F_295 ( struct V_14 * V_15 )
{
return F_290 ( V_15 , V_219 ,
F_294 ) ;
}
static void F_296 ( struct V_448 * V_47 )
{
struct V_14 * V_15 = F_128 ( V_47 , struct V_14 ,
V_43 . V_47 ) ;
F_297 ( V_447 ) ;
if ( F_295 ( V_15 ) )
F_289 ( V_15 ) ;
}
static void F_298 ( struct V_48 * V_35 )
{
int V_79 ;
F_299 ( V_46 ) ;
struct V_443 V_444 ;
struct V_449 * V_450 = F_300 ( V_451 ,
& V_46 , L_15 , V_35 -> V_259 ) ;
if ( F_182 ( V_450 ) ) {
F_165 ( & V_35 -> V_231 -> V_35 ,
L_16 ) ;
for ( V_79 = V_35 -> V_245 - 1 ; V_79 > 0 ; V_79 -- )
F_145 ( V_35 , V_79 ) ;
return;
}
V_444 . V_445 = NULL ;
F_301 ( & V_444 . V_446 , 0 ) ;
V_444 . V_46 = & V_46 ;
for ( V_79 = V_35 -> V_245 - 1 ; V_79 > 0 ; V_79 -- ) {
struct V_14 * V_15 = F_21 ( V_35 , V_79 ) ;
if ( F_141 ( V_15 ) )
continue;
V_15 -> V_43 . V_19 = F_287 ( & V_444 ) ;
V_15 -> V_43 . V_46 = V_444 . V_46 ;
F_291 ( & V_15 -> V_43 . V_47 , F_296 ) ;
F_16 ( V_444 . V_46 , & V_15 -> V_43 . V_47 ) ;
}
F_280 ( & V_444 , V_35 ) ;
F_302 ( V_450 ) ;
}
static void F_303 ( struct V_48 * V_35 )
{
struct V_449 * V_452 = NULL ;
F_99 ( & V_351 ) ;
F_122 ( & V_35 -> V_104 ) ;
if ( F_131 ( & V_453 ) && ! F_304 ( V_260 ) ) {
V_452 = V_260 ;
V_260 = NULL ;
}
F_100 ( & V_351 ) ;
if ( V_452 )
F_302 ( V_452 ) ;
}
static void F_305 ( struct V_48 * V_35 )
{
int V_79 ;
V_35 -> V_239 = 0 ;
F_306 ( & V_35 -> V_406 ) ;
F_303 ( V_35 ) ;
if ( ! V_35 -> V_249 || ( V_35 -> V_249 && F_146 ( & V_35 -> V_249 -> V_250 ) == - 1 ) ) {
for ( V_79 = V_35 -> V_245 - 1 ; V_79 >= 0 ; V_79 -- ) {
struct V_14 * V_15 = F_21 ( V_35 , V_79 ) ;
F_141 ( V_15 ) ;
F_144 ( V_15 ) ;
}
} else {
F_298 ( V_35 ) ;
F_168 ( V_35 ) ;
F_145 ( V_35 , 0 ) ;
}
F_276 ( V_35 ) ;
}
static void F_307 ( struct V_48 * V_35 )
{
struct V_138 * V_139 ;
F_263 (ns, &dev->namespaces, list) {
if ( V_139 -> V_88 -> V_55 & V_454 )
F_308 ( V_139 -> V_88 ) ;
if ( ! F_309 ( V_139 -> V_173 ) )
F_221 ( V_139 -> V_173 ) ;
}
}
static int F_310 ( struct V_48 * V_35 )
{
struct V_251 * V_252 = & V_35 -> V_231 -> V_35 ;
V_35 -> V_85 = F_311 ( L_17 , V_252 ,
V_67 , V_67 , 0 ) ;
if ( ! V_35 -> V_85 )
return - V_118 ;
V_35 -> V_82 = F_311 ( L_18 , V_252 ,
256 , 256 , 0 ) ;
if ( ! V_35 -> V_82 ) {
F_312 ( V_35 -> V_85 ) ;
return - V_118 ;
}
return 0 ;
}
static void F_313 ( struct V_48 * V_35 )
{
F_312 ( V_35 -> V_85 ) ;
F_312 ( V_35 -> V_82 ) ;
}
static int F_314 ( struct V_48 * V_35 )
{
int V_259 , error ;
do {
if ( ! F_315 ( & V_455 , V_254 ) )
return - V_194 ;
F_99 ( & V_351 ) ;
error = F_316 ( & V_455 , & V_259 ) ;
F_100 ( & V_351 ) ;
} while ( error == - V_456 );
if ( error )
return - V_194 ;
V_35 -> V_259 = V_259 ;
return 0 ;
}
static void F_317 ( struct V_48 * V_35 )
{
F_99 ( & V_351 ) ;
F_318 ( & V_455 , V_35 -> V_259 ) ;
F_100 ( & V_351 ) ;
}
static void F_319 ( struct V_48 * V_35 )
{
struct V_138 * V_139 , * V_349 ;
F_203 (ns, next, &dev->namespaces, list) {
F_133 ( & V_139 -> V_80 ) ;
F_320 ( V_139 -> V_88 ) ;
F_44 ( V_139 ) ;
}
}
static void V_343 ( struct V_342 * V_342 )
{
struct V_48 * V_35 = F_128 ( V_342 , struct V_48 , V_342 ) ;
F_319 ( V_35 ) ;
F_321 ( V_35 -> V_52 ) ;
F_44 ( V_35 -> V_50 ) ;
F_44 ( V_35 -> V_247 ) ;
F_44 ( V_35 ) ;
}
static int F_322 ( struct V_457 * V_457 , struct V_458 * V_459 )
{
struct V_48 * V_35 = F_128 ( V_459 -> V_159 , struct V_48 ,
V_460 ) ;
F_197 ( & V_35 -> V_342 ) ;
V_459 -> V_159 = V_35 ;
return 0 ;
}
static int F_323 ( struct V_457 * V_457 , struct V_458 * V_459 )
{
struct V_48 * V_35 = V_459 -> V_159 ;
F_199 ( & V_35 -> V_342 , V_343 ) ;
return 0 ;
}
static long F_324 ( struct V_458 * V_459 , unsigned int V_54 , unsigned long V_335 )
{
struct V_48 * V_35 = V_459 -> V_159 ;
switch ( V_54 ) {
case V_337 :
return F_186 ( V_35 , ( void T_11 * ) V_335 ) ;
default:
return - V_341 ;
}
}
static int F_325 ( struct V_48 * V_35 )
{
int V_44 ;
bool V_461 = false ;
V_44 = F_265 ( V_35 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_169 ( V_35 ) ;
if ( V_44 )
goto V_315;
F_99 ( & V_351 ) ;
if ( F_131 ( & V_453 ) && F_304 ( V_260 ) ) {
V_461 = true ;
V_260 = NULL ;
}
F_326 ( & V_35 -> V_104 , & V_453 ) ;
F_100 ( & V_351 ) ;
if ( V_461 ) {
V_260 = F_300 ( F_207 , NULL , L_14 ) ;
F_19 ( & V_462 ) ;
} else
F_10 ( V_462 , V_260 ) ;
if ( F_304 ( V_260 ) ) {
V_44 = V_260 ? F_183 ( V_260 ) : - V_29 ;
goto V_439;
}
V_44 = F_253 ( V_35 ) ;
if ( V_44 && V_44 != - V_24 )
goto V_439;
return V_44 ;
V_439:
F_145 ( V_35 , 0 ) ;
F_303 ( V_35 ) ;
V_315:
F_276 ( V_35 ) ;
return V_44 ;
}
static int F_327 ( void * V_335 )
{
struct V_48 * V_35 = (struct V_48 * ) V_335 ;
struct V_231 * V_410 = V_35 -> V_231 ;
if ( F_328 ( V_410 ) )
F_329 ( V_410 ) ;
F_199 ( & V_35 -> V_342 , V_343 ) ;
return 0 ;
}
static void F_330 ( struct V_463 * V_464 )
{
struct V_48 * V_35 = F_128 ( V_464 , struct V_48 , V_230 ) ;
F_307 ( V_35 ) ;
F_138 ( V_35 , 1 ) ;
}
static int F_331 ( struct V_48 * V_35 )
{
int V_193 ;
V_193 = F_325 ( V_35 ) ;
if ( V_193 && V_193 != - V_24 )
return V_193 ;
if ( V_193 == - V_24 ) {
F_99 ( & V_351 ) ;
V_35 -> V_232 = F_330 ;
F_123 ( V_234 , & V_35 -> V_230 ) ;
F_100 ( & V_351 ) ;
}
V_35 -> V_239 = 1 ;
return 0 ;
}
static void F_332 ( struct V_48 * V_35 )
{
F_305 ( V_35 ) ;
if ( F_331 ( V_35 ) ) {
F_165 ( & V_35 -> V_231 -> V_35 , L_19 ) ;
F_197 ( & V_35 -> V_342 ) ;
if ( F_182 ( F_300 ( F_327 , V_35 , L_15 ,
V_35 -> V_259 ) ) ) {
F_165 ( & V_35 -> V_231 -> V_35 ,
L_20 ) ;
F_199 ( & V_35 -> V_342 , V_343 ) ;
}
}
}
static void V_233 ( struct V_463 * V_464 )
{
struct V_48 * V_35 = F_128 ( V_464 , struct V_48 , V_230 ) ;
F_332 ( V_35 ) ;
}
static void F_333 ( struct V_463 * V_47 )
{
struct V_48 * V_35 = F_128 ( V_47 , struct V_48 , V_230 ) ;
V_35 -> V_232 ( V_47 ) ;
}
static int F_334 ( struct V_231 * V_410 , const struct V_465 * V_199 )
{
int V_44 = - V_118 ;
struct V_48 * V_35 ;
V_35 = F_148 ( sizeof( * V_35 ) , V_254 ) ;
if ( ! V_35 )
return - V_118 ;
V_35 -> V_247 = F_174 ( F_254 () , sizeof( * V_35 -> V_247 ) ,
V_254 ) ;
if ( ! V_35 -> V_247 )
goto free;
V_35 -> V_50 = F_174 ( F_254 () + 1 , sizeof( void * ) ,
V_254 ) ;
if ( ! V_35 -> V_50 )
goto free;
V_35 -> V_52 = F_335 (unsigned short) ;
if ( ! V_35 -> V_52 )
goto free;
F_155 ( & V_35 -> V_435 ) ;
V_35 -> V_232 = V_233 ;
F_336 ( & V_35 -> V_230 , F_333 ) ;
V_35 -> V_231 = V_410 ;
F_337 ( V_410 , V_35 ) ;
V_44 = F_314 ( V_35 ) ;
if ( V_44 )
goto free;
V_44 = F_310 ( V_35 ) ;
if ( V_44 )
goto V_466;
F_338 ( & V_35 -> V_342 ) ;
V_44 = F_325 ( V_35 ) ;
if ( V_44 ) {
if ( V_44 == - V_24 )
goto V_467;
goto V_468;
}
V_44 = F_261 ( V_35 ) ;
if ( V_44 )
goto V_469;
V_467:
F_339 ( V_35 -> V_262 , sizeof( V_35 -> V_262 ) , L_15 , V_35 -> V_259 ) ;
V_35 -> V_460 . V_470 = V_471 ;
V_35 -> V_460 . V_472 = & V_410 -> V_35 ;
V_35 -> V_460 . V_262 = V_35 -> V_262 ;
V_35 -> V_460 . V_376 = & V_473 ;
V_44 = F_340 ( & V_35 -> V_460 ) ;
if ( V_44 )
goto remove;
V_35 -> V_239 = 1 ;
return 0 ;
remove:
F_307 ( V_35 ) ;
F_319 ( V_35 ) ;
V_469:
F_305 ( V_35 ) ;
V_468:
F_138 ( V_35 , 0 ) ;
F_313 ( V_35 ) ;
V_466:
F_317 ( V_35 ) ;
free:
F_321 ( V_35 -> V_52 ) ;
F_44 ( V_35 -> V_50 ) ;
F_44 ( V_35 -> V_247 ) ;
F_44 ( V_35 ) ;
return V_44 ;
}
static void F_341 ( struct V_231 * V_410 )
{
struct V_48 * V_35 = F_328 ( V_410 ) ;
F_305 ( V_35 ) ;
}
static void F_342 ( struct V_231 * V_410 )
{
struct V_48 * V_35 = F_328 ( V_410 ) ;
F_99 ( & V_351 ) ;
F_122 ( & V_35 -> V_104 ) ;
F_100 ( & V_351 ) ;
F_337 ( V_410 , NULL ) ;
F_343 ( & V_35 -> V_230 ) ;
F_344 ( & V_35 -> V_460 ) ;
F_307 ( V_35 ) ;
F_305 ( V_35 ) ;
F_138 ( V_35 , 0 ) ;
F_345 () ;
F_317 ( V_35 ) ;
F_313 ( V_35 ) ;
F_199 ( & V_35 -> V_342 , V_343 ) ;
}
static int F_346 ( struct V_251 * V_35 )
{
struct V_231 * V_410 = F_347 ( V_35 ) ;
struct V_48 * V_474 = F_328 ( V_410 ) ;
F_305 ( V_474 ) ;
return 0 ;
}
static int F_348 ( struct V_251 * V_35 )
{
struct V_231 * V_410 = F_347 ( V_35 ) ;
struct V_48 * V_474 = F_328 ( V_410 ) ;
if ( F_331 ( V_474 ) && ! F_121 ( & V_474 -> V_230 ) ) {
V_474 -> V_232 = V_233 ;
F_123 ( V_234 , & V_474 -> V_230 ) ;
}
return 0 ;
}
static int T_17 F_349 ( void )
{
int V_44 ;
F_152 ( & V_462 ) ;
V_234 = F_350 ( L_14 ) ;
if ( ! V_234 )
return - V_118 ;
V_44 = F_351 ( V_374 , L_14 ) ;
if ( V_44 < 0 )
goto V_475;
else if ( V_44 > 0 )
V_374 = V_44 ;
V_44 = F_352 ( & V_476 ) ;
if ( V_44 )
goto V_477;
return 0 ;
V_477:
V_477 ( V_374 , L_14 ) ;
V_475:
F_353 ( V_234 ) ;
return V_44 ;
}
static void T_18 F_354 ( void )
{
F_355 ( & V_476 ) ;
V_477 ( V_374 , L_14 ) ;
F_353 ( V_234 ) ;
F_70 ( V_260 && ! F_182 ( V_260 ) ) ;
}
