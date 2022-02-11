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
ASSERT ( ( V_20 & ( V_11 | V_17 ) ) !=
( V_11 | V_17 ) ) ;
ASSERT ( ( V_20 & ~ ( V_24 | V_25 ) ) == 0 ) ;
if ( V_20 & V_23 )
F_7 ( & V_2 -> V_26 , F_8 ( V_20 ) ) ;
else if ( V_20 & V_22 )
F_9 ( & V_2 -> V_26 , F_8 ( V_20 ) ) ;
if ( V_20 & V_17 )
F_7 ( & V_2 -> V_27 , F_10 ( V_20 ) ) ;
else if ( V_20 & V_11 )
F_9 ( & V_2 -> V_27 , F_10 ( V_20 ) ) ;
}
int
F_11 (
T_3 * V_2 ,
T_2 V_20 )
{
F_12 ( V_2 , V_20 , V_21 ) ;
ASSERT ( ( V_20 & ( V_22 | V_23 ) ) !=
( V_22 | V_23 ) ) ;
ASSERT ( ( V_20 & ( V_11 | V_17 ) ) !=
( V_11 | V_17 ) ) ;
ASSERT ( ( V_20 & ~ ( V_24 | V_25 ) ) == 0 ) ;
if ( V_20 & V_23 ) {
if ( ! F_13 ( & V_2 -> V_26 ) )
goto V_28;
} else if ( V_20 & V_22 ) {
if ( ! F_14 ( & V_2 -> V_26 ) )
goto V_28;
}
if ( V_20 & V_17 ) {
if ( ! F_13 ( & V_2 -> V_27 ) )
goto V_29;
} else if ( V_20 & V_11 ) {
if ( ! F_14 ( & V_2 -> V_27 ) )
goto V_29;
}
return 1 ;
V_29:
if ( V_20 & V_23 )
F_15 ( & V_2 -> V_26 ) ;
else if ( V_20 & V_22 )
F_16 ( & V_2 -> V_26 ) ;
V_28:
return 0 ;
}
void
F_17 (
T_3 * V_2 ,
T_2 V_20 )
{
ASSERT ( ( V_20 & ( V_22 | V_23 ) ) !=
( V_22 | V_23 ) ) ;
ASSERT ( ( V_20 & ( V_11 | V_17 ) ) !=
( V_11 | V_17 ) ) ;
ASSERT ( ( V_20 & ~ ( V_24 | V_25 ) ) == 0 ) ;
ASSERT ( V_20 != 0 ) ;
if ( V_20 & V_23 )
F_15 ( & V_2 -> V_26 ) ;
else if ( V_20 & V_22 )
F_16 ( & V_2 -> V_26 ) ;
if ( V_20 & V_17 )
F_15 ( & V_2 -> V_27 ) ;
else if ( V_20 & V_11 )
F_16 ( & V_2 -> V_27 ) ;
F_18 ( V_2 , V_20 , V_21 ) ;
}
void
F_19 (
T_3 * V_2 ,
T_2 V_20 )
{
ASSERT ( V_20 & ( V_23 | V_17 ) ) ;
ASSERT ( ( V_20 & ~ ( V_23 | V_17 ) ) == 0 ) ;
if ( V_20 & V_17 )
F_20 ( & V_2 -> V_27 ) ;
if ( V_20 & V_23 )
F_20 ( & V_2 -> V_26 ) ;
F_21 ( V_2 , V_20 , V_21 ) ;
}
int
F_22 (
T_3 * V_2 ,
T_2 V_20 )
{
if ( V_20 & ( V_17 | V_11 ) ) {
if ( ! ( V_20 & V_11 ) )
return ! ! V_2 -> V_27 . V_30 ;
return F_23 ( & V_2 -> V_27 . V_31 ) ;
}
if ( V_20 & ( V_23 | V_22 ) ) {
if ( ! ( V_20 & V_22 ) )
return ! ! V_2 -> V_26 . V_30 ;
return F_23 ( & V_2 -> V_26 . V_31 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
static inline int
F_24 ( int V_10 , int V_32 )
{
if ( V_10 & ( V_22 | V_23 ) )
V_10 |= ( V_32 + V_33 ) << V_34 ;
if ( V_10 & ( V_11 | V_17 ) )
V_10 |= ( V_32 + V_33 ) << V_35 ;
return V_10 ;
}
void
F_25 (
T_3 * * V_36 ,
int V_37 ,
T_2 V_10 )
{
int V_38 = 0 , V_39 , V_40 , V_41 ;
T_4 * V_42 ;
ASSERT ( V_36 && ( V_37 >= 2 ) ) ;
V_41 = 0 ;
V_39 = 0 ;
V_43:
for (; V_39 < V_37 ; V_39 ++ ) {
ASSERT ( V_36 [ V_39 ] ) ;
if ( V_39 && ( V_36 [ V_39 ] == V_36 [ V_39 - 1 ] ) )
continue;
if ( ! V_41 ) {
for ( V_40 = ( V_39 - 1 ) ; V_40 >= 0 && ! V_41 ; V_40 -- ) {
V_42 = ( T_4 * ) V_36 [ V_40 ] -> V_44 ;
if ( V_42 && ( V_42 -> V_45 & V_46 ) ) {
V_41 ++ ;
}
}
}
if ( V_41 ) {
ASSERT ( V_39 != 0 ) ;
if ( ! F_11 ( V_36 [ V_39 ] , F_24 ( V_10 , V_39 ) ) ) {
V_38 ++ ;
for( V_40 = V_39 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( ( V_40 != ( V_39 - 1 ) ) && V_36 [ V_40 ] ==
V_36 [ V_40 + 1 ] )
continue;
F_17 ( V_36 [ V_40 ] , V_10 ) ;
}
if ( ( V_38 % 5 ) == 0 ) {
F_26 ( 1 ) ;
#ifdef F_27
V_47 ++ ;
#endif
}
V_39 = 0 ;
V_41 = 0 ;
goto V_43;
}
} else {
F_4 ( V_36 [ V_39 ] , F_24 ( V_10 , V_39 ) ) ;
}
}
#ifdef F_27
if ( V_38 ) {
if ( V_38 < 5 ) V_48 ++ ;
else if ( V_38 < 100 ) V_49 ++ ;
else V_50 ++ ;
} else {
V_51 ++ ;
}
#endif
}
void
F_28 (
T_3 * V_52 ,
T_3 * V_53 ,
T_2 V_10 )
{
T_3 * V_54 ;
int V_38 = 0 ;
T_4 * V_42 ;
if ( V_10 & ( V_22 | V_23 ) )
ASSERT ( ( V_10 & ( V_11 | V_17 ) ) == 0 ) ;
ASSERT ( V_52 -> V_55 != V_53 -> V_55 ) ;
if ( V_52 -> V_55 > V_53 -> V_55 ) {
V_54 = V_52 ;
V_52 = V_53 ;
V_53 = V_54 ;
}
V_43:
F_4 ( V_52 , F_24 ( V_10 , 0 ) ) ;
V_42 = ( T_4 * ) V_52 -> V_44 ;
if ( V_42 && ( V_42 -> V_45 & V_46 ) ) {
if ( ! F_11 ( V_53 , F_24 ( V_10 , 1 ) ) ) {
F_17 ( V_52 , V_10 ) ;
if ( ( ++ V_38 % 5 ) == 0 )
F_26 ( 1 ) ;
goto V_43;
}
} else {
F_4 ( V_53 , F_24 ( V_10 , 1 ) ) ;
}
}
void
F_29 (
struct V_1 * V_2 )
{
T_5 * V_56 = F_30 ( & V_2 -> V_57 , V_58 ) ;
F_31 ( V_59 , & V_2 -> V_57 , V_58 ) ;
do {
F_32 ( V_56 , & V_59 . V_59 , V_60 ) ;
if ( F_33 ( V_2 ) )
F_34 () ;
} while ( ! F_35 ( V_2 ) );
F_36 ( V_56 , & V_59 . V_59 ) ;
}
STATIC T_2
F_37 (
T_6 V_4 )
{
T_2 V_61 = 0 ;
if ( V_4 & V_62 ) {
if ( V_4 & V_63 )
V_61 |= V_64 ;
if ( V_4 & V_65 )
V_61 |= V_66 ;
if ( V_4 & V_67 )
V_61 |= V_68 ;
if ( V_4 & V_69 )
V_61 |= V_70 ;
if ( V_4 & V_71 )
V_61 |= V_72 ;
if ( V_4 & V_73 )
V_61 |= V_74 ;
if ( V_4 & V_75 )
V_61 |= V_76 ;
if ( V_4 & V_77 )
V_61 |= V_78 ;
if ( V_4 & V_79 )
V_61 |= V_80 ;
if ( V_4 & V_81 )
V_61 |= V_82 ;
if ( V_4 & V_5 )
V_61 |= V_83 ;
if ( V_4 & V_84 )
V_61 |= V_85 ;
if ( V_4 & V_86 )
V_61 |= V_87 ;
if ( V_4 & V_88 )
V_61 |= V_89 ;
}
return V_61 ;
}
T_2
F_38 (
T_3 * V_2 )
{
T_7 * V_90 = & V_2 -> V_3 ;
return F_37 ( V_90 -> V_4 ) |
( F_39 ( V_2 ) ? V_91 : 0 ) ;
}
T_2
F_40 (
T_8 * V_92 )
{
return F_37 ( F_41 ( V_92 -> V_4 ) ) |
( F_42 ( V_92 ) ? V_91 : 0 ) ;
}
int
F_43 (
T_3 * V_93 ,
struct V_94 * V_95 ,
T_3 * * V_96 ,
struct V_94 * V_97 )
{
T_9 V_98 ;
int error ;
T_2 V_10 ;
F_44 ( V_93 , V_95 ) ;
if ( F_45 ( V_93 -> V_7 ) )
return - V_99 ;
V_10 = F_3 ( V_93 ) ;
error = F_46 ( NULL , V_93 , V_95 , & V_98 , V_97 ) ;
F_17 ( V_93 , V_10 ) ;
if ( error )
goto V_28;
error = F_47 ( V_93 -> V_7 , NULL , V_98 , 0 , 0 , V_96 ) ;
if ( error )
goto V_100;
return 0 ;
V_100:
if ( V_97 )
F_48 ( V_97 -> V_95 ) ;
V_28:
* V_96 = NULL ;
return error ;
}
int
F_49 (
T_10 * V_101 ,
T_3 * V_102 ,
T_11 V_103 ,
T_12 V_104 ,
T_13 V_105 ,
T_14 V_106 ,
int V_107 ,
T_15 * * V_108 ,
T_3 * * V_96 )
{
struct V_109 * V_110 = V_101 -> V_111 ;
T_9 V_112 ;
T_3 * V_2 ;
T_2 V_61 ;
int error ;
struct V_113 V_114 ;
error = F_50 ( V_101 , V_102 ? V_102 -> V_55 : 0 , V_103 , V_107 ,
V_108 , & V_112 ) ;
if ( error )
return error ;
if ( * V_108 || V_112 == V_115 ) {
* V_96 = NULL ;
return 0 ;
}
ASSERT ( * V_108 == NULL ) ;
error = F_47 ( V_110 , V_101 , V_112 , V_116 ,
V_17 , & V_2 ) ;
if ( error )
return error ;
ASSERT ( V_2 != NULL ) ;
if ( V_2 -> V_3 . V_117 == 1 )
V_2 -> V_3 . V_117 = 2 ;
V_2 -> V_3 . V_118 = V_103 ;
V_2 -> V_3 . V_119 = 0 ;
V_2 -> V_3 . V_120 = V_104 ;
ASSERT ( V_2 -> V_3 . V_120 == V_104 ) ;
V_2 -> V_3 . V_121 = F_51 ( F_52 () ) ;
V_2 -> V_3 . V_122 = F_53 ( F_54 () ) ;
F_55 ( V_2 , V_106 ) ;
memset ( & ( V_2 -> V_3 . V_123 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_123 ) ) ;
if ( V_102 && F_56 ( V_102 ) ) {
V_2 -> V_3 . V_122 = V_102 -> V_3 . V_122 ;
if ( ( V_102 -> V_3 . V_118 & V_124 ) && F_57 ( V_103 ) ) {
V_2 -> V_3 . V_118 |= V_124 ;
}
}
if ( ( V_125 ) &&
( V_2 -> V_3 . V_118 & V_124 ) &&
( ! F_58 ( F_59 ( V_2 -> V_3 . V_122 ) ) ) ) {
V_2 -> V_3 . V_118 &= ~ V_124 ;
}
V_2 -> V_3 . V_126 = 0 ;
V_2 -> V_3 . V_127 = 0 ;
ASSERT ( V_2 -> V_3 . V_128 == 0 ) ;
V_114 = F_60 ( V_110 -> V_129 ) ;
V_2 -> V_3 . V_130 . V_131 = ( V_132 ) V_114 . V_133 ;
V_2 -> V_3 . V_130 . V_134 = ( V_132 ) V_114 . V_135 ;
V_2 -> V_3 . V_136 = V_2 -> V_3 . V_130 ;
V_2 -> V_3 . V_137 = V_2 -> V_3 . V_130 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_138 = 0 ;
V_2 -> V_3 . V_139 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( V_2 -> V_3 . V_117 == 3 ) {
ASSERT ( V_2 -> V_3 . V_140 == V_112 ) ;
ASSERT ( F_61 ( & V_2 -> V_3 . V_141 , & V_110 -> V_8 . V_142 ) ) ;
V_2 -> V_3 . V_143 = 0 ;
V_2 -> V_3 . V_144 = 1 ;
V_2 -> V_3 . V_145 = 0 ;
V_2 -> V_3 . V_146 = 0 ;
memset ( & ( V_2 -> V_3 . V_147 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_147 ) ) ;
V_2 -> V_3 . V_148 = V_2 -> V_3 . V_130 ;
}
V_61 = V_149 ;
switch ( V_103 & V_150 ) {
case V_151 :
case V_152 :
case V_153 :
case V_154 :
V_2 -> V_3 . V_12 = V_155 ;
V_2 -> V_14 . V_156 . V_157 = V_105 ;
V_2 -> V_14 . V_15 = 0 ;
V_61 |= V_158 ;
break;
case V_159 :
case V_160 :
if ( V_102 && ( V_102 -> V_3 . V_4 & V_62 ) ) {
T_2 V_4 = 0 ;
if ( F_57 ( V_103 ) ) {
if ( V_102 -> V_3 . V_4 & V_77 )
V_4 |= V_77 ;
if ( V_102 -> V_3 . V_4 & V_84 ) {
V_4 |= V_84 ;
V_2 -> V_3 . V_6 = V_102 -> V_3 . V_6 ;
}
if ( V_102 -> V_3 . V_4 & V_79 )
V_4 |= V_79 ;
} else if ( F_62 ( V_103 ) ) {
if ( V_102 -> V_3 . V_4 & V_77 )
V_4 |= V_63 ;
if ( V_102 -> V_3 . V_4 & V_84 ) {
V_4 |= V_5 ;
V_2 -> V_3 . V_6 = V_102 -> V_3 . V_6 ;
}
}
if ( ( V_102 -> V_3 . V_4 & V_73 ) &&
V_161 )
V_4 |= V_73 ;
if ( ( V_102 -> V_3 . V_4 & V_75 ) &&
V_162 )
V_4 |= V_75 ;
if ( ( V_102 -> V_3 . V_4 & V_71 ) &&
V_163 )
V_4 |= V_71 ;
if ( ( V_102 -> V_3 . V_4 & V_81 ) &&
V_164 )
V_4 |= V_81 ;
if ( ( V_102 -> V_3 . V_4 & V_86 ) &&
V_165 )
V_4 |= V_86 ;
if ( V_102 -> V_3 . V_4 & V_88 )
V_4 |= V_88 ;
V_2 -> V_3 . V_4 |= V_4 ;
}
case V_166 :
V_2 -> V_3 . V_12 = V_167 ;
V_2 -> V_14 . V_15 = V_16 ;
V_2 -> V_14 . V_168 = V_2 -> V_14 . V_169 = 0 ;
V_2 -> V_14 . V_170 . V_171 = NULL ;
break;
default:
ASSERT ( 0 ) ;
}
V_2 -> V_3 . V_18 = V_167 ;
V_2 -> V_3 . V_172 = 0 ;
F_63 ( V_101 , V_2 , V_17 ) ;
F_64 ( V_101 , V_2 , V_61 ) ;
F_65 ( V_2 ) ;
* V_96 = V_2 ;
return 0 ;
}
int
F_66 (
T_10 * * V_173 ,
T_3 * V_93 ,
T_11 V_103 ,
T_12 V_104 ,
T_13 V_105 ,
T_14 V_106 ,
int V_107 ,
T_3 * * V_96 ,
int * V_174 )
{
T_10 * V_101 ;
T_10 * V_175 ;
T_3 * V_2 ;
T_15 * V_108 = NULL ;
int V_176 ;
void * V_177 ;
T_2 V_178 ;
V_101 = * V_173 ;
ASSERT ( V_101 -> V_179 & V_180 ) ;
V_176 = F_49 ( V_101 , V_93 , V_103 , V_104 , V_105 , V_106 , V_107 ,
& V_108 , & V_2 ) ;
if ( V_176 ) {
* V_96 = NULL ;
return V_176 ;
}
if ( ! V_108 && ! V_2 ) {
* V_96 = NULL ;
return - V_181 ;
}
if ( V_108 ) {
struct V_182 V_183 ;
F_67 ( V_101 , V_108 ) ;
V_183 . V_184 = F_68 ( V_101 ) ;
V_183 . V_185 = F_69 ( V_101 ) ;
V_177 = NULL ;
V_178 = 0 ;
if ( V_101 -> V_186 ) {
V_177 = ( void * ) V_101 -> V_186 ;
V_101 -> V_186 = NULL ;
V_178 = V_101 -> V_179 & V_187 ;
V_101 -> V_179 &= ~ ( V_187 ) ;
}
V_175 = F_70 ( V_101 ) ;
V_176 = F_71 ( V_101 , 0 ) ;
V_101 = V_175 ;
if ( V_174 != NULL ) {
* V_174 = 1 ;
}
if ( V_176 ) {
F_72 ( V_108 ) ;
if ( V_177 ) {
V_101 -> V_186 = V_177 ;
F_73 ( V_101 ) ;
}
* V_173 = V_175 ;
* V_96 = NULL ;
return V_176 ;
}
F_74 ( V_101 -> V_188 ) ;
V_183 . V_189 = V_180 ;
V_176 = F_75 ( V_101 , & V_183 , 0 , 0 ) ;
if ( V_177 ) {
V_101 -> V_186 = V_177 ;
V_101 -> V_179 |= V_178 ;
}
if ( V_176 ) {
F_72 ( V_108 ) ;
* V_173 = V_175 ;
* V_96 = NULL ;
return V_176 ;
}
F_76 ( V_101 , V_108 ) ;
V_176 = F_49 ( V_101 , V_93 , V_103 , V_104 , V_105 , V_106 ,
V_107 , & V_108 , & V_2 ) ;
if ( V_176 ) {
* V_173 = V_101 ;
* V_96 = NULL ;
return V_176 ;
}
ASSERT ( ! V_108 && V_2 ) ;
} else {
if ( V_174 != NULL )
* V_174 = 0 ;
}
* V_96 = V_2 ;
* V_173 = V_101 ;
return 0 ;
}
int
F_77 (
T_10 * V_101 ,
T_3 * V_2 )
{
int error ;
F_78 ( V_101 , V_2 , V_190 ) ;
ASSERT ( V_2 -> V_3 . V_120 > 0 ) ;
V_2 -> V_3 . V_120 -- ;
F_79 ( F_80 ( V_2 ) ) ;
F_64 ( V_101 , V_2 , V_149 ) ;
error = 0 ;
if ( V_2 -> V_3 . V_120 == 0 ) {
error = F_81 ( V_101 , V_2 ) ;
}
return error ;
}
int
F_82 (
T_10 * V_101 ,
T_3 * V_2 )
{
F_78 ( V_101 , V_2 , V_190 ) ;
ASSERT ( V_2 -> V_3 . V_117 > 1 ) ;
ASSERT ( V_2 -> V_3 . V_120 > 0 || ( F_80 ( V_2 ) -> V_191 & V_192 ) ) ;
V_2 -> V_3 . V_120 ++ ;
F_83 ( F_80 ( V_2 ) ) ;
F_64 ( V_101 , V_2 , V_149 ) ;
return 0 ;
}
int
F_84 (
T_3 * V_93 ,
struct V_94 * V_95 ,
T_11 V_103 ,
T_13 V_105 ,
T_3 * * V_96 )
{
int V_193 = F_57 ( V_103 ) ;
struct V_109 * V_110 = V_93 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_194 * V_101 = NULL ;
int error ;
T_16 V_195 ;
T_17 V_196 ;
bool V_197 = false ;
T_2 V_198 ;
int V_174 ;
T_14 V_106 ;
struct V_199 * V_200 = NULL ;
struct V_199 * V_201 = NULL ;
struct V_199 * V_202 = NULL ;
struct V_182 * V_183 ;
T_2 V_203 ;
F_85 ( V_93 , V_95 ) ;
if ( F_45 ( V_110 ) )
return - V_99 ;
V_106 = F_86 ( V_93 ) ;
error = F_87 ( V_93 , F_51 ( F_52 () ) ,
F_53 ( F_54 () ) , V_106 ,
V_204 | V_205 ,
& V_200 , & V_201 , & V_202 ) ;
if ( error )
return error ;
if ( V_193 ) {
V_105 = 0 ;
V_203 = F_88 ( V_110 , V_95 -> V_206 ) ;
V_183 = & F_89 ( V_110 ) -> V_207 ;
V_101 = F_90 ( V_110 , V_208 ) ;
} else {
V_203 = F_91 ( V_110 , V_95 -> V_206 ) ;
V_183 = & F_89 ( V_110 ) -> V_209 ;
V_101 = F_90 ( V_110 , V_210 ) ;
}
V_198 = V_211 ;
error = F_75 ( V_101 , V_183 , V_203 , 0 ) ;
if ( error == - V_181 ) {
F_92 ( V_110 ) ;
error = F_75 ( V_101 , V_183 , V_203 , 0 ) ;
}
if ( error == - V_181 ) {
V_203 = 0 ;
error = F_75 ( V_101 , V_183 , 0 , 0 ) ;
}
if ( error ) {
V_198 = 0 ;
goto V_212;
}
F_4 ( V_93 , V_17 | V_213 ) ;
V_197 = true ;
F_93 ( & V_195 , & V_196 ) ;
error = F_94 ( V_101 , V_110 , V_200 , V_201 ,
V_202 , V_203 , 1 , 0 ) ;
if ( error )
goto V_212;
if ( ! V_203 ) {
error = F_95 ( V_101 , V_93 , V_95 ) ;
if ( error )
goto V_212;
}
error = F_66 ( & V_101 , V_93 , V_103 , V_193 ? 2 : 1 , V_105 ,
V_106 , V_203 > 0 , & V_2 , & V_174 ) ;
if ( error ) {
if ( error == - V_181 )
goto V_212;
goto V_214;
}
F_63 ( V_101 , V_93 , V_17 ) ;
V_197 = false ;
error = F_96 ( V_101 , V_93 , V_95 , V_2 -> V_55 ,
& V_196 , & V_195 , V_203 ?
V_203 - F_97 ( V_110 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_181 ) ;
goto V_214;
}
F_78 ( V_101 , V_93 , V_215 | V_190 ) ;
F_64 ( V_101 , V_93 , V_149 ) ;
if ( V_193 ) {
error = F_98 ( V_101 , V_2 , V_93 ) ;
if ( error )
goto V_216;
error = F_82 ( V_101 , V_93 ) ;
if ( error )
goto V_216;
}
if ( V_110 -> V_217 & ( V_218 | V_219 ) )
F_99 ( V_101 ) ;
F_100 ( V_101 , V_2 , V_200 , V_201 , V_202 ) ;
error = F_101 ( & V_101 , & V_195 , & V_174 ) ;
if ( error )
goto V_216;
error = F_71 ( V_101 , V_211 ) ;
if ( error )
goto V_220;
F_102 ( V_200 ) ;
F_102 ( V_201 ) ;
F_102 ( V_202 ) ;
* V_96 = V_2 ;
return 0 ;
V_216:
F_103 ( & V_195 ) ;
V_214:
V_198 |= V_221 ;
V_212:
F_104 ( V_101 , V_198 ) ;
V_220:
if ( V_2 )
F_105 ( V_2 ) ;
F_102 ( V_200 ) ;
F_102 ( V_201 ) ;
F_102 ( V_202 ) ;
if ( V_197 )
F_17 ( V_93 , V_17 ) ;
return error ;
}
int
F_106 (
struct V_1 * V_93 ,
struct V_222 * V_222 ,
T_11 V_103 ,
struct V_1 * * V_96 )
{
struct V_109 * V_110 = V_93 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_194 * V_101 = NULL ;
int error ;
T_2 V_198 = V_211 ;
T_14 V_106 ;
struct V_199 * V_200 = NULL ;
struct V_199 * V_201 = NULL ;
struct V_199 * V_202 = NULL ;
struct V_182 * V_183 ;
T_2 V_203 ;
if ( F_45 ( V_110 ) )
return - V_99 ;
V_106 = F_86 ( V_93 ) ;
error = F_87 ( V_93 , F_51 ( F_52 () ) ,
F_53 ( F_54 () ) , V_106 ,
V_204 | V_205 ,
& V_200 , & V_201 , & V_202 ) ;
if ( error )
return error ;
V_203 = F_97 ( V_110 ) ;
V_101 = F_90 ( V_110 , V_223 ) ;
V_183 = & F_89 ( V_110 ) -> V_224 ;
error = F_75 ( V_101 , V_183 , V_203 , 0 ) ;
if ( error == - V_181 ) {
V_203 = 0 ;
error = F_75 ( V_101 , V_183 , 0 , 0 ) ;
}
if ( error ) {
V_198 = 0 ;
goto V_212;
}
error = F_94 ( V_101 , V_110 , V_200 , V_201 ,
V_202 , V_203 , 1 , 0 ) ;
if ( error )
goto V_212;
error = F_66 ( & V_101 , V_93 , V_103 , 1 , 0 ,
V_106 , V_203 > 0 , & V_2 , NULL ) ;
if ( error ) {
if ( error == - V_181 )
goto V_212;
goto V_214;
}
if ( V_110 -> V_217 & V_218 )
F_99 ( V_101 ) ;
F_100 ( V_101 , V_2 , V_200 , V_201 , V_202 ) ;
V_2 -> V_3 . V_120 -- ;
error = F_81 ( V_101 , V_2 ) ;
if ( error )
goto V_214;
error = F_71 ( V_101 , V_211 ) ;
if ( error )
goto V_220;
F_102 ( V_200 ) ;
F_102 ( V_201 ) ;
F_102 ( V_202 ) ;
* V_96 = V_2 ;
return 0 ;
V_214:
V_198 |= V_221 ;
V_212:
F_104 ( V_101 , V_198 ) ;
V_220:
if ( V_2 )
F_105 ( V_2 ) ;
F_102 ( V_200 ) ;
F_102 ( V_201 ) ;
F_102 ( V_202 ) ;
return error ;
}
int
F_107 (
T_3 * V_225 ,
T_3 * V_226 ,
struct V_94 * V_227 )
{
T_18 * V_110 = V_225 -> V_7 ;
T_10 * V_101 ;
int error ;
T_16 V_195 ;
T_17 V_196 ;
int V_198 ;
int V_174 ;
int V_203 ;
F_108 ( V_225 , V_227 ) ;
ASSERT ( ! F_57 ( V_226 -> V_3 . V_118 ) ) ;
if ( F_45 ( V_110 ) )
return - V_99 ;
error = F_109 ( V_226 , 0 ) ;
if ( error )
goto V_228;
error = F_109 ( V_225 , 0 ) ;
if ( error )
goto V_228;
V_101 = F_90 ( V_110 , V_229 ) ;
V_198 = V_211 ;
V_203 = F_110 ( V_110 , V_227 -> V_206 ) ;
error = F_75 ( V_101 , & F_89 ( V_110 ) -> V_230 , V_203 , 0 ) ;
if ( error == - V_181 ) {
V_203 = 0 ;
error = F_75 ( V_101 , & F_89 ( V_110 ) -> V_230 , 0 , 0 ) ;
}
if ( error ) {
V_198 = 0 ;
goto V_231;
}
F_28 ( V_226 , V_225 , V_17 ) ;
F_63 ( V_101 , V_226 , V_17 ) ;
F_63 ( V_101 , V_225 , V_17 ) ;
if ( F_111 ( ( V_225 -> V_3 . V_4 & V_79 ) &&
( F_112 ( V_225 ) != F_112 ( V_226 ) ) ) ) {
error = - V_232 ;
goto V_231;
}
if ( ! V_203 ) {
error = F_95 ( V_101 , V_225 , V_227 ) ;
if ( error )
goto V_231;
}
F_93 ( & V_195 , & V_196 ) ;
if ( V_226 -> V_3 . V_120 == 0 ) {
error = F_113 ( V_101 , V_226 ) ;
if ( error )
goto V_233;
}
error = F_96 ( V_101 , V_225 , V_227 , V_226 -> V_55 ,
& V_196 , & V_195 , V_203 ) ;
if ( error )
goto V_233;
F_78 ( V_101 , V_225 , V_215 | V_190 ) ;
F_64 ( V_101 , V_225 , V_149 ) ;
error = F_82 ( V_101 , V_226 ) ;
if ( error )
goto V_233;
if ( V_110 -> V_217 & ( V_218 | V_219 ) ) {
F_99 ( V_101 ) ;
}
error = F_101 ( & V_101 , & V_195 , & V_174 ) ;
if ( error ) {
F_103 ( & V_195 ) ;
goto V_233;
}
return F_71 ( V_101 , V_211 ) ;
V_233:
V_198 |= V_221 ;
V_231:
F_104 ( V_101 , V_198 ) ;
V_228:
return error ;
}
int
F_114 (
struct V_194 * * V_173 ,
struct V_1 * V_2 ,
int V_234 ,
T_19 V_235 )
{
struct V_109 * V_110 = V_2 -> V_7 ;
struct V_194 * V_101 = * V_173 ;
struct V_194 * V_175 ;
T_16 V_195 ;
T_17 V_196 ;
T_20 V_236 ;
T_20 V_237 ;
T_21 V_238 ;
int V_174 ;
int error = 0 ;
int V_239 = 0 ;
ASSERT ( F_22 ( V_2 , V_17 ) ) ;
ASSERT ( ! F_115 ( & F_80 ( V_2 ) -> V_240 ) ||
F_22 ( V_2 , V_23 ) ) ;
ASSERT ( V_235 <= F_116 ( V_2 ) ) ;
ASSERT ( V_101 -> V_179 & V_180 ) ;
ASSERT ( V_2 -> V_44 != NULL ) ;
ASSERT ( V_2 -> V_44 -> V_241 == 0 ) ;
ASSERT ( ! F_117 ( V_110 , V_2 ) ) ;
F_118 ( V_2 , V_235 ) ;
V_236 = F_119 ( V_110 , ( V_242 ) V_235 ) ;
V_237 = F_119 ( V_110 , V_110 -> V_129 -> V_243 ) ;
if ( V_236 == V_237 )
return 0 ;
ASSERT ( V_236 < V_237 ) ;
V_238 = V_237 - V_236 + 1 ;
while ( ! V_239 ) {
F_93 ( & V_195 , & V_196 ) ;
error = F_120 ( V_101 , V_2 ,
V_236 , V_238 ,
F_121 ( V_234 ) ,
V_244 ,
& V_196 , & V_195 ,
& V_239 ) ;
if ( error )
goto V_216;
error = F_101 ( & V_101 , & V_195 , & V_174 ) ;
if ( V_174 )
F_63 ( V_101 , V_2 , 0 ) ;
if ( error )
goto V_216;
if ( V_174 ) {
F_64 ( V_101 , V_2 , V_149 ) ;
}
V_175 = F_70 ( V_101 ) ;
error = F_71 ( V_101 , 0 ) ;
V_101 = V_175 ;
F_63 ( V_101 , V_2 , 0 ) ;
if ( error )
goto V_28;
F_74 ( V_101 -> V_188 ) ;
error = F_75 ( V_101 , & F_89 ( V_110 ) -> V_245 , 0 , 0 ) ;
if ( error )
goto V_28;
}
F_64 ( V_101 , V_2 , V_149 ) ;
F_122 ( V_2 , V_235 ) ;
V_28:
* V_173 = V_101 ;
return error ;
V_216:
F_103 ( & V_195 ) ;
goto V_28;
}
int
F_123 (
T_3 * V_2 )
{
T_18 * V_110 = V_2 -> V_7 ;
int error ;
if ( ! F_62 ( V_2 -> V_3 . V_118 ) || ( V_2 -> V_3 . V_118 == 0 ) )
return 0 ;
if ( V_110 -> V_217 & V_246 )
return 0 ;
if ( ! F_45 ( V_110 ) ) {
int V_247 ;
V_247 = F_124 ( V_2 , V_248 ) ;
if ( V_247 ) {
F_125 ( V_2 , V_249 ) ;
if ( V_2 -> V_250 > 0 ) {
error = F_126 ( F_80 ( V_2 ) -> V_251 ) ;
if ( error )
return error ;
}
}
}
if ( V_2 -> V_3 . V_120 == 0 )
return 0 ;
if ( F_127 ( V_2 , false ) ) {
if ( F_128 ( V_2 , V_249 ) )
return 0 ;
error = F_129 ( V_110 , V_2 , true ) ;
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
struct V_109 * V_110 = V_2 -> V_7 ;
struct V_194 * V_101 ;
int error ;
V_101 = F_90 ( V_110 , V_253 ) ;
error = F_75 ( V_101 , & F_89 ( V_110 ) -> V_245 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_45 ( V_110 ) ) ;
F_104 ( V_101 , 0 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_63 ( V_101 , V_2 , 0 ) ;
V_2 -> V_3 . V_126 = 0 ;
F_64 ( V_101 , V_2 , V_149 ) ;
error = F_114 ( & V_101 , V_2 , V_254 , 0 ) ;
if ( error )
goto V_255;
ASSERT ( V_2 -> V_3 . V_127 == 0 ) ;
error = F_71 ( V_101 , V_211 ) ;
if ( error )
goto V_256;
F_17 ( V_2 , V_17 ) ;
return 0 ;
V_255:
F_104 ( V_101 , V_211 | V_221 ) ;
V_256:
F_17 ( V_2 , V_17 ) ;
return error ;
}
STATIC int
F_132 (
struct V_1 * V_2 )
{
T_16 V_195 ;
T_17 V_196 ;
int V_174 ;
struct V_109 * V_110 = V_2 -> V_7 ;
struct V_194 * V_101 ;
int error ;
V_101 = F_90 ( V_110 , V_253 ) ;
V_101 -> V_179 |= V_257 ;
error = F_75 ( V_101 , & F_89 ( V_110 ) -> V_258 ,
F_133 ( V_110 ) , 0 ) ;
if ( error ) {
if ( error == - V_181 ) {
F_134 ( V_110 ,
L_1
L_2 ) ;
} else {
ASSERT ( F_45 ( V_110 ) ) ;
}
F_104 ( V_101 , V_211 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_63 ( V_101 , V_2 , 0 ) ;
F_93 ( & V_195 , & V_196 ) ;
error = F_135 ( V_101 , V_2 , & V_195 ) ;
if ( error ) {
if ( ! F_45 ( V_110 ) ) {
F_136 ( V_110 , L_3 ,
V_259 , error ) ;
F_137 ( V_110 , V_260 ) ;
}
F_104 ( V_101 , V_211 | V_221 ) ;
F_17 ( V_2 , V_17 ) ;
return error ;
}
F_138 ( V_101 , V_2 , V_261 , - 1 ) ;
error = F_101 ( & V_101 , & V_195 , & V_174 ) ;
if ( error )
F_136 ( V_110 , L_4 ,
V_259 , error ) ;
error = F_71 ( V_101 , V_211 ) ;
if ( error )
F_136 ( V_110 , L_5 ,
V_259 , error ) ;
F_17 ( V_2 , V_17 ) ;
return 0 ;
}
void
F_139 (
T_3 * V_2 )
{
struct V_109 * V_110 ;
int error ;
int V_262 = 0 ;
if ( V_2 -> V_3 . V_118 == 0 ) {
ASSERT ( V_2 -> V_14 . V_169 == 0 ) ;
ASSERT ( V_2 -> V_14 . V_263 == 0 ) ;
return;
}
V_110 = V_2 -> V_7 ;
if ( V_110 -> V_217 & V_246 )
return;
if ( V_2 -> V_3 . V_120 != 0 ) {
if ( F_127 ( V_2 , true ) )
F_129 ( V_110 , V_2 , false ) ;
return;
}
if ( F_62 ( V_2 -> V_3 . V_118 ) &&
( V_2 -> V_3 . V_126 != 0 || F_116 ( V_2 ) != 0 ||
V_2 -> V_3 . V_127 > 0 || V_2 -> V_250 > 0 ) )
V_262 = 1 ;
error = F_109 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_140 ( V_2 -> V_3 . V_118 ) )
error = F_141 ( V_2 ) ;
else if ( V_262 )
error = F_131 ( V_2 ) ;
if ( error )
return;
if ( V_2 -> V_3 . V_172 > 0 ) {
ASSERT ( V_2 -> V_3 . V_264 != 0 ) ;
error = F_142 ( V_2 ) ;
if ( error )
return;
}
if ( V_2 -> V_19 )
F_143 ( V_2 , V_265 ) ;
ASSERT ( V_2 -> V_3 . V_172 == 0 ) ;
error = F_132 ( V_2 ) ;
if ( error )
return;
F_144 ( V_2 ) ;
}
int
F_81 (
T_10 * V_101 ,
T_3 * V_2 )
{
T_18 * V_110 ;
T_22 * V_266 ;
T_8 * V_92 ;
T_15 * V_267 ;
T_15 * V_268 ;
T_23 V_269 ;
short V_270 ;
int V_271 ;
int error ;
ASSERT ( V_2 -> V_3 . V_120 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_118 != 0 ) ;
V_110 = V_101 -> V_111 ;
error = F_145 ( V_110 , V_101 , F_146 ( V_110 , V_2 -> V_55 ) , & V_267 ) ;
if ( error )
return error ;
V_266 = F_147 ( V_267 ) ;
V_269 = F_148 ( V_110 , V_2 -> V_55 ) ;
ASSERT ( V_269 != 0 ) ;
V_270 = V_269 % V_272 ;
ASSERT ( V_266 -> V_273 [ V_270 ] ) ;
ASSERT ( F_149 ( V_266 -> V_273 [ V_270 ] ) != V_269 ) ;
if ( V_266 -> V_273 [ V_270 ] != F_150 ( V_274 ) ) {
error = F_151 ( V_110 , V_101 , & V_2 -> V_275 , & V_92 , & V_268 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_92 -> V_276 == F_150 ( V_274 ) ) ;
V_92 -> V_276 = V_266 -> V_273 [ V_270 ] ;
V_271 = V_2 -> V_275 . V_277 +
F_152 ( T_8 , V_276 ) ;
F_153 ( V_110 , V_92 ) ;
F_154 ( V_101 , V_268 ) ;
F_155 ( V_101 , V_268 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
F_156 ( V_110 , V_268 ) ;
}
ASSERT ( V_269 != 0 ) ;
V_266 -> V_273 [ V_270 ] = F_150 ( V_269 ) ;
V_271 = F_152 ( T_22 , V_273 ) +
( sizeof( T_23 ) * V_270 ) ;
F_157 ( V_101 , V_267 , V_278 ) ;
F_155 ( V_101 , V_267 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_113 (
T_10 * V_101 ,
T_3 * V_2 )
{
T_9 V_279 ;
T_18 * V_110 ;
T_22 * V_266 ;
T_8 * V_92 ;
T_15 * V_267 ;
T_15 * V_268 ;
T_24 V_280 ;
T_23 V_269 ;
T_23 V_281 ;
T_15 * V_282 ;
T_8 * V_283 = NULL ;
short V_270 ;
int V_271 , V_284 = 0 ;
int error ;
V_110 = V_101 -> V_111 ;
V_280 = F_146 ( V_110 , V_2 -> V_55 ) ;
error = F_145 ( V_110 , V_101 , V_280 , & V_267 ) ;
if ( error )
return error ;
V_266 = F_147 ( V_267 ) ;
V_269 = F_148 ( V_110 , V_2 -> V_55 ) ;
ASSERT ( V_269 != 0 ) ;
V_270 = V_269 % V_272 ;
ASSERT ( V_266 -> V_273 [ V_270 ] != F_150 ( V_274 ) ) ;
ASSERT ( V_266 -> V_273 [ V_270 ] ) ;
if ( F_149 ( V_266 -> V_273 [ V_270 ] ) == V_269 ) {
error = F_151 ( V_110 , V_101 , & V_2 -> V_275 , & V_92 , & V_268 ,
0 , 0 ) ;
if ( error ) {
F_158 ( V_110 , L_6 ,
V_259 , error ) ;
return error ;
}
V_281 = F_149 ( V_92 -> V_276 ) ;
ASSERT ( V_281 != 0 ) ;
if ( V_281 != V_274 ) {
V_92 -> V_276 = F_150 ( V_274 ) ;
V_271 = V_2 -> V_275 . V_277 +
F_152 ( T_8 , V_276 ) ;
F_153 ( V_110 , V_92 ) ;
F_154 ( V_101 , V_268 ) ;
F_155 ( V_101 , V_268 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
F_156 ( V_110 , V_268 ) ;
} else {
F_159 ( V_101 , V_268 ) ;
}
ASSERT ( V_281 != 0 ) ;
ASSERT ( V_281 != V_269 ) ;
V_266 -> V_273 [ V_270 ] = F_150 ( V_281 ) ;
V_271 = F_152 ( T_22 , V_273 ) +
( sizeof( T_23 ) * V_270 ) ;
F_157 ( V_101 , V_267 , V_278 ) ;
F_155 ( V_101 , V_267 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
} else {
V_281 = F_149 ( V_266 -> V_273 [ V_270 ] ) ;
V_282 = NULL ;
while ( V_281 != V_269 ) {
struct V_285 V_286 ;
if ( V_282 )
F_159 ( V_101 , V_282 ) ;
V_286 . V_287 = 0 ;
V_279 = F_160 ( V_110 , V_280 , V_281 ) ;
error = V_285 ( V_110 , V_101 , V_279 , & V_286 , 0 ) ;
if ( error ) {
F_158 ( V_110 ,
L_7 ,
V_259 , error ) ;
return error ;
}
error = F_151 ( V_110 , V_101 , & V_286 , & V_283 ,
& V_282 , 0 , 0 ) ;
if ( error ) {
F_158 ( V_110 ,
L_6 ,
V_259 , error ) ;
return error ;
}
V_284 = V_286 . V_277 ;
V_281 = F_149 ( V_283 -> V_276 ) ;
ASSERT ( V_281 != V_274 ) ;
ASSERT ( V_281 != 0 ) ;
}
error = F_151 ( V_110 , V_101 , & V_2 -> V_275 , & V_92 , & V_268 ,
0 , 0 ) ;
if ( error ) {
F_158 ( V_110 , L_8 ,
V_259 , error ) ;
return error ;
}
V_281 = F_149 ( V_92 -> V_276 ) ;
ASSERT ( V_281 != 0 ) ;
ASSERT ( V_281 != V_269 ) ;
if ( V_281 != V_274 ) {
V_92 -> V_276 = F_150 ( V_274 ) ;
V_271 = V_2 -> V_275 . V_277 +
F_152 ( T_8 , V_276 ) ;
F_153 ( V_110 , V_92 ) ;
F_154 ( V_101 , V_268 ) ;
F_155 ( V_101 , V_268 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
F_156 ( V_110 , V_268 ) ;
} else {
F_159 ( V_101 , V_268 ) ;
}
V_283 -> V_276 = F_150 ( V_281 ) ;
ASSERT ( V_281 != 0 ) ;
V_271 = V_284 + F_152 ( T_8 , V_276 ) ;
F_153 ( V_110 , V_283 ) ;
F_154 ( V_101 , V_282 ) ;
F_155 ( V_101 , V_282 , V_271 ,
( V_271 + sizeof( T_23 ) - 1 ) ) ;
F_156 ( V_110 , V_282 ) ;
}
return 0 ;
}
STATIC int
F_161 (
T_3 * V_288 ,
T_10 * V_101 ,
T_9 V_98 )
{
T_18 * V_110 = V_288 -> V_7 ;
int V_289 ;
int V_290 ;
int V_291 ;
int V_39 , V_40 ;
T_25 V_292 ;
T_15 * V_293 ;
T_3 * V_2 ;
T_26 * V_294 ;
T_4 * V_295 ;
struct V_296 * V_297 ;
V_297 = F_162 ( V_110 , F_146 ( V_110 , V_98 ) ) ;
V_289 = F_163 ( V_110 ) ;
V_290 = V_289 << V_110 -> V_8 . V_298 ;
V_291 = V_110 -> V_299 / V_289 ;
for ( V_40 = 0 ; V_40 < V_291 ; V_40 ++ , V_98 += V_290 ) {
V_292 = F_164 ( V_110 , F_146 ( V_110 , V_98 ) ,
F_165 ( V_110 , V_98 ) ) ;
V_293 = F_166 ( V_101 , V_110 -> V_300 , V_292 ,
V_110 -> V_301 * V_289 ,
V_302 ) ;
if ( ! V_293 )
return - V_303 ;
V_293 -> V_304 = & V_305 ;
V_295 = V_293 -> V_306 ;
while ( V_295 ) {
if ( V_295 -> V_307 == V_308 ) {
V_294 = ( T_26 * ) V_295 ;
ASSERT ( V_294 -> V_309 == 1 ) ;
V_295 -> V_310 = V_311 ;
F_167 ( V_110 -> V_312 ,
& V_294 -> V_313 ,
& V_294 -> V_314 . V_315 ) ;
F_130 ( V_294 -> V_316 , V_317 ) ;
}
V_295 = V_295 -> V_318 ;
}
for ( V_39 = 0 ; V_39 < V_290 ; V_39 ++ ) {
V_319:
F_168 () ;
V_2 = F_169 ( & V_297 -> V_320 ,
F_148 ( V_110 , ( V_98 + V_39 ) ) ) ;
if ( ! V_2 ) {
F_170 () ;
continue;
}
F_171 ( & V_2 -> V_321 ) ;
if ( V_2 -> V_55 != V_98 + V_39 ||
F_172 ( V_2 , V_317 ) ) {
F_173 ( & V_2 -> V_321 ) ;
F_170 () ;
continue;
}
F_173 ( & V_2 -> V_321 ) ;
if ( V_2 != V_288 &&
! F_11 ( V_2 , V_17 ) ) {
F_170 () ;
F_26 ( 1 ) ;
goto V_319;
}
F_170 () ;
F_174 ( V_2 ) ;
F_130 ( V_2 , V_317 ) ;
V_294 = V_2 -> V_44 ;
if ( ! V_294 || F_175 ( V_2 ) ) {
ASSERT ( V_2 != V_288 ) ;
F_176 ( V_2 ) ;
F_17 ( V_2 , V_17 ) ;
continue;
}
V_294 -> V_322 = V_294 -> V_323 ;
V_294 -> V_323 = 0 ;
V_294 -> V_309 = 1 ;
F_167 ( V_110 -> V_312 , & V_294 -> V_313 ,
& V_294 -> V_314 . V_315 ) ;
F_177 ( V_293 , V_311 ,
& V_294 -> V_314 ) ;
if ( V_2 != V_288 )
F_17 ( V_2 , V_17 ) ;
}
F_178 ( V_101 , V_293 ) ;
F_179 ( V_101 , V_293 ) ;
}
F_180 ( V_297 ) ;
return 0 ;
}
int
F_135 (
T_10 * V_101 ,
T_3 * V_2 ,
T_16 * V_324 )
{
int error ;
int V_325 ;
T_9 V_326 ;
ASSERT ( F_22 ( V_2 , V_17 ) ) ;
ASSERT ( V_2 -> V_3 . V_120 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_127 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_172 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_126 == 0 || ! F_62 ( V_2 -> V_3 . V_118 ) ) ;
ASSERT ( V_2 -> V_3 . V_128 == 0 ) ;
error = F_113 ( V_101 , V_2 ) ;
if ( error )
return error ;
error = F_181 ( V_101 , V_2 -> V_55 , V_324 , & V_325 , & V_326 ) ;
if ( error )
return error ;
V_2 -> V_3 . V_118 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_138 = 0 ;
V_2 -> V_3 . V_264 = 0 ;
V_2 -> V_3 . V_12 = V_167 ;
V_2 -> V_3 . V_18 = V_167 ;
V_2 -> V_3 . V_327 ++ ;
F_64 ( V_101 , V_2 , V_149 ) ;
if ( V_325 )
error = F_161 ( V_2 , V_101 , V_326 ) ;
return error ;
}
static void
F_182 (
struct V_1 * V_2 )
{
ASSERT ( F_22 ( V_2 , V_17 | V_11 ) ) ;
F_183 ( V_2 , V_21 ) ;
F_184 ( V_2 -> V_7 , V_2 -> V_44 -> V_328 , 0 ) ;
}
static void
F_185 (
struct V_1 * V_2 )
{
T_5 * V_56 = F_30 ( & V_2 -> V_57 , V_329 ) ;
F_31 ( V_59 , & V_2 -> V_57 , V_329 ) ;
F_182 ( V_2 ) ;
do {
F_186 ( V_56 , & V_59 . V_59 , V_60 ) ;
if ( F_187 ( V_2 ) )
F_34 () ;
} while ( F_187 ( V_2 ) );
F_36 ( V_56 , & V_59 . V_59 ) ;
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
T_3 * V_93 ,
struct V_94 * V_95 ,
T_3 * V_2 )
{
T_18 * V_110 = V_93 -> V_7 ;
T_10 * V_101 = NULL ;
int V_193 = F_57 ( V_2 -> V_3 . V_118 ) ;
int error = 0 ;
T_16 V_195 ;
T_17 V_196 ;
int V_198 ;
int V_174 ;
T_2 V_203 ;
F_190 ( V_93 , V_95 ) ;
if ( F_45 ( V_110 ) )
return - V_99 ;
error = F_109 ( V_93 , 0 ) ;
if ( error )
goto V_228;
error = F_109 ( V_2 , 0 ) ;
if ( error )
goto V_228;
if ( V_193 )
V_101 = F_90 ( V_110 , V_330 ) ;
else
V_101 = F_90 ( V_110 , V_331 ) ;
V_198 = V_211 ;
V_203 = F_191 ( V_110 ) ;
error = F_75 ( V_101 , & F_89 ( V_110 ) -> V_332 , V_203 , 0 ) ;
if ( error == - V_181 ) {
V_203 = 0 ;
error = F_75 ( V_101 , & F_89 ( V_110 ) -> V_332 , 0 , 0 ) ;
}
if ( error ) {
ASSERT ( error != - V_181 ) ;
V_198 = 0 ;
goto V_212;
}
F_28 ( V_93 , V_2 , V_17 ) ;
F_63 ( V_101 , V_93 , V_17 ) ;
F_63 ( V_101 , V_2 , V_17 ) ;
V_198 |= V_221 ;
if ( V_193 ) {
ASSERT ( V_2 -> V_3 . V_120 >= 2 ) ;
if ( V_2 -> V_3 . V_120 != 2 ) {
error = - V_333 ;
goto V_212;
}
if ( ! F_192 ( V_2 ) ) {
error = - V_333 ;
goto V_212;
}
error = F_77 ( V_101 , V_93 ) ;
if ( error )
goto V_212;
error = F_77 ( V_101 , V_2 ) ;
if ( error )
goto V_212;
} else {
F_64 ( V_101 , V_93 , V_149 ) ;
}
F_78 ( V_101 , V_93 , V_215 | V_190 ) ;
error = F_77 ( V_101 , V_2 ) ;
if ( error )
goto V_212;
F_93 ( & V_195 , & V_196 ) ;
error = F_193 ( V_101 , V_93 , V_95 , V_2 -> V_55 ,
& V_196 , & V_195 , V_203 ) ;
if ( error ) {
ASSERT ( error != - V_334 ) ;
goto V_216;
}
if ( V_110 -> V_217 & ( V_218 | V_219 ) )
F_99 ( V_101 ) ;
error = F_101 ( & V_101 , & V_195 , & V_174 ) ;
if ( error )
goto V_216;
error = F_71 ( V_101 , V_211 ) ;
if ( error )
goto V_228;
if ( V_193 && F_194 ( V_2 ) )
F_195 ( V_2 ) ;
return 0 ;
V_216:
F_103 ( & V_195 ) ;
V_212:
F_104 ( V_101 , V_198 ) ;
V_228:
return error ;
}
STATIC void
F_196 (
T_3 * V_335 ,
T_3 * V_336 ,
T_3 * V_53 ,
T_3 * V_337 ,
T_3 * * V_338 ,
int * V_339 )
{
T_3 * V_54 ;
int V_39 , V_40 ;
V_338 [ 0 ] = V_335 ;
V_338 [ 1 ] = V_336 ;
V_338 [ 2 ] = V_53 ;
if ( V_337 ) {
* V_339 = 4 ;
V_338 [ 3 ] = V_337 ;
} else {
* V_339 = 3 ;
V_338 [ 3 ] = NULL ;
}
for ( V_39 = 0 ; V_39 < * V_339 ; V_39 ++ ) {
for ( V_40 = 1 ; V_40 < * V_339 ; V_40 ++ ) {
if ( V_338 [ V_40 ] -> V_55 < V_338 [ V_40 - 1 ] -> V_55 ) {
V_54 = V_338 [ V_40 ] ;
V_338 [ V_40 ] = V_338 [ V_40 - 1 ] ;
V_338 [ V_40 - 1 ] = V_54 ;
}
}
}
}
STATIC int
F_197 (
struct V_194 * V_101 ,
struct V_1 * V_335 ,
struct V_94 * V_340 ,
struct V_1 * V_53 ,
struct V_1 * V_336 ,
struct V_94 * V_341 ,
struct V_1 * V_337 ,
struct V_342 * V_195 ,
T_17 * V_196 ,
int V_343 )
{
int error = 0 ;
int V_344 = 0 ;
int V_345 = 0 ;
int V_346 = 0 ;
error = F_198 ( V_101 , V_335 , V_340 ,
V_337 -> V_55 ,
V_196 , V_195 , V_343 ) ;
if ( error )
goto V_28;
error = F_198 ( V_101 , V_336 , V_341 ,
V_53 -> V_55 ,
V_196 , V_195 , V_343 ) ;
if ( error )
goto V_28;
if ( V_335 != V_336 ) {
V_346 = V_215 | V_190 ;
if ( F_57 ( V_337 -> V_3 . V_118 ) ) {
error = F_198 ( V_101 , V_337 , & V_347 ,
V_335 -> V_55 , V_196 ,
V_195 , V_343 ) ;
if ( error )
goto V_28;
if ( ! F_57 ( V_53 -> V_3 . V_118 ) ) {
error = F_77 ( V_101 , V_336 ) ;
if ( error )
goto V_28;
error = F_82 ( V_101 , V_335 ) ;
if ( error )
goto V_28;
}
V_344 |= V_190 ;
V_345 |= V_215 | V_190 ;
}
if ( F_57 ( V_53 -> V_3 . V_118 ) ) {
error = F_198 ( V_101 , V_53 , & V_347 ,
V_336 -> V_55 , V_196 ,
V_195 , V_343 ) ;
if ( error )
goto V_28;
if ( ! F_57 ( V_337 -> V_3 . V_118 ) ) {
error = F_77 ( V_101 , V_335 ) ;
if ( error )
goto V_28;
error = F_82 ( V_101 , V_336 ) ;
if ( error )
goto V_28;
}
V_344 |= V_215 | V_190 ;
V_345 |= V_190 ;
}
}
if ( V_344 ) {
F_78 ( V_101 , V_53 , V_344 ) ;
F_64 ( V_101 , V_53 , V_149 ) ;
}
if ( V_345 ) {
F_78 ( V_101 , V_337 , V_345 ) ;
F_64 ( V_101 , V_337 , V_149 ) ;
}
if ( V_346 ) {
F_78 ( V_101 , V_336 , V_346 ) ;
F_64 ( V_101 , V_336 , V_149 ) ;
}
F_78 ( V_101 , V_335 , V_215 | V_190 ) ;
F_64 ( V_101 , V_335 , V_149 ) ;
V_28:
return error ;
}
int
F_199 (
T_3 * V_348 ,
struct V_94 * V_349 ,
T_3 * V_350 ,
T_3 * V_351 ,
struct V_94 * V_227 ,
T_3 * V_352 ,
unsigned int V_61 )
{
T_10 * V_101 = NULL ;
T_18 * V_110 = V_348 -> V_7 ;
int V_353 ;
int V_354 ;
int error ;
T_16 V_195 ;
T_17 V_196 ;
int V_198 ;
int V_174 ;
T_3 * V_37 [ 4 ] ;
int V_343 ;
int V_339 ;
F_200 ( V_348 , V_351 , V_349 , V_227 ) ;
V_353 = ( V_348 != V_351 ) ;
V_354 = F_57 ( V_350 -> V_3 . V_118 ) ;
F_196 ( V_348 , V_351 , V_350 , V_352 ,
V_37 , & V_339 ) ;
F_93 ( & V_195 , & V_196 ) ;
V_101 = F_90 ( V_110 , V_355 ) ;
V_198 = V_211 ;
V_343 = F_201 ( V_110 , V_227 -> V_206 ) ;
error = F_75 ( V_101 , & F_89 ( V_110 ) -> V_356 , V_343 , 0 ) ;
if ( error == - V_181 ) {
V_343 = 0 ;
error = F_75 ( V_101 , & F_89 ( V_110 ) -> V_356 , 0 , 0 ) ;
}
if ( error ) {
F_104 ( V_101 , 0 ) ;
goto V_228;
}
error = F_202 ( V_37 ) ;
if ( error ) {
F_104 ( V_101 , V_198 ) ;
goto V_228;
}
F_25 ( V_37 , V_339 , V_17 ) ;
F_63 ( V_101 , V_348 , V_17 ) ;
if ( V_353 )
F_63 ( V_101 , V_351 , V_17 ) ;
F_63 ( V_101 , V_350 , V_17 ) ;
if ( V_352 )
F_63 ( V_101 , V_352 , V_17 ) ;
if ( F_111 ( ( V_351 -> V_3 . V_4 & V_79 ) &&
( F_112 ( V_351 ) != F_112 ( V_350 ) ) ) ) {
error = - V_232 ;
goto V_231;
}
if ( V_61 & V_357 ) {
if ( V_352 == NULL ) {
error = - V_358 ;
goto V_231;
}
error = F_197 ( V_101 , V_348 , V_349 , V_350 ,
V_351 , V_227 , V_352 ,
& V_195 , & V_196 , V_343 ) ;
if ( error )
goto V_233;
goto V_359;
}
if ( V_352 == NULL ) {
if ( ! V_343 ) {
error = F_95 ( V_101 , V_351 , V_227 ) ;
if ( error )
goto V_231;
}
error = F_96 ( V_101 , V_351 , V_227 ,
V_350 -> V_55 , & V_196 ,
& V_195 , V_343 ) ;
if ( error == - V_181 )
goto V_231;
if ( error )
goto V_233;
F_78 ( V_101 , V_351 ,
V_215 | V_190 ) ;
if ( V_353 && V_354 ) {
error = F_82 ( V_101 , V_351 ) ;
if ( error )
goto V_233;
}
} else {
if ( F_57 ( V_352 -> V_3 . V_118 ) ) {
if ( ! ( F_192 ( V_352 ) ) ||
( V_352 -> V_3 . V_120 > 2 ) ) {
error = - V_360 ;
goto V_231;
}
}
error = F_198 ( V_101 , V_351 , V_227 ,
V_350 -> V_55 ,
& V_196 , & V_195 , V_343 ) ;
if ( error )
goto V_233;
F_78 ( V_101 , V_351 ,
V_215 | V_190 ) ;
error = F_77 ( V_101 , V_352 ) ;
if ( error )
goto V_233;
if ( V_354 ) {
error = F_77 ( V_101 , V_352 ) ;
if ( error )
goto V_233;
}
}
if ( V_353 && V_354 ) {
error = F_198 ( V_101 , V_350 , & V_347 ,
V_351 -> V_55 ,
& V_196 , & V_195 , V_343 ) ;
ASSERT ( error != - V_360 ) ;
if ( error )
goto V_233;
}
F_78 ( V_101 , V_350 , V_190 ) ;
F_64 ( V_101 , V_350 , V_149 ) ;
if ( V_354 && ( V_353 || V_352 != NULL ) ) {
error = F_77 ( V_101 , V_348 ) ;
if ( error )
goto V_233;
}
error = F_193 ( V_101 , V_348 , V_349 , V_350 -> V_55 ,
& V_196 , & V_195 , V_343 ) ;
if ( error )
goto V_233;
F_78 ( V_101 , V_348 , V_215 | V_190 ) ;
F_64 ( V_101 , V_348 , V_149 ) ;
if ( V_353 )
F_64 ( V_101 , V_351 , V_149 ) ;
V_359:
if ( V_110 -> V_217 & ( V_218 | V_219 ) ) {
F_99 ( V_101 ) ;
}
error = F_101 ( & V_101 , & V_195 , & V_174 ) ;
if ( error ) {
F_103 ( & V_195 ) ;
F_104 ( V_101 , ( V_211 |
V_221 ) ) ;
goto V_228;
}
return F_71 ( V_101 , V_211 ) ;
V_233:
V_198 |= V_221 ;
V_231:
F_103 ( & V_195 ) ;
F_104 ( V_101 , V_198 ) ;
V_228:
return error ;
}
STATIC int
F_203 (
T_3 * V_2 ,
T_15 * V_293 )
{
T_18 * V_110 = V_2 -> V_7 ;
struct V_296 * V_297 ;
unsigned long V_361 , V_362 ;
unsigned long V_290 ;
int V_363 ;
T_3 * * V_364 ;
T_3 * V_365 ;
int V_366 ;
int V_367 = 0 ;
int V_368 ;
int V_39 ;
V_297 = F_162 ( V_110 , F_146 ( V_110 , V_2 -> V_55 ) ) ;
V_290 = V_110 -> V_369 >> V_110 -> V_8 . V_370 ;
V_363 = V_290 * sizeof( T_3 * ) ;
V_364 = F_204 ( V_363 , V_371 | V_372 ) ;
if ( ! V_364 )
goto V_373;
V_362 = ~ ( ( ( V_110 -> V_369 >> V_110 -> V_8 . V_370 ) ) - 1 ) ;
V_361 = F_148 ( V_110 , V_2 -> V_55 ) & V_362 ;
F_168 () ;
V_366 = F_205 ( & V_297 -> V_320 , ( void * * ) V_364 ,
V_361 , V_290 ) ;
if ( V_366 == 0 )
goto V_374;
for ( V_39 = 0 ; V_39 < V_366 ; V_39 ++ ) {
V_365 = V_364 [ V_39 ] ;
if ( V_365 == V_2 )
continue;
F_171 ( & V_2 -> V_321 ) ;
if ( ! V_2 -> V_55 ||
( F_148 ( V_110 , V_365 -> V_55 ) & V_362 ) != V_361 ) {
F_173 ( & V_2 -> V_321 ) ;
continue;
}
F_173 ( & V_2 -> V_321 ) ;
if ( F_175 ( V_365 ) && F_187 ( V_365 ) == 0 )
continue;
if ( ! F_11 ( V_365 , V_11 ) )
continue;
if ( ! F_35 ( V_365 ) ) {
F_17 ( V_365 , V_11 ) ;
continue;
}
if ( F_187 ( V_365 ) ) {
F_176 ( V_365 ) ;
F_17 ( V_365 , V_11 ) ;
continue;
}
if ( ! F_175 ( V_365 ) ) {
int error ;
error = F_206 ( V_365 , V_293 ) ;
if ( error ) {
F_17 ( V_365 , V_11 ) ;
goto V_375;
}
V_367 ++ ;
} else {
F_176 ( V_365 ) ;
}
F_17 ( V_365 , V_11 ) ;
}
if ( V_367 ) {
F_207 ( V_376 ) ;
F_208 ( V_377 , V_367 ) ;
}
V_374:
F_170 () ;
F_48 ( V_364 ) ;
V_373:
F_180 ( V_297 ) ;
return 0 ;
V_375:
F_170 () ;
V_368 = ( V_293 -> V_378 & V_379 ) ;
if ( V_368 )
F_72 ( V_293 ) ;
F_137 ( V_110 , V_380 ) ;
if ( ! V_368 ) {
if ( V_293 -> V_381 ) {
F_209 ( V_293 ) ;
F_210 ( V_293 ) ;
F_211 ( V_293 , - V_99 ) ;
F_212 ( V_293 ) ;
} else {
F_210 ( V_293 ) ;
F_72 ( V_293 ) ;
}
}
F_213 ( V_365 , false ) ;
F_48 ( V_364 ) ;
F_180 ( V_297 ) ;
return - V_382 ;
}
int
F_214 (
struct V_1 * V_2 ,
struct V_383 * * V_384 )
{
struct V_109 * V_110 = V_2 -> V_7 ;
struct V_383 * V_293 ;
struct V_385 * V_92 ;
int error ;
F_207 ( V_386 ) ;
ASSERT ( F_22 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_33 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_127 > F_215 ( V_2 , V_254 ) ) ;
* V_384 = NULL ;
F_188 ( V_2 ) ;
if ( F_128 ( V_2 , V_317 ) ) {
F_176 ( V_2 ) ;
return 0 ;
}
if ( F_45 ( V_110 ) ) {
error = - V_99 ;
goto V_387;
}
error = F_151 ( V_110 , NULL , & V_2 -> V_275 , & V_92 , & V_293 , V_388 ,
0 ) ;
if ( error || ! V_293 ) {
F_176 ( V_2 ) ;
return error ;
}
error = F_206 ( V_2 , V_293 ) ;
if ( error )
goto V_389;
if ( F_216 ( V_293 ) )
F_217 ( V_110 , 0 ) ;
error = F_203 ( V_2 , V_293 ) ;
if ( error )
goto V_375;
* V_384 = V_293 ;
return 0 ;
V_389:
F_72 ( V_293 ) ;
F_137 ( V_110 , V_380 ) ;
V_375:
error = - V_382 ;
V_387:
F_213 ( V_2 , false ) ;
return error ;
}
STATIC int
F_206 (
struct V_1 * V_2 ,
struct V_383 * V_293 )
{
struct V_390 * V_294 = V_2 -> V_44 ;
struct V_385 * V_92 ;
struct V_109 * V_110 = V_2 -> V_7 ;
ASSERT ( F_22 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_33 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_127 > F_215 ( V_2 , V_254 ) ) ;
ASSERT ( V_294 != NULL && V_294 -> V_323 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_117 > 1 ) ;
V_92 = ( T_8 * ) F_218 ( V_293 , V_2 -> V_275 . V_277 ) ;
if ( F_219 ( V_92 -> V_391 != F_220 ( V_392 ) ,
V_110 , V_393 , V_394 ) ) {
F_221 ( V_110 , V_395 ,
L_9 ,
V_259 , V_2 -> V_55 , F_41 ( V_92 -> V_391 ) , V_92 ) ;
goto V_389;
}
if ( F_219 ( V_2 -> V_3 . V_391 != V_392 ,
V_110 , V_396 , V_397 ) ) {
F_221 ( V_110 , V_395 ,
L_10 ,
V_259 , V_2 -> V_55 , V_2 , V_2 -> V_3 . V_391 ) ;
goto V_389;
}
if ( F_62 ( V_2 -> V_3 . V_118 ) ) {
if ( F_219 (
( V_2 -> V_3 . V_12 != V_167 ) &&
( V_2 -> V_3 . V_12 != V_13 ) ,
V_110 , V_398 , V_399 ) ) {
F_221 ( V_110 , V_395 ,
L_11 ,
V_259 , V_2 -> V_55 , V_2 ) ;
goto V_389;
}
} else if ( F_57 ( V_2 -> V_3 . V_118 ) ) {
if ( F_219 (
( V_2 -> V_3 . V_12 != V_167 ) &&
( V_2 -> V_3 . V_12 != V_13 ) &&
( V_2 -> V_3 . V_12 != V_400 ) ,
V_110 , V_401 , V_402 ) ) {
F_221 ( V_110 , V_395 ,
L_12 ,
V_259 , V_2 -> V_55 , V_2 ) ;
goto V_389;
}
}
if ( F_219 ( V_2 -> V_3 . V_127 + V_2 -> V_3 . V_172 >
V_2 -> V_3 . V_128 , V_110 , V_403 ,
V_404 ) ) {
F_221 ( V_110 , V_395 ,
L_13
L_14 ,
V_259 , V_2 -> V_55 ,
V_2 -> V_3 . V_127 + V_2 -> V_3 . V_172 ,
V_2 -> V_3 . V_128 , V_2 ) ;
goto V_389;
}
if ( F_219 ( V_2 -> V_3 . V_264 > V_110 -> V_8 . V_405 ,
V_110 , V_406 , V_407 ) ) {
F_221 ( V_110 , V_395 ,
L_15 ,
V_259 , V_2 -> V_55 , V_2 -> V_3 . V_264 , V_2 ) ;
goto V_389;
}
if ( V_2 -> V_3 . V_117 < 3 )
V_2 -> V_3 . V_408 ++ ;
F_222 ( V_92 , & V_2 -> V_3 ) ;
if ( V_2 -> V_3 . V_408 == V_409 )
V_2 -> V_3 . V_408 = 0 ;
F_223 ( V_2 , V_92 , V_294 , V_254 ) ;
if ( F_39 ( V_2 ) )
F_223 ( V_2 , V_92 , V_294 , V_265 ) ;
F_156 ( V_110 , V_293 ) ;
V_294 -> V_322 = V_294 -> V_323 ;
V_294 -> V_323 = 0 ;
V_294 -> V_309 = 1 ;
F_167 ( V_110 -> V_312 , & V_294 -> V_313 ,
& V_294 -> V_314 . V_315 ) ;
F_177 ( V_293 , V_410 , & V_294 -> V_314 ) ;
if ( V_2 -> V_3 . V_117 == 3 )
V_92 -> V_145 = F_224 ( V_294 -> V_314 . V_315 ) ;
F_153 ( V_110 , V_92 ) ;
ASSERT ( V_293 -> V_306 != NULL ) ;
ASSERT ( V_293 -> V_381 != NULL ) ;
return 0 ;
V_389:
return - V_382 ;
}
