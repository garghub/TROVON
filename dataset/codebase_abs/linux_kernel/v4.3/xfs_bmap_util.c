T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return ( F_2 ( V_2 ) ? \
( T_1 ) F_3 ( ( V_2 ) -> V_4 , ( V_3 ) ) : \
F_4 ( ( V_2 ) -> V_4 , ( V_3 ) ) ) ;
}
int
F_5 (
struct V_5 * * V_6 ,
struct V_7 * V_8 ,
int * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int error ;
struct V_14 * free ;
struct V_14 * V_15 ;
ASSERT ( ( * V_6 ) -> V_16 & V_17 ) ;
if ( V_8 -> V_18 == 0 ) {
* V_9 = 0 ;
return 0 ;
}
V_13 = F_6 ( * V_6 , V_8 -> V_18 ) ;
for ( free = V_8 -> V_19 ; free ; free = free -> V_20 )
F_7 ( * V_6 , V_13 , free -> V_21 ,
free -> V_22 ) ;
error = F_8 ( V_6 , NULL , V_9 ) ;
if ( error ) {
if ( * V_9 ) {
F_9 ( V_13 ) ;
F_10 ( ( * V_6 ) -> V_23 ,
( error == - V_24 ) ?
V_25 :
V_26 ) ;
} else {
* V_9 = 1 ;
}
return error ;
}
V_11 = F_11 ( * V_6 , V_13 , V_8 -> V_18 ) ;
for ( free = V_8 -> V_19 ; free != NULL ; free = V_15 ) {
V_15 = free -> V_20 ;
error = F_12 ( * V_6 , V_11 , free -> V_21 ,
free -> V_22 ) ;
if ( error )
return error ;
F_13 ( V_8 , NULL , free ) ;
}
return 0 ;
}
int
F_14 (
struct V_27 * V_28 )
{
T_3 V_29 = 0 ;
int error ;
T_4 * V_30 ;
T_5 V_31 = 0 ;
T_5 V_32 = 0 ;
T_5 V_33 ;
T_6 V_34 ;
V_30 = V_28 -> V_2 -> V_4 ;
V_33 = F_15 ( V_28 -> V_2 ) ;
V_31 = V_33 / V_30 -> V_35 . V_36 ;
error = F_16 ( V_30 , & V_28 -> V_37 , & V_28 -> V_38 ,
V_33 , 1 , V_28 -> V_39 , 0 ,
V_28 -> V_40 , & V_28 -> V_41 , & V_28 -> V_42 ) ;
if ( error )
return error ;
ASSERT ( V_28 -> V_42 ) ;
ASSERT ( V_28 -> V_42 % V_30 -> V_35 . V_36 == 0 ) ;
if ( F_17 ( V_28 -> V_41 , V_33 ) || V_28 -> V_42 % V_33 )
V_31 = 1 ;
V_32 = V_28 -> V_42 / V_30 -> V_35 . V_36 ;
if ( V_32 * V_30 -> V_35 . V_36 >= V_43 )
V_32 = V_43 / V_30 -> V_35 . V_36 ;
F_18 ( V_30 -> V_44 , V_45 ) ;
F_19 ( V_28 -> V_6 , V_30 -> V_44 , V_45 ) ;
if ( V_28 -> V_39 && V_28 -> V_41 == 0 ) {
T_6 V_46 ( V_47 ) ;
error = F_20 ( V_30 , V_28 -> V_6 , V_32 , & V_47 ) ;
if ( error )
return error ;
V_28 -> V_48 = V_47 * V_30 -> V_35 . V_36 ;
} else {
V_28 -> V_48 = 0 ;
}
F_21 ( V_28 ) ;
V_29 = V_28 -> V_48 == 0 ? V_49 : V_50 ;
F_22 ( V_28 -> V_48 , V_30 -> V_35 . V_36 ) ;
V_34 = V_28 -> V_48 ;
V_28 -> V_42 = V_32 ;
if ( ( error = F_23 ( V_28 -> V_6 , V_28 -> V_48 , 1 , V_28 -> V_42 ,
& V_32 , V_29 , V_28 -> V_51 , V_31 , & V_34 ) ) )
return error ;
if ( V_34 == V_52 && V_31 > 1 &&
( error = F_23 ( V_28 -> V_6 , V_28 -> V_48 , 1 ,
V_28 -> V_42 , & V_32 , V_29 ,
V_28 -> V_51 , 1 , & V_34 ) ) )
return error ;
V_28 -> V_48 = V_34 ;
if ( V_28 -> V_48 != V_52 ) {
V_28 -> V_48 *= V_30 -> V_35 . V_36 ;
V_32 *= V_30 -> V_35 . V_36 ;
V_28 -> V_42 = V_32 ;
V_28 -> V_2 -> V_53 . V_54 += V_32 ;
F_24 ( V_28 -> V_6 , V_28 -> V_2 , V_55 ) ;
if ( V_28 -> V_51 )
V_28 -> V_2 -> V_56 -= V_32 ;
F_25 ( V_28 -> V_6 , V_28 -> V_2 ,
V_28 -> V_51 ? V_57 :
V_58 , ( long ) V_32 ) ;
} else {
V_28 -> V_42 = 0 ;
}
return 0 ;
}
int
F_26 (
struct V_1 * V_2 ,
T_7 V_59 ,
int V_60 ,
int * V_39 )
{
struct V_61 V_62 ;
int error ;
error = F_27 ( NULL , V_2 , V_60 , & V_62 , V_39 ) ;
if ( error || * V_39 )
return error ;
* V_39 = V_59 >= V_62 . V_63 + V_62 . V_64 ;
return 0 ;
}
STATIC void
F_28 (
T_8 * V_65 ,
T_9 V_66 ,
int V_67 ,
int * V_68 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_67 ; V_69 ++ ) {
T_10 * V_70 = F_29 ( V_65 , V_66 + V_69 ) ;
* V_68 += F_30 ( V_70 ) ;
}
}
STATIC void
F_31 (
struct V_71 * V_30 ,
struct V_72 * V_73 ,
int V_67 ,
int * V_68 )
{
int V_69 ;
T_11 * V_70 ;
for ( V_69 = 1 ; V_69 <= V_67 ; V_69 ++ ) {
V_70 = F_32 ( V_30 , V_73 , V_69 ) ;
* V_68 += F_33 ( V_70 ) ;
}
}
STATIC int
F_34 (
T_4 * V_30 ,
T_12 * V_6 ,
T_8 * V_65 ,
T_2 V_74 ,
int V_75 ,
int * V_68 )
{
int error ;
T_13 * V_76 , * V_77 ;
int V_78 = V_75 ;
T_14 * V_79 ;
T_2 V_80 = V_74 ;
T_2 V_81 ;
struct V_72 * V_73 , * V_82 ;
int V_67 ;
error = F_35 ( V_30 , V_6 , V_80 , 0 , & V_76 , V_83 ,
& V_84 ) ;
if ( error )
return error ;
* V_68 += 1 ;
V_73 = F_36 ( V_76 ) ;
if ( -- V_78 ) {
V_81 = F_37 ( V_73 -> V_85 . V_86 . V_87 ) ;
while ( V_81 != V_52 ) {
error = F_35 ( V_30 , V_6 , V_81 , 0 , & V_77 ,
V_83 ,
& V_84 ) ;
if ( error )
return error ;
* V_68 += 1 ;
V_82 = F_36 ( V_77 ) ;
V_81 = F_37 ( V_82 -> V_85 . V_86 . V_87 ) ;
F_38 ( V_6 , V_77 ) ;
}
V_79 = F_39 ( V_30 , V_73 , 1 , V_30 -> V_88 [ 1 ] ) ;
V_80 = F_37 ( * V_79 ) ;
if ( F_40 ( ( error =
F_34 ( V_30 , V_6 , V_65 , V_80 , V_78 , V_68 ) ) < 0 ) ) {
F_38 ( V_6 , V_76 ) ;
F_41 ( L_1 ,
V_89 , V_30 ) ;
return - V_24 ;
}
F_38 ( V_6 , V_76 ) ;
} else {
for (; ; ) {
V_81 = F_37 ( V_73 -> V_85 . V_86 . V_87 ) ;
V_67 = F_42 ( V_73 -> V_90 ) ;
F_31 ( V_30 , V_73 , V_67 , V_68 ) ;
F_38 ( V_6 , V_76 ) ;
if ( V_81 == V_52 )
break;
V_80 = V_81 ;
error = F_35 ( V_30 , V_6 , V_80 , 0 , & V_76 ,
V_83 ,
& V_84 ) ;
if ( error )
return error ;
* V_68 += 1 ;
V_73 = F_36 ( V_76 ) ;
}
}
return 0 ;
}
int
F_43 (
T_12 * V_6 ,
T_15 * V_2 ,
int V_60 ,
int * V_68 )
{
struct V_72 * V_73 ;
T_2 V_80 ;
T_8 * V_65 ;
int V_78 ;
T_4 * V_30 ;
T_14 * V_79 ;
V_80 = V_52 ;
V_30 = V_2 -> V_4 ;
V_65 = F_44 ( V_2 , V_60 ) ;
if ( F_45 ( V_2 , V_60 ) == V_91 ) {
F_28 ( V_65 , 0 ,
V_65 -> V_92 / ( V_93 ) sizeof( T_11 ) ,
V_68 ) ;
return 0 ;
}
V_73 = V_65 -> V_94 ;
V_78 = F_42 ( V_73 -> V_95 ) ;
ASSERT ( V_78 > 0 ) ;
V_79 = F_46 ( V_30 , V_73 , 1 , V_65 -> V_96 ) ;
V_80 = F_37 ( * V_79 ) ;
ASSERT ( V_80 != V_52 ) ;
ASSERT ( F_47 ( V_30 , V_80 ) < V_30 -> V_35 . V_97 ) ;
ASSERT ( F_48 ( V_30 , V_80 ) < V_30 -> V_35 . V_98 ) ;
if ( F_40 ( F_34 ( V_30 , V_6 , V_65 , V_80 , V_78 , V_68 ) < 0 ) ) {
F_41 ( L_2 , V_89 ,
V_30 ) ;
return - V_24 ;
}
return 0 ;
}
STATIC int
F_49 (
T_15 * V_2 ,
struct V_99 * V_100 ,
int V_101 ,
T_16 V_102 ,
T_2 V_103 )
{
T_16 V_104 ;
T_4 * V_30 ;
T_8 * V_65 ;
T_9 V_105 ;
T_7 V_106 ;
if ( V_103 == V_107 ) {
V_30 = V_2 -> V_4 ;
V_100 -> V_108 = - 1 ;
V_104 = F_3 ( V_30 , F_50 ( V_30 , F_51 ( V_2 ) ) ) ;
V_104 -= V_100 -> V_109 ;
if ( V_101 && V_100 -> V_109 + V_100 -> V_110 == V_102 ) {
if ( V_104 <= 0 )
return 0 ;
V_100 -> V_110 = V_104 ;
}
} else {
if ( V_103 == V_111 )
V_100 -> V_108 = - 2 ;
else
V_100 -> V_108 = F_1 ( V_2 , V_103 ) ;
V_106 = F_52 ( V_2 -> V_4 , V_100 -> V_109 ) ;
V_65 = F_44 ( V_2 , V_112 ) ;
if ( F_53 ( V_65 , V_106 , & V_105 ) &&
( V_105 == ( V_65 -> V_92 / ( V_93 ) sizeof( T_11 ) ) - 1 ) )
V_100 -> V_113 |= V_114 ;
}
return 1 ;
}
int
F_54 (
T_15 * V_2 ,
struct V_99 * V_115 ,
T_17 V_116 ,
void * V_117 )
{
T_16 V_118 ;
int error = 0 ;
T_16 V_104 ;
int V_119 ;
int V_120 ;
T_18 * V_121 ;
T_4 * V_30 ;
int V_122 ;
int V_123 ;
int V_124 ;
int V_125 ;
struct V_99 * V_100 ;
int V_60 ;
int V_101 ;
int V_126 ;
int V_127 ;
int V_128 = 0 ;
V_30 = V_2 -> V_4 ;
V_126 = V_115 -> V_129 ;
V_60 = V_126 & V_130 ? V_131 : V_112 ;
if ( V_60 == V_131 ) {
if ( F_55 ( V_2 ) ) {
if ( V_2 -> V_53 . V_132 != V_91 &&
V_2 -> V_53 . V_132 != V_133 &&
V_2 -> V_53 . V_132 != V_134 )
return - V_135 ;
} else if ( F_40 (
V_2 -> V_53 . V_132 != 0 &&
V_2 -> V_53 . V_132 != V_91 ) ) {
F_41 ( L_3 , V_89 ,
V_2 -> V_4 ) ;
return - V_24 ;
}
V_101 = 0 ;
V_104 = 1LL << 32 ;
} else {
if ( V_2 -> V_53 . V_136 != V_91 &&
V_2 -> V_53 . V_136 != V_133 &&
V_2 -> V_53 . V_136 != V_134 )
return - V_135 ;
if ( F_15 ( V_2 ) ||
V_2 -> V_53 . V_137 & ( V_138 | V_139 ) ) {
V_101 = 1 ;
V_104 = V_30 -> V_140 -> V_141 ;
} else {
V_101 = 0 ;
V_104 = F_51 ( V_2 ) ;
}
}
if ( V_115 -> V_110 == - 1 ) {
V_104 = F_3 ( V_30 , F_50 ( V_30 , V_104 ) ) ;
V_115 -> V_110 =
F_56 ( T_16 , V_104 - V_115 -> V_109 , 0 ) ;
} else if ( V_115 -> V_110 == 0 ) {
V_115 -> V_142 = 0 ;
return 0 ;
} else if ( V_115 -> V_110 < 0 ) {
return - V_135 ;
}
V_122 = V_115 -> V_143 - 1 ;
if ( V_122 <= 0 )
return - V_135 ;
V_118 = V_115 -> V_109 + V_115 -> V_110 ;
if ( V_115 -> V_143 > V_144 / sizeof( struct V_99 ) )
return - V_145 ;
V_100 = F_57 ( V_115 -> V_143 * sizeof( struct V_99 ) , 0 ) ;
if ( ! V_100 )
return - V_145 ;
F_18 ( V_2 , V_146 ) ;
if ( V_60 == V_112 ) {
if ( ! ( V_126 & V_147 ) &&
( V_2 -> V_56 || F_51 ( V_2 ) > V_2 -> V_53 . V_148 ) ) {
error = F_58 ( F_59 ( V_2 ) -> V_149 ) ;
if ( error )
goto V_150;
}
V_120 = F_60 ( V_2 ) ;
} else {
V_120 = F_61 ( V_2 ) ;
}
if ( V_122 > F_62 ( V_2 , V_60 ) * 2 + 1 )
V_122 = F_62 ( V_2 , V_60 ) * 2 + 1 ;
V_127 = F_63 ( V_60 ) ;
if ( ! ( V_126 & V_151 ) )
V_127 |= V_152 ;
error = - V_145 ;
V_124 = 16 ;
V_121 = F_64 ( V_124 * sizeof( * V_121 ) , V_153 | V_154 ) ;
if ( ! V_121 )
goto V_155;
V_115 -> V_142 = 0 ;
if ( F_62 ( V_2 , V_60 ) == 0 &&
( V_60 == V_131 || ! ( V_126 & V_147 ) ) ) {
error = 0 ;
goto V_156;
}
V_123 = V_122 ;
do {
V_125 = ( V_123 > V_124 ) ? V_124 : V_123 ;
error = F_65 ( V_2 , F_66 ( V_30 , V_115 -> V_109 ) ,
F_52 ( V_30 , V_115 -> V_110 ) ,
V_121 , & V_125 , V_127 ) ;
if ( error )
goto V_156;
ASSERT ( V_125 <= V_124 ) ;
for ( V_119 = 0 ; V_119 < V_125 && V_123 && V_115 -> V_110 ; V_119 ++ ) {
V_100 [ V_128 ] . V_113 = 0 ;
if ( V_121 [ V_119 ] . V_157 == V_158 )
V_100 [ V_128 ] . V_113 |= V_159 ;
else if ( V_121 [ V_119 ] . V_160 == V_111 )
V_100 [ V_128 ] . V_113 |= V_161 ;
V_100 [ V_128 ] . V_109 =
F_3 ( V_30 , V_121 [ V_119 ] . V_63 ) ;
V_100 [ V_128 ] . V_110 =
F_3 ( V_30 , V_121 [ V_119 ] . V_64 ) ;
V_100 [ V_128 ] . V_162 = 0 ;
V_100 [ V_128 ] . V_163 = 0 ;
if ( V_121 [ V_119 ] . V_160 == V_111 &&
V_121 [ V_119 ] . V_63 <= F_50 ( V_30 , F_51 ( V_2 ) ) )
ASSERT ( ( V_126 & V_147 ) != 0 ) ;
if ( V_121 [ V_119 ] . V_160 == V_107 &&
V_60 == V_131 ) {
V_100 [ V_128 ] . V_113 |= V_114 ;
goto V_156;
}
if ( ! F_49 ( V_2 , & V_100 [ V_128 ] ,
V_101 , V_118 ,
V_121 [ V_119 ] . V_160 ) )
goto V_156;
V_115 -> V_109 =
V_100 [ V_128 ] . V_109 +
V_100 [ V_128 ] . V_110 ;
V_115 -> V_110 =
F_56 ( T_16 , 0 , V_118 - V_115 -> V_109 ) ;
if ( ( V_126 & V_164 ) &&
V_121 [ V_119 ] . V_160 == V_107 ) {
memset ( & V_100 [ V_128 ] , 0 , sizeof( V_100 [ V_128 ] ) ) ;
continue;
}
V_123 -- ;
V_115 -> V_142 ++ ;
V_128 ++ ;
}
} while ( V_125 && V_123 && V_115 -> V_110 );
V_156:
F_67 ( V_121 ) ;
V_155:
F_68 ( V_2 , V_120 ) ;
V_150:
F_68 ( V_2 , V_146 ) ;
for ( V_119 = 0 ; V_119 < V_128 ; V_119 ++ ) {
int V_165 = 0 ;
error = V_116 ( & V_117 , & V_100 [ V_119 ] , & V_165 ) ;
if ( error || V_165 )
break;
}
F_67 ( V_100 ) ;
return error ;
}
int
F_69 (
struct V_1 * V_2 ,
T_7 V_166 ,
T_7 V_42 )
{
T_7 V_167 = V_42 ;
int error = 0 ;
ASSERT ( F_70 ( V_2 , V_45 ) ) ;
do {
int V_168 ;
T_18 V_169 ;
int V_170 = 1 ;
T_2 V_171 ;
T_19 V_8 ;
error = F_65 ( V_2 , V_166 , 1 , & V_169 , & V_170 ,
V_172 ) ;
if ( error ) {
if ( ! F_71 ( V_2 -> V_4 ) ) {
F_72 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_173 , V_166 ) ;
}
break;
}
if ( ! V_170 ) {
goto V_174;
}
if ( V_169 . V_160 != V_111 ) {
goto V_174;
}
F_73 ( V_169 . V_64 == 0 ) ;
F_74 ( & V_8 , & V_171 ) ;
error = F_75 ( NULL , V_2 , V_166 , 1 , 0 , 1 , & V_171 ,
& V_8 , & V_168 ) ;
if ( error )
break;
ASSERT ( ! V_8 . V_18 && ! V_8 . V_19 ) ;
V_174:
V_166 ++ ;
V_167 -- ;
} while( V_167 > 0 );
return error ;
}
bool
F_76 ( struct V_1 * V_2 , bool V_175 )
{
if ( ! F_77 ( V_2 -> V_53 . V_176 ) )
return false ;
if ( F_59 ( V_2 ) -> V_177 == 0 &&
F_59 ( V_2 ) -> V_149 -> V_178 == 0 &&
V_2 -> V_56 == 0 )
return false ;
if ( ! ( V_2 -> V_179 . V_180 & V_181 ) )
return false ;
if ( V_2 -> V_53 . V_137 & ( V_138 | V_139 ) )
if ( ! V_175 || V_2 -> V_56 == 0 )
return false ;
return true ;
}
int
F_78 (
T_4 * V_30 ,
T_15 * V_2 ,
bool V_182 )
{
T_12 * V_6 ;
int error ;
T_7 V_183 ;
T_7 V_184 ;
T_20 V_185 ;
int V_170 ;
T_18 V_169 ;
V_183 = F_50 ( V_30 , ( V_186 ) F_51 ( V_2 ) ) ;
V_184 = F_50 ( V_30 , V_30 -> V_140 -> V_141 ) ;
if ( V_184 <= V_183 )
return 0 ;
V_185 = V_184 - V_183 ;
V_170 = 1 ;
F_18 ( V_2 , V_187 ) ;
error = F_65 ( V_2 , V_183 , V_185 , & V_169 , & V_170 , 0 ) ;
F_68 ( V_2 , V_187 ) ;
if ( ! error && ( V_170 != 0 ) &&
( V_169 . V_160 != V_107 ||
V_2 -> V_56 ) ) {
error = F_79 ( V_2 , 0 ) ;
if ( error )
return error ;
V_6 = F_80 ( V_30 , V_188 ) ;
if ( V_182 ) {
if ( ! F_81 ( V_2 , V_189 ) ) {
F_82 ( V_6 ) ;
return - V_190 ;
}
}
error = F_83 ( V_6 , & F_84 ( V_30 ) -> V_191 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_71 ( V_30 ) ) ;
F_82 ( V_6 ) ;
if ( V_182 )
F_68 ( V_2 , V_189 ) ;
return error ;
}
F_18 ( V_2 , V_45 ) ;
F_19 ( V_6 , V_2 , 0 ) ;
error = F_85 ( & V_6 , V_2 , V_112 ,
F_51 ( V_2 ) ) ;
if ( error ) {
F_82 ( V_6 ) ;
} else {
error = F_86 ( V_6 ) ;
if ( ! error )
F_87 ( V_2 ) ;
}
F_68 ( V_2 , V_45 ) ;
if ( V_182 )
F_68 ( V_2 , V_189 ) ;
}
return error ;
}
int
F_88 (
struct V_1 * V_2 ,
T_21 V_41 ,
T_21 V_192 ,
int V_193 )
{
T_4 * V_30 = V_2 -> V_4 ;
T_21 V_68 ;
T_20 V_194 ;
T_20 V_195 ;
T_5 V_196 , V_197 ;
T_7 V_198 ;
T_2 V_199 ;
int V_170 ;
int V_200 ;
int V_201 ;
T_12 * V_6 ;
T_18 V_202 [ 1 ] , * V_203 ;
T_19 V_204 ;
V_93 V_205 , V_206 , V_207 ;
int V_9 ;
int error ;
F_89 ( V_2 ) ;
if ( F_71 ( V_30 ) )
return - V_208 ;
error = F_79 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_192 <= 0 )
return - V_135 ;
V_201 = F_2 ( V_2 ) ;
V_196 = F_15 ( V_2 ) ;
V_68 = V_192 ;
V_203 = & V_202 [ 0 ] ;
V_170 = 1 ;
V_198 = F_90 ( V_30 , V_41 ) ;
V_195 = F_50 ( V_30 , V_68 ) ;
while ( V_195 && ! error ) {
T_7 V_209 , V_210 ;
if ( F_40 ( V_196 ) ) {
V_209 = V_198 ;
F_22 ( V_209 , V_196 ) ;
V_209 *= V_196 ;
V_210 = V_198 + V_195 ;
if ( ( V_197 = F_17 ( V_198 , V_196 ) ) )
V_210 += V_197 ;
if ( ( V_197 = F_17 ( V_210 , V_196 ) ) )
V_210 += V_196 - V_197 ;
} else {
V_209 = 0 ;
V_210 = V_195 ;
}
V_206 = F_91 ( T_7 , ( V_210 - V_209 ) , ( V_43 * V_170 ) ) ;
if ( F_40 ( V_201 ) ) {
V_207 = V_205 = V_206 ;
V_207 /= V_30 -> V_35 . V_36 ;
V_206 = F_92 ( V_30 , 0 ) ;
V_200 = V_211 ;
} else {
V_207 = 0 ;
V_206 = V_205 = F_92 ( V_30 , V_206 ) ;
V_200 = V_212 ;
}
V_6 = F_80 ( V_30 , V_213 ) ;
error = F_83 ( V_6 , & F_84 ( V_30 ) -> V_214 ,
V_206 , V_207 ) ;
if ( error ) {
ASSERT ( error == - V_215 || F_71 ( V_30 ) ) ;
F_82 ( V_6 ) ;
break;
}
F_18 ( V_2 , V_45 ) ;
error = F_93 ( V_6 , V_2 , V_205 ,
0 , V_200 ) ;
if ( error )
goto V_216;
F_19 ( V_6 , V_2 , 0 ) ;
F_74 ( & V_204 , & V_199 ) ;
error = F_94 ( V_6 , V_2 , V_198 ,
V_195 , V_193 , & V_199 ,
0 , V_203 , & V_170 , & V_204 ) ;
if ( error ) {
goto V_217;
}
error = F_5 ( & V_6 , & V_204 , & V_9 ) ;
if ( error ) {
goto V_217;
}
error = F_86 ( V_6 ) ;
F_68 ( V_2 , V_45 ) ;
if ( error ) {
break;
}
V_194 = V_203 -> V_64 ;
if ( V_170 == 0 ) {
error = - V_215 ;
break;
}
V_198 += V_194 ;
V_195 -= V_194 ;
}
return error ;
V_217:
F_95 ( & V_204 ) ;
F_96 ( V_6 , V_2 , ( long ) V_205 , 0 , V_200 ) ;
V_216:
F_82 ( V_6 ) ;
F_68 ( V_2 , V_45 ) ;
return error ;
}
STATIC int
F_97 (
T_15 * V_2 ,
T_21 V_218 ,
T_21 V_59 )
{
T_18 V_169 ;
T_7 V_219 ;
T_21 V_220 ;
T_21 V_41 ;
T_13 * V_76 ;
T_4 * V_30 = V_2 -> V_4 ;
int V_221 ;
int error = 0 ;
if ( V_218 >= F_51 ( V_2 ) )
return 0 ;
if ( V_59 > F_51 ( V_2 ) )
V_59 = F_51 ( V_2 ) ;
for ( V_41 = V_218 ; V_41 <= V_59 ; V_41 = V_220 + 1 ) {
V_93 V_222 ;
V_219 = F_90 ( V_30 , V_41 ) ;
V_221 = 1 ;
V_222 = F_60 ( V_2 ) ;
error = F_65 ( V_2 , V_219 , 1 , & V_169 , & V_221 , 0 ) ;
F_68 ( V_2 , V_222 ) ;
if ( error || V_221 < 1 )
break;
ASSERT ( V_169 . V_64 >= 1 ) ;
ASSERT ( V_169 . V_63 == V_219 ) ;
ASSERT ( V_169 . V_160 != V_111 ) ;
if ( V_169 . V_160 == V_107 ||
V_169 . V_157 == V_158 ) {
V_220 = F_98 ( V_30 , V_169 . V_63 +
V_169 . V_64 ) - 1 ;
continue;
}
V_220 = F_98 ( V_30 , V_169 . V_63 + 1 ) - 1 ;
if ( V_220 > V_59 )
V_220 = V_59 ;
if ( F_99 ( F_59 ( V_2 ) ) ) {
error = F_100 ( F_59 ( V_2 ) , V_41 ,
V_220 - V_41 + 1 ,
V_223 ) ;
if ( error )
return error ;
continue;
}
error = F_101 ( F_2 ( V_2 ) ?
V_30 -> V_224 : V_30 -> V_225 ,
F_1 ( V_2 , V_169 . V_160 ) ,
F_102 ( V_30 -> V_35 . V_226 ) ,
0 , & V_76 , NULL ) ;
if ( error )
return error ;
memset ( V_76 -> V_227 +
( V_41 - F_98 ( V_30 , V_169 . V_63 ) ) ,
0 , V_220 - V_41 + 1 ) ;
error = F_103 ( V_76 ) ;
F_104 ( V_76 ) ;
if ( error )
return error ;
}
return error ;
}
int
F_105 (
struct V_1 * V_2 ,
T_21 V_41 ,
T_21 V_192 )
{
int V_9 ;
int V_168 ;
T_7 V_228 ;
int error ;
T_2 V_199 ;
T_19 V_204 ;
T_18 V_169 ;
T_21 V_229 ;
T_21 V_230 ;
T_5 V_231 = 0 ;
T_4 * V_30 ;
int V_221 ;
V_93 V_206 ;
T_21 V_232 ;
int V_201 ;
T_7 V_198 ;
T_12 * V_6 ;
V_30 = V_2 -> V_4 ;
F_106 ( V_2 ) ;
error = F_79 ( V_2 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_192 <= 0 )
return error ;
V_201 = F_2 ( V_2 ) ;
V_198 = F_50 ( V_30 , V_41 ) ;
V_228 = F_90 ( V_30 , V_41 + V_192 ) ;
F_107 ( F_59 ( V_2 ) ) ;
V_232 = F_56 ( T_21 , 1 << V_30 -> V_35 . V_233 , V_234 ) ;
V_229 = F_108 ( V_41 , V_232 ) ;
V_230 = F_109 ( V_41 + V_192 , V_232 ) - 1 ;
error = F_110 ( F_59 ( V_2 ) -> V_149 , V_229 ,
V_230 ) ;
if ( error )
goto V_100;
F_111 ( F_59 ( V_2 ) , V_229 , V_230 ) ;
if ( V_201 && ! F_112 ( & V_30 -> V_35 ) ) {
V_221 = 1 ;
error = F_65 ( V_2 , V_198 , 1 ,
& V_169 , & V_221 , 0 ) ;
if ( error )
goto V_100;
ASSERT ( V_221 == 0 || V_221 == 1 ) ;
if ( V_221 && V_169 . V_160 != V_107 ) {
T_1 V_73 ;
ASSERT ( V_169 . V_160 != V_111 ) ;
V_73 = V_169 . V_160 ;
V_231 = F_22 ( V_73 , V_30 -> V_35 . V_36 ) ;
if ( V_231 )
V_198 += V_30 -> V_35 . V_36 - V_231 ;
}
V_221 = 1 ;
error = F_65 ( V_2 , V_228 - 1 , 1 ,
& V_169 , & V_221 , 0 ) ;
if ( error )
goto V_100;
ASSERT ( V_221 == 0 || V_221 == 1 ) ;
if ( V_221 && V_169 . V_160 != V_107 ) {
ASSERT ( V_169 . V_160 != V_111 ) ;
V_231 ++ ;
if ( V_231 && ( V_231 != V_30 -> V_35 . V_36 ) )
V_228 -= V_231 ;
}
}
if ( ( V_168 = ( V_228 <= V_198 ) ) )
error = F_97 ( V_2 , V_41 , V_41 + V_192 - 1 ) ;
else {
if ( V_41 < F_98 ( V_30 , V_198 ) )
error = F_97 ( V_2 , V_41 ,
F_98 ( V_30 , V_198 ) - 1 ) ;
if ( ! error &&
F_98 ( V_30 , V_228 ) < V_41 + V_192 )
error = F_97 ( V_2 ,
F_98 ( V_30 , V_228 ) ,
V_41 + V_192 - 1 ) ;
}
V_206 = F_92 ( V_30 , 0 ) ;
while ( ! error && ! V_168 ) {
V_6 = F_80 ( V_30 , V_213 ) ;
error = F_83 ( V_6 , & F_84 ( V_30 ) -> V_214 , V_206 , 0 ) ;
if ( error ) {
ASSERT ( error == - V_215 || F_71 ( V_30 ) ) ;
F_82 ( V_6 ) ;
break;
}
F_18 ( V_2 , V_45 ) ;
error = F_113 ( V_6 , V_30 ,
V_2 -> V_235 , V_2 -> V_236 , V_2 -> V_237 ,
V_206 , 0 , V_212 ) ;
if ( error )
goto V_216;
F_19 ( V_6 , V_2 , 0 ) ;
F_74 ( & V_204 , & V_199 ) ;
error = F_75 ( V_6 , V_2 , V_198 ,
V_228 - V_198 ,
0 , 2 , & V_199 , & V_204 , & V_168 ) ;
if ( error ) {
goto V_217;
}
error = F_5 ( & V_6 , & V_204 , & V_9 ) ;
if ( error ) {
goto V_217;
}
error = F_86 ( V_6 ) ;
F_68 ( V_2 , V_45 ) ;
}
V_100:
return error ;
V_217:
F_95 ( & V_204 ) ;
V_216:
F_82 ( V_6 ) ;
F_68 ( V_2 , V_45 ) ;
goto V_100;
}
int
F_114 (
struct V_1 * V_2 ,
T_21 V_41 ,
T_21 V_192 )
{
struct V_71 * V_30 = V_2 -> V_4 ;
V_93 V_238 ;
int error ;
F_115 ( V_2 ) ;
V_238 = 1 << V_30 -> V_35 . V_233 ;
error = F_105 ( V_2 , V_41 , V_192 ) ;
if ( error )
goto V_100;
error = F_88 ( V_2 , F_108 ( V_41 , V_238 ) ,
F_109 ( V_41 + V_192 , V_238 ) -
F_108 ( V_41 , V_238 ) ,
V_239 ) ;
V_100:
return error ;
}
static int
F_116 (
struct V_1 * V_2 ,
T_21 V_41 ,
T_21 V_192 ,
enum V_240 V_241 )
{
int V_168 = 0 ;
struct V_71 * V_30 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int error ;
struct V_7 V_204 ;
T_2 V_242 ;
int V_9 ;
T_7 V_243 ;
T_7 V_244 ;
T_7 V_245 ;
ASSERT ( V_241 == V_246 || V_241 == V_247 ) ;
if ( V_241 == V_246 ) {
V_244 = F_50 ( V_30 , V_41 + V_192 ) ;
V_243 = F_50 ( V_30 , F_59 ( V_2 ) -> V_177 ) ;
} else {
V_244 = V_52 ;
V_243 = F_50 ( V_30 , V_41 ) ;
}
V_245 = F_50 ( V_30 , V_192 ) ;
if ( F_76 ( V_2 , true ) ) {
error = F_78 ( V_30 , V_2 , false ) ;
if ( error )
return error ;
}
error = F_110 ( F_59 ( V_2 ) -> V_149 ,
V_41 , - 1 ) ;
if ( error )
return error ;
error = F_117 ( F_59 ( V_2 ) -> V_149 ,
V_41 >> V_248 , - 1 ) ;
if ( error )
return error ;
if ( V_241 == V_247 ) {
error = F_118 ( V_2 , V_243 ) ;
if ( error )
return error ;
}
while ( ! error && ! V_168 ) {
V_6 = F_80 ( V_30 , V_213 ) ;
error = F_83 ( V_6 , & F_84 ( V_30 ) -> V_214 ,
F_92 ( V_30 , 0 ) , 0 ) ;
if ( error ) {
F_82 ( V_6 ) ;
break;
}
F_18 ( V_2 , V_45 ) ;
error = F_113 ( V_6 , V_30 , V_2 -> V_235 ,
V_2 -> V_236 , V_2 -> V_237 ,
F_92 ( V_30 , 0 ) , 0 ,
V_212 ) ;
if ( error )
goto V_249;
F_19 ( V_6 , V_2 , V_45 ) ;
F_74 ( & V_204 , & V_242 ) ;
error = F_119 ( V_6 , V_2 , & V_244 , V_245 ,
& V_168 , V_243 , & V_242 , & V_204 ,
V_241 , V_250 ) ;
if ( error )
goto V_251;
error = F_5 ( & V_6 , & V_204 , & V_9 ) ;
if ( error )
goto V_251;
error = F_86 ( V_6 ) ;
}
return error ;
V_251:
F_95 ( & V_204 ) ;
V_249:
F_82 ( V_6 ) ;
return error ;
}
int
F_120 (
struct V_1 * V_2 ,
T_21 V_41 ,
T_21 V_192 )
{
int error ;
ASSERT ( F_70 ( V_2 , V_189 ) ) ;
F_121 ( V_2 ) ;
error = F_105 ( V_2 , V_41 , V_192 ) ;
if ( error )
return error ;
return F_116 ( V_2 , V_41 , V_192 , V_246 ) ;
}
int
F_122 (
struct V_1 * V_2 ,
T_22 V_41 ,
T_22 V_192 )
{
ASSERT ( F_70 ( V_2 , V_189 ) ) ;
F_123 ( V_2 ) ;
return F_116 ( V_2 , V_41 , V_192 , V_247 ) ;
}
static int
F_124 (
T_15 * V_2 ,
T_15 * V_252 )
{
if ( V_2 -> V_53 . V_136 == V_134 ||
V_252 -> V_53 . V_136 == V_134 )
return - V_135 ;
if ( V_2 -> V_53 . V_253 < V_252 -> V_53 . V_253 )
return - V_135 ;
if ( V_2 -> V_53 . V_136 == V_91 &&
V_252 -> V_53 . V_136 == V_133 )
return - V_135 ;
if ( V_252 -> V_53 . V_136 == V_91 &&
F_62 ( V_252 , V_112 ) >
F_125 ( V_2 , V_112 ) )
return - V_135 ;
if ( V_2 -> V_53 . V_136 == V_91 &&
F_62 ( V_2 , V_112 ) >
F_125 ( V_252 , V_112 ) )
return - V_135 ;
if ( V_252 -> V_53 . V_136 == V_133 ) {
if ( F_126 ( V_2 ) &&
F_127 ( V_252 -> V_179 . V_94 ) > F_126 ( V_2 ) )
return - V_135 ;
if ( F_62 ( V_252 , V_112 ) <=
F_125 ( V_2 , V_112 ) )
return - V_135 ;
}
if ( V_2 -> V_53 . V_136 == V_133 ) {
if ( F_126 ( V_252 ) &&
F_127 ( V_2 -> V_179 . V_94 ) > F_126 ( V_252 ) )
return - V_135 ;
if ( F_62 ( V_2 , V_112 ) <=
F_125 ( V_252 , V_112 ) )
return - V_135 ;
}
return 0 ;
}
static int
F_128 (
struct V_1 * V_2 )
{
int error ;
error = F_58 ( F_59 ( V_2 ) -> V_149 ) ;
if ( error )
return error ;
F_111 ( F_59 ( V_2 ) , 0 , - 1 ) ;
if ( F_59 ( V_2 ) -> V_149 -> V_178 )
return - V_135 ;
return 0 ;
}
int
F_129 (
T_15 * V_2 ,
T_15 * V_252 ,
T_23 * V_254 )
{
T_4 * V_30 = V_2 -> V_4 ;
T_12 * V_6 ;
T_24 * V_255 = & V_254 -> V_256 ;
T_8 * V_257 , * V_65 , * V_258 ;
int V_259 , V_260 ;
int error = 0 ;
int V_261 = 0 ;
int V_262 = 0 ;
T_25 V_263 ;
int V_264 ;
V_257 = F_64 ( sizeof( T_8 ) , V_153 ) ;
if ( ! V_257 ) {
error = - V_145 ;
goto V_100;
}
V_264 = V_189 | V_265 ;
F_130 ( V_2 , V_252 , V_189 ) ;
F_130 ( V_2 , V_252 , V_265 ) ;
if ( ( V_2 -> V_53 . V_176 & V_266 ) != ( V_252 -> V_53 . V_176 & V_266 ) ) {
error = - V_135 ;
goto V_267;
}
if ( F_2 ( V_2 ) != F_2 ( V_252 ) ) {
error = - V_135 ;
goto V_267;
}
error = F_128 ( V_2 ) ;
if ( error )
goto V_267;
error = F_128 ( V_252 ) ;
if ( error )
goto V_267;
V_6 = F_80 ( V_30 , V_268 ) ;
error = F_83 ( V_6 , & F_84 ( V_30 ) -> V_269 , 0 , 0 ) ;
if ( error ) {
F_82 ( V_6 ) ;
goto V_267;
}
F_130 ( V_2 , V_252 , V_45 ) ;
V_264 |= V_45 ;
F_19 ( V_6 , V_2 , V_264 ) ;
F_19 ( V_6 , V_252 , V_264 ) ;
if ( V_254 -> V_270 != 0 ||
V_254 -> V_271 != V_2 -> V_53 . V_148 ||
V_254 -> V_271 != V_252 -> V_53 . V_148 ) {
error = - V_272 ;
goto V_249;
}
F_131 ( V_2 , 0 ) ;
F_131 ( V_252 , 1 ) ;
error = F_124 ( V_2 , V_252 ) ;
if ( error ) {
F_132 ( V_30 ,
L_5 ,
V_273 , V_2 -> V_173 ) ;
goto V_249;
}
if ( ( V_255 -> V_274 . V_275 != F_59 ( V_2 ) -> V_276 . V_275 ) ||
( V_255 -> V_274 . V_277 != F_59 ( V_2 ) -> V_276 . V_277 ) ||
( V_255 -> V_278 . V_275 != F_59 ( V_2 ) -> V_279 . V_275 ) ||
( V_255 -> V_278 . V_277 != F_59 ( V_2 ) -> V_279 . V_277 ) ) {
error = - V_280 ;
goto V_249;
}
if ( ( ( F_55 ( V_2 ) != 0 ) && ( V_2 -> V_53 . V_281 > 0 ) ) &&
( V_2 -> V_53 . V_132 != V_134 ) ) {
error = F_43 ( V_6 , V_2 , V_131 , & V_261 ) ;
if ( error )
goto V_249;
}
if ( ( ( F_55 ( V_252 ) != 0 ) && ( V_252 -> V_53 . V_281 > 0 ) ) &&
( V_252 -> V_53 . V_132 != V_134 ) ) {
error = F_43 ( V_6 , V_252 , V_131 ,
& V_262 ) ;
if ( error )
goto V_249;
}
V_259 = V_55 ;
V_260 = V_55 ;
if ( V_2 -> V_53 . V_282 == 3 &&
V_2 -> V_53 . V_136 == V_133 ) {
V_260 |= V_283 ;
error = F_133 ( V_6 , V_2 , V_112 ,
V_252 -> V_173 , NULL ) ;
if ( error )
goto V_249;
}
if ( V_252 -> V_53 . V_282 == 3 &&
V_252 -> V_53 . V_136 == V_133 ) {
V_259 |= V_283 ;
error = F_133 ( V_6 , V_252 , V_112 ,
V_2 -> V_173 , NULL ) ;
if ( error )
goto V_249;
}
V_65 = & V_2 -> V_179 ;
V_258 = & V_252 -> V_179 ;
* V_257 = * V_65 ;
* V_65 = * V_258 ;
* V_258 = * V_257 ;
V_263 = ( T_25 ) V_2 -> V_53 . V_54 ;
V_2 -> V_53 . V_54 = V_252 -> V_53 . V_54 - V_262 + V_261 ;
V_252 -> V_53 . V_54 = V_263 + V_262 - V_261 ;
V_263 = ( T_25 ) V_2 -> V_53 . V_253 ;
V_2 -> V_53 . V_253 = V_252 -> V_53 . V_253 ;
V_252 -> V_53 . V_253 = V_263 ;
V_263 = ( T_25 ) V_2 -> V_53 . V_136 ;
V_2 -> V_53 . V_136 = V_252 -> V_53 . V_136 ;
V_252 -> V_53 . V_136 = V_263 ;
ASSERT ( V_252 -> V_56 == 0 ) ;
V_252 -> V_56 = V_2 -> V_56 ;
V_2 -> V_56 = 0 ;
switch ( V_2 -> V_53 . V_136 ) {
case V_91 :
if ( V_2 -> V_53 . V_253 <= V_284 ) {
V_65 -> V_285 . V_286 =
V_65 -> V_287 . V_288 ;
}
V_259 |= V_289 ;
break;
case V_133 :
ASSERT ( V_2 -> V_53 . V_282 < 3 ||
( V_259 & V_283 ) ) ;
V_259 |= V_290 ;
break;
}
switch ( V_252 -> V_53 . V_136 ) {
case V_91 :
if ( V_252 -> V_53 . V_253 <= V_284 ) {
V_258 -> V_285 . V_286 =
V_258 -> V_287 . V_288 ;
}
V_260 |= V_289 ;
break;
case V_133 :
V_260 |= V_290 ;
ASSERT ( V_252 -> V_53 . V_282 < 3 ||
( V_260 & V_283 ) ) ;
break;
}
F_24 ( V_6 , V_2 , V_259 ) ;
F_24 ( V_6 , V_252 , V_260 ) ;
if ( V_30 -> V_291 & V_292 )
F_134 ( V_6 ) ;
error = F_86 ( V_6 ) ;
F_135 ( V_2 , 0 ) ;
F_135 ( V_252 , 1 ) ;
V_100:
F_67 ( V_257 ) ;
return error ;
V_267:
F_68 ( V_2 , V_264 ) ;
F_68 ( V_252 , V_264 ) ;
goto V_100;
V_249:
F_82 ( V_6 ) ;
goto V_100;
}
