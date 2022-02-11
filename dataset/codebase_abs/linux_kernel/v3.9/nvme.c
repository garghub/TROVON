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
F_2 ( sizeof( struct V_10 ) != 512 ) ;
}
static struct V_11 * V_11 ( struct V_12 * V_13 )
{
return ( void * ) & V_13 -> V_14 [ F_3 ( V_13 -> V_15 ) ] ;
}
static int F_4 ( struct V_12 * V_13 , void * V_16 ,
T_1 V_17 , unsigned V_18 )
{
int V_19 = V_13 -> V_15 - 1 ;
struct V_11 * V_20 = V_11 ( V_13 ) ;
int V_21 ;
do {
V_21 = F_5 ( V_13 -> V_14 , V_19 ) ;
if ( V_21 >= V_19 )
return - V_22 ;
} while ( F_6 ( V_21 , V_13 -> V_14 ) );
V_20 [ V_21 ] . V_23 = V_17 ;
V_20 [ V_21 ] . V_16 = V_16 ;
V_20 [ V_21 ] . V_18 = V_24 + V_18 ;
return V_21 ;
}
static int F_7 ( struct V_12 * V_13 , void * V_16 ,
T_1 V_17 , unsigned V_18 )
{
int V_21 ;
F_8 ( V_13 -> V_25 ,
( V_21 = F_4 ( V_13 , V_16 , V_17 , V_18 ) ) >= 0 ) ;
return ( V_21 < 0 ) ? - V_26 : V_21 ;
}
static void F_9 ( struct V_27 * V_28 , void * V_16 ,
struct V_29 * V_30 )
{
if ( V_16 == V_31 )
return;
if ( V_16 == V_32 )
return;
if ( V_16 == V_33 ) {
F_10 ( & V_28 -> V_34 -> V_28 ,
L_1 ,
V_30 -> V_35 , F_11 ( & V_30 -> V_36 ) ) ;
return;
}
if ( V_16 == V_37 ) {
F_10 ( & V_28 -> V_34 -> V_28 ,
L_2 ,
V_30 -> V_35 , F_11 ( & V_30 -> V_36 ) ) ;
return;
}
F_10 ( & V_28 -> V_34 -> V_28 , L_3 , V_16 ) ;
}
static void * F_12 ( struct V_12 * V_13 , int V_21 ,
T_1 * V_23 )
{
void * V_16 ;
struct V_11 * V_20 = V_11 ( V_13 ) ;
if ( V_21 >= V_13 -> V_15 ) {
* V_23 = F_9 ;
return V_37 ;
}
if ( V_23 )
* V_23 = V_20 [ V_21 ] . V_23 ;
V_16 = V_20 [ V_21 ] . V_16 ;
V_20 [ V_21 ] . V_23 = F_9 ;
V_20 [ V_21 ] . V_16 = V_33 ;
F_13 ( V_21 , V_13 -> V_14 ) ;
F_14 ( & V_13 -> V_25 ) ;
return V_16 ;
}
static void * F_15 ( struct V_12 * V_13 , int V_21 ,
T_1 * V_23 )
{
void * V_16 ;
struct V_11 * V_20 = V_11 ( V_13 ) ;
if ( V_23 )
* V_23 = V_20 [ V_21 ] . V_23 ;
V_16 = V_20 [ V_21 ] . V_16 ;
V_20 [ V_21 ] . V_23 = F_9 ;
V_20 [ V_21 ] . V_16 = V_31 ;
return V_16 ;
}
static struct V_12 * F_16 ( struct V_27 * V_28 )
{
return V_28 -> V_38 [ F_17 () + 1 ] ;
}
static void F_18 ( struct V_12 * V_13 )
{
F_19 () ;
}
static int F_20 ( struct V_12 * V_13 , struct V_6 * V_39 )
{
unsigned long V_40 ;
T_2 V_41 ;
F_21 ( & V_13 -> V_42 , V_40 ) ;
V_41 = V_13 -> V_43 ;
memcpy ( & V_13 -> V_44 [ V_41 ] , V_39 , sizeof( * V_39 ) ) ;
if ( ++ V_41 == V_13 -> V_15 )
V_41 = 0 ;
F_22 ( V_41 , V_13 -> V_45 ) ;
V_13 -> V_43 = V_41 ;
F_23 ( & V_13 -> V_42 , V_40 ) ;
return 0 ;
}
static T_3 * * F_24 ( struct V_46 * V_47 )
{
return ( ( void * ) V_47 ) + V_47 -> V_48 ;
}
static int F_25 ( unsigned V_49 )
{
unsigned V_50 = F_26 ( V_49 + V_51 , V_51 ) ;
return F_26 ( 8 * V_50 , V_51 - 8 ) ;
}
static struct V_46 *
F_27 ( unsigned V_52 , unsigned V_53 , T_4 V_54 )
{
struct V_46 * V_47 = F_28 ( sizeof( struct V_46 ) +
sizeof( T_3 * ) * F_25 ( V_53 ) +
sizeof( struct V_55 ) * V_52 , V_54 ) ;
if ( V_47 ) {
V_47 -> V_48 = F_29 ( struct V_46 , V_56 [ V_52 ] ) ;
V_47 -> V_57 = - 1 ;
V_47 -> V_58 = V_53 ;
V_47 -> V_59 = 0 ;
}
return V_47 ;
}
static void F_30 ( struct V_27 * V_28 , struct V_46 * V_47 )
{
const int V_60 = V_51 / 8 - 1 ;
int V_61 ;
T_3 * * V_62 = F_24 ( V_47 ) ;
T_5 V_63 = V_47 -> V_64 ;
if ( V_47 -> V_57 == 0 )
F_31 ( V_28 -> V_65 , V_62 [ 0 ] , V_63 ) ;
for ( V_61 = 0 ; V_61 < V_47 -> V_57 ; V_61 ++ ) {
T_3 * V_66 = V_62 [ V_61 ] ;
T_5 V_67 = F_32 ( V_66 [ V_60 ] ) ;
F_31 ( V_28 -> V_68 , V_66 , V_63 ) ;
V_63 = V_67 ;
}
F_33 ( V_47 ) ;
}
static void F_34 ( struct V_27 * V_28 , struct V_69 * V_69 )
{
struct V_12 * V_13 = F_16 ( V_28 ) ;
if ( F_35 ( & V_13 -> V_70 ) )
F_36 ( & V_13 -> V_25 , & V_13 -> V_71 ) ;
F_37 ( & V_13 -> V_70 , V_69 ) ;
F_18 ( V_13 ) ;
F_38 ( V_72 ) ;
}
static void F_39 ( struct V_27 * V_28 , void * V_16 ,
struct V_29 * V_30 )
{
struct V_46 * V_47 = V_16 ;
struct V_69 * V_69 = V_47 -> V_73 ;
T_2 V_74 = F_11 ( & V_30 -> V_74 ) >> 1 ;
if ( V_47 -> V_59 )
F_40 ( & V_28 -> V_34 -> V_28 , V_47 -> V_56 , V_47 -> V_59 ,
F_41 ( V_69 ) ? V_75 : V_76 ) ;
F_30 ( V_28 , V_47 ) ;
if ( V_74 ) {
F_42 ( V_69 , - V_77 ) ;
} else if ( V_69 -> V_78 > V_69 -> V_79 ) {
F_34 ( V_28 , V_69 ) ;
} else {
F_42 ( V_69 , 0 ) ;
}
}
static int F_43 ( struct V_27 * V_28 ,
struct V_80 * V_39 , struct V_46 * V_47 ,
int V_81 , T_4 V_54 )
{
struct V_82 * V_83 ;
int V_58 = V_81 ;
struct V_55 * V_56 = V_47 -> V_56 ;
int V_84 = F_44 ( V_56 ) ;
T_6 V_85 = F_45 ( V_56 ) ;
int V_48 = F_46 ( V_85 ) ;
T_3 * V_66 ;
T_3 * * V_62 = F_24 ( V_47 ) ;
T_5 V_63 ;
int V_50 , V_61 ;
V_39 -> V_86 = F_47 ( V_85 ) ;
V_58 -= ( V_51 - V_48 ) ;
if ( V_58 <= 0 )
return V_81 ;
V_84 -= ( V_51 - V_48 ) ;
if ( V_84 ) {
V_85 += ( V_51 - V_48 ) ;
} else {
V_56 = F_48 ( V_56 ) ;
V_85 = F_45 ( V_56 ) ;
V_84 = F_44 ( V_56 ) ;
}
if ( V_58 <= V_51 ) {
V_39 -> V_87 = F_47 ( V_85 ) ;
return V_81 ;
}
V_50 = F_26 ( V_58 , V_51 ) ;
if ( V_50 <= ( 256 / 8 ) ) {
V_83 = V_28 -> V_65 ;
V_47 -> V_57 = 0 ;
} else {
V_83 = V_28 -> V_68 ;
V_47 -> V_57 = 1 ;
}
V_66 = F_49 ( V_83 , V_54 , & V_63 ) ;
if ( ! V_66 ) {
V_39 -> V_87 = F_47 ( V_85 ) ;
V_47 -> V_57 = - 1 ;
return ( V_81 - V_58 ) + V_51 ;
}
V_62 [ 0 ] = V_66 ;
V_47 -> V_64 = V_63 ;
V_39 -> V_87 = F_47 ( V_63 ) ;
V_61 = 0 ;
for (; ; ) {
if ( V_61 == V_51 / 8 ) {
T_3 * V_88 = V_66 ;
V_66 = F_49 ( V_83 , V_54 , & V_63 ) ;
if ( ! V_66 )
return V_81 - V_58 ;
V_62 [ V_47 -> V_57 ++ ] = V_66 ;
V_66 [ 0 ] = V_88 [ V_61 - 1 ] ;
V_88 [ V_61 - 1 ] = F_47 ( V_63 ) ;
V_61 = 1 ;
}
V_66 [ V_61 ++ ] = F_47 ( V_85 ) ;
V_84 -= V_51 ;
V_85 += V_51 ;
V_58 -= V_51 ;
if ( V_58 <= 0 )
break;
if ( V_84 > 0 )
continue;
F_50 ( V_84 < 0 ) ;
V_56 = F_48 ( V_56 ) ;
V_85 = F_45 ( V_56 ) ;
V_84 = F_44 ( V_56 ) ;
}
return V_81 ;
}
static int F_51 ( struct V_89 * V_28 , struct V_46 * V_47 ,
struct V_69 * V_69 , enum V_90 V_91 , int V_92 )
{
struct V_93 * V_94 , * V_95 = NULL ;
struct V_55 * V_56 = NULL ;
int V_61 , V_96 , V_58 = 0 , V_97 = 0 ;
F_52 ( V_47 -> V_56 , V_92 ) ;
V_96 = V_69 -> V_79 ;
F_53 (bvec, bio, i) {
if ( V_95 && F_54 ( V_95 , V_94 ) ) {
V_56 -> V_58 += V_94 -> V_98 ;
} else {
if ( V_95 && F_55 ( V_95 , V_94 ) )
break;
V_56 = V_56 ? V_56 + 1 : V_47 -> V_56 ;
F_56 ( V_56 , V_94 -> V_99 , V_94 -> V_98 ,
V_94 -> V_100 ) ;
V_97 ++ ;
}
V_58 += V_94 -> V_98 ;
V_95 = V_94 ;
}
V_69 -> V_79 = V_61 ;
V_47 -> V_59 = V_97 ;
F_57 ( V_56 ) ;
if ( F_58 ( V_28 , V_47 -> V_56 , V_47 -> V_59 , V_91 ) == 0 ) {
V_69 -> V_79 = V_96 ;
return - V_101 ;
}
return V_58 ;
}
static int F_59 ( struct V_12 * V_13 , struct V_102 * V_103 ,
int V_21 )
{
struct V_6 * V_104 = & V_13 -> V_44 [ V_13 -> V_43 ] ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
V_104 -> V_105 . V_106 = V_107 ;
V_104 -> V_105 . V_35 = V_21 ;
V_104 -> V_105 . V_108 = F_60 ( V_103 -> V_109 ) ;
if ( ++ V_13 -> V_43 == V_13 -> V_15 )
V_13 -> V_43 = 0 ;
F_22 ( V_13 -> V_43 , V_13 -> V_45 ) ;
return 0 ;
}
static int F_61 ( struct V_12 * V_13 , struct V_102 * V_103 )
{
int V_21 = F_4 ( V_13 , ( void * ) V_32 ,
F_9 , V_110 ) ;
if ( F_62 ( V_21 < 0 ) )
return V_21 ;
return F_59 ( V_13 , V_103 , V_21 ) ;
}
static int F_63 ( struct V_12 * V_13 , struct V_102 * V_103 ,
struct V_69 * V_69 )
{
struct V_6 * V_104 ;
struct V_46 * V_47 ;
enum V_90 V_91 ;
int V_21 , V_58 , V_111 = - V_101 ;
T_2 V_112 ;
T_7 V_113 ;
int V_92 = F_64 ( V_103 -> V_114 , V_69 ) ;
if ( ( V_69 -> V_115 & V_116 ) && V_92 ) {
V_111 = F_61 ( V_13 , V_103 ) ;
if ( V_111 )
return V_111 ;
}
V_47 = F_27 ( V_92 , V_69 -> V_117 , V_118 ) ;
if ( ! V_47 )
goto V_119;
V_47 -> V_73 = V_69 ;
V_111 = - V_22 ;
V_21 = F_4 ( V_13 , V_47 , F_39 , V_110 ) ;
if ( F_62 ( V_21 < 0 ) )
goto V_120;
if ( ( V_69 -> V_115 & V_116 ) && ! V_92 )
return F_59 ( V_13 , V_103 , V_21 ) ;
V_112 = 0 ;
if ( V_69 -> V_115 & V_121 )
V_112 |= V_122 ;
if ( V_69 -> V_115 & ( V_123 | V_124 ) )
V_112 |= V_125 ;
V_113 = 0 ;
if ( V_69 -> V_115 & V_124 )
V_113 |= V_126 ;
V_104 = & V_13 -> V_44 [ V_13 -> V_43 ] ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
if ( F_41 ( V_69 ) ) {
V_104 -> V_127 . V_106 = V_128 ;
V_91 = V_75 ;
} else {
V_104 -> V_127 . V_106 = V_129 ;
V_91 = V_76 ;
}
V_111 = F_51 ( V_13 -> V_130 , V_47 , V_69 , V_91 , V_92 ) ;
if ( V_111 < 0 )
goto F_12;
V_58 = V_111 ;
V_104 -> V_127 . V_35 = V_21 ;
V_104 -> V_127 . V_108 = F_60 ( V_103 -> V_109 ) ;
V_58 = F_43 ( V_13 -> V_28 , & V_104 -> V_105 , V_47 , V_58 ,
V_118 ) ;
V_104 -> V_127 . V_131 = F_47 ( V_69 -> V_132 >> ( V_103 -> V_133 - 9 ) ) ;
V_104 -> V_127 . V_58 = F_65 ( ( V_58 >> V_103 -> V_133 ) - 1 ) ;
V_104 -> V_127 . V_112 = F_65 ( V_112 ) ;
V_104 -> V_127 . V_113 = F_60 ( V_113 ) ;
V_69 -> V_132 += V_58 >> 9 ;
if ( ++ V_13 -> V_43 == V_13 -> V_15 )
V_13 -> V_43 = 0 ;
F_22 ( V_13 -> V_43 , V_13 -> V_45 ) ;
return 0 ;
F_12:
F_12 ( V_13 , V_21 , NULL ) ;
V_120:
F_30 ( V_13 -> V_28 , V_47 ) ;
V_119:
return V_111 ;
}
static void F_66 ( struct V_134 * V_135 , struct V_69 * V_69 )
{
struct V_102 * V_103 = V_135 -> V_136 ;
struct V_12 * V_13 = F_16 ( V_103 -> V_28 ) ;
int V_111 = - V_22 ;
F_67 ( & V_13 -> V_42 ) ;
if ( F_35 ( & V_13 -> V_70 ) )
V_111 = F_63 ( V_13 , V_103 , V_69 ) ;
if ( F_62 ( V_111 ) ) {
if ( F_35 ( & V_13 -> V_70 ) )
F_36 ( & V_13 -> V_25 , & V_13 -> V_71 ) ;
F_37 ( & V_13 -> V_70 , V_69 ) ;
}
F_68 ( & V_13 -> V_42 ) ;
F_18 ( V_13 ) ;
}
static T_8 F_69 ( struct V_12 * V_13 )
{
T_2 V_137 , V_138 ;
V_137 = V_13 -> V_139 ;
V_138 = V_13 -> V_140 ;
for (; ; ) {
void * V_16 ;
T_1 V_23 ;
struct V_29 V_30 = V_13 -> V_141 [ V_137 ] ;
if ( ( F_70 ( V_30 . V_74 ) & 1 ) != V_138 )
break;
V_13 -> V_142 = F_70 ( V_30 . V_142 ) ;
if ( ++ V_137 == V_13 -> V_15 ) {
V_137 = 0 ;
V_138 = ! V_138 ;
}
V_16 = F_12 ( V_13 , V_30 . V_35 , & V_23 ) ;
V_23 ( V_13 -> V_28 , V_16 , & V_30 ) ;
}
if ( V_137 == V_13 -> V_139 && V_138 == V_13 -> V_140 )
return V_143 ;
F_22 ( V_137 , V_13 -> V_45 + ( 1 << V_13 -> V_28 -> V_144 ) ) ;
V_13 -> V_139 = V_137 ;
V_13 -> V_140 = V_138 ;
return V_145 ;
}
static T_8 F_71 ( int V_146 , void * V_147 )
{
T_8 V_111 ;
struct V_12 * V_13 = V_147 ;
F_72 ( & V_13 -> V_42 ) ;
V_111 = F_69 ( V_13 ) ;
F_73 ( & V_13 -> V_42 ) ;
return V_111 ;
}
static T_8 F_74 ( int V_146 , void * V_147 )
{
struct V_12 * V_13 = V_147 ;
struct V_29 V_30 = V_13 -> V_141 [ V_13 -> V_139 ] ;
if ( ( F_70 ( V_30 . V_74 ) & 1 ) != V_13 -> V_140 )
return V_143 ;
return V_148 ;
}
static void F_75 ( struct V_12 * V_13 , int V_21 )
{
F_67 ( & V_13 -> V_42 ) ;
F_15 ( V_13 , V_21 , NULL ) ;
F_68 ( & V_13 -> V_42 ) ;
}
static void F_76 ( struct V_27 * V_28 , void * V_16 ,
struct V_29 * V_30 )
{
struct V_149 * V_150 = V_16 ;
V_150 -> V_111 = F_77 ( & V_30 -> V_111 ) ;
V_150 -> V_74 = F_11 ( & V_30 -> V_74 ) >> 1 ;
F_38 ( V_150 -> V_151 ) ;
}
static int F_78 ( struct V_12 * V_13 ,
struct V_6 * V_39 , T_7 * V_111 , unsigned V_18 )
{
int V_21 ;
struct V_149 V_150 ;
V_150 . V_151 = V_152 ;
V_150 . V_74 = - V_26 ;
V_21 = F_7 ( V_13 , & V_150 , F_76 ,
V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
V_39 -> V_105 . V_35 = V_21 ;
F_79 ( V_153 ) ;
F_20 ( V_13 , V_39 ) ;
F_80 () ;
if ( V_150 . V_74 == - V_26 ) {
F_75 ( V_13 , V_21 ) ;
return - V_26 ;
}
if ( V_111 )
* V_111 = V_150 . V_111 ;
return V_150 . V_74 ;
}
static int F_81 ( struct V_27 * V_28 , struct V_6 * V_39 ,
T_7 * V_111 )
{
return F_78 ( V_28 -> V_38 [ 0 ] , V_39 , V_111 , V_154 ) ;
}
static int F_82 ( struct V_27 * V_28 , T_9 V_106 , T_2 V_155 )
{
int V_74 ;
struct V_6 V_156 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_157 . V_106 = V_106 ;
V_156 . V_157 . V_158 = F_65 ( V_155 ) ;
V_74 = F_81 ( V_28 , & V_156 , NULL ) ;
if ( V_74 )
return - V_77 ;
return 0 ;
}
static int F_83 ( struct V_27 * V_28 , T_2 V_158 ,
struct V_12 * V_13 )
{
int V_74 ;
struct V_6 V_156 ;
int V_40 = V_159 | V_160 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_161 . V_106 = V_162 ;
V_156 . V_161 . V_86 = F_47 ( V_13 -> V_163 ) ;
V_156 . V_161 . V_164 = F_65 ( V_158 ) ;
V_156 . V_161 . V_165 = F_65 ( V_13 -> V_15 - 1 ) ;
V_156 . V_161 . V_166 = F_65 ( V_40 ) ;
V_156 . V_161 . V_167 = F_65 ( V_13 -> V_168 ) ;
V_74 = F_81 ( V_28 , & V_156 , NULL ) ;
if ( V_74 )
return - V_77 ;
return 0 ;
}
static int F_84 ( struct V_27 * V_28 , T_2 V_158 ,
struct V_12 * V_13 )
{
int V_74 ;
struct V_6 V_156 ;
int V_40 = V_159 | V_169 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_170 . V_106 = V_171 ;
V_156 . V_170 . V_86 = F_47 ( V_13 -> V_172 ) ;
V_156 . V_170 . V_173 = F_65 ( V_158 ) ;
V_156 . V_170 . V_165 = F_65 ( V_13 -> V_15 - 1 ) ;
V_156 . V_170 . V_174 = F_65 ( V_40 ) ;
V_156 . V_170 . V_164 = F_65 ( V_158 ) ;
V_74 = F_81 ( V_28 , & V_156 , NULL ) ;
if ( V_74 )
return - V_77 ;
return 0 ;
}
static int F_85 ( struct V_27 * V_28 , T_2 V_164 )
{
return F_82 ( V_28 , V_175 , V_164 ) ;
}
static int F_86 ( struct V_27 * V_28 , T_2 V_173 )
{
return F_82 ( V_28 , V_176 , V_173 ) ;
}
static int F_87 ( struct V_27 * V_28 , unsigned V_108 , unsigned V_177 ,
T_5 V_85 )
{
struct V_6 V_156 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_178 . V_106 = V_179 ;
V_156 . V_178 . V_108 = F_60 ( V_108 ) ;
V_156 . V_178 . V_86 = F_47 ( V_85 ) ;
V_156 . V_178 . V_177 = F_60 ( V_177 ) ;
return F_81 ( V_28 , & V_156 , NULL ) ;
}
static int F_88 ( struct V_27 * V_28 , unsigned V_180 , unsigned V_108 ,
T_5 V_85 , T_7 * V_111 )
{
struct V_6 V_156 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_181 . V_106 = V_182 ;
V_156 . V_181 . V_108 = F_60 ( V_108 ) ;
V_156 . V_181 . V_86 = F_47 ( V_85 ) ;
V_156 . V_181 . V_180 = F_60 ( V_180 ) ;
return F_81 ( V_28 , & V_156 , V_111 ) ;
}
static int F_89 ( struct V_27 * V_28 , unsigned V_180 ,
unsigned V_183 , T_5 V_85 , T_7 * V_111 )
{
struct V_6 V_156 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_181 . V_106 = V_184 ;
V_156 . V_181 . V_86 = F_47 ( V_85 ) ;
V_156 . V_181 . V_180 = F_60 ( V_180 ) ;
V_156 . V_181 . V_183 = F_60 ( V_183 ) ;
return F_81 ( V_28 , & V_156 , V_111 ) ;
}
static void F_90 ( struct V_12 * V_13 , bool V_18 )
{
int V_19 = V_13 -> V_15 - 1 ;
struct V_11 * V_20 = V_11 ( V_13 ) ;
unsigned long V_185 = V_24 ;
int V_21 ;
F_91 (cmdid, nvmeq->cmdid_data, depth) {
void * V_16 ;
T_1 V_23 ;
static struct V_29 V_30 = {
. V_74 = F_65 ( V_186 ) << 1 ,
} ;
if ( V_18 && ! F_92 ( V_185 , V_20 [ V_21 ] . V_18 ) )
continue;
F_10 ( V_13 -> V_130 , L_4 , V_21 ) ;
V_16 = F_15 ( V_13 , V_21 , & V_23 ) ;
V_23 ( V_13 -> V_28 , V_16 , & V_30 ) ;
}
}
static void F_93 ( struct V_12 * V_13 )
{
F_94 ( V_13 -> V_130 , F_95 ( V_13 -> V_15 ) ,
( void * ) V_13 -> V_141 , V_13 -> V_163 ) ;
F_94 ( V_13 -> V_130 , F_96 ( V_13 -> V_15 ) ,
V_13 -> V_44 , V_13 -> V_172 ) ;
F_33 ( V_13 ) ;
}
static void F_97 ( struct V_27 * V_28 , int V_158 )
{
struct V_12 * V_13 = V_28 -> V_38 [ V_158 ] ;
int V_187 = V_28 -> V_188 [ V_13 -> V_168 ] . V_187 ;
F_67 ( & V_13 -> V_42 ) ;
F_90 ( V_13 , false ) ;
while ( F_98 ( & V_13 -> V_70 ) ) {
struct V_69 * V_69 = F_99 ( & V_13 -> V_70 ) ;
F_42 ( V_69 , - V_77 ) ;
}
F_68 ( & V_13 -> V_42 ) ;
F_100 ( V_187 , NULL ) ;
F_101 ( V_187 , V_13 ) ;
if ( V_158 ) {
F_86 ( V_28 , V_158 ) ;
F_85 ( V_28 , V_158 ) ;
}
F_93 ( V_13 ) ;
}
static struct V_12 * F_102 ( struct V_27 * V_28 , int V_158 ,
int V_19 , int V_187 )
{
struct V_89 * V_189 = & V_28 -> V_34 -> V_28 ;
unsigned V_190 = F_26 ( V_19 , 8 ) + ( V_19 *
sizeof( struct V_11 ) ) ;
struct V_12 * V_13 = F_103 ( sizeof( * V_13 ) + V_190 , V_191 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_141 = F_104 ( V_189 , F_95 ( V_19 ) ,
& V_13 -> V_163 , V_191 ) ;
if ( ! V_13 -> V_141 )
goto V_192;
memset ( ( void * ) V_13 -> V_141 , 0 , F_95 ( V_19 ) ) ;
V_13 -> V_44 = F_104 ( V_189 , F_96 ( V_19 ) ,
& V_13 -> V_172 , V_191 ) ;
if ( ! V_13 -> V_44 )
goto V_193;
V_13 -> V_130 = V_189 ;
V_13 -> V_28 = V_28 ;
F_105 ( & V_13 -> V_42 ) ;
V_13 -> V_139 = 0 ;
V_13 -> V_140 = 1 ;
F_106 ( & V_13 -> V_25 ) ;
F_107 ( & V_13 -> V_71 , V_72 ) ;
F_108 ( & V_13 -> V_70 ) ;
V_13 -> V_45 = & V_28 -> V_194 [ V_158 << ( V_28 -> V_144 + 1 ) ] ;
V_13 -> V_15 = V_19 ;
V_13 -> V_168 = V_187 ;
return V_13 ;
V_193:
F_94 ( V_189 , F_95 ( V_13 -> V_15 ) , ( void * ) V_13 -> V_141 ,
V_13 -> V_163 ) ;
V_192:
F_33 ( V_13 ) ;
return NULL ;
}
static int F_109 ( struct V_27 * V_28 , struct V_12 * V_13 ,
const char * V_195 )
{
if ( V_196 )
return F_110 ( V_28 -> V_188 [ V_13 -> V_168 ] . V_187 ,
F_74 , F_71 ,
V_197 | V_198 ,
V_195 , V_13 ) ;
return F_111 ( V_28 -> V_188 [ V_13 -> V_168 ] . V_187 , F_71 ,
V_197 | V_198 , V_195 , V_13 ) ;
}
static struct V_12 * F_112 ( struct V_27 * V_28 , int V_158 ,
int V_199 , int V_187 )
{
int V_111 ;
struct V_12 * V_13 = F_102 ( V_28 , V_158 , V_199 , V_187 ) ;
if ( ! V_13 )
return F_113 ( - V_101 ) ;
V_111 = F_83 ( V_28 , V_158 , V_13 ) ;
if ( V_111 < 0 )
goto V_192;
V_111 = F_84 ( V_28 , V_158 , V_13 ) ;
if ( V_111 < 0 )
goto V_200;
V_111 = F_109 ( V_28 , V_13 , L_5 ) ;
if ( V_111 < 0 )
goto V_201;
return V_13 ;
V_201:
F_86 ( V_28 , V_158 ) ;
V_200:
F_85 ( V_28 , V_158 ) ;
V_192:
F_94 ( V_13 -> V_130 , F_95 ( V_13 -> V_15 ) ,
( void * ) V_13 -> V_141 , V_13 -> V_163 ) ;
F_94 ( V_13 -> V_130 , F_96 ( V_13 -> V_15 ) ,
V_13 -> V_44 , V_13 -> V_172 ) ;
F_33 ( V_13 ) ;
return F_113 ( V_111 ) ;
}
static int F_114 ( struct V_27 * V_28 )
{
int V_111 = 0 ;
T_7 V_202 ;
T_6 V_203 ;
unsigned long V_18 ;
struct V_12 * V_13 ;
V_28 -> V_194 = ( ( void V_204 * ) V_28 -> V_205 ) + 4096 ;
V_13 = F_102 ( V_28 , 0 , 64 , 0 ) ;
if ( ! V_13 )
return - V_101 ;
V_202 = V_13 -> V_15 - 1 ;
V_202 |= V_202 << 16 ;
V_28 -> V_206 = V_207 | V_208 ;
V_28 -> V_206 |= ( V_209 - 12 ) << V_210 ;
V_28 -> V_206 |= V_211 | V_212 ;
V_28 -> V_206 |= V_213 | V_214 ;
F_22 ( 0 , & V_28 -> V_205 -> V_215 ) ;
F_22 ( V_202 , & V_28 -> V_205 -> V_202 ) ;
F_115 ( V_13 -> V_172 , & V_28 -> V_205 -> V_216 ) ;
F_115 ( V_13 -> V_163 , & V_28 -> V_205 -> V_217 ) ;
F_22 ( V_28 -> V_206 , & V_28 -> V_205 -> V_215 ) ;
V_203 = F_116 ( & V_28 -> V_205 -> V_203 ) ;
V_18 = ( ( F_117 ( V_203 ) + 1 ) * V_218 / 2 ) + V_24 ;
V_28 -> V_144 = F_118 ( V_203 ) ;
while ( ! V_111 && ! ( F_119 ( & V_28 -> V_205 -> V_219 ) & V_220 ) ) {
F_120 ( 100 ) ;
if ( F_121 ( V_152 ) )
V_111 = - V_26 ;
if ( F_92 ( V_24 , V_18 ) ) {
F_122 ( & V_28 -> V_34 -> V_28 ,
L_6 ) ;
V_111 = - V_221 ;
}
}
if ( V_111 ) {
F_93 ( V_13 ) ;
return V_111 ;
}
V_111 = F_109 ( V_28 , V_13 , L_7 ) ;
V_28 -> V_38 [ 0 ] = V_13 ;
return V_111 ;
}
static struct V_46 * F_123 ( struct V_27 * V_28 , int V_222 ,
unsigned long V_223 , unsigned V_58 )
{
int V_61 , V_224 , V_225 , V_59 , V_48 ;
struct V_55 * V_56 ;
struct V_226 * * V_227 ;
struct V_46 * V_47 ;
if ( V_223 & 3 )
return F_113 ( - V_228 ) ;
if ( ! V_58 )
return F_113 ( - V_228 ) ;
V_48 = F_46 ( V_223 ) ;
V_225 = F_26 ( V_48 + V_58 , V_51 ) ;
V_227 = F_124 ( V_225 , sizeof( * V_227 ) , V_191 ) ;
if ( ! V_227 )
return F_113 ( - V_101 ) ;
V_224 = F_125 ( V_223 , V_225 , 1 , V_227 ) ;
if ( V_224 < V_225 ) {
V_225 = V_224 ;
V_224 = - V_229 ;
goto V_230;
}
V_47 = F_27 ( V_225 , V_58 , V_191 ) ;
V_56 = V_47 -> V_56 ;
F_52 ( V_56 , V_225 ) ;
for ( V_61 = 0 ; V_61 < V_225 ; V_61 ++ ) {
F_56 ( & V_56 [ V_61 ] , V_227 [ V_61 ] ,
F_126 ( int , V_58 , V_51 - V_48 ) , V_48 ) ;
V_58 -= ( V_51 - V_48 ) ;
V_48 = 0 ;
}
F_57 ( & V_56 [ V_61 - 1 ] ) ;
V_47 -> V_59 = V_225 ;
V_224 = - V_101 ;
V_59 = F_58 ( & V_28 -> V_34 -> V_28 , V_56 , V_225 ,
V_222 ? V_75 : V_76 ) ;
if ( ! V_59 )
goto V_120;
F_33 ( V_227 ) ;
return V_47 ;
V_120:
F_33 ( V_47 ) ;
V_230:
for ( V_61 = 0 ; V_61 < V_225 ; V_61 ++ )
F_127 ( V_227 [ V_61 ] ) ;
F_33 ( V_227 ) ;
return F_113 ( V_224 ) ;
}
static void F_128 ( struct V_27 * V_28 , int V_222 ,
struct V_46 * V_47 )
{
int V_61 ;
F_40 ( & V_28 -> V_34 -> V_28 , V_47 -> V_56 , V_47 -> V_59 ,
V_222 ? V_75 : V_76 ) ;
for ( V_61 = 0 ; V_61 < V_47 -> V_59 ; V_61 ++ )
F_127 ( F_129 ( & V_47 -> V_56 [ V_61 ] ) ) ;
}
static int F_130 ( struct V_102 * V_103 , struct V_231 T_10 * V_232 )
{
struct V_27 * V_28 = V_103 -> V_28 ;
struct V_12 * V_13 ;
struct V_231 V_233 ;
struct V_6 V_156 ;
unsigned V_58 ;
int V_74 ;
struct V_46 * V_47 ;
if ( F_131 ( & V_233 , V_232 , sizeof( V_233 ) ) )
return - V_229 ;
V_58 = ( V_233 . V_234 + 1 ) << V_103 -> V_133 ;
switch ( V_233 . V_106 ) {
case V_128 :
case V_129 :
case V_235 :
V_47 = F_123 ( V_28 , V_233 . V_106 & 1 , V_233 . V_223 , V_58 ) ;
break;
default:
return - V_228 ;
}
if ( F_132 ( V_47 ) )
return F_133 ( V_47 ) ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_127 . V_106 = V_233 . V_106 ;
V_156 . V_127 . V_40 = V_233 . V_40 ;
V_156 . V_127 . V_108 = F_60 ( V_103 -> V_109 ) ;
V_156 . V_127 . V_131 = F_47 ( V_233 . V_131 ) ;
V_156 . V_127 . V_58 = F_65 ( V_233 . V_234 ) ;
V_156 . V_127 . V_112 = F_65 ( V_233 . V_112 ) ;
V_156 . V_127 . V_113 = F_65 ( V_233 . V_113 ) ;
V_156 . V_127 . V_236 = V_233 . V_236 ;
V_156 . V_127 . V_237 = V_233 . V_237 ;
V_156 . V_127 . V_238 = V_233 . V_238 ;
V_58 = F_43 ( V_28 , & V_156 . V_105 , V_47 , V_58 , V_191 ) ;
V_13 = F_16 ( V_28 ) ;
F_18 ( V_13 ) ;
if ( V_58 != ( V_233 . V_234 + 1 ) << V_103 -> V_133 )
V_74 = - V_101 ;
else
V_74 = F_78 ( V_13 , & V_156 , NULL , V_110 ) ;
F_128 ( V_28 , V_233 . V_106 & 1 , V_47 ) ;
F_30 ( V_28 , V_47 ) ;
return V_74 ;
}
static int F_134 ( struct V_27 * V_28 ,
struct V_239 T_10 * V_240 )
{
struct V_239 V_39 ;
struct V_6 V_156 ;
int V_74 , V_58 ;
struct V_46 * V_241 ( V_47 ) ;
if ( ! F_135 ( V_242 ) )
return - V_243 ;
if ( F_131 ( & V_39 , V_240 , sizeof( V_39 ) ) )
return - V_229 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_105 . V_106 = V_39 . V_106 ;
V_156 . V_105 . V_40 = V_39 . V_40 ;
V_156 . V_105 . V_108 = F_60 ( V_39 . V_108 ) ;
V_156 . V_105 . V_244 [ 0 ] = F_60 ( V_39 . V_244 ) ;
V_156 . V_105 . V_244 [ 1 ] = F_60 ( V_39 . V_245 ) ;
V_156 . V_105 . V_246 [ 0 ] = F_60 ( V_39 . V_246 ) ;
V_156 . V_105 . V_246 [ 1 ] = F_60 ( V_39 . V_247 ) ;
V_156 . V_105 . V_246 [ 2 ] = F_60 ( V_39 . V_248 ) ;
V_156 . V_105 . V_246 [ 3 ] = F_60 ( V_39 . V_249 ) ;
V_156 . V_105 . V_246 [ 4 ] = F_60 ( V_39 . V_250 ) ;
V_156 . V_105 . V_246 [ 5 ] = F_60 ( V_39 . V_251 ) ;
V_58 = V_39 . V_252 ;
if ( V_39 . V_252 ) {
V_47 = F_123 ( V_28 , V_39 . V_106 & 1 , V_39 . V_223 ,
V_58 ) ;
if ( F_132 ( V_47 ) )
return F_133 ( V_47 ) ;
V_58 = F_43 ( V_28 , & V_156 . V_105 , V_47 , V_58 ,
V_191 ) ;
}
if ( V_58 != V_39 . V_252 )
V_74 = - V_101 ;
else
V_74 = F_81 ( V_28 , & V_156 , & V_39 . V_111 ) ;
if ( V_39 . V_252 ) {
F_128 ( V_28 , V_39 . V_106 & 1 , V_47 ) ;
F_30 ( V_28 , V_47 ) ;
}
if ( ! V_74 && F_136 ( & V_240 -> V_111 , & V_39 . V_111 ,
sizeof( V_39 . V_111 ) ) )
V_74 = - V_229 ;
return V_74 ;
}
static int F_137 ( struct V_253 * V_254 , T_11 V_255 , unsigned int V_39 ,
unsigned long V_256 )
{
struct V_102 * V_103 = V_254 -> V_257 -> V_258 ;
switch ( V_39 ) {
case V_259 :
return V_103 -> V_109 ;
case V_260 :
return F_134 ( V_103 -> V_28 , ( void T_10 * ) V_256 ) ;
case V_261 :
return F_130 ( V_103 , ( void T_10 * ) V_256 ) ;
default:
return - V_262 ;
}
}
static void F_138 ( struct V_12 * V_13 )
{
while ( F_98 ( & V_13 -> V_70 ) ) {
struct V_69 * V_69 = F_99 ( & V_13 -> V_70 ) ;
struct V_102 * V_103 = V_69 -> V_263 -> V_257 -> V_258 ;
if ( F_63 ( V_13 , V_103 , V_69 ) ) {
F_139 ( & V_13 -> V_70 , V_69 ) ;
break;
}
if ( F_35 ( & V_13 -> V_70 ) )
F_140 ( & V_13 -> V_25 ,
& V_13 -> V_71 ) ;
}
}
static int F_141 ( void * V_147 )
{
struct V_27 * V_28 ;
while ( ! F_142 () ) {
F_143 ( V_264 ) ;
F_72 ( & V_265 ) ;
F_144 (dev, &dev_list, node) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_28 -> V_266 ; V_61 ++ ) {
struct V_12 * V_13 = V_28 -> V_38 [ V_61 ] ;
if ( ! V_13 )
continue;
F_67 ( & V_13 -> V_42 ) ;
if ( F_69 ( V_13 ) )
F_145 ( L_8 ) ;
F_90 ( V_13 , true ) ;
F_138 ( V_13 ) ;
F_68 ( & V_13 -> V_42 ) ;
}
}
F_73 ( & V_265 ) ;
F_79 ( V_267 ) ;
F_146 ( V_218 ) ;
}
return 0 ;
}
static int F_147 ( void )
{
int V_268 , error ;
do {
if ( ! F_148 ( & V_269 , V_191 ) )
return - 1 ;
F_72 ( & V_265 ) ;
error = F_149 ( & V_269 , & V_268 ) ;
F_73 ( & V_265 ) ;
} while ( error == - V_270 );
if ( error )
V_268 = - 1 ;
return V_268 ;
}
static void F_150 ( int V_268 )
{
F_72 ( & V_265 ) ;
F_151 ( & V_269 , V_268 ) ;
F_73 ( & V_265 ) ;
}
static struct V_102 * F_152 ( struct V_27 * V_28 , int V_108 ,
struct V_8 * V_155 , struct V_9 * V_271 )
{
struct V_102 * V_103 ;
struct V_272 * V_273 ;
int V_274 ;
if ( V_271 -> V_275 & V_276 )
return NULL ;
V_103 = F_103 ( sizeof( * V_103 ) , V_191 ) ;
if ( ! V_103 )
return NULL ;
V_103 -> V_114 = F_153 ( V_191 ) ;
if ( ! V_103 -> V_114 )
goto V_277;
V_103 -> V_114 -> V_278 = V_279 ;
F_154 ( V_280 , V_103 -> V_114 ) ;
F_154 ( V_281 , V_103 -> V_114 ) ;
F_155 ( V_103 -> V_114 , F_66 ) ;
V_103 -> V_28 = V_28 ;
V_103 -> V_114 -> V_136 = V_103 ;
V_273 = F_156 ( V_282 ) ;
if ( ! V_273 )
goto V_283;
V_103 -> V_109 = V_108 ;
V_103 -> V_273 = V_273 ;
V_274 = V_155 -> V_284 & 0xf ;
V_103 -> V_133 = V_155 -> V_274 [ V_274 ] . V_285 ;
F_157 ( V_103 -> V_114 , 1 << V_103 -> V_133 ) ;
if ( V_28 -> V_286 )
F_158 ( V_103 -> V_114 , V_28 -> V_286 ) ;
V_273 -> V_287 = V_288 ;
V_273 -> V_289 = V_282 ;
V_273 -> V_290 = V_282 * F_147 () ;
V_273 -> V_291 = & V_292 ;
V_273 -> V_258 = V_103 ;
V_273 -> V_114 = V_103 -> V_114 ;
V_273 -> V_293 = & V_28 -> V_34 -> V_28 ;
sprintf ( V_273 -> V_294 , L_9 , V_28 -> V_295 , V_108 ) ;
F_159 ( V_273 , F_160 ( & V_155 -> V_296 ) << ( V_103 -> V_133 - 9 ) ) ;
return V_103 ;
V_283:
F_161 ( V_103 -> V_114 ) ;
V_277:
F_33 ( V_103 ) ;
return NULL ;
}
static void F_162 ( struct V_102 * V_103 )
{
int V_268 = V_103 -> V_273 -> V_290 / V_282 ;
F_163 ( V_103 -> V_273 ) ;
F_150 ( V_268 ) ;
F_161 ( V_103 -> V_114 ) ;
F_33 ( V_103 ) ;
}
static int F_164 ( struct V_27 * V_28 , int V_225 )
{
int V_74 ;
T_7 V_111 ;
T_7 V_297 = ( V_225 - 1 ) | ( ( V_225 - 1 ) << 16 ) ;
V_74 = F_89 ( V_28 , V_298 , V_297 , 0 ,
& V_111 ) ;
if ( V_74 )
return - V_77 ;
return F_165 ( V_111 & 0xffff , V_111 >> 16 ) + 1 ;
}
static int F_166 ( struct V_27 * V_28 )
{
int V_111 , V_299 , V_61 , V_300 , V_301 , V_15 ;
V_300 = F_167 () ;
V_111 = F_164 ( V_28 , V_300 ) ;
if ( V_111 < 0 )
return V_111 ;
if ( V_111 < V_300 )
V_300 = V_111 ;
F_101 ( V_28 -> V_188 [ 0 ] . V_187 , V_28 -> V_38 [ 0 ] ) ;
V_301 = 4096 + ( ( V_300 + 1 ) << ( V_28 -> V_144 + 3 ) ) ;
if ( V_301 > 8192 ) {
F_168 ( V_28 -> V_205 ) ;
V_28 -> V_205 = F_169 ( F_170 ( V_28 -> V_34 , 0 ) ,
V_301 ) ;
V_28 -> V_194 = ( ( void V_204 * ) V_28 -> V_205 ) + 4096 ;
V_28 -> V_38 [ 0 ] -> V_45 = V_28 -> V_194 ;
}
for ( V_61 = 0 ; V_61 < V_300 ; V_61 ++ )
V_28 -> V_188 [ V_61 ] . V_188 = V_61 ;
for (; ; ) {
V_111 = F_171 ( V_28 -> V_34 , V_28 -> V_188 ,
V_300 ) ;
if ( V_111 == 0 ) {
break;
} else if ( V_111 > 0 ) {
V_300 = V_111 ;
continue;
} else {
V_300 = 1 ;
break;
}
}
V_111 = F_109 ( V_28 , V_28 -> V_38 [ 0 ] , L_7 ) ;
V_299 = F_172 ( V_302 ) ;
for ( V_61 = 0 ; V_61 < V_300 ; V_61 ++ ) {
F_100 ( V_28 -> V_188 [ V_61 ] . V_187 , F_173 ( V_299 ) ) ;
V_299 = F_174 ( V_299 , V_302 ) ;
}
V_15 = F_126 ( int , F_175 ( F_116 ( & V_28 -> V_205 -> V_203 ) ) + 1 ,
V_303 ) ;
for ( V_61 = 0 ; V_61 < V_300 ; V_61 ++ ) {
V_28 -> V_38 [ V_61 + 1 ] = F_112 ( V_28 , V_61 + 1 , V_15 , V_61 ) ;
if ( F_132 ( V_28 -> V_38 [ V_61 + 1 ] ) )
return F_133 ( V_28 -> V_38 [ V_61 + 1 ] ) ;
V_28 -> V_266 ++ ;
}
for (; V_61 < F_176 () ; V_61 ++ ) {
int V_304 = V_61 % F_177 ( V_28 -> V_266 - 1 ) ;
V_28 -> V_38 [ V_61 + 1 ] = V_28 -> V_38 [ V_304 + 1 ] ;
}
return 0 ;
}
static void F_178 ( struct V_27 * V_28 )
{
int V_61 ;
for ( V_61 = V_28 -> V_266 - 1 ; V_61 >= 0 ; V_61 -- )
F_97 ( V_28 , V_61 ) ;
}
static int F_179 ( struct V_27 * V_28 )
{
int V_305 , V_306 , V_61 ;
struct V_102 * V_103 , * V_307 ;
struct V_7 * V_308 ;
struct V_8 * V_309 ;
void * V_310 ;
T_5 V_85 ;
V_305 = F_166 ( V_28 ) ;
if ( V_305 )
return V_305 ;
V_310 = F_104 ( & V_28 -> V_34 -> V_28 , 8192 , & V_85 ,
V_191 ) ;
V_305 = F_87 ( V_28 , 0 , 1 , V_85 ) ;
if ( V_305 ) {
V_305 = - V_77 ;
goto V_311;
}
V_308 = V_310 ;
V_306 = F_77 ( & V_308 -> V_306 ) ;
memcpy ( V_28 -> V_312 , V_308 -> V_313 , sizeof( V_308 -> V_313 ) ) ;
memcpy ( V_28 -> V_314 , V_308 -> V_315 , sizeof( V_308 -> V_315 ) ) ;
memcpy ( V_28 -> V_316 , V_308 -> V_317 , sizeof( V_308 -> V_317 ) ) ;
if ( V_308 -> V_318 ) {
int V_319 = F_180 ( F_116 ( & V_28 -> V_205 -> V_203 ) ) + 12 ;
V_28 -> V_286 = 1 << ( V_308 -> V_318 + V_319 - 9 ) ;
}
V_309 = V_310 ;
for ( V_61 = 1 ; V_61 <= V_306 ; V_61 ++ ) {
V_305 = F_87 ( V_28 , V_61 , 0 , V_85 ) ;
if ( V_305 )
continue;
if ( V_309 -> V_320 == 0 )
continue;
V_305 = F_88 ( V_28 , V_321 , V_61 ,
V_85 + 4096 , NULL ) ;
if ( V_305 )
memset ( V_310 + 4096 , 0 , 4096 ) ;
V_103 = F_152 ( V_28 , V_61 , V_310 , V_310 + 4096 ) ;
if ( V_103 )
F_181 ( & V_103 -> V_62 , & V_28 -> V_322 ) ;
}
F_144 (ns, &dev->namespaces, list)
F_182 ( V_103 -> V_273 ) ;
goto V_323;
V_311:
F_183 (ns, next, &dev->namespaces, list) {
F_184 ( & V_103 -> V_62 ) ;
F_162 ( V_103 ) ;
}
V_323:
F_94 ( & V_28 -> V_34 -> V_28 , 8192 , V_310 , V_85 ) ;
return V_305 ;
}
static int F_185 ( struct V_27 * V_28 )
{
struct V_102 * V_103 , * V_307 ;
F_72 ( & V_265 ) ;
F_184 ( & V_28 -> V_324 ) ;
F_73 ( & V_265 ) ;
F_183 (ns, next, &dev->namespaces, list) {
F_184 ( & V_103 -> V_62 ) ;
F_186 ( V_103 -> V_273 ) ;
F_162 ( V_103 ) ;
}
F_178 ( V_28 ) ;
return 0 ;
}
static int F_187 ( struct V_27 * V_28 )
{
struct V_89 * V_189 = & V_28 -> V_34 -> V_28 ;
V_28 -> V_68 = F_188 ( L_10 , V_189 ,
V_51 , V_51 , 0 ) ;
if ( ! V_28 -> V_68 )
return - V_101 ;
V_28 -> V_65 = F_188 ( L_11 , V_189 ,
256 , 256 , 0 ) ;
if ( ! V_28 -> V_65 ) {
F_189 ( V_28 -> V_68 ) ;
return - V_101 ;
}
return 0 ;
}
static void F_190 ( struct V_27 * V_28 )
{
F_189 ( V_28 -> V_68 ) ;
F_189 ( V_28 -> V_65 ) ;
}
static int F_191 ( struct V_27 * V_28 )
{
int V_295 , error ;
do {
if ( ! F_148 ( & V_325 , V_191 ) )
return - V_221 ;
F_72 ( & V_265 ) ;
error = F_149 ( & V_325 , & V_295 ) ;
F_73 ( & V_265 ) ;
} while ( error == - V_270 );
if ( error )
return - V_221 ;
V_28 -> V_295 = V_295 ;
return 0 ;
}
static void F_192 ( struct V_27 * V_28 )
{
F_72 ( & V_265 ) ;
F_151 ( & V_325 , V_28 -> V_295 ) ;
F_73 ( & V_265 ) ;
}
static int F_193 ( struct V_34 * V_326 , const struct V_327 * V_155 )
{
int V_328 , V_111 = - V_101 ;
struct V_27 * V_28 ;
V_28 = F_103 ( sizeof( * V_28 ) , V_191 ) ;
if ( ! V_28 )
return - V_101 ;
V_28 -> V_188 = F_124 ( F_176 () , sizeof( * V_28 -> V_188 ) ,
V_191 ) ;
if ( ! V_28 -> V_188 )
goto free;
V_28 -> V_38 = F_124 ( F_176 () + 1 , sizeof( void * ) ,
V_191 ) ;
if ( ! V_28 -> V_38 )
goto free;
if ( F_194 ( V_326 ) )
goto free;
F_195 ( V_326 ) ;
V_328 = F_196 ( V_326 , V_329 ) ;
if ( F_197 ( V_326 , V_328 , L_5 ) )
goto V_330;
F_198 ( & V_28 -> V_322 ) ;
V_28 -> V_34 = V_326 ;
F_199 ( V_326 , V_28 ) ;
F_200 ( & V_326 -> V_28 , F_201 ( 64 ) ) ;
F_202 ( & V_326 -> V_28 , F_201 ( 64 ) ) ;
V_111 = F_191 ( V_28 ) ;
if ( V_111 )
goto V_330;
V_28 -> V_188 [ 0 ] . V_187 = V_326 -> V_146 ;
V_111 = F_187 ( V_28 ) ;
if ( V_111 )
goto V_331;
V_28 -> V_205 = F_169 ( F_170 ( V_326 , 0 ) , 8192 ) ;
if ( ! V_28 -> V_205 ) {
V_111 = - V_101 ;
goto V_331;
}
V_111 = F_114 ( V_28 ) ;
if ( V_111 )
goto V_332;
V_28 -> V_266 ++ ;
F_72 ( & V_265 ) ;
F_203 ( & V_28 -> V_324 , & V_333 ) ;
F_73 ( & V_265 ) ;
V_111 = F_179 ( V_28 ) ;
if ( V_111 )
goto V_334;
return 0 ;
V_334:
F_72 ( & V_265 ) ;
F_184 ( & V_28 -> V_324 ) ;
F_73 ( & V_265 ) ;
F_178 ( V_28 ) ;
V_332:
F_168 ( V_28 -> V_205 ) ;
V_331:
F_204 ( V_326 ) ;
F_192 ( V_28 ) ;
F_190 ( V_28 ) ;
V_330:
F_205 ( V_326 ) ;
F_206 ( V_326 ) ;
free:
F_33 ( V_28 -> V_38 ) ;
F_33 ( V_28 -> V_188 ) ;
F_33 ( V_28 ) ;
return V_111 ;
}
static void F_207 ( struct V_34 * V_326 )
{
struct V_27 * V_28 = F_208 ( V_326 ) ;
F_185 ( V_28 ) ;
F_204 ( V_326 ) ;
F_168 ( V_28 -> V_205 ) ;
F_192 ( V_28 ) ;
F_190 ( V_28 ) ;
F_205 ( V_326 ) ;
F_206 ( V_326 ) ;
F_33 ( V_28 -> V_38 ) ;
F_33 ( V_28 -> V_188 ) ;
F_33 ( V_28 ) ;
}
static int T_12 F_209 ( void )
{
int V_111 ;
V_72 = F_210 ( F_141 , NULL , L_5 ) ;
if ( F_132 ( V_72 ) )
return F_133 ( V_72 ) ;
V_111 = F_211 ( V_288 , L_5 ) ;
if ( V_111 < 0 )
goto V_335;
else if ( V_111 > 0 )
V_288 = V_111 ;
V_111 = F_212 ( & V_336 ) ;
if ( V_111 )
goto V_337;
return 0 ;
V_337:
V_337 ( V_288 , L_5 ) ;
V_335:
F_213 ( V_72 ) ;
return V_111 ;
}
static void T_13 F_214 ( void )
{
F_215 ( & V_336 ) ;
V_337 ( V_288 , L_5 ) ;
F_213 ( V_72 ) ;
}
