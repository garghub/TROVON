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
if ( ( F_5 ( & V_22 -> V_27 ) &&
! F_9 ( V_4 -> V_7 , F_10 ( V_4 -> V_34 ) ,
V_35 ) ) ||
! F_4 ( V_4 ) ) {
F_11 ( V_36 , V_37 , V_22 , V_4 -> V_7 ) ;
F_12 ( V_4 , V_38 ) ;
}
}
static void
F_13 (
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_4 -> V_23 -> V_24 ;
struct V_39 * V_40 = V_4 -> V_41 ;
struct V_28 * V_29 = V_4 -> V_7 ;
if ( ! F_4 ( V_4 ) ) {
F_11 ( V_36 , V_37 , V_22 , V_4 -> V_7 ) ;
F_12 ( V_4 , V_38 ) ;
return;
}
if ( ! F_5 ( & V_22 -> V_27 ) )
return;
if ( V_40 )
V_29 -> V_42 = F_14 ( V_40 -> V_43 . V_44 ) ;
F_15 ( V_4 -> V_7 , F_10 ( V_4 -> V_34 ) , V_35 ) ;
}
static int
F_16 (
struct V_45 * V_46 ,
struct V_1 * V_2 ,
T_1 V_47 ,
T_2 V_48 ,
struct V_3 * * V_49 )
{
int V_50 ;
V_50 = F_17 ( V_46 , V_2 , V_47 , V_48 , V_49 ,
V_51 , & V_52 ) ;
if ( ! V_50 && V_46 && * V_49 )
F_18 ( V_46 , * V_49 , V_53 ) ;
return V_50 ;
}
int
F_19 (
struct V_45 * V_46 ,
struct V_1 * V_2 ,
T_1 V_47 ,
struct V_3 * * V_49 )
{
return F_16 ( V_46 , V_2 , V_47 , - 1 , V_49 ) ;
}
static int
F_20 (
struct V_45 * V_46 ,
struct V_1 * V_2 ,
T_1 V_47 ,
struct V_3 * * V_49 )
{
return F_16 ( V_46 , V_2 , V_47 , - 2 , V_49 ) ;
}
static int
F_21 (
struct V_45 * V_46 ,
struct V_1 * V_2 ,
T_3 V_47 ,
struct V_3 * * V_49 )
{
struct V_21 * V_22 = V_2 -> V_20 ;
struct V_3 * V_4 ;
int error ;
struct V_54 V_26 ;
error = F_22 ( V_46 , V_2 , F_23 ( V_22 , V_47 ) ,
- 1 , & V_4 , V_51 ) ;
if ( error )
return error ;
F_18 ( V_46 , V_4 , V_53 ) ;
V_4 -> V_55 = & V_52 ;
memset ( V_4 -> V_7 , 0 , sizeof( struct V_56 ) ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_5 ( & V_22 -> V_27 ) ) {
struct V_56 * V_29 = V_4 -> V_7 ;
V_26 . V_12 = V_30 ;
V_29 -> V_26 . V_17 = F_14 ( V_4 -> V_18 ) ;
V_29 -> V_26 . V_57 = F_14 ( V_2 -> V_58 ) ;
F_24 ( & V_29 -> V_26 . V_31 , & V_22 -> V_27 . V_32 ) ;
} else
V_26 . V_12 = V_33 ;
V_2 -> V_10 -> V_59 ( V_4 -> V_7 , & V_26 ) ;
* V_49 = V_4 ;
return 0 ;
}
STATIC void
F_25 (
struct V_45 * V_46 ,
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_60 ,
int V_61 )
{
T_4 * free ;
T_5 * V_62 ;
free = V_4 -> V_7 ;
V_62 = V_2 -> V_10 -> V_63 ( free ) ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_33 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
F_26 ( V_46 , V_4 ,
( V_64 ) ( ( char * ) & V_62 [ V_60 ] - ( char * ) free ) ,
( V_64 ) ( ( char * ) & V_62 [ V_61 ] - ( char * ) free +
sizeof( V_62 [ 0 ] ) - 1 ) ) ;
}
static void
F_27 (
struct V_45 * V_46 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
#ifdef F_28
T_4 * free ;
free = V_4 -> V_7 ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_33 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
#endif
F_26 ( V_46 , V_4 , 0 , V_2 -> V_10 -> V_65 - 1 ) ;
}
int
F_29 (
T_6 * args ,
struct V_3 * V_66 )
{
T_7 * V_2 ;
int error ;
struct V_3 * V_67 ;
T_3 V_68 ;
T_4 * free ;
T_5 * V_69 ;
int V_70 ;
T_8 * V_6 ;
T_9 * V_71 ;
T_10 * V_22 ;
int V_72 ;
T_11 V_73 ;
T_5 * V_74 ;
T_12 * V_46 ;
struct V_54 V_75 ;
F_30 ( args ) ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_46 = args -> V_76 ;
if ( ( error = F_31 ( args , V_77 , & V_68 ) ) ) {
return error ;
}
ASSERT ( V_68 == F_32 ( V_22 ) ) ;
error = F_21 ( V_46 , V_2 , V_68 , & V_67 ) ;
if ( error )
return error ;
free = V_67 -> V_7 ;
V_2 -> V_10 -> V_78 ( & V_75 , free ) ;
V_6 = V_66 -> V_7 ;
V_71 = F_33 ( V_22 , V_6 ) ;
ASSERT ( F_34 ( V_71 -> V_79 ) <=
( V_64 ) V_2 -> V_80 . V_81 / V_22 -> V_82 ) ;
V_69 = F_35 ( V_71 ) ;
V_74 = V_2 -> V_10 -> V_63 ( free ) ;
for ( V_70 = V_72 = 0 ; V_70 < F_34 ( V_71 -> V_79 ) ; V_70 ++ , V_69 ++ , V_74 ++ ) {
if ( ( V_73 = F_36 ( * V_69 ) ) != V_83 )
V_72 ++ ;
* V_74 = F_37 ( V_73 ) ;
}
V_75 . V_84 = V_72 ;
V_75 . V_85 = F_34 ( V_71 -> V_79 ) ;
V_2 -> V_10 -> V_59 ( V_67 -> V_7 , & V_75 ) ;
F_25 ( V_46 , V_2 , V_67 , 0 , V_75 . V_85 - 1 ) ;
F_27 ( V_46 , V_2 , V_67 ) ;
if ( V_6 -> V_26 . V_16 . V_12 == F_37 ( V_86 ) )
V_6 -> V_26 . V_16 . V_12 = F_37 ( V_19 ) ;
else
V_6 -> V_26 . V_16 . V_12 = F_37 ( V_13 ) ;
V_66 -> V_55 = & V_87 ;
F_18 ( V_46 , V_66 , V_88 ) ;
F_38 ( V_46 , V_2 , V_66 ) ;
F_39 ( V_2 , V_66 ) ;
return 0 ;
}
static int
F_40 (
struct V_3 * V_4 ,
T_6 * args ,
int V_89 )
{
int V_90 ;
T_7 * V_2 ;
int V_91 ;
T_8 * V_6 ;
T_13 * V_92 ;
int V_93 ;
int V_94 ;
int V_95 ;
T_10 * V_22 ;
T_12 * V_46 ;
struct V_8 V_9 ;
struct V_96 * V_97 ;
F_41 ( args , V_89 ) ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_46 = args -> V_76 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_97 = V_2 -> V_10 -> V_98 ( V_6 ) ;
if ( V_89 < 0 )
return F_42 ( V_38 ) ;
if ( V_9 . V_99 == V_2 -> V_10 -> V_100 ( V_22 ) ) {
if ( ! V_9 . V_101 )
return F_42 ( V_102 ) ;
V_90 = V_9 . V_101 > 1 ;
} else
V_90 = 0 ;
ASSERT ( V_89 == 0 || F_34 ( V_97 [ V_89 - 1 ] . V_103 ) <= args -> V_103 ) ;
ASSERT ( V_89 == V_9 . V_99 ||
F_34 ( V_97 [ V_89 ] . V_103 ) >= args -> V_103 ) ;
if ( args -> V_104 & V_105 )
return 0 ;
if ( V_90 )
F_43 ( & V_9 , V_97 , & V_89 , & V_95 ,
& V_91 , & V_94 , & V_93 ) ;
else if ( V_9 . V_101 ) {
V_94 = V_9 . V_99 ;
V_93 = - 1 ;
}
V_92 = F_44 ( & V_9 , V_97 , V_89 , V_90 , V_95 ,
V_91 , & V_94 , & V_93 ) ;
V_92 -> V_103 = F_6 ( args -> V_103 ) ;
V_92 -> V_106 = F_6 ( F_45 ( V_22 ,
args -> V_17 , args -> V_89 ) ) ;
V_2 -> V_10 -> V_107 ( V_6 , & V_9 ) ;
F_38 ( V_46 , V_2 , V_4 ) ;
F_46 ( V_46 , V_2 , V_4 , V_94 , V_93 ) ;
F_39 ( V_2 , V_4 ) ;
return 0 ;
}
static void
F_47 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 V_108 )
{
struct V_54 V_26 ;
V_2 -> V_10 -> V_78 ( & V_26 , V_4 -> V_7 ) ;
ASSERT ( ( V_26 . V_109 % V_2 -> V_10 -> V_110 ( V_2 -> V_20 ) ) == 0 ) ;
ASSERT ( V_26 . V_109 <= V_108 ) ;
ASSERT ( V_108 < V_26 . V_109 + V_26 . V_85 ) ;
}
T_14
F_48 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int * V_99 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_96 * V_97 ;
struct V_8 V_9 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_12 == V_19 ||
V_9 . V_12 == V_13 ) ;
if ( V_99 )
* V_99 = V_9 . V_99 ;
if ( ! V_9 . V_99 )
return 0 ;
V_97 = V_2 -> V_10 -> V_98 ( V_6 ) ;
return F_34 ( V_97 [ V_9 . V_99 - 1 ] . V_103 ) ;
}
STATIC int
F_49 (
struct V_3 * V_4 ,
T_6 * args ,
int * V_111 ,
T_15 * V_112 )
{
struct V_3 * V_113 = NULL ;
T_3 V_114 = - 1 ;
T_3 V_115 = - 1 ;
T_7 * V_2 ;
int error ;
int V_116 ;
T_4 * free = NULL ;
int V_89 ;
T_8 * V_6 ;
int V_117 ;
T_13 * V_92 ;
T_10 * V_22 ;
T_3 V_118 ;
T_3 V_119 ;
T_12 * V_46 ;
struct V_96 * V_97 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_46 = args -> V_76 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_97 = V_2 -> V_10 -> V_98 ( V_6 ) ;
F_39 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_99 > 0 ) ;
V_89 = F_50 ( args , V_4 ) ;
if ( V_112 -> V_120 ) {
V_113 = V_112 -> V_121 . V_4 ;
V_115 = V_112 -> V_121 . V_17 ;
free = V_113 -> V_7 ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_33 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
}
V_117 = V_2 -> V_10 -> V_122 ( args -> V_123 ) ;
for ( V_92 = & V_97 [ V_89 ] ;
V_89 < V_9 . V_99 && F_34 ( V_92 -> V_103 ) == args -> V_103 ;
V_92 ++ , V_89 ++ ) {
if ( F_34 ( V_92 -> V_106 ) == V_124 )
continue;
V_118 = F_51 ( V_22 , F_34 ( V_92 -> V_106 ) ) ;
if ( V_118 != V_114 ) {
T_5 * V_62 ;
V_114 = V_118 ;
V_119 = V_2 -> V_10 -> V_125 ( V_22 , V_118 ) ;
if ( V_119 != V_115 ) {
if ( V_113 )
F_52 ( V_46 , V_113 ) ;
error = F_19 ( V_46 , V_2 ,
F_23 ( V_22 , V_119 ) ,
& V_113 ) ;
if ( error )
return error ;
free = V_113 -> V_7 ;
F_47 ( V_2 , V_113 , V_114 ) ;
}
V_116 = V_2 -> V_10 -> V_126 ( V_22 , V_114 ) ;
V_62 = V_2 -> V_10 -> V_63 ( free ) ;
if ( F_53 ( V_62 [ V_116 ] == F_37 ( V_83 ) ) ) {
F_54 ( L_1 ,
V_37 , V_22 ) ;
if ( V_115 != V_119 )
F_52 ( V_46 , V_113 ) ;
return F_42 ( V_38 ) ;
}
V_115 = V_119 ;
if ( F_36 ( V_62 [ V_116 ] ) >= V_117 )
goto V_127;
}
}
V_116 = - 1 ;
V_127:
ASSERT ( args -> V_104 & V_128 ) ;
if ( V_113 ) {
V_112 -> V_120 = 1 ;
V_112 -> V_121 . V_4 = V_113 ;
V_112 -> V_121 . V_89 = V_116 ;
V_112 -> V_121 . V_17 = V_115 ;
V_112 -> V_121 . V_12 = V_33 ;
} else {
V_112 -> V_120 = 0 ;
}
* V_111 = V_89 ;
return F_42 ( V_129 ) ;
}
STATIC int
F_55 (
struct V_3 * V_4 ,
T_6 * args ,
int * V_111 ,
T_15 * V_112 )
{
struct V_3 * V_113 = NULL ;
T_3 V_114 = - 1 ;
T_16 * V_130 ;
T_7 * V_2 ;
int error ;
int V_89 ;
T_8 * V_6 ;
T_13 * V_92 ;
T_10 * V_22 ;
T_3 V_118 ;
T_12 * V_46 ;
enum V_131 V_132 ;
struct V_96 * V_97 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_46 = args -> V_76 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_97 = V_2 -> V_10 -> V_98 ( V_6 ) ;
F_39 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_99 > 0 ) ;
V_89 = F_50 ( args , V_4 ) ;
if ( V_112 -> V_120 ) {
V_113 = V_112 -> V_121 . V_4 ;
V_114 = V_112 -> V_121 . V_17 ;
}
for ( V_92 = & V_97 [ V_89 ] ;
V_89 < V_9 . V_99 && F_34 ( V_92 -> V_103 ) == args -> V_103 ;
V_92 ++ , V_89 ++ ) {
if ( F_34 ( V_92 -> V_106 ) == V_124 )
continue;
V_118 = F_51 ( V_22 , F_34 ( V_92 -> V_106 ) ) ;
if ( V_118 != V_114 ) {
if ( V_113 && ( args -> V_133 == V_134 ||
V_114 != V_112 -> V_121 . V_17 ) )
F_52 ( V_46 , V_113 ) ;
if ( args -> V_133 != V_134 &&
V_118 == V_112 -> V_121 . V_17 ) {
ASSERT ( V_112 -> V_120 ) ;
V_113 = V_112 -> V_121 . V_4 ;
} else {
error = F_56 ( V_46 , V_2 ,
F_23 ( V_22 , V_118 ) ,
- 1 , & V_113 ) ;
if ( error )
return error ;
}
F_57 ( V_2 , V_113 ) ;
V_114 = V_118 ;
}
V_130 = ( T_16 * ) ( ( char * ) V_113 -> V_7 +
F_58 ( V_22 , F_34 ( V_92 -> V_106 ) ) ) ;
V_132 = V_22 -> V_135 -> V_136 ( args , V_130 -> V_137 , V_130 -> V_123 ) ;
if ( V_132 != V_134 && V_132 != args -> V_133 ) {
if ( args -> V_133 != V_134 &&
V_114 != V_112 -> V_121 . V_17 )
F_52 ( V_46 , V_112 -> V_121 . V_4 ) ;
args -> V_133 = V_132 ;
args -> V_138 = F_2 ( V_130 -> V_138 ) ;
args -> V_139 = V_2 -> V_10 -> V_140 ( V_130 ) ;
* V_111 = V_89 ;
V_112 -> V_120 = 1 ;
V_112 -> V_121 . V_4 = V_113 ;
V_112 -> V_121 . V_17 = V_114 ;
V_112 -> V_121 . V_89 = ( int ) ( ( char * ) V_130 -
( char * ) V_113 -> V_7 ) ;
V_112 -> V_121 . V_12 = V_141 ;
V_113 -> V_55 = & V_142 ;
F_18 ( V_46 , V_113 , V_143 ) ;
if ( V_132 == V_144 )
return F_42 ( V_145 ) ;
}
}
ASSERT ( V_89 == V_9 . V_99 || ( args -> V_104 & V_128 ) ) ;
if ( V_113 ) {
if ( args -> V_133 == V_134 ) {
V_112 -> V_120 = 1 ;
V_112 -> V_121 . V_4 = V_113 ;
V_112 -> V_121 . V_89 = - 1 ;
V_112 -> V_121 . V_17 = V_114 ;
V_112 -> V_121 . V_12 = V_141 ;
V_113 -> V_55 = & V_142 ;
F_18 ( V_46 , V_113 , V_143 ) ;
} else {
if ( V_112 -> V_121 . V_4 != V_113 )
F_52 ( V_46 , V_113 ) ;
}
} else {
V_112 -> V_120 = 0 ;
}
* V_111 = V_89 ;
return F_42 ( V_129 ) ;
}
int
F_59 (
struct V_3 * V_4 ,
T_6 * args ,
int * V_111 ,
T_15 * V_112 )
{
if ( args -> V_104 & V_146 )
return F_49 ( V_4 , args , V_111 ,
V_112 ) ;
return F_55 ( V_4 , args , V_111 , V_112 ) ;
}
static void
F_60 (
T_6 * args ,
struct V_3 * V_147 ,
struct V_8 * V_148 ,
struct V_96 * V_149 ,
int V_150 ,
struct V_3 * V_151 ,
struct V_8 * V_152 ,
struct V_96 * V_153 ,
int V_154 ,
int V_99 )
{
struct V_45 * V_46 = args -> V_76 ;
int V_101 ;
F_61 ( args , V_150 , V_154 , V_99 ) ;
if ( V_99 == 0 )
return;
if ( V_154 < V_152 -> V_99 ) {
memmove ( & V_153 [ V_154 + V_99 ] , & V_153 [ V_154 ] ,
( V_152 -> V_99 - V_154 ) * sizeof( T_13 ) ) ;
F_46 ( V_46 , args -> V_2 , V_151 , V_154 + V_99 ,
V_99 + V_152 -> V_99 - 1 ) ;
}
if ( V_148 -> V_101 ) {
int V_70 ;
for ( V_70 = V_150 , V_101 = 0 ; V_70 < V_150 + V_99 ; V_70 ++ ) {
if ( V_149 [ V_70 ] . V_106 ==
F_6 ( V_124 ) )
V_101 ++ ;
}
} else
V_101 = 0 ;
memcpy ( & V_153 [ V_154 ] , & V_149 [ V_150 ] ,
V_99 * sizeof( T_13 ) ) ;
F_46 ( V_46 , args -> V_2 , V_151 ,
V_154 , V_154 + V_99 - 1 ) ;
if ( V_150 + V_99 < V_148 -> V_99 ) {
memmove ( & V_149 [ V_150 ] , & V_149 [ V_150 + V_99 ] ,
V_99 * sizeof( T_13 ) ) ;
F_46 ( V_46 , args -> V_2 , V_147 ,
V_150 , V_150 + V_99 - 1 ) ;
}
V_148 -> V_99 -= V_99 ;
V_148 -> V_101 -= V_101 ;
V_152 -> V_99 += V_99 ;
V_152 -> V_101 += V_101 ;
}
int
F_62 (
struct V_1 * V_2 ,
struct V_3 * V_155 ,
struct V_3 * V_156 )
{
struct V_5 * V_157 = V_155 -> V_7 ;
struct V_5 * V_158 = V_156 -> V_7 ;
struct V_96 * V_159 ;
struct V_96 * V_160 ;
struct V_8 V_161 ;
struct V_8 V_162 ;
V_2 -> V_10 -> V_11 ( & V_161 , V_157 ) ;
V_2 -> V_10 -> V_11 ( & V_162 , V_158 ) ;
V_159 = V_2 -> V_10 -> V_98 ( V_157 ) ;
V_160 = V_2 -> V_10 -> V_98 ( V_158 ) ;
if ( V_161 . V_99 > 0 && V_162 . V_99 > 0 &&
( F_34 ( V_160 [ 0 ] . V_103 ) < F_34 ( V_159 [ 0 ] . V_103 ) ||
F_34 ( V_160 [ V_162 . V_99 - 1 ] . V_103 ) <
F_34 ( V_159 [ V_161 . V_99 - 1 ] . V_103 ) ) )
return 1 ;
return 0 ;
}
static void
F_63 (
T_15 * V_112 ,
T_17 * V_163 ,
T_17 * V_164 )
{
T_6 * args ;
int V_99 ;
int V_165 ;
T_8 * V_157 ;
T_8 * V_158 ;
int V_166 ;
#if F_64 ( F_28 ) || F_64 ( V_167 )
int V_168 ;
#endif
int V_169 ;
int V_170 ;
struct V_96 * V_159 ;
struct V_96 * V_160 ;
struct V_8 V_161 ;
struct V_8 V_162 ;
struct V_1 * V_2 = V_112 -> args -> V_2 ;
args = V_112 -> args ;
if ( ( V_170 = F_62 ( V_2 , V_163 -> V_4 , V_164 -> V_4 ) ) ) {
T_17 * V_171 ;
V_171 = V_163 ;
V_163 = V_164 ;
V_164 = V_171 ;
}
V_157 = V_163 -> V_4 -> V_7 ;
V_158 = V_164 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_161 , V_157 ) ;
V_2 -> V_10 -> V_11 ( & V_162 , V_158 ) ;
V_159 = V_2 -> V_10 -> V_98 ( V_157 ) ;
V_160 = V_2 -> V_10 -> V_98 ( V_158 ) ;
V_169 = V_161 . V_99 + V_162 . V_99 ;
#if F_64 ( F_28 ) || F_64 ( V_167 )
V_168 = V_161 . V_101 + V_162 . V_101 ;
#endif
V_166 = V_169 >> 1 ;
if ( V_169 & 1 ) {
T_14 V_172 ;
if ( V_166 >= V_161 . V_99 )
V_172 = F_34 ( V_160 [ V_166 - V_161 . V_99 ] . V_103 ) ;
else
V_172 = F_34 ( V_159 [ V_166 ] . V_103 ) ;
V_165 = args -> V_103 <= V_172 ;
}
else
V_165 = 1 ;
V_99 = V_161 . V_99 - V_166 + ( V_165 == 0 ) ;
if ( V_99 > 0 )
F_60 ( args , V_163 -> V_4 , & V_161 , V_159 ,
V_161 . V_99 - V_99 , V_164 -> V_4 ,
& V_162 , V_160 , 0 , V_99 ) ;
else if ( V_99 < 0 )
F_60 ( args , V_164 -> V_4 , & V_162 , V_160 , 0 ,
V_163 -> V_4 , & V_161 , V_159 ,
V_161 . V_99 , V_99 ) ;
ASSERT ( V_161 . V_99 + V_162 . V_99 == V_169 ) ;
ASSERT ( V_161 . V_101 + V_162 . V_101 == V_168 ) ;
V_2 -> V_10 -> V_107 ( V_157 , & V_161 ) ;
V_2 -> V_10 -> V_107 ( V_158 , & V_162 ) ;
F_38 ( args -> V_76 , V_2 , V_163 -> V_4 ) ;
F_38 ( args -> V_76 , V_2 , V_164 -> V_4 ) ;
F_39 ( V_2 , V_163 -> V_4 ) ;
F_39 ( V_2 , V_164 -> V_4 ) ;
if ( V_161 . V_99 < V_162 . V_99 )
V_112 -> V_173 = V_170 ;
else if ( V_161 . V_99 > V_162 . V_99 )
V_112 -> V_173 = ! V_170 ;
else
V_112 -> V_173 = V_170 ^ ( V_163 -> V_89 <= V_161 . V_99 ) ;
if ( ! V_112 -> V_173 )
V_164 -> V_89 = V_163 -> V_89 - V_161 . V_99 ;
if ( V_164 -> V_89 < 0 ) {
V_112 -> V_173 = 1 ;
V_164 -> V_89 = 0 ;
F_65 ( V_2 -> V_20 ,
L_2 ,
V_36 , V_163 -> V_89 ) ;
}
}
static int
F_66 (
T_6 * args ,
struct V_174 * V_26 ,
struct V_175 * free ,
T_3 V_68 ,
int V_176 ,
struct V_3 * V_67 ,
int V_177 )
{
struct V_45 * V_46 = args -> V_76 ;
int V_178 = 0 ;
T_5 * V_62 ;
struct V_54 V_75 ;
struct V_1 * V_2 = args -> V_2 ;
V_2 -> V_10 -> V_78 ( & V_75 , free ) ;
V_62 = V_2 -> V_10 -> V_63 ( free ) ;
if ( V_26 ) {
V_62 [ V_176 ] = F_37 ( V_177 ) ;
F_25 ( V_46 , V_2 , V_67 , V_176 , V_176 ) ;
return 0 ;
}
V_75 . V_84 -- ;
if ( V_176 == V_75 . V_85 - 1 ) {
int V_70 ;
for ( V_70 = V_176 - 1 ; V_70 >= 0 ; V_70 -- ) {
if ( V_62 [ V_70 ] != F_37 ( V_83 ) )
break;
}
V_75 . V_85 = V_70 + 1 ;
V_178 = 0 ;
} else {
V_62 [ V_176 ] = F_37 ( V_83 ) ;
V_178 = 1 ;
}
V_2 -> V_10 -> V_59 ( free , & V_75 ) ;
F_27 ( V_46 , V_2 , V_67 ) ;
if ( ! V_75 . V_84 ) {
int error ;
error = F_67 ( args , V_68 , V_67 ) ;
if ( error == 0 ) {
V_67 = NULL ;
V_178 = 0 ;
} else if ( error != V_102 || args -> V_179 != 0 )
return error ;
}
if ( V_178 )
F_25 ( V_46 , V_2 , V_67 , V_176 , V_176 ) ;
return 0 ;
}
static int
F_68 (
T_6 * args ,
struct V_3 * V_4 ,
int V_89 ,
T_17 * V_180 ,
int * V_181 )
{
T_18 * V_26 ;
T_3 V_108 ;
struct V_3 * V_182 ;
T_16 * V_130 ;
T_7 * V_2 ;
T_8 * V_6 ;
T_13 * V_92 ;
int V_177 ;
int V_73 ;
T_10 * V_22 ;
int V_183 ;
int V_184 ;
T_12 * V_46 ;
struct V_185 * V_186 ;
struct V_8 V_9 ;
struct V_96 * V_97 ;
F_69 ( args , V_89 ) ;
V_2 = args -> V_2 ;
V_46 = args -> V_76 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_97 = V_2 -> V_10 -> V_98 ( V_6 ) ;
V_92 = & V_97 [ V_89 ] ;
V_108 = F_51 ( V_22 , F_34 ( V_92 -> V_106 ) ) ;
ASSERT ( V_180 -> V_17 == V_108 ) ;
V_73 = F_58 ( V_22 , F_34 ( V_92 -> V_106 ) ) ;
ASSERT ( V_180 -> V_89 == V_73 ) ;
V_9 . V_101 ++ ;
V_2 -> V_10 -> V_107 ( V_6 , & V_9 ) ;
F_38 ( V_46 , V_2 , V_4 ) ;
V_92 -> V_106 = F_6 ( V_124 ) ;
F_46 ( V_46 , V_2 , V_4 , V_89 , V_89 ) ;
V_182 = V_180 -> V_4 ;
V_26 = V_182 -> V_7 ;
V_130 = ( T_16 * ) ( ( char * ) V_26 + V_73 ) ;
V_186 = V_2 -> V_10 -> V_187 ( V_26 ) ;
V_177 = F_36 ( V_186 [ 0 ] . V_117 ) ;
V_183 = V_184 = 0 ;
F_70 ( V_46 , V_2 , V_182 , V_73 ,
V_2 -> V_10 -> V_122 ( V_130 -> V_123 ) , & V_183 , & V_184 ) ;
if ( V_184 )
F_71 ( V_2 , V_26 , & V_183 ) ;
if ( V_183 )
F_72 ( V_46 , V_2 , V_182 ) ;
F_57 ( V_2 , V_182 ) ;
if ( V_177 < F_36 ( V_186 [ 0 ] . V_117 ) ) {
int error ;
struct V_3 * V_67 ;
T_3 V_68 ;
int V_176 ;
T_4 * free ;
V_68 = V_2 -> V_10 -> V_125 ( V_22 , V_108 ) ;
error = F_19 ( V_46 , V_2 , F_23 ( V_22 , V_68 ) ,
& V_67 ) ;
if ( error )
return error ;
free = V_67 -> V_7 ;
#ifdef F_28
{
struct V_54 V_75 ;
V_2 -> V_10 -> V_78 ( & V_75 , free ) ;
ASSERT ( V_75 . V_109 == V_2 -> V_10 -> V_110 ( V_22 ) *
( V_68 - F_32 ( V_22 ) ) ) ;
}
#endif
V_176 = V_2 -> V_10 -> V_126 ( V_22 , V_108 ) ;
V_177 = F_36 ( V_186 [ 0 ] . V_117 ) ;
if ( V_177 == V_22 -> V_82 -
V_2 -> V_10 -> V_188 ) {
error = F_67 ( args , V_108 , V_182 ) ;
if ( error == 0 ) {
V_180 -> V_4 = NULL ;
V_26 = NULL ;
}
else if ( ! ( error == V_102 && args -> V_179 == 0 ) )
return error ;
}
error = F_66 ( args , V_26 , free ,
V_68 , V_176 , V_67 , V_177 ) ;
if ( error )
return error ;
}
F_39 ( V_2 , V_4 ) ;
* V_181 = ( V_2 -> V_10 -> V_189 +
( V_64 ) sizeof( V_97 [ 0 ] ) * ( V_9 . V_99 - V_9 . V_101 ) ) <
V_22 -> V_190 ;
return 0 ;
}
int
F_73 (
T_15 * V_112 ,
T_17 * V_191 ,
T_17 * V_192 )
{
T_6 * args ;
T_1 V_17 ;
int error ;
T_10 * V_22 ;
struct V_1 * V_2 ;
args = V_112 -> args ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
ASSERT ( V_191 -> V_12 == V_19 ) ;
error = F_74 ( args , & V_17 ) ;
if ( error ) {
return error ;
}
error = F_75 ( args , F_76 ( V_22 , V_17 ) ,
& V_192 -> V_4 , V_19 ) ;
if ( error )
return error ;
V_192 -> V_17 = V_17 ;
V_192 -> V_12 = V_19 ;
F_63 ( V_112 , V_191 , V_192 ) ;
error = F_77 ( V_112 , V_191 , V_192 ) ;
if ( error ) {
return error ;
}
if ( V_112 -> V_173 )
error = F_40 ( V_191 -> V_4 , args , V_191 -> V_89 ) ;
else
error = F_40 ( V_192 -> V_4 , args , V_192 -> V_89 ) ;
V_191 -> V_103 = F_48 ( V_2 , V_191 -> V_4 , NULL ) ;
V_192 -> V_103 = F_48 ( V_2 , V_192 -> V_4 , NULL ) ;
F_39 ( V_2 , V_191 -> V_4 ) ;
F_39 ( V_2 , V_192 -> V_4 ) ;
return error ;
}
int
F_78 (
T_15 * V_112 ,
int * V_193 )
{
T_17 * V_194 ;
T_1 V_17 ;
struct V_3 * V_4 ;
int V_195 ;
int V_99 ;
int error ;
int V_196 ;
int V_70 ;
T_8 * V_6 ;
int V_181 ;
struct V_8 V_9 ;
struct V_96 * V_97 ;
struct V_1 * V_2 = V_112 -> args -> V_2 ;
V_194 = & V_112 -> V_197 . V_194 [ V_112 -> V_197 . V_198 - 1 ] ;
V_6 = V_194 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_97 = V_2 -> V_10 -> V_98 ( V_6 ) ;
F_39 ( V_2 , V_194 -> V_4 ) ;
V_99 = V_9 . V_99 - V_9 . V_101 ;
V_195 = V_2 -> V_10 -> V_189 + V_99 * sizeof( V_97 [ 0 ] ) ;
if ( V_195 > ( V_112 -> V_199 >> 1 ) ) {
* V_193 = 0 ;
return 0 ;
}
if ( V_99 == 0 ) {
V_196 = ( V_9 . V_200 != 0 ) ;
memcpy ( & V_112 -> V_201 , & V_112 -> V_197 , sizeof( V_112 -> V_197 ) ) ;
error = F_79 ( V_112 , & V_112 -> V_201 , V_196 , 0 ,
& V_181 ) ;
if ( error )
return error ;
* V_193 = V_181 ? 2 : 0 ;
return 0 ;
}
V_196 = V_9 . V_200 < V_9 . V_202 ;
for ( V_70 = 0 , V_4 = NULL ; V_70 < 2 ; V_196 = ! V_196 , V_70 ++ ) {
struct V_8 V_162 ;
V_17 = V_196 ? V_9 . V_200 : V_9 . V_202 ;
if ( V_17 == 0 )
continue;
error = F_80 ( V_112 -> args -> V_76 , V_2 ,
V_17 , - 1 , & V_4 ) ;
if ( error )
return error ;
V_99 = V_9 . V_99 - V_9 . V_101 ;
V_195 = V_112 -> V_199 - ( V_112 -> V_199 >> 2 ) ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_162 , V_6 ) ;
V_97 = V_2 -> V_10 -> V_98 ( V_6 ) ;
V_99 += V_162 . V_99 - V_162 . V_101 ;
V_195 -= V_99 * sizeof( V_97 [ 0 ] ) ;
if ( V_195 >= 0 )
break;
F_52 ( V_112 -> args -> V_76 , V_4 ) ;
}
if ( V_70 >= 2 ) {
* V_193 = 0 ;
return 0 ;
}
memcpy ( & V_112 -> V_201 , & V_112 -> V_197 , sizeof( V_112 -> V_197 ) ) ;
if ( V_17 < V_194 -> V_17 )
error = F_79 ( V_112 , & V_112 -> V_201 , V_196 , 0 ,
& V_181 ) ;
else
error = F_79 ( V_112 , & V_112 -> V_197 , V_196 , 0 ,
& V_181 ) ;
if ( error ) {
return error ;
}
* V_193 = V_181 ? 0 : 1 ;
return 0 ;
}
void
F_81 (
T_15 * V_112 ,
T_17 * V_203 ,
T_17 * V_204 )
{
T_6 * args ;
T_8 * V_205 ;
T_8 * V_206 ;
struct V_8 V_207 ;
struct V_8 V_208 ;
struct V_96 * V_149 ;
struct V_96 * V_153 ;
struct V_1 * V_2 = V_112 -> args -> V_2 ;
args = V_112 -> args ;
ASSERT ( V_203 -> V_12 == V_19 ) ;
ASSERT ( V_204 -> V_12 == V_19 ) ;
V_205 = V_203 -> V_4 -> V_7 ;
V_206 = V_204 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_207 , V_206 ) ;
V_2 -> V_10 -> V_11 ( & V_208 , V_205 ) ;
V_149 = V_2 -> V_10 -> V_98 ( V_206 ) ;
V_153 = V_2 -> V_10 -> V_98 ( V_205 ) ;
if ( V_208 . V_101 )
F_82 ( args , & V_208 , V_203 -> V_4 ) ;
if ( V_207 . V_101 )
F_82 ( args , & V_207 , V_204 -> V_4 ) ;
V_203 -> V_103 = F_34 ( V_153 [ V_208 . V_99 - 1 ] . V_103 ) ;
if ( F_62 ( V_2 , V_204 -> V_4 , V_203 -> V_4 ) )
F_60 ( args , V_203 -> V_4 , & V_208 , V_153 , 0 ,
V_204 -> V_4 , & V_207 , V_149 , 0 ,
V_208 . V_99 ) ;
else
F_60 ( args , V_203 -> V_4 , & V_208 , V_153 , 0 ,
V_204 -> V_4 , & V_207 , V_149 ,
V_207 . V_99 , V_208 . V_99 ) ;
V_204 -> V_103 = F_34 ( V_149 [ V_207 . V_99 - 1 ] . V_103 ) ;
V_2 -> V_10 -> V_107 ( V_206 , & V_207 ) ;
V_2 -> V_10 -> V_107 ( V_205 , & V_208 ) ;
F_38 ( args -> V_76 , V_2 , V_204 -> V_4 ) ;
F_38 ( args -> V_76 , V_2 , V_203 -> V_4 ) ;
F_39 ( V_2 , V_204 -> V_4 ) ;
F_39 ( V_2 , V_203 -> V_4 ) ;
}
int
F_83 (
T_6 * args )
{
T_17 * V_194 ;
int error ;
int V_181 ;
T_15 * V_112 ;
F_84 ( args ) ;
V_112 = F_85 () ;
V_112 -> args = args ;
V_112 -> V_22 = args -> V_2 -> V_20 ;
V_112 -> V_199 = V_112 -> V_22 -> V_82 ;
V_112 -> V_209 = V_112 -> V_22 -> V_210 ;
error = F_86 ( V_112 , & V_181 ) ;
if ( error )
V_181 = error ;
if ( V_181 != V_129 ) {
goto V_211;
}
V_181 = F_87 ( args ,
V_112 -> V_120 ? & V_112 -> V_121 : NULL ) ;
if ( V_181 ) {
goto V_211;
}
V_194 = & V_112 -> V_197 . V_194 [ V_112 -> V_197 . V_198 - 1 ] ;
ASSERT ( V_194 -> V_12 == V_19 ) ;
V_181 = F_40 ( V_194 -> V_4 , args , V_194 -> V_89 ) ;
if ( V_181 == 0 ) {
if ( ! ( args -> V_104 & V_105 ) )
F_88 ( V_112 , & V_112 -> V_197 ) ;
} else {
if ( args -> V_179 == 0 ) {
ASSERT ( V_181 == V_102 ) ;
goto V_211;
}
V_181 = F_89 ( V_112 ) ;
}
V_211:
F_90 ( V_112 ) ;
return V_181 ;
}
static int
F_87 (
T_6 * args ,
T_17 * V_212 )
{
T_18 * V_26 ;
T_3 V_213 ;
struct V_3 * V_182 ;
T_16 * V_130 ;
T_7 * V_2 ;
T_19 * V_214 ;
int error ;
T_3 V_47 ;
struct V_3 * V_67 ;
int V_176 ;
T_4 * free = NULL ;
T_3 V_215 ;
T_3 V_216 = 0 ;
int V_117 ;
int V_178 ;
T_10 * V_22 ;
int V_183 ;
int V_184 ;
T_5 * V_217 ;
T_12 * V_46 ;
T_5 * V_62 ;
struct V_54 V_75 ;
struct V_185 * V_186 ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_46 = args -> V_76 ;
V_117 = V_2 -> V_10 -> V_122 ( args -> V_123 ) ;
if ( V_212 ) {
V_67 = V_212 -> V_4 ;
V_215 = V_212 -> V_17 ;
free = V_67 -> V_7 ;
V_176 = V_212 -> V_89 ;
V_62 = V_2 -> V_10 -> V_63 ( free ) ;
V_2 -> V_10 -> V_78 ( & V_75 , free ) ;
if ( V_176 >= 0 ) {
ASSERT ( V_176 < V_75 . V_85 ) ;
ASSERT ( F_36 ( V_62 [ V_176 ] ) != V_83 ) ;
ASSERT ( F_36 ( V_62 [ V_176 ] ) >= V_117 ) ;
V_213 = V_75 . V_109 + V_176 ;
} else {
V_213 = - 1 ;
V_176 = 0 ;
}
} else {
V_215 = V_213 = - 1 ;
V_67 = NULL ;
V_176 = 0 ;
}
if ( V_213 == - 1 ) {
T_20 V_218 ;
if ( ( error = F_91 ( V_46 , V_2 , & V_218 , V_51 ) ) )
return error ;
V_216 = F_76 ( V_22 , ( T_1 ) V_218 ) ;
V_47 = V_215 ;
}
while ( V_213 == - 1 ) {
if ( V_67 == NULL ) {
if ( ++ V_47 == 0 )
V_47 = F_32 ( V_22 ) ;
if ( V_47 == V_215 )
V_47 ++ ;
if ( V_47 >= V_216 )
break;
error = F_20 ( V_46 , V_2 ,
F_23 ( V_22 , V_47 ) ,
& V_67 ) ;
if ( error )
return error ;
if ( ! V_67 )
continue;
free = V_67 -> V_7 ;
V_176 = 0 ;
}
V_62 = V_2 -> V_10 -> V_63 ( free ) ;
V_2 -> V_10 -> V_78 ( & V_75 , free ) ;
if ( F_36 ( V_62 [ V_176 ] ) != V_83 &&
F_36 ( V_62 [ V_176 ] ) >= V_117 )
V_213 = V_75 . V_109 + V_176 ;
else {
if ( ++ V_176 == V_75 . V_85 ) {
F_52 ( V_46 , V_67 ) ;
V_67 = NULL ;
if ( V_212 && V_212 -> V_4 )
V_212 -> V_4 = NULL ;
}
}
}
if ( F_53 ( V_213 == - 1 ) ) {
if ( ( args -> V_104 & V_105 ) || args -> V_179 == 0 )
return F_42 ( V_102 ) ;
if ( F_53 ( ( error = F_31 ( args ,
V_219 ,
& V_213 ) ) ||
( error = F_92 ( args , V_213 , & V_182 ) ) ) )
return error ;
if ( V_67 )
F_52 ( V_46 , V_67 ) ;
if ( V_212 && V_212 -> V_4 )
V_212 -> V_4 = NULL ;
V_47 = V_2 -> V_10 -> V_125 ( V_22 , V_213 ) ;
error = F_20 ( V_46 , V_2 ,
F_23 ( V_22 , V_47 ) ,
& V_67 ) ;
if ( error )
return error ;
if ( ! V_67 ) {
error = F_31 ( args , V_77 ,
& V_47 ) ;
if ( error )
return error ;
if ( F_53 ( V_2 -> V_10 -> V_125 ( V_22 , V_213 ) != V_47 ) ) {
F_65 ( V_22 ,
L_3
L_4 ,
V_36 , ( unsigned long long ) V_2 -> V_58 ,
( long long ) V_2 -> V_10 -> V_125 ( V_22 , V_213 ) ,
( long long ) V_213 , ( long long ) V_47 ,
( unsigned long long ) V_215 , V_216 ) ;
if ( V_212 ) {
F_65 ( V_22 ,
L_5 ,
V_212 ,
( unsigned long long ) V_212 -> V_17 ,
V_212 -> V_89 ,
V_212 -> V_12 ) ;
} else {
F_65 ( V_22 , L_6 ) ;
}
F_54 ( L_7 ,
V_37 , V_22 ) ;
return F_42 ( V_38 ) ;
}
error = F_21 ( V_46 , V_2 , V_47 , & V_67 ) ;
if ( error )
return error ;
free = V_67 -> V_7 ;
V_62 = V_2 -> V_10 -> V_63 ( free ) ;
V_2 -> V_10 -> V_78 ( & V_75 , free ) ;
V_75 . V_109 = ( V_47 - F_32 ( V_22 ) ) *
V_2 -> V_10 -> V_110 ( V_22 ) ;
} else {
free = V_67 -> V_7 ;
V_62 = V_2 -> V_10 -> V_63 ( free ) ;
V_2 -> V_10 -> V_78 ( & V_75 , free ) ;
}
V_176 = V_2 -> V_10 -> V_126 ( V_22 , V_213 ) ;
if ( V_176 >= V_75 . V_85 ) {
ASSERT ( V_176 < V_2 -> V_10 -> V_110 ( V_22 ) ) ;
V_75 . V_85 = V_176 + 1 ;
V_62 [ V_176 ] = F_37 ( V_83 ) ;
}
if ( V_62 [ V_176 ] == F_37 ( V_83 ) ) {
V_75 . V_84 ++ ;
V_2 -> V_10 -> V_59 ( V_67 -> V_7 , & V_75 ) ;
F_27 ( V_46 , V_2 , V_67 ) ;
}
V_26 = V_182 -> V_7 ;
V_186 = V_2 -> V_10 -> V_187 ( V_26 ) ;
V_62 [ V_176 ] = V_186 [ 0 ] . V_117 ;
V_178 = 1 ;
}
else {
if ( args -> V_104 & V_105 )
return 0 ;
error = F_56 ( V_46 , V_2 , F_23 ( V_22 , V_213 ) ,
- 1 , & V_182 ) ;
if ( error )
return error ;
V_26 = V_182 -> V_7 ;
V_186 = V_2 -> V_10 -> V_187 ( V_26 ) ;
V_178 = 0 ;
}
ASSERT ( F_36 ( V_186 [ 0 ] . V_117 ) >= V_117 ) ;
V_214 = ( T_19 * )
( ( char * ) V_26 + F_36 ( V_186 [ 0 ] . V_220 ) ) ;
V_184 = V_183 = 0 ;
F_93 ( V_46 , V_2 , V_182 , V_214 ,
( V_221 ) ( ( char * ) V_214 - ( char * ) V_26 ) , V_117 ,
& V_183 , & V_184 ) ;
V_130 = ( T_16 * ) V_214 ;
V_130 -> V_138 = F_14 ( args -> V_138 ) ;
V_130 -> V_123 = args -> V_123 ;
memcpy ( V_130 -> V_137 , args -> V_137 , V_130 -> V_123 ) ;
V_2 -> V_10 -> V_222 ( V_130 , args -> V_139 ) ;
V_217 = V_2 -> V_10 -> V_223 ( V_130 ) ;
* V_217 = F_37 ( ( char * ) V_130 - ( char * ) V_26 ) ;
F_94 ( V_46 , V_2 , V_182 , V_130 ) ;
if ( V_184 )
F_71 ( V_2 , V_26 , & V_183 ) ;
if ( V_183 )
F_72 ( V_46 , V_2 , V_182 ) ;
V_62 = V_2 -> V_10 -> V_63 ( free ) ;
if ( F_36 ( V_62 [ V_176 ] ) != F_36 ( V_186 [ 0 ] . V_117 ) ) {
V_62 [ V_176 ] = V_186 [ 0 ] . V_117 ;
V_178 = 1 ;
}
if ( V_178 )
F_25 ( V_46 , V_2 , V_67 , V_176 , V_176 ) ;
args -> V_17 = ( T_1 ) V_213 ;
args -> V_89 = F_36 ( * V_217 ) ;
return 0 ;
}
int
F_95 (
T_6 * args )
{
int error ;
int V_70 ;
int V_181 ;
T_15 * V_112 ;
F_96 ( args ) ;
V_112 = F_85 () ;
V_112 -> args = args ;
V_112 -> V_22 = args -> V_2 -> V_20 ;
V_112 -> V_199 = V_112 -> V_22 -> V_82 ;
V_112 -> V_209 = V_112 -> V_22 -> V_210 ;
error = F_86 ( V_112 , & V_181 ) ;
if ( error )
V_181 = error ;
else if ( V_181 == V_129 && args -> V_133 == V_224 ) {
T_16 * V_130 ;
V_130 = ( T_16 * )
( ( char * ) V_112 -> V_121 . V_4 -> V_7 +
V_112 -> V_121 . V_89 ) ;
V_181 = F_97 ( args , V_130 -> V_137 , V_130 -> V_123 ) ;
}
for ( V_70 = 0 ; V_70 < V_112 -> V_197 . V_198 ; V_70 ++ ) {
F_52 ( args -> V_76 , V_112 -> V_197 . V_194 [ V_70 ] . V_4 ) ;
V_112 -> V_197 . V_194 [ V_70 ] . V_4 = NULL ;
}
if ( V_112 -> V_120 && V_112 -> V_121 . V_4 ) {
F_52 ( args -> V_76 , V_112 -> V_121 . V_4 ) ;
V_112 -> V_121 . V_4 = NULL ;
}
F_90 ( V_112 ) ;
return V_181 ;
}
int
F_98 (
struct V_225 * args )
{
struct V_226 * V_194 ;
int error ;
int V_181 ;
struct V_227 * V_112 ;
F_99 ( args ) ;
V_112 = F_85 () ;
V_112 -> args = args ;
V_112 -> V_22 = args -> V_2 -> V_20 ;
V_112 -> V_199 = V_112 -> V_22 -> V_82 ;
V_112 -> V_209 = V_112 -> V_22 -> V_210 ;
error = F_86 ( V_112 , & V_181 ) ;
if ( error )
goto V_228;
if ( V_181 != V_145 ) {
error = V_181 ;
goto V_228;
}
V_194 = & V_112 -> V_197 . V_194 [ V_112 -> V_197 . V_198 - 1 ] ;
ASSERT ( V_194 -> V_12 == V_19 ) ;
ASSERT ( V_112 -> V_120 ) ;
error = F_68 ( args , V_194 -> V_4 , V_194 -> V_89 ,
& V_112 -> V_121 , & V_181 ) ;
if ( error )
goto V_228;
F_88 ( V_112 , & V_112 -> V_197 ) ;
if ( V_181 && V_112 -> V_197 . V_198 > 1 )
error = F_100 ( V_112 ) ;
if ( ! error )
error = F_101 ( V_112 ) ;
V_228:
F_90 ( V_112 ) ;
return error ;
}
int
F_102 (
T_6 * args )
{
T_17 * V_194 ;
T_18 * V_26 ;
T_16 * V_130 ;
int error ;
int V_70 ;
T_21 V_229 ;
T_8 * V_6 ;
T_13 * V_92 ;
int V_181 ;
T_15 * V_112 ;
F_103 ( args ) ;
V_112 = F_85 () ;
V_112 -> args = args ;
V_112 -> V_22 = args -> V_2 -> V_20 ;
V_112 -> V_199 = V_112 -> V_22 -> V_82 ;
V_112 -> V_209 = V_112 -> V_22 -> V_210 ;
V_229 = args -> V_138 ;
error = F_86 ( V_112 , & V_181 ) ;
if ( error ) {
V_181 = error ;
}
if ( V_181 == V_145 ) {
struct V_96 * V_97 ;
V_194 = & V_112 -> V_197 . V_194 [ V_112 -> V_197 . V_198 - 1 ] ;
ASSERT ( V_194 -> V_12 == V_19 ) ;
V_6 = V_194 -> V_4 -> V_7 ;
V_97 = args -> V_2 -> V_10 -> V_98 ( V_6 ) ;
V_92 = & V_97 [ V_194 -> V_89 ] ;
ASSERT ( V_112 -> V_120 ) ;
V_26 = V_112 -> V_121 . V_4 -> V_7 ;
ASSERT ( V_26 -> V_12 == F_6 ( V_141 ) ||
V_26 -> V_12 == F_6 ( V_230 ) ) ;
V_130 = ( T_16 * )
( ( char * ) V_26 +
F_58 ( V_112 -> V_22 , F_34 ( V_92 -> V_106 ) ) ) ;
ASSERT ( V_229 != F_2 ( V_130 -> V_138 ) ) ;
V_130 -> V_138 = F_14 ( V_229 ) ;
args -> V_2 -> V_10 -> V_222 ( V_130 , args -> V_139 ) ;
F_94 ( args -> V_76 , args -> V_2 ,
V_112 -> V_121 . V_4 , V_130 ) ;
V_181 = 0 ;
}
else if ( V_112 -> V_120 ) {
F_52 ( args -> V_76 , V_112 -> V_121 . V_4 ) ;
V_112 -> V_121 . V_4 = NULL ;
}
for ( V_70 = 0 ; V_70 < V_112 -> V_197 . V_198 ; V_70 ++ ) {
F_52 ( args -> V_76 , V_112 -> V_197 . V_194 [ V_70 ] . V_4 ) ;
V_112 -> V_197 . V_194 [ V_70 ] . V_4 = NULL ;
}
F_90 ( V_112 ) ;
return V_181 ;
}
int
F_104 (
T_6 * args ,
T_20 V_218 ,
int * V_231 )
{
struct V_3 * V_4 ;
T_7 * V_2 ;
int error ;
T_4 * free ;
T_10 * V_22 ;
T_12 * V_46 ;
struct V_54 V_75 ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_46 = args -> V_76 ;
error = F_20 ( V_46 , V_2 , V_218 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_4 )
return 0 ;
free = V_4 -> V_7 ;
V_2 -> V_10 -> V_78 ( & V_75 , free ) ;
if ( V_75 . V_84 > 0 ) {
F_52 ( V_46 , V_4 ) ;
* V_231 = 0 ;
return 0 ;
}
if ( ( error =
F_67 ( args , F_76 ( V_22 , ( T_1 ) V_218 ) ,
V_4 ) ) ) {
ASSERT ( error != V_102 ) ;
F_52 ( V_46 , V_4 ) ;
return error ;
}
* V_231 = 1 ;
return 0 ;
}
