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
STATIC struct V_8 *
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
if ( F_35 ( V_11 -> V_14 ) ) {
V_18 -> V_23 = - V_53 ;
goto V_54;
}
if ( V_18 -> V_23 )
goto V_54;
if ( V_18 -> V_46 == V_47 ) {
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
V_18 -> V_56 = NULL ;
V_18 -> V_46 = type ;
V_18 -> V_28 = V_9 ;
V_18 -> V_20 = NULL ;
V_18 -> V_57 = NULL ;
V_18 -> V_26 = 0 ;
V_18 -> V_27 = 0 ;
V_18 -> V_35 = NULL ;
F_40 ( & V_18 -> V_49 , F_33 ) ;
return V_18 ;
}
STATIC int
F_41 (
struct V_9 * V_9 ,
T_5 V_40 ,
struct V_58 * V_59 ,
int type ,
int V_60 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_61 = 1 << V_9 -> V_62 ;
T_7 V_63 , V_64 ;
int error = 0 ;
int V_65 = V_66 ;
int V_67 = 1 ;
if ( F_35 ( V_13 ) )
return - V_53 ;
if ( type == V_47 )
V_65 |= V_68 ;
if ( ! F_42 ( V_11 , V_69 ) ) {
if ( V_60 )
return - V_70 ;
F_19 ( V_11 , V_69 ) ;
}
ASSERT ( V_11 -> V_29 . V_71 != V_72 ||
( V_11 -> V_73 . V_74 & V_75 ) ) ;
ASSERT ( V_40 <= V_13 -> V_76 -> V_77 ) ;
if ( V_40 + V_61 > V_13 -> V_76 -> V_77 )
V_61 = V_13 -> V_76 -> V_77 - V_40 ;
V_64 = F_43 ( V_13 , ( V_78 ) V_40 + V_61 ) ;
V_63 = F_44 ( V_13 , V_40 ) ;
error = F_45 ( V_11 , V_63 , V_64 - V_63 ,
V_59 , & V_67 , V_65 ) ;
F_21 ( V_11 , V_69 ) ;
if ( error )
return error ;
if ( type == V_79 &&
( ! V_67 || F_46 ( V_59 -> V_80 ) ) ) {
error = F_47 ( V_11 , V_40 , V_59 ) ;
if ( ! error )
F_48 ( V_11 , V_40 , V_61 , type , V_59 ) ;
return error ;
}
#ifdef F_49
if ( type == V_47 ) {
ASSERT ( V_67 ) ;
ASSERT ( V_59 -> V_80 != V_81 ) ;
ASSERT ( V_59 -> V_80 != V_82 ) ;
}
#endif
if ( V_67 )
F_50 ( V_11 , V_40 , V_61 , type , V_59 ) ;
return 0 ;
}
STATIC int
F_51 (
struct V_9 * V_9 ,
struct V_58 * V_59 ,
T_2 V_40 )
{
V_40 >>= V_9 -> V_62 ;
return V_40 >= V_59 -> V_83 &&
V_40 < V_59 -> V_83 + V_59 -> V_84 ;
}
STATIC void
F_52 (
struct V_85 * V_85 )
{
T_1 * V_18 = V_85 -> V_86 ;
if ( ! V_18 -> V_23 )
V_18 -> V_23 = V_85 -> V_87 ;
V_85 -> V_86 = NULL ;
V_85 -> V_88 = NULL ;
F_53 ( V_85 ) ;
F_30 ( V_18 ) ;
}
STATIC void
F_54 (
struct V_89 * V_90 ,
T_1 * V_18 ,
struct V_85 * V_85 )
{
F_55 ( & V_18 -> V_45 ) ;
V_85 -> V_86 = V_18 ;
V_85 -> V_88 = F_52 ;
F_56 ( V_90 -> V_91 == V_92 ? V_93 : V_94 , V_85 ) ;
}
STATIC struct V_85 *
F_57 (
struct V_4 * V_5 )
{
struct V_85 * V_85 = F_58 ( V_95 , V_96 ) ;
ASSERT ( V_85 -> V_86 == NULL ) ;
V_85 -> V_97 . V_98 = V_5 -> V_99 * ( V_5 -> V_100 >> 9 ) ;
V_85 -> V_101 = V_5 -> V_102 ;
return V_85 ;
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
int V_103 ,
int V_104 )
{
ASSERT ( F_66 ( V_1 ) ) ;
ASSERT ( ! F_67 ( V_1 ) ) ;
if ( V_103 ) {
F_68 ( V_1 ) ;
F_69 ( V_1 ) ;
} else
F_70 ( V_1 ) ;
F_71 ( V_1 ) ;
if ( ! V_104 )
F_72 ( V_1 ) ;
}
static inline int F_73 ( struct V_85 * V_85 , struct V_4 * V_5 )
{
return F_74 ( V_85 , V_5 -> V_105 , V_5 -> V_100 , F_75 ( V_5 ) ) ;
}
STATIC void
F_76 (
struct V_89 * V_90 ,
T_1 * V_18 ,
int V_106 )
{
T_1 * V_6 = V_18 ;
T_1 * V_19 ;
struct V_4 * V_5 ;
struct V_85 * V_85 ;
T_8 V_107 = 0 ;
do {
V_19 = V_18 -> V_56 ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 )
F_59 ( V_5 ) ;
} while ( ( V_18 = V_19 ) != NULL );
V_18 = V_6 ;
do {
V_19 = V_18 -> V_56 ;
V_85 = NULL ;
if ( V_106 ) {
V_18 -> V_23 = V_106 ;
F_30 ( V_18 ) ;
continue;
}
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 ) {
if ( ! V_85 ) {
V_108:
V_85 = F_57 ( V_5 ) ;
} else if ( V_5 -> V_99 != V_107 + 1 ) {
F_54 ( V_90 , V_18 , V_85 ) ;
goto V_108;
}
if ( F_73 ( V_85 , V_5 ) != V_5 -> V_100 ) {
F_54 ( V_90 , V_18 , V_85 ) ;
goto V_108;
}
V_107 = V_5 -> V_99 ;
}
if ( V_85 )
F_54 ( V_90 , V_18 , V_85 ) ;
F_30 ( V_18 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_77 (
T_1 * V_18 )
{
T_1 * V_19 ;
struct V_4 * V_5 , * V_109 ;
do {
V_19 = V_18 -> V_56 ;
V_5 = V_18 -> V_20 ;
do {
V_109 = V_5 -> V_21 ;
F_78 ( V_5 ) ;
if ( V_18 -> V_46 == V_47 )
F_79 ( V_5 ) ;
F_80 ( V_5 ) ;
} while ( ( V_5 = V_109 ) != NULL );
F_9 ( V_18 , V_24 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_81 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_2 V_40 ,
unsigned int type ,
T_1 * * V_110 ,
int V_111 )
{
T_1 * V_18 = * V_110 ;
if ( ! V_18 || V_111 || type != V_18 -> V_46 ) {
T_1 * V_112 = * V_110 ;
V_18 = F_37 ( V_9 , type ) ;
V_18 -> V_26 = V_40 ;
V_18 -> V_20 = V_5 ;
V_18 -> V_57 = V_5 ;
if ( V_112 )
V_112 -> V_56 = V_18 ;
* V_110 = V_18 ;
} else {
V_18 -> V_57 -> V_21 = V_5 ;
V_18 -> V_57 = V_5 ;
}
V_5 -> V_21 = NULL ;
V_18 -> V_27 += V_5 -> V_100 ;
}
STATIC void
F_82 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_58 * V_59 ,
T_2 V_40 )
{
T_8 V_113 ;
struct V_12 * V_114 = F_6 ( V_9 ) -> V_14 ;
T_2 V_115 = F_83 ( V_114 , V_59 -> V_83 ) ;
T_9 V_116 = F_84 ( F_6 ( V_9 ) , V_59 -> V_80 ) ;
ASSERT ( V_59 -> V_80 != V_81 ) ;
ASSERT ( V_59 -> V_80 != V_82 ) ;
V_113 = ( V_116 >> ( V_9 -> V_62 - V_117 ) ) +
( ( V_40 - V_115 ) >> V_9 -> V_62 ) ;
ASSERT ( V_113 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_99 = V_113 ;
F_85 ( V_5 ) ;
}
STATIC void
F_86 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_58 * V_59 ,
T_2 V_40 )
{
ASSERT ( V_59 -> V_80 != V_81 ) ;
ASSERT ( V_59 -> V_80 != V_82 ) ;
F_82 ( V_9 , V_5 , V_59 , V_40 ) ;
F_85 ( V_5 ) ;
F_87 ( V_5 ) ;
F_88 ( V_5 ) ;
}
STATIC bool
F_89 (
struct V_1 * V_1 ,
unsigned int type ,
bool V_118 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
if ( F_67 ( V_1 ) )
return false ;
if ( ! V_1 -> V_119 )
return false ;
if ( ! F_90 ( V_1 ) )
return false ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) ) {
if ( type == V_47 )
return true ;
} else if ( F_4 ( V_5 ) ) {
if ( type == V_79 )
return true ;
} else if ( F_91 ( V_5 ) && F_60 ( V_5 ) ) {
if ( type == V_120 )
return true ;
}
if ( ! V_118 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC int
F_92 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_5 V_121 ,
struct V_58 * V_59 ,
T_1 * * V_122 ,
struct V_89 * V_90 )
{
struct V_4 * V_5 , * V_6 ;
T_2 V_123 ;
unsigned long V_124 ;
unsigned int type ;
int V_125 , V_126 ;
int V_61 = 0 , V_54 = 0 , V_127 = 1 ;
T_2 V_40 = F_93 ( V_1 ) ;
if ( V_1 -> V_128 != V_121 )
goto V_106;
if ( ! F_94 ( V_1 ) )
goto V_106;
if ( F_67 ( V_1 ) )
goto V_129;
if ( V_1 -> V_119 != V_9 -> V_130 )
goto V_129;
if ( ! F_89 ( V_1 , ( * V_122 ) -> V_46 , false ) )
goto V_129;
V_123 = F_95 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode)) ;
if ( ! F_51 ( V_9 , V_59 , V_123 ) )
goto V_129;
V_125 = 1 << V_9 -> V_62 ;
V_124 = F_95 (unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE) ;
V_124 = V_124 ? F_96 ( V_124 , V_125 ) : V_131 ;
V_126 = V_124 / V_125 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( V_40 >= V_123 )
break;
if ( ! F_97 ( V_5 ) )
V_127 = 0 ;
if ( ! ( F_98 ( V_1 ) || F_97 ( V_5 ) ) ) {
V_54 = 1 ;
break;
}
if ( F_3 ( V_5 ) || F_4 ( V_5 ) ||
F_60 ( V_5 ) ) {
if ( F_3 ( V_5 ) )
type = V_47 ;
else if ( F_4 ( V_5 ) )
type = V_79 ;
else
type = V_120 ;
ASSERT ( F_51 ( V_9 , V_59 , V_40 ) ) ;
F_99 ( V_5 ) ;
if ( type != V_120 )
F_86 ( V_9 , V_5 , V_59 , V_40 ) ;
F_81 ( V_9 , V_5 , V_40 , type ,
V_122 , V_54 ) ;
V_126 -- ;
V_61 ++ ;
} else {
V_54 = 1 ;
break;
}
} while ( V_40 += V_125 , ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_127 && V_5 == V_6 )
F_100 ( V_1 ) ;
if ( V_61 ) {
if ( -- V_90 -> V_132 <= 0 &&
V_90 -> V_91 == V_133 )
V_54 = 1 ;
}
F_65 ( V_1 , ! V_126 , V_61 ) ;
return V_54 ;
V_129:
F_71 ( V_1 ) ;
V_106:
return 1 ;
}
STATIC void
F_101 (
struct V_9 * V_9 ,
T_10 V_121 ,
struct V_58 * V_59 ,
T_1 * * V_122 ,
struct V_89 * V_90 ,
T_10 V_134 )
{
struct V_135 V_136 ;
int V_54 = 0 , V_137 ;
F_102 ( & V_136 , 0 ) ;
while ( ! V_54 && V_121 <= V_134 ) {
unsigned V_125 = F_95 ( T_10 , V_138 , V_134 - V_121 + 1 ) ;
if ( ! F_103 ( & V_136 , V_9 -> V_130 , V_121 , V_125 ) )
break;
for ( V_137 = 0 ; V_137 < F_104 ( & V_136 ) ; V_137 ++ ) {
V_54 = F_92 ( V_9 , V_136 . V_139 [ V_137 ] , V_121 ++ ,
V_59 , V_122 , V_90 ) ;
if ( V_54 )
break;
}
F_105 ( & V_136 ) ;
F_106 () ;
}
}
STATIC void
F_107 (
struct V_1 * V_1 ,
unsigned int V_40 ,
unsigned int V_140 )
{
F_108 ( V_1 -> V_119 -> V_141 , V_1 , V_40 ,
V_140 ) ;
F_109 ( V_1 , V_40 , V_140 ) ;
}
STATIC void
F_110 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_119 -> V_141 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_5 V_40 = F_93 ( V_1 ) ;
if ( ! F_89 ( V_1 , V_79 , true ) )
goto V_142;
if ( F_35 ( V_11 -> V_14 ) )
goto V_142;
F_111 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_143 , V_40 ) ;
F_19 ( V_11 , V_43 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_7 V_144 ;
if ( ! F_4 ( V_5 ) )
goto V_145;
V_144 = F_44 ( V_11 -> V_14 , V_40 ) ;
error = F_112 ( V_11 , V_144 , 1 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_111 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_145:
V_40 += 1 << V_9 -> V_62 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_21 ( V_11 , V_43 ) ;
V_142:
F_107 ( V_1 , 0 , V_131 ) ;
return;
}
STATIC int
F_113 (
struct V_1 * V_1 ,
struct V_89 * V_90 )
{
struct V_9 * V_9 = V_1 -> V_119 -> V_141 ;
struct V_4 * V_5 , * V_6 ;
struct V_58 V_59 ;
T_1 * V_18 = NULL , * V_146 = NULL ;
T_5 V_40 ;
unsigned int type ;
T_11 V_123 ;
T_10 V_147 , V_148 ;
T_6 V_125 ;
int V_149 , V_150 = 0 , V_127 = 1 ;
int V_61 = 0 ;
int V_60 = 0 ;
F_114 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_90 ( V_1 ) ) ;
if ( F_115 ( ( V_151 -> V_152 & ( V_153 | V_154 ) ) ==
V_153 ) )
goto V_155;
if ( F_115 ( V_151 -> V_152 & V_39 ) )
goto V_155;
V_40 = F_116 ( V_9 ) ;
V_147 = V_40 >> V_156 ;
V_148 = ( V_40 - 1 ) >> V_156 ;
if ( V_1 -> V_128 < V_147 )
V_123 = ( T_2 ) ( V_1 -> V_128 + 1 ) << V_156 ;
else {
unsigned V_157 = V_40 & ( V_131 - 1 ) ;
if ( V_1 -> V_128 > V_147 ||
( V_1 -> V_128 == V_147 && V_157 == 0 ) )
goto V_155;
F_117 ( V_1 , V_157 , V_131 ) ;
V_123 = V_40 ;
}
V_125 = 1 << V_9 -> V_62 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_40 = F_93 ( V_1 ) ;
type = V_120 ;
if ( V_90 -> V_91 == V_133 )
V_60 = 1 ;
do {
int V_158 = 0 ;
if ( V_40 >= V_123 )
break;
if ( ! F_97 ( V_5 ) )
V_127 = 0 ;
if ( ! F_60 ( V_5 ) && F_97 ( V_5 ) ) {
V_150 = 0 ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( type != V_47 ) {
type = V_47 ;
V_150 = 0 ;
}
} else if ( F_4 ( V_5 ) ) {
if ( type != V_79 ) {
type = V_79 ;
V_150 = 0 ;
}
} else if ( F_97 ( V_5 ) ) {
if ( type != V_120 ) {
type = V_120 ;
V_150 = 0 ;
}
} else {
if ( F_98 ( V_1 ) )
ASSERT ( F_60 ( V_5 ) ) ;
V_150 = 0 ;
continue;
}
if ( V_150 )
V_150 = F_51 ( V_9 , & V_59 , V_40 ) ;
if ( ! V_150 ) {
V_158 = 1 ;
V_149 = F_41 ( V_9 , V_40 , & V_59 , type ,
V_60 ) ;
if ( V_149 )
goto error;
V_150 = F_51 ( V_9 , & V_59 , V_40 ) ;
}
if ( V_150 ) {
F_99 ( V_5 ) ;
if ( type != V_120 )
F_86 ( V_9 , V_5 , & V_59 , V_40 ) ;
F_81 ( V_9 , V_5 , V_40 , type , & V_18 ,
V_158 ) ;
V_61 ++ ;
}
if ( ! V_146 )
V_146 = V_18 ;
} while ( V_40 += V_125 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_127 && V_5 == V_6 )
F_100 ( V_1 ) ;
F_65 ( V_1 , 1 , V_61 ) ;
if ( ! V_18 )
return 0 ;
ASSERT ( V_146 ) ;
if ( V_150 ) {
T_2 V_147 ;
V_147 = V_59 . V_83 + V_59 . V_84 ;
V_147 <<= V_9 -> V_62 ;
V_147 = ( V_147 - 1 ) >> V_156 ;
if ( V_147 > V_148 )
V_147 = V_148 ;
F_101 ( V_9 , V_1 -> V_128 + 1 , & V_59 , & V_18 ,
V_90 , V_147 ) ;
}
V_149 = 0 ;
if ( V_18 -> V_46 != V_47 && F_10 ( V_18 ) )
V_149 = F_11 ( V_18 ) ;
F_76 ( V_90 , V_146 , V_149 ) ;
return 0 ;
error:
if ( V_146 )
F_77 ( V_146 ) ;
if ( V_149 == - V_70 )
goto V_155;
F_110 ( V_1 ) ;
F_118 ( V_1 ) ;
F_71 ( V_1 ) ;
return V_149 ;
V_155:
F_119 ( V_90 , V_1 ) ;
F_71 ( V_1 ) ;
return 0 ;
}
STATIC int
F_120 (
struct V_159 * V_119 ,
struct V_89 * V_90 )
{
F_121 ( F_6 ( V_119 -> V_141 ) , V_160 ) ;
return F_122 ( V_119 , V_90 ) ;
}
STATIC int
F_123 (
struct V_1 * V_1 ,
T_12 V_161 )
{
int V_2 , V_3 ;
F_124 ( V_1 -> V_119 -> V_141 , V_1 , 0 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_115 ( V_2 ) )
return 0 ;
if ( F_115 ( V_3 ) )
return 0 ;
return F_125 ( V_1 ) ;
}
static void
F_126 (
struct V_9 * V_9 ,
struct V_4 * V_162 ,
struct V_58 * V_59 ,
T_2 V_40 )
{
struct V_25 * V_18 ;
T_2 V_41 = V_162 -> V_100 ;
int type ;
if ( F_127 ( V_59 ) )
type = V_47 ;
else
type = V_120 ;
F_128 ( F_6 ( V_9 ) , V_40 , V_41 , type , V_59 ) ;
if ( V_162 -> V_21 ) {
V_18 = V_162 -> V_21 ;
ASSERT ( V_18 -> V_27 > 0 ) ;
ASSERT ( V_40 >= V_18 -> V_26 ) ;
if ( V_40 + V_41 > V_18 -> V_26 + V_18 -> V_27 )
V_18 -> V_27 = V_40 - V_18 -> V_26 + V_41 ;
if ( type == V_47 && type != V_18 -> V_46 )
V_18 -> V_46 = V_47 ;
F_129 ( F_6 ( V_9 ) , V_18 -> V_26 ,
V_18 -> V_27 , V_18 -> V_46 ,
V_59 ) ;
} else if ( type == V_47 ||
V_40 + V_41 > F_116 ( V_9 ) ) {
V_18 = F_37 ( V_9 , type ) ;
V_18 -> V_26 = V_40 ;
V_18 -> V_27 = V_41 ;
V_162 -> V_21 = V_18 ;
F_130 ( V_162 ) ;
F_131 ( F_6 ( V_9 ) , V_40 , V_41 , type ,
V_59 ) ;
} else {
F_132 ( F_6 ( V_9 ) , V_40 , V_41 , type ,
V_59 ) ;
}
}
static void
F_133 (
struct V_9 * V_9 ,
T_8 V_163 ,
struct V_4 * V_162 ,
struct V_58 * V_59 ,
T_2 V_40 ,
T_6 V_41 )
{
T_2 V_164 ;
V_164 = V_59 -> V_83 + V_59 -> V_84 - V_163 ;
V_164 <<= V_9 -> V_62 ;
ASSERT ( V_164 > 0 ) ;
if ( V_164 > V_41 )
V_164 = V_41 ;
if ( V_40 < F_116 ( V_9 ) &&
V_40 + V_164 >= F_116 ( V_9 ) ) {
V_164 = F_134 ( F_116 ( V_9 ) - V_40 ,
1 << V_9 -> V_62 ) ;
}
if ( V_164 > V_165 )
V_164 = V_165 ;
V_162 -> V_100 = V_164 ;
}
STATIC int
F_135 (
struct V_9 * V_9 ,
T_8 V_163 ,
struct V_4 * V_162 ,
int V_166 ,
bool V_167 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_7 V_63 , V_64 ;
int error = 0 ;
int V_168 = 0 ;
struct V_58 V_59 ;
int V_67 = 1 ;
T_2 V_40 ;
T_6 V_41 ;
int V_169 = 0 ;
if ( F_35 ( V_13 ) )
return - V_53 ;
V_40 = ( T_2 ) V_163 << V_9 -> V_62 ;
ASSERT ( V_162 -> V_100 >= ( 1 << V_9 -> V_62 ) ) ;
V_41 = V_162 -> V_100 ;
if ( ! V_166 && V_167 && V_40 >= F_116 ( V_9 ) )
return 0 ;
if ( V_166 && ! V_167 ) {
V_168 = V_43 ;
F_19 ( V_11 , V_168 ) ;
} else {
V_168 = F_136 ( V_11 ) ;
}
ASSERT ( V_40 <= V_13 -> V_76 -> V_77 ) ;
if ( V_40 + V_41 > V_13 -> V_76 -> V_77 )
V_41 = V_13 -> V_76 -> V_77 - V_40 ;
V_64 = F_43 ( V_13 , ( V_78 ) V_40 + V_41 ) ;
V_63 = F_44 ( V_13 , V_40 ) ;
error = F_45 ( V_11 , V_63 , V_64 - V_63 ,
& V_59 , & V_67 , V_66 ) ;
if ( error )
goto V_170;
if ( V_166 &&
( ! V_67 ||
( V_59 . V_80 == V_81 ||
V_59 . V_80 == V_82 ) ) ) {
if ( V_167 || F_137 ( V_11 ) ) {
F_21 ( V_11 , V_168 ) ;
error = F_138 ( V_11 , V_40 , V_41 ,
& V_59 , V_67 ) ;
if ( error )
return error ;
V_169 = 1 ;
} else {
if ( V_67 && V_59 . V_80 == V_81 )
V_169 = 1 ;
error = F_139 ( V_11 , V_40 , V_41 , & V_59 ) ;
if ( error )
goto V_170;
F_21 ( V_11 , V_168 ) ;
}
F_140 ( V_11 , V_40 , V_41 ,
F_127 ( & V_59 ) ? V_47
: V_79 , & V_59 ) ;
} else if ( V_67 ) {
F_141 ( V_11 , V_40 , V_41 ,
F_127 ( & V_59 ) ? V_47
: V_120 , & V_59 ) ;
F_21 ( V_11 , V_168 ) ;
} else {
F_142 ( V_11 , V_40 , V_41 ) ;
goto V_170;
}
if ( V_167 || V_41 > ( 1 << V_9 -> V_62 ) )
F_133 ( V_9 , V_163 , V_162 ,
& V_59 , V_40 , V_41 ) ;
if ( V_59 . V_80 != V_81 &&
V_59 . V_80 != V_82 &&
( V_166 || ! F_127 ( & V_59 ) ) ) {
F_82 ( V_9 , V_162 , & V_59 , V_40 ) ;
if ( F_127 ( & V_59 ) )
F_79 ( V_162 ) ;
if ( V_166 && V_167 )
F_126 ( V_9 , V_162 , & V_59 , V_40 ) ;
}
V_162 -> V_102 = F_5 ( V_9 ) ;
if ( V_166 &&
( ( ! F_60 ( V_162 ) && ! F_97 ( V_162 ) ) ||
( V_40 >= F_116 ( V_9 ) ) ||
( V_169 || F_127 ( & V_59 ) ) ) )
F_143 ( V_162 ) ;
if ( V_59 . V_80 == V_82 ) {
F_144 ( V_167 ) ;
if ( V_166 ) {
F_63 ( V_162 ) ;
F_85 ( V_162 ) ;
F_145 ( V_162 ) ;
}
}
return 0 ;
V_170:
F_21 ( V_11 , V_168 ) ;
return error ;
}
int
F_146 (
struct V_9 * V_9 ,
T_8 V_163 ,
struct V_4 * V_162 ,
int V_166 )
{
return F_135 ( V_9 , V_163 , V_162 , V_166 , false ) ;
}
int
F_147 (
struct V_9 * V_9 ,
T_8 V_163 ,
struct V_4 * V_162 ,
int V_166 )
{
return F_135 ( V_9 , V_163 , V_162 , V_166 , true ) ;
}
static void
F_148 (
struct V_9 * V_9 ,
struct V_25 * V_18 ,
T_5 V_40 ,
T_6 V_41 )
{
struct V_12 * V_13 = F_6 ( V_9 ) -> V_14 ;
if ( F_35 ( V_13 ) || V_18 -> V_23 )
goto V_171;
ASSERT ( V_41 > 0 ) ;
ASSERT ( V_40 + V_41 <= V_18 -> V_26 + V_18 -> V_27 ) ;
V_18 -> V_27 = V_41 ;
V_18 -> V_26 = V_40 ;
F_149 ( & F_6 ( V_9 ) -> V_172 ) ;
if ( V_40 + V_41 > F_116 ( V_9 ) )
F_150 ( V_9 , V_40 + V_41 ) ;
F_151 ( & F_6 ( V_9 ) -> V_172 ) ;
if ( V_18 -> V_46 == V_120 )
V_18 -> V_23 = F_11 ( V_18 ) ;
V_171:
F_33 ( & V_18 -> V_49 ) ;
return;
}
STATIC void
F_152 (
struct V_173 * V_174 ,
T_5 V_40 ,
T_6 V_41 ,
void * V_175 )
{
struct V_9 * V_9 = F_153 ( V_174 -> V_176 ) ;
struct V_25 * V_18 = V_175 ;
F_154 ( F_6 ( V_9 ) , V_40 , V_41 ,
V_18 ? V_18 -> V_46 : 0 , NULL ) ;
if ( ! V_18 ) {
ASSERT ( V_40 + V_41 <= F_116 ( V_9 ) ) ;
return;
}
F_148 ( V_9 , V_18 , V_40 , V_41 ) ;
}
void
F_155 (
struct V_4 * V_5 ,
int V_127 )
{
struct V_25 * V_18 = V_5 -> V_21 ;
struct V_9 * V_9 = V_18 -> V_28 ;
T_6 V_41 = V_18 -> V_27 ;
ASSERT ( F_156 ( V_18 -> V_28 ) ) ;
if ( ! V_127 )
V_18 -> V_23 = - V_53 ;
F_149 ( & F_6 ( V_9 ) -> V_172 ) ;
if ( V_18 -> V_26 + V_41 > F_116 ( V_9 ) )
V_41 = F_116 ( V_9 ) - V_18 -> V_26 ;
F_151 ( & F_6 ( V_9 ) -> V_172 ) ;
F_148 ( V_9 , V_18 , V_18 -> V_26 , V_41 ) ;
}
void F_155 ( struct V_4 * V_5 , int V_127 ) { }
static inline T_6
F_157 (
struct V_9 * V_9 ,
struct V_173 * V_174 ,
struct V_177 * V_178 ,
T_5 V_40 ,
void (* F_158)( struct V_173 * V_174 ,
T_5 V_40 ,
T_6 V_41 ,
void * V_175 ) ,
int V_152 )
{
struct V_8 * V_179 ;
if ( F_156 ( V_9 ) )
return F_159 ( V_174 , V_9 , V_178 , V_40 ,
F_147 , F_158 , 0 ) ;
V_179 = F_5 ( V_9 ) ;
return F_160 ( V_174 , V_9 , V_179 , V_178 , V_40 ,
F_147 , F_158 , NULL , V_152 ) ;
}
STATIC T_6
F_161 (
struct V_173 * V_174 ,
struct V_177 * V_178 ,
T_5 V_40 )
{
struct V_9 * V_9 = V_174 -> V_176 -> V_180 -> V_141 ;
if ( F_162 ( V_178 ) == V_94 )
return F_157 ( V_9 , V_174 , V_178 , V_40 ,
F_152 , V_181 ) ;
return F_157 ( V_9 , V_174 , V_178 , V_40 , NULL , 0 ) ;
}
STATIC void
F_163 (
struct V_9 * V_9 ,
T_5 V_182 ,
T_5 V_183 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_7 V_144 ;
T_7 V_64 ;
int error ;
V_144 = F_43 ( V_11 -> V_14 , V_182 ) ;
V_64 = F_43 ( V_11 -> V_14 , V_183 ) ;
if ( V_64 <= V_144 )
return;
F_19 ( V_11 , V_43 ) ;
error = F_112 ( V_11 , V_144 ,
V_64 - V_144 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_111 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_143 ) ;
}
}
F_21 ( V_11 , V_43 ) ;
}
STATIC void
F_164 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_5 V_184 ,
unsigned V_125 )
{
T_5 V_185 ;
T_5 V_186 ;
T_5 V_187 ;
T_5 V_188 = V_184 & ( V_131 - 1 ) ;
T_5 V_189 = V_188 + V_125 ;
struct V_4 * V_5 , * V_6 ;
V_185 = ( V_184 >> V_156 ) << V_156 ;
ASSERT ( V_185 + V_188 == V_184 ) ;
V_6 = F_2 ( V_1 ) ;
V_186 = 0 ;
for ( V_5 = V_6 ; V_5 != V_6 || ! V_186 ;
V_5 = V_5 -> V_7 , V_186 = V_187 ,
V_185 += V_5 -> V_100 ) {
V_187 = V_186 + V_5 -> V_100 ;
if ( V_187 <= V_188 )
continue;
if ( V_186 >= V_189 )
break;
if ( ! F_4 ( V_5 ) )
continue;
if ( ! F_165 ( V_5 ) && V_185 < F_116 ( V_9 ) )
continue;
F_163 ( V_9 , V_185 ,
V_185 + V_5 -> V_100 ) ;
F_87 ( V_5 ) ;
F_166 ( V_5 ) ;
F_167 ( V_5 ) ;
F_168 ( V_5 ) ;
F_64 ( V_5 ) ;
}
}
STATIC int
F_169 (
struct V_190 * V_190 ,
struct V_159 * V_119 ,
T_5 V_184 ,
unsigned V_125 ,
unsigned V_152 ,
struct V_1 * * V_191 ,
void * * V_192 )
{
T_10 V_128 = V_184 >> V_156 ;
struct V_1 * V_1 ;
int V_193 ;
ASSERT ( V_125 <= V_131 ) ;
V_1 = F_170 ( V_119 , V_128 , V_152 ) ;
if ( ! V_1 )
return - V_194 ;
V_193 = F_171 ( V_1 , V_184 , V_125 , F_146 ) ;
if ( F_172 ( V_193 ) ) {
struct V_9 * V_9 = V_119 -> V_141 ;
T_3 V_42 = F_116 ( V_9 ) ;
F_164 ( V_9 , V_1 , V_184 , V_125 ) ;
F_71 ( V_1 ) ;
if ( V_184 + V_125 > V_42 ) {
T_6 V_182 = F_173 ( T_6 , V_184 , V_42 ) ;
F_174 ( V_9 , V_182 , V_184 + V_125 ) ;
}
F_175 ( V_1 ) ;
V_1 = NULL ;
}
* V_191 = V_1 ;
return V_193 ;
}
STATIC int
F_176 (
struct V_190 * V_190 ,
struct V_159 * V_119 ,
T_5 V_184 ,
unsigned V_125 ,
unsigned V_195 ,
struct V_1 * V_1 ,
void * V_192 )
{
int V_196 ;
ASSERT ( V_125 <= V_131 ) ;
V_196 = F_177 ( V_190 , V_119 , V_184 , V_125 , V_195 , V_1 , V_192 ) ;
if ( F_172 ( V_196 < V_125 ) ) {
struct V_9 * V_9 = V_119 -> V_141 ;
T_3 V_42 = F_116 ( V_9 ) ;
T_5 V_189 = V_184 + V_125 ;
if ( V_189 > V_42 ) {
if ( V_184 > V_42 )
V_42 = V_184 ;
F_163 ( V_9 , V_42 , V_189 ) ;
F_174 ( V_9 , V_42 , V_189 ) ;
}
}
return V_196 ;
}
STATIC T_8
F_178 (
struct V_159 * V_119 ,
T_8 V_197 )
{
struct V_9 * V_9 = (struct V_9 * ) V_119 -> V_141 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_179 ( F_6 ( V_9 ) ) ;
F_19 ( V_11 , V_198 ) ;
F_180 ( V_119 ) ;
F_21 ( V_11 , V_198 ) ;
return F_181 ( V_119 , V_197 , F_146 ) ;
}
STATIC int
F_182 (
struct V_190 * V_199 ,
struct V_1 * V_1 )
{
return F_183 ( V_1 , F_146 ) ;
}
STATIC int
F_184 (
struct V_190 * V_199 ,
struct V_159 * V_119 ,
struct V_200 * V_139 ,
unsigned V_201 )
{
return F_185 ( V_119 , V_139 , V_201 , F_146 ) ;
}
STATIC int
F_186 (
struct V_1 * V_1 )
{
struct V_159 * V_119 = V_1 -> V_119 ;
struct V_9 * V_9 = V_119 -> V_141 ;
T_5 V_123 ;
T_5 V_40 ;
int V_202 ;
struct V_203 * V_204 ;
if ( F_172 ( ! V_119 ) )
return ! F_187 ( V_1 ) ;
V_123 = F_116 ( V_9 ) ;
V_40 = F_93 ( V_1 ) ;
F_149 ( & V_119 -> V_205 ) ;
if ( F_90 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_40 < V_123 )
F_188 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_40 += 1 << V_9 -> V_62 ;
} while ( V_5 != V_6 );
}
V_204 = F_189 ( V_1 ) ;
V_202 = ! F_187 ( V_1 ) ;
F_151 ( & V_119 -> V_205 ) ;
if ( V_202 ) {
unsigned long V_152 ;
F_190 ( & V_119 -> V_206 , V_152 ) ;
if ( V_1 -> V_119 ) {
F_115 ( ! F_98 ( V_1 ) ) ;
F_191 ( V_1 , V_119 , V_204 ) ;
F_192 ( & V_119 -> V_207 ,
F_193 ( V_1 ) , V_208 ) ;
}
F_194 ( & V_119 -> V_206 , V_152 ) ;
}
F_195 ( V_204 ) ;
if ( V_202 )
F_196 ( V_119 -> V_141 , V_209 ) ;
return V_202 ;
}
