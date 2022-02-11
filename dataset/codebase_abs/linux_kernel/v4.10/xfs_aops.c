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
int
F_27 (
struct V_10 * V_11 ,
T_1 V_53 ,
T_2 V_54 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_45 * V_46 ;
int error ;
error = F_14 ( V_13 , & F_15 ( V_13 ) -> V_47 , 0 , 0 , 0 , & V_46 ) ;
if ( error )
return error ;
return F_18 ( V_11 , V_46 , V_53 , V_54 ) ;
}
STATIC int
F_28 (
struct V_32 * V_33 ,
int error )
{
struct V_10 * V_11 = F_6 ( V_33 -> V_34 ) ;
struct V_45 * V_46 = V_33 -> V_48 ;
F_29 ( & V_46 -> V_51 , V_52 ) ;
F_30 ( F_31 ( V_11 ) -> V_49 , V_50 ) ;
if ( error ) {
F_22 ( V_46 ) ;
return error ;
}
return F_18 ( V_11 , V_46 , V_33 -> V_41 , V_33 -> V_42 ) ;
}
STATIC void
F_32 (
struct V_58 * V_59 )
{
struct V_32 * V_33 =
F_33 ( V_59 , struct V_32 , V_60 ) ;
struct V_10 * V_11 = F_6 ( V_33 -> V_34 ) ;
int error = V_33 -> V_37 -> V_61 ;
if ( F_34 ( V_11 -> V_14 ) )
error = - V_62 ;
if ( V_33 -> V_63 == V_64 ) {
if ( error )
goto V_65;
if ( V_33 -> V_37 -> V_61 ) {
error = F_35 ( V_11 ,
V_33 -> V_41 , V_33 -> V_42 ) ;
goto V_65;
}
error = F_36 ( V_11 , V_33 -> V_41 ,
V_33 -> V_42 ) ;
if ( error )
goto V_65;
}
if ( V_33 -> V_63 == V_66 ) {
if ( error )
goto V_65;
error = F_37 ( V_11 , V_33 -> V_41 ,
V_33 -> V_42 ) ;
} else if ( V_33 -> V_48 ) {
error = F_28 ( V_33 , error ) ;
} else {
ASSERT ( ! F_12 ( V_33 ) ||
V_33 -> V_63 == V_64 ) ;
}
V_65:
F_9 ( V_33 , error ) ;
}
STATIC void
F_38 (
struct V_35 * V_35 )
{
struct V_32 * V_33 = V_35 -> V_40 ;
struct V_12 * V_13 = F_6 ( V_33 -> V_34 ) -> V_14 ;
if ( V_33 -> V_63 == V_66 || V_33 -> V_63 == V_64 )
F_39 ( V_13 -> V_67 , & V_33 -> V_60 ) ;
else if ( V_33 -> V_48 )
F_39 ( V_13 -> V_68 , & V_33 -> V_60 ) ;
else
F_9 ( V_33 , V_35 -> V_61 ) ;
}
STATIC int
F_40 (
struct V_9 * V_9 ,
T_4 V_53 ,
struct V_69 * V_70 ,
int type )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_5 V_71 = 1 << V_9 -> V_27 ;
T_6 V_72 , V_73 ;
int error = 0 ;
int V_74 = V_75 ;
int V_76 = 1 ;
if ( F_34 ( V_13 ) )
return - V_62 ;
ASSERT ( type != V_64 ) ;
if ( type == V_66 )
V_74 |= V_77 ;
F_19 ( V_11 , V_78 ) ;
ASSERT ( V_11 -> V_43 . V_79 != V_80 ||
( V_11 -> V_81 . V_82 & V_83 ) ) ;
ASSERT ( V_53 <= V_13 -> V_84 -> V_85 ) ;
if ( V_53 + V_71 > V_13 -> V_84 -> V_85 )
V_71 = V_13 -> V_84 -> V_85 - V_53 ;
V_73 = F_41 ( V_13 , ( V_86 ) V_53 + V_71 ) ;
V_72 = F_42 ( V_13 , V_53 ) ;
error = F_43 ( V_11 , V_72 , V_73 - V_72 ,
V_70 , & V_76 , V_74 ) ;
if ( V_76 && type == V_87 )
F_44 ( V_11 , V_72 , V_70 ) ;
F_21 ( V_11 , V_78 ) ;
if ( error )
return error ;
if ( type == V_88 &&
( ! V_76 || F_45 ( V_70 -> V_89 ) ) ) {
error = F_46 ( V_11 , V_90 , V_53 ,
V_70 ) ;
if ( ! error )
F_47 ( V_11 , V_53 , V_71 , type , V_70 ) ;
return error ;
}
#ifdef F_48
if ( type == V_66 ) {
ASSERT ( V_76 ) ;
ASSERT ( V_70 -> V_89 != V_91 ) ;
ASSERT ( V_70 -> V_89 != V_92 ) ;
}
#endif
if ( V_76 )
F_49 ( V_11 , V_53 , V_71 , type , V_70 ) ;
return 0 ;
}
STATIC bool
F_50 (
struct V_9 * V_9 ,
struct V_69 * V_70 ,
T_1 V_53 )
{
V_53 >>= V_9 -> V_27 ;
return V_53 >= V_70 -> V_93 &&
V_53 < V_70 -> V_93 + V_70 -> V_94 ;
}
STATIC void
F_51 (
struct V_4 * V_5 )
{
ASSERT ( F_52 ( V_5 ) ) ;
ASSERT ( F_53 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_54 ( V_5 ) ;
F_55 ( V_5 ) ;
F_56 ( V_5 ) ;
}
STATIC void
F_57 (
struct V_1 * V_1 ,
int V_95 )
{
ASSERT ( F_58 ( V_1 ) ) ;
ASSERT ( ! F_59 ( V_1 ) ) ;
if ( V_95 ) {
F_60 ( V_1 ) ;
F_61 ( V_1 ) ;
} else
F_62 ( V_1 ) ;
F_63 ( V_1 ) ;
}
static inline int F_64 ( struct V_35 * V_35 , struct V_4 * V_5 )
{
return F_65 ( V_35 , V_5 -> V_96 , V_5 -> V_29 , F_66 ( V_5 ) ) ;
}
STATIC int
F_67 (
struct V_97 * V_98 ,
struct V_32 * V_33 ,
int V_99 )
{
if ( ! V_99 &&
V_33 -> V_63 != V_66 &&
F_12 ( V_33 ) &&
! V_33 -> V_48 )
V_99 = F_13 ( V_33 ) ;
V_33 -> V_37 -> V_40 = V_33 ;
V_33 -> V_37 -> V_100 = F_38 ;
V_33 -> V_37 -> V_101 = V_102 | F_68 ( V_98 ) ;
if ( V_99 ) {
V_33 -> V_37 -> V_61 = V_99 ;
F_69 ( V_33 -> V_37 ) ;
return V_99 ;
}
F_70 ( V_33 -> V_37 ) ;
return 0 ;
}
static void
F_71 (
struct V_35 * V_35 ,
struct V_4 * V_5 )
{
V_35 -> V_103 . V_104 = V_5 -> V_105 * ( V_5 -> V_29 >> 9 ) ;
V_35 -> V_106 = V_5 -> V_107 ;
}
static struct V_32 *
F_72 (
struct V_9 * V_9 ,
unsigned int type ,
T_1 V_53 ,
struct V_4 * V_5 )
{
struct V_32 * V_33 ;
struct V_35 * V_35 ;
V_35 = F_73 ( V_108 , V_109 , V_110 ) ;
F_71 ( V_35 , V_5 ) ;
V_33 = F_33 ( V_35 , struct V_32 , V_38 ) ;
F_74 ( & V_33 -> V_111 ) ;
V_33 -> V_63 = type ;
V_33 -> V_34 = V_9 ;
V_33 -> V_42 = 0 ;
V_33 -> V_41 = V_53 ;
F_75 ( & V_33 -> V_60 , F_32 ) ;
V_33 -> V_48 = NULL ;
V_33 -> V_37 = V_35 ;
return V_33 ;
}
static void
F_76 (
struct V_32 * V_33 ,
struct V_97 * V_98 ,
struct V_4 * V_5 )
{
struct V_35 * V_112 ;
V_112 = F_77 ( V_108 , V_109 ) ;
F_71 ( V_112 , V_5 ) ;
F_78 ( V_33 -> V_37 , V_112 ) ;
F_79 ( V_33 -> V_37 ) ;
V_33 -> V_37 -> V_101 = V_102 | F_68 ( V_98 ) ;
F_70 ( V_33 -> V_37 ) ;
V_33 -> V_37 = V_112 ;
}
STATIC void
F_80 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_1 V_53 ,
struct V_113 * V_114 ,
struct V_97 * V_98 ,
struct V_115 * V_116 )
{
if ( ! V_114 -> V_33 || V_114 -> V_63 != V_114 -> V_33 -> V_63 ||
V_5 -> V_105 != V_114 -> V_117 + 1 ||
V_53 != V_114 -> V_33 -> V_41 + V_114 -> V_33 -> V_42 ) {
if ( V_114 -> V_33 )
F_81 ( & V_114 -> V_33 -> V_111 , V_116 ) ;
V_114 -> V_33 = F_72 ( V_9 , V_114 -> V_63 , V_53 , V_5 ) ;
}
while ( F_64 ( V_114 -> V_33 -> V_37 , V_5 ) != V_5 -> V_29 )
F_76 ( V_114 -> V_33 , V_98 , V_5 ) ;
V_114 -> V_33 -> V_42 += V_5 -> V_29 ;
V_114 -> V_117 = V_5 -> V_105 ;
F_51 ( V_5 ) ;
}
STATIC void
F_82 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_69 * V_70 ,
T_1 V_53 )
{
T_7 V_118 ;
struct V_12 * V_119 = F_6 ( V_9 ) -> V_14 ;
T_1 V_120 = F_83 ( V_119 , V_70 -> V_93 ) ;
T_8 V_121 = F_84 ( F_6 ( V_9 ) , V_70 -> V_89 ) ;
ASSERT ( V_70 -> V_89 != V_91 ) ;
ASSERT ( V_70 -> V_89 != V_92 ) ;
V_118 = ( V_121 >> ( V_9 -> V_27 - V_122 ) ) +
( ( V_53 - V_120 ) >> V_9 -> V_27 ) ;
ASSERT ( V_118 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_105 = V_118 ;
F_85 ( V_5 ) ;
}
STATIC void
F_86 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_69 * V_70 ,
T_1 V_53 )
{
ASSERT ( V_70 -> V_89 != V_91 ) ;
ASSERT ( V_70 -> V_89 != V_92 ) ;
F_82 ( V_9 , V_5 , V_70 , V_53 ) ;
F_85 ( V_5 ) ;
F_87 ( V_5 ) ;
F_88 ( V_5 ) ;
}
STATIC bool
F_89 (
struct V_1 * V_1 ,
unsigned int type ,
bool V_123 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
if ( F_59 ( V_1 ) )
return false ;
if ( ! V_1 -> V_124 )
return false ;
if ( ! F_90 ( V_1 ) )
return false ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) ) {
if ( type == V_66 )
return true ;
} else if ( F_4 ( V_5 ) ) {
if ( type == V_88 )
return true ;
} else if ( F_91 ( V_5 ) && F_52 ( V_5 ) ) {
if ( type == V_87 )
return true ;
}
if ( ! V_123 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC void
F_92 (
struct V_1 * V_1 ,
unsigned int V_53 ,
unsigned int V_125 )
{
F_93 ( V_1 -> V_124 -> V_126 , V_1 , V_53 ,
V_125 ) ;
F_94 ( V_1 , V_53 , V_125 ) ;
}
STATIC void
F_95 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_124 -> V_126 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_4 V_53 = F_96 ( V_1 ) ;
if ( ! F_89 ( V_1 , V_88 , true ) )
goto V_127;
if ( F_34 ( V_11 -> V_14 ) )
goto V_127;
F_97 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_128 , V_53 ) ;
F_19 ( V_11 , V_56 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_6 V_129 ;
if ( ! F_4 ( V_5 ) )
goto V_130;
V_129 = F_42 ( V_11 -> V_14 , V_53 ) ;
error = F_98 ( V_11 , V_129 , 1 ) ;
if ( error ) {
if ( ! F_34 ( V_11 -> V_14 ) ) {
F_97 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_130:
V_53 += 1 << V_9 -> V_27 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_21 ( V_11 , V_56 ) ;
V_127:
F_92 ( V_1 , 0 , V_26 ) ;
return;
}
static int
F_99 (
struct V_113 * V_114 ,
struct V_9 * V_9 ,
T_4 V_53 ,
unsigned int * V_131 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_69 V_70 ;
bool V_132 = false ;
int error ;
if ( V_114 -> V_63 == V_64 ) {
V_114 -> V_133 = F_50 ( V_9 , & V_114 -> V_70 , V_53 ) ;
if ( V_114 -> V_133 ) {
* V_131 = V_64 ;
return 0 ;
}
}
F_19 ( V_11 , V_78 ) ;
V_132 = F_100 ( V_11 , V_53 , & V_70 ) ;
F_21 ( V_11 , V_78 ) ;
if ( ! V_132 )
return 0 ;
if ( F_45 ( V_70 . V_89 ) ) {
error = F_46 ( V_11 , V_134 , V_53 ,
& V_70 ) ;
if ( error )
return error ;
}
V_114 -> V_63 = * V_131 = V_64 ;
V_114 -> V_133 = true ;
V_114 -> V_70 = V_70 ;
return 0 ;
}
static int
F_101 (
struct V_113 * V_114 ,
struct V_97 * V_98 ,
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_4 V_53 ,
T_9 V_135 )
{
F_102 ( V_136 ) ;
struct V_32 * V_33 , * V_23 ;
struct V_4 * V_5 , * V_6 ;
T_5 V_137 = 1 << V_9 -> V_27 ;
int error = 0 ;
int V_71 = 0 ;
int V_138 = 1 ;
unsigned int V_131 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_53 = F_96 ( V_1 ) ;
do {
if ( V_53 >= V_135 )
break;
if ( ! F_103 ( V_5 ) )
V_138 = 0 ;
if ( ! F_52 ( V_5 ) && F_103 ( V_5 ) ) {
V_114 -> V_133 = false ;
continue;
}
if ( F_3 ( V_5 ) )
V_131 = V_66 ;
else if ( F_4 ( V_5 ) )
V_131 = V_88 ;
else if ( F_103 ( V_5 ) )
V_131 = V_87 ;
else {
if ( F_104 ( V_1 ) )
ASSERT ( F_52 ( V_5 ) ) ;
V_114 -> V_133 = false ;
continue;
}
if ( F_105 ( F_6 ( V_9 ) ) ) {
error = F_99 ( V_114 , V_9 , V_53 , & V_131 ) ;
if ( error )
goto V_139;
}
if ( V_114 -> V_63 != V_131 ) {
V_114 -> V_63 = V_131 ;
V_114 -> V_133 = false ;
}
if ( V_114 -> V_133 )
V_114 -> V_133 = F_50 ( V_9 , & V_114 -> V_70 ,
V_53 ) ;
if ( ! V_114 -> V_133 ) {
error = F_40 ( V_9 , V_53 , & V_114 -> V_70 ,
V_114 -> V_63 ) ;
if ( error )
goto V_139;
V_114 -> V_133 = F_50 ( V_9 , & V_114 -> V_70 ,
V_53 ) ;
}
if ( V_114 -> V_133 ) {
F_106 ( V_5 ) ;
if ( V_114 -> V_63 != V_87 )
F_86 ( V_9 , V_5 , & V_114 -> V_70 , V_53 ) ;
F_80 ( V_9 , V_5 , V_53 , V_114 , V_98 , & V_136 ) ;
V_71 ++ ;
}
} while ( V_53 += V_137 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_138 && V_5 == V_6 )
F_107 ( V_1 ) ;
ASSERT ( V_114 -> V_33 || F_108 ( & V_136 ) ) ;
V_139:
if ( V_71 ) {
F_57 ( V_1 , ! error ) ;
F_109 (ioend, next, &submit_list, io_list) {
int V_140 ;
F_110 ( & V_33 -> V_111 ) ;
V_140 = F_67 ( V_98 , V_33 , error ) ;
if ( V_140 && ! error )
error = V_140 ;
}
} else if ( error ) {
F_95 ( V_1 ) ;
F_111 ( V_1 ) ;
F_63 ( V_1 ) ;
} else {
F_57 ( V_1 , 1 ) ;
F_112 ( V_1 ) ;
}
F_113 ( V_1 -> V_124 , error ) ;
return error ;
}
STATIC int
F_114 (
struct V_1 * V_1 ,
struct V_97 * V_98 ,
void * V_141 )
{
struct V_113 * V_114 = V_141 ;
struct V_9 * V_9 = V_1 -> V_124 -> V_126 ;
T_4 V_53 ;
T_9 V_135 ;
T_10 V_142 ;
F_115 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_90 ( V_1 ) ) ;
if ( F_116 ( ( V_143 -> V_144 & ( V_145 | V_146 ) ) ==
V_145 ) )
goto V_147;
if ( F_116 ( V_143 -> V_144 & V_52 ) )
goto V_147;
V_53 = F_117 ( V_9 ) ;
V_142 = V_53 >> V_148 ;
if ( V_1 -> V_149 < V_142 )
V_135 = ( T_1 ) ( V_1 -> V_149 + 1 ) << V_148 ;
else {
unsigned V_150 = V_53 & ( V_26 - 1 ) ;
if ( V_1 -> V_149 > V_142 ||
( V_1 -> V_149 == V_142 && V_150 == 0 ) )
goto V_147;
F_118 ( V_1 , V_150 , V_26 ) ;
V_135 = V_53 ;
}
return F_101 ( V_114 , V_98 , V_9 , V_1 , V_53 , V_135 ) ;
V_147:
F_119 ( V_98 , V_1 ) ;
F_63 ( V_1 ) ;
return 0 ;
}
STATIC int
F_120 (
struct V_1 * V_1 ,
struct V_97 * V_98 )
{
struct V_113 V_114 = {
. V_63 = V_151 ,
} ;
int V_152 ;
V_152 = F_114 ( V_1 , V_98 , & V_114 ) ;
if ( V_114 . V_33 )
V_152 = F_67 ( V_98 , V_114 . V_33 , V_152 ) ;
return V_152 ;
}
STATIC int
F_121 (
struct V_153 * V_124 ,
struct V_97 * V_98 )
{
struct V_113 V_114 = {
. V_63 = V_151 ,
} ;
int V_152 ;
F_122 ( F_6 ( V_124 -> V_126 ) , V_154 ) ;
if ( F_123 ( V_124 ) )
return F_124 ( V_124 ,
F_5 ( V_124 -> V_126 ) , V_98 ) ;
V_152 = F_125 ( V_124 , V_98 , F_114 , & V_114 ) ;
if ( V_114 . V_33 )
V_152 = F_67 ( V_98 , V_114 . V_33 , V_152 ) ;
return V_152 ;
}
STATIC int
F_126 (
struct V_1 * V_1 ,
T_11 V_155 )
{
int V_2 , V_3 ;
F_127 ( V_1 -> V_124 -> V_126 , V_1 , 0 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( V_2 ) {
F_116 ( ! F_128 ( V_1 ) ) ;
return 0 ;
}
if ( V_3 ) {
F_116 ( ! F_128 ( V_1 ) ) ;
return 0 ;
}
return F_129 ( V_1 ) ;
}
static void
F_130 (
struct V_9 * V_9 ,
T_7 V_156 ,
struct V_4 * V_157 ,
struct V_69 * V_70 ,
T_1 V_53 ,
T_5 V_54 )
{
T_1 V_158 ;
V_158 = V_70 -> V_93 + V_70 -> V_94 - V_156 ;
V_158 <<= V_9 -> V_27 ;
ASSERT ( V_158 > 0 ) ;
if ( V_158 > V_54 )
V_158 = V_54 ;
if ( V_53 < F_117 ( V_9 ) &&
V_53 + V_158 >= F_117 ( V_9 ) ) {
V_158 = F_131 ( F_117 ( V_9 ) - V_53 ,
1 << V_9 -> V_27 ) ;
}
if ( V_158 > V_159 )
V_158 = V_159 ;
V_157 -> V_29 = V_158 ;
}
static int
F_132 (
struct V_9 * V_9 ,
T_7 V_156 ,
struct V_4 * V_157 ,
int V_160 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_72 , V_73 ;
int error = 0 ;
int V_161 = 0 ;
struct V_69 V_70 ;
int V_76 = 1 ;
T_1 V_53 ;
T_5 V_54 ;
F_133 ( V_160 ) ;
if ( F_34 ( V_13 ) )
return - V_62 ;
V_53 = ( T_1 ) V_156 << V_9 -> V_27 ;
ASSERT ( V_157 -> V_29 >= ( 1 << V_9 -> V_27 ) ) ;
V_54 = V_157 -> V_29 ;
if ( V_53 >= F_117 ( V_9 ) )
return 0 ;
V_161 = F_134 ( V_11 ) ;
ASSERT ( V_53 <= V_13 -> V_84 -> V_85 ) ;
if ( V_53 + V_54 > V_13 -> V_84 -> V_85 )
V_54 = V_13 -> V_84 -> V_85 - V_53 ;
V_73 = F_41 ( V_13 , ( V_86 ) V_53 + V_54 ) ;
V_72 = F_42 ( V_13 , V_53 ) ;
error = F_43 ( V_11 , V_72 , V_73 - V_72 ,
& V_70 , & V_76 , V_75 ) ;
if ( error )
goto V_162;
if ( V_76 ) {
F_135 ( V_11 , V_53 , V_54 ,
F_136 ( & V_70 ) ? V_66
: V_87 , & V_70 ) ;
F_21 ( V_11 , V_161 ) ;
} else {
F_137 ( V_11 , V_53 , V_54 ) ;
goto V_162;
}
F_130 ( V_9 , V_156 , V_157 , & V_70 , V_53 , V_54 ) ;
if ( V_70 . V_89 != V_91 &&
V_70 . V_89 != V_92 &&
! F_136 ( & V_70 ) )
F_82 ( V_9 , V_157 , & V_70 , V_53 ) ;
V_157 -> V_107 = F_5 ( V_9 ) ;
return 0 ;
V_162:
F_21 ( V_11 , V_161 ) ;
return error ;
}
STATIC T_5
F_138 (
struct V_163 * V_164 ,
struct V_165 * V_166 )
{
return - V_167 ;
}
STATIC T_7
F_139 (
struct V_153 * V_124 ,
T_7 V_168 )
{
struct V_9 * V_9 = (struct V_9 * ) V_124 -> V_126 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_140 ( F_6 ( V_9 ) ) ;
if ( F_105 ( V_11 ) )
return 0 ;
F_141 ( V_124 ) ;
return F_142 ( V_124 , V_168 , F_132 ) ;
}
STATIC int
F_143 (
struct V_169 * V_170 ,
struct V_1 * V_1 )
{
F_144 ( V_1 -> V_124 -> V_126 , 1 ) ;
return F_145 ( V_1 , F_132 ) ;
}
STATIC int
F_146 (
struct V_169 * V_170 ,
struct V_153 * V_124 ,
struct V_115 * V_171 ,
unsigned V_172 )
{
F_147 ( V_124 -> V_126 , V_172 ) ;
return F_148 ( V_124 , V_171 , V_172 , F_132 ) ;
}
STATIC int
F_149 (
struct V_1 * V_1 )
{
struct V_153 * V_124 = V_1 -> V_124 ;
struct V_9 * V_9 = V_124 -> V_126 ;
T_4 V_135 ;
T_4 V_53 ;
int V_173 ;
if ( F_150 ( ! V_124 ) )
return ! F_151 ( V_1 ) ;
V_135 = F_117 ( V_9 ) ;
V_53 = F_96 ( V_1 ) ;
F_152 ( & V_124 -> V_174 ) ;
if ( F_90 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_53 < V_135 )
F_153 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_53 += 1 << V_9 -> V_27 ;
} while ( V_5 != V_6 );
}
F_154 ( V_1 ) ;
V_173 = ! F_151 ( V_1 ) ;
F_155 ( & V_124 -> V_174 ) ;
if ( V_173 ) {
unsigned long V_144 ;
F_156 ( & V_124 -> V_175 , V_144 ) ;
if ( V_1 -> V_124 ) {
F_116 ( ! F_104 ( V_1 ) ) ;
F_157 ( V_1 , V_124 ) ;
F_158 ( & V_124 -> V_176 ,
F_159 ( V_1 ) , V_177 ) ;
}
F_160 ( & V_124 -> V_175 , V_144 ) ;
}
F_161 ( V_1 ) ;
if ( V_173 )
F_162 ( V_124 -> V_126 , V_178 ) ;
return V_173 ;
}
