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
ASSERT ( F_108 ( V_153 ) ) ;
F_109 ( V_59 , V_157 ) ;
F_86 ( V_153 ) ;
}
STATIC void
F_110 (
struct V_36 * V_37 ,
struct V_1 * log )
{
int V_163 ;
int V_164 ;
if ( V_37 -> V_165 <= 0 )
log -> V_166 = V_167 ;
else
log -> V_166 = V_37 -> V_165 ;
if ( V_37 -> V_168 > 0 ) {
V_163 = log -> V_169 = V_37 -> V_168 ;
log -> V_170 = 0 ;
while ( V_163 != 1 ) {
log -> V_170 ++ ;
V_163 >>= 1 ;
}
if ( F_111 ( & V_37 -> V_79 ) ) {
V_164 = V_37 -> V_168 / V_171 ;
if ( V_37 -> V_168 % V_171 )
V_164 ++ ;
log -> V_172 = V_164 << V_173 ;
log -> V_174 = V_164 ;
} else {
ASSERT ( V_37 -> V_168 <= V_175 ) ;
log -> V_172 = V_176 ;
log -> V_174 = 1 ;
}
goto V_177;
}
log -> V_169 = V_175 ;
log -> V_170 = V_178 ;
log -> V_172 = V_176 ;
log -> V_174 = 1 ;
V_177:
if ( V_37 -> V_165 == 0 )
V_37 -> V_165 = log -> V_166 ;
if ( V_37 -> V_168 == 0 )
V_37 -> V_168 = log -> V_169 ;
}
void
F_68 (
struct V_36 * V_37 )
{
F_112 ( V_37 -> V_179 , & V_37 -> V_38 -> V_120 ,
F_113 ( V_180 * 10 ) ) ;
}
void
F_114 (
struct V_181 * V_182 )
{
struct V_1 * log = F_115 ( F_116 ( V_182 ) ,
struct V_1 , V_120 ) ;
struct V_36 * V_37 = log -> V_152 ;
if ( F_90 ( V_37 ) ) {
F_117 ( V_37 , true ) ;
} else
F_82 ( V_37 , 0 ) ;
F_118 ( V_37 -> V_88 ) ;
F_68 ( V_37 ) ;
}
STATIC struct V_1 *
F_51 (
struct V_36 * V_37 ,
struct V_183 * V_73 ,
T_10 V_74 ,
int V_75 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_184 ;
T_11 * V_59 , * V_185 = NULL ;
T_14 * V_153 ;
int V_186 ;
int error = - V_54 ;
T_4 V_187 = 0 ;
log = F_119 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! log ) {
F_55 ( V_37 , L_16 ) ;
goto V_81;
}
log -> V_152 = V_37 ;
log -> V_188 = V_73 ;
log -> V_9 = F_103 ( V_75 ) ;
log -> V_189 = V_74 ;
log -> V_190 = V_75 ;
log -> V_136 = V_139 ;
log -> V_25 |= V_26 ;
F_120 ( & log -> V_120 , F_114 ) ;
log -> V_191 = - 1 ;
F_121 ( & log -> V_147 , 1 , 0 ) ;
F_121 ( & log -> V_146 , 1 , 0 ) ;
log -> V_192 = 1 ;
F_7 ( & log -> V_56 ) ;
F_7 ( & log -> V_18 ) ;
error = - V_193 ;
if ( F_122 ( & V_37 -> V_79 ) ) {
V_187 = V_37 -> V_79 . V_194 ;
if ( V_187 < V_173 ) {
F_55 ( V_37 , L_17 ,
V_187 , V_173 ) ;
goto V_86;
}
V_187 -= V_173 ;
if ( V_187 > V_37 -> V_195 ) {
F_55 ( V_37 , L_18 ,
V_187 , V_37 -> V_195 ) ;
goto V_86;
}
if ( V_187 && log -> V_189 > 0 &&
! F_111 ( & V_37 -> V_79 ) ) {
F_55 ( V_37 ,
L_19 ,
V_187 ) ;
goto V_86;
}
}
log -> V_196 = 1 << V_187 ;
F_110 ( V_37 , log ) ;
error = - V_54 ;
V_153 = F_123 ( V_37 -> V_197 , V_198 ,
F_124 ( log -> V_169 ) , 0 ) ;
if ( ! V_153 )
goto V_86;
ASSERT ( F_125 ( V_153 ) ) ;
F_86 ( V_153 ) ;
V_153 -> V_199 = V_37 -> V_179 ;
V_153 -> V_200 = F_104 ;
log -> V_201 = V_153 ;
F_10 ( & log -> V_116 ) ;
F_126 ( & log -> V_202 ) ;
V_184 = & log -> V_96 ;
ASSERT ( log -> V_169 >= 4096 ) ;
for ( V_186 = 0 ; V_186 < log -> V_166 ; V_186 ++ ) {
* V_184 = F_119 ( sizeof( T_11 ) , V_53 ) ;
if ( ! * V_184 )
goto V_203;
V_59 = * V_184 ;
V_59 -> V_204 = V_185 ;
V_185 = V_59 ;
V_153 = F_127 ( V_37 -> V_197 ,
F_124 ( log -> V_169 ) , 0 ) ;
if ( ! V_153 )
goto V_203;
ASSERT ( F_125 ( V_153 ) ) ;
F_86 ( V_153 ) ;
V_153 -> V_199 = V_37 -> V_179 ;
V_153 -> V_200 = F_104 ;
V_59 -> V_205 = V_153 ;
V_59 -> V_206 = V_153 -> V_207 ;
#ifdef F_72
log -> V_208 [ V_186 ] = & V_59 -> V_209 ;
#endif
V_2 = & V_59 -> V_209 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_210 = F_128 ( V_211 ) ;
V_2 -> V_212 = F_128 (
F_111 ( & log -> V_152 -> V_79 ) ? 2 : 1 ) ;
V_2 -> V_213 = F_128 ( log -> V_169 ) ;
V_2 -> V_214 = F_128 ( V_215 ) ;
memcpy ( & V_2 -> V_216 , & V_37 -> V_79 . V_217 , sizeof( V_218 ) ) ;
V_59 -> V_219 = F_103 ( V_153 -> V_220 ) - log -> V_172 ;
V_59 -> V_66 = V_68 ;
V_59 -> V_156 = log ;
F_129 ( & V_59 -> V_117 , 0 ) ;
F_10 ( & V_59 -> V_65 ) ;
V_59 -> V_71 = & ( V_59 -> V_221 ) ;
V_59 -> V_222 = ( char * ) V_59 -> V_206 + log -> V_172 ;
F_126 ( & V_59 -> V_119 ) ;
F_126 ( & V_59 -> V_223 ) ;
V_184 = & V_59 -> V_98 ;
}
* V_184 = log -> V_96 ;
log -> V_96 -> V_204 = V_185 ;
error = F_130 ( log ) ;
if ( error )
goto V_203;
return log ;
V_203:
for ( V_59 = log -> V_96 ; V_59 ; V_59 = V_185 ) {
V_185 = V_59 -> V_98 ;
if ( V_59 -> V_205 )
F_131 ( V_59 -> V_205 ) ;
F_132 ( V_59 ) ;
}
F_133 ( & log -> V_116 ) ;
F_131 ( log -> V_201 ) ;
V_86:
F_132 ( log ) ;
V_81:
return F_134 ( error ) ;
}
STATIC int
F_37 (
struct V_1 * log ,
struct V_15 * V_57 ,
struct V_58 * * V_59 ,
T_6 * V_224 )
{
struct V_36 * V_37 = log -> V_152 ;
int error ;
struct V_104 V_105 = {
. V_106 = NULL ,
. V_107 = 0 ,
. V_108 = V_225 ,
} ;
struct V_110 V_111 = {
. V_112 = 1 ,
. V_113 = & V_105 ,
} ;
F_44 ( V_59 ) ;
error = F_74 ( log , & V_111 , V_57 , V_224 , V_59 ,
V_226 ) ;
if ( error )
F_47 ( V_37 , V_72 ) ;
return error ;
}
STATIC void
F_28 (
struct V_1 * log ,
int V_24 )
{
T_6 V_227 = 0 ;
T_6 V_228 ;
int V_229 ;
int V_23 ;
int V_230 ;
int V_231 ;
int V_232 ;
ASSERT ( F_124 ( V_24 ) < log -> V_190 ) ;
V_23 = F_21 ( log , & log -> V_56 . V_12 ) ;
V_229 = F_135 ( V_23 ) ;
V_232 = F_124 ( V_24 ) ;
V_232 = F_136 ( V_232 , ( log -> V_190 >> 2 ) ) ;
V_232 = F_136 ( V_232 , 256 ) ;
if ( V_229 >= V_232 )
return;
F_102 ( & log -> V_147 , & V_231 ,
& V_230 ) ;
V_230 += V_232 ;
if ( V_230 >= log -> V_190 ) {
V_230 -= log -> V_190 ;
V_231 += 1 ;
}
V_227 = F_137 ( V_231 ,
V_230 ) ;
V_228 = F_2 ( & log -> V_146 ) ;
if ( F_138 ( V_227 , V_228 ) > 0 )
V_227 = V_228 ;
if ( ! F_26 ( log ) )
F_139 ( log -> V_87 , V_227 ) ;
}
STATIC void
F_140 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_233 )
{
int V_186 , V_234 , V_235 ;
int V_163 = V_59 -> V_97 + V_233 ;
T_16 V_236 ;
char * V_237 ;
V_236 = F_141 ( V_59 -> V_209 . V_238 ) ;
V_237 = V_59 -> V_222 ;
for ( V_186 = 0 ; V_186 < F_124 ( V_163 ) ; V_186 ++ ) {
if ( V_186 >= ( V_171 / V_176 ) )
break;
V_59 -> V_209 . V_239 [ V_186 ] = * ( T_16 * ) V_237 ;
* ( T_16 * ) V_237 = V_236 ;
V_237 += V_176 ;
}
if ( F_111 ( & log -> V_152 -> V_79 ) ) {
T_17 * V_240 = V_59 -> V_206 ;
for ( ; V_186 < F_124 ( V_163 ) ; V_186 ++ ) {
V_234 = V_186 / ( V_171 / V_176 ) ;
V_235 = V_186 % ( V_171 / V_176 ) ;
V_240 [ V_234 ] . V_241 . V_242 [ V_235 ] = * ( T_16 * ) V_237 ;
* ( T_16 * ) V_237 = V_236 ;
V_237 += V_176 ;
}
for ( V_186 = 1 ; V_186 < log -> V_174 ; V_186 ++ )
V_240 [ V_186 ] . V_241 . V_243 = V_236 ;
}
}
T_18
F_142 (
struct V_1 * log ,
struct V_244 * V_245 ,
char * V_237 ,
int V_163 )
{
T_13 V_246 ;
V_246 = F_143 ( ( char * ) V_245 ,
sizeof( struct V_244 ) ,
F_144 ( struct V_244 , V_247 ) ) ;
if ( F_111 ( & log -> V_152 -> V_79 ) ) {
union V_248 * V_240 = (union V_248 * ) V_245 ;
int V_186 ;
int V_249 ;
V_249 = V_163 / V_171 ;
if ( V_163 % V_171 )
V_249 ++ ;
for ( V_186 = 1 ; V_186 < V_249 ; V_186 ++ ) {
V_246 = F_145 ( V_246 , & V_240 [ V_186 ] . V_241 ,
sizeof( struct V_250 ) ) ;
}
}
V_246 = F_145 ( V_246 , V_237 , V_163 ) ;
return F_146 ( V_246 ) ;
}
STATIC int
F_147 (
struct V_251 * V_153 )
{
struct V_58 * V_59 = V_153 -> V_154 ;
F_85 ( V_153 ) ;
if ( V_59 -> V_66 & V_67 ) {
F_148 ( V_153 , - V_39 ) ;
F_107 ( V_153 ) ;
F_149 ( V_153 ) ;
return 0 ;
}
F_150 ( V_153 ) ;
return 0 ;
}
STATIC int
F_151 (
struct V_1 * log ,
struct V_58 * V_59 )
{
T_14 * V_153 ;
int V_186 ;
T_4 V_252 ;
T_4 V_253 ;
int V_233 ;
int V_254 = 0 ;
int error ;
int V_255 = F_111 ( & log -> V_152 -> V_79 ) ;
int V_163 ;
F_27 ( log -> V_152 , V_256 ) ;
ASSERT ( F_152 ( & V_59 -> V_117 ) == 0 ) ;
V_253 = log -> V_172 + V_59 -> V_97 ;
if ( V_255 && log -> V_152 -> V_79 . V_257 > 1 ) {
V_252 = F_153 ( log , F_154 ( log , V_253 ) ) ;
} else {
V_252 = F_103 ( F_124 ( V_253 ) ) ;
}
V_233 = V_252 - V_253 ;
ASSERT ( V_233 >= 0 ) ;
ASSERT ( ( V_255 && log -> V_152 -> V_79 . V_257 > 1 &&
V_233 < log -> V_152 -> V_79 . V_257 )
||
( log -> V_152 -> V_79 . V_257 <= 1 &&
V_233 < F_103 ( 1 ) ) ) ;
F_6 ( log , & log -> V_56 . V_12 , V_233 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_233 ) ;
F_140 ( log , V_59 , V_233 ) ;
V_163 = V_59 -> V_97 ;
if ( V_255 )
V_163 += V_233 ;
V_59 -> V_209 . V_258 = F_128 ( V_163 ) ;
V_153 = V_59 -> V_205 ;
F_155 ( V_153 , F_156 ( F_157 ( V_59 -> V_209 . V_238 ) ) ) ;
F_158 ( log -> V_152 , V_259 , F_124 ( V_252 ) ) ;
if ( F_159 ( V_153 ) + F_124 ( V_252 ) > log -> V_190 ) {
char * V_260 ;
V_254 = V_252 - ( F_103 ( log -> V_190 - F_159 ( V_153 ) ) ) ;
V_252 = F_103 ( log -> V_190 - F_159 ( V_153 ) ) ;
V_59 -> V_261 = 2 ;
V_260 = ( char * ) & V_59 -> V_209 + V_252 ;
for ( V_186 = 0 ; V_186 < V_254 ; V_186 += V_176 ) {
T_13 V_7 = F_160 ( * ( T_16 * ) V_260 ) ;
if ( ++ V_7 == V_211 )
V_7 ++ ;
* ( T_16 * ) V_260 = F_128 ( V_7 ) ;
V_260 += V_176 ;
}
} else {
V_59 -> V_261 = 1 ;
}
V_59 -> V_209 . V_247 = F_142 ( log , & V_59 -> V_209 ,
V_59 -> V_222 , V_163 ) ;
#ifdef F_72
if ( log -> V_262 &&
( F_161 () % log -> V_262 == 0 ) ) {
V_59 -> V_209 . V_247 &= 0xAAAAAAAA ;
V_59 -> V_66 |= V_161 ;
F_55 ( log -> V_152 ,
L_20 ,
F_157 ( V_59 -> V_209 . V_238 ) ) ;
}
#endif
V_153 -> V_263 = F_124 ( V_252 ) ;
V_153 -> V_154 = V_59 ;
F_162 ( V_153 ) ;
F_163 ( V_153 ) ;
V_153 -> V_264 |= V_265 ;
if ( log -> V_152 -> V_77 & V_266 ) {
V_153 -> V_264 |= V_267 ;
if ( log -> V_152 -> V_197 != log -> V_152 -> V_121 )
F_164 ( log -> V_152 -> V_121 ) ;
else
V_153 -> V_264 |= V_268 ;
}
ASSERT ( F_159 ( V_153 ) <= log -> V_190 - 1 ) ;
ASSERT ( F_159 ( V_153 ) + F_124 ( V_252 ) <= log -> V_190 ) ;
F_165 ( log , V_59 , V_252 , true ) ;
F_155 ( V_153 , F_159 ( V_153 ) + log -> V_189 ) ;
F_166 ( V_153 ) ;
error = F_147 ( V_153 ) ;
if ( error ) {
F_106 ( V_153 , L_21 ) ;
return error ;
}
if ( V_254 ) {
V_153 = V_59 -> V_156 -> V_201 ;
F_155 ( V_153 , 0 ) ;
F_167 ( V_153 ,
( char * ) & V_59 -> V_209 + V_252 , V_254 ) ;
V_153 -> V_154 = V_59 ;
F_162 ( V_153 ) ;
F_163 ( V_153 ) ;
V_153 -> V_264 |= V_265 ;
if ( log -> V_152 -> V_77 & V_266 )
V_153 -> V_264 |= V_267 ;
ASSERT ( F_159 ( V_153 ) <= log -> V_190 - 1 ) ;
ASSERT ( F_159 ( V_153 ) + F_124 ( V_252 ) <= log -> V_190 ) ;
F_155 ( V_153 , F_159 ( V_153 ) + log -> V_189 ) ;
F_166 ( V_153 ) ;
error = F_147 ( V_153 ) ;
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
T_11 * V_59 , * V_269 ;
int V_186 ;
F_168 ( log ) ;
V_59 = log -> V_96 ;
for ( V_186 = 0 ; V_186 < log -> V_166 ; V_186 ++ ) {
F_85 ( V_59 -> V_205 ) ;
F_86 ( V_59 -> V_205 ) ;
V_59 = V_59 -> V_98 ;
}
F_85 ( log -> V_201 ) ;
F_86 ( log -> V_201 ) ;
F_169 ( log -> V_201 , F_124 ( log -> V_169 ) ) ;
F_131 ( log -> V_201 ) ;
V_59 = log -> V_96 ;
for ( V_186 = 0 ; V_186 < log -> V_166 ; V_186 ++ ) {
F_131 ( V_59 -> V_205 ) ;
V_269 = V_59 -> V_98 ;
F_132 ( V_59 ) ;
V_59 = V_269 ;
}
F_133 ( & log -> V_116 ) ;
log -> V_152 -> V_38 = NULL ;
F_132 ( log ) ;
}
static inline void
F_170 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_270 ,
int V_271 )
{
F_12 ( & log -> V_116 ) ;
F_171 ( & V_59 -> V_209 . V_272 , V_270 ) ;
V_59 -> V_97 += V_271 ;
F_15 ( & log -> V_116 ) ;
}
void
F_172 (
struct V_36 * V_37 ,
struct V_15 * V_57 )
{
T_4 V_186 ;
T_4 V_273 = V_57 -> V_29 * ( T_4 ) sizeof( V_274 ) ;
static char * V_275 [ V_276 ] = {
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
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41
} ;
static char * V_277 [ V_278 ] = {
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
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80 ,
L_81 ,
L_82 ,
L_83
} ;
F_55 ( V_37 , L_84 ) ;
F_55 ( V_37 , L_85 ,
( ( V_57 -> V_55 <= 0 ||
V_57 -> V_55 > V_278 ) ?
L_86 : V_277 [ V_57 -> V_55 - 1 ] ) ,
V_57 -> V_55 ) ;
F_55 ( V_37 , L_87 ,
V_57 -> V_21 ) ;
F_55 ( V_37 , L_88 ,
V_57 -> V_42 ) ;
F_55 ( V_37 , L_89 ,
V_57 -> V_28 , V_57 -> V_32 ) ;
F_55 ( V_37 , L_90 ,
V_57 -> V_29 , V_273 ) ;
F_55 ( V_37 , L_91 ,
V_57 -> V_28 + V_57 -> V_32 + V_273 ) ;
F_55 ( V_37 , L_92 ,
V_57 -> V_27 ) ;
for ( V_186 = 0 ; V_186 < V_57 -> V_27 ; V_186 ++ ) {
T_4 V_35 = V_57 -> V_33 [ V_186 ] . V_35 ;
F_55 ( V_37 , L_93 , V_186 ,
( ( V_35 <= 0 || V_35 > V_276 ) ?
L_94 : V_275 [ V_35 - 1 ] ) ,
V_57 -> V_33 [ V_186 ] . V_34 ) ;
}
F_173 ( V_37 , V_279 ,
L_95 ) ;
F_47 ( V_37 , V_72 ) ;
}
static int
F_174 (
struct V_15 * V_57 ,
struct V_110 * V_280 )
{
struct V_110 * V_281 ;
int V_282 = 0 ;
int V_30 = 0 ;
int V_186 ;
if ( V_57 -> V_19 & V_62 )
V_282 ++ ;
for ( V_281 = V_280 ; V_281 ; V_281 = V_281 -> V_283 ) {
if ( V_281 -> V_284 == V_285 )
continue;
V_282 += V_281 -> V_112 ;
for ( V_186 = 0 ; V_186 < V_281 -> V_112 ; V_186 ++ ) {
struct V_104 * V_286 = & V_281 -> V_113 [ V_186 ] ;
V_30 += V_286 -> V_107 ;
F_24 ( V_57 , V_286 -> V_107 , V_286 -> V_108 ) ;
}
}
V_57 -> V_29 += V_282 ;
V_30 += V_282 * sizeof( struct V_287 ) ;
return V_30 ;
}
static int
F_175 (
struct V_287 * V_288 ,
struct V_15 * V_57 )
{
if ( ! ( V_57 -> V_19 & V_62 ) )
return 0 ;
V_288 -> V_289 = F_128 ( V_57 -> V_41 ) ;
V_288 -> V_290 = V_57 -> V_291 ;
V_288 -> V_292 = 0 ;
V_288 -> V_293 = V_294 ;
V_288 -> V_295 = 0 ;
V_57 -> V_19 &= ~ V_62 ;
return sizeof( struct V_287 ) ;
}
static V_274 *
F_176 (
struct V_1 * log ,
struct V_287 * V_288 ,
struct V_15 * V_57 ,
T_4 V_296 )
{
V_288 -> V_289 = F_128 ( V_57 -> V_41 ) ;
V_288 -> V_290 = V_57 -> V_291 ;
V_288 -> V_295 = 0 ;
V_288 -> V_293 = V_296 ;
switch ( V_288 -> V_290 ) {
case V_50 :
case V_297 :
case V_51 :
break;
default:
F_55 ( log -> V_152 ,
L_96 ,
V_288 -> V_290 , V_57 ) ;
return NULL ;
}
return V_288 ;
}
static int
F_177 (
struct V_15 * V_57 ,
struct V_287 * V_288 ,
int V_298 ,
int V_299 ,
int * V_300 ,
int * V_301 ,
int * V_302 ,
int * V_303 )
{
int V_304 ;
V_304 = V_299 - * V_303 ;
* V_300 = * V_303 ;
if ( V_304 <= V_298 ) {
* V_301 = V_304 ;
V_288 -> V_292 = F_128 ( * V_301 ) ;
if ( * V_302 )
V_288 -> V_293 |= ( V_305 | V_306 ) ;
* V_302 = 0 ;
* V_303 = 0 ;
return 0 ;
}
* V_301 = V_298 ;
V_288 -> V_292 = F_128 ( * V_301 ) ;
V_288 -> V_293 |= V_307 ;
if ( * V_302 )
V_288 -> V_293 |= V_306 ;
* V_303 += * V_301 ;
( * V_302 ) ++ ;
V_57 -> V_42 -= sizeof( struct V_287 ) ;
V_57 -> V_29 ++ ;
return sizeof( struct V_287 ) ;
}
static int
F_178 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_4 V_296 ,
int * V_270 ,
int * V_308 ,
int * V_309 ,
int * V_310 ,
int V_311 ,
struct V_58 * * V_312 )
{
if ( * V_309 ) {
F_170 ( log , V_59 , * V_270 , * V_308 ) ;
* V_270 = 0 ;
* V_308 = 0 ;
return F_46 ( log , V_59 ) ;
}
* V_309 = 0 ;
* V_310 = 0 ;
if ( V_59 -> V_219 - V_311 <= sizeof( V_274 ) ) {
F_170 ( log , V_59 , * V_270 , * V_308 ) ;
* V_270 = 0 ;
* V_308 = 0 ;
F_12 ( & log -> V_116 ) ;
F_77 ( log , V_59 ) ;
F_15 ( & log -> V_116 ) ;
if ( ! V_312 )
return F_46 ( log , V_59 ) ;
ASSERT ( V_296 & V_226 ) ;
* V_312 = V_59 ;
}
return 0 ;
}
int
F_74 (
struct V_1 * log ,
struct V_110 * V_280 ,
struct V_15 * V_57 ,
T_6 * V_313 ,
struct V_58 * * V_312 ,
T_4 V_296 )
{
struct V_58 * V_59 = NULL ;
struct V_104 * V_286 ;
struct V_110 * V_281 ;
int V_30 ;
int V_314 ;
int V_309 = 0 ;
int V_310 = 0 ;
int V_315 = 0 ;
int V_270 = 0 ;
int V_308 = 0 ;
int error ;
* V_313 = 0 ;
V_30 = F_174 ( V_57 , V_280 ) ;
if ( V_57 -> V_19 & V_62 )
V_57 -> V_42 -= sizeof( V_274 ) ;
if ( V_296 & ( V_226 | V_114 ) )
V_57 -> V_42 -= sizeof( V_274 ) ;
if ( V_57 -> V_42 < 0 )
F_172 ( log -> V_152 , V_57 ) ;
V_314 = 0 ;
V_281 = V_280 ;
V_286 = V_281 -> V_113 ;
while ( V_281 && ( ! V_281 -> V_112 || V_314 < V_281 -> V_112 ) ) {
void * V_316 ;
int V_311 ;
error = F_179 ( log , V_30 , & V_59 , V_57 ,
& V_315 , & V_311 ) ;
if ( error )
return error ;
ASSERT ( V_311 <= V_59 -> V_219 - 1 ) ;
V_316 = V_59 -> V_222 + V_311 ;
if ( ! * V_313 )
* V_313 = F_157 ( V_59 -> V_209 . V_238 ) ;
while ( V_281 && ( ! V_281 -> V_112 || V_314 < V_281 -> V_112 ) ) {
struct V_104 * V_105 ;
struct V_287 * V_288 ;
int V_317 ;
int V_301 ;
int V_300 ;
bool V_318 = false ;
if ( V_281 -> V_284 == V_285 ) {
ASSERT ( V_281 -> V_112 == 0 ) ;
V_318 = true ;
goto V_319;
}
V_105 = & V_286 [ V_314 ] ;
ASSERT ( V_105 -> V_107 % sizeof( V_320 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_316 % sizeof( V_320 ) == 0 ) ;
V_317 = F_175 ( V_316 , V_57 ) ;
if ( V_317 ) {
V_270 ++ ;
F_180 ( & V_316 , & V_30 , & V_311 ,
V_317 ) ;
}
V_288 = F_176 ( log , V_316 , V_57 , V_296 ) ;
if ( ! V_288 )
return - V_39 ;
F_180 ( & V_316 , & V_30 , & V_311 ,
sizeof( struct V_287 ) ) ;
V_30 += F_177 ( V_57 , V_288 ,
V_59 -> V_219 - V_311 ,
V_105 -> V_107 ,
& V_300 , & V_301 ,
& V_309 ,
& V_310 ) ;
F_181 ( log , V_316 ) ;
ASSERT ( V_301 >= 0 ) ;
if ( V_301 > 0 ) {
memcpy ( V_316 , V_105 -> V_106 + V_300 , V_301 ) ;
F_180 ( & V_316 , & V_30 , & V_311 ,
V_301 ) ;
}
V_301 += V_317 + sizeof( V_274 ) ;
V_270 ++ ;
V_308 += V_315 ? V_301 : 0 ;
error = F_178 ( log , V_59 , V_296 ,
& V_270 , & V_308 ,
& V_309 ,
& V_310 ,
V_311 ,
V_312 ) ;
if ( error )
return error ;
if ( V_309 )
break;
if ( ++ V_314 == V_281 -> V_112 ) {
V_319:
V_281 = V_281 -> V_283 ;
V_314 = 0 ;
if ( V_281 )
V_286 = V_281 -> V_113 ;
}
if ( V_270 == 0 && V_318 == false ) {
if ( ! V_281 )
return 0 ;
break;
}
}
}
ASSERT ( V_30 == 0 ) ;
F_170 ( log , V_59 , V_270 , V_308 ) ;
if ( ! V_312 )
return F_46 ( log , V_59 ) ;
ASSERT ( V_296 & V_226 ) ;
* V_312 = V_59 ;
return 0 ;
}
STATIC void
F_182 (
struct V_1 * log )
{
T_11 * V_59 ;
int V_321 = 0 ;
V_59 = log -> V_96 ;
do {
if ( V_59 -> V_66 == V_118 ) {
V_59 -> V_66 = V_68 ;
V_59 -> V_97 = 0 ;
ASSERT ( V_59 -> V_221 == NULL ) ;
if ( ! V_321 &&
( F_160 ( V_59 -> V_209 . V_272 ) ==
V_322 ) ) {
V_321 = 1 ;
} else {
V_321 = 2 ;
}
V_59 -> V_209 . V_272 = 0 ;
memset ( V_59 -> V_209 . V_239 , 0 ,
sizeof( V_59 -> V_209 . V_239 ) ) ;
V_59 -> V_209 . V_238 = 0 ;
} else if ( V_59 -> V_66 == V_68 )
;
else
break;
V_59 = V_59 -> V_98 ;
} while ( V_59 != log -> V_96 );
if ( V_321 ) {
switch ( log -> V_136 ) {
case V_139 :
case V_140 :
case V_141 :
log -> V_136 = V_140 ;
break;
case V_137 :
if ( V_321 == 1 )
log -> V_136 = V_141 ;
else
log -> V_136 = V_140 ;
break;
case V_138 :
if ( V_321 == 1 )
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
T_11 * V_323 ;
T_6 V_324 , V_61 ;
V_323 = log -> V_96 ;
V_324 = 0 ;
do {
if ( ! ( V_323 -> V_66 & ( V_68 | V_118 ) ) ) {
V_61 = F_157 ( V_323 -> V_209 . V_238 ) ;
if ( ( V_61 && ! V_324 ) ||
( F_138 ( V_61 , V_324 ) < 0 ) ) {
V_324 = V_61 ;
}
}
V_323 = V_323 -> V_98 ;
} while ( V_323 != log -> V_96 );
return V_324 ;
}
STATIC void
F_184 (
struct V_1 * log ,
int V_157 ,
struct V_58 * V_325 )
{
T_11 * V_59 ;
T_11 * V_94 ;
T_7 * V_63 , * V_70 ;
int V_326 = 0 ;
T_6 V_324 ;
int V_327 ;
int V_328 ;
int V_329 ;
int V_330 ;
int V_331 = 0 ;
F_12 ( & log -> V_116 ) ;
V_94 = V_59 = log -> V_96 ;
V_327 = 0 ;
V_329 = 0 ;
V_330 = 0 ;
do {
V_94 = log -> V_96 ;
V_59 = log -> V_96 ;
V_328 = 0 ;
V_330 ++ ;
do {
if ( V_59 -> V_66 &
( V_68 | V_118 ) ) {
V_59 = V_59 -> V_98 ;
continue;
}
if ( ! ( V_59 -> V_66 & V_67 ) ) {
if ( ! ( V_59 -> V_66 &
( V_332 |
V_333 ) ) ) {
if ( V_325 && ( V_325 -> V_66 ==
V_332 ) ) {
V_325 -> V_66 = V_333 ;
}
break;
}
V_324 = F_183 ( log ) ;
if ( V_324 &&
F_138 ( V_324 ,
F_157 ( V_59 -> V_209 . V_238 ) ) < 0 ) {
V_59 = V_59 -> V_98 ;
continue;
}
V_59 -> V_66 = V_334 ;
ASSERT ( F_138 ( F_2 ( & log -> V_146 ) ,
F_157 ( V_59 -> V_209 . V_238 ) ) <= 0 ) ;
if ( V_59 -> V_221 )
F_99 ( & log -> V_146 ,
F_157 ( V_59 -> V_209 . V_238 ) ) ;
} else
V_327 ++ ;
F_15 ( & log -> V_116 ) ;
F_12 ( & V_59 -> V_65 ) ;
V_63 = V_59 -> V_221 ;
while ( V_63 ) {
V_59 -> V_71 = & ( V_59 -> V_221 ) ;
V_59 -> V_221 = NULL ;
F_15 ( & V_59 -> V_65 ) ;
for (; V_63 ; V_63 = V_70 ) {
V_70 = V_63 -> V_70 ;
V_63 -> V_335 ( V_63 -> V_336 , V_157 ) ;
}
F_12 ( & V_59 -> V_65 ) ;
V_63 = V_59 -> V_221 ;
}
V_328 ++ ;
V_329 ++ ;
F_12 ( & log -> V_116 ) ;
ASSERT ( V_59 -> V_221 == NULL ) ;
F_15 ( & V_59 -> V_65 ) ;
if ( ! ( V_59 -> V_66 & V_67 ) )
V_59 -> V_66 = V_118 ;
F_182 ( log ) ;
F_185 ( & V_59 -> V_119 ) ;
V_59 = V_59 -> V_98 ;
} while ( V_94 != V_59 );
if ( V_330 > 5000 ) {
V_326 += V_330 ;
V_330 = 0 ;
F_55 ( log -> V_152 ,
L_97 ,
V_115 , V_326 ) ;
}
} while ( ! V_327 && V_328 );
#ifdef F_72
if ( V_329 ) {
V_94 = V_59 = log -> V_96 ;
do {
ASSERT ( V_59 -> V_66 != V_333 ) ;
if ( V_59 -> V_66 == V_69 ||
V_59 -> V_66 & V_337 ||
V_59 -> V_66 == V_332 ||
V_59 -> V_66 == V_67 )
break;
V_59 = V_59 -> V_98 ;
} while ( V_94 != V_59 );
}
#endif
if ( log -> V_96 -> V_66 & ( V_68 | V_67 ) )
V_331 = 1 ;
F_15 ( & log -> V_116 ) ;
if ( V_331 )
F_185 ( & log -> V_202 ) ;
}
STATIC void
F_109 (
T_11 * V_59 ,
int V_157 )
{
struct V_1 * log = V_59 -> V_156 ;
F_12 ( & log -> V_116 ) ;
ASSERT ( V_59 -> V_66 == V_337 ||
V_59 -> V_66 == V_67 ) ;
ASSERT ( F_152 ( & V_59 -> V_117 ) == 0 ) ;
ASSERT ( V_59 -> V_261 == 1 || V_59 -> V_261 == 2 ) ;
if ( V_59 -> V_66 != V_67 ) {
if ( -- V_59 -> V_261 == 1 ) {
F_15 ( & log -> V_116 ) ;
return;
}
V_59 -> V_66 = V_332 ;
}
F_185 ( & V_59 -> V_223 ) ;
F_15 ( & log -> V_116 ) ;
F_184 ( log , V_157 , V_59 ) ;
}
STATIC int
F_179 (
struct V_1 * log ,
int V_30 ,
struct V_58 * * V_184 ,
struct V_15 * V_57 ,
int * V_338 ,
int * V_339 )
{
int V_311 ;
T_15 * V_2 ;
T_11 * V_59 ;
int error ;
V_340:
F_12 ( & log -> V_116 ) ;
if ( F_26 ( log ) ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
V_59 = log -> V_96 ;
if ( V_59 -> V_66 != V_68 ) {
F_27 ( log -> V_152 , V_341 ) ;
F_78 ( & log -> V_202 , & log -> V_116 ) ;
goto V_340;
}
V_2 = & V_59 -> V_209 ;
F_76 ( & V_59 -> V_117 ) ;
V_311 = V_59 -> V_97 ;
if ( V_311 == 0 ) {
V_57 -> V_42 -= log -> V_172 ;
F_24 ( V_57 ,
log -> V_172 ,
V_342 ) ;
V_2 -> V_343 = F_128 ( log -> V_192 ) ;
V_2 -> V_238 = F_186 (
F_137 ( log -> V_192 , log -> V_344 ) ) ;
ASSERT ( log -> V_344 >= 0 ) ;
}
if ( V_59 -> V_219 - V_59 -> V_97 < 2 * sizeof( V_274 ) ) {
F_187 ( log , V_59 , V_59 -> V_219 ) ;
if ( ! F_188 ( & V_59 -> V_117 , - 1 , 1 ) ) {
F_15 ( & log -> V_116 ) ;
error = F_46 ( log , V_59 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_116 ) ;
}
goto V_340;
}
if ( V_30 <= V_59 -> V_219 - V_59 -> V_97 ) {
* V_338 = 0 ;
V_59 -> V_97 += V_30 ;
} else {
* V_338 = 1 ;
F_187 ( log , V_59 , V_59 -> V_219 ) ;
}
* V_184 = V_59 ;
ASSERT ( V_59 -> V_97 <= V_59 -> V_219 ) ;
F_15 ( & log -> V_116 ) ;
* V_339 = V_311 ;
return 0 ;
}
STATIC void
F_41 (
struct V_1 * log ,
struct V_15 * V_57 )
{
F_189 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
V_57 -> V_22 -- ;
F_1 ( log , & log -> V_56 . V_12 ,
V_57 -> V_42 ) ;
F_1 ( log , & log -> V_18 . V_12 ,
V_57 -> V_42 ) ;
V_57 -> V_42 = V_57 -> V_21 ;
F_23 ( V_57 ) ;
F_190 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
return;
F_6 ( log , & log -> V_56 . V_12 ,
V_57 -> V_21 ) ;
F_191 ( log , V_57 ) ;
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
F_192 ( log , V_57 ) ;
F_193 ( log , V_57 ) ;
V_3 = V_57 -> V_42 ;
if ( V_57 -> V_22 > 0 ) {
ASSERT ( V_57 -> V_19 & V_20 ) ;
V_3 += V_57 -> V_21 * V_57 -> V_22 ;
}
F_1 ( log , & log -> V_56 . V_12 , V_3 ) ;
F_1 ( log , & log -> V_18 . V_12 , V_3 ) ;
F_194 ( log , V_57 ) ;
F_89 ( log -> V_152 ) ;
}
STATIC int
F_46 (
struct V_1 * log ,
struct V_58 * V_59 )
{
int V_345 = 0 ;
if ( V_59 -> V_66 & V_67 )
return - V_39 ;
ASSERT ( F_152 ( & V_59 -> V_117 ) > 0 ) ;
if ( ! F_195 ( & V_59 -> V_117 , & log -> V_116 ) )
return 0 ;
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
ASSERT ( V_59 -> V_66 == V_68 ||
V_59 -> V_66 == V_69 ) ;
if ( V_59 -> V_66 == V_69 ) {
T_6 V_143 = F_100 ( log -> V_152 ) ;
V_345 ++ ;
V_59 -> V_66 = V_337 ;
V_59 -> V_209 . V_346 = F_186 ( V_143 ) ;
F_196 ( log , V_59 , V_143 ) ;
}
F_15 ( & log -> V_116 ) ;
if ( V_345 )
return F_151 ( log , V_59 ) ;
return 0 ;
}
STATIC void
F_187 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_347 )
{
ASSERT ( V_59 -> V_66 == V_68 ) ;
if ( ! V_347 )
V_347 = V_59 -> V_97 ;
V_59 -> V_66 = V_69 ;
V_59 -> V_209 . V_348 = F_128 ( log -> V_191 ) ;
log -> V_191 = log -> V_344 ;
log -> V_349 = log -> V_192 ;
log -> V_344 += F_124 ( V_347 ) + F_124 ( log -> V_172 ) ;
if ( F_111 ( & log -> V_152 -> V_79 ) &&
log -> V_152 -> V_79 . V_257 > 1 ) {
T_13 V_350 = F_124 ( log -> V_152 -> V_79 . V_257 ) ;
log -> V_344 = F_197 ( log -> V_344 , V_350 ) ;
}
if ( log -> V_344 >= log -> V_190 ) {
log -> V_344 -= log -> V_190 ;
ASSERT ( log -> V_344 >= 0 ) ;
F_198 () ;
log -> V_192 ++ ;
if ( log -> V_192 == V_211 )
log -> V_192 ++ ;
}
ASSERT ( V_59 == log -> V_96 ) ;
log -> V_96 = V_59 -> V_98 ;
}
int
F_73 (
struct V_36 * V_37 ,
T_4 V_296 ,
int * V_351 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
T_6 V_61 ;
F_27 ( V_37 , V_352 ) ;
F_199 ( log ) ;
F_12 ( & log -> V_116 ) ;
V_59 = log -> V_96 ;
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
if ( V_59 -> V_66 == V_68 ||
V_59 -> V_66 == V_118 ) {
if ( V_59 -> V_66 == V_118 ||
( F_152 ( & V_59 -> V_117 ) == 0
&& V_59 -> V_97 == 0 ) ) {
V_59 = V_59 -> V_204 ;
if ( V_59 -> V_66 == V_68 ||
V_59 -> V_66 == V_118 )
goto V_353;
else
goto V_354;
} else {
if ( F_152 ( & V_59 -> V_117 ) == 0 ) {
F_76 ( & V_59 -> V_117 ) ;
V_61 = F_157 ( V_59 -> V_209 . V_238 ) ;
F_187 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_116 ) ;
if ( F_46 ( log , V_59 ) )
return - V_39 ;
if ( V_351 )
* V_351 = 1 ;
F_12 ( & log -> V_116 ) ;
if ( F_157 ( V_59 -> V_209 . V_238 ) == V_61 &&
V_59 -> V_66 != V_118 )
goto V_354;
else
goto V_353;
} else {
F_187 ( log , V_59 , 0 ) ;
goto V_354;
}
}
}
V_354:
if ( V_296 & V_95 ) {
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_355 ) ;
F_78 ( & V_59 -> V_119 , & log -> V_116 ) ;
if ( V_59 -> V_66 & V_67 )
return - V_39 ;
if ( V_351 )
* V_351 = 1 ;
} else {
V_353:
F_15 ( & log -> V_116 ) ;
}
return 0 ;
}
void
F_82 (
T_8 * V_37 ,
T_4 V_296 )
{
int error ;
F_200 ( V_37 , 0 ) ;
error = F_73 ( V_37 , V_296 , NULL ) ;
if ( error )
F_55 ( V_37 , L_98 , V_115 , error ) ;
}
int
F_201 (
struct V_36 * V_37 ,
T_6 V_61 ,
T_4 V_296 ,
int * V_351 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
int V_356 = 0 ;
ASSERT ( V_61 != 0 ) ;
F_27 ( V_37 , V_352 ) ;
V_61 = F_202 ( log , V_61 ) ;
if ( V_61 == V_357 )
return 0 ;
V_358:
F_12 ( & log -> V_116 ) ;
V_59 = log -> V_96 ;
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
do {
if ( F_157 ( V_59 -> V_209 . V_238 ) != V_61 ) {
V_59 = V_59 -> V_98 ;
continue;
}
if ( V_59 -> V_66 == V_118 ) {
F_15 ( & log -> V_116 ) ;
return 0 ;
}
if ( V_59 -> V_66 == V_68 ) {
if ( ! V_356 &&
( V_59 -> V_204 -> V_66 &
( V_69 | V_337 ) ) ) {
ASSERT ( ! ( V_59 -> V_66 & V_67 ) ) ;
F_27 ( V_37 , V_355 ) ;
F_78 ( & V_59 -> V_204 -> V_223 ,
& log -> V_116 ) ;
if ( V_351 )
* V_351 = 1 ;
V_356 = 1 ;
goto V_358;
}
F_76 ( & V_59 -> V_117 ) ;
F_187 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_116 ) ;
if ( F_46 ( log , V_59 ) )
return - V_39 ;
if ( V_351 )
* V_351 = 1 ;
F_12 ( & log -> V_116 ) ;
}
if ( ( V_296 & V_95 ) &&
! ( V_59 -> V_66 &
( V_68 | V_118 ) ) ) {
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_355 ) ;
F_78 ( & V_59 -> V_119 , & log -> V_116 ) ;
if ( V_59 -> V_66 & V_67 )
return - V_39 ;
if ( V_351 )
* V_351 = 1 ;
} else {
F_15 ( & log -> V_116 ) ;
}
return 0 ;
} while ( V_59 != log -> V_96 );
F_15 ( & log -> V_116 ) ;
return 0 ;
}
void
F_203 (
T_8 * V_37 ,
T_6 V_61 ,
T_4 V_296 )
{
int error ;
F_200 ( V_37 , V_61 ) ;
error = F_201 ( V_37 , V_61 , V_296 , NULL ) ;
if ( error )
F_55 ( V_37 , L_98 , V_115 , error ) ;
}
STATIC void
F_77 (
struct V_1 * log ,
struct V_58 * V_59 )
{
F_96 ( & log -> V_116 ) ;
if ( V_59 -> V_66 == V_68 ) {
F_187 ( log , V_59 , 0 ) ;
} else {
ASSERT ( V_59 -> V_66 &
( V_69 | V_67 ) ) ;
}
}
void
F_42 (
T_3 * V_57 )
{
ASSERT ( F_152 ( & V_57 -> V_359 ) > 0 ) ;
if ( F_204 ( & V_57 -> V_359 ) )
F_205 ( V_360 , V_57 ) ;
}
T_3 *
F_206 (
T_3 * V_57 )
{
ASSERT ( F_152 ( & V_57 -> V_359 ) > 0 ) ;
F_76 ( & V_57 -> V_359 ) ;
return V_57 ;
}
int
F_207 (
struct V_36 * V_37 ,
int V_44 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_361 ;
T_4 V_362 ;
V_44 += sizeof( V_274 ) ;
V_44 += sizeof( V_363 ) ;
V_44 += sizeof( V_274 ) ;
V_361 = log -> V_169 - log -> V_172 ;
V_362 = F_208 ( V_44 , V_361 ) ;
V_44 += sizeof( V_274 ) * V_362 ;
while ( ! V_362 ||
F_208 ( V_44 , V_361 ) > V_362 ) {
V_44 += sizeof( V_274 ) ;
V_362 ++ ;
}
V_44 += log -> V_172 * V_362 ;
V_44 += log -> V_172 ;
if ( F_111 ( & V_37 -> V_79 ) && V_37 -> V_79 . V_257 > 1 ) {
V_44 += 2 * V_37 -> V_79 . V_257 ;
} else {
V_44 += 2 * V_176 ;
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
T_19 V_364 )
{
struct V_15 * V_16 ;
int V_365 ;
V_16 = F_209 ( V_360 , V_364 ) ;
if ( ! V_16 )
return NULL ;
V_365 = F_207 ( log -> V_152 , V_44 ) ;
F_129 ( & V_16 -> V_359 , 1 ) ;
V_16 -> V_17 = V_366 ;
F_9 ( & V_16 -> V_367 ) ;
V_16 -> V_21 = V_365 ;
V_16 -> V_42 = V_365 ;
V_16 -> V_22 = V_45 ;
V_16 -> V_368 = V_45 ;
V_16 -> V_41 = F_161 () ;
V_16 -> V_291 = V_47 ;
V_16 -> V_19 = V_62 ;
V_16 -> V_55 = 0 ;
if ( V_48 )
V_16 -> V_19 |= V_20 ;
F_23 ( V_16 ) ;
return V_16 ;
}
void
F_181 (
struct V_1 * log ,
void * V_316 )
{
int V_186 ;
int V_369 = 0 ;
for ( V_186 = 0 ; V_186 < log -> V_166 ; V_186 ++ ) {
if ( V_316 >= log -> V_208 [ V_186 ] &&
V_316 <= log -> V_208 [ V_186 ] + log -> V_169 )
V_369 ++ ;
}
if ( ! V_369 )
F_210 ( log -> V_152 , L_99 , V_115 ) ;
}
STATIC void
F_31 (
struct V_1 * log )
{
int V_149 , V_370 ;
int V_7 , V_8 ;
F_101 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_102 ( & log -> V_147 , & V_149 , & V_370 ) ;
if ( V_149 != V_7 ) {
if ( V_7 - 1 != V_149 &&
! ( log -> V_25 & V_371 ) ) {
F_173 ( log -> V_152 , V_279 ,
L_100 , V_115 ) ;
log -> V_25 |= V_371 ;
}
if ( V_8 > F_103 ( V_370 ) &&
! ( log -> V_25 & V_371 ) ) {
F_173 ( log -> V_152 , V_279 ,
L_101 , V_115 ) ;
log -> V_25 |= V_371 ;
}
}
}
STATIC void
F_196 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_6 V_143 )
{
int V_372 ;
if ( F_211 ( V_143 ) == log -> V_349 ) {
V_372 =
log -> V_190 - ( log -> V_191 - F_156 ( V_143 ) ) ;
if ( V_372 < F_124 ( V_59 -> V_97 ) + F_124 ( log -> V_172 ) )
F_210 ( log -> V_152 , L_102 , V_115 ) ;
} else {
ASSERT ( F_211 ( V_143 ) + 1 == log -> V_349 ) ;
if ( F_156 ( V_143 ) == log -> V_191 )
F_210 ( log -> V_152 , L_103 , V_115 ) ;
V_372 = F_156 ( V_143 ) - log -> V_191 ;
if ( V_372 < F_124 ( V_59 -> V_97 ) + 1 )
F_210 ( log -> V_152 , L_102 , V_115 ) ;
}
}
STATIC void
F_165 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_252 ,
bool V_373 )
{
V_274 * V_374 ;
T_11 * V_375 ;
T_17 * V_240 ;
void * V_376 , * V_316 , * V_377 ;
T_20 V_378 ;
T_5 V_379 ;
int V_30 , V_186 , V_234 , V_235 , V_380 ;
int V_381 ;
F_12 ( & log -> V_116 ) ;
V_375 = log -> V_96 ;
for ( V_186 = 0 ; V_186 < log -> V_166 ; V_186 ++ , V_375 = V_375 -> V_98 )
ASSERT ( V_375 ) ;
if ( V_375 != log -> V_96 )
F_210 ( log -> V_152 , L_104 , V_115 ) ;
F_15 ( & log -> V_116 ) ;
if ( V_59 -> V_209 . V_210 != F_128 ( V_211 ) )
F_210 ( log -> V_152 , L_105 , V_115 ) ;
V_376 = V_316 = & V_59 -> V_209 ;
V_377 = & V_59 -> V_209 ;
for ( V_316 += V_176 ; V_316 < V_376 + V_252 ; V_316 += V_176 ) {
if ( * ( T_16 * ) V_316 == F_128 ( V_211 ) )
F_210 ( log -> V_152 , L_106 ,
V_115 ) ;
}
V_30 = F_160 ( V_59 -> V_209 . V_272 ) ;
V_376 = V_316 = V_59 -> V_222 ;
V_374 = V_316 ;
V_240 = V_59 -> V_206 ;
for ( V_186 = 0 ; V_186 < V_30 ; V_186 ++ ) {
V_374 = V_316 ;
V_377 = & V_374 -> V_290 ;
V_378 = V_377 - V_376 ;
if ( ! V_373 || ( V_378 & 0x1ff ) ) {
V_379 = V_374 -> V_290 ;
} else {
V_381 = F_135 ( ( char * ) & V_374 -> V_290 - V_59 -> V_222 ) ;
if ( V_381 >= ( V_171 / V_176 ) ) {
V_234 = V_381 / ( V_171 / V_176 ) ;
V_235 = V_381 % ( V_171 / V_176 ) ;
V_379 = F_212 (
V_240 [ V_234 ] . V_241 . V_242 [ V_235 ] ) ;
} else {
V_379 = F_212 (
V_59 -> V_209 . V_239 [ V_381 ] ) ;
}
}
if ( V_379 != V_50 && V_379 != V_51 )
F_55 ( log -> V_152 ,
L_107 ,
V_115 , V_379 , V_374 ,
( unsigned long ) V_378 ) ;
V_377 = & V_374 -> V_292 ;
V_378 = V_377 - V_376 ;
if ( ! V_373 || ( V_378 & 0x1ff ) ) {
V_380 = F_160 ( V_374 -> V_292 ) ;
} else {
V_381 = F_135 ( ( V_382 ) & V_374 -> V_292 -
( V_382 ) V_59 -> V_222 ) ;
if ( V_381 >= ( V_171 / V_176 ) ) {
V_234 = V_381 / ( V_171 / V_176 ) ;
V_235 = V_381 % ( V_171 / V_176 ) ;
V_380 = F_160 ( V_240 [ V_234 ] . V_241 . V_242 [ V_235 ] ) ;
} else {
V_380 = F_160 ( V_59 -> V_209 . V_239 [ V_381 ] ) ;
}
}
V_316 += sizeof( V_274 ) + V_380 ;
}
}
STATIC int
F_213 (
struct V_1 * log )
{
T_11 * V_59 , * V_383 ;
V_59 = log -> V_96 ;
if ( ! ( V_59 -> V_66 & V_67 ) ) {
V_383 = V_59 ;
do {
V_383 -> V_66 = V_67 ;
V_383 = V_383 -> V_98 ;
} while ( V_383 != V_59 );
return 0 ;
}
return 1 ;
}
int
F_214 (
struct V_36 * V_37 ,
int V_384 )
{
struct V_1 * log ;
int V_385 ;
log = V_37 -> V_38 ;
if ( ! log ||
log -> V_25 & V_26 ) {
V_37 -> V_77 |= V_386 ;
if ( V_37 -> V_122 )
F_215 ( V_37 -> V_122 ) ;
return 0 ;
}
if ( V_384 && log -> V_96 -> V_66 & V_67 ) {
ASSERT ( F_26 ( log ) ) ;
return 1 ;
}
if ( ! V_384 )
F_73 ( V_37 , V_95 , NULL ) ;
F_12 ( & log -> V_116 ) ;
V_37 -> V_77 |= V_386 ;
if ( V_37 -> V_122 )
F_215 ( V_37 -> V_122 ) ;
log -> V_25 |= V_387 ;
V_385 = F_213 ( log ) ;
F_15 ( & log -> V_116 ) ;
F_11 ( & log -> V_56 ) ;
F_11 ( & log -> V_18 ) ;
F_185 ( & log -> V_388 -> V_389 ) ;
F_184 ( log , V_162 , NULL ) ;
#ifdef F_216
{
T_11 * V_59 ;
F_12 ( & log -> V_116 ) ;
V_59 = log -> V_96 ;
do {
ASSERT ( V_59 -> V_221 == 0 ) ;
V_59 = V_59 -> V_98 ;
} while ( V_59 != log -> V_96 );
F_15 ( & log -> V_116 ) ;
}
#endif
return V_385 ;
}
STATIC int
F_94 (
struct V_1 * log )
{
T_11 * V_59 ;
V_59 = log -> V_96 ;
do {
if ( V_59 -> V_209 . V_272 )
return 0 ;
V_59 = V_59 -> V_98 ;
} while ( V_59 != log -> V_96 );
return 1 ;
}
bool
F_217 (
struct V_36 * V_37 ,
T_6 V_61 )
{
struct V_1 * log = V_37 -> V_38 ;
bool V_390 ;
if ( V_37 -> V_77 & V_78 )
return true ;
if ( V_61 == V_357 )
return true ;
V_390 = F_218 ( V_37 -> V_38 , V_61 ) ;
if ( ! V_390 ) {
F_12 ( & log -> V_116 ) ;
F_55 ( V_37 ,
L_108
L_109 ,
F_211 ( V_61 ) , F_156 ( V_61 ) ,
log -> V_192 , log -> V_344 ) ;
F_15 ( & log -> V_116 ) ;
}
return V_390 ;
}
