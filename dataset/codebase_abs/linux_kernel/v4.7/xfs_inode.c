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
V_188 = F_72 ( & V_123 , NULL ) ;
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
} else {
V_209 = F_87 ( V_132 , V_116 -> V_212 ) ;
V_208 = & F_86 ( V_132 ) -> V_214 ;
}
error = F_88 ( V_132 , V_208 , V_209 , 0 , 0 , & V_123 ) ;
if ( error == - V_193 ) {
F_89 ( V_132 ) ;
error = F_88 ( V_132 , V_208 , V_209 , 0 , 0 , & V_123 ) ;
}
if ( error == - V_193 ) {
V_209 = 0 ;
error = F_88 ( V_132 , V_208 , 0 , 0 , 0 , & V_123 ) ;
}
if ( error )
goto V_215;
F_4 ( V_114 , V_23 | V_17 |
V_45 | V_39 ) ;
V_202 = true ;
F_90 ( & V_200 , & V_201 ) ;
error = F_91 ( V_123 , V_132 , V_204 , V_205 ,
V_206 , V_209 , 1 , 0 ) ;
if ( error )
goto V_216;
if ( ! V_209 ) {
error = F_92 ( V_123 , V_114 , V_116 ) ;
if ( error )
goto V_216;
}
error = F_70 ( & V_123 , V_114 , V_125 , V_198 ? 2 : 1 , V_127 ,
V_128 , V_209 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_216;
F_67 ( V_123 , V_114 , V_23 | V_17 ) ;
V_202 = false ;
error = F_93 ( V_123 , V_114 , V_116 , V_2 -> V_69 ,
& V_201 , & V_200 , V_209 ?
V_209 - F_94 ( V_132 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_193 ) ;
goto V_216;
}
F_76 ( V_123 , V_114 , V_217 | V_196 ) ;
F_68 ( V_123 , V_114 , V_162 ) ;
if ( V_198 ) {
error = F_95 ( V_123 , V_2 , V_114 ) ;
if ( error )
goto V_218;
error = F_79 ( V_123 , V_114 ) ;
if ( error )
goto V_218;
}
if ( V_132 -> V_219 & ( V_220 | V_221 ) )
F_96 ( V_123 ) ;
F_97 ( V_123 , V_2 , V_204 , V_205 , V_206 ) ;
error = F_98 ( & V_123 , & V_200 , NULL ) ;
if ( error )
goto V_218;
error = F_99 ( V_123 ) ;
if ( error )
goto V_215;
F_100 ( V_204 ) ;
F_100 ( V_205 ) ;
F_100 ( V_206 ) ;
* V_117 = V_2 ;
return 0 ;
V_218:
F_101 ( & V_200 ) ;
V_216:
F_102 ( V_123 ) ;
V_215:
if ( V_2 ) {
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
}
F_100 ( V_204 ) ;
F_100 ( V_205 ) ;
F_100 ( V_206 ) ;
if ( V_202 )
F_18 ( V_114 , V_23 | V_17 ) ;
return error ;
}
int
F_105 (
struct V_1 * V_114 ,
struct V_222 * V_222 ,
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
V_209 = F_94 ( V_132 ) ;
V_208 = & F_86 ( V_132 ) -> V_223 ;
error = F_88 ( V_132 , V_208 , V_209 , 0 , 0 , & V_123 ) ;
if ( error == - V_193 ) {
V_209 = 0 ;
error = F_88 ( V_132 , V_208 , 0 , 0 , 0 , & V_123 ) ;
}
if ( error )
goto V_215;
error = F_91 ( V_123 , V_132 , V_204 , V_205 ,
V_206 , V_209 , 1 , 0 ) ;
if ( error )
goto V_216;
error = F_70 ( & V_123 , V_114 , V_125 , 1 , 0 ,
V_128 , V_209 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_216;
if ( V_132 -> V_219 & V_220 )
F_96 ( V_123 ) ;
F_97 ( V_123 , V_2 , V_204 , V_205 , V_206 ) ;
error = F_78 ( V_123 , V_2 ) ;
if ( error )
goto V_216;
error = F_99 ( V_123 ) ;
if ( error )
goto V_215;
F_100 ( V_204 ) ;
F_100 ( V_205 ) ;
F_100 ( V_206 ) ;
* V_117 = V_2 ;
return 0 ;
V_216:
F_102 ( V_123 ) ;
V_215:
if ( V_2 ) {
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
}
F_100 ( V_204 ) ;
F_100 ( V_205 ) ;
F_100 ( V_206 ) ;
return error ;
}
int
F_106 (
T_3 * V_224 ,
T_3 * V_225 ,
struct V_115 * V_226 )
{
T_17 * V_132 = V_224 -> V_7 ;
T_9 * V_123 ;
int error ;
T_15 V_200 ;
T_16 V_201 ;
int V_209 ;
F_107 ( V_224 , V_226 ) ;
ASSERT ( ! F_62 ( F_54 ( V_225 ) -> V_141 ) ) ;
if ( F_48 ( V_132 ) )
return - V_120 ;
error = F_108 ( V_225 , 0 ) ;
if ( error )
goto V_227;
error = F_108 ( V_224 , 0 ) ;
if ( error )
goto V_227;
V_209 = F_109 ( V_132 , V_226 -> V_212 ) ;
error = F_88 ( V_132 , & F_86 ( V_132 ) -> V_228 , V_209 , 0 , 0 , & V_123 ) ;
if ( error == - V_193 ) {
V_209 = 0 ;
error = F_88 ( V_132 , & F_86 ( V_132 ) -> V_228 , 0 , 0 , 0 , & V_123 ) ;
}
if ( error )
goto V_227;
F_4 ( V_224 , V_23 | V_45 ) ;
F_30 ( V_225 , V_224 , V_17 ) ;
F_67 ( V_123 , V_225 , V_17 ) ;
F_67 ( V_123 , V_224 , V_23 | V_17 ) ;
if ( F_110 ( ( V_224 -> V_3 . V_4 & V_95 ) &&
( F_111 ( V_224 ) != F_111 ( V_225 ) ) ) ) {
error = - V_229 ;
goto V_230;
}
if ( ! V_209 ) {
error = F_92 ( V_123 , V_224 , V_226 ) ;
if ( error )
goto V_230;
}
F_90 ( & V_200 , & V_201 ) ;
if ( F_54 ( V_225 ) -> V_197 == 0 ) {
error = F_112 ( V_123 , V_225 ) ;
if ( error )
goto V_230;
}
error = F_93 ( V_123 , V_224 , V_226 , V_225 -> V_69 ,
& V_201 , & V_200 , V_209 ) ;
if ( error )
goto V_230;
F_76 ( V_123 , V_224 , V_217 | V_196 ) ;
F_68 ( V_123 , V_224 , V_162 ) ;
error = F_79 ( V_123 , V_225 ) ;
if ( error )
goto V_230;
if ( V_132 -> V_219 & ( V_220 | V_221 ) )
F_96 ( V_123 ) ;
error = F_98 ( & V_123 , & V_200 , NULL ) ;
if ( error ) {
F_101 ( & V_200 ) ;
goto V_230;
}
return F_99 ( V_123 ) ;
V_230:
F_102 ( V_123 ) ;
V_227:
return error ;
}
int
F_113 (
struct V_199 * * V_186 ,
struct V_1 * V_2 ,
int V_231 ,
T_18 V_232 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_199 * V_123 = * V_186 ;
T_15 V_200 ;
T_16 V_201 ;
T_19 V_233 ;
T_19 V_234 ;
T_20 V_235 ;
int error = 0 ;
int V_236 = 0 ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( ! F_114 ( & F_54 ( V_2 ) -> V_237 ) ||
F_23 ( V_2 , V_23 ) ) ;
ASSERT ( V_232 <= F_115 ( V_2 ) ) ;
ASSERT ( V_123 -> V_191 & V_192 ) ;
ASSERT ( V_2 -> V_58 != NULL ) ;
ASSERT ( V_2 -> V_58 -> V_238 == 0 ) ;
ASSERT ( ! F_116 ( V_132 , V_2 ) ) ;
F_117 ( V_2 , V_232 ) ;
V_233 = F_118 ( V_132 , ( V_239 ) V_232 ) ;
V_234 = F_118 ( V_132 , V_132 -> V_149 -> V_240 ) ;
if ( V_233 == V_234 )
return 0 ;
ASSERT ( V_233 < V_234 ) ;
V_235 = V_234 - V_233 + 1 ;
while ( ! V_236 ) {
F_90 ( & V_200 , & V_201 ) ;
error = F_119 ( V_123 , V_2 ,
V_233 , V_235 ,
F_120 ( V_231 ) ,
V_241 ,
& V_201 , & V_200 ,
& V_236 ) ;
if ( error )
goto V_218;
error = F_98 ( & V_123 , & V_200 , V_2 ) ;
if ( error )
goto V_218;
error = F_72 ( & V_123 , V_2 ) ;
if ( error )
goto V_31;
}
F_68 ( V_123 , V_2 , V_162 ) ;
F_121 ( V_2 , V_232 ) ;
V_31:
* V_186 = V_123 ;
return error ;
V_218:
F_101 ( & V_200 ) ;
goto V_31;
}
int
F_122 (
T_3 * V_2 )
{
T_17 * V_132 = V_2 -> V_7 ;
int error ;
if ( ! F_66 ( F_54 ( V_2 ) -> V_141 ) || ( F_54 ( V_2 ) -> V_141 == 0 ) )
return 0 ;
if ( V_132 -> V_219 & V_242 )
return 0 ;
if ( ! F_48 ( V_132 ) ) {
int V_243 ;
V_243 = F_123 ( V_2 , V_244 ) ;
if ( V_243 ) {
F_124 ( V_2 , V_245 ) ;
if ( V_2 -> V_246 > 0 ) {
error = F_125 ( F_54 ( V_2 ) -> V_247 ) ;
if ( error )
return error ;
}
}
}
if ( F_54 ( V_2 ) -> V_197 == 0 )
return 0 ;
if ( F_126 ( V_2 , false ) ) {
if ( F_127 ( V_2 , V_245 ) )
return 0 ;
error = F_128 ( V_132 , V_2 , true ) ;
if ( error && error != - V_248 )
return error ;
if ( V_2 -> V_246 )
F_129 ( V_2 , V_245 ) ;
}
return 0 ;
}
STATIC int
F_130 (
struct V_1 * V_2 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_199 * V_123 ;
int error ;
error = F_88 ( V_132 , & F_86 ( V_132 ) -> V_249 , 0 , 0 , 0 , & V_123 ) ;
if ( error ) {
ASSERT ( F_48 ( V_132 ) ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_67 ( V_123 , V_2 , 0 ) ;
V_2 -> V_3 . V_146 = 0 ;
F_68 ( V_123 , V_2 , V_162 ) ;
error = F_113 ( & V_123 , V_2 , V_250 , 0 ) ;
if ( error )
goto V_251;
ASSERT ( V_2 -> V_3 . V_147 == 0 ) ;
error = F_99 ( V_123 ) ;
if ( error )
goto V_252;
F_18 ( V_2 , V_17 ) ;
return 0 ;
V_251:
F_102 ( V_123 ) ;
V_252:
F_18 ( V_2 , V_17 ) ;
return error ;
}
STATIC int
F_131 (
struct V_1 * V_2 )
{
T_15 V_200 ;
T_16 V_201 ;
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_199 * V_123 ;
int error ;
error = F_88 ( V_132 , & F_86 ( V_132 ) -> V_253 ,
F_132 ( V_132 ) , 0 , V_254 , & V_123 ) ;
if ( error ) {
if ( error == - V_193 ) {
F_133 ( V_132 ,
L_1
L_2 ) ;
} else {
ASSERT ( F_48 ( V_132 ) ) ;
}
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_67 ( V_123 , V_2 , 0 ) ;
F_90 ( & V_200 , & V_201 ) ;
error = F_134 ( V_123 , V_2 , & V_200 ) ;
if ( error ) {
if ( ! F_48 ( V_132 ) ) {
F_135 ( V_132 , L_3 ,
V_255 , error ) ;
F_136 ( V_132 , V_256 ) ;
}
F_102 ( V_123 ) ;
F_18 ( V_2 , V_17 ) ;
return error ;
}
F_137 ( V_123 , V_2 , V_257 , - 1 ) ;
error = F_98 ( & V_123 , & V_200 , NULL ) ;
if ( error ) {
F_135 ( V_132 , L_4 ,
V_255 , error ) ;
F_101 ( & V_200 ) ;
}
error = F_99 ( V_123 ) ;
if ( error )
F_135 ( V_132 , L_5 ,
V_255 , error ) ;
F_18 ( V_2 , V_17 ) ;
return 0 ;
}
void
F_138 (
T_3 * V_2 )
{
struct V_131 * V_132 ;
int error ;
int V_258 = 0 ;
if ( F_54 ( V_2 ) -> V_141 == 0 ) {
ASSERT ( V_2 -> V_14 . V_182 == 0 ) ;
ASSERT ( V_2 -> V_14 . V_259 == 0 ) ;
return;
}
V_132 = V_2 -> V_7 ;
if ( V_132 -> V_219 & V_242 )
return;
if ( F_54 ( V_2 ) -> V_197 != 0 ) {
if ( F_126 ( V_2 , true ) )
F_128 ( V_132 , V_2 , false ) ;
return;
}
if ( F_66 ( F_54 ( V_2 ) -> V_141 ) &&
( V_2 -> V_3 . V_146 != 0 || F_115 ( V_2 ) != 0 ||
V_2 -> V_3 . V_147 > 0 || V_2 -> V_246 > 0 ) )
V_258 = 1 ;
error = F_108 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_139 ( F_54 ( V_2 ) -> V_141 ) )
error = F_140 ( V_2 ) ;
else if ( V_258 )
error = F_130 ( V_2 ) ;
if ( error )
return;
if ( F_41 ( V_2 ) ) {
error = F_141 ( V_2 ) ;
if ( error )
return;
}
ASSERT ( ! V_2 -> V_19 ) ;
ASSERT ( V_2 -> V_3 . V_185 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_260 == 0 ) ;
error = F_131 ( V_2 ) ;
if ( error )
return;
F_142 ( V_2 ) ;
}
STATIC int
F_78 (
struct V_199 * V_123 ,
struct V_1 * V_2 )
{
T_17 * V_132 = V_123 -> V_133 ;
T_21 * V_261 ;
T_22 * V_113 ;
T_14 * V_262 ;
T_14 * V_263 ;
T_23 V_264 ;
short V_265 ;
int V_266 ;
int error ;
ASSERT ( F_54 ( V_2 ) -> V_141 != 0 ) ;
error = F_143 ( V_132 , V_123 , F_144 ( V_132 , V_2 -> V_69 ) , & V_262 ) ;
if ( error )
return error ;
V_261 = F_145 ( V_262 ) ;
V_264 = F_146 ( V_132 , V_2 -> V_69 ) ;
ASSERT ( V_264 != 0 ) ;
V_265 = V_264 % V_267 ;
ASSERT ( V_261 -> V_268 [ V_265 ] ) ;
ASSERT ( F_147 ( V_261 -> V_268 [ V_265 ] ) != V_264 ) ;
if ( V_261 -> V_268 [ V_265 ] != F_148 ( V_269 ) ) {
error = F_149 ( V_132 , V_123 , & V_2 -> V_270 , & V_113 , & V_263 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_113 -> V_271 == F_148 ( V_269 ) ) ;
V_113 -> V_271 = V_261 -> V_268 [ V_265 ] ;
V_266 = V_2 -> V_270 . V_272 +
F_150 ( T_22 , V_271 ) ;
F_151 ( V_132 , V_113 ) ;
F_152 ( V_123 , V_263 ) ;
F_153 ( V_123 , V_263 , V_266 ,
( V_266 + sizeof( T_23 ) - 1 ) ) ;
F_154 ( V_132 , V_263 ) ;
}
ASSERT ( V_264 != 0 ) ;
V_261 -> V_268 [ V_265 ] = F_148 ( V_264 ) ;
V_266 = F_150 ( T_21 , V_268 ) +
( sizeof( T_23 ) * V_265 ) ;
F_155 ( V_123 , V_262 , V_273 ) ;
F_153 ( V_123 , V_262 , V_266 ,
( V_266 + sizeof( T_23 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_112 (
T_9 * V_123 ,
T_3 * V_2 )
{
T_8 V_274 ;
T_17 * V_132 ;
T_21 * V_261 ;
T_22 * V_113 ;
T_14 * V_262 ;
T_14 * V_263 ;
T_24 V_275 ;
T_23 V_264 ;
T_23 V_276 ;
T_14 * V_277 ;
T_22 * V_278 = NULL ;
short V_265 ;
int V_266 , V_279 = 0 ;
int error ;
V_132 = V_123 -> V_133 ;
V_275 = F_144 ( V_132 , V_2 -> V_69 ) ;
error = F_143 ( V_132 , V_123 , V_275 , & V_262 ) ;
if ( error )
return error ;
V_261 = F_145 ( V_262 ) ;
V_264 = F_146 ( V_132 , V_2 -> V_69 ) ;
ASSERT ( V_264 != 0 ) ;
V_265 = V_264 % V_267 ;
ASSERT ( V_261 -> V_268 [ V_265 ] != F_148 ( V_269 ) ) ;
ASSERT ( V_261 -> V_268 [ V_265 ] ) ;
if ( F_147 ( V_261 -> V_268 [ V_265 ] ) == V_264 ) {
error = F_149 ( V_132 , V_123 , & V_2 -> V_270 , & V_113 , & V_263 ,
0 , 0 ) ;
if ( error ) {
F_156 ( V_132 , L_6 ,
V_255 , error ) ;
return error ;
}
V_276 = F_147 ( V_113 -> V_271 ) ;
ASSERT ( V_276 != 0 ) ;
if ( V_276 != V_269 ) {
V_113 -> V_271 = F_148 ( V_269 ) ;
V_266 = V_2 -> V_270 . V_272 +
F_150 ( T_22 , V_271 ) ;
F_151 ( V_132 , V_113 ) ;
F_152 ( V_123 , V_263 ) ;
F_153 ( V_123 , V_263 , V_266 ,
( V_266 + sizeof( T_23 ) - 1 ) ) ;
F_154 ( V_132 , V_263 ) ;
} else {
F_157 ( V_123 , V_263 ) ;
}
ASSERT ( V_276 != 0 ) ;
ASSERT ( V_276 != V_264 ) ;
V_261 -> V_268 [ V_265 ] = F_148 ( V_276 ) ;
V_266 = F_150 ( T_21 , V_268 ) +
( sizeof( T_23 ) * V_265 ) ;
F_155 ( V_123 , V_262 , V_273 ) ;
F_153 ( V_123 , V_262 , V_266 ,
( V_266 + sizeof( T_23 ) - 1 ) ) ;
} else {
V_276 = F_147 ( V_261 -> V_268 [ V_265 ] ) ;
V_277 = NULL ;
while ( V_276 != V_264 ) {
struct V_280 V_281 ;
if ( V_277 )
F_157 ( V_123 , V_277 ) ;
V_281 . V_282 = 0 ;
V_274 = F_158 ( V_132 , V_275 , V_276 ) ;
error = V_280 ( V_132 , V_123 , V_274 , & V_281 , 0 ) ;
if ( error ) {
F_156 ( V_132 ,
L_7 ,
V_255 , error ) ;
return error ;
}
error = F_149 ( V_132 , V_123 , & V_281 , & V_278 ,
& V_277 , 0 , 0 ) ;
if ( error ) {
F_156 ( V_132 ,
L_6 ,
V_255 , error ) ;
return error ;
}
V_279 = V_281 . V_272 ;
V_276 = F_147 ( V_278 -> V_271 ) ;
ASSERT ( V_276 != V_269 ) ;
ASSERT ( V_276 != 0 ) ;
}
error = F_149 ( V_132 , V_123 , & V_2 -> V_270 , & V_113 , & V_263 ,
0 , 0 ) ;
if ( error ) {
F_156 ( V_132 , L_8 ,
V_255 , error ) ;
return error ;
}
V_276 = F_147 ( V_113 -> V_271 ) ;
ASSERT ( V_276 != 0 ) ;
ASSERT ( V_276 != V_264 ) ;
if ( V_276 != V_269 ) {
V_113 -> V_271 = F_148 ( V_269 ) ;
V_266 = V_2 -> V_270 . V_272 +
F_150 ( T_22 , V_271 ) ;
F_151 ( V_132 , V_113 ) ;
F_152 ( V_123 , V_263 ) ;
F_153 ( V_123 , V_263 , V_266 ,
( V_266 + sizeof( T_23 ) - 1 ) ) ;
F_154 ( V_132 , V_263 ) ;
} else {
F_157 ( V_123 , V_263 ) ;
}
V_278 -> V_271 = F_148 ( V_276 ) ;
ASSERT ( V_276 != 0 ) ;
V_266 = V_279 + F_150 ( T_22 , V_271 ) ;
F_151 ( V_132 , V_278 ) ;
F_152 ( V_123 , V_277 ) ;
F_153 ( V_123 , V_277 , V_266 ,
( V_266 + sizeof( T_23 ) - 1 ) ) ;
F_154 ( V_132 , V_277 ) ;
}
return 0 ;
}
STATIC int
F_159 (
T_3 * V_283 ,
T_9 * V_123 ,
struct V_284 * V_285 )
{
T_17 * V_132 = V_283 -> V_7 ;
int V_286 ;
int V_287 ;
int V_288 ;
int V_53 , V_54 ;
int V_289 ;
T_25 V_290 ;
T_14 * V_291 ;
T_3 * V_2 ;
T_26 * V_292 ;
T_4 * V_293 ;
struct V_294 * V_295 ;
T_8 V_119 ;
V_119 = V_285 -> V_296 ;
V_295 = F_160 ( V_132 , F_144 ( V_132 , V_119 ) ) ;
V_286 = F_161 ( V_132 ) ;
V_287 = V_286 << V_132 -> V_8 . V_297 ;
V_288 = V_132 -> V_298 / V_286 ;
for ( V_54 = 0 ; V_54 < V_288 ; V_54 ++ , V_119 += V_287 ) {
V_289 = V_119 - V_285 -> V_296 ;
if ( ( V_285 -> V_299 & F_162 ( V_289 ) ) == 0 ) {
ASSERT ( F_163 ( V_289 , V_287 ) == 0 ) ;
continue;
}
V_290 = F_164 ( V_132 , F_144 ( V_132 , V_119 ) ,
F_165 ( V_132 , V_119 ) ) ;
V_291 = F_166 ( V_123 , V_132 -> V_300 , V_290 ,
V_132 -> V_301 * V_286 ,
V_302 ) ;
if ( ! V_291 )
return - V_303 ;
V_291 -> V_304 = & V_305 ;
V_293 = V_291 -> V_306 ;
while ( V_293 ) {
if ( V_293 -> V_307 == V_308 ) {
V_292 = ( T_26 * ) V_293 ;
ASSERT ( V_292 -> V_309 == 1 ) ;
V_293 -> V_310 = V_311 ;
F_167 ( V_132 -> V_312 ,
& V_292 -> V_313 ,
& V_292 -> V_314 . V_315 ) ;
F_129 ( V_292 -> V_316 , V_317 ) ;
}
V_293 = V_293 -> V_318 ;
}
for ( V_53 = 0 ; V_53 < V_287 ; V_53 ++ ) {
V_319:
F_168 () ;
V_2 = F_169 ( & V_295 -> V_320 ,
F_146 ( V_132 , ( V_119 + V_53 ) ) ) ;
if ( ! V_2 ) {
F_170 () ;
continue;
}
F_171 ( & V_2 -> V_321 ) ;
if ( V_2 -> V_69 != V_119 + V_53 ||
F_172 ( V_2 , V_317 ) ) {
F_173 ( & V_2 -> V_321 ) ;
F_170 () ;
continue;
}
F_173 ( & V_2 -> V_321 ) ;
if ( V_2 != V_283 &&
! F_12 ( V_2 , V_17 ) ) {
F_170 () ;
F_28 ( 1 ) ;
goto V_319;
}
F_170 () ;
F_174 ( V_2 ) ;
F_129 ( V_2 , V_317 ) ;
V_292 = V_2 -> V_58 ;
if ( ! V_292 || F_175 ( V_2 ) ) {
ASSERT ( V_2 != V_283 ) ;
F_176 ( V_2 ) ;
F_18 ( V_2 , V_17 ) ;
continue;
}
V_292 -> V_322 = V_292 -> V_323 ;
V_292 -> V_323 = 0 ;
V_292 -> V_324 = 0 ;
V_292 -> V_309 = 1 ;
F_167 ( V_132 -> V_312 , & V_292 -> V_313 ,
& V_292 -> V_314 . V_315 ) ;
F_177 ( V_291 , V_311 ,
& V_292 -> V_314 ) ;
if ( V_2 != V_283 )
F_18 ( V_2 , V_17 ) ;
}
F_178 ( V_123 , V_291 ) ;
F_179 ( V_123 , V_291 ) ;
}
F_180 ( V_295 ) ;
return 0 ;
}
int
F_134 (
T_9 * V_123 ,
T_3 * V_2 ,
T_15 * V_325 )
{
int error ;
struct V_284 V_285 = { 0 } ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( F_54 ( V_2 ) -> V_197 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_147 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_185 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_146 == 0 || ! F_66 ( F_54 ( V_2 ) -> V_141 ) ) ;
ASSERT ( V_2 -> V_3 . V_148 == 0 ) ;
error = F_112 ( V_123 , V_2 ) ;
if ( error )
return error ;
error = F_181 ( V_123 , V_2 -> V_69 , V_325 , & V_285 ) ;
if ( error )
return error ;
F_54 ( V_2 ) -> V_141 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_153 = 0 ;
V_2 -> V_3 . V_260 = 0 ;
V_2 -> V_3 . V_12 = V_180 ;
V_2 -> V_3 . V_18 = V_180 ;
F_54 ( V_2 ) -> V_326 ++ ;
F_68 ( V_123 , V_2 , V_162 ) ;
if ( V_285 . V_327 )
error = F_159 ( V_2 , V_123 , & V_285 ) ;
return error ;
}
static void
F_182 (
struct V_1 * V_2 )
{
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
F_183 ( V_2 , V_21 ) ;
F_184 ( V_2 -> V_7 , V_2 -> V_58 -> V_328 , 0 ) ;
}
static void
F_185 (
struct V_1 * V_2 )
{
T_5 * V_70 = F_32 ( & V_2 -> V_71 , V_329 ) ;
F_33 ( V_73 , & V_2 -> V_71 , V_329 ) ;
F_182 ( V_2 ) ;
do {
F_186 ( V_70 , & V_73 . V_73 , V_74 ) ;
if ( F_187 ( V_2 ) )
F_36 () ;
} while ( F_187 ( V_2 ) );
F_38 ( V_70 , & V_73 . V_73 ) ;
}
void
F_188 (
struct V_1 * V_2 )
{
if ( F_187 ( V_2 ) )
F_185 ( V_2 ) ;
}
int
F_189 (
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
F_190 ( V_114 , V_116 ) ;
if ( F_48 ( V_132 ) )
return - V_120 ;
error = F_108 ( V_114 , 0 ) ;
if ( error )
goto V_227;
error = F_108 ( V_2 , 0 ) ;
if ( error )
goto V_227;
V_209 = F_191 ( V_132 ) ;
error = F_88 ( V_132 , & F_86 ( V_132 ) -> V_330 , V_209 , 0 , 0 , & V_123 ) ;
if ( error == - V_193 ) {
V_209 = 0 ;
error = F_88 ( V_132 , & F_86 ( V_132 ) -> V_330 , 0 , 0 , 0 ,
& V_123 ) ;
}
if ( error ) {
ASSERT ( error != - V_193 ) ;
goto V_227;
}
F_4 ( V_114 , V_23 | V_45 ) ;
F_30 ( V_114 , V_2 , V_17 ) ;
F_67 ( V_123 , V_114 , V_23 | V_17 ) ;
F_67 ( V_123 , V_2 , V_17 ) ;
if ( V_198 ) {
ASSERT ( F_54 ( V_2 ) -> V_197 >= 2 ) ;
if ( F_54 ( V_2 ) -> V_197 != 2 ) {
error = - V_331 ;
goto V_216;
}
if ( ! F_192 ( V_2 ) ) {
error = - V_331 ;
goto V_216;
}
error = F_75 ( V_123 , V_114 ) ;
if ( error )
goto V_216;
error = F_75 ( V_123 , V_2 ) ;
if ( error )
goto V_216;
} else {
F_68 ( V_123 , V_114 , V_162 ) ;
}
F_76 ( V_123 , V_114 , V_217 | V_196 ) ;
error = F_75 ( V_123 , V_2 ) ;
if ( error )
goto V_216;
F_90 ( & V_200 , & V_201 ) ;
error = F_193 ( V_123 , V_114 , V_116 , V_2 -> V_69 ,
& V_201 , & V_200 , V_209 ) ;
if ( error ) {
ASSERT ( error != - V_332 ) ;
goto V_218;
}
if ( V_132 -> V_219 & ( V_220 | V_221 ) )
F_96 ( V_123 ) ;
error = F_98 ( & V_123 , & V_200 , NULL ) ;
if ( error )
goto V_218;
error = F_99 ( V_123 ) ;
if ( error )
goto V_227;
if ( V_198 && F_194 ( V_2 ) )
F_195 ( V_2 ) ;
return 0 ;
V_218:
F_101 ( & V_200 ) ;
V_216:
F_102 ( V_123 ) ;
V_227:
return error ;
}
STATIC void
F_196 (
struct V_1 * V_333 ,
struct V_1 * V_334 ,
struct V_1 * V_67 ,
struct V_1 * V_335 ,
struct V_1 * V_336 ,
struct V_1 * * V_337 ,
int * V_338 )
{
int V_53 , V_54 ;
ASSERT ( * V_338 == V_339 ) ;
memset ( V_337 , 0 , * V_338 * sizeof( struct V_1 * ) ) ;
V_53 = 0 ;
V_337 [ V_53 ++ ] = V_333 ;
V_337 [ V_53 ++ ] = V_334 ;
V_337 [ V_53 ++ ] = V_67 ;
if ( V_335 )
V_337 [ V_53 ++ ] = V_335 ;
if ( V_336 )
V_337 [ V_53 ++ ] = V_336 ;
* V_338 = V_53 ;
for ( V_53 = 0 ; V_53 < * V_338 ; V_53 ++ ) {
for ( V_54 = 1 ; V_54 < * V_338 ; V_54 ++ ) {
if ( V_337 [ V_54 ] -> V_69 < V_337 [ V_54 - 1 ] -> V_69 ) {
struct V_1 * V_68 = V_337 [ V_54 ] ;
V_337 [ V_54 ] = V_337 [ V_54 - 1 ] ;
V_337 [ V_54 - 1 ] = V_68 ;
}
}
}
}
static int
F_197 (
struct V_199 * V_123 ,
struct V_340 * V_200 )
{
int error ;
if ( V_123 -> V_133 -> V_219 & ( V_220 | V_221 ) )
F_96 ( V_123 ) ;
error = F_98 ( & V_123 , V_200 , NULL ) ;
if ( error ) {
F_101 ( V_200 ) ;
F_102 ( V_123 ) ;
return error ;
}
return F_99 ( V_123 ) ;
}
STATIC int
F_198 (
struct V_199 * V_123 ,
struct V_1 * V_333 ,
struct V_115 * V_341 ,
struct V_1 * V_67 ,
struct V_1 * V_334 ,
struct V_115 * V_342 ,
struct V_1 * V_335 ,
struct V_340 * V_200 ,
T_16 * V_201 ,
int V_343 )
{
int error = 0 ;
int V_344 = 0 ;
int V_345 = 0 ;
int V_346 = 0 ;
error = F_199 ( V_123 , V_333 , V_341 ,
V_335 -> V_69 ,
V_201 , V_200 , V_343 ) ;
if ( error )
goto V_347;
error = F_199 ( V_123 , V_334 , V_342 ,
V_67 -> V_69 ,
V_201 , V_200 , V_343 ) ;
if ( error )
goto V_347;
if ( V_333 != V_334 ) {
V_346 = V_217 | V_196 ;
if ( F_62 ( F_54 ( V_335 ) -> V_141 ) ) {
error = F_199 ( V_123 , V_335 , & V_348 ,
V_333 -> V_69 , V_201 ,
V_200 , V_343 ) ;
if ( error )
goto V_347;
if ( ! F_62 ( F_54 ( V_67 ) -> V_141 ) ) {
error = F_75 ( V_123 , V_334 ) ;
if ( error )
goto V_347;
error = F_79 ( V_123 , V_333 ) ;
if ( error )
goto V_347;
}
V_344 |= V_196 ;
V_345 |= V_217 | V_196 ;
}
if ( F_62 ( F_54 ( V_67 ) -> V_141 ) ) {
error = F_199 ( V_123 , V_67 , & V_348 ,
V_334 -> V_69 , V_201 ,
V_200 , V_343 ) ;
if ( error )
goto V_347;
if ( ! F_62 ( F_54 ( V_335 ) -> V_141 ) ) {
error = F_75 ( V_123 , V_333 ) ;
if ( error )
goto V_347;
error = F_79 ( V_123 , V_334 ) ;
if ( error )
goto V_347;
}
V_344 |= V_217 | V_196 ;
V_345 |= V_196 ;
}
}
if ( V_344 ) {
F_76 ( V_123 , V_67 , V_344 ) ;
F_68 ( V_123 , V_67 , V_162 ) ;
}
if ( V_345 ) {
F_76 ( V_123 , V_335 , V_345 ) ;
F_68 ( V_123 , V_335 , V_162 ) ;
}
if ( V_346 ) {
F_76 ( V_123 , V_334 , V_346 ) ;
F_68 ( V_123 , V_334 , V_162 ) ;
}
F_76 ( V_123 , V_333 , V_217 | V_196 ) ;
F_68 ( V_123 , V_333 , V_162 ) ;
return F_197 ( V_123 , V_200 ) ;
V_347:
F_101 ( V_200 ) ;
F_102 ( V_123 ) ;
return error ;
}
static int
F_200 (
struct V_1 * V_114 ,
struct V_1 * * V_336 )
{
struct V_1 * tmpfile ;
int error ;
error = F_105 ( V_114 , NULL , V_165 | V_349 , & tmpfile ) ;
if ( error )
return error ;
F_77 ( F_54 ( tmpfile ) ) ;
F_201 ( tmpfile ) ;
F_103 ( tmpfile ) ;
F_54 ( tmpfile ) -> V_350 |= V_351 ;
* V_336 = tmpfile ;
return 0 ;
}
int
F_202 (
struct V_1 * V_352 ,
struct V_115 * V_353 ,
struct V_1 * V_354 ,
struct V_1 * V_355 ,
struct V_115 * V_226 ,
struct V_1 * V_356 ,
unsigned int V_77 )
{
struct V_131 * V_132 = V_352 -> V_7 ;
struct V_199 * V_123 ;
struct V_340 V_200 ;
T_16 V_201 ;
struct V_1 * V_336 = NULL ;
struct V_1 * V_51 [ V_339 ] ;
int V_338 = V_339 ;
bool V_357 = ( V_352 != V_355 ) ;
bool V_358 = F_62 ( F_54 ( V_354 ) -> V_141 ) ;
int V_343 ;
int error ;
F_203 ( V_352 , V_355 , V_353 , V_226 ) ;
if ( ( V_77 & V_359 ) && ! V_356 )
return - V_360 ;
if ( V_77 & V_361 ) {
ASSERT ( ! ( V_77 & ( V_362 | V_359 ) ) ) ;
error = F_200 ( V_355 , & V_336 ) ;
if ( error )
return error ;
V_353 -> type = V_363 ;
}
F_196 ( V_352 , V_355 , V_354 , V_356 , V_336 ,
V_51 , & V_338 ) ;
V_343 = F_204 ( V_132 , V_226 -> V_212 ) ;
error = F_88 ( V_132 , & F_86 ( V_132 ) -> V_364 , V_343 , 0 , 0 , & V_123 ) ;
if ( error == - V_193 ) {
V_343 = 0 ;
error = F_88 ( V_132 , & F_86 ( V_132 ) -> V_364 , 0 , 0 , 0 ,
& V_123 ) ;
}
if ( error )
goto V_365;
error = F_205 ( V_51 ) ;
if ( error )
goto V_216;
if ( ! V_357 )
F_4 ( V_352 , V_23 | V_45 ) ;
else
F_30 ( V_352 , V_355 ,
V_23 | V_45 ) ;
F_27 ( V_51 , V_338 , V_17 ) ;
F_67 ( V_123 , V_352 , V_23 | V_17 ) ;
if ( V_357 )
F_67 ( V_123 , V_355 , V_23 | V_17 ) ;
F_67 ( V_123 , V_354 , V_17 ) ;
if ( V_356 )
F_67 ( V_123 , V_356 , V_17 ) ;
if ( V_336 )
F_67 ( V_123 , V_336 , V_17 ) ;
if ( F_110 ( ( V_355 -> V_3 . V_4 & V_95 ) &&
( F_111 ( V_355 ) != F_111 ( V_354 ) ) ) ) {
error = - V_229 ;
goto V_216;
}
F_90 ( & V_200 , & V_201 ) ;
if ( V_77 & V_359 )
return F_198 ( V_123 , V_352 , V_353 , V_354 ,
V_355 , V_226 , V_356 ,
& V_200 , & V_201 , V_343 ) ;
if ( V_356 == NULL ) {
if ( ! V_343 ) {
error = F_92 ( V_123 , V_355 , V_226 ) ;
if ( error )
goto V_216;
}
error = F_93 ( V_123 , V_355 , V_226 ,
V_354 -> V_69 , & V_201 ,
& V_200 , V_343 ) ;
if ( error )
goto V_218;
F_76 ( V_123 , V_355 ,
V_217 | V_196 ) ;
if ( V_357 && V_358 ) {
error = F_79 ( V_123 , V_355 ) ;
if ( error )
goto V_218;
}
} else {
if ( F_62 ( F_54 ( V_356 ) -> V_141 ) ) {
if ( ! ( F_192 ( V_356 ) ) ||
( F_54 ( V_356 ) -> V_197 > 2 ) ) {
error = - V_366 ;
goto V_216;
}
}
error = F_199 ( V_123 , V_355 , V_226 ,
V_354 -> V_69 ,
& V_201 , & V_200 , V_343 ) ;
if ( error )
goto V_218;
F_76 ( V_123 , V_355 ,
V_217 | V_196 ) ;
error = F_75 ( V_123 , V_356 ) ;
if ( error )
goto V_218;
if ( V_358 ) {
error = F_75 ( V_123 , V_356 ) ;
if ( error )
goto V_218;
}
}
if ( V_357 && V_358 ) {
error = F_199 ( V_123 , V_354 , & V_348 ,
V_355 -> V_69 ,
& V_201 , & V_200 , V_343 ) ;
ASSERT ( error != - V_366 ) ;
if ( error )
goto V_218;
}
F_76 ( V_123 , V_354 , V_196 ) ;
F_68 ( V_123 , V_354 , V_162 ) ;
if ( V_358 && ( V_357 || V_356 != NULL ) ) {
error = F_75 ( V_123 , V_352 ) ;
if ( error )
goto V_218;
}
if ( V_336 ) {
error = F_199 ( V_123 , V_352 , V_353 , V_336 -> V_69 ,
& V_201 , & V_200 , V_343 ) ;
} else
error = F_193 ( V_123 , V_352 , V_353 , V_354 -> V_69 ,
& V_201 , & V_200 , V_343 ) ;
if ( error )
goto V_218;
if ( V_336 ) {
ASSERT ( F_54 ( V_336 ) -> V_197 == 0 ) ;
error = F_79 ( V_123 , V_336 ) ;
if ( error )
goto V_218;
error = F_112 ( V_123 , V_336 ) ;
if ( error )
goto V_218;
F_68 ( V_123 , V_336 , V_162 ) ;
F_54 ( V_336 ) -> V_350 &= ~ V_351 ;
}
F_76 ( V_123 , V_352 , V_217 | V_196 ) ;
F_68 ( V_123 , V_352 , V_162 ) ;
if ( V_357 )
F_68 ( V_123 , V_355 , V_162 ) ;
error = F_197 ( V_123 , & V_200 ) ;
if ( V_336 )
F_104 ( V_336 ) ;
return error ;
V_218:
F_101 ( & V_200 ) ;
V_216:
F_102 ( V_123 ) ;
V_365:
if ( V_336 )
F_104 ( V_336 ) ;
return error ;
}
STATIC int
F_206 (
struct V_1 * V_2 ,
struct V_367 * V_291 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_294 * V_295 ;
unsigned long V_368 , V_369 ;
unsigned long V_287 ;
int V_370 ;
struct V_1 * * V_371 ;
struct V_1 * V_372 ;
int V_373 ;
int V_374 = 0 ;
int V_375 ;
int V_53 ;
V_295 = F_160 ( V_132 , F_144 ( V_132 , V_2 -> V_69 ) ) ;
V_287 = V_132 -> V_376 >> V_132 -> V_8 . V_377 ;
V_370 = V_287 * sizeof( T_3 * ) ;
V_371 = F_207 ( V_370 , V_378 | V_379 ) ;
if ( ! V_371 )
goto V_380;
V_369 = ~ ( ( ( V_132 -> V_376 >> V_132 -> V_8 . V_377 ) ) - 1 ) ;
V_368 = F_146 ( V_132 , V_2 -> V_69 ) & V_369 ;
F_168 () ;
V_373 = F_208 ( & V_295 -> V_320 , ( void * * ) V_371 ,
V_368 , V_287 ) ;
if ( V_373 == 0 )
goto V_381;
for ( V_53 = 0 ; V_53 < V_373 ; V_53 ++ ) {
V_372 = V_371 [ V_53 ] ;
if ( V_372 == V_2 )
continue;
F_171 ( & V_372 -> V_321 ) ;
if ( ! V_372 -> V_69 ||
F_172 ( V_372 , V_317 ) ) {
F_173 ( & V_372 -> V_321 ) ;
continue;
}
if ( ( F_146 ( V_132 , V_372 -> V_69 ) & V_369 ) != V_368 ) {
F_173 ( & V_372 -> V_321 ) ;
break;
}
F_173 ( & V_372 -> V_321 ) ;
if ( F_175 ( V_372 ) && F_187 ( V_372 ) == 0 )
continue;
if ( ! F_12 ( V_372 , V_11 ) )
continue;
if ( ! F_37 ( V_372 ) ) {
F_18 ( V_372 , V_11 ) ;
continue;
}
if ( F_187 ( V_372 ) ) {
F_176 ( V_372 ) ;
F_18 ( V_372 , V_11 ) ;
continue;
}
if ( ! V_372 -> V_69 ) {
F_176 ( V_372 ) ;
F_18 ( V_372 , V_11 ) ;
continue;
}
if ( ! F_175 ( V_372 ) ) {
int error ;
error = F_209 ( V_372 , V_291 ) ;
if ( error ) {
F_18 ( V_372 , V_11 ) ;
goto V_382;
}
V_374 ++ ;
} else {
F_176 ( V_372 ) ;
}
F_18 ( V_372 , V_11 ) ;
}
if ( V_374 ) {
F_210 ( V_132 , V_383 ) ;
F_211 ( V_132 , V_384 , V_374 ) ;
}
V_381:
F_170 () ;
F_51 ( V_371 ) ;
V_380:
F_180 ( V_295 ) ;
return 0 ;
V_382:
F_170 () ;
V_375 = ( V_291 -> V_385 & V_386 ) ;
if ( V_375 )
F_73 ( V_291 ) ;
F_136 ( V_132 , V_387 ) ;
if ( ! V_375 ) {
if ( V_291 -> V_388 ) {
V_291 -> V_385 &= ~ V_389 ;
F_212 ( V_291 ) ;
F_213 ( V_291 , - V_120 ) ;
F_214 ( V_291 ) ;
} else {
F_212 ( V_291 ) ;
F_73 ( V_291 ) ;
}
}
F_215 ( V_372 , false ) ;
F_51 ( V_371 ) ;
F_180 ( V_295 ) ;
return - V_390 ;
}
int
F_216 (
struct V_1 * V_2 ,
struct V_367 * * V_391 )
{
struct V_131 * V_132 = V_2 -> V_7 ;
struct V_367 * V_291 = NULL ;
struct V_112 * V_113 ;
int error ;
F_210 ( V_132 , V_392 ) ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_147 > F_217 ( V_2 , V_250 ) ) ;
* V_391 = NULL ;
F_188 ( V_2 ) ;
if ( F_127 ( V_2 , V_317 ) ) {
F_176 ( V_2 ) ;
return 0 ;
}
if ( F_48 ( V_132 ) ) {
error = - V_120 ;
goto V_393;
}
error = F_149 ( V_132 , NULL , & V_2 -> V_270 , & V_113 , & V_291 , V_394 ,
0 ) ;
if ( error == - V_248 ) {
F_176 ( V_2 ) ;
return error ;
}
if ( error )
goto V_395;
error = F_209 ( V_2 , V_291 ) ;
if ( error )
goto V_395;
if ( F_218 ( V_291 ) )
F_219 ( V_132 , 0 ) ;
error = F_206 ( V_2 , V_291 ) ;
if ( error )
goto V_382;
* V_391 = V_291 ;
return 0 ;
V_395:
if ( V_291 )
F_73 ( V_291 ) ;
F_136 ( V_132 , V_387 ) ;
V_382:
error = - V_390 ;
V_393:
F_215 ( V_2 , false ) ;
return error ;
}
STATIC int
F_209 (
struct V_1 * V_2 ,
struct V_367 * V_291 )
{
struct V_396 * V_292 = V_2 -> V_58 ;
struct V_112 * V_113 ;
struct V_131 * V_132 = V_2 -> V_7 ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_147 > F_217 ( V_2 , V_250 ) ) ;
ASSERT ( V_292 != NULL && V_292 -> V_323 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_140 > 1 ) ;
V_113 = F_220 ( V_291 , V_2 -> V_270 . V_272 ) ;
if ( F_221 ( V_113 -> V_397 != F_222 ( V_398 ) ,
V_132 , V_399 , V_400 ) ) {
F_223 ( V_132 , V_401 ,
L_9 ,
V_255 , V_2 -> V_69 , F_43 ( V_113 -> V_397 ) , V_113 ) ;
goto V_395;
}
if ( F_66 ( F_54 ( V_2 ) -> V_141 ) ) {
if ( F_221 (
( V_2 -> V_3 . V_12 != V_180 ) &&
( V_2 -> V_3 . V_12 != V_13 ) ,
V_132 , V_402 , V_403 ) ) {
F_223 ( V_132 , V_401 ,
L_10 ,
V_255 , V_2 -> V_69 , V_2 ) ;
goto V_395;
}
} else if ( F_62 ( F_54 ( V_2 ) -> V_141 ) ) {
if ( F_221 (
( V_2 -> V_3 . V_12 != V_180 ) &&
( V_2 -> V_3 . V_12 != V_13 ) &&
( V_2 -> V_3 . V_12 != V_404 ) ,
V_132 , V_405 , V_406 ) ) {
F_223 ( V_132 , V_401 ,
L_11 ,
V_255 , V_2 -> V_69 , V_2 ) ;
goto V_395;
}
}
if ( F_221 ( V_2 -> V_3 . V_147 + V_2 -> V_3 . V_185 >
V_2 -> V_3 . V_148 , V_132 , V_407 ,
V_408 ) ) {
F_223 ( V_132 , V_401 ,
L_12
L_13 ,
V_255 , V_2 -> V_69 ,
V_2 -> V_3 . V_147 + V_2 -> V_3 . V_185 ,
V_2 -> V_3 . V_148 , V_2 ) ;
goto V_395;
}
if ( F_221 ( V_2 -> V_3 . V_260 > V_132 -> V_8 . V_409 ,
V_132 , V_410 , V_411 ) ) {
F_223 ( V_132 , V_401 ,
L_14 ,
V_255 , V_2 -> V_69 , V_2 -> V_3 . V_260 , V_2 ) ;
goto V_395;
}
if ( V_2 -> V_3 . V_140 < 3 )
V_2 -> V_3 . V_412 ++ ;
F_224 ( V_2 , V_113 , V_292 -> V_314 . V_315 ) ;
if ( V_2 -> V_3 . V_412 == V_413 )
V_2 -> V_3 . V_412 = 0 ;
F_225 ( V_2 , V_113 , V_292 , V_250 ) ;
if ( F_41 ( V_2 ) )
F_225 ( V_2 , V_113 , V_292 , V_414 ) ;
F_154 ( V_132 , V_291 ) ;
V_292 -> V_322 = V_292 -> V_323 ;
V_292 -> V_323 = 0 ;
V_292 -> V_324 = 0 ;
V_292 -> V_309 = 1 ;
F_167 ( V_132 -> V_312 , & V_292 -> V_313 ,
& V_292 -> V_314 . V_315 ) ;
F_177 ( V_291 , V_415 , & V_292 -> V_314 ) ;
F_151 ( V_132 , V_113 ) ;
ASSERT ( V_291 -> V_306 != NULL ) ;
ASSERT ( V_291 -> V_388 != NULL ) ;
return 0 ;
V_395:
return - V_390 ;
}
