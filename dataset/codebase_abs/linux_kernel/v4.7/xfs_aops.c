void
F_1 (
struct V_1 * V_1 ,
int * V_2 ,
int * V_3 )
{
struct V_4 * V_5 , * V_6 ;
* V_2 = * V_3 = 0 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) )
( * V_3 ) = 1 ;
else if ( F_4 ( V_5 ) )
( * V_2 ) = 1 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
}
struct V_8 *
F_5 (
struct V_9 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( F_7 ( V_11 ) )
return V_13 -> V_15 -> V_16 ;
else
return V_13 -> V_17 -> V_16 ;
}
static void
F_8 (
struct V_9 * V_9 ,
struct V_18 * V_19 ,
int error )
{
unsigned int V_20 = V_19 -> V_21 + V_19 -> V_22 - 1 ;
struct V_4 * V_6 , * V_5 ;
unsigned int V_23 = 0 ;
ASSERT ( V_19 -> V_21 < V_24 ) ;
ASSERT ( ( V_19 -> V_21 & ( ( 1 << V_9 -> V_25 ) - 1 ) ) == 0 ) ;
ASSERT ( V_20 < V_24 ) ;
ASSERT ( ( V_19 -> V_22 & ( ( 1 << V_9 -> V_25 ) - 1 ) ) == 0 ) ;
V_5 = V_6 = F_2 ( V_19 -> V_26 ) ;
do {
if ( V_23 < V_19 -> V_21 )
goto V_27;
if ( V_23 > V_20 )
break;
V_5 -> V_28 ( V_5 , ! error ) ;
V_27:
V_23 += V_5 -> V_29 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
}
STATIC void
F_9 (
struct V_30 * V_31 ,
int error )
{
struct V_9 * V_9 = V_31 -> V_32 ;
struct V_33 * V_34 = V_31 -> V_35 ;
struct V_33 * V_33 , * V_36 ;
for ( V_33 = & V_31 -> V_37 ; V_33 ; V_33 = V_36 ) {
struct V_18 * V_19 ;
int V_38 ;
if ( V_33 == V_34 )
V_36 = NULL ;
else
V_36 = V_33 -> V_39 ;
F_10 (bvec, bio, i)
F_8 ( V_9 , V_19 , error ) ;
F_11 ( V_33 ) ;
}
}
static inline bool F_12 ( struct V_30 * V_31 )
{
return V_31 -> V_40 + V_31 -> V_41 >
F_6 ( V_31 -> V_32 ) -> V_42 . V_43 ;
}
STATIC int
F_13 (
struct V_30 * V_31 )
{
struct V_12 * V_13 = F_6 ( V_31 -> V_32 ) -> V_14 ;
struct V_44 * V_45 ;
int error ;
error = F_14 ( V_13 , & F_15 ( V_13 ) -> V_46 , 0 , 0 , 0 , & V_45 ) ;
if ( error )
return error ;
V_31 -> V_47 = V_45 ;
F_16 ( V_31 -> V_32 -> V_48 , V_49 ) ;
F_17 ( & V_45 -> V_50 , V_51 ) ;
return 0 ;
}
STATIC int
F_18 (
struct V_10 * V_11 ,
struct V_44 * V_45 ,
T_1 V_52 ,
T_2 V_53 )
{
T_3 V_54 ;
F_19 ( V_11 , V_55 ) ;
V_54 = F_20 ( V_11 , V_52 + V_53 ) ;
if ( ! V_54 ) {
F_21 ( V_11 , V_55 ) ;
F_22 ( V_45 ) ;
return 0 ;
}
F_23 ( V_11 , V_52 , V_53 ) ;
V_11 -> V_42 . V_43 = V_54 ;
F_24 ( V_45 , V_11 , V_55 ) ;
F_25 ( V_45 , V_11 , V_56 ) ;
return F_26 ( V_45 ) ;
}
STATIC int
F_27 (
struct V_30 * V_31 ,
int error )
{
struct V_10 * V_11 = F_6 ( V_31 -> V_32 ) ;
struct V_44 * V_45 = V_31 -> V_47 ;
F_28 ( & V_45 -> V_50 , V_51 ) ;
F_29 ( F_30 ( V_11 ) -> V_48 , V_49 ) ;
if ( error ) {
F_22 ( V_45 ) ;
return error ;
}
return F_18 ( V_11 , V_45 , V_31 -> V_40 , V_31 -> V_41 ) ;
}
STATIC void
F_31 (
struct V_57 * V_58 )
{
struct V_30 * V_31 =
F_32 ( V_58 , struct V_30 , V_59 ) ;
struct V_10 * V_11 = F_6 ( V_31 -> V_32 ) ;
int error = V_31 -> V_35 -> V_60 ;
if ( F_33 ( V_11 -> V_14 ) )
error = - V_61 ;
if ( V_31 -> V_62 == V_63 ) {
if ( error )
goto V_64;
error = F_34 ( V_11 , V_31 -> V_40 ,
V_31 -> V_41 ) ;
} else if ( V_31 -> V_47 ) {
error = F_27 ( V_31 , error ) ;
} else {
ASSERT ( ! F_12 ( V_31 ) ) ;
}
V_64:
F_9 ( V_31 , error ) ;
}
STATIC void
F_35 (
struct V_33 * V_33 )
{
struct V_30 * V_31 = V_33 -> V_39 ;
struct V_12 * V_13 = F_6 ( V_31 -> V_32 ) -> V_14 ;
if ( V_31 -> V_62 == V_63 )
F_36 ( V_13 -> V_65 , & V_31 -> V_59 ) ;
else if ( V_31 -> V_47 )
F_36 ( V_13 -> V_66 , & V_31 -> V_59 ) ;
else
F_9 ( V_31 , V_33 -> V_60 ) ;
}
STATIC int
F_37 (
struct V_9 * V_9 ,
T_4 V_52 ,
struct V_67 * V_68 ,
int type )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_5 V_69 = 1 << V_9 -> V_25 ;
T_6 V_70 , V_71 ;
int error = 0 ;
int V_72 = V_73 ;
int V_74 = 1 ;
if ( F_33 ( V_13 ) )
return - V_61 ;
if ( type == V_63 )
V_72 |= V_75 ;
F_19 ( V_11 , V_76 ) ;
ASSERT ( V_11 -> V_42 . V_77 != V_78 ||
( V_11 -> V_79 . V_80 & V_81 ) ) ;
ASSERT ( V_52 <= V_13 -> V_82 -> V_83 ) ;
if ( V_52 + V_69 > V_13 -> V_82 -> V_83 )
V_69 = V_13 -> V_82 -> V_83 - V_52 ;
V_71 = F_38 ( V_13 , ( V_84 ) V_52 + V_69 ) ;
V_70 = F_39 ( V_13 , V_52 ) ;
error = F_40 ( V_11 , V_70 , V_71 - V_70 ,
V_68 , & V_74 , V_72 ) ;
F_21 ( V_11 , V_76 ) ;
if ( error )
return error ;
if ( type == V_85 &&
( ! V_74 || F_41 ( V_68 -> V_86 ) ) ) {
error = F_42 ( V_11 , V_52 , V_68 ) ;
if ( ! error )
F_43 ( V_11 , V_52 , V_69 , type , V_68 ) ;
return error ;
}
#ifdef F_44
if ( type == V_63 ) {
ASSERT ( V_74 ) ;
ASSERT ( V_68 -> V_86 != V_87 ) ;
ASSERT ( V_68 -> V_86 != V_88 ) ;
}
#endif
if ( V_74 )
F_45 ( V_11 , V_52 , V_69 , type , V_68 ) ;
return 0 ;
}
STATIC bool
F_46 (
struct V_9 * V_9 ,
struct V_67 * V_68 ,
T_1 V_52 )
{
V_52 >>= V_9 -> V_25 ;
return V_52 >= V_68 -> V_89 &&
V_52 < V_68 -> V_89 + V_68 -> V_90 ;
}
STATIC void
F_47 (
struct V_4 * V_5 )
{
ASSERT ( F_48 ( V_5 ) ) ;
ASSERT ( F_49 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_50 ( V_5 ) ;
F_51 ( V_5 ) ;
F_52 ( V_5 ) ;
}
STATIC void
F_53 (
struct V_1 * V_1 ,
int V_91 )
{
ASSERT ( F_54 ( V_1 ) ) ;
ASSERT ( ! F_55 ( V_1 ) ) ;
if ( V_91 ) {
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
} else
F_58 ( V_1 ) ;
F_59 ( V_1 ) ;
}
static inline int F_60 ( struct V_33 * V_33 , struct V_4 * V_5 )
{
return F_61 ( V_33 , V_5 -> V_92 , V_5 -> V_29 , F_62 ( V_5 ) ) ;
}
STATIC int
F_63 (
struct V_93 * V_94 ,
struct V_30 * V_31 ,
int V_95 )
{
if ( ! V_95 &&
V_31 -> V_62 != V_63 &&
F_12 ( V_31 ) &&
! V_31 -> V_47 )
V_95 = F_13 ( V_31 ) ;
V_31 -> V_35 -> V_39 = V_31 ;
V_31 -> V_35 -> V_96 = F_35 ;
if ( V_95 ) {
V_31 -> V_35 -> V_60 = V_95 ;
F_64 ( V_31 -> V_35 ) ;
return V_95 ;
}
F_65 ( V_94 -> V_97 == V_98 ? V_99 : V_100 ,
V_31 -> V_35 ) ;
return 0 ;
}
static void
F_66 (
struct V_33 * V_33 ,
struct V_4 * V_5 )
{
V_33 -> V_101 . V_102 = V_5 -> V_103 * ( V_5 -> V_29 >> 9 ) ;
V_33 -> V_104 = V_5 -> V_105 ;
}
static struct V_30 *
F_67 (
struct V_9 * V_9 ,
unsigned int type ,
T_1 V_52 ,
struct V_4 * V_5 )
{
struct V_30 * V_31 ;
struct V_33 * V_33 ;
V_33 = F_68 ( V_106 , V_107 , V_108 ) ;
F_66 ( V_33 , V_5 ) ;
V_31 = F_32 ( V_33 , struct V_30 , V_37 ) ;
F_69 ( & V_31 -> V_109 ) ;
V_31 -> V_62 = type ;
V_31 -> V_32 = V_9 ;
V_31 -> V_41 = 0 ;
V_31 -> V_40 = V_52 ;
F_70 ( & V_31 -> V_59 , F_31 ) ;
V_31 -> V_47 = NULL ;
V_31 -> V_35 = V_33 ;
return V_31 ;
}
static void
F_71 (
struct V_30 * V_31 ,
struct V_93 * V_94 ,
struct V_4 * V_5 )
{
struct V_33 * V_110 ;
V_110 = F_72 ( V_106 , V_107 ) ;
F_66 ( V_110 , V_5 ) ;
F_73 ( V_31 -> V_35 , V_110 ) ;
F_74 ( V_31 -> V_35 ) ;
F_65 ( V_94 -> V_97 == V_98 ? V_99 : V_100 ,
V_31 -> V_35 ) ;
V_31 -> V_35 = V_110 ;
}
STATIC void
F_75 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_1 V_52 ,
struct V_111 * V_112 ,
struct V_93 * V_94 ,
struct V_113 * V_114 )
{
if ( ! V_112 -> V_31 || V_112 -> V_62 != V_112 -> V_31 -> V_62 ||
V_5 -> V_103 != V_112 -> V_115 + 1 ||
V_52 != V_112 -> V_31 -> V_40 + V_112 -> V_31 -> V_41 ) {
if ( V_112 -> V_31 )
F_76 ( & V_112 -> V_31 -> V_109 , V_114 ) ;
V_112 -> V_31 = F_67 ( V_9 , V_112 -> V_62 , V_52 , V_5 ) ;
}
while ( F_60 ( V_112 -> V_31 -> V_35 , V_5 ) != V_5 -> V_29 )
F_71 ( V_112 -> V_31 , V_94 , V_5 ) ;
V_112 -> V_31 -> V_41 += V_5 -> V_29 ;
V_112 -> V_115 = V_5 -> V_103 ;
F_47 ( V_5 ) ;
}
STATIC void
F_77 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_67 * V_68 ,
T_1 V_52 )
{
T_7 V_116 ;
struct V_12 * V_117 = F_6 ( V_9 ) -> V_14 ;
T_1 V_118 = F_78 ( V_117 , V_68 -> V_89 ) ;
T_8 V_119 = F_79 ( F_6 ( V_9 ) , V_68 -> V_86 ) ;
ASSERT ( V_68 -> V_86 != V_87 ) ;
ASSERT ( V_68 -> V_86 != V_88 ) ;
V_116 = ( V_119 >> ( V_9 -> V_25 - V_120 ) ) +
( ( V_52 - V_118 ) >> V_9 -> V_25 ) ;
ASSERT ( V_116 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_103 = V_116 ;
F_80 ( V_5 ) ;
}
STATIC void
F_81 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_67 * V_68 ,
T_1 V_52 )
{
ASSERT ( V_68 -> V_86 != V_87 ) ;
ASSERT ( V_68 -> V_86 != V_88 ) ;
F_77 ( V_9 , V_5 , V_68 , V_52 ) ;
F_80 ( V_5 ) ;
F_82 ( V_5 ) ;
F_83 ( V_5 ) ;
}
STATIC bool
F_84 (
struct V_1 * V_1 ,
unsigned int type ,
bool V_121 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
if ( F_55 ( V_1 ) )
return false ;
if ( ! V_1 -> V_122 )
return false ;
if ( ! F_85 ( V_1 ) )
return false ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) ) {
if ( type == V_63 )
return true ;
} else if ( F_4 ( V_5 ) ) {
if ( type == V_85 )
return true ;
} else if ( F_86 ( V_5 ) && F_48 ( V_5 ) ) {
if ( type == V_123 )
return true ;
}
if ( ! V_121 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC void
F_87 (
struct V_1 * V_1 ,
unsigned int V_52 ,
unsigned int V_124 )
{
F_88 ( V_1 -> V_122 -> V_125 , V_1 , V_52 ,
V_124 ) ;
F_89 ( V_1 , V_52 , V_124 ) ;
}
STATIC void
F_90 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_122 -> V_125 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_4 V_52 = F_91 ( V_1 ) ;
if ( ! F_84 ( V_1 , V_85 , true ) )
goto V_126;
if ( F_33 ( V_11 -> V_14 ) )
goto V_126;
F_92 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_127 , V_52 ) ;
F_19 ( V_11 , V_55 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_6 V_128 ;
if ( ! F_4 ( V_5 ) )
goto V_129;
V_128 = F_39 ( V_11 -> V_14 , V_52 ) ;
error = F_93 ( V_11 , V_128 , 1 ) ;
if ( error ) {
if ( ! F_33 ( V_11 -> V_14 ) ) {
F_92 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_129:
V_52 += 1 << V_9 -> V_25 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_21 ( V_11 , V_55 ) ;
V_126:
F_87 ( V_1 , 0 , V_24 ) ;
return;
}
static int
F_94 (
struct V_111 * V_112 ,
struct V_93 * V_94 ,
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_4 V_52 ,
T_9 V_130 )
{
F_95 ( V_131 ) ;
struct V_30 * V_31 , * V_36 ;
struct V_4 * V_5 , * V_6 ;
T_5 V_132 = 1 << V_9 -> V_25 ;
int error = 0 ;
int V_69 = 0 ;
int V_133 = 1 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_52 = F_91 ( V_1 ) ;
do {
if ( V_52 >= V_130 )
break;
if ( ! F_96 ( V_5 ) )
V_133 = 0 ;
if ( ! F_48 ( V_5 ) && F_96 ( V_5 ) ) {
V_112 -> V_134 = false ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( V_112 -> V_62 != V_63 ) {
V_112 -> V_62 = V_63 ;
V_112 -> V_134 = false ;
}
} else if ( F_4 ( V_5 ) ) {
if ( V_112 -> V_62 != V_85 ) {
V_112 -> V_62 = V_85 ;
V_112 -> V_134 = false ;
}
} else if ( F_96 ( V_5 ) ) {
if ( V_112 -> V_62 != V_123 ) {
V_112 -> V_62 = V_123 ;
V_112 -> V_134 = false ;
}
} else {
if ( F_97 ( V_1 ) )
ASSERT ( F_48 ( V_5 ) ) ;
V_112 -> V_134 = false ;
continue;
}
if ( V_112 -> V_134 )
V_112 -> V_134 = F_46 ( V_9 , & V_112 -> V_68 ,
V_52 ) ;
if ( ! V_112 -> V_134 ) {
error = F_37 ( V_9 , V_52 , & V_112 -> V_68 ,
V_112 -> V_62 ) ;
if ( error )
goto V_135;
V_112 -> V_134 = F_46 ( V_9 , & V_112 -> V_68 ,
V_52 ) ;
}
if ( V_112 -> V_134 ) {
F_98 ( V_5 ) ;
if ( V_112 -> V_62 != V_123 )
F_81 ( V_9 , V_5 , & V_112 -> V_68 , V_52 ) ;
F_75 ( V_9 , V_5 , V_52 , V_112 , V_94 , & V_131 ) ;
V_69 ++ ;
}
} while ( V_52 += V_132 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_133 && V_5 == V_6 )
F_99 ( V_1 ) ;
ASSERT ( V_112 -> V_31 || F_100 ( & V_131 ) ) ;
V_135:
if ( V_69 ) {
F_53 ( V_1 , ! error ) ;
F_101 (ioend, next, &submit_list, io_list) {
int V_136 ;
F_102 ( & V_31 -> V_109 ) ;
V_136 = F_63 ( V_94 , V_31 , error ) ;
if ( V_136 && ! error )
error = V_136 ;
}
} else if ( error ) {
F_90 ( V_1 ) ;
F_103 ( V_1 ) ;
F_59 ( V_1 ) ;
} else {
F_53 ( V_1 , 1 ) ;
F_104 ( V_1 ) ;
}
F_105 ( V_1 -> V_122 , error ) ;
return error ;
}
STATIC int
F_106 (
struct V_1 * V_1 ,
struct V_93 * V_94 ,
void * V_137 )
{
struct V_111 * V_112 = V_137 ;
struct V_9 * V_9 = V_1 -> V_122 -> V_125 ;
T_4 V_52 ;
T_9 V_130 ;
T_10 V_138 ;
F_107 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_85 ( V_1 ) ) ;
if ( F_108 ( ( V_139 -> V_140 & ( V_141 | V_142 ) ) ==
V_141 ) )
goto V_143;
if ( F_108 ( V_139 -> V_140 & V_51 ) )
goto V_143;
V_52 = F_109 ( V_9 ) ;
V_138 = V_52 >> V_144 ;
if ( V_1 -> V_145 < V_138 )
V_130 = ( T_1 ) ( V_1 -> V_145 + 1 ) << V_144 ;
else {
unsigned V_146 = V_52 & ( V_24 - 1 ) ;
if ( V_1 -> V_145 > V_138 ||
( V_1 -> V_145 == V_138 && V_146 == 0 ) )
goto V_143;
F_110 ( V_1 , V_146 , V_24 ) ;
V_130 = V_52 ;
}
return F_94 ( V_112 , V_94 , V_9 , V_1 , V_52 , V_130 ) ;
V_143:
F_111 ( V_94 , V_1 ) ;
F_59 ( V_1 ) ;
return 0 ;
}
STATIC int
F_112 (
struct V_1 * V_1 ,
struct V_93 * V_94 )
{
struct V_111 V_112 = {
. V_62 = V_147 ,
} ;
int V_148 ;
V_148 = F_106 ( V_1 , V_94 , & V_112 ) ;
if ( V_112 . V_31 )
V_148 = F_63 ( V_94 , V_112 . V_31 , V_148 ) ;
return V_148 ;
}
STATIC int
F_113 (
struct V_149 * V_122 ,
struct V_93 * V_94 )
{
struct V_111 V_112 = {
. V_62 = V_147 ,
} ;
int V_148 ;
F_114 ( F_6 ( V_122 -> V_125 ) , V_150 ) ;
if ( F_115 ( V_122 ) )
return F_116 ( V_122 ,
F_5 ( V_122 -> V_125 ) , V_94 ) ;
V_148 = F_117 ( V_122 , V_94 , F_106 , & V_112 ) ;
if ( V_112 . V_31 )
V_148 = F_63 ( V_94 , V_112 . V_31 , V_148 ) ;
return V_148 ;
}
STATIC int
F_118 (
struct V_1 * V_1 ,
T_11 V_151 )
{
int V_2 , V_3 ;
F_119 ( V_1 -> V_122 -> V_125 , V_1 , 0 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_108 ( V_2 ) )
return 0 ;
if ( F_108 ( V_3 ) )
return 0 ;
return F_120 ( V_1 ) ;
}
static void
F_121 (
struct V_9 * V_9 ,
struct V_4 * V_152 ,
struct V_67 * V_68 ,
T_1 V_52 )
{
T_12 * V_140 = ( T_12 * ) & V_152 -> V_153 ;
T_1 V_53 = V_152 -> V_29 ;
F_122 ( F_6 ( V_9 ) , V_52 , V_53 ,
F_123 ( V_68 ) ? V_63 : V_123 , V_68 ) ;
if ( F_123 ( V_68 ) ) {
* V_140 |= V_154 ;
F_124 ( V_152 ) ;
} else if ( V_52 + V_53 > F_109 ( V_9 ) || V_52 + V_53 < 0 ) {
* V_140 |= V_155 ;
F_124 ( V_152 ) ;
}
}
static void
F_125 (
struct V_9 * V_9 ,
T_7 V_156 ,
struct V_4 * V_152 ,
struct V_67 * V_68 ,
T_1 V_52 ,
T_5 V_53 )
{
T_1 V_157 ;
V_157 = V_68 -> V_89 + V_68 -> V_90 - V_156 ;
V_157 <<= V_9 -> V_25 ;
ASSERT ( V_157 > 0 ) ;
if ( V_157 > V_53 )
V_157 = V_53 ;
if ( V_52 < F_109 ( V_9 ) &&
V_52 + V_157 >= F_109 ( V_9 ) ) {
V_157 = F_126 ( F_109 ( V_9 ) - V_52 ,
1 << V_9 -> V_25 ) ;
}
if ( V_157 > V_158 )
V_157 = V_158 ;
V_152 -> V_29 = V_157 ;
}
STATIC int
F_127 (
struct V_9 * V_9 ,
T_7 V_156 ,
struct V_4 * V_152 ,
int V_159 ,
bool V_160 ,
bool V_161 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_70 , V_71 ;
int error = 0 ;
int V_162 = 0 ;
struct V_67 V_68 ;
int V_74 = 1 ;
T_1 V_52 ;
T_5 V_53 ;
int V_110 = 0 ;
if ( F_33 ( V_13 ) )
return - V_61 ;
V_52 = ( T_1 ) V_156 << V_9 -> V_25 ;
ASSERT ( V_152 -> V_29 >= ( 1 << V_9 -> V_25 ) ) ;
V_53 = V_152 -> V_29 ;
if ( ! V_159 && V_160 && V_52 >= F_109 ( V_9 ) )
return 0 ;
if ( V_159 && ! V_160 ) {
V_162 = V_55 ;
F_19 ( V_11 , V_162 ) ;
} else {
V_162 = F_128 ( V_11 ) ;
}
ASSERT ( V_52 <= V_13 -> V_82 -> V_83 ) ;
if ( V_52 + V_53 > V_13 -> V_82 -> V_83 )
V_53 = V_13 -> V_82 -> V_83 - V_52 ;
V_71 = F_38 ( V_13 , ( V_84 ) V_52 + V_53 ) ;
V_70 = F_39 ( V_13 , V_52 ) ;
error = F_40 ( V_11 , V_70 , V_71 - V_70 ,
& V_68 , & V_74 , V_73 ) ;
if ( error )
goto V_163;
if ( V_159 &&
( ! V_74 ||
( V_68 . V_86 == V_87 ||
V_68 . V_86 == V_88 ) ||
( F_129 ( V_9 ) && F_123 ( & V_68 ) ) ) ) {
if ( V_160 || F_130 ( V_11 ) ) {
if ( V_162 == V_55 )
F_131 ( V_11 , V_162 ) ;
error = F_132 ( V_11 , V_52 , V_53 ,
& V_68 , V_74 ) ;
if ( error )
return error ;
V_110 = 1 ;
} else {
if ( V_74 && V_68 . V_86 == V_87 )
V_110 = 1 ;
error = F_133 ( V_11 , V_52 , V_53 , & V_68 ) ;
if ( error )
goto V_163;
F_21 ( V_11 , V_162 ) ;
}
F_134 ( V_11 , V_52 , V_53 ,
F_123 ( & V_68 ) ? V_63
: V_85 , & V_68 ) ;
} else if ( V_74 ) {
F_135 ( V_11 , V_52 , V_53 ,
F_123 ( & V_68 ) ? V_63
: V_123 , & V_68 ) ;
F_21 ( V_11 , V_162 ) ;
} else {
F_136 ( V_11 , V_52 , V_53 ) ;
goto V_163;
}
if ( F_129 ( V_9 ) && V_159 ) {
ASSERT ( ! F_123 ( & V_68 ) ) ;
V_110 = 0 ;
}
if ( V_160 || V_53 > ( 1 << V_9 -> V_25 ) )
F_125 ( V_9 , V_156 , V_152 ,
& V_68 , V_52 , V_53 ) ;
if ( V_68 . V_86 != V_87 &&
V_68 . V_86 != V_88 &&
( V_159 || ! F_123 ( & V_68 ) ) ) {
F_77 ( V_9 , V_152 , & V_68 , V_52 ) ;
if ( F_123 ( & V_68 ) )
F_137 ( V_152 ) ;
if ( V_159 && V_160 ) {
if ( V_161 )
ASSERT ( ! F_123 ( & V_68 ) ) ;
else
F_121 ( V_9 , V_152 , & V_68 , V_52 ) ;
}
}
V_152 -> V_105 = F_5 ( V_9 ) ;
if ( V_159 &&
( ( ! F_48 ( V_152 ) && ! F_96 ( V_152 ) ) ||
( V_52 >= F_109 ( V_9 ) ) ||
( V_110 || F_123 ( & V_68 ) ) ) )
F_138 ( V_152 ) ;
if ( V_68 . V_86 == V_88 ) {
F_139 ( V_160 ) ;
if ( V_159 ) {
F_51 ( V_152 ) ;
F_80 ( V_152 ) ;
F_140 ( V_152 ) ;
}
}
return 0 ;
V_163:
F_21 ( V_11 , V_162 ) ;
return error ;
}
int
F_141 (
struct V_9 * V_9 ,
T_7 V_156 ,
struct V_4 * V_152 ,
int V_159 )
{
return F_127 ( V_9 , V_156 , V_152 , V_159 , false , false ) ;
}
int
F_142 (
struct V_9 * V_9 ,
T_7 V_156 ,
struct V_4 * V_152 ,
int V_159 )
{
return F_127 ( V_9 , V_156 , V_152 , V_159 , true , false ) ;
}
int
F_143 (
struct V_9 * V_9 ,
T_7 V_156 ,
struct V_4 * V_152 ,
int V_159 )
{
return F_127 ( V_9 , V_156 , V_152 , V_159 , true , true ) ;
}
STATIC int
F_144 (
struct V_164 * V_165 ,
T_4 V_52 ,
T_5 V_53 ,
void * V_166 )
{
struct V_9 * V_9 = F_145 ( V_165 -> V_167 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_12 V_140 = ( T_12 ) V_166 ;
int error = 0 ;
F_146 ( V_11 , V_52 , V_53 ) ;
if ( F_33 ( V_13 ) )
return - V_61 ;
if ( V_53 <= 0 )
return V_53 ;
if ( V_140 == 0 ) {
ASSERT ( V_52 + V_53 <= F_109 ( V_9 ) ) ;
return 0 ;
}
F_147 ( & V_11 -> V_168 ) ;
if ( V_52 + V_53 > F_109 ( V_9 ) )
F_148 ( V_9 , V_52 + V_53 ) ;
F_149 ( & V_11 -> V_168 ) ;
if ( V_140 & V_154 ) {
F_150 ( V_11 , V_52 , V_53 ) ;
error = F_34 ( V_11 , V_52 , V_53 ) ;
} else if ( V_140 & V_155 ) {
struct V_44 * V_45 ;
F_151 ( V_11 , V_52 , V_53 ) ;
error = F_14 ( V_13 , & F_15 ( V_13 ) -> V_46 , 0 , 0 , 0 ,
& V_45 ) ;
if ( ! error )
error = F_18 ( V_11 , V_45 , V_52 , V_53 ) ;
}
return error ;
}
STATIC T_5
F_152 (
struct V_164 * V_165 ,
struct V_169 * V_170 )
{
struct V_9 * V_9 = V_165 -> V_167 -> V_171 -> V_125 ;
T_13 * V_172 = NULL ;
int V_140 = 0 ;
struct V_8 * V_173 ;
if ( F_153 ( V_170 ) == V_100 ) {
V_172 = F_144 ;
V_140 = V_174 ;
}
if ( F_129 ( V_9 ) ) {
return F_154 ( V_165 , V_9 , V_170 ,
F_142 , V_172 , 0 ) ;
}
V_173 = F_5 ( V_9 ) ;
return F_155 ( V_165 , V_9 , V_173 , V_170 ,
F_142 , V_172 , NULL , V_140 ) ;
}
STATIC void
F_156 (
struct V_9 * V_9 ,
T_4 V_175 ,
T_4 V_20 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_6 V_128 ;
T_6 V_71 ;
int error ;
V_128 = F_38 ( V_11 -> V_14 , V_175 ) ;
V_71 = F_38 ( V_11 -> V_14 , V_20 ) ;
if ( V_71 <= V_128 )
return;
F_19 ( V_11 , V_55 ) ;
error = F_93 ( V_11 , V_128 ,
V_71 - V_128 ) ;
if ( error ) {
if ( ! F_33 ( V_11 -> V_14 ) ) {
F_92 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_127 ) ;
}
}
F_21 ( V_11 , V_55 ) ;
}
STATIC void
F_157 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_4 V_176 ,
unsigned V_132 )
{
T_4 V_177 ;
T_4 V_178 ;
T_4 V_179 ;
T_4 V_180 = V_176 & ( V_24 - 1 ) ;
T_4 V_181 = V_180 + V_132 ;
struct V_4 * V_5 , * V_6 ;
struct V_12 * V_13 = F_6 ( V_9 ) -> V_14 ;
V_177 = ( V_176 >> V_144 ) << V_144 ;
ASSERT ( V_177 + V_180 == V_176 ) ;
V_6 = F_2 ( V_1 ) ;
V_178 = 0 ;
for ( V_5 = V_6 ; V_5 != V_6 || ! V_178 ;
V_5 = V_5 -> V_7 , V_178 = V_179 ,
V_177 += V_5 -> V_29 ) {
V_179 = V_178 + V_5 -> V_29 ;
if ( V_179 <= V_180 )
continue;
if ( V_178 >= V_181 )
break;
if ( ! F_4 ( V_5 ) && ! F_3 ( V_5 ) )
continue;
if ( ! F_158 ( V_13 ) && ! F_159 ( V_5 ) &&
V_177 < F_109 ( V_9 ) )
continue;
if ( F_4 ( V_5 ) )
F_156 ( V_9 , V_177 ,
V_177 + V_5 -> V_29 ) ;
F_82 ( V_5 ) ;
F_160 ( V_5 ) ;
F_161 ( V_5 ) ;
F_162 ( V_5 ) ;
F_52 ( V_5 ) ;
F_83 ( V_5 ) ;
}
}
STATIC int
F_163 (
struct V_182 * V_182 ,
struct V_149 * V_122 ,
T_4 V_176 ,
unsigned V_132 ,
unsigned V_140 ,
struct V_1 * * V_183 ,
void * * V_184 )
{
T_10 V_145 = V_176 >> V_144 ;
struct V_1 * V_1 ;
int V_95 ;
struct V_12 * V_13 = F_6 ( V_122 -> V_125 ) -> V_14 ;
ASSERT ( V_132 <= V_24 ) ;
V_1 = F_164 ( V_122 , V_145 , V_140 ) ;
if ( ! V_1 )
return - V_185 ;
V_95 = F_165 ( V_1 , V_176 , V_132 , F_141 ) ;
if ( F_158 ( V_13 ) )
V_95 = - V_61 ;
if ( F_166 ( V_95 ) ) {
struct V_9 * V_9 = V_122 -> V_125 ;
T_2 V_54 = F_109 ( V_9 ) ;
F_157 ( V_9 , V_1 , V_176 , V_132 ) ;
F_59 ( V_1 ) ;
if ( F_158 ( V_13 ) )
V_54 = 0 ;
if ( V_176 + V_132 > V_54 ) {
T_5 V_175 = F_167 ( T_5 , V_176 , V_54 ) ;
F_168 ( V_9 , V_175 , V_176 + V_132 ) ;
}
F_169 ( V_1 ) ;
V_1 = NULL ;
}
* V_183 = V_1 ;
return V_95 ;
}
STATIC int
F_170 (
struct V_182 * V_182 ,
struct V_149 * V_122 ,
T_4 V_176 ,
unsigned V_132 ,
unsigned V_186 ,
struct V_1 * V_1 ,
void * V_184 )
{
int V_148 ;
ASSERT ( V_132 <= V_24 ) ;
V_148 = F_171 ( V_182 , V_122 , V_176 , V_132 , V_186 , V_1 , V_184 ) ;
if ( F_166 ( V_148 < V_132 ) ) {
struct V_9 * V_9 = V_122 -> V_125 ;
T_2 V_54 = F_109 ( V_9 ) ;
T_4 V_181 = V_176 + V_132 ;
if ( V_181 > V_54 ) {
if ( V_176 > V_54 )
V_54 = V_176 ;
F_156 ( V_9 , V_54 , V_181 ) ;
F_168 ( V_9 , V_54 , V_181 ) ;
}
}
return V_148 ;
}
STATIC T_7
F_172 (
struct V_149 * V_122 ,
T_7 V_187 )
{
struct V_9 * V_9 = (struct V_9 * ) V_122 -> V_125 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_173 ( F_6 ( V_9 ) ) ;
F_19 ( V_11 , V_188 ) ;
F_174 ( V_122 ) ;
F_21 ( V_11 , V_188 ) ;
return F_175 ( V_122 , V_187 , F_141 ) ;
}
STATIC int
F_176 (
struct V_182 * V_189 ,
struct V_1 * V_1 )
{
F_177 ( V_1 -> V_122 -> V_125 , 1 ) ;
return F_178 ( V_1 , F_141 ) ;
}
STATIC int
F_179 (
struct V_182 * V_189 ,
struct V_149 * V_122 ,
struct V_113 * V_190 ,
unsigned V_191 )
{
F_180 ( V_122 -> V_125 , V_191 ) ;
return F_181 ( V_122 , V_190 , V_191 , F_141 ) ;
}
STATIC int
F_182 (
struct V_1 * V_1 )
{
struct V_149 * V_122 = V_1 -> V_122 ;
struct V_9 * V_9 = V_122 -> V_125 ;
T_4 V_130 ;
T_4 V_52 ;
int V_192 ;
if ( F_166 ( ! V_122 ) )
return ! F_183 ( V_1 ) ;
V_130 = F_109 ( V_9 ) ;
V_52 = F_91 ( V_1 ) ;
F_147 ( & V_122 -> V_193 ) ;
if ( F_85 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_52 < V_130 )
F_184 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_52 += 1 << V_9 -> V_25 ;
} while ( V_5 != V_6 );
}
F_185 ( V_1 ) ;
V_192 = ! F_183 ( V_1 ) ;
F_149 ( & V_122 -> V_193 ) ;
if ( V_192 ) {
unsigned long V_140 ;
F_186 ( & V_122 -> V_194 , V_140 ) ;
if ( V_1 -> V_122 ) {
F_108 ( ! F_97 ( V_1 ) ) ;
F_187 ( V_1 , V_122 ) ;
F_188 ( & V_122 -> V_195 ,
F_189 ( V_1 ) , V_196 ) ;
}
F_190 ( & V_122 -> V_194 , V_140 ) ;
}
F_191 ( V_1 ) ;
if ( V_192 )
F_192 ( V_122 -> V_125 , V_197 ) ;
return V_192 ;
}
