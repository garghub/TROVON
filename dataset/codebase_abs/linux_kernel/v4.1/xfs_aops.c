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
F_15 ( V_32 , 0 ) ;
return error ;
}
V_18 -> V_35 = V_32 ;
F_16 ( & V_18 -> V_28 -> V_36 -> V_37 . V_38 [ V_39 - 1 ] ,
1 , V_40 ) ;
F_17 ( & V_32 -> V_41 , V_42 ) ;
return 0 ;
}
STATIC int
F_18 (
struct V_10 * V_11 ,
struct V_31 * V_32 ,
T_2 V_43 ,
T_3 V_44 )
{
T_4 V_45 ;
F_19 ( V_11 , V_46 ) ;
V_45 = F_20 ( V_11 , V_43 + V_44 ) ;
if ( ! V_45 ) {
F_21 ( V_11 , V_46 ) ;
F_15 ( V_32 , 0 ) ;
return 0 ;
}
F_22 ( V_11 , V_43 , V_44 ) ;
V_11 -> V_29 . V_30 = V_45 ;
F_23 ( V_32 , V_11 , V_46 ) ;
F_24 ( V_32 , V_11 , V_47 ) ;
return F_25 ( V_32 , 0 ) ;
}
STATIC int
F_26 (
struct V_25 * V_18 )
{
struct V_10 * V_11 = F_6 ( V_18 -> V_28 ) ;
struct V_31 * V_32 = V_18 -> V_35 ;
F_27 ( & V_32 -> V_41 , V_42 ) ;
F_28 ( & F_29 ( V_11 ) -> V_36 -> V_37 . V_38 [ V_39 - 1 ] ,
0 , 1 , V_40 ) ;
return F_18 ( V_11 , V_32 , V_18 -> V_26 , V_18 -> V_27 ) ;
}
STATIC void
F_30 (
struct V_25 * V_18 )
{
if ( F_31 ( & V_18 -> V_48 ) ) {
struct V_12 * V_13 = F_6 ( V_18 -> V_28 ) -> V_14 ;
if ( V_18 -> V_49 == V_50 )
F_32 ( V_13 -> V_51 , & V_18 -> V_52 ) ;
else if ( V_18 -> V_35 )
F_32 ( V_13 -> V_53 , & V_18 -> V_52 ) ;
else
F_8 ( V_18 ) ;
}
}
STATIC void
F_33 (
struct V_54 * V_55 )
{
T_1 * V_18 = F_34 ( V_55 , T_1 , V_52 ) ;
struct V_10 * V_11 = F_6 ( V_18 -> V_28 ) ;
int error = 0 ;
if ( F_35 ( V_11 -> V_14 ) ) {
V_18 -> V_23 = - V_56 ;
goto V_57;
}
if ( V_18 -> V_23 )
goto V_57;
if ( V_18 -> V_49 == V_50 ) {
error = F_36 ( V_11 , V_18 -> V_26 ,
V_18 -> V_27 ) ;
} else if ( V_18 -> V_35 ) {
error = F_26 ( V_18 ) ;
} else {
ASSERT ( ! F_10 ( V_18 ) ) ;
}
V_57:
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
V_18 = F_38 ( V_24 , V_58 ) ;
F_39 ( & V_18 -> V_48 , 1 ) ;
V_18 -> V_23 = 0 ;
V_18 -> V_59 = NULL ;
V_18 -> V_49 = type ;
V_18 -> V_28 = V_9 ;
V_18 -> V_20 = NULL ;
V_18 -> V_60 = NULL ;
V_18 -> V_26 = 0 ;
V_18 -> V_27 = 0 ;
V_18 -> V_35 = NULL ;
F_40 ( & V_18 -> V_52 , F_33 ) ;
return V_18 ;
}
STATIC int
F_41 (
struct V_9 * V_9 ,
T_5 V_43 ,
struct V_61 * V_62 ,
int type ,
int V_63 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_64 = 1 << V_9 -> V_65 ;
T_7 V_66 , V_67 ;
int error = 0 ;
int V_68 = V_69 ;
int V_70 = 1 ;
if ( F_35 ( V_13 ) )
return - V_56 ;
if ( type == V_50 )
V_68 |= V_71 ;
if ( ! F_42 ( V_11 , V_72 ) ) {
if ( V_63 )
return - V_73 ;
F_19 ( V_11 , V_72 ) ;
}
ASSERT ( V_11 -> V_29 . V_74 != V_75 ||
( V_11 -> V_76 . V_77 & V_78 ) ) ;
ASSERT ( V_43 <= V_13 -> V_79 -> V_80 ) ;
if ( V_43 + V_64 > V_13 -> V_79 -> V_80 )
V_64 = V_13 -> V_79 -> V_80 - V_43 ;
V_67 = F_43 ( V_13 , ( V_81 ) V_43 + V_64 ) ;
V_66 = F_44 ( V_13 , V_43 ) ;
error = F_45 ( V_11 , V_66 , V_67 - V_66 ,
V_62 , & V_70 , V_68 ) ;
F_21 ( V_11 , V_72 ) ;
if ( error )
return error ;
if ( type == V_82 &&
( ! V_70 || F_46 ( V_62 -> V_83 ) ) ) {
error = F_47 ( V_11 , V_43 , V_62 ) ;
if ( ! error )
F_48 ( V_11 , V_43 , V_64 , type , V_62 ) ;
return error ;
}
#ifdef F_49
if ( type == V_50 ) {
ASSERT ( V_70 ) ;
ASSERT ( V_62 -> V_83 != V_84 ) ;
ASSERT ( V_62 -> V_83 != V_85 ) ;
}
#endif
if ( V_70 )
F_50 ( V_11 , V_43 , V_64 , type , V_62 ) ;
return 0 ;
}
STATIC int
F_51 (
struct V_9 * V_9 ,
struct V_61 * V_62 ,
T_2 V_43 )
{
V_43 >>= V_9 -> V_65 ;
return V_43 >= V_62 -> V_86 &&
V_43 < V_62 -> V_86 + V_62 -> V_87 ;
}
STATIC void
F_52 (
struct V_88 * V_88 ,
int error )
{
T_1 * V_18 = V_88 -> V_89 ;
ASSERT ( F_53 ( & V_88 -> V_90 ) >= 1 ) ;
V_18 -> V_23 = F_54 ( V_91 , & V_88 -> V_92 ) ? 0 : error ;
V_88 -> V_89 = NULL ;
V_88 -> V_93 = NULL ;
F_55 ( V_88 ) ;
F_30 ( V_18 ) ;
}
STATIC void
F_56 (
struct V_94 * V_95 ,
T_1 * V_18 ,
struct V_88 * V_88 )
{
F_57 ( & V_18 -> V_48 ) ;
V_88 -> V_89 = V_18 ;
V_88 -> V_93 = F_52 ;
F_58 ( V_95 -> V_96 == V_97 ? V_98 : V_99 , V_88 ) ;
}
STATIC struct V_88 *
F_59 (
struct V_4 * V_5 )
{
int V_100 = F_60 ( V_5 -> V_101 ) ;
struct V_88 * V_88 = F_61 ( V_102 , V_100 ) ;
ASSERT ( V_88 -> V_89 == NULL ) ;
V_88 -> V_103 . V_104 = V_5 -> V_105 * ( V_5 -> V_106 >> 9 ) ;
V_88 -> V_107 = V_5 -> V_101 ;
return V_88 ;
}
STATIC void
F_62 (
struct V_4 * V_5 )
{
ASSERT ( F_63 ( V_5 ) ) ;
ASSERT ( F_64 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_65 ( V_5 ) ;
F_66 ( V_5 ) ;
F_67 ( V_5 ) ;
}
STATIC void
F_68 (
struct V_1 * V_1 ,
int V_108 ,
int V_109 )
{
ASSERT ( F_69 ( V_1 ) ) ;
ASSERT ( ! F_70 ( V_1 ) ) ;
if ( V_108 ) {
F_71 ( V_1 ) ;
F_72 ( V_1 ) ;
} else
F_73 ( V_1 ) ;
F_74 ( V_1 ) ;
if ( ! V_109 )
F_75 ( V_1 ) ;
}
static inline int F_76 ( struct V_88 * V_88 , struct V_4 * V_5 )
{
return F_77 ( V_88 , V_5 -> V_110 , V_5 -> V_106 , F_78 ( V_5 ) ) ;
}
STATIC void
F_79 (
struct V_94 * V_95 ,
T_1 * V_18 ,
int V_111 )
{
T_1 * V_6 = V_18 ;
T_1 * V_19 ;
struct V_4 * V_5 ;
struct V_88 * V_88 ;
T_8 V_112 = 0 ;
do {
V_19 = V_18 -> V_59 ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 )
F_62 ( V_5 ) ;
} while ( ( V_18 = V_19 ) != NULL );
V_18 = V_6 ;
do {
V_19 = V_18 -> V_59 ;
V_88 = NULL ;
if ( V_111 ) {
V_18 -> V_23 = V_111 ;
F_30 ( V_18 ) ;
continue;
}
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 ) {
if ( ! V_88 ) {
V_113:
V_88 = F_59 ( V_5 ) ;
} else if ( V_5 -> V_105 != V_112 + 1 ) {
F_56 ( V_95 , V_18 , V_88 ) ;
goto V_113;
}
if ( F_76 ( V_88 , V_5 ) != V_5 -> V_106 ) {
F_56 ( V_95 , V_18 , V_88 ) ;
goto V_113;
}
V_112 = V_5 -> V_105 ;
}
if ( V_88 )
F_56 ( V_95 , V_18 , V_88 ) ;
F_30 ( V_18 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_80 (
T_1 * V_18 )
{
T_1 * V_19 ;
struct V_4 * V_5 , * V_114 ;
do {
V_19 = V_18 -> V_59 ;
V_5 = V_18 -> V_20 ;
do {
V_114 = V_5 -> V_21 ;
F_81 ( V_5 ) ;
if ( V_18 -> V_49 == V_50 )
F_82 ( V_5 ) ;
F_83 ( V_5 ) ;
} while ( ( V_5 = V_114 ) != NULL );
F_9 ( V_18 , V_24 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_84 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_2 V_43 ,
unsigned int type ,
T_1 * * V_115 ,
int V_116 )
{
T_1 * V_18 = * V_115 ;
if ( ! V_18 || V_116 || type != V_18 -> V_49 ) {
T_1 * V_117 = * V_115 ;
V_18 = F_37 ( V_9 , type ) ;
V_18 -> V_26 = V_43 ;
V_18 -> V_20 = V_5 ;
V_18 -> V_60 = V_5 ;
if ( V_117 )
V_117 -> V_59 = V_18 ;
* V_115 = V_18 ;
} else {
V_18 -> V_60 -> V_21 = V_5 ;
V_18 -> V_60 = V_5 ;
}
V_5 -> V_21 = NULL ;
V_18 -> V_27 += V_5 -> V_106 ;
}
STATIC void
F_85 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_61 * V_62 ,
T_2 V_43 )
{
T_8 V_118 ;
struct V_12 * V_119 = F_6 ( V_9 ) -> V_14 ;
T_2 V_120 = F_86 ( V_119 , V_62 -> V_86 ) ;
T_9 V_121 = F_87 ( F_6 ( V_9 ) , V_62 -> V_83 ) ;
ASSERT ( V_62 -> V_83 != V_84 ) ;
ASSERT ( V_62 -> V_83 != V_85 ) ;
V_118 = ( V_121 >> ( V_9 -> V_65 - V_122 ) ) +
( ( V_43 - V_120 ) >> V_9 -> V_65 ) ;
ASSERT ( V_118 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_105 = V_118 ;
F_88 ( V_5 ) ;
}
STATIC void
F_89 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_61 * V_62 ,
T_2 V_43 )
{
ASSERT ( V_62 -> V_83 != V_84 ) ;
ASSERT ( V_62 -> V_83 != V_85 ) ;
F_85 ( V_9 , V_5 , V_62 , V_43 ) ;
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
if ( F_70 ( V_1 ) )
return false ;
if ( ! V_1 -> V_124 )
return false ;
if ( ! F_93 ( V_1 ) )
return false ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) ) {
if ( type == V_50 )
return true ;
} else if ( F_4 ( V_5 ) ) {
if ( type == V_82 )
return true ;
} else if ( F_94 ( V_5 ) && F_63 ( V_5 ) ) {
if ( type == V_125 )
return true ;
}
if ( ! V_123 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC int
F_95 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_5 V_126 ,
struct V_61 * V_62 ,
T_1 * * V_127 ,
struct V_94 * V_95 )
{
struct V_4 * V_5 , * V_6 ;
T_2 V_128 ;
unsigned long V_129 ;
unsigned int type ;
int V_130 , V_131 ;
int V_64 = 0 , V_57 = 0 , V_132 = 1 ;
T_2 V_43 = F_96 ( V_1 ) ;
if ( V_1 -> V_133 != V_126 )
goto V_111;
if ( ! F_97 ( V_1 ) )
goto V_111;
if ( F_70 ( V_1 ) )
goto V_134;
if ( V_1 -> V_124 != V_9 -> V_135 )
goto V_134;
if ( ! F_92 ( V_1 , ( * V_127 ) -> V_49 , false ) )
goto V_134;
V_128 = F_98 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode)) ;
if ( ! F_51 ( V_9 , V_62 , V_128 ) )
goto V_134;
V_130 = 1 << V_9 -> V_65 ;
V_129 = F_98 (unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE) ;
V_129 = V_129 ? F_99 ( V_129 , V_130 ) : V_136 ;
V_131 = V_129 / V_130 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( V_43 >= V_128 )
break;
if ( ! F_100 ( V_5 ) )
V_132 = 0 ;
if ( ! ( F_101 ( V_1 ) || F_100 ( V_5 ) ) ) {
V_57 = 1 ;
break;
}
if ( F_3 ( V_5 ) || F_4 ( V_5 ) ||
F_63 ( V_5 ) ) {
if ( F_3 ( V_5 ) )
type = V_50 ;
else if ( F_4 ( V_5 ) )
type = V_82 ;
else
type = V_125 ;
ASSERT ( F_51 ( V_9 , V_62 , V_43 ) ) ;
F_102 ( V_5 ) ;
if ( type != V_125 )
F_89 ( V_9 , V_5 , V_62 , V_43 ) ;
F_84 ( V_9 , V_5 , V_43 , type ,
V_127 , V_57 ) ;
V_131 -- ;
V_64 ++ ;
} else {
V_57 = 1 ;
break;
}
} while ( V_43 += V_130 , ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_132 && V_5 == V_6 )
F_103 ( V_1 ) ;
if ( V_64 ) {
if ( -- V_95 -> V_137 <= 0 &&
V_95 -> V_96 == V_138 )
V_57 = 1 ;
}
F_68 ( V_1 , ! V_131 , V_64 ) ;
return V_57 ;
V_134:
F_74 ( V_1 ) ;
V_111:
return 1 ;
}
STATIC void
F_104 (
struct V_9 * V_9 ,
T_10 V_126 ,
struct V_61 * V_62 ,
T_1 * * V_127 ,
struct V_94 * V_95 ,
T_10 V_139 )
{
struct V_140 V_141 ;
int V_57 = 0 , V_142 ;
F_105 ( & V_141 , 0 ) ;
while ( ! V_57 && V_126 <= V_139 ) {
unsigned V_130 = F_98 ( T_10 , V_143 , V_139 - V_126 + 1 ) ;
if ( ! F_106 ( & V_141 , V_9 -> V_135 , V_126 , V_130 ) )
break;
for ( V_142 = 0 ; V_142 < F_107 ( & V_141 ) ; V_142 ++ ) {
V_57 = F_95 ( V_9 , V_141 . V_144 [ V_142 ] , V_126 ++ ,
V_62 , V_127 , V_95 ) ;
if ( V_57 )
break;
}
F_108 ( & V_141 ) ;
F_109 () ;
}
}
STATIC void
F_110 (
struct V_1 * V_1 ,
unsigned int V_43 ,
unsigned int V_145 )
{
F_111 ( V_1 -> V_124 -> V_146 , V_1 , V_43 ,
V_145 ) ;
F_112 ( V_1 , V_43 , V_145 ) ;
}
STATIC void
F_113 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_124 -> V_146 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_5 V_43 = F_96 ( V_1 ) ;
if ( ! F_92 ( V_1 , V_82 , true ) )
goto V_147;
if ( F_35 ( V_11 -> V_14 ) )
goto V_147;
F_114 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_148 , V_43 ) ;
F_19 ( V_11 , V_46 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_7 V_149 ;
if ( ! F_4 ( V_5 ) )
goto V_150;
V_149 = F_44 ( V_11 -> V_14 , V_43 ) ;
error = F_115 ( V_11 , V_149 , 1 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_114 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_150:
V_43 += 1 << V_9 -> V_65 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_21 ( V_11 , V_46 ) ;
V_147:
F_110 ( V_1 , 0 , V_136 ) ;
return;
}
STATIC int
F_116 (
struct V_1 * V_1 ,
struct V_94 * V_95 )
{
struct V_9 * V_9 = V_1 -> V_124 -> V_146 ;
struct V_4 * V_5 , * V_6 ;
struct V_61 V_62 ;
T_1 * V_18 = NULL , * V_151 = NULL ;
T_5 V_43 ;
unsigned int type ;
T_11 V_128 ;
T_10 V_152 , V_153 ;
T_6 V_130 ;
int V_154 , V_155 = 0 , V_132 = 1 ;
int V_64 = 0 ;
int V_63 = 0 ;
F_117 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_93 ( V_1 ) ) ;
if ( F_118 ( ( V_156 -> V_157 & ( V_158 | V_159 ) ) ==
V_158 ) )
goto V_160;
if ( F_118 ( V_156 -> V_157 & V_42 ) )
goto V_160;
V_43 = F_119 ( V_9 ) ;
V_152 = V_43 >> V_161 ;
V_153 = ( V_43 - 1 ) >> V_161 ;
if ( V_1 -> V_133 < V_152 )
V_128 = ( T_2 ) ( V_1 -> V_133 + 1 ) << V_161 ;
else {
unsigned V_162 = V_43 & ( V_136 - 1 ) ;
if ( V_1 -> V_133 > V_152 ||
( V_1 -> V_133 == V_152 && V_162 == 0 ) )
goto V_160;
F_120 ( V_1 , V_162 , V_136 ) ;
V_128 = V_43 ;
}
V_130 = 1 << V_9 -> V_65 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_43 = F_96 ( V_1 ) ;
type = V_125 ;
if ( V_95 -> V_96 == V_138 )
V_63 = 1 ;
do {
int V_163 = 0 ;
if ( V_43 >= V_128 )
break;
if ( ! F_100 ( V_5 ) )
V_132 = 0 ;
if ( ! F_63 ( V_5 ) && F_100 ( V_5 ) ) {
V_155 = 0 ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( type != V_50 ) {
type = V_50 ;
V_155 = 0 ;
}
} else if ( F_4 ( V_5 ) ) {
if ( type != V_82 ) {
type = V_82 ;
V_155 = 0 ;
}
} else if ( F_100 ( V_5 ) ) {
if ( type != V_125 ) {
type = V_125 ;
V_155 = 0 ;
}
} else {
if ( F_101 ( V_1 ) )
ASSERT ( F_63 ( V_5 ) ) ;
V_155 = 0 ;
continue;
}
if ( V_155 )
V_155 = F_51 ( V_9 , & V_62 , V_43 ) ;
if ( ! V_155 ) {
V_163 = 1 ;
V_154 = F_41 ( V_9 , V_43 , & V_62 , type ,
V_63 ) ;
if ( V_154 )
goto error;
V_155 = F_51 ( V_9 , & V_62 , V_43 ) ;
}
if ( V_155 ) {
F_102 ( V_5 ) ;
if ( type != V_125 )
F_89 ( V_9 , V_5 , & V_62 , V_43 ) ;
F_84 ( V_9 , V_5 , V_43 , type , & V_18 ,
V_163 ) ;
V_64 ++ ;
}
if ( ! V_151 )
V_151 = V_18 ;
} while ( V_43 += V_130 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_132 && V_5 == V_6 )
F_103 ( V_1 ) ;
F_68 ( V_1 , 1 , V_64 ) ;
if ( ! V_18 )
return 0 ;
ASSERT ( V_151 ) ;
if ( V_155 ) {
T_2 V_152 ;
V_152 = V_62 . V_86 + V_62 . V_87 ;
V_152 <<= V_9 -> V_65 ;
V_152 = ( V_152 - 1 ) >> V_161 ;
if ( V_152 > V_153 )
V_152 = V_153 ;
F_104 ( V_9 , V_1 -> V_133 + 1 , & V_62 , & V_18 ,
V_95 , V_152 ) ;
}
V_154 = 0 ;
if ( V_18 -> V_49 != V_50 && F_10 ( V_18 ) )
V_154 = F_11 ( V_18 ) ;
F_79 ( V_95 , V_151 , V_154 ) ;
return 0 ;
error:
if ( V_151 )
F_80 ( V_151 ) ;
if ( V_154 == - V_73 )
goto V_160;
F_113 ( V_1 ) ;
F_121 ( V_1 ) ;
F_74 ( V_1 ) ;
return V_154 ;
V_160:
F_122 ( V_95 , V_1 ) ;
F_74 ( V_1 ) ;
return 0 ;
}
STATIC int
F_123 (
struct V_164 * V_124 ,
struct V_94 * V_95 )
{
F_124 ( F_6 ( V_124 -> V_146 ) , V_165 ) ;
return F_125 ( V_124 , V_95 ) ;
}
STATIC int
F_126 (
struct V_1 * V_1 ,
T_12 V_166 )
{
int V_2 , V_3 ;
F_127 ( V_1 -> V_124 -> V_146 , V_1 , 0 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_118 ( V_2 ) )
return 0 ;
if ( F_118 ( V_3 ) )
return 0 ;
return F_128 ( V_1 ) ;
}
static void
F_129 (
struct V_9 * V_9 ,
struct V_4 * V_167 ,
struct V_61 * V_62 ,
T_2 V_43 )
{
struct V_25 * V_18 ;
T_2 V_44 = V_167 -> V_106 ;
int type ;
if ( F_130 ( V_62 ) )
type = V_50 ;
else
type = V_125 ;
F_131 ( F_6 ( V_9 ) , V_43 , V_44 , type , V_62 ) ;
if ( V_167 -> V_21 ) {
V_18 = V_167 -> V_21 ;
ASSERT ( V_18 -> V_27 > 0 ) ;
ASSERT ( V_43 >= V_18 -> V_26 ) ;
if ( V_43 + V_44 > V_18 -> V_26 + V_18 -> V_27 )
V_18 -> V_27 = V_43 - V_18 -> V_26 + V_44 ;
if ( type == V_50 && type != V_18 -> V_49 )
V_18 -> V_49 = V_50 ;
F_132 ( F_6 ( V_9 ) , V_18 -> V_26 ,
V_18 -> V_27 , V_18 -> V_49 ,
V_62 ) ;
} else if ( type == V_50 ||
V_43 + V_44 > F_119 ( V_9 ) ) {
V_18 = F_37 ( V_9 , type ) ;
V_18 -> V_26 = V_43 ;
V_18 -> V_27 = V_44 ;
V_167 -> V_21 = V_18 ;
F_133 ( V_167 ) ;
F_134 ( F_6 ( V_9 ) , V_43 , V_44 , type ,
V_62 ) ;
} else {
F_135 ( F_6 ( V_9 ) , V_43 , V_44 , type ,
V_62 ) ;
}
}
static void
F_136 (
struct V_9 * V_9 ,
T_8 V_168 ,
struct V_4 * V_167 ,
struct V_61 * V_62 ,
T_2 V_43 ,
T_6 V_44 )
{
T_2 V_169 ;
V_169 = V_62 -> V_86 + V_62 -> V_87 - V_168 ;
V_169 <<= V_9 -> V_65 ;
ASSERT ( V_169 > 0 ) ;
if ( V_169 > V_44 )
V_169 = V_44 ;
if ( V_43 < F_119 ( V_9 ) &&
V_43 + V_169 >= F_119 ( V_9 ) ) {
V_169 = F_137 ( F_119 ( V_9 ) - V_43 ,
1 << V_9 -> V_65 ) ;
}
if ( V_169 > V_170 )
V_169 = V_170 ;
V_167 -> V_106 = V_169 ;
}
STATIC int
F_138 (
struct V_9 * V_9 ,
T_8 V_168 ,
struct V_4 * V_167 ,
int V_171 ,
int V_172 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_7 V_66 , V_67 ;
int error = 0 ;
int V_173 = 0 ;
struct V_61 V_62 ;
int V_70 = 1 ;
T_2 V_43 ;
T_6 V_44 ;
int V_174 = 0 ;
if ( F_35 ( V_13 ) )
return - V_56 ;
V_43 = ( T_2 ) V_168 << V_9 -> V_65 ;
ASSERT ( V_167 -> V_106 >= ( 1 << V_9 -> V_65 ) ) ;
V_44 = V_167 -> V_106 ;
if ( ! V_171 && V_172 && V_43 >= F_119 ( V_9 ) )
return 0 ;
if ( V_171 && ! V_172 ) {
V_173 = V_46 ;
F_19 ( V_11 , V_173 ) ;
} else {
V_173 = F_139 ( V_11 ) ;
}
ASSERT ( V_43 <= V_13 -> V_79 -> V_80 ) ;
if ( V_43 + V_44 > V_13 -> V_79 -> V_80 )
V_44 = V_13 -> V_79 -> V_80 - V_43 ;
V_67 = F_43 ( V_13 , ( V_81 ) V_43 + V_44 ) ;
V_66 = F_44 ( V_13 , V_43 ) ;
error = F_45 ( V_11 , V_66 , V_67 - V_66 ,
& V_62 , & V_70 , V_69 ) ;
if ( error )
goto V_175;
if ( V_171 &&
( ! V_70 ||
( V_62 . V_83 == V_84 ||
V_62 . V_83 == V_85 ) ) ) {
if ( V_172 || F_140 ( V_11 ) ) {
F_21 ( V_11 , V_173 ) ;
error = F_141 ( V_11 , V_43 , V_44 ,
& V_62 , V_70 ) ;
if ( error )
return error ;
V_174 = 1 ;
} else {
if ( V_70 && V_62 . V_83 == V_84 )
V_174 = 1 ;
error = F_142 ( V_11 , V_43 , V_44 , & V_62 ) ;
if ( error )
goto V_175;
F_21 ( V_11 , V_173 ) ;
}
F_143 ( V_11 , V_43 , V_44 ,
F_130 ( & V_62 ) ? V_50
: V_82 , & V_62 ) ;
} else if ( V_70 ) {
F_144 ( V_11 , V_43 , V_44 ,
F_130 ( & V_62 ) ? V_50
: V_125 , & V_62 ) ;
F_21 ( V_11 , V_173 ) ;
} else {
F_145 ( V_11 , V_43 , V_44 ) ;
goto V_175;
}
if ( V_172 || V_44 > ( 1 << V_9 -> V_65 ) )
F_136 ( V_9 , V_168 , V_167 ,
& V_62 , V_43 , V_44 ) ;
if ( V_62 . V_83 != V_84 &&
V_62 . V_83 != V_85 &&
( V_171 || ! F_130 ( & V_62 ) ) ) {
F_85 ( V_9 , V_167 , & V_62 , V_43 ) ;
if ( F_130 ( & V_62 ) )
F_82 ( V_167 ) ;
if ( V_171 && V_172 )
F_129 ( V_9 , V_167 , & V_62 , V_43 ) ;
}
V_167 -> V_101 = F_5 ( V_9 ) ;
if ( V_171 &&
( ( ! F_63 ( V_167 ) && ! F_100 ( V_167 ) ) ||
( V_43 >= F_119 ( V_9 ) ) ||
( V_174 || F_130 ( & V_62 ) ) ) )
F_146 ( V_167 ) ;
if ( V_62 . V_83 == V_85 ) {
F_147 ( V_172 ) ;
if ( V_171 ) {
F_66 ( V_167 ) ;
F_88 ( V_167 ) ;
F_148 ( V_167 ) ;
}
}
return 0 ;
V_175:
F_21 ( V_11 , V_173 ) ;
return error ;
}
int
F_149 (
struct V_9 * V_9 ,
T_8 V_168 ,
struct V_4 * V_167 ,
int V_171 )
{
return F_138 ( V_9 , V_168 , V_167 , V_171 , 0 ) ;
}
STATIC int
F_150 (
struct V_9 * V_9 ,
T_8 V_168 ,
struct V_4 * V_167 ,
int V_171 )
{
return F_138 ( V_9 , V_168 , V_167 , V_171 , 1 ) ;
}
STATIC void
F_151 (
struct V_176 * V_177 ,
T_5 V_43 ,
T_6 V_44 ,
void * V_178 )
{
struct V_9 * V_9 = F_152 ( V_177 -> V_179 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_25 * V_18 = V_178 ;
F_153 ( V_11 , V_43 , V_44 ,
V_18 ? V_18 -> V_49 : 0 , NULL ) ;
if ( ! V_18 ) {
ASSERT ( V_43 + V_44 <= F_119 ( V_9 ) ) ;
return;
}
if ( F_35 ( V_13 ) )
goto V_180;
ASSERT ( V_44 > 0 ) ;
ASSERT ( V_43 + V_44 <= V_18 -> V_26 + V_18 -> V_27 ) ;
V_18 -> V_27 = V_44 ;
V_18 -> V_26 = V_43 ;
F_154 ( & V_11 -> V_181 ) ;
if ( V_43 + V_44 > F_119 ( V_9 ) )
F_155 ( V_9 , V_43 + V_44 ) ;
F_156 ( & V_11 -> V_181 ) ;
if ( V_18 -> V_49 == V_125 )
V_18 -> V_23 = F_11 ( V_18 ) ;
V_180:
F_33 ( & V_18 -> V_52 ) ;
return;
}
STATIC T_6
F_157 (
struct V_176 * V_177 ,
struct V_182 * V_183 ,
T_5 V_43 )
{
struct V_9 * V_9 = V_177 -> V_179 -> V_184 -> V_146 ;
struct V_8 * V_185 = F_5 ( V_9 ) ;
if ( F_158 ( V_183 ) == V_99 ) {
return F_159 ( V_177 , V_9 , V_185 , V_183 , V_43 ,
F_150 ,
F_151 , NULL ,
V_186 ) ;
}
return F_159 ( V_177 , V_9 , V_185 , V_183 , V_43 ,
F_150 , NULL , NULL , 0 ) ;
}
STATIC void
F_160 (
struct V_9 * V_9 ,
T_5 V_187 ,
T_5 V_188 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_7 V_149 ;
T_7 V_67 ;
int error ;
V_149 = F_43 ( V_11 -> V_14 , V_187 ) ;
V_67 = F_43 ( V_11 -> V_14 , V_188 ) ;
if ( V_67 <= V_149 )
return;
F_19 ( V_11 , V_46 ) ;
error = F_115 ( V_11 , V_149 ,
V_67 - V_149 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_114 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_148 ) ;
}
}
F_21 ( V_11 , V_46 ) ;
}
STATIC void
F_161 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_5 V_189 ,
unsigned V_130 )
{
T_5 V_190 ;
T_5 V_191 ;
T_5 V_192 ;
T_5 V_193 = V_189 & ( V_136 - 1 ) ;
T_5 V_194 = V_193 + V_130 ;
struct V_4 * V_5 , * V_6 ;
V_190 = ( V_189 >> V_161 ) << V_161 ;
ASSERT ( V_190 + V_193 == V_189 ) ;
V_6 = F_2 ( V_1 ) ;
V_191 = 0 ;
for ( V_5 = V_6 ; V_5 != V_6 || ! V_191 ;
V_5 = V_5 -> V_7 , V_191 = V_192 ,
V_190 += V_5 -> V_106 ) {
V_192 = V_191 + V_5 -> V_106 ;
if ( V_192 <= V_193 )
continue;
if ( V_191 >= V_194 )
break;
if ( ! F_4 ( V_5 ) )
continue;
if ( ! F_162 ( V_5 ) && V_190 < F_119 ( V_9 ) )
continue;
F_160 ( V_9 , V_190 ,
V_190 + V_5 -> V_106 ) ;
F_90 ( V_5 ) ;
F_163 ( V_5 ) ;
F_164 ( V_5 ) ;
F_165 ( V_5 ) ;
F_67 ( V_5 ) ;
}
}
STATIC int
F_166 (
struct V_195 * V_195 ,
struct V_164 * V_124 ,
T_5 V_189 ,
unsigned V_130 ,
unsigned V_157 ,
struct V_1 * * V_196 ,
void * * V_197 )
{
T_10 V_133 = V_189 >> V_161 ;
struct V_1 * V_1 ;
int V_198 ;
ASSERT ( V_130 <= V_136 ) ;
V_1 = F_167 ( V_124 , V_133 , V_157 ) ;
if ( ! V_1 )
return - V_199 ;
V_198 = F_168 ( V_1 , V_189 , V_130 , F_149 ) ;
if ( F_169 ( V_198 ) ) {
struct V_9 * V_9 = V_124 -> V_146 ;
T_3 V_45 = F_119 ( V_9 ) ;
F_161 ( V_9 , V_1 , V_189 , V_130 ) ;
F_74 ( V_1 ) ;
if ( V_189 + V_130 > V_45 ) {
T_6 V_187 = F_170 ( T_6 , V_189 , V_45 ) ;
F_171 ( V_9 , V_187 , V_189 + V_130 ) ;
}
F_172 ( V_1 ) ;
V_1 = NULL ;
}
* V_196 = V_1 ;
return V_198 ;
}
STATIC int
F_173 (
struct V_195 * V_195 ,
struct V_164 * V_124 ,
T_5 V_189 ,
unsigned V_130 ,
unsigned V_200 ,
struct V_1 * V_1 ,
void * V_197 )
{
int V_201 ;
ASSERT ( V_130 <= V_136 ) ;
V_201 = F_174 ( V_195 , V_124 , V_189 , V_130 , V_200 , V_1 , V_197 ) ;
if ( F_169 ( V_201 < V_130 ) ) {
struct V_9 * V_9 = V_124 -> V_146 ;
T_3 V_45 = F_119 ( V_9 ) ;
T_5 V_194 = V_189 + V_130 ;
if ( V_194 > V_45 ) {
if ( V_189 > V_45 )
V_45 = V_189 ;
F_160 ( V_9 , V_45 , V_194 ) ;
F_171 ( V_9 , V_45 , V_194 ) ;
}
}
return V_201 ;
}
STATIC T_8
F_175 (
struct V_164 * V_124 ,
T_8 V_202 )
{
struct V_9 * V_9 = (struct V_9 * ) V_124 -> V_146 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_176 ( F_6 ( V_9 ) ) ;
F_19 ( V_11 , V_203 ) ;
F_177 ( V_124 ) ;
F_21 ( V_11 , V_203 ) ;
return F_178 ( V_124 , V_202 , F_149 ) ;
}
STATIC int
F_179 (
struct V_195 * V_204 ,
struct V_1 * V_1 )
{
return F_180 ( V_1 , F_149 ) ;
}
STATIC int
F_181 (
struct V_195 * V_204 ,
struct V_164 * V_124 ,
struct V_205 * V_144 ,
unsigned V_206 )
{
return F_182 ( V_124 , V_144 , V_206 , F_149 ) ;
}
STATIC int
F_183 (
struct V_1 * V_1 )
{
struct V_164 * V_124 = V_1 -> V_124 ;
struct V_9 * V_9 = V_124 -> V_146 ;
T_5 V_128 ;
T_5 V_43 ;
int V_207 ;
if ( F_169 ( ! V_124 ) )
return ! F_184 ( V_1 ) ;
V_128 = F_119 ( V_9 ) ;
V_43 = F_96 ( V_1 ) ;
F_154 ( & V_124 -> V_208 ) ;
if ( F_93 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_43 < V_128 )
F_185 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_43 += 1 << V_9 -> V_65 ;
} while ( V_5 != V_6 );
}
V_207 = ! F_184 ( V_1 ) ;
F_156 ( & V_124 -> V_208 ) ;
if ( V_207 ) {
unsigned long V_157 ;
F_186 ( & V_124 -> V_209 , V_157 ) ;
if ( V_1 -> V_124 ) {
F_118 ( ! F_101 ( V_1 ) ) ;
F_187 ( V_1 , V_124 ) ;
F_188 ( & V_124 -> V_210 ,
F_189 ( V_1 ) , V_211 ) ;
}
F_190 ( & V_124 -> V_209 , V_157 ) ;
F_191 ( V_124 -> V_146 , V_212 ) ;
}
return V_207 ;
}
