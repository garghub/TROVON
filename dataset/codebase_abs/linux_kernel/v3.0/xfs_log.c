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
static void
F_7 ( T_3 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
V_10 -> V_13 = 0 ;
}
static void
F_8 ( T_3 * V_10 , T_4 V_14 , T_4 type )
{
if ( V_10 -> V_11 == V_15 ) {
V_10 -> V_16 += V_10 -> V_12 ;
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
V_10 -> V_17 [ V_10 -> V_11 ] . V_18 = V_14 ;
V_10 -> V_17 [ V_10 -> V_11 ] . V_19 = type ;
V_10 -> V_12 += V_14 ;
V_10 -> V_11 ++ ;
}
T_5
F_9 (
struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_24 * * V_25 ,
T_4 V_26 )
{
struct log * log = V_21 -> V_27 ;
T_5 V_28 = 0 ;
if ( F_10 ( log ) ||
( ( ( V_23 -> V_29 & V_30 ) == 0 ) &&
( F_11 ( log , V_23 , V_25 , & V_28 ) ) ) ) {
V_28 = ( T_5 ) - 1 ;
if ( V_23 -> V_29 & V_31 ) {
V_26 |= V_32 ;
}
}
if ( ( V_23 -> V_29 & V_31 ) == 0 ||
( V_26 & V_32 ) ) {
F_12 ( log , V_23 ) ;
F_13 ( log , V_23 ) ;
F_14 ( V_23 ) ;
} else {
F_15 ( log , V_23 ) ;
F_16 ( log , V_23 ) ;
V_23 -> V_29 |= V_30 ;
}
return V_28 ;
}
int
F_17 (
struct V_20 * V_21 ,
struct V_24 * V_25 ,
T_6 * V_33 )
{
int V_34 ;
F_18 ( & V_25 -> V_35 ) ;
V_34 = ( V_25 -> V_36 & V_37 ) ;
if ( ! V_34 ) {
F_19 ( ( V_25 -> V_36 == V_38 ) ||
( V_25 -> V_36 == V_39 ) ) ;
V_33 -> V_40 = NULL ;
* ( V_25 -> V_41 ) = V_33 ;
V_25 -> V_41 = & ( V_33 -> V_40 ) ;
}
F_20 ( & V_25 -> V_35 ) ;
return V_34 ;
}
int
F_21 (
struct V_20 * V_21 ,
struct V_24 * V_25 )
{
if ( F_22 ( V_21 -> V_27 , V_25 ) ) {
F_23 ( V_21 , V_42 ) ;
return V_43 ;
}
return 0 ;
}
int
F_24 (
struct V_20 * V_21 ,
int V_44 ,
int V_45 ,
struct V_22 * * V_23 ,
T_7 V_46 ,
T_4 V_26 ,
T_4 V_47 )
{
struct log * log = V_21 -> V_27 ;
struct V_22 * V_48 ;
int V_49 = 0 ;
ASSERT ( V_46 == V_50 || V_46 == V_51 ) ;
if ( F_10 ( log ) )
return F_25 ( V_43 ) ;
F_26 ( V_52 ) ;
if ( * V_23 != NULL ) {
ASSERT ( V_26 & V_53 ) ;
V_48 = * V_23 ;
V_48 -> V_54 ++ ;
F_27 ( log , V_48 ) ;
F_28 ( log , V_48 -> V_55 ) ;
V_49 = F_29 ( log , V_48 ) ;
} else {
V_48 = F_30 ( log , V_44 , V_45 ,
V_46 , V_26 ,
V_56 | V_57 ) ;
if ( ! V_48 )
return F_25 ( V_58 ) ;
V_48 -> V_59 = V_47 ;
* V_23 = V_48 ;
F_27 ( log , V_48 ) ;
F_28 ( log ,
( V_48 -> V_55 *
V_48 -> V_60 ) ) ;
V_49 = F_31 ( log , V_48 ) ;
}
return V_49 ;
}
int
F_32 (
T_8 * V_21 ,
T_9 * V_61 ,
T_10 V_62 ,
int V_63 )
{
int error ;
if ( ! ( V_21 -> V_64 & V_65 ) )
F_33 ( V_21 , L_1 ) ;
else {
F_33 ( V_21 ,
L_2 ) ;
ASSERT ( V_21 -> V_64 & V_66 ) ;
}
V_21 -> V_27 = F_34 ( V_21 , V_61 , V_62 , V_63 ) ;
if ( F_35 ( V_21 -> V_27 ) ) {
error = - F_36 ( V_21 -> V_27 ) ;
goto V_67;
}
error = F_37 ( V_21 ) ;
if ( error ) {
F_38 ( V_21 , L_3 , error ) ;
goto V_68;
}
V_21 -> V_27 -> V_69 = V_21 -> V_70 ;
if ( ! ( V_21 -> V_64 & V_65 ) ) {
int V_71 = ( V_21 -> V_64 & V_66 ) ;
if ( V_71 )
V_21 -> V_64 &= ~ V_66 ;
error = F_39 ( V_21 -> V_27 ) ;
if ( V_71 )
V_21 -> V_64 |= V_66 ;
if ( error ) {
F_38 ( V_21 , L_4 ,
error ) ;
goto V_72;
}
}
V_21 -> V_27 -> V_73 &= ~ V_74 ;
F_40 ( V_21 -> V_27 ) ;
return 0 ;
V_72:
F_41 ( V_21 ) ;
V_68:
F_42 ( V_21 -> V_27 ) ;
V_67:
return error ;
}
int
F_43 ( T_8 * V_21 )
{
int error ;
if ( ! ( V_21 -> V_64 & V_65 ) )
error = F_44 ( V_21 -> V_27 ) ;
else {
error = 0 ;
ASSERT ( V_21 -> V_64 & V_66 ) ;
}
return error ;
}
int
F_45 ( T_8 * V_21 )
{
T_11 * log = V_21 -> V_27 ;
T_12 * V_25 ;
#ifdef F_46
T_12 * V_75 ;
#endif
T_3 * V_10 = NULL ;
T_5 V_28 ;
int error ;
if ( V_21 -> V_64 & V_66 )
return 0 ;
error = F_47 ( V_21 , V_76 , NULL ) ;
ASSERT ( error || ! ( F_10 ( log ) ) ) ;
#ifdef F_46
V_75 = V_25 = log -> V_77 ;
do {
if ( ! ( V_25 -> V_36 & V_37 ) ) {
ASSERT ( V_25 -> V_36 & V_38 ) ;
ASSERT ( V_25 -> V_78 == 0 ) ;
}
V_25 = V_25 -> V_79 ;
} while ( V_25 != V_75 );
#endif
if ( ! ( F_10 ( log ) ) ) {
error = F_24 ( V_21 , 600 , 1 , & V_10 ,
V_51 , 0 , V_80 ) ;
if ( ! error ) {
struct {
T_13 V_81 ;
T_13 V_82 ;
T_14 V_83 ;
} V_81 = {
. V_81 = V_84 ,
} ;
struct V_85 V_86 = {
. V_87 = & V_81 ,
. V_88 = sizeof( V_81 ) ,
. V_89 = V_90 ,
} ;
struct V_91 V_92 = {
. V_93 = 1 ,
. V_94 = & V_86 ,
} ;
V_10 -> V_29 = 0 ;
error = F_48 ( log , & V_92 , V_10 , & V_28 ,
NULL , V_95 ) ;
}
if ( error )
F_49 ( V_21 , L_5 , V_96 ) ;
F_18 ( & log -> V_97 ) ;
V_25 = log -> V_77 ;
F_50 ( & V_25 -> V_98 ) ;
F_51 ( log , V_25 ) ;
F_20 ( & log -> V_97 ) ;
error = F_22 ( log , V_25 ) ;
F_18 ( & log -> V_97 ) ;
if ( ! ( V_25 -> V_36 == V_38 ||
V_25 -> V_36 == V_99 ) ) {
if ( ! F_10 ( log ) ) {
F_52 ( & V_25 -> V_100 ,
& log -> V_97 ) ;
} else {
F_20 ( & log -> V_97 ) ;
}
} else {
F_20 ( & log -> V_97 ) ;
}
if ( V_10 ) {
F_53 ( log , V_10 ) ;
F_13 ( log , V_10 ) ;
F_14 ( V_10 ) ;
}
} else {
F_18 ( & log -> V_97 ) ;
V_25 = log -> V_77 ;
F_50 ( & V_25 -> V_98 ) ;
F_51 ( log , V_25 ) ;
F_20 ( & log -> V_97 ) ;
error = F_22 ( log , V_25 ) ;
F_18 ( & log -> V_97 ) ;
if ( ! ( V_25 -> V_36 == V_38
|| V_25 -> V_36 == V_99
|| V_25 -> V_36 == V_37 ) ) {
F_52 ( & V_25 -> V_100 ,
& log -> V_97 ) ;
} else {
F_20 ( & log -> V_97 ) ;
}
}
return error ;
}
void
F_54 ( T_8 * V_21 )
{
F_41 ( V_21 ) ;
F_42 ( V_21 -> V_27 ) ;
}
void
F_55 (
struct V_20 * V_21 ,
struct V_101 * V_102 ,
int type ,
struct V_103 * V_104 )
{
V_102 -> V_105 = V_21 ;
V_102 -> V_106 = V_21 -> V_70 ;
V_102 -> V_107 = type ;
V_102 -> V_108 = V_104 ;
V_102 -> V_109 = NULL ;
F_56 ( & V_102 -> V_110 ) ;
F_56 ( & V_102 -> V_111 ) ;
}
int
F_57 (
struct V_20 * V_21 ,
struct V_85 V_86 [] ,
int V_112 ,
struct V_22 * V_10 ,
T_5 * V_113 )
{
struct log * log = V_21 -> V_27 ;
int error ;
struct V_91 V_92 = {
. V_93 = V_112 ,
. V_94 = V_86 ,
} ;
if ( F_10 ( log ) )
return F_25 ( V_43 ) ;
error = F_48 ( log , & V_92 , V_10 , V_113 , NULL , 0 ) ;
if ( error )
F_23 ( V_21 , V_42 ) ;
return error ;
}
void
F_58 ( T_8 * V_21 ,
T_5 V_114 )
{
T_3 * V_10 ;
T_11 * log = V_21 -> V_27 ;
int V_115 , V_116 ;
if ( F_10 ( log ) )
return;
if ( V_114 == 0 )
V_114 = F_2 ( & log -> V_117 ) ;
if ( V_114 != 1 )
F_59 ( & log -> V_118 , V_114 ) ;
if ( ! F_60 ( & log -> V_119 ) ) {
#ifdef F_46
if ( log -> V_73 & V_74 )
F_61 ( L_6 ) ;
#endif
F_18 ( & log -> V_120 ) ;
V_116 = F_62 ( log , & log -> V_121 ) ;
F_63 (tic, &log->l_writeq, t_queue) {
ASSERT ( V_10 -> V_29 & V_31 ) ;
if ( V_116 < V_10 -> V_55 && V_114 != 1 )
break;
V_114 = 0 ;
V_116 -= V_10 -> V_55 ;
F_64 ( log , V_10 ) ;
F_65 ( & V_10 -> V_122 ) ;
}
F_20 ( & log -> V_120 ) ;
}
if ( ! F_60 ( & log -> V_123 ) ) {
#ifdef F_46
if ( log -> V_73 & V_74 )
F_61 ( L_6 ) ;
#endif
F_18 ( & log -> V_124 ) ;
V_116 = F_62 ( log , & log -> V_125 ) ;
F_63 (tic, &log->l_reserveq, t_queue) {
if ( V_10 -> V_29 & V_31 )
V_115 = V_10 -> V_55 * V_10 -> V_60 ;
else
V_115 = V_10 -> V_55 ;
if ( V_116 < V_115 && V_114 != 1 )
break;
V_114 = 0 ;
V_116 -= V_115 ;
F_66 ( log , V_10 ) ;
F_65 ( & V_10 -> V_122 ) ;
}
F_20 ( & log -> V_124 ) ;
}
}
int
F_67 ( T_8 * V_21 )
{
int V_126 = 0 ;
T_11 * log = V_21 -> V_27 ;
if ( ! F_68 ( V_21 ) )
return 0 ;
F_18 ( & log -> V_97 ) ;
switch ( log -> V_127 ) {
case V_128 :
case V_129 :
case V_130 :
break;
case V_131 :
case V_132 :
if ( ! F_69 ( log -> V_69 ) &&
F_70 ( log ) ) {
if ( log -> V_127 == V_131 )
log -> V_127 = V_128 ;
else
log -> V_127 = V_129 ;
}
default:
V_126 = 1 ;
break;
}
F_20 ( & log -> V_97 ) ;
return V_126 ;
}
T_5
F_71 (
struct V_20 * V_21 )
{
T_5 V_114 ;
struct log * log = V_21 -> V_27 ;
V_114 = F_69 ( V_21 -> V_70 ) ;
if ( ! V_114 )
V_114 = F_2 ( & log -> V_117 ) ;
F_59 ( & log -> V_118 , V_114 ) ;
return V_114 ;
}
STATIC int
F_62 (
struct log * log ,
T_1 * V_1 )
{
int V_116 ;
int V_133 ;
int V_134 ;
int V_135 ;
int V_136 ;
F_72 ( V_1 , & V_135 , & V_136 ) ;
F_73 ( & log -> V_118 , & V_134 , & V_133 ) ;
V_133 = F_74 ( V_133 ) ;
if ( V_134 == V_135 && V_136 >= V_133 )
V_116 = log -> V_8 - ( V_136 - V_133 ) ;
else if ( V_134 + 1 < V_135 )
return 0 ;
else if ( V_134 < V_135 ) {
ASSERT ( V_134 == ( V_135 - 1 ) ) ;
V_116 = V_133 - V_136 ;
} else {
F_49 ( log -> V_137 ,
L_7
L_8
L_9 ,
V_134 , V_133 , V_135 , V_136 ) ;
ASSERT ( 0 ) ;
V_116 = log -> V_8 ;
}
return V_116 ;
}
void
F_75 ( T_15 * V_138 )
{
T_12 * V_25 ;
T_11 * V_139 ;
int V_140 ;
V_25 = F_76 ( V_138 , T_12 * ) ;
ASSERT ( F_77 (bp, unsigned long) == ( unsigned long ) 2 ) ;
F_78 ( V_138 , ( unsigned long ) 1 ) ;
V_140 = 0 ;
V_139 = V_25 -> V_141 ;
if ( F_79 ( ( F_80 ( V_138 ) ) , V_139 -> V_137 ,
V_142 , V_143 ) ) {
F_81 ( L_10 , V_139 -> V_137 , V_138 , F_82 ( V_138 ) ) ;
F_83 ( V_138 ) ;
F_23 ( V_139 -> V_137 , V_42 ) ;
V_140 = V_144 ;
} else if ( V_25 -> V_36 & V_37 ) {
V_140 = V_144 ;
}
ASSERT ( F_84 ( V_138 ) ) ;
F_85 ( V_25 , V_140 ) ;
}
STATIC void
F_86 ( T_8 * V_21 ,
T_11 * log )
{
int V_145 ;
int V_146 ;
if ( V_21 -> V_147 <= 0 )
log -> V_148 = V_149 ;
else
log -> V_148 = V_21 -> V_147 ;
if ( V_21 -> V_150 > 0 ) {
V_145 = log -> V_151 = V_21 -> V_150 ;
log -> V_152 = 0 ;
while ( V_145 != 1 ) {
log -> V_152 ++ ;
V_145 >>= 1 ;
}
if ( F_87 ( & V_21 -> V_153 ) ) {
V_146 = V_21 -> V_150 / V_154 ;
if ( V_21 -> V_150 % V_154 )
V_146 ++ ;
log -> V_155 = V_146 << V_156 ;
log -> V_157 = V_146 ;
} else {
ASSERT ( V_21 -> V_150 <= V_158 ) ;
log -> V_155 = V_159 ;
log -> V_157 = 1 ;
}
goto V_160;
}
log -> V_151 = V_158 ;
log -> V_152 = V_161 ;
log -> V_155 = V_159 ;
log -> V_157 = 1 ;
V_160:
if ( V_21 -> V_147 == 0 )
V_21 -> V_147 = log -> V_148 ;
if ( V_21 -> V_150 == 0 )
V_21 -> V_150 = log -> V_151 ;
}
STATIC T_11 *
F_34 ( T_8 * V_21 ,
T_9 * V_61 ,
T_10 V_62 ,
int V_63 )
{
T_11 * log ;
T_16 * V_1 ;
T_12 * * V_162 ;
T_12 * V_25 , * V_163 = NULL ;
T_15 * V_138 ;
int V_164 ;
int error = V_58 ;
T_4 V_165 = 0 ;
log = F_88 ( sizeof( T_11 ) , V_57 ) ;
if ( ! log ) {
F_38 ( V_21 , L_11 ) ;
goto V_67;
}
log -> V_137 = V_21 ;
log -> V_166 = V_61 ;
log -> V_8 = F_74 ( V_63 ) ;
log -> V_167 = V_62 ;
log -> V_168 = V_63 ;
log -> V_127 = V_130 ;
log -> V_73 |= V_74 ;
log -> V_169 = - 1 ;
F_89 ( & log -> V_118 , 1 , 0 ) ;
F_89 ( & log -> V_117 , 1 , 0 ) ;
log -> V_170 = 1 ;
F_90 ( & log -> V_125 , 1 , 0 ) ;
F_90 ( & log -> V_121 , 1 , 0 ) ;
F_56 ( & log -> V_123 ) ;
F_56 ( & log -> V_119 ) ;
F_91 ( & log -> V_124 ) ;
F_91 ( & log -> V_120 ) ;
error = V_171 ;
if ( F_92 ( & V_21 -> V_153 ) ) {
V_165 = V_21 -> V_153 . V_172 ;
if ( V_165 < V_156 ) {
F_38 ( V_21 , L_12 ,
V_165 , V_156 ) ;
goto V_68;
}
V_165 -= V_156 ;
if ( V_165 > V_21 -> V_173 ) {
F_38 ( V_21 , L_13 ,
V_165 , V_21 -> V_173 ) ;
goto V_68;
}
if ( V_165 && log -> V_167 > 0 &&
! F_87 ( & V_21 -> V_153 ) ) {
F_38 ( V_21 ,
L_14 ,
V_165 ) ;
goto V_68;
}
}
log -> V_174 = 1 << V_165 ;
F_86 ( V_21 , log ) ;
error = V_58 ;
V_138 = F_93 ( log -> V_151 , V_21 -> V_175 ) ;
if ( ! V_138 )
goto V_68;
F_94 ( V_138 , F_75 ) ;
F_78 ( V_138 , ( unsigned long ) 1 ) ;
ASSERT ( F_95 ( V_138 ) ) ;
ASSERT ( F_96 ( V_138 ) <= 0 ) ;
log -> V_176 = V_138 ;
F_91 ( & log -> V_97 ) ;
F_97 ( & log -> V_177 ) ;
ASSERT ( ( F_98 ( V_138 ) & V_178 ) == 0 ) ;
V_162 = & log -> V_77 ;
ASSERT ( log -> V_151 >= 4096 ) ;
for ( V_164 = 0 ; V_164 < log -> V_148 ; V_164 ++ ) {
* V_162 = F_88 ( sizeof( T_12 ) , V_57 ) ;
if ( ! * V_162 )
goto V_179;
V_25 = * V_162 ;
V_25 -> V_180 = V_163 ;
V_163 = V_25 ;
V_138 = F_99 ( V_21 -> V_175 ,
log -> V_151 , 0 ) ;
if ( ! V_138 )
goto V_179;
if ( ! F_100 ( V_138 ) )
ASSERT ( 0 ) ;
F_94 ( V_138 , F_75 ) ;
F_78 ( V_138 , ( unsigned long ) 1 ) ;
V_25 -> V_181 = V_138 ;
V_25 -> V_182 = V_138 -> V_183 ;
#ifdef F_46
log -> V_184 [ V_164 ] = ( V_185 ) & ( V_25 -> V_186 ) ;
#endif
V_1 = & V_25 -> V_186 ;
memset ( V_1 , 0 , sizeof( T_16 ) ) ;
V_1 -> V_187 = F_101 ( V_188 ) ;
V_1 -> V_189 = F_101 (
F_87 ( & log -> V_137 -> V_153 ) ? 2 : 1 ) ;
V_1 -> V_190 = F_101 ( log -> V_151 ) ;
V_1 -> V_191 = F_101 ( V_192 ) ;
memcpy ( & V_1 -> V_193 , & V_21 -> V_153 . V_194 , sizeof( V_195 ) ) ;
V_25 -> V_196 = F_98 ( V_138 ) - log -> V_155 ;
V_25 -> V_36 = V_38 ;
V_25 -> V_141 = log ;
F_102 ( & V_25 -> V_98 , 0 ) ;
F_91 ( & V_25 -> V_35 ) ;
V_25 -> V_41 = & ( V_25 -> V_197 ) ;
V_25 -> V_198 = ( char * ) V_25 -> V_182 + log -> V_155 ;
ASSERT ( F_95 ( V_25 -> V_181 ) ) ;
ASSERT ( F_96 ( V_25 -> V_181 ) <= 0 ) ;
F_97 ( & V_25 -> V_100 ) ;
F_97 ( & V_25 -> V_199 ) ;
V_162 = & V_25 -> V_79 ;
}
* V_162 = log -> V_77 ;
log -> V_77 -> V_180 = V_163 ;
error = F_103 ( log ) ;
if ( error )
goto V_179;
return log ;
V_179:
for ( V_25 = log -> V_77 ; V_25 ; V_25 = V_163 ) {
V_163 = V_25 -> V_79 ;
if ( V_25 -> V_181 )
F_104 ( V_25 -> V_181 ) ;
F_105 ( V_25 ) ;
}
F_106 ( & log -> V_97 ) ;
F_104 ( log -> V_176 ) ;
V_68:
F_105 ( log ) ;
V_67:
return F_107 ( - error ) ;
}
STATIC int
F_11 (
struct log * log ,
struct V_22 * V_23 ,
struct V_24 * * V_25 ,
T_5 * V_200 )
{
struct V_20 * V_21 = log -> V_137 ;
int error ;
struct V_85 V_86 = {
. V_87 = NULL ,
. V_88 = 0 ,
. V_89 = V_201 ,
} ;
struct V_91 V_92 = {
. V_93 = 1 ,
. V_94 = & V_86 ,
} ;
F_19 ( V_25 ) ;
error = F_48 ( log , & V_92 , V_23 , V_200 , V_25 ,
V_202 ) ;
if ( error )
F_23 ( V_21 , V_42 ) ;
return error ;
}
STATIC void
F_28 (
struct log * log ,
int V_115 )
{
T_5 V_203 = 0 ;
T_5 V_204 ;
int V_205 ;
int V_116 ;
int V_206 ;
int V_207 ;
int V_208 ;
ASSERT ( F_108 ( V_115 ) < log -> V_168 ) ;
V_116 = F_62 ( log , & log -> V_125 ) ;
V_205 = F_109 ( V_116 ) ;
V_208 = F_108 ( V_115 ) ;
V_208 = F_110 ( V_208 , ( log -> V_168 >> 2 ) ) ;
V_208 = F_110 ( V_208 , 256 ) ;
if ( V_205 >= V_208 )
return;
F_73 ( & log -> V_118 , & V_207 ,
& V_206 ) ;
V_206 += V_208 ;
if ( V_206 >= log -> V_168 ) {
V_206 -= log -> V_168 ;
V_207 += 1 ;
}
V_203 = F_111 ( V_207 ,
V_206 ) ;
V_204 = F_2 ( & log -> V_117 ) ;
if ( F_112 ( V_203 , V_204 ) > 0 )
V_203 = V_204 ;
if ( ! F_10 ( log ) )
F_113 ( log -> V_69 , V_203 ) ;
}
STATIC int
F_114 (
struct V_209 * V_138 )
{
struct V_24 * V_25 ;
V_25 = F_76 ( V_138 , T_12 * ) ;
if ( V_25 -> V_36 & V_37 ) {
F_115 ( V_138 , V_43 ) ;
F_83 ( V_138 ) ;
F_116 ( V_138 , 0 ) ;
return 0 ;
}
V_138 -> V_210 |= V_211 ;
F_117 ( V_138 ) ;
return 0 ;
}
STATIC int
F_118 ( T_11 * log ,
T_12 * V_25 )
{
V_185 V_212 ;
T_15 * V_138 ;
int V_164 ;
T_4 V_213 ;
T_4 V_214 ;
int V_215 ;
int V_216 = 0 ;
int error ;
int V_217 = F_87 ( & log -> V_137 -> V_153 ) ;
F_26 ( V_218 ) ;
ASSERT ( F_119 ( & V_25 -> V_98 ) == 0 ) ;
V_214 = log -> V_155 + V_25 -> V_78 ;
if ( V_217 && log -> V_137 -> V_153 . V_219 > 1 ) {
V_213 = F_120 ( log , F_121 ( log , V_214 ) ) ;
} else {
V_213 = F_74 ( F_108 ( V_214 ) ) ;
}
V_215 = V_213 - V_214 ;
ASSERT ( V_215 >= 0 ) ;
ASSERT ( ( V_217 && log -> V_137 -> V_153 . V_219 > 1 &&
V_215 < log -> V_137 -> V_153 . V_219 )
||
( log -> V_137 -> V_153 . V_219 <= 1 &&
V_215 < F_74 ( 1 ) ) ) ;
F_6 ( log , & log -> V_125 , V_215 ) ;
F_6 ( log , & log -> V_121 , V_215 ) ;
F_122 ( log , V_25 , V_215 ) ;
if ( V_217 ) {
V_25 -> V_186 . V_220 =
F_101 ( V_25 -> V_78 + V_215 ) ;
} else {
V_25 -> V_186 . V_220 =
F_101 ( V_25 -> V_78 ) ;
}
V_138 = V_25 -> V_181 ;
ASSERT ( F_77 (bp, unsigned long) == ( unsigned long ) 1 ) ;
F_78 ( V_138 , ( unsigned long ) 2 ) ;
F_123 ( V_138 , F_124 ( F_125 ( V_25 -> V_186 . V_221 ) ) ) ;
F_126 ( V_222 , F_108 ( V_213 ) ) ;
if ( F_82 ( V_138 ) + F_108 ( V_213 ) > log -> V_168 ) {
V_216 = V_213 - ( F_74 ( log -> V_168 - F_82 ( V_138 ) ) ) ;
V_213 = F_74 ( log -> V_168 - F_82 ( V_138 ) ) ;
V_25 -> V_223 = 2 ;
} else {
V_25 -> V_223 = 1 ;
}
F_127 ( V_138 , V_213 ) ;
F_128 ( V_138 , V_25 ) ;
F_129 ( V_138 ) ;
F_130 ( V_138 ) ;
F_131 ( V_138 ) ;
V_138 -> V_210 |= V_224 ;
if ( log -> V_137 -> V_64 & V_225 ) {
if ( log -> V_137 -> V_175 != log -> V_137 -> V_226 )
F_132 ( log -> V_137 -> V_226 ) ;
F_133 ( V_138 ) ;
}
ASSERT ( F_82 ( V_138 ) <= log -> V_168 - 1 ) ;
ASSERT ( F_82 ( V_138 ) + F_108 ( V_213 ) <= log -> V_168 ) ;
F_134 ( log , V_25 , V_213 , V_227 ) ;
F_123 ( V_138 , F_82 ( V_138 ) + log -> V_167 ) ;
F_135 ( V_138 ) ;
if ( ( error = F_114 ( V_138 ) ) ) {
F_81 ( L_15 , log -> V_137 , V_138 ,
F_82 ( V_138 ) ) ;
return error ;
}
if ( V_216 ) {
V_138 = V_25 -> V_141 -> V_176 ;
ASSERT ( F_77 (bp, unsigned long) ==
( unsigned long ) 1 ) ;
F_78 ( V_138 , ( unsigned long ) 2 ) ;
F_123 ( V_138 , 0 ) ;
F_136 ( V_138 , ( V_185 ) ( ( V_228 ) & ( V_25 -> V_186 ) +
( V_228 ) V_213 ) , V_216 ) ;
F_128 ( V_138 , V_25 ) ;
F_129 ( V_138 ) ;
F_130 ( V_138 ) ;
F_131 ( V_138 ) ;
V_138 -> V_210 |= V_224 ;
if ( log -> V_137 -> V_64 & V_225 )
F_133 ( V_138 ) ;
V_212 = F_137 ( V_138 ) ;
for ( V_164 = 0 ; V_164 < V_216 ; V_164 += V_159 ) {
F_138 ( ( V_229 * ) V_212 , 1 ) ;
if ( F_139 ( * ( V_229 * ) V_212 ) == V_188 )
F_138 ( ( V_229 * ) V_212 , 1 ) ;
V_212 += V_159 ;
}
ASSERT ( F_82 ( V_138 ) <= log -> V_168 - 1 ) ;
ASSERT ( F_82 ( V_138 ) + F_108 ( V_213 ) <= log -> V_168 ) ;
F_123 ( V_138 , F_82 ( V_138 ) + log -> V_167 ) ;
F_135 ( V_138 ) ;
if ( ( error = F_114 ( V_138 ) ) ) {
F_81 ( L_16 , log -> V_137 ,
V_138 , F_82 ( V_138 ) ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_42 ( T_11 * log )
{
T_12 * V_25 , * V_230 ;
int V_164 ;
F_140 ( log ) ;
F_141 ( log -> V_176 , log -> V_151 ) ;
F_104 ( log -> V_176 ) ;
V_25 = log -> V_77 ;
for ( V_164 = 0 ; V_164 < log -> V_148 ; V_164 ++ ) {
F_104 ( V_25 -> V_181 ) ;
V_230 = V_25 -> V_79 ;
F_105 ( V_25 ) ;
V_25 = V_230 ;
}
F_106 ( & log -> V_97 ) ;
log -> V_137 -> V_27 = NULL ;
F_105 ( log ) ;
}
static inline void
F_142 ( T_11 * log ,
T_12 * V_25 ,
int V_231 ,
int V_232 )
{
F_18 ( & log -> V_97 ) ;
F_138 ( & V_25 -> V_186 . V_233 , V_231 ) ;
V_25 -> V_78 += V_232 ;
F_20 ( & log -> V_97 ) ;
}
void
F_143 (
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
T_4 V_164 ;
T_4 V_234 = V_23 -> V_13 * ( T_4 ) sizeof( V_235 ) ;
static char * V_236 [ V_237 ] = {
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
L_34 ,
L_35
} ;
static char * V_238 [ V_239 ] = {
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
L_74 ,
L_75
} ;
F_38 ( V_21 ,
L_76
L_77
L_78
L_79
L_80
L_81
L_82
L_83 ,
( ( V_23 -> V_59 <= 0 ||
V_23 -> V_59 > V_239 ) ?
L_84 : V_238 [ V_23 -> V_59 - 1 ] ) ,
V_23 -> V_59 ,
V_23 -> V_55 ,
V_23 -> V_240 ,
V_23 -> V_12 , V_23 -> V_16 ,
V_23 -> V_13 , V_234 ,
V_23 -> V_12 +
V_23 -> V_16 + V_234 ,
V_23 -> V_11 ) ;
for ( V_164 = 0 ; V_164 < V_23 -> V_11 ; V_164 ++ ) {
T_4 V_19 = V_23 -> V_17 [ V_164 ] . V_19 ;
F_38 ( V_21 , L_85 , V_164 ,
( ( V_19 <= 0 || V_19 > V_237 ) ?
L_86 : V_236 [ V_19 - 1 ] ) ,
V_23 -> V_17 [ V_164 ] . V_18 ) ;
}
F_144 ( V_21 , V_241 ,
L_87 ) ;
F_23 ( V_21 , V_242 ) ;
}
static int
F_145 (
struct V_22 * V_23 ,
struct V_91 * V_243 )
{
struct V_91 * V_244 ;
int V_245 = 0 ;
int V_14 = 0 ;
int V_164 ;
if ( V_23 -> V_29 & V_30 )
V_245 ++ ;
for ( V_244 = V_243 ; V_244 ; V_244 = V_244 -> V_246 ) {
V_245 += V_244 -> V_93 ;
for ( V_164 = 0 ; V_164 < V_244 -> V_93 ; V_164 ++ ) {
struct V_85 * V_247 = & V_244 -> V_94 [ V_164 ] ;
V_14 += V_247 -> V_88 ;
F_8 ( V_23 , V_247 -> V_88 , V_247 -> V_89 ) ;
}
}
V_23 -> V_13 += V_245 ;
V_14 += V_245 * sizeof( struct V_248 ) ;
return V_14 ;
}
static int
F_146 (
struct V_248 * V_249 ,
struct V_22 * V_23 )
{
if ( ! ( V_23 -> V_29 & V_30 ) )
return 0 ;
V_249 -> V_250 = F_101 ( V_23 -> V_54 ) ;
V_249 -> V_251 = V_23 -> V_252 ;
V_249 -> V_253 = 0 ;
V_249 -> V_254 = V_255 ;
V_249 -> V_256 = 0 ;
V_23 -> V_29 &= ~ V_30 ;
return sizeof( struct V_248 ) ;
}
static V_235 *
F_147 (
struct log * log ,
struct V_248 * V_249 ,
struct V_22 * V_23 ,
T_4 V_26 )
{
V_249 -> V_250 = F_101 ( V_23 -> V_54 ) ;
V_249 -> V_251 = V_23 -> V_252 ;
V_249 -> V_256 = 0 ;
V_249 -> V_254 = V_26 ;
switch ( V_249 -> V_251 ) {
case V_50 :
case V_257 :
case V_51 :
break;
default:
F_38 ( log -> V_137 ,
L_88 ,
V_249 -> V_251 , V_23 ) ;
return NULL ;
}
return V_249 ;
}
static int
F_148 (
struct V_22 * V_23 ,
struct V_248 * V_249 ,
int V_258 ,
int V_259 ,
int * V_260 ,
int * V_261 ,
int * V_262 ,
int * V_263 )
{
int V_264 ;
V_264 = V_259 - * V_263 ;
* V_260 = * V_263 ;
if ( V_264 <= V_258 ) {
* V_261 = V_264 ;
V_249 -> V_253 = F_101 ( * V_261 ) ;
if ( * V_262 )
V_249 -> V_254 |= ( V_265 | V_266 ) ;
* V_262 = 0 ;
* V_263 = 0 ;
return 0 ;
}
* V_261 = V_258 ;
V_249 -> V_253 = F_101 ( * V_261 ) ;
V_249 -> V_254 |= V_267 ;
if ( * V_262 )
V_249 -> V_254 |= V_266 ;
* V_263 += * V_261 ;
( * V_262 ) ++ ;
V_23 -> V_240 -= sizeof( struct V_248 ) ;
V_23 -> V_13 ++ ;
return sizeof( struct V_248 ) ;
}
static int
F_149 (
struct log * log ,
struct V_24 * V_25 ,
T_4 V_26 ,
int * V_231 ,
int * V_268 ,
int * V_269 ,
int * V_270 ,
int V_271 ,
struct V_24 * * V_272 )
{
if ( * V_269 ) {
F_142 ( log , V_25 , * V_231 , * V_268 ) ;
* V_231 = 0 ;
* V_268 = 0 ;
return F_22 ( log , V_25 ) ;
}
* V_269 = 0 ;
* V_270 = 0 ;
if ( V_25 -> V_196 - V_271 <= sizeof( V_235 ) ) {
F_142 ( log , V_25 , * V_231 , * V_268 ) ;
* V_231 = 0 ;
* V_268 = 0 ;
F_18 ( & log -> V_97 ) ;
F_51 ( log , V_25 ) ;
F_20 ( & log -> V_97 ) ;
if ( ! V_272 )
return F_22 ( log , V_25 ) ;
ASSERT ( V_26 & V_202 ) ;
* V_272 = V_25 ;
}
return 0 ;
}
int
F_48 (
struct log * log ,
struct V_91 * V_243 ,
struct V_22 * V_23 ,
T_5 * V_113 ,
struct V_24 * * V_272 ,
T_4 V_26 )
{
struct V_24 * V_25 = NULL ;
struct V_85 * V_247 ;
struct V_91 * V_244 ;
int V_14 ;
int V_273 ;
int V_269 = 0 ;
int V_270 = 0 ;
int V_274 = 0 ;
int V_231 = 0 ;
int V_268 = 0 ;
int error ;
* V_113 = 0 ;
V_14 = F_145 ( V_23 , V_243 ) ;
if ( log -> V_275 ) {
if ( V_23 -> V_29 & V_30 )
V_23 -> V_240 -= sizeof( V_235 ) ;
if ( V_26 & ( V_202 | V_95 ) )
V_23 -> V_240 -= sizeof( V_235 ) ;
} else
V_23 -> V_240 -= V_14 ;
if ( V_23 -> V_240 < 0 )
F_143 ( log -> V_137 , V_23 ) ;
V_273 = 0 ;
V_244 = V_243 ;
V_247 = V_244 -> V_94 ;
while ( V_244 && V_273 < V_244 -> V_93 ) {
void * V_276 ;
int V_271 ;
error = F_150 ( log , V_14 , & V_25 , V_23 ,
& V_274 , & V_271 ) ;
if ( error )
return error ;
ASSERT ( V_271 <= V_25 -> V_196 - 1 ) ;
V_276 = V_25 -> V_198 + V_271 ;
if ( ! * V_113 )
* V_113 = F_125 ( V_25 -> V_186 . V_221 ) ;
while ( V_244 && V_273 < V_244 -> V_93 ) {
struct V_85 * V_86 = & V_247 [ V_273 ] ;
struct V_248 * V_249 ;
int V_277 ;
int V_261 ;
int V_260 ;
ASSERT ( V_86 -> V_88 % sizeof( V_278 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_276 % sizeof( V_278 ) == 0 ) ;
V_277 = F_146 ( V_276 , V_23 ) ;
if ( V_277 ) {
V_231 ++ ;
F_151 ( & V_276 , & V_14 , & V_271 ,
V_277 ) ;
}
V_249 = F_147 ( log , V_276 , V_23 , V_26 ) ;
if ( ! V_249 )
return F_25 ( V_43 ) ;
F_151 ( & V_276 , & V_14 , & V_271 ,
sizeof( struct V_248 ) ) ;
V_14 += F_148 ( V_23 , V_249 ,
V_25 -> V_196 - V_271 ,
V_86 -> V_88 ,
& V_260 , & V_261 ,
& V_269 ,
& V_270 ) ;
F_152 ( log , V_276 ) ;
ASSERT ( V_261 >= 0 ) ;
memcpy ( V_276 , V_86 -> V_87 + V_260 , V_261 ) ;
F_151 ( & V_276 , & V_14 , & V_271 , V_261 ) ;
V_261 += V_277 + sizeof( V_235 ) ;
V_231 ++ ;
V_268 += V_274 ? V_261 : 0 ;
error = F_149 ( log , V_25 , V_26 ,
& V_231 , & V_268 ,
& V_269 ,
& V_270 ,
V_271 ,
V_272 ) ;
if ( error )
return error ;
if ( V_269 )
break;
if ( ++ V_273 == V_244 -> V_93 ) {
V_244 = V_244 -> V_246 ;
V_273 = 0 ;
if ( V_244 )
V_247 = V_244 -> V_94 ;
}
if ( V_231 == 0 ) {
if ( ! V_244 )
return 0 ;
break;
}
}
}
ASSERT ( V_14 == 0 ) ;
F_142 ( log , V_25 , V_231 , V_268 ) ;
if ( ! V_272 )
return F_22 ( log , V_25 ) ;
ASSERT ( V_26 & V_202 ) ;
* V_272 = V_25 ;
return 0 ;
}
STATIC void
F_153 ( T_11 * log )
{
T_12 * V_25 ;
int V_279 = 0 ;
V_25 = log -> V_77 ;
do {
if ( V_25 -> V_36 == V_99 ) {
V_25 -> V_36 = V_38 ;
V_25 -> V_78 = 0 ;
ASSERT ( V_25 -> V_197 == NULL ) ;
if ( ! V_279 &&
( F_139 ( V_25 -> V_186 . V_233 ) ==
V_280 ) ) {
V_279 = 1 ;
} else {
V_279 = 2 ;
}
V_25 -> V_186 . V_233 = 0 ;
memset ( V_25 -> V_186 . V_281 , 0 ,
sizeof( V_25 -> V_186 . V_281 ) ) ;
V_25 -> V_186 . V_221 = 0 ;
} else if ( V_25 -> V_36 == V_38 )
;
else
break;
V_25 = V_25 -> V_79 ;
} while ( V_25 != log -> V_77 );
if ( V_279 ) {
switch ( log -> V_127 ) {
case V_130 :
case V_131 :
case V_132 :
log -> V_127 = V_131 ;
break;
case V_128 :
if ( V_279 == 1 )
log -> V_127 = V_132 ;
else
log -> V_127 = V_131 ;
break;
case V_129 :
if ( V_279 == 1 )
log -> V_127 = V_130 ;
else
log -> V_127 = V_131 ;
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
T_12 * V_282 ;
T_5 V_283 , V_28 ;
V_282 = log -> V_77 ;
V_283 = 0 ;
do {
if ( ! ( V_282 -> V_36 & ( V_38 | V_99 ) ) ) {
V_28 = F_125 ( V_282 -> V_186 . V_221 ) ;
if ( ( V_28 && ! V_283 ) ||
( F_112 ( V_28 , V_283 ) < 0 ) ) {
V_283 = V_28 ;
}
}
V_282 = V_282 -> V_79 ;
} while ( V_282 != log -> V_77 );
return V_283 ;
}
STATIC void
F_155 (
T_11 * log ,
int V_140 ,
T_12 * V_284 )
{
T_12 * V_25 ;
T_12 * V_75 ;
T_6 * V_33 , * V_40 ;
int V_285 = 0 ;
T_5 V_283 ;
int V_286 ;
int V_287 ;
int V_288 ;
int V_289 ;
int V_290 = 0 ;
F_18 ( & log -> V_97 ) ;
V_75 = V_25 = log -> V_77 ;
V_286 = 0 ;
V_288 = 0 ;
V_289 = 0 ;
do {
V_75 = log -> V_77 ;
V_25 = log -> V_77 ;
V_287 = 0 ;
V_289 ++ ;
do {
if ( V_25 -> V_36 &
( V_38 | V_99 ) ) {
V_25 = V_25 -> V_79 ;
continue;
}
if ( ! ( V_25 -> V_36 & V_37 ) ) {
if ( ! ( V_25 -> V_36 &
( V_291 |
V_292 ) ) ) {
if ( V_284 && ( V_284 -> V_36 ==
V_291 ) ) {
V_284 -> V_36 = V_292 ;
}
break;
}
V_283 = F_154 ( log ) ;
if ( V_283 &&
F_112 ( V_283 ,
F_125 ( V_25 -> V_186 . V_221 ) ) < 0 ) {
V_25 = V_25 -> V_79 ;
continue;
}
V_25 -> V_36 = V_293 ;
ASSERT ( F_112 ( F_2 ( & log -> V_117 ) ,
F_125 ( V_25 -> V_186 . V_221 ) ) <= 0 ) ;
F_59 ( & log -> V_117 ,
F_125 ( V_25 -> V_186 . V_221 ) ) ;
} else
V_286 ++ ;
F_20 ( & log -> V_97 ) ;
F_18 ( & V_25 -> V_35 ) ;
V_33 = V_25 -> V_197 ;
while ( V_33 ) {
V_25 -> V_41 = & ( V_25 -> V_197 ) ;
V_25 -> V_197 = NULL ;
F_20 ( & V_25 -> V_35 ) ;
for (; V_33 ; V_33 = V_40 ) {
V_40 = V_33 -> V_40 ;
V_33 -> V_294 ( V_33 -> V_295 , V_140 ) ;
}
F_18 ( & V_25 -> V_35 ) ;
V_33 = V_25 -> V_197 ;
}
V_287 ++ ;
V_288 ++ ;
F_18 ( & log -> V_97 ) ;
ASSERT ( V_25 -> V_197 == NULL ) ;
F_20 ( & V_25 -> V_35 ) ;
if ( ! ( V_25 -> V_36 & V_37 ) )
V_25 -> V_36 = V_99 ;
F_153 ( log ) ;
F_156 ( & V_25 -> V_100 ) ;
V_25 = V_25 -> V_79 ;
} while ( V_75 != V_25 );
if ( V_289 > 5000 ) {
V_285 += V_289 ;
V_289 = 0 ;
F_38 ( log -> V_137 ,
L_89 ,
V_96 , V_285 ) ;
}
} while ( ! V_286 && V_287 );
#ifdef F_46
if ( V_288 ) {
V_75 = V_25 = log -> V_77 ;
do {
ASSERT ( V_25 -> V_36 != V_292 ) ;
if ( V_25 -> V_36 == V_39 ||
V_25 -> V_36 == V_296 ||
V_25 -> V_36 == V_291 ||
V_25 -> V_36 == V_37 )
break;
V_25 = V_25 -> V_79 ;
} while ( V_75 != V_25 );
}
#endif
if ( log -> V_77 -> V_36 & ( V_38 | V_37 ) )
V_290 = 1 ;
F_20 ( & log -> V_97 ) ;
if ( V_290 )
F_156 ( & log -> V_177 ) ;
}
STATIC void
F_85 (
T_12 * V_25 ,
int V_140 )
{
T_11 * log = V_25 -> V_141 ;
F_18 ( & log -> V_97 ) ;
ASSERT ( V_25 -> V_36 == V_296 ||
V_25 -> V_36 == V_37 ) ;
ASSERT ( F_119 ( & V_25 -> V_98 ) == 0 ) ;
ASSERT ( V_25 -> V_223 == 1 || V_25 -> V_223 == 2 ) ;
if ( V_25 -> V_36 != V_37 ) {
if ( -- V_25 -> V_223 == 1 ) {
F_20 ( & log -> V_97 ) ;
return;
}
V_25 -> V_36 = V_291 ;
}
F_156 ( & V_25 -> V_199 ) ;
F_20 ( & log -> V_97 ) ;
F_155 ( log , V_140 , V_25 ) ;
}
STATIC int
F_150 ( T_11 * log ,
int V_14 ,
T_12 * * V_162 ,
T_3 * V_23 ,
int * V_297 ,
int * V_298 )
{
int V_271 ;
T_16 * V_1 ;
T_12 * V_25 ;
int error ;
V_299:
F_18 ( & log -> V_97 ) ;
if ( F_10 ( log ) ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
V_25 = log -> V_77 ;
if ( V_25 -> V_36 != V_38 ) {
F_26 ( V_300 ) ;
F_52 ( & log -> V_177 , & log -> V_97 ) ;
goto V_299;
}
V_1 = & V_25 -> V_186 ;
F_50 ( & V_25 -> V_98 ) ;
V_271 = V_25 -> V_78 ;
if ( V_271 == 0 ) {
V_23 -> V_240 -= log -> V_155 ;
F_8 ( V_23 ,
log -> V_155 ,
V_301 ) ;
V_1 -> V_302 = F_101 ( log -> V_170 ) ;
V_1 -> V_221 = F_157 (
F_111 ( log -> V_170 , log -> V_303 ) ) ;
ASSERT ( log -> V_303 >= 0 ) ;
}
if ( V_25 -> V_196 - V_25 -> V_78 < 2 * sizeof( V_235 ) ) {
F_158 ( log , V_25 , V_25 -> V_196 ) ;
if ( ! F_159 ( & V_25 -> V_98 , - 1 , 1 ) ) {
F_20 ( & log -> V_97 ) ;
error = F_22 ( log , V_25 ) ;
if ( error )
return error ;
} else {
F_20 ( & log -> V_97 ) ;
}
goto V_299;
}
if ( V_14 <= V_25 -> V_196 - V_25 -> V_78 ) {
* V_297 = 0 ;
V_25 -> V_78 += V_14 ;
} else {
* V_297 = 1 ;
F_158 ( log , V_25 , V_25 -> V_196 ) ;
}
* V_162 = V_25 ;
ASSERT ( V_25 -> V_78 <= V_25 -> V_196 ) ;
F_20 ( & log -> V_97 ) ;
* V_298 = V_271 ;
return 0 ;
}
STATIC int
F_31 ( T_11 * log ,
T_3 * V_10 )
{
int V_116 ;
int V_115 ;
#ifdef F_46
if ( log -> V_73 & V_74 )
F_61 ( L_90 ) ;
#endif
F_160 ( log , V_10 ) ;
V_115 = V_10 -> V_55 ;
if ( V_10 -> V_29 & V_53 )
V_115 *= V_10 -> V_304 ;
if ( ! F_60 ( & log -> V_123 ) ) {
F_18 ( & log -> V_124 ) ;
if ( F_161 ( & log -> V_123 ) ) {
F_20 ( & log -> V_124 ) ;
goto V_305;
}
F_162 ( & V_10 -> V_306 , & log -> V_123 ) ;
F_163 ( log , V_10 ) ;
if ( F_10 ( log ) )
goto V_307;
F_26 ( V_308 ) ;
F_52 ( & V_10 -> V_122 , & log -> V_124 ) ;
F_164 ( log , V_10 ) ;
}
V_305:
if ( F_10 ( log ) )
goto V_309;
V_116 = F_62 ( log , & log -> V_125 ) ;
if ( V_116 < V_115 ) {
F_18 ( & log -> V_124 ) ;
if ( F_161 ( & V_10 -> V_306 ) )
F_162 ( & V_10 -> V_306 , & log -> V_123 ) ;
F_165 ( log , V_10 ) ;
if ( F_10 ( log ) )
goto V_307;
F_28 ( log , V_115 ) ;
F_26 ( V_308 ) ;
F_52 ( & V_10 -> V_122 , & log -> V_124 ) ;
F_166 ( log , V_10 ) ;
goto V_305;
}
if ( ! F_161 ( & V_10 -> V_306 ) ) {
F_18 ( & log -> V_124 ) ;
F_167 ( & V_10 -> V_306 ) ;
F_20 ( & log -> V_124 ) ;
}
F_6 ( log , & log -> V_125 , V_115 ) ;
F_6 ( log , & log -> V_121 , V_115 ) ;
F_168 ( log , V_10 ) ;
F_169 ( log ) ;
return 0 ;
V_309:
F_18 ( & log -> V_124 ) ;
V_307:
F_167 ( & V_10 -> V_306 ) ;
F_20 ( & log -> V_124 ) ;
F_170 ( log , V_10 ) ;
V_10 -> V_240 = 0 ;
V_10 -> V_60 = 0 ;
return F_25 ( V_43 ) ;
}
STATIC int
F_29 ( T_11 * log ,
T_3 * V_10 )
{
int V_116 , V_115 ;
V_10 -> V_240 = V_10 -> V_55 ;
F_7 ( V_10 ) ;
if ( V_10 -> V_60 > 0 )
return 0 ;
#ifdef F_46
if ( log -> V_73 & V_74 )
F_61 ( L_91 ) ;
#endif
F_171 ( log , V_10 ) ;
if ( F_10 ( log ) )
goto V_309;
V_115 = V_10 -> V_55 ;
if ( ! F_60 ( & log -> V_119 ) ) {
struct V_22 * V_310 ;
F_18 ( & log -> V_120 ) ;
V_116 = F_62 ( log , & log -> V_121 ) ;
F_63 (ntic, &log->l_writeq, t_queue) {
ASSERT ( V_310 -> V_29 & V_31 ) ;
if ( V_116 < V_310 -> V_55 )
break;
V_116 -= V_310 -> V_55 ;
F_65 ( & V_310 -> V_122 ) ;
}
if ( V_310 != F_172 ( & log -> V_119 ,
struct V_22 , V_306 ) ) {
if ( F_161 ( & V_10 -> V_306 ) )
F_162 ( & V_10 -> V_306 , & log -> V_119 ) ;
F_173 ( log , V_10 ) ;
F_28 ( log , V_115 ) ;
F_26 ( V_308 ) ;
F_52 ( & V_10 -> V_122 , & log -> V_120 ) ;
F_174 ( log , V_10 ) ;
} else
F_20 ( & log -> V_120 ) ;
}
V_305:
if ( F_10 ( log ) )
goto V_309;
V_116 = F_62 ( log , & log -> V_121 ) ;
if ( V_116 < V_115 ) {
F_18 ( & log -> V_120 ) ;
if ( F_161 ( & V_10 -> V_306 ) )
F_162 ( & V_10 -> V_306 , & log -> V_119 ) ;
if ( F_10 ( log ) )
goto V_307;
F_28 ( log , V_115 ) ;
F_26 ( V_308 ) ;
F_175 ( log , V_10 ) ;
F_52 ( & V_10 -> V_122 , & log -> V_120 ) ;
F_176 ( log , V_10 ) ;
goto V_305;
}
if ( ! F_161 ( & V_10 -> V_306 ) ) {
F_18 ( & log -> V_120 ) ;
F_167 ( & V_10 -> V_306 ) ;
F_20 ( & log -> V_120 ) ;
}
F_6 ( log , & log -> V_121 , V_115 ) ;
F_177 ( log , V_10 ) ;
F_169 ( log ) ;
return 0 ;
V_309:
F_18 ( & log -> V_120 ) ;
V_307:
F_167 ( & V_10 -> V_306 ) ;
F_20 ( & log -> V_120 ) ;
F_178 ( log , V_10 ) ;
V_10 -> V_240 = 0 ;
V_10 -> V_60 = 0 ;
return F_25 ( V_43 ) ;
}
STATIC void
F_16 ( T_11 * log ,
T_3 * V_23 )
{
F_179 ( log , V_23 ) ;
if ( V_23 -> V_60 > 0 )
V_23 -> V_60 -- ;
F_1 ( log , & log -> V_125 ,
V_23 -> V_240 ) ;
F_1 ( log , & log -> V_121 ,
V_23 -> V_240 ) ;
V_23 -> V_240 = V_23 -> V_55 ;
F_7 ( V_23 ) ;
F_180 ( log , V_23 ) ;
if ( V_23 -> V_60 > 0 )
return;
F_6 ( log , & log -> V_125 ,
V_23 -> V_55 ) ;
F_181 ( log , V_23 ) ;
V_23 -> V_240 = V_23 -> V_55 ;
F_7 ( V_23 ) ;
}
STATIC void
F_13 ( T_11 * log ,
T_3 * V_23 )
{
int V_2 ;
if ( V_23 -> V_60 > 0 )
V_23 -> V_60 -- ;
F_182 ( log , V_23 ) ;
F_183 ( log , V_23 ) ;
V_2 = V_23 -> V_240 ;
if ( V_23 -> V_60 > 0 ) {
ASSERT ( V_23 -> V_29 & V_31 ) ;
V_2 += V_23 -> V_55 * V_23 -> V_60 ;
}
F_1 ( log , & log -> V_125 , V_2 ) ;
F_1 ( log , & log -> V_121 , V_2 ) ;
F_184 ( log , V_23 ) ;
F_58 ( log -> V_137 , 1 ) ;
}
STATIC int
F_22 (
T_11 * log ,
T_12 * V_25 )
{
int V_311 = 0 ;
if ( V_25 -> V_36 & V_37 )
return F_25 ( V_43 ) ;
ASSERT ( F_119 ( & V_25 -> V_98 ) > 0 ) ;
if ( ! F_185 ( & V_25 -> V_98 , & log -> V_97 ) )
return 0 ;
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
ASSERT ( V_25 -> V_36 == V_38 ||
V_25 -> V_36 == V_39 ) ;
if ( V_25 -> V_36 == V_39 ) {
T_5 V_114 = F_71 ( log -> V_137 ) ;
V_311 ++ ;
V_25 -> V_36 = V_296 ;
V_25 -> V_186 . V_312 = F_157 ( V_114 ) ;
F_186 ( log , V_25 , V_114 ) ;
}
F_20 ( & log -> V_97 ) ;
if ( V_311 )
return F_118 ( log , V_25 ) ;
return 0 ;
}
STATIC void
F_158 ( T_11 * log ,
T_12 * V_25 ,
int V_313 )
{
ASSERT ( V_25 -> V_36 == V_38 ) ;
if ( ! V_313 )
V_313 = V_25 -> V_78 ;
V_25 -> V_36 = V_39 ;
V_25 -> V_186 . V_314 = F_101 ( log -> V_169 ) ;
log -> V_169 = log -> V_303 ;
log -> V_315 = log -> V_170 ;
log -> V_303 += F_108 ( V_313 ) + F_108 ( log -> V_155 ) ;
if ( F_87 ( & log -> V_137 -> V_153 ) &&
log -> V_137 -> V_153 . V_219 > 1 ) {
T_14 V_316 = F_108 ( log -> V_137 -> V_153 . V_219 ) ;
log -> V_303 = F_187 ( log -> V_303 , V_316 ) ;
}
if ( log -> V_303 >= log -> V_168 ) {
log -> V_170 ++ ;
if ( log -> V_170 == V_188 )
log -> V_170 ++ ;
log -> V_303 -= log -> V_168 ;
ASSERT ( log -> V_303 >= 0 ) ;
}
ASSERT ( V_25 == log -> V_77 ) ;
log -> V_77 = V_25 -> V_79 ;
}
int
F_47 (
struct V_20 * V_21 ,
T_4 V_26 ,
int * V_317 )
{
struct log * log = V_21 -> V_27 ;
struct V_24 * V_25 ;
T_5 V_28 ;
F_26 ( V_318 ) ;
if ( log -> V_275 )
F_188 ( log ) ;
F_18 ( & log -> V_97 ) ;
V_25 = log -> V_77 ;
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
if ( V_25 -> V_36 == V_38 ||
V_25 -> V_36 == V_99 ) {
if ( V_25 -> V_36 == V_99 ||
( F_119 ( & V_25 -> V_98 ) == 0
&& V_25 -> V_78 == 0 ) ) {
V_25 = V_25 -> V_180 ;
if ( V_25 -> V_36 == V_38 ||
V_25 -> V_36 == V_99 )
goto V_319;
else
goto V_320;
} else {
if ( F_119 ( & V_25 -> V_98 ) == 0 ) {
F_50 ( & V_25 -> V_98 ) ;
V_28 = F_125 ( V_25 -> V_186 . V_221 ) ;
F_158 ( log , V_25 , 0 ) ;
F_20 ( & log -> V_97 ) ;
if ( F_22 ( log , V_25 ) )
return F_25 ( V_43 ) ;
if ( V_317 )
* V_317 = 1 ;
F_18 ( & log -> V_97 ) ;
if ( F_125 ( V_25 -> V_186 . V_221 ) == V_28 &&
V_25 -> V_36 != V_99 )
goto V_320;
else
goto V_319;
} else {
F_158 ( log , V_25 , 0 ) ;
goto V_320;
}
}
}
V_320:
if ( V_26 & V_76 ) {
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
F_26 ( V_321 ) ;
F_52 ( & V_25 -> V_100 , & log -> V_97 ) ;
if ( V_25 -> V_36 & V_37 )
return F_25 ( V_43 ) ;
if ( V_317 )
* V_317 = 1 ;
} else {
V_319:
F_20 ( & log -> V_97 ) ;
}
return 0 ;
}
void
F_189 (
T_8 * V_21 ,
T_4 V_26 )
{
int error ;
error = F_47 ( V_21 , V_26 , NULL ) ;
if ( error )
F_38 ( V_21 , L_92 , V_96 , error ) ;
}
int
F_190 (
struct V_20 * V_21 ,
T_5 V_28 ,
T_4 V_26 ,
int * V_317 )
{
struct log * log = V_21 -> V_27 ;
struct V_24 * V_25 ;
int V_322 = 0 ;
ASSERT ( V_28 != 0 ) ;
F_26 ( V_318 ) ;
if ( log -> V_275 ) {
V_28 = F_191 ( log , V_28 ) ;
if ( V_28 == V_323 )
return 0 ;
}
V_324:
F_18 ( & log -> V_97 ) ;
V_25 = log -> V_77 ;
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
do {
if ( F_125 ( V_25 -> V_186 . V_221 ) != V_28 ) {
V_25 = V_25 -> V_79 ;
continue;
}
if ( V_25 -> V_36 == V_99 ) {
F_20 ( & log -> V_97 ) ;
return 0 ;
}
if ( V_25 -> V_36 == V_38 ) {
if ( ! V_322 &&
( V_25 -> V_180 -> V_36 &
( V_39 | V_296 ) ) ) {
ASSERT ( ! ( V_25 -> V_36 & V_37 ) ) ;
F_26 ( V_321 ) ;
F_52 ( & V_25 -> V_180 -> V_199 ,
& log -> V_97 ) ;
if ( V_317 )
* V_317 = 1 ;
V_322 = 1 ;
goto V_324;
}
F_50 ( & V_25 -> V_98 ) ;
F_158 ( log , V_25 , 0 ) ;
F_20 ( & log -> V_97 ) ;
if ( F_22 ( log , V_25 ) )
return F_25 ( V_43 ) ;
if ( V_317 )
* V_317 = 1 ;
F_18 ( & log -> V_97 ) ;
}
if ( ( V_26 & V_76 ) &&
! ( V_25 -> V_36 &
( V_38 | V_99 ) ) ) {
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
F_26 ( V_321 ) ;
F_52 ( & V_25 -> V_100 , & log -> V_97 ) ;
if ( V_25 -> V_36 & V_37 )
return F_25 ( V_43 ) ;
if ( V_317 )
* V_317 = 1 ;
} else {
F_20 ( & log -> V_97 ) ;
}
return 0 ;
} while ( V_25 != log -> V_77 );
F_20 ( & log -> V_97 ) ;
return 0 ;
}
void
F_192 (
T_8 * V_21 ,
T_5 V_28 ,
T_4 V_26 )
{
int error ;
error = F_190 ( V_21 , V_28 , V_26 , NULL ) ;
if ( error )
F_38 ( V_21 , L_92 , V_96 , error ) ;
}
STATIC void
F_51 ( T_11 * log , T_12 * V_25 )
{
F_193 ( & log -> V_97 ) ;
if ( V_25 -> V_36 == V_38 ) {
F_158 ( log , V_25 , 0 ) ;
} else {
ASSERT ( V_25 -> V_36 &
( V_39 | V_37 ) ) ;
}
}
void
F_14 (
T_3 * V_23 )
{
ASSERT ( F_119 ( & V_23 -> V_325 ) > 0 ) ;
if ( F_194 ( & V_23 -> V_325 ) )
F_195 ( V_326 , V_23 ) ;
}
T_3 *
F_196 (
T_3 * V_23 )
{
ASSERT ( F_119 ( & V_23 -> V_325 ) > 0 ) ;
F_50 ( & V_23 -> V_325 ) ;
return V_23 ;
}
T_3 *
F_30 (
struct log * log ,
int V_44 ,
int V_45 ,
char V_46 ,
T_4 V_327 ,
int V_328 )
{
struct V_22 * V_10 ;
T_4 V_329 ;
int V_330 ;
V_10 = F_197 ( V_326 , V_328 ) ;
if ( ! V_10 )
return NULL ;
V_44 += sizeof( V_235 ) ;
V_44 += sizeof( V_331 ) ;
V_44 += sizeof( V_235 ) ;
V_330 = log -> V_151 - log -> V_155 ;
V_329 = F_198 ( V_44 , V_330 ) ;
V_44 += sizeof( V_235 ) * V_329 ;
while ( ! V_329 ||
F_198 ( V_44 , V_330 ) > V_329 ) {
V_44 += sizeof( V_235 ) ;
V_329 ++ ;
}
V_44 += log -> V_155 * V_329 ;
V_44 += log -> V_155 ;
if ( F_87 ( & log -> V_137 -> V_153 ) &&
log -> V_137 -> V_153 . V_219 > 1 ) {
V_44 += 2 * log -> V_137 -> V_153 . V_219 ;
} else {
V_44 += 2 * V_159 ;
}
F_102 ( & V_10 -> V_325 , 1 ) ;
F_56 ( & V_10 -> V_306 ) ;
V_10 -> V_55 = V_44 ;
V_10 -> V_240 = V_44 ;
V_10 -> V_60 = V_45 ;
V_10 -> V_304 = V_45 ;
V_10 -> V_54 = F_199 () ;
V_10 -> V_252 = V_46 ;
V_10 -> V_29 = V_30 ;
V_10 -> V_59 = 0 ;
if ( V_327 & V_53 )
V_10 -> V_29 |= V_31 ;
F_97 ( & V_10 -> V_122 ) ;
F_7 ( V_10 ) ;
return V_10 ;
}
void
F_152 (
struct log * log ,
char * V_276 )
{
int V_164 ;
int V_332 = 0 ;
for ( V_164 = 0 ; V_164 < log -> V_148 ; V_164 ++ ) {
if ( V_276 >= log -> V_184 [ V_164 ] &&
V_276 <= log -> V_184 [ V_164 ] + log -> V_151 )
V_332 ++ ;
}
if ( ! V_332 )
F_200 ( log -> V_137 , L_93 , V_96 ) ;
}
STATIC void
F_169 (
struct log * log )
{
int V_134 , V_333 ;
int V_6 , V_7 ;
F_72 ( & log -> V_121 , & V_6 , & V_7 ) ;
F_73 ( & log -> V_118 , & V_134 , & V_333 ) ;
if ( V_134 != V_6 ) {
if ( V_6 - 1 != V_134 &&
! ( log -> V_73 & V_334 ) ) {
F_144 ( log -> V_137 , V_241 ,
L_94 , V_96 ) ;
log -> V_73 |= V_334 ;
}
if ( V_7 > F_74 ( V_333 ) &&
! ( log -> V_73 & V_334 ) ) {
F_144 ( log -> V_137 , V_241 ,
L_95 , V_96 ) ;
log -> V_73 |= V_334 ;
}
}
}
STATIC void
F_186 ( T_11 * log ,
T_12 * V_25 ,
T_5 V_114 )
{
int V_335 ;
if ( F_201 ( V_114 ) == log -> V_315 ) {
V_335 =
log -> V_168 - ( log -> V_169 - F_124 ( V_114 ) ) ;
if ( V_335 < F_108 ( V_25 -> V_78 ) + F_108 ( log -> V_155 ) )
F_200 ( log -> V_137 , L_96 , V_96 ) ;
} else {
ASSERT ( F_201 ( V_114 ) + 1 == log -> V_315 ) ;
if ( F_124 ( V_114 ) == log -> V_169 )
F_200 ( log -> V_137 , L_97 , V_96 ) ;
V_335 = F_124 ( V_114 ) - log -> V_169 ;
if ( V_335 < F_108 ( V_25 -> V_78 ) + 1 )
F_200 ( log -> V_137 , L_96 , V_96 ) ;
}
}
STATIC void
F_134 ( T_11 * log ,
T_12 * V_25 ,
int V_213 ,
T_17 V_336 )
{
V_235 * V_337 ;
T_12 * V_338 ;
T_18 * V_339 ;
V_185 V_276 ;
V_185 V_340 ;
V_228 V_341 ;
T_7 V_342 ;
int V_14 , V_164 , V_343 , V_344 , V_345 ;
int V_346 ;
F_18 ( & log -> V_97 ) ;
V_338 = log -> V_77 ;
for ( V_164 = 0 ; V_164 < log -> V_148 ; V_164 ++ ) {
if ( V_338 == NULL )
F_200 ( log -> V_137 , L_93 , V_96 ) ;
V_338 = V_338 -> V_79 ;
}
if ( V_338 != log -> V_77 )
F_200 ( log -> V_137 , L_98 , V_96 ) ;
F_20 ( & log -> V_97 ) ;
if ( F_139 ( V_25 -> V_186 . V_187 ) != V_188 )
F_200 ( log -> V_137 , L_99 , V_96 ) ;
V_276 = ( V_185 ) & V_25 -> V_186 ;
for ( V_276 += V_159 ; V_276 < ( ( V_185 ) & V_25 -> V_186 ) + V_213 ;
V_276 += V_159 ) {
if ( F_139 ( * ( V_229 * ) V_276 ) == V_188 )
F_200 ( log -> V_137 , L_100 ,
V_96 ) ;
}
V_14 = F_139 ( V_25 -> V_186 . V_233 ) ;
V_276 = V_25 -> V_198 ;
V_340 = V_276 ;
V_337 = ( V_235 * ) V_276 ;
V_339 = V_25 -> V_182 ;
for ( V_164 = 0 ; V_164 < V_14 ; V_164 ++ ) {
V_337 = ( V_235 * ) V_276 ;
V_341 = ( V_228 )
( ( V_185 ) & ( V_337 -> V_251 ) - V_340 ) ;
if ( V_336 == V_347 || ( V_341 & 0x1ff ) ) {
V_342 = V_337 -> V_251 ;
} else {
V_346 = F_109 ( ( V_185 ) & ( V_337 -> V_251 ) - V_25 -> V_198 ) ;
if ( V_346 >= ( V_154 / V_159 ) ) {
V_343 = V_346 / ( V_154 / V_159 ) ;
V_344 = V_346 % ( V_154 / V_159 ) ;
V_342 = F_202 (
V_339 [ V_343 ] . V_348 . V_349 [ V_344 ] ) ;
} else {
V_342 = F_202 (
V_25 -> V_186 . V_281 [ V_346 ] ) ;
}
}
if ( V_342 != V_50 && V_342 != V_51 )
F_38 ( log -> V_137 ,
L_101 ,
V_96 , V_342 , V_337 ,
( unsigned long ) V_341 ) ;
V_341 = ( V_228 )
( ( V_185 ) & ( V_337 -> V_253 ) - V_340 ) ;
if ( V_336 == V_347 || ( V_341 & 0x1ff ) ) {
V_345 = F_139 ( V_337 -> V_253 ) ;
} else {
V_346 = F_109 ( ( V_228 ) & V_337 -> V_253 -
( V_228 ) V_25 -> V_198 ) ;
if ( V_346 >= ( V_154 / V_159 ) ) {
V_343 = V_346 / ( V_154 / V_159 ) ;
V_344 = V_346 % ( V_154 / V_159 ) ;
V_345 = F_139 ( V_339 [ V_343 ] . V_348 . V_349 [ V_344 ] ) ;
} else {
V_345 = F_139 ( V_25 -> V_186 . V_281 [ V_346 ] ) ;
}
}
V_276 += sizeof( V_235 ) + V_345 ;
}
}
STATIC int
F_203 (
T_11 * log )
{
T_12 * V_25 , * V_350 ;
V_25 = log -> V_77 ;
if ( ! ( V_25 -> V_36 & V_37 ) ) {
V_350 = V_25 ;
do {
V_350 -> V_36 = V_37 ;
V_350 = V_350 -> V_79 ;
} while ( V_350 != V_25 );
return 0 ;
}
return 1 ;
}
int
F_204 (
struct V_20 * V_21 ,
int V_351 )
{
T_3 * V_10 ;
T_11 * log ;
int V_49 ;
log = V_21 -> V_27 ;
if ( ! log ||
log -> V_73 & V_74 ) {
V_21 -> V_64 |= V_352 ;
if ( V_21 -> V_353 )
F_205 ( V_21 -> V_353 ) ;
return 0 ;
}
if ( V_351 && log -> V_77 -> V_36 & V_37 ) {
ASSERT ( F_10 ( log ) ) ;
return 1 ;
}
V_49 = 0 ;
if ( ! V_351 && ( V_21 -> V_64 & V_354 ) )
F_188 ( log ) ;
F_18 ( & log -> V_97 ) ;
V_21 -> V_64 |= V_352 ;
if ( V_21 -> V_353 )
F_205 ( V_21 -> V_353 ) ;
log -> V_73 |= V_355 ;
if ( V_351 )
V_49 = F_203 ( log ) ;
F_20 ( & log -> V_97 ) ;
F_18 ( & log -> V_124 ) ;
F_63 (tic, &log->l_reserveq, t_queue)
F_65 ( & V_10 -> V_122 ) ;
F_20 ( & log -> V_124 ) ;
F_18 ( & log -> V_120 ) ;
F_63 (tic, &log->l_writeq, t_queue)
F_65 ( & V_10 -> V_122 ) ;
F_20 ( & log -> V_120 ) ;
if ( ! ( log -> V_77 -> V_36 & V_37 ) ) {
ASSERT ( ! V_351 ) ;
F_47 ( V_21 , V_76 , NULL ) ;
F_18 ( & log -> V_97 ) ;
V_49 = F_203 ( log ) ;
F_20 ( & log -> V_97 ) ;
}
F_155 ( log , V_144 , NULL ) ;
#ifdef F_206
{
T_12 * V_25 ;
F_18 ( & log -> V_97 ) ;
V_25 = log -> V_77 ;
do {
ASSERT ( V_25 -> V_197 == 0 ) ;
V_25 = V_25 -> V_79 ;
} while ( V_25 != log -> V_77 );
F_20 ( & log -> V_97 ) ;
}
#endif
return V_49 ;
}
STATIC int
F_70 ( T_11 * log )
{
T_12 * V_25 ;
V_25 = log -> V_77 ;
do {
if ( V_25 -> V_186 . V_233 )
return 0 ;
V_25 = V_25 -> V_79 ;
} while ( V_25 != log -> V_77 );
return 1 ;
}
