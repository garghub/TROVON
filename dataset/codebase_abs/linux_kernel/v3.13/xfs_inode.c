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
T_3 * V_2 )
{
T_2 V_10 ;
if ( ( V_2 -> V_3 . V_11 == V_12 ) &&
( ( V_2 -> V_13 . V_14 & V_15 ) == 0 ) ) {
V_10 = V_16 ;
} else {
V_10 = V_17 ;
}
F_4 ( V_2 , V_10 ) ;
return V_10 ;
}
void
F_5 (
T_3 * V_2 ,
unsigned int V_10 )
{
F_6 ( V_2 , V_10 ) ;
}
void
F_4 (
T_3 * V_2 ,
T_2 V_18 )
{
F_7 ( V_2 , V_18 , V_19 ) ;
ASSERT ( ( V_18 & ( V_20 | V_21 ) ) !=
( V_20 | V_21 ) ) ;
ASSERT ( ( V_18 & ( V_17 | V_16 ) ) !=
( V_17 | V_16 ) ) ;
ASSERT ( ( V_18 & ~ ( V_22 | V_23 ) ) == 0 ) ;
if ( V_18 & V_21 )
F_8 ( & V_2 -> V_24 , F_9 ( V_18 ) ) ;
else if ( V_18 & V_20 )
F_10 ( & V_2 -> V_24 , F_9 ( V_18 ) ) ;
if ( V_18 & V_16 )
F_8 ( & V_2 -> V_25 , F_11 ( V_18 ) ) ;
else if ( V_18 & V_17 )
F_10 ( & V_2 -> V_25 , F_11 ( V_18 ) ) ;
}
int
F_12 (
T_3 * V_2 ,
T_2 V_18 )
{
F_13 ( V_2 , V_18 , V_19 ) ;
ASSERT ( ( V_18 & ( V_20 | V_21 ) ) !=
( V_20 | V_21 ) ) ;
ASSERT ( ( V_18 & ( V_17 | V_16 ) ) !=
( V_17 | V_16 ) ) ;
ASSERT ( ( V_18 & ~ ( V_22 | V_23 ) ) == 0 ) ;
if ( V_18 & V_21 ) {
if ( ! F_14 ( & V_2 -> V_24 ) )
goto V_26;
} else if ( V_18 & V_20 ) {
if ( ! F_15 ( & V_2 -> V_24 ) )
goto V_26;
}
if ( V_18 & V_16 ) {
if ( ! F_14 ( & V_2 -> V_25 ) )
goto V_27;
} else if ( V_18 & V_17 ) {
if ( ! F_15 ( & V_2 -> V_25 ) )
goto V_27;
}
return 1 ;
V_27:
if ( V_18 & V_21 )
F_16 ( & V_2 -> V_24 ) ;
else if ( V_18 & V_20 )
F_17 ( & V_2 -> V_24 ) ;
V_26:
return 0 ;
}
void
F_6 (
T_3 * V_2 ,
T_2 V_18 )
{
ASSERT ( ( V_18 & ( V_20 | V_21 ) ) !=
( V_20 | V_21 ) ) ;
ASSERT ( ( V_18 & ( V_17 | V_16 ) ) !=
( V_17 | V_16 ) ) ;
ASSERT ( ( V_18 & ~ ( V_22 | V_23 ) ) == 0 ) ;
ASSERT ( V_18 != 0 ) ;
if ( V_18 & V_21 )
F_16 ( & V_2 -> V_24 ) ;
else if ( V_18 & V_20 )
F_17 ( & V_2 -> V_24 ) ;
if ( V_18 & V_16 )
F_16 ( & V_2 -> V_25 ) ;
else if ( V_18 & V_17 )
F_17 ( & V_2 -> V_25 ) ;
F_18 ( V_2 , V_18 , V_19 ) ;
}
void
F_19 (
T_3 * V_2 ,
T_2 V_18 )
{
ASSERT ( V_18 & ( V_21 | V_16 ) ) ;
ASSERT ( ( V_18 & ~ ( V_21 | V_16 ) ) == 0 ) ;
if ( V_18 & V_16 )
F_20 ( & V_2 -> V_25 ) ;
if ( V_18 & V_21 )
F_20 ( & V_2 -> V_24 ) ;
F_21 ( V_2 , V_18 , V_19 ) ;
}
int
F_22 (
T_3 * V_2 ,
T_2 V_18 )
{
if ( V_18 & ( V_16 | V_17 ) ) {
if ( ! ( V_18 & V_17 ) )
return ! ! V_2 -> V_25 . V_28 ;
return F_23 ( & V_2 -> V_25 . V_29 ) ;
}
if ( V_18 & ( V_21 | V_20 ) ) {
if ( ! ( V_18 & V_20 ) )
return ! ! V_2 -> V_24 . V_28 ;
return F_23 ( & V_2 -> V_24 . V_29 ) ;
}
ASSERT ( 0 ) ;
return 0 ;
}
static inline int
F_24 ( int V_10 , int V_30 )
{
if ( V_10 & ( V_20 | V_21 ) )
V_10 |= ( V_30 + V_31 ) << V_32 ;
if ( V_10 & ( V_17 | V_16 ) )
V_10 |= ( V_30 + V_31 ) << V_33 ;
return V_10 ;
}
void
F_25 (
T_3 * * V_34 ,
int V_35 ,
T_2 V_10 )
{
int V_36 = 0 , V_37 , V_38 , V_39 ;
T_4 * V_40 ;
ASSERT ( V_34 && ( V_35 >= 2 ) ) ;
V_39 = 0 ;
V_37 = 0 ;
V_41:
for (; V_37 < V_35 ; V_37 ++ ) {
ASSERT ( V_34 [ V_37 ] ) ;
if ( V_37 && ( V_34 [ V_37 ] == V_34 [ V_37 - 1 ] ) )
continue;
if ( ! V_39 ) {
for ( V_38 = ( V_37 - 1 ) ; V_38 >= 0 && ! V_39 ; V_38 -- ) {
V_40 = ( T_4 * ) V_34 [ V_38 ] -> V_42 ;
if ( V_40 && ( V_40 -> V_43 & V_44 ) ) {
V_39 ++ ;
}
}
}
if ( V_39 ) {
ASSERT ( V_37 != 0 ) ;
if ( ! F_12 ( V_34 [ V_37 ] , F_24 ( V_10 , V_37 ) ) ) {
V_36 ++ ;
for( V_38 = V_37 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( ( V_38 != ( V_37 - 1 ) ) && V_34 [ V_38 ] ==
V_34 [ V_38 + 1 ] )
continue;
F_6 ( V_34 [ V_38 ] , V_10 ) ;
}
if ( ( V_36 % 5 ) == 0 ) {
F_26 ( 1 ) ;
#ifdef F_27
V_45 ++ ;
#endif
}
V_37 = 0 ;
V_39 = 0 ;
goto V_41;
}
} else {
F_4 ( V_34 [ V_37 ] , F_24 ( V_10 , V_37 ) ) ;
}
}
#ifdef F_27
if ( V_36 ) {
if ( V_36 < 5 ) V_46 ++ ;
else if ( V_36 < 100 ) V_47 ++ ;
else V_48 ++ ;
} else {
V_49 ++ ;
}
#endif
}
void
F_28 (
T_3 * V_50 ,
T_3 * V_51 ,
T_2 V_10 )
{
T_3 * V_52 ;
int V_36 = 0 ;
T_4 * V_40 ;
if ( V_10 & ( V_20 | V_21 ) )
ASSERT ( ( V_10 & ( V_17 | V_16 ) ) == 0 ) ;
ASSERT ( V_50 -> V_53 != V_51 -> V_53 ) ;
if ( V_50 -> V_53 > V_51 -> V_53 ) {
V_52 = V_50 ;
V_50 = V_51 ;
V_51 = V_52 ;
}
V_41:
F_4 ( V_50 , F_24 ( V_10 , 0 ) ) ;
V_40 = ( T_4 * ) V_50 -> V_42 ;
if ( V_40 && ( V_40 -> V_43 & V_44 ) ) {
if ( ! F_12 ( V_51 , F_24 ( V_10 , 1 ) ) ) {
F_6 ( V_50 , V_10 ) ;
if ( ( ++ V_36 % 5 ) == 0 )
F_26 ( 1 ) ;
goto V_41;
}
} else {
F_4 ( V_51 , F_24 ( V_10 , 1 ) ) ;
}
}
void
F_29 (
struct V_1 * V_2 )
{
T_5 * V_54 = F_30 ( & V_2 -> V_55 , V_56 ) ;
F_31 ( V_57 , & V_2 -> V_55 , V_56 ) ;
do {
F_32 ( V_54 , & V_57 . V_57 , V_58 ) ;
if ( F_33 ( V_2 ) )
F_34 () ;
} while ( ! F_35 ( V_2 ) );
F_36 ( V_54 , & V_57 . V_57 ) ;
}
STATIC T_2
F_37 (
T_6 V_4 )
{
T_2 V_59 = 0 ;
if ( V_4 & V_60 ) {
if ( V_4 & V_61 )
V_59 |= V_62 ;
if ( V_4 & V_63 )
V_59 |= V_64 ;
if ( V_4 & V_65 )
V_59 |= V_66 ;
if ( V_4 & V_67 )
V_59 |= V_68 ;
if ( V_4 & V_69 )
V_59 |= V_70 ;
if ( V_4 & V_71 )
V_59 |= V_72 ;
if ( V_4 & V_73 )
V_59 |= V_74 ;
if ( V_4 & V_75 )
V_59 |= V_76 ;
if ( V_4 & V_77 )
V_59 |= V_78 ;
if ( V_4 & V_79 )
V_59 |= V_80 ;
if ( V_4 & V_5 )
V_59 |= V_81 ;
if ( V_4 & V_82 )
V_59 |= V_83 ;
if ( V_4 & V_84 )
V_59 |= V_85 ;
if ( V_4 & V_86 )
V_59 |= V_87 ;
}
return V_59 ;
}
T_2
F_38 (
T_3 * V_2 )
{
T_7 * V_88 = & V_2 -> V_3 ;
return F_37 ( V_88 -> V_4 ) |
( F_39 ( V_2 ) ? V_89 : 0 ) ;
}
T_2
F_40 (
T_8 * V_90 )
{
return F_37 ( F_41 ( V_90 -> V_4 ) ) |
( F_42 ( V_90 ) ? V_89 : 0 ) ;
}
int
F_43 (
T_3 * V_91 ,
struct V_92 * V_93 ,
T_3 * * V_94 ,
struct V_92 * V_95 )
{
T_9 V_96 ;
int error ;
T_2 V_10 ;
F_44 ( V_91 , V_93 ) ;
if ( F_45 ( V_91 -> V_7 ) )
return F_46 ( V_97 ) ;
V_10 = F_3 ( V_91 ) ;
error = F_47 ( NULL , V_91 , V_93 , & V_96 , V_95 ) ;
F_5 ( V_91 , V_10 ) ;
if ( error )
goto V_26;
error = F_48 ( V_91 -> V_7 , NULL , V_96 , 0 , 0 , V_94 ) ;
if ( error )
goto V_98;
return 0 ;
V_98:
if ( V_95 )
F_49 ( V_95 -> V_93 ) ;
V_26:
* V_94 = NULL ;
return error ;
}
int
F_50 (
T_10 * V_99 ,
T_3 * V_100 ,
T_11 V_101 ,
T_12 V_102 ,
T_13 V_103 ,
T_14 V_104 ,
int V_105 ,
T_15 * * V_106 ,
T_3 * * V_94 )
{
struct V_107 * V_108 = V_99 -> V_109 ;
T_9 V_110 ;
T_3 * V_2 ;
T_2 V_59 ;
int error ;
T_16 V_111 ;
int V_112 = 0 ;
error = F_51 ( V_99 , V_100 ? V_100 -> V_53 : 0 , V_101 , V_105 ,
V_106 , & V_110 ) ;
if ( error )
return error ;
if ( * V_106 || V_110 == V_113 ) {
* V_94 = NULL ;
return 0 ;
}
ASSERT ( * V_106 == NULL ) ;
error = F_48 ( V_108 , V_99 , V_110 , V_114 ,
V_16 , & V_2 ) ;
if ( error )
return error ;
ASSERT ( V_2 != NULL ) ;
V_2 -> V_3 . V_115 = V_101 ;
V_2 -> V_3 . V_116 = 0 ;
V_2 -> V_3 . V_117 = V_102 ;
ASSERT ( V_2 -> V_3 . V_117 == V_102 ) ;
V_2 -> V_3 . V_118 = F_52 ( F_53 () ) ;
V_2 -> V_3 . V_119 = F_54 ( F_55 () ) ;
F_56 ( V_2 , V_104 ) ;
memset ( & ( V_2 -> V_3 . V_120 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_120 ) ) ;
if ( F_57 ( & V_108 -> V_8 ) &&
V_2 -> V_3 . V_121 == 1 ) {
V_2 -> V_3 . V_121 = 2 ;
}
if ( ( V_104 != 0 ) && ( V_2 -> V_3 . V_121 == 1 ) )
F_58 ( V_99 , V_2 ) ;
if ( V_100 && F_59 ( V_100 ) ) {
V_2 -> V_3 . V_119 = V_100 -> V_3 . V_119 ;
if ( ( V_100 -> V_3 . V_115 & V_122 ) && F_60 ( V_101 ) ) {
V_2 -> V_3 . V_115 |= V_122 ;
}
}
if ( ( V_123 ) &&
( V_2 -> V_3 . V_115 & V_122 ) &&
( ! F_61 ( F_62 ( V_2 -> V_3 . V_119 ) ) ) ) {
V_2 -> V_3 . V_115 &= ~ V_122 ;
}
V_2 -> V_3 . V_124 = 0 ;
V_2 -> V_3 . V_125 = 0 ;
ASSERT ( V_2 -> V_3 . V_126 == 0 ) ;
F_63 ( & V_111 ) ;
V_2 -> V_3 . V_127 . V_128 = ( V_129 ) V_111 . V_130 ;
V_2 -> V_3 . V_127 . V_131 = ( V_129 ) V_111 . V_132 ;
V_2 -> V_3 . V_133 = V_2 -> V_3 . V_127 ;
V_2 -> V_3 . V_134 = V_2 -> V_3 . V_127 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_135 = 0 ;
V_2 -> V_3 . V_136 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( V_2 -> V_3 . V_121 == 3 ) {
ASSERT ( V_2 -> V_3 . V_137 == V_110 ) ;
ASSERT ( F_64 ( & V_2 -> V_3 . V_138 , & V_108 -> V_8 . V_139 ) ) ;
V_2 -> V_3 . V_140 = 0 ;
V_2 -> V_3 . V_141 = 1 ;
V_2 -> V_3 . V_142 = 0 ;
V_2 -> V_3 . V_143 = 0 ;
memset ( & ( V_2 -> V_3 . V_144 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_144 ) ) ;
V_2 -> V_3 . V_145 = V_2 -> V_3 . V_127 ;
}
V_59 = V_146 ;
switch ( V_101 & V_147 ) {
case V_148 :
case V_149 :
case V_150 :
case V_151 :
V_2 -> V_3 . V_11 = V_152 ;
V_2 -> V_13 . V_153 . V_154 = V_103 ;
V_2 -> V_13 . V_14 = 0 ;
V_59 |= V_155 ;
break;
case V_156 :
if ( V_100 && F_65 ( V_100 ) )
V_112 = 1 ;
case V_157 :
if ( V_100 && ( V_100 -> V_3 . V_4 & V_60 ) ) {
T_2 V_4 = 0 ;
if ( F_60 ( V_101 ) ) {
if ( V_100 -> V_3 . V_4 & V_75 )
V_4 |= V_75 ;
if ( V_100 -> V_3 . V_4 & V_82 ) {
V_4 |= V_82 ;
V_2 -> V_3 . V_6 = V_100 -> V_3 . V_6 ;
}
} else if ( F_66 ( V_101 ) ) {
if ( V_100 -> V_3 . V_4 & V_75 )
V_4 |= V_61 ;
if ( V_100 -> V_3 . V_4 & V_82 ) {
V_4 |= V_5 ;
V_2 -> V_3 . V_6 = V_100 -> V_3 . V_6 ;
}
}
if ( ( V_100 -> V_3 . V_4 & V_71 ) &&
V_158 )
V_4 |= V_71 ;
if ( ( V_100 -> V_3 . V_4 & V_73 ) &&
V_159 )
V_4 |= V_73 ;
if ( ( V_100 -> V_3 . V_4 & V_69 ) &&
V_160 )
V_4 |= V_69 ;
if ( ( V_100 -> V_3 . V_4 & V_79 ) &&
V_161 )
V_4 |= V_79 ;
if ( V_100 -> V_3 . V_4 & V_77 )
V_4 |= V_77 ;
if ( ( V_100 -> V_3 . V_4 & V_84 ) &&
V_162 )
V_4 |= V_84 ;
if ( V_100 -> V_3 . V_4 & V_86 )
V_4 |= V_86 ;
V_2 -> V_3 . V_4 |= V_4 ;
}
case V_163 :
V_2 -> V_3 . V_11 = V_164 ;
V_2 -> V_13 . V_14 = V_15 ;
V_2 -> V_13 . V_165 = V_2 -> V_13 . V_166 = 0 ;
V_2 -> V_13 . V_167 . V_168 = NULL ;
break;
default:
ASSERT ( 0 ) ;
}
V_2 -> V_3 . V_169 = V_164 ;
V_2 -> V_3 . V_170 = 0 ;
F_67 ( V_99 , V_2 , V_16 ) ;
F_68 ( V_99 , V_2 , V_59 ) ;
F_69 ( V_2 ) ;
if ( V_112 ) {
error = F_70 ( V_100 , V_2 ) ;
if ( error < 0 )
return - error ;
if ( ! error )
F_71 ( V_2 , V_171 ) ;
}
* V_94 = V_2 ;
return 0 ;
}
int
F_72 (
T_10 * * V_172 ,
T_3 * V_91 ,
T_11 V_101 ,
T_12 V_102 ,
T_13 V_103 ,
T_14 V_104 ,
int V_105 ,
T_3 * * V_94 ,
int * V_173 )
{
T_10 * V_99 ;
T_10 * V_174 ;
T_3 * V_2 ;
T_15 * V_106 = NULL ;
int V_175 ;
void * V_176 ;
T_2 V_177 ;
V_99 = * V_172 ;
ASSERT ( V_99 -> V_178 & V_179 ) ;
V_175 = F_50 ( V_99 , V_91 , V_101 , V_102 , V_103 , V_104 , V_105 ,
& V_106 , & V_2 ) ;
if ( V_175 ) {
* V_94 = NULL ;
return V_175 ;
}
if ( ! V_106 && ! V_2 ) {
* V_94 = NULL ;
return F_46 ( V_180 ) ;
}
if ( V_106 ) {
struct V_181 V_182 ;
F_73 ( V_99 , V_106 ) ;
V_182 . V_183 = F_74 ( V_99 ) ;
V_182 . V_184 = F_75 ( V_99 ) ;
V_176 = NULL ;
V_177 = 0 ;
if ( V_99 -> V_185 ) {
V_176 = ( void * ) V_99 -> V_185 ;
V_99 -> V_185 = NULL ;
V_177 = V_99 -> V_178 & V_186 ;
V_99 -> V_178 &= ~ ( V_186 ) ;
}
V_174 = F_76 ( V_99 ) ;
V_175 = F_77 ( V_99 , 0 ) ;
V_99 = V_174 ;
if ( V_173 != NULL ) {
* V_173 = 1 ;
}
if ( V_175 ) {
F_78 ( V_106 ) ;
if ( V_176 ) {
V_99 -> V_185 = V_176 ;
F_79 ( V_99 ) ;
}
* V_172 = V_174 ;
* V_94 = NULL ;
return V_175 ;
}
F_80 ( V_99 -> V_187 ) ;
V_182 . V_188 = V_179 ;
V_175 = F_81 ( V_99 , & V_182 , 0 , 0 ) ;
if ( V_176 ) {
V_99 -> V_185 = V_176 ;
V_99 -> V_178 |= V_177 ;
}
if ( V_175 ) {
F_78 ( V_106 ) ;
* V_172 = V_174 ;
* V_94 = NULL ;
return V_175 ;
}
F_82 ( V_99 , V_106 ) ;
V_175 = F_50 ( V_99 , V_91 , V_101 , V_102 , V_103 , V_104 ,
V_105 , & V_106 , & V_2 ) ;
if ( V_175 ) {
* V_172 = V_99 ;
* V_94 = NULL ;
return V_175 ;
}
ASSERT ( ! V_106 && V_2 ) ;
} else {
if ( V_173 != NULL )
* V_173 = 0 ;
}
* V_94 = V_2 ;
* V_172 = V_99 ;
return 0 ;
}
int
F_83 (
T_10 * V_99 ,
T_3 * V_2 )
{
int error ;
F_84 ( V_99 , V_2 , V_189 ) ;
ASSERT ( V_2 -> V_3 . V_117 > 0 ) ;
V_2 -> V_3 . V_117 -- ;
F_85 ( F_86 ( V_2 ) ) ;
F_68 ( V_99 , V_2 , V_146 ) ;
error = 0 ;
if ( V_2 -> V_3 . V_117 == 0 ) {
error = F_87 ( V_99 , V_2 ) ;
}
return error ;
}
void
F_58 (
T_10 * V_99 ,
T_3 * V_2 )
{
T_17 * V_108 ;
ASSERT ( F_22 ( V_2 , V_16 ) ) ;
ASSERT ( V_2 -> V_3 . V_121 == 1 ) ;
V_2 -> V_3 . V_121 = 2 ;
V_2 -> V_3 . V_116 = 0 ;
memset ( & ( V_2 -> V_3 . V_120 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_120 ) ) ;
V_108 = V_99 -> V_109 ;
if ( ! F_57 ( & V_108 -> V_8 ) ) {
F_88 ( & V_108 -> V_190 ) ;
if ( ! F_57 ( & V_108 -> V_8 ) ) {
F_89 ( & V_108 -> V_8 ) ;
F_90 ( & V_108 -> V_190 ) ;
F_91 ( V_99 , V_191 ) ;
} else {
F_90 ( & V_108 -> V_190 ) ;
}
}
}
int
F_92 (
T_10 * V_99 ,
T_3 * V_2 )
{
F_84 ( V_99 , V_2 , V_189 ) ;
ASSERT ( V_2 -> V_3 . V_117 > 0 ) ;
V_2 -> V_3 . V_117 ++ ;
F_93 ( F_86 ( V_2 ) ) ;
if ( ( V_2 -> V_3 . V_121 == 1 ) &&
( V_2 -> V_3 . V_117 > V_192 ) ) {
F_58 ( V_99 , V_2 ) ;
}
F_68 ( V_99 , V_2 , V_146 ) ;
return 0 ;
}
int
F_94 (
T_3 * V_91 ,
struct V_92 * V_93 ,
T_11 V_101 ,
T_13 V_103 ,
T_3 * * V_94 )
{
int V_193 = F_60 ( V_101 ) ;
struct V_107 * V_108 = V_91 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_194 * V_99 = NULL ;
int error ;
T_18 V_195 ;
T_19 V_196 ;
bool V_197 = false ;
T_2 V_198 ;
int V_173 ;
T_14 V_104 ;
struct V_199 * V_200 = NULL ;
struct V_199 * V_201 = NULL ;
struct V_199 * V_202 = NULL ;
struct V_181 V_182 ;
T_2 V_203 ;
F_95 ( V_91 , V_93 ) ;
if ( F_45 ( V_108 ) )
return F_46 ( V_97 ) ;
if ( V_91 -> V_3 . V_4 & V_77 )
V_104 = F_96 ( V_91 ) ;
else
V_104 = V_204 ;
error = F_97 ( V_91 , F_52 ( F_53 () ) ,
F_54 ( F_55 () ) , V_104 ,
V_205 | V_206 ,
& V_200 , & V_201 , & V_202 ) ;
if ( error )
return error ;
if ( V_193 ) {
V_103 = 0 ;
V_203 = F_98 ( V_108 , V_93 -> V_207 ) ;
V_182 . V_183 = F_99 ( V_108 ) -> V_208 . V_183 ;
V_182 . V_184 = V_209 ;
V_99 = F_100 ( V_108 , V_210 ) ;
} else {
V_203 = F_101 ( V_108 , V_93 -> V_207 ) ;
V_182 . V_183 = F_99 ( V_108 ) -> V_211 . V_183 ;
V_182 . V_184 = V_212 ;
V_99 = F_100 ( V_108 , V_213 ) ;
}
V_198 = V_214 ;
V_182 . V_188 = V_179 ;
error = F_81 ( V_99 , & V_182 , V_203 , 0 ) ;
if ( error == V_180 ) {
F_102 ( V_108 ) ;
error = F_81 ( V_99 , & V_182 , V_203 , 0 ) ;
}
if ( error == V_180 ) {
V_203 = 0 ;
error = F_81 ( V_99 , & V_182 , 0 , 0 ) ;
}
if ( error ) {
V_198 = 0 ;
goto V_215;
}
F_4 ( V_91 , V_16 | V_216 ) ;
V_197 = true ;
F_103 ( & V_195 , & V_196 ) ;
error = F_104 ( V_99 , V_108 , V_200 , V_201 ,
V_202 , V_203 , 1 , 0 ) ;
if ( error )
goto V_215;
error = F_105 ( V_99 , V_91 , V_93 , V_203 ) ;
if ( error )
goto V_215;
error = F_72 ( & V_99 , V_91 , V_101 , V_193 ? 2 : 1 , V_103 ,
V_104 , V_203 > 0 , & V_2 , & V_173 ) ;
if ( error ) {
if ( error == V_180 )
goto V_215;
goto V_217;
}
F_67 ( V_99 , V_91 , V_16 ) ;
V_197 = false ;
error = F_106 ( V_99 , V_91 , V_93 , V_2 -> V_53 ,
& V_196 , & V_195 , V_203 ?
V_203 - F_107 ( V_108 ) : 0 ) ;
if ( error ) {
ASSERT ( error != V_180 ) ;
goto V_217;
}
F_84 ( V_99 , V_91 , V_218 | V_189 ) ;
F_68 ( V_99 , V_91 , V_146 ) ;
if ( V_193 ) {
error = F_108 ( V_99 , V_2 , V_91 ) ;
if ( error )
goto V_219;
error = F_92 ( V_99 , V_91 ) ;
if ( error )
goto V_219;
}
if ( V_108 -> V_220 & ( V_221 | V_222 ) )
F_109 ( V_99 ) ;
F_110 ( V_99 , V_2 , V_200 , V_201 , V_202 ) ;
error = F_111 ( & V_99 , & V_195 , & V_173 ) ;
if ( error )
goto V_219;
error = F_77 ( V_99 , V_214 ) ;
if ( error )
goto V_223;
F_112 ( V_200 ) ;
F_112 ( V_201 ) ;
F_112 ( V_202 ) ;
* V_94 = V_2 ;
return 0 ;
V_219:
F_113 ( & V_195 ) ;
V_217:
V_198 |= V_224 ;
V_215:
F_114 ( V_99 , V_198 ) ;
V_223:
if ( V_2 )
F_115 ( V_2 ) ;
F_112 ( V_200 ) ;
F_112 ( V_201 ) ;
F_112 ( V_202 ) ;
if ( V_197 )
F_6 ( V_91 , V_16 ) ;
return error ;
}
int
F_116 (
T_3 * V_225 ,
T_3 * V_226 ,
struct V_92 * V_227 )
{
T_17 * V_108 = V_225 -> V_7 ;
T_10 * V_99 ;
int error ;
T_18 V_195 ;
T_19 V_196 ;
int V_198 ;
int V_173 ;
int V_203 ;
F_117 ( V_225 , V_227 ) ;
ASSERT ( ! F_60 ( V_226 -> V_3 . V_115 ) ) ;
if ( F_45 ( V_108 ) )
return F_46 ( V_97 ) ;
error = F_118 ( V_226 , 0 ) ;
if ( error )
goto V_228;
error = F_118 ( V_225 , 0 ) ;
if ( error )
goto V_228;
V_99 = F_100 ( V_108 , V_229 ) ;
V_198 = V_214 ;
V_203 = F_119 ( V_108 , V_227 -> V_207 ) ;
error = F_81 ( V_99 , & F_99 ( V_108 ) -> V_230 , V_203 , 0 ) ;
if ( error == V_180 ) {
V_203 = 0 ;
error = F_81 ( V_99 , & F_99 ( V_108 ) -> V_230 , 0 , 0 ) ;
}
if ( error ) {
V_198 = 0 ;
goto V_231;
}
F_28 ( V_226 , V_225 , V_16 ) ;
F_67 ( V_99 , V_226 , V_16 ) ;
F_67 ( V_99 , V_225 , V_16 ) ;
if ( F_120 ( ( V_225 -> V_3 . V_4 & V_77 ) &&
( F_96 ( V_225 ) != F_96 ( V_226 ) ) ) ) {
error = F_46 ( V_232 ) ;
goto V_231;
}
error = F_105 ( V_99 , V_225 , V_227 , V_203 ) ;
if ( error )
goto V_231;
F_103 ( & V_195 , & V_196 ) ;
error = F_106 ( V_99 , V_225 , V_227 , V_226 -> V_53 ,
& V_196 , & V_195 , V_203 ) ;
if ( error )
goto V_233;
F_84 ( V_99 , V_225 , V_218 | V_189 ) ;
F_68 ( V_99 , V_225 , V_146 ) ;
error = F_92 ( V_99 , V_226 ) ;
if ( error )
goto V_233;
if ( V_108 -> V_220 & ( V_221 | V_222 ) ) {
F_109 ( V_99 ) ;
}
error = F_111 ( & V_99 , & V_195 , & V_173 ) ;
if ( error ) {
F_113 ( & V_195 ) ;
goto V_233;
}
return F_77 ( V_99 , V_214 ) ;
V_233:
V_198 |= V_224 ;
V_231:
F_114 ( V_99 , V_198 ) ;
V_228:
return error ;
}
int
F_121 (
struct V_194 * * V_172 ,
struct V_1 * V_2 ,
int V_234 ,
T_20 V_235 )
{
struct V_107 * V_108 = V_2 -> V_7 ;
struct V_194 * V_99 = * V_172 ;
struct V_194 * V_174 ;
T_18 V_195 ;
T_19 V_196 ;
T_21 V_236 ;
T_21 V_237 ;
T_22 V_238 ;
int V_173 ;
int error = 0 ;
int V_239 = 0 ;
ASSERT ( F_22 ( V_2 , V_16 ) ) ;
ASSERT ( ! F_122 ( & F_86 ( V_2 ) -> V_240 ) ||
F_22 ( V_2 , V_21 ) ) ;
ASSERT ( V_235 <= F_123 ( V_2 ) ) ;
ASSERT ( V_99 -> V_178 & V_179 ) ;
ASSERT ( V_2 -> V_42 != NULL ) ;
ASSERT ( V_2 -> V_42 -> V_241 == 0 ) ;
ASSERT ( ! F_124 ( V_108 , V_2 ) ) ;
F_125 ( V_2 , V_235 ) ;
V_236 = F_126 ( V_108 , ( V_242 ) V_235 ) ;
V_237 = F_126 ( V_108 , V_108 -> V_243 -> V_244 ) ;
if ( V_236 == V_237 )
return 0 ;
ASSERT ( V_236 < V_237 ) ;
V_238 = V_237 - V_236 + 1 ;
while ( ! V_239 ) {
F_103 ( & V_195 , & V_196 ) ;
error = F_127 ( V_99 , V_2 ,
V_236 , V_238 ,
F_128 ( V_234 ) ,
V_245 ,
& V_196 , & V_195 ,
& V_239 ) ;
if ( error )
goto V_219;
error = F_111 ( & V_99 , & V_195 , & V_173 ) ;
if ( V_173 )
F_67 ( V_99 , V_2 , 0 ) ;
if ( error )
goto V_219;
if ( V_173 ) {
F_68 ( V_99 , V_2 , V_146 ) ;
}
V_174 = F_76 ( V_99 ) ;
error = F_77 ( V_99 , 0 ) ;
V_99 = V_174 ;
F_67 ( V_99 , V_2 , 0 ) ;
if ( error )
goto V_26;
F_80 ( V_99 -> V_187 ) ;
error = F_81 ( V_99 , & F_99 ( V_108 ) -> V_246 , 0 , 0 ) ;
if ( error )
goto V_26;
}
F_68 ( V_99 , V_2 , V_146 ) ;
F_129 ( V_2 , V_235 ) ;
V_26:
* V_172 = V_99 ;
return error ;
V_219:
F_113 ( & V_195 ) ;
goto V_26;
}
int
F_130 (
T_3 * V_2 )
{
T_17 * V_108 = V_2 -> V_7 ;
int error ;
if ( ! F_66 ( V_2 -> V_3 . V_115 ) || ( V_2 -> V_3 . V_115 == 0 ) )
return 0 ;
if ( V_108 -> V_220 & V_247 )
return 0 ;
if ( ! F_45 ( V_108 ) ) {
int V_248 ;
if ( ( V_2 -> V_3 . V_117 == 0 ) && F_65 ( V_2 ) )
F_131 ( V_2 ) ;
V_248 = F_132 ( V_2 , V_249 ) ;
if ( V_248 ) {
F_133 ( V_2 , V_250 ) ;
if ( F_134 ( F_86 ( V_2 ) ) && V_2 -> V_251 > 0 ) {
error = - F_135 ( F_86 ( V_2 ) -> V_252 ) ;
if ( error )
return error ;
}
}
}
if ( V_2 -> V_3 . V_117 == 0 )
return 0 ;
if ( F_136 ( V_2 , false ) ) {
if ( F_137 ( V_2 , V_250 ) )
return 0 ;
error = F_138 ( V_108 , V_2 , true ) ;
if ( error && error != V_253 )
return error ;
if ( V_2 -> V_251 )
F_71 ( V_2 , V_250 ) ;
}
return 0 ;
}
STATIC int
F_139 (
struct V_1 * V_2 )
{
struct V_107 * V_108 = V_2 -> V_7 ;
struct V_194 * V_99 ;
int error ;
V_99 = F_100 ( V_108 , V_254 ) ;
error = F_81 ( V_99 , & F_99 ( V_108 ) -> V_246 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_45 ( V_108 ) ) ;
F_114 ( V_99 , 0 ) ;
return error ;
}
F_4 ( V_2 , V_16 ) ;
F_67 ( V_99 , V_2 , 0 ) ;
V_2 -> V_3 . V_124 = 0 ;
F_68 ( V_99 , V_2 , V_146 ) ;
error = F_121 ( & V_99 , V_2 , V_255 , 0 ) ;
if ( error )
goto V_256;
ASSERT ( V_2 -> V_3 . V_125 == 0 ) ;
error = F_77 ( V_99 , V_214 ) ;
if ( error )
goto V_257;
F_6 ( V_2 , V_16 ) ;
return 0 ;
V_256:
F_114 ( V_99 , V_214 | V_224 ) ;
V_257:
F_6 ( V_2 , V_16 ) ;
return error ;
}
STATIC int
F_140 (
struct V_1 * V_2 )
{
T_18 V_195 ;
T_19 V_196 ;
int V_173 ;
struct V_107 * V_108 = V_2 -> V_7 ;
struct V_194 * V_99 ;
int error ;
V_99 = F_100 ( V_108 , V_254 ) ;
error = F_81 ( V_99 , & F_99 ( V_108 ) -> V_258 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_45 ( V_108 ) ) ;
F_114 ( V_99 , V_214 ) ;
return error ;
}
F_4 ( V_2 , V_16 ) ;
F_67 ( V_99 , V_2 , 0 ) ;
F_103 ( & V_195 , & V_196 ) ;
error = F_141 ( V_99 , V_2 , & V_195 ) ;
if ( error ) {
if ( ! F_45 ( V_108 ) ) {
F_142 ( V_108 , L_1 ,
V_259 , error ) ;
F_143 ( V_108 , V_260 ) ;
}
F_114 ( V_99 , V_214 | V_224 ) ;
F_6 ( V_2 , V_16 ) ;
return error ;
}
F_144 ( V_99 , V_2 , V_261 , - 1 ) ;
error = F_111 ( & V_99 , & V_195 , & V_173 ) ;
if ( error )
F_142 ( V_108 , L_2 ,
V_259 , error ) ;
error = F_77 ( V_99 , V_214 ) ;
if ( error )
F_142 ( V_108 , L_3 ,
V_259 , error ) ;
F_6 ( V_2 , V_16 ) ;
return 0 ;
}
void
F_145 (
T_3 * V_2 )
{
struct V_107 * V_108 ;
int error ;
int V_262 = 0 ;
if ( V_2 -> V_3 . V_115 == 0 ) {
ASSERT ( V_2 -> V_13 . V_166 == 0 ) ;
ASSERT ( V_2 -> V_13 . V_263 == 0 ) ;
return;
}
V_108 = V_2 -> V_7 ;
if ( V_108 -> V_220 & V_247 )
return;
if ( V_2 -> V_3 . V_117 != 0 ) {
if ( F_136 ( V_2 , true ) )
F_138 ( V_108 , V_2 , false ) ;
return;
}
if ( F_66 ( V_2 -> V_3 . V_115 ) &&
( V_2 -> V_3 . V_124 != 0 || F_123 ( V_2 ) != 0 ||
V_2 -> V_3 . V_125 > 0 || V_2 -> V_251 > 0 ) )
V_262 = 1 ;
error = F_118 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_146 ( V_2 -> V_3 . V_115 ) )
error = F_147 ( V_2 ) ;
else if ( V_262 )
error = F_139 ( V_2 ) ;
if ( error )
return;
if ( V_2 -> V_3 . V_170 > 0 ) {
ASSERT ( V_2 -> V_3 . V_264 != 0 ) ;
error = F_148 ( V_2 ) ;
if ( error )
return;
}
if ( V_2 -> V_265 )
F_149 ( V_2 , V_266 ) ;
ASSERT ( V_2 -> V_3 . V_170 == 0 ) ;
error = F_140 ( V_2 ) ;
if ( error )
return;
F_150 ( V_2 ) ;
}
int
F_87 (
T_10 * V_99 ,
T_3 * V_2 )
{
T_17 * V_108 ;
T_23 * V_267 ;
T_8 * V_90 ;
T_15 * V_268 ;
T_15 * V_269 ;
T_24 V_270 ;
short V_271 ;
int V_272 ;
int error ;
ASSERT ( V_2 -> V_3 . V_117 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_115 != 0 ) ;
V_108 = V_99 -> V_109 ;
error = F_151 ( V_108 , V_99 , F_152 ( V_108 , V_2 -> V_53 ) , & V_268 ) ;
if ( error )
return error ;
V_267 = F_153 ( V_268 ) ;
V_270 = F_154 ( V_108 , V_2 -> V_53 ) ;
ASSERT ( V_270 != 0 ) ;
V_271 = V_270 % V_273 ;
ASSERT ( V_267 -> V_274 [ V_271 ] ) ;
ASSERT ( F_155 ( V_267 -> V_274 [ V_271 ] ) != V_270 ) ;
if ( V_267 -> V_274 [ V_271 ] != F_156 ( V_275 ) ) {
error = F_157 ( V_108 , V_99 , & V_2 -> V_276 , & V_90 , & V_269 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_90 -> V_277 == F_156 ( V_275 ) ) ;
V_90 -> V_277 = V_267 -> V_274 [ V_271 ] ;
V_272 = V_2 -> V_276 . V_278 +
F_158 ( T_8 , V_277 ) ;
F_159 ( V_108 , V_90 ) ;
F_160 ( V_99 , V_269 ) ;
F_161 ( V_99 , V_269 , V_272 ,
( V_272 + sizeof( T_24 ) - 1 ) ) ;
F_162 ( V_108 , V_269 ) ;
}
ASSERT ( V_270 != 0 ) ;
V_267 -> V_274 [ V_271 ] = F_156 ( V_270 ) ;
V_272 = F_158 ( T_23 , V_274 ) +
( sizeof( T_24 ) * V_271 ) ;
F_161 ( V_99 , V_268 , V_272 ,
( V_272 + sizeof( T_24 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_163 (
T_10 * V_99 ,
T_3 * V_2 )
{
T_9 V_279 ;
T_17 * V_108 ;
T_23 * V_267 ;
T_8 * V_90 ;
T_15 * V_268 ;
T_15 * V_269 ;
T_25 V_280 ;
T_24 V_270 ;
T_24 V_281 ;
T_15 * V_282 ;
T_8 * V_283 = NULL ;
short V_271 ;
int V_272 , V_284 = 0 ;
int error ;
V_108 = V_99 -> V_109 ;
V_280 = F_152 ( V_108 , V_2 -> V_53 ) ;
error = F_151 ( V_108 , V_99 , V_280 , & V_268 ) ;
if ( error )
return error ;
V_267 = F_153 ( V_268 ) ;
V_270 = F_154 ( V_108 , V_2 -> V_53 ) ;
ASSERT ( V_270 != 0 ) ;
V_271 = V_270 % V_273 ;
ASSERT ( V_267 -> V_274 [ V_271 ] != F_156 ( V_275 ) ) ;
ASSERT ( V_267 -> V_274 [ V_271 ] ) ;
if ( F_155 ( V_267 -> V_274 [ V_271 ] ) == V_270 ) {
error = F_157 ( V_108 , V_99 , & V_2 -> V_276 , & V_90 , & V_269 ,
0 , 0 ) ;
if ( error ) {
F_164 ( V_108 , L_4 ,
V_259 , error ) ;
return error ;
}
V_281 = F_155 ( V_90 -> V_277 ) ;
ASSERT ( V_281 != 0 ) ;
if ( V_281 != V_275 ) {
V_90 -> V_277 = F_156 ( V_275 ) ;
V_272 = V_2 -> V_276 . V_278 +
F_158 ( T_8 , V_277 ) ;
F_159 ( V_108 , V_90 ) ;
F_160 ( V_99 , V_269 ) ;
F_161 ( V_99 , V_269 , V_272 ,
( V_272 + sizeof( T_24 ) - 1 ) ) ;
F_162 ( V_108 , V_269 ) ;
} else {
F_165 ( V_99 , V_269 ) ;
}
ASSERT ( V_281 != 0 ) ;
ASSERT ( V_281 != V_270 ) ;
V_267 -> V_274 [ V_271 ] = F_156 ( V_281 ) ;
V_272 = F_158 ( T_23 , V_274 ) +
( sizeof( T_24 ) * V_271 ) ;
F_161 ( V_99 , V_268 , V_272 ,
( V_272 + sizeof( T_24 ) - 1 ) ) ;
} else {
V_281 = F_155 ( V_267 -> V_274 [ V_271 ] ) ;
V_282 = NULL ;
while ( V_281 != V_270 ) {
struct V_285 V_286 ;
if ( V_282 )
F_165 ( V_99 , V_282 ) ;
V_286 . V_287 = 0 ;
V_279 = F_166 ( V_108 , V_280 , V_281 ) ;
error = V_285 ( V_108 , V_99 , V_279 , & V_286 , 0 ) ;
if ( error ) {
F_164 ( V_108 ,
L_5 ,
V_259 , error ) ;
return error ;
}
error = F_157 ( V_108 , V_99 , & V_286 , & V_283 ,
& V_282 , 0 , 0 ) ;
if ( error ) {
F_164 ( V_108 ,
L_4 ,
V_259 , error ) ;
return error ;
}
V_284 = V_286 . V_278 ;
V_281 = F_155 ( V_283 -> V_277 ) ;
ASSERT ( V_281 != V_275 ) ;
ASSERT ( V_281 != 0 ) ;
}
error = F_157 ( V_108 , V_99 , & V_2 -> V_276 , & V_90 , & V_269 ,
0 , 0 ) ;
if ( error ) {
F_164 ( V_108 , L_6 ,
V_259 , error ) ;
return error ;
}
V_281 = F_155 ( V_90 -> V_277 ) ;
ASSERT ( V_281 != 0 ) ;
ASSERT ( V_281 != V_270 ) ;
if ( V_281 != V_275 ) {
V_90 -> V_277 = F_156 ( V_275 ) ;
V_272 = V_2 -> V_276 . V_278 +
F_158 ( T_8 , V_277 ) ;
F_159 ( V_108 , V_90 ) ;
F_160 ( V_99 , V_269 ) ;
F_161 ( V_99 , V_269 , V_272 ,
( V_272 + sizeof( T_24 ) - 1 ) ) ;
F_162 ( V_108 , V_269 ) ;
} else {
F_165 ( V_99 , V_269 ) ;
}
V_283 -> V_277 = F_156 ( V_281 ) ;
ASSERT ( V_281 != 0 ) ;
V_272 = V_284 + F_158 ( T_8 , V_277 ) ;
F_159 ( V_108 , V_283 ) ;
F_160 ( V_99 , V_282 ) ;
F_161 ( V_99 , V_282 , V_272 ,
( V_272 + sizeof( T_24 ) - 1 ) ) ;
F_162 ( V_108 , V_282 ) ;
}
return 0 ;
}
STATIC int
F_167 (
T_3 * V_288 ,
T_10 * V_99 ,
T_9 V_96 )
{
T_17 * V_108 = V_288 -> V_7 ;
int V_289 ;
int V_290 ;
int V_291 ;
int V_37 , V_38 ;
T_26 V_292 ;
T_15 * V_293 ;
T_3 * V_2 ;
T_27 * V_294 ;
T_4 * V_295 ;
struct V_296 * V_297 ;
V_297 = F_168 ( V_108 , F_152 ( V_108 , V_96 ) ) ;
if ( V_108 -> V_8 . V_298 >= F_169 ( V_108 ) ) {
V_289 = 1 ;
V_291 = V_108 -> V_8 . V_299 ;
V_290 = F_170 ( V_108 ) ;
} else {
V_289 = F_169 ( V_108 ) /
V_108 -> V_8 . V_298 ;
V_291 = V_289 * V_108 -> V_8 . V_299 ;
V_290 = F_170 ( V_108 ) / V_289 ;
}
for ( V_38 = 0 ; V_38 < V_290 ; V_38 ++ , V_96 += V_291 ) {
V_292 = F_171 ( V_108 , F_152 ( V_108 , V_96 ) ,
F_172 ( V_108 , V_96 ) ) ;
V_293 = F_173 ( V_99 , V_108 -> V_300 , V_292 ,
V_108 -> V_301 * V_289 ,
V_302 ) ;
if ( ! V_293 )
return V_303 ;
V_293 -> V_304 = & V_305 ;
V_295 = V_293 -> V_306 ;
while ( V_295 ) {
if ( V_295 -> V_307 == V_308 ) {
V_294 = ( T_27 * ) V_295 ;
ASSERT ( V_294 -> V_309 == 1 ) ;
V_295 -> V_310 = V_311 ;
F_174 ( V_108 -> V_312 ,
& V_294 -> V_313 ,
& V_294 -> V_314 . V_315 ) ;
F_71 ( V_294 -> V_316 , V_317 ) ;
}
V_295 = V_295 -> V_318 ;
}
for ( V_37 = 0 ; V_37 < V_291 ; V_37 ++ ) {
V_319:
F_175 () ;
V_2 = F_176 ( & V_297 -> V_320 ,
F_154 ( V_108 , ( V_96 + V_37 ) ) ) ;
if ( ! V_2 ) {
F_177 () ;
continue;
}
F_88 ( & V_2 -> V_321 ) ;
if ( V_2 -> V_53 != V_96 + V_37 ||
F_178 ( V_2 , V_317 ) ) {
F_90 ( & V_2 -> V_321 ) ;
F_177 () ;
continue;
}
F_90 ( & V_2 -> V_321 ) ;
if ( V_2 != V_288 &&
! F_12 ( V_2 , V_16 ) ) {
F_177 () ;
F_26 ( 1 ) ;
goto V_319;
}
F_177 () ;
F_179 ( V_2 ) ;
F_71 ( V_2 , V_317 ) ;
V_294 = V_2 -> V_42 ;
if ( ! V_294 || F_180 ( V_2 ) ) {
ASSERT ( V_2 != V_288 ) ;
F_181 ( V_2 ) ;
F_6 ( V_2 , V_16 ) ;
continue;
}
V_294 -> V_322 = V_294 -> V_323 ;
V_294 -> V_323 = 0 ;
V_294 -> V_309 = 1 ;
F_174 ( V_108 -> V_312 , & V_294 -> V_313 ,
& V_294 -> V_314 . V_315 ) ;
F_182 ( V_293 , V_311 ,
& V_294 -> V_314 ) ;
if ( V_2 != V_288 )
F_6 ( V_2 , V_16 ) ;
}
F_183 ( V_99 , V_293 ) ;
F_184 ( V_99 , V_293 ) ;
}
F_185 ( V_297 ) ;
return 0 ;
}
int
F_141 (
T_10 * V_99 ,
T_3 * V_2 ,
T_18 * V_324 )
{
int error ;
int V_325 ;
T_9 V_326 ;
ASSERT ( F_22 ( V_2 , V_16 ) ) ;
ASSERT ( V_2 -> V_3 . V_117 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_125 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_170 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_124 == 0 || ! F_66 ( V_2 -> V_3 . V_115 ) ) ;
ASSERT ( V_2 -> V_3 . V_126 == 0 ) ;
error = F_163 ( V_99 , V_2 ) ;
if ( error )
return error ;
error = F_186 ( V_99 , V_2 -> V_53 , V_324 , & V_325 , & V_326 ) ;
if ( error )
return error ;
V_2 -> V_3 . V_115 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_135 = 0 ;
V_2 -> V_3 . V_264 = 0 ;
V_2 -> V_3 . V_11 = V_164 ;
V_2 -> V_3 . V_169 = V_164 ;
V_2 -> V_3 . V_327 ++ ;
F_68 ( V_99 , V_2 , V_146 ) ;
if ( V_325 )
error = F_167 ( V_2 , V_99 , V_326 ) ;
return error ;
}
static void
F_187 (
struct V_1 * V_2 )
{
ASSERT ( F_22 ( V_2 , V_16 | V_17 ) ) ;
F_188 ( V_2 , V_19 ) ;
F_189 ( V_2 -> V_7 , V_2 -> V_42 -> V_328 , 0 ) ;
}
static void
F_190 (
struct V_1 * V_2 )
{
T_5 * V_54 = F_30 ( & V_2 -> V_55 , V_329 ) ;
F_31 ( V_57 , & V_2 -> V_55 , V_329 ) ;
F_187 ( V_2 ) ;
do {
F_191 ( V_54 , & V_57 . V_57 , V_58 ) ;
if ( F_192 ( V_2 ) )
F_34 () ;
} while ( F_192 ( V_2 ) );
F_36 ( V_54 , & V_57 . V_57 ) ;
}
void
F_193 (
struct V_1 * V_2 )
{
if ( F_192 ( V_2 ) )
F_190 ( V_2 ) ;
}
int
F_194 (
T_3 * V_91 ,
struct V_92 * V_93 ,
T_3 * V_2 )
{
T_17 * V_108 = V_91 -> V_7 ;
T_10 * V_99 = NULL ;
int V_193 = F_60 ( V_2 -> V_3 . V_115 ) ;
int error = 0 ;
T_18 V_195 ;
T_19 V_196 ;
int V_198 ;
int V_173 ;
int V_330 ;
T_2 V_203 ;
T_2 V_331 ;
F_195 ( V_91 , V_93 ) ;
if ( F_45 ( V_108 ) )
return F_46 ( V_97 ) ;
error = F_118 ( V_91 , 0 ) ;
if ( error )
goto V_228;
error = F_118 ( V_2 , 0 ) ;
if ( error )
goto V_228;
if ( V_193 ) {
V_99 = F_100 ( V_108 , V_332 ) ;
V_331 = V_333 ;
} else {
V_99 = F_100 ( V_108 , V_334 ) ;
V_331 = V_335 ;
}
V_198 = V_214 ;
V_203 = F_196 ( V_108 ) ;
error = F_81 ( V_99 , & F_99 ( V_108 ) -> V_336 , V_203 , 0 ) ;
if ( error == V_180 ) {
V_203 = 0 ;
error = F_81 ( V_99 , & F_99 ( V_108 ) -> V_336 , 0 , 0 ) ;
}
if ( error ) {
ASSERT ( error != V_180 ) ;
V_198 = 0 ;
goto V_215;
}
F_28 ( V_91 , V_2 , V_16 ) ;
F_67 ( V_99 , V_91 , V_16 ) ;
F_67 ( V_99 , V_2 , V_16 ) ;
V_198 |= V_224 ;
if ( V_193 ) {
ASSERT ( V_2 -> V_3 . V_117 >= 2 ) ;
if ( V_2 -> V_3 . V_117 != 2 ) {
error = F_46 ( V_337 ) ;
goto V_215;
}
if ( ! F_197 ( V_2 ) ) {
error = F_46 ( V_337 ) ;
goto V_215;
}
error = F_83 ( V_99 , V_91 ) ;
if ( error )
goto V_215;
error = F_83 ( V_99 , V_2 ) ;
if ( error )
goto V_215;
} else {
F_68 ( V_99 , V_91 , V_146 ) ;
}
F_84 ( V_99 , V_91 , V_218 | V_189 ) ;
error = F_83 ( V_99 , V_2 ) ;
if ( error )
goto V_215;
V_330 = ( V_2 -> V_3 . V_117 == 0 ) ;
F_103 ( & V_195 , & V_196 ) ;
error = F_198 ( V_99 , V_91 , V_93 , V_2 -> V_53 ,
& V_196 , & V_195 , V_203 ) ;
if ( error ) {
ASSERT ( error != V_338 ) ;
goto V_219;
}
if ( V_108 -> V_220 & ( V_221 | V_222 ) )
F_109 ( V_99 ) ;
error = F_111 ( & V_99 , & V_195 , & V_173 ) ;
if ( error )
goto V_219;
error = F_77 ( V_99 , V_214 ) ;
if ( error )
goto V_228;
if ( ! V_193 && V_330 && F_65 ( V_2 ) )
F_131 ( V_2 ) ;
return 0 ;
V_219:
F_113 ( & V_195 ) ;
V_215:
F_114 ( V_99 , V_198 ) ;
V_228:
return error ;
}
STATIC void
F_199 (
T_3 * V_339 ,
T_3 * V_340 ,
T_3 * V_51 ,
T_3 * V_341 ,
T_3 * * V_342 ,
int * V_343 )
{
T_3 * V_52 ;
int V_37 , V_38 ;
V_342 [ 0 ] = V_339 ;
V_342 [ 1 ] = V_340 ;
V_342 [ 2 ] = V_51 ;
if ( V_341 ) {
* V_343 = 4 ;
V_342 [ 3 ] = V_341 ;
} else {
* V_343 = 3 ;
V_342 [ 3 ] = NULL ;
}
for ( V_37 = 0 ; V_37 < * V_343 ; V_37 ++ ) {
for ( V_38 = 1 ; V_38 < * V_343 ; V_38 ++ ) {
if ( V_342 [ V_38 ] -> V_53 < V_342 [ V_38 - 1 ] -> V_53 ) {
V_52 = V_342 [ V_38 ] ;
V_342 [ V_38 ] = V_342 [ V_38 - 1 ] ;
V_342 [ V_38 - 1 ] = V_52 ;
}
}
}
}
int
F_200 (
T_3 * V_344 ,
struct V_92 * V_345 ,
T_3 * V_346 ,
T_3 * V_347 ,
struct V_92 * V_227 ,
T_3 * V_348 )
{
T_10 * V_99 = NULL ;
T_17 * V_108 = V_344 -> V_7 ;
int V_349 ;
int V_350 ;
int error ;
T_18 V_195 ;
T_19 V_196 ;
int V_198 ;
int V_173 ;
T_3 * V_35 [ 4 ] ;
int V_351 ;
int V_343 ;
F_201 ( V_344 , V_347 , V_345 , V_227 ) ;
V_349 = ( V_344 != V_347 ) ;
V_350 = F_60 ( V_346 -> V_3 . V_115 ) ;
F_199 ( V_344 , V_347 , V_346 , V_348 ,
V_35 , & V_343 ) ;
F_103 ( & V_195 , & V_196 ) ;
V_99 = F_100 ( V_108 , V_352 ) ;
V_198 = V_214 ;
V_351 = F_202 ( V_108 , V_227 -> V_207 ) ;
error = F_81 ( V_99 , & F_99 ( V_108 ) -> V_353 , V_351 , 0 ) ;
if ( error == V_180 ) {
V_351 = 0 ;
error = F_81 ( V_99 , & F_99 ( V_108 ) -> V_353 , 0 , 0 ) ;
}
if ( error ) {
F_114 ( V_99 , 0 ) ;
goto V_228;
}
error = F_203 ( V_35 ) ;
if ( error ) {
F_114 ( V_99 , V_198 ) ;
goto V_228;
}
F_25 ( V_35 , V_343 , V_16 ) ;
F_67 ( V_99 , V_344 , V_16 ) ;
if ( V_349 )
F_67 ( V_99 , V_347 , V_16 ) ;
F_67 ( V_99 , V_346 , V_16 ) ;
if ( V_348 )
F_67 ( V_99 , V_348 , V_16 ) ;
if ( F_120 ( ( V_347 -> V_3 . V_4 & V_77 ) &&
( F_96 ( V_347 ) != F_96 ( V_346 ) ) ) ) {
error = F_46 ( V_232 ) ;
goto V_231;
}
if ( V_348 == NULL ) {
error = F_105 ( V_99 , V_347 , V_227 , V_351 ) ;
if ( error )
goto V_231;
error = F_106 ( V_99 , V_347 , V_227 ,
V_346 -> V_53 , & V_196 ,
& V_195 , V_351 ) ;
if ( error == V_180 )
goto V_231;
if ( error )
goto V_233;
F_84 ( V_99 , V_347 ,
V_218 | V_189 ) ;
if ( V_349 && V_350 ) {
error = F_92 ( V_99 , V_347 ) ;
if ( error )
goto V_233;
}
} else {
if ( F_60 ( V_348 -> V_3 . V_115 ) ) {
if ( ! ( F_197 ( V_348 ) ) ||
( V_348 -> V_3 . V_117 > 2 ) ) {
error = F_46 ( V_354 ) ;
goto V_231;
}
}
error = F_204 ( V_99 , V_347 , V_227 ,
V_346 -> V_53 ,
& V_196 , & V_195 , V_351 ) ;
if ( error )
goto V_233;
F_84 ( V_99 , V_347 ,
V_218 | V_189 ) ;
error = F_83 ( V_99 , V_348 ) ;
if ( error )
goto V_233;
if ( V_350 ) {
error = F_83 ( V_99 , V_348 ) ;
if ( error )
goto V_233;
}
}
if ( V_349 && V_350 ) {
error = F_204 ( V_99 , V_346 , & V_355 ,
V_347 -> V_53 ,
& V_196 , & V_195 , V_351 ) ;
ASSERT ( error != V_354 ) ;
if ( error )
goto V_233;
}
F_84 ( V_99 , V_346 , V_189 ) ;
F_68 ( V_99 , V_346 , V_146 ) ;
if ( V_350 && ( V_349 || V_348 != NULL ) ) {
error = F_83 ( V_99 , V_344 ) ;
if ( error )
goto V_233;
}
error = F_198 ( V_99 , V_344 , V_345 , V_346 -> V_53 ,
& V_196 , & V_195 , V_351 ) ;
if ( error )
goto V_233;
F_84 ( V_99 , V_344 , V_218 | V_189 ) ;
F_68 ( V_99 , V_344 , V_146 ) ;
if ( V_349 )
F_68 ( V_99 , V_347 , V_146 ) ;
if ( V_108 -> V_220 & ( V_221 | V_222 ) ) {
F_109 ( V_99 ) ;
}
error = F_111 ( & V_99 , & V_195 , & V_173 ) ;
if ( error ) {
F_113 ( & V_195 ) ;
F_114 ( V_99 , ( V_214 |
V_224 ) ) ;
goto V_228;
}
return F_77 ( V_99 , V_214 ) ;
V_233:
V_198 |= V_224 ;
V_231:
F_113 ( & V_195 ) ;
F_114 ( V_99 , V_198 ) ;
V_228:
return error ;
}
STATIC int
F_205 (
T_3 * V_2 ,
T_15 * V_293 )
{
T_17 * V_108 = V_2 -> V_7 ;
struct V_296 * V_297 ;
unsigned long V_356 , V_357 ;
unsigned long V_358 ;
int V_359 ;
T_3 * * V_360 ;
T_3 * V_361 ;
int V_362 ;
int V_363 = 0 ;
int V_364 ;
int V_37 ;
V_297 = F_168 ( V_108 , F_152 ( V_108 , V_2 -> V_53 ) ) ;
V_358 = F_169 ( V_108 ) >> V_108 -> V_8 . V_365 ;
V_359 = V_358 * sizeof( T_3 * ) ;
V_360 = F_206 ( V_359 , V_366 | V_367 ) ;
if ( ! V_360 )
goto V_368;
V_357 = ~ ( ( ( F_169 ( V_108 ) >> V_108 -> V_8 . V_365 ) ) - 1 ) ;
V_356 = F_154 ( V_108 , V_2 -> V_53 ) & V_357 ;
F_175 () ;
V_362 = F_207 ( & V_297 -> V_320 , ( void * * ) V_360 ,
V_356 , V_358 ) ;
if ( V_362 == 0 )
goto V_369;
for ( V_37 = 0 ; V_37 < V_362 ; V_37 ++ ) {
V_361 = V_360 [ V_37 ] ;
if ( V_361 == V_2 )
continue;
F_88 ( & V_2 -> V_321 ) ;
if ( ! V_2 -> V_53 ||
( F_154 ( V_108 , V_361 -> V_53 ) & V_357 ) != V_356 ) {
F_90 ( & V_2 -> V_321 ) ;
continue;
}
F_90 ( & V_2 -> V_321 ) ;
if ( F_180 ( V_361 ) && F_192 ( V_361 ) == 0 )
continue;
if ( ! F_12 ( V_361 , V_17 ) )
continue;
if ( ! F_35 ( V_361 ) ) {
F_6 ( V_361 , V_17 ) ;
continue;
}
if ( F_192 ( V_361 ) ) {
F_181 ( V_361 ) ;
F_6 ( V_361 , V_17 ) ;
continue;
}
if ( ! F_180 ( V_361 ) ) {
int error ;
error = F_208 ( V_361 , V_293 ) ;
if ( error ) {
F_6 ( V_361 , V_17 ) ;
goto V_370;
}
V_363 ++ ;
} else {
F_181 ( V_361 ) ;
}
F_6 ( V_361 , V_17 ) ;
}
if ( V_363 ) {
F_209 ( V_371 ) ;
F_210 ( V_372 , V_363 ) ;
}
V_369:
F_177 () ;
F_49 ( V_360 ) ;
V_368:
F_185 ( V_297 ) ;
return 0 ;
V_370:
F_177 () ;
V_364 = ( V_293 -> V_373 & V_374 ) ;
if ( V_364 )
F_78 ( V_293 ) ;
F_143 ( V_108 , V_375 ) ;
if ( ! V_364 ) {
if ( V_293 -> V_376 ) {
F_211 ( V_293 ) ;
F_212 ( V_293 ) ;
F_213 ( V_293 , V_97 ) ;
F_214 ( V_293 , 0 ) ;
} else {
F_212 ( V_293 ) ;
F_78 ( V_293 ) ;
}
}
F_215 ( V_361 , false ) ;
F_49 ( V_360 ) ;
F_185 ( V_297 ) ;
return F_46 ( V_377 ) ;
}
int
F_216 (
struct V_1 * V_2 ,
struct V_378 * * V_379 )
{
struct V_107 * V_108 = V_2 -> V_7 ;
struct V_378 * V_293 ;
struct V_380 * V_90 ;
int error ;
F_209 ( V_381 ) ;
ASSERT ( F_22 ( V_2 , V_16 | V_17 ) ) ;
ASSERT ( F_33 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_11 != V_12 ||
V_2 -> V_3 . V_125 > F_217 ( V_2 , V_255 ) ) ;
* V_379 = NULL ;
F_193 ( V_2 ) ;
if ( F_137 ( V_2 , V_317 ) ) {
F_181 ( V_2 ) ;
return 0 ;
}
if ( F_45 ( V_108 ) ) {
error = F_46 ( V_97 ) ;
goto V_382;
}
error = F_157 ( V_108 , NULL , & V_2 -> V_276 , & V_90 , & V_293 , V_383 ,
0 ) ;
if ( error || ! V_293 ) {
F_181 ( V_2 ) ;
return error ;
}
error = F_208 ( V_2 , V_293 ) ;
if ( error )
goto V_384;
if ( F_218 ( V_293 ) )
F_219 ( V_108 , 0 ) ;
error = F_205 ( V_2 , V_293 ) ;
if ( error )
goto V_370;
* V_379 = V_293 ;
return 0 ;
V_384:
F_78 ( V_293 ) ;
F_143 ( V_108 , V_375 ) ;
V_370:
error = F_46 ( V_377 ) ;
V_382:
F_215 ( V_2 , false ) ;
return error ;
}
STATIC int
F_208 (
struct V_1 * V_2 ,
struct V_378 * V_293 )
{
struct V_385 * V_294 = V_2 -> V_42 ;
struct V_380 * V_90 ;
struct V_107 * V_108 = V_2 -> V_7 ;
ASSERT ( F_22 ( V_2 , V_16 | V_17 ) ) ;
ASSERT ( F_33 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_11 != V_12 ||
V_2 -> V_3 . V_125 > F_217 ( V_2 , V_255 ) ) ;
ASSERT ( V_294 != NULL && V_294 -> V_323 != 0 ) ;
V_90 = ( T_8 * ) F_220 ( V_293 , V_2 -> V_276 . V_278 ) ;
if ( F_221 ( V_90 -> V_386 != F_222 ( V_387 ) ,
V_108 , V_388 , V_389 ) ) {
F_223 ( V_108 , V_390 ,
L_7 ,
V_259 , V_2 -> V_53 , F_41 ( V_90 -> V_386 ) , V_90 ) ;
goto V_384;
}
if ( F_221 ( V_2 -> V_3 . V_386 != V_387 ,
V_108 , V_391 , V_392 ) ) {
F_223 ( V_108 , V_390 ,
L_8 ,
V_259 , V_2 -> V_53 , V_2 , V_2 -> V_3 . V_386 ) ;
goto V_384;
}
if ( F_66 ( V_2 -> V_3 . V_115 ) ) {
if ( F_221 (
( V_2 -> V_3 . V_11 != V_164 ) &&
( V_2 -> V_3 . V_11 != V_12 ) ,
V_108 , V_393 , V_394 ) ) {
F_223 ( V_108 , V_390 ,
L_9 ,
V_259 , V_2 -> V_53 , V_2 ) ;
goto V_384;
}
} else if ( F_60 ( V_2 -> V_3 . V_115 ) ) {
if ( F_221 (
( V_2 -> V_3 . V_11 != V_164 ) &&
( V_2 -> V_3 . V_11 != V_12 ) &&
( V_2 -> V_3 . V_11 != V_395 ) ,
V_108 , V_396 , V_397 ) ) {
F_223 ( V_108 , V_390 ,
L_10 ,
V_259 , V_2 -> V_53 , V_2 ) ;
goto V_384;
}
}
if ( F_221 ( V_2 -> V_3 . V_125 + V_2 -> V_3 . V_170 >
V_2 -> V_3 . V_126 , V_108 , V_398 ,
V_399 ) ) {
F_223 ( V_108 , V_390 ,
L_11
L_12 ,
V_259 , V_2 -> V_53 ,
V_2 -> V_3 . V_125 + V_2 -> V_3 . V_170 ,
V_2 -> V_3 . V_126 , V_2 ) ;
goto V_384;
}
if ( F_221 ( V_2 -> V_3 . V_264 > V_108 -> V_8 . V_400 ,
V_108 , V_401 , V_402 ) ) {
F_223 ( V_108 , V_390 ,
L_13 ,
V_259 , V_2 -> V_53 , V_2 -> V_3 . V_264 , V_2 ) ;
goto V_384;
}
if ( V_2 -> V_3 . V_121 < 3 )
V_2 -> V_3 . V_403 ++ ;
F_224 ( V_90 , & V_2 -> V_3 ) ;
if ( V_2 -> V_3 . V_403 == V_404 )
V_2 -> V_3 . V_403 = 0 ;
ASSERT ( V_2 -> V_3 . V_121 == 1 || F_57 ( & V_108 -> V_8 ) ) ;
if ( V_2 -> V_3 . V_121 == 1 ) {
if ( ! F_57 ( & V_108 -> V_8 ) ) {
ASSERT ( V_2 -> V_3 . V_117 <= V_192 ) ;
V_90 -> V_116 = F_222 ( V_2 -> V_3 . V_117 ) ;
} else {
V_2 -> V_3 . V_121 = 2 ;
V_90 -> V_121 = 2 ;
V_2 -> V_3 . V_116 = 0 ;
V_90 -> V_116 = 0 ;
memset ( & ( V_2 -> V_3 . V_120 [ 0 ] ) , 0 , sizeof( V_2 -> V_3 . V_120 ) ) ;
memset ( & ( V_90 -> V_120 [ 0 ] ) , 0 ,
sizeof( V_90 -> V_120 ) ) ;
ASSERT ( F_96 ( V_2 ) == 0 ) ;
}
}
F_225 ( V_2 , V_90 , V_294 , V_255 , V_293 ) ;
if ( F_39 ( V_2 ) )
F_225 ( V_2 , V_90 , V_294 , V_266 , V_293 ) ;
F_162 ( V_108 , V_293 ) ;
V_294 -> V_322 = V_294 -> V_323 ;
V_294 -> V_323 = 0 ;
V_294 -> V_309 = 1 ;
F_174 ( V_108 -> V_312 , & V_294 -> V_313 ,
& V_294 -> V_314 . V_315 ) ;
F_182 ( V_293 , V_405 , & V_294 -> V_314 ) ;
if ( V_2 -> V_3 . V_121 == 3 )
V_90 -> V_142 = F_226 ( V_294 -> V_314 . V_315 ) ;
F_159 ( V_108 , V_90 ) ;
ASSERT ( V_293 -> V_306 != NULL ) ;
ASSERT ( V_293 -> V_376 != NULL ) ;
return 0 ;
V_384:
return F_46 ( V_377 ) ;
}
