void T_1
F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_2 ( & V_3 [ V_1 ] ) ;
}
void
F_3 (
T_2 * V_4 )
{
T_3 * V_5 = F_4 ( V_4 ) ;
F_5 ( * V_5 , ( F_6 ( & V_4 -> V_6 ) == 0 ) ) ;
}
STATIC void
F_7 (
T_2 * V_4 )
{
if ( F_8 ( & V_4 -> V_6 ) )
F_9 ( F_4 ( V_4 ) ) ;
}
void
F_10 (
struct V_7 * V_7 ,
int * V_8 ,
int * V_9 )
{
struct V_10 * V_11 , * V_12 ;
* V_8 = * V_9 = 0 ;
V_11 = V_12 = F_11 ( V_7 ) ;
do {
if ( F_12 ( V_11 ) )
( * V_9 ) = 1 ;
else if ( F_13 ( V_11 ) )
( * V_8 ) = 1 ;
} while ( ( V_11 = V_11 -> V_13 ) != V_12 );
}
STATIC struct V_14 *
F_14 (
struct V_15 * V_15 )
{
struct V_16 * V_4 = F_15 ( V_15 ) ;
struct V_17 * V_18 = V_4 -> V_19 ;
if ( F_16 ( V_4 ) )
return V_18 -> V_20 -> V_21 ;
else
return V_18 -> V_22 -> V_21 ;
}
STATIC void
F_17 (
T_4 * V_23 )
{
struct V_10 * V_11 , * V_24 ;
struct V_16 * V_4 = F_15 ( V_23 -> V_25 ) ;
for ( V_11 = V_23 -> V_26 ; V_11 ; V_11 = V_24 ) {
V_24 = V_11 -> V_27 ;
V_11 -> V_28 ( V_11 , ! V_23 -> V_29 ) ;
}
if ( F_18 ( V_23 -> V_29 == - V_30 ) ) {
F_19 ( V_4 -> V_19 , V_31 ,
__FILE__ , __LINE__ ) ;
}
F_7 ( V_4 ) ;
F_20 ( V_23 , V_32 ) ;
}
STATIC T_5
F_21 (
T_4 * V_23 )
{
T_2 * V_4 = F_15 ( V_23 -> V_25 ) ;
T_5 V_33 ;
T_5 V_34 ;
V_34 = V_23 -> V_35 + V_23 -> V_36 ;
V_33 = F_22 ( V_4 -> V_37 , V_4 -> V_38 ) ;
V_33 = F_23 ( V_33 , V_34 ) ;
return V_33 > V_4 -> V_39 . V_40 ? V_33 : 0 ;
}
STATIC int
F_24 (
T_4 * V_23 )
{
T_2 * V_4 = F_15 ( V_23 -> V_25 ) ;
T_5 V_33 ;
if ( F_18 ( V_23 -> V_29 ) )
return 0 ;
if ( ! F_25 ( V_4 , V_41 ) )
return V_42 ;
V_33 = F_21 ( V_23 ) ;
if ( V_33 ) {
V_4 -> V_39 . V_40 = V_33 ;
F_26 ( V_4 ) ;
}
F_27 ( V_4 , V_41 ) ;
return 0 ;
}
STATIC void
F_28 (
struct V_43 * V_23 )
{
if ( F_8 ( & V_23 -> V_44 ) ) {
if ( V_23 -> V_45 == V_46 )
F_29 ( V_47 , & V_23 -> V_48 ) ;
else
F_29 ( V_49 , & V_23 -> V_48 ) ;
}
}
STATIC void
F_30 (
struct V_50 * V_51 )
{
T_4 * V_23 = F_31 ( V_51 , T_4 , V_48 ) ;
struct V_16 * V_4 = F_15 ( V_23 -> V_25 ) ;
int error = 0 ;
if ( V_23 -> V_45 == V_46 &&
F_32 ( ! V_23 -> V_29 && ! F_33 ( V_4 -> V_19 ) ) ) {
error = F_34 ( V_4 , V_23 -> V_35 ,
V_23 -> V_36 ) ;
if ( error )
V_23 -> V_29 = error ;
}
error = F_24 ( V_23 ) ;
ASSERT ( ! error || error == V_42 ) ;
if ( error == V_42 ) {
F_35 ( & V_23 -> V_44 ) ;
F_28 ( V_23 ) ;
F_36 ( 1 ) ;
} else {
if ( V_23 -> V_52 )
F_37 ( V_23 -> V_52 , V_23 -> V_53 , 0 ) ;
F_17 ( V_23 ) ;
}
}
STATIC void
F_38 (
struct V_43 * V_23 )
{
if ( F_8 ( & V_23 -> V_44 ) )
F_30 ( & V_23 -> V_48 ) ;
}
STATIC T_4 *
F_39 (
struct V_15 * V_15 ,
unsigned int type )
{
T_4 * V_23 ;
V_23 = F_40 ( V_32 , V_54 ) ;
F_41 ( & V_23 -> V_44 , 1 ) ;
V_23 -> V_29 = 0 ;
V_23 -> V_55 = NULL ;
V_23 -> V_45 = type ;
V_23 -> V_25 = V_15 ;
V_23 -> V_26 = NULL ;
V_23 -> V_56 = NULL ;
F_35 ( & F_15 ( V_23 -> V_25 ) -> V_6 ) ;
V_23 -> V_35 = 0 ;
V_23 -> V_36 = 0 ;
V_23 -> V_52 = NULL ;
V_23 -> V_53 = 0 ;
F_42 ( & V_23 -> V_48 , F_30 ) ;
return V_23 ;
}
STATIC int
F_43 (
struct V_15 * V_15 ,
T_6 V_57 ,
struct V_58 * V_59 ,
int type ,
int V_60 )
{
struct V_16 * V_4 = F_15 ( V_15 ) ;
struct V_17 * V_18 = V_4 -> V_19 ;
T_7 V_61 = 1 << V_15 -> V_62 ;
T_8 V_63 , V_64 ;
int error = 0 ;
int V_65 = V_66 ;
int V_67 = 1 ;
if ( F_33 ( V_18 ) )
return - F_44 ( V_68 ) ;
if ( type == V_46 )
V_65 |= V_69 ;
if ( ! F_25 ( V_4 , V_70 ) ) {
if ( V_60 )
return - F_44 ( V_42 ) ;
F_45 ( V_4 , V_70 ) ;
}
ASSERT ( V_4 -> V_39 . V_71 != V_72 ||
( V_4 -> V_73 . V_74 & V_75 ) ) ;
ASSERT ( V_57 <= V_18 -> V_76 ) ;
if ( V_57 + V_61 > V_18 -> V_76 )
V_61 = V_18 -> V_76 - V_57 ;
V_64 = F_46 ( V_18 , ( V_77 ) V_57 + V_61 ) ;
V_63 = F_47 ( V_18 , V_57 ) ;
error = F_48 ( NULL , V_4 , V_63 , V_64 - V_63 ,
V_65 , NULL , 0 , V_59 , & V_67 , NULL ) ;
F_27 ( V_4 , V_70 ) ;
if ( error )
return - F_44 ( error ) ;
if ( type == V_78 &&
( ! V_67 || F_49 ( V_59 -> V_79 ) ) ) {
error = F_50 ( V_4 , V_57 , V_61 , V_59 ) ;
if ( ! error )
F_51 ( V_4 , V_57 , V_61 , type , V_59 ) ;
return - F_44 ( error ) ;
}
#ifdef F_52
if ( type == V_46 ) {
ASSERT ( V_67 ) ;
ASSERT ( V_59 -> V_79 != V_80 ) ;
ASSERT ( V_59 -> V_79 != V_81 ) ;
}
#endif
if ( V_67 )
F_53 ( V_4 , V_57 , V_61 , type , V_59 ) ;
return 0 ;
}
STATIC int
F_54 (
struct V_15 * V_15 ,
struct V_58 * V_59 ,
T_9 V_57 )
{
V_57 >>= V_15 -> V_62 ;
return V_57 >= V_59 -> V_82 &&
V_57 < V_59 -> V_82 + V_59 -> V_83 ;
}
STATIC void
F_55 (
struct V_84 * V_84 ,
int error )
{
T_4 * V_23 = V_84 -> V_85 ;
ASSERT ( F_6 ( & V_84 -> V_86 ) >= 1 ) ;
V_23 -> V_29 = F_56 ( V_87 , & V_84 -> V_88 ) ? 0 : error ;
V_84 -> V_85 = NULL ;
V_84 -> V_89 = NULL ;
F_57 ( V_84 ) ;
F_28 ( V_23 ) ;
}
STATIC void
F_58 (
struct V_90 * V_91 ,
T_4 * V_23 ,
struct V_84 * V_84 )
{
F_35 ( & V_23 -> V_44 ) ;
V_84 -> V_85 = V_23 ;
V_84 -> V_89 = F_55 ;
if ( F_21 ( V_23 ) )
F_26 ( F_15 ( V_23 -> V_25 ) ) ;
F_59 ( V_91 -> V_92 == V_93 ? V_94 : V_95 , V_84 ) ;
}
STATIC struct V_84 *
F_60 (
struct V_10 * V_11 )
{
int V_96 = F_61 ( V_11 -> V_97 ) ;
struct V_84 * V_84 = F_62 ( V_98 , V_96 ) ;
ASSERT ( V_84 -> V_85 == NULL ) ;
V_84 -> V_99 = V_11 -> V_100 * ( V_11 -> V_101 >> 9 ) ;
V_84 -> V_102 = V_11 -> V_97 ;
return V_84 ;
}
STATIC void
F_63 (
struct V_10 * V_11 )
{
ASSERT ( F_64 ( V_11 ) ) ;
ASSERT ( F_65 ( V_11 ) ) ;
ASSERT ( ! F_13 ( V_11 ) ) ;
ASSERT ( ! F_12 ( V_11 ) ) ;
F_66 ( V_11 ) ;
F_67 ( V_11 ) ;
F_68 ( V_11 ) ;
}
STATIC void
F_69 (
struct V_7 * V_7 ,
int V_103 ,
int V_104 )
{
ASSERT ( F_70 ( V_7 ) ) ;
ASSERT ( ! F_71 ( V_7 ) ) ;
if ( V_103 )
F_72 ( V_7 ) ;
F_73 ( V_7 ) ;
F_74 ( V_7 ) ;
if ( ! V_104 )
F_75 ( V_7 ) ;
}
static inline int F_76 ( struct V_84 * V_84 , struct V_10 * V_11 )
{
return F_77 ( V_84 , V_11 -> V_105 , V_11 -> V_101 , F_78 ( V_11 ) ) ;
}
STATIC void
F_79 (
struct V_90 * V_91 ,
T_4 * V_23 )
{
T_4 * V_12 = V_23 ;
T_4 * V_24 ;
struct V_10 * V_11 ;
struct V_84 * V_84 ;
T_10 V_106 = 0 ;
do {
V_24 = V_23 -> V_55 ;
for ( V_11 = V_23 -> V_26 ; V_11 ; V_11 = V_11 -> V_27 )
F_63 ( V_11 ) ;
} while ( ( V_23 = V_24 ) != NULL );
V_23 = V_12 ;
do {
V_24 = V_23 -> V_55 ;
V_84 = NULL ;
for ( V_11 = V_23 -> V_26 ; V_11 ; V_11 = V_11 -> V_27 ) {
if ( ! V_84 ) {
V_107:
V_84 = F_60 ( V_11 ) ;
} else if ( V_11 -> V_100 != V_106 + 1 ) {
F_58 ( V_91 , V_23 , V_84 ) ;
goto V_107;
}
if ( F_76 ( V_84 , V_11 ) != V_11 -> V_101 ) {
F_58 ( V_91 , V_23 , V_84 ) ;
goto V_107;
}
V_106 = V_11 -> V_100 ;
}
if ( V_84 )
F_58 ( V_91 , V_23 , V_84 ) ;
F_28 ( V_23 ) ;
} while ( ( V_23 = V_24 ) != NULL );
}
STATIC void
F_80 (
T_4 * V_23 )
{
T_4 * V_24 ;
struct V_10 * V_11 , * V_108 ;
do {
V_24 = V_23 -> V_55 ;
V_11 = V_23 -> V_26 ;
do {
V_108 = V_11 -> V_27 ;
F_81 ( V_11 ) ;
F_82 ( V_11 ) ;
} while ( ( V_11 = V_108 ) != NULL );
F_7 ( F_15 ( V_23 -> V_25 ) ) ;
F_20 ( V_23 , V_32 ) ;
} while ( ( V_23 = V_24 ) != NULL );
}
STATIC void
F_83 (
struct V_15 * V_15 ,
struct V_10 * V_11 ,
T_9 V_57 ,
unsigned int type ,
T_4 * * V_109 ,
int V_110 )
{
T_4 * V_23 = * V_109 ;
if ( ! V_23 || V_110 || type != V_23 -> V_45 ) {
T_4 * V_111 = * V_109 ;
V_23 = F_39 ( V_15 , type ) ;
V_23 -> V_35 = V_57 ;
V_23 -> V_26 = V_11 ;
V_23 -> V_56 = V_11 ;
if ( V_111 )
V_111 -> V_55 = V_23 ;
* V_109 = V_23 ;
} else {
V_23 -> V_56 -> V_27 = V_11 ;
V_23 -> V_56 = V_11 ;
}
V_11 -> V_27 = NULL ;
V_23 -> V_36 += V_11 -> V_101 ;
}
STATIC void
F_84 (
struct V_15 * V_15 ,
struct V_10 * V_11 ,
struct V_58 * V_59 ,
T_9 V_57 )
{
T_10 V_112 ;
struct V_17 * V_113 = F_15 ( V_15 ) -> V_19 ;
T_9 V_114 = F_85 ( V_113 , V_59 -> V_82 ) ;
T_11 V_115 = F_86 ( F_15 ( V_15 ) , V_59 -> V_79 ) ;
ASSERT ( V_59 -> V_79 != V_80 ) ;
ASSERT ( V_59 -> V_79 != V_81 ) ;
V_112 = ( V_115 >> ( V_15 -> V_62 - V_116 ) ) +
( ( V_57 - V_114 ) >> V_15 -> V_62 ) ;
ASSERT ( V_112 || F_16 ( F_15 ( V_15 ) ) ) ;
V_11 -> V_100 = V_112 ;
F_87 ( V_11 ) ;
}
STATIC void
F_88 (
struct V_15 * V_15 ,
struct V_10 * V_11 ,
struct V_58 * V_59 ,
T_9 V_57 )
{
ASSERT ( V_59 -> V_79 != V_80 ) ;
ASSERT ( V_59 -> V_79 != V_81 ) ;
F_84 ( V_15 , V_11 , V_59 , V_57 ) ;
F_87 ( V_11 ) ;
F_89 ( V_11 ) ;
F_90 ( V_11 ) ;
}
STATIC int
F_91 (
struct V_7 * V_7 ,
unsigned int type )
{
if ( F_71 ( V_7 ) )
return 0 ;
if ( V_7 -> V_117 && F_92 ( V_7 ) ) {
struct V_10 * V_11 , * V_12 ;
int V_118 = 0 ;
V_11 = V_12 = F_11 ( V_7 ) ;
do {
if ( F_12 ( V_11 ) )
V_118 = ( type == V_46 ) ;
else if ( F_13 ( V_11 ) )
V_118 = ( type == V_78 ) ;
else if ( F_93 ( V_11 ) && F_64 ( V_11 ) )
V_118 = ( type == V_119 ) ;
else
break;
} while ( ( V_11 = V_11 -> V_13 ) != V_12 );
if ( V_118 )
return 1 ;
}
return 0 ;
}
STATIC int
F_94 (
struct V_15 * V_15 ,
struct V_7 * V_7 ,
T_6 V_120 ,
struct V_58 * V_59 ,
T_4 * * V_121 ,
struct V_90 * V_91 )
{
struct V_10 * V_11 , * V_12 ;
T_9 V_122 ;
unsigned long V_123 ;
unsigned int type ;
int V_124 , V_125 ;
int V_61 = 0 , V_126 = 0 , V_127 = 1 ;
T_9 V_57 = F_95 ( V_7 ) ;
if ( V_7 -> V_128 != V_120 )
goto V_129;
if ( ! F_96 ( V_7 ) )
goto V_129;
if ( F_71 ( V_7 ) )
goto V_130;
if ( V_7 -> V_117 != V_15 -> V_131 )
goto V_130;
if ( ! F_91 ( V_7 , ( * V_121 ) -> V_45 ) )
goto V_130;
V_122 = F_97 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode)) ;
V_124 = 1 << V_15 -> V_62 ;
V_123 = F_97 (unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE) ;
V_123 = V_123 ? F_98 ( V_123 , V_124 ) : V_132 ;
V_125 = V_123 / V_124 ;
V_11 = V_12 = F_11 ( V_7 ) ;
do {
if ( V_57 >= V_122 )
break;
if ( ! F_99 ( V_11 ) )
V_127 = 0 ;
if ( ! ( F_100 ( V_7 ) || F_99 ( V_11 ) ) ) {
V_126 = 1 ;
continue;
}
if ( F_12 ( V_11 ) || F_13 ( V_11 ) ||
F_64 ( V_11 ) ) {
if ( F_12 ( V_11 ) )
type = V_46 ;
else if ( F_13 ( V_11 ) )
type = V_78 ;
else
type = V_119 ;
if ( ! F_54 ( V_15 , V_59 , V_57 ) ) {
V_126 = 1 ;
continue;
}
F_101 ( V_11 ) ;
if ( type != V_119 )
F_88 ( V_15 , V_11 , V_59 , V_57 ) ;
F_83 ( V_15 , V_11 , V_57 , type ,
V_121 , V_126 ) ;
V_125 -- ;
V_61 ++ ;
} else {
V_126 = 1 ;
}
} while ( V_57 += V_124 , ( V_11 = V_11 -> V_13 ) != V_12 );
if ( V_127 && V_11 == V_12 )
F_102 ( V_7 ) ;
if ( V_61 ) {
if ( -- V_91 -> V_133 <= 0 &&
V_91 -> V_92 == V_134 )
V_126 = 1 ;
}
F_69 ( V_7 , ! V_125 , V_61 ) ;
return V_126 ;
V_130:
F_74 ( V_7 ) ;
V_129:
return 1 ;
}
STATIC void
F_103 (
struct V_15 * V_15 ,
T_12 V_120 ,
struct V_58 * V_59 ,
T_4 * * V_121 ,
struct V_90 * V_91 ,
T_12 V_135 )
{
struct V_136 V_137 ;
int V_126 = 0 , V_1 ;
F_104 ( & V_137 , 0 ) ;
while ( ! V_126 && V_120 <= V_135 ) {
unsigned V_124 = F_97 ( T_12 , V_138 , V_135 - V_120 + 1 ) ;
if ( ! F_105 ( & V_137 , V_15 -> V_131 , V_120 , V_124 ) )
break;
for ( V_1 = 0 ; V_1 < F_106 ( & V_137 ) ; V_1 ++ ) {
V_126 = F_94 ( V_15 , V_137 . V_139 [ V_1 ] , V_120 ++ ,
V_59 , V_121 , V_91 ) ;
if ( V_126 )
break;
}
F_107 ( & V_137 ) ;
F_108 () ;
}
}
STATIC void
F_109 (
struct V_7 * V_7 ,
unsigned long V_57 )
{
F_110 ( V_7 -> V_117 -> V_140 , V_7 , V_57 ) ;
F_111 ( V_7 , V_57 ) ;
}
STATIC void
F_112 (
struct V_7 * V_7 )
{
struct V_15 * V_15 = V_7 -> V_117 -> V_140 ;
struct V_16 * V_4 = F_15 ( V_15 ) ;
struct V_10 * V_11 , * V_12 ;
T_6 V_57 = F_95 ( V_7 ) ;
if ( ! F_91 ( V_7 , V_78 ) )
goto V_141;
if ( F_33 ( V_4 -> V_19 ) )
goto V_141;
F_113 ( V_4 -> V_19 ,
L_1 ,
V_7 , V_4 -> V_142 , V_57 ) ;
F_45 ( V_4 , V_41 ) ;
V_11 = V_12 = F_11 ( V_7 ) ;
do {
int error ;
T_8 V_143 ;
if ( ! F_13 ( V_11 ) )
goto V_144;
V_143 = F_47 ( V_4 -> V_19 , V_57 ) ;
error = F_114 ( V_4 , V_143 , 1 ) ;
if ( error ) {
if ( ! F_33 ( V_4 -> V_19 ) ) {
F_113 ( V_4 -> V_19 ,
L_2 ) ;
}
break;
}
V_144:
V_57 += 1 << V_15 -> V_62 ;
} while ( ( V_11 = V_11 -> V_13 ) != V_12 );
F_27 ( V_4 , V_41 ) ;
V_141:
F_109 ( V_7 , 0 ) ;
return;
}
STATIC int
F_115 (
struct V_7 * V_7 ,
struct V_90 * V_91 )
{
struct V_15 * V_15 = V_7 -> V_117 -> V_140 ;
int V_8 , V_9 ;
struct V_10 * V_11 , * V_12 ;
struct V_58 V_59 ;
T_4 * V_23 = NULL , * V_145 = NULL ;
T_6 V_57 ;
unsigned int type ;
T_13 V_122 ;
T_12 V_146 , V_147 ;
T_7 V_124 ;
int V_148 , V_149 = 0 , V_127 = 1 ;
int V_61 = 0 ;
int V_60 = 0 ;
F_116 ( V_15 , V_7 , 0 ) ;
ASSERT ( F_92 ( V_7 ) ) ;
if ( ( V_150 -> V_151 & ( V_152 | V_153 ) ) == V_152 )
goto V_154;
F_10 ( V_7 , & V_8 , & V_9 ) ;
if ( ( V_150 -> V_151 & V_155 ) && ( V_8 || V_9 ) )
goto V_154;
V_57 = F_117 ( V_15 ) ;
V_146 = V_57 >> V_156 ;
V_147 = ( V_57 - 1 ) >> V_156 ;
if ( V_7 -> V_128 >= V_146 ) {
if ( ( V_7 -> V_128 >= V_146 + 1 ) ||
! ( F_117 ( V_15 ) & ( V_132 - 1 ) ) ) {
F_74 ( V_7 ) ;
return 0 ;
}
}
V_122 = F_97 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
offset) ;
V_124 = 1 << V_15 -> V_62 ;
V_11 = V_12 = F_11 ( V_7 ) ;
V_57 = F_95 ( V_7 ) ;
type = V_119 ;
if ( V_91 -> V_92 == V_134 && V_91 -> V_60 )
V_60 = 1 ;
do {
int V_157 = 0 ;
if ( V_57 >= V_122 )
break;
if ( ! F_99 ( V_11 ) )
V_127 = 0 ;
if ( ! F_64 ( V_11 ) && F_99 ( V_11 ) ) {
V_149 = 0 ;
continue;
}
if ( F_12 ( V_11 ) ) {
if ( type != V_46 ) {
type = V_46 ;
V_149 = 0 ;
}
} else if ( F_13 ( V_11 ) ) {
if ( type != V_78 ) {
type = V_78 ;
V_149 = 0 ;
}
} else if ( F_99 ( V_11 ) ) {
if ( type != V_119 ) {
type = V_119 ;
V_149 = 0 ;
}
} else {
if ( F_100 ( V_7 ) ) {
ASSERT ( F_64 ( V_11 ) ) ;
V_149 = 0 ;
}
continue;
}
if ( V_149 )
V_149 = F_54 ( V_15 , & V_59 , V_57 ) ;
if ( ! V_149 ) {
V_157 = 1 ;
V_148 = F_43 ( V_15 , V_57 , & V_59 , type ,
V_60 ) ;
if ( V_148 )
goto error;
V_149 = F_54 ( V_15 , & V_59 , V_57 ) ;
}
if ( V_149 ) {
F_101 ( V_11 ) ;
if ( type != V_119 )
F_88 ( V_15 , V_11 , & V_59 , V_57 ) ;
F_83 ( V_15 , V_11 , V_57 , type , & V_23 ,
V_157 ) ;
V_61 ++ ;
}
if ( ! V_145 )
V_145 = V_23 ;
} while ( V_57 += V_124 , ( ( V_11 = V_11 -> V_13 ) != V_12 ) );
if ( V_127 && V_11 == V_12 )
F_102 ( V_7 ) ;
F_69 ( V_7 , 1 , V_61 ) ;
if ( V_23 && V_149 ) {
T_9 V_146 ;
V_146 = V_59 . V_82 + V_59 . V_83 ;
V_146 <<= V_15 -> V_62 ;
V_146 = ( V_146 - 1 ) >> V_156 ;
if ( V_146 > V_147 )
V_146 = V_147 ;
F_103 ( V_15 , V_7 -> V_128 + 1 , & V_59 , & V_23 ,
V_91 , V_146 ) ;
}
if ( V_145 )
F_79 ( V_91 , V_145 ) ;
return 0 ;
error:
if ( V_145 )
F_80 ( V_145 ) ;
if ( V_148 == - V_42 )
goto V_154;
F_112 ( V_7 ) ;
F_118 ( V_7 ) ;
F_74 ( V_7 ) ;
return V_148 ;
V_154:
F_119 ( V_91 , V_7 ) ;
F_74 ( V_7 ) ;
return 0 ;
}
STATIC int
F_120 (
struct V_158 * V_117 ,
struct V_90 * V_91 )
{
F_121 ( F_15 ( V_117 -> V_140 ) , V_159 ) ;
return F_122 ( V_117 , V_91 ) ;
}
STATIC int
F_123 (
struct V_7 * V_7 ,
T_14 V_160 )
{
int V_8 , V_9 ;
F_124 ( V_7 -> V_117 -> V_140 , V_7 , 0 ) ;
F_10 ( V_7 , & V_8 , & V_9 ) ;
if ( F_125 ( V_8 ) )
return 0 ;
if ( F_125 ( V_9 ) )
return 0 ;
return F_126 ( V_7 ) ;
}
STATIC int
F_127 (
struct V_15 * V_15 ,
T_10 V_161 ,
struct V_10 * V_162 ,
int V_163 ,
int V_164 )
{
struct V_16 * V_4 = F_15 ( V_15 ) ;
struct V_17 * V_18 = V_4 -> V_19 ;
T_8 V_63 , V_64 ;
int error = 0 ;
int V_165 = 0 ;
struct V_58 V_59 ;
int V_67 = 1 ;
T_9 V_57 ;
T_7 V_166 ;
int V_167 = 0 ;
if ( F_33 ( V_18 ) )
return - F_44 ( V_68 ) ;
V_57 = ( T_9 ) V_161 << V_15 -> V_62 ;
ASSERT ( V_162 -> V_101 >= ( 1 << V_15 -> V_62 ) ) ;
V_166 = V_162 -> V_101 ;
if ( ! V_163 && V_164 && V_57 >= F_117 ( V_15 ) )
return 0 ;
if ( V_163 ) {
V_165 = V_41 ;
F_45 ( V_4 , V_165 ) ;
} else {
V_165 = F_128 ( V_4 ) ;
}
ASSERT ( V_57 <= V_18 -> V_76 ) ;
if ( V_57 + V_166 > V_18 -> V_76 )
V_166 = V_18 -> V_76 - V_57 ;
V_64 = F_46 ( V_18 , ( V_77 ) V_57 + V_166 ) ;
V_63 = F_47 ( V_18 , V_57 ) ;
error = F_48 ( NULL , V_4 , V_63 , V_64 - V_63 ,
V_66 , NULL , 0 , & V_59 , & V_67 , NULL ) ;
if ( error )
goto V_168;
if ( V_163 &&
( ! V_67 ||
( V_59 . V_79 == V_80 ||
V_59 . V_79 == V_81 ) ) ) {
if ( V_164 ) {
error = F_129 ( V_4 , V_57 , V_166 ,
& V_59 , V_67 ) ;
} else {
error = F_130 ( V_4 , V_57 , V_166 , & V_59 ) ;
}
if ( error )
goto V_168;
F_131 ( V_4 , V_57 , V_166 , 0 , & V_59 ) ;
} else if ( V_67 ) {
F_132 ( V_4 , V_57 , V_166 , 0 , & V_59 ) ;
} else {
F_133 ( V_4 , V_57 , V_166 ) ;
goto V_168;
}
F_27 ( V_4 , V_165 ) ;
if ( V_59 . V_79 != V_80 &&
V_59 . V_79 != V_81 ) {
if ( V_163 || ! F_134 ( & V_59 ) )
F_84 ( V_15 , V_162 , & V_59 , V_57 ) ;
if ( V_163 && F_134 ( & V_59 ) ) {
if ( V_164 )
V_162 -> V_27 = V_15 ;
F_135 ( V_162 ) ;
}
}
V_162 -> V_97 = F_14 ( V_15 ) ;
if ( V_163 &&
( ( ! F_64 ( V_162 ) && ! F_99 ( V_162 ) ) ||
( V_57 >= F_117 ( V_15 ) ) ||
( V_167 || F_134 ( & V_59 ) ) ) )
F_136 ( V_162 ) ;
if ( V_59 . V_79 == V_81 ) {
F_137 ( V_164 ) ;
if ( V_163 ) {
F_67 ( V_162 ) ;
F_87 ( V_162 ) ;
F_138 ( V_162 ) ;
}
}
if ( V_164 || V_166 > ( 1 << V_15 -> V_62 ) ) {
T_9 V_169 ;
V_169 = V_59 . V_82 + V_59 . V_83 - V_161 ;
V_169 <<= V_15 -> V_62 ;
ASSERT ( V_169 > 0 ) ;
if ( V_169 > V_166 )
V_169 = V_166 ;
if ( V_169 > V_170 )
V_169 = V_170 ;
V_162 -> V_101 = V_169 ;
}
return 0 ;
V_168:
F_27 ( V_4 , V_165 ) ;
return - error ;
}
int
F_139 (
struct V_15 * V_15 ,
T_10 V_161 ,
struct V_10 * V_162 ,
int V_163 )
{
return F_127 ( V_15 , V_161 , V_162 , V_163 , 0 ) ;
}
STATIC int
F_140 (
struct V_15 * V_15 ,
T_10 V_161 ,
struct V_10 * V_162 ,
int V_163 )
{
return F_127 ( V_15 , V_161 , V_162 , V_163 , 1 ) ;
}
STATIC void
F_141 (
struct V_171 * V_172 ,
T_6 V_57 ,
T_7 V_166 ,
void * V_173 ,
int V_174 ,
bool V_175 )
{
struct V_43 * V_23 = V_172 -> V_173 ;
V_172 -> V_173 = NULL ;
V_23 -> V_35 = V_57 ;
V_23 -> V_36 = V_166 ;
if ( V_173 && V_166 > 0 )
V_23 -> V_45 = V_46 ;
if ( V_175 ) {
if ( V_23 -> V_45 == V_46 ) {
V_23 -> V_52 = V_172 ;
V_23 -> V_53 = V_174 ;
} else {
F_37 ( V_172 , V_174 , 0 ) ;
}
F_28 ( V_23 ) ;
} else {
F_38 ( V_23 ) ;
}
}
STATIC T_7
F_142 (
int V_176 ,
struct V_171 * V_172 ,
const struct V_177 * V_178 ,
T_6 V_57 ,
unsigned long V_179 )
{
struct V_15 * V_15 = V_172 -> V_180 -> V_181 -> V_140 ;
struct V_14 * V_182 = F_14 ( V_15 ) ;
T_7 V_174 ;
if ( V_176 & V_95 ) {
V_172 -> V_173 = F_39 ( V_15 , V_183 ) ;
V_174 = F_143 ( V_176 , V_172 , V_15 , V_182 , V_178 ,
V_57 , V_179 ,
F_140 ,
F_141 , NULL , 0 ) ;
if ( V_174 != - V_184 && V_172 -> V_173 )
F_17 ( V_172 -> V_173 ) ;
} else {
V_174 = F_143 ( V_176 , V_172 , V_15 , V_182 , V_178 ,
V_57 , V_179 ,
F_140 ,
NULL , NULL , 0 ) ;
}
return V_174 ;
}
STATIC void
F_144 (
struct V_158 * V_117 ,
T_6 V_185 )
{
struct V_15 * V_15 = V_117 -> V_140 ;
if ( V_185 > V_15 -> V_37 ) {
struct V_16 * V_4 = F_15 ( V_15 ) ;
T_8 V_143 ;
T_8 V_64 ;
int error ;
F_145 ( V_15 , V_185 , V_15 -> V_37 ) ;
V_143 = F_46 ( V_4 -> V_19 , V_15 -> V_37 ) + 1 ;
V_64 = F_46 ( V_4 -> V_19 , V_185 ) ;
if ( V_64 <= V_143 )
return;
F_45 ( V_4 , V_41 ) ;
error = F_114 ( V_4 , V_143 ,
V_64 - V_143 ) ;
if ( error ) {
if ( ! F_33 ( V_4 -> V_19 ) ) {
F_113 ( V_4 -> V_19 ,
L_3 ,
V_4 -> V_142 ) ;
}
}
F_27 ( V_4 , V_41 ) ;
}
}
STATIC int
F_146 (
struct V_186 * V_186 ,
struct V_158 * V_117 ,
T_6 V_187 ,
unsigned V_124 ,
unsigned V_151 ,
struct V_7 * * V_188 ,
void * * V_189 )
{
int V_174 ;
V_174 = F_147 ( V_117 , V_187 , V_124 , V_151 | V_190 ,
V_188 , F_139 ) ;
if ( F_18 ( V_174 ) )
F_144 ( V_117 , V_187 + V_124 ) ;
return V_174 ;
}
STATIC int
F_148 (
struct V_186 * V_186 ,
struct V_158 * V_117 ,
T_6 V_187 ,
unsigned V_124 ,
unsigned V_191 ,
struct V_7 * V_7 ,
void * V_189 )
{
int V_174 ;
V_174 = F_149 ( V_186 , V_117 , V_187 , V_124 , V_191 , V_7 , V_189 ) ;
if ( F_18 ( V_174 < V_124 ) )
F_144 ( V_117 , V_187 + V_124 ) ;
return V_174 ;
}
STATIC T_10
F_150 (
struct V_158 * V_117 ,
T_10 V_192 )
{
struct V_15 * V_15 = (struct V_15 * ) V_117 -> V_140 ;
struct V_16 * V_4 = F_15 ( V_15 ) ;
F_151 ( F_15 ( V_15 ) ) ;
F_45 ( V_4 , V_193 ) ;
F_152 ( V_4 , ( T_9 ) 0 , - 1 , 0 , V_194 ) ;
F_27 ( V_4 , V_193 ) ;
return F_153 ( V_117 , V_192 , F_139 ) ;
}
STATIC int
F_154 (
struct V_186 * V_195 ,
struct V_7 * V_7 )
{
return F_155 ( V_7 , F_139 ) ;
}
STATIC int
F_156 (
struct V_186 * V_195 ,
struct V_158 * V_117 ,
struct V_196 * V_139 ,
unsigned V_197 )
{
return F_157 ( V_117 , V_139 , V_197 , F_139 ) ;
}
