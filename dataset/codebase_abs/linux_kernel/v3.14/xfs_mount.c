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
goto V_74;
}
F_39 ( & V_2 -> V_4 , F_40 ( V_62 ) ) ;
F_41 ( & V_2 -> V_4 ) ;
if ( V_60 > V_25 -> V_75 ) {
if ( V_64 )
F_3 ( V_2 , L_5 ,
V_60 , V_25 -> V_75 ) ;
error = V_76 ;
goto V_74;
}
if ( V_67 == NULL ) {
F_42 ( V_62 ) ;
V_60 = V_25 -> V_75 ;
V_67 = V_64 ? & V_77 : & V_78 ;
goto V_70;
}
F_43 ( V_2 ) ;
V_62 -> V_79 = & V_77 ;
V_2 -> V_68 = V_62 ;
F_44 ( V_62 ) ;
return 0 ;
V_74:
F_42 ( V_62 ) ;
return error ;
}
STATIC int
F_45 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
if ( V_2 -> V_80 ) {
if ( ( F_46 ( V_2 -> V_80 ) & V_2 -> V_81 ) ||
( F_46 ( V_2 -> V_82 ) & V_2 -> V_81 ) ) {
F_3 ( V_2 ,
L_6 ,
V_25 -> V_83 ) ;
return F_4 ( V_10 ) ;
} else {
V_2 -> V_80 = F_47 ( V_2 , V_2 -> V_80 ) ;
if ( V_2 -> V_80 && ( V_25 -> V_55 % V_2 -> V_80 ) ) {
F_3 ( V_2 ,
L_7 ,
V_25 -> V_55 ) ;
return F_4 ( V_10 ) ;
} else if ( V_2 -> V_80 ) {
V_2 -> V_82 = F_47 ( V_2 , V_2 -> V_82 ) ;
} else {
F_3 ( V_2 ,
L_8 ,
V_2 -> V_80 , V_25 -> V_83 ) ;
return F_4 ( V_10 ) ;
}
}
if ( F_48 ( V_25 ) ) {
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
return F_4 ( V_10 ) ;
}
} else if ( ( V_2 -> V_8 & V_89 ) != V_89 &&
F_48 ( & V_2 -> V_4 ) ) {
V_2 -> V_80 = V_25 -> V_84 ;
V_2 -> V_82 = V_25 -> V_87 ;
}
return 0 ;
}
STATIC void
F_49 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_5 V_90 ;
if ( V_25 -> V_91 ) {
V_90 = V_25 -> V_92 * V_25 -> V_91 ;
F_50 ( V_90 , 100 ) ;
F_50 ( V_90 , V_2 -> V_93 ) ;
V_2 -> V_94 = ( V_90 * V_2 -> V_93 ) <<
V_25 -> V_95 ;
} else {
V_2 -> V_94 = 0 ;
}
}
STATIC void
F_51 ( T_2 * V_2 )
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
F_52 (
struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_108 ; V_7 ++ ) {
T_5 V_109 = V_2 -> V_4 . V_92 ;
F_50 ( V_109 , 100 ) ;
V_2 -> V_110 [ V_7 ] = V_109 * ( V_7 + 1 ) ;
}
}
STATIC void
F_53 ( T_2 * V_2 )
{
if ( F_54 ( & V_2 -> V_4 ) &&
V_2 -> V_4 . V_111 >=
F_55 ( V_2 , V_2 -> V_112 ) )
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
F_56 ( T_2 * V_2 )
{
T_9 * V_62 ;
T_10 V_115 ;
V_115 = ( T_10 ) F_57 ( V_2 , V_2 -> V_4 . V_92 ) ;
if ( F_58 ( V_2 , V_115 ) != V_2 -> V_4 . V_92 ) {
F_3 ( V_2 , L_10 ) ;
return F_4 ( V_33 ) ;
}
V_62 = F_37 ( V_2 -> V_69 ,
V_115 - F_59 ( V_2 , 1 ) ,
F_59 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_62 ) {
F_3 ( V_2 , L_11 ) ;
return V_72 ;
}
F_42 ( V_62 ) ;
if ( V_2 -> V_116 != V_2 -> V_69 ) {
V_115 = ( T_10 ) F_57 ( V_2 , V_2 -> V_4 . V_117 ) ;
if ( F_58 ( V_2 , V_115 ) != V_2 -> V_4 . V_117 ) {
F_3 ( V_2 , L_12 ) ;
return F_4 ( V_33 ) ;
}
V_62 = F_37 ( V_2 -> V_116 ,
V_115 - F_57 ( V_2 , 1 ) ,
F_57 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_62 ) {
F_3 ( V_2 , L_13 ) ;
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
struct V_118 * V_119 ;
V_2 -> V_120 = 0 ;
if ( V_2 -> V_4 . V_121 == 0 )
return 0 ;
F_15 ( & V_2 -> V_122 ) ;
V_2 -> V_4 . V_121 = 0 ;
F_17 ( & V_2 -> V_122 ) ;
if ( V_2 -> V_8 & V_123 )
return 0 ;
V_119 = F_61 ( V_2 , V_124 ) ;
error = F_62 ( V_119 , & F_63 ( V_2 ) -> V_125 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_119 , 0 ) ;
F_65 ( V_2 , L_14 , V_126 ) ;
return error ;
}
F_66 ( V_119 , V_127 ) ;
return F_67 ( V_119 , 0 ) ;
}
T_5
F_68 ( T_2 * V_2 )
{
T_5 V_128 ;
V_128 = V_2 -> V_4 . V_92 ;
F_50 ( V_128 , 20 ) ;
V_128 = F_69 ( T_5 , V_128 , 8192 ) ;
return V_128 ;
}
int
F_70 (
T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_11 * V_129 ;
T_5 V_128 ;
T_12 V_130 = 0 ;
T_12 V_131 = 0 ;
int error = 0 ;
F_71 ( V_2 , V_25 ) ;
if ( F_72 ( V_25 ) ) {
F_3 ( V_2 , L_15 ) ;
V_25 -> V_132 |= V_25 -> V_133 ;
V_25 -> V_133 = V_25 -> V_132 ;
V_2 -> V_85 |= V_134 | V_135 ;
if ( F_73 ( & V_2 -> V_4 ) &&
! ( V_2 -> V_8 & V_136 ) )
V_2 -> V_8 |= V_137 ;
}
if ( F_73 ( & V_2 -> V_4 ) &&
( V_2 -> V_8 & V_136 ) ) {
F_74 ( & V_2 -> V_4 ) ;
V_2 -> V_85 |= V_134 ;
if ( ! V_25 -> V_132 )
V_2 -> V_85 |= V_138 ;
}
error = F_45 ( V_2 ) ;
if ( error )
goto V_139;
F_75 ( V_2 ) ;
F_76 ( V_2 , V_140 ) ;
F_76 ( V_2 , V_141 ) ;
F_77 ( V_2 ) ;
F_49 ( V_2 ) ;
error = F_1 ( V_2 ) ;
if ( error )
goto V_139;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_112 = V_142 ;
if ( F_78 ( & V_2 -> V_4 ) ) {
int V_143 = V_2 -> V_112 ;
V_143 *= V_2 -> V_4 . V_144 / V_145 ;
if ( V_2 -> V_4 . V_111 >= F_55 ( V_2 , V_143 ) )
V_2 -> V_112 = V_143 ;
F_79 ( V_2 , L_16 ,
V_2 -> V_112 ) ;
}
F_53 ( V_2 ) ;
error = F_56 ( V_2 ) ;
if ( error )
goto V_146;
error = F_80 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_17 ) ;
goto V_146;
}
F_81 ( & V_25 -> V_5 , V_2 -> V_147 ) ;
V_2 -> V_148 = 0 ;
F_82 ( V_2 ) ;
V_2 -> V_149 = ( V_2 -> V_4 . V_83 * 37 ) / 100 ;
F_83 ( V_2 ) ;
F_24 ( & V_2 -> V_23 ) ;
F_26 ( & V_2 -> V_24 , V_49 ) ;
error = F_20 ( V_2 , V_25 -> V_22 , & V_2 -> V_150 ) ;
if ( error ) {
F_3 ( V_2 , L_18 , error ) ;
goto V_146;
}
if ( ! V_25 -> V_117 ) {
F_3 ( V_2 , L_19 ) ;
F_84 ( L_20 , V_151 , V_2 ) ;
error = F_4 ( V_152 ) ;
goto V_153;
}
error = F_85 ( V_2 , V_2 -> V_116 ,
F_86 ( V_2 , V_25 -> V_154 ) ,
F_57 ( V_2 , V_25 -> V_117 ) ) ;
if ( error ) {
F_3 ( V_2 , L_21 ) ;
goto V_155;
}
if ( F_87 ( & V_2 -> V_4 ) &&
! F_88 ( V_2 ) &&
! V_2 -> V_4 . V_156 ) {
error = F_89 ( V_2 , V_25 -> V_22 ) ;
if ( error )
goto V_155;
}
error = F_90 ( V_2 , NULL , V_25 -> V_157 , 0 , V_158 , & V_129 ) ;
if ( error ) {
F_3 ( V_2 , L_22 ) ;
goto V_159;
}
ASSERT ( V_129 != NULL ) ;
if ( F_91 ( ! F_92 ( V_129 -> V_160 . V_161 ) ) ) {
F_3 ( V_2 , L_23 ,
( unsigned long long ) V_129 -> V_162 ) ;
F_93 ( V_129 , V_158 ) ;
F_84 ( L_24 , V_151 ,
V_2 ) ;
error = F_4 ( V_152 ) ;
goto V_163;
}
V_2 -> V_164 = V_129 ;
F_93 ( V_129 , V_158 ) ;
error = F_94 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_25 ) ;
goto V_163;
}
if ( V_2 -> V_85 && ! ( V_2 -> V_8 & V_123 ) ) {
error = F_95 ( V_2 , V_2 -> V_85 ) ;
if ( error ) {
F_3 ( V_2 , L_26 ) ;
goto V_165;
}
}
if ( F_96 ( V_2 ) ) {
error = F_97 ( V_2 , & V_130 , & V_131 ) ;
if ( error )
goto V_165;
} else {
ASSERT ( ! F_98 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_121 & V_166 ) {
F_99 ( V_2 , L_27 ) ;
error = F_60 ( V_2 ) ;
if ( error )
return error ;
}
}
error = F_100 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_28 ) ;
goto V_165;
}
if ( V_130 ) {
ASSERT ( V_2 -> V_120 == 0 ) ;
V_2 -> V_120 = V_131 ;
F_101 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_123 ) ) {
V_128 = F_68 ( V_2 ) ;
error = F_102 ( V_2 , & V_128 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_29 ) ;
}
return 0 ;
V_165:
F_103 ( V_2 ) ;
V_163:
F_104 ( V_129 ) ;
V_159:
F_105 ( V_2 ) ;
V_155:
if ( V_2 -> V_116 && V_2 -> V_116 != V_2 -> V_69 )
F_106 ( V_2 -> V_116 ) ;
F_106 ( V_2 -> V_69 ) ;
V_153:
F_14 ( V_2 ) ;
V_146:
F_9 ( V_2 ) ;
V_139:
return error ;
}
void
F_107 (
struct V_1 * V_2 )
{
T_5 V_128 ;
int error ;
F_108 ( & V_2 -> V_167 ) ;
F_109 ( V_2 ) ;
F_103 ( V_2 ) ;
F_104 ( V_2 -> V_164 ) ;
F_110 ( V_2 , V_168 ) ;
F_111 ( V_2 -> V_169 ) ;
F_108 ( & V_2 -> V_170 ) ;
F_112 ( V_2 , V_171 ) ;
F_113 ( V_2 ) ;
V_128 = 0 ;
error = F_102 ( V_2 , & V_128 , NULL ) ;
if ( error )
F_3 ( V_2 , L_30
L_31 ) ;
error = F_114 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_32
L_31 ) ;
F_105 ( V_2 ) ;
F_9 ( V_2 ) ;
#if F_115 ( V_172 )
F_116 ( V_2 , 0 ) ;
#endif
F_14 ( V_2 ) ;
}
int
F_117 ( T_2 * V_2 )
{
return ! ( V_2 -> V_173 -> V_174 . V_175 || F_118 ( V_2 ) ||
( V_2 -> V_8 & V_123 ) ) ;
}
int
F_114 ( T_2 * V_2 )
{
T_13 * V_119 ;
int error ;
if ( ! F_117 ( V_2 ) )
return 0 ;
F_119 ( V_2 , 0 ) ;
if ( ! F_87 ( & V_2 -> V_4 ) )
return 0 ;
V_119 = F_120 ( V_2 , V_176 , V_15 ) ;
error = F_62 ( V_119 , & F_63 ( V_2 ) -> V_177 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_119 , 0 ) ;
return error ;
}
F_66 ( V_119 , V_178 | V_179 | V_180 ) ;
F_121 ( V_119 ) ;
error = F_67 ( V_119 , 0 ) ;
return error ;
}
STATIC int
F_122 (
T_2 * V_2 ,
T_14 V_181 ,
T_15 V_182 ,
int V_183 )
{
int V_184 ;
long long V_185 ;
long long V_186 , V_187 ;
switch ( V_181 ) {
case V_188 :
V_185 = ( long long ) V_2 -> V_4 . V_189 ;
V_185 += V_182 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_189 = V_185 ;
return 0 ;
case V_190 :
V_185 = ( long long ) V_2 -> V_4 . V_191 ;
V_185 += V_182 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_191 = V_185 ;
return 0 ;
case V_192 :
V_185 = ( long long )
V_2 -> V_4 . V_193 - F_123 ( V_2 ) ;
V_186 = ( long long ) ( V_2 -> V_194 - V_2 -> V_195 ) ;
if ( V_182 > 0 ) {
if ( V_186 > V_182 ) {
V_2 -> V_195 += V_182 ;
} else {
V_187 = V_182 - V_186 ;
V_2 -> V_195 = V_2 -> V_194 ;
V_185 += V_187 ;
}
} else {
V_185 += V_182 ;
if ( V_185 >= 0 ) {
V_2 -> V_4 . V_193 = V_185 +
F_123 ( V_2 ) ;
return 0 ;
}
if ( ! V_183 )
return F_4 ( V_196 ) ;
V_185 = ( long long ) V_2 -> V_195 + V_182 ;
if ( V_185 >= 0 ) {
V_2 -> V_195 = V_185 ;
return 0 ;
}
F_124 ( V_197
L_33
L_34 ,
V_2 -> V_198 ) ;
return F_4 ( V_196 ) ;
}
V_2 -> V_4 . V_193 = V_185 + F_123 ( V_2 ) ;
return 0 ;
case V_199 :
V_185 = ( long long ) V_2 -> V_4 . V_200 ;
V_185 += V_182 ;
if ( V_185 < 0 ) {
return F_4 ( V_196 ) ;
}
V_2 -> V_4 . V_200 = V_185 ;
return 0 ;
case V_201 :
V_185 = ( long long ) V_2 -> V_4 . V_92 ;
V_185 += V_182 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_92 = V_185 ;
return 0 ;
case V_202 :
V_184 = V_2 -> V_4 . V_22 ;
V_184 += V_182 ;
if ( V_184 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_22 = V_184 ;
return 0 ;
case V_203 :
V_184 = V_2 -> V_4 . V_91 ;
V_184 += V_182 ;
if ( V_184 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_91 = V_184 ;
return 0 ;
case V_204 :
V_184 = V_2 -> V_4 . V_205 ;
V_184 += V_182 ;
if ( V_184 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_205 = V_184 ;
return 0 ;
case V_206 :
V_184 = V_2 -> V_4 . V_207 ;
V_184 += V_182 ;
if ( V_184 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_207 = V_184 ;
return 0 ;
case V_208 :
V_185 = ( long long ) V_2 -> V_4 . V_209 ;
V_185 += V_182 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_209 = V_185 ;
return 0 ;
case V_210 :
V_185 = ( long long ) V_2 -> V_4 . V_211 ;
V_185 += V_182 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_211 = V_185 ;
return 0 ;
case V_212 :
V_184 = V_2 -> V_4 . V_213 ;
V_184 += V_182 ;
if ( V_184 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_213 = V_184 ;
return 0 ;
default:
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
}
int
F_125 (
struct V_1 * V_2 ,
T_14 V_181 ,
T_15 V_182 ,
int V_183 )
{
int V_214 ;
#ifdef F_126
ASSERT ( V_181 < V_188 || V_181 > V_192 ) ;
#endif
F_15 ( & V_2 -> V_122 ) ;
V_214 = F_122 ( V_2 , V_181 , V_182 , V_183 ) ;
F_17 ( & V_2 -> V_122 ) ;
return V_214 ;
}
int
F_127 (
struct V_1 * V_2 ,
T_16 * V_215 ,
T_12 V_216 ,
int V_183 )
{
T_16 * V_217 ;
int error = 0 ;
F_15 ( & V_2 -> V_122 ) ;
for ( V_217 = V_215 ; V_217 < ( V_215 + V_216 ) ; V_217 ++ ) {
ASSERT ( V_217 -> V_218 < V_188 ||
V_217 -> V_218 > V_192 ) ;
error = F_122 ( V_2 , V_217 -> V_218 ,
V_217 -> V_219 , V_183 ) ;
if ( error )
goto V_220;
}
F_17 ( & V_2 -> V_122 ) ;
return 0 ;
V_220:
while ( -- V_217 >= V_215 ) {
error = F_122 ( V_2 , V_217 -> V_218 ,
- V_217 -> V_219 , V_183 ) ;
ASSERT ( error == 0 ) ;
}
F_17 ( & V_2 -> V_122 ) ;
return error ;
}
struct V_61 *
F_128 (
struct V_1 * V_2 ,
int V_59 )
{
struct V_61 * V_62 = V_2 -> V_68 ;
if ( ! F_129 ( V_62 ) ) {
if ( V_59 & V_221 )
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
F_95 (
T_2 * V_2 ,
T_17 V_222 )
{
T_13 * V_119 ;
int error ;
ASSERT ( V_222 & ( V_86 | V_88 | V_223 |
V_134 | V_135 |
V_138 ) ) ;
V_119 = F_61 ( V_2 , V_224 ) ;
error = F_62 ( V_119 , & F_63 ( V_2 ) -> V_177 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_119 , 0 ) ;
return error ;
}
F_66 ( V_119 , V_222 ) ;
error = F_67 ( V_119 , 0 ) ;
return error ;
}
int
F_134 (
struct V_1 * V_2 ,
char * V_225 )
{
if ( F_135 ( V_2 -> V_69 ) ||
F_135 ( V_2 -> V_116 ) ||
( V_2 -> V_226 && F_135 ( V_2 -> V_226 ) ) ) {
F_99 ( V_2 , L_35 , V_225 ) ;
F_99 ( V_2 , L_36 ) ;
return V_227 ;
}
return 0 ;
}
STATIC int
F_136 (
struct V_228 * V_229 ,
unsigned long V_230 ,
void * V_231 )
{
T_18 * V_232 ;
T_2 * V_2 ;
V_2 = ( T_2 * ) F_11 ( V_229 , T_2 , V_233 ) ;
V_232 = ( T_18 * )
F_137 ( V_2 -> V_234 , ( unsigned long ) V_231 ) ;
switch ( V_230 ) {
case V_235 :
case V_236 :
memset ( V_232 , 0 , sizeof( T_18 ) ) ;
break;
case V_237 :
case V_238 :
F_138 ( V_2 ) ;
F_139 ( V_2 , V_188 , 0 ) ;
F_139 ( V_2 , V_190 , 0 ) ;
F_139 ( V_2 , V_192 , 0 ) ;
F_140 ( V_2 ) ;
break;
case V_239 :
case V_240 :
F_138 ( V_2 ) ;
F_15 ( & V_2 -> V_122 ) ;
F_141 ( V_2 , V_188 ) ;
F_141 ( V_2 , V_190 ) ;
F_141 ( V_2 , V_192 ) ;
V_2 -> V_4 . V_189 += V_232 -> V_241 ;
V_2 -> V_4 . V_191 += V_232 -> V_242 ;
V_2 -> V_4 . V_193 += V_232 -> V_243 ;
memset ( V_232 , 0 , sizeof( T_18 ) ) ;
F_142 ( V_2 , V_188 , 0 ) ;
F_142 ( V_2 , V_190 , 0 ) ;
F_142 ( V_2 , V_192 , 0 ) ;
F_17 ( & V_2 -> V_122 ) ;
F_140 ( V_2 ) ;
break;
}
return V_244 ;
}
int
F_143 (
T_2 * V_2 )
{
T_18 * V_232 ;
int V_7 ;
V_2 -> V_234 = F_144 ( T_18 ) ;
if ( V_2 -> V_234 == NULL )
return - V_41 ;
F_145 (i) {
V_232 = ( T_18 * ) F_137 ( V_2 -> V_234 , V_7 ) ;
memset ( V_232 , 0 , sizeof( T_18 ) ) ;
}
F_25 ( & V_2 -> V_245 ) ;
V_2 -> V_246 = - 1 ;
#ifdef F_146
V_2 -> V_233 . V_247 = F_136 ;
V_2 -> V_233 . V_248 = 0 ;
F_147 ( & V_2 -> V_233 ) ;
#endif
return 0 ;
}
void
F_43 (
T_2 * V_2 )
{
F_138 ( V_2 ) ;
V_2 -> V_246 = - 1 ;
F_139 ( V_2 , V_188 , 0 ) ;
F_139 ( V_2 , V_190 , 0 ) ;
F_139 ( V_2 , V_192 , 0 ) ;
F_140 ( V_2 ) ;
}
void
F_148 (
T_2 * V_2 )
{
if ( V_2 -> V_234 ) {
F_149 ( & V_2 -> V_233 ) ;
F_150 ( V_2 -> V_234 ) ;
}
F_151 ( & V_2 -> V_245 ) ;
}
STATIC void
F_152 (
T_18 * V_249 )
{
while ( F_153 ( V_250 , & V_249 -> V_251 ) ) {
F_154 ( 1000 ) ;
}
}
STATIC void
F_155 (
T_18 * V_249 )
{
F_156 ( V_250 , & V_249 -> V_251 ) ;
}
STATIC void
F_157 (
T_2 * V_2 )
{
T_18 * V_232 ;
int V_7 ;
F_145 (i) {
V_232 = ( T_18 * ) F_137 ( V_2 -> V_234 , V_7 ) ;
F_152 ( V_232 ) ;
}
}
STATIC void
F_158 (
T_2 * V_2 )
{
T_18 * V_232 ;
int V_7 ;
F_145 (i) {
V_232 = ( T_18 * ) F_137 ( V_2 -> V_234 , V_7 ) ;
F_155 ( V_232 ) ;
}
}
STATIC void
F_159 (
T_2 * V_2 ,
T_18 * V_252 ,
int V_59 )
{
T_18 * V_232 ;
int V_7 ;
memset ( V_252 , 0 , sizeof( T_18 ) ) ;
if ( ! ( V_59 & V_253 ) )
F_157 ( V_2 ) ;
F_145 (i) {
V_232 = ( T_18 * ) F_137 ( V_2 -> V_234 , V_7 ) ;
V_252 -> V_241 += V_232 -> V_241 ;
V_252 -> V_242 += V_232 -> V_242 ;
V_252 -> V_243 += V_232 -> V_243 ;
}
if ( ! ( V_59 & V_253 ) )
F_158 ( V_2 ) ;
}
STATIC int
F_160 (
T_2 * V_2 ,
T_14 V_181 )
{
ASSERT ( ( V_181 >= V_188 ) && ( V_181 <= V_192 ) ) ;
return F_161 ( V_181 , & V_2 -> V_246 ) ;
}
STATIC void
F_141 (
T_2 * V_2 ,
T_14 V_181 )
{
T_18 V_252 ;
ASSERT ( ( V_181 >= V_188 ) && ( V_181 <= V_192 ) ) ;
if ( F_160 ( V_2 , V_181 ) )
return;
F_157 ( V_2 ) ;
if ( ! F_153 ( V_181 , & V_2 -> V_246 ) ) {
F_159 ( V_2 , & V_252 , V_253 ) ;
switch( V_181 ) {
case V_188 :
V_2 -> V_4 . V_189 = V_252 . V_241 ;
break;
case V_190 :
V_2 -> V_4 . V_191 = V_252 . V_242 ;
break;
case V_192 :
V_2 -> V_4 . V_193 = V_252 . V_243 ;
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
T_14 V_181 ,
T_19 V_254 ,
T_19 V_255 )
{
T_18 * V_232 ;
int V_7 ;
ASSERT ( ( V_181 >= V_188 ) && ( V_181 <= V_192 ) ) ;
F_157 ( V_2 ) ;
F_145 (i) {
V_232 = F_137 ( V_2 -> V_234 , V_7 ) ;
switch ( V_181 ) {
case V_188 :
V_232 -> V_241 = V_254 + V_255 ;
break;
case V_190 :
V_232 -> V_242 = V_254 + V_255 ;
break;
case V_192 :
V_232 -> V_243 = V_254 + V_255 ;
break;
default:
F_29 () ;
break;
}
V_255 = 0 ;
}
F_156 ( V_181 , & V_2 -> V_246 ) ;
F_158 ( V_2 ) ;
}
void
F_163 (
T_2 * V_2 ,
int V_59 )
{
T_18 V_252 ;
F_159 ( V_2 , & V_252 , V_59 ) ;
if ( ! F_160 ( V_2 , V_188 ) )
V_2 -> V_4 . V_189 = V_252 . V_241 ;
if ( ! F_160 ( V_2 , V_190 ) )
V_2 -> V_4 . V_191 = V_252 . V_242 ;
if ( ! F_160 ( V_2 , V_192 ) )
V_2 -> V_4 . V_193 = V_252 . V_243 ;
}
void
F_119 (
T_2 * V_2 ,
int V_59 )
{
F_15 ( & V_2 -> V_122 ) ;
F_163 ( V_2 , V_59 ) ;
F_17 ( & V_2 -> V_122 ) ;
}
STATIC void
F_142 (
T_2 * V_2 ,
T_14 V_181 ,
int V_256 )
{
T_19 V_254 , V_255 ;
int V_257 = F_164 () ;
T_19 V_258 = ( T_19 ) V_256 ;
F_141 ( V_2 , V_181 ) ;
switch ( V_181 ) {
case V_188 :
V_254 = V_2 -> V_4 . V_189 ;
V_255 = F_50 ( V_254 , V_257 ) ;
if ( V_254 < F_165 ( V_258 , V_259 ) )
return;
break;
case V_190 :
V_254 = V_2 -> V_4 . V_191 ;
V_255 = F_50 ( V_254 , V_257 ) ;
if ( V_254 < F_165 ( V_258 , V_259 ) )
return;
break;
case V_192 :
V_254 = V_2 -> V_4 . V_193 ;
V_255 = F_50 ( V_254 , V_257 ) ;
if ( V_254 < F_165 ( V_258 , F_166 ( V_2 ) ) )
return;
break;
default:
F_29 () ;
V_254 = V_255 = 0 ;
break;
}
F_162 ( V_2 , V_181 , V_254 , V_255 ) ;
}
STATIC void
F_139 (
T_2 * V_2 ,
T_14 V_222 ,
int V_256 )
{
F_15 ( & V_2 -> V_122 ) ;
F_142 ( V_2 , V_222 , V_256 ) ;
F_17 ( & V_2 -> V_122 ) ;
}
int
F_167 (
T_2 * V_2 ,
T_14 V_181 ,
T_15 V_182 ,
int V_183 )
{
T_18 * V_249 ;
long long V_185 ;
int V_260 = 0 ;
F_168 () ;
V_261:
F_169 () ;
V_249 = F_170 ( V_2 -> V_234 ) ;
if ( F_91 ( F_160 ( V_2 , V_181 ) ) )
goto V_262;
F_152 ( V_249 ) ;
if ( F_91 ( F_160 ( V_2 , V_181 ) ) ) {
F_155 ( V_249 ) ;
goto V_262;
}
switch ( V_181 ) {
case V_188 :
V_185 = V_249 -> V_241 ;
V_185 += V_182 ;
if ( F_91 ( V_185 < 0 ) )
goto V_263;
V_249 -> V_241 = V_185 ;
break;
case V_190 :
V_185 = V_249 -> V_242 ;
V_185 += V_182 ;
if ( F_91 ( V_185 < 0 ) )
goto V_263;
V_249 -> V_242 = V_185 ;
break;
case V_192 :
F_171 ( ( V_2 -> V_194 - V_2 -> V_195 ) != 0 ) ;
V_185 = V_249 -> V_243 - F_123 ( V_2 ) ;
V_185 += V_182 ;
if ( F_91 ( V_185 < 0 ) )
goto V_263;
V_249 -> V_243 = V_185 + F_123 ( V_2 ) ;
break;
default:
F_29 () ;
break;
}
F_155 ( V_249 ) ;
F_172 () ;
return 0 ;
V_262:
F_172 () ;
F_138 ( V_2 ) ;
if ( ! ( F_160 ( V_2 , V_181 ) ) ) {
F_140 ( V_2 ) ;
goto V_261;
}
F_15 ( & V_2 -> V_122 ) ;
V_260 = F_122 ( V_2 , V_181 , V_182 , V_183 ) ;
F_17 ( & V_2 -> V_122 ) ;
if ( V_260 != V_196 )
F_139 ( V_2 , V_181 , 0 ) ;
F_140 ( V_2 ) ;
return V_260 ;
V_263:
F_155 ( V_249 ) ;
F_172 () ;
F_138 ( V_2 ) ;
F_139 ( V_2 , V_181 , V_182 ) ;
F_140 ( V_2 ) ;
goto V_261;
}
