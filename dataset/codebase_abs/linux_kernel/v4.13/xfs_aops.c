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
ASSERT ( ( V_19 -> V_21 & ( F_9 ( V_9 ) - 1 ) ) == 0 ) ;
ASSERT ( V_20 < V_26 ) ;
ASSERT ( ( V_19 -> V_22 & ( F_9 ( V_9 ) - 1 ) ) == 0 ) ;
V_5 = V_6 = F_2 ( V_19 -> V_27 ) ;
V_25 = V_5 -> V_28 ;
do {
if ( V_24 > V_20 )
break;
V_23 = V_5 -> V_7 ;
if ( V_24 < V_19 -> V_21 )
goto V_29;
V_5 -> V_30 ( V_5 , ! error ) ;
V_29:
V_24 += V_25 ;
} while ( ( V_5 = V_23 ) != V_6 );
}
STATIC void
F_10 (
struct V_31 * V_32 ,
int error )
{
struct V_9 * V_9 = V_32 -> V_33 ;
struct V_34 * V_35 = V_32 -> V_36 ;
struct V_34 * V_34 , * V_23 ;
for ( V_34 = & V_32 -> V_37 ; V_34 ; V_34 = V_23 ) {
struct V_18 * V_19 ;
int V_38 ;
if ( V_34 == V_35 )
V_23 = NULL ;
else
V_23 = V_34 -> V_39 ;
F_11 (bvec, bio, i)
F_8 ( V_9 , V_19 , error ) ;
F_12 ( V_34 ) ;
}
}
static inline bool F_13 ( struct V_31 * V_32 )
{
return V_32 -> V_40 + V_32 -> V_41 >
F_6 ( V_32 -> V_33 ) -> V_42 . V_43 ;
}
STATIC int
F_14 (
struct V_31 * V_32 )
{
struct V_12 * V_13 = F_6 ( V_32 -> V_33 ) -> V_14 ;
struct V_44 * V_45 ;
int error ;
error = F_15 ( V_13 , & F_16 ( V_13 ) -> V_46 , 0 , 0 , 0 , & V_45 ) ;
if ( error )
return error ;
V_32 -> V_47 = V_45 ;
F_17 ( V_32 -> V_33 -> V_48 , V_49 ) ;
F_18 ( & V_45 -> V_50 , V_51 ) ;
return 0 ;
}
STATIC int
F_19 (
struct V_10 * V_11 ,
struct V_44 * V_45 ,
T_1 V_52 ,
T_2 V_53 )
{
T_3 V_54 ;
F_20 ( V_11 , V_55 ) ;
V_54 = F_21 ( V_11 , V_52 + V_53 ) ;
if ( ! V_54 ) {
F_22 ( V_11 , V_55 ) ;
F_23 ( V_45 ) ;
return 0 ;
}
F_24 ( V_11 , V_52 , V_53 ) ;
V_11 -> V_42 . V_43 = V_54 ;
F_25 ( V_45 , V_11 , V_55 ) ;
F_26 ( V_45 , V_11 , V_56 ) ;
return F_27 ( V_45 ) ;
}
int
F_28 (
struct V_10 * V_11 ,
T_1 V_52 ,
T_2 V_53 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_44 * V_45 ;
int error ;
error = F_15 ( V_13 , & F_16 ( V_13 ) -> V_46 , 0 , 0 , 0 , & V_45 ) ;
if ( error )
return error ;
return F_19 ( V_11 , V_45 , V_52 , V_53 ) ;
}
STATIC int
F_29 (
struct V_31 * V_32 ,
int error )
{
struct V_10 * V_11 = F_6 ( V_32 -> V_33 ) ;
struct V_44 * V_45 = V_32 -> V_47 ;
F_30 ( & V_45 -> V_50 , V_51 ) ;
F_31 ( F_32 ( V_11 ) -> V_48 , V_49 ) ;
if ( error ) {
F_23 ( V_45 ) ;
return error ;
}
return F_19 ( V_11 , V_45 , V_32 -> V_40 , V_32 -> V_41 ) ;
}
STATIC void
F_33 (
struct V_57 * V_58 )
{
struct V_31 * V_32 =
F_34 ( V_58 , struct V_31 , V_59 ) ;
struct V_10 * V_11 = F_6 ( V_32 -> V_33 ) ;
T_1 V_52 = V_32 -> V_40 ;
T_2 V_53 = V_32 -> V_41 ;
int error ;
if ( F_35 ( V_11 -> V_14 ) ) {
error = - V_60 ;
goto V_61;
}
error = F_36 ( V_32 -> V_36 -> V_62 ) ;
if ( F_37 ( error ) ) {
switch ( V_32 -> V_63 ) {
case V_64 :
F_38 ( V_11 , V_52 , V_53 , true ) ;
break;
}
goto V_61;
}
switch ( V_32 -> V_63 ) {
case V_64 :
error = F_39 ( V_11 , V_52 , V_53 ) ;
break;
case V_65 :
error = F_40 ( V_11 , V_52 , V_53 ) ;
break;
default:
ASSERT ( ! F_13 ( V_32 ) || V_32 -> V_47 ) ;
break;
}
V_61:
if ( V_32 -> V_47 )
error = F_29 ( V_32 , error ) ;
F_10 ( V_32 , error ) ;
}
STATIC void
F_41 (
struct V_34 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_39 ;
struct V_12 * V_13 = F_6 ( V_32 -> V_33 ) -> V_14 ;
if ( V_32 -> V_63 == V_65 || V_32 -> V_63 == V_64 )
F_42 ( V_13 -> V_66 , & V_32 -> V_59 ) ;
else if ( V_32 -> V_47 )
F_42 ( V_13 -> V_67 , & V_32 -> V_59 ) ;
else
F_10 ( V_32 , F_36 ( V_34 -> V_62 ) ) ;
}
STATIC int
F_43 (
struct V_9 * V_9 ,
T_4 V_52 ,
struct V_68 * V_69 ,
int type )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_5 V_70 = F_9 ( V_9 ) ;
T_6 V_71 , V_72 ;
int error = 0 ;
int V_73 = V_74 ;
int V_75 = 1 ;
if ( F_35 ( V_13 ) )
return - V_60 ;
ASSERT ( type != V_64 ) ;
if ( type == V_65 )
V_73 |= V_76 ;
F_20 ( V_11 , V_77 ) ;
ASSERT ( V_11 -> V_42 . V_78 != V_79 ||
( V_11 -> V_80 . V_81 & V_82 ) ) ;
ASSERT ( V_52 <= V_13 -> V_83 -> V_84 ) ;
if ( V_52 + V_70 > V_13 -> V_83 -> V_84 )
V_70 = V_13 -> V_83 -> V_84 - V_52 ;
V_72 = F_44 ( V_13 , ( V_85 ) V_52 + V_70 ) ;
V_71 = F_45 ( V_13 , V_52 ) ;
error = F_46 ( V_11 , V_71 , V_72 - V_71 ,
V_69 , & V_75 , V_73 ) ;
if ( V_75 && type == V_86 )
F_47 ( V_11 , V_71 , V_69 ) ;
F_22 ( V_11 , V_77 ) ;
if ( error )
return error ;
if ( type == V_87 &&
( ! V_75 || F_48 ( V_69 -> V_88 ) ) ) {
error = F_49 ( V_11 , V_89 , V_52 ,
V_69 ) ;
if ( ! error )
F_50 ( V_11 , V_52 , V_70 , type , V_69 ) ;
return error ;
}
#ifdef F_51
if ( type == V_65 ) {
ASSERT ( V_75 ) ;
ASSERT ( V_69 -> V_88 != V_90 ) ;
ASSERT ( V_69 -> V_88 != V_91 ) ;
}
#endif
if ( V_75 )
F_52 ( V_11 , V_52 , V_70 , type , V_69 ) ;
return 0 ;
}
STATIC bool
F_53 (
struct V_9 * V_9 ,
struct V_68 * V_69 ,
T_1 V_52 )
{
V_52 >>= V_9 -> V_92 ;
return V_52 >= V_69 -> V_93 &&
V_52 < V_69 -> V_93 + V_69 -> V_94 ;
}
STATIC void
F_54 (
struct V_4 * V_5 )
{
ASSERT ( F_55 ( V_5 ) ) ;
ASSERT ( F_56 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_57 ( V_5 ) ;
F_58 ( V_5 ) ;
F_59 ( V_5 ) ;
}
STATIC void
F_60 (
struct V_1 * V_1 ,
int V_95 )
{
ASSERT ( F_61 ( V_1 ) ) ;
ASSERT ( ! F_62 ( V_1 ) ) ;
if ( V_95 ) {
F_63 ( V_1 ) ;
F_64 ( V_1 ) ;
} else
F_65 ( V_1 ) ;
F_66 ( V_1 ) ;
}
static inline int F_67 ( struct V_34 * V_34 , struct V_4 * V_5 )
{
return F_68 ( V_34 , V_5 -> V_96 , V_5 -> V_28 , F_69 ( V_5 ) ) ;
}
STATIC int
F_70 (
struct V_97 * V_98 ,
struct V_31 * V_32 ,
int V_99 )
{
if ( ! V_99 && V_32 -> V_63 == V_64 ) {
V_99 = F_71 ( F_6 ( V_32 -> V_33 ) ,
V_32 -> V_40 , V_32 -> V_41 ) ;
}
if ( ! V_99 &&
V_32 -> V_63 != V_65 &&
F_13 ( V_32 ) &&
! V_32 -> V_47 )
V_99 = F_14 ( V_32 ) ;
V_32 -> V_36 -> V_39 = V_32 ;
V_32 -> V_36 -> V_100 = F_41 ;
V_32 -> V_36 -> V_101 = V_102 | F_72 ( V_98 ) ;
if ( V_99 ) {
V_32 -> V_36 -> V_62 = F_73 ( V_99 ) ;
F_74 ( V_32 -> V_36 ) ;
return V_99 ;
}
V_32 -> V_36 -> V_103 = V_32 -> V_33 -> V_104 ;
F_75 ( V_32 -> V_36 ) ;
return 0 ;
}
static void
F_76 (
struct V_34 * V_34 ,
struct V_4 * V_5 )
{
V_34 -> V_105 . V_106 = V_5 -> V_107 * ( V_5 -> V_28 >> 9 ) ;
V_34 -> V_108 = V_5 -> V_109 ;
}
static struct V_31 *
F_77 (
struct V_9 * V_9 ,
unsigned int type ,
T_1 V_52 ,
struct V_4 * V_5 )
{
struct V_31 * V_32 ;
struct V_34 * V_34 ;
V_34 = F_78 ( V_110 , V_111 , V_112 ) ;
F_76 ( V_34 , V_5 ) ;
V_32 = F_34 ( V_34 , struct V_31 , V_37 ) ;
F_79 ( & V_32 -> V_113 ) ;
V_32 -> V_63 = type ;
V_32 -> V_33 = V_9 ;
V_32 -> V_41 = 0 ;
V_32 -> V_40 = V_52 ;
F_80 ( & V_32 -> V_59 , F_33 ) ;
V_32 -> V_47 = NULL ;
V_32 -> V_36 = V_34 ;
return V_32 ;
}
static void
F_81 (
struct V_31 * V_32 ,
struct V_97 * V_98 ,
struct V_4 * V_5 )
{
struct V_34 * V_114 ;
V_114 = F_82 ( V_110 , V_111 ) ;
F_76 ( V_114 , V_5 ) ;
F_83 ( V_32 -> V_36 , V_114 ) ;
F_84 ( V_32 -> V_36 ) ;
V_32 -> V_36 -> V_101 = V_102 | F_72 ( V_98 ) ;
V_32 -> V_36 -> V_103 = V_32 -> V_33 -> V_104 ;
F_75 ( V_32 -> V_36 ) ;
V_32 -> V_36 = V_114 ;
}
STATIC void
F_85 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_1 V_52 ,
struct V_115 * V_116 ,
struct V_97 * V_98 ,
struct V_117 * V_118 )
{
if ( ! V_116 -> V_32 || V_116 -> V_63 != V_116 -> V_32 -> V_63 ||
V_5 -> V_107 != V_116 -> V_119 + 1 ||
V_52 != V_116 -> V_32 -> V_40 + V_116 -> V_32 -> V_41 ) {
if ( V_116 -> V_32 )
F_86 ( & V_116 -> V_32 -> V_113 , V_118 ) ;
V_116 -> V_32 = F_77 ( V_9 , V_116 -> V_63 , V_52 , V_5 ) ;
}
while ( F_67 ( V_116 -> V_32 -> V_36 , V_5 ) != V_5 -> V_28 )
F_81 ( V_116 -> V_32 , V_98 , V_5 ) ;
V_116 -> V_32 -> V_41 += V_5 -> V_28 ;
V_116 -> V_119 = V_5 -> V_107 ;
F_54 ( V_5 ) ;
}
STATIC void
F_87 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_68 * V_69 ,
T_1 V_52 )
{
T_7 V_120 ;
struct V_12 * V_121 = F_6 ( V_9 ) -> V_14 ;
T_1 V_122 = F_88 ( V_121 , V_69 -> V_93 ) ;
T_8 V_123 = F_89 ( F_6 ( V_9 ) , V_69 -> V_88 ) ;
ASSERT ( V_69 -> V_88 != V_90 ) ;
ASSERT ( V_69 -> V_88 != V_91 ) ;
V_120 = ( V_123 >> ( V_9 -> V_92 - V_124 ) ) +
( ( V_52 - V_122 ) >> V_9 -> V_92 ) ;
ASSERT ( V_120 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_107 = V_120 ;
F_90 ( V_5 ) ;
}
STATIC void
F_91 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_68 * V_69 ,
T_1 V_52 )
{
ASSERT ( V_69 -> V_88 != V_90 ) ;
ASSERT ( V_69 -> V_88 != V_91 ) ;
F_87 ( V_9 , V_5 , V_69 , V_52 ) ;
F_90 ( V_5 ) ;
F_92 ( V_5 ) ;
F_93 ( V_5 ) ;
}
STATIC bool
F_94 (
struct V_1 * V_1 ,
unsigned int type ,
bool V_125 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
if ( F_62 ( V_1 ) )
return false ;
if ( ! V_1 -> V_126 )
return false ;
if ( ! F_95 ( V_1 ) )
return false ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) ) {
if ( type == V_65 )
return true ;
} else if ( F_4 ( V_5 ) ) {
if ( type == V_87 )
return true ;
} else if ( F_96 ( V_5 ) && F_55 ( V_5 ) ) {
if ( type == V_86 )
return true ;
}
if ( ! V_125 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC void
F_97 (
struct V_1 * V_1 ,
unsigned int V_52 ,
unsigned int V_127 )
{
F_98 ( V_1 -> V_126 -> V_128 , V_1 , V_52 ,
V_127 ) ;
F_99 ( V_1 , V_52 , V_127 ) ;
}
STATIC void
F_100 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_126 -> V_128 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_4 V_52 = F_101 ( V_1 ) ;
if ( ! F_94 ( V_1 , V_87 , true ) )
goto V_129;
if ( F_35 ( V_11 -> V_14 ) )
goto V_129;
F_102 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_130 , V_52 ) ;
F_20 ( V_11 , V_55 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_6 V_131 ;
if ( ! F_4 ( V_5 ) )
goto V_132;
V_131 = F_45 ( V_11 -> V_14 , V_52 ) ;
error = F_103 ( V_11 , V_131 , 1 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_102 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_132:
V_52 += F_9 ( V_9 ) ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_22 ( V_11 , V_55 ) ;
V_129:
F_97 ( V_1 , 0 , V_26 ) ;
return;
}
static int
F_104 (
struct V_115 * V_116 ,
struct V_9 * V_9 ,
T_4 V_52 ,
unsigned int * V_133 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_68 V_69 ;
bool V_134 = false ;
int error ;
if ( V_116 -> V_63 == V_64 ) {
V_116 -> V_135 = F_53 ( V_9 , & V_116 -> V_69 , V_52 ) ;
if ( V_116 -> V_135 ) {
* V_133 = V_64 ;
return 0 ;
}
}
F_20 ( V_11 , V_77 ) ;
V_134 = F_105 ( V_11 , V_52 , & V_69 ) ;
F_22 ( V_11 , V_77 ) ;
if ( ! V_134 )
return 0 ;
if ( F_48 ( V_69 . V_88 ) ) {
error = F_49 ( V_11 , V_136 , V_52 ,
& V_69 ) ;
if ( error )
return error ;
}
V_116 -> V_63 = * V_133 = V_64 ;
V_116 -> V_135 = true ;
V_116 -> V_69 = V_69 ;
return 0 ;
}
static int
F_106 (
struct V_115 * V_116 ,
struct V_97 * V_98 ,
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_4 V_52 ,
T_9 V_137 )
{
F_107 ( V_138 ) ;
struct V_31 * V_32 , * V_23 ;
struct V_4 * V_5 , * V_6 ;
T_5 V_139 = F_9 ( V_9 ) ;
int error = 0 ;
int V_70 = 0 ;
int V_140 = 1 ;
unsigned int V_133 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_52 = F_101 ( V_1 ) ;
do {
if ( V_52 >= V_137 )
break;
if ( ! F_108 ( V_5 ) )
V_140 = 0 ;
if ( ! F_55 ( V_5 ) && F_108 ( V_5 ) ) {
V_116 -> V_135 = false ;
continue;
}
if ( F_3 ( V_5 ) )
V_133 = V_65 ;
else if ( F_4 ( V_5 ) )
V_133 = V_87 ;
else if ( F_108 ( V_5 ) )
V_133 = V_86 ;
else {
if ( F_109 ( V_1 ) )
ASSERT ( F_55 ( V_5 ) ) ;
V_116 -> V_135 = false ;
continue;
}
if ( F_110 ( F_6 ( V_9 ) ) ) {
error = F_104 ( V_116 , V_9 , V_52 , & V_133 ) ;
if ( error )
goto V_141;
}
if ( V_116 -> V_63 != V_133 ) {
V_116 -> V_63 = V_133 ;
V_116 -> V_135 = false ;
}
if ( V_116 -> V_135 )
V_116 -> V_135 = F_53 ( V_9 , & V_116 -> V_69 ,
V_52 ) ;
if ( ! V_116 -> V_135 ) {
error = F_43 ( V_9 , V_52 , & V_116 -> V_69 ,
V_116 -> V_63 ) ;
if ( error )
goto V_141;
V_116 -> V_135 = F_53 ( V_9 , & V_116 -> V_69 ,
V_52 ) ;
}
if ( V_116 -> V_135 ) {
F_111 ( V_5 ) ;
if ( V_116 -> V_63 != V_86 )
F_91 ( V_9 , V_5 , & V_116 -> V_69 , V_52 ) ;
F_85 ( V_9 , V_5 , V_52 , V_116 , V_98 , & V_138 ) ;
V_70 ++ ;
}
} while ( V_52 += V_139 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_140 && V_5 == V_6 )
F_112 ( V_1 ) ;
ASSERT ( V_116 -> V_32 || F_113 ( & V_138 ) ) ;
V_141:
if ( V_70 ) {
F_60 ( V_1 , ! error ) ;
F_114 (ioend, next, &submit_list, io_list) {
int V_142 ;
F_115 ( & V_32 -> V_113 ) ;
V_142 = F_70 ( V_98 , V_32 , error ) ;
if ( V_142 && ! error )
error = V_142 ;
}
} else if ( error ) {
F_100 ( V_1 ) ;
F_116 ( V_1 ) ;
F_66 ( V_1 ) ;
} else {
F_60 ( V_1 , 1 ) ;
F_117 ( V_1 ) ;
}
F_118 ( V_1 -> V_126 , error ) ;
return error ;
}
STATIC int
F_119 (
struct V_1 * V_1 ,
struct V_97 * V_98 ,
void * V_143 )
{
struct V_115 * V_116 = V_143 ;
struct V_9 * V_9 = V_1 -> V_126 -> V_128 ;
T_4 V_52 ;
T_9 V_137 ;
T_10 V_144 ;
F_120 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_95 ( V_1 ) ) ;
if ( F_121 ( ( V_145 -> V_146 & ( V_147 | V_148 ) ) ==
V_147 ) )
goto V_149;
if ( F_121 ( V_145 -> V_146 & V_51 ) )
goto V_149;
V_52 = F_122 ( V_9 ) ;
V_144 = V_52 >> V_150 ;
if ( V_1 -> V_151 < V_144 )
V_137 = ( T_1 ) ( V_1 -> V_151 + 1 ) << V_150 ;
else {
unsigned V_152 = V_52 & ( V_26 - 1 ) ;
if ( V_1 -> V_151 > V_144 ||
( V_1 -> V_151 == V_144 && V_152 == 0 ) )
goto V_149;
F_123 ( V_1 , V_152 , V_26 ) ;
V_137 = V_52 ;
}
return F_106 ( V_116 , V_98 , V_9 , V_1 , V_52 , V_137 ) ;
V_149:
F_124 ( V_98 , V_1 ) ;
F_66 ( V_1 ) ;
return 0 ;
}
STATIC int
F_125 (
struct V_1 * V_1 ,
struct V_97 * V_98 )
{
struct V_115 V_116 = {
. V_63 = V_153 ,
} ;
int V_154 ;
V_154 = F_119 ( V_1 , V_98 , & V_116 ) ;
if ( V_116 . V_32 )
V_154 = F_70 ( V_98 , V_116 . V_32 , V_154 ) ;
return V_154 ;
}
STATIC int
F_126 (
struct V_155 * V_126 ,
struct V_97 * V_98 )
{
struct V_115 V_116 = {
. V_63 = V_153 ,
} ;
int V_154 ;
F_127 ( F_6 ( V_126 -> V_128 ) , V_156 ) ;
if ( F_128 ( V_126 ) )
return F_129 ( V_126 ,
F_5 ( V_126 -> V_128 ) , V_98 ) ;
V_154 = F_130 ( V_126 , V_98 , F_119 , & V_116 ) ;
if ( V_116 . V_32 )
V_154 = F_70 ( V_98 , V_116 . V_32 , V_154 ) ;
return V_154 ;
}
STATIC int
F_131 (
struct V_1 * V_1 ,
T_11 V_157 )
{
int V_2 , V_3 ;
F_132 ( V_1 -> V_126 -> V_128 , V_1 , 0 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( V_2 ) {
F_121 ( ! F_133 ( V_1 ) ) ;
return 0 ;
}
if ( V_3 ) {
F_121 ( ! F_133 ( V_1 ) ) ;
return 0 ;
}
return F_134 ( V_1 ) ;
}
static void
F_135 (
struct V_9 * V_9 ,
T_7 V_158 ,
struct V_4 * V_159 ,
struct V_68 * V_69 ,
T_1 V_52 ,
T_5 V_53 )
{
T_1 V_160 ;
V_160 = V_69 -> V_93 + V_69 -> V_94 - V_158 ;
V_160 <<= V_9 -> V_92 ;
ASSERT ( V_160 > 0 ) ;
if ( V_160 > V_53 )
V_160 = V_53 ;
if ( V_52 < F_122 ( V_9 ) &&
V_52 + V_160 >= F_122 ( V_9 ) ) {
V_160 = F_136 ( F_122 ( V_9 ) - V_52 ,
F_9 ( V_9 ) ) ;
}
if ( V_160 > V_161 )
V_160 = V_161 ;
V_159 -> V_28 = V_160 ;
}
static int
F_137 (
struct V_9 * V_9 ,
T_7 V_158 ,
struct V_4 * V_159 ,
int V_162 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_71 , V_72 ;
int error = 0 ;
int V_163 = 0 ;
struct V_68 V_69 ;
int V_75 = 1 ;
T_1 V_52 ;
T_5 V_53 ;
F_138 ( V_162 ) ;
if ( F_35 ( V_13 ) )
return - V_60 ;
V_52 = ( T_1 ) V_158 << V_9 -> V_92 ;
ASSERT ( V_159 -> V_28 >= F_9 ( V_9 ) ) ;
V_53 = V_159 -> V_28 ;
if ( V_52 >= F_122 ( V_9 ) )
return 0 ;
V_163 = F_139 ( V_11 ) ;
ASSERT ( V_52 <= V_13 -> V_83 -> V_84 ) ;
if ( V_52 + V_53 > V_13 -> V_83 -> V_84 )
V_53 = V_13 -> V_83 -> V_84 - V_52 ;
V_72 = F_44 ( V_13 , ( V_85 ) V_52 + V_53 ) ;
V_71 = F_45 ( V_13 , V_52 ) ;
error = F_46 ( V_11 , V_71 , V_72 - V_71 ,
& V_69 , & V_75 , V_74 ) ;
if ( error )
goto V_164;
if ( V_75 ) {
F_140 ( V_11 , V_52 , V_53 ,
V_69 . V_165 == V_166 ?
V_65 : V_86 , & V_69 ) ;
F_22 ( V_11 , V_163 ) ;
} else {
F_141 ( V_11 , V_52 , V_53 ) ;
goto V_164;
}
F_135 ( V_9 , V_158 , V_159 , & V_69 , V_52 , V_53 ) ;
if ( F_142 ( & V_69 ) )
F_87 ( V_9 , V_159 , & V_69 , V_52 ) ;
V_159 -> V_109 = F_5 ( V_9 ) ;
return 0 ;
V_164:
F_22 ( V_11 , V_163 ) ;
return error ;
}
STATIC T_5
F_143 (
struct V_167 * V_168 ,
struct V_169 * V_170 )
{
return - V_171 ;
}
STATIC T_7
F_144 (
struct V_155 * V_126 ,
T_7 V_172 )
{
struct V_9 * V_9 = (struct V_9 * ) V_126 -> V_128 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_145 ( F_6 ( V_9 ) ) ;
if ( F_110 ( V_11 ) || F_7 ( V_11 ) )
return 0 ;
F_146 ( V_126 ) ;
return F_147 ( V_126 , V_172 , F_137 ) ;
}
STATIC int
F_148 (
struct V_173 * V_174 ,
struct V_1 * V_1 )
{
F_149 ( V_1 -> V_126 -> V_128 , 1 ) ;
return F_150 ( V_1 , F_137 ) ;
}
STATIC int
F_151 (
struct V_173 * V_174 ,
struct V_155 * V_126 ,
struct V_117 * V_175 ,
unsigned V_176 )
{
F_152 ( V_126 -> V_128 , V_176 ) ;
return F_153 ( V_126 , V_175 , V_176 , F_137 ) ;
}
STATIC int
F_154 (
struct V_1 * V_1 )
{
struct V_155 * V_126 = V_1 -> V_126 ;
struct V_9 * V_9 = V_126 -> V_128 ;
T_4 V_137 ;
T_4 V_52 ;
int V_177 ;
if ( F_37 ( ! V_126 ) )
return ! F_155 ( V_1 ) ;
V_137 = F_122 ( V_9 ) ;
V_52 = F_101 ( V_1 ) ;
F_156 ( & V_126 -> V_178 ) ;
if ( F_95 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_52 < V_137 )
F_157 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_52 += F_9 ( V_9 ) ;
} while ( V_5 != V_6 );
}
F_158 ( V_1 ) ;
V_177 = ! F_155 ( V_1 ) ;
F_159 ( & V_126 -> V_178 ) ;
if ( V_177 ) {
unsigned long V_146 ;
F_160 ( & V_126 -> V_179 , V_146 ) ;
if ( V_1 -> V_126 ) {
F_121 ( ! F_109 ( V_1 ) ) ;
F_161 ( V_1 , V_126 ) ;
F_162 ( & V_126 -> V_180 ,
F_163 ( V_1 ) , V_181 ) ;
}
F_164 ( & V_126 -> V_179 , V_146 ) ;
}
F_165 ( V_1 ) ;
if ( V_177 )
F_166 ( V_126 -> V_128 , V_182 ) ;
return V_177 ;
}
