T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return ( F_2 ( V_2 ) ? \
( T_1 ) F_3 ( ( V_2 ) -> V_4 , ( V_3 ) ) : \
F_4 ( ( V_2 ) -> V_4 , ( V_3 ) ) ) ;
}
int
F_5 (
T_3 * * V_5 ,
T_4 * V_6 ,
int * V_7 )
{
T_5 * V_8 ;
T_6 * V_9 ;
int error ;
T_7 * free ;
struct V_10 V_11 ;
T_8 * V_12 ;
T_7 * V_13 ;
T_3 * V_14 ;
ASSERT ( ( * V_5 ) -> V_15 & V_16 ) ;
if ( V_6 -> V_17 == 0 ) {
* V_7 = 0 ;
return 0 ;
}
V_14 = * V_5 ;
V_9 = F_6 ( V_14 , V_6 -> V_17 ) ;
for ( free = V_6 -> V_18 ; free ; free = free -> V_19 )
F_7 ( V_14 , V_9 , free -> V_20 ,
free -> V_21 ) ;
V_11 . V_22 = V_14 -> V_23 ;
V_11 . V_24 = V_14 -> V_25 ;
V_11 . V_26 = V_16 ;
V_14 = F_8 ( * V_5 ) ;
error = F_9 ( * V_5 , 0 ) ;
* V_5 = V_14 ;
* V_7 = 1 ;
if ( error )
return error ;
F_10 ( V_14 -> V_27 ) ;
error = F_11 ( V_14 , & V_11 , 0 , 0 ) ;
if ( error )
return error ;
V_8 = F_12 ( V_14 , V_9 , V_6 -> V_17 ) ;
for ( free = V_6 -> V_18 ; free != NULL ; free = V_13 ) {
V_13 = free -> V_19 ;
if ( ( error = F_13 ( V_14 , free -> V_20 ,
free -> V_21 ) ) ) {
V_12 = V_14 -> V_28 ;
if ( ! F_14 ( V_12 ) )
F_15 ( V_12 ,
( error == V_29 ) ?
V_30 :
V_31 ) ;
return error ;
}
F_16 ( V_14 , V_8 , free -> V_20 ,
free -> V_21 ) ;
F_17 ( V_6 , NULL , free ) ;
}
return 0 ;
}
int
F_18 (
struct V_32 * V_33 )
{
T_9 V_34 = 0 ;
int error ;
T_8 * V_12 ;
T_10 V_35 = 0 ;
T_10 V_36 = 0 ;
T_10 V_37 ;
T_11 V_38 ;
V_12 = V_33 -> V_2 -> V_4 ;
V_37 = F_19 ( V_33 -> V_2 ) ;
V_35 = V_37 / V_12 -> V_39 . V_40 ;
error = F_20 ( V_12 , & V_33 -> V_41 , & V_33 -> V_42 ,
V_37 , 1 , V_33 -> V_43 , 0 ,
V_33 -> V_44 , & V_33 -> V_45 , & V_33 -> V_46 ) ;
if ( error )
return error ;
ASSERT ( V_33 -> V_46 ) ;
ASSERT ( V_33 -> V_46 % V_12 -> V_39 . V_40 == 0 ) ;
if ( F_21 ( V_33 -> V_45 , V_37 ) || V_33 -> V_46 % V_37 )
V_35 = 1 ;
V_36 = V_33 -> V_46 / V_12 -> V_39 . V_40 ;
if ( V_36 * V_12 -> V_39 . V_40 >= V_47 )
V_36 = V_47 / V_12 -> V_39 . V_40 ;
F_22 ( V_12 -> V_48 , V_49 ) ;
F_23 ( V_33 -> V_5 , V_12 -> V_48 , V_49 ) ;
if ( V_33 -> V_43 && V_33 -> V_45 == 0 ) {
T_11 V_50 ( V_51 ) ;
error = F_24 ( V_12 , V_33 -> V_5 , V_36 , & V_51 ) ;
if ( error )
return error ;
V_33 -> V_52 = V_51 * V_12 -> V_39 . V_40 ;
} else {
V_33 -> V_52 = 0 ;
}
F_25 ( V_33 ) ;
V_34 = V_33 -> V_52 == 0 ? V_53 : V_54 ;
F_26 ( V_33 -> V_52 , V_12 -> V_39 . V_40 ) ;
V_38 = V_33 -> V_52 ;
V_33 -> V_46 = V_36 ;
if ( ( error = F_27 ( V_33 -> V_5 , V_33 -> V_52 , 1 , V_33 -> V_46 ,
& V_36 , V_34 , V_33 -> V_55 , V_35 , & V_38 ) ) )
return error ;
if ( V_38 == V_56 && V_35 > 1 &&
( error = F_27 ( V_33 -> V_5 , V_33 -> V_52 , 1 ,
V_33 -> V_46 , & V_36 , V_34 ,
V_33 -> V_55 , 1 , & V_38 ) ) )
return error ;
V_33 -> V_52 = V_38 ;
if ( V_33 -> V_52 != V_56 ) {
V_33 -> V_52 *= V_12 -> V_39 . V_40 ;
V_36 *= V_12 -> V_39 . V_40 ;
V_33 -> V_46 = V_36 ;
V_33 -> V_2 -> V_57 . V_58 += V_36 ;
F_28 ( V_33 -> V_5 , V_33 -> V_2 , V_59 ) ;
if ( V_33 -> V_55 )
V_33 -> V_2 -> V_60 -= V_36 ;
F_29 ( V_33 -> V_5 , V_33 -> V_2 ,
V_33 -> V_55 ? V_61 :
V_62 , ( long ) V_36 ) ;
} else {
V_33 -> V_46 = 0 ;
}
return 0 ;
}
static void
F_30 (
struct V_63 * V_64 )
{
struct V_32 * args = F_31 ( V_64 ,
struct V_32 , V_64 ) ;
unsigned long V_65 ;
F_32 ( & V_65 , V_66 ) ;
args -> V_67 = F_33 ( args ) ;
F_34 ( args -> V_68 ) ;
F_35 ( & V_65 , V_66 ) ;
}
int
F_36 (
struct V_32 * args )
{
F_37 ( V_68 ) ;
if ( ! args -> V_69 )
return F_33 ( args ) ;
args -> V_68 = & V_68 ;
F_38 ( & args -> V_64 , F_30 ) ;
F_39 ( V_70 , & args -> V_64 ) ;
F_40 ( & V_68 ) ;
return args -> V_67 ;
}
int
F_41 (
struct V_1 * V_2 ,
T_12 V_71 ,
int V_72 ,
int * V_43 )
{
struct V_73 V_74 ;
int error ;
error = F_42 ( NULL , V_2 , V_72 , & V_74 , V_43 ) ;
if ( error || * V_43 )
return error ;
* V_43 = V_71 >= V_74 . V_75 + V_74 . V_76 ;
return 0 ;
}
STATIC void
F_43 (
T_13 * V_77 ,
T_14 V_78 ,
int V_79 ,
int * V_80 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_79 ; V_81 ++ ) {
T_15 * V_82 = F_44 ( V_77 , V_78 + V_81 ) ;
* V_80 += F_45 ( V_82 ) ;
}
}
STATIC void
F_46 (
struct V_83 * V_12 ,
struct V_84 * V_85 ,
int V_79 ,
int * V_80 )
{
int V_81 ;
T_16 * V_82 ;
for ( V_81 = 1 ; V_81 <= V_79 ; V_81 ++ ) {
V_82 = F_47 ( V_12 , V_85 , V_81 ) ;
* V_80 += F_48 ( V_82 ) ;
}
}
STATIC int
F_49 (
T_8 * V_12 ,
T_3 * V_5 ,
T_13 * V_77 ,
T_2 V_86 ,
int V_87 ,
int * V_80 )
{
int error ;
T_17 * V_88 , * V_89 ;
int V_90 = V_87 ;
T_18 * V_91 ;
T_2 V_92 = V_86 ;
T_2 V_93 ;
struct V_84 * V_85 , * V_94 ;
int V_79 ;
error = F_50 ( V_12 , V_5 , V_92 , 0 , & V_88 , V_95 ,
& V_96 ) ;
if ( error )
return error ;
* V_80 += 1 ;
V_85 = F_51 ( V_88 ) ;
if ( -- V_90 ) {
V_93 = F_52 ( V_85 -> V_97 . V_98 . V_99 ) ;
while ( V_93 != V_56 ) {
error = F_50 ( V_12 , V_5 , V_93 , 0 , & V_89 ,
V_95 ,
& V_96 ) ;
if ( error )
return error ;
* V_80 += 1 ;
V_94 = F_51 ( V_89 ) ;
V_93 = F_52 ( V_94 -> V_97 . V_98 . V_99 ) ;
F_53 ( V_5 , V_89 ) ;
}
V_91 = F_54 ( V_12 , V_85 , 1 , V_12 -> V_100 [ 1 ] ) ;
V_92 = F_52 ( * V_91 ) ;
if ( F_55 ( ( error =
F_49 ( V_12 , V_5 , V_77 , V_92 , V_90 , V_80 ) ) < 0 ) ) {
F_53 ( V_5 , V_88 ) ;
F_56 ( L_1 ,
V_101 , V_12 ) ;
return F_57 ( V_29 ) ;
}
F_53 ( V_5 , V_88 ) ;
} else {
for (; ; ) {
V_93 = F_52 ( V_85 -> V_97 . V_98 . V_99 ) ;
V_79 = F_58 ( V_85 -> V_102 ) ;
F_46 ( V_12 , V_85 , V_79 , V_80 ) ;
F_53 ( V_5 , V_88 ) ;
if ( V_93 == V_56 )
break;
V_92 = V_93 ;
error = F_50 ( V_12 , V_5 , V_92 , 0 , & V_88 ,
V_95 ,
& V_96 ) ;
if ( error )
return error ;
* V_80 += 1 ;
V_85 = F_51 ( V_88 ) ;
}
}
return 0 ;
}
int
F_59 (
T_3 * V_5 ,
T_19 * V_2 ,
int V_72 ,
int * V_80 )
{
struct V_84 * V_85 ;
T_2 V_92 ;
T_13 * V_77 ;
int V_90 ;
T_8 * V_12 ;
T_18 * V_91 ;
V_92 = V_56 ;
V_12 = V_2 -> V_4 ;
V_77 = F_60 ( V_2 , V_72 ) ;
if ( F_61 ( V_2 , V_72 ) == V_103 ) {
F_43 ( V_77 , 0 ,
V_77 -> V_104 / ( V_105 ) sizeof( T_16 ) ,
V_80 ) ;
return 0 ;
}
V_85 = V_77 -> V_106 ;
V_90 = F_58 ( V_85 -> V_107 ) ;
ASSERT ( V_90 > 0 ) ;
V_91 = F_62 ( V_12 , V_85 , 1 , V_77 -> V_108 ) ;
V_92 = F_52 ( * V_91 ) ;
ASSERT ( V_92 != V_109 ) ;
ASSERT ( F_63 ( V_12 , V_92 ) < V_12 -> V_39 . V_110 ) ;
ASSERT ( F_64 ( V_12 , V_92 ) < V_12 -> V_39 . V_111 ) ;
if ( F_55 ( F_49 ( V_12 , V_5 , V_77 , V_92 , V_90 , V_80 ) < 0 ) ) {
F_56 ( L_2 , V_101 ,
V_12 ) ;
return F_57 ( V_29 ) ;
}
return 0 ;
}
STATIC int
F_65 (
T_19 * V_2 ,
struct V_112 * V_113 ,
int V_114 ,
T_20 V_115 ,
T_2 V_116 )
{
T_20 V_117 ;
T_8 * V_12 ;
T_13 * V_77 ;
T_14 V_118 ;
T_12 V_119 ;
if ( V_116 == V_120 ) {
V_12 = V_2 -> V_4 ;
V_113 -> V_121 = - 1 ;
V_117 = F_3 ( V_12 , F_66 ( V_12 , F_67 ( V_2 ) ) ) ;
V_117 -= V_113 -> V_122 ;
if ( V_114 && V_113 -> V_122 + V_113 -> V_123 == V_115 ) {
if ( V_117 <= 0 )
return 0 ;
V_113 -> V_123 = V_117 ;
}
} else {
if ( V_116 == V_124 )
V_113 -> V_121 = - 2 ;
else
V_113 -> V_121 = F_1 ( V_2 , V_116 ) ;
V_119 = F_68 ( V_2 -> V_4 , V_113 -> V_122 ) ;
V_77 = F_60 ( V_2 , V_125 ) ;
if ( F_69 ( V_77 , V_119 , & V_118 ) &&
( V_118 == ( V_77 -> V_104 / ( V_105 ) sizeof( T_16 ) ) - 1 ) )
V_113 -> V_126 |= V_127 ;
}
return 1 ;
}
int
F_70 (
T_19 * V_2 ,
struct V_112 * V_128 ,
T_21 V_129 ,
void * V_130 )
{
T_20 V_131 ;
int error = 0 ;
T_20 V_117 ;
int V_132 ;
int V_133 ;
T_22 * V_134 ;
T_8 * V_12 ;
int V_135 ;
int V_136 ;
int V_137 ;
int V_138 ;
struct V_112 * V_113 ;
int V_72 ;
int V_114 ;
int V_139 ;
int V_140 ;
int V_141 = 0 ;
V_12 = V_2 -> V_4 ;
V_139 = V_128 -> V_142 ;
V_72 = V_139 & V_143 ? V_144 : V_125 ;
if ( V_72 == V_144 ) {
if ( F_71 ( V_2 ) ) {
if ( V_2 -> V_57 . V_145 != V_103 &&
V_2 -> V_57 . V_145 != V_146 &&
V_2 -> V_57 . V_145 != V_147 )
return F_57 ( V_148 ) ;
} else if ( F_55 (
V_2 -> V_57 . V_145 != 0 &&
V_2 -> V_57 . V_145 != V_103 ) ) {
F_56 ( L_3 , V_101 ,
V_2 -> V_4 ) ;
return F_57 ( V_29 ) ;
}
V_114 = 0 ;
V_117 = 1LL << 32 ;
} else {
if ( V_2 -> V_57 . V_149 != V_103 &&
V_2 -> V_57 . V_149 != V_146 &&
V_2 -> V_57 . V_149 != V_147 )
return F_57 ( V_148 ) ;
if ( F_19 ( V_2 ) ||
V_2 -> V_57 . V_150 & ( V_151 | V_152 ) ) {
V_114 = 1 ;
V_117 = V_12 -> V_153 -> V_154 ;
} else {
V_114 = 0 ;
V_117 = F_67 ( V_2 ) ;
}
}
if ( V_128 -> V_123 == - 1 ) {
V_117 = F_3 ( V_12 , F_66 ( V_12 , V_117 ) ) ;
V_128 -> V_123 =
F_72 ( T_20 , V_117 - V_128 -> V_122 , 0 ) ;
} else if ( V_128 -> V_123 == 0 ) {
V_128 -> V_155 = 0 ;
return 0 ;
} else if ( V_128 -> V_123 < 0 ) {
return F_57 ( V_148 ) ;
}
V_135 = V_128 -> V_156 - 1 ;
if ( V_135 <= 0 )
return F_57 ( V_148 ) ;
V_131 = V_128 -> V_122 + V_128 -> V_123 ;
if ( V_128 -> V_156 > V_157 / sizeof( struct V_112 ) )
return F_57 ( V_158 ) ;
V_113 = F_73 ( V_128 -> V_156 * sizeof( struct V_112 ) , 0 ) ;
if ( ! V_113 )
return F_57 ( V_158 ) ;
F_22 ( V_2 , V_159 ) ;
if ( V_72 == V_125 && ! ( V_139 & V_160 ) ) {
if ( V_2 -> V_60 || F_67 ( V_2 ) > V_2 -> V_57 . V_161 ) {
error = - F_74 ( F_75 ( V_2 ) -> V_162 ) ;
if ( error )
goto V_163;
}
}
V_133 = F_76 ( V_2 ) ;
if ( V_135 > F_77 ( V_2 , V_72 ) * 2 + 1 )
V_135 = F_77 ( V_2 , V_72 ) * 2 + 1 ;
V_140 = F_78 ( V_72 ) ;
if ( ! ( V_139 & V_164 ) )
V_140 |= V_165 ;
error = V_158 ;
V_137 = 16 ;
V_134 = F_79 ( V_137 * sizeof( * V_134 ) , V_166 | V_167 ) ;
if ( ! V_134 )
goto V_168;
V_128 -> V_155 = 0 ;
if ( F_77 ( V_2 , V_72 ) == 0 &&
( V_72 == V_144 || ! ( V_139 & V_160 ) ) ) {
error = 0 ;
goto V_169;
}
V_136 = V_135 ;
do {
V_138 = ( V_136 > V_137 ) ? V_137 : V_136 ;
error = F_80 ( V_2 , F_81 ( V_12 , V_128 -> V_122 ) ,
F_68 ( V_12 , V_128 -> V_123 ) ,
V_134 , & V_138 , V_140 ) ;
if ( error )
goto V_169;
ASSERT ( V_138 <= V_137 ) ;
for ( V_132 = 0 ; V_132 < V_138 && V_136 && V_128 -> V_123 ; V_132 ++ ) {
V_113 [ V_141 ] . V_126 = 0 ;
if ( V_134 [ V_132 ] . V_170 == V_171 )
V_113 [ V_141 ] . V_126 |= V_172 ;
else if ( V_134 [ V_132 ] . V_173 == V_124 )
V_113 [ V_141 ] . V_126 |= V_174 ;
V_113 [ V_141 ] . V_122 =
F_3 ( V_12 , V_134 [ V_132 ] . V_75 ) ;
V_113 [ V_141 ] . V_123 =
F_3 ( V_12 , V_134 [ V_132 ] . V_76 ) ;
V_113 [ V_141 ] . V_175 = 0 ;
V_113 [ V_141 ] . V_176 = 0 ;
if ( V_134 [ V_132 ] . V_173 == V_124 &&
V_134 [ V_132 ] . V_75 <= F_66 ( V_12 , F_67 ( V_2 ) ) )
ASSERT ( ( V_139 & V_160 ) != 0 ) ;
if ( V_134 [ V_132 ] . V_173 == V_120 &&
V_72 == V_144 ) {
V_113 [ V_141 ] . V_126 |= V_127 ;
goto V_169;
}
if ( ! F_65 ( V_2 , & V_113 [ V_141 ] ,
V_114 , V_131 ,
V_134 [ V_132 ] . V_173 ) )
goto V_169;
V_128 -> V_122 =
V_113 [ V_141 ] . V_122 +
V_113 [ V_141 ] . V_123 ;
V_128 -> V_123 =
F_72 ( T_20 , 0 , V_131 - V_128 -> V_122 ) ;
if ( ( V_139 & V_177 ) &&
V_134 [ V_132 ] . V_173 == V_120 ) {
memset ( & V_113 [ V_141 ] , 0 , sizeof( V_113 [ V_141 ] ) ) ;
continue;
}
V_136 -- ;
V_128 -> V_155 ++ ;
V_141 ++ ;
}
} while ( V_138 && V_136 && V_128 -> V_123 );
V_169:
F_82 ( V_134 ) ;
V_168:
F_83 ( V_2 , V_133 ) ;
V_163:
F_84 ( V_2 , V_159 ) ;
for ( V_132 = 0 ; V_132 < V_141 ; V_132 ++ ) {
int V_178 = 0 ;
error = V_129 ( & V_130 , & V_113 [ V_132 ] , & V_178 ) ;
if ( error || V_178 )
break;
}
F_82 ( V_113 ) ;
return error ;
}
int
F_85 (
struct V_1 * V_2 ,
T_12 V_179 ,
T_12 V_46 )
{
T_12 V_180 = V_46 ;
int error = 0 ;
ASSERT ( F_86 ( V_2 , V_49 ) ) ;
do {
int V_68 ;
T_22 V_181 ;
int V_182 = 1 ;
T_2 V_183 ;
T_4 V_6 ;
error = F_80 ( V_2 , V_179 , 1 , & V_181 , & V_182 ,
V_184 ) ;
if ( error ) {
if ( ! F_14 ( V_2 -> V_4 ) ) {
F_87 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_185 , V_179 ) ;
}
break;
}
if ( ! V_182 ) {
goto V_186;
}
if ( V_181 . V_173 != V_124 ) {
goto V_186;
}
F_88 ( V_181 . V_76 == 0 ) ;
F_89 ( & V_6 , & V_183 ) ;
error = F_90 ( NULL , V_2 , V_179 , 1 , 0 , 1 , & V_183 ,
& V_6 , & V_68 ) ;
if ( error )
break;
ASSERT ( ! V_6 . V_17 && ! V_6 . V_18 ) ;
V_186:
V_179 ++ ;
V_180 -- ;
} while( V_180 > 0 );
return error ;
}
bool
F_91 ( struct V_1 * V_2 , bool V_187 )
{
if ( ! F_92 ( V_2 -> V_57 . V_188 ) )
return false ;
if ( F_75 ( V_2 ) -> V_189 == 0 &&
F_93 ( F_75 ( V_2 ) ) == 0 &&
V_2 -> V_60 == 0 )
return false ;
if ( ! ( V_2 -> V_190 . V_191 & V_192 ) )
return false ;
if ( V_2 -> V_57 . V_150 & ( V_151 | V_152 ) )
if ( ! V_187 || V_2 -> V_60 == 0 )
return false ;
return true ;
}
int
F_94 (
T_8 * V_12 ,
T_19 * V_2 ,
bool V_193 )
{
T_3 * V_5 ;
int error ;
T_12 V_194 ;
T_12 V_195 ;
T_23 V_196 ;
int V_182 ;
T_22 V_181 ;
V_194 = F_66 ( V_12 , ( V_197 ) F_67 ( V_2 ) ) ;
V_195 = F_66 ( V_12 , V_12 -> V_153 -> V_154 ) ;
if ( V_195 <= V_194 )
return 0 ;
V_196 = V_195 - V_194 ;
V_182 = 1 ;
F_22 ( V_2 , V_198 ) ;
error = F_80 ( V_2 , V_194 , V_196 , & V_181 , & V_182 , 0 ) ;
F_84 ( V_2 , V_198 ) ;
if ( ! error && ( V_182 != 0 ) &&
( V_181 . V_173 != V_120 ||
V_2 -> V_60 ) ) {
error = F_95 ( V_2 , 0 ) ;
if ( error )
return error ;
V_5 = F_96 ( V_12 , V_199 ) ;
if ( V_193 ) {
if ( ! F_97 ( V_2 , V_200 ) ) {
F_98 ( V_5 , 0 ) ;
return V_201 ;
}
}
error = F_11 ( V_5 , & F_99 ( V_12 ) -> V_202 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_14 ( V_12 ) ) ;
F_98 ( V_5 , 0 ) ;
if ( V_193 )
F_84 ( V_2 , V_200 ) ;
return error ;
}
F_22 ( V_2 , V_49 ) ;
F_23 ( V_5 , V_2 , 0 ) ;
error = F_100 ( & V_5 , V_2 , V_125 ,
F_67 ( V_2 ) ) ;
if ( error ) {
F_98 ( V_5 ,
( V_203 |
V_204 ) ) ;
} else {
error = F_9 ( V_5 ,
V_203 ) ;
if ( ! error )
F_101 ( V_2 ) ;
}
F_84 ( V_2 , V_49 ) ;
if ( V_193 )
F_84 ( V_2 , V_200 ) ;
}
return error ;
}
STATIC int
F_102 (
T_19 * V_2 ,
T_24 V_45 ,
T_24 V_205 ,
int V_206 ,
int V_207 )
{
T_8 * V_12 = V_2 -> V_4 ;
T_24 V_80 ;
T_23 V_208 ;
T_23 V_209 ;
T_10 V_210 , V_211 ;
T_12 V_212 ;
T_2 V_213 ;
int V_182 ;
int V_214 ;
int V_215 ;
T_3 * V_5 ;
T_22 V_216 [ 1 ] , * V_217 ;
T_4 V_218 ;
V_105 V_219 , V_220 , V_221 ;
int V_7 ;
int error ;
F_103 ( V_2 ) ;
if ( F_14 ( V_12 ) )
return F_57 ( V_222 ) ;
error = F_95 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_205 <= 0 )
return F_57 ( V_148 ) ;
V_215 = F_2 ( V_2 ) ;
V_210 = F_19 ( V_2 ) ;
V_80 = V_205 ;
V_217 = & V_216 [ 0 ] ;
V_182 = 1 ;
V_212 = F_104 ( V_12 , V_45 ) ;
V_209 = F_66 ( V_12 , V_80 ) ;
while ( V_209 && ! error ) {
T_12 V_223 , V_224 ;
if ( F_55 ( V_210 ) ) {
V_223 = V_212 ;
F_26 ( V_223 , V_210 ) ;
V_223 *= V_210 ;
V_224 = V_212 + V_209 ;
if ( ( V_211 = F_21 ( V_212 , V_210 ) ) )
V_224 += V_211 ;
if ( ( V_211 = F_21 ( V_224 , V_210 ) ) )
V_224 += V_210 - V_211 ;
} else {
V_223 = 0 ;
V_224 = V_209 ;
}
V_220 = F_105 ( T_12 , ( V_224 - V_223 ) , ( V_47 * V_182 ) ) ;
if ( F_55 ( V_215 ) ) {
V_221 = V_219 = V_220 ;
V_221 /= V_12 -> V_39 . V_40 ;
V_220 = F_106 ( V_12 , 0 ) ;
V_214 = V_225 ;
} else {
V_221 = 0 ;
V_220 = V_219 = F_106 ( V_12 , V_220 ) ;
V_214 = V_226 ;
}
V_5 = F_96 ( V_12 , V_227 ) ;
error = F_11 ( V_5 , & F_99 ( V_12 ) -> V_228 ,
V_220 , V_221 ) ;
if ( error ) {
ASSERT ( error == V_229 || F_14 ( V_12 ) ) ;
F_98 ( V_5 , 0 ) ;
break;
}
F_22 ( V_2 , V_49 ) ;
error = F_107 ( V_5 , V_2 , V_219 ,
0 , V_214 ) ;
if ( error )
goto V_230;
F_23 ( V_5 , V_2 , 0 ) ;
F_89 ( & V_218 , & V_213 ) ;
error = F_108 ( V_5 , V_2 , V_212 ,
V_209 , V_206 , & V_213 ,
0 , V_217 , & V_182 , & V_218 ) ;
if ( error ) {
goto V_231;
}
error = F_5 ( & V_5 , & V_218 , & V_7 ) ;
if ( error ) {
goto V_231;
}
error = F_9 ( V_5 , V_203 ) ;
F_84 ( V_2 , V_49 ) ;
if ( error ) {
break;
}
V_208 = V_217 -> V_76 ;
if ( V_182 == 0 ) {
error = F_57 ( V_229 ) ;
break;
}
V_212 += V_208 ;
V_209 -= V_208 ;
}
return error ;
V_231:
F_109 ( & V_218 ) ;
F_110 ( V_5 , V_2 , ( long ) V_219 , 0 , V_214 ) ;
V_230:
F_98 ( V_5 , V_203 | V_204 ) ;
F_84 ( V_2 , V_49 ) ;
return error ;
}
STATIC int
F_111 (
T_19 * V_2 ,
T_24 V_232 ,
T_24 V_71 )
{
T_22 V_181 ;
T_12 V_233 ;
T_24 V_234 ;
T_24 V_45 ;
T_17 * V_88 ;
T_8 * V_12 = V_2 -> V_4 ;
int V_235 ;
int error = 0 ;
if ( V_232 >= F_67 ( V_2 ) )
return 0 ;
if ( V_71 > F_67 ( V_2 ) )
V_71 = F_67 ( V_2 ) ;
V_88 = F_112 ( F_2 ( V_2 ) ?
V_12 -> V_236 : V_12 -> V_237 ,
F_113 ( V_12 -> V_39 . V_238 ) , 0 ) ;
if ( ! V_88 )
return F_57 ( V_158 ) ;
F_114 ( V_88 ) ;
for ( V_45 = V_232 ; V_45 <= V_71 ; V_45 = V_234 + 1 ) {
V_233 = F_104 ( V_12 , V_45 ) ;
V_235 = 1 ;
error = F_80 ( V_2 , V_233 , 1 , & V_181 , & V_235 , 0 ) ;
if ( error || V_235 < 1 )
break;
ASSERT ( V_181 . V_76 >= 1 ) ;
ASSERT ( V_181 . V_75 == V_233 ) ;
V_234 = F_115 ( V_12 , V_181 . V_75 + 1 ) - 1 ;
if ( V_234 > V_71 )
V_234 = V_71 ;
if ( V_181 . V_173 == V_120 )
continue;
ASSERT ( V_181 . V_173 != V_124 ) ;
if ( V_181 . V_170 == V_171 )
continue;
F_116 ( V_88 ) ;
F_117 ( V_88 ) ;
F_118 ( V_88 ) ;
F_119 ( V_88 , F_1 ( V_2 , V_181 . V_173 ) ) ;
F_120 ( V_12 , V_88 ) ;
error = F_121 ( V_88 ) ;
if ( error ) {
F_122 ( V_88 ,
L_5 ) ;
break;
}
memset ( V_88 -> V_239 +
( V_45 - F_115 ( V_12 , V_181 . V_75 ) ) ,
0 , V_234 - V_45 + 1 ) ;
F_116 ( V_88 ) ;
F_123 ( V_88 ) ;
F_124 ( V_88 ) ;
F_120 ( V_12 , V_88 ) ;
error = F_121 ( V_88 ) ;
if ( error ) {
F_122 ( V_88 ,
L_6 ) ;
break;
}
}
F_125 ( V_88 ) ;
return error ;
}
STATIC int
F_126 (
T_19 * V_2 ,
T_24 V_45 ,
T_24 V_205 ,
int V_207 )
{
int V_7 ;
int V_68 ;
T_12 V_240 ;
int error ;
T_2 V_213 ;
T_4 V_218 ;
T_22 V_181 ;
T_24 V_241 ;
T_10 V_242 = 0 ;
T_8 * V_12 ;
int V_235 ;
V_105 V_220 ;
T_24 V_243 ;
int V_215 ;
T_12 V_212 ;
T_3 * V_5 ;
int V_193 = 1 ;
V_12 = V_2 -> V_4 ;
F_127 ( V_2 ) ;
error = F_95 ( V_2 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_205 <= 0 )
return error ;
V_215 = F_2 ( V_2 ) ;
V_212 = F_66 ( V_12 , V_45 ) ;
V_240 = F_104 ( V_12 , V_45 + V_205 ) ;
if ( V_207 & V_244 )
V_193 = 0 ;
if ( V_193 ) {
F_22 ( V_2 , V_200 ) ;
F_128 ( F_75 ( V_2 ) ) ;
}
V_243 = F_72 ( T_24 , 1 << V_12 -> V_39 . V_245 , V_246 ) ;
V_241 = V_45 & ~ ( V_243 - 1 ) ;
error = - F_129 ( F_75 ( V_2 ) -> V_162 ,
V_241 , - 1 ) ;
if ( error )
goto V_163;
F_130 ( F_75 ( V_2 ) , V_241 , - 1 ) ;
if ( V_215 && ! F_131 ( & V_12 -> V_39 ) ) {
V_235 = 1 ;
error = F_80 ( V_2 , V_212 , 1 ,
& V_181 , & V_235 , 0 ) ;
if ( error )
goto V_163;
ASSERT ( V_235 == 0 || V_235 == 1 ) ;
if ( V_235 && V_181 . V_173 != V_120 ) {
T_1 V_85 ;
ASSERT ( V_181 . V_173 != V_124 ) ;
V_85 = V_181 . V_173 ;
V_242 = F_26 ( V_85 , V_12 -> V_39 . V_40 ) ;
if ( V_242 )
V_212 += V_12 -> V_39 . V_40 - V_242 ;
}
V_235 = 1 ;
error = F_80 ( V_2 , V_240 - 1 , 1 ,
& V_181 , & V_235 , 0 ) ;
if ( error )
goto V_163;
ASSERT ( V_235 == 0 || V_235 == 1 ) ;
if ( V_235 && V_181 . V_173 != V_120 ) {
ASSERT ( V_181 . V_173 != V_124 ) ;
V_242 ++ ;
if ( V_242 && ( V_242 != V_12 -> V_39 . V_40 ) )
V_240 -= V_242 ;
}
}
if ( ( V_68 = ( V_240 <= V_212 ) ) )
error = F_111 ( V_2 , V_45 , V_45 + V_205 - 1 ) ;
else {
if ( V_45 < F_115 ( V_12 , V_212 ) )
error = F_111 ( V_2 , V_45 ,
F_115 ( V_12 , V_212 ) - 1 ) ;
if ( ! error &&
F_115 ( V_12 , V_240 ) < V_45 + V_205 )
error = F_111 ( V_2 ,
F_115 ( V_12 , V_240 ) ,
V_45 + V_205 - 1 ) ;
}
V_220 = F_106 ( V_12 , 0 ) ;
while ( ! error && ! V_68 ) {
V_5 = F_96 ( V_12 , V_227 ) ;
V_5 -> V_15 |= V_247 ;
error = F_11 ( V_5 , & F_99 ( V_12 ) -> V_228 , V_220 , 0 ) ;
if ( error ) {
ASSERT ( error == V_229 || F_14 ( V_12 ) ) ;
F_98 ( V_5 , 0 ) ;
break;
}
F_22 ( V_2 , V_49 ) ;
error = F_132 ( V_5 , V_12 ,
V_2 -> V_248 , V_2 -> V_249 , V_2 -> V_250 ,
V_220 , 0 , V_226 ) ;
if ( error )
goto V_230;
F_23 ( V_5 , V_2 , 0 ) ;
F_89 ( & V_218 , & V_213 ) ;
error = F_90 ( V_5 , V_2 , V_212 ,
V_240 - V_212 ,
0 , 2 , & V_213 , & V_218 , & V_68 ) ;
if ( error ) {
goto V_231;
}
error = F_5 ( & V_5 , & V_218 , & V_7 ) ;
if ( error ) {
goto V_231;
}
error = F_9 ( V_5 , V_203 ) ;
F_84 ( V_2 , V_49 ) ;
}
V_163:
if ( V_193 )
F_84 ( V_2 , V_200 ) ;
return error ;
V_231:
F_109 ( & V_218 ) ;
V_230:
F_98 ( V_5 , V_203 | V_204 ) ;
F_84 ( V_2 , V_193 ? ( V_49 | V_200 ) :
V_49 ) ;
return error ;
}
STATIC int
F_133 (
struct V_1 * V_2 ,
T_24 V_45 ,
T_24 V_205 ,
int V_207 )
{
struct V_83 * V_12 = V_2 -> V_4 ;
V_105 V_251 ;
T_24 V_252 ;
T_24 V_253 ;
int error ;
V_251 = F_72 ( V_105 , 1 << V_12 -> V_39 . V_245 , V_246 ) ;
V_252 = F_134 ( V_45 , V_251 ) ;
V_253 = F_135 ( V_45 + V_205 , V_251 ) ;
ASSERT ( V_252 >= V_45 ) ;
ASSERT ( V_253 <= V_45 + V_205 ) ;
if ( ! ( V_207 & V_244 ) )
F_22 ( V_2 , V_200 ) ;
if ( V_252 < V_253 - 1 ) {
F_130 ( F_75 ( V_2 ) , V_252 ,
V_253 - 1 ) ;
error = F_102 ( V_2 , V_252 ,
V_253 - V_252 - 1 ,
V_254 | V_255 ,
V_207 ) ;
if ( error )
goto V_256;
if ( V_252 != V_45 )
error = F_136 ( V_2 , V_45 , V_252 - V_45 ) ;
if ( error )
goto V_256;
if ( V_253 != V_45 + V_205 )
error = F_136 ( V_2 , V_253 ,
V_45 + V_205 - V_253 ) ;
} else {
error = F_136 ( V_2 , V_45 , V_205 ) ;
}
V_256:
if ( ! ( V_207 & V_244 ) )
F_84 ( V_2 , V_200 ) ;
return error ;
}
int
F_137 (
T_19 * V_2 ,
int V_257 ,
T_25 * V_258 ,
T_24 V_45 ,
int V_207 )
{
T_8 * V_12 = V_2 -> V_4 ;
int V_259 ;
int error ;
T_26 V_260 ;
int V_261 ;
T_24 V_262 ;
T_3 * V_5 ;
struct V_263 V_263 ;
if ( ! F_92 ( V_2 -> V_57 . V_188 ) )
return F_57 ( V_148 ) ;
switch ( V_258 -> V_264 ) {
case 0 :
break;
case 1 :
V_258 -> V_265 += V_45 ;
break;
case 2 :
V_258 -> V_265 += F_67 ( V_2 ) ;
break;
default:
return F_57 ( V_148 ) ;
}
switch ( V_257 ) {
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
if ( V_258 -> V_271 <= 0 )
return F_57 ( V_148 ) ;
break;
default:
V_258 -> V_271 = 0 ;
break;
}
if ( V_258 -> V_265 < 0 ||
V_258 -> V_265 > V_12 -> V_153 -> V_154 ||
V_258 -> V_265 + V_258 -> V_271 < 0 ||
V_258 -> V_265 + V_258 -> V_271 >= V_12 -> V_153 -> V_154 )
return F_57 ( V_148 ) ;
V_258 -> V_264 = 0 ;
V_262 = V_258 -> V_265 ;
V_260 = F_67 ( V_2 ) ;
V_261 = V_259 = 0 ;
switch ( V_257 ) {
case V_266 :
error = F_133 ( V_2 , V_262 , V_258 -> V_271 ,
V_207 ) ;
if ( error )
return error ;
V_261 = 1 ;
break;
case V_267 :
case V_268 :
error = F_102 ( V_2 , V_262 , V_258 -> V_271 ,
V_254 , V_207 ) ;
if ( error )
return error ;
V_261 = 1 ;
break;
case V_269 :
case V_270 :
if ( ( error = F_126 ( V_2 , V_262 , V_258 -> V_271 ,
V_207 ) ) )
return error ;
break;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
F_22 ( V_2 , V_200 ) ;
if ( V_262 > V_260 ) {
error = F_102 ( V_2 , V_260 ,
V_262 - V_260 , 0 ,
V_207 | V_244 ) ;
if ( error ) {
F_84 ( V_2 , V_200 ) ;
break;
}
}
V_263 . V_276 = V_277 ;
V_263 . V_278 = V_262 ;
error = F_138 ( V_2 , & V_263 ,
V_207 | V_244 ) ;
F_84 ( V_2 , V_200 ) ;
if ( error )
return error ;
V_259 = 1 ;
break;
default:
ASSERT ( 0 ) ;
return F_57 ( V_148 ) ;
}
V_5 = F_96 ( V_12 , V_279 ) ;
error = F_11 ( V_5 , & F_99 ( V_12 ) -> V_280 , 0 , 0 ) ;
if ( error ) {
F_98 ( V_5 , 0 ) ;
return error ;
}
F_22 ( V_2 , V_49 ) ;
F_23 ( V_5 , V_2 , V_49 ) ;
if ( ( V_207 & V_281 ) == 0 ) {
V_2 -> V_57 . V_188 &= ~ V_282 ;
if ( V_2 -> V_57 . V_188 & V_283 )
V_2 -> V_57 . V_188 &= ~ V_284 ;
F_139 ( V_5 , V_2 , V_285 | V_286 ) ;
}
if ( V_261 )
V_2 -> V_57 . V_150 |= V_151 ;
else if ( V_259 )
V_2 -> V_57 . V_150 &= ~ V_151 ;
F_28 ( V_5 , V_2 , V_59 ) ;
if ( V_207 & V_287 )
F_140 ( V_5 ) ;
return F_9 ( V_5 , 0 ) ;
}
static int
F_141 (
T_19 * V_2 ,
T_19 * V_288 )
{
if ( V_2 -> V_57 . V_149 == V_147 ||
V_288 -> V_57 . V_149 == V_147 )
return V_148 ;
if ( V_2 -> V_57 . V_289 < V_288 -> V_57 . V_289 )
return V_148 ;
if ( V_2 -> V_57 . V_149 == V_103 &&
V_288 -> V_57 . V_149 == V_146 )
return V_148 ;
if ( V_288 -> V_57 . V_149 == V_103 &&
F_77 ( V_288 , V_125 ) >
F_142 ( V_2 , V_125 ) )
return V_148 ;
if ( V_2 -> V_57 . V_149 == V_103 &&
F_77 ( V_2 , V_125 ) >
F_142 ( V_288 , V_125 ) )
return V_148 ;
if ( V_288 -> V_57 . V_149 == V_146 ) {
if ( F_143 ( V_2 ) &&
F_144 ( V_288 -> V_190 . V_106 ) > F_143 ( V_2 ) )
return V_148 ;
if ( F_77 ( V_288 , V_125 ) <=
F_142 ( V_2 , V_125 ) )
return V_148 ;
}
if ( V_2 -> V_57 . V_149 == V_146 ) {
if ( F_143 ( V_288 ) &&
F_144 ( V_2 -> V_190 . V_106 ) > F_143 ( V_288 ) )
return V_148 ;
if ( F_77 ( V_2 , V_125 ) <=
F_142 ( V_288 , V_125 ) )
return V_148 ;
}
return 0 ;
}
int
F_145 (
T_19 * V_2 ,
T_19 * V_288 ,
T_27 * V_290 )
{
T_8 * V_12 = V_2 -> V_4 ;
T_3 * V_5 ;
T_28 * V_291 = & V_290 -> V_292 ;
T_13 * V_293 , * V_77 , * V_294 ;
int V_295 , V_296 ;
int error = 0 ;
int V_297 = 0 ;
int V_298 = 0 ;
T_29 V_299 ;
V_293 = F_79 ( sizeof( T_13 ) , V_166 ) ;
if ( ! V_293 ) {
error = F_57 ( V_158 ) ;
goto V_113;
}
F_146 ( V_2 , V_288 , V_200 ) ;
F_146 ( V_2 , V_288 , V_49 ) ;
if ( ( V_2 -> V_57 . V_188 & V_300 ) != ( V_288 -> V_57 . V_188 & V_300 ) ) {
error = F_57 ( V_148 ) ;
goto V_256;
}
if ( F_2 ( V_2 ) != F_2 ( V_288 ) ) {
error = F_57 ( V_148 ) ;
goto V_256;
}
error = - F_74 ( F_75 ( V_288 ) -> V_162 ) ;
if ( error )
goto V_256;
F_130 ( F_75 ( V_288 ) , 0 , - 1 ) ;
if ( F_93 ( F_75 ( V_288 ) ) != 0 ) {
error = F_57 ( V_148 ) ;
goto V_256;
}
if ( V_290 -> V_301 != 0 ||
V_290 -> V_302 != V_2 -> V_57 . V_161 ||
V_290 -> V_302 != V_288 -> V_57 . V_161 ) {
error = F_57 ( V_303 ) ;
goto V_256;
}
F_147 ( V_2 , 0 ) ;
F_147 ( V_288 , 1 ) ;
error = F_141 ( V_2 , V_288 ) ;
if ( error ) {
F_148 ( V_12 ,
L_7 ,
V_304 , V_2 -> V_185 ) ;
goto V_256;
}
if ( ( V_291 -> V_305 . V_306 != F_75 ( V_2 ) -> V_307 . V_306 ) ||
( V_291 -> V_305 . V_308 != F_75 ( V_2 ) -> V_307 . V_308 ) ||
( V_291 -> V_309 . V_306 != F_75 ( V_2 ) -> V_310 . V_306 ) ||
( V_291 -> V_309 . V_308 != F_75 ( V_2 ) -> V_310 . V_308 ) ) {
error = F_57 ( V_311 ) ;
goto V_256;
}
if ( F_149 ( F_75 ( V_2 ) ) ) {
error = F_57 ( V_311 ) ;
goto V_256;
}
F_84 ( V_2 , V_49 ) ;
F_84 ( V_288 , V_49 ) ;
F_130 ( F_75 ( V_2 ) , 0 , - 1 ) ;
V_5 = F_96 ( V_12 , V_312 ) ;
error = F_11 ( V_5 , & F_99 ( V_12 ) -> V_313 , 0 , 0 ) ;
if ( error ) {
F_84 ( V_2 , V_200 ) ;
F_84 ( V_288 , V_200 ) ;
F_98 ( V_5 , 0 ) ;
goto V_113;
}
F_146 ( V_2 , V_288 , V_49 ) ;
if ( ( ( F_71 ( V_2 ) != 0 ) && ( V_2 -> V_57 . V_314 > 0 ) ) &&
( V_2 -> V_57 . V_145 != V_147 ) ) {
error = F_59 ( V_5 , V_2 , V_144 , & V_297 ) ;
if ( error )
goto V_315;
}
if ( ( ( F_71 ( V_288 ) != 0 ) && ( V_288 -> V_57 . V_314 > 0 ) ) &&
( V_288 -> V_57 . V_145 != V_147 ) ) {
error = F_59 ( V_5 , V_288 , V_144 ,
& V_298 ) ;
if ( error )
goto V_315;
}
F_23 ( V_5 , V_2 , V_49 | V_200 ) ;
F_23 ( V_5 , V_288 , V_49 | V_200 ) ;
V_295 = V_59 ;
V_296 = V_59 ;
if ( V_2 -> V_57 . V_316 == 3 &&
V_2 -> V_57 . V_149 == V_146 ) {
V_296 |= V_317 ;
error = F_150 ( V_5 , V_2 , V_125 ,
V_288 -> V_185 , NULL ) ;
if ( error )
goto V_315;
}
if ( V_288 -> V_57 . V_316 == 3 &&
V_288 -> V_57 . V_149 == V_146 ) {
V_295 |= V_317 ;
error = F_150 ( V_5 , V_288 , V_125 ,
V_2 -> V_185 , NULL ) ;
if ( error )
goto V_315;
}
V_77 = & V_2 -> V_190 ;
V_294 = & V_288 -> V_190 ;
* V_293 = * V_77 ;
* V_77 = * V_294 ;
* V_294 = * V_293 ;
V_299 = ( T_29 ) V_2 -> V_57 . V_58 ;
V_2 -> V_57 . V_58 = V_288 -> V_57 . V_58 - V_298 + V_297 ;
V_288 -> V_57 . V_58 = V_299 + V_298 - V_297 ;
V_299 = ( T_29 ) V_2 -> V_57 . V_289 ;
V_2 -> V_57 . V_289 = V_288 -> V_57 . V_289 ;
V_288 -> V_57 . V_289 = V_299 ;
V_299 = ( T_29 ) V_2 -> V_57 . V_149 ;
V_2 -> V_57 . V_149 = V_288 -> V_57 . V_149 ;
V_288 -> V_57 . V_149 = V_299 ;
ASSERT ( V_288 -> V_60 == 0 ) ;
V_288 -> V_60 = V_2 -> V_60 ;
V_2 -> V_60 = 0 ;
switch ( V_2 -> V_57 . V_149 ) {
case V_103 :
if ( V_2 -> V_57 . V_289 <= V_318 ) {
V_77 -> V_319 . V_320 =
V_77 -> V_321 . V_322 ;
}
V_295 |= V_323 ;
break;
case V_146 :
ASSERT ( V_2 -> V_57 . V_316 < 3 ||
( V_295 & V_317 ) ) ;
V_295 |= V_324 ;
break;
}
switch ( V_288 -> V_57 . V_149 ) {
case V_103 :
if ( V_288 -> V_57 . V_289 <= V_318 ) {
V_294 -> V_319 . V_320 =
V_294 -> V_321 . V_322 ;
}
V_296 |= V_323 ;
break;
case V_146 :
V_296 |= V_324 ;
ASSERT ( V_288 -> V_57 . V_316 < 3 ||
( V_296 & V_317 ) ) ;
break;
}
F_28 ( V_5 , V_2 , V_295 ) ;
F_28 ( V_5 , V_288 , V_296 ) ;
if ( V_12 -> V_325 & V_326 )
F_140 ( V_5 ) ;
error = F_9 ( V_5 , 0 ) ;
F_151 ( V_2 , 0 ) ;
F_151 ( V_288 , 1 ) ;
V_113:
F_82 ( V_293 ) ;
return error ;
V_256:
F_84 ( V_2 , V_49 | V_200 ) ;
F_84 ( V_288 , V_49 | V_200 ) ;
goto V_113;
V_315:
F_98 ( V_5 , 0 ) ;
goto V_256;
}
