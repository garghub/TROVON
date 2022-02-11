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
F_27 ( V_40 ) ;
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
F_27 ( V_40 ) ;
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
T_4 V_60 )
{
struct V_1 * log = V_37 -> V_38 ;
T_6 V_61 = 0 ;
if ( F_26 ( log ) ||
( ( ( V_57 -> V_19 & V_62 ) == 0 ) &&
( F_37 ( log , V_57 , V_59 , & V_61 ) ) ) ) {
V_61 = ( T_6 ) - 1 ;
if ( V_57 -> V_19 & V_20 ) {
V_60 |= V_63 ;
}
}
if ( ( V_57 -> V_19 & V_20 ) == 0 ||
( V_60 & V_63 ) ) {
F_38 ( log , V_57 ) ;
F_39 ( log , V_57 ) ;
F_40 ( V_57 ) ;
} else {
F_41 ( log , V_57 ) ;
F_42 ( log , V_57 ) ;
V_57 -> V_19 |= V_62 ;
}
return V_61 ;
}
int
F_43 (
struct V_36 * V_37 ,
struct V_58 * V_59 ,
T_7 * V_64 )
{
int V_65 ;
F_12 ( & V_59 -> V_66 ) ;
V_65 = ( V_59 -> V_67 & V_68 ) ;
if ( ! V_65 ) {
F_44 ( ( V_59 -> V_67 == V_69 ) ||
( V_59 -> V_67 == V_70 ) ) ;
V_64 -> V_71 = NULL ;
* ( V_59 -> V_72 ) = V_64 ;
V_59 -> V_72 = & ( V_64 -> V_71 ) ;
}
F_15 ( & V_59 -> V_66 ) ;
return V_65 ;
}
int
F_45 (
struct V_36 * V_37 ,
struct V_58 * V_59 )
{
if ( F_46 ( V_37 -> V_38 , V_59 ) ) {
F_47 ( V_37 , V_73 ) ;
return - V_39 ;
}
return 0 ;
}
int
F_48 (
T_8 * V_37 ,
T_9 * V_74 ,
T_10 V_75 ,
int V_76 )
{
int error = 0 ;
int V_77 ;
if ( ! ( V_37 -> V_78 & V_79 ) ) {
F_49 ( V_37 , L_1 ,
F_50 ( & V_37 -> V_80 ) ) ;
} else {
F_49 ( V_37 ,
L_2 ,
F_50 ( & V_37 -> V_80 ) ) ;
ASSERT ( V_37 -> V_78 & V_81 ) ;
}
V_37 -> V_38 = F_51 ( V_37 , V_74 , V_75 , V_76 ) ;
if ( F_52 ( V_37 -> V_38 ) ) {
error = F_53 ( V_37 -> V_38 ) ;
goto V_82;
}
V_77 = F_54 ( V_37 ) ;
if ( V_37 -> V_80 . V_83 < V_77 ) {
F_55 ( V_37 ,
L_3 ,
V_37 -> V_80 . V_83 , V_77 ) ;
error = - V_84 ;
} else if ( V_37 -> V_80 . V_83 > V_85 ) {
F_55 ( V_37 ,
L_4 ,
V_37 -> V_80 . V_83 , V_85 ) ;
error = - V_84 ;
} else if ( F_56 ( V_37 , V_37 -> V_80 . V_83 ) > V_86 ) {
F_55 ( V_37 ,
L_5 ,
F_56 ( V_37 , V_37 -> V_80 . V_83 ) ,
V_86 ) ;
error = - V_84 ;
}
if ( error ) {
if ( F_57 ( & V_37 -> V_80 ) ) {
F_58 ( V_37 , L_6 ) ;
ASSERT ( 0 ) ;
goto V_87;
}
F_58 ( V_37 ,
L_7
L_8 ) ;
}
error = F_59 ( V_37 ) ;
if ( error ) {
F_55 ( V_37 , L_9 , error ) ;
goto V_87;
}
V_37 -> V_38 -> V_88 = V_37 -> V_89 ;
if ( ! ( V_37 -> V_78 & V_79 ) ) {
int V_90 = ( V_37 -> V_78 & V_81 ) ;
if ( V_90 )
V_37 -> V_78 &= ~ V_81 ;
error = F_60 ( V_37 -> V_38 ) ;
if ( V_90 )
V_37 -> V_78 |= V_81 ;
if ( error ) {
F_55 ( V_37 , L_10 ,
error ) ;
goto V_91;
}
}
error = F_61 ( & V_37 -> V_38 -> V_92 , & V_93 , & V_37 -> V_94 ,
L_11 ) ;
if ( error )
goto V_91;
V_37 -> V_38 -> V_25 &= ~ V_26 ;
F_62 ( V_37 -> V_38 ) ;
return 0 ;
V_91:
F_63 ( V_37 ) ;
V_87:
F_64 ( V_37 -> V_38 ) ;
V_82:
return error ;
}
int
F_65 ( T_8 * V_37 )
{
int error = 0 ;
if ( ! ( V_37 -> V_78 & V_79 ) ) {
error = F_66 ( V_37 -> V_38 ) ;
if ( ! error )
F_67 ( V_37 ) ;
} else {
ASSERT ( V_37 -> V_78 & V_81 ) ;
}
return error ;
}
int
F_68 ( T_8 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
T_11 * V_59 ;
#ifdef F_69
T_11 * V_95 ;
#endif
T_3 * V_16 = NULL ;
T_6 V_61 ;
int error ;
if ( V_37 -> V_78 & V_81 )
return 0 ;
error = F_70 ( V_37 , V_96 , NULL ) ;
ASSERT ( error || ! ( F_26 ( log ) ) ) ;
#ifdef F_69
V_95 = V_59 = log -> V_97 ;
do {
if ( ! ( V_59 -> V_67 & V_68 ) ) {
ASSERT ( V_59 -> V_67 & V_69 ) ;
ASSERT ( V_59 -> V_98 == 0 ) ;
}
V_59 = V_59 -> V_99 ;
} while ( V_59 != V_95 );
#endif
if ( ! ( F_26 ( log ) ) ) {
error = F_32 ( V_37 , 600 , 1 , & V_16 ,
V_51 , 0 , V_100 ) ;
if ( ! error ) {
struct {
T_12 V_101 ;
T_12 V_102 ;
T_13 V_103 ;
} V_101 = {
. V_101 = V_104 ,
} ;
struct V_105 V_106 = {
. V_107 = & V_101 ,
. V_108 = sizeof( V_101 ) ,
. V_109 = V_110 ,
} ;
struct V_111 V_112 = {
. V_113 = 1 ,
. V_114 = & V_106 ,
} ;
V_16 -> V_19 = 0 ;
V_16 -> V_42 -= sizeof( V_101 ) ;
error = F_71 ( log , & V_112 , V_16 , & V_61 ,
NULL , V_115 ) ;
}
if ( error )
F_72 ( V_37 , L_12 , V_116 ) ;
F_12 ( & log -> V_117 ) ;
V_59 = log -> V_97 ;
F_73 ( & V_59 -> V_118 ) ;
F_74 ( log , V_59 ) ;
F_15 ( & log -> V_117 ) ;
error = F_46 ( log , V_59 ) ;
F_12 ( & log -> V_117 ) ;
if ( ! ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_119 ) ) {
if ( ! F_26 ( log ) ) {
F_75 ( & V_59 -> V_120 ,
& log -> V_117 ) ;
} else {
F_15 ( & log -> V_117 ) ;
}
} else {
F_15 ( & log -> V_117 ) ;
}
if ( V_16 ) {
F_76 ( log , V_16 ) ;
F_39 ( log , V_16 ) ;
F_40 ( V_16 ) ;
}
} else {
F_12 ( & log -> V_117 ) ;
V_59 = log -> V_97 ;
F_73 ( & V_59 -> V_118 ) ;
F_74 ( log , V_59 ) ;
F_15 ( & log -> V_117 ) ;
error = F_46 ( log , V_59 ) ;
F_12 ( & log -> V_117 ) ;
if ( ! ( V_59 -> V_67 == V_69
|| V_59 -> V_67 == V_119
|| V_59 -> V_67 == V_68 ) ) {
F_75 ( & V_59 -> V_120 ,
& log -> V_117 ) ;
} else {
F_15 ( & log -> V_117 ) ;
}
}
return error ;
}
void
F_77 (
struct V_36 * V_37 )
{
F_78 ( & V_37 -> V_38 -> V_121 ) ;
F_79 ( V_37 , V_96 ) ;
F_80 ( V_37 -> V_89 ) ;
F_81 ( V_37 -> V_122 ) ;
F_82 ( V_37 -> V_123 ) ;
F_83 ( V_37 -> V_123 ) ;
F_68 ( V_37 ) ;
}
void
F_84 (
struct V_36 * V_37 )
{
F_77 ( V_37 ) ;
F_63 ( V_37 ) ;
F_85 ( & V_37 -> V_38 -> V_92 ) ;
F_64 ( V_37 -> V_38 ) ;
}
void
F_86 (
struct V_36 * V_37 ,
struct V_124 * V_125 ,
int type ,
const struct V_126 * V_127 )
{
V_125 -> V_128 = V_37 ;
V_125 -> V_129 = V_37 -> V_89 ;
V_125 -> V_130 = type ;
V_125 -> V_131 = V_127 ;
V_125 -> V_132 = NULL ;
F_9 ( & V_125 -> V_133 ) ;
F_9 ( & V_125 -> V_134 ) ;
}
void
F_87 (
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
F_88 ( T_8 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_135 = 0 ;
if ( ! F_89 ( V_37 ) )
return 0 ;
if ( ! F_90 ( log ) )
return 0 ;
F_12 ( & log -> V_117 ) ;
switch ( log -> V_136 ) {
case V_137 :
case V_138 :
case V_139 :
break;
case V_140 :
case V_141 :
if ( F_91 ( log -> V_88 ) )
break;
if ( ! F_92 ( log ) )
break;
V_135 = 1 ;
if ( log -> V_136 == V_140 )
log -> V_136 = V_137 ;
else
log -> V_136 = V_138 ;
break;
default:
V_135 = 1 ;
break;
}
F_15 ( & log -> V_117 ) ;
return V_135 ;
}
T_6
F_93 (
struct V_36 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_124 * V_142 ;
T_6 V_143 ;
F_94 ( & V_37 -> V_89 -> V_144 ) ;
V_142 = F_95 ( V_37 -> V_89 ) ;
if ( V_142 )
V_143 = V_142 -> V_145 ;
else
V_143 = F_2 ( & log -> V_146 ) ;
F_96 ( log , V_143 ) ;
F_97 ( & log -> V_147 , V_143 ) ;
return V_143 ;
}
T_6
F_98 (
struct V_36 * V_37 )
{
T_6 V_143 ;
F_12 ( & V_37 -> V_89 -> V_144 ) ;
V_143 = F_93 ( V_37 ) ;
F_15 ( & V_37 -> V_89 -> V_144 ) ;
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
F_99 ( V_2 , & V_150 , & V_151 ) ;
F_100 ( & log -> V_147 , & V_149 , & V_148 ) ;
V_148 = F_101 ( V_148 ) ;
if ( V_149 == V_150 && V_151 >= V_148 )
V_23 = log -> V_9 - ( V_151 - V_148 ) ;
else if ( V_149 + 1 < V_150 )
return 0 ;
else if ( V_149 < V_150 ) {
ASSERT ( V_149 == ( V_150 - 1 ) ) ;
V_23 = V_148 - V_151 ;
} else {
F_72 ( log -> V_152 ,
L_13
L_14
L_15 ,
V_149 , V_148 , V_150 , V_151 ) ;
ASSERT ( 0 ) ;
V_23 = log -> V_9 ;
}
return V_23 ;
}
void
F_102 ( T_14 * V_153 )
{
struct V_58 * V_59 = V_153 -> V_154 ;
struct V_1 * V_155 = V_59 -> V_156 ;
int V_157 = 0 ;
if ( F_103 ( V_153 -> V_158 , V_155 -> V_152 ,
V_159 , V_160 ) ) {
F_104 ( V_153 , V_116 ) ;
F_105 ( V_153 ) ;
F_47 ( V_155 -> V_152 , V_73 ) ;
V_157 = V_161 ;
} else if ( V_59 -> V_67 & V_68 ) {
V_157 = V_161 ;
}
ASSERT ( F_106 ( V_153 ) ) ;
F_107 ( V_59 , V_157 ) ;
F_83 ( V_153 ) ;
}
STATIC void
F_108 (
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
if ( F_109 ( & V_37 -> V_80 ) ) {
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
F_67 (
struct V_36 * V_37 )
{
F_110 ( V_37 -> V_178 , & V_37 -> V_38 -> V_121 ,
F_111 ( V_179 * 10 ) ) ;
}
void
F_112 (
struct V_180 * V_181 )
{
struct V_1 * log = F_113 ( F_114 ( V_181 ) ,
struct V_1 , V_121 ) ;
struct V_36 * V_37 = log -> V_152 ;
if ( F_88 ( V_37 ) )
F_115 ( V_37 ) ;
else
F_79 ( V_37 , 0 ) ;
F_116 ( V_37 -> V_89 ) ;
F_67 ( V_37 ) ;
}
STATIC struct V_1 *
F_51 (
struct V_36 * V_37 ,
struct V_182 * V_74 ,
T_10 V_75 ,
int V_76 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_183 ;
T_11 * V_59 , * V_184 = NULL ;
T_14 * V_153 ;
int V_185 ;
int error = - V_54 ;
T_4 V_186 = 0 ;
log = F_117 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! log ) {
F_55 ( V_37 , L_16 ) ;
goto V_82;
}
log -> V_152 = V_37 ;
log -> V_187 = V_74 ;
log -> V_9 = F_101 ( V_76 ) ;
log -> V_188 = V_75 ;
log -> V_189 = V_76 ;
log -> V_136 = V_139 ;
log -> V_25 |= V_26 ;
F_118 ( & log -> V_121 , F_112 ) ;
log -> V_190 = - 1 ;
F_119 ( & log -> V_147 , 1 , 0 ) ;
F_119 ( & log -> V_146 , 1 , 0 ) ;
log -> V_191 = 1 ;
F_7 ( & log -> V_56 ) ;
F_7 ( & log -> V_18 ) ;
error = - V_192 ;
if ( F_120 ( & V_37 -> V_80 ) ) {
V_186 = V_37 -> V_80 . V_193 ;
if ( V_186 < V_172 ) {
F_55 ( V_37 , L_17 ,
V_186 , V_172 ) ;
goto V_87;
}
V_186 -= V_172 ;
if ( V_186 > V_37 -> V_194 ) {
F_55 ( V_37 , L_18 ,
V_186 , V_37 -> V_194 ) ;
goto V_87;
}
if ( V_186 && log -> V_188 > 0 &&
! F_109 ( & V_37 -> V_80 ) ) {
F_55 ( V_37 ,
L_19 ,
V_186 ) ;
goto V_87;
}
}
log -> V_195 = 1 << V_186 ;
F_108 ( V_37 , log ) ;
error = - V_54 ;
V_153 = F_121 ( V_37 -> V_196 , V_197 ,
F_122 ( log -> V_168 ) , 0 ) ;
if ( ! V_153 )
goto V_87;
ASSERT ( F_123 ( V_153 ) ) ;
F_83 ( V_153 ) ;
V_153 -> V_198 = F_102 ;
log -> V_199 = V_153 ;
F_10 ( & log -> V_117 ) ;
F_124 ( & log -> V_200 ) ;
V_183 = & log -> V_97 ;
ASSERT ( log -> V_168 >= 4096 ) ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
* V_183 = F_117 ( sizeof( T_11 ) , V_53 ) ;
if ( ! * V_183 )
goto V_201;
V_59 = * V_183 ;
V_59 -> V_202 = V_184 ;
V_184 = V_59 ;
V_153 = F_125 ( V_37 -> V_196 ,
F_122 ( log -> V_168 ) , 0 ) ;
if ( ! V_153 )
goto V_201;
ASSERT ( F_123 ( V_153 ) ) ;
F_83 ( V_153 ) ;
V_153 -> V_198 = F_102 ;
V_59 -> V_203 = V_153 ;
V_59 -> V_204 = V_153 -> V_205 ;
#ifdef F_69
log -> V_206 [ V_185 ] = ( V_207 ) & ( V_59 -> V_208 ) ;
#endif
V_2 = & V_59 -> V_208 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_209 = F_126 ( V_210 ) ;
V_2 -> V_211 = F_126 (
F_109 ( & log -> V_152 -> V_80 ) ? 2 : 1 ) ;
V_2 -> V_212 = F_126 ( log -> V_168 ) ;
V_2 -> V_213 = F_126 ( V_214 ) ;
memcpy ( & V_2 -> V_215 , & V_37 -> V_80 . V_216 , sizeof( V_217 ) ) ;
V_59 -> V_218 = F_101 ( V_153 -> V_219 ) - log -> V_171 ;
V_59 -> V_67 = V_69 ;
V_59 -> V_156 = log ;
F_127 ( & V_59 -> V_118 , 0 ) ;
F_10 ( & V_59 -> V_66 ) ;
V_59 -> V_72 = & ( V_59 -> V_220 ) ;
V_59 -> V_221 = ( char * ) V_59 -> V_204 + log -> V_171 ;
F_124 ( & V_59 -> V_120 ) ;
F_124 ( & V_59 -> V_222 ) ;
V_183 = & V_59 -> V_99 ;
}
* V_183 = log -> V_97 ;
log -> V_97 -> V_202 = V_184 ;
error = F_128 ( log ) ;
if ( error )
goto V_201;
return log ;
V_201:
for ( V_59 = log -> V_97 ; V_59 ; V_59 = V_184 ) {
V_184 = V_59 -> V_99 ;
if ( V_59 -> V_203 )
F_129 ( V_59 -> V_203 ) ;
F_130 ( V_59 ) ;
}
F_131 ( & log -> V_117 ) ;
F_129 ( log -> V_199 ) ;
V_87:
F_130 ( log ) ;
V_82:
return F_132 ( error ) ;
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
struct V_105 V_106 = {
. V_107 = NULL ,
. V_108 = 0 ,
. V_109 = V_224 ,
} ;
struct V_111 V_112 = {
. V_113 = 1 ,
. V_114 = & V_106 ,
} ;
F_44 ( V_59 ) ;
error = F_71 ( log , & V_112 , V_57 , V_223 , V_59 ,
V_225 ) ;
if ( error )
F_47 ( V_37 , V_73 ) ;
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
ASSERT ( F_122 ( V_24 ) < log -> V_189 ) ;
V_23 = F_21 ( log , & log -> V_56 . V_12 ) ;
V_228 = F_133 ( V_23 ) ;
V_231 = F_122 ( V_24 ) ;
V_231 = F_134 ( V_231 , ( log -> V_189 >> 2 ) ) ;
V_231 = F_134 ( V_231 , 256 ) ;
if ( V_228 >= V_231 )
return;
F_100 ( & log -> V_147 , & V_230 ,
& V_229 ) ;
V_229 += V_231 ;
if ( V_229 >= log -> V_189 ) {
V_229 -= log -> V_189 ;
V_230 += 1 ;
}
V_226 = F_135 ( V_230 ,
V_229 ) ;
V_227 = F_2 ( & log -> V_146 ) ;
if ( F_136 ( V_226 , V_227 ) > 0 )
V_226 = V_227 ;
if ( ! F_26 ( log ) )
F_137 ( log -> V_88 , V_226 ) ;
}
STATIC void
F_138 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_232 )
{
int V_185 , V_233 , V_234 ;
int V_162 = V_59 -> V_98 + V_232 ;
T_16 V_235 ;
V_207 V_236 ;
V_235 = F_139 ( V_59 -> V_208 . V_237 ) ;
V_236 = V_59 -> V_221 ;
for ( V_185 = 0 ; V_185 < F_122 ( V_162 ) ; V_185 ++ ) {
if ( V_185 >= ( V_170 / V_175 ) )
break;
V_59 -> V_208 . V_238 [ V_185 ] = * ( T_16 * ) V_236 ;
* ( T_16 * ) V_236 = V_235 ;
V_236 += V_175 ;
}
if ( F_109 ( & log -> V_152 -> V_80 ) ) {
T_17 * V_239 = V_59 -> V_204 ;
for ( ; V_185 < F_122 ( V_162 ) ; V_185 ++ ) {
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
F_140 (
struct V_1 * log ,
struct V_243 * V_244 ,
char * V_236 ,
int V_162 )
{
T_13 V_245 ;
V_245 = F_141 ( ( char * ) V_244 ,
sizeof( struct V_243 ) ,
F_142 ( struct V_243 , V_246 ) ) ;
if ( F_109 ( & log -> V_152 -> V_80 ) ) {
union V_247 * V_239 = (union V_247 * ) V_244 ;
int V_185 ;
for ( V_185 = 1 ; V_185 < log -> V_173 ; V_185 ++ ) {
V_245 = F_143 ( V_245 , & V_239 [ V_185 ] . V_240 ,
sizeof( struct V_248 ) ) ;
}
}
V_245 = F_143 ( V_245 , V_236 , V_162 ) ;
return F_144 ( V_245 ) ;
}
STATIC int
F_145 (
struct V_249 * V_153 )
{
struct V_58 * V_59 = V_153 -> V_154 ;
F_82 ( V_153 ) ;
if ( V_59 -> V_67 & V_68 ) {
F_146 ( V_153 , - V_39 ) ;
F_105 ( V_153 ) ;
F_147 ( V_153 , 0 ) ;
return 0 ;
}
F_148 ( V_153 ) ;
return 0 ;
}
STATIC int
F_149 (
struct V_1 * log ,
struct V_58 * V_59 )
{
T_14 * V_153 ;
int V_185 ;
T_4 V_250 ;
T_4 V_251 ;
int V_232 ;
int V_252 = 0 ;
int error ;
int V_253 = F_109 ( & log -> V_152 -> V_80 ) ;
int V_162 ;
F_27 ( V_254 ) ;
ASSERT ( F_150 ( & V_59 -> V_118 ) == 0 ) ;
V_251 = log -> V_171 + V_59 -> V_98 ;
if ( V_253 && log -> V_152 -> V_80 . V_255 > 1 ) {
V_250 = F_151 ( log , F_152 ( log , V_251 ) ) ;
} else {
V_250 = F_101 ( F_122 ( V_251 ) ) ;
}
V_232 = V_250 - V_251 ;
ASSERT ( V_232 >= 0 ) ;
ASSERT ( ( V_253 && log -> V_152 -> V_80 . V_255 > 1 &&
V_232 < log -> V_152 -> V_80 . V_255 )
||
( log -> V_152 -> V_80 . V_255 <= 1 &&
V_232 < F_101 ( 1 ) ) ) ;
F_6 ( log , & log -> V_56 . V_12 , V_232 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_232 ) ;
F_138 ( log , V_59 , V_232 ) ;
V_162 = V_59 -> V_98 ;
if ( V_253 )
V_162 += V_232 ;
V_59 -> V_208 . V_256 = F_126 ( V_162 ) ;
V_153 = V_59 -> V_203 ;
F_153 ( V_153 , F_154 ( F_155 ( V_59 -> V_208 . V_237 ) ) ) ;
F_156 ( V_257 , F_122 ( V_250 ) ) ;
if ( F_157 ( V_153 ) + F_122 ( V_250 ) > log -> V_189 ) {
char * V_258 ;
V_252 = V_250 - ( F_101 ( log -> V_189 - F_157 ( V_153 ) ) ) ;
V_250 = F_101 ( log -> V_189 - F_157 ( V_153 ) ) ;
V_59 -> V_259 = 2 ;
V_258 = ( char * ) & V_59 -> V_208 + V_250 ;
for ( V_185 = 0 ; V_185 < V_252 ; V_185 += V_175 ) {
T_13 V_7 = F_158 ( * ( T_16 * ) V_258 ) ;
if ( ++ V_7 == V_210 )
V_7 ++ ;
* ( T_16 * ) V_258 = F_126 ( V_7 ) ;
V_258 += V_175 ;
}
} else {
V_59 -> V_259 = 1 ;
}
V_59 -> V_208 . V_246 = F_140 ( log , & V_59 -> V_208 ,
V_59 -> V_221 , V_162 ) ;
V_153 -> V_260 = F_122 ( V_250 ) ;
V_153 -> V_154 = V_59 ;
F_159 ( V_153 ) ;
F_160 ( V_153 ) ;
V_153 -> V_261 |= V_262 ;
if ( log -> V_152 -> V_78 & V_263 ) {
V_153 -> V_261 |= V_264 ;
if ( log -> V_152 -> V_196 != log -> V_152 -> V_122 )
F_161 ( log -> V_152 -> V_122 ) ;
else
V_153 -> V_261 |= V_265 ;
}
ASSERT ( F_157 ( V_153 ) <= log -> V_189 - 1 ) ;
ASSERT ( F_157 ( V_153 ) + F_122 ( V_250 ) <= log -> V_189 ) ;
F_162 ( log , V_59 , V_250 , true ) ;
F_153 ( V_153 , F_157 ( V_153 ) + log -> V_188 ) ;
F_163 ( V_153 ) ;
error = F_145 ( V_153 ) ;
if ( error ) {
F_104 ( V_153 , L_20 ) ;
return error ;
}
if ( V_252 ) {
V_153 = V_59 -> V_156 -> V_199 ;
F_153 ( V_153 , 0 ) ;
F_164 ( V_153 ,
( char * ) & V_59 -> V_208 + V_250 , V_252 ) ;
V_153 -> V_154 = V_59 ;
F_159 ( V_153 ) ;
F_160 ( V_153 ) ;
V_153 -> V_261 |= V_262 ;
if ( log -> V_152 -> V_78 & V_263 )
V_153 -> V_261 |= V_264 ;
ASSERT ( F_157 ( V_153 ) <= log -> V_189 - 1 ) ;
ASSERT ( F_157 ( V_153 ) + F_122 ( V_250 ) <= log -> V_189 ) ;
F_153 ( V_153 , F_157 ( V_153 ) + log -> V_188 ) ;
F_163 ( V_153 ) ;
error = F_145 ( V_153 ) ;
if ( error ) {
F_104 ( V_153 , L_21 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_64 (
struct V_1 * log )
{
T_11 * V_59 , * V_266 ;
int V_185 ;
F_165 ( log ) ;
V_59 = log -> V_97 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
F_82 ( V_59 -> V_203 ) ;
F_83 ( V_59 -> V_203 ) ;
V_59 = V_59 -> V_99 ;
}
F_82 ( log -> V_199 ) ;
F_83 ( log -> V_199 ) ;
F_166 ( log -> V_199 , F_122 ( log -> V_168 ) ) ;
F_129 ( log -> V_199 ) ;
V_59 = log -> V_97 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
F_129 ( V_59 -> V_203 ) ;
V_266 = V_59 -> V_99 ;
F_130 ( V_59 ) ;
V_59 = V_266 ;
}
F_131 ( & log -> V_117 ) ;
log -> V_152 -> V_38 = NULL ;
F_130 ( log ) ;
}
static inline void
F_167 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_267 ,
int V_268 )
{
F_12 ( & log -> V_117 ) ;
F_168 ( & V_59 -> V_208 . V_269 , V_267 ) ;
V_59 -> V_98 += V_268 ;
F_15 ( & log -> V_117 ) ;
}
void
F_169 (
struct V_36 * V_37 ,
struct V_15 * V_57 )
{
T_4 V_185 ;
T_4 V_270 = V_57 -> V_29 * ( T_4 ) sizeof( V_271 ) ;
static char * V_272 [ V_273 ] = {
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
static char * V_274 [ V_275 ] = {
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
F_55 ( V_37 ,
L_81
L_82
L_83
L_84
L_85
L_86
L_87
L_88 ,
( ( V_57 -> V_55 <= 0 ||
V_57 -> V_55 > V_275 ) ?
L_89 : V_274 [ V_57 -> V_55 - 1 ] ) ,
V_57 -> V_55 ,
V_57 -> V_21 ,
V_57 -> V_42 ,
V_57 -> V_28 , V_57 -> V_32 ,
V_57 -> V_29 , V_270 ,
V_57 -> V_28 +
V_57 -> V_32 + V_270 ,
V_57 -> V_27 ) ;
for ( V_185 = 0 ; V_185 < V_57 -> V_27 ; V_185 ++ ) {
T_4 V_35 = V_57 -> V_33 [ V_185 ] . V_35 ;
F_55 ( V_37 , L_90 , V_185 ,
( ( V_35 <= 0 || V_35 > V_273 ) ?
L_91 : V_272 [ V_35 - 1 ] ) ,
V_57 -> V_33 [ V_185 ] . V_34 ) ;
}
F_170 ( V_37 , V_276 ,
L_92 ) ;
F_47 ( V_37 , V_73 ) ;
}
static int
F_171 (
struct V_15 * V_57 ,
struct V_111 * V_277 )
{
struct V_111 * V_278 ;
int V_279 = 0 ;
int V_30 = 0 ;
int V_185 ;
if ( V_57 -> V_19 & V_62 )
V_279 ++ ;
for ( V_278 = V_277 ; V_278 ; V_278 = V_278 -> V_280 ) {
if ( V_278 -> V_281 == V_282 )
continue;
V_279 += V_278 -> V_113 ;
for ( V_185 = 0 ; V_185 < V_278 -> V_113 ; V_185 ++ ) {
struct V_105 * V_283 = & V_278 -> V_114 [ V_185 ] ;
V_30 += V_283 -> V_108 ;
F_24 ( V_57 , V_283 -> V_108 , V_283 -> V_109 ) ;
}
}
V_57 -> V_29 += V_279 ;
V_30 += V_279 * sizeof( struct V_284 ) ;
return V_30 ;
}
static int
F_172 (
struct V_284 * V_285 ,
struct V_15 * V_57 )
{
if ( ! ( V_57 -> V_19 & V_62 ) )
return 0 ;
V_285 -> V_286 = F_126 ( V_57 -> V_41 ) ;
V_285 -> V_287 = V_57 -> V_288 ;
V_285 -> V_289 = 0 ;
V_285 -> V_290 = V_291 ;
V_285 -> V_292 = 0 ;
V_57 -> V_19 &= ~ V_62 ;
return sizeof( struct V_284 ) ;
}
static V_271 *
F_173 (
struct V_1 * log ,
struct V_284 * V_285 ,
struct V_15 * V_57 ,
T_4 V_60 )
{
V_285 -> V_286 = F_126 ( V_57 -> V_41 ) ;
V_285 -> V_287 = V_57 -> V_288 ;
V_285 -> V_292 = 0 ;
V_285 -> V_290 = V_60 ;
switch ( V_285 -> V_287 ) {
case V_50 :
case V_293 :
case V_51 :
break;
default:
F_55 ( log -> V_152 ,
L_93 ,
V_285 -> V_287 , V_57 ) ;
return NULL ;
}
return V_285 ;
}
static int
F_174 (
struct V_15 * V_57 ,
struct V_284 * V_285 ,
int V_294 ,
int V_295 ,
int * V_296 ,
int * V_297 ,
int * V_298 ,
int * V_299 )
{
int V_300 ;
V_300 = V_295 - * V_299 ;
* V_296 = * V_299 ;
if ( V_300 <= V_294 ) {
* V_297 = V_300 ;
V_285 -> V_289 = F_126 ( * V_297 ) ;
if ( * V_298 )
V_285 -> V_290 |= ( V_301 | V_302 ) ;
* V_298 = 0 ;
* V_299 = 0 ;
return 0 ;
}
* V_297 = V_294 ;
V_285 -> V_289 = F_126 ( * V_297 ) ;
V_285 -> V_290 |= V_303 ;
if ( * V_298 )
V_285 -> V_290 |= V_302 ;
* V_299 += * V_297 ;
( * V_298 ) ++ ;
V_57 -> V_42 -= sizeof( struct V_284 ) ;
V_57 -> V_29 ++ ;
return sizeof( struct V_284 ) ;
}
static int
F_175 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_4 V_60 ,
int * V_267 ,
int * V_304 ,
int * V_305 ,
int * V_306 ,
int V_307 ,
struct V_58 * * V_308 )
{
if ( * V_305 ) {
F_167 ( log , V_59 , * V_267 , * V_304 ) ;
* V_267 = 0 ;
* V_304 = 0 ;
return F_46 ( log , V_59 ) ;
}
* V_305 = 0 ;
* V_306 = 0 ;
if ( V_59 -> V_218 - V_307 <= sizeof( V_271 ) ) {
F_167 ( log , V_59 , * V_267 , * V_304 ) ;
* V_267 = 0 ;
* V_304 = 0 ;
F_12 ( & log -> V_117 ) ;
F_74 ( log , V_59 ) ;
F_15 ( & log -> V_117 ) ;
if ( ! V_308 )
return F_46 ( log , V_59 ) ;
ASSERT ( V_60 & V_225 ) ;
* V_308 = V_59 ;
}
return 0 ;
}
int
F_71 (
struct V_1 * log ,
struct V_111 * V_277 ,
struct V_15 * V_57 ,
T_6 * V_309 ,
struct V_58 * * V_308 ,
T_4 V_60 )
{
struct V_58 * V_59 = NULL ;
struct V_105 * V_283 ;
struct V_111 * V_278 ;
int V_30 ;
int V_310 ;
int V_305 = 0 ;
int V_306 = 0 ;
int V_311 = 0 ;
int V_267 = 0 ;
int V_304 = 0 ;
int error ;
* V_309 = 0 ;
V_30 = F_171 ( V_57 , V_277 ) ;
if ( V_57 -> V_19 & V_62 )
V_57 -> V_42 -= sizeof( V_271 ) ;
if ( V_60 & ( V_225 | V_115 ) )
V_57 -> V_42 -= sizeof( V_271 ) ;
if ( V_57 -> V_42 < 0 )
F_169 ( log -> V_152 , V_57 ) ;
V_310 = 0 ;
V_278 = V_277 ;
V_283 = V_278 -> V_114 ;
while ( V_278 && ( ! V_278 -> V_113 || V_310 < V_278 -> V_113 ) ) {
void * V_312 ;
int V_307 ;
error = F_176 ( log , V_30 , & V_59 , V_57 ,
& V_311 , & V_307 ) ;
if ( error )
return error ;
ASSERT ( V_307 <= V_59 -> V_218 - 1 ) ;
V_312 = V_59 -> V_221 + V_307 ;
if ( ! * V_309 )
* V_309 = F_155 ( V_59 -> V_208 . V_237 ) ;
while ( V_278 && ( ! V_278 -> V_113 || V_310 < V_278 -> V_113 ) ) {
struct V_105 * V_106 ;
struct V_284 * V_285 ;
int V_313 ;
int V_297 ;
int V_296 ;
bool V_314 = false ;
if ( V_278 -> V_281 == V_282 ) {
ASSERT ( V_278 -> V_113 == 0 ) ;
V_314 = true ;
goto V_315;
}
V_106 = & V_283 [ V_310 ] ;
ASSERT ( V_106 -> V_108 % sizeof( V_316 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_312 % sizeof( V_316 ) == 0 ) ;
V_313 = F_172 ( V_312 , V_57 ) ;
if ( V_313 ) {
V_267 ++ ;
F_177 ( & V_312 , & V_30 , & V_307 ,
V_313 ) ;
}
V_285 = F_173 ( log , V_312 , V_57 , V_60 ) ;
if ( ! V_285 )
return - V_39 ;
F_177 ( & V_312 , & V_30 , & V_307 ,
sizeof( struct V_284 ) ) ;
V_30 += F_174 ( V_57 , V_285 ,
V_59 -> V_218 - V_307 ,
V_106 -> V_108 ,
& V_296 , & V_297 ,
& V_305 ,
& V_306 ) ;
F_178 ( log , V_312 ) ;
ASSERT ( V_297 >= 0 ) ;
memcpy ( V_312 , V_106 -> V_107 + V_296 , V_297 ) ;
F_177 ( & V_312 , & V_30 , & V_307 , V_297 ) ;
V_297 += V_313 + sizeof( V_271 ) ;
V_267 ++ ;
V_304 += V_311 ? V_297 : 0 ;
error = F_175 ( log , V_59 , V_60 ,
& V_267 , & V_304 ,
& V_305 ,
& V_306 ,
V_307 ,
V_308 ) ;
if ( error )
return error ;
if ( V_305 )
break;
if ( ++ V_310 == V_278 -> V_113 ) {
V_315:
V_278 = V_278 -> V_280 ;
V_310 = 0 ;
if ( V_278 )
V_283 = V_278 -> V_114 ;
}
if ( V_267 == 0 && V_314 == false ) {
if ( ! V_278 )
return 0 ;
break;
}
}
}
ASSERT ( V_30 == 0 ) ;
F_167 ( log , V_59 , V_267 , V_304 ) ;
if ( ! V_308 )
return F_46 ( log , V_59 ) ;
ASSERT ( V_60 & V_225 ) ;
* V_308 = V_59 ;
return 0 ;
}
STATIC void
F_179 (
struct V_1 * log )
{
T_11 * V_59 ;
int V_317 = 0 ;
V_59 = log -> V_97 ;
do {
if ( V_59 -> V_67 == V_119 ) {
V_59 -> V_67 = V_69 ;
V_59 -> V_98 = 0 ;
ASSERT ( V_59 -> V_220 == NULL ) ;
if ( ! V_317 &&
( F_158 ( V_59 -> V_208 . V_269 ) ==
V_318 ) ) {
V_317 = 1 ;
} else {
V_317 = 2 ;
}
V_59 -> V_208 . V_269 = 0 ;
memset ( V_59 -> V_208 . V_238 , 0 ,
sizeof( V_59 -> V_208 . V_238 ) ) ;
V_59 -> V_208 . V_237 = 0 ;
} else if ( V_59 -> V_67 == V_69 )
;
else
break;
V_59 = V_59 -> V_99 ;
} while ( V_59 != log -> V_97 );
if ( V_317 ) {
switch ( log -> V_136 ) {
case V_139 :
case V_140 :
case V_141 :
log -> V_136 = V_140 ;
break;
case V_137 :
if ( V_317 == 1 )
log -> V_136 = V_141 ;
else
log -> V_136 = V_140 ;
break;
case V_138 :
if ( V_317 == 1 )
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
F_180 (
struct V_1 * log )
{
T_11 * V_319 ;
T_6 V_320 , V_61 ;
V_319 = log -> V_97 ;
V_320 = 0 ;
do {
if ( ! ( V_319 -> V_67 & ( V_69 | V_119 ) ) ) {
V_61 = F_155 ( V_319 -> V_208 . V_237 ) ;
if ( ( V_61 && ! V_320 ) ||
( F_136 ( V_61 , V_320 ) < 0 ) ) {
V_320 = V_61 ;
}
}
V_319 = V_319 -> V_99 ;
} while ( V_319 != log -> V_97 );
return V_320 ;
}
STATIC void
F_181 (
struct V_1 * log ,
int V_157 ,
struct V_58 * V_321 )
{
T_11 * V_59 ;
T_11 * V_95 ;
T_7 * V_64 , * V_71 ;
int V_322 = 0 ;
T_6 V_320 ;
int V_323 ;
int V_324 ;
int V_325 ;
int V_326 ;
int V_327 = 0 ;
F_12 ( & log -> V_117 ) ;
V_95 = V_59 = log -> V_97 ;
V_323 = 0 ;
V_325 = 0 ;
V_326 = 0 ;
do {
V_95 = log -> V_97 ;
V_59 = log -> V_97 ;
V_324 = 0 ;
V_326 ++ ;
do {
if ( V_59 -> V_67 &
( V_69 | V_119 ) ) {
V_59 = V_59 -> V_99 ;
continue;
}
if ( ! ( V_59 -> V_67 & V_68 ) ) {
if ( ! ( V_59 -> V_67 &
( V_328 |
V_329 ) ) ) {
if ( V_321 && ( V_321 -> V_67 ==
V_328 ) ) {
V_321 -> V_67 = V_329 ;
}
break;
}
V_320 = F_180 ( log ) ;
if ( V_320 &&
F_136 ( V_320 ,
F_155 ( V_59 -> V_208 . V_237 ) ) < 0 ) {
V_59 = V_59 -> V_99 ;
continue;
}
V_59 -> V_67 = V_330 ;
ASSERT ( F_136 ( F_2 ( & log -> V_146 ) ,
F_155 ( V_59 -> V_208 . V_237 ) ) <= 0 ) ;
if ( V_59 -> V_220 )
F_97 ( & log -> V_146 ,
F_155 ( V_59 -> V_208 . V_237 ) ) ;
} else
V_323 ++ ;
F_15 ( & log -> V_117 ) ;
F_12 ( & V_59 -> V_66 ) ;
V_64 = V_59 -> V_220 ;
while ( V_64 ) {
V_59 -> V_72 = & ( V_59 -> V_220 ) ;
V_59 -> V_220 = NULL ;
F_15 ( & V_59 -> V_66 ) ;
for (; V_64 ; V_64 = V_71 ) {
V_71 = V_64 -> V_71 ;
V_64 -> V_331 ( V_64 -> V_332 , V_157 ) ;
}
F_12 ( & V_59 -> V_66 ) ;
V_64 = V_59 -> V_220 ;
}
V_324 ++ ;
V_325 ++ ;
F_12 ( & log -> V_117 ) ;
ASSERT ( V_59 -> V_220 == NULL ) ;
F_15 ( & V_59 -> V_66 ) ;
if ( ! ( V_59 -> V_67 & V_68 ) )
V_59 -> V_67 = V_119 ;
F_179 ( log ) ;
F_182 ( & V_59 -> V_120 ) ;
V_59 = V_59 -> V_99 ;
} while ( V_95 != V_59 );
if ( V_326 > 5000 ) {
V_322 += V_326 ;
V_326 = 0 ;
F_55 ( log -> V_152 ,
L_94 ,
V_116 , V_322 ) ;
}
} while ( ! V_323 && V_324 );
#ifdef F_69
if ( V_325 ) {
V_95 = V_59 = log -> V_97 ;
do {
ASSERT ( V_59 -> V_67 != V_329 ) ;
if ( V_59 -> V_67 == V_70 ||
V_59 -> V_67 == V_333 ||
V_59 -> V_67 == V_328 ||
V_59 -> V_67 == V_68 )
break;
V_59 = V_59 -> V_99 ;
} while ( V_95 != V_59 );
}
#endif
if ( log -> V_97 -> V_67 & ( V_69 | V_68 ) )
V_327 = 1 ;
F_15 ( & log -> V_117 ) ;
if ( V_327 )
F_182 ( & log -> V_200 ) ;
}
STATIC void
F_107 (
T_11 * V_59 ,
int V_157 )
{
struct V_1 * log = V_59 -> V_156 ;
F_12 ( & log -> V_117 ) ;
ASSERT ( V_59 -> V_67 == V_333 ||
V_59 -> V_67 == V_68 ) ;
ASSERT ( F_150 ( & V_59 -> V_118 ) == 0 ) ;
ASSERT ( V_59 -> V_259 == 1 || V_59 -> V_259 == 2 ) ;
if ( V_59 -> V_67 != V_68 ) {
if ( -- V_59 -> V_259 == 1 ) {
F_15 ( & log -> V_117 ) ;
return;
}
V_59 -> V_67 = V_328 ;
}
F_182 ( & V_59 -> V_222 ) ;
F_15 ( & log -> V_117 ) ;
F_181 ( log , V_157 , V_59 ) ;
}
STATIC int
F_176 (
struct V_1 * log ,
int V_30 ,
struct V_58 * * V_183 ,
struct V_15 * V_57 ,
int * V_334 ,
int * V_335 )
{
int V_307 ;
T_15 * V_2 ;
T_11 * V_59 ;
int error ;
V_336:
F_12 ( & log -> V_117 ) ;
if ( F_26 ( log ) ) {
F_15 ( & log -> V_117 ) ;
return - V_39 ;
}
V_59 = log -> V_97 ;
if ( V_59 -> V_67 != V_69 ) {
F_27 ( V_337 ) ;
F_75 ( & log -> V_200 , & log -> V_117 ) ;
goto V_336;
}
V_2 = & V_59 -> V_208 ;
F_73 ( & V_59 -> V_118 ) ;
V_307 = V_59 -> V_98 ;
if ( V_307 == 0 ) {
V_57 -> V_42 -= log -> V_171 ;
F_24 ( V_57 ,
log -> V_171 ,
V_338 ) ;
V_2 -> V_339 = F_126 ( log -> V_191 ) ;
V_2 -> V_237 = F_183 (
F_135 ( log -> V_191 , log -> V_340 ) ) ;
ASSERT ( log -> V_340 >= 0 ) ;
}
if ( V_59 -> V_218 - V_59 -> V_98 < 2 * sizeof( V_271 ) ) {
F_184 ( log , V_59 , V_59 -> V_218 ) ;
if ( ! F_185 ( & V_59 -> V_118 , - 1 , 1 ) ) {
F_15 ( & log -> V_117 ) ;
error = F_46 ( log , V_59 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_117 ) ;
}
goto V_336;
}
if ( V_30 <= V_59 -> V_218 - V_59 -> V_98 ) {
* V_334 = 0 ;
V_59 -> V_98 += V_30 ;
} else {
* V_334 = 1 ;
F_184 ( log , V_59 , V_59 -> V_218 ) ;
}
* V_183 = V_59 ;
ASSERT ( V_59 -> V_98 <= V_59 -> V_218 ) ;
F_15 ( & log -> V_117 ) ;
* V_335 = V_307 ;
return 0 ;
}
STATIC void
F_42 (
struct V_1 * log ,
struct V_15 * V_57 )
{
F_186 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
V_57 -> V_22 -- ;
F_1 ( log , & log -> V_56 . V_12 ,
V_57 -> V_42 ) ;
F_1 ( log , & log -> V_18 . V_12 ,
V_57 -> V_42 ) ;
V_57 -> V_42 = V_57 -> V_21 ;
F_23 ( V_57 ) ;
F_187 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
return;
F_6 ( log , & log -> V_56 . V_12 ,
V_57 -> V_21 ) ;
F_188 ( log , V_57 ) ;
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
F_189 ( log , V_57 ) ;
F_190 ( log , V_57 ) ;
V_3 = V_57 -> V_42 ;
if ( V_57 -> V_22 > 0 ) {
ASSERT ( V_57 -> V_19 & V_20 ) ;
V_3 += V_57 -> V_21 * V_57 -> V_22 ;
}
F_1 ( log , & log -> V_56 . V_12 , V_3 ) ;
F_1 ( log , & log -> V_18 . V_12 , V_3 ) ;
F_191 ( log , V_57 ) ;
F_87 ( log -> V_152 ) ;
}
STATIC int
F_46 (
struct V_1 * log ,
struct V_58 * V_59 )
{
int V_341 = 0 ;
if ( V_59 -> V_67 & V_68 )
return - V_39 ;
ASSERT ( F_150 ( & V_59 -> V_118 ) > 0 ) ;
if ( ! F_192 ( & V_59 -> V_118 , & log -> V_117 ) )
return 0 ;
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_117 ) ;
return - V_39 ;
}
ASSERT ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_70 ) ;
if ( V_59 -> V_67 == V_70 ) {
T_6 V_143 = F_98 ( log -> V_152 ) ;
V_341 ++ ;
V_59 -> V_67 = V_333 ;
V_59 -> V_208 . V_342 = F_183 ( V_143 ) ;
F_193 ( log , V_59 , V_143 ) ;
}
F_15 ( & log -> V_117 ) ;
if ( V_341 )
return F_149 ( log , V_59 ) ;
return 0 ;
}
STATIC void
F_184 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_343 )
{
ASSERT ( V_59 -> V_67 == V_69 ) ;
if ( ! V_343 )
V_343 = V_59 -> V_98 ;
V_59 -> V_67 = V_70 ;
V_59 -> V_208 . V_344 = F_126 ( log -> V_190 ) ;
log -> V_190 = log -> V_340 ;
log -> V_345 = log -> V_191 ;
log -> V_340 += F_122 ( V_343 ) + F_122 ( log -> V_171 ) ;
if ( F_109 ( & log -> V_152 -> V_80 ) &&
log -> V_152 -> V_80 . V_255 > 1 ) {
T_13 V_346 = F_122 ( log -> V_152 -> V_80 . V_255 ) ;
log -> V_340 = F_194 ( log -> V_340 , V_346 ) ;
}
if ( log -> V_340 >= log -> V_189 ) {
log -> V_191 ++ ;
if ( log -> V_191 == V_210 )
log -> V_191 ++ ;
log -> V_340 -= log -> V_189 ;
ASSERT ( log -> V_340 >= 0 ) ;
}
ASSERT ( V_59 == log -> V_97 ) ;
log -> V_97 = V_59 -> V_99 ;
}
int
F_70 (
struct V_36 * V_37 ,
T_4 V_60 ,
int * V_347 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
T_6 V_61 ;
F_27 ( V_348 ) ;
F_195 ( log ) ;
F_12 ( & log -> V_117 ) ;
V_59 = log -> V_97 ;
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_117 ) ;
return - V_39 ;
}
if ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_119 ) {
if ( V_59 -> V_67 == V_119 ||
( F_150 ( & V_59 -> V_118 ) == 0
&& V_59 -> V_98 == 0 ) ) {
V_59 = V_59 -> V_202 ;
if ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_119 )
goto V_349;
else
goto V_350;
} else {
if ( F_150 ( & V_59 -> V_118 ) == 0 ) {
F_73 ( & V_59 -> V_118 ) ;
V_61 = F_155 ( V_59 -> V_208 . V_237 ) ;
F_184 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_117 ) ;
if ( F_46 ( log , V_59 ) )
return - V_39 ;
if ( V_347 )
* V_347 = 1 ;
F_12 ( & log -> V_117 ) ;
if ( F_155 ( V_59 -> V_208 . V_237 ) == V_61 &&
V_59 -> V_67 != V_119 )
goto V_350;
else
goto V_349;
} else {
F_184 ( log , V_59 , 0 ) ;
goto V_350;
}
}
}
V_350:
if ( V_60 & V_96 ) {
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_117 ) ;
return - V_39 ;
}
F_27 ( V_351 ) ;
F_75 ( & V_59 -> V_120 , & log -> V_117 ) ;
if ( V_59 -> V_67 & V_68 )
return - V_39 ;
if ( V_347 )
* V_347 = 1 ;
} else {
V_349:
F_15 ( & log -> V_117 ) ;
}
return 0 ;
}
void
F_79 (
T_8 * V_37 ,
T_4 V_60 )
{
int error ;
F_196 ( V_37 , 0 ) ;
error = F_70 ( V_37 , V_60 , NULL ) ;
if ( error )
F_55 ( V_37 , L_95 , V_116 , error ) ;
}
int
F_197 (
struct V_36 * V_37 ,
T_6 V_61 ,
T_4 V_60 ,
int * V_347 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
int V_352 = 0 ;
ASSERT ( V_61 != 0 ) ;
F_27 ( V_348 ) ;
V_61 = F_198 ( log , V_61 ) ;
if ( V_61 == V_353 )
return 0 ;
V_354:
F_12 ( & log -> V_117 ) ;
V_59 = log -> V_97 ;
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_117 ) ;
return - V_39 ;
}
do {
if ( F_155 ( V_59 -> V_208 . V_237 ) != V_61 ) {
V_59 = V_59 -> V_99 ;
continue;
}
if ( V_59 -> V_67 == V_119 ) {
F_15 ( & log -> V_117 ) ;
return 0 ;
}
if ( V_59 -> V_67 == V_69 ) {
if ( ! V_352 &&
( V_59 -> V_202 -> V_67 &
( V_70 | V_333 ) ) ) {
ASSERT ( ! ( V_59 -> V_67 & V_68 ) ) ;
F_27 ( V_351 ) ;
F_75 ( & V_59 -> V_202 -> V_222 ,
& log -> V_117 ) ;
if ( V_347 )
* V_347 = 1 ;
V_352 = 1 ;
goto V_354;
}
F_73 ( & V_59 -> V_118 ) ;
F_184 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_117 ) ;
if ( F_46 ( log , V_59 ) )
return - V_39 ;
if ( V_347 )
* V_347 = 1 ;
F_12 ( & log -> V_117 ) ;
}
if ( ( V_60 & V_96 ) &&
! ( V_59 -> V_67 &
( V_69 | V_119 ) ) ) {
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_117 ) ;
return - V_39 ;
}
F_27 ( V_351 ) ;
F_75 ( & V_59 -> V_120 , & log -> V_117 ) ;
if ( V_59 -> V_67 & V_68 )
return - V_39 ;
if ( V_347 )
* V_347 = 1 ;
} else {
F_15 ( & log -> V_117 ) ;
}
return 0 ;
} while ( V_59 != log -> V_97 );
F_15 ( & log -> V_117 ) ;
return 0 ;
}
void
F_199 (
T_8 * V_37 ,
T_6 V_61 ,
T_4 V_60 )
{
int error ;
F_196 ( V_37 , V_61 ) ;
error = F_197 ( V_37 , V_61 , V_60 , NULL ) ;
if ( error )
F_55 ( V_37 , L_95 , V_116 , error ) ;
}
STATIC void
F_74 (
struct V_1 * log ,
struct V_58 * V_59 )
{
F_94 ( & log -> V_117 ) ;
if ( V_59 -> V_67 == V_69 ) {
F_184 ( log , V_59 , 0 ) ;
} else {
ASSERT ( V_59 -> V_67 &
( V_70 | V_68 ) ) ;
}
}
void
F_40 (
T_3 * V_57 )
{
ASSERT ( F_150 ( & V_57 -> V_355 ) > 0 ) ;
if ( F_200 ( & V_57 -> V_355 ) )
F_201 ( V_356 , V_57 ) ;
}
T_3 *
F_202 (
T_3 * V_57 )
{
ASSERT ( F_150 ( & V_57 -> V_355 ) > 0 ) ;
F_73 ( & V_57 -> V_355 ) ;
return V_57 ;
}
int
F_203 (
struct V_36 * V_37 ,
int V_44 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_357 ;
T_4 V_358 ;
V_44 += sizeof( V_271 ) ;
V_44 += sizeof( V_359 ) ;
V_44 += sizeof( V_271 ) ;
V_357 = log -> V_168 - log -> V_171 ;
V_358 = F_204 ( V_44 , V_357 ) ;
V_44 += sizeof( V_271 ) * V_358 ;
while ( ! V_358 ||
F_204 ( V_44 , V_357 ) > V_358 ) {
V_44 += sizeof( V_271 ) ;
V_358 ++ ;
}
V_44 += log -> V_171 * V_358 ;
V_44 += log -> V_171 ;
if ( F_109 ( & V_37 -> V_80 ) && V_37 -> V_80 . V_255 > 1 ) {
V_44 += 2 * V_37 -> V_80 . V_255 ;
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
T_19 V_360 )
{
struct V_15 * V_16 ;
int V_361 ;
V_16 = F_205 ( V_356 , V_360 ) ;
if ( ! V_16 )
return NULL ;
V_361 = F_203 ( log -> V_152 , V_44 ) ;
F_127 ( & V_16 -> V_355 , 1 ) ;
V_16 -> V_17 = V_362 ;
F_9 ( & V_16 -> V_363 ) ;
V_16 -> V_21 = V_361 ;
V_16 -> V_42 = V_361 ;
V_16 -> V_22 = V_45 ;
V_16 -> V_364 = V_45 ;
V_16 -> V_41 = F_206 () ;
V_16 -> V_288 = V_47 ;
V_16 -> V_19 = V_62 ;
V_16 -> V_55 = 0 ;
if ( V_48 )
V_16 -> V_19 |= V_20 ;
F_23 ( V_16 ) ;
return V_16 ;
}
void
F_178 (
struct V_1 * log ,
char * V_312 )
{
int V_185 ;
int V_365 = 0 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
if ( V_312 >= log -> V_206 [ V_185 ] &&
V_312 <= log -> V_206 [ V_185 ] + log -> V_168 )
V_365 ++ ;
}
if ( ! V_365 )
F_207 ( log -> V_152 , L_96 , V_116 ) ;
}
STATIC void
F_31 (
struct V_1 * log )
{
int V_149 , V_366 ;
int V_7 , V_8 ;
F_99 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_100 ( & log -> V_147 , & V_149 , & V_366 ) ;
if ( V_149 != V_7 ) {
if ( V_7 - 1 != V_149 &&
! ( log -> V_25 & V_367 ) ) {
F_170 ( log -> V_152 , V_276 ,
L_97 , V_116 ) ;
log -> V_25 |= V_367 ;
}
if ( V_8 > F_101 ( V_366 ) &&
! ( log -> V_25 & V_367 ) ) {
F_170 ( log -> V_152 , V_276 ,
L_98 , V_116 ) ;
log -> V_25 |= V_367 ;
}
}
}
STATIC void
F_193 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_6 V_143 )
{
int V_368 ;
if ( F_208 ( V_143 ) == log -> V_345 ) {
V_368 =
log -> V_189 - ( log -> V_190 - F_154 ( V_143 ) ) ;
if ( V_368 < F_122 ( V_59 -> V_98 ) + F_122 ( log -> V_171 ) )
F_207 ( log -> V_152 , L_99 , V_116 ) ;
} else {
ASSERT ( F_208 ( V_143 ) + 1 == log -> V_345 ) ;
if ( F_154 ( V_143 ) == log -> V_190 )
F_207 ( log -> V_152 , L_100 , V_116 ) ;
V_368 = F_154 ( V_143 ) - log -> V_190 ;
if ( V_368 < F_122 ( V_59 -> V_98 ) + 1 )
F_207 ( log -> V_152 , L_99 , V_116 ) ;
}
}
STATIC void
F_162 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_250 ,
bool V_369 )
{
V_271 * V_370 ;
T_11 * V_371 ;
T_17 * V_239 ;
V_207 V_312 ;
V_207 V_372 ;
T_20 V_373 ;
T_5 V_374 ;
int V_30 , V_185 , V_233 , V_234 , V_375 ;
int V_376 ;
F_12 ( & log -> V_117 ) ;
V_371 = log -> V_97 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ , V_371 = V_371 -> V_99 )
ASSERT ( V_371 ) ;
if ( V_371 != log -> V_97 )
F_207 ( log -> V_152 , L_101 , V_116 ) ;
F_15 ( & log -> V_117 ) ;
if ( V_59 -> V_208 . V_209 != F_126 ( V_210 ) )
F_207 ( log -> V_152 , L_102 , V_116 ) ;
V_312 = ( V_207 ) & V_59 -> V_208 ;
for ( V_312 += V_175 ; V_312 < ( ( V_207 ) & V_59 -> V_208 ) + V_250 ;
V_312 += V_175 ) {
if ( * ( T_16 * ) V_312 == F_126 ( V_210 ) )
F_207 ( log -> V_152 , L_103 ,
V_116 ) ;
}
V_30 = F_158 ( V_59 -> V_208 . V_269 ) ;
V_312 = V_59 -> V_221 ;
V_372 = V_312 ;
V_370 = ( V_271 * ) V_312 ;
V_239 = V_59 -> V_204 ;
for ( V_185 = 0 ; V_185 < V_30 ; V_185 ++ ) {
V_370 = ( V_271 * ) V_312 ;
V_373 = ( T_20 )
( ( V_207 ) & ( V_370 -> V_287 ) - V_372 ) ;
if ( ! V_369 || ( V_373 & 0x1ff ) ) {
V_374 = V_370 -> V_287 ;
} else {
V_376 = F_133 ( ( V_207 ) & ( V_370 -> V_287 ) - V_59 -> V_221 ) ;
if ( V_376 >= ( V_170 / V_175 ) ) {
V_233 = V_376 / ( V_170 / V_175 ) ;
V_234 = V_376 % ( V_170 / V_175 ) ;
V_374 = F_209 (
V_239 [ V_233 ] . V_240 . V_241 [ V_234 ] ) ;
} else {
V_374 = F_209 (
V_59 -> V_208 . V_238 [ V_376 ] ) ;
}
}
if ( V_374 != V_50 && V_374 != V_51 )
F_55 ( log -> V_152 ,
L_104 ,
V_116 , V_374 , V_370 ,
( unsigned long ) V_373 ) ;
V_373 = ( T_20 )
( ( V_207 ) & ( V_370 -> V_289 ) - V_372 ) ;
if ( ! V_369 || ( V_373 & 0x1ff ) ) {
V_375 = F_158 ( V_370 -> V_289 ) ;
} else {
V_376 = F_133 ( ( T_20 ) & V_370 -> V_289 -
( T_20 ) V_59 -> V_221 ) ;
if ( V_376 >= ( V_170 / V_175 ) ) {
V_233 = V_376 / ( V_170 / V_175 ) ;
V_234 = V_376 % ( V_170 / V_175 ) ;
V_375 = F_158 ( V_239 [ V_233 ] . V_240 . V_241 [ V_234 ] ) ;
} else {
V_375 = F_158 ( V_59 -> V_208 . V_238 [ V_376 ] ) ;
}
}
V_312 += sizeof( V_271 ) + V_375 ;
}
}
STATIC int
F_210 (
struct V_1 * log )
{
T_11 * V_59 , * V_377 ;
V_59 = log -> V_97 ;
if ( ! ( V_59 -> V_67 & V_68 ) ) {
V_377 = V_59 ;
do {
V_377 -> V_67 = V_68 ;
V_377 = V_377 -> V_99 ;
} while ( V_377 != V_59 );
return 0 ;
}
return 1 ;
}
int
F_211 (
struct V_36 * V_37 ,
int V_378 )
{
struct V_1 * log ;
int V_379 ;
log = V_37 -> V_38 ;
if ( ! log ||
log -> V_25 & V_26 ) {
V_37 -> V_78 |= V_380 ;
if ( V_37 -> V_123 )
F_212 ( V_37 -> V_123 ) ;
return 0 ;
}
if ( V_378 && log -> V_97 -> V_67 & V_68 ) {
ASSERT ( F_26 ( log ) ) ;
return 1 ;
}
V_379 = 0 ;
if ( ! V_378 )
F_195 ( log ) ;
F_12 ( & log -> V_117 ) ;
V_37 -> V_78 |= V_380 ;
if ( V_37 -> V_123 )
F_212 ( V_37 -> V_123 ) ;
log -> V_25 |= V_381 ;
if ( V_378 )
V_379 = F_210 ( log ) ;
F_15 ( & log -> V_117 ) ;
F_11 ( & log -> V_56 ) ;
F_11 ( & log -> V_18 ) ;
if ( ! ( log -> V_97 -> V_67 & V_68 ) ) {
ASSERT ( ! V_378 ) ;
F_70 ( V_37 , V_96 , NULL ) ;
F_12 ( & log -> V_117 ) ;
V_379 = F_210 ( log ) ;
F_15 ( & log -> V_117 ) ;
}
F_182 ( & log -> V_382 -> V_383 ) ;
F_181 ( log , V_161 , NULL ) ;
#ifdef F_213
{
T_11 * V_59 ;
F_12 ( & log -> V_117 ) ;
V_59 = log -> V_97 ;
do {
ASSERT ( V_59 -> V_220 == 0 ) ;
V_59 = V_59 -> V_99 ;
} while ( V_59 != log -> V_97 );
F_15 ( & log -> V_117 ) ;
}
#endif
return V_379 ;
}
STATIC int
F_92 (
struct V_1 * log )
{
T_11 * V_59 ;
V_59 = log -> V_97 ;
do {
if ( V_59 -> V_208 . V_269 )
return 0 ;
V_59 = V_59 -> V_99 ;
} while ( V_59 != log -> V_97 );
return 1 ;
}
