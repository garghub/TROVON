static bool
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
if ( V_9 . V_12 == V_13 ) {
struct V_14 * V_15 = V_4 -> V_7 ;
if ( F_2 ( V_15 -> V_16 . V_17 ) != V_4 -> V_18 )
return false ;
} else if ( V_9 . V_12 != V_19 )
return false ;
return F_3 ( V_2 -> V_20 , V_2 , & V_9 , V_6 ) ;
}
static bool
F_4 (
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_4 -> V_23 -> V_24 ;
struct V_25 * V_26 = V_4 -> V_7 ;
if ( F_5 ( & V_22 -> V_27 ) ) {
struct V_28 * V_29 = V_4 -> V_7 ;
if ( V_29 -> V_12 != F_6 ( V_30 ) )
return false ;
if ( ! F_7 ( & V_29 -> V_31 , & V_22 -> V_27 . V_32 ) )
return false ;
if ( F_2 ( V_29 -> V_17 ) != V_4 -> V_18 )
return false ;
if ( ! F_8 ( V_22 , F_2 ( V_29 -> V_33 ) ) )
return false ;
} else {
if ( V_26 -> V_12 != F_6 ( V_34 ) )
return false ;
}
return true ;
}
static void
F_9 (
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_4 -> V_23 -> V_24 ;
if ( F_5 ( & V_22 -> V_27 ) &&
! F_10 ( V_4 , V_35 ) )
F_11 ( V_4 , - V_36 ) ;
else if ( ! F_4 ( V_4 ) )
F_11 ( V_4 , - V_37 ) ;
if ( V_4 -> V_38 )
F_12 ( V_4 ) ;
}
static void
F_13 (
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_4 -> V_23 -> V_24 ;
struct V_39 * V_40 = V_4 -> V_41 ;
struct V_28 * V_29 = V_4 -> V_7 ;
if ( ! F_4 ( V_4 ) ) {
F_11 ( V_4 , - V_37 ) ;
F_12 ( V_4 ) ;
return;
}
if ( ! F_5 ( & V_22 -> V_27 ) )
return;
if ( V_40 )
V_29 -> V_33 = F_14 ( V_40 -> V_42 . V_43 ) ;
F_15 ( V_4 , V_35 ) ;
}
static int
F_16 (
struct V_44 * V_45 ,
struct V_1 * V_2 ,
T_1 V_46 ,
T_2 V_47 ,
struct V_3 * * V_48 )
{
int V_49 ;
V_49 = F_17 ( V_45 , V_2 , V_46 , V_47 , V_48 ,
V_50 , & V_51 ) ;
if ( ! V_49 && V_45 && * V_48 )
F_18 ( V_45 , * V_48 , V_52 ) ;
return V_49 ;
}
int
F_19 (
struct V_44 * V_45 ,
struct V_1 * V_2 ,
T_1 V_46 ,
struct V_3 * * V_48 )
{
return F_16 ( V_45 , V_2 , V_46 , - 1 , V_48 ) ;
}
static int
F_20 (
struct V_44 * V_45 ,
struct V_1 * V_2 ,
T_1 V_46 ,
struct V_3 * * V_48 )
{
return F_16 ( V_45 , V_2 , V_46 , - 2 , V_48 ) ;
}
static int
F_21 (
T_3 * args ,
T_4 V_46 ,
struct V_3 * * V_48 )
{
struct V_44 * V_45 = args -> V_53 ;
struct V_1 * V_2 = args -> V_2 ;
struct V_21 * V_22 = V_2 -> V_20 ;
struct V_3 * V_4 ;
int error ;
struct V_54 V_26 ;
error = F_22 ( V_45 , V_2 , F_23 ( args -> V_55 , V_46 ) ,
- 1 , & V_4 , V_50 ) ;
if ( error )
return error ;
F_18 ( V_45 , V_4 , V_52 ) ;
V_4 -> V_56 = & V_51 ;
memset ( V_4 -> V_7 , 0 , sizeof( struct V_57 ) ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_5 ( & V_22 -> V_27 ) ) {
struct V_57 * V_29 = V_4 -> V_7 ;
V_26 . V_12 = V_30 ;
V_29 -> V_26 . V_17 = F_14 ( V_4 -> V_18 ) ;
V_29 -> V_26 . V_58 = F_14 ( V_2 -> V_59 ) ;
F_24 ( & V_29 -> V_26 . V_31 , & V_22 -> V_27 . V_32 ) ;
} else
V_26 . V_12 = V_34 ;
V_2 -> V_10 -> V_60 ( V_4 -> V_7 , & V_26 ) ;
* V_48 = V_4 ;
return 0 ;
}
STATIC void
F_25 (
struct V_61 * args ,
struct V_3 * V_4 ,
int V_62 ,
int V_63 )
{
T_5 * free ;
T_6 * V_64 ;
free = V_4 -> V_7 ;
V_64 = args -> V_2 -> V_10 -> V_65 ( free ) ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_34 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
F_26 ( args -> V_53 , V_4 ,
( V_66 ) ( ( char * ) & V_64 [ V_62 ] - ( char * ) free ) ,
( V_66 ) ( ( char * ) & V_64 [ V_63 ] - ( char * ) free +
sizeof( V_64 [ 0 ] ) - 1 ) ) ;
}
static void
F_27 (
struct V_61 * args ,
struct V_3 * V_4 )
{
#ifdef F_28
T_5 * free ;
free = V_4 -> V_7 ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_34 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
#endif
F_26 ( args -> V_53 , V_4 , 0 ,
args -> V_2 -> V_10 -> V_67 - 1 ) ;
}
int
F_29 (
T_3 * args ,
struct V_3 * V_68 )
{
T_7 * V_2 ;
int error ;
struct V_3 * V_69 ;
T_4 V_70 ;
T_5 * free ;
T_6 * V_71 ;
int V_72 ;
T_8 * V_6 ;
T_9 * V_73 ;
int V_74 ;
T_10 V_75 ;
T_6 * V_76 ;
T_11 * V_45 ;
struct V_54 V_77 ;
F_30 ( args ) ;
V_2 = args -> V_2 ;
V_45 = args -> V_53 ;
if ( ( error = F_31 ( args , V_78 , & V_70 ) ) ) {
return error ;
}
ASSERT ( V_70 == F_32 ( args -> V_55 , V_79 ) ) ;
error = F_21 ( args , V_70 , & V_69 ) ;
if ( error )
return error ;
free = V_69 -> V_7 ;
V_2 -> V_10 -> V_80 ( & V_77 , free ) ;
V_6 = V_68 -> V_7 ;
V_73 = F_33 ( args -> V_55 , V_6 ) ;
ASSERT ( F_34 ( V_73 -> V_81 ) <=
( V_66 ) V_2 -> V_82 . V_83 / args -> V_55 -> V_84 ) ;
V_71 = F_35 ( V_73 ) ;
V_76 = V_2 -> V_10 -> V_65 ( free ) ;
for ( V_72 = V_74 = 0 ; V_72 < F_34 ( V_73 -> V_81 ) ; V_72 ++ , V_71 ++ , V_76 ++ ) {
if ( ( V_75 = F_36 ( * V_71 ) ) != V_85 )
V_74 ++ ;
* V_76 = F_37 ( V_75 ) ;
}
V_77 . V_86 = V_74 ;
V_77 . V_87 = F_34 ( V_73 -> V_81 ) ;
V_2 -> V_10 -> V_60 ( V_69 -> V_7 , & V_77 ) ;
F_25 ( args , V_69 , 0 , V_77 . V_87 - 1 ) ;
F_27 ( args , V_69 ) ;
if ( V_6 -> V_26 . V_16 . V_12 == F_37 ( V_88 ) )
V_6 -> V_26 . V_16 . V_12 = F_37 ( V_19 ) ;
else
V_6 -> V_26 . V_16 . V_12 = F_37 ( V_13 ) ;
V_68 -> V_56 = & V_89 ;
F_18 ( V_45 , V_68 , V_90 ) ;
F_38 ( args , V_68 ) ;
F_39 ( V_2 , V_68 ) ;
return 0 ;
}
static int
F_40 (
struct V_3 * V_4 ,
T_3 * args ,
int V_91 )
{
int V_92 ;
T_7 * V_2 ;
int V_93 ;
T_8 * V_6 ;
T_12 * V_94 ;
int V_95 ;
int V_96 ;
int V_97 ;
struct V_8 V_9 ;
struct V_98 * V_99 ;
F_41 ( args , V_91 ) ;
V_2 = args -> V_2 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_99 = V_2 -> V_10 -> V_100 ( V_6 ) ;
if ( V_91 < 0 )
return - V_37 ;
if ( V_9 . V_101 == V_2 -> V_10 -> V_102 ( args -> V_55 ) ) {
if ( ! V_9 . V_103 )
return - V_104 ;
V_92 = V_9 . V_103 > 1 ;
} else
V_92 = 0 ;
ASSERT ( V_91 == 0 || F_34 ( V_99 [ V_91 - 1 ] . V_105 ) <= args -> V_105 ) ;
ASSERT ( V_91 == V_9 . V_101 ||
F_34 ( V_99 [ V_91 ] . V_105 ) >= args -> V_105 ) ;
if ( args -> V_106 & V_107 )
return 0 ;
if ( V_92 )
F_42 ( & V_9 , V_99 , & V_91 , & V_97 ,
& V_93 , & V_96 , & V_95 ) ;
else if ( V_9 . V_103 ) {
V_96 = V_9 . V_101 ;
V_95 = - 1 ;
}
V_94 = F_43 ( & V_9 , V_99 , V_91 , V_92 , V_97 ,
V_93 , & V_96 , & V_95 ) ;
V_94 -> V_105 = F_6 ( args -> V_105 ) ;
V_94 -> V_108 = F_6 ( F_44 ( args -> V_55 ,
args -> V_17 , args -> V_91 ) ) ;
V_2 -> V_10 -> V_109 ( V_6 , & V_9 ) ;
F_38 ( args , V_4 ) ;
F_45 ( args , V_4 , V_96 , V_95 ) ;
F_39 ( V_2 , V_4 ) ;
return 0 ;
}
static void
F_46 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_4 V_110 )
{
struct V_54 V_26 ;
V_2 -> V_10 -> V_80 ( & V_26 , V_4 -> V_7 ) ;
ASSERT ( ( V_26 . V_111 %
V_2 -> V_10 -> V_112 ( V_2 -> V_20 -> V_113 ) ) == 0 ) ;
ASSERT ( V_26 . V_111 <= V_110 ) ;
ASSERT ( V_110 < V_26 . V_111 + V_26 . V_87 ) ;
}
T_13
F_47 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int * V_101 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_98 * V_99 ;
struct V_8 V_9 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_12 == V_19 ||
V_9 . V_12 == V_13 ) ;
if ( V_101 )
* V_101 = V_9 . V_101 ;
if ( ! V_9 . V_101 )
return 0 ;
V_99 = V_2 -> V_10 -> V_100 ( V_6 ) ;
return F_34 ( V_99 [ V_9 . V_101 - 1 ] . V_105 ) ;
}
STATIC int
F_48 (
struct V_3 * V_4 ,
T_3 * args ,
int * V_114 ,
T_14 * V_115 )
{
struct V_3 * V_116 = NULL ;
T_4 V_117 = - 1 ;
T_4 V_118 = - 1 ;
T_7 * V_2 ;
int error ;
int V_119 ;
T_5 * free = NULL ;
int V_91 ;
T_8 * V_6 ;
int V_120 ;
T_12 * V_94 ;
T_15 * V_22 ;
T_4 V_121 ;
T_4 V_122 ;
T_11 * V_45 ;
struct V_98 * V_99 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_45 = args -> V_53 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_99 = V_2 -> V_10 -> V_100 ( V_6 ) ;
F_39 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_101 > 0 ) ;
V_91 = F_49 ( args , V_4 ) ;
if ( V_115 -> V_123 ) {
V_116 = V_115 -> V_124 . V_4 ;
V_118 = V_115 -> V_124 . V_17 ;
free = V_116 -> V_7 ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_34 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
}
V_120 = V_2 -> V_10 -> V_125 ( args -> V_126 ) ;
for ( V_94 = & V_99 [ V_91 ] ;
V_91 < V_9 . V_101 && F_34 ( V_94 -> V_105 ) == args -> V_105 ;
V_94 ++ , V_91 ++ ) {
if ( F_34 ( V_94 -> V_108 ) == V_127 )
continue;
V_121 = F_50 ( args -> V_55 ,
F_34 ( V_94 -> V_108 ) ) ;
if ( V_121 != V_117 ) {
T_6 * V_64 ;
V_117 = V_121 ;
V_122 = V_2 -> V_10 -> V_128 ( args -> V_55 , V_121 ) ;
if ( V_122 != V_118 ) {
if ( V_116 )
F_51 ( V_45 , V_116 ) ;
error = F_19 ( V_45 , V_2 ,
F_23 ( args -> V_55 ,
V_122 ) ,
& V_116 ) ;
if ( error )
return error ;
free = V_116 -> V_7 ;
F_46 ( V_2 , V_116 , V_117 ) ;
}
V_119 = V_2 -> V_10 -> V_129 ( args -> V_55 , V_117 ) ;
V_64 = V_2 -> V_10 -> V_65 ( free ) ;
if ( F_52 ( V_64 [ V_119 ] == F_37 ( V_85 ) ) ) {
F_53 ( L_1 ,
V_130 , V_22 ) ;
if ( V_118 != V_122 )
F_51 ( V_45 , V_116 ) ;
return - V_37 ;
}
V_118 = V_122 ;
if ( F_36 ( V_64 [ V_119 ] ) >= V_120 )
goto V_131;
}
}
V_119 = - 1 ;
V_131:
ASSERT ( args -> V_106 & V_132 ) ;
if ( V_116 ) {
V_115 -> V_123 = 1 ;
V_115 -> V_124 . V_4 = V_116 ;
V_115 -> V_124 . V_91 = V_119 ;
V_115 -> V_124 . V_17 = V_118 ;
V_115 -> V_124 . V_12 = V_34 ;
} else {
V_115 -> V_123 = 0 ;
}
* V_114 = V_91 ;
return - V_133 ;
}
STATIC int
F_54 (
struct V_3 * V_4 ,
T_3 * args ,
int * V_114 ,
T_14 * V_115 )
{
struct V_3 * V_116 = NULL ;
T_4 V_117 = - 1 ;
T_16 * V_134 ;
T_7 * V_2 ;
int error ;
int V_91 ;
T_8 * V_6 ;
T_12 * V_94 ;
T_15 * V_22 ;
T_4 V_121 ;
T_11 * V_45 ;
enum V_135 V_136 ;
struct V_98 * V_99 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_45 = args -> V_53 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_99 = V_2 -> V_10 -> V_100 ( V_6 ) ;
F_39 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_101 > 0 ) ;
V_91 = F_49 ( args , V_4 ) ;
if ( V_115 -> V_123 ) {
V_116 = V_115 -> V_124 . V_4 ;
V_117 = V_115 -> V_124 . V_17 ;
}
for ( V_94 = & V_99 [ V_91 ] ;
V_91 < V_9 . V_101 && F_34 ( V_94 -> V_105 ) == args -> V_105 ;
V_94 ++ , V_91 ++ ) {
if ( F_34 ( V_94 -> V_108 ) == V_127 )
continue;
V_121 = F_50 ( args -> V_55 ,
F_34 ( V_94 -> V_108 ) ) ;
if ( V_121 != V_117 ) {
if ( V_116 && ( args -> V_137 == V_138 ||
V_117 != V_115 -> V_124 . V_17 ) )
F_51 ( V_45 , V_116 ) ;
if ( args -> V_137 != V_138 &&
V_121 == V_115 -> V_124 . V_17 ) {
ASSERT ( V_115 -> V_123 ) ;
V_116 = V_115 -> V_124 . V_4 ;
} else {
error = F_55 ( V_45 , V_2 ,
F_23 ( args -> V_55 ,
V_121 ) ,
- 1 , & V_116 ) ;
if ( error )
return error ;
}
F_56 ( V_2 , V_116 ) ;
V_117 = V_121 ;
}
V_134 = ( T_16 * ) ( ( char * ) V_116 -> V_7 +
F_57 ( args -> V_55 ,
F_34 ( V_94 -> V_108 ) ) ) ;
V_136 = V_22 -> V_139 -> V_140 ( args , V_134 -> V_141 , V_134 -> V_126 ) ;
if ( V_136 != V_138 && V_136 != args -> V_137 ) {
if ( args -> V_137 != V_138 &&
V_117 != V_115 -> V_124 . V_17 )
F_51 ( V_45 , V_115 -> V_124 . V_4 ) ;
args -> V_137 = V_136 ;
args -> V_142 = F_2 ( V_134 -> V_142 ) ;
args -> V_143 = V_2 -> V_10 -> V_144 ( V_134 ) ;
* V_114 = V_91 ;
V_115 -> V_123 = 1 ;
V_115 -> V_124 . V_4 = V_116 ;
V_115 -> V_124 . V_17 = V_117 ;
V_115 -> V_124 . V_91 = ( int ) ( ( char * ) V_134 -
( char * ) V_116 -> V_7 ) ;
V_115 -> V_124 . V_12 = V_145 ;
V_116 -> V_56 = & V_146 ;
F_18 ( V_45 , V_116 , V_147 ) ;
if ( V_136 == V_148 )
return - V_149 ;
}
}
ASSERT ( V_91 == V_9 . V_101 || ( args -> V_106 & V_132 ) ) ;
if ( V_116 ) {
if ( args -> V_137 == V_138 ) {
V_115 -> V_123 = 1 ;
V_115 -> V_124 . V_4 = V_116 ;
V_115 -> V_124 . V_91 = - 1 ;
V_115 -> V_124 . V_17 = V_117 ;
V_115 -> V_124 . V_12 = V_145 ;
V_116 -> V_56 = & V_146 ;
F_18 ( V_45 , V_116 , V_147 ) ;
} else {
if ( V_115 -> V_124 . V_4 != V_116 )
F_51 ( V_45 , V_116 ) ;
}
} else {
V_115 -> V_123 = 0 ;
}
* V_114 = V_91 ;
return - V_133 ;
}
int
F_58 (
struct V_3 * V_4 ,
T_3 * args ,
int * V_114 ,
T_14 * V_115 )
{
if ( args -> V_106 & V_150 )
return F_48 ( V_4 , args , V_114 ,
V_115 ) ;
return F_54 ( V_4 , args , V_114 , V_115 ) ;
}
static void
F_59 (
T_3 * args ,
struct V_3 * V_151 ,
struct V_8 * V_152 ,
struct V_98 * V_153 ,
int V_154 ,
struct V_3 * V_155 ,
struct V_8 * V_156 ,
struct V_98 * V_157 ,
int V_158 ,
int V_101 )
{
int V_103 ;
F_60 ( args , V_154 , V_158 , V_101 ) ;
if ( V_101 == 0 )
return;
if ( V_158 < V_156 -> V_101 ) {
memmove ( & V_157 [ V_158 + V_101 ] , & V_157 [ V_158 ] ,
( V_156 -> V_101 - V_158 ) * sizeof( T_12 ) ) ;
F_45 ( args , V_155 , V_158 + V_101 ,
V_101 + V_156 -> V_101 - 1 ) ;
}
if ( V_152 -> V_103 ) {
int V_72 ;
for ( V_72 = V_154 , V_103 = 0 ; V_72 < V_154 + V_101 ; V_72 ++ ) {
if ( V_153 [ V_72 ] . V_108 ==
F_6 ( V_127 ) )
V_103 ++ ;
}
} else
V_103 = 0 ;
memcpy ( & V_157 [ V_158 ] , & V_153 [ V_154 ] ,
V_101 * sizeof( T_12 ) ) ;
F_45 ( args , V_155 , V_158 , V_158 + V_101 - 1 ) ;
if ( V_154 + V_101 < V_152 -> V_101 ) {
memmove ( & V_153 [ V_154 ] , & V_153 [ V_154 + V_101 ] ,
V_101 * sizeof( T_12 ) ) ;
F_45 ( args , V_151 , V_154 , V_154 + V_101 - 1 ) ;
}
V_152 -> V_101 -= V_101 ;
V_152 -> V_103 -= V_103 ;
V_156 -> V_101 += V_101 ;
V_156 -> V_103 += V_103 ;
}
int
F_61 (
struct V_1 * V_2 ,
struct V_3 * V_159 ,
struct V_3 * V_160 )
{
struct V_5 * V_161 = V_159 -> V_7 ;
struct V_5 * V_162 = V_160 -> V_7 ;
struct V_98 * V_163 ;
struct V_98 * V_164 ;
struct V_8 V_165 ;
struct V_8 V_166 ;
V_2 -> V_10 -> V_11 ( & V_165 , V_161 ) ;
V_2 -> V_10 -> V_11 ( & V_166 , V_162 ) ;
V_163 = V_2 -> V_10 -> V_100 ( V_161 ) ;
V_164 = V_2 -> V_10 -> V_100 ( V_162 ) ;
if ( V_165 . V_101 > 0 && V_166 . V_101 > 0 &&
( F_34 ( V_164 [ 0 ] . V_105 ) < F_34 ( V_163 [ 0 ] . V_105 ) ||
F_34 ( V_164 [ V_166 . V_101 - 1 ] . V_105 ) <
F_34 ( V_163 [ V_165 . V_101 - 1 ] . V_105 ) ) )
return 1 ;
return 0 ;
}
static void
F_62 (
T_14 * V_115 ,
T_17 * V_167 ,
T_17 * V_168 )
{
T_3 * args ;
int V_101 ;
int V_169 ;
T_8 * V_161 ;
T_8 * V_162 ;
int V_170 ;
#if F_63 ( F_28 ) || F_63 ( V_171 )
int V_172 ;
#endif
int V_173 ;
int V_174 ;
struct V_98 * V_163 ;
struct V_98 * V_164 ;
struct V_8 V_165 ;
struct V_8 V_166 ;
struct V_1 * V_2 = V_115 -> args -> V_2 ;
args = V_115 -> args ;
if ( ( V_174 = F_61 ( V_2 , V_167 -> V_4 , V_168 -> V_4 ) ) ) {
T_17 * V_175 ;
V_175 = V_167 ;
V_167 = V_168 ;
V_168 = V_175 ;
}
V_161 = V_167 -> V_4 -> V_7 ;
V_162 = V_168 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_165 , V_161 ) ;
V_2 -> V_10 -> V_11 ( & V_166 , V_162 ) ;
V_163 = V_2 -> V_10 -> V_100 ( V_161 ) ;
V_164 = V_2 -> V_10 -> V_100 ( V_162 ) ;
V_173 = V_165 . V_101 + V_166 . V_101 ;
#if F_63 ( F_28 ) || F_63 ( V_171 )
V_172 = V_165 . V_103 + V_166 . V_103 ;
#endif
V_170 = V_173 >> 1 ;
if ( V_173 & 1 ) {
T_13 V_176 ;
if ( V_170 >= V_165 . V_101 )
V_176 = F_34 ( V_164 [ V_170 - V_165 . V_101 ] . V_105 ) ;
else
V_176 = F_34 ( V_163 [ V_170 ] . V_105 ) ;
V_169 = args -> V_105 <= V_176 ;
}
else
V_169 = 1 ;
V_101 = V_165 . V_101 - V_170 + ( V_169 == 0 ) ;
if ( V_101 > 0 )
F_59 ( args , V_167 -> V_4 , & V_165 , V_163 ,
V_165 . V_101 - V_101 , V_168 -> V_4 ,
& V_166 , V_164 , 0 , V_101 ) ;
else if ( V_101 < 0 )
F_59 ( args , V_168 -> V_4 , & V_166 , V_164 , 0 ,
V_167 -> V_4 , & V_165 , V_163 ,
V_165 . V_101 , V_101 ) ;
ASSERT ( V_165 . V_101 + V_166 . V_101 == V_173 ) ;
ASSERT ( V_165 . V_103 + V_166 . V_103 == V_172 ) ;
V_2 -> V_10 -> V_109 ( V_161 , & V_165 ) ;
V_2 -> V_10 -> V_109 ( V_162 , & V_166 ) ;
F_38 ( args , V_167 -> V_4 ) ;
F_38 ( args , V_168 -> V_4 ) ;
F_39 ( V_2 , V_167 -> V_4 ) ;
F_39 ( V_2 , V_168 -> V_4 ) ;
if ( V_165 . V_101 < V_166 . V_101 )
V_115 -> V_177 = V_174 ;
else if ( V_165 . V_101 > V_166 . V_101 )
V_115 -> V_177 = ! V_174 ;
else
V_115 -> V_177 = V_174 ^ ( V_167 -> V_91 <= V_165 . V_101 ) ;
if ( ! V_115 -> V_177 )
V_168 -> V_91 = V_167 -> V_91 - V_165 . V_101 ;
if ( V_168 -> V_91 < 0 ) {
V_115 -> V_177 = 1 ;
V_168 -> V_91 = 0 ;
F_64 ( V_2 -> V_20 ,
L_2 ,
V_178 , V_167 -> V_91 ) ;
}
}
static int
F_65 (
T_3 * args ,
struct V_179 * V_26 ,
struct V_180 * free ,
T_4 V_70 ,
int V_181 ,
struct V_3 * V_69 ,
int V_182 )
{
int V_183 = 0 ;
T_6 * V_64 ;
struct V_54 V_77 ;
struct V_1 * V_2 = args -> V_2 ;
V_2 -> V_10 -> V_80 ( & V_77 , free ) ;
V_64 = V_2 -> V_10 -> V_65 ( free ) ;
if ( V_26 ) {
V_64 [ V_181 ] = F_37 ( V_182 ) ;
F_25 ( args , V_69 , V_181 , V_181 ) ;
return 0 ;
}
V_77 . V_86 -- ;
if ( V_181 == V_77 . V_87 - 1 ) {
int V_72 ;
for ( V_72 = V_181 - 1 ; V_72 >= 0 ; V_72 -- ) {
if ( V_64 [ V_72 ] != F_37 ( V_85 ) )
break;
}
V_77 . V_87 = V_72 + 1 ;
V_183 = 0 ;
} else {
V_64 [ V_181 ] = F_37 ( V_85 ) ;
V_183 = 1 ;
}
V_2 -> V_10 -> V_60 ( free , & V_77 ) ;
F_27 ( args , V_69 ) ;
if ( ! V_77 . V_86 ) {
int error ;
error = F_66 ( args , V_70 , V_69 ) ;
if ( error == 0 ) {
V_69 = NULL ;
V_183 = 0 ;
} else if ( error != - V_104 || args -> V_184 != 0 )
return error ;
}
if ( V_183 )
F_25 ( args , V_69 , V_181 , V_181 ) ;
return 0 ;
}
static int
F_67 (
T_3 * args ,
struct V_3 * V_4 ,
int V_91 ,
T_17 * V_185 ,
int * V_186 )
{
T_18 * V_26 ;
T_4 V_110 ;
struct V_3 * V_187 ;
T_16 * V_134 ;
T_7 * V_2 ;
T_8 * V_6 ;
T_12 * V_94 ;
int V_182 ;
int V_75 ;
int V_188 ;
int V_189 ;
T_11 * V_45 ;
struct V_190 * V_191 ;
struct V_8 V_9 ;
struct V_98 * V_99 ;
F_68 ( args , V_91 ) ;
V_2 = args -> V_2 ;
V_45 = args -> V_53 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_99 = V_2 -> V_10 -> V_100 ( V_6 ) ;
V_94 = & V_99 [ V_91 ] ;
V_110 = F_50 ( args -> V_55 , F_34 ( V_94 -> V_108 ) ) ;
ASSERT ( V_185 -> V_17 == V_110 ) ;
V_75 = F_57 ( args -> V_55 , F_34 ( V_94 -> V_108 ) ) ;
ASSERT ( V_185 -> V_91 == V_75 ) ;
V_9 . V_103 ++ ;
V_2 -> V_10 -> V_109 ( V_6 , & V_9 ) ;
F_38 ( args , V_4 ) ;
V_94 -> V_108 = F_6 ( V_127 ) ;
F_45 ( args , V_4 , V_91 , V_91 ) ;
V_187 = V_185 -> V_4 ;
V_26 = V_187 -> V_7 ;
V_134 = ( T_16 * ) ( ( char * ) V_26 + V_75 ) ;
V_191 = V_2 -> V_10 -> V_192 ( V_26 ) ;
V_182 = F_36 ( V_191 [ 0 ] . V_120 ) ;
V_188 = V_189 = 0 ;
F_69 ( args , V_187 , V_75 ,
V_2 -> V_10 -> V_125 ( V_134 -> V_126 ) , & V_188 , & V_189 ) ;
if ( V_189 )
F_70 ( V_2 , V_26 , & V_188 ) ;
if ( V_188 )
F_71 ( args , V_187 ) ;
F_56 ( V_2 , V_187 ) ;
if ( V_182 < F_36 ( V_191 [ 0 ] . V_120 ) ) {
int error ;
struct V_3 * V_69 ;
T_4 V_70 ;
int V_181 ;
T_5 * free ;
V_70 = V_2 -> V_10 -> V_128 ( args -> V_55 , V_110 ) ;
error = F_19 ( V_45 , V_2 ,
F_23 ( args -> V_55 , V_70 ) ,
& V_69 ) ;
if ( error )
return error ;
free = V_69 -> V_7 ;
#ifdef F_28
{
struct V_54 V_77 ;
V_2 -> V_10 -> V_80 ( & V_77 , free ) ;
ASSERT ( V_77 . V_111 == V_2 -> V_10 -> V_112 ( args -> V_55 ) *
( V_70 - F_32 ( args -> V_55 ,
V_79 ) ) ) ;
}
#endif
V_181 = V_2 -> V_10 -> V_129 ( args -> V_55 , V_110 ) ;
V_182 = F_36 ( V_191 [ 0 ] . V_120 ) ;
if ( V_182 == args -> V_55 -> V_84 -
V_2 -> V_10 -> V_193 ) {
error = F_66 ( args , V_110 , V_187 ) ;
if ( error == 0 ) {
V_185 -> V_4 = NULL ;
V_26 = NULL ;
}
else if ( ! ( error == - V_104 && args -> V_184 == 0 ) )
return error ;
}
error = F_65 ( args , V_26 , free ,
V_70 , V_181 , V_69 , V_182 ) ;
if ( error )
return error ;
}
F_39 ( V_2 , V_4 ) ;
* V_186 = ( V_2 -> V_10 -> V_194 +
( V_66 ) sizeof( V_99 [ 0 ] ) * ( V_9 . V_101 - V_9 . V_103 ) ) <
args -> V_55 -> V_195 ;
return 0 ;
}
int
F_72 (
T_14 * V_115 ,
T_17 * V_196 ,
T_17 * V_197 )
{
T_3 * args ;
T_1 V_17 ;
int error ;
struct V_1 * V_2 ;
args = V_115 -> args ;
V_2 = args -> V_2 ;
ASSERT ( V_196 -> V_12 == V_19 ) ;
error = F_73 ( args , & V_17 ) ;
if ( error ) {
return error ;
}
error = F_74 ( args , F_75 ( args -> V_55 , V_17 ) ,
& V_197 -> V_4 , V_19 ) ;
if ( error )
return error ;
V_197 -> V_17 = V_17 ;
V_197 -> V_12 = V_19 ;
F_62 ( V_115 , V_196 , V_197 ) ;
error = F_76 ( V_115 , V_196 , V_197 ) ;
if ( error ) {
return error ;
}
if ( V_115 -> V_177 )
error = F_40 ( V_196 -> V_4 , args , V_196 -> V_91 ) ;
else
error = F_40 ( V_197 -> V_4 , args , V_197 -> V_91 ) ;
V_196 -> V_105 = F_47 ( V_2 , V_196 -> V_4 , NULL ) ;
V_197 -> V_105 = F_47 ( V_2 , V_197 -> V_4 , NULL ) ;
F_39 ( V_2 , V_196 -> V_4 ) ;
F_39 ( V_2 , V_197 -> V_4 ) ;
return error ;
}
int
F_77 (
T_14 * V_115 ,
int * V_198 )
{
T_17 * V_199 ;
T_1 V_17 ;
struct V_3 * V_4 ;
int V_200 ;
int V_101 ;
int error ;
int V_201 ;
int V_72 ;
T_8 * V_6 ;
int V_186 ;
struct V_8 V_9 ;
struct V_98 * V_99 ;
struct V_1 * V_2 = V_115 -> args -> V_2 ;
V_199 = & V_115 -> V_202 . V_199 [ V_115 -> V_202 . V_203 - 1 ] ;
V_6 = V_199 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_99 = V_2 -> V_10 -> V_100 ( V_6 ) ;
F_39 ( V_2 , V_199 -> V_4 ) ;
V_101 = V_9 . V_101 - V_9 . V_103 ;
V_200 = V_2 -> V_10 -> V_194 + V_101 * sizeof( V_99 [ 0 ] ) ;
if ( V_200 > ( V_115 -> args -> V_55 -> V_84 >> 1 ) ) {
* V_198 = 0 ;
return 0 ;
}
if ( V_101 == 0 ) {
V_201 = ( V_9 . V_204 != 0 ) ;
memcpy ( & V_115 -> V_205 , & V_115 -> V_202 , sizeof( V_115 -> V_202 ) ) ;
error = F_78 ( V_115 , & V_115 -> V_205 , V_201 , 0 ,
& V_186 ) ;
if ( error )
return error ;
* V_198 = V_186 ? 2 : 0 ;
return 0 ;
}
V_201 = V_9 . V_204 < V_9 . V_206 ;
for ( V_72 = 0 , V_4 = NULL ; V_72 < 2 ; V_201 = ! V_201 , V_72 ++ ) {
struct V_8 V_166 ;
V_17 = V_201 ? V_9 . V_204 : V_9 . V_206 ;
if ( V_17 == 0 )
continue;
error = F_79 ( V_115 -> args -> V_53 , V_2 ,
V_17 , - 1 , & V_4 ) ;
if ( error )
return error ;
V_101 = V_9 . V_101 - V_9 . V_103 ;
V_200 = V_115 -> args -> V_55 -> V_84 -
( V_115 -> args -> V_55 -> V_84 >> 2 ) ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_166 , V_6 ) ;
V_99 = V_2 -> V_10 -> V_100 ( V_6 ) ;
V_101 += V_166 . V_101 - V_166 . V_103 ;
V_200 -= V_101 * sizeof( V_99 [ 0 ] ) ;
if ( V_200 >= 0 )
break;
F_51 ( V_115 -> args -> V_53 , V_4 ) ;
}
if ( V_72 >= 2 ) {
* V_198 = 0 ;
return 0 ;
}
memcpy ( & V_115 -> V_205 , & V_115 -> V_202 , sizeof( V_115 -> V_202 ) ) ;
if ( V_17 < V_199 -> V_17 )
error = F_78 ( V_115 , & V_115 -> V_205 , V_201 , 0 ,
& V_186 ) ;
else
error = F_78 ( V_115 , & V_115 -> V_202 , V_201 , 0 ,
& V_186 ) ;
if ( error ) {
return error ;
}
* V_198 = V_186 ? 0 : 1 ;
return 0 ;
}
void
F_80 (
T_14 * V_115 ,
T_17 * V_207 ,
T_17 * V_208 )
{
T_3 * args ;
T_8 * V_209 ;
T_8 * V_210 ;
struct V_8 V_211 ;
struct V_8 V_212 ;
struct V_98 * V_153 ;
struct V_98 * V_157 ;
struct V_1 * V_2 = V_115 -> args -> V_2 ;
args = V_115 -> args ;
ASSERT ( V_207 -> V_12 == V_19 ) ;
ASSERT ( V_208 -> V_12 == V_19 ) ;
V_209 = V_207 -> V_4 -> V_7 ;
V_210 = V_208 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_211 , V_210 ) ;
V_2 -> V_10 -> V_11 ( & V_212 , V_209 ) ;
V_153 = V_2 -> V_10 -> V_100 ( V_210 ) ;
V_157 = V_2 -> V_10 -> V_100 ( V_209 ) ;
if ( V_212 . V_103 )
F_81 ( args , & V_212 , V_207 -> V_4 ) ;
if ( V_211 . V_103 )
F_81 ( args , & V_211 , V_208 -> V_4 ) ;
V_207 -> V_105 = F_34 ( V_157 [ V_212 . V_101 - 1 ] . V_105 ) ;
if ( F_61 ( V_2 , V_208 -> V_4 , V_207 -> V_4 ) )
F_59 ( args , V_207 -> V_4 , & V_212 , V_157 , 0 ,
V_208 -> V_4 , & V_211 , V_153 , 0 ,
V_212 . V_101 ) ;
else
F_59 ( args , V_207 -> V_4 , & V_212 , V_157 , 0 ,
V_208 -> V_4 , & V_211 , V_153 ,
V_211 . V_101 , V_212 . V_101 ) ;
V_208 -> V_105 = F_34 ( V_153 [ V_211 . V_101 - 1 ] . V_105 ) ;
V_2 -> V_10 -> V_109 ( V_210 , & V_211 ) ;
V_2 -> V_10 -> V_109 ( V_209 , & V_212 ) ;
F_38 ( args , V_208 -> V_4 ) ;
F_38 ( args , V_207 -> V_4 ) ;
F_39 ( V_2 , V_208 -> V_4 ) ;
F_39 ( V_2 , V_207 -> V_4 ) ;
}
int
F_82 (
T_3 * args )
{
T_17 * V_199 ;
int error ;
int V_186 ;
T_14 * V_115 ;
F_83 ( args ) ;
V_115 = F_84 () ;
V_115 -> args = args ;
V_115 -> V_22 = args -> V_2 -> V_20 ;
error = F_85 ( V_115 , & V_186 ) ;
if ( error )
V_186 = error ;
if ( V_186 != - V_133 ) {
goto V_213;
}
V_186 = F_86 ( args ,
V_115 -> V_123 ? & V_115 -> V_124 : NULL ) ;
if ( V_186 ) {
goto V_213;
}
V_199 = & V_115 -> V_202 . V_199 [ V_115 -> V_202 . V_203 - 1 ] ;
ASSERT ( V_199 -> V_12 == V_19 ) ;
V_186 = F_40 ( V_199 -> V_4 , args , V_199 -> V_91 ) ;
if ( V_186 == 0 ) {
if ( ! ( args -> V_106 & V_107 ) )
F_87 ( V_115 , & V_115 -> V_202 ) ;
} else {
if ( args -> V_184 == 0 ) {
ASSERT ( V_186 == - V_104 ) ;
goto V_213;
}
V_186 = F_88 ( V_115 ) ;
}
V_213:
F_89 ( V_115 ) ;
return V_186 ;
}
static int
F_86 (
T_3 * args ,
T_17 * V_214 )
{
T_18 * V_26 ;
T_4 V_215 ;
struct V_3 * V_187 ;
T_16 * V_134 ;
T_7 * V_2 ;
T_19 * V_216 ;
int error ;
T_4 V_46 ;
struct V_3 * V_69 ;
int V_181 ;
T_5 * free = NULL ;
T_4 V_217 ;
T_4 V_218 = 0 ;
int V_120 ;
int V_183 ;
T_15 * V_22 ;
int V_188 ;
int V_189 ;
T_6 * V_219 ;
T_11 * V_45 ;
T_6 * V_64 ;
struct V_54 V_77 ;
struct V_190 * V_191 ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_45 = args -> V_53 ;
V_120 = V_2 -> V_10 -> V_125 ( args -> V_126 ) ;
if ( V_214 ) {
V_69 = V_214 -> V_4 ;
V_217 = V_214 -> V_17 ;
free = V_69 -> V_7 ;
V_181 = V_214 -> V_91 ;
V_64 = V_2 -> V_10 -> V_65 ( free ) ;
V_2 -> V_10 -> V_80 ( & V_77 , free ) ;
if ( V_181 >= 0 ) {
ASSERT ( V_181 < V_77 . V_87 ) ;
ASSERT ( F_36 ( V_64 [ V_181 ] ) != V_85 ) ;
ASSERT ( F_36 ( V_64 [ V_181 ] ) >= V_120 ) ;
V_215 = V_77 . V_111 + V_181 ;
} else {
V_215 = - 1 ;
V_181 = 0 ;
}
} else {
V_217 = V_215 = - 1 ;
V_69 = NULL ;
V_181 = 0 ;
}
if ( V_215 == - 1 ) {
T_20 V_220 ;
if ( ( error = F_90 ( V_2 , & V_220 , V_50 ) ) )
return error ;
V_218 = F_75 ( args -> V_55 , ( T_1 ) V_220 ) ;
V_46 = V_217 ;
}
while ( V_215 == - 1 ) {
if ( V_69 == NULL ) {
if ( ++ V_46 == 0 )
V_46 = F_32 ( args -> V_55 ,
V_79 ) ;
if ( V_46 == V_217 )
V_46 ++ ;
if ( V_46 >= V_218 )
break;
error = F_20 ( V_45 , V_2 ,
F_23 ( args -> V_55 , V_46 ) ,
& V_69 ) ;
if ( error )
return error ;
if ( ! V_69 )
continue;
free = V_69 -> V_7 ;
V_181 = 0 ;
}
V_64 = V_2 -> V_10 -> V_65 ( free ) ;
V_2 -> V_10 -> V_80 ( & V_77 , free ) ;
if ( F_36 ( V_64 [ V_181 ] ) != V_85 &&
F_36 ( V_64 [ V_181 ] ) >= V_120 )
V_215 = V_77 . V_111 + V_181 ;
else {
if ( ++ V_181 == V_77 . V_87 ) {
F_51 ( V_45 , V_69 ) ;
V_69 = NULL ;
if ( V_214 && V_214 -> V_4 )
V_214 -> V_4 = NULL ;
}
}
}
if ( F_52 ( V_215 == - 1 ) ) {
if ( ( args -> V_106 & V_107 ) || args -> V_184 == 0 )
return - V_104 ;
if ( F_52 ( ( error = F_31 ( args ,
V_221 ,
& V_215 ) ) ||
( error = F_91 ( args , V_215 , & V_187 ) ) ) )
return error ;
if ( V_69 )
F_51 ( V_45 , V_69 ) ;
if ( V_214 && V_214 -> V_4 )
V_214 -> V_4 = NULL ;
V_46 = V_2 -> V_10 -> V_128 ( args -> V_55 , V_215 ) ;
error = F_20 ( V_45 , V_2 ,
F_23 ( args -> V_55 , V_46 ) ,
& V_69 ) ;
if ( error )
return error ;
if ( ! V_69 ) {
error = F_31 ( args , V_78 ,
& V_46 ) ;
if ( error )
return error ;
if ( V_2 -> V_10 -> V_128 ( args -> V_55 , V_215 ) != V_46 ) {
F_64 ( V_22 ,
L_3 ,
V_178 , ( unsigned long long ) V_2 -> V_59 ,
( long long ) V_2 -> V_10 -> V_128 (
args -> V_55 , V_215 ) ,
( long long ) V_215 , ( long long ) V_46 ,
( unsigned long long ) V_217 , V_218 ) ;
if ( V_214 ) {
F_64 ( V_22 ,
L_4 ,
V_214 ,
( unsigned long long ) V_214 -> V_17 ,
V_214 -> V_91 ,
V_214 -> V_12 ) ;
} else {
F_64 ( V_22 , L_5 ) ;
}
F_53 ( L_6 ,
V_130 , V_22 ) ;
return - V_37 ;
}
error = F_21 ( args , V_46 , & V_69 ) ;
if ( error )
return error ;
free = V_69 -> V_7 ;
V_64 = V_2 -> V_10 -> V_65 ( free ) ;
V_2 -> V_10 -> V_80 ( & V_77 , free ) ;
V_77 . V_111 =
( V_46 - F_32 ( args -> V_55 ,
V_79 ) ) *
V_2 -> V_10 -> V_112 ( args -> V_55 ) ;
} else {
free = V_69 -> V_7 ;
V_64 = V_2 -> V_10 -> V_65 ( free ) ;
V_2 -> V_10 -> V_80 ( & V_77 , free ) ;
}
V_181 = V_2 -> V_10 -> V_129 ( args -> V_55 , V_215 ) ;
if ( V_181 >= V_77 . V_87 ) {
ASSERT ( V_181 < V_2 -> V_10 -> V_112 ( args -> V_55 ) ) ;
V_77 . V_87 = V_181 + 1 ;
V_64 [ V_181 ] = F_37 ( V_85 ) ;
}
if ( V_64 [ V_181 ] == F_37 ( V_85 ) ) {
V_77 . V_86 ++ ;
V_2 -> V_10 -> V_60 ( V_69 -> V_7 , & V_77 ) ;
F_27 ( args , V_69 ) ;
}
V_26 = V_187 -> V_7 ;
V_191 = V_2 -> V_10 -> V_192 ( V_26 ) ;
V_64 [ V_181 ] = V_191 [ 0 ] . V_120 ;
V_183 = 1 ;
}
else {
if ( args -> V_106 & V_107 )
return 0 ;
error = F_55 ( V_45 , V_2 ,
F_23 ( args -> V_55 , V_215 ) ,
- 1 , & V_187 ) ;
if ( error )
return error ;
V_26 = V_187 -> V_7 ;
V_191 = V_2 -> V_10 -> V_192 ( V_26 ) ;
V_183 = 0 ;
}
ASSERT ( F_36 ( V_191 [ 0 ] . V_120 ) >= V_120 ) ;
V_216 = ( T_19 * )
( ( char * ) V_26 + F_36 ( V_191 [ 0 ] . V_222 ) ) ;
V_189 = V_188 = 0 ;
F_92 ( args , V_187 , V_216 ,
( V_223 ) ( ( char * ) V_216 - ( char * ) V_26 ) , V_120 ,
& V_188 , & V_189 ) ;
V_134 = ( T_16 * ) V_216 ;
V_134 -> V_142 = F_14 ( args -> V_142 ) ;
V_134 -> V_126 = args -> V_126 ;
memcpy ( V_134 -> V_141 , args -> V_141 , V_134 -> V_126 ) ;
V_2 -> V_10 -> V_224 ( V_134 , args -> V_143 ) ;
V_219 = V_2 -> V_10 -> V_225 ( V_134 ) ;
* V_219 = F_37 ( ( char * ) V_134 - ( char * ) V_26 ) ;
F_93 ( args , V_187 , V_134 ) ;
if ( V_189 )
F_70 ( V_2 , V_26 , & V_188 ) ;
if ( V_188 )
F_71 ( args , V_187 ) ;
V_64 = V_2 -> V_10 -> V_65 ( free ) ;
if ( F_36 ( V_64 [ V_181 ] ) != F_36 ( V_191 [ 0 ] . V_120 ) ) {
V_64 [ V_181 ] = V_191 [ 0 ] . V_120 ;
V_183 = 1 ;
}
if ( V_183 )
F_25 ( args , V_69 , V_181 , V_181 ) ;
args -> V_17 = ( T_1 ) V_215 ;
args -> V_91 = F_36 ( * V_219 ) ;
return 0 ;
}
int
F_94 (
T_3 * args )
{
int error ;
int V_72 ;
int V_186 ;
T_14 * V_115 ;
F_95 ( args ) ;
V_115 = F_84 () ;
V_115 -> args = args ;
V_115 -> V_22 = args -> V_2 -> V_20 ;
error = F_85 ( V_115 , & V_186 ) ;
if ( error )
V_186 = error ;
else if ( V_186 == - V_133 && args -> V_137 == V_226 ) {
T_16 * V_134 ;
V_134 = ( T_16 * )
( ( char * ) V_115 -> V_124 . V_4 -> V_7 +
V_115 -> V_124 . V_91 ) ;
V_186 = F_96 ( args , V_134 -> V_141 , V_134 -> V_126 ) ;
}
for ( V_72 = 0 ; V_72 < V_115 -> V_202 . V_203 ; V_72 ++ ) {
F_51 ( args -> V_53 , V_115 -> V_202 . V_199 [ V_72 ] . V_4 ) ;
V_115 -> V_202 . V_199 [ V_72 ] . V_4 = NULL ;
}
if ( V_115 -> V_123 && V_115 -> V_124 . V_4 ) {
F_51 ( args -> V_53 , V_115 -> V_124 . V_4 ) ;
V_115 -> V_124 . V_4 = NULL ;
}
F_89 ( V_115 ) ;
return V_186 ;
}
int
F_97 (
struct V_61 * args )
{
struct V_227 * V_199 ;
int error ;
int V_186 ;
struct V_228 * V_115 ;
F_98 ( args ) ;
V_115 = F_84 () ;
V_115 -> args = args ;
V_115 -> V_22 = args -> V_2 -> V_20 ;
error = F_85 ( V_115 , & V_186 ) ;
if ( error )
goto V_229;
if ( V_186 != - V_149 ) {
error = V_186 ;
goto V_229;
}
V_199 = & V_115 -> V_202 . V_199 [ V_115 -> V_202 . V_203 - 1 ] ;
ASSERT ( V_199 -> V_12 == V_19 ) ;
ASSERT ( V_115 -> V_123 ) ;
error = F_67 ( args , V_199 -> V_4 , V_199 -> V_91 ,
& V_115 -> V_124 , & V_186 ) ;
if ( error )
goto V_229;
F_87 ( V_115 , & V_115 -> V_202 ) ;
if ( V_186 && V_115 -> V_202 . V_203 > 1 )
error = F_99 ( V_115 ) ;
if ( ! error )
error = F_100 ( V_115 ) ;
V_229:
F_89 ( V_115 ) ;
return error ;
}
int
F_101 (
T_3 * args )
{
T_17 * V_199 ;
T_18 * V_26 ;
T_16 * V_134 ;
int error ;
int V_72 ;
T_21 V_230 ;
int V_231 ;
T_8 * V_6 ;
T_12 * V_94 ;
int V_186 ;
T_14 * V_115 ;
F_102 ( args ) ;
V_115 = F_84 () ;
V_115 -> args = args ;
V_115 -> V_22 = args -> V_2 -> V_20 ;
V_230 = args -> V_142 ;
V_231 = args -> V_143 ;
error = F_85 ( V_115 , & V_186 ) ;
if ( error ) {
V_186 = error ;
}
if ( V_186 == - V_149 ) {
struct V_98 * V_99 ;
V_199 = & V_115 -> V_202 . V_199 [ V_115 -> V_202 . V_203 - 1 ] ;
ASSERT ( V_199 -> V_12 == V_19 ) ;
V_6 = V_199 -> V_4 -> V_7 ;
V_99 = args -> V_2 -> V_10 -> V_100 ( V_6 ) ;
V_94 = & V_99 [ V_199 -> V_91 ] ;
ASSERT ( V_115 -> V_123 ) ;
V_26 = V_115 -> V_124 . V_4 -> V_7 ;
ASSERT ( V_26 -> V_12 == F_6 ( V_145 ) ||
V_26 -> V_12 == F_6 ( V_232 ) ) ;
V_134 = ( T_16 * )
( ( char * ) V_26 +
F_57 ( args -> V_55 ,
F_34 ( V_94 -> V_108 ) ) ) ;
ASSERT ( V_230 != F_2 ( V_134 -> V_142 ) ) ;
V_134 -> V_142 = F_14 ( V_230 ) ;
args -> V_2 -> V_10 -> V_224 ( V_134 , V_231 ) ;
F_93 ( args , V_115 -> V_124 . V_4 , V_134 ) ;
V_186 = 0 ;
}
else if ( V_115 -> V_123 ) {
F_51 ( args -> V_53 , V_115 -> V_124 . V_4 ) ;
V_115 -> V_124 . V_4 = NULL ;
}
for ( V_72 = 0 ; V_72 < V_115 -> V_202 . V_203 ; V_72 ++ ) {
F_51 ( args -> V_53 , V_115 -> V_202 . V_199 [ V_72 ] . V_4 ) ;
V_115 -> V_202 . V_199 [ V_72 ] . V_4 = NULL ;
}
F_89 ( V_115 ) ;
return V_186 ;
}
int
F_103 (
T_3 * args ,
T_20 V_220 ,
int * V_233 )
{
struct V_3 * V_4 ;
T_7 * V_2 ;
int error ;
T_5 * free ;
T_11 * V_45 ;
struct V_54 V_77 ;
V_2 = args -> V_2 ;
V_45 = args -> V_53 ;
* V_233 = 0 ;
error = F_20 ( V_45 , V_2 , V_220 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_4 )
return 0 ;
free = V_4 -> V_7 ;
V_2 -> V_10 -> V_80 ( & V_77 , free ) ;
if ( V_77 . V_86 > 0 ) {
F_51 ( V_45 , V_4 ) ;
return 0 ;
}
error = F_66 ( args ,
F_75 ( args -> V_55 , ( T_1 ) V_220 ) , V_4 ) ;
if ( error ) {
ASSERT ( error != - V_104 ) ;
F_51 ( V_45 , V_4 ) ;
return error ;
}
* V_233 = 1 ;
return 0 ;
}
