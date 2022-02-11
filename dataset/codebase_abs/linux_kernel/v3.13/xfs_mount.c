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
ASSERT ( V_2 -> V_66 == NULL ) ;
ASSERT ( V_2 -> V_67 != NULL ) ;
V_60 = F_36 ( V_2 -> V_67 ) ;
V_68:
V_62 = F_37 ( V_2 -> V_67 , V_69 ,
F_38 ( V_60 ) , 0 ,
V_64 ? & V_70
: & V_71 ) ;
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
if ( V_60 < V_25 -> V_75 ) {
F_42 ( V_62 ) ;
V_60 = V_25 -> V_75 ;
goto V_68;
}
F_43 ( V_2 ) ;
V_62 -> V_77 = & V_70 ;
V_2 -> V_66 = V_62 ;
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
if ( V_2 -> V_78 ) {
if ( ( F_46 ( V_2 -> V_78 ) & V_2 -> V_79 ) ||
( F_46 ( V_2 -> V_80 ) & V_2 -> V_79 ) ) {
F_3 ( V_2 ,
L_6 ,
V_25 -> V_81 ) ;
return F_4 ( V_10 ) ;
} else {
V_2 -> V_78 = F_47 ( V_2 , V_2 -> V_78 ) ;
if ( V_2 -> V_78 && ( V_25 -> V_55 % V_2 -> V_78 ) ) {
F_3 ( V_2 ,
L_7 ,
V_25 -> V_55 ) ;
return F_4 ( V_10 ) ;
} else if ( V_2 -> V_78 ) {
V_2 -> V_80 = F_47 ( V_2 , V_2 -> V_80 ) ;
} else {
F_3 ( V_2 ,
L_8 ,
V_2 -> V_78 , V_25 -> V_81 ) ;
return F_4 ( V_10 ) ;
}
}
if ( F_48 ( V_25 ) ) {
if ( V_25 -> V_82 != V_2 -> V_78 ) {
V_25 -> V_82 = V_2 -> V_78 ;
V_2 -> V_83 |= V_84 ;
}
if ( V_25 -> V_85 != V_2 -> V_80 ) {
V_25 -> V_85 = V_2 -> V_80 ;
V_2 -> V_83 |= V_86 ;
}
} else {
F_3 ( V_2 ,
L_9 ) ;
return F_4 ( V_10 ) ;
}
} else if ( ( V_2 -> V_8 & V_87 ) != V_87 &&
F_48 ( & V_2 -> V_4 ) ) {
V_2 -> V_78 = V_25 -> V_82 ;
V_2 -> V_80 = V_25 -> V_85 ;
}
return 0 ;
}
STATIC void
F_49 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_5 V_88 ;
if ( V_25 -> V_89 ) {
V_88 = V_25 -> V_90 * V_25 -> V_89 ;
F_50 ( V_88 , 100 ) ;
F_50 ( V_88 , V_2 -> V_91 ) ;
V_2 -> V_92 = ( V_88 * V_2 -> V_91 ) <<
V_25 -> V_93 ;
} else {
V_2 -> V_92 = 0 ;
}
}
STATIC void
F_51 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
int V_94 , V_95 ;
if ( ! ( V_2 -> V_8 & V_96 ) ) {
if ( V_2 -> V_8 & V_97 ) {
V_94 = V_98 ;
V_95 = V_99 ;
} else {
V_94 = V_100 ;
V_95 = V_101 ;
}
} else {
V_94 = V_2 -> V_102 ;
V_95 = V_2 -> V_103 ;
}
if ( V_25 -> V_28 > V_94 ) {
V_2 -> V_102 = V_25 -> V_28 ;
} else {
V_2 -> V_102 = V_94 ;
}
V_2 -> V_104 = 1 << ( V_2 -> V_102 - V_25 -> V_28 ) ;
if ( V_25 -> V_28 > V_95 ) {
V_2 -> V_103 = V_25 -> V_28 ;
} else {
V_2 -> V_103 = V_95 ;
}
V_2 -> V_105 = 1 << ( V_2 -> V_103 - V_25 -> V_28 ) ;
}
void
F_52 (
struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_106 ; V_7 ++ ) {
T_5 V_107 = V_2 -> V_4 . V_90 ;
F_50 ( V_107 , 100 ) ;
V_2 -> V_108 [ V_7 ] = V_107 * ( V_7 + 1 ) ;
}
}
STATIC void
F_53 ( T_2 * V_2 )
{
if ( F_54 ( & V_2 -> V_4 ) &&
V_2 -> V_4 . V_109 >=
F_55 ( V_2 , V_2 -> V_110 ) )
V_2 -> V_111 = V_2 -> V_4 . V_109 - 1 ;
else
V_2 -> V_111 = 0 ;
if ( V_2 -> V_78 && V_2 -> V_111 &&
! ( V_2 -> V_78 & V_2 -> V_111 ) )
V_2 -> V_112 = V_2 -> V_78 ;
else
V_2 -> V_112 = 0 ;
}
STATIC int
F_56 ( T_2 * V_2 )
{
T_9 * V_62 ;
T_10 V_113 ;
V_113 = ( T_10 ) F_57 ( V_2 , V_2 -> V_4 . V_90 ) ;
if ( F_58 ( V_2 , V_113 ) != V_2 -> V_4 . V_90 ) {
F_3 ( V_2 , L_10 ) ;
return F_4 ( V_33 ) ;
}
V_62 = F_37 ( V_2 -> V_67 ,
V_113 - F_59 ( V_2 , 1 ) ,
F_59 ( V_2 , 1 ) , 0 , NULL ) ;
if ( ! V_62 ) {
F_3 ( V_2 , L_11 ) ;
return V_72 ;
}
F_42 ( V_62 ) ;
if ( V_2 -> V_114 != V_2 -> V_67 ) {
V_113 = ( T_10 ) F_57 ( V_2 , V_2 -> V_4 . V_115 ) ;
if ( F_58 ( V_2 , V_113 ) != V_2 -> V_4 . V_115 ) {
F_3 ( V_2 , L_12 ) ;
return F_4 ( V_33 ) ;
}
V_62 = F_37 ( V_2 -> V_114 ,
V_113 - F_57 ( V_2 , 1 ) ,
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
struct V_116 * V_117 ;
V_2 -> V_118 = 0 ;
if ( V_2 -> V_4 . V_119 == 0 )
return 0 ;
F_15 ( & V_2 -> V_120 ) ;
V_2 -> V_4 . V_119 = 0 ;
F_17 ( & V_2 -> V_120 ) ;
if ( V_2 -> V_8 & V_121 )
return 0 ;
V_117 = F_61 ( V_2 , V_122 ) ;
error = F_62 ( V_117 , & F_63 ( V_2 ) -> V_123 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_117 , 0 ) ;
F_65 ( V_2 , L_14 , V_124 ) ;
return error ;
}
F_66 ( V_117 , V_125 ) ;
return F_67 ( V_117 , 0 ) ;
}
T_5
F_68 ( T_2 * V_2 )
{
T_5 V_126 ;
V_126 = V_2 -> V_4 . V_90 ;
F_50 ( V_126 , 20 ) ;
V_126 = F_69 ( T_5 , V_126 , 8192 ) ;
return V_126 ;
}
int
F_70 (
T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_11 * V_127 ;
T_5 V_126 ;
T_12 V_128 = 0 ;
T_12 V_129 = 0 ;
int error = 0 ;
F_71 ( V_2 , V_25 ) ;
if ( F_72 ( V_25 ) ) {
F_3 ( V_2 , L_15 ) ;
V_25 -> V_130 |= V_25 -> V_131 ;
V_25 -> V_131 = V_25 -> V_130 ;
V_2 -> V_83 |= V_132 | V_133 ;
if ( F_73 ( & V_2 -> V_4 ) &&
! ( V_2 -> V_8 & V_134 ) )
V_2 -> V_8 |= V_135 ;
}
if ( F_73 ( & V_2 -> V_4 ) &&
( V_2 -> V_8 & V_134 ) ) {
F_74 ( & V_2 -> V_4 ) ;
V_2 -> V_83 |= V_132 ;
if ( ! V_25 -> V_130 )
V_2 -> V_83 |= V_136 ;
}
error = F_45 ( V_2 ) ;
if ( error )
goto V_137;
F_75 ( V_2 ) ;
F_76 ( V_2 , V_138 ) ;
F_76 ( V_2 , V_139 ) ;
F_77 ( V_2 ) ;
F_49 ( V_2 ) ;
error = F_1 ( V_2 ) ;
if ( error )
goto V_137;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_110 = V_140 ;
if ( F_78 ( & V_2 -> V_4 ) ) {
int V_141 = V_2 -> V_110 ;
V_141 *= V_2 -> V_4 . V_142 / V_143 ;
if ( V_2 -> V_4 . V_109 >= F_55 ( V_2 , V_141 ) )
V_2 -> V_110 = V_141 ;
F_79 ( V_2 , L_16 ,
V_2 -> V_110 ) ;
}
F_53 ( V_2 ) ;
error = F_56 ( V_2 ) ;
if ( error )
goto V_144;
error = F_80 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_17 ) ;
goto V_144;
}
F_81 ( & V_25 -> V_5 , V_2 -> V_145 ) ;
V_2 -> V_146 = 0 ;
F_82 ( V_2 ) ;
V_2 -> V_147 = ( V_2 -> V_4 . V_81 * 37 ) / 100 ;
F_83 ( V_2 ) ;
F_24 ( & V_2 -> V_23 ) ;
F_26 ( & V_2 -> V_24 , V_49 ) ;
error = F_20 ( V_2 , V_25 -> V_22 , & V_2 -> V_148 ) ;
if ( error ) {
F_3 ( V_2 , L_18 , error ) ;
goto V_144;
}
if ( ! V_25 -> V_115 ) {
F_3 ( V_2 , L_19 ) ;
F_84 ( L_20 , V_149 , V_2 ) ;
error = F_4 ( V_150 ) ;
goto V_151;
}
error = F_85 ( V_2 , V_2 -> V_114 ,
F_86 ( V_2 , V_25 -> V_152 ) ,
F_57 ( V_2 , V_25 -> V_115 ) ) ;
if ( error ) {
F_3 ( V_2 , L_21 ) ;
goto V_153;
}
if ( F_87 ( & V_2 -> V_4 ) &&
! F_88 ( V_2 ) &&
! V_2 -> V_4 . V_154 ) {
error = F_89 ( V_2 , V_25 -> V_22 ) ;
if ( error )
goto V_153;
}
error = F_90 ( V_2 , NULL , V_25 -> V_155 , 0 , V_156 , & V_127 ) ;
if ( error ) {
F_3 ( V_2 , L_22 ) ;
goto V_157;
}
ASSERT ( V_127 != NULL ) ;
if ( F_91 ( ! F_92 ( V_127 -> V_158 . V_159 ) ) ) {
F_3 ( V_2 , L_23 ,
( unsigned long long ) V_127 -> V_160 ) ;
F_93 ( V_127 , V_156 ) ;
F_84 ( L_24 , V_149 ,
V_2 ) ;
error = F_4 ( V_150 ) ;
goto V_161;
}
V_2 -> V_162 = V_127 ;
F_93 ( V_127 , V_156 ) ;
error = F_94 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_25 ) ;
goto V_161;
}
if ( V_2 -> V_83 && ! ( V_2 -> V_8 & V_121 ) ) {
error = F_95 ( V_2 , V_2 -> V_83 ) ;
if ( error ) {
F_3 ( V_2 , L_26 ) ;
goto V_163;
}
}
if ( F_96 ( V_2 ) ) {
error = F_97 ( V_2 , & V_128 , & V_129 ) ;
if ( error )
goto V_163;
} else {
ASSERT ( ! F_98 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_119 & V_164 ) {
F_99 ( V_2 , L_27 ) ;
error = F_60 ( V_2 ) ;
if ( error )
return error ;
}
}
error = F_100 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_28 ) ;
goto V_163;
}
if ( V_128 ) {
ASSERT ( V_2 -> V_118 == 0 ) ;
V_2 -> V_118 = V_129 ;
F_101 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_121 ) ) {
V_126 = F_68 ( V_2 ) ;
error = F_102 ( V_2 , & V_126 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_29 ) ;
}
return 0 ;
V_163:
F_103 ( V_2 ) ;
V_161:
F_104 ( V_127 ) ;
V_157:
F_105 ( V_2 ) ;
V_153:
if ( V_2 -> V_114 && V_2 -> V_114 != V_2 -> V_67 )
F_106 ( V_2 -> V_114 ) ;
F_106 ( V_2 -> V_67 ) ;
V_151:
F_14 ( V_2 ) ;
V_144:
F_9 ( V_2 ) ;
V_137:
return error ;
}
void
F_107 (
struct V_1 * V_2 )
{
T_5 V_126 ;
int error ;
F_108 ( & V_2 -> V_165 ) ;
F_109 ( V_2 ) ;
F_103 ( V_2 ) ;
F_104 ( V_2 -> V_162 ) ;
F_110 ( V_2 , V_166 ) ;
F_111 ( V_2 -> V_167 ) ;
F_108 ( & V_2 -> V_168 ) ;
F_112 ( V_2 , V_169 ) ;
F_113 ( V_2 ) ;
V_126 = 0 ;
error = F_102 ( V_2 , & V_126 , NULL ) ;
if ( error )
F_3 ( V_2 , L_30
L_31 ) ;
error = F_114 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_32
L_31 ) ;
F_105 ( V_2 ) ;
F_9 ( V_2 ) ;
#if F_115 ( V_170 )
F_116 ( V_2 , 0 ) ;
#endif
F_14 ( V_2 ) ;
}
int
F_117 ( T_2 * V_2 )
{
return ! ( V_2 -> V_171 -> V_172 . V_173 || F_118 ( V_2 ) ||
( V_2 -> V_8 & V_121 ) ) ;
}
int
F_114 ( T_2 * V_2 )
{
T_13 * V_117 ;
int error ;
if ( ! F_117 ( V_2 ) )
return 0 ;
F_119 ( V_2 , 0 ) ;
if ( ! F_87 ( & V_2 -> V_4 ) )
return 0 ;
V_117 = F_120 ( V_2 , V_174 , V_15 ) ;
error = F_62 ( V_117 , & F_63 ( V_2 ) -> V_175 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_117 , 0 ) ;
return error ;
}
F_66 ( V_117 , V_176 | V_177 | V_178 ) ;
F_121 ( V_117 ) ;
error = F_67 ( V_117 , 0 ) ;
return error ;
}
STATIC int
F_122 (
T_2 * V_2 ,
T_14 V_179 ,
T_15 V_180 ,
int V_181 )
{
int V_182 ;
long long V_183 ;
long long V_184 , V_185 ;
switch ( V_179 ) {
case V_186 :
V_183 = ( long long ) V_2 -> V_4 . V_187 ;
V_183 += V_180 ;
if ( V_183 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_187 = V_183 ;
return 0 ;
case V_188 :
V_183 = ( long long ) V_2 -> V_4 . V_189 ;
V_183 += V_180 ;
if ( V_183 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_189 = V_183 ;
return 0 ;
case V_190 :
V_183 = ( long long )
V_2 -> V_4 . V_191 - F_123 ( V_2 ) ;
V_184 = ( long long ) ( V_2 -> V_192 - V_2 -> V_193 ) ;
if ( V_180 > 0 ) {
if ( V_184 > V_180 ) {
V_2 -> V_193 += V_180 ;
} else {
V_185 = V_180 - V_184 ;
V_2 -> V_193 = V_2 -> V_192 ;
V_183 += V_185 ;
}
} else {
V_183 += V_180 ;
if ( V_183 >= 0 ) {
V_2 -> V_4 . V_191 = V_183 +
F_123 ( V_2 ) ;
return 0 ;
}
if ( ! V_181 )
return F_4 ( V_194 ) ;
V_183 = ( long long ) V_2 -> V_193 + V_180 ;
if ( V_183 >= 0 ) {
V_2 -> V_193 = V_183 ;
return 0 ;
}
F_124 ( V_195
L_33
L_34 ,
V_2 -> V_196 ) ;
return F_4 ( V_194 ) ;
}
V_2 -> V_4 . V_191 = V_183 + F_123 ( V_2 ) ;
return 0 ;
case V_197 :
V_183 = ( long long ) V_2 -> V_4 . V_198 ;
V_183 += V_180 ;
if ( V_183 < 0 ) {
return F_4 ( V_194 ) ;
}
V_2 -> V_4 . V_198 = V_183 ;
return 0 ;
case V_199 :
V_183 = ( long long ) V_2 -> V_4 . V_90 ;
V_183 += V_180 ;
if ( V_183 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_90 = V_183 ;
return 0 ;
case V_200 :
V_182 = V_2 -> V_4 . V_22 ;
V_182 += V_180 ;
if ( V_182 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_22 = V_182 ;
return 0 ;
case V_201 :
V_182 = V_2 -> V_4 . V_89 ;
V_182 += V_180 ;
if ( V_182 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_89 = V_182 ;
return 0 ;
case V_202 :
V_182 = V_2 -> V_4 . V_203 ;
V_182 += V_180 ;
if ( V_182 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_203 = V_182 ;
return 0 ;
case V_204 :
V_182 = V_2 -> V_4 . V_205 ;
V_182 += V_180 ;
if ( V_182 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_205 = V_182 ;
return 0 ;
case V_206 :
V_183 = ( long long ) V_2 -> V_4 . V_207 ;
V_183 += V_180 ;
if ( V_183 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_207 = V_183 ;
return 0 ;
case V_208 :
V_183 = ( long long ) V_2 -> V_4 . V_209 ;
V_183 += V_180 ;
if ( V_183 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_209 = V_183 ;
return 0 ;
case V_210 :
V_182 = V_2 -> V_4 . V_211 ;
V_182 += V_180 ;
if ( V_182 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_211 = V_182 ;
return 0 ;
default:
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
}
int
F_125 (
struct V_1 * V_2 ,
T_14 V_179 ,
T_15 V_180 ,
int V_181 )
{
int V_212 ;
#ifdef F_126
ASSERT ( V_179 < V_186 || V_179 > V_190 ) ;
#endif
F_15 ( & V_2 -> V_120 ) ;
V_212 = F_122 ( V_2 , V_179 , V_180 , V_181 ) ;
F_17 ( & V_2 -> V_120 ) ;
return V_212 ;
}
int
F_127 (
struct V_1 * V_2 ,
T_16 * V_213 ,
T_12 V_214 ,
int V_181 )
{
T_16 * V_215 ;
int error = 0 ;
F_15 ( & V_2 -> V_120 ) ;
for ( V_215 = V_213 ; V_215 < ( V_213 + V_214 ) ; V_215 ++ ) {
ASSERT ( V_215 -> V_216 < V_186 ||
V_215 -> V_216 > V_190 ) ;
error = F_122 ( V_2 , V_215 -> V_216 ,
V_215 -> V_217 , V_181 ) ;
if ( error )
goto V_218;
}
F_17 ( & V_2 -> V_120 ) ;
return 0 ;
V_218:
while ( -- V_215 >= V_213 ) {
error = F_122 ( V_2 , V_215 -> V_216 ,
- V_215 -> V_217 , V_181 ) ;
ASSERT ( error == 0 ) ;
}
F_17 ( & V_2 -> V_120 ) ;
return error ;
}
struct V_61 *
F_128 (
struct V_1 * V_2 ,
int V_59 )
{
struct V_61 * V_62 = V_2 -> V_66 ;
if ( ! F_129 ( V_62 ) ) {
if ( V_59 & V_219 )
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
struct V_61 * V_62 = V_2 -> V_66 ;
F_130 ( V_62 ) ;
V_2 -> V_66 = NULL ;
F_42 ( V_62 ) ;
}
int
F_95 (
T_2 * V_2 ,
T_17 V_220 )
{
T_13 * V_117 ;
int error ;
ASSERT ( V_220 & ( V_84 | V_86 | V_221 |
V_132 | V_133 |
V_136 ) ) ;
V_117 = F_61 ( V_2 , V_222 ) ;
error = F_62 ( V_117 , & F_63 ( V_2 ) -> V_175 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_117 , 0 ) ;
return error ;
}
F_66 ( V_117 , V_220 ) ;
error = F_67 ( V_117 , 0 ) ;
return error ;
}
int
F_134 (
struct V_1 * V_2 ,
char * V_223 )
{
if ( F_135 ( V_2 -> V_67 ) ||
F_135 ( V_2 -> V_114 ) ||
( V_2 -> V_224 && F_135 ( V_2 -> V_224 ) ) ) {
F_99 ( V_2 , L_35 , V_223 ) ;
F_99 ( V_2 , L_36 ) ;
return V_225 ;
}
return 0 ;
}
STATIC int
F_136 (
struct V_226 * V_227 ,
unsigned long V_228 ,
void * V_229 )
{
T_18 * V_230 ;
T_2 * V_2 ;
V_2 = ( T_2 * ) F_11 ( V_227 , T_2 , V_231 ) ;
V_230 = ( T_18 * )
F_137 ( V_2 -> V_232 , ( unsigned long ) V_229 ) ;
switch ( V_228 ) {
case V_233 :
case V_234 :
memset ( V_230 , 0 , sizeof( T_18 ) ) ;
break;
case V_235 :
case V_236 :
F_138 ( V_2 ) ;
F_139 ( V_2 , V_186 , 0 ) ;
F_139 ( V_2 , V_188 , 0 ) ;
F_139 ( V_2 , V_190 , 0 ) ;
F_140 ( V_2 ) ;
break;
case V_237 :
case V_238 :
F_138 ( V_2 ) ;
F_15 ( & V_2 -> V_120 ) ;
F_141 ( V_2 , V_186 ) ;
F_141 ( V_2 , V_188 ) ;
F_141 ( V_2 , V_190 ) ;
V_2 -> V_4 . V_187 += V_230 -> V_239 ;
V_2 -> V_4 . V_189 += V_230 -> V_240 ;
V_2 -> V_4 . V_191 += V_230 -> V_241 ;
memset ( V_230 , 0 , sizeof( T_18 ) ) ;
F_142 ( V_2 , V_186 , 0 ) ;
F_142 ( V_2 , V_188 , 0 ) ;
F_142 ( V_2 , V_190 , 0 ) ;
F_17 ( & V_2 -> V_120 ) ;
F_140 ( V_2 ) ;
break;
}
return V_242 ;
}
int
F_143 (
T_2 * V_2 )
{
T_18 * V_230 ;
int V_7 ;
V_2 -> V_232 = F_144 ( T_18 ) ;
if ( V_2 -> V_232 == NULL )
return - V_41 ;
F_145 (i) {
V_230 = ( T_18 * ) F_137 ( V_2 -> V_232 , V_7 ) ;
memset ( V_230 , 0 , sizeof( T_18 ) ) ;
}
F_25 ( & V_2 -> V_243 ) ;
V_2 -> V_244 = - 1 ;
#ifdef F_146
V_2 -> V_231 . V_245 = F_136 ;
V_2 -> V_231 . V_246 = 0 ;
F_147 ( & V_2 -> V_231 ) ;
#endif
return 0 ;
}
void
F_43 (
T_2 * V_2 )
{
F_138 ( V_2 ) ;
V_2 -> V_244 = - 1 ;
F_139 ( V_2 , V_186 , 0 ) ;
F_139 ( V_2 , V_188 , 0 ) ;
F_139 ( V_2 , V_190 , 0 ) ;
F_140 ( V_2 ) ;
}
void
F_148 (
T_2 * V_2 )
{
if ( V_2 -> V_232 ) {
F_149 ( & V_2 -> V_231 ) ;
F_150 ( V_2 -> V_232 ) ;
}
F_151 ( & V_2 -> V_243 ) ;
}
STATIC void
F_152 (
T_18 * V_247 )
{
while ( F_153 ( V_248 , & V_247 -> V_249 ) ) {
F_154 ( 1000 ) ;
}
}
STATIC void
F_155 (
T_18 * V_247 )
{
F_156 ( V_248 , & V_247 -> V_249 ) ;
}
STATIC void
F_157 (
T_2 * V_2 )
{
T_18 * V_230 ;
int V_7 ;
F_145 (i) {
V_230 = ( T_18 * ) F_137 ( V_2 -> V_232 , V_7 ) ;
F_152 ( V_230 ) ;
}
}
STATIC void
F_158 (
T_2 * V_2 )
{
T_18 * V_230 ;
int V_7 ;
F_145 (i) {
V_230 = ( T_18 * ) F_137 ( V_2 -> V_232 , V_7 ) ;
F_155 ( V_230 ) ;
}
}
STATIC void
F_159 (
T_2 * V_2 ,
T_18 * V_250 ,
int V_59 )
{
T_18 * V_230 ;
int V_7 ;
memset ( V_250 , 0 , sizeof( T_18 ) ) ;
if ( ! ( V_59 & V_251 ) )
F_157 ( V_2 ) ;
F_145 (i) {
V_230 = ( T_18 * ) F_137 ( V_2 -> V_232 , V_7 ) ;
V_250 -> V_239 += V_230 -> V_239 ;
V_250 -> V_240 += V_230 -> V_240 ;
V_250 -> V_241 += V_230 -> V_241 ;
}
if ( ! ( V_59 & V_251 ) )
F_158 ( V_2 ) ;
}
STATIC int
F_160 (
T_2 * V_2 ,
T_14 V_179 )
{
ASSERT ( ( V_179 >= V_186 ) && ( V_179 <= V_190 ) ) ;
return F_161 ( V_179 , & V_2 -> V_244 ) ;
}
STATIC void
F_141 (
T_2 * V_2 ,
T_14 V_179 )
{
T_18 V_250 ;
ASSERT ( ( V_179 >= V_186 ) && ( V_179 <= V_190 ) ) ;
if ( F_160 ( V_2 , V_179 ) )
return;
F_157 ( V_2 ) ;
if ( ! F_153 ( V_179 , & V_2 -> V_244 ) ) {
F_159 ( V_2 , & V_250 , V_251 ) ;
switch( V_179 ) {
case V_186 :
V_2 -> V_4 . V_187 = V_250 . V_239 ;
break;
case V_188 :
V_2 -> V_4 . V_189 = V_250 . V_240 ;
break;
case V_190 :
V_2 -> V_4 . V_191 = V_250 . V_241 ;
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
T_14 V_179 ,
T_19 V_252 ,
T_19 V_253 )
{
T_18 * V_230 ;
int V_7 ;
ASSERT ( ( V_179 >= V_186 ) && ( V_179 <= V_190 ) ) ;
F_157 ( V_2 ) ;
F_145 (i) {
V_230 = F_137 ( V_2 -> V_232 , V_7 ) ;
switch ( V_179 ) {
case V_186 :
V_230 -> V_239 = V_252 + V_253 ;
break;
case V_188 :
V_230 -> V_240 = V_252 + V_253 ;
break;
case V_190 :
V_230 -> V_241 = V_252 + V_253 ;
break;
default:
F_29 () ;
break;
}
V_253 = 0 ;
}
F_156 ( V_179 , & V_2 -> V_244 ) ;
F_158 ( V_2 ) ;
}
void
F_163 (
T_2 * V_2 ,
int V_59 )
{
T_18 V_250 ;
F_159 ( V_2 , & V_250 , V_59 ) ;
if ( ! F_160 ( V_2 , V_186 ) )
V_2 -> V_4 . V_187 = V_250 . V_239 ;
if ( ! F_160 ( V_2 , V_188 ) )
V_2 -> V_4 . V_189 = V_250 . V_240 ;
if ( ! F_160 ( V_2 , V_190 ) )
V_2 -> V_4 . V_191 = V_250 . V_241 ;
}
void
F_119 (
T_2 * V_2 ,
int V_59 )
{
F_15 ( & V_2 -> V_120 ) ;
F_163 ( V_2 , V_59 ) ;
F_17 ( & V_2 -> V_120 ) ;
}
STATIC void
F_142 (
T_2 * V_2 ,
T_14 V_179 ,
int V_254 )
{
T_19 V_252 , V_253 ;
int V_255 = F_164 () ;
T_19 V_256 = ( T_19 ) V_254 ;
F_141 ( V_2 , V_179 ) ;
switch ( V_179 ) {
case V_186 :
V_252 = V_2 -> V_4 . V_187 ;
V_253 = F_50 ( V_252 , V_255 ) ;
if ( V_252 < F_165 ( V_256 , V_257 ) )
return;
break;
case V_188 :
V_252 = V_2 -> V_4 . V_189 ;
V_253 = F_50 ( V_252 , V_255 ) ;
if ( V_252 < F_165 ( V_256 , V_257 ) )
return;
break;
case V_190 :
V_252 = V_2 -> V_4 . V_191 ;
V_253 = F_50 ( V_252 , V_255 ) ;
if ( V_252 < F_165 ( V_256 , F_166 ( V_2 ) ) )
return;
break;
default:
F_29 () ;
V_252 = V_253 = 0 ;
break;
}
F_162 ( V_2 , V_179 , V_252 , V_253 ) ;
}
STATIC void
F_139 (
T_2 * V_2 ,
T_14 V_220 ,
int V_254 )
{
F_15 ( & V_2 -> V_120 ) ;
F_142 ( V_2 , V_220 , V_254 ) ;
F_17 ( & V_2 -> V_120 ) ;
}
int
F_167 (
T_2 * V_2 ,
T_14 V_179 ,
T_15 V_180 ,
int V_181 )
{
T_18 * V_247 ;
long long V_183 ;
int V_258 = 0 ;
F_168 () ;
V_259:
F_169 () ;
V_247 = F_170 ( V_2 -> V_232 ) ;
if ( F_91 ( F_160 ( V_2 , V_179 ) ) )
goto V_260;
F_152 ( V_247 ) ;
if ( F_91 ( F_160 ( V_2 , V_179 ) ) ) {
F_155 ( V_247 ) ;
goto V_260;
}
switch ( V_179 ) {
case V_186 :
V_183 = V_247 -> V_239 ;
V_183 += V_180 ;
if ( F_91 ( V_183 < 0 ) )
goto V_261;
V_247 -> V_239 = V_183 ;
break;
case V_188 :
V_183 = V_247 -> V_240 ;
V_183 += V_180 ;
if ( F_91 ( V_183 < 0 ) )
goto V_261;
V_247 -> V_240 = V_183 ;
break;
case V_190 :
F_171 ( ( V_2 -> V_192 - V_2 -> V_193 ) != 0 ) ;
V_183 = V_247 -> V_241 - F_123 ( V_2 ) ;
V_183 += V_180 ;
if ( F_91 ( V_183 < 0 ) )
goto V_261;
V_247 -> V_241 = V_183 + F_123 ( V_2 ) ;
break;
default:
F_29 () ;
break;
}
F_155 ( V_247 ) ;
F_172 () ;
return 0 ;
V_260:
F_172 () ;
F_138 ( V_2 ) ;
if ( ! ( F_160 ( V_2 , V_179 ) ) ) {
F_140 ( V_2 ) ;
goto V_259;
}
F_15 ( & V_2 -> V_120 ) ;
V_258 = F_122 ( V_2 , V_179 , V_180 , V_181 ) ;
F_17 ( & V_2 -> V_120 ) ;
if ( V_258 != V_194 )
F_139 ( V_2 , V_179 , 0 ) ;
F_140 ( V_2 ) ;
return V_258 ;
V_261:
F_155 ( V_247 ) ;
F_172 () ;
F_138 ( V_2 ) ;
F_139 ( V_2 , V_179 , V_180 ) ;
F_140 ( V_2 ) ;
goto V_259;
}
