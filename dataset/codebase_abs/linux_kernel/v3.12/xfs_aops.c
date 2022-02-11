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
struct V_25 * V_18 )
{
struct V_10 * V_11 = F_6 ( V_18 -> V_28 ) ;
struct V_31 * V_32 = V_18 -> V_35 ;
T_2 V_43 ;
F_19 ( & V_32 -> V_41 , V_42 ) ;
F_20 ( & F_21 ( V_11 ) -> V_36 -> V_37 . V_38 [ V_39 - 1 ] ,
0 , 1 , V_40 ) ;
F_22 ( V_11 , V_44 ) ;
V_43 = F_23 ( V_11 , V_18 -> V_26 + V_18 -> V_27 ) ;
if ( ! V_43 ) {
F_24 ( V_11 , V_44 ) ;
F_15 ( V_32 , 0 ) ;
return 0 ;
}
F_25 ( V_11 , V_18 -> V_26 , V_18 -> V_27 ) ;
V_11 -> V_29 . V_30 = V_43 ;
F_26 ( V_32 , V_11 , V_44 ) ;
F_27 ( V_32 , V_11 , V_45 ) ;
return F_28 ( V_32 , 0 ) ;
}
STATIC void
F_29 (
struct V_25 * V_18 )
{
if ( F_30 ( & V_18 -> V_46 ) ) {
struct V_12 * V_13 = F_6 ( V_18 -> V_28 ) -> V_14 ;
if ( V_18 -> V_47 == V_48 )
F_31 ( V_13 -> V_49 , & V_18 -> V_50 ) ;
else if ( V_18 -> V_35 ||
( V_18 -> V_51 && F_10 ( V_18 ) ) )
F_31 ( V_13 -> V_52 , & V_18 -> V_50 ) ;
else
F_8 ( V_18 ) ;
}
}
STATIC void
F_32 (
struct V_53 * V_54 )
{
T_1 * V_18 = F_33 ( V_54 , T_1 , V_50 ) ;
struct V_10 * V_11 = F_6 ( V_18 -> V_28 ) ;
int error = 0 ;
if ( F_34 ( V_11 -> V_14 ) ) {
V_18 -> V_23 = - V_55 ;
goto V_56;
}
if ( V_18 -> V_23 )
goto V_56;
if ( V_18 -> V_47 == V_48 ) {
error = F_35 ( V_11 , V_18 -> V_26 ,
V_18 -> V_27 ) ;
} else if ( V_18 -> V_51 && F_10 ( V_18 ) ) {
error = F_11 ( V_18 ) ;
if ( error )
goto V_56;
error = F_18 ( V_18 ) ;
} else if ( V_18 -> V_35 ) {
error = F_18 ( V_18 ) ;
} else {
ASSERT ( ! F_10 ( V_18 ) ) ;
}
V_56:
if ( error )
V_18 -> V_23 = - error ;
F_8 ( V_18 ) ;
}
STATIC void
F_36 (
struct V_25 * V_18 )
{
if ( F_30 ( & V_18 -> V_46 ) )
F_32 ( & V_18 -> V_50 ) ;
}
STATIC T_1 *
F_37 (
struct V_9 * V_9 ,
unsigned int type )
{
T_1 * V_18 ;
V_18 = F_38 ( V_24 , V_57 ) ;
F_39 ( & V_18 -> V_46 , 1 ) ;
V_18 -> V_51 = 0 ;
V_18 -> V_23 = 0 ;
V_18 -> V_58 = NULL ;
V_18 -> V_47 = type ;
V_18 -> V_28 = V_9 ;
V_18 -> V_20 = NULL ;
V_18 -> V_59 = NULL ;
V_18 -> V_26 = 0 ;
V_18 -> V_27 = 0 ;
V_18 -> V_35 = NULL ;
F_40 ( & V_18 -> V_50 , F_32 ) ;
return V_18 ;
}
STATIC int
F_41 (
struct V_9 * V_9 ,
T_3 V_60 ,
struct V_61 * V_62 ,
int type ,
int V_63 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_4 V_64 = 1 << V_9 -> V_65 ;
T_5 V_66 , V_67 ;
int error = 0 ;
int V_68 = V_69 ;
int V_70 = 1 ;
if ( F_34 ( V_13 ) )
return - F_42 ( V_55 ) ;
if ( type == V_48 )
V_68 |= V_71 ;
if ( ! F_43 ( V_11 , V_72 ) ) {
if ( V_63 )
return - F_42 ( V_73 ) ;
F_22 ( V_11 , V_72 ) ;
}
ASSERT ( V_11 -> V_29 . V_74 != V_75 ||
( V_11 -> V_76 . V_77 & V_78 ) ) ;
ASSERT ( V_60 <= V_13 -> V_79 -> V_80 ) ;
if ( V_60 + V_64 > V_13 -> V_79 -> V_80 )
V_64 = V_13 -> V_79 -> V_80 - V_60 ;
V_67 = F_44 ( V_13 , ( V_81 ) V_60 + V_64 ) ;
V_66 = F_45 ( V_13 , V_60 ) ;
error = F_46 ( V_11 , V_66 , V_67 - V_66 ,
V_62 , & V_70 , V_68 ) ;
F_24 ( V_11 , V_72 ) ;
if ( error )
return - F_42 ( error ) ;
if ( type == V_82 &&
( ! V_70 || F_47 ( V_62 -> V_83 ) ) ) {
error = F_48 ( V_11 , V_60 , V_64 , V_62 ) ;
if ( ! error )
F_49 ( V_11 , V_60 , V_64 , type , V_62 ) ;
return - F_42 ( error ) ;
}
#ifdef F_50
if ( type == V_48 ) {
ASSERT ( V_70 ) ;
ASSERT ( V_62 -> V_83 != V_84 ) ;
ASSERT ( V_62 -> V_83 != V_85 ) ;
}
#endif
if ( V_70 )
F_51 ( V_11 , V_60 , V_64 , type , V_62 ) ;
return 0 ;
}
STATIC int
F_52 (
struct V_9 * V_9 ,
struct V_61 * V_62 ,
T_6 V_60 )
{
V_60 >>= V_9 -> V_65 ;
return V_60 >= V_62 -> V_86 &&
V_60 < V_62 -> V_86 + V_62 -> V_87 ;
}
STATIC void
F_53 (
struct V_88 * V_88 ,
int error )
{
T_1 * V_18 = V_88 -> V_89 ;
ASSERT ( F_54 ( & V_88 -> V_90 ) >= 1 ) ;
V_18 -> V_23 = F_55 ( V_91 , & V_88 -> V_92 ) ? 0 : error ;
V_88 -> V_89 = NULL ;
V_88 -> V_93 = NULL ;
F_56 ( V_88 ) ;
F_29 ( V_18 ) ;
}
STATIC void
F_57 (
struct V_94 * V_95 ,
T_1 * V_18 ,
struct V_88 * V_88 )
{
F_58 ( & V_18 -> V_46 ) ;
V_88 -> V_89 = V_18 ;
V_88 -> V_93 = F_53 ;
F_59 ( V_95 -> V_96 == V_97 ? V_98 : V_99 , V_88 ) ;
}
STATIC struct V_88 *
F_60 (
struct V_4 * V_5 )
{
int V_100 = F_61 ( V_5 -> V_101 ) ;
struct V_88 * V_88 = F_62 ( V_102 , V_100 ) ;
ASSERT ( V_88 -> V_89 == NULL ) ;
V_88 -> V_103 = V_5 -> V_104 * ( V_5 -> V_105 >> 9 ) ;
V_88 -> V_106 = V_5 -> V_101 ;
return V_88 ;
}
STATIC void
F_63 (
struct V_4 * V_5 )
{
ASSERT ( F_64 ( V_5 ) ) ;
ASSERT ( F_65 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_66 ( V_5 ) ;
F_67 ( V_5 ) ;
F_68 ( V_5 ) ;
}
STATIC void
F_69 (
struct V_1 * V_1 ,
int V_107 ,
int V_108 )
{
ASSERT ( F_70 ( V_1 ) ) ;
ASSERT ( ! F_71 ( V_1 ) ) ;
if ( V_107 )
F_72 ( V_1 ) ;
F_73 ( V_1 ) ;
F_74 ( V_1 ) ;
if ( ! V_108 )
F_75 ( V_1 ) ;
}
static inline int F_76 ( struct V_88 * V_88 , struct V_4 * V_5 )
{
return F_77 ( V_88 , V_5 -> V_109 , V_5 -> V_105 , F_78 ( V_5 ) ) ;
}
STATIC void
F_79 (
struct V_94 * V_95 ,
T_1 * V_18 ,
int V_110 )
{
T_1 * V_6 = V_18 ;
T_1 * V_19 ;
struct V_4 * V_5 ;
struct V_88 * V_88 ;
T_7 V_111 = 0 ;
do {
V_19 = V_18 -> V_58 ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 )
F_63 ( V_5 ) ;
} while ( ( V_18 = V_19 ) != NULL );
V_18 = V_6 ;
do {
V_19 = V_18 -> V_58 ;
V_88 = NULL ;
if ( V_110 ) {
V_18 -> V_23 = - V_110 ;
F_29 ( V_18 ) ;
continue;
}
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 ) {
if ( ! V_88 ) {
V_112:
V_88 = F_60 ( V_5 ) ;
} else if ( V_5 -> V_104 != V_111 + 1 ) {
F_57 ( V_95 , V_18 , V_88 ) ;
goto V_112;
}
if ( F_76 ( V_88 , V_5 ) != V_5 -> V_105 ) {
F_57 ( V_95 , V_18 , V_88 ) ;
goto V_112;
}
V_111 = V_5 -> V_104 ;
}
if ( V_88 )
F_57 ( V_95 , V_18 , V_88 ) ;
F_29 ( V_18 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_80 (
T_1 * V_18 )
{
T_1 * V_19 ;
struct V_4 * V_5 , * V_113 ;
do {
V_19 = V_18 -> V_58 ;
V_5 = V_18 -> V_20 ;
do {
V_113 = V_5 -> V_21 ;
F_81 ( V_5 ) ;
F_82 ( V_5 ) ;
} while ( ( V_5 = V_113 ) != NULL );
F_9 ( V_18 , V_24 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_83 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_6 V_60 ,
unsigned int type ,
T_1 * * V_114 ,
int V_115 )
{
T_1 * V_18 = * V_114 ;
if ( ! V_18 || V_115 || type != V_18 -> V_47 ) {
T_1 * V_116 = * V_114 ;
V_18 = F_37 ( V_9 , type ) ;
V_18 -> V_26 = V_60 ;
V_18 -> V_20 = V_5 ;
V_18 -> V_59 = V_5 ;
if ( V_116 )
V_116 -> V_58 = V_18 ;
* V_114 = V_18 ;
} else {
V_18 -> V_59 -> V_21 = V_5 ;
V_18 -> V_59 = V_5 ;
}
V_5 -> V_21 = NULL ;
V_18 -> V_27 += V_5 -> V_105 ;
}
STATIC void
F_84 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_61 * V_62 ,
T_6 V_60 )
{
T_7 V_117 ;
struct V_12 * V_118 = F_6 ( V_9 ) -> V_14 ;
T_6 V_119 = F_85 ( V_118 , V_62 -> V_86 ) ;
T_8 V_120 = F_86 ( F_6 ( V_9 ) , V_62 -> V_83 ) ;
ASSERT ( V_62 -> V_83 != V_84 ) ;
ASSERT ( V_62 -> V_83 != V_85 ) ;
V_117 = ( V_120 >> ( V_9 -> V_65 - V_121 ) ) +
( ( V_60 - V_119 ) >> V_9 -> V_65 ) ;
ASSERT ( V_117 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_104 = V_117 ;
F_87 ( V_5 ) ;
}
STATIC void
F_88 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_61 * V_62 ,
T_6 V_60 )
{
ASSERT ( V_62 -> V_83 != V_84 ) ;
ASSERT ( V_62 -> V_83 != V_85 ) ;
F_84 ( V_9 , V_5 , V_62 , V_60 ) ;
F_87 ( V_5 ) ;
F_89 ( V_5 ) ;
F_90 ( V_5 ) ;
}
STATIC int
F_91 (
struct V_1 * V_1 ,
unsigned int type )
{
if ( F_71 ( V_1 ) )
return 0 ;
if ( V_1 -> V_122 && F_92 ( V_1 ) ) {
struct V_4 * V_5 , * V_6 ;
int V_123 = 0 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) )
V_123 += ( type == V_48 ) ;
else if ( F_4 ( V_5 ) )
V_123 += ( type == V_82 ) ;
else if ( F_93 ( V_5 ) && F_64 ( V_5 ) )
V_123 += ( type == V_124 ) ;
else
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_123 )
return 1 ;
}
return 0 ;
}
STATIC int
F_94 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_3 V_125 ,
struct V_61 * V_62 ,
T_1 * * V_126 ,
struct V_94 * V_95 )
{
struct V_4 * V_5 , * V_6 ;
T_6 V_127 ;
unsigned long V_128 ;
unsigned int type ;
int V_129 , V_130 ;
int V_64 = 0 , V_56 = 0 , V_131 = 1 ;
T_6 V_60 = F_95 ( V_1 ) ;
if ( V_1 -> V_132 != V_125 )
goto V_110;
if ( ! F_96 ( V_1 ) )
goto V_110;
if ( F_71 ( V_1 ) )
goto V_133;
if ( V_1 -> V_122 != V_9 -> V_134 )
goto V_133;
if ( ! F_91 ( V_1 , ( * V_126 ) -> V_47 ) )
goto V_133;
V_127 = F_97 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode)) ;
if ( ! F_52 ( V_9 , V_62 , V_127 ) )
goto V_133;
V_129 = 1 << V_9 -> V_65 ;
V_128 = F_97 (unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE) ;
V_128 = V_128 ? F_98 ( V_128 , V_129 ) : V_135 ;
V_130 = V_128 / V_129 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( V_60 >= V_127 )
break;
if ( ! F_99 ( V_5 ) )
V_131 = 0 ;
if ( ! ( F_100 ( V_1 ) || F_99 ( V_5 ) ) ) {
V_56 = 1 ;
continue;
}
if ( F_3 ( V_5 ) || F_4 ( V_5 ) ||
F_64 ( V_5 ) ) {
if ( F_3 ( V_5 ) )
type = V_48 ;
else if ( F_4 ( V_5 ) )
type = V_82 ;
else
type = V_124 ;
if ( ! F_52 ( V_9 , V_62 , V_60 ) ) {
V_56 = 1 ;
continue;
}
F_101 ( V_5 ) ;
if ( type != V_124 )
F_88 ( V_9 , V_5 , V_62 , V_60 ) ;
F_83 ( V_9 , V_5 , V_60 , type ,
V_126 , V_56 ) ;
V_130 -- ;
V_64 ++ ;
} else {
V_56 = 1 ;
}
} while ( V_60 += V_129 , ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_131 && V_5 == V_6 )
F_102 ( V_1 ) ;
if ( V_64 ) {
if ( -- V_95 -> V_136 <= 0 &&
V_95 -> V_96 == V_137 )
V_56 = 1 ;
}
F_69 ( V_1 , ! V_130 , V_64 ) ;
return V_56 ;
V_133:
F_74 ( V_1 ) ;
V_110:
return 1 ;
}
STATIC void
F_103 (
struct V_9 * V_9 ,
T_9 V_125 ,
struct V_61 * V_62 ,
T_1 * * V_126 ,
struct V_94 * V_95 ,
T_9 V_138 )
{
struct V_139 V_140 ;
int V_56 = 0 , V_141 ;
F_104 ( & V_140 , 0 ) ;
while ( ! V_56 && V_125 <= V_138 ) {
unsigned V_129 = F_97 ( T_9 , V_142 , V_138 - V_125 + 1 ) ;
if ( ! F_105 ( & V_140 , V_9 -> V_134 , V_125 , V_129 ) )
break;
for ( V_141 = 0 ; V_141 < F_106 ( & V_140 ) ; V_141 ++ ) {
V_56 = F_94 ( V_9 , V_140 . V_143 [ V_141 ] , V_125 ++ ,
V_62 , V_126 , V_95 ) ;
if ( V_56 )
break;
}
F_107 ( & V_140 ) ;
F_108 () ;
}
}
STATIC void
F_109 (
struct V_1 * V_1 ,
unsigned int V_60 ,
unsigned int V_144 )
{
F_110 ( V_1 -> V_122 -> V_145 , V_1 , V_60 ,
V_144 ) ;
F_111 ( V_1 , V_60 , V_144 ) ;
}
STATIC void
F_112 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_122 -> V_145 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_3 V_60 = F_95 ( V_1 ) ;
if ( ! F_91 ( V_1 , V_82 ) )
goto V_146;
if ( F_34 ( V_11 -> V_14 ) )
goto V_146;
F_113 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_147 , V_60 ) ;
F_22 ( V_11 , V_44 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_5 V_148 ;
if ( ! F_4 ( V_5 ) )
goto V_149;
V_148 = F_45 ( V_11 -> V_14 , V_60 ) ;
error = F_114 ( V_11 , V_148 , 1 ) ;
if ( error ) {
if ( ! F_34 ( V_11 -> V_14 ) ) {
F_113 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_149:
V_60 += 1 << V_9 -> V_65 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_24 ( V_11 , V_44 ) ;
V_146:
F_109 ( V_1 , 0 , V_135 ) ;
return;
}
STATIC int
F_115 (
struct V_1 * V_1 ,
struct V_94 * V_95 )
{
struct V_9 * V_9 = V_1 -> V_122 -> V_145 ;
struct V_4 * V_5 , * V_6 ;
struct V_61 V_62 ;
T_1 * V_18 = NULL , * V_150 = NULL ;
T_3 V_60 ;
unsigned int type ;
T_10 V_127 ;
T_9 V_151 , V_152 ;
T_4 V_129 ;
int V_153 , V_154 = 0 , V_131 = 1 ;
int V_64 = 0 ;
int V_63 = 0 ;
F_116 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_92 ( V_1 ) ) ;
if ( F_117 ( ( V_155 -> V_156 & ( V_157 | V_158 ) ) ==
V_157 ) )
goto V_159;
if ( F_118 ( V_155 -> V_156 & V_42 ) )
goto V_159;
V_60 = F_119 ( V_9 ) ;
V_151 = V_60 >> V_160 ;
V_152 = ( V_60 - 1 ) >> V_160 ;
if ( V_1 -> V_132 >= V_151 ) {
unsigned V_161 = V_60 & ( V_135 - 1 ) ;
if ( V_1 -> V_132 >= V_151 + 1 || V_161 == 0 )
goto V_159;
F_120 ( V_1 , V_161 , V_135 ) ;
}
V_127 = F_97 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
offset) ;
V_129 = 1 << V_9 -> V_65 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_60 = F_95 ( V_1 ) ;
type = V_124 ;
if ( V_95 -> V_96 == V_137 )
V_63 = 1 ;
do {
int V_162 = 0 ;
if ( V_60 >= V_127 )
break;
if ( ! F_99 ( V_5 ) )
V_131 = 0 ;
if ( ! F_64 ( V_5 ) && F_99 ( V_5 ) ) {
V_154 = 0 ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( type != V_48 ) {
type = V_48 ;
V_154 = 0 ;
}
} else if ( F_4 ( V_5 ) ) {
if ( type != V_82 ) {
type = V_82 ;
V_154 = 0 ;
}
} else if ( F_99 ( V_5 ) ) {
if ( type != V_124 ) {
type = V_124 ;
V_154 = 0 ;
}
} else {
if ( F_100 ( V_1 ) )
ASSERT ( F_64 ( V_5 ) ) ;
V_154 = 0 ;
continue;
}
if ( V_154 )
V_154 = F_52 ( V_9 , & V_62 , V_60 ) ;
if ( ! V_154 ) {
V_162 = 1 ;
V_153 = F_41 ( V_9 , V_60 , & V_62 , type ,
V_63 ) ;
if ( V_153 )
goto error;
V_154 = F_52 ( V_9 , & V_62 , V_60 ) ;
}
if ( V_154 ) {
F_101 ( V_5 ) ;
if ( type != V_124 )
F_88 ( V_9 , V_5 , & V_62 , V_60 ) ;
F_83 ( V_9 , V_5 , V_60 , type , & V_18 ,
V_162 ) ;
V_64 ++ ;
}
if ( ! V_150 )
V_150 = V_18 ;
} while ( V_60 += V_129 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_131 && V_5 == V_6 )
F_102 ( V_1 ) ;
F_69 ( V_1 , 1 , V_64 ) ;
if ( ! V_18 )
return 0 ;
ASSERT ( V_150 ) ;
if ( V_154 ) {
T_6 V_151 ;
V_151 = V_62 . V_86 + V_62 . V_87 ;
V_151 <<= V_9 -> V_65 ;
V_151 = ( V_151 - 1 ) >> V_160 ;
if ( V_151 > V_152 )
V_151 = V_152 ;
F_103 ( V_9 , V_1 -> V_132 + 1 , & V_62 , & V_18 ,
V_95 , V_151 ) ;
}
V_153 = 0 ;
if ( V_18 -> V_47 != V_48 && F_10 ( V_18 ) )
V_153 = F_11 ( V_18 ) ;
F_79 ( V_95 , V_150 , V_153 ) ;
return 0 ;
error:
if ( V_150 )
F_80 ( V_150 ) ;
if ( V_153 == - V_73 )
goto V_159;
F_112 ( V_1 ) ;
F_121 ( V_1 ) ;
F_74 ( V_1 ) ;
return V_153 ;
V_159:
F_122 ( V_95 , V_1 ) ;
F_74 ( V_1 ) ;
return 0 ;
}
STATIC int
F_123 (
struct V_163 * V_122 ,
struct V_94 * V_95 )
{
F_124 ( F_6 ( V_122 -> V_145 ) , V_164 ) ;
return F_125 ( V_122 , V_95 ) ;
}
STATIC int
F_126 (
struct V_1 * V_1 ,
T_11 V_165 )
{
int V_2 , V_3 ;
F_127 ( V_1 -> V_122 -> V_145 , V_1 , 0 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_118 ( V_2 ) )
return 0 ;
if ( F_118 ( V_3 ) )
return 0 ;
return F_128 ( V_1 ) ;
}
STATIC int
F_129 (
struct V_9 * V_9 ,
T_7 V_166 ,
struct V_4 * V_167 ,
int V_168 ,
int V_169 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_5 V_66 , V_67 ;
int error = 0 ;
int V_170 = 0 ;
struct V_61 V_62 ;
int V_70 = 1 ;
T_6 V_60 ;
T_4 V_171 ;
int V_172 = 0 ;
if ( F_34 ( V_13 ) )
return - F_42 ( V_55 ) ;
V_60 = ( T_6 ) V_166 << V_9 -> V_65 ;
ASSERT ( V_167 -> V_105 >= ( 1 << V_9 -> V_65 ) ) ;
V_171 = V_167 -> V_105 ;
if ( ! V_168 && V_169 && V_60 >= F_119 ( V_9 ) )
return 0 ;
if ( V_168 && ! V_169 ) {
V_170 = V_44 ;
F_22 ( V_11 , V_170 ) ;
} else {
V_170 = F_130 ( V_11 ) ;
}
ASSERT ( V_60 <= V_13 -> V_79 -> V_80 ) ;
if ( V_60 + V_171 > V_13 -> V_79 -> V_80 )
V_171 = V_13 -> V_79 -> V_80 - V_60 ;
V_67 = F_44 ( V_13 , ( V_81 ) V_60 + V_171 ) ;
V_66 = F_45 ( V_13 , V_60 ) ;
error = F_46 ( V_11 , V_66 , V_67 - V_66 ,
& V_62 , & V_70 , V_69 ) ;
if ( error )
goto V_173;
if ( V_168 &&
( ! V_70 ||
( V_62 . V_83 == V_84 ||
V_62 . V_83 == V_85 ) ) ) {
if ( V_169 || F_131 ( V_11 ) ) {
F_24 ( V_11 , V_170 ) ;
error = F_132 ( V_11 , V_60 , V_171 ,
& V_62 , V_70 ) ;
if ( error )
return - error ;
V_172 = 1 ;
} else {
if ( V_70 && V_62 . V_83 == V_84 )
V_172 = 1 ;
error = F_133 ( V_11 , V_60 , V_171 , & V_62 ) ;
if ( error )
goto V_173;
F_24 ( V_11 , V_170 ) ;
}
F_134 ( V_11 , V_60 , V_171 , 0 , & V_62 ) ;
} else if ( V_70 ) {
F_135 ( V_11 , V_60 , V_171 , 0 , & V_62 ) ;
F_24 ( V_11 , V_170 ) ;
} else {
F_136 ( V_11 , V_60 , V_171 ) ;
goto V_173;
}
if ( V_62 . V_83 != V_84 &&
V_62 . V_83 != V_85 ) {
if ( V_168 || ! F_137 ( & V_62 ) )
F_84 ( V_9 , V_167 , & V_62 , V_60 ) ;
if ( V_168 && F_137 ( & V_62 ) ) {
if ( V_169 ) {
V_167 -> V_21 = V_9 ;
F_138 ( V_167 ) ;
}
F_139 ( V_167 ) ;
}
}
V_167 -> V_101 = F_5 ( V_9 ) ;
if ( V_168 &&
( ( ! F_64 ( V_167 ) && ! F_99 ( V_167 ) ) ||
( V_60 >= F_119 ( V_9 ) ) ||
( V_172 || F_137 ( & V_62 ) ) ) )
F_140 ( V_167 ) ;
if ( V_62 . V_83 == V_85 ) {
F_141 ( V_169 ) ;
if ( V_168 ) {
F_67 ( V_167 ) ;
F_87 ( V_167 ) ;
F_142 ( V_167 ) ;
}
}
if ( V_169 || V_171 > ( 1 << V_9 -> V_65 ) ) {
T_6 V_174 ;
V_174 = V_62 . V_86 + V_62 . V_87 - V_166 ;
V_174 <<= V_9 -> V_65 ;
ASSERT ( V_174 > 0 ) ;
if ( V_174 > V_171 )
V_174 = V_171 ;
if ( V_174 > V_175 )
V_174 = V_175 ;
V_167 -> V_105 = V_174 ;
}
return 0 ;
V_173:
F_24 ( V_11 , V_170 ) ;
return - error ;
}
int
F_143 (
struct V_9 * V_9 ,
T_7 V_166 ,
struct V_4 * V_167 ,
int V_168 )
{
return F_129 ( V_9 , V_166 , V_167 , V_168 , 0 ) ;
}
STATIC int
F_144 (
struct V_9 * V_9 ,
T_7 V_166 ,
struct V_4 * V_167 ,
int V_168 )
{
return F_129 ( V_9 , V_166 , V_167 , V_168 , 1 ) ;
}
STATIC void
F_145 (
struct V_176 * V_177 ,
T_3 V_60 ,
T_4 V_171 ,
void * V_178 )
{
struct V_25 * V_18 = V_177 -> V_178 ;
if ( V_60 + V_171 > F_119 ( V_18 -> V_28 ) )
F_146 ( V_18 -> V_28 , V_60 + V_171 ) ;
V_177 -> V_178 = NULL ;
V_18 -> V_26 = V_60 ;
V_18 -> V_27 = V_171 ;
if ( V_178 && V_171 > 0 )
V_18 -> V_47 = V_48 ;
F_36 ( V_18 ) ;
}
STATIC T_4
F_147 (
int V_179 ,
struct V_176 * V_177 ,
const struct V_180 * V_181 ,
T_3 V_60 ,
unsigned long V_182 )
{
struct V_9 * V_9 = V_177 -> V_183 -> V_184 -> V_145 ;
struct V_8 * V_185 = F_5 ( V_9 ) ;
struct V_25 * V_18 = NULL ;
T_4 V_186 ;
if ( V_179 & V_99 ) {
T_12 V_171 = F_148 ( V_181 , V_182 ) ;
V_177 -> V_178 = V_18 = F_37 ( V_9 , V_187 ) ;
if ( V_60 + V_171 > F_6 ( V_9 ) -> V_29 . V_30 )
V_18 -> V_51 = 1 ;
V_186 = F_149 ( V_179 , V_177 , V_9 , V_185 , V_181 ,
V_60 , V_182 ,
F_144 ,
F_145 , NULL , 0 ) ;
if ( V_186 != - V_188 && V_177 -> V_178 )
goto V_189;
} else {
V_186 = F_149 ( V_179 , V_177 , V_9 , V_185 , V_181 ,
V_60 , V_182 ,
F_144 ,
NULL , NULL , 0 ) ;
}
return V_186 ;
V_189:
F_8 ( V_18 ) ;
return V_186 ;
}
STATIC void
F_150 (
struct V_9 * V_9 ,
T_3 V_190 ,
T_3 V_191 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_5 V_148 ;
T_5 V_67 ;
int error ;
V_148 = F_44 ( V_11 -> V_14 , V_190 ) ;
V_67 = F_44 ( V_11 -> V_14 , V_191 ) ;
if ( V_67 <= V_148 )
return;
F_22 ( V_11 , V_44 ) ;
error = F_114 ( V_11 , V_148 ,
V_67 - V_148 ) ;
if ( error ) {
if ( ! F_34 ( V_11 -> V_14 ) ) {
F_113 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_147 ) ;
}
}
F_24 ( V_11 , V_44 ) ;
}
STATIC void
F_151 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_3 V_192 ,
unsigned V_129 )
{
T_3 V_193 ;
T_3 V_194 ;
T_3 V_195 ;
T_3 V_196 = V_192 & ( V_135 - 1 ) ;
T_3 V_197 = V_196 + V_129 ;
struct V_4 * V_5 , * V_6 ;
V_193 = ( V_192 >> V_160 ) << V_160 ;
ASSERT ( V_193 + V_196 == V_192 ) ;
V_6 = F_2 ( V_1 ) ;
V_194 = 0 ;
for ( V_5 = V_6 ; V_5 != V_6 || ! V_194 ;
V_5 = V_5 -> V_7 , V_194 = V_195 ,
V_193 += V_5 -> V_105 ) {
V_195 = V_194 + V_5 -> V_105 ;
if ( V_195 <= V_196 )
continue;
if ( V_194 >= V_197 )
break;
if ( ! F_4 ( V_5 ) )
continue;
if ( ! F_152 ( V_5 ) && V_193 < F_119 ( V_9 ) )
continue;
F_150 ( V_9 , V_193 ,
V_193 + V_5 -> V_105 ) ;
}
}
STATIC int
F_153 (
struct V_198 * V_198 ,
struct V_163 * V_122 ,
T_3 V_192 ,
unsigned V_129 ,
unsigned V_156 ,
struct V_1 * * V_199 ,
void * * V_200 )
{
T_9 V_132 = V_192 >> V_160 ;
struct V_1 * V_1 ;
int V_201 ;
ASSERT ( V_129 <= V_135 ) ;
V_1 = F_154 ( V_122 , V_132 ,
V_156 | V_202 ) ;
if ( ! V_1 )
return - V_203 ;
V_201 = F_155 ( V_1 , V_192 , V_129 , F_143 ) ;
if ( F_156 ( V_201 ) ) {
struct V_9 * V_9 = V_122 -> V_145 ;
F_151 ( V_9 , V_1 , V_192 , V_129 ) ;
F_74 ( V_1 ) ;
if ( V_192 + V_129 > F_119 ( V_9 ) )
F_157 ( V_9 , F_119 ( V_9 ) ) ;
F_158 ( V_1 ) ;
V_1 = NULL ;
}
* V_199 = V_1 ;
return V_201 ;
}
STATIC int
F_159 (
struct V_198 * V_198 ,
struct V_163 * V_122 ,
T_3 V_192 ,
unsigned V_129 ,
unsigned V_204 ,
struct V_1 * V_1 ,
void * V_200 )
{
int V_186 ;
ASSERT ( V_129 <= V_135 ) ;
V_186 = F_160 ( V_198 , V_122 , V_192 , V_129 , V_204 , V_1 , V_200 ) ;
if ( F_156 ( V_186 < V_129 ) ) {
struct V_9 * V_9 = V_122 -> V_145 ;
T_12 V_43 = F_119 ( V_9 ) ;
T_3 V_197 = V_192 + V_129 ;
if ( V_197 > V_43 ) {
F_157 ( V_9 , V_43 ) ;
F_150 ( V_9 , V_43 , V_197 ) ;
}
}
return V_186 ;
}
STATIC T_7
F_161 (
struct V_163 * V_122 ,
T_7 V_205 )
{
struct V_9 * V_9 = (struct V_9 * ) V_122 -> V_145 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_162 ( F_6 ( V_9 ) ) ;
F_22 ( V_11 , V_206 ) ;
F_163 ( V_122 ) ;
F_24 ( V_11 , V_206 ) ;
return F_164 ( V_122 , V_205 , F_143 ) ;
}
STATIC int
F_165 (
struct V_198 * V_207 ,
struct V_1 * V_1 )
{
return F_166 ( V_1 , F_143 ) ;
}
STATIC int
F_167 (
struct V_198 * V_207 ,
struct V_163 * V_122 ,
struct V_208 * V_143 ,
unsigned V_209 )
{
return F_168 ( V_122 , V_143 , V_209 , F_143 ) ;
}
