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
static void
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
int
F_42 (
T_3 * V_112 ,
struct V_113 * V_114 ,
T_3 * * V_115 ,
struct V_113 * V_116 )
{
T_8 V_117 ;
int error ;
F_43 ( V_112 , V_114 ) ;
if ( F_44 ( V_112 -> V_7 ) )
return - V_118 ;
F_4 ( V_112 , V_22 ) ;
error = F_45 ( NULL , V_112 , V_114 , & V_117 , V_116 ) ;
if ( error )
goto V_119;
error = F_46 ( V_112 -> V_7 , NULL , V_117 , 0 , 0 , V_115 ) ;
if ( error )
goto V_120;
F_18 ( V_112 , V_22 ) ;
return 0 ;
V_120:
if ( V_116 )
F_47 ( V_116 -> V_114 ) ;
V_119:
F_18 ( V_112 , V_22 ) ;
* V_115 = NULL ;
return error ;
}
static int
F_48 (
T_9 * V_121 ,
T_3 * V_122 ,
T_10 V_123 ,
T_11 V_124 ,
T_12 V_125 ,
T_13 V_126 ,
int V_127 ,
T_14 * * V_128 ,
T_3 * * V_115 )
{
struct V_129 * V_130 = V_121 -> V_131 ;
T_8 V_132 ;
T_3 * V_2 ;
T_2 V_77 ;
int error ;
struct V_133 V_134 ;
struct V_135 * V_135 ;
error = F_49 ( V_121 , V_122 ? V_122 -> V_69 : 0 , V_123 , V_127 ,
V_128 , & V_132 ) ;
if ( error )
return error ;
if ( * V_128 || V_132 == V_136 ) {
* V_115 = NULL ;
return 0 ;
}
ASSERT ( * V_128 == NULL ) ;
error = F_46 ( V_130 , V_121 , V_132 , V_137 ,
V_17 , & V_2 ) ;
if ( error )
return error ;
ASSERT ( V_2 != NULL ) ;
V_135 = F_50 ( V_2 ) ;
if ( V_2 -> V_3 . V_138 == 1 )
V_2 -> V_3 . V_138 = 2 ;
V_135 -> V_139 = V_123 ;
F_51 ( V_135 , V_124 ) ;
V_2 -> V_3 . V_140 = F_52 ( F_53 () ) ;
V_2 -> V_3 . V_141 = F_54 ( F_55 () ) ;
F_56 ( V_2 , V_126 ) ;
if ( V_122 && F_57 ( V_122 ) ) {
V_2 -> V_3 . V_141 = V_122 -> V_3 . V_141 ;
if ( ( F_50 ( V_122 ) -> V_139 & V_142 ) && F_58 ( V_123 ) )
V_135 -> V_139 |= V_142 ;
}
if ( ( V_143 ) &&
( V_135 -> V_139 & V_142 ) &&
( ! F_59 ( F_60 ( V_2 -> V_3 . V_141 ) ) ) )
V_135 -> V_139 &= ~ V_142 ;
V_2 -> V_3 . V_144 = 0 ;
V_2 -> V_3 . V_145 = 0 ;
ASSERT ( V_2 -> V_3 . V_146 == 0 ) ;
V_134 = F_61 ( V_130 -> V_147 ) ;
V_135 -> V_148 = V_134 ;
V_135 -> V_149 = V_134 ;
V_135 -> V_150 = V_134 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_151 = 0 ;
V_2 -> V_3 . V_152 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( V_2 -> V_3 . V_138 == 3 ) {
V_135 -> V_153 = 1 ;
V_2 -> V_3 . V_75 = 0 ;
V_2 -> V_3 . V_154 . V_155 = ( V_156 ) V_134 . V_157 ;
V_2 -> V_3 . V_154 . V_158 = ( V_156 ) V_134 . V_159 ;
}
V_77 = V_160 ;
switch ( V_123 & V_161 ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
V_2 -> V_3 . V_12 = V_166 ;
V_2 -> V_14 . V_167 . V_168 = V_125 ;
V_2 -> V_14 . V_15 = 0 ;
V_77 |= V_169 ;
break;
case V_170 :
case V_171 :
if ( V_122 && ( V_122 -> V_3 . V_4 & V_78 ) ) {
T_7 V_75 = 0 ;
T_2 V_4 = 0 ;
if ( F_58 ( V_123 ) ) {
if ( V_122 -> V_3 . V_4 & V_93 )
V_4 |= V_93 ;
if ( V_122 -> V_3 . V_4 & V_100 ) {
V_4 |= V_100 ;
V_2 -> V_3 . V_6 = V_122 -> V_3 . V_6 ;
}
if ( V_122 -> V_3 . V_4 & V_95 )
V_4 |= V_95 ;
} else if ( F_62 ( V_123 ) ) {
if ( V_122 -> V_3 . V_4 & V_93 )
V_4 |= V_79 ;
if ( V_122 -> V_3 . V_4 & V_100 ) {
V_4 |= V_5 ;
V_2 -> V_3 . V_6 = V_122 -> V_3 . V_6 ;
}
}
if ( ( V_122 -> V_3 . V_4 & V_89 ) &&
V_172 )
V_4 |= V_89 ;
if ( ( V_122 -> V_3 . V_4 & V_91 ) &&
V_173 )
V_4 |= V_91 ;
if ( ( V_122 -> V_3 . V_4 & V_87 ) &&
V_174 )
V_4 |= V_87 ;
if ( ( V_122 -> V_3 . V_4 & V_97 ) &&
V_175 )
V_4 |= V_97 ;
if ( ( V_122 -> V_3 . V_4 & V_102 ) &&
V_176 )
V_4 |= V_102 ;
if ( V_122 -> V_3 . V_4 & V_104 )
V_4 |= V_104 ;
if ( V_122 -> V_3 . V_75 & V_107 )
V_75 |= V_107 ;
V_2 -> V_3 . V_4 |= V_4 ;
V_2 -> V_3 . V_75 |= V_75 ;
}
case V_177 :
V_2 -> V_3 . V_12 = V_178 ;
V_2 -> V_14 . V_15 = V_16 ;
V_2 -> V_14 . V_179 = V_2 -> V_14 . V_180 = 0 ;
V_2 -> V_14 . V_181 . V_182 = NULL ;
break;
default:
ASSERT ( 0 ) ;
}
V_2 -> V_3 . V_18 = V_178 ;
V_2 -> V_3 . V_183 = 0 ;
F_63 ( V_121 , V_2 , V_17 ) ;
F_64 ( V_121 , V_2 , V_77 ) ;
F_65 ( V_2 ) ;
* V_115 = V_2 ;
return 0 ;
}
int
F_66 (
T_9 * * V_184 ,
T_3 * V_112 ,
T_10 V_123 ,
T_11 V_124 ,
T_12 V_125 ,
T_13 V_126 ,
int V_127 ,
T_3 * * V_115 ,
int * V_185 )
{
T_9 * V_121 ;
T_3 * V_2 ;
T_14 * V_128 = NULL ;
int V_186 ;
void * V_187 ;
T_2 V_188 ;
V_121 = * V_184 ;
ASSERT ( V_121 -> V_189 & V_190 ) ;
V_186 = F_48 ( V_121 , V_112 , V_123 , V_124 , V_125 , V_126 , V_127 ,
& V_128 , & V_2 ) ;
if ( V_186 ) {
* V_115 = NULL ;
return V_186 ;
}
if ( ! V_128 && ! V_2 ) {
* V_115 = NULL ;
return - V_191 ;
}
if ( V_128 ) {
F_67 ( V_121 , V_128 ) ;
V_187 = NULL ;
V_188 = 0 ;
if ( V_121 -> V_192 ) {
V_187 = ( void * ) V_121 -> V_192 ;
V_121 -> V_192 = NULL ;
V_188 = V_121 -> V_189 & V_193 ;
V_121 -> V_189 &= ~ ( V_193 ) ;
}
V_186 = F_68 ( & V_121 , NULL ) ;
if ( V_185 != NULL )
* V_185 = 1 ;
if ( V_187 ) {
V_121 -> V_192 = V_187 ;
V_121 -> V_189 |= V_188 ;
}
if ( V_186 ) {
F_69 ( V_128 ) ;
* V_184 = V_121 ;
* V_115 = NULL ;
return V_186 ;
}
F_70 ( V_121 , V_128 ) ;
V_186 = F_48 ( V_121 , V_112 , V_123 , V_124 , V_125 , V_126 ,
V_127 , & V_128 , & V_2 ) ;
if ( V_186 ) {
* V_184 = V_121 ;
* V_115 = NULL ;
return V_186 ;
}
ASSERT ( ! V_128 && V_2 ) ;
} else {
if ( V_185 != NULL )
* V_185 = 0 ;
}
* V_115 = V_2 ;
* V_184 = V_121 ;
return 0 ;
}
static int
F_71 (
T_9 * V_121 ,
T_3 * V_2 )
{
F_72 ( V_121 , V_2 , V_194 ) ;
F_73 ( F_50 ( V_2 ) ) ;
F_64 ( V_121 , V_2 , V_160 ) ;
if ( F_50 ( V_2 ) -> V_195 )
return 0 ;
return F_74 ( V_121 , V_2 ) ;
}
static int
F_75 (
T_9 * V_121 ,
T_3 * V_2 )
{
F_72 ( V_121 , V_2 , V_194 ) ;
ASSERT ( V_2 -> V_3 . V_138 > 1 ) ;
F_76 ( F_50 ( V_2 ) ) ;
F_64 ( V_121 , V_2 , V_160 ) ;
return 0 ;
}
int
F_77 (
T_3 * V_112 ,
struct V_113 * V_114 ,
T_10 V_123 ,
T_12 V_125 ,
T_3 * * V_115 )
{
int V_196 = F_58 ( V_123 ) ;
struct V_129 * V_130 = V_112 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_197 * V_121 = NULL ;
int error ;
struct V_198 V_199 ;
T_15 V_200 ;
bool V_201 = false ;
T_13 V_126 ;
struct V_202 * V_203 = NULL ;
struct V_202 * V_204 = NULL ;
struct V_202 * V_205 = NULL ;
struct V_206 * V_207 ;
T_2 V_208 ;
F_78 ( V_112 , V_114 ) ;
if ( F_44 ( V_130 ) )
return - V_118 ;
V_126 = F_79 ( V_112 ) ;
error = F_80 ( V_112 , F_52 ( F_53 () ) ,
F_54 ( F_55 () ) , V_126 ,
V_209 | V_210 ,
& V_203 , & V_204 , & V_205 ) ;
if ( error )
return error ;
if ( V_196 ) {
V_125 = 0 ;
V_208 = F_81 ( V_130 , V_114 -> V_211 ) ;
V_207 = & F_82 ( V_130 ) -> V_212 ;
} else {
V_208 = F_83 ( V_130 , V_114 -> V_211 ) ;
V_207 = & F_82 ( V_130 ) -> V_213 ;
}
error = F_84 ( V_130 , V_207 , V_208 , 0 , 0 , & V_121 ) ;
if ( error == - V_191 ) {
F_85 ( V_130 ) ;
error = F_84 ( V_130 , V_207 , V_208 , 0 , 0 , & V_121 ) ;
}
if ( error == - V_191 ) {
V_208 = 0 ;
error = F_84 ( V_130 , V_207 , 0 , 0 , 0 , & V_121 ) ;
}
if ( error )
goto V_214;
F_4 ( V_112 , V_23 | V_17 |
V_45 | V_39 ) ;
V_201 = true ;
F_86 ( & V_199 , & V_200 ) ;
error = F_87 ( V_121 , V_130 , V_203 , V_204 ,
V_205 , V_208 , 1 , 0 ) ;
if ( error )
goto V_215;
if ( ! V_208 ) {
error = F_88 ( V_121 , V_112 , V_114 ) ;
if ( error )
goto V_215;
}
error = F_66 ( & V_121 , V_112 , V_123 , V_196 ? 2 : 1 , V_125 ,
V_126 , V_208 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_215;
F_63 ( V_121 , V_112 , V_23 | V_17 ) ;
V_201 = false ;
error = F_89 ( V_121 , V_112 , V_114 , V_2 -> V_69 ,
& V_200 , & V_199 , V_208 ?
V_208 - F_90 ( V_130 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_191 ) ;
goto V_215;
}
F_72 ( V_121 , V_112 , V_216 | V_194 ) ;
F_64 ( V_121 , V_112 , V_160 ) ;
if ( V_196 ) {
error = F_91 ( V_121 , V_2 , V_112 ) ;
if ( error )
goto V_217;
error = F_75 ( V_121 , V_112 ) ;
if ( error )
goto V_217;
}
if ( V_130 -> V_218 & ( V_219 | V_220 ) )
F_92 ( V_121 ) ;
F_93 ( V_121 , V_2 , V_203 , V_204 , V_205 ) ;
error = F_94 ( & V_121 , & V_199 , NULL ) ;
if ( error )
goto V_217;
error = F_95 ( V_121 ) ;
if ( error )
goto V_214;
F_96 ( V_203 ) ;
F_96 ( V_204 ) ;
F_96 ( V_205 ) ;
* V_115 = V_2 ;
return 0 ;
V_217:
F_97 ( & V_199 ) ;
V_215:
F_98 ( V_121 ) ;
V_214:
if ( V_2 ) {
F_99 ( V_2 ) ;
F_100 ( V_2 ) ;
}
F_96 ( V_203 ) ;
F_96 ( V_204 ) ;
F_96 ( V_205 ) ;
if ( V_201 )
F_18 ( V_112 , V_23 | V_17 ) ;
return error ;
}
int
F_101 (
struct V_1 * V_112 ,
struct V_221 * V_221 ,
T_10 V_123 ,
struct V_1 * * V_115 )
{
struct V_129 * V_130 = V_112 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_197 * V_121 = NULL ;
int error ;
T_13 V_126 ;
struct V_202 * V_203 = NULL ;
struct V_202 * V_204 = NULL ;
struct V_202 * V_205 = NULL ;
struct V_206 * V_207 ;
T_2 V_208 ;
if ( F_44 ( V_130 ) )
return - V_118 ;
V_126 = F_79 ( V_112 ) ;
error = F_80 ( V_112 , F_52 ( F_53 () ) ,
F_54 ( F_55 () ) , V_126 ,
V_209 | V_210 ,
& V_203 , & V_204 , & V_205 ) ;
if ( error )
return error ;
V_208 = F_90 ( V_130 ) ;
V_207 = & F_82 ( V_130 ) -> V_222 ;
error = F_84 ( V_130 , V_207 , V_208 , 0 , 0 , & V_121 ) ;
if ( error == - V_191 ) {
V_208 = 0 ;
error = F_84 ( V_130 , V_207 , 0 , 0 , 0 , & V_121 ) ;
}
if ( error )
goto V_214;
error = F_87 ( V_121 , V_130 , V_203 , V_204 ,
V_205 , V_208 , 1 , 0 ) ;
if ( error )
goto V_215;
error = F_66 ( & V_121 , V_112 , V_123 , 1 , 0 ,
V_126 , V_208 > 0 , & V_2 , NULL ) ;
if ( error )
goto V_215;
if ( V_130 -> V_218 & V_219 )
F_92 ( V_121 ) ;
F_93 ( V_121 , V_2 , V_203 , V_204 , V_205 ) ;
error = F_74 ( V_121 , V_2 ) ;
if ( error )
goto V_215;
error = F_95 ( V_121 ) ;
if ( error )
goto V_214;
F_96 ( V_203 ) ;
F_96 ( V_204 ) ;
F_96 ( V_205 ) ;
* V_115 = V_2 ;
return 0 ;
V_215:
F_98 ( V_121 ) ;
V_214:
if ( V_2 ) {
F_99 ( V_2 ) ;
F_100 ( V_2 ) ;
}
F_96 ( V_203 ) ;
F_96 ( V_204 ) ;
F_96 ( V_205 ) ;
return error ;
}
int
F_102 (
T_3 * V_223 ,
T_3 * V_224 ,
struct V_113 * V_225 )
{
T_16 * V_130 = V_223 -> V_7 ;
T_9 * V_121 ;
int error ;
struct V_198 V_199 ;
T_15 V_200 ;
int V_208 ;
F_103 ( V_223 , V_225 ) ;
ASSERT ( ! F_58 ( F_50 ( V_224 ) -> V_139 ) ) ;
if ( F_44 ( V_130 ) )
return - V_118 ;
error = F_104 ( V_224 , 0 ) ;
if ( error )
goto V_226;
error = F_104 ( V_223 , 0 ) ;
if ( error )
goto V_226;
V_208 = F_105 ( V_130 , V_225 -> V_211 ) ;
error = F_84 ( V_130 , & F_82 ( V_130 ) -> V_227 , V_208 , 0 , 0 , & V_121 ) ;
if ( error == - V_191 ) {
V_208 = 0 ;
error = F_84 ( V_130 , & F_82 ( V_130 ) -> V_227 , 0 , 0 , 0 , & V_121 ) ;
}
if ( error )
goto V_226;
F_4 ( V_223 , V_23 | V_45 ) ;
F_30 ( V_224 , V_223 , V_17 ) ;
F_63 ( V_121 , V_224 , V_17 ) ;
F_63 ( V_121 , V_223 , V_23 | V_17 ) ;
if ( F_106 ( ( V_223 -> V_3 . V_4 & V_95 ) &&
( F_107 ( V_223 ) != F_107 ( V_224 ) ) ) ) {
error = - V_228 ;
goto V_229;
}
if ( ! V_208 ) {
error = F_88 ( V_121 , V_223 , V_225 ) ;
if ( error )
goto V_229;
}
F_86 ( & V_199 , & V_200 ) ;
if ( F_50 ( V_224 ) -> V_195 == 0 ) {
error = F_108 ( V_121 , V_224 ) ;
if ( error )
goto V_229;
}
error = F_89 ( V_121 , V_223 , V_225 , V_224 -> V_69 ,
& V_200 , & V_199 , V_208 ) ;
if ( error )
goto V_229;
F_72 ( V_121 , V_223 , V_216 | V_194 ) ;
F_64 ( V_121 , V_223 , V_160 ) ;
error = F_75 ( V_121 , V_224 ) ;
if ( error )
goto V_229;
if ( V_130 -> V_218 & ( V_219 | V_220 ) )
F_92 ( V_121 ) ;
error = F_94 ( & V_121 , & V_199 , NULL ) ;
if ( error ) {
F_97 ( & V_199 ) ;
goto V_229;
}
return F_95 ( V_121 ) ;
V_229:
F_98 ( V_121 ) ;
V_226:
return error ;
}
int
F_109 (
struct V_197 * * V_184 ,
struct V_1 * V_2 ,
int V_230 ,
T_17 V_231 )
{
struct V_129 * V_130 = V_2 -> V_7 ;
struct V_197 * V_121 = * V_184 ;
struct V_198 V_199 ;
T_15 V_200 ;
T_18 V_232 ;
T_18 V_233 ;
T_19 V_234 ;
int error = 0 ;
int V_235 = 0 ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( ! F_110 ( & F_50 ( V_2 ) -> V_236 ) ||
F_23 ( V_2 , V_23 ) ) ;
ASSERT ( V_231 <= F_111 ( V_2 ) ) ;
ASSERT ( V_121 -> V_189 & V_190 ) ;
ASSERT ( V_2 -> V_58 != NULL ) ;
ASSERT ( V_2 -> V_58 -> V_237 == 0 ) ;
ASSERT ( ! F_112 ( V_130 , V_2 ) ) ;
F_113 ( V_2 , V_231 ) ;
V_232 = F_114 ( V_130 , ( V_238 ) V_231 ) ;
V_233 = F_114 ( V_130 , V_130 -> V_147 -> V_239 ) ;
if ( V_232 == V_233 )
return 0 ;
ASSERT ( V_232 < V_233 ) ;
V_234 = V_233 - V_232 + 1 ;
while ( ! V_235 ) {
F_86 ( & V_199 , & V_200 ) ;
error = F_115 ( V_121 , V_2 ,
V_232 , V_234 ,
F_116 ( V_230 ) ,
V_240 ,
& V_200 , & V_199 ,
& V_235 ) ;
if ( error )
goto V_217;
error = F_94 ( & V_121 , & V_199 , V_2 ) ;
if ( error )
goto V_217;
error = F_68 ( & V_121 , V_2 ) ;
if ( error )
goto V_31;
}
F_64 ( V_121 , V_2 , V_160 ) ;
F_117 ( V_2 , V_231 ) ;
V_31:
* V_184 = V_121 ;
return error ;
V_217:
F_97 ( & V_199 ) ;
goto V_31;
}
int
F_118 (
T_3 * V_2 )
{
T_16 * V_130 = V_2 -> V_7 ;
int error ;
if ( ! F_62 ( F_50 ( V_2 ) -> V_139 ) || ( F_50 ( V_2 ) -> V_139 == 0 ) )
return 0 ;
if ( V_130 -> V_218 & V_241 )
return 0 ;
if ( ! F_44 ( V_130 ) ) {
int V_242 ;
V_242 = F_119 ( V_2 , V_243 ) ;
if ( V_242 ) {
F_120 ( V_2 , V_244 ) ;
if ( V_2 -> V_245 > 0 ) {
error = F_121 ( F_50 ( V_2 ) -> V_246 ) ;
if ( error )
return error ;
}
}
}
if ( F_50 ( V_2 ) -> V_195 == 0 )
return 0 ;
if ( F_122 ( V_2 , false ) ) {
if ( F_123 ( V_2 , V_244 ) )
return 0 ;
error = F_124 ( V_130 , V_2 , true ) ;
if ( error && error != - V_247 )
return error ;
if ( V_2 -> V_245 )
F_125 ( V_2 , V_244 ) ;
}
return 0 ;
}
STATIC int
F_126 (
struct V_1 * V_2 )
{
struct V_129 * V_130 = V_2 -> V_7 ;
struct V_197 * V_121 ;
int error ;
error = F_84 ( V_130 , & F_82 ( V_130 ) -> V_248 , 0 , 0 , 0 , & V_121 ) ;
if ( error ) {
ASSERT ( F_44 ( V_130 ) ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_63 ( V_121 , V_2 , 0 ) ;
V_2 -> V_3 . V_144 = 0 ;
F_64 ( V_121 , V_2 , V_160 ) ;
error = F_109 ( & V_121 , V_2 , V_249 , 0 ) ;
if ( error )
goto V_250;
ASSERT ( V_2 -> V_3 . V_145 == 0 ) ;
error = F_95 ( V_121 ) ;
if ( error )
goto V_251;
F_18 ( V_2 , V_17 ) ;
return 0 ;
V_250:
F_98 ( V_121 ) ;
V_251:
F_18 ( V_2 , V_17 ) ;
return error ;
}
STATIC int
F_127 (
struct V_1 * V_2 )
{
struct V_198 V_199 ;
T_15 V_200 ;
struct V_129 * V_130 = V_2 -> V_7 ;
struct V_197 * V_121 ;
int error ;
error = F_84 ( V_130 , & F_82 ( V_130 ) -> V_252 ,
F_128 ( V_130 ) , 0 , V_253 , & V_121 ) ;
if ( error ) {
if ( error == - V_191 ) {
F_129 ( V_130 ,
L_1
L_2 ) ;
} else {
ASSERT ( F_44 ( V_130 ) ) ;
}
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_63 ( V_121 , V_2 , 0 ) ;
F_86 ( & V_199 , & V_200 ) ;
error = F_130 ( V_121 , V_2 , & V_199 ) ;
if ( error ) {
if ( ! F_44 ( V_130 ) ) {
F_131 ( V_130 , L_3 ,
V_254 , error ) ;
F_132 ( V_130 , V_255 ) ;
}
F_98 ( V_121 ) ;
F_18 ( V_2 , V_17 ) ;
return error ;
}
F_133 ( V_121 , V_2 , V_256 , - 1 ) ;
error = F_94 ( & V_121 , & V_199 , NULL ) ;
if ( error ) {
F_131 ( V_130 , L_4 ,
V_254 , error ) ;
F_97 ( & V_199 ) ;
}
error = F_95 ( V_121 ) ;
if ( error )
F_131 ( V_130 , L_5 ,
V_254 , error ) ;
F_18 ( V_2 , V_17 ) ;
return 0 ;
}
void
F_134 (
T_3 * V_2 )
{
struct V_129 * V_130 ;
int error ;
int V_257 = 0 ;
if ( F_50 ( V_2 ) -> V_139 == 0 ) {
ASSERT ( V_2 -> V_14 . V_180 == 0 ) ;
ASSERT ( V_2 -> V_14 . V_258 == 0 ) ;
return;
}
V_130 = V_2 -> V_7 ;
if ( V_130 -> V_218 & V_241 )
return;
if ( F_50 ( V_2 ) -> V_195 != 0 ) {
if ( F_122 ( V_2 , true ) )
F_124 ( V_130 , V_2 , false ) ;
return;
}
if ( F_62 ( F_50 ( V_2 ) -> V_139 ) &&
( V_2 -> V_3 . V_144 != 0 || F_111 ( V_2 ) != 0 ||
V_2 -> V_3 . V_145 > 0 || V_2 -> V_245 > 0 ) )
V_257 = 1 ;
error = F_104 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_135 ( F_50 ( V_2 ) -> V_139 ) )
error = F_136 ( V_2 ) ;
else if ( V_257 )
error = F_126 ( V_2 ) ;
if ( error )
return;
if ( F_41 ( V_2 ) ) {
error = F_137 ( V_2 ) ;
if ( error )
return;
}
ASSERT ( ! V_2 -> V_19 ) ;
ASSERT ( V_2 -> V_3 . V_183 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_259 == 0 ) ;
error = F_127 ( V_2 ) ;
if ( error )
return;
F_138 ( V_2 ) ;
}
STATIC int
F_74 (
struct V_197 * V_121 ,
struct V_1 * V_2 )
{
T_16 * V_130 = V_121 -> V_131 ;
T_20 * V_260 ;
T_21 * V_261 ;
T_14 * V_262 ;
T_14 * V_263 ;
T_22 V_264 ;
short V_265 ;
int V_266 ;
int error ;
ASSERT ( F_50 ( V_2 ) -> V_139 != 0 ) ;
error = F_139 ( V_130 , V_121 , F_140 ( V_130 , V_2 -> V_69 ) , & V_262 ) ;
if ( error )
return error ;
V_260 = F_141 ( V_262 ) ;
V_264 = F_142 ( V_130 , V_2 -> V_69 ) ;
ASSERT ( V_264 != 0 ) ;
V_265 = V_264 % V_267 ;
ASSERT ( V_260 -> V_268 [ V_265 ] ) ;
ASSERT ( F_143 ( V_260 -> V_268 [ V_265 ] ) != V_264 ) ;
if ( V_260 -> V_268 [ V_265 ] != F_144 ( V_269 ) ) {
error = F_145 ( V_130 , V_121 , & V_2 -> V_270 , & V_261 , & V_263 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_261 -> V_271 == F_144 ( V_269 ) ) ;
V_261 -> V_271 = V_260 -> V_268 [ V_265 ] ;
V_266 = V_2 -> V_270 . V_272 +
F_146 ( T_21 , V_271 ) ;
F_147 ( V_130 , V_261 ) ;
F_148 ( V_121 , V_263 ) ;
F_149 ( V_121 , V_263 , V_266 ,
( V_266 + sizeof( T_22 ) - 1 ) ) ;
F_150 ( V_130 , V_263 ) ;
}
ASSERT ( V_264 != 0 ) ;
V_260 -> V_268 [ V_265 ] = F_144 ( V_264 ) ;
V_266 = F_146 ( T_20 , V_268 ) +
( sizeof( T_22 ) * V_265 ) ;
F_151 ( V_121 , V_262 , V_273 ) ;
F_149 ( V_121 , V_262 , V_266 ,
( V_266 + sizeof( T_22 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_108 (
T_9 * V_121 ,
T_3 * V_2 )
{
T_8 V_274 ;
T_16 * V_130 ;
T_20 * V_260 ;
T_21 * V_261 ;
T_14 * V_262 ;
T_14 * V_263 ;
T_23 V_275 ;
T_22 V_264 ;
T_22 V_276 ;
T_14 * V_277 ;
T_21 * V_278 = NULL ;
short V_265 ;
int V_266 , V_279 = 0 ;
int error ;
V_130 = V_121 -> V_131 ;
V_275 = F_140 ( V_130 , V_2 -> V_69 ) ;
error = F_139 ( V_130 , V_121 , V_275 , & V_262 ) ;
if ( error )
return error ;
V_260 = F_141 ( V_262 ) ;
V_264 = F_142 ( V_130 , V_2 -> V_69 ) ;
ASSERT ( V_264 != 0 ) ;
V_265 = V_264 % V_267 ;
ASSERT ( V_260 -> V_268 [ V_265 ] != F_144 ( V_269 ) ) ;
ASSERT ( V_260 -> V_268 [ V_265 ] ) ;
if ( F_143 ( V_260 -> V_268 [ V_265 ] ) == V_264 ) {
error = F_145 ( V_130 , V_121 , & V_2 -> V_270 , & V_261 , & V_263 ,
0 , 0 ) ;
if ( error ) {
F_152 ( V_130 , L_6 ,
V_254 , error ) ;
return error ;
}
V_276 = F_143 ( V_261 -> V_271 ) ;
ASSERT ( V_276 != 0 ) ;
if ( V_276 != V_269 ) {
V_261 -> V_271 = F_144 ( V_269 ) ;
V_266 = V_2 -> V_270 . V_272 +
F_146 ( T_21 , V_271 ) ;
F_147 ( V_130 , V_261 ) ;
F_148 ( V_121 , V_263 ) ;
F_149 ( V_121 , V_263 , V_266 ,
( V_266 + sizeof( T_22 ) - 1 ) ) ;
F_150 ( V_130 , V_263 ) ;
} else {
F_153 ( V_121 , V_263 ) ;
}
ASSERT ( V_276 != 0 ) ;
ASSERT ( V_276 != V_264 ) ;
V_260 -> V_268 [ V_265 ] = F_144 ( V_276 ) ;
V_266 = F_146 ( T_20 , V_268 ) +
( sizeof( T_22 ) * V_265 ) ;
F_151 ( V_121 , V_262 , V_273 ) ;
F_149 ( V_121 , V_262 , V_266 ,
( V_266 + sizeof( T_22 ) - 1 ) ) ;
} else {
V_276 = F_143 ( V_260 -> V_268 [ V_265 ] ) ;
V_277 = NULL ;
while ( V_276 != V_264 ) {
struct V_280 V_281 ;
if ( V_277 )
F_153 ( V_121 , V_277 ) ;
V_281 . V_282 = 0 ;
V_274 = F_154 ( V_130 , V_275 , V_276 ) ;
error = V_280 ( V_130 , V_121 , V_274 , & V_281 , 0 ) ;
if ( error ) {
F_152 ( V_130 ,
L_7 ,
V_254 , error ) ;
return error ;
}
error = F_145 ( V_130 , V_121 , & V_281 , & V_278 ,
& V_277 , 0 , 0 ) ;
if ( error ) {
F_152 ( V_130 ,
L_6 ,
V_254 , error ) ;
return error ;
}
V_279 = V_281 . V_272 ;
V_276 = F_143 ( V_278 -> V_271 ) ;
ASSERT ( V_276 != V_269 ) ;
ASSERT ( V_276 != 0 ) ;
}
error = F_145 ( V_130 , V_121 , & V_2 -> V_270 , & V_261 , & V_263 ,
0 , 0 ) ;
if ( error ) {
F_152 ( V_130 , L_8 ,
V_254 , error ) ;
return error ;
}
V_276 = F_143 ( V_261 -> V_271 ) ;
ASSERT ( V_276 != 0 ) ;
ASSERT ( V_276 != V_264 ) ;
if ( V_276 != V_269 ) {
V_261 -> V_271 = F_144 ( V_269 ) ;
V_266 = V_2 -> V_270 . V_272 +
F_146 ( T_21 , V_271 ) ;
F_147 ( V_130 , V_261 ) ;
F_148 ( V_121 , V_263 ) ;
F_149 ( V_121 , V_263 , V_266 ,
( V_266 + sizeof( T_22 ) - 1 ) ) ;
F_150 ( V_130 , V_263 ) ;
} else {
F_153 ( V_121 , V_263 ) ;
}
V_278 -> V_271 = F_144 ( V_276 ) ;
ASSERT ( V_276 != 0 ) ;
V_266 = V_279 + F_146 ( T_21 , V_271 ) ;
F_147 ( V_130 , V_278 ) ;
F_148 ( V_121 , V_277 ) ;
F_149 ( V_121 , V_277 , V_266 ,
( V_266 + sizeof( T_22 ) - 1 ) ) ;
F_150 ( V_130 , V_277 ) ;
}
return 0 ;
}
STATIC int
F_155 (
T_3 * V_283 ,
T_9 * V_121 ,
struct V_284 * V_285 )
{
T_16 * V_130 = V_283 -> V_7 ;
int V_286 ;
int V_287 ;
int V_288 ;
int V_53 , V_54 ;
int V_289 ;
T_24 V_290 ;
T_14 * V_291 ;
T_3 * V_2 ;
T_25 * V_292 ;
T_4 * V_293 ;
struct V_294 * V_295 ;
T_8 V_117 ;
V_117 = V_285 -> V_296 ;
V_295 = F_156 ( V_130 , F_140 ( V_130 , V_117 ) ) ;
V_286 = F_157 ( V_130 ) ;
V_287 = V_286 << V_130 -> V_8 . V_297 ;
V_288 = V_130 -> V_298 / V_286 ;
for ( V_54 = 0 ; V_54 < V_288 ; V_54 ++ , V_117 += V_287 ) {
V_289 = V_117 - V_285 -> V_296 ;
if ( ( V_285 -> V_299 & F_158 ( V_289 ) ) == 0 ) {
ASSERT ( F_159 ( V_289 , V_287 ) == 0 ) ;
continue;
}
V_290 = F_160 ( V_130 , F_140 ( V_130 , V_117 ) ,
F_161 ( V_130 , V_117 ) ) ;
V_291 = F_162 ( V_121 , V_130 -> V_300 , V_290 ,
V_130 -> V_301 * V_286 ,
V_302 ) ;
if ( ! V_291 )
return - V_303 ;
V_291 -> V_304 = & V_305 ;
V_293 = V_291 -> V_306 ;
while ( V_293 ) {
if ( V_293 -> V_307 == V_308 ) {
V_292 = ( T_25 * ) V_293 ;
ASSERT ( V_292 -> V_309 == 1 ) ;
V_293 -> V_310 = V_311 ;
F_163 ( V_130 -> V_312 ,
& V_292 -> V_313 ,
& V_292 -> V_314 . V_315 ) ;
F_125 ( V_292 -> V_316 , V_317 ) ;
}
V_293 = V_293 -> V_318 ;
}
for ( V_53 = 0 ; V_53 < V_287 ; V_53 ++ ) {
V_319:
F_164 () ;
V_2 = F_165 ( & V_295 -> V_320 ,
F_142 ( V_130 , ( V_117 + V_53 ) ) ) ;
if ( ! V_2 ) {
F_166 () ;
continue;
}
F_167 ( & V_2 -> V_321 ) ;
if ( V_2 -> V_69 != V_117 + V_53 ||
F_168 ( V_2 , V_317 ) ) {
F_169 ( & V_2 -> V_321 ) ;
F_166 () ;
continue;
}
F_169 ( & V_2 -> V_321 ) ;
if ( V_2 != V_283 &&
! F_12 ( V_2 , V_17 ) ) {
F_166 () ;
F_28 ( 1 ) ;
goto V_319;
}
F_166 () ;
F_170 ( V_2 ) ;
F_125 ( V_2 , V_317 ) ;
V_292 = V_2 -> V_58 ;
if ( ! V_292 || F_171 ( V_2 ) ) {
ASSERT ( V_2 != V_283 ) ;
F_172 ( V_2 ) ;
F_18 ( V_2 , V_17 ) ;
continue;
}
V_292 -> V_322 = V_292 -> V_323 ;
V_292 -> V_323 = 0 ;
V_292 -> V_324 = 0 ;
V_292 -> V_309 = 1 ;
F_163 ( V_130 -> V_312 , & V_292 -> V_313 ,
& V_292 -> V_314 . V_315 ) ;
F_173 ( V_291 , V_311 ,
& V_292 -> V_314 ) ;
if ( V_2 != V_283 )
F_18 ( V_2 , V_17 ) ;
}
F_174 ( V_121 , V_291 ) ;
F_175 ( V_121 , V_291 ) ;
}
F_176 ( V_295 ) ;
return 0 ;
}
int
F_130 (
T_9 * V_121 ,
T_3 * V_2 ,
struct V_198 * V_199 )
{
int error ;
struct V_284 V_285 = { 0 } ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( F_50 ( V_2 ) -> V_195 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_145 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_183 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_144 == 0 || ! F_62 ( F_50 ( V_2 ) -> V_139 ) ) ;
ASSERT ( V_2 -> V_3 . V_146 == 0 ) ;
error = F_108 ( V_121 , V_2 ) ;
if ( error )
return error ;
error = F_177 ( V_121 , V_2 -> V_69 , V_199 , & V_285 ) ;
if ( error )
return error ;
F_50 ( V_2 ) -> V_139 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_151 = 0 ;
V_2 -> V_3 . V_259 = 0 ;
V_2 -> V_3 . V_12 = V_178 ;
V_2 -> V_3 . V_18 = V_178 ;
F_50 ( V_2 ) -> V_325 ++ ;
F_64 ( V_121 , V_2 , V_160 ) ;
if ( V_285 . V_326 )
error = F_155 ( V_2 , V_121 , & V_285 ) ;
return error ;
}
static void
F_178 (
struct V_1 * V_2 )
{
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
F_179 ( V_2 , V_21 ) ;
F_180 ( V_2 -> V_7 , V_2 -> V_58 -> V_327 , 0 ) ;
}
static void
F_181 (
struct V_1 * V_2 )
{
T_5 * V_70 = F_32 ( & V_2 -> V_71 , V_328 ) ;
F_33 ( V_73 , & V_2 -> V_71 , V_328 ) ;
F_178 ( V_2 ) ;
do {
F_182 ( V_70 , & V_73 . V_73 , V_74 ) ;
if ( F_183 ( V_2 ) )
F_36 () ;
} while ( F_183 ( V_2 ) );
F_38 ( V_70 , & V_73 . V_73 ) ;
}
void
F_184 (
struct V_1 * V_2 )
{
if ( F_183 ( V_2 ) )
F_181 ( V_2 ) ;
}
int
F_185 (
T_3 * V_112 ,
struct V_113 * V_114 ,
T_3 * V_2 )
{
T_16 * V_130 = V_112 -> V_7 ;
T_9 * V_121 = NULL ;
int V_196 = F_58 ( F_50 ( V_2 ) -> V_139 ) ;
int error = 0 ;
struct V_198 V_199 ;
T_15 V_200 ;
T_2 V_208 ;
F_186 ( V_112 , V_114 ) ;
if ( F_44 ( V_130 ) )
return - V_118 ;
error = F_104 ( V_112 , 0 ) ;
if ( error )
goto V_226;
error = F_104 ( V_2 , 0 ) ;
if ( error )
goto V_226;
V_208 = F_187 ( V_130 ) ;
error = F_84 ( V_130 , & F_82 ( V_130 ) -> V_329 , V_208 , 0 , 0 , & V_121 ) ;
if ( error == - V_191 ) {
V_208 = 0 ;
error = F_84 ( V_130 , & F_82 ( V_130 ) -> V_329 , 0 , 0 , 0 ,
& V_121 ) ;
}
if ( error ) {
ASSERT ( error != - V_191 ) ;
goto V_226;
}
F_4 ( V_112 , V_23 | V_45 ) ;
F_30 ( V_112 , V_2 , V_17 ) ;
F_63 ( V_121 , V_112 , V_23 | V_17 ) ;
F_63 ( V_121 , V_2 , V_17 ) ;
if ( V_196 ) {
ASSERT ( F_50 ( V_2 ) -> V_195 >= 2 ) ;
if ( F_50 ( V_2 ) -> V_195 != 2 ) {
error = - V_330 ;
goto V_215;
}
if ( ! F_188 ( V_2 ) ) {
error = - V_330 ;
goto V_215;
}
error = F_71 ( V_121 , V_112 ) ;
if ( error )
goto V_215;
error = F_71 ( V_121 , V_2 ) ;
if ( error )
goto V_215;
} else {
F_64 ( V_121 , V_112 , V_160 ) ;
}
F_72 ( V_121 , V_112 , V_216 | V_194 ) ;
error = F_71 ( V_121 , V_2 ) ;
if ( error )
goto V_215;
F_86 ( & V_199 , & V_200 ) ;
error = F_189 ( V_121 , V_112 , V_114 , V_2 -> V_69 ,
& V_200 , & V_199 , V_208 ) ;
if ( error ) {
ASSERT ( error != - V_331 ) ;
goto V_217;
}
if ( V_130 -> V_218 & ( V_219 | V_220 ) )
F_92 ( V_121 ) ;
error = F_94 ( & V_121 , & V_199 , NULL ) ;
if ( error )
goto V_217;
error = F_95 ( V_121 ) ;
if ( error )
goto V_226;
if ( V_196 && F_190 ( V_2 ) )
F_191 ( V_2 ) ;
return 0 ;
V_217:
F_97 ( & V_199 ) ;
V_215:
F_98 ( V_121 ) ;
V_226:
return error ;
}
STATIC void
F_192 (
struct V_1 * V_332 ,
struct V_1 * V_333 ,
struct V_1 * V_67 ,
struct V_1 * V_334 ,
struct V_1 * V_335 ,
struct V_1 * * V_336 ,
int * V_337 )
{
int V_53 , V_54 ;
ASSERT ( * V_337 == V_338 ) ;
memset ( V_336 , 0 , * V_337 * sizeof( struct V_1 * ) ) ;
V_53 = 0 ;
V_336 [ V_53 ++ ] = V_332 ;
V_336 [ V_53 ++ ] = V_333 ;
V_336 [ V_53 ++ ] = V_67 ;
if ( V_334 )
V_336 [ V_53 ++ ] = V_334 ;
if ( V_335 )
V_336 [ V_53 ++ ] = V_335 ;
* V_337 = V_53 ;
for ( V_53 = 0 ; V_53 < * V_337 ; V_53 ++ ) {
for ( V_54 = 1 ; V_54 < * V_337 ; V_54 ++ ) {
if ( V_336 [ V_54 ] -> V_69 < V_336 [ V_54 - 1 ] -> V_69 ) {
struct V_1 * V_68 = V_336 [ V_54 ] ;
V_336 [ V_54 ] = V_336 [ V_54 - 1 ] ;
V_336 [ V_54 - 1 ] = V_68 ;
}
}
}
}
static int
F_193 (
struct V_197 * V_121 ,
struct V_198 * V_199 )
{
int error ;
if ( V_121 -> V_131 -> V_218 & ( V_219 | V_220 ) )
F_92 ( V_121 ) ;
error = F_94 ( & V_121 , V_199 , NULL ) ;
if ( error ) {
F_97 ( V_199 ) ;
F_98 ( V_121 ) ;
return error ;
}
return F_95 ( V_121 ) ;
}
STATIC int
F_194 (
struct V_197 * V_121 ,
struct V_1 * V_332 ,
struct V_113 * V_339 ,
struct V_1 * V_67 ,
struct V_1 * V_333 ,
struct V_113 * V_340 ,
struct V_1 * V_334 ,
struct V_198 * V_199 ,
T_15 * V_200 ,
int V_341 )
{
int error = 0 ;
int V_342 = 0 ;
int V_343 = 0 ;
int V_344 = 0 ;
error = F_195 ( V_121 , V_332 , V_339 ,
V_334 -> V_69 ,
V_200 , V_199 , V_341 ) ;
if ( error )
goto V_345;
error = F_195 ( V_121 , V_333 , V_340 ,
V_67 -> V_69 ,
V_200 , V_199 , V_341 ) ;
if ( error )
goto V_345;
if ( V_332 != V_333 ) {
V_344 = V_216 | V_194 ;
if ( F_58 ( F_50 ( V_334 ) -> V_139 ) ) {
error = F_195 ( V_121 , V_334 , & V_346 ,
V_332 -> V_69 , V_200 ,
V_199 , V_341 ) ;
if ( error )
goto V_345;
if ( ! F_58 ( F_50 ( V_67 ) -> V_139 ) ) {
error = F_71 ( V_121 , V_333 ) ;
if ( error )
goto V_345;
error = F_75 ( V_121 , V_332 ) ;
if ( error )
goto V_345;
}
V_342 |= V_194 ;
V_343 |= V_216 | V_194 ;
}
if ( F_58 ( F_50 ( V_67 ) -> V_139 ) ) {
error = F_195 ( V_121 , V_67 , & V_346 ,
V_333 -> V_69 , V_200 ,
V_199 , V_341 ) ;
if ( error )
goto V_345;
if ( ! F_58 ( F_50 ( V_334 ) -> V_139 ) ) {
error = F_71 ( V_121 , V_332 ) ;
if ( error )
goto V_345;
error = F_75 ( V_121 , V_333 ) ;
if ( error )
goto V_345;
}
V_342 |= V_216 | V_194 ;
V_343 |= V_194 ;
}
}
if ( V_342 ) {
F_72 ( V_121 , V_67 , V_342 ) ;
F_64 ( V_121 , V_67 , V_160 ) ;
}
if ( V_343 ) {
F_72 ( V_121 , V_334 , V_343 ) ;
F_64 ( V_121 , V_334 , V_160 ) ;
}
if ( V_344 ) {
F_72 ( V_121 , V_333 , V_344 ) ;
F_64 ( V_121 , V_333 , V_160 ) ;
}
F_72 ( V_121 , V_332 , V_216 | V_194 ) ;
F_64 ( V_121 , V_332 , V_160 ) ;
return F_193 ( V_121 , V_199 ) ;
V_345:
F_97 ( V_199 ) ;
F_98 ( V_121 ) ;
return error ;
}
static int
F_196 (
struct V_1 * V_112 ,
struct V_1 * * V_335 )
{
struct V_1 * tmpfile ;
int error ;
error = F_101 ( V_112 , NULL , V_163 | V_347 , & tmpfile ) ;
if ( error )
return error ;
F_73 ( F_50 ( tmpfile ) ) ;
F_197 ( tmpfile ) ;
F_99 ( tmpfile ) ;
F_50 ( tmpfile ) -> V_348 |= V_349 ;
* V_335 = tmpfile ;
return 0 ;
}
int
F_198 (
struct V_1 * V_350 ,
struct V_113 * V_351 ,
struct V_1 * V_352 ,
struct V_1 * V_353 ,
struct V_113 * V_225 ,
struct V_1 * V_354 ,
unsigned int V_77 )
{
struct V_129 * V_130 = V_350 -> V_7 ;
struct V_197 * V_121 ;
struct V_198 V_199 ;
T_15 V_200 ;
struct V_1 * V_335 = NULL ;
struct V_1 * V_51 [ V_338 ] ;
int V_337 = V_338 ;
bool V_355 = ( V_350 != V_353 ) ;
bool V_356 = F_58 ( F_50 ( V_352 ) -> V_139 ) ;
int V_341 ;
int error ;
F_199 ( V_350 , V_353 , V_351 , V_225 ) ;
if ( ( V_77 & V_357 ) && ! V_354 )
return - V_358 ;
if ( V_77 & V_359 ) {
ASSERT ( ! ( V_77 & ( V_360 | V_357 ) ) ) ;
error = F_196 ( V_353 , & V_335 ) ;
if ( error )
return error ;
V_351 -> type = V_361 ;
}
F_192 ( V_350 , V_353 , V_352 , V_354 , V_335 ,
V_51 , & V_337 ) ;
V_341 = F_200 ( V_130 , V_225 -> V_211 ) ;
error = F_84 ( V_130 , & F_82 ( V_130 ) -> V_362 , V_341 , 0 , 0 , & V_121 ) ;
if ( error == - V_191 ) {
V_341 = 0 ;
error = F_84 ( V_130 , & F_82 ( V_130 ) -> V_362 , 0 , 0 , 0 ,
& V_121 ) ;
}
if ( error )
goto V_363;
error = F_201 ( V_51 ) ;
if ( error )
goto V_215;
if ( ! V_355 )
F_4 ( V_350 , V_23 | V_45 ) ;
else
F_30 ( V_350 , V_353 ,
V_23 | V_45 ) ;
F_27 ( V_51 , V_337 , V_17 ) ;
F_63 ( V_121 , V_350 , V_23 | V_17 ) ;
if ( V_355 )
F_63 ( V_121 , V_353 , V_23 | V_17 ) ;
F_63 ( V_121 , V_352 , V_17 ) ;
if ( V_354 )
F_63 ( V_121 , V_354 , V_17 ) ;
if ( V_335 )
F_63 ( V_121 , V_335 , V_17 ) ;
if ( F_106 ( ( V_353 -> V_3 . V_4 & V_95 ) &&
( F_107 ( V_353 ) != F_107 ( V_352 ) ) ) ) {
error = - V_228 ;
goto V_215;
}
F_86 ( & V_199 , & V_200 ) ;
if ( V_77 & V_357 )
return F_194 ( V_121 , V_350 , V_351 , V_352 ,
V_353 , V_225 , V_354 ,
& V_199 , & V_200 , V_341 ) ;
if ( V_354 == NULL ) {
if ( ! V_341 ) {
error = F_88 ( V_121 , V_353 , V_225 ) ;
if ( error )
goto V_215;
}
error = F_89 ( V_121 , V_353 , V_225 ,
V_352 -> V_69 , & V_200 ,
& V_199 , V_341 ) ;
if ( error )
goto V_217;
F_72 ( V_121 , V_353 ,
V_216 | V_194 ) ;
if ( V_355 && V_356 ) {
error = F_75 ( V_121 , V_353 ) ;
if ( error )
goto V_217;
}
} else {
if ( F_58 ( F_50 ( V_354 ) -> V_139 ) ) {
if ( ! ( F_188 ( V_354 ) ) ||
( F_50 ( V_354 ) -> V_195 > 2 ) ) {
error = - V_364 ;
goto V_215;
}
}
error = F_195 ( V_121 , V_353 , V_225 ,
V_352 -> V_69 ,
& V_200 , & V_199 , V_341 ) ;
if ( error )
goto V_217;
F_72 ( V_121 , V_353 ,
V_216 | V_194 ) ;
error = F_71 ( V_121 , V_354 ) ;
if ( error )
goto V_217;
if ( V_356 ) {
error = F_71 ( V_121 , V_354 ) ;
if ( error )
goto V_217;
}
}
if ( V_355 && V_356 ) {
error = F_195 ( V_121 , V_352 , & V_346 ,
V_353 -> V_69 ,
& V_200 , & V_199 , V_341 ) ;
ASSERT ( error != - V_364 ) ;
if ( error )
goto V_217;
}
F_72 ( V_121 , V_352 , V_194 ) ;
F_64 ( V_121 , V_352 , V_160 ) ;
if ( V_356 && ( V_355 || V_354 != NULL ) ) {
error = F_71 ( V_121 , V_350 ) ;
if ( error )
goto V_217;
}
if ( V_335 ) {
error = F_195 ( V_121 , V_350 , V_351 , V_335 -> V_69 ,
& V_200 , & V_199 , V_341 ) ;
} else
error = F_189 ( V_121 , V_350 , V_351 , V_352 -> V_69 ,
& V_200 , & V_199 , V_341 ) ;
if ( error )
goto V_217;
if ( V_335 ) {
ASSERT ( F_50 ( V_335 ) -> V_195 == 0 ) ;
error = F_75 ( V_121 , V_335 ) ;
if ( error )
goto V_217;
error = F_108 ( V_121 , V_335 ) ;
if ( error )
goto V_217;
F_64 ( V_121 , V_335 , V_160 ) ;
F_50 ( V_335 ) -> V_348 &= ~ V_349 ;
}
F_72 ( V_121 , V_350 , V_216 | V_194 ) ;
F_64 ( V_121 , V_350 , V_160 ) ;
if ( V_355 )
F_64 ( V_121 , V_353 , V_160 ) ;
error = F_193 ( V_121 , & V_199 ) ;
if ( V_335 )
F_100 ( V_335 ) ;
return error ;
V_217:
F_97 ( & V_199 ) ;
V_215:
F_98 ( V_121 ) ;
V_363:
if ( V_335 )
F_100 ( V_335 ) ;
return error ;
}
STATIC int
F_202 (
struct V_1 * V_2 ,
struct V_365 * V_291 )
{
struct V_129 * V_130 = V_2 -> V_7 ;
struct V_294 * V_295 ;
unsigned long V_366 , V_367 ;
unsigned long V_287 ;
int V_368 ;
struct V_1 * * V_369 ;
struct V_1 * V_370 ;
int V_371 ;
int V_372 = 0 ;
int V_373 ;
int V_53 ;
V_295 = F_156 ( V_130 , F_140 ( V_130 , V_2 -> V_69 ) ) ;
V_287 = V_130 -> V_374 >> V_130 -> V_8 . V_375 ;
V_368 = V_287 * sizeof( T_3 * ) ;
V_369 = F_203 ( V_368 , V_376 | V_377 ) ;
if ( ! V_369 )
goto V_378;
V_367 = ~ ( ( ( V_130 -> V_374 >> V_130 -> V_8 . V_375 ) ) - 1 ) ;
V_366 = F_142 ( V_130 , V_2 -> V_69 ) & V_367 ;
F_164 () ;
V_371 = F_204 ( & V_295 -> V_320 , ( void * * ) V_369 ,
V_366 , V_287 ) ;
if ( V_371 == 0 )
goto V_379;
for ( V_53 = 0 ; V_53 < V_371 ; V_53 ++ ) {
V_370 = V_369 [ V_53 ] ;
if ( V_370 == V_2 )
continue;
F_167 ( & V_370 -> V_321 ) ;
if ( ! V_370 -> V_69 ||
F_168 ( V_370 , V_317 ) ) {
F_169 ( & V_370 -> V_321 ) ;
continue;
}
if ( ( F_142 ( V_130 , V_370 -> V_69 ) & V_367 ) != V_366 ) {
F_169 ( & V_370 -> V_321 ) ;
break;
}
F_169 ( & V_370 -> V_321 ) ;
if ( F_171 ( V_370 ) && F_183 ( V_370 ) == 0 )
continue;
if ( ! F_12 ( V_370 , V_11 ) )
continue;
if ( ! F_37 ( V_370 ) ) {
F_18 ( V_370 , V_11 ) ;
continue;
}
if ( F_183 ( V_370 ) ) {
F_172 ( V_370 ) ;
F_18 ( V_370 , V_11 ) ;
continue;
}
if ( ! V_370 -> V_69 ) {
F_172 ( V_370 ) ;
F_18 ( V_370 , V_11 ) ;
continue;
}
if ( ! F_171 ( V_370 ) ) {
int error ;
error = F_205 ( V_370 , V_291 ) ;
if ( error ) {
F_18 ( V_370 , V_11 ) ;
goto V_380;
}
V_372 ++ ;
} else {
F_172 ( V_370 ) ;
}
F_18 ( V_370 , V_11 ) ;
}
if ( V_372 ) {
F_206 ( V_130 , V_381 ) ;
F_207 ( V_130 , V_382 , V_372 ) ;
}
V_379:
F_166 () ;
F_47 ( V_369 ) ;
V_378:
F_176 ( V_295 ) ;
return 0 ;
V_380:
F_166 () ;
V_373 = ( V_291 -> V_383 & V_384 ) ;
if ( V_373 )
F_69 ( V_291 ) ;
F_132 ( V_130 , V_385 ) ;
if ( ! V_373 ) {
if ( V_291 -> V_386 ) {
V_291 -> V_383 &= ~ V_387 ;
F_208 ( V_291 ) ;
F_209 ( V_291 , - V_118 ) ;
F_210 ( V_291 ) ;
} else {
F_208 ( V_291 ) ;
F_69 ( V_291 ) ;
}
}
F_211 ( V_370 , false ) ;
F_47 ( V_369 ) ;
F_176 ( V_295 ) ;
return - V_388 ;
}
int
F_212 (
struct V_1 * V_2 ,
struct V_365 * * V_389 )
{
struct V_129 * V_130 = V_2 -> V_7 ;
struct V_365 * V_291 = NULL ;
struct V_390 * V_261 ;
int error ;
F_206 ( V_130 , V_391 ) ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_145 > F_213 ( V_2 , V_249 ) ) ;
* V_389 = NULL ;
F_184 ( V_2 ) ;
if ( F_123 ( V_2 , V_317 ) ) {
F_172 ( V_2 ) ;
return 0 ;
}
if ( F_44 ( V_130 ) ) {
error = - V_118 ;
goto V_392;
}
error = F_145 ( V_130 , NULL , & V_2 -> V_270 , & V_261 , & V_291 , V_393 ,
0 ) ;
if ( error == - V_247 ) {
F_172 ( V_2 ) ;
return error ;
}
if ( error )
goto V_394;
error = F_205 ( V_2 , V_291 ) ;
if ( error )
goto V_394;
if ( F_214 ( V_291 ) )
F_215 ( V_130 , 0 ) ;
error = F_202 ( V_2 , V_291 ) ;
if ( error )
goto V_380;
* V_389 = V_291 ;
return 0 ;
V_394:
if ( V_291 )
F_69 ( V_291 ) ;
F_132 ( V_130 , V_385 ) ;
V_380:
error = - V_388 ;
V_392:
F_211 ( V_2 , false ) ;
return error ;
}
STATIC int
F_205 (
struct V_1 * V_2 ,
struct V_365 * V_291 )
{
struct V_395 * V_292 = V_2 -> V_58 ;
struct V_390 * V_261 ;
struct V_129 * V_130 = V_2 -> V_7 ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_35 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_145 > F_213 ( V_2 , V_249 ) ) ;
ASSERT ( V_292 != NULL && V_292 -> V_323 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_138 > 1 ) ;
V_261 = F_216 ( V_291 , V_2 -> V_270 . V_272 ) ;
if ( F_217 ( V_261 -> V_396 != F_218 ( V_397 ) ,
V_130 , V_398 , V_399 ) ) {
F_219 ( V_130 , V_400 ,
L_9 ,
V_254 , V_2 -> V_69 , F_220 ( V_261 -> V_396 ) , V_261 ) ;
goto V_394;
}
if ( F_62 ( F_50 ( V_2 ) -> V_139 ) ) {
if ( F_217 (
( V_2 -> V_3 . V_12 != V_178 ) &&
( V_2 -> V_3 . V_12 != V_13 ) ,
V_130 , V_401 , V_402 ) ) {
F_219 ( V_130 , V_400 ,
L_10 ,
V_254 , V_2 -> V_69 , V_2 ) ;
goto V_394;
}
} else if ( F_58 ( F_50 ( V_2 ) -> V_139 ) ) {
if ( F_217 (
( V_2 -> V_3 . V_12 != V_178 ) &&
( V_2 -> V_3 . V_12 != V_13 ) &&
( V_2 -> V_3 . V_12 != V_403 ) ,
V_130 , V_404 , V_405 ) ) {
F_219 ( V_130 , V_400 ,
L_11 ,
V_254 , V_2 -> V_69 , V_2 ) ;
goto V_394;
}
}
if ( F_217 ( V_2 -> V_3 . V_145 + V_2 -> V_3 . V_183 >
V_2 -> V_3 . V_146 , V_130 , V_406 ,
V_407 ) ) {
F_219 ( V_130 , V_400 ,
L_12
L_13 ,
V_254 , V_2 -> V_69 ,
V_2 -> V_3 . V_145 + V_2 -> V_3 . V_183 ,
V_2 -> V_3 . V_146 , V_2 ) ;
goto V_394;
}
if ( F_217 ( V_2 -> V_3 . V_259 > V_130 -> V_8 . V_408 ,
V_130 , V_409 , V_410 ) ) {
F_219 ( V_130 , V_400 ,
L_14 ,
V_254 , V_2 -> V_69 , V_2 -> V_3 . V_259 , V_2 ) ;
goto V_394;
}
if ( V_2 -> V_3 . V_138 < 3 )
V_2 -> V_3 . V_411 ++ ;
F_221 ( V_2 , V_261 , V_292 -> V_314 . V_315 ) ;
if ( V_2 -> V_3 . V_411 == V_412 )
V_2 -> V_3 . V_411 = 0 ;
F_222 ( V_2 , V_261 , V_292 , V_249 ) ;
if ( F_41 ( V_2 ) )
F_222 ( V_2 , V_261 , V_292 , V_413 ) ;
F_150 ( V_130 , V_291 ) ;
V_292 -> V_322 = V_292 -> V_323 ;
V_292 -> V_323 = 0 ;
V_292 -> V_324 = 0 ;
V_292 -> V_309 = 1 ;
F_163 ( V_130 -> V_312 , & V_292 -> V_313 ,
& V_292 -> V_314 . V_315 ) ;
F_173 ( V_291 , V_414 , & V_292 -> V_314 ) ;
F_147 ( V_130 , V_261 ) ;
ASSERT ( V_291 -> V_306 != NULL ) ;
ASSERT ( V_291 -> V_386 != NULL ) ;
return 0 ;
V_394:
return - V_388 ;
}
