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
int
F_73 (
struct V_38 * V_39 ,
struct V_98 V_99 [] ,
int V_125 ,
struct V_11 * V_12 ,
T_5 * V_126 )
{
struct log * log = V_39 -> V_44 ;
int error ;
struct V_104 V_105 = {
. V_106 = V_125 ,
. V_107 = V_99 ,
} ;
if ( F_15 ( log ) )
return F_24 ( V_25 ) ;
error = F_65 ( log , & V_105 , V_12 , V_126 , NULL , 0 ) ;
if ( error )
F_42 ( V_39 , V_57 ) ;
return error ;
}
void
F_74 ( T_8 * V_39 ,
T_5 V_127 )
{
T_3 * V_12 ;
T_11 * log = V_39 -> V_44 ;
int V_13 , V_10 ;
if ( F_15 ( log ) )
return;
if ( V_127 == 0 )
V_127 = F_2 ( & log -> V_128 ) ;
if ( V_127 != 1 )
F_75 ( & log -> V_129 , V_127 ) ;
if ( ! F_76 ( & log -> V_26 ) ) {
#ifdef F_63
if ( log -> V_86 & V_87 )
F_77 ( L_6 ) ;
#endif
F_21 ( & log -> V_27 ) ;
V_10 = F_22 ( log , & log -> V_28 ) ;
F_8 (tic, &log->l_writeq, t_queue) {
ASSERT ( V_12 -> V_14 & V_15 ) ;
if ( V_10 < V_12 -> V_16 && V_127 != 1 )
break;
V_127 = 0 ;
V_10 -= V_12 -> V_16 ;
F_12 ( log , V_12 ) ;
F_10 ( & V_12 -> V_18 ) ;
}
F_39 ( & log -> V_27 ) ;
}
if ( ! F_76 ( & log -> V_20 ) ) {
#ifdef F_63
if ( log -> V_86 & V_87 )
F_77 ( L_6 ) ;
#endif
F_21 ( & log -> V_23 ) ;
V_10 = F_22 ( log , & log -> V_24 ) ;
F_8 (tic, &log->l_reserveq, t_queue) {
if ( V_12 -> V_14 & V_15 )
V_13 = V_12 -> V_16 * V_12 -> V_17 ;
else
V_13 = V_12 -> V_16 ;
if ( V_10 < V_13 && V_127 != 1 )
break;
V_127 = 0 ;
V_10 -= V_13 ;
F_9 ( log , V_12 ) ;
F_10 ( & V_12 -> V_18 ) ;
}
F_39 ( & log -> V_23 ) ;
}
}
int
F_78 ( T_8 * V_39 )
{
int V_130 = 0 ;
T_11 * log = V_39 -> V_44 ;
if ( ! F_79 ( V_39 ) )
return 0 ;
F_21 ( & log -> V_110 ) ;
switch ( log -> V_131 ) {
case V_132 :
case V_133 :
case V_134 :
break;
case V_135 :
case V_136 :
if ( ! F_80 ( log -> V_82 ) &&
F_81 ( log ) ) {
if ( log -> V_131 == V_135 )
log -> V_131 = V_132 ;
else
log -> V_131 = V_133 ;
}
default:
V_130 = 1 ;
break;
}
F_39 ( & log -> V_110 ) ;
return V_130 ;
}
T_5
F_82 (
struct V_38 * V_39 )
{
T_5 V_127 ;
struct log * log = V_39 -> V_44 ;
V_127 = F_80 ( V_39 -> V_83 ) ;
if ( ! V_127 )
V_127 = F_2 ( & log -> V_128 ) ;
F_75 ( & log -> V_129 , V_127 ) ;
return V_127 ;
}
STATIC int
F_22 (
struct log * log ,
T_1 * V_1 )
{
int V_10 ;
int V_137 ;
int V_138 ;
int V_139 ;
int V_140 ;
F_83 ( V_1 , & V_139 , & V_140 ) ;
F_84 ( & log -> V_129 , & V_138 , & V_137 ) ;
V_137 = F_85 ( V_137 ) ;
if ( V_138 == V_139 && V_140 >= V_137 )
V_10 = log -> V_8 - ( V_140 - V_137 ) ;
else if ( V_138 + 1 < V_139 )
return 0 ;
else if ( V_138 < V_139 ) {
ASSERT ( V_138 == ( V_139 - 1 ) ) ;
V_10 = V_137 - V_140 ;
} else {
F_66 ( log -> V_141 ,
L_7
L_8
L_9 ,
V_138 , V_137 , V_139 , V_140 ) ;
ASSERT ( 0 ) ;
V_10 = log -> V_8 ;
}
return V_10 ;
}
void
F_86 ( T_15 * V_142 )
{
T_12 * V_42 = V_142 -> V_143 ;
T_11 * V_144 = V_42 -> V_145 ;
int V_146 = 0 ;
if ( F_87 ( ( F_88 ( V_142 ) ) , V_144 -> V_141 ,
V_147 , V_148 ) ) {
F_89 ( V_142 , V_109 ) ;
F_90 ( V_142 ) ;
F_42 ( V_144 -> V_141 , V_57 ) ;
V_146 = V_149 ;
} else if ( V_42 -> V_51 & V_52 ) {
V_146 = V_149 ;
}
ASSERT ( F_91 ( V_142 ) ) ;
F_92 ( V_42 , V_146 ) ;
}
STATIC void
F_93 ( T_8 * V_39 ,
T_11 * log )
{
int V_150 ;
int V_151 ;
if ( V_39 -> V_152 <= 0 )
log -> V_153 = V_154 ;
else
log -> V_153 = V_39 -> V_152 ;
if ( V_39 -> V_155 > 0 ) {
V_150 = log -> V_156 = V_39 -> V_155 ;
log -> V_157 = 0 ;
while ( V_150 != 1 ) {
log -> V_157 ++ ;
V_150 >>= 1 ;
}
if ( F_94 ( & V_39 -> V_158 ) ) {
V_151 = V_39 -> V_155 / V_159 ;
if ( V_39 -> V_155 % V_159 )
V_151 ++ ;
log -> V_160 = V_151 << V_161 ;
log -> V_162 = V_151 ;
} else {
ASSERT ( V_39 -> V_155 <= V_163 ) ;
log -> V_160 = V_164 ;
log -> V_162 = 1 ;
}
goto V_165;
}
log -> V_156 = V_163 ;
log -> V_157 = V_166 ;
log -> V_160 = V_164 ;
log -> V_162 = 1 ;
V_165:
if ( V_39 -> V_152 == 0 )
V_39 -> V_152 = log -> V_153 ;
if ( V_39 -> V_155 == 0 )
V_39 -> V_155 = log -> V_156 ;
}
STATIC T_11 *
F_51 ( T_8 * V_39 ,
T_9 * V_74 ,
T_10 V_75 ,
int V_76 )
{
T_11 * log ;
T_16 * V_1 ;
T_12 * * V_167 ;
T_12 * V_42 , * V_168 = NULL ;
T_15 * V_142 ;
int V_169 ;
int error = V_71 ;
T_4 V_170 = 0 ;
log = F_95 ( sizeof( T_11 ) , V_70 ) ;
if ( ! log ) {
F_55 ( V_39 , L_10 ) ;
goto V_80;
}
log -> V_141 = V_39 ;
log -> V_171 = V_74 ;
log -> V_8 = F_85 ( V_76 ) ;
log -> V_172 = V_75 ;
log -> V_173 = V_76 ;
log -> V_131 = V_134 ;
log -> V_86 |= V_87 ;
log -> V_174 = - 1 ;
F_96 ( & log -> V_129 , 1 , 0 ) ;
F_96 ( & log -> V_128 , 1 , 0 ) ;
log -> V_175 = 1 ;
F_97 ( & log -> V_24 , 1 , 0 ) ;
F_97 ( & log -> V_28 , 1 , 0 ) ;
F_72 ( & log -> V_20 ) ;
F_72 ( & log -> V_26 ) ;
F_98 ( & log -> V_23 ) ;
F_98 ( & log -> V_27 ) ;
error = V_176 ;
if ( F_99 ( & V_39 -> V_158 ) ) {
V_170 = V_39 -> V_158 . V_177 ;
if ( V_170 < V_161 ) {
F_55 ( V_39 , L_11 ,
V_170 , V_161 ) ;
goto V_81;
}
V_170 -= V_161 ;
if ( V_170 > V_39 -> V_178 ) {
F_55 ( V_39 , L_12 ,
V_170 , V_39 -> V_178 ) ;
goto V_81;
}
if ( V_170 && log -> V_172 > 0 &&
! F_94 ( & V_39 -> V_158 ) ) {
F_55 ( V_39 ,
L_13 ,
V_170 ) ;
goto V_81;
}
}
log -> V_179 = 1 << V_170 ;
F_93 ( V_39 , log ) ;
error = V_71 ;
V_142 = F_100 ( V_39 -> V_180 , 0 , log -> V_156 , 0 ) ;
if ( ! V_142 )
goto V_81;
V_142 -> V_181 = F_86 ;
ASSERT ( F_101 ( V_142 ) ) ;
log -> V_182 = V_142 ;
F_98 ( & log -> V_110 ) ;
F_102 ( & log -> V_183 ) ;
ASSERT ( ( F_103 ( V_142 ) & V_184 ) == 0 ) ;
V_167 = & log -> V_90 ;
ASSERT ( log -> V_156 >= 4096 ) ;
for ( V_169 = 0 ; V_169 < log -> V_153 ; V_169 ++ ) {
* V_167 = F_95 ( sizeof( T_12 ) , V_70 ) ;
if ( ! * V_167 )
goto V_185;
V_42 = * V_167 ;
V_42 -> V_186 = V_168 ;
V_168 = V_42 ;
V_142 = F_104 ( V_39 -> V_180 ,
log -> V_156 , 0 ) ;
if ( ! V_142 )
goto V_185;
V_142 -> V_181 = F_86 ;
V_42 -> V_187 = V_142 ;
V_42 -> V_188 = V_142 -> V_189 ;
#ifdef F_63
log -> V_190 [ V_169 ] = ( V_191 ) & ( V_42 -> V_192 ) ;
#endif
V_1 = & V_42 -> V_192 ;
memset ( V_1 , 0 , sizeof( T_16 ) ) ;
V_1 -> V_193 = F_105 ( V_194 ) ;
V_1 -> V_195 = F_105 (
F_94 ( & log -> V_141 -> V_158 ) ? 2 : 1 ) ;
V_1 -> V_196 = F_105 ( log -> V_156 ) ;
V_1 -> V_197 = F_105 ( V_198 ) ;
memcpy ( & V_1 -> V_199 , & V_39 -> V_158 . V_200 , sizeof( V_201 ) ) ;
V_42 -> V_202 = F_103 ( V_142 ) - log -> V_160 ;
V_42 -> V_51 = V_53 ;
V_42 -> V_145 = log ;
F_106 ( & V_42 -> V_111 , 0 ) ;
F_98 ( & V_42 -> V_50 ) ;
V_42 -> V_56 = & ( V_42 -> V_203 ) ;
V_42 -> V_204 = ( char * ) V_42 -> V_188 + log -> V_160 ;
ASSERT ( F_101 ( V_42 -> V_187 ) ) ;
F_102 ( & V_42 -> V_113 ) ;
F_102 ( & V_42 -> V_205 ) ;
V_167 = & V_42 -> V_92 ;
}
* V_167 = log -> V_90 ;
log -> V_90 -> V_186 = V_168 ;
error = F_107 ( log ) ;
if ( error )
goto V_185;
return log ;
V_185:
for ( V_42 = log -> V_90 ; V_42 ; V_42 = V_168 ) {
V_168 = V_42 -> V_92 ;
if ( V_42 -> V_187 )
F_108 ( V_42 -> V_187 ) ;
F_109 ( V_42 ) ;
}
F_110 ( & log -> V_110 ) ;
F_108 ( log -> V_182 ) ;
V_81:
F_109 ( log ) ;
V_80:
return F_111 ( - error ) ;
}
STATIC int
F_31 (
struct log * log ,
struct V_11 * V_40 ,
struct V_41 * * V_42 ,
T_5 * V_206 )
{
struct V_38 * V_39 = log -> V_141 ;
int error ;
struct V_98 V_99 = {
. V_100 = NULL ,
. V_101 = 0 ,
. V_102 = V_207 ,
} ;
struct V_104 V_105 = {
. V_106 = 1 ,
. V_107 = & V_99 ,
} ;
F_38 ( V_42 ) ;
error = F_65 ( log , & V_105 , V_40 , V_206 , V_42 ,
V_208 ) ;
if ( error )
F_42 ( V_39 , V_57 ) ;
return error ;
}
STATIC void
F_16 (
struct log * log ,
int V_13 )
{
T_5 V_209 = 0 ;
T_5 V_210 ;
int V_211 ;
int V_10 ;
int V_212 ;
int V_213 ;
int V_214 ;
ASSERT ( F_112 ( V_13 ) < log -> V_173 ) ;
V_10 = F_22 ( log , & log -> V_24 ) ;
V_211 = F_113 ( V_10 ) ;
V_214 = F_112 ( V_13 ) ;
V_214 = F_114 ( V_214 , ( log -> V_173 >> 2 ) ) ;
V_214 = F_114 ( V_214 , 256 ) ;
if ( V_211 >= V_214 )
return;
F_84 ( & log -> V_129 , & V_213 ,
& V_212 ) ;
V_212 += V_214 ;
if ( V_212 >= log -> V_173 ) {
V_212 -= log -> V_173 ;
V_213 += 1 ;
}
V_209 = F_115 ( V_213 ,
V_212 ) ;
V_210 = F_2 ( & log -> V_128 ) ;
if ( F_116 ( V_209 , V_210 ) > 0 )
V_209 = V_210 ;
if ( ! F_15 ( log ) )
F_117 ( log -> V_82 , V_209 ) ;
}
STATIC int
F_118 (
struct V_215 * V_142 )
{
struct V_41 * V_42 = V_142 -> V_143 ;
if ( V_42 -> V_51 & V_52 ) {
F_119 ( V_142 , V_25 ) ;
F_90 ( V_142 ) ;
F_120 ( V_142 , 0 ) ;
return 0 ;
}
F_121 ( V_142 ) ;
return 0 ;
}
STATIC int
F_122 ( T_11 * log ,
T_12 * V_42 )
{
V_191 V_216 ;
T_15 * V_142 ;
int V_169 ;
T_4 V_217 ;
T_4 V_218 ;
int V_219 ;
int V_220 = 0 ;
int error ;
int V_221 = F_94 ( & log -> V_141 -> V_158 ) ;
F_17 ( V_222 ) ;
ASSERT ( F_123 ( & V_42 -> V_111 ) == 0 ) ;
V_218 = log -> V_160 + V_42 -> V_91 ;
if ( V_221 && log -> V_141 -> V_158 . V_223 > 1 ) {
V_217 = F_124 ( log , F_125 ( log , V_218 ) ) ;
} else {
V_217 = F_85 ( F_112 ( V_218 ) ) ;
}
V_219 = V_217 - V_218 ;
ASSERT ( V_219 >= 0 ) ;
ASSERT ( ( V_221 && log -> V_141 -> V_158 . V_223 > 1 &&
V_219 < log -> V_141 -> V_158 . V_223 )
||
( log -> V_141 -> V_158 . V_223 <= 1 &&
V_219 < F_85 ( 1 ) ) ) ;
F_6 ( log , & log -> V_24 , V_219 ) ;
F_6 ( log , & log -> V_28 , V_219 ) ;
F_126 ( log , V_42 , V_219 ) ;
if ( V_221 ) {
V_42 -> V_192 . V_224 =
F_105 ( V_42 -> V_91 + V_219 ) ;
} else {
V_42 -> V_192 . V_224 =
F_105 ( V_42 -> V_91 ) ;
}
V_142 = V_42 -> V_187 ;
F_127 ( V_142 , F_128 ( F_129 ( V_42 -> V_192 . V_225 ) ) ) ;
F_130 ( V_226 , F_112 ( V_217 ) ) ;
if ( F_131 ( V_142 ) + F_112 ( V_217 ) > log -> V_173 ) {
V_220 = V_217 - ( F_85 ( log -> V_173 - F_131 ( V_142 ) ) ) ;
V_217 = F_85 ( log -> V_173 - F_131 ( V_142 ) ) ;
V_42 -> V_227 = 2 ;
} else {
V_42 -> V_227 = 1 ;
}
F_132 ( V_142 , V_217 ) ;
V_142 -> V_143 = V_42 ;
F_133 ( V_142 ) ;
F_134 ( V_142 ) ;
V_142 -> V_228 |= V_229 ;
if ( log -> V_141 -> V_77 & V_230 ) {
V_142 -> V_228 |= V_231 ;
if ( log -> V_141 -> V_180 != log -> V_141 -> V_232 )
F_135 ( log -> V_141 -> V_232 ) ;
else
V_142 -> V_228 |= V_233 ;
}
ASSERT ( F_131 ( V_142 ) <= log -> V_173 - 1 ) ;
ASSERT ( F_131 ( V_142 ) + F_112 ( V_217 ) <= log -> V_173 ) ;
F_136 ( log , V_42 , V_217 , V_234 ) ;
F_127 ( V_142 , F_131 ( V_142 ) + log -> V_172 ) ;
F_137 ( V_142 ) ;
error = F_118 ( V_142 ) ;
if ( error ) {
F_89 ( V_142 , L_14 ) ;
return error ;
}
if ( V_220 ) {
V_142 = V_42 -> V_145 -> V_182 ;
F_127 ( V_142 , 0 ) ;
F_138 ( V_142 ,
( char * ) & V_42 -> V_192 + V_217 , V_220 ) ;
V_142 -> V_143 = V_42 ;
F_133 ( V_142 ) ;
F_134 ( V_142 ) ;
V_142 -> V_228 |= V_229 ;
if ( log -> V_141 -> V_77 & V_230 )
V_142 -> V_228 |= V_231 ;
V_216 = V_142 -> V_189 ;
for ( V_169 = 0 ; V_169 < V_220 ; V_169 += V_164 ) {
F_139 ( ( V_235 * ) V_216 , 1 ) ;
if ( F_140 ( * ( V_235 * ) V_216 ) == V_194 )
F_139 ( ( V_235 * ) V_216 , 1 ) ;
V_216 += V_164 ;
}
ASSERT ( F_131 ( V_142 ) <= log -> V_173 - 1 ) ;
ASSERT ( F_131 ( V_142 ) + F_112 ( V_217 ) <= log -> V_173 ) ;
F_127 ( V_142 , F_131 ( V_142 ) + log -> V_172 ) ;
F_137 ( V_142 ) ;
error = F_118 ( V_142 ) ;
if ( error ) {
F_89 ( V_142 , L_15 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_59 ( T_11 * log )
{
T_12 * V_42 , * V_236 ;
int V_169 ;
F_141 ( log ) ;
F_142 ( log -> V_182 , log -> V_156 ) ;
F_108 ( log -> V_182 ) ;
V_42 = log -> V_90 ;
for ( V_169 = 0 ; V_169 < log -> V_153 ; V_169 ++ ) {
F_108 ( V_42 -> V_187 ) ;
V_236 = V_42 -> V_92 ;
F_109 ( V_42 ) ;
V_42 = V_236 ;
}
F_110 ( & log -> V_110 ) ;
log -> V_141 -> V_44 = NULL ;
F_109 ( log ) ;
}
static inline void
F_143 ( T_11 * log ,
T_12 * V_42 ,
int V_237 ,
int V_238 )
{
F_21 ( & log -> V_110 ) ;
F_139 ( & V_42 -> V_192 . V_239 , V_237 ) ;
V_42 -> V_91 += V_238 ;
F_39 ( & log -> V_110 ) ;
}
void
F_144 (
struct V_38 * V_39 ,
struct V_11 * V_40 )
{
T_4 V_169 ;
T_4 V_240 = V_40 -> V_31 * ( T_4 ) sizeof( V_241 ) ;
static char * V_242 [ V_243 ] = {
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
static char * V_244 [ V_245 ] = {
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
V_40 -> V_72 > V_245 ) ?
L_83 : V_244 [ V_40 -> V_72 - 1 ] ) ,
V_40 -> V_72 ,
V_40 -> V_16 ,
V_40 -> V_73 ,
V_40 -> V_30 , V_40 -> V_34 ,
V_40 -> V_31 , V_240 ,
V_40 -> V_30 +
V_40 -> V_34 + V_240 ,
V_40 -> V_29 ) ;
for ( V_169 = 0 ; V_169 < V_40 -> V_29 ; V_169 ++ ) {
T_4 V_37 = V_40 -> V_35 [ V_169 ] . V_37 ;
F_55 ( V_39 , L_84 , V_169 ,
( ( V_37 <= 0 || V_37 > V_243 ) ?
L_85 : V_242 [ V_37 - 1 ] ) ,
V_40 -> V_35 [ V_169 ] . V_36 ) ;
}
F_145 ( V_39 , V_246 ,
L_86 ) ;
F_42 ( V_39 , V_247 ) ;
}
static int
F_146 (
struct V_11 * V_40 ,
struct V_104 * V_248 )
{
struct V_104 * V_249 ;
int V_250 = 0 ;
int V_32 = 0 ;
int V_169 ;
if ( V_40 -> V_14 & V_46 )
V_250 ++ ;
for ( V_249 = V_248 ; V_249 ; V_249 = V_249 -> V_251 ) {
V_250 += V_249 -> V_106 ;
for ( V_169 = 0 ; V_169 < V_249 -> V_106 ; V_169 ++ ) {
struct V_98 * V_252 = & V_249 -> V_107 [ V_169 ] ;
V_32 += V_252 -> V_101 ;
F_29 ( V_40 , V_252 -> V_101 , V_252 -> V_102 ) ;
}
}
V_40 -> V_31 += V_250 ;
V_32 += V_250 * sizeof( struct V_253 ) ;
return V_32 ;
}
static int
F_147 (
struct V_253 * V_254 ,
struct V_11 * V_40 )
{
if ( ! ( V_40 -> V_14 & V_46 ) )
return 0 ;
V_254 -> V_255 = F_105 ( V_40 -> V_68 ) ;
V_254 -> V_256 = V_40 -> V_257 ;
V_254 -> V_258 = 0 ;
V_254 -> V_259 = V_260 ;
V_254 -> V_261 = 0 ;
V_40 -> V_14 &= ~ V_46 ;
return sizeof( struct V_253 ) ;
}
static V_241 *
F_148 (
struct log * log ,
struct V_253 * V_254 ,
struct V_11 * V_40 ,
T_4 V_43 )
{
V_254 -> V_255 = F_105 ( V_40 -> V_68 ) ;
V_254 -> V_256 = V_40 -> V_257 ;
V_254 -> V_261 = 0 ;
V_254 -> V_259 = V_43 ;
switch ( V_254 -> V_256 ) {
case V_64 :
case V_262 :
case V_65 :
break;
default:
F_55 ( log -> V_141 ,
L_87 ,
V_254 -> V_256 , V_40 ) ;
return NULL ;
}
return V_254 ;
}
static int
F_149 (
struct V_11 * V_40 ,
struct V_253 * V_254 ,
int V_263 ,
int V_264 ,
int * V_265 ,
int * V_266 ,
int * V_267 ,
int * V_268 )
{
int V_269 ;
V_269 = V_264 - * V_268 ;
* V_265 = * V_268 ;
if ( V_269 <= V_263 ) {
* V_266 = V_269 ;
V_254 -> V_258 = F_105 ( * V_266 ) ;
if ( * V_267 )
V_254 -> V_259 |= ( V_270 | V_271 ) ;
* V_267 = 0 ;
* V_268 = 0 ;
return 0 ;
}
* V_266 = V_263 ;
V_254 -> V_258 = F_105 ( * V_266 ) ;
V_254 -> V_259 |= V_272 ;
if ( * V_267 )
V_254 -> V_259 |= V_271 ;
* V_268 += * V_266 ;
( * V_267 ) ++ ;
V_40 -> V_73 -= sizeof( struct V_253 ) ;
V_40 -> V_31 ++ ;
return sizeof( struct V_253 ) ;
}
static int
F_150 (
struct log * log ,
struct V_41 * V_42 ,
T_4 V_43 ,
int * V_237 ,
int * V_273 ,
int * V_274 ,
int * V_275 ,
int V_276 ,
struct V_41 * * V_277 )
{
if ( * V_274 ) {
F_143 ( log , V_42 , * V_237 , * V_273 ) ;
* V_237 = 0 ;
* V_273 = 0 ;
return F_41 ( log , V_42 ) ;
}
* V_274 = 0 ;
* V_275 = 0 ;
if ( V_42 -> V_202 - V_276 <= sizeof( V_241 ) ) {
F_143 ( log , V_42 , * V_237 , * V_273 ) ;
* V_237 = 0 ;
* V_273 = 0 ;
F_21 ( & log -> V_110 ) ;
F_68 ( log , V_42 ) ;
F_39 ( & log -> V_110 ) ;
if ( ! V_277 )
return F_41 ( log , V_42 ) ;
ASSERT ( V_43 & V_208 ) ;
* V_277 = V_42 ;
}
return 0 ;
}
int
F_65 (
struct log * log ,
struct V_104 * V_248 ,
struct V_11 * V_40 ,
T_5 * V_126 ,
struct V_41 * * V_277 ,
T_4 V_43 )
{
struct V_41 * V_42 = NULL ;
struct V_98 * V_252 ;
struct V_104 * V_249 ;
int V_32 ;
int V_278 ;
int V_274 = 0 ;
int V_275 = 0 ;
int V_279 = 0 ;
int V_237 = 0 ;
int V_273 = 0 ;
int error ;
* V_126 = 0 ;
V_32 = F_146 ( V_40 , V_248 ) ;
if ( log -> V_280 ) {
if ( V_40 -> V_14 & V_46 )
V_40 -> V_73 -= sizeof( V_241 ) ;
if ( V_43 & ( V_208 | V_108 ) )
V_40 -> V_73 -= sizeof( V_241 ) ;
} else
V_40 -> V_73 -= V_32 ;
if ( V_40 -> V_73 < 0 )
F_144 ( log -> V_141 , V_40 ) ;
V_278 = 0 ;
V_249 = V_248 ;
V_252 = V_249 -> V_107 ;
while ( V_249 && V_278 < V_249 -> V_106 ) {
void * V_281 ;
int V_276 ;
error = F_151 ( log , V_32 , & V_42 , V_40 ,
& V_279 , & V_276 ) ;
if ( error )
return error ;
ASSERT ( V_276 <= V_42 -> V_202 - 1 ) ;
V_281 = V_42 -> V_204 + V_276 ;
if ( ! * V_126 )
* V_126 = F_129 ( V_42 -> V_192 . V_225 ) ;
while ( V_249 && V_278 < V_249 -> V_106 ) {
struct V_98 * V_99 = & V_252 [ V_278 ] ;
struct V_253 * V_254 ;
int V_282 ;
int V_266 ;
int V_265 ;
ASSERT ( V_99 -> V_101 % sizeof( V_283 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_281 % sizeof( V_283 ) == 0 ) ;
V_282 = F_147 ( V_281 , V_40 ) ;
if ( V_282 ) {
V_237 ++ ;
F_152 ( & V_281 , & V_32 , & V_276 ,
V_282 ) ;
}
V_254 = F_148 ( log , V_281 , V_40 , V_43 ) ;
if ( ! V_254 )
return F_24 ( V_25 ) ;
F_152 ( & V_281 , & V_32 , & V_276 ,
sizeof( struct V_253 ) ) ;
V_32 += F_149 ( V_40 , V_254 ,
V_42 -> V_202 - V_276 ,
V_99 -> V_101 ,
& V_265 , & V_266 ,
& V_274 ,
& V_275 ) ;
F_153 ( log , V_281 ) ;
ASSERT ( V_266 >= 0 ) ;
memcpy ( V_281 , V_99 -> V_100 + V_265 , V_266 ) ;
F_152 ( & V_281 , & V_32 , & V_276 , V_266 ) ;
V_266 += V_282 + sizeof( V_241 ) ;
V_237 ++ ;
V_273 += V_279 ? V_266 : 0 ;
error = F_150 ( log , V_42 , V_43 ,
& V_237 , & V_273 ,
& V_274 ,
& V_275 ,
V_276 ,
V_277 ) ;
if ( error )
return error ;
if ( V_274 )
break;
if ( ++ V_278 == V_249 -> V_106 ) {
V_249 = V_249 -> V_251 ;
V_278 = 0 ;
if ( V_249 )
V_252 = V_249 -> V_107 ;
}
if ( V_237 == 0 ) {
if ( ! V_249 )
return 0 ;
break;
}
}
}
ASSERT ( V_32 == 0 ) ;
F_143 ( log , V_42 , V_237 , V_273 ) ;
if ( ! V_277 )
return F_41 ( log , V_42 ) ;
ASSERT ( V_43 & V_208 ) ;
* V_277 = V_42 ;
return 0 ;
}
STATIC void
F_154 ( T_11 * log )
{
T_12 * V_42 ;
int V_284 = 0 ;
V_42 = log -> V_90 ;
do {
if ( V_42 -> V_51 == V_112 ) {
V_42 -> V_51 = V_53 ;
V_42 -> V_91 = 0 ;
ASSERT ( V_42 -> V_203 == NULL ) ;
if ( ! V_284 &&
( F_140 ( V_42 -> V_192 . V_239 ) ==
V_285 ) ) {
V_284 = 1 ;
} else {
V_284 = 2 ;
}
V_42 -> V_192 . V_239 = 0 ;
memset ( V_42 -> V_192 . V_286 , 0 ,
sizeof( V_42 -> V_192 . V_286 ) ) ;
V_42 -> V_192 . V_225 = 0 ;
} else if ( V_42 -> V_51 == V_53 )
;
else
break;
V_42 = V_42 -> V_92 ;
} while ( V_42 != log -> V_90 );
if ( V_284 ) {
switch ( log -> V_131 ) {
case V_134 :
case V_135 :
case V_136 :
log -> V_131 = V_135 ;
break;
case V_132 :
if ( V_284 == 1 )
log -> V_131 = V_136 ;
else
log -> V_131 = V_135 ;
break;
case V_133 :
if ( V_284 == 1 )
log -> V_131 = V_134 ;
else
log -> V_131 = V_135 ;
break;
default:
ASSERT ( 0 ) ;
}
}
}
STATIC T_5
F_155 (
T_11 * log )
{
T_12 * V_287 ;
T_5 V_288 , V_45 ;
V_287 = log -> V_90 ;
V_288 = 0 ;
do {
if ( ! ( V_287 -> V_51 & ( V_53 | V_112 ) ) ) {
V_45 = F_129 ( V_287 -> V_192 . V_225 ) ;
if ( ( V_45 && ! V_288 ) ||
( F_116 ( V_45 , V_288 ) < 0 ) ) {
V_288 = V_45 ;
}
}
V_287 = V_287 -> V_92 ;
} while ( V_287 != log -> V_90 );
return V_288 ;
}
STATIC void
F_156 (
T_11 * log ,
int V_146 ,
T_12 * V_289 )
{
T_12 * V_42 ;
T_12 * V_88 ;
T_6 * V_48 , * V_55 ;
int V_290 = 0 ;
T_5 V_288 ;
int V_291 ;
int V_292 ;
int V_293 ;
int V_294 ;
int V_295 = 0 ;
F_21 ( & log -> V_110 ) ;
V_88 = V_42 = log -> V_90 ;
V_291 = 0 ;
V_293 = 0 ;
V_294 = 0 ;
do {
V_88 = log -> V_90 ;
V_42 = log -> V_90 ;
V_292 = 0 ;
V_294 ++ ;
do {
if ( V_42 -> V_51 &
( V_53 | V_112 ) ) {
V_42 = V_42 -> V_92 ;
continue;
}
if ( ! ( V_42 -> V_51 & V_52 ) ) {
if ( ! ( V_42 -> V_51 &
( V_296 |
V_297 ) ) ) {
if ( V_289 && ( V_289 -> V_51 ==
V_296 ) ) {
V_289 -> V_51 = V_297 ;
}
break;
}
V_288 = F_155 ( log ) ;
if ( V_288 &&
F_116 ( V_288 ,
F_129 ( V_42 -> V_192 . V_225 ) ) < 0 ) {
V_42 = V_42 -> V_92 ;
continue;
}
V_42 -> V_51 = V_298 ;
ASSERT ( F_116 ( F_2 ( & log -> V_128 ) ,
F_129 ( V_42 -> V_192 . V_225 ) ) <= 0 ) ;
F_75 ( & log -> V_128 ,
F_129 ( V_42 -> V_192 . V_225 ) ) ;
} else
V_291 ++ ;
F_39 ( & log -> V_110 ) ;
F_21 ( & V_42 -> V_50 ) ;
V_48 = V_42 -> V_203 ;
while ( V_48 ) {
V_42 -> V_56 = & ( V_42 -> V_203 ) ;
V_42 -> V_203 = NULL ;
F_39 ( & V_42 -> V_50 ) ;
for (; V_48 ; V_48 = V_55 ) {
V_55 = V_48 -> V_55 ;
V_48 -> V_299 ( V_48 -> V_300 , V_146 ) ;
}
F_21 ( & V_42 -> V_50 ) ;
V_48 = V_42 -> V_203 ;
}
V_292 ++ ;
V_293 ++ ;
F_21 ( & log -> V_110 ) ;
ASSERT ( V_42 -> V_203 == NULL ) ;
F_39 ( & V_42 -> V_50 ) ;
if ( ! ( V_42 -> V_51 & V_52 ) )
V_42 -> V_51 = V_112 ;
F_154 ( log ) ;
F_157 ( & V_42 -> V_113 ) ;
V_42 = V_42 -> V_92 ;
} while ( V_88 != V_42 );
if ( V_294 > 5000 ) {
V_290 += V_294 ;
V_294 = 0 ;
F_55 ( log -> V_141 ,
L_88 ,
V_109 , V_290 ) ;
}
} while ( ! V_291 && V_292 );
#ifdef F_63
if ( V_293 ) {
V_88 = V_42 = log -> V_90 ;
do {
ASSERT ( V_42 -> V_51 != V_297 ) ;
if ( V_42 -> V_51 == V_54 ||
V_42 -> V_51 == V_301 ||
V_42 -> V_51 == V_296 ||
V_42 -> V_51 == V_52 )
break;
V_42 = V_42 -> V_92 ;
} while ( V_88 != V_42 );
}
#endif
if ( log -> V_90 -> V_51 & ( V_53 | V_52 ) )
V_295 = 1 ;
F_39 ( & log -> V_110 ) ;
if ( V_295 )
F_157 ( & log -> V_183 ) ;
}
STATIC void
F_92 (
T_12 * V_42 ,
int V_146 )
{
T_11 * log = V_42 -> V_145 ;
F_21 ( & log -> V_110 ) ;
ASSERT ( V_42 -> V_51 == V_301 ||
V_42 -> V_51 == V_52 ) ;
ASSERT ( F_123 ( & V_42 -> V_111 ) == 0 ) ;
ASSERT ( V_42 -> V_227 == 1 || V_42 -> V_227 == 2 ) ;
if ( V_42 -> V_51 != V_52 ) {
if ( -- V_42 -> V_227 == 1 ) {
F_39 ( & log -> V_110 ) ;
return;
}
V_42 -> V_51 = V_296 ;
}
F_157 ( & V_42 -> V_205 ) ;
F_39 ( & log -> V_110 ) ;
F_156 ( log , V_146 , V_42 ) ;
}
STATIC int
F_151 ( T_11 * log ,
int V_32 ,
T_12 * * V_167 ,
T_3 * V_40 ,
int * V_302 ,
int * V_303 )
{
int V_276 ;
T_16 * V_1 ;
T_12 * V_42 ;
int error ;
V_304:
F_21 ( & log -> V_110 ) ;
if ( F_15 ( log ) ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
V_42 = log -> V_90 ;
if ( V_42 -> V_51 != V_53 ) {
F_17 ( V_305 ) ;
F_19 ( & log -> V_183 , & log -> V_110 ) ;
goto V_304;
}
V_1 = & V_42 -> V_192 ;
F_67 ( & V_42 -> V_111 ) ;
V_276 = V_42 -> V_91 ;
if ( V_276 == 0 ) {
V_40 -> V_73 -= log -> V_160 ;
F_29 ( V_40 ,
log -> V_160 ,
V_306 ) ;
V_1 -> V_307 = F_105 ( log -> V_175 ) ;
V_1 -> V_225 = F_158 (
F_115 ( log -> V_175 , log -> V_308 ) ) ;
ASSERT ( log -> V_308 >= 0 ) ;
}
if ( V_42 -> V_202 - V_42 -> V_91 < 2 * sizeof( V_241 ) ) {
F_159 ( log , V_42 , V_42 -> V_202 ) ;
if ( ! F_160 ( & V_42 -> V_111 , - 1 , 1 ) ) {
F_39 ( & log -> V_110 ) ;
error = F_41 ( log , V_42 ) ;
if ( error )
return error ;
} else {
F_39 ( & log -> V_110 ) ;
}
goto V_304;
}
if ( V_32 <= V_42 -> V_202 - V_42 -> V_91 ) {
* V_302 = 0 ;
V_42 -> V_91 += V_32 ;
} else {
* V_302 = 1 ;
F_159 ( log , V_42 , V_42 -> V_202 ) ;
}
* V_167 = V_42 ;
ASSERT ( V_42 -> V_91 <= V_42 -> V_202 ) ;
F_39 ( & log -> V_110 ) ;
* V_303 = V_276 ;
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
F_161 ( log , V_12 ) ;
V_13 = V_12 -> V_16 ;
if ( V_12 -> V_14 & V_67 )
V_13 *= V_12 -> V_309 ;
V_10 = F_22 ( log , & log -> V_24 ) ;
if ( ! F_76 ( & log -> V_20 ) ) {
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
F_162 ( log , V_12 ) ;
F_163 ( log ) ;
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
F_164 ( log , V_12 ) ;
V_13 = V_12 -> V_16 ;
V_10 = F_22 ( log , & log -> V_28 ) ;
if ( ! F_76 ( & log -> V_26 ) ) {
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
F_165 ( log , V_12 ) ;
F_163 ( log ) ;
return 0 ;
}
STATIC void
F_36 ( T_11 * log ,
T_3 * V_40 )
{
F_166 ( log , V_40 ) ;
if ( V_40 -> V_17 > 0 )
V_40 -> V_17 -- ;
F_1 ( log , & log -> V_24 ,
V_40 -> V_73 ) ;
F_1 ( log , & log -> V_28 ,
V_40 -> V_73 ) ;
V_40 -> V_73 = V_40 -> V_16 ;
F_28 ( V_40 ) ;
F_167 ( log , V_40 ) ;
if ( V_40 -> V_17 > 0 )
return;
F_6 ( log , & log -> V_24 ,
V_40 -> V_16 ) ;
F_168 ( log , V_40 ) ;
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
F_169 ( log , V_40 ) ;
F_170 ( log , V_40 ) ;
V_2 = V_40 -> V_73 ;
if ( V_40 -> V_17 > 0 ) {
ASSERT ( V_40 -> V_14 & V_15 ) ;
V_2 += V_40 -> V_16 * V_40 -> V_17 ;
}
F_1 ( log , & log -> V_24 , V_2 ) ;
F_1 ( log , & log -> V_28 , V_2 ) ;
F_171 ( log , V_40 ) ;
F_74 ( log -> V_141 , 1 ) ;
}
STATIC int
F_41 (
T_11 * log ,
T_12 * V_42 )
{
int V_310 = 0 ;
if ( V_42 -> V_51 & V_52 )
return F_24 ( V_25 ) ;
ASSERT ( F_123 ( & V_42 -> V_111 ) > 0 ) ;
if ( ! F_172 ( & V_42 -> V_111 , & log -> V_110 ) )
return 0 ;
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
ASSERT ( V_42 -> V_51 == V_53 ||
V_42 -> V_51 == V_54 ) ;
if ( V_42 -> V_51 == V_54 ) {
T_5 V_127 = F_82 ( log -> V_141 ) ;
V_310 ++ ;
V_42 -> V_51 = V_301 ;
V_42 -> V_192 . V_311 = F_158 ( V_127 ) ;
F_173 ( log , V_42 , V_127 ) ;
}
F_39 ( & log -> V_110 ) ;
if ( V_310 )
return F_122 ( log , V_42 ) ;
return 0 ;
}
STATIC void
F_159 ( T_11 * log ,
T_12 * V_42 ,
int V_312 )
{
ASSERT ( V_42 -> V_51 == V_53 ) ;
if ( ! V_312 )
V_312 = V_42 -> V_91 ;
V_42 -> V_51 = V_54 ;
V_42 -> V_192 . V_313 = F_105 ( log -> V_174 ) ;
log -> V_174 = log -> V_308 ;
log -> V_314 = log -> V_175 ;
log -> V_308 += F_112 ( V_312 ) + F_112 ( log -> V_160 ) ;
if ( F_94 ( & log -> V_141 -> V_158 ) &&
log -> V_141 -> V_158 . V_223 > 1 ) {
T_14 V_315 = F_112 ( log -> V_141 -> V_158 . V_223 ) ;
log -> V_308 = F_174 ( log -> V_308 , V_315 ) ;
}
if ( log -> V_308 >= log -> V_173 ) {
log -> V_175 ++ ;
if ( log -> V_175 == V_194 )
log -> V_175 ++ ;
log -> V_308 -= log -> V_173 ;
ASSERT ( log -> V_308 >= 0 ) ;
}
ASSERT ( V_42 == log -> V_90 ) ;
log -> V_90 = V_42 -> V_92 ;
}
int
F_64 (
struct V_38 * V_39 ,
T_4 V_43 ,
int * V_316 )
{
struct log * log = V_39 -> V_44 ;
struct V_41 * V_42 ;
T_5 V_45 ;
F_17 ( V_317 ) ;
if ( log -> V_280 )
F_175 ( log ) ;
F_21 ( & log -> V_110 ) ;
V_42 = log -> V_90 ;
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
if ( V_42 -> V_51 == V_53 ||
V_42 -> V_51 == V_112 ) {
if ( V_42 -> V_51 == V_112 ||
( F_123 ( & V_42 -> V_111 ) == 0
&& V_42 -> V_91 == 0 ) ) {
V_42 = V_42 -> V_186 ;
if ( V_42 -> V_51 == V_53 ||
V_42 -> V_51 == V_112 )
goto V_318;
else
goto V_319;
} else {
if ( F_123 ( & V_42 -> V_111 ) == 0 ) {
F_67 ( & V_42 -> V_111 ) ;
V_45 = F_129 ( V_42 -> V_192 . V_225 ) ;
F_159 ( log , V_42 , 0 ) ;
F_39 ( & log -> V_110 ) ;
if ( F_41 ( log , V_42 ) )
return F_24 ( V_25 ) ;
if ( V_316 )
* V_316 = 1 ;
F_21 ( & log -> V_110 ) ;
if ( F_129 ( V_42 -> V_192 . V_225 ) == V_45 &&
V_42 -> V_51 != V_112 )
goto V_319;
else
goto V_318;
} else {
F_159 ( log , V_42 , 0 ) ;
goto V_319;
}
}
}
V_319:
if ( V_43 & V_89 ) {
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
F_17 ( V_320 ) ;
F_19 ( & V_42 -> V_113 , & log -> V_110 ) ;
if ( V_42 -> V_51 & V_52 )
return F_24 ( V_25 ) ;
if ( V_316 )
* V_316 = 1 ;
} else {
V_318:
F_39 ( & log -> V_110 ) ;
}
return 0 ;
}
void
F_176 (
T_8 * V_39 ,
T_4 V_43 )
{
int error ;
error = F_64 ( V_39 , V_43 , NULL ) ;
if ( error )
F_55 ( V_39 , L_89 , V_109 , error ) ;
}
int
F_177 (
struct V_38 * V_39 ,
T_5 V_45 ,
T_4 V_43 ,
int * V_316 )
{
struct log * log = V_39 -> V_44 ;
struct V_41 * V_42 ;
int V_321 = 0 ;
ASSERT ( V_45 != 0 ) ;
F_17 ( V_317 ) ;
if ( log -> V_280 ) {
V_45 = F_178 ( log , V_45 ) ;
if ( V_45 == V_322 )
return 0 ;
}
V_323:
F_21 ( & log -> V_110 ) ;
V_42 = log -> V_90 ;
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
do {
if ( F_129 ( V_42 -> V_192 . V_225 ) != V_45 ) {
V_42 = V_42 -> V_92 ;
continue;
}
if ( V_42 -> V_51 == V_112 ) {
F_39 ( & log -> V_110 ) ;
return 0 ;
}
if ( V_42 -> V_51 == V_53 ) {
if ( ! V_321 &&
( V_42 -> V_186 -> V_51 &
( V_54 | V_301 ) ) ) {
ASSERT ( ! ( V_42 -> V_51 & V_52 ) ) ;
F_17 ( V_320 ) ;
F_19 ( & V_42 -> V_186 -> V_205 ,
& log -> V_110 ) ;
if ( V_316 )
* V_316 = 1 ;
V_321 = 1 ;
goto V_323;
}
F_67 ( & V_42 -> V_111 ) ;
F_159 ( log , V_42 , 0 ) ;
F_39 ( & log -> V_110 ) ;
if ( F_41 ( log , V_42 ) )
return F_24 ( V_25 ) ;
if ( V_316 )
* V_316 = 1 ;
F_21 ( & log -> V_110 ) ;
}
if ( ( V_43 & V_89 ) &&
! ( V_42 -> V_51 &
( V_53 | V_112 ) ) ) {
if ( V_42 -> V_51 & V_52 ) {
F_39 ( & log -> V_110 ) ;
return F_24 ( V_25 ) ;
}
F_17 ( V_320 ) ;
F_19 ( & V_42 -> V_113 , & log -> V_110 ) ;
if ( V_42 -> V_51 & V_52 )
return F_24 ( V_25 ) ;
if ( V_316 )
* V_316 = 1 ;
} else {
F_39 ( & log -> V_110 ) ;
}
return 0 ;
} while ( V_42 != log -> V_90 );
F_39 ( & log -> V_110 ) ;
return 0 ;
}
void
F_179 (
T_8 * V_39 ,
T_5 V_45 ,
T_4 V_43 )
{
int error ;
error = F_177 ( V_39 , V_45 , V_43 , NULL ) ;
if ( error )
F_55 ( V_39 , L_89 , V_109 , error ) ;
}
STATIC void
F_68 ( T_11 * log , T_12 * V_42 )
{
F_180 ( & log -> V_110 ) ;
if ( V_42 -> V_51 == V_53 ) {
F_159 ( log , V_42 , 0 ) ;
} else {
ASSERT ( V_42 -> V_51 &
( V_54 | V_52 ) ) ;
}
}
void
F_34 (
T_3 * V_40 )
{
ASSERT ( F_123 ( & V_40 -> V_324 ) > 0 ) ;
if ( F_181 ( & V_40 -> V_324 ) )
F_182 ( V_325 , V_40 ) ;
}
T_3 *
F_183 (
T_3 * V_40 )
{
ASSERT ( F_123 ( & V_40 -> V_324 ) > 0 ) ;
F_67 ( & V_40 -> V_324 ) ;
return V_40 ;
}
T_3 *
F_46 (
struct log * log ,
int V_58 ,
int V_59 ,
char V_60 ,
T_4 V_326 ,
int V_327 )
{
struct V_11 * V_12 ;
T_4 V_328 ;
int V_329 ;
V_12 = F_184 ( V_325 , V_327 ) ;
if ( ! V_12 )
return NULL ;
V_58 += sizeof( V_241 ) ;
V_58 += sizeof( V_330 ) ;
V_58 += sizeof( V_241 ) ;
V_329 = log -> V_156 - log -> V_160 ;
V_328 = F_185 ( V_58 , V_329 ) ;
V_58 += sizeof( V_241 ) * V_328 ;
while ( ! V_328 ||
F_185 ( V_58 , V_329 ) > V_328 ) {
V_58 += sizeof( V_241 ) ;
V_328 ++ ;
}
V_58 += log -> V_160 * V_328 ;
V_58 += log -> V_160 ;
if ( F_94 ( & log -> V_141 -> V_158 ) &&
log -> V_141 -> V_158 . V_223 > 1 ) {
V_58 += 2 * log -> V_141 -> V_158 . V_223 ;
} else {
V_58 += 2 * V_164 ;
}
F_106 ( & V_12 -> V_324 , 1 ) ;
F_72 ( & V_12 -> V_19 ) ;
V_12 -> V_16 = V_58 ;
V_12 -> V_73 = V_58 ;
V_12 -> V_17 = V_59 ;
V_12 -> V_309 = V_59 ;
V_12 -> V_68 = F_186 () ;
V_12 -> V_257 = V_60 ;
V_12 -> V_14 = V_46 ;
V_12 -> V_72 = 0 ;
if ( V_326 & V_67 )
V_12 -> V_14 |= V_15 ;
F_102 ( & V_12 -> V_18 ) ;
F_28 ( V_12 ) ;
return V_12 ;
}
void
F_153 (
struct log * log ,
char * V_281 )
{
int V_169 ;
int V_331 = 0 ;
for ( V_169 = 0 ; V_169 < log -> V_153 ; V_169 ++ ) {
if ( V_281 >= log -> V_190 [ V_169 ] &&
V_281 <= log -> V_190 [ V_169 ] + log -> V_156 )
V_331 ++ ;
}
if ( ! V_331 )
F_187 ( log -> V_141 , L_90 , V_109 ) ;
}
STATIC void
F_163 (
struct log * log )
{
int V_138 , V_332 ;
int V_6 , V_7 ;
F_83 ( & log -> V_28 , & V_6 , & V_7 ) ;
F_84 ( & log -> V_129 , & V_138 , & V_332 ) ;
if ( V_138 != V_6 ) {
if ( V_6 - 1 != V_138 &&
! ( log -> V_86 & V_333 ) ) {
F_145 ( log -> V_141 , V_246 ,
L_91 , V_109 ) ;
log -> V_86 |= V_333 ;
}
if ( V_7 > F_85 ( V_332 ) &&
! ( log -> V_86 & V_333 ) ) {
F_145 ( log -> V_141 , V_246 ,
L_92 , V_109 ) ;
log -> V_86 |= V_333 ;
}
}
}
STATIC void
F_173 ( T_11 * log ,
T_12 * V_42 ,
T_5 V_127 )
{
int V_334 ;
if ( F_188 ( V_127 ) == log -> V_314 ) {
V_334 =
log -> V_173 - ( log -> V_174 - F_128 ( V_127 ) ) ;
if ( V_334 < F_112 ( V_42 -> V_91 ) + F_112 ( log -> V_160 ) )
F_187 ( log -> V_141 , L_93 , V_109 ) ;
} else {
ASSERT ( F_188 ( V_127 ) + 1 == log -> V_314 ) ;
if ( F_128 ( V_127 ) == log -> V_174 )
F_187 ( log -> V_141 , L_94 , V_109 ) ;
V_334 = F_128 ( V_127 ) - log -> V_174 ;
if ( V_334 < F_112 ( V_42 -> V_91 ) + 1 )
F_187 ( log -> V_141 , L_93 , V_109 ) ;
}
}
STATIC void
F_136 ( T_11 * log ,
T_12 * V_42 ,
int V_217 ,
T_17 V_335 )
{
V_241 * V_336 ;
T_12 * V_337 ;
T_18 * V_338 ;
V_191 V_281 ;
V_191 V_339 ;
T_19 V_340 ;
T_7 V_341 ;
int V_32 , V_169 , V_342 , V_343 , V_344 ;
int V_345 ;
F_21 ( & log -> V_110 ) ;
V_337 = log -> V_90 ;
for ( V_169 = 0 ; V_169 < log -> V_153 ; V_169 ++ ) {
if ( V_337 == NULL )
F_187 ( log -> V_141 , L_90 , V_109 ) ;
V_337 = V_337 -> V_92 ;
}
if ( V_337 != log -> V_90 )
F_187 ( log -> V_141 , L_95 , V_109 ) ;
F_39 ( & log -> V_110 ) ;
if ( V_42 -> V_192 . V_193 != F_105 ( V_194 ) )
F_187 ( log -> V_141 , L_96 , V_109 ) ;
V_281 = ( V_191 ) & V_42 -> V_192 ;
for ( V_281 += V_164 ; V_281 < ( ( V_191 ) & V_42 -> V_192 ) + V_217 ;
V_281 += V_164 ) {
if ( * ( V_235 * ) V_281 == F_105 ( V_194 ) )
F_187 ( log -> V_141 , L_97 ,
V_109 ) ;
}
V_32 = F_140 ( V_42 -> V_192 . V_239 ) ;
V_281 = V_42 -> V_204 ;
V_339 = V_281 ;
V_336 = ( V_241 * ) V_281 ;
V_338 = V_42 -> V_188 ;
for ( V_169 = 0 ; V_169 < V_32 ; V_169 ++ ) {
V_336 = ( V_241 * ) V_281 ;
V_340 = ( T_19 )
( ( V_191 ) & ( V_336 -> V_256 ) - V_339 ) ;
if ( V_335 == V_346 || ( V_340 & 0x1ff ) ) {
V_341 = V_336 -> V_256 ;
} else {
V_345 = F_113 ( ( V_191 ) & ( V_336 -> V_256 ) - V_42 -> V_204 ) ;
if ( V_345 >= ( V_159 / V_164 ) ) {
V_342 = V_345 / ( V_159 / V_164 ) ;
V_343 = V_345 % ( V_159 / V_164 ) ;
V_341 = F_189 (
V_338 [ V_342 ] . V_347 . V_348 [ V_343 ] ) ;
} else {
V_341 = F_189 (
V_42 -> V_192 . V_286 [ V_345 ] ) ;
}
}
if ( V_341 != V_64 && V_341 != V_65 )
F_55 ( log -> V_141 ,
L_98 ,
V_109 , V_341 , V_336 ,
( unsigned long ) V_340 ) ;
V_340 = ( T_19 )
( ( V_191 ) & ( V_336 -> V_258 ) - V_339 ) ;
if ( V_335 == V_346 || ( V_340 & 0x1ff ) ) {
V_344 = F_140 ( V_336 -> V_258 ) ;
} else {
V_345 = F_113 ( ( T_19 ) & V_336 -> V_258 -
( T_19 ) V_42 -> V_204 ) ;
if ( V_345 >= ( V_159 / V_164 ) ) {
V_342 = V_345 / ( V_159 / V_164 ) ;
V_343 = V_345 % ( V_159 / V_164 ) ;
V_344 = F_140 ( V_338 [ V_342 ] . V_347 . V_348 [ V_343 ] ) ;
} else {
V_344 = F_140 ( V_42 -> V_192 . V_286 [ V_345 ] ) ;
}
}
V_281 += sizeof( V_241 ) + V_344 ;
}
}
STATIC int
F_190 (
T_11 * log )
{
T_12 * V_42 , * V_349 ;
V_42 = log -> V_90 ;
if ( ! ( V_42 -> V_51 & V_52 ) ) {
V_349 = V_42 ;
do {
V_349 -> V_51 = V_52 ;
V_349 = V_349 -> V_92 ;
} while ( V_349 != V_42 );
return 0 ;
}
return 1 ;
}
int
F_191 (
struct V_38 * V_39 ,
int V_350 )
{
T_3 * V_12 ;
T_11 * log ;
int V_63 ;
log = V_39 -> V_44 ;
if ( ! log ||
log -> V_86 & V_87 ) {
V_39 -> V_77 |= V_351 ;
if ( V_39 -> V_352 )
F_192 ( V_39 -> V_352 ) ;
return 0 ;
}
if ( V_350 && log -> V_90 -> V_51 & V_52 ) {
ASSERT ( F_15 ( log ) ) ;
return 1 ;
}
V_63 = 0 ;
if ( ! V_350 && ( V_39 -> V_77 & V_353 ) )
F_175 ( log ) ;
F_21 ( & log -> V_110 ) ;
V_39 -> V_77 |= V_351 ;
if ( V_39 -> V_352 )
F_192 ( V_39 -> V_352 ) ;
log -> V_86 |= V_354 ;
if ( V_350 )
V_63 = F_190 ( log ) ;
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
ASSERT ( ! V_350 ) ;
F_64 ( V_39 , V_89 , NULL ) ;
F_21 ( & log -> V_110 ) ;
V_63 = F_190 ( log ) ;
F_39 ( & log -> V_110 ) ;
}
F_156 ( log , V_149 , NULL ) ;
#ifdef F_193
{
T_12 * V_42 ;
F_21 ( & log -> V_110 ) ;
V_42 = log -> V_90 ;
do {
ASSERT ( V_42 -> V_203 == 0 ) ;
V_42 = V_42 -> V_92 ;
} while ( V_42 != log -> V_90 );
F_39 ( & log -> V_110 ) ;
}
#endif
return V_63 ;
}
STATIC int
F_81 ( T_11 * log )
{
T_12 * V_42 ;
V_42 = log -> V_90 ;
do {
if ( V_42 -> V_192 . V_239 )
return 0 ;
V_42 = V_42 -> V_92 ;
} while ( V_42 != log -> V_90 );
return 1 ;
}
