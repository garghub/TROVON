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
F_41 ( & args -> V_64 ) ;
return args -> V_67 ;
}
int
F_42 (
struct V_1 * V_2 ,
T_12 V_71 ,
int V_72 ,
int * V_43 )
{
struct V_73 V_74 ;
int error ;
error = F_43 ( NULL , V_2 , V_72 , & V_74 , V_43 ) ;
if ( error || * V_43 )
return error ;
* V_43 = V_71 >= V_74 . V_75 + V_74 . V_76 ;
return 0 ;
}
STATIC void
F_44 (
T_13 * V_77 ,
T_14 V_78 ,
int V_79 ,
int * V_80 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_79 ; V_81 ++ ) {
T_15 * V_82 = F_45 ( V_77 , V_78 + V_81 ) ;
* V_80 += F_46 ( V_82 ) ;
}
}
STATIC void
F_47 (
struct V_83 * V_12 ,
struct V_84 * V_85 ,
int V_79 ,
int * V_80 )
{
int V_81 ;
T_16 * V_82 ;
for ( V_81 = 1 ; V_81 <= V_79 ; V_81 ++ ) {
V_82 = F_48 ( V_12 , V_85 , V_81 ) ;
* V_80 += F_49 ( V_82 ) ;
}
}
STATIC int
F_50 (
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
error = F_51 ( V_12 , V_5 , V_92 , 0 , & V_88 , V_95 ,
& V_96 ) ;
if ( error )
return error ;
* V_80 += 1 ;
V_85 = F_52 ( V_88 ) ;
if ( -- V_90 ) {
V_93 = F_53 ( V_85 -> V_97 . V_98 . V_99 ) ;
while ( V_93 != V_56 ) {
error = F_51 ( V_12 , V_5 , V_93 , 0 , & V_89 ,
V_95 ,
& V_96 ) ;
if ( error )
return error ;
* V_80 += 1 ;
V_94 = F_52 ( V_89 ) ;
V_93 = F_53 ( V_94 -> V_97 . V_98 . V_99 ) ;
F_54 ( V_5 , V_89 ) ;
}
V_91 = F_55 ( V_12 , V_85 , 1 , V_12 -> V_100 [ 1 ] ) ;
V_92 = F_53 ( * V_91 ) ;
if ( F_56 ( ( error =
F_50 ( V_12 , V_5 , V_77 , V_92 , V_90 , V_80 ) ) < 0 ) ) {
F_54 ( V_5 , V_88 ) ;
F_57 ( L_1 ,
V_101 , V_12 ) ;
return F_58 ( V_29 ) ;
}
F_54 ( V_5 , V_88 ) ;
} else {
for (; ; ) {
V_93 = F_53 ( V_85 -> V_97 . V_98 . V_99 ) ;
V_79 = F_59 ( V_85 -> V_102 ) ;
F_47 ( V_12 , V_85 , V_79 , V_80 ) ;
F_54 ( V_5 , V_88 ) ;
if ( V_93 == V_56 )
break;
V_92 = V_93 ;
error = F_51 ( V_12 , V_5 , V_92 , 0 , & V_88 ,
V_95 ,
& V_96 ) ;
if ( error )
return error ;
* V_80 += 1 ;
V_85 = F_52 ( V_88 ) ;
}
}
return 0 ;
}
int
F_60 (
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
V_77 = F_61 ( V_2 , V_72 ) ;
if ( F_62 ( V_2 , V_72 ) == V_103 ) {
F_44 ( V_77 , 0 ,
V_77 -> V_104 / ( V_105 ) sizeof( T_16 ) ,
V_80 ) ;
return 0 ;
}
V_85 = V_77 -> V_106 ;
V_90 = F_59 ( V_85 -> V_107 ) ;
ASSERT ( V_90 > 0 ) ;
V_91 = F_63 ( V_12 , V_85 , 1 , V_77 -> V_108 ) ;
V_92 = F_53 ( * V_91 ) ;
ASSERT ( V_92 != V_109 ) ;
ASSERT ( F_64 ( V_12 , V_92 ) < V_12 -> V_39 . V_110 ) ;
ASSERT ( F_65 ( V_12 , V_92 ) < V_12 -> V_39 . V_111 ) ;
if ( F_56 ( F_50 ( V_12 , V_5 , V_77 , V_92 , V_90 , V_80 ) < 0 ) ) {
F_57 ( L_2 , V_101 ,
V_12 ) ;
return F_58 ( V_29 ) ;
}
return 0 ;
}
STATIC int
F_66 (
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
V_117 = F_3 ( V_12 , F_67 ( V_12 , F_68 ( V_2 ) ) ) ;
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
V_119 = F_69 ( V_2 -> V_4 , V_113 -> V_122 ) ;
V_77 = F_61 ( V_2 , V_125 ) ;
if ( F_70 ( V_77 , V_119 , & V_118 ) &&
( V_118 == ( V_77 -> V_104 / ( V_105 ) sizeof( T_16 ) ) - 1 ) )
V_113 -> V_126 |= V_127 ;
}
return 1 ;
}
int
F_71 (
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
if ( F_72 ( V_2 ) ) {
if ( V_2 -> V_57 . V_145 != V_103 &&
V_2 -> V_57 . V_145 != V_146 &&
V_2 -> V_57 . V_145 != V_147 )
return F_58 ( V_148 ) ;
} else if ( F_56 (
V_2 -> V_57 . V_145 != 0 &&
V_2 -> V_57 . V_145 != V_103 ) ) {
F_57 ( L_3 , V_101 ,
V_2 -> V_4 ) ;
return F_58 ( V_29 ) ;
}
V_114 = 0 ;
V_117 = 1LL << 32 ;
} else {
if ( V_2 -> V_57 . V_149 != V_103 &&
V_2 -> V_57 . V_149 != V_146 &&
V_2 -> V_57 . V_149 != V_147 )
return F_58 ( V_148 ) ;
if ( F_19 ( V_2 ) ||
V_2 -> V_57 . V_150 & ( V_151 | V_152 ) ) {
V_114 = 1 ;
V_117 = V_12 -> V_153 -> V_154 ;
} else {
V_114 = 0 ;
V_117 = F_68 ( V_2 ) ;
}
}
if ( V_128 -> V_123 == - 1 ) {
V_117 = F_3 ( V_12 , F_67 ( V_12 , V_117 ) ) ;
V_128 -> V_123 =
F_73 ( T_20 , V_117 - V_128 -> V_122 , 0 ) ;
} else if ( V_128 -> V_123 == 0 ) {
V_128 -> V_155 = 0 ;
return 0 ;
} else if ( V_128 -> V_123 < 0 ) {
return F_58 ( V_148 ) ;
}
V_135 = V_128 -> V_156 - 1 ;
if ( V_135 <= 0 )
return F_58 ( V_148 ) ;
V_131 = V_128 -> V_122 + V_128 -> V_123 ;
if ( V_128 -> V_156 > V_157 / sizeof( struct V_112 ) )
return F_58 ( V_158 ) ;
V_113 = F_74 ( V_128 -> V_156 * sizeof( struct V_112 ) , 0 ) ;
if ( ! V_113 )
return F_58 ( V_158 ) ;
F_22 ( V_2 , V_159 ) ;
if ( V_72 == V_125 ) {
if ( ! ( V_139 & V_160 ) &&
( V_2 -> V_60 || F_68 ( V_2 ) > V_2 -> V_57 . V_161 ) ) {
error = - F_75 ( F_76 ( V_2 ) -> V_162 ) ;
if ( error )
goto V_163;
}
V_133 = F_77 ( V_2 ) ;
} else {
V_133 = F_78 ( V_2 ) ;
}
if ( V_135 > F_79 ( V_2 , V_72 ) * 2 + 1 )
V_135 = F_79 ( V_2 , V_72 ) * 2 + 1 ;
V_140 = F_80 ( V_72 ) ;
if ( ! ( V_139 & V_164 ) )
V_140 |= V_165 ;
error = V_158 ;
V_137 = 16 ;
V_134 = F_81 ( V_137 * sizeof( * V_134 ) , V_166 | V_167 ) ;
if ( ! V_134 )
goto V_168;
V_128 -> V_155 = 0 ;
if ( F_79 ( V_2 , V_72 ) == 0 &&
( V_72 == V_144 || ! ( V_139 & V_160 ) ) ) {
error = 0 ;
goto V_169;
}
V_136 = V_135 ;
do {
V_138 = ( V_136 > V_137 ) ? V_137 : V_136 ;
error = F_82 ( V_2 , F_83 ( V_12 , V_128 -> V_122 ) ,
F_69 ( V_12 , V_128 -> V_123 ) ,
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
V_134 [ V_132 ] . V_75 <= F_67 ( V_12 , F_68 ( V_2 ) ) )
ASSERT ( ( V_139 & V_160 ) != 0 ) ;
if ( V_134 [ V_132 ] . V_173 == V_120 &&
V_72 == V_144 ) {
V_113 [ V_141 ] . V_126 |= V_127 ;
goto V_169;
}
if ( ! F_66 ( V_2 , & V_113 [ V_141 ] ,
V_114 , V_131 ,
V_134 [ V_132 ] . V_173 ) )
goto V_169;
V_128 -> V_122 =
V_113 [ V_141 ] . V_122 +
V_113 [ V_141 ] . V_123 ;
V_128 -> V_123 =
F_73 ( T_20 , 0 , V_131 - V_128 -> V_122 ) ;
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
F_84 ( V_134 ) ;
V_168:
F_85 ( V_2 , V_133 ) ;
V_163:
F_85 ( V_2 , V_159 ) ;
for ( V_132 = 0 ; V_132 < V_141 ; V_132 ++ ) {
int V_178 = 0 ;
error = V_129 ( & V_130 , & V_113 [ V_132 ] , & V_178 ) ;
if ( error || V_178 )
break;
}
F_84 ( V_113 ) ;
return error ;
}
int
F_86 (
struct V_1 * V_2 ,
T_12 V_179 ,
T_12 V_46 )
{
T_12 V_180 = V_46 ;
int error = 0 ;
ASSERT ( F_87 ( V_2 , V_49 ) ) ;
do {
int V_68 ;
T_22 V_181 ;
int V_182 = 1 ;
T_2 V_183 ;
T_4 V_6 ;
error = F_82 ( V_2 , V_179 , 1 , & V_181 , & V_182 ,
V_184 ) ;
if ( error ) {
if ( ! F_14 ( V_2 -> V_4 ) ) {
F_88 ( V_2 -> V_4 ,
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
F_89 ( V_181 . V_76 == 0 ) ;
F_90 ( & V_6 , & V_183 ) ;
error = F_91 ( NULL , V_2 , V_179 , 1 , 0 , 1 , & V_183 ,
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
F_92 ( struct V_1 * V_2 , bool V_187 )
{
if ( ! F_93 ( V_2 -> V_57 . V_188 ) )
return false ;
if ( F_76 ( V_2 ) -> V_189 == 0 &&
F_94 ( F_76 ( V_2 ) ) == 0 &&
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
F_95 (
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
V_194 = F_67 ( V_12 , ( V_197 ) F_68 ( V_2 ) ) ;
V_195 = F_67 ( V_12 , V_12 -> V_153 -> V_154 ) ;
if ( V_195 <= V_194 )
return 0 ;
V_196 = V_195 - V_194 ;
V_182 = 1 ;
F_22 ( V_2 , V_198 ) ;
error = F_82 ( V_2 , V_194 , V_196 , & V_181 , & V_182 , 0 ) ;
F_85 ( V_2 , V_198 ) ;
if ( ! error && ( V_182 != 0 ) &&
( V_181 . V_173 != V_120 ||
V_2 -> V_60 ) ) {
error = F_96 ( V_2 , 0 ) ;
if ( error )
return error ;
V_5 = F_97 ( V_12 , V_199 ) ;
if ( V_193 ) {
if ( ! F_98 ( V_2 , V_200 ) ) {
F_99 ( V_5 , 0 ) ;
return V_201 ;
}
}
error = F_11 ( V_5 , & F_100 ( V_12 ) -> V_202 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_14 ( V_12 ) ) ;
F_99 ( V_5 , 0 ) ;
if ( V_193 )
F_85 ( V_2 , V_200 ) ;
return error ;
}
F_22 ( V_2 , V_49 ) ;
F_23 ( V_5 , V_2 , 0 ) ;
error = F_101 ( & V_5 , V_2 , V_125 ,
F_68 ( V_2 ) ) ;
if ( error ) {
F_99 ( V_5 ,
( V_203 |
V_204 ) ) ;
} else {
error = F_9 ( V_5 ,
V_203 ) ;
if ( ! error )
F_102 ( V_2 ) ;
}
F_85 ( V_2 , V_49 ) ;
if ( V_193 )
F_85 ( V_2 , V_200 ) ;
}
return error ;
}
int
F_103 (
struct V_1 * V_2 ,
T_24 V_45 ,
T_24 V_205 ,
int V_206 )
{
T_8 * V_12 = V_2 -> V_4 ;
T_24 V_80 ;
T_23 V_207 ;
T_23 V_208 ;
T_10 V_209 , V_210 ;
T_12 V_211 ;
T_2 V_212 ;
int V_182 ;
int V_213 ;
int V_214 ;
T_3 * V_5 ;
T_22 V_215 [ 1 ] , * V_216 ;
T_4 V_217 ;
V_105 V_218 , V_219 , V_220 ;
int V_7 ;
int error ;
F_104 ( V_2 ) ;
if ( F_14 ( V_12 ) )
return F_58 ( V_221 ) ;
error = F_96 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_205 <= 0 )
return F_58 ( V_148 ) ;
V_214 = F_2 ( V_2 ) ;
V_209 = F_19 ( V_2 ) ;
V_80 = V_205 ;
V_216 = & V_215 [ 0 ] ;
V_182 = 1 ;
V_211 = F_105 ( V_12 , V_45 ) ;
V_208 = F_67 ( V_12 , V_80 ) ;
while ( V_208 && ! error ) {
T_12 V_222 , V_223 ;
if ( F_56 ( V_209 ) ) {
V_222 = V_211 ;
F_26 ( V_222 , V_209 ) ;
V_222 *= V_209 ;
V_223 = V_211 + V_208 ;
if ( ( V_210 = F_21 ( V_211 , V_209 ) ) )
V_223 += V_210 ;
if ( ( V_210 = F_21 ( V_223 , V_209 ) ) )
V_223 += V_209 - V_210 ;
} else {
V_222 = 0 ;
V_223 = V_208 ;
}
V_219 = F_106 ( T_12 , ( V_223 - V_222 ) , ( V_47 * V_182 ) ) ;
if ( F_56 ( V_214 ) ) {
V_220 = V_218 = V_219 ;
V_220 /= V_12 -> V_39 . V_40 ;
V_219 = F_107 ( V_12 , 0 ) ;
V_213 = V_224 ;
} else {
V_220 = 0 ;
V_219 = V_218 = F_107 ( V_12 , V_219 ) ;
V_213 = V_225 ;
}
V_5 = F_97 ( V_12 , V_226 ) ;
error = F_11 ( V_5 , & F_100 ( V_12 ) -> V_227 ,
V_219 , V_220 ) ;
if ( error ) {
ASSERT ( error == V_228 || F_14 ( V_12 ) ) ;
F_99 ( V_5 , 0 ) ;
break;
}
F_22 ( V_2 , V_49 ) ;
error = F_108 ( V_5 , V_2 , V_218 ,
0 , V_213 ) ;
if ( error )
goto V_229;
F_23 ( V_5 , V_2 , 0 ) ;
F_90 ( & V_217 , & V_212 ) ;
error = F_109 ( V_5 , V_2 , V_211 ,
V_208 , V_206 , & V_212 ,
0 , V_216 , & V_182 , & V_217 ) ;
if ( error ) {
goto V_230;
}
error = F_5 ( & V_5 , & V_217 , & V_7 ) ;
if ( error ) {
goto V_230;
}
error = F_9 ( V_5 , V_203 ) ;
F_85 ( V_2 , V_49 ) ;
if ( error ) {
break;
}
V_207 = V_216 -> V_76 ;
if ( V_182 == 0 ) {
error = F_58 ( V_228 ) ;
break;
}
V_211 += V_207 ;
V_208 -= V_207 ;
}
return error ;
V_230:
F_110 ( & V_217 ) ;
F_111 ( V_5 , V_2 , ( long ) V_218 , 0 , V_213 ) ;
V_229:
F_99 ( V_5 , V_203 | V_204 ) ;
F_85 ( V_2 , V_49 ) ;
return error ;
}
STATIC int
F_112 (
T_19 * V_2 ,
T_24 V_231 ,
T_24 V_71 )
{
T_22 V_181 ;
T_12 V_232 ;
T_24 V_233 ;
T_24 V_45 ;
T_17 * V_88 ;
T_8 * V_12 = V_2 -> V_4 ;
int V_234 ;
int error = 0 ;
if ( V_231 >= F_68 ( V_2 ) )
return 0 ;
if ( V_71 > F_68 ( V_2 ) )
V_71 = F_68 ( V_2 ) ;
V_88 = F_113 ( F_2 ( V_2 ) ?
V_12 -> V_235 : V_12 -> V_236 ,
F_114 ( V_12 -> V_39 . V_237 ) , 0 ) ;
if ( ! V_88 )
return F_58 ( V_158 ) ;
F_115 ( V_88 ) ;
for ( V_45 = V_231 ; V_45 <= V_71 ; V_45 = V_233 + 1 ) {
V_105 V_238 ;
V_232 = F_105 ( V_12 , V_45 ) ;
V_234 = 1 ;
V_238 = F_77 ( V_2 ) ;
error = F_82 ( V_2 , V_232 , 1 , & V_181 , & V_234 , 0 ) ;
F_85 ( V_2 , V_238 ) ;
if ( error || V_234 < 1 )
break;
ASSERT ( V_181 . V_76 >= 1 ) ;
ASSERT ( V_181 . V_75 == V_232 ) ;
V_233 = F_116 ( V_12 , V_181 . V_75 + 1 ) - 1 ;
if ( V_233 > V_71 )
V_233 = V_71 ;
if ( V_181 . V_173 == V_120 )
continue;
ASSERT ( V_181 . V_173 != V_124 ) ;
if ( V_181 . V_170 == V_171 )
continue;
F_117 ( V_88 ) ;
F_118 ( V_88 ) ;
F_119 ( V_88 ) ;
F_120 ( V_88 , F_1 ( V_2 , V_181 . V_173 ) ) ;
if ( F_14 ( V_12 ) ) {
error = F_58 ( V_221 ) ;
break;
}
F_121 ( V_88 ) ;
error = F_122 ( V_88 ) ;
if ( error ) {
F_123 ( V_88 ,
L_5 ) ;
break;
}
memset ( V_88 -> V_239 +
( V_45 - F_116 ( V_12 , V_181 . V_75 ) ) ,
0 , V_233 - V_45 + 1 ) ;
F_117 ( V_88 ) ;
F_124 ( V_88 ) ;
F_125 ( V_88 ) ;
if ( F_14 ( V_12 ) ) {
error = F_58 ( V_221 ) ;
break;
}
F_121 ( V_88 ) ;
error = F_122 ( V_88 ) ;
if ( error ) {
F_123 ( V_88 ,
L_6 ) ;
break;
}
}
F_126 ( V_88 ) ;
return error ;
}
int
F_127 (
struct V_1 * V_2 ,
T_24 V_45 ,
T_24 V_205 )
{
int V_7 ;
int V_68 ;
T_12 V_240 ;
int error ;
T_2 V_212 ;
T_4 V_217 ;
T_22 V_181 ;
T_24 V_241 ;
T_10 V_242 = 0 ;
T_8 * V_12 ;
int V_234 ;
V_105 V_219 ;
T_24 V_243 ;
int V_214 ;
T_12 V_211 ;
T_3 * V_5 ;
V_12 = V_2 -> V_4 ;
F_128 ( V_2 ) ;
error = F_96 ( V_2 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_205 <= 0 )
return error ;
V_214 = F_2 ( V_2 ) ;
V_211 = F_67 ( V_12 , V_45 ) ;
V_240 = F_105 ( V_12 , V_45 + V_205 ) ;
F_129 ( F_76 ( V_2 ) ) ;
V_243 = F_73 ( T_24 , 1 << V_12 -> V_39 . V_244 , V_245 ) ;
V_241 = V_45 & ~ ( V_243 - 1 ) ;
error = - F_130 ( F_76 ( V_2 ) -> V_162 ,
V_241 , - 1 ) ;
if ( error )
goto V_113;
F_131 ( F_76 ( V_2 ) , V_241 , - 1 ) ;
if ( V_214 && ! F_132 ( & V_12 -> V_39 ) ) {
V_234 = 1 ;
error = F_82 ( V_2 , V_211 , 1 ,
& V_181 , & V_234 , 0 ) ;
if ( error )
goto V_113;
ASSERT ( V_234 == 0 || V_234 == 1 ) ;
if ( V_234 && V_181 . V_173 != V_120 ) {
T_1 V_85 ;
ASSERT ( V_181 . V_173 != V_124 ) ;
V_85 = V_181 . V_173 ;
V_242 = F_26 ( V_85 , V_12 -> V_39 . V_40 ) ;
if ( V_242 )
V_211 += V_12 -> V_39 . V_40 - V_242 ;
}
V_234 = 1 ;
error = F_82 ( V_2 , V_240 - 1 , 1 ,
& V_181 , & V_234 , 0 ) ;
if ( error )
goto V_113;
ASSERT ( V_234 == 0 || V_234 == 1 ) ;
if ( V_234 && V_181 . V_173 != V_120 ) {
ASSERT ( V_181 . V_173 != V_124 ) ;
V_242 ++ ;
if ( V_242 && ( V_242 != V_12 -> V_39 . V_40 ) )
V_240 -= V_242 ;
}
}
if ( ( V_68 = ( V_240 <= V_211 ) ) )
error = F_112 ( V_2 , V_45 , V_45 + V_205 - 1 ) ;
else {
if ( V_45 < F_116 ( V_12 , V_211 ) )
error = F_112 ( V_2 , V_45 ,
F_116 ( V_12 , V_211 ) - 1 ) ;
if ( ! error &&
F_116 ( V_12 , V_240 ) < V_45 + V_205 )
error = F_112 ( V_2 ,
F_116 ( V_12 , V_240 ) ,
V_45 + V_205 - 1 ) ;
}
V_219 = F_107 ( V_12 , 0 ) ;
while ( ! error && ! V_68 ) {
V_5 = F_97 ( V_12 , V_226 ) ;
error = F_11 ( V_5 , & F_100 ( V_12 ) -> V_227 , V_219 , 0 ) ;
if ( error ) {
ASSERT ( error == V_228 || F_14 ( V_12 ) ) ;
F_99 ( V_5 , 0 ) ;
break;
}
F_22 ( V_2 , V_49 ) ;
error = F_133 ( V_5 , V_12 ,
V_2 -> V_246 , V_2 -> V_247 , V_2 -> V_248 ,
V_219 , 0 , V_225 ) ;
if ( error )
goto V_229;
F_23 ( V_5 , V_2 , 0 ) ;
F_90 ( & V_217 , & V_212 ) ;
error = F_91 ( V_5 , V_2 , V_211 ,
V_240 - V_211 ,
0 , 2 , & V_212 , & V_217 , & V_68 ) ;
if ( error ) {
goto V_230;
}
error = F_5 ( & V_5 , & V_217 , & V_7 ) ;
if ( error ) {
goto V_230;
}
error = F_9 ( V_5 , V_203 ) ;
F_85 ( V_2 , V_49 ) ;
}
V_113:
return error ;
V_230:
F_110 ( & V_217 ) ;
V_229:
F_99 ( V_5 , V_203 | V_204 ) ;
F_85 ( V_2 , V_49 ) ;
goto V_113;
}
int
F_134 (
struct V_1 * V_2 ,
T_24 V_45 ,
T_24 V_205 )
{
struct V_83 * V_12 = V_2 -> V_4 ;
V_105 V_249 ;
T_24 V_250 ;
T_24 V_251 ;
int error ;
F_135 ( V_2 ) ;
V_249 = F_73 ( V_105 , 1 << V_12 -> V_39 . V_244 , V_245 ) ;
V_250 = F_136 ( V_45 , V_249 ) ;
V_251 = F_137 ( V_45 + V_205 , V_249 ) ;
ASSERT ( V_250 >= V_45 ) ;
ASSERT ( V_251 <= V_45 + V_205 ) ;
if ( V_250 < V_251 - 1 ) {
F_22 ( V_2 , V_49 ) ;
error = F_86 ( V_2 ,
F_105 ( V_12 , V_250 ) ,
F_67 ( V_12 , V_251 - V_250 ) ) ;
F_85 ( V_2 , V_49 ) ;
F_131 ( F_76 ( V_2 ) , V_250 ,
V_251 - 1 ) ;
error = F_103 ( V_2 , V_250 ,
V_251 - V_250 - 1 ,
V_252 | V_253 ) ;
if ( error )
goto V_113;
if ( V_250 != V_45 ) {
error = F_138 ( V_2 , V_45 , V_250 - V_45 ) ;
if ( error )
goto V_113;
}
if ( V_251 != V_45 + V_205 )
error = F_138 ( V_2 , V_251 ,
V_45 + V_205 - V_251 ) ;
} else {
error = F_138 ( V_2 , V_45 , V_205 ) ;
}
V_113:
return error ;
}
int
F_139 (
struct V_1 * V_2 ,
T_24 V_45 ,
T_24 V_205 )
{
int V_68 = 0 ;
struct V_83 * V_12 = V_2 -> V_4 ;
struct V_254 * V_5 ;
int error ;
T_14 V_255 = 0 ;
struct V_256 V_217 ;
T_2 V_257 ;
int V_7 ;
T_12 V_179 ;
T_12 V_258 ;
ASSERT ( F_87 ( V_2 , V_200 ) ) ;
F_140 ( V_2 ) ;
V_179 = F_67 ( V_12 , V_45 + V_205 ) ;
V_258 = F_67 ( V_12 , V_205 ) ;
error = F_127 ( V_2 , V_45 , V_205 ) ;
if ( error )
return error ;
while ( ! error && ! V_68 ) {
V_5 = F_97 ( V_12 , V_226 ) ;
V_5 -> V_15 |= V_259 ;
error = F_11 ( V_5 , & F_100 ( V_12 ) -> V_227 ,
F_107 ( V_12 , 0 ) , 0 ) ;
if ( error ) {
ASSERT ( error == V_228 || F_14 ( V_12 ) ) ;
F_99 ( V_5 , 0 ) ;
break;
}
F_22 ( V_2 , V_49 ) ;
error = F_133 ( V_5 , V_12 , V_2 -> V_246 ,
V_2 -> V_247 , V_2 -> V_248 ,
F_107 ( V_12 , 0 ) , 0 ,
V_225 ) ;
if ( error )
goto V_113;
F_23 ( V_5 , V_2 , 0 ) ;
F_90 ( & V_217 , & V_257 ) ;
error = F_141 ( V_5 , V_2 , & V_68 , V_179 ,
V_258 , & V_255 ,
& V_257 , & V_217 ,
V_260 ) ;
if ( error )
goto V_113;
error = F_5 ( & V_5 , & V_217 , & V_7 ) ;
if ( error )
goto V_113;
error = F_9 ( V_5 , V_203 ) ;
F_85 ( V_2 , V_49 ) ;
}
return error ;
V_113:
F_99 ( V_5 , V_203 | V_204 ) ;
F_85 ( V_2 , V_49 ) ;
return error ;
}
static int
F_142 (
T_19 * V_2 ,
T_19 * V_261 )
{
if ( V_2 -> V_57 . V_149 == V_147 ||
V_261 -> V_57 . V_149 == V_147 )
return V_148 ;
if ( V_2 -> V_57 . V_262 < V_261 -> V_57 . V_262 )
return V_148 ;
if ( V_2 -> V_57 . V_149 == V_103 &&
V_261 -> V_57 . V_149 == V_146 )
return V_148 ;
if ( V_261 -> V_57 . V_149 == V_103 &&
F_79 ( V_261 , V_125 ) >
F_143 ( V_2 , V_125 ) )
return V_148 ;
if ( V_2 -> V_57 . V_149 == V_103 &&
F_79 ( V_2 , V_125 ) >
F_143 ( V_261 , V_125 ) )
return V_148 ;
if ( V_261 -> V_57 . V_149 == V_146 ) {
if ( F_144 ( V_2 ) &&
F_145 ( V_261 -> V_190 . V_106 ) > F_144 ( V_2 ) )
return V_148 ;
if ( F_79 ( V_261 , V_125 ) <=
F_143 ( V_2 , V_125 ) )
return V_148 ;
}
if ( V_2 -> V_57 . V_149 == V_146 ) {
if ( F_144 ( V_261 ) &&
F_145 ( V_2 -> V_190 . V_106 ) > F_144 ( V_261 ) )
return V_148 ;
if ( F_79 ( V_2 , V_125 ) <=
F_143 ( V_261 , V_125 ) )
return V_148 ;
}
return 0 ;
}
int
F_146 (
T_19 * V_2 ,
T_19 * V_261 ,
T_25 * V_263 )
{
T_8 * V_12 = V_2 -> V_4 ;
T_3 * V_5 ;
T_26 * V_264 = & V_263 -> V_265 ;
T_13 * V_266 , * V_77 , * V_267 ;
int V_268 , V_269 ;
int error = 0 ;
int V_270 = 0 ;
int V_271 = 0 ;
T_27 V_272 ;
V_266 = F_81 ( sizeof( T_13 ) , V_166 ) ;
if ( ! V_266 ) {
error = F_58 ( V_158 ) ;
goto V_113;
}
F_147 ( V_2 , V_261 , V_200 ) ;
F_147 ( V_2 , V_261 , V_49 ) ;
if ( ( V_2 -> V_57 . V_188 & V_273 ) != ( V_261 -> V_57 . V_188 & V_273 ) ) {
error = F_58 ( V_148 ) ;
goto V_274;
}
if ( F_2 ( V_2 ) != F_2 ( V_261 ) ) {
error = F_58 ( V_148 ) ;
goto V_274;
}
error = - F_75 ( F_76 ( V_261 ) -> V_162 ) ;
if ( error )
goto V_274;
F_131 ( F_76 ( V_261 ) , 0 , - 1 ) ;
if ( F_94 ( F_76 ( V_261 ) ) != 0 ) {
error = F_58 ( V_148 ) ;
goto V_274;
}
if ( V_263 -> V_275 != 0 ||
V_263 -> V_276 != V_2 -> V_57 . V_161 ||
V_263 -> V_276 != V_261 -> V_57 . V_161 ) {
error = F_58 ( V_277 ) ;
goto V_274;
}
F_148 ( V_2 , 0 ) ;
F_148 ( V_261 , 1 ) ;
error = F_142 ( V_2 , V_261 ) ;
if ( error ) {
F_149 ( V_12 ,
L_7 ,
V_278 , V_2 -> V_185 ) ;
goto V_274;
}
if ( ( V_264 -> V_279 . V_280 != F_76 ( V_2 ) -> V_281 . V_280 ) ||
( V_264 -> V_279 . V_282 != F_76 ( V_2 ) -> V_281 . V_282 ) ||
( V_264 -> V_283 . V_280 != F_76 ( V_2 ) -> V_284 . V_280 ) ||
( V_264 -> V_283 . V_282 != F_76 ( V_2 ) -> V_284 . V_282 ) ) {
error = F_58 ( V_285 ) ;
goto V_274;
}
if ( F_150 ( F_76 ( V_2 ) ) ) {
error = F_58 ( V_285 ) ;
goto V_274;
}
F_85 ( V_2 , V_49 ) ;
F_85 ( V_261 , V_49 ) ;
F_131 ( F_76 ( V_2 ) , 0 , - 1 ) ;
V_5 = F_97 ( V_12 , V_286 ) ;
error = F_11 ( V_5 , & F_100 ( V_12 ) -> V_287 , 0 , 0 ) ;
if ( error ) {
F_85 ( V_2 , V_200 ) ;
F_85 ( V_261 , V_200 ) ;
F_99 ( V_5 , 0 ) ;
goto V_113;
}
F_147 ( V_2 , V_261 , V_49 ) ;
if ( ( ( F_72 ( V_2 ) != 0 ) && ( V_2 -> V_57 . V_288 > 0 ) ) &&
( V_2 -> V_57 . V_145 != V_147 ) ) {
error = F_60 ( V_5 , V_2 , V_144 , & V_270 ) ;
if ( error )
goto V_289;
}
if ( ( ( F_72 ( V_261 ) != 0 ) && ( V_261 -> V_57 . V_288 > 0 ) ) &&
( V_261 -> V_57 . V_145 != V_147 ) ) {
error = F_60 ( V_5 , V_261 , V_144 ,
& V_271 ) ;
if ( error )
goto V_289;
}
F_23 ( V_5 , V_2 , V_49 | V_200 ) ;
F_23 ( V_5 , V_261 , V_49 | V_200 ) ;
V_268 = V_59 ;
V_269 = V_59 ;
if ( V_2 -> V_57 . V_290 == 3 &&
V_2 -> V_57 . V_149 == V_146 ) {
V_269 |= V_291 ;
error = F_151 ( V_5 , V_2 , V_125 ,
V_261 -> V_185 , NULL ) ;
if ( error )
goto V_289;
}
if ( V_261 -> V_57 . V_290 == 3 &&
V_261 -> V_57 . V_149 == V_146 ) {
V_268 |= V_291 ;
error = F_151 ( V_5 , V_261 , V_125 ,
V_2 -> V_185 , NULL ) ;
if ( error )
goto V_289;
}
V_77 = & V_2 -> V_190 ;
V_267 = & V_261 -> V_190 ;
* V_266 = * V_77 ;
* V_77 = * V_267 ;
* V_267 = * V_266 ;
V_272 = ( T_27 ) V_2 -> V_57 . V_58 ;
V_2 -> V_57 . V_58 = V_261 -> V_57 . V_58 - V_271 + V_270 ;
V_261 -> V_57 . V_58 = V_272 + V_271 - V_270 ;
V_272 = ( T_27 ) V_2 -> V_57 . V_262 ;
V_2 -> V_57 . V_262 = V_261 -> V_57 . V_262 ;
V_261 -> V_57 . V_262 = V_272 ;
V_272 = ( T_27 ) V_2 -> V_57 . V_149 ;
V_2 -> V_57 . V_149 = V_261 -> V_57 . V_149 ;
V_261 -> V_57 . V_149 = V_272 ;
ASSERT ( V_261 -> V_60 == 0 ) ;
V_261 -> V_60 = V_2 -> V_60 ;
V_2 -> V_60 = 0 ;
switch ( V_2 -> V_57 . V_149 ) {
case V_103 :
if ( V_2 -> V_57 . V_262 <= V_292 ) {
V_77 -> V_293 . V_294 =
V_77 -> V_295 . V_296 ;
}
V_268 |= V_297 ;
break;
case V_146 :
ASSERT ( V_2 -> V_57 . V_290 < 3 ||
( V_268 & V_291 ) ) ;
V_268 |= V_298 ;
break;
}
switch ( V_261 -> V_57 . V_149 ) {
case V_103 :
if ( V_261 -> V_57 . V_262 <= V_292 ) {
V_267 -> V_293 . V_294 =
V_267 -> V_295 . V_296 ;
}
V_269 |= V_297 ;
break;
case V_146 :
V_269 |= V_298 ;
ASSERT ( V_261 -> V_57 . V_290 < 3 ||
( V_269 & V_291 ) ) ;
break;
}
F_28 ( V_5 , V_2 , V_268 ) ;
F_28 ( V_5 , V_261 , V_269 ) ;
if ( V_12 -> V_299 & V_300 )
F_152 ( V_5 ) ;
error = F_9 ( V_5 , 0 ) ;
F_153 ( V_2 , 0 ) ;
F_153 ( V_261 , 1 ) ;
V_113:
F_84 ( V_266 ) ;
return error ;
V_274:
F_85 ( V_2 , V_49 | V_200 ) ;
F_85 ( V_261 , V_49 | V_200 ) ;
goto V_113;
V_289:
F_99 ( V_5 , 0 ) ;
goto V_274;
}
