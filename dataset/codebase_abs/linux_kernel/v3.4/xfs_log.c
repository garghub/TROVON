static void
F_1 (
struct log * log ,
T_1 * V_1 ,
int V_2 )
{
T_2 V_3 = F_2 ( V_1 ) ;
T_2 V_4 , V_5 ;
do {
int V_6 , V_7 ;
F_3 ( V_3 , & V_6 , & V_7 ) ;
V_7 -= V_2 ;
if ( V_7 < 0 ) {
V_7 += log -> V_8 ;
V_6 -- ;
}
V_5 = V_3 ;
V_4 = F_4 ( V_6 , V_7 ) ;
V_3 = F_5 ( V_1 , V_5 , V_4 ) ;
} while ( V_3 != V_5 );
}
static void
F_6 (
struct log * log ,
T_1 * V_1 ,
int V_2 )
{
T_2 V_3 = F_2 ( V_1 ) ;
T_2 V_4 , V_5 ;
do {
int V_9 ;
int V_6 , V_7 ;
F_3 ( V_3 , & V_6 , & V_7 ) ;
V_9 = log -> V_8 - V_7 ;
if ( V_9 > V_2 )
V_7 += V_2 ;
else {
V_7 = V_2 - V_9 ;
V_6 ++ ;
}
V_5 = V_3 ;
V_4 = F_4 ( V_6 , V_7 ) ;
V_3 = F_5 ( V_1 , V_5 , V_4 ) ;
} while ( V_3 != V_5 );
}
STATIC void
F_7 (
struct V_10 * V_1 )
{
F_8 ( & V_1 -> V_11 , 1 , 0 ) ;
F_9 ( & V_1 -> V_12 ) ;
F_10 ( & V_1 -> V_13 ) ;
}
STATIC void
F_11 (
struct V_10 * V_1 )
{
struct V_14 * V_15 ;
F_12 ( & V_1 -> V_13 ) ;
F_13 (tic, &head->waiters, t_queue)
F_14 ( V_15 -> V_16 ) ;
F_15 ( & V_1 -> V_13 ) ;
}
static inline int
F_16 (
struct log * log ,
struct V_10 * V_1 ,
struct V_14 * V_15 )
{
if ( V_1 == & log -> V_17 ) {
ASSERT ( V_15 -> V_18 & V_19 ) ;
return V_15 -> V_20 ;
} else {
if ( V_15 -> V_18 & V_19 )
return V_15 -> V_20 * V_15 -> V_21 ;
else
return V_15 -> V_20 ;
}
}
STATIC bool
F_17 (
struct log * log ,
struct V_10 * V_1 ,
int * V_22 )
{
struct V_14 * V_15 ;
int V_23 ;
F_13 (tic, &head->waiters, t_queue) {
V_23 = F_16 ( log , V_1 , V_15 ) ;
if ( * V_22 < V_23 )
return false ;
* V_22 -= V_23 ;
F_18 ( log , V_15 ) ;
F_14 ( V_15 -> V_16 ) ;
}
return true ;
}
STATIC int
F_19 (
struct log * log ,
struct V_10 * V_1 ,
struct V_14 * V_15 ,
int V_23 )
{
F_20 ( & V_15 -> V_24 , & V_1 -> V_12 ) ;
do {
if ( F_21 ( log ) )
goto V_25;
F_22 ( log , V_23 ) ;
F_23 ( V_26 ) ;
F_15 ( & V_1 -> V_13 ) ;
F_24 ( V_27 ) ;
F_25 ( log , V_15 ) ;
F_26 () ;
F_27 ( log , V_15 ) ;
F_12 ( & V_1 -> V_13 ) ;
if ( F_21 ( log ) )
goto V_25;
} while ( F_28 ( log , & V_1 -> V_11 ) < V_23 );
F_29 ( & V_15 -> V_24 ) ;
return 0 ;
V_25:
F_29 ( & V_15 -> V_24 ) ;
return F_30 ( V_28 ) ;
}
STATIC int
F_31 (
struct log * log ,
struct V_10 * V_1 ,
struct V_14 * V_15 ,
int * V_23 )
{
int V_22 ;
int error = 0 ;
ASSERT ( ! ( log -> V_29 & V_30 ) ) ;
* V_23 = F_16 ( log , V_1 , V_15 ) ;
V_22 = F_28 ( log , & V_1 -> V_11 ) ;
if ( ! F_32 ( & V_1 -> V_12 ) ) {
F_12 ( & V_1 -> V_13 ) ;
if ( ! F_17 ( log , V_1 , & V_22 ) ||
V_22 < * V_23 ) {
error = F_19 ( log , V_1 , V_15 ,
* V_23 ) ;
}
F_15 ( & V_1 -> V_13 ) ;
} else if ( V_22 < * V_23 ) {
F_12 ( & V_1 -> V_13 ) ;
error = F_19 ( log , V_1 , V_15 , * V_23 ) ;
F_15 ( & V_1 -> V_13 ) ;
}
return error ;
}
static void
F_33 ( T_3 * V_15 )
{
V_15 -> V_31 = 0 ;
V_15 -> V_32 = 0 ;
V_15 -> V_33 = 0 ;
}
static void
F_34 ( T_3 * V_15 , T_4 V_34 , T_4 type )
{
if ( V_15 -> V_31 == V_35 ) {
V_15 -> V_36 += V_15 -> V_32 ;
V_15 -> V_31 = 0 ;
V_15 -> V_32 = 0 ;
}
V_15 -> V_37 [ V_15 -> V_31 ] . V_38 = V_34 ;
V_15 -> V_37 [ V_15 -> V_31 ] . V_39 = type ;
V_15 -> V_32 += V_34 ;
V_15 -> V_31 ++ ;
}
int
F_35 (
struct V_40 * V_41 ,
struct V_14 * V_15 )
{
struct log * log = V_41 -> V_42 ;
int V_23 ;
int error = 0 ;
if ( F_21 ( log ) )
return F_30 ( V_28 ) ;
F_24 ( V_43 ) ;
V_15 -> V_44 ++ ;
F_22 ( log , V_15 -> V_20 ) ;
V_15 -> V_45 = V_15 -> V_20 ;
F_33 ( V_15 ) ;
if ( V_15 -> V_21 > 0 )
return 0 ;
F_36 ( log , V_15 ) ;
error = F_31 ( log , & log -> V_17 , V_15 ,
& V_23 ) ;
if ( error )
goto V_46;
F_6 ( log , & log -> V_17 . V_11 , V_23 ) ;
F_37 ( log , V_15 ) ;
F_38 ( log ) ;
return 0 ;
V_46:
V_15 -> V_45 = 0 ;
V_15 -> V_21 = 0 ;
return error ;
}
int
F_39 (
struct V_40 * V_41 ,
int V_47 ,
int V_48 ,
struct V_14 * * V_49 ,
T_5 V_50 ,
bool V_51 ,
T_4 V_52 )
{
struct log * log = V_41 -> V_42 ;
struct V_14 * V_15 ;
int V_23 ;
int error = 0 ;
ASSERT ( V_50 == V_53 || V_50 == V_54 ) ;
if ( F_21 ( log ) )
return F_30 ( V_28 ) ;
F_24 ( V_43 ) ;
ASSERT ( * V_49 == NULL ) ;
V_15 = F_40 ( log , V_47 , V_48 , V_50 , V_51 ,
V_55 | V_56 ) ;
if ( ! V_15 )
return F_30 ( V_57 ) ;
V_15 -> V_58 = V_52 ;
* V_49 = V_15 ;
F_22 ( log , V_15 -> V_20 * V_15 -> V_21 ) ;
F_41 ( log , V_15 ) ;
error = F_31 ( log , & log -> V_59 , V_15 ,
& V_23 ) ;
if ( error )
goto V_46;
F_6 ( log , & log -> V_59 . V_11 , V_23 ) ;
F_6 ( log , & log -> V_17 . V_11 , V_23 ) ;
F_42 ( log , V_15 ) ;
F_38 ( log ) ;
return 0 ;
V_46:
V_15 -> V_45 = 0 ;
V_15 -> V_21 = 0 ;
return error ;
}
T_6
F_43 (
struct V_40 * V_41 ,
struct V_14 * V_60 ,
struct V_61 * * V_62 ,
T_4 V_63 )
{
struct log * log = V_41 -> V_42 ;
T_6 V_64 = 0 ;
if ( F_21 ( log ) ||
( ( ( V_60 -> V_18 & V_65 ) == 0 ) &&
( F_44 ( log , V_60 , V_62 , & V_64 ) ) ) ) {
V_64 = ( T_6 ) - 1 ;
if ( V_60 -> V_18 & V_19 ) {
V_63 |= V_66 ;
}
}
if ( ( V_60 -> V_18 & V_19 ) == 0 ||
( V_63 & V_66 ) ) {
F_45 ( log , V_60 ) ;
F_46 ( log , V_60 ) ;
F_47 ( V_60 ) ;
} else {
F_48 ( log , V_60 ) ;
F_49 ( log , V_60 ) ;
V_60 -> V_18 |= V_65 ;
}
return V_64 ;
}
int
F_50 (
struct V_40 * V_41 ,
struct V_61 * V_62 ,
T_7 * V_67 )
{
int V_68 ;
F_12 ( & V_62 -> V_69 ) ;
V_68 = ( V_62 -> V_70 & V_71 ) ;
if ( ! V_68 ) {
F_51 ( ( V_62 -> V_70 == V_72 ) ||
( V_62 -> V_70 == V_73 ) ) ;
V_67 -> V_74 = NULL ;
* ( V_62 -> V_75 ) = V_67 ;
V_62 -> V_75 = & ( V_67 -> V_74 ) ;
}
F_15 ( & V_62 -> V_69 ) ;
return V_68 ;
}
int
F_52 (
struct V_40 * V_41 ,
struct V_61 * V_62 )
{
if ( F_53 ( V_41 -> V_42 , V_62 ) ) {
F_54 ( V_41 , V_76 ) ;
return V_28 ;
}
return 0 ;
}
int
F_55 (
T_8 * V_41 ,
T_9 * V_77 ,
T_10 V_78 ,
int V_79 )
{
int error ;
if ( ! ( V_41 -> V_80 & V_81 ) )
F_56 ( V_41 , L_1 ) ;
else {
F_56 ( V_41 ,
L_2 ) ;
ASSERT ( V_41 -> V_80 & V_82 ) ;
}
V_41 -> V_42 = F_57 ( V_41 , V_77 , V_78 , V_79 ) ;
if ( F_58 ( V_41 -> V_42 ) ) {
error = - F_59 ( V_41 -> V_42 ) ;
goto V_83;
}
error = F_60 ( V_41 ) ;
if ( error ) {
F_61 ( V_41 , L_3 , error ) ;
goto V_84;
}
V_41 -> V_42 -> V_85 = V_41 -> V_86 ;
if ( ! ( V_41 -> V_80 & V_81 ) ) {
int V_87 = ( V_41 -> V_80 & V_82 ) ;
if ( V_87 )
V_41 -> V_80 &= ~ V_82 ;
error = F_62 ( V_41 -> V_42 ) ;
if ( V_87 )
V_41 -> V_80 |= V_82 ;
if ( error ) {
F_61 ( V_41 , L_4 ,
error ) ;
goto V_88;
}
}
V_41 -> V_42 -> V_29 &= ~ V_30 ;
F_63 ( V_41 -> V_42 ) ;
return 0 ;
V_88:
F_64 ( V_41 ) ;
V_84:
F_65 ( V_41 -> V_42 ) ;
V_83:
return error ;
}
int
F_66 ( T_8 * V_41 )
{
int error ;
if ( ! ( V_41 -> V_80 & V_81 ) )
error = F_67 ( V_41 -> V_42 ) ;
else {
error = 0 ;
ASSERT ( V_41 -> V_80 & V_82 ) ;
}
return error ;
}
int
F_68 ( T_8 * V_41 )
{
T_11 * log = V_41 -> V_42 ;
T_12 * V_62 ;
#ifdef F_69
T_12 * V_89 ;
#endif
T_3 * V_15 = NULL ;
T_6 V_64 ;
int error ;
if ( V_41 -> V_80 & V_82 )
return 0 ;
error = F_70 ( V_41 , V_90 , NULL ) ;
ASSERT ( error || ! ( F_21 ( log ) ) ) ;
#ifdef F_69
V_89 = V_62 = log -> V_91 ;
do {
if ( ! ( V_62 -> V_70 & V_71 ) ) {
ASSERT ( V_62 -> V_70 & V_72 ) ;
ASSERT ( V_62 -> V_92 == 0 ) ;
}
V_62 = V_62 -> V_93 ;
} while ( V_62 != V_89 );
#endif
if ( ! ( F_21 ( log ) ) ) {
error = F_39 ( V_41 , 600 , 1 , & V_15 ,
V_54 , 0 , V_94 ) ;
if ( ! error ) {
struct {
T_13 V_95 ;
T_13 V_96 ;
T_14 V_97 ;
} V_95 = {
. V_95 = V_98 ,
} ;
struct V_99 V_100 = {
. V_101 = & V_95 ,
. V_102 = sizeof( V_95 ) ,
. V_103 = V_104 ,
} ;
struct V_105 V_106 = {
. V_107 = 1 ,
. V_108 = & V_100 ,
} ;
V_15 -> V_18 = 0 ;
V_15 -> V_45 -= sizeof( V_95 ) ;
error = F_71 ( log , & V_106 , V_15 , & V_64 ,
NULL , V_109 ) ;
}
if ( error )
F_72 ( V_41 , L_5 , V_110 ) ;
F_12 ( & log -> V_111 ) ;
V_62 = log -> V_91 ;
F_73 ( & V_62 -> V_112 ) ;
F_74 ( log , V_62 ) ;
F_15 ( & log -> V_111 ) ;
error = F_53 ( log , V_62 ) ;
F_12 ( & log -> V_111 ) ;
if ( ! ( V_62 -> V_70 == V_72 ||
V_62 -> V_70 == V_113 ) ) {
if ( ! F_21 ( log ) ) {
F_75 ( & V_62 -> V_114 ,
& log -> V_111 ) ;
} else {
F_15 ( & log -> V_111 ) ;
}
} else {
F_15 ( & log -> V_111 ) ;
}
if ( V_15 ) {
F_76 ( log , V_15 ) ;
F_46 ( log , V_15 ) ;
F_47 ( V_15 ) ;
}
} else {
F_12 ( & log -> V_111 ) ;
V_62 = log -> V_91 ;
F_73 ( & V_62 -> V_112 ) ;
F_74 ( log , V_62 ) ;
F_15 ( & log -> V_111 ) ;
error = F_53 ( log , V_62 ) ;
F_12 ( & log -> V_111 ) ;
if ( ! ( V_62 -> V_70 == V_72
|| V_62 -> V_70 == V_113
|| V_62 -> V_70 == V_71 ) ) {
F_75 ( & V_62 -> V_114 ,
& log -> V_111 ) ;
} else {
F_15 ( & log -> V_111 ) ;
}
}
return error ;
}
void
F_77 ( T_8 * V_41 )
{
F_64 ( V_41 ) ;
F_65 ( V_41 -> V_42 ) ;
}
void
F_78 (
struct V_40 * V_41 ,
struct V_115 * V_116 ,
int type ,
const struct V_117 * V_118 )
{
V_116 -> V_119 = V_41 ;
V_116 -> V_120 = V_41 -> V_86 ;
V_116 -> V_121 = type ;
V_116 -> V_122 = V_118 ;
V_116 -> V_123 = NULL ;
F_9 ( & V_116 -> V_124 ) ;
F_9 ( & V_116 -> V_125 ) ;
}
void
F_79 (
struct V_40 * V_41 )
{
struct log * log = V_41 -> V_42 ;
int V_22 ;
if ( F_21 ( log ) )
return;
if ( ! F_32 ( & log -> V_17 . V_12 ) ) {
ASSERT ( ! ( log -> V_29 & V_30 ) ) ;
F_12 ( & log -> V_17 . V_13 ) ;
V_22 = F_28 ( log , & log -> V_17 . V_11 ) ;
F_17 ( log , & log -> V_17 , & V_22 ) ;
F_15 ( & log -> V_17 . V_13 ) ;
}
if ( ! F_32 ( & log -> V_59 . V_12 ) ) {
ASSERT ( ! ( log -> V_29 & V_30 ) ) ;
F_12 ( & log -> V_59 . V_13 ) ;
V_22 = F_28 ( log , & log -> V_59 . V_11 ) ;
F_17 ( log , & log -> V_59 , & V_22 ) ;
F_15 ( & log -> V_59 . V_13 ) ;
}
}
int
F_80 ( T_8 * V_41 )
{
int V_126 = 0 ;
T_11 * log = V_41 -> V_42 ;
if ( ! F_81 ( V_41 ) )
return 0 ;
F_12 ( & log -> V_111 ) ;
switch ( log -> V_127 ) {
case V_128 :
case V_129 :
case V_130 :
break;
case V_131 :
case V_132 :
if ( ! F_82 ( log -> V_85 ) &&
F_83 ( log ) ) {
if ( log -> V_127 == V_131 )
log -> V_127 = V_128 ;
else
log -> V_127 = V_129 ;
}
default:
V_126 = 1 ;
break;
}
F_15 ( & log -> V_111 ) ;
return V_126 ;
}
T_6
F_84 (
struct V_40 * V_41 )
{
T_6 V_133 ;
struct log * log = V_41 -> V_42 ;
V_133 = F_82 ( V_41 -> V_86 ) ;
if ( ! V_133 )
V_133 = F_2 ( & log -> V_134 ) ;
F_85 ( & log -> V_135 , V_133 ) ;
return V_133 ;
}
STATIC int
F_28 (
struct log * log ,
T_1 * V_1 )
{
int V_22 ;
int V_136 ;
int V_137 ;
int V_138 ;
int V_139 ;
F_86 ( V_1 , & V_138 , & V_139 ) ;
F_87 ( & log -> V_135 , & V_137 , & V_136 ) ;
V_136 = F_88 ( V_136 ) ;
if ( V_137 == V_138 && V_139 >= V_136 )
V_22 = log -> V_8 - ( V_139 - V_136 ) ;
else if ( V_137 + 1 < V_138 )
return 0 ;
else if ( V_137 < V_138 ) {
ASSERT ( V_137 == ( V_138 - 1 ) ) ;
V_22 = V_136 - V_139 ;
} else {
F_72 ( log -> V_140 ,
L_6
L_7
L_8 ,
V_137 , V_136 , V_138 , V_139 ) ;
ASSERT ( 0 ) ;
V_22 = log -> V_8 ;
}
return V_22 ;
}
void
F_89 ( T_15 * V_141 )
{
T_12 * V_62 = V_141 -> V_142 ;
T_11 * V_143 = V_62 -> V_144 ;
int V_145 = 0 ;
if ( F_90 ( ( F_91 ( V_141 ) ) , V_143 -> V_140 ,
V_146 , V_147 ) ) {
F_92 ( V_141 , V_110 ) ;
F_93 ( V_141 ) ;
F_54 ( V_143 -> V_140 , V_76 ) ;
V_145 = V_148 ;
} else if ( V_62 -> V_70 & V_71 ) {
V_145 = V_148 ;
}
ASSERT ( F_94 ( V_141 ) ) ;
F_95 ( V_62 , V_145 ) ;
}
STATIC void
F_96 ( T_8 * V_41 ,
T_11 * log )
{
int V_149 ;
int V_150 ;
if ( V_41 -> V_151 <= 0 )
log -> V_152 = V_153 ;
else
log -> V_152 = V_41 -> V_151 ;
if ( V_41 -> V_154 > 0 ) {
V_149 = log -> V_155 = V_41 -> V_154 ;
log -> V_156 = 0 ;
while ( V_149 != 1 ) {
log -> V_156 ++ ;
V_149 >>= 1 ;
}
if ( F_97 ( & V_41 -> V_157 ) ) {
V_150 = V_41 -> V_154 / V_158 ;
if ( V_41 -> V_154 % V_158 )
V_150 ++ ;
log -> V_159 = V_150 << V_160 ;
log -> V_161 = V_150 ;
} else {
ASSERT ( V_41 -> V_154 <= V_162 ) ;
log -> V_159 = V_163 ;
log -> V_161 = 1 ;
}
goto V_164;
}
log -> V_155 = V_162 ;
log -> V_156 = V_165 ;
log -> V_159 = V_163 ;
log -> V_161 = 1 ;
V_164:
if ( V_41 -> V_151 == 0 )
V_41 -> V_151 = log -> V_152 ;
if ( V_41 -> V_154 == 0 )
V_41 -> V_154 = log -> V_155 ;
}
STATIC T_11 *
F_57 ( T_8 * V_41 ,
T_9 * V_77 ,
T_10 V_78 ,
int V_79 )
{
T_11 * log ;
T_16 * V_1 ;
T_12 * * V_166 ;
T_12 * V_62 , * V_167 = NULL ;
T_15 * V_141 ;
int V_168 ;
int error = V_57 ;
T_4 V_169 = 0 ;
log = F_98 ( sizeof( T_11 ) , V_56 ) ;
if ( ! log ) {
F_61 ( V_41 , L_9 ) ;
goto V_83;
}
log -> V_140 = V_41 ;
log -> V_170 = V_77 ;
log -> V_8 = F_88 ( V_79 ) ;
log -> V_171 = V_78 ;
log -> V_172 = V_79 ;
log -> V_127 = V_130 ;
log -> V_29 |= V_30 ;
log -> V_173 = - 1 ;
F_99 ( & log -> V_135 , 1 , 0 ) ;
F_99 ( & log -> V_134 , 1 , 0 ) ;
log -> V_174 = 1 ;
F_7 ( & log -> V_59 ) ;
F_7 ( & log -> V_17 ) ;
error = V_175 ;
if ( F_100 ( & V_41 -> V_157 ) ) {
V_169 = V_41 -> V_157 . V_176 ;
if ( V_169 < V_160 ) {
F_61 ( V_41 , L_10 ,
V_169 , V_160 ) ;
goto V_84;
}
V_169 -= V_160 ;
if ( V_169 > V_41 -> V_177 ) {
F_61 ( V_41 , L_11 ,
V_169 , V_41 -> V_177 ) ;
goto V_84;
}
if ( V_169 && log -> V_171 > 0 &&
! F_97 ( & V_41 -> V_157 ) ) {
F_61 ( V_41 ,
L_12 ,
V_169 ) ;
goto V_84;
}
}
log -> V_178 = 1 << V_169 ;
F_96 ( V_41 , log ) ;
error = V_57 ;
V_141 = F_101 ( V_41 -> V_179 , 0 , log -> V_155 , 0 ) ;
if ( ! V_141 )
goto V_84;
V_141 -> V_180 = F_89 ;
ASSERT ( F_102 ( V_141 ) ) ;
log -> V_181 = V_141 ;
F_10 ( & log -> V_111 ) ;
F_103 ( & log -> V_182 ) ;
ASSERT ( ( F_104 ( V_141 ) & V_183 ) == 0 ) ;
V_166 = & log -> V_91 ;
ASSERT ( log -> V_155 >= 4096 ) ;
for ( V_168 = 0 ; V_168 < log -> V_152 ; V_168 ++ ) {
* V_166 = F_98 ( sizeof( T_12 ) , V_56 ) ;
if ( ! * V_166 )
goto V_184;
V_62 = * V_166 ;
V_62 -> V_185 = V_167 ;
V_167 = V_62 ;
V_141 = F_105 ( V_41 -> V_179 ,
log -> V_155 , 0 ) ;
if ( ! V_141 )
goto V_184;
V_141 -> V_180 = F_89 ;
V_62 -> V_186 = V_141 ;
V_62 -> V_187 = V_141 -> V_188 ;
#ifdef F_69
log -> V_189 [ V_168 ] = ( V_190 ) & ( V_62 -> V_191 ) ;
#endif
V_1 = & V_62 -> V_191 ;
memset ( V_1 , 0 , sizeof( T_16 ) ) ;
V_1 -> V_192 = F_106 ( V_193 ) ;
V_1 -> V_194 = F_106 (
F_97 ( & log -> V_140 -> V_157 ) ? 2 : 1 ) ;
V_1 -> V_195 = F_106 ( log -> V_155 ) ;
V_1 -> V_196 = F_106 ( V_197 ) ;
memcpy ( & V_1 -> V_198 , & V_41 -> V_157 . V_199 , sizeof( V_200 ) ) ;
V_62 -> V_201 = F_104 ( V_141 ) - log -> V_159 ;
V_62 -> V_70 = V_72 ;
V_62 -> V_144 = log ;
F_107 ( & V_62 -> V_112 , 0 ) ;
F_10 ( & V_62 -> V_69 ) ;
V_62 -> V_75 = & ( V_62 -> V_202 ) ;
V_62 -> V_203 = ( char * ) V_62 -> V_187 + log -> V_159 ;
ASSERT ( F_102 ( V_62 -> V_186 ) ) ;
F_103 ( & V_62 -> V_114 ) ;
F_103 ( & V_62 -> V_204 ) ;
V_166 = & V_62 -> V_93 ;
}
* V_166 = log -> V_91 ;
log -> V_91 -> V_185 = V_167 ;
error = F_108 ( log ) ;
if ( error )
goto V_184;
return log ;
V_184:
for ( V_62 = log -> V_91 ; V_62 ; V_62 = V_167 ) {
V_167 = V_62 -> V_93 ;
if ( V_62 -> V_186 )
F_109 ( V_62 -> V_186 ) ;
F_110 ( V_62 ) ;
}
F_111 ( & log -> V_111 ) ;
F_109 ( log -> V_181 ) ;
V_84:
F_110 ( log ) ;
V_83:
return F_112 ( - error ) ;
}
STATIC int
F_44 (
struct log * log ,
struct V_14 * V_60 ,
struct V_61 * * V_62 ,
T_6 * V_205 )
{
struct V_40 * V_41 = log -> V_140 ;
int error ;
struct V_99 V_100 = {
. V_101 = NULL ,
. V_102 = 0 ,
. V_103 = V_206 ,
} ;
struct V_105 V_106 = {
. V_107 = 1 ,
. V_108 = & V_100 ,
} ;
F_51 ( V_62 ) ;
error = F_71 ( log , & V_106 , V_60 , V_205 , V_62 ,
V_207 ) ;
if ( error )
F_54 ( V_41 , V_76 ) ;
return error ;
}
STATIC void
F_22 (
struct log * log ,
int V_23 )
{
T_6 V_208 = 0 ;
T_6 V_209 ;
int V_210 ;
int V_22 ;
int V_211 ;
int V_212 ;
int V_213 ;
ASSERT ( F_113 ( V_23 ) < log -> V_172 ) ;
V_22 = F_28 ( log , & log -> V_59 . V_11 ) ;
V_210 = F_114 ( V_22 ) ;
V_213 = F_113 ( V_23 ) ;
V_213 = F_115 ( V_213 , ( log -> V_172 >> 2 ) ) ;
V_213 = F_115 ( V_213 , 256 ) ;
if ( V_210 >= V_213 )
return;
F_87 ( & log -> V_135 , & V_212 ,
& V_211 ) ;
V_211 += V_213 ;
if ( V_211 >= log -> V_172 ) {
V_211 -= log -> V_172 ;
V_212 += 1 ;
}
V_208 = F_116 ( V_212 ,
V_211 ) ;
V_209 = F_2 ( & log -> V_134 ) ;
if ( F_117 ( V_208 , V_209 ) > 0 )
V_208 = V_209 ;
if ( ! F_21 ( log ) )
F_118 ( log -> V_85 , V_208 ) ;
}
STATIC int
F_119 (
struct V_214 * V_141 )
{
struct V_61 * V_62 = V_141 -> V_142 ;
if ( V_62 -> V_70 & V_71 ) {
F_120 ( V_141 , V_28 ) ;
F_93 ( V_141 ) ;
F_121 ( V_141 , 0 ) ;
return 0 ;
}
F_122 ( V_141 ) ;
return 0 ;
}
STATIC int
F_123 ( T_11 * log ,
T_12 * V_62 )
{
V_190 V_215 ;
T_15 * V_141 ;
int V_168 ;
T_4 V_216 ;
T_4 V_217 ;
int V_218 ;
int V_219 = 0 ;
int error ;
int V_220 = F_97 ( & log -> V_140 -> V_157 ) ;
F_24 ( V_221 ) ;
ASSERT ( F_124 ( & V_62 -> V_112 ) == 0 ) ;
V_217 = log -> V_159 + V_62 -> V_92 ;
if ( V_220 && log -> V_140 -> V_157 . V_222 > 1 ) {
V_216 = F_125 ( log , F_126 ( log , V_217 ) ) ;
} else {
V_216 = F_88 ( F_113 ( V_217 ) ) ;
}
V_218 = V_216 - V_217 ;
ASSERT ( V_218 >= 0 ) ;
ASSERT ( ( V_220 && log -> V_140 -> V_157 . V_222 > 1 &&
V_218 < log -> V_140 -> V_157 . V_222 )
||
( log -> V_140 -> V_157 . V_222 <= 1 &&
V_218 < F_88 ( 1 ) ) ) ;
F_6 ( log , & log -> V_59 . V_11 , V_218 ) ;
F_6 ( log , & log -> V_17 . V_11 , V_218 ) ;
F_127 ( log , V_62 , V_218 ) ;
if ( V_220 ) {
V_62 -> V_191 . V_223 =
F_106 ( V_62 -> V_92 + V_218 ) ;
} else {
V_62 -> V_191 . V_223 =
F_106 ( V_62 -> V_92 ) ;
}
V_141 = V_62 -> V_186 ;
F_128 ( V_141 , F_129 ( F_130 ( V_62 -> V_191 . V_224 ) ) ) ;
F_131 ( V_225 , F_113 ( V_216 ) ) ;
if ( F_132 ( V_141 ) + F_113 ( V_216 ) > log -> V_172 ) {
V_219 = V_216 - ( F_88 ( log -> V_172 - F_132 ( V_141 ) ) ) ;
V_216 = F_88 ( log -> V_172 - F_132 ( V_141 ) ) ;
V_62 -> V_226 = 2 ;
} else {
V_62 -> V_226 = 1 ;
}
F_133 ( V_141 , V_216 ) ;
V_141 -> V_142 = V_62 ;
F_134 ( V_141 ) ;
F_135 ( V_141 ) ;
V_141 -> V_227 |= V_228 ;
if ( log -> V_140 -> V_80 & V_229 ) {
V_141 -> V_227 |= V_230 ;
if ( log -> V_140 -> V_179 != log -> V_140 -> V_231 )
F_136 ( log -> V_140 -> V_231 ) ;
else
V_141 -> V_227 |= V_232 ;
}
ASSERT ( F_132 ( V_141 ) <= log -> V_172 - 1 ) ;
ASSERT ( F_132 ( V_141 ) + F_113 ( V_216 ) <= log -> V_172 ) ;
F_137 ( log , V_62 , V_216 , V_233 ) ;
F_128 ( V_141 , F_132 ( V_141 ) + log -> V_171 ) ;
F_138 ( V_141 ) ;
error = F_119 ( V_141 ) ;
if ( error ) {
F_92 ( V_141 , L_13 ) ;
return error ;
}
if ( V_219 ) {
V_141 = V_62 -> V_144 -> V_181 ;
F_128 ( V_141 , 0 ) ;
F_139 ( V_141 ,
( char * ) & V_62 -> V_191 + V_216 , V_219 ) ;
V_141 -> V_142 = V_62 ;
F_134 ( V_141 ) ;
F_135 ( V_141 ) ;
V_141 -> V_227 |= V_228 ;
if ( log -> V_140 -> V_80 & V_229 )
V_141 -> V_227 |= V_230 ;
V_215 = V_141 -> V_188 ;
for ( V_168 = 0 ; V_168 < V_219 ; V_168 += V_163 ) {
F_140 ( ( V_234 * ) V_215 , 1 ) ;
if ( F_141 ( * ( V_234 * ) V_215 ) == V_193 )
F_140 ( ( V_234 * ) V_215 , 1 ) ;
V_215 += V_163 ;
}
ASSERT ( F_132 ( V_141 ) <= log -> V_172 - 1 ) ;
ASSERT ( F_132 ( V_141 ) + F_113 ( V_216 ) <= log -> V_172 ) ;
F_128 ( V_141 , F_132 ( V_141 ) + log -> V_171 ) ;
F_138 ( V_141 ) ;
error = F_119 ( V_141 ) ;
if ( error ) {
F_92 ( V_141 , L_14 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_65 ( T_11 * log )
{
T_12 * V_62 , * V_235 ;
int V_168 ;
F_142 ( log ) ;
F_143 ( log -> V_181 , log -> V_155 ) ;
F_109 ( log -> V_181 ) ;
V_62 = log -> V_91 ;
for ( V_168 = 0 ; V_168 < log -> V_152 ; V_168 ++ ) {
F_109 ( V_62 -> V_186 ) ;
V_235 = V_62 -> V_93 ;
F_110 ( V_62 ) ;
V_62 = V_235 ;
}
F_111 ( & log -> V_111 ) ;
log -> V_140 -> V_42 = NULL ;
F_110 ( log ) ;
}
static inline void
F_144 ( T_11 * log ,
T_12 * V_62 ,
int V_236 ,
int V_237 )
{
F_12 ( & log -> V_111 ) ;
F_140 ( & V_62 -> V_191 . V_238 , V_236 ) ;
V_62 -> V_92 += V_237 ;
F_15 ( & log -> V_111 ) ;
}
void
F_145 (
struct V_40 * V_41 ,
struct V_14 * V_60 )
{
T_4 V_168 ;
T_4 V_239 = V_60 -> V_33 * ( T_4 ) sizeof( V_240 ) ;
static char * V_241 [ V_242 ] = {
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33
} ;
static char * V_243 [ V_244 ] = {
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
L_51 ,
L_52 ,
L_53 ,
L_54 ,
L_55 ,
L_56 ,
L_57 ,
L_58 ,
L_59 ,
L_60 ,
L_61 ,
L_62 ,
L_63 ,
L_64 ,
L_65 ,
L_66 ,
L_67 ,
L_68 ,
L_69 ,
L_70 ,
L_71 ,
L_72 ,
L_73
} ;
F_61 ( V_41 ,
L_74
L_75
L_76
L_77
L_78
L_79
L_80
L_81 ,
( ( V_60 -> V_58 <= 0 ||
V_60 -> V_58 > V_244 ) ?
L_82 : V_243 [ V_60 -> V_58 - 1 ] ) ,
V_60 -> V_58 ,
V_60 -> V_20 ,
V_60 -> V_45 ,
V_60 -> V_32 , V_60 -> V_36 ,
V_60 -> V_33 , V_239 ,
V_60 -> V_32 +
V_60 -> V_36 + V_239 ,
V_60 -> V_31 ) ;
for ( V_168 = 0 ; V_168 < V_60 -> V_31 ; V_168 ++ ) {
T_4 V_39 = V_60 -> V_37 [ V_168 ] . V_39 ;
F_61 ( V_41 , L_83 , V_168 ,
( ( V_39 <= 0 || V_39 > V_242 ) ?
L_84 : V_241 [ V_39 - 1 ] ) ,
V_60 -> V_37 [ V_168 ] . V_38 ) ;
}
F_146 ( V_41 , V_245 ,
L_85 ) ;
F_54 ( V_41 , V_246 ) ;
}
static int
F_147 (
struct V_14 * V_60 ,
struct V_105 * V_247 )
{
struct V_105 * V_248 ;
int V_249 = 0 ;
int V_34 = 0 ;
int V_168 ;
if ( V_60 -> V_18 & V_65 )
V_249 ++ ;
for ( V_248 = V_247 ; V_248 ; V_248 = V_248 -> V_250 ) {
V_249 += V_248 -> V_107 ;
for ( V_168 = 0 ; V_168 < V_248 -> V_107 ; V_168 ++ ) {
struct V_99 * V_251 = & V_248 -> V_108 [ V_168 ] ;
V_34 += V_251 -> V_102 ;
F_34 ( V_60 , V_251 -> V_102 , V_251 -> V_103 ) ;
}
}
V_60 -> V_33 += V_249 ;
V_34 += V_249 * sizeof( struct V_252 ) ;
return V_34 ;
}
static int
F_148 (
struct V_252 * V_253 ,
struct V_14 * V_60 )
{
if ( ! ( V_60 -> V_18 & V_65 ) )
return 0 ;
V_253 -> V_254 = F_106 ( V_60 -> V_44 ) ;
V_253 -> V_255 = V_60 -> V_256 ;
V_253 -> V_257 = 0 ;
V_253 -> V_258 = V_259 ;
V_253 -> V_260 = 0 ;
V_60 -> V_18 &= ~ V_65 ;
return sizeof( struct V_252 ) ;
}
static V_240 *
F_149 (
struct log * log ,
struct V_252 * V_253 ,
struct V_14 * V_60 ,
T_4 V_63 )
{
V_253 -> V_254 = F_106 ( V_60 -> V_44 ) ;
V_253 -> V_255 = V_60 -> V_256 ;
V_253 -> V_260 = 0 ;
V_253 -> V_258 = V_63 ;
switch ( V_253 -> V_255 ) {
case V_53 :
case V_261 :
case V_54 :
break;
default:
F_61 ( log -> V_140 ,
L_86 ,
V_253 -> V_255 , V_60 ) ;
return NULL ;
}
return V_253 ;
}
static int
F_150 (
struct V_14 * V_60 ,
struct V_252 * V_253 ,
int V_262 ,
int V_263 ,
int * V_264 ,
int * V_265 ,
int * V_266 ,
int * V_267 )
{
int V_268 ;
V_268 = V_263 - * V_267 ;
* V_264 = * V_267 ;
if ( V_268 <= V_262 ) {
* V_265 = V_268 ;
V_253 -> V_257 = F_106 ( * V_265 ) ;
if ( * V_266 )
V_253 -> V_258 |= ( V_269 | V_270 ) ;
* V_266 = 0 ;
* V_267 = 0 ;
return 0 ;
}
* V_265 = V_262 ;
V_253 -> V_257 = F_106 ( * V_265 ) ;
V_253 -> V_258 |= V_271 ;
if ( * V_266 )
V_253 -> V_258 |= V_270 ;
* V_267 += * V_265 ;
( * V_266 ) ++ ;
V_60 -> V_45 -= sizeof( struct V_252 ) ;
V_60 -> V_33 ++ ;
return sizeof( struct V_252 ) ;
}
static int
F_151 (
struct log * log ,
struct V_61 * V_62 ,
T_4 V_63 ,
int * V_236 ,
int * V_272 ,
int * V_273 ,
int * V_274 ,
int V_275 ,
struct V_61 * * V_276 )
{
if ( * V_273 ) {
F_144 ( log , V_62 , * V_236 , * V_272 ) ;
* V_236 = 0 ;
* V_272 = 0 ;
return F_53 ( log , V_62 ) ;
}
* V_273 = 0 ;
* V_274 = 0 ;
if ( V_62 -> V_201 - V_275 <= sizeof( V_240 ) ) {
F_144 ( log , V_62 , * V_236 , * V_272 ) ;
* V_236 = 0 ;
* V_272 = 0 ;
F_12 ( & log -> V_111 ) ;
F_74 ( log , V_62 ) ;
F_15 ( & log -> V_111 ) ;
if ( ! V_276 )
return F_53 ( log , V_62 ) ;
ASSERT ( V_63 & V_207 ) ;
* V_276 = V_62 ;
}
return 0 ;
}
int
F_71 (
struct log * log ,
struct V_105 * V_247 ,
struct V_14 * V_60 ,
T_6 * V_277 ,
struct V_61 * * V_276 ,
T_4 V_63 )
{
struct V_61 * V_62 = NULL ;
struct V_99 * V_251 ;
struct V_105 * V_248 ;
int V_34 ;
int V_278 ;
int V_273 = 0 ;
int V_274 = 0 ;
int V_279 = 0 ;
int V_236 = 0 ;
int V_272 = 0 ;
int error ;
* V_277 = 0 ;
V_34 = F_147 ( V_60 , V_247 ) ;
if ( V_60 -> V_18 & V_65 )
V_60 -> V_45 -= sizeof( V_240 ) ;
if ( V_63 & ( V_207 | V_109 ) )
V_60 -> V_45 -= sizeof( V_240 ) ;
if ( V_60 -> V_45 < 0 )
F_145 ( log -> V_140 , V_60 ) ;
V_278 = 0 ;
V_248 = V_247 ;
V_251 = V_248 -> V_108 ;
while ( V_248 && V_278 < V_248 -> V_107 ) {
void * V_280 ;
int V_275 ;
error = F_152 ( log , V_34 , & V_62 , V_60 ,
& V_279 , & V_275 ) ;
if ( error )
return error ;
ASSERT ( V_275 <= V_62 -> V_201 - 1 ) ;
V_280 = V_62 -> V_203 + V_275 ;
if ( ! * V_277 )
* V_277 = F_130 ( V_62 -> V_191 . V_224 ) ;
while ( V_248 && V_278 < V_248 -> V_107 ) {
struct V_99 * V_100 = & V_251 [ V_278 ] ;
struct V_252 * V_253 ;
int V_281 ;
int V_265 ;
int V_264 ;
ASSERT ( V_100 -> V_102 % sizeof( V_282 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_280 % sizeof( V_282 ) == 0 ) ;
V_281 = F_148 ( V_280 , V_60 ) ;
if ( V_281 ) {
V_236 ++ ;
F_153 ( & V_280 , & V_34 , & V_275 ,
V_281 ) ;
}
V_253 = F_149 ( log , V_280 , V_60 , V_63 ) ;
if ( ! V_253 )
return F_30 ( V_28 ) ;
F_153 ( & V_280 , & V_34 , & V_275 ,
sizeof( struct V_252 ) ) ;
V_34 += F_150 ( V_60 , V_253 ,
V_62 -> V_201 - V_275 ,
V_100 -> V_102 ,
& V_264 , & V_265 ,
& V_273 ,
& V_274 ) ;
F_154 ( log , V_280 ) ;
ASSERT ( V_265 >= 0 ) ;
memcpy ( V_280 , V_100 -> V_101 + V_264 , V_265 ) ;
F_153 ( & V_280 , & V_34 , & V_275 , V_265 ) ;
V_265 += V_281 + sizeof( V_240 ) ;
V_236 ++ ;
V_272 += V_279 ? V_265 : 0 ;
error = F_151 ( log , V_62 , V_63 ,
& V_236 , & V_272 ,
& V_273 ,
& V_274 ,
V_275 ,
V_276 ) ;
if ( error )
return error ;
if ( V_273 )
break;
if ( ++ V_278 == V_248 -> V_107 ) {
V_248 = V_248 -> V_250 ;
V_278 = 0 ;
if ( V_248 )
V_251 = V_248 -> V_108 ;
}
if ( V_236 == 0 ) {
if ( ! V_248 )
return 0 ;
break;
}
}
}
ASSERT ( V_34 == 0 ) ;
F_144 ( log , V_62 , V_236 , V_272 ) ;
if ( ! V_276 )
return F_53 ( log , V_62 ) ;
ASSERT ( V_63 & V_207 ) ;
* V_276 = V_62 ;
return 0 ;
}
STATIC void
F_155 ( T_11 * log )
{
T_12 * V_62 ;
int V_283 = 0 ;
V_62 = log -> V_91 ;
do {
if ( V_62 -> V_70 == V_113 ) {
V_62 -> V_70 = V_72 ;
V_62 -> V_92 = 0 ;
ASSERT ( V_62 -> V_202 == NULL ) ;
if ( ! V_283 &&
( F_141 ( V_62 -> V_191 . V_238 ) ==
V_284 ) ) {
V_283 = 1 ;
} else {
V_283 = 2 ;
}
V_62 -> V_191 . V_238 = 0 ;
memset ( V_62 -> V_191 . V_285 , 0 ,
sizeof( V_62 -> V_191 . V_285 ) ) ;
V_62 -> V_191 . V_224 = 0 ;
} else if ( V_62 -> V_70 == V_72 )
;
else
break;
V_62 = V_62 -> V_93 ;
} while ( V_62 != log -> V_91 );
if ( V_283 ) {
switch ( log -> V_127 ) {
case V_130 :
case V_131 :
case V_132 :
log -> V_127 = V_131 ;
break;
case V_128 :
if ( V_283 == 1 )
log -> V_127 = V_132 ;
else
log -> V_127 = V_131 ;
break;
case V_129 :
if ( V_283 == 1 )
log -> V_127 = V_130 ;
else
log -> V_127 = V_131 ;
break;
default:
ASSERT ( 0 ) ;
}
}
}
STATIC T_6
F_156 (
T_11 * log )
{
T_12 * V_286 ;
T_6 V_287 , V_64 ;
V_286 = log -> V_91 ;
V_287 = 0 ;
do {
if ( ! ( V_286 -> V_70 & ( V_72 | V_113 ) ) ) {
V_64 = F_130 ( V_286 -> V_191 . V_224 ) ;
if ( ( V_64 && ! V_287 ) ||
( F_117 ( V_64 , V_287 ) < 0 ) ) {
V_287 = V_64 ;
}
}
V_286 = V_286 -> V_93 ;
} while ( V_286 != log -> V_91 );
return V_287 ;
}
STATIC void
F_157 (
T_11 * log ,
int V_145 ,
T_12 * V_288 )
{
T_12 * V_62 ;
T_12 * V_89 ;
T_7 * V_67 , * V_74 ;
int V_289 = 0 ;
T_6 V_287 ;
int V_290 ;
int V_291 ;
int V_292 ;
int V_293 ;
int V_294 = 0 ;
F_12 ( & log -> V_111 ) ;
V_89 = V_62 = log -> V_91 ;
V_290 = 0 ;
V_292 = 0 ;
V_293 = 0 ;
do {
V_89 = log -> V_91 ;
V_62 = log -> V_91 ;
V_291 = 0 ;
V_293 ++ ;
do {
if ( V_62 -> V_70 &
( V_72 | V_113 ) ) {
V_62 = V_62 -> V_93 ;
continue;
}
if ( ! ( V_62 -> V_70 & V_71 ) ) {
if ( ! ( V_62 -> V_70 &
( V_295 |
V_296 ) ) ) {
if ( V_288 && ( V_288 -> V_70 ==
V_295 ) ) {
V_288 -> V_70 = V_296 ;
}
break;
}
V_287 = F_156 ( log ) ;
if ( V_287 &&
F_117 ( V_287 ,
F_130 ( V_62 -> V_191 . V_224 ) ) < 0 ) {
V_62 = V_62 -> V_93 ;
continue;
}
V_62 -> V_70 = V_297 ;
ASSERT ( F_117 ( F_2 ( & log -> V_134 ) ,
F_130 ( V_62 -> V_191 . V_224 ) ) <= 0 ) ;
F_85 ( & log -> V_134 ,
F_130 ( V_62 -> V_191 . V_224 ) ) ;
} else
V_290 ++ ;
F_15 ( & log -> V_111 ) ;
F_12 ( & V_62 -> V_69 ) ;
V_67 = V_62 -> V_202 ;
while ( V_67 ) {
V_62 -> V_75 = & ( V_62 -> V_202 ) ;
V_62 -> V_202 = NULL ;
F_15 ( & V_62 -> V_69 ) ;
for (; V_67 ; V_67 = V_74 ) {
V_74 = V_67 -> V_74 ;
V_67 -> V_298 ( V_67 -> V_299 , V_145 ) ;
}
F_12 ( & V_62 -> V_69 ) ;
V_67 = V_62 -> V_202 ;
}
V_291 ++ ;
V_292 ++ ;
F_12 ( & log -> V_111 ) ;
ASSERT ( V_62 -> V_202 == NULL ) ;
F_15 ( & V_62 -> V_69 ) ;
if ( ! ( V_62 -> V_70 & V_71 ) )
V_62 -> V_70 = V_113 ;
F_155 ( log ) ;
F_158 ( & V_62 -> V_114 ) ;
V_62 = V_62 -> V_93 ;
} while ( V_89 != V_62 );
if ( V_293 > 5000 ) {
V_289 += V_293 ;
V_293 = 0 ;
F_61 ( log -> V_140 ,
L_87 ,
V_110 , V_289 ) ;
}
} while ( ! V_290 && V_291 );
#ifdef F_69
if ( V_292 ) {
V_89 = V_62 = log -> V_91 ;
do {
ASSERT ( V_62 -> V_70 != V_296 ) ;
if ( V_62 -> V_70 == V_73 ||
V_62 -> V_70 == V_300 ||
V_62 -> V_70 == V_295 ||
V_62 -> V_70 == V_71 )
break;
V_62 = V_62 -> V_93 ;
} while ( V_89 != V_62 );
}
#endif
if ( log -> V_91 -> V_70 & ( V_72 | V_71 ) )
V_294 = 1 ;
F_15 ( & log -> V_111 ) ;
if ( V_294 )
F_158 ( & log -> V_182 ) ;
}
STATIC void
F_95 (
T_12 * V_62 ,
int V_145 )
{
T_11 * log = V_62 -> V_144 ;
F_12 ( & log -> V_111 ) ;
ASSERT ( V_62 -> V_70 == V_300 ||
V_62 -> V_70 == V_71 ) ;
ASSERT ( F_124 ( & V_62 -> V_112 ) == 0 ) ;
ASSERT ( V_62 -> V_226 == 1 || V_62 -> V_226 == 2 ) ;
if ( V_62 -> V_70 != V_71 ) {
if ( -- V_62 -> V_226 == 1 ) {
F_15 ( & log -> V_111 ) ;
return;
}
V_62 -> V_70 = V_295 ;
}
F_158 ( & V_62 -> V_204 ) ;
F_15 ( & log -> V_111 ) ;
F_157 ( log , V_145 , V_62 ) ;
}
STATIC int
F_152 ( T_11 * log ,
int V_34 ,
T_12 * * V_166 ,
T_3 * V_60 ,
int * V_301 ,
int * V_302 )
{
int V_275 ;
T_16 * V_1 ;
T_12 * V_62 ;
int error ;
V_303:
F_12 ( & log -> V_111 ) ;
if ( F_21 ( log ) ) {
F_15 ( & log -> V_111 ) ;
return F_30 ( V_28 ) ;
}
V_62 = log -> V_91 ;
if ( V_62 -> V_70 != V_72 ) {
F_24 ( V_304 ) ;
F_75 ( & log -> V_182 , & log -> V_111 ) ;
goto V_303;
}
V_1 = & V_62 -> V_191 ;
F_73 ( & V_62 -> V_112 ) ;
V_275 = V_62 -> V_92 ;
if ( V_275 == 0 ) {
V_60 -> V_45 -= log -> V_159 ;
F_34 ( V_60 ,
log -> V_159 ,
V_305 ) ;
V_1 -> V_306 = F_106 ( log -> V_174 ) ;
V_1 -> V_224 = F_159 (
F_116 ( log -> V_174 , log -> V_307 ) ) ;
ASSERT ( log -> V_307 >= 0 ) ;
}
if ( V_62 -> V_201 - V_62 -> V_92 < 2 * sizeof( V_240 ) ) {
F_160 ( log , V_62 , V_62 -> V_201 ) ;
if ( ! F_161 ( & V_62 -> V_112 , - 1 , 1 ) ) {
F_15 ( & log -> V_111 ) ;
error = F_53 ( log , V_62 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_111 ) ;
}
goto V_303;
}
if ( V_34 <= V_62 -> V_201 - V_62 -> V_92 ) {
* V_301 = 0 ;
V_62 -> V_92 += V_34 ;
} else {
* V_301 = 1 ;
F_160 ( log , V_62 , V_62 -> V_201 ) ;
}
* V_166 = V_62 ;
ASSERT ( V_62 -> V_92 <= V_62 -> V_201 ) ;
F_15 ( & log -> V_111 ) ;
* V_302 = V_275 ;
return 0 ;
}
STATIC void
F_49 ( T_11 * log ,
T_3 * V_60 )
{
F_162 ( log , V_60 ) ;
if ( V_60 -> V_21 > 0 )
V_60 -> V_21 -- ;
F_1 ( log , & log -> V_59 . V_11 ,
V_60 -> V_45 ) ;
F_1 ( log , & log -> V_17 . V_11 ,
V_60 -> V_45 ) ;
V_60 -> V_45 = V_60 -> V_20 ;
F_33 ( V_60 ) ;
F_163 ( log , V_60 ) ;
if ( V_60 -> V_21 > 0 )
return;
F_6 ( log , & log -> V_59 . V_11 ,
V_60 -> V_20 ) ;
F_164 ( log , V_60 ) ;
V_60 -> V_45 = V_60 -> V_20 ;
F_33 ( V_60 ) ;
}
STATIC void
F_46 ( T_11 * log ,
T_3 * V_60 )
{
int V_2 ;
if ( V_60 -> V_21 > 0 )
V_60 -> V_21 -- ;
F_165 ( log , V_60 ) ;
F_166 ( log , V_60 ) ;
V_2 = V_60 -> V_45 ;
if ( V_60 -> V_21 > 0 ) {
ASSERT ( V_60 -> V_18 & V_19 ) ;
V_2 += V_60 -> V_20 * V_60 -> V_21 ;
}
F_1 ( log , & log -> V_59 . V_11 , V_2 ) ;
F_1 ( log , & log -> V_17 . V_11 , V_2 ) ;
F_167 ( log , V_60 ) ;
F_79 ( log -> V_140 ) ;
}
STATIC int
F_53 (
T_11 * log ,
T_12 * V_62 )
{
int V_308 = 0 ;
if ( V_62 -> V_70 & V_71 )
return F_30 ( V_28 ) ;
ASSERT ( F_124 ( & V_62 -> V_112 ) > 0 ) ;
if ( ! F_168 ( & V_62 -> V_112 , & log -> V_111 ) )
return 0 ;
if ( V_62 -> V_70 & V_71 ) {
F_15 ( & log -> V_111 ) ;
return F_30 ( V_28 ) ;
}
ASSERT ( V_62 -> V_70 == V_72 ||
V_62 -> V_70 == V_73 ) ;
if ( V_62 -> V_70 == V_73 ) {
T_6 V_133 = F_84 ( log -> V_140 ) ;
V_308 ++ ;
V_62 -> V_70 = V_300 ;
V_62 -> V_191 . V_309 = F_159 ( V_133 ) ;
F_169 ( log , V_62 , V_133 ) ;
}
F_15 ( & log -> V_111 ) ;
if ( V_308 )
return F_123 ( log , V_62 ) ;
return 0 ;
}
STATIC void
F_160 ( T_11 * log ,
T_12 * V_62 ,
int V_310 )
{
ASSERT ( V_62 -> V_70 == V_72 ) ;
if ( ! V_310 )
V_310 = V_62 -> V_92 ;
V_62 -> V_70 = V_73 ;
V_62 -> V_191 . V_311 = F_106 ( log -> V_173 ) ;
log -> V_173 = log -> V_307 ;
log -> V_312 = log -> V_174 ;
log -> V_307 += F_113 ( V_310 ) + F_113 ( log -> V_159 ) ;
if ( F_97 ( & log -> V_140 -> V_157 ) &&
log -> V_140 -> V_157 . V_222 > 1 ) {
T_14 V_313 = F_113 ( log -> V_140 -> V_157 . V_222 ) ;
log -> V_307 = F_170 ( log -> V_307 , V_313 ) ;
}
if ( log -> V_307 >= log -> V_172 ) {
log -> V_174 ++ ;
if ( log -> V_174 == V_193 )
log -> V_174 ++ ;
log -> V_307 -= log -> V_172 ;
ASSERT ( log -> V_307 >= 0 ) ;
}
ASSERT ( V_62 == log -> V_91 ) ;
log -> V_91 = V_62 -> V_93 ;
}
int
F_70 (
struct V_40 * V_41 ,
T_4 V_63 ,
int * V_314 )
{
struct log * log = V_41 -> V_42 ;
struct V_61 * V_62 ;
T_6 V_64 ;
F_24 ( V_315 ) ;
F_171 ( log ) ;
F_12 ( & log -> V_111 ) ;
V_62 = log -> V_91 ;
if ( V_62 -> V_70 & V_71 ) {
F_15 ( & log -> V_111 ) ;
return F_30 ( V_28 ) ;
}
if ( V_62 -> V_70 == V_72 ||
V_62 -> V_70 == V_113 ) {
if ( V_62 -> V_70 == V_113 ||
( F_124 ( & V_62 -> V_112 ) == 0
&& V_62 -> V_92 == 0 ) ) {
V_62 = V_62 -> V_185 ;
if ( V_62 -> V_70 == V_72 ||
V_62 -> V_70 == V_113 )
goto V_316;
else
goto V_317;
} else {
if ( F_124 ( & V_62 -> V_112 ) == 0 ) {
F_73 ( & V_62 -> V_112 ) ;
V_64 = F_130 ( V_62 -> V_191 . V_224 ) ;
F_160 ( log , V_62 , 0 ) ;
F_15 ( & log -> V_111 ) ;
if ( F_53 ( log , V_62 ) )
return F_30 ( V_28 ) ;
if ( V_314 )
* V_314 = 1 ;
F_12 ( & log -> V_111 ) ;
if ( F_130 ( V_62 -> V_191 . V_224 ) == V_64 &&
V_62 -> V_70 != V_113 )
goto V_317;
else
goto V_316;
} else {
F_160 ( log , V_62 , 0 ) ;
goto V_317;
}
}
}
V_317:
if ( V_63 & V_90 ) {
if ( V_62 -> V_70 & V_71 ) {
F_15 ( & log -> V_111 ) ;
return F_30 ( V_28 ) ;
}
F_24 ( V_318 ) ;
F_75 ( & V_62 -> V_114 , & log -> V_111 ) ;
if ( V_62 -> V_70 & V_71 )
return F_30 ( V_28 ) ;
if ( V_314 )
* V_314 = 1 ;
} else {
V_316:
F_15 ( & log -> V_111 ) ;
}
return 0 ;
}
void
F_172 (
T_8 * V_41 ,
T_4 V_63 )
{
int error ;
error = F_70 ( V_41 , V_63 , NULL ) ;
if ( error )
F_61 ( V_41 , L_88 , V_110 , error ) ;
}
int
F_173 (
struct V_40 * V_41 ,
T_6 V_64 ,
T_4 V_63 ,
int * V_314 )
{
struct log * log = V_41 -> V_42 ;
struct V_61 * V_62 ;
int V_319 = 0 ;
ASSERT ( V_64 != 0 ) ;
F_24 ( V_315 ) ;
V_64 = F_174 ( log , V_64 ) ;
if ( V_64 == V_320 )
return 0 ;
V_321:
F_12 ( & log -> V_111 ) ;
V_62 = log -> V_91 ;
if ( V_62 -> V_70 & V_71 ) {
F_15 ( & log -> V_111 ) ;
return F_30 ( V_28 ) ;
}
do {
if ( F_130 ( V_62 -> V_191 . V_224 ) != V_64 ) {
V_62 = V_62 -> V_93 ;
continue;
}
if ( V_62 -> V_70 == V_113 ) {
F_15 ( & log -> V_111 ) ;
return 0 ;
}
if ( V_62 -> V_70 == V_72 ) {
if ( ! V_319 &&
( V_62 -> V_185 -> V_70 &
( V_73 | V_300 ) ) ) {
ASSERT ( ! ( V_62 -> V_70 & V_71 ) ) ;
F_24 ( V_318 ) ;
F_75 ( & V_62 -> V_185 -> V_204 ,
& log -> V_111 ) ;
if ( V_314 )
* V_314 = 1 ;
V_319 = 1 ;
goto V_321;
}
F_73 ( & V_62 -> V_112 ) ;
F_160 ( log , V_62 , 0 ) ;
F_15 ( & log -> V_111 ) ;
if ( F_53 ( log , V_62 ) )
return F_30 ( V_28 ) ;
if ( V_314 )
* V_314 = 1 ;
F_12 ( & log -> V_111 ) ;
}
if ( ( V_63 & V_90 ) &&
! ( V_62 -> V_70 &
( V_72 | V_113 ) ) ) {
if ( V_62 -> V_70 & V_71 ) {
F_15 ( & log -> V_111 ) ;
return F_30 ( V_28 ) ;
}
F_24 ( V_318 ) ;
F_75 ( & V_62 -> V_114 , & log -> V_111 ) ;
if ( V_62 -> V_70 & V_71 )
return F_30 ( V_28 ) ;
if ( V_314 )
* V_314 = 1 ;
} else {
F_15 ( & log -> V_111 ) ;
}
return 0 ;
} while ( V_62 != log -> V_91 );
F_15 ( & log -> V_111 ) ;
return 0 ;
}
void
F_175 (
T_8 * V_41 ,
T_6 V_64 ,
T_4 V_63 )
{
int error ;
error = F_173 ( V_41 , V_64 , V_63 , NULL ) ;
if ( error )
F_61 ( V_41 , L_88 , V_110 , error ) ;
}
STATIC void
F_74 ( T_11 * log , T_12 * V_62 )
{
F_176 ( & log -> V_111 ) ;
if ( V_62 -> V_70 == V_72 ) {
F_160 ( log , V_62 , 0 ) ;
} else {
ASSERT ( V_62 -> V_70 &
( V_73 | V_71 ) ) ;
}
}
void
F_47 (
T_3 * V_60 )
{
ASSERT ( F_124 ( & V_60 -> V_322 ) > 0 ) ;
if ( F_177 ( & V_60 -> V_322 ) )
F_178 ( V_323 , V_60 ) ;
}
T_3 *
F_179 (
T_3 * V_60 )
{
ASSERT ( F_124 ( & V_60 -> V_322 ) > 0 ) ;
F_73 ( & V_60 -> V_322 ) ;
return V_60 ;
}
T_3 *
F_40 (
struct log * log ,
int V_47 ,
int V_48 ,
char V_50 ,
bool V_51 ,
int V_324 )
{
struct V_14 * V_15 ;
T_4 V_325 ;
int V_326 ;
V_15 = F_180 ( V_323 , V_324 ) ;
if ( ! V_15 )
return NULL ;
V_47 += sizeof( V_240 ) ;
V_47 += sizeof( V_327 ) ;
V_47 += sizeof( V_240 ) ;
V_326 = log -> V_155 - log -> V_159 ;
V_325 = F_181 ( V_47 , V_326 ) ;
V_47 += sizeof( V_240 ) * V_325 ;
while ( ! V_325 ||
F_181 ( V_47 , V_326 ) > V_325 ) {
V_47 += sizeof( V_240 ) ;
V_325 ++ ;
}
V_47 += log -> V_159 * V_325 ;
V_47 += log -> V_159 ;
if ( F_97 ( & log -> V_140 -> V_157 ) &&
log -> V_140 -> V_157 . V_222 > 1 ) {
V_47 += 2 * log -> V_140 -> V_157 . V_222 ;
} else {
V_47 += 2 * V_163 ;
}
F_107 ( & V_15 -> V_322 , 1 ) ;
V_15 -> V_16 = V_328 ;
F_9 ( & V_15 -> V_24 ) ;
V_15 -> V_20 = V_47 ;
V_15 -> V_45 = V_47 ;
V_15 -> V_21 = V_48 ;
V_15 -> V_329 = V_48 ;
V_15 -> V_44 = F_182 () ;
V_15 -> V_256 = V_50 ;
V_15 -> V_18 = V_65 ;
V_15 -> V_58 = 0 ;
if ( V_51 )
V_15 -> V_18 |= V_19 ;
F_33 ( V_15 ) ;
return V_15 ;
}
void
F_154 (
struct log * log ,
char * V_280 )
{
int V_168 ;
int V_330 = 0 ;
for ( V_168 = 0 ; V_168 < log -> V_152 ; V_168 ++ ) {
if ( V_280 >= log -> V_189 [ V_168 ] &&
V_280 <= log -> V_189 [ V_168 ] + log -> V_155 )
V_330 ++ ;
}
if ( ! V_330 )
F_183 ( log -> V_140 , L_89 , V_110 ) ;
}
STATIC void
F_38 (
struct log * log )
{
int V_137 , V_331 ;
int V_6 , V_7 ;
F_86 ( & log -> V_17 . V_11 , & V_6 , & V_7 ) ;
F_87 ( & log -> V_135 , & V_137 , & V_331 ) ;
if ( V_137 != V_6 ) {
if ( V_6 - 1 != V_137 &&
! ( log -> V_29 & V_332 ) ) {
F_146 ( log -> V_140 , V_245 ,
L_90 , V_110 ) ;
log -> V_29 |= V_332 ;
}
if ( V_7 > F_88 ( V_331 ) &&
! ( log -> V_29 & V_332 ) ) {
F_146 ( log -> V_140 , V_245 ,
L_91 , V_110 ) ;
log -> V_29 |= V_332 ;
}
}
}
STATIC void
F_169 ( T_11 * log ,
T_12 * V_62 ,
T_6 V_133 )
{
int V_333 ;
if ( F_184 ( V_133 ) == log -> V_312 ) {
V_333 =
log -> V_172 - ( log -> V_173 - F_129 ( V_133 ) ) ;
if ( V_333 < F_113 ( V_62 -> V_92 ) + F_113 ( log -> V_159 ) )
F_183 ( log -> V_140 , L_92 , V_110 ) ;
} else {
ASSERT ( F_184 ( V_133 ) + 1 == log -> V_312 ) ;
if ( F_129 ( V_133 ) == log -> V_173 )
F_183 ( log -> V_140 , L_93 , V_110 ) ;
V_333 = F_129 ( V_133 ) - log -> V_173 ;
if ( V_333 < F_113 ( V_62 -> V_92 ) + 1 )
F_183 ( log -> V_140 , L_92 , V_110 ) ;
}
}
STATIC void
F_137 ( T_11 * log ,
T_12 * V_62 ,
int V_216 ,
T_17 V_334 )
{
V_240 * V_335 ;
T_12 * V_336 ;
T_18 * V_337 ;
V_190 V_280 ;
V_190 V_338 ;
T_19 V_339 ;
T_5 V_340 ;
int V_34 , V_168 , V_341 , V_342 , V_343 ;
int V_344 ;
F_12 ( & log -> V_111 ) ;
V_336 = log -> V_91 ;
for ( V_168 = 0 ; V_168 < log -> V_152 ; V_168 ++ ) {
if ( V_336 == NULL )
F_183 ( log -> V_140 , L_89 , V_110 ) ;
V_336 = V_336 -> V_93 ;
}
if ( V_336 != log -> V_91 )
F_183 ( log -> V_140 , L_94 , V_110 ) ;
F_15 ( & log -> V_111 ) ;
if ( V_62 -> V_191 . V_192 != F_106 ( V_193 ) )
F_183 ( log -> V_140 , L_95 , V_110 ) ;
V_280 = ( V_190 ) & V_62 -> V_191 ;
for ( V_280 += V_163 ; V_280 < ( ( V_190 ) & V_62 -> V_191 ) + V_216 ;
V_280 += V_163 ) {
if ( * ( V_234 * ) V_280 == F_106 ( V_193 ) )
F_183 ( log -> V_140 , L_96 ,
V_110 ) ;
}
V_34 = F_141 ( V_62 -> V_191 . V_238 ) ;
V_280 = V_62 -> V_203 ;
V_338 = V_280 ;
V_335 = ( V_240 * ) V_280 ;
V_337 = V_62 -> V_187 ;
for ( V_168 = 0 ; V_168 < V_34 ; V_168 ++ ) {
V_335 = ( V_240 * ) V_280 ;
V_339 = ( T_19 )
( ( V_190 ) & ( V_335 -> V_255 ) - V_338 ) ;
if ( V_334 == V_345 || ( V_339 & 0x1ff ) ) {
V_340 = V_335 -> V_255 ;
} else {
V_344 = F_114 ( ( V_190 ) & ( V_335 -> V_255 ) - V_62 -> V_203 ) ;
if ( V_344 >= ( V_158 / V_163 ) ) {
V_341 = V_344 / ( V_158 / V_163 ) ;
V_342 = V_344 % ( V_158 / V_163 ) ;
V_340 = F_185 (
V_337 [ V_341 ] . V_346 . V_347 [ V_342 ] ) ;
} else {
V_340 = F_185 (
V_62 -> V_191 . V_285 [ V_344 ] ) ;
}
}
if ( V_340 != V_53 && V_340 != V_54 )
F_61 ( log -> V_140 ,
L_97 ,
V_110 , V_340 , V_335 ,
( unsigned long ) V_339 ) ;
V_339 = ( T_19 )
( ( V_190 ) & ( V_335 -> V_257 ) - V_338 ) ;
if ( V_334 == V_345 || ( V_339 & 0x1ff ) ) {
V_343 = F_141 ( V_335 -> V_257 ) ;
} else {
V_344 = F_114 ( ( T_19 ) & V_335 -> V_257 -
( T_19 ) V_62 -> V_203 ) ;
if ( V_344 >= ( V_158 / V_163 ) ) {
V_341 = V_344 / ( V_158 / V_163 ) ;
V_342 = V_344 % ( V_158 / V_163 ) ;
V_343 = F_141 ( V_337 [ V_341 ] . V_346 . V_347 [ V_342 ] ) ;
} else {
V_343 = F_141 ( V_62 -> V_191 . V_285 [ V_344 ] ) ;
}
}
V_280 += sizeof( V_240 ) + V_343 ;
}
}
STATIC int
F_186 (
T_11 * log )
{
T_12 * V_62 , * V_348 ;
V_62 = log -> V_91 ;
if ( ! ( V_62 -> V_70 & V_71 ) ) {
V_348 = V_62 ;
do {
V_348 -> V_70 = V_71 ;
V_348 = V_348 -> V_93 ;
} while ( V_348 != V_62 );
return 0 ;
}
return 1 ;
}
int
F_187 (
struct V_40 * V_41 ,
int V_349 )
{
T_11 * log ;
int V_350 ;
log = V_41 -> V_42 ;
if ( ! log ||
log -> V_29 & V_30 ) {
V_41 -> V_80 |= V_351 ;
if ( V_41 -> V_352 )
F_188 ( V_41 -> V_352 ) ;
return 0 ;
}
if ( V_349 && log -> V_91 -> V_70 & V_71 ) {
ASSERT ( F_21 ( log ) ) ;
return 1 ;
}
V_350 = 0 ;
if ( ! V_349 )
F_171 ( log ) ;
F_12 ( & log -> V_111 ) ;
V_41 -> V_80 |= V_351 ;
if ( V_41 -> V_352 )
F_188 ( V_41 -> V_352 ) ;
log -> V_29 |= V_353 ;
if ( V_349 )
V_350 = F_186 ( log ) ;
F_15 ( & log -> V_111 ) ;
F_11 ( & log -> V_59 ) ;
F_11 ( & log -> V_17 ) ;
if ( ! ( log -> V_91 -> V_70 & V_71 ) ) {
ASSERT ( ! V_349 ) ;
F_70 ( V_41 , V_90 , NULL ) ;
F_12 ( & log -> V_111 ) ;
V_350 = F_186 ( log ) ;
F_15 ( & log -> V_111 ) ;
}
F_157 ( log , V_148 , NULL ) ;
#ifdef F_189
{
T_12 * V_62 ;
F_12 ( & log -> V_111 ) ;
V_62 = log -> V_91 ;
do {
ASSERT ( V_62 -> V_202 == 0 ) ;
V_62 = V_62 -> V_93 ;
} while ( V_62 != log -> V_91 );
F_15 ( & log -> V_111 ) ;
}
#endif
return V_350 ;
}
STATIC int
F_83 ( T_11 * log )
{
T_12 * V_62 ;
V_62 = log -> V_91 ;
do {
if ( V_62 -> V_191 . V_238 )
return 0 ;
V_62 = V_62 -> V_93 ;
} while ( V_62 != log -> V_91 );
return 1 ;
}
