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
STATIC T_2
F_12 (
T_1 * V_18 )
{
T_3 * V_11 = F_6 ( V_18 -> V_27 ) ;
T_2 V_29 ;
T_2 V_30 ;
V_30 = V_18 -> V_31 + V_18 -> V_32 ;
V_29 = F_13 ( F_14 ( F_15 ( V_11 ) ) , V_30 ) ;
return V_29 > V_11 -> V_33 . V_34 ? V_29 : 0 ;
}
static inline bool F_16 ( struct V_35 * V_18 )
{
return V_18 -> V_31 + V_18 -> V_32 >
F_6 ( V_18 -> V_27 ) -> V_33 . V_34 ;
}
STATIC int
F_17 (
T_1 * V_18 )
{
T_3 * V_11 = F_6 ( V_18 -> V_27 ) ;
T_2 V_29 ;
if ( ! F_18 ( V_11 , V_36 ) )
return V_37 ;
V_29 = F_12 ( V_18 ) ;
if ( V_29 ) {
F_19 ( V_11 , V_18 -> V_31 , V_18 -> V_32 ) ;
V_11 -> V_33 . V_34 = V_29 ;
F_20 ( V_11 ) ;
}
F_21 ( V_11 , V_36 ) ;
return 0 ;
}
STATIC void
F_22 (
struct V_35 * V_18 )
{
if ( F_23 ( & V_18 -> V_38 ) ) {
if ( V_18 -> V_39 == V_40 )
F_24 ( V_41 , & V_18 -> V_42 ) ;
else if ( F_16 ( V_18 ) )
F_24 ( V_43 , & V_18 -> V_42 ) ;
else
F_8 ( V_18 ) ;
}
}
STATIC void
F_25 (
struct V_44 * V_45 )
{
T_1 * V_18 = F_26 ( V_45 , T_1 , V_42 ) ;
struct V_10 * V_11 = F_6 ( V_18 -> V_27 ) ;
int error = 0 ;
if ( F_27 ( V_11 -> V_14 ) ) {
V_18 -> V_23 = - V_46 ;
goto V_47;
}
if ( V_18 -> V_23 )
goto V_47;
if ( V_18 -> V_39 == V_40 ) {
error = F_28 ( V_11 , V_18 -> V_31 ,
V_18 -> V_32 ) ;
if ( error ) {
V_18 -> V_23 = - error ;
goto V_47;
}
}
error = F_17 ( V_18 ) ;
ASSERT ( ! error || error == V_37 ) ;
V_47:
if ( error == V_37 ) {
F_29 ( & V_18 -> V_38 ) ;
F_22 ( V_18 ) ;
F_30 ( 1 ) ;
} else {
F_8 ( V_18 ) ;
}
}
STATIC void
F_31 (
struct V_35 * V_18 )
{
if ( F_23 ( & V_18 -> V_38 ) )
F_25 ( & V_18 -> V_42 ) ;
}
STATIC T_1 *
F_32 (
struct V_9 * V_9 ,
unsigned int type )
{
T_1 * V_18 ;
V_18 = F_33 ( V_28 , V_48 ) ;
F_34 ( & V_18 -> V_38 , 1 ) ;
V_18 -> V_25 = 0 ;
V_18 -> V_23 = 0 ;
V_18 -> V_49 = NULL ;
V_18 -> V_39 = type ;
V_18 -> V_27 = V_9 ;
V_18 -> V_20 = NULL ;
V_18 -> V_50 = NULL ;
V_18 -> V_31 = 0 ;
V_18 -> V_32 = 0 ;
V_18 -> V_24 = NULL ;
V_18 -> V_26 = 0 ;
F_35 ( & V_18 -> V_42 , F_25 ) ;
return V_18 ;
}
STATIC int
F_36 (
struct V_9 * V_9 ,
T_4 V_51 ,
struct V_52 * V_53 ,
int type ,
int V_54 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_5 V_55 = 1 << V_9 -> V_56 ;
T_6 V_57 , V_58 ;
int error = 0 ;
int V_59 = V_60 ;
int V_61 = 1 ;
if ( F_27 ( V_13 ) )
return - F_37 ( V_46 ) ;
if ( type == V_40 )
V_59 |= V_62 ;
if ( ! F_18 ( V_11 , V_63 ) ) {
if ( V_54 )
return - F_37 ( V_37 ) ;
F_38 ( V_11 , V_63 ) ;
}
ASSERT ( V_11 -> V_33 . V_64 != V_65 ||
( V_11 -> V_66 . V_67 & V_68 ) ) ;
ASSERT ( V_51 <= V_13 -> V_69 ) ;
if ( V_51 + V_55 > V_13 -> V_69 )
V_55 = V_13 -> V_69 - V_51 ;
V_58 = F_39 ( V_13 , ( V_70 ) V_51 + V_55 ) ;
V_57 = F_40 ( V_13 , V_51 ) ;
error = F_41 ( V_11 , V_57 , V_58 - V_57 ,
V_53 , & V_61 , V_59 ) ;
F_21 ( V_11 , V_63 ) ;
if ( error )
return - F_37 ( error ) ;
if ( type == V_71 &&
( ! V_61 || F_42 ( V_53 -> V_72 ) ) ) {
error = F_43 ( V_11 , V_51 , V_55 , V_53 ) ;
if ( ! error )
F_44 ( V_11 , V_51 , V_55 , type , V_53 ) ;
return - F_37 ( error ) ;
}
#ifdef F_45
if ( type == V_40 ) {
ASSERT ( V_61 ) ;
ASSERT ( V_53 -> V_72 != V_73 ) ;
ASSERT ( V_53 -> V_72 != V_74 ) ;
}
#endif
if ( V_61 )
F_46 ( V_11 , V_51 , V_55 , type , V_53 ) ;
return 0 ;
}
STATIC int
F_47 (
struct V_9 * V_9 ,
struct V_52 * V_53 ,
T_7 V_51 )
{
V_51 >>= V_9 -> V_56 ;
return V_51 >= V_53 -> V_75 &&
V_51 < V_53 -> V_75 + V_53 -> V_76 ;
}
STATIC void
F_48 (
struct V_77 * V_77 ,
int error )
{
T_1 * V_18 = V_77 -> V_78 ;
ASSERT ( F_49 ( & V_77 -> V_79 ) >= 1 ) ;
V_18 -> V_23 = F_50 ( V_80 , & V_77 -> V_81 ) ? 0 : error ;
V_77 -> V_78 = NULL ;
V_77 -> V_82 = NULL ;
F_51 ( V_77 ) ;
F_22 ( V_18 ) ;
}
STATIC void
F_52 (
struct V_83 * V_84 ,
T_1 * V_18 ,
struct V_77 * V_77 )
{
F_29 ( & V_18 -> V_38 ) ;
V_77 -> V_78 = V_18 ;
V_77 -> V_82 = F_48 ;
if ( F_12 ( V_18 ) )
F_20 ( F_6 ( V_18 -> V_27 ) ) ;
F_53 ( V_84 -> V_85 == V_86 ? V_87 : V_88 , V_77 ) ;
}
STATIC struct V_77 *
F_54 (
struct V_4 * V_5 )
{
int V_89 = F_55 ( V_5 -> V_90 ) ;
struct V_77 * V_77 = F_56 ( V_91 , V_89 ) ;
ASSERT ( V_77 -> V_78 == NULL ) ;
V_77 -> V_92 = V_5 -> V_93 * ( V_5 -> V_94 >> 9 ) ;
V_77 -> V_95 = V_5 -> V_90 ;
return V_77 ;
}
STATIC void
F_57 (
struct V_4 * V_5 )
{
ASSERT ( F_58 ( V_5 ) ) ;
ASSERT ( F_59 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_60 ( V_5 ) ;
F_61 ( V_5 ) ;
F_62 ( V_5 ) ;
}
STATIC void
F_63 (
struct V_1 * V_1 ,
int V_96 ,
int V_97 )
{
ASSERT ( F_64 ( V_1 ) ) ;
ASSERT ( ! F_65 ( V_1 ) ) ;
if ( V_96 )
F_66 ( V_1 ) ;
F_67 ( V_1 ) ;
F_68 ( V_1 ) ;
if ( ! V_97 )
F_69 ( V_1 ) ;
}
static inline int F_70 ( struct V_77 * V_77 , struct V_4 * V_5 )
{
return F_71 ( V_77 , V_5 -> V_98 , V_5 -> V_94 , F_72 ( V_5 ) ) ;
}
STATIC void
F_73 (
struct V_83 * V_84 ,
T_1 * V_18 )
{
T_1 * V_6 = V_18 ;
T_1 * V_19 ;
struct V_4 * V_5 ;
struct V_77 * V_77 ;
T_8 V_99 = 0 ;
do {
V_19 = V_18 -> V_49 ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 )
F_57 ( V_5 ) ;
} while ( ( V_18 = V_19 ) != NULL );
V_18 = V_6 ;
do {
V_19 = V_18 -> V_49 ;
V_77 = NULL ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 ) {
if ( ! V_77 ) {
V_100:
V_77 = F_54 ( V_5 ) ;
} else if ( V_5 -> V_93 != V_99 + 1 ) {
F_52 ( V_84 , V_18 , V_77 ) ;
goto V_100;
}
if ( F_70 ( V_77 , V_5 ) != V_5 -> V_94 ) {
F_52 ( V_84 , V_18 , V_77 ) ;
goto V_100;
}
V_99 = V_5 -> V_93 ;
}
if ( V_77 )
F_52 ( V_84 , V_18 , V_77 ) ;
F_22 ( V_18 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_74 (
T_1 * V_18 )
{
T_1 * V_19 ;
struct V_4 * V_5 , * V_101 ;
do {
V_19 = V_18 -> V_49 ;
V_5 = V_18 -> V_20 ;
do {
V_101 = V_5 -> V_21 ;
F_75 ( V_5 ) ;
F_76 ( V_5 ) ;
} while ( ( V_5 = V_101 ) != NULL );
F_11 ( V_18 , V_28 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_77 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_7 V_51 ,
unsigned int type ,
T_1 * * V_102 ,
int V_103 )
{
T_1 * V_18 = * V_102 ;
if ( ! V_18 || V_103 || type != V_18 -> V_39 ) {
T_1 * V_104 = * V_102 ;
V_18 = F_32 ( V_9 , type ) ;
V_18 -> V_31 = V_51 ;
V_18 -> V_20 = V_5 ;
V_18 -> V_50 = V_5 ;
if ( V_104 )
V_104 -> V_49 = V_18 ;
* V_102 = V_18 ;
} else {
V_18 -> V_50 -> V_21 = V_5 ;
V_18 -> V_50 = V_5 ;
}
V_5 -> V_21 = NULL ;
V_18 -> V_32 += V_5 -> V_94 ;
}
STATIC void
F_78 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_52 * V_53 ,
T_7 V_51 )
{
T_8 V_105 ;
struct V_12 * V_106 = F_6 ( V_9 ) -> V_14 ;
T_7 V_107 = F_79 ( V_106 , V_53 -> V_75 ) ;
T_9 V_108 = F_80 ( F_6 ( V_9 ) , V_53 -> V_72 ) ;
ASSERT ( V_53 -> V_72 != V_73 ) ;
ASSERT ( V_53 -> V_72 != V_74 ) ;
V_105 = ( V_108 >> ( V_9 -> V_56 - V_109 ) ) +
( ( V_51 - V_107 ) >> V_9 -> V_56 ) ;
ASSERT ( V_105 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_93 = V_105 ;
F_81 ( V_5 ) ;
}
STATIC void
F_82 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_52 * V_53 ,
T_7 V_51 )
{
ASSERT ( V_53 -> V_72 != V_73 ) ;
ASSERT ( V_53 -> V_72 != V_74 ) ;
F_78 ( V_9 , V_5 , V_53 , V_51 ) ;
F_81 ( V_5 ) ;
F_83 ( V_5 ) ;
F_84 ( V_5 ) ;
}
STATIC int
F_85 (
struct V_1 * V_1 ,
unsigned int type )
{
if ( F_65 ( V_1 ) )
return 0 ;
if ( V_1 -> V_110 && F_86 ( V_1 ) ) {
struct V_4 * V_5 , * V_6 ;
int V_111 = 0 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) )
V_111 = ( type == V_40 ) ;
else if ( F_4 ( V_5 ) )
V_111 = ( type == V_71 ) ;
else if ( F_87 ( V_5 ) && F_58 ( V_5 ) )
V_111 = ( type == V_112 ) ;
else
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_111 )
return 1 ;
}
return 0 ;
}
STATIC int
F_88 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_4 V_113 ,
struct V_52 * V_53 ,
T_1 * * V_114 ,
struct V_83 * V_84 )
{
struct V_4 * V_5 , * V_6 ;
T_7 V_115 ;
unsigned long V_116 ;
unsigned int type ;
int V_117 , V_118 ;
int V_55 = 0 , V_47 = 0 , V_119 = 1 ;
T_7 V_51 = F_89 ( V_1 ) ;
if ( V_1 -> V_120 != V_113 )
goto V_121;
if ( ! F_90 ( V_1 ) )
goto V_121;
if ( F_65 ( V_1 ) )
goto V_122;
if ( V_1 -> V_110 != V_9 -> V_123 )
goto V_122;
if ( ! F_85 ( V_1 , ( * V_114 ) -> V_39 ) )
goto V_122;
V_115 = F_91 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode)) ;
V_117 = 1 << V_9 -> V_56 ;
V_116 = F_91 (unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE) ;
V_116 = V_116 ? F_92 ( V_116 , V_117 ) : V_124 ;
V_118 = V_116 / V_117 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( V_51 >= V_115 )
break;
if ( ! F_93 ( V_5 ) )
V_119 = 0 ;
if ( ! ( F_94 ( V_1 ) || F_93 ( V_5 ) ) ) {
V_47 = 1 ;
continue;
}
if ( F_3 ( V_5 ) || F_4 ( V_5 ) ||
F_58 ( V_5 ) ) {
if ( F_3 ( V_5 ) )
type = V_40 ;
else if ( F_4 ( V_5 ) )
type = V_71 ;
else
type = V_112 ;
if ( ! F_47 ( V_9 , V_53 , V_51 ) ) {
V_47 = 1 ;
continue;
}
F_95 ( V_5 ) ;
if ( type != V_112 )
F_82 ( V_9 , V_5 , V_53 , V_51 ) ;
F_77 ( V_9 , V_5 , V_51 , type ,
V_114 , V_47 ) ;
V_118 -- ;
V_55 ++ ;
} else {
V_47 = 1 ;
}
} while ( V_51 += V_117 , ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_119 && V_5 == V_6 )
F_96 ( V_1 ) ;
if ( V_55 ) {
if ( -- V_84 -> V_125 <= 0 &&
V_84 -> V_85 == V_126 )
V_47 = 1 ;
}
F_63 ( V_1 , ! V_118 , V_55 ) ;
return V_47 ;
V_122:
F_68 ( V_1 ) ;
V_121:
return 1 ;
}
STATIC void
F_97 (
struct V_9 * V_9 ,
T_10 V_113 ,
struct V_52 * V_53 ,
T_1 * * V_114 ,
struct V_83 * V_84 ,
T_10 V_127 )
{
struct V_128 V_129 ;
int V_47 = 0 , V_130 ;
F_98 ( & V_129 , 0 ) ;
while ( ! V_47 && V_113 <= V_127 ) {
unsigned V_117 = F_91 ( T_10 , V_131 , V_127 - V_113 + 1 ) ;
if ( ! F_99 ( & V_129 , V_9 -> V_123 , V_113 , V_117 ) )
break;
for ( V_130 = 0 ; V_130 < F_100 ( & V_129 ) ; V_130 ++ ) {
V_47 = F_88 ( V_9 , V_129 . V_132 [ V_130 ] , V_113 ++ ,
V_53 , V_114 , V_84 ) ;
if ( V_47 )
break;
}
F_101 ( & V_129 ) ;
F_102 () ;
}
}
STATIC void
F_103 (
struct V_1 * V_1 ,
unsigned long V_51 )
{
F_104 ( V_1 -> V_110 -> V_133 , V_1 , V_51 ) ;
F_105 ( V_1 , V_51 ) ;
}
STATIC void
F_106 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_110 -> V_133 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_4 V_51 = F_89 ( V_1 ) ;
if ( ! F_85 ( V_1 , V_71 ) )
goto V_134;
if ( F_27 ( V_11 -> V_14 ) )
goto V_134;
F_107 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_135 , V_51 ) ;
F_38 ( V_11 , V_36 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_6 V_136 ;
if ( ! F_4 ( V_5 ) )
goto V_137;
V_136 = F_40 ( V_11 -> V_14 , V_51 ) ;
error = F_108 ( V_11 , V_136 , 1 ) ;
if ( error ) {
if ( ! F_27 ( V_11 -> V_14 ) ) {
F_107 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_137:
V_51 += 1 << V_9 -> V_56 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_21 ( V_11 , V_36 ) ;
V_134:
F_103 ( V_1 , 0 ) ;
return;
}
STATIC int
F_109 (
struct V_1 * V_1 ,
struct V_83 * V_84 )
{
struct V_9 * V_9 = V_1 -> V_110 -> V_133 ;
struct V_4 * V_5 , * V_6 ;
struct V_52 V_53 ;
T_1 * V_18 = NULL , * V_138 = NULL ;
T_4 V_51 ;
unsigned int type ;
T_11 V_115 ;
T_10 V_139 , V_140 ;
T_5 V_117 ;
int V_141 , V_142 = 0 , V_119 = 1 ;
int V_55 = 0 ;
int V_54 = 0 ;
F_110 ( V_9 , V_1 , 0 ) ;
ASSERT ( F_86 ( V_1 ) ) ;
if ( F_111 ( ( V_143 -> V_144 & ( V_145 | V_146 ) ) ==
V_145 ) )
goto V_147;
if ( F_112 ( V_143 -> V_144 & V_148 ) )
goto V_147;
V_51 = F_14 ( V_9 ) ;
V_139 = V_51 >> V_149 ;
V_140 = ( V_51 - 1 ) >> V_149 ;
if ( V_1 -> V_120 >= V_139 ) {
if ( ( V_1 -> V_120 >= V_139 + 1 ) ||
! ( F_14 ( V_9 ) & ( V_124 - 1 ) ) ) {
F_68 ( V_1 ) ;
return 0 ;
}
}
V_115 = F_91 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
offset) ;
V_117 = 1 << V_9 -> V_56 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_51 = F_89 ( V_1 ) ;
type = V_112 ;
if ( V_84 -> V_85 == V_126 )
V_54 = 1 ;
do {
int V_150 = 0 ;
if ( V_51 >= V_115 )
break;
if ( ! F_93 ( V_5 ) )
V_119 = 0 ;
if ( ! F_58 ( V_5 ) && F_93 ( V_5 ) ) {
V_142 = 0 ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( type != V_40 ) {
type = V_40 ;
V_142 = 0 ;
}
} else if ( F_4 ( V_5 ) ) {
if ( type != V_71 ) {
type = V_71 ;
V_142 = 0 ;
}
} else if ( F_93 ( V_5 ) ) {
if ( type != V_112 ) {
type = V_112 ;
V_142 = 0 ;
}
} else {
if ( F_94 ( V_1 ) ) {
ASSERT ( F_58 ( V_5 ) ) ;
V_142 = 0 ;
}
continue;
}
if ( V_142 )
V_142 = F_47 ( V_9 , & V_53 , V_51 ) ;
if ( ! V_142 ) {
V_150 = 1 ;
V_141 = F_36 ( V_9 , V_51 , & V_53 , type ,
V_54 ) ;
if ( V_141 )
goto error;
V_142 = F_47 ( V_9 , & V_53 , V_51 ) ;
}
if ( V_142 ) {
F_95 ( V_5 ) ;
if ( type != V_112 )
F_82 ( V_9 , V_5 , & V_53 , V_51 ) ;
F_77 ( V_9 , V_5 , V_51 , type , & V_18 ,
V_150 ) ;
V_55 ++ ;
}
if ( ! V_138 )
V_138 = V_18 ;
} while ( V_51 += V_117 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_119 && V_5 == V_6 )
F_96 ( V_1 ) ;
F_63 ( V_1 , 1 , V_55 ) ;
if ( V_18 && V_142 ) {
T_7 V_139 ;
V_139 = V_53 . V_75 + V_53 . V_76 ;
V_139 <<= V_9 -> V_56 ;
V_139 = ( V_139 - 1 ) >> V_149 ;
if ( V_139 > V_140 )
V_139 = V_140 ;
F_97 ( V_9 , V_1 -> V_120 + 1 , & V_53 , & V_18 ,
V_84 , V_139 ) ;
}
if ( V_138 )
F_73 ( V_84 , V_138 ) ;
return 0 ;
error:
if ( V_138 )
F_74 ( V_138 ) ;
if ( V_141 == - V_37 )
goto V_147;
F_106 ( V_1 ) ;
F_113 ( V_1 ) ;
F_68 ( V_1 ) ;
return V_141 ;
V_147:
F_114 ( V_84 , V_1 ) ;
F_68 ( V_1 ) ;
return 0 ;
}
STATIC int
F_115 (
struct V_151 * V_110 ,
struct V_83 * V_84 )
{
F_116 ( F_6 ( V_110 -> V_133 ) , V_152 ) ;
return F_117 ( V_110 , V_84 ) ;
}
STATIC int
F_118 (
struct V_1 * V_1 ,
T_12 V_153 )
{
int V_2 , V_3 ;
F_119 ( V_1 -> V_110 -> V_133 , V_1 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_112 ( V_2 ) )
return 0 ;
if ( F_112 ( V_3 ) )
return 0 ;
return F_120 ( V_1 ) ;
}
STATIC int
F_121 (
struct V_9 * V_9 ,
T_8 V_154 ,
struct V_4 * V_155 ,
int V_156 ,
int V_157 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_57 , V_58 ;
int error = 0 ;
int V_158 = 0 ;
struct V_52 V_53 ;
int V_61 = 1 ;
T_7 V_51 ;
T_5 V_159 ;
int V_160 = 0 ;
if ( F_27 ( V_13 ) )
return - F_37 ( V_46 ) ;
V_51 = ( T_7 ) V_154 << V_9 -> V_56 ;
ASSERT ( V_155 -> V_94 >= ( 1 << V_9 -> V_56 ) ) ;
V_159 = V_155 -> V_94 ;
if ( ! V_156 && V_157 && V_51 >= F_14 ( V_9 ) )
return 0 ;
if ( V_156 ) {
V_158 = V_36 ;
F_38 ( V_11 , V_158 ) ;
} else {
V_158 = F_122 ( V_11 ) ;
}
ASSERT ( V_51 <= V_13 -> V_69 ) ;
if ( V_51 + V_159 > V_13 -> V_69 )
V_159 = V_13 -> V_69 - V_51 ;
V_58 = F_39 ( V_13 , ( V_70 ) V_51 + V_159 ) ;
V_57 = F_40 ( V_13 , V_51 ) ;
error = F_41 ( V_11 , V_57 , V_58 - V_57 ,
& V_53 , & V_61 , V_60 ) ;
if ( error )
goto V_161;
if ( V_156 &&
( ! V_61 ||
( V_53 . V_72 == V_73 ||
V_53 . V_72 == V_74 ) ) ) {
if ( V_157 ) {
error = F_123 ( V_11 , V_51 , V_159 ,
& V_53 , V_61 ) ;
} else {
error = F_124 ( V_11 , V_51 , V_159 , & V_53 ) ;
}
if ( error )
goto V_161;
F_125 ( V_11 , V_51 , V_159 , 0 , & V_53 ) ;
} else if ( V_61 ) {
F_126 ( V_11 , V_51 , V_159 , 0 , & V_53 ) ;
} else {
F_127 ( V_11 , V_51 , V_159 ) ;
goto V_161;
}
F_21 ( V_11 , V_158 ) ;
if ( V_53 . V_72 != V_73 &&
V_53 . V_72 != V_74 ) {
if ( V_156 || ! F_128 ( & V_53 ) )
F_78 ( V_9 , V_155 , & V_53 , V_51 ) ;
if ( V_156 && F_128 ( & V_53 ) ) {
if ( V_157 )
V_155 -> V_21 = V_9 ;
F_129 ( V_155 ) ;
}
}
V_155 -> V_90 = F_5 ( V_9 ) ;
if ( V_156 &&
( ( ! F_58 ( V_155 ) && ! F_93 ( V_155 ) ) ||
( V_51 >= F_14 ( V_9 ) ) ||
( V_160 || F_128 ( & V_53 ) ) ) )
F_130 ( V_155 ) ;
if ( V_53 . V_72 == V_74 ) {
F_131 ( V_157 ) ;
if ( V_156 ) {
F_61 ( V_155 ) ;
F_81 ( V_155 ) ;
F_132 ( V_155 ) ;
}
}
if ( V_157 || V_159 > ( 1 << V_9 -> V_56 ) ) {
T_7 V_162 ;
V_162 = V_53 . V_75 + V_53 . V_76 - V_154 ;
V_162 <<= V_9 -> V_56 ;
ASSERT ( V_162 > 0 ) ;
if ( V_162 > V_159 )
V_162 = V_159 ;
if ( V_162 > V_163 )
V_162 = V_163 ;
V_155 -> V_94 = V_162 ;
}
return 0 ;
V_161:
F_21 ( V_11 , V_158 ) ;
return - error ;
}
int
F_133 (
struct V_9 * V_9 ,
T_8 V_154 ,
struct V_4 * V_155 ,
int V_156 )
{
return F_121 ( V_9 , V_154 , V_155 , V_156 , 0 ) ;
}
STATIC int
F_134 (
struct V_9 * V_9 ,
T_8 V_154 ,
struct V_4 * V_155 ,
int V_156 )
{
return F_121 ( V_9 , V_154 , V_155 , V_156 , 1 ) ;
}
STATIC void
F_135 (
struct V_164 * V_165 ,
T_4 V_51 ,
T_5 V_159 ,
void * V_166 ,
int V_167 ,
bool V_168 )
{
struct V_35 * V_18 = V_165 -> V_166 ;
if ( V_51 + V_159 > F_14 ( V_18 -> V_27 ) )
F_136 ( V_18 -> V_27 , V_51 + V_159 ) ;
V_165 -> V_166 = NULL ;
V_18 -> V_31 = V_51 ;
V_18 -> V_32 = V_159 ;
V_18 -> V_24 = V_165 ;
V_18 -> V_26 = V_167 ;
if ( V_166 && V_159 > 0 )
V_18 -> V_39 = V_40 ;
if ( V_168 ) {
V_18 -> V_25 = 1 ;
F_22 ( V_18 ) ;
} else {
F_31 ( V_18 ) ;
}
}
STATIC T_5
F_137 (
int V_169 ,
struct V_164 * V_165 ,
const struct V_170 * V_171 ,
T_4 V_51 ,
unsigned long V_172 )
{
struct V_9 * V_9 = V_165 -> V_173 -> V_174 -> V_133 ;
struct V_8 * V_175 = F_5 ( V_9 ) ;
T_5 V_167 ;
if ( V_169 & V_88 ) {
V_165 -> V_166 = F_32 ( V_9 , V_176 ) ;
V_167 = F_138 ( V_169 , V_165 , V_9 , V_175 , V_171 ,
V_51 , V_172 ,
F_134 ,
F_135 , NULL , 0 ) ;
if ( V_167 != - V_177 && V_165 -> V_166 )
F_8 ( V_165 -> V_166 ) ;
} else {
V_167 = F_138 ( V_169 , V_165 , V_9 , V_175 , V_171 ,
V_51 , V_172 ,
F_134 ,
NULL , NULL , 0 ) ;
}
return V_167 ;
}
STATIC void
F_139 (
struct V_151 * V_110 ,
T_4 V_178 )
{
struct V_9 * V_9 = V_110 -> V_133 ;
if ( V_178 > V_9 -> V_179 ) {
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_6 V_136 ;
T_6 V_58 ;
int error ;
F_140 ( V_9 , V_178 , V_9 -> V_179 ) ;
V_136 = F_39 ( V_11 -> V_14 , V_9 -> V_179 ) + 1 ;
V_58 = F_39 ( V_11 -> V_14 , V_178 ) ;
if ( V_58 <= V_136 )
return;
F_38 ( V_11 , V_36 ) ;
error = F_108 ( V_11 , V_136 ,
V_58 - V_136 ) ;
if ( error ) {
if ( ! F_27 ( V_11 -> V_14 ) ) {
F_107 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_135 ) ;
}
}
F_21 ( V_11 , V_36 ) ;
}
}
STATIC int
F_141 (
struct V_180 * V_180 ,
struct V_151 * V_110 ,
T_4 V_181 ,
unsigned V_117 ,
unsigned V_144 ,
struct V_1 * * V_182 ,
void * * V_183 )
{
int V_167 ;
V_167 = F_142 ( V_110 , V_181 , V_117 , V_144 | V_184 ,
V_182 , F_133 ) ;
if ( F_143 ( V_167 ) )
F_139 ( V_110 , V_181 + V_117 ) ;
return V_167 ;
}
STATIC int
F_144 (
struct V_180 * V_180 ,
struct V_151 * V_110 ,
T_4 V_181 ,
unsigned V_117 ,
unsigned V_185 ,
struct V_1 * V_1 ,
void * V_183 )
{
int V_167 ;
V_167 = F_145 ( V_180 , V_110 , V_181 , V_117 , V_185 , V_1 , V_183 ) ;
if ( F_143 ( V_167 < V_117 ) )
F_139 ( V_110 , V_181 + V_117 ) ;
return V_167 ;
}
STATIC T_8
F_146 (
struct V_151 * V_110 ,
T_8 V_186 )
{
struct V_9 * V_9 = (struct V_9 * ) V_110 -> V_133 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_147 ( F_6 ( V_9 ) ) ;
F_38 ( V_11 , V_187 ) ;
F_148 ( V_11 , ( T_7 ) 0 , - 1 , 0 , V_188 ) ;
F_21 ( V_11 , V_187 ) ;
return F_149 ( V_110 , V_186 , F_133 ) ;
}
STATIC int
F_150 (
struct V_180 * V_189 ,
struct V_1 * V_1 )
{
return F_151 ( V_1 , F_133 ) ;
}
STATIC int
F_152 (
struct V_180 * V_189 ,
struct V_151 * V_110 ,
struct V_190 * V_132 ,
unsigned V_191 )
{
return F_153 ( V_110 , V_132 , V_191 , F_133 ) ;
}
