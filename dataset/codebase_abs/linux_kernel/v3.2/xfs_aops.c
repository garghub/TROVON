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
V_29 = F_13 ( V_11 -> V_33 , V_11 -> V_34 ) ;
V_29 = F_14 ( V_29 , V_30 ) ;
return V_29 > V_11 -> V_35 . V_36 ? V_29 : 0 ;
}
static inline bool F_15 ( struct V_37 * V_18 )
{
return V_18 -> V_31 + V_18 -> V_32 >
F_6 ( V_18 -> V_27 ) -> V_35 . V_36 ;
}
STATIC int
F_16 (
T_1 * V_18 )
{
T_3 * V_11 = F_6 ( V_18 -> V_27 ) ;
T_2 V_29 ;
if ( ! F_17 ( V_11 , V_38 ) )
return V_39 ;
V_29 = F_12 ( V_18 ) ;
if ( V_29 ) {
F_18 ( V_11 , V_18 -> V_31 , V_18 -> V_32 ) ;
V_11 -> V_35 . V_36 = V_29 ;
F_19 ( V_11 ) ;
}
F_20 ( V_11 , V_38 ) ;
return 0 ;
}
STATIC void
F_21 (
struct V_37 * V_18 )
{
if ( F_22 ( & V_18 -> V_40 ) ) {
if ( V_18 -> V_41 == V_42 )
F_23 ( V_43 , & V_18 -> V_44 ) ;
else if ( F_15 ( V_18 ) )
F_23 ( V_45 , & V_18 -> V_44 ) ;
else
F_8 ( V_18 ) ;
}
}
STATIC void
F_24 (
struct V_46 * V_47 )
{
T_1 * V_18 = F_25 ( V_47 , T_1 , V_44 ) ;
struct V_10 * V_11 = F_6 ( V_18 -> V_27 ) ;
int error = 0 ;
if ( F_26 ( V_11 -> V_14 ) ) {
V_18 -> V_23 = - V_48 ;
goto V_49;
}
if ( V_18 -> V_23 )
goto V_49;
if ( V_18 -> V_41 == V_42 ) {
error = F_27 ( V_11 , V_18 -> V_31 ,
V_18 -> V_32 ) ;
if ( error ) {
V_18 -> V_23 = - error ;
goto V_49;
}
}
error = F_16 ( V_18 ) ;
ASSERT ( ! error || error == V_39 ) ;
V_49:
if ( error == V_39 ) {
F_28 ( & V_18 -> V_40 ) ;
F_21 ( V_18 ) ;
F_29 ( 1 ) ;
} else {
F_8 ( V_18 ) ;
}
}
STATIC void
F_30 (
struct V_37 * V_18 )
{
if ( F_22 ( & V_18 -> V_40 ) )
F_24 ( & V_18 -> V_44 ) ;
}
STATIC T_1 *
F_31 (
struct V_9 * V_9 ,
unsigned int type )
{
T_1 * V_18 ;
V_18 = F_32 ( V_28 , V_50 ) ;
F_33 ( & V_18 -> V_40 , 1 ) ;
V_18 -> V_25 = 0 ;
V_18 -> V_23 = 0 ;
V_18 -> V_51 = NULL ;
V_18 -> V_41 = type ;
V_18 -> V_27 = V_9 ;
V_18 -> V_20 = NULL ;
V_18 -> V_52 = NULL ;
V_18 -> V_31 = 0 ;
V_18 -> V_32 = 0 ;
V_18 -> V_24 = NULL ;
V_18 -> V_26 = 0 ;
F_34 ( & V_18 -> V_44 , F_24 ) ;
return V_18 ;
}
STATIC int
F_35 (
struct V_9 * V_9 ,
T_4 V_53 ,
struct V_54 * V_55 ,
int type ,
int V_56 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_5 V_57 = 1 << V_9 -> V_58 ;
T_6 V_59 , V_60 ;
int error = 0 ;
int V_61 = V_62 ;
int V_63 = 1 ;
if ( F_26 ( V_13 ) )
return - F_36 ( V_48 ) ;
if ( type == V_42 )
V_61 |= V_64 ;
if ( ! F_17 ( V_11 , V_65 ) ) {
if ( V_56 )
return - F_36 ( V_39 ) ;
F_37 ( V_11 , V_65 ) ;
}
ASSERT ( V_11 -> V_35 . V_66 != V_67 ||
( V_11 -> V_68 . V_69 & V_70 ) ) ;
ASSERT ( V_53 <= V_13 -> V_71 ) ;
if ( V_53 + V_57 > V_13 -> V_71 )
V_57 = V_13 -> V_71 - V_53 ;
V_60 = F_38 ( V_13 , ( V_72 ) V_53 + V_57 ) ;
V_59 = F_39 ( V_13 , V_53 ) ;
error = F_40 ( V_11 , V_59 , V_60 - V_59 ,
V_55 , & V_63 , V_61 ) ;
F_20 ( V_11 , V_65 ) ;
if ( error )
return - F_36 ( error ) ;
if ( type == V_73 &&
( ! V_63 || F_41 ( V_55 -> V_74 ) ) ) {
error = F_42 ( V_11 , V_53 , V_57 , V_55 ) ;
if ( ! error )
F_43 ( V_11 , V_53 , V_57 , type , V_55 ) ;
return - F_36 ( error ) ;
}
#ifdef F_44
if ( type == V_42 ) {
ASSERT ( V_63 ) ;
ASSERT ( V_55 -> V_74 != V_75 ) ;
ASSERT ( V_55 -> V_74 != V_76 ) ;
}
#endif
if ( V_63 )
F_45 ( V_11 , V_53 , V_57 , type , V_55 ) ;
return 0 ;
}
STATIC int
F_46 (
struct V_9 * V_9 ,
struct V_54 * V_55 ,
T_7 V_53 )
{
V_53 >>= V_9 -> V_58 ;
return V_53 >= V_55 -> V_77 &&
V_53 < V_55 -> V_77 + V_55 -> V_78 ;
}
STATIC void
F_47 (
struct V_79 * V_79 ,
int error )
{
T_1 * V_18 = V_79 -> V_80 ;
ASSERT ( F_48 ( & V_79 -> V_81 ) >= 1 ) ;
V_18 -> V_23 = F_49 ( V_82 , & V_79 -> V_83 ) ? 0 : error ;
V_79 -> V_80 = NULL ;
V_79 -> V_84 = NULL ;
F_50 ( V_79 ) ;
F_21 ( V_18 ) ;
}
STATIC void
F_51 (
struct V_85 * V_86 ,
T_1 * V_18 ,
struct V_79 * V_79 )
{
F_28 ( & V_18 -> V_40 ) ;
V_79 -> V_80 = V_18 ;
V_79 -> V_84 = F_47 ;
if ( F_12 ( V_18 ) )
F_19 ( F_6 ( V_18 -> V_27 ) ) ;
F_52 ( V_86 -> V_87 == V_88 ? V_89 : V_90 , V_79 ) ;
}
STATIC struct V_79 *
F_53 (
struct V_4 * V_5 )
{
int V_91 = F_54 ( V_5 -> V_92 ) ;
struct V_79 * V_79 = F_55 ( V_93 , V_91 ) ;
ASSERT ( V_79 -> V_80 == NULL ) ;
V_79 -> V_94 = V_5 -> V_95 * ( V_5 -> V_96 >> 9 ) ;
V_79 -> V_97 = V_5 -> V_92 ;
return V_79 ;
}
STATIC void
F_56 (
struct V_4 * V_5 )
{
ASSERT ( F_57 ( V_5 ) ) ;
ASSERT ( F_58 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
F_59 ( V_5 ) ;
F_60 ( V_5 ) ;
F_61 ( V_5 ) ;
}
STATIC void
F_62 (
struct V_1 * V_1 ,
int V_98 ,
int V_99 )
{
ASSERT ( F_63 ( V_1 ) ) ;
ASSERT ( ! F_64 ( V_1 ) ) ;
if ( V_98 )
F_65 ( V_1 ) ;
F_66 ( V_1 ) ;
F_67 ( V_1 ) ;
if ( ! V_99 )
F_68 ( V_1 ) ;
}
static inline int F_69 ( struct V_79 * V_79 , struct V_4 * V_5 )
{
return F_70 ( V_79 , V_5 -> V_100 , V_5 -> V_96 , F_71 ( V_5 ) ) ;
}
STATIC void
F_72 (
struct V_85 * V_86 ,
T_1 * V_18 )
{
T_1 * V_6 = V_18 ;
T_1 * V_19 ;
struct V_4 * V_5 ;
struct V_79 * V_79 ;
T_8 V_101 = 0 ;
do {
V_19 = V_18 -> V_51 ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 )
F_56 ( V_5 ) ;
} while ( ( V_18 = V_19 ) != NULL );
V_18 = V_6 ;
do {
V_19 = V_18 -> V_51 ;
V_79 = NULL ;
for ( V_5 = V_18 -> V_20 ; V_5 ; V_5 = V_5 -> V_21 ) {
if ( ! V_79 ) {
V_102:
V_79 = F_53 ( V_5 ) ;
} else if ( V_5 -> V_95 != V_101 + 1 ) {
F_51 ( V_86 , V_18 , V_79 ) ;
goto V_102;
}
if ( F_69 ( V_79 , V_5 ) != V_5 -> V_96 ) {
F_51 ( V_86 , V_18 , V_79 ) ;
goto V_102;
}
V_101 = V_5 -> V_95 ;
}
if ( V_79 )
F_51 ( V_86 , V_18 , V_79 ) ;
F_21 ( V_18 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_73 (
T_1 * V_18 )
{
T_1 * V_19 ;
struct V_4 * V_5 , * V_103 ;
do {
V_19 = V_18 -> V_51 ;
V_5 = V_18 -> V_20 ;
do {
V_103 = V_5 -> V_21 ;
F_74 ( V_5 ) ;
F_75 ( V_5 ) ;
} while ( ( V_5 = V_103 ) != NULL );
F_11 ( V_18 , V_28 ) ;
} while ( ( V_18 = V_19 ) != NULL );
}
STATIC void
F_76 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_7 V_53 ,
unsigned int type ,
T_1 * * V_104 ,
int V_105 )
{
T_1 * V_18 = * V_104 ;
if ( ! V_18 || V_105 || type != V_18 -> V_41 ) {
T_1 * V_106 = * V_104 ;
V_18 = F_31 ( V_9 , type ) ;
V_18 -> V_31 = V_53 ;
V_18 -> V_20 = V_5 ;
V_18 -> V_52 = V_5 ;
if ( V_106 )
V_106 -> V_51 = V_18 ;
* V_104 = V_18 ;
} else {
V_18 -> V_52 -> V_21 = V_5 ;
V_18 -> V_52 = V_5 ;
}
V_5 -> V_21 = NULL ;
V_18 -> V_32 += V_5 -> V_96 ;
}
STATIC void
F_77 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_54 * V_55 ,
T_7 V_53 )
{
T_8 V_107 ;
struct V_12 * V_108 = F_6 ( V_9 ) -> V_14 ;
T_7 V_109 = F_78 ( V_108 , V_55 -> V_77 ) ;
T_9 V_110 = F_79 ( F_6 ( V_9 ) , V_55 -> V_74 ) ;
ASSERT ( V_55 -> V_74 != V_75 ) ;
ASSERT ( V_55 -> V_74 != V_76 ) ;
V_107 = ( V_110 >> ( V_9 -> V_58 - V_111 ) ) +
( ( V_53 - V_109 ) >> V_9 -> V_58 ) ;
ASSERT ( V_107 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_95 = V_107 ;
F_80 ( V_5 ) ;
}
STATIC void
F_81 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_54 * V_55 ,
T_7 V_53 )
{
ASSERT ( V_55 -> V_74 != V_75 ) ;
ASSERT ( V_55 -> V_74 != V_76 ) ;
F_77 ( V_9 , V_5 , V_55 , V_53 ) ;
F_80 ( V_5 ) ;
F_82 ( V_5 ) ;
F_83 ( V_5 ) ;
}
STATIC int
F_84 (
struct V_1 * V_1 ,
unsigned int type )
{
if ( F_64 ( V_1 ) )
return 0 ;
if ( V_1 -> V_112 && F_85 ( V_1 ) ) {
struct V_4 * V_5 , * V_6 ;
int V_113 = 0 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) )
V_113 = ( type == V_42 ) ;
else if ( F_4 ( V_5 ) )
V_113 = ( type == V_73 ) ;
else if ( F_86 ( V_5 ) && F_57 ( V_5 ) )
V_113 = ( type == V_114 ) ;
else
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_113 )
return 1 ;
}
return 0 ;
}
STATIC int
F_87 (
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_4 V_115 ,
struct V_54 * V_55 ,
T_1 * * V_116 ,
struct V_85 * V_86 )
{
struct V_4 * V_5 , * V_6 ;
T_7 V_117 ;
unsigned long V_118 ;
unsigned int type ;
int V_119 , V_120 ;
int V_57 = 0 , V_49 = 0 , V_121 = 1 ;
T_7 V_53 = F_88 ( V_1 ) ;
if ( V_1 -> V_122 != V_115 )
goto V_123;
if ( ! F_89 ( V_1 ) )
goto V_123;
if ( F_64 ( V_1 ) )
goto V_124;
if ( V_1 -> V_112 != V_9 -> V_125 )
goto V_124;
if ( ! F_84 ( V_1 , ( * V_116 ) -> V_41 ) )
goto V_124;
V_117 = F_90 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode)) ;
V_119 = 1 << V_9 -> V_58 ;
V_118 = F_90 (unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE) ;
V_118 = V_118 ? F_91 ( V_118 , V_119 ) : V_126 ;
V_120 = V_118 / V_119 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( V_53 >= V_117 )
break;
if ( ! F_92 ( V_5 ) )
V_121 = 0 ;
if ( ! ( F_93 ( V_1 ) || F_92 ( V_5 ) ) ) {
V_49 = 1 ;
continue;
}
if ( F_3 ( V_5 ) || F_4 ( V_5 ) ||
F_57 ( V_5 ) ) {
if ( F_3 ( V_5 ) )
type = V_42 ;
else if ( F_4 ( V_5 ) )
type = V_73 ;
else
type = V_114 ;
if ( ! F_46 ( V_9 , V_55 , V_53 ) ) {
V_49 = 1 ;
continue;
}
F_94 ( V_5 ) ;
if ( type != V_114 )
F_81 ( V_9 , V_5 , V_55 , V_53 ) ;
F_76 ( V_9 , V_5 , V_53 , type ,
V_116 , V_49 ) ;
V_120 -- ;
V_57 ++ ;
} else {
V_49 = 1 ;
}
} while ( V_53 += V_119 , ( V_5 = V_5 -> V_7 ) != V_6 );
if ( V_121 && V_5 == V_6 )
F_95 ( V_1 ) ;
if ( V_57 ) {
if ( -- V_86 -> V_127 <= 0 &&
V_86 -> V_87 == V_128 )
V_49 = 1 ;
}
F_62 ( V_1 , ! V_120 , V_57 ) ;
return V_49 ;
V_124:
F_67 ( V_1 ) ;
V_123:
return 1 ;
}
STATIC void
F_96 (
struct V_9 * V_9 ,
T_10 V_115 ,
struct V_54 * V_55 ,
T_1 * * V_116 ,
struct V_85 * V_86 ,
T_10 V_129 )
{
struct V_130 V_131 ;
int V_49 = 0 , V_132 ;
F_97 ( & V_131 , 0 ) ;
while ( ! V_49 && V_115 <= V_129 ) {
unsigned V_119 = F_90 ( T_10 , V_133 , V_129 - V_115 + 1 ) ;
if ( ! F_98 ( & V_131 , V_9 -> V_125 , V_115 , V_119 ) )
break;
for ( V_132 = 0 ; V_132 < F_99 ( & V_131 ) ; V_132 ++ ) {
V_49 = F_87 ( V_9 , V_131 . V_134 [ V_132 ] , V_115 ++ ,
V_55 , V_116 , V_86 ) ;
if ( V_49 )
break;
}
F_100 ( & V_131 ) ;
F_101 () ;
}
}
STATIC void
F_102 (
struct V_1 * V_1 ,
unsigned long V_53 )
{
F_103 ( V_1 -> V_112 -> V_135 , V_1 , V_53 ) ;
F_104 ( V_1 , V_53 ) ;
}
STATIC void
F_105 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_112 -> V_135 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_4 V_53 = F_88 ( V_1 ) ;
if ( ! F_84 ( V_1 , V_73 ) )
goto V_136;
if ( F_26 ( V_11 -> V_14 ) )
goto V_136;
F_106 ( V_11 -> V_14 ,
L_1 ,
V_1 , V_11 -> V_137 , V_53 ) ;
F_37 ( V_11 , V_38 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_6 V_138 ;
if ( ! F_4 ( V_5 ) )
goto V_139;
V_138 = F_39 ( V_11 -> V_14 , V_53 ) ;
error = F_107 ( V_11 , V_138 , 1 ) ;
if ( error ) {
if ( ! F_26 ( V_11 -> V_14 ) ) {
F_106 ( V_11 -> V_14 ,
L_2 ) ;
}
break;
}
V_139:
V_53 += 1 << V_9 -> V_58 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_20 ( V_11 , V_38 ) ;
V_136:
F_102 ( V_1 , 0 ) ;
return;
}
STATIC int
F_108 (
struct V_1 * V_1 ,
struct V_85 * V_86 )
{
struct V_9 * V_9 = V_1 -> V_112 -> V_135 ;
struct V_4 * V_5 , * V_6 ;
struct V_54 V_55 ;
T_1 * V_18 = NULL , * V_140 = NULL ;
T_4 V_53 ;
unsigned int type ;
T_11 V_117 ;
T_10 V_141 , V_142 ;
T_5 V_119 ;
int V_143 , V_144 = 0 , V_121 = 1 ;
int V_57 = 0 ;
int V_56 = 0 ;
F_109 ( V_9 , V_1 , 0 ) ;
ASSERT ( F_85 ( V_1 ) ) ;
if ( F_110 ( ( V_145 -> V_146 & ( V_147 | V_148 ) ) ==
V_147 ) )
goto V_149;
if ( F_111 ( V_145 -> V_146 & V_150 ) )
goto V_149;
V_53 = F_112 ( V_9 ) ;
V_141 = V_53 >> V_151 ;
V_142 = ( V_53 - 1 ) >> V_151 ;
if ( V_1 -> V_122 >= V_141 ) {
if ( ( V_1 -> V_122 >= V_141 + 1 ) ||
! ( F_112 ( V_9 ) & ( V_126 - 1 ) ) ) {
F_67 ( V_1 ) ;
return 0 ;
}
}
V_117 = F_90 (unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
offset) ;
V_119 = 1 << V_9 -> V_58 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_53 = F_88 ( V_1 ) ;
type = V_114 ;
if ( V_86 -> V_87 == V_128 )
V_56 = 1 ;
do {
int V_152 = 0 ;
if ( V_53 >= V_117 )
break;
if ( ! F_92 ( V_5 ) )
V_121 = 0 ;
if ( ! F_57 ( V_5 ) && F_92 ( V_5 ) ) {
V_144 = 0 ;
continue;
}
if ( F_3 ( V_5 ) ) {
if ( type != V_42 ) {
type = V_42 ;
V_144 = 0 ;
}
} else if ( F_4 ( V_5 ) ) {
if ( type != V_73 ) {
type = V_73 ;
V_144 = 0 ;
}
} else if ( F_92 ( V_5 ) ) {
if ( type != V_114 ) {
type = V_114 ;
V_144 = 0 ;
}
} else {
if ( F_93 ( V_1 ) ) {
ASSERT ( F_57 ( V_5 ) ) ;
V_144 = 0 ;
}
continue;
}
if ( V_144 )
V_144 = F_46 ( V_9 , & V_55 , V_53 ) ;
if ( ! V_144 ) {
V_152 = 1 ;
V_143 = F_35 ( V_9 , V_53 , & V_55 , type ,
V_56 ) ;
if ( V_143 )
goto error;
V_144 = F_46 ( V_9 , & V_55 , V_53 ) ;
}
if ( V_144 ) {
F_94 ( V_5 ) ;
if ( type != V_114 )
F_81 ( V_9 , V_5 , & V_55 , V_53 ) ;
F_76 ( V_9 , V_5 , V_53 , type , & V_18 ,
V_152 ) ;
V_57 ++ ;
}
if ( ! V_140 )
V_140 = V_18 ;
} while ( V_53 += V_119 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_121 && V_5 == V_6 )
F_95 ( V_1 ) ;
F_62 ( V_1 , 1 , V_57 ) ;
if ( V_18 && V_144 ) {
T_7 V_141 ;
V_141 = V_55 . V_77 + V_55 . V_78 ;
V_141 <<= V_9 -> V_58 ;
V_141 = ( V_141 - 1 ) >> V_151 ;
if ( V_141 > V_142 )
V_141 = V_142 ;
F_96 ( V_9 , V_1 -> V_122 + 1 , & V_55 , & V_18 ,
V_86 , V_141 ) ;
}
if ( V_140 )
F_72 ( V_86 , V_140 ) ;
return 0 ;
error:
if ( V_140 )
F_73 ( V_140 ) ;
if ( V_143 == - V_39 )
goto V_149;
F_105 ( V_1 ) ;
F_113 ( V_1 ) ;
F_67 ( V_1 ) ;
return V_143 ;
V_149:
F_114 ( V_86 , V_1 ) ;
F_67 ( V_1 ) ;
return 0 ;
}
STATIC int
F_115 (
struct V_153 * V_112 ,
struct V_85 * V_86 )
{
F_116 ( F_6 ( V_112 -> V_135 ) , V_154 ) ;
return F_117 ( V_112 , V_86 ) ;
}
STATIC int
F_118 (
struct V_1 * V_1 ,
T_12 V_155 )
{
int V_2 , V_3 ;
F_119 ( V_1 -> V_112 -> V_135 , V_1 , 0 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_111 ( V_2 ) )
return 0 ;
if ( F_111 ( V_3 ) )
return 0 ;
return F_120 ( V_1 ) ;
}
STATIC int
F_121 (
struct V_9 * V_9 ,
T_8 V_156 ,
struct V_4 * V_157 ,
int V_158 ,
int V_159 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_59 , V_60 ;
int error = 0 ;
int V_160 = 0 ;
struct V_54 V_55 ;
int V_63 = 1 ;
T_7 V_53 ;
T_5 V_161 ;
int V_162 = 0 ;
if ( F_26 ( V_13 ) )
return - F_36 ( V_48 ) ;
V_53 = ( T_7 ) V_156 << V_9 -> V_58 ;
ASSERT ( V_157 -> V_96 >= ( 1 << V_9 -> V_58 ) ) ;
V_161 = V_157 -> V_96 ;
if ( ! V_158 && V_159 && V_53 >= F_112 ( V_9 ) )
return 0 ;
if ( V_158 ) {
V_160 = V_38 ;
F_37 ( V_11 , V_160 ) ;
} else {
V_160 = F_122 ( V_11 ) ;
}
ASSERT ( V_53 <= V_13 -> V_71 ) ;
if ( V_53 + V_161 > V_13 -> V_71 )
V_161 = V_13 -> V_71 - V_53 ;
V_60 = F_38 ( V_13 , ( V_72 ) V_53 + V_161 ) ;
V_59 = F_39 ( V_13 , V_53 ) ;
error = F_40 ( V_11 , V_59 , V_60 - V_59 ,
& V_55 , & V_63 , V_62 ) ;
if ( error )
goto V_163;
if ( V_158 &&
( ! V_63 ||
( V_55 . V_74 == V_75 ||
V_55 . V_74 == V_76 ) ) ) {
if ( V_159 ) {
error = F_123 ( V_11 , V_53 , V_161 ,
& V_55 , V_63 ) ;
} else {
error = F_124 ( V_11 , V_53 , V_161 , & V_55 ) ;
}
if ( error )
goto V_163;
F_125 ( V_11 , V_53 , V_161 , 0 , & V_55 ) ;
} else if ( V_63 ) {
F_126 ( V_11 , V_53 , V_161 , 0 , & V_55 ) ;
} else {
F_127 ( V_11 , V_53 , V_161 ) ;
goto V_163;
}
F_20 ( V_11 , V_160 ) ;
if ( V_55 . V_74 != V_75 &&
V_55 . V_74 != V_76 ) {
if ( V_158 || ! F_128 ( & V_55 ) )
F_77 ( V_9 , V_157 , & V_55 , V_53 ) ;
if ( V_158 && F_128 ( & V_55 ) ) {
if ( V_159 )
V_157 -> V_21 = V_9 ;
F_129 ( V_157 ) ;
}
}
V_157 -> V_92 = F_5 ( V_9 ) ;
if ( V_158 &&
( ( ! F_57 ( V_157 ) && ! F_92 ( V_157 ) ) ||
( V_53 >= F_112 ( V_9 ) ) ||
( V_162 || F_128 ( & V_55 ) ) ) )
F_130 ( V_157 ) ;
if ( V_55 . V_74 == V_76 ) {
F_131 ( V_159 ) ;
if ( V_158 ) {
F_60 ( V_157 ) ;
F_80 ( V_157 ) ;
F_132 ( V_157 ) ;
}
}
if ( V_159 || V_161 > ( 1 << V_9 -> V_58 ) ) {
T_7 V_164 ;
V_164 = V_55 . V_77 + V_55 . V_78 - V_156 ;
V_164 <<= V_9 -> V_58 ;
ASSERT ( V_164 > 0 ) ;
if ( V_164 > V_161 )
V_164 = V_161 ;
if ( V_164 > V_165 )
V_164 = V_165 ;
V_157 -> V_96 = V_164 ;
}
return 0 ;
V_163:
F_20 ( V_11 , V_160 ) ;
return - error ;
}
int
F_133 (
struct V_9 * V_9 ,
T_8 V_156 ,
struct V_4 * V_157 ,
int V_158 )
{
return F_121 ( V_9 , V_156 , V_157 , V_158 , 0 ) ;
}
STATIC int
F_134 (
struct V_9 * V_9 ,
T_8 V_156 ,
struct V_4 * V_157 ,
int V_158 )
{
return F_121 ( V_9 , V_156 , V_157 , V_158 , 1 ) ;
}
STATIC void
F_135 (
struct V_166 * V_167 ,
T_4 V_53 ,
T_5 V_161 ,
void * V_168 ,
int V_169 ,
bool V_170 )
{
struct V_37 * V_18 = V_167 -> V_168 ;
V_167 -> V_168 = NULL ;
V_18 -> V_31 = V_53 ;
V_18 -> V_32 = V_161 ;
V_18 -> V_24 = V_167 ;
V_18 -> V_26 = V_169 ;
if ( V_168 && V_161 > 0 )
V_18 -> V_41 = V_42 ;
if ( V_170 ) {
V_18 -> V_25 = 1 ;
F_21 ( V_18 ) ;
} else {
F_30 ( V_18 ) ;
}
}
STATIC T_5
F_136 (
int V_171 ,
struct V_166 * V_167 ,
const struct V_172 * V_173 ,
T_4 V_53 ,
unsigned long V_174 )
{
struct V_9 * V_9 = V_167 -> V_175 -> V_176 -> V_135 ;
struct V_8 * V_177 = F_5 ( V_9 ) ;
T_5 V_169 ;
if ( V_171 & V_90 ) {
V_167 -> V_168 = F_31 ( V_9 , V_178 ) ;
V_169 = F_137 ( V_171 , V_167 , V_9 , V_177 , V_173 ,
V_53 , V_174 ,
F_134 ,
F_135 , NULL , 0 ) ;
if ( V_169 != - V_179 && V_167 -> V_168 )
F_8 ( V_167 -> V_168 ) ;
} else {
V_169 = F_137 ( V_171 , V_167 , V_9 , V_177 , V_173 ,
V_53 , V_174 ,
F_134 ,
NULL , NULL , 0 ) ;
}
return V_169 ;
}
STATIC void
F_138 (
struct V_153 * V_112 ,
T_4 V_180 )
{
struct V_9 * V_9 = V_112 -> V_135 ;
if ( V_180 > V_9 -> V_33 ) {
struct V_10 * V_11 = F_6 ( V_9 ) ;
T_6 V_138 ;
T_6 V_60 ;
int error ;
F_139 ( V_9 , V_180 , V_9 -> V_33 ) ;
V_138 = F_38 ( V_11 -> V_14 , V_9 -> V_33 ) + 1 ;
V_60 = F_38 ( V_11 -> V_14 , V_180 ) ;
if ( V_60 <= V_138 )
return;
F_37 ( V_11 , V_38 ) ;
error = F_107 ( V_11 , V_138 ,
V_60 - V_138 ) ;
if ( error ) {
if ( ! F_26 ( V_11 -> V_14 ) ) {
F_106 ( V_11 -> V_14 ,
L_3 ,
V_11 -> V_137 ) ;
}
}
F_20 ( V_11 , V_38 ) ;
}
}
STATIC int
F_140 (
struct V_181 * V_181 ,
struct V_153 * V_112 ,
T_4 V_182 ,
unsigned V_119 ,
unsigned V_146 ,
struct V_1 * * V_183 ,
void * * V_184 )
{
int V_169 ;
V_169 = F_141 ( V_112 , V_182 , V_119 , V_146 | V_185 ,
V_183 , F_133 ) ;
if ( F_142 ( V_169 ) )
F_138 ( V_112 , V_182 + V_119 ) ;
return V_169 ;
}
STATIC int
F_143 (
struct V_181 * V_181 ,
struct V_153 * V_112 ,
T_4 V_182 ,
unsigned V_119 ,
unsigned V_186 ,
struct V_1 * V_1 ,
void * V_184 )
{
int V_169 ;
V_169 = F_144 ( V_181 , V_112 , V_182 , V_119 , V_186 , V_1 , V_184 ) ;
if ( F_142 ( V_169 < V_119 ) )
F_138 ( V_112 , V_182 + V_119 ) ;
return V_169 ;
}
STATIC T_8
F_145 (
struct V_153 * V_112 ,
T_8 V_187 )
{
struct V_9 * V_9 = (struct V_9 * ) V_112 -> V_135 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_146 ( F_6 ( V_9 ) ) ;
F_37 ( V_11 , V_188 ) ;
F_147 ( V_11 , ( T_7 ) 0 , - 1 , 0 , V_189 ) ;
F_20 ( V_11 , V_188 ) ;
return F_148 ( V_112 , V_187 , F_133 ) ;
}
STATIC int
F_149 (
struct V_181 * V_190 ,
struct V_1 * V_1 )
{
return F_150 ( V_1 , F_133 ) ;
}
STATIC int
F_151 (
struct V_181 * V_190 ,
struct V_153 * V_112 ,
struct V_191 * V_134 ,
unsigned V_192 )
{
return F_152 ( V_112 , V_134 , V_192 , F_133 ) ;
}
