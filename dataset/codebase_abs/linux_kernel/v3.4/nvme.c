static inline void F_1 ( void )
{
F_2 ( sizeof( struct V_1 ) != 64 ) ;
F_2 ( sizeof( struct V_2 ) != 64 ) ;
F_2 ( sizeof( struct V_3 ) != 64 ) ;
F_2 ( sizeof( struct V_4 ) != 64 ) ;
F_2 ( sizeof( struct V_5 ) != 64 ) ;
F_2 ( sizeof( struct V_6 ) != 64 ) ;
F_2 ( sizeof( struct V_7 ) != 4096 ) ;
F_2 ( sizeof( struct V_8 ) != 4096 ) ;
F_2 ( sizeof( struct V_9 ) != 64 ) ;
}
static struct V_10 * V_10 ( struct V_11 * V_12 )
{
return ( void * ) & V_12 -> V_13 [ F_3 ( V_12 -> V_14 ) ] ;
}
static int F_4 ( struct V_11 * V_12 , void * V_15 ,
T_1 V_16 , unsigned V_17 )
{
int V_18 = V_12 -> V_14 - 1 ;
struct V_10 * V_19 = V_10 ( V_12 ) ;
int V_20 ;
do {
V_20 = F_5 ( V_12 -> V_13 , V_18 ) ;
if ( V_20 >= V_18 )
return - V_21 ;
} while ( F_6 ( V_20 , V_12 -> V_13 ) );
V_19 [ V_20 ] . V_22 = V_16 ;
V_19 [ V_20 ] . V_15 = V_15 ;
V_19 [ V_20 ] . V_17 = V_23 + V_17 ;
return V_20 ;
}
static int F_7 ( struct V_11 * V_12 , void * V_15 ,
T_1 V_16 , unsigned V_17 )
{
int V_20 ;
F_8 ( V_12 -> V_24 ,
( V_20 = F_4 ( V_12 , V_15 , V_16 , V_17 ) ) >= 0 ) ;
return ( V_20 < 0 ) ? - V_25 : V_20 ;
}
static void F_9 ( struct V_26 * V_27 , void * V_15 ,
struct V_28 * V_29 )
{
if ( V_15 == V_30 )
return;
if ( V_15 == V_31 )
return;
if ( V_15 == V_32 ) {
F_10 ( & V_27 -> V_33 -> V_27 ,
L_1 ,
V_29 -> V_34 , F_11 ( & V_29 -> V_35 ) ) ;
return;
}
if ( V_15 == V_36 ) {
F_10 ( & V_27 -> V_33 -> V_27 ,
L_2 ,
V_29 -> V_34 , F_11 ( & V_29 -> V_35 ) ) ;
return;
}
F_10 ( & V_27 -> V_33 -> V_27 , L_3 , V_15 ) ;
}
static void * F_12 ( struct V_11 * V_12 , int V_20 ,
T_1 * V_22 )
{
void * V_15 ;
struct V_10 * V_19 = V_10 ( V_12 ) ;
if ( V_20 >= V_12 -> V_14 ) {
* V_22 = F_9 ;
return V_36 ;
}
* V_22 = V_19 [ V_20 ] . V_22 ;
V_15 = V_19 [ V_20 ] . V_15 ;
V_19 [ V_20 ] . V_22 = F_9 ;
V_19 [ V_20 ] . V_15 = V_32 ;
F_13 ( V_20 , V_12 -> V_13 ) ;
F_14 ( & V_12 -> V_24 ) ;
return V_15 ;
}
static void * F_15 ( struct V_11 * V_12 , int V_20 ,
T_1 * V_22 )
{
void * V_15 ;
struct V_10 * V_19 = V_10 ( V_12 ) ;
if ( V_22 )
* V_22 = V_19 [ V_20 ] . V_22 ;
V_15 = V_19 [ V_20 ] . V_15 ;
V_19 [ V_20 ] . V_22 = F_9 ;
V_19 [ V_20 ] . V_15 = V_30 ;
return V_15 ;
}
static struct V_11 * F_16 ( struct V_26 * V_27 )
{
return V_27 -> V_37 [ F_17 () + 1 ] ;
}
static void F_18 ( struct V_11 * V_12 )
{
F_19 () ;
}
static int F_20 ( struct V_11 * V_12 , struct V_6 * V_38 )
{
unsigned long V_39 ;
T_2 V_40 ;
F_21 ( & V_12 -> V_41 , V_39 ) ;
V_40 = V_12 -> V_42 ;
memcpy ( & V_12 -> V_43 [ V_40 ] , V_38 , sizeof( * V_38 ) ) ;
if ( ++ V_40 == V_12 -> V_14 )
V_40 = 0 ;
F_22 ( V_40 , V_12 -> V_44 ) ;
V_12 -> V_42 = V_40 ;
F_23 ( & V_12 -> V_41 , V_39 ) ;
return 0 ;
}
static T_3 * * F_24 ( struct V_45 * V_46 )
{
return ( ( void * ) V_46 ) + V_46 -> V_47 ;
}
static int F_25 ( unsigned V_48 )
{
unsigned V_49 = F_26 ( V_48 + V_50 , V_50 ) ;
return F_26 ( 8 * V_49 , V_50 - 8 ) ;
}
static struct V_45 *
F_27 ( unsigned V_51 , unsigned V_52 , T_4 V_53 )
{
struct V_45 * V_46 = F_28 ( sizeof( struct V_45 ) +
sizeof( T_3 * ) * F_25 ( V_52 ) +
sizeof( struct V_54 ) * V_51 , V_53 ) ;
if ( V_46 ) {
V_46 -> V_47 = F_29 ( struct V_45 , V_55 [ V_51 ] ) ;
V_46 -> V_56 = - 1 ;
V_46 -> V_57 = V_52 ;
}
return V_46 ;
}
static void F_30 ( struct V_26 * V_27 , struct V_45 * V_46 )
{
const int V_58 = V_50 / 8 - 1 ;
int V_59 ;
T_3 * * V_60 = F_24 ( V_46 ) ;
T_5 V_61 = V_46 -> V_62 ;
if ( V_46 -> V_56 == 0 )
F_31 ( V_27 -> V_63 , V_60 [ 0 ] , V_61 ) ;
for ( V_59 = 0 ; V_59 < V_46 -> V_56 ; V_59 ++ ) {
T_3 * V_64 = V_60 [ V_59 ] ;
T_5 V_65 = F_32 ( V_64 [ V_58 ] ) ;
F_31 ( V_27 -> V_66 , V_64 , V_61 ) ;
V_61 = V_65 ;
}
F_33 ( V_46 ) ;
}
static void F_34 ( struct V_26 * V_27 , struct V_67 * V_67 )
{
struct V_11 * V_12 = F_16 ( V_27 ) ;
if ( F_35 ( & V_12 -> V_68 ) )
F_36 ( & V_12 -> V_24 , & V_12 -> V_69 ) ;
F_37 ( & V_12 -> V_68 , V_67 ) ;
F_18 ( V_12 ) ;
F_38 ( V_70 ) ;
}
static void F_39 ( struct V_26 * V_27 , void * V_15 ,
struct V_28 * V_29 )
{
struct V_45 * V_46 = V_15 ;
struct V_67 * V_67 = V_46 -> V_71 ;
T_2 V_72 = F_11 ( & V_29 -> V_72 ) >> 1 ;
F_40 ( & V_27 -> V_33 -> V_27 , V_46 -> V_55 , V_46 -> V_73 ,
F_41 ( V_67 ) ? V_74 : V_75 ) ;
F_30 ( V_27 , V_46 ) ;
if ( V_72 ) {
F_42 ( V_67 , - V_76 ) ;
} else if ( V_67 -> V_77 > V_67 -> V_78 ) {
F_34 ( V_27 , V_67 ) ;
} else {
F_42 ( V_67 , 0 ) ;
}
}
static int F_43 ( struct V_26 * V_27 ,
struct V_79 * V_38 , struct V_45 * V_46 ,
int V_80 , T_4 V_53 )
{
struct V_81 * V_82 ;
int V_57 = V_80 ;
struct V_54 * V_55 = V_46 -> V_55 ;
int V_83 = F_44 ( V_55 ) ;
T_6 V_84 = F_45 ( V_55 ) ;
int V_47 = F_46 ( V_84 ) ;
T_3 * V_64 ;
T_3 * * V_60 = F_24 ( V_46 ) ;
T_5 V_61 ;
int V_49 , V_59 ;
V_38 -> V_85 = F_47 ( V_84 ) ;
V_57 -= ( V_50 - V_47 ) ;
if ( V_57 <= 0 )
return V_80 ;
V_83 -= ( V_50 - V_47 ) ;
if ( V_83 ) {
V_84 += ( V_50 - V_47 ) ;
} else {
V_55 = F_48 ( V_55 ) ;
V_84 = F_45 ( V_55 ) ;
V_83 = F_44 ( V_55 ) ;
}
if ( V_57 <= V_50 ) {
V_38 -> V_86 = F_47 ( V_84 ) ;
return V_80 ;
}
V_49 = F_26 ( V_57 , V_50 ) ;
if ( V_49 <= ( 256 / 8 ) ) {
V_82 = V_27 -> V_63 ;
V_46 -> V_56 = 0 ;
} else {
V_82 = V_27 -> V_66 ;
V_46 -> V_56 = 1 ;
}
V_64 = F_49 ( V_82 , V_53 , & V_61 ) ;
if ( ! V_64 ) {
V_38 -> V_86 = F_47 ( V_84 ) ;
V_46 -> V_56 = - 1 ;
return ( V_80 - V_57 ) + V_50 ;
}
V_60 [ 0 ] = V_64 ;
V_46 -> V_62 = V_61 ;
V_38 -> V_86 = F_47 ( V_61 ) ;
V_59 = 0 ;
for (; ; ) {
if ( V_59 == V_50 / 8 ) {
T_3 * V_87 = V_64 ;
V_64 = F_49 ( V_82 , V_53 , & V_61 ) ;
if ( ! V_64 )
return V_80 - V_57 ;
V_60 [ V_46 -> V_56 ++ ] = V_64 ;
V_64 [ 0 ] = V_87 [ V_59 - 1 ] ;
V_87 [ V_59 - 1 ] = F_47 ( V_61 ) ;
V_59 = 1 ;
}
V_64 [ V_59 ++ ] = F_47 ( V_84 ) ;
V_83 -= V_50 ;
V_84 += V_50 ;
V_57 -= V_50 ;
if ( V_57 <= 0 )
break;
if ( V_83 > 0 )
continue;
F_50 ( V_83 < 0 ) ;
V_55 = F_48 ( V_55 ) ;
V_84 = F_45 ( V_55 ) ;
V_83 = F_44 ( V_55 ) ;
}
return V_80 ;
}
static int F_51 ( struct V_88 * V_27 , struct V_45 * V_46 ,
struct V_67 * V_67 , enum V_89 V_90 , int V_91 )
{
struct V_92 * V_93 , * V_94 = NULL ;
struct V_54 * V_55 = NULL ;
int V_59 , V_95 , V_57 = 0 , V_96 = 0 ;
F_52 ( V_46 -> V_55 , V_91 ) ;
V_95 = V_67 -> V_78 ;
F_53 (bvec, bio, i) {
if ( V_94 && F_54 ( V_94 , V_93 ) ) {
V_55 -> V_57 += V_93 -> V_97 ;
} else {
if ( V_94 && F_55 ( V_94 , V_93 ) )
break;
V_55 = V_55 ? V_55 + 1 : V_46 -> V_55 ;
F_56 ( V_55 , V_93 -> V_98 , V_93 -> V_97 ,
V_93 -> V_99 ) ;
V_96 ++ ;
}
V_57 += V_93 -> V_97 ;
V_94 = V_93 ;
}
V_67 -> V_78 = V_59 ;
V_46 -> V_73 = V_96 ;
F_57 ( V_55 ) ;
if ( F_58 ( V_27 , V_46 -> V_55 , V_46 -> V_73 , V_90 ) == 0 ) {
V_67 -> V_78 = V_95 ;
return - V_100 ;
}
return V_57 ;
}
static int F_59 ( struct V_11 * V_12 , struct V_101 * V_102 ,
int V_20 )
{
struct V_6 * V_103 = & V_12 -> V_43 [ V_12 -> V_42 ] ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
V_103 -> V_104 . V_105 = V_106 ;
V_103 -> V_104 . V_34 = V_20 ;
V_103 -> V_104 . V_107 = F_60 ( V_102 -> V_108 ) ;
if ( ++ V_12 -> V_42 == V_12 -> V_14 )
V_12 -> V_42 = 0 ;
F_22 ( V_12 -> V_42 , V_12 -> V_44 ) ;
return 0 ;
}
static int F_61 ( struct V_11 * V_12 , struct V_101 * V_102 )
{
int V_20 = F_4 ( V_12 , ( void * ) V_31 ,
F_9 , V_109 ) ;
if ( F_62 ( V_20 < 0 ) )
return V_20 ;
return F_59 ( V_12 , V_102 , V_20 ) ;
}
static int F_63 ( struct V_11 * V_12 , struct V_101 * V_102 ,
struct V_67 * V_67 )
{
struct V_6 * V_103 ;
struct V_45 * V_46 ;
enum V_89 V_90 ;
int V_20 , V_57 , V_110 = - V_100 ;
T_2 V_111 ;
T_7 V_112 ;
int V_91 = F_64 ( V_102 -> V_113 , V_67 ) ;
if ( ( V_67 -> V_114 & V_115 ) && V_91 ) {
V_110 = F_61 ( V_12 , V_102 ) ;
if ( V_110 )
return V_110 ;
}
V_46 = F_27 ( V_91 , V_67 -> V_116 , V_117 ) ;
if ( ! V_46 )
goto V_118;
V_46 -> V_71 = V_67 ;
V_110 = - V_21 ;
V_20 = F_4 ( V_12 , V_46 , F_39 , V_109 ) ;
if ( F_62 ( V_20 < 0 ) )
goto V_119;
if ( ( V_67 -> V_114 & V_115 ) && ! V_91 )
return F_59 ( V_12 , V_102 , V_20 ) ;
V_111 = 0 ;
if ( V_67 -> V_114 & V_120 )
V_111 |= V_121 ;
if ( V_67 -> V_114 & ( V_122 | V_123 ) )
V_111 |= V_124 ;
V_112 = 0 ;
if ( V_67 -> V_114 & V_123 )
V_112 |= V_125 ;
V_103 = & V_12 -> V_43 [ V_12 -> V_42 ] ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
if ( F_41 ( V_67 ) ) {
V_103 -> V_126 . V_105 = V_127 ;
V_90 = V_74 ;
} else {
V_103 -> V_126 . V_105 = V_128 ;
V_90 = V_75 ;
}
V_110 = F_51 ( V_12 -> V_129 , V_46 , V_67 , V_90 , V_91 ) ;
if ( V_110 < 0 )
goto V_119;
V_57 = V_110 ;
V_103 -> V_126 . V_34 = V_20 ;
V_103 -> V_126 . V_107 = F_60 ( V_102 -> V_108 ) ;
V_57 = F_43 ( V_12 -> V_27 , & V_103 -> V_104 , V_46 , V_57 ,
V_117 ) ;
V_103 -> V_126 . V_130 = F_47 ( V_67 -> V_131 >> ( V_102 -> V_132 - 9 ) ) ;
V_103 -> V_126 . V_57 = F_65 ( ( V_57 >> V_102 -> V_132 ) - 1 ) ;
V_103 -> V_126 . V_111 = F_65 ( V_111 ) ;
V_103 -> V_126 . V_112 = F_60 ( V_112 ) ;
V_67 -> V_131 += V_57 >> 9 ;
if ( ++ V_12 -> V_42 == V_12 -> V_14 )
V_12 -> V_42 = 0 ;
F_22 ( V_12 -> V_42 , V_12 -> V_44 ) ;
return 0 ;
V_119:
F_30 ( V_12 -> V_27 , V_46 ) ;
V_118:
return V_110 ;
}
static void F_66 ( struct V_133 * V_134 , struct V_67 * V_67 )
{
struct V_101 * V_102 = V_134 -> V_135 ;
struct V_11 * V_12 = F_16 ( V_102 -> V_27 ) ;
int V_110 = - V_21 ;
F_67 ( & V_12 -> V_41 ) ;
if ( F_35 ( & V_12 -> V_68 ) )
V_110 = F_63 ( V_12 , V_102 , V_67 ) ;
if ( F_62 ( V_110 ) ) {
if ( F_35 ( & V_12 -> V_68 ) )
F_36 ( & V_12 -> V_24 , & V_12 -> V_69 ) ;
F_37 ( & V_12 -> V_68 , V_67 ) ;
}
F_68 ( & V_12 -> V_41 ) ;
F_18 ( V_12 ) ;
}
static T_8 F_69 ( struct V_11 * V_12 )
{
T_2 V_136 , V_137 ;
V_136 = V_12 -> V_138 ;
V_137 = V_12 -> V_139 ;
for (; ; ) {
void * V_15 ;
T_1 V_22 ;
struct V_28 V_29 = V_12 -> V_140 [ V_136 ] ;
if ( ( F_70 ( V_29 . V_72 ) & 1 ) != V_137 )
break;
V_12 -> V_141 = F_70 ( V_29 . V_141 ) ;
if ( ++ V_136 == V_12 -> V_14 ) {
V_136 = 0 ;
V_137 = ! V_137 ;
}
V_15 = F_12 ( V_12 , V_29 . V_34 , & V_22 ) ;
V_22 ( V_12 -> V_27 , V_15 , & V_29 ) ;
}
if ( V_136 == V_12 -> V_138 && V_137 == V_12 -> V_139 )
return V_142 ;
F_22 ( V_136 , V_12 -> V_44 + ( 1 << V_12 -> V_27 -> V_143 ) ) ;
V_12 -> V_138 = V_136 ;
V_12 -> V_139 = V_137 ;
return V_144 ;
}
static T_8 F_71 ( int V_145 , void * V_146 )
{
T_8 V_110 ;
struct V_11 * V_12 = V_146 ;
F_72 ( & V_12 -> V_41 ) ;
V_110 = F_69 ( V_12 ) ;
F_73 ( & V_12 -> V_41 ) ;
return V_110 ;
}
static T_8 F_74 ( int V_145 , void * V_146 )
{
struct V_11 * V_12 = V_146 ;
struct V_28 V_29 = V_12 -> V_140 [ V_12 -> V_138 ] ;
if ( ( F_70 ( V_29 . V_72 ) & 1 ) != V_12 -> V_139 )
return V_142 ;
return V_147 ;
}
static void F_75 ( struct V_11 * V_12 , int V_20 )
{
F_67 ( & V_12 -> V_41 ) ;
F_15 ( V_12 , V_20 , NULL ) ;
F_68 ( & V_12 -> V_41 ) ;
}
static void F_76 ( struct V_26 * V_27 , void * V_15 ,
struct V_28 * V_29 )
{
struct V_148 * V_149 = V_15 ;
V_149 -> V_110 = F_77 ( & V_29 -> V_110 ) ;
V_149 -> V_72 = F_11 ( & V_29 -> V_72 ) >> 1 ;
F_38 ( V_149 -> V_150 ) ;
}
static int F_78 ( struct V_11 * V_12 ,
struct V_6 * V_38 , T_7 * V_110 , unsigned V_17 )
{
int V_20 ;
struct V_148 V_149 ;
V_149 . V_150 = V_151 ;
V_149 . V_72 = - V_25 ;
V_20 = F_7 ( V_12 , & V_149 , F_76 ,
V_17 ) ;
if ( V_20 < 0 )
return V_20 ;
V_38 -> V_104 . V_34 = V_20 ;
F_79 ( V_152 ) ;
F_20 ( V_12 , V_38 ) ;
F_80 () ;
if ( V_149 . V_72 == - V_25 ) {
F_75 ( V_12 , V_20 ) ;
return - V_25 ;
}
if ( V_110 )
* V_110 = V_149 . V_110 ;
return V_149 . V_72 ;
}
static int F_81 ( struct V_26 * V_27 , struct V_6 * V_38 ,
T_7 * V_110 )
{
return F_78 ( V_27 -> V_37 [ 0 ] , V_38 , V_110 , V_153 ) ;
}
static int F_82 ( struct V_26 * V_27 , T_9 V_105 , T_2 V_154 )
{
int V_72 ;
struct V_6 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_156 . V_105 = V_105 ;
V_155 . V_156 . V_157 = F_65 ( V_154 ) ;
V_72 = F_81 ( V_27 , & V_155 , NULL ) ;
if ( V_72 )
return - V_76 ;
return 0 ;
}
static int F_83 ( struct V_26 * V_27 , T_2 V_157 ,
struct V_11 * V_12 )
{
int V_72 ;
struct V_6 V_155 ;
int V_39 = V_158 | V_159 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_160 . V_105 = V_161 ;
V_155 . V_160 . V_85 = F_47 ( V_12 -> V_162 ) ;
V_155 . V_160 . V_163 = F_65 ( V_157 ) ;
V_155 . V_160 . V_164 = F_65 ( V_12 -> V_14 - 1 ) ;
V_155 . V_160 . V_165 = F_65 ( V_39 ) ;
V_155 . V_160 . V_166 = F_65 ( V_12 -> V_167 ) ;
V_72 = F_81 ( V_27 , & V_155 , NULL ) ;
if ( V_72 )
return - V_76 ;
return 0 ;
}
static int F_84 ( struct V_26 * V_27 , T_2 V_157 ,
struct V_11 * V_12 )
{
int V_72 ;
struct V_6 V_155 ;
int V_39 = V_158 | V_168 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_169 . V_105 = V_170 ;
V_155 . V_169 . V_85 = F_47 ( V_12 -> V_171 ) ;
V_155 . V_169 . V_172 = F_65 ( V_157 ) ;
V_155 . V_169 . V_164 = F_65 ( V_12 -> V_14 - 1 ) ;
V_155 . V_169 . V_173 = F_65 ( V_39 ) ;
V_155 . V_169 . V_163 = F_65 ( V_157 ) ;
V_72 = F_81 ( V_27 , & V_155 , NULL ) ;
if ( V_72 )
return - V_76 ;
return 0 ;
}
static int F_85 ( struct V_26 * V_27 , T_2 V_163 )
{
return F_82 ( V_27 , V_174 , V_163 ) ;
}
static int F_86 ( struct V_26 * V_27 , T_2 V_172 )
{
return F_82 ( V_27 , V_175 , V_172 ) ;
}
static int F_87 ( struct V_26 * V_27 , unsigned V_107 , unsigned V_176 ,
T_5 V_84 )
{
struct V_6 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_177 . V_105 = V_178 ;
V_155 . V_177 . V_107 = F_60 ( V_107 ) ;
V_155 . V_177 . V_85 = F_47 ( V_84 ) ;
V_155 . V_177 . V_176 = F_60 ( V_176 ) ;
return F_81 ( V_27 , & V_155 , NULL ) ;
}
static int F_88 ( struct V_26 * V_27 , unsigned V_179 ,
unsigned V_180 , T_5 V_84 )
{
struct V_6 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_181 . V_105 = V_182 ;
V_155 . V_181 . V_85 = F_47 ( V_84 ) ;
V_155 . V_181 . V_179 = F_60 ( V_179 ) ;
V_155 . V_181 . V_180 = F_60 ( V_180 ) ;
return F_81 ( V_27 , & V_155 , NULL ) ;
}
static int F_89 ( struct V_26 * V_27 , unsigned V_179 ,
unsigned V_180 , T_5 V_84 , T_7 * V_110 )
{
struct V_6 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_181 . V_105 = V_183 ;
V_155 . V_181 . V_85 = F_47 ( V_84 ) ;
V_155 . V_181 . V_179 = F_60 ( V_179 ) ;
V_155 . V_181 . V_180 = F_60 ( V_180 ) ;
return F_81 ( V_27 , & V_155 , V_110 ) ;
}
static void F_90 ( struct V_26 * V_27 , int V_157 )
{
struct V_11 * V_12 = V_27 -> V_37 [ V_157 ] ;
int V_184 = V_27 -> V_185 [ V_12 -> V_167 ] . V_184 ;
F_91 ( V_184 , NULL ) ;
F_92 ( V_184 , V_12 ) ;
if ( V_157 ) {
F_86 ( V_27 , V_157 ) ;
F_85 ( V_27 , V_157 ) ;
}
F_93 ( V_12 -> V_129 , F_94 ( V_12 -> V_14 ) ,
( void * ) V_12 -> V_140 , V_12 -> V_162 ) ;
F_93 ( V_12 -> V_129 , F_95 ( V_12 -> V_14 ) ,
V_12 -> V_43 , V_12 -> V_171 ) ;
F_33 ( V_12 ) ;
}
static struct V_11 * F_96 ( struct V_26 * V_27 , int V_157 ,
int V_18 , int V_184 )
{
struct V_88 * V_186 = & V_27 -> V_33 -> V_27 ;
unsigned V_187 = ( V_18 / 8 ) + ( V_18 * sizeof( struct V_10 ) ) ;
struct V_11 * V_12 = F_97 ( sizeof( * V_12 ) + V_187 , V_188 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_140 = F_98 ( V_186 , F_94 ( V_18 ) ,
& V_12 -> V_162 , V_188 ) ;
if ( ! V_12 -> V_140 )
goto V_189;
memset ( ( void * ) V_12 -> V_140 , 0 , F_94 ( V_18 ) ) ;
V_12 -> V_43 = F_98 ( V_186 , F_95 ( V_18 ) ,
& V_12 -> V_171 , V_188 ) ;
if ( ! V_12 -> V_43 )
goto V_190;
V_12 -> V_129 = V_186 ;
V_12 -> V_27 = V_27 ;
F_99 ( & V_12 -> V_41 ) ;
V_12 -> V_138 = 0 ;
V_12 -> V_139 = 1 ;
F_100 ( & V_12 -> V_24 ) ;
F_101 ( & V_12 -> V_69 , V_70 ) ;
F_102 ( & V_12 -> V_68 ) ;
V_12 -> V_44 = & V_27 -> V_191 [ V_157 << ( V_27 -> V_143 + 1 ) ] ;
V_12 -> V_14 = V_18 ;
V_12 -> V_167 = V_184 ;
return V_12 ;
V_190:
F_93 ( V_186 , F_94 ( V_12 -> V_14 ) , ( void * ) V_12 -> V_140 ,
V_12 -> V_162 ) ;
V_189:
F_33 ( V_12 ) ;
return NULL ;
}
static int F_103 ( struct V_26 * V_27 , struct V_11 * V_12 ,
const char * V_192 )
{
if ( V_193 )
return F_104 ( V_27 -> V_185 [ V_12 -> V_167 ] . V_184 ,
F_74 , F_71 ,
V_194 | V_195 ,
V_192 , V_12 ) ;
return F_105 ( V_27 -> V_185 [ V_12 -> V_167 ] . V_184 , F_71 ,
V_194 | V_195 , V_192 , V_12 ) ;
}
int T_10 F_106 ( struct V_26 * V_27 )
{
int V_110 ;
T_7 V_196 ;
T_6 V_197 ;
unsigned long V_17 ;
struct V_11 * V_12 ;
V_27 -> V_191 = ( ( void V_198 * ) V_27 -> V_199 ) + 4096 ;
V_12 = F_96 ( V_27 , 0 , 64 , 0 ) ;
if ( ! V_12 )
return - V_100 ;
V_196 = V_12 -> V_14 - 1 ;
V_196 |= V_196 << 16 ;
V_27 -> V_200 = V_201 | V_202 ;
V_27 -> V_200 |= ( V_203 - 12 ) << V_204 ;
V_27 -> V_200 |= V_205 | V_206 ;
V_27 -> V_200 |= V_207 | V_208 ;
F_22 ( 0 , & V_27 -> V_199 -> V_209 ) ;
F_22 ( V_196 , & V_27 -> V_199 -> V_196 ) ;
F_107 ( V_12 -> V_171 , & V_27 -> V_199 -> V_210 ) ;
F_107 ( V_12 -> V_162 , & V_27 -> V_199 -> V_211 ) ;
F_22 ( V_27 -> V_200 , & V_27 -> V_199 -> V_209 ) ;
V_197 = F_108 ( & V_27 -> V_199 -> V_197 ) ;
V_17 = ( ( F_109 ( V_197 ) + 1 ) * V_212 / 2 ) + V_23 ;
V_27 -> V_143 = F_110 ( V_197 ) ;
while ( ! ( F_111 ( & V_27 -> V_199 -> V_213 ) & V_214 ) ) {
F_112 ( 100 ) ;
if ( F_113 ( V_151 ) )
return - V_25 ;
if ( F_114 ( V_23 , V_17 ) ) {
F_115 ( & V_27 -> V_33 -> V_27 ,
L_4 ) ;
return - V_215 ;
}
}
V_110 = F_103 ( V_27 , V_12 , L_5 ) ;
V_27 -> V_37 [ 0 ] = V_12 ;
return V_110 ;
}
static struct V_45 * F_116 ( struct V_26 * V_27 , int V_216 ,
unsigned long V_217 , unsigned V_57 )
{
int V_59 , V_218 , V_219 , V_73 , V_47 ;
struct V_54 * V_55 ;
struct V_220 * * V_221 ;
struct V_45 * V_46 ;
if ( V_217 & 3 )
return F_117 ( - V_222 ) ;
if ( ! V_57 )
return F_117 ( - V_222 ) ;
V_47 = F_46 ( V_217 ) ;
V_219 = F_26 ( V_47 + V_57 , V_50 ) ;
V_221 = F_118 ( V_219 , sizeof( * V_221 ) , V_188 ) ;
V_218 = F_119 ( V_217 , V_219 , 1 , V_221 ) ;
if ( V_218 < V_219 ) {
V_219 = V_218 ;
V_218 = - V_223 ;
goto V_224;
}
V_46 = F_27 ( V_219 , V_57 , V_188 ) ;
V_55 = V_46 -> V_55 ;
F_52 ( V_55 , V_219 ) ;
for ( V_59 = 0 ; V_59 < V_219 ; V_59 ++ ) {
F_56 ( & V_55 [ V_59 ] , V_221 [ V_59 ] ,
F_120 ( int , V_57 , V_50 - V_47 ) , V_47 ) ;
V_57 -= ( V_50 - V_47 ) ;
V_47 = 0 ;
}
F_57 ( & V_55 [ V_59 - 1 ] ) ;
V_46 -> V_73 = V_219 ;
V_218 = - V_100 ;
V_73 = F_58 ( & V_27 -> V_33 -> V_27 , V_55 , V_219 ,
V_216 ? V_74 : V_75 ) ;
if ( ! V_73 )
goto V_119;
F_33 ( V_221 ) ;
return V_46 ;
V_119:
F_33 ( V_46 ) ;
V_224:
for ( V_59 = 0 ; V_59 < V_219 ; V_59 ++ )
F_121 ( V_221 [ V_59 ] ) ;
F_33 ( V_221 ) ;
return F_117 ( V_218 ) ;
}
static void F_122 ( struct V_26 * V_27 , int V_216 ,
struct V_45 * V_46 )
{
int V_59 ;
F_40 ( & V_27 -> V_33 -> V_27 , V_46 -> V_55 , V_46 -> V_73 ,
V_216 ? V_74 : V_75 ) ;
for ( V_59 = 0 ; V_59 < V_46 -> V_73 ; V_59 ++ )
F_121 ( F_123 ( & V_46 -> V_55 [ V_59 ] ) ) ;
}
static int F_124 ( struct V_101 * V_102 , struct V_225 T_11 * V_226 )
{
struct V_26 * V_27 = V_102 -> V_27 ;
struct V_11 * V_12 ;
struct V_225 V_227 ;
struct V_6 V_155 ;
unsigned V_57 ;
int V_72 ;
struct V_45 * V_46 ;
if ( F_125 ( & V_227 , V_226 , sizeof( V_227 ) ) )
return - V_223 ;
V_57 = ( V_227 . V_228 + 1 ) << V_102 -> V_132 ;
switch ( V_227 . V_105 ) {
case V_127 :
case V_128 :
case V_229 :
V_46 = F_116 ( V_27 , V_227 . V_105 & 1 , V_227 . V_217 , V_57 ) ;
break;
default:
return - V_222 ;
}
if ( F_126 ( V_46 ) )
return F_127 ( V_46 ) ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_126 . V_105 = V_227 . V_105 ;
V_155 . V_126 . V_39 = V_227 . V_39 ;
V_155 . V_126 . V_107 = F_60 ( V_102 -> V_108 ) ;
V_155 . V_126 . V_130 = F_47 ( V_227 . V_130 ) ;
V_155 . V_126 . V_57 = F_65 ( V_227 . V_228 ) ;
V_155 . V_126 . V_111 = F_65 ( V_227 . V_111 ) ;
V_155 . V_126 . V_112 = F_65 ( V_227 . V_112 ) ;
V_155 . V_126 . V_230 = V_227 . V_230 ;
V_155 . V_126 . V_231 = V_227 . V_231 ;
V_155 . V_126 . V_232 = V_227 . V_232 ;
V_57 = F_43 ( V_27 , & V_155 . V_104 , V_46 , V_57 , V_188 ) ;
V_12 = F_16 ( V_27 ) ;
F_18 ( V_12 ) ;
if ( V_57 != ( V_227 . V_228 + 1 ) << V_102 -> V_132 )
V_72 = - V_100 ;
else
V_72 = F_78 ( V_12 , & V_155 , NULL , V_109 ) ;
F_122 ( V_27 , V_227 . V_105 & 1 , V_46 ) ;
F_30 ( V_27 , V_46 ) ;
return V_72 ;
}
static int F_128 ( struct V_101 * V_102 ,
struct V_233 T_11 * V_234 )
{
struct V_26 * V_27 = V_102 -> V_27 ;
struct V_233 V_38 ;
struct V_6 V_155 ;
int V_72 , V_57 ;
struct V_45 * V_46 ;
if ( ! F_129 ( V_235 ) )
return - V_236 ;
if ( F_125 ( & V_38 , V_234 , sizeof( V_38 ) ) )
return - V_223 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_104 . V_105 = V_38 . V_105 ;
V_155 . V_104 . V_39 = V_38 . V_39 ;
V_155 . V_104 . V_107 = F_60 ( V_38 . V_107 ) ;
V_155 . V_104 . V_237 [ 0 ] = F_60 ( V_38 . V_237 ) ;
V_155 . V_104 . V_237 [ 1 ] = F_60 ( V_38 . V_238 ) ;
V_155 . V_104 . V_239 [ 0 ] = F_60 ( V_38 . V_239 ) ;
V_155 . V_104 . V_239 [ 1 ] = F_60 ( V_38 . V_240 ) ;
V_155 . V_104 . V_239 [ 2 ] = F_60 ( V_38 . V_241 ) ;
V_155 . V_104 . V_239 [ 3 ] = F_60 ( V_38 . V_242 ) ;
V_155 . V_104 . V_239 [ 4 ] = F_60 ( V_38 . V_243 ) ;
V_155 . V_104 . V_239 [ 5 ] = F_60 ( V_38 . V_244 ) ;
V_57 = V_38 . V_245 ;
if ( V_38 . V_245 ) {
V_46 = F_116 ( V_27 , V_38 . V_105 & 1 , V_38 . V_217 ,
V_57 ) ;
if ( F_126 ( V_46 ) )
return F_127 ( V_46 ) ;
V_57 = F_43 ( V_27 , & V_155 . V_104 , V_46 , V_57 ,
V_188 ) ;
}
if ( V_57 != V_38 . V_245 )
V_72 = - V_100 ;
else
V_72 = F_81 ( V_27 , & V_155 , NULL ) ;
if ( V_38 . V_245 ) {
F_122 ( V_27 , V_38 . V_105 & 1 , V_46 ) ;
F_30 ( V_27 , V_46 ) ;
}
return V_72 ;
}
static int F_130 ( struct V_246 * V_247 , T_12 V_248 , unsigned int V_38 ,
unsigned long V_249 )
{
struct V_101 * V_102 = V_247 -> V_250 -> V_251 ;
switch ( V_38 ) {
case V_252 :
return V_102 -> V_108 ;
case V_253 :
return F_128 ( V_102 , ( void T_11 * ) V_249 ) ;
case V_254 :
return F_124 ( V_102 , ( void T_11 * ) V_249 ) ;
default:
return - V_255 ;
}
}
static void F_131 ( struct V_11 * V_12 )
{
int V_18 = V_12 -> V_14 - 1 ;
struct V_10 * V_19 = V_10 ( V_12 ) ;
unsigned long V_256 = V_23 ;
int V_20 ;
F_132 (cmdid, nvmeq->cmdid_data, depth) {
void * V_15 ;
T_1 V_22 ;
static struct V_28 V_29 = { . V_72 = F_65 ( V_257 ) << 1 , } ;
if ( ! F_114 ( V_256 , V_19 [ V_20 ] . V_17 ) )
continue;
F_10 ( V_12 -> V_129 , L_6 , V_20 ) ;
V_15 = F_15 ( V_12 , V_20 , & V_22 ) ;
V_22 ( V_12 -> V_27 , V_15 , & V_29 ) ;
}
}
static void F_133 ( struct V_11 * V_12 )
{
while ( F_134 ( & V_12 -> V_68 ) ) {
struct V_67 * V_67 = F_135 ( & V_12 -> V_68 ) ;
struct V_101 * V_102 = V_67 -> V_258 -> V_250 -> V_251 ;
if ( F_63 ( V_12 , V_102 , V_67 ) ) {
F_136 ( & V_12 -> V_68 , V_67 ) ;
break;
}
if ( F_35 ( & V_12 -> V_68 ) )
F_137 ( & V_12 -> V_24 ,
& V_12 -> V_69 ) ;
}
}
static int F_138 ( void * V_146 )
{
struct V_26 * V_27 ;
while ( ! F_139 () ) {
F_140 ( V_259 ) ;
F_72 ( & V_260 ) ;
F_141 (dev, &dev_list, node) {
int V_59 ;
for ( V_59 = 0 ; V_59 < V_27 -> V_261 ; V_59 ++ ) {
struct V_11 * V_12 = V_27 -> V_37 [ V_59 ] ;
if ( ! V_12 )
continue;
F_67 ( & V_12 -> V_41 ) ;
if ( F_69 ( V_12 ) )
F_142 ( L_7 ) ;
F_131 ( V_12 ) ;
F_133 ( V_12 ) ;
F_68 ( & V_12 -> V_41 ) ;
}
}
F_73 ( & V_260 ) ;
F_79 ( V_262 ) ;
F_143 ( V_212 ) ;
}
return 0 ;
}
static int F_144 ( void )
{
int V_263 , error ;
do {
if ( ! F_145 ( & V_264 , V_188 ) )
return - 1 ;
F_72 ( & V_260 ) ;
error = F_146 ( & V_264 , & V_263 ) ;
F_73 ( & V_260 ) ;
} while ( error == - V_265 );
if ( error )
V_263 = - 1 ;
return V_263 ;
}
static void F_147 ( int V_263 )
{
F_72 ( & V_260 ) ;
F_148 ( & V_264 , V_263 ) ;
F_73 ( & V_260 ) ;
}
static struct V_101 * F_149 ( struct V_26 * V_27 , int V_107 ,
struct V_8 * V_154 , struct V_9 * V_266 )
{
struct V_101 * V_102 ;
struct V_267 * V_268 ;
int V_269 ;
if ( V_266 -> V_270 & V_271 )
return NULL ;
V_102 = F_97 ( sizeof( * V_102 ) , V_188 ) ;
if ( ! V_102 )
return NULL ;
V_102 -> V_113 = F_150 ( V_188 ) ;
if ( ! V_102 -> V_113 )
goto V_272;
V_102 -> V_113 -> V_273 = V_274 ;
F_151 ( V_275 , V_102 -> V_113 ) ;
F_151 ( V_276 , V_102 -> V_113 ) ;
F_152 ( V_102 -> V_113 , F_66 ) ;
V_102 -> V_27 = V_27 ;
V_102 -> V_113 -> V_135 = V_102 ;
V_268 = F_153 ( V_277 ) ;
if ( ! V_268 )
goto V_278;
V_102 -> V_108 = V_107 ;
V_102 -> V_268 = V_268 ;
V_269 = V_154 -> V_279 & 0xf ;
V_102 -> V_132 = V_154 -> V_269 [ V_269 ] . V_280 ;
V_268 -> V_281 = V_282 ;
V_268 -> V_283 = V_277 ;
V_268 -> V_284 = V_277 * F_144 () ;
V_268 -> V_285 = & V_286 ;
V_268 -> V_251 = V_102 ;
V_268 -> V_113 = V_102 -> V_113 ;
V_268 -> V_287 = & V_27 -> V_33 -> V_27 ;
sprintf ( V_268 -> V_288 , L_8 , V_27 -> V_289 , V_107 ) ;
F_154 ( V_268 , F_155 ( & V_154 -> V_290 ) << ( V_102 -> V_132 - 9 ) ) ;
return V_102 ;
V_278:
F_156 ( V_102 -> V_113 ) ;
V_272:
F_33 ( V_102 ) ;
return NULL ;
}
static void F_157 ( struct V_101 * V_102 )
{
int V_263 = V_102 -> V_268 -> V_284 / V_277 ;
F_158 ( V_102 -> V_268 ) ;
F_147 ( V_263 ) ;
F_156 ( V_102 -> V_113 ) ;
F_33 ( V_102 ) ;
}
static int F_159 ( struct V_26 * V_27 , int V_219 )
{
int V_72 ;
T_7 V_110 ;
T_7 V_291 = ( V_219 - 1 ) | ( ( V_219 - 1 ) << 16 ) ;
V_72 = F_89 ( V_27 , V_292 , V_291 , 0 ,
& V_110 ) ;
if ( V_72 )
return - V_76 ;
return F_160 ( V_110 & 0xffff , V_110 >> 16 ) + 1 ;
}
static int T_10 F_161 ( struct V_26 * V_27 )
{
int V_110 , V_293 , V_59 , V_294 , V_295 ;
V_294 = F_162 () ;
V_110 = F_159 ( V_27 , V_294 ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_110 < V_294 )
V_294 = V_110 ;
F_92 ( V_27 -> V_185 [ 0 ] . V_184 , V_27 -> V_37 [ 0 ] ) ;
V_295 = 4096 + ( ( V_294 + 1 ) << ( V_27 -> V_143 + 3 ) ) ;
if ( V_295 > 8192 ) {
F_163 ( V_27 -> V_199 ) ;
V_27 -> V_199 = F_164 ( F_165 ( V_27 -> V_33 , 0 ) ,
V_295 ) ;
V_27 -> V_191 = ( ( void V_198 * ) V_27 -> V_199 ) + 4096 ;
V_27 -> V_37 [ 0 ] -> V_44 = V_27 -> V_191 ;
}
for ( V_59 = 0 ; V_59 < V_294 ; V_59 ++ )
V_27 -> V_185 [ V_59 ] . V_185 = V_59 ;
for (; ; ) {
V_110 = F_166 ( V_27 -> V_33 , V_27 -> V_185 ,
V_294 ) ;
if ( V_110 == 0 ) {
break;
} else if ( V_110 > 0 ) {
V_294 = V_110 ;
continue;
} else {
V_294 = 1 ;
break;
}
}
V_110 = F_103 ( V_27 , V_27 -> V_37 [ 0 ] , L_5 ) ;
V_293 = F_167 ( V_296 ) ;
for ( V_59 = 0 ; V_59 < V_294 ; V_59 ++ ) {
F_91 ( V_27 -> V_185 [ V_59 ] . V_184 , F_168 ( V_293 ) ) ;
V_293 = F_169 ( V_293 , V_296 ) ;
}
for ( V_59 = 0 ; V_59 < V_294 ; V_59 ++ ) {
V_27 -> V_37 [ V_59 + 1 ] = F_170 ( V_27 , V_59 + 1 ,
V_297 , V_59 ) ;
if ( F_126 ( V_27 -> V_37 [ V_59 + 1 ] ) )
return F_127 ( V_27 -> V_37 [ V_59 + 1 ] ) ;
V_27 -> V_261 ++ ;
}
for (; V_59 < F_171 () ; V_59 ++ ) {
int V_298 = V_59 % F_172 ( V_27 -> V_261 - 1 ) ;
V_27 -> V_37 [ V_59 + 1 ] = V_27 -> V_37 [ V_298 + 1 ] ;
}
return 0 ;
}
static void F_173 ( struct V_26 * V_27 )
{
int V_59 ;
for ( V_59 = V_27 -> V_261 - 1 ; V_59 >= 0 ; V_59 -- )
F_90 ( V_27 , V_59 ) ;
}
static int T_10 F_174 ( struct V_26 * V_27 )
{
int V_299 , V_300 , V_59 ;
struct V_101 * V_102 , * V_301 ;
struct V_7 * V_302 ;
struct V_8 * V_303 ;
void * V_304 ;
T_5 V_84 ;
V_299 = F_161 ( V_27 ) ;
if ( V_299 )
return V_299 ;
V_304 = F_98 ( & V_27 -> V_33 -> V_27 , 8192 , & V_84 ,
V_188 ) ;
V_299 = F_87 ( V_27 , 0 , 1 , V_84 ) ;
if ( V_299 ) {
V_299 = - V_76 ;
goto V_305;
}
V_302 = V_304 ;
V_300 = F_77 ( & V_302 -> V_300 ) ;
memcpy ( V_27 -> V_306 , V_302 -> V_307 , sizeof( V_302 -> V_307 ) ) ;
memcpy ( V_27 -> V_308 , V_302 -> V_309 , sizeof( V_302 -> V_309 ) ) ;
memcpy ( V_27 -> V_310 , V_302 -> V_311 , sizeof( V_302 -> V_311 ) ) ;
V_303 = V_304 ;
for ( V_59 = 1 ; V_59 <= V_300 ; V_59 ++ ) {
V_299 = F_87 ( V_27 , V_59 , 0 , V_84 ) ;
if ( V_299 )
continue;
if ( V_303 -> V_312 == 0 )
continue;
V_299 = F_88 ( V_27 , V_313 , V_59 ,
V_84 + 4096 ) ;
if ( V_299 )
continue;
V_102 = F_149 ( V_27 , V_59 , V_304 , V_304 + 4096 ) ;
if ( V_102 )
F_175 ( & V_102 -> V_60 , & V_27 -> V_314 ) ;
}
F_141 (ns, &dev->namespaces, list)
F_176 ( V_102 -> V_268 ) ;
goto V_315;
V_305:
F_177 (ns, next, &dev->namespaces, list) {
F_178 ( & V_102 -> V_60 ) ;
F_157 ( V_102 ) ;
}
V_315:
F_93 ( & V_27 -> V_33 -> V_27 , 8192 , V_304 , V_84 ) ;
return V_299 ;
}
static int F_179 ( struct V_26 * V_27 )
{
struct V_101 * V_102 , * V_301 ;
F_72 ( & V_260 ) ;
F_178 ( & V_27 -> V_316 ) ;
F_73 ( & V_260 ) ;
F_177 (ns, next, &dev->namespaces, list) {
F_178 ( & V_102 -> V_60 ) ;
F_180 ( V_102 -> V_268 ) ;
F_157 ( V_102 ) ;
}
F_173 ( V_27 ) ;
return 0 ;
}
static int F_181 ( struct V_26 * V_27 )
{
struct V_88 * V_186 = & V_27 -> V_33 -> V_27 ;
V_27 -> V_66 = F_182 ( L_9 , V_186 ,
V_50 , V_50 , 0 ) ;
if ( ! V_27 -> V_66 )
return - V_100 ;
V_27 -> V_63 = F_182 ( L_10 , V_186 ,
256 , 256 , 0 ) ;
if ( ! V_27 -> V_63 ) {
F_183 ( V_27 -> V_66 ) ;
return - V_100 ;
}
return 0 ;
}
static void F_184 ( struct V_26 * V_27 )
{
F_183 ( V_27 -> V_66 ) ;
F_183 ( V_27 -> V_63 ) ;
}
static void F_185 ( struct V_26 * V_27 )
{
static int V_289 ;
V_27 -> V_289 = V_289 ++ ;
}
static void F_186 ( struct V_26 * V_27 )
{
}
static int T_10 F_187 ( struct V_33 * V_317 ,
const struct V_318 * V_154 )
{
int V_319 , V_110 = - V_100 ;
struct V_26 * V_27 ;
V_27 = F_97 ( sizeof( * V_27 ) , V_188 ) ;
if ( ! V_27 )
return - V_100 ;
V_27 -> V_185 = F_118 ( F_171 () , sizeof( * V_27 -> V_185 ) ,
V_188 ) ;
if ( ! V_27 -> V_185 )
goto free;
V_27 -> V_37 = F_118 ( F_171 () + 1 , sizeof( void * ) ,
V_188 ) ;
if ( ! V_27 -> V_37 )
goto free;
if ( F_188 ( V_317 ) )
goto free;
F_189 ( V_317 ) ;
V_319 = F_190 ( V_317 , V_320 ) ;
if ( F_191 ( V_317 , V_319 , L_11 ) )
goto V_321;
F_192 ( & V_27 -> V_314 ) ;
V_27 -> V_33 = V_317 ;
F_193 ( V_317 , V_27 ) ;
F_194 ( & V_317 -> V_27 , F_195 ( 64 ) ) ;
F_196 ( & V_317 -> V_27 , F_195 ( 64 ) ) ;
F_185 ( V_27 ) ;
V_27 -> V_185 [ 0 ] . V_184 = V_317 -> V_145 ;
V_110 = F_181 ( V_27 ) ;
if ( V_110 )
goto V_322;
V_27 -> V_199 = F_164 ( F_165 ( V_317 , 0 ) , 8192 ) ;
if ( ! V_27 -> V_199 ) {
V_110 = - V_100 ;
goto V_322;
}
V_110 = F_106 ( V_27 ) ;
if ( V_110 )
goto V_323;
V_27 -> V_261 ++ ;
F_72 ( & V_260 ) ;
F_197 ( & V_27 -> V_316 , & V_324 ) ;
F_73 ( & V_260 ) ;
V_110 = F_174 ( V_27 ) ;
if ( V_110 )
goto V_325;
return 0 ;
V_325:
F_72 ( & V_260 ) ;
F_178 ( & V_27 -> V_316 ) ;
F_73 ( & V_260 ) ;
F_173 ( V_27 ) ;
V_323:
F_163 ( V_27 -> V_199 ) ;
V_322:
F_198 ( V_317 ) ;
F_186 ( V_27 ) ;
F_184 ( V_27 ) ;
V_321:
F_199 ( V_317 ) ;
F_200 ( V_317 ) ;
free:
F_33 ( V_27 -> V_37 ) ;
F_33 ( V_27 -> V_185 ) ;
F_33 ( V_27 ) ;
return V_110 ;
}
static void T_13 F_201 ( struct V_33 * V_317 )
{
struct V_26 * V_27 = F_202 ( V_317 ) ;
F_179 ( V_27 ) ;
F_198 ( V_317 ) ;
F_163 ( V_27 -> V_199 ) ;
F_186 ( V_27 ) ;
F_184 ( V_27 ) ;
F_199 ( V_317 ) ;
F_200 ( V_317 ) ;
F_33 ( V_27 -> V_37 ) ;
F_33 ( V_27 -> V_185 ) ;
F_33 ( V_27 ) ;
}
static int T_14 F_203 ( void )
{
int V_110 = - V_21 ;
V_70 = F_204 ( F_138 , NULL , L_11 ) ;
if ( F_126 ( V_70 ) )
return F_127 ( V_70 ) ;
V_282 = F_205 ( V_282 , L_11 ) ;
if ( V_282 <= 0 )
goto V_326;
V_110 = F_206 ( & V_327 ) ;
if ( V_110 )
goto V_328;
return 0 ;
V_328:
V_328 ( V_282 , L_11 ) ;
V_326:
F_207 ( V_70 ) ;
return V_110 ;
}
static void T_15 F_208 ( void )
{
F_209 ( & V_327 ) ;
V_328 ( V_282 , L_11 ) ;
F_207 ( V_70 ) ;
}
