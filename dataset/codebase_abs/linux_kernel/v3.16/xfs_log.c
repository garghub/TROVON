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
return F_27 ( V_39 ) ;
F_28 ( V_40 ) ;
V_16 -> V_41 ++ ;
F_29 ( log , V_16 -> V_21 ) ;
V_16 -> V_42 = V_16 -> V_21 ;
F_23 ( V_16 ) ;
if ( V_16 -> V_22 > 0 )
return 0 ;
F_30 ( log , V_16 ) ;
error = F_20 ( log , & log -> V_18 , V_16 ,
& V_24 ) ;
if ( error )
goto V_43;
F_6 ( log , & log -> V_18 . V_12 , V_24 ) ;
F_31 ( log , V_16 ) ;
F_32 ( log ) ;
return 0 ;
V_43:
V_16 -> V_42 = 0 ;
V_16 -> V_22 = 0 ;
return error ;
}
int
F_33 (
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
return F_27 ( V_39 ) ;
F_28 ( V_40 ) ;
ASSERT ( * V_46 == NULL ) ;
V_16 = F_34 ( log , V_44 , V_45 , V_47 , V_48 ,
V_52 | V_53 ) ;
if ( ! V_16 )
return F_27 ( V_54 ) ;
V_16 -> V_55 = V_49 ;
* V_46 = V_16 ;
F_29 ( log , V_16 -> V_22 ? V_16 -> V_21 * V_16 -> V_22
: V_16 -> V_21 ) ;
F_35 ( log , V_16 ) ;
error = F_20 ( log , & log -> V_56 , V_16 ,
& V_24 ) ;
if ( error )
goto V_43;
F_6 ( log , & log -> V_56 . V_12 , V_24 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_24 ) ;
F_36 ( log , V_16 ) ;
F_32 ( log ) ;
return 0 ;
V_43:
V_16 -> V_42 = 0 ;
V_16 -> V_22 = 0 ;
return error ;
}
T_6
F_37 (
struct V_36 * V_37 ,
struct V_15 * V_57 ,
struct V_58 * * V_59 ,
T_4 V_60 )
{
struct V_1 * log = V_37 -> V_38 ;
T_6 V_61 = 0 ;
if ( F_26 ( log ) ||
( ( ( V_57 -> V_19 & V_62 ) == 0 ) &&
( F_38 ( log , V_57 , V_59 , & V_61 ) ) ) ) {
V_61 = ( T_6 ) - 1 ;
if ( V_57 -> V_19 & V_20 ) {
V_60 |= V_63 ;
}
}
if ( ( V_57 -> V_19 & V_20 ) == 0 ||
( V_60 & V_63 ) ) {
F_39 ( log , V_57 ) ;
F_40 ( log , V_57 ) ;
F_41 ( V_57 ) ;
} else {
F_42 ( log , V_57 ) ;
F_43 ( log , V_57 ) ;
V_57 -> V_19 |= V_62 ;
}
return V_61 ;
}
int
F_44 (
struct V_36 * V_37 ,
struct V_58 * V_59 ,
T_7 * V_64 )
{
int V_65 ;
F_12 ( & V_59 -> V_66 ) ;
V_65 = ( V_59 -> V_67 & V_68 ) ;
if ( ! V_65 ) {
F_45 ( ( V_59 -> V_67 == V_69 ) ||
( V_59 -> V_67 == V_70 ) ) ;
V_64 -> V_71 = NULL ;
* ( V_59 -> V_72 ) = V_64 ;
V_59 -> V_72 = & ( V_64 -> V_71 ) ;
}
F_15 ( & V_59 -> V_66 ) ;
return V_65 ;
}
int
F_46 (
struct V_36 * V_37 ,
struct V_58 * V_59 )
{
if ( F_47 ( V_37 -> V_38 , V_59 ) ) {
F_48 ( V_37 , V_73 ) ;
return V_39 ;
}
return 0 ;
}
int
F_49 (
T_8 * V_37 ,
T_9 * V_74 ,
T_10 V_75 ,
int V_76 )
{
int error = 0 ;
int V_77 ;
if ( ! ( V_37 -> V_78 & V_79 ) ) {
F_50 ( V_37 , L_1 ,
F_51 ( & V_37 -> V_80 ) ) ;
} else {
F_50 ( V_37 ,
L_2 ,
F_51 ( & V_37 -> V_80 ) ) ;
ASSERT ( V_37 -> V_78 & V_81 ) ;
}
V_37 -> V_38 = F_52 ( V_37 , V_74 , V_75 , V_76 ) ;
if ( F_53 ( V_37 -> V_38 ) ) {
error = - F_54 ( V_37 -> V_38 ) ;
goto V_82;
}
V_77 = F_55 ( V_37 ) ;
if ( V_37 -> V_80 . V_83 < V_77 ) {
F_56 ( V_37 ,
L_3 ,
V_37 -> V_80 . V_83 , V_77 ) ;
error = V_84 ;
} else if ( V_37 -> V_80 . V_83 > V_85 ) {
F_56 ( V_37 ,
L_4 ,
V_37 -> V_80 . V_83 , V_85 ) ;
error = V_84 ;
} else if ( F_57 ( V_37 , V_37 -> V_80 . V_83 ) > V_86 ) {
F_56 ( V_37 ,
L_5 ,
F_57 ( V_37 , V_37 -> V_80 . V_83 ) ,
V_86 ) ;
error = V_84 ;
}
if ( error ) {
if ( F_58 ( & V_37 -> V_80 ) ) {
F_59 ( V_37 , L_6 ) ;
ASSERT ( 0 ) ;
goto V_87;
}
F_59 ( V_37 ,
L_7
L_8 ) ;
}
error = F_60 ( V_37 ) ;
if ( error ) {
F_56 ( V_37 , L_9 , error ) ;
goto V_87;
}
V_37 -> V_38 -> V_88 = V_37 -> V_89 ;
if ( ! ( V_37 -> V_78 & V_79 ) ) {
int V_90 = ( V_37 -> V_78 & V_81 ) ;
if ( V_90 )
V_37 -> V_78 &= ~ V_81 ;
error = F_61 ( V_37 -> V_38 ) ;
if ( V_90 )
V_37 -> V_78 |= V_81 ;
if ( error ) {
F_56 ( V_37 , L_10 ,
error ) ;
goto V_91;
}
}
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
T_11 * V_92 ;
#endif
T_3 * V_16 = NULL ;
T_6 V_61 ;
int error ;
if ( V_37 -> V_78 & V_81 )
return 0 ;
error = F_70 ( V_37 , V_93 , NULL ) ;
ASSERT ( error || ! ( F_26 ( log ) ) ) ;
#ifdef F_69
V_92 = V_59 = log -> V_94 ;
do {
if ( ! ( V_59 -> V_67 & V_68 ) ) {
ASSERT ( V_59 -> V_67 & V_69 ) ;
ASSERT ( V_59 -> V_95 == 0 ) ;
}
V_59 = V_59 -> V_96 ;
} while ( V_59 != V_92 );
#endif
if ( ! ( F_26 ( log ) ) ) {
error = F_33 ( V_37 , 600 , 1 , & V_16 ,
V_51 , 0 , V_97 ) ;
if ( ! error ) {
struct {
T_12 V_98 ;
T_12 V_99 ;
T_13 V_100 ;
} V_98 = {
. V_98 = V_101 ,
} ;
struct V_102 V_103 = {
. V_104 = & V_98 ,
. V_105 = sizeof( V_98 ) ,
. V_106 = V_107 ,
} ;
struct V_108 V_109 = {
. V_110 = 1 ,
. V_111 = & V_103 ,
} ;
V_16 -> V_19 = 0 ;
V_16 -> V_42 -= sizeof( V_98 ) ;
error = F_71 ( log , & V_109 , V_16 , & V_61 ,
NULL , V_112 ) ;
}
if ( error )
F_72 ( V_37 , L_11 , V_113 ) ;
F_12 ( & log -> V_114 ) ;
V_59 = log -> V_94 ;
F_73 ( & V_59 -> V_115 ) ;
F_74 ( log , V_59 ) ;
F_15 ( & log -> V_114 ) ;
error = F_47 ( log , V_59 ) ;
F_12 ( & log -> V_114 ) ;
if ( ! ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_116 ) ) {
if ( ! F_26 ( log ) ) {
F_75 ( & V_59 -> V_117 ,
& log -> V_114 ) ;
} else {
F_15 ( & log -> V_114 ) ;
}
} else {
F_15 ( & log -> V_114 ) ;
}
if ( V_16 ) {
F_76 ( log , V_16 ) ;
F_40 ( log , V_16 ) ;
F_41 ( V_16 ) ;
}
} else {
F_12 ( & log -> V_114 ) ;
V_59 = log -> V_94 ;
F_73 ( & V_59 -> V_115 ) ;
F_74 ( log , V_59 ) ;
F_15 ( & log -> V_114 ) ;
error = F_47 ( log , V_59 ) ;
F_12 ( & log -> V_114 ) ;
if ( ! ( V_59 -> V_67 == V_69
|| V_59 -> V_67 == V_116
|| V_59 -> V_67 == V_68 ) ) {
F_75 ( & V_59 -> V_117 ,
& log -> V_114 ) ;
} else {
F_15 ( & log -> V_114 ) ;
}
}
return error ;
}
void
F_77 (
struct V_36 * V_37 )
{
F_78 ( & V_37 -> V_38 -> V_118 ) ;
F_79 ( V_37 , V_93 ) ;
F_80 ( V_37 -> V_89 ) ;
F_81 ( V_37 -> V_119 ) ;
F_82 ( V_37 -> V_120 ) ;
F_83 ( V_37 -> V_120 ) ;
F_68 ( V_37 ) ;
}
void
F_84 (
struct V_36 * V_37 )
{
F_77 ( V_37 ) ;
F_63 ( V_37 ) ;
F_64 ( V_37 -> V_38 ) ;
}
void
F_85 (
struct V_36 * V_37 ,
struct V_121 * V_122 ,
int type ,
const struct V_123 * V_124 )
{
V_122 -> V_125 = V_37 ;
V_122 -> V_126 = V_37 -> V_89 ;
V_122 -> V_127 = type ;
V_122 -> V_128 = V_124 ;
V_122 -> V_129 = NULL ;
F_9 ( & V_122 -> V_130 ) ;
F_9 ( & V_122 -> V_131 ) ;
}
void
F_86 (
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
F_87 ( T_8 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_132 = 0 ;
if ( ! F_88 ( V_37 ) )
return 0 ;
if ( ! F_89 ( log ) )
return 0 ;
F_12 ( & log -> V_114 ) ;
switch ( log -> V_133 ) {
case V_134 :
case V_135 :
case V_136 :
break;
case V_137 :
case V_138 :
if ( F_90 ( log -> V_88 ) )
break;
if ( ! F_91 ( log ) )
break;
V_132 = 1 ;
if ( log -> V_133 == V_137 )
log -> V_133 = V_134 ;
else
log -> V_133 = V_135 ;
break;
default:
V_132 = 1 ;
break;
}
F_15 ( & log -> V_114 ) ;
return V_132 ;
}
T_6
F_92 (
struct V_36 * V_37 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_121 * V_139 ;
T_6 V_140 ;
F_93 ( & V_37 -> V_89 -> V_141 ) ;
V_139 = F_94 ( V_37 -> V_89 ) ;
if ( V_139 )
V_140 = V_139 -> V_142 ;
else
V_140 = F_2 ( & log -> V_143 ) ;
F_95 ( log , V_140 ) ;
F_96 ( & log -> V_144 , V_140 ) ;
return V_140 ;
}
T_6
F_97 (
struct V_36 * V_37 )
{
T_6 V_140 ;
F_12 ( & V_37 -> V_89 -> V_141 ) ;
V_140 = F_92 ( V_37 ) ;
F_15 ( & V_37 -> V_89 -> V_141 ) ;
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
F_98 ( V_2 , & V_147 , & V_148 ) ;
F_99 ( & log -> V_144 , & V_146 , & V_145 ) ;
V_145 = F_100 ( V_145 ) ;
if ( V_146 == V_147 && V_148 >= V_145 )
V_23 = log -> V_9 - ( V_148 - V_145 ) ;
else if ( V_146 + 1 < V_147 )
return 0 ;
else if ( V_146 < V_147 ) {
ASSERT ( V_146 == ( V_147 - 1 ) ) ;
V_23 = V_145 - V_148 ;
} else {
F_72 ( log -> V_149 ,
L_12
L_13
L_14 ,
V_146 , V_145 , V_147 , V_148 ) ;
ASSERT ( 0 ) ;
V_23 = log -> V_9 ;
}
return V_23 ;
}
void
F_101 ( T_14 * V_150 )
{
struct V_58 * V_59 = V_150 -> V_151 ;
struct V_1 * V_152 = V_59 -> V_153 ;
int V_154 = 0 ;
if ( F_102 ( V_150 -> V_155 , V_152 -> V_149 ,
V_156 , V_157 ) ) {
F_103 ( V_150 , V_113 ) ;
F_104 ( V_150 ) ;
F_48 ( V_152 -> V_149 , V_73 ) ;
V_154 = V_158 ;
} else if ( V_59 -> V_67 & V_68 ) {
V_154 = V_158 ;
}
ASSERT ( F_105 ( V_150 ) ) ;
F_106 ( V_59 , V_154 ) ;
F_83 ( V_150 ) ;
}
STATIC void
F_107 (
struct V_36 * V_37 ,
struct V_1 * log )
{
int V_159 ;
int V_160 ;
if ( V_37 -> V_161 <= 0 )
log -> V_162 = V_163 ;
else
log -> V_162 = V_37 -> V_161 ;
if ( V_37 -> V_164 > 0 ) {
V_159 = log -> V_165 = V_37 -> V_164 ;
log -> V_166 = 0 ;
while ( V_159 != 1 ) {
log -> V_166 ++ ;
V_159 >>= 1 ;
}
if ( F_108 ( & V_37 -> V_80 ) ) {
V_160 = V_37 -> V_164 / V_167 ;
if ( V_37 -> V_164 % V_167 )
V_160 ++ ;
log -> V_168 = V_160 << V_169 ;
log -> V_170 = V_160 ;
} else {
ASSERT ( V_37 -> V_164 <= V_171 ) ;
log -> V_168 = V_172 ;
log -> V_170 = 1 ;
}
goto V_173;
}
log -> V_165 = V_171 ;
log -> V_166 = V_174 ;
log -> V_168 = V_172 ;
log -> V_170 = 1 ;
V_173:
if ( V_37 -> V_161 == 0 )
V_37 -> V_161 = log -> V_162 ;
if ( V_37 -> V_164 == 0 )
V_37 -> V_164 = log -> V_165 ;
}
void
F_67 (
struct V_36 * V_37 )
{
F_109 ( V_37 -> V_175 , & V_37 -> V_38 -> V_118 ,
F_110 ( V_176 * 10 ) ) ;
}
void
F_111 (
struct V_177 * V_178 )
{
struct V_1 * log = F_112 ( F_113 ( V_178 ) ,
struct V_1 , V_118 ) ;
struct V_36 * V_37 = log -> V_149 ;
if ( F_87 ( V_37 ) )
F_114 ( V_37 ) ;
else
F_79 ( V_37 , 0 ) ;
F_115 ( V_37 -> V_89 ) ;
F_67 ( V_37 ) ;
}
STATIC struct V_1 *
F_52 (
struct V_36 * V_37 ,
struct V_179 * V_74 ,
T_10 V_75 ,
int V_76 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_180 ;
T_11 * V_59 , * V_181 = NULL ;
T_14 * V_150 ;
int V_182 ;
int error = V_54 ;
T_4 V_183 = 0 ;
log = F_116 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! log ) {
F_56 ( V_37 , L_15 ) ;
goto V_82;
}
log -> V_149 = V_37 ;
log -> V_184 = V_74 ;
log -> V_9 = F_100 ( V_76 ) ;
log -> V_185 = V_75 ;
log -> V_186 = V_76 ;
log -> V_133 = V_136 ;
log -> V_25 |= V_26 ;
F_117 ( & log -> V_118 , F_111 ) ;
log -> V_187 = - 1 ;
F_118 ( & log -> V_144 , 1 , 0 ) ;
F_118 ( & log -> V_143 , 1 , 0 ) ;
log -> V_188 = 1 ;
F_7 ( & log -> V_56 ) ;
F_7 ( & log -> V_18 ) ;
error = V_189 ;
if ( F_119 ( & V_37 -> V_80 ) ) {
V_183 = V_37 -> V_80 . V_190 ;
if ( V_183 < V_169 ) {
F_56 ( V_37 , L_16 ,
V_183 , V_169 ) ;
goto V_87;
}
V_183 -= V_169 ;
if ( V_183 > V_37 -> V_191 ) {
F_56 ( V_37 , L_17 ,
V_183 , V_37 -> V_191 ) ;
goto V_87;
}
if ( V_183 && log -> V_185 > 0 &&
! F_108 ( & V_37 -> V_80 ) ) {
F_56 ( V_37 ,
L_18 ,
V_183 ) ;
goto V_87;
}
}
log -> V_192 = 1 << V_183 ;
F_107 ( V_37 , log ) ;
error = V_54 ;
V_150 = F_120 ( V_37 -> V_193 , 0 , F_121 ( log -> V_165 ) , 0 ) ;
if ( ! V_150 )
goto V_87;
ASSERT ( F_122 ( V_150 ) ) ;
F_83 ( V_150 ) ;
V_150 -> V_194 = F_101 ;
log -> V_195 = V_150 ;
F_10 ( & log -> V_114 ) ;
F_123 ( & log -> V_196 ) ;
V_180 = & log -> V_94 ;
ASSERT ( log -> V_165 >= 4096 ) ;
for ( V_182 = 0 ; V_182 < log -> V_162 ; V_182 ++ ) {
* V_180 = F_116 ( sizeof( T_11 ) , V_53 ) ;
if ( ! * V_180 )
goto V_197;
V_59 = * V_180 ;
V_59 -> V_198 = V_181 ;
V_181 = V_59 ;
V_150 = F_124 ( V_37 -> V_193 ,
F_121 ( log -> V_165 ) , 0 ) ;
if ( ! V_150 )
goto V_197;
ASSERT ( F_122 ( V_150 ) ) ;
F_83 ( V_150 ) ;
V_150 -> V_194 = F_101 ;
V_59 -> V_199 = V_150 ;
V_59 -> V_200 = V_150 -> V_201 ;
#ifdef F_69
log -> V_202 [ V_182 ] = ( V_203 ) & ( V_59 -> V_204 ) ;
#endif
V_2 = & V_59 -> V_204 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_205 = F_125 ( V_206 ) ;
V_2 -> V_207 = F_125 (
F_108 ( & log -> V_149 -> V_80 ) ? 2 : 1 ) ;
V_2 -> V_208 = F_125 ( log -> V_165 ) ;
V_2 -> V_209 = F_125 ( V_210 ) ;
memcpy ( & V_2 -> V_211 , & V_37 -> V_80 . V_212 , sizeof( V_213 ) ) ;
V_59 -> V_214 = F_100 ( V_150 -> V_215 ) - log -> V_168 ;
V_59 -> V_67 = V_69 ;
V_59 -> V_153 = log ;
F_126 ( & V_59 -> V_115 , 0 ) ;
F_10 ( & V_59 -> V_66 ) ;
V_59 -> V_72 = & ( V_59 -> V_216 ) ;
V_59 -> V_217 = ( char * ) V_59 -> V_200 + log -> V_168 ;
F_123 ( & V_59 -> V_117 ) ;
F_123 ( & V_59 -> V_218 ) ;
V_180 = & V_59 -> V_96 ;
}
* V_180 = log -> V_94 ;
log -> V_94 -> V_198 = V_181 ;
error = F_127 ( log ) ;
if ( error )
goto V_197;
return log ;
V_197:
for ( V_59 = log -> V_94 ; V_59 ; V_59 = V_181 ) {
V_181 = V_59 -> V_96 ;
if ( V_59 -> V_199 )
F_128 ( V_59 -> V_199 ) ;
F_129 ( V_59 ) ;
}
F_130 ( & log -> V_114 ) ;
F_128 ( log -> V_195 ) ;
V_87:
F_129 ( log ) ;
V_82:
return F_131 ( - error ) ;
}
STATIC int
F_38 (
struct V_1 * log ,
struct V_15 * V_57 ,
struct V_58 * * V_59 ,
T_6 * V_219 )
{
struct V_36 * V_37 = log -> V_149 ;
int error ;
struct V_102 V_103 = {
. V_104 = NULL ,
. V_105 = 0 ,
. V_106 = V_220 ,
} ;
struct V_108 V_109 = {
. V_110 = 1 ,
. V_111 = & V_103 ,
} ;
F_45 ( V_59 ) ;
error = F_71 ( log , & V_109 , V_57 , V_219 , V_59 ,
V_221 ) ;
if ( error )
F_48 ( V_37 , V_73 ) ;
return error ;
}
STATIC void
F_29 (
struct V_1 * log ,
int V_24 )
{
T_6 V_222 = 0 ;
T_6 V_223 ;
int V_224 ;
int V_23 ;
int V_225 ;
int V_226 ;
int V_227 ;
ASSERT ( F_121 ( V_24 ) < log -> V_186 ) ;
V_23 = F_21 ( log , & log -> V_56 . V_12 ) ;
V_224 = F_132 ( V_23 ) ;
V_227 = F_121 ( V_24 ) ;
V_227 = F_133 ( V_227 , ( log -> V_186 >> 2 ) ) ;
V_227 = F_133 ( V_227 , 256 ) ;
if ( V_224 >= V_227 )
return;
F_99 ( & log -> V_144 , & V_226 ,
& V_225 ) ;
V_225 += V_227 ;
if ( V_225 >= log -> V_186 ) {
V_225 -= log -> V_186 ;
V_226 += 1 ;
}
V_222 = F_134 ( V_226 ,
V_225 ) ;
V_223 = F_2 ( & log -> V_143 ) ;
if ( F_135 ( V_222 , V_223 ) > 0 )
V_222 = V_223 ;
if ( ! F_26 ( log ) )
F_136 ( log -> V_88 , V_222 ) ;
}
STATIC void
F_137 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_228 )
{
int V_182 , V_229 , V_230 ;
int V_159 = V_59 -> V_95 + V_228 ;
T_16 V_231 ;
V_203 V_232 ;
V_231 = F_138 ( V_59 -> V_204 . V_233 ) ;
V_232 = V_59 -> V_217 ;
for ( V_182 = 0 ; V_182 < F_121 ( V_159 ) ; V_182 ++ ) {
if ( V_182 >= ( V_167 / V_172 ) )
break;
V_59 -> V_204 . V_234 [ V_182 ] = * ( T_16 * ) V_232 ;
* ( T_16 * ) V_232 = V_231 ;
V_232 += V_172 ;
}
if ( F_108 ( & log -> V_149 -> V_80 ) ) {
T_17 * V_235 = V_59 -> V_200 ;
for ( ; V_182 < F_121 ( V_159 ) ; V_182 ++ ) {
V_229 = V_182 / ( V_167 / V_172 ) ;
V_230 = V_182 % ( V_167 / V_172 ) ;
V_235 [ V_229 ] . V_236 . V_237 [ V_230 ] = * ( T_16 * ) V_232 ;
* ( T_16 * ) V_232 = V_231 ;
V_232 += V_172 ;
}
for ( V_182 = 1 ; V_182 < log -> V_170 ; V_182 ++ )
V_235 [ V_182 ] . V_236 . V_238 = V_231 ;
}
}
T_18
F_139 (
struct V_1 * log ,
struct V_239 * V_240 ,
char * V_232 ,
int V_159 )
{
T_13 V_241 ;
V_241 = F_140 ( ( char * ) V_240 ,
sizeof( struct V_239 ) ,
F_141 ( struct V_239 , V_242 ) ) ;
if ( F_108 ( & log -> V_149 -> V_80 ) ) {
union V_243 * V_235 = (union V_243 * ) V_240 ;
int V_182 ;
for ( V_182 = 1 ; V_182 < log -> V_170 ; V_182 ++ ) {
V_241 = F_142 ( V_241 , & V_235 [ V_182 ] . V_236 ,
sizeof( struct V_244 ) ) ;
}
}
V_241 = F_142 ( V_241 , V_232 , V_159 ) ;
return F_143 ( V_241 ) ;
}
STATIC int
F_144 (
struct V_245 * V_150 )
{
struct V_58 * V_59 = V_150 -> V_151 ;
F_82 ( V_150 ) ;
if ( V_59 -> V_67 & V_68 ) {
F_145 ( V_150 , V_39 ) ;
F_104 ( V_150 ) ;
F_146 ( V_150 , 0 ) ;
return 0 ;
}
F_147 ( V_150 ) ;
return 0 ;
}
STATIC int
F_148 (
struct V_1 * log ,
struct V_58 * V_59 )
{
T_14 * V_150 ;
int V_182 ;
T_4 V_246 ;
T_4 V_247 ;
int V_228 ;
int V_248 = 0 ;
int error ;
int V_249 = F_108 ( & log -> V_149 -> V_80 ) ;
int V_159 ;
F_28 ( V_250 ) ;
ASSERT ( F_149 ( & V_59 -> V_115 ) == 0 ) ;
V_247 = log -> V_168 + V_59 -> V_95 ;
if ( V_249 && log -> V_149 -> V_80 . V_251 > 1 ) {
V_246 = F_150 ( log , F_151 ( log , V_247 ) ) ;
} else {
V_246 = F_100 ( F_121 ( V_247 ) ) ;
}
V_228 = V_246 - V_247 ;
ASSERT ( V_228 >= 0 ) ;
ASSERT ( ( V_249 && log -> V_149 -> V_80 . V_251 > 1 &&
V_228 < log -> V_149 -> V_80 . V_251 )
||
( log -> V_149 -> V_80 . V_251 <= 1 &&
V_228 < F_100 ( 1 ) ) ) ;
F_6 ( log , & log -> V_56 . V_12 , V_228 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_228 ) ;
F_137 ( log , V_59 , V_228 ) ;
V_159 = V_59 -> V_95 ;
if ( V_249 )
V_159 += V_228 ;
V_59 -> V_204 . V_252 = F_125 ( V_159 ) ;
V_150 = V_59 -> V_199 ;
F_152 ( V_150 , F_153 ( F_154 ( V_59 -> V_204 . V_233 ) ) ) ;
F_155 ( V_253 , F_121 ( V_246 ) ) ;
if ( F_156 ( V_150 ) + F_121 ( V_246 ) > log -> V_186 ) {
char * V_254 ;
V_248 = V_246 - ( F_100 ( log -> V_186 - F_156 ( V_150 ) ) ) ;
V_246 = F_100 ( log -> V_186 - F_156 ( V_150 ) ) ;
V_59 -> V_255 = 2 ;
V_254 = ( char * ) & V_59 -> V_204 + V_246 ;
for ( V_182 = 0 ; V_182 < V_248 ; V_182 += V_172 ) {
T_13 V_7 = F_157 ( * ( T_16 * ) V_254 ) ;
if ( ++ V_7 == V_206 )
V_7 ++ ;
* ( T_16 * ) V_254 = F_125 ( V_7 ) ;
V_254 += V_172 ;
}
} else {
V_59 -> V_255 = 1 ;
}
V_59 -> V_204 . V_242 = F_139 ( log , & V_59 -> V_204 ,
V_59 -> V_217 , V_159 ) ;
V_150 -> V_256 = F_121 ( V_246 ) ;
V_150 -> V_151 = V_59 ;
F_158 ( V_150 ) ;
F_159 ( V_150 ) ;
V_150 -> V_257 |= V_258 ;
if ( log -> V_149 -> V_78 & V_259 ) {
V_150 -> V_257 |= V_260 ;
if ( log -> V_149 -> V_193 != log -> V_149 -> V_119 )
F_160 ( log -> V_149 -> V_119 ) ;
else
V_150 -> V_257 |= V_261 ;
}
ASSERT ( F_156 ( V_150 ) <= log -> V_186 - 1 ) ;
ASSERT ( F_156 ( V_150 ) + F_121 ( V_246 ) <= log -> V_186 ) ;
F_161 ( log , V_59 , V_246 , true ) ;
F_152 ( V_150 , F_156 ( V_150 ) + log -> V_185 ) ;
F_162 ( V_150 ) ;
error = F_144 ( V_150 ) ;
if ( error ) {
F_103 ( V_150 , L_19 ) ;
return error ;
}
if ( V_248 ) {
V_150 = V_59 -> V_153 -> V_195 ;
F_152 ( V_150 , 0 ) ;
F_163 ( V_150 ,
( char * ) & V_59 -> V_204 + V_246 , V_248 ) ;
V_150 -> V_151 = V_59 ;
F_158 ( V_150 ) ;
F_159 ( V_150 ) ;
V_150 -> V_257 |= V_258 ;
if ( log -> V_149 -> V_78 & V_259 )
V_150 -> V_257 |= V_260 ;
ASSERT ( F_156 ( V_150 ) <= log -> V_186 - 1 ) ;
ASSERT ( F_156 ( V_150 ) + F_121 ( V_246 ) <= log -> V_186 ) ;
F_152 ( V_150 , F_156 ( V_150 ) + log -> V_185 ) ;
F_162 ( V_150 ) ;
error = F_144 ( V_150 ) ;
if ( error ) {
F_103 ( V_150 , L_20 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_64 (
struct V_1 * log )
{
T_11 * V_59 , * V_262 ;
int V_182 ;
F_164 ( log ) ;
V_59 = log -> V_94 ;
for ( V_182 = 0 ; V_182 < log -> V_162 ; V_182 ++ ) {
F_82 ( V_59 -> V_199 ) ;
F_83 ( V_59 -> V_199 ) ;
V_59 = V_59 -> V_96 ;
}
F_82 ( log -> V_195 ) ;
F_83 ( log -> V_195 ) ;
F_165 ( log -> V_195 , F_121 ( log -> V_165 ) ) ;
F_128 ( log -> V_195 ) ;
V_59 = log -> V_94 ;
for ( V_182 = 0 ; V_182 < log -> V_162 ; V_182 ++ ) {
F_128 ( V_59 -> V_199 ) ;
V_262 = V_59 -> V_96 ;
F_129 ( V_59 ) ;
V_59 = V_262 ;
}
F_130 ( & log -> V_114 ) ;
log -> V_149 -> V_38 = NULL ;
F_129 ( log ) ;
}
static inline void
F_166 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_263 ,
int V_264 )
{
F_12 ( & log -> V_114 ) ;
F_167 ( & V_59 -> V_204 . V_265 , V_263 ) ;
V_59 -> V_95 += V_264 ;
F_15 ( & log -> V_114 ) ;
}
void
F_168 (
struct V_36 * V_37 ,
struct V_15 * V_57 )
{
T_4 V_182 ;
T_4 V_266 = V_57 -> V_29 * ( T_4 ) sizeof( V_267 ) ;
static char * V_268 [ V_269 ] = {
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
L_35 ,
L_36 ,
L_37 ,
L_38 ,
L_39
} ;
static char * V_270 [ V_271 ] = {
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
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79
} ;
F_56 ( V_37 ,
L_80
L_81
L_82
L_83
L_84
L_85
L_86
L_87 ,
( ( V_57 -> V_55 <= 0 ||
V_57 -> V_55 > V_271 ) ?
L_88 : V_270 [ V_57 -> V_55 - 1 ] ) ,
V_57 -> V_55 ,
V_57 -> V_21 ,
V_57 -> V_42 ,
V_57 -> V_28 , V_57 -> V_32 ,
V_57 -> V_29 , V_266 ,
V_57 -> V_28 +
V_57 -> V_32 + V_266 ,
V_57 -> V_27 ) ;
for ( V_182 = 0 ; V_182 < V_57 -> V_27 ; V_182 ++ ) {
T_4 V_35 = V_57 -> V_33 [ V_182 ] . V_35 ;
F_56 ( V_37 , L_89 , V_182 ,
( ( V_35 <= 0 || V_35 > V_269 ) ?
L_90 : V_268 [ V_35 - 1 ] ) ,
V_57 -> V_33 [ V_182 ] . V_34 ) ;
}
F_169 ( V_37 , V_272 ,
L_91 ) ;
F_48 ( V_37 , V_73 ) ;
}
static int
F_170 (
struct V_15 * V_57 ,
struct V_108 * V_273 )
{
struct V_108 * V_274 ;
int V_275 = 0 ;
int V_30 = 0 ;
int V_182 ;
if ( V_57 -> V_19 & V_62 )
V_275 ++ ;
for ( V_274 = V_273 ; V_274 ; V_274 = V_274 -> V_276 ) {
if ( V_274 -> V_277 == V_278 )
continue;
V_275 += V_274 -> V_110 ;
for ( V_182 = 0 ; V_182 < V_274 -> V_110 ; V_182 ++ ) {
struct V_102 * V_279 = & V_274 -> V_111 [ V_182 ] ;
V_30 += V_279 -> V_105 ;
F_24 ( V_57 , V_279 -> V_105 , V_279 -> V_106 ) ;
}
}
V_57 -> V_29 += V_275 ;
V_30 += V_275 * sizeof( struct V_280 ) ;
return V_30 ;
}
static int
F_171 (
struct V_280 * V_281 ,
struct V_15 * V_57 )
{
if ( ! ( V_57 -> V_19 & V_62 ) )
return 0 ;
V_281 -> V_282 = F_125 ( V_57 -> V_41 ) ;
V_281 -> V_283 = V_57 -> V_284 ;
V_281 -> V_285 = 0 ;
V_281 -> V_286 = V_287 ;
V_281 -> V_288 = 0 ;
V_57 -> V_19 &= ~ V_62 ;
return sizeof( struct V_280 ) ;
}
static V_267 *
F_172 (
struct V_1 * log ,
struct V_280 * V_281 ,
struct V_15 * V_57 ,
T_4 V_60 )
{
V_281 -> V_282 = F_125 ( V_57 -> V_41 ) ;
V_281 -> V_283 = V_57 -> V_284 ;
V_281 -> V_288 = 0 ;
V_281 -> V_286 = V_60 ;
switch ( V_281 -> V_283 ) {
case V_50 :
case V_289 :
case V_51 :
break;
default:
F_56 ( log -> V_149 ,
L_92 ,
V_281 -> V_283 , V_57 ) ;
return NULL ;
}
return V_281 ;
}
static int
F_173 (
struct V_15 * V_57 ,
struct V_280 * V_281 ,
int V_290 ,
int V_291 ,
int * V_292 ,
int * V_293 ,
int * V_294 ,
int * V_295 )
{
int V_296 ;
V_296 = V_291 - * V_295 ;
* V_292 = * V_295 ;
if ( V_296 <= V_290 ) {
* V_293 = V_296 ;
V_281 -> V_285 = F_125 ( * V_293 ) ;
if ( * V_294 )
V_281 -> V_286 |= ( V_297 | V_298 ) ;
* V_294 = 0 ;
* V_295 = 0 ;
return 0 ;
}
* V_293 = V_290 ;
V_281 -> V_285 = F_125 ( * V_293 ) ;
V_281 -> V_286 |= V_299 ;
if ( * V_294 )
V_281 -> V_286 |= V_298 ;
* V_295 += * V_293 ;
( * V_294 ) ++ ;
V_57 -> V_42 -= sizeof( struct V_280 ) ;
V_57 -> V_29 ++ ;
return sizeof( struct V_280 ) ;
}
static int
F_174 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_4 V_60 ,
int * V_263 ,
int * V_300 ,
int * V_301 ,
int * V_302 ,
int V_303 ,
struct V_58 * * V_304 )
{
if ( * V_301 ) {
F_166 ( log , V_59 , * V_263 , * V_300 ) ;
* V_263 = 0 ;
* V_300 = 0 ;
return F_47 ( log , V_59 ) ;
}
* V_301 = 0 ;
* V_302 = 0 ;
if ( V_59 -> V_214 - V_303 <= sizeof( V_267 ) ) {
F_166 ( log , V_59 , * V_263 , * V_300 ) ;
* V_263 = 0 ;
* V_300 = 0 ;
F_12 ( & log -> V_114 ) ;
F_74 ( log , V_59 ) ;
F_15 ( & log -> V_114 ) ;
if ( ! V_304 )
return F_47 ( log , V_59 ) ;
ASSERT ( V_60 & V_221 ) ;
* V_304 = V_59 ;
}
return 0 ;
}
int
F_71 (
struct V_1 * log ,
struct V_108 * V_273 ,
struct V_15 * V_57 ,
T_6 * V_305 ,
struct V_58 * * V_304 ,
T_4 V_60 )
{
struct V_58 * V_59 = NULL ;
struct V_102 * V_279 ;
struct V_108 * V_274 ;
int V_30 ;
int V_306 ;
int V_301 = 0 ;
int V_302 = 0 ;
int V_307 = 0 ;
int V_263 = 0 ;
int V_300 = 0 ;
int error ;
* V_305 = 0 ;
V_30 = F_170 ( V_57 , V_273 ) ;
if ( V_57 -> V_19 & V_62 )
V_57 -> V_42 -= sizeof( V_267 ) ;
if ( V_60 & ( V_221 | V_112 ) )
V_57 -> V_42 -= sizeof( V_267 ) ;
if ( V_57 -> V_42 < 0 )
F_168 ( log -> V_149 , V_57 ) ;
V_306 = 0 ;
V_274 = V_273 ;
V_279 = V_274 -> V_111 ;
while ( V_274 && ( ! V_274 -> V_110 || V_306 < V_274 -> V_110 ) ) {
void * V_308 ;
int V_303 ;
error = F_175 ( log , V_30 , & V_59 , V_57 ,
& V_307 , & V_303 ) ;
if ( error )
return error ;
ASSERT ( V_303 <= V_59 -> V_214 - 1 ) ;
V_308 = V_59 -> V_217 + V_303 ;
if ( ! * V_305 )
* V_305 = F_154 ( V_59 -> V_204 . V_233 ) ;
while ( V_274 && ( ! V_274 -> V_110 || V_306 < V_274 -> V_110 ) ) {
struct V_102 * V_103 ;
struct V_280 * V_281 ;
int V_309 ;
int V_293 ;
int V_292 ;
bool V_310 = false ;
if ( V_274 -> V_277 == V_278 ) {
ASSERT ( V_274 -> V_110 == 0 ) ;
V_310 = true ;
goto V_311;
}
V_103 = & V_279 [ V_306 ] ;
ASSERT ( V_103 -> V_105 % sizeof( V_312 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_308 % sizeof( V_312 ) == 0 ) ;
V_309 = F_171 ( V_308 , V_57 ) ;
if ( V_309 ) {
V_263 ++ ;
F_176 ( & V_308 , & V_30 , & V_303 ,
V_309 ) ;
}
V_281 = F_172 ( log , V_308 , V_57 , V_60 ) ;
if ( ! V_281 )
return F_27 ( V_39 ) ;
F_176 ( & V_308 , & V_30 , & V_303 ,
sizeof( struct V_280 ) ) ;
V_30 += F_173 ( V_57 , V_281 ,
V_59 -> V_214 - V_303 ,
V_103 -> V_105 ,
& V_292 , & V_293 ,
& V_301 ,
& V_302 ) ;
F_177 ( log , V_308 ) ;
ASSERT ( V_293 >= 0 ) ;
memcpy ( V_308 , V_103 -> V_104 + V_292 , V_293 ) ;
F_176 ( & V_308 , & V_30 , & V_303 , V_293 ) ;
V_293 += V_309 + sizeof( V_267 ) ;
V_263 ++ ;
V_300 += V_307 ? V_293 : 0 ;
error = F_174 ( log , V_59 , V_60 ,
& V_263 , & V_300 ,
& V_301 ,
& V_302 ,
V_303 ,
V_304 ) ;
if ( error )
return error ;
if ( V_301 )
break;
if ( ++ V_306 == V_274 -> V_110 ) {
V_311:
V_274 = V_274 -> V_276 ;
V_306 = 0 ;
if ( V_274 )
V_279 = V_274 -> V_111 ;
}
if ( V_263 == 0 && V_310 == false ) {
if ( ! V_274 )
return 0 ;
break;
}
}
}
ASSERT ( V_30 == 0 ) ;
F_166 ( log , V_59 , V_263 , V_300 ) ;
if ( ! V_304 )
return F_47 ( log , V_59 ) ;
ASSERT ( V_60 & V_221 ) ;
* V_304 = V_59 ;
return 0 ;
}
STATIC void
F_178 (
struct V_1 * log )
{
T_11 * V_59 ;
int V_313 = 0 ;
V_59 = log -> V_94 ;
do {
if ( V_59 -> V_67 == V_116 ) {
V_59 -> V_67 = V_69 ;
V_59 -> V_95 = 0 ;
ASSERT ( V_59 -> V_216 == NULL ) ;
if ( ! V_313 &&
( F_157 ( V_59 -> V_204 . V_265 ) ==
V_314 ) ) {
V_313 = 1 ;
} else {
V_313 = 2 ;
}
V_59 -> V_204 . V_265 = 0 ;
memset ( V_59 -> V_204 . V_234 , 0 ,
sizeof( V_59 -> V_204 . V_234 ) ) ;
V_59 -> V_204 . V_233 = 0 ;
} else if ( V_59 -> V_67 == V_69 )
;
else
break;
V_59 = V_59 -> V_96 ;
} while ( V_59 != log -> V_94 );
if ( V_313 ) {
switch ( log -> V_133 ) {
case V_136 :
case V_137 :
case V_138 :
log -> V_133 = V_137 ;
break;
case V_134 :
if ( V_313 == 1 )
log -> V_133 = V_138 ;
else
log -> V_133 = V_137 ;
break;
case V_135 :
if ( V_313 == 1 )
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
F_179 (
struct V_1 * log )
{
T_11 * V_315 ;
T_6 V_316 , V_61 ;
V_315 = log -> V_94 ;
V_316 = 0 ;
do {
if ( ! ( V_315 -> V_67 & ( V_69 | V_116 ) ) ) {
V_61 = F_154 ( V_315 -> V_204 . V_233 ) ;
if ( ( V_61 && ! V_316 ) ||
( F_135 ( V_61 , V_316 ) < 0 ) ) {
V_316 = V_61 ;
}
}
V_315 = V_315 -> V_96 ;
} while ( V_315 != log -> V_94 );
return V_316 ;
}
STATIC void
F_180 (
struct V_1 * log ,
int V_154 ,
struct V_58 * V_317 )
{
T_11 * V_59 ;
T_11 * V_92 ;
T_7 * V_64 , * V_71 ;
int V_318 = 0 ;
T_6 V_316 ;
int V_319 ;
int V_320 ;
int V_321 ;
int V_322 ;
int V_323 = 0 ;
F_12 ( & log -> V_114 ) ;
V_92 = V_59 = log -> V_94 ;
V_319 = 0 ;
V_321 = 0 ;
V_322 = 0 ;
do {
V_92 = log -> V_94 ;
V_59 = log -> V_94 ;
V_320 = 0 ;
V_322 ++ ;
do {
if ( V_59 -> V_67 &
( V_69 | V_116 ) ) {
V_59 = V_59 -> V_96 ;
continue;
}
if ( ! ( V_59 -> V_67 & V_68 ) ) {
if ( ! ( V_59 -> V_67 &
( V_324 |
V_325 ) ) ) {
if ( V_317 && ( V_317 -> V_67 ==
V_324 ) ) {
V_317 -> V_67 = V_325 ;
}
break;
}
V_316 = F_179 ( log ) ;
if ( V_316 &&
F_135 ( V_316 ,
F_154 ( V_59 -> V_204 . V_233 ) ) < 0 ) {
V_59 = V_59 -> V_96 ;
continue;
}
V_59 -> V_67 = V_326 ;
ASSERT ( F_135 ( F_2 ( & log -> V_143 ) ,
F_154 ( V_59 -> V_204 . V_233 ) ) <= 0 ) ;
if ( V_59 -> V_216 )
F_96 ( & log -> V_143 ,
F_154 ( V_59 -> V_204 . V_233 ) ) ;
} else
V_319 ++ ;
F_15 ( & log -> V_114 ) ;
F_12 ( & V_59 -> V_66 ) ;
V_64 = V_59 -> V_216 ;
while ( V_64 ) {
V_59 -> V_72 = & ( V_59 -> V_216 ) ;
V_59 -> V_216 = NULL ;
F_15 ( & V_59 -> V_66 ) ;
for (; V_64 ; V_64 = V_71 ) {
V_71 = V_64 -> V_71 ;
V_64 -> V_327 ( V_64 -> V_328 , V_154 ) ;
}
F_12 ( & V_59 -> V_66 ) ;
V_64 = V_59 -> V_216 ;
}
V_320 ++ ;
V_321 ++ ;
F_12 ( & log -> V_114 ) ;
ASSERT ( V_59 -> V_216 == NULL ) ;
F_15 ( & V_59 -> V_66 ) ;
if ( ! ( V_59 -> V_67 & V_68 ) )
V_59 -> V_67 = V_116 ;
F_178 ( log ) ;
F_181 ( & V_59 -> V_117 ) ;
V_59 = V_59 -> V_96 ;
} while ( V_92 != V_59 );
if ( V_322 > 5000 ) {
V_318 += V_322 ;
V_322 = 0 ;
F_56 ( log -> V_149 ,
L_93 ,
V_113 , V_318 ) ;
}
} while ( ! V_319 && V_320 );
#ifdef F_69
if ( V_321 ) {
V_92 = V_59 = log -> V_94 ;
do {
ASSERT ( V_59 -> V_67 != V_325 ) ;
if ( V_59 -> V_67 == V_70 ||
V_59 -> V_67 == V_329 ||
V_59 -> V_67 == V_324 ||
V_59 -> V_67 == V_68 )
break;
V_59 = V_59 -> V_96 ;
} while ( V_92 != V_59 );
}
#endif
if ( log -> V_94 -> V_67 & ( V_69 | V_68 ) )
V_323 = 1 ;
F_15 ( & log -> V_114 ) ;
if ( V_323 )
F_181 ( & log -> V_196 ) ;
}
STATIC void
F_106 (
T_11 * V_59 ,
int V_154 )
{
struct V_1 * log = V_59 -> V_153 ;
F_12 ( & log -> V_114 ) ;
ASSERT ( V_59 -> V_67 == V_329 ||
V_59 -> V_67 == V_68 ) ;
ASSERT ( F_149 ( & V_59 -> V_115 ) == 0 ) ;
ASSERT ( V_59 -> V_255 == 1 || V_59 -> V_255 == 2 ) ;
if ( V_59 -> V_67 != V_68 ) {
if ( -- V_59 -> V_255 == 1 ) {
F_15 ( & log -> V_114 ) ;
return;
}
V_59 -> V_67 = V_324 ;
}
F_181 ( & V_59 -> V_218 ) ;
F_15 ( & log -> V_114 ) ;
F_180 ( log , V_154 , V_59 ) ;
}
STATIC int
F_175 (
struct V_1 * log ,
int V_30 ,
struct V_58 * * V_180 ,
struct V_15 * V_57 ,
int * V_330 ,
int * V_331 )
{
int V_303 ;
T_15 * V_2 ;
T_11 * V_59 ;
int error ;
V_332:
F_12 ( & log -> V_114 ) ;
if ( F_26 ( log ) ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
V_59 = log -> V_94 ;
if ( V_59 -> V_67 != V_69 ) {
F_28 ( V_333 ) ;
F_75 ( & log -> V_196 , & log -> V_114 ) ;
goto V_332;
}
V_2 = & V_59 -> V_204 ;
F_73 ( & V_59 -> V_115 ) ;
V_303 = V_59 -> V_95 ;
if ( V_303 == 0 ) {
V_57 -> V_42 -= log -> V_168 ;
F_24 ( V_57 ,
log -> V_168 ,
V_334 ) ;
V_2 -> V_335 = F_125 ( log -> V_188 ) ;
V_2 -> V_233 = F_182 (
F_134 ( log -> V_188 , log -> V_336 ) ) ;
ASSERT ( log -> V_336 >= 0 ) ;
}
if ( V_59 -> V_214 - V_59 -> V_95 < 2 * sizeof( V_267 ) ) {
F_183 ( log , V_59 , V_59 -> V_214 ) ;
if ( ! F_184 ( & V_59 -> V_115 , - 1 , 1 ) ) {
F_15 ( & log -> V_114 ) ;
error = F_47 ( log , V_59 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_114 ) ;
}
goto V_332;
}
if ( V_30 <= V_59 -> V_214 - V_59 -> V_95 ) {
* V_330 = 0 ;
V_59 -> V_95 += V_30 ;
} else {
* V_330 = 1 ;
F_183 ( log , V_59 , V_59 -> V_214 ) ;
}
* V_180 = V_59 ;
ASSERT ( V_59 -> V_95 <= V_59 -> V_214 ) ;
F_15 ( & log -> V_114 ) ;
* V_331 = V_303 ;
return 0 ;
}
STATIC void
F_43 (
struct V_1 * log ,
struct V_15 * V_57 )
{
F_185 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
V_57 -> V_22 -- ;
F_1 ( log , & log -> V_56 . V_12 ,
V_57 -> V_42 ) ;
F_1 ( log , & log -> V_18 . V_12 ,
V_57 -> V_42 ) ;
V_57 -> V_42 = V_57 -> V_21 ;
F_23 ( V_57 ) ;
F_186 ( log , V_57 ) ;
if ( V_57 -> V_22 > 0 )
return;
F_6 ( log , & log -> V_56 . V_12 ,
V_57 -> V_21 ) ;
F_187 ( log , V_57 ) ;
V_57 -> V_42 = V_57 -> V_21 ;
F_23 ( V_57 ) ;
}
STATIC void
F_40 (
struct V_1 * log ,
struct V_15 * V_57 )
{
int V_3 ;
if ( V_57 -> V_22 > 0 )
V_57 -> V_22 -- ;
F_188 ( log , V_57 ) ;
F_189 ( log , V_57 ) ;
V_3 = V_57 -> V_42 ;
if ( V_57 -> V_22 > 0 ) {
ASSERT ( V_57 -> V_19 & V_20 ) ;
V_3 += V_57 -> V_21 * V_57 -> V_22 ;
}
F_1 ( log , & log -> V_56 . V_12 , V_3 ) ;
F_1 ( log , & log -> V_18 . V_12 , V_3 ) ;
F_190 ( log , V_57 ) ;
F_86 ( log -> V_149 ) ;
}
STATIC int
F_47 (
struct V_1 * log ,
struct V_58 * V_59 )
{
int V_337 = 0 ;
if ( V_59 -> V_67 & V_68 )
return F_27 ( V_39 ) ;
ASSERT ( F_149 ( & V_59 -> V_115 ) > 0 ) ;
if ( ! F_191 ( & V_59 -> V_115 , & log -> V_114 ) )
return 0 ;
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
ASSERT ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_70 ) ;
if ( V_59 -> V_67 == V_70 ) {
T_6 V_140 = F_97 ( log -> V_149 ) ;
V_337 ++ ;
V_59 -> V_67 = V_329 ;
V_59 -> V_204 . V_338 = F_182 ( V_140 ) ;
F_192 ( log , V_59 , V_140 ) ;
}
F_15 ( & log -> V_114 ) ;
if ( V_337 )
return F_148 ( log , V_59 ) ;
return 0 ;
}
STATIC void
F_183 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_339 )
{
ASSERT ( V_59 -> V_67 == V_69 ) ;
if ( ! V_339 )
V_339 = V_59 -> V_95 ;
V_59 -> V_67 = V_70 ;
V_59 -> V_204 . V_340 = F_125 ( log -> V_187 ) ;
log -> V_187 = log -> V_336 ;
log -> V_341 = log -> V_188 ;
log -> V_336 += F_121 ( V_339 ) + F_121 ( log -> V_168 ) ;
if ( F_108 ( & log -> V_149 -> V_80 ) &&
log -> V_149 -> V_80 . V_251 > 1 ) {
T_13 V_342 = F_121 ( log -> V_149 -> V_80 . V_251 ) ;
log -> V_336 = F_193 ( log -> V_336 , V_342 ) ;
}
if ( log -> V_336 >= log -> V_186 ) {
log -> V_188 ++ ;
if ( log -> V_188 == V_206 )
log -> V_188 ++ ;
log -> V_336 -= log -> V_186 ;
ASSERT ( log -> V_336 >= 0 ) ;
}
ASSERT ( V_59 == log -> V_94 ) ;
log -> V_94 = V_59 -> V_96 ;
}
int
F_70 (
struct V_36 * V_37 ,
T_4 V_60 ,
int * V_343 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
T_6 V_61 ;
F_28 ( V_344 ) ;
F_194 ( log ) ;
F_12 ( & log -> V_114 ) ;
V_59 = log -> V_94 ;
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
if ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_116 ) {
if ( V_59 -> V_67 == V_116 ||
( F_149 ( & V_59 -> V_115 ) == 0
&& V_59 -> V_95 == 0 ) ) {
V_59 = V_59 -> V_198 ;
if ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_116 )
goto V_345;
else
goto V_346;
} else {
if ( F_149 ( & V_59 -> V_115 ) == 0 ) {
F_73 ( & V_59 -> V_115 ) ;
V_61 = F_154 ( V_59 -> V_204 . V_233 ) ;
F_183 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_114 ) ;
if ( F_47 ( log , V_59 ) )
return F_27 ( V_39 ) ;
if ( V_343 )
* V_343 = 1 ;
F_12 ( & log -> V_114 ) ;
if ( F_154 ( V_59 -> V_204 . V_233 ) == V_61 &&
V_59 -> V_67 != V_116 )
goto V_346;
else
goto V_345;
} else {
F_183 ( log , V_59 , 0 ) ;
goto V_346;
}
}
}
V_346:
if ( V_60 & V_93 ) {
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
F_28 ( V_347 ) ;
F_75 ( & V_59 -> V_117 , & log -> V_114 ) ;
if ( V_59 -> V_67 & V_68 )
return F_27 ( V_39 ) ;
if ( V_343 )
* V_343 = 1 ;
} else {
V_345:
F_15 ( & log -> V_114 ) ;
}
return 0 ;
}
void
F_79 (
T_8 * V_37 ,
T_4 V_60 )
{
int error ;
F_195 ( V_37 , 0 ) ;
error = F_70 ( V_37 , V_60 , NULL ) ;
if ( error )
F_56 ( V_37 , L_94 , V_113 , error ) ;
}
int
F_196 (
struct V_36 * V_37 ,
T_6 V_61 ,
T_4 V_60 ,
int * V_343 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
int V_348 = 0 ;
ASSERT ( V_61 != 0 ) ;
F_28 ( V_344 ) ;
V_61 = F_197 ( log , V_61 ) ;
if ( V_61 == V_349 )
return 0 ;
V_350:
F_12 ( & log -> V_114 ) ;
V_59 = log -> V_94 ;
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
do {
if ( F_154 ( V_59 -> V_204 . V_233 ) != V_61 ) {
V_59 = V_59 -> V_96 ;
continue;
}
if ( V_59 -> V_67 == V_116 ) {
F_15 ( & log -> V_114 ) ;
return 0 ;
}
if ( V_59 -> V_67 == V_69 ) {
if ( ! V_348 &&
( V_59 -> V_198 -> V_67 &
( V_70 | V_329 ) ) ) {
ASSERT ( ! ( V_59 -> V_67 & V_68 ) ) ;
F_28 ( V_347 ) ;
F_75 ( & V_59 -> V_198 -> V_218 ,
& log -> V_114 ) ;
if ( V_343 )
* V_343 = 1 ;
V_348 = 1 ;
goto V_350;
}
F_73 ( & V_59 -> V_115 ) ;
F_183 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_114 ) ;
if ( F_47 ( log , V_59 ) )
return F_27 ( V_39 ) ;
if ( V_343 )
* V_343 = 1 ;
F_12 ( & log -> V_114 ) ;
}
if ( ( V_60 & V_93 ) &&
! ( V_59 -> V_67 &
( V_69 | V_116 ) ) ) {
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
F_28 ( V_347 ) ;
F_75 ( & V_59 -> V_117 , & log -> V_114 ) ;
if ( V_59 -> V_67 & V_68 )
return F_27 ( V_39 ) ;
if ( V_343 )
* V_343 = 1 ;
} else {
F_15 ( & log -> V_114 ) ;
}
return 0 ;
} while ( V_59 != log -> V_94 );
F_15 ( & log -> V_114 ) ;
return 0 ;
}
void
F_198 (
T_8 * V_37 ,
T_6 V_61 ,
T_4 V_60 )
{
int error ;
F_195 ( V_37 , V_61 ) ;
error = F_196 ( V_37 , V_61 , V_60 , NULL ) ;
if ( error )
F_56 ( V_37 , L_94 , V_113 , error ) ;
}
STATIC void
F_74 (
struct V_1 * log ,
struct V_58 * V_59 )
{
F_93 ( & log -> V_114 ) ;
if ( V_59 -> V_67 == V_69 ) {
F_183 ( log , V_59 , 0 ) ;
} else {
ASSERT ( V_59 -> V_67 &
( V_70 | V_68 ) ) ;
}
}
void
F_41 (
T_3 * V_57 )
{
ASSERT ( F_149 ( & V_57 -> V_351 ) > 0 ) ;
if ( F_199 ( & V_57 -> V_351 ) )
F_200 ( V_352 , V_57 ) ;
}
T_3 *
F_201 (
T_3 * V_57 )
{
ASSERT ( F_149 ( & V_57 -> V_351 ) > 0 ) ;
F_73 ( & V_57 -> V_351 ) ;
return V_57 ;
}
int
F_202 (
struct V_36 * V_37 ,
int V_44 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_353 ;
T_4 V_354 ;
V_44 += sizeof( V_267 ) ;
V_44 += sizeof( V_355 ) ;
V_44 += sizeof( V_267 ) ;
V_353 = log -> V_165 - log -> V_168 ;
V_354 = F_203 ( V_44 , V_353 ) ;
V_44 += sizeof( V_267 ) * V_354 ;
while ( ! V_354 ||
F_203 ( V_44 , V_353 ) > V_354 ) {
V_44 += sizeof( V_267 ) ;
V_354 ++ ;
}
V_44 += log -> V_168 * V_354 ;
V_44 += log -> V_168 ;
if ( F_108 ( & V_37 -> V_80 ) && V_37 -> V_80 . V_251 > 1 ) {
V_44 += 2 * V_37 -> V_80 . V_251 ;
} else {
V_44 += 2 * V_172 ;
}
return V_44 ;
}
struct V_15 *
F_34 (
struct V_1 * log ,
int V_44 ,
int V_45 ,
char V_47 ,
bool V_48 ,
T_19 V_356 )
{
struct V_15 * V_16 ;
int V_357 ;
V_16 = F_204 ( V_352 , V_356 ) ;
if ( ! V_16 )
return NULL ;
V_357 = F_202 ( log -> V_149 , V_44 ) ;
F_126 ( & V_16 -> V_351 , 1 ) ;
V_16 -> V_17 = V_358 ;
F_9 ( & V_16 -> V_359 ) ;
V_16 -> V_21 = V_357 ;
V_16 -> V_42 = V_357 ;
V_16 -> V_22 = V_45 ;
V_16 -> V_360 = V_45 ;
V_16 -> V_41 = F_205 () ;
V_16 -> V_284 = V_47 ;
V_16 -> V_19 = V_62 ;
V_16 -> V_55 = 0 ;
if ( V_48 )
V_16 -> V_19 |= V_20 ;
F_23 ( V_16 ) ;
return V_16 ;
}
void
F_177 (
struct V_1 * log ,
char * V_308 )
{
int V_182 ;
int V_361 = 0 ;
for ( V_182 = 0 ; V_182 < log -> V_162 ; V_182 ++ ) {
if ( V_308 >= log -> V_202 [ V_182 ] &&
V_308 <= log -> V_202 [ V_182 ] + log -> V_165 )
V_361 ++ ;
}
if ( ! V_361 )
F_206 ( log -> V_149 , L_95 , V_113 ) ;
}
STATIC void
F_32 (
struct V_1 * log )
{
int V_146 , V_362 ;
int V_7 , V_8 ;
F_98 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_99 ( & log -> V_144 , & V_146 , & V_362 ) ;
if ( V_146 != V_7 ) {
if ( V_7 - 1 != V_146 &&
! ( log -> V_25 & V_363 ) ) {
F_169 ( log -> V_149 , V_272 ,
L_96 , V_113 ) ;
log -> V_25 |= V_363 ;
}
if ( V_8 > F_100 ( V_362 ) &&
! ( log -> V_25 & V_363 ) ) {
F_169 ( log -> V_149 , V_272 ,
L_97 , V_113 ) ;
log -> V_25 |= V_363 ;
}
}
}
STATIC void
F_192 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_6 V_140 )
{
int V_364 ;
if ( F_207 ( V_140 ) == log -> V_341 ) {
V_364 =
log -> V_186 - ( log -> V_187 - F_153 ( V_140 ) ) ;
if ( V_364 < F_121 ( V_59 -> V_95 ) + F_121 ( log -> V_168 ) )
F_206 ( log -> V_149 , L_98 , V_113 ) ;
} else {
ASSERT ( F_207 ( V_140 ) + 1 == log -> V_341 ) ;
if ( F_153 ( V_140 ) == log -> V_187 )
F_206 ( log -> V_149 , L_99 , V_113 ) ;
V_364 = F_153 ( V_140 ) - log -> V_187 ;
if ( V_364 < F_121 ( V_59 -> V_95 ) + 1 )
F_206 ( log -> V_149 , L_98 , V_113 ) ;
}
}
STATIC void
F_161 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_246 ,
bool V_365 )
{
V_267 * V_366 ;
T_11 * V_367 ;
T_17 * V_235 ;
V_203 V_308 ;
V_203 V_368 ;
T_20 V_369 ;
T_5 V_370 ;
int V_30 , V_182 , V_229 , V_230 , V_371 ;
int V_372 ;
F_12 ( & log -> V_114 ) ;
V_367 = log -> V_94 ;
for ( V_182 = 0 ; V_182 < log -> V_162 ; V_182 ++ , V_367 = V_367 -> V_96 )
ASSERT ( V_367 ) ;
if ( V_367 != log -> V_94 )
F_206 ( log -> V_149 , L_100 , V_113 ) ;
F_15 ( & log -> V_114 ) ;
if ( V_59 -> V_204 . V_205 != F_125 ( V_206 ) )
F_206 ( log -> V_149 , L_101 , V_113 ) ;
V_308 = ( V_203 ) & V_59 -> V_204 ;
for ( V_308 += V_172 ; V_308 < ( ( V_203 ) & V_59 -> V_204 ) + V_246 ;
V_308 += V_172 ) {
if ( * ( T_16 * ) V_308 == F_125 ( V_206 ) )
F_206 ( log -> V_149 , L_102 ,
V_113 ) ;
}
V_30 = F_157 ( V_59 -> V_204 . V_265 ) ;
V_308 = V_59 -> V_217 ;
V_368 = V_308 ;
V_366 = ( V_267 * ) V_308 ;
V_235 = V_59 -> V_200 ;
for ( V_182 = 0 ; V_182 < V_30 ; V_182 ++ ) {
V_366 = ( V_267 * ) V_308 ;
V_369 = ( T_20 )
( ( V_203 ) & ( V_366 -> V_283 ) - V_368 ) ;
if ( ! V_365 || ( V_369 & 0x1ff ) ) {
V_370 = V_366 -> V_283 ;
} else {
V_372 = F_132 ( ( V_203 ) & ( V_366 -> V_283 ) - V_59 -> V_217 ) ;
if ( V_372 >= ( V_167 / V_172 ) ) {
V_229 = V_372 / ( V_167 / V_172 ) ;
V_230 = V_372 % ( V_167 / V_172 ) ;
V_370 = F_208 (
V_235 [ V_229 ] . V_236 . V_237 [ V_230 ] ) ;
} else {
V_370 = F_208 (
V_59 -> V_204 . V_234 [ V_372 ] ) ;
}
}
if ( V_370 != V_50 && V_370 != V_51 )
F_56 ( log -> V_149 ,
L_103 ,
V_113 , V_370 , V_366 ,
( unsigned long ) V_369 ) ;
V_369 = ( T_20 )
( ( V_203 ) & ( V_366 -> V_285 ) - V_368 ) ;
if ( ! V_365 || ( V_369 & 0x1ff ) ) {
V_371 = F_157 ( V_366 -> V_285 ) ;
} else {
V_372 = F_132 ( ( T_20 ) & V_366 -> V_285 -
( T_20 ) V_59 -> V_217 ) ;
if ( V_372 >= ( V_167 / V_172 ) ) {
V_229 = V_372 / ( V_167 / V_172 ) ;
V_230 = V_372 % ( V_167 / V_172 ) ;
V_371 = F_157 ( V_235 [ V_229 ] . V_236 . V_237 [ V_230 ] ) ;
} else {
V_371 = F_157 ( V_59 -> V_204 . V_234 [ V_372 ] ) ;
}
}
V_308 += sizeof( V_267 ) + V_371 ;
}
}
STATIC int
F_209 (
struct V_1 * log )
{
T_11 * V_59 , * V_373 ;
V_59 = log -> V_94 ;
if ( ! ( V_59 -> V_67 & V_68 ) ) {
V_373 = V_59 ;
do {
V_373 -> V_67 = V_68 ;
V_373 = V_373 -> V_96 ;
} while ( V_373 != V_59 );
return 0 ;
}
return 1 ;
}
int
F_210 (
struct V_36 * V_37 ,
int V_374 )
{
struct V_1 * log ;
int V_375 ;
log = V_37 -> V_38 ;
if ( ! log ||
log -> V_25 & V_26 ) {
V_37 -> V_78 |= V_376 ;
if ( V_37 -> V_120 )
F_211 ( V_37 -> V_120 ) ;
return 0 ;
}
if ( V_374 && log -> V_94 -> V_67 & V_68 ) {
ASSERT ( F_26 ( log ) ) ;
return 1 ;
}
V_375 = 0 ;
if ( ! V_374 )
F_194 ( log ) ;
F_12 ( & log -> V_114 ) ;
V_37 -> V_78 |= V_376 ;
if ( V_37 -> V_120 )
F_211 ( V_37 -> V_120 ) ;
log -> V_25 |= V_377 ;
if ( V_374 )
V_375 = F_209 ( log ) ;
F_15 ( & log -> V_114 ) ;
F_11 ( & log -> V_56 ) ;
F_11 ( & log -> V_18 ) ;
if ( ! ( log -> V_94 -> V_67 & V_68 ) ) {
ASSERT ( ! V_374 ) ;
F_70 ( V_37 , V_93 , NULL ) ;
F_12 ( & log -> V_114 ) ;
V_375 = F_209 ( log ) ;
F_15 ( & log -> V_114 ) ;
}
F_181 ( & log -> V_378 -> V_379 ) ;
F_180 ( log , V_158 , NULL ) ;
#ifdef F_212
{
T_11 * V_59 ;
F_12 ( & log -> V_114 ) ;
V_59 = log -> V_94 ;
do {
ASSERT ( V_59 -> V_216 == 0 ) ;
V_59 = V_59 -> V_96 ;
} while ( V_59 != log -> V_94 );
F_15 ( & log -> V_114 ) ;
}
#endif
return V_375 ;
}
STATIC int
F_91 (
struct V_1 * log )
{
T_11 * V_59 ;
V_59 = log -> V_94 ;
do {
if ( V_59 -> V_204 . V_265 )
return 0 ;
V_59 = V_59 -> V_96 ;
} while ( V_59 != log -> V_94 );
return 1 ;
}
