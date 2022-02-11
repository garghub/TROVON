static void
F_1 (
struct V_1 * log ,
T_1 * V_2 ,
int V_3 )
{
T_2 V_4 = F_2 ( V_2 ) ;
T_2 V_5 , V_6 ;
do {
int V_7 , V_8 ;
F_3 ( V_4 , & V_7 , & V_8 ) ;
V_8 -= V_3 ;
if ( V_8 < 0 ) {
V_8 += log -> V_9 ;
V_7 -- ;
}
V_6 = V_4 ;
V_5 = F_4 ( V_7 , V_8 ) ;
V_4 = F_5 ( V_2 , V_6 , V_5 ) ;
} while ( V_4 != V_6 );
}
static void
F_6 (
struct V_1 * log ,
T_1 * V_2 ,
int V_3 )
{
T_2 V_4 = F_2 ( V_2 ) ;
T_2 V_5 , V_6 ;
do {
int V_10 ;
int V_7 , V_8 ;
F_3 ( V_4 , & V_7 , & V_8 ) ;
V_10 = log -> V_9 - V_8 ;
if ( V_10 > V_3 )
V_8 += V_3 ;
else {
V_8 = V_3 - V_10 ;
V_7 ++ ;
}
V_6 = V_4 ;
V_5 = F_4 ( V_7 , V_8 ) ;
V_4 = F_5 ( V_2 , V_6 , V_5 ) ;
} while ( V_4 != V_6 );
}
STATIC void
F_7 (
struct V_11 * V_2 )
{
F_8 ( & V_2 -> V_12 , 1 , 0 ) ;
F_9 ( & V_2 -> V_13 ) ;
F_10 ( & V_2 -> V_14 ) ;
}
STATIC void
F_11 (
struct V_11 * V_2 )
{
struct V_15 * V_16 ;
F_12 ( & V_2 -> V_14 ) ;
F_13 (tic, &head->waiters, t_queue)
F_14 ( V_16 -> V_17 ) ;
F_15 ( & V_2 -> V_14 ) ;
}
static inline int
F_16 (
struct V_1 * log ,
struct V_11 * V_2 ,
struct V_15 * V_16 )
{
if ( V_2 == & log -> V_18 ) {
ASSERT ( V_16 -> V_19 & V_20 ) ;
return V_16 -> V_21 ;
} else {
if ( V_16 -> V_19 & V_20 )
return V_16 -> V_21 * V_16 -> V_22 ;
else
return V_16 -> V_21 ;
}
}
STATIC bool
F_17 (
struct V_1 * log ,
struct V_11 * V_2 ,
int * V_23 )
{
struct V_15 * V_16 ;
int V_24 ;
F_13 (tic, &head->waiters, t_queue) {
V_24 = F_16 ( log , V_2 , V_16 ) ;
if ( * V_23 < V_24 )
return false ;
* V_23 -= V_24 ;
F_18 ( log , V_16 ) ;
F_14 ( V_16 -> V_17 ) ;
}
return true ;
}
STATIC int
F_19 (
struct V_1 * log ,
struct V_11 * V_2 ,
struct V_15 * V_16 ,
int V_24 ) __releases( &head->lock
STATIC int
F_20 (
struct V_1 * log ,
struct V_11 * V_2 ,
struct V_15 * V_16 ,
int * V_24 )
{
int V_23 ;
int error = 0 ;
ASSERT ( ! ( log -> V_25 & V_26 ) ) ;
* V_24 = F_16 ( log , V_2 , V_16 ) ;
V_23 = F_21 ( log , & V_2 -> V_12 ) ;
if ( ! F_22 ( & V_2 -> V_13 ) ) {
F_12 ( & V_2 -> V_14 ) ;
if ( ! F_17 ( log , V_2 , & V_23 ) ||
V_23 < * V_24 ) {
error = F_19 ( log , V_2 , V_16 ,
* V_24 ) ;
}
F_15 ( & V_2 -> V_14 ) ;
} else if ( V_23 < * V_24 ) {
F_12 ( & V_2 -> V_14 ) ;
error = F_19 ( log , V_2 , V_16 , * V_24 ) ;
F_15 ( & V_2 -> V_14 ) ;
}
return error ;
}
static void
F_23 ( T_3 * V_16 )
{
V_16 -> V_27 = 0 ;
V_16 -> V_28 = 0 ;
V_16 -> V_29 = 0 ;
}
static void
F_24 ( T_3 * V_16 , T_4 V_30 , T_4 type )
{
if ( V_16 -> V_27 == V_31 ) {
V_16 -> V_32 += V_16 -> V_28 ;
V_16 -> V_27 = 0 ;
V_16 -> V_28 = 0 ;
}
V_16 -> V_33 [ V_16 -> V_27 ] . V_34 = V_30 ;
V_16 -> V_33 [ V_16 -> V_27 ] . V_35 = type ;
V_16 -> V_28 += V_30 ;
V_16 -> V_27 ++ ;
}
int
F_25 (
struct V_36 * V_37 ,
struct V_15 * V_16 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_24 ;
int error = 0 ;
if ( F_26 ( log ) )
return - V_39 ;
F_27 ( V_37 , V_40 ) ;
V_16 -> V_41 ++ ;
F_28 ( log , V_16 -> V_21 ) ;
V_16 -> V_42 = V_16 -> V_21 ;
F_23 ( V_16 ) ;
if ( V_16 -> V_22 > 0 )
return 0 ;
F_29 ( log , V_16 ) ;
error = F_20 ( log , & log -> V_18 , V_16 ,
& V_24 ) ;
if ( error )
goto V_43;
F_6 ( log , & log -> V_18 . V_12 , V_24 ) ;
F_30 ( log , V_16 ) ;
F_31 ( log ) ;
return 0 ;
V_43:
V_16 -> V_42 = 0 ;
V_16 -> V_22 = 0 ;
return error ;
}
int
F_32 (
struct V_36 * V_37 ,
int V_44 ,
int V_45 ,
struct V_15 * * V_46 ,
T_5 V_47 ,
bool V_48 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_15 * V_16 ;
int V_24 ;
int error = 0 ;
ASSERT ( V_47 == V_49 || V_47 == V_50 ) ;
if ( F_26 ( log ) )
return - V_39 ;
F_27 ( V_37 , V_40 ) ;
ASSERT ( * V_46 == NULL ) ;
V_16 = F_33 ( log , V_44 , V_45 , V_47 , V_48 ,
V_51 | V_52 ) ;
if ( ! V_16 )
return - V_53 ;
* V_46 = V_16 ;
F_28 ( log , V_16 -> V_22 ? V_16 -> V_21 * V_16 -> V_22
: V_16 -> V_21 ) ;
F_34 ( log , V_16 ) ;
error = F_20 ( log , & log -> V_54 , V_16 ,
& V_24 ) ;
if ( error )
goto V_43;
F_6 ( log , & log -> V_54 . V_12 , V_24 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_24 ) ;
F_35 ( log , V_16 ) ;
F_31 ( log ) ;
return 0 ;
V_43:
V_16 -> V_42 = 0 ;
V_16 -> V_22 = 0 ;
return error ;
}
T_6
F_36 (
struct V_36 * V_37 ,
struct V_15 * V_55 ,
struct V_56 * * V_57 ,
bool V_58 )
{
struct V_1 * log = V_37 -> V_38 ;
T_6 V_59 = 0 ;
if ( F_26 ( log ) ||
( ( ( V_55 -> V_19 & V_60 ) == 0 ) &&
( F_37 ( log , V_55 , V_57 , & V_59 ) ) ) ) {
V_59 = ( T_6 ) - 1 ;
V_58 = false ;
}
if ( ! V_58 ) {
F_38 ( log , V_55 ) ;
F_39 ( log , V_55 ) ;
} else {
F_40 ( log , V_55 ) ;
F_41 ( log , V_55 ) ;
V_55 -> V_19 |= V_60 ;
}
F_42 ( V_55 ) ;
return V_59 ;
}
int
F_43 (
struct V_36 * V_37 ,
struct V_56 * V_57 ,
T_7 * V_61 )
{
int V_62 ;
F_12 ( & V_57 -> V_63 ) ;
V_62 = ( V_57 -> V_64 & V_65 ) ;
if ( ! V_62 ) {
F_44 ( ( V_57 -> V_64 == V_66 ) ||
( V_57 -> V_64 == V_67 ) ) ;
V_61 -> V_68 = NULL ;
* ( V_57 -> V_69 ) = V_61 ;
V_57 -> V_69 = & ( V_61 -> V_68 ) ;
}
F_15 ( & V_57 -> V_63 ) ;
return V_62 ;
}
int
F_45 (
struct V_36 * V_37 ,
struct V_56 * V_57 )
{
if ( F_46 ( V_37 -> V_38 , V_57 ) ) {
F_47 ( V_37 , V_70 ) ;
return - V_39 ;
}
return 0 ;
}
int
F_48 (
T_8 * V_37 ,
T_9 * V_71 ,
T_10 V_72 ,
int V_73 )
{
int error = 0 ;
int V_74 ;
if ( ! ( V_37 -> V_75 & V_76 ) ) {
F_49 ( V_37 , L_1 ,
F_50 ( & V_37 -> V_77 ) ) ;
} else {
F_49 ( V_37 ,
L_2 ,
F_50 ( & V_37 -> V_77 ) ) ;
ASSERT ( V_37 -> V_75 & V_78 ) ;
}
V_37 -> V_38 = F_51 ( V_37 , V_71 , V_72 , V_73 ) ;
if ( F_52 ( V_37 -> V_38 ) ) {
error = F_53 ( V_37 -> V_38 ) ;
goto V_79;
}
V_74 = F_54 ( V_37 ) ;
if ( V_37 -> V_77 . V_80 < V_74 ) {
F_55 ( V_37 ,
L_3 ,
V_37 -> V_77 . V_80 , V_74 ) ;
error = - V_81 ;
} else if ( V_37 -> V_77 . V_80 > V_82 ) {
F_55 ( V_37 ,
L_4 ,
V_37 -> V_77 . V_80 , V_82 ) ;
error = - V_81 ;
} else if ( F_56 ( V_37 , V_37 -> V_77 . V_80 ) > V_83 ) {
F_55 ( V_37 ,
L_5 ,
F_56 ( V_37 , V_37 -> V_77 . V_80 ) ,
V_83 ) ;
error = - V_81 ;
}
if ( error ) {
if ( F_57 ( & V_37 -> V_77 ) ) {
F_58 ( V_37 , L_6 ) ;
ASSERT ( 0 ) ;
goto V_84;
}
F_58 ( V_37 , L_7 ) ;
F_58 ( V_37 ,
L_8 ) ;
}
error = F_59 ( V_37 ) ;
if ( error ) {
F_55 ( V_37 , L_9 , error ) ;
goto V_84;
}
V_37 -> V_38 -> V_85 = V_37 -> V_86 ;
if ( ! ( V_37 -> V_75 & V_76 ) ) {
int V_87 = ( V_37 -> V_75 & V_78 ) ;
if ( V_87 )
V_37 -> V_75 &= ~ V_78 ;
error = F_60 ( V_37 -> V_38 ) ;
if ( V_87 )
V_37 -> V_75 |= V_78 ;
if ( error ) {
F_55 ( V_37 , L_10 ,
error ) ;
F_61 ( V_37 -> V_38 ) ;
goto V_88;
}
}
error = F_62 ( & V_37 -> V_38 -> V_89 , & V_90 , & V_37 -> V_91 ,
L_11 ) ;
if ( error )
goto V_88;
V_37 -> V_38 -> V_25 &= ~ V_26 ;
F_63 ( V_37 -> V_38 ) ;
return 0 ;
V_88:
F_64 ( V_37 ) ;
V_84:
F_65 ( V_37 -> V_38 ) ;
V_79:
return error ;
}
int
F_66 (
struct V_36 * V_37 )
{
int error = 0 ;
if ( V_37 -> V_75 & V_76 ) {
ASSERT ( V_37 -> V_75 & V_78 ) ;
return 0 ;
}
V_37 -> V_92 -> V_93 |= V_94 ;
error = F_67 ( V_37 -> V_38 ) ;
if ( ! error )
F_68 ( V_37 ) ;
V_37 -> V_92 -> V_93 &= ~ V_94 ;
return error ;
}
int
F_69 (
struct V_36 * V_37 )
{
int error ;
error = F_61 ( V_37 -> V_38 ) ;
F_70 ( V_37 ) ;
return error ;
}
static int
F_71 ( T_8 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
T_11 * V_57 ;
#ifdef F_72
T_11 * V_95 ;
#endif
T_3 * V_16 = NULL ;
T_6 V_59 ;
int error ;
if ( V_37 -> V_75 & V_78 )
return 0 ;
error = F_73 ( V_37 , V_96 , NULL ) ;
ASSERT ( error || ! ( F_26 ( log ) ) ) ;
#ifdef F_72
V_95 = V_57 = log -> V_97 ;
do {
if ( ! ( V_57 -> V_64 & V_65 ) ) {
ASSERT ( V_57 -> V_64 & V_66 ) ;
ASSERT ( V_57 -> V_98 == 0 ) ;
}
V_57 = V_57 -> V_99 ;
} while ( V_57 != V_95 );
#endif
if ( ! ( F_26 ( log ) ) ) {
error = F_32 ( V_37 , 600 , 1 , & V_16 , V_50 , 0 ) ;
if ( ! error ) {
struct {
T_12 V_100 ;
T_12 V_101 ;
T_13 V_102 ;
} V_100 = {
. V_100 = V_103 ,
} ;
struct V_104 V_105 = {
. V_106 = & V_100 ,
. V_107 = sizeof( V_100 ) ,
. V_108 = V_109 ,
} ;
struct V_110 V_111 = {
. V_112 = 1 ,
. V_113 = & V_105 ,
} ;
V_16 -> V_19 = 0 ;
V_16 -> V_42 -= sizeof( V_100 ) ;
error = F_74 ( log , & V_111 , V_16 , & V_59 ,
NULL , V_114 ) ;
}
if ( error )
F_75 ( V_37 , L_12 , V_115 ) ;
F_12 ( & log -> V_116 ) ;
V_57 = log -> V_97 ;
F_76 ( & V_57 -> V_117 ) ;
F_77 ( log , V_57 ) ;
F_15 ( & log -> V_116 ) ;
error = F_46 ( log , V_57 ) ;
F_12 ( & log -> V_116 ) ;
if ( ! ( V_57 -> V_64 == V_66 ||
V_57 -> V_64 == V_118 ) ) {
if ( ! F_26 ( log ) ) {
F_78 ( & V_57 -> V_119 ,
& log -> V_116 ) ;
} else {
F_15 ( & log -> V_116 ) ;
}
} else {
F_15 ( & log -> V_116 ) ;
}
if ( V_16 ) {
F_79 ( log , V_16 ) ;
F_39 ( log , V_16 ) ;
F_42 ( V_16 ) ;
}
} else {
F_12 ( & log -> V_116 ) ;
V_57 = log -> V_97 ;
F_76 ( & V_57 -> V_117 ) ;
F_77 ( log , V_57 ) ;
F_15 ( & log -> V_116 ) ;
error = F_46 ( log , V_57 ) ;
F_12 ( & log -> V_116 ) ;
if ( ! ( V_57 -> V_64 == V_66
|| V_57 -> V_64 == V_118
|| V_57 -> V_64 == V_65 ) ) {
F_78 ( & V_57 -> V_119 ,
& log -> V_116 ) ;
} else {
F_15 ( & log -> V_116 ) ;
}
}
return error ;
}
void
F_80 (
struct V_36 * V_37 )
{
F_81 ( & V_37 -> V_38 -> V_120 ) ;
F_82 ( V_37 , V_96 ) ;
F_83 ( V_37 -> V_86 ) ;
F_84 ( V_37 -> V_121 ) ;
F_85 ( V_37 -> V_122 ) ;
F_86 ( V_37 -> V_122 ) ;
F_71 ( V_37 ) ;
}
void
F_70 (
struct V_36 * V_37 )
{
F_80 ( V_37 ) ;
F_64 ( V_37 ) ;
F_87 ( & V_37 -> V_38 -> V_89 ) ;
F_65 ( V_37 -> V_38 ) ;
}
void
F_88 (
struct V_36 * V_37 ,
struct V_123 * V_124 ,
int type ,
const struct V_125 * V_126 )
{
V_124 -> V_127 = V_37 ;
V_124 -> V_128 = V_37 -> V_86 ;
V_124 -> V_129 = type ;
V_124 -> V_130 = V_126 ;
V_124 -> V_131 = NULL ;
F_9 ( & V_124 -> V_132 ) ;
F_9 ( & V_124 -> V_133 ) ;
}
void
F_89 (
struct V_36 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_23 ;
if ( F_26 ( log ) )
return;
if ( ! F_22 ( & log -> V_18 . V_13 ) ) {
ASSERT ( ! ( log -> V_25 & V_26 ) ) ;
F_12 ( & log -> V_18 . V_14 ) ;
V_23 = F_21 ( log , & log -> V_18 . V_12 ) ;
F_17 ( log , & log -> V_18 , & V_23 ) ;
F_15 ( & log -> V_18 . V_14 ) ;
}
if ( ! F_22 ( & log -> V_54 . V_13 ) ) {
ASSERT ( ! ( log -> V_25 & V_26 ) ) ;
F_12 ( & log -> V_54 . V_14 ) ;
V_23 = F_21 ( log , & log -> V_54 . V_12 ) ;
F_17 ( log , & log -> V_54 , & V_23 ) ;
F_15 ( & log -> V_54 . V_14 ) ;
}
}
static int
F_90 ( T_8 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_134 = 0 ;
if ( ! F_91 ( V_37 , V_135 ) )
return 0 ;
if ( ! F_92 ( log ) )
return 0 ;
F_12 ( & log -> V_116 ) ;
switch ( log -> V_136 ) {
case V_137 :
case V_138 :
case V_139 :
break;
case V_140 :
case V_141 :
if ( F_93 ( log -> V_85 ) )
break;
if ( ! F_94 ( log ) )
break;
V_134 = 1 ;
if ( log -> V_136 == V_140 )
log -> V_136 = V_137 ;
else
log -> V_136 = V_138 ;
break;
default:
V_134 = 1 ;
break;
}
F_15 ( & log -> V_116 ) ;
return V_134 ;
}
T_6
F_95 (
struct V_36 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_123 * V_142 ;
T_6 V_143 ;
F_96 ( & V_37 -> V_86 -> V_144 ) ;
V_142 = F_97 ( V_37 -> V_86 ) ;
if ( V_142 )
V_143 = V_142 -> V_145 ;
else
V_143 = F_2 ( & log -> V_146 ) ;
F_98 ( log , V_143 ) ;
F_99 ( & log -> V_147 , V_143 ) ;
return V_143 ;
}
T_6
F_100 (
struct V_36 * V_37 )
{
T_6 V_143 ;
F_12 ( & V_37 -> V_86 -> V_144 ) ;
V_143 = F_95 ( V_37 ) ;
F_15 ( & V_37 -> V_86 -> V_144 ) ;
return V_143 ;
}
STATIC int
F_21 (
struct V_1 * log ,
T_1 * V_2 )
{
int V_23 ;
int V_148 ;
int V_149 ;
int V_150 ;
int V_151 ;
F_101 ( V_2 , & V_150 , & V_151 ) ;
F_102 ( & log -> V_147 , & V_149 , & V_148 ) ;
V_148 = F_103 ( V_148 ) ;
if ( V_149 == V_150 && V_151 >= V_148 )
V_23 = log -> V_9 - ( V_151 - V_148 ) ;
else if ( V_149 + 1 < V_150 )
return 0 ;
else if ( V_149 < V_150 ) {
ASSERT ( V_149 == ( V_150 - 1 ) ) ;
V_23 = V_148 - V_151 ;
} else {
F_75 ( log -> V_152 , L_13 ) ;
F_75 ( log -> V_152 ,
L_14 ,
V_149 , V_148 ) ;
F_75 ( log -> V_152 ,
L_15 ,
V_150 , V_151 ) ;
ASSERT ( 0 ) ;
V_23 = log -> V_9 ;
}
return V_23 ;
}
static void
F_104 ( T_14 * V_153 )
{
struct V_56 * V_57 = V_153 -> V_154 ;
struct V_1 * V_155 = V_57 -> V_156 ;
int V_157 = 0 ;
if ( F_105 ( V_153 -> V_158 , V_155 -> V_152 , V_159 ) ||
V_57 -> V_64 & V_160 ) {
if ( V_57 -> V_64 & V_160 )
V_57 -> V_64 &= ~ V_160 ;
F_106 ( V_153 , V_115 ) ;
F_107 ( V_153 ) ;
F_47 ( V_155 -> V_152 , V_70 ) ;
V_157 = V_161 ;
} else if ( V_57 -> V_64 & V_65 ) {
V_157 = V_161 ;
}
ASSERT ( V_153 -> V_162 & V_163 ) ;
F_108 ( V_57 , V_157 ) ;
F_86 ( V_153 ) ;
}
STATIC void
F_109 (
struct V_36 * V_37 ,
struct V_1 * log )
{
int V_164 ;
int V_165 ;
if ( V_37 -> V_166 <= 0 )
log -> V_167 = V_168 ;
else
log -> V_167 = V_37 -> V_166 ;
if ( V_37 -> V_169 > 0 ) {
V_164 = log -> V_170 = V_37 -> V_169 ;
log -> V_171 = 0 ;
while ( V_164 != 1 ) {
log -> V_171 ++ ;
V_164 >>= 1 ;
}
if ( F_110 ( & V_37 -> V_77 ) ) {
V_165 = V_37 -> V_169 / V_172 ;
if ( V_37 -> V_169 % V_172 )
V_165 ++ ;
log -> V_173 = V_165 << V_174 ;
log -> V_175 = V_165 ;
} else {
ASSERT ( V_37 -> V_169 <= V_176 ) ;
log -> V_173 = V_177 ;
log -> V_175 = 1 ;
}
goto V_178;
}
log -> V_170 = V_176 ;
log -> V_171 = V_179 ;
log -> V_173 = V_177 ;
log -> V_175 = 1 ;
V_178:
if ( V_37 -> V_166 == 0 )
V_37 -> V_166 = log -> V_167 ;
if ( V_37 -> V_169 == 0 )
V_37 -> V_169 = log -> V_170 ;
}
void
F_68 (
struct V_36 * V_37 )
{
F_111 ( V_37 -> V_180 , & V_37 -> V_38 -> V_120 ,
F_112 ( V_181 * 10 ) ) ;
}
static void
F_113 (
struct V_182 * V_183 )
{
struct V_1 * log = F_114 ( F_115 ( V_183 ) ,
struct V_1 , V_120 ) ;
struct V_36 * V_37 = log -> V_152 ;
if ( F_90 ( V_37 ) ) {
F_116 ( V_37 , true ) ;
} else
F_82 ( V_37 , 0 ) ;
F_117 ( V_37 -> V_86 ) ;
F_68 ( V_37 ) ;
}
STATIC struct V_1 *
F_51 (
struct V_36 * V_37 ,
struct V_184 * V_71 ,
T_10 V_72 ,
int V_73 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_185 ;
T_11 * V_57 , * V_186 = NULL ;
T_14 * V_153 ;
int V_187 ;
int error = - V_53 ;
T_4 V_188 = 0 ;
log = F_118 ( sizeof( struct V_1 ) , V_52 ) ;
if ( ! log ) {
F_55 ( V_37 , L_16 ) ;
goto V_79;
}
log -> V_152 = V_37 ;
log -> V_189 = V_71 ;
log -> V_9 = F_103 ( V_73 ) ;
log -> V_190 = V_72 ;
log -> V_191 = V_73 ;
log -> V_136 = V_139 ;
log -> V_25 |= V_26 ;
F_119 ( & log -> V_120 , F_113 ) ;
log -> V_192 = - 1 ;
F_120 ( & log -> V_147 , 1 , 0 ) ;
F_120 ( & log -> V_146 , 1 , 0 ) ;
log -> V_193 = 1 ;
F_7 ( & log -> V_54 ) ;
F_7 ( & log -> V_18 ) ;
error = - V_194 ;
if ( F_121 ( & V_37 -> V_77 ) ) {
V_188 = V_37 -> V_77 . V_195 ;
if ( V_188 < V_174 ) {
F_55 ( V_37 , L_17 ,
V_188 , V_174 ) ;
goto V_84;
}
V_188 -= V_174 ;
if ( V_188 > V_37 -> V_196 ) {
F_55 ( V_37 , L_18 ,
V_188 , V_37 -> V_196 ) ;
goto V_84;
}
if ( V_188 && log -> V_190 > 0 &&
! F_110 ( & V_37 -> V_77 ) ) {
F_55 ( V_37 ,
L_19 ,
V_188 ) ;
goto V_84;
}
}
log -> V_197 = 1 << V_188 ;
F_109 ( V_37 , log ) ;
error = - V_53 ;
V_153 = F_122 ( V_37 -> V_198 , V_199 ,
F_123 ( log -> V_170 ) , V_200 ) ;
if ( ! V_153 )
goto V_84;
ASSERT ( F_124 ( V_153 ) ) ;
F_86 ( V_153 ) ;
V_153 -> V_201 = V_37 -> V_202 ;
V_153 -> V_203 = F_104 ;
log -> V_204 = V_153 ;
F_10 ( & log -> V_116 ) ;
F_125 ( & log -> V_205 ) ;
V_185 = & log -> V_97 ;
ASSERT ( log -> V_170 >= 4096 ) ;
for ( V_187 = 0 ; V_187 < log -> V_167 ; V_187 ++ ) {
* V_185 = F_118 ( sizeof( T_11 ) , V_52 ) ;
if ( ! * V_185 )
goto V_206;
V_57 = * V_185 ;
V_57 -> V_207 = V_186 ;
V_186 = V_57 ;
V_153 = F_126 ( V_37 -> V_198 ,
F_123 ( log -> V_170 ) ,
V_200 ) ;
if ( ! V_153 )
goto V_206;
ASSERT ( F_124 ( V_153 ) ) ;
F_86 ( V_153 ) ;
V_153 -> V_201 = V_37 -> V_202 ;
V_153 -> V_203 = F_104 ;
V_57 -> V_208 = V_153 ;
V_57 -> V_209 = V_153 -> V_210 ;
#ifdef F_72
log -> V_211 [ V_187 ] = & V_57 -> V_212 ;
#endif
V_2 = & V_57 -> V_212 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_213 = F_127 ( V_214 ) ;
V_2 -> V_215 = F_127 (
F_110 ( & log -> V_152 -> V_77 ) ? 2 : 1 ) ;
V_2 -> V_216 = F_127 ( log -> V_170 ) ;
V_2 -> V_217 = F_127 ( V_218 ) ;
memcpy ( & V_2 -> V_219 , & V_37 -> V_77 . V_220 , sizeof( V_221 ) ) ;
V_57 -> V_222 = F_103 ( V_153 -> V_223 ) - log -> V_173 ;
V_57 -> V_64 = V_66 ;
V_57 -> V_156 = log ;
F_128 ( & V_57 -> V_117 , 0 ) ;
F_10 ( & V_57 -> V_63 ) ;
V_57 -> V_69 = & ( V_57 -> V_224 ) ;
V_57 -> V_225 = ( char * ) V_57 -> V_209 + log -> V_173 ;
F_125 ( & V_57 -> V_119 ) ;
F_125 ( & V_57 -> V_226 ) ;
V_185 = & V_57 -> V_99 ;
}
* V_185 = log -> V_97 ;
log -> V_97 -> V_207 = V_186 ;
error = F_129 ( log ) ;
if ( error )
goto V_206;
return log ;
V_206:
for ( V_57 = log -> V_97 ; V_57 ; V_57 = V_186 ) {
V_186 = V_57 -> V_99 ;
if ( V_57 -> V_208 )
F_130 ( V_57 -> V_208 ) ;
F_131 ( V_57 ) ;
}
F_132 ( & log -> V_116 ) ;
F_130 ( log -> V_204 ) ;
V_84:
F_131 ( log ) ;
V_79:
return F_133 ( error ) ;
}
STATIC int
F_37 (
struct V_1 * log ,
struct V_15 * V_55 ,
struct V_56 * * V_57 ,
T_6 * V_227 )
{
struct V_36 * V_37 = log -> V_152 ;
int error ;
struct V_104 V_105 = {
. V_106 = NULL ,
. V_107 = 0 ,
. V_108 = V_228 ,
} ;
struct V_110 V_111 = {
. V_112 = 1 ,
. V_113 = & V_105 ,
} ;
F_44 ( V_57 ) ;
error = F_74 ( log , & V_111 , V_55 , V_227 , V_57 ,
V_229 ) ;
if ( error )
F_47 ( V_37 , V_70 ) ;
return error ;
}
STATIC void
F_28 (
struct V_1 * log ,
int V_24 )
{
T_6 V_230 = 0 ;
T_6 V_231 ;
int V_232 ;
int V_23 ;
int V_233 ;
int V_234 ;
int V_235 ;
ASSERT ( F_123 ( V_24 ) < log -> V_191 ) ;
V_23 = F_21 ( log , & log -> V_54 . V_12 ) ;
V_232 = F_134 ( V_23 ) ;
V_235 = F_123 ( V_24 ) ;
V_235 = F_135 ( V_235 , ( log -> V_191 >> 2 ) ) ;
V_235 = F_135 ( V_235 , 256 ) ;
if ( V_232 >= V_235 )
return;
F_102 ( & log -> V_147 , & V_234 ,
& V_233 ) ;
V_233 += V_235 ;
if ( V_233 >= log -> V_191 ) {
V_233 -= log -> V_191 ;
V_234 += 1 ;
}
V_230 = F_136 ( V_234 ,
V_233 ) ;
V_231 = F_2 ( & log -> V_146 ) ;
if ( F_137 ( V_230 , V_231 ) > 0 )
V_230 = V_231 ;
if ( ! F_26 ( log ) )
F_138 ( log -> V_85 , V_230 ) ;
}
STATIC void
F_139 (
struct V_1 * log ,
struct V_56 * V_57 ,
int V_236 )
{
int V_187 , V_237 , V_238 ;
int V_164 = V_57 -> V_98 + V_236 ;
T_16 V_239 ;
char * V_240 ;
V_239 = F_140 ( V_57 -> V_212 . V_241 ) ;
V_240 = V_57 -> V_225 ;
for ( V_187 = 0 ; V_187 < F_123 ( V_164 ) ; V_187 ++ ) {
if ( V_187 >= ( V_172 / V_177 ) )
break;
V_57 -> V_212 . V_242 [ V_187 ] = * ( T_16 * ) V_240 ;
* ( T_16 * ) V_240 = V_239 ;
V_240 += V_177 ;
}
if ( F_110 ( & log -> V_152 -> V_77 ) ) {
T_17 * V_243 = V_57 -> V_209 ;
for ( ; V_187 < F_123 ( V_164 ) ; V_187 ++ ) {
V_237 = V_187 / ( V_172 / V_177 ) ;
V_238 = V_187 % ( V_172 / V_177 ) ;
V_243 [ V_237 ] . V_244 . V_245 [ V_238 ] = * ( T_16 * ) V_240 ;
* ( T_16 * ) V_240 = V_239 ;
V_240 += V_177 ;
}
for ( V_187 = 1 ; V_187 < log -> V_175 ; V_187 ++ )
V_243 [ V_187 ] . V_244 . V_246 = V_239 ;
}
}
T_18
F_141 (
struct V_1 * log ,
struct V_247 * V_248 ,
char * V_240 ,
int V_164 )
{
T_13 V_249 ;
V_249 = F_142 ( ( char * ) V_248 ,
sizeof( struct V_247 ) ,
F_143 ( struct V_247 , V_250 ) ) ;
if ( F_110 ( & log -> V_152 -> V_77 ) ) {
union V_251 * V_243 = (union V_251 * ) V_248 ;
int V_187 ;
int V_252 ;
V_252 = V_164 / V_172 ;
if ( V_164 % V_172 )
V_252 ++ ;
for ( V_187 = 1 ; V_187 < V_252 ; V_187 ++ ) {
V_249 = F_144 ( V_249 , & V_243 [ V_187 ] . V_244 ,
sizeof( struct V_253 ) ) ;
}
}
V_249 = F_144 ( V_249 , V_240 , V_164 ) ;
return F_145 ( V_249 ) ;
}
STATIC int
F_146 (
struct V_254 * V_153 )
{
struct V_56 * V_57 = V_153 -> V_154 ;
F_85 ( V_153 ) ;
if ( V_57 -> V_64 & V_65 ) {
F_147 ( V_153 , - V_39 ) ;
F_107 ( V_153 ) ;
F_148 ( V_153 ) ;
return 0 ;
}
F_149 ( V_153 ) ;
return 0 ;
}
STATIC int
F_150 (
struct V_1 * log ,
struct V_56 * V_57 )
{
T_14 * V_153 ;
int V_187 ;
T_4 V_255 ;
T_4 V_256 ;
int V_236 ;
int V_257 = 0 ;
int error ;
int V_258 = F_110 ( & log -> V_152 -> V_77 ) ;
int V_164 ;
F_27 ( log -> V_152 , V_259 ) ;
ASSERT ( F_151 ( & V_57 -> V_117 ) == 0 ) ;
V_256 = log -> V_173 + V_57 -> V_98 ;
if ( V_258 && log -> V_152 -> V_77 . V_260 > 1 ) {
V_255 = F_152 ( log , F_153 ( log , V_256 ) ) ;
} else {
V_255 = F_103 ( F_123 ( V_256 ) ) ;
}
V_236 = V_255 - V_256 ;
ASSERT ( V_236 >= 0 ) ;
ASSERT ( ( V_258 && log -> V_152 -> V_77 . V_260 > 1 &&
V_236 < log -> V_152 -> V_77 . V_260 )
||
( log -> V_152 -> V_77 . V_260 <= 1 &&
V_236 < F_103 ( 1 ) ) ) ;
F_6 ( log , & log -> V_54 . V_12 , V_236 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_236 ) ;
F_139 ( log , V_57 , V_236 ) ;
V_164 = V_57 -> V_98 ;
if ( V_258 )
V_164 += V_236 ;
V_57 -> V_212 . V_261 = F_127 ( V_164 ) ;
V_153 = V_57 -> V_208 ;
F_154 ( V_153 , F_155 ( F_156 ( V_57 -> V_212 . V_241 ) ) ) ;
F_157 ( log -> V_152 , V_262 , F_123 ( V_255 ) ) ;
if ( F_158 ( V_153 ) + F_123 ( V_255 ) > log -> V_191 ) {
char * V_263 ;
V_257 = V_255 - ( F_103 ( log -> V_191 - F_158 ( V_153 ) ) ) ;
V_255 = F_103 ( log -> V_191 - F_158 ( V_153 ) ) ;
V_57 -> V_264 = 2 ;
V_263 = ( char * ) & V_57 -> V_212 + V_255 ;
for ( V_187 = 0 ; V_187 < V_257 ; V_187 += V_177 ) {
T_13 V_7 = F_159 ( * ( T_16 * ) V_263 ) ;
if ( ++ V_7 == V_214 )
V_7 ++ ;
* ( T_16 * ) V_263 = F_127 ( V_7 ) ;
V_263 += V_177 ;
}
} else {
V_57 -> V_264 = 1 ;
}
V_57 -> V_212 . V_250 = F_141 ( log , & V_57 -> V_212 ,
V_57 -> V_225 , V_164 ) ;
if ( F_105 ( false , log -> V_152 , V_265 ) ) {
V_57 -> V_212 . V_250 &= F_160 ( 0xAAAAAAAA ) ;
V_57 -> V_64 |= V_160 ;
F_55 ( log -> V_152 ,
L_20 ,
F_156 ( V_57 -> V_212 . V_241 ) ) ;
}
V_153 -> V_266 = F_123 ( V_255 ) ;
V_153 -> V_154 = V_57 ;
V_153 -> V_162 &= ~ V_267 ;
V_153 -> V_162 |= ( V_163 | V_268 | V_269 | V_270 ) ;
if ( log -> V_152 -> V_198 != log -> V_152 -> V_121 )
F_161 ( log -> V_152 -> V_121 ) ;
else
V_153 -> V_162 |= V_267 ;
ASSERT ( F_158 ( V_153 ) <= log -> V_191 - 1 ) ;
ASSERT ( F_158 ( V_153 ) + F_123 ( V_255 ) <= log -> V_191 ) ;
F_162 ( log , V_57 , V_255 , true ) ;
F_154 ( V_153 , F_158 ( V_153 ) + log -> V_190 ) ;
error = F_146 ( V_153 ) ;
if ( error ) {
F_106 ( V_153 , L_21 ) ;
return error ;
}
if ( V_257 ) {
V_153 = V_57 -> V_156 -> V_204 ;
F_154 ( V_153 , 0 ) ;
F_163 ( V_153 ,
( char * ) & V_57 -> V_212 + V_255 , V_257 ) ;
V_153 -> V_154 = V_57 ;
V_153 -> V_162 &= ~ V_267 ;
V_153 -> V_162 |= ( V_163 | V_268 | V_269 | V_270 ) ;
ASSERT ( F_158 ( V_153 ) <= log -> V_191 - 1 ) ;
ASSERT ( F_158 ( V_153 ) + F_123 ( V_255 ) <= log -> V_191 ) ;
F_154 ( V_153 , F_158 ( V_153 ) + log -> V_190 ) ;
error = F_146 ( V_153 ) ;
if ( error ) {
F_106 ( V_153 , L_22 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_65 (
struct V_1 * log )
{
T_11 * V_57 , * V_271 ;
int V_187 ;
F_164 ( log ) ;
V_57 = log -> V_97 ;
for ( V_187 = 0 ; V_187 < log -> V_167 ; V_187 ++ ) {
F_85 ( V_57 -> V_208 ) ;
F_86 ( V_57 -> V_208 ) ;
V_57 = V_57 -> V_99 ;
}
F_85 ( log -> V_204 ) ;
F_86 ( log -> V_204 ) ;
F_165 ( log -> V_204 , F_123 ( log -> V_170 ) ) ;
F_130 ( log -> V_204 ) ;
V_57 = log -> V_97 ;
for ( V_187 = 0 ; V_187 < log -> V_167 ; V_187 ++ ) {
F_130 ( V_57 -> V_208 ) ;
V_271 = V_57 -> V_99 ;
F_131 ( V_57 ) ;
V_57 = V_271 ;
}
F_132 ( & log -> V_116 ) ;
log -> V_152 -> V_38 = NULL ;
F_131 ( log ) ;
}
static inline void
F_166 (
struct V_1 * log ,
struct V_56 * V_57 ,
int V_272 ,
int V_273 )
{
F_12 ( & log -> V_116 ) ;
F_167 ( & V_57 -> V_212 . V_274 , V_272 ) ;
V_57 -> V_98 += V_273 ;
F_15 ( & log -> V_116 ) ;
}
void
F_168 (
struct V_36 * V_37 ,
struct V_15 * V_55 )
{
T_4 V_187 ;
T_4 V_275 = V_55 -> V_29 * ( T_4 ) sizeof( V_276 ) ;
#define F_169 ( type , T_19 ) [XLOG_REG_TYPE_##type] = str
static char * V_277 [ V_278 + 1 ] = {
F_169 ( V_279 , L_23 ) ,
F_169 ( V_280 , L_24 ) ,
F_169 ( V_281 , L_25 ) ,
F_169 ( V_282 , L_26 ) ,
F_169 ( V_283 , L_27 ) ,
F_169 ( V_284 , L_28 ) ,
F_169 ( V_285 , L_29 ) ,
F_169 ( V_286 , L_30 ) ,
F_169 ( V_287 , L_31 ) ,
F_169 ( V_288 , L_32 ) ,
F_169 ( V_289 , L_33 ) ,
F_169 ( V_290 , L_34 ) ,
F_169 ( V_291 , L_35 ) ,
F_169 ( V_292 , L_36 ) ,
F_169 ( V_293 , L_37 ) ,
F_169 ( V_294 , L_38 ) ,
F_169 ( V_295 , L_39 ) ,
F_169 ( V_296 , L_40 ) ,
F_169 ( V_297 , L_41 ) ,
F_169 (ICREATE, L_42 )
} ;
#undef F_169
F_55 ( V_37 , L_43 ) ;
F_55 ( V_37 , L_44 ,
V_55 -> V_21 ) ;
F_55 ( V_37 , L_45 ,
V_55 -> V_42 ) ;
F_55 ( V_37 , L_46 ,
V_55 -> V_28 , V_55 -> V_32 ) ;
F_55 ( V_37 , L_47 ,
V_55 -> V_29 , V_275 ) ;
F_55 ( V_37 , L_48 ,
V_55 -> V_28 + V_55 -> V_32 + V_275 ) ;
F_55 ( V_37 , L_49 ,
V_55 -> V_27 ) ;
for ( V_187 = 0 ; V_187 < V_55 -> V_27 ; V_187 ++ ) {
T_4 V_35 = V_55 -> V_33 [ V_187 ] . V_35 ;
F_55 ( V_37 , L_50 , V_187 ,
( ( V_35 <= 0 || V_35 > V_278 ) ?
L_51 : V_277 [ V_35 ] ) ,
V_55 -> V_33 [ V_187 ] . V_34 ) ;
}
}
void
F_170 (
struct V_298 * V_299 )
{
struct V_36 * V_37 = V_299 -> V_300 ;
struct V_301 * V_302 ;
F_55 ( V_37 , L_52 ) ;
F_55 ( V_37 , L_53 , V_299 -> V_19 ) ;
F_168 ( V_37 , V_299 -> V_303 ) ;
F_13 (lidp, &tp->t_items, lid_trans) {
struct V_123 * V_142 = V_302 -> V_304 ;
struct V_110 * V_305 = V_142 -> V_131 ;
struct V_104 * V_111 ;
int V_187 ;
F_55 ( V_37 , L_54 ) ;
F_55 ( V_37 , L_55 , V_142 -> V_129 ) ;
F_55 ( V_37 , L_53 , V_142 -> V_306 ) ;
if ( ! V_305 )
continue;
F_55 ( V_37 , L_56 , V_305 -> V_112 ) ;
F_55 ( V_37 , L_57 , V_305 -> V_307 ) ;
F_55 ( V_37 , L_58 , V_305 -> V_308 ) ;
F_55 ( V_37 , L_59 , V_305 -> V_309 ) ;
V_111 = V_305 -> V_113 ;
for ( V_187 = 0 ; V_187 < V_305 -> V_112 ; V_187 ++ ) {
int V_310 = F_171 ( V_111 -> V_107 , 32 ) ;
F_55 ( V_37 , L_60 , V_187 ) ;
F_55 ( V_37 , L_61 , V_111 -> V_108 ) ;
F_55 ( V_37 , L_62 , V_111 -> V_107 ) ;
F_55 ( V_37 , L_63 , V_310 , V_187 ) ;
F_172 ( V_111 -> V_106 , V_310 ) ;
V_111 ++ ;
}
}
}
static int
F_173 (
struct V_15 * V_55 ,
struct V_110 * V_311 )
{
struct V_110 * V_305 ;
int V_312 = 0 ;
int V_30 = 0 ;
int V_187 ;
if ( V_55 -> V_19 & V_60 )
V_312 ++ ;
for ( V_305 = V_311 ; V_305 ; V_305 = V_305 -> V_313 ) {
if ( V_305 -> V_309 == V_314 )
continue;
V_312 += V_305 -> V_112 ;
for ( V_187 = 0 ; V_187 < V_305 -> V_112 ; V_187 ++ ) {
struct V_104 * V_315 = & V_305 -> V_113 [ V_187 ] ;
V_30 += V_315 -> V_107 ;
F_24 ( V_55 , V_315 -> V_107 , V_315 -> V_108 ) ;
}
}
V_55 -> V_29 += V_312 ;
V_30 += V_312 * sizeof( struct V_316 ) ;
return V_30 ;
}
static int
F_174 (
struct V_316 * V_317 ,
struct V_15 * V_55 )
{
if ( ! ( V_55 -> V_19 & V_60 ) )
return 0 ;
V_317 -> V_318 = F_127 ( V_55 -> V_41 ) ;
V_317 -> V_319 = V_55 -> V_320 ;
V_317 -> V_321 = 0 ;
V_317 -> V_322 = V_323 ;
V_317 -> V_324 = 0 ;
V_55 -> V_19 &= ~ V_60 ;
return sizeof( struct V_316 ) ;
}
static V_276 *
F_175 (
struct V_1 * log ,
struct V_316 * V_317 ,
struct V_15 * V_55 ,
T_4 V_325 )
{
V_317 -> V_318 = F_127 ( V_55 -> V_41 ) ;
V_317 -> V_319 = V_55 -> V_320 ;
V_317 -> V_324 = 0 ;
V_317 -> V_322 = V_325 ;
switch ( V_317 -> V_319 ) {
case V_49 :
case V_326 :
case V_50 :
break;
default:
F_55 ( log -> V_152 ,
L_64 ,
V_317 -> V_319 , V_55 ) ;
return NULL ;
}
return V_317 ;
}
static int
F_176 (
struct V_15 * V_55 ,
struct V_316 * V_317 ,
int V_327 ,
int V_328 ,
int * V_329 ,
int * V_330 ,
int * V_331 ,
int * V_332 )
{
int V_333 ;
V_333 = V_328 - * V_332 ;
* V_329 = * V_332 ;
if ( V_333 <= V_327 ) {
* V_330 = V_333 ;
V_317 -> V_321 = F_127 ( * V_330 ) ;
if ( * V_331 )
V_317 -> V_322 |= ( V_334 | V_335 ) ;
* V_331 = 0 ;
* V_332 = 0 ;
return 0 ;
}
* V_330 = V_327 ;
V_317 -> V_321 = F_127 ( * V_330 ) ;
V_317 -> V_322 |= V_336 ;
if ( * V_331 )
V_317 -> V_322 |= V_335 ;
* V_332 += * V_330 ;
( * V_331 ) ++ ;
V_55 -> V_42 -= sizeof( struct V_316 ) ;
V_55 -> V_29 ++ ;
return sizeof( struct V_316 ) ;
}
static int
F_177 (
struct V_1 * log ,
struct V_56 * V_57 ,
T_4 V_325 ,
int * V_272 ,
int * V_337 ,
int * V_338 ,
int * V_339 ,
int V_340 ,
struct V_56 * * V_341 )
{
if ( * V_338 ) {
F_166 ( log , V_57 , * V_272 , * V_337 ) ;
* V_272 = 0 ;
* V_337 = 0 ;
return F_46 ( log , V_57 ) ;
}
* V_338 = 0 ;
* V_339 = 0 ;
if ( V_57 -> V_222 - V_340 <= sizeof( V_276 ) ) {
F_166 ( log , V_57 , * V_272 , * V_337 ) ;
* V_272 = 0 ;
* V_337 = 0 ;
F_12 ( & log -> V_116 ) ;
F_77 ( log , V_57 ) ;
F_15 ( & log -> V_116 ) ;
if ( ! V_341 )
return F_46 ( log , V_57 ) ;
ASSERT ( V_325 & V_229 ) ;
* V_341 = V_57 ;
}
return 0 ;
}
int
F_74 (
struct V_1 * log ,
struct V_110 * V_311 ,
struct V_15 * V_55 ,
T_6 * V_342 ,
struct V_56 * * V_341 ,
T_4 V_325 )
{
struct V_56 * V_57 = NULL ;
struct V_104 * V_315 ;
struct V_110 * V_305 ;
int V_30 ;
int V_343 ;
int V_338 = 0 ;
int V_339 = 0 ;
int V_344 = 0 ;
int V_272 = 0 ;
int V_337 = 0 ;
int error ;
* V_342 = 0 ;
V_30 = F_173 ( V_55 , V_311 ) ;
if ( V_55 -> V_19 & V_60 )
V_55 -> V_42 -= sizeof( V_276 ) ;
if ( V_325 & ( V_229 | V_114 ) )
V_55 -> V_42 -= sizeof( V_276 ) ;
if ( V_55 -> V_42 < 0 ) {
F_178 ( log -> V_152 , V_345 ,
L_65 ) ;
F_168 ( log -> V_152 , V_55 ) ;
F_47 ( log -> V_152 , V_70 ) ;
}
V_343 = 0 ;
V_305 = V_311 ;
V_315 = V_305 -> V_113 ;
while ( V_305 && ( ! V_305 -> V_112 || V_343 < V_305 -> V_112 ) ) {
void * V_346 ;
int V_340 ;
error = F_179 ( log , V_30 , & V_57 , V_55 ,
& V_344 , & V_340 ) ;
if ( error )
return error ;
ASSERT ( V_340 <= V_57 -> V_222 - 1 ) ;
V_346 = V_57 -> V_225 + V_340 ;
if ( ! * V_342 )
* V_342 = F_156 ( V_57 -> V_212 . V_241 ) ;
while ( V_305 && ( ! V_305 -> V_112 || V_343 < V_305 -> V_112 ) ) {
struct V_104 * V_105 ;
struct V_316 * V_317 ;
int V_347 ;
int V_330 ;
int V_329 ;
bool V_348 = false ;
if ( V_305 -> V_309 == V_314 ) {
ASSERT ( V_305 -> V_112 == 0 ) ;
V_348 = true ;
goto V_349;
}
V_105 = & V_315 [ V_343 ] ;
ASSERT ( V_105 -> V_107 % sizeof( V_350 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_346 % sizeof( V_350 ) == 0 ) ;
V_347 = F_174 ( V_346 , V_55 ) ;
if ( V_347 ) {
V_272 ++ ;
F_180 ( & V_346 , & V_30 , & V_340 ,
V_347 ) ;
}
V_317 = F_175 ( log , V_346 , V_55 , V_325 ) ;
if ( ! V_317 )
return - V_39 ;
F_180 ( & V_346 , & V_30 , & V_340 ,
sizeof( struct V_316 ) ) ;
V_30 += F_176 ( V_55 , V_317 ,
V_57 -> V_222 - V_340 ,
V_105 -> V_107 ,
& V_329 , & V_330 ,
& V_338 ,
& V_339 ) ;
F_181 ( log , V_346 ) ;
ASSERT ( V_330 >= 0 ) ;
if ( V_330 > 0 ) {
memcpy ( V_346 , V_105 -> V_106 + V_329 , V_330 ) ;
F_180 ( & V_346 , & V_30 , & V_340 ,
V_330 ) ;
}
V_330 += V_347 + sizeof( V_276 ) ;
V_272 ++ ;
V_337 += V_344 ? V_330 : 0 ;
error = F_177 ( log , V_57 , V_325 ,
& V_272 , & V_337 ,
& V_338 ,
& V_339 ,
V_340 ,
V_341 ) ;
if ( error )
return error ;
if ( V_338 )
break;
if ( ++ V_343 == V_305 -> V_112 ) {
V_349:
V_305 = V_305 -> V_313 ;
V_343 = 0 ;
if ( V_305 )
V_315 = V_305 -> V_113 ;
}
if ( V_272 == 0 && V_348 == false ) {
if ( ! V_305 )
return 0 ;
break;
}
}
}
ASSERT ( V_30 == 0 ) ;
F_166 ( log , V_57 , V_272 , V_337 ) ;
if ( ! V_341 )
return F_46 ( log , V_57 ) ;
ASSERT ( V_325 & V_229 ) ;
* V_341 = V_57 ;
return 0 ;
}
STATIC void
F_182 (
struct V_1 * log )
{
T_11 * V_57 ;
int V_351 = 0 ;
V_57 = log -> V_97 ;
do {
if ( V_57 -> V_64 == V_118 ) {
V_57 -> V_64 = V_66 ;
V_57 -> V_98 = 0 ;
ASSERT ( V_57 -> V_224 == NULL ) ;
if ( ! V_351 &&
( F_159 ( V_57 -> V_212 . V_274 ) ==
V_352 ) ) {
V_351 = 1 ;
} else {
V_351 = 2 ;
}
V_57 -> V_212 . V_274 = 0 ;
memset ( V_57 -> V_212 . V_242 , 0 ,
sizeof( V_57 -> V_212 . V_242 ) ) ;
V_57 -> V_212 . V_241 = 0 ;
} else if ( V_57 -> V_64 == V_66 )
;
else
break;
V_57 = V_57 -> V_99 ;
} while ( V_57 != log -> V_97 );
if ( V_351 ) {
switch ( log -> V_136 ) {
case V_139 :
case V_140 :
case V_141 :
log -> V_136 = V_140 ;
break;
case V_137 :
if ( V_351 == 1 )
log -> V_136 = V_141 ;
else
log -> V_136 = V_140 ;
break;
case V_138 :
if ( V_351 == 1 )
log -> V_136 = V_139 ;
else
log -> V_136 = V_140 ;
break;
default:
ASSERT ( 0 ) ;
}
}
}
STATIC T_6
F_183 (
struct V_1 * log )
{
T_11 * V_353 ;
T_6 V_354 , V_59 ;
V_353 = log -> V_97 ;
V_354 = 0 ;
do {
if ( ! ( V_353 -> V_64 & ( V_66 | V_118 ) ) ) {
V_59 = F_156 ( V_353 -> V_212 . V_241 ) ;
if ( ( V_59 && ! V_354 ) ||
( F_137 ( V_59 , V_354 ) < 0 ) ) {
V_354 = V_59 ;
}
}
V_353 = V_353 -> V_99 ;
} while ( V_353 != log -> V_97 );
return V_354 ;
}
STATIC void
F_184 (
struct V_1 * log ,
int V_157 ,
struct V_56 * V_355 )
{
T_11 * V_57 ;
T_11 * V_95 ;
T_7 * V_61 , * V_68 ;
int V_356 = 0 ;
T_6 V_354 ;
int V_357 ;
int V_358 ;
int V_359 ;
int V_360 ;
int V_361 = 0 ;
F_12 ( & log -> V_116 ) ;
V_95 = V_57 = log -> V_97 ;
V_357 = 0 ;
V_359 = 0 ;
V_360 = 0 ;
do {
V_95 = log -> V_97 ;
V_57 = log -> V_97 ;
V_358 = 0 ;
V_360 ++ ;
do {
if ( V_57 -> V_64 &
( V_66 | V_118 ) ) {
V_57 = V_57 -> V_99 ;
continue;
}
if ( ! ( V_57 -> V_64 & V_65 ) ) {
if ( ! ( V_57 -> V_64 &
( V_362 |
V_363 ) ) ) {
if ( V_355 && ( V_355 -> V_64 ==
V_362 ) ) {
V_355 -> V_64 = V_363 ;
}
break;
}
V_354 = F_183 ( log ) ;
if ( V_354 &&
F_137 ( V_354 ,
F_156 ( V_57 -> V_212 . V_241 ) ) < 0 ) {
V_57 = V_57 -> V_99 ;
continue;
}
V_57 -> V_64 = V_364 ;
ASSERT ( F_137 ( F_2 ( & log -> V_146 ) ,
F_156 ( V_57 -> V_212 . V_241 ) ) <= 0 ) ;
if ( V_57 -> V_224 )
F_99 ( & log -> V_146 ,
F_156 ( V_57 -> V_212 . V_241 ) ) ;
} else
V_357 ++ ;
F_15 ( & log -> V_116 ) ;
F_12 ( & V_57 -> V_63 ) ;
V_61 = V_57 -> V_224 ;
while ( V_61 ) {
V_57 -> V_69 = & ( V_57 -> V_224 ) ;
V_57 -> V_224 = NULL ;
F_15 ( & V_57 -> V_63 ) ;
for (; V_61 ; V_61 = V_68 ) {
V_68 = V_61 -> V_68 ;
V_61 -> V_365 ( V_61 -> V_366 , V_157 ) ;
}
F_12 ( & V_57 -> V_63 ) ;
V_61 = V_57 -> V_224 ;
}
V_358 ++ ;
V_359 ++ ;
F_12 ( & log -> V_116 ) ;
ASSERT ( V_57 -> V_224 == NULL ) ;
F_15 ( & V_57 -> V_63 ) ;
if ( ! ( V_57 -> V_64 & V_65 ) )
V_57 -> V_64 = V_118 ;
F_182 ( log ) ;
F_185 ( & V_57 -> V_119 ) ;
V_57 = V_57 -> V_99 ;
} while ( V_95 != V_57 );
if ( V_360 > 5000 ) {
V_356 += V_360 ;
V_360 = 0 ;
F_55 ( log -> V_152 ,
L_66 ,
V_115 , V_356 ) ;
}
} while ( ! V_357 && V_358 );
#ifdef F_72
if ( V_359 ) {
V_95 = V_57 = log -> V_97 ;
do {
ASSERT ( V_57 -> V_64 != V_363 ) ;
if ( V_57 -> V_64 == V_67 ||
V_57 -> V_64 & V_367 ||
V_57 -> V_64 == V_362 ||
V_57 -> V_64 == V_65 )
break;
V_57 = V_57 -> V_99 ;
} while ( V_95 != V_57 );
}
#endif
if ( log -> V_97 -> V_64 & ( V_66 | V_65 ) )
V_361 = 1 ;
F_15 ( & log -> V_116 ) ;
if ( V_361 )
F_185 ( & log -> V_205 ) ;
}
STATIC void
F_108 (
T_11 * V_57 ,
int V_157 )
{
struct V_1 * log = V_57 -> V_156 ;
F_12 ( & log -> V_116 ) ;
ASSERT ( V_57 -> V_64 == V_367 ||
V_57 -> V_64 == V_65 ) ;
ASSERT ( F_151 ( & V_57 -> V_117 ) == 0 ) ;
ASSERT ( V_57 -> V_264 == 1 || V_57 -> V_264 == 2 ) ;
if ( V_57 -> V_64 != V_65 ) {
if ( -- V_57 -> V_264 == 1 ) {
F_15 ( & log -> V_116 ) ;
return;
}
V_57 -> V_64 = V_362 ;
}
F_185 ( & V_57 -> V_226 ) ;
F_15 ( & log -> V_116 ) ;
F_184 ( log , V_157 , V_57 ) ;
}
STATIC int
F_179 (
struct V_1 * log ,
int V_30 ,
struct V_56 * * V_185 ,
struct V_15 * V_55 ,
int * V_368 ,
int * V_369 )
{
int V_340 ;
T_15 * V_2 ;
T_11 * V_57 ;
int error ;
V_370:
F_12 ( & log -> V_116 ) ;
if ( F_26 ( log ) ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
V_57 = log -> V_97 ;
if ( V_57 -> V_64 != V_66 ) {
F_27 ( log -> V_152 , V_371 ) ;
F_78 ( & log -> V_205 , & log -> V_116 ) ;
goto V_370;
}
V_2 = & V_57 -> V_212 ;
F_76 ( & V_57 -> V_117 ) ;
V_340 = V_57 -> V_98 ;
if ( V_340 == 0 ) {
V_55 -> V_42 -= log -> V_173 ;
F_24 ( V_55 ,
log -> V_173 ,
V_372 ) ;
V_2 -> V_373 = F_127 ( log -> V_193 ) ;
V_2 -> V_241 = F_186 (
F_136 ( log -> V_193 , log -> V_374 ) ) ;
ASSERT ( log -> V_374 >= 0 ) ;
}
if ( V_57 -> V_222 - V_57 -> V_98 < 2 * sizeof( V_276 ) ) {
F_187 ( log , V_57 , V_57 -> V_222 ) ;
if ( ! F_188 ( & V_57 -> V_117 , - 1 , 1 ) ) {
F_15 ( & log -> V_116 ) ;
error = F_46 ( log , V_57 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_116 ) ;
}
goto V_370;
}
if ( V_30 <= V_57 -> V_222 - V_57 -> V_98 ) {
* V_368 = 0 ;
V_57 -> V_98 += V_30 ;
} else {
* V_368 = 1 ;
F_187 ( log , V_57 , V_57 -> V_222 ) ;
}
* V_185 = V_57 ;
ASSERT ( V_57 -> V_98 <= V_57 -> V_222 ) ;
F_15 ( & log -> V_116 ) ;
* V_369 = V_340 ;
return 0 ;
}
STATIC void
F_41 (
struct V_1 * log ,
struct V_15 * V_55 )
{
F_189 ( log , V_55 ) ;
if ( V_55 -> V_22 > 0 )
V_55 -> V_22 -- ;
F_1 ( log , & log -> V_54 . V_12 ,
V_55 -> V_42 ) ;
F_1 ( log , & log -> V_18 . V_12 ,
V_55 -> V_42 ) ;
V_55 -> V_42 = V_55 -> V_21 ;
F_23 ( V_55 ) ;
F_190 ( log , V_55 ) ;
if ( V_55 -> V_22 > 0 )
return;
F_6 ( log , & log -> V_54 . V_12 ,
V_55 -> V_21 ) ;
F_191 ( log , V_55 ) ;
V_55 -> V_42 = V_55 -> V_21 ;
F_23 ( V_55 ) ;
}
STATIC void
F_39 (
struct V_1 * log ,
struct V_15 * V_55 )
{
int V_3 ;
if ( V_55 -> V_22 > 0 )
V_55 -> V_22 -- ;
F_192 ( log , V_55 ) ;
F_193 ( log , V_55 ) ;
V_3 = V_55 -> V_42 ;
if ( V_55 -> V_22 > 0 ) {
ASSERT ( V_55 -> V_19 & V_20 ) ;
V_3 += V_55 -> V_21 * V_55 -> V_22 ;
}
F_1 ( log , & log -> V_54 . V_12 , V_3 ) ;
F_1 ( log , & log -> V_18 . V_12 , V_3 ) ;
F_194 ( log , V_55 ) ;
F_89 ( log -> V_152 ) ;
}
STATIC int
F_46 (
struct V_1 * log ,
struct V_56 * V_57 )
{
int V_375 = 0 ;
if ( V_57 -> V_64 & V_65 )
return - V_39 ;
ASSERT ( F_151 ( & V_57 -> V_117 ) > 0 ) ;
if ( ! F_195 ( & V_57 -> V_117 , & log -> V_116 ) )
return 0 ;
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
ASSERT ( V_57 -> V_64 == V_66 ||
V_57 -> V_64 == V_67 ) ;
if ( V_57 -> V_64 == V_67 ) {
T_6 V_143 = F_100 ( log -> V_152 ) ;
V_375 ++ ;
V_57 -> V_64 = V_367 ;
V_57 -> V_212 . V_376 = F_186 ( V_143 ) ;
F_196 ( log , V_57 , V_143 ) ;
}
F_15 ( & log -> V_116 ) ;
if ( V_375 )
return F_150 ( log , V_57 ) ;
return 0 ;
}
STATIC void
F_187 (
struct V_1 * log ,
struct V_56 * V_57 ,
int V_377 )
{
ASSERT ( V_57 -> V_64 == V_66 ) ;
if ( ! V_377 )
V_377 = V_57 -> V_98 ;
V_57 -> V_64 = V_67 ;
V_57 -> V_212 . V_378 = F_127 ( log -> V_192 ) ;
log -> V_192 = log -> V_374 ;
log -> V_379 = log -> V_193 ;
log -> V_374 += F_123 ( V_377 ) + F_123 ( log -> V_173 ) ;
if ( F_110 ( & log -> V_152 -> V_77 ) &&
log -> V_152 -> V_77 . V_260 > 1 ) {
T_13 V_380 = F_123 ( log -> V_152 -> V_77 . V_260 ) ;
log -> V_374 = F_197 ( log -> V_374 , V_380 ) ;
}
if ( log -> V_374 >= log -> V_191 ) {
log -> V_374 -= log -> V_191 ;
ASSERT ( log -> V_374 >= 0 ) ;
F_198 () ;
log -> V_193 ++ ;
if ( log -> V_193 == V_214 )
log -> V_193 ++ ;
}
ASSERT ( V_57 == log -> V_97 ) ;
log -> V_97 = V_57 -> V_99 ;
}
int
F_73 (
struct V_36 * V_37 ,
T_4 V_325 ,
int * V_381 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_56 * V_57 ;
T_6 V_59 ;
F_27 ( V_37 , V_382 ) ;
F_199 ( log ) ;
F_12 ( & log -> V_116 ) ;
V_57 = log -> V_97 ;
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
if ( V_57 -> V_64 == V_66 ||
V_57 -> V_64 == V_118 ) {
if ( V_57 -> V_64 == V_118 ||
( F_151 ( & V_57 -> V_117 ) == 0
&& V_57 -> V_98 == 0 ) ) {
V_57 = V_57 -> V_207 ;
if ( V_57 -> V_64 == V_66 ||
V_57 -> V_64 == V_118 )
goto V_383;
else
goto V_384;
} else {
if ( F_151 ( & V_57 -> V_117 ) == 0 ) {
F_76 ( & V_57 -> V_117 ) ;
V_59 = F_156 ( V_57 -> V_212 . V_241 ) ;
F_187 ( log , V_57 , 0 ) ;
F_15 ( & log -> V_116 ) ;
if ( F_46 ( log , V_57 ) )
return - V_39 ;
if ( V_381 )
* V_381 = 1 ;
F_12 ( & log -> V_116 ) ;
if ( F_156 ( V_57 -> V_212 . V_241 ) == V_59 &&
V_57 -> V_64 != V_118 )
goto V_384;
else
goto V_383;
} else {
F_187 ( log , V_57 , 0 ) ;
goto V_384;
}
}
}
V_384:
if ( V_325 & V_96 ) {
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_385 ) ;
F_78 ( & V_57 -> V_119 , & log -> V_116 ) ;
if ( V_57 -> V_64 & V_65 )
return - V_39 ;
if ( V_381 )
* V_381 = 1 ;
} else {
V_383:
F_15 ( & log -> V_116 ) ;
}
return 0 ;
}
void
F_82 (
T_8 * V_37 ,
T_4 V_325 )
{
F_200 ( V_37 , 0 , V_386 ) ;
F_73 ( V_37 , V_325 , NULL ) ;
}
int
F_201 (
struct V_36 * V_37 ,
T_6 V_59 ,
T_4 V_325 ,
int * V_381 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_56 * V_57 ;
int V_387 = 0 ;
ASSERT ( V_59 != 0 ) ;
F_27 ( V_37 , V_382 ) ;
V_59 = F_202 ( log , V_59 ) ;
if ( V_59 == V_388 )
return 0 ;
V_389:
F_12 ( & log -> V_116 ) ;
V_57 = log -> V_97 ;
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
do {
if ( F_156 ( V_57 -> V_212 . V_241 ) != V_59 ) {
V_57 = V_57 -> V_99 ;
continue;
}
if ( V_57 -> V_64 == V_118 ) {
F_15 ( & log -> V_116 ) ;
return 0 ;
}
if ( V_57 -> V_64 == V_66 ) {
if ( ! V_387 &&
( V_57 -> V_207 -> V_64 &
( V_67 | V_367 ) ) ) {
ASSERT ( ! ( V_57 -> V_64 & V_65 ) ) ;
F_27 ( V_37 , V_385 ) ;
F_78 ( & V_57 -> V_207 -> V_226 ,
& log -> V_116 ) ;
if ( V_381 )
* V_381 = 1 ;
V_387 = 1 ;
goto V_389;
}
F_76 ( & V_57 -> V_117 ) ;
F_187 ( log , V_57 , 0 ) ;
F_15 ( & log -> V_116 ) ;
if ( F_46 ( log , V_57 ) )
return - V_39 ;
if ( V_381 )
* V_381 = 1 ;
F_12 ( & log -> V_116 ) ;
}
if ( ( V_325 & V_96 ) &&
! ( V_57 -> V_64 &
( V_66 | V_118 ) ) ) {
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_385 ) ;
F_78 ( & V_57 -> V_119 , & log -> V_116 ) ;
if ( V_57 -> V_64 & V_65 )
return - V_39 ;
if ( V_381 )
* V_381 = 1 ;
} else {
F_15 ( & log -> V_116 ) ;
}
return 0 ;
} while ( V_57 != log -> V_97 );
F_15 ( & log -> V_116 ) ;
return 0 ;
}
void
F_203 (
T_8 * V_37 ,
T_6 V_59 ,
T_4 V_325 )
{
F_200 ( V_37 , V_59 , V_386 ) ;
F_201 ( V_37 , V_59 , V_325 , NULL ) ;
}
STATIC void
F_77 (
struct V_1 * log ,
struct V_56 * V_57 )
{
F_96 ( & log -> V_116 ) ;
if ( V_57 -> V_64 == V_66 ) {
F_187 ( log , V_57 , 0 ) ;
} else {
ASSERT ( V_57 -> V_64 &
( V_67 | V_65 ) ) ;
}
}
void
F_42 (
T_3 * V_55 )
{
ASSERT ( F_151 ( & V_55 -> V_390 ) > 0 ) ;
if ( F_204 ( & V_55 -> V_390 ) )
F_205 ( V_391 , V_55 ) ;
}
T_3 *
F_206 (
T_3 * V_55 )
{
ASSERT ( F_151 ( & V_55 -> V_390 ) > 0 ) ;
F_76 ( & V_55 -> V_390 ) ;
return V_55 ;
}
int
F_207 (
struct V_36 * V_37 ,
int V_44 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_392 ;
T_4 V_393 ;
V_44 += sizeof( V_276 ) ;
V_44 += sizeof( V_394 ) ;
V_44 += sizeof( V_276 ) ;
V_392 = log -> V_170 - log -> V_173 ;
V_393 = F_208 ( V_44 , V_392 ) ;
V_44 += sizeof( V_276 ) * V_393 ;
while ( ! V_393 ||
F_208 ( V_44 , V_392 ) > V_393 ) {
V_44 += sizeof( V_276 ) ;
V_393 ++ ;
}
V_44 += log -> V_173 * V_393 ;
V_44 += log -> V_173 ;
if ( F_110 ( & V_37 -> V_77 ) && V_37 -> V_77 . V_260 > 1 ) {
V_44 += 2 * V_37 -> V_77 . V_260 ;
} else {
V_44 += 2 * V_177 ;
}
return V_44 ;
}
struct V_15 *
F_33 (
struct V_1 * log ,
int V_44 ,
int V_45 ,
char V_47 ,
bool V_48 ,
T_20 V_395 )
{
struct V_15 * V_16 ;
int V_396 ;
V_16 = F_209 ( V_391 , V_395 ) ;
if ( ! V_16 )
return NULL ;
V_396 = F_207 ( log -> V_152 , V_44 ) ;
F_128 ( & V_16 -> V_390 , 1 ) ;
V_16 -> V_17 = V_397 ;
F_9 ( & V_16 -> V_398 ) ;
V_16 -> V_21 = V_396 ;
V_16 -> V_42 = V_396 ;
V_16 -> V_22 = V_45 ;
V_16 -> V_399 = V_45 ;
V_16 -> V_41 = F_210 () ;
V_16 -> V_320 = V_47 ;
V_16 -> V_19 = V_60 ;
if ( V_48 )
V_16 -> V_19 |= V_20 ;
F_23 ( V_16 ) ;
return V_16 ;
}
void
F_181 (
struct V_1 * log ,
void * V_346 )
{
int V_187 ;
int V_400 = 0 ;
for ( V_187 = 0 ; V_187 < log -> V_167 ; V_187 ++ ) {
if ( V_346 >= log -> V_211 [ V_187 ] &&
V_346 <= log -> V_211 [ V_187 ] + log -> V_170 )
V_400 ++ ;
}
if ( ! V_400 )
F_211 ( log -> V_152 , L_67 , V_115 ) ;
}
STATIC void
F_31 (
struct V_1 * log )
{
int V_149 , V_401 ;
int V_7 , V_8 ;
F_101 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_102 ( & log -> V_147 , & V_149 , & V_401 ) ;
if ( V_149 != V_7 ) {
if ( V_7 - 1 != V_149 &&
! ( log -> V_25 & V_402 ) ) {
F_178 ( log -> V_152 , V_345 ,
L_68 , V_115 ) ;
log -> V_25 |= V_402 ;
}
if ( V_8 > F_103 ( V_401 ) &&
! ( log -> V_25 & V_402 ) ) {
F_178 ( log -> V_152 , V_345 ,
L_69 , V_115 ) ;
log -> V_25 |= V_402 ;
}
}
}
STATIC void
F_196 (
struct V_1 * log ,
struct V_56 * V_57 ,
T_6 V_143 )
{
int V_403 ;
if ( F_212 ( V_143 ) == log -> V_379 ) {
V_403 =
log -> V_191 - ( log -> V_192 - F_155 ( V_143 ) ) ;
if ( V_403 < F_123 ( V_57 -> V_98 ) + F_123 ( log -> V_173 ) )
F_211 ( log -> V_152 , L_70 , V_115 ) ;
} else {
ASSERT ( F_212 ( V_143 ) + 1 == log -> V_379 ) ;
if ( F_155 ( V_143 ) == log -> V_192 )
F_211 ( log -> V_152 , L_71 , V_115 ) ;
V_403 = F_155 ( V_143 ) - log -> V_192 ;
if ( V_403 < F_123 ( V_57 -> V_98 ) + 1 )
F_211 ( log -> V_152 , L_70 , V_115 ) ;
}
}
STATIC void
F_162 (
struct V_1 * log ,
struct V_56 * V_57 ,
int V_255 ,
bool V_404 )
{
V_276 * V_405 ;
T_11 * V_406 ;
T_17 * V_243 ;
void * V_407 , * V_346 , * V_408 ;
T_21 V_409 ;
T_5 V_410 ;
int V_30 , V_187 , V_237 , V_238 , V_411 ;
int V_412 ;
F_12 ( & log -> V_116 ) ;
V_406 = log -> V_97 ;
for ( V_187 = 0 ; V_187 < log -> V_167 ; V_187 ++ , V_406 = V_406 -> V_99 )
ASSERT ( V_406 ) ;
if ( V_406 != log -> V_97 )
F_211 ( log -> V_152 , L_72 , V_115 ) ;
F_15 ( & log -> V_116 ) ;
if ( V_57 -> V_212 . V_213 != F_127 ( V_214 ) )
F_211 ( log -> V_152 , L_73 , V_115 ) ;
V_407 = V_346 = & V_57 -> V_212 ;
V_408 = & V_57 -> V_212 ;
for ( V_346 += V_177 ; V_346 < V_407 + V_255 ; V_346 += V_177 ) {
if ( * ( T_16 * ) V_346 == F_127 ( V_214 ) )
F_211 ( log -> V_152 , L_74 ,
V_115 ) ;
}
V_30 = F_159 ( V_57 -> V_212 . V_274 ) ;
V_407 = V_346 = V_57 -> V_225 ;
V_405 = V_346 ;
V_243 = V_57 -> V_209 ;
for ( V_187 = 0 ; V_187 < V_30 ; V_187 ++ ) {
V_405 = V_346 ;
V_408 = & V_405 -> V_319 ;
V_409 = V_408 - V_407 ;
if ( ! V_404 || ( V_409 & 0x1ff ) ) {
V_410 = V_405 -> V_319 ;
} else {
V_412 = F_134 ( ( char * ) & V_405 -> V_319 - V_57 -> V_225 ) ;
if ( V_412 >= ( V_172 / V_177 ) ) {
V_237 = V_412 / ( V_172 / V_177 ) ;
V_238 = V_412 % ( V_172 / V_177 ) ;
V_410 = F_213 (
V_243 [ V_237 ] . V_244 . V_245 [ V_238 ] ) ;
} else {
V_410 = F_213 (
V_57 -> V_212 . V_242 [ V_412 ] ) ;
}
}
if ( V_410 != V_49 && V_410 != V_50 )
F_55 ( log -> V_152 ,
L_75 ,
V_115 , V_410 , V_405 ,
( unsigned long ) V_409 ) ;
V_408 = & V_405 -> V_321 ;
V_409 = V_408 - V_407 ;
if ( ! V_404 || ( V_409 & 0x1ff ) ) {
V_411 = F_159 ( V_405 -> V_321 ) ;
} else {
V_412 = F_134 ( ( V_413 ) & V_405 -> V_321 -
( V_413 ) V_57 -> V_225 ) ;
if ( V_412 >= ( V_172 / V_177 ) ) {
V_237 = V_412 / ( V_172 / V_177 ) ;
V_238 = V_412 % ( V_172 / V_177 ) ;
V_411 = F_159 ( V_243 [ V_237 ] . V_244 . V_245 [ V_238 ] ) ;
} else {
V_411 = F_159 ( V_57 -> V_212 . V_242 [ V_412 ] ) ;
}
}
V_346 += sizeof( V_276 ) + V_411 ;
}
}
STATIC int
F_214 (
struct V_1 * log )
{
T_11 * V_57 , * V_414 ;
V_57 = log -> V_97 ;
if ( ! ( V_57 -> V_64 & V_65 ) ) {
V_414 = V_57 ;
do {
V_414 -> V_64 = V_65 ;
V_414 = V_414 -> V_99 ;
} while ( V_414 != V_57 );
return 0 ;
}
return 1 ;
}
int
F_215 (
struct V_36 * V_37 ,
int V_415 )
{
struct V_1 * log ;
int V_416 ;
log = V_37 -> V_38 ;
if ( ! log ||
log -> V_25 & V_26 ) {
V_37 -> V_75 |= V_417 ;
if ( V_37 -> V_122 )
V_37 -> V_122 -> V_162 |= V_418 ;
return 0 ;
}
if ( V_415 && log -> V_97 -> V_64 & V_65 ) {
ASSERT ( F_26 ( log ) ) ;
return 1 ;
}
if ( ! V_415 )
F_73 ( V_37 , V_96 , NULL ) ;
F_12 ( & log -> V_116 ) ;
V_37 -> V_75 |= V_417 ;
if ( V_37 -> V_122 )
V_37 -> V_122 -> V_162 |= V_418 ;
log -> V_25 |= V_419 ;
V_416 = F_214 ( log ) ;
F_15 ( & log -> V_116 ) ;
F_11 ( & log -> V_54 ) ;
F_11 ( & log -> V_18 ) ;
F_185 ( & log -> V_420 -> V_421 ) ;
F_184 ( log , V_161 , NULL ) ;
#ifdef F_216
{
T_11 * V_57 ;
F_12 ( & log -> V_116 ) ;
V_57 = log -> V_97 ;
do {
ASSERT ( V_57 -> V_224 == 0 ) ;
V_57 = V_57 -> V_99 ;
} while ( V_57 != log -> V_97 );
F_15 ( & log -> V_116 ) ;
}
#endif
return V_416 ;
}
STATIC int
F_94 (
struct V_1 * log )
{
T_11 * V_57 ;
V_57 = log -> V_97 ;
do {
if ( V_57 -> V_212 . V_274 )
return 0 ;
V_57 = V_57 -> V_99 ;
} while ( V_57 != log -> V_97 );
return 1 ;
}
bool
F_217 (
struct V_36 * V_37 ,
T_6 V_59 )
{
struct V_1 * log = V_37 -> V_38 ;
bool V_422 ;
if ( V_37 -> V_75 & V_76 )
return true ;
if ( V_59 == V_388 )
return true ;
V_422 = F_218 ( V_37 -> V_38 , V_59 ) ;
if ( ! V_422 ) {
F_12 ( & log -> V_116 ) ;
F_55 ( V_37 ,
L_76
L_77 ,
F_212 ( V_59 ) , F_155 ( V_59 ) ,
log -> V_193 , log -> V_374 ) ;
F_15 ( & log -> V_116 ) ;
}
return V_422 ;
}
