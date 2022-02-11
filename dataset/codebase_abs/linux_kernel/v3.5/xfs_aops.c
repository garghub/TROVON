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
if ( V_18 -> V_24 ) {
if ( V_18 -> V_25 ) {
F_9 ( V_18 -> V_24 , V_18 -> V_23 ?
V_18 -> V_23 : V_18 -> V_26 , 0 ) ;
}
F_10 ( V_18 -> V_27 ) ;
}
F_11 ( V_18 , V_28 ) ;
}
static inline bool F_12 ( struct V_29 * V_18 )
{
return V_18 -> V_30 + V_18 -> V_31 >
F_6 ( V_18 -> V_27 ) -> V_32 . V_33 ;
}
STATIC int
F_13 (
struct V_29 * V_18 )
{
struct V_12 * V_13 = F_6 ( V_18 -> V_27 ) -> V_14 ;
struct V_34 * V_35 ;
int error ;
V_35 = F_14 ( V_13 , V_36 ) ;
error = F_15 ( V_35 , 0 , F_16 ( V_13 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_17 ( V_35 , 0 ) ;
return error ;
}
V_18 -> V_37 = V_35 ;
F_18 ( & V_35 -> V_38 , V_39 ) ;
return 0 ;
}
STATIC int
F_19 (
struct V_29 * V_18 )
{
struct V_10 * V_11 = F_6 ( V_18 -> V_27 ) ;
struct V_34 * V_35 = V_18 -> V_37 ;
T_2 V_40 ;
F_20 ( & V_35 -> V_38 , V_39 ) ;
F_21 ( V_11 , V_41 ) ;
V_40 = F_22 ( V_11 , V_18 -> V_30 + V_18 -> V_31 ) ;
if ( ! V_40 ) {
F_23 ( V_11 , V_41 ) ;
F_17 ( V_35 , 0 ) ;
return 0 ;
}
F_24 ( V_11 , V_18 -> V_30 , V_18 -> V_31 ) ;
V_11 -> V_32 . V_33 = V_40 ;
F_25 ( V_35 , V_11 , V_41 ) ;
F_26 ( V_35 , V_11 , V_42 ) ;
return F_27 ( V_35 , 0 ) ;
}
STATIC void
F_28 (
struct V_29 * V_18 )
{
if ( F_29 ( & V_18 -> V_43 ) ) {
struct V_12 * V_13 = F_6 ( V_18 -> V_27 ) -> V_14 ;
if ( V_18 -> V_44 == V_45 )
F_30 ( V_13 -> V_46 , & V_18 -> V_47 ) ;
else if ( V_18 -> V_37 )
F_30 ( V_13 -> V_48 , & V_18 -> V_47 ) ;
else
F_8 ( V_18 ) ;
}
}
STATIC void
F_31 (
struct V_49 * V_50 )
{
T_1 * V_18 = F_32 ( V_50 , T_1 , V_47 ) ;
struct V_10 * V_11 = F_6 ( V_18 -> V_27 ) ;
int error = 0 ;
if ( F_33 ( V_11 -> V_14 ) ) {
V_18 -> V_23 = - V_51 ;
goto V_52;
}
if ( V_18 -> V_23 )
goto V_52;
if ( V_18 -> V_44 == V_45 ) {
if ( V_18 -> V_37 ) {
ASSERT ( V_18 -> V_53 ) ;
F_20 (
& V_18 -> V_37 -> V_38 , V_39 ) ;
F_17 ( V_18 -> V_37 , 0 ) ;
}
error = F_34 ( V_11 , V_18 -> V_30 ,
V_18 -> V_31 ) ;
if ( error ) {
V_18 -> V_23 = - error ;
goto V_52;
}
} else if ( V_18 -> V_37 ) {
error = F_19 ( V_18 ) ;
if ( error )
V_18 -> V_23 = - error ;
} else {
ASSERT ( ! F_12 ( V_18 ) ) ;
}
V_52:
F_8 ( V_18 ) ;
}
STATIC void
F_35 (
struct V_29 * V_18 )
{
if ( F_29 ( & V_18 -> V_43 ) )
F_31 ( & V_18 -> V_47 ) ;
}
STATIC T_1 *
F_36 (
struct V_9 * V_9 ,
unsigned int type )
{
T_1 * V_18 ;
V_18 = F_37 ( V_28 , V_54 ) ;
F_38 ( & V_18 -> V_43 , 1 ) ;
V_18 -> V_25 = 0 ;
V_18 -> V_53 = 0 ;
V_18 -> V_23 = 0 ;
V_18 -> V_55 = NULL ;
V_18 -> V_44 = type ;
V_18 -> V_27 = V_9 ;
V_18 -> V_20 = NULL ;
V_18 -> V_56 = NULL ;
V_18 -> V_30 = 0 ;
V_18 -> V_31 = 0 ;
V_18 -> V_24 = NULL ;
V_18 -> V_26 = 0 ;
V_18 -> V_37 = NULL ;
F_39 ( & V_18 -> V_47 , F_31 ) ;
return V_18 ;
}
STATIC int
F_40 (
struct V_9 * V_9 ,
T_3 V_57 ,
struct V_58 * V_59 ,
int type ,
int V_60 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_4 V_61 = 1 << V_9 -> V_62 ;
T_5 V_63 , V_64 ;
int error = 0 ;
int V_65 = V_66 ;
int V_67 = 1 ;
if ( F_33 ( V_13 ) )
return - F_41 ( V_51 ) ;
if ( type == V_45 )
V_65 |= V_68 ;
if ( ! F_42 ( V_11 , V_69 ) ) {
if ( V_60 )
return - F_41 ( V_70 ) ;
F_21 ( V_11 , V_69 ) ;
}
ASSERT ( V_11 -> V_32 . V_71 != V_72 ||
( V_11 -> V_73 . V_74 & V_75 ) ) ;
ASSERT ( V_57 <= V_13 -> V_76 ) ;
if ( V_57 + V_61 > V_13 -> V_76 )
V_61 = V_13 -> V_76 - V_57 ;
V_64 = F_43 ( V_13 , ( V_77 ) V_57 + V_61 ) ;
V_63 = F_44 ( V_13 , V_57 ) ;
error = F_45 ( V_11 , V_63 , V_64 - V_63 ,
V_59 , & V_67 , V_65 ) ;
F_23 ( V_11 , V_69 ) ;
if ( error )
return - F_41 ( error ) ;
if ( type == V_78 &&
( ! V_67 || F_46 ( V_59 -> V_79 ) ) ) {
error = F_47 ( V_11 , V_57 , V_61 , V_59 ) ;
if ( ! error )
F_48 ( V_11 , V_57 , V_61 , type , V_59 ) ;
return - F_41 ( error ) ;
}
#ifdef F_49
if ( type == V_45 ) {
ASSERT ( V_67 ) ;
ASSERT ( V_59 -> V_79 != V_80 ) ;
ASSERT ( V_59 -> V_79 != V_81 ) ;
}
#endif
if ( V_67 )
F_50 ( V_11 , V_57 , V_61 , type , V_59 ) ;
return 0 ;
}
STATIC int
F_51 (
struct V_9 * V_9 ,
struct V_58 * V_59 ,
T_6 V_57 )
{
V_57 >>= V_9 -> V_62 ;
return V_57 >= V_59 -> V_82 &&
V_57 < V_59 -> V_82 + V_59 -> V_83 ;
}
STATIC void
F_52 (
struct V_84 * V_84 ,
int error )
{
T_1 * V_18 = V_84 -> V_85 ;
ASSERT ( F_53 ( & V_84 -> V_86 ) >= 1 ) ;
V_18 -> V_23 = F_54 ( V_87 , & V_84 -> V_88 ) ? 0 : error ;
V_84 -> V_85 = NULL ;
V_84 -> V_89 = NULL ;
F_55 ( V_84 ) ;
F_28 ( V_18 ) ;
}
STATIC void
F_56 (
struct V_90 * V_91 ,
T_1 * V_18 ,
struct V_84 * V_84 )
{
F_57 ( & V_18 -> V_43 ) ;
V_84 -> V_85 = V_18 ;
V_84 -> V_89 = F_52 ;
F_58 ( V_91 -> V_92 == V_93 ? V_94 : V_95 , V_84 ) ;
}
STATIC struct V_84 *
F_59 (
struct V_4 * V_5 )
{
int V_96 = F_60 ( V_5 -> V_97 ) ;
struct V_84 * V_84 = F_61 ( V_98 , V_96 ) ;
ASSERT ( V_84 -> V_85 == NULL ) ;
V_84 -> V_99 = V_5 -> V_100 * ( V_5 -> V_101 >> 9 ) ;
V_84 -> V_102 = V_5 -> V_97 ;
return V_84 ;
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
int V_103 ,
int V_104 )
{
ASSERT ( F_69 ( V_1 ) ) ;
ASSERT ( ! F_70 ( V_1 ) ) ;
if ( V_103 )
F_71 ( V_1 ) ;
F_72 ( V_1 ) ;
F_73 ( V_1 ) ;
if ( ! V_104 )
F_74 ( V_1 ) ;
}
static inline int F_75 ( struct V_84 * V_84 , struct V_4 * V_5 )
{
return F_76 ( V_84 , V_5 -> V_105 , V_5 -> V_101 , F_77 ( V_5 ) ) ;
}
STATIC void
F_78 (
struct V_90 * V_91 ,
T_1 * V_18 )
{
T_1 * V_6 = V_18 ;
T_1 * V_19 ;
struct V_4 * V_5 ;
struct V_84 * V_84 ;
T_7 V_106 = 0 ;
do {
V_19 = V_18 -> V_55 ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 )
F_62 ( V_5 ) ;
} while ( ( V_18 = V_19 ) != NULL );
V_18 = V_6 ;
do {
V_19 = V_18 -> V_55 ;
V_84 = NULL ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 ) {
if ( ! V_84 ) {
V_107:
V_84 = F_59 ( V_5 ) ;
} else if ( V_5 -> V_100 != V_106 + 1 ) {
F_56 ( V_91 , V_18 , V_84 ) ;
goto V_107;
}
if ( F_75 ( V_84 , V_5 ) != V_5 -> V_101 ) {
F_56 ( V_91 , V_18 , V_84 ) ;
goto V_107;
}
V_106 = V_5 -> V_100 ;
}
if ( V_84 )
F_56 ( V_91 , V_18 , V_84 ) ;
F_28 ( V_18 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_79 (
T_1 * V_18 )
{
T_1 * V_19 ;
struct V_4 * V_5 , * V_108 ;
do {
V_19 = V_18 -> V_55 ;
V_5 = V_18 -> V_20 ;
do {
V_108 = V_5 -> V_21 ;
F_80 ( V_5 ) ;
F_81 ( V_5 ) ;
} while ( ( V_5 = V_108 ) != NULL );
F_11 ( V_18 , V_28 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_82 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_6 V_57 ,
unsigned int type ,
T_1 * * V_109 ,
int V_110 )
{
T_1 * V_18 = * V_109 ;
if ( ! V_18 || V_110 || type != V_18 -> V_44 ) {
T_1 * V_111 = * V_109 ;
V_18 = F_36 ( V_9 , type ) ;
V_18 -> V_30 = V_57 ;
V_18 -> V_20 = V_5 ;
V_18 -> V_56 = V_5 ;
if ( V_111 )
V_111 -> V_55 = V_18 ;
* V_109 = V_18 ;
} else {
V_18 -> V_56 -> V_21 = V_5 ;
V_18 -> V_56 = V_5 ;
}
V_5 -> V_21 = NULL ;
V_18 -> V_31 += V_5 -> V_101 ;
}
STATIC void
F_83 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_58 * V_59 ,
T_6 V_57 )
{
T_7 V_112 ;
struct V_12 * V_113 = F_6 ( V_9 ) -> V_14 ;
T_6 V_114 = F_84 ( V_113 , V_59 -> V_82 ) ;
T_8 V_115 = F_85 ( F_6 ( V_9 ) , V_59 -> V_79 ) ;
ASSERT ( V_59 -> V_79 != V_80 ) ;
ASSERT ( V_59 -> V_79 != V_81 ) ;
V_112 = ( V_115 >> ( V_9 -> V_62 - V_116 ) ) +
( ( V_57 - V_114 ) >> V_9 -> V_62 ) ;
ASSERT ( V_112 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_100 = V_112 ;
F_86 ( V_5 ) ;
}
STATIC void
F_87 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_58 * V_59 ,
T_6 V_57 )
{
ASSERT ( V_59 -> V_79 != V_80 ) ;
ASSERT ( V_59 -> V_79 != V_81 ) ;
F_83 ( V_9 , V_5 , V_59 , V_57 ) ;
F_86 ( V_5 ) ;
F_88 ( V_5 ) ;
F_89 ( V_5 ) ;
}
STATIC int
F_90 (
struct V_1 * V_1 ,
unsigned int type )
{
if ( F_70 ( V_1 ) )
return 0 ;
if ( V_1 -> V_117 && F_91 ( V_1 ) ) {
struct V_4 * V_5 , * V_6 ;
int V_118 = 0 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) )
V_118 += ( type == V_45 ) ;
else if ( F_4 ( V_5 ) )
V_118 += ( type == V_78 ) ;
else if ( F_92 ( V_5 ) && F_63 ( V_5 ) )
V_118 += ( type == V_119 ) ;
else
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_118 )
return 1 ;
}
return 0 ;
}
STATIC int
F_93 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_3 V_120 ,
struct V_58 * V_59 ,
T_1 * * V_121 ,
struct V_90 * V_91 )
{
struct V_4 * V_5 , * V_6 ;
T_6 V_122 ;
unsigned long V_123 ;
unsigned int type ;
int V_124 , V_125 ;
int V_61 = 0 , V_52 = 0 , V_126 = 1 ;
T_6 V_57 = F_94 ( V_1 ) ;
if ( V_1 -> V_127 != V_120 )
goto V_128;
if ( ! F_95 ( V_1 ) )
goto V_128;
if ( F_70 ( V_1 ) )
goto V_129;
if ( V_1 -> V_117 != V_9 -> V_130 )
goto V_129;
if ( ! F_90 ( V_1 , ( * V_121 ) -> V_44 ) )
goto V_129;
V_122 = F_96 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode)) ;
V_124 = 1 << V_9 -> V_62 ;
V_123 = F_96 (unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE) ;
V_123 = V_123 ? F_97 ( V_123 , V_124 ) : V_131 ;
V_125 = V_123 / V_124 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( V_57 >= V_122 )
break;
if ( ! F_98 ( V_5 ) )
V_126 = 0 ;
if ( ! ( F_99 ( V_1 ) || F_98 ( V_5 ) ) ) {
V_52 = 1 ;
continue;
}
if ( F_3 ( V_5 ) || F_4 ( V_5 ) ||
F_63 ( V_5 ) ) {
if ( F_3 ( V_5 ) )
type = V_45 ;
else if ( F_4 ( V_5 ) )
type = V_78 ;
else
type = V_119 ;
if ( ! F_51 ( V_9 , V_59 , V_57 ) ) {
V_52 = 1 ;
continue;
}
F_100 ( V_5 ) ;
if ( type != V_119 )
F_87 ( V_9 , V_5 , V_59 , V_57 ) ;
F_82 ( V_9 , V_5 , V_57 , type ,
V_121 , V_52 ) ;
V_125 -- ;
V_61 ++ ;
} else {
V_52 = 1 ;
}
} while ( V_57 += V_124 , ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_126 && V_5 == V_6 )
F_101 ( V_1 ) ;
if ( V_61 ) {
if ( -- V_91 -> V_132 <= 0 &&
V_91 -> V_92 == V_133 )
V_52 = 1 ;
}
F_68 ( V_1 , ! V_125 , V_61 ) ;
return V_52 ;
V_129:
F_73 ( V_1 ) ;
V_128:
return 1 ;
}
STATIC void
F_102 (
struct V_9 * V_9 ,
T_9 V_120 ,
struct V_58 * V_59 ,
T_1 * * V_121 ,
struct V_90 * V_91 ,
T_9 V_134 )
{
struct V_135 V_136 ;
int V_52 = 0 , V_137 ;
F_103 ( & V_136 , 0 ) ;
while ( ! V_52 && V_120 <= V_134 ) {
unsigned V_124 = F_96 ( T_9 , V_138 , V_134 - V_120 + 1 ) ;
if ( ! F_104 ( & V_136 , V_9 -> V_130 , V_120 , V_124 ) )
break;
for ( V_137 = 0 ; V_137 < F_105 ( & V_136 ) ; V_137 ++ ) {
V_52 = F_93 ( V_9 , V_136 . V_139 [ V_137 ] , V_120 ++ ,
V_59 , V_121 , V_91 ) ;
if ( V_52 )
break;
}
F_106 ( & V_136 ) ;
F_107 () ;
}
}
STATIC void
F_108 (
struct V_1 * V_1 ,
unsigned long V_57 )
{
F_109 ( V_1 -> V_117 -> V_140 , V_1 , V_57 ) ;
F_110 ( V_1 , V_57 ) ;
}
STATIC void
F_111 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_117 -> V_140 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_3 V_57 = F_94 ( V_1 ) ;
if ( ! F_90 ( V_1 , V_78 ) )
goto V_141;
if ( F_33 ( V_11 -> V_14 ) )
goto V_141;
F_112 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_142 , V_57 ) ;
F_21 ( V_11 , V_41 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_5 V_143 ;
if ( ! F_4 ( V_5 ) )
goto V_144;
V_143 = F_44 ( V_11 -> V_14 , V_57 ) ;
error = F_113 ( V_11 , V_143 , 1 ) ;
if ( error ) {
if ( ! F_33 ( V_11 -> V_14 ) ) {
F_112 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_144:
V_57 += 1 << V_9 -> V_62 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_23 ( V_11 , V_41 ) ;
V_141:
F_108 ( V_1 , 0 ) ;
return;
}
STATIC int
F_114 (
struct V_1 * V_1 ,
struct V_90 * V_91 )
{
struct V_9 * V_9 = V_1 -> V_117 -> V_140 ;
struct V_4 * V_5 , * V_6 ;
struct V_58 V_59 ;
T_1 * V_18 = NULL , * V_145 = NULL ;
T_3 V_57 ;
unsigned int type ;
T_10 V_122 ;
T_9 V_146 , V_147 ;
T_4 V_124 ;
int V_148 , V_149 = 0 , V_126 = 1 ;
int V_61 = 0 ;
int V_60 = 0 ;
F_115 ( V_9 , V_1 , 0 ) ;
ASSERT ( F_91 ( V_1 ) ) ;
if ( F_116 ( ( V_150 -> V_151 & ( V_152 | V_153 ) ) ==
V_152 ) )
goto V_154;
if ( F_117 ( V_150 -> V_151 & V_39 ) )
goto V_154;
V_57 = F_118 ( V_9 ) ;
V_146 = V_57 >> V_155 ;
V_147 = ( V_57 - 1 ) >> V_155 ;
if ( V_1 -> V_127 >= V_146 ) {
if ( ( V_1 -> V_127 >= V_146 + 1 ) ||
! ( F_118 ( V_9 ) & ( V_131 - 1 ) ) ) {
F_73 ( V_1 ) ;
return 0 ;
}
}
V_122 = F_96 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
offset) ;
V_124 = 1 << V_9 -> V_62 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_57 = F_94 ( V_1 ) ;
type = V_119 ;
if ( V_91 -> V_92 == V_133 )
V_60 = 1 ;
do {
int V_156 = 0 ;
if ( V_57 >= V_122 )
break;
if ( ! F_98 ( V_5 ) )
V_126 = 0 ;
if ( ! F_63 ( V_5 ) && F_98 ( V_5 ) ) {
V_149 = 0 ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( type != V_45 ) {
type = V_45 ;
V_149 = 0 ;
}
} else if ( F_4 ( V_5 ) ) {
if ( type != V_78 ) {
type = V_78 ;
V_149 = 0 ;
}
} else if ( F_98 ( V_5 ) ) {
if ( type != V_119 ) {
type = V_119 ;
V_149 = 0 ;
}
} else {
if ( F_99 ( V_1 ) )
ASSERT ( F_63 ( V_5 ) ) ;
V_149 = 0 ;
continue;
}
if ( V_149 )
V_149 = F_51 ( V_9 , & V_59 , V_57 ) ;
if ( ! V_149 ) {
V_156 = 1 ;
V_148 = F_40 ( V_9 , V_57 , & V_59 , type ,
V_60 ) ;
if ( V_148 )
goto error;
V_149 = F_51 ( V_9 , & V_59 , V_57 ) ;
}
if ( V_149 ) {
F_100 ( V_5 ) ;
if ( type != V_119 )
F_87 ( V_9 , V_5 , & V_59 , V_57 ) ;
F_82 ( V_9 , V_5 , V_57 , type , & V_18 ,
V_156 ) ;
V_61 ++ ;
}
if ( ! V_145 )
V_145 = V_18 ;
} while ( V_57 += V_124 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_126 && V_5 == V_6 )
F_101 ( V_1 ) ;
F_68 ( V_1 , 1 , V_61 ) ;
if ( V_18 && V_149 ) {
T_6 V_146 ;
V_146 = V_59 . V_82 + V_59 . V_83 ;
V_146 <<= V_9 -> V_62 ;
V_146 = ( V_146 - 1 ) >> V_155 ;
if ( V_146 > V_147 )
V_146 = V_147 ;
F_102 ( V_9 , V_1 -> V_127 + 1 , & V_59 , & V_18 ,
V_91 , V_146 ) ;
}
if ( V_145 ) {
if ( V_18 -> V_44 != V_45 &&
F_12 ( V_18 ) ) {
V_148 = F_13 ( V_18 ) ;
if ( V_148 )
goto error;
}
F_78 ( V_91 , V_145 ) ;
}
return 0 ;
error:
if ( V_145 )
F_79 ( V_145 ) ;
if ( V_148 == - V_70 )
goto V_154;
F_111 ( V_1 ) ;
F_119 ( V_1 ) ;
F_73 ( V_1 ) ;
return V_148 ;
V_154:
F_120 ( V_91 , V_1 ) ;
F_73 ( V_1 ) ;
return 0 ;
}
STATIC int
F_121 (
struct V_157 * V_117 ,
struct V_90 * V_91 )
{
F_122 ( F_6 ( V_117 -> V_140 ) , V_158 ) ;
return F_123 ( V_117 , V_91 ) ;
}
STATIC int
F_124 (
struct V_1 * V_1 ,
T_11 V_159 )
{
int V_2 , V_3 ;
F_125 ( V_1 -> V_117 -> V_140 , V_1 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_117 ( V_2 ) )
return 0 ;
if ( F_117 ( V_3 ) )
return 0 ;
return F_126 ( V_1 ) ;
}
STATIC int
F_127 (
struct V_9 * V_9 ,
T_7 V_160 ,
struct V_4 * V_161 ,
int V_162 ,
int V_163 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_5 V_63 , V_64 ;
int error = 0 ;
int V_164 = 0 ;
struct V_58 V_59 ;
int V_67 = 1 ;
T_6 V_57 ;
T_4 V_165 ;
int V_166 = 0 ;
if ( F_33 ( V_13 ) )
return - F_41 ( V_51 ) ;
V_57 = ( T_6 ) V_160 << V_9 -> V_62 ;
ASSERT ( V_161 -> V_101 >= ( 1 << V_9 -> V_62 ) ) ;
V_165 = V_161 -> V_101 ;
if ( ! V_162 && V_163 && V_57 >= F_118 ( V_9 ) )
return 0 ;
if ( V_162 && ! V_163 ) {
V_164 = V_41 ;
F_21 ( V_11 , V_164 ) ;
} else {
V_164 = F_128 ( V_11 ) ;
}
ASSERT ( V_57 <= V_13 -> V_76 ) ;
if ( V_57 + V_165 > V_13 -> V_76 )
V_165 = V_13 -> V_76 - V_57 ;
V_64 = F_43 ( V_13 , ( V_77 ) V_57 + V_165 ) ;
V_63 = F_44 ( V_13 , V_57 ) ;
error = F_45 ( V_11 , V_63 , V_64 - V_63 ,
& V_59 , & V_67 , V_66 ) ;
if ( error )
goto V_167;
if ( V_162 &&
( ! V_67 ||
( V_59 . V_79 == V_80 ||
V_59 . V_79 == V_81 ) ) ) {
if ( V_163 || F_129 ( V_11 ) ) {
F_23 ( V_11 , V_164 ) ;
error = F_130 ( V_11 , V_57 , V_165 ,
& V_59 , V_67 ) ;
if ( error )
return - error ;
V_166 = 1 ;
} else {
if ( V_67 && V_59 . V_79 == V_80 )
V_166 = 1 ;
error = F_131 ( V_11 , V_57 , V_165 , & V_59 ) ;
if ( error )
goto V_167;
F_23 ( V_11 , V_164 ) ;
}
F_132 ( V_11 , V_57 , V_165 , 0 , & V_59 ) ;
} else if ( V_67 ) {
F_133 ( V_11 , V_57 , V_165 , 0 , & V_59 ) ;
F_23 ( V_11 , V_164 ) ;
} else {
F_134 ( V_11 , V_57 , V_165 ) ;
goto V_167;
}
if ( V_59 . V_79 != V_80 &&
V_59 . V_79 != V_81 ) {
if ( V_162 || ! F_135 ( & V_59 ) )
F_83 ( V_9 , V_161 , & V_59 , V_57 ) ;
if ( V_162 && F_135 ( & V_59 ) ) {
if ( V_163 )
V_161 -> V_21 = V_9 ;
F_136 ( V_161 ) ;
}
}
V_161 -> V_97 = F_5 ( V_9 ) ;
if ( V_162 &&
( ( ! F_63 ( V_161 ) && ! F_98 ( V_161 ) ) ||
( V_57 >= F_118 ( V_9 ) ) ||
( V_166 || F_135 ( & V_59 ) ) ) )
F_137 ( V_161 ) ;
if ( V_59 . V_79 == V_81 ) {
F_138 ( V_163 ) ;
if ( V_162 ) {
F_66 ( V_161 ) ;
F_86 ( V_161 ) ;
F_139 ( V_161 ) ;
}
}
if ( V_163 || V_165 > ( 1 << V_9 -> V_62 ) ) {
T_6 V_168 ;
V_168 = V_59 . V_82 + V_59 . V_83 - V_160 ;
V_168 <<= V_9 -> V_62 ;
ASSERT ( V_168 > 0 ) ;
if ( V_168 > V_165 )
V_168 = V_165 ;
if ( V_168 > V_169 )
V_168 = V_169 ;
V_161 -> V_101 = V_168 ;
}
return 0 ;
V_167:
F_23 ( V_11 , V_164 ) ;
return - error ;
}
int
F_140 (
struct V_9 * V_9 ,
T_7 V_160 ,
struct V_4 * V_161 ,
int V_162 )
{
return F_127 ( V_9 , V_160 , V_161 , V_162 , 0 ) ;
}
STATIC int
F_141 (
struct V_9 * V_9 ,
T_7 V_160 ,
struct V_4 * V_161 ,
int V_162 )
{
return F_127 ( V_9 , V_160 , V_161 , V_162 , 1 ) ;
}
STATIC void
F_142 (
struct V_170 * V_171 ,
T_3 V_57 ,
T_4 V_165 ,
void * V_172 ,
int V_173 ,
bool V_174 )
{
struct V_29 * V_18 = V_171 -> V_172 ;
if ( V_57 + V_165 > F_118 ( V_18 -> V_27 ) )
F_143 ( V_18 -> V_27 , V_57 + V_165 ) ;
V_171 -> V_172 = NULL ;
V_18 -> V_30 = V_57 ;
V_18 -> V_31 = V_165 ;
V_18 -> V_24 = V_171 ;
V_18 -> V_26 = V_173 ;
if ( V_172 && V_165 > 0 )
V_18 -> V_44 = V_45 ;
if ( V_174 ) {
V_18 -> V_25 = 1 ;
F_28 ( V_18 ) ;
} else {
F_35 ( V_18 ) ;
}
}
STATIC T_4
F_144 (
int V_175 ,
struct V_170 * V_171 ,
const struct V_176 * V_177 ,
T_3 V_57 ,
unsigned long V_178 )
{
struct V_9 * V_9 = V_171 -> V_179 -> V_180 -> V_140 ;
struct V_8 * V_181 = F_5 ( V_9 ) ;
struct V_29 * V_18 = NULL ;
T_4 V_173 ;
if ( V_175 & V_95 ) {
T_12 V_165 = F_145 ( V_177 , V_178 ) ;
V_171 -> V_172 = V_18 = F_36 ( V_9 , V_182 ) ;
if ( V_57 + V_165 > F_6 ( V_9 ) -> V_32 . V_33 ) {
V_173 = F_13 ( V_18 ) ;
if ( V_173 )
goto V_183;
V_18 -> V_53 = 1 ;
}
V_173 = F_146 ( V_175 , V_171 , V_9 , V_181 , V_177 ,
V_57 , V_178 ,
F_141 ,
F_142 , NULL , 0 ) ;
if ( V_173 != - V_184 && V_171 -> V_172 )
goto V_185;
} else {
V_173 = F_146 ( V_175 , V_171 , V_9 , V_181 , V_177 ,
V_57 , V_178 ,
F_141 ,
NULL , NULL , 0 ) ;
}
return V_173 ;
V_185:
if ( V_18 -> V_37 ) {
F_20 ( & V_18 -> V_37 -> V_38 ,
V_39 ) ;
F_17 ( V_18 -> V_37 , 0 ) ;
}
V_183:
F_8 ( V_18 ) ;
return V_173 ;
}
STATIC void
F_147 (
struct V_9 * V_9 ,
T_3 V_186 ,
T_3 V_187 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_5 V_143 ;
T_5 V_64 ;
int error ;
V_143 = F_43 ( V_11 -> V_14 , V_186 ) ;
V_64 = F_43 ( V_11 -> V_14 , V_187 ) ;
if ( V_64 <= V_143 )
return;
F_21 ( V_11 , V_41 ) ;
error = F_113 ( V_11 , V_143 ,
V_64 - V_143 ) ;
if ( error ) {
if ( ! F_33 ( V_11 -> V_14 ) ) {
F_112 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_142 ) ;
}
}
F_23 ( V_11 , V_41 ) ;
}
STATIC void
F_148 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_3 V_188 ,
unsigned V_124 )
{
T_3 V_189 = V_188 & V_190 ;
T_3 V_191 ;
T_3 V_192 ;
T_3 V_193 = V_188 & ( V_131 - 1 ) ;
T_3 V_194 = V_193 + V_124 ;
struct V_4 * V_5 , * V_6 ;
ASSERT ( V_189 + V_193 == V_188 ) ;
V_6 = F_2 ( V_1 ) ;
V_191 = 0 ;
for ( V_5 = V_6 ; V_5 != V_6 || ! V_191 ;
V_5 = V_5 -> V_7 , V_191 = V_192 ,
V_189 += V_5 -> V_101 ) {
V_192 = V_191 + V_5 -> V_101 ;
if ( V_192 <= V_193 )
continue;
if ( V_191 >= V_194 )
break;
if ( ! F_4 ( V_5 ) )
continue;
if ( ! F_149 ( V_5 ) && V_189 < F_118 ( V_9 ) )
continue;
F_147 ( V_9 , V_189 ,
V_189 + V_5 -> V_101 ) ;
}
}
STATIC int
F_150 (
struct V_195 * V_195 ,
struct V_157 * V_117 ,
T_3 V_188 ,
unsigned V_124 ,
unsigned V_151 ,
struct V_1 * * V_196 ,
void * * V_197 )
{
T_9 V_127 = V_188 >> V_155 ;
struct V_1 * V_1 ;
int V_198 ;
ASSERT ( V_124 <= V_131 ) ;
V_1 = F_151 ( V_117 , V_127 ,
V_151 | V_199 ) ;
if ( ! V_1 )
return - V_200 ;
V_198 = F_152 ( V_1 , V_188 , V_124 , F_140 ) ;
if ( F_153 ( V_198 ) ) {
struct V_9 * V_9 = V_117 -> V_140 ;
F_148 ( V_9 , V_1 , V_188 , V_124 ) ;
F_73 ( V_1 ) ;
if ( V_188 + V_124 > F_118 ( V_9 ) )
F_154 ( V_9 , V_188 + V_124 , F_118 ( V_9 ) ) ;
F_155 ( V_1 ) ;
V_1 = NULL ;
}
* V_196 = V_1 ;
return V_198 ;
}
STATIC int
F_156 (
struct V_195 * V_195 ,
struct V_157 * V_117 ,
T_3 V_188 ,
unsigned V_124 ,
unsigned V_201 ,
struct V_1 * V_1 ,
void * V_197 )
{
int V_173 ;
ASSERT ( V_124 <= V_131 ) ;
V_173 = F_157 ( V_195 , V_117 , V_188 , V_124 , V_201 , V_1 , V_197 ) ;
if ( F_153 ( V_173 < V_124 ) ) {
struct V_9 * V_9 = V_117 -> V_140 ;
T_12 V_40 = F_118 ( V_9 ) ;
T_3 V_194 = V_188 + V_124 ;
if ( V_194 > V_40 ) {
F_154 ( V_9 , V_194 , V_40 ) ;
F_147 ( V_9 , V_40 , V_194 ) ;
}
}
return V_173 ;
}
STATIC T_7
F_158 (
struct V_157 * V_117 ,
T_7 V_202 )
{
struct V_9 * V_9 = (struct V_9 * ) V_117 -> V_140 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_159 ( F_6 ( V_9 ) ) ;
F_21 ( V_11 , V_203 ) ;
F_160 ( V_11 , ( T_6 ) 0 , - 1 , 0 , V_204 ) ;
F_23 ( V_11 , V_203 ) ;
return F_161 ( V_117 , V_202 , F_140 ) ;
}
STATIC int
F_162 (
struct V_195 * V_205 ,
struct V_1 * V_1 )
{
return F_163 ( V_1 , F_140 ) ;
}
STATIC int
F_164 (
struct V_195 * V_205 ,
struct V_157 * V_117 ,
struct V_206 * V_139 ,
unsigned V_207 )
{
return F_165 ( V_117 , V_139 , V_207 , F_140 ) ;
}
