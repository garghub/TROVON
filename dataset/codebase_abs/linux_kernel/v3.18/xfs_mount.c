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
return - V_10 ;
}
F_4 ( & V_11 ) ;
for ( V_7 = 0 , V_6 = - 1 ; V_7 < V_12 ; V_7 ++ ) {
if ( F_2 ( & V_13 [ V_7 ] ) ) {
V_6 = V_7 ;
continue;
}
if ( F_5 ( V_3 , & V_13 [ V_7 ] ) )
goto V_14;
}
if ( V_6 < 0 ) {
V_13 = F_6 ( V_13 ,
( V_12 + 1 ) * sizeof( * V_13 ) ,
V_12 * sizeof( * V_13 ) ,
V_15 ) ;
V_6 = V_12 ++ ;
}
V_13 [ V_6 ] = * V_3 ;
F_7 ( & V_11 ) ;
return 0 ;
V_14:
F_7 ( & V_11 ) ;
F_3 ( V_2 , L_2 , V_3 ) ;
return - V_10 ;
}
STATIC void
F_8 (
struct V_1 * V_2 )
{
T_1 * V_3 = & V_2 -> V_4 . V_5 ;
int V_7 ;
if ( V_2 -> V_8 & V_9 )
return;
F_4 ( & V_11 ) ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
if ( F_2 ( & V_13 [ V_7 ] ) )
continue;
if ( ! F_5 ( V_3 , & V_13 [ V_7 ] ) )
continue;
memset ( & V_13 [ V_7 ] , 0 , sizeof( T_1 ) ) ;
break;
}
ASSERT ( V_7 < V_12 ) ;
F_7 ( & V_11 ) ;
}
STATIC void
F_9 (
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_10 ( V_17 , struct V_18 , V_16 ) ;
ASSERT ( F_11 ( & V_19 -> V_20 ) == 0 ) ;
F_12 ( V_19 ) ;
}
STATIC void
F_13 (
T_2 * V_2 )
{
T_3 V_21 ;
struct V_18 * V_19 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_4 . V_22 ; V_21 ++ ) {
F_14 ( & V_2 -> V_23 ) ;
V_19 = F_15 ( & V_2 -> V_24 , V_21 ) ;
F_16 ( & V_2 -> V_23 ) ;
ASSERT ( V_19 ) ;
ASSERT ( F_11 ( & V_19 -> V_20 ) == 0 ) ;
F_17 ( & V_19 -> V_16 , F_9 ) ;
}
}
int
F_18 (
T_4 * V_25 ,
T_5 V_26 )
{
ASSERT ( V_27 >= V_25 -> V_28 ) ;
ASSERT ( V_25 -> V_28 >= V_29 ) ;
if ( V_26 >> ( V_30 - V_25 -> V_28 ) > V_31 )
return - V_32 ;
return 0 ;
}
int
F_19 (
T_2 * V_2 ,
T_3 V_33 ,
T_3 * V_34 )
{
T_3 V_35 ;
T_3 V_36 = 0 ;
T_6 * V_19 ;
T_7 V_37 ;
T_8 V_38 ;
T_4 * V_25 = & V_2 -> V_4 ;
int error = - V_39 ;
for ( V_35 = 0 ; V_35 < V_33 ; V_35 ++ ) {
V_19 = F_20 ( V_2 , V_35 ) ;
if ( V_19 ) {
F_21 ( V_19 ) ;
continue;
}
if ( ! V_36 )
V_36 = V_35 ;
V_19 = F_22 ( sizeof( * V_19 ) , V_40 ) ;
if ( ! V_19 )
goto V_41;
V_19 -> V_42 = V_35 ;
V_19 -> V_43 = V_2 ;
F_23 ( & V_19 -> V_44 ) ;
F_24 ( & V_19 -> V_45 ) ;
F_25 ( & V_19 -> V_46 , V_47 ) ;
F_23 ( & V_19 -> V_48 ) ;
V_19 -> V_49 = V_50 ;
if ( F_26 ( V_51 ) )
goto V_41;
F_14 ( & V_2 -> V_23 ) ;
if ( F_27 ( & V_2 -> V_24 , V_35 , V_19 ) ) {
F_28 () ;
F_16 ( & V_2 -> V_23 ) ;
F_29 () ;
error = - V_52 ;
goto V_41;
}
F_16 ( & V_2 -> V_23 ) ;
F_29 () ;
}
V_37 = F_30 ( V_2 , V_25 -> V_53 - 1 , 0 ) ;
V_38 = F_31 ( V_2 , V_33 - 1 , V_37 ) ;
if ( ( V_2 -> V_8 & V_54 ) && V_38 > V_55 )
V_2 -> V_8 |= V_56 ;
else
V_2 -> V_8 &= ~ V_56 ;
if ( V_2 -> V_8 & V_56 )
V_35 = F_32 ( V_2 , V_33 ) ;
else
V_35 = F_33 ( V_2 , V_33 ) ;
if ( V_34 )
* V_34 = V_35 ;
return 0 ;
V_41:
F_12 ( V_19 ) ;
for (; V_35 > V_36 ; V_35 -- ) {
V_19 = F_15 ( & V_2 -> V_24 , V_35 ) ;
F_12 ( V_19 ) ;
}
return error ;
}
int
F_34 (
struct V_1 * V_2 ,
int V_57 )
{
unsigned int V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_25 = & V_2 -> V_4 ;
int error ;
int V_62 = ! ( V_57 & V_63 ) ;
const struct V_64 * V_65 ;
ASSERT ( V_2 -> V_66 == NULL ) ;
ASSERT ( V_2 -> V_67 != NULL ) ;
V_58 = F_35 ( V_2 -> V_67 ) ;
V_65 = NULL ;
V_68:
error = F_36 ( V_2 -> V_67 , V_69 ,
F_37 ( V_58 ) , 0 , & V_60 , V_65 ) ;
if ( error ) {
if ( V_62 )
F_3 ( V_2 , L_3 , error ) ;
if ( error == - V_70 )
error = - V_71 ;
return error ;
}
F_38 ( V_25 , F_39 ( V_60 ) ) ;
if ( V_25 -> V_72 != V_73 ) {
if ( V_62 )
F_3 ( V_2 , L_4 ) ;
error = - V_10 ;
goto V_74;
}
if ( V_58 > V_25 -> V_75 ) {
if ( V_62 )
F_3 ( V_2 , L_5 ,
V_58 , V_25 -> V_75 ) ;
error = - V_76 ;
goto V_74;
}
if ( V_65 == NULL ) {
F_40 ( V_60 ) ;
V_58 = V_25 -> V_75 ;
V_65 = V_62 ? & V_77 : & V_78 ;
goto V_68;
}
F_41 ( V_2 ) ;
V_60 -> V_79 = & V_77 ;
V_2 -> V_66 = V_60 ;
F_42 ( V_60 ) ;
return 0 ;
V_74:
F_40 ( V_60 ) ;
return error ;
}
STATIC int
F_43 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
if ( V_2 -> V_80 ) {
if ( ( F_44 ( V_2 -> V_80 ) & V_2 -> V_81 ) ||
( F_44 ( V_2 -> V_82 ) & V_2 -> V_81 ) ) {
F_3 ( V_2 ,
L_6 ,
V_25 -> V_83 ) ;
return - V_10 ;
} else {
V_2 -> V_80 = F_45 ( V_2 , V_2 -> V_80 ) ;
if ( V_2 -> V_80 && ( V_25 -> V_53 % V_2 -> V_80 ) ) {
F_3 ( V_2 ,
L_7 ,
V_25 -> V_53 ) ;
return - V_10 ;
} else if ( V_2 -> V_80 ) {
V_2 -> V_82 = F_45 ( V_2 , V_2 -> V_82 ) ;
} else {
F_3 ( V_2 ,
L_8 ,
V_2 -> V_80 , V_25 -> V_83 ) ;
return - V_10 ;
}
}
if ( F_46 ( V_25 ) ) {
if ( V_25 -> V_84 != V_2 -> V_80 ) {
V_25 -> V_84 = V_2 -> V_80 ;
V_2 -> V_85 |= V_86 ;
}
if ( V_25 -> V_87 != V_2 -> V_82 ) {
V_25 -> V_87 = V_2 -> V_82 ;
V_2 -> V_85 |= V_88 ;
}
} else {
F_3 ( V_2 ,
L_9 ) ;
return - V_10 ;
}
} else if ( ( V_2 -> V_8 & V_89 ) != V_89 &&
F_46 ( & V_2 -> V_4 ) ) {
V_2 -> V_80 = V_25 -> V_84 ;
V_2 -> V_82 = V_25 -> V_87 ;
}
return 0 ;
}
STATIC void
F_47 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_5 V_90 ;
if ( V_25 -> V_91 ) {
V_90 = V_25 -> V_92 * V_25 -> V_91 ;
F_48 ( V_90 , 100 ) ;
F_48 ( V_90 , V_2 -> V_93 ) ;
V_2 -> V_94 = ( V_90 * V_2 -> V_93 ) <<
V_25 -> V_95 ;
} else {
V_2 -> V_94 = 0 ;
}
}
STATIC void
F_49 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
int V_96 , V_97 ;
if ( ! ( V_2 -> V_8 & V_98 ) ) {
if ( V_2 -> V_8 & V_99 ) {
V_96 = V_100 ;
V_97 = V_101 ;
} else {
V_96 = V_102 ;
V_97 = V_103 ;
}
} else {
V_96 = V_2 -> V_104 ;
V_97 = V_2 -> V_105 ;
}
if ( V_25 -> V_28 > V_96 ) {
V_2 -> V_104 = V_25 -> V_28 ;
} else {
V_2 -> V_104 = V_96 ;
}
V_2 -> V_106 = 1 << ( V_2 -> V_104 - V_25 -> V_28 ) ;
if ( V_25 -> V_28 > V_97 ) {
V_2 -> V_105 = V_25 -> V_28 ;
} else {
V_2 -> V_105 = V_97 ;
}
V_2 -> V_107 = 1 << ( V_2 -> V_105 - V_25 -> V_28 ) ;
}
void
F_50 (
struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_108 ; V_7 ++ ) {
T_5 V_109 = V_2 -> V_4 . V_92 ;
F_48 ( V_109 , 100 ) ;
V_2 -> V_110 [ V_7 ] = V_109 * ( V_7 + 1 ) ;
}
}
STATIC void
F_51 ( T_2 * V_2 )
{
if ( F_52 ( & V_2 -> V_4 ) &&
V_2 -> V_4 . V_111 >=
F_53 ( V_2 , V_2 -> V_112 ) )
V_2 -> V_113 = V_2 -> V_4 . V_111 - 1 ;
else
V_2 -> V_113 = 0 ;
if ( V_2 -> V_80 && V_2 -> V_113 &&
! ( V_2 -> V_80 & V_2 -> V_113 ) )
V_2 -> V_114 = V_2 -> V_80 ;
else
V_2 -> V_114 = 0 ;
}
STATIC int
F_54 (
struct V_1 * V_2 )
{
struct V_59 * V_60 ;
T_9 V_115 ;
int error ;
V_115 = ( T_9 ) F_55 ( V_2 , V_2 -> V_4 . V_92 ) ;
if ( F_56 ( V_2 , V_115 ) != V_2 -> V_4 . V_92 ) {
F_3 ( V_2 , L_10 ) ;
return - V_32 ;
}
error = F_36 ( V_2 -> V_67 ,
V_115 - F_57 ( V_2 , 1 ) ,
F_57 ( V_2 , 1 ) , 0 , & V_60 , NULL ) ;
if ( error ) {
F_3 ( V_2 , L_11 ) ;
return error ;
}
F_40 ( V_60 ) ;
if ( V_2 -> V_116 == V_2 -> V_67 )
return 0 ;
V_115 = ( T_9 ) F_55 ( V_2 , V_2 -> V_4 . V_117 ) ;
if ( F_56 ( V_2 , V_115 ) != V_2 -> V_4 . V_117 ) {
F_3 ( V_2 , L_12 ) ;
return - V_32 ;
}
error = F_36 ( V_2 -> V_116 ,
V_115 - F_55 ( V_2 , 1 ) ,
F_55 ( V_2 , 1 ) , 0 , & V_60 , NULL ) ;
if ( error ) {
F_3 ( V_2 , L_13 ) ;
return error ;
}
F_40 ( V_60 ) ;
return 0 ;
}
int
F_58 (
struct V_1 * V_2 )
{
int error ;
struct V_118 * V_119 ;
V_2 -> V_120 = 0 ;
if ( V_2 -> V_4 . V_121 == 0 )
return 0 ;
F_14 ( & V_2 -> V_122 ) ;
V_2 -> V_4 . V_121 = 0 ;
F_16 ( & V_2 -> V_122 ) ;
if ( V_2 -> V_8 & V_123 )
return 0 ;
V_119 = F_59 ( V_2 , V_124 ) ;
error = F_60 ( V_119 , & F_61 ( V_2 ) -> V_125 , 0 , 0 ) ;
if ( error ) {
F_62 ( V_119 , 0 ) ;
F_63 ( V_2 , L_14 , V_126 ) ;
return error ;
}
F_64 ( V_119 , V_127 ) ;
return F_65 ( V_119 , 0 ) ;
}
T_5
F_66 ( T_2 * V_2 )
{
T_5 V_128 ;
V_128 = V_2 -> V_4 . V_92 ;
F_48 ( V_128 , 20 ) ;
V_128 = F_67 ( T_5 , V_128 , 8192 ) ;
return V_128 ;
}
int
F_68 (
T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_10 * V_129 ;
T_5 V_128 ;
T_11 V_130 = 0 ;
T_11 V_131 = 0 ;
int error = 0 ;
F_69 ( V_2 , V_25 ) ;
if ( F_70 ( V_25 ) ) {
F_3 ( V_2 , L_15 ) ;
V_25 -> V_132 |= V_25 -> V_133 ;
V_25 -> V_133 = V_25 -> V_132 ;
V_2 -> V_85 |= V_134 | V_135 ;
if ( F_71 ( & V_2 -> V_4 ) &&
! ( V_2 -> V_8 & V_136 ) )
V_2 -> V_8 |= V_137 ;
}
if ( F_71 ( & V_2 -> V_4 ) &&
( V_2 -> V_8 & V_136 ) ) {
F_72 ( & V_2 -> V_4 ) ;
V_2 -> V_85 |= V_134 ;
if ( ! V_25 -> V_132 )
V_2 -> V_85 |= V_138 ;
}
if ( ! ( V_2 -> V_4 . V_139 & V_140 ) ) {
V_2 -> V_4 . V_139 |= V_140 ;
V_2 -> V_85 |= V_138 ;
}
error = F_43 ( V_2 ) ;
if ( error )
goto V_141;
F_73 ( V_2 ) ;
F_74 ( V_2 , V_142 ) ;
F_74 ( V_2 , V_143 ) ;
F_75 ( V_2 ) ;
F_47 ( V_2 ) ;
error = F_76 ( & V_2 -> V_144 , & V_145 , NULL , V_2 -> V_146 ) ;
if ( error )
goto V_141;
error = F_1 ( V_2 ) ;
if ( error )
goto V_147;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
V_2 -> V_112 = V_148 ;
if ( F_77 ( & V_2 -> V_4 ) ) {
int V_149 = V_2 -> V_112 ;
V_149 *= V_2 -> V_4 . V_150 / V_151 ;
if ( V_2 -> V_4 . V_111 >= F_53 ( V_2 , V_149 ) )
V_2 -> V_112 = V_149 ;
}
F_51 ( V_2 ) ;
error = F_54 ( V_2 ) ;
if ( error )
goto V_152;
error = F_78 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_16 ) ;
goto V_152;
}
F_79 ( & V_25 -> V_5 , V_2 -> V_153 ) ;
V_2 -> V_154 = 0 ;
error = F_80 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_17 , error ) ;
goto V_152;
}
F_81 ( V_2 ) ;
F_23 ( & V_2 -> V_23 ) ;
F_25 ( & V_2 -> V_24 , V_47 ) ;
error = F_19 ( V_2 , V_25 -> V_22 , & V_2 -> V_155 ) ;
if ( error ) {
F_3 ( V_2 , L_18 , error ) ;
goto V_156;
}
if ( ! V_25 -> V_117 ) {
F_3 ( V_2 , L_19 ) ;
F_82 ( L_20 , V_157 , V_2 ) ;
error = - V_71 ;
goto V_158;
}
error = F_83 ( V_2 , V_2 -> V_116 ,
F_84 ( V_2 , V_25 -> V_159 ) ,
F_55 ( V_2 , V_25 -> V_117 ) ) ;
if ( error ) {
F_3 ( V_2 , L_21 ) ;
goto V_160;
}
if ( F_85 ( & V_2 -> V_4 ) &&
! F_86 ( V_2 ) &&
! V_2 -> V_4 . V_161 ) {
error = F_87 ( V_2 , V_25 -> V_22 ) ;
if ( error )
goto V_162;
}
error = F_88 ( V_2 , NULL , V_25 -> V_163 , 0 , V_164 , & V_129 ) ;
if ( error ) {
F_3 ( V_2 , L_22 ) ;
goto V_162;
}
ASSERT ( V_129 != NULL ) ;
if ( F_89 ( ! F_90 ( V_129 -> V_165 . V_166 ) ) ) {
F_3 ( V_2 , L_23 ,
( unsigned long long ) V_129 -> V_167 ) ;
F_91 ( V_129 , V_164 ) ;
F_82 ( L_24 , V_157 ,
V_2 ) ;
error = - V_71 ;
goto V_168;
}
V_2 -> V_169 = V_129 ;
F_91 ( V_129 , V_164 ) ;
error = F_92 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_25 ) ;
goto V_168;
}
if ( V_2 -> V_85 && ! ( V_2 -> V_8 & V_123 ) ) {
error = F_93 ( V_2 , V_2 -> V_85 ) ;
if ( error ) {
F_3 ( V_2 , L_26 ) ;
goto V_170;
}
}
if ( F_94 ( V_2 ) ) {
error = F_95 ( V_2 , & V_130 , & V_131 ) ;
if ( error )
goto V_170;
} else {
ASSERT ( ! F_96 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_121 & V_171 ) {
F_97 ( V_2 , L_27 ) ;
error = F_58 ( V_2 ) ;
if ( error )
goto V_170;
}
}
error = F_98 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_28 ) ;
goto V_170;
}
if ( V_130 ) {
ASSERT ( V_2 -> V_120 == 0 ) ;
V_2 -> V_120 = V_131 ;
F_99 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_123 ) ) {
V_128 = F_66 ( V_2 ) ;
error = F_100 ( V_2 , & V_128 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_29 ) ;
}
return 0 ;
V_170:
F_101 ( V_2 ) ;
V_168:
F_102 ( V_129 ) ;
V_162:
F_103 ( V_2 ) ;
V_160:
if ( V_2 -> V_116 && V_2 -> V_116 != V_2 -> V_67 )
F_104 ( V_2 -> V_116 ) ;
F_104 ( V_2 -> V_67 ) ;
V_158:
F_13 ( V_2 ) ;
V_156:
F_105 ( V_2 ) ;
V_152:
F_8 ( V_2 ) ;
V_147:
F_106 ( & V_2 -> V_144 ) ;
V_141:
return error ;
}
void
F_107 (
struct V_1 * V_2 )
{
T_5 V_128 ;
int error ;
F_108 ( & V_2 -> V_172 ) ;
F_109 ( V_2 ) ;
F_101 ( V_2 ) ;
F_102 ( V_2 -> V_169 ) ;
F_110 ( V_2 , V_173 ) ;
F_111 ( V_2 -> V_174 ) ;
F_108 ( & V_2 -> V_175 ) ;
F_112 ( V_2 , V_176 ) ;
F_113 ( V_2 ) ;
V_128 = 0 ;
error = F_100 ( V_2 , & V_128 , NULL ) ;
if ( error )
F_3 ( V_2 , L_30
L_31 ) ;
error = F_114 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_32
L_31 ) ;
F_103 ( V_2 ) ;
F_105 ( V_2 ) ;
F_8 ( V_2 ) ;
#if F_115 ( V_177 )
F_116 ( V_2 , 0 ) ;
#endif
F_13 ( V_2 ) ;
F_106 ( & V_2 -> V_144 ) ;
}
int
F_117 ( T_2 * V_2 )
{
return ! ( V_2 -> V_178 -> V_179 . V_180 || F_118 ( V_2 ) ||
( V_2 -> V_8 & V_123 ) ) ;
}
int
F_114 ( T_2 * V_2 )
{
T_12 * V_119 ;
int error ;
if ( ! F_117 ( V_2 ) )
return 0 ;
F_119 ( V_2 , 0 ) ;
if ( ! F_85 ( & V_2 -> V_4 ) )
return 0 ;
V_119 = F_120 ( V_2 , V_181 , V_15 ) ;
error = F_60 ( V_119 , & F_61 ( V_2 ) -> V_182 , 0 , 0 ) ;
if ( error ) {
F_62 ( V_119 , 0 ) ;
return error ;
}
F_64 ( V_119 , V_183 | V_184 | V_185 ) ;
F_121 ( V_119 ) ;
error = F_65 ( V_119 , 0 ) ;
return error ;
}
STATIC int
F_122 (
T_2 * V_2 ,
T_13 V_186 ,
T_14 V_187 ,
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
return - V_10 ;
}
V_2 -> V_4 . V_194 = V_190 ;
return 0 ;
case V_195 :
V_190 = ( long long ) V_2 -> V_4 . V_196 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
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
return - V_201 ;
V_190 = ( long long ) V_2 -> V_200 + V_187 ;
if ( V_190 >= 0 ) {
V_2 -> V_200 = V_190 ;
return 0 ;
}
F_124 ( V_202
L_33
L_34 ,
V_2 -> V_146 ) ;
return - V_201 ;
}
V_2 -> V_4 . V_198 = V_190 + F_123 ( V_2 ) ;
return 0 ;
case V_203 :
V_190 = ( long long ) V_2 -> V_4 . V_204 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
return - V_201 ;
}
V_2 -> V_4 . V_204 = V_190 ;
return 0 ;
case V_205 :
V_190 = ( long long ) V_2 -> V_4 . V_92 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_92 = V_190 ;
return 0 ;
case V_206 :
V_189 = V_2 -> V_4 . V_22 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_22 = V_189 ;
return 0 ;
case V_207 :
V_189 = V_2 -> V_4 . V_91 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_91 = V_189 ;
return 0 ;
case V_208 :
V_189 = V_2 -> V_4 . V_209 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_209 = V_189 ;
return 0 ;
case V_210 :
V_189 = V_2 -> V_4 . V_211 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_211 = V_189 ;
return 0 ;
case V_212 :
V_190 = ( long long ) V_2 -> V_4 . V_213 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_213 = V_190 ;
return 0 ;
case V_214 :
V_190 = ( long long ) V_2 -> V_4 . V_215 ;
V_190 += V_187 ;
if ( V_190 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_215 = V_190 ;
return 0 ;
case V_216 :
V_189 = V_2 -> V_4 . V_217 ;
V_189 += V_187 ;
if ( V_189 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_217 = V_189 ;
return 0 ;
default:
ASSERT ( 0 ) ;
return - V_10 ;
}
}
int
F_125 (
struct V_1 * V_2 ,
T_13 V_186 ,
T_14 V_187 ,
int V_188 )
{
int V_218 ;
#ifdef F_126
ASSERT ( V_186 < V_193 || V_186 > V_197 ) ;
#endif
F_14 ( & V_2 -> V_122 ) ;
V_218 = F_122 ( V_2 , V_186 , V_187 , V_188 ) ;
F_16 ( & V_2 -> V_122 ) ;
return V_218 ;
}
int
F_127 (
struct V_1 * V_2 ,
T_15 * V_219 ,
T_11 V_220 ,
int V_188 )
{
T_15 * V_221 ;
int error = 0 ;
F_14 ( & V_2 -> V_122 ) ;
for ( V_221 = V_219 ; V_221 < ( V_219 + V_220 ) ; V_221 ++ ) {
ASSERT ( V_221 -> V_222 < V_193 ||
V_221 -> V_222 > V_197 ) ;
error = F_122 ( V_2 , V_221 -> V_222 ,
V_221 -> V_223 , V_188 ) ;
if ( error )
goto V_224;
}
F_16 ( & V_2 -> V_122 ) ;
return 0 ;
V_224:
while ( -- V_221 >= V_219 ) {
error = F_122 ( V_2 , V_221 -> V_222 ,
- V_221 -> V_223 , V_188 ) ;
ASSERT ( error == 0 ) ;
}
F_16 ( & V_2 -> V_122 ) ;
return error ;
}
struct V_59 *
F_128 (
struct V_1 * V_2 ,
int V_57 )
{
struct V_59 * V_60 = V_2 -> V_66 ;
if ( ! F_129 ( V_60 ) ) {
if ( V_57 & V_225 )
return NULL ;
F_130 ( V_60 ) ;
}
F_131 ( V_60 ) ;
ASSERT ( F_132 ( V_60 ) ) ;
return V_60 ;
}
void
F_133 (
struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_66 ;
F_130 ( V_60 ) ;
V_2 -> V_66 = NULL ;
F_40 ( V_60 ) ;
}
int
F_93 (
T_2 * V_2 ,
T_16 V_226 )
{
T_12 * V_119 ;
int error ;
ASSERT ( V_226 & ( V_86 | V_88 | V_227 |
V_134 | V_135 |
V_138 ) ) ;
V_119 = F_59 ( V_2 , V_228 ) ;
error = F_60 ( V_119 , & F_61 ( V_2 ) -> V_182 , 0 , 0 ) ;
if ( error ) {
F_62 ( V_119 , 0 ) ;
return error ;
}
F_64 ( V_119 , V_226 ) ;
error = F_65 ( V_119 , 0 ) ;
return error ;
}
int
F_134 (
struct V_1 * V_2 ,
char * V_229 )
{
if ( F_135 ( V_2 -> V_67 ) ||
F_135 ( V_2 -> V_116 ) ||
( V_2 -> V_230 && F_135 ( V_2 -> V_230 ) ) ) {
F_97 ( V_2 , L_35 , V_229 ) ;
F_97 ( V_2 , L_36 ) ;
return - V_231 ;
}
return 0 ;
}
STATIC int
F_136 (
struct V_232 * V_233 ,
unsigned long V_234 ,
void * V_235 )
{
T_17 * V_236 ;
T_2 * V_2 ;
V_2 = ( T_2 * ) F_10 ( V_233 , T_2 , V_237 ) ;
V_236 = ( T_17 * )
F_137 ( V_2 -> V_238 , ( unsigned long ) V_235 ) ;
switch ( V_234 ) {
case V_239 :
case V_240 :
memset ( V_236 , 0 , sizeof( T_17 ) ) ;
break;
case V_241 :
case V_242 :
F_138 ( V_2 ) ;
F_139 ( V_2 , V_193 , 0 ) ;
F_139 ( V_2 , V_195 , 0 ) ;
F_139 ( V_2 , V_197 , 0 ) ;
F_140 ( V_2 ) ;
break;
case V_243 :
case V_244 :
F_138 ( V_2 ) ;
F_14 ( & V_2 -> V_122 ) ;
F_141 ( V_2 , V_193 ) ;
F_141 ( V_2 , V_195 ) ;
F_141 ( V_2 , V_197 ) ;
V_2 -> V_4 . V_194 += V_236 -> V_245 ;
V_2 -> V_4 . V_196 += V_236 -> V_246 ;
V_2 -> V_4 . V_198 += V_236 -> V_247 ;
memset ( V_236 , 0 , sizeof( T_17 ) ) ;
F_142 ( V_2 , V_193 , 0 ) ;
F_142 ( V_2 , V_195 , 0 ) ;
F_142 ( V_2 , V_197 , 0 ) ;
F_16 ( & V_2 -> V_122 ) ;
F_140 ( V_2 ) ;
break;
}
return V_248 ;
}
int
F_143 (
T_2 * V_2 )
{
T_17 * V_236 ;
int V_7 ;
V_2 -> V_238 = F_144 ( T_17 ) ;
if ( V_2 -> V_238 == NULL )
return - V_39 ;
F_145 (i) {
V_236 = ( T_17 * ) F_137 ( V_2 -> V_238 , V_7 ) ;
memset ( V_236 , 0 , sizeof( T_17 ) ) ;
}
F_24 ( & V_2 -> V_249 ) ;
V_2 -> V_250 = - 1 ;
#ifdef F_146
V_2 -> V_237 . V_251 = F_136 ;
V_2 -> V_237 . V_252 = 0 ;
F_147 ( & V_2 -> V_237 ) ;
#endif
return 0 ;
}
void
F_41 (
T_2 * V_2 )
{
F_138 ( V_2 ) ;
V_2 -> V_250 = - 1 ;
F_139 ( V_2 , V_193 , 0 ) ;
F_139 ( V_2 , V_195 , 0 ) ;
F_139 ( V_2 , V_197 , 0 ) ;
F_140 ( V_2 ) ;
}
void
F_148 (
T_2 * V_2 )
{
if ( V_2 -> V_238 ) {
F_149 ( & V_2 -> V_237 ) ;
F_150 ( V_2 -> V_238 ) ;
}
F_151 ( & V_2 -> V_249 ) ;
}
STATIC void
F_152 (
T_17 * V_253 )
{
while ( F_153 ( V_254 , & V_253 -> V_255 ) ) {
F_154 ( 1000 ) ;
}
}
STATIC void
F_155 (
T_17 * V_253 )
{
F_156 ( V_254 , & V_253 -> V_255 ) ;
}
STATIC void
F_157 (
T_2 * V_2 )
{
T_17 * V_236 ;
int V_7 ;
F_145 (i) {
V_236 = ( T_17 * ) F_137 ( V_2 -> V_238 , V_7 ) ;
F_152 ( V_236 ) ;
}
}
STATIC void
F_158 (
T_2 * V_2 )
{
T_17 * V_236 ;
int V_7 ;
F_145 (i) {
V_236 = ( T_17 * ) F_137 ( V_2 -> V_238 , V_7 ) ;
F_155 ( V_236 ) ;
}
}
STATIC void
F_159 (
T_2 * V_2 ,
T_17 * V_256 ,
int V_57 )
{
T_17 * V_236 ;
int V_7 ;
memset ( V_256 , 0 , sizeof( T_17 ) ) ;
if ( ! ( V_57 & V_257 ) )
F_157 ( V_2 ) ;
F_145 (i) {
V_236 = ( T_17 * ) F_137 ( V_2 -> V_238 , V_7 ) ;
V_256 -> V_245 += V_236 -> V_245 ;
V_256 -> V_246 += V_236 -> V_246 ;
V_256 -> V_247 += V_236 -> V_247 ;
}
if ( ! ( V_57 & V_257 ) )
F_158 ( V_2 ) ;
}
STATIC int
F_160 (
T_2 * V_2 ,
T_13 V_186 )
{
ASSERT ( ( V_186 >= V_193 ) && ( V_186 <= V_197 ) ) ;
return F_161 ( V_186 , & V_2 -> V_250 ) ;
}
STATIC void
F_141 (
T_2 * V_2 ,
T_13 V_186 )
{
T_17 V_256 ;
ASSERT ( ( V_186 >= V_193 ) && ( V_186 <= V_197 ) ) ;
if ( F_160 ( V_2 , V_186 ) )
return;
F_157 ( V_2 ) ;
if ( ! F_153 ( V_186 , & V_2 -> V_250 ) ) {
F_159 ( V_2 , & V_256 , V_257 ) ;
switch( V_186 ) {
case V_193 :
V_2 -> V_4 . V_194 = V_256 . V_245 ;
break;
case V_195 :
V_2 -> V_4 . V_196 = V_256 . V_246 ;
break;
case V_197 :
V_2 -> V_4 . V_198 = V_256 . V_247 ;
break;
default:
F_28 () ;
}
}
F_158 ( V_2 ) ;
}
STATIC void
F_162 (
T_2 * V_2 ,
T_13 V_186 ,
T_18 V_258 ,
T_18 V_259 )
{
T_17 * V_236 ;
int V_7 ;
ASSERT ( ( V_186 >= V_193 ) && ( V_186 <= V_197 ) ) ;
F_157 ( V_2 ) ;
F_145 (i) {
V_236 = F_137 ( V_2 -> V_238 , V_7 ) ;
switch ( V_186 ) {
case V_193 :
V_236 -> V_245 = V_258 + V_259 ;
break;
case V_195 :
V_236 -> V_246 = V_258 + V_259 ;
break;
case V_197 :
V_236 -> V_247 = V_258 + V_259 ;
break;
default:
F_28 () ;
break;
}
V_259 = 0 ;
}
F_156 ( V_186 , & V_2 -> V_250 ) ;
F_158 ( V_2 ) ;
}
void
F_163 (
T_2 * V_2 ,
int V_57 )
{
T_17 V_256 ;
F_159 ( V_2 , & V_256 , V_57 ) ;
if ( ! F_160 ( V_2 , V_193 ) )
V_2 -> V_4 . V_194 = V_256 . V_245 ;
if ( ! F_160 ( V_2 , V_195 ) )
V_2 -> V_4 . V_196 = V_256 . V_246 ;
if ( ! F_160 ( V_2 , V_197 ) )
V_2 -> V_4 . V_198 = V_256 . V_247 ;
}
void
F_119 (
T_2 * V_2 ,
int V_57 )
{
F_14 ( & V_2 -> V_122 ) ;
F_163 ( V_2 , V_57 ) ;
F_16 ( & V_2 -> V_122 ) ;
}
STATIC void
F_142 (
T_2 * V_2 ,
T_13 V_186 ,
int V_260 )
{
T_18 V_258 , V_259 ;
int V_261 = F_164 () ;
T_18 V_262 = ( T_18 ) V_260 ;
F_141 ( V_2 , V_186 ) ;
switch ( V_186 ) {
case V_193 :
V_258 = V_2 -> V_4 . V_194 ;
V_259 = F_48 ( V_258 , V_261 ) ;
if ( V_258 < F_165 ( V_262 , V_263 ) )
return;
break;
case V_195 :
V_258 = V_2 -> V_4 . V_196 ;
V_259 = F_48 ( V_258 , V_261 ) ;
if ( V_258 < F_165 ( V_262 , V_263 ) )
return;
break;
case V_197 :
V_258 = V_2 -> V_4 . V_198 ;
V_259 = F_48 ( V_258 , V_261 ) ;
if ( V_258 < F_165 ( V_262 , F_166 ( V_2 ) ) )
return;
break;
default:
F_28 () ;
V_258 = V_259 = 0 ;
break;
}
F_162 ( V_2 , V_186 , V_258 , V_259 ) ;
}
STATIC void
F_139 (
T_2 * V_2 ,
T_13 V_226 ,
int V_260 )
{
F_14 ( & V_2 -> V_122 ) ;
F_142 ( V_2 , V_226 , V_260 ) ;
F_16 ( & V_2 -> V_122 ) ;
}
int
F_167 (
T_2 * V_2 ,
T_13 V_186 ,
T_14 V_187 ,
int V_188 )
{
T_17 * V_253 ;
long long V_190 ;
int V_264 = 0 ;
F_168 () ;
V_265:
F_169 () ;
V_253 = F_170 ( V_2 -> V_238 ) ;
if ( F_89 ( F_160 ( V_2 , V_186 ) ) )
goto V_266;
F_152 ( V_253 ) ;
if ( F_89 ( F_160 ( V_2 , V_186 ) ) ) {
F_155 ( V_253 ) ;
goto V_266;
}
switch ( V_186 ) {
case V_193 :
V_190 = V_253 -> V_245 ;
V_190 += V_187 ;
if ( F_89 ( V_190 < 0 ) )
goto V_267;
V_253 -> V_245 = V_190 ;
break;
case V_195 :
V_190 = V_253 -> V_246 ;
V_190 += V_187 ;
if ( F_89 ( V_190 < 0 ) )
goto V_267;
V_253 -> V_246 = V_190 ;
break;
case V_197 :
F_171 ( ( V_2 -> V_199 - V_2 -> V_200 ) != 0 ) ;
V_190 = V_253 -> V_247 - F_123 ( V_2 ) ;
V_190 += V_187 ;
if ( F_89 ( V_190 < 0 ) )
goto V_267;
V_253 -> V_247 = V_190 + F_123 ( V_2 ) ;
break;
default:
F_28 () ;
break;
}
F_155 ( V_253 ) ;
F_172 () ;
return 0 ;
V_266:
F_172 () ;
F_138 ( V_2 ) ;
if ( ! ( F_160 ( V_2 , V_186 ) ) ) {
F_140 ( V_2 ) ;
goto V_265;
}
F_14 ( & V_2 -> V_122 ) ;
V_264 = F_122 ( V_2 , V_186 , V_187 , V_188 ) ;
F_16 ( & V_2 -> V_122 ) ;
if ( V_264 != - V_201 )
F_139 ( V_2 , V_186 , 0 ) ;
F_140 ( V_2 ) ;
return V_264 ;
V_267:
F_155 ( V_253 ) ;
F_172 () ;
F_138 ( V_2 ) ;
F_139 ( V_2 , V_186 , V_187 ) ;
F_140 ( V_2 ) ;
goto V_265;
}
