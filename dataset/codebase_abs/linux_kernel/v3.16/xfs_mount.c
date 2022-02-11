STATIC int
F_1 (
struct V_1 * V_2 )
{
T_1 * V_3 = & V_2 -> V_4 . V_5 ;
int V_6 , V_7 ;
if ( V_2 -> V_8 & V_9 )
return 0 ;
if ( F_2 ( V_3 ) ) {
F_3 ( V_2 , L_1 ) ;
return F_4 ( V_10 ) ;
}
F_5 ( & V_11 ) ;
for ( V_7 = 0 , V_6 = - 1 ; V_7 < V_12 ; V_7 ++ ) {
if ( F_2 ( & V_13 [ V_7 ] ) ) {
V_6 = V_7 ;
continue;
}
if ( F_6 ( V_3 , & V_13 [ V_7 ] ) )
goto V_14;
}
if ( V_6 < 0 ) {
V_13 = F_7 ( V_13 ,
( V_12 + 1 ) * sizeof( * V_13 ) ,
V_12 * sizeof( * V_13 ) ,
V_15 ) ;
V_6 = V_12 ++ ;
}
V_13 [ V_6 ] = * V_3 ;
F_8 ( & V_11 ) ;
return 0 ;
V_14:
F_8 ( & V_11 ) ;
F_3 ( V_2 , L_2 , V_3 ) ;
return F_4 ( V_10 ) ;
}
STATIC void
F_9 (
struct V_1 * V_2 )
{
T_1 * V_3 = & V_2 -> V_4 . V_5 ;
int V_7 ;
if ( V_2 -> V_8 & V_9 )
return;
F_5 ( & V_11 ) ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
if ( F_2 ( & V_13 [ V_7 ] ) )
continue;
if ( ! F_6 ( V_3 , & V_13 [ V_7 ] ) )
continue;
memset ( & V_13 [ V_7 ] , 0 , sizeof( T_1 ) ) ;
break;
}
ASSERT ( V_7 < V_12 ) ;
F_8 ( & V_11 ) ;
}
STATIC void
F_10 (
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_11 ( V_17 , struct V_18 , V_16 ) ;
ASSERT ( F_12 ( & V_19 -> V_20 ) == 0 ) ;
F_13 ( V_19 ) ;
}
STATIC void
F_14 (
T_2 * V_2 )
{
T_3 V_21 ;
struct V_18 * V_19 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_4 . V_22 ; V_21 ++ ) {
F_15 ( & V_2 -> V_23 ) ;
V_19 = F_16 ( & V_2 -> V_24 , V_21 ) ;
F_17 ( & V_2 -> V_23 ) ;
ASSERT ( V_19 ) ;
ASSERT ( F_12 ( & V_19 -> V_20 ) == 0 ) ;
F_18 ( & V_19 -> V_16 , F_10 ) ;
}
}
int
F_19 (
T_4 * V_25 ,
T_5 V_26 )
{
ASSERT ( V_27 >= V_25 -> V_28 ) ;
ASSERT ( V_25 -> V_28 >= V_29 ) ;
#if V_30
if ( V_26 >> ( V_31 - V_25 -> V_28 ) > V_32 )
return V_33 ;
#else
if ( V_26 << ( V_25 -> V_28 - V_29 ) > V_34 )
return V_33 ;
#endif
return 0 ;
}
int
F_20 (
T_2 * V_2 ,
T_3 V_35 ,
T_3 * V_36 )
{
T_3 V_37 ;
T_3 V_38 = 0 ;
T_6 * V_19 ;
T_7 V_39 ;
T_8 V_40 ;
T_4 * V_25 = & V_2 -> V_4 ;
int error = - V_41 ;
for ( V_37 = 0 ; V_37 < V_35 ; V_37 ++ ) {
V_19 = F_21 ( V_2 , V_37 ) ;
if ( V_19 ) {
F_22 ( V_19 ) ;
continue;
}
if ( ! V_38 )
V_38 = V_37 ;
V_19 = F_23 ( sizeof( * V_19 ) , V_42 ) ;
if ( ! V_19 )
goto V_43;
V_19 -> V_44 = V_37 ;
V_19 -> V_45 = V_2 ;
F_24 ( & V_19 -> V_46 ) ;
F_25 ( & V_19 -> V_47 ) ;
F_26 ( & V_19 -> V_48 , V_49 ) ;
F_24 ( & V_19 -> V_50 ) ;
V_19 -> V_51 = V_52 ;
if ( F_27 ( V_53 ) )
goto V_43;
F_15 ( & V_2 -> V_23 ) ;
if ( F_28 ( & V_2 -> V_24 , V_37 , V_19 ) ) {
F_29 () ;
F_17 ( & V_2 -> V_23 ) ;
F_30 () ;
error = - V_54 ;
goto V_43;
}
F_17 ( & V_2 -> V_23 ) ;
F_30 () ;
}
V_39 = F_31 ( V_2 , V_25 -> V_55 - 1 , 0 ) ;
V_40 = F_32 ( V_2 , V_35 - 1 , V_39 ) ;
if ( ( V_2 -> V_8 & V_56 ) && V_40 > V_57 )
V_2 -> V_8 |= V_58 ;
else
V_2 -> V_8 &= ~ V_58 ;
if ( V_2 -> V_8 & V_58 )
V_37 = F_33 ( V_2 ) ;
else
V_37 = F_34 ( V_2 ) ;
if ( V_36 )
* V_36 = V_37 ;
return 0 ;
V_43:
F_13 ( V_19 ) ;
for (; V_37 > V_38 ; V_37 -- ) {
V_19 = F_16 ( & V_2 -> V_24 , V_37 ) ;
F_13 ( V_19 ) ;
}
return error ;
}
int
F_35 (
struct V_1 * V_2 ,
int V_59 )
{
unsigned int V_60 ;
struct V_61 * V_62 ;
struct V_63 * V_25 = & V_2 -> V_4 ;
int error ;
int V_64 = ! ( V_59 & V_65 ) ;
const struct V_66 * V_67 ;
ASSERT ( V_2 -> V_68 == NULL ) ;
ASSERT ( V_2 -> V_69 != NULL ) ;
V_60 = F_36 ( V_2 -> V_69 ) ;
V_67 = NULL ;
V_70:
V_62 = F_37 ( V_2 -> V_69 , V_71 ,
F_38 ( V_60 ) , 0 , V_67 ) ;
if ( ! V_62 ) {
if ( V_64 )
F_3 ( V_2 , L_3 ) ;
return V_72 ;
}
if ( V_62 -> V_73 ) {
error = V_62 -> V_73 ;
if ( V_64 )
F_3 ( V_2 , L_4 , error ) ;
if ( error == V_74 )
error = V_75 ;
goto V_76;
}
F_39 ( V_25 , F_40 ( V_62 ) ) ;
F_41 ( V_25 ) ;
if ( V_25 -> V_77 != V_78 ) {
if ( V_64 )
F_3 ( V_2 , L_5 ) ;
error = V_10 ;
goto V_76;
}
if ( V_60 > V_25 -> V_79 ) {
if ( V_64 )
F_3 ( V_2 , L_6 ,
V_60 , V_25 -> V_79 ) ;
error = V_80 ;
goto V_76;
}
if ( V_67 == NULL ) {
F_42 ( V_62 ) ;
V_60 = V_25 -> V_79 ;
V_67 = V_64 ? & V_81 : & V_82 ;
goto V_70;
}
F_43 ( V_2 ) ;
V_62 -> V_83 = & V_81 ;
V_2 -> V_68 = V_62 ;
F_44 ( V_62 ) ;
return 0 ;
V_76:
F_42 ( V_62 ) ;
return error ;
}
STATIC int
F_45 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
if ( V_2 -> V_84 ) {
if ( ( F_46 ( V_2 -> V_84 ) & V_2 -> V_85 ) ||
( F_46 ( V_2 -> V_86 ) & V_2 -> V_85 ) ) {
F_3 ( V_2 ,
L_7 ,
V_25 -> V_87 ) ;
return F_4 ( V_10 ) ;
} else {
V_2 -> V_84 = F_47 ( V_2 , V_2 -> V_84 ) ;
if ( V_2 -> V_84 && ( V_25 -> V_55 % V_2 -> V_84 ) ) {
F_3 ( V_2 ,
L_8 ,
V_25 -> V_55 ) ;
return F_4 ( V_10 ) ;
} else if ( V_2 -> V_84 ) {
V_2 -> V_86 = F_47 ( V_2 , V_2 -> V_86 ) ;
} else {
F_3 ( V_2 ,
L_9 ,
V_2 -> V_84 , V_25 -> V_87 ) ;
return F_4 ( V_10 ) ;
}
}
if ( F_48 ( V_25 ) ) {
if ( V_25 -> V_88 != V_2 -> V_84 ) {
V_25 -> V_88 = V_2 -> V_84 ;
V_2 -> V_89 |= V_90 ;
}
if ( V_25 -> V_91 != V_2 -> V_86 ) {
V_25 -> V_91 = V_2 -> V_86 ;
V_2 -> V_89 |= V_92 ;
}
} else {
F_3 ( V_2 ,
L_10 ) ;
return F_4 ( V_10 ) ;
}
} else if ( ( V_2 -> V_8 & V_93 ) != V_93 &&
F_48 ( & V_2 -> V_4 ) ) {
V_2 -> V_84 = V_25 -> V_88 ;
V_2 -> V_86 = V_25 -> V_91 ;
}
return 0 ;
}
STATIC void
F_49 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_5 V_94 ;
if ( V_25 -> V_95 ) {
V_94 = V_25 -> V_96 * V_25 -> V_95 ;
F_50 ( V_94 , 100 ) ;
F_50 ( V_94 , V_2 -> V_97 ) ;
V_2 -> V_98 = ( V_94 * V_2 -> V_97 ) <<
V_25 -> V_99 ;
} else {
V_2 -> V_98 = 0 ;
}
}
STATIC void
F_51 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
int V_100 , V_101 ;
if ( ! ( V_2 -> V_8 & V_102 ) ) {
if ( V_2 -> V_8 & V_103 ) {
V_100 = V_104 ;
V_101 = V_105 ;
} else {
V_100 = V_106 ;
V_101 = V_107 ;
}
} else {
V_100 = V_2 -> V_108 ;
V_101 = V_2 -> V_109 ;
}
if ( V_25 -> V_28 > V_100 ) {
V_2 -> V_108 = V_25 -> V_28 ;
} else {
V_2 -> V_108 = V_100 ;
}
V_2 -> V_110 = 1 << ( V_2 -> V_108 - V_25 -> V_28 ) ;
if ( V_25 -> V_28 > V_101 ) {
V_2 -> V_109 = V_25 -> V_28 ;
} else {
V_2 -> V_109 = V_101 ;
}
V_2 -> V_111 = 1 << ( V_2 -> V_109 - V_25 -> V_28 ) ;
}
void
F_52 (
struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_112 ; V_7 ++ ) {
T_5 V_113 = V_2 -> V_4 . V_96 ;
F_50 ( V_113 , 100 ) ;
V_2 -> V_114 [ V_7 ] = V_113 * ( V_7 + 1 ) ;
}
}
STATIC void
F_53 ( T_2 * V_2 )
{
if ( F_54 ( & V_2 -> V_4 ) &&
V_2 -> V_4 . V_115 >=
F_55 ( V_2 , V_2 -> V_116 ) )
V_2 -> V_117 = V_2 -> V_4 . V_115 - 1 ;
else
V_2 -> V_117 = 0 ;
if ( V_2 -> V_84 && V_2 -> V_117 &&
! ( V_2 -> V_84 & V_2 -> V_117 ) )
V_2 -> V_118 = V_2 -> V_84 ;
else
V_2 -> V_118 = 0 ;
}
STATIC int
F_56 ( T_2 * V_2 )
{
T_9 * V_62 ;
T_10 V_119 ;
V_119 = ( T_10 ) F_57 ( V_2 , V_2 -> V_4 . V_96 ) ;
if ( F_58 ( V_2 , V_119 ) != V_2 -> V_4 . V_96 ) {
F_3 ( V_2 , L_11 ) ;
return F_4 ( V_33 ) ;
}
V_62 = F_37 ( V_2 -> V_69 ,
V_119 - F_59 ( V_2 , 1 ) ,
F_59 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_62 ) {
F_3 ( V_2 , L_12 ) ;
return V_72 ;
}
F_42 ( V_62 ) ;
if ( V_2 -> V_120 != V_2 -> V_69 ) {
V_119 = ( T_10 ) F_57 ( V_2 , V_2 -> V_4 . V_121 ) ;
if ( F_58 ( V_2 , V_119 ) != V_2 -> V_4 . V_121 ) {
F_3 ( V_2 , L_13 ) ;
return F_4 ( V_33 ) ;
}
V_62 = F_37 ( V_2 -> V_120 ,
V_119 - F_57 ( V_2 , 1 ) ,
F_57 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_62 ) {
F_3 ( V_2 , L_14 ) ;
return V_72 ;
}
F_42 ( V_62 ) ;
}
return 0 ;
}
int
F_60 (
struct V_1 * V_2 )
{
int error ;
struct V_122 * V_123 ;
V_2 -> V_124 = 0 ;
if ( V_2 -> V_4 . V_125 == 0 )
return 0 ;
F_15 ( & V_2 -> V_126 ) ;
V_2 -> V_4 . V_125 = 0 ;
F_17 ( & V_2 -> V_126 ) ;
if ( V_2 -> V_8 & V_127 )
return 0 ;
V_123 = F_61 ( V_2 , V_128 ) ;
error = F_62 ( V_123 , & F_63 ( V_2 ) -> V_129 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_123 , 0 ) ;
F_65 ( V_2 , L_15 , V_130 ) ;
return error ;
}
F_66 ( V_123 , V_131 ) ;
return F_67 ( V_123 , 0 ) ;
}
T_5
F_68 ( T_2 * V_2 )
{
T_5 V_132 ;
V_132 = V_2 -> V_4 . V_96 ;
F_50 ( V_132 , 20 ) ;
V_132 = F_69 ( T_5 , V_132 , 8192 ) ;
return V_132 ;
}
int
F_70 (
T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_11 * V_133 ;
T_5 V_132 ;
T_12 V_134 = 0 ;
T_12 V_135 = 0 ;
int error = 0 ;
F_71 ( V_2 , V_25 ) ;
if ( F_72 ( V_25 ) ) {
F_3 ( V_2 , L_16 ) ;
V_25 -> V_136 |= V_25 -> V_137 ;
V_25 -> V_137 = V_25 -> V_136 ;
V_2 -> V_89 |= V_138 | V_139 ;
if ( F_73 ( & V_2 -> V_4 ) &&
! ( V_2 -> V_8 & V_140 ) )
V_2 -> V_8 |= V_141 ;
}
if ( F_73 ( & V_2 -> V_4 ) &&
( V_2 -> V_8 & V_140 ) ) {
F_74 ( & V_2 -> V_4 ) ;
V_2 -> V_89 |= V_138 ;
if ( ! V_25 -> V_136 )
V_2 -> V_89 |= V_142 ;
}
if ( ! ( V_2 -> V_4 . V_143 & V_144 ) ) {
V_2 -> V_4 . V_143 |= V_144 ;
V_2 -> V_89 |= V_142 ;
}
error = F_45 ( V_2 ) ;
if ( error )
goto V_145;
F_75 ( V_2 ) ;
F_76 ( V_2 , V_146 ) ;
F_76 ( V_2 , V_147 ) ;
F_77 ( V_2 ) ;
F_49 ( V_2 ) ;
error = F_1 ( V_2 ) ;
if ( error )
goto V_145;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_116 = V_148 ;
if ( F_78 ( & V_2 -> V_4 ) ) {
int V_149 = V_2 -> V_116 ;
V_149 *= V_2 -> V_4 . V_150 / V_151 ;
if ( V_2 -> V_4 . V_115 >= F_55 ( V_2 , V_149 ) )
V_2 -> V_116 = V_149 ;
}
F_53 ( V_2 ) ;
error = F_56 ( V_2 ) ;
if ( error )
goto V_152;
error = F_79 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_17 ) ;
goto V_152;
}
F_80 ( & V_25 -> V_5 , V_2 -> V_153 ) ;
V_2 -> V_154 = 0 ;
error = F_81 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_18 , error ) ;
goto V_152;
}
F_82 ( V_2 ) ;
F_24 ( & V_2 -> V_23 ) ;
F_26 ( & V_2 -> V_24 , V_49 ) ;
error = F_20 ( V_2 , V_25 -> V_22 , & V_2 -> V_155 ) ;
if ( error ) {
F_3 ( V_2 , L_19 , error ) ;
goto V_156;
}
if ( ! V_25 -> V_121 ) {
F_3 ( V_2 , L_20 ) ;
F_83 ( L_21 , V_157 , V_2 ) ;
error = F_4 ( V_75 ) ;
goto V_158;
}
error = F_84 ( V_2 , V_2 -> V_120 ,
F_85 ( V_2 , V_25 -> V_159 ) ,
F_57 ( V_2 , V_25 -> V_121 ) ) ;
if ( error ) {
F_3 ( V_2 , L_22 ) ;
goto V_160;
}
if ( F_86 ( & V_2 -> V_4 ) &&
! F_87 ( V_2 ) &&
! V_2 -> V_4 . V_161 ) {
error = F_88 ( V_2 , V_25 -> V_22 ) ;
if ( error )
goto V_160;
}
error = F_89 ( V_2 , NULL , V_25 -> V_162 , 0 , V_163 , & V_133 ) ;
if ( error ) {
F_3 ( V_2 , L_23 ) ;
goto V_164;
}
ASSERT ( V_133 != NULL ) ;
if ( F_90 ( ! F_91 ( V_133 -> V_165 . V_166 ) ) ) {
F_3 ( V_2 , L_24 ,
( unsigned long long ) V_133 -> V_167 ) ;
F_92 ( V_133 , V_163 ) ;
F_83 ( L_25 , V_157 ,
V_2 ) ;
error = F_4 ( V_75 ) ;
goto V_168;
}
V_2 -> V_169 = V_133 ;
F_92 ( V_133 , V_163 ) ;
error = F_93 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_26 ) ;
goto V_168;
}
if ( V_2 -> V_89 && ! ( V_2 -> V_8 & V_127 ) ) {
error = F_94 ( V_2 , V_2 -> V_89 ) ;
if ( error ) {
F_3 ( V_2 , L_27 ) ;
goto V_170;
}
}
if ( F_95 ( V_2 ) ) {
error = F_96 ( V_2 , & V_134 , & V_135 ) ;
if ( error )
goto V_170;
} else {
ASSERT ( ! F_97 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_125 & V_171 ) {
F_98 ( V_2 , L_28 ) ;
error = F_60 ( V_2 ) ;
if ( error )
return error ;
}
}
error = F_99 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_29 ) ;
goto V_170;
}
if ( V_134 ) {
ASSERT ( V_2 -> V_124 == 0 ) ;
V_2 -> V_124 = V_135 ;
F_100 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_127 ) ) {
V_132 = F_68 ( V_2 ) ;
error = F_101 ( V_2 , & V_132 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_30 ) ;
}
return 0 ;
V_170:
F_102 ( V_2 ) ;
V_168:
F_103 ( V_133 ) ;
V_164:
F_104 ( V_2 ) ;
V_160:
if ( V_2 -> V_120 && V_2 -> V_120 != V_2 -> V_69 )
F_105 ( V_2 -> V_120 ) ;
F_105 ( V_2 -> V_69 ) ;
V_158:
F_14 ( V_2 ) ;
V_156:
F_106 ( V_2 ) ;
V_152:
F_9 ( V_2 ) ;
V_145:
return error ;
}
void
F_107 (
struct V_1 * V_2 )
{
T_5 V_132 ;
int error ;
F_108 ( & V_2 -> V_172 ) ;
F_109 ( V_2 ) ;
F_102 ( V_2 ) ;
F_103 ( V_2 -> V_169 ) ;
F_110 ( V_2 , V_173 ) ;
F_111 ( V_2 -> V_174 ) ;
F_108 ( & V_2 -> V_175 ) ;
F_112 ( V_2 , V_176 ) ;
F_113 ( V_2 ) ;
V_132 = 0 ;
error = F_101 ( V_2 , & V_132 , NULL ) ;
if ( error )
F_3 ( V_2 , L_31
L_32 ) ;
error = F_114 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_33
L_32 ) ;
F_104 ( V_2 ) ;
F_106 ( V_2 ) ;
F_9 ( V_2 ) ;
#if F_115 ( V_177 )
F_116 ( V_2 , 0 ) ;
#endif
F_14 ( V_2 ) ;
}
int
F_117 ( T_2 * V_2 )
{
return ! ( V_2 -> V_178 -> V_179 . V_180 || F_118 ( V_2 ) ||
( V_2 -> V_8 & V_127 ) ) ;
}
int
F_114 ( T_2 * V_2 )
{
T_13 * V_123 ;
int error ;
if ( ! F_117 ( V_2 ) )
return 0 ;
F_119 ( V_2 , 0 ) ;
if ( ! F_86 ( & V_2 -> V_4 ) )
return 0 ;
V_123 = F_120 ( V_2 , V_181 , V_15 ) ;
error = F_62 ( V_123 , & F_63 ( V_2 ) -> V_182 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_123 , 0 ) ;
return error ;
}
F_66 ( V_123 , V_183 | V_184 | V_185 ) ;
F_121 ( V_123 ) ;
error = F_67 ( V_123 , 0 ) ;
return error ;
}
STATIC int
F_122 (
T_2 * V_2 ,
T_14 V_186 ,
T_15 V_187 ,
int V_188 )
{
int V_189 ;
long long V_190 ;
long long V_191 , V_192 ;
switch ( V_186 ) {
case V_193 :
V_190 = ( long long ) V_2 -> V_4 . V_194 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_194 = V_190 ;
return 0 ;
case V_195 :
V_190 = ( long long ) V_2 -> V_4 . V_196 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_196 = V_190 ;
return 0 ;
case V_197 :
V_190 = ( long long )
V_2 -> V_4 . V_198 - F_123 ( V_2 ) ;
V_191 = ( long long ) ( V_2 -> V_199 - V_2 -> V_200 ) ;
if ( V_187 > 0 ) {
if ( V_191 > V_187 ) {
V_2 -> V_200 += V_187 ;
} else {
V_192 = V_187 - V_191 ;
V_2 -> V_200 = V_2 -> V_199 ;
V_190 += V_192 ;
}
} else {
V_190 += V_187 ;
if ( V_190 >= 0 ) {
V_2 -> V_4 . V_198 = V_190 +
F_123 ( V_2 ) ;
return 0 ;
}
if ( ! V_188 )
return F_4 ( V_201 ) ;
V_190 = ( long long ) V_2 -> V_200 + V_187 ;
if ( V_190 >= 0 ) {
V_2 -> V_200 = V_190 ;
return 0 ;
}
F_124 ( V_202
L_34
L_35 ,
V_2 -> V_203 ) ;
return F_4 ( V_201 ) ;
}
V_2 -> V_4 . V_198 = V_190 + F_123 ( V_2 ) ;
return 0 ;
case V_204 :
V_190 = ( long long ) V_2 -> V_4 . V_205 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
return F_4 ( V_201 ) ;
}
V_2 -> V_4 . V_205 = V_190 ;
return 0 ;
case V_206 :
V_190 = ( long long ) V_2 -> V_4 . V_96 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_96 = V_190 ;
return 0 ;
case V_207 :
V_189 = V_2 -> V_4 . V_22 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_22 = V_189 ;
return 0 ;
case V_208 :
V_189 = V_2 -> V_4 . V_95 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_95 = V_189 ;
return 0 ;
case V_209 :
V_189 = V_2 -> V_4 . V_210 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_210 = V_189 ;
return 0 ;
case V_211 :
V_189 = V_2 -> V_4 . V_212 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_212 = V_189 ;
return 0 ;
case V_213 :
V_190 = ( long long ) V_2 -> V_4 . V_214 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_214 = V_190 ;
return 0 ;
case V_215 :
V_190 = ( long long ) V_2 -> V_4 . V_216 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_216 = V_190 ;
return 0 ;
case V_217 :
V_189 = V_2 -> V_4 . V_218 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_218 = V_189 ;
return 0 ;
default:
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
}
int
F_125 (
struct V_1 * V_2 ,
T_14 V_186 ,
T_15 V_187 ,
int V_188 )
{
int V_219 ;
#ifdef F_126
ASSERT ( V_186 < V_193 || V_186 > V_197 ) ;
#endif
F_15 ( & V_2 -> V_126 ) ;
V_219 = F_122 ( V_2 , V_186 , V_187 , V_188 ) ;
F_17 ( & V_2 -> V_126 ) ;
return V_219 ;
}
int
F_127 (
struct V_1 * V_2 ,
T_16 * V_220 ,
T_12 V_221 ,
int V_188 )
{
T_16 * V_222 ;
int error = 0 ;
F_15 ( & V_2 -> V_126 ) ;
for ( V_222 = V_220 ; V_222 < ( V_220 + V_221 ) ; V_222 ++ ) {
ASSERT ( V_222 -> V_223 < V_193 ||
V_222 -> V_223 > V_197 ) ;
error = F_122 ( V_2 , V_222 -> V_223 ,
V_222 -> V_224 , V_188 ) ;
if ( error )
goto V_225;
}
F_17 ( & V_2 -> V_126 ) ;
return 0 ;
V_225:
while ( -- V_222 >= V_220 ) {
error = F_122 ( V_2 , V_222 -> V_223 ,
- V_222 -> V_224 , V_188 ) ;
ASSERT ( error == 0 ) ;
}
F_17 ( & V_2 -> V_126 ) ;
return error ;
}
struct V_61 *
F_128 (
struct V_1 * V_2 ,
int V_59 )
{
struct V_61 * V_62 = V_2 -> V_68 ;
if ( ! F_129 ( V_62 ) ) {
if ( V_59 & V_226 )
return NULL ;
F_130 ( V_62 ) ;
}
F_131 ( V_62 ) ;
ASSERT ( F_132 ( V_62 ) ) ;
return V_62 ;
}
void
F_133 (
struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_68 ;
F_130 ( V_62 ) ;
V_2 -> V_68 = NULL ;
F_42 ( V_62 ) ;
}
int
F_94 (
T_2 * V_2 ,
T_17 V_227 )
{
T_13 * V_123 ;
int error ;
ASSERT ( V_227 & ( V_90 | V_92 | V_228 |
V_138 | V_139 |
V_142 ) ) ;
V_123 = F_61 ( V_2 , V_229 ) ;
error = F_62 ( V_123 , & F_63 ( V_2 ) -> V_182 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_123 , 0 ) ;
return error ;
}
F_66 ( V_123 , V_227 ) ;
error = F_67 ( V_123 , 0 ) ;
return error ;
}
int
F_134 (
struct V_1 * V_2 ,
char * V_230 )
{
if ( F_135 ( V_2 -> V_69 ) ||
F_135 ( V_2 -> V_120 ) ||
( V_2 -> V_231 && F_135 ( V_2 -> V_231 ) ) ) {
F_98 ( V_2 , L_36 , V_230 ) ;
F_98 ( V_2 , L_37 ) ;
return V_232 ;
}
return 0 ;
}
STATIC int
F_136 (
struct V_233 * V_234 ,
unsigned long V_235 ,
void * V_236 )
{
T_18 * V_237 ;
T_2 * V_2 ;
V_2 = ( T_2 * ) F_11 ( V_234 , T_2 , V_238 ) ;
V_237 = ( T_18 * )
F_137 ( V_2 -> V_239 , ( unsigned long ) V_236 ) ;
switch ( V_235 ) {
case V_240 :
case V_241 :
memset ( V_237 , 0 , sizeof( T_18 ) ) ;
break;
case V_242 :
case V_243 :
F_138 ( V_2 ) ;
F_139 ( V_2 , V_193 , 0 ) ;
F_139 ( V_2 , V_195 , 0 ) ;
F_139 ( V_2 , V_197 , 0 ) ;
F_140 ( V_2 ) ;
break;
case V_244 :
case V_245 :
F_138 ( V_2 ) ;
F_15 ( & V_2 -> V_126 ) ;
F_141 ( V_2 , V_193 ) ;
F_141 ( V_2 , V_195 ) ;
F_141 ( V_2 , V_197 ) ;
V_2 -> V_4 . V_194 += V_237 -> V_246 ;
V_2 -> V_4 . V_196 += V_237 -> V_247 ;
V_2 -> V_4 . V_198 += V_237 -> V_248 ;
memset ( V_237 , 0 , sizeof( T_18 ) ) ;
F_142 ( V_2 , V_193 , 0 ) ;
F_142 ( V_2 , V_195 , 0 ) ;
F_142 ( V_2 , V_197 , 0 ) ;
F_17 ( & V_2 -> V_126 ) ;
F_140 ( V_2 ) ;
break;
}
return V_249 ;
}
int
F_143 (
T_2 * V_2 )
{
T_18 * V_237 ;
int V_7 ;
V_2 -> V_239 = F_144 ( T_18 ) ;
if ( V_2 -> V_239 == NULL )
return - V_41 ;
F_145 (i) {
V_237 = ( T_18 * ) F_137 ( V_2 -> V_239 , V_7 ) ;
memset ( V_237 , 0 , sizeof( T_18 ) ) ;
}
F_25 ( & V_2 -> V_250 ) ;
V_2 -> V_251 = - 1 ;
#ifdef F_146
V_2 -> V_238 . V_252 = F_136 ;
V_2 -> V_238 . V_253 = 0 ;
F_147 ( & V_2 -> V_238 ) ;
#endif
return 0 ;
}
void
F_43 (
T_2 * V_2 )
{
F_138 ( V_2 ) ;
V_2 -> V_251 = - 1 ;
F_139 ( V_2 , V_193 , 0 ) ;
F_139 ( V_2 , V_195 , 0 ) ;
F_139 ( V_2 , V_197 , 0 ) ;
F_140 ( V_2 ) ;
}
void
F_148 (
T_2 * V_2 )
{
if ( V_2 -> V_239 ) {
F_149 ( & V_2 -> V_238 ) ;
F_150 ( V_2 -> V_239 ) ;
}
F_151 ( & V_2 -> V_250 ) ;
}
STATIC void
F_152 (
T_18 * V_254 )
{
while ( F_153 ( V_255 , & V_254 -> V_256 ) ) {
F_154 ( 1000 ) ;
}
}
STATIC void
F_155 (
T_18 * V_254 )
{
F_156 ( V_255 , & V_254 -> V_256 ) ;
}
STATIC void
F_157 (
T_2 * V_2 )
{
T_18 * V_237 ;
int V_7 ;
F_145 (i) {
V_237 = ( T_18 * ) F_137 ( V_2 -> V_239 , V_7 ) ;
F_152 ( V_237 ) ;
}
}
STATIC void
F_158 (
T_2 * V_2 )
{
T_18 * V_237 ;
int V_7 ;
F_145 (i) {
V_237 = ( T_18 * ) F_137 ( V_2 -> V_239 , V_7 ) ;
F_155 ( V_237 ) ;
}
}
STATIC void
F_159 (
T_2 * V_2 ,
T_18 * V_257 ,
int V_59 )
{
T_18 * V_237 ;
int V_7 ;
memset ( V_257 , 0 , sizeof( T_18 ) ) ;
if ( ! ( V_59 & V_258 ) )
F_157 ( V_2 ) ;
F_145 (i) {
V_237 = ( T_18 * ) F_137 ( V_2 -> V_239 , V_7 ) ;
V_257 -> V_246 += V_237 -> V_246 ;
V_257 -> V_247 += V_237 -> V_247 ;
V_257 -> V_248 += V_237 -> V_248 ;
}
if ( ! ( V_59 & V_258 ) )
F_158 ( V_2 ) ;
}
STATIC int
F_160 (
T_2 * V_2 ,
T_14 V_186 )
{
ASSERT ( ( V_186 >= V_193 ) && ( V_186 <= V_197 ) ) ;
return F_161 ( V_186 , & V_2 -> V_251 ) ;
}
STATIC void
F_141 (
T_2 * V_2 ,
T_14 V_186 )
{
T_18 V_257 ;
ASSERT ( ( V_186 >= V_193 ) && ( V_186 <= V_197 ) ) ;
if ( F_160 ( V_2 , V_186 ) )
return;
F_157 ( V_2 ) ;
if ( ! F_153 ( V_186 , & V_2 -> V_251 ) ) {
F_159 ( V_2 , & V_257 , V_258 ) ;
switch( V_186 ) {
case V_193 :
V_2 -> V_4 . V_194 = V_257 . V_246 ;
break;
case V_195 :
V_2 -> V_4 . V_196 = V_257 . V_247 ;
break;
case V_197 :
V_2 -> V_4 . V_198 = V_257 . V_248 ;
break;
default:
F_29 () ;
}
}
F_158 ( V_2 ) ;
}
STATIC void
F_162 (
T_2 * V_2 ,
T_14 V_186 ,
T_19 V_259 ,
T_19 V_260 )
{
T_18 * V_237 ;
int V_7 ;
ASSERT ( ( V_186 >= V_193 ) && ( V_186 <= V_197 ) ) ;
F_157 ( V_2 ) ;
F_145 (i) {
V_237 = F_137 ( V_2 -> V_239 , V_7 ) ;
switch ( V_186 ) {
case V_193 :
V_237 -> V_246 = V_259 + V_260 ;
break;
case V_195 :
V_237 -> V_247 = V_259 + V_260 ;
break;
case V_197 :
V_237 -> V_248 = V_259 + V_260 ;
break;
default:
F_29 () ;
break;
}
V_260 = 0 ;
}
F_156 ( V_186 , & V_2 -> V_251 ) ;
F_158 ( V_2 ) ;
}
void
F_163 (
T_2 * V_2 ,
int V_59 )
{
T_18 V_257 ;
F_159 ( V_2 , & V_257 , V_59 ) ;
if ( ! F_160 ( V_2 , V_193 ) )
V_2 -> V_4 . V_194 = V_257 . V_246 ;
if ( ! F_160 ( V_2 , V_195 ) )
V_2 -> V_4 . V_196 = V_257 . V_247 ;
if ( ! F_160 ( V_2 , V_197 ) )
V_2 -> V_4 . V_198 = V_257 . V_248 ;
}
void
F_119 (
T_2 * V_2 ,
int V_59 )
{
F_15 ( & V_2 -> V_126 ) ;
F_163 ( V_2 , V_59 ) ;
F_17 ( & V_2 -> V_126 ) ;
}
STATIC void
F_142 (
T_2 * V_2 ,
T_14 V_186 ,
int V_261 )
{
T_19 V_259 , V_260 ;
int V_262 = F_164 () ;
T_19 V_263 = ( T_19 ) V_261 ;
F_141 ( V_2 , V_186 ) ;
switch ( V_186 ) {
case V_193 :
V_259 = V_2 -> V_4 . V_194 ;
V_260 = F_50 ( V_259 , V_262 ) ;
if ( V_259 < F_165 ( V_263 , V_264 ) )
return;
break;
case V_195 :
V_259 = V_2 -> V_4 . V_196 ;
V_260 = F_50 ( V_259 , V_262 ) ;
if ( V_259 < F_165 ( V_263 , V_264 ) )
return;
break;
case V_197 :
V_259 = V_2 -> V_4 . V_198 ;
V_260 = F_50 ( V_259 , V_262 ) ;
if ( V_259 < F_165 ( V_263 , F_166 ( V_2 ) ) )
return;
break;
default:
F_29 () ;
V_259 = V_260 = 0 ;
break;
}
F_162 ( V_2 , V_186 , V_259 , V_260 ) ;
}
STATIC void
F_139 (
T_2 * V_2 ,
T_14 V_227 ,
int V_261 )
{
F_15 ( & V_2 -> V_126 ) ;
F_142 ( V_2 , V_227 , V_261 ) ;
F_17 ( & V_2 -> V_126 ) ;
}
int
F_167 (
T_2 * V_2 ,
T_14 V_186 ,
T_15 V_187 ,
int V_188 )
{
T_18 * V_254 ;
long long V_190 ;
int V_265 = 0 ;
F_168 () ;
V_266:
F_169 () ;
V_254 = F_170 ( V_2 -> V_239 ) ;
if ( F_90 ( F_160 ( V_2 , V_186 ) ) )
goto V_267;
F_152 ( V_254 ) ;
if ( F_90 ( F_160 ( V_2 , V_186 ) ) ) {
F_155 ( V_254 ) ;
goto V_267;
}
switch ( V_186 ) {
case V_193 :
V_190 = V_254 -> V_246 ;
V_190 += V_187 ;
if ( F_90 ( V_190 < 0 ) )
goto V_268;
V_254 -> V_246 = V_190 ;
break;
case V_195 :
V_190 = V_254 -> V_247 ;
V_190 += V_187 ;
if ( F_90 ( V_190 < 0 ) )
goto V_268;
V_254 -> V_247 = V_190 ;
break;
case V_197 :
F_171 ( ( V_2 -> V_199 - V_2 -> V_200 ) != 0 ) ;
V_190 = V_254 -> V_248 - F_123 ( V_2 ) ;
V_190 += V_187 ;
if ( F_90 ( V_190 < 0 ) )
goto V_268;
V_254 -> V_248 = V_190 + F_123 ( V_2 ) ;
break;
default:
F_29 () ;
break;
}
F_155 ( V_254 ) ;
F_172 () ;
return 0 ;
V_267:
F_172 () ;
F_138 ( V_2 ) ;
if ( ! ( F_160 ( V_2 , V_186 ) ) ) {
F_140 ( V_2 ) ;
goto V_266;
}
F_15 ( & V_2 -> V_126 ) ;
V_265 = F_122 ( V_2 , V_186 , V_187 , V_188 ) ;
F_17 ( & V_2 -> V_126 ) ;
if ( V_265 != V_201 )
F_139 ( V_2 , V_186 , 0 ) ;
F_140 ( V_2 ) ;
return V_265 ;
V_268:
F_155 ( V_254 ) ;
F_172 () ;
F_138 ( V_2 ) ;
F_139 ( V_2 , V_186 , V_187 ) ;
F_140 ( V_2 ) ;
goto V_266;
}
