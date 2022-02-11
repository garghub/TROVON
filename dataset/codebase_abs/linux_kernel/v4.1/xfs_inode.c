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
static inline int
F_25 ( int V_10 , int V_36 )
{
if ( V_10 & ( V_22 | V_23 ) ) {
ASSERT ( V_36 + V_37 <
( 1 << ( V_38 - V_39 ) ) ) ;
V_10 |= ( V_36 + V_37 ) << V_39 ;
}
if ( V_10 & ( V_24 | V_25 ) ) {
ASSERT ( V_36 + V_37 <
( 1 << ( V_40 - V_38 ) ) ) ;
V_10 |= ( V_36 + V_37 ) <<
V_38 ;
}
if ( V_10 & ( V_11 | V_17 ) )
V_10 |= ( V_36 + V_37 ) << V_40 ;
return V_10 ;
}
void
F_26 (
T_3 * * V_41 ,
int V_42 ,
T_2 V_10 )
{
int V_43 = 0 , V_44 , V_45 , V_46 ;
T_4 * V_47 ;
ASSERT ( V_41 && V_42 >= 2 && V_42 <= 5 ) ;
V_46 = 0 ;
V_44 = 0 ;
V_48:
for (; V_44 < V_42 ; V_44 ++ ) {
ASSERT ( V_41 [ V_44 ] ) ;
if ( V_44 && ( V_41 [ V_44 ] == V_41 [ V_44 - 1 ] ) )
continue;
if ( ! V_46 ) {
for ( V_45 = ( V_44 - 1 ) ; V_45 >= 0 && ! V_46 ; V_45 -- ) {
V_47 = ( T_4 * ) V_41 [ V_45 ] -> V_49 ;
if ( V_47 && ( V_47 -> V_50 & V_51 ) )
V_46 ++ ;
}
}
if ( ! V_46 ) {
F_4 ( V_41 [ V_44 ] , F_25 ( V_10 , V_44 ) ) ;
continue;
}
ASSERT ( V_44 != 0 ) ;
if ( F_12 ( V_41 [ V_44 ] , F_25 ( V_10 , V_44 ) ) )
continue;
V_43 ++ ;
for ( V_45 = V_44 - 1 ; V_45 >= 0 ; V_45 -- ) {
if ( V_45 != ( V_44 - 1 ) && V_41 [ V_45 ] == V_41 [ V_45 + 1 ] )
continue;
F_18 ( V_41 [ V_45 ] , V_10 ) ;
}
if ( ( V_43 % 5 ) == 0 ) {
F_27 ( 1 ) ;
#ifdef F_28
V_52 ++ ;
#endif
}
V_44 = 0 ;
V_46 = 0 ;
goto V_48;
}
#ifdef F_28
if ( V_43 ) {
if ( V_43 < 5 ) V_53 ++ ;
else if ( V_43 < 100 ) V_54 ++ ;
else V_55 ++ ;
} else {
V_56 ++ ;
}
#endif
}
void
F_29 (
T_3 * V_57 ,
T_3 * V_58 ,
T_2 V_10 )
{
T_3 * V_59 ;
int V_43 = 0 ;
T_4 * V_47 ;
if ( V_10 & ( V_22 | V_23 ) ) {
ASSERT ( ! ( V_10 & ( V_24 | V_25 ) ) ) ;
ASSERT ( ! ( V_10 & ( V_11 | V_17 ) ) ) ;
} else if ( V_10 & ( V_24 | V_25 ) )
ASSERT ( ! ( V_10 & ( V_11 | V_17 ) ) ) ;
ASSERT ( V_57 -> V_60 != V_58 -> V_60 ) ;
if ( V_57 -> V_60 > V_58 -> V_60 ) {
V_59 = V_57 ;
V_57 = V_58 ;
V_58 = V_59 ;
}
V_48:
F_4 ( V_57 , F_25 ( V_10 , 0 ) ) ;
V_47 = ( T_4 * ) V_57 -> V_49 ;
if ( V_47 && ( V_47 -> V_50 & V_51 ) ) {
if ( ! F_12 ( V_58 , F_25 ( V_10 , 1 ) ) ) {
F_18 ( V_57 , V_10 ) ;
if ( ( ++ V_43 % 5 ) == 0 )
F_27 ( 1 ) ;
goto V_48;
}
} else {
F_4 ( V_58 , F_25 ( V_10 , 1 ) ) ;
}
}
void
F_30 (
struct V_1 * V_2 )
{
T_5 * V_61 = F_31 ( & V_2 -> V_62 , V_63 ) ;
F_32 ( V_64 , & V_2 -> V_62 , V_63 ) ;
do {
F_33 ( V_61 , & V_64 . V_64 , V_65 ) ;
if ( F_34 ( V_2 ) )
F_35 () ;
} while ( ! F_36 ( V_2 ) );
F_37 ( V_61 , & V_64 . V_64 ) ;
}
STATIC T_2
F_38 (
T_6 V_4 )
{
T_2 V_66 = 0 ;
if ( V_4 & V_67 ) {
if ( V_4 & V_68 )
V_66 |= V_69 ;
if ( V_4 & V_70 )
V_66 |= V_71 ;
if ( V_4 & V_72 )
V_66 |= V_73 ;
if ( V_4 & V_74 )
V_66 |= V_75 ;
if ( V_4 & V_76 )
V_66 |= V_77 ;
if ( V_4 & V_78 )
V_66 |= V_79 ;
if ( V_4 & V_80 )
V_66 |= V_81 ;
if ( V_4 & V_82 )
V_66 |= V_83 ;
if ( V_4 & V_84 )
V_66 |= V_85 ;
if ( V_4 & V_86 )
V_66 |= V_87 ;
if ( V_4 & V_5 )
V_66 |= V_88 ;
if ( V_4 & V_89 )
V_66 |= V_90 ;
if ( V_4 & V_91 )
V_66 |= V_92 ;
if ( V_4 & V_93 )
V_66 |= V_94 ;
}
return V_66 ;
}
T_2
F_39 (
T_3 * V_2 )
{
T_7 * V_95 = & V_2 -> V_3 ;
return F_38 ( V_95 -> V_4 ) |
( F_40 ( V_2 ) ? V_96 : 0 ) ;
}
T_2
F_41 (
T_8 * V_97 )
{
return F_38 ( F_42 ( V_97 -> V_4 ) ) |
( F_43 ( V_97 ) ? V_96 : 0 ) ;
}
int
F_44 (
T_3 * V_98 ,
struct V_99 * V_100 ,
T_3 * * V_101 ,
struct V_99 * V_102 )
{
T_9 V_103 ;
int error ;
T_2 V_10 ;
F_45 ( V_98 , V_100 ) ;
if ( F_46 ( V_98 -> V_7 ) )
return - V_104 ;
V_10 = F_3 ( V_98 ) ;
error = F_47 ( NULL , V_98 , V_100 , & V_103 , V_102 ) ;
F_18 ( V_98 , V_10 ) ;
if ( error )
goto V_31;
error = F_48 ( V_98 -> V_7 , NULL , V_103 , 0 , 0 , V_101 ) ;
if ( error )
goto V_105;
return 0 ;
V_105:
if ( V_102 )
F_49 ( V_102 -> V_100 ) ;
V_31:
* V_101 = NULL ;
return error ;
}
int
F_50 (
T_10 * V_106 ,
T_3 * V_107 ,
T_11 V_108 ,
T_12 V_109 ,
T_13 V_110 ,
T_14 V_111 ,
int V_112 ,
T_15 * * V_113 ,
T_3 * * V_101 )
{
struct V_114 * V_115 = V_106 -> V_116 ;
T_9 V_117 ;
T_3 * V_2 ;
T_2 V_66 ;
int error ;
struct V_118 V_119 ;
error = F_51 ( V_106 , V_107 ? V_107 -> V_60 : 0 , V_108 , V_112 ,
V_113 , & V_117 ) ;
if ( error )
return error ;
if ( * V_113 || V_117 == V_120 ) {
* V_101 = NULL ;
return 0 ;
}
ASSERT ( * V_113 == NULL ) ;
error = F_48 ( V_115 , V_106 , V_117 , V_121 ,
V_17 , & V_2 ) ;
if ( error )
return error ;
ASSERT ( V_2 != NULL ) ;
if ( V_2 -> V_3 . V_122 == 1 )
V_2 -> V_3 . V_122 = 2 ;
V_2 -> V_3 . V_123 = V_108 ;
V_2 -> V_3 . V_124 = 0 ;
V_2 -> V_3 . V_125 = V_109 ;
ASSERT ( V_2 -> V_3 . V_125 == V_109 ) ;
V_2 -> V_3 . V_126 = F_52 ( F_53 () ) ;
V_2 -> V_3 . V_127 = F_54 ( F_55 () ) ;
F_56 ( V_2 , V_111 ) ;
memset ( & ( V_2 -> V_3 . V_128 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_128 ) ) ;
if ( V_107 && F_57 ( V_107 ) ) {
V_2 -> V_3 . V_127 = V_107 -> V_3 . V_127 ;
if ( ( V_107 -> V_3 . V_123 & V_129 ) && F_58 ( V_108 ) ) {
V_2 -> V_3 . V_123 |= V_129 ;
}
}
if ( ( V_130 ) &&
( V_2 -> V_3 . V_123 & V_129 ) &&
( ! F_59 ( F_60 ( V_2 -> V_3 . V_127 ) ) ) ) {
V_2 -> V_3 . V_123 &= ~ V_129 ;
}
V_2 -> V_3 . V_131 = 0 ;
V_2 -> V_3 . V_132 = 0 ;
ASSERT ( V_2 -> V_3 . V_133 == 0 ) ;
V_119 = F_61 ( V_115 -> V_134 ) ;
V_2 -> V_3 . V_135 . V_136 = ( V_137 ) V_119 . V_138 ;
V_2 -> V_3 . V_135 . V_139 = ( V_137 ) V_119 . V_140 ;
V_2 -> V_3 . V_141 = V_2 -> V_3 . V_135 ;
V_2 -> V_3 . V_142 = V_2 -> V_3 . V_135 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_143 = 0 ;
V_2 -> V_3 . V_144 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( V_2 -> V_3 . V_122 == 3 ) {
ASSERT ( V_2 -> V_3 . V_145 == V_117 ) ;
ASSERT ( F_62 ( & V_2 -> V_3 . V_146 , & V_115 -> V_8 . V_147 ) ) ;
V_2 -> V_3 . V_148 = 0 ;
V_2 -> V_3 . V_149 = 1 ;
V_2 -> V_3 . V_150 = 0 ;
V_2 -> V_3 . V_151 = 0 ;
memset ( & ( V_2 -> V_3 . V_152 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_152 ) ) ;
V_2 -> V_3 . V_153 = V_2 -> V_3 . V_135 ;
}
V_66 = V_154 ;
switch ( V_108 & V_155 ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
V_2 -> V_3 . V_12 = V_160 ;
V_2 -> V_14 . V_161 . V_162 = V_110 ;
V_2 -> V_14 . V_15 = 0 ;
V_66 |= V_163 ;
break;
case V_164 :
case V_165 :
if ( V_107 && ( V_107 -> V_3 . V_4 & V_67 ) ) {
T_2 V_4 = 0 ;
if ( F_58 ( V_108 ) ) {
if ( V_107 -> V_3 . V_4 & V_82 )
V_4 |= V_82 ;
if ( V_107 -> V_3 . V_4 & V_89 ) {
V_4 |= V_89 ;
V_2 -> V_3 . V_6 = V_107 -> V_3 . V_6 ;
}
if ( V_107 -> V_3 . V_4 & V_84 )
V_4 |= V_84 ;
} else if ( F_63 ( V_108 ) ) {
if ( V_107 -> V_3 . V_4 & V_82 )
V_4 |= V_68 ;
if ( V_107 -> V_3 . V_4 & V_89 ) {
V_4 |= V_5 ;
V_2 -> V_3 . V_6 = V_107 -> V_3 . V_6 ;
}
}
if ( ( V_107 -> V_3 . V_4 & V_78 ) &&
V_166 )
V_4 |= V_78 ;
if ( ( V_107 -> V_3 . V_4 & V_80 ) &&
V_167 )
V_4 |= V_80 ;
if ( ( V_107 -> V_3 . V_4 & V_76 ) &&
V_168 )
V_4 |= V_76 ;
if ( ( V_107 -> V_3 . V_4 & V_86 ) &&
V_169 )
V_4 |= V_86 ;
if ( ( V_107 -> V_3 . V_4 & V_91 ) &&
V_170 )
V_4 |= V_91 ;
if ( V_107 -> V_3 . V_4 & V_93 )
V_4 |= V_93 ;
V_2 -> V_3 . V_4 |= V_4 ;
}
case V_171 :
V_2 -> V_3 . V_12 = V_172 ;
V_2 -> V_14 . V_15 = V_16 ;
V_2 -> V_14 . V_173 = V_2 -> V_14 . V_174 = 0 ;
V_2 -> V_14 . V_175 . V_176 = NULL ;
break;
default:
ASSERT ( 0 ) ;
}
V_2 -> V_3 . V_18 = V_172 ;
V_2 -> V_3 . V_177 = 0 ;
F_64 ( V_106 , V_2 , V_17 ) ;
F_65 ( V_106 , V_2 , V_66 ) ;
F_66 ( V_2 ) ;
* V_101 = V_2 ;
return 0 ;
}
int
F_67 (
T_10 * * V_178 ,
T_3 * V_98 ,
T_11 V_108 ,
T_12 V_109 ,
T_13 V_110 ,
T_14 V_111 ,
int V_112 ,
T_3 * * V_101 ,
int * V_179 )
{
T_10 * V_106 ;
T_10 * V_180 ;
T_3 * V_2 ;
T_15 * V_113 = NULL ;
int V_181 ;
void * V_182 ;
T_2 V_183 ;
V_106 = * V_178 ;
ASSERT ( V_106 -> V_184 & V_185 ) ;
V_181 = F_50 ( V_106 , V_98 , V_108 , V_109 , V_110 , V_111 , V_112 ,
& V_113 , & V_2 ) ;
if ( V_181 ) {
* V_101 = NULL ;
return V_181 ;
}
if ( ! V_113 && ! V_2 ) {
* V_101 = NULL ;
return - V_186 ;
}
if ( V_113 ) {
struct V_187 V_188 ;
F_68 ( V_106 , V_113 ) ;
V_188 . V_189 = F_69 ( V_106 ) ;
V_188 . V_190 = F_70 ( V_106 ) ;
V_182 = NULL ;
V_183 = 0 ;
if ( V_106 -> V_191 ) {
V_182 = ( void * ) V_106 -> V_191 ;
V_106 -> V_191 = NULL ;
V_183 = V_106 -> V_184 & V_192 ;
V_106 -> V_184 &= ~ ( V_192 ) ;
}
V_180 = F_71 ( V_106 ) ;
V_181 = F_72 ( V_106 , 0 ) ;
V_106 = V_180 ;
if ( V_179 != NULL ) {
* V_179 = 1 ;
}
if ( V_181 ) {
F_73 ( V_113 ) ;
if ( V_182 ) {
V_106 -> V_191 = V_182 ;
F_74 ( V_106 ) ;
}
* V_178 = V_180 ;
* V_101 = NULL ;
return V_181 ;
}
F_75 ( V_106 -> V_193 ) ;
V_188 . V_194 = V_185 ;
V_181 = F_76 ( V_106 , & V_188 , 0 , 0 ) ;
if ( V_182 ) {
V_106 -> V_191 = V_182 ;
V_106 -> V_184 |= V_183 ;
}
if ( V_181 ) {
F_73 ( V_113 ) ;
* V_178 = V_180 ;
* V_101 = NULL ;
return V_181 ;
}
F_77 ( V_106 , V_113 ) ;
V_181 = F_50 ( V_106 , V_98 , V_108 , V_109 , V_110 , V_111 ,
V_112 , & V_113 , & V_2 ) ;
if ( V_181 ) {
* V_178 = V_106 ;
* V_101 = NULL ;
return V_181 ;
}
ASSERT ( ! V_113 && V_2 ) ;
} else {
if ( V_179 != NULL )
* V_179 = 0 ;
}
* V_101 = V_2 ;
* V_178 = V_106 ;
return 0 ;
}
int
F_78 (
T_10 * V_106 ,
T_3 * V_2 )
{
int error ;
F_79 ( V_106 , V_2 , V_195 ) ;
ASSERT ( V_2 -> V_3 . V_125 > 0 ) ;
V_2 -> V_3 . V_125 -- ;
F_80 ( F_81 ( V_2 ) ) ;
F_65 ( V_106 , V_2 , V_154 ) ;
error = 0 ;
if ( V_2 -> V_3 . V_125 == 0 ) {
error = F_82 ( V_106 , V_2 ) ;
}
return error ;
}
int
F_83 (
T_10 * V_106 ,
T_3 * V_2 )
{
F_79 ( V_106 , V_2 , V_195 ) ;
ASSERT ( V_2 -> V_3 . V_122 > 1 ) ;
ASSERT ( V_2 -> V_3 . V_125 > 0 || ( F_81 ( V_2 ) -> V_196 & V_197 ) ) ;
V_2 -> V_3 . V_125 ++ ;
F_84 ( F_81 ( V_2 ) ) ;
F_65 ( V_106 , V_2 , V_154 ) ;
return 0 ;
}
int
F_85 (
T_3 * V_98 ,
struct V_99 * V_100 ,
T_11 V_108 ,
T_13 V_110 ,
T_3 * * V_101 )
{
int V_198 = F_58 ( V_108 ) ;
struct V_114 * V_115 = V_98 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_199 * V_106 = NULL ;
int error ;
T_16 V_200 ;
T_17 V_201 ;
bool V_202 = false ;
T_2 V_203 ;
int V_179 ;
T_14 V_111 ;
struct V_204 * V_205 = NULL ;
struct V_204 * V_206 = NULL ;
struct V_204 * V_207 = NULL ;
struct V_187 * V_188 ;
T_2 V_208 ;
F_86 ( V_98 , V_100 ) ;
if ( F_46 ( V_115 ) )
return - V_104 ;
V_111 = F_87 ( V_98 ) ;
error = F_88 ( V_98 , F_52 ( F_53 () ) ,
F_54 ( F_55 () ) , V_111 ,
V_209 | V_210 ,
& V_205 , & V_206 , & V_207 ) ;
if ( error )
return error ;
if ( V_198 ) {
V_110 = 0 ;
V_208 = F_89 ( V_115 , V_100 -> V_211 ) ;
V_188 = & F_90 ( V_115 ) -> V_212 ;
V_106 = F_91 ( V_115 , V_213 ) ;
} else {
V_208 = F_92 ( V_115 , V_100 -> V_211 ) ;
V_188 = & F_90 ( V_115 ) -> V_214 ;
V_106 = F_91 ( V_115 , V_215 ) ;
}
V_203 = V_216 ;
error = F_76 ( V_106 , V_188 , V_208 , 0 ) ;
if ( error == - V_186 ) {
F_93 ( V_115 ) ;
error = F_76 ( V_106 , V_188 , V_208 , 0 ) ;
}
if ( error == - V_186 ) {
V_208 = 0 ;
error = F_76 ( V_106 , V_188 , 0 , 0 ) ;
}
if ( error ) {
V_203 = 0 ;
goto V_217;
}
F_4 ( V_98 , V_17 | V_218 ) ;
V_202 = true ;
F_94 ( & V_200 , & V_201 ) ;
error = F_95 ( V_106 , V_115 , V_205 , V_206 ,
V_207 , V_208 , 1 , 0 ) ;
if ( error )
goto V_217;
if ( ! V_208 ) {
error = F_96 ( V_106 , V_98 , V_100 ) ;
if ( error )
goto V_217;
}
error = F_67 ( & V_106 , V_98 , V_108 , V_198 ? 2 : 1 , V_110 ,
V_111 , V_208 > 0 , & V_2 , & V_179 ) ;
if ( error ) {
if ( error == - V_186 )
goto V_217;
goto V_219;
}
F_64 ( V_106 , V_98 , V_17 ) ;
V_202 = false ;
error = F_97 ( V_106 , V_98 , V_100 , V_2 -> V_60 ,
& V_201 , & V_200 , V_208 ?
V_208 - F_98 ( V_115 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_186 ) ;
goto V_219;
}
F_79 ( V_106 , V_98 , V_220 | V_195 ) ;
F_65 ( V_106 , V_98 , V_154 ) ;
if ( V_198 ) {
error = F_99 ( V_106 , V_2 , V_98 ) ;
if ( error )
goto V_221;
error = F_83 ( V_106 , V_98 ) ;
if ( error )
goto V_221;
}
if ( V_115 -> V_222 & ( V_223 | V_224 ) )
F_100 ( V_106 ) ;
F_101 ( V_106 , V_2 , V_205 , V_206 , V_207 ) ;
error = F_102 ( & V_106 , & V_200 , & V_179 ) ;
if ( error )
goto V_221;
error = F_72 ( V_106 , V_216 ) ;
if ( error )
goto V_225;
F_103 ( V_205 ) ;
F_103 ( V_206 ) ;
F_103 ( V_207 ) ;
* V_101 = V_2 ;
return 0 ;
V_221:
F_104 ( & V_200 ) ;
V_219:
V_203 |= V_226 ;
V_217:
F_105 ( V_106 , V_203 ) ;
V_225:
if ( V_2 ) {
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
}
F_103 ( V_205 ) ;
F_103 ( V_206 ) ;
F_103 ( V_207 ) ;
if ( V_202 )
F_18 ( V_98 , V_17 ) ;
return error ;
}
int
F_108 (
struct V_1 * V_98 ,
struct V_227 * V_227 ,
T_11 V_108 ,
struct V_1 * * V_101 )
{
struct V_114 * V_115 = V_98 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_199 * V_106 = NULL ;
int error ;
T_2 V_203 = V_216 ;
T_14 V_111 ;
struct V_204 * V_205 = NULL ;
struct V_204 * V_206 = NULL ;
struct V_204 * V_207 = NULL ;
struct V_187 * V_188 ;
T_2 V_208 ;
if ( F_46 ( V_115 ) )
return - V_104 ;
V_111 = F_87 ( V_98 ) ;
error = F_88 ( V_98 , F_52 ( F_53 () ) ,
F_54 ( F_55 () ) , V_111 ,
V_209 | V_210 ,
& V_205 , & V_206 , & V_207 ) ;
if ( error )
return error ;
V_208 = F_98 ( V_115 ) ;
V_106 = F_91 ( V_115 , V_228 ) ;
V_188 = & F_90 ( V_115 ) -> V_229 ;
error = F_76 ( V_106 , V_188 , V_208 , 0 ) ;
if ( error == - V_186 ) {
V_208 = 0 ;
error = F_76 ( V_106 , V_188 , 0 , 0 ) ;
}
if ( error ) {
V_203 = 0 ;
goto V_217;
}
error = F_95 ( V_106 , V_115 , V_205 , V_206 ,
V_207 , V_208 , 1 , 0 ) ;
if ( error )
goto V_217;
error = F_67 ( & V_106 , V_98 , V_108 , 1 , 0 ,
V_111 , V_208 > 0 , & V_2 , NULL ) ;
if ( error ) {
if ( error == - V_186 )
goto V_217;
goto V_219;
}
if ( V_115 -> V_222 & V_223 )
F_100 ( V_106 ) ;
F_101 ( V_106 , V_2 , V_205 , V_206 , V_207 ) ;
V_2 -> V_3 . V_125 -- ;
error = F_82 ( V_106 , V_2 ) ;
if ( error )
goto V_219;
error = F_72 ( V_106 , V_216 ) ;
if ( error )
goto V_225;
F_103 ( V_205 ) ;
F_103 ( V_206 ) ;
F_103 ( V_207 ) ;
* V_101 = V_2 ;
return 0 ;
V_219:
V_203 |= V_226 ;
V_217:
F_105 ( V_106 , V_203 ) ;
V_225:
if ( V_2 ) {
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
}
F_103 ( V_205 ) ;
F_103 ( V_206 ) ;
F_103 ( V_207 ) ;
return error ;
}
int
F_109 (
T_3 * V_230 ,
T_3 * V_231 ,
struct V_99 * V_232 )
{
T_18 * V_115 = V_230 -> V_7 ;
T_10 * V_106 ;
int error ;
T_16 V_200 ;
T_17 V_201 ;
int V_203 ;
int V_179 ;
int V_208 ;
F_110 ( V_230 , V_232 ) ;
ASSERT ( ! F_58 ( V_231 -> V_3 . V_123 ) ) ;
if ( F_46 ( V_115 ) )
return - V_104 ;
error = F_111 ( V_231 , 0 ) ;
if ( error )
goto V_233;
error = F_111 ( V_230 , 0 ) ;
if ( error )
goto V_233;
V_106 = F_91 ( V_115 , V_234 ) ;
V_203 = V_216 ;
V_208 = F_112 ( V_115 , V_232 -> V_211 ) ;
error = F_76 ( V_106 , & F_90 ( V_115 ) -> V_235 , V_208 , 0 ) ;
if ( error == - V_186 ) {
V_208 = 0 ;
error = F_76 ( V_106 , & F_90 ( V_115 ) -> V_235 , 0 , 0 ) ;
}
if ( error ) {
V_203 = 0 ;
goto V_236;
}
F_29 ( V_231 , V_230 , V_17 ) ;
F_64 ( V_106 , V_231 , V_17 ) ;
F_64 ( V_106 , V_230 , V_17 ) ;
if ( F_113 ( ( V_230 -> V_3 . V_4 & V_84 ) &&
( F_114 ( V_230 ) != F_114 ( V_231 ) ) ) ) {
error = - V_237 ;
goto V_236;
}
if ( ! V_208 ) {
error = F_96 ( V_106 , V_230 , V_232 ) ;
if ( error )
goto V_236;
}
F_94 ( & V_200 , & V_201 ) ;
if ( V_231 -> V_3 . V_125 == 0 ) {
error = F_115 ( V_106 , V_231 ) ;
if ( error )
goto V_238;
}
error = F_97 ( V_106 , V_230 , V_232 , V_231 -> V_60 ,
& V_201 , & V_200 , V_208 ) ;
if ( error )
goto V_238;
F_79 ( V_106 , V_230 , V_220 | V_195 ) ;
F_65 ( V_106 , V_230 , V_154 ) ;
error = F_83 ( V_106 , V_231 ) ;
if ( error )
goto V_238;
if ( V_115 -> V_222 & ( V_223 | V_224 ) ) {
F_100 ( V_106 ) ;
}
error = F_102 ( & V_106 , & V_200 , & V_179 ) ;
if ( error ) {
F_104 ( & V_200 ) ;
goto V_238;
}
return F_72 ( V_106 , V_216 ) ;
V_238:
V_203 |= V_226 ;
V_236:
F_105 ( V_106 , V_203 ) ;
V_233:
return error ;
}
int
F_116 (
struct V_199 * * V_178 ,
struct V_1 * V_2 ,
int V_239 ,
T_19 V_240 )
{
struct V_114 * V_115 = V_2 -> V_7 ;
struct V_199 * V_106 = * V_178 ;
struct V_199 * V_180 ;
T_16 V_200 ;
T_17 V_201 ;
T_20 V_241 ;
T_20 V_242 ;
T_21 V_243 ;
int V_179 ;
int error = 0 ;
int V_244 = 0 ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( ! F_117 ( & F_81 ( V_2 ) -> V_245 ) ||
F_23 ( V_2 , V_23 ) ) ;
ASSERT ( V_240 <= F_118 ( V_2 ) ) ;
ASSERT ( V_106 -> V_184 & V_185 ) ;
ASSERT ( V_2 -> V_49 != NULL ) ;
ASSERT ( V_2 -> V_49 -> V_246 == 0 ) ;
ASSERT ( ! F_119 ( V_115 , V_2 ) ) ;
F_120 ( V_2 , V_240 ) ;
V_241 = F_121 ( V_115 , ( V_247 ) V_240 ) ;
V_242 = F_121 ( V_115 , V_115 -> V_134 -> V_248 ) ;
if ( V_241 == V_242 )
return 0 ;
ASSERT ( V_241 < V_242 ) ;
V_243 = V_242 - V_241 + 1 ;
while ( ! V_244 ) {
F_94 ( & V_200 , & V_201 ) ;
error = F_122 ( V_106 , V_2 ,
V_241 , V_243 ,
F_123 ( V_239 ) ,
V_249 ,
& V_201 , & V_200 ,
& V_244 ) ;
if ( error )
goto V_221;
error = F_102 ( & V_106 , & V_200 , & V_179 ) ;
if ( V_179 )
F_64 ( V_106 , V_2 , 0 ) ;
if ( error )
goto V_221;
if ( V_179 ) {
F_65 ( V_106 , V_2 , V_154 ) ;
}
V_180 = F_71 ( V_106 ) ;
error = F_72 ( V_106 , 0 ) ;
V_106 = V_180 ;
F_64 ( V_106 , V_2 , 0 ) ;
if ( error )
goto V_31;
F_75 ( V_106 -> V_193 ) ;
error = F_76 ( V_106 , & F_90 ( V_115 ) -> V_250 , 0 , 0 ) ;
if ( error )
goto V_31;
}
F_65 ( V_106 , V_2 , V_154 ) ;
F_124 ( V_2 , V_240 ) ;
V_31:
* V_178 = V_106 ;
return error ;
V_221:
F_104 ( & V_200 ) ;
goto V_31;
}
int
F_125 (
T_3 * V_2 )
{
T_18 * V_115 = V_2 -> V_7 ;
int error ;
if ( ! F_63 ( V_2 -> V_3 . V_123 ) || ( V_2 -> V_3 . V_123 == 0 ) )
return 0 ;
if ( V_115 -> V_222 & V_251 )
return 0 ;
if ( ! F_46 ( V_115 ) ) {
int V_252 ;
V_252 = F_126 ( V_2 , V_253 ) ;
if ( V_252 ) {
F_127 ( V_2 , V_254 ) ;
if ( V_2 -> V_255 > 0 ) {
error = F_128 ( F_81 ( V_2 ) -> V_256 ) ;
if ( error )
return error ;
}
}
}
if ( V_2 -> V_3 . V_125 == 0 )
return 0 ;
if ( F_129 ( V_2 , false ) ) {
if ( F_130 ( V_2 , V_254 ) )
return 0 ;
error = F_131 ( V_115 , V_2 , true ) ;
if ( error && error != - V_257 )
return error ;
if ( V_2 -> V_255 )
F_132 ( V_2 , V_254 ) ;
}
return 0 ;
}
STATIC int
F_133 (
struct V_1 * V_2 )
{
struct V_114 * V_115 = V_2 -> V_7 ;
struct V_199 * V_106 ;
int error ;
V_106 = F_91 ( V_115 , V_258 ) ;
error = F_76 ( V_106 , & F_90 ( V_115 ) -> V_250 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_46 ( V_115 ) ) ;
F_105 ( V_106 , 0 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_64 ( V_106 , V_2 , 0 ) ;
V_2 -> V_3 . V_131 = 0 ;
F_65 ( V_106 , V_2 , V_154 ) ;
error = F_116 ( & V_106 , V_2 , V_259 , 0 ) ;
if ( error )
goto V_260;
ASSERT ( V_2 -> V_3 . V_132 == 0 ) ;
error = F_72 ( V_106 , V_216 ) ;
if ( error )
goto V_261;
F_18 ( V_2 , V_17 ) ;
return 0 ;
V_260:
F_105 ( V_106 , V_216 | V_226 ) ;
V_261:
F_18 ( V_2 , V_17 ) ;
return error ;
}
STATIC int
F_134 (
struct V_1 * V_2 )
{
T_16 V_200 ;
T_17 V_201 ;
int V_179 ;
struct V_114 * V_115 = V_2 -> V_7 ;
struct V_199 * V_106 ;
int error ;
V_106 = F_91 ( V_115 , V_258 ) ;
V_106 -> V_184 |= V_262 ;
error = F_76 ( V_106 , & F_90 ( V_115 ) -> V_263 ,
F_135 ( V_115 ) , 0 ) ;
if ( error ) {
if ( error == - V_186 ) {
F_136 ( V_115 ,
L_1
L_2 ) ;
} else {
ASSERT ( F_46 ( V_115 ) ) ;
}
F_105 ( V_106 , V_216 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_64 ( V_106 , V_2 , 0 ) ;
F_94 ( & V_200 , & V_201 ) ;
error = F_137 ( V_106 , V_2 , & V_200 ) ;
if ( error ) {
if ( ! F_46 ( V_115 ) ) {
F_138 ( V_115 , L_3 ,
V_264 , error ) ;
F_139 ( V_115 , V_265 ) ;
}
F_105 ( V_106 , V_216 | V_226 ) ;
F_18 ( V_2 , V_17 ) ;
return error ;
}
F_140 ( V_106 , V_2 , V_266 , - 1 ) ;
error = F_102 ( & V_106 , & V_200 , & V_179 ) ;
if ( error )
F_138 ( V_115 , L_4 ,
V_264 , error ) ;
error = F_72 ( V_106 , V_216 ) ;
if ( error )
F_138 ( V_115 , L_5 ,
V_264 , error ) ;
F_18 ( V_2 , V_17 ) ;
return 0 ;
}
void
F_141 (
T_3 * V_2 )
{
struct V_114 * V_115 ;
int error ;
int V_267 = 0 ;
if ( V_2 -> V_3 . V_123 == 0 ) {
ASSERT ( V_2 -> V_14 . V_174 == 0 ) ;
ASSERT ( V_2 -> V_14 . V_268 == 0 ) ;
return;
}
V_115 = V_2 -> V_7 ;
if ( V_115 -> V_222 & V_251 )
return;
if ( V_2 -> V_3 . V_125 != 0 ) {
if ( F_129 ( V_2 , true ) )
F_131 ( V_115 , V_2 , false ) ;
return;
}
if ( F_63 ( V_2 -> V_3 . V_123 ) &&
( V_2 -> V_3 . V_131 != 0 || F_118 ( V_2 ) != 0 ||
V_2 -> V_3 . V_132 > 0 || V_2 -> V_255 > 0 ) )
V_267 = 1 ;
error = F_111 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_142 ( V_2 -> V_3 . V_123 ) )
error = F_143 ( V_2 ) ;
else if ( V_267 )
error = F_133 ( V_2 ) ;
if ( error )
return;
if ( F_40 ( V_2 ) ) {
error = F_144 ( V_2 ) ;
if ( error )
return;
}
ASSERT ( ! V_2 -> V_19 ) ;
ASSERT ( V_2 -> V_3 . V_177 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_269 == 0 ) ;
error = F_134 ( V_2 ) ;
if ( error )
return;
F_145 ( V_2 ) ;
}
int
F_82 (
T_10 * V_106 ,
T_3 * V_2 )
{
T_18 * V_115 ;
T_22 * V_270 ;
T_8 * V_97 ;
T_15 * V_271 ;
T_15 * V_272 ;
T_23 V_273 ;
short V_274 ;
int V_275 ;
int error ;
ASSERT ( V_2 -> V_3 . V_125 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_123 != 0 ) ;
V_115 = V_106 -> V_116 ;
error = F_146 ( V_115 , V_106 , F_147 ( V_115 , V_2 -> V_60 ) , & V_271 ) ;
if ( error )
return error ;
V_270 = F_148 ( V_271 ) ;
V_273 = F_149 ( V_115 , V_2 -> V_60 ) ;
ASSERT ( V_273 != 0 ) ;
V_274 = V_273 % V_276 ;
ASSERT ( V_270 -> V_277 [ V_274 ] ) ;
ASSERT ( F_150 ( V_270 -> V_277 [ V_274 ] ) != V_273 ) ;
if ( V_270 -> V_277 [ V_274 ] != F_151 ( V_278 ) ) {
error = F_152 ( V_115 , V_106 , & V_2 -> V_279 , & V_97 , & V_272 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_97 -> V_280 == F_151 ( V_278 ) ) ;
V_97 -> V_280 = V_270 -> V_277 [ V_274 ] ;
V_275 = V_2 -> V_279 . V_281 +
F_153 ( T_8 , V_280 ) ;
F_154 ( V_115 , V_97 ) ;
F_155 ( V_106 , V_272 ) ;
F_156 ( V_106 , V_272 , V_275 ,
( V_275 + sizeof( T_23 ) - 1 ) ) ;
F_157 ( V_115 , V_272 ) ;
}
ASSERT ( V_273 != 0 ) ;
V_270 -> V_277 [ V_274 ] = F_151 ( V_273 ) ;
V_275 = F_153 ( T_22 , V_277 ) +
( sizeof( T_23 ) * V_274 ) ;
F_158 ( V_106 , V_271 , V_282 ) ;
F_156 ( V_106 , V_271 , V_275 ,
( V_275 + sizeof( T_23 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_115 (
T_10 * V_106 ,
T_3 * V_2 )
{
T_9 V_283 ;
T_18 * V_115 ;
T_22 * V_270 ;
T_8 * V_97 ;
T_15 * V_271 ;
T_15 * V_272 ;
T_24 V_284 ;
T_23 V_273 ;
T_23 V_285 ;
T_15 * V_286 ;
T_8 * V_287 = NULL ;
short V_274 ;
int V_275 , V_288 = 0 ;
int error ;
V_115 = V_106 -> V_116 ;
V_284 = F_147 ( V_115 , V_2 -> V_60 ) ;
error = F_146 ( V_115 , V_106 , V_284 , & V_271 ) ;
if ( error )
return error ;
V_270 = F_148 ( V_271 ) ;
V_273 = F_149 ( V_115 , V_2 -> V_60 ) ;
ASSERT ( V_273 != 0 ) ;
V_274 = V_273 % V_276 ;
ASSERT ( V_270 -> V_277 [ V_274 ] != F_151 ( V_278 ) ) ;
ASSERT ( V_270 -> V_277 [ V_274 ] ) ;
if ( F_150 ( V_270 -> V_277 [ V_274 ] ) == V_273 ) {
error = F_152 ( V_115 , V_106 , & V_2 -> V_279 , & V_97 , & V_272 ,
0 , 0 ) ;
if ( error ) {
F_159 ( V_115 , L_6 ,
V_264 , error ) ;
return error ;
}
V_285 = F_150 ( V_97 -> V_280 ) ;
ASSERT ( V_285 != 0 ) ;
if ( V_285 != V_278 ) {
V_97 -> V_280 = F_151 ( V_278 ) ;
V_275 = V_2 -> V_279 . V_281 +
F_153 ( T_8 , V_280 ) ;
F_154 ( V_115 , V_97 ) ;
F_155 ( V_106 , V_272 ) ;
F_156 ( V_106 , V_272 , V_275 ,
( V_275 + sizeof( T_23 ) - 1 ) ) ;
F_157 ( V_115 , V_272 ) ;
} else {
F_160 ( V_106 , V_272 ) ;
}
ASSERT ( V_285 != 0 ) ;
ASSERT ( V_285 != V_273 ) ;
V_270 -> V_277 [ V_274 ] = F_151 ( V_285 ) ;
V_275 = F_153 ( T_22 , V_277 ) +
( sizeof( T_23 ) * V_274 ) ;
F_158 ( V_106 , V_271 , V_282 ) ;
F_156 ( V_106 , V_271 , V_275 ,
( V_275 + sizeof( T_23 ) - 1 ) ) ;
} else {
V_285 = F_150 ( V_270 -> V_277 [ V_274 ] ) ;
V_286 = NULL ;
while ( V_285 != V_273 ) {
struct V_289 V_290 ;
if ( V_286 )
F_160 ( V_106 , V_286 ) ;
V_290 . V_291 = 0 ;
V_283 = F_161 ( V_115 , V_284 , V_285 ) ;
error = V_289 ( V_115 , V_106 , V_283 , & V_290 , 0 ) ;
if ( error ) {
F_159 ( V_115 ,
L_7 ,
V_264 , error ) ;
return error ;
}
error = F_152 ( V_115 , V_106 , & V_290 , & V_287 ,
& V_286 , 0 , 0 ) ;
if ( error ) {
F_159 ( V_115 ,
L_6 ,
V_264 , error ) ;
return error ;
}
V_288 = V_290 . V_281 ;
V_285 = F_150 ( V_287 -> V_280 ) ;
ASSERT ( V_285 != V_278 ) ;
ASSERT ( V_285 != 0 ) ;
}
error = F_152 ( V_115 , V_106 , & V_2 -> V_279 , & V_97 , & V_272 ,
0 , 0 ) ;
if ( error ) {
F_159 ( V_115 , L_8 ,
V_264 , error ) ;
return error ;
}
V_285 = F_150 ( V_97 -> V_280 ) ;
ASSERT ( V_285 != 0 ) ;
ASSERT ( V_285 != V_273 ) ;
if ( V_285 != V_278 ) {
V_97 -> V_280 = F_151 ( V_278 ) ;
V_275 = V_2 -> V_279 . V_281 +
F_153 ( T_8 , V_280 ) ;
F_154 ( V_115 , V_97 ) ;
F_155 ( V_106 , V_272 ) ;
F_156 ( V_106 , V_272 , V_275 ,
( V_275 + sizeof( T_23 ) - 1 ) ) ;
F_157 ( V_115 , V_272 ) ;
} else {
F_160 ( V_106 , V_272 ) ;
}
V_287 -> V_280 = F_151 ( V_285 ) ;
ASSERT ( V_285 != 0 ) ;
V_275 = V_288 + F_153 ( T_8 , V_280 ) ;
F_154 ( V_115 , V_287 ) ;
F_155 ( V_106 , V_286 ) ;
F_156 ( V_106 , V_286 , V_275 ,
( V_275 + sizeof( T_23 ) - 1 ) ) ;
F_157 ( V_115 , V_286 ) ;
}
return 0 ;
}
STATIC int
F_162 (
T_3 * V_292 ,
T_10 * V_106 ,
T_9 V_103 )
{
T_18 * V_115 = V_292 -> V_7 ;
int V_293 ;
int V_294 ;
int V_295 ;
int V_44 , V_45 ;
T_25 V_296 ;
T_15 * V_297 ;
T_3 * V_2 ;
T_26 * V_298 ;
T_4 * V_299 ;
struct V_300 * V_301 ;
V_301 = F_163 ( V_115 , F_147 ( V_115 , V_103 ) ) ;
V_293 = F_164 ( V_115 ) ;
V_294 = V_293 << V_115 -> V_8 . V_302 ;
V_295 = V_115 -> V_303 / V_293 ;
for ( V_45 = 0 ; V_45 < V_295 ; V_45 ++ , V_103 += V_294 ) {
V_296 = F_165 ( V_115 , F_147 ( V_115 , V_103 ) ,
F_166 ( V_115 , V_103 ) ) ;
V_297 = F_167 ( V_106 , V_115 -> V_304 , V_296 ,
V_115 -> V_305 * V_293 ,
V_306 ) ;
if ( ! V_297 )
return - V_307 ;
V_297 -> V_308 = & V_309 ;
V_299 = V_297 -> V_310 ;
while ( V_299 ) {
if ( V_299 -> V_311 == V_312 ) {
V_298 = ( T_26 * ) V_299 ;
ASSERT ( V_298 -> V_313 == 1 ) ;
V_299 -> V_314 = V_315 ;
F_168 ( V_115 -> V_316 ,
& V_298 -> V_317 ,
& V_298 -> V_318 . V_319 ) ;
F_132 ( V_298 -> V_320 , V_321 ) ;
}
V_299 = V_299 -> V_322 ;
}
for ( V_44 = 0 ; V_44 < V_294 ; V_44 ++ ) {
V_323:
F_169 () ;
V_2 = F_170 ( & V_301 -> V_324 ,
F_149 ( V_115 , ( V_103 + V_44 ) ) ) ;
if ( ! V_2 ) {
F_171 () ;
continue;
}
F_172 ( & V_2 -> V_325 ) ;
if ( V_2 -> V_60 != V_103 + V_44 ||
F_173 ( V_2 , V_321 ) ) {
F_174 ( & V_2 -> V_325 ) ;
F_171 () ;
continue;
}
F_174 ( & V_2 -> V_325 ) ;
if ( V_2 != V_292 &&
! F_12 ( V_2 , V_17 ) ) {
F_171 () ;
F_27 ( 1 ) ;
goto V_323;
}
F_171 () ;
F_175 ( V_2 ) ;
F_132 ( V_2 , V_321 ) ;
V_298 = V_2 -> V_49 ;
if ( ! V_298 || F_176 ( V_2 ) ) {
ASSERT ( V_2 != V_292 ) ;
F_177 ( V_2 ) ;
F_18 ( V_2 , V_17 ) ;
continue;
}
V_298 -> V_326 = V_298 -> V_327 ;
V_298 -> V_327 = 0 ;
V_298 -> V_313 = 1 ;
F_168 ( V_115 -> V_316 , & V_298 -> V_317 ,
& V_298 -> V_318 . V_319 ) ;
F_178 ( V_297 , V_315 ,
& V_298 -> V_318 ) ;
if ( V_2 != V_292 )
F_18 ( V_2 , V_17 ) ;
}
F_179 ( V_106 , V_297 ) ;
F_180 ( V_106 , V_297 ) ;
}
F_181 ( V_301 ) ;
return 0 ;
}
int
F_137 (
T_10 * V_106 ,
T_3 * V_2 ,
T_16 * V_328 )
{
int error ;
int V_329 ;
T_9 V_330 ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( V_2 -> V_3 . V_125 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_132 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_177 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_131 == 0 || ! F_63 ( V_2 -> V_3 . V_123 ) ) ;
ASSERT ( V_2 -> V_3 . V_133 == 0 ) ;
error = F_115 ( V_106 , V_2 ) ;
if ( error )
return error ;
error = F_182 ( V_106 , V_2 -> V_60 , V_328 , & V_329 , & V_330 ) ;
if ( error )
return error ;
V_2 -> V_3 . V_123 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_143 = 0 ;
V_2 -> V_3 . V_269 = 0 ;
V_2 -> V_3 . V_12 = V_172 ;
V_2 -> V_3 . V_18 = V_172 ;
V_2 -> V_3 . V_331 ++ ;
F_65 ( V_106 , V_2 , V_154 ) ;
if ( V_329 )
error = F_162 ( V_2 , V_106 , V_330 ) ;
return error ;
}
static void
F_183 (
struct V_1 * V_2 )
{
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
F_184 ( V_2 , V_21 ) ;
F_185 ( V_2 -> V_7 , V_2 -> V_49 -> V_332 , 0 ) ;
}
static void
F_186 (
struct V_1 * V_2 )
{
T_5 * V_61 = F_31 ( & V_2 -> V_62 , V_333 ) ;
F_32 ( V_64 , & V_2 -> V_62 , V_333 ) ;
F_183 ( V_2 ) ;
do {
F_187 ( V_61 , & V_64 . V_64 , V_65 ) ;
if ( F_188 ( V_2 ) )
F_35 () ;
} while ( F_188 ( V_2 ) );
F_37 ( V_61 , & V_64 . V_64 ) ;
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
T_3 * V_98 ,
struct V_99 * V_100 ,
T_3 * V_2 )
{
T_18 * V_115 = V_98 -> V_7 ;
T_10 * V_106 = NULL ;
int V_198 = F_58 ( V_2 -> V_3 . V_123 ) ;
int error = 0 ;
T_16 V_200 ;
T_17 V_201 ;
int V_203 ;
int V_179 ;
T_2 V_208 ;
F_191 ( V_98 , V_100 ) ;
if ( F_46 ( V_115 ) )
return - V_104 ;
error = F_111 ( V_98 , 0 ) ;
if ( error )
goto V_233;
error = F_111 ( V_2 , 0 ) ;
if ( error )
goto V_233;
if ( V_198 )
V_106 = F_91 ( V_115 , V_334 ) ;
else
V_106 = F_91 ( V_115 , V_335 ) ;
V_203 = V_216 ;
V_208 = F_192 ( V_115 ) ;
error = F_76 ( V_106 , & F_90 ( V_115 ) -> V_336 , V_208 , 0 ) ;
if ( error == - V_186 ) {
V_208 = 0 ;
error = F_76 ( V_106 , & F_90 ( V_115 ) -> V_336 , 0 , 0 ) ;
}
if ( error ) {
ASSERT ( error != - V_186 ) ;
V_203 = 0 ;
goto V_217;
}
F_29 ( V_98 , V_2 , V_17 ) ;
F_64 ( V_106 , V_98 , V_17 ) ;
F_64 ( V_106 , V_2 , V_17 ) ;
V_203 |= V_226 ;
if ( V_198 ) {
ASSERT ( V_2 -> V_3 . V_125 >= 2 ) ;
if ( V_2 -> V_3 . V_125 != 2 ) {
error = - V_337 ;
goto V_217;
}
if ( ! F_193 ( V_2 ) ) {
error = - V_337 ;
goto V_217;
}
error = F_78 ( V_106 , V_98 ) ;
if ( error )
goto V_217;
error = F_78 ( V_106 , V_2 ) ;
if ( error )
goto V_217;
} else {
F_65 ( V_106 , V_98 , V_154 ) ;
}
F_79 ( V_106 , V_98 , V_220 | V_195 ) ;
error = F_78 ( V_106 , V_2 ) ;
if ( error )
goto V_217;
F_94 ( & V_200 , & V_201 ) ;
error = F_194 ( V_106 , V_98 , V_100 , V_2 -> V_60 ,
& V_201 , & V_200 , V_208 ) ;
if ( error ) {
ASSERT ( error != - V_338 ) ;
goto V_221;
}
if ( V_115 -> V_222 & ( V_223 | V_224 ) )
F_100 ( V_106 ) ;
error = F_102 ( & V_106 , & V_200 , & V_179 ) ;
if ( error )
goto V_221;
error = F_72 ( V_106 , V_216 ) ;
if ( error )
goto V_233;
if ( V_198 && F_195 ( V_2 ) )
F_196 ( V_2 ) ;
return 0 ;
V_221:
F_104 ( & V_200 ) ;
V_217:
F_105 ( V_106 , V_203 ) ;
V_233:
return error ;
}
STATIC void
F_197 (
struct V_1 * V_339 ,
struct V_1 * V_340 ,
struct V_1 * V_58 ,
struct V_1 * V_341 ,
struct V_1 * V_342 ,
struct V_1 * * V_343 ,
int * V_344 )
{
int V_44 , V_45 ;
ASSERT ( * V_344 == V_345 ) ;
memset ( V_343 , 0 , * V_344 * sizeof( struct V_1 * ) ) ;
V_44 = 0 ;
V_343 [ V_44 ++ ] = V_339 ;
V_343 [ V_44 ++ ] = V_340 ;
V_343 [ V_44 ++ ] = V_58 ;
if ( V_341 )
V_343 [ V_44 ++ ] = V_341 ;
if ( V_342 )
V_343 [ V_44 ++ ] = V_342 ;
* V_344 = V_44 ;
for ( V_44 = 0 ; V_44 < * V_344 ; V_44 ++ ) {
for ( V_45 = 1 ; V_45 < * V_344 ; V_45 ++ ) {
if ( V_343 [ V_45 ] -> V_60 < V_343 [ V_45 - 1 ] -> V_60 ) {
struct V_1 * V_59 = V_343 [ V_45 ] ;
V_343 [ V_45 ] = V_343 [ V_45 - 1 ] ;
V_343 [ V_45 - 1 ] = V_59 ;
}
}
}
}
static int
F_198 (
struct V_199 * V_106 ,
struct V_346 * V_200 )
{
int V_179 = 0 ;
int error ;
if ( V_106 -> V_116 -> V_222 & ( V_223 | V_224 ) )
F_100 ( V_106 ) ;
error = F_102 ( & V_106 , V_200 , & V_179 ) ;
if ( error ) {
F_104 ( V_200 ) ;
F_105 ( V_106 , V_216 | V_226 ) ;
return error ;
}
return F_72 ( V_106 , V_216 ) ;
}
STATIC int
F_199 (
struct V_199 * V_106 ,
struct V_1 * V_339 ,
struct V_99 * V_347 ,
struct V_1 * V_58 ,
struct V_1 * V_340 ,
struct V_99 * V_348 ,
struct V_1 * V_341 ,
struct V_346 * V_200 ,
T_17 * V_201 ,
int V_349 )
{
int error = 0 ;
int V_350 = 0 ;
int V_351 = 0 ;
int V_352 = 0 ;
error = F_200 ( V_106 , V_339 , V_347 ,
V_341 -> V_60 ,
V_201 , V_200 , V_349 ) ;
if ( error )
goto V_219;
error = F_200 ( V_106 , V_340 , V_348 ,
V_58 -> V_60 ,
V_201 , V_200 , V_349 ) ;
if ( error )
goto V_219;
if ( V_339 != V_340 ) {
V_352 = V_220 | V_195 ;
if ( F_58 ( V_341 -> V_3 . V_123 ) ) {
error = F_200 ( V_106 , V_341 , & V_353 ,
V_339 -> V_60 , V_201 ,
V_200 , V_349 ) ;
if ( error )
goto V_219;
if ( ! F_58 ( V_58 -> V_3 . V_123 ) ) {
error = F_78 ( V_106 , V_340 ) ;
if ( error )
goto V_219;
error = F_83 ( V_106 , V_339 ) ;
if ( error )
goto V_219;
}
V_350 |= V_195 ;
V_351 |= V_220 | V_195 ;
}
if ( F_58 ( V_58 -> V_3 . V_123 ) ) {
error = F_200 ( V_106 , V_58 , & V_353 ,
V_340 -> V_60 , V_201 ,
V_200 , V_349 ) ;
if ( error )
goto V_219;
if ( ! F_58 ( V_341 -> V_3 . V_123 ) ) {
error = F_78 ( V_106 , V_339 ) ;
if ( error )
goto V_219;
error = F_83 ( V_106 , V_340 ) ;
if ( error )
goto V_219;
}
V_350 |= V_220 | V_195 ;
V_351 |= V_195 ;
}
}
if ( V_350 ) {
F_79 ( V_106 , V_58 , V_350 ) ;
F_65 ( V_106 , V_58 , V_154 ) ;
}
if ( V_351 ) {
F_79 ( V_106 , V_341 , V_351 ) ;
F_65 ( V_106 , V_341 , V_154 ) ;
}
if ( V_352 ) {
F_79 ( V_106 , V_340 , V_352 ) ;
F_65 ( V_106 , V_340 , V_154 ) ;
}
F_79 ( V_106 , V_339 , V_220 | V_195 ) ;
F_65 ( V_106 , V_339 , V_154 ) ;
return F_198 ( V_106 , V_200 ) ;
V_219:
F_104 ( V_200 ) ;
F_105 ( V_106 , V_216 | V_226 ) ;
return error ;
}
static int
F_201 (
struct V_1 * V_98 ,
struct V_1 * * V_342 )
{
struct V_1 * tmpfile ;
int error ;
error = F_108 ( V_98 , NULL , V_157 | V_354 , & tmpfile ) ;
if ( error )
return error ;
F_80 ( F_81 ( tmpfile ) ) ;
F_106 ( tmpfile ) ;
F_81 ( tmpfile ) -> V_196 |= V_197 ;
* V_342 = tmpfile ;
return 0 ;
}
int
F_202 (
struct V_1 * V_355 ,
struct V_99 * V_356 ,
struct V_1 * V_357 ,
struct V_1 * V_358 ,
struct V_99 * V_232 ,
struct V_1 * V_359 ,
unsigned int V_66 )
{
struct V_114 * V_115 = V_355 -> V_7 ;
struct V_199 * V_106 ;
struct V_346 V_200 ;
T_17 V_201 ;
struct V_1 * V_342 = NULL ;
struct V_1 * V_42 [ V_345 ] ;
int V_344 = V_345 ;
bool V_360 = ( V_355 != V_358 ) ;
bool V_361 = F_58 ( V_357 -> V_3 . V_123 ) ;
int V_203 = 0 ;
int V_349 ;
int error ;
F_203 ( V_355 , V_358 , V_356 , V_232 ) ;
if ( ( V_66 & V_362 ) && ! V_359 )
return - V_363 ;
if ( V_66 & V_364 ) {
ASSERT ( ! ( V_66 & ( V_365 | V_362 ) ) ) ;
error = F_201 ( V_358 , & V_342 ) ;
if ( error )
return error ;
V_356 -> type = V_366 ;
}
F_197 ( V_355 , V_358 , V_357 , V_359 , V_342 ,
V_42 , & V_344 ) ;
V_106 = F_91 ( V_115 , V_367 ) ;
V_349 = F_204 ( V_115 , V_232 -> V_211 ) ;
error = F_76 ( V_106 , & F_90 ( V_115 ) -> V_368 , V_349 , 0 ) ;
if ( error == - V_186 ) {
V_349 = 0 ;
error = F_76 ( V_106 , & F_90 ( V_115 ) -> V_368 , 0 , 0 ) ;
}
if ( error )
goto V_217;
V_203 = V_216 ;
error = F_205 ( V_42 ) ;
if ( error )
goto V_217;
F_26 ( V_42 , V_344 , V_17 ) ;
F_64 ( V_106 , V_355 , V_17 ) ;
if ( V_360 )
F_64 ( V_106 , V_358 , V_17 ) ;
F_64 ( V_106 , V_357 , V_17 ) ;
if ( V_359 )
F_64 ( V_106 , V_359 , V_17 ) ;
if ( V_342 )
F_64 ( V_106 , V_342 , V_17 ) ;
if ( F_113 ( ( V_358 -> V_3 . V_4 & V_84 ) &&
( F_114 ( V_358 ) != F_114 ( V_357 ) ) ) ) {
error = - V_237 ;
goto V_217;
}
F_94 ( & V_200 , & V_201 ) ;
if ( V_66 & V_362 )
return F_199 ( V_106 , V_355 , V_356 , V_357 ,
V_358 , V_232 , V_359 ,
& V_200 , & V_201 , V_349 ) ;
if ( V_359 == NULL ) {
if ( ! V_349 ) {
error = F_96 ( V_106 , V_358 , V_232 ) ;
if ( error )
goto V_217;
}
error = F_97 ( V_106 , V_358 , V_232 ,
V_357 -> V_60 , & V_201 ,
& V_200 , V_349 ) ;
if ( error == - V_186 )
goto V_221;
if ( error )
goto V_219;
F_79 ( V_106 , V_358 ,
V_220 | V_195 ) ;
if ( V_360 && V_361 ) {
error = F_83 ( V_106 , V_358 ) ;
if ( error )
goto V_219;
}
} else {
if ( F_58 ( V_359 -> V_3 . V_123 ) ) {
if ( ! ( F_193 ( V_359 ) ) ||
( V_359 -> V_3 . V_125 > 2 ) ) {
error = - V_369 ;
goto V_217;
}
}
error = F_200 ( V_106 , V_358 , V_232 ,
V_357 -> V_60 ,
& V_201 , & V_200 , V_349 ) ;
if ( error )
goto V_219;
F_79 ( V_106 , V_358 ,
V_220 | V_195 ) ;
error = F_78 ( V_106 , V_359 ) ;
if ( error )
goto V_219;
if ( V_361 ) {
error = F_78 ( V_106 , V_359 ) ;
if ( error )
goto V_219;
}
}
if ( V_360 && V_361 ) {
error = F_200 ( V_106 , V_357 , & V_353 ,
V_358 -> V_60 ,
& V_201 , & V_200 , V_349 ) ;
ASSERT ( error != - V_369 ) ;
if ( error )
goto V_219;
}
F_79 ( V_106 , V_357 , V_195 ) ;
F_65 ( V_106 , V_357 , V_154 ) ;
if ( V_361 && ( V_360 || V_359 != NULL ) ) {
error = F_78 ( V_106 , V_355 ) ;
if ( error )
goto V_219;
}
if ( V_342 ) {
error = F_200 ( V_106 , V_355 , V_356 , V_342 -> V_60 ,
& V_201 , & V_200 , V_349 ) ;
} else
error = F_194 ( V_106 , V_355 , V_356 , V_357 -> V_60 ,
& V_201 , & V_200 , V_349 ) ;
if ( error )
goto V_219;
if ( V_342 ) {
ASSERT ( F_81 ( V_342 ) -> V_370 == 0 && V_342 -> V_3 . V_125 == 0 ) ;
error = F_83 ( V_106 , V_342 ) ;
if ( error )
goto V_219;
error = F_115 ( V_106 , V_342 ) ;
if ( error )
goto V_219;
F_65 ( V_106 , V_342 , V_154 ) ;
F_81 ( V_342 ) -> V_196 &= ~ V_197 ;
}
F_79 ( V_106 , V_355 , V_220 | V_195 ) ;
F_65 ( V_106 , V_355 , V_154 ) ;
if ( V_360 )
F_65 ( V_106 , V_358 , V_154 ) ;
error = F_198 ( V_106 , & V_200 ) ;
if ( V_342 )
F_107 ( V_342 ) ;
return error ;
V_219:
V_203 |= V_226 ;
V_221:
F_104 ( & V_200 ) ;
V_217:
F_105 ( V_106 , V_203 ) ;
if ( V_342 )
F_107 ( V_342 ) ;
return error ;
}
STATIC int
F_206 (
T_3 * V_2 ,
T_15 * V_297 )
{
T_18 * V_115 = V_2 -> V_7 ;
struct V_300 * V_301 ;
unsigned long V_371 , V_372 ;
unsigned long V_294 ;
int V_373 ;
T_3 * * V_374 ;
T_3 * V_375 ;
int V_376 ;
int V_377 = 0 ;
int V_378 ;
int V_44 ;
V_301 = F_163 ( V_115 , F_147 ( V_115 , V_2 -> V_60 ) ) ;
V_294 = V_115 -> V_379 >> V_115 -> V_8 . V_380 ;
V_373 = V_294 * sizeof( T_3 * ) ;
V_374 = F_207 ( V_373 , V_381 | V_382 ) ;
if ( ! V_374 )
goto V_383;
V_372 = ~ ( ( ( V_115 -> V_379 >> V_115 -> V_8 . V_380 ) ) - 1 ) ;
V_371 = F_149 ( V_115 , V_2 -> V_60 ) & V_372 ;
F_169 () ;
V_376 = F_208 ( & V_301 -> V_324 , ( void * * ) V_374 ,
V_371 , V_294 ) ;
if ( V_376 == 0 )
goto V_384;
for ( V_44 = 0 ; V_44 < V_376 ; V_44 ++ ) {
V_375 = V_374 [ V_44 ] ;
if ( V_375 == V_2 )
continue;
F_172 ( & V_2 -> V_325 ) ;
if ( ! V_2 -> V_60 ||
( F_149 ( V_115 , V_375 -> V_60 ) & V_372 ) != V_371 ) {
F_174 ( & V_2 -> V_325 ) ;
continue;
}
F_174 ( & V_2 -> V_325 ) ;
if ( F_176 ( V_375 ) && F_188 ( V_375 ) == 0 )
continue;
if ( ! F_12 ( V_375 , V_11 ) )
continue;
if ( ! F_36 ( V_375 ) ) {
F_18 ( V_375 , V_11 ) ;
continue;
}
if ( F_188 ( V_375 ) ) {
F_177 ( V_375 ) ;
F_18 ( V_375 , V_11 ) ;
continue;
}
if ( ! F_176 ( V_375 ) ) {
int error ;
error = F_209 ( V_375 , V_297 ) ;
if ( error ) {
F_18 ( V_375 , V_11 ) ;
goto V_385;
}
V_377 ++ ;
} else {
F_177 ( V_375 ) ;
}
F_18 ( V_375 , V_11 ) ;
}
if ( V_377 ) {
F_210 ( V_386 ) ;
F_211 ( V_387 , V_377 ) ;
}
V_384:
F_171 () ;
F_49 ( V_374 ) ;
V_383:
F_181 ( V_301 ) ;
return 0 ;
V_385:
F_171 () ;
V_378 = ( V_297 -> V_388 & V_389 ) ;
if ( V_378 )
F_73 ( V_297 ) ;
F_139 ( V_115 , V_390 ) ;
if ( ! V_378 ) {
if ( V_297 -> V_391 ) {
F_212 ( V_297 ) ;
F_213 ( V_297 ) ;
F_214 ( V_297 , - V_104 ) ;
F_215 ( V_297 ) ;
} else {
F_213 ( V_297 ) ;
F_73 ( V_297 ) ;
}
}
F_216 ( V_375 , false ) ;
F_49 ( V_374 ) ;
F_181 ( V_301 ) ;
return - V_392 ;
}
int
F_217 (
struct V_1 * V_2 ,
struct V_393 * * V_394 )
{
struct V_114 * V_115 = V_2 -> V_7 ;
struct V_393 * V_297 ;
struct V_395 * V_97 ;
int error ;
F_210 ( V_396 ) ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_34 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_132 > F_218 ( V_2 , V_259 ) ) ;
* V_394 = NULL ;
F_189 ( V_2 ) ;
if ( F_130 ( V_2 , V_321 ) ) {
F_177 ( V_2 ) ;
return 0 ;
}
if ( F_46 ( V_115 ) ) {
error = - V_104 ;
goto V_397;
}
error = F_152 ( V_115 , NULL , & V_2 -> V_279 , & V_97 , & V_297 , V_398 ,
0 ) ;
if ( error || ! V_297 ) {
F_177 ( V_2 ) ;
return error ;
}
error = F_209 ( V_2 , V_297 ) ;
if ( error )
goto V_399;
if ( F_219 ( V_297 ) )
F_220 ( V_115 , 0 ) ;
error = F_206 ( V_2 , V_297 ) ;
if ( error )
goto V_385;
* V_394 = V_297 ;
return 0 ;
V_399:
F_73 ( V_297 ) ;
F_139 ( V_115 , V_390 ) ;
V_385:
error = - V_392 ;
V_397:
F_216 ( V_2 , false ) ;
return error ;
}
STATIC int
F_209 (
struct V_1 * V_2 ,
struct V_393 * V_297 )
{
struct V_400 * V_298 = V_2 -> V_49 ;
struct V_395 * V_97 ;
struct V_114 * V_115 = V_2 -> V_7 ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_34 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_132 > F_218 ( V_2 , V_259 ) ) ;
ASSERT ( V_298 != NULL && V_298 -> V_327 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_122 > 1 ) ;
V_97 = ( T_8 * ) F_221 ( V_297 , V_2 -> V_279 . V_281 ) ;
if ( F_222 ( V_97 -> V_401 != F_223 ( V_402 ) ,
V_115 , V_403 , V_404 ) ) {
F_224 ( V_115 , V_405 ,
L_9 ,
V_264 , V_2 -> V_60 , F_42 ( V_97 -> V_401 ) , V_97 ) ;
goto V_399;
}
if ( F_222 ( V_2 -> V_3 . V_401 != V_402 ,
V_115 , V_406 , V_407 ) ) {
F_224 ( V_115 , V_405 ,
L_10 ,
V_264 , V_2 -> V_60 , V_2 , V_2 -> V_3 . V_401 ) ;
goto V_399;
}
if ( F_63 ( V_2 -> V_3 . V_123 ) ) {
if ( F_222 (
( V_2 -> V_3 . V_12 != V_172 ) &&
( V_2 -> V_3 . V_12 != V_13 ) ,
V_115 , V_408 , V_409 ) ) {
F_224 ( V_115 , V_405 ,
L_11 ,
V_264 , V_2 -> V_60 , V_2 ) ;
goto V_399;
}
} else if ( F_58 ( V_2 -> V_3 . V_123 ) ) {
if ( F_222 (
( V_2 -> V_3 . V_12 != V_172 ) &&
( V_2 -> V_3 . V_12 != V_13 ) &&
( V_2 -> V_3 . V_12 != V_410 ) ,
V_115 , V_411 , V_412 ) ) {
F_224 ( V_115 , V_405 ,
L_12 ,
V_264 , V_2 -> V_60 , V_2 ) ;
goto V_399;
}
}
if ( F_222 ( V_2 -> V_3 . V_132 + V_2 -> V_3 . V_177 >
V_2 -> V_3 . V_133 , V_115 , V_413 ,
V_414 ) ) {
F_224 ( V_115 , V_405 ,
L_13
L_14 ,
V_264 , V_2 -> V_60 ,
V_2 -> V_3 . V_132 + V_2 -> V_3 . V_177 ,
V_2 -> V_3 . V_133 , V_2 ) ;
goto V_399;
}
if ( F_222 ( V_2 -> V_3 . V_269 > V_115 -> V_8 . V_415 ,
V_115 , V_416 , V_417 ) ) {
F_224 ( V_115 , V_405 ,
L_15 ,
V_264 , V_2 -> V_60 , V_2 -> V_3 . V_269 , V_2 ) ;
goto V_399;
}
if ( V_2 -> V_3 . V_122 < 3 )
V_2 -> V_3 . V_418 ++ ;
F_225 ( V_97 , & V_2 -> V_3 ) ;
if ( V_2 -> V_3 . V_418 == V_419 )
V_2 -> V_3 . V_418 = 0 ;
F_226 ( V_2 , V_97 , V_298 , V_259 ) ;
if ( F_40 ( V_2 ) )
F_226 ( V_2 , V_97 , V_298 , V_420 ) ;
F_157 ( V_115 , V_297 ) ;
V_298 -> V_326 = V_298 -> V_327 ;
V_298 -> V_327 = 0 ;
V_298 -> V_313 = 1 ;
F_168 ( V_115 -> V_316 , & V_298 -> V_317 ,
& V_298 -> V_318 . V_319 ) ;
F_178 ( V_297 , V_421 , & V_298 -> V_318 ) ;
if ( V_2 -> V_3 . V_122 == 3 )
V_97 -> V_150 = F_227 ( V_298 -> V_318 . V_319 ) ;
F_154 ( V_115 , V_97 ) ;
ASSERT ( V_297 -> V_310 != NULL ) ;
ASSERT ( V_297 -> V_391 != NULL ) ;
return 0 ;
V_399:
return - V_392 ;
}
