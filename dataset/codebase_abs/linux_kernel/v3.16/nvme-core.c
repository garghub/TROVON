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
if ( V_19 == V_33 ) {
++ V_15 -> V_34 -> V_35 ;
return;
}
if ( V_19 == V_36 ) {
F_12 ( V_15 -> V_37 ,
L_1 ,
V_31 -> V_38 , F_13 ( & V_31 -> V_39 ) ) ;
return;
}
if ( V_19 == V_40 ) {
F_12 ( V_15 -> V_37 ,
L_2 ,
V_31 -> V_38 , F_13 ( & V_31 -> V_39 ) ) ;
return;
}
F_12 ( V_15 -> V_37 , L_3 , V_19 ) ;
}
static void F_14 ( struct V_14 * V_15 , void * V_19 ,
struct V_30 * V_31 )
{
struct V_41 * V_42 = V_19 ;
V_42 -> V_43 = F_15 ( & V_31 -> V_43 ) ;
V_42 -> V_44 = F_13 ( & V_31 -> V_44 ) >> 1 ;
F_16 ( V_42 -> V_45 , & V_42 -> V_46 ) ;
}
static void * F_17 ( struct V_14 * V_15 , int V_23 ,
T_1 * V_25 )
{
void * V_19 ;
struct V_13 * V_22 = V_13 ( V_15 ) ;
if ( V_23 >= V_15 -> V_17 || ! V_22 [ V_23 ] . V_25 ) {
if ( V_25 )
* V_25 = F_11 ;
return V_40 ;
}
if ( V_25 )
* V_25 = V_22 [ V_23 ] . V_25 ;
V_19 = V_22 [ V_23 ] . V_19 ;
V_22 [ V_23 ] . V_25 = F_11 ;
V_22 [ V_23 ] . V_19 = V_36 ;
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
static struct V_14 * F_21 ( struct V_47 * V_34 , int V_48 )
{
return F_22 ( V_34 -> V_49 [ V_48 ] ) ;
}
static struct V_14 * F_23 ( struct V_47 * V_34 ) __acquires( T_2 )
{
struct V_14 * V_15 ;
unsigned V_50 = F_24 ( * V_34 -> V_51 ) ;
F_25 () ;
V_15 = F_26 ( V_34 -> V_49 [ V_50 ] ) ;
if ( V_15 )
return V_15 ;
F_27 () ;
F_28 ( * V_34 -> V_51 ) ;
return NULL ;
}
static void F_29 ( struct V_14 * V_15 ) __releases( T_2 )
{
F_27 () ;
F_28 ( V_15 -> V_34 -> V_51 ) ;
}
static struct V_14 * F_30 ( struct V_47 * V_34 , int V_52 )
__acquires( T_2 )
{
struct V_14 * V_15 ;
F_25 () ;
V_15 = F_26 ( V_34 -> V_49 [ V_52 ] ) ;
if ( V_15 )
return V_15 ;
F_27 () ;
return NULL ;
}
static void F_31 ( struct V_14 * V_15 ) __releases( T_2 )
{
F_27 () ;
}
static int F_32 ( struct V_14 * V_15 , struct V_8 * V_53 )
{
unsigned long V_54 ;
T_3 V_55 ;
F_33 ( & V_15 -> V_56 , V_54 ) ;
if ( V_15 -> V_57 ) {
F_34 ( & V_15 -> V_56 , V_54 ) ;
return - V_24 ;
}
V_55 = V_15 -> V_58 ;
memcpy ( & V_15 -> V_59 [ V_55 ] , V_53 , sizeof( * V_53 ) ) ;
if ( ++ V_55 == V_15 -> V_17 )
V_55 = 0 ;
F_35 ( V_55 , V_15 -> V_60 ) ;
V_15 -> V_58 = V_55 ;
F_34 ( & V_15 -> V_56 , V_54 ) ;
return 0 ;
}
static T_4 * * F_36 ( struct V_61 * V_62 )
{
return ( ( void * ) V_62 ) + V_62 -> V_63 ;
}
static int F_37 ( unsigned V_64 )
{
unsigned V_65 = F_5 ( V_64 + V_66 , V_66 ) ;
return F_5 ( 8 * V_65 , V_66 - 8 ) ;
}
static struct V_61 *
F_38 ( unsigned V_67 , unsigned V_68 , T_5 V_69 )
{
struct V_61 * V_62 = F_39 ( sizeof( struct V_61 ) +
sizeof( T_4 * ) * F_37 ( V_68 ) +
sizeof( struct V_70 ) * V_67 , V_69 ) ;
if ( V_62 ) {
V_62 -> V_63 = F_40 ( struct V_61 , V_71 [ V_67 ] ) ;
V_62 -> V_72 = - 1 ;
V_62 -> V_73 = V_68 ;
V_62 -> V_74 = 0 ;
V_62 -> V_75 = 0ULL ;
V_62 -> V_76 = V_26 ;
}
return V_62 ;
}
void F_41 ( struct V_47 * V_34 , struct V_61 * V_62 )
{
const int V_77 = V_66 / 8 - 1 ;
int V_78 ;
T_4 * * V_79 = F_36 ( V_62 ) ;
T_6 V_80 = V_62 -> V_75 ;
if ( V_62 -> V_72 == 0 )
F_42 ( V_34 -> V_81 , V_79 [ 0 ] , V_80 ) ;
for ( V_78 = 0 ; V_78 < V_62 -> V_72 ; V_78 ++ ) {
T_4 * V_82 = V_79 [ V_78 ] ;
T_6 V_83 = F_43 ( V_82 [ V_77 ] ) ;
F_42 ( V_34 -> V_84 , V_82 , V_80 ) ;
V_80 = V_83 ;
}
F_44 ( V_62 ) ;
}
static void F_45 ( struct V_85 * V_85 )
{
struct V_86 * V_87 = V_85 -> V_88 -> V_89 ;
if ( F_46 ( V_87 -> V_90 ) ) {
const int V_91 = F_47 ( V_85 ) ;
int V_92 = F_48 () ;
F_49 ( V_92 , & V_87 -> V_93 ) ;
F_50 ( V_92 , & V_87 -> V_93 , V_94 [ V_91 ] ) ;
F_51 ( V_92 , & V_87 -> V_93 , V_95 [ V_91 ] ,
F_52 ( V_85 ) ) ;
F_53 ( & V_87 -> V_93 , V_91 ) ;
F_54 () ;
}
}
static void F_55 ( struct V_85 * V_85 , unsigned long V_76 )
{
struct V_86 * V_87 = V_85 -> V_88 -> V_89 ;
if ( F_46 ( V_87 -> V_90 ) ) {
const int V_91 = F_47 ( V_85 ) ;
unsigned long V_96 = V_26 - V_76 ;
int V_92 = F_48 () ;
F_51 ( V_92 , & V_87 -> V_93 , V_97 [ V_91 ] , V_96 ) ;
F_49 ( V_92 , & V_87 -> V_93 ) ;
F_56 ( & V_87 -> V_93 , V_91 ) ;
F_54 () ;
}
}
static void F_57 ( struct V_14 * V_15 , void * V_19 ,
struct V_30 * V_31 )
{
struct V_61 * V_62 = V_19 ;
struct V_85 * V_85 = V_62 -> V_98 ;
T_3 V_44 = F_13 ( & V_31 -> V_44 ) >> 1 ;
int error = 0 ;
if ( F_58 ( V_44 ) ) {
if ( ! ( V_44 & V_99 ||
V_85 -> V_100 & V_101 ) &&
( V_26 - V_62 -> V_76 ) < V_102 ) {
if ( ! F_59 ( & V_15 -> V_28 ) )
F_60 ( & V_15 -> V_28 ,
& V_15 -> V_103 ) ;
F_61 ( & V_62 -> V_104 , & V_15 -> V_105 ) ;
F_19 ( & V_15 -> V_28 ) ;
return;
}
error = - V_106 ;
}
if ( V_62 -> V_74 ) {
F_62 ( V_15 -> V_37 , V_62 -> V_71 , V_62 -> V_74 ,
F_47 ( V_85 ) ? V_107 : V_108 ) ;
F_55 ( V_85 , V_62 -> V_76 ) ;
}
F_41 ( V_15 -> V_34 , V_62 ) ;
F_63 ( F_64 ( V_85 -> V_88 ) , V_85 , error ) ;
F_65 ( V_85 , error ) ;
}
int F_66 ( struct V_47 * V_34 , struct V_61 * V_62 , int V_109 ,
T_5 V_69 )
{
struct V_110 * V_111 ;
int V_73 = V_109 ;
struct V_70 * V_71 = V_62 -> V_71 ;
int V_112 = F_67 ( V_71 ) ;
T_7 V_113 = F_68 ( V_71 ) ;
int V_63 = F_69 ( V_113 ) ;
T_4 * V_82 ;
T_4 * * V_79 = F_36 ( V_62 ) ;
T_6 V_80 ;
int V_65 , V_78 ;
V_73 -= ( V_66 - V_63 ) ;
if ( V_73 <= 0 )
return V_109 ;
V_112 -= ( V_66 - V_63 ) ;
if ( V_112 ) {
V_113 += ( V_66 - V_63 ) ;
} else {
V_71 = F_70 ( V_71 ) ;
V_113 = F_68 ( V_71 ) ;
V_112 = F_67 ( V_71 ) ;
}
if ( V_73 <= V_66 ) {
V_62 -> V_75 = V_113 ;
return V_109 ;
}
V_65 = F_5 ( V_73 , V_66 ) ;
if ( V_65 <= ( 256 / 8 ) ) {
V_111 = V_34 -> V_81 ;
V_62 -> V_72 = 0 ;
} else {
V_111 = V_34 -> V_84 ;
V_62 -> V_72 = 1 ;
}
V_82 = F_71 ( V_111 , V_69 , & V_80 ) ;
if ( ! V_82 ) {
V_62 -> V_75 = V_113 ;
V_62 -> V_72 = - 1 ;
return ( V_109 - V_73 ) + V_66 ;
}
V_79 [ 0 ] = V_82 ;
V_62 -> V_75 = V_80 ;
V_78 = 0 ;
for (; ; ) {
if ( V_78 == V_66 / 8 ) {
T_4 * V_114 = V_82 ;
V_82 = F_71 ( V_111 , V_69 , & V_80 ) ;
if ( ! V_82 )
return V_109 - V_73 ;
V_79 [ V_62 -> V_72 ++ ] = V_82 ;
V_82 [ 0 ] = V_114 [ V_78 - 1 ] ;
V_114 [ V_78 - 1 ] = F_72 ( V_80 ) ;
V_78 = 1 ;
}
V_82 [ V_78 ++ ] = F_72 ( V_113 ) ;
V_112 -= V_66 ;
V_113 += V_66 ;
V_73 -= V_66 ;
if ( V_73 <= 0 )
break;
if ( V_112 > 0 )
continue;
F_73 ( V_112 < 0 ) ;
V_71 = F_70 ( V_71 ) ;
V_113 = F_68 ( V_71 ) ;
V_112 = F_67 ( V_71 ) ;
}
return V_109 ;
}
static int F_74 ( struct V_85 * V_85 , struct V_14 * V_15 ,
int V_115 )
{
struct V_85 * V_116 = F_75 ( V_85 , V_115 >> 9 , V_117 , NULL ) ;
if ( ! V_116 )
return - V_118 ;
F_76 ( F_64 ( V_85 -> V_88 ) , V_85 ,
V_116 -> V_119 . V_120 ) ;
F_77 ( V_116 , V_85 ) ;
if ( ! F_59 ( & V_15 -> V_28 ) )
F_60 ( & V_15 -> V_28 , & V_15 -> V_103 ) ;
F_78 ( & V_15 -> V_121 , V_116 ) ;
F_78 ( & V_15 -> V_121 , V_85 ) ;
F_19 ( & V_15 -> V_28 ) ;
return 0 ;
}
static int F_79 ( struct V_14 * V_15 , struct V_61 * V_62 ,
struct V_85 * V_85 , enum V_122 V_123 , int V_124 )
{
struct V_125 V_126 , V_127 ;
struct V_128 V_129 ;
struct V_70 * V_71 = NULL ;
int V_73 = 0 , V_130 = 0 , V_131 = V_85 -> V_119 . V_132 ;
int V_133 = 1 ;
if ( V_15 -> V_34 -> V_134 )
V_131 = V_15 -> V_34 -> V_134 -
( ( V_85 -> V_119 . V_120 << 9 ) &
( V_15 -> V_34 -> V_134 - 1 ) ) ;
F_80 ( V_62 -> V_71 , V_124 ) ;
F_81 (bvec, bio, iter) {
if ( ! V_133 && F_82 ( & V_127 , & V_126 ) ) {
V_71 -> V_73 += V_126 . V_135 ;
} else {
if ( ! V_133 && F_83 ( & V_127 , & V_126 ) )
return F_74 ( V_85 , V_15 ,
V_73 ) ;
V_71 = V_71 ? V_71 + 1 : V_62 -> V_71 ;
F_84 ( V_71 , V_126 . V_136 ,
V_126 . V_135 , V_126 . V_137 ) ;
V_130 ++ ;
}
if ( V_131 - V_73 < V_126 . V_135 )
return F_74 ( V_85 , V_15 , V_131 ) ;
V_73 += V_126 . V_135 ;
V_127 = V_126 ;
V_133 = 0 ;
}
V_62 -> V_74 = V_130 ;
F_85 ( V_71 ) ;
if ( F_86 ( V_15 -> V_37 , V_62 -> V_71 , V_62 -> V_74 , V_123 ) == 0 )
return - V_118 ;
F_73 ( V_73 != V_85 -> V_119 . V_132 ) ;
return V_73 ;
}
static int F_87 ( struct V_14 * V_15 , struct V_138 * V_139 ,
struct V_85 * V_85 , struct V_61 * V_62 , int V_23 )
{
struct V_140 * V_141 =
(struct V_140 * ) F_36 ( V_62 ) [ 0 ] ;
struct V_8 * V_142 = & V_15 -> V_59 [ V_15 -> V_58 ] ;
V_141 -> V_143 = F_88 ( 0 ) ;
V_141 -> V_144 = F_88 ( V_85 -> V_119 . V_132 >> V_139 -> V_145 ) ;
V_141 -> V_146 = F_72 ( F_89 ( V_139 , V_85 -> V_119 . V_120 ) ) ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_147 . V_148 = V_149 ;
V_142 -> V_147 . V_38 = V_23 ;
V_142 -> V_147 . V_150 = F_88 ( V_139 -> V_151 ) ;
V_142 -> V_147 . V_152 = F_72 ( V_62 -> V_75 ) ;
V_142 -> V_147 . V_153 = 0 ;
V_142 -> V_147 . V_154 = F_88 ( V_155 ) ;
if ( ++ V_15 -> V_58 == V_15 -> V_17 )
V_15 -> V_58 = 0 ;
F_35 ( V_15 -> V_58 , V_15 -> V_60 ) ;
return 0 ;
}
static int F_90 ( struct V_14 * V_15 , struct V_138 * V_139 ,
int V_23 )
{
struct V_8 * V_142 = & V_15 -> V_59 [ V_15 -> V_58 ] ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_156 . V_148 = V_157 ;
V_142 -> V_156 . V_38 = V_23 ;
V_142 -> V_156 . V_150 = F_88 ( V_139 -> V_151 ) ;
if ( ++ V_15 -> V_58 == V_15 -> V_17 )
V_15 -> V_58 = 0 ;
F_35 ( V_15 -> V_58 , V_15 -> V_60 ) ;
return 0 ;
}
static int F_91 ( struct V_14 * V_15 , struct V_61 * V_62 )
{
struct V_85 * V_85 = V_62 -> V_98 ;
struct V_138 * V_139 = V_85 -> V_88 -> V_89 -> V_158 ;
struct V_8 * V_142 ;
int V_23 ;
T_3 V_159 ;
T_8 V_160 ;
V_23 = F_6 ( V_15 , V_62 , F_57 , V_161 ) ;
if ( F_58 ( V_23 < 0 ) )
return V_23 ;
if ( V_85 -> V_100 & V_162 )
return F_87 ( V_15 , V_139 , V_85 , V_62 , V_23 ) ;
if ( V_85 -> V_100 & V_163 )
return F_90 ( V_15 , V_139 , V_23 ) ;
V_159 = 0 ;
if ( V_85 -> V_100 & V_164 )
V_159 |= V_165 ;
if ( V_85 -> V_100 & ( V_166 | V_167 ) )
V_159 |= V_168 ;
V_160 = 0 ;
if ( V_85 -> V_100 & V_167 )
V_160 |= V_169 ;
V_142 = & V_15 -> V_59 [ V_15 -> V_58 ] ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_91 . V_148 = F_47 ( V_85 ) ? V_170 : V_171 ;
V_142 -> V_91 . V_38 = V_23 ;
V_142 -> V_91 . V_150 = F_88 ( V_139 -> V_151 ) ;
V_142 -> V_91 . V_152 = F_72 ( F_68 ( V_62 -> V_71 ) ) ;
V_142 -> V_91 . V_172 = F_72 ( V_62 -> V_75 ) ;
V_142 -> V_91 . V_146 = F_72 ( F_89 ( V_139 , V_85 -> V_119 . V_120 ) ) ;
V_142 -> V_91 . V_73 =
F_92 ( ( V_85 -> V_119 . V_132 >> V_139 -> V_145 ) - 1 ) ;
V_142 -> V_91 . V_159 = F_92 ( V_159 ) ;
V_142 -> V_91 . V_160 = F_88 ( V_160 ) ;
if ( ++ V_15 -> V_58 == V_15 -> V_17 )
V_15 -> V_58 = 0 ;
F_35 ( V_15 -> V_58 , V_15 -> V_60 ) ;
return 0 ;
}
static int F_93 ( struct V_14 * V_15 , struct V_85 * V_85 )
{
struct V_85 * V_116 = F_94 ( V_85 , V_117 ) ;
if ( ! V_116 )
return - V_118 ;
V_116 -> V_119 . V_132 = 0 ;
V_116 -> V_173 = 0 ;
V_85 -> V_100 &= ~ V_163 ;
F_77 ( V_116 , V_85 ) ;
if ( ! F_59 ( & V_15 -> V_28 ) )
F_60 ( & V_15 -> V_28 , & V_15 -> V_103 ) ;
F_78 ( & V_15 -> V_121 , V_116 ) ;
F_78 ( & V_15 -> V_121 , V_85 ) ;
F_95 ( V_174 ) ;
return 0 ;
}
static int F_96 ( struct V_14 * V_15 , struct V_138 * V_139 ,
struct V_85 * V_85 )
{
struct V_61 * V_62 ;
int V_124 = F_97 ( V_139 -> V_90 , V_85 ) ;
int V_43 ;
if ( ( V_85 -> V_100 & V_163 ) && V_124 )
return F_93 ( V_15 , V_85 ) ;
V_62 = F_38 ( V_124 , V_85 -> V_119 . V_132 , V_117 ) ;
if ( ! V_62 )
return - V_118 ;
V_62 -> V_98 = V_85 ;
if ( V_85 -> V_100 & V_162 ) {
void * V_141 ;
V_141 = F_71 ( V_15 -> V_34 -> V_81 ,
V_117 ,
& V_62 -> V_75 ) ;
if ( ! V_141 ) {
V_43 = - V_118 ;
goto V_175;
}
F_36 ( V_62 ) [ 0 ] = ( T_4 * ) V_141 ;
V_62 -> V_72 = 0 ;
} else if ( V_124 ) {
V_43 = F_79 ( V_15 , V_62 , V_85 ,
F_47 ( V_85 ) ? V_107 : V_108 ,
V_124 ) ;
if ( V_43 <= 0 )
goto V_175;
if ( F_66 ( V_15 -> V_34 , V_62 , V_43 , V_117 ) !=
V_43 ) {
V_43 = - V_118 ;
goto V_175;
}
F_45 ( V_85 ) ;
}
if ( F_58 ( F_91 ( V_15 , V_62 ) ) ) {
if ( ! F_59 ( & V_15 -> V_28 ) )
F_60 ( & V_15 -> V_28 , & V_15 -> V_103 ) ;
F_61 ( & V_62 -> V_104 , & V_15 -> V_105 ) ;
}
return 0 ;
V_175:
F_41 ( V_15 -> V_34 , V_62 ) ;
return V_43 ;
}
static int F_98 ( struct V_14 * V_15 )
{
T_3 V_176 , V_177 ;
V_176 = V_15 -> V_178 ;
V_177 = V_15 -> V_179 ;
for (; ; ) {
void * V_19 ;
T_1 V_25 ;
struct V_30 V_31 = V_15 -> V_180 [ V_176 ] ;
if ( ( F_99 ( V_31 . V_44 ) & 1 ) != V_177 )
break;
V_15 -> V_181 = F_99 ( V_31 . V_181 ) ;
if ( ++ V_176 == V_15 -> V_17 ) {
V_176 = 0 ;
V_177 = ! V_177 ;
}
V_19 = F_17 ( V_15 , V_31 . V_38 , & V_25 ) ;
V_25 ( V_15 , V_19 , & V_31 ) ;
}
if ( V_176 == V_15 -> V_178 && V_177 == V_15 -> V_179 )
return 0 ;
F_35 ( V_176 , V_15 -> V_60 + V_15 -> V_34 -> V_182 ) ;
V_15 -> V_178 = V_176 ;
V_15 -> V_179 = V_177 ;
V_15 -> V_183 = 1 ;
return 1 ;
}
static void F_100 ( struct V_184 * V_185 , struct V_85 * V_85 )
{
struct V_138 * V_139 = V_185 -> V_186 ;
struct V_14 * V_15 = F_23 ( V_139 -> V_34 ) ;
int V_43 = - V_24 ;
if ( ! V_15 ) {
F_65 ( V_85 , - V_106 ) ;
return;
}
F_101 ( & V_15 -> V_56 ) ;
if ( ! V_15 -> V_57 && F_102 ( & V_15 -> V_121 ) )
V_43 = F_96 ( V_15 , V_139 , V_85 ) ;
if ( F_58 ( V_43 ) ) {
if ( ! F_59 ( & V_15 -> V_28 ) )
F_60 ( & V_15 -> V_28 , & V_15 -> V_103 ) ;
F_78 ( & V_15 -> V_121 , V_85 ) ;
}
F_98 ( V_15 ) ;
F_103 ( & V_15 -> V_56 ) ;
F_29 ( V_15 ) ;
}
static T_9 F_104 ( int V_187 , void * V_188 )
{
T_9 V_43 ;
struct V_14 * V_15 = V_188 ;
F_105 ( & V_15 -> V_56 ) ;
F_98 ( V_15 ) ;
V_43 = V_15 -> V_183 ? V_189 : V_190 ;
V_15 -> V_183 = 0 ;
F_106 ( & V_15 -> V_56 ) ;
return V_43 ;
}
static T_9 F_107 ( int V_187 , void * V_188 )
{
struct V_14 * V_15 = V_188 ;
struct V_30 V_31 = V_15 -> V_180 [ V_15 -> V_178 ] ;
if ( ( F_99 ( V_31 . V_44 ) & 1 ) != V_15 -> V_179 )
return V_190 ;
return V_191 ;
}
static void F_108 ( struct V_14 * V_15 , int V_23 )
{
F_101 ( & V_15 -> V_56 ) ;
F_20 ( V_15 , V_23 , NULL ) ;
F_103 ( & V_15 -> V_56 ) ;
}
static void F_109 ( struct V_14 * V_15 , void * V_19 ,
struct V_30 * V_31 )
{
struct V_192 * V_42 = V_19 ;
V_42 -> V_43 = F_15 ( & V_31 -> V_43 ) ;
V_42 -> V_44 = F_13 ( & V_31 -> V_44 ) >> 1 ;
F_95 ( V_42 -> V_193 ) ;
}
static int F_110 ( struct V_47 * V_34 , int V_52 ,
struct V_8 * V_53 ,
T_8 * V_43 , unsigned V_21 )
{
int V_23 , V_194 ;
struct V_192 V_42 ;
struct V_14 * V_15 ;
V_15 = F_30 ( V_34 , V_52 ) ;
if ( ! V_15 )
return - V_195 ;
V_42 . V_193 = V_196 ;
V_42 . V_44 = - V_29 ;
V_23 = F_6 ( V_15 , & V_42 , F_109 , V_21 ) ;
if ( V_23 < 0 ) {
F_31 ( V_15 ) ;
return V_23 ;
}
V_53 -> V_156 . V_38 = V_23 ;
F_111 ( V_197 ) ;
V_194 = F_32 ( V_15 , V_53 ) ;
if ( V_194 ) {
F_17 ( V_15 , V_23 , NULL ) ;
F_31 ( V_15 ) ;
F_111 ( V_198 ) ;
return V_194 ;
}
F_31 ( V_15 ) ;
F_112 ( V_21 ) ;
if ( V_42 . V_44 == - V_29 ) {
V_15 = F_30 ( V_34 , V_52 ) ;
if ( V_15 ) {
F_108 ( V_15 , V_23 ) ;
F_31 ( V_15 ) ;
}
return - V_29 ;
}
if ( V_43 )
* V_43 = V_42 . V_43 ;
return V_42 . V_44 ;
}
static int F_113 ( struct V_14 * V_15 ,
struct V_8 * V_53 ,
struct V_41 * V_42 , unsigned V_21 )
{
int V_23 ;
V_23 = F_9 ( V_15 , V_42 , F_14 , V_21 ) ;
if ( V_23 < 0 )
return V_23 ;
V_42 -> V_44 = - V_29 ;
V_53 -> V_156 . V_38 = V_23 ;
return F_32 ( V_15 , V_53 ) ;
}
int F_114 ( struct V_47 * V_34 , struct V_8 * V_53 ,
T_8 * V_43 )
{
return F_110 ( V_34 , 0 , V_53 , V_43 , V_199 ) ;
}
int F_115 ( struct V_47 * V_34 , struct V_8 * V_53 ,
T_8 * V_43 )
{
return F_110 ( V_34 , F_116 () + 1 , V_53 , V_43 ,
V_161 ) ;
}
static int F_117 ( struct V_47 * V_34 ,
struct V_8 * V_53 , struct V_41 * V_42 )
{
return F_113 ( F_21 ( V_34 , 0 ) , V_53 , V_42 ,
V_199 ) ;
}
static int F_118 ( struct V_47 * V_34 , T_10 V_148 , T_3 V_200 )
{
int V_44 ;
struct V_8 V_201 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_202 . V_148 = V_148 ;
V_201 . V_202 . V_48 = F_92 ( V_200 ) ;
V_44 = F_114 ( V_34 , & V_201 , NULL ) ;
if ( V_44 )
return - V_106 ;
return 0 ;
}
static int F_119 ( struct V_47 * V_34 , T_3 V_48 ,
struct V_14 * V_15 )
{
int V_44 ;
struct V_8 V_201 ;
int V_54 = V_203 | V_204 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_205 . V_148 = V_206 ;
V_201 . V_205 . V_152 = F_72 ( V_15 -> V_207 ) ;
V_201 . V_205 . V_208 = F_92 ( V_48 ) ;
V_201 . V_205 . V_209 = F_92 ( V_15 -> V_17 - 1 ) ;
V_201 . V_205 . V_210 = F_92 ( V_54 ) ;
V_201 . V_205 . V_211 = F_92 ( V_15 -> V_212 ) ;
V_44 = F_114 ( V_34 , & V_201 , NULL ) ;
if ( V_44 )
return - V_106 ;
return 0 ;
}
static int F_120 ( struct V_47 * V_34 , T_3 V_48 ,
struct V_14 * V_15 )
{
int V_44 ;
struct V_8 V_201 ;
int V_54 = V_203 | V_213 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_214 . V_148 = V_215 ;
V_201 . V_214 . V_152 = F_72 ( V_15 -> V_216 ) ;
V_201 . V_214 . V_217 = F_92 ( V_48 ) ;
V_201 . V_214 . V_209 = F_92 ( V_15 -> V_17 - 1 ) ;
V_201 . V_214 . V_218 = F_92 ( V_54 ) ;
V_201 . V_214 . V_208 = F_92 ( V_48 ) ;
V_44 = F_114 ( V_34 , & V_201 , NULL ) ;
if ( V_44 )
return - V_106 ;
return 0 ;
}
static int F_121 ( struct V_47 * V_34 , T_3 V_208 )
{
return F_118 ( V_34 , V_219 , V_208 ) ;
}
static int F_122 ( struct V_47 * V_34 , T_3 V_217 )
{
return F_118 ( V_34 , V_220 , V_217 ) ;
}
int F_123 ( struct V_47 * V_34 , unsigned V_150 , unsigned V_221 ,
T_6 V_113 )
{
struct V_8 V_201 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_222 . V_148 = V_223 ;
V_201 . V_222 . V_150 = F_88 ( V_150 ) ;
V_201 . V_222 . V_152 = F_72 ( V_113 ) ;
V_201 . V_222 . V_221 = F_88 ( V_221 ) ;
return F_114 ( V_34 , & V_201 , NULL ) ;
}
int F_124 ( struct V_47 * V_34 , unsigned V_224 , unsigned V_150 ,
T_6 V_113 , T_8 * V_43 )
{
struct V_8 V_201 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_225 . V_148 = V_226 ;
V_201 . V_225 . V_150 = F_88 ( V_150 ) ;
V_201 . V_225 . V_152 = F_72 ( V_113 ) ;
V_201 . V_225 . V_224 = F_88 ( V_224 ) ;
return F_114 ( V_34 , & V_201 , V_43 ) ;
}
int F_125 ( struct V_47 * V_34 , unsigned V_224 , unsigned V_227 ,
T_6 V_113 , T_8 * V_43 )
{
struct V_8 V_201 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_225 . V_148 = V_228 ;
V_201 . V_225 . V_152 = F_72 ( V_113 ) ;
V_201 . V_225 . V_224 = F_88 ( V_224 ) ;
V_201 . V_225 . V_227 = F_88 ( V_227 ) ;
return F_114 ( V_34 , & V_201 , V_43 ) ;
}
static void V_7 ( int V_23 , struct V_14 * V_15 )
{
int V_229 ;
struct V_8 V_53 ;
struct V_47 * V_34 = V_15 -> V_34 ;
struct V_13 * V_22 = V_13 ( V_15 ) ;
struct V_14 * V_230 ;
if ( ! V_15 -> V_48 || V_22 [ V_23 ] . V_27 ) {
if ( F_126 ( & V_34 -> V_231 ) )
return;
F_127 ( & V_34 -> V_104 ) ;
F_12 ( & V_34 -> V_232 -> V_34 ,
L_4 , V_23 ,
V_15 -> V_48 ) ;
V_34 -> V_233 = V_234 ;
F_128 ( V_235 , & V_34 -> V_231 ) ;
return;
}
if ( ! V_34 -> V_35 )
return;
V_230 = F_26 ( V_34 -> V_49 [ 0 ] ) ;
V_229 = F_6 ( V_230 , V_33 , F_11 ,
V_199 ) ;
if ( V_229 < 0 )
return;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . abort . V_148 = V_236 ;
V_53 . abort . V_237 = V_23 ;
V_53 . abort . V_217 = F_92 ( V_15 -> V_48 ) ;
V_53 . abort . V_38 = V_229 ;
-- V_34 -> V_35 ;
V_22 [ V_23 ] . V_27 = 1 ;
V_22 [ V_23 ] . V_21 = V_26 + V_199 ;
F_12 ( V_15 -> V_37 , L_5 , V_23 ,
V_15 -> V_48 ) ;
F_32 ( V_230 , & V_53 ) ;
}
static void F_129 ( struct V_14 * V_15 , bool V_21 )
{
int V_18 = V_15 -> V_17 - 1 ;
struct V_13 * V_22 = V_13 ( V_15 ) ;
unsigned long V_238 = V_26 ;
int V_23 ;
F_130 (cmdid, nvmeq->cmdid_data, depth) {
void * V_19 ;
T_1 V_25 ;
static struct V_30 V_31 = {
. V_44 = F_92 ( V_239 << 1 ) ,
} ;
if ( V_21 && ! F_131 ( V_238 , V_22 [ V_23 ] . V_21 ) )
continue;
if ( V_22 [ V_23 ] . V_19 == V_32 )
continue;
if ( V_21 && V_15 -> V_34 -> V_240 ) {
V_7 ( V_23 , V_15 ) ;
continue;
}
F_12 ( V_15 -> V_37 , L_6 , V_23 ,
V_15 -> V_48 ) ;
V_19 = F_20 ( V_15 , V_23 , & V_25 ) ;
V_25 ( V_15 , V_19 , & V_31 ) ;
}
}
static void F_132 ( struct V_241 * V_242 )
{
struct V_14 * V_15 = F_133 ( V_242 , struct V_14 , V_243 ) ;
F_101 ( & V_15 -> V_56 ) ;
while ( F_134 ( & V_15 -> V_121 ) ) {
struct V_85 * V_85 = F_135 ( & V_15 -> V_121 ) ;
F_65 ( V_85 , - V_106 ) ;
}
while ( ! F_136 ( & V_15 -> V_105 ) ) {
static struct V_30 V_31 = {
. V_44 = F_92 (
( V_239 | V_99 ) << 1 ) ,
} ;
struct V_61 * V_62 = F_137 ( & V_15 -> V_105 ,
struct V_61 ,
V_104 ) ;
F_138 ( & V_62 -> V_104 ) ;
F_57 ( V_15 , V_62 , & V_31 ) ;
}
F_103 ( & V_15 -> V_56 ) ;
F_139 ( V_15 -> V_37 , F_140 ( V_15 -> V_17 ) ,
( void * ) V_15 -> V_180 , V_15 -> V_207 ) ;
F_139 ( V_15 -> V_37 , F_141 ( V_15 -> V_17 ) ,
V_15 -> V_59 , V_15 -> V_216 ) ;
if ( V_15 -> V_48 )
F_142 ( V_15 -> V_244 ) ;
F_44 ( V_15 ) ;
}
static void F_143 ( struct V_47 * V_34 , int V_245 )
{
int V_78 ;
for ( V_78 = V_34 -> V_246 - 1 ; V_78 >= V_245 ; V_78 -- ) {
struct V_14 * V_15 = F_21 ( V_34 , V_78 ) ;
F_144 ( V_34 -> V_49 [ V_78 ] , NULL ) ;
F_145 ( & V_15 -> V_243 , F_132 ) ;
V_34 -> V_246 -- ;
}
}
static int F_146 ( struct V_14 * V_15 )
{
int V_247 = V_15 -> V_34 -> V_248 [ V_15 -> V_212 ] . V_247 ;
F_101 ( & V_15 -> V_56 ) ;
if ( V_15 -> V_57 ) {
F_103 ( & V_15 -> V_56 ) ;
return 1 ;
}
V_15 -> V_57 = 1 ;
V_15 -> V_34 -> V_249 -- ;
F_103 ( & V_15 -> V_56 ) ;
F_147 ( V_247 , NULL ) ;
F_148 ( V_247 , V_15 ) ;
return 0 ;
}
static void F_149 ( struct V_14 * V_15 )
{
F_101 ( & V_15 -> V_56 ) ;
F_98 ( V_15 ) ;
F_129 ( V_15 , false ) ;
F_103 ( & V_15 -> V_56 ) ;
}
static void F_150 ( struct V_47 * V_34 , int V_48 )
{
struct V_14 * V_15 = F_21 ( V_34 , V_48 ) ;
if ( ! V_15 )
return;
if ( F_146 ( V_15 ) )
return;
if ( V_48 && F_151 ( & V_34 -> V_250 -> V_251 ) != - 1 ) {
F_122 ( V_34 , V_48 ) ;
F_121 ( V_34 , V_48 ) ;
}
F_149 ( V_15 ) ;
}
static struct V_14 * F_152 ( struct V_47 * V_34 , int V_48 ,
int V_18 , int V_247 )
{
struct V_252 * V_253 = & V_34 -> V_232 -> V_34 ;
unsigned V_254 = F_4 ( V_18 ) ;
struct V_14 * V_15 = F_153 ( sizeof( * V_15 ) + V_254 , V_255 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_180 = F_154 ( V_253 , F_140 ( V_18 ) ,
& V_15 -> V_207 , V_255 ) ;
if ( ! V_15 -> V_180 )
goto V_256;
memset ( ( void * ) V_15 -> V_180 , 0 , F_140 ( V_18 ) ) ;
V_15 -> V_59 = F_154 ( V_253 , F_141 ( V_18 ) ,
& V_15 -> V_216 , V_255 ) ;
if ( ! V_15 -> V_59 )
goto V_257;
if ( V_48 && ! F_155 ( & V_15 -> V_244 , V_255 ) )
goto V_258;
V_15 -> V_37 = V_253 ;
V_15 -> V_34 = V_34 ;
snprintf ( V_15 -> V_259 , sizeof( V_15 -> V_259 ) , L_7 ,
V_34 -> V_260 , V_48 ) ;
F_156 ( & V_15 -> V_56 ) ;
V_15 -> V_178 = 0 ;
V_15 -> V_179 = 1 ;
F_157 ( & V_15 -> V_28 ) ;
F_158 ( & V_15 -> V_103 , V_174 ) ;
F_159 ( & V_15 -> V_121 ) ;
F_160 ( & V_15 -> V_105 ) ;
V_15 -> V_60 = & V_34 -> V_261 [ V_48 * 2 * V_34 -> V_182 ] ;
V_15 -> V_17 = V_18 ;
V_15 -> V_212 = V_247 ;
V_15 -> V_48 = V_48 ;
V_15 -> V_57 = 1 ;
V_34 -> V_246 ++ ;
F_144 ( V_34 -> V_49 [ V_48 ] , V_15 ) ;
return V_15 ;
V_258:
F_139 ( V_253 , F_141 ( V_18 ) , ( void * ) V_15 -> V_59 ,
V_15 -> V_216 ) ;
V_257:
F_139 ( V_253 , F_140 ( V_18 ) , ( void * ) V_15 -> V_180 ,
V_15 -> V_207 ) ;
V_256:
F_44 ( V_15 ) ;
return NULL ;
}
static int F_161 ( struct V_47 * V_34 , struct V_14 * V_15 ,
const char * V_262 )
{
if ( V_263 )
return F_162 ( V_34 -> V_248 [ V_15 -> V_212 ] . V_247 ,
F_107 , F_104 , V_264 ,
V_262 , V_15 ) ;
return F_163 ( V_34 -> V_248 [ V_15 -> V_212 ] . V_247 , F_104 ,
V_264 , V_262 , V_15 ) ;
}
static void F_164 ( struct V_14 * V_15 , T_3 V_48 )
{
struct V_47 * V_34 = V_15 -> V_34 ;
unsigned V_254 = F_4 ( V_15 -> V_17 ) ;
V_15 -> V_58 = 0 ;
V_15 -> V_178 = 0 ;
V_15 -> V_179 = 1 ;
V_15 -> V_60 = & V_34 -> V_261 [ V_48 * 2 * V_34 -> V_182 ] ;
memset ( V_15 -> V_16 , 0 , V_254 ) ;
memset ( ( void * ) V_15 -> V_180 , 0 , F_140 ( V_15 -> V_17 ) ) ;
F_129 ( V_15 , false ) ;
V_15 -> V_57 = 0 ;
V_34 -> V_249 ++ ;
}
static int F_165 ( struct V_14 * V_15 , int V_48 )
{
struct V_47 * V_34 = V_15 -> V_34 ;
int V_43 ;
V_43 = F_119 ( V_34 , V_48 , V_15 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_120 ( V_34 , V_48 , V_15 ) ;
if ( V_43 < 0 )
goto V_265;
V_43 = F_161 ( V_34 , V_15 , V_15 -> V_259 ) ;
if ( V_43 < 0 )
goto V_266;
F_101 ( & V_15 -> V_56 ) ;
F_164 ( V_15 , V_48 ) ;
F_103 ( & V_15 -> V_56 ) ;
return V_43 ;
V_266:
F_122 ( V_34 , V_48 ) ;
V_265:
F_121 ( V_34 , V_48 ) ;
return V_43 ;
}
static int F_166 ( struct V_47 * V_34 , T_7 V_267 , bool V_268 )
{
unsigned long V_21 ;
T_8 V_269 = V_268 ? V_270 : 0 ;
V_21 = ( ( F_167 ( V_267 ) + 1 ) * V_271 / 2 ) + V_26 ;
while ( ( F_151 ( & V_34 -> V_250 -> V_251 ) & V_270 ) != V_269 ) {
F_168 ( 100 ) ;
if ( F_169 ( V_196 ) )
return - V_29 ;
if ( F_131 ( V_26 , V_21 ) ) {
F_170 ( & V_34 -> V_232 -> V_34 ,
L_8 , V_268 ?
L_9 : L_10 ) ;
return - V_195 ;
}
}
return 0 ;
}
static int F_171 ( struct V_47 * V_34 , T_7 V_267 )
{
T_8 V_272 = F_151 ( & V_34 -> V_250 -> V_272 ) ;
if ( V_272 & V_273 )
F_35 ( V_272 & ~ V_273 , & V_34 -> V_250 -> V_272 ) ;
return F_166 ( V_34 , V_267 , false ) ;
}
static int F_172 ( struct V_47 * V_34 , T_7 V_267 )
{
return F_166 ( V_34 , V_267 , true ) ;
}
static int F_173 ( struct V_47 * V_34 )
{
unsigned long V_21 ;
T_8 V_272 ;
V_272 = ( F_151 ( & V_34 -> V_250 -> V_272 ) & ~ V_274 ) | V_275 ;
F_35 ( V_272 , & V_34 -> V_250 -> V_272 ) ;
V_21 = 2 * V_271 + V_26 ;
while ( ( F_151 ( & V_34 -> V_250 -> V_251 ) & V_276 ) !=
V_277 ) {
F_168 ( 100 ) ;
if ( F_169 ( V_196 ) )
return - V_29 ;
if ( F_131 ( V_26 , V_21 ) ) {
F_170 ( & V_34 -> V_232 -> V_34 ,
L_11 ) ;
return - V_195 ;
}
}
return 0 ;
}
static int F_174 ( struct V_47 * V_34 )
{
int V_43 ;
T_8 V_278 ;
T_7 V_267 = F_175 ( & V_34 -> V_250 -> V_267 ) ;
struct V_14 * V_15 ;
V_43 = F_171 ( V_34 , V_267 ) ;
if ( V_43 < 0 )
return V_43 ;
V_15 = F_21 ( V_34 , 0 ) ;
if ( ! V_15 ) {
V_15 = F_152 ( V_34 , 0 , 64 , 0 ) ;
if ( ! V_15 )
return - V_118 ;
}
V_278 = V_15 -> V_17 - 1 ;
V_278 |= V_278 << 16 ;
V_34 -> V_279 = V_273 | V_280 ;
V_34 -> V_279 |= ( V_281 - 12 ) << V_282 ;
V_34 -> V_279 |= V_283 | V_284 ;
V_34 -> V_279 |= V_285 | V_286 ;
F_35 ( V_278 , & V_34 -> V_250 -> V_278 ) ;
F_176 ( V_15 -> V_216 , & V_34 -> V_250 -> V_287 ) ;
F_176 ( V_15 -> V_207 , & V_34 -> V_250 -> V_288 ) ;
F_35 ( V_34 -> V_279 , & V_34 -> V_250 -> V_272 ) ;
V_43 = F_172 ( V_34 , V_267 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_161 ( V_34 , V_15 , V_15 -> V_259 ) ;
if ( V_43 )
return V_43 ;
F_101 ( & V_15 -> V_56 ) ;
F_164 ( V_15 , 0 ) ;
F_103 ( & V_15 -> V_56 ) ;
return V_43 ;
}
struct V_61 * F_177 ( struct V_47 * V_34 , int V_289 ,
unsigned long V_290 , unsigned V_73 )
{
int V_78 , V_291 , V_292 , V_74 , V_63 ;
struct V_70 * V_71 ;
struct V_293 * * V_294 ;
struct V_61 * V_62 ;
if ( V_290 & 3 )
return F_178 ( - V_295 ) ;
if ( ! V_73 || V_73 > V_296 - V_66 )
return F_178 ( - V_295 ) ;
V_63 = F_69 ( V_290 ) ;
V_292 = F_5 ( V_63 + V_73 , V_66 ) ;
V_294 = F_179 ( V_292 , sizeof( * V_294 ) , V_255 ) ;
if ( ! V_294 )
return F_178 ( - V_118 ) ;
V_291 = F_180 ( V_290 , V_292 , 1 , V_294 ) ;
if ( V_291 < V_292 ) {
V_292 = V_291 ;
V_291 = - V_297 ;
goto V_298;
}
V_291 = - V_118 ;
V_62 = F_38 ( V_292 , V_73 , V_255 ) ;
if ( ! V_62 )
goto V_298;
V_71 = V_62 -> V_71 ;
F_80 ( V_71 , V_292 ) ;
for ( V_78 = 0 ; V_78 < V_292 ; V_78 ++ ) {
F_84 ( & V_71 [ V_78 ] , V_294 [ V_78 ] ,
F_181 ( unsigned , V_73 , V_66 - V_63 ) ,
V_63 ) ;
V_73 -= ( V_66 - V_63 ) ;
V_63 = 0 ;
}
F_85 ( & V_71 [ V_78 - 1 ] ) ;
V_62 -> V_74 = V_292 ;
V_74 = F_86 ( & V_34 -> V_232 -> V_34 , V_71 , V_292 ,
V_289 ? V_107 : V_108 ) ;
if ( ! V_74 )
goto V_175;
F_44 ( V_294 ) ;
return V_62 ;
V_175:
F_44 ( V_62 ) ;
V_298:
for ( V_78 = 0 ; V_78 < V_292 ; V_78 ++ )
F_182 ( V_294 [ V_78 ] ) ;
F_44 ( V_294 ) ;
return F_178 ( V_291 ) ;
}
void F_183 ( struct V_47 * V_34 , int V_289 ,
struct V_61 * V_62 )
{
int V_78 ;
F_62 ( & V_34 -> V_232 -> V_34 , V_62 -> V_71 , V_62 -> V_74 ,
V_289 ? V_107 : V_108 ) ;
for ( V_78 = 0 ; V_78 < V_62 -> V_74 ; V_78 ++ )
F_182 ( F_184 ( & V_62 -> V_71 [ V_78 ] ) ) ;
}
static int F_185 ( struct V_138 * V_139 , struct V_299 T_11 * V_300 )
{
struct V_47 * V_34 = V_139 -> V_34 ;
struct V_299 V_301 ;
struct V_8 V_201 ;
unsigned V_73 , V_302 ;
int V_44 , V_78 ;
struct V_61 * V_62 , * V_303 = NULL ;
T_6 V_304 ;
void * V_305 , * V_306 ( V_307 ) ;
if ( F_186 ( & V_301 , V_300 , sizeof( V_301 ) ) )
return - V_297 ;
V_73 = ( V_301 . V_308 + 1 ) << V_139 -> V_145 ;
V_302 = ( V_301 . V_308 + 1 ) * V_139 -> V_309 ;
if ( V_302 && ( ( V_301 . V_310 & 3 ) || ! V_301 . V_310 ) )
return - V_295 ;
switch ( V_301 . V_148 ) {
case V_170 :
case V_171 :
case V_311 :
V_62 = F_177 ( V_34 , V_301 . V_148 & 1 , V_301 . V_290 , V_73 ) ;
break;
default:
return - V_295 ;
}
if ( F_187 ( V_62 ) )
return F_188 ( V_62 ) ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_91 . V_148 = V_301 . V_148 ;
V_201 . V_91 . V_54 = V_301 . V_54 ;
V_201 . V_91 . V_150 = F_88 ( V_139 -> V_151 ) ;
V_201 . V_91 . V_146 = F_72 ( V_301 . V_146 ) ;
V_201 . V_91 . V_73 = F_92 ( V_301 . V_308 ) ;
V_201 . V_91 . V_159 = F_92 ( V_301 . V_159 ) ;
V_201 . V_91 . V_160 = F_88 ( V_301 . V_160 ) ;
V_201 . V_91 . V_312 = F_88 ( V_301 . V_312 ) ;
V_201 . V_91 . V_313 = F_92 ( V_301 . V_313 ) ;
V_201 . V_91 . V_314 = F_92 ( V_301 . V_314 ) ;
if ( V_302 ) {
V_303 = F_177 ( V_34 , V_301 . V_148 & 1 , V_301 . V_310 ,
V_302 ) ;
if ( F_187 ( V_303 ) ) {
V_44 = F_188 ( V_303 ) ;
V_303 = NULL ;
goto V_315;
}
V_307 = F_154 ( & V_34 -> V_232 -> V_34 , V_302 ,
& V_304 , V_255 ) ;
if ( ! V_307 ) {
V_44 = - V_118 ;
goto V_315;
}
if ( V_301 . V_148 & 1 ) {
int V_316 = 0 ;
for ( V_78 = 0 ; V_78 < V_303 -> V_74 ; V_78 ++ ) {
V_305 = F_189 ( F_184 ( & V_303 -> V_71 [ V_78 ] ) ) +
V_303 -> V_71 [ V_78 ] . V_63 ;
memcpy ( V_307 + V_316 , V_305 ,
V_303 -> V_71 [ V_78 ] . V_73 ) ;
F_190 ( V_305 ) ;
V_316 += V_303 -> V_71 [ V_78 ] . V_73 ;
}
}
V_201 . V_91 . V_310 = F_72 ( V_304 ) ;
}
V_73 = F_66 ( V_34 , V_62 , V_73 , V_255 ) ;
V_201 . V_91 . V_152 = F_72 ( F_68 ( V_62 -> V_71 ) ) ;
V_201 . V_91 . V_172 = F_72 ( V_62 -> V_75 ) ;
if ( V_73 != ( V_301 . V_308 + 1 ) << V_139 -> V_145 )
V_44 = - V_118 ;
else
V_44 = F_115 ( V_34 , & V_201 , NULL ) ;
if ( V_302 ) {
if ( V_44 == V_317 && ! ( V_301 . V_148 & 1 ) ) {
int V_316 = 0 ;
for ( V_78 = 0 ; V_78 < V_303 -> V_74 ; V_78 ++ ) {
V_305 = F_189 ( F_184 ( & V_303 -> V_71 [ V_78 ] ) ) +
V_303 -> V_71 [ V_78 ] . V_63 ;
memcpy ( V_305 , V_307 + V_316 ,
V_303 -> V_71 [ V_78 ] . V_73 ) ;
F_190 ( V_305 ) ;
V_316 += V_303 -> V_71 [ V_78 ] . V_73 ;
}
}
F_139 ( & V_34 -> V_232 -> V_34 , V_302 , V_307 ,
V_304 ) ;
}
V_315:
F_183 ( V_34 , V_301 . V_148 & 1 , V_62 ) ;
F_41 ( V_34 , V_62 ) ;
if ( V_303 ) {
F_183 ( V_34 , V_301 . V_148 & 1 , V_303 ) ;
F_41 ( V_34 , V_303 ) ;
}
return V_44 ;
}
static int F_191 ( struct V_47 * V_34 ,
struct V_318 T_11 * V_319 )
{
struct V_318 V_53 ;
struct V_8 V_201 ;
int V_44 , V_73 ;
struct V_61 * V_306 ( V_62 ) ;
unsigned V_21 ;
if ( ! F_192 ( V_320 ) )
return - V_321 ;
if ( F_186 ( & V_53 , V_319 , sizeof( V_53 ) ) )
return - V_297 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_156 . V_148 = V_53 . V_148 ;
V_201 . V_156 . V_54 = V_53 . V_54 ;
V_201 . V_156 . V_150 = F_88 ( V_53 . V_150 ) ;
V_201 . V_156 . V_322 [ 0 ] = F_88 ( V_53 . V_322 ) ;
V_201 . V_156 . V_322 [ 1 ] = F_88 ( V_53 . V_323 ) ;
V_201 . V_156 . V_324 [ 0 ] = F_88 ( V_53 . V_324 ) ;
V_201 . V_156 . V_324 [ 1 ] = F_88 ( V_53 . V_325 ) ;
V_201 . V_156 . V_324 [ 2 ] = F_88 ( V_53 . V_326 ) ;
V_201 . V_156 . V_324 [ 3 ] = F_88 ( V_53 . V_327 ) ;
V_201 . V_156 . V_324 [ 4 ] = F_88 ( V_53 . V_328 ) ;
V_201 . V_156 . V_324 [ 5 ] = F_88 ( V_53 . V_329 ) ;
V_73 = V_53 . V_330 ;
if ( V_53 . V_330 ) {
V_62 = F_177 ( V_34 , V_53 . V_148 & 1 , V_53 . V_290 ,
V_73 ) ;
if ( F_187 ( V_62 ) )
return F_188 ( V_62 ) ;
V_73 = F_66 ( V_34 , V_62 , V_73 , V_255 ) ;
V_201 . V_156 . V_152 = F_72 ( F_68 ( V_62 -> V_71 ) ) ;
V_201 . V_156 . V_172 = F_72 ( V_62 -> V_75 ) ;
}
V_21 = V_53 . V_331 ? F_193 ( V_53 . V_331 ) :
V_199 ;
if ( V_73 != V_53 . V_330 )
V_44 = - V_118 ;
else
V_44 = F_110 ( V_34 , 0 , & V_201 , & V_53 . V_43 , V_21 ) ;
if ( V_53 . V_330 ) {
F_183 ( V_34 , V_53 . V_148 & 1 , V_62 ) ;
F_41 ( V_34 , V_62 ) ;
}
if ( ( V_44 >= 0 ) && F_194 ( & V_319 -> V_43 , & V_53 . V_43 ,
sizeof( V_53 . V_43 ) ) )
V_44 = - V_297 ;
return V_44 ;
}
static int F_195 ( struct V_332 * V_333 , T_12 V_334 , unsigned int V_53 ,
unsigned long V_335 )
{
struct V_138 * V_139 = V_333 -> V_89 -> V_158 ;
switch ( V_53 ) {
case V_336 :
F_196 () ;
return V_139 -> V_151 ;
case V_337 :
return F_191 ( V_139 -> V_34 , ( void T_11 * ) V_335 ) ;
case V_338 :
return F_185 ( V_139 , ( void T_11 * ) V_335 ) ;
case V_339 :
return F_197 ( ( void T_11 * ) V_335 ) ;
case V_340 :
return F_198 ( V_139 , ( void T_11 * ) V_335 ) ;
default:
return - V_341 ;
}
}
static int F_199 ( struct V_332 * V_333 , T_12 V_334 ,
unsigned int V_53 , unsigned long V_335 )
{
struct V_138 * V_139 = V_333 -> V_89 -> V_158 ;
switch ( V_53 ) {
case V_340 :
return F_200 ( V_139 , V_335 ) ;
}
return F_195 ( V_333 , V_334 , V_53 , V_335 ) ;
}
static int F_201 ( struct V_332 * V_333 , T_12 V_334 )
{
struct V_138 * V_139 = V_333 -> V_89 -> V_158 ;
struct V_47 * V_34 = V_139 -> V_34 ;
F_202 ( & V_34 -> V_342 ) ;
return 0 ;
}
static void F_203 ( struct V_86 * V_87 , T_12 V_334 )
{
struct V_138 * V_139 = V_87 -> V_158 ;
struct V_47 * V_34 = V_139 -> V_34 ;
F_204 ( & V_34 -> V_342 , V_343 ) ;
}
static int F_205 ( struct V_332 * V_344 , struct V_345 * V_346 )
{
V_346 -> V_347 = 1 << 6 ;
V_346 -> V_95 = 1 << 5 ;
V_346 -> V_348 = F_206 ( V_344 -> V_89 ) >> 11 ;
return 0 ;
}
static void F_207 ( struct V_14 * V_15 )
{
struct V_61 * V_62 , * V_349 ;
F_208 (iod, next, &nvmeq->iod_bio, node) {
if ( F_58 ( F_91 ( V_15 , V_62 ) ) )
break;
F_138 ( & V_62 -> V_104 ) ;
if ( F_102 ( & V_15 -> V_121 ) &&
F_136 ( & V_15 -> V_105 ) )
F_209 ( & V_15 -> V_28 ,
& V_15 -> V_103 ) ;
}
}
static void F_210 ( struct V_14 * V_15 )
{
while ( F_134 ( & V_15 -> V_121 ) ) {
struct V_85 * V_85 = F_135 ( & V_15 -> V_121 ) ;
struct V_138 * V_139 = V_85 -> V_88 -> V_89 -> V_158 ;
if ( F_102 ( & V_15 -> V_121 ) &&
F_136 ( & V_15 -> V_105 ) )
F_209 ( & V_15 -> V_28 ,
& V_15 -> V_103 ) ;
if ( F_96 ( V_15 , V_139 , V_85 ) ) {
if ( ! F_59 ( & V_15 -> V_28 ) )
F_60 ( & V_15 -> V_28 ,
& V_15 -> V_103 ) ;
F_211 ( & V_15 -> V_121 , V_85 ) ;
break;
}
}
}
static int F_212 ( void * V_188 )
{
struct V_47 * V_34 , * V_349 ;
while ( ! F_213 () ) {
F_111 ( V_350 ) ;
F_105 ( & V_351 ) ;
F_208 (dev, next, &dev_list, node) {
int V_78 ;
if ( F_151 ( & V_34 -> V_250 -> V_251 ) & V_352 &&
V_34 -> V_240 ) {
if ( F_126 ( & V_34 -> V_231 ) )
continue;
F_127 ( & V_34 -> V_104 ) ;
F_12 ( & V_34 -> V_232 -> V_34 ,
L_12 ) ;
V_34 -> V_233 = V_234 ;
F_128 ( V_235 , & V_34 -> V_231 ) ;
continue;
}
F_25 () ;
for ( V_78 = 0 ; V_78 < V_34 -> V_246 ; V_78 ++ ) {
struct V_14 * V_15 =
F_26 ( V_34 -> V_49 [ V_78 ] ) ;
if ( ! V_15 )
continue;
F_101 ( & V_15 -> V_56 ) ;
if ( V_15 -> V_57 )
goto V_353;
F_98 ( V_15 ) ;
F_129 ( V_15 , true ) ;
F_210 ( V_15 ) ;
F_207 ( V_15 ) ;
V_353:
F_103 ( & V_15 -> V_56 ) ;
}
F_27 () ;
}
F_106 ( & V_351 ) ;
F_112 ( F_214 ( V_271 ) ) ;
}
return 0 ;
}
static void F_215 ( struct V_138 * V_139 )
{
T_8 V_354 = F_216 ( V_139 -> V_90 ) ;
V_139 -> V_90 -> V_355 . V_356 = 0 ;
V_139 -> V_90 -> V_355 . V_357 = V_354 ;
V_139 -> V_90 -> V_355 . V_358 = V_354 ;
V_139 -> V_90 -> V_355 . V_359 = 0xffffffff ;
F_217 ( V_360 , V_139 -> V_90 ) ;
}
static struct V_138 * F_218 ( struct V_47 * V_34 , unsigned V_150 ,
struct V_10 * V_200 , struct V_11 * V_361 )
{
struct V_138 * V_139 ;
struct V_86 * V_87 ;
int V_362 ;
if ( V_361 -> V_154 & V_363 )
return NULL ;
V_139 = F_153 ( sizeof( * V_139 ) , V_255 ) ;
if ( ! V_139 )
return NULL ;
V_139 -> V_90 = F_219 ( V_255 ) ;
if ( ! V_139 -> V_90 )
goto V_364;
V_139 -> V_90 -> V_365 = V_366 ;
F_217 ( V_367 , V_139 -> V_90 ) ;
F_217 ( V_368 , V_139 -> V_90 ) ;
F_220 ( V_139 -> V_90 , F_100 ) ;
V_139 -> V_34 = V_34 ;
V_139 -> V_90 -> V_186 = V_139 ;
V_87 = F_221 ( 0 ) ;
if ( ! V_87 )
goto V_369;
V_139 -> V_151 = V_150 ;
V_139 -> V_87 = V_87 ;
V_362 = V_200 -> V_370 & 0xf ;
V_139 -> V_145 = V_200 -> V_362 [ V_362 ] . V_371 ;
V_139 -> V_309 = F_99 ( V_200 -> V_362 [ V_362 ] . V_309 ) ;
F_222 ( V_139 -> V_90 , 1 << V_139 -> V_145 ) ;
if ( V_34 -> V_372 )
F_223 ( V_139 -> V_90 , V_34 -> V_372 ) ;
if ( V_34 -> V_373 & V_374 )
F_224 ( V_139 -> V_90 , V_163 | V_164 ) ;
V_87 -> V_375 = V_376 ;
V_87 -> V_377 = 0 ;
V_87 -> V_378 = & V_379 ;
V_87 -> V_158 = V_139 ;
V_87 -> V_90 = V_139 -> V_90 ;
V_87 -> V_380 = & V_34 -> V_232 -> V_34 ;
V_87 -> V_54 = V_381 ;
sprintf ( V_87 -> V_382 , L_13 , V_34 -> V_260 , V_150 ) ;
F_225 ( V_87 , F_226 ( & V_200 -> V_383 ) << ( V_139 -> V_145 - 9 ) ) ;
if ( V_34 -> V_384 & V_385 )
F_215 ( V_139 ) ;
return V_139 ;
V_369:
F_227 ( V_139 -> V_90 ) ;
V_364:
F_44 ( V_139 ) ;
return NULL ;
}
static int F_228 ( int V_104 )
{
int V_386 , V_387 , V_388 = V_296 , V_389 = V_104 ;
F_229 (n) {
if ( V_386 == V_104 )
continue;
V_387 = F_230 ( V_104 , V_386 ) ;
if ( V_387 < V_388 ) {
V_388 = V_387 ;
V_389 = V_386 ;
}
}
return V_389 ;
}
static void F_231 ( T_13 * V_390 , struct V_14 * V_15 ,
int V_292 )
{
int V_92 ;
F_232 (cpu, qmask) {
if ( F_233 ( V_15 -> V_244 ) >= V_292 )
break;
if ( ! F_234 ( V_92 , V_15 -> V_244 ) )
* F_235 ( V_15 -> V_34 -> V_51 , V_92 ) = V_15 -> V_48 ;
}
}
static void F_236 ( T_13 * V_391 , const T_13 * V_392 ,
const T_13 * V_393 , struct V_14 * V_15 , int V_394 )
{
int V_395 ;
F_232 (next_cpu, new_mask) {
F_237 ( V_391 , V_391 , F_238 ( V_395 ) ) ;
F_237 ( V_391 , V_391 , F_239 ( V_395 ) ) ;
F_240 ( V_391 , V_391 , V_392 ) ;
F_231 ( V_391 , V_15 , V_394 ) ;
}
}
static void F_241 ( struct V_47 * V_34 )
{
unsigned V_78 , V_396 ;
V_396 = F_242 ( V_34 -> V_397 , F_243 () ) ;
for ( V_78 = V_34 -> V_246 ; V_78 <= V_396 ; V_78 ++ )
if ( ! F_152 ( V_34 , V_78 , V_34 -> V_17 , V_78 - 1 ) )
break;
V_396 = F_242 ( V_34 -> V_246 - 1 , F_243 () ) ;
for ( V_78 = V_34 -> V_249 ; V_78 <= V_396 ; V_78 ++ )
if ( F_165 ( F_21 ( V_34 , V_78 ) , V_78 ) )
break;
}
static void F_244 ( struct V_47 * V_34 )
{
unsigned V_92 , V_394 , V_49 , V_398 , V_78 ;
T_14 V_392 ;
F_241 ( V_34 ) ;
V_49 = F_242 ( V_34 -> V_249 - 1 , F_243 () ) ;
if ( ! V_49 )
return;
V_394 = F_243 () / V_49 ;
V_398 = V_49 - ( F_243 () - V_49 * V_394 ) ;
if ( ! F_245 ( & V_392 , V_255 ) )
return;
F_246 ( V_392 , V_399 ) ;
V_92 = F_247 ( V_392 ) ;
for ( V_78 = 1 ; V_78 <= V_49 ; V_78 ++ ) {
struct V_14 * V_15 = F_30 ( V_34 , V_78 ) ;
T_13 V_391 ;
F_248 ( V_15 -> V_244 ) ;
if ( ! F_233 ( V_392 ) ) {
F_31 ( V_15 ) ;
break;
}
V_391 = * F_238 ( V_92 ) ;
F_231 ( & V_391 , V_15 , V_394 ) ;
if ( F_249 ( V_391 ) < V_394 )
F_236 ( & V_391 , V_392 ,
F_239 ( V_92 ) ,
V_15 , V_394 ) ;
if ( F_249 ( V_391 ) < V_394 )
F_236 ( & V_391 , V_392 ,
F_250 ( V_92 ) ,
V_15 , V_394 ) ;
if ( F_249 ( V_391 ) < V_394 )
F_236 ( & V_391 , V_392 ,
F_251 ( F_252 ( V_92 ) ) ,
V_15 , V_394 ) ;
if ( F_249 ( V_391 ) < V_394 )
F_236 ( & V_391 , V_392 ,
F_251 (
F_228 (
F_252 ( V_92 ) ) ) ,
V_15 , V_394 ) ;
if ( F_249 ( V_391 ) < V_394 )
F_236 ( & V_391 , V_392 ,
V_392 ,
V_15 , V_394 ) ;
F_253 ( F_233 ( V_15 -> V_244 ) != V_394 ,
L_14 ,
V_34 -> V_260 , V_78 ) ;
F_147 ( V_34 -> V_248 [ V_15 -> V_212 ] . V_247 ,
V_15 -> V_244 ) ;
F_254 ( V_392 , V_392 ,
V_15 -> V_244 ) ;
V_92 = F_255 ( V_92 , V_392 ) ;
if ( V_398 && ! -- V_398 )
V_394 ++ ;
F_31 ( V_15 ) ;
}
F_253 ( F_233 ( V_392 ) , L_15 ,
V_34 -> V_260 ) ;
V_78 = 0 ;
F_254 ( V_392 , V_400 , V_399 ) ;
F_232 ( V_92 , V_392 )
* F_235 ( V_34 -> V_51 , V_92 ) = ( V_78 ++ % V_49 ) + 1 ;
F_142 ( V_392 ) ;
}
static int F_256 ( struct V_47 * V_34 , int V_292 )
{
int V_44 ;
T_8 V_43 ;
T_8 V_401 = ( V_292 - 1 ) | ( ( V_292 - 1 ) << 16 ) ;
V_44 = F_125 ( V_34 , V_402 , V_401 , 0 ,
& V_43 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_44 > 0 ) {
F_170 ( & V_34 -> V_232 -> V_34 , L_16 ,
V_44 ) ;
return - V_24 ;
}
return F_242 ( V_43 & 0xffff , V_43 >> 16 ) + 1 ;
}
static T_15 F_257 ( struct V_47 * V_34 , unsigned V_403 )
{
return 4096 + ( ( V_403 + 1 ) * 8 * V_34 -> V_182 ) ;
}
static void F_258 ( struct V_404 * V_46 )
{
struct V_47 * V_34 = F_133 ( V_46 , struct V_47 , V_405 ) ;
if ( V_34 -> V_240 )
F_244 ( V_34 ) ;
}
static int F_259 ( struct V_406 * V_407 ,
unsigned long V_408 , void * V_409 )
{
struct V_47 * V_34 ;
switch ( V_408 ) {
case V_410 :
case V_411 :
F_105 ( & V_351 ) ;
F_260 (dev, &dev_list, node)
F_261 ( & V_34 -> V_405 ) ;
F_106 ( & V_351 ) ;
break;
}
return V_412 ;
}
static int F_262 ( struct V_47 * V_34 )
{
struct V_14 * V_230 = F_21 ( V_34 , 0 ) ;
struct V_232 * V_413 = V_34 -> V_232 ;
int V_43 , V_78 , V_414 , V_403 , V_64 ;
V_403 = F_263 () ;
V_43 = F_256 ( V_34 , V_403 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_43 < V_403 )
V_403 = V_43 ;
V_64 = F_257 ( V_34 , V_403 ) ;
if ( V_64 > 8192 ) {
F_264 ( V_34 -> V_250 ) ;
do {
V_34 -> V_250 = F_265 ( F_266 ( V_413 , 0 ) , V_64 ) ;
if ( V_34 -> V_250 )
break;
if ( ! -- V_403 )
return - V_118 ;
V_64 = F_257 ( V_34 , V_403 ) ;
} while ( 1 );
V_34 -> V_261 = ( ( void V_415 * ) V_34 -> V_250 ) + 4096 ;
V_230 -> V_60 = V_34 -> V_261 ;
}
F_148 ( V_34 -> V_248 [ 0 ] . V_247 , V_230 ) ;
for ( V_78 = 0 ; V_78 < V_403 ; V_78 ++ )
V_34 -> V_248 [ V_78 ] . V_248 = V_78 ;
V_414 = F_267 ( V_413 , V_34 -> V_248 , 1 , V_403 ) ;
if ( V_414 < 0 ) {
V_414 = F_268 ( V_413 , 1 , F_242 ( V_403 , 32 ) ) ;
if ( V_414 < 0 ) {
V_414 = 1 ;
} else {
for ( V_78 = 0 ; V_78 < V_414 ; V_78 ++ )
V_34 -> V_248 [ V_78 ] . V_247 = V_78 + V_413 -> V_187 ;
}
}
V_403 = V_414 ;
V_34 -> V_397 = V_403 ;
V_43 = F_161 ( V_34 , V_230 , V_230 -> V_259 ) ;
if ( V_43 ) {
V_230 -> V_57 = 1 ;
goto V_416;
}
F_143 ( V_34 , V_403 + 1 ) ;
F_244 ( V_34 ) ;
return 0 ;
V_416:
F_143 ( V_34 , 1 ) ;
return V_43 ;
}
static int F_269 ( struct V_47 * V_34 )
{
struct V_232 * V_413 = V_34 -> V_232 ;
int V_417 ;
unsigned V_418 , V_78 ;
struct V_138 * V_139 ;
struct V_9 * V_419 ;
struct V_10 * V_420 ;
void * V_421 ;
T_6 V_113 ;
int V_422 = F_270 ( F_175 ( & V_34 -> V_250 -> V_267 ) ) + 12 ;
V_421 = F_154 ( & V_413 -> V_34 , 8192 , & V_113 , V_255 ) ;
if ( ! V_421 )
return - V_118 ;
V_417 = F_123 ( V_34 , 0 , 1 , V_113 ) ;
if ( V_417 ) {
F_170 ( & V_413 -> V_34 , L_17 , V_417 ) ;
V_417 = - V_106 ;
goto V_423;
}
V_419 = V_421 ;
V_418 = F_15 ( & V_419 -> V_418 ) ;
V_34 -> V_384 = F_13 ( & V_419 -> V_384 ) ;
V_34 -> V_35 = V_419 -> V_424 + 1 ;
V_34 -> V_373 = V_419 -> V_373 ;
memcpy ( V_34 -> V_425 , V_419 -> V_426 , sizeof( V_419 -> V_426 ) ) ;
memcpy ( V_34 -> V_427 , V_419 -> V_428 , sizeof( V_419 -> V_428 ) ) ;
memcpy ( V_34 -> V_429 , V_419 -> V_430 , sizeof( V_419 -> V_430 ) ) ;
if ( V_419 -> V_431 )
V_34 -> V_372 = 1 << ( V_419 -> V_431 + V_422 - 9 ) ;
if ( ( V_413 -> V_432 == V_433 ) &&
( V_413 -> V_252 == 0x0953 ) && V_419 -> V_434 [ 3 ] )
V_34 -> V_134 = 1 << ( V_419 -> V_434 [ 3 ] + V_422 ) ;
V_420 = V_421 ;
for ( V_78 = 1 ; V_78 <= V_418 ; V_78 ++ ) {
V_417 = F_123 ( V_34 , V_78 , 0 , V_113 ) ;
if ( V_417 )
continue;
if ( V_420 -> V_435 == 0 )
continue;
V_417 = F_124 ( V_34 , V_436 , V_78 ,
V_113 + 4096 , NULL ) ;
if ( V_417 )
memset ( V_421 + 4096 , 0 , 4096 ) ;
V_139 = F_218 ( V_34 , V_78 , V_421 , V_421 + 4096 ) ;
if ( V_139 )
F_61 ( & V_139 -> V_79 , & V_34 -> V_437 ) ;
}
F_260 (ns, &dev->namespaces, list)
F_271 ( V_139 -> V_87 ) ;
V_417 = 0 ;
V_423:
F_139 ( & V_34 -> V_232 -> V_34 , 8192 , V_421 , V_113 ) ;
return V_417 ;
}
static int F_272 ( struct V_47 * V_34 )
{
T_7 V_267 ;
int V_438 , V_43 = - V_118 ;
struct V_232 * V_413 = V_34 -> V_232 ;
if ( F_273 ( V_413 ) )
return V_43 ;
V_34 -> V_248 [ 0 ] . V_247 = V_413 -> V_187 ;
F_274 ( V_413 ) ;
V_438 = F_275 ( V_413 , V_439 ) ;
if ( F_276 ( V_413 , V_438 , L_18 ) )
goto V_440;
if ( F_277 ( & V_413 -> V_34 , F_278 ( 64 ) ) &&
F_277 ( & V_413 -> V_34 , F_278 ( 32 ) ) )
goto V_441;
V_34 -> V_250 = F_265 ( F_266 ( V_413 , 0 ) , 8192 ) ;
if ( ! V_34 -> V_250 )
goto V_441;
if ( F_151 ( & V_34 -> V_250 -> V_251 ) == - 1 ) {
V_43 = - V_195 ;
goto V_315;
}
V_267 = F_175 ( & V_34 -> V_250 -> V_267 ) ;
V_34 -> V_17 = F_181 ( int , F_279 ( V_267 ) + 1 , V_442 ) ;
V_34 -> V_182 = 1 << F_280 ( V_267 ) ;
V_34 -> V_261 = ( ( void V_415 * ) V_34 -> V_250 ) + 4096 ;
return 0 ;
V_315:
F_264 ( V_34 -> V_250 ) ;
V_34 -> V_250 = NULL ;
V_441:
F_281 ( V_413 ) ;
V_440:
F_282 ( V_413 ) ;
return V_43 ;
}
static void F_283 ( struct V_47 * V_34 )
{
if ( V_34 -> V_232 -> V_443 )
F_284 ( V_34 -> V_232 ) ;
else if ( V_34 -> V_232 -> V_444 )
F_285 ( V_34 -> V_232 ) ;
if ( V_34 -> V_250 ) {
F_264 ( V_34 -> V_250 ) ;
V_34 -> V_250 = NULL ;
F_281 ( V_34 -> V_232 ) ;
}
if ( F_286 ( V_34 -> V_232 ) )
F_282 ( V_34 -> V_232 ) ;
}
static void F_287 ( struct V_445 * V_446 , struct V_47 * V_34 )
{
V_446 -> V_447 = V_196 ;
F_288 () ;
for (; ; ) {
F_111 ( V_197 ) ;
if ( ! F_289 ( & V_446 -> V_448 ) )
break;
if ( ! F_112 ( V_199 ) ||
F_169 ( V_196 ) ) {
F_111 ( V_198 ) ;
F_171 ( V_34 , F_175 ( & V_34 -> V_250 -> V_267 ) ) ;
F_150 ( V_34 , 0 ) ;
F_290 ( V_449 , V_446 -> V_45 -> V_193 , 1 ) ;
F_291 ( V_446 -> V_45 ) ;
return;
}
}
F_111 ( V_198 ) ;
}
static void F_292 ( struct V_445 * V_446 )
{
F_293 ( & V_446 -> V_448 ) ;
if ( V_446 -> V_447 )
F_95 ( V_446 -> V_447 ) ;
}
static struct V_445 * F_294 ( struct V_445 * V_446 )
{
F_295 ( & V_446 -> V_448 ) ;
return V_446 ;
}
static void F_296 ( struct V_14 * V_15 )
{
struct V_445 * V_446 = V_15 -> V_42 . V_19 ;
F_149 ( V_15 ) ;
F_292 ( V_446 ) ;
}
static int F_297 ( struct V_14 * V_15 , T_10 V_148 ,
T_16 V_25 )
{
struct V_8 V_201 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_202 . V_148 = V_148 ;
V_201 . V_202 . V_48 = F_92 ( V_15 -> V_48 ) ;
F_298 ( & V_15 -> V_42 . V_46 , V_25 ) ;
return F_117 ( V_15 -> V_34 , & V_201 , & V_15 -> V_42 ) ;
}
static void F_299 ( struct V_450 * V_46 )
{
struct V_14 * V_15 = F_133 ( V_46 , struct V_14 ,
V_42 . V_46 ) ;
F_296 ( V_15 ) ;
}
static int F_300 ( struct V_14 * V_15 )
{
return F_297 ( V_15 , V_219 ,
F_299 ) ;
}
static void F_301 ( struct V_450 * V_46 )
{
struct V_14 * V_15 = F_133 ( V_46 , struct V_14 ,
V_42 . V_46 ) ;
int V_44 = V_15 -> V_42 . V_44 ;
if ( ! V_44 )
V_44 = F_300 ( V_15 ) ;
if ( V_44 )
F_296 ( V_15 ) ;
}
static int F_302 ( struct V_14 * V_15 )
{
return F_297 ( V_15 , V_220 ,
F_301 ) ;
}
static void F_303 ( struct V_450 * V_46 )
{
struct V_14 * V_15 = F_133 ( V_46 , struct V_14 ,
V_42 . V_46 ) ;
F_304 ( V_449 ) ;
if ( F_302 ( V_15 ) )
F_296 ( V_15 ) ;
}
static void F_305 ( struct V_47 * V_34 )
{
int V_78 ;
F_306 ( V_45 ) ;
struct V_445 V_446 ;
struct V_451 * V_452 = F_307 ( V_453 ,
& V_45 , L_19 , V_34 -> V_260 ) ;
if ( F_187 ( V_452 ) ) {
F_170 ( & V_34 -> V_232 -> V_34 ,
L_20 ) ;
for ( V_78 = V_34 -> V_246 - 1 ; V_78 > 0 ; V_78 -- )
F_150 ( V_34 , V_78 ) ;
return;
}
V_446 . V_447 = NULL ;
F_308 ( & V_446 . V_448 , 0 ) ;
V_446 . V_45 = & V_45 ;
for ( V_78 = V_34 -> V_246 - 1 ; V_78 > 0 ; V_78 -- ) {
struct V_14 * V_15 = F_21 ( V_34 , V_78 ) ;
if ( F_146 ( V_15 ) )
continue;
V_15 -> V_42 . V_19 = F_294 ( & V_446 ) ;
V_15 -> V_42 . V_45 = V_446 . V_45 ;
F_298 ( & V_15 -> V_42 . V_46 , F_303 ) ;
F_16 ( V_446 . V_45 , & V_15 -> V_42 . V_46 ) ;
}
F_287 ( & V_446 , V_34 ) ;
F_309 ( V_452 ) ;
}
static void F_310 ( struct V_47 * V_34 )
{
struct V_451 * V_454 = NULL ;
F_105 ( & V_351 ) ;
F_127 ( & V_34 -> V_104 ) ;
if ( F_136 ( & V_455 ) && ! F_311 ( V_174 ) ) {
V_454 = V_174 ;
V_174 = NULL ;
}
F_106 ( & V_351 ) ;
if ( V_454 )
F_309 ( V_454 ) ;
}
static void F_312 ( struct V_47 * V_34 )
{
int V_78 ;
V_34 -> V_240 = 0 ;
F_310 ( V_34 ) ;
if ( ! V_34 -> V_250 || ( V_34 -> V_250 && F_151 ( & V_34 -> V_250 -> V_251 ) == - 1 ) ) {
for ( V_78 = V_34 -> V_246 - 1 ; V_78 >= 0 ; V_78 -- ) {
struct V_14 * V_15 = F_21 ( V_34 , V_78 ) ;
F_146 ( V_15 ) ;
F_149 ( V_15 ) ;
}
} else {
F_305 ( V_34 ) ;
F_173 ( V_34 ) ;
F_150 ( V_34 , 0 ) ;
}
F_283 ( V_34 ) ;
}
static void F_313 ( struct V_47 * V_34 )
{
struct V_138 * V_139 ;
F_260 (ns, &dev->namespaces, list) {
if ( V_139 -> V_87 -> V_54 & V_456 )
F_314 ( V_139 -> V_87 ) ;
if ( ! F_315 ( V_139 -> V_90 ) )
F_227 ( V_139 -> V_90 ) ;
}
}
static int F_316 ( struct V_47 * V_34 )
{
struct V_252 * V_253 = & V_34 -> V_232 -> V_34 ;
V_34 -> V_84 = F_317 ( L_21 , V_253 ,
V_66 , V_66 , 0 ) ;
if ( ! V_34 -> V_84 )
return - V_118 ;
V_34 -> V_81 = F_317 ( L_22 , V_253 ,
256 , 256 , 0 ) ;
if ( ! V_34 -> V_81 ) {
F_318 ( V_34 -> V_84 ) ;
return - V_118 ;
}
return 0 ;
}
static void F_319 ( struct V_47 * V_34 )
{
F_318 ( V_34 -> V_84 ) ;
F_318 ( V_34 -> V_81 ) ;
}
static int F_320 ( struct V_47 * V_34 )
{
int V_260 , error ;
do {
if ( ! F_321 ( & V_457 , V_255 ) )
return - V_195 ;
F_105 ( & V_351 ) ;
error = F_322 ( & V_457 , & V_260 ) ;
F_106 ( & V_351 ) ;
} while ( error == - V_458 );
if ( error )
return - V_195 ;
V_34 -> V_260 = V_260 ;
return 0 ;
}
static void F_323 ( struct V_47 * V_34 )
{
F_105 ( & V_351 ) ;
F_324 ( & V_457 , V_34 -> V_260 ) ;
F_106 ( & V_351 ) ;
}
static void F_325 ( struct V_47 * V_34 )
{
struct V_138 * V_139 , * V_349 ;
F_208 (ns, next, &dev->namespaces, list) {
F_138 ( & V_139 -> V_79 ) ;
F_326 ( V_139 -> V_87 ) ;
F_44 ( V_139 ) ;
}
}
static void V_343 ( struct V_342 * V_342 )
{
struct V_47 * V_34 = F_133 ( V_342 , struct V_47 , V_342 ) ;
F_325 ( V_34 ) ;
F_327 ( V_34 -> V_51 ) ;
F_44 ( V_34 -> V_49 ) ;
F_44 ( V_34 -> V_248 ) ;
F_44 ( V_34 ) ;
}
static int F_328 ( struct V_459 * V_459 , struct V_460 * V_461 )
{
struct V_47 * V_34 = F_133 ( V_461 -> V_158 , struct V_47 ,
V_462 ) ;
F_202 ( & V_34 -> V_342 ) ;
V_461 -> V_158 = V_34 ;
return 0 ;
}
static int F_329 ( struct V_459 * V_459 , struct V_460 * V_461 )
{
struct V_47 * V_34 = V_461 -> V_158 ;
F_204 ( & V_34 -> V_342 , V_343 ) ;
return 0 ;
}
static long F_330 ( struct V_460 * V_461 , unsigned int V_53 , unsigned long V_335 )
{
struct V_47 * V_34 = V_461 -> V_158 ;
switch ( V_53 ) {
case V_337 :
return F_191 ( V_34 , ( void T_11 * ) V_335 ) ;
default:
return - V_341 ;
}
}
static int F_331 ( struct V_47 * V_34 )
{
int V_43 ;
bool V_463 = false ;
V_43 = F_272 ( V_34 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_174 ( V_34 ) ;
if ( V_43 )
goto V_315;
F_105 ( & V_351 ) ;
if ( F_136 ( & V_455 ) && F_311 ( V_174 ) ) {
V_463 = true ;
V_174 = NULL ;
}
F_332 ( & V_34 -> V_104 , & V_455 ) ;
F_106 ( & V_351 ) ;
if ( V_463 ) {
V_174 = F_307 ( F_212 , NULL , L_18 ) ;
F_19 ( & V_464 ) ;
} else
F_10 ( V_464 , V_174 ) ;
if ( F_311 ( V_174 ) ) {
V_43 = V_174 ? F_188 ( V_174 ) : - V_29 ;
goto V_441;
}
V_43 = F_262 ( V_34 ) ;
if ( V_43 && V_43 != - V_24 )
goto V_441;
return V_43 ;
V_441:
F_150 ( V_34 , 0 ) ;
F_310 ( V_34 ) ;
V_315:
F_283 ( V_34 ) ;
return V_43 ;
}
static int F_333 ( void * V_335 )
{
struct V_47 * V_34 = (struct V_47 * ) V_335 ;
struct V_232 * V_413 = V_34 -> V_232 ;
if ( F_334 ( V_413 ) )
F_335 ( V_413 ) ;
F_204 ( & V_34 -> V_342 , V_343 ) ;
return 0 ;
}
static void F_336 ( struct V_404 * V_465 )
{
struct V_47 * V_34 = F_133 ( V_465 , struct V_47 , V_231 ) ;
F_313 ( V_34 ) ;
F_143 ( V_34 , 1 ) ;
}
static int F_337 ( struct V_47 * V_34 )
{
int V_194 ;
V_194 = F_331 ( V_34 ) ;
if ( V_194 && V_194 != - V_24 )
return V_194 ;
if ( V_194 == - V_24 ) {
F_105 ( & V_351 ) ;
V_34 -> V_233 = F_336 ;
F_128 ( V_235 , & V_34 -> V_231 ) ;
F_106 ( & V_351 ) ;
}
V_34 -> V_240 = 1 ;
return 0 ;
}
static void F_338 ( struct V_47 * V_34 )
{
F_312 ( V_34 ) ;
if ( F_337 ( V_34 ) ) {
F_170 ( & V_34 -> V_232 -> V_34 , L_23 ) ;
F_202 ( & V_34 -> V_342 ) ;
if ( F_187 ( F_307 ( F_333 , V_34 , L_19 ,
V_34 -> V_260 ) ) ) {
F_170 ( & V_34 -> V_232 -> V_34 ,
L_24 ) ;
F_204 ( & V_34 -> V_342 , V_343 ) ;
}
}
}
static void V_234 ( struct V_404 * V_465 )
{
struct V_47 * V_34 = F_133 ( V_465 , struct V_47 , V_231 ) ;
F_338 ( V_34 ) ;
}
static void F_339 ( struct V_404 * V_46 )
{
struct V_47 * V_34 = F_133 ( V_46 , struct V_47 , V_231 ) ;
V_34 -> V_233 ( V_46 ) ;
}
static int F_340 ( struct V_232 * V_413 , const struct V_466 * V_200 )
{
int V_43 = - V_118 ;
struct V_47 * V_34 ;
V_34 = F_153 ( sizeof( * V_34 ) , V_255 ) ;
if ( ! V_34 )
return - V_118 ;
V_34 -> V_248 = F_179 ( F_263 () , sizeof( * V_34 -> V_248 ) ,
V_255 ) ;
if ( ! V_34 -> V_248 )
goto free;
V_34 -> V_49 = F_179 ( F_263 () + 1 , sizeof( void * ) ,
V_255 ) ;
if ( ! V_34 -> V_49 )
goto free;
V_34 -> V_51 = F_341 (unsigned short) ;
if ( ! V_34 -> V_51 )
goto free;
F_160 ( & V_34 -> V_437 ) ;
V_34 -> V_233 = V_234 ;
F_342 ( & V_34 -> V_231 , F_339 ) ;
F_342 ( & V_34 -> V_405 , F_258 ) ;
V_34 -> V_232 = V_413 ;
F_343 ( V_413 , V_34 ) ;
V_43 = F_320 ( V_34 ) ;
if ( V_43 )
goto free;
V_43 = F_316 ( V_34 ) ;
if ( V_43 )
goto V_467;
F_344 ( & V_34 -> V_342 ) ;
V_43 = F_331 ( V_34 ) ;
if ( V_43 ) {
if ( V_43 == - V_24 )
goto V_468;
goto V_469;
}
V_43 = F_269 ( V_34 ) ;
if ( V_43 )
goto V_470;
V_468:
F_345 ( V_34 -> V_262 , sizeof( V_34 -> V_262 ) , L_19 , V_34 -> V_260 ) ;
V_34 -> V_462 . V_471 = V_472 ;
V_34 -> V_462 . V_473 = & V_413 -> V_34 ;
V_34 -> V_462 . V_262 = V_34 -> V_262 ;
V_34 -> V_462 . V_378 = & V_474 ;
V_43 = F_346 ( & V_34 -> V_462 ) ;
if ( V_43 )
goto remove;
V_34 -> V_240 = 1 ;
return 0 ;
remove:
F_313 ( V_34 ) ;
F_325 ( V_34 ) ;
V_470:
F_312 ( V_34 ) ;
V_469:
F_143 ( V_34 , 0 ) ;
F_319 ( V_34 ) ;
V_467:
F_323 ( V_34 ) ;
free:
F_327 ( V_34 -> V_51 ) ;
F_44 ( V_34 -> V_49 ) ;
F_44 ( V_34 -> V_248 ) ;
F_44 ( V_34 ) ;
return V_43 ;
}
static void F_347 ( struct V_232 * V_413 , bool V_475 )
{
struct V_47 * V_34 = F_334 ( V_413 ) ;
if ( V_475 )
F_312 ( V_34 ) ;
else
F_337 ( V_34 ) ;
}
static void F_348 ( struct V_232 * V_413 )
{
struct V_47 * V_34 = F_334 ( V_413 ) ;
F_312 ( V_34 ) ;
}
static void F_349 ( struct V_232 * V_413 )
{
struct V_47 * V_34 = F_334 ( V_413 ) ;
F_105 ( & V_351 ) ;
F_127 ( & V_34 -> V_104 ) ;
F_106 ( & V_351 ) ;
F_343 ( V_413 , NULL ) ;
F_350 ( & V_34 -> V_231 ) ;
F_350 ( & V_34 -> V_405 ) ;
F_351 ( & V_34 -> V_462 ) ;
F_313 ( V_34 ) ;
F_312 ( V_34 ) ;
F_143 ( V_34 , 0 ) ;
F_352 () ;
F_323 ( V_34 ) ;
F_319 ( V_34 ) ;
F_204 ( & V_34 -> V_342 , V_343 ) ;
}
static int F_353 ( struct V_252 * V_34 )
{
struct V_232 * V_413 = F_354 ( V_34 ) ;
struct V_47 * V_476 = F_334 ( V_413 ) ;
F_312 ( V_476 ) ;
return 0 ;
}
static int F_355 ( struct V_252 * V_34 )
{
struct V_232 * V_413 = F_354 ( V_34 ) ;
struct V_47 * V_476 = F_334 ( V_413 ) ;
if ( F_337 ( V_476 ) && ! F_126 ( & V_476 -> V_231 ) ) {
V_476 -> V_233 = V_234 ;
F_128 ( V_235 , & V_476 -> V_231 ) ;
}
return 0 ;
}
static int T_17 F_356 ( void )
{
int V_43 ;
F_157 ( & V_464 ) ;
V_235 = F_357 ( L_18 ) ;
if ( ! V_235 )
return - V_118 ;
V_43 = F_358 ( V_376 , L_18 ) ;
if ( V_43 < 0 )
goto V_477;
else if ( V_43 > 0 )
V_376 = V_43 ;
V_478 . V_479 = & F_259 ;
V_43 = F_359 ( & V_478 ) ;
if ( V_43 )
goto V_480;
V_43 = F_360 ( & V_481 ) ;
if ( V_43 )
goto V_482;
return 0 ;
V_482:
F_361 ( & V_478 ) ;
V_480:
V_480 ( V_376 , L_18 ) ;
V_477:
F_362 ( V_235 ) ;
return V_43 ;
}
static void T_18 F_363 ( void )
{
F_364 ( & V_481 ) ;
F_361 ( & V_478 ) ;
V_480 ( V_376 , L_18 ) ;
F_362 ( V_235 ) ;
F_73 ( V_174 && ! F_187 ( V_174 ) ) ;
F_1 () ;
}
