static bool
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
F_2 ( & V_9 , V_6 ) ;
if ( V_9 . V_10 == V_11 ) {
struct V_12 * V_13 = V_4 -> V_7 ;
if ( F_3 ( V_13 -> V_14 . V_15 ) != V_4 -> V_16 )
return false ;
} else if ( V_9 . V_10 != V_17 )
return false ;
return F_4 ( V_2 , & V_9 , V_6 ) ;
}
static bool
F_5 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_18 -> V_19 ;
struct V_20 * V_21 = V_4 -> V_7 ;
if ( F_6 ( & V_2 -> V_22 ) ) {
struct V_23 * V_24 = V_4 -> V_7 ;
if ( V_24 -> V_10 != F_7 ( V_25 ) )
return false ;
if ( ! F_8 ( & V_24 -> V_26 , & V_2 -> V_22 . V_27 ) )
return false ;
if ( F_3 ( V_24 -> V_15 ) != V_4 -> V_16 )
return false ;
} else {
if ( V_21 -> V_10 != F_7 ( V_28 ) )
return false ;
}
return true ;
}
static void
F_9 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_18 -> V_19 ;
if ( ( F_6 ( & V_2 -> V_22 ) &&
! F_10 ( V_4 -> V_7 , F_11 ( V_4 -> V_29 ) ,
V_30 ) ) ||
! F_5 ( V_4 ) ) {
F_12 ( V_31 , V_32 , V_2 , V_4 -> V_7 ) ;
F_13 ( V_4 , V_33 ) ;
}
}
static void
F_14 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_18 -> V_19 ;
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_23 * V_24 = V_4 -> V_7 ;
if ( ! F_5 ( V_4 ) ) {
F_12 ( V_31 , V_32 , V_2 , V_4 -> V_7 ) ;
F_13 ( V_4 , V_33 ) ;
return;
}
if ( ! F_6 ( & V_2 -> V_22 ) )
return;
if ( V_35 )
V_24 -> V_37 = F_15 ( V_35 -> V_38 . V_39 ) ;
F_16 ( V_4 -> V_7 , F_11 ( V_4 -> V_29 ) , V_30 ) ;
}
static int
F_17 (
struct V_40 * V_41 ,
struct V_42 * V_43 ,
T_1 V_44 ,
T_2 V_45 ,
struct V_3 * * V_46 )
{
int V_47 ;
V_47 = F_18 ( V_41 , V_43 , V_44 , V_45 , V_46 ,
V_48 , & V_49 ) ;
if ( ! V_47 && V_41 && * V_46 )
F_19 ( V_41 , * V_46 , V_50 ) ;
return V_47 ;
}
int
F_20 (
struct V_40 * V_41 ,
struct V_42 * V_43 ,
T_1 V_44 ,
struct V_3 * * V_46 )
{
return F_17 ( V_41 , V_43 , V_44 , - 1 , V_46 ) ;
}
static int
F_21 (
struct V_40 * V_41 ,
struct V_42 * V_43 ,
T_1 V_44 ,
struct V_3 * * V_46 )
{
return F_17 ( V_41 , V_43 , V_44 , - 2 , V_46 ) ;
}
void
F_22 (
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
if ( V_54 -> V_21 . V_10 == F_7 ( V_28 ) ) {
V_52 -> V_10 = F_23 ( V_54 -> V_21 . V_10 ) ;
V_52 -> V_55 = F_23 ( V_54 -> V_21 . V_55 ) ;
V_52 -> V_56 = F_23 ( V_54 -> V_21 . V_56 ) ;
V_52 -> V_57 = F_23 ( V_54 -> V_21 . V_57 ) ;
} else {
struct V_58 * V_24 = (struct V_58 * ) V_54 ;
V_52 -> V_10 = F_23 ( V_24 -> V_21 . V_10 ) ;
V_52 -> V_55 = F_23 ( V_24 -> V_55 ) ;
V_52 -> V_56 = F_23 ( V_24 -> V_56 ) ;
V_52 -> V_57 = F_23 ( V_24 -> V_57 ) ;
}
ASSERT ( V_52 -> V_10 == V_28 ||
V_52 -> V_10 == V_25 ) ;
}
static void
F_24 (
struct V_53 * V_52 ,
struct V_51 * V_54 )
{
ASSERT ( V_54 -> V_10 == V_28 ||
V_54 -> V_10 == V_25 ) ;
if ( V_54 -> V_10 == V_28 ) {
V_52 -> V_21 . V_10 = F_7 ( V_54 -> V_10 ) ;
V_52 -> V_21 . V_55 = F_7 ( V_54 -> V_55 ) ;
V_52 -> V_21 . V_56 = F_7 ( V_54 -> V_56 ) ;
V_52 -> V_21 . V_57 = F_7 ( V_54 -> V_57 ) ;
} else {
struct V_58 * V_24 = (struct V_58 * ) V_52 ;
V_24 -> V_21 . V_10 = F_7 ( V_54 -> V_10 ) ;
V_24 -> V_55 = F_7 ( V_54 -> V_55 ) ;
V_24 -> V_56 = F_7 ( V_54 -> V_56 ) ;
V_24 -> V_57 = F_7 ( V_54 -> V_57 ) ;
}
}
static int
F_25 (
struct V_40 * V_41 ,
struct V_42 * V_43 ,
T_3 V_44 ,
struct V_3 * * V_46 )
{
struct V_1 * V_2 = V_43 -> V_59 ;
struct V_3 * V_4 ;
int error ;
struct V_51 V_21 ;
error = F_26 ( V_41 , V_43 , F_27 ( V_2 , V_44 ) ,
- 1 , & V_4 , V_48 ) ;
if ( error )
return error ;
F_19 ( V_41 , V_4 , V_50 ) ;
V_4 -> V_60 = & V_49 ;
memset ( V_4 -> V_7 , 0 , sizeof( struct V_58 ) ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
if ( F_6 ( & V_2 -> V_22 ) ) {
struct V_58 * V_24 = V_4 -> V_7 ;
V_21 . V_10 = V_25 ;
V_24 -> V_21 . V_15 = F_15 ( V_4 -> V_16 ) ;
V_24 -> V_21 . V_61 = F_15 ( V_43 -> V_62 ) ;
F_28 ( & V_24 -> V_21 . V_26 , & V_2 -> V_22 . V_27 ) ;
} else
V_21 . V_10 = V_28 ;
F_24 ( V_4 -> V_7 , & V_21 ) ;
* V_46 = V_4 ;
return 0 ;
}
STATIC void
F_29 (
struct V_40 * V_41 ,
struct V_3 * V_4 ,
int V_63 ,
int V_64 )
{
T_4 * free ;
T_5 * V_65 ;
free = V_4 -> V_7 ;
V_65 = F_30 ( V_41 -> V_66 , free ) ;
ASSERT ( free -> V_21 . V_10 == F_7 ( V_28 ) ||
free -> V_21 . V_10 == F_7 ( V_25 ) ) ;
F_31 ( V_41 , V_4 ,
( V_67 ) ( ( char * ) & V_65 [ V_63 ] - ( char * ) free ) ,
( V_67 ) ( ( char * ) & V_65 [ V_64 ] - ( char * ) free +
sizeof( V_65 [ 0 ] ) - 1 ) ) ;
}
static void
F_32 (
struct V_40 * V_41 ,
struct V_3 * V_4 )
{
T_4 * free ;
free = V_4 -> V_7 ;
ASSERT ( free -> V_21 . V_10 == F_7 ( V_28 ) ||
free -> V_21 . V_10 == F_7 ( V_25 ) ) ;
F_31 ( V_41 , V_4 , 0 , F_33 ( V_41 -> V_66 ) - 1 ) ;
}
int
F_34 (
T_6 * args ,
struct V_3 * V_68 )
{
T_7 * V_43 ;
int error ;
struct V_3 * V_69 ;
T_3 V_70 ;
T_4 * free ;
T_5 * V_54 ;
int V_71 ;
T_8 * V_6 ;
T_9 * V_72 ;
T_10 * V_2 ;
int V_73 ;
T_11 V_74 ;
T_5 * V_52 ;
T_12 * V_41 ;
struct V_51 V_75 ;
F_35 ( args ) ;
V_43 = args -> V_43 ;
V_2 = V_43 -> V_59 ;
V_41 = args -> V_76 ;
if ( ( error = F_36 ( args , V_77 , & V_70 ) ) ) {
return error ;
}
ASSERT ( V_70 == F_37 ( V_2 ) ) ;
error = F_25 ( V_41 , V_43 , V_70 , & V_69 ) ;
if ( error )
return error ;
free = V_69 -> V_7 ;
F_22 ( & V_75 , free ) ;
V_6 = V_68 -> V_7 ;
V_72 = F_38 ( V_2 , V_6 ) ;
ASSERT ( F_23 ( V_72 -> V_78 ) <=
( V_67 ) V_43 -> V_79 . V_80 / V_2 -> V_81 ) ;
V_54 = F_39 ( V_72 ) ;
V_52 = F_30 ( V_2 , free ) ;
for ( V_71 = V_73 = 0 ; V_71 < F_23 ( V_72 -> V_78 ) ; V_71 ++ , V_54 ++ , V_52 ++ ) {
if ( ( V_74 = F_40 ( * V_54 ) ) != V_82 )
V_73 ++ ;
* V_52 = F_41 ( V_74 ) ;
}
V_75 . V_57 = V_73 ;
V_75 . V_56 = F_23 ( V_72 -> V_78 ) ;
F_24 ( V_69 -> V_7 , & V_75 ) ;
F_29 ( V_41 , V_69 , 0 , V_75 . V_56 - 1 ) ;
F_32 ( V_41 , V_69 ) ;
if ( V_6 -> V_21 . V_14 . V_10 == F_41 ( V_83 ) )
V_6 -> V_21 . V_14 . V_10 = F_41 ( V_17 ) ;
else
V_6 -> V_21 . V_14 . V_10 = F_41 ( V_11 ) ;
V_68 -> V_60 = & V_84 ;
F_19 ( V_41 , V_68 , V_85 ) ;
F_42 ( V_41 , V_68 ) ;
F_43 ( V_2 , V_68 ) ;
return 0 ;
}
static int
F_44 (
struct V_3 * V_4 ,
T_6 * args ,
int V_86 )
{
int V_87 ;
T_7 * V_43 ;
int V_88 ;
T_8 * V_6 ;
T_13 * V_89 ;
int V_90 ;
int V_91 ;
int V_92 ;
T_10 * V_2 ;
T_12 * V_41 ;
struct V_8 V_9 ;
struct V_93 * V_94 ;
F_45 ( args , V_86 ) ;
V_43 = args -> V_43 ;
V_2 = V_43 -> V_59 ;
V_41 = args -> V_76 ;
V_6 = V_4 -> V_7 ;
F_2 ( & V_9 , V_6 ) ;
V_94 = F_46 ( V_6 ) ;
if ( V_86 < 0 )
return F_47 ( V_33 ) ;
if ( V_9 . V_95 == F_48 ( V_2 , V_6 ) ) {
if ( ! V_9 . V_96 )
return F_47 ( V_97 ) ;
V_87 = V_9 . V_96 > 1 ;
} else
V_87 = 0 ;
ASSERT ( V_86 == 0 || F_23 ( V_94 [ V_86 - 1 ] . V_98 ) <= args -> V_98 ) ;
ASSERT ( V_86 == V_9 . V_95 ||
F_23 ( V_94 [ V_86 ] . V_98 ) >= args -> V_98 ) ;
if ( args -> V_99 & V_100 )
return 0 ;
if ( V_87 )
F_49 ( & V_9 , V_94 , & V_86 , & V_92 ,
& V_88 , & V_91 , & V_90 ) ;
else if ( V_9 . V_96 ) {
V_91 = V_9 . V_95 ;
V_90 = - 1 ;
}
V_89 = F_50 ( & V_9 , V_94 , V_86 , V_87 , V_92 ,
V_88 , & V_91 , & V_90 ) ;
V_89 -> V_98 = F_7 ( args -> V_98 ) ;
V_89 -> V_101 = F_7 ( F_51 ( V_2 ,
args -> V_15 , args -> V_86 ) ) ;
F_52 ( V_6 , & V_9 ) ;
F_42 ( V_41 , V_4 ) ;
F_53 ( V_41 , V_4 , V_91 , V_90 ) ;
F_43 ( V_2 , V_4 ) ;
return 0 ;
}
static void
F_54 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_51 V_21 ;
F_22 ( & V_21 , V_4 -> V_7 ) ;
ASSERT ( ( V_21 . V_55 % F_55 ( V_2 ) ) == 0 ) ;
ASSERT ( V_21 . V_55 <= V_102 ) ;
ASSERT ( V_102 < V_21 . V_55 + V_21 . V_56 ) ;
}
T_14
F_56 (
struct V_3 * V_4 ,
int * V_95 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_93 * V_94 ;
struct V_8 V_9 ;
F_2 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_10 == V_17 ||
V_9 . V_10 == V_11 ) ;
if ( V_95 )
* V_95 = V_9 . V_95 ;
if ( ! V_9 . V_95 )
return 0 ;
V_94 = F_46 ( V_6 ) ;
return F_23 ( V_94 [ V_9 . V_95 - 1 ] . V_98 ) ;
}
STATIC int
F_57 (
struct V_3 * V_4 ,
T_6 * args ,
int * V_103 ,
T_15 * V_104 )
{
struct V_3 * V_105 = NULL ;
T_3 V_106 = - 1 ;
T_3 V_107 = - 1 ;
T_7 * V_43 ;
int error ;
int V_108 ;
T_4 * free = NULL ;
int V_86 ;
T_8 * V_6 ;
int V_109 ;
T_13 * V_89 ;
T_10 * V_2 ;
T_3 V_110 ;
T_3 V_111 ;
T_12 * V_41 ;
struct V_93 * V_94 ;
struct V_8 V_9 ;
V_43 = args -> V_43 ;
V_41 = args -> V_76 ;
V_2 = V_43 -> V_59 ;
V_6 = V_4 -> V_7 ;
F_2 ( & V_9 , V_6 ) ;
V_94 = F_46 ( V_6 ) ;
F_43 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_95 > 0 ) ;
V_86 = F_58 ( args , V_4 ) ;
if ( V_104 -> V_112 ) {
V_105 = V_104 -> V_113 . V_4 ;
V_107 = V_104 -> V_113 . V_15 ;
free = V_105 -> V_7 ;
ASSERT ( free -> V_21 . V_10 == F_7 ( V_28 ) ||
free -> V_21 . V_10 == F_7 ( V_25 ) ) ;
}
V_109 = F_59 ( args -> V_114 ) ;
for ( V_89 = & V_94 [ V_86 ] ;
V_86 < V_9 . V_95 && F_23 ( V_89 -> V_98 ) == args -> V_98 ;
V_89 ++ , V_86 ++ ) {
if ( F_23 ( V_89 -> V_101 ) == V_115 )
continue;
V_110 = F_60 ( V_2 , F_23 ( V_89 -> V_101 ) ) ;
if ( V_110 != V_106 ) {
T_5 * V_65 ;
V_106 = V_110 ;
V_111 = F_61 ( V_2 , V_110 ) ;
if ( V_111 != V_107 ) {
if ( V_105 )
F_62 ( V_41 , V_105 ) ;
error = F_20 ( V_41 , V_43 ,
F_27 ( V_2 , V_111 ) ,
& V_105 ) ;
if ( error )
return error ;
free = V_105 -> V_7 ;
F_54 ( V_2 , V_105 , V_106 ) ;
}
V_108 = F_63 ( V_2 , V_106 ) ;
V_65 = F_30 ( V_2 , free ) ;
if ( F_64 ( V_65 [ V_108 ] == F_41 ( V_82 ) ) ) {
F_65 ( L_1 ,
V_32 , V_2 ) ;
if ( V_107 != V_111 )
F_62 ( V_41 , V_105 ) ;
return F_47 ( V_33 ) ;
}
V_107 = V_111 ;
if ( F_40 ( V_65 [ V_108 ] ) >= V_109 )
goto V_116;
}
}
V_108 = - 1 ;
V_116:
ASSERT ( args -> V_99 & V_117 ) ;
if ( V_105 ) {
V_104 -> V_112 = 1 ;
V_104 -> V_113 . V_4 = V_105 ;
V_104 -> V_113 . V_86 = V_108 ;
V_104 -> V_113 . V_15 = V_107 ;
V_104 -> V_113 . V_10 = V_28 ;
} else {
V_104 -> V_112 = 0 ;
}
* V_103 = V_86 ;
return F_47 ( V_118 ) ;
}
STATIC int
F_66 (
struct V_3 * V_4 ,
T_6 * args ,
int * V_103 ,
T_15 * V_104 )
{
struct V_3 * V_105 = NULL ;
T_3 V_106 = - 1 ;
T_16 * V_119 ;
T_7 * V_43 ;
int error ;
int V_86 ;
T_8 * V_6 ;
T_13 * V_89 ;
T_10 * V_2 ;
T_3 V_110 ;
T_12 * V_41 ;
enum V_120 V_121 ;
struct V_93 * V_94 ;
struct V_8 V_9 ;
V_43 = args -> V_43 ;
V_41 = args -> V_76 ;
V_2 = V_43 -> V_59 ;
V_6 = V_4 -> V_7 ;
F_2 ( & V_9 , V_6 ) ;
V_94 = F_46 ( V_6 ) ;
F_43 ( V_2 , V_4 ) ;
ASSERT ( V_9 . V_95 > 0 ) ;
V_86 = F_58 ( args , V_4 ) ;
if ( V_104 -> V_112 ) {
V_105 = V_104 -> V_113 . V_4 ;
V_106 = V_104 -> V_113 . V_15 ;
}
for ( V_89 = & V_94 [ V_86 ] ;
V_86 < V_9 . V_95 && F_23 ( V_89 -> V_98 ) == args -> V_98 ;
V_89 ++ , V_86 ++ ) {
if ( F_23 ( V_89 -> V_101 ) == V_115 )
continue;
V_110 = F_60 ( V_2 , F_23 ( V_89 -> V_101 ) ) ;
if ( V_110 != V_106 ) {
if ( V_105 && ( args -> V_122 == V_123 ||
V_106 != V_104 -> V_113 . V_15 ) )
F_62 ( V_41 , V_105 ) ;
if ( args -> V_122 != V_123 &&
V_110 == V_104 -> V_113 . V_15 ) {
ASSERT ( V_104 -> V_112 ) ;
V_105 = V_104 -> V_113 . V_4 ;
} else {
error = F_67 ( V_41 , V_43 ,
F_27 ( V_2 , V_110 ) ,
- 1 , & V_105 ) ;
if ( error )
return error ;
}
F_68 ( V_43 , V_105 ) ;
V_106 = V_110 ;
}
V_119 = ( T_16 * ) ( ( char * ) V_105 -> V_7 +
F_69 ( V_2 , F_23 ( V_89 -> V_101 ) ) ) ;
V_121 = V_2 -> V_124 -> V_125 ( args , V_119 -> V_126 , V_119 -> V_114 ) ;
if ( V_121 != V_123 && V_121 != args -> V_122 ) {
if ( args -> V_122 != V_123 &&
V_106 != V_104 -> V_113 . V_15 )
F_62 ( V_41 , V_104 -> V_113 . V_4 ) ;
args -> V_122 = V_121 ;
args -> V_127 = F_3 ( V_119 -> V_127 ) ;
* V_103 = V_86 ;
V_104 -> V_112 = 1 ;
V_104 -> V_113 . V_4 = V_105 ;
V_104 -> V_113 . V_15 = V_106 ;
V_104 -> V_113 . V_86 = ( int ) ( ( char * ) V_119 -
( char * ) V_105 -> V_7 ) ;
V_104 -> V_113 . V_10 = V_128 ;
V_105 -> V_60 = & V_129 ;
F_19 ( V_41 , V_105 , V_130 ) ;
if ( V_121 == V_131 )
return F_47 ( V_132 ) ;
}
}
ASSERT ( V_86 == V_9 . V_95 || ( args -> V_99 & V_117 ) ) ;
if ( V_105 ) {
if ( args -> V_122 == V_123 ) {
V_104 -> V_112 = 1 ;
V_104 -> V_113 . V_4 = V_105 ;
V_104 -> V_113 . V_86 = - 1 ;
V_104 -> V_113 . V_15 = V_106 ;
V_104 -> V_113 . V_10 = V_128 ;
V_105 -> V_60 = & V_129 ;
F_19 ( V_41 , V_105 , V_130 ) ;
} else {
if ( V_104 -> V_113 . V_4 != V_105 )
F_62 ( V_41 , V_105 ) ;
}
} else {
V_104 -> V_112 = 0 ;
}
* V_103 = V_86 ;
return F_47 ( V_118 ) ;
}
int
F_70 (
struct V_3 * V_4 ,
T_6 * args ,
int * V_103 ,
T_15 * V_104 )
{
if ( args -> V_99 & V_133 )
return F_57 ( V_4 , args , V_103 ,
V_104 ) ;
return F_66 ( V_4 , args , V_103 , V_104 ) ;
}
static void
F_71 (
T_6 * args ,
struct V_3 * V_134 ,
struct V_8 * V_135 ,
struct V_93 * V_136 ,
int V_137 ,
struct V_3 * V_138 ,
struct V_8 * V_139 ,
struct V_93 * V_140 ,
int V_141 ,
int V_95 )
{
struct V_40 * V_41 = args -> V_76 ;
int V_96 ;
F_72 ( args , V_137 , V_141 , V_95 ) ;
if ( V_95 == 0 )
return;
if ( V_141 < V_139 -> V_95 ) {
memmove ( & V_140 [ V_141 + V_95 ] , & V_140 [ V_141 ] ,
( V_139 -> V_95 - V_141 ) * sizeof( T_13 ) ) ;
F_53 ( V_41 , V_138 , V_141 + V_95 ,
V_95 + V_139 -> V_95 - 1 ) ;
}
if ( V_135 -> V_96 ) {
int V_71 ;
for ( V_71 = V_137 , V_96 = 0 ; V_71 < V_137 + V_95 ; V_71 ++ ) {
if ( V_136 [ V_71 ] . V_101 ==
F_7 ( V_115 ) )
V_96 ++ ;
}
} else
V_96 = 0 ;
memcpy ( & V_140 [ V_141 ] , & V_136 [ V_137 ] ,
V_95 * sizeof( T_13 ) ) ;
F_53 ( V_41 , V_138 , V_141 , V_141 + V_95 - 1 ) ;
if ( V_137 + V_95 < V_135 -> V_95 ) {
memmove ( & V_136 [ V_137 ] , & V_136 [ V_137 + V_95 ] ,
V_95 * sizeof( T_13 ) ) ;
F_53 ( V_41 , V_134 , V_137 , V_137 + V_95 - 1 ) ;
}
V_135 -> V_95 -= V_95 ;
V_135 -> V_96 -= V_96 ;
V_139 -> V_95 += V_95 ;
V_139 -> V_96 += V_96 ;
}
int
F_73 (
struct V_3 * V_142 ,
struct V_3 * V_143 )
{
struct V_5 * V_144 = V_142 -> V_7 ;
struct V_5 * V_145 = V_143 -> V_7 ;
struct V_93 * V_146 ;
struct V_93 * V_147 ;
struct V_8 V_148 ;
struct V_8 V_149 ;
F_2 ( & V_148 , V_144 ) ;
F_2 ( & V_149 , V_145 ) ;
V_146 = F_46 ( V_144 ) ;
V_147 = F_46 ( V_145 ) ;
if ( V_148 . V_95 > 0 && V_149 . V_95 > 0 &&
( F_23 ( V_147 [ 0 ] . V_98 ) < F_23 ( V_146 [ 0 ] . V_98 ) ||
F_23 ( V_147 [ V_149 . V_95 - 1 ] . V_98 ) <
F_23 ( V_146 [ V_148 . V_95 - 1 ] . V_98 ) ) )
return 1 ;
return 0 ;
}
static void
F_74 (
T_15 * V_104 ,
T_17 * V_150 ,
T_17 * V_151 )
{
T_6 * args ;
int V_95 ;
int V_152 ;
T_8 * V_144 ;
T_8 * V_145 ;
int V_153 ;
#if F_75 ( V_154 ) || F_75 ( V_155 )
int V_156 ;
#endif
int V_157 ;
int V_158 ;
struct V_93 * V_146 ;
struct V_93 * V_147 ;
struct V_8 V_148 ;
struct V_8 V_149 ;
args = V_104 -> args ;
if ( ( V_158 = F_73 ( V_150 -> V_4 , V_151 -> V_4 ) ) ) {
T_17 * V_159 ;
V_159 = V_150 ;
V_150 = V_151 ;
V_151 = V_159 ;
}
V_144 = V_150 -> V_4 -> V_7 ;
V_145 = V_151 -> V_4 -> V_7 ;
F_2 ( & V_148 , V_144 ) ;
F_2 ( & V_149 , V_145 ) ;
V_146 = F_46 ( V_144 ) ;
V_147 = F_46 ( V_145 ) ;
V_157 = V_148 . V_95 + V_149 . V_95 ;
#if F_75 ( V_154 ) || F_75 ( V_155 )
V_156 = V_148 . V_96 + V_149 . V_96 ;
#endif
V_153 = V_157 >> 1 ;
if ( V_157 & 1 ) {
T_14 V_160 ;
if ( V_153 >= V_148 . V_95 )
V_160 = F_23 ( V_147 [ V_153 - V_148 . V_95 ] . V_98 ) ;
else
V_160 = F_23 ( V_146 [ V_153 ] . V_98 ) ;
V_152 = args -> V_98 <= V_160 ;
}
else
V_152 = 1 ;
V_95 = V_148 . V_95 - V_153 + ( V_152 == 0 ) ;
if ( V_95 > 0 )
F_71 ( args , V_150 -> V_4 , & V_148 , V_146 ,
V_148 . V_95 - V_95 , V_151 -> V_4 ,
& V_149 , V_147 , 0 , V_95 ) ;
else if ( V_95 < 0 )
F_71 ( args , V_151 -> V_4 , & V_149 , V_147 , 0 ,
V_150 -> V_4 , & V_148 , V_146 ,
V_148 . V_95 , V_95 ) ;
ASSERT ( V_148 . V_95 + V_149 . V_95 == V_157 ) ;
ASSERT ( V_148 . V_96 + V_149 . V_96 == V_156 ) ;
F_52 ( V_144 , & V_148 ) ;
F_52 ( V_145 , & V_149 ) ;
F_42 ( args -> V_76 , V_150 -> V_4 ) ;
F_42 ( args -> V_76 , V_151 -> V_4 ) ;
F_43 ( args -> V_43 -> V_59 , V_150 -> V_4 ) ;
F_43 ( args -> V_43 -> V_59 , V_151 -> V_4 ) ;
if ( V_148 . V_95 < V_149 . V_95 )
V_104 -> V_161 = V_158 ;
else if ( V_148 . V_95 > V_149 . V_95 )
V_104 -> V_161 = ! V_158 ;
else
V_104 -> V_161 = V_158 ^ ( V_150 -> V_86 <= V_148 . V_95 ) ;
if ( ! V_104 -> V_161 )
V_151 -> V_86 = V_150 -> V_86 - V_148 . V_95 ;
if( V_151 -> V_86 < 0 ) {
V_104 -> V_161 = 1 ;
V_151 -> V_86 = 0 ;
F_76 ( args -> V_43 -> V_59 ,
L_2 ,
V_31 , V_150 -> V_86 ) ;
}
}
static int
F_77 (
T_6 * args ,
struct V_162 * V_21 ,
struct V_53 * free ,
T_3 V_70 ,
int V_163 ,
struct V_3 * V_69 ,
int V_164 )
{
struct V_40 * V_41 = args -> V_76 ;
int V_165 = 0 ;
T_5 * V_65 ;
struct V_51 V_75 ;
F_22 ( & V_75 , free ) ;
V_65 = F_30 ( V_41 -> V_66 , free ) ;
if ( V_21 ) {
V_65 [ V_163 ] = F_41 ( V_164 ) ;
F_29 ( V_41 , V_69 , V_163 , V_163 ) ;
return 0 ;
}
V_75 . V_57 -- ;
if ( V_163 == V_75 . V_56 - 1 ) {
int V_71 ;
for ( V_71 = V_163 - 1 ; V_71 >= 0 ; V_71 -- ) {
if ( V_65 [ V_71 ] != F_41 ( V_82 ) )
break;
}
V_75 . V_56 = V_71 + 1 ;
V_165 = 0 ;
} else {
V_65 [ V_163 ] = F_41 ( V_82 ) ;
V_165 = 1 ;
}
F_24 ( free , & V_75 ) ;
F_32 ( V_41 , V_69 ) ;
if ( ! V_75 . V_57 ) {
int error ;
error = F_78 ( args , V_70 , V_69 ) ;
if ( error == 0 ) {
V_69 = NULL ;
V_165 = 0 ;
} else if ( error != V_97 || args -> V_166 != 0 )
return error ;
}
if ( V_165 )
F_29 ( V_41 , V_69 , V_163 , V_163 ) ;
return 0 ;
}
static int
F_79 (
T_6 * args ,
struct V_3 * V_4 ,
int V_86 ,
T_17 * V_167 ,
int * V_168 )
{
T_18 * V_21 ;
T_3 V_102 ;
struct V_3 * V_169 ;
T_16 * V_119 ;
T_7 * V_43 ;
T_8 * V_6 ;
T_13 * V_89 ;
int V_164 ;
int V_74 ;
T_10 * V_2 ;
int V_170 ;
int V_171 ;
T_12 * V_41 ;
struct V_172 * V_173 ;
struct V_8 V_9 ;
struct V_93 * V_94 ;
F_80 ( args , V_86 ) ;
V_43 = args -> V_43 ;
V_41 = args -> V_76 ;
V_2 = V_43 -> V_59 ;
V_6 = V_4 -> V_7 ;
F_2 ( & V_9 , V_6 ) ;
V_94 = F_46 ( V_6 ) ;
V_89 = & V_94 [ V_86 ] ;
V_102 = F_60 ( V_2 , F_23 ( V_89 -> V_101 ) ) ;
ASSERT ( V_167 -> V_15 == V_102 ) ;
V_74 = F_69 ( V_2 , F_23 ( V_89 -> V_101 ) ) ;
ASSERT ( V_167 -> V_86 == V_74 ) ;
V_9 . V_96 ++ ;
F_52 ( V_6 , & V_9 ) ;
F_42 ( V_41 , V_4 ) ;
V_89 -> V_101 = F_7 ( V_115 ) ;
F_53 ( V_41 , V_4 , V_86 , V_86 ) ;
V_169 = V_167 -> V_4 ;
V_21 = V_169 -> V_7 ;
V_119 = ( T_16 * ) ( ( char * ) V_21 + V_74 ) ;
V_173 = F_81 ( V_21 ) ;
V_164 = F_40 ( V_173 [ 0 ] . V_109 ) ;
V_170 = V_171 = 0 ;
F_82 ( V_41 , V_169 , V_74 ,
F_59 ( V_119 -> V_114 ) , & V_170 , & V_171 ) ;
if ( V_171 )
F_83 ( V_2 , V_21 , & V_170 ) ;
if ( V_170 )
F_84 ( V_41 , V_169 ) ;
F_68 ( V_43 , V_169 ) ;
if ( V_164 < F_40 ( V_173 [ 0 ] . V_109 ) ) {
int error ;
struct V_3 * V_69 ;
T_3 V_70 ;
int V_163 ;
T_4 * free ;
V_70 = F_61 ( V_2 , V_102 ) ;
error = F_20 ( V_41 , V_43 , F_27 ( V_2 , V_70 ) ,
& V_69 ) ;
if ( error )
return error ;
free = V_69 -> V_7 ;
#ifdef V_154
{
struct V_51 V_75 ;
F_22 ( & V_75 , free ) ;
ASSERT ( V_75 . V_55 == F_55 ( V_2 ) *
( V_70 - F_37 ( V_2 ) ) ) ;
}
#endif
V_163 = F_63 ( V_2 , V_102 ) ;
V_164 = F_40 ( V_173 [ 0 ] . V_109 ) ;
if ( V_164 == V_2 -> V_81 -
F_85 ( V_21 ) ) {
error = F_78 ( args , V_102 , V_169 ) ;
if ( error == 0 ) {
V_167 -> V_4 = NULL ;
V_21 = NULL ;
}
else if ( ! ( error == V_97 && args -> V_166 == 0 ) )
return error ;
}
error = F_77 ( args , V_21 , free ,
V_70 , V_163 , V_69 , V_164 ) ;
if ( error )
return error ;
}
F_43 ( V_2 , V_4 ) ;
* V_168 = ( F_86 ( V_6 ) +
( V_67 ) sizeof( V_94 [ 0 ] ) * ( V_9 . V_95 - V_9 . V_96 ) ) <
V_2 -> V_174 ;
return 0 ;
}
int
F_87 (
T_15 * V_104 ,
T_17 * V_175 ,
T_17 * V_176 )
{
T_6 * args ;
T_1 V_15 ;
int error ;
T_10 * V_2 ;
args = V_104 -> args ;
V_2 = args -> V_43 -> V_59 ;
ASSERT ( args != NULL ) ;
ASSERT ( V_175 -> V_10 == V_17 ) ;
error = F_88 ( args , & V_15 ) ;
if ( error ) {
return error ;
}
error = F_89 ( args , F_90 ( V_2 , V_15 ) ,
& V_176 -> V_4 , V_17 ) ;
if ( error )
return error ;
V_176 -> V_15 = V_15 ;
V_176 -> V_10 = V_17 ;
F_74 ( V_104 , V_175 , V_176 ) ;
error = F_91 ( V_104 , V_175 , V_176 ) ;
if ( error ) {
return error ;
}
if ( V_104 -> V_161 )
error = F_44 ( V_175 -> V_4 , args , V_175 -> V_86 ) ;
else
error = F_44 ( V_176 -> V_4 , args , V_176 -> V_86 ) ;
V_175 -> V_98 = F_56 ( V_175 -> V_4 , NULL ) ;
V_176 -> V_98 = F_56 ( V_176 -> V_4 , NULL ) ;
F_43 ( V_2 , V_175 -> V_4 ) ;
F_43 ( V_2 , V_176 -> V_4 ) ;
return error ;
}
int
F_92 (
T_15 * V_104 ,
int * V_177 )
{
T_17 * V_178 ;
T_1 V_15 ;
struct V_3 * V_4 ;
int V_179 ;
int V_95 ;
int error ;
int V_180 ;
int V_71 ;
T_8 * V_6 ;
int V_168 ;
struct V_8 V_9 ;
struct V_93 * V_94 ;
V_178 = & V_104 -> V_181 . V_178 [ V_104 -> V_181 . V_182 - 1 ] ;
V_6 = V_178 -> V_4 -> V_7 ;
F_2 ( & V_9 , V_6 ) ;
V_94 = F_46 ( V_6 ) ;
F_43 ( V_104 -> args -> V_43 -> V_59 , V_178 -> V_4 ) ;
V_95 = V_9 . V_95 - V_9 . V_96 ;
V_179 = F_86 ( V_6 ) + V_95 * sizeof( V_94 [ 0 ] ) ;
if ( V_179 > ( V_104 -> V_183 >> 1 ) ) {
* V_177 = 0 ;
return 0 ;
}
if ( V_95 == 0 ) {
V_180 = ( V_9 . V_184 != 0 ) ;
memcpy ( & V_104 -> V_185 , & V_104 -> V_181 , sizeof( V_104 -> V_181 ) ) ;
error = F_93 ( V_104 , & V_104 -> V_185 , V_180 , 0 ,
& V_168 ) ;
if ( error )
return error ;
* V_177 = V_168 ? 2 : 0 ;
return 0 ;
}
V_180 = V_9 . V_184 < V_9 . V_186 ;
for ( V_71 = 0 , V_4 = NULL ; V_71 < 2 ; V_180 = ! V_180 , V_71 ++ ) {
struct V_8 V_149 ;
V_15 = V_180 ? V_9 . V_184 : V_9 . V_186 ;
if ( V_15 == 0 )
continue;
error = F_94 ( V_104 -> args -> V_76 , V_104 -> args -> V_43 ,
V_15 , - 1 , & V_4 ) ;
if ( error )
return error ;
V_95 = V_9 . V_95 - V_9 . V_96 ;
V_179 = V_104 -> V_183 - ( V_104 -> V_183 >> 2 ) ;
V_6 = V_4 -> V_7 ;
F_2 ( & V_149 , V_6 ) ;
V_94 = F_46 ( V_6 ) ;
V_95 += V_149 . V_95 - V_149 . V_96 ;
V_179 -= V_95 * sizeof( V_94 [ 0 ] ) ;
if ( V_179 >= 0 )
break;
F_62 ( V_104 -> args -> V_76 , V_4 ) ;
}
if ( V_71 >= 2 ) {
* V_177 = 0 ;
return 0 ;
}
memcpy ( & V_104 -> V_185 , & V_104 -> V_181 , sizeof( V_104 -> V_181 ) ) ;
if ( V_15 < V_178 -> V_15 )
error = F_93 ( V_104 , & V_104 -> V_185 , V_180 , 0 ,
& V_168 ) ;
else
error = F_93 ( V_104 , & V_104 -> V_181 , V_180 , 0 ,
& V_168 ) ;
if ( error ) {
return error ;
}
* V_177 = V_168 ? 0 : 1 ;
return 0 ;
}
void
F_95 (
T_15 * V_104 ,
T_17 * V_187 ,
T_17 * V_188 )
{
T_6 * args ;
T_8 * V_189 ;
T_8 * V_190 ;
struct V_8 V_191 ;
struct V_8 V_192 ;
struct V_93 * V_136 ;
struct V_93 * V_140 ;
args = V_104 -> args ;
ASSERT ( V_187 -> V_10 == V_17 ) ;
ASSERT ( V_188 -> V_10 == V_17 ) ;
V_189 = V_187 -> V_4 -> V_7 ;
V_190 = V_188 -> V_4 -> V_7 ;
F_2 ( & V_191 , V_190 ) ;
F_2 ( & V_192 , V_189 ) ;
V_136 = F_46 ( V_190 ) ;
V_140 = F_46 ( V_189 ) ;
if ( V_192 . V_96 )
F_96 ( args , & V_192 , V_187 -> V_4 ) ;
if ( V_191 . V_96 )
F_96 ( args , & V_191 , V_188 -> V_4 ) ;
V_187 -> V_98 = F_23 ( V_140 [ V_192 . V_95 - 1 ] . V_98 ) ;
if ( F_73 ( V_188 -> V_4 , V_187 -> V_4 ) )
F_71 ( args , V_187 -> V_4 , & V_192 , V_140 , 0 ,
V_188 -> V_4 , & V_191 , V_136 , 0 ,
V_192 . V_95 ) ;
else
F_71 ( args , V_187 -> V_4 , & V_192 , V_140 , 0 ,
V_188 -> V_4 , & V_191 , V_136 ,
V_191 . V_95 , V_192 . V_95 ) ;
V_188 -> V_98 = F_23 ( V_136 [ V_191 . V_95 - 1 ] . V_98 ) ;
F_52 ( V_190 , & V_191 ) ;
F_52 ( V_189 , & V_192 ) ;
F_42 ( args -> V_76 , V_188 -> V_4 ) ;
F_42 ( args -> V_76 , V_187 -> V_4 ) ;
F_43 ( args -> V_43 -> V_59 , V_188 -> V_4 ) ;
F_43 ( args -> V_43 -> V_59 , V_187 -> V_4 ) ;
}
int
F_97 (
T_6 * args )
{
T_17 * V_178 ;
int error ;
int V_168 ;
T_15 * V_104 ;
F_98 ( args ) ;
V_104 = F_99 () ;
V_104 -> args = args ;
V_104 -> V_2 = args -> V_43 -> V_59 ;
V_104 -> V_183 = V_104 -> V_2 -> V_81 ;
V_104 -> V_193 = V_104 -> V_2 -> V_194 ;
error = F_100 ( V_104 , & V_168 ) ;
if ( error )
V_168 = error ;
if ( V_168 != V_118 ) {
goto V_195;
}
V_168 = F_101 ( args ,
V_104 -> V_112 ? & V_104 -> V_113 : NULL ) ;
if ( V_168 ) {
goto V_195;
}
V_178 = & V_104 -> V_181 . V_178 [ V_104 -> V_181 . V_182 - 1 ] ;
ASSERT ( V_178 -> V_10 == V_17 ) ;
V_168 = F_44 ( V_178 -> V_4 , args , V_178 -> V_86 ) ;
if ( V_168 == 0 ) {
if ( ! ( args -> V_99 & V_100 ) )
F_102 ( V_104 , & V_104 -> V_181 ) ;
} else {
if ( args -> V_166 == 0 ) {
ASSERT ( V_168 == V_97 ) ;
goto V_195;
}
V_168 = F_103 ( V_104 ) ;
}
V_195:
F_104 ( V_104 ) ;
return V_168 ;
}
static int
F_101 (
T_6 * args ,
T_17 * V_196 )
{
T_18 * V_21 ;
T_3 V_197 ;
struct V_3 * V_169 ;
T_16 * V_119 ;
T_7 * V_43 ;
T_19 * V_198 ;
int error ;
T_3 V_44 ;
struct V_3 * V_69 ;
int V_163 ;
T_4 * free = NULL ;
T_3 V_199 ;
T_3 V_200 = 0 ;
int V_109 ;
int V_165 ;
T_10 * V_2 ;
int V_170 ;
int V_171 ;
T_5 * V_201 ;
T_12 * V_41 ;
T_5 * V_65 ;
struct V_51 V_75 ;
struct V_172 * V_173 ;
V_43 = args -> V_43 ;
V_2 = V_43 -> V_59 ;
V_41 = args -> V_76 ;
V_109 = F_59 ( args -> V_114 ) ;
if ( V_196 ) {
V_69 = V_196 -> V_4 ;
V_199 = V_196 -> V_15 ;
free = V_69 -> V_7 ;
V_163 = V_196 -> V_86 ;
V_65 = F_30 ( V_2 , free ) ;
F_22 ( & V_75 , free ) ;
if ( V_163 >= 0 ) {
ASSERT ( V_163 < V_75 . V_56 ) ;
ASSERT ( F_40 ( V_65 [ V_163 ] ) != V_82 ) ;
ASSERT ( F_40 ( V_65 [ V_163 ] ) >= V_109 ) ;
V_197 = V_75 . V_55 + V_163 ;
} else {
V_197 = - 1 ;
V_163 = 0 ;
}
} else {
V_199 = V_197 = - 1 ;
V_69 = NULL ;
V_163 = 0 ;
}
if ( V_197 == - 1 ) {
T_20 V_202 ;
if ( ( error = F_105 ( V_41 , V_43 , & V_202 , V_48 ) ) )
return error ;
V_200 = F_90 ( V_2 , ( T_1 ) V_202 ) ;
V_44 = V_199 ;
}
while ( V_197 == - 1 ) {
if ( V_69 == NULL ) {
if ( ++ V_44 == 0 )
V_44 = F_37 ( V_2 ) ;
if ( V_44 == V_199 )
V_44 ++ ;
if ( V_44 >= V_200 )
break;
error = F_21 ( V_41 , V_43 ,
F_27 ( V_2 , V_44 ) ,
& V_69 ) ;
if ( error )
return error ;
if ( ! V_69 )
continue;
free = V_69 -> V_7 ;
V_163 = 0 ;
}
V_65 = F_30 ( V_2 , free ) ;
F_22 ( & V_75 , free ) ;
if ( F_40 ( V_65 [ V_163 ] ) != V_82 &&
F_40 ( V_65 [ V_163 ] ) >= V_109 )
V_197 = V_75 . V_55 + V_163 ;
else {
if ( ++ V_163 == V_75 . V_56 ) {
F_62 ( V_41 , V_69 ) ;
V_69 = NULL ;
if ( V_196 && V_196 -> V_4 )
V_196 -> V_4 = NULL ;
}
}
}
if ( F_64 ( V_197 == - 1 ) ) {
if ( ( args -> V_99 & V_100 ) || args -> V_166 == 0 )
return F_47 ( V_97 ) ;
if ( F_64 ( ( error = F_36 ( args ,
V_203 ,
& V_197 ) ) ||
( error = F_106 ( args , V_197 , & V_169 ) ) ) )
return error ;
if ( V_69 )
F_62 ( V_41 , V_69 ) ;
if ( V_196 && V_196 -> V_4 )
V_196 -> V_4 = NULL ;
V_44 = F_61 ( V_2 , V_197 ) ;
error = F_21 ( V_41 , V_43 ,
F_27 ( V_2 , V_44 ) ,
& V_69 ) ;
if ( error )
return error ;
if ( ! V_69 ) {
error = F_36 ( args , V_77 ,
& V_44 ) ;
if ( error )
return error ;
if ( F_64 ( F_61 ( V_2 , V_197 ) != V_44 ) ) {
F_76 ( V_2 ,
L_3
L_4 ,
V_31 , ( unsigned long long ) V_43 -> V_62 ,
( long long ) F_61 ( V_2 , V_197 ) ,
( long long ) V_197 , ( long long ) V_44 ,
( unsigned long long ) V_199 , V_200 ) ;
if ( V_196 ) {
F_76 ( V_2 ,
L_5 ,
V_196 ,
( unsigned long long ) V_196 -> V_15 ,
V_196 -> V_86 ,
V_196 -> V_10 ) ;
} else {
F_76 ( V_2 , L_6 ) ;
}
F_65 ( L_7 ,
V_32 , V_2 ) ;
return F_47 ( V_33 ) ;
}
error = F_25 ( V_41 , V_43 , V_44 , & V_69 ) ;
if ( error )
return error ;
free = V_69 -> V_7 ;
V_65 = F_30 ( V_2 , free ) ;
F_22 ( & V_75 , free ) ;
V_75 . V_55 = ( V_44 - F_37 ( V_2 ) ) *
F_55 ( V_2 ) ;
} else {
free = V_69 -> V_7 ;
V_65 = F_30 ( V_2 , free ) ;
F_22 ( & V_75 , free ) ;
}
V_163 = F_63 ( V_2 , V_197 ) ;
if ( V_163 >= V_75 . V_56 ) {
ASSERT ( V_163 < F_55 ( V_2 ) ) ;
V_75 . V_56 = V_163 + 1 ;
V_65 [ V_163 ] = F_41 ( V_82 ) ;
}
if ( V_65 [ V_163 ] == F_41 ( V_82 ) ) {
V_75 . V_57 ++ ;
F_24 ( V_69 -> V_7 , & V_75 ) ;
F_32 ( V_41 , V_69 ) ;
}
V_21 = V_169 -> V_7 ;
V_173 = F_81 ( V_21 ) ;
V_65 [ V_163 ] = V_173 [ 0 ] . V_109 ;
V_165 = 1 ;
}
else {
if ( args -> V_99 & V_100 )
return 0 ;
error = F_67 ( V_41 , V_43 , F_27 ( V_2 , V_197 ) ,
- 1 , & V_169 ) ;
if ( error )
return error ;
V_21 = V_169 -> V_7 ;
V_173 = F_81 ( V_21 ) ;
V_165 = 0 ;
}
ASSERT ( F_40 ( V_173 [ 0 ] . V_109 ) >= V_109 ) ;
V_198 = ( T_19 * )
( ( char * ) V_21 + F_40 ( V_173 [ 0 ] . V_204 ) ) ;
V_171 = V_170 = 0 ;
F_107 ( V_41 , V_169 , V_198 ,
( V_205 ) ( ( char * ) V_198 - ( char * ) V_21 ) , V_109 ,
& V_170 , & V_171 ) ;
V_119 = ( T_16 * ) V_198 ;
V_119 -> V_127 = F_15 ( args -> V_127 ) ;
V_119 -> V_114 = args -> V_114 ;
memcpy ( V_119 -> V_126 , args -> V_126 , V_119 -> V_114 ) ;
V_201 = F_108 ( V_119 ) ;
* V_201 = F_41 ( ( char * ) V_119 - ( char * ) V_21 ) ;
F_109 ( V_41 , V_169 , V_119 ) ;
if ( V_171 )
F_83 ( V_2 , V_21 , & V_170 ) ;
if ( V_170 )
F_84 ( V_41 , V_169 ) ;
V_65 = F_30 ( V_2 , free ) ;
if ( F_40 ( V_65 [ V_163 ] ) != F_40 ( V_173 [ 0 ] . V_109 ) ) {
V_65 [ V_163 ] = V_173 [ 0 ] . V_109 ;
V_165 = 1 ;
}
if ( V_165 )
F_29 ( V_41 , V_69 , V_163 , V_163 ) ;
args -> V_15 = ( T_1 ) V_197 ;
args -> V_86 = F_40 ( * V_201 ) ;
return 0 ;
}
int
F_110 (
T_6 * args )
{
int error ;
int V_71 ;
int V_168 ;
T_15 * V_104 ;
F_111 ( args ) ;
V_104 = F_99 () ;
V_104 -> args = args ;
V_104 -> V_2 = args -> V_43 -> V_59 ;
V_104 -> V_183 = V_104 -> V_2 -> V_81 ;
V_104 -> V_193 = V_104 -> V_2 -> V_194 ;
error = F_100 ( V_104 , & V_168 ) ;
if ( error )
V_168 = error ;
else if ( V_168 == V_118 && args -> V_122 == V_206 ) {
T_16 * V_119 ;
V_119 = ( T_16 * )
( ( char * ) V_104 -> V_113 . V_4 -> V_7 +
V_104 -> V_113 . V_86 ) ;
V_168 = F_112 ( args , V_119 -> V_126 , V_119 -> V_114 ) ;
}
for ( V_71 = 0 ; V_71 < V_104 -> V_181 . V_182 ; V_71 ++ ) {
F_62 ( args -> V_76 , V_104 -> V_181 . V_178 [ V_71 ] . V_4 ) ;
V_104 -> V_181 . V_178 [ V_71 ] . V_4 = NULL ;
}
if ( V_104 -> V_112 && V_104 -> V_113 . V_4 ) {
F_62 ( args -> V_76 , V_104 -> V_113 . V_4 ) ;
V_104 -> V_113 . V_4 = NULL ;
}
F_104 ( V_104 ) ;
return V_168 ;
}
int
F_113 (
T_6 * args )
{
T_17 * V_178 ;
int error ;
int V_168 ;
T_15 * V_104 ;
F_114 ( args ) ;
V_104 = F_99 () ;
V_104 -> args = args ;
V_104 -> V_2 = args -> V_43 -> V_59 ;
V_104 -> V_183 = V_104 -> V_2 -> V_81 ;
V_104 -> V_193 = V_104 -> V_2 -> V_194 ;
error = F_100 ( V_104 , & V_168 ) ;
if ( error )
V_168 = error ;
if ( V_168 != V_132 ) {
F_104 ( V_104 ) ;
return V_168 ;
}
V_178 = & V_104 -> V_181 . V_178 [ V_104 -> V_181 . V_182 - 1 ] ;
ASSERT ( V_178 -> V_10 == V_17 ) ;
ASSERT ( V_104 -> V_112 ) ;
error = F_79 ( args , V_178 -> V_4 , V_178 -> V_86 ,
& V_104 -> V_113 , & V_168 ) ;
if ( error )
return error ;
F_102 ( V_104 , & V_104 -> V_181 ) ;
if ( V_168 && V_104 -> V_181 . V_182 > 1 )
error = F_115 ( V_104 ) ;
if ( ! error )
error = F_116 ( V_104 ) ;
F_104 ( V_104 ) ;
return error ;
}
int
F_117 (
T_6 * args )
{
T_17 * V_178 ;
T_18 * V_21 ;
T_16 * V_119 ;
int error ;
int V_71 ;
T_21 V_207 ;
T_8 * V_6 ;
T_13 * V_89 ;
int V_168 ;
T_15 * V_104 ;
F_118 ( args ) ;
V_104 = F_99 () ;
V_104 -> args = args ;
V_104 -> V_2 = args -> V_43 -> V_59 ;
V_104 -> V_183 = V_104 -> V_2 -> V_81 ;
V_104 -> V_193 = V_104 -> V_2 -> V_194 ;
V_207 = args -> V_127 ;
error = F_100 ( V_104 , & V_168 ) ;
if ( error ) {
V_168 = error ;
}
if ( V_168 == V_132 ) {
struct V_93 * V_94 ;
V_178 = & V_104 -> V_181 . V_178 [ V_104 -> V_181 . V_182 - 1 ] ;
ASSERT ( V_178 -> V_10 == V_17 ) ;
V_6 = V_178 -> V_4 -> V_7 ;
V_94 = F_46 ( V_6 ) ;
V_89 = & V_94 [ V_178 -> V_86 ] ;
ASSERT ( V_104 -> V_112 ) ;
V_21 = V_104 -> V_113 . V_4 -> V_7 ;
ASSERT ( V_21 -> V_10 == F_7 ( V_128 ) ||
V_21 -> V_10 == F_7 ( V_208 ) ) ;
V_119 = ( T_16 * )
( ( char * ) V_21 +
F_69 ( V_104 -> V_2 , F_23 ( V_89 -> V_101 ) ) ) ;
ASSERT ( V_207 != F_3 ( V_119 -> V_127 ) ) ;
V_119 -> V_127 = F_15 ( V_207 ) ;
F_109 ( args -> V_76 , V_104 -> V_113 . V_4 , V_119 ) ;
V_168 = 0 ;
}
else if ( V_104 -> V_112 ) {
F_62 ( args -> V_76 , V_104 -> V_113 . V_4 ) ;
V_104 -> V_113 . V_4 = NULL ;
}
for ( V_71 = 0 ; V_71 < V_104 -> V_181 . V_182 ; V_71 ++ ) {
F_62 ( args -> V_76 , V_104 -> V_181 . V_178 [ V_71 ] . V_4 ) ;
V_104 -> V_181 . V_178 [ V_71 ] . V_4 = NULL ;
}
F_104 ( V_104 ) ;
return V_168 ;
}
int
F_119 (
T_6 * args ,
T_20 V_202 ,
int * V_209 )
{
struct V_3 * V_4 ;
T_7 * V_43 ;
int error ;
T_4 * free ;
T_10 * V_2 ;
T_12 * V_41 ;
struct V_51 V_75 ;
V_43 = args -> V_43 ;
V_2 = V_43 -> V_59 ;
V_41 = args -> V_76 ;
error = F_21 ( V_41 , V_43 , V_202 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_4 )
return 0 ;
free = V_4 -> V_7 ;
F_22 ( & V_75 , free ) ;
if ( V_75 . V_57 > 0 ) {
F_62 ( V_41 , V_4 ) ;
* V_209 = 0 ;
return 0 ;
}
if ( ( error =
F_78 ( args , F_90 ( V_2 , ( T_1 ) V_202 ) ,
V_4 ) ) ) {
ASSERT ( error != V_97 ) ;
F_62 ( V_41 , V_4 ) ;
return error ;
}
* V_209 = 1 ;
return 0 ;
}
