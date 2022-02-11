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
unsigned V_107 , T_5 V_84 )
{
struct V_6 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_180 . V_105 = V_181 ;
V_155 . V_180 . V_107 = F_60 ( V_107 ) ;
V_155 . V_180 . V_85 = F_47 ( V_84 ) ;
V_155 . V_180 . V_179 = F_60 ( V_179 ) ;
return F_81 ( V_27 , & V_155 , NULL ) ;
}
static int F_89 ( struct V_26 * V_27 , unsigned V_179 ,
unsigned V_182 , T_5 V_84 , T_7 * V_110 )
{
struct V_6 V_155 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_180 . V_105 = V_183 ;
V_155 . V_180 . V_85 = F_47 ( V_84 ) ;
V_155 . V_180 . V_179 = F_60 ( V_179 ) ;
V_155 . V_180 . V_182 = F_60 ( V_182 ) ;
return F_81 ( V_27 , & V_155 , V_110 ) ;
}
static void F_90 ( struct V_11 * V_12 , bool V_17 )
{
int V_18 = V_12 -> V_14 - 1 ;
struct V_10 * V_19 = V_10 ( V_12 ) ;
unsigned long V_184 = V_23 ;
int V_20 ;
F_91 (cmdid, nvmeq->cmdid_data, depth) {
void * V_15 ;
T_1 V_22 ;
static struct V_28 V_29 = {
. V_72 = F_65 ( V_185 ) << 1 ,
} ;
if ( V_17 && ! F_92 ( V_184 , V_19 [ V_20 ] . V_17 ) )
continue;
F_10 ( V_12 -> V_129 , L_4 , V_20 ) ;
V_15 = F_15 ( V_12 , V_20 , & V_22 ) ;
V_22 ( V_12 -> V_27 , V_15 , & V_29 ) ;
}
}
static void F_93 ( struct V_11 * V_12 )
{
F_94 ( V_12 -> V_129 , F_95 ( V_12 -> V_14 ) ,
( void * ) V_12 -> V_140 , V_12 -> V_162 ) ;
F_94 ( V_12 -> V_129 , F_96 ( V_12 -> V_14 ) ,
V_12 -> V_43 , V_12 -> V_171 ) ;
F_33 ( V_12 ) ;
}
static void F_97 ( struct V_26 * V_27 , int V_157 )
{
struct V_11 * V_12 = V_27 -> V_37 [ V_157 ] ;
int V_186 = V_27 -> V_187 [ V_12 -> V_167 ] . V_186 ;
F_67 ( & V_12 -> V_41 ) ;
F_90 ( V_12 , false ) ;
F_68 ( & V_12 -> V_41 ) ;
F_98 ( V_186 , NULL ) ;
F_99 ( V_186 , V_12 ) ;
if ( V_157 ) {
F_86 ( V_27 , V_157 ) ;
F_85 ( V_27 , V_157 ) ;
}
F_93 ( V_12 ) ;
}
static struct V_11 * F_100 ( struct V_26 * V_27 , int V_157 ,
int V_18 , int V_186 )
{
struct V_88 * V_188 = & V_27 -> V_33 -> V_27 ;
unsigned V_189 = F_26 ( V_18 , 8 ) + ( V_18 *
sizeof( struct V_10 ) ) ;
struct V_11 * V_12 = F_101 ( sizeof( * V_12 ) + V_189 , V_190 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_140 = F_102 ( V_188 , F_95 ( V_18 ) ,
& V_12 -> V_162 , V_190 ) ;
if ( ! V_12 -> V_140 )
goto V_191;
memset ( ( void * ) V_12 -> V_140 , 0 , F_95 ( V_18 ) ) ;
V_12 -> V_43 = F_102 ( V_188 , F_96 ( V_18 ) ,
& V_12 -> V_171 , V_190 ) ;
if ( ! V_12 -> V_43 )
goto V_192;
V_12 -> V_129 = V_188 ;
V_12 -> V_27 = V_27 ;
F_103 ( & V_12 -> V_41 ) ;
V_12 -> V_138 = 0 ;
V_12 -> V_139 = 1 ;
F_104 ( & V_12 -> V_24 ) ;
F_105 ( & V_12 -> V_69 , V_70 ) ;
F_106 ( & V_12 -> V_68 ) ;
V_12 -> V_44 = & V_27 -> V_193 [ V_157 << ( V_27 -> V_143 + 1 ) ] ;
V_12 -> V_14 = V_18 ;
V_12 -> V_167 = V_186 ;
return V_12 ;
V_192:
F_94 ( V_188 , F_95 ( V_12 -> V_14 ) , ( void * ) V_12 -> V_140 ,
V_12 -> V_162 ) ;
V_191:
F_33 ( V_12 ) ;
return NULL ;
}
static int F_107 ( struct V_26 * V_27 , struct V_11 * V_12 ,
const char * V_194 )
{
if ( V_195 )
return F_108 ( V_27 -> V_187 [ V_12 -> V_167 ] . V_186 ,
F_74 , F_71 ,
V_196 | V_197 ,
V_194 , V_12 ) ;
return F_109 ( V_27 -> V_187 [ V_12 -> V_167 ] . V_186 , F_71 ,
V_196 | V_197 , V_194 , V_12 ) ;
}
static struct V_11 * F_110 ( struct V_26 * V_27 , int V_157 ,
int V_198 , int V_186 )
{
int V_110 ;
struct V_11 * V_12 = F_100 ( V_27 , V_157 , V_198 , V_186 ) ;
if ( ! V_12 )
return F_111 ( - V_100 ) ;
V_110 = F_83 ( V_27 , V_157 , V_12 ) ;
if ( V_110 < 0 )
goto V_191;
V_110 = F_84 ( V_27 , V_157 , V_12 ) ;
if ( V_110 < 0 )
goto V_199;
V_110 = F_107 ( V_27 , V_12 , L_5 ) ;
if ( V_110 < 0 )
goto V_200;
return V_12 ;
V_200:
F_86 ( V_27 , V_157 ) ;
V_199:
F_85 ( V_27 , V_157 ) ;
V_191:
F_94 ( V_12 -> V_129 , F_95 ( V_12 -> V_14 ) ,
( void * ) V_12 -> V_140 , V_12 -> V_162 ) ;
F_94 ( V_12 -> V_129 , F_96 ( V_12 -> V_14 ) ,
V_12 -> V_43 , V_12 -> V_171 ) ;
F_33 ( V_12 ) ;
return F_111 ( V_110 ) ;
}
static int F_112 ( struct V_26 * V_27 )
{
int V_110 = 0 ;
T_7 V_201 ;
T_6 V_202 ;
unsigned long V_17 ;
struct V_11 * V_12 ;
V_27 -> V_193 = ( ( void V_203 * ) V_27 -> V_204 ) + 4096 ;
V_12 = F_100 ( V_27 , 0 , 64 , 0 ) ;
if ( ! V_12 )
return - V_100 ;
V_201 = V_12 -> V_14 - 1 ;
V_201 |= V_201 << 16 ;
V_27 -> V_205 = V_206 | V_207 ;
V_27 -> V_205 |= ( V_208 - 12 ) << V_209 ;
V_27 -> V_205 |= V_210 | V_211 ;
V_27 -> V_205 |= V_212 | V_213 ;
F_22 ( 0 , & V_27 -> V_204 -> V_214 ) ;
F_22 ( V_201 , & V_27 -> V_204 -> V_201 ) ;
F_113 ( V_12 -> V_171 , & V_27 -> V_204 -> V_215 ) ;
F_113 ( V_12 -> V_162 , & V_27 -> V_204 -> V_216 ) ;
F_22 ( V_27 -> V_205 , & V_27 -> V_204 -> V_214 ) ;
V_202 = F_114 ( & V_27 -> V_204 -> V_202 ) ;
V_17 = ( ( F_115 ( V_202 ) + 1 ) * V_217 / 2 ) + V_23 ;
V_27 -> V_143 = F_116 ( V_202 ) ;
while ( ! V_110 && ! ( F_117 ( & V_27 -> V_204 -> V_218 ) & V_219 ) ) {
F_118 ( 100 ) ;
if ( F_119 ( V_151 ) )
V_110 = - V_25 ;
if ( F_92 ( V_23 , V_17 ) ) {
F_120 ( & V_27 -> V_33 -> V_27 ,
L_6 ) ;
V_110 = - V_220 ;
}
}
if ( V_110 ) {
F_93 ( V_12 ) ;
return V_110 ;
}
V_110 = F_107 ( V_27 , V_12 , L_7 ) ;
V_27 -> V_37 [ 0 ] = V_12 ;
return V_110 ;
}
static struct V_45 * F_121 ( struct V_26 * V_27 , int V_221 ,
unsigned long V_222 , unsigned V_57 )
{
int V_59 , V_223 , V_224 , V_73 , V_47 ;
struct V_54 * V_55 ;
struct V_225 * * V_226 ;
struct V_45 * V_46 ;
if ( V_222 & 3 )
return F_111 ( - V_227 ) ;
if ( ! V_57 )
return F_111 ( - V_227 ) ;
V_47 = F_46 ( V_222 ) ;
V_224 = F_26 ( V_47 + V_57 , V_50 ) ;
V_226 = F_122 ( V_224 , sizeof( * V_226 ) , V_190 ) ;
if ( ! V_226 )
return F_111 ( - V_100 ) ;
V_223 = F_123 ( V_222 , V_224 , 1 , V_226 ) ;
if ( V_223 < V_224 ) {
V_224 = V_223 ;
V_223 = - V_228 ;
goto V_229;
}
V_46 = F_27 ( V_224 , V_57 , V_190 ) ;
V_55 = V_46 -> V_55 ;
F_52 ( V_55 , V_224 ) ;
for ( V_59 = 0 ; V_59 < V_224 ; V_59 ++ ) {
F_56 ( & V_55 [ V_59 ] , V_226 [ V_59 ] ,
F_124 ( int , V_57 , V_50 - V_47 ) , V_47 ) ;
V_57 -= ( V_50 - V_47 ) ;
V_47 = 0 ;
}
F_57 ( & V_55 [ V_59 - 1 ] ) ;
V_46 -> V_73 = V_224 ;
V_223 = - V_100 ;
V_73 = F_58 ( & V_27 -> V_33 -> V_27 , V_55 , V_224 ,
V_221 ? V_74 : V_75 ) ;
if ( ! V_73 )
goto V_119;
F_33 ( V_226 ) ;
return V_46 ;
V_119:
F_33 ( V_46 ) ;
V_229:
for ( V_59 = 0 ; V_59 < V_224 ; V_59 ++ )
F_125 ( V_226 [ V_59 ] ) ;
F_33 ( V_226 ) ;
return F_111 ( V_223 ) ;
}
static void F_126 ( struct V_26 * V_27 , int V_221 ,
struct V_45 * V_46 )
{
int V_59 ;
F_40 ( & V_27 -> V_33 -> V_27 , V_46 -> V_55 , V_46 -> V_73 ,
V_221 ? V_74 : V_75 ) ;
for ( V_59 = 0 ; V_59 < V_46 -> V_73 ; V_59 ++ )
F_125 ( F_127 ( & V_46 -> V_55 [ V_59 ] ) ) ;
}
static int F_128 ( struct V_101 * V_102 , struct V_230 T_10 * V_231 )
{
struct V_26 * V_27 = V_102 -> V_27 ;
struct V_11 * V_12 ;
struct V_230 V_232 ;
struct V_6 V_155 ;
unsigned V_57 ;
int V_72 ;
struct V_45 * V_46 ;
if ( F_129 ( & V_232 , V_231 , sizeof( V_232 ) ) )
return - V_228 ;
V_57 = ( V_232 . V_233 + 1 ) << V_102 -> V_132 ;
switch ( V_232 . V_105 ) {
case V_127 :
case V_128 :
case V_234 :
V_46 = F_121 ( V_27 , V_232 . V_105 & 1 , V_232 . V_222 , V_57 ) ;
break;
default:
return - V_227 ;
}
if ( F_130 ( V_46 ) )
return F_131 ( V_46 ) ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_126 . V_105 = V_232 . V_105 ;
V_155 . V_126 . V_39 = V_232 . V_39 ;
V_155 . V_126 . V_107 = F_60 ( V_102 -> V_108 ) ;
V_155 . V_126 . V_130 = F_47 ( V_232 . V_130 ) ;
V_155 . V_126 . V_57 = F_65 ( V_232 . V_233 ) ;
V_155 . V_126 . V_111 = F_65 ( V_232 . V_111 ) ;
V_155 . V_126 . V_112 = F_65 ( V_232 . V_112 ) ;
V_155 . V_126 . V_235 = V_232 . V_235 ;
V_155 . V_126 . V_236 = V_232 . V_236 ;
V_155 . V_126 . V_237 = V_232 . V_237 ;
V_57 = F_43 ( V_27 , & V_155 . V_104 , V_46 , V_57 , V_190 ) ;
V_12 = F_16 ( V_27 ) ;
F_18 ( V_12 ) ;
if ( V_57 != ( V_232 . V_233 + 1 ) << V_102 -> V_132 )
V_72 = - V_100 ;
else
V_72 = F_78 ( V_12 , & V_155 , NULL , V_109 ) ;
F_126 ( V_27 , V_232 . V_105 & 1 , V_46 ) ;
F_30 ( V_27 , V_46 ) ;
return V_72 ;
}
static int F_132 ( struct V_26 * V_27 ,
struct V_238 T_10 * V_239 )
{
struct V_238 V_38 ;
struct V_6 V_155 ;
int V_72 , V_57 ;
struct V_45 * V_240 ( V_46 ) ;
if ( ! F_133 ( V_241 ) )
return - V_242 ;
if ( F_129 ( & V_38 , V_239 , sizeof( V_38 ) ) )
return - V_228 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_104 . V_105 = V_38 . V_105 ;
V_155 . V_104 . V_39 = V_38 . V_39 ;
V_155 . V_104 . V_107 = F_60 ( V_38 . V_107 ) ;
V_155 . V_104 . V_243 [ 0 ] = F_60 ( V_38 . V_243 ) ;
V_155 . V_104 . V_243 [ 1 ] = F_60 ( V_38 . V_244 ) ;
V_155 . V_104 . V_245 [ 0 ] = F_60 ( V_38 . V_245 ) ;
V_155 . V_104 . V_245 [ 1 ] = F_60 ( V_38 . V_246 ) ;
V_155 . V_104 . V_245 [ 2 ] = F_60 ( V_38 . V_247 ) ;
V_155 . V_104 . V_245 [ 3 ] = F_60 ( V_38 . V_248 ) ;
V_155 . V_104 . V_245 [ 4 ] = F_60 ( V_38 . V_249 ) ;
V_155 . V_104 . V_245 [ 5 ] = F_60 ( V_38 . V_250 ) ;
V_57 = V_38 . V_251 ;
if ( V_38 . V_251 ) {
V_46 = F_121 ( V_27 , V_38 . V_105 & 1 , V_38 . V_222 ,
V_57 ) ;
if ( F_130 ( V_46 ) )
return F_131 ( V_46 ) ;
V_57 = F_43 ( V_27 , & V_155 . V_104 , V_46 , V_57 ,
V_190 ) ;
}
if ( V_57 != V_38 . V_251 )
V_72 = - V_100 ;
else
V_72 = F_81 ( V_27 , & V_155 , NULL ) ;
if ( V_38 . V_251 ) {
F_126 ( V_27 , V_38 . V_105 & 1 , V_46 ) ;
F_30 ( V_27 , V_46 ) ;
}
return V_72 ;
}
static int F_134 ( struct V_252 * V_253 , T_11 V_254 , unsigned int V_38 ,
unsigned long V_255 )
{
struct V_101 * V_102 = V_253 -> V_256 -> V_257 ;
switch ( V_38 ) {
case V_258 :
return V_102 -> V_108 ;
case V_259 :
return F_132 ( V_102 -> V_27 , ( void T_10 * ) V_255 ) ;
case V_260 :
return F_128 ( V_102 , ( void T_10 * ) V_255 ) ;
default:
return - V_261 ;
}
}
static void F_135 ( struct V_11 * V_12 )
{
while ( F_136 ( & V_12 -> V_68 ) ) {
struct V_67 * V_67 = F_137 ( & V_12 -> V_68 ) ;
struct V_101 * V_102 = V_67 -> V_262 -> V_256 -> V_257 ;
if ( F_63 ( V_12 , V_102 , V_67 ) ) {
F_138 ( & V_12 -> V_68 , V_67 ) ;
break;
}
if ( F_35 ( & V_12 -> V_68 ) )
F_139 ( & V_12 -> V_24 ,
& V_12 -> V_69 ) ;
}
}
static int F_140 ( void * V_146 )
{
struct V_26 * V_27 ;
while ( ! F_141 () ) {
F_142 ( V_263 ) ;
F_72 ( & V_264 ) ;
F_143 (dev, &dev_list, node) {
int V_59 ;
for ( V_59 = 0 ; V_59 < V_27 -> V_265 ; V_59 ++ ) {
struct V_11 * V_12 = V_27 -> V_37 [ V_59 ] ;
if ( ! V_12 )
continue;
F_67 ( & V_12 -> V_41 ) ;
if ( F_69 ( V_12 ) )
F_144 ( L_8 ) ;
F_90 ( V_12 , true ) ;
F_135 ( V_12 ) ;
F_68 ( & V_12 -> V_41 ) ;
}
}
F_73 ( & V_264 ) ;
F_79 ( V_266 ) ;
F_145 ( V_217 ) ;
}
return 0 ;
}
static int F_146 ( void )
{
int V_267 , error ;
do {
if ( ! F_147 ( & V_268 , V_190 ) )
return - 1 ;
F_72 ( & V_264 ) ;
error = F_148 ( & V_268 , & V_267 ) ;
F_73 ( & V_264 ) ;
} while ( error == - V_269 );
if ( error )
V_267 = - 1 ;
return V_267 ;
}
static void F_149 ( int V_267 )
{
F_72 ( & V_264 ) ;
F_150 ( & V_268 , V_267 ) ;
F_73 ( & V_264 ) ;
}
static struct V_101 * F_151 ( struct V_26 * V_27 , int V_107 ,
struct V_8 * V_154 , struct V_9 * V_270 )
{
struct V_101 * V_102 ;
struct V_271 * V_272 ;
int V_273 ;
if ( V_270 -> V_274 & V_275 )
return NULL ;
V_102 = F_101 ( sizeof( * V_102 ) , V_190 ) ;
if ( ! V_102 )
return NULL ;
V_102 -> V_113 = F_152 ( V_190 ) ;
if ( ! V_102 -> V_113 )
goto V_276;
V_102 -> V_113 -> V_277 = V_278 ;
F_153 ( V_279 , V_102 -> V_113 ) ;
F_153 ( V_280 , V_102 -> V_113 ) ;
F_154 ( V_102 -> V_113 , F_66 ) ;
V_102 -> V_27 = V_27 ;
V_102 -> V_113 -> V_135 = V_102 ;
V_272 = F_155 ( V_281 ) ;
if ( ! V_272 )
goto V_282;
V_102 -> V_108 = V_107 ;
V_102 -> V_272 = V_272 ;
V_273 = V_154 -> V_283 & 0xf ;
V_102 -> V_132 = V_154 -> V_273 [ V_273 ] . V_284 ;
F_156 ( V_102 -> V_113 , 1 << V_102 -> V_132 ) ;
if ( V_27 -> V_285 )
F_157 ( V_102 -> V_113 , V_27 -> V_285 ) ;
V_272 -> V_286 = V_287 ;
V_272 -> V_288 = V_281 ;
V_272 -> V_289 = V_281 * F_146 () ;
V_272 -> V_290 = & V_291 ;
V_272 -> V_257 = V_102 ;
V_272 -> V_113 = V_102 -> V_113 ;
V_272 -> V_292 = & V_27 -> V_33 -> V_27 ;
sprintf ( V_272 -> V_293 , L_9 , V_27 -> V_294 , V_107 ) ;
F_158 ( V_272 , F_159 ( & V_154 -> V_295 ) << ( V_102 -> V_132 - 9 ) ) ;
return V_102 ;
V_282:
F_160 ( V_102 -> V_113 ) ;
V_276:
F_33 ( V_102 ) ;
return NULL ;
}
static void F_161 ( struct V_101 * V_102 )
{
int V_267 = V_102 -> V_272 -> V_289 / V_281 ;
F_162 ( V_102 -> V_272 ) ;
F_149 ( V_267 ) ;
F_160 ( V_102 -> V_113 ) ;
F_33 ( V_102 ) ;
}
static int F_163 ( struct V_26 * V_27 , int V_224 )
{
int V_72 ;
T_7 V_110 ;
T_7 V_296 = ( V_224 - 1 ) | ( ( V_224 - 1 ) << 16 ) ;
V_72 = F_89 ( V_27 , V_297 , V_296 , 0 ,
& V_110 ) ;
if ( V_72 )
return - V_76 ;
return F_164 ( V_110 & 0xffff , V_110 >> 16 ) + 1 ;
}
static int F_165 ( struct V_26 * V_27 )
{
int V_110 , V_298 , V_59 , V_299 , V_300 , V_14 ;
V_299 = F_166 () ;
V_110 = F_163 ( V_27 , V_299 ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_110 < V_299 )
V_299 = V_110 ;
F_99 ( V_27 -> V_187 [ 0 ] . V_186 , V_27 -> V_37 [ 0 ] ) ;
V_300 = 4096 + ( ( V_299 + 1 ) << ( V_27 -> V_143 + 3 ) ) ;
if ( V_300 > 8192 ) {
F_167 ( V_27 -> V_204 ) ;
V_27 -> V_204 = F_168 ( F_169 ( V_27 -> V_33 , 0 ) ,
V_300 ) ;
V_27 -> V_193 = ( ( void V_203 * ) V_27 -> V_204 ) + 4096 ;
V_27 -> V_37 [ 0 ] -> V_44 = V_27 -> V_193 ;
}
for ( V_59 = 0 ; V_59 < V_299 ; V_59 ++ )
V_27 -> V_187 [ V_59 ] . V_187 = V_59 ;
for (; ; ) {
V_110 = F_170 ( V_27 -> V_33 , V_27 -> V_187 ,
V_299 ) ;
if ( V_110 == 0 ) {
break;
} else if ( V_110 > 0 ) {
V_299 = V_110 ;
continue;
} else {
V_299 = 1 ;
break;
}
}
V_110 = F_107 ( V_27 , V_27 -> V_37 [ 0 ] , L_7 ) ;
V_298 = F_171 ( V_301 ) ;
for ( V_59 = 0 ; V_59 < V_299 ; V_59 ++ ) {
F_98 ( V_27 -> V_187 [ V_59 ] . V_186 , F_172 ( V_298 ) ) ;
V_298 = F_173 ( V_298 , V_301 ) ;
}
V_14 = F_124 ( int , F_174 ( F_114 ( & V_27 -> V_204 -> V_202 ) ) + 1 ,
V_302 ) ;
for ( V_59 = 0 ; V_59 < V_299 ; V_59 ++ ) {
V_27 -> V_37 [ V_59 + 1 ] = F_110 ( V_27 , V_59 + 1 , V_14 , V_59 ) ;
if ( F_130 ( V_27 -> V_37 [ V_59 + 1 ] ) )
return F_131 ( V_27 -> V_37 [ V_59 + 1 ] ) ;
V_27 -> V_265 ++ ;
}
for (; V_59 < F_175 () ; V_59 ++ ) {
int V_303 = V_59 % F_176 ( V_27 -> V_265 - 1 ) ;
V_27 -> V_37 [ V_59 + 1 ] = V_27 -> V_37 [ V_303 + 1 ] ;
}
return 0 ;
}
static void F_177 ( struct V_26 * V_27 )
{
int V_59 ;
for ( V_59 = V_27 -> V_265 - 1 ; V_59 >= 0 ; V_59 -- )
F_97 ( V_27 , V_59 ) ;
}
static int F_178 ( struct V_26 * V_27 )
{
int V_304 , V_305 , V_59 ;
struct V_101 * V_102 , * V_306 ;
struct V_7 * V_307 ;
struct V_8 * V_308 ;
void * V_309 ;
T_5 V_84 ;
V_304 = F_165 ( V_27 ) ;
if ( V_304 )
return V_304 ;
V_309 = F_102 ( & V_27 -> V_33 -> V_27 , 8192 , & V_84 ,
V_190 ) ;
V_304 = F_87 ( V_27 , 0 , 1 , V_84 ) ;
if ( V_304 ) {
V_304 = - V_76 ;
goto V_310;
}
V_307 = V_309 ;
V_305 = F_77 ( & V_307 -> V_305 ) ;
memcpy ( V_27 -> V_311 , V_307 -> V_312 , sizeof( V_307 -> V_312 ) ) ;
memcpy ( V_27 -> V_313 , V_307 -> V_314 , sizeof( V_307 -> V_314 ) ) ;
memcpy ( V_27 -> V_315 , V_307 -> V_316 , sizeof( V_307 -> V_316 ) ) ;
if ( V_307 -> V_317 ) {
int V_318 = F_179 ( F_114 ( & V_27 -> V_204 -> V_202 ) ) + 12 ;
V_27 -> V_285 = 1 << ( V_307 -> V_317 + V_318 - 9 ) ;
}
V_308 = V_309 ;
for ( V_59 = 1 ; V_59 <= V_305 ; V_59 ++ ) {
V_304 = F_87 ( V_27 , V_59 , 0 , V_84 ) ;
if ( V_304 )
continue;
if ( V_308 -> V_319 == 0 )
continue;
V_304 = F_88 ( V_27 , V_320 , V_59 ,
V_84 + 4096 ) ;
if ( V_304 )
continue;
V_102 = F_151 ( V_27 , V_59 , V_309 , V_309 + 4096 ) ;
if ( V_102 )
F_180 ( & V_102 -> V_60 , & V_27 -> V_321 ) ;
}
F_143 (ns, &dev->namespaces, list)
F_181 ( V_102 -> V_272 ) ;
goto V_322;
V_310:
F_182 (ns, next, &dev->namespaces, list) {
F_183 ( & V_102 -> V_60 ) ;
F_161 ( V_102 ) ;
}
V_322:
F_94 ( & V_27 -> V_33 -> V_27 , 8192 , V_309 , V_84 ) ;
return V_304 ;
}
static int F_184 ( struct V_26 * V_27 )
{
struct V_101 * V_102 , * V_306 ;
F_72 ( & V_264 ) ;
F_183 ( & V_27 -> V_323 ) ;
F_73 ( & V_264 ) ;
F_182 (ns, next, &dev->namespaces, list) {
F_183 ( & V_102 -> V_60 ) ;
F_185 ( V_102 -> V_272 ) ;
F_161 ( V_102 ) ;
}
F_177 ( V_27 ) ;
return 0 ;
}
static int F_186 ( struct V_26 * V_27 )
{
struct V_88 * V_188 = & V_27 -> V_33 -> V_27 ;
V_27 -> V_66 = F_187 ( L_10 , V_188 ,
V_50 , V_50 , 0 ) ;
if ( ! V_27 -> V_66 )
return - V_100 ;
V_27 -> V_63 = F_187 ( L_11 , V_188 ,
256 , 256 , 0 ) ;
if ( ! V_27 -> V_63 ) {
F_188 ( V_27 -> V_66 ) ;
return - V_100 ;
}
return 0 ;
}
static void F_189 ( struct V_26 * V_27 )
{
F_188 ( V_27 -> V_66 ) ;
F_188 ( V_27 -> V_63 ) ;
}
static int F_190 ( struct V_26 * V_27 )
{
int V_294 , error ;
do {
if ( ! F_147 ( & V_324 , V_190 ) )
return - V_220 ;
F_72 ( & V_264 ) ;
error = F_148 ( & V_324 , & V_294 ) ;
F_73 ( & V_264 ) ;
} while ( error == - V_269 );
if ( error )
return - V_220 ;
V_27 -> V_294 = V_294 ;
return 0 ;
}
static void F_191 ( struct V_26 * V_27 )
{
F_72 ( & V_264 ) ;
F_150 ( & V_324 , V_27 -> V_294 ) ;
F_73 ( & V_264 ) ;
}
static int F_192 ( struct V_33 * V_325 , const struct V_326 * V_154 )
{
int V_327 , V_110 = - V_100 ;
struct V_26 * V_27 ;
V_27 = F_101 ( sizeof( * V_27 ) , V_190 ) ;
if ( ! V_27 )
return - V_100 ;
V_27 -> V_187 = F_122 ( F_175 () , sizeof( * V_27 -> V_187 ) ,
V_190 ) ;
if ( ! V_27 -> V_187 )
goto free;
V_27 -> V_37 = F_122 ( F_175 () + 1 , sizeof( void * ) ,
V_190 ) ;
if ( ! V_27 -> V_37 )
goto free;
if ( F_193 ( V_325 ) )
goto free;
F_194 ( V_325 ) ;
V_327 = F_195 ( V_325 , V_328 ) ;
if ( F_196 ( V_325 , V_327 , L_5 ) )
goto V_329;
F_197 ( & V_27 -> V_321 ) ;
V_27 -> V_33 = V_325 ;
F_198 ( V_325 , V_27 ) ;
F_199 ( & V_325 -> V_27 , F_200 ( 64 ) ) ;
F_201 ( & V_325 -> V_27 , F_200 ( 64 ) ) ;
V_110 = F_190 ( V_27 ) ;
if ( V_110 )
goto V_329;
V_27 -> V_187 [ 0 ] . V_186 = V_325 -> V_145 ;
V_110 = F_186 ( V_27 ) ;
if ( V_110 )
goto V_330;
V_27 -> V_204 = F_168 ( F_169 ( V_325 , 0 ) , 8192 ) ;
if ( ! V_27 -> V_204 ) {
V_110 = - V_100 ;
goto V_330;
}
V_110 = F_112 ( V_27 ) ;
if ( V_110 )
goto V_331;
V_27 -> V_265 ++ ;
F_72 ( & V_264 ) ;
F_202 ( & V_27 -> V_323 , & V_332 ) ;
F_73 ( & V_264 ) ;
V_110 = F_178 ( V_27 ) ;
if ( V_110 )
goto V_333;
return 0 ;
V_333:
F_72 ( & V_264 ) ;
F_183 ( & V_27 -> V_323 ) ;
F_73 ( & V_264 ) ;
F_177 ( V_27 ) ;
V_331:
F_167 ( V_27 -> V_204 ) ;
V_330:
F_203 ( V_325 ) ;
F_191 ( V_27 ) ;
F_189 ( V_27 ) ;
V_329:
F_204 ( V_325 ) ;
F_205 ( V_325 ) ;
free:
F_33 ( V_27 -> V_37 ) ;
F_33 ( V_27 -> V_187 ) ;
F_33 ( V_27 ) ;
return V_110 ;
}
static void F_206 ( struct V_33 * V_325 )
{
struct V_26 * V_27 = F_207 ( V_325 ) ;
F_184 ( V_27 ) ;
F_203 ( V_325 ) ;
F_167 ( V_27 -> V_204 ) ;
F_191 ( V_27 ) ;
F_189 ( V_27 ) ;
F_204 ( V_325 ) ;
F_205 ( V_325 ) ;
F_33 ( V_27 -> V_37 ) ;
F_33 ( V_27 -> V_187 ) ;
F_33 ( V_27 ) ;
}
static int T_12 F_208 ( void )
{
int V_110 ;
V_70 = F_209 ( F_140 , NULL , L_5 ) ;
if ( F_130 ( V_70 ) )
return F_131 ( V_70 ) ;
V_110 = F_210 ( V_287 , L_5 ) ;
if ( V_110 < 0 )
goto V_334;
else if ( V_110 > 0 )
V_287 = V_110 ;
V_110 = F_211 ( & V_335 ) ;
if ( V_110 )
goto V_336;
return 0 ;
V_336:
V_336 ( V_287 , L_5 ) ;
V_334:
F_212 ( V_70 ) ;
return V_110 ;
}
static void T_13 F_213 ( void )
{
F_214 ( & V_335 ) ;
V_336 ( V_287 , L_5 ) ;
F_212 ( V_70 ) ;
}
