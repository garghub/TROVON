STATIC struct V_1 *
F_1 ( void )
{
T_1 * V_2 , * V_3 ;
T_2 * V_4 ;
T_3 V_5 ;
T_4 V_6 ;
V_2 = F_2 ( & V_5 ,
V_7 * sizeof( T_1 ) ,
V_8 * sizeof( T_1 ) ) ;
if ( ! V_2 )
goto V_9;
V_3 = F_3 ( V_5 ) ;
if ( ! V_3 )
goto V_10;
V_5 /= sizeof( T_1 ) ;
V_11 = V_5 << 8 ;
V_4 = F_4 ( sizeof( T_2 ) , V_12 ) ;
V_4 -> V_13 = V_5 - 1 ;
V_4 -> V_14 = V_2 ;
V_4 -> V_15 = V_3 ;
ASSERT ( V_4 -> V_14 != NULL ) ;
ASSERT ( V_4 -> V_15 != NULL ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
F_5 ( & ( V_4 -> V_14 [ V_6 ] ) , L_1 , V_6 ) ;
F_5 ( & ( V_4 -> V_15 [ V_6 ] ) , L_2 , V_6 ) ;
}
F_6 ( & V_4 -> V_16 ) ;
V_4 -> V_17 = 0 ;
F_7 ( & V_4 -> V_18 ) ;
if ( ! V_19 ) {
V_4 -> V_19 = F_8 ( sizeof( V_20 ) ,
L_3 ) ;
V_19 = V_4 -> V_19 ;
} else
V_4 -> V_19 = V_19 ;
F_9 ( & V_21 ) ;
if ( ! V_22 ) {
V_4 -> V_22 = F_8 ( sizeof( V_23 ) ,
L_4 ) ;
V_22 = V_4 -> V_22 ;
} else
V_4 -> V_22 = V_22 ;
F_10 ( & V_4 -> V_24 , 0 ) ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = 0 ;
return V_4 ;
V_10:
F_11 ( V_2 ) ;
V_9:
return NULL ;
}
STATIC void
F_12 (
struct V_1 * V_4 )
{
struct V_28 * V_29 , * V_30 ;
int V_5 , V_6 ;
ASSERT ( V_4 != NULL ) ;
ASSERT ( V_4 -> V_27 == 0 ) ;
F_13 ( & V_21 ) ;
V_5 = V_4 -> V_13 + 1 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
F_14 ( & ( V_4 -> V_14 [ V_6 ] ) ) ;
F_14 ( & ( V_4 -> V_15 [ V_6 ] ) ) ;
}
F_11 ( V_4 -> V_14 ) ;
F_11 ( V_4 -> V_15 ) ;
V_4 -> V_14 = NULL ;
V_4 -> V_15 = NULL ;
V_4 -> V_13 = 0 ;
F_15 ( & V_4 -> V_18 ) ;
F_16 (dqp, n, &xqm->qm_dqfrlist, q_freelist) {
F_17 ( V_29 ) ;
F_18 ( & V_29 -> V_31 ) ;
V_32 -> V_17 -- ;
F_19 ( V_29 ) ;
F_20 ( V_29 ) ;
}
F_21 ( & V_4 -> V_18 ) ;
F_22 ( & V_4 -> V_18 ) ;
F_23 ( V_4 ) ;
}
STATIC int
F_24 (
struct V_33 * V_34 )
{
F_15 ( & V_35 ) ;
if ( ! V_32 ) {
V_32 = F_1 () ;
if ( ! V_32 ) {
F_21 ( & V_35 ) ;
return V_36 ;
}
}
V_32 -> V_27 ++ ;
F_21 ( & V_35 ) ;
return 0 ;
}
STATIC void
F_25 (
struct V_33 * V_34 )
{
V_20 * V_29 , * V_30 ;
ASSERT ( V_32 ) ;
ASSERT ( V_32 -> V_27 > 0 ) ;
F_15 ( & V_32 -> V_18 ) ;
F_16 (dqp, n, &xfs_Gqm->qm_dqfrlist, q_freelist) {
F_17 ( V_29 ) ;
if ( V_29 -> V_37 & V_38 ) {
ASSERT ( V_29 -> V_39 == NULL ) ;
ASSERT ( ! F_26 ( V_29 ) ) ;
ASSERT ( F_27 ( & V_29 -> V_40 ) ) ;
ASSERT ( F_27 ( & V_29 -> V_41 ) ) ;
F_18 ( & V_29 -> V_31 ) ;
V_32 -> V_17 -- ;
F_19 ( V_29 ) ;
F_20 ( V_29 ) ;
} else {
F_19 ( V_29 ) ;
}
}
F_21 ( & V_32 -> V_18 ) ;
F_15 ( & V_35 ) ;
if ( -- V_32 -> V_27 == 0 ) {
F_12 ( V_32 ) ;
V_32 = NULL ;
}
F_21 ( & V_35 ) ;
}
void
F_28 (
struct V_33 * V_34 )
{
if ( V_34 -> V_42 ) {
F_29 ( V_34 , V_43 ) ;
F_30 ( V_34 ) ;
}
}
void
F_31 (
T_5 * V_34 )
{
int error = 0 ;
T_4 V_44 ;
if ( V_34 -> V_45 . V_46 ) {
F_32 ( V_34 , L_5 ) ;
V_34 -> V_47 = 0 ;
goto V_48;
}
ASSERT ( F_33 ( V_34 ) ) ;
error = F_34 ( V_34 ) ;
if ( error ) {
ASSERT ( V_34 -> V_42 == NULL ) ;
V_34 -> V_47 = 0 ;
goto V_48;
}
if ( F_35 ( V_34 ) ) {
error = F_36 ( V_34 ) ;
if ( error ) {
return;
}
}
if ( ! F_37 ( V_34 ) )
V_34 -> V_47 &= ~ V_49 ;
if ( ! ( F_38 ( V_34 ) || F_39 ( V_34 ) ) )
V_34 -> V_47 &= ~ V_50 ;
V_48:
F_40 ( & V_34 -> V_51 ) ;
V_44 = V_34 -> V_45 . V_52 ;
V_34 -> V_45 . V_52 = V_34 -> V_47 & V_53 ;
F_41 ( & V_34 -> V_51 ) ;
if ( V_44 != ( V_34 -> V_47 & V_53 ) ) {
if ( F_42 ( V_34 , V_54 ) ) {
ASSERT ( ! ( F_33 ( V_34 ) ) ) ;
F_43 ( V_34 , L_6 ,
V_55 ) ;
}
}
if ( error ) {
F_44 ( V_34 , L_7 ) ;
return;
}
}
void
F_45 (
T_5 * V_34 )
{
ASSERT ( V_34 -> V_56 ) ;
F_46 ( V_34 -> V_56 ) ;
if ( V_34 -> V_57 )
F_46 ( V_34 -> V_57 ) ;
if ( V_34 -> V_58 )
F_46 ( V_34 -> V_58 ) ;
if ( V_34 -> V_42 ) {
if ( V_34 -> V_42 -> V_59 ) {
F_47 ( V_34 -> V_42 -> V_59 ) ;
V_34 -> V_42 -> V_59 = NULL ;
}
if ( V_34 -> V_42 -> V_60 ) {
F_47 ( V_34 -> V_42 -> V_60 ) ;
V_34 -> V_42 -> V_60 = NULL ;
}
}
}
STATIC int
F_48 (
struct V_33 * V_34 ,
int V_61 )
{
struct V_62 * V_63 = V_34 -> V_42 ;
int V_64 ;
struct V_28 * V_29 ;
int error ;
if ( ! V_63 )
return 0 ;
V_65:
F_15 ( & V_63 -> V_66 ) ;
F_49 (dqp, &q->qi_dqlist, q_mplist) {
F_17 ( V_29 ) ;
if ( ! F_26 ( V_29 ) ) {
F_19 ( V_29 ) ;
continue;
}
V_64 = V_63 -> V_67 ;
if ( ! F_50 ( V_29 ) ) {
F_51 ( V_29 ) ;
}
F_21 ( & V_63 -> V_66 ) ;
error = F_52 ( V_29 , V_61 ) ;
F_19 ( V_29 ) ;
if ( error )
return error ;
F_15 ( & V_63 -> V_66 ) ;
if ( V_64 != V_63 -> V_67 ) {
F_21 ( & V_63 -> V_66 ) ;
goto V_65;
}
}
F_21 ( & V_63 -> V_66 ) ;
return 0 ;
}
STATIC void
F_53 (
struct V_33 * V_34 )
{
struct V_62 * V_63 = V_34 -> V_42 ;
struct V_28 * V_29 , * V_68 ;
int V_69 ;
V_65:
ASSERT ( F_54 ( & V_63 -> V_66 ) ) ;
F_49 (dqp, &q->qi_dqlist, q_mplist) {
F_17 ( V_29 ) ;
if ( ( V_68 = V_29 -> V_70 ) ) {
F_17 ( V_68 ) ;
V_29 -> V_70 = NULL ;
}
F_19 ( V_29 ) ;
if ( V_68 ) {
V_69 = V_63 -> V_67 ;
F_21 ( & V_63 -> V_66 ) ;
F_55 ( V_68 ) ;
F_15 ( & V_63 -> V_66 ) ;
if ( V_69 != V_63 -> V_67 )
goto V_65;
}
}
}
STATIC int
F_56 (
struct V_33 * V_34 ,
T_4 V_71 )
{
struct V_62 * V_63 = V_34 -> V_42 ;
struct V_28 * V_29 , * V_30 ;
T_4 V_72 ;
int V_69 ;
int V_73 ;
if ( ! V_63 )
return 0 ;
V_72 = ( V_71 & V_74 ) ? V_75 : 0 ;
V_72 |= ( V_71 & V_76 ) ? V_77 : 0 ;
V_72 |= ( V_71 & V_78 ) ? V_79 : 0 ;
F_15 ( & V_63 -> V_66 ) ;
F_53 ( V_34 ) ;
V_65:
V_73 = 0 ;
ASSERT ( F_54 ( & V_63 -> V_66 ) ) ;
F_16 (dqp, n, &q->qi_dqlist, q_mplist) {
if ( ( V_29 -> V_37 & V_72 ) == 0 )
continue;
if ( ! F_57 ( & V_29 -> V_80 -> V_81 ) ) {
V_69 = V_63 -> V_67 ;
F_21 ( & V_63 -> V_66 ) ;
F_15 ( & V_29 -> V_80 -> V_81 ) ;
F_15 ( & V_63 -> V_66 ) ;
if ( V_69 != V_63 -> V_67 ) {
F_21 ( & V_29 -> V_80 -> V_81 ) ;
goto V_65;
}
}
V_73 += F_58 ( V_29 ) ;
}
F_21 ( & V_63 -> V_66 ) ;
return V_73 ;
}
int
F_29 (
T_5 * V_34 ,
T_4 V_71 )
{
int V_82 ;
if ( V_34 -> V_42 ) {
while ( ( V_82 = F_56 ( V_34 , V_71 ) ) ) {
F_59 ( V_82 * 10 ) ;
}
}
return 0 ;
}
STATIC int
F_60 (
T_6 * V_83 ,
T_7 V_84 ,
T_4 type ,
T_4 V_85 ,
V_20 * V_86 ,
V_20 * * V_87 )
{
V_20 * V_29 ;
int error ;
ASSERT ( F_61 ( V_83 , V_88 ) ) ;
error = 0 ;
V_29 = * V_87 ;
if ( V_29 ) {
F_62 ( V_29 ) ;
return 0 ;
}
if ( V_86 ) {
ASSERT ( type == V_79 || type == V_77 ) ;
F_17 ( V_86 ) ;
V_29 = V_86 -> V_70 ;
if ( V_29 && F_63 ( V_29 -> V_89 . V_90 ) == V_84 ) {
F_17 ( V_29 ) ;
F_64 ( V_29 ) ;
ASSERT ( * V_87 == NULL ) ;
* V_87 = V_29 ;
F_19 ( V_29 ) ;
F_19 ( V_86 ) ;
return 0 ;
}
F_19 ( V_86 ) ;
}
error = F_65 ( V_83 -> V_91 , V_83 , V_84 , type , V_92 , & V_29 ) ;
if ( error )
return error ;
F_66 ( V_29 ) ;
* V_87 = V_29 ;
F_19 ( V_29 ) ;
return 0 ;
}
STATIC void
F_67 (
V_20 * V_93 ,
V_20 * V_94 )
{
V_20 * V_95 ;
F_17 ( V_93 ) ;
if ( ( V_95 = V_93 -> V_70 ) ) {
if ( V_95 == V_94 ) {
F_19 ( V_93 ) ;
return;
}
V_93 -> V_70 = NULL ;
F_19 ( V_93 ) ;
F_68 ( V_95 ) ;
F_17 ( V_93 ) ;
F_17 ( V_94 ) ;
} else {
ASSERT ( F_69 ( V_93 ) ) ;
F_17 ( V_94 ) ;
}
ASSERT ( F_69 ( V_93 ) ) ;
ASSERT ( F_69 ( V_94 ) ) ;
if ( V_93 -> V_70 == NULL ) {
F_64 ( V_94 ) ;
V_93 -> V_70 = V_94 ;
}
F_19 ( V_94 ) ;
F_19 ( V_93 ) ;
}
int
F_70 (
T_6 * V_83 ,
T_4 V_71 )
{
T_5 * V_34 = V_83 -> V_91 ;
T_4 V_96 = 0 ;
int error = 0 ;
if ( ! F_33 ( V_34 ) ||
! F_71 ( V_34 ) ||
! F_72 ( V_34 , V_83 ) ||
V_83 -> V_97 == V_34 -> V_45 . V_98 ||
V_83 -> V_97 == V_34 -> V_45 . V_99 )
return 0 ;
ASSERT ( F_61 ( V_83 , V_88 ) ) ;
if ( F_37 ( V_34 ) ) {
error = F_60 ( V_83 , V_83 -> V_100 . V_101 , V_75 ,
V_71 & V_102 ,
NULL , & V_83 -> V_103 ) ;
if ( error )
goto V_104;
V_96 ++ ;
}
ASSERT ( F_61 ( V_83 , V_88 ) ) ;
if ( F_73 ( V_34 ) ) {
error = F_38 ( V_34 ) ?
F_60 ( V_83 , V_83 -> V_100 . V_105 , V_79 ,
V_71 & V_102 ,
V_83 -> V_103 , & V_83 -> V_106 ) :
F_60 ( V_83 , F_74 ( V_83 ) , V_77 ,
V_71 & V_102 ,
V_83 -> V_103 , & V_83 -> V_106 ) ;
if ( error )
goto V_104;
V_96 ++ ;
}
if ( V_96 == 2 ) {
ASSERT ( F_61 ( V_83 , V_88 ) ) ;
ASSERT ( V_83 -> V_103 ) ;
ASSERT ( V_83 -> V_106 ) ;
if ( V_83 -> V_103 -> V_70 == V_83 -> V_106 )
goto V_104;
F_67 ( V_83 -> V_103 , V_83 -> V_106 ) ;
}
V_104:
#ifdef F_75
if ( ! error ) {
if ( F_37 ( V_34 ) )
ASSERT ( V_83 -> V_103 ) ;
if ( F_73 ( V_34 ) )
ASSERT ( V_83 -> V_106 ) ;
}
ASSERT ( F_61 ( V_83 , V_88 ) ) ;
#endif
return error ;
}
int
F_76 (
struct V_107 * V_83 ,
T_4 V_71 )
{
int error ;
F_77 ( V_83 , V_88 ) ;
error = F_70 ( V_83 , V_71 ) ;
F_78 ( V_83 , V_88 ) ;
return error ;
}
void
F_46 (
T_6 * V_83 )
{
if ( ! ( V_83 -> V_103 || V_83 -> V_106 ) )
return;
F_79 ( V_83 ) ;
ASSERT ( V_83 -> V_97 != V_83 -> V_91 -> V_45 . V_98 ) ;
ASSERT ( V_83 -> V_97 != V_83 -> V_91 -> V_45 . V_99 ) ;
if ( V_83 -> V_103 ) {
F_68 ( V_83 -> V_103 ) ;
V_83 -> V_103 = NULL ;
}
if ( V_83 -> V_106 ) {
F_68 ( V_83 -> V_106 ) ;
V_83 -> V_106 = NULL ;
}
}
int
F_80 (
struct V_33 * V_34 ,
int V_71 )
{
struct V_62 * V_63 = V_34 -> V_42 ;
int V_64 , V_108 ;
struct V_28 * V_29 ;
int error ;
if ( ! F_33 ( V_34 ) || ! F_71 ( V_34 ) )
return 0 ;
V_108 = 0 ;
V_65:
F_15 ( & V_63 -> V_66 ) ;
if ( ! F_71 ( V_34 ) ) {
F_21 ( & V_63 -> V_66 ) ;
return 0 ;
}
ASSERT ( F_54 ( & V_63 -> V_66 ) ) ;
F_49 (dqp, &q->qi_dqlist, q_mplist) {
if ( V_71 & V_109 ) {
if ( ! F_26 ( V_29 ) )
continue;
if ( ! F_81 ( V_29 ) )
continue;
} else {
F_17 ( V_29 ) ;
}
if ( ! F_26 ( V_29 ) ) {
F_19 ( V_29 ) ;
continue;
}
V_64 = V_63 -> V_67 ;
if ( ! F_50 ( V_29 ) ) {
if ( V_71 & V_109 ) {
F_19 ( V_29 ) ;
continue;
}
F_51 ( V_29 ) ;
}
F_21 ( & V_63 -> V_66 ) ;
error = F_52 ( V_29 , V_71 ) ;
F_19 ( V_29 ) ;
if ( error && F_82 ( V_34 ) )
return 0 ;
else if ( error )
return error ;
F_15 ( & V_63 -> V_66 ) ;
if ( V_64 != V_63 -> V_67 ) {
if ( ++ V_108 >= V_110 )
break;
F_21 ( & V_63 -> V_66 ) ;
goto V_65;
}
}
F_21 ( & V_63 -> V_66 ) ;
return 0 ;
}
STATIC int
F_34 (
T_5 * V_34 )
{
T_8 * V_111 ;
int error ;
V_20 * V_29 ;
ASSERT ( F_33 ( V_34 ) ) ;
if ( ( error = F_24 ( V_34 ) ) ) {
return error ;
}
V_111 = V_34 -> V_42 = F_4 ( sizeof( T_8 ) , V_12 ) ;
if ( ( error = F_83 ( V_34 ) ) ) {
F_23 ( V_111 ) ;
V_34 -> V_42 = NULL ;
return error ;
}
F_6 ( & V_111 -> V_112 ) ;
F_7 ( & V_111 -> V_66 ) ;
F_84 ( & V_111 -> V_66 , & V_113 ) ;
V_111 -> V_67 = 0 ;
F_7 ( & V_111 -> V_114 ) ;
V_111 -> V_115 = F_85 ( V_34 , V_116 ) ;
ASSERT ( V_111 -> V_115 ) ;
V_111 -> V_117 = F_86 ( V_111 -> V_115 ) ;
F_87 ( V_111 -> V_117 , sizeof( V_118 ) ) ;
V_34 -> V_47 |= ( V_34 -> V_45 . V_52 & V_119 ) ;
error = F_65 ( V_34 , NULL , ( T_7 ) 0 ,
F_88 ( V_34 ) ? V_75 :
( F_89 ( V_34 ) ? V_79 :
V_77 ) ,
V_120 | V_92 ,
& V_29 ) ;
if ( ! error ) {
T_9 * V_121 = & V_29 -> V_89 ;
V_111 -> V_122 = V_121 -> V_123 ?
F_63 ( V_121 -> V_123 ) : V_124 ;
V_111 -> V_125 = V_121 -> V_126 ?
F_63 ( V_121 -> V_126 ) : V_127 ;
V_111 -> V_128 = V_121 -> V_129 ?
F_63 ( V_121 -> V_129 ) : V_130 ;
V_111 -> V_131 = V_121 -> V_132 ?
F_90 ( V_121 -> V_132 ) : V_133 ;
V_111 -> V_134 = V_121 -> V_135 ?
F_90 ( V_121 -> V_135 ) : V_136 ;
V_111 -> V_137 = V_121 -> V_138 ?
F_90 ( V_121 -> V_138 ) : V_139 ;
V_111 -> V_140 = F_91 ( V_121 -> V_141 ) ;
V_111 -> V_142 = F_91 ( V_121 -> V_143 ) ;
V_111 -> V_144 = F_91 ( V_121 -> V_145 ) ;
V_111 -> V_146 = F_91 ( V_121 -> V_147 ) ;
V_111 -> V_148 = F_91 ( V_121 -> V_149 ) ;
V_111 -> V_150 = F_91 ( V_121 -> V_151 ) ;
F_20 ( V_29 ) ;
} else {
V_111 -> V_122 = V_124 ;
V_111 -> V_125 = V_127 ;
V_111 -> V_128 = V_130 ;
V_111 -> V_131 = V_133 ;
V_111 -> V_134 = V_136 ;
V_111 -> V_137 = V_139 ;
}
return 0 ;
}
void
F_30 (
T_5 * V_34 )
{
T_8 * V_152 ;
V_152 = V_34 -> V_42 ;
ASSERT ( V_152 != NULL ) ;
ASSERT ( V_32 != NULL ) ;
F_25 ( V_34 ) ;
ASSERT ( F_27 ( & V_152 -> V_112 ) ) ;
F_22 ( & V_152 -> V_66 ) ;
if ( V_152 -> V_59 ) {
F_47 ( V_152 -> V_59 ) ;
V_152 -> V_59 = NULL ;
}
if ( V_152 -> V_60 ) {
F_47 ( V_152 -> V_60 ) ;
V_152 -> V_60 = NULL ;
}
F_22 ( & V_152 -> V_114 ) ;
F_23 ( V_152 ) ;
V_34 -> V_42 = NULL ;
}
STATIC void
F_5 (
T_10 * V_153 ,
char * V_154 ,
int V_30 )
{
F_7 ( & V_153 -> V_81 ) ;
F_6 ( & V_153 -> V_155 ) ;
V_153 -> V_156 = 0 ;
V_153 -> V_157 = 0 ;
}
STATIC void
F_14 (
T_10 * V_153 )
{
F_22 ( & ( V_153 -> V_81 ) ) ;
}
STATIC int
F_92 (
T_5 * V_34 ,
T_6 * * V_83 ,
T_11 V_158 ,
T_4 V_71 )
{
T_12 * V_159 ;
int error ;
int V_160 ;
V_159 = F_93 ( V_34 , V_161 ) ;
if ( ( error = F_94 ( V_159 ,
F_95 ( V_34 ) ,
F_96 ( V_34 ) , 0 ,
V_162 ,
V_163 ) ) ) {
F_97 ( V_159 , 0 ) ;
return error ;
}
error = F_98 ( & V_159 , NULL , V_164 , 1 , 0 , 0 , 1 , V_83 , & V_160 ) ;
if ( error ) {
F_97 ( V_159 , V_165 |
V_166 ) ;
return error ;
}
F_40 ( & V_34 -> V_51 ) ;
if ( V_71 & V_167 ) {
ASSERT ( ! F_99 ( & V_34 -> V_45 ) ) ;
ASSERT ( ( V_158 & ( V_168 | V_169 |
V_170 | V_54 ) ) ==
( V_168 | V_169 |
V_170 | V_54 ) ) ;
F_100 ( & V_34 -> V_45 ) ;
V_34 -> V_45 . V_98 = V_171 ;
V_34 -> V_45 . V_99 = V_171 ;
V_34 -> V_45 . V_52 = 0 ;
}
if ( V_71 & V_74 )
V_34 -> V_45 . V_98 = ( * V_83 ) -> V_97 ;
else
V_34 -> V_45 . V_99 = ( * V_83 ) -> V_97 ;
F_41 ( & V_34 -> V_51 ) ;
F_101 ( V_159 , V_158 ) ;
if ( ( error = F_102 ( V_159 , V_165 ) ) ) {
F_43 ( V_34 , L_8 , V_55 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_103 (
T_5 * V_34 ,
T_13 * V_172 ,
T_7 V_84 ,
T_4 type )
{
T_9 * V_173 ;
int V_174 ;
F_104 ( V_172 , V_175 ) ;
#ifdef F_75
V_174 = F_105 ( V_34 , V_116 ) ;
F_87 ( V_174 , sizeof( V_118 ) ) ;
ASSERT ( V_34 -> V_42 -> V_117 == V_174 ) ;
#endif
V_173 = V_172 -> V_176 ;
for ( V_174 = 0 ; V_174 < V_34 -> V_42 -> V_117 ; V_174 ++ ) {
( void ) F_106 ( V_34 , V_173 , V_84 + V_174 , type , V_177 ,
L_9 ) ;
V_173 -> V_178 = 0 ;
V_173 -> V_179 = 0 ;
V_173 -> V_180 = 0 ;
V_173 -> V_123 = 0 ;
V_173 -> V_126 = 0 ;
V_173 -> V_129 = 0 ;
V_173 -> V_132 = 0 ;
V_173 -> V_135 = 0 ;
V_173 -> V_138 = 0 ;
V_173 = ( T_9 * ) ( ( V_118 * ) V_173 + 1 ) ;
}
}
STATIC int
F_107 (
T_5 * V_34 ,
T_7 V_181 ,
T_14 V_182 ,
T_15 V_183 ,
T_4 V_71 )
{
T_13 * V_172 ;
int error ;
int type ;
ASSERT ( V_183 > 0 ) ;
type = V_71 & V_74 ? V_75 :
( V_71 & V_76 ? V_77 : V_79 ) ;
error = 0 ;
while ( V_183 -- ) {
error = F_108 ( V_34 , NULL , V_34 -> V_184 ,
F_109 ( V_34 , V_182 ) ,
V_34 -> V_42 -> V_115 , 0 , & V_172 ) ;
if ( error )
break;
F_103 ( V_34 , V_172 , V_181 , type ) ;
F_110 ( V_34 , V_172 ) ;
V_182 ++ ;
V_181 += V_34 -> V_42 -> V_117 ;
}
return error ;
}
STATIC int
F_111 (
T_5 * V_34 ,
T_6 * V_185 ,
T_4 V_71 )
{
T_16 * V_186 ;
int V_6 , V_187 ;
int error ;
T_17 V_188 ;
T_15 V_189 ;
T_7 V_181 ;
T_14 V_190 ;
T_15 V_191 ;
error = 0 ;
if ( V_185 -> V_100 . V_192 == 0 )
return 0 ;
V_186 = F_112 ( V_193 * sizeof( * V_186 ) , V_12 ) ;
V_188 = 0 ;
V_189 = F_113 ( V_34 , ( V_194 ) F_114 ( V_34 ) ) ;
do {
V_187 = V_193 ;
F_77 ( V_185 , V_195 ) ;
error = F_115 ( NULL , V_185 , V_188 ,
V_189 - V_188 ,
V_196 ,
NULL ,
0 , V_186 , & V_187 , NULL ) ;
F_78 ( V_185 , V_195 ) ;
if ( error )
break;
ASSERT ( V_187 <= V_193 ) ;
for ( V_6 = 0 ; V_6 < V_187 ; V_6 ++ ) {
ASSERT ( V_186 [ V_6 ] . V_197 != V_198 ) ;
ASSERT ( V_186 [ V_6 ] . V_199 ) ;
V_188 += V_186 [ V_6 ] . V_199 ;
if ( V_186 [ V_6 ] . V_197 == V_200 )
continue;
V_181 = ( T_7 ) V_186 [ V_6 ] . V_201 *
V_34 -> V_42 -> V_117 ;
if ( ( V_6 + 1 < V_187 ) &&
( V_186 [ V_6 + 1 ] . V_197 != V_200 ) ) {
V_191 = V_186 [ V_6 + 1 ] . V_199 ;
V_190 = V_186 [ V_6 + 1 ] . V_197 ;
while ( V_191 -- ) {
F_116 ( V_34 -> V_184 ,
F_109 ( V_34 , V_190 ) ,
V_34 -> V_42 -> V_115 ) ;
V_190 ++ ;
}
}
if ( ( error = F_107 ( V_34 ,
V_181 ,
V_186 [ V_6 ] . V_197 ,
V_186 [ V_6 ] . V_199 ,
V_71 ) ) ) {
break;
}
}
if ( error )
break;
} while ( V_187 > 0 );
F_23 ( V_186 ) ;
return error ;
}
STATIC int
F_117 (
struct V_107 * V_83 ,
T_7 V_84 ,
T_4 type ,
T_18 V_202 ,
T_18 V_203 )
{
struct V_33 * V_34 = V_83 -> V_91 ;
struct V_28 * V_29 ;
int error ;
error = F_65 ( V_34 , V_83 , V_84 , type ,
V_102 | V_92 , & V_29 ) ;
if ( error ) {
ASSERT ( error != V_204 ) ;
ASSERT ( error != V_205 ) ;
return error ;
}
F_118 ( V_29 ) ;
F_119 ( & V_29 -> V_89 . V_179 , 1 ) ;
V_29 -> V_206 ++ ;
if ( V_202 ) {
F_119 ( & V_29 -> V_89 . V_178 , V_202 ) ;
V_29 -> V_207 += V_202 ;
}
if ( V_203 ) {
F_119 ( & V_29 -> V_89 . V_180 , V_203 ) ;
V_29 -> V_208 += V_203 ;
}
if ( V_29 -> V_89 . V_90 ) {
F_120 ( V_34 , & V_29 -> V_89 ) ;
F_121 ( V_34 , & V_29 -> V_89 ) ;
}
V_29 -> V_37 |= V_209 ;
F_55 ( V_29 ) ;
return 0 ;
}
STATIC int
F_122 (
T_6 * V_83 ,
T_18 * V_210 )
{
T_15 V_203 ;
T_19 V_211 ;
T_20 * V_212 ;
T_19 V_213 ;
int error ;
ASSERT ( F_123 ( V_83 ) ) ;
V_212 = F_124 ( V_83 , V_214 ) ;
if ( ! ( V_212 -> V_215 & V_216 ) ) {
if ( ( error = F_125 ( NULL , V_83 , V_214 ) ) )
return error ;
}
V_203 = 0 ;
V_213 = V_212 -> V_217 / ( T_4 ) sizeof( V_218 ) ;
for ( V_211 = 0 ; V_211 < V_213 ; V_211 ++ )
V_203 += F_126 ( F_127 ( V_212 , V_211 ) ) ;
* V_210 = ( T_18 ) V_203 ;
return 0 ;
}
STATIC int
F_128 (
T_5 * V_34 ,
T_21 V_219 ,
void T_22 * V_220 ,
int V_221 ,
int * V_222 ,
int * V_223 )
{
T_6 * V_83 ;
T_18 V_202 , V_203 = 0 ;
int error ;
ASSERT ( F_33 ( V_34 ) ) ;
if ( V_219 == V_34 -> V_45 . V_98 || V_219 == V_34 -> V_45 . V_99 ) {
* V_223 = V_224 ;
return F_129 ( V_225 ) ;
}
error = F_130 ( V_34 , NULL , V_219 , 0 , V_88 , & V_83 ) ;
if ( error ) {
* V_223 = V_224 ;
return error ;
}
ASSERT ( V_83 -> V_226 == 0 ) ;
if ( F_123 ( V_83 ) ) {
error = F_122 ( V_83 , & V_203 ) ;
if ( error )
goto V_227;
}
V_202 = ( T_18 ) V_83 -> V_100 . V_192 - V_203 ;
if ( F_37 ( V_34 ) ) {
error = F_117 ( V_83 , V_83 -> V_100 . V_101 ,
V_75 , V_202 , V_203 ) ;
if ( error )
goto V_227;
}
if ( F_38 ( V_34 ) ) {
error = F_117 ( V_83 , V_83 -> V_100 . V_105 ,
V_79 , V_202 , V_203 ) ;
if ( error )
goto V_227;
}
if ( F_39 ( V_34 ) ) {
error = F_117 ( V_83 , F_74 ( V_83 ) ,
V_77 , V_202 , V_203 ) ;
if ( error )
goto V_227;
}
F_78 ( V_83 , V_88 ) ;
F_47 ( V_83 ) ;
* V_223 = V_228 ;
return 0 ;
V_227:
F_78 ( V_83 , V_88 ) ;
F_47 ( V_83 ) ;
* V_223 = V_229 ;
return error ;
}
int
F_36 (
T_5 * V_34 )
{
int V_104 , V_230 , error ;
T_21 V_231 ;
T_3 V_232 ;
T_6 * V_233 , * V_234 ;
T_4 V_71 ;
V_230 = V_235 ;
V_232 = 1 ;
V_231 = 0 ;
V_71 = 0 ;
ASSERT ( V_34 -> V_42 -> V_59 || V_34 -> V_42 -> V_60 ) ;
ASSERT ( F_33 ( V_34 ) ) ;
ASSERT ( F_27 ( & V_34 -> V_42 -> V_112 ) ) ;
F_32 ( V_34 , L_10 ) ;
V_233 = V_34 -> V_42 -> V_59 ;
if ( V_233 ) {
error = F_111 ( V_34 , V_233 , V_74 ) ;
if ( error )
goto V_236;
V_71 |= V_49 ;
}
V_234 = V_34 -> V_42 -> V_60 ;
if ( V_234 ) {
error = F_111 ( V_34 , V_234 , F_38 ( V_34 ) ?
V_78 : V_76 ) ;
if ( error )
goto V_236;
V_71 |= V_50 ;
}
do {
error = F_131 ( V_34 , & V_231 , & V_230 ,
F_128 ,
V_232 , NULL , & V_104 ) ;
if ( error )
break;
} while ( ! V_104 );
if ( ! error )
error = F_48 ( V_34 , 0 ) ;
if ( error ) {
F_29 ( V_34 , V_43 ) ;
goto V_236;
}
F_132 ( V_34 -> V_184 ) ;
V_34 -> V_47 &= ~ ( V_50 | V_49 ) ;
V_34 -> V_47 |= V_71 ;
V_236:
if ( error ) {
F_44 ( V_34 ,
L_11 ,
error ) ;
ASSERT ( V_34 -> V_42 != NULL ) ;
ASSERT ( V_32 != NULL ) ;
F_30 ( V_34 ) ;
if ( F_133 ( V_34 ) ) {
F_44 ( V_34 ,
L_12 ) ;
}
} else
F_32 ( V_34 , L_13 ) ;
return ( error ) ;
}
STATIC int
F_83 (
T_5 * V_34 )
{
T_6 * V_233 , * V_234 ;
int error ;
T_11 V_237 ;
T_4 V_71 ;
ASSERT ( V_34 -> V_42 ) ;
V_233 = V_234 = NULL ;
V_237 = 0 ;
V_71 = 0 ;
if ( F_99 ( & V_34 -> V_45 ) ) {
if ( F_37 ( V_34 ) &&
V_34 -> V_45 . V_98 != V_171 ) {
ASSERT ( V_34 -> V_45 . V_98 > 0 ) ;
if ( ( error = F_130 ( V_34 , NULL , V_34 -> V_45 . V_98 ,
0 , 0 , & V_233 ) ) )
return F_129 ( error ) ;
}
if ( F_73 ( V_34 ) &&
V_34 -> V_45 . V_99 != V_171 ) {
ASSERT ( V_34 -> V_45 . V_99 > 0 ) ;
if ( ( error = F_130 ( V_34 , NULL , V_34 -> V_45 . V_99 ,
0 , 0 , & V_234 ) ) ) {
if ( V_233 )
F_47 ( V_233 ) ;
return F_129 ( error ) ;
}
}
} else {
V_71 |= V_167 ;
V_237 |= ( V_168 | V_169 |
V_170 | V_54 ) ;
}
if ( F_37 ( V_34 ) && V_233 == NULL ) {
if ( ( error = F_92 ( V_34 , & V_233 ,
V_237 | V_169 ,
V_71 | V_74 ) ) )
return F_129 ( error ) ;
V_71 &= ~ V_167 ;
}
if ( F_73 ( V_34 ) && V_234 == NULL ) {
V_71 |= ( F_38 ( V_34 ) ?
V_78 : V_76 ) ;
error = F_92 ( V_34 , & V_234 ,
V_237 | V_170 , V_71 ) ;
if ( error ) {
if ( V_233 )
F_47 ( V_233 ) ;
return F_129 ( error ) ;
}
}
V_34 -> V_42 -> V_59 = V_233 ;
V_34 -> V_42 -> V_60 = V_234 ;
return 0 ;
}
STATIC V_20 *
F_134 ( void )
{
V_20 * V_238 ;
V_20 * V_29 ;
int V_108 ;
int V_239 ;
V_108 = 0 ;
V_238 = NULL ;
V_65:
V_239 = 0 ;
F_15 ( & V_32 -> V_18 ) ;
F_49 (dqp, &xfs_Gqm->qm_dqfrlist, q_freelist) {
struct V_33 * V_34 = V_29 -> V_39 ;
F_17 ( V_29 ) ;
if ( V_29 -> V_37 & V_240 ) {
ASSERT ( ! ( V_29 -> V_37 & V_38 ) ) ;
F_135 ( V_29 ) ;
F_136 ( V_241 . V_242 ) ;
V_108 ++ ;
V_239 = 1 ;
goto V_243;
}
if ( V_29 -> V_37 & V_38 ) {
ASSERT ( V_34 == NULL ) ;
ASSERT ( ! F_26 ( V_29 ) ) ;
ASSERT ( F_27 ( & V_29 -> V_40 ) ) ;
ASSERT ( F_27 ( & V_29 -> V_41 ) ) ;
F_18 ( & V_29 -> V_31 ) ;
V_32 -> V_17 -- ;
V_238 = V_29 ;
F_136 ( V_241 . V_244 ) ;
goto V_243;
}
ASSERT ( V_29 -> V_80 ) ;
ASSERT ( ! F_27 ( & V_29 -> V_41 ) ) ;
if ( ! F_50 ( V_29 ) )
goto V_243;
if ( F_26 ( V_29 ) ) {
int error ;
F_137 ( V_29 ) ;
error = F_52 ( V_29 , 0 ) ;
if ( error ) {
F_44 ( V_34 , L_14 ,
V_55 , V_29 ) ;
}
goto V_243;
}
if ( ! F_57 ( & V_29 -> V_80 -> V_81 ) ) {
V_108 ++ ;
goto V_245;
}
if ( ! F_57 ( & V_34 -> V_42 -> V_66 ) ) {
V_108 ++ ;
V_239 = 1 ;
goto V_246;
}
ASSERT ( V_29 -> V_247 == 0 ) ;
F_18 ( & V_29 -> V_41 ) ;
V_34 -> V_42 -> V_248 -- ;
V_34 -> V_42 -> V_67 ++ ;
F_18 ( & V_29 -> V_40 ) ;
V_29 -> V_80 -> V_156 ++ ;
F_18 ( & V_29 -> V_31 ) ;
V_32 -> V_17 -- ;
V_238 = V_29 ;
F_21 ( & V_34 -> V_42 -> V_66 ) ;
V_246:
F_21 ( & V_29 -> V_80 -> V_81 ) ;
V_245:
F_138 ( V_29 ) ;
V_243:
F_19 ( V_29 ) ;
if ( V_238 )
break;
if ( V_108 >= V_249 )
break;
if ( V_239 ) {
F_21 ( & V_32 -> V_18 ) ;
goto V_65;
}
}
F_21 ( & V_32 -> V_18 ) ;
return V_238 ;
}
STATIC int
F_139 (
int V_250 )
{
int V_251 = 0 ;
V_20 * V_29 ;
if ( V_250 <= 0 )
return 0 ;
while ( V_251 < V_250 ) {
V_29 = F_134 () ;
if ( ! V_29 )
return V_251 ;
F_20 ( V_29 ) ;
V_251 ++ ;
}
return V_251 ;
}
STATIC int
F_140 (
struct V_252 * V_253 ,
struct V_254 * V_255 )
{
int V_256 , V_257 , V_30 ;
T_23 V_258 = V_255 -> V_258 ;
if ( ! F_141 ( V_258 ) )
return 0 ;
if ( ! V_32 )
return 0 ;
V_257 = V_32 -> V_17 ;
V_256 = F_142 ( & V_32 -> V_24 ) - V_257 ;
ASSERT ( V_256 >= 0 ) ;
if ( V_257 <= V_256 && V_257 < V_11 )
return 0 ;
V_256 *= V_32 -> V_25 ;
V_30 = V_257 - V_256 - V_11 ;
return F_139 ( F_143 ( V_257 , V_30 ) ) ;
}
T_24
F_144 (
V_20 * * V_259 )
{
V_20 * V_29 ;
if ( F_142 ( & V_32 -> V_24 ) >= V_11 ) {
if ( ( V_29 = F_134 () ) ) {
F_136 ( V_241 . V_260 ) ;
memset ( & V_29 -> V_89 , 0 , sizeof( V_29 -> V_89 ) ) ;
* V_259 = V_29 ;
return V_261 ;
}
F_136 ( V_241 . V_262 ) ;
}
ASSERT ( V_32 -> V_19 != NULL ) ;
* V_259 = F_145 ( V_32 -> V_19 , V_12 ) ;
F_146 ( & V_32 -> V_24 ) ;
return V_263 ;
}
int
F_42 (
T_5 * V_34 ,
T_11 V_71 )
{
T_12 * V_159 ;
int error ;
V_159 = F_93 ( V_34 , V_264 ) ;
if ( ( error = F_94 ( V_159 , 0 ,
V_34 -> V_45 . V_265 + 128 , 0 ,
0 ,
V_266 ) ) ) {
F_97 ( V_159 , 0 ) ;
return error ;
}
F_101 ( V_159 , V_71 ) ;
error = F_102 ( V_159 , 0 ) ;
return error ;
}
int
F_147 (
struct V_107 * V_83 ,
T_25 V_267 ,
T_26 V_268 ,
T_27 V_269 ,
T_4 V_71 ,
struct V_28 * * V_270 ,
struct V_28 * * V_271 )
{
struct V_33 * V_34 = V_83 -> V_91 ;
struct V_28 * V_272 , * V_273 ;
int error ;
T_4 V_274 ;
if ( ! F_33 ( V_34 ) || ! F_71 ( V_34 ) )
return 0 ;
V_274 = V_88 ;
F_77 ( V_83 , V_274 ) ;
if ( ( V_71 & V_275 ) && F_148 ( V_83 ) )
V_268 = V_83 -> V_100 . V_105 ;
if ( F_72 ( V_34 , V_83 ) ) {
error = F_70 ( V_83 , V_102 ) ;
if ( error ) {
F_78 ( V_83 , V_274 ) ;
return error ;
}
}
V_272 = V_273 = NULL ;
if ( ( V_71 & V_74 ) && F_37 ( V_34 ) ) {
if ( V_83 -> V_100 . V_101 != V_267 ) {
F_78 ( V_83 , V_274 ) ;
if ( ( error = F_65 ( V_34 , NULL , ( T_7 ) V_267 ,
V_75 ,
V_102 |
V_92 ,
& V_272 ) ) ) {
ASSERT ( error != V_205 ) ;
return error ;
}
F_19 ( V_272 ) ;
V_274 = V_195 ;
F_77 ( V_83 , V_274 ) ;
} else {
ASSERT ( V_83 -> V_103 ) ;
V_272 = V_83 -> V_103 ;
F_17 ( V_272 ) ;
F_64 ( V_272 ) ;
F_19 ( V_272 ) ;
}
}
if ( ( V_71 & V_78 ) && F_38 ( V_34 ) ) {
if ( V_83 -> V_100 . V_105 != V_268 ) {
F_78 ( V_83 , V_274 ) ;
if ( ( error = F_65 ( V_34 , NULL , ( T_7 ) V_268 ,
V_79 ,
V_102 |
V_92 ,
& V_273 ) ) ) {
if ( V_272 )
F_68 ( V_272 ) ;
ASSERT ( error != V_205 ) ;
return error ;
}
F_19 ( V_273 ) ;
V_274 = V_195 ;
F_77 ( V_83 , V_274 ) ;
} else {
ASSERT ( V_83 -> V_106 ) ;
V_273 = V_83 -> V_106 ;
F_17 ( V_273 ) ;
F_64 ( V_273 ) ;
F_19 ( V_273 ) ;
}
} else if ( ( V_71 & V_76 ) && F_39 ( V_34 ) ) {
if ( F_74 ( V_83 ) != V_269 ) {
F_78 ( V_83 , V_274 ) ;
if ( ( error = F_65 ( V_34 , NULL , ( T_7 ) V_269 ,
V_77 ,
V_102 |
V_92 ,
& V_273 ) ) ) {
if ( V_272 )
F_68 ( V_272 ) ;
ASSERT ( error != V_205 ) ;
return ( error ) ;
}
F_19 ( V_273 ) ;
V_274 = V_195 ;
F_77 ( V_83 , V_274 ) ;
} else {
ASSERT ( V_83 -> V_106 ) ;
V_273 = V_83 -> V_106 ;
F_17 ( V_273 ) ;
F_64 ( V_273 ) ;
F_19 ( V_273 ) ;
}
}
if ( V_272 )
F_149 ( V_83 ) ;
F_78 ( V_83 , V_274 ) ;
if ( V_270 )
* V_270 = V_272 ;
else if ( V_272 )
F_68 ( V_272 ) ;
if ( V_271 )
* V_271 = V_273 ;
else if ( V_273 )
F_68 ( V_273 ) ;
return 0 ;
}
V_20 *
F_150 (
T_12 * V_159 ,
T_6 * V_83 ,
V_20 * * V_276 ,
V_20 * V_277 )
{
V_20 * V_278 ;
T_4 V_279 = F_123 ( V_83 ) ?
V_280 : V_281 ;
ASSERT ( F_61 ( V_83 , V_88 ) ) ;
ASSERT ( F_33 ( V_83 -> V_91 ) ) ;
V_278 = * V_276 ;
ASSERT ( V_278 ) ;
ASSERT ( V_278 != V_277 ) ;
F_151 ( V_159 , V_278 , V_279 , - ( V_83 -> V_100 . V_192 ) ) ;
F_151 ( V_159 , V_278 , V_282 , - 1 ) ;
F_151 ( V_159 , V_277 , V_279 , V_83 -> V_100 . V_192 ) ;
F_151 ( V_159 , V_277 , V_282 , 1 ) ;
F_17 ( V_277 ) ;
F_64 ( V_277 ) ;
F_19 ( V_277 ) ;
* V_276 = V_277 ;
return V_278 ;
}
int
F_152 (
T_12 * V_159 ,
T_6 * V_83 ,
V_20 * V_283 ,
V_20 * V_68 ,
T_4 V_71 )
{
T_5 * V_34 = V_83 -> V_91 ;
T_4 V_284 , V_285 , V_286 = 0 ;
V_20 * V_287 , * V_288 , * V_289 , * V_290 ;
int error ;
ASSERT ( F_61 ( V_83 , V_88 | V_195 ) ) ;
ASSERT ( F_33 ( V_34 ) ) ;
V_284 = V_83 -> V_226 ;
V_289 = V_290 = V_287 = V_288 = NULL ;
V_285 = F_123 ( V_83 ) ?
V_291 : V_292 ;
if ( F_37 ( V_34 ) && V_283 &&
V_83 -> V_100 . V_101 != ( T_25 ) F_63 ( V_283 -> V_89 . V_90 ) ) {
V_289 = V_283 ;
if ( V_284 ) {
ASSERT ( V_83 -> V_103 ) ;
V_287 = V_83 -> V_103 ;
}
}
if ( F_73 ( V_83 -> V_91 ) && V_68 ) {
if ( F_39 ( V_83 -> V_91 ) &&
F_74 ( V_83 ) != F_63 ( V_68 -> V_89 . V_90 ) )
V_286 = V_293 ;
if ( V_286 ||
( F_38 ( V_83 -> V_91 ) &&
V_83 -> V_100 . V_105 != F_63 ( V_68 -> V_89 . V_90 ) ) ) {
V_290 = V_68 ;
if ( V_284 ) {
ASSERT ( V_83 -> V_106 ) ;
V_288 = V_83 -> V_106 ;
}
}
}
if ( ( error = F_153 ( V_159 , V_83 -> V_91 ,
V_289 , V_290 , V_83 -> V_100 . V_192 , 1 ,
V_71 | V_285 | V_286 ) ) )
return ( error ) ;
if ( V_284 ) {
ASSERT ( V_289 || V_290 ) ;
ASSERT ( V_287 || V_288 ) ;
if ( ( error = F_153 ( NULL , V_83 -> V_91 ,
V_289 , V_290 , ( T_18 ) V_284 , 0 ,
V_71 | V_285 | V_286 ) ) )
return ( error ) ;
F_153 ( NULL , V_83 -> V_91 ,
V_287 , V_288 , - ( ( T_18 ) V_284 ) , 0 ,
V_285 ) ;
}
return ( 0 ) ;
}
int
F_154 (
struct V_107 * * V_294 )
{
struct V_33 * V_34 = V_294 [ 0 ] -> V_91 ;
int V_6 ;
if ( ! F_33 ( V_34 ) || ! F_71 ( V_34 ) )
return 0 ;
for ( V_6 = 0 ; ( V_6 < 4 && V_294 [ V_6 ] ) ; V_6 ++ ) {
struct V_107 * V_83 = V_294 [ V_6 ] ;
int error ;
if ( V_6 == 0 || V_83 != V_294 [ V_6 - 1 ] ) {
if ( F_72 ( V_34 , V_83 ) ) {
error = F_76 ( V_83 , 0 ) ;
if ( error )
return error ;
}
}
}
return 0 ;
}
void
F_155 (
struct V_295 * V_159 ,
struct V_107 * V_83 ,
struct V_28 * V_283 ,
struct V_28 * V_68 )
{
struct V_33 * V_34 = V_159 -> V_296 ;
if ( ! F_33 ( V_34 ) || ! F_71 ( V_34 ) )
return;
ASSERT ( F_61 ( V_83 , V_88 ) ) ;
ASSERT ( F_33 ( V_34 ) ) ;
if ( V_283 ) {
F_17 ( V_283 ) ;
F_64 ( V_283 ) ;
F_19 ( V_283 ) ;
ASSERT ( V_83 -> V_103 == NULL ) ;
V_83 -> V_103 = V_283 ;
ASSERT ( F_37 ( V_34 ) ) ;
ASSERT ( V_83 -> V_100 . V_101 == F_63 ( V_283 -> V_89 . V_90 ) ) ;
F_151 ( V_159 , V_283 , V_282 , 1 ) ;
}
if ( V_68 ) {
F_17 ( V_68 ) ;
F_64 ( V_68 ) ;
F_19 ( V_68 ) ;
ASSERT ( V_83 -> V_106 == NULL ) ;
V_83 -> V_106 = V_68 ;
ASSERT ( F_73 ( V_34 ) ) ;
ASSERT ( ( F_38 ( V_34 ) ?
V_83 -> V_100 . V_105 : F_74 ( V_83 ) ) ==
F_63 ( V_68 -> V_89 . V_90 ) ) ;
F_151 ( V_159 , V_68 , V_282 , 1 ) ;
}
}
