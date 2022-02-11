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
F_18 ( V_19 ) ;
F_19 ( & V_19 -> V_16 , F_11 ) ;
}
}
int
F_20 (
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
F_21 (
T_2 * V_4 ,
T_3 V_32 ,
T_3 * V_33 )
{
T_3 V_34 ;
T_3 V_35 = 0 ;
T_6 * V_19 ;
int error = - V_36 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
V_19 = F_22 ( V_4 , V_34 ) ;
if ( V_19 ) {
F_23 ( V_19 ) ;
continue;
}
if ( ! V_35 )
V_35 = V_34 ;
V_19 = F_24 ( sizeof( * V_19 ) , V_37 ) ;
if ( ! V_19 )
goto V_38;
V_19 -> V_39 = V_34 ;
V_19 -> V_40 = V_4 ;
F_25 ( & V_19 -> V_41 ) ;
F_26 ( & V_19 -> V_42 ) ;
F_27 ( & V_19 -> V_43 , V_44 ) ;
if ( F_28 ( V_19 ) )
goto V_38;
if ( F_29 ( V_45 ) )
goto V_38;
F_15 ( & V_4 -> V_23 ) ;
if ( F_30 ( & V_4 -> V_24 , V_34 , V_19 ) ) {
F_31 () ;
F_17 ( & V_4 -> V_23 ) ;
F_32 () ;
error = - V_46 ;
goto V_38;
}
F_17 ( & V_4 -> V_23 ) ;
F_32 () ;
}
V_34 = F_33 ( V_4 , V_32 ) ;
if ( V_33 )
* V_33 = V_34 ;
V_4 -> V_47 = F_34 ( V_4 ) ;
return 0 ;
V_38:
F_18 ( V_19 ) ;
F_2 ( V_19 ) ;
for (; V_34 > V_35 ; V_34 -- ) {
V_19 = F_16 ( & V_4 -> V_24 , V_34 ) ;
F_18 ( V_19 ) ;
F_2 ( V_19 ) ;
}
return error ;
}
int
F_35 (
struct V_3 * V_4 ,
int V_48 )
{
unsigned int V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_25 = & V_4 -> V_6 ;
int error ;
int V_53 = ! ( V_48 & V_54 ) ;
const struct V_55 * V_56 ;
ASSERT ( V_4 -> V_57 == NULL ) ;
ASSERT ( V_4 -> V_58 != NULL ) ;
V_49 = F_36 ( V_4 -> V_58 ) ;
V_56 = NULL ;
V_59:
error = F_37 ( V_4 -> V_58 , V_60 ,
F_38 ( V_49 ) , V_61 , & V_51 ,
V_56 ) ;
if ( error ) {
if ( V_53 )
F_5 ( V_4 , L_3 , error ) ;
if ( error == - V_62 )
error = - V_63 ;
return error ;
}
F_39 ( V_25 , F_40 ( V_51 ) ) ;
if ( V_25 -> V_64 != V_65 ) {
if ( V_53 )
F_5 ( V_4 , L_4 ) ;
error = - V_12 ;
goto V_66;
}
if ( V_49 > V_25 -> V_67 ) {
if ( V_53 )
F_5 ( V_4 , L_5 ,
V_49 , V_25 -> V_67 ) ;
error = - V_68 ;
goto V_66;
}
if ( V_56 == NULL ) {
F_41 ( V_51 ) ;
V_49 = V_25 -> V_67 ;
V_56 = V_53 ? & V_69 : & V_70 ;
goto V_59;
}
F_42 ( V_4 ) ;
V_51 -> V_71 = & V_69 ;
V_4 -> V_57 = V_51 ;
F_43 ( V_51 ) ;
return 0 ;
V_66:
F_41 ( V_51 ) ;
return error ;
}
STATIC int
F_44 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
if ( V_4 -> V_72 ) {
if ( ( F_45 ( V_4 -> V_72 ) & V_4 -> V_73 ) ||
( F_45 ( V_4 -> V_74 ) & V_4 -> V_73 ) ) {
F_5 ( V_4 ,
L_6 ,
V_25 -> V_75 ) ;
return - V_12 ;
} else {
V_4 -> V_72 = F_46 ( V_4 , V_4 -> V_72 ) ;
if ( V_4 -> V_72 && ( V_25 -> V_76 % V_4 -> V_72 ) ) {
F_5 ( V_4 ,
L_7 ,
V_25 -> V_76 ) ;
return - V_12 ;
} else if ( V_4 -> V_72 ) {
V_4 -> V_74 = F_46 ( V_4 , V_4 -> V_74 ) ;
} else {
F_5 ( V_4 ,
L_8 ,
V_4 -> V_72 , V_25 -> V_75 ) ;
return - V_12 ;
}
}
if ( F_47 ( V_25 ) ) {
if ( V_25 -> V_77 != V_4 -> V_72 ) {
V_25 -> V_77 = V_4 -> V_72 ;
V_4 -> V_78 = true ;
}
if ( V_25 -> V_79 != V_4 -> V_74 ) {
V_25 -> V_79 = V_4 -> V_74 ;
V_4 -> V_78 = true ;
}
} else {
F_5 ( V_4 ,
L_9 ) ;
return - V_12 ;
}
} else if ( ( V_4 -> V_10 & V_80 ) != V_80 &&
F_47 ( & V_4 -> V_6 ) ) {
V_4 -> V_72 = V_25 -> V_77 ;
V_4 -> V_74 = V_25 -> V_79 ;
}
return 0 ;
}
STATIC void
F_48 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
T_5 V_81 ;
if ( V_25 -> V_82 ) {
V_81 = V_25 -> V_83 * V_25 -> V_82 ;
F_49 ( V_81 , 100 ) ;
F_49 ( V_81 , V_4 -> V_84 ) ;
V_4 -> V_85 = ( V_81 * V_4 -> V_84 ) <<
V_25 -> V_86 ;
} else {
V_4 -> V_85 = 0 ;
}
}
STATIC void
F_50 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
int V_87 , V_88 ;
if ( ! ( V_4 -> V_10 & V_89 ) ) {
if ( V_4 -> V_10 & V_90 ) {
V_87 = V_91 ;
V_88 = V_92 ;
} else {
V_87 = V_93 ;
V_88 = V_94 ;
}
} else {
V_87 = V_4 -> V_95 ;
V_88 = V_4 -> V_96 ;
}
if ( V_25 -> V_28 > V_87 ) {
V_4 -> V_95 = V_25 -> V_28 ;
} else {
V_4 -> V_95 = V_87 ;
}
V_4 -> V_97 = 1 << ( V_4 -> V_95 - V_25 -> V_28 ) ;
if ( V_25 -> V_28 > V_88 ) {
V_4 -> V_96 = V_25 -> V_28 ;
} else {
V_4 -> V_96 = V_88 ;
}
V_4 -> V_98 = 1 << ( V_4 -> V_96 - V_25 -> V_28 ) ;
}
void
F_51 (
struct V_3 * V_4 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_99 ; V_9 ++ ) {
T_5 V_100 = V_4 -> V_6 . V_83 ;
F_49 ( V_100 , 100 ) ;
V_4 -> V_101 [ V_9 ] = V_100 * ( V_9 + 1 ) ;
}
}
STATIC void
F_52 ( T_2 * V_4 )
{
if ( F_53 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_102 >=
F_54 ( V_4 , V_4 -> V_103 ) )
V_4 -> V_104 = V_4 -> V_6 . V_102 - 1 ;
else
V_4 -> V_104 = 0 ;
if ( V_4 -> V_72 && V_4 -> V_104 &&
! ( V_4 -> V_72 & V_4 -> V_104 ) )
V_4 -> V_105 = V_4 -> V_72 ;
else
V_4 -> V_105 = 0 ;
}
STATIC int
F_55 (
struct V_3 * V_4 )
{
struct V_50 * V_51 ;
T_7 V_106 ;
int error ;
V_106 = ( T_7 ) F_56 ( V_4 , V_4 -> V_6 . V_83 ) ;
if ( F_57 ( V_4 , V_106 ) != V_4 -> V_6 . V_83 ) {
F_5 ( V_4 , L_10 ) ;
return - V_31 ;
}
error = F_37 ( V_4 -> V_58 ,
V_106 - F_58 ( V_4 , 1 ) ,
F_58 ( V_4 , 1 ) , 0 , & V_51 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_11 ) ;
return error ;
}
F_41 ( V_51 ) ;
if ( V_4 -> V_107 == V_4 -> V_58 )
return 0 ;
V_106 = ( T_7 ) F_56 ( V_4 , V_4 -> V_6 . V_108 ) ;
if ( F_57 ( V_4 , V_106 ) != V_4 -> V_6 . V_108 ) {
F_5 ( V_4 , L_12 ) ;
return - V_31 ;
}
error = F_37 ( V_4 -> V_107 ,
V_106 - F_56 ( V_4 , 1 ) ,
F_56 ( V_4 , 1 ) , 0 , & V_51 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_13 ) ;
return error ;
}
F_41 ( V_51 ) ;
return 0 ;
}
int
F_59 (
struct V_3 * V_4 )
{
V_4 -> V_109 = 0 ;
if ( V_4 -> V_6 . V_110 == 0 )
return 0 ;
F_15 ( & V_4 -> V_111 ) ;
V_4 -> V_6 . V_110 = 0 ;
F_17 ( & V_4 -> V_111 ) ;
if ( ! F_60 ( V_4 , V_112 ) )
return 0 ;
return F_61 ( V_4 , false ) ;
}
T_5
F_62 ( T_2 * V_4 )
{
T_5 V_113 ;
V_113 = V_4 -> V_6 . V_83 ;
F_49 ( V_113 , 20 ) ;
V_113 = F_63 ( T_5 , V_113 , 8192 ) ;
return V_113 ;
}
int
F_64 (
struct V_3 * V_4 )
{
struct V_52 * V_25 = & ( V_4 -> V_6 ) ;
struct V_114 * V_115 ;
T_5 V_113 ;
T_8 V_116 = 0 ;
T_8 V_117 = 0 ;
int error = 0 ;
F_65 ( V_4 , V_25 ) ;
if ( F_66 ( V_25 ) ) {
F_5 ( V_4 , L_14 ) ;
V_25 -> V_118 |= V_25 -> V_119 ;
V_4 -> V_78 = true ;
if ( F_67 ( & V_4 -> V_6 ) &&
! ( V_4 -> V_10 & V_120 ) )
V_4 -> V_10 |= V_121 ;
}
if ( F_67 ( & V_4 -> V_6 ) &&
( V_4 -> V_10 & V_120 ) ) {
F_68 ( & V_4 -> V_6 ) ;
V_4 -> V_78 = true ;
if ( ! V_25 -> V_118 )
V_4 -> V_78 = true ;
}
if ( ! ( V_4 -> V_6 . V_122 & V_123 ) ) {
V_4 -> V_6 . V_122 |= V_123 ;
V_4 -> V_78 = true ;
}
error = F_44 ( V_4 ) ;
if ( error )
goto V_124;
F_69 ( V_4 ) ;
F_70 ( V_4 , V_125 ) ;
F_70 ( V_4 , V_126 ) ;
F_71 ( V_4 ) ;
F_72 ( V_4 ) ;
F_73 ( V_4 ) ;
F_48 ( V_4 ) ;
V_4 -> V_127 = 1 ;
error = F_74 ( & V_4 -> V_128 , & V_129 , NULL , V_4 -> V_130 ) ;
if ( error )
goto V_124;
error = F_74 ( & V_4 -> V_131 . V_132 , & V_133 ,
& V_4 -> V_128 , L_15 ) ;
if ( error )
goto V_134;
error = F_75 ( V_4 ) ;
if ( error )
goto V_135;
error = F_3 ( V_4 ) ;
if ( error )
goto V_136;
F_50 ( V_4 ) ;
F_51 ( V_4 ) ;
V_4 -> V_103 = V_137 ;
if ( F_76 ( & V_4 -> V_6 ) ) {
int V_138 = V_4 -> V_103 ;
V_138 *= V_4 -> V_6 . V_139 / V_140 ;
if ( V_4 -> V_6 . V_102 >= F_54 ( V_4 , V_138 ) )
V_4 -> V_103 = V_138 ;
}
if ( F_77 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_141 !=
F_54 ( V_4 , V_4 -> V_103 ) ) {
F_5 ( V_4 ,
L_16 ,
V_4 -> V_6 . V_141 ,
F_54 ( V_4 , V_4 -> V_103 ) ) ;
error = - V_12 ;
goto V_142;
}
F_52 ( V_4 ) ;
error = F_55 ( V_4 ) ;
if ( error )
goto V_142;
error = F_78 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_17 ) ;
goto V_142;
}
F_79 ( & V_25 -> V_7 , V_4 -> V_143 ) ;
V_4 -> V_144 = 0 ;
error = F_80 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_18 , error ) ;
goto V_142;
}
F_81 ( V_4 ) ;
F_25 ( & V_4 -> V_23 ) ;
F_27 ( & V_4 -> V_24 , V_44 ) ;
error = F_21 ( V_4 , V_25 -> V_22 , & V_4 -> V_145 ) ;
if ( error ) {
F_5 ( V_4 , L_19 , error ) ;
goto V_146;
}
if ( ! V_25 -> V_108 ) {
F_5 ( V_4 , L_20 ) ;
F_82 ( L_21 , V_147 , V_4 ) ;
error = - V_63 ;
goto V_148;
}
error = F_83 ( V_4 , V_4 -> V_107 ,
F_84 ( V_4 , V_25 -> V_149 ) ,
F_56 ( V_4 , V_25 -> V_108 ) ) ;
if ( error ) {
F_5 ( V_4 , L_22 ) ;
goto V_150;
}
if ( F_85 ( & V_4 -> V_6 ) &&
! F_86 ( V_4 ) &&
! V_4 -> V_6 . V_151 ) {
error = F_87 ( V_4 , V_25 -> V_22 ) ;
if ( error )
goto V_152;
}
error = F_88 ( V_4 , NULL , V_25 -> V_153 , 0 , V_154 , & V_115 ) ;
if ( error ) {
F_5 ( V_4 , L_23 ) ;
goto V_152;
}
ASSERT ( V_115 != NULL ) ;
if ( F_89 ( ! F_90 ( F_91 ( V_115 ) -> V_155 ) ) ) {
F_5 ( V_4 , L_24 ,
( unsigned long long ) V_115 -> V_156 ) ;
F_92 ( V_115 , V_154 ) ;
F_82 ( L_25 , V_147 ,
V_4 ) ;
error = - V_63 ;
goto V_157;
}
V_4 -> V_158 = V_115 ;
F_92 ( V_115 , V_154 ) ;
error = F_93 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_26 ) ;
goto V_157;
}
if ( V_4 -> V_78 && ! ( V_4 -> V_10 & V_159 ) ) {
error = F_61 ( V_4 , false ) ;
if ( error ) {
F_5 ( V_4 , L_27 ) ;
goto V_160;
}
}
if ( F_94 ( V_4 ) ) {
error = F_95 ( V_4 , & V_116 , & V_117 ) ;
if ( error )
goto V_160;
} else {
ASSERT ( ! F_96 ( V_4 ) ) ;
if ( V_4 -> V_6 . V_110 & V_161 ) {
F_97 ( V_4 , L_28 ) ;
error = F_59 ( V_4 ) ;
if ( error )
goto V_160;
}
}
V_4 -> V_162 -> V_163 |= V_164 ;
error = F_98 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_29 ) ;
goto V_160;
}
if ( ( V_4 -> V_10 & ( V_159 | V_165 ) ) ==
V_159 ) {
F_99 ( V_4 ) ;
}
if ( V_116 ) {
ASSERT ( V_4 -> V_109 == 0 ) ;
V_4 -> V_109 = V_117 ;
F_100 ( V_4 ) ;
}
if ( ! ( V_4 -> V_10 & V_159 ) ) {
V_113 = F_62 ( V_4 ) ;
error = F_101 ( V_4 , & V_113 , NULL ) ;
if ( error )
F_5 ( V_4 ,
L_30 ) ;
error = F_102 ( V_4 ) ;
if ( error ) {
F_103 ( V_4 ,
L_31 , error ) ;
F_104 ( V_4 , V_166 ) ;
goto V_167;
}
error = F_105 ( V_4 ) ;
if ( error && error != - V_168 )
goto V_169;
}
return 0 ;
V_169:
F_106 ( V_4 ) ;
V_167:
F_107 ( V_4 ) ;
V_160:
V_4 -> V_162 -> V_163 &= ~ V_164 ;
F_108 ( V_4 ) ;
V_157:
F_109 ( V_115 ) ;
F_110 ( & V_4 -> V_170 ) ;
F_111 ( V_4 , V_171 ) ;
V_152:
V_4 -> V_10 |= V_172 ;
F_112 ( V_4 ) ;
V_150:
if ( V_4 -> V_107 && V_4 -> V_107 != V_4 -> V_58 )
F_113 ( V_4 -> V_107 ) ;
F_113 ( V_4 -> V_58 ) ;
V_148:
F_14 ( V_4 ) ;
V_146:
F_114 ( V_4 ) ;
V_142:
F_10 ( V_4 ) ;
V_136:
F_115 ( V_4 ) ;
V_135:
F_116 ( & V_4 -> V_131 . V_132 ) ;
V_134:
F_116 ( & V_4 -> V_128 ) ;
V_124:
return error ;
}
void
F_117 (
struct V_3 * V_4 )
{
T_5 V_113 ;
int error ;
F_110 ( & V_4 -> V_173 ) ;
F_110 ( & V_4 -> V_174 ) ;
F_106 ( V_4 ) ;
F_107 ( V_4 ) ;
F_108 ( V_4 ) ;
F_109 ( V_4 -> V_158 ) ;
F_118 ( V_4 , V_175 ) ;
V_4 -> V_10 |= V_172 ;
F_119 ( V_4 -> V_176 ) ;
F_110 ( & V_4 -> V_170 ) ;
F_111 ( V_4 , V_171 ) ;
F_120 ( V_4 ) ;
V_113 = 0 ;
error = F_101 ( V_4 , & V_113 , NULL ) ;
if ( error )
F_5 ( V_4 , L_32
L_33 ) ;
error = F_121 ( V_4 ) ;
if ( error )
F_5 ( V_4 , L_34
L_33 ) ;
F_122 ( V_4 ) ;
F_114 ( V_4 ) ;
F_10 ( V_4 ) ;
#if F_123 ( V_177 )
F_124 ( V_4 , 0 ) ;
#endif
F_14 ( V_4 ) ;
F_115 ( V_4 ) ;
F_116 ( & V_4 -> V_131 . V_132 ) ;
F_116 ( & V_4 -> V_128 ) ;
}
bool
F_60 (
struct V_3 * V_4 ,
int V_178 )
{
ASSERT ( V_178 > V_179 ) ;
if ( ( V_4 -> V_162 -> V_180 . V_181 >= V_178 ) ||
F_125 ( V_4 ) || ( V_4 -> V_10 & V_159 ) )
return false ;
return true ;
}
int
F_121 ( T_2 * V_4 )
{
if ( ! F_60 ( V_4 , V_182 ) )
return 0 ;
if ( ! F_85 ( & V_4 -> V_6 ) )
return 0 ;
return F_61 ( V_4 , true ) ;
}
int
F_126 (
struct V_3 * V_4 ,
T_9 V_183 )
{
F_127 ( & V_4 -> V_184 , V_183 , V_185 ) ;
if ( F_128 ( & V_4 -> V_184 , 0 , V_185 ) < 0 ) {
ASSERT ( 0 ) ;
F_129 ( & V_4 -> V_184 , - V_183 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_130 (
struct V_3 * V_4 ,
T_9 V_183 )
{
F_129 ( & V_4 -> V_186 , V_183 ) ;
if ( F_131 ( & V_4 -> V_186 , 0 ) < 0 ) {
ASSERT ( 0 ) ;
F_129 ( & V_4 -> V_186 , - V_183 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_132 (
struct V_3 * V_4 ,
T_9 V_183 ,
bool V_187 )
{
T_9 V_188 ;
long long V_189 ;
T_10 V_190 ;
if ( V_183 > 0 ) {
if ( F_133 ( V_4 -> V_191 == V_4 -> V_192 ) ) {
F_129 ( & V_4 -> V_193 , V_183 ) ;
return 0 ;
}
F_15 ( & V_4 -> V_111 ) ;
V_189 = ( long long ) ( V_4 -> V_191 - V_4 -> V_192 ) ;
if ( V_189 > V_183 ) {
V_4 -> V_192 += V_183 ;
} else {
V_183 -= V_189 ;
V_4 -> V_192 = V_4 -> V_191 ;
F_129 ( & V_4 -> V_193 , V_183 ) ;
}
F_17 ( & V_4 -> V_111 ) ;
return 0 ;
}
if ( F_128 ( & V_4 -> V_193 , 2 * V_194 ,
V_194 ) < 0 )
V_190 = 1 ;
else
V_190 = V_194 ;
F_127 ( & V_4 -> V_193 , V_183 , V_190 ) ;
if ( F_128 ( & V_4 -> V_193 , V_4 -> V_195 ,
V_194 ) >= 0 ) {
return 0 ;
}
F_15 ( & V_4 -> V_111 ) ;
F_129 ( & V_4 -> V_193 , - V_183 ) ;
if ( ! V_187 )
goto V_196;
V_188 = ( long long ) V_4 -> V_192 + V_183 ;
if ( V_188 >= 0 ) {
V_4 -> V_192 = V_188 ;
F_17 ( & V_4 -> V_111 ) ;
return 0 ;
}
F_134 ( V_197
L_35
L_36 ,
V_4 -> V_130 ) ;
V_196:
F_17 ( & V_4 -> V_111 ) ;
return - V_168 ;
}
int
F_135 (
struct V_3 * V_4 ,
T_9 V_183 )
{
T_9 V_188 ;
int V_198 = 0 ;
F_15 ( & V_4 -> V_111 ) ;
V_188 = V_4 -> V_6 . V_199 + V_183 ;
if ( V_188 < 0 )
V_198 = - V_168 ;
else
V_4 -> V_6 . V_199 = V_188 ;
F_17 ( & V_4 -> V_111 ) ;
return V_198 ;
}
struct V_50 *
F_136 (
struct V_3 * V_4 ,
int V_48 )
{
struct V_50 * V_51 = V_4 -> V_57 ;
if ( ! F_137 ( V_51 ) ) {
if ( V_48 & V_200 )
return NULL ;
F_138 ( V_51 ) ;
}
F_139 ( V_51 ) ;
ASSERT ( V_51 -> V_201 & V_202 ) ;
return V_51 ;
}
void
F_140 (
struct V_3 * V_4 )
{
struct V_50 * V_51 = V_4 -> V_57 ;
F_138 ( V_51 ) ;
V_4 -> V_57 = NULL ;
F_41 ( V_51 ) ;
}
int
F_141 (
struct V_3 * V_4 ,
char * V_203 )
{
if ( F_142 ( V_4 -> V_58 ) ||
F_142 ( V_4 -> V_107 ) ||
( V_4 -> V_204 && F_142 ( V_4 -> V_204 ) ) ) {
F_97 ( V_4 , L_37 , V_203 ) ;
F_97 ( V_4 , L_38 ) ;
return - V_205 ;
}
return 0 ;
}
