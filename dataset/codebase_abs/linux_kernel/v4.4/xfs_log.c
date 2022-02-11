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
if ( F_105 ( V_153 -> V_158 , V_155 -> V_152 ,
V_159 , V_160 ) ) {
F_106 ( V_153 , V_115 ) ;
F_107 ( V_153 ) ;
F_47 ( V_155 -> V_152 , V_72 ) ;
V_157 = V_161 ;
} else if ( V_59 -> V_66 & V_67 ) {
V_157 = V_161 ;
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
int V_162 ;
int V_163 ;
if ( V_37 -> V_164 <= 0 )
log -> V_165 = V_166 ;
else
log -> V_165 = V_37 -> V_164 ;
if ( V_37 -> V_167 > 0 ) {
V_162 = log -> V_168 = V_37 -> V_167 ;
log -> V_169 = 0 ;
while ( V_162 != 1 ) {
log -> V_169 ++ ;
V_162 >>= 1 ;
}
if ( F_111 ( & V_37 -> V_79 ) ) {
V_163 = V_37 -> V_167 / V_170 ;
if ( V_37 -> V_167 % V_170 )
V_163 ++ ;
log -> V_171 = V_163 << V_172 ;
log -> V_173 = V_163 ;
} else {
ASSERT ( V_37 -> V_167 <= V_174 ) ;
log -> V_171 = V_175 ;
log -> V_173 = 1 ;
}
goto V_176;
}
log -> V_168 = V_174 ;
log -> V_169 = V_177 ;
log -> V_171 = V_175 ;
log -> V_173 = 1 ;
V_176:
if ( V_37 -> V_164 == 0 )
V_37 -> V_164 = log -> V_165 ;
if ( V_37 -> V_167 == 0 )
V_37 -> V_167 = log -> V_168 ;
}
void
F_68 (
struct V_36 * V_37 )
{
F_112 ( V_37 -> V_178 , & V_37 -> V_38 -> V_120 ,
F_113 ( V_179 * 10 ) ) ;
}
void
F_114 (
struct V_180 * V_181 )
{
struct V_1 * log = F_115 ( F_116 ( V_181 ) ,
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
struct V_182 * V_73 ,
T_10 V_74 ,
int V_75 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_183 ;
T_11 * V_59 , * V_184 = NULL ;
T_14 * V_153 ;
int V_185 ;
int error = - V_54 ;
T_4 V_186 = 0 ;
log = F_119 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! log ) {
F_55 ( V_37 , L_16 ) ;
goto V_81;
}
log -> V_152 = V_37 ;
log -> V_187 = V_73 ;
log -> V_9 = F_103 ( V_75 ) ;
log -> V_188 = V_74 ;
log -> V_189 = V_75 ;
log -> V_136 = V_139 ;
log -> V_25 |= V_26 ;
F_120 ( & log -> V_120 , F_114 ) ;
log -> V_190 = - 1 ;
F_121 ( & log -> V_147 , 1 , 0 ) ;
F_121 ( & log -> V_146 , 1 , 0 ) ;
log -> V_191 = 1 ;
F_7 ( & log -> V_56 ) ;
F_7 ( & log -> V_18 ) ;
error = - V_192 ;
if ( F_122 ( & V_37 -> V_79 ) ) {
V_186 = V_37 -> V_79 . V_193 ;
if ( V_186 < V_172 ) {
F_55 ( V_37 , L_17 ,
V_186 , V_172 ) ;
goto V_86;
}
V_186 -= V_172 ;
if ( V_186 > V_37 -> V_194 ) {
F_55 ( V_37 , L_18 ,
V_186 , V_37 -> V_194 ) ;
goto V_86;
}
if ( V_186 && log -> V_188 > 0 &&
! F_111 ( & V_37 -> V_79 ) ) {
F_55 ( V_37 ,
L_19 ,
V_186 ) ;
goto V_86;
}
}
log -> V_195 = 1 << V_186 ;
F_110 ( V_37 , log ) ;
error = - V_54 ;
V_153 = F_123 ( V_37 -> V_196 , V_197 ,
F_124 ( log -> V_168 ) , 0 ) ;
if ( ! V_153 )
goto V_86;
ASSERT ( F_125 ( V_153 ) ) ;
F_86 ( V_153 ) ;
V_153 -> V_198 = V_37 -> V_178 ;
V_153 -> V_199 = F_104 ;
log -> V_200 = V_153 ;
F_10 ( & log -> V_116 ) ;
F_126 ( & log -> V_201 ) ;
V_183 = & log -> V_96 ;
ASSERT ( log -> V_168 >= 4096 ) ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
* V_183 = F_119 ( sizeof( T_11 ) , V_53 ) ;
if ( ! * V_183 )
goto V_202;
V_59 = * V_183 ;
V_59 -> V_203 = V_184 ;
V_184 = V_59 ;
V_153 = F_127 ( V_37 -> V_196 ,
F_124 ( log -> V_168 ) , 0 ) ;
if ( ! V_153 )
goto V_202;
ASSERT ( F_125 ( V_153 ) ) ;
F_86 ( V_153 ) ;
V_153 -> V_198 = V_37 -> V_178 ;
V_153 -> V_199 = F_104 ;
V_59 -> V_204 = V_153 ;
V_59 -> V_205 = V_153 -> V_206 ;
#ifdef F_72
log -> V_207 [ V_185 ] = & V_59 -> V_208 ;
#endif
V_2 = & V_59 -> V_208 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_209 = F_128 ( V_210 ) ;
V_2 -> V_211 = F_128 (
F_111 ( & log -> V_152 -> V_79 ) ? 2 : 1 ) ;
V_2 -> V_212 = F_128 ( log -> V_168 ) ;
V_2 -> V_213 = F_128 ( V_214 ) ;
memcpy ( & V_2 -> V_215 , & V_37 -> V_79 . V_216 , sizeof( V_217 ) ) ;
V_59 -> V_218 = F_103 ( V_153 -> V_219 ) - log -> V_171 ;
V_59 -> V_66 = V_68 ;
V_59 -> V_156 = log ;
F_129 ( & V_59 -> V_117 , 0 ) ;
F_10 ( & V_59 -> V_65 ) ;
V_59 -> V_71 = & ( V_59 -> V_220 ) ;
V_59 -> V_221 = ( char * ) V_59 -> V_205 + log -> V_171 ;
F_126 ( & V_59 -> V_119 ) ;
F_126 ( & V_59 -> V_222 ) ;
V_183 = & V_59 -> V_98 ;
}
* V_183 = log -> V_96 ;
log -> V_96 -> V_203 = V_184 ;
error = F_130 ( log ) ;
if ( error )
goto V_202;
return log ;
V_202:
for ( V_59 = log -> V_96 ; V_59 ; V_59 = V_184 ) {
V_184 = V_59 -> V_98 ;
if ( V_59 -> V_204 )
F_131 ( V_59 -> V_204 ) ;
F_132 ( V_59 ) ;
}
F_133 ( & log -> V_116 ) ;
F_131 ( log -> V_200 ) ;
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
T_6 * V_223 )
{
struct V_36 * V_37 = log -> V_152 ;
int error ;
struct V_104 V_105 = {
. V_106 = NULL ,
. V_107 = 0 ,
. V_108 = V_224 ,
} ;
struct V_110 V_111 = {
. V_112 = 1 ,
. V_113 = & V_105 ,
} ;
F_44 ( V_59 ) ;
error = F_74 ( log , & V_111 , V_57 , V_223 , V_59 ,
V_225 ) ;
if ( error )
F_47 ( V_37 , V_72 ) ;
return error ;
}
STATIC void
F_28 (
struct V_1 * log ,
int V_24 )
{
T_6 V_226 = 0 ;
T_6 V_227 ;
int V_228 ;
int V_23 ;
int V_229 ;
int V_230 ;
int V_231 ;
ASSERT ( F_124 ( V_24 ) < log -> V_189 ) ;
V_23 = F_21 ( log , & log -> V_56 . V_12 ) ;
V_228 = F_135 ( V_23 ) ;
V_231 = F_124 ( V_24 ) ;
V_231 = F_136 ( V_231 , ( log -> V_189 >> 2 ) ) ;
V_231 = F_136 ( V_231 , 256 ) ;
if ( V_228 >= V_231 )
return;
F_102 ( & log -> V_147 , & V_230 ,
& V_229 ) ;
V_229 += V_231 ;
if ( V_229 >= log -> V_189 ) {
V_229 -= log -> V_189 ;
V_230 += 1 ;
}
V_226 = F_137 ( V_230 ,
V_229 ) ;
V_227 = F_2 ( & log -> V_146 ) ;
if ( F_138 ( V_226 , V_227 ) > 0 )
V_226 = V_227 ;
if ( ! F_26 ( log ) )
F_139 ( log -> V_87 , V_226 ) ;
}
STATIC void
F_140 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_232 )
{
int V_185 , V_233 , V_234 ;
int V_162 = V_59 -> V_97 + V_232 ;
T_16 V_235 ;
char * V_236 ;
V_235 = F_141 ( V_59 -> V_208 . V_237 ) ;
V_236 = V_59 -> V_221 ;
for ( V_185 = 0 ; V_185 < F_124 ( V_162 ) ; V_185 ++ ) {
if ( V_185 >= ( V_170 / V_175 ) )
break;
V_59 -> V_208 . V_238 [ V_185 ] = * ( T_16 * ) V_236 ;
* ( T_16 * ) V_236 = V_235 ;
V_236 += V_175 ;
}
if ( F_111 ( & log -> V_152 -> V_79 ) ) {
T_17 * V_239 = V_59 -> V_205 ;
for ( ; V_185 < F_124 ( V_162 ) ; V_185 ++ ) {
V_233 = V_185 / ( V_170 / V_175 ) ;
V_234 = V_185 % ( V_170 / V_175 ) ;
V_239 [ V_233 ] . V_240 . V_241 [ V_234 ] = * ( T_16 * ) V_236 ;
* ( T_16 * ) V_236 = V_235 ;
V_236 += V_175 ;
}
for ( V_185 = 1 ; V_185 < log -> V_173 ; V_185 ++ )
V_239 [ V_185 ] . V_240 . V_242 = V_235 ;
}
}
T_18
F_142 (
struct V_1 * log ,
struct V_243 * V_244 ,
char * V_236 ,
int V_162 )
{
T_13 V_245 ;
V_245 = F_143 ( ( char * ) V_244 ,
sizeof( struct V_243 ) ,
F_144 ( struct V_243 , V_246 ) ) ;
if ( F_111 ( & log -> V_152 -> V_79 ) ) {
union V_247 * V_239 = (union V_247 * ) V_244 ;
int V_185 ;
int V_248 ;
V_248 = V_162 / V_170 ;
if ( V_162 % V_170 )
V_248 ++ ;
for ( V_185 = 1 ; V_185 < V_248 ; V_185 ++ ) {
V_245 = F_145 ( V_245 , & V_239 [ V_185 ] . V_240 ,
sizeof( struct V_249 ) ) ;
}
}
V_245 = F_145 ( V_245 , V_236 , V_162 ) ;
return F_146 ( V_245 ) ;
}
STATIC int
F_147 (
struct V_250 * V_153 )
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
int V_185 ;
T_4 V_251 ;
T_4 V_252 ;
int V_232 ;
int V_253 = 0 ;
int error ;
int V_254 = F_111 ( & log -> V_152 -> V_79 ) ;
int V_162 ;
F_27 ( log -> V_152 , V_255 ) ;
ASSERT ( F_152 ( & V_59 -> V_117 ) == 0 ) ;
V_252 = log -> V_171 + V_59 -> V_97 ;
if ( V_254 && log -> V_152 -> V_79 . V_256 > 1 ) {
V_251 = F_153 ( log , F_154 ( log , V_252 ) ) ;
} else {
V_251 = F_103 ( F_124 ( V_252 ) ) ;
}
V_232 = V_251 - V_252 ;
ASSERT ( V_232 >= 0 ) ;
ASSERT ( ( V_254 && log -> V_152 -> V_79 . V_256 > 1 &&
V_232 < log -> V_152 -> V_79 . V_256 )
||
( log -> V_152 -> V_79 . V_256 <= 1 &&
V_232 < F_103 ( 1 ) ) ) ;
F_6 ( log , & log -> V_56 . V_12 , V_232 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_232 ) ;
F_140 ( log , V_59 , V_232 ) ;
V_162 = V_59 -> V_97 ;
if ( V_254 )
V_162 += V_232 ;
V_59 -> V_208 . V_257 = F_128 ( V_162 ) ;
V_153 = V_59 -> V_204 ;
F_155 ( V_153 , F_156 ( F_157 ( V_59 -> V_208 . V_237 ) ) ) ;
F_158 ( log -> V_152 , V_258 , F_124 ( V_251 ) ) ;
if ( F_159 ( V_153 ) + F_124 ( V_251 ) > log -> V_189 ) {
char * V_259 ;
V_253 = V_251 - ( F_103 ( log -> V_189 - F_159 ( V_153 ) ) ) ;
V_251 = F_103 ( log -> V_189 - F_159 ( V_153 ) ) ;
V_59 -> V_260 = 2 ;
V_259 = ( char * ) & V_59 -> V_208 + V_251 ;
for ( V_185 = 0 ; V_185 < V_253 ; V_185 += V_175 ) {
T_13 V_7 = F_160 ( * ( T_16 * ) V_259 ) ;
if ( ++ V_7 == V_210 )
V_7 ++ ;
* ( T_16 * ) V_259 = F_128 ( V_7 ) ;
V_259 += V_175 ;
}
} else {
V_59 -> V_260 = 1 ;
}
V_59 -> V_208 . V_246 = F_142 ( log , & V_59 -> V_208 ,
V_59 -> V_221 , V_162 ) ;
V_153 -> V_261 = F_124 ( V_251 ) ;
V_153 -> V_154 = V_59 ;
F_161 ( V_153 ) ;
F_162 ( V_153 ) ;
V_153 -> V_262 |= V_263 ;
if ( log -> V_152 -> V_77 & V_264 ) {
V_153 -> V_262 |= V_265 ;
if ( log -> V_152 -> V_196 != log -> V_152 -> V_121 )
F_163 ( log -> V_152 -> V_121 ) ;
else
V_153 -> V_262 |= V_266 ;
}
ASSERT ( F_159 ( V_153 ) <= log -> V_189 - 1 ) ;
ASSERT ( F_159 ( V_153 ) + F_124 ( V_251 ) <= log -> V_189 ) ;
F_164 ( log , V_59 , V_251 , true ) ;
F_155 ( V_153 , F_159 ( V_153 ) + log -> V_188 ) ;
F_165 ( V_153 ) ;
error = F_147 ( V_153 ) ;
if ( error ) {
F_106 ( V_153 , L_20 ) ;
return error ;
}
if ( V_253 ) {
V_153 = V_59 -> V_156 -> V_200 ;
F_155 ( V_153 , 0 ) ;
F_166 ( V_153 ,
( char * ) & V_59 -> V_208 + V_251 , V_253 ) ;
V_153 -> V_154 = V_59 ;
F_161 ( V_153 ) ;
F_162 ( V_153 ) ;
V_153 -> V_262 |= V_263 ;
if ( log -> V_152 -> V_77 & V_264 )
V_153 -> V_262 |= V_265 ;
ASSERT ( F_159 ( V_153 ) <= log -> V_189 - 1 ) ;
ASSERT ( F_159 ( V_153 ) + F_124 ( V_251 ) <= log -> V_189 ) ;
F_155 ( V_153 , F_159 ( V_153 ) + log -> V_188 ) ;
F_165 ( V_153 ) ;
error = F_147 ( V_153 ) ;
if ( error ) {
F_106 ( V_153 , L_21 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_65 (
struct V_1 * log )
{
T_11 * V_59 , * V_267 ;
int V_185 ;
F_167 ( log ) ;
V_59 = log -> V_96 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
F_85 ( V_59 -> V_204 ) ;
F_86 ( V_59 -> V_204 ) ;
V_59 = V_59 -> V_98 ;
}
F_85 ( log -> V_200 ) ;
F_86 ( log -> V_200 ) ;
F_168 ( log -> V_200 , F_124 ( log -> V_168 ) ) ;
F_131 ( log -> V_200 ) ;
V_59 = log -> V_96 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
F_131 ( V_59 -> V_204 ) ;
V_267 = V_59 -> V_98 ;
F_132 ( V_59 ) ;
V_59 = V_267 ;
}
F_133 ( & log -> V_116 ) ;
log -> V_152 -> V_38 = NULL ;
F_132 ( log ) ;
}
static inline void
F_169 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_268 ,
int V_269 )
{
F_12 ( & log -> V_116 ) ;
F_170 ( & V_59 -> V_208 . V_270 , V_268 ) ;
V_59 -> V_97 += V_269 ;
F_15 ( & log -> V_116 ) ;
}
void
F_171 (
struct V_36 * V_37 ,
struct V_15 * V_57 )
{
T_4 V_185 ;
T_4 V_271 = V_57 -> V_29 * ( T_4 ) sizeof( V_272 ) ;
static char * V_273 [ V_274 ] = {
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
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ,
L_39 ,
L_40
} ;
static char * V_275 [ V_276 ] = {
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
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80
} ;
F_55 ( V_37 , L_81 ) ;
F_55 ( V_37 , L_82 ,
( ( V_57 -> V_55 <= 0 ||
V_57 -> V_55 > V_276 ) ?
L_83 : V_275 [ V_57 -> V_55 - 1 ] ) ,
V_57 -> V_55 ) ;
F_55 ( V_37 , L_84 ,
V_57 -> V_21 ) ;
F_55 ( V_37 , L_85 ,
V_57 -> V_42 ) ;
F_55 ( V_37 , L_86 ,
V_57 -> V_28 , V_57 -> V_32 ) ;
F_55 ( V_37 , L_87 ,
V_57 -> V_29 , V_271 ) ;
F_55 ( V_37 , L_88 ,
V_57 -> V_28 + V_57 -> V_32 + V_271 ) ;
F_55 ( V_37 , L_89 ,
V_57 -> V_27 ) ;
for ( V_185 = 0 ; V_185 < V_57 -> V_27 ; V_185 ++ ) {
T_4 V_35 = V_57 -> V_33 [ V_185 ] . V_35 ;
F_55 ( V_37 , L_90 , V_185 ,
( ( V_35 <= 0 || V_35 > V_274 ) ?
L_91 : V_273 [ V_35 - 1 ] ) ,
V_57 -> V_33 [ V_185 ] . V_34 ) ;
}
F_172 ( V_37 , V_277 ,
L_92 ) ;
F_47 ( V_37 , V_72 ) ;
}
static int
F_173 (
struct V_15 * V_57 ,
struct V_110 * V_278 )
{
struct V_110 * V_279 ;
int V_280 = 0 ;
int V_30 = 0 ;
int V_185 ;
if ( V_57 -> V_19 & V_62 )
V_280 ++ ;
for ( V_279 = V_278 ; V_279 ; V_279 = V_279 -> V_281 ) {
if ( V_279 -> V_282 == V_283 )
continue;
V_280 += V_279 -> V_112 ;
for ( V_185 = 0 ; V_185 < V_279 -> V_112 ; V_185 ++ ) {
struct V_104 * V_284 = & V_279 -> V_113 [ V_185 ] ;
V_30 += V_284 -> V_107 ;
F_24 ( V_57 , V_284 -> V_107 , V_284 -> V_108 ) ;
}
}
V_57 -> V_29 += V_280 ;
V_30 += V_280 * sizeof( struct V_285 ) ;
return V_30 ;
}
static int
F_174 (
struct V_285 * V_286 ,
struct V_15 * V_57 )
{
if ( ! ( V_57 -> V_19 & V_62 ) )
return 0 ;
V_286 -> V_287 = F_128 ( V_57 -> V_41 ) ;
V_286 -> V_288 = V_57 -> V_289 ;
V_286 -> V_290 = 0 ;
V_286 -> V_291 = V_292 ;
V_286 -> V_293 = 0 ;
V_57 -> V_19 &= ~ V_62 ;
return sizeof( struct V_285 ) ;
}
static V_272 *
F_175 (
struct V_1 * log ,
struct V_285 * V_286 ,
struct V_15 * V_57 ,
T_4 V_294 )
{
V_286 -> V_287 = F_128 ( V_57 -> V_41 ) ;
V_286 -> V_288 = V_57 -> V_289 ;
V_286 -> V_293 = 0 ;
V_286 -> V_291 = V_294 ;
switch ( V_286 -> V_288 ) {
case V_50 :
case V_295 :
case V_51 :
break;
default:
F_55 ( log -> V_152 ,
L_93 ,
V_286 -> V_288 , V_57 ) ;
return NULL ;
}
return V_286 ;
}
static int
F_176 (
struct V_15 * V_57 ,
struct V_285 * V_286 ,
int V_296 ,
int V_297 ,
int * V_298 ,
int * V_299 ,
int * V_300 ,
int * V_301 )
{
int V_302 ;
V_302 = V_297 - * V_301 ;
* V_298 = * V_301 ;
if ( V_302 <= V_296 ) {
* V_299 = V_302 ;
V_286 -> V_290 = F_128 ( * V_299 ) ;
if ( * V_300 )
V_286 -> V_291 |= ( V_303 | V_304 ) ;
* V_300 = 0 ;
* V_301 = 0 ;
return 0 ;
}
* V_299 = V_296 ;
V_286 -> V_290 = F_128 ( * V_299 ) ;
V_286 -> V_291 |= V_305 ;
if ( * V_300 )
V_286 -> V_291 |= V_304 ;
* V_301 += * V_299 ;
( * V_300 ) ++ ;
V_57 -> V_42 -= sizeof( struct V_285 ) ;
V_57 -> V_29 ++ ;
return sizeof( struct V_285 ) ;
}
static int
F_177 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_4 V_294 ,
int * V_268 ,
int * V_306 ,
int * V_307 ,
int * V_308 ,
int V_309 ,
struct V_58 * * V_310 )
{
if ( * V_307 ) {
F_169 ( log , V_59 , * V_268 , * V_306 ) ;
* V_268 = 0 ;
* V_306 = 0 ;
return F_46 ( log , V_59 ) ;
}
* V_307 = 0 ;
* V_308 = 0 ;
if ( V_59 -> V_218 - V_309 <= sizeof( V_272 ) ) {
F_169 ( log , V_59 , * V_268 , * V_306 ) ;
* V_268 = 0 ;
* V_306 = 0 ;
F_12 ( & log -> V_116 ) ;
F_77 ( log , V_59 ) ;
F_15 ( & log -> V_116 ) ;
if ( ! V_310 )
return F_46 ( log , V_59 ) ;
ASSERT ( V_294 & V_225 ) ;
* V_310 = V_59 ;
}
return 0 ;
}
int
F_74 (
struct V_1 * log ,
struct V_110 * V_278 ,
struct V_15 * V_57 ,
T_6 * V_311 ,
struct V_58 * * V_310 ,
T_4 V_294 )
{
struct V_58 * V_59 = NULL ;
struct V_104 * V_284 ;
struct V_110 * V_279 ;
int V_30 ;
int V_312 ;
int V_307 = 0 ;
int V_308 = 0 ;
int V_313 = 0 ;
int V_268 = 0 ;
int V_306 = 0 ;
int error ;
* V_311 = 0 ;
V_30 = F_173 ( V_57 , V_278 ) ;
if ( V_57 -> V_19 & V_62 )
V_57 -> V_42 -= sizeof( V_272 ) ;
if ( V_294 & ( V_225 | V_114 ) )
V_57 -> V_42 -= sizeof( V_272 ) ;
if ( V_57 -> V_42 < 0 )
F_171 ( log -> V_152 , V_57 ) ;
V_312 = 0 ;
V_279 = V_278 ;
V_284 = V_279 -> V_113 ;
while ( V_279 && ( ! V_279 -> V_112 || V_312 < V_279 -> V_112 ) ) {
void * V_314 ;
int V_309 ;
error = F_178 ( log , V_30 , & V_59 , V_57 ,
& V_313 , & V_309 ) ;
if ( error )
return error ;
ASSERT ( V_309 <= V_59 -> V_218 - 1 ) ;
V_314 = V_59 -> V_221 + V_309 ;
if ( ! * V_311 )
* V_311 = F_157 ( V_59 -> V_208 . V_237 ) ;
while ( V_279 && ( ! V_279 -> V_112 || V_312 < V_279 -> V_112 ) ) {
struct V_104 * V_105 ;
struct V_285 * V_286 ;
int V_315 ;
int V_299 ;
int V_298 ;
bool V_316 = false ;
if ( V_279 -> V_282 == V_283 ) {
ASSERT ( V_279 -> V_112 == 0 ) ;
V_316 = true ;
goto V_317;
}
V_105 = & V_284 [ V_312 ] ;
ASSERT ( V_105 -> V_107 % sizeof( V_318 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_314 % sizeof( V_318 ) == 0 ) ;
V_315 = F_174 ( V_314 , V_57 ) ;
if ( V_315 ) {
V_268 ++ ;
F_179 ( & V_314 , & V_30 , & V_309 ,
V_315 ) ;
}
V_286 = F_175 ( log , V_314 , V_57 , V_294 ) ;
if ( ! V_286 )
return - V_39 ;
F_179 ( & V_314 , & V_30 , & V_309 ,
sizeof( struct V_285 ) ) ;
V_30 += F_176 ( V_57 , V_286 ,
V_59 -> V_218 - V_309 ,
V_105 -> V_107 ,
& V_298 , & V_299 ,
& V_307 ,
& V_308 ) ;
F_180 ( log , V_314 ) ;
ASSERT ( V_299 >= 0 ) ;
if ( V_299 > 0 ) {
memcpy ( V_314 , V_105 -> V_106 + V_298 , V_299 ) ;
F_179 ( & V_314 , & V_30 , & V_309 ,
V_299 ) ;
}
V_299 += V_315 + sizeof( V_272 ) ;
V_268 ++ ;
V_306 += V_313 ? V_299 : 0 ;
error = F_177 ( log , V_59 , V_294 ,
& V_268 , & V_306 ,
& V_307 ,
& V_308 ,
V_309 ,
V_310 ) ;
if ( error )
return error ;
if ( V_307 )
break;
if ( ++ V_312 == V_279 -> V_112 ) {
V_317:
V_279 = V_279 -> V_281 ;
V_312 = 0 ;
if ( V_279 )
V_284 = V_279 -> V_113 ;
}
if ( V_268 == 0 && V_316 == false ) {
if ( ! V_279 )
return 0 ;
break;
}
}
}
ASSERT ( V_30 == 0 ) ;
F_169 ( log , V_59 , V_268 , V_306 ) ;
if ( ! V_310 )
return F_46 ( log , V_59 ) ;
ASSERT ( V_294 & V_225 ) ;
* V_310 = V_59 ;
return 0 ;
}
STATIC void
F_181 (
struct V_1 * log )
{
T_11 * V_59 ;
int V_319 = 0 ;
V_59 = log -> V_96 ;
do {
if ( V_59 -> V_66 == V_118 ) {
V_59 -> V_66 = V_68 ;
V_59 -> V_97 = 0 ;
ASSERT ( V_59 -> V_220 == NULL ) ;
if ( ! V_319 &&
( F_160 ( V_59 -> V_208 . V_270 ) ==
V_320 ) ) {
V_319 = 1 ;
} else {
V_319 = 2 ;
}
V_59 -> V_208 . V_270 = 0 ;
memset ( V_59 -> V_208 . V_238 , 0 ,
sizeof( V_59 -> V_208 . V_238 ) ) ;
V_59 -> V_208 . V_237 = 0 ;
} else if ( V_59 -> V_66 == V_68 )
;
else
break;
V_59 = V_59 -> V_98 ;
} while ( V_59 != log -> V_96 );
if ( V_319 ) {
switch ( log -> V_136 ) {
case V_139 :
case V_140 :
case V_141 :
log -> V_136 = V_140 ;
break;
case V_137 :
if ( V_319 == 1 )
log -> V_136 = V_141 ;
else
log -> V_136 = V_140 ;
break;
case V_138 :
if ( V_319 == 1 )
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
F_182 (
struct V_1 * log )
{
T_11 * V_321 ;
T_6 V_322 , V_61 ;
V_321 = log -> V_96 ;
V_322 = 0 ;
do {
if ( ! ( V_321 -> V_66 & ( V_68 | V_118 ) ) ) {
V_61 = F_157 ( V_321 -> V_208 . V_237 ) ;
if ( ( V_61 && ! V_322 ) ||
( F_138 ( V_61 , V_322 ) < 0 ) ) {
V_322 = V_61 ;
}
}
V_321 = V_321 -> V_98 ;
} while ( V_321 != log -> V_96 );
return V_322 ;
}
STATIC void
F_183 (
struct V_1 * log ,
int V_157 ,
struct V_58 * V_323 )
{
T_11 * V_59 ;
T_11 * V_94 ;
T_7 * V_63 , * V_70 ;
int V_324 = 0 ;
T_6 V_322 ;
int V_325 ;
int V_326 ;
int V_327 ;
int V_328 ;
int V_329 = 0 ;
F_12 ( & log -> V_116 ) ;
V_94 = V_59 = log -> V_96 ;
V_325 = 0 ;
V_327 = 0 ;
V_328 = 0 ;
do {
V_94 = log -> V_96 ;
V_59 = log -> V_96 ;
V_326 = 0 ;
V_328 ++ ;
do {
if ( V_59 -> V_66 &
( V_68 | V_118 ) ) {
V_59 = V_59 -> V_98 ;
continue;
}
if ( ! ( V_59 -> V_66 & V_67 ) ) {
if ( ! ( V_59 -> V_66 &
( V_330 |
V_331 ) ) ) {
if ( V_323 && ( V_323 -> V_66 ==
V_330 ) ) {
V_323 -> V_66 = V_331 ;
}
break;
}
V_322 = F_182 ( log ) ;
if ( V_322 &&
F_138 ( V_322 ,
F_157 ( V_59 -> V_208 . V_237 ) ) < 0 ) {
V_59 = V_59 -> V_98 ;
continue;
}
V_59 -> V_66 = V_332 ;
ASSERT ( F_138 ( F_2 ( & log -> V_146 ) ,
F_157 ( V_59 -> V_208 . V_237 ) ) <= 0 ) ;
if ( V_59 -> V_220 )
F_99 ( & log -> V_146 ,
F_157 ( V_59 -> V_208 . V_237 ) ) ;
} else
V_325 ++ ;
F_15 ( & log -> V_116 ) ;
F_12 ( & V_59 -> V_65 ) ;
V_63 = V_59 -> V_220 ;
while ( V_63 ) {
V_59 -> V_71 = & ( V_59 -> V_220 ) ;
V_59 -> V_220 = NULL ;
F_15 ( & V_59 -> V_65 ) ;
for (; V_63 ; V_63 = V_70 ) {
V_70 = V_63 -> V_70 ;
V_63 -> V_333 ( V_63 -> V_334 , V_157 ) ;
}
F_12 ( & V_59 -> V_65 ) ;
V_63 = V_59 -> V_220 ;
}
V_326 ++ ;
V_327 ++ ;
F_12 ( & log -> V_116 ) ;
ASSERT ( V_59 -> V_220 == NULL ) ;
F_15 ( & V_59 -> V_65 ) ;
if ( ! ( V_59 -> V_66 & V_67 ) )
V_59 -> V_66 = V_118 ;
F_181 ( log ) ;
F_184 ( & V_59 -> V_119 ) ;
V_59 = V_59 -> V_98 ;
} while ( V_94 != V_59 );
if ( V_328 > 5000 ) {
V_324 += V_328 ;
V_328 = 0 ;
F_55 ( log -> V_152 ,
L_94 ,
V_115 , V_324 ) ;
}
} while ( ! V_325 && V_326 );
#ifdef F_72
if ( V_327 ) {
V_94 = V_59 = log -> V_96 ;
do {
ASSERT ( V_59 -> V_66 != V_331 ) ;
if ( V_59 -> V_66 == V_69 ||
V_59 -> V_66 == V_335 ||
V_59 -> V_66 == V_330 ||
V_59 -> V_66 == V_67 )
break;
V_59 = V_59 -> V_98 ;
} while ( V_94 != V_59 );
}
#endif
if ( log -> V_96 -> V_66 & ( V_68 | V_67 ) )
V_329 = 1 ;
F_15 ( & log -> V_116 ) ;
if ( V_329 )
F_184 ( & log -> V_201 ) ;
}
STATIC void
F_109 (
T_11 * V_59 ,
int V_157 )
{
struct V_1 * log = V_59 -> V_156 ;
F_12 ( & log -> V_116 ) ;
ASSERT ( V_59 -> V_66 == V_335 ||
V_59 -> V_66 == V_67 ) ;
ASSERT ( F_152 ( & V_59 -> V_117 ) == 0 ) ;
ASSERT ( V_59 -> V_260 == 1 || V_59 -> V_260 == 2 ) ;
if ( V_59 -> V_66 != V_67 ) {
if ( -- V_59 -> V_260 == 1 ) {
F_15 ( & log -> V_116 ) ;
return;
}
V_59 -> V_66 = V_330 ;
}
F_184 ( & V_59 -> V_222 ) ;
F_15 ( & log -> V_116 ) ;
F_183 ( log , V_157 , V_59 ) ;
}
STATIC int
F_178 (
struct V_1 * log ,
int V_30 ,
struct V_58 * * V_183 ,
struct V_15 * V_57 ,
int * V_336 ,
int * V_337 )
{
int V_309 ;
T_15 * V_2 ;
T_11 * V_59 ;
int error ;
V_338:
F_12 ( & log -> V_116 ) ;
if ( F_26 ( log ) ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
V_59 = log -> V_96 ;
if ( V_59 -> V_66 != V_68 ) {
F_27 ( log -> V_152 , V_339 ) ;
F_78 ( & log -> V_201 , & log -> V_116 ) ;
goto V_338;
}
V_2 = & V_59 -> V_208 ;
F_76 ( & V_59 -> V_117 ) ;
V_309 = V_59 -> V_97 ;
if ( V_309 == 0 ) {
V_57 -> V_42 -= log -> V_171 ;
F_24 ( V_57 ,
log -> V_171 ,
V_340 ) ;
V_2 -> V_341 = F_128 ( log -> V_191 ) ;
V_2 -> V_237 = F_185 (
F_137 ( log -> V_191 , log -> V_342 ) ) ;
ASSERT ( log -> V_342 >= 0 ) ;
}
if ( V_59 -> V_218 - V_59 -> V_97 < 2 * sizeof( V_272 ) ) {
F_186 ( log , V_59 , V_59 -> V_218 ) ;
if ( ! F_187 ( & V_59 -> V_117 , - 1 , 1 ) ) {
F_15 ( & log -> V_116 ) ;
error = F_46 ( log , V_59 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_116 ) ;
}
goto V_338;
}
if ( V_30 <= V_59 -> V_218 - V_59 -> V_97 ) {
* V_336 = 0 ;
V_59 -> V_97 += V_30 ;
} else {
* V_336 = 1 ;
F_186 ( log , V_59 , V_59 -> V_218 ) ;
}
* V_183 = V_59 ;
ASSERT ( V_59 -> V_97 <= V_59 -> V_218 ) ;
F_15 ( & log -> V_116 ) ;
* V_337 = V_309 ;
return 0 ;
}
STATIC void
F_41 (
struct V_1 * log ,
struct V_15 * V_57 )
{
F_188 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
V_57 -> V_22 -- ;
F_1 ( log , & log -> V_56 . V_12 ,
V_57 -> V_42 ) ;
F_1 ( log , & log -> V_18 . V_12 ,
V_57 -> V_42 ) ;
V_57 -> V_42 = V_57 -> V_21 ;
F_23 ( V_57 ) ;
F_189 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
return;
F_6 ( log , & log -> V_56 . V_12 ,
V_57 -> V_21 ) ;
F_190 ( log , V_57 ) ;
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
F_191 ( log , V_57 ) ;
F_192 ( log , V_57 ) ;
V_3 = V_57 -> V_42 ;
if ( V_57 -> V_22 > 0 ) {
ASSERT ( V_57 -> V_19 & V_20 ) ;
V_3 += V_57 -> V_21 * V_57 -> V_22 ;
}
F_1 ( log , & log -> V_56 . V_12 , V_3 ) ;
F_1 ( log , & log -> V_18 . V_12 , V_3 ) ;
F_193 ( log , V_57 ) ;
F_89 ( log -> V_152 ) ;
}
STATIC int
F_46 (
struct V_1 * log ,
struct V_58 * V_59 )
{
int V_343 = 0 ;
if ( V_59 -> V_66 & V_67 )
return - V_39 ;
ASSERT ( F_152 ( & V_59 -> V_117 ) > 0 ) ;
if ( ! F_194 ( & V_59 -> V_117 , & log -> V_116 ) )
return 0 ;
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
ASSERT ( V_59 -> V_66 == V_68 ||
V_59 -> V_66 == V_69 ) ;
if ( V_59 -> V_66 == V_69 ) {
T_6 V_143 = F_100 ( log -> V_152 ) ;
V_343 ++ ;
V_59 -> V_66 = V_335 ;
V_59 -> V_208 . V_344 = F_185 ( V_143 ) ;
F_195 ( log , V_59 , V_143 ) ;
}
F_15 ( & log -> V_116 ) ;
if ( V_343 )
return F_151 ( log , V_59 ) ;
return 0 ;
}
STATIC void
F_186 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_345 )
{
ASSERT ( V_59 -> V_66 == V_68 ) ;
if ( ! V_345 )
V_345 = V_59 -> V_97 ;
V_59 -> V_66 = V_69 ;
V_59 -> V_208 . V_346 = F_128 ( log -> V_190 ) ;
log -> V_190 = log -> V_342 ;
log -> V_347 = log -> V_191 ;
log -> V_342 += F_124 ( V_345 ) + F_124 ( log -> V_171 ) ;
if ( F_111 ( & log -> V_152 -> V_79 ) &&
log -> V_152 -> V_79 . V_256 > 1 ) {
T_13 V_348 = F_124 ( log -> V_152 -> V_79 . V_256 ) ;
log -> V_342 = F_196 ( log -> V_342 , V_348 ) ;
}
if ( log -> V_342 >= log -> V_189 ) {
log -> V_342 -= log -> V_189 ;
ASSERT ( log -> V_342 >= 0 ) ;
F_197 () ;
log -> V_191 ++ ;
if ( log -> V_191 == V_210 )
log -> V_191 ++ ;
}
ASSERT ( V_59 == log -> V_96 ) ;
log -> V_96 = V_59 -> V_98 ;
}
int
F_73 (
struct V_36 * V_37 ,
T_4 V_294 ,
int * V_349 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
T_6 V_61 ;
F_27 ( V_37 , V_350 ) ;
F_198 ( log ) ;
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
V_59 = V_59 -> V_203 ;
if ( V_59 -> V_66 == V_68 ||
V_59 -> V_66 == V_118 )
goto V_351;
else
goto V_352;
} else {
if ( F_152 ( & V_59 -> V_117 ) == 0 ) {
F_76 ( & V_59 -> V_117 ) ;
V_61 = F_157 ( V_59 -> V_208 . V_237 ) ;
F_186 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_116 ) ;
if ( F_46 ( log , V_59 ) )
return - V_39 ;
if ( V_349 )
* V_349 = 1 ;
F_12 ( & log -> V_116 ) ;
if ( F_157 ( V_59 -> V_208 . V_237 ) == V_61 &&
V_59 -> V_66 != V_118 )
goto V_352;
else
goto V_351;
} else {
F_186 ( log , V_59 , 0 ) ;
goto V_352;
}
}
}
V_352:
if ( V_294 & V_95 ) {
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_353 ) ;
F_78 ( & V_59 -> V_119 , & log -> V_116 ) ;
if ( V_59 -> V_66 & V_67 )
return - V_39 ;
if ( V_349 )
* V_349 = 1 ;
} else {
V_351:
F_15 ( & log -> V_116 ) ;
}
return 0 ;
}
void
F_82 (
T_8 * V_37 ,
T_4 V_294 )
{
int error ;
F_199 ( V_37 , 0 ) ;
error = F_73 ( V_37 , V_294 , NULL ) ;
if ( error )
F_55 ( V_37 , L_95 , V_115 , error ) ;
}
int
F_200 (
struct V_36 * V_37 ,
T_6 V_61 ,
T_4 V_294 ,
int * V_349 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
int V_354 = 0 ;
ASSERT ( V_61 != 0 ) ;
F_27 ( V_37 , V_350 ) ;
V_61 = F_201 ( log , V_61 ) ;
if ( V_61 == V_355 )
return 0 ;
V_356:
F_12 ( & log -> V_116 ) ;
V_59 = log -> V_96 ;
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
do {
if ( F_157 ( V_59 -> V_208 . V_237 ) != V_61 ) {
V_59 = V_59 -> V_98 ;
continue;
}
if ( V_59 -> V_66 == V_118 ) {
F_15 ( & log -> V_116 ) ;
return 0 ;
}
if ( V_59 -> V_66 == V_68 ) {
if ( ! V_354 &&
( V_59 -> V_203 -> V_66 &
( V_69 | V_335 ) ) ) {
ASSERT ( ! ( V_59 -> V_66 & V_67 ) ) ;
F_27 ( V_37 , V_353 ) ;
F_78 ( & V_59 -> V_203 -> V_222 ,
& log -> V_116 ) ;
if ( V_349 )
* V_349 = 1 ;
V_354 = 1 ;
goto V_356;
}
F_76 ( & V_59 -> V_117 ) ;
F_186 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_116 ) ;
if ( F_46 ( log , V_59 ) )
return - V_39 ;
if ( V_349 )
* V_349 = 1 ;
F_12 ( & log -> V_116 ) ;
}
if ( ( V_294 & V_95 ) &&
! ( V_59 -> V_66 &
( V_68 | V_118 ) ) ) {
if ( V_59 -> V_66 & V_67 ) {
F_15 ( & log -> V_116 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_353 ) ;
F_78 ( & V_59 -> V_119 , & log -> V_116 ) ;
if ( V_59 -> V_66 & V_67 )
return - V_39 ;
if ( V_349 )
* V_349 = 1 ;
} else {
F_15 ( & log -> V_116 ) ;
}
return 0 ;
} while ( V_59 != log -> V_96 );
F_15 ( & log -> V_116 ) ;
return 0 ;
}
void
F_202 (
T_8 * V_37 ,
T_6 V_61 ,
T_4 V_294 )
{
int error ;
F_199 ( V_37 , V_61 ) ;
error = F_200 ( V_37 , V_61 , V_294 , NULL ) ;
if ( error )
F_55 ( V_37 , L_95 , V_115 , error ) ;
}
STATIC void
F_77 (
struct V_1 * log ,
struct V_58 * V_59 )
{
F_96 ( & log -> V_116 ) ;
if ( V_59 -> V_66 == V_68 ) {
F_186 ( log , V_59 , 0 ) ;
} else {
ASSERT ( V_59 -> V_66 &
( V_69 | V_67 ) ) ;
}
}
void
F_42 (
T_3 * V_57 )
{
ASSERT ( F_152 ( & V_57 -> V_357 ) > 0 ) ;
if ( F_203 ( & V_57 -> V_357 ) )
F_204 ( V_358 , V_57 ) ;
}
T_3 *
F_205 (
T_3 * V_57 )
{
ASSERT ( F_152 ( & V_57 -> V_357 ) > 0 ) ;
F_76 ( & V_57 -> V_357 ) ;
return V_57 ;
}
int
F_206 (
struct V_36 * V_37 ,
int V_44 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_359 ;
T_4 V_360 ;
V_44 += sizeof( V_272 ) ;
V_44 += sizeof( V_361 ) ;
V_44 += sizeof( V_272 ) ;
V_359 = log -> V_168 - log -> V_171 ;
V_360 = F_207 ( V_44 , V_359 ) ;
V_44 += sizeof( V_272 ) * V_360 ;
while ( ! V_360 ||
F_207 ( V_44 , V_359 ) > V_360 ) {
V_44 += sizeof( V_272 ) ;
V_360 ++ ;
}
V_44 += log -> V_171 * V_360 ;
V_44 += log -> V_171 ;
if ( F_111 ( & V_37 -> V_79 ) && V_37 -> V_79 . V_256 > 1 ) {
V_44 += 2 * V_37 -> V_79 . V_256 ;
} else {
V_44 += 2 * V_175 ;
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
T_19 V_362 )
{
struct V_15 * V_16 ;
int V_363 ;
V_16 = F_208 ( V_358 , V_362 ) ;
if ( ! V_16 )
return NULL ;
V_363 = F_206 ( log -> V_152 , V_44 ) ;
F_129 ( & V_16 -> V_357 , 1 ) ;
V_16 -> V_17 = V_364 ;
F_9 ( & V_16 -> V_365 ) ;
V_16 -> V_21 = V_363 ;
V_16 -> V_42 = V_363 ;
V_16 -> V_22 = V_45 ;
V_16 -> V_366 = V_45 ;
V_16 -> V_41 = F_209 () ;
V_16 -> V_289 = V_47 ;
V_16 -> V_19 = V_62 ;
V_16 -> V_55 = 0 ;
if ( V_48 )
V_16 -> V_19 |= V_20 ;
F_23 ( V_16 ) ;
return V_16 ;
}
void
F_180 (
struct V_1 * log ,
void * V_314 )
{
int V_185 ;
int V_367 = 0 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
if ( V_314 >= log -> V_207 [ V_185 ] &&
V_314 <= log -> V_207 [ V_185 ] + log -> V_168 )
V_367 ++ ;
}
if ( ! V_367 )
F_210 ( log -> V_152 , L_96 , V_115 ) ;
}
STATIC void
F_31 (
struct V_1 * log )
{
int V_149 , V_368 ;
int V_7 , V_8 ;
F_101 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_102 ( & log -> V_147 , & V_149 , & V_368 ) ;
if ( V_149 != V_7 ) {
if ( V_7 - 1 != V_149 &&
! ( log -> V_25 & V_369 ) ) {
F_172 ( log -> V_152 , V_277 ,
L_97 , V_115 ) ;
log -> V_25 |= V_369 ;
}
if ( V_8 > F_103 ( V_368 ) &&
! ( log -> V_25 & V_369 ) ) {
F_172 ( log -> V_152 , V_277 ,
L_98 , V_115 ) ;
log -> V_25 |= V_369 ;
}
}
}
STATIC void
F_195 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_6 V_143 )
{
int V_370 ;
if ( F_211 ( V_143 ) == log -> V_347 ) {
V_370 =
log -> V_189 - ( log -> V_190 - F_156 ( V_143 ) ) ;
if ( V_370 < F_124 ( V_59 -> V_97 ) + F_124 ( log -> V_171 ) )
F_210 ( log -> V_152 , L_99 , V_115 ) ;
} else {
ASSERT ( F_211 ( V_143 ) + 1 == log -> V_347 ) ;
if ( F_156 ( V_143 ) == log -> V_190 )
F_210 ( log -> V_152 , L_100 , V_115 ) ;
V_370 = F_156 ( V_143 ) - log -> V_190 ;
if ( V_370 < F_124 ( V_59 -> V_97 ) + 1 )
F_210 ( log -> V_152 , L_99 , V_115 ) ;
}
}
STATIC void
F_164 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_251 ,
bool V_371 )
{
V_272 * V_372 ;
T_11 * V_373 ;
T_17 * V_239 ;
void * V_374 , * V_314 , * V_375 ;
T_20 V_376 ;
T_5 V_377 ;
int V_30 , V_185 , V_233 , V_234 , V_378 ;
int V_379 ;
F_12 ( & log -> V_116 ) ;
V_373 = log -> V_96 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ , V_373 = V_373 -> V_98 )
ASSERT ( V_373 ) ;
if ( V_373 != log -> V_96 )
F_210 ( log -> V_152 , L_101 , V_115 ) ;
F_15 ( & log -> V_116 ) ;
if ( V_59 -> V_208 . V_209 != F_128 ( V_210 ) )
F_210 ( log -> V_152 , L_102 , V_115 ) ;
V_374 = V_314 = & V_59 -> V_208 ;
V_375 = & V_59 -> V_208 ;
for ( V_314 += V_175 ; V_314 < V_374 + V_251 ; V_314 += V_175 ) {
if ( * ( T_16 * ) V_314 == F_128 ( V_210 ) )
F_210 ( log -> V_152 , L_103 ,
V_115 ) ;
}
V_30 = F_160 ( V_59 -> V_208 . V_270 ) ;
V_374 = V_314 = V_59 -> V_221 ;
V_372 = V_314 ;
V_239 = V_59 -> V_205 ;
for ( V_185 = 0 ; V_185 < V_30 ; V_185 ++ ) {
V_372 = V_314 ;
V_375 = & V_372 -> V_288 ;
V_376 = V_375 - V_374 ;
if ( ! V_371 || ( V_376 & 0x1ff ) ) {
V_377 = V_372 -> V_288 ;
} else {
V_379 = F_135 ( ( char * ) & V_372 -> V_288 - V_59 -> V_221 ) ;
if ( V_379 >= ( V_170 / V_175 ) ) {
V_233 = V_379 / ( V_170 / V_175 ) ;
V_234 = V_379 % ( V_170 / V_175 ) ;
V_377 = F_212 (
V_239 [ V_233 ] . V_240 . V_241 [ V_234 ] ) ;
} else {
V_377 = F_212 (
V_59 -> V_208 . V_238 [ V_379 ] ) ;
}
}
if ( V_377 != V_50 && V_377 != V_51 )
F_55 ( log -> V_152 ,
L_104 ,
V_115 , V_377 , V_372 ,
( unsigned long ) V_376 ) ;
V_375 = & V_372 -> V_290 ;
V_376 = V_375 - V_374 ;
if ( ! V_371 || ( V_376 & 0x1ff ) ) {
V_378 = F_160 ( V_372 -> V_290 ) ;
} else {
V_379 = F_135 ( ( V_380 ) & V_372 -> V_290 -
( V_380 ) V_59 -> V_221 ) ;
if ( V_379 >= ( V_170 / V_175 ) ) {
V_233 = V_379 / ( V_170 / V_175 ) ;
V_234 = V_379 % ( V_170 / V_175 ) ;
V_378 = F_160 ( V_239 [ V_233 ] . V_240 . V_241 [ V_234 ] ) ;
} else {
V_378 = F_160 ( V_59 -> V_208 . V_238 [ V_379 ] ) ;
}
}
V_314 += sizeof( V_272 ) + V_378 ;
}
}
STATIC int
F_213 (
struct V_1 * log )
{
T_11 * V_59 , * V_381 ;
V_59 = log -> V_96 ;
if ( ! ( V_59 -> V_66 & V_67 ) ) {
V_381 = V_59 ;
do {
V_381 -> V_66 = V_67 ;
V_381 = V_381 -> V_98 ;
} while ( V_381 != V_59 );
return 0 ;
}
return 1 ;
}
int
F_214 (
struct V_36 * V_37 ,
int V_382 )
{
struct V_1 * log ;
int V_383 ;
log = V_37 -> V_38 ;
if ( ! log ||
log -> V_25 & V_26 ) {
V_37 -> V_77 |= V_384 ;
if ( V_37 -> V_122 )
F_215 ( V_37 -> V_122 ) ;
return 0 ;
}
if ( V_382 && log -> V_96 -> V_66 & V_67 ) {
ASSERT ( F_26 ( log ) ) ;
return 1 ;
}
if ( ! V_382 )
F_73 ( V_37 , V_95 , NULL ) ;
F_12 ( & log -> V_116 ) ;
V_37 -> V_77 |= V_384 ;
if ( V_37 -> V_122 )
F_215 ( V_37 -> V_122 ) ;
log -> V_25 |= V_385 ;
V_383 = F_213 ( log ) ;
F_15 ( & log -> V_116 ) ;
F_11 ( & log -> V_56 ) ;
F_11 ( & log -> V_18 ) ;
F_184 ( & log -> V_386 -> V_387 ) ;
F_183 ( log , V_161 , NULL ) ;
#ifdef F_216
{
T_11 * V_59 ;
F_12 ( & log -> V_116 ) ;
V_59 = log -> V_96 ;
do {
ASSERT ( V_59 -> V_220 == 0 ) ;
V_59 = V_59 -> V_98 ;
} while ( V_59 != log -> V_96 );
F_15 ( & log -> V_116 ) ;
}
#endif
return V_383 ;
}
STATIC int
F_94 (
struct V_1 * log )
{
T_11 * V_59 ;
V_59 = log -> V_96 ;
do {
if ( V_59 -> V_208 . V_270 )
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
bool V_388 ;
if ( V_37 -> V_77 & V_78 )
return true ;
if ( V_61 == V_355 )
return true ;
V_388 = F_218 ( V_37 -> V_38 , V_61 ) ;
if ( ! V_388 ) {
F_12 ( & log -> V_116 ) ;
F_55 ( V_37 ,
L_105
L_106 ,
F_211 ( V_61 ) , F_156 ( V_61 ) ,
log -> V_191 , log -> V_342 ) ;
F_15 ( & log -> V_116 ) ;
}
return V_388 ;
}
