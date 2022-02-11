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
struct V_137 * V_137 ;
error = F_53 ( V_123 , V_124 ? V_124 -> V_69 : 0 , V_125 , V_129 ,
V_130 , & V_134 ) ;
if ( error )
return error ;
if ( * V_130 || V_134 == V_138 ) {
* V_117 = NULL ;
return 0 ;
}
ASSERT ( * V_130 == NULL ) ;
error = F_50 ( V_132 , V_123 , V_134 , V_139 ,
V_17 , & V_2 ) ;
if ( error )
return error ;
ASSERT ( V_2 != NULL ) ;
V_137 = F_54 ( V_2 ) ;
if ( V_2 -> V_3 . V_140 == 1 )
V_2 -> V_3 . V_140 = 2 ;
V_137 -> V_141 = V_125 ;
F_55 ( V_137 , V_126 ) ;
V_2 -> V_3 . V_142 = F_56 ( F_57 () ) ;
V_2 -> V_3 . V_143 = F_58 ( F_59 () ) ;
F_60 ( V_2 , V_128 ) ;
if ( V_124 && F_61 ( V_124 ) ) {
V_2 -> V_3 . V_143 = V_124 -> V_3 . V_143 ;
if ( ( F_54 ( V_124 ) -> V_141 & V_144 ) && F_62 ( V_125 ) )
V_137 -> V_141 |= V_144 ;
}
if ( ( V_145 ) &&
( V_137 -> V_141 & V_144 ) &&
( ! F_63 ( F_64 ( V_2 -> V_3 . V_143 ) ) ) )
V_137 -> V_141 &= ~ V_144 ;
V_2 -> V_3 . V_146 = 0 ;
V_2 -> V_3 . V_147 = 0 ;
ASSERT ( V_2 -> V_3 . V_148 == 0 ) ;
V_136 = F_65 ( V_132 -> V_149 ) ;
V_137 -> V_150 = V_136 ;
V_137 -> V_151 = V_136 ;
V_137 -> V_152 = V_136 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_153 = 0 ;
V_2 -> V_3 . V_154 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( V_2 -> V_3 . V_140 == 3 ) {
V_137 -> V_155 = 1 ;
V_2 -> V_3 . V_75 = 0 ;
V_2 -> V_3 . V_156 . V_157 = ( V_158 ) V_136 . V_159 ;
V_2 -> V_3 . V_156 . V_160 = ( V_158 ) V_136 . V_161 ;
}
V_77 = V_162 ;
switch ( V_125 & V_163 ) {
case V_164 :
case V_165 :
case V_166 :
case V_167 :
V_2 -> V_3 . V_12 = V_168 ;
V_2 -> V_14 . V_169 . V_170 = V_127 ;
V_2 -> V_14 . V_15 = 0 ;
V_77 |= V_171 ;
break;
case V_172 :
case V_173 :
if ( V_124 && ( V_124 -> V_3 . V_4 & V_78 ) ) {
T_7 V_75 = 0 ;
T_2 V_4 = 0 ;
if ( F_62 ( V_125 ) ) {
if ( V_124 -> V_3 . V_4 & V_93 )
V_4 |= V_93 ;
if ( V_124 -> V_3 . V_4 & V_100 ) {
V_4 |= V_100 ;
V_2 -> V_3 . V_6 = V_124 -> V_3 . V_6 ;
}
if ( V_124 -> V_3 . V_4 & V_95 )
V_4 |= V_95 ;
} else if ( F_66 ( V_125 ) ) {
if ( V_124 -> V_3 . V_4 & V_93 )
V_4 |= V_79 ;
if ( V_124 -> V_3 . V_4 & V_100 ) {
V_4 |= V_5 ;
V_2 -> V_3 . V_6 = V_124 -> V_3 . V_6 ;
}
}
if ( ( V_124 -> V_3 . V_4 & V_89 ) &&
V_174 )
V_4 |= V_89 ;
if ( ( V_124 -> V_3 . V_4 & V_91 ) &&
V_175 )
V_4 |= V_91 ;
if ( ( V_124 -> V_3 . V_4 & V_87 ) &&
V_176 )
V_4 |= V_87 ;
if ( ( V_124 -> V_3 . V_4 & V_97 ) &&
V_177 )
V_4 |= V_97 ;
if ( ( V_124 -> V_3 . V_4 & V_102 ) &&
V_178 )
V_4 |= V_102 ;
if ( V_124 -> V_3 . V_4 & V_104 )
V_4 |= V_104 ;
if ( V_124 -> V_3 . V_75 & V_107 )
V_75 |= V_107 ;
V_2 -> V_3 . V_4 |= V_4 ;
V_2 -> V_3 . V_75 |= V_75 ;
}
case V_179 :
V_2 -> V_3 . V_12 = V_180 ;
V_2 -> V_14 . V_15 = V_16 ;
V_2 -> V_14 . V_181 = V_2 -> V_14 . V_182 = 0 ;
V_2 -> V_14 . V_183 . V_184 = NULL ;
break;
default:
ASSERT ( 0 ) ;
}
V_2 -> V_3 . V_18 = V_180 ;
V_2 -> V_3 . V_185 = 0 ;
F_67 ( V_123 , V_2 , V_17 ) ;
F_68 ( V_123 , V_2 , V_77 ) ;
F_69 ( V_2 ) ;
* V_117 = V_2 ;
return 0 ;
}
int
F_70 (
T_9 * * V_186 ,
T_3 * V_114 ,
T_10 V_125 ,
T_11 V_126 ,
T_12 V_127 ,
T_13 V_128 ,
int V_129 ,
T_3 * * V_117 ,
int * V_187 )
{
T_9 * V_123 ;
T_3 * V_2 ;
T_14 * V_130 = NULL ;
int V_188 ;
void * V_189 ;
T_2 V_190 ;
V_123 = * V_186 ;
ASSERT ( V_123 -> V_191 & V_192 ) ;
V_188 = F_52 ( V_123 , V_114 , V_125 , V_126 , V_127 , V_128 , V_129 ,
& V_130 , & V_2 ) ;
if ( V_188 ) {
* V_117 = NULL ;
return V_188 ;
}
if ( ! V_130 && ! V_2 ) {
* V_117 = NULL ;
return - V_193 ;
}
if ( V_130 ) {
F_71 ( V_123 , V_130 ) ;
V_189 = NULL ;
V_190 = 0 ;
if ( V_123 -> V_194 ) {
V_189 = ( void * ) V_123 -> V_194 ;
V_123 -> V_194 = NULL ;
V_190 = V_123 -> V_191 & V_195 ;
V_123 -> V_191 &= ~ ( V_195 ) ;
}
V_188 = F_72 ( & V_123 , 0 ) ;
if ( V_187 != NULL )
* V_187 = 1 ;
if ( V_189 ) {
V_123 -> V_194 = V_189 ;
V_123 -> V_191 |= V_190 ;
}
if ( V_188 ) {
F_73 ( V_130 ) ;
* V_186 = V_123 ;
* V_117 = NULL ;
return V_188 ;
}
F_74 ( V_123 , V_130 ) ;
V_188 = F_52 ( V_123 , V_114 , V_125 , V_126 , V_127 , V_128 ,
V_129 , & V_130 , & V_2 ) ;
if ( V_188 ) {
* V_186 = V_123 ;
* V_117 = NULL ;
return V_188 ;
}
ASSERT ( ! V_130 && V_2 ) ;
} else {
if ( V_187 != NULL )
* V_187 = 0 ;
}
* V_117 = V_2 ;
* V_186 = V_123 ;
return 0 ;
}
int
F_75 (
T_9 * V_123 ,
T_3 * V_2 )
{
F_76 ( V_123 , V_2 , V_196 ) ;
F_77 ( F_54 ( V_2 ) ) ;
F_68 ( V_123 , V_2 , V_162 ) ;
if ( F_54 ( V_2 ) -> V_197 )
return 0 ;
return F_78 ( V_123 , V_2 ) ;
}
int
F_79 (
T_9 * V_123 ,
T_3 * V_2 )
{
F_76 ( V_123 , V_2 , V_196 ) ;
ASSERT ( V_2 -> V_3 . V_140 > 1 ) ;
F_80 ( F_54 ( V_2 ) ) ;
F_68 ( V_123 , V_2 , V_162 ) ;
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
int V_198 = F_62 ( V_125 ) ;
struct V_131 * V_132 = V_114 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_199 * V_123 = NULL ;
int error ;
T_15 V_200 ;
T_16 V_201 ;
bool V_202 = false ;
T_13 V_128 ;
struct V_203 * V_204 = NULL ;
struct V_203 * V_205 = NULL ;
struct V_203 * V_206 = NULL ;
struct V_207 * V_208 ;
T_2 V_209 ;
F_82 ( V_114 , V_116 ) ;
if ( F_48 ( V_132 ) )
return - V_120 ;
V_128 = F_83 ( V_114 ) ;
error = F_84 ( V_114 , F_56 ( F_57 () ) ,
F_58 ( F_59 () ) , V_128 ,
V_210 | V_211 ,
& V_204 , & V_205 , & V_206 ) ;
if ( error )
return error ;
if ( V_198 ) {
V_127 = 0 ;
V_209 = F_85 ( V_132 , V_116 -> V_212 ) ;
V_208 = & F_86 ( V_132 ) -> V_213 ;
V_123 = F_87 ( V_132 , V_214 ) ;
} else {
V_209 = F_88 ( V_132 , V_116 -> V_212 ) ;
V_208 = & F_86 ( V_132 ) -> V_215 ;
V_123 = F_87 ( V_132 , V_216 ) ;
}
error = F_89 ( V_123 , V_208 , V_209 , 0 ) ;
if ( error == - V_193 ) {
F_90 ( V_132 ) ;
error = F_89 ( V_123 , V_208 , V_209 , 0 ) ;
}
if ( error == - V_193 ) {
V_209 = 0 ;
error = F_89 ( V_123 , V_208 , 0 , 0 ) ;
}
if ( error )
goto V_217;
F_4 ( V_114 , V_23 | V_17 |
V_45 | V_39 ) ;
V_202 = true ;
F_91 ( & V_200 , & V_201 ) ;
error = F_92 ( V_123 , V_132 , V_204 , V_205 ,
V_206 , V_209 , 1 , 0 ) ;
if ( error )
goto V_217;
if ( ! V_209 ) {
error = F_93 ( V_123 , V_114 , V_116 ) ;
if ( error )
goto V_217;
}
error = F_70 ( & V_123 , V_114 , V_125 , V_198 ? 2 : 1 , V_127 ,
V_128 , V_209 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_217;
F_67 ( V_123 , V_114 , V_23 | V_17 ) ;
V_202 = false ;
error = F_94 ( V_123 , V_114 , V_116 , V_2 -> V_69 ,
& V_201 , & V_200 , V_209 ?
V_209 - F_95 ( V_132 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_193 ) ;
goto V_217;
}
F_76 ( V_123 , V_114 , V_218 | V_196 ) ;
F_68 ( V_123 , V_114 , V_162 ) ;
if ( V_198 ) {
error = F_96 ( V_123 , V_2 , V_114 ) ;
if ( error )
goto V_219;
error = F_79 ( V_123 , V_114 ) ;
if ( error )
goto V_219;
}
if ( V_132 -> V_220 & ( V_221 | V_222 ) )
F_97 ( V_123 ) ;
F_98 ( V_123 , V_2 , V_204 , V_205 , V_206 ) ;
error = F_99 ( & V_123 , & V_200 , NULL ) ;
if ( error )
goto V_219;
error = F_100 ( V_123 ) ;
if ( error )
goto V_223;
F_101 ( V_204 ) ;
F_101 ( V_205 ) ;
F_101 ( V_206 ) ;
* V_117 = V_2 ;
return 0 ;
V_219:
F_102 ( & V_200 ) ;
V_217:
F_103 ( V_123 ) ;
V_223:
if ( V_2 ) {
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
}
F_101 ( V_204 ) ;
F_101 ( V_205 ) ;
F_101 ( V_206 ) ;
if ( V_202 )
F_18 ( V_114 , V_23 | V_17 ) ;
return error ;
}
int
F_106 (
struct V_1 * V_114 ,
struct V_224 * V_224 ,
T_10 V_125 ,
struct V_1 * * V_117 )
{
struct V_131 * V_132 = V_114 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_199 * V_123 = NULL ;
int error ;
T_13 V_128 ;
struct V_203 * V_204 = NULL ;
struct V_203 * V_205 = NULL ;
struct V_203 * V_206 = NULL ;
struct V_207 * V_208 ;
T_2 V_209 ;
if ( F_48 ( V_132 ) )
return - V_120 ;
V_128 = F_83 ( V_114 ) ;
error = F_84 ( V_114 , F_56 ( F_57 () ) ,
F_58 ( F_59 () ) , V_128 ,
V_210 | V_211 ,
& V_204 , & V_205 , & V_206 ) ;
if ( error )
return error ;
V_209 = F_95 ( V_132 ) ;
V_123 = F_87 ( V_132 , V_225 ) ;
V_208 = & F_86 ( V_132 ) -> V_226 ;
error = F_89 ( V_123 , V_208 , V_209 , 0 ) ;
if ( error == - V_193 ) {
V_209 = 0 ;
error = F_89 ( V_123 , V_208 , 0 , 0 ) ;
}
if ( error )
goto V_217;
error = F_92 ( V_123 , V_132 , V_204 , V_205 ,
V_206 , V_209 , 1 , 0 ) ;
if ( error )
goto V_217;
error = F_70 ( & V_123 , V_114 , V_125 , 1 , 0 ,
V_128 , V_209 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_217;
if ( V_132 -> V_220 & V_221 )
F_97 ( V_123 ) ;
F_98 ( V_123 , V_2 , V_204 , V_205 , V_206 ) ;
error = F_78 ( V_123 , V_2 ) ;
if ( error )
goto V_217;
error = F_100 ( V_123 ) ;
if ( error )
goto V_223;
F_101 ( V_204 ) ;
F_101 ( V_205 ) ;
F_101 ( V_206 ) ;
* V_117 = V_2 ;
return 0 ;
V_217:
F_103 ( V_123 ) ;
V_223:
if ( V_2 ) {
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
}
F_101 ( V_204 ) ;
F_101 ( V_205 ) ;
F_101 ( V_206 ) ;
return error ;
}
int
F_107 (
T_3 * V_227 ,
T_3 * V_228 ,
struct V_115 * V_229 )
{
T_17 * V_132 = V_227 -> V_7 ;
T_9 * V_123 ;
int error ;
T_15 V_200 ;
T_16 V_201 ;
int V_209 ;
F_108 ( V_227 , V_229 ) ;
ASSERT ( ! F_62 ( F_54 ( V_228 ) -> V_141 ) ) ;
if ( F_48 ( V_132 ) )
return - V_120 ;
error = F_109 ( V_228 , 0 ) ;
if ( error )
goto V_230;
error = F_109 ( V_227 , 0 ) ;
if ( error )
goto V_230;
V_123 = F_87 ( V_132 , V_231 ) ;
V_209 = F_110 ( V_132 , V_229 -> V_212 ) ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_232 , V_209 , 0 ) ;
if ( error == - V_193 ) {
V_209 = 0 ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_232 , 0 , 0 ) ;
}
if ( error )
goto V_233;
F_4 ( V_227 , V_23 | V_45 ) ;
F_30 ( V_228 , V_227 , V_17 ) ;
F_67 ( V_123 , V_228 , V_17 ) ;
F_67 ( V_123 , V_227 , V_23 | V_17 ) ;
if ( F_111 ( ( V_227 -> V_3 . V_4 & V_95 ) &&
( F_112 ( V_227 ) != F_112 ( V_228 ) ) ) ) {
error = - V_234 ;
goto V_233;
}
if ( ! V_209 ) {
error = F_93 ( V_123 , V_227 , V_229 ) ;
if ( error )
goto V_233;
}
F_91 ( & V_200 , & V_201 ) ;
if ( F_54 ( V_228 ) -> V_197 == 0 ) {
error = F_113 ( V_123 , V_228 ) ;
if ( error )
goto V_233;
}
error = F_94 ( V_123 , V_227 , V_229 , V_228 -> V_69 ,
& V_201 , & V_200 , V_209 ) ;
if ( error )
goto V_233;
F_76 ( V_123 , V_227 , V_218 | V_196 ) ;
F_68 ( V_123 , V_227 , V_162 ) ;
error = F_79 ( V_123 , V_228 ) ;
if ( error )
goto V_233;
if ( V_132 -> V_220 & ( V_221 | V_222 ) )
F_97 ( V_123 ) ;
error = F_99 ( & V_123 , & V_200 , NULL ) ;
if ( error ) {
F_102 ( & V_200 ) ;
goto V_233;
}
return F_100 ( V_123 ) ;
V_233:
F_103 ( V_123 ) ;
V_230:
return error ;
}
int
F_114 (
struct V_199 * * V_186 ,
struct V_1 * V_2 ,
int V_235 ,
T_18 V_236 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_199 * V_123 = * V_186 ;
T_15 V_200 ;
T_16 V_201 ;
T_19 V_237 ;
T_19 V_238 ;
T_20 V_239 ;
int error = 0 ;
int V_240 = 0 ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( ! F_115 ( & F_54 ( V_2 ) -> V_241 ) ||
F_23 ( V_2 , V_23 ) ) ;
ASSERT ( V_236 <= F_116 ( V_2 ) ) ;
ASSERT ( V_123 -> V_191 & V_192 ) ;
ASSERT ( V_2 -> V_58 != NULL ) ;
ASSERT ( V_2 -> V_58 -> V_242 == 0 ) ;
ASSERT ( ! F_117 ( V_132 , V_2 ) ) ;
F_118 ( V_2 , V_236 ) ;
V_237 = F_119 ( V_132 , ( V_243 ) V_236 ) ;
V_238 = F_119 ( V_132 , V_132 -> V_149 -> V_244 ) ;
if ( V_237 == V_238 )
return 0 ;
ASSERT ( V_237 < V_238 ) ;
V_239 = V_238 - V_237 + 1 ;
while ( ! V_240 ) {
F_91 ( & V_200 , & V_201 ) ;
error = F_120 ( V_123 , V_2 ,
V_237 , V_239 ,
F_121 ( V_235 ) ,
V_245 ,
& V_201 , & V_200 ,
& V_240 ) ;
if ( error )
goto V_219;
error = F_99 ( & V_123 , & V_200 , V_2 ) ;
if ( error )
goto V_219;
error = F_72 ( & V_123 , V_2 ) ;
if ( error )
goto V_31;
}
F_68 ( V_123 , V_2 , V_162 ) ;
F_122 ( V_2 , V_236 ) ;
V_31:
* V_186 = V_123 ;
return error ;
V_219:
F_102 ( & V_200 ) ;
goto V_31;
}
int
F_123 (
T_3 * V_2 )
{
T_17 * V_132 = V_2 -> V_7 ;
int error ;
if ( ! F_66 ( F_54 ( V_2 ) -> V_141 ) || ( F_54 ( V_2 ) -> V_141 == 0 ) )
return 0 ;
if ( V_132 -> V_220 & V_246 )
return 0 ;
if ( ! F_48 ( V_132 ) ) {
int V_247 ;
V_247 = F_124 ( V_2 , V_248 ) ;
if ( V_247 ) {
F_125 ( V_2 , V_249 ) ;
if ( V_2 -> V_250 > 0 ) {
error = F_126 ( F_54 ( V_2 ) -> V_251 ) ;
if ( error )
return error ;
}
}
}
if ( F_54 ( V_2 ) -> V_197 == 0 )
return 0 ;
if ( F_127 ( V_2 , false ) ) {
if ( F_128 ( V_2 , V_249 ) )
return 0 ;
error = F_129 ( V_132 , V_2 , true ) ;
if ( error && error != - V_252 )
return error ;
if ( V_2 -> V_250 )
F_130 ( V_2 , V_249 ) ;
}
return 0 ;
}
STATIC int
F_131 (
struct V_1 * V_2 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_199 * V_123 ;
int error ;
V_123 = F_87 ( V_132 , V_253 ) ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_254 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_48 ( V_132 ) ) ;
F_103 ( V_123 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_67 ( V_123 , V_2 , 0 ) ;
V_2 -> V_3 . V_146 = 0 ;
F_68 ( V_123 , V_2 , V_162 ) ;
error = F_114 ( & V_123 , V_2 , V_255 , 0 ) ;
if ( error )
goto V_256;
ASSERT ( V_2 -> V_3 . V_147 == 0 ) ;
error = F_100 ( V_123 ) ;
if ( error )
goto V_257;
F_18 ( V_2 , V_17 ) ;
return 0 ;
V_256:
F_103 ( V_123 ) ;
V_257:
F_18 ( V_2 , V_17 ) ;
return error ;
}
STATIC int
F_132 (
struct V_1 * V_2 )
{
T_15 V_200 ;
T_16 V_201 ;
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_199 * V_123 ;
int error ;
V_123 = F_87 ( V_132 , V_253 ) ;
V_123 -> V_191 |= V_258 ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_259 ,
F_133 ( V_132 ) , 0 ) ;
if ( error ) {
if ( error == - V_193 ) {
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
F_67 ( V_123 , V_2 , 0 ) ;
F_91 ( & V_200 , & V_201 ) ;
error = F_135 ( V_123 , V_2 , & V_200 ) ;
if ( error ) {
if ( ! F_48 ( V_132 ) ) {
F_136 ( V_132 , L_3 ,
V_260 , error ) ;
F_137 ( V_132 , V_261 ) ;
}
F_103 ( V_123 ) ;
F_18 ( V_2 , V_17 ) ;
return error ;
}
F_138 ( V_123 , V_2 , V_262 , - 1 ) ;
error = F_99 ( & V_123 , & V_200 , NULL ) ;
if ( error ) {
F_136 ( V_132 , L_4 ,
V_260 , error ) ;
F_102 ( & V_200 ) ;
}
error = F_100 ( V_123 ) ;
if ( error )
F_136 ( V_132 , L_5 ,
V_260 , error ) ;
F_18 ( V_2 , V_17 ) ;
return 0 ;
}
void
F_139 (
T_3 * V_2 )
{
struct V_131 * V_132 ;
int error ;
int V_263 = 0 ;
if ( F_54 ( V_2 ) -> V_141 == 0 ) {
ASSERT ( V_2 -> V_14 . V_182 == 0 ) ;
ASSERT ( V_2 -> V_14 . V_264 == 0 ) ;
return;
}
V_132 = V_2 -> V_7 ;
if ( V_132 -> V_220 & V_246 )
return;
if ( F_54 ( V_2 ) -> V_197 != 0 ) {
if ( F_127 ( V_2 , true ) )
F_129 ( V_132 , V_2 , false ) ;
return;
}
if ( F_66 ( F_54 ( V_2 ) -> V_141 ) &&
( V_2 -> V_3 . V_146 != 0 || F_116 ( V_2 ) != 0 ||
V_2 -> V_3 . V_147 > 0 || V_2 -> V_250 > 0 ) )
V_263 = 1 ;
error = F_109 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_140 ( F_54 ( V_2 ) -> V_141 ) )
error = F_141 ( V_2 ) ;
else if ( V_263 )
error = F_131 ( V_2 ) ;
if ( error )
return;
if ( F_41 ( V_2 ) ) {
error = F_142 ( V_2 ) ;
if ( error )
return;
}
ASSERT ( ! V_2 -> V_19 ) ;
ASSERT ( V_2 -> V_3 . V_185 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_265 == 0 ) ;
error = F_132 ( V_2 ) ;
if ( error )
return;
F_143 ( V_2 ) ;
}
STATIC int
F_78 (
struct V_199 * V_123 ,
struct V_1 * V_2 )
{
T_17 * V_132 = V_123 -> V_133 ;
T_21 * V_266 ;
T_22 * V_113 ;
T_14 * V_267 ;
T_14 * V_268 ;
T_23 V_269 ;
short V_270 ;
int V_271 ;
int error ;
ASSERT ( F_54 ( V_2 ) -> V_141 != 0 ) ;
error = F_144 ( V_132 , V_123 , F_145 ( V_132 , V_2 -> V_69 ) , & V_267 ) ;
if ( error )
return error ;
V_266 = F_146 ( V_267 ) ;
V_269 = F_147 ( V_132 , V_2 -> V_69 ) ;
ASSERT ( V_269 != 0 ) ;
V_270 = V_269 % V_272 ;
ASSERT ( V_266 -> V_273 [ V_270 ] ) ;
ASSERT ( F_148 ( V_266 -> V_273 [ V_270 ] ) != V_269 ) ;
if ( V_266 -> V_273 [ V_270 ] != F_149 ( V_274 ) ) {
error = F_150 ( V_132 , V_123 , & V_2 -> V_275 , & V_113 , & V_268 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_113 -> V_276 == F_149 ( V_274 ) ) ;
V_113 -> V_276 = V_266 -> V_273 [ V_270 ] ;
V_271 = V_2 -> V_275 . V_277 +
F_151 ( T_22 , V_276 ) ;
F_152 ( V_132 , V_113 ) ;
F_153 ( V_123 , V_268 ) ;
F_154 ( V_123 , V_268 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
F_155 ( V_132 , V_268 ) ;
}
ASSERT ( V_269 != 0 ) ;
V_266 -> V_273 [ V_270 ] = F_149 ( V_269 ) ;
V_271 = F_151 ( T_21 , V_273 ) +
( sizeof( T_23 ) * V_270 ) ;
F_156 ( V_123 , V_267 , V_278 ) ;
F_154 ( V_123 , V_267 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_113 (
T_9 * V_123 ,
T_3 * V_2 )
{
T_8 V_279 ;
T_17 * V_132 ;
T_21 * V_266 ;
T_22 * V_113 ;
T_14 * V_267 ;
T_14 * V_268 ;
T_24 V_280 ;
T_23 V_269 ;
T_23 V_281 ;
T_14 * V_282 ;
T_22 * V_283 = NULL ;
short V_270 ;
int V_271 , V_284 = 0 ;
int error ;
V_132 = V_123 -> V_133 ;
V_280 = F_145 ( V_132 , V_2 -> V_69 ) ;
error = F_144 ( V_132 , V_123 , V_280 , & V_267 ) ;
if ( error )
return error ;
V_266 = F_146 ( V_267 ) ;
V_269 = F_147 ( V_132 , V_2 -> V_69 ) ;
ASSERT ( V_269 != 0 ) ;
V_270 = V_269 % V_272 ;
ASSERT ( V_266 -> V_273 [ V_270 ] != F_149 ( V_274 ) ) ;
ASSERT ( V_266 -> V_273 [ V_270 ] ) ;
if ( F_148 ( V_266 -> V_273 [ V_270 ] ) == V_269 ) {
error = F_150 ( V_132 , V_123 , & V_2 -> V_275 , & V_113 , & V_268 ,
0 , 0 ) ;
if ( error ) {
F_157 ( V_132 , L_6 ,
V_260 , error ) ;
return error ;
}
V_281 = F_148 ( V_113 -> V_276 ) ;
ASSERT ( V_281 != 0 ) ;
if ( V_281 != V_274 ) {
V_113 -> V_276 = F_149 ( V_274 ) ;
V_271 = V_2 -> V_275 . V_277 +
F_151 ( T_22 , V_276 ) ;
F_152 ( V_132 , V_113 ) ;
F_153 ( V_123 , V_268 ) ;
F_154 ( V_123 , V_268 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
F_155 ( V_132 , V_268 ) ;
} else {
F_158 ( V_123 , V_268 ) ;
}
ASSERT ( V_281 != 0 ) ;
ASSERT ( V_281 != V_269 ) ;
V_266 -> V_273 [ V_270 ] = F_149 ( V_281 ) ;
V_271 = F_151 ( T_21 , V_273 ) +
( sizeof( T_23 ) * V_270 ) ;
F_156 ( V_123 , V_267 , V_278 ) ;
F_154 ( V_123 , V_267 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
} else {
V_281 = F_148 ( V_266 -> V_273 [ V_270 ] ) ;
V_282 = NULL ;
while ( V_281 != V_269 ) {
struct V_285 V_286 ;
if ( V_282 )
F_158 ( V_123 , V_282 ) ;
V_286 . V_287 = 0 ;
V_279 = F_159 ( V_132 , V_280 , V_281 ) ;
error = V_285 ( V_132 , V_123 , V_279 , & V_286 , 0 ) ;
if ( error ) {
F_157 ( V_132 ,
L_7 ,
V_260 , error ) ;
return error ;
}
error = F_150 ( V_132 , V_123 , & V_286 , & V_283 ,
& V_282 , 0 , 0 ) ;
if ( error ) {
F_157 ( V_132 ,
L_6 ,
V_260 , error ) ;
return error ;
}
V_284 = V_286 . V_277 ;
V_281 = F_148 ( V_283 -> V_276 ) ;
ASSERT ( V_281 != V_274 ) ;
ASSERT ( V_281 != 0 ) ;
}
error = F_150 ( V_132 , V_123 , & V_2 -> V_275 , & V_113 , & V_268 ,
0 , 0 ) ;
if ( error ) {
F_157 ( V_132 , L_8 ,
V_260 , error ) ;
return error ;
}
V_281 = F_148 ( V_113 -> V_276 ) ;
ASSERT ( V_281 != 0 ) ;
ASSERT ( V_281 != V_269 ) ;
if ( V_281 != V_274 ) {
V_113 -> V_276 = F_149 ( V_274 ) ;
V_271 = V_2 -> V_275 . V_277 +
F_151 ( T_22 , V_276 ) ;
F_152 ( V_132 , V_113 ) ;
F_153 ( V_123 , V_268 ) ;
F_154 ( V_123 , V_268 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
F_155 ( V_132 , V_268 ) ;
} else {
F_158 ( V_123 , V_268 ) ;
}
V_283 -> V_276 = F_149 ( V_281 ) ;
ASSERT ( V_281 != 0 ) ;
V_271 = V_284 + F_151 ( T_22 , V_276 ) ;
F_152 ( V_132 , V_283 ) ;
F_153 ( V_123 , V_282 ) ;
F_154 ( V_123 , V_282 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
F_155 ( V_132 , V_282 ) ;
}
return 0 ;
}
STATIC int
F_160 (
T_3 * V_288 ,
T_9 * V_123 ,
struct V_289 * V_290 )
{
T_17 * V_132 = V_288 -> V_7 ;
int V_291 ;
int V_292 ;
int V_293 ;
int V_53 , V_54 ;
int V_294 ;
T_25 V_295 ;
T_14 * V_296 ;
T_3 * V_2 ;
T_26 * V_297 ;
T_4 * V_298 ;
struct V_299 * V_300 ;
T_8 V_119 ;
V_119 = V_290 -> V_301 ;
V_300 = F_161 ( V_132 , F_145 ( V_132 , V_119 ) ) ;
V_291 = F_162 ( V_132 ) ;
V_292 = V_291 << V_132 -> V_8 . V_302 ;
V_293 = V_132 -> V_303 / V_291 ;
for ( V_54 = 0 ; V_54 < V_293 ; V_54 ++ , V_119 += V_292 ) {
V_294 = V_119 - V_290 -> V_301 ;
if ( ( V_290 -> V_304 & F_163 ( V_294 ) ) == 0 ) {
ASSERT ( F_164 ( V_294 , V_292 ) == 0 ) ;
continue;
}
V_295 = F_165 ( V_132 , F_145 ( V_132 , V_119 ) ,
F_166 ( V_132 , V_119 ) ) ;
V_296 = F_167 ( V_123 , V_132 -> V_305 , V_295 ,
V_132 -> V_306 * V_291 ,
V_307 ) ;
if ( ! V_296 )
return - V_308 ;
V_296 -> V_309 = & V_310 ;
V_298 = V_296 -> V_311 ;
while ( V_298 ) {
if ( V_298 -> V_312 == V_313 ) {
V_297 = ( T_26 * ) V_298 ;
ASSERT ( V_297 -> V_314 == 1 ) ;
V_298 -> V_315 = V_316 ;
F_168 ( V_132 -> V_317 ,
& V_297 -> V_318 ,
& V_297 -> V_319 . V_320 ) ;
F_130 ( V_297 -> V_321 , V_322 ) ;
}
V_298 = V_298 -> V_323 ;
}
for ( V_53 = 0 ; V_53 < V_292 ; V_53 ++ ) {
V_324:
F_169 () ;
V_2 = F_170 ( & V_300 -> V_325 ,
F_147 ( V_132 , ( V_119 + V_53 ) ) ) ;
if ( ! V_2 ) {
F_171 () ;
continue;
}
F_172 ( & V_2 -> V_326 ) ;
if ( V_2 -> V_69 != V_119 + V_53 ||
F_173 ( V_2 , V_322 ) ) {
F_174 ( & V_2 -> V_326 ) ;
F_171 () ;
continue;
}
F_174 ( & V_2 -> V_326 ) ;
if ( V_2 != V_288 &&
! F_12 ( V_2 , V_17 ) ) {
F_171 () ;
F_28 ( 1 ) ;
goto V_324;
}
F_171 () ;
F_175 ( V_2 ) ;
F_130 ( V_2 , V_322 ) ;
V_297 = V_2 -> V_58 ;
if ( ! V_297 || F_176 ( V_2 ) ) {
ASSERT ( V_2 != V_288 ) ;
F_177 ( V_2 ) ;
F_18 ( V_2 , V_17 ) ;
continue;
}
V_297 -> V_327 = V_297 -> V_328 ;
V_297 -> V_328 = 0 ;
V_297 -> V_329 = 0 ;
V_297 -> V_314 = 1 ;
F_168 ( V_132 -> V_317 , & V_297 -> V_318 ,
& V_297 -> V_319 . V_320 ) ;
F_178 ( V_296 , V_316 ,
& V_297 -> V_319 ) ;
if ( V_2 != V_288 )
F_18 ( V_2 , V_17 ) ;
}
F_179 ( V_123 , V_296 ) ;
F_180 ( V_123 , V_296 ) ;
}
F_181 ( V_300 ) ;
return 0 ;
}
int
F_135 (
T_9 * V_123 ,
T_3 * V_2 ,
T_15 * V_330 )
{
int error ;
struct V_289 V_290 = { 0 } ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( F_54 ( V_2 ) -> V_197 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_147 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_185 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_146 == 0 || ! F_66 ( F_54 ( V_2 ) -> V_141 ) ) ;
ASSERT ( V_2 -> V_3 . V_148 == 0 ) ;
error = F_113 ( V_123 , V_2 ) ;
if ( error )
return error ;
error = F_182 ( V_123 , V_2 -> V_69 , V_330 , & V_290 ) ;
if ( error )
return error ;
F_54 ( V_2 ) -> V_141 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_153 = 0 ;
V_2 -> V_3 . V_265 = 0 ;
V_2 -> V_3 . V_12 = V_180 ;
V_2 -> V_3 . V_18 = V_180 ;
F_54 ( V_2 ) -> V_331 ++ ;
F_68 ( V_123 , V_2 , V_162 ) ;
if ( V_290 . V_332 )
error = F_160 ( V_2 , V_123 , & V_290 ) ;
return error ;
}
static void
F_183 (
struct V_1 * V_2 )
{
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
F_184 ( V_2 , V_21 ) ;
F_185 ( V_2 -> V_7 , V_2 -> V_58 -> V_333 , 0 ) ;
}
static void
F_186 (
struct V_1 * V_2 )
{
T_5 * V_70 = F_32 ( & V_2 -> V_71 , V_334 ) ;
F_33 ( V_73 , & V_2 -> V_71 , V_334 ) ;
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
int V_198 = F_62 ( F_54 ( V_2 ) -> V_141 ) ;
int error = 0 ;
T_15 V_200 ;
T_16 V_201 ;
T_2 V_209 ;
F_191 ( V_114 , V_116 ) ;
if ( F_48 ( V_132 ) )
return - V_120 ;
error = F_109 ( V_114 , 0 ) ;
if ( error )
goto V_230;
error = F_109 ( V_2 , 0 ) ;
if ( error )
goto V_230;
if ( V_198 )
V_123 = F_87 ( V_132 , V_335 ) ;
else
V_123 = F_87 ( V_132 , V_336 ) ;
V_209 = F_192 ( V_132 ) ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_337 , V_209 , 0 ) ;
if ( error == - V_193 ) {
V_209 = 0 ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_337 , 0 , 0 ) ;
}
if ( error ) {
ASSERT ( error != - V_193 ) ;
goto V_217;
}
F_4 ( V_114 , V_23 | V_45 ) ;
F_30 ( V_114 , V_2 , V_17 ) ;
F_67 ( V_123 , V_114 , V_23 | V_17 ) ;
F_67 ( V_123 , V_2 , V_17 ) ;
if ( V_198 ) {
ASSERT ( F_54 ( V_2 ) -> V_197 >= 2 ) ;
if ( F_54 ( V_2 ) -> V_197 != 2 ) {
error = - V_338 ;
goto V_217;
}
if ( ! F_193 ( V_2 ) ) {
error = - V_338 ;
goto V_217;
}
error = F_75 ( V_123 , V_114 ) ;
if ( error )
goto V_217;
error = F_75 ( V_123 , V_2 ) ;
if ( error )
goto V_217;
} else {
F_68 ( V_123 , V_114 , V_162 ) ;
}
F_76 ( V_123 , V_114 , V_218 | V_196 ) ;
error = F_75 ( V_123 , V_2 ) ;
if ( error )
goto V_217;
F_91 ( & V_200 , & V_201 ) ;
error = F_194 ( V_123 , V_114 , V_116 , V_2 -> V_69 ,
& V_201 , & V_200 , V_209 ) ;
if ( error ) {
ASSERT ( error != - V_339 ) ;
goto V_219;
}
if ( V_132 -> V_220 & ( V_221 | V_222 ) )
F_97 ( V_123 ) ;
error = F_99 ( & V_123 , & V_200 , NULL ) ;
if ( error )
goto V_219;
error = F_100 ( V_123 ) ;
if ( error )
goto V_230;
if ( V_198 && F_195 ( V_2 ) )
F_196 ( V_2 ) ;
return 0 ;
V_219:
F_102 ( & V_200 ) ;
V_217:
F_103 ( V_123 ) ;
V_230:
return error ;
}
STATIC void
F_197 (
struct V_1 * V_340 ,
struct V_1 * V_341 ,
struct V_1 * V_67 ,
struct V_1 * V_342 ,
struct V_1 * V_343 ,
struct V_1 * * V_344 ,
int * V_345 )
{
int V_53 , V_54 ;
ASSERT ( * V_345 == V_346 ) ;
memset ( V_344 , 0 , * V_345 * sizeof( struct V_1 * ) ) ;
V_53 = 0 ;
V_344 [ V_53 ++ ] = V_340 ;
V_344 [ V_53 ++ ] = V_341 ;
V_344 [ V_53 ++ ] = V_67 ;
if ( V_342 )
V_344 [ V_53 ++ ] = V_342 ;
if ( V_343 )
V_344 [ V_53 ++ ] = V_343 ;
* V_345 = V_53 ;
for ( V_53 = 0 ; V_53 < * V_345 ; V_53 ++ ) {
for ( V_54 = 1 ; V_54 < * V_345 ; V_54 ++ ) {
if ( V_344 [ V_54 ] -> V_69 < V_344 [ V_54 - 1 ] -> V_69 ) {
struct V_1 * V_68 = V_344 [ V_54 ] ;
V_344 [ V_54 ] = V_344 [ V_54 - 1 ] ;
V_344 [ V_54 - 1 ] = V_68 ;
}
}
}
}
static int
F_198 (
struct V_199 * V_123 ,
struct V_347 * V_200 )
{
int error ;
if ( V_123 -> V_133 -> V_220 & ( V_221 | V_222 ) )
F_97 ( V_123 ) ;
error = F_99 ( & V_123 , V_200 , NULL ) ;
if ( error ) {
F_102 ( V_200 ) ;
F_103 ( V_123 ) ;
return error ;
}
return F_100 ( V_123 ) ;
}
STATIC int
F_199 (
struct V_199 * V_123 ,
struct V_1 * V_340 ,
struct V_115 * V_348 ,
struct V_1 * V_67 ,
struct V_1 * V_341 ,
struct V_115 * V_349 ,
struct V_1 * V_342 ,
struct V_347 * V_200 ,
T_16 * V_201 ,
int V_350 )
{
int error = 0 ;
int V_351 = 0 ;
int V_352 = 0 ;
int V_353 = 0 ;
error = F_200 ( V_123 , V_340 , V_348 ,
V_342 -> V_69 ,
V_201 , V_200 , V_350 ) ;
if ( error )
goto V_354;
error = F_200 ( V_123 , V_341 , V_349 ,
V_67 -> V_69 ,
V_201 , V_200 , V_350 ) ;
if ( error )
goto V_354;
if ( V_340 != V_341 ) {
V_353 = V_218 | V_196 ;
if ( F_62 ( F_54 ( V_342 ) -> V_141 ) ) {
error = F_200 ( V_123 , V_342 , & V_355 ,
V_340 -> V_69 , V_201 ,
V_200 , V_350 ) ;
if ( error )
goto V_354;
if ( ! F_62 ( F_54 ( V_67 ) -> V_141 ) ) {
error = F_75 ( V_123 , V_341 ) ;
if ( error )
goto V_354;
error = F_79 ( V_123 , V_340 ) ;
if ( error )
goto V_354;
}
V_351 |= V_196 ;
V_352 |= V_218 | V_196 ;
}
if ( F_62 ( F_54 ( V_67 ) -> V_141 ) ) {
error = F_200 ( V_123 , V_67 , & V_355 ,
V_341 -> V_69 , V_201 ,
V_200 , V_350 ) ;
if ( error )
goto V_354;
if ( ! F_62 ( F_54 ( V_342 ) -> V_141 ) ) {
error = F_75 ( V_123 , V_340 ) ;
if ( error )
goto V_354;
error = F_79 ( V_123 , V_341 ) ;
if ( error )
goto V_354;
}
V_351 |= V_218 | V_196 ;
V_352 |= V_196 ;
}
}
if ( V_351 ) {
F_76 ( V_123 , V_67 , V_351 ) ;
F_68 ( V_123 , V_67 , V_162 ) ;
}
if ( V_352 ) {
F_76 ( V_123 , V_342 , V_352 ) ;
F_68 ( V_123 , V_342 , V_162 ) ;
}
if ( V_353 ) {
F_76 ( V_123 , V_341 , V_353 ) ;
F_68 ( V_123 , V_341 , V_162 ) ;
}
F_76 ( V_123 , V_340 , V_218 | V_196 ) ;
F_68 ( V_123 , V_340 , V_162 ) ;
return F_198 ( V_123 , V_200 ) ;
V_354:
F_102 ( V_200 ) ;
F_103 ( V_123 ) ;
return error ;
}
static int
F_201 (
struct V_1 * V_114 ,
struct V_1 * * V_343 )
{
struct V_1 * tmpfile ;
int error ;
error = F_106 ( V_114 , NULL , V_165 | V_356 , & tmpfile ) ;
if ( error )
return error ;
F_77 ( F_54 ( tmpfile ) ) ;
F_104 ( tmpfile ) ;
F_54 ( tmpfile ) -> V_357 |= V_358 ;
* V_343 = tmpfile ;
return 0 ;
}
int
F_202 (
struct V_1 * V_359 ,
struct V_115 * V_360 ,
struct V_1 * V_361 ,
struct V_1 * V_362 ,
struct V_115 * V_229 ,
struct V_1 * V_363 ,
unsigned int V_77 )
{
struct V_131 * V_132 = V_359 -> V_7 ;
struct V_199 * V_123 ;
struct V_347 V_200 ;
T_16 V_201 ;
struct V_1 * V_343 = NULL ;
struct V_1 * V_51 [ V_346 ] ;
int V_345 = V_346 ;
bool V_364 = ( V_359 != V_362 ) ;
bool V_365 = F_62 ( F_54 ( V_361 ) -> V_141 ) ;
int V_350 ;
int error ;
F_203 ( V_359 , V_362 , V_360 , V_229 ) ;
if ( ( V_77 & V_366 ) && ! V_363 )
return - V_367 ;
if ( V_77 & V_368 ) {
ASSERT ( ! ( V_77 & ( V_369 | V_366 ) ) ) ;
error = F_201 ( V_362 , & V_343 ) ;
if ( error )
return error ;
V_360 -> type = V_370 ;
}
F_197 ( V_359 , V_362 , V_361 , V_363 , V_343 ,
V_51 , & V_345 ) ;
V_123 = F_87 ( V_132 , V_371 ) ;
V_350 = F_204 ( V_132 , V_229 -> V_212 ) ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_372 , V_350 , 0 ) ;
if ( error == - V_193 ) {
V_350 = 0 ;
error = F_89 ( V_123 , & F_86 ( V_132 ) -> V_372 , 0 , 0 ) ;
}
if ( error )
goto V_217;
error = F_205 ( V_51 ) ;
if ( error )
goto V_217;
if ( ! V_364 )
F_4 ( V_359 , V_23 | V_45 ) ;
else
F_30 ( V_359 , V_362 ,
V_23 | V_45 ) ;
F_27 ( V_51 , V_345 , V_17 ) ;
F_67 ( V_123 , V_359 , V_23 | V_17 ) ;
if ( V_364 )
F_67 ( V_123 , V_362 , V_23 | V_17 ) ;
F_67 ( V_123 , V_361 , V_17 ) ;
if ( V_363 )
F_67 ( V_123 , V_363 , V_17 ) ;
if ( V_343 )
F_67 ( V_123 , V_343 , V_17 ) ;
if ( F_111 ( ( V_362 -> V_3 . V_4 & V_95 ) &&
( F_112 ( V_362 ) != F_112 ( V_361 ) ) ) ) {
error = - V_234 ;
goto V_217;
}
F_91 ( & V_200 , & V_201 ) ;
if ( V_77 & V_366 )
return F_199 ( V_123 , V_359 , V_360 , V_361 ,
V_362 , V_229 , V_363 ,
& V_200 , & V_201 , V_350 ) ;
if ( V_363 == NULL ) {
if ( ! V_350 ) {
error = F_93 ( V_123 , V_362 , V_229 ) ;
if ( error )
goto V_217;
}
error = F_94 ( V_123 , V_362 , V_229 ,
V_361 -> V_69 , & V_201 ,
& V_200 , V_350 ) ;
if ( error )
goto V_219;
F_76 ( V_123 , V_362 ,
V_218 | V_196 ) ;
if ( V_364 && V_365 ) {
error = F_79 ( V_123 , V_362 ) ;
if ( error )
goto V_219;
}
} else {
if ( F_62 ( F_54 ( V_363 ) -> V_141 ) ) {
if ( ! ( F_193 ( V_363 ) ) ||
( F_54 ( V_363 ) -> V_197 > 2 ) ) {
error = - V_373 ;
goto V_217;
}
}
error = F_200 ( V_123 , V_362 , V_229 ,
V_361 -> V_69 ,
& V_201 , & V_200 , V_350 ) ;
if ( error )
goto V_219;
F_76 ( V_123 , V_362 ,
V_218 | V_196 ) ;
error = F_75 ( V_123 , V_363 ) ;
if ( error )
goto V_219;
if ( V_365 ) {
error = F_75 ( V_123 , V_363 ) ;
if ( error )
goto V_219;
}
}
if ( V_364 && V_365 ) {
error = F_200 ( V_123 , V_361 , & V_355 ,
V_362 -> V_69 ,
& V_201 , & V_200 , V_350 ) ;
ASSERT ( error != - V_373 ) ;
if ( error )
goto V_219;
}
F_76 ( V_123 , V_361 , V_196 ) ;
F_68 ( V_123 , V_361 , V_162 ) ;
if ( V_365 && ( V_364 || V_363 != NULL ) ) {
error = F_75 ( V_123 , V_359 ) ;
if ( error )
goto V_219;
}
if ( V_343 ) {
error = F_200 ( V_123 , V_359 , V_360 , V_343 -> V_69 ,
& V_201 , & V_200 , V_350 ) ;
} else
error = F_194 ( V_123 , V_359 , V_360 , V_361 -> V_69 ,
& V_201 , & V_200 , V_350 ) ;
if ( error )
goto V_219;
if ( V_343 ) {
ASSERT ( F_54 ( V_343 ) -> V_197 == 0 ) ;
error = F_79 ( V_123 , V_343 ) ;
if ( error )
goto V_219;
error = F_113 ( V_123 , V_343 ) ;
if ( error )
goto V_219;
F_68 ( V_123 , V_343 , V_162 ) ;
F_54 ( V_343 ) -> V_357 &= ~ V_358 ;
}
F_76 ( V_123 , V_359 , V_218 | V_196 ) ;
F_68 ( V_123 , V_359 , V_162 ) ;
if ( V_364 )
F_68 ( V_123 , V_362 , V_162 ) ;
error = F_198 ( V_123 , & V_200 ) ;
if ( V_343 )
F_105 ( V_343 ) ;
return error ;
V_219:
F_102 ( & V_200 ) ;
V_217:
F_103 ( V_123 ) ;
if ( V_343 )
F_105 ( V_343 ) ;
return error ;
}
STATIC int
F_206 (
T_3 * V_2 ,
T_14 * V_296 )
{
T_17 * V_132 = V_2 -> V_7 ;
struct V_299 * V_300 ;
unsigned long V_374 , V_375 ;
unsigned long V_292 ;
int V_376 ;
T_3 * * V_377 ;
T_3 * V_378 ;
int V_379 ;
int V_380 = 0 ;
int V_381 ;
int V_53 ;
V_300 = F_161 ( V_132 , F_145 ( V_132 , V_2 -> V_69 ) ) ;
V_292 = V_132 -> V_382 >> V_132 -> V_8 . V_383 ;
V_376 = V_292 * sizeof( T_3 * ) ;
V_377 = F_207 ( V_376 , V_384 | V_385 ) ;
if ( ! V_377 )
goto V_386;
V_375 = ~ ( ( ( V_132 -> V_382 >> V_132 -> V_8 . V_383 ) ) - 1 ) ;
V_374 = F_147 ( V_132 , V_2 -> V_69 ) & V_375 ;
F_169 () ;
V_379 = F_208 ( & V_300 -> V_325 , ( void * * ) V_377 ,
V_374 , V_292 ) ;
if ( V_379 == 0 )
goto V_387;
for ( V_53 = 0 ; V_53 < V_379 ; V_53 ++ ) {
V_378 = V_377 [ V_53 ] ;
if ( V_378 == V_2 )
continue;
F_172 ( & V_2 -> V_326 ) ;
if ( ! V_2 -> V_69 ||
( F_147 ( V_132 , V_378 -> V_69 ) & V_375 ) != V_374 ) {
F_174 ( & V_2 -> V_326 ) ;
continue;
}
F_174 ( & V_2 -> V_326 ) ;
if ( F_176 ( V_378 ) && F_188 ( V_378 ) == 0 )
continue;
if ( ! F_12 ( V_378 , V_11 ) )
continue;
if ( ! F_37 ( V_378 ) ) {
F_18 ( V_378 , V_11 ) ;
continue;
}
if ( F_188 ( V_378 ) ) {
F_177 ( V_378 ) ;
F_18 ( V_378 , V_11 ) ;
continue;
}
if ( ! F_176 ( V_378 ) ) {
int error ;
error = F_209 ( V_378 , V_296 ) ;
if ( error ) {
F_18 ( V_378 , V_11 ) ;
goto V_388;
}
V_380 ++ ;
} else {
F_177 ( V_378 ) ;
}
F_18 ( V_378 , V_11 ) ;
}
if ( V_380 ) {
F_210 ( V_132 , V_389 ) ;
F_211 ( V_132 , V_390 , V_380 ) ;
}
V_387:
F_171 () ;
F_51 ( V_377 ) ;
V_386:
F_181 ( V_300 ) ;
return 0 ;
V_388:
F_171 () ;
V_381 = ( V_296 -> V_391 & V_392 ) ;
if ( V_381 )
F_73 ( V_296 ) ;
F_137 ( V_132 , V_393 ) ;
if ( ! V_381 ) {
if ( V_296 -> V_394 ) {
V_296 -> V_391 &= ~ V_395 ;
F_212 ( V_296 ) ;
F_213 ( V_296 , - V_120 ) ;
F_214 ( V_296 ) ;
} else {
F_212 ( V_296 ) ;
F_73 ( V_296 ) ;
}
}
F_215 ( V_378 , false ) ;
F_51 ( V_377 ) ;
F_181 ( V_300 ) ;
return - V_396 ;
}
int
F_216 (
struct V_1 * V_2 ,
struct V_397 * * V_398 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_397 * V_296 ;
struct V_112 * V_113 ;
int error ;
F_210 ( V_132 , V_399 ) ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_147 > F_217 ( V_2 , V_255 ) ) ;
* V_398 = NULL ;
F_189 ( V_2 ) ;
if ( F_128 ( V_2 , V_322 ) ) {
F_177 ( V_2 ) ;
return 0 ;
}
if ( F_48 ( V_132 ) ) {
error = - V_120 ;
goto V_400;
}
error = F_150 ( V_132 , NULL , & V_2 -> V_275 , & V_113 , & V_296 , V_401 ,
0 ) ;
if ( error || ! V_296 ) {
F_177 ( V_2 ) ;
return error ;
}
error = F_209 ( V_2 , V_296 ) ;
if ( error )
goto V_402;
if ( F_218 ( V_296 ) )
F_219 ( V_132 , 0 ) ;
error = F_206 ( V_2 , V_296 ) ;
if ( error )
goto V_388;
* V_398 = V_296 ;
return 0 ;
V_402:
F_73 ( V_296 ) ;
F_137 ( V_132 , V_393 ) ;
V_388:
error = - V_396 ;
V_400:
F_215 ( V_2 , false ) ;
return error ;
}
STATIC int
F_209 (
struct V_1 * V_2 ,
struct V_397 * V_296 )
{
struct V_403 * V_297 = V_2 -> V_58 ;
struct V_112 * V_113 ;
struct V_131 * V_132 = V_2 -> V_7 ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_147 > F_217 ( V_2 , V_255 ) ) ;
ASSERT ( V_297 != NULL && V_297 -> V_328 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_140 > 1 ) ;
V_113 = F_220 ( V_296 , V_2 -> V_275 . V_277 ) ;
if ( F_221 ( V_113 -> V_404 != F_222 ( V_405 ) ,
V_132 , V_406 , V_407 ) ) {
F_223 ( V_132 , V_408 ,
L_9 ,
V_260 , V_2 -> V_69 , F_43 ( V_113 -> V_404 ) , V_113 ) ;
goto V_402;
}
if ( F_66 ( F_54 ( V_2 ) -> V_141 ) ) {
if ( F_221 (
( V_2 -> V_3 . V_12 != V_180 ) &&
( V_2 -> V_3 . V_12 != V_13 ) ,
V_132 , V_409 , V_410 ) ) {
F_223 ( V_132 , V_408 ,
L_10 ,
V_260 , V_2 -> V_69 , V_2 ) ;
goto V_402;
}
} else if ( F_62 ( F_54 ( V_2 ) -> V_141 ) ) {
if ( F_221 (
( V_2 -> V_3 . V_12 != V_180 ) &&
( V_2 -> V_3 . V_12 != V_13 ) &&
( V_2 -> V_3 . V_12 != V_411 ) ,
V_132 , V_412 , V_413 ) ) {
F_223 ( V_132 , V_408 ,
L_11 ,
V_260 , V_2 -> V_69 , V_2 ) ;
goto V_402;
}
}
if ( F_221 ( V_2 -> V_3 . V_147 + V_2 -> V_3 . V_185 >
V_2 -> V_3 . V_148 , V_132 , V_414 ,
V_415 ) ) {
F_223 ( V_132 , V_408 ,
L_12
L_13 ,
V_260 , V_2 -> V_69 ,
V_2 -> V_3 . V_147 + V_2 -> V_3 . V_185 ,
V_2 -> V_3 . V_148 , V_2 ) ;
goto V_402;
}
if ( F_221 ( V_2 -> V_3 . V_265 > V_132 -> V_8 . V_416 ,
V_132 , V_417 , V_418 ) ) {
F_223 ( V_132 , V_408 ,
L_14 ,
V_260 , V_2 -> V_69 , V_2 -> V_3 . V_265 , V_2 ) ;
goto V_402;
}
if ( V_2 -> V_3 . V_140 < 3 )
V_2 -> V_3 . V_419 ++ ;
F_224 ( V_2 , V_113 , V_297 -> V_319 . V_320 ) ;
if ( V_2 -> V_3 . V_419 == V_420 )
V_2 -> V_3 . V_419 = 0 ;
F_225 ( V_2 , V_113 , V_297 , V_255 ) ;
if ( F_41 ( V_2 ) )
F_225 ( V_2 , V_113 , V_297 , V_421 ) ;
F_155 ( V_132 , V_296 ) ;
V_297 -> V_327 = V_297 -> V_328 ;
V_297 -> V_328 = 0 ;
V_297 -> V_329 = 0 ;
V_297 -> V_314 = 1 ;
F_168 ( V_132 -> V_317 , & V_297 -> V_318 ,
& V_297 -> V_319 . V_320 ) ;
F_178 ( V_296 , V_422 , & V_297 -> V_319 ) ;
F_152 ( V_132 , V_113 ) ;
ASSERT ( V_296 -> V_311 != NULL ) ;
ASSERT ( V_296 -> V_394 != NULL ) ;
return 0 ;
V_402:
return - V_396 ;
}
