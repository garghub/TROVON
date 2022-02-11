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
STATIC void
F_8 (
T_1 * V_18 )
{
struct V_4 * V_5 , * V_19 ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_19 ) {
V_19 = V_5 -> V_21 ;
V_5 -> V_22 ( V_5 , ! V_18 -> V_23 ) ;
}
F_9 ( V_18 , V_24 ) ;
}
static inline bool F_10 ( struct V_25 * V_18 )
{
return V_18 -> V_26 + V_18 -> V_27 >
F_6 ( V_18 -> V_28 ) -> V_29 . V_30 ;
}
STATIC int
F_11 (
struct V_25 * V_18 )
{
struct V_12 * V_13 = F_6 ( V_18 -> V_28 ) -> V_14 ;
struct V_31 * V_32 ;
int error ;
V_32 = F_12 ( V_13 , V_33 ) ;
error = F_13 ( V_32 , & F_14 ( V_13 ) -> V_34 , 0 , 0 ) ;
if ( error ) {
F_15 ( V_32 ) ;
return error ;
}
V_18 -> V_35 = V_32 ;
F_16 ( V_18 -> V_28 -> V_36 , V_37 ) ;
F_17 ( & V_32 -> V_38 , V_39 ) ;
return 0 ;
}
STATIC int
F_18 (
struct V_10 * V_11 ,
struct V_31 * V_32 ,
T_2 V_40 ,
T_3 V_41 )
{
T_4 V_42 ;
F_19 ( V_11 , V_43 ) ;
V_42 = F_20 ( V_11 , V_40 + V_41 ) ;
if ( ! V_42 ) {
F_21 ( V_11 , V_43 ) ;
F_15 ( V_32 ) ;
return 0 ;
}
F_22 ( V_11 , V_40 , V_41 ) ;
V_11 -> V_29 . V_30 = V_42 ;
F_23 ( V_32 , V_11 , V_43 ) ;
F_24 ( V_32 , V_11 , V_44 ) ;
return F_25 ( V_32 ) ;
}
STATIC int
F_26 (
struct V_25 * V_18 )
{
struct V_10 * V_11 = F_6 ( V_18 -> V_28 ) ;
struct V_31 * V_32 = V_18 -> V_35 ;
F_27 ( & V_32 -> V_38 , V_39 ) ;
F_28 ( F_29 ( V_11 ) -> V_36 , V_37 ) ;
if ( V_18 -> V_23 ) {
F_15 ( V_32 ) ;
return V_18 -> V_23 ;
}
return F_18 ( V_11 , V_32 , V_18 -> V_26 , V_18 -> V_27 ) ;
}
STATIC void
F_30 (
struct V_25 * V_18 )
{
if ( F_31 ( & V_18 -> V_45 ) ) {
struct V_12 * V_13 = F_6 ( V_18 -> V_28 ) -> V_14 ;
if ( V_18 -> V_46 == V_47 )
F_32 ( V_13 -> V_48 , & V_18 -> V_49 ) ;
else if ( V_18 -> V_35 )
F_32 ( V_13 -> V_50 , & V_18 -> V_49 ) ;
else
F_8 ( V_18 ) ;
}
}
STATIC void
F_33 (
struct V_51 * V_52 )
{
T_1 * V_18 = F_34 ( V_52 , T_1 , V_49 ) ;
struct V_10 * V_11 = F_6 ( V_18 -> V_28 ) ;
int error = 0 ;
if ( F_35 ( V_11 -> V_14 ) )
V_18 -> V_23 = - V_53 ;
if ( V_18 -> V_46 == V_47 ) {
if ( V_18 -> V_23 )
goto V_54;
error = F_36 ( V_11 , V_18 -> V_26 ,
V_18 -> V_27 ) ;
} else if ( V_18 -> V_35 ) {
error = F_26 ( V_18 ) ;
} else {
ASSERT ( ! F_10 ( V_18 ) ) ;
}
V_54:
if ( error )
V_18 -> V_23 = error ;
F_8 ( V_18 ) ;
}
STATIC T_1 *
F_37 (
struct V_9 * V_9 ,
unsigned int type )
{
T_1 * V_18 ;
V_18 = F_38 ( V_24 , V_55 ) ;
F_39 ( & V_18 -> V_45 , 1 ) ;
V_18 -> V_23 = 0 ;
F_40 ( & V_18 -> V_56 ) ;
V_18 -> V_46 = type ;
V_18 -> V_28 = V_9 ;
V_18 -> V_20 = NULL ;
V_18 -> V_57 = NULL ;
V_18 -> V_26 = 0 ;
V_18 -> V_27 = 0 ;
V_18 -> V_35 = NULL ;
F_41 ( & V_18 -> V_49 , F_33 ) ;
return V_18 ;
}
STATIC int
F_42 (
struct V_9 * V_9 ,
T_5 V_40 ,
struct V_58 * V_59 ,
int type )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_60 = 1 << V_9 -> V_61 ;
T_7 V_62 , V_63 ;
int error = 0 ;
int V_64 = V_65 ;
int V_66 = 1 ;
if ( F_35 ( V_13 ) )
return - V_53 ;
if ( type == V_47 )
V_64 |= V_67 ;
F_19 ( V_11 , V_68 ) ;
ASSERT ( V_11 -> V_29 . V_69 != V_70 ||
( V_11 -> V_71 . V_72 & V_73 ) ) ;
ASSERT ( V_40 <= V_13 -> V_74 -> V_75 ) ;
if ( V_40 + V_60 > V_13 -> V_74 -> V_75 )
V_60 = V_13 -> V_74 -> V_75 - V_40 ;
V_63 = F_43 ( V_13 , ( V_76 ) V_40 + V_60 ) ;
V_62 = F_44 ( V_13 , V_40 ) ;
error = F_45 ( V_11 , V_62 , V_63 - V_62 ,
V_59 , & V_66 , V_64 ) ;
F_21 ( V_11 , V_68 ) ;
if ( error )
return error ;
if ( type == V_77 &&
( ! V_66 || F_46 ( V_59 -> V_78 ) ) ) {
error = F_47 ( V_11 , V_40 , V_59 ) ;
if ( ! error )
F_48 ( V_11 , V_40 , V_60 , type , V_59 ) ;
return error ;
}
#ifdef F_49
if ( type == V_47 ) {
ASSERT ( V_66 ) ;
ASSERT ( V_59 -> V_78 != V_79 ) ;
ASSERT ( V_59 -> V_78 != V_80 ) ;
}
#endif
if ( V_66 )
F_50 ( V_11 , V_40 , V_60 , type , V_59 ) ;
return 0 ;
}
STATIC bool
F_51 (
struct V_9 * V_9 ,
struct V_58 * V_59 ,
T_2 V_40 )
{
V_40 >>= V_9 -> V_61 ;
return V_40 >= V_59 -> V_81 &&
V_40 < V_59 -> V_81 + V_59 -> V_82 ;
}
STATIC void
F_52 (
struct V_83 * V_83 )
{
T_1 * V_18 = V_83 -> V_84 ;
if ( ! V_18 -> V_23 )
V_18 -> V_23 = V_83 -> V_85 ;
V_83 -> V_84 = NULL ;
V_83 -> V_86 = NULL ;
F_53 ( V_83 ) ;
F_30 ( V_18 ) ;
}
STATIC void
F_54 (
struct V_87 * V_88 ,
T_1 * V_18 ,
struct V_83 * V_83 )
{
F_55 ( & V_18 -> V_45 ) ;
V_83 -> V_84 = V_18 ;
V_83 -> V_86 = F_52 ;
F_56 ( V_88 -> V_89 == V_90 ? V_91 : V_92 , V_83 ) ;
}
STATIC struct V_83 *
F_57 (
struct V_4 * V_5 )
{
struct V_83 * V_83 = F_58 ( V_93 , V_94 ) ;
ASSERT ( V_83 -> V_84 == NULL ) ;
V_83 -> V_95 . V_96 = V_5 -> V_97 * ( V_5 -> V_98 >> 9 ) ;
V_83 -> V_99 = V_5 -> V_100 ;
return V_83 ;
}
STATIC void
F_59 (
struct V_4 * V_5 )
{
ASSERT ( F_60 ( V_5 ) ) ;
ASSERT ( F_61 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_62 ( V_5 ) ;
F_63 ( V_5 ) ;
F_64 ( V_5 ) ;
}
STATIC void
F_65 (
struct V_1 * V_1 ,
int V_101 )
{
ASSERT ( F_66 ( V_1 ) ) ;
ASSERT ( ! F_67 ( V_1 ) ) ;
if ( V_101 ) {
F_68 ( V_1 ) ;
F_69 ( V_1 ) ;
} else
F_70 ( V_1 ) ;
F_71 ( V_1 ) ;
}
static inline int F_72 ( struct V_83 * V_83 , struct V_4 * V_5 )
{
return F_73 ( V_83 , V_5 -> V_102 , V_5 -> V_98 , F_74 ( V_5 ) ) ;
}
STATIC int
F_75 (
struct V_87 * V_88 ,
T_1 * V_18 ,
int V_103 )
{
struct V_4 * V_5 ;
struct V_83 * V_83 ;
T_8 V_104 = 0 ;
if ( ! V_103 &&
V_18 -> V_46 != V_47 && F_10 ( V_18 ) )
V_103 = F_11 ( V_18 ) ;
if ( V_103 ) {
V_18 -> V_23 = V_103 ;
F_30 ( V_18 ) ;
return V_103 ;
}
V_83 = NULL ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 ) {
if ( ! V_83 ) {
V_105:
V_83 = F_57 ( V_5 ) ;
} else if ( V_5 -> V_97 != V_104 + 1 ) {
F_54 ( V_88 , V_18 , V_83 ) ;
goto V_105;
}
if ( F_72 ( V_83 , V_5 ) != V_5 -> V_98 ) {
F_54 ( V_88 , V_18 , V_83 ) ;
goto V_105;
}
V_104 = V_5 -> V_97 ;
}
if ( V_83 )
F_54 ( V_88 , V_18 , V_83 ) ;
F_30 ( V_18 ) ;
return 0 ;
}
STATIC void
F_76 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_2 V_40 ,
struct V_106 * V_107 ,
struct V_108 * V_109 )
{
if ( ! V_107 -> V_18 || V_107 -> V_46 != V_107 -> V_18 -> V_46 ||
V_5 -> V_97 != V_107 -> V_110 + 1 ||
V_40 != V_107 -> V_18 -> V_26 + V_107 -> V_18 -> V_27 ) {
struct V_25 * V_111 ;
if ( V_107 -> V_18 )
F_77 ( & V_107 -> V_18 -> V_56 , V_109 ) ;
V_111 = F_37 ( V_9 , V_107 -> V_46 ) ;
V_111 -> V_26 = V_40 ;
V_111 -> V_20 = V_5 ;
V_111 -> V_57 = V_5 ;
V_107 -> V_18 = V_111 ;
} else {
V_107 -> V_18 -> V_57 -> V_21 = V_5 ;
V_107 -> V_18 -> V_57 = V_5 ;
}
V_5 -> V_21 = NULL ;
V_107 -> V_18 -> V_27 += V_5 -> V_98 ;
V_107 -> V_110 = V_5 -> V_97 ;
F_59 ( V_5 ) ;
}
STATIC void
F_78 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_58 * V_59 ,
T_2 V_40 )
{
T_8 V_112 ;
struct V_12 * V_113 = F_6 ( V_9 ) -> V_14 ;
T_2 V_114 = F_79 ( V_113 , V_59 -> V_81 ) ;
T_9 V_115 = F_80 ( F_6 ( V_9 ) , V_59 -> V_78 ) ;
ASSERT ( V_59 -> V_78 != V_79 ) ;
ASSERT ( V_59 -> V_78 != V_80 ) ;
V_112 = ( V_115 >> ( V_9 -> V_61 - V_116 ) ) +
( ( V_40 - V_114 ) >> V_9 -> V_61 ) ;
ASSERT ( V_112 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_97 = V_112 ;
F_81 ( V_5 ) ;
}
STATIC void
F_82 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_58 * V_59 ,
T_2 V_40 )
{
ASSERT ( V_59 -> V_78 != V_79 ) ;
ASSERT ( V_59 -> V_78 != V_80 ) ;
F_78 ( V_9 , V_5 , V_59 , V_40 ) ;
F_81 ( V_5 ) ;
F_83 ( V_5 ) ;
F_84 ( V_5 ) ;
}
STATIC bool
F_85 (
struct V_1 * V_1 ,
unsigned int type ,
bool V_117 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
if ( F_67 ( V_1 ) )
return false ;
if ( ! V_1 -> V_118 )
return false ;
if ( ! F_86 ( V_1 ) )
return false ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) ) {
if ( type == V_47 )
return true ;
} else if ( F_4 ( V_5 ) ) {
if ( type == V_77 )
return true ;
} else if ( F_87 ( V_5 ) && F_60 ( V_5 ) ) {
if ( type == V_119 )
return true ;
}
if ( ! V_117 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC void
F_88 (
struct V_1 * V_1 ,
unsigned int V_40 ,
unsigned int V_120 )
{
F_89 ( V_1 -> V_118 -> V_121 , V_1 , V_40 ,
V_120 ) ;
F_90 ( V_1 , V_40 , V_120 ) ;
}
STATIC void
F_91 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_118 -> V_121 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_5 V_40 = F_92 ( V_1 ) ;
if ( ! F_85 ( V_1 , V_77 , true ) )
goto V_122;
if ( F_35 ( V_11 -> V_14 ) )
goto V_122;
F_93 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_123 , V_40 ) ;
F_19 ( V_11 , V_43 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_7 V_124 ;
if ( ! F_4 ( V_5 ) )
goto V_125;
V_124 = F_44 ( V_11 -> V_14 , V_40 ) ;
error = F_94 ( V_11 , V_124 , 1 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_93 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_125:
V_40 += 1 << V_9 -> V_61 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_21 ( V_11 , V_43 ) ;
V_122:
F_88 ( V_1 , 0 , V_126 ) ;
return;
}
static int
F_95 (
struct V_106 * V_107 ,
struct V_87 * V_88 ,
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_5 V_40 ,
T_10 V_127 )
{
F_96 ( V_128 ) ;
struct V_25 * V_18 , * V_19 ;
struct V_4 * V_5 , * V_6 ;
T_6 V_129 = 1 << V_9 -> V_61 ;
int error = 0 ;
int V_60 = 0 ;
int V_130 = 1 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_40 = F_92 ( V_1 ) ;
do {
if ( V_40 >= V_127 )
break;
if ( ! F_97 ( V_5 ) )
V_130 = 0 ;
if ( ! F_60 ( V_5 ) && F_97 ( V_5 ) ) {
V_107 -> V_131 = false ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( V_107 -> V_46 != V_47 ) {
V_107 -> V_46 = V_47 ;
V_107 -> V_131 = false ;
}
} else if ( F_4 ( V_5 ) ) {
if ( V_107 -> V_46 != V_77 ) {
V_107 -> V_46 = V_77 ;
V_107 -> V_131 = false ;
}
} else if ( F_97 ( V_5 ) ) {
if ( V_107 -> V_46 != V_119 ) {
V_107 -> V_46 = V_119 ;
V_107 -> V_131 = false ;
}
} else {
if ( F_98 ( V_1 ) )
ASSERT ( F_60 ( V_5 ) ) ;
V_107 -> V_131 = false ;
continue;
}
if ( V_107 -> V_131 )
V_107 -> V_131 = F_51 ( V_9 , & V_107 -> V_59 ,
V_40 ) ;
if ( ! V_107 -> V_131 ) {
error = F_42 ( V_9 , V_40 , & V_107 -> V_59 ,
V_107 -> V_46 ) ;
if ( error )
goto V_132;
V_107 -> V_131 = F_51 ( V_9 , & V_107 -> V_59 ,
V_40 ) ;
}
if ( V_107 -> V_131 ) {
F_99 ( V_5 ) ;
if ( V_107 -> V_46 != V_119 )
F_82 ( V_9 , V_5 , & V_107 -> V_59 , V_40 ) ;
F_76 ( V_9 , V_5 , V_40 , V_107 , & V_128 ) ;
V_60 ++ ;
}
} while ( V_40 += V_129 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_130 && V_5 == V_6 )
F_100 ( V_1 ) ;
ASSERT ( V_107 -> V_18 || F_101 ( & V_128 ) ) ;
V_132:
if ( V_60 ) {
F_65 ( V_1 , ! error ) ;
F_102 (ioend, next, &submit_list, io_list) {
int V_133 ;
F_103 ( & V_18 -> V_56 ) ;
V_133 = F_75 ( V_88 , V_18 , error ) ;
if ( V_133 && ! error )
error = V_133 ;
}
} else if ( error ) {
F_91 ( V_1 ) ;
F_104 ( V_1 ) ;
F_71 ( V_1 ) ;
} else {
F_65 ( V_1 , 1 ) ;
F_105 ( V_1 ) ;
}
F_106 ( V_1 -> V_118 , error ) ;
return error ;
}
STATIC int
F_107 (
struct V_1 * V_1 ,
struct V_87 * V_88 ,
void * V_134 )
{
struct V_106 * V_107 = V_134 ;
struct V_9 * V_9 = V_1 -> V_118 -> V_121 ;
T_5 V_40 ;
T_10 V_127 ;
T_11 V_135 ;
F_108 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_86 ( V_1 ) ) ;
if ( F_109 ( ( V_136 -> V_137 & ( V_138 | V_139 ) ) ==
V_138 ) )
goto V_140;
if ( F_109 ( V_136 -> V_137 & V_39 ) )
goto V_140;
V_40 = F_110 ( V_9 ) ;
V_135 = V_40 >> V_141 ;
if ( V_1 -> V_142 < V_135 )
V_127 = ( T_2 ) ( V_1 -> V_142 + 1 ) << V_141 ;
else {
unsigned V_143 = V_40 & ( V_126 - 1 ) ;
if ( V_1 -> V_142 > V_135 ||
( V_1 -> V_142 == V_135 && V_143 == 0 ) )
goto V_140;
F_111 ( V_1 , V_143 , V_126 ) ;
V_127 = V_40 ;
}
return F_95 ( V_107 , V_88 , V_9 , V_1 , V_40 , V_127 ) ;
V_140:
F_112 ( V_88 , V_1 ) ;
F_71 ( V_1 ) ;
return 0 ;
}
STATIC int
F_113 (
struct V_1 * V_1 ,
struct V_87 * V_88 )
{
struct V_106 V_107 = {
. V_46 = V_144 ,
} ;
int V_145 ;
V_145 = F_107 ( V_1 , V_88 , & V_107 ) ;
if ( V_107 . V_18 )
V_145 = F_75 ( V_88 , V_107 . V_18 , V_145 ) ;
return V_145 ;
}
STATIC int
F_114 (
struct V_146 * V_118 ,
struct V_87 * V_88 )
{
struct V_106 V_107 = {
. V_46 = V_144 ,
} ;
int V_145 ;
F_115 ( F_6 ( V_118 -> V_121 ) , V_147 ) ;
if ( F_116 ( V_118 ) )
return F_117 ( V_118 ,
F_5 ( V_118 -> V_121 ) , V_88 ) ;
V_145 = F_118 ( V_118 , V_88 , F_107 , & V_107 ) ;
if ( V_107 . V_18 )
V_145 = F_75 ( V_88 , V_107 . V_18 , V_145 ) ;
return V_145 ;
}
STATIC int
F_119 (
struct V_1 * V_1 ,
T_12 V_148 )
{
int V_2 , V_3 ;
F_120 ( V_1 -> V_118 -> V_121 , V_1 , 0 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_109 ( V_2 ) )
return 0 ;
if ( F_109 ( V_3 ) )
return 0 ;
return F_121 ( V_1 ) ;
}
static void
F_122 (
struct V_9 * V_9 ,
struct V_4 * V_149 ,
struct V_58 * V_59 ,
T_2 V_40 )
{
T_13 * V_137 = ( T_13 * ) & V_149 -> V_21 ;
T_2 V_41 = V_149 -> V_98 ;
F_123 ( F_6 ( V_9 ) , V_40 , V_41 ,
F_124 ( V_59 ) ? V_47 : V_119 , V_59 ) ;
if ( F_124 ( V_59 ) ) {
* V_137 |= V_150 ;
F_125 ( V_149 ) ;
} else if ( V_40 + V_41 > F_110 ( V_9 ) || V_40 + V_41 < 0 ) {
* V_137 |= V_151 ;
F_125 ( V_149 ) ;
}
}
static void
F_126 (
struct V_9 * V_9 ,
T_8 V_152 ,
struct V_4 * V_149 ,
struct V_58 * V_59 ,
T_2 V_40 ,
T_6 V_41 )
{
T_2 V_153 ;
V_153 = V_59 -> V_81 + V_59 -> V_82 - V_152 ;
V_153 <<= V_9 -> V_61 ;
ASSERT ( V_153 > 0 ) ;
if ( V_153 > V_41 )
V_153 = V_41 ;
if ( V_40 < F_110 ( V_9 ) &&
V_40 + V_153 >= F_110 ( V_9 ) ) {
V_153 = F_127 ( F_110 ( V_9 ) - V_40 ,
1 << V_9 -> V_61 ) ;
}
if ( V_153 > V_154 )
V_153 = V_154 ;
V_149 -> V_98 = V_153 ;
}
STATIC int
F_128 (
struct V_9 * V_9 ,
T_8 V_152 ,
struct V_4 * V_149 ,
int V_155 ,
bool V_156 ,
bool V_157 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_7 V_62 , V_63 ;
int error = 0 ;
int V_158 = 0 ;
struct V_58 V_59 ;
int V_66 = 1 ;
T_2 V_40 ;
T_6 V_41 ;
int V_111 = 0 ;
if ( F_35 ( V_13 ) )
return - V_53 ;
V_40 = ( T_2 ) V_152 << V_9 -> V_61 ;
ASSERT ( V_149 -> V_98 >= ( 1 << V_9 -> V_61 ) ) ;
V_41 = V_149 -> V_98 ;
if ( ! V_155 && V_156 && V_40 >= F_110 ( V_9 ) )
return 0 ;
if ( V_155 && ! V_156 ) {
V_158 = V_43 ;
F_19 ( V_11 , V_158 ) ;
} else {
V_158 = F_129 ( V_11 ) ;
}
ASSERT ( V_40 <= V_13 -> V_74 -> V_75 ) ;
if ( V_40 + V_41 > V_13 -> V_74 -> V_75 )
V_41 = V_13 -> V_74 -> V_75 - V_40 ;
V_63 = F_43 ( V_13 , ( V_76 ) V_40 + V_41 ) ;
V_62 = F_44 ( V_13 , V_40 ) ;
error = F_45 ( V_11 , V_62 , V_63 - V_62 ,
& V_59 , & V_66 , V_65 ) ;
if ( error )
goto V_159;
if ( V_155 &&
( ! V_66 ||
( V_59 . V_78 == V_79 ||
V_59 . V_78 == V_80 ) ||
( F_130 ( V_9 ) && F_124 ( & V_59 ) ) ) ) {
if ( V_156 || F_131 ( V_11 ) ) {
if ( V_158 == V_43 )
F_132 ( V_11 , V_158 ) ;
error = F_133 ( V_11 , V_40 , V_41 ,
& V_59 , V_66 ) ;
if ( error )
return error ;
V_111 = 1 ;
} else {
if ( V_66 && V_59 . V_78 == V_79 )
V_111 = 1 ;
error = F_134 ( V_11 , V_40 , V_41 , & V_59 ) ;
if ( error )
goto V_159;
F_21 ( V_11 , V_158 ) ;
}
F_135 ( V_11 , V_40 , V_41 ,
F_124 ( & V_59 ) ? V_47
: V_77 , & V_59 ) ;
} else if ( V_66 ) {
F_136 ( V_11 , V_40 , V_41 ,
F_124 ( & V_59 ) ? V_47
: V_119 , & V_59 ) ;
F_21 ( V_11 , V_158 ) ;
} else {
F_137 ( V_11 , V_40 , V_41 ) ;
goto V_159;
}
if ( F_130 ( V_9 ) && V_155 ) {
ASSERT ( ! F_124 ( & V_59 ) ) ;
V_111 = 0 ;
}
if ( V_156 || V_41 > ( 1 << V_9 -> V_61 ) )
F_126 ( V_9 , V_152 , V_149 ,
& V_59 , V_40 , V_41 ) ;
if ( V_59 . V_78 != V_79 &&
V_59 . V_78 != V_80 &&
( V_155 || ! F_124 ( & V_59 ) ) ) {
F_78 ( V_9 , V_149 , & V_59 , V_40 ) ;
if ( F_124 ( & V_59 ) )
F_138 ( V_149 ) ;
if ( V_155 && V_156 ) {
if ( V_157 )
ASSERT ( ! F_124 ( & V_59 ) ) ;
else
F_122 ( V_9 , V_149 , & V_59 , V_40 ) ;
}
}
V_149 -> V_100 = F_5 ( V_9 ) ;
if ( V_155 &&
( ( ! F_60 ( V_149 ) && ! F_97 ( V_149 ) ) ||
( V_40 >= F_110 ( V_9 ) ) ||
( V_111 || F_124 ( & V_59 ) ) ) )
F_139 ( V_149 ) ;
if ( V_59 . V_78 == V_80 ) {
F_140 ( V_156 ) ;
if ( V_155 ) {
F_63 ( V_149 ) ;
F_81 ( V_149 ) ;
F_141 ( V_149 ) ;
}
}
return 0 ;
V_159:
F_21 ( V_11 , V_158 ) ;
return error ;
}
int
F_142 (
struct V_9 * V_9 ,
T_8 V_152 ,
struct V_4 * V_149 ,
int V_155 )
{
return F_128 ( V_9 , V_152 , V_149 , V_155 , false , false ) ;
}
int
F_143 (
struct V_9 * V_9 ,
T_8 V_152 ,
struct V_4 * V_149 ,
int V_155 )
{
return F_128 ( V_9 , V_152 , V_149 , V_155 , true , false ) ;
}
int
F_144 (
struct V_9 * V_9 ,
T_8 V_152 ,
struct V_4 * V_149 ,
int V_155 )
{
return F_128 ( V_9 , V_152 , V_149 , V_155 , true , true ) ;
}
STATIC int
F_145 (
struct V_160 * V_161 ,
T_5 V_40 ,
T_6 V_41 ,
void * V_162 )
{
struct V_9 * V_9 = F_146 ( V_161 -> V_163 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_13 V_137 = ( T_13 ) V_162 ;
int error = 0 ;
F_147 ( V_11 , V_40 , V_41 ) ;
if ( F_35 ( V_13 ) )
return - V_53 ;
if ( V_41 <= 0 )
return V_41 ;
if ( V_137 == 0 ) {
ASSERT ( V_40 + V_41 <= F_110 ( V_9 ) ) ;
return 0 ;
}
F_148 ( & V_11 -> V_164 ) ;
if ( V_40 + V_41 > F_110 ( V_9 ) )
F_149 ( V_9 , V_40 + V_41 ) ;
F_150 ( & V_11 -> V_164 ) ;
if ( V_137 & V_150 ) {
F_151 ( V_11 , V_40 , V_41 ) ;
error = F_36 ( V_11 , V_40 , V_41 ) ;
} else if ( V_137 & V_151 ) {
struct V_31 * V_32 ;
F_152 ( V_11 , V_40 , V_41 ) ;
V_32 = F_12 ( V_13 , V_33 ) ;
error = F_13 ( V_32 , & F_14 ( V_13 ) -> V_34 , 0 , 0 ) ;
if ( error ) {
F_15 ( V_32 ) ;
return error ;
}
error = F_18 ( V_11 , V_32 , V_40 , V_41 ) ;
}
return error ;
}
STATIC T_6
F_153 (
struct V_160 * V_161 ,
struct V_165 * V_166 ,
T_5 V_40 )
{
struct V_9 * V_9 = V_161 -> V_163 -> V_167 -> V_121 ;
T_14 * V_168 = NULL ;
int V_137 = 0 ;
struct V_8 * V_169 ;
if ( F_154 ( V_166 ) == V_92 ) {
V_168 = F_145 ;
V_137 = V_170 ;
}
if ( F_130 ( V_9 ) ) {
return F_155 ( V_161 , V_9 , V_166 , V_40 ,
F_143 , V_168 , 0 ) ;
}
V_169 = F_5 ( V_9 ) ;
return F_156 ( V_161 , V_9 , V_169 , V_166 , V_40 ,
F_143 , V_168 , NULL , V_137 ) ;
}
STATIC void
F_157 (
struct V_9 * V_9 ,
T_5 V_171 ,
T_5 V_172 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_7 V_124 ;
T_7 V_63 ;
int error ;
V_124 = F_43 ( V_11 -> V_14 , V_171 ) ;
V_63 = F_43 ( V_11 -> V_14 , V_172 ) ;
if ( V_63 <= V_124 )
return;
F_19 ( V_11 , V_43 ) ;
error = F_94 ( V_11 , V_124 ,
V_63 - V_124 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_93 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_123 ) ;
}
}
F_21 ( V_11 , V_43 ) ;
}
STATIC void
F_158 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_5 V_173 ,
unsigned V_129 )
{
T_5 V_174 ;
T_5 V_175 ;
T_5 V_176 ;
T_5 V_177 = V_173 & ( V_126 - 1 ) ;
T_5 V_178 = V_177 + V_129 ;
struct V_4 * V_5 , * V_6 ;
struct V_12 * V_13 = F_6 ( V_9 ) -> V_14 ;
V_174 = ( V_173 >> V_141 ) << V_141 ;
ASSERT ( V_174 + V_177 == V_173 ) ;
V_6 = F_2 ( V_1 ) ;
V_175 = 0 ;
for ( V_5 = V_6 ; V_5 != V_6 || ! V_175 ;
V_5 = V_5 -> V_7 , V_175 = V_176 ,
V_174 += V_5 -> V_98 ) {
V_176 = V_175 + V_5 -> V_98 ;
if ( V_176 <= V_177 )
continue;
if ( V_175 >= V_178 )
break;
if ( ! F_4 ( V_5 ) && ! F_3 ( V_5 ) )
continue;
if ( ! F_159 ( V_13 ) && ! F_160 ( V_5 ) &&
V_174 < F_110 ( V_9 ) )
continue;
if ( F_4 ( V_5 ) )
F_157 ( V_9 , V_174 ,
V_174 + V_5 -> V_98 ) ;
F_83 ( V_5 ) ;
F_161 ( V_5 ) ;
F_162 ( V_5 ) ;
F_163 ( V_5 ) ;
F_64 ( V_5 ) ;
F_84 ( V_5 ) ;
}
}
STATIC int
F_164 (
struct V_179 * V_179 ,
struct V_146 * V_118 ,
T_5 V_173 ,
unsigned V_129 ,
unsigned V_137 ,
struct V_1 * * V_180 ,
void * * V_181 )
{
T_11 V_142 = V_173 >> V_141 ;
struct V_1 * V_1 ;
int V_103 ;
struct V_12 * V_13 = F_6 ( V_118 -> V_121 ) -> V_14 ;
ASSERT ( V_129 <= V_126 ) ;
V_1 = F_165 ( V_118 , V_142 , V_137 ) ;
if ( ! V_1 )
return - V_182 ;
V_103 = F_166 ( V_1 , V_173 , V_129 , F_142 ) ;
if ( F_159 ( V_13 ) )
V_103 = - V_53 ;
if ( F_167 ( V_103 ) ) {
struct V_9 * V_9 = V_118 -> V_121 ;
T_3 V_42 = F_110 ( V_9 ) ;
F_158 ( V_9 , V_1 , V_173 , V_129 ) ;
F_71 ( V_1 ) ;
if ( F_159 ( V_13 ) )
V_42 = 0 ;
if ( V_173 + V_129 > V_42 ) {
T_6 V_171 = F_168 ( T_6 , V_173 , V_42 ) ;
F_169 ( V_9 , V_171 , V_173 + V_129 ) ;
}
F_170 ( V_1 ) ;
V_1 = NULL ;
}
* V_180 = V_1 ;
return V_103 ;
}
STATIC int
F_171 (
struct V_179 * V_179 ,
struct V_146 * V_118 ,
T_5 V_173 ,
unsigned V_129 ,
unsigned V_183 ,
struct V_1 * V_1 ,
void * V_181 )
{
int V_145 ;
ASSERT ( V_129 <= V_126 ) ;
V_145 = F_172 ( V_179 , V_118 , V_173 , V_129 , V_183 , V_1 , V_181 ) ;
if ( F_167 ( V_145 < V_129 ) ) {
struct V_9 * V_9 = V_118 -> V_121 ;
T_3 V_42 = F_110 ( V_9 ) ;
T_5 V_178 = V_173 + V_129 ;
if ( V_178 > V_42 ) {
if ( V_173 > V_42 )
V_42 = V_173 ;
F_157 ( V_9 , V_42 , V_178 ) ;
F_169 ( V_9 , V_42 , V_178 ) ;
}
}
return V_145 ;
}
STATIC T_8
F_173 (
struct V_146 * V_118 ,
T_8 V_184 )
{
struct V_9 * V_9 = (struct V_9 * ) V_118 -> V_121 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_174 ( F_6 ( V_9 ) ) ;
F_19 ( V_11 , V_185 ) ;
F_175 ( V_118 ) ;
F_21 ( V_11 , V_185 ) ;
return F_176 ( V_118 , V_184 , F_142 ) ;
}
STATIC int
F_177 (
struct V_179 * V_186 ,
struct V_1 * V_1 )
{
F_178 ( V_1 -> V_118 -> V_121 , 1 ) ;
return F_179 ( V_1 , F_142 ) ;
}
STATIC int
F_180 (
struct V_179 * V_186 ,
struct V_146 * V_118 ,
struct V_108 * V_187 ,
unsigned V_188 )
{
F_181 ( V_118 -> V_121 , V_188 ) ;
return F_182 ( V_118 , V_187 , V_188 , F_142 ) ;
}
STATIC int
F_183 (
struct V_1 * V_1 )
{
struct V_146 * V_118 = V_1 -> V_118 ;
struct V_9 * V_9 = V_118 -> V_121 ;
T_5 V_127 ;
T_5 V_40 ;
int V_189 ;
if ( F_167 ( ! V_118 ) )
return ! F_184 ( V_1 ) ;
V_127 = F_110 ( V_9 ) ;
V_40 = F_92 ( V_1 ) ;
F_148 ( & V_118 -> V_190 ) ;
if ( F_86 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_40 < V_127 )
F_185 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_40 += 1 << V_9 -> V_61 ;
} while ( V_5 != V_6 );
}
F_186 ( V_1 ) ;
V_189 = ! F_184 ( V_1 ) ;
F_150 ( & V_118 -> V_190 ) ;
if ( V_189 ) {
unsigned long V_137 ;
F_187 ( & V_118 -> V_191 , V_137 ) ;
if ( V_1 -> V_118 ) {
F_109 ( ! F_98 ( V_1 ) ) ;
F_188 ( V_1 , V_118 ) ;
F_189 ( & V_118 -> V_192 ,
F_190 ( V_1 ) , V_193 ) ;
}
F_191 ( & V_118 -> V_191 , V_137 ) ;
}
F_192 ( V_1 ) ;
if ( V_189 )
F_193 ( V_118 -> V_121 , V_194 ) ;
return V_189 ;
}
