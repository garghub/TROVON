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
V_60 = F_36 ( V_2 -> V_67 , V_69 ,
F_37 ( V_58 ) , 0 , V_65 ) ;
if ( ! V_60 ) {
if ( V_62 )
F_3 ( V_2 , L_3 ) ;
return - V_70 ;
}
if ( V_60 -> V_71 ) {
error = V_60 -> V_71 ;
if ( V_62 )
F_3 ( V_2 , L_4 , error ) ;
if ( error == - V_72 )
error = - V_73 ;
goto V_74;
}
F_38 ( V_25 , F_39 ( V_60 ) ) ;
if ( V_25 -> V_75 != V_76 ) {
if ( V_62 )
F_3 ( V_2 , L_5 ) ;
error = - V_10 ;
goto V_74;
}
if ( V_58 > V_25 -> V_77 ) {
if ( V_62 )
F_3 ( V_2 , L_6 ,
V_58 , V_25 -> V_77 ) ;
error = - V_78 ;
goto V_74;
}
if ( V_65 == NULL ) {
F_40 ( V_60 ) ;
V_58 = V_25 -> V_77 ;
V_65 = V_62 ? & V_79 : & V_80 ;
goto V_68;
}
F_41 ( V_2 ) ;
V_60 -> V_81 = & V_79 ;
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
if ( V_2 -> V_82 ) {
if ( ( F_44 ( V_2 -> V_82 ) & V_2 -> V_83 ) ||
( F_44 ( V_2 -> V_84 ) & V_2 -> V_83 ) ) {
F_3 ( V_2 ,
L_7 ,
V_25 -> V_85 ) ;
return - V_10 ;
} else {
V_2 -> V_82 = F_45 ( V_2 , V_2 -> V_82 ) ;
if ( V_2 -> V_82 && ( V_25 -> V_53 % V_2 -> V_82 ) ) {
F_3 ( V_2 ,
L_8 ,
V_25 -> V_53 ) ;
return - V_10 ;
} else if ( V_2 -> V_82 ) {
V_2 -> V_84 = F_45 ( V_2 , V_2 -> V_84 ) ;
} else {
F_3 ( V_2 ,
L_9 ,
V_2 -> V_82 , V_25 -> V_85 ) ;
return - V_10 ;
}
}
if ( F_46 ( V_25 ) ) {
if ( V_25 -> V_86 != V_2 -> V_82 ) {
V_25 -> V_86 = V_2 -> V_82 ;
V_2 -> V_87 |= V_88 ;
}
if ( V_25 -> V_89 != V_2 -> V_84 ) {
V_25 -> V_89 = V_2 -> V_84 ;
V_2 -> V_87 |= V_90 ;
}
} else {
F_3 ( V_2 ,
L_10 ) ;
return - V_10 ;
}
} else if ( ( V_2 -> V_8 & V_91 ) != V_91 &&
F_46 ( & V_2 -> V_4 ) ) {
V_2 -> V_82 = V_25 -> V_86 ;
V_2 -> V_84 = V_25 -> V_89 ;
}
return 0 ;
}
STATIC void
F_47 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_5 V_92 ;
if ( V_25 -> V_93 ) {
V_92 = V_25 -> V_94 * V_25 -> V_93 ;
F_48 ( V_92 , 100 ) ;
F_48 ( V_92 , V_2 -> V_95 ) ;
V_2 -> V_96 = ( V_92 * V_2 -> V_95 ) <<
V_25 -> V_97 ;
} else {
V_2 -> V_96 = 0 ;
}
}
STATIC void
F_49 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
int V_98 , V_99 ;
if ( ! ( V_2 -> V_8 & V_100 ) ) {
if ( V_2 -> V_8 & V_101 ) {
V_98 = V_102 ;
V_99 = V_103 ;
} else {
V_98 = V_104 ;
V_99 = V_105 ;
}
} else {
V_98 = V_2 -> V_106 ;
V_99 = V_2 -> V_107 ;
}
if ( V_25 -> V_28 > V_98 ) {
V_2 -> V_106 = V_25 -> V_28 ;
} else {
V_2 -> V_106 = V_98 ;
}
V_2 -> V_108 = 1 << ( V_2 -> V_106 - V_25 -> V_28 ) ;
if ( V_25 -> V_28 > V_99 ) {
V_2 -> V_107 = V_25 -> V_28 ;
} else {
V_2 -> V_107 = V_99 ;
}
V_2 -> V_109 = 1 << ( V_2 -> V_107 - V_25 -> V_28 ) ;
}
void
F_50 (
struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_110 ; V_7 ++ ) {
T_5 V_111 = V_2 -> V_4 . V_94 ;
F_48 ( V_111 , 100 ) ;
V_2 -> V_112 [ V_7 ] = V_111 * ( V_7 + 1 ) ;
}
}
STATIC void
F_51 ( T_2 * V_2 )
{
if ( F_52 ( & V_2 -> V_4 ) &&
V_2 -> V_4 . V_113 >=
F_53 ( V_2 , V_2 -> V_114 ) )
V_2 -> V_115 = V_2 -> V_4 . V_113 - 1 ;
else
V_2 -> V_115 = 0 ;
if ( V_2 -> V_82 && V_2 -> V_115 &&
! ( V_2 -> V_82 & V_2 -> V_115 ) )
V_2 -> V_116 = V_2 -> V_82 ;
else
V_2 -> V_116 = 0 ;
}
STATIC int
F_54 ( T_2 * V_2 )
{
T_9 * V_60 ;
T_10 V_117 ;
V_117 = ( T_10 ) F_55 ( V_2 , V_2 -> V_4 . V_94 ) ;
if ( F_56 ( V_2 , V_117 ) != V_2 -> V_4 . V_94 ) {
F_3 ( V_2 , L_11 ) ;
return - V_32 ;
}
V_60 = F_36 ( V_2 -> V_67 ,
V_117 - F_57 ( V_2 , 1 ) ,
F_57 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_60 ) {
F_3 ( V_2 , L_12 ) ;
return - V_70 ;
}
F_40 ( V_60 ) ;
if ( V_2 -> V_118 != V_2 -> V_67 ) {
V_117 = ( T_10 ) F_55 ( V_2 , V_2 -> V_4 . V_119 ) ;
if ( F_56 ( V_2 , V_117 ) != V_2 -> V_4 . V_119 ) {
F_3 ( V_2 , L_13 ) ;
return - V_32 ;
}
V_60 = F_36 ( V_2 -> V_118 ,
V_117 - F_55 ( V_2 , 1 ) ,
F_55 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_60 ) {
F_3 ( V_2 , L_14 ) ;
return - V_70 ;
}
F_40 ( V_60 ) ;
}
return 0 ;
}
int
F_58 (
struct V_1 * V_2 )
{
int error ;
struct V_120 * V_121 ;
V_2 -> V_122 = 0 ;
if ( V_2 -> V_4 . V_123 == 0 )
return 0 ;
F_14 ( & V_2 -> V_124 ) ;
V_2 -> V_4 . V_123 = 0 ;
F_16 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_8 & V_125 )
return 0 ;
V_121 = F_59 ( V_2 , V_126 ) ;
error = F_60 ( V_121 , & F_61 ( V_2 ) -> V_127 , 0 , 0 ) ;
if ( error ) {
F_62 ( V_121 , 0 ) ;
F_63 ( V_2 , L_15 , V_128 ) ;
return error ;
}
F_64 ( V_121 , V_129 ) ;
return F_65 ( V_121 , 0 ) ;
}
T_5
F_66 ( T_2 * V_2 )
{
T_5 V_130 ;
V_130 = V_2 -> V_4 . V_94 ;
F_48 ( V_130 , 20 ) ;
V_130 = F_67 ( T_5 , V_130 , 8192 ) ;
return V_130 ;
}
int
F_68 (
T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_11 * V_131 ;
T_5 V_130 ;
T_12 V_132 = 0 ;
T_12 V_133 = 0 ;
int error = 0 ;
F_69 ( V_2 , V_25 ) ;
if ( F_70 ( V_25 ) ) {
F_3 ( V_2 , L_16 ) ;
V_25 -> V_134 |= V_25 -> V_135 ;
V_25 -> V_135 = V_25 -> V_134 ;
V_2 -> V_87 |= V_136 | V_137 ;
if ( F_71 ( & V_2 -> V_4 ) &&
! ( V_2 -> V_8 & V_138 ) )
V_2 -> V_8 |= V_139 ;
}
if ( F_71 ( & V_2 -> V_4 ) &&
( V_2 -> V_8 & V_138 ) ) {
F_72 ( & V_2 -> V_4 ) ;
V_2 -> V_87 |= V_136 ;
if ( ! V_25 -> V_134 )
V_2 -> V_87 |= V_140 ;
}
if ( ! ( V_2 -> V_4 . V_141 & V_142 ) ) {
V_2 -> V_4 . V_141 |= V_142 ;
V_2 -> V_87 |= V_140 ;
}
error = F_43 ( V_2 ) ;
if ( error )
goto V_143;
F_73 ( V_2 ) ;
F_74 ( V_2 , V_144 ) ;
F_74 ( V_2 , V_145 ) ;
F_75 ( V_2 ) ;
F_47 ( V_2 ) ;
V_2 -> V_146 . V_147 . V_148 = V_149 ;
error = F_76 ( & V_2 -> V_146 , & V_150 , NULL , V_2 -> V_151 ) ;
if ( error )
goto V_143;
error = F_1 ( V_2 ) ;
if ( error )
goto V_152;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
V_2 -> V_114 = V_153 ;
if ( F_77 ( & V_2 -> V_4 ) ) {
int V_154 = V_2 -> V_114 ;
V_154 *= V_2 -> V_4 . V_155 / V_156 ;
if ( V_2 -> V_4 . V_113 >= F_53 ( V_2 , V_154 ) )
V_2 -> V_114 = V_154 ;
}
F_51 ( V_2 ) ;
error = F_54 ( V_2 ) ;
if ( error )
goto V_157;
error = F_78 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_17 ) ;
goto V_157;
}
F_79 ( & V_25 -> V_5 , V_2 -> V_158 ) ;
V_2 -> V_159 = 0 ;
error = F_80 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_18 , error ) ;
goto V_157;
}
F_81 ( V_2 ) ;
F_23 ( & V_2 -> V_23 ) ;
F_25 ( & V_2 -> V_24 , V_47 ) ;
error = F_19 ( V_2 , V_25 -> V_22 , & V_2 -> V_160 ) ;
if ( error ) {
F_3 ( V_2 , L_19 , error ) ;
goto V_161;
}
if ( ! V_25 -> V_119 ) {
F_3 ( V_2 , L_20 ) ;
F_82 ( L_21 , V_162 , V_2 ) ;
error = - V_73 ;
goto V_163;
}
error = F_83 ( V_2 , V_2 -> V_118 ,
F_84 ( V_2 , V_25 -> V_164 ) ,
F_55 ( V_2 , V_25 -> V_119 ) ) ;
if ( error ) {
F_3 ( V_2 , L_22 ) ;
goto V_165;
}
if ( F_85 ( & V_2 -> V_4 ) &&
! F_86 ( V_2 ) &&
! V_2 -> V_4 . V_166 ) {
error = F_87 ( V_2 , V_25 -> V_22 ) ;
if ( error )
goto V_167;
}
error = F_88 ( V_2 , NULL , V_25 -> V_168 , 0 , V_169 , & V_131 ) ;
if ( error ) {
F_3 ( V_2 , L_23 ) ;
goto V_167;
}
ASSERT ( V_131 != NULL ) ;
if ( F_89 ( ! F_90 ( V_131 -> V_170 . V_171 ) ) ) {
F_3 ( V_2 , L_24 ,
( unsigned long long ) V_131 -> V_172 ) ;
F_91 ( V_131 , V_169 ) ;
F_82 ( L_25 , V_162 ,
V_2 ) ;
error = - V_73 ;
goto V_173;
}
V_2 -> V_174 = V_131 ;
F_91 ( V_131 , V_169 ) ;
error = F_92 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_26 ) ;
goto V_173;
}
if ( V_2 -> V_87 && ! ( V_2 -> V_8 & V_125 ) ) {
error = F_93 ( V_2 , V_2 -> V_87 ) ;
if ( error ) {
F_3 ( V_2 , L_27 ) ;
goto V_175;
}
}
if ( F_94 ( V_2 ) ) {
error = F_95 ( V_2 , & V_132 , & V_133 ) ;
if ( error )
goto V_175;
} else {
ASSERT ( ! F_96 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_123 & V_176 ) {
F_97 ( V_2 , L_28 ) ;
error = F_58 ( V_2 ) ;
if ( error )
goto V_175;
}
}
error = F_98 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_29 ) ;
goto V_175;
}
if ( V_132 ) {
ASSERT ( V_2 -> V_122 == 0 ) ;
V_2 -> V_122 = V_133 ;
F_99 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_125 ) ) {
V_130 = F_66 ( V_2 ) ;
error = F_100 ( V_2 , & V_130 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_30 ) ;
}
return 0 ;
V_175:
F_101 ( V_2 ) ;
V_173:
F_102 ( V_131 ) ;
V_167:
F_103 ( V_2 ) ;
V_165:
if ( V_2 -> V_118 && V_2 -> V_118 != V_2 -> V_67 )
F_104 ( V_2 -> V_118 ) ;
F_104 ( V_2 -> V_67 ) ;
V_163:
F_13 ( V_2 ) ;
V_161:
F_105 ( V_2 ) ;
V_157:
F_8 ( V_2 ) ;
V_152:
F_106 ( & V_2 -> V_146 ) ;
V_143:
return error ;
}
void
F_107 (
struct V_1 * V_2 )
{
T_5 V_130 ;
int error ;
F_108 ( & V_2 -> V_177 ) ;
F_109 ( V_2 ) ;
F_101 ( V_2 ) ;
F_102 ( V_2 -> V_174 ) ;
F_110 ( V_2 , V_178 ) ;
F_111 ( V_2 -> V_179 ) ;
F_108 ( & V_2 -> V_180 ) ;
F_112 ( V_2 , V_181 ) ;
F_113 ( V_2 ) ;
V_130 = 0 ;
error = F_100 ( V_2 , & V_130 , NULL ) ;
if ( error )
F_3 ( V_2 , L_31
L_32 ) ;
error = F_114 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_33
L_32 ) ;
F_103 ( V_2 ) ;
F_105 ( V_2 ) ;
F_8 ( V_2 ) ;
#if F_115 ( V_182 )
F_116 ( V_2 , 0 ) ;
#endif
F_13 ( V_2 ) ;
F_106 ( & V_2 -> V_146 ) ;
}
int
F_117 ( T_2 * V_2 )
{
return ! ( V_2 -> V_183 -> V_184 . V_185 || F_118 ( V_2 ) ||
( V_2 -> V_8 & V_125 ) ) ;
}
int
F_114 ( T_2 * V_2 )
{
T_13 * V_121 ;
int error ;
if ( ! F_117 ( V_2 ) )
return 0 ;
F_119 ( V_2 , 0 ) ;
if ( ! F_85 ( & V_2 -> V_4 ) )
return 0 ;
V_121 = F_120 ( V_2 , V_186 , V_15 ) ;
error = F_60 ( V_121 , & F_61 ( V_2 ) -> V_187 , 0 , 0 ) ;
if ( error ) {
F_62 ( V_121 , 0 ) ;
return error ;
}
F_64 ( V_121 , V_188 | V_189 | V_190 ) ;
F_121 ( V_121 ) ;
error = F_65 ( V_121 , 0 ) ;
return error ;
}
STATIC int
F_122 (
T_2 * V_2 ,
T_14 V_191 ,
T_15 V_192 ,
int V_193 )
{
int V_194 ;
long long V_195 ;
long long V_196 , V_197 ;
switch ( V_191 ) {
case V_198 :
V_195 = ( long long ) V_2 -> V_4 . V_199 ;
V_195 += V_192 ;
if ( V_195 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_199 = V_195 ;
return 0 ;
case V_200 :
V_195 = ( long long ) V_2 -> V_4 . V_201 ;
V_195 += V_192 ;
if ( V_195 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_201 = V_195 ;
return 0 ;
case V_202 :
V_195 = ( long long )
V_2 -> V_4 . V_203 - F_123 ( V_2 ) ;
V_196 = ( long long ) ( V_2 -> V_204 - V_2 -> V_205 ) ;
if ( V_192 > 0 ) {
if ( V_196 > V_192 ) {
V_2 -> V_205 += V_192 ;
} else {
V_197 = V_192 - V_196 ;
V_2 -> V_205 = V_2 -> V_204 ;
V_195 += V_197 ;
}
} else {
V_195 += V_192 ;
if ( V_195 >= 0 ) {
V_2 -> V_4 . V_203 = V_195 +
F_123 ( V_2 ) ;
return 0 ;
}
if ( ! V_193 )
return - V_206 ;
V_195 = ( long long ) V_2 -> V_205 + V_192 ;
if ( V_195 >= 0 ) {
V_2 -> V_205 = V_195 ;
return 0 ;
}
F_124 ( V_207
L_34
L_35 ,
V_2 -> V_151 ) ;
return - V_206 ;
}
V_2 -> V_4 . V_203 = V_195 + F_123 ( V_2 ) ;
return 0 ;
case V_208 :
V_195 = ( long long ) V_2 -> V_4 . V_209 ;
V_195 += V_192 ;
if ( V_195 < 0 ) {
return - V_206 ;
}
V_2 -> V_4 . V_209 = V_195 ;
return 0 ;
case V_210 :
V_195 = ( long long ) V_2 -> V_4 . V_94 ;
V_195 += V_192 ;
if ( V_195 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_94 = V_195 ;
return 0 ;
case V_211 :
V_194 = V_2 -> V_4 . V_22 ;
V_194 += V_192 ;
if ( V_194 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_22 = V_194 ;
return 0 ;
case V_212 :
V_194 = V_2 -> V_4 . V_93 ;
V_194 += V_192 ;
if ( V_194 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_93 = V_194 ;
return 0 ;
case V_213 :
V_194 = V_2 -> V_4 . V_214 ;
V_194 += V_192 ;
if ( V_194 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_214 = V_194 ;
return 0 ;
case V_215 :
V_194 = V_2 -> V_4 . V_216 ;
V_194 += V_192 ;
if ( V_194 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_216 = V_194 ;
return 0 ;
case V_217 :
V_195 = ( long long ) V_2 -> V_4 . V_218 ;
V_195 += V_192 ;
if ( V_195 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_218 = V_195 ;
return 0 ;
case V_219 :
V_195 = ( long long ) V_2 -> V_4 . V_220 ;
V_195 += V_192 ;
if ( V_195 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_220 = V_195 ;
return 0 ;
case V_221 :
V_194 = V_2 -> V_4 . V_222 ;
V_194 += V_192 ;
if ( V_194 < 0 ) {
ASSERT ( 0 ) ;
return - V_10 ;
}
V_2 -> V_4 . V_222 = V_194 ;
return 0 ;
default:
ASSERT ( 0 ) ;
return - V_10 ;
}
}
int
F_125 (
struct V_1 * V_2 ,
T_14 V_191 ,
T_15 V_192 ,
int V_193 )
{
int V_223 ;
#ifdef F_126
ASSERT ( V_191 < V_198 || V_191 > V_202 ) ;
#endif
F_14 ( & V_2 -> V_124 ) ;
V_223 = F_122 ( V_2 , V_191 , V_192 , V_193 ) ;
F_16 ( & V_2 -> V_124 ) ;
return V_223 ;
}
int
F_127 (
struct V_1 * V_2 ,
T_16 * V_224 ,
T_12 V_225 ,
int V_193 )
{
T_16 * V_226 ;
int error = 0 ;
F_14 ( & V_2 -> V_124 ) ;
for ( V_226 = V_224 ; V_226 < ( V_224 + V_225 ) ; V_226 ++ ) {
ASSERT ( V_226 -> V_227 < V_198 ||
V_226 -> V_227 > V_202 ) ;
error = F_122 ( V_2 , V_226 -> V_227 ,
V_226 -> V_228 , V_193 ) ;
if ( error )
goto V_229;
}
F_16 ( & V_2 -> V_124 ) ;
return 0 ;
V_229:
while ( -- V_226 >= V_224 ) {
error = F_122 ( V_2 , V_226 -> V_227 ,
- V_226 -> V_228 , V_193 ) ;
ASSERT ( error == 0 ) ;
}
F_16 ( & V_2 -> V_124 ) ;
return error ;
}
struct V_59 *
F_128 (
struct V_1 * V_2 ,
int V_57 )
{
struct V_59 * V_60 = V_2 -> V_66 ;
if ( ! F_129 ( V_60 ) ) {
if ( V_57 & V_230 )
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
T_17 V_231 )
{
T_13 * V_121 ;
int error ;
ASSERT ( V_231 & ( V_88 | V_90 | V_232 |
V_136 | V_137 |
V_140 ) ) ;
V_121 = F_59 ( V_2 , V_233 ) ;
error = F_60 ( V_121 , & F_61 ( V_2 ) -> V_187 , 0 , 0 ) ;
if ( error ) {
F_62 ( V_121 , 0 ) ;
return error ;
}
F_64 ( V_121 , V_231 ) ;
error = F_65 ( V_121 , 0 ) ;
return error ;
}
int
F_134 (
struct V_1 * V_2 ,
char * V_234 )
{
if ( F_135 ( V_2 -> V_67 ) ||
F_135 ( V_2 -> V_118 ) ||
( V_2 -> V_235 && F_135 ( V_2 -> V_235 ) ) ) {
F_97 ( V_2 , L_36 , V_234 ) ;
F_97 ( V_2 , L_37 ) ;
return - V_236 ;
}
return 0 ;
}
STATIC int
F_136 (
struct V_237 * V_238 ,
unsigned long V_239 ,
void * V_240 )
{
T_18 * V_241 ;
T_2 * V_2 ;
V_2 = ( T_2 * ) F_10 ( V_238 , T_2 , V_242 ) ;
V_241 = ( T_18 * )
F_137 ( V_2 -> V_243 , ( unsigned long ) V_240 ) ;
switch ( V_239 ) {
case V_244 :
case V_245 :
memset ( V_241 , 0 , sizeof( T_18 ) ) ;
break;
case V_246 :
case V_247 :
F_138 ( V_2 ) ;
F_139 ( V_2 , V_198 , 0 ) ;
F_139 ( V_2 , V_200 , 0 ) ;
F_139 ( V_2 , V_202 , 0 ) ;
F_140 ( V_2 ) ;
break;
case V_248 :
case V_249 :
F_138 ( V_2 ) ;
F_14 ( & V_2 -> V_124 ) ;
F_141 ( V_2 , V_198 ) ;
F_141 ( V_2 , V_200 ) ;
F_141 ( V_2 , V_202 ) ;
V_2 -> V_4 . V_199 += V_241 -> V_250 ;
V_2 -> V_4 . V_201 += V_241 -> V_251 ;
V_2 -> V_4 . V_203 += V_241 -> V_252 ;
memset ( V_241 , 0 , sizeof( T_18 ) ) ;
F_142 ( V_2 , V_198 , 0 ) ;
F_142 ( V_2 , V_200 , 0 ) ;
F_142 ( V_2 , V_202 , 0 ) ;
F_16 ( & V_2 -> V_124 ) ;
F_140 ( V_2 ) ;
break;
}
return V_253 ;
}
int
F_143 (
T_2 * V_2 )
{
T_18 * V_241 ;
int V_7 ;
V_2 -> V_243 = F_144 ( T_18 ) ;
if ( V_2 -> V_243 == NULL )
return - V_39 ;
F_145 (i) {
V_241 = ( T_18 * ) F_137 ( V_2 -> V_243 , V_7 ) ;
memset ( V_241 , 0 , sizeof( T_18 ) ) ;
}
F_24 ( & V_2 -> V_254 ) ;
V_2 -> V_255 = - 1 ;
#ifdef F_146
V_2 -> V_242 . V_256 = F_136 ;
V_2 -> V_242 . V_257 = 0 ;
F_147 ( & V_2 -> V_242 ) ;
#endif
return 0 ;
}
void
F_41 (
T_2 * V_2 )
{
F_138 ( V_2 ) ;
V_2 -> V_255 = - 1 ;
F_139 ( V_2 , V_198 , 0 ) ;
F_139 ( V_2 , V_200 , 0 ) ;
F_139 ( V_2 , V_202 , 0 ) ;
F_140 ( V_2 ) ;
}
void
F_148 (
T_2 * V_2 )
{
if ( V_2 -> V_243 ) {
F_149 ( & V_2 -> V_242 ) ;
F_150 ( V_2 -> V_243 ) ;
}
F_151 ( & V_2 -> V_254 ) ;
}
STATIC void
F_152 (
T_18 * V_258 )
{
while ( F_153 ( V_259 , & V_258 -> V_260 ) ) {
F_154 ( 1000 ) ;
}
}
STATIC void
F_155 (
T_18 * V_258 )
{
F_156 ( V_259 , & V_258 -> V_260 ) ;
}
STATIC void
F_157 (
T_2 * V_2 )
{
T_18 * V_241 ;
int V_7 ;
F_145 (i) {
V_241 = ( T_18 * ) F_137 ( V_2 -> V_243 , V_7 ) ;
F_152 ( V_241 ) ;
}
}
STATIC void
F_158 (
T_2 * V_2 )
{
T_18 * V_241 ;
int V_7 ;
F_145 (i) {
V_241 = ( T_18 * ) F_137 ( V_2 -> V_243 , V_7 ) ;
F_155 ( V_241 ) ;
}
}
STATIC void
F_159 (
T_2 * V_2 ,
T_18 * V_261 ,
int V_57 )
{
T_18 * V_241 ;
int V_7 ;
memset ( V_261 , 0 , sizeof( T_18 ) ) ;
if ( ! ( V_57 & V_262 ) )
F_157 ( V_2 ) ;
F_145 (i) {
V_241 = ( T_18 * ) F_137 ( V_2 -> V_243 , V_7 ) ;
V_261 -> V_250 += V_241 -> V_250 ;
V_261 -> V_251 += V_241 -> V_251 ;
V_261 -> V_252 += V_241 -> V_252 ;
}
if ( ! ( V_57 & V_262 ) )
F_158 ( V_2 ) ;
}
STATIC int
F_160 (
T_2 * V_2 ,
T_14 V_191 )
{
ASSERT ( ( V_191 >= V_198 ) && ( V_191 <= V_202 ) ) ;
return F_161 ( V_191 , & V_2 -> V_255 ) ;
}
STATIC void
F_141 (
T_2 * V_2 ,
T_14 V_191 )
{
T_18 V_261 ;
ASSERT ( ( V_191 >= V_198 ) && ( V_191 <= V_202 ) ) ;
if ( F_160 ( V_2 , V_191 ) )
return;
F_157 ( V_2 ) ;
if ( ! F_153 ( V_191 , & V_2 -> V_255 ) ) {
F_159 ( V_2 , & V_261 , V_262 ) ;
switch( V_191 ) {
case V_198 :
V_2 -> V_4 . V_199 = V_261 . V_250 ;
break;
case V_200 :
V_2 -> V_4 . V_201 = V_261 . V_251 ;
break;
case V_202 :
V_2 -> V_4 . V_203 = V_261 . V_252 ;
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
T_14 V_191 ,
T_19 V_263 ,
T_19 V_264 )
{
T_18 * V_241 ;
int V_7 ;
ASSERT ( ( V_191 >= V_198 ) && ( V_191 <= V_202 ) ) ;
F_157 ( V_2 ) ;
F_145 (i) {
V_241 = F_137 ( V_2 -> V_243 , V_7 ) ;
switch ( V_191 ) {
case V_198 :
V_241 -> V_250 = V_263 + V_264 ;
break;
case V_200 :
V_241 -> V_251 = V_263 + V_264 ;
break;
case V_202 :
V_241 -> V_252 = V_263 + V_264 ;
break;
default:
F_28 () ;
break;
}
V_264 = 0 ;
}
F_156 ( V_191 , & V_2 -> V_255 ) ;
F_158 ( V_2 ) ;
}
void
F_163 (
T_2 * V_2 ,
int V_57 )
{
T_18 V_261 ;
F_159 ( V_2 , & V_261 , V_57 ) ;
if ( ! F_160 ( V_2 , V_198 ) )
V_2 -> V_4 . V_199 = V_261 . V_250 ;
if ( ! F_160 ( V_2 , V_200 ) )
V_2 -> V_4 . V_201 = V_261 . V_251 ;
if ( ! F_160 ( V_2 , V_202 ) )
V_2 -> V_4 . V_203 = V_261 . V_252 ;
}
void
F_119 (
T_2 * V_2 ,
int V_57 )
{
F_14 ( & V_2 -> V_124 ) ;
F_163 ( V_2 , V_57 ) ;
F_16 ( & V_2 -> V_124 ) ;
}
STATIC void
F_142 (
T_2 * V_2 ,
T_14 V_191 ,
int V_265 )
{
T_19 V_263 , V_264 ;
int V_266 = F_164 () ;
T_19 V_267 = ( T_19 ) V_265 ;
F_141 ( V_2 , V_191 ) ;
switch ( V_191 ) {
case V_198 :
V_263 = V_2 -> V_4 . V_199 ;
V_264 = F_48 ( V_263 , V_266 ) ;
if ( V_263 < F_165 ( V_267 , V_268 ) )
return;
break;
case V_200 :
V_263 = V_2 -> V_4 . V_201 ;
V_264 = F_48 ( V_263 , V_266 ) ;
if ( V_263 < F_165 ( V_267 , V_268 ) )
return;
break;
case V_202 :
V_263 = V_2 -> V_4 . V_203 ;
V_264 = F_48 ( V_263 , V_266 ) ;
if ( V_263 < F_165 ( V_267 , F_166 ( V_2 ) ) )
return;
break;
default:
F_28 () ;
V_263 = V_264 = 0 ;
break;
}
F_162 ( V_2 , V_191 , V_263 , V_264 ) ;
}
STATIC void
F_139 (
T_2 * V_2 ,
T_14 V_231 ,
int V_265 )
{
F_14 ( & V_2 -> V_124 ) ;
F_142 ( V_2 , V_231 , V_265 ) ;
F_16 ( & V_2 -> V_124 ) ;
}
int
F_167 (
T_2 * V_2 ,
T_14 V_191 ,
T_15 V_192 ,
int V_193 )
{
T_18 * V_258 ;
long long V_195 ;
int V_269 = 0 ;
F_168 () ;
V_270:
F_169 () ;
V_258 = F_170 ( V_2 -> V_243 ) ;
if ( F_89 ( F_160 ( V_2 , V_191 ) ) )
goto V_271;
F_152 ( V_258 ) ;
if ( F_89 ( F_160 ( V_2 , V_191 ) ) ) {
F_155 ( V_258 ) ;
goto V_271;
}
switch ( V_191 ) {
case V_198 :
V_195 = V_258 -> V_250 ;
V_195 += V_192 ;
if ( F_89 ( V_195 < 0 ) )
goto V_272;
V_258 -> V_250 = V_195 ;
break;
case V_200 :
V_195 = V_258 -> V_251 ;
V_195 += V_192 ;
if ( F_89 ( V_195 < 0 ) )
goto V_272;
V_258 -> V_251 = V_195 ;
break;
case V_202 :
F_171 ( ( V_2 -> V_204 - V_2 -> V_205 ) != 0 ) ;
V_195 = V_258 -> V_252 - F_123 ( V_2 ) ;
V_195 += V_192 ;
if ( F_89 ( V_195 < 0 ) )
goto V_272;
V_258 -> V_252 = V_195 + F_123 ( V_2 ) ;
break;
default:
F_28 () ;
break;
}
F_155 ( V_258 ) ;
F_172 () ;
return 0 ;
V_271:
F_172 () ;
F_138 ( V_2 ) ;
if ( ! ( F_160 ( V_2 , V_191 ) ) ) {
F_140 ( V_2 ) ;
goto V_270;
}
F_14 ( & V_2 -> V_124 ) ;
V_269 = F_122 ( V_2 , V_191 , V_192 , V_193 ) ;
F_16 ( & V_2 -> V_124 ) ;
if ( V_269 != - V_206 )
F_139 ( V_2 , V_191 , 0 ) ;
F_140 ( V_2 ) ;
return V_269 ;
V_272:
F_155 ( V_258 ) ;
F_172 () ;
F_138 ( V_2 ) ;
F_139 ( V_2 , V_191 , V_192 ) ;
F_140 ( V_2 ) ;
goto V_270;
}
