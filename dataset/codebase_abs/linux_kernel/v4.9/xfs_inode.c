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
T_1
F_3 (
struct V_1 * V_2 )
{
T_1 V_10 , V_11 ;
V_10 = 0 ;
if ( V_2 -> V_3 . V_12 & V_13 )
V_10 = V_2 -> V_3 . V_14 ;
V_11 = F_1 ( V_2 ) ;
V_10 = F_4 ( V_10 , V_11 ) ;
if ( V_10 == 0 )
return V_15 ;
return V_10 ;
}
T_2
F_5 (
struct V_1 * V_2 )
{
T_2 V_16 = V_17 ;
if ( V_2 -> V_3 . V_18 == V_19 &&
( V_2 -> V_20 . V_21 & V_22 ) == 0 )
V_16 = V_23 ;
F_6 ( V_2 , V_16 ) ;
return V_16 ;
}
T_2
F_7 (
struct V_1 * V_2 )
{
T_2 V_16 = V_17 ;
if ( V_2 -> V_3 . V_24 == V_19 &&
( V_2 -> V_25 -> V_21 & V_22 ) == 0 )
V_16 = V_23 ;
F_6 ( V_2 , V_16 ) ;
return V_16 ;
}
void
F_6 (
T_3 * V_2 ,
T_2 V_26 )
{
F_8 ( V_2 , V_26 , V_27 ) ;
ASSERT ( ( V_26 & ( V_28 | V_29 ) ) !=
( V_28 | V_29 ) ) ;
ASSERT ( ( V_26 & ( V_30 | V_31 ) ) !=
( V_30 | V_31 ) ) ;
ASSERT ( ( V_26 & ( V_17 | V_23 ) ) !=
( V_17 | V_23 ) ) ;
ASSERT ( ( V_26 & ~ ( V_32 | V_33 ) ) == 0 ) ;
if ( V_26 & V_29 )
F_9 ( & V_2 -> V_34 , F_10 ( V_26 ) ) ;
else if ( V_26 & V_28 )
F_11 ( & V_2 -> V_34 , F_10 ( V_26 ) ) ;
if ( V_26 & V_31 )
F_9 ( & V_2 -> V_35 , F_12 ( V_26 ) ) ;
else if ( V_26 & V_30 )
F_11 ( & V_2 -> V_35 , F_12 ( V_26 ) ) ;
if ( V_26 & V_23 )
F_9 ( & V_2 -> V_36 , F_13 ( V_26 ) ) ;
else if ( V_26 & V_17 )
F_11 ( & V_2 -> V_36 , F_13 ( V_26 ) ) ;
}
int
F_14 (
T_3 * V_2 ,
T_2 V_26 )
{
F_15 ( V_2 , V_26 , V_27 ) ;
ASSERT ( ( V_26 & ( V_28 | V_29 ) ) !=
( V_28 | V_29 ) ) ;
ASSERT ( ( V_26 & ( V_30 | V_31 ) ) !=
( V_30 | V_31 ) ) ;
ASSERT ( ( V_26 & ( V_17 | V_23 ) ) !=
( V_17 | V_23 ) ) ;
ASSERT ( ( V_26 & ~ ( V_32 | V_33 ) ) == 0 ) ;
if ( V_26 & V_29 ) {
if ( ! F_16 ( & V_2 -> V_34 ) )
goto V_37;
} else if ( V_26 & V_28 ) {
if ( ! F_17 ( & V_2 -> V_34 ) )
goto V_37;
}
if ( V_26 & V_31 ) {
if ( ! F_16 ( & V_2 -> V_35 ) )
goto V_38;
} else if ( V_26 & V_30 ) {
if ( ! F_17 ( & V_2 -> V_35 ) )
goto V_38;
}
if ( V_26 & V_23 ) {
if ( ! F_16 ( & V_2 -> V_36 ) )
goto V_39;
} else if ( V_26 & V_17 ) {
if ( ! F_17 ( & V_2 -> V_36 ) )
goto V_39;
}
return 1 ;
V_39:
if ( V_26 & V_31 )
F_18 ( & V_2 -> V_35 ) ;
else if ( V_26 & V_30 )
F_19 ( & V_2 -> V_35 ) ;
V_38:
if ( V_26 & V_29 )
F_18 ( & V_2 -> V_34 ) ;
else if ( V_26 & V_28 )
F_19 ( & V_2 -> V_34 ) ;
V_37:
return 0 ;
}
void
F_20 (
T_3 * V_2 ,
T_2 V_26 )
{
ASSERT ( ( V_26 & ( V_28 | V_29 ) ) !=
( V_28 | V_29 ) ) ;
ASSERT ( ( V_26 & ( V_30 | V_31 ) ) !=
( V_30 | V_31 ) ) ;
ASSERT ( ( V_26 & ( V_17 | V_23 ) ) !=
( V_17 | V_23 ) ) ;
ASSERT ( ( V_26 & ~ ( V_32 | V_33 ) ) == 0 ) ;
ASSERT ( V_26 != 0 ) ;
if ( V_26 & V_29 )
F_18 ( & V_2 -> V_34 ) ;
else if ( V_26 & V_28 )
F_19 ( & V_2 -> V_34 ) ;
if ( V_26 & V_31 )
F_18 ( & V_2 -> V_35 ) ;
else if ( V_26 & V_30 )
F_19 ( & V_2 -> V_35 ) ;
if ( V_26 & V_23 )
F_18 ( & V_2 -> V_36 ) ;
else if ( V_26 & V_17 )
F_19 ( & V_2 -> V_36 ) ;
F_21 ( V_2 , V_26 , V_27 ) ;
}
void
F_22 (
T_3 * V_2 ,
T_2 V_26 )
{
ASSERT ( V_26 & ( V_29 | V_31 | V_23 ) ) ;
ASSERT ( ( V_26 &
~ ( V_29 | V_31 | V_23 ) ) == 0 ) ;
if ( V_26 & V_23 )
F_23 ( & V_2 -> V_36 ) ;
if ( V_26 & V_31 )
F_23 ( & V_2 -> V_35 ) ;
if ( V_26 & V_29 )
F_23 ( & V_2 -> V_34 ) ;
F_24 ( V_2 , V_26 , V_27 ) ;
}
int
F_25 (
T_3 * V_2 ,
T_2 V_26 )
{
if ( V_26 & ( V_23 | V_17 ) ) {
if ( ! ( V_26 & V_17 ) )
return ! ! V_2 -> V_36 . V_40 ;
return F_26 ( & V_2 -> V_36 . V_41 ) ;
}
if ( V_26 & ( V_31 | V_30 ) ) {
if ( ! ( V_26 & V_30 ) )
return ! ! V_2 -> V_35 . V_40 ;
return F_26 ( & V_2 -> V_35 . V_41 ) ;
}
if ( V_26 & ( V_29 | V_28 ) ) {
if ( ! ( V_26 & V_28 ) )
return ! ! V_2 -> V_34 . V_40 ;
return F_26 ( & V_2 -> V_34 . V_41 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
static bool
F_27 (
int V_42 )
{
return V_42 < V_43 ;
}
static inline int
F_28 ( int V_16 , int V_42 )
{
int V_44 = 0 ;
ASSERT ( ! ( V_16 & ( V_45 | V_46 |
V_47 ) ) ) ;
ASSERT ( F_27 ( V_42 ) ) ;
if ( V_16 & ( V_28 | V_29 ) ) {
ASSERT ( V_42 <= V_48 ) ;
ASSERT ( F_27 ( V_42 +
V_49 ) ) ;
V_44 += V_42 << V_50 ;
if ( V_16 & V_51 )
V_44 += V_49 << V_50 ;
}
if ( V_16 & ( V_30 | V_31 ) ) {
ASSERT ( V_42 <= V_52 ) ;
V_44 += V_42 << V_53 ;
}
if ( V_16 & ( V_17 | V_23 ) ) {
ASSERT ( V_42 <= V_54 ) ;
V_44 += V_42 << V_55 ;
}
return ( V_16 & ~ V_33 ) | V_44 ;
}
static void
F_29 (
T_3 * * V_56 ,
int V_57 ,
T_2 V_16 )
{
int V_58 = 0 , V_59 , V_60 , V_61 ;
T_4 * V_62 ;
ASSERT ( V_56 && V_57 >= 2 && V_57 <= 5 ) ;
ASSERT ( V_16 & ( V_29 | V_31 |
V_23 ) ) ;
ASSERT ( ! ( V_16 & ( V_28 | V_30 |
V_17 ) ) ) ;
ASSERT ( ! ( V_16 & V_29 ) ||
V_57 <= V_48 + 1 ) ;
ASSERT ( ! ( V_16 & V_31 ) ||
V_57 <= V_52 + 1 ) ;
ASSERT ( ! ( V_16 & V_23 ) ||
V_57 <= V_54 + 1 ) ;
if ( V_16 & V_29 ) {
ASSERT ( ! ( V_16 & ( V_31 | V_23 ) ) ) ;
} else if ( V_16 & V_31 )
ASSERT ( ! ( V_16 & V_23 ) ) ;
V_61 = 0 ;
V_59 = 0 ;
V_63:
for (; V_59 < V_57 ; V_59 ++ ) {
ASSERT ( V_56 [ V_59 ] ) ;
if ( V_59 && ( V_56 [ V_59 ] == V_56 [ V_59 - 1 ] ) )
continue;
if ( ! V_61 ) {
for ( V_60 = ( V_59 - 1 ) ; V_60 >= 0 && ! V_61 ; V_60 -- ) {
V_62 = ( T_4 * ) V_56 [ V_60 ] -> V_64 ;
if ( V_62 && ( V_62 -> V_65 & V_66 ) )
V_61 ++ ;
}
}
if ( ! V_61 ) {
F_6 ( V_56 [ V_59 ] , F_28 ( V_16 , V_59 ) ) ;
continue;
}
ASSERT ( V_59 != 0 ) ;
if ( F_14 ( V_56 [ V_59 ] , F_28 ( V_16 , V_59 ) ) )
continue;
V_58 ++ ;
for ( V_60 = V_59 - 1 ; V_60 >= 0 ; V_60 -- ) {
if ( V_60 != ( V_59 - 1 ) && V_56 [ V_60 ] == V_56 [ V_60 + 1 ] )
continue;
F_20 ( V_56 [ V_60 ] , V_16 ) ;
}
if ( ( V_58 % 5 ) == 0 ) {
F_30 ( 1 ) ;
#ifdef F_31
V_67 ++ ;
#endif
}
V_59 = 0 ;
V_61 = 0 ;
goto V_63;
}
#ifdef F_31
if ( V_58 ) {
if ( V_58 < 5 ) V_68 ++ ;
else if ( V_58 < 100 ) V_69 ++ ;
else V_70 ++ ;
} else {
V_71 ++ ;
}
#endif
}
void
F_32 (
T_3 * V_72 ,
T_3 * V_73 ,
T_2 V_16 )
{
T_3 * V_74 ;
int V_58 = 0 ;
T_4 * V_62 ;
if ( V_16 & ( V_28 | V_29 ) ) {
ASSERT ( ! ( V_16 & ( V_30 | V_31 ) ) ) ;
ASSERT ( ! ( V_16 & ( V_17 | V_23 ) ) ) ;
} else if ( V_16 & ( V_30 | V_31 ) )
ASSERT ( ! ( V_16 & ( V_17 | V_23 ) ) ) ;
ASSERT ( V_72 -> V_75 != V_73 -> V_75 ) ;
if ( V_72 -> V_75 > V_73 -> V_75 ) {
V_74 = V_72 ;
V_72 = V_73 ;
V_73 = V_74 ;
}
V_63:
F_6 ( V_72 , F_28 ( V_16 , 0 ) ) ;
V_62 = ( T_4 * ) V_72 -> V_64 ;
if ( V_62 && ( V_62 -> V_65 & V_66 ) ) {
if ( ! F_14 ( V_73 , F_28 ( V_16 , 1 ) ) ) {
F_20 ( V_72 , V_16 ) ;
if ( ( ++ V_58 % 5 ) == 0 )
F_30 ( 1 ) ;
goto V_63;
}
} else {
F_6 ( V_73 , F_28 ( V_16 , 1 ) ) ;
}
}
void
F_33 (
struct V_1 * V_2 )
{
T_5 * V_76 = F_34 ( & V_2 -> V_77 , V_78 ) ;
F_35 ( V_79 , & V_2 -> V_77 , V_78 ) ;
do {
F_36 ( V_76 , & V_79 . V_79 , V_80 ) ;
if ( F_37 ( V_2 ) )
F_38 () ;
} while ( ! F_39 ( V_2 ) );
F_40 ( V_76 , & V_79 . V_79 ) ;
}
STATIC T_2
F_41 (
T_6 V_4 ,
T_7 V_12 ,
bool V_81 )
{
T_2 V_82 = 0 ;
if ( V_4 & V_83 ) {
if ( V_4 & V_84 )
V_82 |= V_85 ;
if ( V_4 & V_86 )
V_82 |= V_87 ;
if ( V_4 & V_88 )
V_82 |= V_89 ;
if ( V_4 & V_90 )
V_82 |= V_91 ;
if ( V_4 & V_92 )
V_82 |= V_93 ;
if ( V_4 & V_94 )
V_82 |= V_95 ;
if ( V_4 & V_96 )
V_82 |= V_97 ;
if ( V_4 & V_98 )
V_82 |= V_99 ;
if ( V_4 & V_100 )
V_82 |= V_101 ;
if ( V_4 & V_102 )
V_82 |= V_103 ;
if ( V_4 & V_5 )
V_82 |= V_104 ;
if ( V_4 & V_105 )
V_82 |= V_106 ;
if ( V_4 & V_107 )
V_82 |= V_108 ;
if ( V_4 & V_109 )
V_82 |= V_110 ;
}
if ( V_12 & V_111 ) {
if ( V_12 & V_112 )
V_82 |= V_113 ;
if ( V_12 & V_13 )
V_82 |= V_114 ;
}
if ( V_81 )
V_82 |= V_115 ;
return V_82 ;
}
T_2
F_42 (
struct V_1 * V_2 )
{
struct V_116 * V_117 = & V_2 -> V_3 ;
return F_41 ( V_117 -> V_4 , V_117 -> V_12 , F_43 ( V_2 ) ) ;
}
int
F_44 (
T_3 * V_118 ,
struct V_119 * V_120 ,
T_3 * * V_121 ,
struct V_119 * V_122 )
{
T_8 V_123 ;
int error ;
F_45 ( V_118 , V_120 ) ;
if ( F_46 ( V_118 -> V_7 ) )
return - V_124 ;
F_6 ( V_118 , V_28 ) ;
error = F_47 ( NULL , V_118 , V_120 , & V_123 , V_122 ) ;
if ( error )
goto V_125;
error = F_48 ( V_118 -> V_7 , NULL , V_123 , 0 , 0 , V_121 ) ;
if ( error )
goto V_126;
F_20 ( V_118 , V_28 ) ;
return 0 ;
V_126:
if ( V_122 )
F_49 ( V_122 -> V_120 ) ;
V_125:
F_20 ( V_118 , V_28 ) ;
* V_121 = NULL ;
return error ;
}
static int
F_50 (
T_9 * V_127 ,
T_3 * V_128 ,
T_10 V_129 ,
T_11 V_130 ,
T_12 V_131 ,
T_13 V_132 ,
int V_133 ,
T_14 * * V_134 ,
T_3 * * V_121 )
{
struct V_135 * V_136 = V_127 -> V_137 ;
T_8 V_138 ;
T_3 * V_2 ;
T_2 V_82 ;
int error ;
struct V_139 V_140 ;
struct V_141 * V_141 ;
error = F_51 ( V_127 , V_128 ? V_128 -> V_75 : 0 , V_129 , V_133 ,
V_134 , & V_138 ) ;
if ( error )
return error ;
if ( * V_134 || V_138 == V_142 ) {
* V_121 = NULL ;
return 0 ;
}
ASSERT ( * V_134 == NULL ) ;
error = F_48 ( V_136 , V_127 , V_138 , V_143 ,
V_23 , & V_2 ) ;
if ( error )
return error ;
ASSERT ( V_2 != NULL ) ;
V_141 = F_52 ( V_2 ) ;
if ( V_2 -> V_3 . V_144 == 1 )
V_2 -> V_3 . V_144 = 2 ;
V_141 -> V_145 = V_129 ;
F_53 ( V_141 , V_130 ) ;
V_2 -> V_3 . V_146 = F_54 ( F_55 () ) ;
V_2 -> V_3 . V_147 = F_56 ( F_57 () ) ;
F_58 ( V_2 , V_132 ) ;
if ( V_128 && F_59 ( V_128 ) ) {
V_2 -> V_3 . V_147 = V_128 -> V_3 . V_147 ;
if ( ( F_52 ( V_128 ) -> V_145 & V_148 ) && F_60 ( V_129 ) )
V_141 -> V_145 |= V_148 ;
}
if ( ( V_149 ) &&
( V_141 -> V_145 & V_148 ) &&
( ! F_61 ( F_62 ( V_2 -> V_3 . V_147 ) ) ) )
V_141 -> V_145 &= ~ V_148 ;
V_2 -> V_3 . V_150 = 0 ;
V_2 -> V_3 . V_151 = 0 ;
ASSERT ( V_2 -> V_3 . V_152 == 0 ) ;
V_140 = F_63 ( V_141 ) ;
V_141 -> V_153 = V_140 ;
V_141 -> V_154 = V_140 ;
V_141 -> V_155 = V_140 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_156 = 0 ;
V_2 -> V_3 . V_157 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( V_2 -> V_3 . V_144 == 3 ) {
V_141 -> V_158 = 1 ;
V_2 -> V_3 . V_12 = 0 ;
V_2 -> V_3 . V_14 = 0 ;
V_2 -> V_3 . V_159 . V_160 = ( V_161 ) V_140 . V_162 ;
V_2 -> V_3 . V_159 . V_163 = ( V_161 ) V_140 . V_164 ;
}
V_82 = V_165 ;
switch ( V_129 & V_166 ) {
case V_167 :
case V_168 :
case V_169 :
case V_170 :
V_2 -> V_3 . V_18 = V_171 ;
V_2 -> V_20 . V_172 . V_173 = V_131 ;
V_2 -> V_20 . V_21 = 0 ;
V_82 |= V_174 ;
break;
case V_175 :
case V_176 :
if ( V_128 && ( V_128 -> V_3 . V_4 & V_83 ) ) {
T_7 V_12 = 0 ;
T_2 V_4 = 0 ;
if ( F_60 ( V_129 ) ) {
if ( V_128 -> V_3 . V_4 & V_98 )
V_4 |= V_98 ;
if ( V_128 -> V_3 . V_4 & V_105 ) {
V_4 |= V_105 ;
V_2 -> V_3 . V_6 = V_128 -> V_3 . V_6 ;
}
if ( V_128 -> V_3 . V_4 & V_100 )
V_4 |= V_100 ;
} else if ( F_64 ( V_129 ) ) {
if ( V_128 -> V_3 . V_4 & V_98 )
V_4 |= V_84 ;
if ( V_128 -> V_3 . V_4 & V_105 ) {
V_4 |= V_5 ;
V_2 -> V_3 . V_6 = V_128 -> V_3 . V_6 ;
}
}
if ( ( V_128 -> V_3 . V_4 & V_94 ) &&
V_177 )
V_4 |= V_94 ;
if ( ( V_128 -> V_3 . V_4 & V_96 ) &&
V_178 )
V_4 |= V_96 ;
if ( ( V_128 -> V_3 . V_4 & V_92 ) &&
V_179 )
V_4 |= V_92 ;
if ( ( V_128 -> V_3 . V_4 & V_102 ) &&
V_180 )
V_4 |= V_102 ;
if ( ( V_128 -> V_3 . V_4 & V_107 ) &&
V_181 )
V_4 |= V_107 ;
if ( V_128 -> V_3 . V_4 & V_109 )
V_4 |= V_109 ;
if ( V_128 -> V_3 . V_12 & V_112 )
V_12 |= V_112 ;
V_2 -> V_3 . V_4 |= V_4 ;
V_2 -> V_3 . V_12 |= V_12 ;
}
if ( V_128 &&
( V_128 -> V_3 . V_12 & V_111 ) &&
V_128 -> V_3 . V_144 == 3 &&
V_2 -> V_3 . V_144 == 3 ) {
if ( V_128 -> V_3 . V_12 & V_13 ) {
V_2 -> V_3 . V_12 |= V_13 ;
V_2 -> V_3 . V_14 = V_128 -> V_3 . V_14 ;
}
}
case V_182 :
V_2 -> V_3 . V_18 = V_183 ;
V_2 -> V_20 . V_21 = V_22 ;
V_2 -> V_20 . V_184 = V_2 -> V_20 . V_185 = 0 ;
V_2 -> V_20 . V_186 . V_187 = NULL ;
break;
default:
ASSERT ( 0 ) ;
}
V_2 -> V_3 . V_24 = V_183 ;
V_2 -> V_3 . V_188 = 0 ;
F_65 ( V_127 , V_2 , V_23 ) ;
F_66 ( V_127 , V_2 , V_82 ) ;
F_67 ( V_2 ) ;
* V_121 = V_2 ;
return 0 ;
}
int
F_68 (
T_9 * * V_189 ,
T_3 * V_118 ,
T_10 V_129 ,
T_11 V_130 ,
T_12 V_131 ,
T_13 V_132 ,
int V_133 ,
T_3 * * V_121 ,
int * V_190 )
{
T_9 * V_127 ;
T_3 * V_2 ;
T_14 * V_134 = NULL ;
int V_191 ;
void * V_192 ;
T_2 V_193 ;
V_127 = * V_189 ;
ASSERT ( V_127 -> V_194 & V_195 ) ;
V_191 = F_50 ( V_127 , V_118 , V_129 , V_130 , V_131 , V_132 , V_133 ,
& V_134 , & V_2 ) ;
if ( V_191 ) {
* V_121 = NULL ;
return V_191 ;
}
if ( ! V_134 && ! V_2 ) {
* V_121 = NULL ;
return - V_196 ;
}
if ( V_134 ) {
F_69 ( V_127 , V_134 ) ;
V_192 = NULL ;
V_193 = 0 ;
if ( V_127 -> V_197 ) {
V_192 = ( void * ) V_127 -> V_197 ;
V_127 -> V_197 = NULL ;
V_193 = V_127 -> V_194 & V_198 ;
V_127 -> V_194 &= ~ ( V_198 ) ;
}
V_191 = F_70 ( & V_127 , NULL ) ;
if ( V_190 != NULL )
* V_190 = 1 ;
if ( V_192 ) {
V_127 -> V_197 = V_192 ;
V_127 -> V_194 |= V_193 ;
}
if ( V_191 ) {
F_71 ( V_134 ) ;
* V_189 = V_127 ;
* V_121 = NULL ;
return V_191 ;
}
F_72 ( V_127 , V_134 ) ;
V_191 = F_50 ( V_127 , V_118 , V_129 , V_130 , V_131 , V_132 ,
V_133 , & V_134 , & V_2 ) ;
if ( V_191 ) {
* V_189 = V_127 ;
* V_121 = NULL ;
return V_191 ;
}
ASSERT ( ! V_134 && V_2 ) ;
} else {
if ( V_190 != NULL )
* V_190 = 0 ;
}
* V_121 = V_2 ;
* V_189 = V_127 ;
return 0 ;
}
static int
F_73 (
T_9 * V_127 ,
T_3 * V_2 )
{
F_74 ( V_127 , V_2 , V_199 ) ;
F_75 ( F_52 ( V_2 ) ) ;
F_66 ( V_127 , V_2 , V_165 ) ;
if ( F_52 ( V_2 ) -> V_200 )
return 0 ;
return F_76 ( V_127 , V_2 ) ;
}
static int
F_77 (
T_9 * V_127 ,
T_3 * V_2 )
{
F_74 ( V_127 , V_2 , V_199 ) ;
ASSERT ( V_2 -> V_3 . V_144 > 1 ) ;
F_78 ( F_52 ( V_2 ) ) ;
F_66 ( V_127 , V_2 , V_165 ) ;
return 0 ;
}
int
F_79 (
T_3 * V_118 ,
struct V_119 * V_120 ,
T_10 V_129 ,
T_12 V_131 ,
T_3 * * V_121 )
{
int V_201 = F_60 ( V_129 ) ;
struct V_135 * V_136 = V_118 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_202 * V_127 = NULL ;
int error ;
struct V_203 V_204 ;
T_15 V_205 ;
bool V_206 = false ;
T_13 V_132 ;
struct V_207 * V_208 = NULL ;
struct V_207 * V_209 = NULL ;
struct V_207 * V_210 = NULL ;
struct V_211 * V_212 ;
T_2 V_213 ;
F_80 ( V_118 , V_120 ) ;
if ( F_46 ( V_136 ) )
return - V_124 ;
V_132 = F_81 ( V_118 ) ;
error = F_82 ( V_118 , F_54 ( F_55 () ) ,
F_56 ( F_57 () ) , V_132 ,
V_214 | V_215 ,
& V_208 , & V_209 , & V_210 ) ;
if ( error )
return error ;
if ( V_201 ) {
V_131 = 0 ;
V_213 = F_83 ( V_136 , V_120 -> V_216 ) ;
V_212 = & F_84 ( V_136 ) -> V_217 ;
} else {
V_213 = F_85 ( V_136 , V_120 -> V_216 ) ;
V_212 = & F_84 ( V_136 ) -> V_218 ;
}
error = F_86 ( V_136 , V_212 , V_213 , 0 , 0 , & V_127 ) ;
if ( error == - V_196 ) {
F_87 ( V_136 ) ;
error = F_86 ( V_136 , V_212 , V_213 , 0 , 0 , & V_127 ) ;
}
if ( error == - V_196 ) {
V_213 = 0 ;
error = F_86 ( V_136 , V_212 , 0 , 0 , 0 , & V_127 ) ;
}
if ( error )
goto V_219;
F_6 ( V_118 , V_29 | V_23 |
V_51 | V_45 ) ;
V_206 = true ;
F_88 ( & V_204 , & V_205 ) ;
error = F_89 ( V_127 , V_136 , V_208 , V_209 ,
V_210 , V_213 , 1 , 0 ) ;
if ( error )
goto V_220;
if ( ! V_213 ) {
error = F_90 ( V_127 , V_118 , V_120 ) ;
if ( error )
goto V_220;
}
error = F_68 ( & V_127 , V_118 , V_129 , V_201 ? 2 : 1 , V_131 ,
V_132 , V_213 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_220;
F_65 ( V_127 , V_118 , V_29 | V_23 ) ;
V_206 = false ;
error = F_91 ( V_127 , V_118 , V_120 , V_2 -> V_75 ,
& V_205 , & V_204 , V_213 ?
V_213 - F_92 ( V_136 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_196 ) ;
goto V_220;
}
F_74 ( V_127 , V_118 , V_221 | V_199 ) ;
F_66 ( V_127 , V_118 , V_165 ) ;
if ( V_201 ) {
error = F_93 ( V_127 , V_2 , V_118 ) ;
if ( error )
goto V_222;
error = F_77 ( V_127 , V_118 ) ;
if ( error )
goto V_222;
}
if ( V_136 -> V_223 & ( V_224 | V_225 ) )
F_94 ( V_127 ) ;
F_95 ( V_127 , V_2 , V_208 , V_209 , V_210 ) ;
error = F_96 ( & V_127 , & V_204 , NULL ) ;
if ( error )
goto V_222;
error = F_97 ( V_127 ) ;
if ( error )
goto V_219;
F_98 ( V_208 ) ;
F_98 ( V_209 ) ;
F_98 ( V_210 ) ;
* V_121 = V_2 ;
return 0 ;
V_222:
F_99 ( & V_204 ) ;
V_220:
F_100 ( V_127 ) ;
V_219:
if ( V_2 ) {
F_101 ( V_2 ) ;
F_102 ( V_2 ) ;
}
F_98 ( V_208 ) ;
F_98 ( V_209 ) ;
F_98 ( V_210 ) ;
if ( V_206 )
F_20 ( V_118 , V_29 | V_23 ) ;
return error ;
}
int
F_103 (
struct V_1 * V_118 ,
struct V_226 * V_226 ,
T_10 V_129 ,
struct V_1 * * V_121 )
{
struct V_135 * V_136 = V_118 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_202 * V_127 = NULL ;
int error ;
T_13 V_132 ;
struct V_207 * V_208 = NULL ;
struct V_207 * V_209 = NULL ;
struct V_207 * V_210 = NULL ;
struct V_211 * V_212 ;
T_2 V_213 ;
if ( F_46 ( V_136 ) )
return - V_124 ;
V_132 = F_81 ( V_118 ) ;
error = F_82 ( V_118 , F_54 ( F_55 () ) ,
F_56 ( F_57 () ) , V_132 ,
V_214 | V_215 ,
& V_208 , & V_209 , & V_210 ) ;
if ( error )
return error ;
V_213 = F_92 ( V_136 ) ;
V_212 = & F_84 ( V_136 ) -> V_227 ;
error = F_86 ( V_136 , V_212 , V_213 , 0 , 0 , & V_127 ) ;
if ( error == - V_196 ) {
V_213 = 0 ;
error = F_86 ( V_136 , V_212 , 0 , 0 , 0 , & V_127 ) ;
}
if ( error )
goto V_219;
error = F_89 ( V_127 , V_136 , V_208 , V_209 ,
V_210 , V_213 , 1 , 0 ) ;
if ( error )
goto V_220;
error = F_68 ( & V_127 , V_118 , V_129 , 1 , 0 ,
V_132 , V_213 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_220;
if ( V_136 -> V_223 & V_224 )
F_94 ( V_127 ) ;
F_95 ( V_127 , V_2 , V_208 , V_209 , V_210 ) ;
error = F_76 ( V_127 , V_2 ) ;
if ( error )
goto V_220;
error = F_97 ( V_127 ) ;
if ( error )
goto V_219;
F_98 ( V_208 ) ;
F_98 ( V_209 ) ;
F_98 ( V_210 ) ;
* V_121 = V_2 ;
return 0 ;
V_220:
F_100 ( V_127 ) ;
V_219:
if ( V_2 ) {
F_101 ( V_2 ) ;
F_102 ( V_2 ) ;
}
F_98 ( V_208 ) ;
F_98 ( V_209 ) ;
F_98 ( V_210 ) ;
return error ;
}
int
F_104 (
T_3 * V_228 ,
T_3 * V_229 ,
struct V_119 * V_230 )
{
T_16 * V_136 = V_228 -> V_7 ;
T_9 * V_127 ;
int error ;
struct V_203 V_204 ;
T_15 V_205 ;
int V_213 ;
F_105 ( V_228 , V_230 ) ;
ASSERT ( ! F_60 ( F_52 ( V_229 ) -> V_145 ) ) ;
if ( F_46 ( V_136 ) )
return - V_124 ;
error = F_106 ( V_229 , 0 ) ;
if ( error )
goto V_231;
error = F_106 ( V_228 , 0 ) ;
if ( error )
goto V_231;
V_213 = F_107 ( V_136 , V_230 -> V_216 ) ;
error = F_86 ( V_136 , & F_84 ( V_136 ) -> V_232 , V_213 , 0 , 0 , & V_127 ) ;
if ( error == - V_196 ) {
V_213 = 0 ;
error = F_86 ( V_136 , & F_84 ( V_136 ) -> V_232 , 0 , 0 , 0 , & V_127 ) ;
}
if ( error )
goto V_231;
F_6 ( V_228 , V_29 | V_51 ) ;
F_32 ( V_229 , V_228 , V_23 ) ;
F_65 ( V_127 , V_229 , V_23 ) ;
F_65 ( V_127 , V_228 , V_29 | V_23 ) ;
if ( F_108 ( ( V_228 -> V_3 . V_4 & V_100 ) &&
( F_109 ( V_228 ) != F_109 ( V_229 ) ) ) ) {
error = - V_233 ;
goto V_234;
}
if ( ! V_213 ) {
error = F_90 ( V_127 , V_228 , V_230 ) ;
if ( error )
goto V_234;
}
F_88 ( & V_204 , & V_205 ) ;
if ( F_52 ( V_229 ) -> V_200 == 0 ) {
error = F_110 ( V_127 , V_229 ) ;
if ( error )
goto V_234;
}
error = F_91 ( V_127 , V_228 , V_230 , V_229 -> V_75 ,
& V_205 , & V_204 , V_213 ) ;
if ( error )
goto V_234;
F_74 ( V_127 , V_228 , V_221 | V_199 ) ;
F_66 ( V_127 , V_228 , V_165 ) ;
error = F_77 ( V_127 , V_229 ) ;
if ( error )
goto V_234;
if ( V_136 -> V_223 & ( V_224 | V_225 ) )
F_94 ( V_127 ) ;
error = F_96 ( & V_127 , & V_204 , NULL ) ;
if ( error ) {
F_99 ( & V_204 ) ;
goto V_234;
}
return F_97 ( V_127 ) ;
V_234:
F_100 ( V_127 ) ;
V_231:
return error ;
}
int
F_111 (
struct V_202 * * V_189 ,
struct V_1 * V_2 ,
int V_235 ,
T_17 V_236 )
{
struct V_135 * V_136 = V_2 -> V_7 ;
struct V_202 * V_127 = * V_189 ;
struct V_203 V_204 ;
T_15 V_205 ;
T_18 V_237 ;
T_18 V_238 ;
T_19 V_239 ;
int error = 0 ;
int V_240 = 0 ;
ASSERT ( F_25 ( V_2 , V_23 ) ) ;
ASSERT ( ! F_112 ( & F_52 ( V_2 ) -> V_241 ) ||
F_25 ( V_2 , V_29 ) ) ;
ASSERT ( V_236 <= F_113 ( V_2 ) ) ;
ASSERT ( V_127 -> V_194 & V_195 ) ;
ASSERT ( V_2 -> V_64 != NULL ) ;
ASSERT ( V_2 -> V_64 -> V_242 == 0 ) ;
ASSERT ( ! F_114 ( V_136 , V_2 ) ) ;
F_115 ( V_2 , V_236 ) ;
V_237 = F_116 ( V_136 , ( V_243 ) V_236 ) ;
V_238 = F_116 ( V_136 , V_136 -> V_244 -> V_245 ) ;
if ( V_237 == V_238 )
return 0 ;
ASSERT ( V_237 < V_238 ) ;
V_239 = V_238 - V_237 + 1 ;
while ( ! V_240 ) {
F_88 ( & V_204 , & V_205 ) ;
error = F_117 ( V_127 , V_2 ,
V_237 , V_239 ,
F_118 ( V_235 ) ,
V_246 ,
& V_205 , & V_204 ,
& V_240 ) ;
if ( error )
goto V_222;
error = F_96 ( & V_127 , & V_204 , V_2 ) ;
if ( error )
goto V_222;
error = F_70 ( & V_127 , V_2 ) ;
if ( error )
goto V_37;
}
error = F_119 ( V_2 , & V_127 , V_237 ,
V_238 ) ;
if ( error )
goto V_37;
if ( V_2 -> V_3 . V_152 == 0 && F_120 ( V_2 ) ) {
V_2 -> V_3 . V_12 &= ~ V_247 ;
F_121 ( V_2 ) ;
}
F_66 ( V_127 , V_2 , V_165 ) ;
F_122 ( V_2 , V_236 ) ;
V_37:
* V_189 = V_127 ;
return error ;
V_222:
F_99 ( & V_204 ) ;
goto V_37;
}
int
F_123 (
T_3 * V_2 )
{
T_16 * V_136 = V_2 -> V_7 ;
int error ;
if ( ! F_64 ( F_52 ( V_2 ) -> V_145 ) || ( F_52 ( V_2 ) -> V_145 == 0 ) )
return 0 ;
if ( V_136 -> V_223 & V_248 )
return 0 ;
if ( ! F_46 ( V_136 ) ) {
int V_249 ;
V_249 = F_124 ( V_2 , V_250 ) ;
if ( V_249 ) {
F_125 ( V_2 , V_251 ) ;
if ( V_2 -> V_252 > 0 ) {
error = F_126 ( F_52 ( V_2 ) -> V_253 ) ;
if ( error )
return error ;
}
}
}
if ( F_52 ( V_2 ) -> V_200 == 0 )
return 0 ;
if ( F_127 ( V_2 , false ) ) {
if ( F_128 ( V_2 , V_251 ) )
return 0 ;
error = F_129 ( V_136 , V_2 , true ) ;
if ( error && error != - V_254 )
return error ;
if ( V_2 -> V_252 )
F_130 ( V_2 , V_251 ) ;
}
return 0 ;
}
STATIC int
F_131 (
struct V_1 * V_2 )
{
struct V_135 * V_136 = V_2 -> V_7 ;
struct V_202 * V_127 ;
int error ;
error = F_86 ( V_136 , & F_84 ( V_136 ) -> V_255 , 0 , 0 , 0 , & V_127 ) ;
if ( error ) {
ASSERT ( F_46 ( V_136 ) ) ;
return error ;
}
F_6 ( V_2 , V_23 ) ;
F_65 ( V_127 , V_2 , 0 ) ;
V_2 -> V_3 . V_150 = 0 ;
F_66 ( V_127 , V_2 , V_165 ) ;
error = F_111 ( & V_127 , V_2 , V_256 , 0 ) ;
if ( error )
goto V_257;
ASSERT ( V_2 -> V_3 . V_151 == 0 ) ;
error = F_97 ( V_127 ) ;
if ( error )
goto V_258;
F_20 ( V_2 , V_23 ) ;
return 0 ;
V_257:
F_100 ( V_127 ) ;
V_258:
F_20 ( V_2 , V_23 ) ;
return error ;
}
STATIC int
F_132 (
struct V_1 * V_2 )
{
struct V_203 V_204 ;
T_15 V_205 ;
struct V_135 * V_136 = V_2 -> V_7 ;
struct V_202 * V_127 ;
int error ;
error = F_86 ( V_136 , & F_84 ( V_136 ) -> V_259 ,
F_133 ( V_136 ) , 0 , V_260 , & V_127 ) ;
if ( error ) {
if ( error == - V_196 ) {
F_134 ( V_136 ,
L_1
L_2 ) ;
} else {
ASSERT ( F_46 ( V_136 ) ) ;
}
return error ;
}
F_6 ( V_2 , V_23 ) ;
F_65 ( V_127 , V_2 , 0 ) ;
F_88 ( & V_204 , & V_205 ) ;
error = F_135 ( V_127 , V_2 , & V_204 ) ;
if ( error ) {
if ( ! F_46 ( V_136 ) ) {
F_136 ( V_136 , L_3 ,
V_261 , error ) ;
F_137 ( V_136 , V_262 ) ;
}
F_100 ( V_127 ) ;
F_20 ( V_2 , V_23 ) ;
return error ;
}
F_138 ( V_127 , V_2 , V_263 , - 1 ) ;
error = F_96 ( & V_127 , & V_204 , NULL ) ;
if ( error ) {
F_136 ( V_136 , L_4 ,
V_261 , error ) ;
F_99 ( & V_204 ) ;
}
error = F_97 ( V_127 ) ;
if ( error )
F_136 ( V_136 , L_5 ,
V_261 , error ) ;
F_20 ( V_2 , V_23 ) ;
return 0 ;
}
void
F_139 (
T_3 * V_2 )
{
struct V_135 * V_136 ;
int error ;
int V_264 = 0 ;
if ( F_52 ( V_2 ) -> V_145 == 0 ) {
ASSERT ( V_2 -> V_20 . V_185 == 0 ) ;
ASSERT ( V_2 -> V_20 . V_265 == 0 ) ;
return;
}
V_136 = V_2 -> V_7 ;
ASSERT ( ! F_128 ( V_2 , V_266 ) ) ;
if ( V_136 -> V_223 & V_248 )
return;
if ( F_52 ( V_2 ) -> V_200 != 0 ) {
if ( F_127 ( V_2 , true ) )
F_129 ( V_136 , V_2 , false ) ;
return;
}
if ( F_64 ( F_52 ( V_2 ) -> V_145 ) &&
( V_2 -> V_3 . V_150 != 0 || F_113 ( V_2 ) != 0 ||
V_2 -> V_3 . V_151 > 0 || V_2 -> V_252 > 0 ) )
V_264 = 1 ;
error = F_106 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_140 ( F_52 ( V_2 ) -> V_145 ) )
error = F_141 ( V_2 ) ;
else if ( V_264 )
error = F_131 ( V_2 ) ;
if ( error )
return;
if ( F_43 ( V_2 ) ) {
error = F_142 ( V_2 ) ;
if ( error )
return;
}
ASSERT ( ! V_2 -> V_25 ) ;
ASSERT ( V_2 -> V_3 . V_188 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_267 == 0 ) ;
error = F_132 ( V_2 ) ;
if ( error )
return;
F_143 ( V_2 ) ;
}
STATIC int
F_76 (
struct V_202 * V_127 ,
struct V_1 * V_2 )
{
T_16 * V_136 = V_127 -> V_137 ;
T_20 * V_268 ;
T_21 * V_269 ;
T_14 * V_270 ;
T_14 * V_271 ;
T_22 V_272 ;
short V_273 ;
int V_274 ;
int error ;
ASSERT ( F_52 ( V_2 ) -> V_145 != 0 ) ;
error = F_144 ( V_136 , V_127 , F_145 ( V_136 , V_2 -> V_75 ) , & V_270 ) ;
if ( error )
return error ;
V_268 = F_146 ( V_270 ) ;
V_272 = F_147 ( V_136 , V_2 -> V_75 ) ;
ASSERT ( V_272 != 0 ) ;
V_273 = V_272 % V_275 ;
ASSERT ( V_268 -> V_276 [ V_273 ] ) ;
ASSERT ( F_148 ( V_268 -> V_276 [ V_273 ] ) != V_272 ) ;
if ( V_268 -> V_276 [ V_273 ] != F_149 ( V_277 ) ) {
error = F_150 ( V_136 , V_127 , & V_2 -> V_278 , & V_269 , & V_271 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_269 -> V_279 == F_149 ( V_277 ) ) ;
V_269 -> V_279 = V_268 -> V_276 [ V_273 ] ;
V_274 = V_2 -> V_278 . V_280 +
F_151 ( T_21 , V_279 ) ;
F_152 ( V_136 , V_269 ) ;
F_153 ( V_127 , V_271 ) ;
F_154 ( V_127 , V_271 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
F_155 ( V_136 , V_271 ) ;
}
ASSERT ( V_272 != 0 ) ;
V_268 -> V_276 [ V_273 ] = F_149 ( V_272 ) ;
V_274 = F_151 ( T_20 , V_276 ) +
( sizeof( T_22 ) * V_273 ) ;
F_156 ( V_127 , V_270 , V_281 ) ;
F_154 ( V_127 , V_270 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_110 (
T_9 * V_127 ,
T_3 * V_2 )
{
T_8 V_282 ;
T_16 * V_136 ;
T_20 * V_268 ;
T_21 * V_269 ;
T_14 * V_270 ;
T_14 * V_271 ;
T_23 V_283 ;
T_22 V_272 ;
T_22 V_284 ;
T_14 * V_285 ;
T_21 * V_286 = NULL ;
short V_273 ;
int V_274 , V_287 = 0 ;
int error ;
V_136 = V_127 -> V_137 ;
V_283 = F_145 ( V_136 , V_2 -> V_75 ) ;
error = F_144 ( V_136 , V_127 , V_283 , & V_270 ) ;
if ( error )
return error ;
V_268 = F_146 ( V_270 ) ;
V_272 = F_147 ( V_136 , V_2 -> V_75 ) ;
ASSERT ( V_272 != 0 ) ;
V_273 = V_272 % V_275 ;
ASSERT ( V_268 -> V_276 [ V_273 ] != F_149 ( V_277 ) ) ;
ASSERT ( V_268 -> V_276 [ V_273 ] ) ;
if ( F_148 ( V_268 -> V_276 [ V_273 ] ) == V_272 ) {
error = F_150 ( V_136 , V_127 , & V_2 -> V_278 , & V_269 , & V_271 ,
0 , 0 ) ;
if ( error ) {
F_157 ( V_136 , L_6 ,
V_261 , error ) ;
return error ;
}
V_284 = F_148 ( V_269 -> V_279 ) ;
ASSERT ( V_284 != 0 ) ;
if ( V_284 != V_277 ) {
V_269 -> V_279 = F_149 ( V_277 ) ;
V_274 = V_2 -> V_278 . V_280 +
F_151 ( T_21 , V_279 ) ;
F_152 ( V_136 , V_269 ) ;
F_153 ( V_127 , V_271 ) ;
F_154 ( V_127 , V_271 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
F_155 ( V_136 , V_271 ) ;
} else {
F_158 ( V_127 , V_271 ) ;
}
ASSERT ( V_284 != 0 ) ;
ASSERT ( V_284 != V_272 ) ;
V_268 -> V_276 [ V_273 ] = F_149 ( V_284 ) ;
V_274 = F_151 ( T_20 , V_276 ) +
( sizeof( T_22 ) * V_273 ) ;
F_156 ( V_127 , V_270 , V_281 ) ;
F_154 ( V_127 , V_270 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
} else {
V_284 = F_148 ( V_268 -> V_276 [ V_273 ] ) ;
V_285 = NULL ;
while ( V_284 != V_272 ) {
struct V_288 V_289 ;
if ( V_285 )
F_158 ( V_127 , V_285 ) ;
V_289 . V_290 = 0 ;
V_282 = F_159 ( V_136 , V_283 , V_284 ) ;
error = V_288 ( V_136 , V_127 , V_282 , & V_289 , 0 ) ;
if ( error ) {
F_157 ( V_136 ,
L_7 ,
V_261 , error ) ;
return error ;
}
error = F_150 ( V_136 , V_127 , & V_289 , & V_286 ,
& V_285 , 0 , 0 ) ;
if ( error ) {
F_157 ( V_136 ,
L_6 ,
V_261 , error ) ;
return error ;
}
V_287 = V_289 . V_280 ;
V_284 = F_148 ( V_286 -> V_279 ) ;
ASSERT ( V_284 != V_277 ) ;
ASSERT ( V_284 != 0 ) ;
}
error = F_150 ( V_136 , V_127 , & V_2 -> V_278 , & V_269 , & V_271 ,
0 , 0 ) ;
if ( error ) {
F_157 ( V_136 , L_8 ,
V_261 , error ) ;
return error ;
}
V_284 = F_148 ( V_269 -> V_279 ) ;
ASSERT ( V_284 != 0 ) ;
ASSERT ( V_284 != V_272 ) ;
if ( V_284 != V_277 ) {
V_269 -> V_279 = F_149 ( V_277 ) ;
V_274 = V_2 -> V_278 . V_280 +
F_151 ( T_21 , V_279 ) ;
F_152 ( V_136 , V_269 ) ;
F_153 ( V_127 , V_271 ) ;
F_154 ( V_127 , V_271 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
F_155 ( V_136 , V_271 ) ;
} else {
F_158 ( V_127 , V_271 ) ;
}
V_286 -> V_279 = F_149 ( V_284 ) ;
ASSERT ( V_284 != 0 ) ;
V_274 = V_287 + F_151 ( T_21 , V_279 ) ;
F_152 ( V_136 , V_286 ) ;
F_153 ( V_127 , V_285 ) ;
F_154 ( V_127 , V_285 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
F_155 ( V_136 , V_285 ) ;
}
return 0 ;
}
STATIC int
F_160 (
T_3 * V_291 ,
T_9 * V_127 ,
struct V_292 * V_293 )
{
T_16 * V_136 = V_291 -> V_7 ;
int V_294 ;
int V_295 ;
int V_296 ;
int V_59 , V_60 ;
int V_297 ;
T_24 V_298 ;
T_14 * V_299 ;
T_3 * V_2 ;
T_25 * V_300 ;
T_4 * V_301 ;
struct V_302 * V_303 ;
T_8 V_123 ;
V_123 = V_293 -> V_304 ;
V_303 = F_161 ( V_136 , F_145 ( V_136 , V_123 ) ) ;
V_294 = F_162 ( V_136 ) ;
V_295 = V_294 << V_136 -> V_8 . V_305 ;
V_296 = V_136 -> V_306 / V_294 ;
for ( V_60 = 0 ; V_60 < V_296 ; V_60 ++ , V_123 += V_295 ) {
V_297 = V_123 - V_293 -> V_304 ;
if ( ( V_293 -> V_307 & F_163 ( V_297 ) ) == 0 ) {
ASSERT ( F_164 ( V_297 , V_295 ) == 0 ) ;
continue;
}
V_298 = F_165 ( V_136 , F_145 ( V_136 , V_123 ) ,
F_166 ( V_136 , V_123 ) ) ;
V_299 = F_167 ( V_127 , V_136 -> V_308 , V_298 ,
V_136 -> V_309 * V_294 ,
V_310 ) ;
if ( ! V_299 )
return - V_311 ;
V_299 -> V_312 = & V_313 ;
V_301 = V_299 -> V_314 ;
while ( V_301 ) {
if ( V_301 -> V_315 == V_316 ) {
V_300 = ( T_25 * ) V_301 ;
ASSERT ( V_300 -> V_317 == 1 ) ;
V_301 -> V_318 = V_319 ;
F_168 ( V_136 -> V_320 ,
& V_300 -> V_321 ,
& V_300 -> V_322 . V_323 ) ;
F_130 ( V_300 -> V_324 , V_325 ) ;
}
V_301 = V_301 -> V_326 ;
}
for ( V_59 = 0 ; V_59 < V_295 ; V_59 ++ ) {
V_327:
F_169 () ;
V_2 = F_170 ( & V_303 -> V_328 ,
F_147 ( V_136 , ( V_123 + V_59 ) ) ) ;
if ( ! V_2 ) {
F_171 () ;
continue;
}
F_172 ( & V_2 -> V_329 ) ;
if ( V_2 -> V_75 != V_123 + V_59 ||
F_173 ( V_2 , V_325 ) ) {
F_174 ( & V_2 -> V_329 ) ;
F_171 () ;
continue;
}
F_174 ( & V_2 -> V_329 ) ;
if ( V_2 != V_291 &&
! F_14 ( V_2 , V_23 ) ) {
F_171 () ;
F_30 ( 1 ) ;
goto V_327;
}
F_171 () ;
F_175 ( V_2 ) ;
F_130 ( V_2 , V_325 ) ;
V_300 = V_2 -> V_64 ;
if ( ! V_300 || F_176 ( V_2 ) ) {
ASSERT ( V_2 != V_291 ) ;
F_177 ( V_2 ) ;
F_20 ( V_2 , V_23 ) ;
continue;
}
V_300 -> V_330 = V_300 -> V_331 ;
V_300 -> V_331 = 0 ;
V_300 -> V_332 = 0 ;
V_300 -> V_317 = 1 ;
F_168 ( V_136 -> V_320 , & V_300 -> V_321 ,
& V_300 -> V_322 . V_323 ) ;
F_178 ( V_299 , V_319 ,
& V_300 -> V_322 ) ;
if ( V_2 != V_291 )
F_20 ( V_2 , V_23 ) ;
}
F_179 ( V_127 , V_299 ) ;
F_180 ( V_127 , V_299 ) ;
}
F_181 ( V_303 ) ;
return 0 ;
}
int
F_135 (
T_9 * V_127 ,
T_3 * V_2 ,
struct V_203 * V_204 )
{
int error ;
struct V_292 V_293 = { 0 } ;
ASSERT ( F_25 ( V_2 , V_23 ) ) ;
ASSERT ( F_52 ( V_2 ) -> V_200 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_151 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_188 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_150 == 0 || ! F_64 ( F_52 ( V_2 ) -> V_145 ) ) ;
ASSERT ( V_2 -> V_3 . V_152 == 0 ) ;
error = F_110 ( V_127 , V_2 ) ;
if ( error )
return error ;
error = F_182 ( V_127 , V_2 -> V_75 , V_204 , & V_293 ) ;
if ( error )
return error ;
F_52 ( V_2 ) -> V_145 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_156 = 0 ;
V_2 -> V_3 . V_267 = 0 ;
V_2 -> V_3 . V_18 = V_183 ;
V_2 -> V_3 . V_24 = V_183 ;
F_52 ( V_2 ) -> V_333 ++ ;
F_66 ( V_127 , V_2 , V_165 ) ;
if ( V_293 . V_334 )
error = F_160 ( V_2 , V_127 , & V_293 ) ;
return error ;
}
static void
F_183 (
struct V_1 * V_2 )
{
ASSERT ( F_25 ( V_2 , V_23 | V_17 ) ) ;
F_184 ( V_2 , V_27 ) ;
F_185 ( V_2 -> V_7 , V_2 -> V_64 -> V_335 , 0 ) ;
}
static void
F_186 (
struct V_1 * V_2 )
{
T_5 * V_76 = F_34 ( & V_2 -> V_77 , V_336 ) ;
F_35 ( V_79 , & V_2 -> V_77 , V_336 ) ;
F_183 ( V_2 ) ;
do {
F_187 ( V_76 , & V_79 . V_79 , V_80 ) ;
if ( F_188 ( V_2 ) )
F_38 () ;
} while ( F_188 ( V_2 ) );
F_40 ( V_76 , & V_79 . V_79 ) ;
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
T_3 * V_118 ,
struct V_119 * V_120 ,
T_3 * V_2 )
{
T_16 * V_136 = V_118 -> V_7 ;
T_9 * V_127 = NULL ;
int V_201 = F_60 ( F_52 ( V_2 ) -> V_145 ) ;
int error = 0 ;
struct V_203 V_204 ;
T_15 V_205 ;
T_2 V_213 ;
F_191 ( V_118 , V_120 ) ;
if ( F_46 ( V_136 ) )
return - V_124 ;
error = F_106 ( V_118 , 0 ) ;
if ( error )
goto V_231;
error = F_106 ( V_2 , 0 ) ;
if ( error )
goto V_231;
V_213 = F_192 ( V_136 ) ;
error = F_86 ( V_136 , & F_84 ( V_136 ) -> V_337 , V_213 , 0 , 0 , & V_127 ) ;
if ( error == - V_196 ) {
V_213 = 0 ;
error = F_86 ( V_136 , & F_84 ( V_136 ) -> V_337 , 0 , 0 , 0 ,
& V_127 ) ;
}
if ( error ) {
ASSERT ( error != - V_196 ) ;
goto V_231;
}
F_6 ( V_118 , V_29 | V_51 ) ;
F_32 ( V_118 , V_2 , V_23 ) ;
F_65 ( V_127 , V_118 , V_29 | V_23 ) ;
F_65 ( V_127 , V_2 , V_23 ) ;
if ( V_201 ) {
ASSERT ( F_52 ( V_2 ) -> V_200 >= 2 ) ;
if ( F_52 ( V_2 ) -> V_200 != 2 ) {
error = - V_338 ;
goto V_220;
}
if ( ! F_193 ( V_2 ) ) {
error = - V_338 ;
goto V_220;
}
error = F_73 ( V_127 , V_118 ) ;
if ( error )
goto V_220;
error = F_73 ( V_127 , V_2 ) ;
if ( error )
goto V_220;
} else {
F_66 ( V_127 , V_118 , V_165 ) ;
}
F_74 ( V_127 , V_118 , V_221 | V_199 ) ;
error = F_73 ( V_127 , V_2 ) ;
if ( error )
goto V_220;
F_88 ( & V_204 , & V_205 ) ;
error = F_194 ( V_127 , V_118 , V_120 , V_2 -> V_75 ,
& V_205 , & V_204 , V_213 ) ;
if ( error ) {
ASSERT ( error != - V_339 ) ;
goto V_222;
}
if ( V_136 -> V_223 & ( V_224 | V_225 ) )
F_94 ( V_127 ) ;
error = F_96 ( & V_127 , & V_204 , NULL ) ;
if ( error )
goto V_222;
error = F_97 ( V_127 ) ;
if ( error )
goto V_231;
if ( V_201 && F_195 ( V_2 ) )
F_196 ( V_2 ) ;
return 0 ;
V_222:
F_99 ( & V_204 ) ;
V_220:
F_100 ( V_127 ) ;
V_231:
return error ;
}
STATIC void
F_197 (
struct V_1 * V_340 ,
struct V_1 * V_341 ,
struct V_1 * V_73 ,
struct V_1 * V_342 ,
struct V_1 * V_343 ,
struct V_1 * * V_344 ,
int * V_345 )
{
int V_59 , V_60 ;
ASSERT ( * V_345 == V_346 ) ;
memset ( V_344 , 0 , * V_345 * sizeof( struct V_1 * ) ) ;
V_59 = 0 ;
V_344 [ V_59 ++ ] = V_340 ;
V_344 [ V_59 ++ ] = V_341 ;
V_344 [ V_59 ++ ] = V_73 ;
if ( V_342 )
V_344 [ V_59 ++ ] = V_342 ;
if ( V_343 )
V_344 [ V_59 ++ ] = V_343 ;
* V_345 = V_59 ;
for ( V_59 = 0 ; V_59 < * V_345 ; V_59 ++ ) {
for ( V_60 = 1 ; V_60 < * V_345 ; V_60 ++ ) {
if ( V_344 [ V_60 ] -> V_75 < V_344 [ V_60 - 1 ] -> V_75 ) {
struct V_1 * V_74 = V_344 [ V_60 ] ;
V_344 [ V_60 ] = V_344 [ V_60 - 1 ] ;
V_344 [ V_60 - 1 ] = V_74 ;
}
}
}
}
static int
F_198 (
struct V_202 * V_127 ,
struct V_203 * V_204 )
{
int error ;
if ( V_127 -> V_137 -> V_223 & ( V_224 | V_225 ) )
F_94 ( V_127 ) ;
error = F_96 ( & V_127 , V_204 , NULL ) ;
if ( error ) {
F_99 ( V_204 ) ;
F_100 ( V_127 ) ;
return error ;
}
return F_97 ( V_127 ) ;
}
STATIC int
F_199 (
struct V_202 * V_127 ,
struct V_1 * V_340 ,
struct V_119 * V_347 ,
struct V_1 * V_73 ,
struct V_1 * V_341 ,
struct V_119 * V_348 ,
struct V_1 * V_342 ,
struct V_203 * V_204 ,
T_15 * V_205 ,
int V_349 )
{
int error = 0 ;
int V_350 = 0 ;
int V_351 = 0 ;
int V_352 = 0 ;
error = F_200 ( V_127 , V_340 , V_347 ,
V_342 -> V_75 ,
V_205 , V_204 , V_349 ) ;
if ( error )
goto V_353;
error = F_200 ( V_127 , V_341 , V_348 ,
V_73 -> V_75 ,
V_205 , V_204 , V_349 ) ;
if ( error )
goto V_353;
if ( V_340 != V_341 ) {
V_352 = V_221 | V_199 ;
if ( F_60 ( F_52 ( V_342 ) -> V_145 ) ) {
error = F_200 ( V_127 , V_342 , & V_354 ,
V_340 -> V_75 , V_205 ,
V_204 , V_349 ) ;
if ( error )
goto V_353;
if ( ! F_60 ( F_52 ( V_73 ) -> V_145 ) ) {
error = F_73 ( V_127 , V_341 ) ;
if ( error )
goto V_353;
error = F_77 ( V_127 , V_340 ) ;
if ( error )
goto V_353;
}
V_350 |= V_199 ;
V_351 |= V_221 | V_199 ;
}
if ( F_60 ( F_52 ( V_73 ) -> V_145 ) ) {
error = F_200 ( V_127 , V_73 , & V_354 ,
V_341 -> V_75 , V_205 ,
V_204 , V_349 ) ;
if ( error )
goto V_353;
if ( ! F_60 ( F_52 ( V_342 ) -> V_145 ) ) {
error = F_73 ( V_127 , V_340 ) ;
if ( error )
goto V_353;
error = F_77 ( V_127 , V_341 ) ;
if ( error )
goto V_353;
}
V_350 |= V_221 | V_199 ;
V_351 |= V_199 ;
}
}
if ( V_350 ) {
F_74 ( V_127 , V_73 , V_350 ) ;
F_66 ( V_127 , V_73 , V_165 ) ;
}
if ( V_351 ) {
F_74 ( V_127 , V_342 , V_351 ) ;
F_66 ( V_127 , V_342 , V_165 ) ;
}
if ( V_352 ) {
F_74 ( V_127 , V_341 , V_352 ) ;
F_66 ( V_127 , V_341 , V_165 ) ;
}
F_74 ( V_127 , V_340 , V_221 | V_199 ) ;
F_66 ( V_127 , V_340 , V_165 ) ;
return F_198 ( V_127 , V_204 ) ;
V_353:
F_99 ( V_204 ) ;
F_100 ( V_127 ) ;
return error ;
}
static int
F_201 (
struct V_1 * V_118 ,
struct V_1 * * V_343 )
{
struct V_1 * tmpfile ;
int error ;
error = F_103 ( V_118 , NULL , V_168 | V_355 , & tmpfile ) ;
if ( error )
return error ;
F_75 ( F_52 ( tmpfile ) ) ;
F_202 ( tmpfile ) ;
F_101 ( tmpfile ) ;
F_52 ( tmpfile ) -> V_356 |= V_357 ;
* V_343 = tmpfile ;
return 0 ;
}
int
F_203 (
struct V_1 * V_358 ,
struct V_119 * V_359 ,
struct V_1 * V_360 ,
struct V_1 * V_361 ,
struct V_119 * V_230 ,
struct V_1 * V_362 ,
unsigned int V_82 )
{
struct V_135 * V_136 = V_358 -> V_7 ;
struct V_202 * V_127 ;
struct V_203 V_204 ;
T_15 V_205 ;
struct V_1 * V_343 = NULL ;
struct V_1 * V_57 [ V_346 ] ;
int V_345 = V_346 ;
bool V_363 = ( V_358 != V_361 ) ;
bool V_364 = F_60 ( F_52 ( V_360 ) -> V_145 ) ;
int V_349 ;
int error ;
F_204 ( V_358 , V_361 , V_359 , V_230 ) ;
if ( ( V_82 & V_365 ) && ! V_362 )
return - V_366 ;
if ( V_82 & V_367 ) {
ASSERT ( ! ( V_82 & ( V_368 | V_365 ) ) ) ;
error = F_201 ( V_361 , & V_343 ) ;
if ( error )
return error ;
V_359 -> type = V_369 ;
}
F_197 ( V_358 , V_361 , V_360 , V_362 , V_343 ,
V_57 , & V_345 ) ;
V_349 = F_205 ( V_136 , V_230 -> V_216 ) ;
error = F_86 ( V_136 , & F_84 ( V_136 ) -> V_370 , V_349 , 0 , 0 , & V_127 ) ;
if ( error == - V_196 ) {
V_349 = 0 ;
error = F_86 ( V_136 , & F_84 ( V_136 ) -> V_370 , 0 , 0 , 0 ,
& V_127 ) ;
}
if ( error )
goto V_371;
error = F_206 ( V_57 ) ;
if ( error )
goto V_220;
if ( ! V_363 )
F_6 ( V_358 , V_29 | V_51 ) ;
else
F_32 ( V_358 , V_361 ,
V_29 | V_51 ) ;
F_29 ( V_57 , V_345 , V_23 ) ;
F_65 ( V_127 , V_358 , V_29 | V_23 ) ;
if ( V_363 )
F_65 ( V_127 , V_361 , V_29 | V_23 ) ;
F_65 ( V_127 , V_360 , V_23 ) ;
if ( V_362 )
F_65 ( V_127 , V_362 , V_23 ) ;
if ( V_343 )
F_65 ( V_127 , V_343 , V_23 ) ;
if ( F_108 ( ( V_361 -> V_3 . V_4 & V_100 ) &&
( F_109 ( V_361 ) != F_109 ( V_360 ) ) ) ) {
error = - V_233 ;
goto V_220;
}
F_88 ( & V_204 , & V_205 ) ;
if ( V_82 & V_365 )
return F_199 ( V_127 , V_358 , V_359 , V_360 ,
V_361 , V_230 , V_362 ,
& V_204 , & V_205 , V_349 ) ;
if ( V_362 == NULL ) {
if ( ! V_349 ) {
error = F_90 ( V_127 , V_361 , V_230 ) ;
if ( error )
goto V_220;
}
error = F_91 ( V_127 , V_361 , V_230 ,
V_360 -> V_75 , & V_205 ,
& V_204 , V_349 ) ;
if ( error )
goto V_222;
F_74 ( V_127 , V_361 ,
V_221 | V_199 ) ;
if ( V_363 && V_364 ) {
error = F_77 ( V_127 , V_361 ) ;
if ( error )
goto V_222;
}
} else {
if ( F_60 ( F_52 ( V_362 ) -> V_145 ) ) {
if ( ! ( F_193 ( V_362 ) ) ||
( F_52 ( V_362 ) -> V_200 > 2 ) ) {
error = - V_372 ;
goto V_220;
}
}
error = F_200 ( V_127 , V_361 , V_230 ,
V_360 -> V_75 ,
& V_205 , & V_204 , V_349 ) ;
if ( error )
goto V_222;
F_74 ( V_127 , V_361 ,
V_221 | V_199 ) ;
error = F_73 ( V_127 , V_362 ) ;
if ( error )
goto V_222;
if ( V_364 ) {
error = F_73 ( V_127 , V_362 ) ;
if ( error )
goto V_222;
}
}
if ( V_363 && V_364 ) {
error = F_200 ( V_127 , V_360 , & V_354 ,
V_361 -> V_75 ,
& V_205 , & V_204 , V_349 ) ;
ASSERT ( error != - V_372 ) ;
if ( error )
goto V_222;
}
F_74 ( V_127 , V_360 , V_199 ) ;
F_66 ( V_127 , V_360 , V_165 ) ;
if ( V_364 && ( V_363 || V_362 != NULL ) ) {
error = F_73 ( V_127 , V_358 ) ;
if ( error )
goto V_222;
}
if ( V_343 ) {
error = F_200 ( V_127 , V_358 , V_359 , V_343 -> V_75 ,
& V_205 , & V_204 , V_349 ) ;
} else
error = F_194 ( V_127 , V_358 , V_359 , V_360 -> V_75 ,
& V_205 , & V_204 , V_349 ) ;
if ( error )
goto V_222;
if ( V_343 ) {
ASSERT ( F_52 ( V_343 ) -> V_200 == 0 ) ;
error = F_77 ( V_127 , V_343 ) ;
if ( error )
goto V_222;
error = F_110 ( V_127 , V_343 ) ;
if ( error )
goto V_222;
F_66 ( V_127 , V_343 , V_165 ) ;
F_52 ( V_343 ) -> V_356 &= ~ V_357 ;
}
F_74 ( V_127 , V_358 , V_221 | V_199 ) ;
F_66 ( V_127 , V_358 , V_165 ) ;
if ( V_363 )
F_66 ( V_127 , V_361 , V_165 ) ;
error = F_198 ( V_127 , & V_204 ) ;
if ( V_343 )
F_102 ( V_343 ) ;
return error ;
V_222:
F_99 ( & V_204 ) ;
V_220:
F_100 ( V_127 ) ;
V_371:
if ( V_343 )
F_102 ( V_343 ) ;
return error ;
}
STATIC int
F_207 (
struct V_1 * V_2 ,
struct V_373 * V_299 )
{
struct V_135 * V_136 = V_2 -> V_7 ;
struct V_302 * V_303 ;
unsigned long V_374 , V_375 ;
unsigned long V_295 ;
int V_376 ;
struct V_1 * * V_377 ;
struct V_1 * V_378 ;
int V_379 ;
int V_380 = 0 ;
int V_381 ;
int V_59 ;
V_303 = F_161 ( V_136 , F_145 ( V_136 , V_2 -> V_75 ) ) ;
V_295 = V_136 -> V_382 >> V_136 -> V_8 . V_383 ;
V_376 = V_295 * sizeof( T_3 * ) ;
V_377 = F_208 ( V_376 , V_384 | V_385 ) ;
if ( ! V_377 )
goto V_386;
V_375 = ~ ( ( ( V_136 -> V_382 >> V_136 -> V_8 . V_383 ) ) - 1 ) ;
V_374 = F_147 ( V_136 , V_2 -> V_75 ) & V_375 ;
F_169 () ;
V_379 = F_209 ( & V_303 -> V_328 , ( void * * ) V_377 ,
V_374 , V_295 ) ;
if ( V_379 == 0 )
goto V_387;
for ( V_59 = 0 ; V_59 < V_379 ; V_59 ++ ) {
V_378 = V_377 [ V_59 ] ;
if ( V_378 == V_2 )
continue;
F_172 ( & V_378 -> V_329 ) ;
if ( ! V_378 -> V_75 ||
F_173 ( V_378 , V_325 ) ) {
F_174 ( & V_378 -> V_329 ) ;
continue;
}
if ( ( F_147 ( V_136 , V_378 -> V_75 ) & V_375 ) != V_374 ) {
F_174 ( & V_378 -> V_329 ) ;
break;
}
F_174 ( & V_378 -> V_329 ) ;
if ( F_176 ( V_378 ) && F_188 ( V_378 ) == 0 )
continue;
if ( ! F_14 ( V_378 , V_17 ) )
continue;
if ( ! F_39 ( V_378 ) ) {
F_20 ( V_378 , V_17 ) ;
continue;
}
if ( F_188 ( V_378 ) ) {
F_177 ( V_378 ) ;
F_20 ( V_378 , V_17 ) ;
continue;
}
if ( ! V_378 -> V_75 ) {
F_177 ( V_378 ) ;
F_20 ( V_378 , V_17 ) ;
continue;
}
if ( ! F_176 ( V_378 ) ) {
int error ;
error = F_210 ( V_378 , V_299 ) ;
if ( error ) {
F_20 ( V_378 , V_17 ) ;
goto V_388;
}
V_380 ++ ;
} else {
F_177 ( V_378 ) ;
}
F_20 ( V_378 , V_17 ) ;
}
if ( V_380 ) {
F_211 ( V_136 , V_389 ) ;
F_212 ( V_136 , V_390 , V_380 ) ;
}
V_387:
F_171 () ;
F_49 ( V_377 ) ;
V_386:
F_181 ( V_303 ) ;
return 0 ;
V_388:
F_171 () ;
V_381 = ( V_299 -> V_391 & V_392 ) ;
if ( V_381 )
F_71 ( V_299 ) ;
F_137 ( V_136 , V_393 ) ;
if ( ! V_381 ) {
if ( V_299 -> V_394 ) {
V_299 -> V_391 &= ~ V_395 ;
F_213 ( V_299 ) ;
F_214 ( V_299 , - V_124 ) ;
F_215 ( V_299 ) ;
} else {
F_213 ( V_299 ) ;
F_71 ( V_299 ) ;
}
}
F_216 ( V_378 , false ) ;
F_49 ( V_377 ) ;
F_181 ( V_303 ) ;
return - V_396 ;
}
int
F_217 (
struct V_1 * V_2 ,
struct V_373 * * V_397 )
{
struct V_135 * V_136 = V_2 -> V_7 ;
struct V_373 * V_299 = NULL ;
struct V_398 * V_269 ;
int error ;
F_211 ( V_136 , V_399 ) ;
ASSERT ( F_25 ( V_2 , V_23 | V_17 ) ) ;
ASSERT ( F_37 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_18 != V_19 ||
V_2 -> V_3 . V_151 > F_218 ( V_2 , V_256 ) ) ;
* V_397 = NULL ;
F_189 ( V_2 ) ;
if ( F_128 ( V_2 , V_325 ) ) {
F_177 ( V_2 ) ;
return 0 ;
}
if ( F_46 ( V_136 ) ) {
error = - V_124 ;
goto V_400;
}
error = F_150 ( V_136 , NULL , & V_2 -> V_278 , & V_269 , & V_299 , V_401 ,
0 ) ;
if ( error == - V_254 ) {
F_177 ( V_2 ) ;
return error ;
}
if ( error )
goto V_402;
error = F_210 ( V_2 , V_299 ) ;
if ( error )
goto V_402;
if ( F_219 ( V_299 ) )
F_220 ( V_136 , 0 ) ;
error = F_207 ( V_2 , V_299 ) ;
if ( error )
goto V_388;
* V_397 = V_299 ;
return 0 ;
V_402:
if ( V_299 )
F_71 ( V_299 ) ;
F_137 ( V_136 , V_393 ) ;
V_388:
error = - V_396 ;
V_400:
F_216 ( V_2 , false ) ;
return error ;
}
STATIC int
F_210 (
struct V_1 * V_2 ,
struct V_373 * V_299 )
{
struct V_403 * V_300 = V_2 -> V_64 ;
struct V_398 * V_269 ;
struct V_135 * V_136 = V_2 -> V_7 ;
ASSERT ( F_25 ( V_2 , V_23 | V_17 ) ) ;
ASSERT ( F_37 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_18 != V_19 ||
V_2 -> V_3 . V_151 > F_218 ( V_2 , V_256 ) ) ;
ASSERT ( V_300 != NULL && V_300 -> V_331 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_144 > 1 ) ;
V_269 = F_221 ( V_299 , V_2 -> V_278 . V_280 ) ;
if ( F_222 ( V_269 -> V_404 != F_223 ( V_405 ) ,
V_136 , V_406 , V_407 ) ) {
F_224 ( V_136 , V_408 ,
L_9 ,
V_261 , V_2 -> V_75 , F_225 ( V_269 -> V_404 ) , V_269 ) ;
goto V_402;
}
if ( F_64 ( F_52 ( V_2 ) -> V_145 ) ) {
if ( F_222 (
( V_2 -> V_3 . V_18 != V_183 ) &&
( V_2 -> V_3 . V_18 != V_19 ) ,
V_136 , V_409 , V_410 ) ) {
F_224 ( V_136 , V_408 ,
L_10 ,
V_261 , V_2 -> V_75 , V_2 ) ;
goto V_402;
}
} else if ( F_60 ( F_52 ( V_2 ) -> V_145 ) ) {
if ( F_222 (
( V_2 -> V_3 . V_18 != V_183 ) &&
( V_2 -> V_3 . V_18 != V_19 ) &&
( V_2 -> V_3 . V_18 != V_411 ) ,
V_136 , V_412 , V_413 ) ) {
F_224 ( V_136 , V_408 ,
L_11 ,
V_261 , V_2 -> V_75 , V_2 ) ;
goto V_402;
}
}
if ( F_222 ( V_2 -> V_3 . V_151 + V_2 -> V_3 . V_188 >
V_2 -> V_3 . V_152 , V_136 , V_414 ,
V_415 ) ) {
F_224 ( V_136 , V_408 ,
L_12
L_13 ,
V_261 , V_2 -> V_75 ,
V_2 -> V_3 . V_151 + V_2 -> V_3 . V_188 ,
V_2 -> V_3 . V_152 , V_2 ) ;
goto V_402;
}
if ( F_222 ( V_2 -> V_3 . V_267 > V_136 -> V_8 . V_416 ,
V_136 , V_417 , V_418 ) ) {
F_224 ( V_136 , V_408 ,
L_14 ,
V_261 , V_2 -> V_75 , V_2 -> V_3 . V_267 , V_2 ) ;
goto V_402;
}
if ( V_2 -> V_3 . V_144 < 3 )
V_2 -> V_3 . V_419 ++ ;
F_226 ( V_2 , V_269 , V_300 -> V_322 . V_323 ) ;
if ( V_2 -> V_3 . V_419 == V_420 )
V_2 -> V_3 . V_419 = 0 ;
F_227 ( V_2 , V_269 , V_300 , V_256 ) ;
if ( F_43 ( V_2 ) )
F_227 ( V_2 , V_269 , V_300 , V_421 ) ;
F_155 ( V_136 , V_299 ) ;
V_300 -> V_330 = V_300 -> V_331 ;
V_300 -> V_331 = 0 ;
V_300 -> V_332 = 0 ;
V_300 -> V_317 = 1 ;
F_168 ( V_136 -> V_320 , & V_300 -> V_321 ,
& V_300 -> V_322 . V_323 ) ;
F_178 ( V_299 , V_422 , & V_300 -> V_322 ) ;
F_152 ( V_136 , V_269 ) ;
ASSERT ( V_299 -> V_314 != NULL ) ;
ASSERT ( V_299 -> V_394 != NULL ) ;
return 0 ;
V_402:
return - V_396 ;
}
