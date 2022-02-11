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
int V_24 )
{
F_20 ( & V_16 -> V_25 , & V_2 -> V_13 ) ;
do {
if ( F_21 ( log ) )
goto V_26;
F_22 ( log , V_24 ) ;
F_23 ( V_27 ) ;
F_15 ( & V_2 -> V_14 ) ;
F_24 ( V_28 ) ;
F_25 ( log , V_16 ) ;
F_26 () ;
F_27 ( log , V_16 ) ;
F_12 ( & V_2 -> V_14 ) ;
if ( F_21 ( log ) )
goto V_26;
} while ( F_28 ( log , & V_2 -> V_12 ) < V_24 );
F_29 ( & V_16 -> V_25 ) ;
return 0 ;
V_26:
F_29 ( & V_16 -> V_25 ) ;
return F_30 ( V_29 ) ;
}
STATIC int
F_31 (
struct V_1 * log ,
struct V_11 * V_2 ,
struct V_15 * V_16 ,
int * V_24 )
{
int V_23 ;
int error = 0 ;
ASSERT ( ! ( log -> V_30 & V_31 ) ) ;
* V_24 = F_16 ( log , V_2 , V_16 ) ;
V_23 = F_28 ( log , & V_2 -> V_12 ) ;
if ( ! F_32 ( & V_2 -> V_13 ) ) {
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
F_33 ( T_3 * V_16 )
{
V_16 -> V_32 = 0 ;
V_16 -> V_33 = 0 ;
V_16 -> V_34 = 0 ;
}
static void
F_34 ( T_3 * V_16 , T_4 V_35 , T_4 type )
{
if ( V_16 -> V_32 == V_36 ) {
V_16 -> V_37 += V_16 -> V_33 ;
V_16 -> V_32 = 0 ;
V_16 -> V_33 = 0 ;
}
V_16 -> V_38 [ V_16 -> V_32 ] . V_39 = V_35 ;
V_16 -> V_38 [ V_16 -> V_32 ] . V_40 = type ;
V_16 -> V_33 += V_35 ;
V_16 -> V_32 ++ ;
}
int
F_35 (
struct V_41 * V_42 ,
struct V_15 * V_16 )
{
struct V_1 * log = V_42 -> V_43 ;
int V_24 ;
int error = 0 ;
if ( F_21 ( log ) )
return F_30 ( V_29 ) ;
F_24 ( V_44 ) ;
V_16 -> V_45 ++ ;
F_22 ( log , V_16 -> V_21 ) ;
V_16 -> V_46 = V_16 -> V_21 ;
F_33 ( V_16 ) ;
if ( V_16 -> V_22 > 0 )
return 0 ;
F_36 ( log , V_16 ) ;
error = F_31 ( log , & log -> V_18 , V_16 ,
& V_24 ) ;
if ( error )
goto V_47;
F_6 ( log , & log -> V_18 . V_12 , V_24 ) ;
F_37 ( log , V_16 ) ;
F_38 ( log ) ;
return 0 ;
V_47:
V_16 -> V_46 = 0 ;
V_16 -> V_22 = 0 ;
return error ;
}
int
F_39 (
struct V_41 * V_42 ,
int V_48 ,
int V_49 ,
struct V_15 * * V_50 ,
T_5 V_51 ,
bool V_52 ,
T_4 V_53 )
{
struct V_1 * log = V_42 -> V_43 ;
struct V_15 * V_16 ;
int V_24 ;
int error = 0 ;
ASSERT ( V_51 == V_54 || V_51 == V_55 ) ;
if ( F_21 ( log ) )
return F_30 ( V_29 ) ;
F_24 ( V_44 ) ;
ASSERT ( * V_50 == NULL ) ;
V_16 = F_40 ( log , V_48 , V_49 , V_51 , V_52 ,
V_56 | V_57 ) ;
if ( ! V_16 )
return F_30 ( V_58 ) ;
V_16 -> V_59 = V_53 ;
* V_50 = V_16 ;
F_22 ( log , V_16 -> V_21 * V_16 -> V_22 ) ;
F_41 ( log , V_16 ) ;
error = F_31 ( log , & log -> V_60 , V_16 ,
& V_24 ) ;
if ( error )
goto V_47;
F_6 ( log , & log -> V_60 . V_12 , V_24 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_24 ) ;
F_42 ( log , V_16 ) ;
F_38 ( log ) ;
return 0 ;
V_47:
V_16 -> V_46 = 0 ;
V_16 -> V_22 = 0 ;
return error ;
}
T_6
F_43 (
struct V_41 * V_42 ,
struct V_15 * V_61 ,
struct V_62 * * V_63 ,
T_4 V_64 )
{
struct V_1 * log = V_42 -> V_43 ;
T_6 V_65 = 0 ;
if ( F_21 ( log ) ||
( ( ( V_61 -> V_19 & V_66 ) == 0 ) &&
( F_44 ( log , V_61 , V_63 , & V_65 ) ) ) ) {
V_65 = ( T_6 ) - 1 ;
if ( V_61 -> V_19 & V_20 ) {
V_64 |= V_67 ;
}
}
if ( ( V_61 -> V_19 & V_20 ) == 0 ||
( V_64 & V_67 ) ) {
F_45 ( log , V_61 ) ;
F_46 ( log , V_61 ) ;
F_47 ( V_61 ) ;
} else {
F_48 ( log , V_61 ) ;
F_49 ( log , V_61 ) ;
V_61 -> V_19 |= V_66 ;
}
return V_65 ;
}
int
F_50 (
struct V_41 * V_42 ,
struct V_62 * V_63 ,
T_7 * V_68 )
{
int V_69 ;
F_12 ( & V_63 -> V_70 ) ;
V_69 = ( V_63 -> V_71 & V_72 ) ;
if ( ! V_69 ) {
F_51 ( ( V_63 -> V_71 == V_73 ) ||
( V_63 -> V_71 == V_74 ) ) ;
V_68 -> V_75 = NULL ;
* ( V_63 -> V_76 ) = V_68 ;
V_63 -> V_76 = & ( V_68 -> V_75 ) ;
}
F_15 ( & V_63 -> V_70 ) ;
return V_69 ;
}
int
F_52 (
struct V_41 * V_42 ,
struct V_62 * V_63 )
{
if ( F_53 ( V_42 -> V_43 , V_63 ) ) {
F_54 ( V_42 , V_77 ) ;
return V_29 ;
}
return 0 ;
}
int
F_55 (
T_8 * V_42 ,
T_9 * V_78 ,
T_10 V_79 ,
int V_80 )
{
int error ;
if ( ! ( V_42 -> V_81 & V_82 ) )
F_56 ( V_42 , L_1 ) ;
else {
F_56 ( V_42 ,
L_2 ) ;
ASSERT ( V_42 -> V_81 & V_83 ) ;
}
V_42 -> V_43 = F_57 ( V_42 , V_78 , V_79 , V_80 ) ;
if ( F_58 ( V_42 -> V_43 ) ) {
error = - F_59 ( V_42 -> V_43 ) ;
goto V_84;
}
error = F_60 ( V_42 ) ;
if ( error ) {
F_61 ( V_42 , L_3 , error ) ;
goto V_85;
}
V_42 -> V_43 -> V_86 = V_42 -> V_87 ;
if ( ! ( V_42 -> V_81 & V_82 ) ) {
int V_88 = ( V_42 -> V_81 & V_83 ) ;
if ( V_88 )
V_42 -> V_81 &= ~ V_83 ;
error = F_62 ( V_42 -> V_43 ) ;
if ( V_88 )
V_42 -> V_81 |= V_83 ;
if ( error ) {
F_61 ( V_42 , L_4 ,
error ) ;
goto V_89;
}
}
V_42 -> V_43 -> V_30 &= ~ V_31 ;
F_63 ( V_42 -> V_43 ) ;
return 0 ;
V_89:
F_64 ( V_42 ) ;
V_85:
F_65 ( V_42 -> V_43 ) ;
V_84:
return error ;
}
int
F_66 ( T_8 * V_42 )
{
int error ;
if ( ! ( V_42 -> V_81 & V_82 ) )
error = F_67 ( V_42 -> V_43 ) ;
else {
error = 0 ;
ASSERT ( V_42 -> V_81 & V_83 ) ;
}
return error ;
}
int
F_68 ( T_8 * V_42 )
{
T_11 * log = V_42 -> V_43 ;
T_12 * V_63 ;
#ifdef F_69
T_12 * V_90 ;
#endif
T_3 * V_16 = NULL ;
T_6 V_65 ;
int error ;
if ( V_42 -> V_81 & V_83 )
return 0 ;
error = F_70 ( V_42 , V_91 , NULL ) ;
ASSERT ( error || ! ( F_21 ( log ) ) ) ;
#ifdef F_69
V_90 = V_63 = log -> V_92 ;
do {
if ( ! ( V_63 -> V_71 & V_72 ) ) {
ASSERT ( V_63 -> V_71 & V_73 ) ;
ASSERT ( V_63 -> V_93 == 0 ) ;
}
V_63 = V_63 -> V_94 ;
} while ( V_63 != V_90 );
#endif
if ( ! ( F_21 ( log ) ) ) {
error = F_39 ( V_42 , 600 , 1 , & V_16 ,
V_55 , 0 , V_95 ) ;
if ( ! error ) {
struct {
T_13 V_96 ;
T_13 V_97 ;
T_14 V_98 ;
} V_96 = {
. V_96 = V_99 ,
} ;
struct V_100 V_101 = {
. V_102 = & V_96 ,
. V_103 = sizeof( V_96 ) ,
. V_104 = V_105 ,
} ;
struct V_106 V_107 = {
. V_108 = 1 ,
. V_109 = & V_101 ,
} ;
V_16 -> V_19 = 0 ;
V_16 -> V_46 -= sizeof( V_96 ) ;
error = F_71 ( log , & V_107 , V_16 , & V_65 ,
NULL , V_110 ) ;
}
if ( error )
F_72 ( V_42 , L_5 , V_111 ) ;
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
F_73 ( & V_63 -> V_113 ) ;
F_74 ( log , V_63 ) ;
F_15 ( & log -> V_112 ) ;
error = F_53 ( log , V_63 ) ;
F_12 ( & log -> V_112 ) ;
if ( ! ( V_63 -> V_71 == V_73 ||
V_63 -> V_71 == V_114 ) ) {
if ( ! F_21 ( log ) ) {
F_75 ( & V_63 -> V_115 ,
& log -> V_112 ) ;
} else {
F_15 ( & log -> V_112 ) ;
}
} else {
F_15 ( & log -> V_112 ) ;
}
if ( V_16 ) {
F_76 ( log , V_16 ) ;
F_46 ( log , V_16 ) ;
F_47 ( V_16 ) ;
}
} else {
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
F_73 ( & V_63 -> V_113 ) ;
F_74 ( log , V_63 ) ;
F_15 ( & log -> V_112 ) ;
error = F_53 ( log , V_63 ) ;
F_12 ( & log -> V_112 ) ;
if ( ! ( V_63 -> V_71 == V_73
|| V_63 -> V_71 == V_114
|| V_63 -> V_71 == V_72 ) ) {
F_75 ( & V_63 -> V_115 ,
& log -> V_112 ) ;
} else {
F_15 ( & log -> V_112 ) ;
}
}
return error ;
}
void
F_77 ( T_8 * V_42 )
{
F_78 ( & V_42 -> V_116 ) ;
F_64 ( V_42 ) ;
F_65 ( V_42 -> V_43 ) ;
}
void
F_79 (
struct V_41 * V_42 ,
struct V_117 * V_118 ,
int type ,
const struct V_119 * V_120 )
{
V_118 -> V_121 = V_42 ;
V_118 -> V_122 = V_42 -> V_87 ;
V_118 -> V_123 = type ;
V_118 -> V_124 = V_120 ;
V_118 -> V_125 = NULL ;
F_9 ( & V_118 -> V_126 ) ;
F_9 ( & V_118 -> V_127 ) ;
}
void
F_80 (
struct V_41 * V_42 )
{
struct V_1 * log = V_42 -> V_43 ;
int V_23 ;
if ( F_21 ( log ) )
return;
if ( ! F_32 ( & log -> V_18 . V_13 ) ) {
ASSERT ( ! ( log -> V_30 & V_31 ) ) ;
F_12 ( & log -> V_18 . V_14 ) ;
V_23 = F_28 ( log , & log -> V_18 . V_12 ) ;
F_17 ( log , & log -> V_18 , & V_23 ) ;
F_15 ( & log -> V_18 . V_14 ) ;
}
if ( ! F_32 ( & log -> V_60 . V_13 ) ) {
ASSERT ( ! ( log -> V_30 & V_31 ) ) ;
F_12 ( & log -> V_60 . V_14 ) ;
V_23 = F_28 ( log , & log -> V_60 . V_12 ) ;
F_17 ( log , & log -> V_60 , & V_23 ) ;
F_15 ( & log -> V_60 . V_14 ) ;
}
}
int
F_81 ( T_8 * V_42 )
{
int V_128 = 0 ;
T_11 * log = V_42 -> V_43 ;
if ( ! F_82 ( V_42 ) )
return 0 ;
F_12 ( & log -> V_112 ) ;
switch ( log -> V_129 ) {
case V_130 :
case V_131 :
case V_132 :
break;
case V_133 :
case V_134 :
if ( ! F_83 ( log -> V_86 ) &&
F_84 ( log ) ) {
if ( log -> V_129 == V_133 )
log -> V_129 = V_130 ;
else
log -> V_129 = V_131 ;
}
default:
V_128 = 1 ;
break;
}
F_15 ( & log -> V_112 ) ;
return V_128 ;
}
T_6
F_85 (
struct V_41 * V_42 )
{
struct V_1 * log = V_42 -> V_43 ;
struct V_117 * V_135 ;
T_6 V_136 ;
F_86 ( & V_42 -> V_87 -> V_137 ) ;
V_135 = F_87 ( V_42 -> V_87 ) ;
if ( V_135 )
V_136 = V_135 -> V_138 ;
else
V_136 = F_2 ( & log -> V_139 ) ;
F_88 ( & log -> V_140 , V_136 ) ;
return V_136 ;
}
T_6
F_89 (
struct V_41 * V_42 )
{
T_6 V_136 ;
F_12 ( & V_42 -> V_87 -> V_137 ) ;
V_136 = F_85 ( V_42 ) ;
F_15 ( & V_42 -> V_87 -> V_137 ) ;
return V_136 ;
}
STATIC int
F_28 (
struct V_1 * log ,
T_1 * V_2 )
{
int V_23 ;
int V_141 ;
int V_142 ;
int V_143 ;
int V_144 ;
F_90 ( V_2 , & V_143 , & V_144 ) ;
F_91 ( & log -> V_140 , & V_142 , & V_141 ) ;
V_141 = F_92 ( V_141 ) ;
if ( V_142 == V_143 && V_144 >= V_141 )
V_23 = log -> V_9 - ( V_144 - V_141 ) ;
else if ( V_142 + 1 < V_143 )
return 0 ;
else if ( V_142 < V_143 ) {
ASSERT ( V_142 == ( V_143 - 1 ) ) ;
V_23 = V_141 - V_144 ;
} else {
F_72 ( log -> V_145 ,
L_6
L_7
L_8 ,
V_142 , V_141 , V_143 , V_144 ) ;
ASSERT ( 0 ) ;
V_23 = log -> V_9 ;
}
return V_23 ;
}
void
F_93 ( T_15 * V_146 )
{
T_12 * V_63 = V_146 -> V_147 ;
T_11 * V_148 = V_63 -> V_149 ;
int V_150 = 0 ;
if ( F_94 ( ( F_95 ( V_146 ) ) , V_148 -> V_145 ,
V_151 , V_152 ) ) {
F_96 ( V_146 , V_111 ) ;
F_97 ( V_146 ) ;
F_54 ( V_148 -> V_145 , V_77 ) ;
V_150 = V_153 ;
} else if ( V_63 -> V_71 & V_72 ) {
V_150 = V_153 ;
}
ASSERT ( F_98 ( V_146 ) ) ;
F_99 ( V_63 , V_150 ) ;
}
STATIC void
F_100 ( T_8 * V_42 ,
T_11 * log )
{
int V_154 ;
int V_155 ;
if ( V_42 -> V_156 <= 0 )
log -> V_157 = V_158 ;
else
log -> V_157 = V_42 -> V_156 ;
if ( V_42 -> V_159 > 0 ) {
V_154 = log -> V_160 = V_42 -> V_159 ;
log -> V_161 = 0 ;
while ( V_154 != 1 ) {
log -> V_161 ++ ;
V_154 >>= 1 ;
}
if ( F_101 ( & V_42 -> V_162 ) ) {
V_155 = V_42 -> V_159 / V_163 ;
if ( V_42 -> V_159 % V_163 )
V_155 ++ ;
log -> V_164 = V_155 << V_165 ;
log -> V_166 = V_155 ;
} else {
ASSERT ( V_42 -> V_159 <= V_167 ) ;
log -> V_164 = V_168 ;
log -> V_166 = 1 ;
}
goto V_169;
}
log -> V_160 = V_167 ;
log -> V_161 = V_170 ;
log -> V_164 = V_168 ;
log -> V_166 = 1 ;
V_169:
if ( V_42 -> V_156 == 0 )
V_42 -> V_156 = log -> V_157 ;
if ( V_42 -> V_159 == 0 )
V_42 -> V_159 = log -> V_160 ;
}
STATIC T_11 *
F_57 ( T_8 * V_42 ,
T_9 * V_78 ,
T_10 V_79 ,
int V_80 )
{
T_11 * log ;
T_16 * V_2 ;
T_12 * * V_171 ;
T_12 * V_63 , * V_172 = NULL ;
T_15 * V_146 ;
int V_173 ;
int error = V_58 ;
T_4 V_174 = 0 ;
log = F_102 ( sizeof( T_11 ) , V_57 ) ;
if ( ! log ) {
F_61 ( V_42 , L_9 ) ;
goto V_84;
}
log -> V_145 = V_42 ;
log -> V_175 = V_78 ;
log -> V_9 = F_92 ( V_80 ) ;
log -> V_176 = V_79 ;
log -> V_177 = V_80 ;
log -> V_129 = V_132 ;
log -> V_30 |= V_31 ;
log -> V_178 = - 1 ;
F_103 ( & log -> V_140 , 1 , 0 ) ;
F_103 ( & log -> V_139 , 1 , 0 ) ;
log -> V_179 = 1 ;
F_7 ( & log -> V_60 ) ;
F_7 ( & log -> V_18 ) ;
error = V_180 ;
if ( F_104 ( & V_42 -> V_162 ) ) {
V_174 = V_42 -> V_162 . V_181 ;
if ( V_174 < V_165 ) {
F_61 ( V_42 , L_10 ,
V_174 , V_165 ) ;
goto V_85;
}
V_174 -= V_165 ;
if ( V_174 > V_42 -> V_182 ) {
F_61 ( V_42 , L_11 ,
V_174 , V_42 -> V_182 ) ;
goto V_85;
}
if ( V_174 && log -> V_176 > 0 &&
! F_101 ( & V_42 -> V_162 ) ) {
F_61 ( V_42 ,
L_12 ,
V_174 ) ;
goto V_85;
}
}
log -> V_183 = 1 << V_174 ;
F_100 ( V_42 , log ) ;
error = V_58 ;
V_146 = F_105 ( V_42 -> V_184 , 0 , F_106 ( log -> V_160 ) , 0 ) ;
if ( ! V_146 )
goto V_85;
V_146 -> V_185 = F_93 ;
ASSERT ( F_107 ( V_146 ) ) ;
log -> V_186 = V_146 ;
F_10 ( & log -> V_112 ) ;
F_108 ( & log -> V_187 ) ;
V_171 = & log -> V_92 ;
ASSERT ( log -> V_160 >= 4096 ) ;
for ( V_173 = 0 ; V_173 < log -> V_157 ; V_173 ++ ) {
* V_171 = F_102 ( sizeof( T_12 ) , V_57 ) ;
if ( ! * V_171 )
goto V_188;
V_63 = * V_171 ;
V_63 -> V_189 = V_172 ;
V_172 = V_63 ;
V_146 = F_109 ( V_42 -> V_184 ,
F_106 ( log -> V_160 ) , 0 ) ;
if ( ! V_146 )
goto V_188;
V_146 -> V_185 = F_93 ;
V_63 -> V_190 = V_146 ;
V_63 -> V_191 = V_146 -> V_192 ;
#ifdef F_69
log -> V_193 [ V_173 ] = ( V_194 ) & ( V_63 -> V_195 ) ;
#endif
V_2 = & V_63 -> V_195 ;
memset ( V_2 , 0 , sizeof( T_16 ) ) ;
V_2 -> V_196 = F_110 ( V_197 ) ;
V_2 -> V_198 = F_110 (
F_101 ( & log -> V_145 -> V_162 ) ? 2 : 1 ) ;
V_2 -> V_199 = F_110 ( log -> V_160 ) ;
V_2 -> V_200 = F_110 ( V_201 ) ;
memcpy ( & V_2 -> V_202 , & V_42 -> V_162 . V_203 , sizeof( V_204 ) ) ;
V_63 -> V_205 = F_92 ( V_146 -> V_206 ) - log -> V_164 ;
V_63 -> V_71 = V_73 ;
V_63 -> V_149 = log ;
F_111 ( & V_63 -> V_113 , 0 ) ;
F_10 ( & V_63 -> V_70 ) ;
V_63 -> V_76 = & ( V_63 -> V_207 ) ;
V_63 -> V_208 = ( char * ) V_63 -> V_191 + log -> V_164 ;
ASSERT ( F_107 ( V_63 -> V_190 ) ) ;
F_108 ( & V_63 -> V_115 ) ;
F_108 ( & V_63 -> V_209 ) ;
V_171 = & V_63 -> V_94 ;
}
* V_171 = log -> V_92 ;
log -> V_92 -> V_189 = V_172 ;
error = F_112 ( log ) ;
if ( error )
goto V_188;
return log ;
V_188:
for ( V_63 = log -> V_92 ; V_63 ; V_63 = V_172 ) {
V_172 = V_63 -> V_94 ;
if ( V_63 -> V_190 )
F_113 ( V_63 -> V_190 ) ;
F_114 ( V_63 ) ;
}
F_115 ( & log -> V_112 ) ;
F_113 ( log -> V_186 ) ;
V_85:
F_114 ( log ) ;
V_84:
return F_116 ( - error ) ;
}
STATIC int
F_44 (
struct V_1 * log ,
struct V_15 * V_61 ,
struct V_62 * * V_63 ,
T_6 * V_210 )
{
struct V_41 * V_42 = log -> V_145 ;
int error ;
struct V_100 V_101 = {
. V_102 = NULL ,
. V_103 = 0 ,
. V_104 = V_211 ,
} ;
struct V_106 V_107 = {
. V_108 = 1 ,
. V_109 = & V_101 ,
} ;
F_51 ( V_63 ) ;
error = F_71 ( log , & V_107 , V_61 , V_210 , V_63 ,
V_212 ) ;
if ( error )
F_54 ( V_42 , V_77 ) ;
return error ;
}
STATIC void
F_22 (
struct V_1 * log ,
int V_24 )
{
T_6 V_213 = 0 ;
T_6 V_214 ;
int V_215 ;
int V_23 ;
int V_216 ;
int V_217 ;
int V_218 ;
ASSERT ( F_106 ( V_24 ) < log -> V_177 ) ;
V_23 = F_28 ( log , & log -> V_60 . V_12 ) ;
V_215 = F_117 ( V_23 ) ;
V_218 = F_106 ( V_24 ) ;
V_218 = F_118 ( V_218 , ( log -> V_177 >> 2 ) ) ;
V_218 = F_118 ( V_218 , 256 ) ;
if ( V_215 >= V_218 )
return;
F_91 ( & log -> V_140 , & V_217 ,
& V_216 ) ;
V_216 += V_218 ;
if ( V_216 >= log -> V_177 ) {
V_216 -= log -> V_177 ;
V_217 += 1 ;
}
V_213 = F_119 ( V_217 ,
V_216 ) ;
V_214 = F_2 ( & log -> V_139 ) ;
if ( F_120 ( V_213 , V_214 ) > 0 )
V_213 = V_214 ;
if ( ! F_21 ( log ) )
F_121 ( log -> V_86 , V_213 ) ;
}
STATIC int
F_122 (
struct V_219 * V_146 )
{
struct V_62 * V_63 = V_146 -> V_147 ;
if ( V_63 -> V_71 & V_72 ) {
F_123 ( V_146 , V_29 ) ;
F_97 ( V_146 ) ;
F_124 ( V_146 , 0 ) ;
return 0 ;
}
F_125 ( V_146 ) ;
return 0 ;
}
STATIC int
F_126 ( T_11 * log ,
T_12 * V_63 )
{
V_194 V_220 ;
T_15 * V_146 ;
int V_173 ;
T_4 V_221 ;
T_4 V_222 ;
int V_223 ;
int V_224 = 0 ;
int error ;
int V_225 = F_101 ( & log -> V_145 -> V_162 ) ;
F_24 ( V_226 ) ;
ASSERT ( F_127 ( & V_63 -> V_113 ) == 0 ) ;
V_222 = log -> V_164 + V_63 -> V_93 ;
if ( V_225 && log -> V_145 -> V_162 . V_227 > 1 ) {
V_221 = F_128 ( log , F_129 ( log , V_222 ) ) ;
} else {
V_221 = F_92 ( F_106 ( V_222 ) ) ;
}
V_223 = V_221 - V_222 ;
ASSERT ( V_223 >= 0 ) ;
ASSERT ( ( V_225 && log -> V_145 -> V_162 . V_227 > 1 &&
V_223 < log -> V_145 -> V_162 . V_227 )
||
( log -> V_145 -> V_162 . V_227 <= 1 &&
V_223 < F_92 ( 1 ) ) ) ;
F_6 ( log , & log -> V_60 . V_12 , V_223 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_223 ) ;
F_130 ( log , V_63 , V_223 ) ;
if ( V_225 ) {
V_63 -> V_195 . V_228 =
F_110 ( V_63 -> V_93 + V_223 ) ;
} else {
V_63 -> V_195 . V_228 =
F_110 ( V_63 -> V_93 ) ;
}
V_146 = V_63 -> V_190 ;
F_131 ( V_146 , F_132 ( F_133 ( V_63 -> V_195 . V_229 ) ) ) ;
F_134 ( V_230 , F_106 ( V_221 ) ) ;
if ( F_135 ( V_146 ) + F_106 ( V_221 ) > log -> V_177 ) {
V_224 = V_221 - ( F_92 ( log -> V_177 - F_135 ( V_146 ) ) ) ;
V_221 = F_92 ( log -> V_177 - F_135 ( V_146 ) ) ;
V_63 -> V_231 = 2 ;
} else {
V_63 -> V_231 = 1 ;
}
V_146 -> V_232 = F_106 ( V_221 ) ;
V_146 -> V_147 = V_63 ;
F_136 ( V_146 ) ;
F_137 ( V_146 ) ;
V_146 -> V_233 |= V_234 ;
if ( log -> V_145 -> V_81 & V_235 ) {
V_146 -> V_233 |= V_236 ;
if ( log -> V_145 -> V_184 != log -> V_145 -> V_237 )
F_138 ( log -> V_145 -> V_237 ) ;
else
V_146 -> V_233 |= V_238 ;
}
ASSERT ( F_135 ( V_146 ) <= log -> V_177 - 1 ) ;
ASSERT ( F_135 ( V_146 ) + F_106 ( V_221 ) <= log -> V_177 ) ;
F_139 ( log , V_63 , V_221 , V_239 ) ;
F_131 ( V_146 , F_135 ( V_146 ) + log -> V_176 ) ;
F_140 ( V_146 ) ;
error = F_122 ( V_146 ) ;
if ( error ) {
F_96 ( V_146 , L_13 ) ;
return error ;
}
if ( V_224 ) {
V_146 = V_63 -> V_149 -> V_186 ;
F_131 ( V_146 , 0 ) ;
F_141 ( V_146 ,
( char * ) & V_63 -> V_195 + V_221 , V_224 ) ;
V_146 -> V_147 = V_63 ;
F_136 ( V_146 ) ;
F_137 ( V_146 ) ;
V_146 -> V_233 |= V_234 ;
if ( log -> V_145 -> V_81 & V_235 )
V_146 -> V_233 |= V_236 ;
V_220 = V_146 -> V_192 ;
for ( V_173 = 0 ; V_173 < V_224 ; V_173 += V_168 ) {
F_142 ( ( V_240 * ) V_220 , 1 ) ;
if ( F_143 ( * ( V_240 * ) V_220 ) == V_197 )
F_142 ( ( V_240 * ) V_220 , 1 ) ;
V_220 += V_168 ;
}
ASSERT ( F_135 ( V_146 ) <= log -> V_177 - 1 ) ;
ASSERT ( F_135 ( V_146 ) + F_106 ( V_221 ) <= log -> V_177 ) ;
F_131 ( V_146 , F_135 ( V_146 ) + log -> V_176 ) ;
F_140 ( V_146 ) ;
error = F_122 ( V_146 ) ;
if ( error ) {
F_96 ( V_146 , L_14 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_65 ( T_11 * log )
{
T_12 * V_63 , * V_241 ;
int V_173 ;
F_144 ( log ) ;
F_145 ( log -> V_186 , F_106 ( log -> V_160 ) ) ;
F_113 ( log -> V_186 ) ;
V_63 = log -> V_92 ;
for ( V_173 = 0 ; V_173 < log -> V_157 ; V_173 ++ ) {
F_113 ( V_63 -> V_190 ) ;
V_241 = V_63 -> V_94 ;
F_114 ( V_63 ) ;
V_63 = V_241 ;
}
F_115 ( & log -> V_112 ) ;
log -> V_145 -> V_43 = NULL ;
F_114 ( log ) ;
}
static inline void
F_146 ( T_11 * log ,
T_12 * V_63 ,
int V_242 ,
int V_243 )
{
F_12 ( & log -> V_112 ) ;
F_142 ( & V_63 -> V_195 . V_244 , V_242 ) ;
V_63 -> V_93 += V_243 ;
F_15 ( & log -> V_112 ) ;
}
void
F_147 (
struct V_41 * V_42 ,
struct V_15 * V_61 )
{
T_4 V_173 ;
T_4 V_245 = V_61 -> V_34 * ( T_4 ) sizeof( V_246 ) ;
static char * V_247 [ V_248 ] = {
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
static char * V_249 [ V_250 ] = {
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
F_61 ( V_42 ,
L_74
L_75
L_76
L_77
L_78
L_79
L_80
L_81 ,
( ( V_61 -> V_59 <= 0 ||
V_61 -> V_59 > V_250 ) ?
L_82 : V_249 [ V_61 -> V_59 - 1 ] ) ,
V_61 -> V_59 ,
V_61 -> V_21 ,
V_61 -> V_46 ,
V_61 -> V_33 , V_61 -> V_37 ,
V_61 -> V_34 , V_245 ,
V_61 -> V_33 +
V_61 -> V_37 + V_245 ,
V_61 -> V_32 ) ;
for ( V_173 = 0 ; V_173 < V_61 -> V_32 ; V_173 ++ ) {
T_4 V_40 = V_61 -> V_38 [ V_173 ] . V_40 ;
F_61 ( V_42 , L_83 , V_173 ,
( ( V_40 <= 0 || V_40 > V_248 ) ?
L_84 : V_247 [ V_40 - 1 ] ) ,
V_61 -> V_38 [ V_173 ] . V_39 ) ;
}
F_148 ( V_42 , V_251 ,
L_85 ) ;
F_54 ( V_42 , V_252 ) ;
}
static int
F_149 (
struct V_15 * V_61 ,
struct V_106 * V_253 )
{
struct V_106 * V_254 ;
int V_255 = 0 ;
int V_35 = 0 ;
int V_173 ;
if ( V_61 -> V_19 & V_66 )
V_255 ++ ;
for ( V_254 = V_253 ; V_254 ; V_254 = V_254 -> V_256 ) {
V_255 += V_254 -> V_108 ;
for ( V_173 = 0 ; V_173 < V_254 -> V_108 ; V_173 ++ ) {
struct V_100 * V_257 = & V_254 -> V_109 [ V_173 ] ;
V_35 += V_257 -> V_103 ;
F_34 ( V_61 , V_257 -> V_103 , V_257 -> V_104 ) ;
}
}
V_61 -> V_34 += V_255 ;
V_35 += V_255 * sizeof( struct V_258 ) ;
return V_35 ;
}
static int
F_150 (
struct V_258 * V_259 ,
struct V_15 * V_61 )
{
if ( ! ( V_61 -> V_19 & V_66 ) )
return 0 ;
V_259 -> V_260 = F_110 ( V_61 -> V_45 ) ;
V_259 -> V_261 = V_61 -> V_262 ;
V_259 -> V_263 = 0 ;
V_259 -> V_264 = V_265 ;
V_259 -> V_266 = 0 ;
V_61 -> V_19 &= ~ V_66 ;
return sizeof( struct V_258 ) ;
}
static V_246 *
F_151 (
struct V_1 * log ,
struct V_258 * V_259 ,
struct V_15 * V_61 ,
T_4 V_64 )
{
V_259 -> V_260 = F_110 ( V_61 -> V_45 ) ;
V_259 -> V_261 = V_61 -> V_262 ;
V_259 -> V_266 = 0 ;
V_259 -> V_264 = V_64 ;
switch ( V_259 -> V_261 ) {
case V_54 :
case V_267 :
case V_55 :
break;
default:
F_61 ( log -> V_145 ,
L_86 ,
V_259 -> V_261 , V_61 ) ;
return NULL ;
}
return V_259 ;
}
static int
F_152 (
struct V_15 * V_61 ,
struct V_258 * V_259 ,
int V_268 ,
int V_269 ,
int * V_270 ,
int * V_271 ,
int * V_272 ,
int * V_273 )
{
int V_274 ;
V_274 = V_269 - * V_273 ;
* V_270 = * V_273 ;
if ( V_274 <= V_268 ) {
* V_271 = V_274 ;
V_259 -> V_263 = F_110 ( * V_271 ) ;
if ( * V_272 )
V_259 -> V_264 |= ( V_275 | V_276 ) ;
* V_272 = 0 ;
* V_273 = 0 ;
return 0 ;
}
* V_271 = V_268 ;
V_259 -> V_263 = F_110 ( * V_271 ) ;
V_259 -> V_264 |= V_277 ;
if ( * V_272 )
V_259 -> V_264 |= V_276 ;
* V_273 += * V_271 ;
( * V_272 ) ++ ;
V_61 -> V_46 -= sizeof( struct V_258 ) ;
V_61 -> V_34 ++ ;
return sizeof( struct V_258 ) ;
}
static int
F_153 (
struct V_1 * log ,
struct V_62 * V_63 ,
T_4 V_64 ,
int * V_242 ,
int * V_278 ,
int * V_279 ,
int * V_280 ,
int V_281 ,
struct V_62 * * V_282 )
{
if ( * V_279 ) {
F_146 ( log , V_63 , * V_242 , * V_278 ) ;
* V_242 = 0 ;
* V_278 = 0 ;
return F_53 ( log , V_63 ) ;
}
* V_279 = 0 ;
* V_280 = 0 ;
if ( V_63 -> V_205 - V_281 <= sizeof( V_246 ) ) {
F_146 ( log , V_63 , * V_242 , * V_278 ) ;
* V_242 = 0 ;
* V_278 = 0 ;
F_12 ( & log -> V_112 ) ;
F_74 ( log , V_63 ) ;
F_15 ( & log -> V_112 ) ;
if ( ! V_282 )
return F_53 ( log , V_63 ) ;
ASSERT ( V_64 & V_212 ) ;
* V_282 = V_63 ;
}
return 0 ;
}
int
F_71 (
struct V_1 * log ,
struct V_106 * V_253 ,
struct V_15 * V_61 ,
T_6 * V_283 ,
struct V_62 * * V_282 ,
T_4 V_64 )
{
struct V_62 * V_63 = NULL ;
struct V_100 * V_257 ;
struct V_106 * V_254 ;
int V_35 ;
int V_284 ;
int V_279 = 0 ;
int V_280 = 0 ;
int V_285 = 0 ;
int V_242 = 0 ;
int V_278 = 0 ;
int error ;
* V_283 = 0 ;
V_35 = F_149 ( V_61 , V_253 ) ;
if ( V_61 -> V_19 & V_66 )
V_61 -> V_46 -= sizeof( V_246 ) ;
if ( V_64 & ( V_212 | V_110 ) )
V_61 -> V_46 -= sizeof( V_246 ) ;
if ( V_61 -> V_46 < 0 )
F_147 ( log -> V_145 , V_61 ) ;
V_284 = 0 ;
V_254 = V_253 ;
V_257 = V_254 -> V_109 ;
while ( V_254 && V_284 < V_254 -> V_108 ) {
void * V_286 ;
int V_281 ;
error = F_154 ( log , V_35 , & V_63 , V_61 ,
& V_285 , & V_281 ) ;
if ( error )
return error ;
ASSERT ( V_281 <= V_63 -> V_205 - 1 ) ;
V_286 = V_63 -> V_208 + V_281 ;
if ( ! * V_283 )
* V_283 = F_133 ( V_63 -> V_195 . V_229 ) ;
while ( V_254 && V_284 < V_254 -> V_108 ) {
struct V_100 * V_101 = & V_257 [ V_284 ] ;
struct V_258 * V_259 ;
int V_287 ;
int V_271 ;
int V_270 ;
ASSERT ( V_101 -> V_103 % sizeof( V_288 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_286 % sizeof( V_288 ) == 0 ) ;
V_287 = F_150 ( V_286 , V_61 ) ;
if ( V_287 ) {
V_242 ++ ;
F_155 ( & V_286 , & V_35 , & V_281 ,
V_287 ) ;
}
V_259 = F_151 ( log , V_286 , V_61 , V_64 ) ;
if ( ! V_259 )
return F_30 ( V_29 ) ;
F_155 ( & V_286 , & V_35 , & V_281 ,
sizeof( struct V_258 ) ) ;
V_35 += F_152 ( V_61 , V_259 ,
V_63 -> V_205 - V_281 ,
V_101 -> V_103 ,
& V_270 , & V_271 ,
& V_279 ,
& V_280 ) ;
F_156 ( log , V_286 ) ;
ASSERT ( V_271 >= 0 ) ;
memcpy ( V_286 , V_101 -> V_102 + V_270 , V_271 ) ;
F_155 ( & V_286 , & V_35 , & V_281 , V_271 ) ;
V_271 += V_287 + sizeof( V_246 ) ;
V_242 ++ ;
V_278 += V_285 ? V_271 : 0 ;
error = F_153 ( log , V_63 , V_64 ,
& V_242 , & V_278 ,
& V_279 ,
& V_280 ,
V_281 ,
V_282 ) ;
if ( error )
return error ;
if ( V_279 )
break;
if ( ++ V_284 == V_254 -> V_108 ) {
V_254 = V_254 -> V_256 ;
V_284 = 0 ;
if ( V_254 )
V_257 = V_254 -> V_109 ;
}
if ( V_242 == 0 ) {
if ( ! V_254 )
return 0 ;
break;
}
}
}
ASSERT ( V_35 == 0 ) ;
F_146 ( log , V_63 , V_242 , V_278 ) ;
if ( ! V_282 )
return F_53 ( log , V_63 ) ;
ASSERT ( V_64 & V_212 ) ;
* V_282 = V_63 ;
return 0 ;
}
STATIC void
F_157 ( T_11 * log )
{
T_12 * V_63 ;
int V_289 = 0 ;
V_63 = log -> V_92 ;
do {
if ( V_63 -> V_71 == V_114 ) {
V_63 -> V_71 = V_73 ;
V_63 -> V_93 = 0 ;
ASSERT ( V_63 -> V_207 == NULL ) ;
if ( ! V_289 &&
( F_143 ( V_63 -> V_195 . V_244 ) ==
V_290 ) ) {
V_289 = 1 ;
} else {
V_289 = 2 ;
}
V_63 -> V_195 . V_244 = 0 ;
memset ( V_63 -> V_195 . V_291 , 0 ,
sizeof( V_63 -> V_195 . V_291 ) ) ;
V_63 -> V_195 . V_229 = 0 ;
} else if ( V_63 -> V_71 == V_73 )
;
else
break;
V_63 = V_63 -> V_94 ;
} while ( V_63 != log -> V_92 );
if ( V_289 ) {
switch ( log -> V_129 ) {
case V_132 :
case V_133 :
case V_134 :
log -> V_129 = V_133 ;
break;
case V_130 :
if ( V_289 == 1 )
log -> V_129 = V_134 ;
else
log -> V_129 = V_133 ;
break;
case V_131 :
if ( V_289 == 1 )
log -> V_129 = V_132 ;
else
log -> V_129 = V_133 ;
break;
default:
ASSERT ( 0 ) ;
}
}
}
STATIC T_6
F_158 (
T_11 * log )
{
T_12 * V_292 ;
T_6 V_293 , V_65 ;
V_292 = log -> V_92 ;
V_293 = 0 ;
do {
if ( ! ( V_292 -> V_71 & ( V_73 | V_114 ) ) ) {
V_65 = F_133 ( V_292 -> V_195 . V_229 ) ;
if ( ( V_65 && ! V_293 ) ||
( F_120 ( V_65 , V_293 ) < 0 ) ) {
V_293 = V_65 ;
}
}
V_292 = V_292 -> V_94 ;
} while ( V_292 != log -> V_92 );
return V_293 ;
}
STATIC void
F_159 (
T_11 * log ,
int V_150 ,
T_12 * V_294 )
{
T_12 * V_63 ;
T_12 * V_90 ;
T_7 * V_68 , * V_75 ;
int V_295 = 0 ;
T_6 V_293 ;
int V_296 ;
int V_297 ;
int V_298 ;
int V_299 ;
int V_300 = 0 ;
F_12 ( & log -> V_112 ) ;
V_90 = V_63 = log -> V_92 ;
V_296 = 0 ;
V_298 = 0 ;
V_299 = 0 ;
do {
V_90 = log -> V_92 ;
V_63 = log -> V_92 ;
V_297 = 0 ;
V_299 ++ ;
do {
if ( V_63 -> V_71 &
( V_73 | V_114 ) ) {
V_63 = V_63 -> V_94 ;
continue;
}
if ( ! ( V_63 -> V_71 & V_72 ) ) {
if ( ! ( V_63 -> V_71 &
( V_301 |
V_302 ) ) ) {
if ( V_294 && ( V_294 -> V_71 ==
V_301 ) ) {
V_294 -> V_71 = V_302 ;
}
break;
}
V_293 = F_158 ( log ) ;
if ( V_293 &&
F_120 ( V_293 ,
F_133 ( V_63 -> V_195 . V_229 ) ) < 0 ) {
V_63 = V_63 -> V_94 ;
continue;
}
V_63 -> V_71 = V_303 ;
ASSERT ( F_120 ( F_2 ( & log -> V_139 ) ,
F_133 ( V_63 -> V_195 . V_229 ) ) <= 0 ) ;
F_88 ( & log -> V_139 ,
F_133 ( V_63 -> V_195 . V_229 ) ) ;
} else
V_296 ++ ;
F_15 ( & log -> V_112 ) ;
F_12 ( & V_63 -> V_70 ) ;
V_68 = V_63 -> V_207 ;
while ( V_68 ) {
V_63 -> V_76 = & ( V_63 -> V_207 ) ;
V_63 -> V_207 = NULL ;
F_15 ( & V_63 -> V_70 ) ;
for (; V_68 ; V_68 = V_75 ) {
V_75 = V_68 -> V_75 ;
V_68 -> V_304 ( V_68 -> V_305 , V_150 ) ;
}
F_12 ( & V_63 -> V_70 ) ;
V_68 = V_63 -> V_207 ;
}
V_297 ++ ;
V_298 ++ ;
F_12 ( & log -> V_112 ) ;
ASSERT ( V_63 -> V_207 == NULL ) ;
F_15 ( & V_63 -> V_70 ) ;
if ( ! ( V_63 -> V_71 & V_72 ) )
V_63 -> V_71 = V_114 ;
F_157 ( log ) ;
F_160 ( & V_63 -> V_115 ) ;
V_63 = V_63 -> V_94 ;
} while ( V_90 != V_63 );
if ( V_299 > 5000 ) {
V_295 += V_299 ;
V_299 = 0 ;
F_61 ( log -> V_145 ,
L_87 ,
V_111 , V_295 ) ;
}
} while ( ! V_296 && V_297 );
#ifdef F_69
if ( V_298 ) {
V_90 = V_63 = log -> V_92 ;
do {
ASSERT ( V_63 -> V_71 != V_302 ) ;
if ( V_63 -> V_71 == V_74 ||
V_63 -> V_71 == V_306 ||
V_63 -> V_71 == V_301 ||
V_63 -> V_71 == V_72 )
break;
V_63 = V_63 -> V_94 ;
} while ( V_90 != V_63 );
}
#endif
if ( log -> V_92 -> V_71 & ( V_73 | V_72 ) )
V_300 = 1 ;
F_15 ( & log -> V_112 ) ;
if ( V_300 )
F_160 ( & log -> V_187 ) ;
}
STATIC void
F_99 (
T_12 * V_63 ,
int V_150 )
{
T_11 * log = V_63 -> V_149 ;
F_12 ( & log -> V_112 ) ;
ASSERT ( V_63 -> V_71 == V_306 ||
V_63 -> V_71 == V_72 ) ;
ASSERT ( F_127 ( & V_63 -> V_113 ) == 0 ) ;
ASSERT ( V_63 -> V_231 == 1 || V_63 -> V_231 == 2 ) ;
if ( V_63 -> V_71 != V_72 ) {
if ( -- V_63 -> V_231 == 1 ) {
F_15 ( & log -> V_112 ) ;
return;
}
V_63 -> V_71 = V_301 ;
}
F_160 ( & V_63 -> V_209 ) ;
F_15 ( & log -> V_112 ) ;
F_159 ( log , V_150 , V_63 ) ;
}
STATIC int
F_154 ( T_11 * log ,
int V_35 ,
T_12 * * V_171 ,
T_3 * V_61 ,
int * V_307 ,
int * V_308 )
{
int V_281 ;
T_16 * V_2 ;
T_12 * V_63 ;
int error ;
V_309:
F_12 ( & log -> V_112 ) ;
if ( F_21 ( log ) ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
V_63 = log -> V_92 ;
if ( V_63 -> V_71 != V_73 ) {
F_24 ( V_310 ) ;
F_75 ( & log -> V_187 , & log -> V_112 ) ;
goto V_309;
}
V_2 = & V_63 -> V_195 ;
F_73 ( & V_63 -> V_113 ) ;
V_281 = V_63 -> V_93 ;
if ( V_281 == 0 ) {
V_61 -> V_46 -= log -> V_164 ;
F_34 ( V_61 ,
log -> V_164 ,
V_311 ) ;
V_2 -> V_312 = F_110 ( log -> V_179 ) ;
V_2 -> V_229 = F_161 (
F_119 ( log -> V_179 , log -> V_313 ) ) ;
ASSERT ( log -> V_313 >= 0 ) ;
}
if ( V_63 -> V_205 - V_63 -> V_93 < 2 * sizeof( V_246 ) ) {
F_162 ( log , V_63 , V_63 -> V_205 ) ;
if ( ! F_163 ( & V_63 -> V_113 , - 1 , 1 ) ) {
F_15 ( & log -> V_112 ) ;
error = F_53 ( log , V_63 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_112 ) ;
}
goto V_309;
}
if ( V_35 <= V_63 -> V_205 - V_63 -> V_93 ) {
* V_307 = 0 ;
V_63 -> V_93 += V_35 ;
} else {
* V_307 = 1 ;
F_162 ( log , V_63 , V_63 -> V_205 ) ;
}
* V_171 = V_63 ;
ASSERT ( V_63 -> V_93 <= V_63 -> V_205 ) ;
F_15 ( & log -> V_112 ) ;
* V_308 = V_281 ;
return 0 ;
}
STATIC void
F_49 ( T_11 * log ,
T_3 * V_61 )
{
F_164 ( log , V_61 ) ;
if ( V_61 -> V_22 > 0 )
V_61 -> V_22 -- ;
F_1 ( log , & log -> V_60 . V_12 ,
V_61 -> V_46 ) ;
F_1 ( log , & log -> V_18 . V_12 ,
V_61 -> V_46 ) ;
V_61 -> V_46 = V_61 -> V_21 ;
F_33 ( V_61 ) ;
F_165 ( log , V_61 ) ;
if ( V_61 -> V_22 > 0 )
return;
F_6 ( log , & log -> V_60 . V_12 ,
V_61 -> V_21 ) ;
F_166 ( log , V_61 ) ;
V_61 -> V_46 = V_61 -> V_21 ;
F_33 ( V_61 ) ;
}
STATIC void
F_46 ( T_11 * log ,
T_3 * V_61 )
{
int V_3 ;
if ( V_61 -> V_22 > 0 )
V_61 -> V_22 -- ;
F_167 ( log , V_61 ) ;
F_168 ( log , V_61 ) ;
V_3 = V_61 -> V_46 ;
if ( V_61 -> V_22 > 0 ) {
ASSERT ( V_61 -> V_19 & V_20 ) ;
V_3 += V_61 -> V_21 * V_61 -> V_22 ;
}
F_1 ( log , & log -> V_60 . V_12 , V_3 ) ;
F_1 ( log , & log -> V_18 . V_12 , V_3 ) ;
F_169 ( log , V_61 ) ;
F_80 ( log -> V_145 ) ;
}
STATIC int
F_53 (
T_11 * log ,
T_12 * V_63 )
{
int V_314 = 0 ;
if ( V_63 -> V_71 & V_72 )
return F_30 ( V_29 ) ;
ASSERT ( F_127 ( & V_63 -> V_113 ) > 0 ) ;
if ( ! F_170 ( & V_63 -> V_113 , & log -> V_112 ) )
return 0 ;
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
ASSERT ( V_63 -> V_71 == V_73 ||
V_63 -> V_71 == V_74 ) ;
if ( V_63 -> V_71 == V_74 ) {
T_6 V_136 = F_89 ( log -> V_145 ) ;
V_314 ++ ;
V_63 -> V_71 = V_306 ;
V_63 -> V_195 . V_315 = F_161 ( V_136 ) ;
F_171 ( log , V_63 , V_136 ) ;
}
F_15 ( & log -> V_112 ) ;
if ( V_314 )
return F_126 ( log , V_63 ) ;
return 0 ;
}
STATIC void
F_162 ( T_11 * log ,
T_12 * V_63 ,
int V_316 )
{
ASSERT ( V_63 -> V_71 == V_73 ) ;
if ( ! V_316 )
V_316 = V_63 -> V_93 ;
V_63 -> V_71 = V_74 ;
V_63 -> V_195 . V_317 = F_110 ( log -> V_178 ) ;
log -> V_178 = log -> V_313 ;
log -> V_318 = log -> V_179 ;
log -> V_313 += F_106 ( V_316 ) + F_106 ( log -> V_164 ) ;
if ( F_101 ( & log -> V_145 -> V_162 ) &&
log -> V_145 -> V_162 . V_227 > 1 ) {
T_14 V_319 = F_106 ( log -> V_145 -> V_162 . V_227 ) ;
log -> V_313 = F_172 ( log -> V_313 , V_319 ) ;
}
if ( log -> V_313 >= log -> V_177 ) {
log -> V_179 ++ ;
if ( log -> V_179 == V_197 )
log -> V_179 ++ ;
log -> V_313 -= log -> V_177 ;
ASSERT ( log -> V_313 >= 0 ) ;
}
ASSERT ( V_63 == log -> V_92 ) ;
log -> V_92 = V_63 -> V_94 ;
}
int
F_70 (
struct V_41 * V_42 ,
T_4 V_64 ,
int * V_320 )
{
struct V_1 * log = V_42 -> V_43 ;
struct V_62 * V_63 ;
T_6 V_65 ;
F_24 ( V_321 ) ;
F_173 ( log ) ;
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
if ( V_63 -> V_71 == V_73 ||
V_63 -> V_71 == V_114 ) {
if ( V_63 -> V_71 == V_114 ||
( F_127 ( & V_63 -> V_113 ) == 0
&& V_63 -> V_93 == 0 ) ) {
V_63 = V_63 -> V_189 ;
if ( V_63 -> V_71 == V_73 ||
V_63 -> V_71 == V_114 )
goto V_322;
else
goto V_323;
} else {
if ( F_127 ( & V_63 -> V_113 ) == 0 ) {
F_73 ( & V_63 -> V_113 ) ;
V_65 = F_133 ( V_63 -> V_195 . V_229 ) ;
F_162 ( log , V_63 , 0 ) ;
F_15 ( & log -> V_112 ) ;
if ( F_53 ( log , V_63 ) )
return F_30 ( V_29 ) ;
if ( V_320 )
* V_320 = 1 ;
F_12 ( & log -> V_112 ) ;
if ( F_133 ( V_63 -> V_195 . V_229 ) == V_65 &&
V_63 -> V_71 != V_114 )
goto V_323;
else
goto V_322;
} else {
F_162 ( log , V_63 , 0 ) ;
goto V_323;
}
}
}
V_323:
if ( V_64 & V_91 ) {
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
F_24 ( V_324 ) ;
F_75 ( & V_63 -> V_115 , & log -> V_112 ) ;
if ( V_63 -> V_71 & V_72 )
return F_30 ( V_29 ) ;
if ( V_320 )
* V_320 = 1 ;
} else {
V_322:
F_15 ( & log -> V_112 ) ;
}
return 0 ;
}
void
F_174 (
T_8 * V_42 ,
T_4 V_64 )
{
int error ;
F_175 ( V_42 , 0 ) ;
error = F_70 ( V_42 , V_64 , NULL ) ;
if ( error )
F_61 ( V_42 , L_88 , V_111 , error ) ;
}
int
F_176 (
struct V_41 * V_42 ,
T_6 V_65 ,
T_4 V_64 ,
int * V_320 )
{
struct V_1 * log = V_42 -> V_43 ;
struct V_62 * V_63 ;
int V_325 = 0 ;
ASSERT ( V_65 != 0 ) ;
F_24 ( V_321 ) ;
V_65 = F_177 ( log , V_65 ) ;
if ( V_65 == V_326 )
return 0 ;
V_327:
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
do {
if ( F_133 ( V_63 -> V_195 . V_229 ) != V_65 ) {
V_63 = V_63 -> V_94 ;
continue;
}
if ( V_63 -> V_71 == V_114 ) {
F_15 ( & log -> V_112 ) ;
return 0 ;
}
if ( V_63 -> V_71 == V_73 ) {
if ( ! V_325 &&
( V_63 -> V_189 -> V_71 &
( V_74 | V_306 ) ) ) {
ASSERT ( ! ( V_63 -> V_71 & V_72 ) ) ;
F_24 ( V_324 ) ;
F_75 ( & V_63 -> V_189 -> V_209 ,
& log -> V_112 ) ;
if ( V_320 )
* V_320 = 1 ;
V_325 = 1 ;
goto V_327;
}
F_73 ( & V_63 -> V_113 ) ;
F_162 ( log , V_63 , 0 ) ;
F_15 ( & log -> V_112 ) ;
if ( F_53 ( log , V_63 ) )
return F_30 ( V_29 ) ;
if ( V_320 )
* V_320 = 1 ;
F_12 ( & log -> V_112 ) ;
}
if ( ( V_64 & V_91 ) &&
! ( V_63 -> V_71 &
( V_73 | V_114 ) ) ) {
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
F_24 ( V_324 ) ;
F_75 ( & V_63 -> V_115 , & log -> V_112 ) ;
if ( V_63 -> V_71 & V_72 )
return F_30 ( V_29 ) ;
if ( V_320 )
* V_320 = 1 ;
} else {
F_15 ( & log -> V_112 ) ;
}
return 0 ;
} while ( V_63 != log -> V_92 );
F_15 ( & log -> V_112 ) ;
return 0 ;
}
void
F_178 (
T_8 * V_42 ,
T_6 V_65 ,
T_4 V_64 )
{
int error ;
F_175 ( V_42 , V_65 ) ;
error = F_176 ( V_42 , V_65 , V_64 , NULL ) ;
if ( error )
F_61 ( V_42 , L_88 , V_111 , error ) ;
}
STATIC void
F_74 ( T_11 * log , T_12 * V_63 )
{
F_86 ( & log -> V_112 ) ;
if ( V_63 -> V_71 == V_73 ) {
F_162 ( log , V_63 , 0 ) ;
} else {
ASSERT ( V_63 -> V_71 &
( V_74 | V_72 ) ) ;
}
}
void
F_47 (
T_3 * V_61 )
{
ASSERT ( F_127 ( & V_61 -> V_328 ) > 0 ) ;
if ( F_179 ( & V_61 -> V_328 ) )
F_180 ( V_329 , V_61 ) ;
}
T_3 *
F_181 (
T_3 * V_61 )
{
ASSERT ( F_127 ( & V_61 -> V_328 ) > 0 ) ;
F_73 ( & V_61 -> V_328 ) ;
return V_61 ;
}
T_3 *
F_40 (
struct V_1 * log ,
int V_48 ,
int V_49 ,
char V_51 ,
bool V_52 ,
T_17 V_330 )
{
struct V_15 * V_16 ;
T_4 V_331 ;
int V_332 ;
V_16 = F_182 ( V_329 , V_330 ) ;
if ( ! V_16 )
return NULL ;
V_48 += sizeof( V_246 ) ;
V_48 += sizeof( V_333 ) ;
V_48 += sizeof( V_246 ) ;
V_332 = log -> V_160 - log -> V_164 ;
V_331 = F_183 ( V_48 , V_332 ) ;
V_48 += sizeof( V_246 ) * V_331 ;
while ( ! V_331 ||
F_183 ( V_48 , V_332 ) > V_331 ) {
V_48 += sizeof( V_246 ) ;
V_331 ++ ;
}
V_48 += log -> V_164 * V_331 ;
V_48 += log -> V_164 ;
if ( F_101 ( & log -> V_145 -> V_162 ) &&
log -> V_145 -> V_162 . V_227 > 1 ) {
V_48 += 2 * log -> V_145 -> V_162 . V_227 ;
} else {
V_48 += 2 * V_168 ;
}
F_111 ( & V_16 -> V_328 , 1 ) ;
V_16 -> V_17 = V_334 ;
F_9 ( & V_16 -> V_25 ) ;
V_16 -> V_21 = V_48 ;
V_16 -> V_46 = V_48 ;
V_16 -> V_22 = V_49 ;
V_16 -> V_335 = V_49 ;
V_16 -> V_45 = F_184 () ;
V_16 -> V_262 = V_51 ;
V_16 -> V_19 = V_66 ;
V_16 -> V_59 = 0 ;
if ( V_52 )
V_16 -> V_19 |= V_20 ;
F_33 ( V_16 ) ;
return V_16 ;
}
void
F_156 (
struct V_1 * log ,
char * V_286 )
{
int V_173 ;
int V_336 = 0 ;
for ( V_173 = 0 ; V_173 < log -> V_157 ; V_173 ++ ) {
if ( V_286 >= log -> V_193 [ V_173 ] &&
V_286 <= log -> V_193 [ V_173 ] + log -> V_160 )
V_336 ++ ;
}
if ( ! V_336 )
F_185 ( log -> V_145 , L_89 , V_111 ) ;
}
STATIC void
F_38 (
struct V_1 * log )
{
int V_142 , V_337 ;
int V_7 , V_8 ;
F_90 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_91 ( & log -> V_140 , & V_142 , & V_337 ) ;
if ( V_142 != V_7 ) {
if ( V_7 - 1 != V_142 &&
! ( log -> V_30 & V_338 ) ) {
F_148 ( log -> V_145 , V_251 ,
L_90 , V_111 ) ;
log -> V_30 |= V_338 ;
}
if ( V_8 > F_92 ( V_337 ) &&
! ( log -> V_30 & V_338 ) ) {
F_148 ( log -> V_145 , V_251 ,
L_91 , V_111 ) ;
log -> V_30 |= V_338 ;
}
}
}
STATIC void
F_171 ( T_11 * log ,
T_12 * V_63 ,
T_6 V_136 )
{
int V_339 ;
if ( F_186 ( V_136 ) == log -> V_318 ) {
V_339 =
log -> V_177 - ( log -> V_178 - F_132 ( V_136 ) ) ;
if ( V_339 < F_106 ( V_63 -> V_93 ) + F_106 ( log -> V_164 ) )
F_185 ( log -> V_145 , L_92 , V_111 ) ;
} else {
ASSERT ( F_186 ( V_136 ) + 1 == log -> V_318 ) ;
if ( F_132 ( V_136 ) == log -> V_178 )
F_185 ( log -> V_145 , L_93 , V_111 ) ;
V_339 = F_132 ( V_136 ) - log -> V_178 ;
if ( V_339 < F_106 ( V_63 -> V_93 ) + 1 )
F_185 ( log -> V_145 , L_92 , V_111 ) ;
}
}
STATIC void
F_139 ( T_11 * log ,
T_12 * V_63 ,
int V_221 ,
T_18 V_340 )
{
V_246 * V_341 ;
T_12 * V_342 ;
T_19 * V_343 ;
V_194 V_286 ;
V_194 V_344 ;
T_20 V_345 ;
T_5 V_346 ;
int V_35 , V_173 , V_347 , V_348 , V_349 ;
int V_350 ;
F_12 ( & log -> V_112 ) ;
V_342 = log -> V_92 ;
for ( V_173 = 0 ; V_173 < log -> V_157 ; V_173 ++ ) {
if ( V_342 == NULL )
F_185 ( log -> V_145 , L_89 , V_111 ) ;
V_342 = V_342 -> V_94 ;
}
if ( V_342 != log -> V_92 )
F_185 ( log -> V_145 , L_94 , V_111 ) ;
F_15 ( & log -> V_112 ) ;
if ( V_63 -> V_195 . V_196 != F_110 ( V_197 ) )
F_185 ( log -> V_145 , L_95 , V_111 ) ;
V_286 = ( V_194 ) & V_63 -> V_195 ;
for ( V_286 += V_168 ; V_286 < ( ( V_194 ) & V_63 -> V_195 ) + V_221 ;
V_286 += V_168 ) {
if ( * ( V_240 * ) V_286 == F_110 ( V_197 ) )
F_185 ( log -> V_145 , L_96 ,
V_111 ) ;
}
V_35 = F_143 ( V_63 -> V_195 . V_244 ) ;
V_286 = V_63 -> V_208 ;
V_344 = V_286 ;
V_341 = ( V_246 * ) V_286 ;
V_343 = V_63 -> V_191 ;
for ( V_173 = 0 ; V_173 < V_35 ; V_173 ++ ) {
V_341 = ( V_246 * ) V_286 ;
V_345 = ( T_20 )
( ( V_194 ) & ( V_341 -> V_261 ) - V_344 ) ;
if ( V_340 == V_351 || ( V_345 & 0x1ff ) ) {
V_346 = V_341 -> V_261 ;
} else {
V_350 = F_117 ( ( V_194 ) & ( V_341 -> V_261 ) - V_63 -> V_208 ) ;
if ( V_350 >= ( V_163 / V_168 ) ) {
V_347 = V_350 / ( V_163 / V_168 ) ;
V_348 = V_350 % ( V_163 / V_168 ) ;
V_346 = F_187 (
V_343 [ V_347 ] . V_352 . V_353 [ V_348 ] ) ;
} else {
V_346 = F_187 (
V_63 -> V_195 . V_291 [ V_350 ] ) ;
}
}
if ( V_346 != V_54 && V_346 != V_55 )
F_61 ( log -> V_145 ,
L_97 ,
V_111 , V_346 , V_341 ,
( unsigned long ) V_345 ) ;
V_345 = ( T_20 )
( ( V_194 ) & ( V_341 -> V_263 ) - V_344 ) ;
if ( V_340 == V_351 || ( V_345 & 0x1ff ) ) {
V_349 = F_143 ( V_341 -> V_263 ) ;
} else {
V_350 = F_117 ( ( T_20 ) & V_341 -> V_263 -
( T_20 ) V_63 -> V_208 ) ;
if ( V_350 >= ( V_163 / V_168 ) ) {
V_347 = V_350 / ( V_163 / V_168 ) ;
V_348 = V_350 % ( V_163 / V_168 ) ;
V_349 = F_143 ( V_343 [ V_347 ] . V_352 . V_353 [ V_348 ] ) ;
} else {
V_349 = F_143 ( V_63 -> V_195 . V_291 [ V_350 ] ) ;
}
}
V_286 += sizeof( V_246 ) + V_349 ;
}
}
STATIC int
F_188 (
T_11 * log )
{
T_12 * V_63 , * V_354 ;
V_63 = log -> V_92 ;
if ( ! ( V_63 -> V_71 & V_72 ) ) {
V_354 = V_63 ;
do {
V_354 -> V_71 = V_72 ;
V_354 = V_354 -> V_94 ;
} while ( V_354 != V_63 );
return 0 ;
}
return 1 ;
}
int
F_189 (
struct V_41 * V_42 ,
int V_355 )
{
T_11 * log ;
int V_356 ;
log = V_42 -> V_43 ;
if ( ! log ||
log -> V_30 & V_31 ) {
V_42 -> V_81 |= V_357 ;
if ( V_42 -> V_358 )
F_190 ( V_42 -> V_358 ) ;
return 0 ;
}
if ( V_355 && log -> V_92 -> V_71 & V_72 ) {
ASSERT ( F_21 ( log ) ) ;
return 1 ;
}
V_356 = 0 ;
if ( ! V_355 )
F_173 ( log ) ;
F_12 ( & log -> V_112 ) ;
V_42 -> V_81 |= V_357 ;
if ( V_42 -> V_358 )
F_190 ( V_42 -> V_358 ) ;
log -> V_30 |= V_359 ;
if ( V_355 )
V_356 = F_188 ( log ) ;
F_15 ( & log -> V_112 ) ;
F_11 ( & log -> V_60 ) ;
F_11 ( & log -> V_18 ) ;
if ( ! ( log -> V_92 -> V_71 & V_72 ) ) {
ASSERT ( ! V_355 ) ;
F_70 ( V_42 , V_91 , NULL ) ;
F_12 ( & log -> V_112 ) ;
V_356 = F_188 ( log ) ;
F_15 ( & log -> V_112 ) ;
}
F_159 ( log , V_153 , NULL ) ;
#ifdef F_191
{
T_12 * V_63 ;
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
do {
ASSERT ( V_63 -> V_207 == 0 ) ;
V_63 = V_63 -> V_94 ;
} while ( V_63 != log -> V_92 );
F_15 ( & log -> V_112 ) ;
}
#endif
return V_356 ;
}
STATIC int
F_84 ( T_11 * log )
{
T_12 * V_63 ;
V_63 = log -> V_92 ;
do {
if ( V_63 -> V_195 . V_244 )
return 0 ;
V_63 = V_63 -> V_94 ;
} while ( V_63 != log -> V_92 );
return 1 ;
}
