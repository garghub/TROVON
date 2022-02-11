T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return ( F_2 ( V_2 ) ? \
( T_1 ) F_3 ( ( V_2 ) -> V_4 , ( V_3 ) ) : \
F_4 ( ( V_2 ) -> V_4 , ( V_3 ) ) ) ;
}
int
F_5 (
struct V_1 * V_2 ,
T_2 V_5 ,
T_3 V_6 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_1 V_9 = F_1 ( V_2 , V_5 ) ;
T_4 V_10 = F_6 ( V_8 , V_9 ) ;
T_5 V_11 = F_7 ( V_8 , V_6 ) ;
if ( F_8 ( F_9 ( V_2 ) ) )
return F_10 ( F_11 ( F_9 ( V_2 ) ) ,
V_9 , V_11 ) ;
return F_12 ( V_8 -> V_12 , V_10 , V_6 , V_13 ) ;
}
int
F_13 (
struct V_14 * * V_15 ,
struct V_16 * V_17 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int error ;
int V_22 ;
struct V_23 * free ;
struct V_23 * V_24 ;
ASSERT ( ( * V_15 ) -> V_25 & V_26 ) ;
if ( V_17 -> V_27 == 0 )
return 0 ;
V_21 = F_14 ( * V_15 , V_17 -> V_27 ) ;
for ( free = V_17 -> V_28 ; free ; free = free -> V_29 )
F_15 ( * V_15 , V_21 , free -> V_30 ,
free -> V_31 ) ;
error = F_16 ( V_15 , V_2 , & V_22 ) ;
if ( error ) {
if ( V_22 ) {
F_17 ( V_21 ) ;
F_18 ( ( * V_15 ) -> V_32 ,
( error == - V_33 ) ?
V_34 :
V_35 ) ;
}
return error ;
}
V_19 = F_19 ( * V_15 , V_21 , V_17 -> V_27 ) ;
for ( free = V_17 -> V_28 ; free != NULL ; free = V_24 ) {
V_24 = free -> V_29 ;
error = F_20 ( * V_15 , V_19 , free -> V_30 ,
free -> V_31 ) ;
if ( error )
return error ;
F_21 ( V_17 , NULL , free ) ;
}
return 0 ;
}
int
F_22 (
struct V_36 * V_37 )
{
T_6 V_38 = 0 ;
int error ;
T_7 * V_8 ;
T_8 V_39 = 0 ;
T_8 V_40 = 0 ;
T_8 V_41 ;
T_9 V_42 ;
V_8 = V_37 -> V_2 -> V_4 ;
V_41 = F_23 ( V_37 -> V_2 ) ;
V_39 = V_41 / V_8 -> V_43 . V_44 ;
error = F_24 ( V_8 , & V_37 -> V_45 , & V_37 -> V_46 ,
V_41 , 1 , V_37 -> V_47 , 0 ,
V_37 -> V_48 , & V_37 -> V_49 , & V_37 -> V_50 ) ;
if ( error )
return error ;
ASSERT ( V_37 -> V_50 ) ;
ASSERT ( V_37 -> V_50 % V_8 -> V_43 . V_44 == 0 ) ;
if ( F_25 ( V_37 -> V_49 , V_41 ) || V_37 -> V_50 % V_41 )
V_39 = 1 ;
V_40 = V_37 -> V_50 / V_8 -> V_43 . V_44 ;
if ( V_40 * V_8 -> V_43 . V_44 >= V_51 )
V_40 = V_51 / V_8 -> V_43 . V_44 ;
F_26 ( V_8 -> V_52 , V_53 ) ;
F_27 ( V_37 -> V_15 , V_8 -> V_52 , V_53 ) ;
F_26 ( V_8 -> V_54 , V_53 ) ;
F_27 ( V_37 -> V_15 , V_8 -> V_54 , V_53 ) ;
if ( V_37 -> V_47 && V_37 -> V_49 == 0 ) {
T_9 V_55 ( V_56 ) ;
error = F_28 ( V_8 , V_37 -> V_15 , V_40 , & V_56 ) ;
if ( error )
return error ;
V_37 -> V_57 = V_56 * V_8 -> V_43 . V_44 ;
} else {
V_37 -> V_57 = 0 ;
}
F_29 ( V_37 ) ;
V_38 = V_37 -> V_57 == 0 ? V_58 : V_59 ;
F_30 ( V_37 -> V_57 , V_8 -> V_43 . V_44 ) ;
V_42 = V_37 -> V_57 ;
V_37 -> V_50 = V_40 ;
if ( ( error = F_31 ( V_37 -> V_15 , V_37 -> V_57 , 1 , V_37 -> V_50 ,
& V_40 , V_38 , V_37 -> V_60 , V_39 , & V_42 ) ) )
return error ;
if ( V_42 == V_61 && V_39 > 1 &&
( error = F_31 ( V_37 -> V_15 , V_37 -> V_57 , 1 ,
V_37 -> V_50 , & V_40 , V_38 ,
V_37 -> V_60 , 1 , & V_42 ) ) )
return error ;
V_37 -> V_57 = V_42 ;
if ( V_37 -> V_57 != V_61 ) {
V_37 -> V_57 *= V_8 -> V_43 . V_44 ;
V_40 *= V_8 -> V_43 . V_44 ;
V_37 -> V_50 = V_40 ;
V_37 -> V_2 -> V_62 . V_63 += V_40 ;
F_32 ( V_37 -> V_15 , V_37 -> V_2 , V_64 ) ;
if ( V_37 -> V_60 )
V_37 -> V_2 -> V_65 -= V_40 ;
F_33 ( V_37 -> V_15 , V_37 -> V_2 ,
V_37 -> V_60 ? V_66 :
V_67 , ( long ) V_40 ) ;
if ( V_37 -> V_68 & V_69 ) {
error = F_5 ( V_37 -> V_2 , V_37 -> V_57 , V_37 -> V_50 ) ;
if ( error )
return error ;
}
} else {
V_37 -> V_50 = 0 ;
}
return 0 ;
}
int
F_34 (
struct V_1 * V_2 ,
T_10 V_70 ,
int V_71 ,
int * V_47 )
{
struct V_72 V_73 ;
int error ;
error = F_35 ( NULL , V_2 , V_71 , & V_73 , V_47 ) ;
if ( error || * V_47 )
return error ;
* V_47 = V_70 >= V_73 . V_74 + V_73 . V_75 ;
return 0 ;
}
STATIC void
F_36 (
T_11 * V_76 ,
T_12 V_77 ,
int V_78 ,
int * V_79 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_78 ; V_80 ++ ) {
T_13 * V_81 = F_37 ( V_76 , V_77 + V_80 ) ;
* V_79 += F_38 ( V_81 ) ;
}
}
STATIC void
F_39 (
struct V_7 * V_8 ,
struct V_82 * V_10 ,
int V_78 ,
int * V_79 )
{
int V_80 ;
T_14 * V_81 ;
for ( V_80 = 1 ; V_80 <= V_78 ; V_80 ++ ) {
V_81 = F_40 ( V_8 , V_10 , V_80 ) ;
* V_79 += F_41 ( V_81 ) ;
}
}
STATIC int
F_42 (
T_7 * V_8 ,
T_15 * V_15 ,
T_11 * V_76 ,
T_2 V_83 ,
int V_84 ,
int * V_79 )
{
int error ;
T_16 * V_85 , * V_86 ;
int V_87 = V_84 ;
T_17 * V_88 ;
T_2 V_89 = V_83 ;
T_2 V_90 ;
struct V_82 * V_10 , * V_91 ;
int V_78 ;
error = F_43 ( V_8 , V_15 , V_89 , 0 , & V_85 , V_92 ,
& V_93 ) ;
if ( error )
return error ;
* V_79 += 1 ;
V_10 = F_44 ( V_85 ) ;
if ( -- V_87 ) {
V_90 = F_45 ( V_10 -> V_94 . V_95 . V_96 ) ;
while ( V_90 != V_61 ) {
error = F_43 ( V_8 , V_15 , V_90 , 0 , & V_86 ,
V_92 ,
& V_93 ) ;
if ( error )
return error ;
* V_79 += 1 ;
V_91 = F_44 ( V_86 ) ;
V_90 = F_45 ( V_91 -> V_94 . V_95 . V_96 ) ;
F_46 ( V_15 , V_86 ) ;
}
V_88 = F_47 ( V_8 , V_10 , 1 , V_8 -> V_97 [ 1 ] ) ;
V_89 = F_45 ( * V_88 ) ;
if ( F_48 ( ( error =
F_42 ( V_8 , V_15 , V_76 , V_89 , V_87 , V_79 ) ) < 0 ) ) {
F_46 ( V_15 , V_85 ) ;
F_49 ( L_1 ,
V_98 , V_8 ) ;
return - V_33 ;
}
F_46 ( V_15 , V_85 ) ;
} else {
for (; ; ) {
V_90 = F_45 ( V_10 -> V_94 . V_95 . V_96 ) ;
V_78 = F_50 ( V_10 -> V_99 ) ;
F_39 ( V_8 , V_10 , V_78 , V_79 ) ;
F_46 ( V_15 , V_85 ) ;
if ( V_90 == V_61 )
break;
V_89 = V_90 ;
error = F_43 ( V_8 , V_15 , V_89 , 0 , & V_85 ,
V_92 ,
& V_93 ) ;
if ( error )
return error ;
* V_79 += 1 ;
V_10 = F_44 ( V_85 ) ;
}
}
return 0 ;
}
int
F_51 (
T_15 * V_15 ,
T_18 * V_2 ,
int V_71 ,
int * V_79 )
{
struct V_82 * V_10 ;
T_2 V_89 ;
T_11 * V_76 ;
int V_87 ;
T_7 * V_8 ;
T_17 * V_88 ;
V_89 = V_61 ;
V_8 = V_2 -> V_4 ;
V_76 = F_52 ( V_2 , V_71 ) ;
if ( F_53 ( V_2 , V_71 ) == V_100 ) {
F_36 ( V_76 , 0 ,
V_76 -> V_101 / ( V_102 ) sizeof( T_14 ) ,
V_79 ) ;
return 0 ;
}
V_10 = V_76 -> V_103 ;
V_87 = F_50 ( V_10 -> V_104 ) ;
ASSERT ( V_87 > 0 ) ;
V_88 = F_54 ( V_8 , V_10 , 1 , V_76 -> V_105 ) ;
V_89 = F_45 ( * V_88 ) ;
ASSERT ( V_89 != V_61 ) ;
ASSERT ( F_55 ( V_8 , V_89 ) < V_8 -> V_43 . V_106 ) ;
ASSERT ( F_56 ( V_8 , V_89 ) < V_8 -> V_43 . V_107 ) ;
if ( F_48 ( F_42 ( V_8 , V_15 , V_76 , V_89 , V_87 , V_79 ) < 0 ) ) {
F_49 ( L_2 , V_98 ,
V_8 ) ;
return - V_33 ;
}
return 0 ;
}
STATIC int
F_57 (
T_18 * V_2 ,
struct V_108 * V_109 ,
int V_110 ,
T_19 V_111 ,
T_2 V_112 )
{
T_19 V_113 ;
T_7 * V_8 ;
T_11 * V_76 ;
T_12 V_114 ;
T_10 V_115 ;
if ( V_112 == V_116 ) {
V_8 = V_2 -> V_4 ;
V_109 -> V_117 = - 1 ;
V_113 = F_3 ( V_8 , F_58 ( V_8 , F_59 ( V_2 ) ) ) ;
V_113 -= V_109 -> V_118 ;
if ( V_110 && V_109 -> V_118 + V_109 -> V_119 == V_111 ) {
if ( V_113 <= 0 )
return 0 ;
V_109 -> V_119 = V_113 ;
}
} else {
if ( V_112 == V_120 )
V_109 -> V_117 = - 2 ;
else
V_109 -> V_117 = F_1 ( V_2 , V_112 ) ;
V_115 = F_60 ( V_2 -> V_4 , V_109 -> V_118 ) ;
V_76 = F_52 ( V_2 , V_121 ) ;
if ( F_61 ( V_76 , V_115 , & V_114 ) &&
( V_114 == ( V_76 -> V_101 / ( V_102 ) sizeof( T_14 ) ) - 1 ) )
V_109 -> V_122 |= V_123 ;
}
return 1 ;
}
int
F_62 (
T_18 * V_2 ,
struct V_108 * V_124 ,
T_20 V_125 ,
void * V_126 )
{
T_19 V_127 ;
int error = 0 ;
T_19 V_113 ;
int V_128 ;
int V_129 ;
T_21 * V_130 ;
T_7 * V_8 ;
int V_131 ;
int V_132 ;
int V_133 ;
int V_134 ;
struct V_108 * V_109 ;
int V_71 ;
int V_110 ;
int V_135 ;
int V_136 ;
int V_137 = 0 ;
V_8 = V_2 -> V_4 ;
V_135 = V_124 -> V_138 ;
V_71 = V_135 & V_139 ? V_140 : V_121 ;
if ( V_71 == V_140 ) {
if ( F_63 ( V_2 ) ) {
if ( V_2 -> V_62 . V_141 != V_100 &&
V_2 -> V_62 . V_141 != V_142 &&
V_2 -> V_62 . V_141 != V_143 )
return - V_144 ;
} else if ( F_48 (
V_2 -> V_62 . V_141 != 0 &&
V_2 -> V_62 . V_141 != V_100 ) ) {
F_49 ( L_3 , V_98 ,
V_2 -> V_4 ) ;
return - V_33 ;
}
V_110 = 0 ;
V_113 = 1LL << 32 ;
} else {
if ( V_2 -> V_62 . V_145 != V_100 &&
V_2 -> V_62 . V_145 != V_142 &&
V_2 -> V_62 . V_145 != V_143 )
return - V_144 ;
if ( F_23 ( V_2 ) ||
V_2 -> V_62 . V_146 & ( V_147 | V_148 ) ) {
V_110 = 1 ;
V_113 = V_8 -> V_12 -> V_149 ;
} else {
V_110 = 0 ;
V_113 = F_59 ( V_2 ) ;
}
}
if ( V_124 -> V_119 == - 1 ) {
V_113 = F_3 ( V_8 , F_58 ( V_8 , V_113 ) ) ;
V_124 -> V_119 =
F_64 ( T_19 , V_113 - V_124 -> V_118 , 0 ) ;
} else if ( V_124 -> V_119 == 0 ) {
V_124 -> V_150 = 0 ;
return 0 ;
} else if ( V_124 -> V_119 < 0 ) {
return - V_144 ;
}
V_131 = V_124 -> V_151 - 1 ;
if ( V_131 <= 0 )
return - V_144 ;
V_127 = V_124 -> V_118 + V_124 -> V_119 ;
if ( V_124 -> V_151 > V_152 / sizeof( struct V_108 ) )
return - V_153 ;
V_109 = F_65 ( V_124 -> V_151 * sizeof( struct V_108 ) , 0 ) ;
if ( ! V_109 )
return - V_153 ;
F_26 ( V_2 , V_154 ) ;
if ( V_71 == V_121 ) {
if ( ! ( V_135 & V_155 ) &&
( V_2 -> V_65 || F_59 ( V_2 ) > V_2 -> V_62 . V_156 ) ) {
error = F_66 ( F_9 ( V_2 ) -> V_157 ) ;
if ( error )
goto V_158;
}
V_129 = F_67 ( V_2 ) ;
} else {
V_129 = F_68 ( V_2 ) ;
}
if ( V_131 > F_69 ( V_2 , V_71 ) * 2 + 1 )
V_131 = F_69 ( V_2 , V_71 ) * 2 + 1 ;
V_136 = F_70 ( V_71 ) ;
if ( ! ( V_135 & V_159 ) )
V_136 |= V_160 ;
error = - V_153 ;
V_133 = 16 ;
V_130 = F_71 ( V_133 * sizeof( * V_130 ) , V_161 | V_162 ) ;
if ( ! V_130 )
goto V_163;
V_124 -> V_150 = 0 ;
if ( F_69 ( V_2 , V_71 ) == 0 &&
( V_71 == V_140 || ! ( V_135 & V_155 ) ) ) {
error = 0 ;
goto V_164;
}
V_132 = V_131 ;
do {
V_134 = ( V_132 > V_133 ) ? V_133 : V_132 ;
error = F_72 ( V_2 , F_6 ( V_8 , V_124 -> V_118 ) ,
F_60 ( V_8 , V_124 -> V_119 ) ,
V_130 , & V_134 , V_136 ) ;
if ( error )
goto V_164;
ASSERT ( V_134 <= V_133 ) ;
for ( V_128 = 0 ; V_128 < V_134 && V_132 && V_124 -> V_119 ; V_128 ++ ) {
V_109 [ V_137 ] . V_122 = 0 ;
if ( V_130 [ V_128 ] . V_165 == V_166 )
V_109 [ V_137 ] . V_122 |= V_167 ;
else if ( V_130 [ V_128 ] . V_168 == V_120 )
V_109 [ V_137 ] . V_122 |= V_169 ;
V_109 [ V_137 ] . V_118 =
F_3 ( V_8 , V_130 [ V_128 ] . V_74 ) ;
V_109 [ V_137 ] . V_119 =
F_3 ( V_8 , V_130 [ V_128 ] . V_75 ) ;
V_109 [ V_137 ] . V_170 = 0 ;
V_109 [ V_137 ] . V_171 = 0 ;
if ( V_130 [ V_128 ] . V_168 == V_120 &&
V_130 [ V_128 ] . V_74 <= F_58 ( V_8 , F_59 ( V_2 ) ) )
ASSERT ( ( V_135 & V_155 ) != 0 ) ;
if ( V_130 [ V_128 ] . V_168 == V_116 &&
V_71 == V_140 ) {
V_109 [ V_137 ] . V_122 |= V_123 ;
goto V_164;
}
if ( ! F_57 ( V_2 , & V_109 [ V_137 ] ,
V_110 , V_127 ,
V_130 [ V_128 ] . V_168 ) )
goto V_164;
V_124 -> V_118 =
V_109 [ V_137 ] . V_118 +
V_109 [ V_137 ] . V_119 ;
V_124 -> V_119 =
F_64 ( T_19 , 0 , V_127 - V_124 -> V_118 ) ;
if ( ( V_135 & V_172 ) &&
V_130 [ V_128 ] . V_168 == V_116 ) {
memset ( & V_109 [ V_137 ] , 0 , sizeof( V_109 [ V_137 ] ) ) ;
continue;
}
V_132 -- ;
V_124 -> V_150 ++ ;
V_137 ++ ;
}
} while ( V_134 && V_132 && V_124 -> V_119 );
V_164:
F_73 ( V_130 ) ;
V_163:
F_74 ( V_2 , V_129 ) ;
V_158:
F_74 ( V_2 , V_154 ) ;
for ( V_128 = 0 ; V_128 < V_137 ; V_128 ++ ) {
int V_173 = 0 ;
error = V_125 ( & V_126 , & V_109 [ V_128 ] , & V_173 ) ;
if ( error || V_173 )
break;
}
F_73 ( V_109 ) ;
return error ;
}
int
F_75 (
struct V_1 * V_2 ,
T_10 V_5 ,
T_10 V_50 )
{
T_10 V_174 = V_50 ;
int error = 0 ;
ASSERT ( F_76 ( V_2 , V_53 ) ) ;
do {
int V_175 ;
T_21 V_176 ;
int V_177 = 1 ;
T_2 V_178 ;
T_22 V_17 ;
error = F_72 ( V_2 , V_5 , 1 , & V_176 , & V_177 ,
V_179 ) ;
if ( error ) {
if ( ! F_77 ( V_2 -> V_4 ) ) {
F_78 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_180 , V_5 ) ;
}
break;
}
if ( ! V_177 ) {
goto V_181;
}
if ( V_176 . V_168 != V_120 ) {
goto V_181;
}
F_79 ( V_176 . V_75 == 0 ) ;
F_80 ( & V_17 , & V_178 ) ;
error = F_81 ( NULL , V_2 , V_5 , 1 , 0 , 1 , & V_178 ,
& V_17 , & V_175 ) ;
if ( error )
break;
ASSERT ( ! V_17 . V_27 && ! V_17 . V_28 ) ;
V_181:
V_5 ++ ;
V_174 -- ;
} while( V_174 > 0 );
return error ;
}
bool
F_82 ( struct V_1 * V_2 , bool V_182 )
{
if ( ! F_83 ( F_9 ( V_2 ) -> V_183 ) )
return false ;
if ( F_9 ( V_2 ) -> V_184 == 0 &&
F_9 ( V_2 ) -> V_157 -> V_185 == 0 &&
V_2 -> V_65 == 0 )
return false ;
if ( ! ( V_2 -> V_186 . V_187 & V_188 ) )
return false ;
if ( V_2 -> V_62 . V_146 & ( V_147 | V_148 ) )
if ( ! V_182 || V_2 -> V_65 == 0 )
return false ;
return true ;
}
int
F_84 (
T_7 * V_8 ,
T_18 * V_2 ,
bool V_189 )
{
T_15 * V_15 ;
int error ;
T_10 V_190 ;
T_10 V_191 ;
T_23 V_192 ;
int V_177 ;
T_21 V_176 ;
V_190 = F_58 ( V_8 , ( V_193 ) F_59 ( V_2 ) ) ;
V_191 = F_58 ( V_8 , V_8 -> V_12 -> V_149 ) ;
if ( V_191 <= V_190 )
return 0 ;
V_192 = V_191 - V_190 ;
V_177 = 1 ;
F_26 ( V_2 , V_194 ) ;
error = F_72 ( V_2 , V_190 , V_192 , & V_176 , & V_177 , 0 ) ;
F_74 ( V_2 , V_194 ) ;
if ( ! error && ( V_177 != 0 ) &&
( V_176 . V_168 != V_116 ||
V_2 -> V_65 ) ) {
error = F_85 ( V_2 , 0 ) ;
if ( error )
return error ;
V_15 = F_86 ( V_8 , V_195 ) ;
if ( V_189 ) {
if ( ! F_87 ( V_2 , V_196 ) ) {
F_88 ( V_15 ) ;
return - V_197 ;
}
}
error = F_89 ( V_15 , & F_90 ( V_8 ) -> V_198 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_77 ( V_8 ) ) ;
F_88 ( V_15 ) ;
if ( V_189 )
F_74 ( V_2 , V_196 ) ;
return error ;
}
F_26 ( V_2 , V_53 ) ;
F_27 ( V_15 , V_2 , 0 ) ;
error = F_91 ( & V_15 , V_2 , V_121 ,
F_59 ( V_2 ) ) ;
if ( error ) {
F_88 ( V_15 ) ;
} else {
error = F_92 ( V_15 ) ;
if ( ! error )
F_93 ( V_2 ) ;
}
F_74 ( V_2 , V_53 ) ;
if ( V_189 )
F_74 ( V_2 , V_196 ) ;
}
return error ;
}
int
F_94 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_199 ,
int V_200 )
{
T_7 * V_8 = V_2 -> V_4 ;
T_3 V_79 ;
T_23 V_201 ;
T_23 V_202 ;
T_8 V_203 , V_204 ;
T_10 V_205 ;
T_2 V_206 ;
int V_177 ;
int V_207 ;
int V_208 ;
T_15 * V_15 ;
T_21 V_209 [ 1 ] , * V_210 ;
T_22 V_211 ;
V_102 V_212 , V_213 , V_214 ;
int error ;
F_95 ( V_2 ) ;
if ( F_77 ( V_8 ) )
return - V_215 ;
error = F_85 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_199 <= 0 )
return - V_144 ;
V_208 = F_2 ( V_2 ) ;
V_203 = F_23 ( V_2 ) ;
V_79 = V_199 ;
V_210 = & V_209 [ 0 ] ;
V_177 = 1 ;
V_205 = F_96 ( V_8 , V_49 ) ;
V_202 = F_58 ( V_8 , V_79 ) ;
while ( V_202 && ! error ) {
T_10 V_216 , V_217 ;
if ( F_48 ( V_203 ) ) {
V_216 = V_205 ;
F_30 ( V_216 , V_203 ) ;
V_216 *= V_203 ;
V_217 = V_205 + V_202 ;
if ( ( V_204 = F_25 ( V_205 , V_203 ) ) )
V_217 += V_204 ;
if ( ( V_204 = F_25 ( V_217 , V_203 ) ) )
V_217 += V_203 - V_204 ;
} else {
V_216 = 0 ;
V_217 = V_202 ;
}
V_213 = F_97 ( T_10 , ( V_217 - V_216 ) , ( V_51 * V_177 ) ) ;
if ( F_48 ( V_208 ) ) {
V_214 = V_212 = V_213 ;
V_214 /= V_8 -> V_43 . V_44 ;
V_213 = F_98 ( V_8 , 0 ) ;
V_207 = V_218 ;
} else {
V_214 = 0 ;
V_213 = V_212 = F_98 ( V_8 , V_213 ) ;
V_207 = V_219 ;
}
V_15 = F_86 ( V_8 , V_220 ) ;
error = F_89 ( V_15 , & F_90 ( V_8 ) -> V_221 ,
V_213 , V_214 ) ;
if ( error ) {
ASSERT ( error == - V_222 || F_77 ( V_8 ) ) ;
F_88 ( V_15 ) ;
break;
}
F_26 ( V_2 , V_53 ) ;
error = F_99 ( V_15 , V_2 , V_212 ,
0 , V_207 ) ;
if ( error )
goto V_223;
F_27 ( V_15 , V_2 , 0 ) ;
F_80 ( & V_211 , & V_206 ) ;
error = F_100 ( V_15 , V_2 , V_205 ,
V_202 , V_200 , & V_206 ,
V_213 , V_210 , & V_177 , & V_211 ) ;
if ( error )
goto V_224;
error = F_13 ( & V_15 , & V_211 , NULL ) ;
if ( error )
goto V_224;
error = F_92 ( V_15 ) ;
F_74 ( V_2 , V_53 ) ;
if ( error )
break;
V_201 = V_210 -> V_75 ;
if ( V_177 == 0 ) {
error = - V_222 ;
break;
}
V_205 += V_201 ;
V_202 -= V_201 ;
}
return error ;
V_224:
F_101 ( & V_211 ) ;
F_102 ( V_15 , V_2 , ( long ) V_212 , 0 , V_207 ) ;
V_223:
F_88 ( V_15 ) ;
F_74 ( V_2 , V_53 ) ;
return error ;
}
STATIC int
F_103 (
T_18 * V_2 ,
T_3 V_225 ,
T_3 V_70 )
{
T_21 V_176 ;
T_10 V_226 ;
T_3 V_227 ;
T_3 V_49 ;
T_16 * V_85 ;
T_7 * V_8 = V_2 -> V_4 ;
int V_228 ;
int error = 0 ;
if ( V_225 >= F_59 ( V_2 ) )
return 0 ;
if ( V_70 > F_59 ( V_2 ) )
V_70 = F_59 ( V_2 ) ;
for ( V_49 = V_225 ; V_49 <= V_70 ; V_49 = V_227 + 1 ) {
V_102 V_229 ;
V_226 = F_96 ( V_8 , V_49 ) ;
V_228 = 1 ;
V_229 = F_67 ( V_2 ) ;
error = F_72 ( V_2 , V_226 , 1 , & V_176 , & V_228 , 0 ) ;
F_74 ( V_2 , V_229 ) ;
if ( error || V_228 < 1 )
break;
ASSERT ( V_176 . V_75 >= 1 ) ;
ASSERT ( V_176 . V_74 == V_226 ) ;
ASSERT ( V_176 . V_168 != V_120 ) ;
if ( V_176 . V_168 == V_116 ||
V_176 . V_165 == V_166 ) {
V_227 = F_7 ( V_8 , V_176 . V_74 +
V_176 . V_75 ) - 1 ;
continue;
}
V_227 = F_7 ( V_8 , V_176 . V_74 + 1 ) - 1 ;
if ( V_227 > V_70 )
V_227 = V_70 ;
if ( F_8 ( F_9 ( V_2 ) ) ) {
error = F_104 ( F_9 ( V_2 ) , V_49 ,
V_227 - V_49 + 1 ,
V_230 ) ;
if ( error )
return error ;
continue;
}
error = F_105 ( F_2 ( V_2 ) ?
V_8 -> V_231 : V_8 -> V_232 ,
F_1 ( V_2 , V_176 . V_168 ) ,
F_106 ( V_8 -> V_43 . V_233 ) ,
0 , & V_85 , NULL ) ;
if ( error )
return error ;
memset ( V_85 -> V_234 +
( V_49 - F_7 ( V_8 , V_176 . V_74 ) ) ,
0 , V_227 - V_49 + 1 ) ;
error = F_107 ( V_85 ) ;
F_108 ( V_85 ) ;
if ( error )
return error ;
}
return error ;
}
int
F_109 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_199 )
{
int V_175 ;
T_10 V_235 ;
int error ;
T_2 V_206 ;
T_22 V_211 ;
T_21 V_176 ;
T_3 V_236 ;
T_3 V_237 ;
T_8 V_238 = 0 ;
T_7 * V_8 ;
int V_228 ;
V_102 V_213 ;
T_3 V_239 ;
int V_208 ;
T_10 V_205 ;
T_15 * V_15 ;
V_8 = V_2 -> V_4 ;
F_110 ( V_2 ) ;
error = F_85 ( V_2 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_199 <= 0 )
return error ;
V_208 = F_2 ( V_2 ) ;
V_205 = F_58 ( V_8 , V_49 ) ;
V_235 = F_96 ( V_8 , V_49 + V_199 ) ;
F_111 ( F_9 ( V_2 ) ) ;
V_239 = F_64 ( T_3 , 1 << V_8 -> V_43 . V_240 , V_241 ) ;
V_236 = F_112 ( V_49 , V_239 ) ;
V_237 = F_113 ( V_49 + V_199 , V_239 ) - 1 ;
error = F_114 ( F_9 ( V_2 ) -> V_157 , V_236 ,
V_237 ) ;
if ( error )
goto V_109;
F_115 ( F_9 ( V_2 ) , V_236 , V_237 ) ;
if ( V_208 && ! F_116 ( & V_8 -> V_43 ) ) {
V_228 = 1 ;
error = F_72 ( V_2 , V_205 , 1 ,
& V_176 , & V_228 , 0 ) ;
if ( error )
goto V_109;
ASSERT ( V_228 == 0 || V_228 == 1 ) ;
if ( V_228 && V_176 . V_168 != V_116 ) {
T_1 V_10 ;
ASSERT ( V_176 . V_168 != V_120 ) ;
V_10 = V_176 . V_168 ;
V_238 = F_30 ( V_10 , V_8 -> V_43 . V_44 ) ;
if ( V_238 )
V_205 += V_8 -> V_43 . V_44 - V_238 ;
}
V_228 = 1 ;
error = F_72 ( V_2 , V_235 - 1 , 1 ,
& V_176 , & V_228 , 0 ) ;
if ( error )
goto V_109;
ASSERT ( V_228 == 0 || V_228 == 1 ) ;
if ( V_228 && V_176 . V_168 != V_116 ) {
ASSERT ( V_176 . V_168 != V_120 ) ;
V_238 ++ ;
if ( V_238 && ( V_238 != V_8 -> V_43 . V_44 ) )
V_235 -= V_238 ;
}
}
if ( ( V_175 = ( V_235 <= V_205 ) ) )
error = F_103 ( V_2 , V_49 , V_49 + V_199 - 1 ) ;
else {
if ( V_49 < F_7 ( V_8 , V_205 ) )
error = F_103 ( V_2 , V_49 ,
F_7 ( V_8 , V_205 ) - 1 ) ;
if ( ! error &&
F_7 ( V_8 , V_235 ) < V_49 + V_199 )
error = F_103 ( V_2 ,
F_7 ( V_8 , V_235 ) ,
V_49 + V_199 - 1 ) ;
}
V_213 = F_98 ( V_8 , 0 ) ;
while ( ! error && ! V_175 ) {
V_15 = F_86 ( V_8 , V_220 ) ;
error = F_89 ( V_15 , & F_90 ( V_8 ) -> V_221 , V_213 , 0 ) ;
if ( error ) {
ASSERT ( error == - V_222 || F_77 ( V_8 ) ) ;
F_88 ( V_15 ) ;
break;
}
F_26 ( V_2 , V_53 ) ;
error = F_117 ( V_15 , V_8 ,
V_2 -> V_242 , V_2 -> V_243 , V_2 -> V_244 ,
V_213 , 0 , V_219 ) ;
if ( error )
goto V_223;
F_27 ( V_15 , V_2 , 0 ) ;
F_80 ( & V_211 , & V_206 ) ;
error = F_81 ( V_15 , V_2 , V_205 ,
V_235 - V_205 ,
0 , 2 , & V_206 , & V_211 , & V_175 ) ;
if ( error )
goto V_224;
error = F_13 ( & V_15 , & V_211 , NULL ) ;
if ( error )
goto V_224;
error = F_92 ( V_15 ) ;
F_74 ( V_2 , V_53 ) ;
}
V_109:
return error ;
V_224:
F_101 ( & V_211 ) ;
V_223:
F_88 ( V_15 ) ;
F_74 ( V_2 , V_53 ) ;
goto V_109;
}
int
F_118 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_199 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
V_102 V_245 ;
int error ;
F_119 ( V_2 ) ;
V_245 = 1 << V_8 -> V_43 . V_240 ;
error = F_109 ( V_2 , V_49 , V_199 ) ;
if ( error )
goto V_109;
error = F_94 ( V_2 , F_112 ( V_49 , V_245 ) ,
F_113 ( V_49 + V_199 , V_245 ) -
F_112 ( V_49 , V_245 ) ,
V_246 ) ;
V_109:
return error ;
}
static int
F_120 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_199 ,
enum V_247 V_248 )
{
int V_175 = 0 ;
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_14 * V_15 ;
int error ;
struct V_16 V_211 ;
T_2 V_249 ;
T_10 V_250 ;
T_10 V_251 ;
T_10 V_252 ;
ASSERT ( V_248 == V_253 || V_248 == V_254 ) ;
if ( V_248 == V_253 ) {
V_251 = F_58 ( V_8 , V_49 + V_199 ) ;
V_250 = F_58 ( V_8 , F_9 ( V_2 ) -> V_184 ) ;
} else {
V_251 = V_61 ;
V_250 = F_58 ( V_8 , V_49 ) ;
}
V_252 = F_58 ( V_8 , V_199 ) ;
if ( F_82 ( V_2 , true ) ) {
error = F_84 ( V_8 , V_2 , false ) ;
if ( error )
return error ;
}
error = F_114 ( F_9 ( V_2 ) -> V_157 ,
V_49 , - 1 ) ;
if ( error )
return error ;
error = F_121 ( F_9 ( V_2 ) -> V_157 ,
V_49 >> V_255 , - 1 ) ;
if ( error )
return error ;
if ( V_248 == V_254 ) {
error = F_122 ( V_2 , V_250 ) ;
if ( error )
return error ;
}
while ( ! error && ! V_175 ) {
V_15 = F_86 ( V_8 , V_220 ) ;
error = F_89 ( V_15 , & F_90 ( V_8 ) -> V_221 ,
F_98 ( V_8 , 0 ) , 0 ) ;
if ( error ) {
F_88 ( V_15 ) ;
break;
}
F_26 ( V_2 , V_53 ) ;
error = F_117 ( V_15 , V_8 , V_2 -> V_242 ,
V_2 -> V_243 , V_2 -> V_244 ,
F_98 ( V_8 , 0 ) , 0 ,
V_219 ) ;
if ( error )
goto V_256;
F_27 ( V_15 , V_2 , V_53 ) ;
F_80 ( & V_211 , & V_249 ) ;
error = F_123 ( V_15 , V_2 , & V_251 , V_252 ,
& V_175 , V_250 , & V_249 , & V_211 ,
V_248 , V_257 ) ;
if ( error )
goto V_258;
error = F_13 ( & V_15 , & V_211 , NULL ) ;
if ( error )
goto V_258;
error = F_92 ( V_15 ) ;
}
return error ;
V_258:
F_101 ( & V_211 ) ;
V_256:
F_88 ( V_15 ) ;
return error ;
}
int
F_124 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_199 )
{
int error ;
ASSERT ( F_76 ( V_2 , V_196 ) ) ;
F_125 ( V_2 ) ;
error = F_109 ( V_2 , V_49 , V_199 ) ;
if ( error )
return error ;
return F_120 ( V_2 , V_49 , V_199 , V_253 ) ;
}
int
F_126 (
struct V_1 * V_2 ,
T_24 V_49 ,
T_24 V_199 )
{
ASSERT ( F_76 ( V_2 , V_196 ) ) ;
F_127 ( V_2 ) ;
return F_120 ( V_2 , V_49 , V_199 , V_254 ) ;
}
static int
F_128 (
T_18 * V_2 ,
T_18 * V_259 )
{
if ( V_2 -> V_62 . V_145 == V_143 ||
V_259 -> V_62 . V_145 == V_143 )
return - V_144 ;
if ( V_2 -> V_62 . V_260 < V_259 -> V_62 . V_260 )
return - V_144 ;
if ( V_2 -> V_62 . V_145 == V_100 &&
V_259 -> V_62 . V_145 == V_142 )
return - V_144 ;
if ( V_259 -> V_62 . V_145 == V_100 &&
F_69 ( V_259 , V_121 ) >
F_129 ( V_2 , V_121 ) )
return - V_144 ;
if ( V_2 -> V_62 . V_145 == V_100 &&
F_69 ( V_2 , V_121 ) >
F_129 ( V_259 , V_121 ) )
return - V_144 ;
if ( V_259 -> V_62 . V_145 == V_142 ) {
if ( F_130 ( V_2 ) &&
F_131 ( V_259 -> V_186 . V_103 ) > F_130 ( V_2 ) )
return - V_144 ;
if ( F_69 ( V_259 , V_121 ) <=
F_129 ( V_2 , V_121 ) )
return - V_144 ;
}
if ( V_2 -> V_62 . V_145 == V_142 ) {
if ( F_130 ( V_259 ) &&
F_131 ( V_2 -> V_186 . V_103 ) > F_130 ( V_259 ) )
return - V_144 ;
if ( F_69 ( V_2 , V_121 ) <=
F_129 ( V_259 , V_121 ) )
return - V_144 ;
}
return 0 ;
}
static int
F_132 (
struct V_1 * V_2 )
{
int error ;
error = F_66 ( F_9 ( V_2 ) -> V_157 ) ;
if ( error )
return error ;
F_115 ( F_9 ( V_2 ) , 0 , - 1 ) ;
if ( F_9 ( V_2 ) -> V_157 -> V_185 )
return - V_144 ;
return 0 ;
}
int
F_133 (
T_18 * V_2 ,
T_18 * V_259 ,
T_25 * V_261 )
{
T_7 * V_8 = V_2 -> V_4 ;
T_15 * V_15 ;
T_26 * V_262 = & V_261 -> V_263 ;
T_11 * V_264 , * V_76 , * V_265 ;
int V_266 , V_267 ;
int error = 0 ;
int V_268 = 0 ;
int V_269 = 0 ;
T_27 V_270 ;
int V_271 ;
V_264 = F_71 ( sizeof( T_11 ) , V_161 ) ;
if ( ! V_264 ) {
error = - V_153 ;
goto V_109;
}
V_271 = V_196 | V_272 ;
F_134 ( V_2 , V_259 , V_196 ) ;
F_134 ( V_2 , V_259 , V_272 ) ;
if ( ( F_9 ( V_2 ) -> V_183 & V_273 ) != ( F_9 ( V_259 ) -> V_183 & V_273 ) ) {
error = - V_144 ;
goto V_274;
}
if ( F_2 ( V_2 ) != F_2 ( V_259 ) ) {
error = - V_144 ;
goto V_274;
}
error = F_132 ( V_2 ) ;
if ( error )
goto V_274;
error = F_132 ( V_259 ) ;
if ( error )
goto V_274;
V_15 = F_86 ( V_8 , V_275 ) ;
error = F_89 ( V_15 , & F_90 ( V_8 ) -> V_276 , 0 , 0 ) ;
if ( error ) {
F_88 ( V_15 ) ;
goto V_274;
}
F_134 ( V_2 , V_259 , V_53 ) ;
V_271 |= V_53 ;
F_27 ( V_15 , V_2 , V_271 ) ;
F_27 ( V_15 , V_259 , V_271 ) ;
if ( V_261 -> V_277 != 0 ||
V_261 -> V_278 != V_2 -> V_62 . V_156 ||
V_261 -> V_278 != V_259 -> V_62 . V_156 ) {
error = - V_279 ;
goto V_256;
}
F_135 ( V_2 , 0 ) ;
F_135 ( V_259 , 1 ) ;
error = F_128 ( V_2 , V_259 ) ;
if ( error ) {
F_136 ( V_8 ,
L_5 ,
V_280 , V_2 -> V_180 ) ;
goto V_256;
}
if ( ( V_262 -> V_281 . V_282 != F_9 ( V_2 ) -> V_283 . V_282 ) ||
( V_262 -> V_281 . V_284 != F_9 ( V_2 ) -> V_283 . V_284 ) ||
( V_262 -> V_285 . V_282 != F_9 ( V_2 ) -> V_286 . V_282 ) ||
( V_262 -> V_285 . V_284 != F_9 ( V_2 ) -> V_286 . V_284 ) ) {
error = - V_287 ;
goto V_256;
}
if ( ( ( F_63 ( V_2 ) != 0 ) && ( V_2 -> V_62 . V_288 > 0 ) ) &&
( V_2 -> V_62 . V_141 != V_143 ) ) {
error = F_51 ( V_15 , V_2 , V_140 , & V_268 ) ;
if ( error )
goto V_256;
}
if ( ( ( F_63 ( V_259 ) != 0 ) && ( V_259 -> V_62 . V_288 > 0 ) ) &&
( V_259 -> V_62 . V_141 != V_143 ) ) {
error = F_51 ( V_15 , V_259 , V_140 ,
& V_269 ) ;
if ( error )
goto V_256;
}
V_266 = V_64 ;
V_267 = V_64 ;
if ( V_2 -> V_62 . V_289 == 3 &&
V_2 -> V_62 . V_145 == V_142 ) {
V_267 |= V_290 ;
error = F_137 ( V_15 , V_2 , V_121 ,
V_259 -> V_180 , NULL ) ;
if ( error )
goto V_256;
}
if ( V_259 -> V_62 . V_289 == 3 &&
V_259 -> V_62 . V_145 == V_142 ) {
V_266 |= V_290 ;
error = F_137 ( V_15 , V_259 , V_121 ,
V_2 -> V_180 , NULL ) ;
if ( error )
goto V_256;
}
V_76 = & V_2 -> V_186 ;
V_265 = & V_259 -> V_186 ;
* V_264 = * V_76 ;
* V_76 = * V_265 ;
* V_265 = * V_264 ;
V_270 = ( T_27 ) V_2 -> V_62 . V_63 ;
V_2 -> V_62 . V_63 = V_259 -> V_62 . V_63 - V_269 + V_268 ;
V_259 -> V_62 . V_63 = V_270 + V_269 - V_268 ;
V_270 = ( T_27 ) V_2 -> V_62 . V_260 ;
V_2 -> V_62 . V_260 = V_259 -> V_62 . V_260 ;
V_259 -> V_62 . V_260 = V_270 ;
V_270 = ( T_27 ) V_2 -> V_62 . V_145 ;
V_2 -> V_62 . V_145 = V_259 -> V_62 . V_145 ;
V_259 -> V_62 . V_145 = V_270 ;
ASSERT ( V_259 -> V_65 == 0 ) ;
V_259 -> V_65 = V_2 -> V_65 ;
V_2 -> V_65 = 0 ;
switch ( V_2 -> V_62 . V_145 ) {
case V_100 :
if ( V_2 -> V_62 . V_260 <= V_291 ) {
V_76 -> V_292 . V_293 =
V_76 -> V_294 . V_295 ;
}
V_266 |= V_296 ;
break;
case V_142 :
ASSERT ( V_2 -> V_62 . V_289 < 3 ||
( V_266 & V_290 ) ) ;
V_266 |= V_297 ;
break;
}
switch ( V_259 -> V_62 . V_145 ) {
case V_100 :
if ( V_259 -> V_62 . V_260 <= V_291 ) {
V_265 -> V_292 . V_293 =
V_265 -> V_294 . V_295 ;
}
V_267 |= V_296 ;
break;
case V_142 :
V_267 |= V_297 ;
ASSERT ( V_259 -> V_62 . V_289 < 3 ||
( V_267 & V_290 ) ) ;
break;
}
F_32 ( V_15 , V_2 , V_266 ) ;
F_32 ( V_15 , V_259 , V_267 ) ;
if ( V_8 -> V_298 & V_299 )
F_138 ( V_15 ) ;
error = F_92 ( V_15 ) ;
F_139 ( V_2 , 0 ) ;
F_139 ( V_259 , 1 ) ;
V_109:
F_73 ( V_264 ) ;
return error ;
V_274:
F_74 ( V_2 , V_271 ) ;
F_74 ( V_259 , V_271 ) ;
goto V_109;
V_256:
F_88 ( V_15 ) ;
goto V_109;
}
