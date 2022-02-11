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
static bool
F_16 (
struct V_1 * V_2 ,
T_1 V_44 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_2 -> V_20 ;
unsigned int V_45 ;
int V_46 ;
V_46 = V_2 -> V_10 -> V_47 ( V_22 -> V_48 ) ;
V_45 = ( F_17 ( V_22 -> V_48 , V_44 ) -
F_18 ( V_22 -> V_48 , V_49 ) ) *
V_46 ;
if ( F_5 ( & V_22 -> V_27 ) ) {
struct V_50 * V_29 = V_4 -> V_7 ;
if ( F_19 ( V_29 -> V_45 ) != V_45 )
return false ;
if ( F_19 ( V_29 -> V_51 ) > V_46 )
return false ;
if ( F_19 ( V_29 -> V_51 ) < F_19 ( V_29 -> V_52 ) )
return false ;
} else {
struct V_25 * V_26 = V_4 -> V_7 ;
if ( F_19 ( V_26 -> V_45 ) != V_45 )
return false ;
if ( F_19 ( V_26 -> V_51 ) > V_46 )
return false ;
if ( F_19 ( V_26 -> V_51 ) < F_19 ( V_26 -> V_52 ) )
return false ;
}
return true ;
}
static int
F_20 (
struct V_53 * V_54 ,
struct V_1 * V_2 ,
T_1 V_44 ,
T_2 V_55 ,
struct V_3 * * V_56 )
{
int V_57 ;
V_57 = F_21 ( V_54 , V_2 , V_44 , V_55 , V_56 ,
V_58 , & V_59 ) ;
if ( V_57 || ! * V_56 )
return V_57 ;
if ( ! F_16 ( V_2 , V_44 , * V_56 ) ) {
F_11 ( * V_56 , - V_37 ) ;
F_12 ( * V_56 ) ;
F_22 ( V_54 , * V_56 ) ;
return - V_37 ;
}
if ( V_54 )
F_23 ( V_54 , * V_56 , V_60 ) ;
return 0 ;
}
int
F_24 (
struct V_53 * V_54 ,
struct V_1 * V_2 ,
T_1 V_44 ,
struct V_3 * * V_56 )
{
return F_20 ( V_54 , V_2 , V_44 , - 1 , V_56 ) ;
}
static int
F_25 (
struct V_53 * V_54 ,
struct V_1 * V_2 ,
T_1 V_44 ,
struct V_3 * * V_56 )
{
return F_20 ( V_54 , V_2 , V_44 , - 2 , V_56 ) ;
}
static int
F_26 (
T_3 * args ,
T_4 V_44 ,
struct V_3 * * V_56 )
{
struct V_53 * V_54 = args -> V_61 ;
struct V_1 * V_2 = args -> V_2 ;
struct V_21 * V_22 = V_2 -> V_20 ;
struct V_3 * V_4 ;
int error ;
struct V_62 V_26 ;
error = F_27 ( V_54 , V_2 , F_28 ( args -> V_63 , V_44 ) ,
- 1 , & V_4 , V_58 ) ;
if ( error )
return error ;
F_23 ( V_54 , V_4 , V_60 ) ;
V_4 -> V_64 = & V_59 ;
memset ( V_4 -> V_7 , 0 , sizeof( struct V_50 ) ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_5 ( & V_22 -> V_27 ) ) {
struct V_50 * V_29 = V_4 -> V_7 ;
V_26 . V_12 = V_30 ;
V_29 -> V_26 . V_17 = F_14 ( V_4 -> V_18 ) ;
V_29 -> V_26 . V_65 = F_14 ( V_2 -> V_66 ) ;
F_29 ( & V_29 -> V_26 . V_31 , & V_22 -> V_27 . V_32 ) ;
} else
V_26 . V_12 = V_34 ;
V_2 -> V_10 -> V_67 ( V_4 -> V_7 , & V_26 ) ;
* V_56 = V_4 ;
return 0 ;
}
STATIC void
F_30 (
struct V_68 * args ,
struct V_3 * V_4 ,
int V_69 ,
int V_70 )
{
T_5 * free ;
T_6 * V_71 ;
free = V_4 -> V_7 ;
V_71 = args -> V_2 -> V_10 -> V_72 ( free ) ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_34 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
F_31 ( args -> V_61 , V_4 ,
( V_73 ) ( ( char * ) & V_71 [ V_69 ] - ( char * ) free ) ,
( V_73 ) ( ( char * ) & V_71 [ V_70 ] - ( char * ) free +
sizeof( V_71 [ 0 ] ) - 1 ) ) ;
}
static void
F_32 (
struct V_68 * args ,
struct V_3 * V_4 )
{
#ifdef F_33
T_5 * free ;
free = V_4 -> V_7 ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_34 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
#endif
F_31 ( args -> V_61 , V_4 , 0 ,
args -> V_2 -> V_10 -> V_74 - 1 ) ;
}
int
F_34 (
T_3 * args ,
struct V_3 * V_75 )
{
T_7 * V_2 ;
int error ;
struct V_3 * V_76 ;
T_4 V_77 ;
T_5 * free ;
T_6 * V_78 ;
int V_79 ;
T_8 * V_6 ;
T_9 * V_80 ;
int V_81 ;
T_10 V_82 ;
T_6 * V_83 ;
T_11 * V_54 ;
struct V_62 V_84 ;
F_35 ( args ) ;
V_2 = args -> V_2 ;
V_54 = args -> V_61 ;
if ( ( error = F_36 ( args , V_85 , & V_77 ) ) ) {
return error ;
}
ASSERT ( V_77 == F_18 ( args -> V_63 , V_49 ) ) ;
error = F_26 ( args , V_77 , & V_76 ) ;
if ( error )
return error ;
free = V_76 -> V_7 ;
V_2 -> V_10 -> V_86 ( & V_84 , free ) ;
V_6 = V_75 -> V_7 ;
V_80 = F_37 ( args -> V_63 , V_6 ) ;
ASSERT ( F_19 ( V_80 -> V_87 ) <=
( V_73 ) V_2 -> V_88 . V_89 / args -> V_63 -> V_90 ) ;
V_78 = F_38 ( V_80 ) ;
V_83 = V_2 -> V_10 -> V_72 ( free ) ;
for ( V_79 = V_81 = 0 ; V_79 < F_19 ( V_80 -> V_87 ) ; V_79 ++ , V_78 ++ , V_83 ++ ) {
if ( ( V_82 = F_39 ( * V_78 ) ) != V_91 )
V_81 ++ ;
* V_83 = F_40 ( V_82 ) ;
}
V_84 . V_52 = V_81 ;
V_84 . V_51 = F_19 ( V_80 -> V_87 ) ;
V_2 -> V_10 -> V_67 ( V_76 -> V_7 , & V_84 ) ;
F_30 ( args , V_76 , 0 , V_84 . V_51 - 1 ) ;
F_32 ( args , V_76 ) ;
if ( V_6 -> V_26 . V_16 . V_12 == F_40 ( V_92 ) )
V_6 -> V_26 . V_16 . V_12 = F_40 ( V_19 ) ;
else
V_6 -> V_26 . V_16 . V_12 = F_40 ( V_13 ) ;
V_75 -> V_64 = & V_93 ;
F_23 ( V_54 , V_75 , V_94 ) ;
F_41 ( args , V_75 ) ;
F_42 ( V_2 , V_75 ) ;
return 0 ;
}
static int
F_43 (
struct V_3 * V_4 ,
T_3 * args ,
int V_95 )
{
int V_96 ;
T_7 * V_2 ;
int V_97 ;
T_8 * V_6 ;
T_12 * V_98 ;
int V_99 ;
int V_100 ;
int V_101 ;
struct V_8 V_9 ;
struct V_102 * V_103 ;
F_44 ( args , V_95 ) ;
V_2 = args -> V_2 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_103 = V_2 -> V_10 -> V_104 ( V_6 ) ;
if ( V_95 < 0 )
return - V_37 ;
if ( V_9 . V_105 == V_2 -> V_10 -> V_106 ( args -> V_63 ) ) {
if ( ! V_9 . V_107 )
return - V_108 ;
V_96 = V_9 . V_107 > 1 ;
} else
V_96 = 0 ;
ASSERT ( V_95 == 0 || F_19 ( V_103 [ V_95 - 1 ] . V_109 ) <= args -> V_109 ) ;
ASSERT ( V_95 == V_9 . V_105 ||
F_19 ( V_103 [ V_95 ] . V_109 ) >= args -> V_109 ) ;
if ( args -> V_110 & V_111 )
return 0 ;
if ( V_96 )
F_45 ( & V_9 , V_103 , & V_95 , & V_101 ,
& V_97 , & V_100 , & V_99 ) ;
else if ( V_9 . V_107 ) {
V_100 = V_9 . V_105 ;
V_99 = - 1 ;
}
V_98 = F_46 ( & V_9 , V_103 , V_95 , V_96 , V_101 ,
V_97 , & V_100 , & V_99 ) ;
V_98 -> V_109 = F_6 ( args -> V_109 ) ;
V_98 -> V_112 = F_6 ( F_47 ( args -> V_63 ,
args -> V_17 , args -> V_95 ) ) ;
V_2 -> V_10 -> V_113 ( V_6 , & V_9 ) ;
F_41 ( args , V_4 ) ;
F_48 ( args , V_4 , V_100 , V_99 ) ;
F_42 ( V_2 , V_4 ) ;
return 0 ;
}
static void
F_49 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_4 V_114 )
{
struct V_62 V_26 ;
V_2 -> V_10 -> V_86 ( & V_26 , V_4 -> V_7 ) ;
ASSERT ( ( V_26 . V_45 %
V_2 -> V_10 -> V_47 ( V_2 -> V_20 -> V_48 ) ) == 0 ) ;
ASSERT ( V_26 . V_45 <= V_114 ) ;
ASSERT ( V_114 < V_26 . V_45 + V_26 . V_51 ) ;
}
T_13
F_50 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int * V_105 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_102 * V_103 ;
struct V_8 V_9 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_12 == V_19 ||
V_9 . V_12 == V_13 ||
V_9 . V_12 == V_92 ||
V_9 . V_12 == V_115 ) ;
if ( V_105 )
* V_105 = V_9 . V_105 ;
if ( ! V_9 . V_105 )
return 0 ;
V_103 = V_2 -> V_10 -> V_104 ( V_6 ) ;
return F_19 ( V_103 [ V_9 . V_105 - 1 ] . V_109 ) ;
}
STATIC int
F_51 (
struct V_3 * V_4 ,
T_3 * args ,
int * V_116 ,
T_14 * V_117 )
{
struct V_3 * V_118 = NULL ;
T_4 V_119 = - 1 ;
T_4 V_120 = - 1 ;
T_7 * V_2 ;
int error ;
int V_121 ;
T_5 * free = NULL ;
int V_95 ;
T_8 * V_6 ;
int V_122 ;
T_12 * V_98 ;
T_15 * V_22 ;
T_4 V_123 ;
T_4 V_124 ;
T_11 * V_54 ;
struct V_102 * V_103 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_54 = args -> V_61 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_103 = V_2 -> V_10 -> V_104 ( V_6 ) ;
F_42 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_105 > 0 ) ;
V_95 = F_52 ( args , V_4 ) ;
if ( V_117 -> V_125 ) {
V_118 = V_117 -> V_126 . V_4 ;
V_120 = V_117 -> V_126 . V_17 ;
free = V_118 -> V_7 ;
ASSERT ( free -> V_26 . V_12 == F_6 ( V_34 ) ||
free -> V_26 . V_12 == F_6 ( V_30 ) ) ;
}
V_122 = V_2 -> V_10 -> V_127 ( args -> V_128 ) ;
for ( V_98 = & V_103 [ V_95 ] ;
V_95 < V_9 . V_105 && F_19 ( V_98 -> V_109 ) == args -> V_109 ;
V_98 ++ , V_95 ++ ) {
if ( F_19 ( V_98 -> V_112 ) == V_129 )
continue;
V_123 = F_53 ( args -> V_63 ,
F_19 ( V_98 -> V_112 ) ) ;
if ( V_123 != V_119 ) {
T_6 * V_71 ;
V_119 = V_123 ;
V_124 = V_2 -> V_10 -> V_130 ( args -> V_63 , V_123 ) ;
if ( V_124 != V_120 ) {
if ( V_118 )
F_22 ( V_54 , V_118 ) ;
error = F_24 ( V_54 , V_2 ,
F_28 ( args -> V_63 ,
V_124 ) ,
& V_118 ) ;
if ( error )
return error ;
free = V_118 -> V_7 ;
F_49 ( V_2 , V_118 , V_119 ) ;
}
V_121 = V_2 -> V_10 -> V_131 ( args -> V_63 , V_119 ) ;
V_71 = V_2 -> V_10 -> V_72 ( free ) ;
if ( F_54 ( V_71 [ V_121 ] == F_40 ( V_91 ) ) ) {
F_55 ( L_1 ,
V_132 , V_22 ) ;
if ( V_120 != V_124 )
F_22 ( V_54 , V_118 ) ;
return - V_37 ;
}
V_120 = V_124 ;
if ( F_39 ( V_71 [ V_121 ] ) >= V_122 )
goto V_133;
}
}
V_121 = - 1 ;
V_133:
ASSERT ( args -> V_110 & V_134 ) ;
if ( V_118 ) {
V_117 -> V_125 = 1 ;
V_117 -> V_126 . V_4 = V_118 ;
V_117 -> V_126 . V_95 = V_121 ;
V_117 -> V_126 . V_17 = V_120 ;
V_117 -> V_126 . V_12 = V_34 ;
} else {
V_117 -> V_125 = 0 ;
}
* V_116 = V_95 ;
return - V_135 ;
}
STATIC int
F_56 (
struct V_3 * V_4 ,
T_3 * args ,
int * V_116 ,
T_14 * V_117 )
{
struct V_3 * V_118 = NULL ;
T_4 V_119 = - 1 ;
T_16 * V_136 ;
T_7 * V_2 ;
int error ;
int V_95 ;
T_8 * V_6 ;
T_12 * V_98 ;
T_15 * V_22 ;
T_4 V_123 ;
T_11 * V_54 ;
enum V_137 V_138 ;
struct V_102 * V_103 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_54 = args -> V_61 ;
V_22 = V_2 -> V_20 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_103 = V_2 -> V_10 -> V_104 ( V_6 ) ;
F_42 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_105 > 0 ) ;
V_95 = F_52 ( args , V_4 ) ;
if ( V_117 -> V_125 ) {
V_118 = V_117 -> V_126 . V_4 ;
V_119 = V_117 -> V_126 . V_17 ;
}
for ( V_98 = & V_103 [ V_95 ] ;
V_95 < V_9 . V_105 && F_19 ( V_98 -> V_109 ) == args -> V_109 ;
V_98 ++ , V_95 ++ ) {
if ( F_19 ( V_98 -> V_112 ) == V_129 )
continue;
V_123 = F_53 ( args -> V_63 ,
F_19 ( V_98 -> V_112 ) ) ;
if ( V_123 != V_119 ) {
if ( V_118 && ( args -> V_139 == V_140 ||
V_119 != V_117 -> V_126 . V_17 ) )
F_22 ( V_54 , V_118 ) ;
if ( args -> V_139 != V_140 &&
V_123 == V_117 -> V_126 . V_17 ) {
ASSERT ( V_117 -> V_125 ) ;
V_118 = V_117 -> V_126 . V_4 ;
} else {
error = F_57 ( V_54 , V_2 ,
F_28 ( args -> V_63 ,
V_123 ) ,
- 1 , & V_118 ) ;
if ( error )
return error ;
}
F_58 ( V_2 , V_118 ) ;
V_119 = V_123 ;
}
V_136 = ( T_16 * ) ( ( char * ) V_118 -> V_7 +
F_59 ( args -> V_63 ,
F_19 ( V_98 -> V_112 ) ) ) ;
V_138 = V_22 -> V_141 -> V_142 ( args , V_136 -> V_143 , V_136 -> V_128 ) ;
if ( V_138 != V_140 && V_138 != args -> V_139 ) {
if ( args -> V_139 != V_140 &&
V_119 != V_117 -> V_126 . V_17 )
F_22 ( V_54 , V_117 -> V_126 . V_4 ) ;
args -> V_139 = V_138 ;
args -> V_144 = F_2 ( V_136 -> V_144 ) ;
args -> V_145 = V_2 -> V_10 -> V_146 ( V_136 ) ;
* V_116 = V_95 ;
V_117 -> V_125 = 1 ;
V_117 -> V_126 . V_4 = V_118 ;
V_117 -> V_126 . V_17 = V_119 ;
V_117 -> V_126 . V_95 = ( int ) ( ( char * ) V_136 -
( char * ) V_118 -> V_7 ) ;
V_117 -> V_126 . V_12 = V_147 ;
V_118 -> V_64 = & V_148 ;
F_23 ( V_54 , V_118 , V_149 ) ;
if ( V_138 == V_150 )
return - V_151 ;
}
}
ASSERT ( V_95 == V_9 . V_105 || ( args -> V_110 & V_134 ) ) ;
if ( V_118 ) {
if ( args -> V_139 == V_140 ) {
V_117 -> V_125 = 1 ;
V_117 -> V_126 . V_4 = V_118 ;
V_117 -> V_126 . V_95 = - 1 ;
V_117 -> V_126 . V_17 = V_119 ;
V_117 -> V_126 . V_12 = V_147 ;
V_118 -> V_64 = & V_148 ;
F_23 ( V_54 , V_118 , V_149 ) ;
} else {
if ( V_117 -> V_126 . V_4 != V_118 )
F_22 ( V_54 , V_118 ) ;
}
} else {
V_117 -> V_125 = 0 ;
}
* V_116 = V_95 ;
return - V_135 ;
}
int
F_60 (
struct V_3 * V_4 ,
T_3 * args ,
int * V_116 ,
T_14 * V_117 )
{
if ( args -> V_110 & V_152 )
return F_51 ( V_4 , args , V_116 ,
V_117 ) ;
return F_56 ( V_4 , args , V_116 , V_117 ) ;
}
static void
F_61 (
T_3 * args ,
struct V_3 * V_153 ,
struct V_8 * V_154 ,
struct V_102 * V_155 ,
int V_156 ,
struct V_3 * V_157 ,
struct V_8 * V_158 ,
struct V_102 * V_159 ,
int V_160 ,
int V_105 )
{
int V_107 ;
F_62 ( args , V_156 , V_160 , V_105 ) ;
if ( V_105 == 0 )
return;
if ( V_160 < V_158 -> V_105 ) {
memmove ( & V_159 [ V_160 + V_105 ] , & V_159 [ V_160 ] ,
( V_158 -> V_105 - V_160 ) * sizeof( T_12 ) ) ;
F_48 ( args , V_157 , V_160 + V_105 ,
V_105 + V_158 -> V_105 - 1 ) ;
}
if ( V_154 -> V_107 ) {
int V_79 ;
for ( V_79 = V_156 , V_107 = 0 ; V_79 < V_156 + V_105 ; V_79 ++ ) {
if ( V_155 [ V_79 ] . V_112 ==
F_6 ( V_129 ) )
V_107 ++ ;
}
} else
V_107 = 0 ;
memcpy ( & V_159 [ V_160 ] , & V_155 [ V_156 ] ,
V_105 * sizeof( T_12 ) ) ;
F_48 ( args , V_157 , V_160 , V_160 + V_105 - 1 ) ;
if ( V_156 + V_105 < V_154 -> V_105 ) {
memmove ( & V_155 [ V_156 ] , & V_155 [ V_156 + V_105 ] ,
V_105 * sizeof( T_12 ) ) ;
F_48 ( args , V_153 , V_156 , V_156 + V_105 - 1 ) ;
}
V_154 -> V_105 -= V_105 ;
V_154 -> V_107 -= V_107 ;
V_158 -> V_105 += V_105 ;
V_158 -> V_107 += V_107 ;
}
int
F_63 (
struct V_1 * V_2 ,
struct V_3 * V_161 ,
struct V_3 * V_162 )
{
struct V_5 * V_163 = V_161 -> V_7 ;
struct V_5 * V_164 = V_162 -> V_7 ;
struct V_102 * V_165 ;
struct V_102 * V_166 ;
struct V_8 V_167 ;
struct V_8 V_168 ;
V_2 -> V_10 -> V_11 ( & V_167 , V_163 ) ;
V_2 -> V_10 -> V_11 ( & V_168 , V_164 ) ;
V_165 = V_2 -> V_10 -> V_104 ( V_163 ) ;
V_166 = V_2 -> V_10 -> V_104 ( V_164 ) ;
if ( V_167 . V_105 > 0 && V_168 . V_105 > 0 &&
( F_19 ( V_166 [ 0 ] . V_109 ) < F_19 ( V_165 [ 0 ] . V_109 ) ||
F_19 ( V_166 [ V_168 . V_105 - 1 ] . V_109 ) <
F_19 ( V_165 [ V_167 . V_105 - 1 ] . V_109 ) ) )
return 1 ;
return 0 ;
}
static void
F_64 (
T_14 * V_117 ,
T_17 * V_169 ,
T_17 * V_170 )
{
T_3 * args ;
int V_105 ;
int V_171 ;
T_8 * V_163 ;
T_8 * V_164 ;
int V_172 ;
#if F_65 ( F_33 ) || F_65 ( V_173 )
int V_174 ;
#endif
int V_175 ;
int V_176 ;
struct V_102 * V_165 ;
struct V_102 * V_166 ;
struct V_8 V_167 ;
struct V_8 V_168 ;
struct V_1 * V_2 = V_117 -> args -> V_2 ;
args = V_117 -> args ;
if ( ( V_176 = F_63 ( V_2 , V_169 -> V_4 , V_170 -> V_4 ) ) ) {
T_17 * V_177 ;
V_177 = V_169 ;
V_169 = V_170 ;
V_170 = V_177 ;
}
V_163 = V_169 -> V_4 -> V_7 ;
V_164 = V_170 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_167 , V_163 ) ;
V_2 -> V_10 -> V_11 ( & V_168 , V_164 ) ;
V_165 = V_2 -> V_10 -> V_104 ( V_163 ) ;
V_166 = V_2 -> V_10 -> V_104 ( V_164 ) ;
V_175 = V_167 . V_105 + V_168 . V_105 ;
#if F_65 ( F_33 ) || F_65 ( V_173 )
V_174 = V_167 . V_107 + V_168 . V_107 ;
#endif
V_172 = V_175 >> 1 ;
if ( V_175 & 1 ) {
T_13 V_178 ;
if ( V_172 >= V_167 . V_105 )
V_178 = F_19 ( V_166 [ V_172 - V_167 . V_105 ] . V_109 ) ;
else
V_178 = F_19 ( V_165 [ V_172 ] . V_109 ) ;
V_171 = args -> V_109 <= V_178 ;
}
else
V_171 = 1 ;
V_105 = V_167 . V_105 - V_172 + ( V_171 == 0 ) ;
if ( V_105 > 0 )
F_61 ( args , V_169 -> V_4 , & V_167 , V_165 ,
V_167 . V_105 - V_105 , V_170 -> V_4 ,
& V_168 , V_166 , 0 , V_105 ) ;
else if ( V_105 < 0 )
F_61 ( args , V_170 -> V_4 , & V_168 , V_166 , 0 ,
V_169 -> V_4 , & V_167 , V_165 ,
V_167 . V_105 , V_105 ) ;
ASSERT ( V_167 . V_105 + V_168 . V_105 == V_175 ) ;
ASSERT ( V_167 . V_107 + V_168 . V_107 == V_174 ) ;
V_2 -> V_10 -> V_113 ( V_163 , & V_167 ) ;
V_2 -> V_10 -> V_113 ( V_164 , & V_168 ) ;
F_41 ( args , V_169 -> V_4 ) ;
F_41 ( args , V_170 -> V_4 ) ;
F_42 ( V_2 , V_169 -> V_4 ) ;
F_42 ( V_2 , V_170 -> V_4 ) ;
if ( V_167 . V_105 < V_168 . V_105 )
V_117 -> V_179 = V_176 ;
else if ( V_167 . V_105 > V_168 . V_105 )
V_117 -> V_179 = ! V_176 ;
else
V_117 -> V_179 = V_176 ^ ( V_169 -> V_95 <= V_167 . V_105 ) ;
if ( ! V_117 -> V_179 )
V_170 -> V_95 = V_169 -> V_95 - V_167 . V_105 ;
if ( V_170 -> V_95 < 0 ) {
V_117 -> V_179 = 1 ;
V_170 -> V_95 = 0 ;
F_66 ( V_2 -> V_20 ,
L_2 ,
V_180 , V_169 -> V_95 ) ;
}
}
static int
F_67 (
T_3 * args ,
struct V_181 * V_26 ,
struct V_182 * free ,
T_4 V_77 ,
int V_183 ,
struct V_3 * V_76 ,
int V_184 )
{
int V_185 = 0 ;
T_6 * V_71 ;
struct V_62 V_84 ;
struct V_1 * V_2 = args -> V_2 ;
V_2 -> V_10 -> V_86 ( & V_84 , free ) ;
V_71 = V_2 -> V_10 -> V_72 ( free ) ;
if ( V_26 ) {
V_71 [ V_183 ] = F_40 ( V_184 ) ;
F_30 ( args , V_76 , V_183 , V_183 ) ;
return 0 ;
}
V_84 . V_52 -- ;
if ( V_183 == V_84 . V_51 - 1 ) {
int V_79 ;
for ( V_79 = V_183 - 1 ; V_79 >= 0 ; V_79 -- ) {
if ( V_71 [ V_79 ] != F_40 ( V_91 ) )
break;
}
V_84 . V_51 = V_79 + 1 ;
V_185 = 0 ;
} else {
V_71 [ V_183 ] = F_40 ( V_91 ) ;
V_185 = 1 ;
}
V_2 -> V_10 -> V_67 ( free , & V_84 ) ;
F_32 ( args , V_76 ) ;
if ( ! V_84 . V_52 ) {
int error ;
error = F_68 ( args , V_77 , V_76 ) ;
if ( error == 0 ) {
V_76 = NULL ;
V_185 = 0 ;
} else if ( error != - V_108 || args -> V_186 != 0 )
return error ;
}
if ( V_185 )
F_30 ( args , V_76 , V_183 , V_183 ) ;
return 0 ;
}
static int
F_69 (
T_3 * args ,
struct V_3 * V_4 ,
int V_95 ,
T_17 * V_187 ,
int * V_188 )
{
T_18 * V_26 ;
T_4 V_114 ;
struct V_3 * V_189 ;
T_16 * V_136 ;
T_7 * V_2 ;
T_8 * V_6 ;
T_12 * V_98 ;
int V_184 ;
int V_82 ;
int V_190 ;
int V_191 ;
T_11 * V_54 ;
struct V_192 * V_193 ;
struct V_8 V_9 ;
struct V_102 * V_103 ;
F_70 ( args , V_95 ) ;
V_2 = args -> V_2 ;
V_54 = args -> V_61 ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_103 = V_2 -> V_10 -> V_104 ( V_6 ) ;
V_98 = & V_103 [ V_95 ] ;
V_114 = F_53 ( args -> V_63 , F_19 ( V_98 -> V_112 ) ) ;
ASSERT ( V_187 -> V_17 == V_114 ) ;
V_82 = F_59 ( args -> V_63 , F_19 ( V_98 -> V_112 ) ) ;
ASSERT ( V_187 -> V_95 == V_82 ) ;
V_9 . V_107 ++ ;
V_2 -> V_10 -> V_113 ( V_6 , & V_9 ) ;
F_41 ( args , V_4 ) ;
V_98 -> V_112 = F_6 ( V_129 ) ;
F_48 ( args , V_4 , V_95 , V_95 ) ;
V_189 = V_187 -> V_4 ;
V_26 = V_189 -> V_7 ;
V_136 = ( T_16 * ) ( ( char * ) V_26 + V_82 ) ;
V_193 = V_2 -> V_10 -> V_194 ( V_26 ) ;
V_184 = F_39 ( V_193 [ 0 ] . V_122 ) ;
V_190 = V_191 = 0 ;
F_71 ( args , V_189 , V_82 ,
V_2 -> V_10 -> V_127 ( V_136 -> V_128 ) , & V_190 , & V_191 ) ;
if ( V_191 )
F_72 ( V_2 , V_26 , & V_190 ) ;
if ( V_190 )
F_73 ( args , V_189 ) ;
F_58 ( V_2 , V_189 ) ;
if ( V_184 < F_39 ( V_193 [ 0 ] . V_122 ) ) {
int error ;
struct V_3 * V_76 ;
T_4 V_77 ;
int V_183 ;
T_5 * free ;
V_77 = V_2 -> V_10 -> V_130 ( args -> V_63 , V_114 ) ;
error = F_24 ( V_54 , V_2 ,
F_28 ( args -> V_63 , V_77 ) ,
& V_76 ) ;
if ( error )
return error ;
free = V_76 -> V_7 ;
#ifdef F_33
{
struct V_62 V_84 ;
V_2 -> V_10 -> V_86 ( & V_84 , free ) ;
ASSERT ( V_84 . V_45 == V_2 -> V_10 -> V_47 ( args -> V_63 ) *
( V_77 - F_18 ( args -> V_63 ,
V_49 ) ) ) ;
}
#endif
V_183 = V_2 -> V_10 -> V_131 ( args -> V_63 , V_114 ) ;
V_184 = F_39 ( V_193 [ 0 ] . V_122 ) ;
if ( V_184 == args -> V_63 -> V_90 -
V_2 -> V_10 -> V_195 ) {
error = F_68 ( args , V_114 , V_189 ) ;
if ( error == 0 ) {
V_187 -> V_4 = NULL ;
V_26 = NULL ;
}
else if ( ! ( error == - V_108 && args -> V_186 == 0 ) )
return error ;
}
error = F_67 ( args , V_26 , free ,
V_77 , V_183 , V_76 , V_184 ) ;
if ( error )
return error ;
}
F_42 ( V_2 , V_4 ) ;
* V_188 = ( V_2 -> V_10 -> V_196 +
( V_73 ) sizeof( V_103 [ 0 ] ) * ( V_9 . V_105 - V_9 . V_107 ) ) <
args -> V_63 -> V_197 ;
return 0 ;
}
int
F_74 (
T_14 * V_117 ,
T_17 * V_198 ,
T_17 * V_199 )
{
T_3 * args ;
T_1 V_17 ;
int error ;
struct V_1 * V_2 ;
args = V_117 -> args ;
V_2 = args -> V_2 ;
ASSERT ( V_198 -> V_12 == V_19 ) ;
error = F_75 ( args , & V_17 ) ;
if ( error ) {
return error ;
}
error = F_76 ( args , F_17 ( args -> V_63 , V_17 ) ,
& V_199 -> V_4 , V_19 ) ;
if ( error )
return error ;
V_199 -> V_17 = V_17 ;
V_199 -> V_12 = V_19 ;
F_64 ( V_117 , V_198 , V_199 ) ;
error = F_77 ( V_117 , V_198 , V_199 ) ;
if ( error ) {
return error ;
}
if ( V_117 -> V_179 )
error = F_43 ( V_198 -> V_4 , args , V_198 -> V_95 ) ;
else
error = F_43 ( V_199 -> V_4 , args , V_199 -> V_95 ) ;
V_198 -> V_109 = F_50 ( V_2 , V_198 -> V_4 , NULL ) ;
V_199 -> V_109 = F_50 ( V_2 , V_199 -> V_4 , NULL ) ;
F_42 ( V_2 , V_198 -> V_4 ) ;
F_42 ( V_2 , V_199 -> V_4 ) ;
return error ;
}
int
F_78 (
T_14 * V_117 ,
int * V_200 )
{
T_17 * V_201 ;
T_1 V_17 ;
struct V_3 * V_4 ;
int V_202 ;
int V_105 ;
int error ;
int V_203 ;
int V_79 ;
T_8 * V_6 ;
int V_188 ;
struct V_8 V_9 ;
struct V_102 * V_103 ;
struct V_1 * V_2 = V_117 -> args -> V_2 ;
V_201 = & V_117 -> V_204 . V_201 [ V_117 -> V_204 . V_205 - 1 ] ;
V_6 = V_201 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_103 = V_2 -> V_10 -> V_104 ( V_6 ) ;
F_42 ( V_2 , V_201 -> V_4 ) ;
V_105 = V_9 . V_105 - V_9 . V_107 ;
V_202 = V_2 -> V_10 -> V_196 + V_105 * sizeof( V_103 [ 0 ] ) ;
if ( V_202 > ( V_117 -> args -> V_63 -> V_90 >> 1 ) ) {
* V_200 = 0 ;
return 0 ;
}
if ( V_105 == 0 ) {
V_203 = ( V_9 . V_206 != 0 ) ;
memcpy ( & V_117 -> V_207 , & V_117 -> V_204 , sizeof( V_117 -> V_204 ) ) ;
error = F_79 ( V_117 , & V_117 -> V_207 , V_203 , 0 ,
& V_188 ) ;
if ( error )
return error ;
* V_200 = V_188 ? 2 : 0 ;
return 0 ;
}
V_203 = V_9 . V_206 < V_9 . V_208 ;
for ( V_79 = 0 , V_4 = NULL ; V_79 < 2 ; V_203 = ! V_203 , V_79 ++ ) {
struct V_8 V_168 ;
V_17 = V_203 ? V_9 . V_206 : V_9 . V_208 ;
if ( V_17 == 0 )
continue;
error = F_80 ( V_117 -> args -> V_61 , V_2 ,
V_17 , - 1 , & V_4 ) ;
if ( error )
return error ;
V_105 = V_9 . V_105 - V_9 . V_107 ;
V_202 = V_117 -> args -> V_63 -> V_90 -
( V_117 -> args -> V_63 -> V_90 >> 2 ) ;
V_6 = V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_168 , V_6 ) ;
V_103 = V_2 -> V_10 -> V_104 ( V_6 ) ;
V_105 += V_168 . V_105 - V_168 . V_107 ;
V_202 -= V_105 * sizeof( V_103 [ 0 ] ) ;
if ( V_202 >= 0 )
break;
F_22 ( V_117 -> args -> V_61 , V_4 ) ;
}
if ( V_79 >= 2 ) {
* V_200 = 0 ;
return 0 ;
}
memcpy ( & V_117 -> V_207 , & V_117 -> V_204 , sizeof( V_117 -> V_204 ) ) ;
if ( V_17 < V_201 -> V_17 )
error = F_79 ( V_117 , & V_117 -> V_207 , V_203 , 0 ,
& V_188 ) ;
else
error = F_79 ( V_117 , & V_117 -> V_204 , V_203 , 0 ,
& V_188 ) ;
if ( error ) {
return error ;
}
* V_200 = V_188 ? 0 : 1 ;
return 0 ;
}
void
F_81 (
T_14 * V_117 ,
T_17 * V_209 ,
T_17 * V_210 )
{
T_3 * args ;
T_8 * V_211 ;
T_8 * V_212 ;
struct V_8 V_213 ;
struct V_8 V_214 ;
struct V_102 * V_155 ;
struct V_102 * V_159 ;
struct V_1 * V_2 = V_117 -> args -> V_2 ;
args = V_117 -> args ;
ASSERT ( V_209 -> V_12 == V_19 ) ;
ASSERT ( V_210 -> V_12 == V_19 ) ;
V_211 = V_209 -> V_4 -> V_7 ;
V_212 = V_210 -> V_4 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_213 , V_212 ) ;
V_2 -> V_10 -> V_11 ( & V_214 , V_211 ) ;
V_155 = V_2 -> V_10 -> V_104 ( V_212 ) ;
V_159 = V_2 -> V_10 -> V_104 ( V_211 ) ;
if ( V_214 . V_107 )
F_82 ( args , & V_214 , V_209 -> V_4 ) ;
if ( V_213 . V_107 )
F_82 ( args , & V_213 , V_210 -> V_4 ) ;
V_209 -> V_109 = F_19 ( V_159 [ V_214 . V_105 - 1 ] . V_109 ) ;
if ( F_63 ( V_2 , V_210 -> V_4 , V_209 -> V_4 ) )
F_61 ( args , V_209 -> V_4 , & V_214 , V_159 , 0 ,
V_210 -> V_4 , & V_213 , V_155 , 0 ,
V_214 . V_105 ) ;
else
F_61 ( args , V_209 -> V_4 , & V_214 , V_159 , 0 ,
V_210 -> V_4 , & V_213 , V_155 ,
V_213 . V_105 , V_214 . V_105 ) ;
V_210 -> V_109 = F_19 ( V_155 [ V_213 . V_105 - 1 ] . V_109 ) ;
V_2 -> V_10 -> V_113 ( V_212 , & V_213 ) ;
V_2 -> V_10 -> V_113 ( V_211 , & V_214 ) ;
F_41 ( args , V_210 -> V_4 ) ;
F_41 ( args , V_209 -> V_4 ) ;
F_42 ( V_2 , V_210 -> V_4 ) ;
F_42 ( V_2 , V_209 -> V_4 ) ;
}
int
F_83 (
T_3 * args )
{
T_17 * V_201 ;
int error ;
int V_188 ;
T_14 * V_117 ;
F_84 ( args ) ;
V_117 = F_85 () ;
V_117 -> args = args ;
V_117 -> V_22 = args -> V_2 -> V_20 ;
error = F_86 ( V_117 , & V_188 ) ;
if ( error )
V_188 = error ;
if ( V_188 != - V_135 ) {
goto V_215;
}
V_188 = F_87 ( args ,
V_117 -> V_125 ? & V_117 -> V_126 : NULL ) ;
if ( V_188 ) {
goto V_215;
}
V_201 = & V_117 -> V_204 . V_201 [ V_117 -> V_204 . V_205 - 1 ] ;
ASSERT ( V_201 -> V_12 == V_19 ) ;
V_188 = F_43 ( V_201 -> V_4 , args , V_201 -> V_95 ) ;
if ( V_188 == 0 ) {
if ( ! ( args -> V_110 & V_111 ) )
F_88 ( V_117 , & V_117 -> V_204 ) ;
} else {
if ( args -> V_186 == 0 ) {
ASSERT ( V_188 == - V_108 ) ;
goto V_215;
}
V_188 = F_89 ( V_117 ) ;
}
V_215:
F_90 ( V_117 ) ;
return V_188 ;
}
static int
F_87 (
T_3 * args ,
T_17 * V_216 )
{
T_18 * V_26 ;
T_4 V_217 ;
struct V_3 * V_189 ;
T_16 * V_136 ;
T_7 * V_2 ;
T_19 * V_218 ;
int error ;
T_4 V_44 ;
struct V_3 * V_76 ;
int V_183 ;
T_5 * free = NULL ;
T_4 V_219 ;
T_4 V_220 = 0 ;
int V_122 ;
int V_185 ;
T_15 * V_22 ;
int V_190 ;
int V_191 ;
T_6 * V_221 ;
T_11 * V_54 ;
T_6 * V_71 ;
struct V_62 V_84 ;
struct V_192 * V_193 ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_54 = args -> V_61 ;
V_122 = V_2 -> V_10 -> V_127 ( args -> V_128 ) ;
if ( V_216 ) {
V_76 = V_216 -> V_4 ;
V_219 = V_216 -> V_17 ;
free = V_76 -> V_7 ;
V_183 = V_216 -> V_95 ;
V_71 = V_2 -> V_10 -> V_72 ( free ) ;
V_2 -> V_10 -> V_86 ( & V_84 , free ) ;
if ( V_183 >= 0 ) {
ASSERT ( V_183 < V_84 . V_51 ) ;
ASSERT ( F_39 ( V_71 [ V_183 ] ) != V_91 ) ;
ASSERT ( F_39 ( V_71 [ V_183 ] ) >= V_122 ) ;
V_217 = V_84 . V_45 + V_183 ;
} else {
V_217 = - 1 ;
V_183 = 0 ;
}
} else {
V_219 = V_217 = - 1 ;
V_76 = NULL ;
V_183 = 0 ;
}
if ( V_217 == - 1 ) {
T_20 V_222 ;
if ( ( error = F_91 ( V_2 , & V_222 , V_58 ) ) )
return error ;
V_220 = F_17 ( args -> V_63 , ( T_1 ) V_222 ) ;
V_44 = V_219 ;
}
while ( V_217 == - 1 ) {
if ( V_76 == NULL ) {
if ( ++ V_44 == 0 )
V_44 = F_18 ( args -> V_63 ,
V_49 ) ;
if ( V_44 == V_219 )
V_44 ++ ;
if ( V_44 >= V_220 )
break;
error = F_25 ( V_54 , V_2 ,
F_28 ( args -> V_63 , V_44 ) ,
& V_76 ) ;
if ( error )
return error ;
if ( ! V_76 )
continue;
free = V_76 -> V_7 ;
V_183 = 0 ;
}
V_71 = V_2 -> V_10 -> V_72 ( free ) ;
V_2 -> V_10 -> V_86 ( & V_84 , free ) ;
if ( F_39 ( V_71 [ V_183 ] ) != V_91 &&
F_39 ( V_71 [ V_183 ] ) >= V_122 )
V_217 = V_84 . V_45 + V_183 ;
else {
if ( ++ V_183 == V_84 . V_51 ) {
F_22 ( V_54 , V_76 ) ;
V_76 = NULL ;
if ( V_216 && V_216 -> V_4 )
V_216 -> V_4 = NULL ;
}
}
}
if ( F_54 ( V_217 == - 1 ) ) {
if ( ( args -> V_110 & V_111 ) || args -> V_186 == 0 )
return - V_108 ;
if ( F_54 ( ( error = F_36 ( args ,
V_223 ,
& V_217 ) ) ||
( error = F_92 ( args , V_217 , & V_189 ) ) ) )
return error ;
if ( V_76 )
F_22 ( V_54 , V_76 ) ;
if ( V_216 && V_216 -> V_4 )
V_216 -> V_4 = NULL ;
V_44 = V_2 -> V_10 -> V_130 ( args -> V_63 , V_217 ) ;
error = F_25 ( V_54 , V_2 ,
F_28 ( args -> V_63 , V_44 ) ,
& V_76 ) ;
if ( error )
return error ;
if ( ! V_76 ) {
error = F_36 ( args , V_85 ,
& V_44 ) ;
if ( error )
return error ;
if ( V_2 -> V_10 -> V_130 ( args -> V_63 , V_217 ) != V_44 ) {
F_66 ( V_22 ,
L_3 ,
V_180 , ( unsigned long long ) V_2 -> V_66 ,
( long long ) V_2 -> V_10 -> V_130 (
args -> V_63 , V_217 ) ,
( long long ) V_217 , ( long long ) V_44 ,
( unsigned long long ) V_219 , V_220 ) ;
if ( V_216 ) {
F_66 ( V_22 ,
L_4 ,
V_216 ,
( unsigned long long ) V_216 -> V_17 ,
V_216 -> V_95 ,
V_216 -> V_12 ) ;
} else {
F_66 ( V_22 , L_5 ) ;
}
F_55 ( L_6 ,
V_132 , V_22 ) ;
return - V_37 ;
}
error = F_26 ( args , V_44 , & V_76 ) ;
if ( error )
return error ;
free = V_76 -> V_7 ;
V_71 = V_2 -> V_10 -> V_72 ( free ) ;
V_2 -> V_10 -> V_86 ( & V_84 , free ) ;
V_84 . V_45 =
( V_44 - F_18 ( args -> V_63 ,
V_49 ) ) *
V_2 -> V_10 -> V_47 ( args -> V_63 ) ;
} else {
free = V_76 -> V_7 ;
V_71 = V_2 -> V_10 -> V_72 ( free ) ;
V_2 -> V_10 -> V_86 ( & V_84 , free ) ;
}
V_183 = V_2 -> V_10 -> V_131 ( args -> V_63 , V_217 ) ;
if ( V_183 >= V_84 . V_51 ) {
ASSERT ( V_183 < V_2 -> V_10 -> V_47 ( args -> V_63 ) ) ;
V_84 . V_51 = V_183 + 1 ;
V_71 [ V_183 ] = F_40 ( V_91 ) ;
}
if ( V_71 [ V_183 ] == F_40 ( V_91 ) ) {
V_84 . V_52 ++ ;
V_2 -> V_10 -> V_67 ( V_76 -> V_7 , & V_84 ) ;
F_32 ( args , V_76 ) ;
}
V_26 = V_189 -> V_7 ;
V_193 = V_2 -> V_10 -> V_194 ( V_26 ) ;
V_71 [ V_183 ] = V_193 [ 0 ] . V_122 ;
V_185 = 1 ;
}
else {
if ( args -> V_110 & V_111 )
return 0 ;
error = F_57 ( V_54 , V_2 ,
F_28 ( args -> V_63 , V_217 ) ,
- 1 , & V_189 ) ;
if ( error )
return error ;
V_26 = V_189 -> V_7 ;
V_193 = V_2 -> V_10 -> V_194 ( V_26 ) ;
V_185 = 0 ;
}
ASSERT ( F_39 ( V_193 [ 0 ] . V_122 ) >= V_122 ) ;
V_218 = ( T_19 * )
( ( char * ) V_26 + F_39 ( V_193 [ 0 ] . V_224 ) ) ;
V_191 = V_190 = 0 ;
F_93 ( args , V_189 , V_218 ,
( V_225 ) ( ( char * ) V_218 - ( char * ) V_26 ) , V_122 ,
& V_190 , & V_191 ) ;
V_136 = ( T_16 * ) V_218 ;
V_136 -> V_144 = F_14 ( args -> V_144 ) ;
V_136 -> V_128 = args -> V_128 ;
memcpy ( V_136 -> V_143 , args -> V_143 , V_136 -> V_128 ) ;
V_2 -> V_10 -> V_226 ( V_136 , args -> V_145 ) ;
V_221 = V_2 -> V_10 -> V_227 ( V_136 ) ;
* V_221 = F_40 ( ( char * ) V_136 - ( char * ) V_26 ) ;
F_94 ( args , V_189 , V_136 ) ;
if ( V_191 )
F_72 ( V_2 , V_26 , & V_190 ) ;
if ( V_190 )
F_73 ( args , V_189 ) ;
V_71 = V_2 -> V_10 -> V_72 ( free ) ;
if ( F_39 ( V_71 [ V_183 ] ) != F_39 ( V_193 [ 0 ] . V_122 ) ) {
V_71 [ V_183 ] = V_193 [ 0 ] . V_122 ;
V_185 = 1 ;
}
if ( V_185 )
F_30 ( args , V_76 , V_183 , V_183 ) ;
args -> V_17 = ( T_1 ) V_217 ;
args -> V_95 = F_39 ( * V_221 ) ;
return 0 ;
}
int
F_95 (
T_3 * args )
{
int error ;
int V_79 ;
int V_188 ;
T_14 * V_117 ;
F_96 ( args ) ;
V_117 = F_85 () ;
V_117 -> args = args ;
V_117 -> V_22 = args -> V_2 -> V_20 ;
error = F_86 ( V_117 , & V_188 ) ;
if ( error )
V_188 = error ;
else if ( V_188 == - V_135 && args -> V_139 == V_228 ) {
T_16 * V_136 ;
V_136 = ( T_16 * )
( ( char * ) V_117 -> V_126 . V_4 -> V_7 +
V_117 -> V_126 . V_95 ) ;
V_188 = F_97 ( args , V_136 -> V_143 , V_136 -> V_128 ) ;
}
for ( V_79 = 0 ; V_79 < V_117 -> V_204 . V_205 ; V_79 ++ ) {
F_22 ( args -> V_61 , V_117 -> V_204 . V_201 [ V_79 ] . V_4 ) ;
V_117 -> V_204 . V_201 [ V_79 ] . V_4 = NULL ;
}
if ( V_117 -> V_125 && V_117 -> V_126 . V_4 ) {
F_22 ( args -> V_61 , V_117 -> V_126 . V_4 ) ;
V_117 -> V_126 . V_4 = NULL ;
}
F_90 ( V_117 ) ;
return V_188 ;
}
int
F_98 (
struct V_68 * args )
{
struct V_229 * V_201 ;
int error ;
int V_188 ;
struct V_230 * V_117 ;
F_99 ( args ) ;
V_117 = F_85 () ;
V_117 -> args = args ;
V_117 -> V_22 = args -> V_2 -> V_20 ;
error = F_86 ( V_117 , & V_188 ) ;
if ( error )
goto V_231;
if ( V_188 != - V_151 ) {
error = V_188 ;
goto V_231;
}
V_201 = & V_117 -> V_204 . V_201 [ V_117 -> V_204 . V_205 - 1 ] ;
ASSERT ( V_201 -> V_12 == V_19 ) ;
ASSERT ( V_117 -> V_125 ) ;
error = F_69 ( args , V_201 -> V_4 , V_201 -> V_95 ,
& V_117 -> V_126 , & V_188 ) ;
if ( error )
goto V_231;
F_88 ( V_117 , & V_117 -> V_204 ) ;
if ( V_188 && V_117 -> V_204 . V_205 > 1 )
error = F_100 ( V_117 ) ;
if ( ! error )
error = F_101 ( V_117 ) ;
V_231:
F_90 ( V_117 ) ;
return error ;
}
int
F_102 (
T_3 * args )
{
T_17 * V_201 ;
T_18 * V_26 ;
T_16 * V_136 ;
int error ;
int V_79 ;
T_21 V_232 ;
int V_233 ;
T_8 * V_6 ;
T_12 * V_98 ;
int V_188 ;
T_14 * V_117 ;
F_103 ( args ) ;
V_117 = F_85 () ;
V_117 -> args = args ;
V_117 -> V_22 = args -> V_2 -> V_20 ;
V_232 = args -> V_144 ;
V_233 = args -> V_145 ;
error = F_86 ( V_117 , & V_188 ) ;
if ( error ) {
V_188 = error ;
}
if ( V_188 == - V_151 ) {
struct V_102 * V_103 ;
V_201 = & V_117 -> V_204 . V_201 [ V_117 -> V_204 . V_205 - 1 ] ;
ASSERT ( V_201 -> V_12 == V_19 ) ;
V_6 = V_201 -> V_4 -> V_7 ;
V_103 = args -> V_2 -> V_10 -> V_104 ( V_6 ) ;
V_98 = & V_103 [ V_201 -> V_95 ] ;
ASSERT ( V_117 -> V_125 ) ;
V_26 = V_117 -> V_126 . V_4 -> V_7 ;
ASSERT ( V_26 -> V_12 == F_6 ( V_147 ) ||
V_26 -> V_12 == F_6 ( V_234 ) ) ;
V_136 = ( T_16 * )
( ( char * ) V_26 +
F_59 ( args -> V_63 ,
F_19 ( V_98 -> V_112 ) ) ) ;
ASSERT ( V_232 != F_2 ( V_136 -> V_144 ) ) ;
V_136 -> V_144 = F_14 ( V_232 ) ;
args -> V_2 -> V_10 -> V_226 ( V_136 , V_233 ) ;
F_94 ( args , V_117 -> V_126 . V_4 , V_136 ) ;
V_188 = 0 ;
}
else if ( V_117 -> V_125 ) {
F_22 ( args -> V_61 , V_117 -> V_126 . V_4 ) ;
V_117 -> V_126 . V_4 = NULL ;
}
for ( V_79 = 0 ; V_79 < V_117 -> V_204 . V_205 ; V_79 ++ ) {
F_22 ( args -> V_61 , V_117 -> V_204 . V_201 [ V_79 ] . V_4 ) ;
V_117 -> V_204 . V_201 [ V_79 ] . V_4 = NULL ;
}
F_90 ( V_117 ) ;
return V_188 ;
}
int
F_104 (
T_3 * args ,
T_20 V_222 ,
int * V_235 )
{
struct V_3 * V_4 ;
T_7 * V_2 ;
int error ;
T_5 * free ;
T_11 * V_54 ;
struct V_62 V_84 ;
V_2 = args -> V_2 ;
V_54 = args -> V_61 ;
* V_235 = 0 ;
error = F_25 ( V_54 , V_2 , V_222 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_4 )
return 0 ;
free = V_4 -> V_7 ;
V_2 -> V_10 -> V_86 ( & V_84 , free ) ;
if ( V_84 . V_52 > 0 ) {
F_22 ( V_54 , V_4 ) ;
return 0 ;
}
error = F_68 ( args ,
F_17 ( args -> V_63 , ( T_1 ) V_222 ) , V_4 ) ;
if ( error ) {
ASSERT ( error != - V_108 ) ;
F_22 ( V_54 , V_4 ) ;
return error ;
}
* V_235 = 1 ;
return 0 ;
}
