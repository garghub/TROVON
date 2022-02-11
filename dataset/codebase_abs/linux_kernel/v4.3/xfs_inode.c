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
T_6 V_4 )
{
T_2 V_75 = 0 ;
if ( V_4 & V_76 ) {
if ( V_4 & V_77 )
V_75 |= V_78 ;
if ( V_4 & V_79 )
V_75 |= V_80 ;
if ( V_4 & V_81 )
V_75 |= V_82 ;
if ( V_4 & V_83 )
V_75 |= V_84 ;
if ( V_4 & V_85 )
V_75 |= V_86 ;
if ( V_4 & V_87 )
V_75 |= V_88 ;
if ( V_4 & V_89 )
V_75 |= V_90 ;
if ( V_4 & V_91 )
V_75 |= V_92 ;
if ( V_4 & V_93 )
V_75 |= V_94 ;
if ( V_4 & V_95 )
V_75 |= V_96 ;
if ( V_4 & V_5 )
V_75 |= V_97 ;
if ( V_4 & V_98 )
V_75 |= V_99 ;
if ( V_4 & V_100 )
V_75 |= V_101 ;
if ( V_4 & V_102 )
V_75 |= V_103 ;
}
return V_75 ;
}
T_2
F_40 (
T_3 * V_2 )
{
T_7 * V_104 = & V_2 -> V_3 ;
return F_39 ( V_104 -> V_4 ) |
( F_41 ( V_2 ) ? V_105 : 0 ) ;
}
T_2
F_42 (
T_8 * V_106 )
{
return F_39 ( F_43 ( V_106 -> V_4 ) ) |
( F_44 ( V_106 ) ? V_105 : 0 ) ;
}
int
F_45 (
T_3 * V_107 ,
struct V_108 * V_109 ,
T_3 * * V_110 ,
struct V_108 * V_111 )
{
T_9 V_112 ;
int error ;
F_46 ( V_107 , V_109 ) ;
if ( F_47 ( V_107 -> V_7 ) )
return - V_113 ;
F_4 ( V_107 , V_22 ) ;
error = F_48 ( NULL , V_107 , V_109 , & V_112 , V_111 ) ;
if ( error )
goto V_114;
error = F_49 ( V_107 -> V_7 , NULL , V_112 , 0 , 0 , V_110 ) ;
if ( error )
goto V_115;
F_18 ( V_107 , V_22 ) ;
return 0 ;
V_115:
if ( V_111 )
F_50 ( V_111 -> V_109 ) ;
V_114:
F_18 ( V_107 , V_22 ) ;
* V_110 = NULL ;
return error ;
}
int
F_51 (
T_10 * V_116 ,
T_3 * V_117 ,
T_11 V_118 ,
T_12 V_119 ,
T_13 V_120 ,
T_14 V_121 ,
int V_122 ,
T_15 * * V_123 ,
T_3 * * V_110 )
{
struct V_124 * V_125 = V_116 -> V_126 ;
T_9 V_127 ;
T_3 * V_2 ;
T_2 V_75 ;
int error ;
struct V_128 V_129 ;
error = F_52 ( V_116 , V_117 ? V_117 -> V_69 : 0 , V_118 , V_122 ,
V_123 , & V_127 ) ;
if ( error )
return error ;
if ( * V_123 || V_127 == V_130 ) {
* V_110 = NULL ;
return 0 ;
}
ASSERT ( * V_123 == NULL ) ;
error = F_49 ( V_125 , V_116 , V_127 , V_131 ,
V_17 , & V_2 ) ;
if ( error )
return error ;
ASSERT ( V_2 != NULL ) ;
if ( V_2 -> V_3 . V_132 == 1 )
V_2 -> V_3 . V_132 = 2 ;
V_2 -> V_3 . V_133 = V_118 ;
V_2 -> V_3 . V_134 = 0 ;
V_2 -> V_3 . V_135 = V_119 ;
ASSERT ( V_2 -> V_3 . V_135 == V_119 ) ;
V_2 -> V_3 . V_136 = F_53 ( F_54 () ) ;
V_2 -> V_3 . V_137 = F_55 ( F_56 () ) ;
F_57 ( V_2 , V_121 ) ;
memset ( & ( V_2 -> V_3 . V_138 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_138 ) ) ;
if ( V_117 && F_58 ( V_117 ) ) {
V_2 -> V_3 . V_137 = V_117 -> V_3 . V_137 ;
if ( ( V_117 -> V_3 . V_133 & V_139 ) && F_59 ( V_118 ) ) {
V_2 -> V_3 . V_133 |= V_139 ;
}
}
if ( ( V_140 ) &&
( V_2 -> V_3 . V_133 & V_139 ) &&
( ! F_60 ( F_61 ( V_2 -> V_3 . V_137 ) ) ) ) {
V_2 -> V_3 . V_133 &= ~ V_139 ;
}
V_2 -> V_3 . V_141 = 0 ;
V_2 -> V_3 . V_142 = 0 ;
ASSERT ( V_2 -> V_3 . V_143 == 0 ) ;
V_129 = F_62 ( V_125 -> V_144 ) ;
V_2 -> V_3 . V_145 . V_146 = ( V_147 ) V_129 . V_148 ;
V_2 -> V_3 . V_145 . V_149 = ( V_147 ) V_129 . V_150 ;
V_2 -> V_3 . V_151 = V_2 -> V_3 . V_145 ;
V_2 -> V_3 . V_152 = V_2 -> V_3 . V_145 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_153 = 0 ;
V_2 -> V_3 . V_154 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( V_2 -> V_3 . V_132 == 3 ) {
ASSERT ( V_2 -> V_3 . V_155 == V_127 ) ;
ASSERT ( F_63 ( & V_2 -> V_3 . V_156 , & V_125 -> V_8 . V_157 ) ) ;
V_2 -> V_3 . V_158 = 0 ;
V_2 -> V_3 . V_159 = 1 ;
V_2 -> V_3 . V_160 = 0 ;
V_2 -> V_3 . V_161 = 0 ;
memset ( & ( V_2 -> V_3 . V_162 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_162 ) ) ;
V_2 -> V_3 . V_163 = V_2 -> V_3 . V_145 ;
}
V_75 = V_164 ;
switch ( V_118 & V_165 ) {
case V_166 :
case V_167 :
case V_168 :
case V_169 :
V_2 -> V_3 . V_12 = V_170 ;
V_2 -> V_14 . V_171 . V_172 = V_120 ;
V_2 -> V_14 . V_15 = 0 ;
V_75 |= V_173 ;
break;
case V_174 :
case V_175 :
if ( V_117 && ( V_117 -> V_3 . V_4 & V_76 ) ) {
T_2 V_4 = 0 ;
if ( F_59 ( V_118 ) ) {
if ( V_117 -> V_3 . V_4 & V_91 )
V_4 |= V_91 ;
if ( V_117 -> V_3 . V_4 & V_98 ) {
V_4 |= V_98 ;
V_2 -> V_3 . V_6 = V_117 -> V_3 . V_6 ;
}
if ( V_117 -> V_3 . V_4 & V_93 )
V_4 |= V_93 ;
} else if ( F_64 ( V_118 ) ) {
if ( V_117 -> V_3 . V_4 & V_91 )
V_4 |= V_77 ;
if ( V_117 -> V_3 . V_4 & V_98 ) {
V_4 |= V_5 ;
V_2 -> V_3 . V_6 = V_117 -> V_3 . V_6 ;
}
}
if ( ( V_117 -> V_3 . V_4 & V_87 ) &&
V_176 )
V_4 |= V_87 ;
if ( ( V_117 -> V_3 . V_4 & V_89 ) &&
V_177 )
V_4 |= V_89 ;
if ( ( V_117 -> V_3 . V_4 & V_85 ) &&
V_178 )
V_4 |= V_85 ;
if ( ( V_117 -> V_3 . V_4 & V_95 ) &&
V_179 )
V_4 |= V_95 ;
if ( ( V_117 -> V_3 . V_4 & V_100 ) &&
V_180 )
V_4 |= V_100 ;
if ( V_117 -> V_3 . V_4 & V_102 )
V_4 |= V_102 ;
V_2 -> V_3 . V_4 |= V_4 ;
}
case V_181 :
V_2 -> V_3 . V_12 = V_182 ;
V_2 -> V_14 . V_15 = V_16 ;
V_2 -> V_14 . V_183 = V_2 -> V_14 . V_184 = 0 ;
V_2 -> V_14 . V_185 . V_186 = NULL ;
break;
default:
ASSERT ( 0 ) ;
}
V_2 -> V_3 . V_18 = V_182 ;
V_2 -> V_3 . V_187 = 0 ;
F_65 ( V_116 , V_2 , V_17 ) ;
F_66 ( V_116 , V_2 , V_75 ) ;
F_67 ( V_2 ) ;
* V_110 = V_2 ;
return 0 ;
}
int
F_68 (
T_10 * * V_188 ,
T_3 * V_107 ,
T_11 V_118 ,
T_12 V_119 ,
T_13 V_120 ,
T_14 V_121 ,
int V_122 ,
T_3 * * V_110 ,
int * V_189 )
{
T_10 * V_116 ;
T_3 * V_2 ;
T_15 * V_123 = NULL ;
int V_190 ;
void * V_191 ;
T_2 V_192 ;
V_116 = * V_188 ;
ASSERT ( V_116 -> V_193 & V_194 ) ;
V_190 = F_51 ( V_116 , V_107 , V_118 , V_119 , V_120 , V_121 , V_122 ,
& V_123 , & V_2 ) ;
if ( V_190 ) {
* V_110 = NULL ;
return V_190 ;
}
if ( ! V_123 && ! V_2 ) {
* V_110 = NULL ;
return - V_195 ;
}
if ( V_123 ) {
F_69 ( V_116 , V_123 ) ;
V_191 = NULL ;
V_192 = 0 ;
if ( V_116 -> V_196 ) {
V_191 = ( void * ) V_116 -> V_196 ;
V_116 -> V_196 = NULL ;
V_192 = V_116 -> V_193 & V_197 ;
V_116 -> V_193 &= ~ ( V_197 ) ;
}
V_190 = F_70 ( & V_116 , 0 ) ;
if ( V_189 != NULL )
* V_189 = 1 ;
if ( V_191 ) {
V_116 -> V_196 = V_191 ;
V_116 -> V_193 |= V_192 ;
}
if ( V_190 ) {
F_71 ( V_123 ) ;
* V_188 = V_116 ;
* V_110 = NULL ;
return V_190 ;
}
F_72 ( V_116 , V_123 ) ;
V_190 = F_51 ( V_116 , V_107 , V_118 , V_119 , V_120 , V_121 ,
V_122 , & V_123 , & V_2 ) ;
if ( V_190 ) {
* V_188 = V_116 ;
* V_110 = NULL ;
return V_190 ;
}
ASSERT ( ! V_123 && V_2 ) ;
} else {
if ( V_189 != NULL )
* V_189 = 0 ;
}
* V_110 = V_2 ;
* V_188 = V_116 ;
return 0 ;
}
int
F_73 (
T_10 * V_116 ,
T_3 * V_2 )
{
int error ;
F_74 ( V_116 , V_2 , V_198 ) ;
ASSERT ( V_2 -> V_3 . V_135 > 0 ) ;
V_2 -> V_3 . V_135 -- ;
F_75 ( F_76 ( V_2 ) ) ;
F_66 ( V_116 , V_2 , V_164 ) ;
error = 0 ;
if ( V_2 -> V_3 . V_135 == 0 ) {
error = F_77 ( V_116 , V_2 ) ;
}
return error ;
}
int
F_78 (
T_10 * V_116 ,
T_3 * V_2 )
{
F_74 ( V_116 , V_2 , V_198 ) ;
ASSERT ( V_2 -> V_3 . V_132 > 1 ) ;
ASSERT ( V_2 -> V_3 . V_135 > 0 || ( F_76 ( V_2 ) -> V_199 & V_200 ) ) ;
V_2 -> V_3 . V_135 ++ ;
F_79 ( F_76 ( V_2 ) ) ;
F_66 ( V_116 , V_2 , V_164 ) ;
return 0 ;
}
int
F_80 (
T_3 * V_107 ,
struct V_108 * V_109 ,
T_11 V_118 ,
T_13 V_120 ,
T_3 * * V_110 )
{
int V_201 = F_59 ( V_118 ) ;
struct V_124 * V_125 = V_107 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_202 * V_116 = NULL ;
int error ;
T_16 V_203 ;
T_17 V_204 ;
bool V_205 = false ;
int V_189 ;
T_14 V_121 ;
struct V_206 * V_207 = NULL ;
struct V_206 * V_208 = NULL ;
struct V_206 * V_209 = NULL ;
struct V_210 * V_211 ;
T_2 V_212 ;
F_81 ( V_107 , V_109 ) ;
if ( F_47 ( V_125 ) )
return - V_113 ;
V_121 = F_82 ( V_107 ) ;
error = F_83 ( V_107 , F_53 ( F_54 () ) ,
F_55 ( F_56 () ) , V_121 ,
V_213 | V_214 ,
& V_207 , & V_208 , & V_209 ) ;
if ( error )
return error ;
if ( V_201 ) {
V_120 = 0 ;
V_212 = F_84 ( V_125 , V_109 -> V_215 ) ;
V_211 = & F_85 ( V_125 ) -> V_216 ;
V_116 = F_86 ( V_125 , V_217 ) ;
} else {
V_212 = F_87 ( V_125 , V_109 -> V_215 ) ;
V_211 = & F_85 ( V_125 ) -> V_218 ;
V_116 = F_86 ( V_125 , V_219 ) ;
}
error = F_88 ( V_116 , V_211 , V_212 , 0 ) ;
if ( error == - V_195 ) {
F_89 ( V_125 ) ;
error = F_88 ( V_116 , V_211 , V_212 , 0 ) ;
}
if ( error == - V_195 ) {
V_212 = 0 ;
error = F_88 ( V_116 , V_211 , 0 , 0 ) ;
}
if ( error )
goto V_220;
F_4 ( V_107 , V_23 | V_17 |
V_45 | V_39 ) ;
V_205 = true ;
F_90 ( & V_203 , & V_204 ) ;
error = F_91 ( V_116 , V_125 , V_207 , V_208 ,
V_209 , V_212 , 1 , 0 ) ;
if ( error )
goto V_220;
if ( ! V_212 ) {
error = F_92 ( V_116 , V_107 , V_109 ) ;
if ( error )
goto V_220;
}
error = F_68 ( & V_116 , V_107 , V_118 , V_201 ? 2 : 1 , V_120 ,
V_121 , V_212 > 0 , & V_2 , & V_189 ) ;
if ( error )
goto V_220;
F_65 ( V_116 , V_107 , V_23 | V_17 ) ;
V_205 = false ;
error = F_93 ( V_116 , V_107 , V_109 , V_2 -> V_69 ,
& V_204 , & V_203 , V_212 ?
V_212 - F_94 ( V_125 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_195 ) ;
goto V_220;
}
F_74 ( V_116 , V_107 , V_221 | V_198 ) ;
F_66 ( V_116 , V_107 , V_164 ) ;
if ( V_201 ) {
error = F_95 ( V_116 , V_2 , V_107 ) ;
if ( error )
goto V_222;
error = F_78 ( V_116 , V_107 ) ;
if ( error )
goto V_222;
}
if ( V_125 -> V_223 & ( V_224 | V_225 ) )
F_96 ( V_116 ) ;
F_97 ( V_116 , V_2 , V_207 , V_208 , V_209 ) ;
error = F_98 ( & V_116 , & V_203 , & V_189 ) ;
if ( error )
goto V_222;
error = F_99 ( V_116 ) ;
if ( error )
goto V_226;
F_100 ( V_207 ) ;
F_100 ( V_208 ) ;
F_100 ( V_209 ) ;
* V_110 = V_2 ;
return 0 ;
V_222:
F_101 ( & V_203 ) ;
V_220:
F_102 ( V_116 ) ;
V_226:
if ( V_2 ) {
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
}
F_100 ( V_207 ) ;
F_100 ( V_208 ) ;
F_100 ( V_209 ) ;
if ( V_205 )
F_18 ( V_107 , V_23 | V_17 ) ;
return error ;
}
int
F_105 (
struct V_1 * V_107 ,
struct V_227 * V_227 ,
T_11 V_118 ,
struct V_1 * * V_110 )
{
struct V_124 * V_125 = V_107 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_202 * V_116 = NULL ;
int error ;
T_14 V_121 ;
struct V_206 * V_207 = NULL ;
struct V_206 * V_208 = NULL ;
struct V_206 * V_209 = NULL ;
struct V_210 * V_211 ;
T_2 V_212 ;
if ( F_47 ( V_125 ) )
return - V_113 ;
V_121 = F_82 ( V_107 ) ;
error = F_83 ( V_107 , F_53 ( F_54 () ) ,
F_55 ( F_56 () ) , V_121 ,
V_213 | V_214 ,
& V_207 , & V_208 , & V_209 ) ;
if ( error )
return error ;
V_212 = F_94 ( V_125 ) ;
V_116 = F_86 ( V_125 , V_228 ) ;
V_211 = & F_85 ( V_125 ) -> V_229 ;
error = F_88 ( V_116 , V_211 , V_212 , 0 ) ;
if ( error == - V_195 ) {
V_212 = 0 ;
error = F_88 ( V_116 , V_211 , 0 , 0 ) ;
}
if ( error )
goto V_220;
error = F_91 ( V_116 , V_125 , V_207 , V_208 ,
V_209 , V_212 , 1 , 0 ) ;
if ( error )
goto V_220;
error = F_68 ( & V_116 , V_107 , V_118 , 1 , 0 ,
V_121 , V_212 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_220;
if ( V_125 -> V_223 & V_224 )
F_96 ( V_116 ) ;
F_97 ( V_116 , V_2 , V_207 , V_208 , V_209 ) ;
V_2 -> V_3 . V_135 -- ;
error = F_77 ( V_116 , V_2 ) ;
if ( error )
goto V_220;
error = F_99 ( V_116 ) ;
if ( error )
goto V_226;
F_100 ( V_207 ) ;
F_100 ( V_208 ) ;
F_100 ( V_209 ) ;
* V_110 = V_2 ;
return 0 ;
V_220:
F_102 ( V_116 ) ;
V_226:
if ( V_2 ) {
F_103 ( V_2 ) ;
F_104 ( V_2 ) ;
}
F_100 ( V_207 ) ;
F_100 ( V_208 ) ;
F_100 ( V_209 ) ;
return error ;
}
int
F_106 (
T_3 * V_230 ,
T_3 * V_231 ,
struct V_108 * V_232 )
{
T_18 * V_125 = V_230 -> V_7 ;
T_10 * V_116 ;
int error ;
T_16 V_203 ;
T_17 V_204 ;
int V_189 ;
int V_212 ;
F_107 ( V_230 , V_232 ) ;
ASSERT ( ! F_59 ( V_231 -> V_3 . V_133 ) ) ;
if ( F_47 ( V_125 ) )
return - V_113 ;
error = F_108 ( V_231 , 0 ) ;
if ( error )
goto V_233;
error = F_108 ( V_230 , 0 ) ;
if ( error )
goto V_233;
V_116 = F_86 ( V_125 , V_234 ) ;
V_212 = F_109 ( V_125 , V_232 -> V_215 ) ;
error = F_88 ( V_116 , & F_85 ( V_125 ) -> V_235 , V_212 , 0 ) ;
if ( error == - V_195 ) {
V_212 = 0 ;
error = F_88 ( V_116 , & F_85 ( V_125 ) -> V_235 , 0 , 0 ) ;
}
if ( error )
goto V_236;
F_4 ( V_230 , V_23 | V_45 ) ;
F_30 ( V_231 , V_230 , V_17 ) ;
F_65 ( V_116 , V_231 , V_17 ) ;
F_65 ( V_116 , V_230 , V_23 | V_17 ) ;
if ( F_110 ( ( V_230 -> V_3 . V_4 & V_93 ) &&
( F_111 ( V_230 ) != F_111 ( V_231 ) ) ) ) {
error = - V_237 ;
goto V_236;
}
if ( ! V_212 ) {
error = F_92 ( V_116 , V_230 , V_232 ) ;
if ( error )
goto V_236;
}
F_90 ( & V_203 , & V_204 ) ;
if ( V_231 -> V_3 . V_135 == 0 ) {
error = F_112 ( V_116 , V_231 ) ;
if ( error )
goto V_236;
}
error = F_93 ( V_116 , V_230 , V_232 , V_231 -> V_69 ,
& V_204 , & V_203 , V_212 ) ;
if ( error )
goto V_236;
F_74 ( V_116 , V_230 , V_221 | V_198 ) ;
F_66 ( V_116 , V_230 , V_164 ) ;
error = F_78 ( V_116 , V_231 ) ;
if ( error )
goto V_236;
if ( V_125 -> V_223 & ( V_224 | V_225 ) ) {
F_96 ( V_116 ) ;
}
error = F_98 ( & V_116 , & V_203 , & V_189 ) ;
if ( error ) {
F_101 ( & V_203 ) ;
goto V_236;
}
return F_99 ( V_116 ) ;
V_236:
F_102 ( V_116 ) ;
V_233:
return error ;
}
int
F_113 (
struct V_202 * * V_188 ,
struct V_1 * V_2 ,
int V_238 ,
T_19 V_239 )
{
struct V_124 * V_125 = V_2 -> V_7 ;
struct V_202 * V_116 = * V_188 ;
T_16 V_203 ;
T_17 V_204 ;
T_20 V_240 ;
T_20 V_241 ;
T_21 V_242 ;
int V_189 ;
int error = 0 ;
int V_243 = 0 ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( ! F_114 ( & F_76 ( V_2 ) -> V_244 ) ||
F_23 ( V_2 , V_23 ) ) ;
ASSERT ( V_239 <= F_115 ( V_2 ) ) ;
ASSERT ( V_116 -> V_193 & V_194 ) ;
ASSERT ( V_2 -> V_58 != NULL ) ;
ASSERT ( V_2 -> V_58 -> V_245 == 0 ) ;
ASSERT ( ! F_116 ( V_125 , V_2 ) ) ;
F_117 ( V_2 , V_239 ) ;
V_240 = F_118 ( V_125 , ( V_246 ) V_239 ) ;
V_241 = F_118 ( V_125 , V_125 -> V_144 -> V_247 ) ;
if ( V_240 == V_241 )
return 0 ;
ASSERT ( V_240 < V_241 ) ;
V_242 = V_241 - V_240 + 1 ;
while ( ! V_243 ) {
F_90 ( & V_203 , & V_204 ) ;
error = F_119 ( V_116 , V_2 ,
V_240 , V_242 ,
F_120 ( V_238 ) ,
V_248 ,
& V_204 , & V_203 ,
& V_243 ) ;
if ( error )
goto V_222;
error = F_98 ( & V_116 , & V_203 , & V_189 ) ;
if ( V_189 )
F_65 ( V_116 , V_2 , 0 ) ;
if ( error )
goto V_222;
error = F_70 ( & V_116 , V_2 ) ;
if ( error )
goto V_31;
}
F_66 ( V_116 , V_2 , V_164 ) ;
F_121 ( V_2 , V_239 ) ;
V_31:
* V_188 = V_116 ;
return error ;
V_222:
F_101 ( & V_203 ) ;
goto V_31;
}
int
F_122 (
T_3 * V_2 )
{
T_18 * V_125 = V_2 -> V_7 ;
int error ;
if ( ! F_64 ( V_2 -> V_3 . V_133 ) || ( V_2 -> V_3 . V_133 == 0 ) )
return 0 ;
if ( V_125 -> V_223 & V_249 )
return 0 ;
if ( ! F_47 ( V_125 ) ) {
int V_250 ;
V_250 = F_123 ( V_2 , V_251 ) ;
if ( V_250 ) {
F_124 ( V_2 , V_252 ) ;
if ( V_2 -> V_253 > 0 ) {
error = F_125 ( F_76 ( V_2 ) -> V_254 ) ;
if ( error )
return error ;
}
}
}
if ( V_2 -> V_3 . V_135 == 0 )
return 0 ;
if ( F_126 ( V_2 , false ) ) {
if ( F_127 ( V_2 , V_252 ) )
return 0 ;
error = F_128 ( V_125 , V_2 , true ) ;
if ( error && error != - V_255 )
return error ;
if ( V_2 -> V_253 )
F_129 ( V_2 , V_252 ) ;
}
return 0 ;
}
STATIC int
F_130 (
struct V_1 * V_2 )
{
struct V_124 * V_125 = V_2 -> V_7 ;
struct V_202 * V_116 ;
int error ;
V_116 = F_86 ( V_125 , V_256 ) ;
error = F_88 ( V_116 , & F_85 ( V_125 ) -> V_257 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_47 ( V_125 ) ) ;
F_102 ( V_116 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_65 ( V_116 , V_2 , 0 ) ;
V_2 -> V_3 . V_141 = 0 ;
F_66 ( V_116 , V_2 , V_164 ) ;
error = F_113 ( & V_116 , V_2 , V_258 , 0 ) ;
if ( error )
goto V_259;
ASSERT ( V_2 -> V_3 . V_142 == 0 ) ;
error = F_99 ( V_116 ) ;
if ( error )
goto V_260;
F_18 ( V_2 , V_17 ) ;
return 0 ;
V_259:
F_102 ( V_116 ) ;
V_260:
F_18 ( V_2 , V_17 ) ;
return error ;
}
STATIC int
F_131 (
struct V_1 * V_2 )
{
T_16 V_203 ;
T_17 V_204 ;
int V_189 ;
struct V_124 * V_125 = V_2 -> V_7 ;
struct V_202 * V_116 ;
int error ;
V_116 = F_86 ( V_125 , V_256 ) ;
V_116 -> V_193 |= V_261 ;
error = F_88 ( V_116 , & F_85 ( V_125 ) -> V_262 ,
F_132 ( V_125 ) , 0 ) ;
if ( error ) {
if ( error == - V_195 ) {
F_133 ( V_125 ,
L_1
L_2 ) ;
} else {
ASSERT ( F_47 ( V_125 ) ) ;
}
F_102 ( V_116 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_65 ( V_116 , V_2 , 0 ) ;
F_90 ( & V_203 , & V_204 ) ;
error = F_134 ( V_116 , V_2 , & V_203 ) ;
if ( error ) {
if ( ! F_47 ( V_125 ) ) {
F_135 ( V_125 , L_3 ,
V_263 , error ) ;
F_136 ( V_125 , V_264 ) ;
}
F_102 ( V_116 ) ;
F_18 ( V_2 , V_17 ) ;
return error ;
}
F_137 ( V_116 , V_2 , V_265 , - 1 ) ;
error = F_98 ( & V_116 , & V_203 , & V_189 ) ;
if ( error ) {
F_135 ( V_125 , L_4 ,
V_263 , error ) ;
F_101 ( & V_203 ) ;
}
error = F_99 ( V_116 ) ;
if ( error )
F_135 ( V_125 , L_5 ,
V_263 , error ) ;
F_18 ( V_2 , V_17 ) ;
return 0 ;
}
void
F_138 (
T_3 * V_2 )
{
struct V_124 * V_125 ;
int error ;
int V_266 = 0 ;
if ( V_2 -> V_3 . V_133 == 0 ) {
ASSERT ( V_2 -> V_14 . V_184 == 0 ) ;
ASSERT ( V_2 -> V_14 . V_267 == 0 ) ;
return;
}
V_125 = V_2 -> V_7 ;
if ( V_125 -> V_223 & V_249 )
return;
if ( V_2 -> V_3 . V_135 != 0 ) {
if ( F_126 ( V_2 , true ) )
F_128 ( V_125 , V_2 , false ) ;
return;
}
if ( F_64 ( V_2 -> V_3 . V_133 ) &&
( V_2 -> V_3 . V_141 != 0 || F_115 ( V_2 ) != 0 ||
V_2 -> V_3 . V_142 > 0 || V_2 -> V_253 > 0 ) )
V_266 = 1 ;
error = F_108 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_139 ( V_2 -> V_3 . V_133 ) )
error = F_140 ( V_2 ) ;
else if ( V_266 )
error = F_130 ( V_2 ) ;
if ( error )
return;
if ( F_41 ( V_2 ) ) {
error = F_141 ( V_2 ) ;
if ( error )
return;
}
ASSERT ( ! V_2 -> V_19 ) ;
ASSERT ( V_2 -> V_3 . V_187 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_268 == 0 ) ;
error = F_131 ( V_2 ) ;
if ( error )
return;
F_142 ( V_2 ) ;
}
int
F_77 (
T_10 * V_116 ,
T_3 * V_2 )
{
T_18 * V_125 ;
T_22 * V_269 ;
T_8 * V_106 ;
T_15 * V_270 ;
T_15 * V_271 ;
T_23 V_272 ;
short V_273 ;
int V_274 ;
int error ;
ASSERT ( V_2 -> V_3 . V_135 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_133 != 0 ) ;
V_125 = V_116 -> V_126 ;
error = F_143 ( V_125 , V_116 , F_144 ( V_125 , V_2 -> V_69 ) , & V_270 ) ;
if ( error )
return error ;
V_269 = F_145 ( V_270 ) ;
V_272 = F_146 ( V_125 , V_2 -> V_69 ) ;
ASSERT ( V_272 != 0 ) ;
V_273 = V_272 % V_275 ;
ASSERT ( V_269 -> V_276 [ V_273 ] ) ;
ASSERT ( F_147 ( V_269 -> V_276 [ V_273 ] ) != V_272 ) ;
if ( V_269 -> V_276 [ V_273 ] != F_148 ( V_277 ) ) {
error = F_149 ( V_125 , V_116 , & V_2 -> V_278 , & V_106 , & V_271 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_106 -> V_279 == F_148 ( V_277 ) ) ;
V_106 -> V_279 = V_269 -> V_276 [ V_273 ] ;
V_274 = V_2 -> V_278 . V_280 +
F_150 ( T_8 , V_279 ) ;
F_151 ( V_125 , V_106 ) ;
F_152 ( V_116 , V_271 ) ;
F_153 ( V_116 , V_271 , V_274 ,
( V_274 + sizeof( T_23 ) - 1 ) ) ;
F_154 ( V_125 , V_271 ) ;
}
ASSERT ( V_272 != 0 ) ;
V_269 -> V_276 [ V_273 ] = F_148 ( V_272 ) ;
V_274 = F_150 ( T_22 , V_276 ) +
( sizeof( T_23 ) * V_273 ) ;
F_155 ( V_116 , V_270 , V_281 ) ;
F_153 ( V_116 , V_270 , V_274 ,
( V_274 + sizeof( T_23 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_112 (
T_10 * V_116 ,
T_3 * V_2 )
{
T_9 V_282 ;
T_18 * V_125 ;
T_22 * V_269 ;
T_8 * V_106 ;
T_15 * V_270 ;
T_15 * V_271 ;
T_24 V_283 ;
T_23 V_272 ;
T_23 V_284 ;
T_15 * V_285 ;
T_8 * V_286 = NULL ;
short V_273 ;
int V_274 , V_287 = 0 ;
int error ;
V_125 = V_116 -> V_126 ;
V_283 = F_144 ( V_125 , V_2 -> V_69 ) ;
error = F_143 ( V_125 , V_116 , V_283 , & V_270 ) ;
if ( error )
return error ;
V_269 = F_145 ( V_270 ) ;
V_272 = F_146 ( V_125 , V_2 -> V_69 ) ;
ASSERT ( V_272 != 0 ) ;
V_273 = V_272 % V_275 ;
ASSERT ( V_269 -> V_276 [ V_273 ] != F_148 ( V_277 ) ) ;
ASSERT ( V_269 -> V_276 [ V_273 ] ) ;
if ( F_147 ( V_269 -> V_276 [ V_273 ] ) == V_272 ) {
error = F_149 ( V_125 , V_116 , & V_2 -> V_278 , & V_106 , & V_271 ,
0 , 0 ) ;
if ( error ) {
F_156 ( V_125 , L_6 ,
V_263 , error ) ;
return error ;
}
V_284 = F_147 ( V_106 -> V_279 ) ;
ASSERT ( V_284 != 0 ) ;
if ( V_284 != V_277 ) {
V_106 -> V_279 = F_148 ( V_277 ) ;
V_274 = V_2 -> V_278 . V_280 +
F_150 ( T_8 , V_279 ) ;
F_151 ( V_125 , V_106 ) ;
F_152 ( V_116 , V_271 ) ;
F_153 ( V_116 , V_271 , V_274 ,
( V_274 + sizeof( T_23 ) - 1 ) ) ;
F_154 ( V_125 , V_271 ) ;
} else {
F_157 ( V_116 , V_271 ) ;
}
ASSERT ( V_284 != 0 ) ;
ASSERT ( V_284 != V_272 ) ;
V_269 -> V_276 [ V_273 ] = F_148 ( V_284 ) ;
V_274 = F_150 ( T_22 , V_276 ) +
( sizeof( T_23 ) * V_273 ) ;
F_155 ( V_116 , V_270 , V_281 ) ;
F_153 ( V_116 , V_270 , V_274 ,
( V_274 + sizeof( T_23 ) - 1 ) ) ;
} else {
V_284 = F_147 ( V_269 -> V_276 [ V_273 ] ) ;
V_285 = NULL ;
while ( V_284 != V_272 ) {
struct V_288 V_289 ;
if ( V_285 )
F_157 ( V_116 , V_285 ) ;
V_289 . V_290 = 0 ;
V_282 = F_158 ( V_125 , V_283 , V_284 ) ;
error = V_288 ( V_125 , V_116 , V_282 , & V_289 , 0 ) ;
if ( error ) {
F_156 ( V_125 ,
L_7 ,
V_263 , error ) ;
return error ;
}
error = F_149 ( V_125 , V_116 , & V_289 , & V_286 ,
& V_285 , 0 , 0 ) ;
if ( error ) {
F_156 ( V_125 ,
L_6 ,
V_263 , error ) ;
return error ;
}
V_287 = V_289 . V_280 ;
V_284 = F_147 ( V_286 -> V_279 ) ;
ASSERT ( V_284 != V_277 ) ;
ASSERT ( V_284 != 0 ) ;
}
error = F_149 ( V_125 , V_116 , & V_2 -> V_278 , & V_106 , & V_271 ,
0 , 0 ) ;
if ( error ) {
F_156 ( V_125 , L_8 ,
V_263 , error ) ;
return error ;
}
V_284 = F_147 ( V_106 -> V_279 ) ;
ASSERT ( V_284 != 0 ) ;
ASSERT ( V_284 != V_272 ) ;
if ( V_284 != V_277 ) {
V_106 -> V_279 = F_148 ( V_277 ) ;
V_274 = V_2 -> V_278 . V_280 +
F_150 ( T_8 , V_279 ) ;
F_151 ( V_125 , V_106 ) ;
F_152 ( V_116 , V_271 ) ;
F_153 ( V_116 , V_271 , V_274 ,
( V_274 + sizeof( T_23 ) - 1 ) ) ;
F_154 ( V_125 , V_271 ) ;
} else {
F_157 ( V_116 , V_271 ) ;
}
V_286 -> V_279 = F_148 ( V_284 ) ;
ASSERT ( V_284 != 0 ) ;
V_274 = V_287 + F_150 ( T_8 , V_279 ) ;
F_151 ( V_125 , V_286 ) ;
F_152 ( V_116 , V_285 ) ;
F_153 ( V_116 , V_285 , V_274 ,
( V_274 + sizeof( T_23 ) - 1 ) ) ;
F_154 ( V_125 , V_285 ) ;
}
return 0 ;
}
STATIC int
F_159 (
T_3 * V_291 ,
T_10 * V_116 ,
struct V_292 * V_293 )
{
T_18 * V_125 = V_291 -> V_7 ;
int V_294 ;
int V_295 ;
int V_296 ;
int V_53 , V_54 ;
int V_297 ;
T_25 V_298 ;
T_15 * V_299 ;
T_3 * V_2 ;
T_26 * V_300 ;
T_4 * V_301 ;
struct V_302 * V_303 ;
T_9 V_112 ;
V_112 = V_293 -> V_304 ;
V_303 = F_160 ( V_125 , F_144 ( V_125 , V_112 ) ) ;
V_294 = F_161 ( V_125 ) ;
V_295 = V_294 << V_125 -> V_8 . V_305 ;
V_296 = V_125 -> V_306 / V_294 ;
for ( V_54 = 0 ; V_54 < V_296 ; V_54 ++ , V_112 += V_295 ) {
V_297 = V_112 - V_293 -> V_304 ;
if ( ( V_293 -> V_307 & F_162 ( V_297 ) ) == 0 ) {
ASSERT ( F_163 ( V_297 , V_295 ) == 0 ) ;
continue;
}
V_298 = F_164 ( V_125 , F_144 ( V_125 , V_112 ) ,
F_165 ( V_125 , V_112 ) ) ;
V_299 = F_166 ( V_116 , V_125 -> V_308 , V_298 ,
V_125 -> V_309 * V_294 ,
V_310 ) ;
if ( ! V_299 )
return - V_311 ;
V_299 -> V_312 = & V_313 ;
V_301 = V_299 -> V_314 ;
while ( V_301 ) {
if ( V_301 -> V_315 == V_316 ) {
V_300 = ( T_26 * ) V_301 ;
ASSERT ( V_300 -> V_317 == 1 ) ;
V_301 -> V_318 = V_319 ;
F_167 ( V_125 -> V_320 ,
& V_300 -> V_321 ,
& V_300 -> V_322 . V_323 ) ;
F_129 ( V_300 -> V_324 , V_325 ) ;
}
V_301 = V_301 -> V_326 ;
}
for ( V_53 = 0 ; V_53 < V_295 ; V_53 ++ ) {
V_327:
F_168 () ;
V_2 = F_169 ( & V_303 -> V_328 ,
F_146 ( V_125 , ( V_112 + V_53 ) ) ) ;
if ( ! V_2 ) {
F_170 () ;
continue;
}
F_171 ( & V_2 -> V_329 ) ;
if ( V_2 -> V_69 != V_112 + V_53 ||
F_172 ( V_2 , V_325 ) ) {
F_173 ( & V_2 -> V_329 ) ;
F_170 () ;
continue;
}
F_173 ( & V_2 -> V_329 ) ;
if ( V_2 != V_291 &&
! F_12 ( V_2 , V_17 ) ) {
F_170 () ;
F_28 ( 1 ) ;
goto V_327;
}
F_170 () ;
F_174 ( V_2 ) ;
F_129 ( V_2 , V_325 ) ;
V_300 = V_2 -> V_58 ;
if ( ! V_300 || F_175 ( V_2 ) ) {
ASSERT ( V_2 != V_291 ) ;
F_176 ( V_2 ) ;
F_18 ( V_2 , V_17 ) ;
continue;
}
V_300 -> V_330 = V_300 -> V_331 ;
V_300 -> V_331 = 0 ;
V_300 -> V_317 = 1 ;
F_167 ( V_125 -> V_320 , & V_300 -> V_321 ,
& V_300 -> V_322 . V_323 ) ;
F_177 ( V_299 , V_319 ,
& V_300 -> V_322 ) ;
if ( V_2 != V_291 )
F_18 ( V_2 , V_17 ) ;
}
F_178 ( V_116 , V_299 ) ;
F_179 ( V_116 , V_299 ) ;
}
F_180 ( V_303 ) ;
return 0 ;
}
int
F_134 (
T_10 * V_116 ,
T_3 * V_2 ,
T_16 * V_332 )
{
int error ;
struct V_292 V_293 = { 0 } ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( V_2 -> V_3 . V_135 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_142 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_187 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_141 == 0 || ! F_64 ( V_2 -> V_3 . V_133 ) ) ;
ASSERT ( V_2 -> V_3 . V_143 == 0 ) ;
error = F_112 ( V_116 , V_2 ) ;
if ( error )
return error ;
error = F_181 ( V_116 , V_2 -> V_69 , V_332 , & V_293 ) ;
if ( error )
return error ;
V_2 -> V_3 . V_133 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_153 = 0 ;
V_2 -> V_3 . V_268 = 0 ;
V_2 -> V_3 . V_12 = V_182 ;
V_2 -> V_3 . V_18 = V_182 ;
V_2 -> V_3 . V_333 ++ ;
F_66 ( V_116 , V_2 , V_164 ) ;
if ( V_293 . V_334 )
error = F_159 ( V_2 , V_116 , & V_293 ) ;
return error ;
}
static void
F_182 (
struct V_1 * V_2 )
{
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
F_183 ( V_2 , V_21 ) ;
F_184 ( V_2 -> V_7 , V_2 -> V_58 -> V_335 , 0 ) ;
}
static void
F_185 (
struct V_1 * V_2 )
{
T_5 * V_70 = F_32 ( & V_2 -> V_71 , V_336 ) ;
F_33 ( V_73 , & V_2 -> V_71 , V_336 ) ;
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
T_3 * V_107 ,
struct V_108 * V_109 ,
T_3 * V_2 )
{
T_18 * V_125 = V_107 -> V_7 ;
T_10 * V_116 = NULL ;
int V_201 = F_59 ( V_2 -> V_3 . V_133 ) ;
int error = 0 ;
T_16 V_203 ;
T_17 V_204 ;
int V_189 ;
T_2 V_212 ;
F_190 ( V_107 , V_109 ) ;
if ( F_47 ( V_125 ) )
return - V_113 ;
error = F_108 ( V_107 , 0 ) ;
if ( error )
goto V_233;
error = F_108 ( V_2 , 0 ) ;
if ( error )
goto V_233;
if ( V_201 )
V_116 = F_86 ( V_125 , V_337 ) ;
else
V_116 = F_86 ( V_125 , V_338 ) ;
V_212 = F_191 ( V_125 ) ;
error = F_88 ( V_116 , & F_85 ( V_125 ) -> V_339 , V_212 , 0 ) ;
if ( error == - V_195 ) {
V_212 = 0 ;
error = F_88 ( V_116 , & F_85 ( V_125 ) -> V_339 , 0 , 0 ) ;
}
if ( error ) {
ASSERT ( error != - V_195 ) ;
goto V_220;
}
F_4 ( V_107 , V_23 | V_45 ) ;
F_30 ( V_107 , V_2 , V_17 ) ;
F_65 ( V_116 , V_107 , V_23 | V_17 ) ;
F_65 ( V_116 , V_2 , V_17 ) ;
if ( V_201 ) {
ASSERT ( V_2 -> V_3 . V_135 >= 2 ) ;
if ( V_2 -> V_3 . V_135 != 2 ) {
error = - V_340 ;
goto V_220;
}
if ( ! F_192 ( V_2 ) ) {
error = - V_340 ;
goto V_220;
}
error = F_73 ( V_116 , V_107 ) ;
if ( error )
goto V_220;
error = F_73 ( V_116 , V_2 ) ;
if ( error )
goto V_220;
} else {
F_66 ( V_116 , V_107 , V_164 ) ;
}
F_74 ( V_116 , V_107 , V_221 | V_198 ) ;
error = F_73 ( V_116 , V_2 ) ;
if ( error )
goto V_220;
F_90 ( & V_203 , & V_204 ) ;
error = F_193 ( V_116 , V_107 , V_109 , V_2 -> V_69 ,
& V_204 , & V_203 , V_212 ) ;
if ( error ) {
ASSERT ( error != - V_341 ) ;
goto V_222;
}
if ( V_125 -> V_223 & ( V_224 | V_225 ) )
F_96 ( V_116 ) ;
error = F_98 ( & V_116 , & V_203 , & V_189 ) ;
if ( error )
goto V_222;
error = F_99 ( V_116 ) ;
if ( error )
goto V_233;
if ( V_201 && F_194 ( V_2 ) )
F_195 ( V_2 ) ;
return 0 ;
V_222:
F_101 ( & V_203 ) ;
V_220:
F_102 ( V_116 ) ;
V_233:
return error ;
}
STATIC void
F_196 (
struct V_1 * V_342 ,
struct V_1 * V_343 ,
struct V_1 * V_67 ,
struct V_1 * V_344 ,
struct V_1 * V_345 ,
struct V_1 * * V_346 ,
int * V_347 )
{
int V_53 , V_54 ;
ASSERT ( * V_347 == V_348 ) ;
memset ( V_346 , 0 , * V_347 * sizeof( struct V_1 * ) ) ;
V_53 = 0 ;
V_346 [ V_53 ++ ] = V_342 ;
V_346 [ V_53 ++ ] = V_343 ;
V_346 [ V_53 ++ ] = V_67 ;
if ( V_344 )
V_346 [ V_53 ++ ] = V_344 ;
if ( V_345 )
V_346 [ V_53 ++ ] = V_345 ;
* V_347 = V_53 ;
for ( V_53 = 0 ; V_53 < * V_347 ; V_53 ++ ) {
for ( V_54 = 1 ; V_54 < * V_347 ; V_54 ++ ) {
if ( V_346 [ V_54 ] -> V_69 < V_346 [ V_54 - 1 ] -> V_69 ) {
struct V_1 * V_68 = V_346 [ V_54 ] ;
V_346 [ V_54 ] = V_346 [ V_54 - 1 ] ;
V_346 [ V_54 - 1 ] = V_68 ;
}
}
}
}
static int
F_197 (
struct V_202 * V_116 ,
struct V_349 * V_203 )
{
int V_189 = 0 ;
int error ;
if ( V_116 -> V_126 -> V_223 & ( V_224 | V_225 ) )
F_96 ( V_116 ) ;
error = F_98 ( & V_116 , V_203 , & V_189 ) ;
if ( error ) {
F_101 ( V_203 ) ;
F_102 ( V_116 ) ;
return error ;
}
return F_99 ( V_116 ) ;
}
STATIC int
F_198 (
struct V_202 * V_116 ,
struct V_1 * V_342 ,
struct V_108 * V_350 ,
struct V_1 * V_67 ,
struct V_1 * V_343 ,
struct V_108 * V_351 ,
struct V_1 * V_344 ,
struct V_349 * V_203 ,
T_17 * V_204 ,
int V_352 )
{
int error = 0 ;
int V_353 = 0 ;
int V_354 = 0 ;
int V_355 = 0 ;
error = F_199 ( V_116 , V_342 , V_350 ,
V_344 -> V_69 ,
V_204 , V_203 , V_352 ) ;
if ( error )
goto V_356;
error = F_199 ( V_116 , V_343 , V_351 ,
V_67 -> V_69 ,
V_204 , V_203 , V_352 ) ;
if ( error )
goto V_356;
if ( V_342 != V_343 ) {
V_355 = V_221 | V_198 ;
if ( F_59 ( V_344 -> V_3 . V_133 ) ) {
error = F_199 ( V_116 , V_344 , & V_357 ,
V_342 -> V_69 , V_204 ,
V_203 , V_352 ) ;
if ( error )
goto V_356;
if ( ! F_59 ( V_67 -> V_3 . V_133 ) ) {
error = F_73 ( V_116 , V_343 ) ;
if ( error )
goto V_356;
error = F_78 ( V_116 , V_342 ) ;
if ( error )
goto V_356;
}
V_353 |= V_198 ;
V_354 |= V_221 | V_198 ;
}
if ( F_59 ( V_67 -> V_3 . V_133 ) ) {
error = F_199 ( V_116 , V_67 , & V_357 ,
V_343 -> V_69 , V_204 ,
V_203 , V_352 ) ;
if ( error )
goto V_356;
if ( ! F_59 ( V_344 -> V_3 . V_133 ) ) {
error = F_73 ( V_116 , V_342 ) ;
if ( error )
goto V_356;
error = F_78 ( V_116 , V_343 ) ;
if ( error )
goto V_356;
}
V_353 |= V_221 | V_198 ;
V_354 |= V_198 ;
}
}
if ( V_353 ) {
F_74 ( V_116 , V_67 , V_353 ) ;
F_66 ( V_116 , V_67 , V_164 ) ;
}
if ( V_354 ) {
F_74 ( V_116 , V_344 , V_354 ) ;
F_66 ( V_116 , V_344 , V_164 ) ;
}
if ( V_355 ) {
F_74 ( V_116 , V_343 , V_355 ) ;
F_66 ( V_116 , V_343 , V_164 ) ;
}
F_74 ( V_116 , V_342 , V_221 | V_198 ) ;
F_66 ( V_116 , V_342 , V_164 ) ;
return F_197 ( V_116 , V_203 ) ;
V_356:
F_101 ( V_203 ) ;
F_102 ( V_116 ) ;
return error ;
}
static int
F_200 (
struct V_1 * V_107 ,
struct V_1 * * V_345 )
{
struct V_1 * tmpfile ;
int error ;
error = F_105 ( V_107 , NULL , V_167 | V_358 , & tmpfile ) ;
if ( error )
return error ;
F_75 ( F_76 ( tmpfile ) ) ;
F_103 ( tmpfile ) ;
F_76 ( tmpfile ) -> V_199 |= V_200 ;
* V_345 = tmpfile ;
return 0 ;
}
int
F_201 (
struct V_1 * V_359 ,
struct V_108 * V_360 ,
struct V_1 * V_361 ,
struct V_1 * V_362 ,
struct V_108 * V_232 ,
struct V_1 * V_363 ,
unsigned int V_75 )
{
struct V_124 * V_125 = V_359 -> V_7 ;
struct V_202 * V_116 ;
struct V_349 V_203 ;
T_17 V_204 ;
struct V_1 * V_345 = NULL ;
struct V_1 * V_51 [ V_348 ] ;
int V_347 = V_348 ;
bool V_364 = ( V_359 != V_362 ) ;
bool V_365 = F_59 ( V_361 -> V_3 . V_133 ) ;
int V_352 ;
int error ;
F_202 ( V_359 , V_362 , V_360 , V_232 ) ;
if ( ( V_75 & V_366 ) && ! V_363 )
return - V_367 ;
if ( V_75 & V_368 ) {
ASSERT ( ! ( V_75 & ( V_369 | V_366 ) ) ) ;
error = F_200 ( V_362 , & V_345 ) ;
if ( error )
return error ;
V_360 -> type = V_370 ;
}
F_196 ( V_359 , V_362 , V_361 , V_363 , V_345 ,
V_51 , & V_347 ) ;
V_116 = F_86 ( V_125 , V_371 ) ;
V_352 = F_203 ( V_125 , V_232 -> V_215 ) ;
error = F_88 ( V_116 , & F_85 ( V_125 ) -> V_372 , V_352 , 0 ) ;
if ( error == - V_195 ) {
V_352 = 0 ;
error = F_88 ( V_116 , & F_85 ( V_125 ) -> V_372 , 0 , 0 ) ;
}
if ( error )
goto V_220;
error = F_204 ( V_51 ) ;
if ( error )
goto V_220;
if ( ! V_364 )
F_4 ( V_359 , V_23 | V_45 ) ;
else
F_30 ( V_359 , V_362 ,
V_23 | V_45 ) ;
F_27 ( V_51 , V_347 , V_17 ) ;
F_65 ( V_116 , V_359 , V_23 | V_17 ) ;
if ( V_364 )
F_65 ( V_116 , V_362 , V_23 | V_17 ) ;
F_65 ( V_116 , V_361 , V_17 ) ;
if ( V_363 )
F_65 ( V_116 , V_363 , V_17 ) ;
if ( V_345 )
F_65 ( V_116 , V_345 , V_17 ) ;
if ( F_110 ( ( V_362 -> V_3 . V_4 & V_93 ) &&
( F_111 ( V_362 ) != F_111 ( V_361 ) ) ) ) {
error = - V_237 ;
goto V_220;
}
F_90 ( & V_203 , & V_204 ) ;
if ( V_75 & V_366 )
return F_198 ( V_116 , V_359 , V_360 , V_361 ,
V_362 , V_232 , V_363 ,
& V_203 , & V_204 , V_352 ) ;
if ( V_363 == NULL ) {
if ( ! V_352 ) {
error = F_92 ( V_116 , V_362 , V_232 ) ;
if ( error )
goto V_220;
}
error = F_93 ( V_116 , V_362 , V_232 ,
V_361 -> V_69 , & V_204 ,
& V_203 , V_352 ) ;
if ( error )
goto V_222;
F_74 ( V_116 , V_362 ,
V_221 | V_198 ) ;
if ( V_364 && V_365 ) {
error = F_78 ( V_116 , V_362 ) ;
if ( error )
goto V_222;
}
} else {
if ( F_59 ( V_363 -> V_3 . V_133 ) ) {
if ( ! ( F_192 ( V_363 ) ) ||
( V_363 -> V_3 . V_135 > 2 ) ) {
error = - V_373 ;
goto V_220;
}
}
error = F_199 ( V_116 , V_362 , V_232 ,
V_361 -> V_69 ,
& V_204 , & V_203 , V_352 ) ;
if ( error )
goto V_222;
F_74 ( V_116 , V_362 ,
V_221 | V_198 ) ;
error = F_73 ( V_116 , V_363 ) ;
if ( error )
goto V_222;
if ( V_365 ) {
error = F_73 ( V_116 , V_363 ) ;
if ( error )
goto V_222;
}
}
if ( V_364 && V_365 ) {
error = F_199 ( V_116 , V_361 , & V_357 ,
V_362 -> V_69 ,
& V_204 , & V_203 , V_352 ) ;
ASSERT ( error != - V_373 ) ;
if ( error )
goto V_222;
}
F_74 ( V_116 , V_361 , V_198 ) ;
F_66 ( V_116 , V_361 , V_164 ) ;
if ( V_365 && ( V_364 || V_363 != NULL ) ) {
error = F_73 ( V_116 , V_359 ) ;
if ( error )
goto V_222;
}
if ( V_345 ) {
error = F_199 ( V_116 , V_359 , V_360 , V_345 -> V_69 ,
& V_204 , & V_203 , V_352 ) ;
} else
error = F_193 ( V_116 , V_359 , V_360 , V_361 -> V_69 ,
& V_204 , & V_203 , V_352 ) ;
if ( error )
goto V_222;
if ( V_345 ) {
ASSERT ( F_76 ( V_345 ) -> V_374 == 0 && V_345 -> V_3 . V_135 == 0 ) ;
error = F_78 ( V_116 , V_345 ) ;
if ( error )
goto V_222;
error = F_112 ( V_116 , V_345 ) ;
if ( error )
goto V_222;
F_66 ( V_116 , V_345 , V_164 ) ;
F_76 ( V_345 ) -> V_199 &= ~ V_200 ;
}
F_74 ( V_116 , V_359 , V_221 | V_198 ) ;
F_66 ( V_116 , V_359 , V_164 ) ;
if ( V_364 )
F_66 ( V_116 , V_362 , V_164 ) ;
error = F_197 ( V_116 , & V_203 ) ;
if ( V_345 )
F_104 ( V_345 ) ;
return error ;
V_222:
F_101 ( & V_203 ) ;
V_220:
F_102 ( V_116 ) ;
if ( V_345 )
F_104 ( V_345 ) ;
return error ;
}
STATIC int
F_205 (
T_3 * V_2 ,
T_15 * V_299 )
{
T_18 * V_125 = V_2 -> V_7 ;
struct V_302 * V_303 ;
unsigned long V_375 , V_376 ;
unsigned long V_295 ;
int V_377 ;
T_3 * * V_378 ;
T_3 * V_379 ;
int V_380 ;
int V_381 = 0 ;
int V_382 ;
int V_53 ;
V_303 = F_160 ( V_125 , F_144 ( V_125 , V_2 -> V_69 ) ) ;
V_295 = V_125 -> V_383 >> V_125 -> V_8 . V_384 ;
V_377 = V_295 * sizeof( T_3 * ) ;
V_378 = F_206 ( V_377 , V_385 | V_386 ) ;
if ( ! V_378 )
goto V_387;
V_376 = ~ ( ( ( V_125 -> V_383 >> V_125 -> V_8 . V_384 ) ) - 1 ) ;
V_375 = F_146 ( V_125 , V_2 -> V_69 ) & V_376 ;
F_168 () ;
V_380 = F_207 ( & V_303 -> V_328 , ( void * * ) V_378 ,
V_375 , V_295 ) ;
if ( V_380 == 0 )
goto V_388;
for ( V_53 = 0 ; V_53 < V_380 ; V_53 ++ ) {
V_379 = V_378 [ V_53 ] ;
if ( V_379 == V_2 )
continue;
F_171 ( & V_2 -> V_329 ) ;
if ( ! V_2 -> V_69 ||
( F_146 ( V_125 , V_379 -> V_69 ) & V_376 ) != V_375 ) {
F_173 ( & V_2 -> V_329 ) ;
continue;
}
F_173 ( & V_2 -> V_329 ) ;
if ( F_175 ( V_379 ) && F_187 ( V_379 ) == 0 )
continue;
if ( ! F_12 ( V_379 , V_11 ) )
continue;
if ( ! F_37 ( V_379 ) ) {
F_18 ( V_379 , V_11 ) ;
continue;
}
if ( F_187 ( V_379 ) ) {
F_176 ( V_379 ) ;
F_18 ( V_379 , V_11 ) ;
continue;
}
if ( ! F_175 ( V_379 ) ) {
int error ;
error = F_208 ( V_379 , V_299 ) ;
if ( error ) {
F_18 ( V_379 , V_11 ) ;
goto V_389;
}
V_381 ++ ;
} else {
F_176 ( V_379 ) ;
}
F_18 ( V_379 , V_11 ) ;
}
if ( V_381 ) {
F_209 ( V_390 ) ;
F_210 ( V_391 , V_381 ) ;
}
V_388:
F_170 () ;
F_50 ( V_378 ) ;
V_387:
F_180 ( V_303 ) ;
return 0 ;
V_389:
F_170 () ;
V_382 = ( V_299 -> V_392 & V_393 ) ;
if ( V_382 )
F_71 ( V_299 ) ;
F_136 ( V_125 , V_394 ) ;
if ( ! V_382 ) {
if ( V_299 -> V_395 ) {
F_211 ( V_299 ) ;
F_212 ( V_299 ) ;
F_213 ( V_299 , - V_113 ) ;
F_214 ( V_299 ) ;
} else {
F_212 ( V_299 ) ;
F_71 ( V_299 ) ;
}
}
F_215 ( V_379 , false ) ;
F_50 ( V_378 ) ;
F_180 ( V_303 ) ;
return - V_396 ;
}
int
F_216 (
struct V_1 * V_2 ,
struct V_397 * * V_398 )
{
struct V_124 * V_125 = V_2 -> V_7 ;
struct V_397 * V_299 ;
struct V_399 * V_106 ;
int error ;
F_209 ( V_400 ) ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_142 > F_217 ( V_2 , V_258 ) ) ;
* V_398 = NULL ;
F_188 ( V_2 ) ;
if ( F_127 ( V_2 , V_325 ) ) {
F_176 ( V_2 ) ;
return 0 ;
}
if ( F_47 ( V_125 ) ) {
error = - V_113 ;
goto V_401;
}
error = F_149 ( V_125 , NULL , & V_2 -> V_278 , & V_106 , & V_299 , V_402 ,
0 ) ;
if ( error || ! V_299 ) {
F_176 ( V_2 ) ;
return error ;
}
error = F_208 ( V_2 , V_299 ) ;
if ( error )
goto V_403;
if ( F_218 ( V_299 ) )
F_219 ( V_125 , 0 ) ;
error = F_205 ( V_2 , V_299 ) ;
if ( error )
goto V_389;
* V_398 = V_299 ;
return 0 ;
V_403:
F_71 ( V_299 ) ;
F_136 ( V_125 , V_394 ) ;
V_389:
error = - V_396 ;
V_401:
F_215 ( V_2 , false ) ;
return error ;
}
STATIC int
F_208 (
struct V_1 * V_2 ,
struct V_397 * V_299 )
{
struct V_404 * V_300 = V_2 -> V_58 ;
struct V_399 * V_106 ;
struct V_124 * V_125 = V_2 -> V_7 ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_142 > F_217 ( V_2 , V_258 ) ) ;
ASSERT ( V_300 != NULL && V_300 -> V_331 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_132 > 1 ) ;
V_106 = F_220 ( V_299 , V_2 -> V_278 . V_280 ) ;
if ( F_221 ( V_106 -> V_405 != F_222 ( V_406 ) ,
V_125 , V_407 , V_408 ) ) {
F_223 ( V_125 , V_409 ,
L_9 ,
V_263 , V_2 -> V_69 , F_43 ( V_106 -> V_405 ) , V_106 ) ;
goto V_403;
}
if ( F_221 ( V_2 -> V_3 . V_405 != V_406 ,
V_125 , V_410 , V_411 ) ) {
F_223 ( V_125 , V_409 ,
L_10 ,
V_263 , V_2 -> V_69 , V_2 , V_2 -> V_3 . V_405 ) ;
goto V_403;
}
if ( F_64 ( V_2 -> V_3 . V_133 ) ) {
if ( F_221 (
( V_2 -> V_3 . V_12 != V_182 ) &&
( V_2 -> V_3 . V_12 != V_13 ) ,
V_125 , V_412 , V_413 ) ) {
F_223 ( V_125 , V_409 ,
L_11 ,
V_263 , V_2 -> V_69 , V_2 ) ;
goto V_403;
}
} else if ( F_59 ( V_2 -> V_3 . V_133 ) ) {
if ( F_221 (
( V_2 -> V_3 . V_12 != V_182 ) &&
( V_2 -> V_3 . V_12 != V_13 ) &&
( V_2 -> V_3 . V_12 != V_414 ) ,
V_125 , V_415 , V_416 ) ) {
F_223 ( V_125 , V_409 ,
L_12 ,
V_263 , V_2 -> V_69 , V_2 ) ;
goto V_403;
}
}
if ( F_221 ( V_2 -> V_3 . V_142 + V_2 -> V_3 . V_187 >
V_2 -> V_3 . V_143 , V_125 , V_417 ,
V_418 ) ) {
F_223 ( V_125 , V_409 ,
L_13
L_14 ,
V_263 , V_2 -> V_69 ,
V_2 -> V_3 . V_142 + V_2 -> V_3 . V_187 ,
V_2 -> V_3 . V_143 , V_2 ) ;
goto V_403;
}
if ( F_221 ( V_2 -> V_3 . V_268 > V_125 -> V_8 . V_419 ,
V_125 , V_420 , V_421 ) ) {
F_223 ( V_125 , V_409 ,
L_15 ,
V_263 , V_2 -> V_69 , V_2 -> V_3 . V_268 , V_2 ) ;
goto V_403;
}
if ( V_2 -> V_3 . V_132 < 3 )
V_2 -> V_3 . V_422 ++ ;
F_224 ( V_106 , & V_2 -> V_3 ) ;
if ( V_2 -> V_3 . V_422 == V_423 )
V_2 -> V_3 . V_422 = 0 ;
F_225 ( V_2 , V_106 , V_300 , V_258 ) ;
if ( F_41 ( V_2 ) )
F_225 ( V_2 , V_106 , V_300 , V_424 ) ;
F_154 ( V_125 , V_299 ) ;
V_300 -> V_330 = V_300 -> V_331 ;
V_300 -> V_331 = 0 ;
V_300 -> V_317 = 1 ;
F_167 ( V_125 -> V_320 , & V_300 -> V_321 ,
& V_300 -> V_322 . V_323 ) ;
F_177 ( V_299 , V_425 , & V_300 -> V_322 ) ;
if ( V_2 -> V_3 . V_132 == 3 )
V_106 -> V_160 = F_226 ( V_300 -> V_322 . V_323 ) ;
F_151 ( V_125 , V_106 ) ;
ASSERT ( V_299 -> V_314 != NULL ) ;
ASSERT ( V_299 -> V_395 != NULL ) ;
return 0 ;
V_403:
return - V_396 ;
}
