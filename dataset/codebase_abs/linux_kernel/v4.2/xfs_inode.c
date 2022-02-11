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
T_3 * V_2 ;
T_15 * V_113 = NULL ;
int V_180 ;
void * V_181 ;
T_2 V_182 ;
V_106 = * V_178 ;
ASSERT ( V_106 -> V_183 & V_184 ) ;
V_180 = F_50 ( V_106 , V_98 , V_108 , V_109 , V_110 , V_111 , V_112 ,
& V_113 , & V_2 ) ;
if ( V_180 ) {
* V_101 = NULL ;
return V_180 ;
}
if ( ! V_113 && ! V_2 ) {
* V_101 = NULL ;
return - V_185 ;
}
if ( V_113 ) {
F_68 ( V_106 , V_113 ) ;
V_181 = NULL ;
V_182 = 0 ;
if ( V_106 -> V_186 ) {
V_181 = ( void * ) V_106 -> V_186 ;
V_106 -> V_186 = NULL ;
V_182 = V_106 -> V_183 & V_187 ;
V_106 -> V_183 &= ~ ( V_187 ) ;
}
V_180 = F_69 ( & V_106 , 0 ) ;
if ( V_179 != NULL )
* V_179 = 1 ;
if ( V_181 ) {
V_106 -> V_186 = V_181 ;
V_106 -> V_183 |= V_182 ;
}
if ( V_180 ) {
F_70 ( V_113 ) ;
* V_178 = V_106 ;
* V_101 = NULL ;
return V_180 ;
}
F_71 ( V_106 , V_113 ) ;
V_180 = F_50 ( V_106 , V_98 , V_108 , V_109 , V_110 , V_111 ,
V_112 , & V_113 , & V_2 ) ;
if ( V_180 ) {
* V_178 = V_106 ;
* V_101 = NULL ;
return V_180 ;
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
F_72 (
T_10 * V_106 ,
T_3 * V_2 )
{
int error ;
F_73 ( V_106 , V_2 , V_188 ) ;
ASSERT ( V_2 -> V_3 . V_125 > 0 ) ;
V_2 -> V_3 . V_125 -- ;
F_74 ( F_75 ( V_2 ) ) ;
F_65 ( V_106 , V_2 , V_154 ) ;
error = 0 ;
if ( V_2 -> V_3 . V_125 == 0 ) {
error = F_76 ( V_106 , V_2 ) ;
}
return error ;
}
int
F_77 (
T_10 * V_106 ,
T_3 * V_2 )
{
F_73 ( V_106 , V_2 , V_188 ) ;
ASSERT ( V_2 -> V_3 . V_122 > 1 ) ;
ASSERT ( V_2 -> V_3 . V_125 > 0 || ( F_75 ( V_2 ) -> V_189 & V_190 ) ) ;
V_2 -> V_3 . V_125 ++ ;
F_78 ( F_75 ( V_2 ) ) ;
F_65 ( V_106 , V_2 , V_154 ) ;
return 0 ;
}
int
F_79 (
T_3 * V_98 ,
struct V_99 * V_100 ,
T_11 V_108 ,
T_13 V_110 ,
T_3 * * V_101 )
{
int V_191 = F_58 ( V_108 ) ;
struct V_114 * V_115 = V_98 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_192 * V_106 = NULL ;
int error ;
T_16 V_193 ;
T_17 V_194 ;
bool V_195 = false ;
int V_179 ;
T_14 V_111 ;
struct V_196 * V_197 = NULL ;
struct V_196 * V_198 = NULL ;
struct V_196 * V_199 = NULL ;
struct V_200 * V_201 ;
T_2 V_202 ;
F_80 ( V_98 , V_100 ) ;
if ( F_46 ( V_115 ) )
return - V_104 ;
V_111 = F_81 ( V_98 ) ;
error = F_82 ( V_98 , F_52 ( F_53 () ) ,
F_54 ( F_55 () ) , V_111 ,
V_203 | V_204 ,
& V_197 , & V_198 , & V_199 ) ;
if ( error )
return error ;
if ( V_191 ) {
V_110 = 0 ;
V_202 = F_83 ( V_115 , V_100 -> V_205 ) ;
V_201 = & F_84 ( V_115 ) -> V_206 ;
V_106 = F_85 ( V_115 , V_207 ) ;
} else {
V_202 = F_86 ( V_115 , V_100 -> V_205 ) ;
V_201 = & F_84 ( V_115 ) -> V_208 ;
V_106 = F_85 ( V_115 , V_209 ) ;
}
error = F_87 ( V_106 , V_201 , V_202 , 0 ) ;
if ( error == - V_185 ) {
F_88 ( V_115 ) ;
error = F_87 ( V_106 , V_201 , V_202 , 0 ) ;
}
if ( error == - V_185 ) {
V_202 = 0 ;
error = F_87 ( V_106 , V_201 , 0 , 0 ) ;
}
if ( error )
goto V_210;
F_4 ( V_98 , V_17 | V_211 ) ;
V_195 = true ;
F_89 ( & V_193 , & V_194 ) ;
error = F_90 ( V_106 , V_115 , V_197 , V_198 ,
V_199 , V_202 , 1 , 0 ) ;
if ( error )
goto V_210;
if ( ! V_202 ) {
error = F_91 ( V_106 , V_98 , V_100 ) ;
if ( error )
goto V_210;
}
error = F_67 ( & V_106 , V_98 , V_108 , V_191 ? 2 : 1 , V_110 ,
V_111 , V_202 > 0 , & V_2 , & V_179 ) ;
if ( error ) {
if ( error == - V_185 )
goto V_210;
goto V_210;
}
F_64 ( V_106 , V_98 , V_17 ) ;
V_195 = false ;
error = F_92 ( V_106 , V_98 , V_100 , V_2 -> V_60 ,
& V_194 , & V_193 , V_202 ?
V_202 - F_93 ( V_115 ) : 0 ) ;
if ( error ) {
ASSERT ( error != - V_185 ) ;
goto V_210;
}
F_73 ( V_106 , V_98 , V_212 | V_188 ) ;
F_65 ( V_106 , V_98 , V_154 ) ;
if ( V_191 ) {
error = F_94 ( V_106 , V_2 , V_98 ) ;
if ( error )
goto V_213;
error = F_77 ( V_106 , V_98 ) ;
if ( error )
goto V_213;
}
if ( V_115 -> V_214 & ( V_215 | V_216 ) )
F_95 ( V_106 ) ;
F_96 ( V_106 , V_2 , V_197 , V_198 , V_199 ) ;
error = F_97 ( & V_106 , & V_193 , & V_179 ) ;
if ( error )
goto V_213;
error = F_98 ( V_106 ) ;
if ( error )
goto V_217;
F_99 ( V_197 ) ;
F_99 ( V_198 ) ;
F_99 ( V_199 ) ;
* V_101 = V_2 ;
return 0 ;
V_213:
F_100 ( & V_193 ) ;
V_210:
F_101 ( V_106 ) ;
V_217:
if ( V_2 ) {
F_102 ( V_2 ) ;
F_103 ( V_2 ) ;
}
F_99 ( V_197 ) ;
F_99 ( V_198 ) ;
F_99 ( V_199 ) ;
if ( V_195 )
F_18 ( V_98 , V_17 ) ;
return error ;
}
int
F_104 (
struct V_1 * V_98 ,
struct V_218 * V_218 ,
T_11 V_108 ,
struct V_1 * * V_101 )
{
struct V_114 * V_115 = V_98 -> V_7 ;
struct V_1 * V_2 = NULL ;
struct V_192 * V_106 = NULL ;
int error ;
T_14 V_111 ;
struct V_196 * V_197 = NULL ;
struct V_196 * V_198 = NULL ;
struct V_196 * V_199 = NULL ;
struct V_200 * V_201 ;
T_2 V_202 ;
if ( F_46 ( V_115 ) )
return - V_104 ;
V_111 = F_81 ( V_98 ) ;
error = F_82 ( V_98 , F_52 ( F_53 () ) ,
F_54 ( F_55 () ) , V_111 ,
V_203 | V_204 ,
& V_197 , & V_198 , & V_199 ) ;
if ( error )
return error ;
V_202 = F_93 ( V_115 ) ;
V_106 = F_85 ( V_115 , V_219 ) ;
V_201 = & F_84 ( V_115 ) -> V_220 ;
error = F_87 ( V_106 , V_201 , V_202 , 0 ) ;
if ( error == - V_185 ) {
V_202 = 0 ;
error = F_87 ( V_106 , V_201 , 0 , 0 ) ;
}
if ( error )
goto V_210;
error = F_90 ( V_106 , V_115 , V_197 , V_198 ,
V_199 , V_202 , 1 , 0 ) ;
if ( error )
goto V_210;
error = F_67 ( & V_106 , V_98 , V_108 , 1 , 0 ,
V_111 , V_202 > 0 , & V_2 , NULL ) ;
if ( error ) {
if ( error == - V_185 )
goto V_210;
goto V_210;
}
if ( V_115 -> V_214 & V_215 )
F_95 ( V_106 ) ;
F_96 ( V_106 , V_2 , V_197 , V_198 , V_199 ) ;
V_2 -> V_3 . V_125 -- ;
error = F_76 ( V_106 , V_2 ) ;
if ( error )
goto V_210;
error = F_98 ( V_106 ) ;
if ( error )
goto V_217;
F_99 ( V_197 ) ;
F_99 ( V_198 ) ;
F_99 ( V_199 ) ;
* V_101 = V_2 ;
return 0 ;
V_210:
F_101 ( V_106 ) ;
V_217:
if ( V_2 ) {
F_102 ( V_2 ) ;
F_103 ( V_2 ) ;
}
F_99 ( V_197 ) ;
F_99 ( V_198 ) ;
F_99 ( V_199 ) ;
return error ;
}
int
F_105 (
T_3 * V_221 ,
T_3 * V_222 ,
struct V_99 * V_223 )
{
T_18 * V_115 = V_221 -> V_7 ;
T_10 * V_106 ;
int error ;
T_16 V_193 ;
T_17 V_194 ;
int V_179 ;
int V_202 ;
F_106 ( V_221 , V_223 ) ;
ASSERT ( ! F_58 ( V_222 -> V_3 . V_123 ) ) ;
if ( F_46 ( V_115 ) )
return - V_104 ;
error = F_107 ( V_222 , 0 ) ;
if ( error )
goto V_224;
error = F_107 ( V_221 , 0 ) ;
if ( error )
goto V_224;
V_106 = F_85 ( V_115 , V_225 ) ;
V_202 = F_108 ( V_115 , V_223 -> V_205 ) ;
error = F_87 ( V_106 , & F_84 ( V_115 ) -> V_226 , V_202 , 0 ) ;
if ( error == - V_185 ) {
V_202 = 0 ;
error = F_87 ( V_106 , & F_84 ( V_115 ) -> V_226 , 0 , 0 ) ;
}
if ( error )
goto V_227;
F_29 ( V_222 , V_221 , V_17 ) ;
F_64 ( V_106 , V_222 , V_17 ) ;
F_64 ( V_106 , V_221 , V_17 ) ;
if ( F_109 ( ( V_221 -> V_3 . V_4 & V_84 ) &&
( F_110 ( V_221 ) != F_110 ( V_222 ) ) ) ) {
error = - V_228 ;
goto V_227;
}
if ( ! V_202 ) {
error = F_91 ( V_106 , V_221 , V_223 ) ;
if ( error )
goto V_227;
}
F_89 ( & V_193 , & V_194 ) ;
if ( V_222 -> V_3 . V_125 == 0 ) {
error = F_111 ( V_106 , V_222 ) ;
if ( error )
goto V_227;
}
error = F_92 ( V_106 , V_221 , V_223 , V_222 -> V_60 ,
& V_194 , & V_193 , V_202 ) ;
if ( error )
goto V_227;
F_73 ( V_106 , V_221 , V_212 | V_188 ) ;
F_65 ( V_106 , V_221 , V_154 ) ;
error = F_77 ( V_106 , V_222 ) ;
if ( error )
goto V_227;
if ( V_115 -> V_214 & ( V_215 | V_216 ) ) {
F_95 ( V_106 ) ;
}
error = F_97 ( & V_106 , & V_193 , & V_179 ) ;
if ( error ) {
F_100 ( & V_193 ) ;
goto V_227;
}
return F_98 ( V_106 ) ;
V_227:
F_101 ( V_106 ) ;
V_224:
return error ;
}
int
F_112 (
struct V_192 * * V_178 ,
struct V_1 * V_2 ,
int V_229 ,
T_19 V_230 )
{
struct V_114 * V_115 = V_2 -> V_7 ;
struct V_192 * V_106 = * V_178 ;
T_16 V_193 ;
T_17 V_194 ;
T_20 V_231 ;
T_20 V_232 ;
T_21 V_233 ;
int V_179 ;
int error = 0 ;
int V_234 = 0 ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( ! F_113 ( & F_75 ( V_2 ) -> V_235 ) ||
F_23 ( V_2 , V_23 ) ) ;
ASSERT ( V_230 <= F_114 ( V_2 ) ) ;
ASSERT ( V_106 -> V_183 & V_184 ) ;
ASSERT ( V_2 -> V_49 != NULL ) ;
ASSERT ( V_2 -> V_49 -> V_236 == 0 ) ;
ASSERT ( ! F_115 ( V_115 , V_2 ) ) ;
F_116 ( V_2 , V_230 ) ;
V_231 = F_117 ( V_115 , ( V_237 ) V_230 ) ;
V_232 = F_117 ( V_115 , V_115 -> V_134 -> V_238 ) ;
if ( V_231 == V_232 )
return 0 ;
ASSERT ( V_231 < V_232 ) ;
V_233 = V_232 - V_231 + 1 ;
while ( ! V_234 ) {
F_89 ( & V_193 , & V_194 ) ;
error = F_118 ( V_106 , V_2 ,
V_231 , V_233 ,
F_119 ( V_229 ) ,
V_239 ,
& V_194 , & V_193 ,
& V_234 ) ;
if ( error )
goto V_213;
error = F_97 ( & V_106 , & V_193 , & V_179 ) ;
if ( V_179 )
F_64 ( V_106 , V_2 , 0 ) ;
if ( error )
goto V_213;
error = F_69 ( & V_106 , V_2 ) ;
if ( error )
goto V_31;
}
F_65 ( V_106 , V_2 , V_154 ) ;
F_120 ( V_2 , V_230 ) ;
V_31:
* V_178 = V_106 ;
return error ;
V_213:
F_100 ( & V_193 ) ;
goto V_31;
}
int
F_121 (
T_3 * V_2 )
{
T_18 * V_115 = V_2 -> V_7 ;
int error ;
if ( ! F_63 ( V_2 -> V_3 . V_123 ) || ( V_2 -> V_3 . V_123 == 0 ) )
return 0 ;
if ( V_115 -> V_214 & V_240 )
return 0 ;
if ( ! F_46 ( V_115 ) ) {
int V_241 ;
V_241 = F_122 ( V_2 , V_242 ) ;
if ( V_241 ) {
F_123 ( V_2 , V_243 ) ;
if ( V_2 -> V_244 > 0 ) {
error = F_124 ( F_75 ( V_2 ) -> V_245 ) ;
if ( error )
return error ;
}
}
}
if ( V_2 -> V_3 . V_125 == 0 )
return 0 ;
if ( F_125 ( V_2 , false ) ) {
if ( F_126 ( V_2 , V_243 ) )
return 0 ;
error = F_127 ( V_115 , V_2 , true ) ;
if ( error && error != - V_246 )
return error ;
if ( V_2 -> V_244 )
F_128 ( V_2 , V_243 ) ;
}
return 0 ;
}
STATIC int
F_129 (
struct V_1 * V_2 )
{
struct V_114 * V_115 = V_2 -> V_7 ;
struct V_192 * V_106 ;
int error ;
V_106 = F_85 ( V_115 , V_247 ) ;
error = F_87 ( V_106 , & F_84 ( V_115 ) -> V_248 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_46 ( V_115 ) ) ;
F_101 ( V_106 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_64 ( V_106 , V_2 , 0 ) ;
V_2 -> V_3 . V_131 = 0 ;
F_65 ( V_106 , V_2 , V_154 ) ;
error = F_112 ( & V_106 , V_2 , V_249 , 0 ) ;
if ( error )
goto V_250;
ASSERT ( V_2 -> V_3 . V_132 == 0 ) ;
error = F_98 ( V_106 ) ;
if ( error )
goto V_251;
F_18 ( V_2 , V_17 ) ;
return 0 ;
V_250:
F_101 ( V_106 ) ;
V_251:
F_18 ( V_2 , V_17 ) ;
return error ;
}
STATIC int
F_130 (
struct V_1 * V_2 )
{
T_16 V_193 ;
T_17 V_194 ;
int V_179 ;
struct V_114 * V_115 = V_2 -> V_7 ;
struct V_192 * V_106 ;
int error ;
V_106 = F_85 ( V_115 , V_247 ) ;
V_106 -> V_183 |= V_252 ;
error = F_87 ( V_106 , & F_84 ( V_115 ) -> V_253 ,
F_131 ( V_115 ) , 0 ) ;
if ( error ) {
if ( error == - V_185 ) {
F_132 ( V_115 ,
L_1
L_2 ) ;
} else {
ASSERT ( F_46 ( V_115 ) ) ;
}
F_101 ( V_106 ) ;
return error ;
}
F_4 ( V_2 , V_17 ) ;
F_64 ( V_106 , V_2 , 0 ) ;
F_89 ( & V_193 , & V_194 ) ;
error = F_133 ( V_106 , V_2 , & V_193 ) ;
if ( error ) {
if ( ! F_46 ( V_115 ) ) {
F_134 ( V_115 , L_3 ,
V_254 , error ) ;
F_135 ( V_115 , V_255 ) ;
}
F_101 ( V_106 ) ;
F_18 ( V_2 , V_17 ) ;
return error ;
}
F_136 ( V_106 , V_2 , V_256 , - 1 ) ;
error = F_97 ( & V_106 , & V_193 , & V_179 ) ;
if ( error )
F_134 ( V_115 , L_4 ,
V_254 , error ) ;
error = F_98 ( V_106 ) ;
if ( error )
F_134 ( V_115 , L_5 ,
V_254 , error ) ;
F_18 ( V_2 , V_17 ) ;
return 0 ;
}
void
F_137 (
T_3 * V_2 )
{
struct V_114 * V_115 ;
int error ;
int V_257 = 0 ;
if ( V_2 -> V_3 . V_123 == 0 ) {
ASSERT ( V_2 -> V_14 . V_174 == 0 ) ;
ASSERT ( V_2 -> V_14 . V_258 == 0 ) ;
return;
}
V_115 = V_2 -> V_7 ;
if ( V_115 -> V_214 & V_240 )
return;
if ( V_2 -> V_3 . V_125 != 0 ) {
if ( F_125 ( V_2 , true ) )
F_127 ( V_115 , V_2 , false ) ;
return;
}
if ( F_63 ( V_2 -> V_3 . V_123 ) &&
( V_2 -> V_3 . V_131 != 0 || F_114 ( V_2 ) != 0 ||
V_2 -> V_3 . V_132 > 0 || V_2 -> V_244 > 0 ) )
V_257 = 1 ;
error = F_107 ( V_2 , 0 ) ;
if ( error )
return;
if ( F_138 ( V_2 -> V_3 . V_123 ) )
error = F_139 ( V_2 ) ;
else if ( V_257 )
error = F_129 ( V_2 ) ;
if ( error )
return;
if ( F_40 ( V_2 ) ) {
error = F_140 ( V_2 ) ;
if ( error )
return;
}
ASSERT ( ! V_2 -> V_19 ) ;
ASSERT ( V_2 -> V_3 . V_177 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_259 == 0 ) ;
error = F_130 ( V_2 ) ;
if ( error )
return;
F_141 ( V_2 ) ;
}
int
F_76 (
T_10 * V_106 ,
T_3 * V_2 )
{
T_18 * V_115 ;
T_22 * V_260 ;
T_8 * V_97 ;
T_15 * V_261 ;
T_15 * V_262 ;
T_23 V_263 ;
short V_264 ;
int V_265 ;
int error ;
ASSERT ( V_2 -> V_3 . V_125 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_123 != 0 ) ;
V_115 = V_106 -> V_116 ;
error = F_142 ( V_115 , V_106 , F_143 ( V_115 , V_2 -> V_60 ) , & V_261 ) ;
if ( error )
return error ;
V_260 = F_144 ( V_261 ) ;
V_263 = F_145 ( V_115 , V_2 -> V_60 ) ;
ASSERT ( V_263 != 0 ) ;
V_264 = V_263 % V_266 ;
ASSERT ( V_260 -> V_267 [ V_264 ] ) ;
ASSERT ( F_146 ( V_260 -> V_267 [ V_264 ] ) != V_263 ) ;
if ( V_260 -> V_267 [ V_264 ] != F_147 ( V_268 ) ) {
error = F_148 ( V_115 , V_106 , & V_2 -> V_269 , & V_97 , & V_262 ,
0 , 0 ) ;
if ( error )
return error ;
ASSERT ( V_97 -> V_270 == F_147 ( V_268 ) ) ;
V_97 -> V_270 = V_260 -> V_267 [ V_264 ] ;
V_265 = V_2 -> V_269 . V_271 +
F_149 ( T_8 , V_270 ) ;
F_150 ( V_115 , V_97 ) ;
F_151 ( V_106 , V_262 ) ;
F_152 ( V_106 , V_262 , V_265 ,
( V_265 + sizeof( T_23 ) - 1 ) ) ;
F_153 ( V_115 , V_262 ) ;
}
ASSERT ( V_263 != 0 ) ;
V_260 -> V_267 [ V_264 ] = F_147 ( V_263 ) ;
V_265 = F_149 ( T_22 , V_267 ) +
( sizeof( T_23 ) * V_264 ) ;
F_154 ( V_106 , V_261 , V_272 ) ;
F_152 ( V_106 , V_261 , V_265 ,
( V_265 + sizeof( T_23 ) - 1 ) ) ;
return 0 ;
}
STATIC int
F_111 (
T_10 * V_106 ,
T_3 * V_2 )
{
T_9 V_273 ;
T_18 * V_115 ;
T_22 * V_260 ;
T_8 * V_97 ;
T_15 * V_261 ;
T_15 * V_262 ;
T_24 V_274 ;
T_23 V_263 ;
T_23 V_275 ;
T_15 * V_276 ;
T_8 * V_277 = NULL ;
short V_264 ;
int V_265 , V_278 = 0 ;
int error ;
V_115 = V_106 -> V_116 ;
V_274 = F_143 ( V_115 , V_2 -> V_60 ) ;
error = F_142 ( V_115 , V_106 , V_274 , & V_261 ) ;
if ( error )
return error ;
V_260 = F_144 ( V_261 ) ;
V_263 = F_145 ( V_115 , V_2 -> V_60 ) ;
ASSERT ( V_263 != 0 ) ;
V_264 = V_263 % V_266 ;
ASSERT ( V_260 -> V_267 [ V_264 ] != F_147 ( V_268 ) ) ;
ASSERT ( V_260 -> V_267 [ V_264 ] ) ;
if ( F_146 ( V_260 -> V_267 [ V_264 ] ) == V_263 ) {
error = F_148 ( V_115 , V_106 , & V_2 -> V_269 , & V_97 , & V_262 ,
0 , 0 ) ;
if ( error ) {
F_155 ( V_115 , L_6 ,
V_254 , error ) ;
return error ;
}
V_275 = F_146 ( V_97 -> V_270 ) ;
ASSERT ( V_275 != 0 ) ;
if ( V_275 != V_268 ) {
V_97 -> V_270 = F_147 ( V_268 ) ;
V_265 = V_2 -> V_269 . V_271 +
F_149 ( T_8 , V_270 ) ;
F_150 ( V_115 , V_97 ) ;
F_151 ( V_106 , V_262 ) ;
F_152 ( V_106 , V_262 , V_265 ,
( V_265 + sizeof( T_23 ) - 1 ) ) ;
F_153 ( V_115 , V_262 ) ;
} else {
F_156 ( V_106 , V_262 ) ;
}
ASSERT ( V_275 != 0 ) ;
ASSERT ( V_275 != V_263 ) ;
V_260 -> V_267 [ V_264 ] = F_147 ( V_275 ) ;
V_265 = F_149 ( T_22 , V_267 ) +
( sizeof( T_23 ) * V_264 ) ;
F_154 ( V_106 , V_261 , V_272 ) ;
F_152 ( V_106 , V_261 , V_265 ,
( V_265 + sizeof( T_23 ) - 1 ) ) ;
} else {
V_275 = F_146 ( V_260 -> V_267 [ V_264 ] ) ;
V_276 = NULL ;
while ( V_275 != V_263 ) {
struct V_279 V_280 ;
if ( V_276 )
F_156 ( V_106 , V_276 ) ;
V_280 . V_281 = 0 ;
V_273 = F_157 ( V_115 , V_274 , V_275 ) ;
error = V_279 ( V_115 , V_106 , V_273 , & V_280 , 0 ) ;
if ( error ) {
F_155 ( V_115 ,
L_7 ,
V_254 , error ) ;
return error ;
}
error = F_148 ( V_115 , V_106 , & V_280 , & V_277 ,
& V_276 , 0 , 0 ) ;
if ( error ) {
F_155 ( V_115 ,
L_6 ,
V_254 , error ) ;
return error ;
}
V_278 = V_280 . V_271 ;
V_275 = F_146 ( V_277 -> V_270 ) ;
ASSERT ( V_275 != V_268 ) ;
ASSERT ( V_275 != 0 ) ;
}
error = F_148 ( V_115 , V_106 , & V_2 -> V_269 , & V_97 , & V_262 ,
0 , 0 ) ;
if ( error ) {
F_155 ( V_115 , L_8 ,
V_254 , error ) ;
return error ;
}
V_275 = F_146 ( V_97 -> V_270 ) ;
ASSERT ( V_275 != 0 ) ;
ASSERT ( V_275 != V_263 ) ;
if ( V_275 != V_268 ) {
V_97 -> V_270 = F_147 ( V_268 ) ;
V_265 = V_2 -> V_269 . V_271 +
F_149 ( T_8 , V_270 ) ;
F_150 ( V_115 , V_97 ) ;
F_151 ( V_106 , V_262 ) ;
F_152 ( V_106 , V_262 , V_265 ,
( V_265 + sizeof( T_23 ) - 1 ) ) ;
F_153 ( V_115 , V_262 ) ;
} else {
F_156 ( V_106 , V_262 ) ;
}
V_277 -> V_270 = F_147 ( V_275 ) ;
ASSERT ( V_275 != 0 ) ;
V_265 = V_278 + F_149 ( T_8 , V_270 ) ;
F_150 ( V_115 , V_277 ) ;
F_151 ( V_106 , V_276 ) ;
F_152 ( V_106 , V_276 , V_265 ,
( V_265 + sizeof( T_23 ) - 1 ) ) ;
F_153 ( V_115 , V_276 ) ;
}
return 0 ;
}
STATIC int
F_158 (
T_3 * V_282 ,
T_10 * V_106 ,
struct V_283 * V_284 )
{
T_18 * V_115 = V_282 -> V_7 ;
int V_285 ;
int V_286 ;
int V_287 ;
int V_44 , V_45 ;
int V_288 ;
T_25 V_289 ;
T_15 * V_290 ;
T_3 * V_2 ;
T_26 * V_291 ;
T_4 * V_292 ;
struct V_293 * V_294 ;
T_9 V_103 ;
V_103 = V_284 -> V_295 ;
V_294 = F_159 ( V_115 , F_143 ( V_115 , V_103 ) ) ;
V_285 = F_160 ( V_115 ) ;
V_286 = V_285 << V_115 -> V_8 . V_296 ;
V_287 = V_115 -> V_297 / V_285 ;
for ( V_45 = 0 ; V_45 < V_287 ; V_45 ++ , V_103 += V_286 ) {
V_288 = V_103 - V_284 -> V_295 ;
if ( ( V_284 -> V_298 & F_161 ( V_288 ) ) == 0 ) {
ASSERT ( F_162 ( V_288 , V_286 ) == 0 ) ;
continue;
}
V_289 = F_163 ( V_115 , F_143 ( V_115 , V_103 ) ,
F_164 ( V_115 , V_103 ) ) ;
V_290 = F_165 ( V_106 , V_115 -> V_299 , V_289 ,
V_115 -> V_300 * V_285 ,
V_301 ) ;
if ( ! V_290 )
return - V_302 ;
V_290 -> V_303 = & V_304 ;
V_292 = V_290 -> V_305 ;
while ( V_292 ) {
if ( V_292 -> V_306 == V_307 ) {
V_291 = ( T_26 * ) V_292 ;
ASSERT ( V_291 -> V_308 == 1 ) ;
V_292 -> V_309 = V_310 ;
F_166 ( V_115 -> V_311 ,
& V_291 -> V_312 ,
& V_291 -> V_313 . V_314 ) ;
F_128 ( V_291 -> V_315 , V_316 ) ;
}
V_292 = V_292 -> V_317 ;
}
for ( V_44 = 0 ; V_44 < V_286 ; V_44 ++ ) {
V_318:
F_167 () ;
V_2 = F_168 ( & V_294 -> V_319 ,
F_145 ( V_115 , ( V_103 + V_44 ) ) ) ;
if ( ! V_2 ) {
F_169 () ;
continue;
}
F_170 ( & V_2 -> V_320 ) ;
if ( V_2 -> V_60 != V_103 + V_44 ||
F_171 ( V_2 , V_316 ) ) {
F_172 ( & V_2 -> V_320 ) ;
F_169 () ;
continue;
}
F_172 ( & V_2 -> V_320 ) ;
if ( V_2 != V_282 &&
! F_12 ( V_2 , V_17 ) ) {
F_169 () ;
F_27 ( 1 ) ;
goto V_318;
}
F_169 () ;
F_173 ( V_2 ) ;
F_128 ( V_2 , V_316 ) ;
V_291 = V_2 -> V_49 ;
if ( ! V_291 || F_174 ( V_2 ) ) {
ASSERT ( V_2 != V_282 ) ;
F_175 ( V_2 ) ;
F_18 ( V_2 , V_17 ) ;
continue;
}
V_291 -> V_321 = V_291 -> V_322 ;
V_291 -> V_322 = 0 ;
V_291 -> V_308 = 1 ;
F_166 ( V_115 -> V_311 , & V_291 -> V_312 ,
& V_291 -> V_313 . V_314 ) ;
F_176 ( V_290 , V_310 ,
& V_291 -> V_313 ) ;
if ( V_2 != V_282 )
F_18 ( V_2 , V_17 ) ;
}
F_177 ( V_106 , V_290 ) ;
F_178 ( V_106 , V_290 ) ;
}
F_179 ( V_294 ) ;
return 0 ;
}
int
F_133 (
T_10 * V_106 ,
T_3 * V_2 ,
T_16 * V_323 )
{
int error ;
struct V_283 V_284 = { 0 } ;
ASSERT ( F_23 ( V_2 , V_17 ) ) ;
ASSERT ( V_2 -> V_3 . V_125 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_132 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_177 == 0 ) ;
ASSERT ( V_2 -> V_3 . V_131 == 0 || ! F_63 ( V_2 -> V_3 . V_123 ) ) ;
ASSERT ( V_2 -> V_3 . V_133 == 0 ) ;
error = F_111 ( V_106 , V_2 ) ;
if ( error )
return error ;
error = F_180 ( V_106 , V_2 -> V_60 , V_323 , & V_284 ) ;
if ( error )
return error ;
V_2 -> V_3 . V_123 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_143 = 0 ;
V_2 -> V_3 . V_259 = 0 ;
V_2 -> V_3 . V_12 = V_172 ;
V_2 -> V_3 . V_18 = V_172 ;
V_2 -> V_3 . V_324 ++ ;
F_65 ( V_106 , V_2 , V_154 ) ;
if ( V_284 . V_325 )
error = F_158 ( V_2 , V_106 , & V_284 ) ;
return error ;
}
static void
F_181 (
struct V_1 * V_2 )
{
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
F_182 ( V_2 , V_21 ) ;
F_183 ( V_2 -> V_7 , V_2 -> V_49 -> V_326 , 0 ) ;
}
static void
F_184 (
struct V_1 * V_2 )
{
T_5 * V_61 = F_31 ( & V_2 -> V_62 , V_327 ) ;
F_32 ( V_64 , & V_2 -> V_62 , V_327 ) ;
F_181 ( V_2 ) ;
do {
F_185 ( V_61 , & V_64 . V_64 , V_65 ) ;
if ( F_186 ( V_2 ) )
F_35 () ;
} while ( F_186 ( V_2 ) );
F_37 ( V_61 , & V_64 . V_64 ) ;
}
void
F_187 (
struct V_1 * V_2 )
{
if ( F_186 ( V_2 ) )
F_184 ( V_2 ) ;
}
int
F_188 (
T_3 * V_98 ,
struct V_99 * V_100 ,
T_3 * V_2 )
{
T_18 * V_115 = V_98 -> V_7 ;
T_10 * V_106 = NULL ;
int V_191 = F_58 ( V_2 -> V_3 . V_123 ) ;
int error = 0 ;
T_16 V_193 ;
T_17 V_194 ;
int V_179 ;
T_2 V_202 ;
F_189 ( V_98 , V_100 ) ;
if ( F_46 ( V_115 ) )
return - V_104 ;
error = F_107 ( V_98 , 0 ) ;
if ( error )
goto V_224;
error = F_107 ( V_2 , 0 ) ;
if ( error )
goto V_224;
if ( V_191 )
V_106 = F_85 ( V_115 , V_328 ) ;
else
V_106 = F_85 ( V_115 , V_329 ) ;
V_202 = F_190 ( V_115 ) ;
error = F_87 ( V_106 , & F_84 ( V_115 ) -> V_330 , V_202 , 0 ) ;
if ( error == - V_185 ) {
V_202 = 0 ;
error = F_87 ( V_106 , & F_84 ( V_115 ) -> V_330 , 0 , 0 ) ;
}
if ( error ) {
ASSERT ( error != - V_185 ) ;
goto V_210;
}
F_29 ( V_98 , V_2 , V_17 ) ;
F_64 ( V_106 , V_98 , V_17 ) ;
F_64 ( V_106 , V_2 , V_17 ) ;
if ( V_191 ) {
ASSERT ( V_2 -> V_3 . V_125 >= 2 ) ;
if ( V_2 -> V_3 . V_125 != 2 ) {
error = - V_331 ;
goto V_210;
}
if ( ! F_191 ( V_2 ) ) {
error = - V_331 ;
goto V_210;
}
error = F_72 ( V_106 , V_98 ) ;
if ( error )
goto V_210;
error = F_72 ( V_106 , V_2 ) ;
if ( error )
goto V_210;
} else {
F_65 ( V_106 , V_98 , V_154 ) ;
}
F_73 ( V_106 , V_98 , V_212 | V_188 ) ;
error = F_72 ( V_106 , V_2 ) ;
if ( error )
goto V_210;
F_89 ( & V_193 , & V_194 ) ;
error = F_192 ( V_106 , V_98 , V_100 , V_2 -> V_60 ,
& V_194 , & V_193 , V_202 ) ;
if ( error ) {
ASSERT ( error != - V_332 ) ;
goto V_213;
}
if ( V_115 -> V_214 & ( V_215 | V_216 ) )
F_95 ( V_106 ) ;
error = F_97 ( & V_106 , & V_193 , & V_179 ) ;
if ( error )
goto V_213;
error = F_98 ( V_106 ) ;
if ( error )
goto V_224;
if ( V_191 && F_193 ( V_2 ) )
F_194 ( V_2 ) ;
return 0 ;
V_213:
F_100 ( & V_193 ) ;
V_210:
F_101 ( V_106 ) ;
V_224:
return error ;
}
STATIC void
F_195 (
struct V_1 * V_333 ,
struct V_1 * V_334 ,
struct V_1 * V_58 ,
struct V_1 * V_335 ,
struct V_1 * V_336 ,
struct V_1 * * V_337 ,
int * V_338 )
{
int V_44 , V_45 ;
ASSERT ( * V_338 == V_339 ) ;
memset ( V_337 , 0 , * V_338 * sizeof( struct V_1 * ) ) ;
V_44 = 0 ;
V_337 [ V_44 ++ ] = V_333 ;
V_337 [ V_44 ++ ] = V_334 ;
V_337 [ V_44 ++ ] = V_58 ;
if ( V_335 )
V_337 [ V_44 ++ ] = V_335 ;
if ( V_336 )
V_337 [ V_44 ++ ] = V_336 ;
* V_338 = V_44 ;
for ( V_44 = 0 ; V_44 < * V_338 ; V_44 ++ ) {
for ( V_45 = 1 ; V_45 < * V_338 ; V_45 ++ ) {
if ( V_337 [ V_45 ] -> V_60 < V_337 [ V_45 - 1 ] -> V_60 ) {
struct V_1 * V_59 = V_337 [ V_45 ] ;
V_337 [ V_45 ] = V_337 [ V_45 - 1 ] ;
V_337 [ V_45 - 1 ] = V_59 ;
}
}
}
}
static int
F_196 (
struct V_192 * V_106 ,
struct V_340 * V_193 )
{
int V_179 = 0 ;
int error ;
if ( V_106 -> V_116 -> V_214 & ( V_215 | V_216 ) )
F_95 ( V_106 ) ;
error = F_97 ( & V_106 , V_193 , & V_179 ) ;
if ( error ) {
F_100 ( V_193 ) ;
F_101 ( V_106 ) ;
return error ;
}
return F_98 ( V_106 ) ;
}
STATIC int
F_197 (
struct V_192 * V_106 ,
struct V_1 * V_333 ,
struct V_99 * V_341 ,
struct V_1 * V_58 ,
struct V_1 * V_334 ,
struct V_99 * V_342 ,
struct V_1 * V_335 ,
struct V_340 * V_193 ,
T_17 * V_194 ,
int V_343 )
{
int error = 0 ;
int V_344 = 0 ;
int V_345 = 0 ;
int V_346 = 0 ;
error = F_198 ( V_106 , V_333 , V_341 ,
V_335 -> V_60 ,
V_194 , V_193 , V_343 ) ;
if ( error )
goto V_347;
error = F_198 ( V_106 , V_334 , V_342 ,
V_58 -> V_60 ,
V_194 , V_193 , V_343 ) ;
if ( error )
goto V_347;
if ( V_333 != V_334 ) {
V_346 = V_212 | V_188 ;
if ( F_58 ( V_335 -> V_3 . V_123 ) ) {
error = F_198 ( V_106 , V_335 , & V_348 ,
V_333 -> V_60 , V_194 ,
V_193 , V_343 ) ;
if ( error )
goto V_347;
if ( ! F_58 ( V_58 -> V_3 . V_123 ) ) {
error = F_72 ( V_106 , V_334 ) ;
if ( error )
goto V_347;
error = F_77 ( V_106 , V_333 ) ;
if ( error )
goto V_347;
}
V_344 |= V_188 ;
V_345 |= V_212 | V_188 ;
}
if ( F_58 ( V_58 -> V_3 . V_123 ) ) {
error = F_198 ( V_106 , V_58 , & V_348 ,
V_334 -> V_60 , V_194 ,
V_193 , V_343 ) ;
if ( error )
goto V_347;
if ( ! F_58 ( V_335 -> V_3 . V_123 ) ) {
error = F_72 ( V_106 , V_333 ) ;
if ( error )
goto V_347;
error = F_77 ( V_106 , V_334 ) ;
if ( error )
goto V_347;
}
V_344 |= V_212 | V_188 ;
V_345 |= V_188 ;
}
}
if ( V_344 ) {
F_73 ( V_106 , V_58 , V_344 ) ;
F_65 ( V_106 , V_58 , V_154 ) ;
}
if ( V_345 ) {
F_73 ( V_106 , V_335 , V_345 ) ;
F_65 ( V_106 , V_335 , V_154 ) ;
}
if ( V_346 ) {
F_73 ( V_106 , V_334 , V_346 ) ;
F_65 ( V_106 , V_334 , V_154 ) ;
}
F_73 ( V_106 , V_333 , V_212 | V_188 ) ;
F_65 ( V_106 , V_333 , V_154 ) ;
return F_196 ( V_106 , V_193 ) ;
V_347:
F_100 ( V_193 ) ;
F_101 ( V_106 ) ;
return error ;
}
static int
F_199 (
struct V_1 * V_98 ,
struct V_1 * * V_336 )
{
struct V_1 * tmpfile ;
int error ;
error = F_104 ( V_98 , NULL , V_157 | V_349 , & tmpfile ) ;
if ( error )
return error ;
F_74 ( F_75 ( tmpfile ) ) ;
F_102 ( tmpfile ) ;
F_75 ( tmpfile ) -> V_189 |= V_190 ;
* V_336 = tmpfile ;
return 0 ;
}
int
F_200 (
struct V_1 * V_350 ,
struct V_99 * V_351 ,
struct V_1 * V_352 ,
struct V_1 * V_353 ,
struct V_99 * V_223 ,
struct V_1 * V_354 ,
unsigned int V_66 )
{
struct V_114 * V_115 = V_350 -> V_7 ;
struct V_192 * V_106 ;
struct V_340 V_193 ;
T_17 V_194 ;
struct V_1 * V_336 = NULL ;
struct V_1 * V_42 [ V_339 ] ;
int V_338 = V_339 ;
bool V_355 = ( V_350 != V_353 ) ;
bool V_356 = F_58 ( V_352 -> V_3 . V_123 ) ;
int V_343 ;
int error ;
F_201 ( V_350 , V_353 , V_351 , V_223 ) ;
if ( ( V_66 & V_357 ) && ! V_354 )
return - V_358 ;
if ( V_66 & V_359 ) {
ASSERT ( ! ( V_66 & ( V_360 | V_357 ) ) ) ;
error = F_199 ( V_353 , & V_336 ) ;
if ( error )
return error ;
V_351 -> type = V_361 ;
}
F_195 ( V_350 , V_353 , V_352 , V_354 , V_336 ,
V_42 , & V_338 ) ;
V_106 = F_85 ( V_115 , V_362 ) ;
V_343 = F_202 ( V_115 , V_223 -> V_205 ) ;
error = F_87 ( V_106 , & F_84 ( V_115 ) -> V_363 , V_343 , 0 ) ;
if ( error == - V_185 ) {
V_343 = 0 ;
error = F_87 ( V_106 , & F_84 ( V_115 ) -> V_363 , 0 , 0 ) ;
}
if ( error )
goto V_210;
error = F_203 ( V_42 ) ;
if ( error )
goto V_210;
F_26 ( V_42 , V_338 , V_17 ) ;
F_64 ( V_106 , V_350 , V_17 ) ;
if ( V_355 )
F_64 ( V_106 , V_353 , V_17 ) ;
F_64 ( V_106 , V_352 , V_17 ) ;
if ( V_354 )
F_64 ( V_106 , V_354 , V_17 ) ;
if ( V_336 )
F_64 ( V_106 , V_336 , V_17 ) ;
if ( F_109 ( ( V_353 -> V_3 . V_4 & V_84 ) &&
( F_110 ( V_353 ) != F_110 ( V_352 ) ) ) ) {
error = - V_228 ;
goto V_210;
}
F_89 ( & V_193 , & V_194 ) ;
if ( V_66 & V_357 )
return F_197 ( V_106 , V_350 , V_351 , V_352 ,
V_353 , V_223 , V_354 ,
& V_193 , & V_194 , V_343 ) ;
if ( V_354 == NULL ) {
if ( ! V_343 ) {
error = F_91 ( V_106 , V_353 , V_223 ) ;
if ( error )
goto V_210;
}
error = F_92 ( V_106 , V_353 , V_223 ,
V_352 -> V_60 , & V_194 ,
& V_193 , V_343 ) ;
if ( error )
goto V_213;
F_73 ( V_106 , V_353 ,
V_212 | V_188 ) ;
if ( V_355 && V_356 ) {
error = F_77 ( V_106 , V_353 ) ;
if ( error )
goto V_213;
}
} else {
if ( F_58 ( V_354 -> V_3 . V_123 ) ) {
if ( ! ( F_191 ( V_354 ) ) ||
( V_354 -> V_3 . V_125 > 2 ) ) {
error = - V_364 ;
goto V_210;
}
}
error = F_198 ( V_106 , V_353 , V_223 ,
V_352 -> V_60 ,
& V_194 , & V_193 , V_343 ) ;
if ( error )
goto V_213;
F_73 ( V_106 , V_353 ,
V_212 | V_188 ) ;
error = F_72 ( V_106 , V_354 ) ;
if ( error )
goto V_213;
if ( V_356 ) {
error = F_72 ( V_106 , V_354 ) ;
if ( error )
goto V_213;
}
}
if ( V_355 && V_356 ) {
error = F_198 ( V_106 , V_352 , & V_348 ,
V_353 -> V_60 ,
& V_194 , & V_193 , V_343 ) ;
ASSERT ( error != - V_364 ) ;
if ( error )
goto V_213;
}
F_73 ( V_106 , V_352 , V_188 ) ;
F_65 ( V_106 , V_352 , V_154 ) ;
if ( V_356 && ( V_355 || V_354 != NULL ) ) {
error = F_72 ( V_106 , V_350 ) ;
if ( error )
goto V_213;
}
if ( V_336 ) {
error = F_198 ( V_106 , V_350 , V_351 , V_336 -> V_60 ,
& V_194 , & V_193 , V_343 ) ;
} else
error = F_192 ( V_106 , V_350 , V_351 , V_352 -> V_60 ,
& V_194 , & V_193 , V_343 ) ;
if ( error )
goto V_213;
if ( V_336 ) {
ASSERT ( F_75 ( V_336 ) -> V_365 == 0 && V_336 -> V_3 . V_125 == 0 ) ;
error = F_77 ( V_106 , V_336 ) ;
if ( error )
goto V_213;
error = F_111 ( V_106 , V_336 ) ;
if ( error )
goto V_213;
F_65 ( V_106 , V_336 , V_154 ) ;
F_75 ( V_336 ) -> V_189 &= ~ V_190 ;
}
F_73 ( V_106 , V_350 , V_212 | V_188 ) ;
F_65 ( V_106 , V_350 , V_154 ) ;
if ( V_355 )
F_65 ( V_106 , V_353 , V_154 ) ;
error = F_196 ( V_106 , & V_193 ) ;
if ( V_336 )
F_103 ( V_336 ) ;
return error ;
V_213:
F_100 ( & V_193 ) ;
V_210:
F_101 ( V_106 ) ;
if ( V_336 )
F_103 ( V_336 ) ;
return error ;
}
STATIC int
F_204 (
T_3 * V_2 ,
T_15 * V_290 )
{
T_18 * V_115 = V_2 -> V_7 ;
struct V_293 * V_294 ;
unsigned long V_366 , V_367 ;
unsigned long V_286 ;
int V_368 ;
T_3 * * V_369 ;
T_3 * V_370 ;
int V_371 ;
int V_372 = 0 ;
int V_373 ;
int V_44 ;
V_294 = F_159 ( V_115 , F_143 ( V_115 , V_2 -> V_60 ) ) ;
V_286 = V_115 -> V_374 >> V_115 -> V_8 . V_375 ;
V_368 = V_286 * sizeof( T_3 * ) ;
V_369 = F_205 ( V_368 , V_376 | V_377 ) ;
if ( ! V_369 )
goto V_378;
V_367 = ~ ( ( ( V_115 -> V_374 >> V_115 -> V_8 . V_375 ) ) - 1 ) ;
V_366 = F_145 ( V_115 , V_2 -> V_60 ) & V_367 ;
F_167 () ;
V_371 = F_206 ( & V_294 -> V_319 , ( void * * ) V_369 ,
V_366 , V_286 ) ;
if ( V_371 == 0 )
goto V_379;
for ( V_44 = 0 ; V_44 < V_371 ; V_44 ++ ) {
V_370 = V_369 [ V_44 ] ;
if ( V_370 == V_2 )
continue;
F_170 ( & V_2 -> V_320 ) ;
if ( ! V_2 -> V_60 ||
( F_145 ( V_115 , V_370 -> V_60 ) & V_367 ) != V_366 ) {
F_172 ( & V_2 -> V_320 ) ;
continue;
}
F_172 ( & V_2 -> V_320 ) ;
if ( F_174 ( V_370 ) && F_186 ( V_370 ) == 0 )
continue;
if ( ! F_12 ( V_370 , V_11 ) )
continue;
if ( ! F_36 ( V_370 ) ) {
F_18 ( V_370 , V_11 ) ;
continue;
}
if ( F_186 ( V_370 ) ) {
F_175 ( V_370 ) ;
F_18 ( V_370 , V_11 ) ;
continue;
}
if ( ! F_174 ( V_370 ) ) {
int error ;
error = F_207 ( V_370 , V_290 ) ;
if ( error ) {
F_18 ( V_370 , V_11 ) ;
goto V_380;
}
V_372 ++ ;
} else {
F_175 ( V_370 ) ;
}
F_18 ( V_370 , V_11 ) ;
}
if ( V_372 ) {
F_208 ( V_381 ) ;
F_209 ( V_382 , V_372 ) ;
}
V_379:
F_169 () ;
F_49 ( V_369 ) ;
V_378:
F_179 ( V_294 ) ;
return 0 ;
V_380:
F_169 () ;
V_373 = ( V_290 -> V_383 & V_384 ) ;
if ( V_373 )
F_70 ( V_290 ) ;
F_135 ( V_115 , V_385 ) ;
if ( ! V_373 ) {
if ( V_290 -> V_386 ) {
F_210 ( V_290 ) ;
F_211 ( V_290 ) ;
F_212 ( V_290 , - V_104 ) ;
F_213 ( V_290 ) ;
} else {
F_211 ( V_290 ) ;
F_70 ( V_290 ) ;
}
}
F_214 ( V_370 , false ) ;
F_49 ( V_369 ) ;
F_179 ( V_294 ) ;
return - V_387 ;
}
int
F_215 (
struct V_1 * V_2 ,
struct V_388 * * V_389 )
{
struct V_114 * V_115 = V_2 -> V_7 ;
struct V_388 * V_290 ;
struct V_390 * V_97 ;
int error ;
F_208 ( V_391 ) ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_34 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_132 > F_216 ( V_2 , V_249 ) ) ;
* V_389 = NULL ;
F_187 ( V_2 ) ;
if ( F_126 ( V_2 , V_316 ) ) {
F_175 ( V_2 ) ;
return 0 ;
}
if ( F_46 ( V_115 ) ) {
error = - V_104 ;
goto V_392;
}
error = F_148 ( V_115 , NULL , & V_2 -> V_269 , & V_97 , & V_290 , V_393 ,
0 ) ;
if ( error || ! V_290 ) {
F_175 ( V_2 ) ;
return error ;
}
error = F_207 ( V_2 , V_290 ) ;
if ( error )
goto V_394;
if ( F_217 ( V_290 ) )
F_218 ( V_115 , 0 ) ;
error = F_204 ( V_2 , V_290 ) ;
if ( error )
goto V_380;
* V_389 = V_290 ;
return 0 ;
V_394:
F_70 ( V_290 ) ;
F_135 ( V_115 , V_385 ) ;
V_380:
error = - V_387 ;
V_392:
F_214 ( V_2 , false ) ;
return error ;
}
STATIC int
F_207 (
struct V_1 * V_2 ,
struct V_388 * V_290 )
{
struct V_395 * V_291 = V_2 -> V_49 ;
struct V_390 * V_97 ;
struct V_114 * V_115 = V_2 -> V_7 ;
ASSERT ( F_23 ( V_2 , V_17 | V_11 ) ) ;
ASSERT ( F_34 ( V_2 ) ) ;
ASSERT ( V_2 -> V_3 . V_12 != V_13 ||
V_2 -> V_3 . V_132 > F_216 ( V_2 , V_249 ) ) ;
ASSERT ( V_291 != NULL && V_291 -> V_322 != 0 ) ;
ASSERT ( V_2 -> V_3 . V_122 > 1 ) ;
V_97 = F_219 ( V_290 , V_2 -> V_269 . V_271 ) ;
if ( F_220 ( V_97 -> V_396 != F_221 ( V_397 ) ,
V_115 , V_398 , V_399 ) ) {
F_222 ( V_115 , V_400 ,
L_9 ,
V_254 , V_2 -> V_60 , F_42 ( V_97 -> V_396 ) , V_97 ) ;
goto V_394;
}
if ( F_220 ( V_2 -> V_3 . V_396 != V_397 ,
V_115 , V_401 , V_402 ) ) {
F_222 ( V_115 , V_400 ,
L_10 ,
V_254 , V_2 -> V_60 , V_2 , V_2 -> V_3 . V_396 ) ;
goto V_394;
}
if ( F_63 ( V_2 -> V_3 . V_123 ) ) {
if ( F_220 (
( V_2 -> V_3 . V_12 != V_172 ) &&
( V_2 -> V_3 . V_12 != V_13 ) ,
V_115 , V_403 , V_404 ) ) {
F_222 ( V_115 , V_400 ,
L_11 ,
V_254 , V_2 -> V_60 , V_2 ) ;
goto V_394;
}
} else if ( F_58 ( V_2 -> V_3 . V_123 ) ) {
if ( F_220 (
( V_2 -> V_3 . V_12 != V_172 ) &&
( V_2 -> V_3 . V_12 != V_13 ) &&
( V_2 -> V_3 . V_12 != V_405 ) ,
V_115 , V_406 , V_407 ) ) {
F_222 ( V_115 , V_400 ,
L_12 ,
V_254 , V_2 -> V_60 , V_2 ) ;
goto V_394;
}
}
if ( F_220 ( V_2 -> V_3 . V_132 + V_2 -> V_3 . V_177 >
V_2 -> V_3 . V_133 , V_115 , V_408 ,
V_409 ) ) {
F_222 ( V_115 , V_400 ,
L_13
L_14 ,
V_254 , V_2 -> V_60 ,
V_2 -> V_3 . V_132 + V_2 -> V_3 . V_177 ,
V_2 -> V_3 . V_133 , V_2 ) ;
goto V_394;
}
if ( F_220 ( V_2 -> V_3 . V_259 > V_115 -> V_8 . V_410 ,
V_115 , V_411 , V_412 ) ) {
F_222 ( V_115 , V_400 ,
L_15 ,
V_254 , V_2 -> V_60 , V_2 -> V_3 . V_259 , V_2 ) ;
goto V_394;
}
if ( V_2 -> V_3 . V_122 < 3 )
V_2 -> V_3 . V_413 ++ ;
F_223 ( V_97 , & V_2 -> V_3 ) ;
if ( V_2 -> V_3 . V_413 == V_414 )
V_2 -> V_3 . V_413 = 0 ;
F_224 ( V_2 , V_97 , V_291 , V_249 ) ;
if ( F_40 ( V_2 ) )
F_224 ( V_2 , V_97 , V_291 , V_415 ) ;
F_153 ( V_115 , V_290 ) ;
V_291 -> V_321 = V_291 -> V_322 ;
V_291 -> V_322 = 0 ;
V_291 -> V_308 = 1 ;
F_166 ( V_115 -> V_311 , & V_291 -> V_312 ,
& V_291 -> V_313 . V_314 ) ;
F_176 ( V_290 , V_416 , & V_291 -> V_313 ) ;
if ( V_2 -> V_3 . V_122 == 3 )
V_97 -> V_150 = F_225 ( V_291 -> V_313 . V_314 ) ;
F_150 ( V_115 , V_97 ) ;
ASSERT ( V_290 -> V_305 != NULL ) ;
ASSERT ( V_290 -> V_386 != NULL ) ;
return 0 ;
V_394:
return - V_387 ;
}
