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
V_4 = F_4 ( sizeof( T_2 ) , V_11 ) ;
V_4 -> V_12 = V_5 - 1 ;
V_4 -> V_13 = V_2 ;
V_4 -> V_14 = V_3 ;
ASSERT ( V_4 -> V_13 != NULL ) ;
ASSERT ( V_4 -> V_14 != NULL ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
F_5 ( & ( V_4 -> V_13 [ V_6 ] ) , L_1 , V_6 ) ;
F_5 ( & ( V_4 -> V_14 [ V_6 ] ) , L_2 , V_6 ) ;
}
F_6 ( & V_4 -> V_15 ) ;
V_4 -> V_16 = 0 ;
F_7 ( & V_4 -> V_17 ) ;
if ( ! V_18 ) {
V_4 -> V_18 = F_8 ( sizeof( V_19 ) ,
L_3 ) ;
V_18 = V_4 -> V_18 ;
} else
V_4 -> V_18 = V_18 ;
F_9 ( & V_20 ) ;
if ( ! V_21 ) {
V_4 -> V_21 = F_8 ( sizeof( V_22 ) ,
L_4 ) ;
V_21 = V_4 -> V_21 ;
} else
V_4 -> V_21 = V_21 ;
F_10 ( & V_4 -> V_23 , 0 ) ;
V_4 -> V_24 = 0 ;
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
int V_5 , V_6 ;
ASSERT ( V_4 != NULL ) ;
ASSERT ( V_4 -> V_24 == 0 ) ;
F_13 ( & V_20 ) ;
F_14 ( & V_4 -> V_17 ) ;
ASSERT ( F_15 ( & V_4 -> V_15 ) ) ;
F_16 ( & V_4 -> V_17 ) ;
V_5 = V_4 -> V_12 + 1 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
F_17 ( & ( V_4 -> V_13 [ V_6 ] ) ) ;
F_17 ( & ( V_4 -> V_14 [ V_6 ] ) ) ;
}
F_11 ( V_4 -> V_13 ) ;
F_11 ( V_4 -> V_14 ) ;
V_4 -> V_13 = NULL ;
V_4 -> V_14 = NULL ;
V_4 -> V_12 = 0 ;
F_18 ( V_4 ) ;
}
STATIC int
F_19 (
struct V_25 * V_26 )
{
F_14 ( & V_27 ) ;
if ( ! V_28 ) {
V_28 = F_1 () ;
if ( ! V_28 ) {
F_16 ( & V_27 ) ;
return V_29 ;
}
}
V_28 -> V_24 ++ ;
F_16 ( & V_27 ) ;
return 0 ;
}
STATIC void
F_20 (
struct V_25 * V_26 )
{
ASSERT ( V_28 ) ;
ASSERT ( V_28 -> V_24 > 0 ) ;
F_14 ( & V_27 ) ;
if ( -- V_28 -> V_24 == 0 ) {
F_12 ( V_28 ) ;
V_28 = NULL ;
}
F_16 ( & V_27 ) ;
}
void
F_21 (
struct V_25 * V_26 )
{
if ( V_26 -> V_30 ) {
F_22 ( V_26 , V_31 ) ;
F_23 ( V_26 ) ;
}
}
void
F_24 (
T_5 * V_26 )
{
int error = 0 ;
T_4 V_32 ;
if ( V_26 -> V_33 . V_34 ) {
F_25 ( V_26 , L_5 ) ;
V_26 -> V_35 = 0 ;
goto V_36;
}
ASSERT ( F_26 ( V_26 ) ) ;
error = F_27 ( V_26 ) ;
if ( error ) {
ASSERT ( V_26 -> V_30 == NULL ) ;
V_26 -> V_35 = 0 ;
goto V_36;
}
if ( F_28 ( V_26 ) ) {
error = F_29 ( V_26 ) ;
if ( error ) {
return;
}
}
if ( ! F_30 ( V_26 ) )
V_26 -> V_35 &= ~ V_37 ;
if ( ! ( F_31 ( V_26 ) || F_32 ( V_26 ) ) )
V_26 -> V_35 &= ~ V_38 ;
V_36:
F_33 ( & V_26 -> V_39 ) ;
V_32 = V_26 -> V_33 . V_40 ;
V_26 -> V_33 . V_40 = V_26 -> V_35 & V_41 ;
F_34 ( & V_26 -> V_39 ) ;
if ( V_32 != ( V_26 -> V_35 & V_41 ) ) {
if ( F_35 ( V_26 , V_42 ) ) {
ASSERT ( ! ( F_26 ( V_26 ) ) ) ;
F_36 ( V_26 , L_6 ,
V_43 ) ;
}
}
if ( error ) {
F_37 ( V_26 , L_7 ) ;
return;
}
}
void
F_38 (
T_5 * V_26 )
{
ASSERT ( V_26 -> V_44 ) ;
F_39 ( V_26 -> V_44 ) ;
if ( V_26 -> V_45 )
F_39 ( V_26 -> V_45 ) ;
if ( V_26 -> V_46 )
F_39 ( V_26 -> V_46 ) ;
if ( V_26 -> V_30 ) {
if ( V_26 -> V_30 -> V_47 ) {
F_40 ( V_26 -> V_30 -> V_47 ) ;
V_26 -> V_30 -> V_47 = NULL ;
}
if ( V_26 -> V_30 -> V_48 ) {
F_40 ( V_26 -> V_30 -> V_48 ) ;
V_26 -> V_30 -> V_48 = NULL ;
}
}
}
STATIC int
F_41 (
struct V_25 * V_26 )
{
struct V_49 * V_50 = V_26 -> V_30 ;
int V_51 ;
struct V_52 * V_53 ;
int error ;
if ( ! V_50 )
return 0 ;
V_54:
F_14 ( & V_50 -> V_55 ) ;
F_42 (dqp, &q->qi_dqlist, q_mplist) {
F_43 ( V_53 ) ;
if ( ( V_53 -> V_56 & V_57 ) ||
! F_44 ( V_53 ) ) {
F_45 ( V_53 ) ;
continue;
}
V_51 = V_50 -> V_58 ;
if ( ! F_46 ( V_53 ) ) {
F_47 ( V_53 ) ;
}
F_16 ( & V_50 -> V_55 ) ;
error = F_48 ( V_53 , 0 ) ;
F_45 ( V_53 ) ;
if ( error )
return error ;
F_14 ( & V_50 -> V_55 ) ;
if ( V_51 != V_50 -> V_58 ) {
F_16 ( & V_50 -> V_55 ) ;
goto V_54;
}
}
F_16 ( & V_50 -> V_55 ) ;
return 0 ;
}
STATIC void
F_49 (
struct V_25 * V_26 )
{
struct V_49 * V_50 = V_26 -> V_30 ;
struct V_52 * V_53 , * V_59 ;
V_54:
ASSERT ( F_50 ( & V_50 -> V_55 ) ) ;
F_42 (dqp, &q->qi_dqlist, q_mplist) {
F_43 ( V_53 ) ;
if ( V_53 -> V_56 & V_57 ) {
F_45 ( V_53 ) ;
F_16 ( & V_50 -> V_55 ) ;
F_51 ( 1 ) ;
F_14 ( & V_50 -> V_55 ) ;
goto V_54;
}
V_59 = V_53 -> V_60 ;
if ( V_59 )
V_53 -> V_60 = NULL ;
F_45 ( V_53 ) ;
if ( V_59 )
F_52 ( V_59 ) ;
}
}
STATIC int
F_53 (
struct V_25 * V_26 ,
T_4 V_61 )
{
struct V_49 * V_50 = V_26 -> V_30 ;
struct V_52 * V_53 , * V_62 ;
T_4 V_63 ;
int V_64 = 0 ;
F_54 ( V_65 ) ;
if ( ! V_50 )
return 0 ;
V_63 = ( V_61 & V_66 ) ? V_67 : 0 ;
V_63 |= ( V_61 & V_68 ) ? V_69 : 0 ;
V_63 |= ( V_61 & V_70 ) ? V_71 : 0 ;
F_14 ( & V_50 -> V_55 ) ;
F_49 ( V_26 ) ;
F_55 (dqp, n, &q->qi_dqlist, q_mplist) {
F_43 ( V_53 ) ;
if ( ( V_53 -> V_56 & V_63 ) != 0 &&
! ( V_53 -> V_56 & V_57 ) ) {
if ( V_53 -> V_72 == 0 ) {
V_53 -> V_56 |= V_57 ;
F_56 ( & V_53 -> V_73 , & V_65 ) ;
} else
V_64 ++ ;
}
F_45 ( V_53 ) ;
}
F_16 ( & V_50 -> V_55 ) ;
F_55 (dqp, n, &dispose_list, q_mplist)
F_57 ( V_53 ) ;
return V_64 ;
}
int
F_22 (
T_5 * V_26 ,
T_4 V_61 )
{
int V_74 ;
if ( V_26 -> V_30 ) {
while ( ( V_74 = F_53 ( V_26 , V_61 ) ) ) {
F_51 ( V_74 * 10 ) ;
}
}
return 0 ;
}
STATIC int
F_58 (
T_6 * V_75 ,
T_7 V_76 ,
T_4 type ,
T_4 V_77 ,
V_19 * V_78 ,
V_19 * * V_79 )
{
V_19 * V_53 ;
int error ;
ASSERT ( F_59 ( V_75 , V_80 ) ) ;
error = 0 ;
V_53 = * V_79 ;
if ( V_53 ) {
F_60 ( V_53 ) ;
return 0 ;
}
if ( V_78 ) {
ASSERT ( type == V_71 || type == V_69 ) ;
F_43 ( V_78 ) ;
V_53 = V_78 -> V_60 ;
if ( V_53 && F_61 ( V_53 -> V_81 . V_82 ) == V_76 ) {
ASSERT ( * V_79 == NULL ) ;
* V_79 = F_62 ( V_53 ) ;
F_45 ( V_78 ) ;
return 0 ;
}
F_45 ( V_78 ) ;
}
error = F_63 ( V_75 -> V_83 , V_75 , V_76 , type ,
V_77 | V_84 , & V_53 ) ;
if ( error )
return error ;
F_64 ( V_53 ) ;
* V_79 = V_53 ;
F_45 ( V_53 ) ;
return 0 ;
}
STATIC void
F_65 (
V_19 * V_85 ,
V_19 * V_86 )
{
V_19 * V_87 ;
F_43 ( V_85 ) ;
V_87 = V_85 -> V_60 ;
if ( V_87 ) {
if ( V_87 == V_86 )
goto V_88;
V_85 -> V_60 = NULL ;
F_52 ( V_87 ) ;
}
V_85 -> V_60 = F_62 ( V_86 ) ;
V_88:
F_45 ( V_85 ) ;
}
int
F_66 (
T_6 * V_75 ,
T_4 V_61 )
{
T_5 * V_26 = V_75 -> V_83 ;
T_4 V_89 = 0 ;
int error = 0 ;
if ( ! F_26 ( V_26 ) ||
! F_67 ( V_26 ) ||
! F_68 ( V_26 , V_75 ) ||
V_75 -> V_90 == V_26 -> V_33 . V_91 ||
V_75 -> V_90 == V_26 -> V_33 . V_92 )
return 0 ;
ASSERT ( F_59 ( V_75 , V_80 ) ) ;
if ( F_30 ( V_26 ) ) {
error = F_58 ( V_75 , V_75 -> V_93 . V_94 , V_67 ,
V_61 & V_95 ,
NULL , & V_75 -> V_96 ) ;
if ( error )
goto V_88;
V_89 ++ ;
}
ASSERT ( F_59 ( V_75 , V_80 ) ) ;
if ( F_69 ( V_26 ) ) {
error = F_31 ( V_26 ) ?
F_58 ( V_75 , V_75 -> V_93 . V_97 , V_71 ,
V_61 & V_95 ,
V_75 -> V_96 , & V_75 -> V_98 ) :
F_58 ( V_75 , F_70 ( V_75 ) , V_69 ,
V_61 & V_95 ,
V_75 -> V_96 , & V_75 -> V_98 ) ;
if ( error )
goto V_88;
V_89 ++ ;
}
if ( V_89 == 2 ) {
ASSERT ( F_59 ( V_75 , V_80 ) ) ;
ASSERT ( V_75 -> V_96 ) ;
ASSERT ( V_75 -> V_98 ) ;
if ( V_75 -> V_96 -> V_60 != V_75 -> V_98 )
F_65 ( V_75 -> V_96 , V_75 -> V_98 ) ;
}
V_88:
#ifdef F_71
if ( ! error ) {
if ( F_30 ( V_26 ) )
ASSERT ( V_75 -> V_96 ) ;
if ( F_69 ( V_26 ) )
ASSERT ( V_75 -> V_98 ) ;
}
ASSERT ( F_59 ( V_75 , V_80 ) ) ;
#endif
return error ;
}
int
F_72 (
struct V_99 * V_75 ,
T_4 V_61 )
{
int error ;
F_73 ( V_75 , V_80 ) ;
error = F_66 ( V_75 , V_61 ) ;
F_74 ( V_75 , V_80 ) ;
return error ;
}
void
F_39 (
T_6 * V_75 )
{
if ( ! ( V_75 -> V_96 || V_75 -> V_98 ) )
return;
F_75 ( V_75 ) ;
ASSERT ( V_75 -> V_90 != V_75 -> V_83 -> V_33 . V_91 ) ;
ASSERT ( V_75 -> V_90 != V_75 -> V_83 -> V_33 . V_92 ) ;
if ( V_75 -> V_96 ) {
F_52 ( V_75 -> V_96 ) ;
V_75 -> V_96 = NULL ;
}
if ( V_75 -> V_98 ) {
F_52 ( V_75 -> V_98 ) ;
V_75 -> V_98 = NULL ;
}
}
STATIC int
F_27 (
T_5 * V_26 )
{
T_8 * V_100 ;
int error ;
V_19 * V_53 ;
ASSERT ( F_26 ( V_26 ) ) ;
if ( ( error = F_19 ( V_26 ) ) ) {
return error ;
}
V_100 = V_26 -> V_30 = F_4 ( sizeof( T_8 ) , V_11 ) ;
if ( ( error = F_76 ( V_26 ) ) ) {
F_18 ( V_100 ) ;
V_26 -> V_30 = NULL ;
return error ;
}
F_6 ( & V_100 -> V_101 ) ;
F_7 ( & V_100 -> V_55 ) ;
F_77 ( & V_100 -> V_55 , & V_102 ) ;
V_100 -> V_58 = 0 ;
F_7 ( & V_100 -> V_103 ) ;
V_100 -> V_104 = F_78 ( V_26 , V_105 ) ;
ASSERT ( V_100 -> V_104 ) ;
V_100 -> V_106 = F_79 ( V_100 -> V_104 ) ;
F_80 ( V_100 -> V_106 , sizeof( V_107 ) ) ;
V_26 -> V_35 |= ( V_26 -> V_33 . V_40 & V_108 ) ;
error = F_81 ( V_26 , 0 ,
F_82 ( V_26 ) ? V_67 :
( F_83 ( V_26 ) ? V_71 :
V_69 ) ,
V_84 , & V_53 ) ;
if ( ! error ) {
T_9 * V_109 = & V_53 -> V_81 ;
V_100 -> V_110 = V_109 -> V_111 ?
F_61 ( V_109 -> V_111 ) : V_112 ;
V_100 -> V_113 = V_109 -> V_114 ?
F_61 ( V_109 -> V_114 ) : V_115 ;
V_100 -> V_116 = V_109 -> V_117 ?
F_61 ( V_109 -> V_117 ) : V_118 ;
V_100 -> V_119 = V_109 -> V_120 ?
F_84 ( V_109 -> V_120 ) : V_121 ;
V_100 -> V_122 = V_109 -> V_123 ?
F_84 ( V_109 -> V_123 ) : V_124 ;
V_100 -> V_125 = V_109 -> V_126 ?
F_84 ( V_109 -> V_126 ) : V_127 ;
V_100 -> V_128 = F_85 ( V_109 -> V_129 ) ;
V_100 -> V_130 = F_85 ( V_109 -> V_131 ) ;
V_100 -> V_132 = F_85 ( V_109 -> V_133 ) ;
V_100 -> V_134 = F_85 ( V_109 -> V_135 ) ;
V_100 -> V_136 = F_85 ( V_109 -> V_137 ) ;
V_100 -> V_138 = F_85 ( V_109 -> V_139 ) ;
F_86 ( V_53 ) ;
} else {
V_100 -> V_110 = V_112 ;
V_100 -> V_113 = V_115 ;
V_100 -> V_116 = V_118 ;
V_100 -> V_119 = V_121 ;
V_100 -> V_122 = V_124 ;
V_100 -> V_125 = V_127 ;
}
return 0 ;
}
void
F_23 (
T_5 * V_26 )
{
T_8 * V_140 ;
V_140 = V_26 -> V_30 ;
ASSERT ( V_140 != NULL ) ;
ASSERT ( V_28 != NULL ) ;
F_20 ( V_26 ) ;
ASSERT ( F_15 ( & V_140 -> V_101 ) ) ;
F_87 ( & V_140 -> V_55 ) ;
if ( V_140 -> V_47 ) {
F_40 ( V_140 -> V_47 ) ;
V_140 -> V_47 = NULL ;
}
if ( V_140 -> V_48 ) {
F_40 ( V_140 -> V_48 ) ;
V_140 -> V_48 = NULL ;
}
F_87 ( & V_140 -> V_103 ) ;
F_18 ( V_140 ) ;
V_26 -> V_30 = NULL ;
}
STATIC void
F_5 (
T_10 * V_141 ,
char * V_142 ,
int V_62 )
{
F_7 ( & V_141 -> V_143 ) ;
F_6 ( & V_141 -> V_144 ) ;
V_141 -> V_145 = 0 ;
V_141 -> V_146 = 0 ;
}
STATIC void
F_17 (
T_10 * V_141 )
{
F_87 ( & ( V_141 -> V_143 ) ) ;
}
STATIC int
F_88 (
T_5 * V_26 ,
T_6 * * V_75 ,
T_11 V_147 ,
T_4 V_61 )
{
T_12 * V_148 ;
int error ;
int V_149 ;
V_148 = F_89 ( V_26 , V_150 ) ;
if ( ( error = F_90 ( V_148 ,
F_91 ( V_26 ) ,
F_92 ( V_26 ) , 0 ,
V_151 ,
V_152 ) ) ) {
F_93 ( V_148 , 0 ) ;
return error ;
}
error = F_94 ( & V_148 , NULL , V_153 , 1 , 0 , 0 , 1 , V_75 , & V_149 ) ;
if ( error ) {
F_93 ( V_148 , V_154 |
V_155 ) ;
return error ;
}
F_33 ( & V_26 -> V_39 ) ;
if ( V_61 & V_156 ) {
ASSERT ( ! F_95 ( & V_26 -> V_33 ) ) ;
ASSERT ( ( V_147 & ( V_157 | V_158 |
V_159 | V_42 ) ) ==
( V_157 | V_158 |
V_159 | V_42 ) ) ;
F_96 ( & V_26 -> V_33 ) ;
V_26 -> V_33 . V_91 = V_160 ;
V_26 -> V_33 . V_92 = V_160 ;
V_26 -> V_33 . V_40 = 0 ;
}
if ( V_61 & V_66 )
V_26 -> V_33 . V_91 = ( * V_75 ) -> V_90 ;
else
V_26 -> V_33 . V_92 = ( * V_75 ) -> V_90 ;
F_34 ( & V_26 -> V_39 ) ;
F_97 ( V_148 , V_147 ) ;
if ( ( error = F_98 ( V_148 , V_154 ) ) ) {
F_36 ( V_26 , L_8 , V_43 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_99 (
T_5 * V_26 ,
T_13 * V_161 ,
T_7 V_76 ,
T_4 type )
{
T_9 * V_162 ;
int V_163 ;
F_100 ( V_161 , V_164 ) ;
#ifdef F_71
V_163 = F_101 ( V_26 , V_105 ) ;
F_80 ( V_163 , sizeof( V_107 ) ) ;
ASSERT ( V_26 -> V_30 -> V_106 == V_163 ) ;
#endif
V_162 = V_161 -> V_165 ;
for ( V_163 = 0 ; V_163 < V_26 -> V_30 -> V_106 ; V_163 ++ ) {
( void ) F_102 ( V_26 , V_162 , V_76 + V_163 , type , V_166 ,
L_9 ) ;
V_162 -> V_167 = 0 ;
V_162 -> V_168 = 0 ;
V_162 -> V_169 = 0 ;
V_162 -> V_111 = 0 ;
V_162 -> V_114 = 0 ;
V_162 -> V_117 = 0 ;
V_162 -> V_120 = 0 ;
V_162 -> V_123 = 0 ;
V_162 -> V_126 = 0 ;
V_162 = ( T_9 * ) ( ( V_107 * ) V_162 + 1 ) ;
}
}
STATIC int
F_103 (
T_5 * V_26 ,
T_7 V_170 ,
T_14 V_171 ,
T_15 V_172 ,
T_4 V_61 )
{
T_13 * V_161 ;
int error ;
int type ;
ASSERT ( V_172 > 0 ) ;
type = V_61 & V_66 ? V_67 :
( V_61 & V_68 ? V_69 : V_71 ) ;
error = 0 ;
while ( V_172 -- ) {
error = F_104 ( V_26 , NULL , V_26 -> V_173 ,
F_105 ( V_26 , V_171 ) ,
V_26 -> V_30 -> V_104 , 0 , & V_161 ) ;
if ( error )
break;
F_99 ( V_26 , V_161 , V_170 , type ) ;
F_106 ( V_161 ) ;
F_107 ( V_161 ) ;
V_171 ++ ;
V_170 += V_26 -> V_30 -> V_106 ;
}
return error ;
}
STATIC int
F_108 (
T_5 * V_26 ,
T_6 * V_174 ,
T_4 V_61 )
{
T_16 * V_175 ;
int V_6 , V_176 ;
int error ;
T_17 V_177 ;
T_15 V_178 ;
T_7 V_170 ;
T_14 V_179 ;
T_15 V_180 ;
error = 0 ;
if ( V_174 -> V_93 . V_181 == 0 )
return 0 ;
V_175 = F_109 ( V_182 * sizeof( * V_175 ) , V_11 ) ;
V_177 = 0 ;
V_178 = F_110 ( V_26 , ( V_183 ) F_111 ( V_26 ) ) ;
do {
V_176 = V_182 ;
F_73 ( V_174 , V_184 ) ;
error = F_112 ( V_174 , V_177 , V_178 - V_177 ,
V_175 , & V_176 , 0 ) ;
F_74 ( V_174 , V_184 ) ;
if ( error )
break;
ASSERT ( V_176 <= V_182 ) ;
for ( V_6 = 0 ; V_6 < V_176 ; V_6 ++ ) {
ASSERT ( V_175 [ V_6 ] . V_185 != V_186 ) ;
ASSERT ( V_175 [ V_6 ] . V_187 ) ;
V_177 += V_175 [ V_6 ] . V_187 ;
if ( V_175 [ V_6 ] . V_185 == V_188 )
continue;
V_170 = ( T_7 ) V_175 [ V_6 ] . V_189 *
V_26 -> V_30 -> V_106 ;
if ( ( V_6 + 1 < V_176 ) &&
( V_175 [ V_6 + 1 ] . V_185 != V_188 ) ) {
V_180 = V_175 [ V_6 + 1 ] . V_187 ;
V_179 = V_175 [ V_6 + 1 ] . V_185 ;
while ( V_180 -- ) {
F_113 ( V_26 -> V_173 ,
F_105 ( V_26 , V_179 ) ,
V_26 -> V_30 -> V_104 ) ;
V_179 ++ ;
}
}
if ( ( error = F_103 ( V_26 ,
V_170 ,
V_175 [ V_6 ] . V_185 ,
V_175 [ V_6 ] . V_187 ,
V_61 ) ) ) {
break;
}
}
if ( error )
break;
} while ( V_176 > 0 );
F_18 ( V_175 ) ;
return error ;
}
STATIC int
F_114 (
struct V_99 * V_75 ,
T_7 V_76 ,
T_4 type ,
T_18 V_190 ,
T_18 V_191 )
{
struct V_25 * V_26 = V_75 -> V_83 ;
struct V_52 * V_53 ;
int error ;
error = F_63 ( V_26 , V_75 , V_76 , type ,
V_95 | V_84 , & V_53 ) ;
if ( error ) {
ASSERT ( error != V_192 ) ;
ASSERT ( error != V_193 ) ;
return error ;
}
F_115 ( V_53 ) ;
F_116 ( & V_53 -> V_81 . V_168 , 1 ) ;
V_53 -> V_194 ++ ;
if ( V_190 ) {
F_116 ( & V_53 -> V_81 . V_167 , V_190 ) ;
V_53 -> V_195 += V_190 ;
}
if ( V_191 ) {
F_116 ( & V_53 -> V_81 . V_169 , V_191 ) ;
V_53 -> V_196 += V_191 ;
}
if ( V_53 -> V_81 . V_82 ) {
F_117 ( V_26 , & V_53 -> V_81 ) ;
F_118 ( V_26 , & V_53 -> V_81 ) ;
}
V_53 -> V_56 |= V_197 ;
F_119 ( V_53 ) ;
return 0 ;
}
STATIC int
F_120 (
T_6 * V_75 ,
T_18 * V_198 )
{
T_15 V_191 ;
T_19 V_199 ;
T_20 * V_200 ;
T_19 V_201 ;
int error ;
ASSERT ( F_121 ( V_75 ) ) ;
V_200 = F_122 ( V_75 , V_202 ) ;
if ( ! ( V_200 -> V_203 & V_204 ) ) {
if ( ( error = F_123 ( NULL , V_75 , V_202 ) ) )
return error ;
}
V_191 = 0 ;
V_201 = V_200 -> V_205 / ( T_4 ) sizeof( V_206 ) ;
for ( V_199 = 0 ; V_199 < V_201 ; V_199 ++ )
V_191 += F_124 ( F_125 ( V_200 , V_199 ) ) ;
* V_198 = ( T_18 ) V_191 ;
return 0 ;
}
STATIC int
F_126 (
T_5 * V_26 ,
T_21 V_207 ,
void T_22 * V_208 ,
int V_209 ,
int * V_210 ,
int * V_211 )
{
T_6 * V_75 ;
T_18 V_190 , V_191 = 0 ;
int error ;
ASSERT ( F_26 ( V_26 ) ) ;
if ( V_207 == V_26 -> V_33 . V_91 || V_207 == V_26 -> V_33 . V_92 ) {
* V_211 = V_212 ;
return F_127 ( V_213 ) ;
}
error = F_128 ( V_26 , NULL , V_207 , 0 , V_80 , & V_75 ) ;
if ( error ) {
* V_211 = V_212 ;
return error ;
}
ASSERT ( V_75 -> V_214 == 0 ) ;
if ( F_121 ( V_75 ) ) {
error = F_120 ( V_75 , & V_191 ) ;
if ( error )
goto V_215;
}
V_190 = ( T_18 ) V_75 -> V_93 . V_181 - V_191 ;
if ( F_30 ( V_26 ) ) {
error = F_114 ( V_75 , V_75 -> V_93 . V_94 ,
V_67 , V_190 , V_191 ) ;
if ( error )
goto V_215;
}
if ( F_31 ( V_26 ) ) {
error = F_114 ( V_75 , V_75 -> V_93 . V_97 ,
V_71 , V_190 , V_191 ) ;
if ( error )
goto V_215;
}
if ( F_32 ( V_26 ) ) {
error = F_114 ( V_75 , F_70 ( V_75 ) ,
V_69 , V_190 , V_191 ) ;
if ( error )
goto V_215;
}
F_74 ( V_75 , V_80 ) ;
F_40 ( V_75 ) ;
* V_211 = V_216 ;
return 0 ;
V_215:
F_74 ( V_75 , V_80 ) ;
F_40 ( V_75 ) ;
* V_211 = V_217 ;
return error ;
}
int
F_29 (
T_5 * V_26 )
{
int V_88 , V_218 , error ;
T_21 V_219 ;
T_3 V_220 ;
T_6 * V_221 , * V_222 ;
T_4 V_61 ;
V_218 = V_223 ;
V_220 = 1 ;
V_219 = 0 ;
V_61 = 0 ;
ASSERT ( V_26 -> V_30 -> V_47 || V_26 -> V_30 -> V_48 ) ;
ASSERT ( F_26 ( V_26 ) ) ;
ASSERT ( F_15 ( & V_26 -> V_30 -> V_101 ) ) ;
F_25 ( V_26 , L_10 ) ;
V_221 = V_26 -> V_30 -> V_47 ;
if ( V_221 ) {
error = F_108 ( V_26 , V_221 , V_66 ) ;
if ( error )
goto V_224;
V_61 |= V_37 ;
}
V_222 = V_26 -> V_30 -> V_48 ;
if ( V_222 ) {
error = F_108 ( V_26 , V_222 , F_31 ( V_26 ) ?
V_70 : V_68 ) ;
if ( error )
goto V_224;
V_61 |= V_38 ;
}
do {
error = F_129 ( V_26 , & V_219 , & V_218 ,
F_126 ,
V_220 , NULL , & V_88 ) ;
if ( error )
break;
} while ( ! V_88 );
if ( ! error )
error = F_41 ( V_26 ) ;
if ( error ) {
F_22 ( V_26 , V_31 ) ;
goto V_224;
}
F_130 ( V_26 -> V_173 , 1 ) ;
V_26 -> V_35 &= ~ ( V_38 | V_37 ) ;
V_26 -> V_35 |= V_61 ;
V_224:
if ( error ) {
F_37 ( V_26 ,
L_11 ,
error ) ;
ASSERT ( V_26 -> V_30 != NULL ) ;
ASSERT ( V_28 != NULL ) ;
F_23 ( V_26 ) ;
if ( F_131 ( V_26 ) ) {
F_37 ( V_26 ,
L_12 ) ;
}
} else
F_25 ( V_26 , L_13 ) ;
return ( error ) ;
}
STATIC int
F_76 (
T_5 * V_26 )
{
T_6 * V_221 , * V_222 ;
int error ;
T_11 V_225 ;
T_4 V_61 ;
ASSERT ( V_26 -> V_30 ) ;
V_221 = V_222 = NULL ;
V_225 = 0 ;
V_61 = 0 ;
if ( F_95 ( & V_26 -> V_33 ) ) {
if ( F_30 ( V_26 ) &&
V_26 -> V_33 . V_91 != V_160 ) {
ASSERT ( V_26 -> V_33 . V_91 > 0 ) ;
if ( ( error = F_128 ( V_26 , NULL , V_26 -> V_33 . V_91 ,
0 , 0 , & V_221 ) ) )
return F_127 ( error ) ;
}
if ( F_69 ( V_26 ) &&
V_26 -> V_33 . V_92 != V_160 ) {
ASSERT ( V_26 -> V_33 . V_92 > 0 ) ;
if ( ( error = F_128 ( V_26 , NULL , V_26 -> V_33 . V_92 ,
0 , 0 , & V_222 ) ) ) {
if ( V_221 )
F_40 ( V_221 ) ;
return F_127 ( error ) ;
}
}
} else {
V_61 |= V_156 ;
V_225 |= ( V_157 | V_158 |
V_159 | V_42 ) ;
}
if ( F_30 ( V_26 ) && V_221 == NULL ) {
if ( ( error = F_88 ( V_26 , & V_221 ,
V_225 | V_158 ,
V_61 | V_66 ) ) )
return F_127 ( error ) ;
V_61 &= ~ V_156 ;
}
if ( F_69 ( V_26 ) && V_222 == NULL ) {
V_61 |= ( F_31 ( V_26 ) ?
V_70 : V_68 ) ;
error = F_88 ( V_26 , & V_222 ,
V_225 | V_159 , V_61 ) ;
if ( error ) {
if ( V_221 )
F_40 ( V_221 ) ;
return F_127 ( error ) ;
}
}
V_26 -> V_30 -> V_47 = V_221 ;
V_26 -> V_30 -> V_48 = V_222 ;
return 0 ;
}
STATIC void
F_132 (
struct V_52 * V_53 )
{
struct V_25 * V_26 = V_53 -> V_226 ;
struct V_49 * V_140 = V_26 -> V_30 ;
F_14 ( & V_53 -> V_227 -> V_143 ) ;
F_133 ( & V_53 -> V_228 ) ;
V_53 -> V_227 -> V_145 ++ ;
F_16 ( & V_53 -> V_227 -> V_143 ) ;
F_14 ( & V_140 -> V_55 ) ;
F_133 ( & V_53 -> V_73 ) ;
V_140 -> V_229 -- ;
V_140 -> V_58 ++ ;
F_16 ( & V_140 -> V_55 ) ;
F_86 ( V_53 ) ;
}
STATIC void
F_134 (
struct V_52 * V_53 ,
struct V_230 * V_65 )
{
struct V_25 * V_26 = V_53 -> V_226 ;
int error ;
if ( ! F_135 ( V_53 ) )
goto V_231;
if ( V_53 -> V_72 ) {
F_45 ( V_53 ) ;
F_136 ( V_53 ) ;
F_137 ( V_232 . V_233 ) ;
F_133 ( & V_53 -> V_234 ) ;
V_28 -> V_16 -- ;
return;
}
ASSERT ( V_53 -> V_227 ) ;
ASSERT ( ! F_15 ( & V_53 -> V_73 ) ) ;
if ( ! F_46 ( V_53 ) )
goto V_231;
if ( F_44 ( V_53 ) ) {
F_138 ( V_53 ) ;
error = F_48 ( V_53 , 0 ) ;
if ( error ) {
F_37 ( V_26 , L_14 ,
V_43 , V_53 ) ;
}
goto V_231;
}
F_139 ( V_53 ) ;
V_53 -> V_56 |= V_57 ;
F_45 ( V_53 ) ;
ASSERT ( V_53 -> V_72 == 0 ) ;
F_56 ( & V_53 -> V_234 , V_65 ) ;
V_28 -> V_16 -- ;
F_140 ( V_53 ) ;
F_137 ( V_232 . V_235 ) ;
return;
V_231:
F_45 ( V_53 ) ;
F_56 ( & V_53 -> V_234 , & V_28 -> V_15 ) ;
F_141 ( V_53 ) ;
F_137 ( V_232 . V_236 ) ;
}
STATIC int
F_142 (
struct V_237 * V_238 ,
struct V_239 * V_240 )
{
int V_241 = V_240 -> V_241 ;
F_54 ( V_65 ) ;
struct V_52 * V_53 ;
if ( ( V_240 -> V_242 & ( V_243 | V_244 ) ) != ( V_243 | V_244 ) )
return 0 ;
if ( ! V_241 )
goto V_9;
F_14 ( & V_28 -> V_17 ) ;
while ( ! F_15 ( & V_28 -> V_15 ) ) {
if ( V_241 -- <= 0 )
break;
V_53 = F_143 ( & V_28 -> V_15 , struct V_52 ,
V_234 ) ;
F_134 ( V_53 , & V_65 ) ;
}
F_16 ( & V_28 -> V_17 ) ;
while ( ! F_15 ( & V_65 ) ) {
V_53 = F_143 ( & V_65 , struct V_52 ,
V_234 ) ;
F_133 ( & V_53 -> V_234 ) ;
F_132 ( V_53 ) ;
}
V_9:
return ( V_28 -> V_16 / 100 ) * V_245 ;
}
int
F_35 (
T_5 * V_26 ,
T_11 V_61 )
{
T_12 * V_148 ;
int error ;
V_148 = F_89 ( V_26 , V_246 ) ;
if ( ( error = F_90 ( V_148 , 0 ,
V_26 -> V_33 . V_247 + 128 , 0 ,
0 ,
V_248 ) ) ) {
F_93 ( V_148 , 0 ) ;
return error ;
}
F_97 ( V_148 , V_61 ) ;
error = F_98 ( V_148 , 0 ) ;
return error ;
}
int
F_144 (
struct V_99 * V_75 ,
T_23 V_249 ,
T_24 V_250 ,
T_25 V_251 ,
T_4 V_61 ,
struct V_52 * * V_252 ,
struct V_52 * * V_253 )
{
struct V_25 * V_26 = V_75 -> V_83 ;
struct V_52 * V_254 , * V_255 ;
int error ;
T_4 V_256 ;
if ( ! F_26 ( V_26 ) || ! F_67 ( V_26 ) )
return 0 ;
V_256 = V_80 ;
F_73 ( V_75 , V_256 ) ;
if ( ( V_61 & V_257 ) && F_145 ( V_75 ) )
V_250 = V_75 -> V_93 . V_97 ;
if ( F_68 ( V_26 , V_75 ) ) {
error = F_66 ( V_75 , V_95 ) ;
if ( error ) {
F_74 ( V_75 , V_256 ) ;
return error ;
}
}
V_254 = V_255 = NULL ;
if ( ( V_61 & V_66 ) && F_30 ( V_26 ) ) {
if ( V_75 -> V_93 . V_94 != V_249 ) {
F_74 ( V_75 , V_256 ) ;
if ( ( error = F_63 ( V_26 , NULL , ( T_7 ) V_249 ,
V_67 ,
V_95 |
V_84 ,
& V_254 ) ) ) {
ASSERT ( error != V_193 ) ;
return error ;
}
F_45 ( V_254 ) ;
V_256 = V_184 ;
F_73 ( V_75 , V_256 ) ;
} else {
ASSERT ( V_75 -> V_96 ) ;
V_254 = F_62 ( V_75 -> V_96 ) ;
}
}
if ( ( V_61 & V_70 ) && F_31 ( V_26 ) ) {
if ( V_75 -> V_93 . V_97 != V_250 ) {
F_74 ( V_75 , V_256 ) ;
if ( ( error = F_63 ( V_26 , NULL , ( T_7 ) V_250 ,
V_71 ,
V_95 |
V_84 ,
& V_255 ) ) ) {
if ( V_254 )
F_52 ( V_254 ) ;
ASSERT ( error != V_193 ) ;
return error ;
}
F_45 ( V_255 ) ;
V_256 = V_184 ;
F_73 ( V_75 , V_256 ) ;
} else {
ASSERT ( V_75 -> V_98 ) ;
V_255 = F_62 ( V_75 -> V_98 ) ;
}
} else if ( ( V_61 & V_68 ) && F_32 ( V_26 ) ) {
if ( F_70 ( V_75 ) != V_251 ) {
F_74 ( V_75 , V_256 ) ;
if ( ( error = F_63 ( V_26 , NULL , ( T_7 ) V_251 ,
V_69 ,
V_95 |
V_84 ,
& V_255 ) ) ) {
if ( V_254 )
F_52 ( V_254 ) ;
ASSERT ( error != V_193 ) ;
return ( error ) ;
}
F_45 ( V_255 ) ;
V_256 = V_184 ;
F_73 ( V_75 , V_256 ) ;
} else {
ASSERT ( V_75 -> V_98 ) ;
V_255 = F_62 ( V_75 -> V_98 ) ;
}
}
if ( V_254 )
F_146 ( V_75 ) ;
F_74 ( V_75 , V_256 ) ;
if ( V_252 )
* V_252 = V_254 ;
else if ( V_254 )
F_52 ( V_254 ) ;
if ( V_253 )
* V_253 = V_255 ;
else if ( V_255 )
F_52 ( V_255 ) ;
return 0 ;
}
V_19 *
F_147 (
T_12 * V_148 ,
T_6 * V_75 ,
V_19 * * V_258 ,
V_19 * V_259 )
{
V_19 * V_260 ;
T_4 V_261 = F_121 ( V_75 ) ?
V_262 : V_263 ;
ASSERT ( F_59 ( V_75 , V_80 ) ) ;
ASSERT ( F_26 ( V_75 -> V_83 ) ) ;
V_260 = * V_258 ;
ASSERT ( V_260 ) ;
ASSERT ( V_260 != V_259 ) ;
F_148 ( V_148 , V_260 , V_261 , - ( V_75 -> V_93 . V_181 ) ) ;
F_148 ( V_148 , V_260 , V_264 , - 1 ) ;
F_148 ( V_148 , V_259 , V_261 , V_75 -> V_93 . V_181 ) ;
F_148 ( V_148 , V_259 , V_264 , 1 ) ;
* V_258 = F_62 ( V_259 ) ;
return V_260 ;
}
int
F_149 (
T_12 * V_148 ,
T_6 * V_75 ,
V_19 * V_265 ,
V_19 * V_59 ,
T_4 V_61 )
{
T_5 * V_26 = V_75 -> V_83 ;
T_4 V_266 , V_267 , V_268 = 0 ;
V_19 * V_269 , * V_270 , * V_271 , * V_272 ;
int error ;
ASSERT ( F_59 ( V_75 , V_80 | V_184 ) ) ;
ASSERT ( F_26 ( V_26 ) ) ;
V_266 = V_75 -> V_214 ;
V_271 = V_272 = V_269 = V_270 = NULL ;
V_267 = F_121 ( V_75 ) ?
V_273 : V_274 ;
if ( F_30 ( V_26 ) && V_265 &&
V_75 -> V_93 . V_94 != ( T_23 ) F_61 ( V_265 -> V_81 . V_82 ) ) {
V_271 = V_265 ;
if ( V_266 ) {
ASSERT ( V_75 -> V_96 ) ;
V_269 = V_75 -> V_96 ;
}
}
if ( F_69 ( V_75 -> V_83 ) && V_59 ) {
if ( F_32 ( V_75 -> V_83 ) &&
F_70 ( V_75 ) != F_61 ( V_59 -> V_81 . V_82 ) )
V_268 = V_275 ;
if ( V_268 ||
( F_31 ( V_75 -> V_83 ) &&
V_75 -> V_93 . V_97 != F_61 ( V_59 -> V_81 . V_82 ) ) ) {
V_272 = V_59 ;
if ( V_266 ) {
ASSERT ( V_75 -> V_98 ) ;
V_270 = V_75 -> V_98 ;
}
}
}
if ( ( error = F_150 ( V_148 , V_75 -> V_83 ,
V_271 , V_272 , V_75 -> V_93 . V_181 , 1 ,
V_61 | V_267 | V_268 ) ) )
return ( error ) ;
if ( V_266 ) {
ASSERT ( V_271 || V_272 ) ;
ASSERT ( V_269 || V_270 ) ;
if ( ( error = F_150 ( NULL , V_75 -> V_83 ,
V_271 , V_272 , ( T_18 ) V_266 , 0 ,
V_61 | V_267 | V_268 ) ) )
return ( error ) ;
F_150 ( NULL , V_75 -> V_83 ,
V_269 , V_270 , - ( ( T_18 ) V_266 ) , 0 ,
V_267 ) ;
}
return ( 0 ) ;
}
int
F_151 (
struct V_99 * * V_276 )
{
struct V_25 * V_26 = V_276 [ 0 ] -> V_83 ;
int V_6 ;
if ( ! F_26 ( V_26 ) || ! F_67 ( V_26 ) )
return 0 ;
for ( V_6 = 0 ; ( V_6 < 4 && V_276 [ V_6 ] ) ; V_6 ++ ) {
struct V_99 * V_75 = V_276 [ V_6 ] ;
int error ;
if ( V_6 == 0 || V_75 != V_276 [ V_6 - 1 ] ) {
if ( F_68 ( V_26 , V_75 ) ) {
error = F_72 ( V_75 , 0 ) ;
if ( error )
return error ;
}
}
}
return 0 ;
}
void
F_152 (
struct V_277 * V_148 ,
struct V_99 * V_75 ,
struct V_52 * V_265 ,
struct V_52 * V_59 )
{
struct V_25 * V_26 = V_148 -> V_278 ;
if ( ! F_26 ( V_26 ) || ! F_67 ( V_26 ) )
return;
ASSERT ( F_59 ( V_75 , V_80 ) ) ;
ASSERT ( F_26 ( V_26 ) ) ;
if ( V_265 ) {
ASSERT ( V_75 -> V_96 == NULL ) ;
ASSERT ( F_30 ( V_26 ) ) ;
ASSERT ( V_75 -> V_93 . V_94 == F_61 ( V_265 -> V_81 . V_82 ) ) ;
V_75 -> V_96 = F_62 ( V_265 ) ;
F_148 ( V_148 , V_265 , V_264 , 1 ) ;
}
if ( V_59 ) {
ASSERT ( V_75 -> V_98 == NULL ) ;
ASSERT ( F_69 ( V_26 ) ) ;
ASSERT ( ( F_31 ( V_26 ) ?
V_75 -> V_93 . V_97 : F_70 ( V_75 ) ) ==
F_61 ( V_59 -> V_81 . V_82 ) ) ;
V_75 -> V_98 = F_62 ( V_59 ) ;
F_148 ( V_148 , V_59 , V_264 , 1 ) ;
}
}
