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
V_1 * sizeof( * V_2 ) ,
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
if ( V_26 >> ( V_30 - V_25 -> V_28 ) > V_31 )
return - V_32 ;
return 0 ;
}
int
F_20 (
T_2 * V_4 ,
T_3 V_33 ,
T_3 * V_34 )
{
T_3 V_35 ;
T_3 V_36 = 0 ;
T_6 * V_19 ;
T_7 V_37 ;
T_8 V_38 ;
T_4 * V_25 = & V_4 -> V_6 ;
int error = - V_39 ;
for ( V_35 = 0 ; V_35 < V_33 ; V_35 ++ ) {
V_19 = F_21 ( V_4 , V_35 ) ;
if ( V_19 ) {
F_22 ( V_19 ) ;
continue;
}
if ( ! V_36 )
V_36 = V_35 ;
V_19 = F_23 ( sizeof( * V_19 ) , V_40 ) ;
if ( ! V_19 )
goto V_41;
V_19 -> V_42 = V_35 ;
V_19 -> V_43 = V_4 ;
F_24 ( & V_19 -> V_44 ) ;
F_25 ( & V_19 -> V_45 ) ;
F_26 ( & V_19 -> V_46 , V_47 ) ;
F_24 ( & V_19 -> V_48 ) ;
V_19 -> V_49 = V_50 ;
if ( F_27 ( V_51 ) )
goto V_41;
F_15 ( & V_4 -> V_23 ) ;
if ( F_28 ( & V_4 -> V_24 , V_35 , V_19 ) ) {
F_29 () ;
F_17 ( & V_4 -> V_23 ) ;
F_30 () ;
error = - V_52 ;
goto V_41;
}
F_17 ( & V_4 -> V_23 ) ;
F_30 () ;
}
V_37 = F_31 ( V_4 , V_25 -> V_53 - 1 , 0 ) ;
V_38 = F_32 ( V_4 , V_33 - 1 , V_37 ) ;
if ( ( V_4 -> V_10 & V_54 ) && V_38 > V_55 )
V_4 -> V_10 |= V_56 ;
else
V_4 -> V_10 &= ~ V_56 ;
if ( V_4 -> V_10 & V_56 )
V_35 = F_33 ( V_4 , V_33 ) ;
else
V_35 = F_34 ( V_4 , V_33 ) ;
if ( V_34 )
* V_34 = V_35 ;
return 0 ;
V_41:
F_2 ( V_19 ) ;
for (; V_35 > V_36 ; V_35 -- ) {
V_19 = F_16 ( & V_4 -> V_24 , V_35 ) ;
F_2 ( V_19 ) ;
}
return error ;
}
int
F_35 (
struct V_3 * V_4 ,
int V_57 )
{
unsigned int V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_25 = & V_4 -> V_6 ;
int error ;
int V_62 = ! ( V_57 & V_63 ) ;
const struct V_64 * V_65 ;
ASSERT ( V_4 -> V_66 == NULL ) ;
ASSERT ( V_4 -> V_67 != NULL ) ;
V_58 = F_36 ( V_4 -> V_67 ) ;
V_65 = NULL ;
V_68:
error = F_37 ( V_4 -> V_67 , V_69 ,
F_38 ( V_58 ) , 0 , & V_60 , V_65 ) ;
if ( error ) {
if ( V_62 )
F_5 ( V_4 , L_3 , error ) ;
if ( error == - V_70 )
error = - V_71 ;
return error ;
}
F_39 ( V_25 , F_40 ( V_60 ) ) ;
if ( V_25 -> V_72 != V_73 ) {
if ( V_62 )
F_5 ( V_4 , L_4 ) ;
error = - V_12 ;
goto V_74;
}
if ( V_58 > V_25 -> V_75 ) {
if ( V_62 )
F_5 ( V_4 , L_5 ,
V_58 , V_25 -> V_75 ) ;
error = - V_76 ;
goto V_74;
}
if ( V_65 == NULL ) {
F_41 ( V_60 ) ;
V_58 = V_25 -> V_75 ;
V_65 = V_62 ? & V_77 : & V_78 ;
goto V_68;
}
F_42 ( V_4 ) ;
V_60 -> V_79 = & V_77 ;
V_4 -> V_66 = V_60 ;
F_43 ( V_60 ) ;
return 0 ;
V_74:
F_41 ( V_60 ) ;
return error ;
}
STATIC int
F_44 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
if ( V_4 -> V_80 ) {
if ( ( F_45 ( V_4 -> V_80 ) & V_4 -> V_81 ) ||
( F_45 ( V_4 -> V_82 ) & V_4 -> V_81 ) ) {
F_5 ( V_4 ,
L_6 ,
V_25 -> V_83 ) ;
return - V_12 ;
} else {
V_4 -> V_80 = F_46 ( V_4 , V_4 -> V_80 ) ;
if ( V_4 -> V_80 && ( V_25 -> V_53 % V_4 -> V_80 ) ) {
F_5 ( V_4 ,
L_7 ,
V_25 -> V_53 ) ;
return - V_12 ;
} else if ( V_4 -> V_80 ) {
V_4 -> V_82 = F_46 ( V_4 , V_4 -> V_82 ) ;
} else {
F_5 ( V_4 ,
L_8 ,
V_4 -> V_80 , V_25 -> V_83 ) ;
return - V_12 ;
}
}
if ( F_47 ( V_25 ) ) {
if ( V_25 -> V_84 != V_4 -> V_80 ) {
V_25 -> V_84 = V_4 -> V_80 ;
V_4 -> V_85 = true ;
}
if ( V_25 -> V_86 != V_4 -> V_82 ) {
V_25 -> V_86 = V_4 -> V_82 ;
V_4 -> V_85 = true ;
}
} else {
F_5 ( V_4 ,
L_9 ) ;
return - V_12 ;
}
} else if ( ( V_4 -> V_10 & V_87 ) != V_87 &&
F_47 ( & V_4 -> V_6 ) ) {
V_4 -> V_80 = V_25 -> V_84 ;
V_4 -> V_82 = V_25 -> V_86 ;
}
return 0 ;
}
STATIC void
F_48 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
T_5 V_88 ;
if ( V_25 -> V_89 ) {
V_88 = V_25 -> V_90 * V_25 -> V_89 ;
F_49 ( V_88 , 100 ) ;
F_49 ( V_88 , V_4 -> V_91 ) ;
V_4 -> V_92 = ( V_88 * V_4 -> V_91 ) <<
V_25 -> V_93 ;
} else {
V_4 -> V_92 = 0 ;
}
}
STATIC void
F_50 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
int V_94 , V_95 ;
if ( ! ( V_4 -> V_10 & V_96 ) ) {
if ( V_4 -> V_10 & V_97 ) {
V_94 = V_98 ;
V_95 = V_99 ;
} else {
V_94 = V_100 ;
V_95 = V_101 ;
}
} else {
V_94 = V_4 -> V_102 ;
V_95 = V_4 -> V_103 ;
}
if ( V_25 -> V_28 > V_94 ) {
V_4 -> V_102 = V_25 -> V_28 ;
} else {
V_4 -> V_102 = V_94 ;
}
V_4 -> V_104 = 1 << ( V_4 -> V_102 - V_25 -> V_28 ) ;
if ( V_25 -> V_28 > V_95 ) {
V_4 -> V_103 = V_25 -> V_28 ;
} else {
V_4 -> V_103 = V_95 ;
}
V_4 -> V_105 = 1 << ( V_4 -> V_103 - V_25 -> V_28 ) ;
}
void
F_51 (
struct V_3 * V_4 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_106 ; V_9 ++ ) {
T_5 V_107 = V_4 -> V_6 . V_90 ;
F_49 ( V_107 , 100 ) ;
V_4 -> V_108 [ V_9 ] = V_107 * ( V_9 + 1 ) ;
}
}
STATIC void
F_52 ( T_2 * V_4 )
{
if ( F_53 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_109 >=
F_54 ( V_4 , V_4 -> V_110 ) )
V_4 -> V_111 = V_4 -> V_6 . V_109 - 1 ;
else
V_4 -> V_111 = 0 ;
if ( V_4 -> V_80 && V_4 -> V_111 &&
! ( V_4 -> V_80 & V_4 -> V_111 ) )
V_4 -> V_112 = V_4 -> V_80 ;
else
V_4 -> V_112 = 0 ;
}
STATIC int
F_55 (
struct V_3 * V_4 )
{
struct V_59 * V_60 ;
T_9 V_113 ;
int error ;
V_113 = ( T_9 ) F_56 ( V_4 , V_4 -> V_6 . V_90 ) ;
if ( F_57 ( V_4 , V_113 ) != V_4 -> V_6 . V_90 ) {
F_5 ( V_4 , L_10 ) ;
return - V_32 ;
}
error = F_37 ( V_4 -> V_67 ,
V_113 - F_58 ( V_4 , 1 ) ,
F_58 ( V_4 , 1 ) , 0 , & V_60 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_11 ) ;
return error ;
}
F_41 ( V_60 ) ;
if ( V_4 -> V_114 == V_4 -> V_67 )
return 0 ;
V_113 = ( T_9 ) F_56 ( V_4 , V_4 -> V_6 . V_115 ) ;
if ( F_57 ( V_4 , V_113 ) != V_4 -> V_6 . V_115 ) {
F_5 ( V_4 , L_12 ) ;
return - V_32 ;
}
error = F_37 ( V_4 -> V_114 ,
V_113 - F_56 ( V_4 , 1 ) ,
F_56 ( V_4 , 1 ) , 0 , & V_60 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_13 ) ;
return error ;
}
F_41 ( V_60 ) ;
return 0 ;
}
int
F_59 (
struct V_3 * V_4 )
{
V_4 -> V_116 = 0 ;
if ( V_4 -> V_6 . V_117 == 0 )
return 0 ;
F_15 ( & V_4 -> V_118 ) ;
V_4 -> V_6 . V_117 = 0 ;
F_17 ( & V_4 -> V_118 ) ;
if ( ! F_60 ( V_4 , V_119 ) )
return 0 ;
return F_61 ( V_4 , false ) ;
}
T_5
F_62 ( T_2 * V_4 )
{
T_5 V_120 ;
V_120 = V_4 -> V_6 . V_90 ;
F_49 ( V_120 , 20 ) ;
V_120 = F_63 ( T_5 , V_120 , 8192 ) ;
return V_120 ;
}
int
F_64 (
struct V_3 * V_4 )
{
struct V_61 * V_25 = & ( V_4 -> V_6 ) ;
struct V_121 * V_122 ;
T_5 V_120 ;
T_10 V_123 = 0 ;
T_10 V_124 = 0 ;
int error = 0 ;
F_65 ( V_4 , V_25 ) ;
if ( F_66 ( V_25 ) ) {
F_5 ( V_4 , L_14 ) ;
V_25 -> V_125 |= V_25 -> V_126 ;
V_4 -> V_85 = true ;
if ( F_67 ( & V_4 -> V_6 ) &&
! ( V_4 -> V_10 & V_127 ) )
V_4 -> V_10 |= V_128 ;
}
if ( F_67 ( & V_4 -> V_6 ) &&
( V_4 -> V_10 & V_127 ) ) {
F_68 ( & V_4 -> V_6 ) ;
V_4 -> V_85 = true ;
if ( ! V_25 -> V_125 )
V_4 -> V_85 = true ;
}
if ( ! ( V_4 -> V_6 . V_129 & V_130 ) ) {
V_4 -> V_6 . V_129 |= V_130 ;
V_4 -> V_85 = true ;
}
error = F_44 ( V_4 ) ;
if ( error )
goto V_131;
F_69 ( V_4 ) ;
F_70 ( V_4 , V_132 ) ;
F_70 ( V_4 , V_133 ) ;
F_71 ( V_4 ) ;
F_48 ( V_4 ) ;
error = F_72 ( & V_4 -> V_134 , & V_135 , NULL , V_4 -> V_136 ) ;
if ( error )
goto V_131;
error = F_72 ( & V_4 -> V_137 . V_138 , & V_139 ,
& V_4 -> V_134 , L_15 ) ;
if ( error )
goto V_140;
error = F_3 ( V_4 ) ;
if ( error )
goto V_141;
F_50 ( V_4 ) ;
F_51 ( V_4 ) ;
V_4 -> V_110 = V_142 ;
if ( F_73 ( & V_4 -> V_6 ) ) {
int V_143 = V_4 -> V_110 ;
V_143 *= V_4 -> V_6 . V_144 / V_145 ;
if ( V_4 -> V_6 . V_109 >= F_54 ( V_4 , V_143 ) )
V_4 -> V_110 = V_143 ;
}
if ( F_74 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_146 !=
F_54 ( V_4 , V_4 -> V_110 ) ) {
F_5 ( V_4 ,
L_16 ,
V_4 -> V_6 . V_146 ,
F_54 ( V_4 , V_4 -> V_110 ) ) ;
error = - V_12 ;
goto V_147;
}
F_52 ( V_4 ) ;
error = F_55 ( V_4 ) ;
if ( error )
goto V_147;
error = F_75 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_17 ) ;
goto V_147;
}
F_76 ( & V_25 -> V_7 , V_4 -> V_148 ) ;
V_4 -> V_149 = 0 ;
error = F_77 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_18 , error ) ;
goto V_147;
}
F_78 ( V_4 ) ;
F_24 ( & V_4 -> V_23 ) ;
F_26 ( & V_4 -> V_24 , V_47 ) ;
error = F_20 ( V_4 , V_25 -> V_22 , & V_4 -> V_150 ) ;
if ( error ) {
F_5 ( V_4 , L_19 , error ) ;
goto V_151;
}
if ( ! V_25 -> V_115 ) {
F_5 ( V_4 , L_20 ) ;
F_79 ( L_21 , V_152 , V_4 ) ;
error = - V_71 ;
goto V_153;
}
error = F_80 ( V_4 , V_4 -> V_114 ,
F_81 ( V_4 , V_25 -> V_154 ) ,
F_56 ( V_4 , V_25 -> V_115 ) ) ;
if ( error ) {
F_5 ( V_4 , L_22 ) ;
goto V_155;
}
if ( F_82 ( & V_4 -> V_6 ) &&
! F_83 ( V_4 ) &&
! V_4 -> V_6 . V_156 ) {
error = F_84 ( V_4 , V_25 -> V_22 ) ;
if ( error )
goto V_157;
}
error = F_85 ( V_4 , NULL , V_25 -> V_158 , 0 , V_159 , & V_122 ) ;
if ( error ) {
F_5 ( V_4 , L_23 ) ;
goto V_157;
}
ASSERT ( V_122 != NULL ) ;
if ( F_86 ( ! F_87 ( V_122 -> V_160 . V_161 ) ) ) {
F_5 ( V_4 , L_24 ,
( unsigned long long ) V_122 -> V_162 ) ;
F_88 ( V_122 , V_159 ) ;
F_79 ( L_25 , V_152 ,
V_4 ) ;
error = - V_71 ;
goto V_163;
}
V_4 -> V_164 = V_122 ;
F_88 ( V_122 , V_159 ) ;
error = F_89 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_26 ) ;
goto V_163;
}
if ( V_4 -> V_85 && ! ( V_4 -> V_10 & V_165 ) ) {
error = F_61 ( V_4 , false ) ;
if ( error ) {
F_5 ( V_4 , L_27 ) ;
goto V_166;
}
}
if ( F_90 ( V_4 ) ) {
error = F_91 ( V_4 , & V_123 , & V_124 ) ;
if ( error )
goto V_166;
} else {
ASSERT ( ! F_92 ( V_4 ) ) ;
if ( V_4 -> V_6 . V_117 & V_167 ) {
F_93 ( V_4 , L_28 ) ;
error = F_59 ( V_4 ) ;
if ( error )
goto V_166;
}
}
error = F_94 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_29 ) ;
goto V_166;
}
if ( V_123 ) {
ASSERT ( V_4 -> V_116 == 0 ) ;
V_4 -> V_116 = V_124 ;
F_95 ( V_4 ) ;
}
if ( ! ( V_4 -> V_10 & V_165 ) ) {
V_120 = F_62 ( V_4 ) ;
error = F_96 ( V_4 , & V_120 , NULL ) ;
if ( error )
F_5 ( V_4 ,
L_30 ) ;
}
return 0 ;
V_166:
F_97 ( V_4 ) ;
V_163:
F_98 ( V_122 ) ;
F_99 ( & V_4 -> V_168 ) ;
F_100 ( V_4 , V_169 ) ;
V_157:
F_101 ( V_4 ) ;
V_155:
if ( V_4 -> V_114 && V_4 -> V_114 != V_4 -> V_67 )
F_102 ( V_4 -> V_114 ) ;
F_102 ( V_4 -> V_67 ) ;
V_153:
F_14 ( V_4 ) ;
V_151:
F_103 ( V_4 ) ;
V_147:
F_10 ( V_4 ) ;
V_141:
F_104 ( & V_4 -> V_137 . V_138 ) ;
V_140:
F_104 ( & V_4 -> V_134 ) ;
V_131:
return error ;
}
void
F_105 (
struct V_3 * V_4 )
{
T_5 V_120 ;
int error ;
F_99 ( & V_4 -> V_170 ) ;
F_106 ( V_4 ) ;
F_97 ( V_4 ) ;
F_98 ( V_4 -> V_164 ) ;
F_107 ( V_4 , V_171 ) ;
F_108 ( V_4 -> V_172 ) ;
F_99 ( & V_4 -> V_168 ) ;
F_100 ( V_4 , V_169 ) ;
F_109 ( V_4 ) ;
V_120 = 0 ;
error = F_96 ( V_4 , & V_120 , NULL ) ;
if ( error )
F_5 ( V_4 , L_31
L_32 ) ;
error = F_110 ( V_4 ) ;
if ( error )
F_5 ( V_4 , L_33
L_32 ) ;
F_111 ( V_4 ) ;
F_103 ( V_4 ) ;
F_10 ( V_4 ) ;
#if F_112 ( V_173 )
F_113 ( V_4 , 0 ) ;
#endif
F_14 ( V_4 ) ;
F_104 ( & V_4 -> V_137 . V_138 ) ;
F_104 ( & V_4 -> V_134 ) ;
}
bool
F_60 (
struct V_3 * V_4 ,
int V_174 )
{
ASSERT ( V_174 > V_175 ) ;
if ( ( V_4 -> V_176 -> V_177 . V_178 >= V_174 ) ||
F_114 ( V_4 ) || ( V_4 -> V_10 & V_165 ) )
return false ;
return true ;
}
int
F_110 ( T_2 * V_4 )
{
if ( ! F_60 ( V_4 , V_179 ) )
return 0 ;
if ( ! F_82 ( & V_4 -> V_6 ) )
return 0 ;
return F_61 ( V_4 , true ) ;
}
int
F_115 (
struct V_3 * V_4 ,
T_11 V_180 )
{
F_116 ( & V_4 -> V_181 , V_180 , V_182 ) ;
if ( F_117 ( & V_4 -> V_181 , 0 , V_182 ) < 0 ) {
ASSERT ( 0 ) ;
F_118 ( & V_4 -> V_181 , - V_180 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_119 (
struct V_3 * V_4 ,
T_11 V_180 )
{
F_118 ( & V_4 -> V_183 , V_180 ) ;
if ( F_120 ( & V_4 -> V_183 , 0 ) < 0 ) {
ASSERT ( 0 ) ;
F_118 ( & V_4 -> V_183 , - V_180 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_121 (
struct V_3 * V_4 ,
T_11 V_180 ,
bool V_184 )
{
T_11 V_185 ;
long long V_186 ;
T_12 V_187 ;
if ( V_180 > 0 ) {
if ( F_122 ( V_4 -> V_188 == V_4 -> V_189 ) ) {
F_118 ( & V_4 -> V_190 , V_180 ) ;
return 0 ;
}
F_15 ( & V_4 -> V_118 ) ;
V_186 = ( long long ) ( V_4 -> V_188 - V_4 -> V_189 ) ;
if ( V_186 > V_180 ) {
V_4 -> V_189 += V_180 ;
} else {
V_180 -= V_186 ;
V_4 -> V_189 = V_4 -> V_188 ;
F_118 ( & V_4 -> V_190 , V_180 ) ;
}
F_17 ( & V_4 -> V_118 ) ;
return 0 ;
}
if ( F_117 ( & V_4 -> V_190 , 2 * V_191 ,
V_191 ) < 0 )
V_187 = 1 ;
else
V_187 = V_191 ;
F_116 ( & V_4 -> V_190 , V_180 , V_187 ) ;
if ( F_117 ( & V_4 -> V_190 , F_123 ( V_4 ) ,
V_191 ) >= 0 ) {
return 0 ;
}
F_15 ( & V_4 -> V_118 ) ;
F_118 ( & V_4 -> V_190 , - V_180 ) ;
if ( ! V_184 )
goto V_192;
V_185 = ( long long ) V_4 -> V_189 + V_180 ;
if ( V_185 >= 0 ) {
V_4 -> V_189 = V_185 ;
F_17 ( & V_4 -> V_118 ) ;
return 0 ;
}
F_124 ( V_193
L_34
L_35 ,
V_4 -> V_136 ) ;
V_192:
F_17 ( & V_4 -> V_118 ) ;
return - V_194 ;
}
int
F_125 (
struct V_3 * V_4 ,
T_11 V_180 )
{
T_11 V_185 ;
int V_195 = 0 ;
F_15 ( & V_4 -> V_118 ) ;
V_185 = V_4 -> V_6 . V_196 + V_180 ;
if ( V_185 < 0 )
V_195 = - V_194 ;
else
V_4 -> V_6 . V_196 = V_185 ;
F_17 ( & V_4 -> V_118 ) ;
return V_195 ;
}
struct V_59 *
F_126 (
struct V_3 * V_4 ,
int V_57 )
{
struct V_59 * V_60 = V_4 -> V_66 ;
if ( ! F_127 ( V_60 ) ) {
if ( V_57 & V_197 )
return NULL ;
F_128 ( V_60 ) ;
}
F_129 ( V_60 ) ;
ASSERT ( F_130 ( V_60 ) ) ;
return V_60 ;
}
void
F_131 (
struct V_3 * V_4 )
{
struct V_59 * V_60 = V_4 -> V_66 ;
F_128 ( V_60 ) ;
V_4 -> V_66 = NULL ;
F_41 ( V_60 ) ;
}
int
F_132 (
struct V_3 * V_4 ,
char * V_198 )
{
if ( F_133 ( V_4 -> V_67 ) ||
F_133 ( V_4 -> V_114 ) ||
( V_4 -> V_199 && F_133 ( V_4 -> V_199 ) ) ) {
F_93 ( V_4 , L_36 , V_198 ) ;
F_93 ( V_4 , L_37 ) ;
return - V_200 ;
}
return 0 ;
}
