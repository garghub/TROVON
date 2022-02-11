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
T_12 * V_25 = V_138 -> V_139 ;
T_11 * V_140 = V_25 -> V_141 ;
int V_142 = 0 ;
if ( F_76 ( ( F_77 ( V_138 ) ) , V_140 -> V_137 ,
V_143 , V_144 ) ) {
F_78 ( L_10 , V_140 -> V_137 , V_138 , F_79 ( V_138 ) ) ;
F_80 ( V_138 ) ;
F_23 ( V_140 -> V_137 , V_42 ) ;
V_142 = V_145 ;
} else if ( V_25 -> V_36 & V_37 ) {
V_142 = V_145 ;
}
ASSERT ( F_81 ( V_138 ) ) ;
F_82 ( V_25 , V_142 ) ;
}
STATIC void
F_83 ( T_8 * V_21 ,
T_11 * log )
{
int V_146 ;
int V_147 ;
if ( V_21 -> V_148 <= 0 )
log -> V_149 = V_150 ;
else
log -> V_149 = V_21 -> V_148 ;
if ( V_21 -> V_151 > 0 ) {
V_146 = log -> V_152 = V_21 -> V_151 ;
log -> V_153 = 0 ;
while ( V_146 != 1 ) {
log -> V_153 ++ ;
V_146 >>= 1 ;
}
if ( F_84 ( & V_21 -> V_154 ) ) {
V_147 = V_21 -> V_151 / V_155 ;
if ( V_21 -> V_151 % V_155 )
V_147 ++ ;
log -> V_156 = V_147 << V_157 ;
log -> V_158 = V_147 ;
} else {
ASSERT ( V_21 -> V_151 <= V_159 ) ;
log -> V_156 = V_160 ;
log -> V_158 = 1 ;
}
goto V_161;
}
log -> V_152 = V_159 ;
log -> V_153 = V_162 ;
log -> V_156 = V_160 ;
log -> V_158 = 1 ;
V_161:
if ( V_21 -> V_148 == 0 )
V_21 -> V_148 = log -> V_149 ;
if ( V_21 -> V_151 == 0 )
V_21 -> V_151 = log -> V_152 ;
}
STATIC T_11 *
F_34 ( T_8 * V_21 ,
T_9 * V_61 ,
T_10 V_62 ,
int V_63 )
{
T_11 * log ;
T_16 * V_1 ;
T_12 * * V_163 ;
T_12 * V_25 , * V_164 = NULL ;
T_15 * V_138 ;
int V_165 ;
int error = V_58 ;
T_4 V_166 = 0 ;
log = F_85 ( sizeof( T_11 ) , V_57 ) ;
if ( ! log ) {
F_38 ( V_21 , L_11 ) ;
goto V_67;
}
log -> V_137 = V_21 ;
log -> V_167 = V_61 ;
log -> V_8 = F_74 ( V_63 ) ;
log -> V_168 = V_62 ;
log -> V_169 = V_63 ;
log -> V_127 = V_130 ;
log -> V_73 |= V_74 ;
log -> V_170 = - 1 ;
F_86 ( & log -> V_118 , 1 , 0 ) ;
F_86 ( & log -> V_117 , 1 , 0 ) ;
log -> V_171 = 1 ;
F_87 ( & log -> V_125 , 1 , 0 ) ;
F_87 ( & log -> V_121 , 1 , 0 ) ;
F_56 ( & log -> V_123 ) ;
F_56 ( & log -> V_119 ) ;
F_88 ( & log -> V_124 ) ;
F_88 ( & log -> V_120 ) ;
error = V_172 ;
if ( F_89 ( & V_21 -> V_154 ) ) {
V_166 = V_21 -> V_154 . V_173 ;
if ( V_166 < V_157 ) {
F_38 ( V_21 , L_12 ,
V_166 , V_157 ) ;
goto V_68;
}
V_166 -= V_157 ;
if ( V_166 > V_21 -> V_174 ) {
F_38 ( V_21 , L_13 ,
V_166 , V_21 -> V_174 ) ;
goto V_68;
}
if ( V_166 && log -> V_168 > 0 &&
! F_84 ( & V_21 -> V_154 ) ) {
F_38 ( V_21 ,
L_14 ,
V_166 ) ;
goto V_68;
}
}
log -> V_175 = 1 << V_166 ;
F_83 ( V_21 , log ) ;
error = V_58 ;
V_138 = F_90 ( log -> V_152 , V_21 -> V_176 ) ;
if ( ! V_138 )
goto V_68;
V_138 -> V_177 = F_75 ;
ASSERT ( F_91 ( V_138 ) ) ;
log -> V_178 = V_138 ;
F_88 ( & log -> V_97 ) ;
F_92 ( & log -> V_179 ) ;
ASSERT ( ( F_93 ( V_138 ) & V_180 ) == 0 ) ;
V_163 = & log -> V_77 ;
ASSERT ( log -> V_152 >= 4096 ) ;
for ( V_165 = 0 ; V_165 < log -> V_149 ; V_165 ++ ) {
* V_163 = F_85 ( sizeof( T_12 ) , V_57 ) ;
if ( ! * V_163 )
goto V_181;
V_25 = * V_163 ;
V_25 -> V_182 = V_164 ;
V_164 = V_25 ;
V_138 = F_94 ( V_21 -> V_176 ,
log -> V_152 , 0 ) ;
if ( ! V_138 )
goto V_181;
V_138 -> V_177 = F_75 ;
V_25 -> V_183 = V_138 ;
V_25 -> V_184 = V_138 -> V_185 ;
#ifdef F_46
log -> V_186 [ V_165 ] = ( V_187 ) & ( V_25 -> V_188 ) ;
#endif
V_1 = & V_25 -> V_188 ;
memset ( V_1 , 0 , sizeof( T_16 ) ) ;
V_1 -> V_189 = F_95 ( V_190 ) ;
V_1 -> V_191 = F_95 (
F_84 ( & log -> V_137 -> V_154 ) ? 2 : 1 ) ;
V_1 -> V_192 = F_95 ( log -> V_152 ) ;
V_1 -> V_193 = F_95 ( V_194 ) ;
memcpy ( & V_1 -> V_195 , & V_21 -> V_154 . V_196 , sizeof( V_197 ) ) ;
V_25 -> V_198 = F_93 ( V_138 ) - log -> V_156 ;
V_25 -> V_36 = V_38 ;
V_25 -> V_141 = log ;
F_96 ( & V_25 -> V_98 , 0 ) ;
F_88 ( & V_25 -> V_35 ) ;
V_25 -> V_41 = & ( V_25 -> V_199 ) ;
V_25 -> V_200 = ( char * ) V_25 -> V_184 + log -> V_156 ;
ASSERT ( F_91 ( V_25 -> V_183 ) ) ;
F_92 ( & V_25 -> V_100 ) ;
F_92 ( & V_25 -> V_201 ) ;
V_163 = & V_25 -> V_79 ;
}
* V_163 = log -> V_77 ;
log -> V_77 -> V_182 = V_164 ;
error = F_97 ( log ) ;
if ( error )
goto V_181;
return log ;
V_181:
for ( V_25 = log -> V_77 ; V_25 ; V_25 = V_164 ) {
V_164 = V_25 -> V_79 ;
if ( V_25 -> V_183 )
F_98 ( V_25 -> V_183 ) ;
F_99 ( V_25 ) ;
}
F_100 ( & log -> V_97 ) ;
F_98 ( log -> V_178 ) ;
V_68:
F_99 ( log ) ;
V_67:
return F_101 ( - error ) ;
}
STATIC int
F_11 (
struct log * log ,
struct V_22 * V_23 ,
struct V_24 * * V_25 ,
T_5 * V_202 )
{
struct V_20 * V_21 = log -> V_137 ;
int error ;
struct V_85 V_86 = {
. V_87 = NULL ,
. V_88 = 0 ,
. V_89 = V_203 ,
} ;
struct V_91 V_92 = {
. V_93 = 1 ,
. V_94 = & V_86 ,
} ;
F_19 ( V_25 ) ;
error = F_48 ( log , & V_92 , V_23 , V_202 , V_25 ,
V_204 ) ;
if ( error )
F_23 ( V_21 , V_42 ) ;
return error ;
}
STATIC void
F_28 (
struct log * log ,
int V_115 )
{
T_5 V_205 = 0 ;
T_5 V_206 ;
int V_207 ;
int V_116 ;
int V_208 ;
int V_209 ;
int V_210 ;
ASSERT ( F_102 ( V_115 ) < log -> V_169 ) ;
V_116 = F_62 ( log , & log -> V_125 ) ;
V_207 = F_103 ( V_116 ) ;
V_210 = F_102 ( V_115 ) ;
V_210 = F_104 ( V_210 , ( log -> V_169 >> 2 ) ) ;
V_210 = F_104 ( V_210 , 256 ) ;
if ( V_207 >= V_210 )
return;
F_73 ( & log -> V_118 , & V_209 ,
& V_208 ) ;
V_208 += V_210 ;
if ( V_208 >= log -> V_169 ) {
V_208 -= log -> V_169 ;
V_209 += 1 ;
}
V_205 = F_105 ( V_209 ,
V_208 ) ;
V_206 = F_2 ( & log -> V_117 ) ;
if ( F_106 ( V_205 , V_206 ) > 0 )
V_205 = V_206 ;
if ( ! F_10 ( log ) )
F_107 ( log -> V_69 , V_205 ) ;
}
STATIC int
F_108 (
struct V_211 * V_138 )
{
struct V_24 * V_25 = V_138 -> V_139 ;
if ( V_25 -> V_36 & V_37 ) {
F_109 ( V_138 , V_43 ) ;
F_80 ( V_138 ) ;
F_110 ( V_138 , 0 ) ;
return 0 ;
}
F_111 ( V_138 ) ;
return 0 ;
}
STATIC int
F_112 ( T_11 * log ,
T_12 * V_25 )
{
V_187 V_212 ;
T_15 * V_138 ;
int V_165 ;
T_4 V_213 ;
T_4 V_214 ;
int V_215 ;
int V_216 = 0 ;
int error ;
int V_217 = F_84 ( & log -> V_137 -> V_154 ) ;
F_26 ( V_218 ) ;
ASSERT ( F_113 ( & V_25 -> V_98 ) == 0 ) ;
V_214 = log -> V_156 + V_25 -> V_78 ;
if ( V_217 && log -> V_137 -> V_154 . V_219 > 1 ) {
V_213 = F_114 ( log , F_115 ( log , V_214 ) ) ;
} else {
V_213 = F_74 ( F_102 ( V_214 ) ) ;
}
V_215 = V_213 - V_214 ;
ASSERT ( V_215 >= 0 ) ;
ASSERT ( ( V_217 && log -> V_137 -> V_154 . V_219 > 1 &&
V_215 < log -> V_137 -> V_154 . V_219 )
||
( log -> V_137 -> V_154 . V_219 <= 1 &&
V_215 < F_74 ( 1 ) ) ) ;
F_6 ( log , & log -> V_125 , V_215 ) ;
F_6 ( log , & log -> V_121 , V_215 ) ;
F_116 ( log , V_25 , V_215 ) ;
if ( V_217 ) {
V_25 -> V_188 . V_220 =
F_95 ( V_25 -> V_78 + V_215 ) ;
} else {
V_25 -> V_188 . V_220 =
F_95 ( V_25 -> V_78 ) ;
}
V_138 = V_25 -> V_183 ;
F_117 ( V_138 , F_118 ( F_119 ( V_25 -> V_188 . V_221 ) ) ) ;
F_120 ( V_222 , F_102 ( V_213 ) ) ;
if ( F_79 ( V_138 ) + F_102 ( V_213 ) > log -> V_169 ) {
V_216 = V_213 - ( F_74 ( log -> V_169 - F_79 ( V_138 ) ) ) ;
V_213 = F_74 ( log -> V_169 - F_79 ( V_138 ) ) ;
V_25 -> V_223 = 2 ;
} else {
V_25 -> V_223 = 1 ;
}
F_121 ( V_138 , V_213 ) ;
V_138 -> V_139 = V_25 ;
F_122 ( V_138 ) ;
F_123 ( V_138 ) ;
V_138 -> V_224 |= V_225 ;
if ( log -> V_137 -> V_64 & V_226 ) {
V_138 -> V_224 |= V_227 ;
if ( log -> V_137 -> V_176 != log -> V_137 -> V_228 )
F_124 ( log -> V_137 -> V_228 ) ;
else
V_138 -> V_224 |= V_229 ;
}
ASSERT ( F_79 ( V_138 ) <= log -> V_169 - 1 ) ;
ASSERT ( F_79 ( V_138 ) + F_102 ( V_213 ) <= log -> V_169 ) ;
F_125 ( log , V_25 , V_213 , V_230 ) ;
F_117 ( V_138 , F_79 ( V_138 ) + log -> V_168 ) ;
F_126 ( V_138 ) ;
if ( ( error = F_108 ( V_138 ) ) ) {
F_78 ( L_15 , log -> V_137 , V_138 ,
F_79 ( V_138 ) ) ;
return error ;
}
if ( V_216 ) {
V_138 = V_25 -> V_141 -> V_178 ;
F_117 ( V_138 , 0 ) ;
F_127 ( V_138 ,
( char * ) & V_25 -> V_188 + V_213 , V_216 ) ;
V_138 -> V_139 = V_25 ;
F_122 ( V_138 ) ;
F_123 ( V_138 ) ;
V_138 -> V_224 |= V_225 ;
if ( log -> V_137 -> V_64 & V_226 )
V_138 -> V_224 |= V_227 ;
V_212 = V_138 -> V_185 ;
for ( V_165 = 0 ; V_165 < V_216 ; V_165 += V_160 ) {
F_128 ( ( V_231 * ) V_212 , 1 ) ;
if ( F_129 ( * ( V_231 * ) V_212 ) == V_190 )
F_128 ( ( V_231 * ) V_212 , 1 ) ;
V_212 += V_160 ;
}
ASSERT ( F_79 ( V_138 ) <= log -> V_169 - 1 ) ;
ASSERT ( F_79 ( V_138 ) + F_102 ( V_213 ) <= log -> V_169 ) ;
F_117 ( V_138 , F_79 ( V_138 ) + log -> V_168 ) ;
F_126 ( V_138 ) ;
if ( ( error = F_108 ( V_138 ) ) ) {
F_78 ( L_16 , log -> V_137 ,
V_138 , F_79 ( V_138 ) ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_42 ( T_11 * log )
{
T_12 * V_25 , * V_232 ;
int V_165 ;
F_130 ( log ) ;
F_131 ( log -> V_178 , log -> V_152 ) ;
F_98 ( log -> V_178 ) ;
V_25 = log -> V_77 ;
for ( V_165 = 0 ; V_165 < log -> V_149 ; V_165 ++ ) {
F_98 ( V_25 -> V_183 ) ;
V_232 = V_25 -> V_79 ;
F_99 ( V_25 ) ;
V_25 = V_232 ;
}
F_100 ( & log -> V_97 ) ;
log -> V_137 -> V_27 = NULL ;
F_99 ( log ) ;
}
static inline void
F_132 ( T_11 * log ,
T_12 * V_25 ,
int V_233 ,
int V_234 )
{
F_18 ( & log -> V_97 ) ;
F_128 ( & V_25 -> V_188 . V_235 , V_233 ) ;
V_25 -> V_78 += V_234 ;
F_20 ( & log -> V_97 ) ;
}
void
F_133 (
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
T_4 V_165 ;
T_4 V_236 = V_23 -> V_13 * ( T_4 ) sizeof( V_237 ) ;
static char * V_238 [ V_239 ] = {
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
static char * V_240 [ V_241 ] = {
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
V_23 -> V_59 > V_241 ) ?
L_84 : V_240 [ V_23 -> V_59 - 1 ] ) ,
V_23 -> V_59 ,
V_23 -> V_55 ,
V_23 -> V_242 ,
V_23 -> V_12 , V_23 -> V_16 ,
V_23 -> V_13 , V_236 ,
V_23 -> V_12 +
V_23 -> V_16 + V_236 ,
V_23 -> V_11 ) ;
for ( V_165 = 0 ; V_165 < V_23 -> V_11 ; V_165 ++ ) {
T_4 V_19 = V_23 -> V_17 [ V_165 ] . V_19 ;
F_38 ( V_21 , L_85 , V_165 ,
( ( V_19 <= 0 || V_19 > V_239 ) ?
L_86 : V_238 [ V_19 - 1 ] ) ,
V_23 -> V_17 [ V_165 ] . V_18 ) ;
}
F_134 ( V_21 , V_243 ,
L_87 ) ;
F_23 ( V_21 , V_244 ) ;
}
static int
F_135 (
struct V_22 * V_23 ,
struct V_91 * V_245 )
{
struct V_91 * V_246 ;
int V_247 = 0 ;
int V_14 = 0 ;
int V_165 ;
if ( V_23 -> V_29 & V_30 )
V_247 ++ ;
for ( V_246 = V_245 ; V_246 ; V_246 = V_246 -> V_248 ) {
V_247 += V_246 -> V_93 ;
for ( V_165 = 0 ; V_165 < V_246 -> V_93 ; V_165 ++ ) {
struct V_85 * V_249 = & V_246 -> V_94 [ V_165 ] ;
V_14 += V_249 -> V_88 ;
F_8 ( V_23 , V_249 -> V_88 , V_249 -> V_89 ) ;
}
}
V_23 -> V_13 += V_247 ;
V_14 += V_247 * sizeof( struct V_250 ) ;
return V_14 ;
}
static int
F_136 (
struct V_250 * V_251 ,
struct V_22 * V_23 )
{
if ( ! ( V_23 -> V_29 & V_30 ) )
return 0 ;
V_251 -> V_252 = F_95 ( V_23 -> V_54 ) ;
V_251 -> V_253 = V_23 -> V_254 ;
V_251 -> V_255 = 0 ;
V_251 -> V_256 = V_257 ;
V_251 -> V_258 = 0 ;
V_23 -> V_29 &= ~ V_30 ;
return sizeof( struct V_250 ) ;
}
static V_237 *
F_137 (
struct log * log ,
struct V_250 * V_251 ,
struct V_22 * V_23 ,
T_4 V_26 )
{
V_251 -> V_252 = F_95 ( V_23 -> V_54 ) ;
V_251 -> V_253 = V_23 -> V_254 ;
V_251 -> V_258 = 0 ;
V_251 -> V_256 = V_26 ;
switch ( V_251 -> V_253 ) {
case V_50 :
case V_259 :
case V_51 :
break;
default:
F_38 ( log -> V_137 ,
L_88 ,
V_251 -> V_253 , V_23 ) ;
return NULL ;
}
return V_251 ;
}
static int
F_138 (
struct V_22 * V_23 ,
struct V_250 * V_251 ,
int V_260 ,
int V_261 ,
int * V_262 ,
int * V_263 ,
int * V_264 ,
int * V_265 )
{
int V_266 ;
V_266 = V_261 - * V_265 ;
* V_262 = * V_265 ;
if ( V_266 <= V_260 ) {
* V_263 = V_266 ;
V_251 -> V_255 = F_95 ( * V_263 ) ;
if ( * V_264 )
V_251 -> V_256 |= ( V_267 | V_268 ) ;
* V_264 = 0 ;
* V_265 = 0 ;
return 0 ;
}
* V_263 = V_260 ;
V_251 -> V_255 = F_95 ( * V_263 ) ;
V_251 -> V_256 |= V_269 ;
if ( * V_264 )
V_251 -> V_256 |= V_268 ;
* V_265 += * V_263 ;
( * V_264 ) ++ ;
V_23 -> V_242 -= sizeof( struct V_250 ) ;
V_23 -> V_13 ++ ;
return sizeof( struct V_250 ) ;
}
static int
F_139 (
struct log * log ,
struct V_24 * V_25 ,
T_4 V_26 ,
int * V_233 ,
int * V_270 ,
int * V_271 ,
int * V_272 ,
int V_273 ,
struct V_24 * * V_274 )
{
if ( * V_271 ) {
F_132 ( log , V_25 , * V_233 , * V_270 ) ;
* V_233 = 0 ;
* V_270 = 0 ;
return F_22 ( log , V_25 ) ;
}
* V_271 = 0 ;
* V_272 = 0 ;
if ( V_25 -> V_198 - V_273 <= sizeof( V_237 ) ) {
F_132 ( log , V_25 , * V_233 , * V_270 ) ;
* V_233 = 0 ;
* V_270 = 0 ;
F_18 ( & log -> V_97 ) ;
F_51 ( log , V_25 ) ;
F_20 ( & log -> V_97 ) ;
if ( ! V_274 )
return F_22 ( log , V_25 ) ;
ASSERT ( V_26 & V_204 ) ;
* V_274 = V_25 ;
}
return 0 ;
}
int
F_48 (
struct log * log ,
struct V_91 * V_245 ,
struct V_22 * V_23 ,
T_5 * V_113 ,
struct V_24 * * V_274 ,
T_4 V_26 )
{
struct V_24 * V_25 = NULL ;
struct V_85 * V_249 ;
struct V_91 * V_246 ;
int V_14 ;
int V_275 ;
int V_271 = 0 ;
int V_272 = 0 ;
int V_276 = 0 ;
int V_233 = 0 ;
int V_270 = 0 ;
int error ;
* V_113 = 0 ;
V_14 = F_135 ( V_23 , V_245 ) ;
if ( log -> V_277 ) {
if ( V_23 -> V_29 & V_30 )
V_23 -> V_242 -= sizeof( V_237 ) ;
if ( V_26 & ( V_204 | V_95 ) )
V_23 -> V_242 -= sizeof( V_237 ) ;
} else
V_23 -> V_242 -= V_14 ;
if ( V_23 -> V_242 < 0 )
F_133 ( log -> V_137 , V_23 ) ;
V_275 = 0 ;
V_246 = V_245 ;
V_249 = V_246 -> V_94 ;
while ( V_246 && V_275 < V_246 -> V_93 ) {
void * V_278 ;
int V_273 ;
error = F_140 ( log , V_14 , & V_25 , V_23 ,
& V_276 , & V_273 ) ;
if ( error )
return error ;
ASSERT ( V_273 <= V_25 -> V_198 - 1 ) ;
V_278 = V_25 -> V_200 + V_273 ;
if ( ! * V_113 )
* V_113 = F_119 ( V_25 -> V_188 . V_221 ) ;
while ( V_246 && V_275 < V_246 -> V_93 ) {
struct V_85 * V_86 = & V_249 [ V_275 ] ;
struct V_250 * V_251 ;
int V_279 ;
int V_263 ;
int V_262 ;
ASSERT ( V_86 -> V_88 % sizeof( V_280 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_278 % sizeof( V_280 ) == 0 ) ;
V_279 = F_136 ( V_278 , V_23 ) ;
if ( V_279 ) {
V_233 ++ ;
F_141 ( & V_278 , & V_14 , & V_273 ,
V_279 ) ;
}
V_251 = F_137 ( log , V_278 , V_23 , V_26 ) ;
if ( ! V_251 )
return F_25 ( V_43 ) ;
F_141 ( & V_278 , & V_14 , & V_273 ,
sizeof( struct V_250 ) ) ;
V_14 += F_138 ( V_23 , V_251 ,
V_25 -> V_198 - V_273 ,
V_86 -> V_88 ,
& V_262 , & V_263 ,
& V_271 ,
& V_272 ) ;
F_142 ( log , V_278 ) ;
ASSERT ( V_263 >= 0 ) ;
memcpy ( V_278 , V_86 -> V_87 + V_262 , V_263 ) ;
F_141 ( & V_278 , & V_14 , & V_273 , V_263 ) ;
V_263 += V_279 + sizeof( V_237 ) ;
V_233 ++ ;
V_270 += V_276 ? V_263 : 0 ;
error = F_139 ( log , V_25 , V_26 ,
& V_233 , & V_270 ,
& V_271 ,
& V_272 ,
V_273 ,
V_274 ) ;
if ( error )
return error ;
if ( V_271 )
break;
if ( ++ V_275 == V_246 -> V_93 ) {
V_246 = V_246 -> V_248 ;
V_275 = 0 ;
if ( V_246 )
V_249 = V_246 -> V_94 ;
}
if ( V_233 == 0 ) {
if ( ! V_246 )
return 0 ;
break;
}
}
}
ASSERT ( V_14 == 0 ) ;
F_132 ( log , V_25 , V_233 , V_270 ) ;
if ( ! V_274 )
return F_22 ( log , V_25 ) ;
ASSERT ( V_26 & V_204 ) ;
* V_274 = V_25 ;
return 0 ;
}
STATIC void
F_143 ( T_11 * log )
{
T_12 * V_25 ;
int V_281 = 0 ;
V_25 = log -> V_77 ;
do {
if ( V_25 -> V_36 == V_99 ) {
V_25 -> V_36 = V_38 ;
V_25 -> V_78 = 0 ;
ASSERT ( V_25 -> V_199 == NULL ) ;
if ( ! V_281 &&
( F_129 ( V_25 -> V_188 . V_235 ) ==
V_282 ) ) {
V_281 = 1 ;
} else {
V_281 = 2 ;
}
V_25 -> V_188 . V_235 = 0 ;
memset ( V_25 -> V_188 . V_283 , 0 ,
sizeof( V_25 -> V_188 . V_283 ) ) ;
V_25 -> V_188 . V_221 = 0 ;
} else if ( V_25 -> V_36 == V_38 )
;
else
break;
V_25 = V_25 -> V_79 ;
} while ( V_25 != log -> V_77 );
if ( V_281 ) {
switch ( log -> V_127 ) {
case V_130 :
case V_131 :
case V_132 :
log -> V_127 = V_131 ;
break;
case V_128 :
if ( V_281 == 1 )
log -> V_127 = V_132 ;
else
log -> V_127 = V_131 ;
break;
case V_129 :
if ( V_281 == 1 )
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
F_144 (
T_11 * log )
{
T_12 * V_284 ;
T_5 V_285 , V_28 ;
V_284 = log -> V_77 ;
V_285 = 0 ;
do {
if ( ! ( V_284 -> V_36 & ( V_38 | V_99 ) ) ) {
V_28 = F_119 ( V_284 -> V_188 . V_221 ) ;
if ( ( V_28 && ! V_285 ) ||
( F_106 ( V_28 , V_285 ) < 0 ) ) {
V_285 = V_28 ;
}
}
V_284 = V_284 -> V_79 ;
} while ( V_284 != log -> V_77 );
return V_285 ;
}
STATIC void
F_145 (
T_11 * log ,
int V_142 ,
T_12 * V_286 )
{
T_12 * V_25 ;
T_12 * V_75 ;
T_6 * V_33 , * V_40 ;
int V_287 = 0 ;
T_5 V_285 ;
int V_288 ;
int V_289 ;
int V_290 ;
int V_291 ;
int V_292 = 0 ;
F_18 ( & log -> V_97 ) ;
V_75 = V_25 = log -> V_77 ;
V_288 = 0 ;
V_290 = 0 ;
V_291 = 0 ;
do {
V_75 = log -> V_77 ;
V_25 = log -> V_77 ;
V_289 = 0 ;
V_291 ++ ;
do {
if ( V_25 -> V_36 &
( V_38 | V_99 ) ) {
V_25 = V_25 -> V_79 ;
continue;
}
if ( ! ( V_25 -> V_36 & V_37 ) ) {
if ( ! ( V_25 -> V_36 &
( V_293 |
V_294 ) ) ) {
if ( V_286 && ( V_286 -> V_36 ==
V_293 ) ) {
V_286 -> V_36 = V_294 ;
}
break;
}
V_285 = F_144 ( log ) ;
if ( V_285 &&
F_106 ( V_285 ,
F_119 ( V_25 -> V_188 . V_221 ) ) < 0 ) {
V_25 = V_25 -> V_79 ;
continue;
}
V_25 -> V_36 = V_295 ;
ASSERT ( F_106 ( F_2 ( & log -> V_117 ) ,
F_119 ( V_25 -> V_188 . V_221 ) ) <= 0 ) ;
F_59 ( & log -> V_117 ,
F_119 ( V_25 -> V_188 . V_221 ) ) ;
} else
V_288 ++ ;
F_20 ( & log -> V_97 ) ;
F_18 ( & V_25 -> V_35 ) ;
V_33 = V_25 -> V_199 ;
while ( V_33 ) {
V_25 -> V_41 = & ( V_25 -> V_199 ) ;
V_25 -> V_199 = NULL ;
F_20 ( & V_25 -> V_35 ) ;
for (; V_33 ; V_33 = V_40 ) {
V_40 = V_33 -> V_40 ;
V_33 -> V_296 ( V_33 -> V_297 , V_142 ) ;
}
F_18 ( & V_25 -> V_35 ) ;
V_33 = V_25 -> V_199 ;
}
V_289 ++ ;
V_290 ++ ;
F_18 ( & log -> V_97 ) ;
ASSERT ( V_25 -> V_199 == NULL ) ;
F_20 ( & V_25 -> V_35 ) ;
if ( ! ( V_25 -> V_36 & V_37 ) )
V_25 -> V_36 = V_99 ;
F_143 ( log ) ;
F_146 ( & V_25 -> V_100 ) ;
V_25 = V_25 -> V_79 ;
} while ( V_75 != V_25 );
if ( V_291 > 5000 ) {
V_287 += V_291 ;
V_291 = 0 ;
F_38 ( log -> V_137 ,
L_89 ,
V_96 , V_287 ) ;
}
} while ( ! V_288 && V_289 );
#ifdef F_46
if ( V_290 ) {
V_75 = V_25 = log -> V_77 ;
do {
ASSERT ( V_25 -> V_36 != V_294 ) ;
if ( V_25 -> V_36 == V_39 ||
V_25 -> V_36 == V_298 ||
V_25 -> V_36 == V_293 ||
V_25 -> V_36 == V_37 )
break;
V_25 = V_25 -> V_79 ;
} while ( V_75 != V_25 );
}
#endif
if ( log -> V_77 -> V_36 & ( V_38 | V_37 ) )
V_292 = 1 ;
F_20 ( & log -> V_97 ) ;
if ( V_292 )
F_146 ( & log -> V_179 ) ;
}
STATIC void
F_82 (
T_12 * V_25 ,
int V_142 )
{
T_11 * log = V_25 -> V_141 ;
F_18 ( & log -> V_97 ) ;
ASSERT ( V_25 -> V_36 == V_298 ||
V_25 -> V_36 == V_37 ) ;
ASSERT ( F_113 ( & V_25 -> V_98 ) == 0 ) ;
ASSERT ( V_25 -> V_223 == 1 || V_25 -> V_223 == 2 ) ;
if ( V_25 -> V_36 != V_37 ) {
if ( -- V_25 -> V_223 == 1 ) {
F_20 ( & log -> V_97 ) ;
return;
}
V_25 -> V_36 = V_293 ;
}
F_146 ( & V_25 -> V_201 ) ;
F_20 ( & log -> V_97 ) ;
F_145 ( log , V_142 , V_25 ) ;
}
STATIC int
F_140 ( T_11 * log ,
int V_14 ,
T_12 * * V_163 ,
T_3 * V_23 ,
int * V_299 ,
int * V_300 )
{
int V_273 ;
T_16 * V_1 ;
T_12 * V_25 ;
int error ;
V_301:
F_18 ( & log -> V_97 ) ;
if ( F_10 ( log ) ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
V_25 = log -> V_77 ;
if ( V_25 -> V_36 != V_38 ) {
F_26 ( V_302 ) ;
F_52 ( & log -> V_179 , & log -> V_97 ) ;
goto V_301;
}
V_1 = & V_25 -> V_188 ;
F_50 ( & V_25 -> V_98 ) ;
V_273 = V_25 -> V_78 ;
if ( V_273 == 0 ) {
V_23 -> V_242 -= log -> V_156 ;
F_8 ( V_23 ,
log -> V_156 ,
V_303 ) ;
V_1 -> V_304 = F_95 ( log -> V_171 ) ;
V_1 -> V_221 = F_147 (
F_105 ( log -> V_171 , log -> V_305 ) ) ;
ASSERT ( log -> V_305 >= 0 ) ;
}
if ( V_25 -> V_198 - V_25 -> V_78 < 2 * sizeof( V_237 ) ) {
F_148 ( log , V_25 , V_25 -> V_198 ) ;
if ( ! F_149 ( & V_25 -> V_98 , - 1 , 1 ) ) {
F_20 ( & log -> V_97 ) ;
error = F_22 ( log , V_25 ) ;
if ( error )
return error ;
} else {
F_20 ( & log -> V_97 ) ;
}
goto V_301;
}
if ( V_14 <= V_25 -> V_198 - V_25 -> V_78 ) {
* V_299 = 0 ;
V_25 -> V_78 += V_14 ;
} else {
* V_299 = 1 ;
F_148 ( log , V_25 , V_25 -> V_198 ) ;
}
* V_163 = V_25 ;
ASSERT ( V_25 -> V_78 <= V_25 -> V_198 ) ;
F_20 ( & log -> V_97 ) ;
* V_300 = V_273 ;
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
F_150 ( log , V_10 ) ;
V_115 = V_10 -> V_55 ;
if ( V_10 -> V_29 & V_53 )
V_115 *= V_10 -> V_306 ;
if ( ! F_60 ( & log -> V_123 ) ) {
F_18 ( & log -> V_124 ) ;
if ( F_151 ( & log -> V_123 ) ) {
F_20 ( & log -> V_124 ) ;
goto V_307;
}
F_152 ( & V_10 -> V_308 , & log -> V_123 ) ;
F_153 ( log , V_10 ) ;
if ( F_10 ( log ) )
goto V_309;
F_26 ( V_310 ) ;
F_52 ( & V_10 -> V_122 , & log -> V_124 ) ;
F_154 ( log , V_10 ) ;
}
V_307:
if ( F_10 ( log ) )
goto V_311;
V_116 = F_62 ( log , & log -> V_125 ) ;
if ( V_116 < V_115 ) {
F_18 ( & log -> V_124 ) ;
if ( F_151 ( & V_10 -> V_308 ) )
F_152 ( & V_10 -> V_308 , & log -> V_123 ) ;
F_155 ( log , V_10 ) ;
if ( F_10 ( log ) )
goto V_309;
F_28 ( log , V_115 ) ;
F_26 ( V_310 ) ;
F_52 ( & V_10 -> V_122 , & log -> V_124 ) ;
F_156 ( log , V_10 ) ;
goto V_307;
}
if ( ! F_151 ( & V_10 -> V_308 ) ) {
F_18 ( & log -> V_124 ) ;
F_157 ( & V_10 -> V_308 ) ;
F_20 ( & log -> V_124 ) ;
}
F_6 ( log , & log -> V_125 , V_115 ) ;
F_6 ( log , & log -> V_121 , V_115 ) ;
F_158 ( log , V_10 ) ;
F_159 ( log ) ;
return 0 ;
V_311:
F_18 ( & log -> V_124 ) ;
V_309:
F_157 ( & V_10 -> V_308 ) ;
F_20 ( & log -> V_124 ) ;
F_160 ( log , V_10 ) ;
V_10 -> V_242 = 0 ;
V_10 -> V_60 = 0 ;
return F_25 ( V_43 ) ;
}
STATIC int
F_29 ( T_11 * log ,
T_3 * V_10 )
{
int V_116 , V_115 ;
V_10 -> V_242 = V_10 -> V_55 ;
F_7 ( V_10 ) ;
if ( V_10 -> V_60 > 0 )
return 0 ;
#ifdef F_46
if ( log -> V_73 & V_74 )
F_61 ( L_91 ) ;
#endif
F_161 ( log , V_10 ) ;
if ( F_10 ( log ) )
goto V_311;
V_115 = V_10 -> V_55 ;
if ( ! F_60 ( & log -> V_119 ) ) {
struct V_22 * V_312 ;
F_18 ( & log -> V_120 ) ;
V_116 = F_62 ( log , & log -> V_121 ) ;
F_63 (ntic, &log->l_writeq, t_queue) {
ASSERT ( V_312 -> V_29 & V_31 ) ;
if ( V_116 < V_312 -> V_55 )
break;
V_116 -= V_312 -> V_55 ;
F_65 ( & V_312 -> V_122 ) ;
}
if ( V_312 != F_162 ( & log -> V_119 ,
struct V_22 , V_308 ) ) {
if ( F_151 ( & V_10 -> V_308 ) )
F_152 ( & V_10 -> V_308 , & log -> V_119 ) ;
F_163 ( log , V_10 ) ;
F_28 ( log , V_115 ) ;
F_26 ( V_310 ) ;
F_52 ( & V_10 -> V_122 , & log -> V_120 ) ;
F_164 ( log , V_10 ) ;
} else
F_20 ( & log -> V_120 ) ;
}
V_307:
if ( F_10 ( log ) )
goto V_311;
V_116 = F_62 ( log , & log -> V_121 ) ;
if ( V_116 < V_115 ) {
F_18 ( & log -> V_120 ) ;
if ( F_151 ( & V_10 -> V_308 ) )
F_152 ( & V_10 -> V_308 , & log -> V_119 ) ;
if ( F_10 ( log ) )
goto V_309;
F_28 ( log , V_115 ) ;
F_26 ( V_310 ) ;
F_165 ( log , V_10 ) ;
F_52 ( & V_10 -> V_122 , & log -> V_120 ) ;
F_166 ( log , V_10 ) ;
goto V_307;
}
if ( ! F_151 ( & V_10 -> V_308 ) ) {
F_18 ( & log -> V_120 ) ;
F_157 ( & V_10 -> V_308 ) ;
F_20 ( & log -> V_120 ) ;
}
F_6 ( log , & log -> V_121 , V_115 ) ;
F_167 ( log , V_10 ) ;
F_159 ( log ) ;
return 0 ;
V_311:
F_18 ( & log -> V_120 ) ;
V_309:
F_157 ( & V_10 -> V_308 ) ;
F_20 ( & log -> V_120 ) ;
F_168 ( log , V_10 ) ;
V_10 -> V_242 = 0 ;
V_10 -> V_60 = 0 ;
return F_25 ( V_43 ) ;
}
STATIC void
F_16 ( T_11 * log ,
T_3 * V_23 )
{
F_169 ( log , V_23 ) ;
if ( V_23 -> V_60 > 0 )
V_23 -> V_60 -- ;
F_1 ( log , & log -> V_125 ,
V_23 -> V_242 ) ;
F_1 ( log , & log -> V_121 ,
V_23 -> V_242 ) ;
V_23 -> V_242 = V_23 -> V_55 ;
F_7 ( V_23 ) ;
F_170 ( log , V_23 ) ;
if ( V_23 -> V_60 > 0 )
return;
F_6 ( log , & log -> V_125 ,
V_23 -> V_55 ) ;
F_171 ( log , V_23 ) ;
V_23 -> V_242 = V_23 -> V_55 ;
F_7 ( V_23 ) ;
}
STATIC void
F_13 ( T_11 * log ,
T_3 * V_23 )
{
int V_2 ;
if ( V_23 -> V_60 > 0 )
V_23 -> V_60 -- ;
F_172 ( log , V_23 ) ;
F_173 ( log , V_23 ) ;
V_2 = V_23 -> V_242 ;
if ( V_23 -> V_60 > 0 ) {
ASSERT ( V_23 -> V_29 & V_31 ) ;
V_2 += V_23 -> V_55 * V_23 -> V_60 ;
}
F_1 ( log , & log -> V_125 , V_2 ) ;
F_1 ( log , & log -> V_121 , V_2 ) ;
F_174 ( log , V_23 ) ;
F_58 ( log -> V_137 , 1 ) ;
}
STATIC int
F_22 (
T_11 * log ,
T_12 * V_25 )
{
int V_313 = 0 ;
if ( V_25 -> V_36 & V_37 )
return F_25 ( V_43 ) ;
ASSERT ( F_113 ( & V_25 -> V_98 ) > 0 ) ;
if ( ! F_175 ( & V_25 -> V_98 , & log -> V_97 ) )
return 0 ;
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
ASSERT ( V_25 -> V_36 == V_38 ||
V_25 -> V_36 == V_39 ) ;
if ( V_25 -> V_36 == V_39 ) {
T_5 V_114 = F_71 ( log -> V_137 ) ;
V_313 ++ ;
V_25 -> V_36 = V_298 ;
V_25 -> V_188 . V_314 = F_147 ( V_114 ) ;
F_176 ( log , V_25 , V_114 ) ;
}
F_20 ( & log -> V_97 ) ;
if ( V_313 )
return F_112 ( log , V_25 ) ;
return 0 ;
}
STATIC void
F_148 ( T_11 * log ,
T_12 * V_25 ,
int V_315 )
{
ASSERT ( V_25 -> V_36 == V_38 ) ;
if ( ! V_315 )
V_315 = V_25 -> V_78 ;
V_25 -> V_36 = V_39 ;
V_25 -> V_188 . V_316 = F_95 ( log -> V_170 ) ;
log -> V_170 = log -> V_305 ;
log -> V_317 = log -> V_171 ;
log -> V_305 += F_102 ( V_315 ) + F_102 ( log -> V_156 ) ;
if ( F_84 ( & log -> V_137 -> V_154 ) &&
log -> V_137 -> V_154 . V_219 > 1 ) {
T_14 V_318 = F_102 ( log -> V_137 -> V_154 . V_219 ) ;
log -> V_305 = F_177 ( log -> V_305 , V_318 ) ;
}
if ( log -> V_305 >= log -> V_169 ) {
log -> V_171 ++ ;
if ( log -> V_171 == V_190 )
log -> V_171 ++ ;
log -> V_305 -= log -> V_169 ;
ASSERT ( log -> V_305 >= 0 ) ;
}
ASSERT ( V_25 == log -> V_77 ) ;
log -> V_77 = V_25 -> V_79 ;
}
int
F_47 (
struct V_20 * V_21 ,
T_4 V_26 ,
int * V_319 )
{
struct log * log = V_21 -> V_27 ;
struct V_24 * V_25 ;
T_5 V_28 ;
F_26 ( V_320 ) ;
if ( log -> V_277 )
F_178 ( log ) ;
F_18 ( & log -> V_97 ) ;
V_25 = log -> V_77 ;
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
if ( V_25 -> V_36 == V_38 ||
V_25 -> V_36 == V_99 ) {
if ( V_25 -> V_36 == V_99 ||
( F_113 ( & V_25 -> V_98 ) == 0
&& V_25 -> V_78 == 0 ) ) {
V_25 = V_25 -> V_182 ;
if ( V_25 -> V_36 == V_38 ||
V_25 -> V_36 == V_99 )
goto V_321;
else
goto V_322;
} else {
if ( F_113 ( & V_25 -> V_98 ) == 0 ) {
F_50 ( & V_25 -> V_98 ) ;
V_28 = F_119 ( V_25 -> V_188 . V_221 ) ;
F_148 ( log , V_25 , 0 ) ;
F_20 ( & log -> V_97 ) ;
if ( F_22 ( log , V_25 ) )
return F_25 ( V_43 ) ;
if ( V_319 )
* V_319 = 1 ;
F_18 ( & log -> V_97 ) ;
if ( F_119 ( V_25 -> V_188 . V_221 ) == V_28 &&
V_25 -> V_36 != V_99 )
goto V_322;
else
goto V_321;
} else {
F_148 ( log , V_25 , 0 ) ;
goto V_322;
}
}
}
V_322:
if ( V_26 & V_76 ) {
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
F_26 ( V_323 ) ;
F_52 ( & V_25 -> V_100 , & log -> V_97 ) ;
if ( V_25 -> V_36 & V_37 )
return F_25 ( V_43 ) ;
if ( V_319 )
* V_319 = 1 ;
} else {
V_321:
F_20 ( & log -> V_97 ) ;
}
return 0 ;
}
void
F_179 (
T_8 * V_21 ,
T_4 V_26 )
{
int error ;
error = F_47 ( V_21 , V_26 , NULL ) ;
if ( error )
F_38 ( V_21 , L_92 , V_96 , error ) ;
}
int
F_180 (
struct V_20 * V_21 ,
T_5 V_28 ,
T_4 V_26 ,
int * V_319 )
{
struct log * log = V_21 -> V_27 ;
struct V_24 * V_25 ;
int V_324 = 0 ;
ASSERT ( V_28 != 0 ) ;
F_26 ( V_320 ) ;
if ( log -> V_277 ) {
V_28 = F_181 ( log , V_28 ) ;
if ( V_28 == V_325 )
return 0 ;
}
V_326:
F_18 ( & log -> V_97 ) ;
V_25 = log -> V_77 ;
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
do {
if ( F_119 ( V_25 -> V_188 . V_221 ) != V_28 ) {
V_25 = V_25 -> V_79 ;
continue;
}
if ( V_25 -> V_36 == V_99 ) {
F_20 ( & log -> V_97 ) ;
return 0 ;
}
if ( V_25 -> V_36 == V_38 ) {
if ( ! V_324 &&
( V_25 -> V_182 -> V_36 &
( V_39 | V_298 ) ) ) {
ASSERT ( ! ( V_25 -> V_36 & V_37 ) ) ;
F_26 ( V_323 ) ;
F_52 ( & V_25 -> V_182 -> V_201 ,
& log -> V_97 ) ;
if ( V_319 )
* V_319 = 1 ;
V_324 = 1 ;
goto V_326;
}
F_50 ( & V_25 -> V_98 ) ;
F_148 ( log , V_25 , 0 ) ;
F_20 ( & log -> V_97 ) ;
if ( F_22 ( log , V_25 ) )
return F_25 ( V_43 ) ;
if ( V_319 )
* V_319 = 1 ;
F_18 ( & log -> V_97 ) ;
}
if ( ( V_26 & V_76 ) &&
! ( V_25 -> V_36 &
( V_38 | V_99 ) ) ) {
if ( V_25 -> V_36 & V_37 ) {
F_20 ( & log -> V_97 ) ;
return F_25 ( V_43 ) ;
}
F_26 ( V_323 ) ;
F_52 ( & V_25 -> V_100 , & log -> V_97 ) ;
if ( V_25 -> V_36 & V_37 )
return F_25 ( V_43 ) ;
if ( V_319 )
* V_319 = 1 ;
} else {
F_20 ( & log -> V_97 ) ;
}
return 0 ;
} while ( V_25 != log -> V_77 );
F_20 ( & log -> V_97 ) ;
return 0 ;
}
void
F_182 (
T_8 * V_21 ,
T_5 V_28 ,
T_4 V_26 )
{
int error ;
error = F_180 ( V_21 , V_28 , V_26 , NULL ) ;
if ( error )
F_38 ( V_21 , L_92 , V_96 , error ) ;
}
STATIC void
F_51 ( T_11 * log , T_12 * V_25 )
{
F_183 ( & log -> V_97 ) ;
if ( V_25 -> V_36 == V_38 ) {
F_148 ( log , V_25 , 0 ) ;
} else {
ASSERT ( V_25 -> V_36 &
( V_39 | V_37 ) ) ;
}
}
void
F_14 (
T_3 * V_23 )
{
ASSERT ( F_113 ( & V_23 -> V_327 ) > 0 ) ;
if ( F_184 ( & V_23 -> V_327 ) )
F_185 ( V_328 , V_23 ) ;
}
T_3 *
F_186 (
T_3 * V_23 )
{
ASSERT ( F_113 ( & V_23 -> V_327 ) > 0 ) ;
F_50 ( & V_23 -> V_327 ) ;
return V_23 ;
}
T_3 *
F_30 (
struct log * log ,
int V_44 ,
int V_45 ,
char V_46 ,
T_4 V_329 ,
int V_330 )
{
struct V_22 * V_10 ;
T_4 V_331 ;
int V_332 ;
V_10 = F_187 ( V_328 , V_330 ) ;
if ( ! V_10 )
return NULL ;
V_44 += sizeof( V_237 ) ;
V_44 += sizeof( V_333 ) ;
V_44 += sizeof( V_237 ) ;
V_332 = log -> V_152 - log -> V_156 ;
V_331 = F_188 ( V_44 , V_332 ) ;
V_44 += sizeof( V_237 ) * V_331 ;
while ( ! V_331 ||
F_188 ( V_44 , V_332 ) > V_331 ) {
V_44 += sizeof( V_237 ) ;
V_331 ++ ;
}
V_44 += log -> V_156 * V_331 ;
V_44 += log -> V_156 ;
if ( F_84 ( & log -> V_137 -> V_154 ) &&
log -> V_137 -> V_154 . V_219 > 1 ) {
V_44 += 2 * log -> V_137 -> V_154 . V_219 ;
} else {
V_44 += 2 * V_160 ;
}
F_96 ( & V_10 -> V_327 , 1 ) ;
F_56 ( & V_10 -> V_308 ) ;
V_10 -> V_55 = V_44 ;
V_10 -> V_242 = V_44 ;
V_10 -> V_60 = V_45 ;
V_10 -> V_306 = V_45 ;
V_10 -> V_54 = F_189 () ;
V_10 -> V_254 = V_46 ;
V_10 -> V_29 = V_30 ;
V_10 -> V_59 = 0 ;
if ( V_329 & V_53 )
V_10 -> V_29 |= V_31 ;
F_92 ( & V_10 -> V_122 ) ;
F_7 ( V_10 ) ;
return V_10 ;
}
void
F_142 (
struct log * log ,
char * V_278 )
{
int V_165 ;
int V_334 = 0 ;
for ( V_165 = 0 ; V_165 < log -> V_149 ; V_165 ++ ) {
if ( V_278 >= log -> V_186 [ V_165 ] &&
V_278 <= log -> V_186 [ V_165 ] + log -> V_152 )
V_334 ++ ;
}
if ( ! V_334 )
F_190 ( log -> V_137 , L_93 , V_96 ) ;
}
STATIC void
F_159 (
struct log * log )
{
int V_134 , V_335 ;
int V_6 , V_7 ;
F_72 ( & log -> V_121 , & V_6 , & V_7 ) ;
F_73 ( & log -> V_118 , & V_134 , & V_335 ) ;
if ( V_134 != V_6 ) {
if ( V_6 - 1 != V_134 &&
! ( log -> V_73 & V_336 ) ) {
F_134 ( log -> V_137 , V_243 ,
L_94 , V_96 ) ;
log -> V_73 |= V_336 ;
}
if ( V_7 > F_74 ( V_335 ) &&
! ( log -> V_73 & V_336 ) ) {
F_134 ( log -> V_137 , V_243 ,
L_95 , V_96 ) ;
log -> V_73 |= V_336 ;
}
}
}
STATIC void
F_176 ( T_11 * log ,
T_12 * V_25 ,
T_5 V_114 )
{
int V_337 ;
if ( F_191 ( V_114 ) == log -> V_317 ) {
V_337 =
log -> V_169 - ( log -> V_170 - F_118 ( V_114 ) ) ;
if ( V_337 < F_102 ( V_25 -> V_78 ) + F_102 ( log -> V_156 ) )
F_190 ( log -> V_137 , L_96 , V_96 ) ;
} else {
ASSERT ( F_191 ( V_114 ) + 1 == log -> V_317 ) ;
if ( F_118 ( V_114 ) == log -> V_170 )
F_190 ( log -> V_137 , L_97 , V_96 ) ;
V_337 = F_118 ( V_114 ) - log -> V_170 ;
if ( V_337 < F_102 ( V_25 -> V_78 ) + 1 )
F_190 ( log -> V_137 , L_96 , V_96 ) ;
}
}
STATIC void
F_125 ( T_11 * log ,
T_12 * V_25 ,
int V_213 ,
T_17 V_338 )
{
V_237 * V_339 ;
T_12 * V_340 ;
T_18 * V_341 ;
V_187 V_278 ;
V_187 V_342 ;
T_19 V_343 ;
T_7 V_344 ;
int V_14 , V_165 , V_345 , V_346 , V_347 ;
int V_348 ;
F_18 ( & log -> V_97 ) ;
V_340 = log -> V_77 ;
for ( V_165 = 0 ; V_165 < log -> V_149 ; V_165 ++ ) {
if ( V_340 == NULL )
F_190 ( log -> V_137 , L_93 , V_96 ) ;
V_340 = V_340 -> V_79 ;
}
if ( V_340 != log -> V_77 )
F_190 ( log -> V_137 , L_98 , V_96 ) ;
F_20 ( & log -> V_97 ) ;
if ( V_25 -> V_188 . V_189 != F_95 ( V_190 ) )
F_190 ( log -> V_137 , L_99 , V_96 ) ;
V_278 = ( V_187 ) & V_25 -> V_188 ;
for ( V_278 += V_160 ; V_278 < ( ( V_187 ) & V_25 -> V_188 ) + V_213 ;
V_278 += V_160 ) {
if ( * ( V_231 * ) V_278 == F_95 ( V_190 ) )
F_190 ( log -> V_137 , L_100 ,
V_96 ) ;
}
V_14 = F_129 ( V_25 -> V_188 . V_235 ) ;
V_278 = V_25 -> V_200 ;
V_342 = V_278 ;
V_339 = ( V_237 * ) V_278 ;
V_341 = V_25 -> V_184 ;
for ( V_165 = 0 ; V_165 < V_14 ; V_165 ++ ) {
V_339 = ( V_237 * ) V_278 ;
V_343 = ( T_19 )
( ( V_187 ) & ( V_339 -> V_253 ) - V_342 ) ;
if ( V_338 == V_349 || ( V_343 & 0x1ff ) ) {
V_344 = V_339 -> V_253 ;
} else {
V_348 = F_103 ( ( V_187 ) & ( V_339 -> V_253 ) - V_25 -> V_200 ) ;
if ( V_348 >= ( V_155 / V_160 ) ) {
V_345 = V_348 / ( V_155 / V_160 ) ;
V_346 = V_348 % ( V_155 / V_160 ) ;
V_344 = F_192 (
V_341 [ V_345 ] . V_350 . V_351 [ V_346 ] ) ;
} else {
V_344 = F_192 (
V_25 -> V_188 . V_283 [ V_348 ] ) ;
}
}
if ( V_344 != V_50 && V_344 != V_51 )
F_38 ( log -> V_137 ,
L_101 ,
V_96 , V_344 , V_339 ,
( unsigned long ) V_343 ) ;
V_343 = ( T_19 )
( ( V_187 ) & ( V_339 -> V_255 ) - V_342 ) ;
if ( V_338 == V_349 || ( V_343 & 0x1ff ) ) {
V_347 = F_129 ( V_339 -> V_255 ) ;
} else {
V_348 = F_103 ( ( T_19 ) & V_339 -> V_255 -
( T_19 ) V_25 -> V_200 ) ;
if ( V_348 >= ( V_155 / V_160 ) ) {
V_345 = V_348 / ( V_155 / V_160 ) ;
V_346 = V_348 % ( V_155 / V_160 ) ;
V_347 = F_129 ( V_341 [ V_345 ] . V_350 . V_351 [ V_346 ] ) ;
} else {
V_347 = F_129 ( V_25 -> V_188 . V_283 [ V_348 ] ) ;
}
}
V_278 += sizeof( V_237 ) + V_347 ;
}
}
STATIC int
F_193 (
T_11 * log )
{
T_12 * V_25 , * V_352 ;
V_25 = log -> V_77 ;
if ( ! ( V_25 -> V_36 & V_37 ) ) {
V_352 = V_25 ;
do {
V_352 -> V_36 = V_37 ;
V_352 = V_352 -> V_79 ;
} while ( V_352 != V_25 );
return 0 ;
}
return 1 ;
}
int
F_194 (
struct V_20 * V_21 ,
int V_353 )
{
T_3 * V_10 ;
T_11 * log ;
int V_49 ;
log = V_21 -> V_27 ;
if ( ! log ||
log -> V_73 & V_74 ) {
V_21 -> V_64 |= V_354 ;
if ( V_21 -> V_355 )
F_195 ( V_21 -> V_355 ) ;
return 0 ;
}
if ( V_353 && log -> V_77 -> V_36 & V_37 ) {
ASSERT ( F_10 ( log ) ) ;
return 1 ;
}
V_49 = 0 ;
if ( ! V_353 && ( V_21 -> V_64 & V_356 ) )
F_178 ( log ) ;
F_18 ( & log -> V_97 ) ;
V_21 -> V_64 |= V_354 ;
if ( V_21 -> V_355 )
F_195 ( V_21 -> V_355 ) ;
log -> V_73 |= V_357 ;
if ( V_353 )
V_49 = F_193 ( log ) ;
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
ASSERT ( ! V_353 ) ;
F_47 ( V_21 , V_76 , NULL ) ;
F_18 ( & log -> V_97 ) ;
V_49 = F_193 ( log ) ;
F_20 ( & log -> V_97 ) ;
}
F_145 ( log , V_145 , NULL ) ;
#ifdef F_196
{
T_12 * V_25 ;
F_18 ( & log -> V_97 ) ;
V_25 = log -> V_77 ;
do {
ASSERT ( V_25 -> V_199 == 0 ) ;
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
if ( V_25 -> V_188 . V_235 )
return 0 ;
V_25 = V_25 -> V_79 ;
} while ( V_25 != log -> V_77 );
return 1 ;
}
