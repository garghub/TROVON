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
STATIC bool
F_7 (
struct log * log ,
int * V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
F_8 (tic, &log->l_reserveq, t_queue) {
if ( V_12 -> V_14 & V_15 )
V_13 = V_12 -> V_16 * V_12 -> V_17 ;
else
V_13 = V_12 -> V_16 ;
if ( * V_10 < V_13 )
return false ;
* V_10 -= V_13 ;
F_9 ( log , V_12 ) ;
F_10 ( & V_12 -> V_18 ) ;
}
return true ;
}
STATIC bool
F_11 (
struct log * log ,
int * V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
F_8 (tic, &log->l_writeq, t_queue) {
ASSERT ( V_12 -> V_14 & V_15 ) ;
V_13 = V_12 -> V_16 ;
if ( * V_10 < V_13 )
return false ;
* V_10 -= V_13 ;
F_12 ( log , V_12 ) ;
F_10 ( & V_12 -> V_18 ) ;
}
return true ;
}
STATIC int
F_13 (
struct log * log ,
struct V_11 * V_12 ,
int V_13 )
{
F_14 ( & V_12 -> V_19 , & log -> V_20 ) ;
do {
if ( F_15 ( log ) )
goto V_21;
F_16 ( log , V_13 ) ;
F_17 ( V_22 ) ;
F_18 ( log , V_12 ) ;
F_19 ( & V_12 -> V_18 , & log -> V_23 ) ;
F_20 ( log , V_12 ) ;
F_21 ( & log -> V_23 ) ;
if ( F_15 ( log ) )
goto V_21;
} while ( F_22 ( log , & log -> V_24 ) < V_13 );
F_23 ( & V_12 -> V_19 ) ;
return 0 ;
V_21:
F_23 ( & V_12 -> V_19 ) ;
return F_24 ( V_25 ) ;
}
STATIC int
F_25 (
struct log * log ,
struct V_11 * V_12 ,
int V_13 )
{
F_14 ( & V_12 -> V_19 , & log -> V_26 ) ;
do {
if ( F_15 ( log ) )
goto V_21;
F_16 ( log , V_13 ) ;
F_17 ( V_22 ) ;
F_26 ( log , V_12 ) ;
F_19 ( & V_12 -> V_18 , & log -> V_27 ) ;
F_27 ( log , V_12 ) ;
F_21 ( & log -> V_27 ) ;
if ( F_15 ( log ) )
goto V_21;
} while ( F_22 ( log , & log -> V_28 ) < V_13 );
F_23 ( & V_12 -> V_19 ) ;
return 0 ;
V_21:
F_23 ( & V_12 -> V_19 ) ;
return F_24 ( V_25 ) ;
}
static void
F_28 ( T_3 * V_12 )
{
V_12 -> V_29 = 0 ;
V_12 -> V_30 = 0 ;
V_12 -> V_31 = 0 ;
}
static void
F_29 ( T_3 * V_12 , T_4 V_32 , T_4 type )
{
if ( V_12 -> V_29 == V_33 ) {
V_12 -> V_34 += V_12 -> V_30 ;
V_12 -> V_29 = 0 ;
V_12 -> V_30 = 0 ;
}
V_12 -> V_35 [ V_12 -> V_29 ] . V_36 = V_32 ;
V_12 -> V_35 [ V_12 -> V_29 ] . V_37 = type ;
V_12 -> V_30 += V_32 ;
V_12 -> V_29 ++ ;
}
T_5
F_30 (
struct V_38 * V_39 ,
struct V_11 * V_40 ,
struct V_41 * * V_42 ,
T_4 V_43 )
{
struct log * log = V_39 -> V_44 ;
T_5 V_45 = 0 ;
if ( F_15 ( log ) ||
( ( ( V_40 -> V_14 & V_46 ) == 0 ) &&
( F_31 ( log , V_40 , V_42 , & V_45 ) ) ) ) {
V_45 = ( T_5 ) - 1 ;
if ( V_40 -> V_14 & V_15 ) {
V_43 |= V_47 ;
}
}
if ( ( V_40 -> V_14 & V_15 ) == 0 ||
( V_43 & V_47 ) ) {
F_32 ( log , V_40 ) ;
F_33 ( log , V_40 ) ;
F_34 ( V_40 ) ;
} else {
F_35 ( log , V_40 ) ;
F_36 ( log , V_40 ) ;
V_40 -> V_14 |= V_46 ;
}
return V_45 ;
}
int
F_37 (
struct V_38 * V_39 ,
struct V_41 * V_42 ,
T_6 * V_48 )
{
int V_49 ;
F_21 ( & V_42 -> V_50 ) ;
V_49 = ( V_42 -> V_51 & V_52 ) ;
if ( ! V_49 ) {
F_38 ( ( V_42 -> V_51 == V_53 ) ||
( V_42 -> V_51 == V_54 ) ) ;
V_48 -> V_55 = NULL ;
* ( V_42 -> V_56 ) = V_48 ;
V_42 -> V_56 = & ( V_48 -> V_55 ) ;
}
F_39 ( & V_42 -> V_50 ) ;
return V_49 ;
}
int
F_40 (
struct V_38 * V_39 ,
struct V_41 * V_42 )
{
if ( F_41 ( V_39 -> V_44 , V_42 ) ) {
F_42 ( V_39 , V_57 ) ;
return V_25 ;
}
return 0 ;
}
int
F_43 (
struct V_38 * V_39 ,
int V_58 ,
int V_59 ,
struct V_11 * * V_40 ,
T_7 V_60 ,
T_4 V_43 ,
T_4 V_61 )
{
struct log * log = V_39 -> V_44 ;
struct V_11 * V_62 ;
int V_63 = 0 ;
ASSERT ( V_60 == V_64 || V_60 == V_65 ) ;
if ( F_15 ( log ) )
return F_24 ( V_25 ) ;
F_17 ( V_66 ) ;
if ( * V_40 != NULL ) {
ASSERT ( V_43 & V_67 ) ;
V_62 = * V_40 ;
V_62 -> V_68 ++ ;
F_44 ( log , V_62 ) ;
F_16 ( log , V_62 -> V_16 ) ;
V_63 = F_45 ( log , V_62 ) ;
} else {
V_62 = F_46 ( log , V_58 , V_59 ,
V_60 , V_43 ,
V_69 | V_70 ) ;
if ( ! V_62 )
return F_24 ( V_71 ) ;
V_62 -> V_72 = V_61 ;
* V_40 = V_62 ;
F_44 ( log , V_62 ) ;
F_16 ( log ,
( V_62 -> V_16 *
V_62 -> V_17 ) ) ;
V_63 = F_47 ( log , V_62 ) ;
}
if ( F_48 ( V_63 ) ) {
V_62 -> V_73 = 0 ;
V_62 -> V_17 = 0 ;
}
return V_63 ;
}
int
F_49 (
T_8 * V_39 ,
T_9 * V_74 ,
T_10 V_75 ,
int V_76 )
{
int error ;
if ( ! ( V_39 -> V_77 & V_78 ) )
F_50 ( V_39 , L_1 ) ;
else {
F_50 ( V_39 ,
L_2 ) ;
ASSERT ( V_39 -> V_77 & V_79 ) ;
}
V_39 -> V_44 = F_51 ( V_39 , V_74 , V_75 , V_76 ) ;
if ( F_52 ( V_39 -> V_44 ) ) {
error = - F_53 ( V_39 -> V_44 ) ;
goto V_80;
}
error = F_54 ( V_39 ) ;
if ( error ) {
F_55 ( V_39 , L_3 , error ) ;
goto V_81;
}
V_39 -> V_44 -> V_82 = V_39 -> V_83 ;
if ( ! ( V_39 -> V_77 & V_78 ) ) {
int V_84 = ( V_39 -> V_77 & V_79 ) ;
if ( V_84 )
V_39 -> V_77 &= ~ V_79 ;
error = F_56 ( V_39 -> V_44 ) ;
if ( V_84 )
V_39 -> V_77 |= V_79 ;
if ( error ) {
F_55 ( V_39 , L_4 ,
error ) ;
goto V_85;
}
}
V_39 -> V_44 -> V_86 &= ~ V_87 ;
F_57 ( V_39 -> V_44 ) ;
return 0 ;
V_85:
F_58 ( V_39 ) ;
V_81:
F_59 ( V_39 -> V_44 ) ;
V_80:
return error ;
}
int
F_60 ( T_8 * V_39 )
{
int error ;
if ( ! ( V_39 -> V_77 & V_78 ) )
error = F_61 ( V_39 -> V_44 ) ;
else {
error = 0 ;
ASSERT ( V_39 -> V_77 & V_79 ) ;
}
return error ;
}
int
F_62 ( T_8 * V_39 )
{
T_11 * log = V_39 -> V_44 ;
T_12 * V_42 ;
#ifdef F_63
T_12 * V_88 ;
#endif
T_3 * V_12 = NULL ;
T_5 V_45 ;
int error ;
if ( V_39 -> V_77 & V_79 )
return 0 ;
error = F_64 ( V_39 , V_89 , NULL ) ;
ASSERT ( error || ! ( F_15 ( log ) ) ) ;
#ifdef F_63
V_88 = V_42 = log -> V_90 ;
do {
if ( ! ( V_42 -> V_51 & V_52 ) ) {
ASSERT ( V_42 -> V_51 & V_53 ) ;
ASSERT ( V_42 -> V_91 == 0 ) ;
}
V_42 = V_42 -> V_92 ;
} while ( V_42 != V_88 );
#endif
if ( ! ( F_15 ( log ) ) ) {
error = F_43 ( V_39 , 600 , 1 , & V_12 ,
V_65 , 0 , V_93 ) ;
if ( ! error ) {
struct {
T_13 V_94 ;
T_13 V_95 ;
T_14 V_96 ;
} V_94 = {
. V_94 = V_97 ,
} ;
struct V_98 V_99 = {
. V_100 = & V_94 ,
. V_101 = sizeof( V_94 ) ,
. V_102 = V_103 ,
} ;
struct V_104 V_105 = {
. V_106 = 1 ,
. V_107 = & V_99 ,
} ;
V_12 -> V_14 = 0 ;
error = F_65 ( log , & V_105 , V_12 , & V_45 ,
NULL , V_108 ) ;
}
if ( error )
F_66 ( V_39 , L_5 , V_109 ) ;
F_21 ( & log -> V_110 ) ;
V_42 = log -> V_90 ;
F_67 ( & V_42 -> V_111 ) ;
F_68 ( log , V_42 ) ;
F_39 ( & log -> V_110 ) ;
error = F_41 ( log , V_42 ) ;
F_21 ( & log -> V_110 ) ;
if ( ! ( V_42 -> V_51 == V_53 ||
V_42 -> V_51 == V_112 ) ) {
if ( ! F_15 ( log ) ) {
F_19 ( & V_42 -> V_113 ,
& log -> V_110 ) ;
} else {
F_39 ( & log -> V_110 ) ;
}
} else {
F_39 ( & log -> V_110 ) ;
}
if ( V_12 ) {
F_69 ( log , V_12 ) ;
F_33 ( log , V_12 ) ;
F_34 ( V_12 ) ;
}
} else {
F_21 ( & log -> V_110 ) ;
V_42 = log -> V_90 ;
F_67 ( & V_42 -> V_111 ) ;
F_68 ( log , V_42 ) ;
F_39 ( & log -> V_110 ) ;
error = F_41 ( log , V_42 ) ;
F_21 ( & log -> V_110 ) ;
if ( ! ( V_42 -> V_51 == V_53
|| V_42 -> V_51 == V_112
|| V_42 -> V_51 == V_52 ) ) {
F_19 ( & V_42 -> V_113 ,
& log -> V_110 ) ;
} else {
F_39 ( & log -> V_110 ) ;
}
}
return error ;
}
void
F_70 ( T_8 * V_39 )
{
F_58 ( V_39 ) ;
F_59 ( V_39 -> V_44 ) ;
}
void
F_71 (
struct V_38 * V_39 ,
struct V_114 * V_115 ,
int type ,
const struct V_116 * V_117 )
{
V_115 -> V_118 = V_39 ;
V_115 -> V_119 = V_39 -> V_83 ;
V_115 -> V_120 = type ;
V_115 -> V_121 = V_117 ;
V_115 -> V_122 = NULL ;
F_72 ( & V_115 -> V_123 ) ;
F_72 ( & V_115 -> V_124 ) ;
}
void
F_73 ( T_8 * V_39 ,
T_5 V_125 )
{
T_3 * V_12 ;
T_11 * log = V_39 -> V_44 ;
int V_13 , V_10 ;
if ( F_15 ( log ) )
return;
if ( V_125 == 0 )
V_125 = F_2 ( & log -> V_126 ) ;
if ( V_125 != 1 )
F_74 ( & log -> V_127 , V_125 ) ;
if ( ! F_75 ( & log -> V_26 ) ) {
#ifdef F_63
if ( log -> V_86 & V_87 )
F_76 ( L_6 ) ;
#endif
F_21 ( & log -> V_27 ) ;
V_10 = F_22 ( log , & log -> V_28 ) ;
F_8 (tic, &log->l_writeq, t_queue) {
ASSERT ( V_12 -> V_14 & V_15 ) ;
if ( V_10 < V_12 -> V_16 && V_125 != 1 )
break;
V_125 = 0 ;
V_10 -= V_12 -> V_16 ;
F_12 ( log , V_12 ) ;
F_10 ( & V_12 -> V_18 ) ;
}
F_39 ( & log -> V_27 ) ;
}
if ( ! F_75 ( & log -> V_20 ) ) {
#ifdef F_63
if ( log -> V_86 & V_87 )
F_76 ( L_6 ) ;
#endif
F_21 ( & log -> V_23 ) ;
V_10 = F_22 ( log , & log -> V_24 ) ;
F_8 (tic, &log->l_reserveq, t_queue) {
if ( V_12 -> V_14 & V_15 )
V_13 = V_12 -> V_16 * V_12 -> V_17 ;
else
V_13 = V_12 -> V_16 ;
if ( V_10 < V_13 && V_125 != 1 )
break;
V_125 = 0 ;
V_10 -= V_13 ;
F_9 ( log , V_12 ) ;
F_10 ( & V_12 -> V_18 ) ;
}
F_39 ( & log -> V_23 ) ;
}
}
int
F_77 ( T_8 * V_39 )
{
int V_128 = 0 ;
T_11 * log = V_39 -> V_44 ;
if ( ! F_78 ( V_39 ) )
return 0 ;
F_21 ( & log -> V_110 ) ;
switch ( log -> V_129 ) {
case V_130 :
case V_131 :
case V_132 :
break;
case V_133 :
case V_134 :
if ( ! F_79 ( log -> V_82 ) &&
F_80 ( log ) ) {
if ( log -> V_129 == V_133 )
log -> V_129 = V_130 ;
else
log -> V_129 = V_131 ;
}
default:
V_128 = 1 ;
break;
}
F_39 ( & log -> V_110 ) ;
return V_128 ;
}
T_5
F_81 (
struct V_38 * V_39 )
{
T_5 V_125 ;
struct log * log = V_39 -> V_44 ;
V_125 = F_79 ( V_39 -> V_83 ) ;
if ( ! V_125 )
V_125 = F_2 ( & log -> V_126 ) ;
F_74 ( & log -> V_127 , V_125 ) ;
return V_125 ;
}
STATIC int
F_22 (
struct log * log ,
T_1 * V_1 )
{
int V_10 ;
int V_135 ;
int V_136 ;
int V_137 ;
int V_138 ;
F_82 ( V_1 , & V_137 , & V_138 ) ;
F_83 ( & log -> V_127 , & V_136 , & V_135 ) ;
V_135 = F_84 ( V_135 ) ;
if ( V_136 == V_137 && V_138 >= V_135 )
V_10 = log -> V_8 - ( V_138 - V_135 ) ;
else if ( V_136 + 1 < V_137 )
return 0 ;
else if ( V_136 < V_137 ) {
ASSERT ( V_136 == ( V_137 - 1 ) ) ;
V_10 = V_135 - V_138 ;
} else {
F_66 ( log -> V_139 ,
L_7
L_8
L_9 ,
V_136 , V_135 , V_137 , V_138 ) ;
ASSERT ( 0 ) ;
V_10 = log -> V_8 ;
}
return V_10 ;
}
void
F_85 ( T_15 * V_140 )
{
T_12 * V_42 = V_140 -> V_141 ;
T_11 * V_142 = V_42 -> V_143 ;
int V_144 = 0 ;
if ( F_86 ( ( F_87 ( V_140 ) ) , V_142 -> V_139 ,
V_145 , V_146 ) ) {
F_88 ( V_140 , V_109 ) ;
F_89 ( V_140 ) ;
F_42 ( V_142 -> V_139 , V_57 ) ;
V_144 = V_147 ;
} else if ( V_42 -> V_51 & V_52 ) {
V_144 = V_147 ;
}
ASSERT ( F_90 ( V_140 ) ) ;
F_91 ( V_42 , V_144 ) ;
}
STATIC void
F_92 ( T_8 * V_39 ,
T_11 * log )
{
int V_148 ;
int V_149 ;
if ( V_39 -> V_150 <= 0 )
log -> V_151 = V_152 ;
else
log -> V_151 = V_39 -> V_150 ;
if ( V_39 -> V_153 > 0 ) {
V_148 = log -> V_154 = V_39 -> V_153 ;
log -> V_155 = 0 ;
while ( V_148 != 1 ) {
log -> V_155 ++ ;
V_148 >>= 1 ;
}
if ( F_93 ( & V_39 -> V_156 ) ) {
V_149 = V_39 -> V_153 / V_157 ;
if ( V_39 -> V_153 % V_157 )
V_149 ++ ;
log -> V_158 = V_149 << V_159 ;
log -> V_160 = V_149 ;
} else {
ASSERT ( V_39 -> V_153 <= V_161 ) ;
log -> V_158 = V_162 ;
log -> V_160 = 1 ;
}
goto V_163;
}
log -> V_154 = V_161 ;
log -> V_155 = V_164 ;
log -> V_158 = V_162 ;
log -> V_160 = 1 ;
V_163:
if ( V_39 -> V_150 == 0 )
V_39 -> V_150 = log -> V_151 ;
if ( V_39 -> V_153 == 0 )
V_39 -> V_153 = log -> V_154 ;
}
STATIC T_11 *
F_51 ( T_8 * V_39 ,
T_9 * V_74 ,
T_10 V_75 ,
int V_76 )
{
T_11 * log ;
T_16 * V_1 ;
T_12 * * V_165 ;
T_12 * V_42 , * V_166 = NULL ;
T_15 * V_140 ;
int V_167 ;
int error = V_71 ;
T_4 V_168 = 0 ;
log = F_94 ( sizeof( T_11 ) , V_70 ) ;
if ( ! log ) {
F_55 ( V_39 , L_10 ) ;
goto V_80;
}
log -> V_139 = V_39 ;
log -> V_169 = V_74 ;
log -> V_8 = F_84 ( V_76 ) ;
log -> V_170 = V_75 ;
log -> V_171 = V_76 ;
log -> V_129 = V_132 ;
log -> V_86 |= V_87 ;
log -> V_172 = - 1 ;
F_95 ( & log -> V_127 , 1 , 0 ) ;
F_95 ( & log -> V_126 , 1 , 0 ) ;
log -> V_173 = 1 ;
F_96 ( & log -> V_24 , 1 , 0 ) ;
F_96 ( & log -> V_28 , 1 , 0 ) ;
F_72 ( & log -> V_20 ) ;
F_72 ( & log -> V_26 ) ;
F_97 ( & log -> V_23 ) ;
F_97 ( & log -> V_27 ) ;
error = V_174 ;
if ( F_98 ( & V_39 -> V_156 ) ) {
V_168 = V_39 -> V_156 . V_175 ;
if ( V_168 < V_159 ) {
F_55 ( V_39 , L_11 ,
V_168 , V_159 ) ;
goto V_81;
}
V_168 -= V_159 ;
if ( V_168 > V_39 -> V_176 ) {
F_55 ( V_39 , L_12 ,
V_168 , V_39 -> V_176 ) ;
goto V_81;
}
if ( V_168 && log -> V_170 > 0 &&
! F_93 ( & V_39 -> V_156 ) ) {
F_55 ( V_39 ,
L_13 ,
V_168 ) ;
goto V_81;
}
}
log -> V_177 = 1 << V_168 ;
F_92 ( V_39 , log ) ;
error = V_71 ;
V_140 = F_99 ( V_39 -> V_178 , 0 , log -> V_154 , 0 ) ;
if ( ! V_140 )
goto V_81;
V_140 -> V_179 = F_85 ;
ASSERT ( F_100 ( V_140 ) ) ;
log -> V_180 = V_140 ;
F_97 ( & log -> V_110 ) ;
F_101 ( & log -> V_181 ) ;
ASSERT ( ( F_102 ( V_140 ) & V_182 ) == 0 ) ;
V_165 = & log -> V_90 ;
ASSERT ( log -> V_154 >= 4096 ) ;
for ( V_167 = 0 ; V_167 < log -> V_151 ; V_167 ++ ) {
* V_165 = F_94 ( sizeof( T_12 ) , V_70 ) ;
if ( ! * V_165 )
goto V_183;
V_42 = * V_165 ;
V_42 -> V_184 = V_166 ;
V_166 = V_42 ;
V_140 = F_103 ( V_39 -> V_178 ,
log -> V_154 , 0 ) ;
if ( ! V_140 )
goto V_183;
V_140 -> V_179 = F_85 ;
V_42 -> V_185 = V_140 ;
V_42 -> V_186 = V_140 -> V_187 ;
#ifdef F_63
log -> V_188 [ V_167 ] = ( V_189 ) & ( V_42 -> V_190 ) ;
#endif
V_1 = & V_42 -> V_190 ;
memset ( V_1 , 0 , sizeof( T_16 ) ) ;
V_1 -> V_191 = F_104 ( V_192 ) ;
V_1 -> V_193 = F_104 (
F_93 ( & log -> V_139 -> V_156 ) ? 2 : 1 ) ;
V_1 -> V_194 = F_104 ( log -> V_154 ) ;
V_1 -> V_195 = F_104 ( V_196 ) ;
memcpy ( & V_1 -> V_197 , & V_39 -> V_156 . V_198 , sizeof( V_199 ) ) ;
V_42 -> V_200 = F_102 ( V_140 ) - log -> V_158 ;
V_42 -> V_51 = V_53 ;
V_42 -> V_143 = log ;
F_105 ( & V_42 -> V_111 , 0 ) ;
F_97 ( & V_42 -> V_50 ) ;
V_42 -> V_56 = & ( V_42 -> V_201 ) ;
V_42 -> V_202 = ( char * ) V_42 -> V_186 + log -> V_158 ;
ASSERT ( F_100 ( V_42 -> V_185 ) ) ;
F_101 ( & V_42 -> V_113 ) ;
F_101 ( & V_42 -> V_203 ) ;
V_165 = & V_42 -> V_92 ;
}
* V_165 = log -> V_90 ;
log -> V_90 -> V_184 = V_166 ;
error = F_106 ( log ) ;
if ( error )
goto V_183;
return log ;
V_183:
for ( V_42 = log -> V_90 ; V_42 ; V_42 = V_166 ) {
V_166 = V_42 -> V_92 ;
if ( V_42 -> V_185 )
F_107 ( V_42 -> V_185 ) ;
F_108 ( V_42 ) ;
}
F_109 ( & log -> V_110 ) ;
F_107 ( log -> V_180 ) ;
V_81:
F_108 ( log ) ;
V_80:
return F_110 ( - error ) ;
}
STATIC int
F_31 (
struct log * log ,
struct V_11 * V_40 ,
struct V_41 * * V_42 ,
T_5 * V_204 )
{
struct V_38 * V_39 = log -> V_139 ;
int error ;
struct V_98 V_99 = {
. V_100 = NULL ,
. V_101 = 0 ,
. V_102 = V_205 ,
} ;
struct V_104 V_105 = {
. V_106 = 1 ,
. V_107 = & V_99 ,
} ;
F_38 ( V_42 ) ;
error = F_65 ( log , & V_105 , V_40 , V_204 , V_42 ,
V_206 ) ;
if ( error )
F_42 ( V_39 , V_57 ) ;
return error ;
}
STATIC void
F_16 (
struct log * log ,
int V_13 )
{
T_5 V_207 = 0 ;
T_5 V_208 ;
int V_209 ;
int V_10 ;
int V_210 ;
int V_211 ;
int V_212 ;
ASSERT ( F_111 ( V_13 ) < log -> V_171 ) ;
V_10 = F_22 ( log , & log -> V_24 ) ;
V_209 = F_112 ( V_10 ) ;
V_212 = F_111 ( V_13 ) ;
V_212 = F_113 ( V_212 , ( log -> V_171 >> 2 ) ) ;
V_212 = F_113 ( V_212 , 256 ) ;
if ( V_209 >= V_212 )
return;
F_83 ( & log -> V_127 , & V_211 ,
& V_210 ) ;
V_210 += V_212 ;
if ( V_210 >= log -> V_171 ) {
V_210 -= log -> V_171 ;
V_211 += 1 ;
}
V_207 = F_114 ( V_211 ,
V_210 ) ;
V_208 = F_2 ( & log -> V_126 ) ;
if ( F_115 ( V_207 , V_208 ) > 0 )
V_207 = V_208 ;
if ( ! F_15 ( log ) )
F_116 ( log -> V_82 , V_207 ) ;
}
STATIC int
F_117 (
struct V_213 * V_140 )
{
struct V_41 * V_42 = V_140 -> V_141 ;
if ( V_42 -> V_51 & V_52 ) {
F_118 ( V_140 , V_25 ) ;
F_89 ( V_140 ) ;
F_119 ( V_140 , 0 ) ;
return 0 ;
}
F_120 ( V_140 ) ;
return 0 ;
}
STATIC int
F_121 ( T_11 * log ,
T_12 * V_42 )
{
V_189 V_214 ;
T_15 * V_140 ;
int V_167 ;
T_4 V_215 ;
T_4 V_216 ;
int V_217 ;
int V_218 = 0 ;
int error ;
int V_219 = F_93 ( & log -> V_139 -> V_156 ) ;
F_17 ( V_220 ) ;
ASSERT ( F_122 ( & V_42 -> V_111 ) == 0 ) ;
V_216 = log -> V_158 + V_42 -> V_91 ;
if ( V_219 && log -> V_139 -> V_156 . V_221 > 1 ) {
V_215 = F_123 ( log , F_124 ( log , V_216 ) ) ;
} else {
V_215 = F_84 ( F_111 ( V_216 ) ) ;
}
V_217 = V_215 - V_216 ;
ASSERT ( V_217 >= 0 ) ;
ASSERT ( ( V_219 && log -> V_139 -> V_156 . V_221 > 1 &&
V_217 < log -> V_139 -> V_156 . V_221 )
||
( log -> V_139 -> V_156 . V_221 <= 1 &&
V_217 < F_84 ( 1 ) ) ) ;
F_6 ( log , & log -> V_24 , V_217 ) ;
F_6 ( log , & log -> V_28 , V_217 ) ;
F_125 ( log , V_42 , V_217 ) ;
if ( V_219 ) {
V_42 -> V_190 . V_222 =
F_104 ( V_42 -> V_91 + V_217 ) ;
} else {
V_42 -> V_190 . V_222 =
F_104 ( V_42 -> V_91 ) ;
}
V_140 = V_42 -> V_185 ;
F_126 ( V_140 , F_127 ( F_128 ( V_42 -> V_190 . V_223 ) ) ) ;
F_129 ( V_224 , F_111 ( V_215 ) ) ;
if ( F_130 ( V_140 ) + F_111 ( V_215 ) > log -> V_171 ) {
V_218 = V_215 - ( F_84 ( log -> V_171 - F_130 ( V_140 ) ) ) ;
V_215 = F_84 ( log -> V_171 - F_130 ( V_140 ) ) ;
V_42 -> V_225 = 2 ;
} else {
V_42 -> V_225 = 1 ;
}
F_131 ( V_140 , V_215 ) ;
V_140 -> V_141 = V_42 ;
F_132 ( V_140 ) ;
F_133 ( V_140 ) ;
V_140 -> V_226 |= V_227 ;
if ( log -> V_139 -> V_77 & V_228 ) {
V_140 -> V_226 |= V_229 ;
if ( log -> V_139 -> V_178 != log -> V_139 -> V_230 )
F_134 ( log -> V_139 -> V_230 ) ;
else
V_140 -> V_226 |= V_231 ;
}
ASSERT ( F_130 ( V_140 ) <= log -> V_171 - 1 ) ;
ASSERT ( F_130 ( V_140 ) + F_111 ( V_215 ) <= log -> V_171 ) ;
F_135 ( log , V_42 , V_215 , V_232 ) ;
F_126 ( V_140 , F_130 ( V_140 ) + log -> V_170 ) ;
F_136 ( V_140 ) ;
error = F_117 ( V_140 ) ;
if ( error ) {
F_88 ( V_140 , L_14 ) ;
return error ;
}
if ( V_218 ) {
V_140 = V_42 -> V_143 -> V_180 ;
F_126 ( V_140 , 0 ) ;
F_137 ( V_140 ,
( char * ) & V_42 -> V_190 + V_215 , V_218 ) ;
V_140 -> V_141 = V_42 ;
F_132 ( V_140 ) ;
F_133 ( V_140 ) ;
V_140 -> V_226 |= V_227 ;
if ( log -> V_139 -> V_77 & V_228 )
V_140 -> V_226 |= V_229 ;
V_214 = V_140 -> V_187 ;
for ( V_167 = 0 ; V_167 < V_218 ; V_167 += V_162 ) {
F_138 ( ( V_233 * ) V_214 , 1 ) ;
if ( F_139 ( * ( V_233 * ) V_214 ) == V_192 )
F_138 ( ( V_233 * ) V_214 , 1 ) ;
V_214 += V_162 ;
}
ASSERT ( F_130 ( V_140 ) <= log -> V_171 - 1 ) ;
ASSERT ( F_130 ( V_140 ) + F_111 ( V_215 ) <= log -> V_171 ) ;
F_126 ( V_140 , F_130 ( V_140 ) + log -> V_170 ) ;
F_136 ( V_140 ) ;
error = F_117 ( V_140 ) ;
if ( error ) {
F_88 ( V_140 , L_15 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_59 ( T_11 * log )
{
T_12 * V_42 , * V_234 ;
int V_167 ;
F_140 ( log ) ;
F_141 ( log -> V_180 , log -> V_154 ) ;
F_107 ( log -> V_180 ) ;
V_42 = log -> V_90 ;
for ( V_167 = 0 ; V_167 < log -> V_151 ; V_167 ++ ) {
F_107 ( V_42 -> V_185 ) ;
V_234 = V_42 -> V_92 ;
F_108 ( V_42 ) ;
V_42 = V_234 ;
}
F_109 ( & log -> V_110 ) ;
log -> V_139 -> V_44 = NULL ;
F_108 ( log ) ;
}
static inline void
F_142 ( T_11 * log ,
T_12 * V_42 ,
int V_235 ,
int V_236 )
{
F_21 ( & log -> V_110 ) ;
F_138 ( & V_42 -> V_190 . V_237 , V_235 ) ;
V_42 -> V_91 += V_236 ;
F_39 ( & log -> V_110 ) ;
}
void
F_143 (
struct V_38 * V_39 ,
struct V_11 * V_40 )
{
T_4 V_167 ;
T_4 V_238 = V_40 -> V_31 * ( T_4 ) sizeof( V_239 ) ;
static char * V_240 [ V_241 ] = {
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
L_33 ,
L_34
} ;
static char * V_242 [ V_243 ] = {
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
L_73 ,
L_74
} ;
F_55 ( V_39 ,
L_75
L_76
L_77
L_78
L_79
L_80
L_81
L_82 ,
( ( V_40 -> V_72 <= 0 ||
V_40 -> V_72 > V_243 ) ?
L_83 : V_242 [ V_40 -> V_72 - 1 ] ) ,
V_40 -> V_72 ,
V_40 -> V_16 ,
V_40 -> V_73 ,
V_40 -> V_30 , V_40 -> V_34 ,
V_40 -> V_31 , V_238 ,
V_40 -> V_30 +
V_40 -> V_34 + V_238 ,
V_40 -> V_29 ) ;
for ( V_167 = 0 ; V_167 < V_40 -> V_29 ; V_167 ++ ) {
T_4 V_37 = V_40 -> V_35 [ V_167 ] . V_37 ;
F_55 ( V_39 , L_84 , V_167 ,
( ( V_37 <= 0 || V_37 > V_241 ) ?
L_85 : V_240 [ V_37 - 1 ] ) ,
V_40 -> V_35 [ V_167 ] . V_36 ) ;
}
F_144 ( V_39 , V_244 ,
L_86 ) ;
F_42 ( V_39 , V_245 ) ;
}
static int
F_145 (
struct V_11 * V_40 ,
struct V_104 * V_246 )
{
struct V_104 * V_247 ;
int V_248 = 0 ;
int V_32 = 0 ;
int V_167 ;
if ( V_40 -> V_14 & V_46 )
V_248 ++ ;
for ( V_247 = V_246 ; V_247 ; V_247 = V_247 -> V_249 ) {
V_248 += V_247 -> V_106 ;
for ( V_167 = 0 ; V_167 < V_247 -> V_106 ; V_167 ++ ) {
struct V_98 * V_250 = & V_247 -> V_107 [ V_167 ] ;
V_32 += V_250 -> V_101 ;
F_29 ( V_40 , V_250 -> V_101 , V_250 -> V_102 ) ;
}
}
V_40 -> V_31 += V_248 ;
V_32 += V_248 * sizeof( struct V_251 ) ;
return V_32 ;
}
static int
F_146 (
struct V_251 * V_252 ,
struct V_11 * V_40 )
{
if ( ! ( V_40 -> V_14 & V_46 ) )
return 0 ;
V_252 -> V_253 = F_104 ( V_40 -> V_68 ) ;
V_252 -> V_254 = V_40 -> V_255 ;
V_252 -> V_256 = 0 ;
V_252 -> V_257 = V_258 ;
V_252 -> V_259 = 0 ;
V_40 -> V_14 &= ~ V_46 ;
return sizeof( struct V_251 ) ;
}
static V_239 *
F_147 (
struct log * log ,
struct V_251 * V_252 ,
struct V_11 * V_40 ,
T_4 V_43 )
{
V_252 -> V_253 = F_104 ( V_40 -> V_68 ) ;
V_252 -> V_254 = V_40 -> V_255 ;
V_252 -> V_259 = 0 ;
V_252 -> V_257 = V_43 ;
switch ( V_252 -> V_254 ) {
case V_64 :
case V_260 :
case V_65 :
break;
default:
F_55 ( log -> V_139 ,
L_87 ,
V_252 -> V_254 , V_40 ) ;
return NULL ;
}
return V_252 ;
}
static int
F_148 (
struct V_11 * V_40 ,
struct V_251 * V_252 ,
int V_261 ,
int V_262 ,
int * V_263 ,
int * V_264 ,
int * V_265 ,
int * V_266 )
{
int V_267 ;
V_267 = V_262 - * V_266 ;
* V_263 = * V_266 ;
if ( V_267 <= V_261 ) {
* V_264 = V_267 ;
V_252 -> V_256 = F_104 ( * V_264 ) ;
if ( * V_265 )
V_252 -> V_257 |= ( V_268 | V_269 ) ;
* V_265 = 0 ;
* V_266 = 0 ;
return 0 ;
}
* V_264 = V_261 ;
V_252 -> V_256 = F_104 ( * V_264 ) ;
V_252 -> V_257 |= V_270 ;
if ( * V_265 )
V_252 -> V_257 |= V_269 ;
* V_266 += * V_264 ;
( * V_265 ) ++ ;
V_40 -> V_73 -= sizeof( struct V_251 ) ;
V_40 -> V_31 ++ ;
return sizeof( struct V_251 ) ;
}
static int
F_149 (
struct log * log ,
struct V_41 * V_42 ,
T_4 V_43 ,
int * V_235 ,
int * V_271 ,
int * V_272 ,
int * V_273 ,
int V_274 ,
struct V_41 * * V_275 )
{
if ( * V_272 ) {
F_142 ( log , V_42 , * V_235 , * V_271 ) ;
* V_235 = 0 ;
* V_271 = 0 ;
return F_41 ( log , V_42 ) ;
}
* V_272 = 0 ;
* V_273 = 0 ;
if ( V_42 -> V_200 - V_274 <= sizeof( V_239 ) ) {
F_142 ( log , V_42 , * V_235 , * V_271 ) ;
* V_235 = 0 ;
* V_271 = 0 ;
F_21 ( & log -> V_110 ) ;
F_68 ( log , V_42 ) ;
F_39 ( & log -> V_110 ) ;
if ( ! V_275 )
return F_41 ( log , V_42 ) ;
ASSERT ( V_43 & V_206 ) ;
* V_275 = V_42 ;
}
return 0 ;
}
int
F_65 (
struct log * log ,
struct V_104 * V_246 ,
struct V_11 * V_40 ,
T_5 * V_276 ,
struct V_41 * * V_275 ,
T_4 V_43 )
{
struct V_41 * V_42 = NULL ;
struct V_98 * V_250 ;
struct V_104 * V_247 ;
int V_32 ;
int V_277 ;
int V_272 = 0 ;
int V_273 = 0 ;
int V_278 = 0 ;
int V_235 = 0 ;
int V_271 = 0 ;
int error ;
* V_276 = 0 ;
V_32 = F_145 ( V_40 , V_246 ) ;
if ( V_40 -> V_14 & V_46 )
V_40 -> V_73 -= sizeof( V_239 ) ;
if ( V_43 & ( V_206 | V_108 ) )
V_40 -> V_73 -= sizeof( V_239 ) ;
if ( V_40 -> V_73 < 0 )
F_143 ( log -> V_139 , V_40 ) ;
V_277 = 0 ;
V_247 = V_246 ;
V_250 = V_247 -> V_107 ;
while ( V_247 && V_277 < V_247 -> V_106 ) {
void * V_279 ;
int V_274 ;
error = F_150 ( log , V_32 , & V_42 , V_40 ,
& V_278 , & V_274 ) ;
if ( error )
return error ;
ASSERT ( V_274 <= V_42 -> V_200 - 1 ) ;
V_279 = V_42 -> V_202 + V_274 ;
if ( ! * V_276 )
* V_276 = F_128 ( V_42 -> V_190 . V_223 ) ;
while ( V_247 && V_277 < V_247 -> V_106 ) {
struct V_98 * V_99 = & V_250 [ V_277 ] ;
struct V_251 * V_252 ;
int V_280 ;
int V_264 ;
int V_263 ;
ASSERT ( V_99 -> V_101 % sizeof( V_281 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_279 % sizeof( V_281 ) == 0 ) ;
V_280 = F_146 ( V_279 , V_40 ) ;
if ( V_280 ) {
V_235 ++ ;
F_151 ( & V_279 , & V_32 , & V_274 ,
V_280 ) ;
}
V_252 = F_147 ( log , V_279 , V_40 , V_43 ) ;
if ( ! V_252 )
return F_24 ( V_25 ) ;
F_151 ( & V_279 , & V_32 , & V_274 ,
sizeof( struct V_251 ) ) ;
V_32 += F_148 ( V_40 , V_252 ,
V_42 -> V_200 - V_274 ,
V_99 -> V_101 ,
& V_263 , & V_264 ,
& V_272 ,
& V_273 ) ;
F_152 ( log , V_279 ) ;
ASSERT ( V_264 >= 0 ) ;
memcpy ( V_279 , V_99 -> V_100 + V_263 , V_264 ) ;
F_151 ( & V_279 , & V_32 , & V_274 , V_264 ) ;
V_264 += V_280 + sizeof( V_239 ) ;
V_235 ++ ;
V_271 += V_278 ? V_264 : 0 ;
error = F_149 ( log , V_42 , V_43 ,
& V_235 , & V_271 ,
& V_272 ,
& V_273 ,
V_274 ,
V_275 ) ;
if ( error )
return error ;
if ( V_272 )
break;
if ( ++ V_277 == V_247 -> V_106 ) {
V_247 = V_247 -> V_249 ;
V_277 = 0 ;
if ( V_247 )
V_250 = V_247 -> V_107 ;
}
if ( V_235 == 0 ) {
if ( ! V_247 )
return 0 ;
break;
}
}
}
ASSERT ( V_32 == 0 ) ;
F_142 ( log , V_42 , V_235 , V_271 ) ;
if ( ! V_275 )
return F_41 ( log , V_42 ) ;
ASSERT ( V_43 & V_206 ) ;
* V_275 = V_42 ;
return 0 ;
}
STATIC void
F_153 ( T_11 * log )
{
T_12 * V_42 ;
int V_282 = 0 ;
V_42 = log -> V_90 ;
do {
if ( V_42 -> V_51 == V_112 ) {
V_42 -> V_51 = V_53 ;
V_42 -> V_91 = 0 ;
ASSERT ( V_42 -> V_201 == NULL ) ;
if ( ! V_282 &&
( F_139 ( V_42 -> V_190 . V_237 ) ==
V_283 ) ) {
V_282 = 1 ;
} else {
V_282 = 2 ;
}
V_42 -> V_190 . V_237 = 0 ;
memset ( V_42 -> V_190 . V_284 , 0 ,
sizeof( V_42 -> V_190 . V_284 ) ) ;
V_42 -> V_190 . V_223 = 0 ;
} else if ( V_42 -> V_51 == V_53 )
;
else
break;
V_42 = V_42 -> V_92 ;
} while ( V_42 != log -> V_90 );
if ( V_282 ) {
switch ( log -> V_129 ) {
case V_132 :
case V_133 :
case V_134 :
log -> V_129 = V_133 ;
break;
case V_130 :
if ( V_282 == 1 )
log -> V_129 = V_134 ;
else
log -> V_129 = V_133 ;
break;
case V_131 :
if ( V_282 == 1 )
log -> V_129 = V_132 ;
else
log -> V_129 = V_133 ;
break;
default:
ASSERT ( 0 ) ;
}
}
}
STATIC T_5
F_154 (
T_11 * log )
{
T_12 * V_285 ;
T_5 V_286 , V_45 ;
V_285 = log -> V_90 ;
V_286 = 0 ;
do {
if ( ! ( V_285 -> V_51 & ( V_53 | V_112 ) ) ) {
V_45 = F_128 ( V_285 -> V_190 . V_223 ) ;
if ( ( V_45 && ! V_286 ) ||
( F_115 ( V_45 , V_286 ) < 0 ) ) {
V_286 = V_45 ;
}
}
V_285 = V_285 -> V_92 ;
} while ( V_285 != log -> V_90 );
return V_286 ;
}
STATIC void
F_155 (
T_11 * log ,
int V_144 ,
T_12 * V_287 )
{
T_12 * V_42 ;
T_12 * V_88 ;
T_6 * V_48 , * V_55 ;
int V_288 = 0 ;
T_5 V_286 ;
int V_289 ;
int V_290 ;
int V_291 ;
int V_292 ;
int V_293 = 0 ;
F_21 ( & log -> V_110 ) ;
V_88 = V_42 = log -> V_90 ;
V_289 = 0 ;
V_291 = 0 ;
V_292 = 0 ;
do {
V_88 = log -> V_90 ;
V_42 = log -> V_90 ;
V_290 = 0 ;
V_292 ++ ;
do {
if ( V_42 -> V_51 &
( V_53 | V_112 ) ) {
V_42 = V_42 -> V_92 ;
continue;
}
if ( ! ( V_42 -> V_51 & V_52 ) ) {
if ( ! ( V_42 -> V_51 &
( V_294 |
V_295 ) ) ) {
if ( V_287 && ( V_287 -> V_51 ==
V_294 ) ) {
V_287 -> V_51 = V_295 ;
}
break;
}
V_286 = F_154 ( log ) ;
if ( V_286 &&
F_115 ( V_286 ,
F_128 ( V_42 -> V_190 . V_223 ) ) < 0 ) {
V_42 = V_42 -> V_92 ;
continue;
}
V_42 -> V_51 = V_296 ;
ASSERT ( F_115 ( F_2 ( & log -> V_126 ) ,
F_128 ( V_42 -> V_190 . V_223 ) ) <= 0 ) ;
F_74 ( & log -> V_126 ,
F_128 ( V_42 -> V_190 . V_223 ) ) ;
} else
V_289 ++ ;
F_39 ( & log -> V_110 ) ;
F_21 ( & V_42 -> V_50 ) ;
V_48 = V_42 -> V_201 ;
while ( V_48 ) {
V_42 -> V_56 = & ( V_42 -> V_201 ) ;
V_42 -> V_201 = NULL ;
F_39 ( & V_42 -> V_50 ) ;
for (; V_48 ; V_48 = V_55 ) {
V_55 = V_48 -> V_55 ;
V_48 -> V_297 ( V_48 -> V_298 , V_144 ) ;
}
F_21 ( & V_42 -> V_50 ) ;
V_48 = V_42 -> V_201 ;
}
V_290 ++ ;
V_291 ++ ;
F_21 ( & log -> V_110 ) ;
ASSERT ( V_42 -> V_201 == NULL ) ;
F_39 ( & V_42 -> V_50 ) ;
if ( ! ( V_42 -> V_51 & V_52 ) )
V_42 -> V_51 = V_112 ;
F_153 ( log ) ;
F_156 ( & V_42 -> V_113 ) ;
V_42 = V_42 -> V_92 ;
} while ( V_88 != V_42 );
if ( V_292 > 5000 ) {
V_288 += V_292 ;
V_292 = 0 ;
F_55 ( log -> V_139 ,
L_88 ,
V_109 , V_288 ) ;
}
} while ( ! V_289 && V_290 );
#ifdef F_63
if ( V_291 ) {
V_88 = V_42 = log -> V_90 ;
do {
ASSERT ( V_42 -> V_51 != V_295 ) ;
if ( V_42 -> V_51 == V_54 ||
V_42 -> V_51 == V_299 ||
V_42 -> V_51 == V_294 ||
V_42 -> V_51 == V_52 )
break;
V_42 = V_42 -> V_92 ;
} while ( V_88 != V_42 );
}
#endif
if ( log -> V_90 -> V_51 & ( V_53 | V_52 ) )
V_293 = 1 ;
F_39 ( & log -> V_110 ) ;
if ( V_293 )
F_156 ( & log -> V_181 ) ;
}
STATIC void
F_91 (
T_12 * V_42 ,
int V_144 )
{
T_11 * log = V_42 -> V_143 ;
F_21 ( & log -> V_110 ) ;
ASSERT ( V_42 -> V_51 == V_299 ||
V_42 -> V_51 == V_52 ) ;
ASSERT ( F_122 ( & V_42 -> V_111 ) == 0 ) ;
ASSERT ( V_42 -> V_225 == 1 || V_42 -> V_225 == 2 ) ;
if ( V_42 -> V_51 != V_52 ) {
if ( -- V_42 -> V_225 == 1 ) {
F_39 ( & log -> V_110 ) ;
return;
}
V_42 -> V_51 = V_294 ;
}
F_156 ( & V_42 -> V_203 ) ;
F_39 ( & log -> V_110 ) ;
F_155 ( log , V_144 , V_42 ) ;
}
STATIC int
F_150 ( T_11 * log ,
int V_32 ,
T_12 * * V_165 ,
T_3 * V_40 ,
int * V_300 ,
int * V_301 )
{
int V_274 ;
T_16 * V_1 ;
T_12 * V_42 ;
int error ;
V_302:
F_21 ( & log -> V_110 ) ;
if ( F_15 ( log ) ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
V_42 = log -> V_90 ;
if ( V_42 -> V_51 != V_53 ) {
F_17 ( V_303 ) ;
F_19 ( & log -> V_181 , & log -> V_110 ) ;
goto V_302;
}
V_1 = & V_42 -> V_190 ;
F_67 ( & V_42 -> V_111 ) ;
V_274 = V_42 -> V_91 ;
if ( V_274 == 0 ) {
V_40 -> V_73 -= log -> V_158 ;
F_29 ( V_40 ,
log -> V_158 ,
V_304 ) ;
V_1 -> V_305 = F_104 ( log -> V_173 ) ;
V_1 -> V_223 = F_157 (
F_114 ( log -> V_173 , log -> V_306 ) ) ;
ASSERT ( log -> V_306 >= 0 ) ;
}
if ( V_42 -> V_200 - V_42 -> V_91 < 2 * sizeof( V_239 ) ) {
F_158 ( log , V_42 , V_42 -> V_200 ) ;
if ( ! F_159 ( & V_42 -> V_111 , - 1 , 1 ) ) {
F_39 ( & log -> V_110 ) ;
error = F_41 ( log , V_42 ) ;
if ( error )
return error ;
} else {
F_39 ( & log -> V_110 ) ;
}
goto V_302;
}
if ( V_32 <= V_42 -> V_200 - V_42 -> V_91 ) {
* V_300 = 0 ;
V_42 -> V_91 += V_32 ;
} else {
* V_300 = 1 ;
F_158 ( log , V_42 , V_42 -> V_200 ) ;
}
* V_165 = V_42 ;
ASSERT ( V_42 -> V_91 <= V_42 -> V_200 ) ;
F_39 ( & log -> V_110 ) ;
* V_301 = V_274 ;
return 0 ;
}
STATIC int
F_47 (
struct log * log ,
struct V_11 * V_12 )
{
int V_10 , V_13 ;
int error = 0 ;
ASSERT ( ! ( log -> V_86 & V_87 ) ) ;
F_160 ( log , V_12 ) ;
V_13 = V_12 -> V_16 ;
if ( V_12 -> V_14 & V_67 )
V_13 *= V_12 -> V_307 ;
V_10 = F_22 ( log , & log -> V_24 ) ;
if ( ! F_75 ( & log -> V_20 ) ) {
F_21 ( & log -> V_23 ) ;
if ( ! F_7 ( log , & V_10 ) ||
V_10 < V_13 )
error = F_13 ( log , V_12 , V_13 ) ;
F_39 ( & log -> V_23 ) ;
} else if ( V_10 < V_13 ) {
F_21 ( & log -> V_23 ) ;
error = F_13 ( log , V_12 , V_13 ) ;
F_39 ( & log -> V_23 ) ;
}
if ( error )
return error ;
F_6 ( log , & log -> V_24 , V_13 ) ;
F_6 ( log , & log -> V_28 , V_13 ) ;
F_161 ( log , V_12 ) ;
F_162 ( log ) ;
return 0 ;
}
STATIC int
F_45 (
struct log * log ,
struct V_11 * V_12 )
{
int V_10 , V_13 ;
int error = 0 ;
V_12 -> V_73 = V_12 -> V_16 ;
F_28 ( V_12 ) ;
if ( V_12 -> V_17 > 0 )
return 0 ;
ASSERT ( ! ( log -> V_86 & V_87 ) ) ;
F_163 ( log , V_12 ) ;
V_13 = V_12 -> V_16 ;
V_10 = F_22 ( log , & log -> V_28 ) ;
if ( ! F_75 ( & log -> V_26 ) ) {
F_21 ( & log -> V_27 ) ;
if ( ! F_11 ( log , & V_10 ) ||
V_10 < V_13 )
error = F_25 ( log , V_12 , V_13 ) ;
F_39 ( & log -> V_27 ) ;
} else if ( V_10 < V_13 ) {
F_21 ( & log -> V_27 ) ;
error = F_25 ( log , V_12 , V_13 ) ;
F_39 ( & log -> V_27 ) ;
}
if ( error )
return error ;
F_6 ( log , & log -> V_28 , V_13 ) ;
F_164 ( log , V_12 ) ;
F_162 ( log ) ;
return 0 ;
}
STATIC void
F_36 ( T_11 * log ,
T_3 * V_40 )
{
F_165 ( log , V_40 ) ;
if ( V_40 -> V_17 > 0 )
V_40 -> V_17 -- ;
F_1 ( log , & log -> V_24 ,
V_40 -> V_73 ) ;
F_1 ( log , & log -> V_28 ,
V_40 -> V_73 ) ;
V_40 -> V_73 = V_40 -> V_16 ;
F_28 ( V_40 ) ;
F_166 ( log , V_40 ) ;
if ( V_40 -> V_17 > 0 )
return;
F_6 ( log , & log -> V_24 ,
V_40 -> V_16 ) ;
F_167 ( log , V_40 ) ;
V_40 -> V_73 = V_40 -> V_16 ;
F_28 ( V_40 ) ;
}
STATIC void
F_33 ( T_11 * log ,
T_3 * V_40 )
{
int V_2 ;
if ( V_40 -> V_17 > 0 )
V_40 -> V_17 -- ;
F_168 ( log , V_40 ) ;
F_169 ( log , V_40 ) ;
V_2 = V_40 -> V_73 ;
if ( V_40 -> V_17 > 0 ) {
ASSERT ( V_40 -> V_14 & V_15 ) ;
V_2 += V_40 -> V_16 * V_40 -> V_17 ;
}
F_1 ( log , & log -> V_24 , V_2 ) ;
F_1 ( log , & log -> V_28 , V_2 ) ;
F_170 ( log , V_40 ) ;
F_73 ( log -> V_139 , 1 ) ;
}
STATIC int
F_41 (
T_11 * log ,
T_12 * V_42 )
{
int V_308 = 0 ;
if ( V_42 -> V_51 & V_52 )
return F_24 ( V_25 ) ;
ASSERT ( F_122 ( & V_42 -> V_111 ) > 0 ) ;
if ( ! F_171 ( & V_42 -> V_111 , & log -> V_110 ) )
return 0 ;
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
ASSERT ( V_42 -> V_51 == V_53 ||
V_42 -> V_51 == V_54 ) ;
if ( V_42 -> V_51 == V_54 ) {
T_5 V_125 = F_81 ( log -> V_139 ) ;
V_308 ++ ;
V_42 -> V_51 = V_299 ;
V_42 -> V_190 . V_309 = F_157 ( V_125 ) ;
F_172 ( log , V_42 , V_125 ) ;
}
F_39 ( & log -> V_110 ) ;
if ( V_308 )
return F_121 ( log , V_42 ) ;
return 0 ;
}
STATIC void
F_158 ( T_11 * log ,
T_12 * V_42 ,
int V_310 )
{
ASSERT ( V_42 -> V_51 == V_53 ) ;
if ( ! V_310 )
V_310 = V_42 -> V_91 ;
V_42 -> V_51 = V_54 ;
V_42 -> V_190 . V_311 = F_104 ( log -> V_172 ) ;
log -> V_172 = log -> V_306 ;
log -> V_312 = log -> V_173 ;
log -> V_306 += F_111 ( V_310 ) + F_111 ( log -> V_158 ) ;
if ( F_93 ( & log -> V_139 -> V_156 ) &&
log -> V_139 -> V_156 . V_221 > 1 ) {
T_14 V_313 = F_111 ( log -> V_139 -> V_156 . V_221 ) ;
log -> V_306 = F_173 ( log -> V_306 , V_313 ) ;
}
if ( log -> V_306 >= log -> V_171 ) {
log -> V_173 ++ ;
if ( log -> V_173 == V_192 )
log -> V_173 ++ ;
log -> V_306 -= log -> V_171 ;
ASSERT ( log -> V_306 >= 0 ) ;
}
ASSERT ( V_42 == log -> V_90 ) ;
log -> V_90 = V_42 -> V_92 ;
}
int
F_64 (
struct V_38 * V_39 ,
T_4 V_43 ,
int * V_314 )
{
struct log * log = V_39 -> V_44 ;
struct V_41 * V_42 ;
T_5 V_45 ;
F_17 ( V_315 ) ;
F_174 ( log ) ;
F_21 ( & log -> V_110 ) ;
V_42 = log -> V_90 ;
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
if ( V_42 -> V_51 == V_53 ||
V_42 -> V_51 == V_112 ) {
if ( V_42 -> V_51 == V_112 ||
( F_122 ( & V_42 -> V_111 ) == 0
&& V_42 -> V_91 == 0 ) ) {
V_42 = V_42 -> V_184 ;
if ( V_42 -> V_51 == V_53 ||
V_42 -> V_51 == V_112 )
goto V_316;
else
goto V_317;
} else {
if ( F_122 ( & V_42 -> V_111 ) == 0 ) {
F_67 ( & V_42 -> V_111 ) ;
V_45 = F_128 ( V_42 -> V_190 . V_223 ) ;
F_158 ( log , V_42 , 0 ) ;
F_39 ( & log -> V_110 ) ;
if ( F_41 ( log , V_42 ) )
return F_24 ( V_25 ) ;
if ( V_314 )
* V_314 = 1 ;
F_21 ( & log -> V_110 ) ;
if ( F_128 ( V_42 -> V_190 . V_223 ) == V_45 &&
V_42 -> V_51 != V_112 )
goto V_317;
else
goto V_316;
} else {
F_158 ( log , V_42 , 0 ) ;
goto V_317;
}
}
}
V_317:
if ( V_43 & V_89 ) {
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
F_17 ( V_318 ) ;
F_19 ( & V_42 -> V_113 , & log -> V_110 ) ;
if ( V_42 -> V_51 & V_52 )
return F_24 ( V_25 ) ;
if ( V_314 )
* V_314 = 1 ;
} else {
V_316:
F_39 ( & log -> V_110 ) ;
}
return 0 ;
}
void
F_175 (
T_8 * V_39 ,
T_4 V_43 )
{
int error ;
error = F_64 ( V_39 , V_43 , NULL ) ;
if ( error )
F_55 ( V_39 , L_89 , V_109 , error ) ;
}
int
F_176 (
struct V_38 * V_39 ,
T_5 V_45 ,
T_4 V_43 ,
int * V_314 )
{
struct log * log = V_39 -> V_44 ;
struct V_41 * V_42 ;
int V_319 = 0 ;
ASSERT ( V_45 != 0 ) ;
F_17 ( V_315 ) ;
V_45 = F_177 ( log , V_45 ) ;
if ( V_45 == V_320 )
return 0 ;
V_321:
F_21 ( & log -> V_110 ) ;
V_42 = log -> V_90 ;
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
do {
if ( F_128 ( V_42 -> V_190 . V_223 ) != V_45 ) {
V_42 = V_42 -> V_92 ;
continue;
}
if ( V_42 -> V_51 == V_112 ) {
F_39 ( & log -> V_110 ) ;
return 0 ;
}
if ( V_42 -> V_51 == V_53 ) {
if ( ! V_319 &&
( V_42 -> V_184 -> V_51 &
( V_54 | V_299 ) ) ) {
ASSERT ( ! ( V_42 -> V_51 & V_52 ) ) ;
F_17 ( V_318 ) ;
F_19 ( & V_42 -> V_184 -> V_203 ,
& log -> V_110 ) ;
if ( V_314 )
* V_314 = 1 ;
V_319 = 1 ;
goto V_321;
}
F_67 ( & V_42 -> V_111 ) ;
F_158 ( log , V_42 , 0 ) ;
F_39 ( & log -> V_110 ) ;
if ( F_41 ( log , V_42 ) )
return F_24 ( V_25 ) ;
if ( V_314 )
* V_314 = 1 ;
F_21 ( & log -> V_110 ) ;
}
if ( ( V_43 & V_89 ) &&
! ( V_42 -> V_51 &
( V_53 | V_112 ) ) ) {
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
F_17 ( V_318 ) ;
F_19 ( & V_42 -> V_113 , & log -> V_110 ) ;
if ( V_42 -> V_51 & V_52 )
return F_24 ( V_25 ) ;
if ( V_314 )
* V_314 = 1 ;
} else {
F_39 ( & log -> V_110 ) ;
}
return 0 ;
} while ( V_42 != log -> V_90 );
F_39 ( & log -> V_110 ) ;
return 0 ;
}
void
F_178 (
T_8 * V_39 ,
T_5 V_45 ,
T_4 V_43 )
{
int error ;
error = F_176 ( V_39 , V_45 , V_43 , NULL ) ;
if ( error )
F_55 ( V_39 , L_89 , V_109 , error ) ;
}
STATIC void
F_68 ( T_11 * log , T_12 * V_42 )
{
F_179 ( & log -> V_110 ) ;
if ( V_42 -> V_51 == V_53 ) {
F_158 ( log , V_42 , 0 ) ;
} else {
ASSERT ( V_42 -> V_51 &
( V_54 | V_52 ) ) ;
}
}
void
F_34 (
T_3 * V_40 )
{
ASSERT ( F_122 ( & V_40 -> V_322 ) > 0 ) ;
if ( F_180 ( & V_40 -> V_322 ) )
F_181 ( V_323 , V_40 ) ;
}
T_3 *
F_182 (
T_3 * V_40 )
{
ASSERT ( F_122 ( & V_40 -> V_322 ) > 0 ) ;
F_67 ( & V_40 -> V_322 ) ;
return V_40 ;
}
T_3 *
F_46 (
struct log * log ,
int V_58 ,
int V_59 ,
char V_60 ,
T_4 V_324 ,
int V_325 )
{
struct V_11 * V_12 ;
T_4 V_326 ;
int V_327 ;
V_12 = F_183 ( V_323 , V_325 ) ;
if ( ! V_12 )
return NULL ;
V_58 += sizeof( V_239 ) ;
V_58 += sizeof( V_328 ) ;
V_58 += sizeof( V_239 ) ;
V_327 = log -> V_154 - log -> V_158 ;
V_326 = F_184 ( V_58 , V_327 ) ;
V_58 += sizeof( V_239 ) * V_326 ;
while ( ! V_326 ||
F_184 ( V_58 , V_327 ) > V_326 ) {
V_58 += sizeof( V_239 ) ;
V_326 ++ ;
}
V_58 += log -> V_158 * V_326 ;
V_58 += log -> V_158 ;
if ( F_93 ( & log -> V_139 -> V_156 ) &&
log -> V_139 -> V_156 . V_221 > 1 ) {
V_58 += 2 * log -> V_139 -> V_156 . V_221 ;
} else {
V_58 += 2 * V_162 ;
}
F_105 ( & V_12 -> V_322 , 1 ) ;
F_72 ( & V_12 -> V_19 ) ;
V_12 -> V_16 = V_58 ;
V_12 -> V_73 = V_58 ;
V_12 -> V_17 = V_59 ;
V_12 -> V_307 = V_59 ;
V_12 -> V_68 = F_185 () ;
V_12 -> V_255 = V_60 ;
V_12 -> V_14 = V_46 ;
V_12 -> V_72 = 0 ;
if ( V_324 & V_67 )
V_12 -> V_14 |= V_15 ;
F_101 ( & V_12 -> V_18 ) ;
F_28 ( V_12 ) ;
return V_12 ;
}
void
F_152 (
struct log * log ,
char * V_279 )
{
int V_167 ;
int V_329 = 0 ;
for ( V_167 = 0 ; V_167 < log -> V_151 ; V_167 ++ ) {
if ( V_279 >= log -> V_188 [ V_167 ] &&
V_279 <= log -> V_188 [ V_167 ] + log -> V_154 )
V_329 ++ ;
}
if ( ! V_329 )
F_186 ( log -> V_139 , L_90 , V_109 ) ;
}
STATIC void
F_162 (
struct log * log )
{
int V_136 , V_330 ;
int V_6 , V_7 ;
F_82 ( & log -> V_28 , & V_6 , & V_7 ) ;
F_83 ( & log -> V_127 , & V_136 , & V_330 ) ;
if ( V_136 != V_6 ) {
if ( V_6 - 1 != V_136 &&
! ( log -> V_86 & V_331 ) ) {
F_144 ( log -> V_139 , V_244 ,
L_91 , V_109 ) ;
log -> V_86 |= V_331 ;
}
if ( V_7 > F_84 ( V_330 ) &&
! ( log -> V_86 & V_331 ) ) {
F_144 ( log -> V_139 , V_244 ,
L_92 , V_109 ) ;
log -> V_86 |= V_331 ;
}
}
}
STATIC void
F_172 ( T_11 * log ,
T_12 * V_42 ,
T_5 V_125 )
{
int V_332 ;
if ( F_187 ( V_125 ) == log -> V_312 ) {
V_332 =
log -> V_171 - ( log -> V_172 - F_127 ( V_125 ) ) ;
if ( V_332 < F_111 ( V_42 -> V_91 ) + F_111 ( log -> V_158 ) )
F_186 ( log -> V_139 , L_93 , V_109 ) ;
} else {
ASSERT ( F_187 ( V_125 ) + 1 == log -> V_312 ) ;
if ( F_127 ( V_125 ) == log -> V_172 )
F_186 ( log -> V_139 , L_94 , V_109 ) ;
V_332 = F_127 ( V_125 ) - log -> V_172 ;
if ( V_332 < F_111 ( V_42 -> V_91 ) + 1 )
F_186 ( log -> V_139 , L_93 , V_109 ) ;
}
}
STATIC void
F_135 ( T_11 * log ,
T_12 * V_42 ,
int V_215 ,
T_17 V_333 )
{
V_239 * V_334 ;
T_12 * V_335 ;
T_18 * V_336 ;
V_189 V_279 ;
V_189 V_337 ;
T_19 V_338 ;
T_7 V_339 ;
int V_32 , V_167 , V_340 , V_341 , V_342 ;
int V_343 ;
F_21 ( & log -> V_110 ) ;
V_335 = log -> V_90 ;
for ( V_167 = 0 ; V_167 < log -> V_151 ; V_167 ++ ) {
if ( V_335 == NULL )
F_186 ( log -> V_139 , L_90 , V_109 ) ;
V_335 = V_335 -> V_92 ;
}
if ( V_335 != log -> V_90 )
F_186 ( log -> V_139 , L_95 , V_109 ) ;
F_39 ( & log -> V_110 ) ;
if ( V_42 -> V_190 . V_191 != F_104 ( V_192 ) )
F_186 ( log -> V_139 , L_96 , V_109 ) ;
V_279 = ( V_189 ) & V_42 -> V_190 ;
for ( V_279 += V_162 ; V_279 < ( ( V_189 ) & V_42 -> V_190 ) + V_215 ;
V_279 += V_162 ) {
if ( * ( V_233 * ) V_279 == F_104 ( V_192 ) )
F_186 ( log -> V_139 , L_97 ,
V_109 ) ;
}
V_32 = F_139 ( V_42 -> V_190 . V_237 ) ;
V_279 = V_42 -> V_202 ;
V_337 = V_279 ;
V_334 = ( V_239 * ) V_279 ;
V_336 = V_42 -> V_186 ;
for ( V_167 = 0 ; V_167 < V_32 ; V_167 ++ ) {
V_334 = ( V_239 * ) V_279 ;
V_338 = ( T_19 )
( ( V_189 ) & ( V_334 -> V_254 ) - V_337 ) ;
if ( V_333 == V_344 || ( V_338 & 0x1ff ) ) {
V_339 = V_334 -> V_254 ;
} else {
V_343 = F_112 ( ( V_189 ) & ( V_334 -> V_254 ) - V_42 -> V_202 ) ;
if ( V_343 >= ( V_157 / V_162 ) ) {
V_340 = V_343 / ( V_157 / V_162 ) ;
V_341 = V_343 % ( V_157 / V_162 ) ;
V_339 = F_188 (
V_336 [ V_340 ] . V_345 . V_346 [ V_341 ] ) ;
} else {
V_339 = F_188 (
V_42 -> V_190 . V_284 [ V_343 ] ) ;
}
}
if ( V_339 != V_64 && V_339 != V_65 )
F_55 ( log -> V_139 ,
L_98 ,
V_109 , V_339 , V_334 ,
( unsigned long ) V_338 ) ;
V_338 = ( T_19 )
( ( V_189 ) & ( V_334 -> V_256 ) - V_337 ) ;
if ( V_333 == V_344 || ( V_338 & 0x1ff ) ) {
V_342 = F_139 ( V_334 -> V_256 ) ;
} else {
V_343 = F_112 ( ( T_19 ) & V_334 -> V_256 -
( T_19 ) V_42 -> V_202 ) ;
if ( V_343 >= ( V_157 / V_162 ) ) {
V_340 = V_343 / ( V_157 / V_162 ) ;
V_341 = V_343 % ( V_157 / V_162 ) ;
V_342 = F_139 ( V_336 [ V_340 ] . V_345 . V_346 [ V_341 ] ) ;
} else {
V_342 = F_139 ( V_42 -> V_190 . V_284 [ V_343 ] ) ;
}
}
V_279 += sizeof( V_239 ) + V_342 ;
}
}
STATIC int
F_189 (
T_11 * log )
{
T_12 * V_42 , * V_347 ;
V_42 = log -> V_90 ;
if ( ! ( V_42 -> V_51 & V_52 ) ) {
V_347 = V_42 ;
do {
V_347 -> V_51 = V_52 ;
V_347 = V_347 -> V_92 ;
} while ( V_347 != V_42 );
return 0 ;
}
return 1 ;
}
int
F_190 (
struct V_38 * V_39 ,
int V_348 )
{
T_3 * V_12 ;
T_11 * log ;
int V_63 ;
log = V_39 -> V_44 ;
if ( ! log ||
log -> V_86 & V_87 ) {
V_39 -> V_77 |= V_349 ;
if ( V_39 -> V_350 )
F_191 ( V_39 -> V_350 ) ;
return 0 ;
}
if ( V_348 && log -> V_90 -> V_51 & V_52 ) {
ASSERT ( F_15 ( log ) ) ;
return 1 ;
}
V_63 = 0 ;
if ( ! V_348 )
F_174 ( log ) ;
F_21 ( & log -> V_110 ) ;
V_39 -> V_77 |= V_349 ;
if ( V_39 -> V_350 )
F_191 ( V_39 -> V_350 ) ;
log -> V_86 |= V_351 ;
if ( V_348 )
V_63 = F_189 ( log ) ;
F_39 ( & log -> V_110 ) ;
F_21 ( & log -> V_23 ) ;
F_8 (tic, &log->l_reserveq, t_queue)
F_10 ( & V_12 -> V_18 ) ;
F_39 ( & log -> V_23 ) ;
F_21 ( & log -> V_27 ) ;
F_8 (tic, &log->l_writeq, t_queue)
F_10 ( & V_12 -> V_18 ) ;
F_39 ( & log -> V_27 ) ;
if ( ! ( log -> V_90 -> V_51 & V_52 ) ) {
ASSERT ( ! V_348 ) ;
F_64 ( V_39 , V_89 , NULL ) ;
F_21 ( & log -> V_110 ) ;
V_63 = F_189 ( log ) ;
F_39 ( & log -> V_110 ) ;
}
F_155 ( log , V_147 , NULL ) ;
#ifdef F_192
{
T_12 * V_42 ;
F_21 ( & log -> V_110 ) ;
V_42 = log -> V_90 ;
do {
ASSERT ( V_42 -> V_201 == 0 ) ;
V_42 = V_42 -> V_92 ;
} while ( V_42 != log -> V_90 );
F_39 ( & log -> V_110 ) ;
}
#endif
return V_63 ;
}
STATIC int
F_80 ( T_11 * log )
{
T_12 * V_42 ;
V_42 = log -> V_90 ;
do {
if ( V_42 -> V_190 . V_237 )
return 0 ;
V_42 = V_42 -> V_92 ;
} while ( V_42 != log -> V_90 );
return 1 ;
}
