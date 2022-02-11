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
bool V_48 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_15 * V_16 ;
int V_24 ;
int error = 0 ;
ASSERT ( V_47 == V_49 || V_47 == V_50 ) ;
if ( F_26 ( log ) )
return - V_39 ;
F_27 ( V_37 , V_40 ) ;
ASSERT ( * V_46 == NULL ) ;
V_16 = F_33 ( log , V_44 , V_45 , V_47 , V_48 ,
V_51 | V_52 ) ;
if ( ! V_16 )
return - V_53 ;
* V_46 = V_16 ;
F_28 ( log , V_16 -> V_22 ? V_16 -> V_21 * V_16 -> V_22
: V_16 -> V_21 ) ;
F_34 ( log , V_16 ) ;
error = F_20 ( log , & log -> V_54 , V_16 ,
& V_24 ) ;
if ( error )
goto V_43;
F_6 ( log , & log -> V_54 . V_12 , V_24 ) ;
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
struct V_15 * V_55 ,
struct V_56 * * V_57 ,
bool V_58 )
{
struct V_1 * log = V_37 -> V_38 ;
T_6 V_59 = 0 ;
if ( F_26 ( log ) ||
( ( ( V_55 -> V_19 & V_60 ) == 0 ) &&
( F_37 ( log , V_55 , V_57 , & V_59 ) ) ) ) {
V_59 = ( T_6 ) - 1 ;
V_58 = false ;
}
if ( ! V_58 ) {
F_38 ( log , V_55 ) ;
F_39 ( log , V_55 ) ;
} else {
F_40 ( log , V_55 ) ;
F_41 ( log , V_55 ) ;
V_55 -> V_19 |= V_60 ;
}
F_42 ( V_55 ) ;
return V_59 ;
}
int
F_43 (
struct V_36 * V_37 ,
struct V_56 * V_57 ,
T_7 * V_61 )
{
int V_62 ;
F_12 ( & V_57 -> V_63 ) ;
V_62 = ( V_57 -> V_64 & V_65 ) ;
if ( ! V_62 ) {
F_44 ( ( V_57 -> V_64 == V_66 ) ||
( V_57 -> V_64 == V_67 ) ) ;
V_61 -> V_68 = NULL ;
* ( V_57 -> V_69 ) = V_61 ;
V_57 -> V_69 = & ( V_61 -> V_68 ) ;
}
F_15 ( & V_57 -> V_63 ) ;
return V_62 ;
}
int
F_45 (
struct V_36 * V_37 ,
struct V_56 * V_57 )
{
if ( F_46 ( V_37 -> V_38 , V_57 ) ) {
F_47 ( V_37 , V_70 ) ;
return - V_39 ;
}
return 0 ;
}
int
F_48 (
T_8 * V_37 ,
T_9 * V_71 ,
T_10 V_72 ,
int V_73 )
{
int error = 0 ;
int V_74 ;
if ( ! ( V_37 -> V_75 & V_76 ) ) {
F_49 ( V_37 , L_1 ,
F_50 ( & V_37 -> V_77 ) ) ;
} else {
F_49 ( V_37 ,
L_2 ,
F_50 ( & V_37 -> V_77 ) ) ;
ASSERT ( V_37 -> V_75 & V_78 ) ;
}
V_37 -> V_38 = F_51 ( V_37 , V_71 , V_72 , V_73 ) ;
if ( F_52 ( V_37 -> V_38 ) ) {
error = F_53 ( V_37 -> V_38 ) ;
goto V_79;
}
V_74 = F_54 ( V_37 ) ;
if ( V_37 -> V_77 . V_80 < V_74 ) {
F_55 ( V_37 ,
L_3 ,
V_37 -> V_77 . V_80 , V_74 ) ;
error = - V_81 ;
} else if ( V_37 -> V_77 . V_80 > V_82 ) {
F_55 ( V_37 ,
L_4 ,
V_37 -> V_77 . V_80 , V_82 ) ;
error = - V_81 ;
} else if ( F_56 ( V_37 , V_37 -> V_77 . V_80 ) > V_83 ) {
F_55 ( V_37 ,
L_5 ,
F_56 ( V_37 , V_37 -> V_77 . V_80 ) ,
V_83 ) ;
error = - V_81 ;
}
if ( error ) {
if ( F_57 ( & V_37 -> V_77 ) ) {
F_58 ( V_37 , L_6 ) ;
ASSERT ( 0 ) ;
goto V_84;
}
F_58 ( V_37 , L_7 ) ;
F_58 ( V_37 ,
L_8 ) ;
}
error = F_59 ( V_37 ) ;
if ( error ) {
F_55 ( V_37 , L_9 , error ) ;
goto V_84;
}
V_37 -> V_38 -> V_85 = V_37 -> V_86 ;
if ( ! ( V_37 -> V_75 & V_76 ) ) {
int V_87 = ( V_37 -> V_75 & V_78 ) ;
if ( V_87 )
V_37 -> V_75 &= ~ V_78 ;
error = F_60 ( V_37 -> V_38 ) ;
if ( V_87 )
V_37 -> V_75 |= V_78 ;
if ( error ) {
F_55 ( V_37 , L_10 ,
error ) ;
F_61 ( V_37 -> V_38 ) ;
goto V_88;
}
}
error = F_62 ( & V_37 -> V_38 -> V_89 , & V_90 , & V_37 -> V_91 ,
L_11 ) ;
if ( error )
goto V_88;
V_37 -> V_38 -> V_25 &= ~ V_26 ;
F_63 ( V_37 -> V_38 ) ;
return 0 ;
V_88:
F_64 ( V_37 ) ;
V_84:
F_65 ( V_37 -> V_38 ) ;
V_79:
return error ;
}
int
F_66 (
struct V_36 * V_37 )
{
int error = 0 ;
if ( V_37 -> V_75 & V_76 ) {
ASSERT ( V_37 -> V_75 & V_78 ) ;
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
T_11 * V_57 ;
#ifdef F_72
T_11 * V_92 ;
#endif
T_3 * V_16 = NULL ;
T_6 V_59 ;
int error ;
if ( V_37 -> V_75 & V_78 )
return 0 ;
error = F_73 ( V_37 , V_93 , NULL ) ;
ASSERT ( error || ! ( F_26 ( log ) ) ) ;
#ifdef F_72
V_92 = V_57 = log -> V_94 ;
do {
if ( ! ( V_57 -> V_64 & V_65 ) ) {
ASSERT ( V_57 -> V_64 & V_66 ) ;
ASSERT ( V_57 -> V_95 == 0 ) ;
}
V_57 = V_57 -> V_96 ;
} while ( V_57 != V_92 );
#endif
if ( ! ( F_26 ( log ) ) ) {
error = F_32 ( V_37 , 600 , 1 , & V_16 , V_50 , 0 ) ;
if ( ! error ) {
struct {
T_12 V_97 ;
T_12 V_98 ;
T_13 V_99 ;
} V_97 = {
. V_97 = V_100 ,
} ;
struct V_101 V_102 = {
. V_103 = & V_97 ,
. V_104 = sizeof( V_97 ) ,
. V_105 = V_106 ,
} ;
struct V_107 V_108 = {
. V_109 = 1 ,
. V_110 = & V_102 ,
} ;
V_16 -> V_19 = 0 ;
V_16 -> V_42 -= sizeof( V_97 ) ;
error = F_74 ( log , & V_108 , V_16 , & V_59 ,
NULL , V_111 ) ;
}
if ( error )
F_75 ( V_37 , L_12 , V_112 ) ;
F_12 ( & log -> V_113 ) ;
V_57 = log -> V_94 ;
F_76 ( & V_57 -> V_114 ) ;
F_77 ( log , V_57 ) ;
F_15 ( & log -> V_113 ) ;
error = F_46 ( log , V_57 ) ;
F_12 ( & log -> V_113 ) ;
if ( ! ( V_57 -> V_64 == V_66 ||
V_57 -> V_64 == V_115 ) ) {
if ( ! F_26 ( log ) ) {
F_78 ( & V_57 -> V_116 ,
& log -> V_113 ) ;
} else {
F_15 ( & log -> V_113 ) ;
}
} else {
F_15 ( & log -> V_113 ) ;
}
if ( V_16 ) {
F_79 ( log , V_16 ) ;
F_39 ( log , V_16 ) ;
F_42 ( V_16 ) ;
}
} else {
F_12 ( & log -> V_113 ) ;
V_57 = log -> V_94 ;
F_76 ( & V_57 -> V_114 ) ;
F_77 ( log , V_57 ) ;
F_15 ( & log -> V_113 ) ;
error = F_46 ( log , V_57 ) ;
F_12 ( & log -> V_113 ) ;
if ( ! ( V_57 -> V_64 == V_66
|| V_57 -> V_64 == V_115
|| V_57 -> V_64 == V_65 ) ) {
F_78 ( & V_57 -> V_116 ,
& log -> V_113 ) ;
} else {
F_15 ( & log -> V_113 ) ;
}
}
return error ;
}
void
F_80 (
struct V_36 * V_37 )
{
F_81 ( & V_37 -> V_38 -> V_117 ) ;
F_82 ( V_37 , V_93 ) ;
F_83 ( V_37 -> V_86 ) ;
F_84 ( V_37 -> V_118 ) ;
F_85 ( V_37 -> V_119 ) ;
F_86 ( V_37 -> V_119 ) ;
F_71 ( V_37 ) ;
}
void
F_70 (
struct V_36 * V_37 )
{
F_80 ( V_37 ) ;
F_64 ( V_37 ) ;
F_87 ( & V_37 -> V_38 -> V_89 ) ;
F_65 ( V_37 -> V_38 ) ;
}
void
F_88 (
struct V_36 * V_37 ,
struct V_120 * V_121 ,
int type ,
const struct V_122 * V_123 )
{
V_121 -> V_124 = V_37 ;
V_121 -> V_125 = V_37 -> V_86 ;
V_121 -> V_126 = type ;
V_121 -> V_127 = V_123 ;
V_121 -> V_128 = NULL ;
F_9 ( & V_121 -> V_129 ) ;
F_9 ( & V_121 -> V_130 ) ;
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
if ( ! F_22 ( & log -> V_54 . V_13 ) ) {
ASSERT ( ! ( log -> V_25 & V_26 ) ) ;
F_12 ( & log -> V_54 . V_14 ) ;
V_23 = F_21 ( log , & log -> V_54 . V_12 ) ;
F_17 ( log , & log -> V_54 , & V_23 ) ;
F_15 ( & log -> V_54 . V_14 ) ;
}
}
int
F_90 ( T_8 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_131 = 0 ;
if ( ! F_91 ( V_37 , V_132 ) )
return 0 ;
if ( ! F_92 ( log ) )
return 0 ;
F_12 ( & log -> V_113 ) ;
switch ( log -> V_133 ) {
case V_134 :
case V_135 :
case V_136 :
break;
case V_137 :
case V_138 :
if ( F_93 ( log -> V_85 ) )
break;
if ( ! F_94 ( log ) )
break;
V_131 = 1 ;
if ( log -> V_133 == V_137 )
log -> V_133 = V_134 ;
else
log -> V_133 = V_135 ;
break;
default:
V_131 = 1 ;
break;
}
F_15 ( & log -> V_113 ) ;
return V_131 ;
}
T_6
F_95 (
struct V_36 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_120 * V_139 ;
T_6 V_140 ;
F_96 ( & V_37 -> V_86 -> V_141 ) ;
V_139 = F_97 ( V_37 -> V_86 ) ;
if ( V_139 )
V_140 = V_139 -> V_142 ;
else
V_140 = F_2 ( & log -> V_143 ) ;
F_98 ( log , V_140 ) ;
F_99 ( & log -> V_144 , V_140 ) ;
return V_140 ;
}
T_6
F_100 (
struct V_36 * V_37 )
{
T_6 V_140 ;
F_12 ( & V_37 -> V_86 -> V_141 ) ;
V_140 = F_95 ( V_37 ) ;
F_15 ( & V_37 -> V_86 -> V_141 ) ;
return V_140 ;
}
STATIC int
F_21 (
struct V_1 * log ,
T_1 * V_2 )
{
int V_23 ;
int V_145 ;
int V_146 ;
int V_147 ;
int V_148 ;
F_101 ( V_2 , & V_147 , & V_148 ) ;
F_102 ( & log -> V_144 , & V_146 , & V_145 ) ;
V_145 = F_103 ( V_145 ) ;
if ( V_146 == V_147 && V_148 >= V_145 )
V_23 = log -> V_9 - ( V_148 - V_145 ) ;
else if ( V_146 + 1 < V_147 )
return 0 ;
else if ( V_146 < V_147 ) {
ASSERT ( V_146 == ( V_147 - 1 ) ) ;
V_23 = V_145 - V_148 ;
} else {
F_75 ( log -> V_149 , L_13 ) ;
F_75 ( log -> V_149 ,
L_14 ,
V_146 , V_145 ) ;
F_75 ( log -> V_149 ,
L_15 ,
V_147 , V_148 ) ;
ASSERT ( 0 ) ;
V_23 = log -> V_9 ;
}
return V_23 ;
}
void
F_104 ( T_14 * V_150 )
{
struct V_56 * V_57 = V_150 -> V_151 ;
struct V_1 * V_152 = V_57 -> V_153 ;
int V_154 = 0 ;
if ( F_105 ( V_150 -> V_155 , V_152 -> V_149 , V_156 ,
V_157 ) ||
V_57 -> V_64 & V_158 ) {
if ( V_57 -> V_64 & V_158 )
V_57 -> V_64 &= ~ V_158 ;
F_106 ( V_150 , V_112 ) ;
F_107 ( V_150 ) ;
F_47 ( V_152 -> V_149 , V_70 ) ;
V_154 = V_159 ;
} else if ( V_57 -> V_64 & V_65 ) {
V_154 = V_159 ;
}
ASSERT ( V_150 -> V_160 & V_161 ) ;
F_108 ( V_57 , V_154 ) ;
F_86 ( V_150 ) ;
}
STATIC void
F_109 (
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
if ( F_110 ( & V_37 -> V_77 ) ) {
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
F_111 ( V_37 -> V_178 , & V_37 -> V_38 -> V_117 ,
F_112 ( V_179 * 10 ) ) ;
}
void
F_113 (
struct V_180 * V_181 )
{
struct V_1 * log = F_114 ( F_115 ( V_181 ) ,
struct V_1 , V_117 ) ;
struct V_36 * V_37 = log -> V_149 ;
if ( F_90 ( V_37 ) ) {
F_116 ( V_37 , true ) ;
} else
F_82 ( V_37 , 0 ) ;
F_117 ( V_37 -> V_86 ) ;
F_68 ( V_37 ) ;
}
STATIC struct V_1 *
F_51 (
struct V_36 * V_37 ,
struct V_182 * V_71 ,
T_10 V_72 ,
int V_73 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_183 ;
T_11 * V_57 , * V_184 = NULL ;
T_14 * V_150 ;
int V_185 ;
int error = - V_53 ;
T_4 V_186 = 0 ;
log = F_118 ( sizeof( struct V_1 ) , V_52 ) ;
if ( ! log ) {
F_55 ( V_37 , L_16 ) ;
goto V_79;
}
log -> V_149 = V_37 ;
log -> V_187 = V_71 ;
log -> V_9 = F_103 ( V_73 ) ;
log -> V_188 = V_72 ;
log -> V_189 = V_73 ;
log -> V_133 = V_136 ;
log -> V_25 |= V_26 ;
F_119 ( & log -> V_117 , F_113 ) ;
log -> V_190 = - 1 ;
F_120 ( & log -> V_144 , 1 , 0 ) ;
F_120 ( & log -> V_143 , 1 , 0 ) ;
log -> V_191 = 1 ;
F_7 ( & log -> V_54 ) ;
F_7 ( & log -> V_18 ) ;
error = - V_192 ;
if ( F_121 ( & V_37 -> V_77 ) ) {
V_186 = V_37 -> V_77 . V_193 ;
if ( V_186 < V_172 ) {
F_55 ( V_37 , L_17 ,
V_186 , V_172 ) ;
goto V_84;
}
V_186 -= V_172 ;
if ( V_186 > V_37 -> V_194 ) {
F_55 ( V_37 , L_18 ,
V_186 , V_37 -> V_194 ) ;
goto V_84;
}
if ( V_186 && log -> V_188 > 0 &&
! F_110 ( & V_37 -> V_77 ) ) {
F_55 ( V_37 ,
L_19 ,
V_186 ) ;
goto V_84;
}
}
log -> V_195 = 1 << V_186 ;
F_109 ( V_37 , log ) ;
error = - V_53 ;
V_150 = F_122 ( V_37 -> V_196 , V_197 ,
F_123 ( log -> V_168 ) , 0 ) ;
if ( ! V_150 )
goto V_84;
ASSERT ( F_124 ( V_150 ) ) ;
F_86 ( V_150 ) ;
V_150 -> V_198 = V_37 -> V_178 ;
V_150 -> V_199 = F_104 ;
log -> V_200 = V_150 ;
F_10 ( & log -> V_113 ) ;
F_125 ( & log -> V_201 ) ;
V_183 = & log -> V_94 ;
ASSERT ( log -> V_168 >= 4096 ) ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
* V_183 = F_118 ( sizeof( T_11 ) , V_52 ) ;
if ( ! * V_183 )
goto V_202;
V_57 = * V_183 ;
V_57 -> V_203 = V_184 ;
V_184 = V_57 ;
V_150 = F_126 ( V_37 -> V_196 ,
F_123 ( log -> V_168 ) , 0 ) ;
if ( ! V_150 )
goto V_202;
ASSERT ( F_124 ( V_150 ) ) ;
F_86 ( V_150 ) ;
V_150 -> V_198 = V_37 -> V_178 ;
V_150 -> V_199 = F_104 ;
V_57 -> V_204 = V_150 ;
V_57 -> V_205 = V_150 -> V_206 ;
#ifdef F_72
log -> V_207 [ V_185 ] = & V_57 -> V_208 ;
#endif
V_2 = & V_57 -> V_208 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_209 = F_127 ( V_210 ) ;
V_2 -> V_211 = F_127 (
F_110 ( & log -> V_149 -> V_77 ) ? 2 : 1 ) ;
V_2 -> V_212 = F_127 ( log -> V_168 ) ;
V_2 -> V_213 = F_127 ( V_214 ) ;
memcpy ( & V_2 -> V_215 , & V_37 -> V_77 . V_216 , sizeof( V_217 ) ) ;
V_57 -> V_218 = F_103 ( V_150 -> V_219 ) - log -> V_171 ;
V_57 -> V_64 = V_66 ;
V_57 -> V_153 = log ;
F_128 ( & V_57 -> V_114 , 0 ) ;
F_10 ( & V_57 -> V_63 ) ;
V_57 -> V_69 = & ( V_57 -> V_220 ) ;
V_57 -> V_221 = ( char * ) V_57 -> V_205 + log -> V_171 ;
F_125 ( & V_57 -> V_116 ) ;
F_125 ( & V_57 -> V_222 ) ;
V_183 = & V_57 -> V_96 ;
}
* V_183 = log -> V_94 ;
log -> V_94 -> V_203 = V_184 ;
error = F_129 ( log ) ;
if ( error )
goto V_202;
return log ;
V_202:
for ( V_57 = log -> V_94 ; V_57 ; V_57 = V_184 ) {
V_184 = V_57 -> V_96 ;
if ( V_57 -> V_204 )
F_130 ( V_57 -> V_204 ) ;
F_131 ( V_57 ) ;
}
F_132 ( & log -> V_113 ) ;
F_130 ( log -> V_200 ) ;
V_84:
F_131 ( log ) ;
V_79:
return F_133 ( error ) ;
}
STATIC int
F_37 (
struct V_1 * log ,
struct V_15 * V_55 ,
struct V_56 * * V_57 ,
T_6 * V_223 )
{
struct V_36 * V_37 = log -> V_149 ;
int error ;
struct V_101 V_102 = {
. V_103 = NULL ,
. V_104 = 0 ,
. V_105 = V_224 ,
} ;
struct V_107 V_108 = {
. V_109 = 1 ,
. V_110 = & V_102 ,
} ;
F_44 ( V_57 ) ;
error = F_74 ( log , & V_108 , V_55 , V_223 , V_57 ,
V_225 ) ;
if ( error )
F_47 ( V_37 , V_70 ) ;
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
ASSERT ( F_123 ( V_24 ) < log -> V_189 ) ;
V_23 = F_21 ( log , & log -> V_54 . V_12 ) ;
V_228 = F_134 ( V_23 ) ;
V_231 = F_123 ( V_24 ) ;
V_231 = F_135 ( V_231 , ( log -> V_189 >> 2 ) ) ;
V_231 = F_135 ( V_231 , 256 ) ;
if ( V_228 >= V_231 )
return;
F_102 ( & log -> V_144 , & V_230 ,
& V_229 ) ;
V_229 += V_231 ;
if ( V_229 >= log -> V_189 ) {
V_229 -= log -> V_189 ;
V_230 += 1 ;
}
V_226 = F_136 ( V_230 ,
V_229 ) ;
V_227 = F_2 ( & log -> V_143 ) ;
if ( F_137 ( V_226 , V_227 ) > 0 )
V_226 = V_227 ;
if ( ! F_26 ( log ) )
F_138 ( log -> V_85 , V_226 ) ;
}
STATIC void
F_139 (
struct V_1 * log ,
struct V_56 * V_57 ,
int V_232 )
{
int V_185 , V_233 , V_234 ;
int V_162 = V_57 -> V_95 + V_232 ;
T_16 V_235 ;
char * V_236 ;
V_235 = F_140 ( V_57 -> V_208 . V_237 ) ;
V_236 = V_57 -> V_221 ;
for ( V_185 = 0 ; V_185 < F_123 ( V_162 ) ; V_185 ++ ) {
if ( V_185 >= ( V_170 / V_175 ) )
break;
V_57 -> V_208 . V_238 [ V_185 ] = * ( T_16 * ) V_236 ;
* ( T_16 * ) V_236 = V_235 ;
V_236 += V_175 ;
}
if ( F_110 ( & log -> V_149 -> V_77 ) ) {
T_17 * V_239 = V_57 -> V_205 ;
for ( ; V_185 < F_123 ( V_162 ) ; V_185 ++ ) {
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
F_141 (
struct V_1 * log ,
struct V_243 * V_244 ,
char * V_236 ,
int V_162 )
{
T_13 V_245 ;
V_245 = F_142 ( ( char * ) V_244 ,
sizeof( struct V_243 ) ,
F_143 ( struct V_243 , V_246 ) ) ;
if ( F_110 ( & log -> V_149 -> V_77 ) ) {
union V_247 * V_239 = (union V_247 * ) V_244 ;
int V_185 ;
int V_248 ;
V_248 = V_162 / V_170 ;
if ( V_162 % V_170 )
V_248 ++ ;
for ( V_185 = 1 ; V_185 < V_248 ; V_185 ++ ) {
V_245 = F_144 ( V_245 , & V_239 [ V_185 ] . V_240 ,
sizeof( struct V_249 ) ) ;
}
}
V_245 = F_144 ( V_245 , V_236 , V_162 ) ;
return F_145 ( V_245 ) ;
}
STATIC int
F_146 (
struct V_250 * V_150 )
{
struct V_56 * V_57 = V_150 -> V_151 ;
F_85 ( V_150 ) ;
if ( V_57 -> V_64 & V_65 ) {
F_147 ( V_150 , - V_39 ) ;
F_107 ( V_150 ) ;
F_148 ( V_150 ) ;
return 0 ;
}
F_149 ( V_150 ) ;
return 0 ;
}
STATIC int
F_150 (
struct V_1 * log ,
struct V_56 * V_57 )
{
T_14 * V_150 ;
int V_185 ;
T_4 V_251 ;
T_4 V_252 ;
int V_232 ;
int V_253 = 0 ;
int error ;
int V_254 = F_110 ( & log -> V_149 -> V_77 ) ;
int V_162 ;
F_27 ( log -> V_149 , V_255 ) ;
ASSERT ( F_151 ( & V_57 -> V_114 ) == 0 ) ;
V_252 = log -> V_171 + V_57 -> V_95 ;
if ( V_254 && log -> V_149 -> V_77 . V_256 > 1 ) {
V_251 = F_152 ( log , F_153 ( log , V_252 ) ) ;
} else {
V_251 = F_103 ( F_123 ( V_252 ) ) ;
}
V_232 = V_251 - V_252 ;
ASSERT ( V_232 >= 0 ) ;
ASSERT ( ( V_254 && log -> V_149 -> V_77 . V_256 > 1 &&
V_232 < log -> V_149 -> V_77 . V_256 )
||
( log -> V_149 -> V_77 . V_256 <= 1 &&
V_232 < F_103 ( 1 ) ) ) ;
F_6 ( log , & log -> V_54 . V_12 , V_232 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_232 ) ;
F_139 ( log , V_57 , V_232 ) ;
V_162 = V_57 -> V_95 ;
if ( V_254 )
V_162 += V_232 ;
V_57 -> V_208 . V_257 = F_127 ( V_162 ) ;
V_150 = V_57 -> V_204 ;
F_154 ( V_150 , F_155 ( F_156 ( V_57 -> V_208 . V_237 ) ) ) ;
F_157 ( log -> V_149 , V_258 , F_123 ( V_251 ) ) ;
if ( F_158 ( V_150 ) + F_123 ( V_251 ) > log -> V_189 ) {
char * V_259 ;
V_253 = V_251 - ( F_103 ( log -> V_189 - F_158 ( V_150 ) ) ) ;
V_251 = F_103 ( log -> V_189 - F_158 ( V_150 ) ) ;
V_57 -> V_260 = 2 ;
V_259 = ( char * ) & V_57 -> V_208 + V_251 ;
for ( V_185 = 0 ; V_185 < V_253 ; V_185 += V_175 ) {
T_13 V_7 = F_159 ( * ( T_16 * ) V_259 ) ;
if ( ++ V_7 == V_210 )
V_7 ++ ;
* ( T_16 * ) V_259 = F_127 ( V_7 ) ;
V_259 += V_175 ;
}
} else {
V_57 -> V_260 = 1 ;
}
V_57 -> V_208 . V_246 = F_141 ( log , & V_57 -> V_208 ,
V_57 -> V_221 , V_162 ) ;
#ifdef F_72
if ( log -> V_261 &&
( F_160 () % log -> V_261 == 0 ) ) {
V_57 -> V_208 . V_246 &= 0xAAAAAAAA ;
V_57 -> V_64 |= V_158 ;
F_55 ( log -> V_149 ,
L_20 ,
F_156 ( V_57 -> V_208 . V_237 ) ) ;
}
#endif
V_150 -> V_262 = F_123 ( V_251 ) ;
V_150 -> V_151 = V_57 ;
V_150 -> V_160 &= ~ ( V_263 | V_264 ) ;
V_150 -> V_160 |= ( V_161 | V_265 | V_266 ) ;
if ( log -> V_149 -> V_75 & V_267 ) {
V_150 -> V_160 |= V_263 ;
if ( log -> V_149 -> V_196 != log -> V_149 -> V_118 )
F_161 ( log -> V_149 -> V_118 ) ;
else
V_150 -> V_160 |= V_264 ;
}
ASSERT ( F_158 ( V_150 ) <= log -> V_189 - 1 ) ;
ASSERT ( F_158 ( V_150 ) + F_123 ( V_251 ) <= log -> V_189 ) ;
F_162 ( log , V_57 , V_251 , true ) ;
F_154 ( V_150 , F_158 ( V_150 ) + log -> V_188 ) ;
error = F_146 ( V_150 ) ;
if ( error ) {
F_106 ( V_150 , L_21 ) ;
return error ;
}
if ( V_253 ) {
V_150 = V_57 -> V_153 -> V_200 ;
F_154 ( V_150 , 0 ) ;
F_163 ( V_150 ,
( char * ) & V_57 -> V_208 + V_251 , V_253 ) ;
V_150 -> V_151 = V_57 ;
V_150 -> V_160 &= ~ ( V_263 | V_264 ) ;
V_150 -> V_160 |= ( V_161 | V_265 | V_266 ) ;
if ( log -> V_149 -> V_75 & V_267 )
V_150 -> V_160 |= V_263 ;
ASSERT ( F_158 ( V_150 ) <= log -> V_189 - 1 ) ;
ASSERT ( F_158 ( V_150 ) + F_123 ( V_251 ) <= log -> V_189 ) ;
F_154 ( V_150 , F_158 ( V_150 ) + log -> V_188 ) ;
error = F_146 ( V_150 ) ;
if ( error ) {
F_106 ( V_150 , L_22 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_65 (
struct V_1 * log )
{
T_11 * V_57 , * V_268 ;
int V_185 ;
F_164 ( log ) ;
V_57 = log -> V_94 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
F_85 ( V_57 -> V_204 ) ;
F_86 ( V_57 -> V_204 ) ;
V_57 = V_57 -> V_96 ;
}
F_85 ( log -> V_200 ) ;
F_86 ( log -> V_200 ) ;
F_165 ( log -> V_200 , F_123 ( log -> V_168 ) ) ;
F_130 ( log -> V_200 ) ;
V_57 = log -> V_94 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
F_130 ( V_57 -> V_204 ) ;
V_268 = V_57 -> V_96 ;
F_131 ( V_57 ) ;
V_57 = V_268 ;
}
F_132 ( & log -> V_113 ) ;
log -> V_149 -> V_38 = NULL ;
F_131 ( log ) ;
}
static inline void
F_166 (
struct V_1 * log ,
struct V_56 * V_57 ,
int V_269 ,
int V_270 )
{
F_12 ( & log -> V_113 ) ;
F_167 ( & V_57 -> V_208 . V_271 , V_269 ) ;
V_57 -> V_95 += V_270 ;
F_15 ( & log -> V_113 ) ;
}
void
F_168 (
struct V_36 * V_37 ,
struct V_15 * V_55 )
{
T_4 V_185 ;
T_4 V_272 = V_55 -> V_29 * ( T_4 ) sizeof( V_273 ) ;
#define F_169 ( type , T_19 ) [XLOG_REG_TYPE_##type] = str
static char * V_274 [ V_275 + 1 ] = {
F_169 ( V_276 , L_23 ) ,
F_169 ( V_277 , L_24 ) ,
F_169 ( V_278 , L_25 ) ,
F_169 ( V_279 , L_26 ) ,
F_169 ( V_280 , L_27 ) ,
F_169 ( V_281 , L_28 ) ,
F_169 ( V_282 , L_29 ) ,
F_169 ( V_283 , L_30 ) ,
F_169 ( V_284 , L_31 ) ,
F_169 ( V_285 , L_32 ) ,
F_169 ( V_286 , L_33 ) ,
F_169 ( V_287 , L_34 ) ,
F_169 ( V_288 , L_35 ) ,
F_169 ( V_289 , L_36 ) ,
F_169 ( V_290 , L_37 ) ,
F_169 ( V_291 , L_38 ) ,
F_169 ( V_292 , L_39 ) ,
F_169 ( V_293 , L_40 ) ,
F_169 ( V_294 , L_41 ) ,
F_169 (ICREATE, L_42 )
} ;
#undef F_169
F_55 ( V_37 , L_43 ) ;
F_55 ( V_37 , L_44 ,
V_55 -> V_21 ) ;
F_55 ( V_37 , L_45 ,
V_55 -> V_42 ) ;
F_55 ( V_37 , L_46 ,
V_55 -> V_28 , V_55 -> V_32 ) ;
F_55 ( V_37 , L_47 ,
V_55 -> V_29 , V_272 ) ;
F_55 ( V_37 , L_48 ,
V_55 -> V_28 + V_55 -> V_32 + V_272 ) ;
F_55 ( V_37 , L_49 ,
V_55 -> V_27 ) ;
for ( V_185 = 0 ; V_185 < V_55 -> V_27 ; V_185 ++ ) {
T_4 V_35 = V_55 -> V_33 [ V_185 ] . V_35 ;
F_55 ( V_37 , L_50 , V_185 ,
( ( V_35 <= 0 || V_35 > V_275 ) ?
L_51 : V_274 [ V_35 ] ) ,
V_55 -> V_33 [ V_185 ] . V_34 ) ;
}
F_170 ( V_37 , V_295 ,
L_52 ) ;
F_47 ( V_37 , V_70 ) ;
}
static int
F_171 (
struct V_15 * V_55 ,
struct V_107 * V_296 )
{
struct V_107 * V_297 ;
int V_298 = 0 ;
int V_30 = 0 ;
int V_185 ;
if ( V_55 -> V_19 & V_60 )
V_298 ++ ;
for ( V_297 = V_296 ; V_297 ; V_297 = V_297 -> V_299 ) {
if ( V_297 -> V_300 == V_301 )
continue;
V_298 += V_297 -> V_109 ;
for ( V_185 = 0 ; V_185 < V_297 -> V_109 ; V_185 ++ ) {
struct V_101 * V_302 = & V_297 -> V_110 [ V_185 ] ;
V_30 += V_302 -> V_104 ;
F_24 ( V_55 , V_302 -> V_104 , V_302 -> V_105 ) ;
}
}
V_55 -> V_29 += V_298 ;
V_30 += V_298 * sizeof( struct V_303 ) ;
return V_30 ;
}
static int
F_172 (
struct V_303 * V_304 ,
struct V_15 * V_55 )
{
if ( ! ( V_55 -> V_19 & V_60 ) )
return 0 ;
V_304 -> V_305 = F_127 ( V_55 -> V_41 ) ;
V_304 -> V_306 = V_55 -> V_307 ;
V_304 -> V_308 = 0 ;
V_304 -> V_309 = V_310 ;
V_304 -> V_311 = 0 ;
V_55 -> V_19 &= ~ V_60 ;
return sizeof( struct V_303 ) ;
}
static V_273 *
F_173 (
struct V_1 * log ,
struct V_303 * V_304 ,
struct V_15 * V_55 ,
T_4 V_312 )
{
V_304 -> V_305 = F_127 ( V_55 -> V_41 ) ;
V_304 -> V_306 = V_55 -> V_307 ;
V_304 -> V_311 = 0 ;
V_304 -> V_309 = V_312 ;
switch ( V_304 -> V_306 ) {
case V_49 :
case V_313 :
case V_50 :
break;
default:
F_55 ( log -> V_149 ,
L_53 ,
V_304 -> V_306 , V_55 ) ;
return NULL ;
}
return V_304 ;
}
static int
F_174 (
struct V_15 * V_55 ,
struct V_303 * V_304 ,
int V_314 ,
int V_315 ,
int * V_316 ,
int * V_317 ,
int * V_318 ,
int * V_319 )
{
int V_320 ;
V_320 = V_315 - * V_319 ;
* V_316 = * V_319 ;
if ( V_320 <= V_314 ) {
* V_317 = V_320 ;
V_304 -> V_308 = F_127 ( * V_317 ) ;
if ( * V_318 )
V_304 -> V_309 |= ( V_321 | V_322 ) ;
* V_318 = 0 ;
* V_319 = 0 ;
return 0 ;
}
* V_317 = V_314 ;
V_304 -> V_308 = F_127 ( * V_317 ) ;
V_304 -> V_309 |= V_323 ;
if ( * V_318 )
V_304 -> V_309 |= V_322 ;
* V_319 += * V_317 ;
( * V_318 ) ++ ;
V_55 -> V_42 -= sizeof( struct V_303 ) ;
V_55 -> V_29 ++ ;
return sizeof( struct V_303 ) ;
}
static int
F_175 (
struct V_1 * log ,
struct V_56 * V_57 ,
T_4 V_312 ,
int * V_269 ,
int * V_324 ,
int * V_325 ,
int * V_326 ,
int V_327 ,
struct V_56 * * V_328 )
{
if ( * V_325 ) {
F_166 ( log , V_57 , * V_269 , * V_324 ) ;
* V_269 = 0 ;
* V_324 = 0 ;
return F_46 ( log , V_57 ) ;
}
* V_325 = 0 ;
* V_326 = 0 ;
if ( V_57 -> V_218 - V_327 <= sizeof( V_273 ) ) {
F_166 ( log , V_57 , * V_269 , * V_324 ) ;
* V_269 = 0 ;
* V_324 = 0 ;
F_12 ( & log -> V_113 ) ;
F_77 ( log , V_57 ) ;
F_15 ( & log -> V_113 ) ;
if ( ! V_328 )
return F_46 ( log , V_57 ) ;
ASSERT ( V_312 & V_225 ) ;
* V_328 = V_57 ;
}
return 0 ;
}
int
F_74 (
struct V_1 * log ,
struct V_107 * V_296 ,
struct V_15 * V_55 ,
T_6 * V_329 ,
struct V_56 * * V_328 ,
T_4 V_312 )
{
struct V_56 * V_57 = NULL ;
struct V_101 * V_302 ;
struct V_107 * V_297 ;
int V_30 ;
int V_330 ;
int V_325 = 0 ;
int V_326 = 0 ;
int V_331 = 0 ;
int V_269 = 0 ;
int V_324 = 0 ;
int error ;
* V_329 = 0 ;
V_30 = F_171 ( V_55 , V_296 ) ;
if ( V_55 -> V_19 & V_60 )
V_55 -> V_42 -= sizeof( V_273 ) ;
if ( V_312 & ( V_225 | V_111 ) )
V_55 -> V_42 -= sizeof( V_273 ) ;
if ( V_55 -> V_42 < 0 )
F_168 ( log -> V_149 , V_55 ) ;
V_330 = 0 ;
V_297 = V_296 ;
V_302 = V_297 -> V_110 ;
while ( V_297 && ( ! V_297 -> V_109 || V_330 < V_297 -> V_109 ) ) {
void * V_332 ;
int V_327 ;
error = F_176 ( log , V_30 , & V_57 , V_55 ,
& V_331 , & V_327 ) ;
if ( error )
return error ;
ASSERT ( V_327 <= V_57 -> V_218 - 1 ) ;
V_332 = V_57 -> V_221 + V_327 ;
if ( ! * V_329 )
* V_329 = F_156 ( V_57 -> V_208 . V_237 ) ;
while ( V_297 && ( ! V_297 -> V_109 || V_330 < V_297 -> V_109 ) ) {
struct V_101 * V_102 ;
struct V_303 * V_304 ;
int V_333 ;
int V_317 ;
int V_316 ;
bool V_334 = false ;
if ( V_297 -> V_300 == V_301 ) {
ASSERT ( V_297 -> V_109 == 0 ) ;
V_334 = true ;
goto V_335;
}
V_102 = & V_302 [ V_330 ] ;
ASSERT ( V_102 -> V_104 % sizeof( V_336 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_332 % sizeof( V_336 ) == 0 ) ;
V_333 = F_172 ( V_332 , V_55 ) ;
if ( V_333 ) {
V_269 ++ ;
F_177 ( & V_332 , & V_30 , & V_327 ,
V_333 ) ;
}
V_304 = F_173 ( log , V_332 , V_55 , V_312 ) ;
if ( ! V_304 )
return - V_39 ;
F_177 ( & V_332 , & V_30 , & V_327 ,
sizeof( struct V_303 ) ) ;
V_30 += F_174 ( V_55 , V_304 ,
V_57 -> V_218 - V_327 ,
V_102 -> V_104 ,
& V_316 , & V_317 ,
& V_325 ,
& V_326 ) ;
F_178 ( log , V_332 ) ;
ASSERT ( V_317 >= 0 ) ;
if ( V_317 > 0 ) {
memcpy ( V_332 , V_102 -> V_103 + V_316 , V_317 ) ;
F_177 ( & V_332 , & V_30 , & V_327 ,
V_317 ) ;
}
V_317 += V_333 + sizeof( V_273 ) ;
V_269 ++ ;
V_324 += V_331 ? V_317 : 0 ;
error = F_175 ( log , V_57 , V_312 ,
& V_269 , & V_324 ,
& V_325 ,
& V_326 ,
V_327 ,
V_328 ) ;
if ( error )
return error ;
if ( V_325 )
break;
if ( ++ V_330 == V_297 -> V_109 ) {
V_335:
V_297 = V_297 -> V_299 ;
V_330 = 0 ;
if ( V_297 )
V_302 = V_297 -> V_110 ;
}
if ( V_269 == 0 && V_334 == false ) {
if ( ! V_297 )
return 0 ;
break;
}
}
}
ASSERT ( V_30 == 0 ) ;
F_166 ( log , V_57 , V_269 , V_324 ) ;
if ( ! V_328 )
return F_46 ( log , V_57 ) ;
ASSERT ( V_312 & V_225 ) ;
* V_328 = V_57 ;
return 0 ;
}
STATIC void
F_179 (
struct V_1 * log )
{
T_11 * V_57 ;
int V_337 = 0 ;
V_57 = log -> V_94 ;
do {
if ( V_57 -> V_64 == V_115 ) {
V_57 -> V_64 = V_66 ;
V_57 -> V_95 = 0 ;
ASSERT ( V_57 -> V_220 == NULL ) ;
if ( ! V_337 &&
( F_159 ( V_57 -> V_208 . V_271 ) ==
V_338 ) ) {
V_337 = 1 ;
} else {
V_337 = 2 ;
}
V_57 -> V_208 . V_271 = 0 ;
memset ( V_57 -> V_208 . V_238 , 0 ,
sizeof( V_57 -> V_208 . V_238 ) ) ;
V_57 -> V_208 . V_237 = 0 ;
} else if ( V_57 -> V_64 == V_66 )
;
else
break;
V_57 = V_57 -> V_96 ;
} while ( V_57 != log -> V_94 );
if ( V_337 ) {
switch ( log -> V_133 ) {
case V_136 :
case V_137 :
case V_138 :
log -> V_133 = V_137 ;
break;
case V_134 :
if ( V_337 == 1 )
log -> V_133 = V_138 ;
else
log -> V_133 = V_137 ;
break;
case V_135 :
if ( V_337 == 1 )
log -> V_133 = V_136 ;
else
log -> V_133 = V_137 ;
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
T_11 * V_339 ;
T_6 V_340 , V_59 ;
V_339 = log -> V_94 ;
V_340 = 0 ;
do {
if ( ! ( V_339 -> V_64 & ( V_66 | V_115 ) ) ) {
V_59 = F_156 ( V_339 -> V_208 . V_237 ) ;
if ( ( V_59 && ! V_340 ) ||
( F_137 ( V_59 , V_340 ) < 0 ) ) {
V_340 = V_59 ;
}
}
V_339 = V_339 -> V_96 ;
} while ( V_339 != log -> V_94 );
return V_340 ;
}
STATIC void
F_181 (
struct V_1 * log ,
int V_154 ,
struct V_56 * V_341 )
{
T_11 * V_57 ;
T_11 * V_92 ;
T_7 * V_61 , * V_68 ;
int V_342 = 0 ;
T_6 V_340 ;
int V_343 ;
int V_344 ;
int V_345 ;
int V_346 ;
int V_347 = 0 ;
F_12 ( & log -> V_113 ) ;
V_92 = V_57 = log -> V_94 ;
V_343 = 0 ;
V_345 = 0 ;
V_346 = 0 ;
do {
V_92 = log -> V_94 ;
V_57 = log -> V_94 ;
V_344 = 0 ;
V_346 ++ ;
do {
if ( V_57 -> V_64 &
( V_66 | V_115 ) ) {
V_57 = V_57 -> V_96 ;
continue;
}
if ( ! ( V_57 -> V_64 & V_65 ) ) {
if ( ! ( V_57 -> V_64 &
( V_348 |
V_349 ) ) ) {
if ( V_341 && ( V_341 -> V_64 ==
V_348 ) ) {
V_341 -> V_64 = V_349 ;
}
break;
}
V_340 = F_180 ( log ) ;
if ( V_340 &&
F_137 ( V_340 ,
F_156 ( V_57 -> V_208 . V_237 ) ) < 0 ) {
V_57 = V_57 -> V_96 ;
continue;
}
V_57 -> V_64 = V_350 ;
ASSERT ( F_137 ( F_2 ( & log -> V_143 ) ,
F_156 ( V_57 -> V_208 . V_237 ) ) <= 0 ) ;
if ( V_57 -> V_220 )
F_99 ( & log -> V_143 ,
F_156 ( V_57 -> V_208 . V_237 ) ) ;
} else
V_343 ++ ;
F_15 ( & log -> V_113 ) ;
F_12 ( & V_57 -> V_63 ) ;
V_61 = V_57 -> V_220 ;
while ( V_61 ) {
V_57 -> V_69 = & ( V_57 -> V_220 ) ;
V_57 -> V_220 = NULL ;
F_15 ( & V_57 -> V_63 ) ;
for (; V_61 ; V_61 = V_68 ) {
V_68 = V_61 -> V_68 ;
V_61 -> V_351 ( V_61 -> V_352 , V_154 ) ;
}
F_12 ( & V_57 -> V_63 ) ;
V_61 = V_57 -> V_220 ;
}
V_344 ++ ;
V_345 ++ ;
F_12 ( & log -> V_113 ) ;
ASSERT ( V_57 -> V_220 == NULL ) ;
F_15 ( & V_57 -> V_63 ) ;
if ( ! ( V_57 -> V_64 & V_65 ) )
V_57 -> V_64 = V_115 ;
F_179 ( log ) ;
F_182 ( & V_57 -> V_116 ) ;
V_57 = V_57 -> V_96 ;
} while ( V_92 != V_57 );
if ( V_346 > 5000 ) {
V_342 += V_346 ;
V_346 = 0 ;
F_55 ( log -> V_149 ,
L_54 ,
V_112 , V_342 ) ;
}
} while ( ! V_343 && V_344 );
#ifdef F_72
if ( V_345 ) {
V_92 = V_57 = log -> V_94 ;
do {
ASSERT ( V_57 -> V_64 != V_349 ) ;
if ( V_57 -> V_64 == V_67 ||
V_57 -> V_64 & V_353 ||
V_57 -> V_64 == V_348 ||
V_57 -> V_64 == V_65 )
break;
V_57 = V_57 -> V_96 ;
} while ( V_92 != V_57 );
}
#endif
if ( log -> V_94 -> V_64 & ( V_66 | V_65 ) )
V_347 = 1 ;
F_15 ( & log -> V_113 ) ;
if ( V_347 )
F_182 ( & log -> V_201 ) ;
}
STATIC void
F_108 (
T_11 * V_57 ,
int V_154 )
{
struct V_1 * log = V_57 -> V_153 ;
F_12 ( & log -> V_113 ) ;
ASSERT ( V_57 -> V_64 == V_353 ||
V_57 -> V_64 == V_65 ) ;
ASSERT ( F_151 ( & V_57 -> V_114 ) == 0 ) ;
ASSERT ( V_57 -> V_260 == 1 || V_57 -> V_260 == 2 ) ;
if ( V_57 -> V_64 != V_65 ) {
if ( -- V_57 -> V_260 == 1 ) {
F_15 ( & log -> V_113 ) ;
return;
}
V_57 -> V_64 = V_348 ;
}
F_182 ( & V_57 -> V_222 ) ;
F_15 ( & log -> V_113 ) ;
F_181 ( log , V_154 , V_57 ) ;
}
STATIC int
F_176 (
struct V_1 * log ,
int V_30 ,
struct V_56 * * V_183 ,
struct V_15 * V_55 ,
int * V_354 ,
int * V_355 )
{
int V_327 ;
T_15 * V_2 ;
T_11 * V_57 ;
int error ;
V_356:
F_12 ( & log -> V_113 ) ;
if ( F_26 ( log ) ) {
F_15 ( & log -> V_113 ) ;
return - V_39 ;
}
V_57 = log -> V_94 ;
if ( V_57 -> V_64 != V_66 ) {
F_27 ( log -> V_149 , V_357 ) ;
F_78 ( & log -> V_201 , & log -> V_113 ) ;
goto V_356;
}
V_2 = & V_57 -> V_208 ;
F_76 ( & V_57 -> V_114 ) ;
V_327 = V_57 -> V_95 ;
if ( V_327 == 0 ) {
V_55 -> V_42 -= log -> V_171 ;
F_24 ( V_55 ,
log -> V_171 ,
V_358 ) ;
V_2 -> V_359 = F_127 ( log -> V_191 ) ;
V_2 -> V_237 = F_183 (
F_136 ( log -> V_191 , log -> V_360 ) ) ;
ASSERT ( log -> V_360 >= 0 ) ;
}
if ( V_57 -> V_218 - V_57 -> V_95 < 2 * sizeof( V_273 ) ) {
F_184 ( log , V_57 , V_57 -> V_218 ) ;
if ( ! F_185 ( & V_57 -> V_114 , - 1 , 1 ) ) {
F_15 ( & log -> V_113 ) ;
error = F_46 ( log , V_57 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_113 ) ;
}
goto V_356;
}
if ( V_30 <= V_57 -> V_218 - V_57 -> V_95 ) {
* V_354 = 0 ;
V_57 -> V_95 += V_30 ;
} else {
* V_354 = 1 ;
F_184 ( log , V_57 , V_57 -> V_218 ) ;
}
* V_183 = V_57 ;
ASSERT ( V_57 -> V_95 <= V_57 -> V_218 ) ;
F_15 ( & log -> V_113 ) ;
* V_355 = V_327 ;
return 0 ;
}
STATIC void
F_41 (
struct V_1 * log ,
struct V_15 * V_55 )
{
F_186 ( log , V_55 ) ;
if ( V_55 -> V_22 > 0 )
V_55 -> V_22 -- ;
F_1 ( log , & log -> V_54 . V_12 ,
V_55 -> V_42 ) ;
F_1 ( log , & log -> V_18 . V_12 ,
V_55 -> V_42 ) ;
V_55 -> V_42 = V_55 -> V_21 ;
F_23 ( V_55 ) ;
F_187 ( log , V_55 ) ;
if ( V_55 -> V_22 > 0 )
return;
F_6 ( log , & log -> V_54 . V_12 ,
V_55 -> V_21 ) ;
F_188 ( log , V_55 ) ;
V_55 -> V_42 = V_55 -> V_21 ;
F_23 ( V_55 ) ;
}
STATIC void
F_39 (
struct V_1 * log ,
struct V_15 * V_55 )
{
int V_3 ;
if ( V_55 -> V_22 > 0 )
V_55 -> V_22 -- ;
F_189 ( log , V_55 ) ;
F_190 ( log , V_55 ) ;
V_3 = V_55 -> V_42 ;
if ( V_55 -> V_22 > 0 ) {
ASSERT ( V_55 -> V_19 & V_20 ) ;
V_3 += V_55 -> V_21 * V_55 -> V_22 ;
}
F_1 ( log , & log -> V_54 . V_12 , V_3 ) ;
F_1 ( log , & log -> V_18 . V_12 , V_3 ) ;
F_191 ( log , V_55 ) ;
F_89 ( log -> V_149 ) ;
}
STATIC int
F_46 (
struct V_1 * log ,
struct V_56 * V_57 )
{
int V_361 = 0 ;
if ( V_57 -> V_64 & V_65 )
return - V_39 ;
ASSERT ( F_151 ( & V_57 -> V_114 ) > 0 ) ;
if ( ! F_192 ( & V_57 -> V_114 , & log -> V_113 ) )
return 0 ;
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_113 ) ;
return - V_39 ;
}
ASSERT ( V_57 -> V_64 == V_66 ||
V_57 -> V_64 == V_67 ) ;
if ( V_57 -> V_64 == V_67 ) {
T_6 V_140 = F_100 ( log -> V_149 ) ;
V_361 ++ ;
V_57 -> V_64 = V_353 ;
V_57 -> V_208 . V_362 = F_183 ( V_140 ) ;
F_193 ( log , V_57 , V_140 ) ;
}
F_15 ( & log -> V_113 ) ;
if ( V_361 )
return F_150 ( log , V_57 ) ;
return 0 ;
}
STATIC void
F_184 (
struct V_1 * log ,
struct V_56 * V_57 ,
int V_363 )
{
ASSERT ( V_57 -> V_64 == V_66 ) ;
if ( ! V_363 )
V_363 = V_57 -> V_95 ;
V_57 -> V_64 = V_67 ;
V_57 -> V_208 . V_364 = F_127 ( log -> V_190 ) ;
log -> V_190 = log -> V_360 ;
log -> V_365 = log -> V_191 ;
log -> V_360 += F_123 ( V_363 ) + F_123 ( log -> V_171 ) ;
if ( F_110 ( & log -> V_149 -> V_77 ) &&
log -> V_149 -> V_77 . V_256 > 1 ) {
T_13 V_366 = F_123 ( log -> V_149 -> V_77 . V_256 ) ;
log -> V_360 = F_194 ( log -> V_360 , V_366 ) ;
}
if ( log -> V_360 >= log -> V_189 ) {
log -> V_360 -= log -> V_189 ;
ASSERT ( log -> V_360 >= 0 ) ;
F_195 () ;
log -> V_191 ++ ;
if ( log -> V_191 == V_210 )
log -> V_191 ++ ;
}
ASSERT ( V_57 == log -> V_94 ) ;
log -> V_94 = V_57 -> V_96 ;
}
int
F_73 (
struct V_36 * V_37 ,
T_4 V_312 ,
int * V_367 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_56 * V_57 ;
T_6 V_59 ;
F_27 ( V_37 , V_368 ) ;
F_196 ( log ) ;
F_12 ( & log -> V_113 ) ;
V_57 = log -> V_94 ;
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_113 ) ;
return - V_39 ;
}
if ( V_57 -> V_64 == V_66 ||
V_57 -> V_64 == V_115 ) {
if ( V_57 -> V_64 == V_115 ||
( F_151 ( & V_57 -> V_114 ) == 0
&& V_57 -> V_95 == 0 ) ) {
V_57 = V_57 -> V_203 ;
if ( V_57 -> V_64 == V_66 ||
V_57 -> V_64 == V_115 )
goto V_369;
else
goto V_370;
} else {
if ( F_151 ( & V_57 -> V_114 ) == 0 ) {
F_76 ( & V_57 -> V_114 ) ;
V_59 = F_156 ( V_57 -> V_208 . V_237 ) ;
F_184 ( log , V_57 , 0 ) ;
F_15 ( & log -> V_113 ) ;
if ( F_46 ( log , V_57 ) )
return - V_39 ;
if ( V_367 )
* V_367 = 1 ;
F_12 ( & log -> V_113 ) ;
if ( F_156 ( V_57 -> V_208 . V_237 ) == V_59 &&
V_57 -> V_64 != V_115 )
goto V_370;
else
goto V_369;
} else {
F_184 ( log , V_57 , 0 ) ;
goto V_370;
}
}
}
V_370:
if ( V_312 & V_93 ) {
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_113 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_371 ) ;
F_78 ( & V_57 -> V_116 , & log -> V_113 ) ;
if ( V_57 -> V_64 & V_65 )
return - V_39 ;
if ( V_367 )
* V_367 = 1 ;
} else {
V_369:
F_15 ( & log -> V_113 ) ;
}
return 0 ;
}
void
F_82 (
T_8 * V_37 ,
T_4 V_312 )
{
int error ;
F_197 ( V_37 , 0 , V_372 ) ;
error = F_73 ( V_37 , V_312 , NULL ) ;
if ( error )
F_55 ( V_37 , L_55 , V_112 , error ) ;
}
int
F_198 (
struct V_36 * V_37 ,
T_6 V_59 ,
T_4 V_312 ,
int * V_367 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_56 * V_57 ;
int V_373 = 0 ;
ASSERT ( V_59 != 0 ) ;
F_27 ( V_37 , V_368 ) ;
V_59 = F_199 ( log , V_59 ) ;
if ( V_59 == V_374 )
return 0 ;
V_375:
F_12 ( & log -> V_113 ) ;
V_57 = log -> V_94 ;
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_113 ) ;
return - V_39 ;
}
do {
if ( F_156 ( V_57 -> V_208 . V_237 ) != V_59 ) {
V_57 = V_57 -> V_96 ;
continue;
}
if ( V_57 -> V_64 == V_115 ) {
F_15 ( & log -> V_113 ) ;
return 0 ;
}
if ( V_57 -> V_64 == V_66 ) {
if ( ! V_373 &&
( V_57 -> V_203 -> V_64 &
( V_67 | V_353 ) ) ) {
ASSERT ( ! ( V_57 -> V_64 & V_65 ) ) ;
F_27 ( V_37 , V_371 ) ;
F_78 ( & V_57 -> V_203 -> V_222 ,
& log -> V_113 ) ;
if ( V_367 )
* V_367 = 1 ;
V_373 = 1 ;
goto V_375;
}
F_76 ( & V_57 -> V_114 ) ;
F_184 ( log , V_57 , 0 ) ;
F_15 ( & log -> V_113 ) ;
if ( F_46 ( log , V_57 ) )
return - V_39 ;
if ( V_367 )
* V_367 = 1 ;
F_12 ( & log -> V_113 ) ;
}
if ( ( V_312 & V_93 ) &&
! ( V_57 -> V_64 &
( V_66 | V_115 ) ) ) {
if ( V_57 -> V_64 & V_65 ) {
F_15 ( & log -> V_113 ) ;
return - V_39 ;
}
F_27 ( V_37 , V_371 ) ;
F_78 ( & V_57 -> V_116 , & log -> V_113 ) ;
if ( V_57 -> V_64 & V_65 )
return - V_39 ;
if ( V_367 )
* V_367 = 1 ;
} else {
F_15 ( & log -> V_113 ) ;
}
return 0 ;
} while ( V_57 != log -> V_94 );
F_15 ( & log -> V_113 ) ;
return 0 ;
}
void
F_200 (
T_8 * V_37 ,
T_6 V_59 ,
T_4 V_312 )
{
int error ;
F_197 ( V_37 , V_59 , V_372 ) ;
error = F_198 ( V_37 , V_59 , V_312 , NULL ) ;
if ( error )
F_55 ( V_37 , L_55 , V_112 , error ) ;
}
STATIC void
F_77 (
struct V_1 * log ,
struct V_56 * V_57 )
{
F_96 ( & log -> V_113 ) ;
if ( V_57 -> V_64 == V_66 ) {
F_184 ( log , V_57 , 0 ) ;
} else {
ASSERT ( V_57 -> V_64 &
( V_67 | V_65 ) ) ;
}
}
void
F_42 (
T_3 * V_55 )
{
ASSERT ( F_151 ( & V_55 -> V_376 ) > 0 ) ;
if ( F_201 ( & V_55 -> V_376 ) )
F_202 ( V_377 , V_55 ) ;
}
T_3 *
F_203 (
T_3 * V_55 )
{
ASSERT ( F_151 ( & V_55 -> V_376 ) > 0 ) ;
F_76 ( & V_55 -> V_376 ) ;
return V_55 ;
}
int
F_204 (
struct V_36 * V_37 ,
int V_44 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_378 ;
T_4 V_379 ;
V_44 += sizeof( V_273 ) ;
V_44 += sizeof( V_380 ) ;
V_44 += sizeof( V_273 ) ;
V_378 = log -> V_168 - log -> V_171 ;
V_379 = F_205 ( V_44 , V_378 ) ;
V_44 += sizeof( V_273 ) * V_379 ;
while ( ! V_379 ||
F_205 ( V_44 , V_378 ) > V_379 ) {
V_44 += sizeof( V_273 ) ;
V_379 ++ ;
}
V_44 += log -> V_171 * V_379 ;
V_44 += log -> V_171 ;
if ( F_110 ( & V_37 -> V_77 ) && V_37 -> V_77 . V_256 > 1 ) {
V_44 += 2 * V_37 -> V_77 . V_256 ;
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
T_20 V_381 )
{
struct V_15 * V_16 ;
int V_382 ;
V_16 = F_206 ( V_377 , V_381 ) ;
if ( ! V_16 )
return NULL ;
V_382 = F_204 ( log -> V_149 , V_44 ) ;
F_128 ( & V_16 -> V_376 , 1 ) ;
V_16 -> V_17 = V_383 ;
F_9 ( & V_16 -> V_384 ) ;
V_16 -> V_21 = V_382 ;
V_16 -> V_42 = V_382 ;
V_16 -> V_22 = V_45 ;
V_16 -> V_385 = V_45 ;
V_16 -> V_41 = F_160 () ;
V_16 -> V_307 = V_47 ;
V_16 -> V_19 = V_60 ;
if ( V_48 )
V_16 -> V_19 |= V_20 ;
F_23 ( V_16 ) ;
return V_16 ;
}
void
F_178 (
struct V_1 * log ,
void * V_332 )
{
int V_185 ;
int V_386 = 0 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ ) {
if ( V_332 >= log -> V_207 [ V_185 ] &&
V_332 <= log -> V_207 [ V_185 ] + log -> V_168 )
V_386 ++ ;
}
if ( ! V_386 )
F_207 ( log -> V_149 , L_56 , V_112 ) ;
}
STATIC void
F_31 (
struct V_1 * log )
{
int V_146 , V_387 ;
int V_7 , V_8 ;
F_101 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_102 ( & log -> V_144 , & V_146 , & V_387 ) ;
if ( V_146 != V_7 ) {
if ( V_7 - 1 != V_146 &&
! ( log -> V_25 & V_388 ) ) {
F_170 ( log -> V_149 , V_295 ,
L_57 , V_112 ) ;
log -> V_25 |= V_388 ;
}
if ( V_8 > F_103 ( V_387 ) &&
! ( log -> V_25 & V_388 ) ) {
F_170 ( log -> V_149 , V_295 ,
L_58 , V_112 ) ;
log -> V_25 |= V_388 ;
}
}
}
STATIC void
F_193 (
struct V_1 * log ,
struct V_56 * V_57 ,
T_6 V_140 )
{
int V_389 ;
if ( F_208 ( V_140 ) == log -> V_365 ) {
V_389 =
log -> V_189 - ( log -> V_190 - F_155 ( V_140 ) ) ;
if ( V_389 < F_123 ( V_57 -> V_95 ) + F_123 ( log -> V_171 ) )
F_207 ( log -> V_149 , L_59 , V_112 ) ;
} else {
ASSERT ( F_208 ( V_140 ) + 1 == log -> V_365 ) ;
if ( F_155 ( V_140 ) == log -> V_190 )
F_207 ( log -> V_149 , L_60 , V_112 ) ;
V_389 = F_155 ( V_140 ) - log -> V_190 ;
if ( V_389 < F_123 ( V_57 -> V_95 ) + 1 )
F_207 ( log -> V_149 , L_59 , V_112 ) ;
}
}
STATIC void
F_162 (
struct V_1 * log ,
struct V_56 * V_57 ,
int V_251 ,
bool V_390 )
{
V_273 * V_391 ;
T_11 * V_392 ;
T_17 * V_239 ;
void * V_393 , * V_332 , * V_394 ;
T_21 V_395 ;
T_5 V_396 ;
int V_30 , V_185 , V_233 , V_234 , V_397 ;
int V_398 ;
F_12 ( & log -> V_113 ) ;
V_392 = log -> V_94 ;
for ( V_185 = 0 ; V_185 < log -> V_165 ; V_185 ++ , V_392 = V_392 -> V_96 )
ASSERT ( V_392 ) ;
if ( V_392 != log -> V_94 )
F_207 ( log -> V_149 , L_61 , V_112 ) ;
F_15 ( & log -> V_113 ) ;
if ( V_57 -> V_208 . V_209 != F_127 ( V_210 ) )
F_207 ( log -> V_149 , L_62 , V_112 ) ;
V_393 = V_332 = & V_57 -> V_208 ;
V_394 = & V_57 -> V_208 ;
for ( V_332 += V_175 ; V_332 < V_393 + V_251 ; V_332 += V_175 ) {
if ( * ( T_16 * ) V_332 == F_127 ( V_210 ) )
F_207 ( log -> V_149 , L_63 ,
V_112 ) ;
}
V_30 = F_159 ( V_57 -> V_208 . V_271 ) ;
V_393 = V_332 = V_57 -> V_221 ;
V_391 = V_332 ;
V_239 = V_57 -> V_205 ;
for ( V_185 = 0 ; V_185 < V_30 ; V_185 ++ ) {
V_391 = V_332 ;
V_394 = & V_391 -> V_306 ;
V_395 = V_394 - V_393 ;
if ( ! V_390 || ( V_395 & 0x1ff ) ) {
V_396 = V_391 -> V_306 ;
} else {
V_398 = F_134 ( ( char * ) & V_391 -> V_306 - V_57 -> V_221 ) ;
if ( V_398 >= ( V_170 / V_175 ) ) {
V_233 = V_398 / ( V_170 / V_175 ) ;
V_234 = V_398 % ( V_170 / V_175 ) ;
V_396 = F_209 (
V_239 [ V_233 ] . V_240 . V_241 [ V_234 ] ) ;
} else {
V_396 = F_209 (
V_57 -> V_208 . V_238 [ V_398 ] ) ;
}
}
if ( V_396 != V_49 && V_396 != V_50 )
F_55 ( log -> V_149 ,
L_64 ,
V_112 , V_396 , V_391 ,
( unsigned long ) V_395 ) ;
V_394 = & V_391 -> V_308 ;
V_395 = V_394 - V_393 ;
if ( ! V_390 || ( V_395 & 0x1ff ) ) {
V_397 = F_159 ( V_391 -> V_308 ) ;
} else {
V_398 = F_134 ( ( V_399 ) & V_391 -> V_308 -
( V_399 ) V_57 -> V_221 ) ;
if ( V_398 >= ( V_170 / V_175 ) ) {
V_233 = V_398 / ( V_170 / V_175 ) ;
V_234 = V_398 % ( V_170 / V_175 ) ;
V_397 = F_159 ( V_239 [ V_233 ] . V_240 . V_241 [ V_234 ] ) ;
} else {
V_397 = F_159 ( V_57 -> V_208 . V_238 [ V_398 ] ) ;
}
}
V_332 += sizeof( V_273 ) + V_397 ;
}
}
STATIC int
F_210 (
struct V_1 * log )
{
T_11 * V_57 , * V_400 ;
V_57 = log -> V_94 ;
if ( ! ( V_57 -> V_64 & V_65 ) ) {
V_400 = V_57 ;
do {
V_400 -> V_64 = V_65 ;
V_400 = V_400 -> V_96 ;
} while ( V_400 != V_57 );
return 0 ;
}
return 1 ;
}
int
F_211 (
struct V_36 * V_37 ,
int V_401 )
{
struct V_1 * log ;
int V_402 ;
log = V_37 -> V_38 ;
if ( ! log ||
log -> V_25 & V_26 ) {
V_37 -> V_75 |= V_403 ;
if ( V_37 -> V_119 )
V_37 -> V_119 -> V_160 |= V_404 ;
return 0 ;
}
if ( V_401 && log -> V_94 -> V_64 & V_65 ) {
ASSERT ( F_26 ( log ) ) ;
return 1 ;
}
if ( ! V_401 )
F_73 ( V_37 , V_93 , NULL ) ;
F_12 ( & log -> V_113 ) ;
V_37 -> V_75 |= V_403 ;
if ( V_37 -> V_119 )
V_37 -> V_119 -> V_160 |= V_404 ;
log -> V_25 |= V_405 ;
V_402 = F_210 ( log ) ;
F_15 ( & log -> V_113 ) ;
F_11 ( & log -> V_54 ) ;
F_11 ( & log -> V_18 ) ;
F_182 ( & log -> V_406 -> V_407 ) ;
F_181 ( log , V_159 , NULL ) ;
#ifdef F_212
{
T_11 * V_57 ;
F_12 ( & log -> V_113 ) ;
V_57 = log -> V_94 ;
do {
ASSERT ( V_57 -> V_220 == 0 ) ;
V_57 = V_57 -> V_96 ;
} while ( V_57 != log -> V_94 );
F_15 ( & log -> V_113 ) ;
}
#endif
return V_402 ;
}
STATIC int
F_94 (
struct V_1 * log )
{
T_11 * V_57 ;
V_57 = log -> V_94 ;
do {
if ( V_57 -> V_208 . V_271 )
return 0 ;
V_57 = V_57 -> V_96 ;
} while ( V_57 != log -> V_94 );
return 1 ;
}
bool
F_213 (
struct V_36 * V_37 ,
T_6 V_59 )
{
struct V_1 * log = V_37 -> V_38 ;
bool V_408 ;
if ( V_37 -> V_75 & V_76 )
return true ;
if ( V_59 == V_374 )
return true ;
V_408 = F_214 ( V_37 -> V_38 , V_59 ) ;
if ( ! V_408 ) {
F_12 ( & log -> V_113 ) ;
F_55 ( V_37 ,
L_65
L_66 ,
F_208 ( V_59 ) , F_155 ( V_59 ) ,
log -> V_191 , log -> V_360 ) ;
F_15 ( & log -> V_113 ) ;
}
return V_408 ;
}
