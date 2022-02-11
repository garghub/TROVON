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
F_18 ( & V_18 -> V_27 -> V_38 -> V_39 . V_40 [ V_41 - 1 ] ,
1 , V_42 ) ;
F_19 ( & V_35 -> V_43 , V_44 ) ;
return 0 ;
}
STATIC int
F_20 (
struct V_29 * V_18 )
{
struct V_10 * V_11 = F_6 ( V_18 -> V_27 ) ;
struct V_34 * V_35 = V_18 -> V_37 ;
T_2 V_45 ;
F_21 ( & V_35 -> V_43 , V_44 ) ;
F_22 ( V_11 , V_46 ) ;
V_45 = F_23 ( V_11 , V_18 -> V_30 + V_18 -> V_31 ) ;
if ( ! V_45 ) {
F_24 ( V_11 , V_46 ) ;
F_17 ( V_35 , 0 ) ;
return 0 ;
}
F_25 ( V_11 , V_18 -> V_30 , V_18 -> V_31 ) ;
V_11 -> V_32 . V_33 = V_45 ;
F_26 ( V_35 , V_11 , V_46 ) ;
F_27 ( V_35 , V_11 , V_47 ) ;
return F_28 ( V_35 , 0 ) ;
}
STATIC void
F_29 (
struct V_29 * V_18 )
{
if ( F_30 ( & V_18 -> V_48 ) ) {
struct V_12 * V_13 = F_6 ( V_18 -> V_27 ) -> V_14 ;
if ( V_18 -> V_49 == V_50 )
F_31 ( V_13 -> V_51 , & V_18 -> V_52 ) ;
else if ( V_18 -> V_37 )
F_31 ( V_13 -> V_53 , & V_18 -> V_52 ) ;
else
F_8 ( V_18 ) ;
}
}
STATIC void
F_32 (
struct V_54 * V_55 )
{
T_1 * V_18 = F_33 ( V_55 , T_1 , V_52 ) ;
struct V_10 * V_11 = F_6 ( V_18 -> V_27 ) ;
int error = 0 ;
if ( V_18 -> V_37 ) {
F_34 (
& V_18 -> V_27 -> V_38 -> V_39 . V_40 [ V_41 - 1 ] ,
0 , 1 , V_42 ) ;
}
if ( F_35 ( V_11 -> V_14 ) ) {
V_18 -> V_23 = - V_56 ;
goto V_57;
}
if ( V_18 -> V_23 )
goto V_57;
if ( V_18 -> V_49 == V_50 ) {
if ( V_18 -> V_37 ) {
ASSERT ( V_18 -> V_58 ) ;
F_21 (
& V_18 -> V_37 -> V_43 , V_44 ) ;
F_17 ( V_18 -> V_37 , 0 ) ;
}
error = F_36 ( V_11 , V_18 -> V_30 ,
V_18 -> V_31 ) ;
if ( error ) {
V_18 -> V_23 = - error ;
goto V_57;
}
} else if ( V_18 -> V_37 ) {
error = F_20 ( V_18 ) ;
if ( error )
V_18 -> V_23 = - error ;
} else {
ASSERT ( ! F_12 ( V_18 ) ) ;
}
V_57:
F_8 ( V_18 ) ;
}
STATIC void
F_37 (
struct V_29 * V_18 )
{
if ( F_30 ( & V_18 -> V_48 ) )
F_32 ( & V_18 -> V_52 ) ;
}
STATIC T_1 *
F_38 (
struct V_9 * V_9 ,
unsigned int type )
{
T_1 * V_18 ;
V_18 = F_39 ( V_28 , V_59 ) ;
F_40 ( & V_18 -> V_48 , 1 ) ;
V_18 -> V_25 = 0 ;
V_18 -> V_58 = 0 ;
V_18 -> V_23 = 0 ;
V_18 -> V_60 = NULL ;
V_18 -> V_49 = type ;
V_18 -> V_27 = V_9 ;
V_18 -> V_20 = NULL ;
V_18 -> V_61 = NULL ;
V_18 -> V_30 = 0 ;
V_18 -> V_31 = 0 ;
V_18 -> V_24 = NULL ;
V_18 -> V_26 = 0 ;
V_18 -> V_37 = NULL ;
F_41 ( & V_18 -> V_52 , F_32 ) ;
return V_18 ;
}
STATIC int
F_42 (
struct V_9 * V_9 ,
T_3 V_62 ,
struct V_63 * V_64 ,
int type ,
int V_65 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_4 V_66 = 1 << V_9 -> V_67 ;
T_5 V_68 , V_69 ;
int error = 0 ;
int V_70 = V_71 ;
int V_72 = 1 ;
if ( F_35 ( V_13 ) )
return - F_43 ( V_56 ) ;
if ( type == V_50 )
V_70 |= V_73 ;
if ( ! F_44 ( V_11 , V_74 ) ) {
if ( V_65 )
return - F_43 ( V_75 ) ;
F_22 ( V_11 , V_74 ) ;
}
ASSERT ( V_11 -> V_32 . V_76 != V_77 ||
( V_11 -> V_78 . V_79 & V_80 ) ) ;
ASSERT ( V_62 <= V_13 -> V_81 -> V_82 ) ;
if ( V_62 + V_66 > V_13 -> V_81 -> V_82 )
V_66 = V_13 -> V_81 -> V_82 - V_62 ;
V_69 = F_45 ( V_13 , ( V_83 ) V_62 + V_66 ) ;
V_68 = F_46 ( V_13 , V_62 ) ;
error = F_47 ( V_11 , V_68 , V_69 - V_68 ,
V_64 , & V_72 , V_70 ) ;
F_24 ( V_11 , V_74 ) ;
if ( error )
return - F_43 ( error ) ;
if ( type == V_84 &&
( ! V_72 || F_48 ( V_64 -> V_85 ) ) ) {
error = F_49 ( V_11 , V_62 , V_66 , V_64 ) ;
if ( ! error )
F_50 ( V_11 , V_62 , V_66 , type , V_64 ) ;
return - F_43 ( error ) ;
}
#ifdef F_51
if ( type == V_50 ) {
ASSERT ( V_72 ) ;
ASSERT ( V_64 -> V_85 != V_86 ) ;
ASSERT ( V_64 -> V_85 != V_87 ) ;
}
#endif
if ( V_72 )
F_52 ( V_11 , V_62 , V_66 , type , V_64 ) ;
return 0 ;
}
STATIC int
F_53 (
struct V_9 * V_9 ,
struct V_63 * V_64 ,
T_6 V_62 )
{
V_62 >>= V_9 -> V_67 ;
return V_62 >= V_64 -> V_88 &&
V_62 < V_64 -> V_88 + V_64 -> V_89 ;
}
STATIC void
F_54 (
struct V_90 * V_90 ,
int error )
{
T_1 * V_18 = V_90 -> V_91 ;
ASSERT ( F_55 ( & V_90 -> V_92 ) >= 1 ) ;
V_18 -> V_23 = F_56 ( V_93 , & V_90 -> V_94 ) ? 0 : error ;
V_90 -> V_91 = NULL ;
V_90 -> V_95 = NULL ;
F_57 ( V_90 ) ;
F_29 ( V_18 ) ;
}
STATIC void
F_58 (
struct V_96 * V_97 ,
T_1 * V_18 ,
struct V_90 * V_90 )
{
F_59 ( & V_18 -> V_48 ) ;
V_90 -> V_91 = V_18 ;
V_90 -> V_95 = F_54 ;
F_60 ( V_97 -> V_98 == V_99 ? V_100 : V_101 , V_90 ) ;
}
STATIC struct V_90 *
F_61 (
struct V_4 * V_5 )
{
int V_102 = F_62 ( V_5 -> V_103 ) ;
struct V_90 * V_90 = F_63 ( V_104 , V_102 ) ;
ASSERT ( V_90 -> V_91 == NULL ) ;
V_90 -> V_105 = V_5 -> V_106 * ( V_5 -> V_107 >> 9 ) ;
V_90 -> V_108 = V_5 -> V_103 ;
return V_90 ;
}
STATIC void
F_64 (
struct V_4 * V_5 )
{
ASSERT ( F_65 ( V_5 ) ) ;
ASSERT ( F_66 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_67 ( V_5 ) ;
F_68 ( V_5 ) ;
F_69 ( V_5 ) ;
}
STATIC void
F_70 (
struct V_1 * V_1 ,
int V_109 ,
int V_110 )
{
ASSERT ( F_71 ( V_1 ) ) ;
ASSERT ( ! F_72 ( V_1 ) ) ;
if ( V_109 )
F_73 ( V_1 ) ;
F_74 ( V_1 ) ;
F_75 ( V_1 ) ;
if ( ! V_110 )
F_76 ( V_1 ) ;
}
static inline int F_77 ( struct V_90 * V_90 , struct V_4 * V_5 )
{
return F_78 ( V_90 , V_5 -> V_111 , V_5 -> V_107 , F_79 ( V_5 ) ) ;
}
STATIC void
F_80 (
struct V_96 * V_97 ,
T_1 * V_18 )
{
T_1 * V_6 = V_18 ;
T_1 * V_19 ;
struct V_4 * V_5 ;
struct V_90 * V_90 ;
T_7 V_112 = 0 ;
do {
V_19 = V_18 -> V_60 ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 )
F_64 ( V_5 ) ;
} while ( ( V_18 = V_19 ) != NULL );
V_18 = V_6 ;
do {
V_19 = V_18 -> V_60 ;
V_90 = NULL ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 ) {
if ( ! V_90 ) {
V_113:
V_90 = F_61 ( V_5 ) ;
} else if ( V_5 -> V_106 != V_112 + 1 ) {
F_58 ( V_97 , V_18 , V_90 ) ;
goto V_113;
}
if ( F_77 ( V_90 , V_5 ) != V_5 -> V_107 ) {
F_58 ( V_97 , V_18 , V_90 ) ;
goto V_113;
}
V_112 = V_5 -> V_106 ;
}
if ( V_90 )
F_58 ( V_97 , V_18 , V_90 ) ;
F_29 ( V_18 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_81 (
T_1 * V_18 )
{
T_1 * V_19 ;
struct V_4 * V_5 , * V_114 ;
do {
V_19 = V_18 -> V_60 ;
V_5 = V_18 -> V_20 ;
do {
V_114 = V_5 -> V_21 ;
F_82 ( V_5 ) ;
F_83 ( V_5 ) ;
} while ( ( V_5 = V_114 ) != NULL );
F_11 ( V_18 , V_28 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_84 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_6 V_62 ,
unsigned int type ,
T_1 * * V_115 ,
int V_116 )
{
T_1 * V_18 = * V_115 ;
if ( ! V_18 || V_116 || type != V_18 -> V_49 ) {
T_1 * V_117 = * V_115 ;
V_18 = F_38 ( V_9 , type ) ;
V_18 -> V_30 = V_62 ;
V_18 -> V_20 = V_5 ;
V_18 -> V_61 = V_5 ;
if ( V_117 )
V_117 -> V_60 = V_18 ;
* V_115 = V_18 ;
} else {
V_18 -> V_61 -> V_21 = V_5 ;
V_18 -> V_61 = V_5 ;
}
V_5 -> V_21 = NULL ;
V_18 -> V_31 += V_5 -> V_107 ;
}
STATIC void
F_85 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_63 * V_64 ,
T_6 V_62 )
{
T_7 V_118 ;
struct V_12 * V_119 = F_6 ( V_9 ) -> V_14 ;
T_6 V_120 = F_86 ( V_119 , V_64 -> V_88 ) ;
T_8 V_121 = F_87 ( F_6 ( V_9 ) , V_64 -> V_85 ) ;
ASSERT ( V_64 -> V_85 != V_86 ) ;
ASSERT ( V_64 -> V_85 != V_87 ) ;
V_118 = ( V_121 >> ( V_9 -> V_67 - V_122 ) ) +
( ( V_62 - V_120 ) >> V_9 -> V_67 ) ;
ASSERT ( V_118 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_106 = V_118 ;
F_88 ( V_5 ) ;
}
STATIC void
F_89 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_63 * V_64 ,
T_6 V_62 )
{
ASSERT ( V_64 -> V_85 != V_86 ) ;
ASSERT ( V_64 -> V_85 != V_87 ) ;
F_85 ( V_9 , V_5 , V_64 , V_62 ) ;
F_88 ( V_5 ) ;
F_90 ( V_5 ) ;
F_91 ( V_5 ) ;
}
STATIC int
F_92 (
struct V_1 * V_1 ,
unsigned int type )
{
if ( F_72 ( V_1 ) )
return 0 ;
if ( V_1 -> V_123 && F_93 ( V_1 ) ) {
struct V_4 * V_5 , * V_6 ;
int V_124 = 0 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) )
V_124 += ( type == V_50 ) ;
else if ( F_4 ( V_5 ) )
V_124 += ( type == V_84 ) ;
else if ( F_94 ( V_5 ) && F_65 ( V_5 ) )
V_124 += ( type == V_125 ) ;
else
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_124 )
return 1 ;
}
return 0 ;
}
STATIC int
F_95 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_3 V_126 ,
struct V_63 * V_64 ,
T_1 * * V_127 ,
struct V_96 * V_97 )
{
struct V_4 * V_5 , * V_6 ;
T_6 V_128 ;
unsigned long V_129 ;
unsigned int type ;
int V_130 , V_131 ;
int V_66 = 0 , V_57 = 0 , V_132 = 1 ;
T_6 V_62 = F_96 ( V_1 ) ;
if ( V_1 -> V_133 != V_126 )
goto V_134;
if ( ! F_97 ( V_1 ) )
goto V_134;
if ( F_72 ( V_1 ) )
goto V_135;
if ( V_1 -> V_123 != V_9 -> V_136 )
goto V_135;
if ( ! F_92 ( V_1 , ( * V_127 ) -> V_49 ) )
goto V_135;
V_128 = F_98 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode)) ;
V_130 = 1 << V_9 -> V_67 ;
V_129 = F_98 (unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE) ;
V_129 = V_129 ? F_99 ( V_129 , V_130 ) : V_137 ;
V_131 = V_129 / V_130 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( V_62 >= V_128 )
break;
if ( ! F_100 ( V_5 ) )
V_132 = 0 ;
if ( ! ( F_101 ( V_1 ) || F_100 ( V_5 ) ) ) {
V_57 = 1 ;
continue;
}
if ( F_3 ( V_5 ) || F_4 ( V_5 ) ||
F_65 ( V_5 ) ) {
if ( F_3 ( V_5 ) )
type = V_50 ;
else if ( F_4 ( V_5 ) )
type = V_84 ;
else
type = V_125 ;
if ( ! F_53 ( V_9 , V_64 , V_62 ) ) {
V_57 = 1 ;
continue;
}
F_102 ( V_5 ) ;
if ( type != V_125 )
F_89 ( V_9 , V_5 , V_64 , V_62 ) ;
F_84 ( V_9 , V_5 , V_62 , type ,
V_127 , V_57 ) ;
V_131 -- ;
V_66 ++ ;
} else {
V_57 = 1 ;
}
} while ( V_62 += V_130 , ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_132 && V_5 == V_6 )
F_103 ( V_1 ) ;
if ( V_66 ) {
if ( -- V_97 -> V_138 <= 0 &&
V_97 -> V_98 == V_139 )
V_57 = 1 ;
}
F_70 ( V_1 , ! V_131 , V_66 ) ;
return V_57 ;
V_135:
F_75 ( V_1 ) ;
V_134:
return 1 ;
}
STATIC void
F_104 (
struct V_9 * V_9 ,
T_9 V_126 ,
struct V_63 * V_64 ,
T_1 * * V_127 ,
struct V_96 * V_97 ,
T_9 V_140 )
{
struct V_141 V_142 ;
int V_57 = 0 , V_143 ;
F_105 ( & V_142 , 0 ) ;
while ( ! V_57 && V_126 <= V_140 ) {
unsigned V_130 = F_98 ( T_9 , V_144 , V_140 - V_126 + 1 ) ;
if ( ! F_106 ( & V_142 , V_9 -> V_136 , V_126 , V_130 ) )
break;
for ( V_143 = 0 ; V_143 < F_107 ( & V_142 ) ; V_143 ++ ) {
V_57 = F_95 ( V_9 , V_142 . V_145 [ V_143 ] , V_126 ++ ,
V_64 , V_127 , V_97 ) ;
if ( V_57 )
break;
}
F_108 ( & V_142 ) ;
F_109 () ;
}
}
STATIC void
F_110 (
struct V_1 * V_1 ,
unsigned long V_62 )
{
F_111 ( V_1 -> V_123 -> V_146 , V_1 , V_62 ) ;
F_112 ( V_1 , V_62 ) ;
}
STATIC void
F_113 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_123 -> V_146 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_3 V_62 = F_96 ( V_1 ) ;
if ( ! F_92 ( V_1 , V_84 ) )
goto V_147;
if ( F_35 ( V_11 -> V_14 ) )
goto V_147;
F_114 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_148 , V_62 ) ;
F_22 ( V_11 , V_46 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_5 V_149 ;
if ( ! F_4 ( V_5 ) )
goto V_150;
V_149 = F_46 ( V_11 -> V_14 , V_62 ) ;
error = F_115 ( V_11 , V_149 , 1 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_114 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_150:
V_62 += 1 << V_9 -> V_67 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_24 ( V_11 , V_46 ) ;
V_147:
F_110 ( V_1 , 0 ) ;
return;
}
STATIC int
F_116 (
struct V_1 * V_1 ,
struct V_96 * V_97 )
{
struct V_9 * V_9 = V_1 -> V_123 -> V_146 ;
struct V_4 * V_5 , * V_6 ;
struct V_63 V_64 ;
T_1 * V_18 = NULL , * V_151 = NULL ;
T_3 V_62 ;
unsigned int type ;
T_10 V_128 ;
T_9 V_152 , V_153 ;
T_4 V_130 ;
int V_154 , V_155 = 0 , V_132 = 1 ;
int V_66 = 0 ;
int V_65 = 0 ;
F_117 ( V_9 , V_1 , 0 ) ;
ASSERT ( F_93 ( V_1 ) ) ;
if ( F_118 ( ( V_156 -> V_157 & ( V_158 | V_159 ) ) ==
V_158 ) )
goto V_160;
if ( F_119 ( V_156 -> V_157 & V_44 ) )
goto V_160;
V_62 = F_120 ( V_9 ) ;
V_152 = V_62 >> V_161 ;
V_153 = ( V_62 - 1 ) >> V_161 ;
if ( V_1 -> V_133 >= V_152 ) {
unsigned V_162 = V_62 & ( V_137 - 1 ) ;
if ( V_1 -> V_133 >= V_152 + 1 || V_162 == 0 ) {
F_75 ( V_1 ) ;
return 0 ;
}
F_121 ( V_1 , V_162 , V_137 ) ;
}
V_128 = F_98 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
offset) ;
V_130 = 1 << V_9 -> V_67 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_62 = F_96 ( V_1 ) ;
type = V_125 ;
if ( V_97 -> V_98 == V_139 )
V_65 = 1 ;
do {
int V_163 = 0 ;
if ( V_62 >= V_128 )
break;
if ( ! F_100 ( V_5 ) )
V_132 = 0 ;
if ( ! F_65 ( V_5 ) && F_100 ( V_5 ) ) {
V_155 = 0 ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( type != V_50 ) {
type = V_50 ;
V_155 = 0 ;
}
} else if ( F_4 ( V_5 ) ) {
if ( type != V_84 ) {
type = V_84 ;
V_155 = 0 ;
}
} else if ( F_100 ( V_5 ) ) {
if ( type != V_125 ) {
type = V_125 ;
V_155 = 0 ;
}
} else {
if ( F_101 ( V_1 ) )
ASSERT ( F_65 ( V_5 ) ) ;
V_155 = 0 ;
continue;
}
if ( V_155 )
V_155 = F_53 ( V_9 , & V_64 , V_62 ) ;
if ( ! V_155 ) {
V_163 = 1 ;
V_154 = F_42 ( V_9 , V_62 , & V_64 , type ,
V_65 ) ;
if ( V_154 )
goto error;
V_155 = F_53 ( V_9 , & V_64 , V_62 ) ;
}
if ( V_155 ) {
F_102 ( V_5 ) ;
if ( type != V_125 )
F_89 ( V_9 , V_5 , & V_64 , V_62 ) ;
F_84 ( V_9 , V_5 , V_62 , type , & V_18 ,
V_163 ) ;
V_66 ++ ;
}
if ( ! V_151 )
V_151 = V_18 ;
} while ( V_62 += V_130 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_132 && V_5 == V_6 )
F_103 ( V_1 ) ;
F_70 ( V_1 , 1 , V_66 ) ;
if ( V_18 && V_155 ) {
T_6 V_152 ;
V_152 = V_64 . V_88 + V_64 . V_89 ;
V_152 <<= V_9 -> V_67 ;
V_152 = ( V_152 - 1 ) >> V_161 ;
if ( V_152 > V_153 )
V_152 = V_153 ;
F_104 ( V_9 , V_1 -> V_133 + 1 , & V_64 , & V_18 ,
V_97 , V_152 ) ;
}
if ( V_151 ) {
if ( V_18 -> V_49 != V_50 &&
F_12 ( V_18 ) ) {
V_154 = F_13 ( V_18 ) ;
if ( V_154 )
goto error;
}
F_80 ( V_97 , V_151 ) ;
}
return 0 ;
error:
if ( V_151 )
F_81 ( V_151 ) ;
if ( V_154 == - V_75 )
goto V_160;
F_113 ( V_1 ) ;
F_122 ( V_1 ) ;
F_75 ( V_1 ) ;
return V_154 ;
V_160:
F_123 ( V_97 , V_1 ) ;
F_75 ( V_1 ) ;
return 0 ;
}
STATIC int
F_124 (
struct V_164 * V_123 ,
struct V_96 * V_97 )
{
F_125 ( F_6 ( V_123 -> V_146 ) , V_165 ) ;
return F_126 ( V_123 , V_97 ) ;
}
STATIC int
F_127 (
struct V_1 * V_1 ,
T_11 V_166 )
{
int V_2 , V_3 ;
F_128 ( V_1 -> V_123 -> V_146 , V_1 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_119 ( V_2 ) )
return 0 ;
if ( F_119 ( V_3 ) )
return 0 ;
return F_129 ( V_1 ) ;
}
STATIC int
F_130 (
struct V_9 * V_9 ,
T_7 V_167 ,
struct V_4 * V_168 ,
int V_169 ,
int V_170 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_5 V_68 , V_69 ;
int error = 0 ;
int V_171 = 0 ;
struct V_63 V_64 ;
int V_72 = 1 ;
T_6 V_62 ;
T_4 V_172 ;
int V_173 = 0 ;
if ( F_35 ( V_13 ) )
return - F_43 ( V_56 ) ;
V_62 = ( T_6 ) V_167 << V_9 -> V_67 ;
ASSERT ( V_168 -> V_107 >= ( 1 << V_9 -> V_67 ) ) ;
V_172 = V_168 -> V_107 ;
if ( ! V_169 && V_170 && V_62 >= F_120 ( V_9 ) )
return 0 ;
if ( V_169 && ! V_170 ) {
V_171 = V_46 ;
F_22 ( V_11 , V_171 ) ;
} else {
V_171 = F_131 ( V_11 ) ;
}
ASSERT ( V_62 <= V_13 -> V_81 -> V_82 ) ;
if ( V_62 + V_172 > V_13 -> V_81 -> V_82 )
V_172 = V_13 -> V_81 -> V_82 - V_62 ;
V_69 = F_45 ( V_13 , ( V_83 ) V_62 + V_172 ) ;
V_68 = F_46 ( V_13 , V_62 ) ;
error = F_47 ( V_11 , V_68 , V_69 - V_68 ,
& V_64 , & V_72 , V_71 ) ;
if ( error )
goto V_174;
if ( V_169 &&
( ! V_72 ||
( V_64 . V_85 == V_86 ||
V_64 . V_85 == V_87 ) ) ) {
if ( V_170 || F_132 ( V_11 ) ) {
F_24 ( V_11 , V_171 ) ;
error = F_133 ( V_11 , V_62 , V_172 ,
& V_64 , V_72 ) ;
if ( error )
return - error ;
V_173 = 1 ;
} else {
if ( V_72 && V_64 . V_85 == V_86 )
V_173 = 1 ;
error = F_134 ( V_11 , V_62 , V_172 , & V_64 ) ;
if ( error )
goto V_174;
F_24 ( V_11 , V_171 ) ;
}
F_135 ( V_11 , V_62 , V_172 , 0 , & V_64 ) ;
} else if ( V_72 ) {
F_136 ( V_11 , V_62 , V_172 , 0 , & V_64 ) ;
F_24 ( V_11 , V_171 ) ;
} else {
F_137 ( V_11 , V_62 , V_172 ) ;
goto V_174;
}
if ( V_64 . V_85 != V_86 &&
V_64 . V_85 != V_87 ) {
if ( V_169 || ! F_138 ( & V_64 ) )
F_85 ( V_9 , V_168 , & V_64 , V_62 ) ;
if ( V_169 && F_138 ( & V_64 ) ) {
if ( V_170 )
V_168 -> V_21 = V_9 ;
F_139 ( V_168 ) ;
}
}
V_168 -> V_103 = F_5 ( V_9 ) ;
if ( V_169 &&
( ( ! F_65 ( V_168 ) && ! F_100 ( V_168 ) ) ||
( V_62 >= F_120 ( V_9 ) ) ||
( V_173 || F_138 ( & V_64 ) ) ) )
F_140 ( V_168 ) ;
if ( V_64 . V_85 == V_87 ) {
F_141 ( V_170 ) ;
if ( V_169 ) {
F_68 ( V_168 ) ;
F_88 ( V_168 ) ;
F_142 ( V_168 ) ;
}
}
if ( V_170 || V_172 > ( 1 << V_9 -> V_67 ) ) {
T_6 V_175 ;
V_175 = V_64 . V_88 + V_64 . V_89 - V_167 ;
V_175 <<= V_9 -> V_67 ;
ASSERT ( V_175 > 0 ) ;
if ( V_175 > V_172 )
V_175 = V_172 ;
if ( V_175 > V_176 )
V_175 = V_176 ;
V_168 -> V_107 = V_175 ;
}
return 0 ;
V_174:
F_24 ( V_11 , V_171 ) ;
return - error ;
}
int
F_143 (
struct V_9 * V_9 ,
T_7 V_167 ,
struct V_4 * V_168 ,
int V_169 )
{
return F_130 ( V_9 , V_167 , V_168 , V_169 , 0 ) ;
}
STATIC int
F_144 (
struct V_9 * V_9 ,
T_7 V_167 ,
struct V_4 * V_168 ,
int V_169 )
{
return F_130 ( V_9 , V_167 , V_168 , V_169 , 1 ) ;
}
STATIC void
F_145 (
struct V_177 * V_178 ,
T_3 V_62 ,
T_4 V_172 ,
void * V_179 ,
int V_180 ,
bool V_181 )
{
struct V_29 * V_18 = V_178 -> V_179 ;
if ( V_62 + V_172 > F_120 ( V_18 -> V_27 ) )
F_146 ( V_18 -> V_27 , V_62 + V_172 ) ;
V_178 -> V_179 = NULL ;
V_18 -> V_30 = V_62 ;
V_18 -> V_31 = V_172 ;
V_18 -> V_24 = V_178 ;
V_18 -> V_26 = V_180 ;
if ( V_179 && V_172 > 0 )
V_18 -> V_49 = V_50 ;
if ( V_181 ) {
V_18 -> V_25 = 1 ;
F_29 ( V_18 ) ;
} else {
F_37 ( V_18 ) ;
}
}
STATIC T_4
F_147 (
int V_182 ,
struct V_177 * V_178 ,
const struct V_183 * V_184 ,
T_3 V_62 ,
unsigned long V_185 )
{
struct V_9 * V_9 = V_178 -> V_186 -> V_187 -> V_146 ;
struct V_8 * V_188 = F_5 ( V_9 ) ;
struct V_29 * V_18 = NULL ;
T_4 V_180 ;
if ( V_182 & V_101 ) {
T_12 V_172 = F_148 ( V_184 , V_185 ) ;
V_178 -> V_179 = V_18 = F_38 ( V_9 , V_189 ) ;
if ( V_62 + V_172 > F_6 ( V_9 ) -> V_32 . V_33 ) {
V_180 = F_13 ( V_18 ) ;
if ( V_180 )
goto V_190;
V_18 -> V_58 = 1 ;
}
V_180 = F_149 ( V_182 , V_178 , V_9 , V_188 , V_184 ,
V_62 , V_185 ,
F_144 ,
F_145 , NULL , 0 ) ;
if ( V_180 != - V_191 && V_178 -> V_179 )
goto V_192;
} else {
V_180 = F_149 ( V_182 , V_178 , V_9 , V_188 , V_184 ,
V_62 , V_185 ,
F_144 ,
NULL , NULL , 0 ) ;
}
return V_180 ;
V_192:
if ( V_18 -> V_37 ) {
F_21 ( & V_18 -> V_37 -> V_43 ,
V_44 ) ;
F_34 (
& V_9 -> V_38 -> V_39 . V_40 [ V_41 - 1 ] ,
0 , 1 , V_42 ) ;
F_17 ( V_18 -> V_37 , 0 ) ;
}
V_190:
F_8 ( V_18 ) ;
return V_180 ;
}
STATIC void
F_150 (
struct V_9 * V_9 ,
T_3 V_193 ,
T_3 V_194 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_5 V_149 ;
T_5 V_69 ;
int error ;
V_149 = F_45 ( V_11 -> V_14 , V_193 ) ;
V_69 = F_45 ( V_11 -> V_14 , V_194 ) ;
if ( V_69 <= V_149 )
return;
F_22 ( V_11 , V_46 ) ;
error = F_115 ( V_11 , V_149 ,
V_69 - V_149 ) ;
if ( error ) {
if ( ! F_35 ( V_11 -> V_14 ) ) {
F_114 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_148 ) ;
}
}
F_24 ( V_11 , V_46 ) ;
}
STATIC void
F_151 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_3 V_195 ,
unsigned V_130 )
{
T_3 V_196 = V_195 & V_197 ;
T_3 V_198 ;
T_3 V_199 ;
T_3 V_200 = V_195 & ( V_137 - 1 ) ;
T_3 V_201 = V_200 + V_130 ;
struct V_4 * V_5 , * V_6 ;
ASSERT ( V_196 + V_200 == V_195 ) ;
V_6 = F_2 ( V_1 ) ;
V_198 = 0 ;
for ( V_5 = V_6 ; V_5 != V_6 || ! V_198 ;
V_5 = V_5 -> V_7 , V_198 = V_199 ,
V_196 += V_5 -> V_107 ) {
V_199 = V_198 + V_5 -> V_107 ;
if ( V_199 <= V_200 )
continue;
if ( V_198 >= V_201 )
break;
if ( ! F_4 ( V_5 ) )
continue;
if ( ! F_152 ( V_5 ) && V_196 < F_120 ( V_9 ) )
continue;
F_150 ( V_9 , V_196 ,
V_196 + V_5 -> V_107 ) ;
}
}
STATIC int
F_153 (
struct V_202 * V_202 ,
struct V_164 * V_123 ,
T_3 V_195 ,
unsigned V_130 ,
unsigned V_157 ,
struct V_1 * * V_203 ,
void * * V_204 )
{
T_9 V_133 = V_195 >> V_161 ;
struct V_1 * V_1 ;
int V_205 ;
ASSERT ( V_130 <= V_137 ) ;
V_1 = F_154 ( V_123 , V_133 ,
V_157 | V_206 ) ;
if ( ! V_1 )
return - V_207 ;
V_205 = F_155 ( V_1 , V_195 , V_130 , F_143 ) ;
if ( F_156 ( V_205 ) ) {
struct V_9 * V_9 = V_123 -> V_146 ;
F_151 ( V_9 , V_1 , V_195 , V_130 ) ;
F_75 ( V_1 ) ;
if ( V_195 + V_130 > F_120 ( V_9 ) )
F_157 ( V_9 , V_195 + V_130 , F_120 ( V_9 ) ) ;
F_158 ( V_1 ) ;
V_1 = NULL ;
}
* V_203 = V_1 ;
return V_205 ;
}
STATIC int
F_159 (
struct V_202 * V_202 ,
struct V_164 * V_123 ,
T_3 V_195 ,
unsigned V_130 ,
unsigned V_208 ,
struct V_1 * V_1 ,
void * V_204 )
{
int V_180 ;
ASSERT ( V_130 <= V_137 ) ;
V_180 = F_160 ( V_202 , V_123 , V_195 , V_130 , V_208 , V_1 , V_204 ) ;
if ( F_156 ( V_180 < V_130 ) ) {
struct V_9 * V_9 = V_123 -> V_146 ;
T_12 V_45 = F_120 ( V_9 ) ;
T_3 V_201 = V_195 + V_130 ;
if ( V_201 > V_45 ) {
F_157 ( V_9 , V_201 , V_45 ) ;
F_150 ( V_9 , V_45 , V_201 ) ;
}
}
return V_180 ;
}
STATIC T_7
F_161 (
struct V_164 * V_123 ,
T_7 V_209 )
{
struct V_9 * V_9 = (struct V_9 * ) V_123 -> V_146 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_162 ( F_6 ( V_9 ) ) ;
F_22 ( V_11 , V_210 ) ;
F_163 ( V_11 , ( T_6 ) 0 , - 1 , 0 , V_211 ) ;
F_24 ( V_11 , V_210 ) ;
return F_164 ( V_123 , V_209 , F_143 ) ;
}
STATIC int
F_165 (
struct V_202 * V_212 ,
struct V_1 * V_1 )
{
return F_166 ( V_1 , F_143 ) ;
}
STATIC int
F_167 (
struct V_202 * V_212 ,
struct V_164 * V_123 ,
struct V_213 * V_145 ,
unsigned V_214 )
{
return F_168 ( V_123 , V_145 , V_214 , F_143 ) ;
}
