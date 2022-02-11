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
F_22 ( log , V_16 -> V_22 ? V_16 -> V_21 * V_16 -> V_22
: V_16 -> V_21 ) ;
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
int error = 0 ;
if ( ! ( V_42 -> V_81 & V_82 ) ) {
error = F_67 ( V_42 -> V_43 ) ;
if ( ! error )
F_68 ( V_42 ) ;
} else {
ASSERT ( V_42 -> V_81 & V_83 ) ;
}
return error ;
}
int
F_69 ( T_8 * V_42 )
{
struct V_1 * log = V_42 -> V_43 ;
T_11 * V_63 ;
#ifdef F_70
T_11 * V_90 ;
#endif
T_3 * V_16 = NULL ;
T_6 V_65 ;
int error ;
if ( V_42 -> V_81 & V_83 )
return 0 ;
error = F_71 ( V_42 , V_91 , NULL ) ;
ASSERT ( error || ! ( F_21 ( log ) ) ) ;
#ifdef F_70
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
T_12 V_96 ;
T_12 V_97 ;
T_13 V_98 ;
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
error = F_72 ( log , & V_107 , V_16 , & V_65 ,
NULL , V_110 ) ;
}
if ( error )
F_73 ( V_42 , L_5 , V_111 ) ;
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
F_74 ( & V_63 -> V_113 ) ;
F_75 ( log , V_63 ) ;
F_15 ( & log -> V_112 ) ;
error = F_53 ( log , V_63 ) ;
F_12 ( & log -> V_112 ) ;
if ( ! ( V_63 -> V_71 == V_73 ||
V_63 -> V_71 == V_114 ) ) {
if ( ! F_21 ( log ) ) {
F_76 ( & V_63 -> V_115 ,
& log -> V_112 ) ;
} else {
F_15 ( & log -> V_112 ) ;
}
} else {
F_15 ( & log -> V_112 ) ;
}
if ( V_16 ) {
F_77 ( log , V_16 ) ;
F_46 ( log , V_16 ) ;
F_47 ( V_16 ) ;
}
} else {
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
F_74 ( & V_63 -> V_113 ) ;
F_75 ( log , V_63 ) ;
F_15 ( & log -> V_112 ) ;
error = F_53 ( log , V_63 ) ;
F_12 ( & log -> V_112 ) ;
if ( ! ( V_63 -> V_71 == V_73
|| V_63 -> V_71 == V_114
|| V_63 -> V_71 == V_72 ) ) {
F_76 ( & V_63 -> V_115 ,
& log -> V_112 ) ;
} else {
F_15 ( & log -> V_112 ) ;
}
}
return error ;
}
void
F_78 (
struct V_41 * V_42 )
{
F_79 ( & V_42 -> V_43 -> V_116 ) ;
F_80 ( V_42 , V_91 ) ;
F_81 ( V_42 -> V_87 ) ;
F_82 ( V_42 -> V_117 ) ;
F_83 ( V_42 -> V_118 ) ;
F_84 ( V_42 -> V_118 ) ;
F_69 ( V_42 ) ;
}
void
F_85 (
struct V_41 * V_42 )
{
F_78 ( V_42 ) ;
F_64 ( V_42 ) ;
F_65 ( V_42 -> V_43 ) ;
}
void
F_86 (
struct V_41 * V_42 ,
struct V_119 * V_120 ,
int type ,
const struct V_121 * V_122 )
{
V_120 -> V_123 = V_42 ;
V_120 -> V_124 = V_42 -> V_87 ;
V_120 -> V_125 = type ;
V_120 -> V_126 = V_122 ;
V_120 -> V_127 = NULL ;
F_9 ( & V_120 -> V_128 ) ;
F_9 ( & V_120 -> V_129 ) ;
}
void
F_87 (
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
F_88 ( T_8 * V_42 )
{
int V_130 = 0 ;
struct V_1 * log = V_42 -> V_43 ;
if ( ! F_89 ( V_42 ) )
return 0 ;
F_12 ( & log -> V_112 ) ;
switch ( log -> V_131 ) {
case V_132 :
case V_133 :
case V_134 :
break;
case V_135 :
case V_136 :
if ( ! F_90 ( log -> V_86 ) &&
F_91 ( log ) ) {
if ( log -> V_131 == V_135 )
log -> V_131 = V_132 ;
else
log -> V_131 = V_133 ;
}
default:
V_130 = 1 ;
break;
}
F_15 ( & log -> V_112 ) ;
return V_130 ;
}
T_6
F_92 (
struct V_41 * V_42 )
{
struct V_1 * log = V_42 -> V_43 ;
struct V_119 * V_137 ;
T_6 V_138 ;
F_93 ( & V_42 -> V_87 -> V_139 ) ;
V_137 = F_94 ( V_42 -> V_87 ) ;
if ( V_137 )
V_138 = V_137 -> V_140 ;
else
V_138 = F_2 ( & log -> V_141 ) ;
F_95 ( & log -> V_142 , V_138 ) ;
return V_138 ;
}
T_6
F_96 (
struct V_41 * V_42 )
{
T_6 V_138 ;
F_12 ( & V_42 -> V_87 -> V_139 ) ;
V_138 = F_92 ( V_42 ) ;
F_15 ( & V_42 -> V_87 -> V_139 ) ;
return V_138 ;
}
STATIC int
F_28 (
struct V_1 * log ,
T_1 * V_2 )
{
int V_23 ;
int V_143 ;
int V_144 ;
int V_145 ;
int V_146 ;
F_97 ( V_2 , & V_145 , & V_146 ) ;
F_98 ( & log -> V_142 , & V_144 , & V_143 ) ;
V_143 = F_99 ( V_143 ) ;
if ( V_144 == V_145 && V_146 >= V_143 )
V_23 = log -> V_9 - ( V_146 - V_143 ) ;
else if ( V_144 + 1 < V_145 )
return 0 ;
else if ( V_144 < V_145 ) {
ASSERT ( V_144 == ( V_145 - 1 ) ) ;
V_23 = V_143 - V_146 ;
} else {
F_73 ( log -> V_147 ,
L_6
L_7
L_8 ,
V_144 , V_143 , V_145 , V_146 ) ;
ASSERT ( 0 ) ;
V_23 = log -> V_9 ;
}
return V_23 ;
}
void
F_100 ( T_14 * V_148 )
{
struct V_62 * V_63 = V_148 -> V_149 ;
struct V_1 * V_150 = V_63 -> V_151 ;
int V_152 = 0 ;
if ( F_101 ( ( F_102 ( V_148 ) ) , V_150 -> V_147 ,
V_153 , V_154 ) ) {
F_103 ( V_148 , V_111 ) ;
F_104 ( V_148 ) ;
F_54 ( V_150 -> V_147 , V_77 ) ;
V_152 = V_155 ;
} else if ( V_63 -> V_71 & V_72 ) {
V_152 = V_155 ;
}
ASSERT ( F_105 ( V_148 ) ) ;
F_106 ( V_63 , V_152 ) ;
}
STATIC void
F_107 (
struct V_41 * V_42 ,
struct V_1 * log )
{
int V_156 ;
int V_157 ;
if ( V_42 -> V_158 <= 0 )
log -> V_159 = V_160 ;
else
log -> V_159 = V_42 -> V_158 ;
if ( V_42 -> V_161 > 0 ) {
V_156 = log -> V_162 = V_42 -> V_161 ;
log -> V_163 = 0 ;
while ( V_156 != 1 ) {
log -> V_163 ++ ;
V_156 >>= 1 ;
}
if ( F_108 ( & V_42 -> V_164 ) ) {
V_157 = V_42 -> V_161 / V_165 ;
if ( V_42 -> V_161 % V_165 )
V_157 ++ ;
log -> V_166 = V_157 << V_167 ;
log -> V_168 = V_157 ;
} else {
ASSERT ( V_42 -> V_161 <= V_169 ) ;
log -> V_166 = V_170 ;
log -> V_168 = 1 ;
}
goto V_171;
}
log -> V_162 = V_169 ;
log -> V_163 = V_172 ;
log -> V_166 = V_170 ;
log -> V_168 = 1 ;
V_171:
if ( V_42 -> V_158 == 0 )
V_42 -> V_158 = log -> V_159 ;
if ( V_42 -> V_161 == 0 )
V_42 -> V_161 = log -> V_162 ;
}
void
F_68 (
struct V_41 * V_42 )
{
F_109 ( V_42 -> V_173 , & V_42 -> V_43 -> V_116 ,
F_110 ( V_174 * 10 ) ) ;
}
void
F_111 (
struct V_175 * V_176 )
{
struct V_1 * log = F_112 ( F_113 ( V_176 ) ,
struct V_1 , V_116 ) ;
struct V_41 * V_42 = log -> V_147 ;
if ( F_88 ( V_42 ) )
F_114 ( V_42 ) ;
else
F_80 ( V_42 , 0 ) ;
F_115 ( V_42 -> V_87 ) ;
F_68 ( V_42 ) ;
}
STATIC struct V_1 *
F_57 (
struct V_41 * V_42 ,
struct V_177 * V_78 ,
T_10 V_79 ,
int V_80 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_178 ;
T_11 * V_63 , * V_179 = NULL ;
T_14 * V_148 ;
int V_180 ;
int error = V_58 ;
T_4 V_181 = 0 ;
log = F_116 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! log ) {
F_61 ( V_42 , L_9 ) ;
goto V_84;
}
log -> V_147 = V_42 ;
log -> V_182 = V_78 ;
log -> V_9 = F_99 ( V_80 ) ;
log -> V_183 = V_79 ;
log -> V_184 = V_80 ;
log -> V_131 = V_134 ;
log -> V_30 |= V_31 ;
F_117 ( & log -> V_116 , F_111 ) ;
log -> V_185 = - 1 ;
F_118 ( & log -> V_142 , 1 , 0 ) ;
F_118 ( & log -> V_141 , 1 , 0 ) ;
log -> V_186 = 1 ;
F_7 ( & log -> V_60 ) ;
F_7 ( & log -> V_18 ) ;
error = V_187 ;
if ( F_119 ( & V_42 -> V_164 ) ) {
V_181 = V_42 -> V_164 . V_188 ;
if ( V_181 < V_167 ) {
F_61 ( V_42 , L_10 ,
V_181 , V_167 ) ;
goto V_85;
}
V_181 -= V_167 ;
if ( V_181 > V_42 -> V_189 ) {
F_61 ( V_42 , L_11 ,
V_181 , V_42 -> V_189 ) ;
goto V_85;
}
if ( V_181 && log -> V_183 > 0 &&
! F_108 ( & V_42 -> V_164 ) ) {
F_61 ( V_42 ,
L_12 ,
V_181 ) ;
goto V_85;
}
}
log -> V_190 = 1 << V_181 ;
F_107 ( V_42 , log ) ;
error = V_58 ;
V_148 = F_120 ( V_42 -> V_191 , 0 , F_121 ( log -> V_162 ) , 0 ) ;
if ( ! V_148 )
goto V_85;
V_148 -> V_192 = F_100 ;
ASSERT ( F_122 ( V_148 ) ) ;
log -> V_193 = V_148 ;
F_10 ( & log -> V_112 ) ;
F_123 ( & log -> V_194 ) ;
V_178 = & log -> V_92 ;
ASSERT ( log -> V_162 >= 4096 ) ;
for ( V_180 = 0 ; V_180 < log -> V_159 ; V_180 ++ ) {
* V_178 = F_116 ( sizeof( T_11 ) , V_57 ) ;
if ( ! * V_178 )
goto V_195;
V_63 = * V_178 ;
V_63 -> V_196 = V_179 ;
V_179 = V_63 ;
V_148 = F_124 ( V_42 -> V_191 ,
F_121 ( log -> V_162 ) , 0 ) ;
if ( ! V_148 )
goto V_195;
V_148 -> V_192 = F_100 ;
V_63 -> V_197 = V_148 ;
V_63 -> V_198 = V_148 -> V_199 ;
#ifdef F_70
log -> V_200 [ V_180 ] = ( V_201 ) & ( V_63 -> V_202 ) ;
#endif
V_2 = & V_63 -> V_202 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_203 = F_125 ( V_204 ) ;
V_2 -> V_205 = F_125 (
F_108 ( & log -> V_147 -> V_164 ) ? 2 : 1 ) ;
V_2 -> V_206 = F_125 ( log -> V_162 ) ;
V_2 -> V_207 = F_125 ( V_208 ) ;
memcpy ( & V_2 -> V_209 , & V_42 -> V_164 . V_210 , sizeof( V_211 ) ) ;
V_63 -> V_212 = F_99 ( V_148 -> V_213 ) - log -> V_166 ;
V_63 -> V_71 = V_73 ;
V_63 -> V_151 = log ;
F_126 ( & V_63 -> V_113 , 0 ) ;
F_10 ( & V_63 -> V_70 ) ;
V_63 -> V_76 = & ( V_63 -> V_214 ) ;
V_63 -> V_215 = ( char * ) V_63 -> V_198 + log -> V_166 ;
ASSERT ( F_122 ( V_63 -> V_197 ) ) ;
F_123 ( & V_63 -> V_115 ) ;
F_123 ( & V_63 -> V_216 ) ;
V_178 = & V_63 -> V_94 ;
}
* V_178 = log -> V_92 ;
log -> V_92 -> V_196 = V_179 ;
error = F_127 ( log ) ;
if ( error )
goto V_195;
return log ;
V_195:
for ( V_63 = log -> V_92 ; V_63 ; V_63 = V_179 ) {
V_179 = V_63 -> V_94 ;
if ( V_63 -> V_197 )
F_128 ( V_63 -> V_197 ) ;
F_129 ( V_63 ) ;
}
F_130 ( & log -> V_112 ) ;
F_128 ( log -> V_193 ) ;
V_85:
F_129 ( log ) ;
V_84:
return F_131 ( - error ) ;
}
STATIC int
F_44 (
struct V_1 * log ,
struct V_15 * V_61 ,
struct V_62 * * V_63 ,
T_6 * V_217 )
{
struct V_41 * V_42 = log -> V_147 ;
int error ;
struct V_100 V_101 = {
. V_102 = NULL ,
. V_103 = 0 ,
. V_104 = V_218 ,
} ;
struct V_106 V_107 = {
. V_108 = 1 ,
. V_109 = & V_101 ,
} ;
F_51 ( V_63 ) ;
error = F_72 ( log , & V_107 , V_61 , V_217 , V_63 ,
V_219 ) ;
if ( error )
F_54 ( V_42 , V_77 ) ;
return error ;
}
STATIC void
F_22 (
struct V_1 * log ,
int V_24 )
{
T_6 V_220 = 0 ;
T_6 V_221 ;
int V_222 ;
int V_23 ;
int V_223 ;
int V_224 ;
int V_225 ;
ASSERT ( F_121 ( V_24 ) < log -> V_184 ) ;
V_23 = F_28 ( log , & log -> V_60 . V_12 ) ;
V_222 = F_132 ( V_23 ) ;
V_225 = F_121 ( V_24 ) ;
V_225 = F_133 ( V_225 , ( log -> V_184 >> 2 ) ) ;
V_225 = F_133 ( V_225 , 256 ) ;
if ( V_222 >= V_225 )
return;
F_98 ( & log -> V_142 , & V_224 ,
& V_223 ) ;
V_223 += V_225 ;
if ( V_223 >= log -> V_184 ) {
V_223 -= log -> V_184 ;
V_224 += 1 ;
}
V_220 = F_134 ( V_224 ,
V_223 ) ;
V_221 = F_2 ( & log -> V_141 ) ;
if ( F_135 ( V_220 , V_221 ) > 0 )
V_220 = V_221 ;
if ( ! F_21 ( log ) )
F_136 ( log -> V_86 , V_220 ) ;
}
STATIC void
F_137 (
struct V_1 * log ,
struct V_62 * V_63 ,
int V_226 )
{
int V_180 , V_227 , V_228 ;
int V_156 = V_63 -> V_93 + V_226 ;
T_16 V_229 ;
V_201 V_230 ;
V_229 = F_138 ( V_63 -> V_202 . V_231 ) ;
V_230 = V_63 -> V_215 ;
for ( V_180 = 0 ; V_180 < F_121 ( V_156 ) ; V_180 ++ ) {
if ( V_180 >= ( V_165 / V_170 ) )
break;
V_63 -> V_202 . V_232 [ V_180 ] = * ( T_16 * ) V_230 ;
* ( T_16 * ) V_230 = V_229 ;
V_230 += V_170 ;
}
if ( F_108 ( & log -> V_147 -> V_164 ) ) {
T_17 * V_233 = V_63 -> V_198 ;
for ( ; V_180 < F_121 ( V_156 ) ; V_180 ++ ) {
V_227 = V_180 / ( V_165 / V_170 ) ;
V_228 = V_180 % ( V_165 / V_170 ) ;
V_233 [ V_227 ] . V_234 . V_235 [ V_228 ] = * ( T_16 * ) V_230 ;
* ( T_16 * ) V_230 = V_229 ;
V_230 += V_170 ;
}
for ( V_180 = 1 ; V_180 < log -> V_168 ; V_180 ++ )
V_233 [ V_180 ] . V_234 . V_236 = V_229 ;
}
}
T_18
F_139 (
struct V_1 * log ,
struct V_237 * V_238 ,
char * V_230 ,
int V_156 )
{
T_13 V_239 ;
V_239 = F_140 ( ( char * ) V_238 ,
sizeof( struct V_237 ) ,
F_141 ( struct V_237 , V_240 ) ) ;
if ( F_108 ( & log -> V_147 -> V_164 ) ) {
union V_241 * V_233 = (union V_241 * ) V_238 ;
int V_180 ;
for ( V_180 = 1 ; V_180 < log -> V_168 ; V_180 ++ ) {
V_239 = F_142 ( V_239 , & V_233 [ V_180 ] . V_234 ,
sizeof( struct V_242 ) ) ;
}
}
V_239 = F_142 ( V_239 , V_230 , V_156 ) ;
return F_143 ( V_239 ) ;
}
STATIC int
F_144 (
struct V_243 * V_148 )
{
struct V_62 * V_63 = V_148 -> V_149 ;
if ( V_63 -> V_71 & V_72 ) {
F_145 ( V_148 , V_29 ) ;
F_104 ( V_148 ) ;
F_146 ( V_148 , 0 ) ;
return 0 ;
}
F_147 ( V_148 ) ;
return 0 ;
}
STATIC int
F_148 (
struct V_1 * log ,
struct V_62 * V_63 )
{
T_14 * V_148 ;
int V_180 ;
T_4 V_244 ;
T_4 V_245 ;
int V_226 ;
int V_246 = 0 ;
int error ;
int V_247 = F_108 ( & log -> V_147 -> V_164 ) ;
int V_156 ;
F_24 ( V_248 ) ;
ASSERT ( F_149 ( & V_63 -> V_113 ) == 0 ) ;
V_245 = log -> V_166 + V_63 -> V_93 ;
if ( V_247 && log -> V_147 -> V_164 . V_249 > 1 ) {
V_244 = F_150 ( log , F_151 ( log , V_245 ) ) ;
} else {
V_244 = F_99 ( F_121 ( V_245 ) ) ;
}
V_226 = V_244 - V_245 ;
ASSERT ( V_226 >= 0 ) ;
ASSERT ( ( V_247 && log -> V_147 -> V_164 . V_249 > 1 &&
V_226 < log -> V_147 -> V_164 . V_249 )
||
( log -> V_147 -> V_164 . V_249 <= 1 &&
V_226 < F_99 ( 1 ) ) ) ;
F_6 ( log , & log -> V_60 . V_12 , V_226 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_226 ) ;
F_137 ( log , V_63 , V_226 ) ;
V_156 = V_63 -> V_93 ;
if ( V_247 )
V_156 += V_226 ;
V_63 -> V_202 . V_250 = F_125 ( V_156 ) ;
V_148 = V_63 -> V_197 ;
F_152 ( V_148 , F_153 ( F_154 ( V_63 -> V_202 . V_231 ) ) ) ;
F_155 ( V_251 , F_121 ( V_244 ) ) ;
if ( F_156 ( V_148 ) + F_121 ( V_244 ) > log -> V_184 ) {
char * V_252 ;
V_246 = V_244 - ( F_99 ( log -> V_184 - F_156 ( V_148 ) ) ) ;
V_244 = F_99 ( log -> V_184 - F_156 ( V_148 ) ) ;
V_63 -> V_253 = 2 ;
V_252 = ( char * ) & V_63 -> V_202 + V_244 ;
for ( V_180 = 0 ; V_180 < V_246 ; V_180 += V_170 ) {
T_13 V_7 = F_157 ( * ( T_16 * ) V_252 ) ;
if ( ++ V_7 == V_204 )
V_7 ++ ;
* ( T_16 * ) V_252 = F_125 ( V_7 ) ;
V_252 += V_170 ;
}
} else {
V_63 -> V_253 = 1 ;
}
V_63 -> V_202 . V_240 = F_139 ( log , & V_63 -> V_202 ,
V_63 -> V_215 , V_156 ) ;
V_148 -> V_254 = F_121 ( V_244 ) ;
V_148 -> V_149 = V_63 ;
F_158 ( V_148 ) ;
F_159 ( V_148 ) ;
V_148 -> V_255 |= V_256 ;
if ( log -> V_147 -> V_81 & V_257 ) {
V_148 -> V_255 |= V_258 ;
if ( log -> V_147 -> V_191 != log -> V_147 -> V_117 )
F_160 ( log -> V_147 -> V_117 ) ;
else
V_148 -> V_255 |= V_259 ;
}
ASSERT ( F_156 ( V_148 ) <= log -> V_184 - 1 ) ;
ASSERT ( F_156 ( V_148 ) + F_121 ( V_244 ) <= log -> V_184 ) ;
F_161 ( log , V_63 , V_244 , V_260 ) ;
F_152 ( V_148 , F_156 ( V_148 ) + log -> V_183 ) ;
F_162 ( V_148 ) ;
error = F_144 ( V_148 ) ;
if ( error ) {
F_103 ( V_148 , L_13 ) ;
return error ;
}
if ( V_246 ) {
V_148 = V_63 -> V_151 -> V_193 ;
F_152 ( V_148 , 0 ) ;
F_163 ( V_148 ,
( char * ) & V_63 -> V_202 + V_244 , V_246 ) ;
V_148 -> V_149 = V_63 ;
F_158 ( V_148 ) ;
F_159 ( V_148 ) ;
V_148 -> V_255 |= V_256 ;
if ( log -> V_147 -> V_81 & V_257 )
V_148 -> V_255 |= V_258 ;
ASSERT ( F_156 ( V_148 ) <= log -> V_184 - 1 ) ;
ASSERT ( F_156 ( V_148 ) + F_121 ( V_244 ) <= log -> V_184 ) ;
F_152 ( V_148 , F_156 ( V_148 ) + log -> V_183 ) ;
F_162 ( V_148 ) ;
error = F_144 ( V_148 ) ;
if ( error ) {
F_103 ( V_148 , L_14 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_65 (
struct V_1 * log )
{
T_11 * V_63 , * V_261 ;
int V_180 ;
F_164 ( log ) ;
F_165 ( log -> V_193 , F_121 ( log -> V_162 ) ) ;
F_128 ( log -> V_193 ) ;
V_63 = log -> V_92 ;
for ( V_180 = 0 ; V_180 < log -> V_159 ; V_180 ++ ) {
F_128 ( V_63 -> V_197 ) ;
V_261 = V_63 -> V_94 ;
F_129 ( V_63 ) ;
V_63 = V_261 ;
}
F_130 ( & log -> V_112 ) ;
log -> V_147 -> V_43 = NULL ;
F_129 ( log ) ;
}
static inline void
F_166 (
struct V_1 * log ,
struct V_62 * V_63 ,
int V_262 ,
int V_263 )
{
F_12 ( & log -> V_112 ) ;
F_167 ( & V_63 -> V_202 . V_264 , V_262 ) ;
V_63 -> V_93 += V_263 ;
F_15 ( & log -> V_112 ) ;
}
void
F_168 (
struct V_41 * V_42 ,
struct V_15 * V_61 )
{
T_4 V_180 ;
T_4 V_265 = V_61 -> V_34 * ( T_4 ) sizeof( V_266 ) ;
static char * V_267 [ V_268 ] = {
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
static char * V_269 [ V_270 ] = {
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
V_61 -> V_59 > V_270 ) ?
L_82 : V_269 [ V_61 -> V_59 - 1 ] ) ,
V_61 -> V_59 ,
V_61 -> V_21 ,
V_61 -> V_46 ,
V_61 -> V_33 , V_61 -> V_37 ,
V_61 -> V_34 , V_265 ,
V_61 -> V_33 +
V_61 -> V_37 + V_265 ,
V_61 -> V_32 ) ;
for ( V_180 = 0 ; V_180 < V_61 -> V_32 ; V_180 ++ ) {
T_4 V_40 = V_61 -> V_38 [ V_180 ] . V_40 ;
F_61 ( V_42 , L_83 , V_180 ,
( ( V_40 <= 0 || V_40 > V_268 ) ?
L_84 : V_267 [ V_40 - 1 ] ) ,
V_61 -> V_38 [ V_180 ] . V_39 ) ;
}
F_169 ( V_42 , V_271 ,
L_85 ) ;
F_54 ( V_42 , V_272 ) ;
}
static int
F_170 (
struct V_15 * V_61 ,
struct V_106 * V_273 )
{
struct V_106 * V_274 ;
int V_275 = 0 ;
int V_35 = 0 ;
int V_180 ;
if ( V_61 -> V_19 & V_66 )
V_275 ++ ;
for ( V_274 = V_273 ; V_274 ; V_274 = V_274 -> V_276 ) {
V_275 += V_274 -> V_108 ;
for ( V_180 = 0 ; V_180 < V_274 -> V_108 ; V_180 ++ ) {
struct V_100 * V_277 = & V_274 -> V_109 [ V_180 ] ;
V_35 += V_277 -> V_103 ;
F_34 ( V_61 , V_277 -> V_103 , V_277 -> V_104 ) ;
}
}
V_61 -> V_34 += V_275 ;
V_35 += V_275 * sizeof( struct V_278 ) ;
return V_35 ;
}
static int
F_171 (
struct V_278 * V_279 ,
struct V_15 * V_61 )
{
if ( ! ( V_61 -> V_19 & V_66 ) )
return 0 ;
V_279 -> V_280 = F_125 ( V_61 -> V_45 ) ;
V_279 -> V_281 = V_61 -> V_282 ;
V_279 -> V_283 = 0 ;
V_279 -> V_284 = V_285 ;
V_279 -> V_286 = 0 ;
V_61 -> V_19 &= ~ V_66 ;
return sizeof( struct V_278 ) ;
}
static V_266 *
F_172 (
struct V_1 * log ,
struct V_278 * V_279 ,
struct V_15 * V_61 ,
T_4 V_64 )
{
V_279 -> V_280 = F_125 ( V_61 -> V_45 ) ;
V_279 -> V_281 = V_61 -> V_282 ;
V_279 -> V_286 = 0 ;
V_279 -> V_284 = V_64 ;
switch ( V_279 -> V_281 ) {
case V_54 :
case V_287 :
case V_55 :
break;
default:
F_61 ( log -> V_147 ,
L_86 ,
V_279 -> V_281 , V_61 ) ;
return NULL ;
}
return V_279 ;
}
static int
F_173 (
struct V_15 * V_61 ,
struct V_278 * V_279 ,
int V_288 ,
int V_289 ,
int * V_290 ,
int * V_291 ,
int * V_292 ,
int * V_293 )
{
int V_294 ;
V_294 = V_289 - * V_293 ;
* V_290 = * V_293 ;
if ( V_294 <= V_288 ) {
* V_291 = V_294 ;
V_279 -> V_283 = F_125 ( * V_291 ) ;
if ( * V_292 )
V_279 -> V_284 |= ( V_295 | V_296 ) ;
* V_292 = 0 ;
* V_293 = 0 ;
return 0 ;
}
* V_291 = V_288 ;
V_279 -> V_283 = F_125 ( * V_291 ) ;
V_279 -> V_284 |= V_297 ;
if ( * V_292 )
V_279 -> V_284 |= V_296 ;
* V_293 += * V_291 ;
( * V_292 ) ++ ;
V_61 -> V_46 -= sizeof( struct V_278 ) ;
V_61 -> V_34 ++ ;
return sizeof( struct V_278 ) ;
}
static int
F_174 (
struct V_1 * log ,
struct V_62 * V_63 ,
T_4 V_64 ,
int * V_262 ,
int * V_298 ,
int * V_299 ,
int * V_300 ,
int V_301 ,
struct V_62 * * V_302 )
{
if ( * V_299 ) {
F_166 ( log , V_63 , * V_262 , * V_298 ) ;
* V_262 = 0 ;
* V_298 = 0 ;
return F_53 ( log , V_63 ) ;
}
* V_299 = 0 ;
* V_300 = 0 ;
if ( V_63 -> V_212 - V_301 <= sizeof( V_266 ) ) {
F_166 ( log , V_63 , * V_262 , * V_298 ) ;
* V_262 = 0 ;
* V_298 = 0 ;
F_12 ( & log -> V_112 ) ;
F_75 ( log , V_63 ) ;
F_15 ( & log -> V_112 ) ;
if ( ! V_302 )
return F_53 ( log , V_63 ) ;
ASSERT ( V_64 & V_219 ) ;
* V_302 = V_63 ;
}
return 0 ;
}
int
F_72 (
struct V_1 * log ,
struct V_106 * V_273 ,
struct V_15 * V_61 ,
T_6 * V_303 ,
struct V_62 * * V_302 ,
T_4 V_64 )
{
struct V_62 * V_63 = NULL ;
struct V_100 * V_277 ;
struct V_106 * V_274 ;
int V_35 ;
int V_304 ;
int V_299 = 0 ;
int V_300 = 0 ;
int V_305 = 0 ;
int V_262 = 0 ;
int V_298 = 0 ;
int error ;
* V_303 = 0 ;
V_35 = F_170 ( V_61 , V_273 ) ;
if ( V_61 -> V_19 & V_66 )
V_61 -> V_46 -= sizeof( V_266 ) ;
if ( V_64 & ( V_219 | V_110 ) )
V_61 -> V_46 -= sizeof( V_266 ) ;
if ( V_61 -> V_46 < 0 )
F_168 ( log -> V_147 , V_61 ) ;
V_304 = 0 ;
V_274 = V_273 ;
V_277 = V_274 -> V_109 ;
while ( V_274 && V_304 < V_274 -> V_108 ) {
void * V_306 ;
int V_301 ;
error = F_175 ( log , V_35 , & V_63 , V_61 ,
& V_305 , & V_301 ) ;
if ( error )
return error ;
ASSERT ( V_301 <= V_63 -> V_212 - 1 ) ;
V_306 = V_63 -> V_215 + V_301 ;
if ( ! * V_303 )
* V_303 = F_154 ( V_63 -> V_202 . V_231 ) ;
while ( V_274 && V_304 < V_274 -> V_108 ) {
struct V_100 * V_101 = & V_277 [ V_304 ] ;
struct V_278 * V_279 ;
int V_307 ;
int V_291 ;
int V_290 ;
ASSERT ( V_101 -> V_103 % sizeof( V_308 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_306 % sizeof( V_308 ) == 0 ) ;
V_307 = F_171 ( V_306 , V_61 ) ;
if ( V_307 ) {
V_262 ++ ;
F_176 ( & V_306 , & V_35 , & V_301 ,
V_307 ) ;
}
V_279 = F_172 ( log , V_306 , V_61 , V_64 ) ;
if ( ! V_279 )
return F_30 ( V_29 ) ;
F_176 ( & V_306 , & V_35 , & V_301 ,
sizeof( struct V_278 ) ) ;
V_35 += F_173 ( V_61 , V_279 ,
V_63 -> V_212 - V_301 ,
V_101 -> V_103 ,
& V_290 , & V_291 ,
& V_299 ,
& V_300 ) ;
F_177 ( log , V_306 ) ;
ASSERT ( V_291 >= 0 ) ;
memcpy ( V_306 , V_101 -> V_102 + V_290 , V_291 ) ;
F_176 ( & V_306 , & V_35 , & V_301 , V_291 ) ;
V_291 += V_307 + sizeof( V_266 ) ;
V_262 ++ ;
V_298 += V_305 ? V_291 : 0 ;
error = F_174 ( log , V_63 , V_64 ,
& V_262 , & V_298 ,
& V_299 ,
& V_300 ,
V_301 ,
V_302 ) ;
if ( error )
return error ;
if ( V_299 )
break;
if ( ++ V_304 == V_274 -> V_108 ) {
V_274 = V_274 -> V_276 ;
V_304 = 0 ;
if ( V_274 )
V_277 = V_274 -> V_109 ;
}
if ( V_262 == 0 ) {
if ( ! V_274 )
return 0 ;
break;
}
}
}
ASSERT ( V_35 == 0 ) ;
F_166 ( log , V_63 , V_262 , V_298 ) ;
if ( ! V_302 )
return F_53 ( log , V_63 ) ;
ASSERT ( V_64 & V_219 ) ;
* V_302 = V_63 ;
return 0 ;
}
STATIC void
F_178 (
struct V_1 * log )
{
T_11 * V_63 ;
int V_309 = 0 ;
V_63 = log -> V_92 ;
do {
if ( V_63 -> V_71 == V_114 ) {
V_63 -> V_71 = V_73 ;
V_63 -> V_93 = 0 ;
ASSERT ( V_63 -> V_214 == NULL ) ;
if ( ! V_309 &&
( F_157 ( V_63 -> V_202 . V_264 ) ==
V_310 ) ) {
V_309 = 1 ;
} else {
V_309 = 2 ;
}
V_63 -> V_202 . V_264 = 0 ;
memset ( V_63 -> V_202 . V_232 , 0 ,
sizeof( V_63 -> V_202 . V_232 ) ) ;
V_63 -> V_202 . V_231 = 0 ;
} else if ( V_63 -> V_71 == V_73 )
;
else
break;
V_63 = V_63 -> V_94 ;
} while ( V_63 != log -> V_92 );
if ( V_309 ) {
switch ( log -> V_131 ) {
case V_134 :
case V_135 :
case V_136 :
log -> V_131 = V_135 ;
break;
case V_132 :
if ( V_309 == 1 )
log -> V_131 = V_136 ;
else
log -> V_131 = V_135 ;
break;
case V_133 :
if ( V_309 == 1 )
log -> V_131 = V_134 ;
else
log -> V_131 = V_135 ;
break;
default:
ASSERT ( 0 ) ;
}
}
}
STATIC T_6
F_179 (
struct V_1 * log )
{
T_11 * V_311 ;
T_6 V_312 , V_65 ;
V_311 = log -> V_92 ;
V_312 = 0 ;
do {
if ( ! ( V_311 -> V_71 & ( V_73 | V_114 ) ) ) {
V_65 = F_154 ( V_311 -> V_202 . V_231 ) ;
if ( ( V_65 && ! V_312 ) ||
( F_135 ( V_65 , V_312 ) < 0 ) ) {
V_312 = V_65 ;
}
}
V_311 = V_311 -> V_94 ;
} while ( V_311 != log -> V_92 );
return V_312 ;
}
STATIC void
F_180 (
struct V_1 * log ,
int V_152 ,
struct V_62 * V_313 )
{
T_11 * V_63 ;
T_11 * V_90 ;
T_7 * V_68 , * V_75 ;
int V_314 = 0 ;
T_6 V_312 ;
int V_315 ;
int V_316 ;
int V_317 ;
int V_318 ;
int V_319 = 0 ;
F_12 ( & log -> V_112 ) ;
V_90 = V_63 = log -> V_92 ;
V_315 = 0 ;
V_317 = 0 ;
V_318 = 0 ;
do {
V_90 = log -> V_92 ;
V_63 = log -> V_92 ;
V_316 = 0 ;
V_318 ++ ;
do {
if ( V_63 -> V_71 &
( V_73 | V_114 ) ) {
V_63 = V_63 -> V_94 ;
continue;
}
if ( ! ( V_63 -> V_71 & V_72 ) ) {
if ( ! ( V_63 -> V_71 &
( V_320 |
V_321 ) ) ) {
if ( V_313 && ( V_313 -> V_71 ==
V_320 ) ) {
V_313 -> V_71 = V_321 ;
}
break;
}
V_312 = F_179 ( log ) ;
if ( V_312 &&
F_135 ( V_312 ,
F_154 ( V_63 -> V_202 . V_231 ) ) < 0 ) {
V_63 = V_63 -> V_94 ;
continue;
}
V_63 -> V_71 = V_322 ;
ASSERT ( F_135 ( F_2 ( & log -> V_141 ) ,
F_154 ( V_63 -> V_202 . V_231 ) ) <= 0 ) ;
if ( V_63 -> V_214 )
F_95 ( & log -> V_141 ,
F_154 ( V_63 -> V_202 . V_231 ) ) ;
} else
V_315 ++ ;
F_15 ( & log -> V_112 ) ;
F_12 ( & V_63 -> V_70 ) ;
V_68 = V_63 -> V_214 ;
while ( V_68 ) {
V_63 -> V_76 = & ( V_63 -> V_214 ) ;
V_63 -> V_214 = NULL ;
F_15 ( & V_63 -> V_70 ) ;
for (; V_68 ; V_68 = V_75 ) {
V_75 = V_68 -> V_75 ;
V_68 -> V_323 ( V_68 -> V_324 , V_152 ) ;
}
F_12 ( & V_63 -> V_70 ) ;
V_68 = V_63 -> V_214 ;
}
V_316 ++ ;
V_317 ++ ;
F_12 ( & log -> V_112 ) ;
ASSERT ( V_63 -> V_214 == NULL ) ;
F_15 ( & V_63 -> V_70 ) ;
if ( ! ( V_63 -> V_71 & V_72 ) )
V_63 -> V_71 = V_114 ;
F_178 ( log ) ;
F_181 ( & V_63 -> V_115 ) ;
V_63 = V_63 -> V_94 ;
} while ( V_90 != V_63 );
if ( V_318 > 5000 ) {
V_314 += V_318 ;
V_318 = 0 ;
F_61 ( log -> V_147 ,
L_87 ,
V_111 , V_314 ) ;
}
} while ( ! V_315 && V_316 );
#ifdef F_70
if ( V_317 ) {
V_90 = V_63 = log -> V_92 ;
do {
ASSERT ( V_63 -> V_71 != V_321 ) ;
if ( V_63 -> V_71 == V_74 ||
V_63 -> V_71 == V_325 ||
V_63 -> V_71 == V_320 ||
V_63 -> V_71 == V_72 )
break;
V_63 = V_63 -> V_94 ;
} while ( V_90 != V_63 );
}
#endif
if ( log -> V_92 -> V_71 & ( V_73 | V_72 ) )
V_319 = 1 ;
F_15 ( & log -> V_112 ) ;
if ( V_319 )
F_181 ( & log -> V_194 ) ;
}
STATIC void
F_106 (
T_11 * V_63 ,
int V_152 )
{
struct V_1 * log = V_63 -> V_151 ;
F_12 ( & log -> V_112 ) ;
ASSERT ( V_63 -> V_71 == V_325 ||
V_63 -> V_71 == V_72 ) ;
ASSERT ( F_149 ( & V_63 -> V_113 ) == 0 ) ;
ASSERT ( V_63 -> V_253 == 1 || V_63 -> V_253 == 2 ) ;
if ( V_63 -> V_71 != V_72 ) {
if ( -- V_63 -> V_253 == 1 ) {
F_15 ( & log -> V_112 ) ;
return;
}
V_63 -> V_71 = V_320 ;
}
F_181 ( & V_63 -> V_216 ) ;
F_15 ( & log -> V_112 ) ;
F_180 ( log , V_152 , V_63 ) ;
}
STATIC int
F_175 (
struct V_1 * log ,
int V_35 ,
struct V_62 * * V_178 ,
struct V_15 * V_61 ,
int * V_326 ,
int * V_327 )
{
int V_301 ;
T_15 * V_2 ;
T_11 * V_63 ;
int error ;
V_328:
F_12 ( & log -> V_112 ) ;
if ( F_21 ( log ) ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
V_63 = log -> V_92 ;
if ( V_63 -> V_71 != V_73 ) {
F_24 ( V_329 ) ;
F_76 ( & log -> V_194 , & log -> V_112 ) ;
goto V_328;
}
V_2 = & V_63 -> V_202 ;
F_74 ( & V_63 -> V_113 ) ;
V_301 = V_63 -> V_93 ;
if ( V_301 == 0 ) {
V_61 -> V_46 -= log -> V_166 ;
F_34 ( V_61 ,
log -> V_166 ,
V_330 ) ;
V_2 -> V_331 = F_125 ( log -> V_186 ) ;
V_2 -> V_231 = F_182 (
F_134 ( log -> V_186 , log -> V_332 ) ) ;
ASSERT ( log -> V_332 >= 0 ) ;
}
if ( V_63 -> V_212 - V_63 -> V_93 < 2 * sizeof( V_266 ) ) {
F_183 ( log , V_63 , V_63 -> V_212 ) ;
if ( ! F_184 ( & V_63 -> V_113 , - 1 , 1 ) ) {
F_15 ( & log -> V_112 ) ;
error = F_53 ( log , V_63 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_112 ) ;
}
goto V_328;
}
if ( V_35 <= V_63 -> V_212 - V_63 -> V_93 ) {
* V_326 = 0 ;
V_63 -> V_93 += V_35 ;
} else {
* V_326 = 1 ;
F_183 ( log , V_63 , V_63 -> V_212 ) ;
}
* V_178 = V_63 ;
ASSERT ( V_63 -> V_93 <= V_63 -> V_212 ) ;
F_15 ( & log -> V_112 ) ;
* V_327 = V_301 ;
return 0 ;
}
STATIC void
F_49 (
struct V_1 * log ,
struct V_15 * V_61 )
{
F_185 ( log , V_61 ) ;
if ( V_61 -> V_22 > 0 )
V_61 -> V_22 -- ;
F_1 ( log , & log -> V_60 . V_12 ,
V_61 -> V_46 ) ;
F_1 ( log , & log -> V_18 . V_12 ,
V_61 -> V_46 ) ;
V_61 -> V_46 = V_61 -> V_21 ;
F_33 ( V_61 ) ;
F_186 ( log , V_61 ) ;
if ( V_61 -> V_22 > 0 )
return;
F_6 ( log , & log -> V_60 . V_12 ,
V_61 -> V_21 ) ;
F_187 ( log , V_61 ) ;
V_61 -> V_46 = V_61 -> V_21 ;
F_33 ( V_61 ) ;
}
STATIC void
F_46 (
struct V_1 * log ,
struct V_15 * V_61 )
{
int V_3 ;
if ( V_61 -> V_22 > 0 )
V_61 -> V_22 -- ;
F_188 ( log , V_61 ) ;
F_189 ( log , V_61 ) ;
V_3 = V_61 -> V_46 ;
if ( V_61 -> V_22 > 0 ) {
ASSERT ( V_61 -> V_19 & V_20 ) ;
V_3 += V_61 -> V_21 * V_61 -> V_22 ;
}
F_1 ( log , & log -> V_60 . V_12 , V_3 ) ;
F_1 ( log , & log -> V_18 . V_12 , V_3 ) ;
F_190 ( log , V_61 ) ;
F_87 ( log -> V_147 ) ;
}
STATIC int
F_53 (
struct V_1 * log ,
struct V_62 * V_63 )
{
int V_333 = 0 ;
if ( V_63 -> V_71 & V_72 )
return F_30 ( V_29 ) ;
ASSERT ( F_149 ( & V_63 -> V_113 ) > 0 ) ;
if ( ! F_191 ( & V_63 -> V_113 , & log -> V_112 ) )
return 0 ;
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
ASSERT ( V_63 -> V_71 == V_73 ||
V_63 -> V_71 == V_74 ) ;
if ( V_63 -> V_71 == V_74 ) {
T_6 V_138 = F_96 ( log -> V_147 ) ;
V_333 ++ ;
V_63 -> V_71 = V_325 ;
V_63 -> V_202 . V_334 = F_182 ( V_138 ) ;
F_192 ( log , V_63 , V_138 ) ;
}
F_15 ( & log -> V_112 ) ;
if ( V_333 )
return F_148 ( log , V_63 ) ;
return 0 ;
}
STATIC void
F_183 (
struct V_1 * log ,
struct V_62 * V_63 ,
int V_335 )
{
ASSERT ( V_63 -> V_71 == V_73 ) ;
if ( ! V_335 )
V_335 = V_63 -> V_93 ;
V_63 -> V_71 = V_74 ;
V_63 -> V_202 . V_336 = F_125 ( log -> V_185 ) ;
log -> V_185 = log -> V_332 ;
log -> V_337 = log -> V_186 ;
log -> V_332 += F_121 ( V_335 ) + F_121 ( log -> V_166 ) ;
if ( F_108 ( & log -> V_147 -> V_164 ) &&
log -> V_147 -> V_164 . V_249 > 1 ) {
T_13 V_338 = F_121 ( log -> V_147 -> V_164 . V_249 ) ;
log -> V_332 = F_193 ( log -> V_332 , V_338 ) ;
}
if ( log -> V_332 >= log -> V_184 ) {
log -> V_186 ++ ;
if ( log -> V_186 == V_204 )
log -> V_186 ++ ;
log -> V_332 -= log -> V_184 ;
ASSERT ( log -> V_332 >= 0 ) ;
}
ASSERT ( V_63 == log -> V_92 ) ;
log -> V_92 = V_63 -> V_94 ;
}
int
F_71 (
struct V_41 * V_42 ,
T_4 V_64 ,
int * V_339 )
{
struct V_1 * log = V_42 -> V_43 ;
struct V_62 * V_63 ;
T_6 V_65 ;
F_24 ( V_340 ) ;
F_194 ( log ) ;
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
if ( V_63 -> V_71 == V_73 ||
V_63 -> V_71 == V_114 ) {
if ( V_63 -> V_71 == V_114 ||
( F_149 ( & V_63 -> V_113 ) == 0
&& V_63 -> V_93 == 0 ) ) {
V_63 = V_63 -> V_196 ;
if ( V_63 -> V_71 == V_73 ||
V_63 -> V_71 == V_114 )
goto V_341;
else
goto V_342;
} else {
if ( F_149 ( & V_63 -> V_113 ) == 0 ) {
F_74 ( & V_63 -> V_113 ) ;
V_65 = F_154 ( V_63 -> V_202 . V_231 ) ;
F_183 ( log , V_63 , 0 ) ;
F_15 ( & log -> V_112 ) ;
if ( F_53 ( log , V_63 ) )
return F_30 ( V_29 ) ;
if ( V_339 )
* V_339 = 1 ;
F_12 ( & log -> V_112 ) ;
if ( F_154 ( V_63 -> V_202 . V_231 ) == V_65 &&
V_63 -> V_71 != V_114 )
goto V_342;
else
goto V_341;
} else {
F_183 ( log , V_63 , 0 ) ;
goto V_342;
}
}
}
V_342:
if ( V_64 & V_91 ) {
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
F_24 ( V_343 ) ;
F_76 ( & V_63 -> V_115 , & log -> V_112 ) ;
if ( V_63 -> V_71 & V_72 )
return F_30 ( V_29 ) ;
if ( V_339 )
* V_339 = 1 ;
} else {
V_341:
F_15 ( & log -> V_112 ) ;
}
return 0 ;
}
void
F_80 (
T_8 * V_42 ,
T_4 V_64 )
{
int error ;
F_195 ( V_42 , 0 ) ;
error = F_71 ( V_42 , V_64 , NULL ) ;
if ( error )
F_61 ( V_42 , L_88 , V_111 , error ) ;
}
int
F_196 (
struct V_41 * V_42 ,
T_6 V_65 ,
T_4 V_64 ,
int * V_339 )
{
struct V_1 * log = V_42 -> V_43 ;
struct V_62 * V_63 ;
int V_344 = 0 ;
ASSERT ( V_65 != 0 ) ;
F_24 ( V_340 ) ;
V_65 = F_197 ( log , V_65 ) ;
if ( V_65 == V_345 )
return 0 ;
V_346:
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
do {
if ( F_154 ( V_63 -> V_202 . V_231 ) != V_65 ) {
V_63 = V_63 -> V_94 ;
continue;
}
if ( V_63 -> V_71 == V_114 ) {
F_15 ( & log -> V_112 ) ;
return 0 ;
}
if ( V_63 -> V_71 == V_73 ) {
if ( ! V_344 &&
( V_63 -> V_196 -> V_71 &
( V_74 | V_325 ) ) ) {
ASSERT ( ! ( V_63 -> V_71 & V_72 ) ) ;
F_24 ( V_343 ) ;
F_76 ( & V_63 -> V_196 -> V_216 ,
& log -> V_112 ) ;
if ( V_339 )
* V_339 = 1 ;
V_344 = 1 ;
goto V_346;
}
F_74 ( & V_63 -> V_113 ) ;
F_183 ( log , V_63 , 0 ) ;
F_15 ( & log -> V_112 ) ;
if ( F_53 ( log , V_63 ) )
return F_30 ( V_29 ) ;
if ( V_339 )
* V_339 = 1 ;
F_12 ( & log -> V_112 ) ;
}
if ( ( V_64 & V_91 ) &&
! ( V_63 -> V_71 &
( V_73 | V_114 ) ) ) {
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
F_24 ( V_343 ) ;
F_76 ( & V_63 -> V_115 , & log -> V_112 ) ;
if ( V_63 -> V_71 & V_72 )
return F_30 ( V_29 ) ;
if ( V_339 )
* V_339 = 1 ;
} else {
F_15 ( & log -> V_112 ) ;
}
return 0 ;
} while ( V_63 != log -> V_92 );
F_15 ( & log -> V_112 ) ;
return 0 ;
}
void
F_198 (
T_8 * V_42 ,
T_6 V_65 ,
T_4 V_64 )
{
int error ;
F_195 ( V_42 , V_65 ) ;
error = F_196 ( V_42 , V_65 , V_64 , NULL ) ;
if ( error )
F_61 ( V_42 , L_88 , V_111 , error ) ;
}
STATIC void
F_75 (
struct V_1 * log ,
struct V_62 * V_63 )
{
F_93 ( & log -> V_112 ) ;
if ( V_63 -> V_71 == V_73 ) {
F_183 ( log , V_63 , 0 ) ;
} else {
ASSERT ( V_63 -> V_71 &
( V_74 | V_72 ) ) ;
}
}
void
F_47 (
T_3 * V_61 )
{
ASSERT ( F_149 ( & V_61 -> V_347 ) > 0 ) ;
if ( F_199 ( & V_61 -> V_347 ) )
F_200 ( V_348 , V_61 ) ;
}
T_3 *
F_201 (
T_3 * V_61 )
{
ASSERT ( F_149 ( & V_61 -> V_347 ) > 0 ) ;
F_74 ( & V_61 -> V_347 ) ;
return V_61 ;
}
struct V_15 *
F_40 (
struct V_1 * log ,
int V_48 ,
int V_49 ,
char V_51 ,
bool V_52 ,
T_19 V_349 )
{
struct V_15 * V_16 ;
T_4 V_350 ;
int V_351 ;
V_16 = F_202 ( V_348 , V_349 ) ;
if ( ! V_16 )
return NULL ;
V_48 += sizeof( V_266 ) ;
V_48 += sizeof( V_352 ) ;
V_48 += sizeof( V_266 ) ;
V_351 = log -> V_162 - log -> V_166 ;
V_350 = F_203 ( V_48 , V_351 ) ;
V_48 += sizeof( V_266 ) * V_350 ;
while ( ! V_350 ||
F_203 ( V_48 , V_351 ) > V_350 ) {
V_48 += sizeof( V_266 ) ;
V_350 ++ ;
}
V_48 += log -> V_166 * V_350 ;
V_48 += log -> V_166 ;
if ( F_108 ( & log -> V_147 -> V_164 ) &&
log -> V_147 -> V_164 . V_249 > 1 ) {
V_48 += 2 * log -> V_147 -> V_164 . V_249 ;
} else {
V_48 += 2 * V_170 ;
}
F_126 ( & V_16 -> V_347 , 1 ) ;
V_16 -> V_17 = V_353 ;
F_9 ( & V_16 -> V_25 ) ;
V_16 -> V_21 = V_48 ;
V_16 -> V_46 = V_48 ;
V_16 -> V_22 = V_49 ;
V_16 -> V_354 = V_49 ;
V_16 -> V_45 = F_204 () ;
V_16 -> V_282 = V_51 ;
V_16 -> V_19 = V_66 ;
V_16 -> V_59 = 0 ;
if ( V_52 )
V_16 -> V_19 |= V_20 ;
F_33 ( V_16 ) ;
return V_16 ;
}
void
F_177 (
struct V_1 * log ,
char * V_306 )
{
int V_180 ;
int V_355 = 0 ;
for ( V_180 = 0 ; V_180 < log -> V_159 ; V_180 ++ ) {
if ( V_306 >= log -> V_200 [ V_180 ] &&
V_306 <= log -> V_200 [ V_180 ] + log -> V_162 )
V_355 ++ ;
}
if ( ! V_355 )
F_205 ( log -> V_147 , L_89 , V_111 ) ;
}
STATIC void
F_38 (
struct V_1 * log )
{
int V_144 , V_356 ;
int V_7 , V_8 ;
F_97 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_98 ( & log -> V_142 , & V_144 , & V_356 ) ;
if ( V_144 != V_7 ) {
if ( V_7 - 1 != V_144 &&
! ( log -> V_30 & V_357 ) ) {
F_169 ( log -> V_147 , V_271 ,
L_90 , V_111 ) ;
log -> V_30 |= V_357 ;
}
if ( V_8 > F_99 ( V_356 ) &&
! ( log -> V_30 & V_357 ) ) {
F_169 ( log -> V_147 , V_271 ,
L_91 , V_111 ) ;
log -> V_30 |= V_357 ;
}
}
}
STATIC void
F_192 (
struct V_1 * log ,
struct V_62 * V_63 ,
T_6 V_138 )
{
int V_358 ;
if ( F_206 ( V_138 ) == log -> V_337 ) {
V_358 =
log -> V_184 - ( log -> V_185 - F_153 ( V_138 ) ) ;
if ( V_358 < F_121 ( V_63 -> V_93 ) + F_121 ( log -> V_166 ) )
F_205 ( log -> V_147 , L_92 , V_111 ) ;
} else {
ASSERT ( F_206 ( V_138 ) + 1 == log -> V_337 ) ;
if ( F_153 ( V_138 ) == log -> V_185 )
F_205 ( log -> V_147 , L_93 , V_111 ) ;
V_358 = F_153 ( V_138 ) - log -> V_185 ;
if ( V_358 < F_121 ( V_63 -> V_93 ) + 1 )
F_205 ( log -> V_147 , L_92 , V_111 ) ;
}
}
STATIC void
F_161 (
struct V_1 * log ,
struct V_62 * V_63 ,
int V_244 ,
T_20 V_359 )
{
V_266 * V_360 ;
T_11 * V_361 ;
T_17 * V_233 ;
V_201 V_306 ;
V_201 V_362 ;
T_21 V_363 ;
T_5 V_364 ;
int V_35 , V_180 , V_227 , V_228 , V_365 ;
int V_366 ;
F_12 ( & log -> V_112 ) ;
V_361 = log -> V_92 ;
for ( V_180 = 0 ; V_180 < log -> V_159 ; V_180 ++ ) {
if ( V_361 == NULL )
F_205 ( log -> V_147 , L_89 , V_111 ) ;
V_361 = V_361 -> V_94 ;
}
if ( V_361 != log -> V_92 )
F_205 ( log -> V_147 , L_94 , V_111 ) ;
F_15 ( & log -> V_112 ) ;
if ( V_63 -> V_202 . V_203 != F_125 ( V_204 ) )
F_205 ( log -> V_147 , L_95 , V_111 ) ;
V_306 = ( V_201 ) & V_63 -> V_202 ;
for ( V_306 += V_170 ; V_306 < ( ( V_201 ) & V_63 -> V_202 ) + V_244 ;
V_306 += V_170 ) {
if ( * ( T_16 * ) V_306 == F_125 ( V_204 ) )
F_205 ( log -> V_147 , L_96 ,
V_111 ) ;
}
V_35 = F_157 ( V_63 -> V_202 . V_264 ) ;
V_306 = V_63 -> V_215 ;
V_362 = V_306 ;
V_360 = ( V_266 * ) V_306 ;
V_233 = V_63 -> V_198 ;
for ( V_180 = 0 ; V_180 < V_35 ; V_180 ++ ) {
V_360 = ( V_266 * ) V_306 ;
V_363 = ( T_21 )
( ( V_201 ) & ( V_360 -> V_281 ) - V_362 ) ;
if ( V_359 == V_367 || ( V_363 & 0x1ff ) ) {
V_364 = V_360 -> V_281 ;
} else {
V_366 = F_132 ( ( V_201 ) & ( V_360 -> V_281 ) - V_63 -> V_215 ) ;
if ( V_366 >= ( V_165 / V_170 ) ) {
V_227 = V_366 / ( V_165 / V_170 ) ;
V_228 = V_366 % ( V_165 / V_170 ) ;
V_364 = F_207 (
V_233 [ V_227 ] . V_234 . V_235 [ V_228 ] ) ;
} else {
V_364 = F_207 (
V_63 -> V_202 . V_232 [ V_366 ] ) ;
}
}
if ( V_364 != V_54 && V_364 != V_55 )
F_61 ( log -> V_147 ,
L_97 ,
V_111 , V_364 , V_360 ,
( unsigned long ) V_363 ) ;
V_363 = ( T_21 )
( ( V_201 ) & ( V_360 -> V_283 ) - V_362 ) ;
if ( V_359 == V_367 || ( V_363 & 0x1ff ) ) {
V_365 = F_157 ( V_360 -> V_283 ) ;
} else {
V_366 = F_132 ( ( T_21 ) & V_360 -> V_283 -
( T_21 ) V_63 -> V_215 ) ;
if ( V_366 >= ( V_165 / V_170 ) ) {
V_227 = V_366 / ( V_165 / V_170 ) ;
V_228 = V_366 % ( V_165 / V_170 ) ;
V_365 = F_157 ( V_233 [ V_227 ] . V_234 . V_235 [ V_228 ] ) ;
} else {
V_365 = F_157 ( V_63 -> V_202 . V_232 [ V_366 ] ) ;
}
}
V_306 += sizeof( V_266 ) + V_365 ;
}
}
STATIC int
F_208 (
struct V_1 * log )
{
T_11 * V_63 , * V_368 ;
V_63 = log -> V_92 ;
if ( ! ( V_63 -> V_71 & V_72 ) ) {
V_368 = V_63 ;
do {
V_368 -> V_71 = V_72 ;
V_368 = V_368 -> V_94 ;
} while ( V_368 != V_63 );
return 0 ;
}
return 1 ;
}
int
F_209 (
struct V_41 * V_42 ,
int V_369 )
{
struct V_1 * log ;
int V_370 ;
log = V_42 -> V_43 ;
if ( ! log ||
log -> V_30 & V_31 ) {
V_42 -> V_81 |= V_371 ;
if ( V_42 -> V_118 )
F_210 ( V_42 -> V_118 ) ;
return 0 ;
}
if ( V_369 && log -> V_92 -> V_71 & V_72 ) {
ASSERT ( F_21 ( log ) ) ;
return 1 ;
}
V_370 = 0 ;
if ( ! V_369 )
F_194 ( log ) ;
F_12 ( & log -> V_112 ) ;
V_42 -> V_81 |= V_371 ;
if ( V_42 -> V_118 )
F_210 ( V_42 -> V_118 ) ;
log -> V_30 |= V_372 ;
if ( V_369 )
V_370 = F_208 ( log ) ;
F_15 ( & log -> V_112 ) ;
F_11 ( & log -> V_60 ) ;
F_11 ( & log -> V_18 ) ;
if ( ! ( log -> V_92 -> V_71 & V_72 ) ) {
ASSERT ( ! V_369 ) ;
F_71 ( V_42 , V_91 , NULL ) ;
F_12 ( & log -> V_112 ) ;
V_370 = F_208 ( log ) ;
F_15 ( & log -> V_112 ) ;
}
F_180 ( log , V_155 , NULL ) ;
#ifdef F_211
{
T_11 * V_63 ;
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
do {
ASSERT ( V_63 -> V_214 == 0 ) ;
V_63 = V_63 -> V_94 ;
} while ( V_63 != log -> V_92 );
F_15 ( & log -> V_112 ) ;
}
#endif
return V_370 ;
}
STATIC int
F_91 (
struct V_1 * log )
{
T_11 * V_63 ;
V_63 = log -> V_92 ;
do {
if ( V_63 -> V_202 . V_264 )
return 0 ;
V_63 = V_63 -> V_94 ;
} while ( V_63 != log -> V_92 );
return 1 ;
}
