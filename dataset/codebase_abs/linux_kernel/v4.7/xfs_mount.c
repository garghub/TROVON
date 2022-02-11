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
if ( V_4 -> V_10 & V_11 )
return 0 ;
if ( F_4 ( V_5 ) ) {
F_5 ( V_4 , L_1 ) ;
return - V_12 ;
}
F_6 ( & V_13 ) ;
for ( V_9 = 0 , V_8 = - 1 ; V_9 < V_1 ; V_9 ++ ) {
if ( F_4 ( & V_2 [ V_9 ] ) ) {
V_8 = V_9 ;
continue;
}
if ( F_7 ( V_5 , & V_2 [ V_9 ] ) )
goto V_14;
}
if ( V_8 < 0 ) {
V_2 = F_8 ( V_2 ,
( V_1 + 1 ) * sizeof( * V_2 ) ,
V_15 ) ;
V_8 = V_1 ++ ;
}
V_2 [ V_8 ] = * V_5 ;
F_9 ( & V_13 ) ;
return 0 ;
V_14:
F_9 ( & V_13 ) ;
F_5 ( V_4 , L_2 , V_5 ) ;
return - V_12 ;
}
STATIC void
F_10 (
struct V_3 * V_4 )
{
T_1 * V_5 = & V_4 -> V_6 . V_7 ;
int V_9 ;
if ( V_4 -> V_10 & V_11 )
return;
F_6 ( & V_13 ) ;
for ( V_9 = 0 ; V_9 < V_1 ; V_9 ++ ) {
if ( F_4 ( & V_2 [ V_9 ] ) )
continue;
if ( ! F_7 ( V_5 , & V_2 [ V_9 ] ) )
continue;
memset ( & V_2 [ V_9 ] , 0 , sizeof( T_1 ) ) ;
break;
}
ASSERT ( V_9 < V_1 ) ;
F_9 ( & V_13 ) ;
}
STATIC void
F_11 (
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_12 ( V_17 , struct V_18 , V_16 ) ;
ASSERT ( F_13 ( & V_19 -> V_20 ) == 0 ) ;
F_2 ( V_19 ) ;
}
STATIC void
F_14 (
T_2 * V_4 )
{
T_3 V_21 ;
struct V_18 * V_19 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_6 . V_22 ; V_21 ++ ) {
F_15 ( & V_4 -> V_23 ) ;
V_19 = F_16 ( & V_4 -> V_24 , V_21 ) ;
F_17 ( & V_4 -> V_23 ) ;
ASSERT ( V_19 ) ;
ASSERT ( F_13 ( & V_19 -> V_20 ) == 0 ) ;
F_18 ( & V_19 -> V_16 , F_11 ) ;
}
}
int
F_19 (
T_4 * V_25 ,
T_5 V_26 )
{
ASSERT ( V_27 >= V_25 -> V_28 ) ;
ASSERT ( V_25 -> V_28 >= V_29 ) ;
if ( V_26 >> ( V_27 - V_25 -> V_28 ) > V_30 )
return - V_31 ;
return 0 ;
}
int
F_20 (
T_2 * V_4 ,
T_3 V_32 ,
T_3 * V_33 )
{
T_3 V_34 ;
T_3 V_35 = 0 ;
T_6 * V_19 ;
int error = - V_36 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
V_19 = F_21 ( V_4 , V_34 ) ;
if ( V_19 ) {
F_22 ( V_19 ) ;
continue;
}
if ( ! V_35 )
V_35 = V_34 ;
V_19 = F_23 ( sizeof( * V_19 ) , V_37 ) ;
if ( ! V_19 )
goto V_38;
V_19 -> V_39 = V_34 ;
V_19 -> V_40 = V_4 ;
F_24 ( & V_19 -> V_41 ) ;
F_25 ( & V_19 -> V_42 ) ;
F_26 ( & V_19 -> V_43 , V_44 ) ;
F_24 ( & V_19 -> V_45 ) ;
V_19 -> V_46 = V_47 ;
if ( F_27 ( V_48 ) )
goto V_38;
F_15 ( & V_4 -> V_23 ) ;
if ( F_28 ( & V_4 -> V_24 , V_34 , V_19 ) ) {
F_29 () ;
F_17 ( & V_4 -> V_23 ) ;
F_30 () ;
error = - V_49 ;
goto V_38;
}
F_17 ( & V_4 -> V_23 ) ;
F_30 () ;
}
V_34 = F_31 ( V_4 , V_32 ) ;
if ( V_33 )
* V_33 = V_34 ;
return 0 ;
V_38:
F_2 ( V_19 ) ;
for (; V_34 > V_35 ; V_34 -- ) {
V_19 = F_16 ( & V_4 -> V_24 , V_34 ) ;
F_2 ( V_19 ) ;
}
return error ;
}
int
F_32 (
struct V_3 * V_4 ,
int V_50 )
{
unsigned int V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_25 = & V_4 -> V_6 ;
int error ;
int V_55 = ! ( V_50 & V_56 ) ;
const struct V_57 * V_58 ;
ASSERT ( V_4 -> V_59 == NULL ) ;
ASSERT ( V_4 -> V_60 != NULL ) ;
V_51 = F_33 ( V_4 -> V_60 ) ;
V_58 = NULL ;
V_61:
error = F_34 ( V_4 -> V_60 , V_62 ,
F_35 ( V_51 ) , 0 , & V_53 , V_58 ) ;
if ( error ) {
if ( V_55 )
F_5 ( V_4 , L_3 , error ) ;
if ( error == - V_63 )
error = - V_64 ;
return error ;
}
F_36 ( V_25 , F_37 ( V_53 ) ) ;
if ( V_25 -> V_65 != V_66 ) {
if ( V_55 )
F_5 ( V_4 , L_4 ) ;
error = - V_12 ;
goto V_67;
}
if ( V_51 > V_25 -> V_68 ) {
if ( V_55 )
F_5 ( V_4 , L_5 ,
V_51 , V_25 -> V_68 ) ;
error = - V_69 ;
goto V_67;
}
if ( V_58 == NULL ) {
F_38 ( V_53 ) ;
V_51 = V_25 -> V_68 ;
V_58 = V_55 ? & V_70 : & V_71 ;
goto V_61;
}
F_39 ( V_4 ) ;
V_53 -> V_72 = & V_70 ;
V_4 -> V_59 = V_53 ;
F_40 ( V_53 ) ;
return 0 ;
V_67:
F_38 ( V_53 ) ;
return error ;
}
STATIC int
F_41 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
if ( V_4 -> V_73 ) {
if ( ( F_42 ( V_4 -> V_73 ) & V_4 -> V_74 ) ||
( F_42 ( V_4 -> V_75 ) & V_4 -> V_74 ) ) {
F_5 ( V_4 ,
L_6 ,
V_25 -> V_76 ) ;
return - V_12 ;
} else {
V_4 -> V_73 = F_43 ( V_4 , V_4 -> V_73 ) ;
if ( V_4 -> V_73 && ( V_25 -> V_77 % V_4 -> V_73 ) ) {
F_5 ( V_4 ,
L_7 ,
V_25 -> V_77 ) ;
return - V_12 ;
} else if ( V_4 -> V_73 ) {
V_4 -> V_75 = F_43 ( V_4 , V_4 -> V_75 ) ;
} else {
F_5 ( V_4 ,
L_8 ,
V_4 -> V_73 , V_25 -> V_76 ) ;
return - V_12 ;
}
}
if ( F_44 ( V_25 ) ) {
if ( V_25 -> V_78 != V_4 -> V_73 ) {
V_25 -> V_78 = V_4 -> V_73 ;
V_4 -> V_79 = true ;
}
if ( V_25 -> V_80 != V_4 -> V_75 ) {
V_25 -> V_80 = V_4 -> V_75 ;
V_4 -> V_79 = true ;
}
} else {
F_5 ( V_4 ,
L_9 ) ;
return - V_12 ;
}
} else if ( ( V_4 -> V_10 & V_81 ) != V_81 &&
F_44 ( & V_4 -> V_6 ) ) {
V_4 -> V_73 = V_25 -> V_78 ;
V_4 -> V_75 = V_25 -> V_80 ;
}
return 0 ;
}
STATIC void
F_45 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
T_5 V_82 ;
if ( V_25 -> V_83 ) {
V_82 = V_25 -> V_84 * V_25 -> V_83 ;
F_46 ( V_82 , 100 ) ;
F_46 ( V_82 , V_4 -> V_85 ) ;
V_4 -> V_86 = ( V_82 * V_4 -> V_85 ) <<
V_25 -> V_87 ;
} else {
V_4 -> V_86 = 0 ;
}
}
STATIC void
F_47 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
int V_88 , V_89 ;
if ( ! ( V_4 -> V_10 & V_90 ) ) {
if ( V_4 -> V_10 & V_91 ) {
V_88 = V_92 ;
V_89 = V_93 ;
} else {
V_88 = V_94 ;
V_89 = V_95 ;
}
} else {
V_88 = V_4 -> V_96 ;
V_89 = V_4 -> V_97 ;
}
if ( V_25 -> V_28 > V_88 ) {
V_4 -> V_96 = V_25 -> V_28 ;
} else {
V_4 -> V_96 = V_88 ;
}
V_4 -> V_98 = 1 << ( V_4 -> V_96 - V_25 -> V_28 ) ;
if ( V_25 -> V_28 > V_89 ) {
V_4 -> V_97 = V_25 -> V_28 ;
} else {
V_4 -> V_97 = V_89 ;
}
V_4 -> V_99 = 1 << ( V_4 -> V_97 - V_25 -> V_28 ) ;
}
void
F_48 (
struct V_3 * V_4 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_100 ; V_9 ++ ) {
T_5 V_101 = V_4 -> V_6 . V_84 ;
F_46 ( V_101 , 100 ) ;
V_4 -> V_102 [ V_9 ] = V_101 * ( V_9 + 1 ) ;
}
}
STATIC void
F_49 ( T_2 * V_4 )
{
if ( F_50 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_103 >=
F_51 ( V_4 , V_4 -> V_104 ) )
V_4 -> V_105 = V_4 -> V_6 . V_103 - 1 ;
else
V_4 -> V_105 = 0 ;
if ( V_4 -> V_73 && V_4 -> V_105 &&
! ( V_4 -> V_73 & V_4 -> V_105 ) )
V_4 -> V_106 = V_4 -> V_73 ;
else
V_4 -> V_106 = 0 ;
}
STATIC int
F_52 (
struct V_3 * V_4 )
{
struct V_52 * V_53 ;
T_7 V_107 ;
int error ;
V_107 = ( T_7 ) F_53 ( V_4 , V_4 -> V_6 . V_84 ) ;
if ( F_54 ( V_4 , V_107 ) != V_4 -> V_6 . V_84 ) {
F_5 ( V_4 , L_10 ) ;
return - V_31 ;
}
error = F_34 ( V_4 -> V_60 ,
V_107 - F_55 ( V_4 , 1 ) ,
F_55 ( V_4 , 1 ) , 0 , & V_53 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_11 ) ;
return error ;
}
F_38 ( V_53 ) ;
if ( V_4 -> V_108 == V_4 -> V_60 )
return 0 ;
V_107 = ( T_7 ) F_53 ( V_4 , V_4 -> V_6 . V_109 ) ;
if ( F_54 ( V_4 , V_107 ) != V_4 -> V_6 . V_109 ) {
F_5 ( V_4 , L_12 ) ;
return - V_31 ;
}
error = F_34 ( V_4 -> V_108 ,
V_107 - F_53 ( V_4 , 1 ) ,
F_53 ( V_4 , 1 ) , 0 , & V_53 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_13 ) ;
return error ;
}
F_38 ( V_53 ) ;
return 0 ;
}
int
F_56 (
struct V_3 * V_4 )
{
V_4 -> V_110 = 0 ;
if ( V_4 -> V_6 . V_111 == 0 )
return 0 ;
F_15 ( & V_4 -> V_112 ) ;
V_4 -> V_6 . V_111 = 0 ;
F_17 ( & V_4 -> V_112 ) ;
if ( ! F_57 ( V_4 , V_113 ) )
return 0 ;
return F_58 ( V_4 , false ) ;
}
T_5
F_59 ( T_2 * V_4 )
{
T_5 V_114 ;
V_114 = V_4 -> V_6 . V_84 ;
F_46 ( V_114 , 20 ) ;
V_114 = F_60 ( T_5 , V_114 , 8192 ) ;
return V_114 ;
}
int
F_61 (
struct V_3 * V_4 )
{
struct V_54 * V_25 = & ( V_4 -> V_6 ) ;
struct V_115 * V_116 ;
T_5 V_114 ;
T_8 V_117 = 0 ;
T_8 V_118 = 0 ;
int error = 0 ;
F_62 ( V_4 , V_25 ) ;
if ( F_63 ( V_25 ) ) {
F_5 ( V_4 , L_14 ) ;
V_25 -> V_119 |= V_25 -> V_120 ;
V_4 -> V_79 = true ;
if ( F_64 ( & V_4 -> V_6 ) &&
! ( V_4 -> V_10 & V_121 ) )
V_4 -> V_10 |= V_122 ;
}
if ( F_64 ( & V_4 -> V_6 ) &&
( V_4 -> V_10 & V_121 ) ) {
F_65 ( & V_4 -> V_6 ) ;
V_4 -> V_79 = true ;
if ( ! V_25 -> V_119 )
V_4 -> V_79 = true ;
}
if ( ! ( V_4 -> V_6 . V_123 & V_124 ) ) {
V_4 -> V_6 . V_123 |= V_124 ;
V_4 -> V_79 = true ;
}
error = F_41 ( V_4 ) ;
if ( error )
goto V_125;
F_66 ( V_4 ) ;
F_67 ( V_4 , V_126 ) ;
F_67 ( V_4 , V_127 ) ;
F_68 ( V_4 ) ;
F_45 ( V_4 ) ;
V_4 -> V_128 = 1 ;
error = F_69 ( & V_4 -> V_129 , & V_130 , NULL , V_4 -> V_131 ) ;
if ( error )
goto V_125;
error = F_69 ( & V_4 -> V_132 . V_133 , & V_134 ,
& V_4 -> V_129 , L_15 ) ;
if ( error )
goto V_135;
error = F_70 ( V_4 ) ;
if ( error )
goto V_136;
error = F_3 ( V_4 ) ;
if ( error )
goto V_137;
F_47 ( V_4 ) ;
F_48 ( V_4 ) ;
V_4 -> V_104 = V_138 ;
if ( F_71 ( & V_4 -> V_6 ) ) {
int V_139 = V_4 -> V_104 ;
V_139 *= V_4 -> V_6 . V_140 / V_141 ;
if ( V_4 -> V_6 . V_103 >= F_51 ( V_4 , V_139 ) )
V_4 -> V_104 = V_139 ;
}
if ( F_72 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_142 !=
F_51 ( V_4 , V_4 -> V_104 ) ) {
F_5 ( V_4 ,
L_16 ,
V_4 -> V_6 . V_142 ,
F_51 ( V_4 , V_4 -> V_104 ) ) ;
error = - V_12 ;
goto V_143;
}
F_49 ( V_4 ) ;
error = F_52 ( V_4 ) ;
if ( error )
goto V_143;
error = F_73 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_17 ) ;
goto V_143;
}
F_74 ( & V_25 -> V_7 , V_4 -> V_144 ) ;
V_4 -> V_145 = 0 ;
error = F_75 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_18 , error ) ;
goto V_143;
}
F_76 ( V_4 ) ;
F_24 ( & V_4 -> V_23 ) ;
F_26 ( & V_4 -> V_24 , V_44 ) ;
error = F_20 ( V_4 , V_25 -> V_22 , & V_4 -> V_146 ) ;
if ( error ) {
F_5 ( V_4 , L_19 , error ) ;
goto V_147;
}
if ( ! V_25 -> V_109 ) {
F_5 ( V_4 , L_20 ) ;
F_77 ( L_21 , V_148 , V_4 ) ;
error = - V_64 ;
goto V_149;
}
error = F_78 ( V_4 , V_4 -> V_108 ,
F_79 ( V_4 , V_25 -> V_150 ) ,
F_53 ( V_4 , V_25 -> V_109 ) ) ;
if ( error ) {
F_5 ( V_4 , L_22 ) ;
goto V_151;
}
if ( F_80 ( & V_4 -> V_6 ) &&
! F_81 ( V_4 ) &&
! V_4 -> V_6 . V_152 ) {
error = F_82 ( V_4 , V_25 -> V_22 ) ;
if ( error )
goto V_153;
}
error = F_83 ( V_4 , NULL , V_25 -> V_154 , 0 , V_155 , & V_116 ) ;
if ( error ) {
F_5 ( V_4 , L_23 ) ;
goto V_153;
}
ASSERT ( V_116 != NULL ) ;
if ( F_84 ( ! F_85 ( F_86 ( V_116 ) -> V_156 ) ) ) {
F_5 ( V_4 , L_24 ,
( unsigned long long ) V_116 -> V_157 ) ;
F_87 ( V_116 , V_155 ) ;
F_77 ( L_25 , V_148 ,
V_4 ) ;
error = - V_64 ;
goto V_158;
}
V_4 -> V_159 = V_116 ;
F_87 ( V_116 , V_155 ) ;
error = F_88 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_26 ) ;
goto V_158;
}
if ( V_4 -> V_79 && ! ( V_4 -> V_10 & V_160 ) ) {
error = F_58 ( V_4 , false ) ;
if ( error ) {
F_5 ( V_4 , L_27 ) ;
goto V_161;
}
}
if ( F_89 ( V_4 ) ) {
error = F_90 ( V_4 , & V_117 , & V_118 ) ;
if ( error )
goto V_161;
} else {
ASSERT ( ! F_91 ( V_4 ) ) ;
if ( V_4 -> V_6 . V_111 & V_162 ) {
F_92 ( V_4 , L_28 ) ;
error = F_56 ( V_4 ) ;
if ( error )
goto V_161;
}
}
error = F_93 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_29 ) ;
goto V_161;
}
if ( V_117 ) {
ASSERT ( V_4 -> V_110 == 0 ) ;
V_4 -> V_110 = V_118 ;
F_94 ( V_4 ) ;
}
if ( ! ( V_4 -> V_10 & V_160 ) ) {
V_114 = F_59 ( V_4 ) ;
error = F_95 ( V_4 , & V_114 , NULL ) ;
if ( error )
F_5 ( V_4 ,
L_30 ) ;
}
return 0 ;
V_161:
F_96 ( V_4 ) ;
V_158:
F_97 ( V_116 ) ;
F_98 ( & V_4 -> V_163 ) ;
F_99 ( V_4 , V_164 ) ;
V_153:
V_4 -> V_10 |= V_165 ;
F_100 ( V_4 ) ;
V_151:
if ( V_4 -> V_108 && V_4 -> V_108 != V_4 -> V_60 )
F_101 ( V_4 -> V_108 ) ;
F_101 ( V_4 -> V_60 ) ;
V_149:
F_14 ( V_4 ) ;
V_147:
F_102 ( V_4 ) ;
V_143:
F_10 ( V_4 ) ;
V_137:
F_103 ( V_4 ) ;
V_136:
F_104 ( & V_4 -> V_132 . V_133 ) ;
V_135:
F_104 ( & V_4 -> V_129 ) ;
V_125:
return error ;
}
void
F_105 (
struct V_3 * V_4 )
{
T_5 V_114 ;
int error ;
F_98 ( & V_4 -> V_166 ) ;
F_106 ( V_4 ) ;
F_96 ( V_4 ) ;
F_97 ( V_4 -> V_159 ) ;
F_107 ( V_4 , V_167 ) ;
V_4 -> V_10 |= V_165 ;
F_108 ( V_4 -> V_168 ) ;
F_98 ( & V_4 -> V_163 ) ;
F_99 ( V_4 , V_164 ) ;
F_109 ( V_4 ) ;
V_114 = 0 ;
error = F_95 ( V_4 , & V_114 , NULL ) ;
if ( error )
F_5 ( V_4 , L_31
L_32 ) ;
error = F_110 ( V_4 ) ;
if ( error )
F_5 ( V_4 , L_33
L_32 ) ;
F_111 ( V_4 ) ;
F_102 ( V_4 ) ;
F_10 ( V_4 ) ;
#if F_112 ( V_169 )
F_113 ( V_4 , 0 ) ;
#endif
F_14 ( V_4 ) ;
F_103 ( V_4 ) ;
F_104 ( & V_4 -> V_132 . V_133 ) ;
F_104 ( & V_4 -> V_129 ) ;
}
bool
F_57 (
struct V_3 * V_4 ,
int V_170 )
{
ASSERT ( V_170 > V_171 ) ;
if ( ( V_4 -> V_172 -> V_173 . V_174 >= V_170 ) ||
F_114 ( V_4 ) || ( V_4 -> V_10 & V_160 ) )
return false ;
return true ;
}
int
F_110 ( T_2 * V_4 )
{
if ( ! F_57 ( V_4 , V_175 ) )
return 0 ;
if ( ! F_80 ( & V_4 -> V_6 ) )
return 0 ;
return F_58 ( V_4 , true ) ;
}
int
F_115 (
struct V_3 * V_4 ,
T_9 V_176 )
{
F_116 ( & V_4 -> V_177 , V_176 , V_178 ) ;
if ( F_117 ( & V_4 -> V_177 , 0 , V_178 ) < 0 ) {
ASSERT ( 0 ) ;
F_118 ( & V_4 -> V_177 , - V_176 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_119 (
struct V_3 * V_4 ,
T_9 V_176 )
{
F_118 ( & V_4 -> V_179 , V_176 ) ;
if ( F_120 ( & V_4 -> V_179 , 0 ) < 0 ) {
ASSERT ( 0 ) ;
F_118 ( & V_4 -> V_179 , - V_176 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_121 (
struct V_3 * V_4 ,
T_9 V_176 ,
bool V_180 )
{
T_9 V_181 ;
long long V_182 ;
T_10 V_183 ;
if ( V_176 > 0 ) {
if ( F_122 ( V_4 -> V_184 == V_4 -> V_185 ) ) {
F_118 ( & V_4 -> V_186 , V_176 ) ;
return 0 ;
}
F_15 ( & V_4 -> V_112 ) ;
V_182 = ( long long ) ( V_4 -> V_184 - V_4 -> V_185 ) ;
if ( V_182 > V_176 ) {
V_4 -> V_185 += V_176 ;
} else {
V_176 -= V_182 ;
V_4 -> V_185 = V_4 -> V_184 ;
F_118 ( & V_4 -> V_186 , V_176 ) ;
}
F_17 ( & V_4 -> V_112 ) ;
return 0 ;
}
if ( F_117 ( & V_4 -> V_186 , 2 * V_187 ,
V_187 ) < 0 )
V_183 = 1 ;
else
V_183 = V_187 ;
F_116 ( & V_4 -> V_186 , V_176 , V_183 ) ;
if ( F_117 ( & V_4 -> V_186 , F_123 ( V_4 ) ,
V_187 ) >= 0 ) {
return 0 ;
}
F_15 ( & V_4 -> V_112 ) ;
F_118 ( & V_4 -> V_186 , - V_176 ) ;
if ( ! V_180 )
goto V_188;
V_181 = ( long long ) V_4 -> V_185 + V_176 ;
if ( V_181 >= 0 ) {
V_4 -> V_185 = V_181 ;
F_17 ( & V_4 -> V_112 ) ;
return 0 ;
}
F_124 ( V_189
L_34
L_35 ,
V_4 -> V_131 ) ;
V_188:
F_17 ( & V_4 -> V_112 ) ;
return - V_190 ;
}
int
F_125 (
struct V_3 * V_4 ,
T_9 V_176 )
{
T_9 V_181 ;
int V_191 = 0 ;
F_15 ( & V_4 -> V_112 ) ;
V_181 = V_4 -> V_6 . V_192 + V_176 ;
if ( V_181 < 0 )
V_191 = - V_190 ;
else
V_4 -> V_6 . V_192 = V_181 ;
F_17 ( & V_4 -> V_112 ) ;
return V_191 ;
}
struct V_52 *
F_126 (
struct V_3 * V_4 ,
int V_50 )
{
struct V_52 * V_53 = V_4 -> V_59 ;
if ( ! F_127 ( V_53 ) ) {
if ( V_50 & V_193 )
return NULL ;
F_128 ( V_53 ) ;
}
F_129 ( V_53 ) ;
ASSERT ( V_53 -> V_194 & V_195 ) ;
return V_53 ;
}
void
F_130 (
struct V_3 * V_4 )
{
struct V_52 * V_53 = V_4 -> V_59 ;
F_128 ( V_53 ) ;
V_4 -> V_59 = NULL ;
F_38 ( V_53 ) ;
}
int
F_131 (
struct V_3 * V_4 ,
char * V_196 )
{
if ( F_132 ( V_4 -> V_60 ) ||
F_132 ( V_4 -> V_108 ) ||
( V_4 -> V_197 && F_132 ( V_4 -> V_197 ) ) ) {
F_92 ( V_4 , L_36 , V_196 ) ;
F_92 ( V_4 , L_37 ) ;
return - V_198 ;
}
return 0 ;
}
