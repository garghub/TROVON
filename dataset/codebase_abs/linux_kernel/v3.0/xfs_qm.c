static void
F_1 (
struct V_1 * V_2 )
{
T_1 * V_3 ;
int V_4 = 0 ;
F_2 (dqp, &mp->m_quotainfo->qi_dqlist_lock, qi_mplist) {
F_3 ( V_2 , L_1
L_2 ,
V_4 ++ , F_4 ( V_3 -> V_5 . V_6 ) ,
F_5 ( V_3 ) ,
( long long ) F_6 ( V_3 -> V_5 . V_7 ) ,
( long long ) F_6 ( V_3 -> V_5 . V_8 ) ,
V_3 -> V_9 ) ;
}
}
static void F_1 ( struct V_1 * V_2 ) { }
STATIC struct V_10 *
F_7 ( void )
{
T_2 * V_11 , * V_12 ;
T_3 * V_13 ;
T_4 V_14 ;
T_5 V_4 ;
V_11 = F_8 ( & V_14 ,
V_15 * sizeof( T_2 ) ,
V_16 * sizeof( T_2 ) ) ;
if ( ! V_11 )
goto V_17;
V_12 = F_9 ( V_14 ) ;
if ( ! V_12 )
goto V_18;
V_14 /= sizeof( T_2 ) ;
V_19 = V_14 << 8 ;
V_13 = F_10 ( sizeof( T_3 ) , V_20 ) ;
V_13 -> V_21 = V_14 - 1 ;
V_13 -> V_22 = V_11 ;
V_13 -> V_23 = V_12 ;
ASSERT ( V_13 -> V_22 != NULL ) ;
ASSERT ( V_13 -> V_23 != NULL ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
F_11 ( & ( V_13 -> V_22 [ V_4 ] ) , L_3 , V_4 ) ;
F_11 ( & ( V_13 -> V_23 [ V_4 ] ) , L_4 , V_4 ) ;
}
F_12 ( & V_13 -> V_24 ) ;
V_13 -> V_25 = 0 ;
F_13 ( & V_13 -> V_26 ) ;
if ( ! V_27 ) {
V_13 -> V_27 = F_14 ( sizeof( T_1 ) ,
L_5 ) ;
V_27 = V_13 -> V_27 ;
} else
V_13 -> V_27 = V_27 ;
F_15 ( & V_28 ) ;
if ( ! V_29 ) {
V_13 -> V_29 = F_14 ( sizeof( V_30 ) ,
L_6 ) ;
V_29 = V_13 -> V_29 ;
} else
V_13 -> V_29 = V_29 ;
F_16 ( & V_13 -> V_31 , 0 ) ;
V_13 -> V_32 = V_33 ;
V_13 -> V_34 = 0 ;
#ifdef F_17
F_13 ( & V_35 ) ;
#endif
return V_13 ;
V_18:
F_18 ( V_11 ) ;
V_17:
return NULL ;
}
STATIC void
F_19 (
struct V_10 * V_13 )
{
struct V_36 * V_3 , * V_37 ;
int V_14 , V_4 ;
ASSERT ( V_13 != NULL ) ;
ASSERT ( V_13 -> V_34 == 0 ) ;
F_20 ( & V_28 ) ;
V_14 = V_13 -> V_21 + 1 ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
F_21 ( & ( V_13 -> V_22 [ V_4 ] ) ) ;
F_21 ( & ( V_13 -> V_23 [ V_4 ] ) ) ;
}
F_18 ( V_13 -> V_22 ) ;
F_18 ( V_13 -> V_23 ) ;
V_13 -> V_22 = NULL ;
V_13 -> V_23 = NULL ;
V_13 -> V_21 = 0 ;
F_22 ( & V_13 -> V_26 ) ;
F_23 (dqp, n, &xqm->qm_dqfrlist, q_freelist) {
F_24 ( V_3 ) ;
#ifdef F_25
F_3 ( V_3 -> V_38 , L_7 , V_3 ) ;
#endif
F_26 ( & V_3 -> V_39 ) ;
V_40 -> V_25 -- ;
F_27 ( V_3 ) ;
F_28 ( V_3 ) ;
}
F_29 ( & V_13 -> V_26 ) ;
F_30 ( & V_13 -> V_26 ) ;
#ifdef F_17
F_30 ( & V_35 ) ;
#endif
F_31 ( V_13 ) ;
}
STATIC int
F_32 (
struct V_1 * V_2 )
{
F_22 ( & V_41 ) ;
if ( ! V_40 ) {
V_40 = F_7 () ;
if ( ! V_40 ) {
F_29 ( & V_41 ) ;
return V_42 ;
}
}
V_40 -> V_34 ++ ;
F_29 ( & V_41 ) ;
return 0 ;
}
STATIC void
F_33 (
struct V_1 * V_2 )
{
T_1 * V_3 , * V_37 ;
ASSERT ( V_40 ) ;
ASSERT ( V_40 -> V_34 > 0 ) ;
F_22 ( & V_40 -> V_26 ) ;
F_23 (dqp, n, &xfs_Gqm->qm_dqfrlist, q_freelist) {
F_24 ( V_3 ) ;
if ( V_3 -> V_43 & V_44 ) {
ASSERT ( V_3 -> V_38 == NULL ) ;
ASSERT ( ! F_34 ( V_3 ) ) ;
ASSERT ( F_35 ( & V_3 -> V_45 ) ) ;
ASSERT ( F_35 ( & V_3 -> V_46 ) ) ;
F_26 ( & V_3 -> V_39 ) ;
V_40 -> V_25 -- ;
F_27 ( V_3 ) ;
F_28 ( V_3 ) ;
} else {
F_27 ( V_3 ) ;
}
}
F_29 ( & V_40 -> V_26 ) ;
F_22 ( & V_41 ) ;
if ( -- V_40 -> V_34 == 0 ) {
F_19 ( V_40 ) ;
V_40 = NULL ;
}
F_29 ( & V_41 ) ;
}
void
F_36 (
struct V_1 * V_2 )
{
if ( V_2 -> V_47 ) {
F_37 ( V_2 , V_48 ) ;
F_38 ( V_2 ) ;
}
}
void
F_39 (
T_6 * V_2 )
{
int error = 0 ;
T_5 V_49 ;
if ( V_2 -> V_50 . V_51 ) {
F_40 ( V_2 , L_8 ) ;
V_2 -> V_52 = 0 ;
goto V_53;
}
ASSERT ( F_41 ( V_2 ) ) ;
error = F_42 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_47 == NULL ) ;
V_2 -> V_52 = 0 ;
goto V_53;
}
if ( F_43 ( V_2 ) ) {
error = F_44 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_45 ( V_2 ) )
V_2 -> V_52 &= ~ V_54 ;
if ( ! ( F_46 ( V_2 ) || F_47 ( V_2 ) ) )
V_2 -> V_52 &= ~ V_55 ;
V_53:
F_48 ( & V_2 -> V_56 ) ;
V_49 = V_2 -> V_50 . V_57 ;
V_2 -> V_50 . V_57 = V_2 -> V_52 & V_58 ;
F_49 ( & V_2 -> V_56 ) ;
if ( V_49 != ( V_2 -> V_52 & V_58 ) ) {
if ( F_50 ( V_2 , V_59 ) ) {
ASSERT ( ! ( F_41 ( V_2 ) ) ) ;
F_51 ( V_2 , L_9 ,
V_60 ) ;
}
}
if ( error ) {
F_52 ( V_2 , L_10 ) ;
return;
}
#ifdef F_25
if ( F_53 ( V_2 ) )
F_54 ( V_2 ) ;
#endif
}
void
F_55 (
T_6 * V_2 )
{
ASSERT ( V_2 -> V_61 ) ;
F_56 ( V_2 -> V_61 ) ;
if ( V_2 -> V_62 )
F_56 ( V_2 -> V_62 ) ;
if ( V_2 -> V_63 )
F_56 ( V_2 -> V_63 ) ;
if ( V_2 -> V_47 ) {
if ( V_2 -> V_47 -> V_64 ) {
F_57 ( V_2 -> V_47 -> V_64 ) ;
V_2 -> V_47 -> V_64 = NULL ;
}
if ( V_2 -> V_47 -> V_65 ) {
F_57 ( V_2 -> V_47 -> V_65 ) ;
V_2 -> V_47 -> V_65 = NULL ;
}
}
}
STATIC int
F_58 (
struct V_1 * V_2 ,
int V_66 )
{
struct V_67 * V_68 = V_2 -> V_47 ;
int V_69 ;
struct V_36 * V_3 ;
int error ;
if ( ! V_68 )
return 0 ;
V_70:
F_22 ( & V_68 -> V_71 ) ;
F_2 (dqp, &q->qi_dqlist, q_mplist) {
F_24 ( V_3 ) ;
if ( ! F_34 ( V_3 ) ) {
F_27 ( V_3 ) ;
continue;
}
V_69 = V_68 -> V_72 ;
if ( ! F_59 ( V_3 ) ) {
F_60 ( V_3 ) ;
}
F_29 ( & V_68 -> V_71 ) ;
error = F_61 ( V_3 , V_66 ) ;
F_27 ( V_3 ) ;
if ( error )
return error ;
F_22 ( & V_68 -> V_71 ) ;
if ( V_69 != V_68 -> V_72 ) {
F_29 ( & V_68 -> V_71 ) ;
goto V_70;
}
}
F_29 ( & V_68 -> V_71 ) ;
return 0 ;
}
STATIC void
F_62 (
struct V_1 * V_2 )
{
struct V_67 * V_68 = V_2 -> V_47 ;
struct V_36 * V_3 , * V_73 ;
int V_74 ;
V_70:
ASSERT ( F_63 ( & V_68 -> V_71 ) ) ;
F_2 (dqp, &q->qi_dqlist, q_mplist) {
F_24 ( V_3 ) ;
if ( ( V_73 = V_3 -> V_75 ) ) {
F_24 ( V_73 ) ;
V_3 -> V_75 = NULL ;
}
F_27 ( V_3 ) ;
if ( V_73 ) {
V_74 = V_68 -> V_72 ;
F_29 ( & V_68 -> V_71 ) ;
F_64 ( V_73 ) ;
F_22 ( & V_68 -> V_71 ) ;
if ( V_74 != V_68 -> V_72 )
goto V_70;
}
}
}
STATIC int
F_65 (
struct V_1 * V_2 ,
T_5 V_76 )
{
struct V_67 * V_68 = V_2 -> V_47 ;
struct V_36 * V_3 , * V_37 ;
T_5 V_77 ;
int V_74 ;
int V_78 ;
if ( ! V_68 )
return 0 ;
V_77 = ( V_76 & V_79 ) ? V_80 : 0 ;
V_77 |= ( V_76 & V_81 ) ? V_82 : 0 ;
V_77 |= ( V_76 & V_83 ) ? V_84 : 0 ;
F_22 ( & V_68 -> V_71 ) ;
F_62 ( V_2 ) ;
V_70:
V_78 = 0 ;
ASSERT ( F_63 ( & V_68 -> V_71 ) ) ;
F_23 (dqp, n, &q->qi_dqlist, q_mplist) {
if ( ( V_3 -> V_43 & V_77 ) == 0 )
continue;
if ( ! F_66 ( & V_3 -> V_85 -> V_86 ) ) {
V_74 = V_68 -> V_72 ;
F_29 ( & V_68 -> V_71 ) ;
F_22 ( & V_3 -> V_85 -> V_86 ) ;
F_22 ( & V_68 -> V_71 ) ;
if ( V_74 != V_68 -> V_72 ) {
F_29 ( & V_3 -> V_85 -> V_86 ) ;
goto V_70;
}
}
V_78 += F_67 ( V_3 ) ;
}
F_29 ( & V_68 -> V_71 ) ;
return V_78 ;
}
int
F_37 (
T_6 * V_2 ,
T_5 V_76 )
{
int V_87 ;
if ( V_2 -> V_47 ) {
while ( ( V_87 = F_65 ( V_2 , V_76 ) ) ) {
F_68 ( V_87 * 10 ) ;
}
}
return 0 ;
}
STATIC int
F_69 (
T_7 * V_88 ,
T_8 V_89 ,
T_5 type ,
T_5 V_90 ,
T_1 * V_91 ,
T_1 * * V_92 )
{
T_1 * V_3 ;
int error ;
ASSERT ( F_70 ( V_88 , V_93 ) ) ;
error = 0 ;
V_3 = * V_92 ;
if ( V_3 ) {
F_71 ( V_3 ) ;
return 0 ;
}
if ( V_91 ) {
ASSERT ( type == V_84 || type == V_82 ) ;
F_24 ( V_91 ) ;
V_3 = V_91 -> V_75 ;
if ( V_3 && F_4 ( V_3 -> V_5 . V_6 ) == V_89 ) {
F_24 ( V_3 ) ;
F_72 ( V_3 ) ;
ASSERT ( * V_92 == NULL ) ;
* V_92 = V_3 ;
F_27 ( V_3 ) ;
F_27 ( V_91 ) ;
return 0 ;
}
F_27 ( V_91 ) ;
}
error = F_73 ( V_88 -> V_94 , V_88 , V_89 , type , V_95 , & V_3 ) ;
if ( error )
return error ;
F_74 ( V_3 ) ;
* V_92 = V_3 ;
F_27 ( V_3 ) ;
return 0 ;
}
STATIC void
F_75 (
T_1 * V_96 ,
T_1 * V_97 )
{
T_1 * V_98 ;
F_24 ( V_96 ) ;
if ( ( V_98 = V_96 -> V_75 ) ) {
if ( V_98 == V_97 ) {
F_27 ( V_96 ) ;
return;
}
V_96 -> V_75 = NULL ;
F_27 ( V_96 ) ;
F_76 ( V_98 ) ;
F_24 ( V_96 ) ;
F_24 ( V_97 ) ;
} else {
ASSERT ( F_77 ( V_96 ) ) ;
F_24 ( V_97 ) ;
}
ASSERT ( F_77 ( V_96 ) ) ;
ASSERT ( F_77 ( V_97 ) ) ;
if ( V_96 -> V_75 == NULL ) {
F_72 ( V_97 ) ;
V_96 -> V_75 = V_97 ;
}
F_27 ( V_97 ) ;
F_27 ( V_96 ) ;
}
int
F_78 (
T_7 * V_88 ,
T_5 V_76 )
{
T_6 * V_2 = V_88 -> V_94 ;
T_5 V_99 = 0 ;
int error = 0 ;
if ( ! F_41 ( V_2 ) ||
! F_53 ( V_2 ) ||
! F_79 ( V_2 , V_88 ) ||
V_88 -> V_100 == V_2 -> V_50 . V_101 ||
V_88 -> V_100 == V_2 -> V_50 . V_102 )
return 0 ;
ASSERT ( F_70 ( V_88 , V_93 ) ) ;
if ( F_45 ( V_2 ) ) {
error = F_69 ( V_88 , V_88 -> V_103 . V_104 , V_80 ,
V_76 & V_105 ,
NULL , & V_88 -> V_106 ) ;
if ( error )
goto V_107;
V_99 ++ ;
}
ASSERT ( F_70 ( V_88 , V_93 ) ) ;
if ( F_80 ( V_2 ) ) {
error = F_46 ( V_2 ) ?
F_69 ( V_88 , V_88 -> V_103 . V_108 , V_84 ,
V_76 & V_105 ,
V_88 -> V_106 , & V_88 -> V_109 ) :
F_69 ( V_88 , F_81 ( V_88 ) , V_82 ,
V_76 & V_105 ,
V_88 -> V_106 , & V_88 -> V_109 ) ;
if ( error )
goto V_107;
V_99 ++ ;
}
if ( V_99 == 2 ) {
ASSERT ( F_70 ( V_88 , V_93 ) ) ;
ASSERT ( V_88 -> V_106 ) ;
ASSERT ( V_88 -> V_109 ) ;
if ( V_88 -> V_106 -> V_75 == V_88 -> V_109 )
goto V_107;
F_75 ( V_88 -> V_106 , V_88 -> V_109 ) ;
}
V_107:
#ifdef F_25
if ( ! error ) {
if ( F_45 ( V_2 ) )
ASSERT ( V_88 -> V_106 ) ;
if ( F_80 ( V_2 ) )
ASSERT ( V_88 -> V_109 ) ;
}
ASSERT ( F_70 ( V_88 , V_93 ) ) ;
#endif
return error ;
}
int
F_82 (
struct V_110 * V_88 ,
T_5 V_76 )
{
int error ;
F_83 ( V_88 , V_93 ) ;
error = F_78 ( V_88 , V_76 ) ;
F_84 ( V_88 , V_93 ) ;
return error ;
}
void
F_56 (
T_7 * V_88 )
{
if ( ! ( V_88 -> V_106 || V_88 -> V_109 ) )
return;
F_85 ( V_88 ) ;
ASSERT ( V_88 -> V_100 != V_88 -> V_94 -> V_50 . V_101 ) ;
ASSERT ( V_88 -> V_100 != V_88 -> V_94 -> V_50 . V_102 ) ;
if ( V_88 -> V_106 ) {
F_76 ( V_88 -> V_106 ) ;
V_88 -> V_106 = NULL ;
}
if ( V_88 -> V_109 ) {
F_76 ( V_88 -> V_109 ) ;
V_88 -> V_109 = NULL ;
}
}
int
F_86 (
struct V_1 * V_2 ,
int V_76 )
{
struct V_67 * V_68 = V_2 -> V_47 ;
int V_69 , V_111 ;
struct V_36 * V_3 ;
int error ;
if ( ! F_41 ( V_2 ) || ! F_53 ( V_2 ) )
return 0 ;
V_111 = 0 ;
V_70:
F_22 ( & V_68 -> V_71 ) ;
if ( ! F_53 ( V_2 ) ) {
F_29 ( & V_68 -> V_71 ) ;
return 0 ;
}
ASSERT ( F_63 ( & V_68 -> V_71 ) ) ;
F_2 (dqp, &q->qi_dqlist, q_mplist) {
if ( V_76 & V_112 ) {
if ( ! F_34 ( V_3 ) )
continue;
if ( ! F_87 ( V_3 ) )
continue;
} else {
F_24 ( V_3 ) ;
}
if ( ! F_34 ( V_3 ) ) {
F_27 ( V_3 ) ;
continue;
}
V_69 = V_68 -> V_72 ;
if ( ! F_59 ( V_3 ) ) {
if ( V_76 & V_112 ) {
F_27 ( V_3 ) ;
continue;
}
F_60 ( V_3 ) ;
}
F_29 ( & V_68 -> V_71 ) ;
error = F_61 ( V_3 , V_76 ) ;
F_27 ( V_3 ) ;
if ( error && F_88 ( V_2 ) )
return 0 ;
else if ( error )
return error ;
F_22 ( & V_68 -> V_71 ) ;
if ( V_69 != V_68 -> V_72 ) {
if ( ++ V_111 >= V_113 )
break;
F_29 ( & V_68 -> V_71 ) ;
goto V_70;
}
}
F_29 ( & V_68 -> V_71 ) ;
return 0 ;
}
STATIC int
F_42 (
T_6 * V_2 )
{
T_9 * V_114 ;
int error ;
T_1 * V_3 ;
ASSERT ( F_41 ( V_2 ) ) ;
if ( ( error = F_32 ( V_2 ) ) ) {
return error ;
}
V_114 = V_2 -> V_47 = F_10 ( sizeof( T_9 ) , V_20 ) ;
if ( ( error = F_89 ( V_2 ) ) ) {
F_31 ( V_114 ) ;
V_2 -> V_47 = NULL ;
return error ;
}
F_12 ( & V_114 -> V_115 ) ;
F_13 ( & V_114 -> V_71 ) ;
F_90 ( & V_114 -> V_71 , & V_116 ) ;
V_114 -> V_72 = 0 ;
F_13 ( & V_114 -> V_117 ) ;
V_114 -> V_118 = F_91 ( V_2 , V_119 ) ;
ASSERT ( V_114 -> V_118 ) ;
V_114 -> V_120 = F_92 ( V_114 -> V_118 ) ;
F_93 ( V_114 -> V_120 , sizeof( V_121 ) ) ;
V_2 -> V_52 |= ( V_2 -> V_50 . V_57 & V_122 ) ;
error = F_73 ( V_2 , NULL , ( T_8 ) 0 ,
F_94 ( V_2 ) ? V_80 :
( F_95 ( V_2 ) ? V_84 :
V_82 ) ,
V_123 | V_95 ,
& V_3 ) ;
if ( ! error ) {
T_10 * V_124 = & V_3 -> V_5 ;
V_114 -> V_125 = V_124 -> V_126 ?
F_4 ( V_124 -> V_126 ) : V_127 ;
V_114 -> V_128 = V_124 -> V_129 ?
F_4 ( V_124 -> V_129 ) : V_130 ;
V_114 -> V_131 = V_124 -> V_132 ?
F_4 ( V_124 -> V_132 ) : V_133 ;
V_114 -> V_134 = V_124 -> V_135 ?
F_96 ( V_124 -> V_135 ) : V_136 ;
V_114 -> V_137 = V_124 -> V_138 ?
F_96 ( V_124 -> V_138 ) : V_139 ;
V_114 -> V_140 = V_124 -> V_141 ?
F_96 ( V_124 -> V_141 ) : V_142 ;
V_114 -> V_143 = F_6 ( V_124 -> V_144 ) ;
V_114 -> V_145 = F_6 ( V_124 -> V_146 ) ;
V_114 -> V_147 = F_6 ( V_124 -> V_148 ) ;
V_114 -> V_149 = F_6 ( V_124 -> V_150 ) ;
V_114 -> V_151 = F_6 ( V_124 -> V_152 ) ;
V_114 -> V_153 = F_6 ( V_124 -> V_154 ) ;
F_28 ( V_3 ) ;
} else {
V_114 -> V_125 = V_127 ;
V_114 -> V_128 = V_130 ;
V_114 -> V_131 = V_133 ;
V_114 -> V_134 = V_136 ;
V_114 -> V_137 = V_139 ;
V_114 -> V_140 = V_142 ;
}
return 0 ;
}
void
F_38 (
T_6 * V_2 )
{
T_9 * V_155 ;
V_155 = V_2 -> V_47 ;
ASSERT ( V_155 != NULL ) ;
ASSERT ( V_40 != NULL ) ;
F_33 ( V_2 ) ;
ASSERT ( F_35 ( & V_155 -> V_115 ) ) ;
F_30 ( & V_155 -> V_71 ) ;
if ( V_155 -> V_64 ) {
F_57 ( V_155 -> V_64 ) ;
V_155 -> V_64 = NULL ;
}
if ( V_155 -> V_65 ) {
F_57 ( V_155 -> V_65 ) ;
V_155 -> V_65 = NULL ;
}
F_30 ( & V_155 -> V_117 ) ;
F_31 ( V_155 ) ;
V_2 -> V_47 = NULL ;
}
STATIC void
F_11 (
T_11 * V_156 ,
char * V_157 ,
int V_37 )
{
F_13 ( & V_156 -> V_86 ) ;
F_12 ( & V_156 -> V_158 ) ;
V_156 -> V_159 = 0 ;
V_156 -> V_160 = 0 ;
}
STATIC void
F_21 (
T_11 * V_156 )
{
F_30 ( & ( V_156 -> V_86 ) ) ;
}
STATIC int
F_97 (
T_6 * V_2 ,
T_7 * * V_88 ,
T_12 V_161 ,
T_5 V_76 )
{
T_13 * V_162 ;
int error ;
int V_163 ;
V_162 = F_98 ( V_2 , V_164 ) ;
if ( ( error = F_99 ( V_162 ,
F_100 ( V_2 ) ,
F_101 ( V_2 ) , 0 ,
V_165 ,
V_166 ) ) ) {
F_102 ( V_162 , 0 ) ;
return error ;
}
error = F_103 ( & V_162 , NULL , V_167 , 1 , 0 , 0 , 1 , V_88 , & V_163 ) ;
if ( error ) {
F_102 ( V_162 , V_168 |
V_169 ) ;
return error ;
}
F_48 ( & V_2 -> V_56 ) ;
if ( V_76 & V_170 ) {
ASSERT ( ! F_104 ( & V_2 -> V_50 ) ) ;
ASSERT ( ( V_161 & ( V_171 | V_172 |
V_173 | V_59 ) ) ==
( V_171 | V_172 |
V_173 | V_59 ) ) ;
F_105 ( & V_2 -> V_50 ) ;
V_2 -> V_50 . V_101 = V_174 ;
V_2 -> V_50 . V_102 = V_174 ;
V_2 -> V_50 . V_57 = 0 ;
}
if ( V_76 & V_79 )
V_2 -> V_50 . V_101 = ( * V_88 ) -> V_100 ;
else
V_2 -> V_50 . V_102 = ( * V_88 ) -> V_100 ;
F_49 ( & V_2 -> V_56 ) ;
F_106 ( V_162 , V_161 ) ;
if ( ( error = F_107 ( V_162 , V_168 ) ) ) {
F_51 ( V_2 , L_11 , V_60 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_108 (
T_6 * V_2 ,
T_14 * V_175 ,
T_8 V_89 ,
T_5 type )
{
T_10 * V_176 ;
int V_177 ;
F_109 ( V_175 , V_178 ) ;
#ifdef F_17
V_177 = F_110 ( V_2 , V_119 ) ;
F_93 ( V_177 , sizeof( V_121 ) ) ;
ASSERT ( V_2 -> V_47 -> V_120 == V_177 ) ;
#endif
V_176 = ( T_10 * ) F_111 ( V_175 ) ;
for ( V_177 = 0 ; V_177 < V_2 -> V_47 -> V_120 ; V_177 ++ ) {
( void ) F_112 ( V_2 , V_176 , V_89 + V_177 , type , V_179 ,
L_12 ) ;
V_176 -> V_7 = 0 ;
V_176 -> V_8 = 0 ;
V_176 -> V_180 = 0 ;
V_176 -> V_126 = 0 ;
V_176 -> V_129 = 0 ;
V_176 -> V_132 = 0 ;
V_176 -> V_135 = 0 ;
V_176 -> V_138 = 0 ;
V_176 -> V_141 = 0 ;
V_176 = ( T_10 * ) ( ( V_121 * ) V_176 + 1 ) ;
}
}
STATIC int
F_113 (
T_6 * V_2 ,
T_8 V_181 ,
T_15 V_182 ,
T_16 V_183 ,
T_5 V_76 )
{
T_14 * V_175 ;
int error ;
int type ;
ASSERT ( V_183 > 0 ) ;
type = V_76 & V_79 ? V_80 :
( V_76 & V_81 ? V_82 : V_84 ) ;
error = 0 ;
while ( V_183 -- ) {
error = F_114 ( V_2 , NULL , V_2 -> V_184 ,
F_115 ( V_2 , V_182 ) ,
V_2 -> V_47 -> V_118 , 0 , & V_175 ) ;
if ( error )
break;
F_108 ( V_2 , V_175 , V_181 , type ) ;
F_116 ( V_2 , V_175 ) ;
V_182 ++ ;
V_181 += V_2 -> V_47 -> V_120 ;
}
return error ;
}
STATIC int
F_117 (
T_6 * V_2 ,
T_7 * V_185 ,
T_5 V_76 )
{
T_17 * V_186 ;
int V_4 , V_187 ;
int error ;
T_18 V_188 ;
T_16 V_189 ;
T_8 V_181 ;
T_15 V_190 ;
T_16 V_191 ;
error = 0 ;
if ( V_185 -> V_103 . V_192 == 0 )
return 0 ;
V_186 = F_118 ( V_193 * sizeof( * V_186 ) , V_20 ) ;
V_188 = 0 ;
V_189 = F_119 ( V_2 , ( V_194 ) F_120 ( V_2 ) ) ;
do {
V_187 = V_193 ;
F_83 ( V_185 , V_195 ) ;
error = F_121 ( NULL , V_185 , V_188 ,
V_189 - V_188 ,
V_196 ,
NULL ,
0 , V_186 , & V_187 , NULL ) ;
F_84 ( V_185 , V_195 ) ;
if ( error )
break;
ASSERT ( V_187 <= V_193 ) ;
for ( V_4 = 0 ; V_4 < V_187 ; V_4 ++ ) {
ASSERT ( V_186 [ V_4 ] . V_197 != V_198 ) ;
ASSERT ( V_186 [ V_4 ] . V_199 ) ;
V_188 += V_186 [ V_4 ] . V_199 ;
if ( V_186 [ V_4 ] . V_197 == V_200 )
continue;
V_181 = ( T_8 ) V_186 [ V_4 ] . V_201 *
V_2 -> V_47 -> V_120 ;
if ( ( V_4 + 1 < V_187 ) &&
( V_186 [ V_4 + 1 ] . V_197 != V_200 ) ) {
V_191 = V_186 [ V_4 + 1 ] . V_199 ;
V_190 = V_186 [ V_4 + 1 ] . V_197 ;
while ( V_191 -- ) {
F_122 ( V_2 -> V_184 ,
F_115 ( V_2 , V_190 ) ,
V_2 -> V_47 -> V_118 ) ;
V_190 ++ ;
}
}
if ( ( error = F_113 ( V_2 ,
V_181 ,
V_186 [ V_4 ] . V_197 ,
V_186 [ V_4 ] . V_199 ,
V_76 ) ) ) {
break;
}
}
if ( error )
break;
} while ( V_187 > 0 );
F_31 ( V_186 ) ;
return error ;
}
STATIC int
F_123 (
struct V_110 * V_88 ,
T_8 V_89 ,
T_5 type ,
T_19 V_202 ,
T_19 V_203 )
{
struct V_1 * V_2 = V_88 -> V_94 ;
struct V_36 * V_3 ;
int error ;
error = F_73 ( V_2 , V_88 , V_89 , type ,
V_105 | V_95 , & V_3 ) ;
if ( error ) {
ASSERT ( error != V_204 ) ;
ASSERT ( error != V_205 ) ;
return error ;
}
F_124 ( V_3 ) ;
F_125 ( & V_3 -> V_5 . V_8 , 1 ) ;
V_3 -> V_206 ++ ;
if ( V_202 ) {
F_125 ( & V_3 -> V_5 . V_7 , V_202 ) ;
V_3 -> V_207 += V_202 ;
}
if ( V_203 ) {
F_125 ( & V_3 -> V_5 . V_180 , V_203 ) ;
V_3 -> V_208 += V_203 ;
}
if ( V_3 -> V_5 . V_6 ) {
F_126 ( V_2 , & V_3 -> V_5 ) ;
F_127 ( V_2 , & V_3 -> V_5 ) ;
}
V_3 -> V_43 |= V_209 ;
F_64 ( V_3 ) ;
return 0 ;
}
STATIC int
F_128 (
T_7 * V_88 ,
T_19 * V_210 )
{
T_16 V_203 ;
T_20 V_211 ;
T_21 * V_212 ;
T_20 V_213 ;
int error ;
ASSERT ( F_129 ( V_88 ) ) ;
V_212 = F_130 ( V_88 , V_214 ) ;
if ( ! ( V_212 -> V_215 & V_216 ) ) {
if ( ( error = F_131 ( NULL , V_88 , V_214 ) ) )
return error ;
}
V_203 = 0 ;
V_213 = V_212 -> V_217 / ( T_5 ) sizeof( V_218 ) ;
for ( V_211 = 0 ; V_211 < V_213 ; V_211 ++ )
V_203 += F_132 ( F_133 ( V_212 , V_211 ) ) ;
* V_210 = ( T_19 ) V_203 ;
return 0 ;
}
STATIC int
F_134 (
T_6 * V_2 ,
T_22 V_219 ,
void T_23 * V_220 ,
int V_221 ,
int * V_222 ,
int * V_223 )
{
T_7 * V_88 ;
T_19 V_202 , V_203 = 0 ;
int error ;
ASSERT ( F_41 ( V_2 ) ) ;
if ( V_219 == V_2 -> V_50 . V_101 || V_219 == V_2 -> V_50 . V_102 ) {
* V_223 = V_224 ;
return F_135 ( V_225 ) ;
}
error = F_136 ( V_2 , NULL , V_219 , 0 , V_93 , & V_88 ) ;
if ( error ) {
* V_223 = V_224 ;
return error ;
}
ASSERT ( V_88 -> V_226 == 0 ) ;
if ( F_129 ( V_88 ) ) {
error = F_128 ( V_88 , & V_203 ) ;
if ( error )
goto V_227;
}
V_202 = ( T_19 ) V_88 -> V_103 . V_192 - V_203 ;
if ( F_45 ( V_2 ) ) {
error = F_123 ( V_88 , V_88 -> V_103 . V_104 ,
V_80 , V_202 , V_203 ) ;
if ( error )
goto V_227;
}
if ( F_46 ( V_2 ) ) {
error = F_123 ( V_88 , V_88 -> V_103 . V_108 ,
V_84 , V_202 , V_203 ) ;
if ( error )
goto V_227;
}
if ( F_47 ( V_2 ) ) {
error = F_123 ( V_88 , F_81 ( V_88 ) ,
V_82 , V_202 , V_203 ) ;
if ( error )
goto V_227;
}
F_84 ( V_88 , V_93 ) ;
F_57 ( V_88 ) ;
* V_223 = V_228 ;
return 0 ;
V_227:
F_84 ( V_88 , V_93 ) ;
F_57 ( V_88 ) ;
* V_223 = V_229 ;
return error ;
}
int
F_44 (
T_6 * V_2 )
{
int V_107 , V_230 , error ;
T_22 V_231 ;
T_4 V_232 ;
T_7 * V_233 , * V_234 ;
T_5 V_76 ;
V_230 = V_235 ;
V_232 = 1 ;
V_231 = 0 ;
V_76 = 0 ;
ASSERT ( V_2 -> V_47 -> V_64 || V_2 -> V_47 -> V_65 ) ;
ASSERT ( F_41 ( V_2 ) ) ;
ASSERT ( F_35 ( & V_2 -> V_47 -> V_115 ) ) ;
F_40 ( V_2 , L_13 ) ;
V_233 = V_2 -> V_47 -> V_64 ;
if ( V_233 ) {
error = F_117 ( V_2 , V_233 , V_79 ) ;
if ( error )
goto V_236;
V_76 |= V_54 ;
}
V_234 = V_2 -> V_47 -> V_65 ;
if ( V_234 ) {
error = F_117 ( V_2 , V_234 , F_46 ( V_2 ) ?
V_83 : V_81 ) ;
if ( error )
goto V_236;
V_76 |= V_55 ;
}
do {
error = F_137 ( V_2 , & V_231 , & V_230 ,
F_134 ,
V_232 , NULL , & V_107 ) ;
if ( error )
break;
} while ( ! V_107 );
if ( ! error )
error = F_58 ( V_2 , 0 ) ;
if ( error ) {
F_37 ( V_2 , V_48 ) ;
goto V_236;
}
F_138 ( V_2 -> V_184 ) ;
V_2 -> V_52 &= ~ ( V_55 | V_54 ) ;
V_2 -> V_52 |= V_76 ;
F_1 ( V_2 ) ;
V_236:
if ( error ) {
F_52 ( V_2 ,
L_14 ,
error ) ;
ASSERT ( V_2 -> V_47 != NULL ) ;
ASSERT ( V_40 != NULL ) ;
F_38 ( V_2 ) ;
if ( F_139 ( V_2 ) ) {
F_52 ( V_2 ,
L_15 ) ;
}
} else
F_40 ( V_2 , L_16 ) ;
return ( error ) ;
}
STATIC int
F_89 (
T_6 * V_2 )
{
T_7 * V_233 , * V_234 ;
int error ;
T_12 V_237 ;
T_5 V_76 ;
ASSERT ( V_2 -> V_47 ) ;
V_233 = V_234 = NULL ;
V_237 = 0 ;
V_76 = 0 ;
if ( F_104 ( & V_2 -> V_50 ) ) {
if ( F_45 ( V_2 ) &&
V_2 -> V_50 . V_101 != V_174 ) {
ASSERT ( V_2 -> V_50 . V_101 > 0 ) ;
if ( ( error = F_136 ( V_2 , NULL , V_2 -> V_50 . V_101 ,
0 , 0 , & V_233 ) ) )
return F_135 ( error ) ;
}
if ( F_80 ( V_2 ) &&
V_2 -> V_50 . V_102 != V_174 ) {
ASSERT ( V_2 -> V_50 . V_102 > 0 ) ;
if ( ( error = F_136 ( V_2 , NULL , V_2 -> V_50 . V_102 ,
0 , 0 , & V_234 ) ) ) {
if ( V_233 )
F_57 ( V_233 ) ;
return F_135 ( error ) ;
}
}
} else {
V_76 |= V_170 ;
V_237 |= ( V_171 | V_172 |
V_173 | V_59 ) ;
}
if ( F_45 ( V_2 ) && V_233 == NULL ) {
if ( ( error = F_97 ( V_2 , & V_233 ,
V_237 | V_172 ,
V_76 | V_79 ) ) )
return F_135 ( error ) ;
V_76 &= ~ V_170 ;
}
if ( F_80 ( V_2 ) && V_234 == NULL ) {
V_76 |= ( F_46 ( V_2 ) ?
V_83 : V_81 ) ;
error = F_97 ( V_2 , & V_234 ,
V_237 | V_173 , V_76 ) ;
if ( error ) {
if ( V_233 )
F_57 ( V_233 ) ;
return F_135 ( error ) ;
}
}
V_2 -> V_47 -> V_64 = V_233 ;
V_2 -> V_47 -> V_65 = V_234 ;
return 0 ;
}
STATIC T_1 *
F_140 ( void )
{
T_1 * V_238 ;
T_1 * V_3 ;
int V_111 ;
int V_239 ;
V_111 = 0 ;
V_238 = NULL ;
V_70:
V_239 = 0 ;
F_22 ( & V_40 -> V_26 ) ;
F_2 (dqp, &xfs_Gqm->qm_dqfrlist, q_freelist) {
struct V_1 * V_2 = V_3 -> V_38 ;
F_24 ( V_3 ) ;
if ( V_3 -> V_43 & V_240 ) {
ASSERT ( ! ( V_3 -> V_43 & V_44 ) ) ;
F_141 ( V_3 ) ;
F_142 ( V_241 . V_242 ) ;
V_111 ++ ;
V_239 = 1 ;
goto V_243;
}
if ( V_3 -> V_43 & V_44 ) {
ASSERT ( V_2 == NULL ) ;
ASSERT ( ! F_34 ( V_3 ) ) ;
ASSERT ( F_35 ( & V_3 -> V_45 ) ) ;
ASSERT ( F_35 ( & V_3 -> V_46 ) ) ;
F_26 ( & V_3 -> V_39 ) ;
V_40 -> V_25 -- ;
V_238 = V_3 ;
F_142 ( V_241 . V_244 ) ;
goto V_243;
}
ASSERT ( V_3 -> V_85 ) ;
ASSERT ( ! F_35 ( & V_3 -> V_46 ) ) ;
if ( ! F_59 ( V_3 ) )
goto V_243;
if ( F_34 ( V_3 ) ) {
int error ;
F_143 ( V_3 ) ;
error = F_61 ( V_3 , 0 ) ;
if ( error ) {
F_52 ( V_2 , L_17 ,
V_60 , V_3 ) ;
}
goto V_243;
}
if ( ! F_66 ( & V_3 -> V_85 -> V_86 ) ) {
V_111 ++ ;
goto V_245;
}
if ( ! F_66 ( & V_2 -> V_47 -> V_71 ) ) {
V_111 ++ ;
V_239 = 1 ;
goto V_246;
}
ASSERT ( V_3 -> V_9 == 0 ) ;
F_26 ( & V_3 -> V_46 ) ;
V_2 -> V_47 -> V_247 -- ;
V_2 -> V_47 -> V_72 ++ ;
F_26 ( & V_3 -> V_45 ) ;
V_3 -> V_85 -> V_159 ++ ;
F_26 ( & V_3 -> V_39 ) ;
V_40 -> V_25 -- ;
V_238 = V_3 ;
F_29 ( & V_2 -> V_47 -> V_71 ) ;
V_246:
F_29 ( & V_3 -> V_85 -> V_86 ) ;
V_245:
F_144 ( V_3 ) ;
V_243:
F_27 ( V_3 ) ;
if ( V_238 )
break;
if ( V_111 >= V_248 )
break;
if ( V_239 ) {
F_29 ( & V_40 -> V_26 ) ;
goto V_70;
}
}
F_29 ( & V_40 -> V_26 ) ;
return V_238 ;
}
STATIC int
F_145 (
int V_249 )
{
int V_250 = 0 ;
T_1 * V_3 ;
if ( V_249 <= 0 )
return 0 ;
while ( V_250 < V_249 ) {
V_3 = F_140 () ;
if ( ! V_3 )
return V_250 ;
F_28 ( V_3 ) ;
V_250 ++ ;
}
return V_250 ;
}
STATIC int
F_146 (
struct V_251 * V_252 ,
struct V_253 * V_254 )
{
int V_255 , V_256 , V_37 ;
T_24 V_257 = V_254 -> V_257 ;
if ( ! F_147 ( V_257 ) )
return 0 ;
if ( ! V_40 )
return 0 ;
V_256 = V_40 -> V_25 ;
V_255 = F_148 ( & V_40 -> V_31 ) - V_256 ;
ASSERT ( V_255 >= 0 ) ;
if ( V_256 <= V_255 && V_256 < V_19 )
return 0 ;
V_255 *= V_40 -> V_32 ;
V_37 = V_256 - V_255 - V_19 ;
return F_145 ( F_149 ( V_256 , V_37 ) ) ;
}
T_25
F_150 (
T_1 * * V_258 )
{
T_1 * V_3 ;
if ( F_148 ( & V_40 -> V_31 ) >= V_19 ) {
if ( ( V_3 = F_140 () ) ) {
F_142 ( V_241 . V_259 ) ;
memset ( & V_3 -> V_5 , 0 , sizeof( V_3 -> V_5 ) ) ;
* V_258 = V_3 ;
return V_260 ;
}
F_142 ( V_241 . V_261 ) ;
}
ASSERT ( V_40 -> V_27 != NULL ) ;
* V_258 = F_151 ( V_40 -> V_27 , V_20 ) ;
F_152 ( & V_40 -> V_31 ) ;
return V_262 ;
}
int
F_50 (
T_6 * V_2 ,
T_12 V_76 )
{
T_13 * V_162 ;
int error ;
#ifdef F_25
F_40 ( V_2 , L_18 ) ;
#endif
V_162 = F_98 ( V_2 , V_263 ) ;
if ( ( error = F_99 ( V_162 , 0 ,
V_2 -> V_50 . V_264 + 128 , 0 ,
0 ,
V_265 ) ) ) {
F_102 ( V_162 , 0 ) ;
return error ;
}
F_106 ( V_162 , V_76 ) ;
error = F_107 ( V_162 , 0 ) ;
return error ;
}
int
F_153 (
struct V_110 * V_88 ,
T_26 V_266 ,
T_27 V_267 ,
T_28 V_268 ,
T_5 V_76 ,
struct V_36 * * V_269 ,
struct V_36 * * V_270 )
{
struct V_1 * V_2 = V_88 -> V_94 ;
struct V_36 * V_271 , * V_272 ;
int error ;
T_5 V_273 ;
if ( ! F_41 ( V_2 ) || ! F_53 ( V_2 ) )
return 0 ;
V_273 = V_93 ;
F_83 ( V_88 , V_273 ) ;
if ( ( V_76 & V_274 ) && F_154 ( V_88 ) )
V_267 = V_88 -> V_103 . V_108 ;
if ( F_79 ( V_2 , V_88 ) ) {
error = F_78 ( V_88 , V_105 ) ;
if ( error ) {
F_84 ( V_88 , V_273 ) ;
return error ;
}
}
V_271 = V_272 = NULL ;
if ( ( V_76 & V_79 ) && F_45 ( V_2 ) ) {
if ( V_88 -> V_103 . V_104 != V_266 ) {
F_84 ( V_88 , V_273 ) ;
if ( ( error = F_73 ( V_2 , NULL , ( T_8 ) V_266 ,
V_80 ,
V_105 |
V_95 ,
& V_271 ) ) ) {
ASSERT ( error != V_205 ) ;
return error ;
}
F_27 ( V_271 ) ;
V_273 = V_195 ;
F_83 ( V_88 , V_273 ) ;
} else {
ASSERT ( V_88 -> V_106 ) ;
V_271 = V_88 -> V_106 ;
F_24 ( V_271 ) ;
F_72 ( V_271 ) ;
F_27 ( V_271 ) ;
}
}
if ( ( V_76 & V_83 ) && F_46 ( V_2 ) ) {
if ( V_88 -> V_103 . V_108 != V_267 ) {
F_84 ( V_88 , V_273 ) ;
if ( ( error = F_73 ( V_2 , NULL , ( T_8 ) V_267 ,
V_84 ,
V_105 |
V_95 ,
& V_272 ) ) ) {
if ( V_271 )
F_76 ( V_271 ) ;
ASSERT ( error != V_205 ) ;
return error ;
}
F_27 ( V_272 ) ;
V_273 = V_195 ;
F_83 ( V_88 , V_273 ) ;
} else {
ASSERT ( V_88 -> V_109 ) ;
V_272 = V_88 -> V_109 ;
F_24 ( V_272 ) ;
F_72 ( V_272 ) ;
F_27 ( V_272 ) ;
}
} else if ( ( V_76 & V_81 ) && F_47 ( V_2 ) ) {
if ( F_81 ( V_88 ) != V_268 ) {
F_84 ( V_88 , V_273 ) ;
if ( ( error = F_73 ( V_2 , NULL , ( T_8 ) V_268 ,
V_82 ,
V_105 |
V_95 ,
& V_272 ) ) ) {
if ( V_271 )
F_76 ( V_271 ) ;
ASSERT ( error != V_205 ) ;
return ( error ) ;
}
F_27 ( V_272 ) ;
V_273 = V_195 ;
F_83 ( V_88 , V_273 ) ;
} else {
ASSERT ( V_88 -> V_109 ) ;
V_272 = V_88 -> V_109 ;
F_24 ( V_272 ) ;
F_72 ( V_272 ) ;
F_27 ( V_272 ) ;
}
}
if ( V_271 )
F_155 ( V_88 ) ;
F_84 ( V_88 , V_273 ) ;
if ( V_269 )
* V_269 = V_271 ;
else if ( V_271 )
F_76 ( V_271 ) ;
if ( V_270 )
* V_270 = V_272 ;
else if ( V_272 )
F_76 ( V_272 ) ;
return 0 ;
}
T_1 *
F_156 (
T_13 * V_162 ,
T_7 * V_88 ,
T_1 * * V_275 ,
T_1 * V_276 )
{
T_1 * V_277 ;
T_5 V_278 = F_129 ( V_88 ) ?
V_279 : V_280 ;
ASSERT ( F_70 ( V_88 , V_93 ) ) ;
ASSERT ( F_41 ( V_88 -> V_94 ) ) ;
V_277 = * V_275 ;
ASSERT ( V_277 ) ;
ASSERT ( V_277 != V_276 ) ;
F_157 ( V_162 , V_277 , V_278 , - ( V_88 -> V_103 . V_192 ) ) ;
F_157 ( V_162 , V_277 , V_281 , - 1 ) ;
F_157 ( V_162 , V_276 , V_278 , V_88 -> V_103 . V_192 ) ;
F_157 ( V_162 , V_276 , V_281 , 1 ) ;
F_24 ( V_276 ) ;
F_72 ( V_276 ) ;
F_27 ( V_276 ) ;
* V_275 = V_276 ;
return V_277 ;
}
int
F_158 (
T_13 * V_162 ,
T_7 * V_88 ,
T_1 * V_282 ,
T_1 * V_73 ,
T_5 V_76 )
{
T_6 * V_2 = V_88 -> V_94 ;
T_5 V_283 , V_284 , V_285 = 0 ;
T_1 * V_286 , * V_287 , * V_288 , * V_289 ;
int error ;
ASSERT ( F_70 ( V_88 , V_93 | V_195 ) ) ;
ASSERT ( F_41 ( V_2 ) ) ;
V_283 = V_88 -> V_226 ;
V_288 = V_289 = V_286 = V_287 = NULL ;
V_284 = F_129 ( V_88 ) ?
V_290 : V_291 ;
if ( F_45 ( V_2 ) && V_282 &&
V_88 -> V_103 . V_104 != ( T_26 ) F_4 ( V_282 -> V_5 . V_6 ) ) {
V_288 = V_282 ;
if ( V_283 ) {
ASSERT ( V_88 -> V_106 ) ;
V_286 = V_88 -> V_106 ;
}
}
if ( F_80 ( V_88 -> V_94 ) && V_73 ) {
if ( F_47 ( V_88 -> V_94 ) &&
F_81 ( V_88 ) != F_4 ( V_73 -> V_5 . V_6 ) )
V_285 = V_292 ;
if ( V_285 ||
( F_46 ( V_88 -> V_94 ) &&
V_88 -> V_103 . V_108 != F_4 ( V_73 -> V_5 . V_6 ) ) ) {
V_289 = V_73 ;
if ( V_283 ) {
ASSERT ( V_88 -> V_109 ) ;
V_287 = V_88 -> V_109 ;
}
}
}
if ( ( error = F_159 ( V_162 , V_88 -> V_94 ,
V_288 , V_289 , V_88 -> V_103 . V_192 , 1 ,
V_76 | V_284 | V_285 ) ) )
return ( error ) ;
if ( V_283 ) {
ASSERT ( V_288 || V_289 ) ;
ASSERT ( V_286 || V_287 ) ;
if ( ( error = F_159 ( NULL , V_88 -> V_94 ,
V_288 , V_289 , ( T_19 ) V_283 , 0 ,
V_76 | V_284 | V_285 ) ) )
return ( error ) ;
F_159 ( NULL , V_88 -> V_94 ,
V_286 , V_287 , - ( ( T_19 ) V_283 ) , 0 ,
V_284 ) ;
}
return ( 0 ) ;
}
int
F_160 (
struct V_110 * * V_293 )
{
struct V_1 * V_2 = V_293 [ 0 ] -> V_94 ;
int V_4 ;
if ( ! F_41 ( V_2 ) || ! F_53 ( V_2 ) )
return 0 ;
for ( V_4 = 0 ; ( V_4 < 4 && V_293 [ V_4 ] ) ; V_4 ++ ) {
struct V_110 * V_88 = V_293 [ V_4 ] ;
int error ;
if ( V_4 == 0 || V_88 != V_293 [ V_4 - 1 ] ) {
if ( F_79 ( V_2 , V_88 ) ) {
error = F_82 ( V_88 , 0 ) ;
if ( error )
return error ;
}
}
}
return 0 ;
}
void
F_161 (
struct V_294 * V_162 ,
struct V_110 * V_88 ,
struct V_36 * V_282 ,
struct V_36 * V_73 )
{
struct V_1 * V_2 = V_162 -> V_295 ;
if ( ! F_41 ( V_2 ) || ! F_53 ( V_2 ) )
return;
ASSERT ( F_70 ( V_88 , V_93 ) ) ;
ASSERT ( F_41 ( V_2 ) ) ;
if ( V_282 ) {
F_24 ( V_282 ) ;
F_72 ( V_282 ) ;
F_27 ( V_282 ) ;
ASSERT ( V_88 -> V_106 == NULL ) ;
V_88 -> V_106 = V_282 ;
ASSERT ( F_45 ( V_2 ) ) ;
ASSERT ( V_88 -> V_103 . V_104 == F_4 ( V_282 -> V_5 . V_6 ) ) ;
F_157 ( V_162 , V_282 , V_281 , 1 ) ;
}
if ( V_73 ) {
F_24 ( V_73 ) ;
F_72 ( V_73 ) ;
F_27 ( V_73 ) ;
ASSERT ( V_88 -> V_109 == NULL ) ;
V_88 -> V_109 = V_73 ;
ASSERT ( F_80 ( V_2 ) ) ;
ASSERT ( ( F_46 ( V_2 ) ?
V_88 -> V_103 . V_108 : F_81 ( V_88 ) ) ==
F_4 ( V_73 -> V_5 . V_6 ) ) ;
F_157 ( V_162 , V_73 , V_281 , 1 ) ;
}
}
