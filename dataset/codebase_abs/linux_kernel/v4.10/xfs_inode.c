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
if ( V_26 & V_29 ) {
F_9 ( & F_10 ( V_2 ) -> V_34 ,
F_11 ( V_26 ) ) ;
} else if ( V_26 & V_28 ) {
F_12 ( & F_10 ( V_2 ) -> V_34 ,
F_11 ( V_26 ) ) ;
}
if ( V_26 & V_31 )
F_13 ( & V_2 -> V_35 , F_14 ( V_26 ) ) ;
else if ( V_26 & V_30 )
F_15 ( & V_2 -> V_35 , F_14 ( V_26 ) ) ;
if ( V_26 & V_23 )
F_13 ( & V_2 -> V_36 , F_16 ( V_26 ) ) ;
else if ( V_26 & V_17 )
F_15 ( & V_2 -> V_36 , F_16 ( V_26 ) ) ;
}
int
F_17 (
T_3 * V_2 ,
T_2 V_26 )
{
F_18 ( V_2 , V_26 , V_27 ) ;
ASSERT ( ( V_26 & ( V_28 | V_29 ) ) !=
( V_28 | V_29 ) ) ;
ASSERT ( ( V_26 & ( V_30 | V_31 ) ) !=
( V_30 | V_31 ) ) ;
ASSERT ( ( V_26 & ( V_17 | V_23 ) ) !=
( V_17 | V_23 ) ) ;
ASSERT ( ( V_26 & ~ ( V_32 | V_33 ) ) == 0 ) ;
if ( V_26 & V_29 ) {
if ( ! F_19 ( & F_10 ( V_2 ) -> V_34 ) )
goto V_37;
} else if ( V_26 & V_28 ) {
if ( ! F_20 ( & F_10 ( V_2 ) -> V_34 ) )
goto V_37;
}
if ( V_26 & V_31 ) {
if ( ! F_21 ( & V_2 -> V_35 ) )
goto V_38;
} else if ( V_26 & V_30 ) {
if ( ! F_22 ( & V_2 -> V_35 ) )
goto V_38;
}
if ( V_26 & V_23 ) {
if ( ! F_21 ( & V_2 -> V_36 ) )
goto V_39;
} else if ( V_26 & V_17 ) {
if ( ! F_22 ( & V_2 -> V_36 ) )
goto V_39;
}
return 1 ;
V_39:
if ( V_26 & V_31 )
F_23 ( & V_2 -> V_35 ) ;
else if ( V_26 & V_30 )
F_24 ( & V_2 -> V_35 ) ;
V_38:
if ( V_26 & V_29 )
F_25 ( & F_10 ( V_2 ) -> V_34 ) ;
else if ( V_26 & V_28 )
F_26 ( & F_10 ( V_2 ) -> V_34 ) ;
V_37:
return 0 ;
}
void
F_27 (
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
F_25 ( & F_10 ( V_2 ) -> V_34 ) ;
else if ( V_26 & V_28 )
F_26 ( & F_10 ( V_2 ) -> V_34 ) ;
if ( V_26 & V_31 )
F_23 ( & V_2 -> V_35 ) ;
else if ( V_26 & V_30 )
F_24 ( & V_2 -> V_35 ) ;
if ( V_26 & V_23 )
F_23 ( & V_2 -> V_36 ) ;
else if ( V_26 & V_17 )
F_24 ( & V_2 -> V_36 ) ;
F_28 ( V_2 , V_26 , V_27 ) ;
}
void
F_29 (
T_3 * V_2 ,
T_2 V_26 )
{
ASSERT ( V_26 & ( V_29 | V_31 | V_23 ) ) ;
ASSERT ( ( V_26 &
~ ( V_29 | V_31 | V_23 ) ) == 0 ) ;
if ( V_26 & V_23 )
F_30 ( & V_2 -> V_36 ) ;
if ( V_26 & V_31 )
F_30 ( & V_2 -> V_35 ) ;
if ( V_26 & V_29 )
F_31 ( & F_10 ( V_2 ) -> V_34 ) ;
F_32 ( V_2 , V_26 , V_27 ) ;
}
int
F_33 (
T_3 * V_2 ,
T_2 V_26 )
{
if ( V_26 & ( V_23 | V_17 ) ) {
if ( ! ( V_26 & V_17 ) )
return ! ! V_2 -> V_36 . V_40 ;
return F_34 ( & V_2 -> V_36 . V_41 ) ;
}
if ( V_26 & ( V_31 | V_30 ) ) {
if ( ! ( V_26 & V_30 ) )
return ! ! V_2 -> V_35 . V_40 ;
return F_34 ( & V_2 -> V_35 . V_41 ) ;
}
if ( V_26 & ( V_29 | V_28 ) ) {
if ( ! ( V_26 & V_28 ) )
return ! V_42 ||
F_35 ( & F_10 ( V_2 ) -> V_34 , 0 ) ;
return F_34 ( & F_10 ( V_2 ) -> V_34 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
static bool
F_36 (
int V_43 )
{
return V_43 < V_44 ;
}
static inline int
F_37 ( int V_16 , int V_43 )
{
int V_45 = 0 ;
ASSERT ( ! ( V_16 & ( V_46 | V_47 |
V_48 ) ) ) ;
ASSERT ( F_36 ( V_43 ) ) ;
if ( V_16 & ( V_28 | V_29 ) ) {
ASSERT ( V_43 <= V_49 ) ;
V_45 += V_43 << V_50 ;
}
if ( V_16 & ( V_30 | V_31 ) ) {
ASSERT ( V_43 <= V_51 ) ;
V_45 += V_43 << V_52 ;
}
if ( V_16 & ( V_17 | V_23 ) ) {
ASSERT ( V_43 <= V_53 ) ;
V_45 += V_43 << V_54 ;
}
return ( V_16 & ~ V_33 ) | V_45 ;
}
static void
F_38 (
T_3 * * V_55 ,
int V_56 ,
T_2 V_16 )
{
int V_57 = 0 , V_58 , V_59 , V_60 ;
T_4 * V_61 ;
ASSERT ( V_55 && V_56 >= 2 && V_56 <= 5 ) ;
ASSERT ( V_16 & ( V_29 | V_31 |
V_23 ) ) ;
ASSERT ( ! ( V_16 & ( V_28 | V_30 |
V_17 ) ) ) ;
ASSERT ( ! ( V_16 & V_31 ) ||
V_56 <= V_51 + 1 ) ;
ASSERT ( ! ( V_16 & V_23 ) ||
V_56 <= V_53 + 1 ) ;
if ( V_16 & V_29 ) {
ASSERT ( ! ( V_16 & ( V_31 | V_23 ) ) ) ;
} else if ( V_16 & V_31 )
ASSERT ( ! ( V_16 & V_23 ) ) ;
V_60 = 0 ;
V_58 = 0 ;
V_62:
for (; V_58 < V_56 ; V_58 ++ ) {
ASSERT ( V_55 [ V_58 ] ) ;
if ( V_58 && ( V_55 [ V_58 ] == V_55 [ V_58 - 1 ] ) )
continue;
if ( ! V_60 ) {
for ( V_59 = ( V_58 - 1 ) ; V_59 >= 0 && ! V_60 ; V_59 -- ) {
V_61 = ( T_4 * ) V_55 [ V_59 ] -> V_63 ;
if ( V_61 && ( V_61 -> V_64 & V_65 ) )
V_60 ++ ;
}
}
if ( ! V_60 ) {
F_6 ( V_55 [ V_58 ] , F_37 ( V_16 , V_58 ) ) ;
continue;
}
ASSERT ( V_58 != 0 ) ;
if ( F_17 ( V_55 [ V_58 ] , F_37 ( V_16 , V_58 ) ) )
continue;
V_57 ++ ;
for ( V_59 = V_58 - 1 ; V_59 >= 0 ; V_59 -- ) {
if ( V_59 != ( V_58 - 1 ) && V_55 [ V_59 ] == V_55 [ V_59 + 1 ] )
continue;
F_27 ( V_55 [ V_59 ] , V_16 ) ;
}
if ( ( V_57 % 5 ) == 0 ) {
F_39 ( 1 ) ;
#ifdef F_40
V_66 ++ ;
#endif
}
V_58 = 0 ;
V_60 = 0 ;
goto V_62;
}
#ifdef F_40
if ( V_57 ) {
if ( V_57 < 5 ) V_67 ++ ;
else if ( V_57 < 100 ) V_68 ++ ;
else V_69 ++ ;
} else {
V_70 ++ ;
}
#endif
}
void
F_41 (
T_3 * V_71 ,
T_3 * V_72 ,
T_2 V_16 )
{
T_3 * V_73 ;
int V_57 = 0 ;
T_4 * V_61 ;
ASSERT ( ! ( V_16 & ( V_28 | V_29 ) ) ) ;
if ( V_16 & ( V_30 | V_31 ) )
ASSERT ( ! ( V_16 & ( V_17 | V_23 ) ) ) ;
ASSERT ( V_71 -> V_74 != V_72 -> V_74 ) ;
if ( V_71 -> V_74 > V_72 -> V_74 ) {
V_73 = V_71 ;
V_71 = V_72 ;
V_72 = V_73 ;
}
V_62:
F_6 ( V_71 , F_37 ( V_16 , 0 ) ) ;
V_61 = ( T_4 * ) V_71 -> V_63 ;
if ( V_61 && ( V_61 -> V_64 & V_65 ) ) {
if ( ! F_17 ( V_72 , F_37 ( V_16 , 1 ) ) ) {
F_27 ( V_71 , V_16 ) ;
if ( ( ++ V_57 % 5 ) == 0 )
F_39 ( 1 ) ;
goto V_62;
}
} else {
F_6 ( V_72 , F_37 ( V_16 , 1 ) ) ;
}
}
void
F_42 (
struct V_1 * V_2 )
{
T_5 * V_75 = F_43 ( & V_2 -> V_76 , V_77 ) ;
F_44 ( V_78 , & V_2 -> V_76 , V_77 ) ;
do {
F_45 ( V_75 , & V_78 . V_78 , V_79 ) ;
if ( F_46 ( V_2 ) )
F_47 () ;
} while ( ! F_48 ( V_2 ) );
F_49 ( V_75 , & V_78 . V_78 ) ;
}
STATIC T_2
F_50 (
T_6 V_4 ,
T_7 V_12 ,
bool V_80 )
{
T_2 V_81 = 0 ;
if ( V_4 & V_82 ) {
if ( V_4 & V_83 )
V_81 |= V_84 ;
if ( V_4 & V_85 )
V_81 |= V_86 ;
if ( V_4 & V_87 )
V_81 |= V_88 ;
if ( V_4 & V_89 )
V_81 |= V_90 ;
if ( V_4 & V_91 )
V_81 |= V_92 ;
if ( V_4 & V_93 )
V_81 |= V_94 ;
if ( V_4 & V_95 )
V_81 |= V_96 ;
if ( V_4 & V_97 )
V_81 |= V_98 ;
if ( V_4 & V_99 )
V_81 |= V_100 ;
if ( V_4 & V_101 )
V_81 |= V_102 ;
if ( V_4 & V_5 )
V_81 |= V_103 ;
if ( V_4 & V_104 )
V_81 |= V_105 ;
if ( V_4 & V_106 )
V_81 |= V_107 ;
if ( V_4 & V_108 )
V_81 |= V_109 ;
}
if ( V_12 & V_110 ) {
if ( V_12 & V_111 )
V_81 |= V_112 ;
if ( V_12 & V_13 )
V_81 |= V_113 ;
}
if ( V_80 )
V_81 |= V_114 ;
return V_81 ;
}
T_2
F_51 (
struct V_1 * V_2 )
{
struct V_115 * V_116 = & V_2 -> V_3 ;
return F_50 ( V_116 -> V_4 , V_116 -> V_12 , F_52 ( V_2 ) ) ;
}
int
F_53 (
T_3 * V_117 ,
struct V_118 * V_119 ,
T_3 * * V_120 ,
struct V_118 * V_121 )
{
T_8 V_122 ;
int error ;
F_54 ( V_117 , V_119 ) ;
if ( F_55 ( V_117 -> V_7 ) )
return - V_123 ;
error = F_56 ( NULL , V_117 , V_119 , & V_122 , V_121 ) ;
if ( error )
goto V_124;
error = F_57 ( V_117 -> V_7 , NULL , V_122 , 0 , 0 , V_120 ) ;
if ( error )
goto V_125;
return 0 ;
V_125:
if ( V_121 )
F_58 ( V_121 -> V_119 ) ;
V_124:
* V_120 = NULL ;
return error ;
}
static int
F_59 (
T_9 * V_126 ,
T_3 * V_127 ,
T_10 V_128 ,
T_11 V_129 ,
T_12 V_130 ,
T_13 V_131 ,
int V_132 ,
T_14 * * V_133 ,
T_3 * * V_120 )
{
struct V_134 * V_135 = V_126 -> V_136 ;
T_8 V_137 ;
T_3 * V_2 ;
T_2 V_81 ;
int error ;
struct V_138 V_139 ;
struct V_140 * V_140 ;
error = F_60 ( V_126 , V_127 ? V_127 -> V_74 : 0 , V_128 , V_132 ,
V_133 , & V_137 ) ;
if ( error )
return error ;
if ( * V_133 || V_137 == V_141 ) {
* V_120 = NULL ;
return 0 ;
}
ASSERT ( * V_133 == NULL ) ;
error = F_57 ( V_135 , V_126 , V_137 , V_142 ,
V_23 , & V_2 ) ;
if ( error )
return error ;
ASSERT ( V_2 != NULL ) ;
V_140 = F_10 ( V_2 ) ;
if ( V_2 -> V_3 . V_143 == 1 )
V_2 -> V_3 . V_143 = 2 ;
V_140 -> V_144 = V_128 ;
F_61 ( V_140 , V_129 ) ;
V_2 -> V_3 . V_145 = F_62 ( F_63 () ) ;
V_2 -> V_3 . V_146 = F_64 ( F_65 () ) ;
F_66 ( V_2 , V_131 ) ;
if ( V_127 && F_67 ( V_127 ) ) {
V_2 -> V_3 . V_146 = V_127 -> V_3 . V_146 ;
if ( ( F_10 ( V_127 ) -> V_144 & V_147 ) && F_68 ( V_128 ) )
V_140 -> V_144 |= V_147 ;
}
if ( ( V_148 ) &&
( V_140 -> V_144 & V_147 ) &&
( ! F_69 ( F_70 ( V_2 -> V_3 . V_146 ) ) ) )
V_140 -> V_144 &= ~ V_147 ;
V_2 -> V_3 . V_149 = 0 ;
V_2 -> V_3 . V_150 = 0 ;
ASSERT ( V_2 -> V_3 . V_151 == 0 ) ;
V_139 = F_71 ( V_140 ) ;
V_140 -> V_152 = V_139 ;
V_140 -> V_153 = V_139 ;
V_140 -> V_154 = V_139 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_155 = 0 ;
V_2 -> V_3 . V_156 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( V_2 -> V_3 . V_143 == 3 ) {
V_140 -> V_157 = 1 ;
V_2 -> V_3 . V_12 = 0 ;
V_2 -> V_3 . V_14 = 0 ;
V_2 -> V_3 . V_158 . V_159 = ( V_160 ) V_139 . V_161 ;
V_2 -> V_3 . V_158 . V_162 = ( V_160 ) V_139 . V_163 ;
}
V_81 = V_164 ;
switch ( V_128 & V_165 ) {
case V_166 :
case V_167 :
case V_168 :
case V_169 :
V_2 -> V_3 . V_18 = V_170 ;
V_2 -> V_20 . V_171 . V_172 = V_130 ;
V_2 -> V_20 . V_21 = 0 ;
V_81 |= V_173 ;
break;
case V_174 :
case V_175 :
if ( V_127 && ( V_127 -> V_3 . V_4 & V_82 ) ) {
T_7 V_12 = 0 ;
T_2 V_4 = 0 ;
if ( F_68 ( V_128 ) ) {
if ( V_127 -> V_3 . V_4 & V_97 )
V_4 |= V_97 ;
if ( V_127 -> V_3 . V_4 & V_104 ) {
V_4 |= V_104 ;
V_2 -> V_3 . V_6 = V_127 -> V_3 . V_6 ;
}
if ( V_127 -> V_3 . V_4 & V_99 )
V_4 |= V_99 ;
} else if ( F_72 ( V_128 ) ) {
if ( V_127 -> V_3 . V_4 & V_97 )
V_4 |= V_83 ;
if ( V_127 -> V_3 . V_4 & V_104 ) {
V_4 |= V_5 ;
V_2 -> V_3 . V_6 = V_127 -> V_3 . V_6 ;
}
}
if ( ( V_127 -> V_3 . V_4 & V_93 ) &&
V_176 )
V_4 |= V_93 ;
if ( ( V_127 -> V_3 . V_4 & V_95 ) &&
V_177 )
V_4 |= V_95 ;
if ( ( V_127 -> V_3 . V_4 & V_91 ) &&
V_178 )
V_4 |= V_91 ;
if ( ( V_127 -> V_3 . V_4 & V_101 ) &&
V_179 )
V_4 |= V_101 ;
if ( ( V_127 -> V_3 . V_4 & V_106 ) &&
V_180 )
V_4 |= V_106 ;
if ( V_127 -> V_3 . V_4 & V_108 )
V_4 |= V_108 ;
if ( V_127 -> V_3 . V_12 & V_111 )
V_12 |= V_111 ;
V_2 -> V_3 . V_4 |= V_4 ;
V_2 -> V_3 . V_12 |= V_12 ;
}
if ( V_127 &&
( V_127 -> V_3 . V_12 & V_110 ) &&
V_127 -> V_3 . V_143 == 3 &&
V_2 -> V_3 . V_143 == 3 ) {
if ( V_127 -> V_3 . V_12 & V_13 ) {
V_2 -> V_3 . V_12 |= V_13 ;
V_2 -> V_3 . V_14 = V_127 -> V_3 . V_14 ;
}
}
case V_181 :
V_2 -> V_3 . V_18 = V_182 ;
V_2 -> V_20 . V_21 = V_22 ;
V_2 -> V_20 . V_183 = V_2 -> V_20 . V_184 = 0 ;
V_2 -> V_20 . V_185 . V_186 = NULL ;
break;
default:
ASSERT ( 0 ) ;
}
V_2 -> V_3 . V_24 = V_182 ;
V_2 -> V_3 . V_187 = 0 ;
F_73 ( V_126 , V_2 , V_23 ) ;
F_74 ( V_126 , V_2 , V_81 ) ;
F_75 ( V_2 ) ;
* V_120 = V_2 ;
return 0 ;
}
int
F_76 (
T_9 * * V_188 ,
T_3 * V_117 ,
T_10 V_128 ,
T_11 V_129 ,
T_12 V_130 ,
T_13 V_131 ,
int V_132 ,
T_3 * * V_120 ,
int * V_189 )
{
T_9 * V_126 ;
T_3 * V_2 ;
T_14 * V_133 = NULL ;
int V_190 ;
void * V_191 ;
T_2 V_192 ;
V_126 = * V_188 ;
ASSERT ( V_126 -> V_193 & V_194 ) ;
V_190 = F_59 ( V_126 , V_117 , V_128 , V_129 , V_130 , V_131 , V_132 ,
& V_133 , & V_2 ) ;
if ( V_190 ) {
* V_120 = NULL ;
return V_190 ;
}
if ( ! V_133 && ! V_2 ) {
* V_120 = NULL ;
return - V_195 ;
}
if ( V_133 ) {
F_77 ( V_126 , V_133 ) ;
V_191 = NULL ;
V_192 = 0 ;
if ( V_126 -> V_196 ) {
V_191 = ( void * ) V_126 -> V_196 ;
V_126 -> V_196 = NULL ;
V_192 = V_126 -> V_193 & V_197 ;
V_126 -> V_193 &= ~ ( V_197 ) ;
}
V_190 = F_78 ( & V_126 , NULL ) ;
if ( V_189 != NULL )
* V_189 = 1 ;
if ( V_191 ) {
V_126 -> V_196 = V_191 ;
V_126 -> V_193 |= V_192 ;
}
if ( V_190 ) {
F_79 ( V_133 ) ;
* V_188 = V_126 ;
* V_120 = NULL ;
return V_190 ;
}
F_80 ( V_126 , V_133 ) ;
V_190 = F_59 ( V_126 , V_117 , V_128 , V_129 , V_130 , V_131 ,
V_132 , & V_133 , & V_2 ) ;
if ( V_190 ) {
* V_188 = V_126 ;
* V_120 = NULL ;
return V_190 ;
}
ASSERT ( ! V_133 && V_2 ) ;
} else {
if ( V_189 != NULL )
* V_189 = 0 ;
}
* V_120 = V_2 ;
* V_188 = V_126 ;
return 0 ;
}
static int
F_81 (
T_9 * V_126 ,
T_3 * V_2 )
{
F_82 ( V_126 , V_2 , V_198 ) ;
F_83 ( F_10 ( V_2 ) ) ;
F_74 ( V_126 , V_2 , V_164 ) ;
if ( F_10 ( V_2 ) -> V_199 )
return 0 ;
return F_84 ( V_126 , V_2 ) ;
}
static int
F_85 (
T_9 * V_126 ,
T_3 * V_2 )
{
F_82 ( V_126 , V_2 , V_198 ) ;
ASSERT ( V_2 -> V_3 . V_143 > 1 ) ;
F_86 ( F_10 ( V_2 ) ) ;
F_74 ( V_126 , V_2 , V_164 ) ;
return 0 ;
}
int
F_87 (
T_3 * V_117 ,
struct V_118 * V_119 ,
T_10 V_128 ,
T_12 V_130 ,
T_3 * * V_120 )
{
int V_200 = F_68 ( V_128 ) ;
struct V_134 * V_135 = V_117 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_201 * V_126 = NULL ;
int error ;
struct V_202 V_203 ;
T_15 V_204 ;
bool V_205 = false ;
T_13 V_131 ;
struct V_206 * V_207 = NULL ;
struct V_206 * V_208 = NULL ;
struct V_206 * V_209 = NULL ;
struct V_210 * V_211 ;
T_2 V_212 ;
F_88 ( V_117 , V_119 ) ;
if ( F_55 ( V_135 ) )
return - V_123 ;
V_131 = F_89 ( V_117 ) ;
error = F_90 ( V_117 , F_62 ( F_63 () ) ,
F_64 ( F_65 () ) , V_131 ,
V_213 | V_214 ,
& V_207 , & V_208 , & V_209 ) ;
if ( error )
return error ;
if ( V_200 ) {
V_130 = 0 ;
V_212 = F_91 ( V_135 , V_119 -> V_215 ) ;
V_211 = & F_92 ( V_135 ) -> V_216 ;
} else {
V_212 = F_93 ( V_135 , V_119 -> V_215 ) ;
V_211 = & F_92 ( V_135 ) -> V_217 ;
}
error = F_94 ( V_135 , V_211 , V_212 , 0 , 0 , & V_126 ) ;
if ( error == - V_195 ) {
F_95 ( V_135 ) ;
error = F_94 ( V_135 , V_211 , V_212 , 0 , 0 , & V_126 ) ;
}
if ( error == - V_195 ) {
V_212 = 0 ;
error = F_94 ( V_135 , V_211 , 0 , 0 , 0 , & V_126 ) ;
}
if ( error )
goto V_218;
F_6 ( V_117 , V_23 | V_46 ) ;
V_205 = true ;
F_96 ( & V_203 , & V_204 ) ;
error = F_97 ( V_126 , V_135 , V_207 , V_208 ,
V_209 , V_212 , 1 , 0 ) ;
if ( error )
goto V_219;
if ( ! V_212 ) {
error = F_98 ( V_126 , V_117 , V_119 ) ;
if ( error )
goto V_219;
}
error = F_76 ( & V_126 , V_117 , V_128 , V_200 ? 2 : 1 , V_130 ,
V_131 , V_212 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_219;
F_73 ( V_126 , V_117 , V_23 ) ;
V_205 = false ;
error = F_99 ( V_126 , V_117 , V_119 , V_2 -> V_74 ,
& V_204 , & V_203 , V_212 ?
V_212 - F_100 ( V_135 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_195 ) ;
goto V_219;
}
F_82 ( V_126 , V_117 , V_220 | V_198 ) ;
F_74 ( V_126 , V_117 , V_164 ) ;
if ( V_200 ) {
error = F_101 ( V_126 , V_2 , V_117 ) ;
if ( error )
goto V_221;
error = F_85 ( V_126 , V_117 ) ;
if ( error )
goto V_221;
}
if ( V_135 -> V_222 & ( V_223 | V_224 ) )
F_102 ( V_126 ) ;
F_103 ( V_126 , V_2 , V_207 , V_208 , V_209 ) ;
error = F_104 ( & V_126 , & V_203 , NULL ) ;
if ( error )
goto V_221;
error = F_105 ( V_126 ) ;
if ( error )
goto V_218;
F_106 ( V_207 ) ;
F_106 ( V_208 ) ;
F_106 ( V_209 ) ;
* V_120 = V_2 ;
return 0 ;
V_221:
F_107 ( & V_203 ) ;
V_219:
F_108 ( V_126 ) ;
V_218:
if ( V_2 ) {
F_109 ( V_2 ) ;
F_110 ( V_2 ) ;
}
F_106 ( V_207 ) ;
F_106 ( V_208 ) ;
F_106 ( V_209 ) ;
if ( V_205 )
F_27 ( V_117 , V_23 ) ;
return error ;
}
int
F_111 (
struct V_1 * V_117 ,
struct V_225 * V_225 ,
T_10 V_128 ,
struct V_1 * * V_120 )
{
struct V_134 * V_135 = V_117 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_201 * V_126 = NULL ;
int error ;
T_13 V_131 ;
struct V_206 * V_207 = NULL ;
struct V_206 * V_208 = NULL ;
struct V_206 * V_209 = NULL ;
struct V_210 * V_211 ;
T_2 V_212 ;
if ( F_55 ( V_135 ) )
return - V_123 ;
V_131 = F_89 ( V_117 ) ;
error = F_90 ( V_117 , F_62 ( F_63 () ) ,
F_64 ( F_65 () ) , V_131 ,
V_213 | V_214 ,
& V_207 , & V_208 , & V_209 ) ;
if ( error )
return error ;
V_212 = F_100 ( V_135 ) ;
V_211 = & F_92 ( V_135 ) -> V_226 ;
error = F_94 ( V_135 , V_211 , V_212 , 0 , 0 , & V_126 ) ;
if ( error == - V_195 ) {
V_212 = 0 ;
error = F_94 ( V_135 , V_211 , 0 , 0 , 0 , & V_126 ) ;
}
if ( error )
goto V_218;
error = F_97 ( V_126 , V_135 , V_207 , V_208 ,
V_209 , V_212 , 1 , 0 ) ;
if ( error )
goto V_219;
error = F_76 ( & V_126 , V_117 , V_128 , 1 , 0 ,
V_131 , V_212 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_219;
if ( V_135 -> V_222 & V_223 )
F_102 ( V_126 ) ;
F_103 ( V_126 , V_2 , V_207 , V_208 , V_209 ) ;
error = F_84 ( V_126 , V_2 ) ;
if ( error )
goto V_219;
error = F_105 ( V_126 ) ;
if ( error )
goto V_218;
F_106 ( V_207 ) ;
F_106 ( V_208 ) ;
F_106 ( V_209 ) ;
* V_120 = V_2 ;
return 0 ;
V_219:
F_108 ( V_126 ) ;
V_218:
if ( V_2 ) {
F_109 ( V_2 ) ;
F_110 ( V_2 ) ;
}
F_106 ( V_207 ) ;
F_106 ( V_208 ) ;
F_106 ( V_209 ) ;
return error ;
}
int
F_112 (
T_3 * V_227 ,
T_3 * V_228 ,
struct V_118 * V_229 )
{
T_16 * V_135 = V_227 -> V_7 ;
T_9 * V_126 ;
int error ;
struct V_202 V_203 ;
T_15 V_204 ;
int V_212 ;
F_113 ( V_227 , V_229 ) ;
ASSERT ( ! F_68 ( F_10 ( V_228 ) -> V_144 ) ) ;
if ( F_55 ( V_135 ) )
return - V_123 ;
error = F_114 ( V_228 , 0 ) ;
if ( error )
goto V_230;
error = F_114 ( V_227 , 0 ) ;
if ( error )
goto V_230;
V_212 = F_115 ( V_135 , V_229 -> V_215 ) ;
error = F_94 ( V_135 , & F_92 ( V_135 ) -> V_231 , V_212 , 0 , 0 , & V_126 ) ;
if ( error == - V_195 ) {
V_212 = 0 ;
error = F_94 ( V_135 , & F_92 ( V_135 ) -> V_231 , 0 , 0 , 0 , & V_126 ) ;
}
if ( error )
goto V_230;
F_41 ( V_228 , V_227 , V_23 ) ;
F_73 ( V_126 , V_228 , V_23 ) ;
F_73 ( V_126 , V_227 , V_23 ) ;
if ( F_116 ( ( V_227 -> V_3 . V_4 & V_99 ) &&
( F_117 ( V_227 ) != F_117 ( V_228 ) ) ) ) {
error = - V_232 ;
goto V_233;
}
if ( ! V_212 ) {
error = F_98 ( V_126 , V_227 , V_229 ) ;
if ( error )
goto V_233;
}
F_96 ( & V_203 , & V_204 ) ;
if ( F_10 ( V_228 ) -> V_199 == 0 ) {
error = F_118 ( V_126 , V_228 ) ;
if ( error )
goto V_233;
}
error = F_99 ( V_126 , V_227 , V_229 , V_228 -> V_74 ,
& V_204 , & V_203 , V_212 ) ;
if ( error )
goto V_233;
F_82 ( V_126 , V_227 , V_220 | V_198 ) ;
F_74 ( V_126 , V_227 , V_164 ) ;
error = F_85 ( V_126 , V_228 ) ;
if ( error )
goto V_233;
if ( V_135 -> V_222 & ( V_223 | V_224 ) )
F_102 ( V_126 ) ;
error = F_104 ( & V_126 , & V_203 , NULL ) ;
if ( error ) {
F_107 ( & V_203 ) ;
goto V_233;
}
return F_105 ( V_126 ) ;
V_233:
F_108 ( V_126 ) ;
V_230:
return error ;
}
int
F_119 (
struct V_201 * * V_188 ,
struct V_1 * V_2 ,
int V_234 ,
T_17 V_235 )
{
struct V_134 * V_135 = V_2 -> V_7 ;
struct V_201 * V_126 = * V_188 ;
struct V_202 V_203 ;
T_15 V_204 ;
T_18 V_236 ;
T_18 V_237 ;
T_19 V_238 ;
int error = 0 ;
int V_239 = 0 ;
ASSERT ( F_33 ( V_2 , V_23 ) ) ;
ASSERT ( ! F_120 ( & F_10 ( V_2 ) -> V_240 ) ||
F_33 ( V_2 , V_29 ) ) ;
ASSERT ( V_235 <= F_121 ( V_2 ) ) ;
ASSERT ( V_126 -> V_193 & V_194 ) ;
ASSERT ( V_2 -> V_63 != NULL ) ;
ASSERT ( V_2 -> V_63 -> V_241 == 0 ) ;
ASSERT ( ! F_122 ( V_135 , V_2 ) ) ;
F_123 ( V_2 , V_235 ) ;
V_236 = F_124 ( V_135 , ( V_242 ) V_235 ) ;
V_237 = F_124 ( V_135 , V_135 -> V_243 -> V_244 ) ;
if ( V_236 == V_237 )
return 0 ;
ASSERT ( V_236 < V_237 ) ;
V_238 = V_237 - V_236 + 1 ;
while ( ! V_239 ) {
F_96 ( & V_203 , & V_204 ) ;
error = F_125 ( V_126 , V_2 ,
V_236 , V_238 ,
F_126 ( V_234 ) ,
V_245 ,
& V_204 , & V_203 ,
& V_239 ) ;
if ( error )
goto V_221;
error = F_104 ( & V_126 , & V_203 , V_2 ) ;
if ( error )
goto V_221;
error = F_78 ( & V_126 , V_2 ) ;
if ( error )
goto V_37;
}
error = F_127 ( V_2 , & V_126 , V_236 ,
V_237 ) ;
if ( error )
goto V_37;
if ( V_2 -> V_3 . V_151 == 0 && F_128 ( V_2 ) ) {
V_2 -> V_3 . V_12 &= ~ V_246 ;
F_129 ( V_2 ) ;
}
F_74 ( V_126 , V_2 , V_164 ) ;
F_130 ( V_2 , V_235 ) ;
V_37:
* V_188 = V_126 ;
return error ;
V_221:
F_107 ( & V_203 ) ;
goto V_37;
}
int
F_131 (
T_3 * V_2 )
{
T_16 * V_135 = V_2 -> V_7 ;
int error ;
if ( ! F_72 ( F_10 ( V_2 ) -> V_144 ) || ( F_10 ( V_2 ) -> V_144 == 0 ) )
return 0 ;
if ( V_135 -> V_222 & V_247 )
return 0 ;
if ( ! F_55 ( V_135 ) ) {
int V_248 ;
V_248 = F_132 ( V_2 , V_249 ) ;
if ( V_248 ) {
F_133 ( V_2 , V_250 ) ;
if ( V_2 -> V_251 > 0 ) {
error = F_134 ( F_10 ( V_2 ) -> V_252 ) ;
if ( error )
return error ;
}
}
}
if ( F_10 ( V_2 ) -> V_199 == 0 )
return 0 ;
if ( F_135 ( V_2 , false ) ) {
if ( F_136 ( V_2 , V_250 ) )
return 0 ;
error = F_137 ( V_135 , V_2 , true ) ;
if ( error && error != - V_253 )
return error ;
if ( V_2 -> V_251 )
F_138 ( V_2 , V_250 ) ;
}
return 0 ;
}
STATIC int
F_139 (
struct V_1 * V_2 )
{
struct V_134 * V_135 = V_2 -> V_7 ;
struct V_201 * V_126 ;
int error ;
error = F_94 ( V_135 , & F_92 ( V_135 ) -> V_254 , 0 , 0 , 0 , & V_126 ) ;
if ( error ) {
ASSERT ( F_55 ( V_135 ) ) ;
return error ;
}
F_6 ( V_2 , V_23 ) ;
F_73 ( V_126 , V_2 , 0 ) ;
V_2 -> V_3 . V_149 = 0 ;
F_74 ( V_126 , V_2 , V_164 ) ;
error = F_119 ( & V_126 , V_2 , V_255 , 0 ) ;
if ( error )
goto V_256;
ASSERT ( V_2 -> V_3 . V_150 == 0 ) ;
error = F_105 ( V_126 ) ;
if ( error )
goto V_257;
F_27 ( V_2 , V_23 ) ;
return 0 ;
V_256:
F_108 ( V_126 ) ;
V_257:
F_27 ( V_2 , V_23 ) ;
return error ;
}
STATIC int
F_140 (
struct V_1 * V_2 )
{
struct V_202 V_203 ;
T_15 V_204 ;
struct V_134 * V_135 = V_2 -> V_7 ;
struct V_201 * V_126 ;
int error ;
if ( F_116 ( V_135 -> V_258 ) ) {
error = F_94 ( V_135 , & F_92 ( V_135 ) -> V_259 ,
F_141 ( V_135 ) , 0 , V_260 ,
& V_126 ) ;
} else {
error = F_94 ( V_135 , & F_92 ( V_135 ) -> V_259 , 0 , 0 , 0 , & V_126 ) ;
}
if ( error ) {
if ( error == - V_195 ) {
F_142 ( V_135 ,
L_1
L_2 ) ;
} else {
ASSERT ( F_55 ( V_135 ) ) ;
}
return error ;
}
F_6 ( V_2 , V_23 ) ;
F_73 ( V_126 , V_2 , 0 ) ;
F_96 ( & V_203 , & V_204 ) ;
error = F_143 ( V_126 , V_2 , & V_203 ) ;
if ( error ) {
if ( ! F_55 ( V_135 ) ) {
F_144 ( V_135 , L_3 ,
V_261 , error ) ;
F_145 ( V_135 , V_262 ) ;
}
F_108 ( V_126 ) ;
F_27 ( V_2 , V_23 ) ;
return error ;
}
F_146 ( V_126 , V_2 , V_263 , - 1 ) ;
error = F_104 ( & V_126 , & V_203 , NULL ) ;
if ( error ) {
F_144 ( V_135 , L_4 ,
V_261 , error ) ;
F_107 ( & V_203 ) ;
}
error = F_105 ( V_126 ) ;
if ( error )
F_144 ( V_135 , L_5 ,
V_261 , error ) ;
F_27 ( V_2 , V_23 ) ;
return 0 ;
}
void
F_147 (
T_3 * V_2 )
{
struct V_134 * V_135 ;
int error ;
int V_264 = 0 ;
if ( F_10 ( V_2 ) -> V_144 == 0 ) {
ASSERT ( V_2 -> V_20 . V_184 == 0 ) ;
ASSERT ( V_2 -> V_20 . V_265 == 0 ) ;
return;
}
V_135 = V_2 -> V_7 ;
ASSERT ( ! F_136 ( V_2 , V_266 ) ) ;
if ( V_135 -> V_222 & V_247 )
return;
if ( F_10 ( V_2 ) -> V_199 != 0 ) {
if ( F_135 ( V_2 , true ) )
F_137 ( V_135 , V_2 , false ) ;
return;
}
if ( F_72 ( F_10 ( V_2 ) -> V_144 ) &&
( V_2 -> V_3 . V_149 != 0 || F_121 ( V_2 ) != 0 ||
V_2 -> V_3 . V_150 > 0 || V_2 -> V_251 > 0 ) )
V_264 = 1 ;
error = F_114 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_148 ( F_10 ( V_2 ) -> V_144 ) )
error = F_149 ( V_2 ) ;
else if ( V_264 )
error = F_139 ( V_2 ) ;
if ( error )
return;
if ( F_52 ( V_2 ) ) {
error = F_150 ( V_2 ) ;
if ( error )
return;
}
ASSERT ( ! V_2 -> V_25 ) ;
ASSERT ( V_2 -> V_3 . V_187 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_267 == 0 ) ;
error = F_140 ( V_2 ) ;
if ( error )
return;
F_151 ( V_2 ) ;
}
STATIC int
F_84 (
struct V_201 * V_126 ,
struct V_1 * V_2 )
{
T_16 * V_135 = V_126 -> V_136 ;
T_20 * V_268 ;
T_21 * V_269 ;
T_14 * V_270 ;
T_14 * V_271 ;
T_22 V_272 ;
short V_273 ;
int V_274 ;
int error ;
ASSERT ( F_10 ( V_2 ) -> V_144 != 0 ) ;
error = F_152 ( V_135 , V_126 , F_153 ( V_135 , V_2 -> V_74 ) , & V_270 ) ;
if ( error )
return error ;
V_268 = F_154 ( V_270 ) ;
V_272 = F_155 ( V_135 , V_2 -> V_74 ) ;
ASSERT ( V_272 != 0 ) ;
V_273 = V_272 % V_275 ;
ASSERT ( V_268 -> V_276 [ V_273 ] ) ;
ASSERT ( F_156 ( V_268 -> V_276 [ V_273 ] ) != V_272 ) ;
if ( V_268 -> V_276 [ V_273 ] != F_157 ( V_277 ) ) {
error = F_158 ( V_135 , V_126 , & V_2 -> V_278 , & V_269 , & V_271 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_269 -> V_279 == F_157 ( V_277 ) ) ;
V_269 -> V_279 = V_268 -> V_276 [ V_273 ] ;
V_274 = V_2 -> V_278 . V_280 +
F_159 ( T_21 , V_279 ) ;
F_160 ( V_135 , V_269 ) ;
F_161 ( V_126 , V_271 ) ;
F_162 ( V_126 , V_271 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
F_163 ( V_135 , V_271 ) ;
}
ASSERT ( V_272 != 0 ) ;
V_268 -> V_276 [ V_273 ] = F_157 ( V_272 ) ;
V_274 = F_159 ( T_20 , V_276 ) +
( sizeof( T_22 ) * V_273 ) ;
F_162 ( V_126 , V_270 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_118 (
T_9 * V_126 ,
T_3 * V_2 )
{
T_8 V_281 ;
T_16 * V_135 ;
T_20 * V_268 ;
T_21 * V_269 ;
T_14 * V_270 ;
T_14 * V_271 ;
T_23 V_282 ;
T_22 V_272 ;
T_22 V_283 ;
T_14 * V_284 ;
T_21 * V_285 = NULL ;
short V_273 ;
int V_274 , V_286 = 0 ;
int error ;
V_135 = V_126 -> V_136 ;
V_282 = F_153 ( V_135 , V_2 -> V_74 ) ;
error = F_152 ( V_135 , V_126 , V_282 , & V_270 ) ;
if ( error )
return error ;
V_268 = F_154 ( V_270 ) ;
V_272 = F_155 ( V_135 , V_2 -> V_74 ) ;
ASSERT ( V_272 != 0 ) ;
V_273 = V_272 % V_275 ;
ASSERT ( V_268 -> V_276 [ V_273 ] != F_157 ( V_277 ) ) ;
ASSERT ( V_268 -> V_276 [ V_273 ] ) ;
if ( F_156 ( V_268 -> V_276 [ V_273 ] ) == V_272 ) {
error = F_158 ( V_135 , V_126 , & V_2 -> V_278 , & V_269 , & V_271 ,
0 , 0 ) ;
if ( error ) {
F_164 ( V_135 , L_6 ,
V_261 , error ) ;
return error ;
}
V_283 = F_156 ( V_269 -> V_279 ) ;
ASSERT ( V_283 != 0 ) ;
if ( V_283 != V_277 ) {
V_269 -> V_279 = F_157 ( V_277 ) ;
V_274 = V_2 -> V_278 . V_280 +
F_159 ( T_21 , V_279 ) ;
F_160 ( V_135 , V_269 ) ;
F_161 ( V_126 , V_271 ) ;
F_162 ( V_126 , V_271 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
F_163 ( V_135 , V_271 ) ;
} else {
F_165 ( V_126 , V_271 ) ;
}
ASSERT ( V_283 != 0 ) ;
ASSERT ( V_283 != V_272 ) ;
V_268 -> V_276 [ V_273 ] = F_157 ( V_283 ) ;
V_274 = F_159 ( T_20 , V_276 ) +
( sizeof( T_22 ) * V_273 ) ;
F_162 ( V_126 , V_270 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
} else {
V_283 = F_156 ( V_268 -> V_276 [ V_273 ] ) ;
V_284 = NULL ;
while ( V_283 != V_272 ) {
struct V_287 V_288 ;
if ( V_284 )
F_165 ( V_126 , V_284 ) ;
V_288 . V_289 = 0 ;
V_281 = F_166 ( V_135 , V_282 , V_283 ) ;
error = V_287 ( V_135 , V_126 , V_281 , & V_288 , 0 ) ;
if ( error ) {
F_164 ( V_135 ,
L_7 ,
V_261 , error ) ;
return error ;
}
error = F_158 ( V_135 , V_126 , & V_288 , & V_285 ,
& V_284 , 0 , 0 ) ;
if ( error ) {
F_164 ( V_135 ,
L_6 ,
V_261 , error ) ;
return error ;
}
V_286 = V_288 . V_280 ;
V_283 = F_156 ( V_285 -> V_279 ) ;
ASSERT ( V_283 != V_277 ) ;
ASSERT ( V_283 != 0 ) ;
}
error = F_158 ( V_135 , V_126 , & V_2 -> V_278 , & V_269 , & V_271 ,
0 , 0 ) ;
if ( error ) {
F_164 ( V_135 , L_8 ,
V_261 , error ) ;
return error ;
}
V_283 = F_156 ( V_269 -> V_279 ) ;
ASSERT ( V_283 != 0 ) ;
ASSERT ( V_283 != V_272 ) ;
if ( V_283 != V_277 ) {
V_269 -> V_279 = F_157 ( V_277 ) ;
V_274 = V_2 -> V_278 . V_280 +
F_159 ( T_21 , V_279 ) ;
F_160 ( V_135 , V_269 ) ;
F_161 ( V_126 , V_271 ) ;
F_162 ( V_126 , V_271 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
F_163 ( V_135 , V_271 ) ;
} else {
F_165 ( V_126 , V_271 ) ;
}
V_285 -> V_279 = F_157 ( V_283 ) ;
ASSERT ( V_283 != 0 ) ;
V_274 = V_286 + F_159 ( T_21 , V_279 ) ;
F_160 ( V_135 , V_285 ) ;
F_161 ( V_126 , V_284 ) ;
F_162 ( V_126 , V_284 , V_274 ,
( V_274 + sizeof( T_22 ) - 1 ) ) ;
F_163 ( V_135 , V_284 ) ;
}
return 0 ;
}
STATIC int
F_167 (
T_3 * V_290 ,
T_9 * V_126 ,
struct V_291 * V_292 )
{
T_16 * V_135 = V_290 -> V_7 ;
int V_293 ;
int V_294 ;
int V_295 ;
int V_58 , V_59 ;
int V_296 ;
T_24 V_297 ;
T_14 * V_298 ;
T_3 * V_2 ;
T_25 * V_299 ;
T_4 * V_300 ;
struct V_301 * V_302 ;
T_8 V_122 ;
V_122 = V_292 -> V_303 ;
V_302 = F_168 ( V_135 , F_153 ( V_135 , V_122 ) ) ;
V_293 = F_169 ( V_135 ) ;
V_294 = V_293 << V_135 -> V_8 . V_304 ;
V_295 = V_135 -> V_305 / V_293 ;
for ( V_59 = 0 ; V_59 < V_295 ; V_59 ++ , V_122 += V_294 ) {
V_296 = V_122 - V_292 -> V_303 ;
if ( ( V_292 -> V_306 & F_170 ( V_296 ) ) == 0 ) {
ASSERT ( F_171 ( V_296 , V_294 ) == 0 ) ;
continue;
}
V_297 = F_172 ( V_135 , F_153 ( V_135 , V_122 ) ,
F_173 ( V_135 , V_122 ) ) ;
V_298 = F_174 ( V_126 , V_135 -> V_307 , V_297 ,
V_135 -> V_308 * V_293 ,
V_309 ) ;
if ( ! V_298 )
return - V_310 ;
V_298 -> V_311 = & V_312 ;
V_300 = V_298 -> V_313 ;
while ( V_300 ) {
if ( V_300 -> V_314 == V_315 ) {
V_299 = ( T_25 * ) V_300 ;
ASSERT ( V_299 -> V_316 == 1 ) ;
V_300 -> V_317 = V_318 ;
F_175 ( V_135 -> V_319 ,
& V_299 -> V_320 ,
& V_299 -> V_321 . V_322 ) ;
F_138 ( V_299 -> V_323 , V_324 ) ;
}
V_300 = V_300 -> V_325 ;
}
for ( V_58 = 0 ; V_58 < V_294 ; V_58 ++ ) {
V_326:
F_176 () ;
V_2 = F_177 ( & V_302 -> V_327 ,
F_155 ( V_135 , ( V_122 + V_58 ) ) ) ;
if ( ! V_2 ) {
F_178 () ;
continue;
}
F_179 ( & V_2 -> V_328 ) ;
if ( V_2 -> V_74 != V_122 + V_58 ||
F_180 ( V_2 , V_324 ) ) {
F_181 ( & V_2 -> V_328 ) ;
F_178 () ;
continue;
}
F_181 ( & V_2 -> V_328 ) ;
if ( V_2 != V_290 &&
! F_17 ( V_2 , V_23 ) ) {
F_178 () ;
F_39 ( 1 ) ;
goto V_326;
}
F_178 () ;
F_182 ( V_2 ) ;
F_138 ( V_2 , V_324 ) ;
V_299 = V_2 -> V_63 ;
if ( ! V_299 || F_183 ( V_2 ) ) {
ASSERT ( V_2 != V_290 ) ;
F_184 ( V_2 ) ;
F_27 ( V_2 , V_23 ) ;
continue;
}
V_299 -> V_329 = V_299 -> V_330 ;
V_299 -> V_330 = 0 ;
V_299 -> V_331 = 0 ;
V_299 -> V_316 = 1 ;
F_175 ( V_135 -> V_319 , & V_299 -> V_320 ,
& V_299 -> V_321 . V_322 ) ;
F_185 ( V_298 , V_318 ,
& V_299 -> V_321 ) ;
if ( V_2 != V_290 )
F_27 ( V_2 , V_23 ) ;
}
F_186 ( V_126 , V_298 ) ;
F_187 ( V_126 , V_298 ) ;
}
F_188 ( V_302 ) ;
return 0 ;
}
int
F_143 (
T_9 * V_126 ,
T_3 * V_2 ,
struct V_202 * V_203 )
{
int error ;
struct V_291 V_292 = { 0 } ;
ASSERT ( F_33 ( V_2 , V_23 ) ) ;
ASSERT ( F_10 ( V_2 ) -> V_199 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_150 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_187 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_149 == 0 || ! F_72 ( F_10 ( V_2 ) -> V_144 ) ) ;
ASSERT ( V_2 -> V_3 . V_151 == 0 ) ;
error = F_118 ( V_126 , V_2 ) ;
if ( error )
return error ;
error = F_189 ( V_126 , V_2 -> V_74 , V_203 , & V_292 ) ;
if ( error )
return error ;
F_10 ( V_2 ) -> V_144 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_155 = 0 ;
V_2 -> V_3 . V_267 = 0 ;
V_2 -> V_3 . V_18 = V_182 ;
V_2 -> V_3 . V_24 = V_182 ;
F_10 ( V_2 ) -> V_332 ++ ;
F_74 ( V_126 , V_2 , V_164 ) ;
if ( V_292 . V_333 )
error = F_167 ( V_2 , V_126 , & V_292 ) ;
return error ;
}
static void
F_190 (
struct V_1 * V_2 )
{
ASSERT ( F_33 ( V_2 , V_23 | V_17 ) ) ;
F_191 ( V_2 , V_27 ) ;
F_192 ( V_2 -> V_7 , V_2 -> V_63 -> V_334 , 0 ) ;
}
static void
F_193 (
struct V_1 * V_2 )
{
T_5 * V_75 = F_43 ( & V_2 -> V_76 , V_335 ) ;
F_44 ( V_78 , & V_2 -> V_76 , V_335 ) ;
F_190 ( V_2 ) ;
do {
F_194 ( V_75 , & V_78 . V_78 , V_79 ) ;
if ( F_195 ( V_2 ) )
F_47 () ;
} while ( F_195 ( V_2 ) );
F_49 ( V_75 , & V_78 . V_78 ) ;
}
void
F_196 (
struct V_1 * V_2 )
{
if ( F_195 ( V_2 ) )
F_193 ( V_2 ) ;
}
int
F_197 (
T_3 * V_117 ,
struct V_118 * V_119 ,
T_3 * V_2 )
{
T_16 * V_135 = V_117 -> V_7 ;
T_9 * V_126 = NULL ;
int V_200 = F_68 ( F_10 ( V_2 ) -> V_144 ) ;
int error = 0 ;
struct V_202 V_203 ;
T_15 V_204 ;
T_2 V_212 ;
F_198 ( V_117 , V_119 ) ;
if ( F_55 ( V_135 ) )
return - V_123 ;
error = F_114 ( V_117 , 0 ) ;
if ( error )
goto V_230;
error = F_114 ( V_2 , 0 ) ;
if ( error )
goto V_230;
V_212 = F_199 ( V_135 ) ;
error = F_94 ( V_135 , & F_92 ( V_135 ) -> V_336 , V_212 , 0 , 0 , & V_126 ) ;
if ( error == - V_195 ) {
V_212 = 0 ;
error = F_94 ( V_135 , & F_92 ( V_135 ) -> V_336 , 0 , 0 , 0 ,
& V_126 ) ;
}
if ( error ) {
ASSERT ( error != - V_195 ) ;
goto V_230;
}
F_41 ( V_117 , V_2 , V_23 ) ;
F_73 ( V_126 , V_117 , V_23 ) ;
F_73 ( V_126 , V_2 , V_23 ) ;
if ( V_200 ) {
ASSERT ( F_10 ( V_2 ) -> V_199 >= 2 ) ;
if ( F_10 ( V_2 ) -> V_199 != 2 ) {
error = - V_337 ;
goto V_219;
}
if ( ! F_200 ( V_2 ) ) {
error = - V_337 ;
goto V_219;
}
error = F_81 ( V_126 , V_117 ) ;
if ( error )
goto V_219;
error = F_81 ( V_126 , V_2 ) ;
if ( error )
goto V_219;
} else {
F_74 ( V_126 , V_117 , V_164 ) ;
}
F_82 ( V_126 , V_117 , V_220 | V_198 ) ;
error = F_81 ( V_126 , V_2 ) ;
if ( error )
goto V_219;
F_96 ( & V_203 , & V_204 ) ;
error = F_201 ( V_126 , V_117 , V_119 , V_2 -> V_74 ,
& V_204 , & V_203 , V_212 ) ;
if ( error ) {
ASSERT ( error != - V_338 ) ;
goto V_221;
}
if ( V_135 -> V_222 & ( V_223 | V_224 ) )
F_102 ( V_126 ) ;
error = F_104 ( & V_126 , & V_203 , NULL ) ;
if ( error )
goto V_221;
error = F_105 ( V_126 ) ;
if ( error )
goto V_230;
if ( V_200 && F_202 ( V_2 ) )
F_203 ( V_2 ) ;
return 0 ;
V_221:
F_107 ( & V_203 ) ;
V_219:
F_108 ( V_126 ) ;
V_230:
return error ;
}
STATIC void
F_204 (
struct V_1 * V_339 ,
struct V_1 * V_340 ,
struct V_1 * V_72 ,
struct V_1 * V_341 ,
struct V_1 * V_342 ,
struct V_1 * * V_343 ,
int * V_344 )
{
int V_58 , V_59 ;
ASSERT ( * V_344 == V_345 ) ;
memset ( V_343 , 0 , * V_344 * sizeof( struct V_1 * ) ) ;
V_58 = 0 ;
V_343 [ V_58 ++ ] = V_339 ;
V_343 [ V_58 ++ ] = V_340 ;
V_343 [ V_58 ++ ] = V_72 ;
if ( V_341 )
V_343 [ V_58 ++ ] = V_341 ;
if ( V_342 )
V_343 [ V_58 ++ ] = V_342 ;
* V_344 = V_58 ;
for ( V_58 = 0 ; V_58 < * V_344 ; V_58 ++ ) {
for ( V_59 = 1 ; V_59 < * V_344 ; V_59 ++ ) {
if ( V_343 [ V_59 ] -> V_74 < V_343 [ V_59 - 1 ] -> V_74 ) {
struct V_1 * V_73 = V_343 [ V_59 ] ;
V_343 [ V_59 ] = V_343 [ V_59 - 1 ] ;
V_343 [ V_59 - 1 ] = V_73 ;
}
}
}
}
static int
F_205 (
struct V_201 * V_126 ,
struct V_202 * V_203 )
{
int error ;
if ( V_126 -> V_136 -> V_222 & ( V_223 | V_224 ) )
F_102 ( V_126 ) ;
error = F_104 ( & V_126 , V_203 , NULL ) ;
if ( error ) {
F_107 ( V_203 ) ;
F_108 ( V_126 ) ;
return error ;
}
return F_105 ( V_126 ) ;
}
STATIC int
F_206 (
struct V_201 * V_126 ,
struct V_1 * V_339 ,
struct V_118 * V_346 ,
struct V_1 * V_72 ,
struct V_1 * V_340 ,
struct V_118 * V_347 ,
struct V_1 * V_341 ,
struct V_202 * V_203 ,
T_15 * V_204 ,
int V_348 )
{
int error = 0 ;
int V_349 = 0 ;
int V_350 = 0 ;
int V_351 = 0 ;
error = F_207 ( V_126 , V_339 , V_346 ,
V_341 -> V_74 ,
V_204 , V_203 , V_348 ) ;
if ( error )
goto V_352;
error = F_207 ( V_126 , V_340 , V_347 ,
V_72 -> V_74 ,
V_204 , V_203 , V_348 ) ;
if ( error )
goto V_352;
if ( V_339 != V_340 ) {
V_351 = V_220 | V_198 ;
if ( F_68 ( F_10 ( V_341 ) -> V_144 ) ) {
error = F_207 ( V_126 , V_341 , & V_353 ,
V_339 -> V_74 , V_204 ,
V_203 , V_348 ) ;
if ( error )
goto V_352;
if ( ! F_68 ( F_10 ( V_72 ) -> V_144 ) ) {
error = F_81 ( V_126 , V_340 ) ;
if ( error )
goto V_352;
error = F_85 ( V_126 , V_339 ) ;
if ( error )
goto V_352;
}
V_349 |= V_198 ;
V_350 |= V_220 | V_198 ;
}
if ( F_68 ( F_10 ( V_72 ) -> V_144 ) ) {
error = F_207 ( V_126 , V_72 , & V_353 ,
V_340 -> V_74 , V_204 ,
V_203 , V_348 ) ;
if ( error )
goto V_352;
if ( ! F_68 ( F_10 ( V_341 ) -> V_144 ) ) {
error = F_81 ( V_126 , V_339 ) ;
if ( error )
goto V_352;
error = F_85 ( V_126 , V_340 ) ;
if ( error )
goto V_352;
}
V_349 |= V_220 | V_198 ;
V_350 |= V_198 ;
}
}
if ( V_349 ) {
F_82 ( V_126 , V_72 , V_349 ) ;
F_74 ( V_126 , V_72 , V_164 ) ;
}
if ( V_350 ) {
F_82 ( V_126 , V_341 , V_350 ) ;
F_74 ( V_126 , V_341 , V_164 ) ;
}
if ( V_351 ) {
F_82 ( V_126 , V_340 , V_351 ) ;
F_74 ( V_126 , V_340 , V_164 ) ;
}
F_82 ( V_126 , V_339 , V_220 | V_198 ) ;
F_74 ( V_126 , V_339 , V_164 ) ;
return F_205 ( V_126 , V_203 ) ;
V_352:
F_107 ( V_203 ) ;
F_108 ( V_126 ) ;
return error ;
}
static int
F_208 (
struct V_1 * V_117 ,
struct V_1 * * V_342 )
{
struct V_1 * tmpfile ;
int error ;
error = F_111 ( V_117 , NULL , V_167 | V_354 , & tmpfile ) ;
if ( error )
return error ;
F_83 ( F_10 ( tmpfile ) ) ;
F_209 ( tmpfile ) ;
F_109 ( tmpfile ) ;
F_10 ( tmpfile ) -> V_355 |= V_356 ;
* V_342 = tmpfile ;
return 0 ;
}
int
F_210 (
struct V_1 * V_357 ,
struct V_118 * V_358 ,
struct V_1 * V_359 ,
struct V_1 * V_360 ,
struct V_118 * V_229 ,
struct V_1 * V_361 ,
unsigned int V_81 )
{
struct V_134 * V_135 = V_357 -> V_7 ;
struct V_201 * V_126 ;
struct V_202 V_203 ;
T_15 V_204 ;
struct V_1 * V_342 = NULL ;
struct V_1 * V_56 [ V_345 ] ;
int V_344 = V_345 ;
bool V_362 = ( V_357 != V_360 ) ;
bool V_363 = F_68 ( F_10 ( V_359 ) -> V_144 ) ;
int V_348 ;
int error ;
F_211 ( V_357 , V_360 , V_358 , V_229 ) ;
if ( ( V_81 & V_364 ) && ! V_361 )
return - V_365 ;
if ( V_81 & V_366 ) {
ASSERT ( ! ( V_81 & ( V_367 | V_364 ) ) ) ;
error = F_208 ( V_360 , & V_342 ) ;
if ( error )
return error ;
V_358 -> type = V_368 ;
}
F_204 ( V_357 , V_360 , V_359 , V_361 , V_342 ,
V_56 , & V_344 ) ;
V_348 = F_212 ( V_135 , V_229 -> V_215 ) ;
error = F_94 ( V_135 , & F_92 ( V_135 ) -> V_369 , V_348 , 0 , 0 , & V_126 ) ;
if ( error == - V_195 ) {
V_348 = 0 ;
error = F_94 ( V_135 , & F_92 ( V_135 ) -> V_369 , 0 , 0 , 0 ,
& V_126 ) ;
}
if ( error )
goto V_370;
error = F_213 ( V_56 ) ;
if ( error )
goto V_219;
F_38 ( V_56 , V_344 , V_23 ) ;
F_73 ( V_126 , V_357 , V_23 ) ;
if ( V_362 )
F_73 ( V_126 , V_360 , V_23 ) ;
F_73 ( V_126 , V_359 , V_23 ) ;
if ( V_361 )
F_73 ( V_126 , V_361 , V_23 ) ;
if ( V_342 )
F_73 ( V_126 , V_342 , V_23 ) ;
if ( F_116 ( ( V_360 -> V_3 . V_4 & V_99 ) &&
( F_117 ( V_360 ) != F_117 ( V_359 ) ) ) ) {
error = - V_232 ;
goto V_219;
}
F_96 ( & V_203 , & V_204 ) ;
if ( V_81 & V_364 )
return F_206 ( V_126 , V_357 , V_358 , V_359 ,
V_360 , V_229 , V_361 ,
& V_203 , & V_204 , V_348 ) ;
if ( V_361 == NULL ) {
if ( ! V_348 ) {
error = F_98 ( V_126 , V_360 , V_229 ) ;
if ( error )
goto V_219;
}
error = F_99 ( V_126 , V_360 , V_229 ,
V_359 -> V_74 , & V_204 ,
& V_203 , V_348 ) ;
if ( error )
goto V_221;
F_82 ( V_126 , V_360 ,
V_220 | V_198 ) ;
if ( V_362 && V_363 ) {
error = F_85 ( V_126 , V_360 ) ;
if ( error )
goto V_221;
}
} else {
if ( F_68 ( F_10 ( V_361 ) -> V_144 ) ) {
if ( ! ( F_200 ( V_361 ) ) ||
( F_10 ( V_361 ) -> V_199 > 2 ) ) {
error = - V_371 ;
goto V_219;
}
}
error = F_207 ( V_126 , V_360 , V_229 ,
V_359 -> V_74 ,
& V_204 , & V_203 , V_348 ) ;
if ( error )
goto V_221;
F_82 ( V_126 , V_360 ,
V_220 | V_198 ) ;
error = F_81 ( V_126 , V_361 ) ;
if ( error )
goto V_221;
if ( V_363 ) {
error = F_81 ( V_126 , V_361 ) ;
if ( error )
goto V_221;
}
}
if ( V_362 && V_363 ) {
error = F_207 ( V_126 , V_359 , & V_353 ,
V_360 -> V_74 ,
& V_204 , & V_203 , V_348 ) ;
ASSERT ( error != - V_371 ) ;
if ( error )
goto V_221;
}
F_82 ( V_126 , V_359 , V_198 ) ;
F_74 ( V_126 , V_359 , V_164 ) ;
if ( V_363 && ( V_362 || V_361 != NULL ) ) {
error = F_81 ( V_126 , V_357 ) ;
if ( error )
goto V_221;
}
if ( V_342 ) {
error = F_207 ( V_126 , V_357 , V_358 , V_342 -> V_74 ,
& V_204 , & V_203 , V_348 ) ;
} else
error = F_201 ( V_126 , V_357 , V_358 , V_359 -> V_74 ,
& V_204 , & V_203 , V_348 ) ;
if ( error )
goto V_221;
if ( V_342 ) {
ASSERT ( F_10 ( V_342 ) -> V_199 == 0 ) ;
error = F_85 ( V_126 , V_342 ) ;
if ( error )
goto V_221;
error = F_118 ( V_126 , V_342 ) ;
if ( error )
goto V_221;
F_74 ( V_126 , V_342 , V_164 ) ;
F_10 ( V_342 ) -> V_355 &= ~ V_356 ;
}
F_82 ( V_126 , V_357 , V_220 | V_198 ) ;
F_74 ( V_126 , V_357 , V_164 ) ;
if ( V_362 )
F_74 ( V_126 , V_360 , V_164 ) ;
error = F_205 ( V_126 , & V_203 ) ;
if ( V_342 )
F_110 ( V_342 ) ;
return error ;
V_221:
F_107 ( & V_203 ) ;
V_219:
F_108 ( V_126 ) ;
V_370:
if ( V_342 )
F_110 ( V_342 ) ;
return error ;
}
STATIC int
F_214 (
struct V_1 * V_2 ,
struct V_372 * V_298 )
{
struct V_134 * V_135 = V_2 -> V_7 ;
struct V_301 * V_302 ;
unsigned long V_373 , V_374 ;
unsigned long V_294 ;
int V_375 ;
struct V_1 * * V_376 ;
struct V_1 * V_377 ;
int V_378 ;
int V_379 = 0 ;
int V_380 ;
int V_58 ;
V_302 = F_168 ( V_135 , F_153 ( V_135 , V_2 -> V_74 ) ) ;
V_294 = V_135 -> V_381 >> V_135 -> V_8 . V_382 ;
V_375 = V_294 * sizeof( T_3 * ) ;
V_376 = F_215 ( V_375 , V_383 | V_384 ) ;
if ( ! V_376 )
goto V_385;
V_374 = ~ ( ( ( V_135 -> V_381 >> V_135 -> V_8 . V_382 ) ) - 1 ) ;
V_373 = F_155 ( V_135 , V_2 -> V_74 ) & V_374 ;
F_176 () ;
V_378 = F_216 ( & V_302 -> V_327 , ( void * * ) V_376 ,
V_373 , V_294 ) ;
if ( V_378 == 0 )
goto V_386;
for ( V_58 = 0 ; V_58 < V_378 ; V_58 ++ ) {
V_377 = V_376 [ V_58 ] ;
if ( V_377 == V_2 )
continue;
F_179 ( & V_377 -> V_328 ) ;
if ( ! V_377 -> V_74 ||
F_180 ( V_377 , V_324 ) ) {
F_181 ( & V_377 -> V_328 ) ;
continue;
}
if ( ( F_155 ( V_135 , V_377 -> V_74 ) & V_374 ) != V_373 ) {
F_181 ( & V_377 -> V_328 ) ;
break;
}
F_181 ( & V_377 -> V_328 ) ;
if ( F_183 ( V_377 ) && F_195 ( V_377 ) == 0 )
continue;
if ( ! F_17 ( V_377 , V_17 ) )
continue;
if ( ! F_48 ( V_377 ) ) {
F_27 ( V_377 , V_17 ) ;
continue;
}
if ( F_195 ( V_377 ) ) {
F_184 ( V_377 ) ;
F_27 ( V_377 , V_17 ) ;
continue;
}
if ( ! V_377 -> V_74 ) {
F_184 ( V_377 ) ;
F_27 ( V_377 , V_17 ) ;
continue;
}
if ( ! F_183 ( V_377 ) ) {
int error ;
error = F_217 ( V_377 , V_298 ) ;
if ( error ) {
F_27 ( V_377 , V_17 ) ;
goto V_387;
}
V_379 ++ ;
} else {
F_184 ( V_377 ) ;
}
F_27 ( V_377 , V_17 ) ;
}
if ( V_379 ) {
F_218 ( V_135 , V_388 ) ;
F_219 ( V_135 , V_389 , V_379 ) ;
}
V_386:
F_178 () ;
F_58 ( V_376 ) ;
V_385:
F_188 ( V_302 ) ;
return 0 ;
V_387:
F_178 () ;
V_380 = ( V_298 -> V_390 & V_391 ) ;
if ( V_380 )
F_79 ( V_298 ) ;
F_145 ( V_135 , V_392 ) ;
if ( ! V_380 ) {
if ( V_298 -> V_393 ) {
V_298 -> V_390 &= ~ V_394 ;
F_220 ( V_298 ) ;
F_221 ( V_298 , - V_123 ) ;
F_222 ( V_298 ) ;
} else {
F_220 ( V_298 ) ;
F_79 ( V_298 ) ;
}
}
F_223 ( V_377 , false ) ;
F_58 ( V_376 ) ;
F_188 ( V_302 ) ;
return - V_395 ;
}
int
F_224 (
struct V_1 * V_2 ,
struct V_372 * * V_396 )
{
struct V_134 * V_135 = V_2 -> V_7 ;
struct V_372 * V_298 = NULL ;
struct V_397 * V_269 ;
int error ;
F_218 ( V_135 , V_398 ) ;
ASSERT ( F_33 ( V_2 , V_23 | V_17 ) ) ;
ASSERT ( F_46 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_18 != V_19 ||
V_2 -> V_3 . V_150 > F_225 ( V_2 , V_255 ) ) ;
* V_396 = NULL ;
F_196 ( V_2 ) ;
if ( F_136 ( V_2 , V_324 ) ) {
F_184 ( V_2 ) ;
return 0 ;
}
if ( F_55 ( V_135 ) ) {
error = - V_123 ;
goto V_399;
}
error = F_158 ( V_135 , NULL , & V_2 -> V_278 , & V_269 , & V_298 , V_400 ,
0 ) ;
if ( error == - V_253 ) {
F_184 ( V_2 ) ;
return error ;
}
if ( error )
goto V_401;
error = F_217 ( V_2 , V_298 ) ;
if ( error )
goto V_401;
if ( F_226 ( V_298 ) )
F_227 ( V_135 , 0 ) ;
error = F_214 ( V_2 , V_298 ) ;
if ( error )
goto V_387;
* V_396 = V_298 ;
return 0 ;
V_401:
if ( V_298 )
F_79 ( V_298 ) ;
F_145 ( V_135 , V_392 ) ;
V_387:
error = - V_395 ;
V_399:
F_223 ( V_2 , false ) ;
return error ;
}
STATIC int
F_217 (
struct V_1 * V_2 ,
struct V_372 * V_298 )
{
struct V_402 * V_299 = V_2 -> V_63 ;
struct V_397 * V_269 ;
struct V_134 * V_135 = V_2 -> V_7 ;
ASSERT ( F_33 ( V_2 , V_23 | V_17 ) ) ;
ASSERT ( F_46 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_18 != V_19 ||
V_2 -> V_3 . V_150 > F_225 ( V_2 , V_255 ) ) ;
ASSERT ( V_299 != NULL && V_299 -> V_330 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_143 > 1 ) ;
V_269 = F_228 ( V_298 , V_2 -> V_278 . V_280 ) ;
if ( F_229 ( V_269 -> V_403 != F_230 ( V_404 ) ,
V_135 , V_405 , V_406 ) ) {
F_231 ( V_135 , V_407 ,
L_9 ,
V_261 , V_2 -> V_74 , F_232 ( V_269 -> V_403 ) , V_269 ) ;
goto V_401;
}
if ( F_72 ( F_10 ( V_2 ) -> V_144 ) ) {
if ( F_229 (
( V_2 -> V_3 . V_18 != V_182 ) &&
( V_2 -> V_3 . V_18 != V_19 ) ,
V_135 , V_408 , V_409 ) ) {
F_231 ( V_135 , V_407 ,
L_10 ,
V_261 , V_2 -> V_74 , V_2 ) ;
goto V_401;
}
} else if ( F_68 ( F_10 ( V_2 ) -> V_144 ) ) {
if ( F_229 (
( V_2 -> V_3 . V_18 != V_182 ) &&
( V_2 -> V_3 . V_18 != V_19 ) &&
( V_2 -> V_3 . V_18 != V_410 ) ,
V_135 , V_411 , V_412 ) ) {
F_231 ( V_135 , V_407 ,
L_11 ,
V_261 , V_2 -> V_74 , V_2 ) ;
goto V_401;
}
}
if ( F_229 ( V_2 -> V_3 . V_150 + V_2 -> V_3 . V_187 >
V_2 -> V_3 . V_151 , V_135 , V_413 ,
V_414 ) ) {
F_231 ( V_135 , V_407 ,
L_12
L_13 ,
V_261 , V_2 -> V_74 ,
V_2 -> V_3 . V_150 + V_2 -> V_3 . V_187 ,
V_2 -> V_3 . V_151 , V_2 ) ;
goto V_401;
}
if ( F_229 ( V_2 -> V_3 . V_267 > V_135 -> V_8 . V_415 ,
V_135 , V_416 , V_417 ) ) {
F_231 ( V_135 , V_407 ,
L_14 ,
V_261 , V_2 -> V_74 , V_2 -> V_3 . V_267 , V_2 ) ;
goto V_401;
}
if ( V_2 -> V_3 . V_143 < 3 )
V_2 -> V_3 . V_418 ++ ;
F_233 ( V_2 , V_269 , V_299 -> V_321 . V_322 ) ;
if ( V_2 -> V_3 . V_418 == V_419 )
V_2 -> V_3 . V_418 = 0 ;
F_234 ( V_2 , V_269 , V_299 , V_255 ) ;
if ( F_52 ( V_2 ) )
F_234 ( V_2 , V_269 , V_299 , V_420 ) ;
F_163 ( V_135 , V_298 ) ;
V_299 -> V_329 = V_299 -> V_330 ;
V_299 -> V_330 = 0 ;
V_299 -> V_331 = 0 ;
V_299 -> V_316 = 1 ;
F_175 ( V_135 -> V_319 , & V_299 -> V_320 ,
& V_299 -> V_321 . V_322 ) ;
F_185 ( V_298 , V_421 , & V_299 -> V_321 ) ;
F_160 ( V_135 , V_269 ) ;
ASSERT ( V_298 -> V_313 != NULL ) ;
ASSERT ( V_298 -> V_393 != NULL ) ;
return 0 ;
V_401:
return - V_395 ;
}
