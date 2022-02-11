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
T_8 * V_10 ;
T_7 * V_11 ;
ASSERT ( ( * V_5 ) -> V_12 & V_13 ) ;
if ( V_6 -> V_14 == 0 ) {
* V_7 = 0 ;
return 0 ;
}
V_9 = F_6 ( * V_5 , V_6 -> V_14 ) ;
for ( free = V_6 -> V_15 ; free ; free = free -> V_16 )
F_7 ( * V_5 , V_9 , free -> V_17 ,
free -> V_18 ) ;
error = F_8 ( V_5 , NULL ) ;
* V_7 = 1 ;
if ( error )
return error ;
V_8 = F_9 ( * V_5 , V_9 , V_6 -> V_14 ) ;
for ( free = V_6 -> V_15 ; free != NULL ; free = V_11 ) {
V_11 = free -> V_16 ;
if ( ( error = F_10 ( * V_5 , free -> V_17 ,
free -> V_18 ) ) ) {
V_10 = ( * V_5 ) -> V_19 ;
if ( ! F_11 ( V_10 ) )
F_12 ( V_10 ,
( error == - V_20 ) ?
V_21 :
V_22 ) ;
return error ;
}
F_13 ( * V_5 , V_8 , free -> V_17 ,
free -> V_18 ) ;
F_14 ( V_6 , NULL , free ) ;
}
return 0 ;
}
int
F_15 (
struct V_23 * V_24 )
{
T_9 V_25 = 0 ;
int error ;
T_8 * V_10 ;
T_10 V_26 = 0 ;
T_10 V_27 = 0 ;
T_10 V_28 ;
T_11 V_29 ;
V_10 = V_24 -> V_2 -> V_4 ;
V_28 = F_16 ( V_24 -> V_2 ) ;
V_26 = V_28 / V_10 -> V_30 . V_31 ;
error = F_17 ( V_10 , & V_24 -> V_32 , & V_24 -> V_33 ,
V_28 , 1 , V_24 -> V_34 , 0 ,
V_24 -> V_35 , & V_24 -> V_36 , & V_24 -> V_37 ) ;
if ( error )
return error ;
ASSERT ( V_24 -> V_37 ) ;
ASSERT ( V_24 -> V_37 % V_10 -> V_30 . V_31 == 0 ) ;
if ( F_18 ( V_24 -> V_36 , V_28 ) || V_24 -> V_37 % V_28 )
V_26 = 1 ;
V_27 = V_24 -> V_37 / V_10 -> V_30 . V_31 ;
if ( V_27 * V_10 -> V_30 . V_31 >= V_38 )
V_27 = V_38 / V_10 -> V_30 . V_31 ;
F_19 ( V_10 -> V_39 , V_40 ) ;
F_20 ( V_24 -> V_5 , V_10 -> V_39 , V_40 ) ;
if ( V_24 -> V_34 && V_24 -> V_36 == 0 ) {
T_11 V_41 ( V_42 ) ;
error = F_21 ( V_10 , V_24 -> V_5 , V_27 , & V_42 ) ;
if ( error )
return error ;
V_24 -> V_43 = V_42 * V_10 -> V_30 . V_31 ;
} else {
V_24 -> V_43 = 0 ;
}
F_22 ( V_24 ) ;
V_25 = V_24 -> V_43 == 0 ? V_44 : V_45 ;
F_23 ( V_24 -> V_43 , V_10 -> V_30 . V_31 ) ;
V_29 = V_24 -> V_43 ;
V_24 -> V_37 = V_27 ;
if ( ( error = F_24 ( V_24 -> V_5 , V_24 -> V_43 , 1 , V_24 -> V_37 ,
& V_27 , V_25 , V_24 -> V_46 , V_26 , & V_29 ) ) )
return error ;
if ( V_29 == V_47 && V_26 > 1 &&
( error = F_24 ( V_24 -> V_5 , V_24 -> V_43 , 1 ,
V_24 -> V_37 , & V_27 , V_25 ,
V_24 -> V_46 , 1 , & V_29 ) ) )
return error ;
V_24 -> V_43 = V_29 ;
if ( V_24 -> V_43 != V_47 ) {
V_24 -> V_43 *= V_10 -> V_30 . V_31 ;
V_27 *= V_10 -> V_30 . V_31 ;
V_24 -> V_37 = V_27 ;
V_24 -> V_2 -> V_48 . V_49 += V_27 ;
F_25 ( V_24 -> V_5 , V_24 -> V_2 , V_50 ) ;
if ( V_24 -> V_46 )
V_24 -> V_2 -> V_51 -= V_27 ;
F_26 ( V_24 -> V_5 , V_24 -> V_2 ,
V_24 -> V_46 ? V_52 :
V_53 , ( long ) V_27 ) ;
} else {
V_24 -> V_37 = 0 ;
}
return 0 ;
}
int
F_27 (
struct V_1 * V_2 ,
T_12 V_54 ,
int V_55 ,
int * V_34 )
{
struct V_56 V_57 ;
int error ;
error = F_28 ( NULL , V_2 , V_55 , & V_57 , V_34 ) ;
if ( error || * V_34 )
return error ;
* V_34 = V_54 >= V_57 . V_58 + V_57 . V_59 ;
return 0 ;
}
STATIC void
F_29 (
T_13 * V_60 ,
T_14 V_61 ,
int V_62 ,
int * V_63 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
T_15 * V_65 = F_30 ( V_60 , V_61 + V_64 ) ;
* V_63 += F_31 ( V_65 ) ;
}
}
STATIC void
F_32 (
struct V_66 * V_10 ,
struct V_67 * V_68 ,
int V_62 ,
int * V_63 )
{
int V_64 ;
T_16 * V_65 ;
for ( V_64 = 1 ; V_64 <= V_62 ; V_64 ++ ) {
V_65 = F_33 ( V_10 , V_68 , V_64 ) ;
* V_63 += F_34 ( V_65 ) ;
}
}
STATIC int
F_35 (
T_8 * V_10 ,
T_3 * V_5 ,
T_13 * V_60 ,
T_2 V_69 ,
int V_70 ,
int * V_63 )
{
int error ;
T_17 * V_71 , * V_72 ;
int V_73 = V_70 ;
T_18 * V_74 ;
T_2 V_75 = V_69 ;
T_2 V_76 ;
struct V_67 * V_68 , * V_77 ;
int V_62 ;
error = F_36 ( V_10 , V_5 , V_75 , 0 , & V_71 , V_78 ,
& V_79 ) ;
if ( error )
return error ;
* V_63 += 1 ;
V_68 = F_37 ( V_71 ) ;
if ( -- V_73 ) {
V_76 = F_38 ( V_68 -> V_80 . V_81 . V_82 ) ;
while ( V_76 != V_47 ) {
error = F_36 ( V_10 , V_5 , V_76 , 0 , & V_72 ,
V_78 ,
& V_79 ) ;
if ( error )
return error ;
* V_63 += 1 ;
V_77 = F_37 ( V_72 ) ;
V_76 = F_38 ( V_77 -> V_80 . V_81 . V_82 ) ;
F_39 ( V_5 , V_72 ) ;
}
V_74 = F_40 ( V_10 , V_68 , 1 , V_10 -> V_83 [ 1 ] ) ;
V_75 = F_38 ( * V_74 ) ;
if ( F_41 ( ( error =
F_35 ( V_10 , V_5 , V_60 , V_75 , V_73 , V_63 ) ) < 0 ) ) {
F_39 ( V_5 , V_71 ) ;
F_42 ( L_1 ,
V_84 , V_10 ) ;
return - V_20 ;
}
F_39 ( V_5 , V_71 ) ;
} else {
for (; ; ) {
V_76 = F_38 ( V_68 -> V_80 . V_81 . V_82 ) ;
V_62 = F_43 ( V_68 -> V_85 ) ;
F_32 ( V_10 , V_68 , V_62 , V_63 ) ;
F_39 ( V_5 , V_71 ) ;
if ( V_76 == V_47 )
break;
V_75 = V_76 ;
error = F_36 ( V_10 , V_5 , V_75 , 0 , & V_71 ,
V_78 ,
& V_79 ) ;
if ( error )
return error ;
* V_63 += 1 ;
V_68 = F_37 ( V_71 ) ;
}
}
return 0 ;
}
int
F_44 (
T_3 * V_5 ,
T_19 * V_2 ,
int V_55 ,
int * V_63 )
{
struct V_67 * V_68 ;
T_2 V_75 ;
T_13 * V_60 ;
int V_73 ;
T_8 * V_10 ;
T_18 * V_74 ;
V_75 = V_47 ;
V_10 = V_2 -> V_4 ;
V_60 = F_45 ( V_2 , V_55 ) ;
if ( F_46 ( V_2 , V_55 ) == V_86 ) {
F_29 ( V_60 , 0 ,
V_60 -> V_87 / ( V_88 ) sizeof( T_16 ) ,
V_63 ) ;
return 0 ;
}
V_68 = V_60 -> V_89 ;
V_73 = F_43 ( V_68 -> V_90 ) ;
ASSERT ( V_73 > 0 ) ;
V_74 = F_47 ( V_10 , V_68 , 1 , V_60 -> V_91 ) ;
V_75 = F_38 ( * V_74 ) ;
ASSERT ( V_75 != V_47 ) ;
ASSERT ( F_48 ( V_10 , V_75 ) < V_10 -> V_30 . V_92 ) ;
ASSERT ( F_49 ( V_10 , V_75 ) < V_10 -> V_30 . V_93 ) ;
if ( F_41 ( F_35 ( V_10 , V_5 , V_60 , V_75 , V_73 , V_63 ) < 0 ) ) {
F_42 ( L_2 , V_84 ,
V_10 ) ;
return - V_20 ;
}
return 0 ;
}
STATIC int
F_50 (
T_19 * V_2 ,
struct V_94 * V_95 ,
int V_96 ,
T_20 V_97 ,
T_2 V_98 )
{
T_20 V_99 ;
T_8 * V_10 ;
T_13 * V_60 ;
T_14 V_100 ;
T_12 V_101 ;
if ( V_98 == V_102 ) {
V_10 = V_2 -> V_4 ;
V_95 -> V_103 = - 1 ;
V_99 = F_3 ( V_10 , F_51 ( V_10 , F_52 ( V_2 ) ) ) ;
V_99 -= V_95 -> V_104 ;
if ( V_96 && V_95 -> V_104 + V_95 -> V_105 == V_97 ) {
if ( V_99 <= 0 )
return 0 ;
V_95 -> V_105 = V_99 ;
}
} else {
if ( V_98 == V_106 )
V_95 -> V_103 = - 2 ;
else
V_95 -> V_103 = F_1 ( V_2 , V_98 ) ;
V_101 = F_53 ( V_2 -> V_4 , V_95 -> V_104 ) ;
V_60 = F_45 ( V_2 , V_107 ) ;
if ( F_54 ( V_60 , V_101 , & V_100 ) &&
( V_100 == ( V_60 -> V_87 / ( V_88 ) sizeof( T_16 ) ) - 1 ) )
V_95 -> V_108 |= V_109 ;
}
return 1 ;
}
int
F_55 (
T_19 * V_2 ,
struct V_94 * V_110 ,
T_21 V_111 ,
void * V_112 )
{
T_20 V_113 ;
int error = 0 ;
T_20 V_99 ;
int V_114 ;
int V_115 ;
T_22 * V_116 ;
T_8 * V_10 ;
int V_117 ;
int V_118 ;
int V_119 ;
int V_120 ;
struct V_94 * V_95 ;
int V_55 ;
int V_96 ;
int V_121 ;
int V_122 ;
int V_123 = 0 ;
V_10 = V_2 -> V_4 ;
V_121 = V_110 -> V_124 ;
V_55 = V_121 & V_125 ? V_126 : V_107 ;
if ( V_55 == V_126 ) {
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_48 . V_127 != V_86 &&
V_2 -> V_48 . V_127 != V_128 &&
V_2 -> V_48 . V_127 != V_129 )
return - V_130 ;
} else if ( F_41 (
V_2 -> V_48 . V_127 != 0 &&
V_2 -> V_48 . V_127 != V_86 ) ) {
F_42 ( L_3 , V_84 ,
V_2 -> V_4 ) ;
return - V_20 ;
}
V_96 = 0 ;
V_99 = 1LL << 32 ;
} else {
if ( V_2 -> V_48 . V_131 != V_86 &&
V_2 -> V_48 . V_131 != V_128 &&
V_2 -> V_48 . V_131 != V_129 )
return - V_130 ;
if ( F_16 ( V_2 ) ||
V_2 -> V_48 . V_132 & ( V_133 | V_134 ) ) {
V_96 = 1 ;
V_99 = V_10 -> V_135 -> V_136 ;
} else {
V_96 = 0 ;
V_99 = F_52 ( V_2 ) ;
}
}
if ( V_110 -> V_105 == - 1 ) {
V_99 = F_3 ( V_10 , F_51 ( V_10 , V_99 ) ) ;
V_110 -> V_105 =
F_57 ( T_20 , V_99 - V_110 -> V_104 , 0 ) ;
} else if ( V_110 -> V_105 == 0 ) {
V_110 -> V_137 = 0 ;
return 0 ;
} else if ( V_110 -> V_105 < 0 ) {
return - V_130 ;
}
V_117 = V_110 -> V_138 - 1 ;
if ( V_117 <= 0 )
return - V_130 ;
V_113 = V_110 -> V_104 + V_110 -> V_105 ;
if ( V_110 -> V_138 > V_139 / sizeof( struct V_94 ) )
return - V_140 ;
V_95 = F_58 ( V_110 -> V_138 * sizeof( struct V_94 ) , 0 ) ;
if ( ! V_95 )
return - V_140 ;
F_19 ( V_2 , V_141 ) ;
if ( V_55 == V_107 ) {
if ( ! ( V_121 & V_142 ) &&
( V_2 -> V_51 || F_52 ( V_2 ) > V_2 -> V_48 . V_143 ) ) {
error = F_59 ( F_60 ( V_2 ) -> V_144 ) ;
if ( error )
goto V_145;
}
V_115 = F_61 ( V_2 ) ;
} else {
V_115 = F_62 ( V_2 ) ;
}
if ( V_117 > F_63 ( V_2 , V_55 ) * 2 + 1 )
V_117 = F_63 ( V_2 , V_55 ) * 2 + 1 ;
V_122 = F_64 ( V_55 ) ;
if ( ! ( V_121 & V_146 ) )
V_122 |= V_147 ;
error = - V_140 ;
V_119 = 16 ;
V_116 = F_65 ( V_119 * sizeof( * V_116 ) , V_148 | V_149 ) ;
if ( ! V_116 )
goto V_150;
V_110 -> V_137 = 0 ;
if ( F_63 ( V_2 , V_55 ) == 0 &&
( V_55 == V_126 || ! ( V_121 & V_142 ) ) ) {
error = 0 ;
goto V_151;
}
V_118 = V_117 ;
do {
V_120 = ( V_118 > V_119 ) ? V_119 : V_118 ;
error = F_66 ( V_2 , F_67 ( V_10 , V_110 -> V_104 ) ,
F_53 ( V_10 , V_110 -> V_105 ) ,
V_116 , & V_120 , V_122 ) ;
if ( error )
goto V_151;
ASSERT ( V_120 <= V_119 ) ;
for ( V_114 = 0 ; V_114 < V_120 && V_118 && V_110 -> V_105 ; V_114 ++ ) {
V_95 [ V_123 ] . V_108 = 0 ;
if ( V_116 [ V_114 ] . V_152 == V_153 )
V_95 [ V_123 ] . V_108 |= V_154 ;
else if ( V_116 [ V_114 ] . V_155 == V_106 )
V_95 [ V_123 ] . V_108 |= V_156 ;
V_95 [ V_123 ] . V_104 =
F_3 ( V_10 , V_116 [ V_114 ] . V_58 ) ;
V_95 [ V_123 ] . V_105 =
F_3 ( V_10 , V_116 [ V_114 ] . V_59 ) ;
V_95 [ V_123 ] . V_157 = 0 ;
V_95 [ V_123 ] . V_158 = 0 ;
if ( V_116 [ V_114 ] . V_155 == V_106 &&
V_116 [ V_114 ] . V_58 <= F_51 ( V_10 , F_52 ( V_2 ) ) )
ASSERT ( ( V_121 & V_142 ) != 0 ) ;
if ( V_116 [ V_114 ] . V_155 == V_102 &&
V_55 == V_126 ) {
V_95 [ V_123 ] . V_108 |= V_109 ;
goto V_151;
}
if ( ! F_50 ( V_2 , & V_95 [ V_123 ] ,
V_96 , V_113 ,
V_116 [ V_114 ] . V_155 ) )
goto V_151;
V_110 -> V_104 =
V_95 [ V_123 ] . V_104 +
V_95 [ V_123 ] . V_105 ;
V_110 -> V_105 =
F_57 ( T_20 , 0 , V_113 - V_110 -> V_104 ) ;
if ( ( V_121 & V_159 ) &&
V_116 [ V_114 ] . V_155 == V_102 ) {
memset ( & V_95 [ V_123 ] , 0 , sizeof( V_95 [ V_123 ] ) ) ;
continue;
}
V_118 -- ;
V_110 -> V_137 ++ ;
V_123 ++ ;
}
} while ( V_120 && V_118 && V_110 -> V_105 );
V_151:
F_68 ( V_116 ) ;
V_150:
F_69 ( V_2 , V_115 ) ;
V_145:
F_69 ( V_2 , V_141 ) ;
for ( V_114 = 0 ; V_114 < V_123 ; V_114 ++ ) {
int V_160 = 0 ;
error = V_111 ( & V_112 , & V_95 [ V_114 ] , & V_160 ) ;
if ( error || V_160 )
break;
}
F_68 ( V_95 ) ;
return error ;
}
int
F_70 (
struct V_1 * V_2 ,
T_12 V_161 ,
T_12 V_37 )
{
T_12 V_162 = V_37 ;
int error = 0 ;
ASSERT ( F_71 ( V_2 , V_40 ) ) ;
do {
int V_163 ;
T_22 V_164 ;
int V_165 = 1 ;
T_2 V_166 ;
T_4 V_6 ;
error = F_66 ( V_2 , V_161 , 1 , & V_164 , & V_165 ,
V_167 ) ;
if ( error ) {
if ( ! F_11 ( V_2 -> V_4 ) ) {
F_72 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_168 , V_161 ) ;
}
break;
}
if ( ! V_165 ) {
goto V_169;
}
if ( V_164 . V_155 != V_106 ) {
goto V_169;
}
F_73 ( V_164 . V_59 == 0 ) ;
F_74 ( & V_6 , & V_166 ) ;
error = F_75 ( NULL , V_2 , V_161 , 1 , 0 , 1 , & V_166 ,
& V_6 , & V_163 ) ;
if ( error )
break;
ASSERT ( ! V_6 . V_14 && ! V_6 . V_15 ) ;
V_169:
V_161 ++ ;
V_162 -- ;
} while( V_162 > 0 );
return error ;
}
bool
F_76 ( struct V_1 * V_2 , bool V_170 )
{
if ( ! F_77 ( V_2 -> V_48 . V_171 ) )
return false ;
if ( F_60 ( V_2 ) -> V_172 == 0 &&
F_60 ( V_2 ) -> V_144 -> V_173 == 0 &&
V_2 -> V_51 == 0 )
return false ;
if ( ! ( V_2 -> V_174 . V_175 & V_176 ) )
return false ;
if ( V_2 -> V_48 . V_132 & ( V_133 | V_134 ) )
if ( ! V_170 || V_2 -> V_51 == 0 )
return false ;
return true ;
}
int
F_78 (
T_8 * V_10 ,
T_19 * V_2 ,
bool V_177 )
{
T_3 * V_5 ;
int error ;
T_12 V_178 ;
T_12 V_179 ;
T_23 V_180 ;
int V_165 ;
T_22 V_164 ;
V_178 = F_51 ( V_10 , ( V_181 ) F_52 ( V_2 ) ) ;
V_179 = F_51 ( V_10 , V_10 -> V_135 -> V_136 ) ;
if ( V_179 <= V_178 )
return 0 ;
V_180 = V_179 - V_178 ;
V_165 = 1 ;
F_19 ( V_2 , V_182 ) ;
error = F_66 ( V_2 , V_178 , V_180 , & V_164 , & V_165 , 0 ) ;
F_69 ( V_2 , V_182 ) ;
if ( ! error && ( V_165 != 0 ) &&
( V_164 . V_155 != V_102 ||
V_2 -> V_51 ) ) {
error = F_79 ( V_2 , 0 ) ;
if ( error )
return error ;
V_5 = F_80 ( V_10 , V_183 ) ;
if ( V_177 ) {
if ( ! F_81 ( V_2 , V_184 ) ) {
F_82 ( V_5 ) ;
return - V_185 ;
}
}
error = F_83 ( V_5 , & F_84 ( V_10 ) -> V_186 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_11 ( V_10 ) ) ;
F_82 ( V_5 ) ;
if ( V_177 )
F_69 ( V_2 , V_184 ) ;
return error ;
}
F_19 ( V_2 , V_40 ) ;
F_20 ( V_5 , V_2 , 0 ) ;
error = F_85 ( & V_5 , V_2 , V_107 ,
F_52 ( V_2 ) ) ;
if ( error ) {
F_82 ( V_5 ) ;
} else {
error = F_86 ( V_5 ) ;
if ( ! error )
F_87 ( V_2 ) ;
}
F_69 ( V_2 , V_40 ) ;
if ( V_177 )
F_69 ( V_2 , V_184 ) ;
}
return error ;
}
int
F_88 (
struct V_1 * V_2 ,
T_24 V_36 ,
T_24 V_187 ,
int V_188 )
{
T_8 * V_10 = V_2 -> V_4 ;
T_24 V_63 ;
T_23 V_189 ;
T_23 V_190 ;
T_10 V_191 , V_192 ;
T_12 V_193 ;
T_2 V_194 ;
int V_165 ;
int V_195 ;
int V_196 ;
T_3 * V_5 ;
T_22 V_197 [ 1 ] , * V_198 ;
T_4 V_199 ;
V_88 V_200 , V_201 , V_202 ;
int V_7 ;
int error ;
F_89 ( V_2 ) ;
if ( F_11 ( V_10 ) )
return - V_203 ;
error = F_79 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_187 <= 0 )
return - V_130 ;
V_196 = F_2 ( V_2 ) ;
V_191 = F_16 ( V_2 ) ;
V_63 = V_187 ;
V_198 = & V_197 [ 0 ] ;
V_165 = 1 ;
V_193 = F_90 ( V_10 , V_36 ) ;
V_190 = F_51 ( V_10 , V_63 ) ;
while ( V_190 && ! error ) {
T_12 V_204 , V_205 ;
if ( F_41 ( V_191 ) ) {
V_204 = V_193 ;
F_23 ( V_204 , V_191 ) ;
V_204 *= V_191 ;
V_205 = V_193 + V_190 ;
if ( ( V_192 = F_18 ( V_193 , V_191 ) ) )
V_205 += V_192 ;
if ( ( V_192 = F_18 ( V_205 , V_191 ) ) )
V_205 += V_191 - V_192 ;
} else {
V_204 = 0 ;
V_205 = V_190 ;
}
V_201 = F_91 ( T_12 , ( V_205 - V_204 ) , ( V_38 * V_165 ) ) ;
if ( F_41 ( V_196 ) ) {
V_202 = V_200 = V_201 ;
V_202 /= V_10 -> V_30 . V_31 ;
V_201 = F_92 ( V_10 , 0 ) ;
V_195 = V_206 ;
} else {
V_202 = 0 ;
V_201 = V_200 = F_92 ( V_10 , V_201 ) ;
V_195 = V_207 ;
}
V_5 = F_80 ( V_10 , V_208 ) ;
error = F_83 ( V_5 , & F_84 ( V_10 ) -> V_209 ,
V_201 , V_202 ) ;
if ( error ) {
ASSERT ( error == - V_210 || F_11 ( V_10 ) ) ;
F_82 ( V_5 ) ;
break;
}
F_19 ( V_2 , V_40 ) ;
error = F_93 ( V_5 , V_2 , V_200 ,
0 , V_195 ) ;
if ( error )
goto V_211;
F_20 ( V_5 , V_2 , 0 ) ;
F_74 ( & V_199 , & V_194 ) ;
error = F_94 ( V_5 , V_2 , V_193 ,
V_190 , V_188 , & V_194 ,
0 , V_198 , & V_165 , & V_199 ) ;
if ( error ) {
goto V_212;
}
error = F_5 ( & V_5 , & V_199 , & V_7 ) ;
if ( error ) {
goto V_212;
}
error = F_86 ( V_5 ) ;
F_69 ( V_2 , V_40 ) ;
if ( error ) {
break;
}
V_189 = V_198 -> V_59 ;
if ( V_165 == 0 ) {
error = - V_210 ;
break;
}
V_193 += V_189 ;
V_190 -= V_189 ;
}
return error ;
V_212:
F_95 ( & V_199 ) ;
F_96 ( V_5 , V_2 , ( long ) V_200 , 0 , V_195 ) ;
V_211:
F_82 ( V_5 ) ;
F_69 ( V_2 , V_40 ) ;
return error ;
}
STATIC int
F_97 (
T_19 * V_2 ,
T_24 V_213 ,
T_24 V_54 )
{
T_22 V_164 ;
T_12 V_214 ;
T_24 V_215 ;
T_24 V_36 ;
T_17 * V_71 ;
T_8 * V_10 = V_2 -> V_4 ;
int V_216 ;
int error = 0 ;
if ( V_213 >= F_52 ( V_2 ) )
return 0 ;
if ( V_54 > F_52 ( V_2 ) )
V_54 = F_52 ( V_2 ) ;
for ( V_36 = V_213 ; V_36 <= V_54 ; V_36 = V_215 + 1 ) {
V_88 V_217 ;
V_214 = F_90 ( V_10 , V_36 ) ;
V_216 = 1 ;
V_217 = F_61 ( V_2 ) ;
error = F_66 ( V_2 , V_214 , 1 , & V_164 , & V_216 , 0 ) ;
F_69 ( V_2 , V_217 ) ;
if ( error || V_216 < 1 )
break;
ASSERT ( V_164 . V_59 >= 1 ) ;
ASSERT ( V_164 . V_58 == V_214 ) ;
ASSERT ( V_164 . V_155 != V_106 ) ;
if ( V_164 . V_155 == V_102 ||
V_164 . V_152 == V_153 ) {
V_215 = F_98 ( V_10 , V_164 . V_58 +
V_164 . V_59 ) - 1 ;
continue;
}
V_215 = F_98 ( V_10 , V_164 . V_58 + 1 ) - 1 ;
if ( V_215 > V_54 )
V_215 = V_54 ;
if ( F_99 ( F_60 ( V_2 ) ) ) {
error = F_100 ( F_60 ( V_2 ) , V_36 ,
V_215 - V_36 + 1 ,
V_218 ) ;
if ( error )
return error ;
continue;
}
error = F_101 ( F_2 ( V_2 ) ?
V_10 -> V_219 : V_10 -> V_220 ,
F_1 ( V_2 , V_164 . V_155 ) ,
F_102 ( V_10 -> V_30 . V_221 ) ,
0 , & V_71 , NULL ) ;
if ( error )
return error ;
memset ( V_71 -> V_222 +
( V_36 - F_98 ( V_10 , V_164 . V_58 ) ) ,
0 , V_215 - V_36 + 1 ) ;
error = F_103 ( V_71 ) ;
F_104 ( V_71 ) ;
if ( error )
return error ;
}
return error ;
}
int
F_105 (
struct V_1 * V_2 ,
T_24 V_36 ,
T_24 V_187 )
{
int V_7 ;
int V_163 ;
T_12 V_223 ;
int error ;
T_2 V_194 ;
T_4 V_199 ;
T_22 V_164 ;
T_24 V_224 ;
T_24 V_225 ;
T_10 V_226 = 0 ;
T_8 * V_10 ;
int V_216 ;
V_88 V_201 ;
T_24 V_227 ;
int V_196 ;
T_12 V_193 ;
T_3 * V_5 ;
V_10 = V_2 -> V_4 ;
F_106 ( V_2 ) ;
error = F_79 ( V_2 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_187 <= 0 )
return error ;
V_196 = F_2 ( V_2 ) ;
V_193 = F_51 ( V_10 , V_36 ) ;
V_223 = F_90 ( V_10 , V_36 + V_187 ) ;
F_107 ( F_60 ( V_2 ) ) ;
V_227 = F_57 ( T_24 , 1 << V_10 -> V_30 . V_228 , V_229 ) ;
V_224 = F_108 ( V_36 , V_227 ) ;
V_225 = F_109 ( V_36 + V_187 , V_227 ) - 1 ;
error = F_110 ( F_60 ( V_2 ) -> V_144 , V_224 ,
V_225 ) ;
if ( error )
goto V_95;
F_111 ( F_60 ( V_2 ) , V_224 , V_225 ) ;
if ( V_196 && ! F_112 ( & V_10 -> V_30 ) ) {
V_216 = 1 ;
error = F_66 ( V_2 , V_193 , 1 ,
& V_164 , & V_216 , 0 ) ;
if ( error )
goto V_95;
ASSERT ( V_216 == 0 || V_216 == 1 ) ;
if ( V_216 && V_164 . V_155 != V_102 ) {
T_1 V_68 ;
ASSERT ( V_164 . V_155 != V_106 ) ;
V_68 = V_164 . V_155 ;
V_226 = F_23 ( V_68 , V_10 -> V_30 . V_31 ) ;
if ( V_226 )
V_193 += V_10 -> V_30 . V_31 - V_226 ;
}
V_216 = 1 ;
error = F_66 ( V_2 , V_223 - 1 , 1 ,
& V_164 , & V_216 , 0 ) ;
if ( error )
goto V_95;
ASSERT ( V_216 == 0 || V_216 == 1 ) ;
if ( V_216 && V_164 . V_155 != V_102 ) {
ASSERT ( V_164 . V_155 != V_106 ) ;
V_226 ++ ;
if ( V_226 && ( V_226 != V_10 -> V_30 . V_31 ) )
V_223 -= V_226 ;
}
}
if ( ( V_163 = ( V_223 <= V_193 ) ) )
error = F_97 ( V_2 , V_36 , V_36 + V_187 - 1 ) ;
else {
if ( V_36 < F_98 ( V_10 , V_193 ) )
error = F_97 ( V_2 , V_36 ,
F_98 ( V_10 , V_193 ) - 1 ) ;
if ( ! error &&
F_98 ( V_10 , V_223 ) < V_36 + V_187 )
error = F_97 ( V_2 ,
F_98 ( V_10 , V_223 ) ,
V_36 + V_187 - 1 ) ;
}
V_201 = F_92 ( V_10 , 0 ) ;
while ( ! error && ! V_163 ) {
V_5 = F_80 ( V_10 , V_208 ) ;
error = F_83 ( V_5 , & F_84 ( V_10 ) -> V_209 , V_201 , 0 ) ;
if ( error ) {
ASSERT ( error == - V_210 || F_11 ( V_10 ) ) ;
F_82 ( V_5 ) ;
break;
}
F_19 ( V_2 , V_40 ) ;
error = F_113 ( V_5 , V_10 ,
V_2 -> V_230 , V_2 -> V_231 , V_2 -> V_232 ,
V_201 , 0 , V_207 ) ;
if ( error )
goto V_211;
F_20 ( V_5 , V_2 , 0 ) ;
F_74 ( & V_199 , & V_194 ) ;
error = F_75 ( V_5 , V_2 , V_193 ,
V_223 - V_193 ,
0 , 2 , & V_194 , & V_199 , & V_163 ) ;
if ( error ) {
goto V_212;
}
error = F_5 ( & V_5 , & V_199 , & V_7 ) ;
if ( error ) {
goto V_212;
}
error = F_86 ( V_5 ) ;
F_69 ( V_2 , V_40 ) ;
}
V_95:
return error ;
V_212:
F_95 ( & V_199 ) ;
V_211:
F_82 ( V_5 ) ;
F_69 ( V_2 , V_40 ) ;
goto V_95;
}
int
F_114 (
struct V_1 * V_2 ,
T_24 V_36 ,
T_24 V_187 )
{
struct V_66 * V_10 = V_2 -> V_4 ;
V_88 V_233 ;
int error ;
F_115 ( V_2 ) ;
V_233 = 1 << V_10 -> V_30 . V_228 ;
error = F_105 ( V_2 , V_36 , V_187 ) ;
if ( error )
goto V_95;
error = F_88 ( V_2 , F_108 ( V_36 , V_233 ) ,
F_109 ( V_36 + V_187 , V_233 ) -
F_108 ( V_36 , V_233 ) ,
V_234 ) ;
V_95:
return error ;
}
static int
F_116 (
struct V_1 * V_2 ,
T_24 V_36 ,
T_24 V_187 ,
enum V_235 V_236 )
{
int V_163 = 0 ;
struct V_66 * V_10 = V_2 -> V_4 ;
struct V_237 * V_5 ;
int error ;
struct V_238 V_199 ;
T_2 V_239 ;
int V_7 ;
T_12 V_240 ;
T_12 V_241 ;
T_12 V_242 ;
ASSERT ( V_236 == V_243 || V_236 == V_244 ) ;
if ( V_236 == V_243 ) {
V_241 = F_51 ( V_10 , V_36 + V_187 ) ;
V_240 = F_51 ( V_10 , F_60 ( V_2 ) -> V_172 ) ;
} else {
V_241 = V_47 ;
V_240 = F_51 ( V_10 , V_36 ) ;
}
V_242 = F_51 ( V_10 , V_187 ) ;
if ( F_76 ( V_2 , true ) ) {
error = F_78 ( V_10 , V_2 , false ) ;
if ( error )
return error ;
}
error = F_110 ( F_60 ( V_2 ) -> V_144 ,
V_36 , - 1 ) ;
if ( error )
return error ;
error = F_117 ( F_60 ( V_2 ) -> V_144 ,
V_36 >> V_245 , - 1 ) ;
if ( error )
return error ;
if ( V_236 == V_244 ) {
error = F_118 ( V_2 , V_240 ) ;
if ( error )
return error ;
}
while ( ! error && ! V_163 ) {
V_5 = F_80 ( V_10 , V_208 ) ;
error = F_83 ( V_5 , & F_84 ( V_10 ) -> V_209 ,
F_92 ( V_10 , 0 ) , 0 ) ;
if ( error ) {
F_82 ( V_5 ) ;
break;
}
F_19 ( V_2 , V_40 ) ;
error = F_113 ( V_5 , V_10 , V_2 -> V_230 ,
V_2 -> V_231 , V_2 -> V_232 ,
F_92 ( V_10 , 0 ) , 0 ,
V_207 ) ;
if ( error )
goto V_95;
F_20 ( V_5 , V_2 , V_40 ) ;
F_74 ( & V_199 , & V_239 ) ;
error = F_119 ( V_5 , V_2 , & V_241 , V_242 ,
& V_163 , V_240 , & V_239 , & V_199 ,
V_236 , V_246 ) ;
if ( error )
goto V_95;
error = F_5 ( & V_5 , & V_199 , & V_7 ) ;
if ( error )
goto V_95;
error = F_86 ( V_5 ) ;
}
return error ;
V_95:
F_82 ( V_5 ) ;
return error ;
}
int
F_120 (
struct V_1 * V_2 ,
T_24 V_36 ,
T_24 V_187 )
{
int error ;
ASSERT ( F_71 ( V_2 , V_184 ) ) ;
F_121 ( V_2 ) ;
error = F_105 ( V_2 , V_36 , V_187 ) ;
if ( error )
return error ;
return F_116 ( V_2 , V_36 , V_187 , V_243 ) ;
}
int
F_122 (
struct V_1 * V_2 ,
T_25 V_36 ,
T_25 V_187 )
{
ASSERT ( F_71 ( V_2 , V_184 ) ) ;
F_123 ( V_2 ) ;
return F_116 ( V_2 , V_36 , V_187 , V_244 ) ;
}
static int
F_124 (
T_19 * V_2 ,
T_19 * V_247 )
{
if ( V_2 -> V_48 . V_131 == V_129 ||
V_247 -> V_48 . V_131 == V_129 )
return - V_130 ;
if ( V_2 -> V_48 . V_248 < V_247 -> V_48 . V_248 )
return - V_130 ;
if ( V_2 -> V_48 . V_131 == V_86 &&
V_247 -> V_48 . V_131 == V_128 )
return - V_130 ;
if ( V_247 -> V_48 . V_131 == V_86 &&
F_63 ( V_247 , V_107 ) >
F_125 ( V_2 , V_107 ) )
return - V_130 ;
if ( V_2 -> V_48 . V_131 == V_86 &&
F_63 ( V_2 , V_107 ) >
F_125 ( V_247 , V_107 ) )
return - V_130 ;
if ( V_247 -> V_48 . V_131 == V_128 ) {
if ( F_126 ( V_2 ) &&
F_127 ( V_247 -> V_174 . V_89 ) > F_126 ( V_2 ) )
return - V_130 ;
if ( F_63 ( V_247 , V_107 ) <=
F_125 ( V_2 , V_107 ) )
return - V_130 ;
}
if ( V_2 -> V_48 . V_131 == V_128 ) {
if ( F_126 ( V_247 ) &&
F_127 ( V_2 -> V_174 . V_89 ) > F_126 ( V_247 ) )
return - V_130 ;
if ( F_63 ( V_2 , V_107 ) <=
F_125 ( V_247 , V_107 ) )
return - V_130 ;
}
return 0 ;
}
static int
F_128 (
struct V_1 * V_2 )
{
int error ;
error = F_59 ( F_60 ( V_2 ) -> V_144 ) ;
if ( error )
return error ;
F_111 ( F_60 ( V_2 ) , 0 , - 1 ) ;
if ( F_60 ( V_2 ) -> V_144 -> V_173 )
return - V_130 ;
return 0 ;
}
int
F_129 (
T_19 * V_2 ,
T_19 * V_247 ,
T_26 * V_249 )
{
T_8 * V_10 = V_2 -> V_4 ;
T_3 * V_5 ;
T_27 * V_250 = & V_249 -> V_251 ;
T_13 * V_252 , * V_60 , * V_253 ;
int V_254 , V_255 ;
int error = 0 ;
int V_256 = 0 ;
int V_257 = 0 ;
T_28 V_258 ;
int V_259 ;
V_252 = F_65 ( sizeof( T_13 ) , V_148 ) ;
if ( ! V_252 ) {
error = - V_140 ;
goto V_95;
}
V_259 = V_184 | V_260 ;
F_130 ( V_2 , V_247 , V_184 ) ;
F_130 ( V_2 , V_247 , V_260 ) ;
if ( ( V_2 -> V_48 . V_171 & V_261 ) != ( V_247 -> V_48 . V_171 & V_261 ) ) {
error = - V_130 ;
goto V_262;
}
if ( F_2 ( V_2 ) != F_2 ( V_247 ) ) {
error = - V_130 ;
goto V_262;
}
error = F_128 ( V_2 ) ;
if ( error )
goto V_262;
error = F_128 ( V_247 ) ;
if ( error )
goto V_262;
V_5 = F_80 ( V_10 , V_263 ) ;
error = F_83 ( V_5 , & F_84 ( V_10 ) -> V_264 , 0 , 0 ) ;
if ( error ) {
F_82 ( V_5 ) ;
goto V_262;
}
F_130 ( V_2 , V_247 , V_40 ) ;
V_259 |= V_40 ;
F_20 ( V_5 , V_2 , V_259 ) ;
F_20 ( V_5 , V_247 , V_259 ) ;
if ( V_249 -> V_265 != 0 ||
V_249 -> V_266 != V_2 -> V_48 . V_143 ||
V_249 -> V_266 != V_247 -> V_48 . V_143 ) {
error = - V_267 ;
goto V_268;
}
F_131 ( V_2 , 0 ) ;
F_131 ( V_247 , 1 ) ;
error = F_124 ( V_2 , V_247 ) ;
if ( error ) {
F_132 ( V_10 ,
L_5 ,
V_269 , V_2 -> V_168 ) ;
goto V_268;
}
if ( ( V_250 -> V_270 . V_271 != F_60 ( V_2 ) -> V_272 . V_271 ) ||
( V_250 -> V_270 . V_273 != F_60 ( V_2 ) -> V_272 . V_273 ) ||
( V_250 -> V_274 . V_271 != F_60 ( V_2 ) -> V_275 . V_271 ) ||
( V_250 -> V_274 . V_273 != F_60 ( V_2 ) -> V_275 . V_273 ) ) {
error = - V_276 ;
goto V_268;
}
if ( ( ( F_56 ( V_2 ) != 0 ) && ( V_2 -> V_48 . V_277 > 0 ) ) &&
( V_2 -> V_48 . V_127 != V_129 ) ) {
error = F_44 ( V_5 , V_2 , V_126 , & V_256 ) ;
if ( error )
goto V_268;
}
if ( ( ( F_56 ( V_247 ) != 0 ) && ( V_247 -> V_48 . V_277 > 0 ) ) &&
( V_247 -> V_48 . V_127 != V_129 ) ) {
error = F_44 ( V_5 , V_247 , V_126 ,
& V_257 ) ;
if ( error )
goto V_268;
}
V_254 = V_50 ;
V_255 = V_50 ;
if ( V_2 -> V_48 . V_278 == 3 &&
V_2 -> V_48 . V_131 == V_128 ) {
V_255 |= V_279 ;
error = F_133 ( V_5 , V_2 , V_107 ,
V_247 -> V_168 , NULL ) ;
if ( error )
goto V_268;
}
if ( V_247 -> V_48 . V_278 == 3 &&
V_247 -> V_48 . V_131 == V_128 ) {
V_254 |= V_279 ;
error = F_133 ( V_5 , V_247 , V_107 ,
V_2 -> V_168 , NULL ) ;
if ( error )
goto V_268;
}
V_60 = & V_2 -> V_174 ;
V_253 = & V_247 -> V_174 ;
* V_252 = * V_60 ;
* V_60 = * V_253 ;
* V_253 = * V_252 ;
V_258 = ( T_28 ) V_2 -> V_48 . V_49 ;
V_2 -> V_48 . V_49 = V_247 -> V_48 . V_49 - V_257 + V_256 ;
V_247 -> V_48 . V_49 = V_258 + V_257 - V_256 ;
V_258 = ( T_28 ) V_2 -> V_48 . V_248 ;
V_2 -> V_48 . V_248 = V_247 -> V_48 . V_248 ;
V_247 -> V_48 . V_248 = V_258 ;
V_258 = ( T_28 ) V_2 -> V_48 . V_131 ;
V_2 -> V_48 . V_131 = V_247 -> V_48 . V_131 ;
V_247 -> V_48 . V_131 = V_258 ;
ASSERT ( V_247 -> V_51 == 0 ) ;
V_247 -> V_51 = V_2 -> V_51 ;
V_2 -> V_51 = 0 ;
switch ( V_2 -> V_48 . V_131 ) {
case V_86 :
if ( V_2 -> V_48 . V_248 <= V_280 ) {
V_60 -> V_281 . V_282 =
V_60 -> V_283 . V_284 ;
}
V_254 |= V_285 ;
break;
case V_128 :
ASSERT ( V_2 -> V_48 . V_278 < 3 ||
( V_254 & V_279 ) ) ;
V_254 |= V_286 ;
break;
}
switch ( V_247 -> V_48 . V_131 ) {
case V_86 :
if ( V_247 -> V_48 . V_248 <= V_280 ) {
V_253 -> V_281 . V_282 =
V_253 -> V_283 . V_284 ;
}
V_255 |= V_285 ;
break;
case V_128 :
V_255 |= V_286 ;
ASSERT ( V_247 -> V_48 . V_278 < 3 ||
( V_255 & V_279 ) ) ;
break;
}
F_25 ( V_5 , V_2 , V_254 ) ;
F_25 ( V_5 , V_247 , V_255 ) ;
if ( V_10 -> V_287 & V_288 )
F_134 ( V_5 ) ;
error = F_86 ( V_5 ) ;
F_135 ( V_2 , 0 ) ;
F_135 ( V_247 , 1 ) ;
V_95:
F_68 ( V_252 ) ;
return error ;
V_262:
F_69 ( V_2 , V_259 ) ;
F_69 ( V_247 , V_259 ) ;
goto V_95;
V_268:
F_82 ( V_5 ) ;
goto V_95;
}
