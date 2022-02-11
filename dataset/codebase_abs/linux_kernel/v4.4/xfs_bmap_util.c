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
return F_10 ( F_9 ( V_2 ) , V_10 , V_11 ) ;
return F_11 ( V_8 -> V_12 , V_10 , V_6 , V_13 ) ;
}
int
F_12 (
struct V_14 * * V_15 ,
struct V_16 * V_17 ,
int * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int error ;
struct V_23 * free ;
struct V_23 * V_24 ;
ASSERT ( ( * V_15 ) -> V_25 & V_26 ) ;
if ( V_17 -> V_27 == 0 ) {
* V_18 = 0 ;
return 0 ;
}
V_22 = F_13 ( * V_15 , V_17 -> V_27 ) ;
for ( free = V_17 -> V_28 ; free ; free = free -> V_29 )
F_14 ( * V_15 , V_22 , free -> V_30 ,
free -> V_31 ) ;
error = F_15 ( V_15 , NULL , V_18 ) ;
if ( error ) {
if ( * V_18 ) {
F_16 ( V_22 ) ;
F_17 ( ( * V_15 ) -> V_32 ,
( error == - V_33 ) ?
V_34 :
V_35 ) ;
} else {
* V_18 = 1 ;
}
return error ;
}
V_20 = F_18 ( * V_15 , V_22 , V_17 -> V_27 ) ;
for ( free = V_17 -> V_28 ; free != NULL ; free = V_24 ) {
V_24 = free -> V_29 ;
error = F_19 ( * V_15 , V_20 , free -> V_30 ,
free -> V_31 ) ;
if ( error )
return error ;
F_20 ( V_17 , NULL , free ) ;
}
return 0 ;
}
int
F_21 (
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
V_41 = F_22 ( V_37 -> V_2 ) ;
V_39 = V_41 / V_8 -> V_43 . V_44 ;
error = F_23 ( V_8 , & V_37 -> V_45 , & V_37 -> V_46 ,
V_41 , 1 , V_37 -> V_47 , 0 ,
V_37 -> V_48 , & V_37 -> V_49 , & V_37 -> V_50 ) ;
if ( error )
return error ;
ASSERT ( V_37 -> V_50 ) ;
ASSERT ( V_37 -> V_50 % V_8 -> V_43 . V_44 == 0 ) ;
if ( F_24 ( V_37 -> V_49 , V_41 ) || V_37 -> V_50 % V_41 )
V_39 = 1 ;
V_40 = V_37 -> V_50 / V_8 -> V_43 . V_44 ;
if ( V_40 * V_8 -> V_43 . V_44 >= V_51 )
V_40 = V_51 / V_8 -> V_43 . V_44 ;
F_25 ( V_8 -> V_52 , V_53 ) ;
F_26 ( V_37 -> V_15 , V_8 -> V_52 , V_53 ) ;
if ( V_37 -> V_47 && V_37 -> V_49 == 0 ) {
T_9 V_54 ( V_55 ) ;
error = F_27 ( V_8 , V_37 -> V_15 , V_40 , & V_55 ) ;
if ( error )
return error ;
V_37 -> V_56 = V_55 * V_8 -> V_43 . V_44 ;
} else {
V_37 -> V_56 = 0 ;
}
F_28 ( V_37 ) ;
V_38 = V_37 -> V_56 == 0 ? V_57 : V_58 ;
F_29 ( V_37 -> V_56 , V_8 -> V_43 . V_44 ) ;
V_42 = V_37 -> V_56 ;
V_37 -> V_50 = V_40 ;
if ( ( error = F_30 ( V_37 -> V_15 , V_37 -> V_56 , 1 , V_37 -> V_50 ,
& V_40 , V_38 , V_37 -> V_59 , V_39 , & V_42 ) ) )
return error ;
if ( V_42 == V_60 && V_39 > 1 &&
( error = F_30 ( V_37 -> V_15 , V_37 -> V_56 , 1 ,
V_37 -> V_50 , & V_40 , V_38 ,
V_37 -> V_59 , 1 , & V_42 ) ) )
return error ;
V_37 -> V_56 = V_42 ;
if ( V_37 -> V_56 != V_60 ) {
V_37 -> V_56 *= V_8 -> V_43 . V_44 ;
V_40 *= V_8 -> V_43 . V_44 ;
V_37 -> V_50 = V_40 ;
V_37 -> V_2 -> V_61 . V_62 += V_40 ;
F_31 ( V_37 -> V_15 , V_37 -> V_2 , V_63 ) ;
if ( V_37 -> V_59 )
V_37 -> V_2 -> V_64 -= V_40 ;
F_32 ( V_37 -> V_15 , V_37 -> V_2 ,
V_37 -> V_59 ? V_65 :
V_66 , ( long ) V_40 ) ;
if ( V_37 -> V_67 & V_68 ) {
error = F_5 ( V_37 -> V_2 , V_37 -> V_56 , V_37 -> V_50 ) ;
if ( error )
return error ;
}
} else {
V_37 -> V_50 = 0 ;
}
return 0 ;
}
int
F_33 (
struct V_1 * V_2 ,
T_10 V_69 ,
int V_70 ,
int * V_47 )
{
struct V_71 V_72 ;
int error ;
error = F_34 ( NULL , V_2 , V_70 , & V_72 , V_47 ) ;
if ( error || * V_47 )
return error ;
* V_47 = V_69 >= V_72 . V_73 + V_72 . V_74 ;
return 0 ;
}
STATIC void
F_35 (
T_11 * V_75 ,
T_12 V_76 ,
int V_77 ,
int * V_78 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_77 ; V_79 ++ ) {
T_13 * V_80 = F_36 ( V_75 , V_76 + V_79 ) ;
* V_78 += F_37 ( V_80 ) ;
}
}
STATIC void
F_38 (
struct V_7 * V_8 ,
struct V_81 * V_10 ,
int V_77 ,
int * V_78 )
{
int V_79 ;
T_14 * V_80 ;
for ( V_79 = 1 ; V_79 <= V_77 ; V_79 ++ ) {
V_80 = F_39 ( V_8 , V_10 , V_79 ) ;
* V_78 += F_40 ( V_80 ) ;
}
}
STATIC int
F_41 (
T_7 * V_8 ,
T_15 * V_15 ,
T_11 * V_75 ,
T_2 V_82 ,
int V_83 ,
int * V_78 )
{
int error ;
T_16 * V_84 , * V_85 ;
int V_86 = V_83 ;
T_17 * V_87 ;
T_2 V_88 = V_82 ;
T_2 V_89 ;
struct V_81 * V_10 , * V_90 ;
int V_77 ;
error = F_42 ( V_8 , V_15 , V_88 , 0 , & V_84 , V_91 ,
& V_92 ) ;
if ( error )
return error ;
* V_78 += 1 ;
V_10 = F_43 ( V_84 ) ;
if ( -- V_86 ) {
V_89 = F_44 ( V_10 -> V_93 . V_94 . V_95 ) ;
while ( V_89 != V_60 ) {
error = F_42 ( V_8 , V_15 , V_89 , 0 , & V_85 ,
V_91 ,
& V_92 ) ;
if ( error )
return error ;
* V_78 += 1 ;
V_90 = F_43 ( V_85 ) ;
V_89 = F_44 ( V_90 -> V_93 . V_94 . V_95 ) ;
F_45 ( V_15 , V_85 ) ;
}
V_87 = F_46 ( V_8 , V_10 , 1 , V_8 -> V_96 [ 1 ] ) ;
V_88 = F_44 ( * V_87 ) ;
if ( F_47 ( ( error =
F_41 ( V_8 , V_15 , V_75 , V_88 , V_86 , V_78 ) ) < 0 ) ) {
F_45 ( V_15 , V_84 ) ;
F_48 ( L_1 ,
V_97 , V_8 ) ;
return - V_33 ;
}
F_45 ( V_15 , V_84 ) ;
} else {
for (; ; ) {
V_89 = F_44 ( V_10 -> V_93 . V_94 . V_95 ) ;
V_77 = F_49 ( V_10 -> V_98 ) ;
F_38 ( V_8 , V_10 , V_77 , V_78 ) ;
F_45 ( V_15 , V_84 ) ;
if ( V_89 == V_60 )
break;
V_88 = V_89 ;
error = F_42 ( V_8 , V_15 , V_88 , 0 , & V_84 ,
V_91 ,
& V_92 ) ;
if ( error )
return error ;
* V_78 += 1 ;
V_10 = F_43 ( V_84 ) ;
}
}
return 0 ;
}
int
F_50 (
T_15 * V_15 ,
T_18 * V_2 ,
int V_70 ,
int * V_78 )
{
struct V_81 * V_10 ;
T_2 V_88 ;
T_11 * V_75 ;
int V_86 ;
T_7 * V_8 ;
T_17 * V_87 ;
V_88 = V_60 ;
V_8 = V_2 -> V_4 ;
V_75 = F_51 ( V_2 , V_70 ) ;
if ( F_52 ( V_2 , V_70 ) == V_99 ) {
F_35 ( V_75 , 0 ,
V_75 -> V_100 / ( V_101 ) sizeof( T_14 ) ,
V_78 ) ;
return 0 ;
}
V_10 = V_75 -> V_102 ;
V_86 = F_49 ( V_10 -> V_103 ) ;
ASSERT ( V_86 > 0 ) ;
V_87 = F_53 ( V_8 , V_10 , 1 , V_75 -> V_104 ) ;
V_88 = F_44 ( * V_87 ) ;
ASSERT ( V_88 != V_60 ) ;
ASSERT ( F_54 ( V_8 , V_88 ) < V_8 -> V_43 . V_105 ) ;
ASSERT ( F_55 ( V_8 , V_88 ) < V_8 -> V_43 . V_106 ) ;
if ( F_47 ( F_41 ( V_8 , V_15 , V_75 , V_88 , V_86 , V_78 ) < 0 ) ) {
F_48 ( L_2 , V_97 ,
V_8 ) ;
return - V_33 ;
}
return 0 ;
}
STATIC int
F_56 (
T_18 * V_2 ,
struct V_107 * V_108 ,
int V_109 ,
T_19 V_110 ,
T_2 V_111 )
{
T_19 V_112 ;
T_7 * V_8 ;
T_11 * V_75 ;
T_12 V_113 ;
T_10 V_114 ;
if ( V_111 == V_115 ) {
V_8 = V_2 -> V_4 ;
V_108 -> V_116 = - 1 ;
V_112 = F_3 ( V_8 , F_57 ( V_8 , F_58 ( V_2 ) ) ) ;
V_112 -= V_108 -> V_117 ;
if ( V_109 && V_108 -> V_117 + V_108 -> V_118 == V_110 ) {
if ( V_112 <= 0 )
return 0 ;
V_108 -> V_118 = V_112 ;
}
} else {
if ( V_111 == V_119 )
V_108 -> V_116 = - 2 ;
else
V_108 -> V_116 = F_1 ( V_2 , V_111 ) ;
V_114 = F_59 ( V_2 -> V_4 , V_108 -> V_117 ) ;
V_75 = F_51 ( V_2 , V_120 ) ;
if ( F_60 ( V_75 , V_114 , & V_113 ) &&
( V_113 == ( V_75 -> V_100 / ( V_101 ) sizeof( T_14 ) ) - 1 ) )
V_108 -> V_121 |= V_122 ;
}
return 1 ;
}
int
F_61 (
T_18 * V_2 ,
struct V_107 * V_123 ,
T_20 V_124 ,
void * V_125 )
{
T_19 V_126 ;
int error = 0 ;
T_19 V_112 ;
int V_127 ;
int V_128 ;
T_21 * V_129 ;
T_7 * V_8 ;
int V_130 ;
int V_131 ;
int V_132 ;
int V_133 ;
struct V_107 * V_108 ;
int V_70 ;
int V_109 ;
int V_134 ;
int V_135 ;
int V_136 = 0 ;
V_8 = V_2 -> V_4 ;
V_134 = V_123 -> V_137 ;
V_70 = V_134 & V_138 ? V_139 : V_120 ;
if ( V_70 == V_139 ) {
if ( F_62 ( V_2 ) ) {
if ( V_2 -> V_61 . V_140 != V_99 &&
V_2 -> V_61 . V_140 != V_141 &&
V_2 -> V_61 . V_140 != V_142 )
return - V_143 ;
} else if ( F_47 (
V_2 -> V_61 . V_140 != 0 &&
V_2 -> V_61 . V_140 != V_99 ) ) {
F_48 ( L_3 , V_97 ,
V_2 -> V_4 ) ;
return - V_33 ;
}
V_109 = 0 ;
V_112 = 1LL << 32 ;
} else {
if ( V_2 -> V_61 . V_144 != V_99 &&
V_2 -> V_61 . V_144 != V_141 &&
V_2 -> V_61 . V_144 != V_142 )
return - V_143 ;
if ( F_22 ( V_2 ) ||
V_2 -> V_61 . V_145 & ( V_146 | V_147 ) ) {
V_109 = 1 ;
V_112 = V_8 -> V_12 -> V_148 ;
} else {
V_109 = 0 ;
V_112 = F_58 ( V_2 ) ;
}
}
if ( V_123 -> V_118 == - 1 ) {
V_112 = F_3 ( V_8 , F_57 ( V_8 , V_112 ) ) ;
V_123 -> V_118 =
F_63 ( T_19 , V_112 - V_123 -> V_117 , 0 ) ;
} else if ( V_123 -> V_118 == 0 ) {
V_123 -> V_149 = 0 ;
return 0 ;
} else if ( V_123 -> V_118 < 0 ) {
return - V_143 ;
}
V_130 = V_123 -> V_150 - 1 ;
if ( V_130 <= 0 )
return - V_143 ;
V_126 = V_123 -> V_117 + V_123 -> V_118 ;
if ( V_123 -> V_150 > V_151 / sizeof( struct V_107 ) )
return - V_152 ;
V_108 = F_64 ( V_123 -> V_150 * sizeof( struct V_107 ) , 0 ) ;
if ( ! V_108 )
return - V_152 ;
F_25 ( V_2 , V_153 ) ;
if ( V_70 == V_120 ) {
if ( ! ( V_134 & V_154 ) &&
( V_2 -> V_64 || F_58 ( V_2 ) > V_2 -> V_61 . V_155 ) ) {
error = F_65 ( F_9 ( V_2 ) -> V_156 ) ;
if ( error )
goto V_157;
}
V_128 = F_66 ( V_2 ) ;
} else {
V_128 = F_67 ( V_2 ) ;
}
if ( V_130 > F_68 ( V_2 , V_70 ) * 2 + 1 )
V_130 = F_68 ( V_2 , V_70 ) * 2 + 1 ;
V_135 = F_69 ( V_70 ) ;
if ( ! ( V_134 & V_158 ) )
V_135 |= V_159 ;
error = - V_152 ;
V_132 = 16 ;
V_129 = F_70 ( V_132 * sizeof( * V_129 ) , V_160 | V_161 ) ;
if ( ! V_129 )
goto V_162;
V_123 -> V_149 = 0 ;
if ( F_68 ( V_2 , V_70 ) == 0 &&
( V_70 == V_139 || ! ( V_134 & V_154 ) ) ) {
error = 0 ;
goto V_163;
}
V_131 = V_130 ;
do {
V_133 = ( V_131 > V_132 ) ? V_132 : V_131 ;
error = F_71 ( V_2 , F_6 ( V_8 , V_123 -> V_117 ) ,
F_59 ( V_8 , V_123 -> V_118 ) ,
V_129 , & V_133 , V_135 ) ;
if ( error )
goto V_163;
ASSERT ( V_133 <= V_132 ) ;
for ( V_127 = 0 ; V_127 < V_133 && V_131 && V_123 -> V_118 ; V_127 ++ ) {
V_108 [ V_136 ] . V_121 = 0 ;
if ( V_129 [ V_127 ] . V_164 == V_165 )
V_108 [ V_136 ] . V_121 |= V_166 ;
else if ( V_129 [ V_127 ] . V_167 == V_119 )
V_108 [ V_136 ] . V_121 |= V_168 ;
V_108 [ V_136 ] . V_117 =
F_3 ( V_8 , V_129 [ V_127 ] . V_73 ) ;
V_108 [ V_136 ] . V_118 =
F_3 ( V_8 , V_129 [ V_127 ] . V_74 ) ;
V_108 [ V_136 ] . V_169 = 0 ;
V_108 [ V_136 ] . V_170 = 0 ;
if ( V_129 [ V_127 ] . V_167 == V_119 &&
V_129 [ V_127 ] . V_73 <= F_57 ( V_8 , F_58 ( V_2 ) ) )
ASSERT ( ( V_134 & V_154 ) != 0 ) ;
if ( V_129 [ V_127 ] . V_167 == V_115 &&
V_70 == V_139 ) {
V_108 [ V_136 ] . V_121 |= V_122 ;
goto V_163;
}
if ( ! F_56 ( V_2 , & V_108 [ V_136 ] ,
V_109 , V_126 ,
V_129 [ V_127 ] . V_167 ) )
goto V_163;
V_123 -> V_117 =
V_108 [ V_136 ] . V_117 +
V_108 [ V_136 ] . V_118 ;
V_123 -> V_118 =
F_63 ( T_19 , 0 , V_126 - V_123 -> V_117 ) ;
if ( ( V_134 & V_171 ) &&
V_129 [ V_127 ] . V_167 == V_115 ) {
memset ( & V_108 [ V_136 ] , 0 , sizeof( V_108 [ V_136 ] ) ) ;
continue;
}
V_131 -- ;
V_123 -> V_149 ++ ;
V_136 ++ ;
}
} while ( V_133 && V_131 && V_123 -> V_118 );
V_163:
F_72 ( V_129 ) ;
V_162:
F_73 ( V_2 , V_128 ) ;
V_157:
F_73 ( V_2 , V_153 ) ;
for ( V_127 = 0 ; V_127 < V_136 ; V_127 ++ ) {
int V_172 = 0 ;
error = V_124 ( & V_125 , & V_108 [ V_127 ] , & V_172 ) ;
if ( error || V_172 )
break;
}
F_72 ( V_108 ) ;
return error ;
}
int
F_74 (
struct V_1 * V_2 ,
T_10 V_5 ,
T_10 V_50 )
{
T_10 V_173 = V_50 ;
int error = 0 ;
ASSERT ( F_75 ( V_2 , V_53 ) ) ;
do {
int V_174 ;
T_21 V_175 ;
int V_176 = 1 ;
T_2 V_177 ;
T_22 V_17 ;
error = F_71 ( V_2 , V_5 , 1 , & V_175 , & V_176 ,
V_178 ) ;
if ( error ) {
if ( ! F_76 ( V_2 -> V_4 ) ) {
F_77 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_179 , V_5 ) ;
}
break;
}
if ( ! V_176 ) {
goto V_180;
}
if ( V_175 . V_167 != V_119 ) {
goto V_180;
}
F_78 ( V_175 . V_74 == 0 ) ;
F_79 ( & V_17 , & V_177 ) ;
error = F_80 ( NULL , V_2 , V_5 , 1 , 0 , 1 , & V_177 ,
& V_17 , & V_174 ) ;
if ( error )
break;
ASSERT ( ! V_17 . V_27 && ! V_17 . V_28 ) ;
V_180:
V_5 ++ ;
V_173 -- ;
} while( V_173 > 0 );
return error ;
}
bool
F_81 ( struct V_1 * V_2 , bool V_181 )
{
if ( ! F_82 ( V_2 -> V_61 . V_182 ) )
return false ;
if ( F_9 ( V_2 ) -> V_183 == 0 &&
F_9 ( V_2 ) -> V_156 -> V_184 == 0 &&
V_2 -> V_64 == 0 )
return false ;
if ( ! ( V_2 -> V_185 . V_186 & V_187 ) )
return false ;
if ( V_2 -> V_61 . V_145 & ( V_146 | V_147 ) )
if ( ! V_181 || V_2 -> V_64 == 0 )
return false ;
return true ;
}
int
F_83 (
T_7 * V_8 ,
T_18 * V_2 ,
bool V_188 )
{
T_15 * V_15 ;
int error ;
T_10 V_189 ;
T_10 V_190 ;
T_23 V_191 ;
int V_176 ;
T_21 V_175 ;
V_189 = F_57 ( V_8 , ( V_192 ) F_58 ( V_2 ) ) ;
V_190 = F_57 ( V_8 , V_8 -> V_12 -> V_148 ) ;
if ( V_190 <= V_189 )
return 0 ;
V_191 = V_190 - V_189 ;
V_176 = 1 ;
F_25 ( V_2 , V_193 ) ;
error = F_71 ( V_2 , V_189 , V_191 , & V_175 , & V_176 , 0 ) ;
F_73 ( V_2 , V_193 ) ;
if ( ! error && ( V_176 != 0 ) &&
( V_175 . V_167 != V_115 ||
V_2 -> V_64 ) ) {
error = F_84 ( V_2 , 0 ) ;
if ( error )
return error ;
V_15 = F_85 ( V_8 , V_194 ) ;
if ( V_188 ) {
if ( ! F_86 ( V_2 , V_195 ) ) {
F_87 ( V_15 ) ;
return - V_196 ;
}
}
error = F_88 ( V_15 , & F_89 ( V_8 ) -> V_197 , 0 , 0 ) ;
if ( error ) {
ASSERT ( F_76 ( V_8 ) ) ;
F_87 ( V_15 ) ;
if ( V_188 )
F_73 ( V_2 , V_195 ) ;
return error ;
}
F_25 ( V_2 , V_53 ) ;
F_26 ( V_15 , V_2 , 0 ) ;
error = F_90 ( & V_15 , V_2 , V_120 ,
F_58 ( V_2 ) ) ;
if ( error ) {
F_87 ( V_15 ) ;
} else {
error = F_91 ( V_15 ) ;
if ( ! error )
F_92 ( V_2 ) ;
}
F_73 ( V_2 , V_53 ) ;
if ( V_188 )
F_73 ( V_2 , V_195 ) ;
}
return error ;
}
int
F_93 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_198 ,
int V_199 )
{
T_7 * V_8 = V_2 -> V_4 ;
T_3 V_78 ;
T_23 V_200 ;
T_23 V_201 ;
T_8 V_202 , V_203 ;
T_10 V_204 ;
T_2 V_205 ;
int V_176 ;
int V_206 ;
int V_207 ;
T_15 * V_15 ;
T_21 V_208 [ 1 ] , * V_209 ;
T_22 V_210 ;
V_101 V_211 , V_212 , V_213 ;
int V_18 ;
int error ;
F_94 ( V_2 ) ;
if ( F_76 ( V_8 ) )
return - V_214 ;
error = F_84 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_198 <= 0 )
return - V_143 ;
V_207 = F_2 ( V_2 ) ;
V_202 = F_22 ( V_2 ) ;
V_78 = V_198 ;
V_209 = & V_208 [ 0 ] ;
V_176 = 1 ;
V_204 = F_95 ( V_8 , V_49 ) ;
V_201 = F_57 ( V_8 , V_78 ) ;
while ( V_201 && ! error ) {
T_10 V_215 , V_216 ;
if ( F_47 ( V_202 ) ) {
V_215 = V_204 ;
F_29 ( V_215 , V_202 ) ;
V_215 *= V_202 ;
V_216 = V_204 + V_201 ;
if ( ( V_203 = F_24 ( V_204 , V_202 ) ) )
V_216 += V_203 ;
if ( ( V_203 = F_24 ( V_216 , V_202 ) ) )
V_216 += V_202 - V_203 ;
} else {
V_215 = 0 ;
V_216 = V_201 ;
}
V_212 = F_96 ( T_10 , ( V_216 - V_215 ) , ( V_51 * V_176 ) ) ;
if ( F_47 ( V_207 ) ) {
V_213 = V_211 = V_212 ;
V_213 /= V_8 -> V_43 . V_44 ;
V_212 = F_97 ( V_8 , 0 ) ;
V_206 = V_217 ;
} else {
V_213 = 0 ;
V_212 = V_211 = F_97 ( V_8 , V_212 ) ;
V_206 = V_218 ;
}
V_15 = F_85 ( V_8 , V_219 ) ;
error = F_88 ( V_15 , & F_89 ( V_8 ) -> V_220 ,
V_212 , V_213 ) ;
if ( error ) {
ASSERT ( error == - V_221 || F_76 ( V_8 ) ) ;
F_87 ( V_15 ) ;
break;
}
F_25 ( V_2 , V_53 ) ;
error = F_98 ( V_15 , V_2 , V_211 ,
0 , V_206 ) ;
if ( error )
goto V_222;
F_26 ( V_15 , V_2 , 0 ) ;
F_79 ( & V_210 , & V_205 ) ;
error = F_99 ( V_15 , V_2 , V_204 ,
V_201 , V_199 , & V_205 ,
V_212 , V_209 , & V_176 , & V_210 ) ;
if ( error ) {
goto V_223;
}
error = F_12 ( & V_15 , & V_210 , & V_18 ) ;
if ( error ) {
goto V_223;
}
error = F_91 ( V_15 ) ;
F_73 ( V_2 , V_53 ) ;
if ( error ) {
break;
}
V_200 = V_209 -> V_74 ;
if ( V_176 == 0 ) {
error = - V_221 ;
break;
}
V_204 += V_200 ;
V_201 -= V_200 ;
}
return error ;
V_223:
F_100 ( & V_210 ) ;
F_101 ( V_15 , V_2 , ( long ) V_211 , 0 , V_206 ) ;
V_222:
F_87 ( V_15 ) ;
F_73 ( V_2 , V_53 ) ;
return error ;
}
STATIC int
F_102 (
T_18 * V_2 ,
T_3 V_224 ,
T_3 V_69 )
{
T_21 V_175 ;
T_10 V_225 ;
T_3 V_226 ;
T_3 V_49 ;
T_16 * V_84 ;
T_7 * V_8 = V_2 -> V_4 ;
int V_227 ;
int error = 0 ;
if ( V_224 >= F_58 ( V_2 ) )
return 0 ;
if ( V_69 > F_58 ( V_2 ) )
V_69 = F_58 ( V_2 ) ;
for ( V_49 = V_224 ; V_49 <= V_69 ; V_49 = V_226 + 1 ) {
V_101 V_228 ;
V_225 = F_95 ( V_8 , V_49 ) ;
V_227 = 1 ;
V_228 = F_66 ( V_2 ) ;
error = F_71 ( V_2 , V_225 , 1 , & V_175 , & V_227 , 0 ) ;
F_73 ( V_2 , V_228 ) ;
if ( error || V_227 < 1 )
break;
ASSERT ( V_175 . V_74 >= 1 ) ;
ASSERT ( V_175 . V_73 == V_225 ) ;
ASSERT ( V_175 . V_167 != V_119 ) ;
if ( V_175 . V_167 == V_115 ||
V_175 . V_164 == V_165 ) {
V_226 = F_7 ( V_8 , V_175 . V_73 +
V_175 . V_74 ) - 1 ;
continue;
}
V_226 = F_7 ( V_8 , V_175 . V_73 + 1 ) - 1 ;
if ( V_226 > V_69 )
V_226 = V_69 ;
if ( F_8 ( F_9 ( V_2 ) ) ) {
error = F_103 ( F_9 ( V_2 ) , V_49 ,
V_226 - V_49 + 1 ,
V_229 ) ;
if ( error )
return error ;
continue;
}
error = F_104 ( F_2 ( V_2 ) ?
V_8 -> V_230 : V_8 -> V_231 ,
F_1 ( V_2 , V_175 . V_167 ) ,
F_105 ( V_8 -> V_43 . V_232 ) ,
0 , & V_84 , NULL ) ;
if ( error )
return error ;
memset ( V_84 -> V_233 +
( V_49 - F_7 ( V_8 , V_175 . V_73 ) ) ,
0 , V_226 - V_49 + 1 ) ;
error = F_106 ( V_84 ) ;
F_107 ( V_84 ) ;
if ( error )
return error ;
}
return error ;
}
int
F_108 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_198 )
{
int V_18 ;
int V_174 ;
T_10 V_234 ;
int error ;
T_2 V_205 ;
T_22 V_210 ;
T_21 V_175 ;
T_3 V_235 ;
T_3 V_236 ;
T_8 V_237 = 0 ;
T_7 * V_8 ;
int V_227 ;
V_101 V_212 ;
T_3 V_238 ;
int V_207 ;
T_10 V_204 ;
T_15 * V_15 ;
V_8 = V_2 -> V_4 ;
F_109 ( V_2 ) ;
error = F_84 ( V_2 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_198 <= 0 )
return error ;
V_207 = F_2 ( V_2 ) ;
V_204 = F_57 ( V_8 , V_49 ) ;
V_234 = F_95 ( V_8 , V_49 + V_198 ) ;
F_110 ( F_9 ( V_2 ) ) ;
V_238 = F_63 ( T_3 , 1 << V_8 -> V_43 . V_239 , V_240 ) ;
V_235 = F_111 ( V_49 , V_238 ) ;
V_236 = F_112 ( V_49 + V_198 , V_238 ) - 1 ;
error = F_113 ( F_9 ( V_2 ) -> V_156 , V_235 ,
V_236 ) ;
if ( error )
goto V_108;
F_114 ( F_9 ( V_2 ) , V_235 , V_236 ) ;
if ( V_207 && ! F_115 ( & V_8 -> V_43 ) ) {
V_227 = 1 ;
error = F_71 ( V_2 , V_204 , 1 ,
& V_175 , & V_227 , 0 ) ;
if ( error )
goto V_108;
ASSERT ( V_227 == 0 || V_227 == 1 ) ;
if ( V_227 && V_175 . V_167 != V_115 ) {
T_1 V_10 ;
ASSERT ( V_175 . V_167 != V_119 ) ;
V_10 = V_175 . V_167 ;
V_237 = F_29 ( V_10 , V_8 -> V_43 . V_44 ) ;
if ( V_237 )
V_204 += V_8 -> V_43 . V_44 - V_237 ;
}
V_227 = 1 ;
error = F_71 ( V_2 , V_234 - 1 , 1 ,
& V_175 , & V_227 , 0 ) ;
if ( error )
goto V_108;
ASSERT ( V_227 == 0 || V_227 == 1 ) ;
if ( V_227 && V_175 . V_167 != V_115 ) {
ASSERT ( V_175 . V_167 != V_119 ) ;
V_237 ++ ;
if ( V_237 && ( V_237 != V_8 -> V_43 . V_44 ) )
V_234 -= V_237 ;
}
}
if ( ( V_174 = ( V_234 <= V_204 ) ) )
error = F_102 ( V_2 , V_49 , V_49 + V_198 - 1 ) ;
else {
if ( V_49 < F_7 ( V_8 , V_204 ) )
error = F_102 ( V_2 , V_49 ,
F_7 ( V_8 , V_204 ) - 1 ) ;
if ( ! error &&
F_7 ( V_8 , V_234 ) < V_49 + V_198 )
error = F_102 ( V_2 ,
F_7 ( V_8 , V_234 ) ,
V_49 + V_198 - 1 ) ;
}
V_212 = F_97 ( V_8 , 0 ) ;
while ( ! error && ! V_174 ) {
V_15 = F_85 ( V_8 , V_219 ) ;
error = F_88 ( V_15 , & F_89 ( V_8 ) -> V_220 , V_212 , 0 ) ;
if ( error ) {
ASSERT ( error == - V_221 || F_76 ( V_8 ) ) ;
F_87 ( V_15 ) ;
break;
}
F_25 ( V_2 , V_53 ) ;
error = F_116 ( V_15 , V_8 ,
V_2 -> V_241 , V_2 -> V_242 , V_2 -> V_243 ,
V_212 , 0 , V_218 ) ;
if ( error )
goto V_222;
F_26 ( V_15 , V_2 , 0 ) ;
F_79 ( & V_210 , & V_205 ) ;
error = F_80 ( V_15 , V_2 , V_204 ,
V_234 - V_204 ,
0 , 2 , & V_205 , & V_210 , & V_174 ) ;
if ( error ) {
goto V_223;
}
error = F_12 ( & V_15 , & V_210 , & V_18 ) ;
if ( error ) {
goto V_223;
}
error = F_91 ( V_15 ) ;
F_73 ( V_2 , V_53 ) ;
}
V_108:
return error ;
V_223:
F_100 ( & V_210 ) ;
V_222:
F_87 ( V_15 ) ;
F_73 ( V_2 , V_53 ) ;
goto V_108;
}
int
F_117 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_198 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
V_101 V_244 ;
int error ;
F_118 ( V_2 ) ;
V_244 = 1 << V_8 -> V_43 . V_239 ;
error = F_108 ( V_2 , V_49 , V_198 ) ;
if ( error )
goto V_108;
error = F_93 ( V_2 , F_111 ( V_49 , V_244 ) ,
F_112 ( V_49 + V_198 , V_244 ) -
F_111 ( V_49 , V_244 ) ,
V_245 ) ;
V_108:
return error ;
}
static int
F_119 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_198 ,
enum V_246 V_247 )
{
int V_174 = 0 ;
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_14 * V_15 ;
int error ;
struct V_16 V_210 ;
T_2 V_248 ;
int V_18 ;
T_10 V_249 ;
T_10 V_250 ;
T_10 V_251 ;
ASSERT ( V_247 == V_252 || V_247 == V_253 ) ;
if ( V_247 == V_252 ) {
V_250 = F_57 ( V_8 , V_49 + V_198 ) ;
V_249 = F_57 ( V_8 , F_9 ( V_2 ) -> V_183 ) ;
} else {
V_250 = V_60 ;
V_249 = F_57 ( V_8 , V_49 ) ;
}
V_251 = F_57 ( V_8 , V_198 ) ;
if ( F_81 ( V_2 , true ) ) {
error = F_83 ( V_8 , V_2 , false ) ;
if ( error )
return error ;
}
error = F_113 ( F_9 ( V_2 ) -> V_156 ,
V_49 , - 1 ) ;
if ( error )
return error ;
error = F_120 ( F_9 ( V_2 ) -> V_156 ,
V_49 >> V_254 , - 1 ) ;
if ( error )
return error ;
if ( V_247 == V_253 ) {
error = F_121 ( V_2 , V_249 ) ;
if ( error )
return error ;
}
while ( ! error && ! V_174 ) {
V_15 = F_85 ( V_8 , V_219 ) ;
error = F_88 ( V_15 , & F_89 ( V_8 ) -> V_220 ,
F_97 ( V_8 , 0 ) , 0 ) ;
if ( error ) {
F_87 ( V_15 ) ;
break;
}
F_25 ( V_2 , V_53 ) ;
error = F_116 ( V_15 , V_8 , V_2 -> V_241 ,
V_2 -> V_242 , V_2 -> V_243 ,
F_97 ( V_8 , 0 ) , 0 ,
V_218 ) ;
if ( error )
goto V_255;
F_26 ( V_15 , V_2 , V_53 ) ;
F_79 ( & V_210 , & V_248 ) ;
error = F_122 ( V_15 , V_2 , & V_250 , V_251 ,
& V_174 , V_249 , & V_248 , & V_210 ,
V_247 , V_256 ) ;
if ( error )
goto V_257;
error = F_12 ( & V_15 , & V_210 , & V_18 ) ;
if ( error )
goto V_257;
error = F_91 ( V_15 ) ;
}
return error ;
V_257:
F_100 ( & V_210 ) ;
V_255:
F_87 ( V_15 ) ;
return error ;
}
int
F_123 (
struct V_1 * V_2 ,
T_3 V_49 ,
T_3 V_198 )
{
int error ;
ASSERT ( F_75 ( V_2 , V_195 ) ) ;
F_124 ( V_2 ) ;
error = F_108 ( V_2 , V_49 , V_198 ) ;
if ( error )
return error ;
return F_119 ( V_2 , V_49 , V_198 , V_252 ) ;
}
int
F_125 (
struct V_1 * V_2 ,
T_24 V_49 ,
T_24 V_198 )
{
ASSERT ( F_75 ( V_2 , V_195 ) ) ;
F_126 ( V_2 ) ;
return F_119 ( V_2 , V_49 , V_198 , V_253 ) ;
}
static int
F_127 (
T_18 * V_2 ,
T_18 * V_258 )
{
if ( V_2 -> V_61 . V_144 == V_142 ||
V_258 -> V_61 . V_144 == V_142 )
return - V_143 ;
if ( V_2 -> V_61 . V_259 < V_258 -> V_61 . V_259 )
return - V_143 ;
if ( V_2 -> V_61 . V_144 == V_99 &&
V_258 -> V_61 . V_144 == V_141 )
return - V_143 ;
if ( V_258 -> V_61 . V_144 == V_99 &&
F_68 ( V_258 , V_120 ) >
F_128 ( V_2 , V_120 ) )
return - V_143 ;
if ( V_2 -> V_61 . V_144 == V_99 &&
F_68 ( V_2 , V_120 ) >
F_128 ( V_258 , V_120 ) )
return - V_143 ;
if ( V_258 -> V_61 . V_144 == V_141 ) {
if ( F_129 ( V_2 ) &&
F_130 ( V_258 -> V_185 . V_102 ) > F_129 ( V_2 ) )
return - V_143 ;
if ( F_68 ( V_258 , V_120 ) <=
F_128 ( V_2 , V_120 ) )
return - V_143 ;
}
if ( V_2 -> V_61 . V_144 == V_141 ) {
if ( F_129 ( V_258 ) &&
F_130 ( V_2 -> V_185 . V_102 ) > F_129 ( V_258 ) )
return - V_143 ;
if ( F_68 ( V_2 , V_120 ) <=
F_128 ( V_258 , V_120 ) )
return - V_143 ;
}
return 0 ;
}
static int
F_131 (
struct V_1 * V_2 )
{
int error ;
error = F_65 ( F_9 ( V_2 ) -> V_156 ) ;
if ( error )
return error ;
F_114 ( F_9 ( V_2 ) , 0 , - 1 ) ;
if ( F_9 ( V_2 ) -> V_156 -> V_184 )
return - V_143 ;
return 0 ;
}
int
F_132 (
T_18 * V_2 ,
T_18 * V_258 ,
T_25 * V_260 )
{
T_7 * V_8 = V_2 -> V_4 ;
T_15 * V_15 ;
T_26 * V_261 = & V_260 -> V_262 ;
T_11 * V_263 , * V_75 , * V_264 ;
int V_265 , V_266 ;
int error = 0 ;
int V_267 = 0 ;
int V_268 = 0 ;
T_27 V_269 ;
int V_270 ;
V_263 = F_70 ( sizeof( T_11 ) , V_160 ) ;
if ( ! V_263 ) {
error = - V_152 ;
goto V_108;
}
V_270 = V_195 | V_271 ;
F_133 ( V_2 , V_258 , V_195 ) ;
F_133 ( V_2 , V_258 , V_271 ) ;
if ( ( V_2 -> V_61 . V_182 & V_272 ) != ( V_258 -> V_61 . V_182 & V_272 ) ) {
error = - V_143 ;
goto V_273;
}
if ( F_2 ( V_2 ) != F_2 ( V_258 ) ) {
error = - V_143 ;
goto V_273;
}
error = F_131 ( V_2 ) ;
if ( error )
goto V_273;
error = F_131 ( V_258 ) ;
if ( error )
goto V_273;
V_15 = F_85 ( V_8 , V_274 ) ;
error = F_88 ( V_15 , & F_89 ( V_8 ) -> V_275 , 0 , 0 ) ;
if ( error ) {
F_87 ( V_15 ) ;
goto V_273;
}
F_133 ( V_2 , V_258 , V_53 ) ;
V_270 |= V_53 ;
F_26 ( V_15 , V_2 , V_270 ) ;
F_26 ( V_15 , V_258 , V_270 ) ;
if ( V_260 -> V_276 != 0 ||
V_260 -> V_277 != V_2 -> V_61 . V_155 ||
V_260 -> V_277 != V_258 -> V_61 . V_155 ) {
error = - V_278 ;
goto V_255;
}
F_134 ( V_2 , 0 ) ;
F_134 ( V_258 , 1 ) ;
error = F_127 ( V_2 , V_258 ) ;
if ( error ) {
F_135 ( V_8 ,
L_5 ,
V_279 , V_2 -> V_179 ) ;
goto V_255;
}
if ( ( V_261 -> V_280 . V_281 != F_9 ( V_2 ) -> V_282 . V_281 ) ||
( V_261 -> V_280 . V_283 != F_9 ( V_2 ) -> V_282 . V_283 ) ||
( V_261 -> V_284 . V_281 != F_9 ( V_2 ) -> V_285 . V_281 ) ||
( V_261 -> V_284 . V_283 != F_9 ( V_2 ) -> V_285 . V_283 ) ) {
error = - V_286 ;
goto V_255;
}
if ( ( ( F_62 ( V_2 ) != 0 ) && ( V_2 -> V_61 . V_287 > 0 ) ) &&
( V_2 -> V_61 . V_140 != V_142 ) ) {
error = F_50 ( V_15 , V_2 , V_139 , & V_267 ) ;
if ( error )
goto V_255;
}
if ( ( ( F_62 ( V_258 ) != 0 ) && ( V_258 -> V_61 . V_287 > 0 ) ) &&
( V_258 -> V_61 . V_140 != V_142 ) ) {
error = F_50 ( V_15 , V_258 , V_139 ,
& V_268 ) ;
if ( error )
goto V_255;
}
V_265 = V_63 ;
V_266 = V_63 ;
if ( V_2 -> V_61 . V_288 == 3 &&
V_2 -> V_61 . V_144 == V_141 ) {
V_266 |= V_289 ;
error = F_136 ( V_15 , V_2 , V_120 ,
V_258 -> V_179 , NULL ) ;
if ( error )
goto V_255;
}
if ( V_258 -> V_61 . V_288 == 3 &&
V_258 -> V_61 . V_144 == V_141 ) {
V_265 |= V_289 ;
error = F_136 ( V_15 , V_258 , V_120 ,
V_2 -> V_179 , NULL ) ;
if ( error )
goto V_255;
}
V_75 = & V_2 -> V_185 ;
V_264 = & V_258 -> V_185 ;
* V_263 = * V_75 ;
* V_75 = * V_264 ;
* V_264 = * V_263 ;
V_269 = ( T_27 ) V_2 -> V_61 . V_62 ;
V_2 -> V_61 . V_62 = V_258 -> V_61 . V_62 - V_268 + V_267 ;
V_258 -> V_61 . V_62 = V_269 + V_268 - V_267 ;
V_269 = ( T_27 ) V_2 -> V_61 . V_259 ;
V_2 -> V_61 . V_259 = V_258 -> V_61 . V_259 ;
V_258 -> V_61 . V_259 = V_269 ;
V_269 = ( T_27 ) V_2 -> V_61 . V_144 ;
V_2 -> V_61 . V_144 = V_258 -> V_61 . V_144 ;
V_258 -> V_61 . V_144 = V_269 ;
ASSERT ( V_258 -> V_64 == 0 ) ;
V_258 -> V_64 = V_2 -> V_64 ;
V_2 -> V_64 = 0 ;
switch ( V_2 -> V_61 . V_144 ) {
case V_99 :
if ( V_2 -> V_61 . V_259 <= V_290 ) {
V_75 -> V_291 . V_292 =
V_75 -> V_293 . V_294 ;
}
V_265 |= V_295 ;
break;
case V_141 :
ASSERT ( V_2 -> V_61 . V_288 < 3 ||
( V_265 & V_289 ) ) ;
V_265 |= V_296 ;
break;
}
switch ( V_258 -> V_61 . V_144 ) {
case V_99 :
if ( V_258 -> V_61 . V_259 <= V_290 ) {
V_264 -> V_291 . V_292 =
V_264 -> V_293 . V_294 ;
}
V_266 |= V_295 ;
break;
case V_141 :
V_266 |= V_296 ;
ASSERT ( V_258 -> V_61 . V_288 < 3 ||
( V_266 & V_289 ) ) ;
break;
}
F_31 ( V_15 , V_2 , V_265 ) ;
F_31 ( V_15 , V_258 , V_266 ) ;
if ( V_8 -> V_297 & V_298 )
F_137 ( V_15 ) ;
error = F_91 ( V_15 ) ;
F_138 ( V_2 , 0 ) ;
F_138 ( V_258 , 1 ) ;
V_108:
F_72 ( V_263 ) ;
return error ;
V_273:
F_73 ( V_2 , V_270 ) ;
F_73 ( V_258 , V_270 ) ;
goto V_108;
V_255:
F_87 ( V_15 ) ;
goto V_108;
}
