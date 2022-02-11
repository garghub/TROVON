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
F_9 ( V_18 -> V_25 ) ;
if ( V_18 -> V_26 ) {
F_10 ( V_18 -> V_24 , V_18 -> V_23 ?
V_18 -> V_23 : V_18 -> V_27 , 0 ) ;
}
}
F_11 ( V_18 , V_28 ) ;
}
static inline bool F_12 ( struct V_29 * V_18 )
{
return V_18 -> V_30 + V_18 -> V_31 >
F_6 ( V_18 -> V_25 ) -> V_32 . V_33 ;
}
STATIC int
F_13 (
struct V_29 * V_18 )
{
struct V_12 * V_13 = F_6 ( V_18 -> V_25 ) -> V_14 ;
struct V_34 * V_35 ;
int error ;
V_35 = F_14 ( V_13 , V_36 ) ;
error = F_15 ( V_35 , 0 , F_16 ( V_13 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_17 ( V_35 , 0 ) ;
return error ;
}
V_18 -> V_37 = V_35 ;
F_18 ( & V_18 -> V_25 -> V_38 -> V_39 . V_40 [ V_41 - 1 ] ,
1 , V_42 ) ;
F_19 ( & V_35 -> V_43 , V_44 ) ;
return 0 ;
}
STATIC int
F_20 (
struct V_29 * V_18 )
{
struct V_10 * V_11 = F_6 ( V_18 -> V_25 ) ;
struct V_34 * V_35 = V_18 -> V_37 ;
T_2 V_45 ;
F_21 ( & V_35 -> V_43 , V_44 ) ;
F_22 ( & F_23 ( V_11 ) -> V_38 -> V_39 . V_40 [ V_41 - 1 ] ,
0 , 1 , V_42 ) ;
F_24 ( V_11 , V_46 ) ;
V_45 = F_25 ( V_11 , V_18 -> V_30 + V_18 -> V_31 ) ;
if ( ! V_45 ) {
F_26 ( V_11 , V_46 ) ;
F_17 ( V_35 , 0 ) ;
return 0 ;
}
F_27 ( V_11 , V_18 -> V_30 , V_18 -> V_31 ) ;
V_11 -> V_32 . V_33 = V_45 ;
F_28 ( V_35 , V_11 , V_46 ) ;
F_29 ( V_35 , V_11 , V_47 ) ;
return F_30 ( V_35 , 0 ) ;
}
STATIC void
F_31 (
struct V_29 * V_18 )
{
if ( F_32 ( & V_18 -> V_48 ) ) {
struct V_12 * V_13 = F_6 ( V_18 -> V_25 ) -> V_14 ;
if ( V_18 -> V_49 == V_50 )
F_33 ( V_13 -> V_51 , & V_18 -> V_52 ) ;
else if ( V_18 -> V_37 ||
( V_18 -> V_53 && F_12 ( V_18 ) ) )
F_33 ( V_13 -> V_54 , & V_18 -> V_52 ) ;
else
F_8 ( V_18 ) ;
}
}
STATIC void
F_34 (
struct V_55 * V_56 )
{
T_1 * V_18 = F_35 ( V_56 , T_1 , V_52 ) ;
struct V_10 * V_11 = F_6 ( V_18 -> V_25 ) ;
int error = 0 ;
if ( F_36 ( V_11 -> V_14 ) ) {
V_18 -> V_23 = - V_57 ;
goto V_58;
}
if ( V_18 -> V_23 )
goto V_58;
if ( V_18 -> V_49 == V_50 ) {
error = F_37 ( V_11 , V_18 -> V_30 ,
V_18 -> V_31 ) ;
} else if ( V_18 -> V_53 && F_12 ( V_18 ) ) {
error = F_13 ( V_18 ) ;
if ( error )
goto V_58;
error = F_20 ( V_18 ) ;
} else if ( V_18 -> V_37 ) {
error = F_20 ( V_18 ) ;
} else {
ASSERT ( ! F_12 ( V_18 ) ) ;
}
V_58:
if ( error )
V_18 -> V_23 = - error ;
F_8 ( V_18 ) ;
}
STATIC void
F_38 (
struct V_29 * V_18 )
{
if ( F_32 ( & V_18 -> V_48 ) )
F_34 ( & V_18 -> V_52 ) ;
}
STATIC T_1 *
F_39 (
struct V_9 * V_9 ,
unsigned int type )
{
T_1 * V_18 ;
V_18 = F_40 ( V_28 , V_59 ) ;
F_41 ( & V_18 -> V_48 , 1 ) ;
V_18 -> V_26 = 0 ;
V_18 -> V_53 = 0 ;
V_18 -> V_23 = 0 ;
V_18 -> V_60 = NULL ;
V_18 -> V_49 = type ;
V_18 -> V_25 = V_9 ;
V_18 -> V_20 = NULL ;
V_18 -> V_61 = NULL ;
V_18 -> V_30 = 0 ;
V_18 -> V_31 = 0 ;
V_18 -> V_24 = NULL ;
V_18 -> V_27 = 0 ;
V_18 -> V_37 = NULL ;
F_42 ( & V_18 -> V_52 , F_34 ) ;
return V_18 ;
}
STATIC int
F_43 (
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
if ( F_36 ( V_13 ) )
return - F_44 ( V_57 ) ;
if ( type == V_50 )
V_70 |= V_73 ;
if ( ! F_45 ( V_11 , V_74 ) ) {
if ( V_65 )
return - F_44 ( V_75 ) ;
F_24 ( V_11 , V_74 ) ;
}
ASSERT ( V_11 -> V_32 . V_76 != V_77 ||
( V_11 -> V_78 . V_79 & V_80 ) ) ;
ASSERT ( V_62 <= V_13 -> V_81 -> V_82 ) ;
if ( V_62 + V_66 > V_13 -> V_81 -> V_82 )
V_66 = V_13 -> V_81 -> V_82 - V_62 ;
V_69 = F_46 ( V_13 , ( V_83 ) V_62 + V_66 ) ;
V_68 = F_47 ( V_13 , V_62 ) ;
error = F_48 ( V_11 , V_68 , V_69 - V_68 ,
V_64 , & V_72 , V_70 ) ;
F_26 ( V_11 , V_74 ) ;
if ( error )
return - F_44 ( error ) ;
if ( type == V_84 &&
( ! V_72 || F_49 ( V_64 -> V_85 ) ) ) {
error = F_50 ( V_11 , V_62 , V_66 , V_64 ) ;
if ( ! error )
F_51 ( V_11 , V_62 , V_66 , type , V_64 ) ;
return - F_44 ( error ) ;
}
#ifdef F_52
if ( type == V_50 ) {
ASSERT ( V_72 ) ;
ASSERT ( V_64 -> V_85 != V_86 ) ;
ASSERT ( V_64 -> V_85 != V_87 ) ;
}
#endif
if ( V_72 )
F_53 ( V_11 , V_62 , V_66 , type , V_64 ) ;
return 0 ;
}
STATIC int
F_54 (
struct V_9 * V_9 ,
struct V_63 * V_64 ,
T_6 V_62 )
{
V_62 >>= V_9 -> V_67 ;
return V_62 >= V_64 -> V_88 &&
V_62 < V_64 -> V_88 + V_64 -> V_89 ;
}
STATIC void
F_55 (
struct V_90 * V_90 ,
int error )
{
T_1 * V_18 = V_90 -> V_91 ;
ASSERT ( F_56 ( & V_90 -> V_92 ) >= 1 ) ;
V_18 -> V_23 = F_57 ( V_93 , & V_90 -> V_94 ) ? 0 : error ;
V_90 -> V_91 = NULL ;
V_90 -> V_95 = NULL ;
F_58 ( V_90 ) ;
F_31 ( V_18 ) ;
}
STATIC void
F_59 (
struct V_96 * V_97 ,
T_1 * V_18 ,
struct V_90 * V_90 )
{
F_60 ( & V_18 -> V_48 ) ;
V_90 -> V_91 = V_18 ;
V_90 -> V_95 = F_55 ;
F_61 ( V_97 -> V_98 == V_99 ? V_100 : V_101 , V_90 ) ;
}
STATIC struct V_90 *
F_62 (
struct V_4 * V_5 )
{
int V_102 = F_63 ( V_5 -> V_103 ) ;
struct V_90 * V_90 = F_64 ( V_104 , V_102 ) ;
ASSERT ( V_90 -> V_91 == NULL ) ;
V_90 -> V_105 = V_5 -> V_106 * ( V_5 -> V_107 >> 9 ) ;
V_90 -> V_108 = V_5 -> V_103 ;
return V_90 ;
}
STATIC void
F_65 (
struct V_4 * V_5 )
{
ASSERT ( F_66 ( V_5 ) ) ;
ASSERT ( F_67 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_68 ( V_5 ) ;
F_69 ( V_5 ) ;
F_70 ( V_5 ) ;
}
STATIC void
F_71 (
struct V_1 * V_1 ,
int V_109 ,
int V_110 )
{
ASSERT ( F_72 ( V_1 ) ) ;
ASSERT ( ! F_73 ( V_1 ) ) ;
if ( V_109 )
F_74 ( V_1 ) ;
F_75 ( V_1 ) ;
F_76 ( V_1 ) ;
if ( ! V_110 )
F_77 ( V_1 ) ;
}
static inline int F_78 ( struct V_90 * V_90 , struct V_4 * V_5 )
{
return F_79 ( V_90 , V_5 -> V_111 , V_5 -> V_107 , F_80 ( V_5 ) ) ;
}
STATIC void
F_81 (
struct V_96 * V_97 ,
T_1 * V_18 ,
int V_112 )
{
T_1 * V_6 = V_18 ;
T_1 * V_19 ;
struct V_4 * V_5 ;
struct V_90 * V_90 ;
T_7 V_113 = 0 ;
do {
V_19 = V_18 -> V_60 ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 )
F_65 ( V_5 ) ;
} while ( ( V_18 = V_19 ) != NULL );
V_18 = V_6 ;
do {
V_19 = V_18 -> V_60 ;
V_90 = NULL ;
if ( V_112 ) {
V_18 -> V_23 = - V_112 ;
F_31 ( V_18 ) ;
continue;
}
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 ) {
if ( ! V_90 ) {
V_114:
V_90 = F_62 ( V_5 ) ;
} else if ( V_5 -> V_106 != V_113 + 1 ) {
F_59 ( V_97 , V_18 , V_90 ) ;
goto V_114;
}
if ( F_78 ( V_90 , V_5 ) != V_5 -> V_107 ) {
F_59 ( V_97 , V_18 , V_90 ) ;
goto V_114;
}
V_113 = V_5 -> V_106 ;
}
if ( V_90 )
F_59 ( V_97 , V_18 , V_90 ) ;
F_31 ( V_18 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_82 (
T_1 * V_18 )
{
T_1 * V_19 ;
struct V_4 * V_5 , * V_115 ;
do {
V_19 = V_18 -> V_60 ;
V_5 = V_18 -> V_20 ;
do {
V_115 = V_5 -> V_21 ;
F_83 ( V_5 ) ;
F_84 ( V_5 ) ;
} while ( ( V_5 = V_115 ) != NULL );
F_11 ( V_18 , V_28 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_85 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_6 V_62 ,
unsigned int type ,
T_1 * * V_116 ,
int V_117 )
{
T_1 * V_18 = * V_116 ;
if ( ! V_18 || V_117 || type != V_18 -> V_49 ) {
T_1 * V_118 = * V_116 ;
V_18 = F_39 ( V_9 , type ) ;
V_18 -> V_30 = V_62 ;
V_18 -> V_20 = V_5 ;
V_18 -> V_61 = V_5 ;
if ( V_118 )
V_118 -> V_60 = V_18 ;
* V_116 = V_18 ;
} else {
V_18 -> V_61 -> V_21 = V_5 ;
V_18 -> V_61 = V_5 ;
}
V_5 -> V_21 = NULL ;
V_18 -> V_31 += V_5 -> V_107 ;
}
STATIC void
F_86 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_63 * V_64 ,
T_6 V_62 )
{
T_7 V_119 ;
struct V_12 * V_120 = F_6 ( V_9 ) -> V_14 ;
T_6 V_121 = F_87 ( V_120 , V_64 -> V_88 ) ;
T_8 V_122 = F_88 ( F_6 ( V_9 ) , V_64 -> V_85 ) ;
ASSERT ( V_64 -> V_85 != V_86 ) ;
ASSERT ( V_64 -> V_85 != V_87 ) ;
V_119 = ( V_122 >> ( V_9 -> V_67 - V_123 ) ) +
( ( V_62 - V_121 ) >> V_9 -> V_67 ) ;
ASSERT ( V_119 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_106 = V_119 ;
F_89 ( V_5 ) ;
}
STATIC void
F_90 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_63 * V_64 ,
T_6 V_62 )
{
ASSERT ( V_64 -> V_85 != V_86 ) ;
ASSERT ( V_64 -> V_85 != V_87 ) ;
F_86 ( V_9 , V_5 , V_64 , V_62 ) ;
F_89 ( V_5 ) ;
F_91 ( V_5 ) ;
F_92 ( V_5 ) ;
}
STATIC int
F_93 (
struct V_1 * V_1 ,
unsigned int type )
{
if ( F_73 ( V_1 ) )
return 0 ;
if ( V_1 -> V_124 && F_94 ( V_1 ) ) {
struct V_4 * V_5 , * V_6 ;
int V_125 = 0 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) )
V_125 += ( type == V_50 ) ;
else if ( F_4 ( V_5 ) )
V_125 += ( type == V_84 ) ;
else if ( F_95 ( V_5 ) && F_66 ( V_5 ) )
V_125 += ( type == V_126 ) ;
else
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_125 )
return 1 ;
}
return 0 ;
}
STATIC int
F_96 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_3 V_127 ,
struct V_63 * V_64 ,
T_1 * * V_128 ,
struct V_96 * V_97 )
{
struct V_4 * V_5 , * V_6 ;
T_6 V_129 ;
unsigned long V_130 ;
unsigned int type ;
int V_131 , V_132 ;
int V_66 = 0 , V_58 = 0 , V_133 = 1 ;
T_6 V_62 = F_97 ( V_1 ) ;
if ( V_1 -> V_134 != V_127 )
goto V_112;
if ( ! F_98 ( V_1 ) )
goto V_112;
if ( F_73 ( V_1 ) )
goto V_135;
if ( V_1 -> V_124 != V_9 -> V_136 )
goto V_135;
if ( ! F_93 ( V_1 , ( * V_128 ) -> V_49 ) )
goto V_135;
V_129 = F_99 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode)) ;
if ( ! F_54 ( V_9 , V_64 , V_129 ) )
goto V_135;
V_131 = 1 << V_9 -> V_67 ;
V_130 = F_99 (unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE) ;
V_130 = V_130 ? F_100 ( V_130 , V_131 ) : V_137 ;
V_132 = V_130 / V_131 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( V_62 >= V_129 )
break;
if ( ! F_101 ( V_5 ) )
V_133 = 0 ;
if ( ! ( F_102 ( V_1 ) || F_101 ( V_5 ) ) ) {
V_58 = 1 ;
continue;
}
if ( F_3 ( V_5 ) || F_4 ( V_5 ) ||
F_66 ( V_5 ) ) {
if ( F_3 ( V_5 ) )
type = V_50 ;
else if ( F_4 ( V_5 ) )
type = V_84 ;
else
type = V_126 ;
if ( ! F_54 ( V_9 , V_64 , V_62 ) ) {
V_58 = 1 ;
continue;
}
F_103 ( V_5 ) ;
if ( type != V_126 )
F_90 ( V_9 , V_5 , V_64 , V_62 ) ;
F_85 ( V_9 , V_5 , V_62 , type ,
V_128 , V_58 ) ;
V_132 -- ;
V_66 ++ ;
} else {
V_58 = 1 ;
}
} while ( V_62 += V_131 , ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_133 && V_5 == V_6 )
F_104 ( V_1 ) ;
if ( V_66 ) {
if ( -- V_97 -> V_138 <= 0 &&
V_97 -> V_98 == V_139 )
V_58 = 1 ;
}
F_71 ( V_1 , ! V_132 , V_66 ) ;
return V_58 ;
V_135:
F_76 ( V_1 ) ;
V_112:
return 1 ;
}
STATIC void
F_105 (
struct V_9 * V_9 ,
T_9 V_127 ,
struct V_63 * V_64 ,
T_1 * * V_128 ,
struct V_96 * V_97 ,
T_9 V_140 )
{
struct V_141 V_142 ;
int V_58 = 0 , V_143 ;
F_106 ( & V_142 , 0 ) ;
while ( ! V_58 && V_127 <= V_140 ) {
unsigned V_131 = F_99 ( T_9 , V_144 , V_140 - V_127 + 1 ) ;
if ( ! F_107 ( & V_142 , V_9 -> V_136 , V_127 , V_131 ) )
break;
for ( V_143 = 0 ; V_143 < F_108 ( & V_142 ) ; V_143 ++ ) {
V_58 = F_96 ( V_9 , V_142 . V_145 [ V_143 ] , V_127 ++ ,
V_64 , V_128 , V_97 ) ;
if ( V_58 )
break;
}
F_109 ( & V_142 ) ;
F_110 () ;
}
}
STATIC void
F_111 (
struct V_1 * V_1 ,
unsigned long V_62 )
{
F_112 ( V_1 -> V_124 -> V_146 , V_1 , V_62 ) ;
F_113 ( V_1 , V_62 ) ;
}
STATIC void
F_114 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_124 -> V_146 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_3 V_62 = F_97 ( V_1 ) ;
if ( ! F_93 ( V_1 , V_84 ) )
goto V_147;
if ( F_36 ( V_11 -> V_14 ) )
goto V_147;
F_115 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_148 , V_62 ) ;
F_24 ( V_11 , V_46 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_5 V_149 ;
if ( ! F_4 ( V_5 ) )
goto V_150;
V_149 = F_47 ( V_11 -> V_14 , V_62 ) ;
error = F_116 ( V_11 , V_149 , 1 ) ;
if ( error ) {
if ( ! F_36 ( V_11 -> V_14 ) ) {
F_115 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_150:
V_62 += 1 << V_9 -> V_67 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_26 ( V_11 , V_46 ) ;
V_147:
F_111 ( V_1 , 0 ) ;
return;
}
STATIC int
F_117 (
struct V_1 * V_1 ,
struct V_96 * V_97 )
{
struct V_9 * V_9 = V_1 -> V_124 -> V_146 ;
struct V_4 * V_5 , * V_6 ;
struct V_63 V_64 ;
T_1 * V_18 = NULL , * V_151 = NULL ;
T_3 V_62 ;
unsigned int type ;
T_10 V_129 ;
T_9 V_152 , V_153 ;
T_4 V_131 ;
int V_154 , V_155 = 0 , V_133 = 1 ;
int V_66 = 0 ;
int V_65 = 0 ;
F_118 ( V_9 , V_1 , 0 ) ;
ASSERT ( F_94 ( V_1 ) ) ;
if ( F_119 ( ( V_156 -> V_157 & ( V_158 | V_159 ) ) ==
V_158 ) )
goto V_160;
if ( F_120 ( V_156 -> V_157 & V_44 ) )
goto V_160;
V_62 = F_121 ( V_9 ) ;
V_152 = V_62 >> V_161 ;
V_153 = ( V_62 - 1 ) >> V_161 ;
if ( V_1 -> V_134 >= V_152 ) {
unsigned V_162 = V_62 & ( V_137 - 1 ) ;
if ( V_1 -> V_134 >= V_152 + 1 || V_162 == 0 )
goto V_160;
F_122 ( V_1 , V_162 , V_137 ) ;
}
V_129 = F_99 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
offset) ;
V_131 = 1 << V_9 -> V_67 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_62 = F_97 ( V_1 ) ;
type = V_126 ;
if ( V_97 -> V_98 == V_139 )
V_65 = 1 ;
do {
int V_163 = 0 ;
if ( V_62 >= V_129 )
break;
if ( ! F_101 ( V_5 ) )
V_133 = 0 ;
if ( ! F_66 ( V_5 ) && F_101 ( V_5 ) ) {
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
} else if ( F_101 ( V_5 ) ) {
if ( type != V_126 ) {
type = V_126 ;
V_155 = 0 ;
}
} else {
if ( F_102 ( V_1 ) )
ASSERT ( F_66 ( V_5 ) ) ;
V_155 = 0 ;
continue;
}
if ( V_155 )
V_155 = F_54 ( V_9 , & V_64 , V_62 ) ;
if ( ! V_155 ) {
V_163 = 1 ;
V_154 = F_43 ( V_9 , V_62 , & V_64 , type ,
V_65 ) ;
if ( V_154 )
goto error;
V_155 = F_54 ( V_9 , & V_64 , V_62 ) ;
}
if ( V_155 ) {
F_103 ( V_5 ) ;
if ( type != V_126 )
F_90 ( V_9 , V_5 , & V_64 , V_62 ) ;
F_85 ( V_9 , V_5 , V_62 , type , & V_18 ,
V_163 ) ;
V_66 ++ ;
}
if ( ! V_151 )
V_151 = V_18 ;
} while ( V_62 += V_131 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_133 && V_5 == V_6 )
F_104 ( V_1 ) ;
F_71 ( V_1 , 1 , V_66 ) ;
if ( ! V_18 )
return 0 ;
ASSERT ( V_151 ) ;
if ( V_155 ) {
T_6 V_152 ;
V_152 = V_64 . V_88 + V_64 . V_89 ;
V_152 <<= V_9 -> V_67 ;
V_152 = ( V_152 - 1 ) >> V_161 ;
if ( V_152 > V_153 )
V_152 = V_153 ;
F_105 ( V_9 , V_1 -> V_134 + 1 , & V_64 , & V_18 ,
V_97 , V_152 ) ;
}
V_154 = 0 ;
if ( V_18 -> V_49 != V_50 && F_12 ( V_18 ) )
V_154 = F_13 ( V_18 ) ;
F_81 ( V_97 , V_151 , V_154 ) ;
return 0 ;
error:
if ( V_151 )
F_82 ( V_151 ) ;
if ( V_154 == - V_75 )
goto V_160;
F_114 ( V_1 ) ;
F_123 ( V_1 ) ;
F_76 ( V_1 ) ;
return V_154 ;
V_160:
F_124 ( V_97 , V_1 ) ;
F_76 ( V_1 ) ;
return 0 ;
}
STATIC int
F_125 (
struct V_164 * V_124 ,
struct V_96 * V_97 )
{
F_126 ( F_6 ( V_124 -> V_146 ) , V_165 ) ;
return F_127 ( V_124 , V_97 ) ;
}
STATIC int
F_128 (
struct V_1 * V_1 ,
T_11 V_166 )
{
int V_2 , V_3 ;
F_129 ( V_1 -> V_124 -> V_146 , V_1 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_120 ( V_2 ) )
return 0 ;
if ( F_120 ( V_3 ) )
return 0 ;
return F_130 ( V_1 ) ;
}
STATIC int
F_131 (
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
if ( F_36 ( V_13 ) )
return - F_44 ( V_57 ) ;
V_62 = ( T_6 ) V_167 << V_9 -> V_67 ;
ASSERT ( V_168 -> V_107 >= ( 1 << V_9 -> V_67 ) ) ;
V_172 = V_168 -> V_107 ;
if ( ! V_169 && V_170 && V_62 >= F_121 ( V_9 ) )
return 0 ;
if ( V_169 && ! V_170 ) {
V_171 = V_46 ;
F_24 ( V_11 , V_171 ) ;
} else {
V_171 = F_132 ( V_11 ) ;
}
ASSERT ( V_62 <= V_13 -> V_81 -> V_82 ) ;
if ( V_62 + V_172 > V_13 -> V_81 -> V_82 )
V_172 = V_13 -> V_81 -> V_82 - V_62 ;
V_69 = F_46 ( V_13 , ( V_83 ) V_62 + V_172 ) ;
V_68 = F_47 ( V_13 , V_62 ) ;
error = F_48 ( V_11 , V_68 , V_69 - V_68 ,
& V_64 , & V_72 , V_71 ) ;
if ( error )
goto V_174;
if ( V_169 &&
( ! V_72 ||
( V_64 . V_85 == V_86 ||
V_64 . V_85 == V_87 ) ) ) {
if ( V_170 || F_133 ( V_11 ) ) {
F_26 ( V_11 , V_171 ) ;
error = F_134 ( V_11 , V_62 , V_172 ,
& V_64 , V_72 ) ;
if ( error )
return - error ;
V_173 = 1 ;
} else {
if ( V_72 && V_64 . V_85 == V_86 )
V_173 = 1 ;
error = F_135 ( V_11 , V_62 , V_172 , & V_64 ) ;
if ( error )
goto V_174;
F_26 ( V_11 , V_171 ) ;
}
F_136 ( V_11 , V_62 , V_172 , 0 , & V_64 ) ;
} else if ( V_72 ) {
F_137 ( V_11 , V_62 , V_172 , 0 , & V_64 ) ;
F_26 ( V_11 , V_171 ) ;
} else {
F_138 ( V_11 , V_62 , V_172 ) ;
goto V_174;
}
if ( V_64 . V_85 != V_86 &&
V_64 . V_85 != V_87 ) {
if ( V_169 || ! F_139 ( & V_64 ) )
F_86 ( V_9 , V_168 , & V_64 , V_62 ) ;
if ( V_169 && F_139 ( & V_64 ) ) {
if ( V_170 )
V_168 -> V_21 = V_9 ;
F_140 ( V_168 ) ;
}
}
V_168 -> V_103 = F_5 ( V_9 ) ;
if ( V_169 &&
( ( ! F_66 ( V_168 ) && ! F_101 ( V_168 ) ) ||
( V_62 >= F_121 ( V_9 ) ) ||
( V_173 || F_139 ( & V_64 ) ) ) )
F_141 ( V_168 ) ;
if ( V_64 . V_85 == V_87 ) {
F_142 ( V_170 ) ;
if ( V_169 ) {
F_69 ( V_168 ) ;
F_89 ( V_168 ) ;
F_143 ( V_168 ) ;
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
F_26 ( V_11 , V_171 ) ;
return - error ;
}
int
F_144 (
struct V_9 * V_9 ,
T_7 V_167 ,
struct V_4 * V_168 ,
int V_169 )
{
return F_131 ( V_9 , V_167 , V_168 , V_169 , 0 ) ;
}
STATIC int
F_145 (
struct V_9 * V_9 ,
T_7 V_167 ,
struct V_4 * V_168 ,
int V_169 )
{
return F_131 ( V_9 , V_167 , V_168 , V_169 , 1 ) ;
}
STATIC void
F_146 (
struct V_177 * V_178 ,
T_3 V_62 ,
T_4 V_172 ,
void * V_179 ,
int V_180 ,
bool V_181 )
{
struct V_29 * V_18 = V_178 -> V_179 ;
if ( V_62 + V_172 > F_121 ( V_18 -> V_25 ) )
F_147 ( V_18 -> V_25 , V_62 + V_172 ) ;
V_178 -> V_179 = NULL ;
V_18 -> V_30 = V_62 ;
V_18 -> V_31 = V_172 ;
V_18 -> V_24 = V_178 ;
V_18 -> V_27 = V_180 ;
if ( V_179 && V_172 > 0 )
V_18 -> V_49 = V_50 ;
if ( V_181 ) {
V_18 -> V_26 = 1 ;
F_31 ( V_18 ) ;
} else {
F_38 ( V_18 ) ;
}
}
STATIC T_4
F_148 (
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
T_12 V_172 = F_149 ( V_184 , V_185 ) ;
V_178 -> V_179 = V_18 = F_39 ( V_9 , V_189 ) ;
if ( V_62 + V_172 > F_6 ( V_9 ) -> V_32 . V_33 )
V_18 -> V_53 = 1 ;
V_180 = F_150 ( V_182 , V_178 , V_9 , V_188 , V_184 ,
V_62 , V_185 ,
F_145 ,
F_146 , NULL , 0 ) ;
if ( V_180 != - V_190 && V_178 -> V_179 )
goto V_191;
} else {
V_180 = F_150 ( V_182 , V_178 , V_9 , V_188 , V_184 ,
V_62 , V_185 ,
F_145 ,
NULL , NULL , 0 ) ;
}
return V_180 ;
V_191:
F_8 ( V_18 ) ;
return V_180 ;
}
STATIC void
F_151 (
struct V_9 * V_9 ,
T_3 V_192 ,
T_3 V_193 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_5 V_149 ;
T_5 V_69 ;
int error ;
V_149 = F_46 ( V_11 -> V_14 , V_192 ) ;
V_69 = F_46 ( V_11 -> V_14 , V_193 ) ;
if ( V_69 <= V_149 )
return;
F_24 ( V_11 , V_46 ) ;
error = F_116 ( V_11 , V_149 ,
V_69 - V_149 ) ;
if ( error ) {
if ( ! F_36 ( V_11 -> V_14 ) ) {
F_115 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_148 ) ;
}
}
F_26 ( V_11 , V_46 ) ;
}
STATIC void
F_152 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_3 V_194 ,
unsigned V_131 )
{
T_3 V_195 = V_194 & V_196 ;
T_3 V_197 ;
T_3 V_198 ;
T_3 V_199 = V_194 & ( V_137 - 1 ) ;
T_3 V_200 = V_199 + V_131 ;
struct V_4 * V_5 , * V_6 ;
ASSERT ( V_195 + V_199 == V_194 ) ;
V_6 = F_2 ( V_1 ) ;
V_197 = 0 ;
for ( V_5 = V_6 ; V_5 != V_6 || ! V_197 ;
V_5 = V_5 -> V_7 , V_197 = V_198 ,
V_195 += V_5 -> V_107 ) {
V_198 = V_197 + V_5 -> V_107 ;
if ( V_198 <= V_199 )
continue;
if ( V_197 >= V_200 )
break;
if ( ! F_4 ( V_5 ) )
continue;
if ( ! F_153 ( V_5 ) && V_195 < F_121 ( V_9 ) )
continue;
F_151 ( V_9 , V_195 ,
V_195 + V_5 -> V_107 ) ;
}
}
STATIC int
F_154 (
struct V_201 * V_201 ,
struct V_164 * V_124 ,
T_3 V_194 ,
unsigned V_131 ,
unsigned V_157 ,
struct V_1 * * V_202 ,
void * * V_203 )
{
T_9 V_134 = V_194 >> V_161 ;
struct V_1 * V_1 ;
int V_204 ;
ASSERT ( V_131 <= V_137 ) ;
V_1 = F_155 ( V_124 , V_134 ,
V_157 | V_205 ) ;
if ( ! V_1 )
return - V_206 ;
V_204 = F_156 ( V_1 , V_194 , V_131 , F_144 ) ;
if ( F_157 ( V_204 ) ) {
struct V_9 * V_9 = V_124 -> V_146 ;
F_152 ( V_9 , V_1 , V_194 , V_131 ) ;
F_76 ( V_1 ) ;
if ( V_194 + V_131 > F_121 ( V_9 ) )
F_158 ( V_9 , V_194 + V_131 , F_121 ( V_9 ) ) ;
F_159 ( V_1 ) ;
V_1 = NULL ;
}
* V_202 = V_1 ;
return V_204 ;
}
STATIC int
F_160 (
struct V_201 * V_201 ,
struct V_164 * V_124 ,
T_3 V_194 ,
unsigned V_131 ,
unsigned V_207 ,
struct V_1 * V_1 ,
void * V_203 )
{
int V_180 ;
ASSERT ( V_131 <= V_137 ) ;
V_180 = F_161 ( V_201 , V_124 , V_194 , V_131 , V_207 , V_1 , V_203 ) ;
if ( F_157 ( V_180 < V_131 ) ) {
struct V_9 * V_9 = V_124 -> V_146 ;
T_12 V_45 = F_121 ( V_9 ) ;
T_3 V_200 = V_194 + V_131 ;
if ( V_200 > V_45 ) {
F_158 ( V_9 , V_200 , V_45 ) ;
F_151 ( V_9 , V_45 , V_200 ) ;
}
}
return V_180 ;
}
STATIC T_7
F_162 (
struct V_164 * V_124 ,
T_7 V_208 )
{
struct V_9 * V_9 = (struct V_9 * ) V_124 -> V_146 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_163 ( F_6 ( V_9 ) ) ;
F_24 ( V_11 , V_209 ) ;
F_164 ( V_124 ) ;
F_26 ( V_11 , V_209 ) ;
return F_165 ( V_124 , V_208 , F_144 ) ;
}
STATIC int
F_166 (
struct V_201 * V_210 ,
struct V_1 * V_1 )
{
return F_167 ( V_1 , F_144 ) ;
}
STATIC int
F_168 (
struct V_201 * V_210 ,
struct V_164 * V_124 ,
struct V_211 * V_145 ,
unsigned V_212 )
{
return F_169 ( V_124 , V_145 , V_212 , F_144 ) ;
}
