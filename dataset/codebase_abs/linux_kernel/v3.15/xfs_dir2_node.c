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
} else {
if ( V_26 -> V_12 != F_6 ( V_33 ) )
return false ;
}
return true ;
}
static void
F_8 (
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_4 -> V_23 -> V_24 ;
if ( F_5 ( & V_22 -> V_27 ) &&
! F_9 ( V_4 , V_34 ) )
F_10 ( V_4 , V_35 ) ;
else if ( ! F_4 ( V_4 ) )
F_10 ( V_4 , V_36 ) ;
if ( V_4 -> V_37 )
F_11 ( V_4 ) ;
}
static void
F_12 (
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_4 -> V_23 -> V_24 ;
struct V_38 * V_39 = V_4 -> V_40 ;
struct V_28 * V_29 = V_4 -> V_7 ;
if ( ! F_4 ( V_4 ) ) {
F_10 ( V_4 , V_36 ) ;
F_11 ( V_4 ) ;
return;
}
if ( ! F_5 ( & V_22 -> V_27 ) )
return;
if ( V_39 )
V_29 -> V_41 = F_13 ( V_39 -> V_42 . V_43 ) ;
F_14 ( V_4 , V_34 ) ;
}
static int
F_15 (
struct V_44 * V_45 ,
struct V_1 * V_2 ,
T_1 V_46 ,
T_2 V_47 ,
struct V_3 * * V_48 )
{
int V_49 ;
V_49 = F_16 ( V_45 , V_2 , V_46 , V_47 , V_48 ,
V_50 , & V_51 ) ;
if ( ! V_49 && V_45 && * V_48 )
F_17 ( V_45 , * V_48 , V_52 ) ;
return V_49 ;
}
int
F_18 (
struct V_44 * V_45 ,
struct V_1 * V_2 ,
T_1 V_46 ,
struct V_3 * * V_48 )
{
return F_15 ( V_45 , V_2 , V_46 , - 1 , V_48 ) ;
}
static int
F_19 (
struct V_44 * V_45 ,
struct V_1 * V_2 ,
T_1 V_46 ,
struct V_3 * * V_48 )
{
return F_15 ( V_45 , V_2 , V_46 , - 2 , V_48 ) ;
}
static int
F_20 (
struct V_44 * V_45 ,
struct V_1 * V_2 ,
T_3 V_46 ,
struct V_3 * * V_48 )
{
struct V_21 * V_22 = V_2 -> V_20 ;
struct V_3 * V_4 ;
int error ;
struct V_53 V_26 ;
error = F_21 ( V_45 , V_2 , F_22 ( V_22 , V_46 ) ,
- 1 , & V_4 , V_50 ) ;
if ( error )
return error ;
F_17 ( V_45 , V_4 , V_52 ) ;
V_4 -> V_54 = & V_51 ;
memset ( V_4 -> V_7 , 0 , sizeof( struct V_55 ) ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_5 ( & V_22 -> V_27 ) ) {
struct V_55 * V_29 = V_4 -> V_7 ;
V_26 . V_12 = V_30 ;
V_29 -> V_26 . V_17 = F_13 ( V_4 -> V_18 ) ;
V_29 -> V_26 . V_56 = F_13 ( V_2 -> V_57 ) ;
F_23 ( & V_29 -> V_26 . V_31 , & V_22 -> V_27 . V_32 ) ;
} else
V_26 . V_12 = V_33 ;
V_2 -> V_10 -> V_58 ( V_4 -> V_7 , & V_26 ) ;
* V_48 = V_4 ;
return 0 ;
}
STATIC void
F_24 (
struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_59 ,
int V_60 )
{
T_4 * free ;
T_5 * V_61 ;
free = V_4 -> V_7 ;
V_61 = V_2 -> V_10 -> V_62 ( free ) ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_33 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
F_25 ( V_45 , V_4 ,
( V_63 ) ( ( char * ) & V_61 [ V_59 ] - ( char * ) free ) ,
( V_63 ) ( ( char * ) & V_61 [ V_60 ] - ( char * ) free +
sizeof( V_61 [ 0 ] ) - 1 ) ) ;
}
static void
F_26 (
struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
#ifdef F_27
T_4 * free ;
free = V_4 -> V_7 ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_33 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
#endif
F_25 ( V_45 , V_4 , 0 , V_2 -> V_10 -> V_64 - 1 ) ;
}
int
F_28 (
T_6 * args ,
struct V_3 * V_65 )
{
T_7 * V_2 ;
int error ;
struct V_3 * V_66 ;
T_3 V_67 ;
T_4 * free ;
T_5 * V_68 ;
int V_69 ;
T_8 * V_6 ;
T_9 * V_70 ;
T_10 * V_22 ;
int V_71 ;
T_11 V_72 ;
T_5 * V_73 ;
T_12 * V_45 ;
struct V_53 V_74 ;
F_29 ( args ) ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_45 = args -> V_75 ;
if ( ( error = F_30 ( args , V_76 , & V_67 ) ) ) {
return error ;
}
ASSERT ( V_67 == F_31 ( V_22 ) ) ;
error = F_20 ( V_45 , V_2 , V_67 , & V_66 ) ;
if ( error )
return error ;
free = V_66 -> V_7 ;
V_2 -> V_10 -> V_77 ( & V_74 , free ) ;
V_6 = V_65 -> V_7 ;
V_70 = F_32 ( V_22 , V_6 ) ;
ASSERT ( F_33 ( V_70 -> V_78 ) <=
( V_63 ) V_2 -> V_79 . V_80 / V_22 -> V_81 ) ;
V_68 = F_34 ( V_70 ) ;
V_73 = V_2 -> V_10 -> V_62 ( free ) ;
for ( V_69 = V_71 = 0 ; V_69 < F_33 ( V_70 -> V_78 ) ; V_69 ++ , V_68 ++ , V_73 ++ ) {
if ( ( V_72 = F_35 ( * V_68 ) ) != V_82 )
V_71 ++ ;
* V_73 = F_36 ( V_72 ) ;
}
V_74 . V_83 = V_71 ;
V_74 . V_84 = F_33 ( V_70 -> V_78 ) ;
V_2 -> V_10 -> V_58 ( V_66 -> V_7 , & V_74 ) ;
F_24 ( V_45 , V_2 , V_66 , 0 , V_74 . V_84 - 1 ) ;
F_26 ( V_45 , V_2 , V_66 ) ;
if ( V_6 -> V_26 . V_16 . V_12 == F_36 ( V_85 ) )
V_6 -> V_26 . V_16 . V_12 = F_36 ( V_19 ) ;
else
V_6 -> V_26 . V_16 . V_12 = F_36 ( V_13 ) ;
V_65 -> V_54 = & V_86 ;
F_17 ( V_45 , V_65 , V_87 ) ;
F_37 ( V_45 , V_2 , V_65 ) ;
F_38 ( V_2 , V_65 ) ;
return 0 ;
}
static int
F_39 (
struct V_3 * V_4 ,
T_6 * args ,
int V_88 )
{
int V_89 ;
T_7 * V_2 ;
int V_90 ;
T_8 * V_6 ;
T_13 * V_91 ;
int V_92 ;
int V_93 ;
int V_94 ;
T_10 * V_22 ;
T_12 * V_45 ;
struct V_8 V_9 ;
struct V_95 * V_96 ;
F_40 ( args , V_88 ) ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_45 = args -> V_75 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_96 = V_2 -> V_10 -> V_97 ( V_6 ) ;
if ( V_88 < 0 )
return F_41 ( V_36 ) ;
if ( V_9 . V_98 == V_2 -> V_10 -> V_99 ( V_22 ) ) {
if ( ! V_9 . V_100 )
return F_41 ( V_101 ) ;
V_89 = V_9 . V_100 > 1 ;
} else
V_89 = 0 ;
ASSERT ( V_88 == 0 || F_33 ( V_96 [ V_88 - 1 ] . V_102 ) <= args -> V_102 ) ;
ASSERT ( V_88 == V_9 . V_98 ||
F_33 ( V_96 [ V_88 ] . V_102 ) >= args -> V_102 ) ;
if ( args -> V_103 & V_104 )
return 0 ;
if ( V_89 )
F_42 ( & V_9 , V_96 , & V_88 , & V_94 ,
& V_90 , & V_93 , & V_92 ) ;
else if ( V_9 . V_100 ) {
V_93 = V_9 . V_98 ;
V_92 = - 1 ;
}
V_91 = F_43 ( & V_9 , V_96 , V_88 , V_89 , V_94 ,
V_90 , & V_93 , & V_92 ) ;
V_91 -> V_102 = F_6 ( args -> V_102 ) ;
V_91 -> V_105 = F_6 ( F_44 ( V_22 ,
args -> V_17 , args -> V_88 ) ) ;
V_2 -> V_10 -> V_106 ( V_6 , & V_9 ) ;
F_37 ( V_45 , V_2 , V_4 ) ;
F_45 ( V_45 , V_2 , V_4 , V_93 , V_92 ) ;
F_38 ( V_2 , V_4 ) ;
return 0 ;
}
static void
F_46 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 V_107 )
{
struct V_53 V_26 ;
V_2 -> V_10 -> V_77 ( & V_26 , V_4 -> V_7 ) ;
ASSERT ( ( V_26 . V_108 % V_2 -> V_10 -> V_109 ( V_2 -> V_20 ) ) == 0 ) ;
ASSERT ( V_26 . V_108 <= V_107 ) ;
ASSERT ( V_107 < V_26 . V_108 + V_26 . V_84 ) ;
}
T_14
F_47 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int * V_98 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_95 * V_96 ;
struct V_8 V_9 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_12 == V_19 ||
V_9 . V_12 == V_13 ) ;
if ( V_98 )
* V_98 = V_9 . V_98 ;
if ( ! V_9 . V_98 )
return 0 ;
V_96 = V_2 -> V_10 -> V_97 ( V_6 ) ;
return F_33 ( V_96 [ V_9 . V_98 - 1 ] . V_102 ) ;
}
STATIC int
F_48 (
struct V_3 * V_4 ,
T_6 * args ,
int * V_110 ,
T_15 * V_111 )
{
struct V_3 * V_112 = NULL ;
T_3 V_113 = - 1 ;
T_3 V_114 = - 1 ;
T_7 * V_2 ;
int error ;
int V_115 ;
T_4 * free = NULL ;
int V_88 ;
T_8 * V_6 ;
int V_116 ;
T_13 * V_91 ;
T_10 * V_22 ;
T_3 V_117 ;
T_3 V_118 ;
T_12 * V_45 ;
struct V_95 * V_96 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_45 = args -> V_75 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_96 = V_2 -> V_10 -> V_97 ( V_6 ) ;
F_38 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_98 > 0 ) ;
V_88 = F_49 ( args , V_4 ) ;
if ( V_111 -> V_119 ) {
V_112 = V_111 -> V_120 . V_4 ;
V_114 = V_111 -> V_120 . V_17 ;
free = V_112 -> V_7 ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_33 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
}
V_116 = V_2 -> V_10 -> V_121 ( args -> V_122 ) ;
for ( V_91 = & V_96 [ V_88 ] ;
V_88 < V_9 . V_98 && F_33 ( V_91 -> V_102 ) == args -> V_102 ;
V_91 ++ , V_88 ++ ) {
if ( F_33 ( V_91 -> V_105 ) == V_123 )
continue;
V_117 = F_50 ( V_22 , F_33 ( V_91 -> V_105 ) ) ;
if ( V_117 != V_113 ) {
T_5 * V_61 ;
V_113 = V_117 ;
V_118 = V_2 -> V_10 -> V_124 ( V_22 , V_117 ) ;
if ( V_118 != V_114 ) {
if ( V_112 )
F_51 ( V_45 , V_112 ) ;
error = F_18 ( V_45 , V_2 ,
F_22 ( V_22 , V_118 ) ,
& V_112 ) ;
if ( error )
return error ;
free = V_112 -> V_7 ;
F_46 ( V_2 , V_112 , V_113 ) ;
}
V_115 = V_2 -> V_10 -> V_125 ( V_22 , V_113 ) ;
V_61 = V_2 -> V_10 -> V_62 ( free ) ;
if ( F_52 ( V_61 [ V_115 ] == F_36 ( V_82 ) ) ) {
F_53 ( L_1 ,
V_126 , V_22 ) ;
if ( V_114 != V_118 )
F_51 ( V_45 , V_112 ) ;
return F_41 ( V_36 ) ;
}
V_114 = V_118 ;
if ( F_35 ( V_61 [ V_115 ] ) >= V_116 )
goto V_127;
}
}
V_115 = - 1 ;
V_127:
ASSERT ( args -> V_103 & V_128 ) ;
if ( V_112 ) {
V_111 -> V_119 = 1 ;
V_111 -> V_120 . V_4 = V_112 ;
V_111 -> V_120 . V_88 = V_115 ;
V_111 -> V_120 . V_17 = V_114 ;
V_111 -> V_120 . V_12 = V_33 ;
} else {
V_111 -> V_119 = 0 ;
}
* V_110 = V_88 ;
return F_41 ( V_129 ) ;
}
STATIC int
F_54 (
struct V_3 * V_4 ,
T_6 * args ,
int * V_110 ,
T_15 * V_111 )
{
struct V_3 * V_112 = NULL ;
T_3 V_113 = - 1 ;
T_16 * V_130 ;
T_7 * V_2 ;
int error ;
int V_88 ;
T_8 * V_6 ;
T_13 * V_91 ;
T_10 * V_22 ;
T_3 V_117 ;
T_12 * V_45 ;
enum V_131 V_132 ;
struct V_95 * V_96 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_45 = args -> V_75 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_96 = V_2 -> V_10 -> V_97 ( V_6 ) ;
F_38 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_98 > 0 ) ;
V_88 = F_49 ( args , V_4 ) ;
if ( V_111 -> V_119 ) {
V_112 = V_111 -> V_120 . V_4 ;
V_113 = V_111 -> V_120 . V_17 ;
}
for ( V_91 = & V_96 [ V_88 ] ;
V_88 < V_9 . V_98 && F_33 ( V_91 -> V_102 ) == args -> V_102 ;
V_91 ++ , V_88 ++ ) {
if ( F_33 ( V_91 -> V_105 ) == V_123 )
continue;
V_117 = F_50 ( V_22 , F_33 ( V_91 -> V_105 ) ) ;
if ( V_117 != V_113 ) {
if ( V_112 && ( args -> V_133 == V_134 ||
V_113 != V_111 -> V_120 . V_17 ) )
F_51 ( V_45 , V_112 ) ;
if ( args -> V_133 != V_134 &&
V_117 == V_111 -> V_120 . V_17 ) {
ASSERT ( V_111 -> V_119 ) ;
V_112 = V_111 -> V_120 . V_4 ;
} else {
error = F_55 ( V_45 , V_2 ,
F_22 ( V_22 , V_117 ) ,
- 1 , & V_112 ) ;
if ( error )
return error ;
}
F_56 ( V_2 , V_112 ) ;
V_113 = V_117 ;
}
V_130 = ( T_16 * ) ( ( char * ) V_112 -> V_7 +
F_57 ( V_22 , F_33 ( V_91 -> V_105 ) ) ) ;
V_132 = V_22 -> V_135 -> V_136 ( args , V_130 -> V_137 , V_130 -> V_122 ) ;
if ( V_132 != V_134 && V_132 != args -> V_133 ) {
if ( args -> V_133 != V_134 &&
V_113 != V_111 -> V_120 . V_17 )
F_51 ( V_45 , V_111 -> V_120 . V_4 ) ;
args -> V_133 = V_132 ;
args -> V_138 = F_2 ( V_130 -> V_138 ) ;
args -> V_139 = V_2 -> V_10 -> V_140 ( V_130 ) ;
* V_110 = V_88 ;
V_111 -> V_119 = 1 ;
V_111 -> V_120 . V_4 = V_112 ;
V_111 -> V_120 . V_17 = V_113 ;
V_111 -> V_120 . V_88 = ( int ) ( ( char * ) V_130 -
( char * ) V_112 -> V_7 ) ;
V_111 -> V_120 . V_12 = V_141 ;
V_112 -> V_54 = & V_142 ;
F_17 ( V_45 , V_112 , V_143 ) ;
if ( V_132 == V_144 )
return F_41 ( V_145 ) ;
}
}
ASSERT ( V_88 == V_9 . V_98 || ( args -> V_103 & V_128 ) ) ;
if ( V_112 ) {
if ( args -> V_133 == V_134 ) {
V_111 -> V_119 = 1 ;
V_111 -> V_120 . V_4 = V_112 ;
V_111 -> V_120 . V_88 = - 1 ;
V_111 -> V_120 . V_17 = V_113 ;
V_111 -> V_120 . V_12 = V_141 ;
V_112 -> V_54 = & V_142 ;
F_17 ( V_45 , V_112 , V_143 ) ;
} else {
if ( V_111 -> V_120 . V_4 != V_112 )
F_51 ( V_45 , V_112 ) ;
}
} else {
V_111 -> V_119 = 0 ;
}
* V_110 = V_88 ;
return F_41 ( V_129 ) ;
}
int
F_58 (
struct V_3 * V_4 ,
T_6 * args ,
int * V_110 ,
T_15 * V_111 )
{
if ( args -> V_103 & V_146 )
return F_48 ( V_4 , args , V_110 ,
V_111 ) ;
return F_54 ( V_4 , args , V_110 , V_111 ) ;
}
static void
F_59 (
T_6 * args ,
struct V_3 * V_147 ,
struct V_8 * V_148 ,
struct V_95 * V_149 ,
int V_150 ,
struct V_3 * V_151 ,
struct V_8 * V_152 ,
struct V_95 * V_153 ,
int V_154 ,
int V_98 )
{
struct V_44 * V_45 = args -> V_75 ;
int V_100 ;
F_60 ( args , V_150 , V_154 , V_98 ) ;
if ( V_98 == 0 )
return;
if ( V_154 < V_152 -> V_98 ) {
memmove ( & V_153 [ V_154 + V_98 ] , & V_153 [ V_154 ] ,
( V_152 -> V_98 - V_154 ) * sizeof( T_13 ) ) ;
F_45 ( V_45 , args -> V_2 , V_151 , V_154 + V_98 ,
V_98 + V_152 -> V_98 - 1 ) ;
}
if ( V_148 -> V_100 ) {
int V_69 ;
for ( V_69 = V_150 , V_100 = 0 ; V_69 < V_150 + V_98 ; V_69 ++ ) {
if ( V_149 [ V_69 ] . V_105 ==
F_6 ( V_123 ) )
V_100 ++ ;
}
} else
V_100 = 0 ;
memcpy ( & V_153 [ V_154 ] , & V_149 [ V_150 ] ,
V_98 * sizeof( T_13 ) ) ;
F_45 ( V_45 , args -> V_2 , V_151 ,
V_154 , V_154 + V_98 - 1 ) ;
if ( V_150 + V_98 < V_148 -> V_98 ) {
memmove ( & V_149 [ V_150 ] , & V_149 [ V_150 + V_98 ] ,
V_98 * sizeof( T_13 ) ) ;
F_45 ( V_45 , args -> V_2 , V_147 ,
V_150 , V_150 + V_98 - 1 ) ;
}
V_148 -> V_98 -= V_98 ;
V_148 -> V_100 -= V_100 ;
V_152 -> V_98 += V_98 ;
V_152 -> V_100 += V_100 ;
}
int
F_61 (
struct V_1 * V_2 ,
struct V_3 * V_155 ,
struct V_3 * V_156 )
{
struct V_5 * V_157 = V_155 -> V_7 ;
struct V_5 * V_158 = V_156 -> V_7 ;
struct V_95 * V_159 ;
struct V_95 * V_160 ;
struct V_8 V_161 ;
struct V_8 V_162 ;
V_2 -> V_10 -> V_11 ( & V_161 , V_157 ) ;
V_2 -> V_10 -> V_11 ( & V_162 , V_158 ) ;
V_159 = V_2 -> V_10 -> V_97 ( V_157 ) ;
V_160 = V_2 -> V_10 -> V_97 ( V_158 ) ;
if ( V_161 . V_98 > 0 && V_162 . V_98 > 0 &&
( F_33 ( V_160 [ 0 ] . V_102 ) < F_33 ( V_159 [ 0 ] . V_102 ) ||
F_33 ( V_160 [ V_162 . V_98 - 1 ] . V_102 ) <
F_33 ( V_159 [ V_161 . V_98 - 1 ] . V_102 ) ) )
return 1 ;
return 0 ;
}
static void
F_62 (
T_15 * V_111 ,
T_17 * V_163 ,
T_17 * V_164 )
{
T_6 * args ;
int V_98 ;
int V_165 ;
T_8 * V_157 ;
T_8 * V_158 ;
int V_166 ;
#if F_63 ( F_27 ) || F_63 ( V_167 )
int V_168 ;
#endif
int V_169 ;
int V_170 ;
struct V_95 * V_159 ;
struct V_95 * V_160 ;
struct V_8 V_161 ;
struct V_8 V_162 ;
struct V_1 * V_2 = V_111 -> args -> V_2 ;
args = V_111 -> args ;
if ( ( V_170 = F_61 ( V_2 , V_163 -> V_4 , V_164 -> V_4 ) ) ) {
T_17 * V_171 ;
V_171 = V_163 ;
V_163 = V_164 ;
V_164 = V_171 ;
}
V_157 = V_163 -> V_4 -> V_7 ;
V_158 = V_164 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_161 , V_157 ) ;
V_2 -> V_10 -> V_11 ( & V_162 , V_158 ) ;
V_159 = V_2 -> V_10 -> V_97 ( V_157 ) ;
V_160 = V_2 -> V_10 -> V_97 ( V_158 ) ;
V_169 = V_161 . V_98 + V_162 . V_98 ;
#if F_63 ( F_27 ) || F_63 ( V_167 )
V_168 = V_161 . V_100 + V_162 . V_100 ;
#endif
V_166 = V_169 >> 1 ;
if ( V_169 & 1 ) {
T_14 V_172 ;
if ( V_166 >= V_161 . V_98 )
V_172 = F_33 ( V_160 [ V_166 - V_161 . V_98 ] . V_102 ) ;
else
V_172 = F_33 ( V_159 [ V_166 ] . V_102 ) ;
V_165 = args -> V_102 <= V_172 ;
}
else
V_165 = 1 ;
V_98 = V_161 . V_98 - V_166 + ( V_165 == 0 ) ;
if ( V_98 > 0 )
F_59 ( args , V_163 -> V_4 , & V_161 , V_159 ,
V_161 . V_98 - V_98 , V_164 -> V_4 ,
& V_162 , V_160 , 0 , V_98 ) ;
else if ( V_98 < 0 )
F_59 ( args , V_164 -> V_4 , & V_162 , V_160 , 0 ,
V_163 -> V_4 , & V_161 , V_159 ,
V_161 . V_98 , V_98 ) ;
ASSERT ( V_161 . V_98 + V_162 . V_98 == V_169 ) ;
ASSERT ( V_161 . V_100 + V_162 . V_100 == V_168 ) ;
V_2 -> V_10 -> V_106 ( V_157 , & V_161 ) ;
V_2 -> V_10 -> V_106 ( V_158 , & V_162 ) ;
F_37 ( args -> V_75 , V_2 , V_163 -> V_4 ) ;
F_37 ( args -> V_75 , V_2 , V_164 -> V_4 ) ;
F_38 ( V_2 , V_163 -> V_4 ) ;
F_38 ( V_2 , V_164 -> V_4 ) ;
if ( V_161 . V_98 < V_162 . V_98 )
V_111 -> V_173 = V_170 ;
else if ( V_161 . V_98 > V_162 . V_98 )
V_111 -> V_173 = ! V_170 ;
else
V_111 -> V_173 = V_170 ^ ( V_163 -> V_88 <= V_161 . V_98 ) ;
if ( ! V_111 -> V_173 )
V_164 -> V_88 = V_163 -> V_88 - V_161 . V_98 ;
if ( V_164 -> V_88 < 0 ) {
V_111 -> V_173 = 1 ;
V_164 -> V_88 = 0 ;
F_64 ( V_2 -> V_20 ,
L_2 ,
V_174 , V_163 -> V_88 ) ;
}
}
static int
F_65 (
T_6 * args ,
struct V_175 * V_26 ,
struct V_176 * free ,
T_3 V_67 ,
int V_177 ,
struct V_3 * V_66 ,
int V_178 )
{
struct V_44 * V_45 = args -> V_75 ;
int V_179 = 0 ;
T_5 * V_61 ;
struct V_53 V_74 ;
struct V_1 * V_2 = args -> V_2 ;
V_2 -> V_10 -> V_77 ( & V_74 , free ) ;
V_61 = V_2 -> V_10 -> V_62 ( free ) ;
if ( V_26 ) {
V_61 [ V_177 ] = F_36 ( V_178 ) ;
F_24 ( V_45 , V_2 , V_66 , V_177 , V_177 ) ;
return 0 ;
}
V_74 . V_83 -- ;
if ( V_177 == V_74 . V_84 - 1 ) {
int V_69 ;
for ( V_69 = V_177 - 1 ; V_69 >= 0 ; V_69 -- ) {
if ( V_61 [ V_69 ] != F_36 ( V_82 ) )
break;
}
V_74 . V_84 = V_69 + 1 ;
V_179 = 0 ;
} else {
V_61 [ V_177 ] = F_36 ( V_82 ) ;
V_179 = 1 ;
}
V_2 -> V_10 -> V_58 ( free , & V_74 ) ;
F_26 ( V_45 , V_2 , V_66 ) ;
if ( ! V_74 . V_83 ) {
int error ;
error = F_66 ( args , V_67 , V_66 ) ;
if ( error == 0 ) {
V_66 = NULL ;
V_179 = 0 ;
} else if ( error != V_101 || args -> V_180 != 0 )
return error ;
}
if ( V_179 )
F_24 ( V_45 , V_2 , V_66 , V_177 , V_177 ) ;
return 0 ;
}
static int
F_67 (
T_6 * args ,
struct V_3 * V_4 ,
int V_88 ,
T_17 * V_181 ,
int * V_182 )
{
T_18 * V_26 ;
T_3 V_107 ;
struct V_3 * V_183 ;
T_16 * V_130 ;
T_7 * V_2 ;
T_8 * V_6 ;
T_13 * V_91 ;
int V_178 ;
int V_72 ;
T_10 * V_22 ;
int V_184 ;
int V_185 ;
T_12 * V_45 ;
struct V_186 * V_187 ;
struct V_8 V_9 ;
struct V_95 * V_96 ;
F_68 ( args , V_88 ) ;
V_2 = args -> V_2 ;
V_45 = args -> V_75 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_96 = V_2 -> V_10 -> V_97 ( V_6 ) ;
V_91 = & V_96 [ V_88 ] ;
V_107 = F_50 ( V_22 , F_33 ( V_91 -> V_105 ) ) ;
ASSERT ( V_181 -> V_17 == V_107 ) ;
V_72 = F_57 ( V_22 , F_33 ( V_91 -> V_105 ) ) ;
ASSERT ( V_181 -> V_88 == V_72 ) ;
V_9 . V_100 ++ ;
V_2 -> V_10 -> V_106 ( V_6 , & V_9 ) ;
F_37 ( V_45 , V_2 , V_4 ) ;
V_91 -> V_105 = F_6 ( V_123 ) ;
F_45 ( V_45 , V_2 , V_4 , V_88 , V_88 ) ;
V_183 = V_181 -> V_4 ;
V_26 = V_183 -> V_7 ;
V_130 = ( T_16 * ) ( ( char * ) V_26 + V_72 ) ;
V_187 = V_2 -> V_10 -> V_188 ( V_26 ) ;
V_178 = F_35 ( V_187 [ 0 ] . V_116 ) ;
V_184 = V_185 = 0 ;
F_69 ( V_45 , V_2 , V_183 , V_72 ,
V_2 -> V_10 -> V_121 ( V_130 -> V_122 ) , & V_184 , & V_185 ) ;
if ( V_185 )
F_70 ( V_2 , V_26 , & V_184 ) ;
if ( V_184 )
F_71 ( V_45 , V_2 , V_183 ) ;
F_56 ( V_2 , V_183 ) ;
if ( V_178 < F_35 ( V_187 [ 0 ] . V_116 ) ) {
int error ;
struct V_3 * V_66 ;
T_3 V_67 ;
int V_177 ;
T_4 * free ;
V_67 = V_2 -> V_10 -> V_124 ( V_22 , V_107 ) ;
error = F_18 ( V_45 , V_2 , F_22 ( V_22 , V_67 ) ,
& V_66 ) ;
if ( error )
return error ;
free = V_66 -> V_7 ;
#ifdef F_27
{
struct V_53 V_74 ;
V_2 -> V_10 -> V_77 ( & V_74 , free ) ;
ASSERT ( V_74 . V_108 == V_2 -> V_10 -> V_109 ( V_22 ) *
( V_67 - F_31 ( V_22 ) ) ) ;
}
#endif
V_177 = V_2 -> V_10 -> V_125 ( V_22 , V_107 ) ;
V_178 = F_35 ( V_187 [ 0 ] . V_116 ) ;
if ( V_178 == V_22 -> V_81 -
V_2 -> V_10 -> V_189 ) {
error = F_66 ( args , V_107 , V_183 ) ;
if ( error == 0 ) {
V_181 -> V_4 = NULL ;
V_26 = NULL ;
}
else if ( ! ( error == V_101 && args -> V_180 == 0 ) )
return error ;
}
error = F_65 ( args , V_26 , free ,
V_67 , V_177 , V_66 , V_178 ) ;
if ( error )
return error ;
}
F_38 ( V_2 , V_4 ) ;
* V_182 = ( V_2 -> V_10 -> V_190 +
( V_63 ) sizeof( V_96 [ 0 ] ) * ( V_9 . V_98 - V_9 . V_100 ) ) <
V_22 -> V_191 ;
return 0 ;
}
int
F_72 (
T_15 * V_111 ,
T_17 * V_192 ,
T_17 * V_193 )
{
T_6 * args ;
T_1 V_17 ;
int error ;
T_10 * V_22 ;
struct V_1 * V_2 ;
args = V_111 -> args ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
ASSERT ( V_192 -> V_12 == V_19 ) ;
error = F_73 ( args , & V_17 ) ;
if ( error ) {
return error ;
}
error = F_74 ( args , F_75 ( V_22 , V_17 ) ,
& V_193 -> V_4 , V_19 ) ;
if ( error )
return error ;
V_193 -> V_17 = V_17 ;
V_193 -> V_12 = V_19 ;
F_62 ( V_111 , V_192 , V_193 ) ;
error = F_76 ( V_111 , V_192 , V_193 ) ;
if ( error ) {
return error ;
}
if ( V_111 -> V_173 )
error = F_39 ( V_192 -> V_4 , args , V_192 -> V_88 ) ;
else
error = F_39 ( V_193 -> V_4 , args , V_193 -> V_88 ) ;
V_192 -> V_102 = F_47 ( V_2 , V_192 -> V_4 , NULL ) ;
V_193 -> V_102 = F_47 ( V_2 , V_193 -> V_4 , NULL ) ;
F_38 ( V_2 , V_192 -> V_4 ) ;
F_38 ( V_2 , V_193 -> V_4 ) ;
return error ;
}
int
F_77 (
T_15 * V_111 ,
int * V_194 )
{
T_17 * V_195 ;
T_1 V_17 ;
struct V_3 * V_4 ;
int V_196 ;
int V_98 ;
int error ;
int V_197 ;
int V_69 ;
T_8 * V_6 ;
int V_182 ;
struct V_8 V_9 ;
struct V_95 * V_96 ;
struct V_1 * V_2 = V_111 -> args -> V_2 ;
V_195 = & V_111 -> V_198 . V_195 [ V_111 -> V_198 . V_199 - 1 ] ;
V_6 = V_195 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_96 = V_2 -> V_10 -> V_97 ( V_6 ) ;
F_38 ( V_2 , V_195 -> V_4 ) ;
V_98 = V_9 . V_98 - V_9 . V_100 ;
V_196 = V_2 -> V_10 -> V_190 + V_98 * sizeof( V_96 [ 0 ] ) ;
if ( V_196 > ( V_111 -> V_200 >> 1 ) ) {
* V_194 = 0 ;
return 0 ;
}
if ( V_98 == 0 ) {
V_197 = ( V_9 . V_201 != 0 ) ;
memcpy ( & V_111 -> V_202 , & V_111 -> V_198 , sizeof( V_111 -> V_198 ) ) ;
error = F_78 ( V_111 , & V_111 -> V_202 , V_197 , 0 ,
& V_182 ) ;
if ( error )
return error ;
* V_194 = V_182 ? 2 : 0 ;
return 0 ;
}
V_197 = V_9 . V_201 < V_9 . V_203 ;
for ( V_69 = 0 , V_4 = NULL ; V_69 < 2 ; V_197 = ! V_197 , V_69 ++ ) {
struct V_8 V_162 ;
V_17 = V_197 ? V_9 . V_201 : V_9 . V_203 ;
if ( V_17 == 0 )
continue;
error = F_79 ( V_111 -> args -> V_75 , V_2 ,
V_17 , - 1 , & V_4 ) ;
if ( error )
return error ;
V_98 = V_9 . V_98 - V_9 . V_100 ;
V_196 = V_111 -> V_200 - ( V_111 -> V_200 >> 2 ) ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_162 , V_6 ) ;
V_96 = V_2 -> V_10 -> V_97 ( V_6 ) ;
V_98 += V_162 . V_98 - V_162 . V_100 ;
V_196 -= V_98 * sizeof( V_96 [ 0 ] ) ;
if ( V_196 >= 0 )
break;
F_51 ( V_111 -> args -> V_75 , V_4 ) ;
}
if ( V_69 >= 2 ) {
* V_194 = 0 ;
return 0 ;
}
memcpy ( & V_111 -> V_202 , & V_111 -> V_198 , sizeof( V_111 -> V_198 ) ) ;
if ( V_17 < V_195 -> V_17 )
error = F_78 ( V_111 , & V_111 -> V_202 , V_197 , 0 ,
& V_182 ) ;
else
error = F_78 ( V_111 , & V_111 -> V_198 , V_197 , 0 ,
& V_182 ) ;
if ( error ) {
return error ;
}
* V_194 = V_182 ? 0 : 1 ;
return 0 ;
}
void
F_80 (
T_15 * V_111 ,
T_17 * V_204 ,
T_17 * V_205 )
{
T_6 * args ;
T_8 * V_206 ;
T_8 * V_207 ;
struct V_8 V_208 ;
struct V_8 V_209 ;
struct V_95 * V_149 ;
struct V_95 * V_153 ;
struct V_1 * V_2 = V_111 -> args -> V_2 ;
args = V_111 -> args ;
ASSERT ( V_204 -> V_12 == V_19 ) ;
ASSERT ( V_205 -> V_12 == V_19 ) ;
V_206 = V_204 -> V_4 -> V_7 ;
V_207 = V_205 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_208 , V_207 ) ;
V_2 -> V_10 -> V_11 ( & V_209 , V_206 ) ;
V_149 = V_2 -> V_10 -> V_97 ( V_207 ) ;
V_153 = V_2 -> V_10 -> V_97 ( V_206 ) ;
if ( V_209 . V_100 )
F_81 ( args , & V_209 , V_204 -> V_4 ) ;
if ( V_208 . V_100 )
F_81 ( args , & V_208 , V_205 -> V_4 ) ;
V_204 -> V_102 = F_33 ( V_153 [ V_209 . V_98 - 1 ] . V_102 ) ;
if ( F_61 ( V_2 , V_205 -> V_4 , V_204 -> V_4 ) )
F_59 ( args , V_204 -> V_4 , & V_209 , V_153 , 0 ,
V_205 -> V_4 , & V_208 , V_149 , 0 ,
V_209 . V_98 ) ;
else
F_59 ( args , V_204 -> V_4 , & V_209 , V_153 , 0 ,
V_205 -> V_4 , & V_208 , V_149 ,
V_208 . V_98 , V_209 . V_98 ) ;
V_205 -> V_102 = F_33 ( V_149 [ V_208 . V_98 - 1 ] . V_102 ) ;
V_2 -> V_10 -> V_106 ( V_207 , & V_208 ) ;
V_2 -> V_10 -> V_106 ( V_206 , & V_209 ) ;
F_37 ( args -> V_75 , V_2 , V_205 -> V_4 ) ;
F_37 ( args -> V_75 , V_2 , V_204 -> V_4 ) ;
F_38 ( V_2 , V_205 -> V_4 ) ;
F_38 ( V_2 , V_204 -> V_4 ) ;
}
int
F_82 (
T_6 * args )
{
T_17 * V_195 ;
int error ;
int V_182 ;
T_15 * V_111 ;
F_83 ( args ) ;
V_111 = F_84 () ;
V_111 -> args = args ;
V_111 -> V_22 = args -> V_2 -> V_20 ;
V_111 -> V_200 = V_111 -> V_22 -> V_81 ;
V_111 -> V_210 = V_111 -> V_22 -> V_211 ;
error = F_85 ( V_111 , & V_182 ) ;
if ( error )
V_182 = error ;
if ( V_182 != V_129 ) {
goto V_212;
}
V_182 = F_86 ( args ,
V_111 -> V_119 ? & V_111 -> V_120 : NULL ) ;
if ( V_182 ) {
goto V_212;
}
V_195 = & V_111 -> V_198 . V_195 [ V_111 -> V_198 . V_199 - 1 ] ;
ASSERT ( V_195 -> V_12 == V_19 ) ;
V_182 = F_39 ( V_195 -> V_4 , args , V_195 -> V_88 ) ;
if ( V_182 == 0 ) {
if ( ! ( args -> V_103 & V_104 ) )
F_87 ( V_111 , & V_111 -> V_198 ) ;
} else {
if ( args -> V_180 == 0 ) {
ASSERT ( V_182 == V_101 ) ;
goto V_212;
}
V_182 = F_88 ( V_111 ) ;
}
V_212:
F_89 ( V_111 ) ;
return V_182 ;
}
static int
F_86 (
T_6 * args ,
T_17 * V_213 )
{
T_18 * V_26 ;
T_3 V_214 ;
struct V_3 * V_183 ;
T_16 * V_130 ;
T_7 * V_2 ;
T_19 * V_215 ;
int error ;
T_3 V_46 ;
struct V_3 * V_66 ;
int V_177 ;
T_4 * free = NULL ;
T_3 V_216 ;
T_3 V_217 = 0 ;
int V_116 ;
int V_179 ;
T_10 * V_22 ;
int V_184 ;
int V_185 ;
T_5 * V_218 ;
T_12 * V_45 ;
T_5 * V_61 ;
struct V_53 V_74 ;
struct V_186 * V_187 ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_45 = args -> V_75 ;
V_116 = V_2 -> V_10 -> V_121 ( args -> V_122 ) ;
if ( V_213 ) {
V_66 = V_213 -> V_4 ;
V_216 = V_213 -> V_17 ;
free = V_66 -> V_7 ;
V_177 = V_213 -> V_88 ;
V_61 = V_2 -> V_10 -> V_62 ( free ) ;
V_2 -> V_10 -> V_77 ( & V_74 , free ) ;
if ( V_177 >= 0 ) {
ASSERT ( V_177 < V_74 . V_84 ) ;
ASSERT ( F_35 ( V_61 [ V_177 ] ) != V_82 ) ;
ASSERT ( F_35 ( V_61 [ V_177 ] ) >= V_116 ) ;
V_214 = V_74 . V_108 + V_177 ;
} else {
V_214 = - 1 ;
V_177 = 0 ;
}
} else {
V_216 = V_214 = - 1 ;
V_66 = NULL ;
V_177 = 0 ;
}
if ( V_214 == - 1 ) {
T_20 V_219 ;
if ( ( error = F_90 ( V_45 , V_2 , & V_219 , V_50 ) ) )
return error ;
V_217 = F_75 ( V_22 , ( T_1 ) V_219 ) ;
V_46 = V_216 ;
}
while ( V_214 == - 1 ) {
if ( V_66 == NULL ) {
if ( ++ V_46 == 0 )
V_46 = F_31 ( V_22 ) ;
if ( V_46 == V_216 )
V_46 ++ ;
if ( V_46 >= V_217 )
break;
error = F_19 ( V_45 , V_2 ,
F_22 ( V_22 , V_46 ) ,
& V_66 ) ;
if ( error )
return error ;
if ( ! V_66 )
continue;
free = V_66 -> V_7 ;
V_177 = 0 ;
}
V_61 = V_2 -> V_10 -> V_62 ( free ) ;
V_2 -> V_10 -> V_77 ( & V_74 , free ) ;
if ( F_35 ( V_61 [ V_177 ] ) != V_82 &&
F_35 ( V_61 [ V_177 ] ) >= V_116 )
V_214 = V_74 . V_108 + V_177 ;
else {
if ( ++ V_177 == V_74 . V_84 ) {
F_51 ( V_45 , V_66 ) ;
V_66 = NULL ;
if ( V_213 && V_213 -> V_4 )
V_213 -> V_4 = NULL ;
}
}
}
if ( F_52 ( V_214 == - 1 ) ) {
if ( ( args -> V_103 & V_104 ) || args -> V_180 == 0 )
return F_41 ( V_101 ) ;
if ( F_52 ( ( error = F_30 ( args ,
V_220 ,
& V_214 ) ) ||
( error = F_91 ( args , V_214 , & V_183 ) ) ) )
return error ;
if ( V_66 )
F_51 ( V_45 , V_66 ) ;
if ( V_213 && V_213 -> V_4 )
V_213 -> V_4 = NULL ;
V_46 = V_2 -> V_10 -> V_124 ( V_22 , V_214 ) ;
error = F_19 ( V_45 , V_2 ,
F_22 ( V_22 , V_46 ) ,
& V_66 ) ;
if ( error )
return error ;
if ( ! V_66 ) {
error = F_30 ( args , V_76 ,
& V_46 ) ;
if ( error )
return error ;
if ( F_52 ( V_2 -> V_10 -> V_124 ( V_22 , V_214 ) != V_46 ) ) {
F_64 ( V_22 ,
L_3
L_4 ,
V_174 , ( unsigned long long ) V_2 -> V_57 ,
( long long ) V_2 -> V_10 -> V_124 ( V_22 , V_214 ) ,
( long long ) V_214 , ( long long ) V_46 ,
( unsigned long long ) V_216 , V_217 ) ;
if ( V_213 ) {
F_64 ( V_22 ,
L_5 ,
V_213 ,
( unsigned long long ) V_213 -> V_17 ,
V_213 -> V_88 ,
V_213 -> V_12 ) ;
} else {
F_64 ( V_22 , L_6 ) ;
}
F_53 ( L_7 ,
V_126 , V_22 ) ;
return F_41 ( V_36 ) ;
}
error = F_20 ( V_45 , V_2 , V_46 , & V_66 ) ;
if ( error )
return error ;
free = V_66 -> V_7 ;
V_61 = V_2 -> V_10 -> V_62 ( free ) ;
V_2 -> V_10 -> V_77 ( & V_74 , free ) ;
V_74 . V_108 = ( V_46 - F_31 ( V_22 ) ) *
V_2 -> V_10 -> V_109 ( V_22 ) ;
} else {
free = V_66 -> V_7 ;
V_61 = V_2 -> V_10 -> V_62 ( free ) ;
V_2 -> V_10 -> V_77 ( & V_74 , free ) ;
}
V_177 = V_2 -> V_10 -> V_125 ( V_22 , V_214 ) ;
if ( V_177 >= V_74 . V_84 ) {
ASSERT ( V_177 < V_2 -> V_10 -> V_109 ( V_22 ) ) ;
V_74 . V_84 = V_177 + 1 ;
V_61 [ V_177 ] = F_36 ( V_82 ) ;
}
if ( V_61 [ V_177 ] == F_36 ( V_82 ) ) {
V_74 . V_83 ++ ;
V_2 -> V_10 -> V_58 ( V_66 -> V_7 , & V_74 ) ;
F_26 ( V_45 , V_2 , V_66 ) ;
}
V_26 = V_183 -> V_7 ;
V_187 = V_2 -> V_10 -> V_188 ( V_26 ) ;
V_61 [ V_177 ] = V_187 [ 0 ] . V_116 ;
V_179 = 1 ;
}
else {
if ( args -> V_103 & V_104 )
return 0 ;
error = F_55 ( V_45 , V_2 , F_22 ( V_22 , V_214 ) ,
- 1 , & V_183 ) ;
if ( error )
return error ;
V_26 = V_183 -> V_7 ;
V_187 = V_2 -> V_10 -> V_188 ( V_26 ) ;
V_179 = 0 ;
}
ASSERT ( F_35 ( V_187 [ 0 ] . V_116 ) >= V_116 ) ;
V_215 = ( T_19 * )
( ( char * ) V_26 + F_35 ( V_187 [ 0 ] . V_221 ) ) ;
V_185 = V_184 = 0 ;
F_92 ( V_45 , V_2 , V_183 , V_215 ,
( V_222 ) ( ( char * ) V_215 - ( char * ) V_26 ) , V_116 ,
& V_184 , & V_185 ) ;
V_130 = ( T_16 * ) V_215 ;
V_130 -> V_138 = F_13 ( args -> V_138 ) ;
V_130 -> V_122 = args -> V_122 ;
memcpy ( V_130 -> V_137 , args -> V_137 , V_130 -> V_122 ) ;
V_2 -> V_10 -> V_223 ( V_130 , args -> V_139 ) ;
V_218 = V_2 -> V_10 -> V_224 ( V_130 ) ;
* V_218 = F_36 ( ( char * ) V_130 - ( char * ) V_26 ) ;
F_93 ( V_45 , V_2 , V_183 , V_130 ) ;
if ( V_185 )
F_70 ( V_2 , V_26 , & V_184 ) ;
if ( V_184 )
F_71 ( V_45 , V_2 , V_183 ) ;
V_61 = V_2 -> V_10 -> V_62 ( free ) ;
if ( F_35 ( V_61 [ V_177 ] ) != F_35 ( V_187 [ 0 ] . V_116 ) ) {
V_61 [ V_177 ] = V_187 [ 0 ] . V_116 ;
V_179 = 1 ;
}
if ( V_179 )
F_24 ( V_45 , V_2 , V_66 , V_177 , V_177 ) ;
args -> V_17 = ( T_1 ) V_214 ;
args -> V_88 = F_35 ( * V_218 ) ;
return 0 ;
}
int
F_94 (
T_6 * args )
{
int error ;
int V_69 ;
int V_182 ;
T_15 * V_111 ;
F_95 ( args ) ;
V_111 = F_84 () ;
V_111 -> args = args ;
V_111 -> V_22 = args -> V_2 -> V_20 ;
V_111 -> V_200 = V_111 -> V_22 -> V_81 ;
V_111 -> V_210 = V_111 -> V_22 -> V_211 ;
error = F_85 ( V_111 , & V_182 ) ;
if ( error )
V_182 = error ;
else if ( V_182 == V_129 && args -> V_133 == V_225 ) {
T_16 * V_130 ;
V_130 = ( T_16 * )
( ( char * ) V_111 -> V_120 . V_4 -> V_7 +
V_111 -> V_120 . V_88 ) ;
V_182 = F_96 ( args , V_130 -> V_137 , V_130 -> V_122 ) ;
}
for ( V_69 = 0 ; V_69 < V_111 -> V_198 . V_199 ; V_69 ++ ) {
F_51 ( args -> V_75 , V_111 -> V_198 . V_195 [ V_69 ] . V_4 ) ;
V_111 -> V_198 . V_195 [ V_69 ] . V_4 = NULL ;
}
if ( V_111 -> V_119 && V_111 -> V_120 . V_4 ) {
F_51 ( args -> V_75 , V_111 -> V_120 . V_4 ) ;
V_111 -> V_120 . V_4 = NULL ;
}
F_89 ( V_111 ) ;
return V_182 ;
}
int
F_97 (
struct V_226 * args )
{
struct V_227 * V_195 ;
int error ;
int V_182 ;
struct V_228 * V_111 ;
F_98 ( args ) ;
V_111 = F_84 () ;
V_111 -> args = args ;
V_111 -> V_22 = args -> V_2 -> V_20 ;
V_111 -> V_200 = V_111 -> V_22 -> V_81 ;
V_111 -> V_210 = V_111 -> V_22 -> V_211 ;
error = F_85 ( V_111 , & V_182 ) ;
if ( error )
goto V_229;
if ( V_182 != V_145 ) {
error = V_182 ;
goto V_229;
}
V_195 = & V_111 -> V_198 . V_195 [ V_111 -> V_198 . V_199 - 1 ] ;
ASSERT ( V_195 -> V_12 == V_19 ) ;
ASSERT ( V_111 -> V_119 ) ;
error = F_67 ( args , V_195 -> V_4 , V_195 -> V_88 ,
& V_111 -> V_120 , & V_182 ) ;
if ( error )
goto V_229;
F_87 ( V_111 , & V_111 -> V_198 ) ;
if ( V_182 && V_111 -> V_198 . V_199 > 1 )
error = F_99 ( V_111 ) ;
if ( ! error )
error = F_100 ( V_111 ) ;
V_229:
F_89 ( V_111 ) ;
return error ;
}
int
F_101 (
T_6 * args )
{
T_17 * V_195 ;
T_18 * V_26 ;
T_16 * V_130 ;
int error ;
int V_69 ;
T_21 V_230 ;
T_8 * V_6 ;
T_13 * V_91 ;
int V_182 ;
T_15 * V_111 ;
F_102 ( args ) ;
V_111 = F_84 () ;
V_111 -> args = args ;
V_111 -> V_22 = args -> V_2 -> V_20 ;
V_111 -> V_200 = V_111 -> V_22 -> V_81 ;
V_111 -> V_210 = V_111 -> V_22 -> V_211 ;
V_230 = args -> V_138 ;
error = F_85 ( V_111 , & V_182 ) ;
if ( error ) {
V_182 = error ;
}
if ( V_182 == V_145 ) {
struct V_95 * V_96 ;
V_195 = & V_111 -> V_198 . V_195 [ V_111 -> V_198 . V_199 - 1 ] ;
ASSERT ( V_195 -> V_12 == V_19 ) ;
V_6 = V_195 -> V_4 -> V_7 ;
V_96 = args -> V_2 -> V_10 -> V_97 ( V_6 ) ;
V_91 = & V_96 [ V_195 -> V_88 ] ;
ASSERT ( V_111 -> V_119 ) ;
V_26 = V_111 -> V_120 . V_4 -> V_7 ;
ASSERT ( V_26 -> V_12 == F_6 ( V_141 ) ||
V_26 -> V_12 == F_6 ( V_231 ) ) ;
V_130 = ( T_16 * )
( ( char * ) V_26 +
F_57 ( V_111 -> V_22 , F_33 ( V_91 -> V_105 ) ) ) ;
ASSERT ( V_230 != F_2 ( V_130 -> V_138 ) ) ;
V_130 -> V_138 = F_13 ( V_230 ) ;
args -> V_2 -> V_10 -> V_223 ( V_130 , args -> V_139 ) ;
F_93 ( args -> V_75 , args -> V_2 ,
V_111 -> V_120 . V_4 , V_130 ) ;
V_182 = 0 ;
}
else if ( V_111 -> V_119 ) {
F_51 ( args -> V_75 , V_111 -> V_120 . V_4 ) ;
V_111 -> V_120 . V_4 = NULL ;
}
for ( V_69 = 0 ; V_69 < V_111 -> V_198 . V_199 ; V_69 ++ ) {
F_51 ( args -> V_75 , V_111 -> V_198 . V_195 [ V_69 ] . V_4 ) ;
V_111 -> V_198 . V_195 [ V_69 ] . V_4 = NULL ;
}
F_89 ( V_111 ) ;
return V_182 ;
}
int
F_103 (
T_6 * args ,
T_20 V_219 ,
int * V_232 )
{
struct V_3 * V_4 ;
T_7 * V_2 ;
int error ;
T_4 * free ;
T_10 * V_22 ;
T_12 * V_45 ;
struct V_53 V_74 ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_45 = args -> V_75 ;
error = F_19 ( V_45 , V_2 , V_219 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_4 )
return 0 ;
free = V_4 -> V_7 ;
V_2 -> V_10 -> V_77 ( & V_74 , free ) ;
if ( V_74 . V_83 > 0 ) {
F_51 ( V_45 , V_4 ) ;
* V_232 = 0 ;
return 0 ;
}
if ( ( error =
F_66 ( args , F_75 ( V_22 , ( T_1 ) V_219 ) ,
V_4 ) ) ) {
ASSERT ( error != V_101 ) ;
F_51 ( V_45 , V_4 ) ;
return error ;
}
* V_232 = 1 ;
return 0 ;
}
