T_1
F_1 (
struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 . V_4 & V_5 ) && V_2 -> V_3 . V_6 )
return V_2 -> V_3 . V_6 ;
if ( F_2 ( V_2 ) )
return V_2 -> V_7 -> V_8 . V_9 ;
return 0 ;
}
T_2
F_3 (
struct V_1 * V_2 )
{
T_2 V_10 = V_11 ;
if ( V_2 -> V_3 . V_12 == V_13 &&
( V_2 -> V_14 . V_15 & V_16 ) == 0 )
V_10 = V_17 ;
F_4 ( V_2 , V_10 ) ;
return V_10 ;
}
T_2
F_5 (
struct V_1 * V_2 )
{
T_2 V_10 = V_11 ;
if ( V_2 -> V_3 . V_18 == V_13 &&
( V_2 -> V_19 -> V_15 & V_16 ) == 0 )
V_10 = V_17 ;
F_4 ( V_2 , V_10 ) ;
return V_10 ;
}
void
F_4 (
T_3 * V_2 ,
T_2 V_20 )
{
F_6 ( V_2 , V_20 , V_21 ) ;
ASSERT ( ( V_20 & ( V_22 | V_23 ) ) !=
( V_22 | V_23 ) ) ;
ASSERT ( ( V_20 & ( V_24 | V_25 ) ) !=
( V_24 | V_25 ) ) ;
ASSERT ( ( V_20 & ( V_11 | V_17 ) ) !=
( V_11 | V_17 ) ) ;
ASSERT ( ( V_20 & ~ ( V_26 | V_27 ) ) == 0 ) ;
if ( V_20 & V_23 )
F_7 ( & V_2 -> V_28 , F_8 ( V_20 ) ) ;
else if ( V_20 & V_22 )
F_9 ( & V_2 -> V_28 , F_8 ( V_20 ) ) ;
if ( V_20 & V_25 )
F_7 ( & V_2 -> V_29 , F_10 ( V_20 ) ) ;
else if ( V_20 & V_24 )
F_9 ( & V_2 -> V_29 , F_10 ( V_20 ) ) ;
if ( V_20 & V_17 )
F_7 ( & V_2 -> V_30 , F_11 ( V_20 ) ) ;
else if ( V_20 & V_11 )
F_9 ( & V_2 -> V_30 , F_11 ( V_20 ) ) ;
}
int
F_12 (
T_3 * V_2 ,
T_2 V_20 )
{
F_13 ( V_2 , V_20 , V_21 ) ;
ASSERT ( ( V_20 & ( V_22 | V_23 ) ) !=
( V_22 | V_23 ) ) ;
ASSERT ( ( V_20 & ( V_24 | V_25 ) ) !=
( V_24 | V_25 ) ) ;
ASSERT ( ( V_20 & ( V_11 | V_17 ) ) !=
( V_11 | V_17 ) ) ;
ASSERT ( ( V_20 & ~ ( V_26 | V_27 ) ) == 0 ) ;
if ( V_20 & V_23 ) {
if ( ! F_14 ( & V_2 -> V_28 ) )
goto V_31;
} else if ( V_20 & V_22 ) {
if ( ! F_15 ( & V_2 -> V_28 ) )
goto V_31;
}
if ( V_20 & V_25 ) {
if ( ! F_14 ( & V_2 -> V_29 ) )
goto V_32;
} else if ( V_20 & V_24 ) {
if ( ! F_15 ( & V_2 -> V_29 ) )
goto V_32;
}
if ( V_20 & V_17 ) {
if ( ! F_14 ( & V_2 -> V_30 ) )
goto V_33;
} else if ( V_20 & V_11 ) {
if ( ! F_15 ( & V_2 -> V_30 ) )
goto V_33;
}
return 1 ;
V_33:
if ( V_20 & V_25 )
F_16 ( & V_2 -> V_29 ) ;
else if ( V_20 & V_24 )
F_17 ( & V_2 -> V_29 ) ;
V_32:
if ( V_20 & V_23 )
F_16 ( & V_2 -> V_28 ) ;
else if ( V_20 & V_22 )
F_17 ( & V_2 -> V_28 ) ;
V_31:
return 0 ;
}
void
F_18 (
T_3 * V_2 ,
T_2 V_20 )
{
ASSERT ( ( V_20 & ( V_22 | V_23 ) ) !=
( V_22 | V_23 ) ) ;
ASSERT ( ( V_20 & ( V_24 | V_25 ) ) !=
( V_24 | V_25 ) ) ;
ASSERT ( ( V_20 & ( V_11 | V_17 ) ) !=
( V_11 | V_17 ) ) ;
ASSERT ( ( V_20 & ~ ( V_26 | V_27 ) ) == 0 ) ;
ASSERT ( V_20 != 0 ) ;
if ( V_20 & V_23 )
F_16 ( & V_2 -> V_28 ) ;
else if ( V_20 & V_22 )
F_17 ( & V_2 -> V_28 ) ;
if ( V_20 & V_25 )
F_16 ( & V_2 -> V_29 ) ;
else if ( V_20 & V_24 )
F_17 ( & V_2 -> V_29 ) ;
if ( V_20 & V_17 )
F_16 ( & V_2 -> V_30 ) ;
else if ( V_20 & V_11 )
F_17 ( & V_2 -> V_30 ) ;
F_19 ( V_2 , V_20 , V_21 ) ;
}
void
F_20 (
T_3 * V_2 ,
T_2 V_20 )
{
ASSERT ( V_20 & ( V_23 | V_25 | V_17 ) ) ;
ASSERT ( ( V_20 &
~ ( V_23 | V_25 | V_17 ) ) == 0 ) ;
if ( V_20 & V_17 )
F_21 ( & V_2 -> V_30 ) ;
if ( V_20 & V_25 )
F_21 ( & V_2 -> V_29 ) ;
if ( V_20 & V_23 )
F_21 ( & V_2 -> V_28 ) ;
F_22 ( V_2 , V_20 , V_21 ) ;
}
int
F_23 (
T_3 * V_2 ,
T_2 V_20 )
{
if ( V_20 & ( V_17 | V_11 ) ) {
if ( ! ( V_20 & V_11 ) )
return ! ! V_2 -> V_30 . V_34 ;
return F_24 ( & V_2 -> V_30 . V_35 ) ;
}
if ( V_20 & ( V_25 | V_24 ) ) {
if ( ! ( V_20 & V_24 ) )
return ! ! V_2 -> V_29 . V_34 ;
return F_24 ( & V_2 -> V_29 . V_35 ) ;
}
if ( V_20 & ( V_23 | V_22 ) ) {
if ( ! ( V_20 & V_22 ) )
return ! ! V_2 -> V_28 . V_34 ;
return F_24 ( & V_2 -> V_28 . V_35 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
static bool
F_25 (
int V_36 )
{
return V_36 < V_37 ;
}
static inline int
F_26 ( int V_10 , int V_36 )
{
int V_38 = 0 ;
ASSERT ( ! ( V_10 & ( V_39 | V_40 |
V_41 ) ) ) ;
ASSERT ( F_25 ( V_36 ) ) ;
if ( V_10 & ( V_22 | V_23 ) ) {
ASSERT ( V_36 <= V_42 ) ;
ASSERT ( F_25 ( V_36 +
V_43 ) ) ;
V_38 += V_36 << V_44 ;
if ( V_10 & V_45 )
V_38 += V_43 << V_44 ;
}
if ( V_10 & ( V_24 | V_25 ) ) {
ASSERT ( V_36 <= V_46 ) ;
V_38 += V_36 << V_47 ;
}
if ( V_10 & ( V_11 | V_17 ) ) {
ASSERT ( V_36 <= V_48 ) ;
V_38 += V_36 << V_49 ;
}
return ( V_10 & ~ V_27 ) | V_38 ;
}
void
F_27 (
T_3 * * V_50 ,
int V_51 ,
T_2 V_10 )
{
int V_52 = 0 , V_53 , V_54 , V_55 ;
T_4 * V_56 ;
ASSERT ( V_50 && V_51 >= 2 && V_51 <= 5 ) ;
ASSERT ( V_10 & ( V_23 | V_25 |
V_17 ) ) ;
ASSERT ( ! ( V_10 & ( V_22 | V_24 |
V_11 ) ) ) ;
ASSERT ( ! ( V_10 & V_23 ) ||
V_51 <= V_42 + 1 ) ;
ASSERT ( ! ( V_10 & V_25 ) ||
V_51 <= V_46 + 1 ) ;
ASSERT ( ! ( V_10 & V_17 ) ||
V_51 <= V_48 + 1 ) ;
if ( V_10 & V_23 ) {
ASSERT ( ! ( V_10 & ( V_25 | V_17 ) ) ) ;
} else if ( V_10 & V_25 )
ASSERT ( ! ( V_10 & V_17 ) ) ;
V_55 = 0 ;
V_53 = 0 ;
V_57:
for (; V_53 < V_51 ; V_53 ++ ) {
ASSERT ( V_50 [ V_53 ] ) ;
if ( V_53 && ( V_50 [ V_53 ] == V_50 [ V_53 - 1 ] ) )
continue;
if ( ! V_55 ) {
for ( V_54 = ( V_53 - 1 ) ; V_54 >= 0 && ! V_55 ; V_54 -- ) {
V_56 = ( T_4 * ) V_50 [ V_54 ] -> V_58 ;
if ( V_56 && ( V_56 -> V_59 & V_60 ) )
V_55 ++ ;
}
}
if ( ! V_55 ) {
F_4 ( V_50 [ V_53 ] , F_26 ( V_10 , V_53 ) ) ;
continue;
}
ASSERT ( V_53 != 0 ) ;
if ( F_12 ( V_50 [ V_53 ] , F_26 ( V_10 , V_53 ) ) )
continue;
V_52 ++ ;
for ( V_54 = V_53 - 1 ; V_54 >= 0 ; V_54 -- ) {
if ( V_54 != ( V_53 - 1 ) && V_50 [ V_54 ] == V_50 [ V_54 + 1 ] )
continue;
F_18 ( V_50 [ V_54 ] , V_10 ) ;
}
if ( ( V_52 % 5 ) == 0 ) {
F_28 ( 1 ) ;
#ifdef F_29
V_61 ++ ;
#endif
}
V_53 = 0 ;
V_55 = 0 ;
goto V_57;
}
#ifdef F_29
if ( V_52 ) {
if ( V_52 < 5 ) V_62 ++ ;
else if ( V_52 < 100 ) V_63 ++ ;
else V_64 ++ ;
} else {
V_65 ++ ;
}
#endif
}
void
F_30 (
T_3 * V_66 ,
T_3 * V_67 ,
T_2 V_10 )
{
T_3 * V_68 ;
int V_52 = 0 ;
T_4 * V_56 ;
if ( V_10 & ( V_22 | V_23 ) ) {
ASSERT ( ! ( V_10 & ( V_24 | V_25 ) ) ) ;
ASSERT ( ! ( V_10 & ( V_11 | V_17 ) ) ) ;
} else if ( V_10 & ( V_24 | V_25 ) )
ASSERT ( ! ( V_10 & ( V_11 | V_17 ) ) ) ;
ASSERT ( V_66 -> V_69 != V_67 -> V_69 ) ;
if ( V_66 -> V_69 > V_67 -> V_69 ) {
V_68 = V_66 ;
V_66 = V_67 ;
V_67 = V_68 ;
}
V_57:
F_4 ( V_66 , F_26 ( V_10 , 0 ) ) ;
V_56 = ( T_4 * ) V_66 -> V_58 ;
if ( V_56 && ( V_56 -> V_59 & V_60 ) ) {
if ( ! F_12 ( V_67 , F_26 ( V_10 , 1 ) ) ) {
F_18 ( V_66 , V_10 ) ;
if ( ( ++ V_52 % 5 ) == 0 )
F_28 ( 1 ) ;
goto V_57;
}
} else {
F_4 ( V_67 , F_26 ( V_10 , 1 ) ) ;
}
}
void
F_31 (
struct V_1 * V_2 )
{
T_5 * V_70 = F_32 ( & V_2 -> V_71 , V_72 ) ;
F_33 ( V_73 , & V_2 -> V_71 , V_72 ) ;
do {
F_34 ( V_70 , & V_73 . V_73 , V_74 ) ;
if ( F_35 ( V_2 ) )
F_36 () ;
} while ( ! F_37 ( V_2 ) );
F_38 ( V_70 , & V_73 . V_73 ) ;
}
STATIC T_2
F_39 (
T_6 V_4 ,
T_7 V_75 ,
bool V_76 )
{
T_2 V_77 = 0 ;
if ( V_4 & V_78 ) {
if ( V_4 & V_79 )
V_77 |= V_80 ;
if ( V_4 & V_81 )
V_77 |= V_82 ;
if ( V_4 & V_83 )
V_77 |= V_84 ;
if ( V_4 & V_85 )
V_77 |= V_86 ;
if ( V_4 & V_87 )
V_77 |= V_88 ;
if ( V_4 & V_89 )
V_77 |= V_90 ;
if ( V_4 & V_91 )
V_77 |= V_92 ;
if ( V_4 & V_93 )
V_77 |= V_94 ;
if ( V_4 & V_95 )
V_77 |= V_96 ;
if ( V_4 & V_97 )
V_77 |= V_98 ;
if ( V_4 & V_5 )
V_77 |= V_99 ;
if ( V_4 & V_100 )
V_77 |= V_101 ;
if ( V_4 & V_102 )
V_77 |= V_103 ;
if ( V_4 & V_104 )
V_77 |= V_105 ;
}
if ( V_75 & V_106 ) {
if ( V_75 & V_107 )
V_77 |= V_108 ;
}
if ( V_76 )
V_77 |= V_109 ;
return V_77 ;
}
T_2
F_40 (
struct V_1 * V_2 )
{
struct V_110 * V_111 = & V_2 -> V_3 ;
return F_39 ( V_111 -> V_4 , V_111 -> V_75 , F_41 ( V_2 ) ) ;
}
T_2
F_42 (
struct V_112 * V_113 )
{
return F_39 ( F_43 ( V_113 -> V_4 ) ,
F_44 ( V_113 -> V_75 ) , F_45 ( V_113 ) ) ;
}
int
F_46 (
T_3 * V_114 ,
struct V_115 * V_116 ,
T_3 * * V_117 ,
struct V_115 * V_118 )
{
T_8 V_119 ;
int error ;
F_47 ( V_114 , V_116 ) ;
if ( F_48 ( V_114 -> V_7 ) )
return - V_120 ;
F_4 ( V_114 , V_22 ) ;
error = F_49 ( NULL , V_114 , V_116 , & V_119 , V_118 ) ;
if ( error )
goto V_121;
error = F_50 ( V_114 -> V_7 , NULL , V_119 , 0 , 0 , V_117 ) ;
if ( error )
goto V_122;
F_18 ( V_114 , V_22 ) ;
return 0 ;
V_122:
if ( V_118 )
F_51 ( V_118 -> V_116 ) ;
V_121:
F_18 ( V_114 , V_22 ) ;
* V_117 = NULL ;
return error ;
}
int
F_52 (
T_9 * V_123 ,
T_3 * V_124 ,
T_10 V_125 ,
T_11 V_126 ,
T_12 V_127 ,
T_13 V_128 ,
int V_129 ,
T_14 * * V_130 ,
T_3 * * V_117 )
{
struct V_131 * V_132 = V_123 -> V_133 ;
T_8 V_134 ;
T_3 * V_2 ;
T_2 V_77 ;
int error ;
struct V_135 V_136 ;
error = F_53 ( V_123 , V_124 ? V_124 -> V_69 : 0 , V_125 , V_129 ,
V_130 , & V_134 ) ;
if ( error )
return error ;
if ( * V_130 || V_134 == V_137 ) {
* V_117 = NULL ;
return 0 ;
}
ASSERT ( * V_130 == NULL ) ;
error = F_50 ( V_132 , V_123 , V_134 , V_138 ,
V_17 , & V_2 ) ;
if ( error )
return error ;
ASSERT ( V_2 != NULL ) ;
if ( V_2 -> V_3 . V_139 == 1 )
V_2 -> V_3 . V_139 = 2 ;
V_2 -> V_3 . V_140 = V_125 ;
V_2 -> V_3 . V_141 = 0 ;
V_2 -> V_3 . V_142 = V_126 ;
ASSERT ( V_2 -> V_3 . V_142 == V_126 ) ;
V_2 -> V_3 . V_143 = F_54 ( F_55 () ) ;
V_2 -> V_3 . V_144 = F_56 ( F_57 () ) ;
F_58 ( V_2 , V_128 ) ;
memset ( & ( V_2 -> V_3 . V_145 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_145 ) ) ;
if ( V_124 && F_59 ( V_124 ) ) {
V_2 -> V_3 . V_144 = V_124 -> V_3 . V_144 ;
if ( ( V_124 -> V_3 . V_140 & V_146 ) && F_60 ( V_125 ) ) {
V_2 -> V_3 . V_140 |= V_146 ;
}
}
if ( ( V_147 ) &&
( V_2 -> V_3 . V_140 & V_146 ) &&
( ! F_61 ( F_62 ( V_2 -> V_3 . V_144 ) ) ) ) {
V_2 -> V_3 . V_140 &= ~ V_146 ;
}
V_2 -> V_3 . V_148 = 0 ;
V_2 -> V_3 . V_149 = 0 ;
ASSERT ( V_2 -> V_3 . V_150 == 0 ) ;
V_136 = F_63 ( V_132 -> V_151 ) ;
V_2 -> V_3 . V_152 . V_153 = ( V_154 ) V_136 . V_155 ;
V_2 -> V_3 . V_152 . V_156 = ( V_154 ) V_136 . V_157 ;
V_2 -> V_3 . V_158 = V_2 -> V_3 . V_152 ;
V_2 -> V_3 . V_159 = V_2 -> V_3 . V_152 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_160 = 0 ;
V_2 -> V_3 . V_161 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( V_2 -> V_3 . V_139 == 3 ) {
ASSERT ( V_2 -> V_3 . V_162 == V_134 ) ;
ASSERT ( F_64 ( & V_2 -> V_3 . V_163 , & V_132 -> V_8 . V_164 ) ) ;
V_2 -> V_3 . V_165 = 0 ;
V_2 -> V_3 . V_166 = 1 ;
V_2 -> V_3 . V_167 = 0 ;
V_2 -> V_3 . V_75 = 0 ;
memset ( & ( V_2 -> V_3 . V_168 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_168 ) ) ;
V_2 -> V_3 . V_169 = V_2 -> V_3 . V_152 ;
}
V_77 = V_170 ;
switch ( V_125 & V_171 ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_2 -> V_3 . V_12 = V_176 ;
V_2 -> V_14 . V_177 . V_178 = V_127 ;
V_2 -> V_14 . V_15 = 0 ;
V_77 |= V_179 ;
break;
case V_180 :
case V_181 :
if ( V_124 && ( V_124 -> V_3 . V_4 & V_78 ) ) {
T_7 V_75 = 0 ;
T_2 V_4 = 0 ;
if ( F_60 ( V_125 ) ) {
if ( V_124 -> V_3 . V_4 & V_93 )
V_4 |= V_93 ;
if ( V_124 -> V_3 . V_4 & V_100 ) {
V_4 |= V_100 ;
V_2 -> V_3 . V_6 = V_124 -> V_3 . V_6 ;
}
if ( V_124 -> V_3 . V_4 & V_95 )
V_4 |= V_95 ;
} else if ( F_65 ( V_125 ) ) {
if ( V_124 -> V_3 . V_4 & V_93 )
V_4 |= V_79 ;
if ( V_124 -> V_3 . V_4 & V_100 ) {
V_4 |= V_5 ;
V_2 -> V_3 . V_6 = V_124 -> V_3 . V_6 ;
}
}
if ( ( V_124 -> V_3 . V_4 & V_89 ) &&
V_182 )
V_4 |= V_89 ;
if ( ( V_124 -> V_3 . V_4 & V_91 ) &&
V_183 )
V_4 |= V_91 ;
if ( ( V_124 -> V_3 . V_4 & V_87 ) &&
V_184 )
V_4 |= V_87 ;
if ( ( V_124 -> V_3 . V_4 & V_97 ) &&
V_185 )
V_4 |= V_97 ;
if ( ( V_124 -> V_3 . V_4 & V_102 ) &&
V_186 )
V_4 |= V_102 ;
if ( V_124 -> V_3 . V_4 & V_104 )
V_4 |= V_104 ;
if ( V_124 -> V_3 . V_75 & V_107 )
V_75 |= V_107 ;
V_2 -> V_3 . V_4 |= V_4 ;
V_2 -> V_3 . V_75 |= V_75 ;
}
case V_187 :
V_2 -> V_3 . V_12 = V_188 ;
V_2 -> V_14 . V_15 = V_16 ;
V_2 -> V_14 . V_189 = V_2 -> V_14 . V_190 = 0 ;
V_2 -> V_14 . V_191 . V_192 = NULL ;
break;
default:
ASSERT ( 0 ) ;
}
V_2 -> V_3 . V_18 = V_188 ;
V_2 -> V_3 . V_193 = 0 ;
F_66 ( V_123 , V_2 , V_17 ) ;
F_67 ( V_123 , V_2 , V_77 ) ;
F_68 ( V_2 ) ;
* V_117 = V_2 ;
return 0 ;
}
int
F_69 (
T_9 * * V_194 ,
T_3 * V_114 ,
T_10 V_125 ,
T_11 V_126 ,
T_12 V_127 ,
T_13 V_128 ,
int V_129 ,
T_3 * * V_117 ,
int * V_195 )
{
T_9 * V_123 ;
T_3 * V_2 ;
T_14 * V_130 = NULL ;
int V_196 ;
void * V_197 ;
T_2 V_198 ;
V_123 = * V_194 ;
ASSERT ( V_123 -> V_199 & V_200 ) ;
V_196 = F_52 ( V_123 , V_114 , V_125 , V_126 , V_127 , V_128 , V_129 ,
& V_130 , & V_2 ) ;
if ( V_196 ) {
* V_117 = NULL ;
return V_196 ;
}
if ( ! V_130 && ! V_2 ) {
* V_117 = NULL ;
return - V_201 ;
}
if ( V_130 ) {
F_70 ( V_123 , V_130 ) ;
V_197 = NULL ;
V_198 = 0 ;
if ( V_123 -> V_202 ) {
V_197 = ( void * ) V_123 -> V_202 ;
V_123 -> V_202 = NULL ;
V_198 = V_123 -> V_199 & V_203 ;
V_123 -> V_199 &= ~ ( V_203 ) ;
}
V_196 = F_71 ( & V_123 , 0 ) ;
if ( V_195 != NULL )
* V_195 = 1 ;
if ( V_197 ) {
V_123 -> V_202 = V_197 ;
V_123 -> V_199 |= V_198 ;
}
if ( V_196 ) {
F_72 ( V_130 ) ;
* V_194 = V_123 ;
* V_117 = NULL ;
return V_196 ;
}
F_73 ( V_123 , V_130 ) ;
V_196 = F_52 ( V_123 , V_114 , V_125 , V_126 , V_127 , V_128 ,
V_129 , & V_130 , & V_2 ) ;
if ( V_196 ) {
* V_194 = V_123 ;
* V_117 = NULL ;
return V_196 ;
}
ASSERT ( ! V_130 && V_2 ) ;
} else {
if ( V_195 != NULL )
* V_195 = 0 ;
}
* V_117 = V_2 ;
* V_194 = V_123 ;
return 0 ;
}
int
F_74 (
T_9 * V_123 ,
T_3 * V_2 )
{
int error ;
F_75 ( V_123 , V_2 , V_204 ) ;
ASSERT ( V_2 -> V_3 . V_142 > 0 ) ;
V_2 -> V_3 . V_142 -- ;
F_76 ( F_77 ( V_2 ) ) ;
F_67 ( V_123 , V_2 , V_170 ) ;
error = 0 ;
if ( V_2 -> V_3 . V_142 == 0 ) {
error = F_78 ( V_123 , V_2 ) ;
}
return error ;
}
int
F_79 (
T_9 * V_123 ,
T_3 * V_2 )
{
F_75 ( V_123 , V_2 , V_204 ) ;
ASSERT ( V_2 -> V_3 . V_139 > 1 ) ;
ASSERT ( V_2 -> V_3 . V_142 > 0 || ( F_77 ( V_2 ) -> V_205 & V_206 ) ) ;
V_2 -> V_3 . V_142 ++ ;
F_80 ( F_77 ( V_2 ) ) ;
F_67 ( V_123 , V_2 , V_170 ) ;
return 0 ;
}
int
F_81 (
T_3 * V_114 ,
struct V_115 * V_116 ,
T_10 V_125 ,
T_12 V_127 ,
T_3 * * V_117 )
{
int V_207 = F_60 ( V_125 ) ;
struct V_131 * V_132 = V_114 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_208 * V_123 = NULL ;
int error ;
T_15 V_209 ;
T_16 V_210 ;
bool V_211 = false ;
T_13 V_128 ;
struct V_212 * V_213 = NULL ;
struct V_212 * V_214 = NULL ;
struct V_212 * V_215 = NULL ;
struct V_216 * V_217 ;
T_2 V_218 ;
F_82 ( V_114 , V_116 ) ;
if ( F_48 ( V_132 ) )
return - V_120 ;
V_128 = F_83 ( V_114 ) ;
error = F_84 ( V_114 , F_54 ( F_55 () ) ,
F_56 ( F_57 () ) , V_128 ,
V_219 | V_220 ,
& V_213 , & V_214 , & V_215 ) ;
if ( error )
return error ;
if ( V_207 ) {
V_127 = 0 ;
V_218 = F_85 ( V_132 , V_116 -> V_221 ) ;
V_217 = & F_86 ( V_132 ) -> V_222 ;
V_123 = F_87 ( V_132 , V_223 ) ;
} else {
V_218 = F_88 ( V_132 , V_116 -> V_221 ) ;
V_217 = & F_86 ( V_132 ) -> V_224 ;
V_123 = F_87 ( V_132 , V_225 ) ;
}
error = F_89 ( V_123 , V_217 , V_218 , 0 ) ;
if ( error == - V_201 ) {
F_90 ( V_132 ) ;
error = F_89 ( V_123 , V_217 , V_218 , 0 ) ;
}
if ( error == - V_201 ) {
V_218 = 0 ;
error = F_89 ( V_123 , V_217 , 0 , 0 ) ;
}
if ( error )
goto V_226;
F_4 ( V_114 , V_23 | V_17 |
V_45 | V_39 ) ;
V_211 = true ;
F_91 ( & V_209 , & V_210 ) ;
error = F_92 ( V_123 , V_132 , V_213 , V_214 ,
V_215 , V_218 , 1 , 0 ) ;
if ( error )
goto V_226;
if ( ! V_218 ) {
error = F_93 ( V_123 , V_114 , V_116 ) ;
if ( error )
goto V_226;
}
error = F_69 ( & V_123 , V_114 , V_125 , V_207 ? 2 : 1 , V_127 ,
V_128 , V_218 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_226;
F_66 ( V_123 , V_114 , V_23 | V_17 ) ;
V_211 = false ;
error = F_94 ( V_123 , V_114 , V_116 , V_2 -> V_69 ,
& V_210 , & V_209 , V_218 ?
V_218 - F_95 ( V_132 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_201 ) ;
goto V_226;
}
F_75 ( V_123 , V_114 , V_227 | V_204 ) ;
F_67 ( V_123 , V_114 , V_170 ) ;
if ( V_207 ) {
error = F_96 ( V_123 , V_2 , V_114 ) ;
if ( error )
goto V_228;
error = F_79 ( V_123 , V_114 ) ;
if ( error )
goto V_228;
}
if ( V_132 -> V_229 & ( V_230 | V_231 ) )
F_97 ( V_123 ) ;
F_98 ( V_123 , V_2 , V_213 , V_214 , V_215 ) ;
error = F_99 ( & V_123 , & V_209 , NULL ) ;
if ( error )
goto V_228;
error = F_100 ( V_123 ) ;
if ( error )
goto V_232;
F_101 ( V_213 ) ;
F_101 ( V_214 ) ;
F_101 ( V_215 ) ;
* V_117 = V_2 ;
return 0 ;
V_228:
F_102 ( & V_209 ) ;
V_226:
F_103 ( V_123 ) ;
V_232:
if ( V_2 ) {
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
}
F_101 ( V_213 ) ;
F_101 ( V_214 ) ;
F_101 ( V_215 ) ;
if ( V_211 )
F_18 ( V_114 , V_23 | V_17 ) ;
return error ;
}
int
F_106 (
struct V_1 * V_114 ,
struct V_233 * V_233 ,
T_10 V_125 ,
struct V_1 * * V_117 )
{
struct V_131 * V_132 = V_114 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_208 * V_123 = NULL ;
int error ;
T_13 V_128 ;
struct V_212 * V_213 = NULL ;
struct V_212 * V_214 = NULL ;
struct V_212 * V_215 = NULL ;
struct V_216 * V_217 ;
T_2 V_218 ;
if ( F_48 ( V_132 ) )
return - V_120 ;
V_128 = F_83 ( V_114 ) ;
error = F_84 ( V_114 , F_54 ( F_55 () ) ,
F_56 ( F_57 () ) , V_128 ,
V_219 | V_220 ,
& V_213 , & V_214 , & V_215 ) ;
if ( error )
return error ;
V_218 = F_95 ( V_132 ) ;
V_123 = F_87 ( V_132 , V_234 ) ;
V_217 = & F_86 ( V_132 ) -> V_235 ;
error = F_89 ( V_123 , V_217 , V_218 , 0 ) ;
if ( error == - V_201 ) {
V_218 = 0 ;
error = F_89 ( V_123 , V_217 , 0 , 0 ) ;
}
if ( error )
goto V_226;
error = F_92 ( V_123 , V_132 , V_213 , V_214 ,
V_215 , V_218 , 1 , 0 ) ;
if ( error )
goto V_226;
error = F_69 ( & V_123 , V_114 , V_125 , 1 , 0 ,
V_128 , V_218 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_226;
if ( V_132 -> V_229 & V_230 )
F_97 ( V_123 ) ;
F_98 ( V_123 , V_2 , V_213 , V_214 , V_215 ) ;
V_2 -> V_3 . V_142 -- ;
error = F_78 ( V_123 , V_2 ) ;
if ( error )
goto V_226;
error = F_100 ( V_123 ) ;
if ( error )
goto V_232;
F_101 ( V_213 ) ;
F_101 ( V_214 ) ;
F_101 ( V_215 ) ;
* V_117 = V_2 ;
return 0 ;
V_226:
F_103 ( V_123 ) ;
V_232:
if ( V_2 ) {
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
}
F_101 ( V_213 ) ;
F_101 ( V_214 ) ;
F_101 ( V_215 ) ;
return error ;
}
int
F_107 (
T_3 * V_236 ,
T_3 * V_237 ,
struct V_115 * V_238 )
{
T_17 * V_132 = V_236 -> V_7 ;
T_9 * V_123 ;
int error ;
T_15 V_209 ;
T_16 V_210 ;
int V_218 ;
F_108 ( V_236 , V_238 ) ;
ASSERT ( ! F_60 ( V_237 -> V_3 . V_140 ) ) ;
if ( F_48 ( V_132 ) )
return - V_120 ;
error = F_109 ( V_237 , 0 ) ;
if ( error )
goto V_239;
error = F_109 ( V_236 , 0 ) ;
if ( error )
goto V_239;
V_123 = F_87 ( V_132 , V_240 ) ;
V_218 = F_110 ( V_132 , V_238 -> V_221 ) ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_241 , V_218 , 0 ) ;
if ( error == - V_201 ) {
V_218 = 0 ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_241 , 0 , 0 ) ;
}
if ( error )
goto V_242;
F_4 ( V_236 , V_23 | V_45 ) ;
F_30 ( V_237 , V_236 , V_17 ) ;
F_66 ( V_123 , V_237 , V_17 ) ;
F_66 ( V_123 , V_236 , V_23 | V_17 ) ;
if ( F_111 ( ( V_236 -> V_3 . V_4 & V_95 ) &&
( F_112 ( V_236 ) != F_112 ( V_237 ) ) ) ) {
error = - V_243 ;
goto V_242;
}
if ( ! V_218 ) {
error = F_93 ( V_123 , V_236 , V_238 ) ;
if ( error )
goto V_242;
}
F_91 ( & V_209 , & V_210 ) ;
if ( V_237 -> V_3 . V_142 == 0 ) {
error = F_113 ( V_123 , V_237 ) ;
if ( error )
goto V_242;
}
error = F_94 ( V_123 , V_236 , V_238 , V_237 -> V_69 ,
& V_210 , & V_209 , V_218 ) ;
if ( error )
goto V_242;
F_75 ( V_123 , V_236 , V_227 | V_204 ) ;
F_67 ( V_123 , V_236 , V_170 ) ;
error = F_79 ( V_123 , V_237 ) ;
if ( error )
goto V_242;
if ( V_132 -> V_229 & ( V_230 | V_231 ) )
F_97 ( V_123 ) ;
error = F_99 ( & V_123 , & V_209 , NULL ) ;
if ( error ) {
F_102 ( & V_209 ) ;
goto V_242;
}
return F_100 ( V_123 ) ;
V_242:
F_103 ( V_123 ) ;
V_239:
return error ;
}
int
F_114 (
struct V_208 * * V_194 ,
struct V_1 * V_2 ,
int V_244 ,
T_18 V_245 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_208 * V_123 = * V_194 ;
T_15 V_209 ;
T_16 V_210 ;
T_19 V_246 ;
T_19 V_247 ;
T_20 V_248 ;
int error = 0 ;
int V_249 = 0 ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( ! F_115 ( & F_77 ( V_2 ) -> V_250 ) ||
F_23 ( V_2 , V_23 ) ) ;
ASSERT ( V_245 <= F_116 ( V_2 ) ) ;
ASSERT ( V_123 -> V_199 & V_200 ) ;
ASSERT ( V_2 -> V_58 != NULL ) ;
ASSERT ( V_2 -> V_58 -> V_251 == 0 ) ;
ASSERT ( ! F_117 ( V_132 , V_2 ) ) ;
F_118 ( V_2 , V_245 ) ;
V_246 = F_119 ( V_132 , ( V_252 ) V_245 ) ;
V_247 = F_119 ( V_132 , V_132 -> V_151 -> V_253 ) ;
if ( V_246 == V_247 )
return 0 ;
ASSERT ( V_246 < V_247 ) ;
V_248 = V_247 - V_246 + 1 ;
while ( ! V_249 ) {
F_91 ( & V_209 , & V_210 ) ;
error = F_120 ( V_123 , V_2 ,
V_246 , V_248 ,
F_121 ( V_244 ) ,
V_254 ,
& V_210 , & V_209 ,
& V_249 ) ;
if ( error )
goto V_228;
error = F_99 ( & V_123 , & V_209 , V_2 ) ;
if ( error )
goto V_228;
error = F_71 ( & V_123 , V_2 ) ;
if ( error )
goto V_31;
}
F_67 ( V_123 , V_2 , V_170 ) ;
F_122 ( V_2 , V_245 ) ;
V_31:
* V_194 = V_123 ;
return error ;
V_228:
F_102 ( & V_209 ) ;
goto V_31;
}
int
F_123 (
T_3 * V_2 )
{
T_17 * V_132 = V_2 -> V_7 ;
int error ;
if ( ! F_65 ( V_2 -> V_3 . V_140 ) || ( V_2 -> V_3 . V_140 == 0 ) )
return 0 ;
if ( V_132 -> V_229 & V_255 )
return 0 ;
if ( ! F_48 ( V_132 ) ) {
int V_256 ;
V_256 = F_124 ( V_2 , V_257 ) ;
if ( V_256 ) {
F_125 ( V_2 , V_258 ) ;
if ( V_2 -> V_259 > 0 ) {
error = F_126 ( F_77 ( V_2 ) -> V_260 ) ;
if ( error )
return error ;
}
}
}
if ( V_2 -> V_3 . V_142 == 0 )
return 0 ;
if ( F_127 ( V_2 , false ) ) {
if ( F_128 ( V_2 , V_258 ) )
return 0 ;
error = F_129 ( V_132 , V_2 , true ) ;
if ( error && error != - V_261 )
return error ;
if ( V_2 -> V_259 )
F_130 ( V_2 , V_258 ) ;
}
return 0 ;
}
STATIC int
F_131 (
struct V_1 * V_2 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_208 * V_123 ;
int error ;
V_123 = F_87 ( V_132 , V_262 ) ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_263 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_48 ( V_132 ) ) ;
F_103 ( V_123 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_66 ( V_123 , V_2 , 0 ) ;
V_2 -> V_3 . V_148 = 0 ;
F_67 ( V_123 , V_2 , V_170 ) ;
error = F_114 ( & V_123 , V_2 , V_264 , 0 ) ;
if ( error )
goto V_265;
ASSERT ( V_2 -> V_3 . V_149 == 0 ) ;
error = F_100 ( V_123 ) ;
if ( error )
goto V_266;
F_18 ( V_2 , V_17 ) ;
return 0 ;
V_265:
F_103 ( V_123 ) ;
V_266:
F_18 ( V_2 , V_17 ) ;
return error ;
}
STATIC int
F_132 (
struct V_1 * V_2 )
{
T_15 V_209 ;
T_16 V_210 ;
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_208 * V_123 ;
int error ;
V_123 = F_87 ( V_132 , V_262 ) ;
V_123 -> V_199 |= V_267 ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_268 ,
F_133 ( V_132 ) , 0 ) ;
if ( error ) {
if ( error == - V_201 ) {
F_134 ( V_132 ,
L_1
L_2 ) ;
} else {
ASSERT ( F_48 ( V_132 ) ) ;
}
F_103 ( V_123 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_66 ( V_123 , V_2 , 0 ) ;
F_91 ( & V_209 , & V_210 ) ;
error = F_135 ( V_123 , V_2 , & V_209 ) ;
if ( error ) {
if ( ! F_48 ( V_132 ) ) {
F_136 ( V_132 , L_3 ,
V_269 , error ) ;
F_137 ( V_132 , V_270 ) ;
}
F_103 ( V_123 ) ;
F_18 ( V_2 , V_17 ) ;
return error ;
}
F_138 ( V_123 , V_2 , V_271 , - 1 ) ;
error = F_99 ( & V_123 , & V_209 , NULL ) ;
if ( error ) {
F_136 ( V_132 , L_4 ,
V_269 , error ) ;
F_102 ( & V_209 ) ;
}
error = F_100 ( V_123 ) ;
if ( error )
F_136 ( V_132 , L_5 ,
V_269 , error ) ;
F_18 ( V_2 , V_17 ) ;
return 0 ;
}
void
F_139 (
T_3 * V_2 )
{
struct V_131 * V_132 ;
int error ;
int V_272 = 0 ;
if ( V_2 -> V_3 . V_140 == 0 ) {
ASSERT ( V_2 -> V_14 . V_190 == 0 ) ;
ASSERT ( V_2 -> V_14 . V_273 == 0 ) ;
return;
}
V_132 = V_2 -> V_7 ;
if ( V_132 -> V_229 & V_255 )
return;
if ( V_2 -> V_3 . V_142 != 0 ) {
if ( F_127 ( V_2 , true ) )
F_129 ( V_132 , V_2 , false ) ;
return;
}
if ( F_65 ( V_2 -> V_3 . V_140 ) &&
( V_2 -> V_3 . V_148 != 0 || F_116 ( V_2 ) != 0 ||
V_2 -> V_3 . V_149 > 0 || V_2 -> V_259 > 0 ) )
V_272 = 1 ;
error = F_109 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_140 ( V_2 -> V_3 . V_140 ) )
error = F_141 ( V_2 ) ;
else if ( V_272 )
error = F_131 ( V_2 ) ;
if ( error )
return;
if ( F_41 ( V_2 ) ) {
error = F_142 ( V_2 ) ;
if ( error )
return;
}
ASSERT ( ! V_2 -> V_19 ) ;
ASSERT ( V_2 -> V_3 . V_193 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_274 == 0 ) ;
error = F_132 ( V_2 ) ;
if ( error )
return;
F_143 ( V_2 ) ;
}
int
F_78 (
T_9 * V_123 ,
T_3 * V_2 )
{
T_17 * V_132 ;
T_21 * V_275 ;
T_22 * V_113 ;
T_14 * V_276 ;
T_14 * V_277 ;
T_23 V_278 ;
short V_279 ;
int V_280 ;
int error ;
ASSERT ( V_2 -> V_3 . V_142 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_140 != 0 ) ;
V_132 = V_123 -> V_133 ;
error = F_144 ( V_132 , V_123 , F_145 ( V_132 , V_2 -> V_69 ) , & V_276 ) ;
if ( error )
return error ;
V_275 = F_146 ( V_276 ) ;
V_278 = F_147 ( V_132 , V_2 -> V_69 ) ;
ASSERT ( V_278 != 0 ) ;
V_279 = V_278 % V_281 ;
ASSERT ( V_275 -> V_282 [ V_279 ] ) ;
ASSERT ( F_148 ( V_275 -> V_282 [ V_279 ] ) != V_278 ) ;
if ( V_275 -> V_282 [ V_279 ] != F_149 ( V_283 ) ) {
error = F_150 ( V_132 , V_123 , & V_2 -> V_284 , & V_113 , & V_277 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_113 -> V_285 == F_149 ( V_283 ) ) ;
V_113 -> V_285 = V_275 -> V_282 [ V_279 ] ;
V_280 = V_2 -> V_284 . V_286 +
F_151 ( T_22 , V_285 ) ;
F_152 ( V_132 , V_113 ) ;
F_153 ( V_123 , V_277 ) ;
F_154 ( V_123 , V_277 , V_280 ,
( V_280 + sizeof( T_23 ) - 1 ) ) ;
F_155 ( V_132 , V_277 ) ;
}
ASSERT ( V_278 != 0 ) ;
V_275 -> V_282 [ V_279 ] = F_149 ( V_278 ) ;
V_280 = F_151 ( T_21 , V_282 ) +
( sizeof( T_23 ) * V_279 ) ;
F_156 ( V_123 , V_276 , V_287 ) ;
F_154 ( V_123 , V_276 , V_280 ,
( V_280 + sizeof( T_23 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_113 (
T_9 * V_123 ,
T_3 * V_2 )
{
T_8 V_288 ;
T_17 * V_132 ;
T_21 * V_275 ;
T_22 * V_113 ;
T_14 * V_276 ;
T_14 * V_277 ;
T_24 V_289 ;
T_23 V_278 ;
T_23 V_290 ;
T_14 * V_291 ;
T_22 * V_292 = NULL ;
short V_279 ;
int V_280 , V_293 = 0 ;
int error ;
V_132 = V_123 -> V_133 ;
V_289 = F_145 ( V_132 , V_2 -> V_69 ) ;
error = F_144 ( V_132 , V_123 , V_289 , & V_276 ) ;
if ( error )
return error ;
V_275 = F_146 ( V_276 ) ;
V_278 = F_147 ( V_132 , V_2 -> V_69 ) ;
ASSERT ( V_278 != 0 ) ;
V_279 = V_278 % V_281 ;
ASSERT ( V_275 -> V_282 [ V_279 ] != F_149 ( V_283 ) ) ;
ASSERT ( V_275 -> V_282 [ V_279 ] ) ;
if ( F_148 ( V_275 -> V_282 [ V_279 ] ) == V_278 ) {
error = F_150 ( V_132 , V_123 , & V_2 -> V_284 , & V_113 , & V_277 ,
0 , 0 ) ;
if ( error ) {
F_157 ( V_132 , L_6 ,
V_269 , error ) ;
return error ;
}
V_290 = F_148 ( V_113 -> V_285 ) ;
ASSERT ( V_290 != 0 ) ;
if ( V_290 != V_283 ) {
V_113 -> V_285 = F_149 ( V_283 ) ;
V_280 = V_2 -> V_284 . V_286 +
F_151 ( T_22 , V_285 ) ;
F_152 ( V_132 , V_113 ) ;
F_153 ( V_123 , V_277 ) ;
F_154 ( V_123 , V_277 , V_280 ,
( V_280 + sizeof( T_23 ) - 1 ) ) ;
F_155 ( V_132 , V_277 ) ;
} else {
F_158 ( V_123 , V_277 ) ;
}
ASSERT ( V_290 != 0 ) ;
ASSERT ( V_290 != V_278 ) ;
V_275 -> V_282 [ V_279 ] = F_149 ( V_290 ) ;
V_280 = F_151 ( T_21 , V_282 ) +
( sizeof( T_23 ) * V_279 ) ;
F_156 ( V_123 , V_276 , V_287 ) ;
F_154 ( V_123 , V_276 , V_280 ,
( V_280 + sizeof( T_23 ) - 1 ) ) ;
} else {
V_290 = F_148 ( V_275 -> V_282 [ V_279 ] ) ;
V_291 = NULL ;
while ( V_290 != V_278 ) {
struct V_294 V_295 ;
if ( V_291 )
F_158 ( V_123 , V_291 ) ;
V_295 . V_296 = 0 ;
V_288 = F_159 ( V_132 , V_289 , V_290 ) ;
error = V_294 ( V_132 , V_123 , V_288 , & V_295 , 0 ) ;
if ( error ) {
F_157 ( V_132 ,
L_7 ,
V_269 , error ) ;
return error ;
}
error = F_150 ( V_132 , V_123 , & V_295 , & V_292 ,
& V_291 , 0 , 0 ) ;
if ( error ) {
F_157 ( V_132 ,
L_6 ,
V_269 , error ) ;
return error ;
}
V_293 = V_295 . V_286 ;
V_290 = F_148 ( V_292 -> V_285 ) ;
ASSERT ( V_290 != V_283 ) ;
ASSERT ( V_290 != 0 ) ;
}
error = F_150 ( V_132 , V_123 , & V_2 -> V_284 , & V_113 , & V_277 ,
0 , 0 ) ;
if ( error ) {
F_157 ( V_132 , L_8 ,
V_269 , error ) ;
return error ;
}
V_290 = F_148 ( V_113 -> V_285 ) ;
ASSERT ( V_290 != 0 ) ;
ASSERT ( V_290 != V_278 ) ;
if ( V_290 != V_283 ) {
V_113 -> V_285 = F_149 ( V_283 ) ;
V_280 = V_2 -> V_284 . V_286 +
F_151 ( T_22 , V_285 ) ;
F_152 ( V_132 , V_113 ) ;
F_153 ( V_123 , V_277 ) ;
F_154 ( V_123 , V_277 , V_280 ,
( V_280 + sizeof( T_23 ) - 1 ) ) ;
F_155 ( V_132 , V_277 ) ;
} else {
F_158 ( V_123 , V_277 ) ;
}
V_292 -> V_285 = F_149 ( V_290 ) ;
ASSERT ( V_290 != 0 ) ;
V_280 = V_293 + F_151 ( T_22 , V_285 ) ;
F_152 ( V_132 , V_292 ) ;
F_153 ( V_123 , V_291 ) ;
F_154 ( V_123 , V_291 , V_280 ,
( V_280 + sizeof( T_23 ) - 1 ) ) ;
F_155 ( V_132 , V_291 ) ;
}
return 0 ;
}
STATIC int
F_160 (
T_3 * V_297 ,
T_9 * V_123 ,
struct V_298 * V_299 )
{
T_17 * V_132 = V_297 -> V_7 ;
int V_300 ;
int V_301 ;
int V_302 ;
int V_53 , V_54 ;
int V_303 ;
T_25 V_304 ;
T_14 * V_305 ;
T_3 * V_2 ;
T_26 * V_306 ;
T_4 * V_307 ;
struct V_308 * V_309 ;
T_8 V_119 ;
V_119 = V_299 -> V_310 ;
V_309 = F_161 ( V_132 , F_145 ( V_132 , V_119 ) ) ;
V_300 = F_162 ( V_132 ) ;
V_301 = V_300 << V_132 -> V_8 . V_311 ;
V_302 = V_132 -> V_312 / V_300 ;
for ( V_54 = 0 ; V_54 < V_302 ; V_54 ++ , V_119 += V_301 ) {
V_303 = V_119 - V_299 -> V_310 ;
if ( ( V_299 -> V_313 & F_163 ( V_303 ) ) == 0 ) {
ASSERT ( F_164 ( V_303 , V_301 ) == 0 ) ;
continue;
}
V_304 = F_165 ( V_132 , F_145 ( V_132 , V_119 ) ,
F_166 ( V_132 , V_119 ) ) ;
V_305 = F_167 ( V_123 , V_132 -> V_314 , V_304 ,
V_132 -> V_315 * V_300 ,
V_316 ) ;
if ( ! V_305 )
return - V_317 ;
V_305 -> V_318 = & V_319 ;
V_307 = V_305 -> V_320 ;
while ( V_307 ) {
if ( V_307 -> V_321 == V_322 ) {
V_306 = ( T_26 * ) V_307 ;
ASSERT ( V_306 -> V_323 == 1 ) ;
V_307 -> V_324 = V_325 ;
F_168 ( V_132 -> V_326 ,
& V_306 -> V_327 ,
& V_306 -> V_328 . V_329 ) ;
F_130 ( V_306 -> V_330 , V_331 ) ;
}
V_307 = V_307 -> V_332 ;
}
for ( V_53 = 0 ; V_53 < V_301 ; V_53 ++ ) {
V_333:
F_169 () ;
V_2 = F_170 ( & V_309 -> V_334 ,
F_147 ( V_132 , ( V_119 + V_53 ) ) ) ;
if ( ! V_2 ) {
F_171 () ;
continue;
}
F_172 ( & V_2 -> V_335 ) ;
if ( V_2 -> V_69 != V_119 + V_53 ||
F_173 ( V_2 , V_331 ) ) {
F_174 ( & V_2 -> V_335 ) ;
F_171 () ;
continue;
}
F_174 ( & V_2 -> V_335 ) ;
if ( V_2 != V_297 &&
! F_12 ( V_2 , V_17 ) ) {
F_171 () ;
F_28 ( 1 ) ;
goto V_333;
}
F_171 () ;
F_175 ( V_2 ) ;
F_130 ( V_2 , V_331 ) ;
V_306 = V_2 -> V_58 ;
if ( ! V_306 || F_176 ( V_2 ) ) {
ASSERT ( V_2 != V_297 ) ;
F_177 ( V_2 ) ;
F_18 ( V_2 , V_17 ) ;
continue;
}
V_306 -> V_336 = V_306 -> V_337 ;
V_306 -> V_337 = 0 ;
V_306 -> V_338 = 0 ;
V_306 -> V_323 = 1 ;
F_168 ( V_132 -> V_326 , & V_306 -> V_327 ,
& V_306 -> V_328 . V_329 ) ;
F_178 ( V_305 , V_325 ,
& V_306 -> V_328 ) ;
if ( V_2 != V_297 )
F_18 ( V_2 , V_17 ) ;
}
F_179 ( V_123 , V_305 ) ;
F_180 ( V_123 , V_305 ) ;
}
F_181 ( V_309 ) ;
return 0 ;
}
int
F_135 (
T_9 * V_123 ,
T_3 * V_2 ,
T_15 * V_339 )
{
int error ;
struct V_298 V_299 = { 0 } ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( V_2 -> V_3 . V_142 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_149 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_193 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_148 == 0 || ! F_65 ( V_2 -> V_3 . V_140 ) ) ;
ASSERT ( V_2 -> V_3 . V_150 == 0 ) ;
error = F_113 ( V_123 , V_2 ) ;
if ( error )
return error ;
error = F_182 ( V_123 , V_2 -> V_69 , V_339 , & V_299 ) ;
if ( error )
return error ;
V_2 -> V_3 . V_140 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_160 = 0 ;
V_2 -> V_3 . V_274 = 0 ;
V_2 -> V_3 . V_12 = V_188 ;
V_2 -> V_3 . V_18 = V_188 ;
V_2 -> V_3 . V_340 ++ ;
F_67 ( V_123 , V_2 , V_170 ) ;
if ( V_299 . V_341 )
error = F_160 ( V_2 , V_123 , & V_299 ) ;
return error ;
}
static void
F_183 (
struct V_1 * V_2 )
{
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
F_184 ( V_2 , V_21 ) ;
F_185 ( V_2 -> V_7 , V_2 -> V_58 -> V_342 , 0 ) ;
}
static void
F_186 (
struct V_1 * V_2 )
{
T_5 * V_70 = F_32 ( & V_2 -> V_71 , V_343 ) ;
F_33 ( V_73 , & V_2 -> V_71 , V_343 ) ;
F_183 ( V_2 ) ;
do {
F_187 ( V_70 , & V_73 . V_73 , V_74 ) ;
if ( F_188 ( V_2 ) )
F_36 () ;
} while ( F_188 ( V_2 ) );
F_38 ( V_70 , & V_73 . V_73 ) ;
}
void
F_189 (
struct V_1 * V_2 )
{
if ( F_188 ( V_2 ) )
F_186 ( V_2 ) ;
}
int
F_190 (
T_3 * V_114 ,
struct V_115 * V_116 ,
T_3 * V_2 )
{
T_17 * V_132 = V_114 -> V_7 ;
T_9 * V_123 = NULL ;
int V_207 = F_60 ( V_2 -> V_3 . V_140 ) ;
int error = 0 ;
T_15 V_209 ;
T_16 V_210 ;
T_2 V_218 ;
F_191 ( V_114 , V_116 ) ;
if ( F_48 ( V_132 ) )
return - V_120 ;
error = F_109 ( V_114 , 0 ) ;
if ( error )
goto V_239;
error = F_109 ( V_2 , 0 ) ;
if ( error )
goto V_239;
if ( V_207 )
V_123 = F_87 ( V_132 , V_344 ) ;
else
V_123 = F_87 ( V_132 , V_345 ) ;
V_218 = F_192 ( V_132 ) ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_346 , V_218 , 0 ) ;
if ( error == - V_201 ) {
V_218 = 0 ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_346 , 0 , 0 ) ;
}
if ( error ) {
ASSERT ( error != - V_201 ) ;
goto V_226;
}
F_4 ( V_114 , V_23 | V_45 ) ;
F_30 ( V_114 , V_2 , V_17 ) ;
F_66 ( V_123 , V_114 , V_23 | V_17 ) ;
F_66 ( V_123 , V_2 , V_17 ) ;
if ( V_207 ) {
ASSERT ( V_2 -> V_3 . V_142 >= 2 ) ;
if ( V_2 -> V_3 . V_142 != 2 ) {
error = - V_347 ;
goto V_226;
}
if ( ! F_193 ( V_2 ) ) {
error = - V_347 ;
goto V_226;
}
error = F_74 ( V_123 , V_114 ) ;
if ( error )
goto V_226;
error = F_74 ( V_123 , V_2 ) ;
if ( error )
goto V_226;
} else {
F_67 ( V_123 , V_114 , V_170 ) ;
}
F_75 ( V_123 , V_114 , V_227 | V_204 ) ;
error = F_74 ( V_123 , V_2 ) ;
if ( error )
goto V_226;
F_91 ( & V_209 , & V_210 ) ;
error = F_194 ( V_123 , V_114 , V_116 , V_2 -> V_69 ,
& V_210 , & V_209 , V_218 ) ;
if ( error ) {
ASSERT ( error != - V_348 ) ;
goto V_228;
}
if ( V_132 -> V_229 & ( V_230 | V_231 ) )
F_97 ( V_123 ) ;
error = F_99 ( & V_123 , & V_209 , NULL ) ;
if ( error )
goto V_228;
error = F_100 ( V_123 ) ;
if ( error )
goto V_239;
if ( V_207 && F_195 ( V_2 ) )
F_196 ( V_2 ) ;
return 0 ;
V_228:
F_102 ( & V_209 ) ;
V_226:
F_103 ( V_123 ) ;
V_239:
return error ;
}
STATIC void
F_197 (
struct V_1 * V_349 ,
struct V_1 * V_350 ,
struct V_1 * V_67 ,
struct V_1 * V_351 ,
struct V_1 * V_352 ,
struct V_1 * * V_353 ,
int * V_354 )
{
int V_53 , V_54 ;
ASSERT ( * V_354 == V_355 ) ;
memset ( V_353 , 0 , * V_354 * sizeof( struct V_1 * ) ) ;
V_53 = 0 ;
V_353 [ V_53 ++ ] = V_349 ;
V_353 [ V_53 ++ ] = V_350 ;
V_353 [ V_53 ++ ] = V_67 ;
if ( V_351 )
V_353 [ V_53 ++ ] = V_351 ;
if ( V_352 )
V_353 [ V_53 ++ ] = V_352 ;
* V_354 = V_53 ;
for ( V_53 = 0 ; V_53 < * V_354 ; V_53 ++ ) {
for ( V_54 = 1 ; V_54 < * V_354 ; V_54 ++ ) {
if ( V_353 [ V_54 ] -> V_69 < V_353 [ V_54 - 1 ] -> V_69 ) {
struct V_1 * V_68 = V_353 [ V_54 ] ;
V_353 [ V_54 ] = V_353 [ V_54 - 1 ] ;
V_353 [ V_54 - 1 ] = V_68 ;
}
}
}
}
static int
F_198 (
struct V_208 * V_123 ,
struct V_356 * V_209 )
{
int error ;
if ( V_123 -> V_133 -> V_229 & ( V_230 | V_231 ) )
F_97 ( V_123 ) ;
error = F_99 ( & V_123 , V_209 , NULL ) ;
if ( error ) {
F_102 ( V_209 ) ;
F_103 ( V_123 ) ;
return error ;
}
return F_100 ( V_123 ) ;
}
STATIC int
F_199 (
struct V_208 * V_123 ,
struct V_1 * V_349 ,
struct V_115 * V_357 ,
struct V_1 * V_67 ,
struct V_1 * V_350 ,
struct V_115 * V_358 ,
struct V_1 * V_351 ,
struct V_356 * V_209 ,
T_16 * V_210 ,
int V_359 )
{
int error = 0 ;
int V_360 = 0 ;
int V_361 = 0 ;
int V_362 = 0 ;
error = F_200 ( V_123 , V_349 , V_357 ,
V_351 -> V_69 ,
V_210 , V_209 , V_359 ) ;
if ( error )
goto V_363;
error = F_200 ( V_123 , V_350 , V_358 ,
V_67 -> V_69 ,
V_210 , V_209 , V_359 ) ;
if ( error )
goto V_363;
if ( V_349 != V_350 ) {
V_362 = V_227 | V_204 ;
if ( F_60 ( V_351 -> V_3 . V_140 ) ) {
error = F_200 ( V_123 , V_351 , & V_364 ,
V_349 -> V_69 , V_210 ,
V_209 , V_359 ) ;
if ( error )
goto V_363;
if ( ! F_60 ( V_67 -> V_3 . V_140 ) ) {
error = F_74 ( V_123 , V_350 ) ;
if ( error )
goto V_363;
error = F_79 ( V_123 , V_349 ) ;
if ( error )
goto V_363;
}
V_360 |= V_204 ;
V_361 |= V_227 | V_204 ;
}
if ( F_60 ( V_67 -> V_3 . V_140 ) ) {
error = F_200 ( V_123 , V_67 , & V_364 ,
V_350 -> V_69 , V_210 ,
V_209 , V_359 ) ;
if ( error )
goto V_363;
if ( ! F_60 ( V_351 -> V_3 . V_140 ) ) {
error = F_74 ( V_123 , V_349 ) ;
if ( error )
goto V_363;
error = F_79 ( V_123 , V_350 ) ;
if ( error )
goto V_363;
}
V_360 |= V_227 | V_204 ;
V_361 |= V_204 ;
}
}
if ( V_360 ) {
F_75 ( V_123 , V_67 , V_360 ) ;
F_67 ( V_123 , V_67 , V_170 ) ;
}
if ( V_361 ) {
F_75 ( V_123 , V_351 , V_361 ) ;
F_67 ( V_123 , V_351 , V_170 ) ;
}
if ( V_362 ) {
F_75 ( V_123 , V_350 , V_362 ) ;
F_67 ( V_123 , V_350 , V_170 ) ;
}
F_75 ( V_123 , V_349 , V_227 | V_204 ) ;
F_67 ( V_123 , V_349 , V_170 ) ;
return F_198 ( V_123 , V_209 ) ;
V_363:
F_102 ( V_209 ) ;
F_103 ( V_123 ) ;
return error ;
}
static int
F_201 (
struct V_1 * V_114 ,
struct V_1 * * V_352 )
{
struct V_1 * tmpfile ;
int error ;
error = F_106 ( V_114 , NULL , V_173 | V_365 , & tmpfile ) ;
if ( error )
return error ;
F_76 ( F_77 ( tmpfile ) ) ;
F_104 ( tmpfile ) ;
F_77 ( tmpfile ) -> V_205 |= V_206 ;
* V_352 = tmpfile ;
return 0 ;
}
int
F_202 (
struct V_1 * V_366 ,
struct V_115 * V_367 ,
struct V_1 * V_368 ,
struct V_1 * V_369 ,
struct V_115 * V_238 ,
struct V_1 * V_370 ,
unsigned int V_77 )
{
struct V_131 * V_132 = V_366 -> V_7 ;
struct V_208 * V_123 ;
struct V_356 V_209 ;
T_16 V_210 ;
struct V_1 * V_352 = NULL ;
struct V_1 * V_51 [ V_355 ] ;
int V_354 = V_355 ;
bool V_371 = ( V_366 != V_369 ) ;
bool V_372 = F_60 ( V_368 -> V_3 . V_140 ) ;
int V_359 ;
int error ;
F_203 ( V_366 , V_369 , V_367 , V_238 ) ;
if ( ( V_77 & V_373 ) && ! V_370 )
return - V_374 ;
if ( V_77 & V_375 ) {
ASSERT ( ! ( V_77 & ( V_376 | V_373 ) ) ) ;
error = F_201 ( V_369 , & V_352 ) ;
if ( error )
return error ;
V_367 -> type = V_377 ;
}
F_197 ( V_366 , V_369 , V_368 , V_370 , V_352 ,
V_51 , & V_354 ) ;
V_123 = F_87 ( V_132 , V_378 ) ;
V_359 = F_204 ( V_132 , V_238 -> V_221 ) ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_379 , V_359 , 0 ) ;
if ( error == - V_201 ) {
V_359 = 0 ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_379 , 0 , 0 ) ;
}
if ( error )
goto V_226;
error = F_205 ( V_51 ) ;
if ( error )
goto V_226;
if ( ! V_371 )
F_4 ( V_366 , V_23 | V_45 ) ;
else
F_30 ( V_366 , V_369 ,
V_23 | V_45 ) ;
F_27 ( V_51 , V_354 , V_17 ) ;
F_66 ( V_123 , V_366 , V_23 | V_17 ) ;
if ( V_371 )
F_66 ( V_123 , V_369 , V_23 | V_17 ) ;
F_66 ( V_123 , V_368 , V_17 ) ;
if ( V_370 )
F_66 ( V_123 , V_370 , V_17 ) ;
if ( V_352 )
F_66 ( V_123 , V_352 , V_17 ) ;
if ( F_111 ( ( V_369 -> V_3 . V_4 & V_95 ) &&
( F_112 ( V_369 ) != F_112 ( V_368 ) ) ) ) {
error = - V_243 ;
goto V_226;
}
F_91 ( & V_209 , & V_210 ) ;
if ( V_77 & V_373 )
return F_199 ( V_123 , V_366 , V_367 , V_368 ,
V_369 , V_238 , V_370 ,
& V_209 , & V_210 , V_359 ) ;
if ( V_370 == NULL ) {
if ( ! V_359 ) {
error = F_93 ( V_123 , V_369 , V_238 ) ;
if ( error )
goto V_226;
}
error = F_94 ( V_123 , V_369 , V_238 ,
V_368 -> V_69 , & V_210 ,
& V_209 , V_359 ) ;
if ( error )
goto V_228;
F_75 ( V_123 , V_369 ,
V_227 | V_204 ) ;
if ( V_371 && V_372 ) {
error = F_79 ( V_123 , V_369 ) ;
if ( error )
goto V_228;
}
} else {
if ( F_60 ( V_370 -> V_3 . V_140 ) ) {
if ( ! ( F_193 ( V_370 ) ) ||
( V_370 -> V_3 . V_142 > 2 ) ) {
error = - V_380 ;
goto V_226;
}
}
error = F_200 ( V_123 , V_369 , V_238 ,
V_368 -> V_69 ,
& V_210 , & V_209 , V_359 ) ;
if ( error )
goto V_228;
F_75 ( V_123 , V_369 ,
V_227 | V_204 ) ;
error = F_74 ( V_123 , V_370 ) ;
if ( error )
goto V_228;
if ( V_372 ) {
error = F_74 ( V_123 , V_370 ) ;
if ( error )
goto V_228;
}
}
if ( V_371 && V_372 ) {
error = F_200 ( V_123 , V_368 , & V_364 ,
V_369 -> V_69 ,
& V_210 , & V_209 , V_359 ) ;
ASSERT ( error != - V_380 ) ;
if ( error )
goto V_228;
}
F_75 ( V_123 , V_368 , V_204 ) ;
F_67 ( V_123 , V_368 , V_170 ) ;
if ( V_372 && ( V_371 || V_370 != NULL ) ) {
error = F_74 ( V_123 , V_366 ) ;
if ( error )
goto V_228;
}
if ( V_352 ) {
error = F_200 ( V_123 , V_366 , V_367 , V_352 -> V_69 ,
& V_210 , & V_209 , V_359 ) ;
} else
error = F_194 ( V_123 , V_366 , V_367 , V_368 -> V_69 ,
& V_210 , & V_209 , V_359 ) ;
if ( error )
goto V_228;
if ( V_352 ) {
ASSERT ( F_77 ( V_352 ) -> V_381 == 0 && V_352 -> V_3 . V_142 == 0 ) ;
error = F_79 ( V_123 , V_352 ) ;
if ( error )
goto V_228;
error = F_113 ( V_123 , V_352 ) ;
if ( error )
goto V_228;
F_67 ( V_123 , V_352 , V_170 ) ;
F_77 ( V_352 ) -> V_205 &= ~ V_206 ;
}
F_75 ( V_123 , V_366 , V_227 | V_204 ) ;
F_67 ( V_123 , V_366 , V_170 ) ;
if ( V_371 )
F_67 ( V_123 , V_369 , V_170 ) ;
error = F_198 ( V_123 , & V_209 ) ;
if ( V_352 )
F_105 ( V_352 ) ;
return error ;
V_228:
F_102 ( & V_209 ) ;
V_226:
F_103 ( V_123 ) ;
if ( V_352 )
F_105 ( V_352 ) ;
return error ;
}
STATIC int
F_206 (
T_3 * V_2 ,
T_14 * V_305 )
{
T_17 * V_132 = V_2 -> V_7 ;
struct V_308 * V_309 ;
unsigned long V_382 , V_383 ;
unsigned long V_301 ;
int V_384 ;
T_3 * * V_385 ;
T_3 * V_386 ;
int V_387 ;
int V_388 = 0 ;
int V_389 ;
int V_53 ;
V_309 = F_161 ( V_132 , F_145 ( V_132 , V_2 -> V_69 ) ) ;
V_301 = V_132 -> V_390 >> V_132 -> V_8 . V_391 ;
V_384 = V_301 * sizeof( T_3 * ) ;
V_385 = F_207 ( V_384 , V_392 | V_393 ) ;
if ( ! V_385 )
goto V_394;
V_383 = ~ ( ( ( V_132 -> V_390 >> V_132 -> V_8 . V_391 ) ) - 1 ) ;
V_382 = F_147 ( V_132 , V_2 -> V_69 ) & V_383 ;
F_169 () ;
V_387 = F_208 ( & V_309 -> V_334 , ( void * * ) V_385 ,
V_382 , V_301 ) ;
if ( V_387 == 0 )
goto V_395;
for ( V_53 = 0 ; V_53 < V_387 ; V_53 ++ ) {
V_386 = V_385 [ V_53 ] ;
if ( V_386 == V_2 )
continue;
F_172 ( & V_2 -> V_335 ) ;
if ( ! V_2 -> V_69 ||
( F_147 ( V_132 , V_386 -> V_69 ) & V_383 ) != V_382 ) {
F_174 ( & V_2 -> V_335 ) ;
continue;
}
F_174 ( & V_2 -> V_335 ) ;
if ( F_176 ( V_386 ) && F_188 ( V_386 ) == 0 )
continue;
if ( ! F_12 ( V_386 , V_11 ) )
continue;
if ( ! F_37 ( V_386 ) ) {
F_18 ( V_386 , V_11 ) ;
continue;
}
if ( F_188 ( V_386 ) ) {
F_177 ( V_386 ) ;
F_18 ( V_386 , V_11 ) ;
continue;
}
if ( ! F_176 ( V_386 ) ) {
int error ;
error = F_209 ( V_386 , V_305 ) ;
if ( error ) {
F_18 ( V_386 , V_11 ) ;
goto V_396;
}
V_388 ++ ;
} else {
F_177 ( V_386 ) ;
}
F_18 ( V_386 , V_11 ) ;
}
if ( V_388 ) {
F_210 ( V_132 , V_397 ) ;
F_211 ( V_132 , V_398 , V_388 ) ;
}
V_395:
F_171 () ;
F_51 ( V_385 ) ;
V_394:
F_181 ( V_309 ) ;
return 0 ;
V_396:
F_171 () ;
V_389 = ( V_305 -> V_399 & V_400 ) ;
if ( V_389 )
F_72 ( V_305 ) ;
F_137 ( V_132 , V_401 ) ;
if ( ! V_389 ) {
if ( V_305 -> V_402 ) {
F_212 ( V_305 ) ;
F_213 ( V_305 ) ;
F_214 ( V_305 , - V_120 ) ;
F_215 ( V_305 ) ;
} else {
F_213 ( V_305 ) ;
F_72 ( V_305 ) ;
}
}
F_216 ( V_386 , false ) ;
F_51 ( V_385 ) ;
F_181 ( V_309 ) ;
return - V_403 ;
}
int
F_217 (
struct V_1 * V_2 ,
struct V_404 * * V_405 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_404 * V_305 ;
struct V_112 * V_113 ;
int error ;
F_210 ( V_132 , V_406 ) ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_149 > F_218 ( V_2 , V_264 ) ) ;
* V_405 = NULL ;
F_189 ( V_2 ) ;
if ( F_128 ( V_2 , V_331 ) ) {
F_177 ( V_2 ) ;
return 0 ;
}
if ( F_48 ( V_132 ) ) {
error = - V_120 ;
goto V_407;
}
error = F_150 ( V_132 , NULL , & V_2 -> V_284 , & V_113 , & V_305 , V_408 ,
0 ) ;
if ( error || ! V_305 ) {
F_177 ( V_2 ) ;
return error ;
}
error = F_209 ( V_2 , V_305 ) ;
if ( error )
goto V_409;
if ( F_219 ( V_305 ) )
F_220 ( V_132 , 0 ) ;
error = F_206 ( V_2 , V_305 ) ;
if ( error )
goto V_396;
* V_405 = V_305 ;
return 0 ;
V_409:
F_72 ( V_305 ) ;
F_137 ( V_132 , V_401 ) ;
V_396:
error = - V_403 ;
V_407:
F_216 ( V_2 , false ) ;
return error ;
}
STATIC int
F_209 (
struct V_1 * V_2 ,
struct V_404 * V_305 )
{
struct V_410 * V_306 = V_2 -> V_58 ;
struct V_112 * V_113 ;
struct V_131 * V_132 = V_2 -> V_7 ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_149 > F_218 ( V_2 , V_264 ) ) ;
ASSERT ( V_306 != NULL && V_306 -> V_337 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_139 > 1 ) ;
V_113 = F_221 ( V_305 , V_2 -> V_284 . V_286 ) ;
if ( F_222 ( V_113 -> V_411 != F_223 ( V_412 ) ,
V_132 , V_413 , V_414 ) ) {
F_224 ( V_132 , V_415 ,
L_9 ,
V_269 , V_2 -> V_69 , F_43 ( V_113 -> V_411 ) , V_113 ) ;
goto V_409;
}
if ( F_222 ( V_2 -> V_3 . V_411 != V_412 ,
V_132 , V_416 , V_417 ) ) {
F_224 ( V_132 , V_415 ,
L_10 ,
V_269 , V_2 -> V_69 , V_2 , V_2 -> V_3 . V_411 ) ;
goto V_409;
}
if ( F_65 ( V_2 -> V_3 . V_140 ) ) {
if ( F_222 (
( V_2 -> V_3 . V_12 != V_188 ) &&
( V_2 -> V_3 . V_12 != V_13 ) ,
V_132 , V_418 , V_419 ) ) {
F_224 ( V_132 , V_415 ,
L_11 ,
V_269 , V_2 -> V_69 , V_2 ) ;
goto V_409;
}
} else if ( F_60 ( V_2 -> V_3 . V_140 ) ) {
if ( F_222 (
( V_2 -> V_3 . V_12 != V_188 ) &&
( V_2 -> V_3 . V_12 != V_13 ) &&
( V_2 -> V_3 . V_12 != V_420 ) ,
V_132 , V_421 , V_422 ) ) {
F_224 ( V_132 , V_415 ,
L_12 ,
V_269 , V_2 -> V_69 , V_2 ) ;
goto V_409;
}
}
if ( F_222 ( V_2 -> V_3 . V_149 + V_2 -> V_3 . V_193 >
V_2 -> V_3 . V_150 , V_132 , V_423 ,
V_424 ) ) {
F_224 ( V_132 , V_415 ,
L_13
L_14 ,
V_269 , V_2 -> V_69 ,
V_2 -> V_3 . V_149 + V_2 -> V_3 . V_193 ,
V_2 -> V_3 . V_150 , V_2 ) ;
goto V_409;
}
if ( F_222 ( V_2 -> V_3 . V_274 > V_132 -> V_8 . V_425 ,
V_132 , V_426 , V_427 ) ) {
F_224 ( V_132 , V_415 ,
L_15 ,
V_269 , V_2 -> V_69 , V_2 -> V_3 . V_274 , V_2 ) ;
goto V_409;
}
if ( V_2 -> V_3 . V_139 < 3 )
V_2 -> V_3 . V_428 ++ ;
F_225 ( V_113 , & V_2 -> V_3 ) ;
if ( V_2 -> V_3 . V_428 == V_429 )
V_2 -> V_3 . V_428 = 0 ;
F_226 ( V_2 , V_113 , V_306 , V_264 ) ;
if ( F_41 ( V_2 ) )
F_226 ( V_2 , V_113 , V_306 , V_430 ) ;
F_155 ( V_132 , V_305 ) ;
V_306 -> V_336 = V_306 -> V_337 ;
V_306 -> V_337 = 0 ;
V_306 -> V_338 = 0 ;
V_306 -> V_323 = 1 ;
F_168 ( V_132 -> V_326 , & V_306 -> V_327 ,
& V_306 -> V_328 . V_329 ) ;
F_178 ( V_305 , V_431 , & V_306 -> V_328 ) ;
if ( V_2 -> V_3 . V_139 == 3 )
V_113 -> V_167 = F_227 ( V_306 -> V_328 . V_329 ) ;
F_152 ( V_132 , V_113 ) ;
ASSERT ( V_305 -> V_320 != NULL ) ;
ASSERT ( V_305 -> V_402 != NULL ) ;
return 0 ;
V_409:
return - V_403 ;
}
