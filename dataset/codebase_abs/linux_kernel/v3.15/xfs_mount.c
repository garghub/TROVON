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
F_39 ( & V_2 -> V_4 , F_40 ( V_62 ) ) ;
F_41 ( & V_2 -> V_4 ) ;
if ( V_60 > V_25 -> V_77 ) {
if ( V_64 )
F_3 ( V_2 , L_5 ,
V_60 , V_25 -> V_77 ) ;
error = V_78 ;
goto V_76;
}
if ( V_67 == NULL ) {
F_42 ( V_62 ) ;
V_60 = V_25 -> V_77 ;
V_67 = V_64 ? & V_79 : & V_80 ;
goto V_70;
}
F_43 ( V_2 ) ;
V_62 -> V_81 = & V_79 ;
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
if ( V_2 -> V_82 ) {
if ( ( F_46 ( V_2 -> V_82 ) & V_2 -> V_83 ) ||
( F_46 ( V_2 -> V_84 ) & V_2 -> V_83 ) ) {
F_3 ( V_2 ,
L_6 ,
V_25 -> V_85 ) ;
return F_4 ( V_10 ) ;
} else {
V_2 -> V_82 = F_47 ( V_2 , V_2 -> V_82 ) ;
if ( V_2 -> V_82 && ( V_25 -> V_55 % V_2 -> V_82 ) ) {
F_3 ( V_2 ,
L_7 ,
V_25 -> V_55 ) ;
return F_4 ( V_10 ) ;
} else if ( V_2 -> V_82 ) {
V_2 -> V_84 = F_47 ( V_2 , V_2 -> V_84 ) ;
} else {
F_3 ( V_2 ,
L_8 ,
V_2 -> V_82 , V_25 -> V_85 ) ;
return F_4 ( V_10 ) ;
}
}
if ( F_48 ( V_25 ) ) {
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
L_9 ) ;
return F_4 ( V_10 ) ;
}
} else if ( ( V_2 -> V_8 & V_91 ) != V_91 &&
F_48 ( & V_2 -> V_4 ) ) {
V_2 -> V_82 = V_25 -> V_86 ;
V_2 -> V_84 = V_25 -> V_89 ;
}
return 0 ;
}
STATIC void
F_49 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_5 V_92 ;
if ( V_25 -> V_93 ) {
V_92 = V_25 -> V_94 * V_25 -> V_93 ;
F_50 ( V_92 , 100 ) ;
F_50 ( V_92 , V_2 -> V_95 ) ;
V_2 -> V_96 = ( V_92 * V_2 -> V_95 ) <<
V_25 -> V_97 ;
} else {
V_2 -> V_96 = 0 ;
}
}
STATIC void
F_51 ( T_2 * V_2 )
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
F_52 (
struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_110 ; V_7 ++ ) {
T_5 V_111 = V_2 -> V_4 . V_94 ;
F_50 ( V_111 , 100 ) ;
V_2 -> V_112 [ V_7 ] = V_111 * ( V_7 + 1 ) ;
}
}
STATIC void
F_53 ( T_2 * V_2 )
{
if ( F_54 ( & V_2 -> V_4 ) &&
V_2 -> V_4 . V_113 >=
F_55 ( V_2 , V_2 -> V_114 ) )
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
F_56 ( T_2 * V_2 )
{
T_9 * V_62 ;
T_10 V_117 ;
V_117 = ( T_10 ) F_57 ( V_2 , V_2 -> V_4 . V_94 ) ;
if ( F_58 ( V_2 , V_117 ) != V_2 -> V_4 . V_94 ) {
F_3 ( V_2 , L_10 ) ;
return F_4 ( V_33 ) ;
}
V_62 = F_37 ( V_2 -> V_69 ,
V_117 - F_59 ( V_2 , 1 ) ,
F_59 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_62 ) {
F_3 ( V_2 , L_11 ) ;
return V_72 ;
}
F_42 ( V_62 ) ;
if ( V_2 -> V_118 != V_2 -> V_69 ) {
V_117 = ( T_10 ) F_57 ( V_2 , V_2 -> V_4 . V_119 ) ;
if ( F_58 ( V_2 , V_117 ) != V_2 -> V_4 . V_119 ) {
F_3 ( V_2 , L_12 ) ;
return F_4 ( V_33 ) ;
}
V_62 = F_37 ( V_2 -> V_118 ,
V_117 - F_57 ( V_2 , 1 ) ,
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
struct V_120 * V_121 ;
V_2 -> V_122 = 0 ;
if ( V_2 -> V_4 . V_123 == 0 )
return 0 ;
F_15 ( & V_2 -> V_124 ) ;
V_2 -> V_4 . V_123 = 0 ;
F_17 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_8 & V_125 )
return 0 ;
V_121 = F_61 ( V_2 , V_126 ) ;
error = F_62 ( V_121 , & F_63 ( V_2 ) -> V_127 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_121 , 0 ) ;
F_65 ( V_2 , L_14 , V_128 ) ;
return error ;
}
F_66 ( V_121 , V_129 ) ;
return F_67 ( V_121 , 0 ) ;
}
T_5
F_68 ( T_2 * V_2 )
{
T_5 V_130 ;
V_130 = V_2 -> V_4 . V_94 ;
F_50 ( V_130 , 20 ) ;
V_130 = F_69 ( T_5 , V_130 , 8192 ) ;
return V_130 ;
}
int
F_70 (
T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_11 * V_131 ;
T_5 V_130 ;
T_12 V_132 = 0 ;
T_12 V_133 = 0 ;
int error = 0 ;
F_71 ( V_2 , V_25 ) ;
if ( F_72 ( V_25 ) ) {
F_3 ( V_2 , L_15 ) ;
V_25 -> V_134 |= V_25 -> V_135 ;
V_25 -> V_135 = V_25 -> V_134 ;
V_2 -> V_87 |= V_136 | V_137 ;
if ( F_73 ( & V_2 -> V_4 ) &&
! ( V_2 -> V_8 & V_138 ) )
V_2 -> V_8 |= V_139 ;
}
if ( F_73 ( & V_2 -> V_4 ) &&
( V_2 -> V_8 & V_138 ) ) {
F_74 ( & V_2 -> V_4 ) ;
V_2 -> V_87 |= V_136 ;
if ( ! V_25 -> V_134 )
V_2 -> V_87 |= V_140 ;
}
error = F_45 ( V_2 ) ;
if ( error )
goto V_141;
F_75 ( V_2 ) ;
F_76 ( V_2 , V_142 ) ;
F_76 ( V_2 , V_143 ) ;
F_77 ( V_2 ) ;
F_49 ( V_2 ) ;
error = F_1 ( V_2 ) ;
if ( error )
goto V_141;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_114 = V_144 ;
if ( F_78 ( & V_2 -> V_4 ) ) {
int V_145 = V_2 -> V_114 ;
V_145 *= V_2 -> V_4 . V_146 / V_147 ;
if ( V_2 -> V_4 . V_113 >= F_55 ( V_2 , V_145 ) )
V_2 -> V_114 = V_145 ;
}
F_53 ( V_2 ) ;
error = F_56 ( V_2 ) ;
if ( error )
goto V_148;
error = F_79 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_16 ) ;
goto V_148;
}
F_80 ( & V_25 -> V_5 , V_2 -> V_149 ) ;
V_2 -> V_150 = 0 ;
F_81 ( V_2 ) ;
V_2 -> V_151 = ( V_2 -> V_4 . V_85 * 37 ) / 100 ;
F_82 ( V_2 ) ;
F_24 ( & V_2 -> V_23 ) ;
F_26 ( & V_2 -> V_24 , V_49 ) ;
error = F_20 ( V_2 , V_25 -> V_22 , & V_2 -> V_152 ) ;
if ( error ) {
F_3 ( V_2 , L_17 , error ) ;
goto V_148;
}
if ( ! V_25 -> V_119 ) {
F_3 ( V_2 , L_18 ) ;
F_83 ( L_19 , V_153 , V_2 ) ;
error = F_4 ( V_75 ) ;
goto V_154;
}
error = F_84 ( V_2 , V_2 -> V_118 ,
F_85 ( V_2 , V_25 -> V_155 ) ,
F_57 ( V_2 , V_25 -> V_119 ) ) ;
if ( error ) {
F_3 ( V_2 , L_20 ) ;
goto V_156;
}
if ( F_86 ( & V_2 -> V_4 ) &&
! F_87 ( V_2 ) &&
! V_2 -> V_4 . V_157 ) {
error = F_88 ( V_2 , V_25 -> V_22 ) ;
if ( error )
goto V_156;
}
error = F_89 ( V_2 , NULL , V_25 -> V_158 , 0 , V_159 , & V_131 ) ;
if ( error ) {
F_3 ( V_2 , L_21 ) ;
goto V_160;
}
ASSERT ( V_131 != NULL ) ;
if ( F_90 ( ! F_91 ( V_131 -> V_161 . V_162 ) ) ) {
F_3 ( V_2 , L_22 ,
( unsigned long long ) V_131 -> V_163 ) ;
F_92 ( V_131 , V_159 ) ;
F_83 ( L_23 , V_153 ,
V_2 ) ;
error = F_4 ( V_75 ) ;
goto V_164;
}
V_2 -> V_165 = V_131 ;
F_92 ( V_131 , V_159 ) ;
error = F_93 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_24 ) ;
goto V_164;
}
if ( V_2 -> V_87 && ! ( V_2 -> V_8 & V_125 ) ) {
error = F_94 ( V_2 , V_2 -> V_87 ) ;
if ( error ) {
F_3 ( V_2 , L_25 ) ;
goto V_166;
}
}
if ( F_95 ( V_2 ) ) {
error = F_96 ( V_2 , & V_132 , & V_133 ) ;
if ( error )
goto V_166;
} else {
ASSERT ( ! F_97 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_123 & V_167 ) {
F_98 ( V_2 , L_26 ) ;
error = F_60 ( V_2 ) ;
if ( error )
return error ;
}
}
error = F_99 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_27 ) ;
goto V_166;
}
if ( V_132 ) {
ASSERT ( V_2 -> V_122 == 0 ) ;
V_2 -> V_122 = V_133 ;
F_100 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_125 ) ) {
V_130 = F_68 ( V_2 ) ;
error = F_101 ( V_2 , & V_130 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_28 ) ;
}
return 0 ;
V_166:
F_102 ( V_2 ) ;
V_164:
F_103 ( V_131 ) ;
V_160:
F_104 ( V_2 ) ;
V_156:
if ( V_2 -> V_118 && V_2 -> V_118 != V_2 -> V_69 )
F_105 ( V_2 -> V_118 ) ;
F_105 ( V_2 -> V_69 ) ;
V_154:
F_14 ( V_2 ) ;
V_148:
F_9 ( V_2 ) ;
V_141:
return error ;
}
void
F_106 (
struct V_1 * V_2 )
{
T_5 V_130 ;
int error ;
F_107 ( & V_2 -> V_168 ) ;
F_108 ( V_2 ) ;
F_102 ( V_2 ) ;
F_103 ( V_2 -> V_165 ) ;
F_109 ( V_2 , V_169 ) ;
F_110 ( V_2 -> V_170 ) ;
F_107 ( & V_2 -> V_171 ) ;
F_111 ( V_2 , V_172 ) ;
F_112 ( V_2 ) ;
V_130 = 0 ;
error = F_101 ( V_2 , & V_130 , NULL ) ;
if ( error )
F_3 ( V_2 , L_29
L_30 ) ;
error = F_113 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_31
L_30 ) ;
F_104 ( V_2 ) ;
F_9 ( V_2 ) ;
#if F_114 ( V_173 )
F_115 ( V_2 , 0 ) ;
#endif
F_14 ( V_2 ) ;
}
int
F_116 ( T_2 * V_2 )
{
return ! ( V_2 -> V_174 -> V_175 . V_176 || F_117 ( V_2 ) ||
( V_2 -> V_8 & V_125 ) ) ;
}
int
F_113 ( T_2 * V_2 )
{
T_13 * V_121 ;
int error ;
if ( ! F_116 ( V_2 ) )
return 0 ;
F_118 ( V_2 , 0 ) ;
if ( ! F_86 ( & V_2 -> V_4 ) )
return 0 ;
V_121 = F_119 ( V_2 , V_177 , V_15 ) ;
error = F_62 ( V_121 , & F_63 ( V_2 ) -> V_178 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_121 , 0 ) ;
return error ;
}
F_66 ( V_121 , V_179 | V_180 | V_181 ) ;
F_120 ( V_121 ) ;
error = F_67 ( V_121 , 0 ) ;
return error ;
}
STATIC int
F_121 (
T_2 * V_2 ,
T_14 V_182 ,
T_15 V_183 ,
int V_184 )
{
int V_185 ;
long long V_186 ;
long long V_187 , V_188 ;
switch ( V_182 ) {
case V_189 :
V_186 = ( long long ) V_2 -> V_4 . V_190 ;
V_186 += V_183 ;
if ( V_186 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_190 = V_186 ;
return 0 ;
case V_191 :
V_186 = ( long long ) V_2 -> V_4 . V_192 ;
V_186 += V_183 ;
if ( V_186 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_192 = V_186 ;
return 0 ;
case V_193 :
V_186 = ( long long )
V_2 -> V_4 . V_194 - F_122 ( V_2 ) ;
V_187 = ( long long ) ( V_2 -> V_195 - V_2 -> V_196 ) ;
if ( V_183 > 0 ) {
if ( V_187 > V_183 ) {
V_2 -> V_196 += V_183 ;
} else {
V_188 = V_183 - V_187 ;
V_2 -> V_196 = V_2 -> V_195 ;
V_186 += V_188 ;
}
} else {
V_186 += V_183 ;
if ( V_186 >= 0 ) {
V_2 -> V_4 . V_194 = V_186 +
F_122 ( V_2 ) ;
return 0 ;
}
if ( ! V_184 )
return F_4 ( V_197 ) ;
V_186 = ( long long ) V_2 -> V_196 + V_183 ;
if ( V_186 >= 0 ) {
V_2 -> V_196 = V_186 ;
return 0 ;
}
F_123 ( V_198
L_32
L_33 ,
V_2 -> V_199 ) ;
return F_4 ( V_197 ) ;
}
V_2 -> V_4 . V_194 = V_186 + F_122 ( V_2 ) ;
return 0 ;
case V_200 :
V_186 = ( long long ) V_2 -> V_4 . V_201 ;
V_186 += V_183 ;
if ( V_186 < 0 ) {
return F_4 ( V_197 ) ;
}
V_2 -> V_4 . V_201 = V_186 ;
return 0 ;
case V_202 :
V_186 = ( long long ) V_2 -> V_4 . V_94 ;
V_186 += V_183 ;
if ( V_186 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_94 = V_186 ;
return 0 ;
case V_203 :
V_185 = V_2 -> V_4 . V_22 ;
V_185 += V_183 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_22 = V_185 ;
return 0 ;
case V_204 :
V_185 = V_2 -> V_4 . V_93 ;
V_185 += V_183 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_93 = V_185 ;
return 0 ;
case V_205 :
V_185 = V_2 -> V_4 . V_206 ;
V_185 += V_183 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_206 = V_185 ;
return 0 ;
case V_207 :
V_185 = V_2 -> V_4 . V_208 ;
V_185 += V_183 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_208 = V_185 ;
return 0 ;
case V_209 :
V_186 = ( long long ) V_2 -> V_4 . V_210 ;
V_186 += V_183 ;
if ( V_186 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_210 = V_186 ;
return 0 ;
case V_211 :
V_186 = ( long long ) V_2 -> V_4 . V_212 ;
V_186 += V_183 ;
if ( V_186 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_212 = V_186 ;
return 0 ;
case V_213 :
V_185 = V_2 -> V_4 . V_214 ;
V_185 += V_183 ;
if ( V_185 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_214 = V_185 ;
return 0 ;
default:
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
}
int
F_124 (
struct V_1 * V_2 ,
T_14 V_182 ,
T_15 V_183 ,
int V_184 )
{
int V_215 ;
#ifdef F_125
ASSERT ( V_182 < V_189 || V_182 > V_193 ) ;
#endif
F_15 ( & V_2 -> V_124 ) ;
V_215 = F_121 ( V_2 , V_182 , V_183 , V_184 ) ;
F_17 ( & V_2 -> V_124 ) ;
return V_215 ;
}
int
F_126 (
struct V_1 * V_2 ,
T_16 * V_216 ,
T_12 V_217 ,
int V_184 )
{
T_16 * V_218 ;
int error = 0 ;
F_15 ( & V_2 -> V_124 ) ;
for ( V_218 = V_216 ; V_218 < ( V_216 + V_217 ) ; V_218 ++ ) {
ASSERT ( V_218 -> V_219 < V_189 ||
V_218 -> V_219 > V_193 ) ;
error = F_121 ( V_2 , V_218 -> V_219 ,
V_218 -> V_220 , V_184 ) ;
if ( error )
goto V_221;
}
F_17 ( & V_2 -> V_124 ) ;
return 0 ;
V_221:
while ( -- V_218 >= V_216 ) {
error = F_121 ( V_2 , V_218 -> V_219 ,
- V_218 -> V_220 , V_184 ) ;
ASSERT ( error == 0 ) ;
}
F_17 ( & V_2 -> V_124 ) ;
return error ;
}
struct V_61 *
F_127 (
struct V_1 * V_2 ,
int V_59 )
{
struct V_61 * V_62 = V_2 -> V_68 ;
if ( ! F_128 ( V_62 ) ) {
if ( V_59 & V_222 )
return NULL ;
F_129 ( V_62 ) ;
}
F_130 ( V_62 ) ;
ASSERT ( F_131 ( V_62 ) ) ;
return V_62 ;
}
void
F_132 (
struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_68 ;
F_129 ( V_62 ) ;
V_2 -> V_68 = NULL ;
F_42 ( V_62 ) ;
}
int
F_94 (
T_2 * V_2 ,
T_17 V_223 )
{
T_13 * V_121 ;
int error ;
ASSERT ( V_223 & ( V_88 | V_90 | V_224 |
V_136 | V_137 |
V_140 ) ) ;
V_121 = F_61 ( V_2 , V_225 ) ;
error = F_62 ( V_121 , & F_63 ( V_2 ) -> V_178 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_121 , 0 ) ;
return error ;
}
F_66 ( V_121 , V_223 ) ;
error = F_67 ( V_121 , 0 ) ;
return error ;
}
int
F_133 (
struct V_1 * V_2 ,
char * V_226 )
{
if ( F_134 ( V_2 -> V_69 ) ||
F_134 ( V_2 -> V_118 ) ||
( V_2 -> V_227 && F_134 ( V_2 -> V_227 ) ) ) {
F_98 ( V_2 , L_34 , V_226 ) ;
F_98 ( V_2 , L_35 ) ;
return V_228 ;
}
return 0 ;
}
STATIC int
F_135 (
struct V_229 * V_230 ,
unsigned long V_231 ,
void * V_232 )
{
T_18 * V_233 ;
T_2 * V_2 ;
V_2 = ( T_2 * ) F_11 ( V_230 , T_2 , V_234 ) ;
V_233 = ( T_18 * )
F_136 ( V_2 -> V_235 , ( unsigned long ) V_232 ) ;
switch ( V_231 ) {
case V_236 :
case V_237 :
memset ( V_233 , 0 , sizeof( T_18 ) ) ;
break;
case V_238 :
case V_239 :
F_137 ( V_2 ) ;
F_138 ( V_2 , V_189 , 0 ) ;
F_138 ( V_2 , V_191 , 0 ) ;
F_138 ( V_2 , V_193 , 0 ) ;
F_139 ( V_2 ) ;
break;
case V_240 :
case V_241 :
F_137 ( V_2 ) ;
F_15 ( & V_2 -> V_124 ) ;
F_140 ( V_2 , V_189 ) ;
F_140 ( V_2 , V_191 ) ;
F_140 ( V_2 , V_193 ) ;
V_2 -> V_4 . V_190 += V_233 -> V_242 ;
V_2 -> V_4 . V_192 += V_233 -> V_243 ;
V_2 -> V_4 . V_194 += V_233 -> V_244 ;
memset ( V_233 , 0 , sizeof( T_18 ) ) ;
F_141 ( V_2 , V_189 , 0 ) ;
F_141 ( V_2 , V_191 , 0 ) ;
F_141 ( V_2 , V_193 , 0 ) ;
F_17 ( & V_2 -> V_124 ) ;
F_139 ( V_2 ) ;
break;
}
return V_245 ;
}
int
F_142 (
T_2 * V_2 )
{
T_18 * V_233 ;
int V_7 ;
V_2 -> V_235 = F_143 ( T_18 ) ;
if ( V_2 -> V_235 == NULL )
return - V_41 ;
F_144 (i) {
V_233 = ( T_18 * ) F_136 ( V_2 -> V_235 , V_7 ) ;
memset ( V_233 , 0 , sizeof( T_18 ) ) ;
}
F_25 ( & V_2 -> V_246 ) ;
V_2 -> V_247 = - 1 ;
#ifdef F_145
V_2 -> V_234 . V_248 = F_135 ;
V_2 -> V_234 . V_249 = 0 ;
F_146 ( & V_2 -> V_234 ) ;
#endif
return 0 ;
}
void
F_43 (
T_2 * V_2 )
{
F_137 ( V_2 ) ;
V_2 -> V_247 = - 1 ;
F_138 ( V_2 , V_189 , 0 ) ;
F_138 ( V_2 , V_191 , 0 ) ;
F_138 ( V_2 , V_193 , 0 ) ;
F_139 ( V_2 ) ;
}
void
F_147 (
T_2 * V_2 )
{
if ( V_2 -> V_235 ) {
F_148 ( & V_2 -> V_234 ) ;
F_149 ( V_2 -> V_235 ) ;
}
F_150 ( & V_2 -> V_246 ) ;
}
STATIC void
F_151 (
T_18 * V_250 )
{
while ( F_152 ( V_251 , & V_250 -> V_252 ) ) {
F_153 ( 1000 ) ;
}
}
STATIC void
F_154 (
T_18 * V_250 )
{
F_155 ( V_251 , & V_250 -> V_252 ) ;
}
STATIC void
F_156 (
T_2 * V_2 )
{
T_18 * V_233 ;
int V_7 ;
F_144 (i) {
V_233 = ( T_18 * ) F_136 ( V_2 -> V_235 , V_7 ) ;
F_151 ( V_233 ) ;
}
}
STATIC void
F_157 (
T_2 * V_2 )
{
T_18 * V_233 ;
int V_7 ;
F_144 (i) {
V_233 = ( T_18 * ) F_136 ( V_2 -> V_235 , V_7 ) ;
F_154 ( V_233 ) ;
}
}
STATIC void
F_158 (
T_2 * V_2 ,
T_18 * V_253 ,
int V_59 )
{
T_18 * V_233 ;
int V_7 ;
memset ( V_253 , 0 , sizeof( T_18 ) ) ;
if ( ! ( V_59 & V_254 ) )
F_156 ( V_2 ) ;
F_144 (i) {
V_233 = ( T_18 * ) F_136 ( V_2 -> V_235 , V_7 ) ;
V_253 -> V_242 += V_233 -> V_242 ;
V_253 -> V_243 += V_233 -> V_243 ;
V_253 -> V_244 += V_233 -> V_244 ;
}
if ( ! ( V_59 & V_254 ) )
F_157 ( V_2 ) ;
}
STATIC int
F_159 (
T_2 * V_2 ,
T_14 V_182 )
{
ASSERT ( ( V_182 >= V_189 ) && ( V_182 <= V_193 ) ) ;
return F_160 ( V_182 , & V_2 -> V_247 ) ;
}
STATIC void
F_140 (
T_2 * V_2 ,
T_14 V_182 )
{
T_18 V_253 ;
ASSERT ( ( V_182 >= V_189 ) && ( V_182 <= V_193 ) ) ;
if ( F_159 ( V_2 , V_182 ) )
return;
F_156 ( V_2 ) ;
if ( ! F_152 ( V_182 , & V_2 -> V_247 ) ) {
F_158 ( V_2 , & V_253 , V_254 ) ;
switch( V_182 ) {
case V_189 :
V_2 -> V_4 . V_190 = V_253 . V_242 ;
break;
case V_191 :
V_2 -> V_4 . V_192 = V_253 . V_243 ;
break;
case V_193 :
V_2 -> V_4 . V_194 = V_253 . V_244 ;
break;
default:
F_29 () ;
}
}
F_157 ( V_2 ) ;
}
STATIC void
F_161 (
T_2 * V_2 ,
T_14 V_182 ,
T_19 V_255 ,
T_19 V_256 )
{
T_18 * V_233 ;
int V_7 ;
ASSERT ( ( V_182 >= V_189 ) && ( V_182 <= V_193 ) ) ;
F_156 ( V_2 ) ;
F_144 (i) {
V_233 = F_136 ( V_2 -> V_235 , V_7 ) ;
switch ( V_182 ) {
case V_189 :
V_233 -> V_242 = V_255 + V_256 ;
break;
case V_191 :
V_233 -> V_243 = V_255 + V_256 ;
break;
case V_193 :
V_233 -> V_244 = V_255 + V_256 ;
break;
default:
F_29 () ;
break;
}
V_256 = 0 ;
}
F_155 ( V_182 , & V_2 -> V_247 ) ;
F_157 ( V_2 ) ;
}
void
F_162 (
T_2 * V_2 ,
int V_59 )
{
T_18 V_253 ;
F_158 ( V_2 , & V_253 , V_59 ) ;
if ( ! F_159 ( V_2 , V_189 ) )
V_2 -> V_4 . V_190 = V_253 . V_242 ;
if ( ! F_159 ( V_2 , V_191 ) )
V_2 -> V_4 . V_192 = V_253 . V_243 ;
if ( ! F_159 ( V_2 , V_193 ) )
V_2 -> V_4 . V_194 = V_253 . V_244 ;
}
void
F_118 (
T_2 * V_2 ,
int V_59 )
{
F_15 ( & V_2 -> V_124 ) ;
F_162 ( V_2 , V_59 ) ;
F_17 ( & V_2 -> V_124 ) ;
}
STATIC void
F_141 (
T_2 * V_2 ,
T_14 V_182 ,
int V_257 )
{
T_19 V_255 , V_256 ;
int V_258 = F_163 () ;
T_19 V_259 = ( T_19 ) V_257 ;
F_140 ( V_2 , V_182 ) ;
switch ( V_182 ) {
case V_189 :
V_255 = V_2 -> V_4 . V_190 ;
V_256 = F_50 ( V_255 , V_258 ) ;
if ( V_255 < F_164 ( V_259 , V_260 ) )
return;
break;
case V_191 :
V_255 = V_2 -> V_4 . V_192 ;
V_256 = F_50 ( V_255 , V_258 ) ;
if ( V_255 < F_164 ( V_259 , V_260 ) )
return;
break;
case V_193 :
V_255 = V_2 -> V_4 . V_194 ;
V_256 = F_50 ( V_255 , V_258 ) ;
if ( V_255 < F_164 ( V_259 , F_165 ( V_2 ) ) )
return;
break;
default:
F_29 () ;
V_255 = V_256 = 0 ;
break;
}
F_161 ( V_2 , V_182 , V_255 , V_256 ) ;
}
STATIC void
F_138 (
T_2 * V_2 ,
T_14 V_223 ,
int V_257 )
{
F_15 ( & V_2 -> V_124 ) ;
F_141 ( V_2 , V_223 , V_257 ) ;
F_17 ( & V_2 -> V_124 ) ;
}
int
F_166 (
T_2 * V_2 ,
T_14 V_182 ,
T_15 V_183 ,
int V_184 )
{
T_18 * V_250 ;
long long V_186 ;
int V_261 = 0 ;
F_167 () ;
V_262:
F_168 () ;
V_250 = F_169 ( V_2 -> V_235 ) ;
if ( F_90 ( F_159 ( V_2 , V_182 ) ) )
goto V_263;
F_151 ( V_250 ) ;
if ( F_90 ( F_159 ( V_2 , V_182 ) ) ) {
F_154 ( V_250 ) ;
goto V_263;
}
switch ( V_182 ) {
case V_189 :
V_186 = V_250 -> V_242 ;
V_186 += V_183 ;
if ( F_90 ( V_186 < 0 ) )
goto V_264;
V_250 -> V_242 = V_186 ;
break;
case V_191 :
V_186 = V_250 -> V_243 ;
V_186 += V_183 ;
if ( F_90 ( V_186 < 0 ) )
goto V_264;
V_250 -> V_243 = V_186 ;
break;
case V_193 :
F_170 ( ( V_2 -> V_195 - V_2 -> V_196 ) != 0 ) ;
V_186 = V_250 -> V_244 - F_122 ( V_2 ) ;
V_186 += V_183 ;
if ( F_90 ( V_186 < 0 ) )
goto V_264;
V_250 -> V_244 = V_186 + F_122 ( V_2 ) ;
break;
default:
F_29 () ;
break;
}
F_154 ( V_250 ) ;
F_171 () ;
return 0 ;
V_263:
F_171 () ;
F_137 ( V_2 ) ;
if ( ! ( F_159 ( V_2 , V_182 ) ) ) {
F_139 ( V_2 ) ;
goto V_262;
}
F_15 ( & V_2 -> V_124 ) ;
V_261 = F_121 ( V_2 , V_182 , V_183 , V_184 ) ;
F_17 ( & V_2 -> V_124 ) ;
if ( V_261 != V_197 )
F_138 ( V_2 , V_182 , 0 ) ;
F_139 ( V_2 ) ;
return V_261 ;
V_264:
F_154 ( V_250 ) ;
F_171 () ;
F_137 ( V_2 ) ;
F_138 ( V_2 , V_182 , V_183 ) ;
F_139 ( V_2 ) ;
goto V_262;
}
