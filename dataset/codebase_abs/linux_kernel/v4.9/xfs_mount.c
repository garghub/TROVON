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
V_4 -> V_50 = F_32 ( V_4 ) ;
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
F_33 (
struct V_3 * V_4 ,
int V_51 )
{
unsigned int V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_25 = & V_4 -> V_6 ;
int error ;
int V_56 = ! ( V_51 & V_57 ) ;
const struct V_58 * V_59 ;
ASSERT ( V_4 -> V_60 == NULL ) ;
ASSERT ( V_4 -> V_61 != NULL ) ;
V_52 = F_34 ( V_4 -> V_61 ) ;
V_59 = NULL ;
V_62:
error = F_35 ( V_4 -> V_61 , V_63 ,
F_36 ( V_52 ) , V_64 , & V_54 ,
V_59 ) ;
if ( error ) {
if ( V_56 )
F_5 ( V_4 , L_3 , error ) ;
if ( error == - V_65 )
error = - V_66 ;
return error ;
}
F_37 ( V_25 , F_38 ( V_54 ) ) ;
if ( V_25 -> V_67 != V_68 ) {
if ( V_56 )
F_5 ( V_4 , L_4 ) ;
error = - V_12 ;
goto V_69;
}
if ( V_52 > V_25 -> V_70 ) {
if ( V_56 )
F_5 ( V_4 , L_5 ,
V_52 , V_25 -> V_70 ) ;
error = - V_71 ;
goto V_69;
}
if ( V_59 == NULL ) {
F_39 ( V_54 ) ;
V_52 = V_25 -> V_70 ;
V_59 = V_56 ? & V_72 : & V_73 ;
goto V_62;
}
F_40 ( V_4 ) ;
V_54 -> V_74 = & V_72 ;
V_4 -> V_60 = V_54 ;
F_41 ( V_54 ) ;
return 0 ;
V_69:
F_39 ( V_54 ) ;
return error ;
}
STATIC int
F_42 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
if ( V_4 -> V_75 ) {
if ( ( F_43 ( V_4 -> V_75 ) & V_4 -> V_76 ) ||
( F_43 ( V_4 -> V_77 ) & V_4 -> V_76 ) ) {
F_5 ( V_4 ,
L_6 ,
V_25 -> V_78 ) ;
return - V_12 ;
} else {
V_4 -> V_75 = F_44 ( V_4 , V_4 -> V_75 ) ;
if ( V_4 -> V_75 && ( V_25 -> V_79 % V_4 -> V_75 ) ) {
F_5 ( V_4 ,
L_7 ,
V_25 -> V_79 ) ;
return - V_12 ;
} else if ( V_4 -> V_75 ) {
V_4 -> V_77 = F_44 ( V_4 , V_4 -> V_77 ) ;
} else {
F_5 ( V_4 ,
L_8 ,
V_4 -> V_75 , V_25 -> V_78 ) ;
return - V_12 ;
}
}
if ( F_45 ( V_25 ) ) {
if ( V_25 -> V_80 != V_4 -> V_75 ) {
V_25 -> V_80 = V_4 -> V_75 ;
V_4 -> V_81 = true ;
}
if ( V_25 -> V_82 != V_4 -> V_77 ) {
V_25 -> V_82 = V_4 -> V_77 ;
V_4 -> V_81 = true ;
}
} else {
F_5 ( V_4 ,
L_9 ) ;
return - V_12 ;
}
} else if ( ( V_4 -> V_10 & V_83 ) != V_83 &&
F_45 ( & V_4 -> V_6 ) ) {
V_4 -> V_75 = V_25 -> V_80 ;
V_4 -> V_77 = V_25 -> V_82 ;
}
return 0 ;
}
STATIC void
F_46 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
T_5 V_84 ;
if ( V_25 -> V_85 ) {
V_84 = V_25 -> V_86 * V_25 -> V_85 ;
F_47 ( V_84 , 100 ) ;
F_47 ( V_84 , V_4 -> V_87 ) ;
V_4 -> V_88 = ( V_84 * V_4 -> V_87 ) <<
V_25 -> V_89 ;
} else {
V_4 -> V_88 = 0 ;
}
}
STATIC void
F_48 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
int V_90 , V_91 ;
if ( ! ( V_4 -> V_10 & V_92 ) ) {
if ( V_4 -> V_10 & V_93 ) {
V_90 = V_94 ;
V_91 = V_95 ;
} else {
V_90 = V_96 ;
V_91 = V_97 ;
}
} else {
V_90 = V_4 -> V_98 ;
V_91 = V_4 -> V_99 ;
}
if ( V_25 -> V_28 > V_90 ) {
V_4 -> V_98 = V_25 -> V_28 ;
} else {
V_4 -> V_98 = V_90 ;
}
V_4 -> V_100 = 1 << ( V_4 -> V_98 - V_25 -> V_28 ) ;
if ( V_25 -> V_28 > V_91 ) {
V_4 -> V_99 = V_25 -> V_28 ;
} else {
V_4 -> V_99 = V_91 ;
}
V_4 -> V_101 = 1 << ( V_4 -> V_99 - V_25 -> V_28 ) ;
}
void
F_49 (
struct V_3 * V_4 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_102 ; V_9 ++ ) {
T_5 V_103 = V_4 -> V_6 . V_86 ;
F_47 ( V_103 , 100 ) ;
V_4 -> V_104 [ V_9 ] = V_103 * ( V_9 + 1 ) ;
}
}
STATIC void
F_50 ( T_2 * V_4 )
{
if ( F_51 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_105 >=
F_52 ( V_4 , V_4 -> V_106 ) )
V_4 -> V_107 = V_4 -> V_6 . V_105 - 1 ;
else
V_4 -> V_107 = 0 ;
if ( V_4 -> V_75 && V_4 -> V_107 &&
! ( V_4 -> V_75 & V_4 -> V_107 ) )
V_4 -> V_108 = V_4 -> V_75 ;
else
V_4 -> V_108 = 0 ;
}
STATIC int
F_53 (
struct V_3 * V_4 )
{
struct V_53 * V_54 ;
T_7 V_109 ;
int error ;
V_109 = ( T_7 ) F_54 ( V_4 , V_4 -> V_6 . V_86 ) ;
if ( F_55 ( V_4 , V_109 ) != V_4 -> V_6 . V_86 ) {
F_5 ( V_4 , L_10 ) ;
return - V_31 ;
}
error = F_35 ( V_4 -> V_61 ,
V_109 - F_56 ( V_4 , 1 ) ,
F_56 ( V_4 , 1 ) , 0 , & V_54 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_11 ) ;
return error ;
}
F_39 ( V_54 ) ;
if ( V_4 -> V_110 == V_4 -> V_61 )
return 0 ;
V_109 = ( T_7 ) F_54 ( V_4 , V_4 -> V_6 . V_111 ) ;
if ( F_55 ( V_4 , V_109 ) != V_4 -> V_6 . V_111 ) {
F_5 ( V_4 , L_12 ) ;
return - V_31 ;
}
error = F_35 ( V_4 -> V_110 ,
V_109 - F_54 ( V_4 , 1 ) ,
F_54 ( V_4 , 1 ) , 0 , & V_54 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_13 ) ;
return error ;
}
F_39 ( V_54 ) ;
return 0 ;
}
int
F_57 (
struct V_3 * V_4 )
{
V_4 -> V_112 = 0 ;
if ( V_4 -> V_6 . V_113 == 0 )
return 0 ;
F_15 ( & V_4 -> V_114 ) ;
V_4 -> V_6 . V_113 = 0 ;
F_17 ( & V_4 -> V_114 ) ;
if ( ! F_58 ( V_4 , V_115 ) )
return 0 ;
return F_59 ( V_4 , false ) ;
}
T_5
F_60 ( T_2 * V_4 )
{
T_5 V_116 ;
V_116 = V_4 -> V_6 . V_86 ;
F_47 ( V_116 , 20 ) ;
V_116 = F_61 ( T_5 , V_116 , 8192 ) ;
return V_116 ;
}
int
F_62 (
struct V_3 * V_4 )
{
struct V_55 * V_25 = & ( V_4 -> V_6 ) ;
struct V_117 * V_118 ;
T_5 V_116 ;
T_8 V_119 = 0 ;
T_8 V_120 = 0 ;
int error = 0 ;
F_63 ( V_4 , V_25 ) ;
if ( F_64 ( V_25 ) ) {
F_5 ( V_4 , L_14 ) ;
V_25 -> V_121 |= V_25 -> V_122 ;
V_4 -> V_81 = true ;
if ( F_65 ( & V_4 -> V_6 ) &&
! ( V_4 -> V_10 & V_123 ) )
V_4 -> V_10 |= V_124 ;
}
if ( F_65 ( & V_4 -> V_6 ) &&
( V_4 -> V_10 & V_123 ) ) {
F_66 ( & V_4 -> V_6 ) ;
V_4 -> V_81 = true ;
if ( ! V_25 -> V_121 )
V_4 -> V_81 = true ;
}
if ( ! ( V_4 -> V_6 . V_125 & V_126 ) ) {
V_4 -> V_6 . V_125 |= V_126 ;
V_4 -> V_81 = true ;
}
error = F_42 ( V_4 ) ;
if ( error )
goto V_127;
F_67 ( V_4 ) ;
F_68 ( V_4 , V_128 ) ;
F_68 ( V_4 , V_129 ) ;
F_69 ( V_4 ) ;
F_70 ( V_4 ) ;
F_71 ( V_4 ) ;
F_46 ( V_4 ) ;
V_4 -> V_130 = 1 ;
error = F_72 ( & V_4 -> V_131 , & V_132 , NULL , V_4 -> V_133 ) ;
if ( error )
goto V_127;
error = F_72 ( & V_4 -> V_134 . V_135 , & V_136 ,
& V_4 -> V_131 , L_15 ) ;
if ( error )
goto V_137;
error = F_73 ( V_4 ) ;
if ( error )
goto V_138;
error = F_3 ( V_4 ) ;
if ( error )
goto V_139;
F_48 ( V_4 ) ;
F_49 ( V_4 ) ;
V_4 -> V_106 = V_140 ;
if ( F_74 ( & V_4 -> V_6 ) ) {
int V_141 = V_4 -> V_106 ;
V_141 *= V_4 -> V_6 . V_142 / V_143 ;
if ( V_4 -> V_6 . V_105 >= F_52 ( V_4 , V_141 ) )
V_4 -> V_106 = V_141 ;
}
if ( F_75 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_144 !=
F_52 ( V_4 , V_4 -> V_106 ) ) {
F_5 ( V_4 ,
L_16 ,
V_4 -> V_6 . V_144 ,
F_52 ( V_4 , V_4 -> V_106 ) ) ;
error = - V_12 ;
goto V_145;
}
F_50 ( V_4 ) ;
error = F_53 ( V_4 ) ;
if ( error )
goto V_145;
error = F_76 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_17 ) ;
goto V_145;
}
F_77 ( & V_25 -> V_7 , V_4 -> V_146 ) ;
V_4 -> V_147 = 0 ;
error = F_78 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_18 , error ) ;
goto V_145;
}
F_79 ( V_4 ) ;
F_24 ( & V_4 -> V_23 ) ;
F_26 ( & V_4 -> V_24 , V_44 ) ;
error = F_20 ( V_4 , V_25 -> V_22 , & V_4 -> V_148 ) ;
if ( error ) {
F_5 ( V_4 , L_19 , error ) ;
goto V_149;
}
if ( ! V_25 -> V_111 ) {
F_5 ( V_4 , L_20 ) ;
F_80 ( L_21 , V_150 , V_4 ) ;
error = - V_66 ;
goto V_151;
}
error = F_81 ( V_4 , V_4 -> V_110 ,
F_82 ( V_4 , V_25 -> V_152 ) ,
F_54 ( V_4 , V_25 -> V_111 ) ) ;
if ( error ) {
F_5 ( V_4 , L_22 ) ;
goto V_153;
}
if ( F_83 ( & V_4 -> V_6 ) &&
! F_84 ( V_4 ) &&
! V_4 -> V_6 . V_154 ) {
error = F_85 ( V_4 , V_25 -> V_22 ) ;
if ( error )
goto V_155;
}
error = F_86 ( V_4 , NULL , V_25 -> V_156 , 0 , V_157 , & V_118 ) ;
if ( error ) {
F_5 ( V_4 , L_23 ) ;
goto V_155;
}
ASSERT ( V_118 != NULL ) ;
if ( F_87 ( ! F_88 ( F_89 ( V_118 ) -> V_158 ) ) ) {
F_5 ( V_4 , L_24 ,
( unsigned long long ) V_118 -> V_159 ) ;
F_90 ( V_118 , V_157 ) ;
F_80 ( L_25 , V_150 ,
V_4 ) ;
error = - V_66 ;
goto V_160;
}
V_4 -> V_161 = V_118 ;
F_90 ( V_118 , V_157 ) ;
error = F_91 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_26 ) ;
goto V_160;
}
if ( V_4 -> V_81 && ! ( V_4 -> V_10 & V_162 ) ) {
error = F_59 ( V_4 , false ) ;
if ( error ) {
F_5 ( V_4 , L_27 ) ;
goto V_163;
}
}
if ( F_92 ( V_4 ) ) {
error = F_93 ( V_4 , & V_119 , & V_120 ) ;
if ( error )
goto V_163;
} else {
ASSERT ( ! F_94 ( V_4 ) ) ;
if ( V_4 -> V_6 . V_113 & V_164 ) {
F_95 ( V_4 , L_28 ) ;
error = F_57 ( V_4 ) ;
if ( error )
goto V_163;
}
}
V_4 -> V_165 -> V_166 |= V_167 ;
error = F_96 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_29 ) ;
goto V_163;
}
if ( ( V_4 -> V_10 & ( V_162 | V_168 ) ) ==
V_162 ) {
F_97 ( V_4 ) ;
}
if ( V_119 ) {
ASSERT ( V_4 -> V_112 == 0 ) ;
V_4 -> V_112 = V_120 ;
F_98 ( V_4 ) ;
}
if ( ! ( V_4 -> V_10 & V_162 ) ) {
V_116 = F_60 ( V_4 ) ;
error = F_99 ( V_4 , & V_116 , NULL ) ;
if ( error )
F_5 ( V_4 ,
L_30 ) ;
error = F_100 ( V_4 ) ;
if ( error ) {
F_101 ( V_4 ,
L_31 , error ) ;
F_102 ( V_4 , V_169 ) ;
goto V_170;
}
error = F_103 ( V_4 ) ;
if ( error && error != - V_171 )
goto V_172;
}
return 0 ;
V_172:
F_104 ( V_4 ) ;
V_170:
F_105 ( V_4 ) ;
V_163:
V_4 -> V_165 -> V_166 &= ~ V_167 ;
F_106 ( V_4 ) ;
V_160:
F_107 ( V_118 ) ;
F_108 ( & V_4 -> V_173 ) ;
F_109 ( V_4 , V_174 ) ;
V_155:
V_4 -> V_10 |= V_175 ;
F_110 ( V_4 ) ;
V_153:
if ( V_4 -> V_110 && V_4 -> V_110 != V_4 -> V_61 )
F_111 ( V_4 -> V_110 ) ;
F_111 ( V_4 -> V_61 ) ;
V_151:
F_14 ( V_4 ) ;
V_149:
F_112 ( V_4 ) ;
V_145:
F_10 ( V_4 ) ;
V_139:
F_113 ( V_4 ) ;
V_138:
F_114 ( & V_4 -> V_134 . V_135 ) ;
V_137:
F_114 ( & V_4 -> V_131 ) ;
V_127:
return error ;
}
void
F_115 (
struct V_3 * V_4 )
{
T_5 V_116 ;
int error ;
F_108 ( & V_4 -> V_176 ) ;
F_108 ( & V_4 -> V_177 ) ;
F_104 ( V_4 ) ;
F_105 ( V_4 ) ;
F_106 ( V_4 ) ;
F_107 ( V_4 -> V_161 ) ;
F_116 ( V_4 , V_178 ) ;
V_4 -> V_10 |= V_175 ;
F_117 ( V_4 -> V_179 ) ;
F_108 ( & V_4 -> V_173 ) ;
F_109 ( V_4 , V_174 ) ;
F_118 ( V_4 ) ;
V_116 = 0 ;
error = F_99 ( V_4 , & V_116 , NULL ) ;
if ( error )
F_5 ( V_4 , L_32
L_33 ) ;
error = F_119 ( V_4 ) ;
if ( error )
F_5 ( V_4 , L_34
L_33 ) ;
F_120 ( V_4 ) ;
F_112 ( V_4 ) ;
F_10 ( V_4 ) ;
#if F_121 ( V_180 )
F_122 ( V_4 , 0 ) ;
#endif
F_14 ( V_4 ) ;
F_113 ( V_4 ) ;
F_114 ( & V_4 -> V_134 . V_135 ) ;
F_114 ( & V_4 -> V_131 ) ;
}
bool
F_58 (
struct V_3 * V_4 ,
int V_181 )
{
ASSERT ( V_181 > V_182 ) ;
if ( ( V_4 -> V_165 -> V_183 . V_184 >= V_181 ) ||
F_123 ( V_4 ) || ( V_4 -> V_10 & V_162 ) )
return false ;
return true ;
}
int
F_119 ( T_2 * V_4 )
{
if ( ! F_58 ( V_4 , V_185 ) )
return 0 ;
if ( ! F_83 ( & V_4 -> V_6 ) )
return 0 ;
return F_59 ( V_4 , true ) ;
}
int
F_124 (
struct V_3 * V_4 ,
T_9 V_186 )
{
F_125 ( & V_4 -> V_187 , V_186 , V_188 ) ;
if ( F_126 ( & V_4 -> V_187 , 0 , V_188 ) < 0 ) {
ASSERT ( 0 ) ;
F_127 ( & V_4 -> V_187 , - V_186 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_128 (
struct V_3 * V_4 ,
T_9 V_186 )
{
F_127 ( & V_4 -> V_189 , V_186 ) ;
if ( F_129 ( & V_4 -> V_189 , 0 ) < 0 ) {
ASSERT ( 0 ) ;
F_127 ( & V_4 -> V_189 , - V_186 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_130 (
struct V_3 * V_4 ,
T_9 V_186 ,
bool V_190 )
{
T_9 V_191 ;
long long V_192 ;
T_10 V_193 ;
if ( V_186 > 0 ) {
if ( F_131 ( V_4 -> V_194 == V_4 -> V_195 ) ) {
F_127 ( & V_4 -> V_196 , V_186 ) ;
return 0 ;
}
F_15 ( & V_4 -> V_114 ) ;
V_192 = ( long long ) ( V_4 -> V_194 - V_4 -> V_195 ) ;
if ( V_192 > V_186 ) {
V_4 -> V_195 += V_186 ;
} else {
V_186 -= V_192 ;
V_4 -> V_195 = V_4 -> V_194 ;
F_127 ( & V_4 -> V_196 , V_186 ) ;
}
F_17 ( & V_4 -> V_114 ) ;
return 0 ;
}
if ( F_126 ( & V_4 -> V_196 , 2 * V_197 ,
V_197 ) < 0 )
V_193 = 1 ;
else
V_193 = V_197 ;
F_125 ( & V_4 -> V_196 , V_186 , V_193 ) ;
if ( F_126 ( & V_4 -> V_196 , V_4 -> V_198 ,
V_197 ) >= 0 ) {
return 0 ;
}
F_15 ( & V_4 -> V_114 ) ;
F_127 ( & V_4 -> V_196 , - V_186 ) ;
if ( ! V_190 )
goto V_199;
V_191 = ( long long ) V_4 -> V_195 + V_186 ;
if ( V_191 >= 0 ) {
V_4 -> V_195 = V_191 ;
F_17 ( & V_4 -> V_114 ) ;
return 0 ;
}
F_132 ( V_200
L_35
L_36 ,
V_4 -> V_133 ) ;
V_199:
F_17 ( & V_4 -> V_114 ) ;
return - V_171 ;
}
int
F_133 (
struct V_3 * V_4 ,
T_9 V_186 )
{
T_9 V_191 ;
int V_201 = 0 ;
F_15 ( & V_4 -> V_114 ) ;
V_191 = V_4 -> V_6 . V_202 + V_186 ;
if ( V_191 < 0 )
V_201 = - V_171 ;
else
V_4 -> V_6 . V_202 = V_191 ;
F_17 ( & V_4 -> V_114 ) ;
return V_201 ;
}
struct V_53 *
F_134 (
struct V_3 * V_4 ,
int V_51 )
{
struct V_53 * V_54 = V_4 -> V_60 ;
if ( ! F_135 ( V_54 ) ) {
if ( V_51 & V_203 )
return NULL ;
F_136 ( V_54 ) ;
}
F_137 ( V_54 ) ;
ASSERT ( V_54 -> V_204 & V_205 ) ;
return V_54 ;
}
void
F_138 (
struct V_3 * V_4 )
{
struct V_53 * V_54 = V_4 -> V_60 ;
F_136 ( V_54 ) ;
V_4 -> V_60 = NULL ;
F_39 ( V_54 ) ;
}
int
F_139 (
struct V_3 * V_4 ,
char * V_206 )
{
if ( F_140 ( V_4 -> V_61 ) ||
F_140 ( V_4 -> V_110 ) ||
( V_4 -> V_207 && F_140 ( V_4 -> V_207 ) ) ) {
F_95 ( V_4 , L_37 , V_206 ) ;
F_95 ( V_4 , L_38 ) ;
return - V_208 ;
}
return 0 ;
}
