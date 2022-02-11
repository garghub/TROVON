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
return F_7 ( F_8 ( F_9 ( V_2 ) ) ,
V_10 << ( V_8 -> V_11 -> V_12 - 9 ) ,
V_6 << ( V_8 -> V_11 -> V_12 - 9 ) ,
V_13 , true ) ;
}
int
F_10 (
struct V_14 * V_15 )
{
T_5 V_16 = 0 ;
int error ;
T_6 * V_8 ;
T_7 V_17 = 0 ;
T_7 V_18 = 0 ;
T_7 V_19 ;
T_8 V_20 ;
V_8 = V_15 -> V_2 -> V_4 ;
V_19 = F_11 ( V_15 -> V_2 ) ;
V_17 = V_19 / V_8 -> V_21 . V_22 ;
error = F_12 ( V_8 , & V_15 -> V_23 , & V_15 -> V_24 ,
V_19 , 1 , V_15 -> V_25 , 0 ,
V_15 -> V_26 , & V_15 -> V_27 , & V_15 -> V_28 ) ;
if ( error )
return error ;
ASSERT ( V_15 -> V_28 ) ;
ASSERT ( V_15 -> V_28 % V_8 -> V_21 . V_22 == 0 ) ;
if ( F_13 ( V_15 -> V_27 , V_19 ) || V_15 -> V_28 % V_19 )
V_17 = 1 ;
V_18 = V_15 -> V_28 / V_8 -> V_21 . V_22 ;
if ( V_18 * V_8 -> V_21 . V_22 >= V_29 )
V_18 = V_29 / V_8 -> V_21 . V_22 ;
F_14 ( V_8 -> V_30 , V_31 | V_32 ) ;
F_15 ( V_15 -> V_33 , V_8 -> V_30 , V_31 ) ;
F_14 ( V_8 -> V_34 , V_31 | V_35 ) ;
F_15 ( V_15 -> V_33 , V_8 -> V_34 , V_31 ) ;
if ( V_15 -> V_25 && V_15 -> V_27 == 0 ) {
T_8 V_36 ( V_37 ) ;
error = F_16 ( V_8 , V_15 -> V_33 , V_18 , & V_37 ) ;
if ( error )
return error ;
V_15 -> V_38 = V_37 * V_8 -> V_21 . V_22 ;
} else {
V_15 -> V_38 = 0 ;
}
F_17 ( V_15 ) ;
V_16 = V_15 -> V_38 == 0 ? V_39 : V_40 ;
F_18 ( V_15 -> V_38 , V_8 -> V_21 . V_22 ) ;
V_20 = V_15 -> V_38 ;
V_15 -> V_28 = V_18 ;
if ( ( error = F_19 ( V_15 -> V_33 , V_15 -> V_38 , 1 , V_15 -> V_28 ,
& V_18 , V_16 , V_15 -> V_41 , V_17 , & V_20 ) ) )
return error ;
if ( V_20 == V_42 && V_17 > 1 &&
( error = F_19 ( V_15 -> V_33 , V_15 -> V_38 , 1 ,
V_15 -> V_28 , & V_18 , V_16 ,
V_15 -> V_41 , 1 , & V_20 ) ) )
return error ;
V_15 -> V_38 = V_20 ;
if ( V_15 -> V_38 != V_42 ) {
V_15 -> V_38 *= V_8 -> V_21 . V_22 ;
V_18 *= V_8 -> V_21 . V_22 ;
V_15 -> V_28 = V_18 ;
V_15 -> V_2 -> V_43 . V_44 += V_18 ;
F_20 ( V_15 -> V_33 , V_15 -> V_2 , V_45 ) ;
if ( V_15 -> V_41 )
V_15 -> V_2 -> V_46 -= V_18 ;
F_21 ( V_15 -> V_33 , V_15 -> V_2 ,
V_15 -> V_41 ? V_47 :
V_48 , ( long ) V_18 ) ;
if ( V_15 -> V_49 & V_50 ) {
error = F_5 ( V_15 -> V_2 , V_15 -> V_38 , V_15 -> V_28 ) ;
if ( error )
return error ;
}
} else {
V_15 -> V_28 = 0 ;
}
return 0 ;
}
int
F_22 (
struct V_1 * V_2 ,
T_9 V_51 ,
int V_52 ,
int * V_25 )
{
struct V_53 V_54 ;
int error ;
error = F_23 ( NULL , V_2 , V_52 , & V_54 , V_25 ) ;
if ( error || * V_25 )
return error ;
* V_25 = V_51 >= V_54 . V_55 + V_54 . V_56 ;
return 0 ;
}
STATIC void
F_24 (
T_10 * V_57 ,
T_11 V_58 ,
int V_59 ,
int * V_60 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_59 ; V_61 ++ ) {
T_12 * V_62 = F_25 ( V_57 , V_58 + V_61 ) ;
* V_60 += F_26 ( V_62 ) ;
}
}
STATIC void
F_27 (
struct V_7 * V_8 ,
struct V_63 * V_10 ,
int V_59 ,
int * V_60 )
{
int V_61 ;
T_13 * V_62 ;
for ( V_61 = 1 ; V_61 <= V_59 ; V_61 ++ ) {
V_62 = F_28 ( V_8 , V_10 , V_61 ) ;
* V_60 += F_29 ( V_62 ) ;
}
}
STATIC int
F_30 (
T_6 * V_8 ,
T_14 * V_33 ,
T_10 * V_57 ,
T_2 V_64 ,
int V_65 ,
int * V_60 )
{
int error ;
T_15 * V_66 , * V_67 ;
int V_68 = V_65 ;
T_16 * V_69 ;
T_2 V_70 = V_64 ;
T_2 V_71 ;
struct V_63 * V_10 , * V_72 ;
int V_59 ;
error = F_31 ( V_8 , V_33 , V_70 , 0 , & V_66 , V_73 ,
& V_74 ) ;
if ( error )
return error ;
* V_60 += 1 ;
V_10 = F_32 ( V_66 ) ;
if ( -- V_68 ) {
V_71 = F_33 ( V_10 -> V_75 . V_76 . V_77 ) ;
while ( V_71 != V_42 ) {
error = F_31 ( V_8 , V_33 , V_71 , 0 , & V_67 ,
V_73 ,
& V_74 ) ;
if ( error )
return error ;
* V_60 += 1 ;
V_72 = F_32 ( V_67 ) ;
V_71 = F_33 ( V_72 -> V_75 . V_76 . V_77 ) ;
F_34 ( V_33 , V_67 ) ;
}
V_69 = F_35 ( V_8 , V_10 , 1 , V_8 -> V_78 [ 1 ] ) ;
V_70 = F_33 ( * V_69 ) ;
if ( F_36 ( ( error =
F_30 ( V_8 , V_33 , V_57 , V_70 , V_68 , V_60 ) ) < 0 ) ) {
F_34 ( V_33 , V_66 ) ;
F_37 ( L_1 ,
V_79 , V_8 ) ;
return - V_80 ;
}
F_34 ( V_33 , V_66 ) ;
} else {
for (; ; ) {
V_71 = F_33 ( V_10 -> V_75 . V_76 . V_77 ) ;
V_59 = F_38 ( V_10 -> V_81 ) ;
F_27 ( V_8 , V_10 , V_59 , V_60 ) ;
F_34 ( V_33 , V_66 ) ;
if ( V_71 == V_42 )
break;
V_70 = V_71 ;
error = F_31 ( V_8 , V_33 , V_70 , 0 , & V_66 ,
V_73 ,
& V_74 ) ;
if ( error )
return error ;
* V_60 += 1 ;
V_10 = F_32 ( V_66 ) ;
}
}
return 0 ;
}
static int
F_39 (
T_14 * V_33 ,
T_17 * V_2 ,
int V_52 ,
int * V_60 )
{
struct V_63 * V_10 ;
T_2 V_70 ;
T_10 * V_57 ;
int V_68 ;
T_6 * V_8 ;
T_16 * V_69 ;
V_70 = V_42 ;
V_8 = V_2 -> V_4 ;
V_57 = F_40 ( V_2 , V_52 ) ;
if ( F_41 ( V_2 , V_52 ) == V_82 ) {
F_24 ( V_57 , 0 ,
V_57 -> V_83 / ( V_84 ) sizeof( T_13 ) ,
V_60 ) ;
return 0 ;
}
V_10 = V_57 -> V_85 ;
V_68 = F_38 ( V_10 -> V_86 ) ;
ASSERT ( V_68 > 0 ) ;
V_69 = F_42 ( V_8 , V_10 , 1 , V_57 -> V_87 ) ;
V_70 = F_33 ( * V_69 ) ;
ASSERT ( V_70 != V_42 ) ;
ASSERT ( F_43 ( V_8 , V_70 ) < V_8 -> V_21 . V_88 ) ;
ASSERT ( F_44 ( V_8 , V_70 ) < V_8 -> V_21 . V_89 ) ;
if ( F_36 ( F_30 ( V_8 , V_33 , V_57 , V_70 , V_68 , V_60 ) < 0 ) ) {
F_37 ( L_2 , V_79 ,
V_8 ) ;
return - V_80 ;
}
return 0 ;
}
STATIC int
F_45 (
T_17 * V_2 ,
struct V_90 * V_91 ,
int V_92 ,
T_18 V_93 ,
T_2 V_94 )
{
T_18 V_95 ;
T_6 * V_8 ;
T_10 * V_57 ;
T_11 V_96 ;
T_9 V_97 ;
if ( V_94 == V_98 ) {
V_8 = V_2 -> V_4 ;
V_91 -> V_99 = - 1 ;
V_95 = F_3 ( V_8 , F_46 ( V_8 , F_47 ( V_2 ) ) ) ;
V_95 -= V_91 -> V_100 ;
if ( V_92 && V_91 -> V_100 + V_91 -> V_101 == V_93 ) {
if ( V_95 <= 0 )
return 0 ;
V_91 -> V_101 = V_95 ;
}
} else {
if ( V_94 == V_102 )
V_91 -> V_99 = - 2 ;
else
V_91 -> V_99 = F_1 ( V_2 , V_94 ) ;
V_97 = F_48 ( V_2 -> V_4 , V_91 -> V_100 ) ;
V_57 = F_40 ( V_2 , V_103 ) ;
if ( F_49 ( V_57 , V_97 , & V_96 ) &&
( V_96 == ( V_57 -> V_83 / ( V_84 ) sizeof( T_13 ) ) - 1 ) )
V_91 -> V_104 |= V_105 ;
}
return 1 ;
}
int
F_50 (
T_17 * V_2 ,
struct V_90 * V_106 ,
T_19 V_107 ,
void * V_108 )
{
T_18 V_109 ;
int error = 0 ;
T_18 V_95 ;
int V_110 ;
int V_111 ;
T_20 * V_112 ;
T_6 * V_8 ;
int V_113 ;
int V_114 ;
int V_115 ;
int V_116 ;
struct V_90 * V_91 ;
int V_52 ;
int V_92 ;
int V_117 ;
int V_118 ;
int V_119 = 0 ;
V_8 = V_2 -> V_4 ;
V_117 = V_106 -> V_120 ;
V_52 = V_117 & V_121 ? V_122 : V_103 ;
if ( V_52 == V_122 ) {
if ( F_51 ( V_2 ) ) {
if ( V_2 -> V_43 . V_123 != V_82 &&
V_2 -> V_43 . V_123 != V_124 &&
V_2 -> V_43 . V_123 != V_125 )
return - V_126 ;
} else if ( F_36 (
V_2 -> V_43 . V_123 != 0 &&
V_2 -> V_43 . V_123 != V_82 ) ) {
F_37 ( L_3 , V_79 ,
V_2 -> V_4 ) ;
return - V_80 ;
}
V_92 = 0 ;
V_95 = 1LL << 32 ;
} else {
if ( V_2 -> V_43 . V_127 != V_82 &&
V_2 -> V_43 . V_127 != V_124 &&
V_2 -> V_43 . V_127 != V_125 )
return - V_126 ;
if ( F_11 ( V_2 ) ||
V_2 -> V_43 . V_128 & ( V_129 | V_130 ) ) {
V_92 = 1 ;
V_95 = V_8 -> V_11 -> V_131 ;
} else {
V_92 = 0 ;
V_95 = F_47 ( V_2 ) ;
}
}
if ( V_106 -> V_101 == - 1 ) {
V_95 = F_3 ( V_8 , F_46 ( V_8 , V_95 ) ) ;
V_106 -> V_101 =
F_52 ( T_18 , V_95 - V_106 -> V_100 , 0 ) ;
} else if ( V_106 -> V_101 == 0 ) {
V_106 -> V_132 = 0 ;
return 0 ;
} else if ( V_106 -> V_101 < 0 ) {
return - V_126 ;
}
V_113 = V_106 -> V_133 - 1 ;
if ( V_113 <= 0 )
return - V_126 ;
V_109 = V_106 -> V_100 + V_106 -> V_101 ;
if ( V_106 -> V_133 > V_134 / sizeof( struct V_90 ) )
return - V_135 ;
V_91 = F_53 ( V_106 -> V_133 * sizeof( struct V_90 ) , 0 ) ;
if ( ! V_91 )
return - V_135 ;
F_14 ( V_2 , V_136 ) ;
if ( V_52 == V_103 ) {
if ( ! ( V_117 & V_137 ) &&
( V_2 -> V_46 || F_47 ( V_2 ) > V_2 -> V_43 . V_138 ) ) {
error = F_54 ( F_9 ( V_2 ) -> V_139 ) ;
if ( error )
goto V_140;
}
V_111 = F_55 ( V_2 ) ;
} else {
V_111 = F_56 ( V_2 ) ;
}
if ( V_113 > F_57 ( V_2 , V_52 ) * 2 + 1 )
V_113 = F_57 ( V_2 , V_52 ) * 2 + 1 ;
V_118 = F_58 ( V_52 ) ;
if ( ! ( V_117 & V_141 ) )
V_118 |= V_142 ;
error = - V_135 ;
V_115 = 16 ;
V_112 = F_59 ( V_115 * sizeof( * V_112 ) , V_143 | V_144 ) ;
if ( ! V_112 )
goto V_145;
V_106 -> V_132 = 0 ;
if ( F_57 ( V_2 , V_52 ) == 0 &&
( V_52 == V_122 || ! ( V_117 & V_137 ) ) ) {
error = 0 ;
goto V_146;
}
V_114 = V_113 ;
do {
V_116 = ( V_114 > V_115 ) ? V_115 : V_114 ;
error = F_60 ( V_2 , F_6 ( V_8 , V_106 -> V_100 ) ,
F_48 ( V_8 , V_106 -> V_101 ) ,
V_112 , & V_116 , V_118 ) ;
if ( error )
goto V_146;
ASSERT ( V_116 <= V_115 ) ;
for ( V_110 = 0 ; V_110 < V_116 && V_114 && V_106 -> V_101 ; V_110 ++ ) {
V_91 [ V_119 ] . V_104 = 0 ;
if ( V_112 [ V_110 ] . V_147 == V_148 )
V_91 [ V_119 ] . V_104 |= V_149 ;
else if ( V_112 [ V_110 ] . V_150 == V_102 )
V_91 [ V_119 ] . V_104 |= V_151 ;
V_91 [ V_119 ] . V_100 =
F_3 ( V_8 , V_112 [ V_110 ] . V_55 ) ;
V_91 [ V_119 ] . V_101 =
F_3 ( V_8 , V_112 [ V_110 ] . V_56 ) ;
V_91 [ V_119 ] . V_152 = 0 ;
V_91 [ V_119 ] . V_153 = 0 ;
if ( V_112 [ V_110 ] . V_150 == V_102 &&
V_112 [ V_110 ] . V_55 <= F_46 ( V_8 , F_47 ( V_2 ) ) )
ASSERT ( ( V_117 & V_137 ) != 0 ) ;
if ( V_112 [ V_110 ] . V_150 == V_98 &&
V_52 == V_122 ) {
V_91 [ V_119 ] . V_104 |= V_105 ;
goto V_146;
}
if ( ! F_45 ( V_2 , & V_91 [ V_119 ] ,
V_92 , V_109 ,
V_112 [ V_110 ] . V_150 ) )
goto V_146;
V_106 -> V_100 =
V_91 [ V_119 ] . V_100 +
V_91 [ V_119 ] . V_101 ;
V_106 -> V_101 =
F_52 ( T_18 , 0 , V_109 - V_106 -> V_100 ) ;
if ( ( V_117 & V_154 ) &&
V_112 [ V_110 ] . V_150 == V_98 ) {
memset ( & V_91 [ V_119 ] , 0 , sizeof( V_91 [ V_119 ] ) ) ;
continue;
}
V_114 -- ;
V_106 -> V_132 ++ ;
V_119 ++ ;
}
} while ( V_116 && V_114 && V_106 -> V_101 );
V_146:
F_61 ( V_112 ) ;
V_145:
F_62 ( V_2 , V_111 ) ;
V_140:
F_62 ( V_2 , V_136 ) ;
for ( V_110 = 0 ; V_110 < V_119 ; V_110 ++ ) {
int V_155 = 0 ;
error = V_107 ( & V_108 , & V_91 [ V_110 ] , & V_155 ) ;
if ( error || V_155 )
break;
}
F_61 ( V_91 ) ;
return error ;
}
int
F_63 (
struct V_1 * V_2 ,
T_9 V_5 ,
T_9 V_28 )
{
T_9 V_156 = V_28 ;
int error = 0 ;
ASSERT ( F_64 ( V_2 , V_31 ) ) ;
do {
int V_157 ;
T_20 V_158 ;
int V_159 = 1 ;
T_2 V_160 ;
struct V_161 V_162 ;
error = F_60 ( V_2 , V_5 , 1 , & V_158 , & V_159 ,
V_163 ) ;
if ( error ) {
if ( ! F_65 ( V_2 -> V_4 ) ) {
F_66 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_164 , V_5 ) ;
}
break;
}
if ( ! V_159 ) {
goto V_165;
}
if ( V_158 . V_150 != V_102 ) {
goto V_165;
}
F_67 ( V_158 . V_56 == 0 ) ;
F_68 ( & V_162 , & V_160 ) ;
error = F_69 ( NULL , V_2 , V_5 , 1 , 0 , 1 , & V_160 ,
& V_162 , & V_157 ) ;
if ( error )
break;
ASSERT ( ! F_70 ( & V_162 ) ) ;
V_165:
V_5 ++ ;
V_156 -- ;
} while( V_156 > 0 );
return error ;
}
bool
F_71 ( struct V_1 * V_2 , bool V_166 )
{
if ( ! F_72 ( F_9 ( V_2 ) -> V_167 ) )
return false ;
if ( F_9 ( V_2 ) -> V_168 == 0 &&
F_9 ( V_2 ) -> V_139 -> V_169 == 0 &&
V_2 -> V_46 == 0 )
return false ;
if ( ! ( V_2 -> V_170 . V_171 & V_172 ) )
return false ;
if ( V_2 -> V_43 . V_128 & ( V_129 | V_130 ) )
if ( ! V_166 || V_2 -> V_46 == 0 )
return false ;
return true ;
}
int
F_73 (
T_6 * V_8 ,
T_17 * V_2 ,
bool V_173 )
{
T_14 * V_33 ;
int error ;
T_9 V_174 ;
T_9 V_175 ;
T_21 V_176 ;
int V_159 ;
T_20 V_158 ;
V_174 = F_46 ( V_8 , ( V_177 ) F_47 ( V_2 ) ) ;
V_175 = F_46 ( V_8 , V_8 -> V_11 -> V_131 ) ;
if ( V_175 <= V_174 )
return 0 ;
V_176 = V_175 - V_174 ;
V_159 = 1 ;
F_14 ( V_2 , V_178 ) ;
error = F_60 ( V_2 , V_174 , V_176 , & V_158 , & V_159 , 0 ) ;
F_62 ( V_2 , V_178 ) ;
if ( ! error && ( V_159 != 0 ) &&
( V_158 . V_150 != V_98 ||
V_2 -> V_46 ) ) {
error = F_74 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_173 ) {
if ( ! F_75 ( V_2 , V_179 ) )
return - V_180 ;
}
error = F_76 ( V_8 , & F_77 ( V_8 ) -> V_181 , 0 , 0 , 0 ,
& V_33 ) ;
if ( error ) {
ASSERT ( F_65 ( V_8 ) ) ;
if ( V_173 )
F_62 ( V_2 , V_179 ) ;
return error ;
}
F_14 ( V_2 , V_31 ) ;
F_15 ( V_33 , V_2 , 0 ) ;
error = F_78 ( & V_33 , V_2 , V_103 ,
F_47 ( V_2 ) ) ;
if ( error ) {
F_79 ( V_33 ) ;
} else {
error = F_80 ( V_33 ) ;
if ( ! error )
F_81 ( V_2 ) ;
}
F_62 ( V_2 , V_31 ) ;
if ( V_173 )
F_62 ( V_2 , V_179 ) ;
}
return error ;
}
int
F_82 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_182 ,
int V_183 )
{
T_6 * V_8 = V_2 -> V_4 ;
T_3 V_60 ;
T_21 V_184 ;
T_21 V_185 ;
T_7 V_186 , V_187 ;
T_9 V_188 ;
T_2 V_189 ;
int V_159 ;
int V_190 ;
int V_191 ;
T_14 * V_33 ;
T_20 V_192 [ 1 ] , * V_193 ;
struct V_161 V_162 ;
V_84 V_194 , V_195 , V_196 ;
int error ;
F_83 ( V_2 ) ;
if ( F_65 ( V_8 ) )
return - V_197 ;
error = F_74 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_182 <= 0 )
return - V_126 ;
V_191 = F_2 ( V_2 ) ;
V_186 = F_11 ( V_2 ) ;
V_60 = V_182 ;
V_193 = & V_192 [ 0 ] ;
V_159 = 1 ;
V_188 = F_84 ( V_8 , V_27 ) ;
V_185 = F_46 ( V_8 , V_60 ) ;
while ( V_185 && ! error ) {
T_9 V_198 , V_199 ;
if ( F_36 ( V_186 ) ) {
V_198 = V_188 ;
F_18 ( V_198 , V_186 ) ;
V_198 *= V_186 ;
V_199 = V_188 + V_185 ;
if ( ( V_187 = F_13 ( V_188 , V_186 ) ) )
V_199 += V_187 ;
if ( ( V_187 = F_13 ( V_199 , V_186 ) ) )
V_199 += V_186 - V_187 ;
} else {
V_198 = 0 ;
V_199 = V_185 ;
}
V_195 = F_85 ( T_9 , ( V_199 - V_198 ) , ( V_29 * V_159 ) ) ;
if ( F_36 ( V_191 ) ) {
V_196 = V_194 = V_195 ;
V_196 /= V_8 -> V_21 . V_22 ;
V_195 = F_86 ( V_8 , 0 ) ;
V_190 = V_200 ;
} else {
V_196 = 0 ;
V_195 = V_194 = F_86 ( V_8 , V_195 ) ;
V_190 = V_201 ;
}
error = F_76 ( V_8 , & F_77 ( V_8 ) -> V_202 , V_195 ,
V_196 , 0 , & V_33 ) ;
if ( error ) {
ASSERT ( error == - V_203 || F_65 ( V_8 ) ) ;
break;
}
F_14 ( V_2 , V_31 ) ;
error = F_87 ( V_33 , V_2 , V_194 ,
0 , V_190 ) ;
if ( error )
goto V_204;
F_15 ( V_33 , V_2 , 0 ) ;
F_68 ( & V_162 , & V_189 ) ;
error = F_88 ( V_33 , V_2 , V_188 ,
V_185 , V_183 , & V_189 ,
V_195 , V_193 , & V_159 , & V_162 ) ;
if ( error )
goto V_205;
error = F_89 ( & V_33 , & V_162 , NULL ) ;
if ( error )
goto V_205;
error = F_80 ( V_33 ) ;
F_62 ( V_2 , V_31 ) ;
if ( error )
break;
V_184 = V_193 -> V_56 ;
if ( V_159 == 0 ) {
error = - V_203 ;
break;
}
V_188 += V_184 ;
V_185 -= V_184 ;
}
return error ;
V_205:
F_90 ( & V_162 ) ;
F_91 ( V_33 , V_2 , ( long ) V_194 , 0 , V_190 ) ;
V_204:
F_79 ( V_33 ) ;
F_62 ( V_2 , V_31 ) ;
return error ;
}
static int
F_92 (
struct V_1 * V_2 ,
T_9 V_188 ,
T_21 V_206 ,
int * V_157 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_207 * V_33 ;
struct V_161 V_162 ;
T_2 V_189 ;
V_84 V_195 = F_86 ( V_8 , 0 ) ;
int error ;
error = F_76 ( V_8 , & F_77 ( V_8 ) -> V_202 , V_195 , 0 , 0 , & V_33 ) ;
if ( error ) {
ASSERT ( error == - V_203 || F_65 ( V_8 ) ) ;
return error ;
}
F_14 ( V_2 , V_31 ) ;
error = F_93 ( V_33 , V_8 , V_2 -> V_208 , V_2 -> V_209 ,
V_2 -> V_210 , V_195 , 0 , V_201 ) ;
if ( error )
goto V_211;
F_15 ( V_33 , V_2 , 0 ) ;
F_68 ( & V_162 , & V_189 ) ;
error = F_69 ( V_33 , V_2 , V_188 , V_206 , 0 , 2 , & V_189 ,
& V_162 , V_157 ) ;
if ( error )
goto V_212;
error = F_89 ( & V_33 , & V_162 , V_2 ) ;
if ( error )
goto V_212;
error = F_80 ( V_33 ) ;
V_213:
F_62 ( V_2 , V_31 ) ;
return error ;
V_212:
F_90 ( & V_162 ) ;
V_211:
F_79 ( V_33 ) ;
goto V_213;
}
static int
F_94 (
struct V_1 * V_2 ,
T_9 * V_188 ,
T_9 * V_214 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_53 V_158 ;
int V_215 , error ;
T_7 V_216 = 0 ;
V_215 = 1 ;
error = F_60 ( V_2 , * V_188 , 1 , & V_158 , & V_215 , 0 ) ;
if ( error )
return error ;
if ( V_215 && V_158 . V_150 != V_98 ) {
T_1 V_10 ;
ASSERT ( V_158 . V_150 != V_102 ) ;
V_10 = V_158 . V_150 ;
V_216 = F_18 ( V_10 , V_8 -> V_21 . V_22 ) ;
if ( V_216 )
* V_188 += V_8 -> V_21 . V_22 - V_216 ;
}
V_215 = 1 ;
error = F_60 ( V_2 , * V_214 - 1 , 1 , & V_158 , & V_215 , 0 ) ;
if ( error )
return error ;
if ( V_215 && V_158 . V_150 != V_98 ) {
ASSERT ( V_158 . V_150 != V_102 ) ;
V_216 ++ ;
if ( V_216 && V_216 != V_8 -> V_21 . V_22 )
* V_214 -= V_216 ;
}
return 0 ;
}
static int
F_95 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_182 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_217 * V_217 = F_9 ( V_2 ) ;
T_3 V_218 , V_219 , V_93 ;
int error ;
F_96 ( V_217 ) ;
V_218 = F_52 ( T_3 , 1 << V_8 -> V_21 . V_220 , V_221 ) ;
V_219 = F_97 ( V_27 , V_218 ) ;
V_93 = F_98 ( V_27 + V_182 , V_218 ) - 1 ;
error = F_99 ( V_217 -> V_139 , V_219 , V_93 ) ;
if ( error )
return error ;
F_100 ( V_217 , V_219 , V_93 ) ;
return 0 ;
}
int
F_101 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_182 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_9 V_188 ;
T_9 V_214 ;
int V_157 = 0 , error ;
F_102 ( V_2 ) ;
error = F_74 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_182 <= 0 )
return 0 ;
error = F_95 ( V_2 , V_27 , V_182 ) ;
if ( error )
return error ;
V_188 = F_46 ( V_8 , V_27 ) ;
V_214 = F_84 ( V_8 , V_27 + V_182 ) ;
if ( F_2 ( V_2 ) &&
! F_103 ( & V_8 -> V_21 ) ) {
error = F_94 ( V_2 , & V_188 ,
& V_214 ) ;
if ( error )
return error ;
}
if ( V_214 > V_188 ) {
while ( ! V_157 ) {
error = F_92 ( V_2 , V_188 ,
V_214 - V_188 , & V_157 ) ;
if ( error )
return error ;
}
}
return F_104 ( V_2 , V_27 , V_182 , NULL ) ;
}
int
F_105 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_182 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
V_84 V_222 ;
int error ;
F_106 ( V_2 ) ;
V_222 = 1 << V_8 -> V_21 . V_220 ;
error = F_101 ( V_2 , V_27 , V_182 ) ;
if ( error )
goto V_91;
error = F_82 ( V_2 , F_97 ( V_27 , V_222 ) ,
F_98 ( V_27 + V_182 , V_222 ) -
F_97 ( V_27 , V_222 ) ,
V_223 ) ;
V_91:
return error ;
}
static int
F_107 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_182 ,
enum V_224 V_225 )
{
int V_157 = 0 ;
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_207 * V_33 ;
int error ;
struct V_161 V_162 ;
T_2 V_226 ;
T_9 V_227 ;
T_9 V_228 ;
T_9 V_229 ;
ASSERT ( V_225 == V_230 || V_225 == V_231 ) ;
if ( V_225 == V_230 ) {
V_228 = F_46 ( V_8 , V_27 + V_182 ) ;
V_227 = F_46 ( V_8 , F_9 ( V_2 ) -> V_168 ) ;
} else {
V_228 = V_42 ;
V_227 = F_46 ( V_8 , V_27 ) ;
}
V_229 = F_46 ( V_8 , V_182 ) ;
if ( F_71 ( V_2 , true ) ) {
error = F_73 ( V_8 , V_2 , false ) ;
if ( error )
return error ;
}
error = F_99 ( F_9 ( V_2 ) -> V_139 ,
V_27 , - 1 ) ;
if ( error )
return error ;
error = F_108 ( F_9 ( V_2 ) -> V_139 ,
V_27 >> V_232 , - 1 ) ;
if ( error )
return error ;
if ( V_225 == V_231 ) {
error = F_109 ( V_2 , V_227 ) ;
if ( error )
return error ;
}
while ( ! error && ! V_157 ) {
error = F_76 ( V_8 , & F_77 ( V_8 ) -> V_202 ,
F_86 ( V_8 , 0 ) , 0 , 0 , & V_33 ) ;
if ( error )
break;
F_14 ( V_2 , V_31 ) ;
error = F_93 ( V_33 , V_8 , V_2 -> V_208 ,
V_2 -> V_209 , V_2 -> V_210 ,
F_86 ( V_8 , 0 ) , 0 ,
V_201 ) ;
if ( error )
goto V_211;
F_15 ( V_33 , V_2 , V_31 ) ;
F_68 ( & V_162 , & V_226 ) ;
error = F_110 ( V_33 , V_2 , & V_228 , V_229 ,
& V_157 , V_227 , & V_226 , & V_162 ,
V_225 , V_233 ) ;
if ( error )
goto V_212;
error = F_89 ( & V_33 , & V_162 , NULL ) ;
if ( error )
goto V_212;
error = F_80 ( V_33 ) ;
}
return error ;
V_212:
F_90 ( & V_162 ) ;
V_211:
F_79 ( V_33 ) ;
return error ;
}
int
F_111 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_182 )
{
int error ;
ASSERT ( F_64 ( V_2 , V_179 ) ) ;
F_112 ( V_2 ) ;
error = F_101 ( V_2 , V_27 , V_182 ) ;
if ( error )
return error ;
return F_107 ( V_2 , V_27 , V_182 , V_230 ) ;
}
int
F_113 (
struct V_1 * V_2 ,
T_22 V_27 ,
T_22 V_182 )
{
ASSERT ( F_64 ( V_2 , V_179 ) ) ;
F_114 ( V_2 ) ;
return F_107 ( V_2 , V_27 , V_182 , V_231 ) ;
}
static int
F_115 (
T_17 * V_2 ,
T_17 * V_234 )
{
if ( V_2 -> V_43 . V_127 == V_125 ||
V_234 -> V_43 . V_127 == V_125 )
return - V_126 ;
if ( V_2 -> V_43 . V_235 < V_234 -> V_43 . V_235 )
return - V_126 ;
if ( V_2 -> V_43 . V_127 == V_82 &&
V_234 -> V_43 . V_127 == V_124 )
return - V_126 ;
if ( V_234 -> V_43 . V_127 == V_82 &&
F_57 ( V_234 , V_103 ) >
F_116 ( V_2 , V_103 ) )
return - V_126 ;
if ( V_2 -> V_43 . V_127 == V_82 &&
F_57 ( V_2 , V_103 ) >
F_116 ( V_234 , V_103 ) )
return - V_126 ;
if ( V_234 -> V_43 . V_127 == V_124 ) {
if ( F_117 ( V_2 ) &&
F_118 ( V_234 -> V_170 . V_85 ) > F_117 ( V_2 ) )
return - V_126 ;
if ( F_57 ( V_234 , V_103 ) <=
F_116 ( V_2 , V_103 ) )
return - V_126 ;
}
if ( V_2 -> V_43 . V_127 == V_124 ) {
if ( F_117 ( V_234 ) &&
F_118 ( V_2 -> V_170 . V_85 ) > F_117 ( V_234 ) )
return - V_126 ;
if ( F_57 ( V_2 , V_103 ) <=
F_116 ( V_234 , V_103 ) )
return - V_126 ;
}
return 0 ;
}
static int
F_119 (
struct V_1 * V_2 )
{
int error ;
error = F_54 ( F_9 ( V_2 ) -> V_139 ) ;
if ( error )
return error ;
F_100 ( F_9 ( V_2 ) , 0 , - 1 ) ;
if ( F_9 ( V_2 ) -> V_139 -> V_169 )
return - V_126 ;
return 0 ;
}
int
F_120 (
T_17 * V_2 ,
T_17 * V_234 ,
T_23 * V_236 )
{
T_6 * V_8 = V_2 -> V_4 ;
T_14 * V_33 ;
T_24 * V_237 = & V_236 -> V_238 ;
T_10 * V_239 , * V_57 , * V_240 ;
int V_241 , V_242 ;
int error = 0 ;
int V_243 = 0 ;
int V_244 = 0 ;
T_25 V_245 ;
int V_246 ;
if ( F_121 ( & V_8 -> V_21 ) )
return - V_247 ;
V_239 = F_59 ( sizeof( T_10 ) , V_143 ) ;
if ( ! V_239 ) {
error = - V_135 ;
goto V_91;
}
V_246 = V_179 | V_248 ;
F_122 ( V_2 , V_234 , V_179 ) ;
F_122 ( V_2 , V_234 , V_248 ) ;
if ( ( F_9 ( V_2 ) -> V_167 & V_249 ) != ( F_9 ( V_234 ) -> V_167 & V_249 ) ) {
error = - V_126 ;
goto V_213;
}
if ( F_2 ( V_2 ) != F_2 ( V_234 ) ) {
error = - V_126 ;
goto V_213;
}
error = F_119 ( V_2 ) ;
if ( error )
goto V_213;
error = F_119 ( V_234 ) ;
if ( error )
goto V_213;
error = F_76 ( V_8 , & F_77 ( V_8 ) -> V_250 , 0 , 0 , 0 , & V_33 ) ;
if ( error )
goto V_213;
F_122 ( V_2 , V_234 , V_31 ) ;
V_246 |= V_31 ;
F_15 ( V_33 , V_2 , V_246 ) ;
F_15 ( V_33 , V_234 , V_246 ) ;
if ( V_236 -> V_251 != 0 ||
V_236 -> V_252 != V_2 -> V_43 . V_138 ||
V_236 -> V_252 != V_234 -> V_43 . V_138 ) {
error = - V_253 ;
goto V_211;
}
F_123 ( V_2 , 0 ) ;
F_123 ( V_234 , 1 ) ;
error = F_115 ( V_2 , V_234 ) ;
if ( error ) {
F_124 ( V_8 ,
L_5 ,
V_254 , V_2 -> V_164 ) ;
goto V_211;
}
if ( ( V_237 -> V_255 . V_256 != F_9 ( V_2 ) -> V_257 . V_256 ) ||
( V_237 -> V_255 . V_258 != F_9 ( V_2 ) -> V_257 . V_258 ) ||
( V_237 -> V_259 . V_256 != F_9 ( V_2 ) -> V_260 . V_256 ) ||
( V_237 -> V_259 . V_258 != F_9 ( V_2 ) -> V_260 . V_258 ) ) {
error = - V_261 ;
goto V_211;
}
if ( ( ( F_51 ( V_2 ) != 0 ) && ( V_2 -> V_43 . V_262 > 0 ) ) &&
( V_2 -> V_43 . V_123 != V_125 ) ) {
error = F_39 ( V_33 , V_2 , V_122 , & V_243 ) ;
if ( error )
goto V_211;
}
if ( ( ( F_51 ( V_234 ) != 0 ) && ( V_234 -> V_43 . V_262 > 0 ) ) &&
( V_234 -> V_43 . V_123 != V_125 ) ) {
error = F_39 ( V_33 , V_234 , V_122 ,
& V_244 ) ;
if ( error )
goto V_211;
}
V_241 = V_45 ;
V_242 = V_45 ;
if ( V_2 -> V_43 . V_263 == 3 &&
V_2 -> V_43 . V_127 == V_124 ) {
V_242 |= V_264 ;
error = F_125 ( V_33 , V_2 , V_103 ,
V_234 -> V_164 , NULL ) ;
if ( error )
goto V_211;
}
if ( V_234 -> V_43 . V_263 == 3 &&
V_234 -> V_43 . V_127 == V_124 ) {
V_241 |= V_264 ;
error = F_125 ( V_33 , V_234 , V_103 ,
V_2 -> V_164 , NULL ) ;
if ( error )
goto V_211;
}
V_57 = & V_2 -> V_170 ;
V_240 = & V_234 -> V_170 ;
* V_239 = * V_57 ;
* V_57 = * V_240 ;
* V_240 = * V_239 ;
V_245 = ( T_25 ) V_2 -> V_43 . V_44 ;
V_2 -> V_43 . V_44 = V_234 -> V_43 . V_44 - V_244 + V_243 ;
V_234 -> V_43 . V_44 = V_245 + V_244 - V_243 ;
V_245 = ( T_25 ) V_2 -> V_43 . V_235 ;
V_2 -> V_43 . V_235 = V_234 -> V_43 . V_235 ;
V_234 -> V_43 . V_235 = V_245 ;
V_245 = ( T_25 ) V_2 -> V_43 . V_127 ;
V_2 -> V_43 . V_127 = V_234 -> V_43 . V_127 ;
V_234 -> V_43 . V_127 = V_245 ;
ASSERT ( V_234 -> V_46 == 0 ) ;
V_234 -> V_46 = V_2 -> V_46 ;
V_2 -> V_46 = 0 ;
switch ( V_2 -> V_43 . V_127 ) {
case V_82 :
if ( V_2 -> V_43 . V_235 <= V_265 ) {
V_57 -> V_266 . V_267 =
V_57 -> V_268 . V_269 ;
}
V_241 |= V_270 ;
break;
case V_124 :
ASSERT ( V_2 -> V_43 . V_263 < 3 ||
( V_241 & V_264 ) ) ;
V_241 |= V_271 ;
break;
}
switch ( V_234 -> V_43 . V_127 ) {
case V_82 :
if ( V_234 -> V_43 . V_235 <= V_265 ) {
V_240 -> V_266 . V_267 =
V_240 -> V_268 . V_269 ;
}
V_242 |= V_270 ;
break;
case V_124 :
V_242 |= V_271 ;
ASSERT ( V_234 -> V_43 . V_263 < 3 ||
( V_242 & V_264 ) ) ;
break;
}
F_20 ( V_33 , V_2 , V_241 ) ;
F_20 ( V_33 , V_234 , V_242 ) ;
if ( V_8 -> V_272 & V_273 )
F_126 ( V_33 ) ;
error = F_80 ( V_33 ) ;
F_127 ( V_2 , 0 ) ;
F_127 ( V_234 , 1 ) ;
V_91:
F_61 ( V_239 ) ;
return error ;
V_213:
F_62 ( V_2 , V_246 ) ;
F_62 ( V_234 , V_246 ) ;
goto V_91;
V_211:
F_79 ( V_33 ) ;
goto V_91;
}
