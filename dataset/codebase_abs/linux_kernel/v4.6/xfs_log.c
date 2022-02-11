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
bool V_48 ,
T_4 V_49 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_15 * V_16 ;
int V_24 ;
int error = 0 ;
ASSERT ( V_47 == V_50 || V_47 == V_51 ) ;
if ( F_26 ( log ) )
return - V_39 ;
F_27 ( V_37 , V_40 ) ;
ASSERT ( * V_46 == NULL ) ;
V_16 = F_33 ( log , V_44 , V_45 , V_47 , V_48 ,
V_52 | V_53 ) ;
if ( ! V_16 )
return - V_54 ;
V_16 -> V_55 = V_49 ;
* V_46 = V_16 ;
F_28 ( log , V_16 -> V_22 ? V_16 -> V_21 * V_16 -> V_22
: V_16 -> V_21 ) ;
F_34 ( log , V_16 ) ;
error = F_20 ( log , & log -> V_56 , V_16 ,
& V_24 ) ;
if ( error )
goto V_43;
F_6 ( log , & log -> V_56 . V_12 , V_24 ) ;
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
struct V_15 * V_57 ,
struct V_58 * * V_59 ,
bool V_60 )
{
struct V_1 * log = V_37 -> V_38 ;
T_6 V_61 = 0 ;
if ( F_26 ( log ) ||
( ( ( V_57 -> V_19 & V_62 ) == 0 ) &&
( F_37 ( log , V_57 , V_59 , & V_61 ) ) ) ) {
V_61 = ( T_6 ) - 1 ;
V_60 = false ;
}
if ( ! V_60 ) {
F_38 ( log , V_57 ) ;
F_39 ( log , V_57 ) ;
} else {
F_40 ( log , V_57 ) ;
F_41 ( log , V_57 ) ;
V_57 -> V_19 |= V_62 ;
}
F_42 ( V_57 ) ;
return V_61 ;
}
int
F_43 (
struct V_36 * V_37 ,
struct V_58 * V_59 ,
T_7 * V_63 )
{
int V_64 ;
F_12 ( & V_59 -> V_65 ) ;
V_64 = ( V_59 -> V_66 & V_67 ) ;
if ( ! V_64 ) {
F_44 ( ( V_59 -> V_66 == V_68 ) ||
( V_59 -> V_66 == V_69 ) ) ;
V_63 -> V_70 = NULL ;
* ( V_59 -> V_71 ) = V_63 ;
V_59 -> V_71 = & ( V_63 -> V_70 ) ;
}
F_15 ( & V_59 -> V_65 ) ;
return V_64 ;
}
int
F_45 (
struct V_36 * V_37 ,
struct V_58 * V_59 )
{
if ( F_46 ( V_37 -> V_38 , V_59 ) ) {
F_47 ( V_37 , V_72 ) ;
return - V_39 ;
}
return 0 ;
}
int
F_48 (
T_8 * V_37 ,
T_9 * V_73 ,
T_10 V_74 ,
int V_75 )
{
int error = 0 ;
int V_76 ;
if ( ! ( V_37 -> V_77 & V_78 ) ) {
F_49 ( V_37 , L_1 ,
F_50 ( & V_37 -> V_79 ) ) ;
} else {
F_49 ( V_37 ,
L_2 ,
F_50 ( & V_37 -> V_79 ) ) ;
ASSERT ( V_37 -> V_77 & V_80 ) ;
}
V_37 -> V_38 = F_51 ( V_37 , V_73 , V_74 , V_75 ) ;
if ( F_52 ( V_37 -> V_38 ) ) {
error = F_53 ( V_37 -> V_38 ) ;
goto V_81;
}
V_76 = F_54 ( V_37 ) ;
if ( V_37 -> V_79 . V_82 < V_76 ) {
F_55 ( V_37 ,
L_3 ,
V_37 -> V_79 . V_82 , V_76 ) ;
error = - V_83 ;
} else if ( V_37 -> V_79 . V_82 > V_84 ) {
F_55 ( V_37 ,
L_4 ,
V_37 -> V_79 . V_82 , V_84 ) ;
error = - V_83 ;
} else if ( F_56 ( V_37 , V_37 -> V_79 . V_82 ) > V_85 ) {
F_55 ( V_37 ,
L_5 ,
F_56 ( V_37 , V_37 -> V_79 . V_82 ) ,
V_85 ) ;
error = - V_83 ;
}
if ( error ) {
if ( F_57 ( & V_37 -> V_79 ) ) {
F_58 ( V_37 , L_6 ) ;
ASSERT ( 0 ) ;
goto V_86;
}
F_58 ( V_37 , L_7 ) ;
F_58 ( V_37 ,
L_8 ) ;
}
error = F_59 ( V_37 ) ;
if ( error ) {
F_55 ( V_37 , L_9 , error ) ;
goto V_86;
}
V_37 -> V_38 -> V_87 = V_37 -> V_88 ;
if ( ! ( V_37 -> V_77 & V_78 ) ) {
int V_89 = ( V_37 -> V_77 & V_80 ) ;
if ( V_89 )
V_37 -> V_77 &= ~ V_80 ;
error = F_60 ( V_37 -> V_38 ) ;
if ( V_89 )
V_37 -> V_77 |= V_80 ;
if ( error ) {
F_55 ( V_37 , L_10 ,
error ) ;
F_61 ( V_37 -> V_38 ) ;
goto V_90;
}
}
error = F_62 ( & V_37 -> V_38 -> V_91 , & V_92 , & V_37 -> V_93 ,
L_11 ) ;
if ( error )
goto V_90;
V_37 -> V_38 -> V_25 &= ~ V_26 ;
F_63 ( V_37 -> V_38 ) ;
return 0 ;
V_90:
F_64 ( V_37 ) ;
V_86:
F_65 ( V_37 -> V_38 ) ;
V_81:
return error ;
}
int
F_66 (
struct V_36 * V_37 )
{
int error = 0 ;
if ( V_37 -> V_77 & V_78 ) {
ASSERT ( V_37 -> V_77 & V_80 ) ;
return 0 ;
}
error = F_67 ( V_37 -> V_38 ) ;
if ( ! error )
F_68 ( V_37 ) ;
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
int
F_71 ( T_8 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
T_11 * V_59 ;
#ifdef F_72
T_11 * V_94 ;
#endif
T_3 * V_16 = NULL ;
T_6 V_61 ;
int error ;
if ( V_37 -> V_77 & V_80 )
return 0 ;
error = F_73 ( V_37 , V_95 , NULL ) ;
ASSERT ( error || ! ( F_26 ( log ) ) ) ;
#ifdef F_72
V_94 = V_59 = log -> V_96 ;
do {
if ( ! ( V_59 -> V_66 & V_67 ) ) {
ASSERT ( V_59 -> V_66 & V_68 ) ;
ASSERT ( V_59 -> V_97 == 0 ) ;
}
V_59 = V_59 -> V_98 ;
} while ( V_59 != V_94 );
#endif
if ( ! ( F_26 ( log ) ) ) {
error = F_32 ( V_37 , 600 , 1 , & V_16 ,
V_51 , 0 , V_99 ) ;
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
error = F_74 ( log , & V_111 , V_16 , & V_61 ,
NULL , V_114 ) ;
}
if ( error )
F_75 ( V_37 , L_12 , V_115 ) ;
F_12 ( & log -> V_116 ) ;
V_59 = log -> V_96 ;
F_76 ( & V_59 -> V_117 ) ;
F_77 ( log , V_59 ) ;
F_15 ( & log -> V_116 ) ;
error = F_46 ( log , V_59 ) ;
F_12 ( & log -> V_116 ) ;
if ( ! ( V_59 -> V_66 == V_68 ||
V_59 -> V_66 == V_118 ) ) {
if ( ! F_26 ( log ) ) {
F_78 ( & V_59 -> V_119 ,
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
V_59 = log -> V_96 ;
F_76 ( & V_59 -> V_117 ) ;
F_77 ( log , V_59 ) ;
F_15 ( & log -> V_116 ) ;
error = F_46 ( log , V_59 ) ;
F_12 ( & log -> V_116 ) ;
if ( ! ( V_59 -> V_66 == V_68
|| V_59 -> V_66 == V_118
|| V_59 -> V_66 == V_67 ) ) {
F_78 ( & V_59 -> V_119 ,
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
F_82 ( V_37 , V_95 ) ;
F_83 ( V_37 -> V_88 ) ;
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
F_87 ( & V_37 -> V_38 -> V_91 ) ;
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
V_124 -> V_128 = V_37 -> V_88 ;
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
if ( ! F_22 ( & log -> V_56 . V_13 ) ) {
ASSERT ( ! ( log -> V_25 & V_26 ) ) ;
F_12 ( & log -> V_56 . V_14 ) ;
V_23 = F_21 ( log , & log -> V_56 . V_12 ) ;
F_17 ( log , & log -> V_56 , & V_23 ) ;
F_15 ( & log -> V_56 . V_14 ) ;
}
}
int
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
if ( F_93 ( log -> V_87 ) )
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
F_96 ( & V_37 -> V_88 -> V_144 ) ;
V_142 = F_97 ( V_37 -> V_88 ) ;
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
F_12 ( & V_37 -> V_88 -> V_144 ) ;
V_143 = F_95 ( V_37 ) ;
F_15 ( & V_37 -> V_88 -> V_144 ) ;
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
void
F_104 ( T_14 * V_153 )
{
struct V_58 * V_59 = V_153 -> V_154 ;
struct V_1 * V_155 = V_59 -> V_156 ;
int V_157 = 0 ;
if ( F_105 ( V_153 -> V_158 , V_155 -> V_152 , V_159 ,
V_160 ) ||
V_59 -> V_66 & V_161 ) {
if ( V_59 -> V_66 & V_161 )
V_59 -> V_66 &= ~ V_161 ;
F_106 ( V_153 , V_115 ) ;
F_107 ( V_153 ) ;
F_47 ( V_155 -> V_152 , V_72 ) ;
V_157 = V_162 ;
} else if ( V_59 -> V_66 & V_67 ) {
V_157 = V_162 ;
}
ASSERT ( V_153 -> V_163 & V_164 ) ;
F_108 ( V_59 , V_157 ) ;
F_86 ( V_153 ) ;
}
STATIC void
F_109 (
struct V_36 * V_37 ,
struct V_1 * log )
{
int V_165 ;
int V_166 ;
if ( V_37 -> V_167 <= 0 )
log -> V_168 = V_169 ;
else
log -> V_168 = V_37 -> V_167 ;
if ( V_37 -> V_170 > 0 ) {
V_165 = log -> V_171 = V_37 -> V_170 ;
log -> V_172 = 0 ;
while ( V_165 != 1 ) {
log -> V_172 ++ ;
V_165 >>= 1 ;
}
if ( F_110 ( & V_37 -> V_79 ) ) {
V_166 = V_37 -> V_170 / V_173 ;
if ( V_37 -> V_170 % V_173 )
V_166 ++ ;
log -> V_174 = V_166 << V_175 ;
log -> V_176 = V_166 ;
} else {
ASSERT ( V_37 -> V_170 <= V_177 ) ;
log -> V_174 = V_178 ;
log -> V_176 = 1 ;
}
goto V_179;
}
log -> V_171 = V_177 ;
log -> V_172 = V_180 ;
log -> V_174 = V_178 ;
log -> V_176 = 1 ;
V_179:
if ( V_37 -> V_167 == 0 )
V_37 -> V_167 = log -> V_168 ;
if ( V_37 -> V_170 == 0 )
V_37 -> V_170 = log -> V_171 ;
}
void
F_68 (
struct V_36 * V_37 )
{
F_111 ( V_37 -> V_181 , & V_37 -> V_38 -> V_120 ,
F_112 ( V_182 * 10 ) ) ;
}
void
F_113 (
struct V_183 * V_184 )
{
struct V_1 * log = F_114 ( F_115 ( V_184 ) ,
struct V_1 , V_120 ) ;
struct V_36 * V_37 = log -> V_152 ;
if ( F_90 ( V_37 ) ) {
F_116 ( V_37 , true ) ;
} else
F_82 ( V_37 , 0 ) ;
F_117 ( V_37 -> V_88 ) ;
F_68 ( V_37 ) ;
}
STATIC struct V_1 *
F_51 (
struct V_36 * V_37 ,
struct V_185 * V_73 ,
T_10 V_74 ,
int V_75 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_186 ;
T_11 * V_59 , * V_187 = NULL ;
T_14 * V_153 ;
int V_188 ;
int error = - V_54 ;
T_4 V_189 = 0 ;
log = F_118 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! log ) {
F_55 ( V_37 , L_16 ) ;
goto V_81;
}
log -> V_152 = V_37 ;
log -> V_190 = V_73 ;
log -> V_9 = F_103 ( V_75 ) ;
log -> V_191 = V_74 ;
log -> V_192 = V_75 ;
log -> V_136 = V_139 ;
log -> V_25 |= V_26 ;
F_119 ( & log -> V_120 , F_113 ) ;
log -> V_193 = - 1 ;
F_120 ( & log -> V_147 , 1 , 0 ) ;
F_120 ( & log -> V_146 , 1 , 0 ) ;
log -> V_194 = 1 ;
F_7 ( & log -> V_56 ) ;
F_7 ( & log -> V_18 ) ;
error = - V_195 ;
if ( F_121 ( & V_37 -> V_79 ) ) {
V_189 = V_37 -> V_79 . V_196 ;
if ( V_189 < V_175 ) {
F_55 ( V_37 , L_17 ,
V_189 , V_175 ) ;
goto V_86;
}
V_189 -= V_175 ;
if ( V_189 > V_37 -> V_197 ) {
F_55 ( V_37 , L_18 ,
V_189 , V_37 -> V_197 ) ;
goto V_86;
}
if ( V_189 && log -> V_191 > 0 &&
! F_110 ( & V_37 -> V_79 ) ) {
F_55 ( V_37 ,
L_19 ,
V_189 ) ;
goto V_86;
}
}
log -> V_198 = 1 << V_189 ;
F_109 ( V_37 , log ) ;
error = - V_54 ;
V_153 = F_122 ( V_37 -> V_199 , V_200 ,
F_123 ( log -> V_171 ) , 0 ) ;
if ( ! V_153 )
goto V_86;
ASSERT ( F_124 ( V_153 ) ) ;
F_86 ( V_153 ) ;
V_153 -> V_201 = V_37 -> V_181 ;
V_153 -> V_202 = F_104 ;
log -> V_203 = V_153 ;
F_10 ( & log -> V_116 ) ;
F_125 ( & log -> V_204 ) ;
V_186 = & log -> V_96 ;
ASSERT ( log -> V_171 >= 4096 ) ;
for ( V_188 = 0 ; V_188 < log -> V_168 ; V_188 ++ ) {
* V_186 = F_118 ( sizeof( T_11 ) , V_53 ) ;
if ( ! * V_186 )
goto V_205;
V_59 = * V_186 ;
V_59 -> V_206 = V_187 ;
V_187 = V_59 ;
V_153 = F_126 ( V_37 -> V_199 ,
F_123 ( log -> V_171 ) , 0 ) ;
if ( ! V_153 )
goto V_205;
ASSERT ( F_124 ( V_153 ) ) ;
F_86 ( V_153 ) ;
V_153 -> V_201 = V_37 -> V_181 ;
V_153 -> V_202 = F_104 ;
V_59 -> V_207 = V_153 ;
V_59 -> V_208 = V_153 -> V_209 ;
#ifdef F_72
log -> V_210 [ V_188 ] = & V_59 -> V_211 ;
#endif
V_2 = & V_59 -> V_211 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_212 = F_127 ( V_213 ) ;
V_2 -> V_214 = F_127 (
F_110 ( & log -> V_152 -> V_79 ) ? 2 : 1 ) ;
V_2 -> V_215 = F_127 ( log -> V_171 ) ;
V_2 -> V_216 = F_127 ( V_217 ) ;
memcpy ( & V_2 -> V_218 , & V_37 -> V_79 . V_219 , sizeof( V_220 ) ) ;
V_59 -> V_221 = F_103 ( V_153 -> V_222 ) - log -> V_174 ;
V_59 -> V_66 = V_68 ;
V_59 -> V_156 = log ;
F_128 ( & V_59 -> V_117 , 0 ) ;
F_10 ( & V_59 -> V_65 ) ;
V_59 -> V_71 = & ( V_59 -> V_223 ) ;
V_59 -> V_224 = ( char * ) V_59 -> V_208 + log -> V_174 ;
F_125 ( & V_59 -> V_119 ) ;
F_125 ( & V_59 -> V_225 ) ;
V_186 = & V_59 -> V_98 ;
}
* V_186 = log -> V_96 ;
log -> V_96 -> V_206 = V_187 ;
error = F_129 ( log ) ;
if ( error )
goto V_205;
return log ;
V_205:
for ( V_59 = log -> V_96 ; V_59 ; V_59 = V_187 ) {
V_187 = V_59 -> V_98 ;
if ( V_59 -> V_207 )
F_130 ( V_59 -> V_207 ) ;
F_131 ( V_59 ) ;
}
F_132 ( & log -> V_116 ) ;
F_130 ( log -> V_203 ) ;
V_86:
F_131 ( log ) ;
V_81:
return F_133 ( error ) ;
}
STATIC int
F_37 (
struct V_1 * log ,
struct V_15 * V_57 ,
struct V_58 * * V_59 ,
T_6 * V_226 )
{
struct V_36 * V_37 = log -> V_152 ;
int error ;
struct V_104 V_105 = {
. V_106 = NULL ,
. V_107 = 0 ,
. V_108 = V_227 ,
} ;
struct V_110 V_111 = {
. V_112 = 1 ,
. V_113 = & V_105 ,
} ;
F_44 ( V_59 ) ;
error = F_74 ( log , & V_111 , V_57 , V_226 , V_59 ,
V_228 ) ;
if ( error )
F_47 ( V_37 , V_72 ) ;
return error ;
}
STATIC void
F_28 (
struct V_1 * log ,
int V_24 )
{
T_6 V_229 = 0 ;
T_6 V_230 ;
int V_231 ;
int V_23 ;
int V_232 ;
int V_233 ;
int V_234 ;
ASSERT ( F_123 ( V_24 ) < log -> V_192 ) ;
V_23 = F_21 ( log , & log -> V_56 . V_12 ) ;
V_231 = F_134 ( V_23 ) ;
V_234 = F_123 ( V_24 ) ;
V_234 = F_135 ( V_234 , ( log -> V_192 >> 2 ) ) ;
V_234 = F_135 ( V_234 , 256 ) ;
if ( V_231 >= V_234 )
return;
F_102 ( & log -> V_147 , & V_233 ,
& V_232 ) ;
V_232 += V_234 ;
if ( V_232 >= log -> V_192 ) {
V_232 -= log -> V_192 ;
V_233 += 1 ;
}
V_229 = F_136 ( V_233 ,
V_232 ) ;
V_230 = F_2 ( & log -> V_146 ) ;
if ( F_137 ( V_229 , V_230 ) > 0 )
V_229 = V_230 ;
if ( ! F_26 ( log ) )
F_138 ( log -> V_87 , V_229 ) ;
}
STATIC void
F_139 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_235 )
{
int V_188 , V_236 , V_237 ;
int V_165 = V_59 -> V_97 + V_235 ;
T_16 V_238 ;
char * V_239 ;
V_238 = F_140 ( V_59 -> V_211 . V_240 ) ;
V_239 = V_59 -> V_224 ;
for ( V_188 = 0 ; V_188 < F_123 ( V_165 ) ; V_188 ++ ) {
if ( V_188 >= ( V_173 / V_178 ) )
break;
V_59 -> V_211 . V_241 [ V_188 ] = * ( T_16 * ) V_239 ;
* ( T_16 * ) V_239 = V_238 ;
V_239 += V_178 ;
}
if ( F_110 ( & log -> V_152 -> V_79 ) ) {
T_17 * V_242 = V_59 -> V_208 ;
for ( ; V_188 < F_123 ( V_165 ) ; V_188 ++ ) {
V_236 = V_188 / ( V_173 / V_178 ) ;
V_237 = V_188 % ( V_173 / V_178 ) ;
V_242 [ V_236 ] . V_243 . V_244 [ V_237 ] = * ( T_16 * ) V_239 ;
* ( T_16 * ) V_239 = V_238 ;
V_239 += V_178 ;
}
for ( V_188 = 1 ; V_188 < log -> V_176 ; V_188 ++ )
V_242 [ V_188 ] . V_243 . V_245 = V_238 ;
}
}
T_18
F_141 (
struct V_1 * log ,
struct V_246 * V_247 ,
char * V_239 ,
int V_165 )
{
T_13 V_248 ;
V_248 = F_142 ( ( char * ) V_247 ,
sizeof( struct V_246 ) ,
F_143 ( struct V_246 , V_249 ) ) ;
if ( F_110 ( & log -> V_152 -> V_79 ) ) {
union V_250 * V_242 = (union V_250 * ) V_247 ;
int V_188 ;
int V_251 ;
V_251 = V_165 / V_173 ;
if ( V_165 % V_173 )
V_251 ++ ;
for ( V_188 = 1 ; V_188 < V_251 ; V_188 ++ ) {
V_248 = F_144 ( V_248 , & V_242 [ V_188 ] . V_243 ,
sizeof( struct V_252 ) ) ;
}
}
V_248 = F_144 ( V_248 , V_239 , V_165 ) ;
return F_145 ( V_248 ) ;
}
STATIC int
F_146 (
struct V_253 * V_153 )
{
struct V_58 * V_59 = V_153 -> V_154 ;
F_85 ( V_153 ) ;
if ( V_59 -> V_66 & V_67 ) {
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
struct V_58 * V_59 )
{
T_14 * V_153 ;
int V_188 ;
T_4 V_254 ;
T_4 V_255 ;
int V_235 ;
int V_256 = 0 ;
int error ;
int V_257 = F_110 ( & log -> V_152 -> V_79 ) ;
int V_165 ;
F_27 ( log -> V_152 , V_258 ) ;
ASSERT ( F_151 ( & V_59 -> V_117 ) == 0 ) ;
V_255 = log -> V_174 + V_59 -> V_97 ;
if ( V_257 && log -> V_152 -> V_79 . V_259 > 1 ) {
V_254 = F_152 ( log , F_153 ( log , V_255 ) ) ;
} else {
V_254 = F_103 ( F_123 ( V_255 ) ) ;
}
V_235 = V_254 - V_255 ;
ASSERT ( V_235 >= 0 ) ;
ASSERT ( ( V_257 && log -> V_152 -> V_79 . V_259 > 1 &&
V_235 < log -> V_152 -> V_79 . V_259 )
||
( log -> V_152 -> V_79 . V_259 <= 1 &&
V_235 < F_103 ( 1 ) ) ) ;
F_6 ( log , & log -> V_56 . V_12 , V_235 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_235 ) ;
F_139 ( log , V_59 , V_235 ) ;
V_165 = V_59 -> V_97 ;
if ( V_257 )
V_165 += V_235 ;
V_59 -> V_211 . V_260 = F_127 ( V_165 ) ;
V_153 = V_59 -> V_207 ;
F_154 ( V_153 , F_155 ( F_156 ( V_59 -> V_211 . V_240 ) ) ) ;
F_157 ( log -> V_152 , V_261 , F_123 ( V_254 ) ) ;
if ( F_158 ( V_153 ) + F_123 ( V_254 ) > log -> V_192 ) {
char * V_262 ;
V_256 = V_254 - ( F_103 ( log -> V_192 - F_158 ( V_153 ) ) ) ;
V_254 = F_103 ( log -> V_192 - F_158 ( V_153 ) ) ;
V_59 -> V_263 = 2 ;
V_262 = ( char * ) & V_59 -> V_211 + V_254 ;
for ( V_188 = 0 ; V_188 < V_256 ; V_188 += V_178 ) {
T_13 V_7 = F_159 ( * ( T_16 * ) V_262 ) ;
if ( ++ V_7 == V_213 )
V_7 ++ ;
* ( T_16 * ) V_262 = F_127 ( V_7 ) ;
V_262 += V_178 ;
}
} else {
V_59 -> V_263 = 1 ;
}
V_59 -> V_211 . V_249 = F_141 ( log , & V_59 -> V_211 ,
V_59 -> V_224 , V_165 ) ;
#ifdef F_72
if ( log -> V_264 &&
( F_160 () % log -> V_264 == 0 ) ) {
V_59 -> V_211 . V_249 &= 0xAAAAAAAA ;
V_59 -> V_66 |= V_161 ;
F_55 ( log -> V_152 ,
L_20 ,
F_156 ( V_59 -> V_211 . V_240 ) ) ;
}
#endif
V_153 -> V_265 = F_123 ( V_254 ) ;
V_153 -> V_154 = V_59 ;
V_153 -> V_163 &= ~ ( V_266 | V_267 ) ;
V_153 -> V_163 |= ( V_164 | V_268 | V_269 ) ;
if ( log -> V_152 -> V_77 & V_270 ) {
V_153 -> V_163 |= V_266 ;
if ( log -> V_152 -> V_199 != log -> V_152 -> V_121 )
F_161 ( log -> V_152 -> V_121 ) ;
else
V_153 -> V_163 |= V_267 ;
}
ASSERT ( F_158 ( V_153 ) <= log -> V_192 - 1 ) ;
ASSERT ( F_158 ( V_153 ) + F_123 ( V_254 ) <= log -> V_192 ) ;
F_162 ( log , V_59 , V_254 , true ) ;
F_154 ( V_153 , F_158 ( V_153 ) + log -> V_191 ) ;
error = F_146 ( V_153 ) ;
if ( error ) {
F_106 ( V_153 , L_21 ) ;
return error ;
}
if ( V_256 ) {
V_153 = V_59 -> V_156 -> V_203 ;
F_154 ( V_153 , 0 ) ;
F_163 ( V_153 ,
( char * ) & V_59 -> V_211 + V_254 , V_256 ) ;
V_153 -> V_154 = V_59 ;
V_153 -> V_163 &= ~ ( V_266 | V_267 ) ;
V_153 -> V_163 |= ( V_164 | V_268 | V_269 ) ;
if ( log -> V_152 -> V_77 & V_270 )
V_153 -> V_163 |= V_266 ;
ASSERT ( F_158 ( V_153 ) <= log -> V_192 - 1 ) ;
ASSERT ( F_158 ( V_153 ) + F_123 ( V_254 ) <= log -> V_192 ) ;
F_154 ( V_153 , F_158 ( V_153 ) + log -> V_191 ) ;
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
T_11 * V_59 , * V_271 ;
int V_188 ;
F_164 ( log ) ;
V_59 = log -> V_96 ;
for ( V_188 = 0 ; V_188 < log -> V_168 ; V_188 ++ ) {
F_85 ( V_59 -> V_207 ) ;
F_86 ( V_59 -> V_207 ) ;
V_59 = V_59 -> V_98 ;
}
F_85 ( log -> V_203 ) ;
F_86 ( log -> V_203 ) ;
F_165 ( log -> V_203 , F_123 ( log -> V_171 ) ) ;
F_130 ( log -> V_203 ) ;
V_59 = log -> V_96 ;
for ( V_188 = 0 ; V_188 < log -> V_168 ; V_188 ++ ) {
F_130 ( V_59 -> V_207 ) ;
V_271 = V_59 -> V_98 ;
F_131 ( V_59 ) ;
V_59 = V_271 ;
}
F_132 ( & log -> V_116 ) ;
log -> V_152 -> V_38 = NULL ;
F_131 ( log ) ;
}
static inline void
F_166 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_272 ,
int V_273 )
{
F_12 ( & log -> V_116 ) ;
F_167 ( & V_59 -> V_211 . V_274 , V_272 ) ;
V_59 -> V_97 += V_273 ;
F_15 ( & log -> V_116 ) ;
}
void
F_168 (
struct V_36 * V_37 ,
struct V_15 * V_57 )
{
T_4 V_188 ;
T_4 V_275 = V_57 -> V_29 * ( T_4 ) sizeof( V_276 ) ;
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
#define F_170 ( type ) [XFS_TRANS_##type] = #type
static char * V_298 [ V_299 ] = {
F_170 ( V_300 ) ,
F_170 ( V_301 ) ,
F_170 ( V_302 ) ,
F_170 ( V_303 ) ,
F_170 ( V_304 ) ,
F_170 ( V_305 ) ,
F_170 ( REMOVE ) ,
F_170 ( V_306 ) ,
F_170 ( RENAME ) ,
F_170 ( V_307 ) ,
F_170 ( V_308 ) ,
F_170 ( V_309 ) ,
F_170 ( V_310 ) ,
F_170 ( V_311 ) ,
F_170 ( V_312 ) ,
F_170 ( V_313 ) ,
F_170 ( V_314 ) ,
F_170 ( V_315 ) ,
F_170 ( V_316 ) ,
F_170 ( V_317 ) ,
F_170 ( V_318 ) ,
F_170 ( V_319 ) ,
F_170 ( V_320 ) ,
F_170 ( V_321 ) ,
F_170 ( V_322 ) ,
F_170 ( V_323 ) ,
F_170 ( V_324 ) ,
F_170 ( V_325 ) ,
F_170 ( V_326 ) ,
F_170 ( V_327 ) ,
F_170 ( V_328 ) ,
F_170 ( V_329 ) ,
F_170 ( V_330 ) ,
F_170 ( V_331 ) ,
F_170 ( V_332 ) ,
F_170 ( V_333 ) ,
F_170 ( V_334 ) ,
F_170 ( V_335 ) ,
F_170 ( V_336 ) ,
F_170 ( V_337 ) ,
F_170 (CREATE_TMPFILE)
} ;
#undef F_170
F_55 ( V_37 , L_43 ) ;
F_55 ( V_37 , L_44 ,
( ( V_57 -> V_55 <= 0 ||
V_57 -> V_55 > V_299 ) ?
L_45 : V_298 [ V_57 -> V_55 ] ) ,
V_57 -> V_55 ) ;
F_55 ( V_37 , L_46 ,
V_57 -> V_21 ) ;
F_55 ( V_37 , L_47 ,
V_57 -> V_42 ) ;
F_55 ( V_37 , L_48 ,
V_57 -> V_28 , V_57 -> V_32 ) ;
F_55 ( V_37 , L_49 ,
V_57 -> V_29 , V_275 ) ;
F_55 ( V_37 , L_50 ,
V_57 -> V_28 + V_57 -> V_32 + V_275 ) ;
F_55 ( V_37 , L_51 ,
V_57 -> V_27 ) ;
for ( V_188 = 0 ; V_188 < V_57 -> V_27 ; V_188 ++ ) {
T_4 V_35 = V_57 -> V_33 [ V_188 ] . V_35 ;
F_55 ( V_37 , L_52 , V_188 ,
( ( V_35 <= 0 || V_35 > V_278 ) ?
L_53 : V_277 [ V_35 ] ) ,
V_57 -> V_33 [ V_188 ] . V_34 ) ;
}
F_171 ( V_37 , V_338 ,
L_54 ) ;
F_47 ( V_37 , V_72 ) ;
}
static int
F_172 (
struct V_15 * V_57 ,
struct V_110 * V_339 )
{
struct V_110 * V_340 ;
int V_341 = 0 ;
int V_30 = 0 ;
int V_188 ;
if ( V_57 -> V_19 & V_62 )
V_341 ++ ;
for ( V_340 = V_339 ; V_340 ; V_340 = V_340 -> V_342 ) {
if ( V_340 -> V_343 == V_344 )
continue;
V_341 += V_340 -> V_112 ;
for ( V_188 = 0 ; V_188 < V_340 -> V_112 ; V_188 ++ ) {
struct V_104 * V_345 = & V_340 -> V_113 [ V_188 ] ;
V_30 += V_345 -> V_107 ;
F_24 ( V_57 , V_345 -> V_107 , V_345 -> V_108 ) ;
}
}
V_57 -> V_29 += V_341 ;
V_30 += V_341 * sizeof( struct V_346 ) ;
return V_30 ;
}
static int
F_173 (
struct V_346 * V_347 ,
struct V_15 * V_57 )
{
if ( ! ( V_57 -> V_19 & V_62 ) )
return 0 ;
V_347 -> V_348 = F_127 ( V_57 -> V_41 ) ;
V_347 -> V_349 = V_57 -> V_350 ;
V_347 -> V_351 = 0 ;
V_347 -> V_352 = V_353 ;
V_347 -> V_354 = 0 ;
V_57 -> V_19 &= ~ V_62 ;
return sizeof( struct V_346 ) ;
}
static V_276 *
F_174 (
struct V_1 * log ,
struct V_346 * V_347 ,
struct V_15 * V_57 ,
T_4 V_355 )
{
V_347 -> V_348 = F_127 ( V_57 -> V_41 ) ;
V_347 -> V_349 = V_57 -> V_350 ;
V_347 -> V_354 = 0 ;
V_347 -> V_352 = V_355 ;
switch ( V_347 -> V_349 ) {
case V_50 :
case V_356 :
case V_51 :
break;
default:
F_55 ( log -> V_152 ,
L_55 ,
V_347 -> V_349 , V_57 ) ;
return NULL ;
}
return V_347 ;
}
static int
F_175 (
struct V_15 * V_57 ,
struct V_346 * V_347 ,
int V_357 ,
int V_358 ,
int * V_359 ,
int * V_360 ,
int * V_361 ,
int * V_362 )
{
int V_363 ;
V_363 = V_358 - * V_362 ;
* V_359 = * V_362 ;
if ( V_363 <= V_357 ) {
* V_360 = V_363 ;
V_347 -> V_351 = F_127 ( * V_360 ) ;
if ( * V_361 )
V_347 -> V_352 |= ( V_364 | V_365 ) ;
* V_361 = 0 ;
* V_362 = 0 ;
return 0 ;
}
* V_360 = V_357 ;
V_347 -> V_351 = F_127 ( * V_360 ) ;
V_347 -> V_352 |= V_366 ;
if ( * V_361 )
V_347 -> V_352 |= V_365 ;
* V_362 += * V_360 ;
( * V_361 ) ++ ;
V_57 -> V_42 -= sizeof( struct V_346 ) ;
V_57 -> V_29 ++ ;
return sizeof( struct V_346 ) ;
}
static int
F_176 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_4 V_355 ,
int * V_272 ,
int * V_367 ,
int * V_368 ,
int * V_369 ,
int V_370 ,
struct V_58 * * V_371 )
{
if ( * V_368 ) {
F_166 ( log , V_59 , * V_272 , * V_367 ) ;
* V_272 = 0 ;
* V_367 = 0 ;
return F_46 ( log , V_59 ) ;
}
* V_368 = 0 ;
* V_369 = 0 ;
if ( V_59 -> V_221 - V_370 <= sizeof( V_276 ) ) {
F_166 ( log , V_59 , * V_272 , * V_367 ) ;
* V_272 = 0 ;
* V_367 = 0 ;
F_12 ( & log -> V_116 ) ;
F_77 ( log , V_59 ) ;
F_15 ( & log -> V_116 ) ;
if ( ! V_371 )
return F_46 ( log , V_59 ) ;
ASSERT ( V_355 & V_228 ) ;
* V_371 = V_59 ;
}
return 0 ;
}
int
F_74 (
struct V_1 * log ,
struct V_110 * V_339 ,
struct V_15 * V_57 ,
T_6 * V_372 ,
struct V_58 * * V_371 ,
T_4 V_355 )
{
struct V_58 * V_59 = NULL ;
struct V_104 * V_345 ;
struct V_110 * V_340 ;
int V_30 ;
int V_373 ;
int V_368 = 0 ;
int V_369 = 0 ;
int V_374 = 0 ;
int V_272 = 0 ;
int V_367 = 0 ;
int error ;
* V_372 = 0 ;
V_30 = F_172 ( V_57 , V_339 ) ;
if ( V_57 -> V_19 & V_62 )
V_57 -> V_42 -= sizeof( V_276 ) ;
if ( V_355 & ( V_228 | V_114 ) )
V_57 -> V_42 -= sizeof( V_276 ) ;
if ( V_57 -> V_42 < 0 )
F_168 ( log -> V_152 , V_57 ) ;
V_373 = 0 ;
V_340 = V_339 ;
V_345 = V_340 -> V_113 ;
while ( V_340 && ( ! V_340 -> V_112 || V_373 < V_340 -> V_112 ) ) {
void * V_375 ;
int V_370 ;
error = F_177 ( log , V_30 , & V_59 , V_57 ,
& V_374 , & V_370 ) ;
if ( error )
return error ;
ASSERT ( V_370 <= V_59 -> V_221 - 1 ) ;
V_375 = V_59 -> V_224 + V_370 ;
if ( ! * V_372 )
* V_372 = F_156 ( V_59 -> V_211 . V_240 ) ;
while ( V_340 && ( ! V_340 -> V_112 || V_373 < V_340 -> V_112 ) ) {
struct V_104 * V_105 ;
struct V_346 * V_347 ;
int V_376 ;
int V_360 ;
int V_359 ;
bool V_377 = false ;
if ( V_340 -> V_343 == V_344 ) {
ASSERT ( V_340 -> V_112 == 0 ) ;
V_377 = true ;
goto V_378;
}
V_105 = & V_345 [ V_373 ] ;
ASSERT ( V_105 -> V_107 % sizeof( V_379 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_375 % sizeof( V_379 ) == 0 ) ;
V_376 = F_173 ( V_375 , V_57 ) ;
if ( V_376 ) {
V_272 ++ ;
F_178 ( & V_375 , & V_30 , & V_370 ,
V_376 ) ;
}
V_347 = F_174 ( log , V_375 , V_57 , V_355 ) ;
if ( ! V_347 )
return - V_39 ;
F_178 ( & V_375 , & V_30 , & V_370 ,
sizeof( struct V_346 ) ) ;
V_30 += F_175 ( V_57 , V_347 ,
V_59 -> V_221 - V_370 ,
V_105 -> V_107 ,
& V_359 , & V_360 ,
& V_368 ,
& V_369 ) ;
F_179 ( log , V_375 ) ;
ASSERT ( V_360 >= 0 ) ;
if ( V_360 > 0 ) {
memcpy ( V_375 , V_105 -> V_106 + V_359 , V_360 ) ;
F_178 ( & V_375 , & V_30 , & V_370 ,
V_360 ) ;
}
V_360 += V_376 + sizeof( V_276 ) ;
V_272 ++ ;
V_367 += V_374 ? V_360 : 0 ;
error = F_176 ( log , V_59 , V_355 ,
& V_272 , & V_367 ,
& V_368 ,
& V_369 ,
V_370 ,
V_371 ) ;
if ( error )
return error ;
if ( V_368 )
break;
if ( ++ V_373 == V_340 -> V_112 ) {
V_378:
V_340 = V_340 -> V_342 ;
V_373 = 0 ;
if ( V_340 )
V_345 = V_340 -> V_113 ;
}
if ( V_272 == 0 && V_377 == false ) {
if ( ! V_340 )
return 0 ;
break;
}
}
}
ASSERT ( V_30 == 0 ) ;
F_166 ( log , V_59 , V_272 , V_367 ) ;
if ( ! V_371 )
return F_46 ( log , V_59 ) ;
ASSERT ( V_355 & V_228 ) ;
* V_371 = V_59 ;
return 0 ;
}
STATIC void
F_180 (
struct V_1 * log )
{
T_11 * V_59 ;
int V_380 = 0 ;
V_59 = log -> V_96 ;
do {
if ( V_59 -> V_66 == V_118 ) {
V_59 -> V_66 = V_68 ;
V_59 -> V_97 = 0 ;
ASSERT ( V_59 -> V_223 == NULL ) ;
if ( ! V_380 &&
( F_159 ( V_59 -> V_211 . V_274 ) ==
V_381 ) ) {
V_380 = 1 ;
} else {
V_380 = 2 ;
}
V_59 -> V_211 . V_274 = 0 ;
memset ( V_59 -> V_211 . V_241 , 0 ,
sizeof( V_59 -> V_211 . V_241 ) ) ;
V_59 -> V_211 . V_240 = 0 ;
} else if ( V_59 -> V_66 == V_68 )
;
else
break;
V_59 = V_59 -> V_98 ;
} while ( V_59 != log -> V_96 );
if ( V_380 ) {
switch ( log -> V_136 ) {
case V_139 :
case V_140 :
case V_141 :
log -> V_136 = V_140 ;
break;
case V_137 :
if ( V_380 == 1 )
log -> V_136 = V_141 ;
else
log -> V_136 = V_140 ;
break;
case V_138 :
if ( V_380 == 1 )
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
F_181 (
struct V_1 * log )
{
T_11 * V_382 ;
T_6 V_383 , V_61 ;
V_382 = log -> V_96 ;
V_383 = 0 ;
do {
if ( ! ( V_382 -> V_66 & ( V_68 | V_118 ) ) ) {
V_61 = F_156 ( V_382 -> V_211 . V_240 ) ;
if ( ( V_61 && ! V_383 ) ||
( F_137 ( V_61 , V_383 ) < 0 ) ) {
V_383 = V_61 ;
}
}
V_382 = V_382 -> V_98 ;
} while ( V_382 != log -> V_96 );
return V_383 ;
}
STATIC void
F_182 (
struct V_1 * log ,
int V_157 ,
struct V_58 * V_384 )
{
T_11 * V_59 ;
T_11 * V_94 ;
T_7 * V_63 , * V_70 ;
int V_385 = 0 ;
T_6 V_383 ;
int V_386 ;
int V_387 ;
int V_388 ;
int V_389 ;
int V_390 = 0 ;
F_12 ( & log -> V_116 ) ;
V_94 = V_59 = log -> V_96 ;
V_386 = 0 ;
V_388 = 0 ;
V_389 = 0 ;
do {
V_94 = log -> V_96 ;
V_59 = log -> V_96 ;
V_387 = 0 ;
V_389 ++ ;
do {
if ( V_59 -> V_66 &
( V_68 | V_118 ) ) {
V_59 = V_59 -> V_98 ;
continue;
}
if ( ! ( V_59 -> V_66 & V_67 ) ) {
if ( ! ( V_59 -> V_66 &
( V_391 |
V_392 ) ) ) {
if ( V_384 && ( V_384 -> V_66 ==
V_391 ) ) {
V_384 -> V_66 = V_392 ;
}
break;
}
V_383 = F_181 ( log ) ;
if ( V_383 &&
F_137 ( V_383 ,
F_156 ( V_59 -> V_211 . V_240 ) ) < 0 ) {
V_59 = V_59 -> V_98 ;
continue;
}
V_59 -> V_66 = V_393 ;
ASSERT ( F_137 ( F_2 ( & log -> V_146 ) ,
F_156 ( V_59 -> V_211 . V_240 ) ) <= 0 ) ;
if ( V_59 -> V_223 )
F_99 ( & log -> V_146 ,
F_156 ( V_59 -> V_211 . V_240 ) ) ;
} else
V_386 ++ ;
F_15 ( & log -> V_116 ) ;
F_12 ( & V_59 -> V_65 ) ;
V_63 = V_59 -> V_223 ;
while ( V_63 ) {
V_59 -> V_71 = & ( V_59 -> V_223 ) ;
V_59 -> V_223 = NULL ;
F_15 ( & V_59 -> V_65 ) ;
for (; V_63 ; V_63 = V_70 ) {
V_70 = V_63 -> V_70 ;
V_63 -> V_394 ( V_63 -> V_395 , V_157 ) ;
}
F_12 ( & V_59 -> V_65 ) ;
V_63 = V_59 -> V_223 ;
}
V_387 ++ ;
V_388 ++ ;
F_12 ( & log -> V_116 ) ;
ASSERT ( V_59 -> V_223 == NULL ) ;
F_15 ( & V_59 -> V_65 ) ;
if ( ! ( V_59 -> V_66 & V_67 ) )
V_59 -> V_66 = V_118 ;
F_180 ( log ) ;
F_183 ( & V_59 -> V_119 ) ;
V_59 = V_59 -> V_98 ;
} while ( V_94 != V_59 );
if ( V_389 > 5000 ) {
V_385 += V_389 ;
V_389 = 0 ;
F_55 ( log -> V_152 ,
L_56 ,
V_115 , V_385 ) ;
}
} while ( ! V_386 && V_387 );
#ifdef F_72
if ( V_388 ) {
V_94 = V_59 = log -> V_96 ;
do {
ASSERT ( V_59 -> V_66 != V_392 ) ;
if ( V_59 -> V_66 == V_69 ||
V_59 -> V_66 & V_396 ||
V_59 -> V_66 == V_391 ||
V_59 -> V_66 == V_67 )
break;
V_59 = V_59 -> V_98 ;
} while ( V_94 != V_59 );
}
#endif
if ( log -> V_96 -> V_66 & ( V_68 | V_67 ) )
V_390 = 1 ;
F_15 ( & log -> V_116 ) ;
if ( V_390 )
F_183 ( & log -> V_204 ) ;
}
STATIC void
F_108 (
T_11 * V_59 ,
int V_157 )
{
struct V_1 * log = V_59 -> V_156 ;
F_12 ( & log -> V_116 ) ;
ASSERT ( V_59 -> V_66 == V_396 ||
V_59 -> V_66 == V_67 ) ;
ASSERT ( F_151 ( & V_59 -> V_117 ) == 0 ) ;
ASSERT ( V_59 -> V_263 == 1 || V_59 -> V_263 == 2 ) ;
if ( V_59 -> V_66 != V_67 ) {
if ( -- V_59 -> V_263 == 1 ) {
F_15 ( & log -> V_116 ) ;
return;
}
V_59 -> V_66 = V_391 ;
}
F_183 ( & V_59 -> V_225 ) ;
F_15 ( & log -> V_116 ) ;
F_182 ( log , V_157 , V_59 ) ;
}
STATIC int
F_177 (
struct V_1 * log ,
int V_30 ,
struct V_58 * * V_186 ,
struct V_15 * V_57 ,
int * V_397 ,
int * V_398 )
{
int V_370 ;
T_15 * V_2 ;
T_11 * V_59 ;
int error ;
V_399:
F_12 ( & log -> V_116 ) ;
if ( F_26 ( log ) ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
V_59 = log -> V_96 ;
if ( V_59 -> V_66 != V_68 ) {
F_27 ( log -> V_152 , V_400 ) ;
F_78 ( & log -> V_204 , & log -> V_116 ) ;
goto V_399;
}
V_2 = & V_59 -> V_211 ;
F_76 ( & V_59 -> V_117 ) ;
V_370 = V_59 -> V_97 ;
if ( V_370 == 0 ) {
V_57 -> V_42 -= log -> V_174 ;
F_24 ( V_57 ,
log -> V_174 ,
V_401 ) ;
V_2 -> V_402 = F_127 ( log -> V_194 ) ;
V_2 -> V_240 = F_184 (
F_136 ( log -> V_194 , log -> V_403 ) ) ;
ASSERT ( log -> V_403 >= 0 ) ;
}
if ( V_59 -> V_221 - V_59 -> V_97 < 2 * sizeof( V_276 ) ) {
F_185 ( log , V_59 , V_59 -> V_221 ) ;
if ( ! F_186 ( & V_59 -> V_117 , - 1 , 1 ) ) {
F_15 ( & log -> V_116 ) ;
error = F_46 ( log , V_59 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_116 ) ;
}
goto V_399;
}
if ( V_30 <= V_59 -> V_221 - V_59 -> V_97 ) {
* V_397 = 0 ;
V_59 -> V_97 += V_30 ;
} else {
* V_397 = 1 ;
F_185 ( log , V_59 , V_59 -> V_221 ) ;
}
* V_186 = V_59 ;
ASSERT ( V_59 -> V_97 <= V_59 -> V_221 ) ;
F_15 ( & log -> V_116 ) ;
* V_398 = V_370 ;
return 0 ;
}
STATIC void
F_41 (
struct V_1 * log ,
struct V_15 * V_57 )
{
F_187 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
V_57 -> V_22 -- ;
F_1 ( log , & log -> V_56 . V_12 ,
V_57 -> V_42 ) ;
F_1 ( log , & log -> V_18 . V_12 ,
V_57 -> V_42 ) ;
V_57 -> V_42 = V_57 -> V_21 ;
F_23 ( V_57 ) ;
F_188 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
return;
F_6 ( log , & log -> V_56 . V_12 ,
V_57 -> V_21 ) ;
F_189 ( log , V_57 ) ;
V_57 -> V_42 = V_57 -> V_21 ;
F_23 ( V_57 ) ;
}
STATIC void
F_39 (
struct V_1 * log ,
struct V_15 * V_57 )
{
int V_3 ;
if ( V_57 -> V_22 > 0 )
V_57 -> V_22 -- ;
F_190 ( log , V_57 ) ;
F_191 ( log , V_57 ) ;
V_3 = V_57 -> V_42 ;
if ( V_57 -> V_22 > 0 ) {
ASSERT ( V_57 -> V_19 & V_20 ) ;
V_3 += V_57 -> V_21 * V_57 -> V_22 ;
}
F_1 ( log , & log -> V_56 . V_12 , V_3 ) ;
F_1 ( log , & log -> V_18 . V_12 , V_3 ) ;
F_192 ( log , V_57 ) ;
F_89 ( log -> V_152 ) ;
}
STATIC int
F_46 (
struct V_1 * log ,
struct V_58 * V_59 )
{
int V_404 = 0 ;
if ( V_59 -> V_66 & V_67 )
return - V_39 ;
ASSERT ( F_151 ( & V_59 -> V_117 ) > 0 ) ;
if ( ! F_193 ( & V_59 -> V_117 , & log -> V_116 ) )
return 0 ;
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
ASSERT ( V_59 -> V_66 == V_68 ||
V_59 -> V_66 == V_69 ) ;
if ( V_59 -> V_66 == V_69 ) {
T_6 V_143 = F_100 ( log -> V_152 ) ;
V_404 ++ ;
V_59 -> V_66 = V_396 ;
V_59 -> V_211 . V_405 = F_184 ( V_143 ) ;
F_194 ( log , V_59 , V_143 ) ;
}
F_15 ( & log -> V_116 ) ;
if ( V_404 )
return F_150 ( log , V_59 ) ;
return 0 ;
}
STATIC void
F_185 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_406 )
{
ASSERT ( V_59 -> V_66 == V_68 ) ;
if ( ! V_406 )
V_406 = V_59 -> V_97 ;
V_59 -> V_66 = V_69 ;
V_59 -> V_211 . V_407 = F_127 ( log -> V_193 ) ;
log -> V_193 = log -> V_403 ;
log -> V_408 = log -> V_194 ;
log -> V_403 += F_123 ( V_406 ) + F_123 ( log -> V_174 ) ;
if ( F_110 ( & log -> V_152 -> V_79 ) &&
log -> V_152 -> V_79 . V_259 > 1 ) {
T_13 V_409 = F_123 ( log -> V_152 -> V_79 . V_259 ) ;
log -> V_403 = F_195 ( log -> V_403 , V_409 ) ;
}
if ( log -> V_403 >= log -> V_192 ) {
log -> V_403 -= log -> V_192 ;
ASSERT ( log -> V_403 >= 0 ) ;
F_196 () ;
log -> V_194 ++ ;
if ( log -> V_194 == V_213 )
log -> V_194 ++ ;
}
ASSERT ( V_59 == log -> V_96 ) ;
log -> V_96 = V_59 -> V_98 ;
}
int
F_73 (
struct V_36 * V_37 ,
T_4 V_355 ,
int * V_410 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
T_6 V_61 ;
F_27 ( V_37 , V_411 ) ;
F_197 ( log ) ;
F_12 ( & log -> V_116 ) ;
V_59 = log -> V_96 ;
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
if ( V_59 -> V_66 == V_68 ||
V_59 -> V_66 == V_118 ) {
if ( V_59 -> V_66 == V_118 ||
( F_151 ( & V_59 -> V_117 ) == 0
&& V_59 -> V_97 == 0 ) ) {
V_59 = V_59 -> V_206 ;
if ( V_59 -> V_66 == V_68 ||
V_59 -> V_66 == V_118 )
goto V_412;
else
goto V_413;
} else {
if ( F_151 ( & V_59 -> V_117 ) == 0 ) {
F_76 ( & V_59 -> V_117 ) ;
V_61 = F_156 ( V_59 -> V_211 . V_240 ) ;
F_185 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_116 ) ;
if ( F_46 ( log , V_59 ) )
return - V_39 ;
if ( V_410 )
* V_410 = 1 ;
F_12 ( & log -> V_116 ) ;
if ( F_156 ( V_59 -> V_211 . V_240 ) == V_61 &&
V_59 -> V_66 != V_118 )
goto V_413;
else
goto V_412;
} else {
F_185 ( log , V_59 , 0 ) ;
goto V_413;
}
}
}
V_413:
if ( V_355 & V_95 ) {
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_414 ) ;
F_78 ( & V_59 -> V_119 , & log -> V_116 ) ;
if ( V_59 -> V_66 & V_67 )
return - V_39 ;
if ( V_410 )
* V_410 = 1 ;
} else {
V_412:
F_15 ( & log -> V_116 ) ;
}
return 0 ;
}
void
F_82 (
T_8 * V_37 ,
T_4 V_355 )
{
int error ;
F_198 ( V_37 , 0 ) ;
error = F_73 ( V_37 , V_355 , NULL ) ;
if ( error )
F_55 ( V_37 , L_57 , V_115 , error ) ;
}
int
F_199 (
struct V_36 * V_37 ,
T_6 V_61 ,
T_4 V_355 ,
int * V_410 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
int V_415 = 0 ;
ASSERT ( V_61 != 0 ) ;
F_27 ( V_37 , V_411 ) ;
V_61 = F_200 ( log , V_61 ) ;
if ( V_61 == V_416 )
return 0 ;
V_417:
F_12 ( & log -> V_116 ) ;
V_59 = log -> V_96 ;
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
do {
if ( F_156 ( V_59 -> V_211 . V_240 ) != V_61 ) {
V_59 = V_59 -> V_98 ;
continue;
}
if ( V_59 -> V_66 == V_118 ) {
F_15 ( & log -> V_116 ) ;
return 0 ;
}
if ( V_59 -> V_66 == V_68 ) {
if ( ! V_415 &&
( V_59 -> V_206 -> V_66 &
( V_69 | V_396 ) ) ) {
ASSERT ( ! ( V_59 -> V_66 & V_67 ) ) ;
F_27 ( V_37 , V_414 ) ;
F_78 ( & V_59 -> V_206 -> V_225 ,
& log -> V_116 ) ;
if ( V_410 )
* V_410 = 1 ;
V_415 = 1 ;
goto V_417;
}
F_76 ( & V_59 -> V_117 ) ;
F_185 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_116 ) ;
if ( F_46 ( log , V_59 ) )
return - V_39 ;
if ( V_410 )
* V_410 = 1 ;
F_12 ( & log -> V_116 ) ;
}
if ( ( V_355 & V_95 ) &&
! ( V_59 -> V_66 &
( V_68 | V_118 ) ) ) {
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_414 ) ;
F_78 ( & V_59 -> V_119 , & log -> V_116 ) ;
if ( V_59 -> V_66 & V_67 )
return - V_39 ;
if ( V_410 )
* V_410 = 1 ;
} else {
F_15 ( & log -> V_116 ) ;
}
return 0 ;
} while ( V_59 != log -> V_96 );
F_15 ( & log -> V_116 ) ;
return 0 ;
}
void
F_201 (
T_8 * V_37 ,
T_6 V_61 ,
T_4 V_355 )
{
int error ;
F_198 ( V_37 , V_61 ) ;
error = F_199 ( V_37 , V_61 , V_355 , NULL ) ;
if ( error )
F_55 ( V_37 , L_57 , V_115 , error ) ;
}
STATIC void
F_77 (
struct V_1 * log ,
struct V_58 * V_59 )
{
F_96 ( & log -> V_116 ) ;
if ( V_59 -> V_66 == V_68 ) {
F_185 ( log , V_59 , 0 ) ;
} else {
ASSERT ( V_59 -> V_66 &
( V_69 | V_67 ) ) ;
}
}
void
F_42 (
T_3 * V_57 )
{
ASSERT ( F_151 ( & V_57 -> V_418 ) > 0 ) ;
if ( F_202 ( & V_57 -> V_418 ) )
F_203 ( V_419 , V_57 ) ;
}
T_3 *
F_204 (
T_3 * V_57 )
{
ASSERT ( F_151 ( & V_57 -> V_418 ) > 0 ) ;
F_76 ( & V_57 -> V_418 ) ;
return V_57 ;
}
int
F_205 (
struct V_36 * V_37 ,
int V_44 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_420 ;
T_4 V_421 ;
V_44 += sizeof( V_276 ) ;
V_44 += sizeof( V_422 ) ;
V_44 += sizeof( V_276 ) ;
V_420 = log -> V_171 - log -> V_174 ;
V_421 = F_206 ( V_44 , V_420 ) ;
V_44 += sizeof( V_276 ) * V_421 ;
while ( ! V_421 ||
F_206 ( V_44 , V_420 ) > V_421 ) {
V_44 += sizeof( V_276 ) ;
V_421 ++ ;
}
V_44 += log -> V_174 * V_421 ;
V_44 += log -> V_174 ;
if ( F_110 ( & V_37 -> V_79 ) && V_37 -> V_79 . V_259 > 1 ) {
V_44 += 2 * V_37 -> V_79 . V_259 ;
} else {
V_44 += 2 * V_178 ;
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
T_20 V_423 )
{
struct V_15 * V_16 ;
int V_424 ;
V_16 = F_207 ( V_419 , V_423 ) ;
if ( ! V_16 )
return NULL ;
V_424 = F_205 ( log -> V_152 , V_44 ) ;
F_128 ( & V_16 -> V_418 , 1 ) ;
V_16 -> V_17 = V_425 ;
F_9 ( & V_16 -> V_426 ) ;
V_16 -> V_21 = V_424 ;
V_16 -> V_42 = V_424 ;
V_16 -> V_22 = V_45 ;
V_16 -> V_427 = V_45 ;
V_16 -> V_41 = F_160 () ;
V_16 -> V_350 = V_47 ;
V_16 -> V_19 = V_62 ;
V_16 -> V_55 = 0 ;
if ( V_48 )
V_16 -> V_19 |= V_20 ;
F_23 ( V_16 ) ;
return V_16 ;
}
void
F_179 (
struct V_1 * log ,
void * V_375 )
{
int V_188 ;
int V_428 = 0 ;
for ( V_188 = 0 ; V_188 < log -> V_168 ; V_188 ++ ) {
if ( V_375 >= log -> V_210 [ V_188 ] &&
V_375 <= log -> V_210 [ V_188 ] + log -> V_171 )
V_428 ++ ;
}
if ( ! V_428 )
F_208 ( log -> V_152 , L_58 , V_115 ) ;
}
STATIC void
F_31 (
struct V_1 * log )
{
int V_149 , V_429 ;
int V_7 , V_8 ;
F_101 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_102 ( & log -> V_147 , & V_149 , & V_429 ) ;
if ( V_149 != V_7 ) {
if ( V_7 - 1 != V_149 &&
! ( log -> V_25 & V_430 ) ) {
F_171 ( log -> V_152 , V_338 ,
L_59 , V_115 ) ;
log -> V_25 |= V_430 ;
}
if ( V_8 > F_103 ( V_429 ) &&
! ( log -> V_25 & V_430 ) ) {
F_171 ( log -> V_152 , V_338 ,
L_60 , V_115 ) ;
log -> V_25 |= V_430 ;
}
}
}
STATIC void
F_194 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_6 V_143 )
{
int V_431 ;
if ( F_209 ( V_143 ) == log -> V_408 ) {
V_431 =
log -> V_192 - ( log -> V_193 - F_155 ( V_143 ) ) ;
if ( V_431 < F_123 ( V_59 -> V_97 ) + F_123 ( log -> V_174 ) )
F_208 ( log -> V_152 , L_61 , V_115 ) ;
} else {
ASSERT ( F_209 ( V_143 ) + 1 == log -> V_408 ) ;
if ( F_155 ( V_143 ) == log -> V_193 )
F_208 ( log -> V_152 , L_62 , V_115 ) ;
V_431 = F_155 ( V_143 ) - log -> V_193 ;
if ( V_431 < F_123 ( V_59 -> V_97 ) + 1 )
F_208 ( log -> V_152 , L_61 , V_115 ) ;
}
}
STATIC void
F_162 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_254 ,
bool V_432 )
{
V_276 * V_433 ;
T_11 * V_434 ;
T_17 * V_242 ;
void * V_435 , * V_375 , * V_436 ;
T_21 V_437 ;
T_5 V_438 ;
int V_30 , V_188 , V_236 , V_237 , V_439 ;
int V_440 ;
F_12 ( & log -> V_116 ) ;
V_434 = log -> V_96 ;
for ( V_188 = 0 ; V_188 < log -> V_168 ; V_188 ++ , V_434 = V_434 -> V_98 )
ASSERT ( V_434 ) ;
if ( V_434 != log -> V_96 )
F_208 ( log -> V_152 , L_63 , V_115 ) ;
F_15 ( & log -> V_116 ) ;
if ( V_59 -> V_211 . V_212 != F_127 ( V_213 ) )
F_208 ( log -> V_152 , L_64 , V_115 ) ;
V_435 = V_375 = & V_59 -> V_211 ;
V_436 = & V_59 -> V_211 ;
for ( V_375 += V_178 ; V_375 < V_435 + V_254 ; V_375 += V_178 ) {
if ( * ( T_16 * ) V_375 == F_127 ( V_213 ) )
F_208 ( log -> V_152 , L_65 ,
V_115 ) ;
}
V_30 = F_159 ( V_59 -> V_211 . V_274 ) ;
V_435 = V_375 = V_59 -> V_224 ;
V_433 = V_375 ;
V_242 = V_59 -> V_208 ;
for ( V_188 = 0 ; V_188 < V_30 ; V_188 ++ ) {
V_433 = V_375 ;
V_436 = & V_433 -> V_349 ;
V_437 = V_436 - V_435 ;
if ( ! V_432 || ( V_437 & 0x1ff ) ) {
V_438 = V_433 -> V_349 ;
} else {
V_440 = F_134 ( ( char * ) & V_433 -> V_349 - V_59 -> V_224 ) ;
if ( V_440 >= ( V_173 / V_178 ) ) {
V_236 = V_440 / ( V_173 / V_178 ) ;
V_237 = V_440 % ( V_173 / V_178 ) ;
V_438 = F_210 (
V_242 [ V_236 ] . V_243 . V_244 [ V_237 ] ) ;
} else {
V_438 = F_210 (
V_59 -> V_211 . V_241 [ V_440 ] ) ;
}
}
if ( V_438 != V_50 && V_438 != V_51 )
F_55 ( log -> V_152 ,
L_66 ,
V_115 , V_438 , V_433 ,
( unsigned long ) V_437 ) ;
V_436 = & V_433 -> V_351 ;
V_437 = V_436 - V_435 ;
if ( ! V_432 || ( V_437 & 0x1ff ) ) {
V_439 = F_159 ( V_433 -> V_351 ) ;
} else {
V_440 = F_134 ( ( V_441 ) & V_433 -> V_351 -
( V_441 ) V_59 -> V_224 ) ;
if ( V_440 >= ( V_173 / V_178 ) ) {
V_236 = V_440 / ( V_173 / V_178 ) ;
V_237 = V_440 % ( V_173 / V_178 ) ;
V_439 = F_159 ( V_242 [ V_236 ] . V_243 . V_244 [ V_237 ] ) ;
} else {
V_439 = F_159 ( V_59 -> V_211 . V_241 [ V_440 ] ) ;
}
}
V_375 += sizeof( V_276 ) + V_439 ;
}
}
STATIC int
F_211 (
struct V_1 * log )
{
T_11 * V_59 , * V_442 ;
V_59 = log -> V_96 ;
if ( ! ( V_59 -> V_66 & V_67 ) ) {
V_442 = V_59 ;
do {
V_442 -> V_66 = V_67 ;
V_442 = V_442 -> V_98 ;
} while ( V_442 != V_59 );
return 0 ;
}
return 1 ;
}
int
F_212 (
struct V_36 * V_37 ,
int V_443 )
{
struct V_1 * log ;
int V_444 ;
log = V_37 -> V_38 ;
if ( ! log ||
log -> V_25 & V_26 ) {
V_37 -> V_77 |= V_445 ;
if ( V_37 -> V_122 )
V_37 -> V_122 -> V_163 |= V_446 ;
return 0 ;
}
if ( V_443 && log -> V_96 -> V_66 & V_67 ) {
ASSERT ( F_26 ( log ) ) ;
return 1 ;
}
if ( ! V_443 )
F_73 ( V_37 , V_95 , NULL ) ;
F_12 ( & log -> V_116 ) ;
V_37 -> V_77 |= V_445 ;
if ( V_37 -> V_122 )
V_37 -> V_122 -> V_163 |= V_446 ;
log -> V_25 |= V_447 ;
V_444 = F_211 ( log ) ;
F_15 ( & log -> V_116 ) ;
F_11 ( & log -> V_56 ) ;
F_11 ( & log -> V_18 ) ;
F_183 ( & log -> V_448 -> V_449 ) ;
F_182 ( log , V_162 , NULL ) ;
#ifdef F_213
{
T_11 * V_59 ;
F_12 ( & log -> V_116 ) ;
V_59 = log -> V_96 ;
do {
ASSERT ( V_59 -> V_223 == 0 ) ;
V_59 = V_59 -> V_98 ;
} while ( V_59 != log -> V_96 );
F_15 ( & log -> V_116 ) ;
}
#endif
return V_444 ;
}
STATIC int
F_94 (
struct V_1 * log )
{
T_11 * V_59 ;
V_59 = log -> V_96 ;
do {
if ( V_59 -> V_211 . V_274 )
return 0 ;
V_59 = V_59 -> V_98 ;
} while ( V_59 != log -> V_96 );
return 1 ;
}
bool
F_214 (
struct V_36 * V_37 ,
T_6 V_61 )
{
struct V_1 * log = V_37 -> V_38 ;
bool V_450 ;
if ( V_37 -> V_77 & V_78 )
return true ;
if ( V_61 == V_416 )
return true ;
V_450 = F_215 ( V_37 -> V_38 , V_61 ) ;
if ( ! V_450 ) {
F_12 ( & log -> V_116 ) ;
F_55 ( V_37 ,
L_67
L_68 ,
F_209 ( V_61 ) , F_155 ( V_61 ) ,
log -> V_194 , log -> V_403 ) ;
F_15 ( & log -> V_116 ) ;
}
return V_450 ;
}
