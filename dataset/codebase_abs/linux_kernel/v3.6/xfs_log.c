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
struct V_1 * log = V_42 -> V_43 ;
T_11 * V_63 ;
#ifdef F_69
T_11 * V_90 ;
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
struct V_1 * log = V_42 -> V_43 ;
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
F_93 ( T_14 * V_146 )
{
struct V_62 * V_63 = V_146 -> V_147 ;
struct V_1 * V_148 = V_63 -> V_149 ;
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
F_100 (
struct V_41 * V_42 ,
struct V_1 * log )
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
STATIC struct V_1 *
F_57 (
struct V_41 * V_42 ,
struct V_171 * V_78 ,
T_10 V_79 ,
int V_80 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_172 ;
T_11 * V_63 , * V_173 = NULL ;
T_14 * V_146 ;
int V_174 ;
int error = V_58 ;
T_4 V_175 = 0 ;
log = F_102 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! log ) {
F_61 ( V_42 , L_9 ) ;
goto V_84;
}
log -> V_145 = V_42 ;
log -> V_176 = V_78 ;
log -> V_9 = F_92 ( V_80 ) ;
log -> V_177 = V_79 ;
log -> V_178 = V_80 ;
log -> V_129 = V_132 ;
log -> V_30 |= V_31 ;
log -> V_179 = - 1 ;
F_103 ( & log -> V_140 , 1 , 0 ) ;
F_103 ( & log -> V_139 , 1 , 0 ) ;
log -> V_180 = 1 ;
F_7 ( & log -> V_60 ) ;
F_7 ( & log -> V_18 ) ;
error = V_181 ;
if ( F_104 ( & V_42 -> V_162 ) ) {
V_175 = V_42 -> V_162 . V_182 ;
if ( V_175 < V_165 ) {
F_61 ( V_42 , L_10 ,
V_175 , V_165 ) ;
goto V_85;
}
V_175 -= V_165 ;
if ( V_175 > V_42 -> V_183 ) {
F_61 ( V_42 , L_11 ,
V_175 , V_42 -> V_183 ) ;
goto V_85;
}
if ( V_175 && log -> V_177 > 0 &&
! F_101 ( & V_42 -> V_162 ) ) {
F_61 ( V_42 ,
L_12 ,
V_175 ) ;
goto V_85;
}
}
log -> V_184 = 1 << V_175 ;
F_100 ( V_42 , log ) ;
error = V_58 ;
V_146 = F_105 ( V_42 -> V_185 , 0 , F_106 ( log -> V_160 ) , 0 ) ;
if ( ! V_146 )
goto V_85;
V_146 -> V_186 = F_93 ;
ASSERT ( F_107 ( V_146 ) ) ;
log -> V_187 = V_146 ;
F_10 ( & log -> V_112 ) ;
F_108 ( & log -> V_188 ) ;
V_172 = & log -> V_92 ;
ASSERT ( log -> V_160 >= 4096 ) ;
for ( V_174 = 0 ; V_174 < log -> V_157 ; V_174 ++ ) {
* V_172 = F_102 ( sizeof( T_11 ) , V_57 ) ;
if ( ! * V_172 )
goto V_189;
V_63 = * V_172 ;
V_63 -> V_190 = V_173 ;
V_173 = V_63 ;
V_146 = F_109 ( V_42 -> V_185 ,
F_106 ( log -> V_160 ) , 0 ) ;
if ( ! V_146 )
goto V_189;
V_146 -> V_186 = F_93 ;
V_63 -> V_191 = V_146 ;
V_63 -> V_192 = V_146 -> V_193 ;
#ifdef F_69
log -> V_194 [ V_174 ] = ( V_195 ) & ( V_63 -> V_196 ) ;
#endif
V_2 = & V_63 -> V_196 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_197 = F_110 ( V_198 ) ;
V_2 -> V_199 = F_110 (
F_101 ( & log -> V_145 -> V_162 ) ? 2 : 1 ) ;
V_2 -> V_200 = F_110 ( log -> V_160 ) ;
V_2 -> V_201 = F_110 ( V_202 ) ;
memcpy ( & V_2 -> V_203 , & V_42 -> V_162 . V_204 , sizeof( V_205 ) ) ;
V_63 -> V_206 = F_92 ( V_146 -> V_207 ) - log -> V_164 ;
V_63 -> V_71 = V_73 ;
V_63 -> V_149 = log ;
F_111 ( & V_63 -> V_113 , 0 ) ;
F_10 ( & V_63 -> V_70 ) ;
V_63 -> V_76 = & ( V_63 -> V_208 ) ;
V_63 -> V_209 = ( char * ) V_63 -> V_192 + log -> V_164 ;
ASSERT ( F_107 ( V_63 -> V_191 ) ) ;
F_108 ( & V_63 -> V_115 ) ;
F_108 ( & V_63 -> V_210 ) ;
V_172 = & V_63 -> V_94 ;
}
* V_172 = log -> V_92 ;
log -> V_92 -> V_190 = V_173 ;
error = F_112 ( log ) ;
if ( error )
goto V_189;
return log ;
V_189:
for ( V_63 = log -> V_92 ; V_63 ; V_63 = V_173 ) {
V_173 = V_63 -> V_94 ;
if ( V_63 -> V_191 )
F_113 ( V_63 -> V_191 ) ;
F_114 ( V_63 ) ;
}
F_115 ( & log -> V_112 ) ;
F_113 ( log -> V_187 ) ;
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
T_6 * V_211 )
{
struct V_41 * V_42 = log -> V_145 ;
int error ;
struct V_100 V_101 = {
. V_102 = NULL ,
. V_103 = 0 ,
. V_104 = V_212 ,
} ;
struct V_106 V_107 = {
. V_108 = 1 ,
. V_109 = & V_101 ,
} ;
F_51 ( V_63 ) ;
error = F_71 ( log , & V_107 , V_61 , V_211 , V_63 ,
V_213 ) ;
if ( error )
F_54 ( V_42 , V_77 ) ;
return error ;
}
STATIC void
F_22 (
struct V_1 * log ,
int V_24 )
{
T_6 V_214 = 0 ;
T_6 V_215 ;
int V_216 ;
int V_23 ;
int V_217 ;
int V_218 ;
int V_219 ;
ASSERT ( F_106 ( V_24 ) < log -> V_178 ) ;
V_23 = F_28 ( log , & log -> V_60 . V_12 ) ;
V_216 = F_117 ( V_23 ) ;
V_219 = F_106 ( V_24 ) ;
V_219 = F_118 ( V_219 , ( log -> V_178 >> 2 ) ) ;
V_219 = F_118 ( V_219 , 256 ) ;
if ( V_216 >= V_219 )
return;
F_91 ( & log -> V_140 , & V_218 ,
& V_217 ) ;
V_217 += V_219 ;
if ( V_217 >= log -> V_178 ) {
V_217 -= log -> V_178 ;
V_218 += 1 ;
}
V_214 = F_119 ( V_218 ,
V_217 ) ;
V_215 = F_2 ( & log -> V_139 ) ;
if ( F_120 ( V_214 , V_215 ) > 0 )
V_214 = V_215 ;
if ( ! F_21 ( log ) )
F_121 ( log -> V_86 , V_214 ) ;
}
STATIC int
F_122 (
struct V_220 * V_146 )
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
F_126 (
struct V_1 * log ,
struct V_62 * V_63 )
{
V_195 V_221 ;
T_14 * V_146 ;
int V_174 ;
T_4 V_222 ;
T_4 V_223 ;
int V_224 ;
int V_225 = 0 ;
int error ;
int V_226 = F_101 ( & log -> V_145 -> V_162 ) ;
F_24 ( V_227 ) ;
ASSERT ( F_127 ( & V_63 -> V_113 ) == 0 ) ;
V_223 = log -> V_164 + V_63 -> V_93 ;
if ( V_226 && log -> V_145 -> V_162 . V_228 > 1 ) {
V_222 = F_128 ( log , F_129 ( log , V_223 ) ) ;
} else {
V_222 = F_92 ( F_106 ( V_223 ) ) ;
}
V_224 = V_222 - V_223 ;
ASSERT ( V_224 >= 0 ) ;
ASSERT ( ( V_226 && log -> V_145 -> V_162 . V_228 > 1 &&
V_224 < log -> V_145 -> V_162 . V_228 )
||
( log -> V_145 -> V_162 . V_228 <= 1 &&
V_224 < F_92 ( 1 ) ) ) ;
F_6 ( log , & log -> V_60 . V_12 , V_224 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_224 ) ;
F_130 ( log , V_63 , V_224 ) ;
if ( V_226 ) {
V_63 -> V_196 . V_229 =
F_110 ( V_63 -> V_93 + V_224 ) ;
} else {
V_63 -> V_196 . V_229 =
F_110 ( V_63 -> V_93 ) ;
}
V_146 = V_63 -> V_191 ;
F_131 ( V_146 , F_132 ( F_133 ( V_63 -> V_196 . V_230 ) ) ) ;
F_134 ( V_231 , F_106 ( V_222 ) ) ;
if ( F_135 ( V_146 ) + F_106 ( V_222 ) > log -> V_178 ) {
V_225 = V_222 - ( F_92 ( log -> V_178 - F_135 ( V_146 ) ) ) ;
V_222 = F_92 ( log -> V_178 - F_135 ( V_146 ) ) ;
V_63 -> V_232 = 2 ;
} else {
V_63 -> V_232 = 1 ;
}
V_146 -> V_233 = F_106 ( V_222 ) ;
V_146 -> V_147 = V_63 ;
F_136 ( V_146 ) ;
F_137 ( V_146 ) ;
V_146 -> V_234 |= V_235 ;
if ( log -> V_145 -> V_81 & V_236 ) {
V_146 -> V_234 |= V_237 ;
if ( log -> V_145 -> V_185 != log -> V_145 -> V_238 )
F_138 ( log -> V_145 -> V_238 ) ;
else
V_146 -> V_234 |= V_239 ;
}
ASSERT ( F_135 ( V_146 ) <= log -> V_178 - 1 ) ;
ASSERT ( F_135 ( V_146 ) + F_106 ( V_222 ) <= log -> V_178 ) ;
F_139 ( log , V_63 , V_222 , V_240 ) ;
F_131 ( V_146 , F_135 ( V_146 ) + log -> V_177 ) ;
F_140 ( V_146 ) ;
error = F_122 ( V_146 ) ;
if ( error ) {
F_96 ( V_146 , L_13 ) ;
return error ;
}
if ( V_225 ) {
V_146 = V_63 -> V_149 -> V_187 ;
F_131 ( V_146 , 0 ) ;
F_141 ( V_146 ,
( char * ) & V_63 -> V_196 + V_222 , V_225 ) ;
V_146 -> V_147 = V_63 ;
F_136 ( V_146 ) ;
F_137 ( V_146 ) ;
V_146 -> V_234 |= V_235 ;
if ( log -> V_145 -> V_81 & V_236 )
V_146 -> V_234 |= V_237 ;
V_221 = V_146 -> V_193 ;
for ( V_174 = 0 ; V_174 < V_225 ; V_174 += V_168 ) {
F_142 ( ( V_241 * ) V_221 , 1 ) ;
if ( F_143 ( * ( V_241 * ) V_221 ) == V_198 )
F_142 ( ( V_241 * ) V_221 , 1 ) ;
V_221 += V_168 ;
}
ASSERT ( F_135 ( V_146 ) <= log -> V_178 - 1 ) ;
ASSERT ( F_135 ( V_146 ) + F_106 ( V_222 ) <= log -> V_178 ) ;
F_131 ( V_146 , F_135 ( V_146 ) + log -> V_177 ) ;
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
F_65 (
struct V_1 * log )
{
T_11 * V_63 , * V_242 ;
int V_174 ;
F_144 ( log ) ;
F_145 ( log -> V_187 , F_106 ( log -> V_160 ) ) ;
F_113 ( log -> V_187 ) ;
V_63 = log -> V_92 ;
for ( V_174 = 0 ; V_174 < log -> V_157 ; V_174 ++ ) {
F_113 ( V_63 -> V_191 ) ;
V_242 = V_63 -> V_94 ;
F_114 ( V_63 ) ;
V_63 = V_242 ;
}
F_115 ( & log -> V_112 ) ;
log -> V_145 -> V_43 = NULL ;
F_114 ( log ) ;
}
static inline void
F_146 (
struct V_1 * log ,
struct V_62 * V_63 ,
int V_243 ,
int V_244 )
{
F_12 ( & log -> V_112 ) ;
F_142 ( & V_63 -> V_196 . V_245 , V_243 ) ;
V_63 -> V_93 += V_244 ;
F_15 ( & log -> V_112 ) ;
}
void
F_147 (
struct V_41 * V_42 ,
struct V_15 * V_61 )
{
T_4 V_174 ;
T_4 V_246 = V_61 -> V_34 * ( T_4 ) sizeof( V_247 ) ;
static char * V_248 [ V_249 ] = {
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
static char * V_250 [ V_251 ] = {
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
V_61 -> V_59 > V_251 ) ?
L_82 : V_250 [ V_61 -> V_59 - 1 ] ) ,
V_61 -> V_59 ,
V_61 -> V_21 ,
V_61 -> V_46 ,
V_61 -> V_33 , V_61 -> V_37 ,
V_61 -> V_34 , V_246 ,
V_61 -> V_33 +
V_61 -> V_37 + V_246 ,
V_61 -> V_32 ) ;
for ( V_174 = 0 ; V_174 < V_61 -> V_32 ; V_174 ++ ) {
T_4 V_40 = V_61 -> V_38 [ V_174 ] . V_40 ;
F_61 ( V_42 , L_83 , V_174 ,
( ( V_40 <= 0 || V_40 > V_249 ) ?
L_84 : V_248 [ V_40 - 1 ] ) ,
V_61 -> V_38 [ V_174 ] . V_39 ) ;
}
F_148 ( V_42 , V_252 ,
L_85 ) ;
F_54 ( V_42 , V_253 ) ;
}
static int
F_149 (
struct V_15 * V_61 ,
struct V_106 * V_254 )
{
struct V_106 * V_255 ;
int V_256 = 0 ;
int V_35 = 0 ;
int V_174 ;
if ( V_61 -> V_19 & V_66 )
V_256 ++ ;
for ( V_255 = V_254 ; V_255 ; V_255 = V_255 -> V_257 ) {
V_256 += V_255 -> V_108 ;
for ( V_174 = 0 ; V_174 < V_255 -> V_108 ; V_174 ++ ) {
struct V_100 * V_258 = & V_255 -> V_109 [ V_174 ] ;
V_35 += V_258 -> V_103 ;
F_34 ( V_61 , V_258 -> V_103 , V_258 -> V_104 ) ;
}
}
V_61 -> V_34 += V_256 ;
V_35 += V_256 * sizeof( struct V_259 ) ;
return V_35 ;
}
static int
F_150 (
struct V_259 * V_260 ,
struct V_15 * V_61 )
{
if ( ! ( V_61 -> V_19 & V_66 ) )
return 0 ;
V_260 -> V_261 = F_110 ( V_61 -> V_45 ) ;
V_260 -> V_262 = V_61 -> V_263 ;
V_260 -> V_264 = 0 ;
V_260 -> V_265 = V_266 ;
V_260 -> V_267 = 0 ;
V_61 -> V_19 &= ~ V_66 ;
return sizeof( struct V_259 ) ;
}
static V_247 *
F_151 (
struct V_1 * log ,
struct V_259 * V_260 ,
struct V_15 * V_61 ,
T_4 V_64 )
{
V_260 -> V_261 = F_110 ( V_61 -> V_45 ) ;
V_260 -> V_262 = V_61 -> V_263 ;
V_260 -> V_267 = 0 ;
V_260 -> V_265 = V_64 ;
switch ( V_260 -> V_262 ) {
case V_54 :
case V_268 :
case V_55 :
break;
default:
F_61 ( log -> V_145 ,
L_86 ,
V_260 -> V_262 , V_61 ) ;
return NULL ;
}
return V_260 ;
}
static int
F_152 (
struct V_15 * V_61 ,
struct V_259 * V_260 ,
int V_269 ,
int V_270 ,
int * V_271 ,
int * V_272 ,
int * V_273 ,
int * V_274 )
{
int V_275 ;
V_275 = V_270 - * V_274 ;
* V_271 = * V_274 ;
if ( V_275 <= V_269 ) {
* V_272 = V_275 ;
V_260 -> V_264 = F_110 ( * V_272 ) ;
if ( * V_273 )
V_260 -> V_265 |= ( V_276 | V_277 ) ;
* V_273 = 0 ;
* V_274 = 0 ;
return 0 ;
}
* V_272 = V_269 ;
V_260 -> V_264 = F_110 ( * V_272 ) ;
V_260 -> V_265 |= V_278 ;
if ( * V_273 )
V_260 -> V_265 |= V_277 ;
* V_274 += * V_272 ;
( * V_273 ) ++ ;
V_61 -> V_46 -= sizeof( struct V_259 ) ;
V_61 -> V_34 ++ ;
return sizeof( struct V_259 ) ;
}
static int
F_153 (
struct V_1 * log ,
struct V_62 * V_63 ,
T_4 V_64 ,
int * V_243 ,
int * V_279 ,
int * V_280 ,
int * V_281 ,
int V_282 ,
struct V_62 * * V_283 )
{
if ( * V_280 ) {
F_146 ( log , V_63 , * V_243 , * V_279 ) ;
* V_243 = 0 ;
* V_279 = 0 ;
return F_53 ( log , V_63 ) ;
}
* V_280 = 0 ;
* V_281 = 0 ;
if ( V_63 -> V_206 - V_282 <= sizeof( V_247 ) ) {
F_146 ( log , V_63 , * V_243 , * V_279 ) ;
* V_243 = 0 ;
* V_279 = 0 ;
F_12 ( & log -> V_112 ) ;
F_74 ( log , V_63 ) ;
F_15 ( & log -> V_112 ) ;
if ( ! V_283 )
return F_53 ( log , V_63 ) ;
ASSERT ( V_64 & V_213 ) ;
* V_283 = V_63 ;
}
return 0 ;
}
int
F_71 (
struct V_1 * log ,
struct V_106 * V_254 ,
struct V_15 * V_61 ,
T_6 * V_284 ,
struct V_62 * * V_283 ,
T_4 V_64 )
{
struct V_62 * V_63 = NULL ;
struct V_100 * V_258 ;
struct V_106 * V_255 ;
int V_35 ;
int V_285 ;
int V_280 = 0 ;
int V_281 = 0 ;
int V_286 = 0 ;
int V_243 = 0 ;
int V_279 = 0 ;
int error ;
* V_284 = 0 ;
V_35 = F_149 ( V_61 , V_254 ) ;
if ( V_61 -> V_19 & V_66 )
V_61 -> V_46 -= sizeof( V_247 ) ;
if ( V_64 & ( V_213 | V_110 ) )
V_61 -> V_46 -= sizeof( V_247 ) ;
if ( V_61 -> V_46 < 0 )
F_147 ( log -> V_145 , V_61 ) ;
V_285 = 0 ;
V_255 = V_254 ;
V_258 = V_255 -> V_109 ;
while ( V_255 && V_285 < V_255 -> V_108 ) {
void * V_287 ;
int V_282 ;
error = F_154 ( log , V_35 , & V_63 , V_61 ,
& V_286 , & V_282 ) ;
if ( error )
return error ;
ASSERT ( V_282 <= V_63 -> V_206 - 1 ) ;
V_287 = V_63 -> V_209 + V_282 ;
if ( ! * V_284 )
* V_284 = F_133 ( V_63 -> V_196 . V_230 ) ;
while ( V_255 && V_285 < V_255 -> V_108 ) {
struct V_100 * V_101 = & V_258 [ V_285 ] ;
struct V_259 * V_260 ;
int V_288 ;
int V_272 ;
int V_271 ;
ASSERT ( V_101 -> V_103 % sizeof( V_289 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_287 % sizeof( V_289 ) == 0 ) ;
V_288 = F_150 ( V_287 , V_61 ) ;
if ( V_288 ) {
V_243 ++ ;
F_155 ( & V_287 , & V_35 , & V_282 ,
V_288 ) ;
}
V_260 = F_151 ( log , V_287 , V_61 , V_64 ) ;
if ( ! V_260 )
return F_30 ( V_29 ) ;
F_155 ( & V_287 , & V_35 , & V_282 ,
sizeof( struct V_259 ) ) ;
V_35 += F_152 ( V_61 , V_260 ,
V_63 -> V_206 - V_282 ,
V_101 -> V_103 ,
& V_271 , & V_272 ,
& V_280 ,
& V_281 ) ;
F_156 ( log , V_287 ) ;
ASSERT ( V_272 >= 0 ) ;
memcpy ( V_287 , V_101 -> V_102 + V_271 , V_272 ) ;
F_155 ( & V_287 , & V_35 , & V_282 , V_272 ) ;
V_272 += V_288 + sizeof( V_247 ) ;
V_243 ++ ;
V_279 += V_286 ? V_272 : 0 ;
error = F_153 ( log , V_63 , V_64 ,
& V_243 , & V_279 ,
& V_280 ,
& V_281 ,
V_282 ,
V_283 ) ;
if ( error )
return error ;
if ( V_280 )
break;
if ( ++ V_285 == V_255 -> V_108 ) {
V_255 = V_255 -> V_257 ;
V_285 = 0 ;
if ( V_255 )
V_258 = V_255 -> V_109 ;
}
if ( V_243 == 0 ) {
if ( ! V_255 )
return 0 ;
break;
}
}
}
ASSERT ( V_35 == 0 ) ;
F_146 ( log , V_63 , V_243 , V_279 ) ;
if ( ! V_283 )
return F_53 ( log , V_63 ) ;
ASSERT ( V_64 & V_213 ) ;
* V_283 = V_63 ;
return 0 ;
}
STATIC void
F_157 (
struct V_1 * log )
{
T_11 * V_63 ;
int V_290 = 0 ;
V_63 = log -> V_92 ;
do {
if ( V_63 -> V_71 == V_114 ) {
V_63 -> V_71 = V_73 ;
V_63 -> V_93 = 0 ;
ASSERT ( V_63 -> V_208 == NULL ) ;
if ( ! V_290 &&
( F_143 ( V_63 -> V_196 . V_245 ) ==
V_291 ) ) {
V_290 = 1 ;
} else {
V_290 = 2 ;
}
V_63 -> V_196 . V_245 = 0 ;
memset ( V_63 -> V_196 . V_292 , 0 ,
sizeof( V_63 -> V_196 . V_292 ) ) ;
V_63 -> V_196 . V_230 = 0 ;
} else if ( V_63 -> V_71 == V_73 )
;
else
break;
V_63 = V_63 -> V_94 ;
} while ( V_63 != log -> V_92 );
if ( V_290 ) {
switch ( log -> V_129 ) {
case V_132 :
case V_133 :
case V_134 :
log -> V_129 = V_133 ;
break;
case V_130 :
if ( V_290 == 1 )
log -> V_129 = V_134 ;
else
log -> V_129 = V_133 ;
break;
case V_131 :
if ( V_290 == 1 )
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
struct V_1 * log )
{
T_11 * V_293 ;
T_6 V_294 , V_65 ;
V_293 = log -> V_92 ;
V_294 = 0 ;
do {
if ( ! ( V_293 -> V_71 & ( V_73 | V_114 ) ) ) {
V_65 = F_133 ( V_293 -> V_196 . V_230 ) ;
if ( ( V_65 && ! V_294 ) ||
( F_120 ( V_65 , V_294 ) < 0 ) ) {
V_294 = V_65 ;
}
}
V_293 = V_293 -> V_94 ;
} while ( V_293 != log -> V_92 );
return V_294 ;
}
STATIC void
F_159 (
struct V_1 * log ,
int V_150 ,
struct V_62 * V_295 )
{
T_11 * V_63 ;
T_11 * V_90 ;
T_7 * V_68 , * V_75 ;
int V_296 = 0 ;
T_6 V_294 ;
int V_297 ;
int V_298 ;
int V_299 ;
int V_300 ;
int V_301 = 0 ;
F_12 ( & log -> V_112 ) ;
V_90 = V_63 = log -> V_92 ;
V_297 = 0 ;
V_299 = 0 ;
V_300 = 0 ;
do {
V_90 = log -> V_92 ;
V_63 = log -> V_92 ;
V_298 = 0 ;
V_300 ++ ;
do {
if ( V_63 -> V_71 &
( V_73 | V_114 ) ) {
V_63 = V_63 -> V_94 ;
continue;
}
if ( ! ( V_63 -> V_71 & V_72 ) ) {
if ( ! ( V_63 -> V_71 &
( V_302 |
V_303 ) ) ) {
if ( V_295 && ( V_295 -> V_71 ==
V_302 ) ) {
V_295 -> V_71 = V_303 ;
}
break;
}
V_294 = F_158 ( log ) ;
if ( V_294 &&
F_120 ( V_294 ,
F_133 ( V_63 -> V_196 . V_230 ) ) < 0 ) {
V_63 = V_63 -> V_94 ;
continue;
}
V_63 -> V_71 = V_304 ;
ASSERT ( F_120 ( F_2 ( & log -> V_139 ) ,
F_133 ( V_63 -> V_196 . V_230 ) ) <= 0 ) ;
F_88 ( & log -> V_139 ,
F_133 ( V_63 -> V_196 . V_230 ) ) ;
} else
V_297 ++ ;
F_15 ( & log -> V_112 ) ;
F_12 ( & V_63 -> V_70 ) ;
V_68 = V_63 -> V_208 ;
while ( V_68 ) {
V_63 -> V_76 = & ( V_63 -> V_208 ) ;
V_63 -> V_208 = NULL ;
F_15 ( & V_63 -> V_70 ) ;
for (; V_68 ; V_68 = V_75 ) {
V_75 = V_68 -> V_75 ;
V_68 -> V_305 ( V_68 -> V_306 , V_150 ) ;
}
F_12 ( & V_63 -> V_70 ) ;
V_68 = V_63 -> V_208 ;
}
V_298 ++ ;
V_299 ++ ;
F_12 ( & log -> V_112 ) ;
ASSERT ( V_63 -> V_208 == NULL ) ;
F_15 ( & V_63 -> V_70 ) ;
if ( ! ( V_63 -> V_71 & V_72 ) )
V_63 -> V_71 = V_114 ;
F_157 ( log ) ;
F_160 ( & V_63 -> V_115 ) ;
V_63 = V_63 -> V_94 ;
} while ( V_90 != V_63 );
if ( V_300 > 5000 ) {
V_296 += V_300 ;
V_300 = 0 ;
F_61 ( log -> V_145 ,
L_87 ,
V_111 , V_296 ) ;
}
} while ( ! V_297 && V_298 );
#ifdef F_69
if ( V_299 ) {
V_90 = V_63 = log -> V_92 ;
do {
ASSERT ( V_63 -> V_71 != V_303 ) ;
if ( V_63 -> V_71 == V_74 ||
V_63 -> V_71 == V_307 ||
V_63 -> V_71 == V_302 ||
V_63 -> V_71 == V_72 )
break;
V_63 = V_63 -> V_94 ;
} while ( V_90 != V_63 );
}
#endif
if ( log -> V_92 -> V_71 & ( V_73 | V_72 ) )
V_301 = 1 ;
F_15 ( & log -> V_112 ) ;
if ( V_301 )
F_160 ( & log -> V_188 ) ;
}
STATIC void
F_99 (
T_11 * V_63 ,
int V_150 )
{
struct V_1 * log = V_63 -> V_149 ;
F_12 ( & log -> V_112 ) ;
ASSERT ( V_63 -> V_71 == V_307 ||
V_63 -> V_71 == V_72 ) ;
ASSERT ( F_127 ( & V_63 -> V_113 ) == 0 ) ;
ASSERT ( V_63 -> V_232 == 1 || V_63 -> V_232 == 2 ) ;
if ( V_63 -> V_71 != V_72 ) {
if ( -- V_63 -> V_232 == 1 ) {
F_15 ( & log -> V_112 ) ;
return;
}
V_63 -> V_71 = V_302 ;
}
F_160 ( & V_63 -> V_210 ) ;
F_15 ( & log -> V_112 ) ;
F_159 ( log , V_150 , V_63 ) ;
}
STATIC int
F_154 (
struct V_1 * log ,
int V_35 ,
struct V_62 * * V_172 ,
struct V_15 * V_61 ,
int * V_308 ,
int * V_309 )
{
int V_282 ;
T_15 * V_2 ;
T_11 * V_63 ;
int error ;
V_310:
F_12 ( & log -> V_112 ) ;
if ( F_21 ( log ) ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
V_63 = log -> V_92 ;
if ( V_63 -> V_71 != V_73 ) {
F_24 ( V_311 ) ;
F_75 ( & log -> V_188 , & log -> V_112 ) ;
goto V_310;
}
V_2 = & V_63 -> V_196 ;
F_73 ( & V_63 -> V_113 ) ;
V_282 = V_63 -> V_93 ;
if ( V_282 == 0 ) {
V_61 -> V_46 -= log -> V_164 ;
F_34 ( V_61 ,
log -> V_164 ,
V_312 ) ;
V_2 -> V_313 = F_110 ( log -> V_180 ) ;
V_2 -> V_230 = F_161 (
F_119 ( log -> V_180 , log -> V_314 ) ) ;
ASSERT ( log -> V_314 >= 0 ) ;
}
if ( V_63 -> V_206 - V_63 -> V_93 < 2 * sizeof( V_247 ) ) {
F_162 ( log , V_63 , V_63 -> V_206 ) ;
if ( ! F_163 ( & V_63 -> V_113 , - 1 , 1 ) ) {
F_15 ( & log -> V_112 ) ;
error = F_53 ( log , V_63 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_112 ) ;
}
goto V_310;
}
if ( V_35 <= V_63 -> V_206 - V_63 -> V_93 ) {
* V_308 = 0 ;
V_63 -> V_93 += V_35 ;
} else {
* V_308 = 1 ;
F_162 ( log , V_63 , V_63 -> V_206 ) ;
}
* V_172 = V_63 ;
ASSERT ( V_63 -> V_93 <= V_63 -> V_206 ) ;
F_15 ( & log -> V_112 ) ;
* V_309 = V_282 ;
return 0 ;
}
STATIC void
F_49 (
struct V_1 * log ,
struct V_15 * V_61 )
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
F_46 (
struct V_1 * log ,
struct V_15 * V_61 )
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
struct V_1 * log ,
struct V_62 * V_63 )
{
int V_315 = 0 ;
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
V_315 ++ ;
V_63 -> V_71 = V_307 ;
V_63 -> V_196 . V_316 = F_161 ( V_136 ) ;
F_171 ( log , V_63 , V_136 ) ;
}
F_15 ( & log -> V_112 ) ;
if ( V_315 )
return F_126 ( log , V_63 ) ;
return 0 ;
}
STATIC void
F_162 (
struct V_1 * log ,
struct V_62 * V_63 ,
int V_317 )
{
ASSERT ( V_63 -> V_71 == V_73 ) ;
if ( ! V_317 )
V_317 = V_63 -> V_93 ;
V_63 -> V_71 = V_74 ;
V_63 -> V_196 . V_318 = F_110 ( log -> V_179 ) ;
log -> V_179 = log -> V_314 ;
log -> V_319 = log -> V_180 ;
log -> V_314 += F_106 ( V_317 ) + F_106 ( log -> V_164 ) ;
if ( F_101 ( & log -> V_145 -> V_162 ) &&
log -> V_145 -> V_162 . V_228 > 1 ) {
T_13 V_320 = F_106 ( log -> V_145 -> V_162 . V_228 ) ;
log -> V_314 = F_172 ( log -> V_314 , V_320 ) ;
}
if ( log -> V_314 >= log -> V_178 ) {
log -> V_180 ++ ;
if ( log -> V_180 == V_198 )
log -> V_180 ++ ;
log -> V_314 -= log -> V_178 ;
ASSERT ( log -> V_314 >= 0 ) ;
}
ASSERT ( V_63 == log -> V_92 ) ;
log -> V_92 = V_63 -> V_94 ;
}
int
F_70 (
struct V_41 * V_42 ,
T_4 V_64 ,
int * V_321 )
{
struct V_1 * log = V_42 -> V_43 ;
struct V_62 * V_63 ;
T_6 V_65 ;
F_24 ( V_322 ) ;
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
V_63 = V_63 -> V_190 ;
if ( V_63 -> V_71 == V_73 ||
V_63 -> V_71 == V_114 )
goto V_323;
else
goto V_324;
} else {
if ( F_127 ( & V_63 -> V_113 ) == 0 ) {
F_73 ( & V_63 -> V_113 ) ;
V_65 = F_133 ( V_63 -> V_196 . V_230 ) ;
F_162 ( log , V_63 , 0 ) ;
F_15 ( & log -> V_112 ) ;
if ( F_53 ( log , V_63 ) )
return F_30 ( V_29 ) ;
if ( V_321 )
* V_321 = 1 ;
F_12 ( & log -> V_112 ) ;
if ( F_133 ( V_63 -> V_196 . V_230 ) == V_65 &&
V_63 -> V_71 != V_114 )
goto V_324;
else
goto V_323;
} else {
F_162 ( log , V_63 , 0 ) ;
goto V_324;
}
}
}
V_324:
if ( V_64 & V_91 ) {
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
F_24 ( V_325 ) ;
F_75 ( & V_63 -> V_115 , & log -> V_112 ) ;
if ( V_63 -> V_71 & V_72 )
return F_30 ( V_29 ) ;
if ( V_321 )
* V_321 = 1 ;
} else {
V_323:
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
int * V_321 )
{
struct V_1 * log = V_42 -> V_43 ;
struct V_62 * V_63 ;
int V_326 = 0 ;
ASSERT ( V_65 != 0 ) ;
F_24 ( V_322 ) ;
V_65 = F_177 ( log , V_65 ) ;
if ( V_65 == V_327 )
return 0 ;
V_328:
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
do {
if ( F_133 ( V_63 -> V_196 . V_230 ) != V_65 ) {
V_63 = V_63 -> V_94 ;
continue;
}
if ( V_63 -> V_71 == V_114 ) {
F_15 ( & log -> V_112 ) ;
return 0 ;
}
if ( V_63 -> V_71 == V_73 ) {
if ( ! V_326 &&
( V_63 -> V_190 -> V_71 &
( V_74 | V_307 ) ) ) {
ASSERT ( ! ( V_63 -> V_71 & V_72 ) ) ;
F_24 ( V_325 ) ;
F_75 ( & V_63 -> V_190 -> V_210 ,
& log -> V_112 ) ;
if ( V_321 )
* V_321 = 1 ;
V_326 = 1 ;
goto V_328;
}
F_73 ( & V_63 -> V_113 ) ;
F_162 ( log , V_63 , 0 ) ;
F_15 ( & log -> V_112 ) ;
if ( F_53 ( log , V_63 ) )
return F_30 ( V_29 ) ;
if ( V_321 )
* V_321 = 1 ;
F_12 ( & log -> V_112 ) ;
}
if ( ( V_64 & V_91 ) &&
! ( V_63 -> V_71 &
( V_73 | V_114 ) ) ) {
if ( V_63 -> V_71 & V_72 ) {
F_15 ( & log -> V_112 ) ;
return F_30 ( V_29 ) ;
}
F_24 ( V_325 ) ;
F_75 ( & V_63 -> V_115 , & log -> V_112 ) ;
if ( V_63 -> V_71 & V_72 )
return F_30 ( V_29 ) ;
if ( V_321 )
* V_321 = 1 ;
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
F_74 (
struct V_1 * log ,
struct V_62 * V_63 )
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
ASSERT ( F_127 ( & V_61 -> V_329 ) > 0 ) ;
if ( F_179 ( & V_61 -> V_329 ) )
F_180 ( V_330 , V_61 ) ;
}
T_3 *
F_181 (
T_3 * V_61 )
{
ASSERT ( F_127 ( & V_61 -> V_329 ) > 0 ) ;
F_73 ( & V_61 -> V_329 ) ;
return V_61 ;
}
struct V_15 *
F_40 (
struct V_1 * log ,
int V_48 ,
int V_49 ,
char V_51 ,
bool V_52 ,
T_16 V_331 )
{
struct V_15 * V_16 ;
T_4 V_332 ;
int V_333 ;
V_16 = F_182 ( V_330 , V_331 ) ;
if ( ! V_16 )
return NULL ;
V_48 += sizeof( V_247 ) ;
V_48 += sizeof( V_334 ) ;
V_48 += sizeof( V_247 ) ;
V_333 = log -> V_160 - log -> V_164 ;
V_332 = F_183 ( V_48 , V_333 ) ;
V_48 += sizeof( V_247 ) * V_332 ;
while ( ! V_332 ||
F_183 ( V_48 , V_333 ) > V_332 ) {
V_48 += sizeof( V_247 ) ;
V_332 ++ ;
}
V_48 += log -> V_164 * V_332 ;
V_48 += log -> V_164 ;
if ( F_101 ( & log -> V_145 -> V_162 ) &&
log -> V_145 -> V_162 . V_228 > 1 ) {
V_48 += 2 * log -> V_145 -> V_162 . V_228 ;
} else {
V_48 += 2 * V_168 ;
}
F_111 ( & V_16 -> V_329 , 1 ) ;
V_16 -> V_17 = V_335 ;
F_9 ( & V_16 -> V_25 ) ;
V_16 -> V_21 = V_48 ;
V_16 -> V_46 = V_48 ;
V_16 -> V_22 = V_49 ;
V_16 -> V_336 = V_49 ;
V_16 -> V_45 = F_184 () ;
V_16 -> V_263 = V_51 ;
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
char * V_287 )
{
int V_174 ;
int V_337 = 0 ;
for ( V_174 = 0 ; V_174 < log -> V_157 ; V_174 ++ ) {
if ( V_287 >= log -> V_194 [ V_174 ] &&
V_287 <= log -> V_194 [ V_174 ] + log -> V_160 )
V_337 ++ ;
}
if ( ! V_337 )
F_185 ( log -> V_145 , L_89 , V_111 ) ;
}
STATIC void
F_38 (
struct V_1 * log )
{
int V_142 , V_338 ;
int V_7 , V_8 ;
F_90 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_91 ( & log -> V_140 , & V_142 , & V_338 ) ;
if ( V_142 != V_7 ) {
if ( V_7 - 1 != V_142 &&
! ( log -> V_30 & V_339 ) ) {
F_148 ( log -> V_145 , V_252 ,
L_90 , V_111 ) ;
log -> V_30 |= V_339 ;
}
if ( V_8 > F_92 ( V_338 ) &&
! ( log -> V_30 & V_339 ) ) {
F_148 ( log -> V_145 , V_252 ,
L_91 , V_111 ) ;
log -> V_30 |= V_339 ;
}
}
}
STATIC void
F_171 (
struct V_1 * log ,
struct V_62 * V_63 ,
T_6 V_136 )
{
int V_340 ;
if ( F_186 ( V_136 ) == log -> V_319 ) {
V_340 =
log -> V_178 - ( log -> V_179 - F_132 ( V_136 ) ) ;
if ( V_340 < F_106 ( V_63 -> V_93 ) + F_106 ( log -> V_164 ) )
F_185 ( log -> V_145 , L_92 , V_111 ) ;
} else {
ASSERT ( F_186 ( V_136 ) + 1 == log -> V_319 ) ;
if ( F_132 ( V_136 ) == log -> V_179 )
F_185 ( log -> V_145 , L_93 , V_111 ) ;
V_340 = F_132 ( V_136 ) - log -> V_179 ;
if ( V_340 < F_106 ( V_63 -> V_93 ) + 1 )
F_185 ( log -> V_145 , L_92 , V_111 ) ;
}
}
STATIC void
F_139 (
struct V_1 * log ,
struct V_62 * V_63 ,
int V_222 ,
T_17 V_341 )
{
V_247 * V_342 ;
T_11 * V_343 ;
T_18 * V_344 ;
V_195 V_287 ;
V_195 V_345 ;
T_19 V_346 ;
T_5 V_347 ;
int V_35 , V_174 , V_348 , V_349 , V_350 ;
int V_351 ;
F_12 ( & log -> V_112 ) ;
V_343 = log -> V_92 ;
for ( V_174 = 0 ; V_174 < log -> V_157 ; V_174 ++ ) {
if ( V_343 == NULL )
F_185 ( log -> V_145 , L_89 , V_111 ) ;
V_343 = V_343 -> V_94 ;
}
if ( V_343 != log -> V_92 )
F_185 ( log -> V_145 , L_94 , V_111 ) ;
F_15 ( & log -> V_112 ) ;
if ( V_63 -> V_196 . V_197 != F_110 ( V_198 ) )
F_185 ( log -> V_145 , L_95 , V_111 ) ;
V_287 = ( V_195 ) & V_63 -> V_196 ;
for ( V_287 += V_168 ; V_287 < ( ( V_195 ) & V_63 -> V_196 ) + V_222 ;
V_287 += V_168 ) {
if ( * ( V_241 * ) V_287 == F_110 ( V_198 ) )
F_185 ( log -> V_145 , L_96 ,
V_111 ) ;
}
V_35 = F_143 ( V_63 -> V_196 . V_245 ) ;
V_287 = V_63 -> V_209 ;
V_345 = V_287 ;
V_342 = ( V_247 * ) V_287 ;
V_344 = V_63 -> V_192 ;
for ( V_174 = 0 ; V_174 < V_35 ; V_174 ++ ) {
V_342 = ( V_247 * ) V_287 ;
V_346 = ( T_19 )
( ( V_195 ) & ( V_342 -> V_262 ) - V_345 ) ;
if ( V_341 == V_352 || ( V_346 & 0x1ff ) ) {
V_347 = V_342 -> V_262 ;
} else {
V_351 = F_117 ( ( V_195 ) & ( V_342 -> V_262 ) - V_63 -> V_209 ) ;
if ( V_351 >= ( V_163 / V_168 ) ) {
V_348 = V_351 / ( V_163 / V_168 ) ;
V_349 = V_351 % ( V_163 / V_168 ) ;
V_347 = F_187 (
V_344 [ V_348 ] . V_353 . V_354 [ V_349 ] ) ;
} else {
V_347 = F_187 (
V_63 -> V_196 . V_292 [ V_351 ] ) ;
}
}
if ( V_347 != V_54 && V_347 != V_55 )
F_61 ( log -> V_145 ,
L_97 ,
V_111 , V_347 , V_342 ,
( unsigned long ) V_346 ) ;
V_346 = ( T_19 )
( ( V_195 ) & ( V_342 -> V_264 ) - V_345 ) ;
if ( V_341 == V_352 || ( V_346 & 0x1ff ) ) {
V_350 = F_143 ( V_342 -> V_264 ) ;
} else {
V_351 = F_117 ( ( T_19 ) & V_342 -> V_264 -
( T_19 ) V_63 -> V_209 ) ;
if ( V_351 >= ( V_163 / V_168 ) ) {
V_348 = V_351 / ( V_163 / V_168 ) ;
V_349 = V_351 % ( V_163 / V_168 ) ;
V_350 = F_143 ( V_344 [ V_348 ] . V_353 . V_354 [ V_349 ] ) ;
} else {
V_350 = F_143 ( V_63 -> V_196 . V_292 [ V_351 ] ) ;
}
}
V_287 += sizeof( V_247 ) + V_350 ;
}
}
STATIC int
F_188 (
struct V_1 * log )
{
T_11 * V_63 , * V_355 ;
V_63 = log -> V_92 ;
if ( ! ( V_63 -> V_71 & V_72 ) ) {
V_355 = V_63 ;
do {
V_355 -> V_71 = V_72 ;
V_355 = V_355 -> V_94 ;
} while ( V_355 != V_63 );
return 0 ;
}
return 1 ;
}
int
F_189 (
struct V_41 * V_42 ,
int V_356 )
{
struct V_1 * log ;
int V_357 ;
log = V_42 -> V_43 ;
if ( ! log ||
log -> V_30 & V_31 ) {
V_42 -> V_81 |= V_358 ;
if ( V_42 -> V_359 )
F_190 ( V_42 -> V_359 ) ;
return 0 ;
}
if ( V_356 && log -> V_92 -> V_71 & V_72 ) {
ASSERT ( F_21 ( log ) ) ;
return 1 ;
}
V_357 = 0 ;
if ( ! V_356 )
F_173 ( log ) ;
F_12 ( & log -> V_112 ) ;
V_42 -> V_81 |= V_358 ;
if ( V_42 -> V_359 )
F_190 ( V_42 -> V_359 ) ;
log -> V_30 |= V_360 ;
if ( V_356 )
V_357 = F_188 ( log ) ;
F_15 ( & log -> V_112 ) ;
F_11 ( & log -> V_60 ) ;
F_11 ( & log -> V_18 ) ;
if ( ! ( log -> V_92 -> V_71 & V_72 ) ) {
ASSERT ( ! V_356 ) ;
F_70 ( V_42 , V_91 , NULL ) ;
F_12 ( & log -> V_112 ) ;
V_357 = F_188 ( log ) ;
F_15 ( & log -> V_112 ) ;
}
F_159 ( log , V_153 , NULL ) ;
#ifdef F_191
{
T_11 * V_63 ;
F_12 ( & log -> V_112 ) ;
V_63 = log -> V_92 ;
do {
ASSERT ( V_63 -> V_208 == 0 ) ;
V_63 = V_63 -> V_94 ;
} while ( V_63 != log -> V_92 );
F_15 ( & log -> V_112 ) ;
}
#endif
return V_357 ;
}
STATIC int
F_84 (
struct V_1 * log )
{
T_11 * V_63 ;
V_63 = log -> V_92 ;
do {
if ( V_63 -> V_196 . V_245 )
return 0 ;
V_63 = V_63 -> V_94 ;
} while ( V_63 != log -> V_92 );
return 1 ;
}
