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
F_68 ( V_33 -> V_37 , V_101 ,
( V_98 -> V_102 == V_103 ) ? V_104 : 0 ) ;
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
V_35 -> V_105 . V_106 = V_5 -> V_107 * ( V_5 -> V_29 >> 9 ) ;
V_35 -> V_108 = V_5 -> V_109 ;
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
V_35 = F_73 ( V_110 , V_111 , V_112 ) ;
F_71 ( V_35 , V_5 ) ;
V_33 = F_33 ( V_35 , struct V_32 , V_38 ) ;
F_74 ( & V_33 -> V_113 ) ;
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
struct V_35 * V_114 ;
V_114 = F_77 ( V_110 , V_111 ) ;
F_71 ( V_114 , V_5 ) ;
F_78 ( V_33 -> V_37 , V_114 ) ;
F_79 ( V_33 -> V_37 ) ;
F_68 ( V_33 -> V_37 , V_101 ,
( V_98 -> V_102 == V_103 ) ? V_104 : 0 ) ;
F_70 ( V_33 -> V_37 ) ;
V_33 -> V_37 = V_114 ;
}
STATIC void
F_80 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_1 V_53 ,
struct V_115 * V_116 ,
struct V_97 * V_98 ,
struct V_117 * V_118 )
{
if ( ! V_116 -> V_33 || V_116 -> V_63 != V_116 -> V_33 -> V_63 ||
V_5 -> V_107 != V_116 -> V_119 + 1 ||
V_53 != V_116 -> V_33 -> V_41 + V_116 -> V_33 -> V_42 ) {
if ( V_116 -> V_33 )
F_81 ( & V_116 -> V_33 -> V_113 , V_118 ) ;
V_116 -> V_33 = F_72 ( V_9 , V_116 -> V_63 , V_53 , V_5 ) ;
}
while ( F_64 ( V_116 -> V_33 -> V_37 , V_5 ) != V_5 -> V_29 )
F_76 ( V_116 -> V_33 , V_98 , V_5 ) ;
V_116 -> V_33 -> V_42 += V_5 -> V_29 ;
V_116 -> V_119 = V_5 -> V_107 ;
F_51 ( V_5 ) ;
}
STATIC void
F_82 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_69 * V_70 ,
T_1 V_53 )
{
T_7 V_120 ;
struct V_12 * V_121 = F_6 ( V_9 ) -> V_14 ;
T_1 V_122 = F_83 ( V_121 , V_70 -> V_93 ) ;
T_8 V_123 = F_84 ( F_6 ( V_9 ) , V_70 -> V_89 ) ;
ASSERT ( V_70 -> V_89 != V_91 ) ;
ASSERT ( V_70 -> V_89 != V_92 ) ;
V_120 = ( V_123 >> ( V_9 -> V_27 - V_124 ) ) +
( ( V_53 - V_122 ) >> V_9 -> V_27 ) ;
ASSERT ( V_120 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_107 = V_120 ;
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
bool V_125 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
if ( F_59 ( V_1 ) )
return false ;
if ( ! V_1 -> V_126 )
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
if ( ! V_125 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC void
F_92 (
struct V_1 * V_1 ,
unsigned int V_53 ,
unsigned int V_127 )
{
F_93 ( V_1 -> V_126 -> V_128 , V_1 , V_53 ,
V_127 ) ;
F_94 ( V_1 , V_53 , V_127 ) ;
}
STATIC void
F_95 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_126 -> V_128 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_4 V_53 = F_96 ( V_1 ) ;
if ( ! F_89 ( V_1 , V_88 , true ) )
goto V_129;
if ( F_34 ( V_11 -> V_14 ) )
goto V_129;
F_97 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_130 , V_53 ) ;
F_19 ( V_11 , V_56 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_6 V_131 ;
if ( ! F_4 ( V_5 ) )
goto V_132;
V_131 = F_42 ( V_11 -> V_14 , V_53 ) ;
error = F_98 ( V_11 , V_131 , 1 ) ;
if ( error ) {
if ( ! F_34 ( V_11 -> V_14 ) ) {
F_97 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_132:
V_53 += 1 << V_9 -> V_27 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_21 ( V_11 , V_56 ) ;
V_129:
F_92 ( V_1 , 0 , V_26 ) ;
return;
}
static int
F_99 (
struct V_115 * V_116 ,
struct V_9 * V_9 ,
T_4 V_53 ,
unsigned int * V_133 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_69 V_70 ;
bool V_134 = false , V_135 = false ;
int error ;
if ( V_116 -> V_63 == V_64 ) {
V_116 -> V_136 = F_50 ( V_9 , & V_116 -> V_70 , V_53 ) ;
if ( V_116 -> V_136 ) {
* V_133 = V_64 ;
return 0 ;
}
}
F_19 ( V_11 , V_78 ) ;
V_134 = F_100 ( V_11 , V_53 , & V_70 , & V_135 ) ;
F_21 ( V_11 , V_78 ) ;
if ( ! V_134 )
return 0 ;
if ( V_135 ) {
error = F_46 ( V_11 , V_137 , V_53 ,
& V_70 ) ;
if ( error )
return error ;
}
V_116 -> V_63 = * V_133 = V_64 ;
V_116 -> V_136 = true ;
V_116 -> V_70 = V_70 ;
return 0 ;
}
static int
F_101 (
struct V_115 * V_116 ,
struct V_97 * V_98 ,
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_4 V_53 ,
T_9 V_138 )
{
F_102 ( V_139 ) ;
struct V_32 * V_33 , * V_23 ;
struct V_4 * V_5 , * V_6 ;
T_5 V_140 = 1 << V_9 -> V_27 ;
int error = 0 ;
int V_71 = 0 ;
int V_141 = 1 ;
unsigned int V_133 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_53 = F_96 ( V_1 ) ;
do {
if ( V_53 >= V_138 )
break;
if ( ! F_103 ( V_5 ) )
V_141 = 0 ;
if ( ! F_52 ( V_5 ) && F_103 ( V_5 ) ) {
V_116 -> V_136 = false ;
continue;
}
if ( F_3 ( V_5 ) )
V_133 = V_66 ;
else if ( F_4 ( V_5 ) )
V_133 = V_88 ;
else if ( F_103 ( V_5 ) )
V_133 = V_87 ;
else {
if ( F_104 ( V_1 ) )
ASSERT ( F_52 ( V_5 ) ) ;
V_116 -> V_136 = false ;
continue;
}
if ( F_105 ( F_6 ( V_9 ) ) ) {
error = F_99 ( V_116 , V_9 , V_53 , & V_133 ) ;
if ( error )
goto V_142;
}
if ( V_116 -> V_63 != V_133 ) {
V_116 -> V_63 = V_133 ;
V_116 -> V_136 = false ;
}
if ( V_116 -> V_136 )
V_116 -> V_136 = F_50 ( V_9 , & V_116 -> V_70 ,
V_53 ) ;
if ( ! V_116 -> V_136 ) {
error = F_40 ( V_9 , V_53 , & V_116 -> V_70 ,
V_116 -> V_63 ) ;
if ( error )
goto V_142;
V_116 -> V_136 = F_50 ( V_9 , & V_116 -> V_70 ,
V_53 ) ;
}
if ( V_116 -> V_136 ) {
F_106 ( V_5 ) ;
if ( V_116 -> V_63 != V_87 )
F_86 ( V_9 , V_5 , & V_116 -> V_70 , V_53 ) ;
F_80 ( V_9 , V_5 , V_53 , V_116 , V_98 , & V_139 ) ;
V_71 ++ ;
}
} while ( V_53 += V_140 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_141 && V_5 == V_6 )
F_107 ( V_1 ) ;
ASSERT ( V_116 -> V_33 || F_108 ( & V_139 ) ) ;
V_142:
if ( V_71 ) {
F_57 ( V_1 , ! error ) ;
F_109 (ioend, next, &submit_list, io_list) {
int V_143 ;
F_110 ( & V_33 -> V_113 ) ;
V_143 = F_67 ( V_98 , V_33 , error ) ;
if ( V_143 && ! error )
error = V_143 ;
}
} else if ( error ) {
F_95 ( V_1 ) ;
F_111 ( V_1 ) ;
F_63 ( V_1 ) ;
} else {
F_57 ( V_1 , 1 ) ;
F_112 ( V_1 ) ;
}
F_113 ( V_1 -> V_126 , error ) ;
return error ;
}
STATIC int
F_114 (
struct V_1 * V_1 ,
struct V_97 * V_98 ,
void * V_144 )
{
struct V_115 * V_116 = V_144 ;
struct V_9 * V_9 = V_1 -> V_126 -> V_128 ;
T_4 V_53 ;
T_9 V_138 ;
T_10 V_145 ;
F_115 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_90 ( V_1 ) ) ;
if ( F_116 ( ( V_146 -> V_147 & ( V_148 | V_149 ) ) ==
V_148 ) )
goto V_150;
if ( F_116 ( V_146 -> V_147 & V_52 ) )
goto V_150;
V_53 = F_117 ( V_9 ) ;
V_145 = V_53 >> V_151 ;
if ( V_1 -> V_152 < V_145 )
V_138 = ( T_1 ) ( V_1 -> V_152 + 1 ) << V_151 ;
else {
unsigned V_153 = V_53 & ( V_26 - 1 ) ;
if ( V_1 -> V_152 > V_145 ||
( V_1 -> V_152 == V_145 && V_153 == 0 ) )
goto V_150;
F_118 ( V_1 , V_153 , V_26 ) ;
V_138 = V_53 ;
}
return F_101 ( V_116 , V_98 , V_9 , V_1 , V_53 , V_138 ) ;
V_150:
F_119 ( V_98 , V_1 ) ;
F_63 ( V_1 ) ;
return 0 ;
}
STATIC int
F_120 (
struct V_1 * V_1 ,
struct V_97 * V_98 )
{
struct V_115 V_116 = {
. V_63 = V_154 ,
} ;
int V_155 ;
V_155 = F_114 ( V_1 , V_98 , & V_116 ) ;
if ( V_116 . V_33 )
V_155 = F_67 ( V_98 , V_116 . V_33 , V_155 ) ;
return V_155 ;
}
STATIC int
F_121 (
struct V_156 * V_126 ,
struct V_97 * V_98 )
{
struct V_115 V_116 = {
. V_63 = V_154 ,
} ;
int V_155 ;
F_122 ( F_6 ( V_126 -> V_128 ) , V_157 ) ;
if ( F_123 ( V_126 ) )
return F_124 ( V_126 ,
F_5 ( V_126 -> V_128 ) , V_98 ) ;
V_155 = F_125 ( V_126 , V_98 , F_114 , & V_116 ) ;
if ( V_116 . V_33 )
V_155 = F_67 ( V_98 , V_116 . V_33 , V_155 ) ;
return V_155 ;
}
STATIC int
F_126 (
struct V_1 * V_1 ,
T_11 V_158 )
{
int V_2 , V_3 ;
F_127 ( V_1 -> V_126 -> V_128 , V_1 , 0 , 0 ) ;
if ( F_128 ( V_1 ) )
return 0 ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_116 ( V_2 ) )
return 0 ;
if ( F_116 ( V_3 ) )
return 0 ;
return F_129 ( V_1 ) ;
}
static void
F_130 (
struct V_9 * V_9 ,
struct V_4 * V_159 ,
struct V_69 * V_70 ,
T_1 V_53 ,
bool V_134 )
{
T_12 * V_147 = ( T_12 * ) & V_159 -> V_160 ;
T_1 V_54 = V_159 -> V_29 ;
F_131 ( F_6 ( V_9 ) , V_53 , V_54 ,
F_132 ( V_70 ) ? V_66 : V_134 ? V_64 :
V_87 , V_70 ) ;
if ( F_132 ( V_70 ) ) {
* V_147 |= V_161 ;
F_133 ( V_159 ) ;
} else if ( V_134 ) {
* V_147 |= V_162 ;
F_133 ( V_159 ) ;
}
if ( V_53 + V_54 > F_117 ( V_9 ) || V_53 + V_54 < 0 ) {
* V_147 |= V_163 ;
F_133 ( V_159 ) ;
}
}
static void
F_134 (
struct V_9 * V_9 ,
T_7 V_164 ,
struct V_4 * V_159 ,
struct V_69 * V_70 ,
T_1 V_53 ,
T_5 V_54 )
{
T_1 V_165 ;
V_165 = V_70 -> V_93 + V_70 -> V_94 - V_164 ;
V_165 <<= V_9 -> V_27 ;
ASSERT ( V_165 > 0 ) ;
if ( V_165 > V_54 )
V_165 = V_54 ;
if ( V_53 < F_117 ( V_9 ) &&
V_53 + V_165 >= F_117 ( V_9 ) ) {
V_165 = F_135 ( F_117 ( V_9 ) - V_53 ,
1 << V_9 -> V_27 ) ;
}
if ( V_165 > V_166 )
V_165 = V_166 ;
V_159 -> V_29 = V_165 ;
}
static int
F_136 (
struct V_10 * V_11 ,
T_6 V_72 ,
struct V_69 * V_70 )
{
struct V_69 V_167 ;
T_6 V_168 ;
bool V_169 ;
bool V_170 ;
int error ;
V_167 = * V_70 ;
if ( V_72 > V_167 . V_93 ) {
V_168 = V_72 - V_167 . V_93 ;
V_167 . V_94 -= V_168 ;
V_167 . V_89 += V_168 ;
V_167 . V_93 = V_72 ;
}
error = F_137 ( V_11 , & V_167 , & V_169 , & V_170 ) ;
if ( error )
return error ;
if ( V_169 ) {
F_138 ( V_11 , V_70 ) ;
return - V_171 ;
}
return 0 ;
}
STATIC int
F_139 (
struct V_9 * V_9 ,
T_7 V_164 ,
struct V_4 * V_159 ,
int V_172 ,
bool V_173 ,
bool V_174 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_72 , V_73 ;
int error = 0 ;
int V_175 = 0 ;
struct V_69 V_70 ;
int V_76 = 1 ;
T_1 V_53 ;
T_5 V_54 ;
int V_114 = 0 ;
bool V_134 = false ;
bool V_135 = false ;
F_140 ( V_172 && ! V_173 ) ;
if ( F_34 ( V_13 ) )
return - V_62 ;
V_53 = ( T_1 ) V_164 << V_9 -> V_27 ;
ASSERT ( V_159 -> V_29 >= ( 1 << V_9 -> V_27 ) ) ;
V_54 = V_159 -> V_29 ;
if ( ! V_172 && V_53 >= F_117 ( V_9 ) )
return 0 ;
V_175 = F_141 ( V_11 ) ;
ASSERT ( V_53 <= V_13 -> V_84 -> V_85 ) ;
if ( V_53 + V_54 > V_13 -> V_84 -> V_85 )
V_54 = V_13 -> V_84 -> V_85 - V_53 ;
V_73 = F_41 ( V_13 , ( V_86 ) V_53 + V_54 ) ;
V_72 = F_42 ( V_13 , V_53 ) ;
if ( V_172 && V_173 && F_105 ( V_11 ) )
V_134 = F_100 ( V_11 , V_53 , & V_70 ,
& V_135 ) ;
if ( ! V_134 ) {
error = F_43 ( V_11 , V_72 , V_73 - V_72 ,
& V_70 , & V_76 , V_75 ) ;
if ( V_172 && V_173 && V_76 &&
V_70 . V_89 != V_91 &&
V_70 . V_89 != V_92 &&
! F_132 ( & V_70 ) )
F_44 ( V_11 , V_72 ,
& V_70 ) ;
}
ASSERT ( ! V_135 ) ;
if ( error )
goto V_176;
if ( V_172 &&
( ! V_76 ||
( V_70 . V_89 == V_91 ||
V_70 . V_89 == V_92 ) ||
( F_142 ( V_9 ) && F_132 ( & V_70 ) ) ) ) {
if ( V_175 == V_56 )
F_143 ( V_11 , V_175 ) ;
error = F_144 ( V_11 , V_53 , V_54 ,
& V_70 , V_76 ) ;
if ( error )
return error ;
V_114 = 1 ;
F_145 ( V_11 , V_53 , V_54 ,
F_132 ( & V_70 ) ? V_66
: V_88 , & V_70 ) ;
} else if ( V_76 ) {
F_146 ( V_11 , V_53 , V_54 ,
F_132 ( & V_70 ) ? V_66
: V_87 , & V_70 ) ;
F_21 ( V_11 , V_175 ) ;
} else {
F_147 ( V_11 , V_53 , V_54 ) ;
goto V_176;
}
if ( F_142 ( V_9 ) && V_172 ) {
ASSERT ( ! F_132 ( & V_70 ) ) ;
V_114 = 0 ;
}
F_134 ( V_9 , V_164 , V_159 , & V_70 , V_53 , V_54 ) ;
if ( V_70 . V_89 != V_91 &&
V_70 . V_89 != V_92 &&
( V_172 || ! F_132 ( & V_70 ) ) ) {
if ( V_172 && V_173 && ! V_134 ) {
error = F_136 ( V_11 , V_72 ,
& V_70 ) ;
if ( error )
return error ;
}
F_82 ( V_9 , V_159 , & V_70 , V_53 ) ;
if ( F_132 ( & V_70 ) )
F_148 ( V_159 ) ;
if ( V_172 ) {
if ( V_174 )
ASSERT ( ! F_132 ( & V_70 ) ) ;
else
F_130 ( V_9 , V_159 , & V_70 , V_53 ,
V_134 ) ;
}
}
V_159 -> V_109 = F_5 ( V_9 ) ;
if ( V_172 &&
( ( ! F_52 ( V_159 ) && ! F_103 ( V_159 ) ) ||
( V_53 >= F_117 ( V_9 ) ) ||
( V_114 || F_132 ( & V_70 ) ) ) )
F_149 ( V_159 ) ;
F_140 ( V_173 && V_70 . V_89 == V_92 ) ;
return 0 ;
V_176:
F_21 ( V_11 , V_175 ) ;
return error ;
}
int
F_150 (
struct V_9 * V_9 ,
T_7 V_164 ,
struct V_4 * V_159 ,
int V_172 )
{
return F_139 ( V_9 , V_164 , V_159 , V_172 , false , false ) ;
}
int
F_151 (
struct V_9 * V_9 ,
T_7 V_164 ,
struct V_4 * V_159 ,
int V_172 )
{
return F_139 ( V_9 , V_164 , V_159 , V_172 , true , false ) ;
}
int
F_152 (
struct V_9 * V_9 ,
T_7 V_164 ,
struct V_4 * V_159 ,
int V_172 )
{
return F_139 ( V_9 , V_164 , V_159 , V_172 , true , true ) ;
}
int
F_153 (
struct V_177 * V_178 ,
T_4 V_53 ,
T_5 V_54 ,
void * V_179 )
{
struct V_9 * V_9 = F_154 ( V_178 -> V_180 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_12 V_147 = ( T_12 ) V_179 ;
int error = 0 ;
F_155 ( V_11 , V_53 , V_54 ) ;
if ( F_34 ( V_11 -> V_14 ) )
return - V_62 ;
if ( V_54 <= 0 )
return V_54 ;
if ( V_147 == 0 ) {
ASSERT ( V_53 + V_54 <= F_117 ( V_9 ) ) ;
return 0 ;
}
F_156 ( & V_11 -> V_181 ) ;
if ( V_53 + V_54 > F_117 ( V_9 ) )
F_157 ( V_9 , V_53 + V_54 ) ;
F_158 ( & V_11 -> V_181 ) ;
if ( V_147 & V_162 )
error = F_36 ( V_11 , V_53 , V_54 ) ;
if ( V_147 & V_161 ) {
F_159 ( V_11 , V_53 , V_54 ) ;
error = F_37 ( V_11 , V_53 , V_54 ) ;
}
if ( V_147 & V_163 ) {
F_160 ( V_11 , V_53 , V_54 ) ;
error = F_27 ( V_11 , V_53 , V_54 ) ;
}
return error ;
}
STATIC T_5
F_161 (
struct V_177 * V_178 ,
struct V_182 * V_183 )
{
return - V_184 ;
}
STATIC T_7
F_162 (
struct V_156 * V_126 ,
T_7 V_185 )
{
struct V_9 * V_9 = (struct V_9 * ) V_126 -> V_128 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_163 ( F_6 ( V_9 ) ) ;
F_19 ( V_11 , V_186 ) ;
if ( F_105 ( V_11 ) ) {
F_21 ( V_11 , V_186 ) ;
return 0 ;
}
F_164 ( V_126 ) ;
F_21 ( V_11 , V_186 ) ;
return F_165 ( V_126 , V_185 , F_150 ) ;
}
STATIC int
F_166 (
struct V_187 * V_188 ,
struct V_1 * V_1 )
{
F_167 ( V_1 -> V_126 -> V_128 , 1 ) ;
return F_168 ( V_1 , F_150 ) ;
}
STATIC int
F_169 (
struct V_187 * V_188 ,
struct V_156 * V_126 ,
struct V_117 * V_189 ,
unsigned V_190 )
{
F_170 ( V_126 -> V_128 , V_190 ) ;
return F_171 ( V_126 , V_189 , V_190 , F_150 ) ;
}
STATIC int
F_172 (
struct V_1 * V_1 )
{
struct V_156 * V_126 = V_1 -> V_126 ;
struct V_9 * V_9 = V_126 -> V_128 ;
T_4 V_138 ;
T_4 V_53 ;
int V_191 ;
if ( F_173 ( ! V_126 ) )
return ! F_174 ( V_1 ) ;
V_138 = F_117 ( V_9 ) ;
V_53 = F_96 ( V_1 ) ;
F_156 ( & V_126 -> V_192 ) ;
if ( F_90 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_53 < V_138 )
F_175 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_53 += 1 << V_9 -> V_27 ;
} while ( V_5 != V_6 );
}
F_176 ( V_1 ) ;
V_191 = ! F_174 ( V_1 ) ;
F_158 ( & V_126 -> V_192 ) ;
if ( V_191 ) {
unsigned long V_147 ;
F_177 ( & V_126 -> V_193 , V_147 ) ;
if ( V_1 -> V_126 ) {
F_116 ( ! F_104 ( V_1 ) ) ;
F_178 ( V_1 , V_126 ) ;
F_179 ( & V_126 -> V_194 ,
F_180 ( V_1 ) , V_195 ) ;
}
F_181 ( & V_126 -> V_193 , V_147 ) ;
}
F_182 ( V_1 ) ;
if ( V_191 )
F_183 ( V_126 -> V_128 , V_196 ) ;
return V_191 ;
}
