void
F_1 ( void )
{
if ( V_1 == 0 )
return;
F_2 ( V_2 ) ;
V_2 = NULL ;
V_1 = 0 ;
}
STATIC int
F_3 (
struct V_3 * V_4 )
{
T_1 * V_5 = & V_4 -> V_6 . V_7 ;
int V_8 , V_9 ;
F_4 ( & V_4 -> V_10 -> V_11 , V_5 ) ;
if ( V_4 -> V_12 & V_13 )
return 0 ;
if ( F_5 ( V_5 ) ) {
F_6 ( V_4 , L_1 ) ;
return - V_14 ;
}
F_7 ( & V_15 ) ;
for ( V_9 = 0 , V_8 = - 1 ; V_9 < V_1 ; V_9 ++ ) {
if ( F_5 ( & V_2 [ V_9 ] ) ) {
V_8 = V_9 ;
continue;
}
if ( F_8 ( V_5 , & V_2 [ V_9 ] ) )
goto V_16;
}
if ( V_8 < 0 ) {
V_2 = F_9 ( V_2 ,
( V_1 + 1 ) * sizeof( * V_2 ) ,
V_17 ) ;
V_8 = V_1 ++ ;
}
V_2 [ V_8 ] = * V_5 ;
F_10 ( & V_15 ) ;
return 0 ;
V_16:
F_10 ( & V_15 ) ;
F_6 ( V_4 , L_2 , V_5 ) ;
return - V_14 ;
}
STATIC void
F_11 (
struct V_3 * V_4 )
{
T_1 * V_5 = & V_4 -> V_6 . V_7 ;
int V_9 ;
if ( V_4 -> V_12 & V_13 )
return;
F_7 ( & V_15 ) ;
for ( V_9 = 0 ; V_9 < V_1 ; V_9 ++ ) {
if ( F_5 ( & V_2 [ V_9 ] ) )
continue;
if ( ! F_8 ( V_5 , & V_2 [ V_9 ] ) )
continue;
memset ( & V_2 [ V_9 ] , 0 , sizeof( T_1 ) ) ;
break;
}
ASSERT ( V_9 < V_1 ) ;
F_10 ( & V_15 ) ;
}
STATIC void
F_12 (
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 , struct V_20 , V_18 ) ;
ASSERT ( F_14 ( & V_21 -> V_22 ) == 0 ) ;
F_2 ( V_21 ) ;
}
STATIC void
F_15 (
T_2 * V_4 )
{
T_3 V_23 ;
struct V_20 * V_21 ;
for ( V_23 = 0 ; V_23 < V_4 -> V_6 . V_24 ; V_23 ++ ) {
F_16 ( & V_4 -> V_25 ) ;
V_21 = F_17 ( & V_4 -> V_26 , V_23 ) ;
F_18 ( & V_4 -> V_25 ) ;
ASSERT ( V_21 ) ;
ASSERT ( F_14 ( & V_21 -> V_22 ) == 0 ) ;
F_19 ( V_21 ) ;
F_20 ( & V_21 -> V_18 , F_12 ) ;
}
}
int
F_21 (
T_4 * V_27 ,
T_5 V_28 )
{
ASSERT ( V_29 >= V_27 -> V_30 ) ;
ASSERT ( V_27 -> V_30 >= V_31 ) ;
if ( V_28 >> ( V_29 - V_27 -> V_30 ) > V_32 )
return - V_33 ;
return 0 ;
}
int
F_22 (
T_2 * V_4 ,
T_3 V_34 ,
T_3 * V_35 )
{
T_3 V_36 ;
T_3 V_37 = V_38 ;
T_6 * V_21 ;
int error = - V_39 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
V_21 = F_23 ( V_4 , V_36 ) ;
if ( V_21 ) {
F_24 ( V_21 ) ;
continue;
}
V_21 = F_25 ( sizeof( * V_21 ) , V_40 ) ;
if ( ! V_21 )
goto V_41;
V_21 -> V_42 = V_36 ;
V_21 -> V_43 = V_4 ;
F_26 ( & V_21 -> V_44 ) ;
F_27 ( & V_21 -> V_45 ) ;
F_28 ( & V_21 -> V_46 , V_47 ) ;
if ( F_29 ( V_21 ) )
goto V_48;
F_30 ( & V_21 -> V_49 ) ;
if ( F_31 ( V_50 ) )
goto V_51;
F_16 ( & V_4 -> V_25 ) ;
if ( F_32 ( & V_4 -> V_26 , V_36 , V_21 ) ) {
F_33 () ;
F_18 ( & V_4 -> V_25 ) ;
F_34 () ;
error = - V_52 ;
goto V_51;
}
F_18 ( & V_4 -> V_25 ) ;
F_34 () ;
if ( V_37 == V_38 )
V_37 = V_36 ;
}
V_36 = F_35 ( V_4 , V_34 ) ;
if ( V_35 )
* V_35 = V_36 ;
V_4 -> V_53 = F_36 ( V_4 ) ;
return 0 ;
V_51:
F_19 ( V_21 ) ;
V_48:
F_2 ( V_21 ) ;
V_41:
for ( V_36 = V_37 ; V_36 < V_34 ; V_36 ++ ) {
V_21 = F_17 ( & V_4 -> V_26 , V_36 ) ;
if ( ! V_21 )
break;
F_19 ( V_21 ) ;
F_2 ( V_21 ) ;
}
return error ;
}
int
F_37 (
struct V_3 * V_4 ,
int V_54 )
{
unsigned int V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_27 = & V_4 -> V_6 ;
int error ;
int V_59 = ! ( V_54 & V_60 ) ;
const struct V_61 * V_62 ;
ASSERT ( V_4 -> V_63 == NULL ) ;
ASSERT ( V_4 -> V_64 != NULL ) ;
V_55 = F_38 ( V_4 -> V_64 ) ;
V_62 = NULL ;
V_65:
error = F_39 ( V_4 -> V_64 , V_66 ,
F_40 ( V_55 ) , V_67 , & V_57 ,
V_62 ) ;
if ( error ) {
if ( V_59 )
F_6 ( V_4 , L_3 , error ) ;
if ( error == - V_68 )
error = - V_69 ;
return error ;
}
F_41 ( V_27 , F_42 ( V_57 ) ) ;
if ( V_27 -> V_70 != V_71 ) {
if ( V_59 )
F_6 ( V_4 , L_4 ) ;
error = - V_14 ;
goto V_72;
}
if ( V_55 > V_27 -> V_73 ) {
if ( V_59 )
F_6 ( V_4 , L_5 ,
V_55 , V_27 -> V_73 ) ;
error = - V_74 ;
goto V_72;
}
if ( V_62 == NULL ) {
F_43 ( V_57 ) ;
V_55 = V_27 -> V_73 ;
V_62 = V_59 ? & V_75 : & V_76 ;
goto V_65;
}
F_44 ( V_4 ) ;
V_57 -> V_77 = & V_75 ;
V_4 -> V_63 = V_57 ;
F_45 ( V_57 ) ;
return 0 ;
V_72:
F_43 ( V_57 ) ;
return error ;
}
STATIC int
F_46 ( T_2 * V_4 )
{
T_4 * V_27 = & ( V_4 -> V_6 ) ;
if ( V_4 -> V_78 ) {
if ( ( F_47 ( V_4 -> V_78 ) & V_4 -> V_79 ) ||
( F_47 ( V_4 -> V_80 ) & V_4 -> V_79 ) ) {
F_6 ( V_4 ,
L_6 ,
V_27 -> V_81 ) ;
return - V_14 ;
} else {
V_4 -> V_78 = F_48 ( V_4 , V_4 -> V_78 ) ;
if ( V_4 -> V_78 && ( V_27 -> V_82 % V_4 -> V_78 ) ) {
F_6 ( V_4 ,
L_7 ,
V_27 -> V_82 ) ;
return - V_14 ;
} else if ( V_4 -> V_78 ) {
V_4 -> V_80 = F_48 ( V_4 , V_4 -> V_80 ) ;
} else {
F_6 ( V_4 ,
L_8 ,
V_4 -> V_78 , V_27 -> V_81 ) ;
return - V_14 ;
}
}
if ( F_49 ( V_27 ) ) {
if ( V_27 -> V_83 != V_4 -> V_78 ) {
V_27 -> V_83 = V_4 -> V_78 ;
V_4 -> V_84 = true ;
}
if ( V_27 -> V_85 != V_4 -> V_80 ) {
V_27 -> V_85 = V_4 -> V_80 ;
V_4 -> V_84 = true ;
}
} else {
F_6 ( V_4 ,
L_9 ) ;
return - V_14 ;
}
} else if ( ( V_4 -> V_12 & V_86 ) != V_86 &&
F_49 ( & V_4 -> V_6 ) ) {
V_4 -> V_78 = V_27 -> V_83 ;
V_4 -> V_80 = V_27 -> V_85 ;
}
return 0 ;
}
STATIC void
F_50 ( T_2 * V_4 )
{
T_4 * V_27 = & ( V_4 -> V_6 ) ;
T_5 V_87 ;
if ( V_27 -> V_88 ) {
V_87 = V_27 -> V_89 * V_27 -> V_88 ;
F_51 ( V_87 , 100 ) ;
F_51 ( V_87 , V_4 -> V_90 ) ;
V_4 -> V_91 = ( V_87 * V_4 -> V_90 ) <<
V_27 -> V_92 ;
} else {
V_4 -> V_91 = 0 ;
}
}
STATIC void
F_52 ( T_2 * V_4 )
{
T_4 * V_27 = & ( V_4 -> V_6 ) ;
int V_93 , V_94 ;
if ( ! ( V_4 -> V_12 & V_95 ) ) {
if ( V_4 -> V_12 & V_96 ) {
V_93 = V_97 ;
V_94 = V_98 ;
} else {
V_93 = V_99 ;
V_94 = V_100 ;
}
} else {
V_93 = V_4 -> V_101 ;
V_94 = V_4 -> V_102 ;
}
if ( V_27 -> V_30 > V_93 ) {
V_4 -> V_101 = V_27 -> V_30 ;
} else {
V_4 -> V_101 = V_93 ;
}
V_4 -> V_103 = 1 << ( V_4 -> V_101 - V_27 -> V_30 ) ;
if ( V_27 -> V_30 > V_94 ) {
V_4 -> V_102 = V_27 -> V_30 ;
} else {
V_4 -> V_102 = V_94 ;
}
V_4 -> V_104 = 1 << ( V_4 -> V_102 - V_27 -> V_30 ) ;
}
void
F_53 (
struct V_3 * V_4 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_105 ; V_9 ++ ) {
T_5 V_106 = V_4 -> V_6 . V_89 ;
F_51 ( V_106 , 100 ) ;
V_4 -> V_107 [ V_9 ] = V_106 * ( V_9 + 1 ) ;
}
}
STATIC void
F_54 ( T_2 * V_4 )
{
if ( F_55 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_108 >= F_56 ( V_4 ) )
V_4 -> V_109 = V_4 -> V_6 . V_108 - 1 ;
else
V_4 -> V_109 = 0 ;
if ( V_4 -> V_78 && V_4 -> V_109 &&
! ( V_4 -> V_78 & V_4 -> V_109 ) )
V_4 -> V_110 = V_4 -> V_78 ;
else
V_4 -> V_110 = 0 ;
}
STATIC int
F_57 (
struct V_3 * V_4 )
{
struct V_56 * V_57 ;
T_7 V_111 ;
int error ;
V_111 = ( T_7 ) F_58 ( V_4 , V_4 -> V_6 . V_89 ) ;
if ( F_59 ( V_4 , V_111 ) != V_4 -> V_6 . V_89 ) {
F_6 ( V_4 , L_10 ) ;
return - V_33 ;
}
error = F_39 ( V_4 -> V_64 ,
V_111 - F_60 ( V_4 , 1 ) ,
F_60 ( V_4 , 1 ) , 0 , & V_57 , NULL ) ;
if ( error ) {
F_6 ( V_4 , L_11 ) ;
return error ;
}
F_43 ( V_57 ) ;
if ( V_4 -> V_112 == V_4 -> V_64 )
return 0 ;
V_111 = ( T_7 ) F_58 ( V_4 , V_4 -> V_6 . V_113 ) ;
if ( F_59 ( V_4 , V_111 ) != V_4 -> V_6 . V_113 ) {
F_6 ( V_4 , L_12 ) ;
return - V_33 ;
}
error = F_39 ( V_4 -> V_112 ,
V_111 - F_58 ( V_4 , 1 ) ,
F_58 ( V_4 , 1 ) , 0 , & V_57 , NULL ) ;
if ( error ) {
F_6 ( V_4 , L_13 ) ;
return error ;
}
F_43 ( V_57 ) ;
return 0 ;
}
int
F_61 (
struct V_3 * V_4 )
{
V_4 -> V_114 = 0 ;
if ( V_4 -> V_6 . V_115 == 0 )
return 0 ;
F_16 ( & V_4 -> V_116 ) ;
V_4 -> V_6 . V_115 = 0 ;
F_18 ( & V_4 -> V_116 ) ;
if ( ! F_62 ( V_4 , V_117 ) )
return 0 ;
return F_63 ( V_4 , false ) ;
}
T_5
F_64 ( T_2 * V_4 )
{
T_5 V_118 ;
V_118 = V_4 -> V_6 . V_89 ;
F_51 ( V_118 , 20 ) ;
V_118 = F_65 ( T_5 , V_118 , 8192 ) ;
return V_118 ;
}
int
F_66 (
struct V_3 * V_4 )
{
struct V_58 * V_27 = & ( V_4 -> V_6 ) ;
struct V_119 * V_120 ;
T_5 V_118 ;
T_8 V_121 = 0 ;
T_8 V_122 = 0 ;
int error = 0 ;
F_67 ( V_4 , V_27 ) ;
if ( F_68 ( V_27 ) ) {
F_6 ( V_4 , L_14 ) ;
V_27 -> V_123 |= V_27 -> V_124 ;
V_4 -> V_84 = true ;
if ( F_69 ( & V_4 -> V_6 ) &&
! ( V_4 -> V_12 & V_125 ) )
V_4 -> V_12 |= V_126 ;
}
if ( F_69 ( & V_4 -> V_6 ) &&
( V_4 -> V_12 & V_125 ) ) {
F_70 ( & V_4 -> V_6 ) ;
V_4 -> V_84 = true ;
if ( ! V_27 -> V_123 )
V_4 -> V_84 = true ;
}
if ( ! ( V_4 -> V_6 . V_127 & V_128 ) ) {
V_4 -> V_6 . V_127 |= V_128 ;
V_4 -> V_84 = true ;
}
error = F_46 ( V_4 ) ;
if ( error )
goto V_129;
F_71 ( V_4 ) ;
F_72 ( V_4 , V_130 ) ;
F_72 ( V_4 , V_131 ) ;
F_73 ( V_4 ) ;
F_74 ( V_4 ) ;
F_75 ( V_4 ) ;
F_50 ( V_4 ) ;
V_4 -> V_132 = 1 ;
error = F_76 ( & V_4 -> V_133 , & V_134 , NULL , V_4 -> V_135 ) ;
if ( error )
goto V_129;
error = F_76 ( & V_4 -> V_136 . V_137 , & V_138 ,
& V_4 -> V_133 , L_15 ) ;
if ( error )
goto V_139;
error = F_77 ( V_4 ) ;
if ( error )
goto V_140;
error = F_78 ( V_4 ) ;
if ( error )
goto V_141;
error = F_3 ( V_4 ) ;
if ( error )
goto V_142;
F_52 ( V_4 ) ;
F_53 ( V_4 ) ;
V_4 -> V_143 = V_144 ;
if ( F_79 ( & V_4 -> V_6 ) ) {
int V_145 = V_4 -> V_143 ;
V_145 *= V_4 -> V_6 . V_146 / V_147 ;
if ( V_4 -> V_6 . V_108 >= F_80 ( V_4 , V_145 ) )
V_4 -> V_143 = V_145 ;
}
if ( F_81 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_148 !=
F_80 ( V_4 , V_4 -> V_143 ) ) {
F_6 ( V_4 ,
L_16 ,
V_4 -> V_6 . V_148 ,
F_80 ( V_4 , V_4 -> V_143 ) ) ;
error = - V_14 ;
goto V_149;
}
F_54 ( V_4 ) ;
error = F_57 ( V_4 ) ;
if ( error )
goto V_149;
error = F_82 ( V_4 ) ;
if ( error ) {
F_6 ( V_4 , L_17 ) ;
goto V_149;
}
V_4 -> V_150 [ 0 ] =
( F_83 ( & V_27 -> V_7 . V_151 [ 8 ] ) << 16 ) |
F_83 ( & V_27 -> V_7 . V_151 [ 4 ] ) ;
V_4 -> V_150 [ 1 ] = F_84 ( & V_27 -> V_7 . V_151 [ 0 ] ) ;
V_4 -> V_152 = 0 ;
error = F_85 ( V_4 ) ;
if ( error ) {
F_6 ( V_4 , L_18 , error ) ;
goto V_149;
}
F_86 ( V_4 ) ;
F_26 ( & V_4 -> V_25 ) ;
F_28 ( & V_4 -> V_26 , V_47 ) ;
error = F_22 ( V_4 , V_27 -> V_24 , & V_4 -> V_153 ) ;
if ( error ) {
F_6 ( V_4 , L_19 , error ) ;
goto V_154;
}
if ( ! V_27 -> V_113 ) {
F_6 ( V_4 , L_20 ) ;
F_87 ( L_21 , V_155 , V_4 ) ;
error = - V_69 ;
goto V_156;
}
error = F_88 ( V_4 , V_4 -> V_112 ,
F_89 ( V_4 , V_27 -> V_157 ) ,
F_58 ( V_4 , V_27 -> V_113 ) ) ;
if ( error ) {
F_6 ( V_4 , L_22 ) ;
goto V_158;
}
if ( F_90 ( & V_4 -> V_6 ) &&
! F_91 ( V_4 ) &&
! V_4 -> V_6 . V_159 ) {
error = F_92 ( V_4 , V_27 -> V_24 ) ;
if ( error )
goto V_160;
}
error = F_93 ( V_4 , NULL , V_27 -> V_161 , 0 , V_162 , & V_120 ) ;
if ( error ) {
F_6 ( V_4 , L_23 ) ;
goto V_160;
}
ASSERT ( V_120 != NULL ) ;
if ( F_94 ( ! F_95 ( F_96 ( V_120 ) -> V_163 ) ) ) {
F_6 ( V_4 , L_24 ,
( unsigned long long ) V_120 -> V_164 ) ;
F_97 ( V_120 , V_162 ) ;
F_87 ( L_25 , V_155 ,
V_4 ) ;
error = - V_69 ;
goto V_165;
}
V_4 -> V_166 = V_120 ;
F_97 ( V_120 , V_162 ) ;
error = F_98 ( V_4 ) ;
if ( error ) {
F_6 ( V_4 , L_26 ) ;
goto V_165;
}
if ( V_4 -> V_84 && ! ( V_4 -> V_12 & V_167 ) ) {
error = F_63 ( V_4 , false ) ;
if ( error ) {
F_6 ( V_4 , L_27 ) ;
goto V_168;
}
}
if ( F_99 ( V_4 ) ) {
error = F_100 ( V_4 , & V_121 , & V_122 ) ;
if ( error )
goto V_168;
} else {
ASSERT ( ! F_101 ( V_4 ) ) ;
if ( V_4 -> V_6 . V_115 & V_169 ) {
F_102 ( V_4 , L_28 ) ;
error = F_61 ( V_4 ) ;
if ( error )
goto V_168;
}
}
error = F_103 ( V_4 ) ;
if ( error ) {
F_6 ( V_4 , L_29 ) ;
goto V_168;
}
if ( ( V_4 -> V_12 & ( V_167 | V_170 ) ) ==
V_167 ) {
F_104 ( V_4 ) ;
}
if ( V_121 ) {
ASSERT ( V_4 -> V_114 == 0 ) ;
V_4 -> V_114 = V_122 ;
F_105 ( V_4 ) ;
}
if ( ! ( V_4 -> V_12 & V_167 ) ) {
V_118 = F_64 ( V_4 ) ;
error = F_106 ( V_4 , & V_118 , NULL ) ;
if ( error )
F_6 ( V_4 ,
L_30 ) ;
error = F_107 ( V_4 ) ;
if ( error ) {
F_108 ( V_4 ,
L_31 , error ) ;
F_109 ( V_4 , V_171 ) ;
goto V_172;
}
error = F_110 ( V_4 ) ;
if ( error && error != - V_173 )
goto V_174;
}
return 0 ;
V_174:
F_111 ( V_4 ) ;
V_172:
F_112 ( V_4 ) ;
V_168:
F_113 ( V_4 ) ;
V_165:
F_114 ( V_120 ) ;
F_115 ( & V_4 -> V_175 ) ;
F_116 ( V_4 , V_176 ) ;
F_117 ( V_4 ) ;
V_160:
V_4 -> V_12 |= V_177 ;
F_118 ( V_4 ) ;
V_158:
if ( V_4 -> V_112 && V_4 -> V_112 != V_4 -> V_64 )
F_119 ( V_4 -> V_112 ) ;
F_119 ( V_4 -> V_64 ) ;
V_156:
F_15 ( V_4 ) ;
V_154:
F_120 ( V_4 ) ;
V_149:
F_11 ( V_4 ) ;
V_142:
F_121 ( V_4 ) ;
V_141:
F_122 ( V_4 ) ;
V_140:
F_123 ( & V_4 -> V_136 . V_137 ) ;
V_139:
F_123 ( & V_4 -> V_133 ) ;
V_129:
return error ;
}
void
F_124 (
struct V_3 * V_4 )
{
T_5 V_118 ;
int error ;
F_115 ( & V_4 -> V_178 ) ;
F_115 ( & V_4 -> V_179 ) ;
F_111 ( V_4 ) ;
F_112 ( V_4 ) ;
F_113 ( V_4 ) ;
F_114 ( V_4 -> V_166 ) ;
F_125 ( V_4 , V_180 ) ;
F_126 ( V_4 ) ;
F_127 ( V_181 ) ;
V_4 -> V_12 |= V_177 ;
F_128 ( V_4 -> V_182 ) ;
F_115 ( & V_4 -> V_175 ) ;
F_116 ( V_4 , V_176 ) ;
F_117 ( V_4 ) ;
V_118 = 0 ;
error = F_106 ( V_4 , & V_118 , NULL ) ;
if ( error )
F_6 ( V_4 , L_32
L_33 ) ;
error = F_129 ( V_4 ) ;
if ( error )
F_6 ( V_4 , L_34
L_33 ) ;
F_130 ( V_4 ) ;
F_120 ( V_4 ) ;
F_11 ( V_4 ) ;
#if F_131 ( V_183 )
F_132 ( V_4 ) ;
#endif
F_15 ( V_4 ) ;
F_121 ( V_4 ) ;
F_122 ( V_4 ) ;
F_123 ( & V_4 -> V_136 . V_137 ) ;
F_123 ( & V_4 -> V_133 ) ;
}
bool
F_62 (
struct V_3 * V_4 ,
int V_184 )
{
ASSERT ( V_184 > V_185 ) ;
if ( ( V_4 -> V_10 -> V_186 . V_187 >= V_184 ) ||
F_133 ( V_4 ) || ( V_4 -> V_12 & V_167 ) )
return false ;
return true ;
}
int
F_129 ( T_2 * V_4 )
{
if ( ! F_62 ( V_4 , V_188 ) )
return 0 ;
if ( ! F_90 ( & V_4 -> V_6 ) )
return 0 ;
return F_63 ( V_4 , true ) ;
}
int
F_134 (
struct V_3 * V_4 ,
T_9 V_189 )
{
F_135 ( & V_4 -> V_190 , V_189 , V_191 ) ;
if ( F_136 ( & V_4 -> V_190 , 0 , V_191 ) < 0 ) {
ASSERT ( 0 ) ;
F_137 ( & V_4 -> V_190 , - V_189 ) ;
return - V_14 ;
}
return 0 ;
}
int
F_138 (
struct V_3 * V_4 ,
T_9 V_189 )
{
F_137 ( & V_4 -> V_192 , V_189 ) ;
if ( F_139 ( & V_4 -> V_192 , 0 ) < 0 ) {
ASSERT ( 0 ) ;
F_137 ( & V_4 -> V_192 , - V_189 ) ;
return - V_14 ;
}
return 0 ;
}
int
F_140 (
struct V_3 * V_4 ,
T_9 V_189 ,
bool V_193 )
{
T_9 V_194 ;
long long V_195 ;
T_10 V_196 ;
if ( V_189 > 0 ) {
if ( F_141 ( V_4 -> V_197 == V_4 -> V_198 ) ) {
F_137 ( & V_4 -> V_199 , V_189 ) ;
return 0 ;
}
F_16 ( & V_4 -> V_116 ) ;
V_195 = ( long long ) ( V_4 -> V_197 - V_4 -> V_198 ) ;
if ( V_195 > V_189 ) {
V_4 -> V_198 += V_189 ;
} else {
V_189 -= V_195 ;
V_4 -> V_198 = V_4 -> V_197 ;
F_137 ( & V_4 -> V_199 , V_189 ) ;
}
F_18 ( & V_4 -> V_116 ) ;
return 0 ;
}
if ( F_136 ( & V_4 -> V_199 , 2 * V_200 ,
V_200 ) < 0 )
V_196 = 1 ;
else
V_196 = V_200 ;
F_135 ( & V_4 -> V_199 , V_189 , V_196 ) ;
if ( F_136 ( & V_4 -> V_199 , V_4 -> V_201 ,
V_200 ) >= 0 ) {
return 0 ;
}
F_16 ( & V_4 -> V_116 ) ;
F_137 ( & V_4 -> V_199 , - V_189 ) ;
if ( ! V_193 )
goto V_202;
V_194 = ( long long ) V_4 -> V_198 + V_189 ;
if ( V_194 >= 0 ) {
V_4 -> V_198 = V_194 ;
F_18 ( & V_4 -> V_116 ) ;
return 0 ;
}
F_142 ( V_203
L_35
L_36 ,
V_4 -> V_135 ) ;
V_202:
F_18 ( & V_4 -> V_116 ) ;
return - V_173 ;
}
int
F_143 (
struct V_3 * V_4 ,
T_9 V_189 )
{
T_9 V_194 ;
int V_204 = 0 ;
F_16 ( & V_4 -> V_116 ) ;
V_194 = V_4 -> V_6 . V_205 + V_189 ;
if ( V_194 < 0 )
V_204 = - V_173 ;
else
V_4 -> V_6 . V_205 = V_194 ;
F_18 ( & V_4 -> V_116 ) ;
return V_204 ;
}
struct V_56 *
F_144 (
struct V_3 * V_4 ,
int V_54 )
{
struct V_56 * V_57 = V_4 -> V_63 ;
if ( ! F_145 ( V_57 ) ) {
if ( V_54 & V_206 )
return NULL ;
F_146 ( V_57 ) ;
}
F_147 ( V_57 ) ;
ASSERT ( V_57 -> V_207 & V_208 ) ;
return V_57 ;
}
void
F_148 (
struct V_3 * V_4 )
{
struct V_56 * V_57 = V_4 -> V_63 ;
F_146 ( V_57 ) ;
V_4 -> V_63 = NULL ;
F_43 ( V_57 ) ;
}
int
F_149 (
struct V_3 * V_4 ,
char * V_209 )
{
if ( F_150 ( V_4 -> V_64 ) ||
F_150 ( V_4 -> V_112 ) ||
( V_4 -> V_210 && F_150 ( V_4 -> V_210 ) ) ) {
F_102 ( V_4 , L_37 , V_209 ) ;
F_102 ( V_4 , L_38 ) ;
return - V_211 ;
}
return 0 ;
}
