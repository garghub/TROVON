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
V_23 = V_5 -> V_7 ;
if ( V_24 < V_19 -> V_21 )
goto V_29;
if ( V_24 > V_20 )
break;
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
int error = V_32 -> V_36 -> V_60 ;
if ( F_35 ( V_11 -> V_14 ) ) {
error = - V_61 ;
goto V_62;
}
if ( F_36 ( error ) ) {
switch ( V_32 -> V_63 ) {
case V_64 :
F_37 ( V_11 , V_52 , V_53 , true ) ;
break;
}
goto V_62;
}
switch ( V_32 -> V_63 ) {
case V_64 :
error = F_38 ( V_11 , V_52 , V_53 ) ;
break;
case V_65 :
error = F_39 ( V_11 , V_52 , V_53 ) ;
break;
default:
ASSERT ( ! F_13 ( V_32 ) || V_32 -> V_47 ) ;
break;
}
V_62:
if ( V_32 -> V_47 )
error = F_29 ( V_32 , error ) ;
F_10 ( V_32 , error ) ;
}
STATIC void
F_40 (
struct V_34 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_39 ;
struct V_12 * V_13 = F_6 ( V_32 -> V_33 ) -> V_14 ;
if ( V_32 -> V_63 == V_65 || V_32 -> V_63 == V_64 )
F_41 ( V_13 -> V_66 , & V_32 -> V_59 ) ;
else if ( V_32 -> V_47 )
F_41 ( V_13 -> V_67 , & V_32 -> V_59 ) ;
else
F_10 ( V_32 , V_34 -> V_60 ) ;
}
STATIC int
F_42 (
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
return - V_61 ;
ASSERT ( type != V_64 ) ;
if ( type == V_65 )
V_73 |= V_76 ;
F_20 ( V_11 , V_77 ) ;
ASSERT ( V_11 -> V_42 . V_78 != V_79 ||
( V_11 -> V_80 . V_81 & V_82 ) ) ;
ASSERT ( V_52 <= V_13 -> V_83 -> V_84 ) ;
if ( V_52 + V_70 > V_13 -> V_83 -> V_84 )
V_70 = V_13 -> V_83 -> V_84 - V_52 ;
V_72 = F_43 ( V_13 , ( V_85 ) V_52 + V_70 ) ;
V_71 = F_44 ( V_13 , V_52 ) ;
error = F_45 ( V_11 , V_71 , V_72 - V_71 ,
V_69 , & V_75 , V_73 ) ;
if ( V_75 && type == V_86 )
F_46 ( V_11 , V_71 , V_69 ) ;
F_22 ( V_11 , V_77 ) ;
if ( error )
return error ;
if ( type == V_87 &&
( ! V_75 || F_47 ( V_69 -> V_88 ) ) ) {
error = F_48 ( V_11 , V_89 , V_52 ,
V_69 ) ;
if ( ! error )
F_49 ( V_11 , V_52 , V_70 , type , V_69 ) ;
return error ;
}
#ifdef F_50
if ( type == V_65 ) {
ASSERT ( V_75 ) ;
ASSERT ( V_69 -> V_88 != V_90 ) ;
ASSERT ( V_69 -> V_88 != V_91 ) ;
}
#endif
if ( V_75 )
F_51 ( V_11 , V_52 , V_70 , type , V_69 ) ;
return 0 ;
}
STATIC bool
F_52 (
struct V_9 * V_9 ,
struct V_68 * V_69 ,
T_1 V_52 )
{
V_52 >>= V_9 -> V_92 ;
return V_52 >= V_69 -> V_93 &&
V_52 < V_69 -> V_93 + V_69 -> V_94 ;
}
STATIC void
F_53 (
struct V_4 * V_5 )
{
ASSERT ( F_54 ( V_5 ) ) ;
ASSERT ( F_55 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_56 ( V_5 ) ;
F_57 ( V_5 ) ;
F_58 ( V_5 ) ;
}
STATIC void
F_59 (
struct V_1 * V_1 ,
int V_95 )
{
ASSERT ( F_60 ( V_1 ) ) ;
ASSERT ( ! F_61 ( V_1 ) ) ;
if ( V_95 ) {
F_62 ( V_1 ) ;
F_63 ( V_1 ) ;
} else
F_64 ( V_1 ) ;
F_65 ( V_1 ) ;
}
static inline int F_66 ( struct V_34 * V_34 , struct V_4 * V_5 )
{
return F_67 ( V_34 , V_5 -> V_96 , V_5 -> V_28 , F_68 ( V_5 ) ) ;
}
STATIC int
F_69 (
struct V_97 * V_98 ,
struct V_31 * V_32 ,
int V_99 )
{
if ( ! V_99 && V_32 -> V_63 == V_64 ) {
V_99 = F_70 ( F_6 ( V_32 -> V_33 ) ,
V_32 -> V_40 , V_32 -> V_41 ) ;
}
if ( ! V_99 &&
V_32 -> V_63 != V_65 &&
F_13 ( V_32 ) &&
! V_32 -> V_47 )
V_99 = F_14 ( V_32 ) ;
V_32 -> V_36 -> V_39 = V_32 ;
V_32 -> V_36 -> V_100 = F_40 ;
V_32 -> V_36 -> V_101 = V_102 | F_71 ( V_98 ) ;
if ( V_99 ) {
V_32 -> V_36 -> V_60 = V_99 ;
F_72 ( V_32 -> V_36 ) ;
return V_99 ;
}
F_73 ( V_32 -> V_36 ) ;
return 0 ;
}
static void
F_74 (
struct V_34 * V_34 ,
struct V_4 * V_5 )
{
V_34 -> V_103 . V_104 = V_5 -> V_105 * ( V_5 -> V_28 >> 9 ) ;
V_34 -> V_106 = V_5 -> V_107 ;
}
static struct V_31 *
F_75 (
struct V_9 * V_9 ,
unsigned int type ,
T_1 V_52 ,
struct V_4 * V_5 )
{
struct V_31 * V_32 ;
struct V_34 * V_34 ;
V_34 = F_76 ( V_108 , V_109 , V_110 ) ;
F_74 ( V_34 , V_5 ) ;
V_32 = F_34 ( V_34 , struct V_31 , V_37 ) ;
F_77 ( & V_32 -> V_111 ) ;
V_32 -> V_63 = type ;
V_32 -> V_33 = V_9 ;
V_32 -> V_41 = 0 ;
V_32 -> V_40 = V_52 ;
F_78 ( & V_32 -> V_59 , F_33 ) ;
V_32 -> V_47 = NULL ;
V_32 -> V_36 = V_34 ;
return V_32 ;
}
static void
F_79 (
struct V_31 * V_32 ,
struct V_97 * V_98 ,
struct V_4 * V_5 )
{
struct V_34 * V_112 ;
V_112 = F_80 ( V_108 , V_109 ) ;
F_74 ( V_112 , V_5 ) ;
F_81 ( V_32 -> V_36 , V_112 ) ;
F_82 ( V_32 -> V_36 ) ;
V_32 -> V_36 -> V_101 = V_102 | F_71 ( V_98 ) ;
F_73 ( V_32 -> V_36 ) ;
V_32 -> V_36 = V_112 ;
}
STATIC void
F_83 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_1 V_52 ,
struct V_113 * V_114 ,
struct V_97 * V_98 ,
struct V_115 * V_116 )
{
if ( ! V_114 -> V_32 || V_114 -> V_63 != V_114 -> V_32 -> V_63 ||
V_5 -> V_105 != V_114 -> V_117 + 1 ||
V_52 != V_114 -> V_32 -> V_40 + V_114 -> V_32 -> V_41 ) {
if ( V_114 -> V_32 )
F_84 ( & V_114 -> V_32 -> V_111 , V_116 ) ;
V_114 -> V_32 = F_75 ( V_9 , V_114 -> V_63 , V_52 , V_5 ) ;
}
while ( F_66 ( V_114 -> V_32 -> V_36 , V_5 ) != V_5 -> V_28 )
F_79 ( V_114 -> V_32 , V_98 , V_5 ) ;
V_114 -> V_32 -> V_41 += V_5 -> V_28 ;
V_114 -> V_117 = V_5 -> V_105 ;
F_53 ( V_5 ) ;
}
STATIC void
F_85 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_68 * V_69 ,
T_1 V_52 )
{
T_7 V_118 ;
struct V_12 * V_119 = F_6 ( V_9 ) -> V_14 ;
T_1 V_120 = F_86 ( V_119 , V_69 -> V_93 ) ;
T_8 V_121 = F_87 ( F_6 ( V_9 ) , V_69 -> V_88 ) ;
ASSERT ( V_69 -> V_88 != V_90 ) ;
ASSERT ( V_69 -> V_88 != V_91 ) ;
V_118 = ( V_121 >> ( V_9 -> V_92 - V_122 ) ) +
( ( V_52 - V_120 ) >> V_9 -> V_92 ) ;
ASSERT ( V_118 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_105 = V_118 ;
F_88 ( V_5 ) ;
}
STATIC void
F_89 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_68 * V_69 ,
T_1 V_52 )
{
ASSERT ( V_69 -> V_88 != V_90 ) ;
ASSERT ( V_69 -> V_88 != V_91 ) ;
F_85 ( V_9 , V_5 , V_69 , V_52 ) ;
F_88 ( V_5 ) ;
F_90 ( V_5 ) ;
F_91 ( V_5 ) ;
}
STATIC bool
F_92 (
struct V_1 * V_1 ,
unsigned int type ,
bool V_123 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
if ( F_61 ( V_1 ) )
return false ;
if ( ! V_1 -> V_124 )
return false ;
if ( ! F_93 ( V_1 ) )
return false ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) ) {
if ( type == V_65 )
return true ;
} else if ( F_4 ( V_5 ) ) {
if ( type == V_87 )
return true ;
} else if ( F_94 ( V_5 ) && F_54 ( V_5 ) ) {
if ( type == V_86 )
return true ;
}
if ( ! V_123 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC void
F_95 (
struct V_1 * V_1 ,
unsigned int V_52 ,
unsigned int V_125 )
{
F_96 ( V_1 -> V_124 -> V_126 , V_1 , V_52 ,
V_125 ) ;
F_97 ( V_1 , V_52 , V_125 ) ;
}
STATIC void
F_98 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_124 -> V_126 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_4 V_52 = F_99 ( V_1 ) ;
if ( ! F_92 ( V_1 , V_87 , true ) )
goto V_127;
if ( F_35 ( V_11 -> V_14 ) )
goto V_127;
F_100 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_128 , V_52 ) ;
F_20 ( V_11 , V_55 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_6 V_129 ;
if ( ! F_4 ( V_5 ) )
goto V_130;
V_129 = F_44 ( V_11 -> V_14 , V_52 ) ;
error = F_101 ( V_11 , V_129 , 1 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_100 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_130:
V_52 += F_9 ( V_9 ) ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_22 ( V_11 , V_55 ) ;
V_127:
F_95 ( V_1 , 0 , V_26 ) ;
return;
}
static int
F_102 (
struct V_113 * V_114 ,
struct V_9 * V_9 ,
T_4 V_52 ,
unsigned int * V_131 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_68 V_69 ;
bool V_132 = false ;
int error ;
if ( V_114 -> V_63 == V_64 ) {
V_114 -> V_133 = F_52 ( V_9 , & V_114 -> V_69 , V_52 ) ;
if ( V_114 -> V_133 ) {
* V_131 = V_64 ;
return 0 ;
}
}
F_20 ( V_11 , V_77 ) ;
V_132 = F_103 ( V_11 , V_52 , & V_69 ) ;
F_22 ( V_11 , V_77 ) ;
if ( ! V_132 )
return 0 ;
if ( F_47 ( V_69 . V_88 ) ) {
error = F_48 ( V_11 , V_134 , V_52 ,
& V_69 ) ;
if ( error )
return error ;
}
V_114 -> V_63 = * V_131 = V_64 ;
V_114 -> V_133 = true ;
V_114 -> V_69 = V_69 ;
return 0 ;
}
static int
F_104 (
struct V_113 * V_114 ,
struct V_97 * V_98 ,
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_4 V_52 ,
T_9 V_135 )
{
F_105 ( V_136 ) ;
struct V_31 * V_32 , * V_23 ;
struct V_4 * V_5 , * V_6 ;
T_5 V_137 = F_9 ( V_9 ) ;
int error = 0 ;
int V_70 = 0 ;
int V_138 = 1 ;
unsigned int V_131 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_52 = F_99 ( V_1 ) ;
do {
if ( V_52 >= V_135 )
break;
if ( ! F_106 ( V_5 ) )
V_138 = 0 ;
if ( ! F_54 ( V_5 ) && F_106 ( V_5 ) ) {
V_114 -> V_133 = false ;
continue;
}
if ( F_3 ( V_5 ) )
V_131 = V_65 ;
else if ( F_4 ( V_5 ) )
V_131 = V_87 ;
else if ( F_106 ( V_5 ) )
V_131 = V_86 ;
else {
if ( F_107 ( V_1 ) )
ASSERT ( F_54 ( V_5 ) ) ;
V_114 -> V_133 = false ;
continue;
}
if ( F_108 ( F_6 ( V_9 ) ) ) {
error = F_102 ( V_114 , V_9 , V_52 , & V_131 ) ;
if ( error )
goto V_139;
}
if ( V_114 -> V_63 != V_131 ) {
V_114 -> V_63 = V_131 ;
V_114 -> V_133 = false ;
}
if ( V_114 -> V_133 )
V_114 -> V_133 = F_52 ( V_9 , & V_114 -> V_69 ,
V_52 ) ;
if ( ! V_114 -> V_133 ) {
error = F_42 ( V_9 , V_52 , & V_114 -> V_69 ,
V_114 -> V_63 ) ;
if ( error )
goto V_139;
V_114 -> V_133 = F_52 ( V_9 , & V_114 -> V_69 ,
V_52 ) ;
}
if ( V_114 -> V_133 ) {
F_109 ( V_5 ) ;
if ( V_114 -> V_63 != V_86 )
F_89 ( V_9 , V_5 , & V_114 -> V_69 , V_52 ) ;
F_83 ( V_9 , V_5 , V_52 , V_114 , V_98 , & V_136 ) ;
V_70 ++ ;
}
} while ( V_52 += V_137 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_138 && V_5 == V_6 )
F_110 ( V_1 ) ;
ASSERT ( V_114 -> V_32 || F_111 ( & V_136 ) ) ;
V_139:
if ( V_70 ) {
F_59 ( V_1 , ! error ) ;
F_112 (ioend, next, &submit_list, io_list) {
int V_140 ;
F_113 ( & V_32 -> V_111 ) ;
V_140 = F_69 ( V_98 , V_32 , error ) ;
if ( V_140 && ! error )
error = V_140 ;
}
} else if ( error ) {
F_98 ( V_1 ) ;
F_114 ( V_1 ) ;
F_65 ( V_1 ) ;
} else {
F_59 ( V_1 , 1 ) ;
F_115 ( V_1 ) ;
}
F_116 ( V_1 -> V_124 , error ) ;
return error ;
}
STATIC int
F_117 (
struct V_1 * V_1 ,
struct V_97 * V_98 ,
void * V_141 )
{
struct V_113 * V_114 = V_141 ;
struct V_9 * V_9 = V_1 -> V_124 -> V_126 ;
T_4 V_52 ;
T_9 V_135 ;
T_10 V_142 ;
F_118 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_93 ( V_1 ) ) ;
if ( F_119 ( ( V_143 -> V_144 & ( V_145 | V_146 ) ) ==
V_145 ) )
goto V_147;
if ( F_119 ( V_143 -> V_144 & V_51 ) )
goto V_147;
V_52 = F_120 ( V_9 ) ;
V_142 = V_52 >> V_148 ;
if ( V_1 -> V_149 < V_142 )
V_135 = ( T_1 ) ( V_1 -> V_149 + 1 ) << V_148 ;
else {
unsigned V_150 = V_52 & ( V_26 - 1 ) ;
if ( V_1 -> V_149 > V_142 ||
( V_1 -> V_149 == V_142 && V_150 == 0 ) )
goto V_147;
F_121 ( V_1 , V_150 , V_26 ) ;
V_135 = V_52 ;
}
return F_104 ( V_114 , V_98 , V_9 , V_1 , V_52 , V_135 ) ;
V_147:
F_122 ( V_98 , V_1 ) ;
F_65 ( V_1 ) ;
return 0 ;
}
STATIC int
F_123 (
struct V_1 * V_1 ,
struct V_97 * V_98 )
{
struct V_113 V_114 = {
. V_63 = V_151 ,
} ;
int V_152 ;
V_152 = F_117 ( V_1 , V_98 , & V_114 ) ;
if ( V_114 . V_32 )
V_152 = F_69 ( V_98 , V_114 . V_32 , V_152 ) ;
return V_152 ;
}
STATIC int
F_124 (
struct V_153 * V_124 ,
struct V_97 * V_98 )
{
struct V_113 V_114 = {
. V_63 = V_151 ,
} ;
int V_152 ;
F_125 ( F_6 ( V_124 -> V_126 ) , V_154 ) ;
if ( F_126 ( V_124 ) )
return F_127 ( V_124 ,
F_5 ( V_124 -> V_126 ) , V_98 ) ;
V_152 = F_128 ( V_124 , V_98 , F_117 , & V_114 ) ;
if ( V_114 . V_32 )
V_152 = F_69 ( V_98 , V_114 . V_32 , V_152 ) ;
return V_152 ;
}
STATIC int
F_129 (
struct V_1 * V_1 ,
T_11 V_155 )
{
int V_2 , V_3 ;
F_130 ( V_1 -> V_124 -> V_126 , V_1 , 0 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( V_2 ) {
F_119 ( ! F_131 ( V_1 ) ) ;
return 0 ;
}
if ( V_3 ) {
F_119 ( ! F_131 ( V_1 ) ) ;
return 0 ;
}
return F_132 ( V_1 ) ;
}
static void
F_133 (
struct V_9 * V_9 ,
T_7 V_156 ,
struct V_4 * V_157 ,
struct V_68 * V_69 ,
T_1 V_52 ,
T_5 V_53 )
{
T_1 V_158 ;
V_158 = V_69 -> V_93 + V_69 -> V_94 - V_156 ;
V_158 <<= V_9 -> V_92 ;
ASSERT ( V_158 > 0 ) ;
if ( V_158 > V_53 )
V_158 = V_53 ;
if ( V_52 < F_120 ( V_9 ) &&
V_52 + V_158 >= F_120 ( V_9 ) ) {
V_158 = F_134 ( F_120 ( V_9 ) - V_52 ,
F_9 ( V_9 ) ) ;
}
if ( V_158 > V_159 )
V_158 = V_159 ;
V_157 -> V_28 = V_158 ;
}
static int
F_135 (
struct V_9 * V_9 ,
T_7 V_156 ,
struct V_4 * V_157 ,
int V_160 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_71 , V_72 ;
int error = 0 ;
int V_161 = 0 ;
struct V_68 V_69 ;
int V_75 = 1 ;
T_1 V_52 ;
T_5 V_53 ;
F_136 ( V_160 ) ;
if ( F_35 ( V_13 ) )
return - V_61 ;
V_52 = ( T_1 ) V_156 << V_9 -> V_92 ;
ASSERT ( V_157 -> V_28 >= F_9 ( V_9 ) ) ;
V_53 = V_157 -> V_28 ;
if ( V_52 >= F_120 ( V_9 ) )
return 0 ;
V_161 = F_137 ( V_11 ) ;
ASSERT ( V_52 <= V_13 -> V_83 -> V_84 ) ;
if ( V_52 + V_53 > V_13 -> V_83 -> V_84 )
V_53 = V_13 -> V_83 -> V_84 - V_52 ;
V_72 = F_43 ( V_13 , ( V_85 ) V_52 + V_53 ) ;
V_71 = F_44 ( V_13 , V_52 ) ;
error = F_45 ( V_11 , V_71 , V_72 - V_71 ,
& V_69 , & V_75 , V_74 ) ;
if ( error )
goto V_162;
if ( V_75 ) {
F_138 ( V_11 , V_52 , V_53 ,
F_139 ( & V_69 ) ? V_65
: V_86 , & V_69 ) ;
F_22 ( V_11 , V_161 ) ;
} else {
F_140 ( V_11 , V_52 , V_53 ) ;
goto V_162;
}
F_133 ( V_9 , V_156 , V_157 , & V_69 , V_52 , V_53 ) ;
if ( V_69 . V_88 != V_90 &&
V_69 . V_88 != V_91 &&
! F_139 ( & V_69 ) )
F_85 ( V_9 , V_157 , & V_69 , V_52 ) ;
V_157 -> V_107 = F_5 ( V_9 ) ;
return 0 ;
V_162:
F_22 ( V_11 , V_161 ) ;
return error ;
}
STATIC T_5
F_141 (
struct V_163 * V_164 ,
struct V_165 * V_166 )
{
return - V_167 ;
}
STATIC T_7
F_142 (
struct V_153 * V_124 ,
T_7 V_168 )
{
struct V_9 * V_9 = (struct V_9 * ) V_124 -> V_126 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_143 ( F_6 ( V_9 ) ) ;
if ( F_108 ( V_11 ) )
return 0 ;
F_144 ( V_124 ) ;
return F_145 ( V_124 , V_168 , F_135 ) ;
}
STATIC int
F_146 (
struct V_169 * V_170 ,
struct V_1 * V_1 )
{
F_147 ( V_1 -> V_124 -> V_126 , 1 ) ;
return F_148 ( V_1 , F_135 ) ;
}
STATIC int
F_149 (
struct V_169 * V_170 ,
struct V_153 * V_124 ,
struct V_115 * V_171 ,
unsigned V_172 )
{
F_150 ( V_124 -> V_126 , V_172 ) ;
return F_151 ( V_124 , V_171 , V_172 , F_135 ) ;
}
STATIC int
F_152 (
struct V_1 * V_1 )
{
struct V_153 * V_124 = V_1 -> V_124 ;
struct V_9 * V_9 = V_124 -> V_126 ;
T_4 V_135 ;
T_4 V_52 ;
int V_173 ;
if ( F_36 ( ! V_124 ) )
return ! F_153 ( V_1 ) ;
V_135 = F_120 ( V_9 ) ;
V_52 = F_99 ( V_1 ) ;
F_154 ( & V_124 -> V_174 ) ;
if ( F_93 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_52 < V_135 )
F_155 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_52 += F_9 ( V_9 ) ;
} while ( V_5 != V_6 );
}
F_156 ( V_1 ) ;
V_173 = ! F_153 ( V_1 ) ;
F_157 ( & V_124 -> V_174 ) ;
if ( V_173 ) {
unsigned long V_144 ;
F_158 ( & V_124 -> V_175 , V_144 ) ;
if ( V_1 -> V_124 ) {
F_119 ( ! F_107 ( V_1 ) ) ;
F_159 ( V_1 , V_124 ) ;
F_160 ( & V_124 -> V_176 ,
F_161 ( V_1 ) , V_177 ) ;
}
F_162 ( & V_124 -> V_175 , V_144 ) ;
}
F_163 ( V_1 ) ;
if ( V_173 )
F_164 ( V_124 -> V_126 , V_178 ) ;
return V_173 ;
}
