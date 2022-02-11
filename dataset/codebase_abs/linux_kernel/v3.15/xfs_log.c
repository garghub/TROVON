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
if ( F_102 ( ( F_103 ( V_150 ) ) , V_152 -> V_149 ,
V_155 , V_156 ) ) {
F_104 ( V_150 , V_113 ) ;
F_105 ( V_150 ) ;
F_48 ( V_152 -> V_149 , V_73 ) ;
V_154 = V_157 ;
} else if ( V_59 -> V_67 & V_68 ) {
V_154 = V_157 ;
}
ASSERT ( F_106 ( V_150 ) ) ;
F_107 ( V_59 , V_154 ) ;
F_83 ( V_150 ) ;
}
STATIC void
F_108 (
struct V_36 * V_37 ,
struct V_1 * log )
{
int V_158 ;
int V_159 ;
if ( V_37 -> V_160 <= 0 )
log -> V_161 = V_162 ;
else
log -> V_161 = V_37 -> V_160 ;
if ( V_37 -> V_163 > 0 ) {
V_158 = log -> V_164 = V_37 -> V_163 ;
log -> V_165 = 0 ;
while ( V_158 != 1 ) {
log -> V_165 ++ ;
V_158 >>= 1 ;
}
if ( F_109 ( & V_37 -> V_80 ) ) {
V_159 = V_37 -> V_163 / V_166 ;
if ( V_37 -> V_163 % V_166 )
V_159 ++ ;
log -> V_167 = V_159 << V_168 ;
log -> V_169 = V_159 ;
} else {
ASSERT ( V_37 -> V_163 <= V_170 ) ;
log -> V_167 = V_171 ;
log -> V_169 = 1 ;
}
goto V_172;
}
log -> V_164 = V_170 ;
log -> V_165 = V_173 ;
log -> V_167 = V_171 ;
log -> V_169 = 1 ;
V_172:
if ( V_37 -> V_160 == 0 )
V_37 -> V_160 = log -> V_161 ;
if ( V_37 -> V_163 == 0 )
V_37 -> V_163 = log -> V_164 ;
}
void
F_67 (
struct V_36 * V_37 )
{
F_110 ( V_37 -> V_174 , & V_37 -> V_38 -> V_118 ,
F_111 ( V_175 * 10 ) ) ;
}
void
F_112 (
struct V_176 * V_177 )
{
struct V_1 * log = F_113 ( F_114 ( V_177 ) ,
struct V_1 , V_118 ) ;
struct V_36 * V_37 = log -> V_149 ;
if ( F_87 ( V_37 ) )
F_115 ( V_37 ) ;
else
F_79 ( V_37 , 0 ) ;
F_116 ( V_37 -> V_89 ) ;
F_67 ( V_37 ) ;
}
STATIC struct V_1 *
F_52 (
struct V_36 * V_37 ,
struct V_178 * V_74 ,
T_10 V_75 ,
int V_76 )
{
struct V_1 * log ;
T_15 * V_2 ;
T_11 * * V_179 ;
T_11 * V_59 , * V_180 = NULL ;
T_14 * V_150 ;
int V_181 ;
int error = V_54 ;
T_4 V_182 = 0 ;
log = F_117 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! log ) {
F_56 ( V_37 , L_15 ) ;
goto V_82;
}
log -> V_149 = V_37 ;
log -> V_183 = V_74 ;
log -> V_9 = F_100 ( V_76 ) ;
log -> V_184 = V_75 ;
log -> V_185 = V_76 ;
log -> V_133 = V_136 ;
log -> V_25 |= V_26 ;
F_118 ( & log -> V_118 , F_112 ) ;
log -> V_186 = - 1 ;
F_119 ( & log -> V_144 , 1 , 0 ) ;
F_119 ( & log -> V_143 , 1 , 0 ) ;
log -> V_187 = 1 ;
F_7 ( & log -> V_56 ) ;
F_7 ( & log -> V_18 ) ;
error = V_188 ;
if ( F_120 ( & V_37 -> V_80 ) ) {
V_182 = V_37 -> V_80 . V_189 ;
if ( V_182 < V_168 ) {
F_56 ( V_37 , L_16 ,
V_182 , V_168 ) ;
goto V_87;
}
V_182 -= V_168 ;
if ( V_182 > V_37 -> V_190 ) {
F_56 ( V_37 , L_17 ,
V_182 , V_37 -> V_190 ) ;
goto V_87;
}
if ( V_182 && log -> V_184 > 0 &&
! F_109 ( & V_37 -> V_80 ) ) {
F_56 ( V_37 ,
L_18 ,
V_182 ) ;
goto V_87;
}
}
log -> V_191 = 1 << V_182 ;
F_108 ( V_37 , log ) ;
error = V_54 ;
V_150 = F_121 ( V_37 -> V_192 , 0 , F_122 ( log -> V_164 ) , 0 ) ;
if ( ! V_150 )
goto V_87;
ASSERT ( F_123 ( V_150 ) ) ;
F_83 ( V_150 ) ;
V_150 -> V_193 = F_101 ;
log -> V_194 = V_150 ;
F_10 ( & log -> V_114 ) ;
F_124 ( & log -> V_195 ) ;
V_179 = & log -> V_94 ;
ASSERT ( log -> V_164 >= 4096 ) ;
for ( V_181 = 0 ; V_181 < log -> V_161 ; V_181 ++ ) {
* V_179 = F_117 ( sizeof( T_11 ) , V_53 ) ;
if ( ! * V_179 )
goto V_196;
V_59 = * V_179 ;
V_59 -> V_197 = V_180 ;
V_180 = V_59 ;
V_150 = F_125 ( V_37 -> V_192 ,
F_122 ( log -> V_164 ) , 0 ) ;
if ( ! V_150 )
goto V_196;
ASSERT ( F_123 ( V_150 ) ) ;
F_83 ( V_150 ) ;
V_150 -> V_193 = F_101 ;
V_59 -> V_198 = V_150 ;
V_59 -> V_199 = V_150 -> V_200 ;
#ifdef F_69
log -> V_201 [ V_181 ] = ( V_202 ) & ( V_59 -> V_203 ) ;
#endif
V_2 = & V_59 -> V_203 ;
memset ( V_2 , 0 , sizeof( T_15 ) ) ;
V_2 -> V_204 = F_126 ( V_205 ) ;
V_2 -> V_206 = F_126 (
F_109 ( & log -> V_149 -> V_80 ) ? 2 : 1 ) ;
V_2 -> V_207 = F_126 ( log -> V_164 ) ;
V_2 -> V_208 = F_126 ( V_209 ) ;
memcpy ( & V_2 -> V_210 , & V_37 -> V_80 . V_211 , sizeof( V_212 ) ) ;
V_59 -> V_213 = F_100 ( V_150 -> V_214 ) - log -> V_167 ;
V_59 -> V_67 = V_69 ;
V_59 -> V_153 = log ;
F_127 ( & V_59 -> V_115 , 0 ) ;
F_10 ( & V_59 -> V_66 ) ;
V_59 -> V_72 = & ( V_59 -> V_215 ) ;
V_59 -> V_216 = ( char * ) V_59 -> V_199 + log -> V_167 ;
F_124 ( & V_59 -> V_117 ) ;
F_124 ( & V_59 -> V_217 ) ;
V_179 = & V_59 -> V_96 ;
}
* V_179 = log -> V_94 ;
log -> V_94 -> V_197 = V_180 ;
error = F_128 ( log ) ;
if ( error )
goto V_196;
return log ;
V_196:
for ( V_59 = log -> V_94 ; V_59 ; V_59 = V_180 ) {
V_180 = V_59 -> V_96 ;
if ( V_59 -> V_198 )
F_129 ( V_59 -> V_198 ) ;
F_130 ( V_59 ) ;
}
F_131 ( & log -> V_114 ) ;
F_129 ( log -> V_194 ) ;
V_87:
F_130 ( log ) ;
V_82:
return F_132 ( - error ) ;
}
STATIC int
F_38 (
struct V_1 * log ,
struct V_15 * V_57 ,
struct V_58 * * V_59 ,
T_6 * V_218 )
{
struct V_36 * V_37 = log -> V_149 ;
int error ;
struct V_102 V_103 = {
. V_104 = NULL ,
. V_105 = 0 ,
. V_106 = V_219 ,
} ;
struct V_108 V_109 = {
. V_110 = 1 ,
. V_111 = & V_103 ,
} ;
F_45 ( V_59 ) ;
error = F_71 ( log , & V_109 , V_57 , V_218 , V_59 ,
V_220 ) ;
if ( error )
F_48 ( V_37 , V_73 ) ;
return error ;
}
STATIC void
F_29 (
struct V_1 * log ,
int V_24 )
{
T_6 V_221 = 0 ;
T_6 V_222 ;
int V_223 ;
int V_23 ;
int V_224 ;
int V_225 ;
int V_226 ;
ASSERT ( F_122 ( V_24 ) < log -> V_185 ) ;
V_23 = F_21 ( log , & log -> V_56 . V_12 ) ;
V_223 = F_133 ( V_23 ) ;
V_226 = F_122 ( V_24 ) ;
V_226 = F_134 ( V_226 , ( log -> V_185 >> 2 ) ) ;
V_226 = F_134 ( V_226 , 256 ) ;
if ( V_223 >= V_226 )
return;
F_99 ( & log -> V_144 , & V_225 ,
& V_224 ) ;
V_224 += V_226 ;
if ( V_224 >= log -> V_185 ) {
V_224 -= log -> V_185 ;
V_225 += 1 ;
}
V_221 = F_135 ( V_225 ,
V_224 ) ;
V_222 = F_2 ( & log -> V_143 ) ;
if ( F_136 ( V_221 , V_222 ) > 0 )
V_221 = V_222 ;
if ( ! F_26 ( log ) )
F_137 ( log -> V_88 , V_221 ) ;
}
STATIC void
F_138 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_227 )
{
int V_181 , V_228 , V_229 ;
int V_158 = V_59 -> V_95 + V_227 ;
T_16 V_230 ;
V_202 V_231 ;
V_230 = F_139 ( V_59 -> V_203 . V_232 ) ;
V_231 = V_59 -> V_216 ;
for ( V_181 = 0 ; V_181 < F_122 ( V_158 ) ; V_181 ++ ) {
if ( V_181 >= ( V_166 / V_171 ) )
break;
V_59 -> V_203 . V_233 [ V_181 ] = * ( T_16 * ) V_231 ;
* ( T_16 * ) V_231 = V_230 ;
V_231 += V_171 ;
}
if ( F_109 ( & log -> V_149 -> V_80 ) ) {
T_17 * V_234 = V_59 -> V_199 ;
for ( ; V_181 < F_122 ( V_158 ) ; V_181 ++ ) {
V_228 = V_181 / ( V_166 / V_171 ) ;
V_229 = V_181 % ( V_166 / V_171 ) ;
V_234 [ V_228 ] . V_235 . V_236 [ V_229 ] = * ( T_16 * ) V_231 ;
* ( T_16 * ) V_231 = V_230 ;
V_231 += V_171 ;
}
for ( V_181 = 1 ; V_181 < log -> V_169 ; V_181 ++ )
V_234 [ V_181 ] . V_235 . V_237 = V_230 ;
}
}
T_18
F_140 (
struct V_1 * log ,
struct V_238 * V_239 ,
char * V_231 ,
int V_158 )
{
T_13 V_240 ;
V_240 = F_141 ( ( char * ) V_239 ,
sizeof( struct V_238 ) ,
F_142 ( struct V_238 , V_241 ) ) ;
if ( F_109 ( & log -> V_149 -> V_80 ) ) {
union V_242 * V_234 = (union V_242 * ) V_239 ;
int V_181 ;
for ( V_181 = 1 ; V_181 < log -> V_169 ; V_181 ++ ) {
V_240 = F_143 ( V_240 , & V_234 [ V_181 ] . V_235 ,
sizeof( struct V_243 ) ) ;
}
}
V_240 = F_143 ( V_240 , V_231 , V_158 ) ;
return F_144 ( V_240 ) ;
}
STATIC int
F_145 (
struct V_244 * V_150 )
{
struct V_58 * V_59 = V_150 -> V_151 ;
F_82 ( V_150 ) ;
if ( V_59 -> V_67 & V_68 ) {
F_146 ( V_150 , V_39 ) ;
F_105 ( V_150 ) ;
F_147 ( V_150 , 0 ) ;
return 0 ;
}
F_148 ( V_150 ) ;
return 0 ;
}
STATIC int
F_149 (
struct V_1 * log ,
struct V_58 * V_59 )
{
T_14 * V_150 ;
int V_181 ;
T_4 V_245 ;
T_4 V_246 ;
int V_227 ;
int V_247 = 0 ;
int error ;
int V_248 = F_109 ( & log -> V_149 -> V_80 ) ;
int V_158 ;
F_28 ( V_249 ) ;
ASSERT ( F_150 ( & V_59 -> V_115 ) == 0 ) ;
V_246 = log -> V_167 + V_59 -> V_95 ;
if ( V_248 && log -> V_149 -> V_80 . V_250 > 1 ) {
V_245 = F_151 ( log , F_152 ( log , V_246 ) ) ;
} else {
V_245 = F_100 ( F_122 ( V_246 ) ) ;
}
V_227 = V_245 - V_246 ;
ASSERT ( V_227 >= 0 ) ;
ASSERT ( ( V_248 && log -> V_149 -> V_80 . V_250 > 1 &&
V_227 < log -> V_149 -> V_80 . V_250 )
||
( log -> V_149 -> V_80 . V_250 <= 1 &&
V_227 < F_100 ( 1 ) ) ) ;
F_6 ( log , & log -> V_56 . V_12 , V_227 ) ;
F_6 ( log , & log -> V_18 . V_12 , V_227 ) ;
F_138 ( log , V_59 , V_227 ) ;
V_158 = V_59 -> V_95 ;
if ( V_248 )
V_158 += V_227 ;
V_59 -> V_203 . V_251 = F_126 ( V_158 ) ;
V_150 = V_59 -> V_198 ;
F_153 ( V_150 , F_154 ( F_155 ( V_59 -> V_203 . V_232 ) ) ) ;
F_156 ( V_252 , F_122 ( V_245 ) ) ;
if ( F_157 ( V_150 ) + F_122 ( V_245 ) > log -> V_185 ) {
char * V_253 ;
V_247 = V_245 - ( F_100 ( log -> V_185 - F_157 ( V_150 ) ) ) ;
V_245 = F_100 ( log -> V_185 - F_157 ( V_150 ) ) ;
V_59 -> V_254 = 2 ;
V_253 = ( char * ) & V_59 -> V_203 + V_245 ;
for ( V_181 = 0 ; V_181 < V_247 ; V_181 += V_171 ) {
T_13 V_7 = F_158 ( * ( T_16 * ) V_253 ) ;
if ( ++ V_7 == V_205 )
V_7 ++ ;
* ( T_16 * ) V_253 = F_126 ( V_7 ) ;
V_253 += V_171 ;
}
} else {
V_59 -> V_254 = 1 ;
}
V_59 -> V_203 . V_241 = F_140 ( log , & V_59 -> V_203 ,
V_59 -> V_216 , V_158 ) ;
V_150 -> V_255 = F_122 ( V_245 ) ;
V_150 -> V_151 = V_59 ;
F_159 ( V_150 ) ;
F_160 ( V_150 ) ;
V_150 -> V_256 |= V_257 ;
if ( log -> V_149 -> V_78 & V_258 ) {
V_150 -> V_256 |= V_259 ;
if ( log -> V_149 -> V_192 != log -> V_149 -> V_119 )
F_161 ( log -> V_149 -> V_119 ) ;
else
V_150 -> V_256 |= V_260 ;
}
ASSERT ( F_157 ( V_150 ) <= log -> V_185 - 1 ) ;
ASSERT ( F_157 ( V_150 ) + F_122 ( V_245 ) <= log -> V_185 ) ;
F_162 ( log , V_59 , V_245 , true ) ;
F_153 ( V_150 , F_157 ( V_150 ) + log -> V_184 ) ;
F_163 ( V_150 ) ;
error = F_145 ( V_150 ) ;
if ( error ) {
F_104 ( V_150 , L_19 ) ;
return error ;
}
if ( V_247 ) {
V_150 = V_59 -> V_153 -> V_194 ;
F_153 ( V_150 , 0 ) ;
F_164 ( V_150 ,
( char * ) & V_59 -> V_203 + V_245 , V_247 ) ;
V_150 -> V_151 = V_59 ;
F_159 ( V_150 ) ;
F_160 ( V_150 ) ;
V_150 -> V_256 |= V_257 ;
if ( log -> V_149 -> V_78 & V_258 )
V_150 -> V_256 |= V_259 ;
ASSERT ( F_157 ( V_150 ) <= log -> V_185 - 1 ) ;
ASSERT ( F_157 ( V_150 ) + F_122 ( V_245 ) <= log -> V_185 ) ;
F_153 ( V_150 , F_157 ( V_150 ) + log -> V_184 ) ;
F_163 ( V_150 ) ;
error = F_145 ( V_150 ) ;
if ( error ) {
F_104 ( V_150 , L_20 ) ;
return error ;
}
}
return 0 ;
}
STATIC void
F_64 (
struct V_1 * log )
{
T_11 * V_59 , * V_261 ;
int V_181 ;
F_165 ( log ) ;
V_59 = log -> V_94 ;
for ( V_181 = 0 ; V_181 < log -> V_161 ; V_181 ++ ) {
F_82 ( V_59 -> V_198 ) ;
F_83 ( V_59 -> V_198 ) ;
V_59 = V_59 -> V_96 ;
}
F_82 ( log -> V_194 ) ;
F_83 ( log -> V_194 ) ;
F_166 ( log -> V_194 , F_122 ( log -> V_164 ) ) ;
F_129 ( log -> V_194 ) ;
V_59 = log -> V_94 ;
for ( V_181 = 0 ; V_181 < log -> V_161 ; V_181 ++ ) {
F_129 ( V_59 -> V_198 ) ;
V_261 = V_59 -> V_96 ;
F_130 ( V_59 ) ;
V_59 = V_261 ;
}
F_131 ( & log -> V_114 ) ;
log -> V_149 -> V_38 = NULL ;
F_130 ( log ) ;
}
static inline void
F_167 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_262 ,
int V_263 )
{
F_12 ( & log -> V_114 ) ;
F_168 ( & V_59 -> V_203 . V_264 , V_262 ) ;
V_59 -> V_95 += V_263 ;
F_15 ( & log -> V_114 ) ;
}
void
F_169 (
struct V_36 * V_37 ,
struct V_15 * V_57 )
{
T_4 V_181 ;
T_4 V_265 = V_57 -> V_29 * ( T_4 ) sizeof( V_266 ) ;
static char * V_267 [ V_268 ] = {
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
static char * V_269 [ V_270 ] = {
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
V_57 -> V_55 > V_270 ) ?
L_88 : V_269 [ V_57 -> V_55 - 1 ] ) ,
V_57 -> V_55 ,
V_57 -> V_21 ,
V_57 -> V_42 ,
V_57 -> V_28 , V_57 -> V_32 ,
V_57 -> V_29 , V_265 ,
V_57 -> V_28 +
V_57 -> V_32 + V_265 ,
V_57 -> V_27 ) ;
for ( V_181 = 0 ; V_181 < V_57 -> V_27 ; V_181 ++ ) {
T_4 V_35 = V_57 -> V_33 [ V_181 ] . V_35 ;
F_56 ( V_37 , L_89 , V_181 ,
( ( V_35 <= 0 || V_35 > V_268 ) ?
L_90 : V_267 [ V_35 - 1 ] ) ,
V_57 -> V_33 [ V_181 ] . V_34 ) ;
}
F_170 ( V_37 , V_271 ,
L_91 ) ;
F_48 ( V_37 , V_73 ) ;
}
static int
F_171 (
struct V_15 * V_57 ,
struct V_108 * V_272 )
{
struct V_108 * V_273 ;
int V_274 = 0 ;
int V_30 = 0 ;
int V_181 ;
if ( V_57 -> V_19 & V_62 )
V_274 ++ ;
for ( V_273 = V_272 ; V_273 ; V_273 = V_273 -> V_275 ) {
if ( V_273 -> V_276 == V_277 )
continue;
V_274 += V_273 -> V_110 ;
for ( V_181 = 0 ; V_181 < V_273 -> V_110 ; V_181 ++ ) {
struct V_102 * V_278 = & V_273 -> V_111 [ V_181 ] ;
V_30 += V_278 -> V_105 ;
F_24 ( V_57 , V_278 -> V_105 , V_278 -> V_106 ) ;
}
}
V_57 -> V_29 += V_274 ;
V_30 += V_274 * sizeof( struct V_279 ) ;
return V_30 ;
}
static int
F_172 (
struct V_279 * V_280 ,
struct V_15 * V_57 )
{
if ( ! ( V_57 -> V_19 & V_62 ) )
return 0 ;
V_280 -> V_281 = F_126 ( V_57 -> V_41 ) ;
V_280 -> V_282 = V_57 -> V_283 ;
V_280 -> V_284 = 0 ;
V_280 -> V_285 = V_286 ;
V_280 -> V_287 = 0 ;
V_57 -> V_19 &= ~ V_62 ;
return sizeof( struct V_279 ) ;
}
static V_266 *
F_173 (
struct V_1 * log ,
struct V_279 * V_280 ,
struct V_15 * V_57 ,
T_4 V_60 )
{
V_280 -> V_281 = F_126 ( V_57 -> V_41 ) ;
V_280 -> V_282 = V_57 -> V_283 ;
V_280 -> V_287 = 0 ;
V_280 -> V_285 = V_60 ;
switch ( V_280 -> V_282 ) {
case V_50 :
case V_288 :
case V_51 :
break;
default:
F_56 ( log -> V_149 ,
L_92 ,
V_280 -> V_282 , V_57 ) ;
return NULL ;
}
return V_280 ;
}
static int
F_174 (
struct V_15 * V_57 ,
struct V_279 * V_280 ,
int V_289 ,
int V_290 ,
int * V_291 ,
int * V_292 ,
int * V_293 ,
int * V_294 )
{
int V_295 ;
V_295 = V_290 - * V_294 ;
* V_291 = * V_294 ;
if ( V_295 <= V_289 ) {
* V_292 = V_295 ;
V_280 -> V_284 = F_126 ( * V_292 ) ;
if ( * V_293 )
V_280 -> V_285 |= ( V_296 | V_297 ) ;
* V_293 = 0 ;
* V_294 = 0 ;
return 0 ;
}
* V_292 = V_289 ;
V_280 -> V_284 = F_126 ( * V_292 ) ;
V_280 -> V_285 |= V_298 ;
if ( * V_293 )
V_280 -> V_285 |= V_297 ;
* V_294 += * V_292 ;
( * V_293 ) ++ ;
V_57 -> V_42 -= sizeof( struct V_279 ) ;
V_57 -> V_29 ++ ;
return sizeof( struct V_279 ) ;
}
static int
F_175 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_4 V_60 ,
int * V_262 ,
int * V_299 ,
int * V_300 ,
int * V_301 ,
int V_302 ,
struct V_58 * * V_303 )
{
if ( * V_300 ) {
F_167 ( log , V_59 , * V_262 , * V_299 ) ;
* V_262 = 0 ;
* V_299 = 0 ;
return F_47 ( log , V_59 ) ;
}
* V_300 = 0 ;
* V_301 = 0 ;
if ( V_59 -> V_213 - V_302 <= sizeof( V_266 ) ) {
F_167 ( log , V_59 , * V_262 , * V_299 ) ;
* V_262 = 0 ;
* V_299 = 0 ;
F_12 ( & log -> V_114 ) ;
F_74 ( log , V_59 ) ;
F_15 ( & log -> V_114 ) ;
if ( ! V_303 )
return F_47 ( log , V_59 ) ;
ASSERT ( V_60 & V_220 ) ;
* V_303 = V_59 ;
}
return 0 ;
}
int
F_71 (
struct V_1 * log ,
struct V_108 * V_272 ,
struct V_15 * V_57 ,
T_6 * V_304 ,
struct V_58 * * V_303 ,
T_4 V_60 )
{
struct V_58 * V_59 = NULL ;
struct V_102 * V_278 ;
struct V_108 * V_273 ;
int V_30 ;
int V_305 ;
int V_300 = 0 ;
int V_301 = 0 ;
int V_306 = 0 ;
int V_262 = 0 ;
int V_299 = 0 ;
int error ;
* V_304 = 0 ;
V_30 = F_171 ( V_57 , V_272 ) ;
if ( V_57 -> V_19 & V_62 )
V_57 -> V_42 -= sizeof( V_266 ) ;
if ( V_60 & ( V_220 | V_112 ) )
V_57 -> V_42 -= sizeof( V_266 ) ;
if ( V_57 -> V_42 < 0 )
F_169 ( log -> V_149 , V_57 ) ;
V_305 = 0 ;
V_273 = V_272 ;
V_278 = V_273 -> V_111 ;
while ( V_273 && ( ! V_273 -> V_110 || V_305 < V_273 -> V_110 ) ) {
void * V_307 ;
int V_302 ;
error = F_176 ( log , V_30 , & V_59 , V_57 ,
& V_306 , & V_302 ) ;
if ( error )
return error ;
ASSERT ( V_302 <= V_59 -> V_213 - 1 ) ;
V_307 = V_59 -> V_216 + V_302 ;
if ( ! * V_304 )
* V_304 = F_155 ( V_59 -> V_203 . V_232 ) ;
while ( V_273 && ( ! V_273 -> V_110 || V_305 < V_273 -> V_110 ) ) {
struct V_102 * V_103 ;
struct V_279 * V_280 ;
int V_308 ;
int V_292 ;
int V_291 ;
bool V_309 = false ;
if ( V_273 -> V_276 == V_277 ) {
ASSERT ( V_273 -> V_110 == 0 ) ;
V_309 = true ;
goto V_310;
}
V_103 = & V_278 [ V_305 ] ;
ASSERT ( V_103 -> V_105 % sizeof( V_311 ) == 0 ) ;
ASSERT ( ( unsigned long ) V_307 % sizeof( V_311 ) == 0 ) ;
V_308 = F_172 ( V_307 , V_57 ) ;
if ( V_308 ) {
V_262 ++ ;
F_177 ( & V_307 , & V_30 , & V_302 ,
V_308 ) ;
}
V_280 = F_173 ( log , V_307 , V_57 , V_60 ) ;
if ( ! V_280 )
return F_27 ( V_39 ) ;
F_177 ( & V_307 , & V_30 , & V_302 ,
sizeof( struct V_279 ) ) ;
V_30 += F_174 ( V_57 , V_280 ,
V_59 -> V_213 - V_302 ,
V_103 -> V_105 ,
& V_291 , & V_292 ,
& V_300 ,
& V_301 ) ;
F_178 ( log , V_307 ) ;
ASSERT ( V_292 >= 0 ) ;
memcpy ( V_307 , V_103 -> V_104 + V_291 , V_292 ) ;
F_177 ( & V_307 , & V_30 , & V_302 , V_292 ) ;
V_292 += V_308 + sizeof( V_266 ) ;
V_262 ++ ;
V_299 += V_306 ? V_292 : 0 ;
error = F_175 ( log , V_59 , V_60 ,
& V_262 , & V_299 ,
& V_300 ,
& V_301 ,
V_302 ,
V_303 ) ;
if ( error )
return error ;
if ( V_300 )
break;
if ( ++ V_305 == V_273 -> V_110 ) {
V_310:
V_273 = V_273 -> V_275 ;
V_305 = 0 ;
if ( V_273 )
V_278 = V_273 -> V_111 ;
}
if ( V_262 == 0 && V_309 == false ) {
if ( ! V_273 )
return 0 ;
break;
}
}
}
ASSERT ( V_30 == 0 ) ;
F_167 ( log , V_59 , V_262 , V_299 ) ;
if ( ! V_303 )
return F_47 ( log , V_59 ) ;
ASSERT ( V_60 & V_220 ) ;
* V_303 = V_59 ;
return 0 ;
}
STATIC void
F_179 (
struct V_1 * log )
{
T_11 * V_59 ;
int V_312 = 0 ;
V_59 = log -> V_94 ;
do {
if ( V_59 -> V_67 == V_116 ) {
V_59 -> V_67 = V_69 ;
V_59 -> V_95 = 0 ;
ASSERT ( V_59 -> V_215 == NULL ) ;
if ( ! V_312 &&
( F_158 ( V_59 -> V_203 . V_264 ) ==
V_313 ) ) {
V_312 = 1 ;
} else {
V_312 = 2 ;
}
V_59 -> V_203 . V_264 = 0 ;
memset ( V_59 -> V_203 . V_233 , 0 ,
sizeof( V_59 -> V_203 . V_233 ) ) ;
V_59 -> V_203 . V_232 = 0 ;
} else if ( V_59 -> V_67 == V_69 )
;
else
break;
V_59 = V_59 -> V_96 ;
} while ( V_59 != log -> V_94 );
if ( V_312 ) {
switch ( log -> V_133 ) {
case V_136 :
case V_137 :
case V_138 :
log -> V_133 = V_137 ;
break;
case V_134 :
if ( V_312 == 1 )
log -> V_133 = V_138 ;
else
log -> V_133 = V_137 ;
break;
case V_135 :
if ( V_312 == 1 )
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
T_11 * V_314 ;
T_6 V_315 , V_61 ;
V_314 = log -> V_94 ;
V_315 = 0 ;
do {
if ( ! ( V_314 -> V_67 & ( V_69 | V_116 ) ) ) {
V_61 = F_155 ( V_314 -> V_203 . V_232 ) ;
if ( ( V_61 && ! V_315 ) ||
( F_136 ( V_61 , V_315 ) < 0 ) ) {
V_315 = V_61 ;
}
}
V_314 = V_314 -> V_96 ;
} while ( V_314 != log -> V_94 );
return V_315 ;
}
STATIC void
F_181 (
struct V_1 * log ,
int V_154 ,
struct V_58 * V_316 )
{
T_11 * V_59 ;
T_11 * V_92 ;
T_7 * V_64 , * V_71 ;
int V_317 = 0 ;
T_6 V_315 ;
int V_318 ;
int V_319 ;
int V_320 ;
int V_321 ;
int V_322 = 0 ;
F_12 ( & log -> V_114 ) ;
V_92 = V_59 = log -> V_94 ;
V_318 = 0 ;
V_320 = 0 ;
V_321 = 0 ;
do {
V_92 = log -> V_94 ;
V_59 = log -> V_94 ;
V_319 = 0 ;
V_321 ++ ;
do {
if ( V_59 -> V_67 &
( V_69 | V_116 ) ) {
V_59 = V_59 -> V_96 ;
continue;
}
if ( ! ( V_59 -> V_67 & V_68 ) ) {
if ( ! ( V_59 -> V_67 &
( V_323 |
V_324 ) ) ) {
if ( V_316 && ( V_316 -> V_67 ==
V_323 ) ) {
V_316 -> V_67 = V_324 ;
}
break;
}
V_315 = F_180 ( log ) ;
if ( V_315 &&
F_136 ( V_315 ,
F_155 ( V_59 -> V_203 . V_232 ) ) < 0 ) {
V_59 = V_59 -> V_96 ;
continue;
}
V_59 -> V_67 = V_325 ;
ASSERT ( F_136 ( F_2 ( & log -> V_143 ) ,
F_155 ( V_59 -> V_203 . V_232 ) ) <= 0 ) ;
if ( V_59 -> V_215 )
F_96 ( & log -> V_143 ,
F_155 ( V_59 -> V_203 . V_232 ) ) ;
} else
V_318 ++ ;
F_15 ( & log -> V_114 ) ;
F_12 ( & V_59 -> V_66 ) ;
V_64 = V_59 -> V_215 ;
while ( V_64 ) {
V_59 -> V_72 = & ( V_59 -> V_215 ) ;
V_59 -> V_215 = NULL ;
F_15 ( & V_59 -> V_66 ) ;
for (; V_64 ; V_64 = V_71 ) {
V_71 = V_64 -> V_71 ;
V_64 -> V_326 ( V_64 -> V_327 , V_154 ) ;
}
F_12 ( & V_59 -> V_66 ) ;
V_64 = V_59 -> V_215 ;
}
V_319 ++ ;
V_320 ++ ;
F_12 ( & log -> V_114 ) ;
ASSERT ( V_59 -> V_215 == NULL ) ;
F_15 ( & V_59 -> V_66 ) ;
if ( ! ( V_59 -> V_67 & V_68 ) )
V_59 -> V_67 = V_116 ;
F_179 ( log ) ;
F_182 ( & V_59 -> V_117 ) ;
V_59 = V_59 -> V_96 ;
} while ( V_92 != V_59 );
if ( V_321 > 5000 ) {
V_317 += V_321 ;
V_321 = 0 ;
F_56 ( log -> V_149 ,
L_93 ,
V_113 , V_317 ) ;
}
} while ( ! V_318 && V_319 );
#ifdef F_69
if ( V_320 ) {
V_92 = V_59 = log -> V_94 ;
do {
ASSERT ( V_59 -> V_67 != V_324 ) ;
if ( V_59 -> V_67 == V_70 ||
V_59 -> V_67 == V_328 ||
V_59 -> V_67 == V_323 ||
V_59 -> V_67 == V_68 )
break;
V_59 = V_59 -> V_96 ;
} while ( V_92 != V_59 );
}
#endif
if ( log -> V_94 -> V_67 & ( V_69 | V_68 ) )
V_322 = 1 ;
F_15 ( & log -> V_114 ) ;
if ( V_322 )
F_182 ( & log -> V_195 ) ;
}
STATIC void
F_107 (
T_11 * V_59 ,
int V_154 )
{
struct V_1 * log = V_59 -> V_153 ;
F_12 ( & log -> V_114 ) ;
ASSERT ( V_59 -> V_67 == V_328 ||
V_59 -> V_67 == V_68 ) ;
ASSERT ( F_150 ( & V_59 -> V_115 ) == 0 ) ;
ASSERT ( V_59 -> V_254 == 1 || V_59 -> V_254 == 2 ) ;
if ( V_59 -> V_67 != V_68 ) {
if ( -- V_59 -> V_254 == 1 ) {
F_15 ( & log -> V_114 ) ;
return;
}
V_59 -> V_67 = V_323 ;
}
F_182 ( & V_59 -> V_217 ) ;
F_15 ( & log -> V_114 ) ;
F_181 ( log , V_154 , V_59 ) ;
}
STATIC int
F_176 (
struct V_1 * log ,
int V_30 ,
struct V_58 * * V_179 ,
struct V_15 * V_57 ,
int * V_329 ,
int * V_330 )
{
int V_302 ;
T_15 * V_2 ;
T_11 * V_59 ;
int error ;
V_331:
F_12 ( & log -> V_114 ) ;
if ( F_26 ( log ) ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
V_59 = log -> V_94 ;
if ( V_59 -> V_67 != V_69 ) {
F_28 ( V_332 ) ;
F_75 ( & log -> V_195 , & log -> V_114 ) ;
goto V_331;
}
V_2 = & V_59 -> V_203 ;
F_73 ( & V_59 -> V_115 ) ;
V_302 = V_59 -> V_95 ;
if ( V_302 == 0 ) {
V_57 -> V_42 -= log -> V_167 ;
F_24 ( V_57 ,
log -> V_167 ,
V_333 ) ;
V_2 -> V_334 = F_126 ( log -> V_187 ) ;
V_2 -> V_232 = F_183 (
F_135 ( log -> V_187 , log -> V_335 ) ) ;
ASSERT ( log -> V_335 >= 0 ) ;
}
if ( V_59 -> V_213 - V_59 -> V_95 < 2 * sizeof( V_266 ) ) {
F_184 ( log , V_59 , V_59 -> V_213 ) ;
if ( ! F_185 ( & V_59 -> V_115 , - 1 , 1 ) ) {
F_15 ( & log -> V_114 ) ;
error = F_47 ( log , V_59 ) ;
if ( error )
return error ;
} else {
F_15 ( & log -> V_114 ) ;
}
goto V_331;
}
if ( V_30 <= V_59 -> V_213 - V_59 -> V_95 ) {
* V_329 = 0 ;
V_59 -> V_95 += V_30 ;
} else {
* V_329 = 1 ;
F_184 ( log , V_59 , V_59 -> V_213 ) ;
}
* V_179 = V_59 ;
ASSERT ( V_59 -> V_95 <= V_59 -> V_213 ) ;
F_15 ( & log -> V_114 ) ;
* V_330 = V_302 ;
return 0 ;
}
STATIC void
F_43 (
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
F_40 (
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
F_86 ( log -> V_149 ) ;
}
STATIC int
F_47 (
struct V_1 * log ,
struct V_58 * V_59 )
{
int V_336 = 0 ;
if ( V_59 -> V_67 & V_68 )
return F_27 ( V_39 ) ;
ASSERT ( F_150 ( & V_59 -> V_115 ) > 0 ) ;
if ( ! F_192 ( & V_59 -> V_115 , & log -> V_114 ) )
return 0 ;
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
ASSERT ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_70 ) ;
if ( V_59 -> V_67 == V_70 ) {
T_6 V_140 = F_97 ( log -> V_149 ) ;
V_336 ++ ;
V_59 -> V_67 = V_328 ;
V_59 -> V_203 . V_337 = F_183 ( V_140 ) ;
F_193 ( log , V_59 , V_140 ) ;
}
F_15 ( & log -> V_114 ) ;
if ( V_336 )
return F_149 ( log , V_59 ) ;
return 0 ;
}
STATIC void
F_184 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_338 )
{
ASSERT ( V_59 -> V_67 == V_69 ) ;
if ( ! V_338 )
V_338 = V_59 -> V_95 ;
V_59 -> V_67 = V_70 ;
V_59 -> V_203 . V_339 = F_126 ( log -> V_186 ) ;
log -> V_186 = log -> V_335 ;
log -> V_340 = log -> V_187 ;
log -> V_335 += F_122 ( V_338 ) + F_122 ( log -> V_167 ) ;
if ( F_109 ( & log -> V_149 -> V_80 ) &&
log -> V_149 -> V_80 . V_250 > 1 ) {
T_13 V_341 = F_122 ( log -> V_149 -> V_80 . V_250 ) ;
log -> V_335 = F_194 ( log -> V_335 , V_341 ) ;
}
if ( log -> V_335 >= log -> V_185 ) {
log -> V_187 ++ ;
if ( log -> V_187 == V_205 )
log -> V_187 ++ ;
log -> V_335 -= log -> V_185 ;
ASSERT ( log -> V_335 >= 0 ) ;
}
ASSERT ( V_59 == log -> V_94 ) ;
log -> V_94 = V_59 -> V_96 ;
}
int
F_70 (
struct V_36 * V_37 ,
T_4 V_60 ,
int * V_342 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
T_6 V_61 ;
F_28 ( V_343 ) ;
F_195 ( log ) ;
F_12 ( & log -> V_114 ) ;
V_59 = log -> V_94 ;
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
if ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_116 ) {
if ( V_59 -> V_67 == V_116 ||
( F_150 ( & V_59 -> V_115 ) == 0
&& V_59 -> V_95 == 0 ) ) {
V_59 = V_59 -> V_197 ;
if ( V_59 -> V_67 == V_69 ||
V_59 -> V_67 == V_116 )
goto V_344;
else
goto V_345;
} else {
if ( F_150 ( & V_59 -> V_115 ) == 0 ) {
F_73 ( & V_59 -> V_115 ) ;
V_61 = F_155 ( V_59 -> V_203 . V_232 ) ;
F_184 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_114 ) ;
if ( F_47 ( log , V_59 ) )
return F_27 ( V_39 ) ;
if ( V_342 )
* V_342 = 1 ;
F_12 ( & log -> V_114 ) ;
if ( F_155 ( V_59 -> V_203 . V_232 ) == V_61 &&
V_59 -> V_67 != V_116 )
goto V_345;
else
goto V_344;
} else {
F_184 ( log , V_59 , 0 ) ;
goto V_345;
}
}
}
V_345:
if ( V_60 & V_93 ) {
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
F_28 ( V_346 ) ;
F_75 ( & V_59 -> V_117 , & log -> V_114 ) ;
if ( V_59 -> V_67 & V_68 )
return F_27 ( V_39 ) ;
if ( V_342 )
* V_342 = 1 ;
} else {
V_344:
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
F_196 ( V_37 , 0 ) ;
error = F_70 ( V_37 , V_60 , NULL ) ;
if ( error )
F_56 ( V_37 , L_94 , V_113 , error ) ;
}
int
F_197 (
struct V_36 * V_37 ,
T_6 V_61 ,
T_4 V_60 ,
int * V_342 )
{
struct V_1 * log = V_37 -> V_38 ;
struct V_58 * V_59 ;
int V_347 = 0 ;
ASSERT ( V_61 != 0 ) ;
F_28 ( V_343 ) ;
V_61 = F_198 ( log , V_61 ) ;
if ( V_61 == V_348 )
return 0 ;
V_349:
F_12 ( & log -> V_114 ) ;
V_59 = log -> V_94 ;
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
do {
if ( F_155 ( V_59 -> V_203 . V_232 ) != V_61 ) {
V_59 = V_59 -> V_96 ;
continue;
}
if ( V_59 -> V_67 == V_116 ) {
F_15 ( & log -> V_114 ) ;
return 0 ;
}
if ( V_59 -> V_67 == V_69 ) {
if ( ! V_347 &&
( V_59 -> V_197 -> V_67 &
( V_70 | V_328 ) ) ) {
ASSERT ( ! ( V_59 -> V_67 & V_68 ) ) ;
F_28 ( V_346 ) ;
F_75 ( & V_59 -> V_197 -> V_217 ,
& log -> V_114 ) ;
if ( V_342 )
* V_342 = 1 ;
V_347 = 1 ;
goto V_349;
}
F_73 ( & V_59 -> V_115 ) ;
F_184 ( log , V_59 , 0 ) ;
F_15 ( & log -> V_114 ) ;
if ( F_47 ( log , V_59 ) )
return F_27 ( V_39 ) ;
if ( V_342 )
* V_342 = 1 ;
F_12 ( & log -> V_114 ) ;
}
if ( ( V_60 & V_93 ) &&
! ( V_59 -> V_67 &
( V_69 | V_116 ) ) ) {
if ( V_59 -> V_67 & V_68 ) {
F_15 ( & log -> V_114 ) ;
return F_27 ( V_39 ) ;
}
F_28 ( V_346 ) ;
F_75 ( & V_59 -> V_117 , & log -> V_114 ) ;
if ( V_59 -> V_67 & V_68 )
return F_27 ( V_39 ) ;
if ( V_342 )
* V_342 = 1 ;
} else {
F_15 ( & log -> V_114 ) ;
}
return 0 ;
} while ( V_59 != log -> V_94 );
F_15 ( & log -> V_114 ) ;
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
F_56 ( V_37 , L_94 , V_113 , error ) ;
}
STATIC void
F_74 (
struct V_1 * log ,
struct V_58 * V_59 )
{
F_93 ( & log -> V_114 ) ;
if ( V_59 -> V_67 == V_69 ) {
F_184 ( log , V_59 , 0 ) ;
} else {
ASSERT ( V_59 -> V_67 &
( V_70 | V_68 ) ) ;
}
}
void
F_41 (
T_3 * V_57 )
{
ASSERT ( F_150 ( & V_57 -> V_350 ) > 0 ) ;
if ( F_200 ( & V_57 -> V_350 ) )
F_201 ( V_351 , V_57 ) ;
}
T_3 *
F_202 (
T_3 * V_57 )
{
ASSERT ( F_150 ( & V_57 -> V_350 ) > 0 ) ;
F_73 ( & V_57 -> V_350 ) ;
return V_57 ;
}
int
F_203 (
struct V_36 * V_37 ,
int V_44 )
{
struct V_1 * log = V_37 -> V_38 ;
int V_352 ;
T_4 V_353 ;
V_44 += sizeof( V_266 ) ;
V_44 += sizeof( V_354 ) ;
V_44 += sizeof( V_266 ) ;
V_352 = log -> V_164 - log -> V_167 ;
V_353 = F_204 ( V_44 , V_352 ) ;
V_44 += sizeof( V_266 ) * V_353 ;
while ( ! V_353 ||
F_204 ( V_44 , V_352 ) > V_353 ) {
V_44 += sizeof( V_266 ) ;
V_353 ++ ;
}
V_44 += log -> V_167 * V_353 ;
V_44 += log -> V_167 ;
if ( F_109 ( & V_37 -> V_80 ) && V_37 -> V_80 . V_250 > 1 ) {
V_44 += 2 * V_37 -> V_80 . V_250 ;
} else {
V_44 += 2 * V_171 ;
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
T_19 V_355 )
{
struct V_15 * V_16 ;
int V_356 ;
V_16 = F_205 ( V_351 , V_355 ) ;
if ( ! V_16 )
return NULL ;
V_356 = F_203 ( log -> V_149 , V_44 ) ;
F_127 ( & V_16 -> V_350 , 1 ) ;
V_16 -> V_17 = V_357 ;
F_9 ( & V_16 -> V_358 ) ;
V_16 -> V_21 = V_356 ;
V_16 -> V_42 = V_356 ;
V_16 -> V_22 = V_45 ;
V_16 -> V_359 = V_45 ;
V_16 -> V_41 = F_206 () ;
V_16 -> V_283 = V_47 ;
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
char * V_307 )
{
int V_181 ;
int V_360 = 0 ;
for ( V_181 = 0 ; V_181 < log -> V_161 ; V_181 ++ ) {
if ( V_307 >= log -> V_201 [ V_181 ] &&
V_307 <= log -> V_201 [ V_181 ] + log -> V_164 )
V_360 ++ ;
}
if ( ! V_360 )
F_207 ( log -> V_149 , L_95 , V_113 ) ;
}
STATIC void
F_32 (
struct V_1 * log )
{
int V_146 , V_361 ;
int V_7 , V_8 ;
F_98 ( & log -> V_18 . V_12 , & V_7 , & V_8 ) ;
F_99 ( & log -> V_144 , & V_146 , & V_361 ) ;
if ( V_146 != V_7 ) {
if ( V_7 - 1 != V_146 &&
! ( log -> V_25 & V_362 ) ) {
F_170 ( log -> V_149 , V_271 ,
L_96 , V_113 ) ;
log -> V_25 |= V_362 ;
}
if ( V_8 > F_100 ( V_361 ) &&
! ( log -> V_25 & V_362 ) ) {
F_170 ( log -> V_149 , V_271 ,
L_97 , V_113 ) ;
log -> V_25 |= V_362 ;
}
}
}
STATIC void
F_193 (
struct V_1 * log ,
struct V_58 * V_59 ,
T_6 V_140 )
{
int V_363 ;
if ( F_208 ( V_140 ) == log -> V_340 ) {
V_363 =
log -> V_185 - ( log -> V_186 - F_154 ( V_140 ) ) ;
if ( V_363 < F_122 ( V_59 -> V_95 ) + F_122 ( log -> V_167 ) )
F_207 ( log -> V_149 , L_98 , V_113 ) ;
} else {
ASSERT ( F_208 ( V_140 ) + 1 == log -> V_340 ) ;
if ( F_154 ( V_140 ) == log -> V_186 )
F_207 ( log -> V_149 , L_99 , V_113 ) ;
V_363 = F_154 ( V_140 ) - log -> V_186 ;
if ( V_363 < F_122 ( V_59 -> V_95 ) + 1 )
F_207 ( log -> V_149 , L_98 , V_113 ) ;
}
}
STATIC void
F_162 (
struct V_1 * log ,
struct V_58 * V_59 ,
int V_245 ,
bool V_364 )
{
V_266 * V_365 ;
T_11 * V_366 ;
T_17 * V_234 ;
V_202 V_307 ;
V_202 V_367 ;
T_20 V_368 ;
T_5 V_369 ;
int V_30 , V_181 , V_228 , V_229 , V_370 ;
int V_371 ;
F_12 ( & log -> V_114 ) ;
V_366 = log -> V_94 ;
for ( V_181 = 0 ; V_181 < log -> V_161 ; V_181 ++ , V_366 = V_366 -> V_96 )
ASSERT ( V_366 ) ;
if ( V_366 != log -> V_94 )
F_207 ( log -> V_149 , L_100 , V_113 ) ;
F_15 ( & log -> V_114 ) ;
if ( V_59 -> V_203 . V_204 != F_126 ( V_205 ) )
F_207 ( log -> V_149 , L_101 , V_113 ) ;
V_307 = ( V_202 ) & V_59 -> V_203 ;
for ( V_307 += V_171 ; V_307 < ( ( V_202 ) & V_59 -> V_203 ) + V_245 ;
V_307 += V_171 ) {
if ( * ( T_16 * ) V_307 == F_126 ( V_205 ) )
F_207 ( log -> V_149 , L_102 ,
V_113 ) ;
}
V_30 = F_158 ( V_59 -> V_203 . V_264 ) ;
V_307 = V_59 -> V_216 ;
V_367 = V_307 ;
V_365 = ( V_266 * ) V_307 ;
V_234 = V_59 -> V_199 ;
for ( V_181 = 0 ; V_181 < V_30 ; V_181 ++ ) {
V_365 = ( V_266 * ) V_307 ;
V_368 = ( T_20 )
( ( V_202 ) & ( V_365 -> V_282 ) - V_367 ) ;
if ( ! V_364 || ( V_368 & 0x1ff ) ) {
V_369 = V_365 -> V_282 ;
} else {
V_371 = F_133 ( ( V_202 ) & ( V_365 -> V_282 ) - V_59 -> V_216 ) ;
if ( V_371 >= ( V_166 / V_171 ) ) {
V_228 = V_371 / ( V_166 / V_171 ) ;
V_229 = V_371 % ( V_166 / V_171 ) ;
V_369 = F_209 (
V_234 [ V_228 ] . V_235 . V_236 [ V_229 ] ) ;
} else {
V_369 = F_209 (
V_59 -> V_203 . V_233 [ V_371 ] ) ;
}
}
if ( V_369 != V_50 && V_369 != V_51 )
F_56 ( log -> V_149 ,
L_103 ,
V_113 , V_369 , V_365 ,
( unsigned long ) V_368 ) ;
V_368 = ( T_20 )
( ( V_202 ) & ( V_365 -> V_284 ) - V_367 ) ;
if ( ! V_364 || ( V_368 & 0x1ff ) ) {
V_370 = F_158 ( V_365 -> V_284 ) ;
} else {
V_371 = F_133 ( ( T_20 ) & V_365 -> V_284 -
( T_20 ) V_59 -> V_216 ) ;
if ( V_371 >= ( V_166 / V_171 ) ) {
V_228 = V_371 / ( V_166 / V_171 ) ;
V_229 = V_371 % ( V_166 / V_171 ) ;
V_370 = F_158 ( V_234 [ V_228 ] . V_235 . V_236 [ V_229 ] ) ;
} else {
V_370 = F_158 ( V_59 -> V_203 . V_233 [ V_371 ] ) ;
}
}
V_307 += sizeof( V_266 ) + V_370 ;
}
}
STATIC int
F_210 (
struct V_1 * log )
{
T_11 * V_59 , * V_372 ;
V_59 = log -> V_94 ;
if ( ! ( V_59 -> V_67 & V_68 ) ) {
V_372 = V_59 ;
do {
V_372 -> V_67 = V_68 ;
V_372 = V_372 -> V_96 ;
} while ( V_372 != V_59 );
return 0 ;
}
return 1 ;
}
int
F_211 (
struct V_36 * V_37 ,
int V_373 )
{
struct V_1 * log ;
int V_374 ;
log = V_37 -> V_38 ;
if ( ! log ||
log -> V_25 & V_26 ) {
V_37 -> V_78 |= V_375 ;
if ( V_37 -> V_120 )
F_212 ( V_37 -> V_120 ) ;
return 0 ;
}
if ( V_373 && log -> V_94 -> V_67 & V_68 ) {
ASSERT ( F_26 ( log ) ) ;
return 1 ;
}
V_374 = 0 ;
if ( ! V_373 )
F_195 ( log ) ;
F_12 ( & log -> V_114 ) ;
V_37 -> V_78 |= V_375 ;
if ( V_37 -> V_120 )
F_212 ( V_37 -> V_120 ) ;
log -> V_25 |= V_376 ;
if ( V_373 )
V_374 = F_210 ( log ) ;
F_15 ( & log -> V_114 ) ;
F_11 ( & log -> V_56 ) ;
F_11 ( & log -> V_18 ) ;
if ( ! ( log -> V_94 -> V_67 & V_68 ) ) {
ASSERT ( ! V_373 ) ;
F_70 ( V_37 , V_93 , NULL ) ;
F_12 ( & log -> V_114 ) ;
V_374 = F_210 ( log ) ;
F_15 ( & log -> V_114 ) ;
}
F_181 ( log , V_157 , NULL ) ;
#ifdef F_213
{
T_11 * V_59 ;
F_12 ( & log -> V_114 ) ;
V_59 = log -> V_94 ;
do {
ASSERT ( V_59 -> V_215 == 0 ) ;
V_59 = V_59 -> V_96 ;
} while ( V_59 != log -> V_94 );
F_15 ( & log -> V_114 ) ;
}
#endif
return V_374 ;
}
STATIC int
F_91 (
struct V_1 * log )
{
T_11 * V_59 ;
V_59 = log -> V_94 ;
do {
if ( V_59 -> V_203 . V_264 )
return 0 ;
V_59 = V_59 -> V_96 ;
} while ( V_59 != log -> V_94 );
return 1 ;
}
