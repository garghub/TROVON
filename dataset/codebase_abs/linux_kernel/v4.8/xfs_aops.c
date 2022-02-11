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
struct V_4 * V_6 , * V_5 , * V_23 ;
unsigned int V_24 = 0 ;
unsigned int V_25 ;
ASSERT ( V_19 -> V_21 < V_26 ) ;
ASSERT ( ( V_19 -> V_21 & ( ( 1 << V_9 -> V_27 ) - 1 ) ) == 0 ) ;
ASSERT ( V_20 < V_26 ) ;
ASSERT ( ( V_19 -> V_22 & ( ( 1 << V_9 -> V_27 ) - 1 ) ) == 0 ) ;
V_5 = V_6 = F_2 ( V_19 -> V_28 ) ;
V_25 = V_5 -> V_29 ;
do {
V_23 = V_5 -> V_7 ;
if ( V_24 < V_19 -> V_21 )
goto V_30;
if ( V_24 > V_20 )
break;
V_5 -> V_31 ( V_5 , ! error ) ;
V_30:
V_24 += V_25 ;
} while ( ( V_5 = V_23 ) != V_6 );
}
STATIC void
F_9 (
struct V_32 * V_33 ,
int error )
{
struct V_9 * V_9 = V_33 -> V_34 ;
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_35 * V_35 , * V_23 ;
for ( V_35 = & V_33 -> V_38 ; V_35 ; V_35 = V_23 ) {
struct V_18 * V_19 ;
int V_39 ;
if ( V_35 == V_36 )
V_23 = NULL ;
else
V_23 = V_35 -> V_40 ;
F_10 (bvec, bio, i)
F_8 ( V_9 , V_19 , error ) ;
F_11 ( V_35 ) ;
}
}
static inline bool F_12 ( struct V_32 * V_33 )
{
return V_33 -> V_41 + V_33 -> V_42 >
F_6 ( V_33 -> V_34 ) -> V_43 . V_44 ;
}
STATIC int
F_13 (
struct V_32 * V_33 )
{
struct V_12 * V_13 = F_6 ( V_33 -> V_34 ) -> V_14 ;
struct V_45 * V_46 ;
int error ;
error = F_14 ( V_13 , & F_15 ( V_13 ) -> V_47 , 0 , 0 , 0 , & V_46 ) ;
if ( error )
return error ;
V_33 -> V_48 = V_46 ;
F_16 ( V_33 -> V_34 -> V_49 , V_50 ) ;
F_17 ( & V_46 -> V_51 , V_52 ) ;
return 0 ;
}
STATIC int
F_18 (
struct V_10 * V_11 ,
struct V_45 * V_46 ,
T_1 V_53 ,
T_2 V_54 )
{
T_3 V_55 ;
F_19 ( V_11 , V_56 ) ;
V_55 = F_20 ( V_11 , V_53 + V_54 ) ;
if ( ! V_55 ) {
F_21 ( V_11 , V_56 ) ;
F_22 ( V_46 ) ;
return 0 ;
}
F_23 ( V_11 , V_53 , V_54 ) ;
V_11 -> V_43 . V_44 = V_55 ;
F_24 ( V_46 , V_11 , V_56 ) ;
F_25 ( V_46 , V_11 , V_57 ) ;
return F_26 ( V_46 ) ;
}
STATIC int
F_27 (
struct V_32 * V_33 ,
int error )
{
struct V_10 * V_11 = F_6 ( V_33 -> V_34 ) ;
struct V_45 * V_46 = V_33 -> V_48 ;
F_28 ( & V_46 -> V_51 , V_52 ) ;
F_29 ( F_30 ( V_11 ) -> V_49 , V_50 ) ;
if ( error ) {
F_22 ( V_46 ) ;
return error ;
}
return F_18 ( V_11 , V_46 , V_33 -> V_41 , V_33 -> V_42 ) ;
}
STATIC void
F_31 (
struct V_58 * V_59 )
{
struct V_32 * V_33 =
F_32 ( V_59 , struct V_32 , V_60 ) ;
struct V_10 * V_11 = F_6 ( V_33 -> V_34 ) ;
int error = V_33 -> V_37 -> V_61 ;
if ( F_33 ( V_11 -> V_14 ) )
error = - V_62 ;
if ( V_33 -> V_63 == V_64 ) {
if ( error )
goto V_65;
error = F_34 ( V_11 , V_33 -> V_41 ,
V_33 -> V_42 ) ;
} else if ( V_33 -> V_48 ) {
error = F_27 ( V_33 , error ) ;
} else {
ASSERT ( ! F_12 ( V_33 ) ) ;
}
V_65:
F_9 ( V_33 , error ) ;
}
STATIC void
F_35 (
struct V_35 * V_35 )
{
struct V_32 * V_33 = V_35 -> V_40 ;
struct V_12 * V_13 = F_6 ( V_33 -> V_34 ) -> V_14 ;
if ( V_33 -> V_63 == V_64 )
F_36 ( V_13 -> V_66 , & V_33 -> V_60 ) ;
else if ( V_33 -> V_48 )
F_36 ( V_13 -> V_67 , & V_33 -> V_60 ) ;
else
F_9 ( V_33 , V_35 -> V_61 ) ;
}
STATIC int
F_37 (
struct V_9 * V_9 ,
T_4 V_53 ,
struct V_68 * V_69 ,
int type )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_5 V_70 = 1 << V_9 -> V_27 ;
T_6 V_71 , V_72 ;
int error = 0 ;
int V_73 = V_74 ;
int V_75 = 1 ;
if ( F_33 ( V_13 ) )
return - V_62 ;
if ( type == V_64 )
V_73 |= V_76 ;
F_19 ( V_11 , V_77 ) ;
ASSERT ( V_11 -> V_43 . V_78 != V_79 ||
( V_11 -> V_80 . V_81 & V_82 ) ) ;
ASSERT ( V_53 <= V_13 -> V_83 -> V_84 ) ;
if ( V_53 + V_70 > V_13 -> V_83 -> V_84 )
V_70 = V_13 -> V_83 -> V_84 - V_53 ;
V_72 = F_38 ( V_13 , ( V_85 ) V_53 + V_70 ) ;
V_71 = F_39 ( V_13 , V_53 ) ;
error = F_40 ( V_11 , V_71 , V_72 - V_71 ,
V_69 , & V_75 , V_73 ) ;
F_21 ( V_11 , V_77 ) ;
if ( error )
return error ;
if ( type == V_86 &&
( ! V_75 || F_41 ( V_69 -> V_87 ) ) ) {
error = F_42 ( V_11 , V_53 , V_69 ) ;
if ( ! error )
F_43 ( V_11 , V_53 , V_70 , type , V_69 ) ;
return error ;
}
#ifdef F_44
if ( type == V_64 ) {
ASSERT ( V_75 ) ;
ASSERT ( V_69 -> V_87 != V_88 ) ;
ASSERT ( V_69 -> V_87 != V_89 ) ;
}
#endif
if ( V_75 )
F_45 ( V_11 , V_53 , V_70 , type , V_69 ) ;
return 0 ;
}
STATIC bool
F_46 (
struct V_9 * V_9 ,
struct V_68 * V_69 ,
T_1 V_53 )
{
V_53 >>= V_9 -> V_27 ;
return V_53 >= V_69 -> V_90 &&
V_53 < V_69 -> V_90 + V_69 -> V_91 ;
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
int V_92 )
{
ASSERT ( F_54 ( V_1 ) ) ;
ASSERT ( ! F_55 ( V_1 ) ) ;
if ( V_92 ) {
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
} else
F_58 ( V_1 ) ;
F_59 ( V_1 ) ;
}
static inline int F_60 ( struct V_35 * V_35 , struct V_4 * V_5 )
{
return F_61 ( V_35 , V_5 -> V_93 , V_5 -> V_29 , F_62 ( V_5 ) ) ;
}
STATIC int
F_63 (
struct V_94 * V_95 ,
struct V_32 * V_33 ,
int V_96 )
{
if ( ! V_96 &&
V_33 -> V_63 != V_64 &&
F_12 ( V_33 ) &&
! V_33 -> V_48 )
V_96 = F_13 ( V_33 ) ;
V_33 -> V_37 -> V_40 = V_33 ;
V_33 -> V_37 -> V_97 = F_35 ;
F_64 ( V_33 -> V_37 , V_98 ,
( V_95 -> V_99 == V_100 ) ? V_101 : 0 ) ;
if ( V_96 ) {
V_33 -> V_37 -> V_61 = V_96 ;
F_65 ( V_33 -> V_37 ) ;
return V_96 ;
}
F_66 ( V_33 -> V_37 ) ;
return 0 ;
}
static void
F_67 (
struct V_35 * V_35 ,
struct V_4 * V_5 )
{
V_35 -> V_102 . V_103 = V_5 -> V_104 * ( V_5 -> V_29 >> 9 ) ;
V_35 -> V_105 = V_5 -> V_106 ;
}
static struct V_32 *
F_68 (
struct V_9 * V_9 ,
unsigned int type ,
T_1 V_53 ,
struct V_4 * V_5 )
{
struct V_32 * V_33 ;
struct V_35 * V_35 ;
V_35 = F_69 ( V_107 , V_108 , V_109 ) ;
F_67 ( V_35 , V_5 ) ;
V_33 = F_32 ( V_35 , struct V_32 , V_38 ) ;
F_70 ( & V_33 -> V_110 ) ;
V_33 -> V_63 = type ;
V_33 -> V_34 = V_9 ;
V_33 -> V_42 = 0 ;
V_33 -> V_41 = V_53 ;
F_71 ( & V_33 -> V_60 , F_31 ) ;
V_33 -> V_48 = NULL ;
V_33 -> V_37 = V_35 ;
return V_33 ;
}
static void
F_72 (
struct V_32 * V_33 ,
struct V_94 * V_95 ,
struct V_4 * V_5 )
{
struct V_35 * V_111 ;
V_111 = F_73 ( V_107 , V_108 ) ;
F_67 ( V_111 , V_5 ) ;
F_74 ( V_33 -> V_37 , V_111 ) ;
F_75 ( V_33 -> V_37 ) ;
F_64 ( V_33 -> V_37 , V_98 ,
( V_95 -> V_99 == V_100 ) ? V_101 : 0 ) ;
F_66 ( V_33 -> V_37 ) ;
V_33 -> V_37 = V_111 ;
}
STATIC void
F_76 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_1 V_53 ,
struct V_112 * V_113 ,
struct V_94 * V_95 ,
struct V_114 * V_115 )
{
if ( ! V_113 -> V_33 || V_113 -> V_63 != V_113 -> V_33 -> V_63 ||
V_5 -> V_104 != V_113 -> V_116 + 1 ||
V_53 != V_113 -> V_33 -> V_41 + V_113 -> V_33 -> V_42 ) {
if ( V_113 -> V_33 )
F_77 ( & V_113 -> V_33 -> V_110 , V_115 ) ;
V_113 -> V_33 = F_68 ( V_9 , V_113 -> V_63 , V_53 , V_5 ) ;
}
while ( F_60 ( V_113 -> V_33 -> V_37 , V_5 ) != V_5 -> V_29 )
F_72 ( V_113 -> V_33 , V_95 , V_5 ) ;
V_113 -> V_33 -> V_42 += V_5 -> V_29 ;
V_113 -> V_116 = V_5 -> V_104 ;
F_47 ( V_5 ) ;
}
STATIC void
F_78 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_68 * V_69 ,
T_1 V_53 )
{
T_7 V_117 ;
struct V_12 * V_118 = F_6 ( V_9 ) -> V_14 ;
T_1 V_119 = F_79 ( V_118 , V_69 -> V_90 ) ;
T_8 V_120 = F_80 ( F_6 ( V_9 ) , V_69 -> V_87 ) ;
ASSERT ( V_69 -> V_87 != V_88 ) ;
ASSERT ( V_69 -> V_87 != V_89 ) ;
V_117 = ( V_120 >> ( V_9 -> V_27 - V_121 ) ) +
( ( V_53 - V_119 ) >> V_9 -> V_27 ) ;
ASSERT ( V_117 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_104 = V_117 ;
F_81 ( V_5 ) ;
}
STATIC void
F_82 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_68 * V_69 ,
T_1 V_53 )
{
ASSERT ( V_69 -> V_87 != V_88 ) ;
ASSERT ( V_69 -> V_87 != V_89 ) ;
F_78 ( V_9 , V_5 , V_69 , V_53 ) ;
F_81 ( V_5 ) ;
F_83 ( V_5 ) ;
F_84 ( V_5 ) ;
}
STATIC bool
F_85 (
struct V_1 * V_1 ,
unsigned int type ,
bool V_122 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
if ( F_55 ( V_1 ) )
return false ;
if ( ! V_1 -> V_123 )
return false ;
if ( ! F_86 ( V_1 ) )
return false ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) ) {
if ( type == V_64 )
return true ;
} else if ( F_4 ( V_5 ) ) {
if ( type == V_86 )
return true ;
} else if ( F_87 ( V_5 ) && F_48 ( V_5 ) ) {
if ( type == V_124 )
return true ;
}
if ( ! V_122 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC void
F_88 (
struct V_1 * V_1 ,
unsigned int V_53 ,
unsigned int V_125 )
{
F_89 ( V_1 -> V_123 -> V_126 , V_1 , V_53 ,
V_125 ) ;
F_90 ( V_1 , V_53 , V_125 ) ;
}
STATIC void
F_91 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_123 -> V_126 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_4 V_53 = F_92 ( V_1 ) ;
if ( ! F_85 ( V_1 , V_86 , true ) )
goto V_127;
if ( F_33 ( V_11 -> V_14 ) )
goto V_127;
F_93 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_128 , V_53 ) ;
F_19 ( V_11 , V_56 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_6 V_129 ;
if ( ! F_4 ( V_5 ) )
goto V_130;
V_129 = F_39 ( V_11 -> V_14 , V_53 ) ;
error = F_94 ( V_11 , V_129 , 1 ) ;
if ( error ) {
if ( ! F_33 ( V_11 -> V_14 ) ) {
F_93 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_130:
V_53 += 1 << V_9 -> V_27 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_21 ( V_11 , V_56 ) ;
V_127:
F_88 ( V_1 , 0 , V_26 ) ;
return;
}
static int
F_95 (
struct V_112 * V_113 ,
struct V_94 * V_95 ,
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_4 V_53 ,
T_9 V_131 )
{
F_96 ( V_132 ) ;
struct V_32 * V_33 , * V_23 ;
struct V_4 * V_5 , * V_6 ;
T_5 V_133 = 1 << V_9 -> V_27 ;
int error = 0 ;
int V_70 = 0 ;
int V_134 = 1 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_53 = F_92 ( V_1 ) ;
do {
if ( V_53 >= V_131 )
break;
if ( ! F_97 ( V_5 ) )
V_134 = 0 ;
if ( ! F_48 ( V_5 ) && F_97 ( V_5 ) ) {
V_113 -> V_135 = false ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( V_113 -> V_63 != V_64 ) {
V_113 -> V_63 = V_64 ;
V_113 -> V_135 = false ;
}
} else if ( F_4 ( V_5 ) ) {
if ( V_113 -> V_63 != V_86 ) {
V_113 -> V_63 = V_86 ;
V_113 -> V_135 = false ;
}
} else if ( F_97 ( V_5 ) ) {
if ( V_113 -> V_63 != V_124 ) {
V_113 -> V_63 = V_124 ;
V_113 -> V_135 = false ;
}
} else {
if ( F_98 ( V_1 ) )
ASSERT ( F_48 ( V_5 ) ) ;
V_113 -> V_135 = false ;
continue;
}
if ( V_113 -> V_135 )
V_113 -> V_135 = F_46 ( V_9 , & V_113 -> V_69 ,
V_53 ) ;
if ( ! V_113 -> V_135 ) {
error = F_37 ( V_9 , V_53 , & V_113 -> V_69 ,
V_113 -> V_63 ) ;
if ( error )
goto V_136;
V_113 -> V_135 = F_46 ( V_9 , & V_113 -> V_69 ,
V_53 ) ;
}
if ( V_113 -> V_135 ) {
F_99 ( V_5 ) ;
if ( V_113 -> V_63 != V_124 )
F_82 ( V_9 , V_5 , & V_113 -> V_69 , V_53 ) ;
F_76 ( V_9 , V_5 , V_53 , V_113 , V_95 , & V_132 ) ;
V_70 ++ ;
}
} while ( V_53 += V_133 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_134 && V_5 == V_6 )
F_100 ( V_1 ) ;
ASSERT ( V_113 -> V_33 || F_101 ( & V_132 ) ) ;
V_136:
if ( V_70 ) {
F_53 ( V_1 , ! error ) ;
F_102 (ioend, next, &submit_list, io_list) {
int V_137 ;
F_103 ( & V_33 -> V_110 ) ;
V_137 = F_63 ( V_95 , V_33 , error ) ;
if ( V_137 && ! error )
error = V_137 ;
}
} else if ( error ) {
F_91 ( V_1 ) ;
F_104 ( V_1 ) ;
F_59 ( V_1 ) ;
} else {
F_53 ( V_1 , 1 ) ;
F_105 ( V_1 ) ;
}
F_106 ( V_1 -> V_123 , error ) ;
return error ;
}
STATIC int
F_107 (
struct V_1 * V_1 ,
struct V_94 * V_95 ,
void * V_138 )
{
struct V_112 * V_113 = V_138 ;
struct V_9 * V_9 = V_1 -> V_123 -> V_126 ;
T_4 V_53 ;
T_9 V_131 ;
T_10 V_139 ;
F_108 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_86 ( V_1 ) ) ;
if ( F_109 ( ( V_140 -> V_141 & ( V_142 | V_143 ) ) ==
V_142 ) )
goto V_144;
if ( F_109 ( V_140 -> V_141 & V_52 ) )
goto V_144;
V_53 = F_110 ( V_9 ) ;
V_139 = V_53 >> V_145 ;
if ( V_1 -> V_146 < V_139 )
V_131 = ( T_1 ) ( V_1 -> V_146 + 1 ) << V_145 ;
else {
unsigned V_147 = V_53 & ( V_26 - 1 ) ;
if ( V_1 -> V_146 > V_139 ||
( V_1 -> V_146 == V_139 && V_147 == 0 ) )
goto V_144;
F_111 ( V_1 , V_147 , V_26 ) ;
V_131 = V_53 ;
}
return F_95 ( V_113 , V_95 , V_9 , V_1 , V_53 , V_131 ) ;
V_144:
F_112 ( V_95 , V_1 ) ;
F_59 ( V_1 ) ;
return 0 ;
}
STATIC int
F_113 (
struct V_1 * V_1 ,
struct V_94 * V_95 )
{
struct V_112 V_113 = {
. V_63 = V_148 ,
} ;
int V_149 ;
V_149 = F_107 ( V_1 , V_95 , & V_113 ) ;
if ( V_113 . V_33 )
V_149 = F_63 ( V_95 , V_113 . V_33 , V_149 ) ;
return V_149 ;
}
STATIC int
F_114 (
struct V_150 * V_123 ,
struct V_94 * V_95 )
{
struct V_112 V_113 = {
. V_63 = V_148 ,
} ;
int V_149 ;
F_115 ( F_6 ( V_123 -> V_126 ) , V_151 ) ;
if ( F_116 ( V_123 ) )
return F_117 ( V_123 ,
F_5 ( V_123 -> V_126 ) , V_95 ) ;
V_149 = F_118 ( V_123 , V_95 , F_107 , & V_113 ) ;
if ( V_113 . V_33 )
V_149 = F_63 ( V_95 , V_113 . V_33 , V_149 ) ;
return V_149 ;
}
STATIC int
F_119 (
struct V_1 * V_1 ,
T_11 V_152 )
{
int V_2 , V_3 ;
F_120 ( V_1 -> V_123 -> V_126 , V_1 , 0 , 0 ) ;
if ( F_121 ( V_1 ) )
return 0 ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_109 ( V_2 ) )
return 0 ;
if ( F_109 ( V_3 ) )
return 0 ;
return F_122 ( V_1 ) ;
}
static void
F_123 (
struct V_9 * V_9 ,
struct V_4 * V_153 ,
struct V_68 * V_69 ,
T_1 V_53 )
{
T_12 * V_141 = ( T_12 * ) & V_153 -> V_154 ;
T_1 V_54 = V_153 -> V_29 ;
F_124 ( F_6 ( V_9 ) , V_53 , V_54 ,
F_125 ( V_69 ) ? V_64 : V_124 , V_69 ) ;
if ( F_125 ( V_69 ) ) {
* V_141 |= V_155 ;
F_126 ( V_153 ) ;
} else if ( V_53 + V_54 > F_110 ( V_9 ) || V_53 + V_54 < 0 ) {
* V_141 |= V_156 ;
F_126 ( V_153 ) ;
}
}
static void
F_127 (
struct V_9 * V_9 ,
T_7 V_157 ,
struct V_4 * V_153 ,
struct V_68 * V_69 ,
T_1 V_53 ,
T_5 V_54 )
{
T_1 V_158 ;
V_158 = V_69 -> V_90 + V_69 -> V_91 - V_157 ;
V_158 <<= V_9 -> V_27 ;
ASSERT ( V_158 > 0 ) ;
if ( V_158 > V_54 )
V_158 = V_54 ;
if ( V_53 < F_110 ( V_9 ) &&
V_53 + V_158 >= F_110 ( V_9 ) ) {
V_158 = F_128 ( F_110 ( V_9 ) - V_53 ,
1 << V_9 -> V_27 ) ;
}
if ( V_158 > V_159 )
V_158 = V_159 ;
V_153 -> V_29 = V_158 ;
}
STATIC int
F_129 (
struct V_9 * V_9 ,
T_7 V_157 ,
struct V_4 * V_153 ,
int V_160 ,
bool V_161 ,
bool V_162 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_71 , V_72 ;
int error = 0 ;
int V_163 = 0 ;
struct V_68 V_69 ;
int V_75 = 1 ;
T_1 V_53 ;
T_5 V_54 ;
int V_111 = 0 ;
F_130 ( V_160 && ! V_161 ) ;
if ( F_33 ( V_13 ) )
return - V_62 ;
V_53 = ( T_1 ) V_157 << V_9 -> V_27 ;
ASSERT ( V_153 -> V_29 >= ( 1 << V_9 -> V_27 ) ) ;
V_54 = V_153 -> V_29 ;
if ( ! V_160 && V_53 >= F_110 ( V_9 ) )
return 0 ;
V_163 = F_131 ( V_11 ) ;
ASSERT ( V_53 <= V_13 -> V_83 -> V_84 ) ;
if ( V_53 + V_54 > V_13 -> V_83 -> V_84 )
V_54 = V_13 -> V_83 -> V_84 - V_53 ;
V_72 = F_38 ( V_13 , ( V_85 ) V_53 + V_54 ) ;
V_71 = F_39 ( V_13 , V_53 ) ;
error = F_40 ( V_11 , V_71 , V_72 - V_71 ,
& V_69 , & V_75 , V_74 ) ;
if ( error )
goto V_164;
if ( V_160 &&
( ! V_75 ||
( V_69 . V_87 == V_88 ||
V_69 . V_87 == V_89 ) ||
( F_132 ( V_9 ) && F_125 ( & V_69 ) ) ) ) {
if ( V_163 == V_56 )
F_133 ( V_11 , V_163 ) ;
error = F_134 ( V_11 , V_53 , V_54 ,
& V_69 , V_75 ) ;
if ( error )
return error ;
V_111 = 1 ;
F_135 ( V_11 , V_53 , V_54 ,
F_125 ( & V_69 ) ? V_64
: V_86 , & V_69 ) ;
} else if ( V_75 ) {
F_136 ( V_11 , V_53 , V_54 ,
F_125 ( & V_69 ) ? V_64
: V_124 , & V_69 ) ;
F_21 ( V_11 , V_163 ) ;
} else {
F_137 ( V_11 , V_53 , V_54 ) ;
goto V_164;
}
if ( F_132 ( V_9 ) && V_160 ) {
ASSERT ( ! F_125 ( & V_69 ) ) ;
V_111 = 0 ;
}
F_127 ( V_9 , V_157 , V_153 , & V_69 , V_53 , V_54 ) ;
if ( V_69 . V_87 != V_88 &&
V_69 . V_87 != V_89 &&
( V_160 || ! F_125 ( & V_69 ) ) ) {
F_78 ( V_9 , V_153 , & V_69 , V_53 ) ;
if ( F_125 ( & V_69 ) )
F_138 ( V_153 ) ;
if ( V_160 ) {
if ( V_162 )
ASSERT ( ! F_125 ( & V_69 ) ) ;
else
F_123 ( V_9 , V_153 , & V_69 , V_53 ) ;
}
}
V_153 -> V_106 = F_5 ( V_9 ) ;
if ( V_160 &&
( ( ! F_48 ( V_153 ) && ! F_97 ( V_153 ) ) ||
( V_53 >= F_110 ( V_9 ) ) ||
( V_111 || F_125 ( & V_69 ) ) ) )
F_139 ( V_153 ) ;
F_130 ( V_161 && V_69 . V_87 == V_89 ) ;
return 0 ;
V_164:
F_21 ( V_11 , V_163 ) ;
return error ;
}
int
F_140 (
struct V_9 * V_9 ,
T_7 V_157 ,
struct V_4 * V_153 ,
int V_160 )
{
return F_129 ( V_9 , V_157 , V_153 , V_160 , false , false ) ;
}
int
F_141 (
struct V_9 * V_9 ,
T_7 V_157 ,
struct V_4 * V_153 ,
int V_160 )
{
return F_129 ( V_9 , V_157 , V_153 , V_160 , true , false ) ;
}
int
F_142 (
struct V_9 * V_9 ,
T_7 V_157 ,
struct V_4 * V_153 ,
int V_160 )
{
return F_129 ( V_9 , V_157 , V_153 , V_160 , true , true ) ;
}
int
F_143 (
struct V_165 * V_166 ,
T_4 V_53 ,
T_5 V_54 ,
void * V_167 )
{
struct V_9 * V_9 = F_144 ( V_166 -> V_168 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_12 V_141 = ( T_12 ) V_167 ;
int error = 0 ;
F_145 ( V_11 , V_53 , V_54 ) ;
if ( F_33 ( V_13 ) )
return - V_62 ;
if ( V_54 <= 0 )
return V_54 ;
if ( V_141 == 0 ) {
ASSERT ( V_53 + V_54 <= F_110 ( V_9 ) ) ;
return 0 ;
}
F_146 ( & V_11 -> V_169 ) ;
if ( V_53 + V_54 > F_110 ( V_9 ) )
F_147 ( V_9 , V_53 + V_54 ) ;
F_148 ( & V_11 -> V_169 ) ;
if ( V_141 & V_155 ) {
F_149 ( V_11 , V_53 , V_54 ) ;
error = F_34 ( V_11 , V_53 , V_54 ) ;
} else if ( V_141 & V_156 ) {
struct V_45 * V_46 ;
F_150 ( V_11 , V_53 , V_54 ) ;
error = F_14 ( V_13 , & F_15 ( V_13 ) -> V_47 , 0 , 0 , 0 ,
& V_46 ) ;
if ( ! error )
error = F_18 ( V_11 , V_46 , V_53 , V_54 ) ;
}
return error ;
}
STATIC T_5
F_151 (
struct V_165 * V_166 ,
struct V_170 * V_171 )
{
return - V_172 ;
}
STATIC T_7
F_152 (
struct V_150 * V_123 ,
T_7 V_173 )
{
struct V_9 * V_9 = (struct V_9 * ) V_123 -> V_126 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_153 ( F_6 ( V_9 ) ) ;
F_19 ( V_11 , V_174 ) ;
F_154 ( V_123 ) ;
F_21 ( V_11 , V_174 ) ;
return F_155 ( V_123 , V_173 , F_140 ) ;
}
STATIC int
F_156 (
struct V_175 * V_176 ,
struct V_1 * V_1 )
{
F_157 ( V_1 -> V_123 -> V_126 , 1 ) ;
return F_158 ( V_1 , F_140 ) ;
}
STATIC int
F_159 (
struct V_175 * V_176 ,
struct V_150 * V_123 ,
struct V_114 * V_177 ,
unsigned V_178 )
{
F_160 ( V_123 -> V_126 , V_178 ) ;
return F_161 ( V_123 , V_177 , V_178 , F_140 ) ;
}
STATIC int
F_162 (
struct V_1 * V_1 )
{
struct V_150 * V_123 = V_1 -> V_123 ;
struct V_9 * V_9 = V_123 -> V_126 ;
T_4 V_131 ;
T_4 V_53 ;
int V_179 ;
if ( F_163 ( ! V_123 ) )
return ! F_164 ( V_1 ) ;
V_131 = F_110 ( V_9 ) ;
V_53 = F_92 ( V_1 ) ;
F_146 ( & V_123 -> V_180 ) ;
if ( F_86 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_53 < V_131 )
F_165 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_53 += 1 << V_9 -> V_27 ;
} while ( V_5 != V_6 );
}
F_166 ( V_1 ) ;
V_179 = ! F_164 ( V_1 ) ;
F_148 ( & V_123 -> V_180 ) ;
if ( V_179 ) {
unsigned long V_141 ;
F_167 ( & V_123 -> V_181 , V_141 ) ;
if ( V_1 -> V_123 ) {
F_109 ( ! F_98 ( V_1 ) ) ;
F_168 ( V_1 , V_123 ) ;
F_169 ( & V_123 -> V_182 ,
F_170 ( V_1 ) , V_183 ) ;
}
F_171 ( & V_123 -> V_181 , V_141 ) ;
}
F_172 ( V_1 ) ;
if ( V_179 )
F_173 ( V_123 -> V_126 , V_184 ) ;
return V_179 ;
}
