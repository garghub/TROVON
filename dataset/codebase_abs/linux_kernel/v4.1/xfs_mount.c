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
V_2 -> V_85 = true ;
}
if ( V_25 -> V_86 != V_2 -> V_82 ) {
V_25 -> V_86 = V_2 -> V_82 ;
V_2 -> V_85 = true ;
}
} else {
F_3 ( V_2 ,
L_9 ) ;
return - V_10 ;
}
} else if ( ( V_2 -> V_8 & V_87 ) != V_87 &&
F_46 ( & V_2 -> V_4 ) ) {
V_2 -> V_80 = V_25 -> V_84 ;
V_2 -> V_82 = V_25 -> V_86 ;
}
return 0 ;
}
STATIC void
F_47 ( T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_5 V_88 ;
if ( V_25 -> V_89 ) {
V_88 = V_25 -> V_90 * V_25 -> V_89 ;
F_48 ( V_88 , 100 ) ;
F_48 ( V_88 , V_2 -> V_91 ) ;
V_2 -> V_92 = ( V_88 * V_2 -> V_91 ) <<
V_25 -> V_93 ;
} else {
V_2 -> V_92 = 0 ;
}
}
STATIC void
F_49 ( T_2 * V_2 )
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
F_50 (
struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_106 ; V_7 ++ ) {
T_5 V_107 = V_2 -> V_4 . V_90 ;
F_48 ( V_107 , 100 ) ;
V_2 -> V_108 [ V_7 ] = V_107 * ( V_7 + 1 ) ;
}
}
STATIC void
F_51 ( T_2 * V_2 )
{
if ( F_52 ( & V_2 -> V_4 ) &&
V_2 -> V_4 . V_109 >=
F_53 ( V_2 , V_2 -> V_110 ) )
V_2 -> V_111 = V_2 -> V_4 . V_109 - 1 ;
else
V_2 -> V_111 = 0 ;
if ( V_2 -> V_80 && V_2 -> V_111 &&
! ( V_2 -> V_80 & V_2 -> V_111 ) )
V_2 -> V_112 = V_2 -> V_80 ;
else
V_2 -> V_112 = 0 ;
}
STATIC int
F_54 (
struct V_1 * V_2 )
{
struct V_59 * V_60 ;
T_9 V_113 ;
int error ;
V_113 = ( T_9 ) F_55 ( V_2 , V_2 -> V_4 . V_90 ) ;
if ( F_56 ( V_2 , V_113 ) != V_2 -> V_4 . V_90 ) {
F_3 ( V_2 , L_10 ) ;
return - V_32 ;
}
error = F_36 ( V_2 -> V_67 ,
V_113 - F_57 ( V_2 , 1 ) ,
F_57 ( V_2 , 1 ) , 0 , & V_60 , NULL ) ;
if ( error ) {
F_3 ( V_2 , L_11 ) ;
return error ;
}
F_40 ( V_60 ) ;
if ( V_2 -> V_114 == V_2 -> V_67 )
return 0 ;
V_113 = ( T_9 ) F_55 ( V_2 , V_2 -> V_4 . V_115 ) ;
if ( F_56 ( V_2 , V_113 ) != V_2 -> V_4 . V_115 ) {
F_3 ( V_2 , L_12 ) ;
return - V_32 ;
}
error = F_36 ( V_2 -> V_114 ,
V_113 - F_55 ( V_2 , 1 ) ,
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
V_2 -> V_116 = 0 ;
if ( V_2 -> V_4 . V_117 == 0 )
return 0 ;
F_14 ( & V_2 -> V_118 ) ;
V_2 -> V_4 . V_117 = 0 ;
F_16 ( & V_2 -> V_118 ) ;
if ( ! F_59 ( V_2 , V_119 ) )
return 0 ;
return F_60 ( V_2 , false ) ;
}
T_5
F_61 ( T_2 * V_2 )
{
T_5 V_120 ;
V_120 = V_2 -> V_4 . V_90 ;
F_48 ( V_120 , 20 ) ;
V_120 = F_62 ( T_5 , V_120 , 8192 ) ;
return V_120 ;
}
int
F_63 (
T_2 * V_2 )
{
T_4 * V_25 = & ( V_2 -> V_4 ) ;
T_10 * V_121 ;
T_5 V_120 ;
T_11 V_122 = 0 ;
T_11 V_123 = 0 ;
int error = 0 ;
F_64 ( V_2 , V_25 ) ;
if ( F_65 ( V_25 ) ) {
F_3 ( V_2 , L_14 ) ;
V_25 -> V_124 |= V_25 -> V_125 ;
V_2 -> V_85 = true ;
if ( F_66 ( & V_2 -> V_4 ) &&
! ( V_2 -> V_8 & V_126 ) )
V_2 -> V_8 |= V_127 ;
}
if ( F_66 ( & V_2 -> V_4 ) &&
( V_2 -> V_8 & V_126 ) ) {
F_67 ( & V_2 -> V_4 ) ;
V_2 -> V_85 = true ;
if ( ! V_25 -> V_124 )
V_2 -> V_85 = true ;
}
if ( ! ( V_2 -> V_4 . V_128 & V_129 ) ) {
V_2 -> V_4 . V_128 |= V_129 ;
V_2 -> V_85 = true ;
}
error = F_43 ( V_2 ) ;
if ( error )
goto V_130;
F_68 ( V_2 ) ;
F_69 ( V_2 , V_131 ) ;
F_69 ( V_2 , V_132 ) ;
F_70 ( V_2 ) ;
F_47 ( V_2 ) ;
error = F_71 ( & V_2 -> V_133 , & V_134 , NULL , V_2 -> V_135 ) ;
if ( error )
goto V_130;
error = F_1 ( V_2 ) ;
if ( error )
goto V_136;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
V_2 -> V_110 = V_137 ;
if ( F_72 ( & V_2 -> V_4 ) ) {
int V_138 = V_2 -> V_110 ;
V_138 *= V_2 -> V_4 . V_139 / V_140 ;
if ( V_2 -> V_4 . V_109 >= F_53 ( V_2 , V_138 ) )
V_2 -> V_110 = V_138 ;
}
F_51 ( V_2 ) ;
error = F_54 ( V_2 ) ;
if ( error )
goto V_141;
error = F_73 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_15 ) ;
goto V_141;
}
F_74 ( & V_25 -> V_5 , V_2 -> V_142 ) ;
V_2 -> V_143 = 0 ;
error = F_75 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_16 , error ) ;
goto V_141;
}
F_76 ( V_2 ) ;
F_23 ( & V_2 -> V_23 ) ;
F_25 ( & V_2 -> V_24 , V_47 ) ;
error = F_19 ( V_2 , V_25 -> V_22 , & V_2 -> V_144 ) ;
if ( error ) {
F_3 ( V_2 , L_17 , error ) ;
goto V_145;
}
if ( ! V_25 -> V_115 ) {
F_3 ( V_2 , L_18 ) ;
F_77 ( L_19 , V_146 , V_2 ) ;
error = - V_71 ;
goto V_147;
}
error = F_78 ( V_2 , V_2 -> V_114 ,
F_79 ( V_2 , V_25 -> V_148 ) ,
F_55 ( V_2 , V_25 -> V_115 ) ) ;
if ( error ) {
F_3 ( V_2 , L_20 ) ;
goto V_149;
}
if ( F_80 ( & V_2 -> V_4 ) &&
! F_81 ( V_2 ) &&
! V_2 -> V_4 . V_150 ) {
error = F_82 ( V_2 , V_25 -> V_22 ) ;
if ( error )
goto V_151;
}
error = F_83 ( V_2 , NULL , V_25 -> V_152 , 0 , V_153 , & V_121 ) ;
if ( error ) {
F_3 ( V_2 , L_21 ) ;
goto V_151;
}
ASSERT ( V_121 != NULL ) ;
if ( F_84 ( ! F_85 ( V_121 -> V_154 . V_155 ) ) ) {
F_3 ( V_2 , L_22 ,
( unsigned long long ) V_121 -> V_156 ) ;
F_86 ( V_121 , V_153 ) ;
F_77 ( L_23 , V_146 ,
V_2 ) ;
error = - V_71 ;
goto V_157;
}
V_2 -> V_158 = V_121 ;
F_86 ( V_121 , V_153 ) ;
error = F_87 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_24 ) ;
goto V_157;
}
if ( V_2 -> V_85 && ! ( V_2 -> V_8 & V_159 ) ) {
error = F_60 ( V_2 , false ) ;
if ( error ) {
F_3 ( V_2 , L_25 ) ;
goto V_160;
}
}
if ( F_88 ( V_2 ) ) {
error = F_89 ( V_2 , & V_122 , & V_123 ) ;
if ( error )
goto V_160;
} else {
ASSERT ( ! F_90 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_117 & V_161 ) {
F_91 ( V_2 , L_26 ) ;
error = F_58 ( V_2 ) ;
if ( error )
goto V_160;
}
}
error = F_92 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_27 ) ;
goto V_160;
}
if ( V_122 ) {
ASSERT ( V_2 -> V_116 == 0 ) ;
V_2 -> V_116 = V_123 ;
F_93 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_159 ) ) {
V_120 = F_61 ( V_2 ) ;
error = F_94 ( V_2 , & V_120 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_28 ) ;
}
return 0 ;
V_160:
F_95 ( V_2 ) ;
V_157:
F_96 ( V_121 ) ;
V_151:
F_97 ( V_2 ) ;
V_149:
if ( V_2 -> V_114 && V_2 -> V_114 != V_2 -> V_67 )
F_98 ( V_2 -> V_114 ) ;
F_98 ( V_2 -> V_67 ) ;
V_147:
F_13 ( V_2 ) ;
V_145:
F_99 ( V_2 ) ;
V_141:
F_8 ( V_2 ) ;
V_136:
F_100 ( & V_2 -> V_133 ) ;
V_130:
return error ;
}
void
F_101 (
struct V_1 * V_2 )
{
T_5 V_120 ;
int error ;
F_102 ( & V_2 -> V_162 ) ;
F_103 ( V_2 ) ;
F_95 ( V_2 ) ;
F_96 ( V_2 -> V_158 ) ;
F_104 ( V_2 , V_163 ) ;
F_105 ( V_2 -> V_164 ) ;
F_102 ( & V_2 -> V_165 ) ;
F_106 ( V_2 , V_166 ) ;
F_107 ( V_2 ) ;
V_120 = 0 ;
error = F_94 ( V_2 , & V_120 , NULL ) ;
if ( error )
F_3 ( V_2 , L_29
L_30 ) ;
error = F_108 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_31
L_30 ) ;
F_97 ( V_2 ) ;
F_99 ( V_2 ) ;
F_8 ( V_2 ) ;
#if F_109 ( V_167 )
F_110 ( V_2 , 0 ) ;
#endif
F_13 ( V_2 ) ;
F_100 ( & V_2 -> V_133 ) ;
}
bool
F_59 (
struct V_1 * V_2 ,
int V_168 )
{
ASSERT ( V_168 > V_169 ) ;
if ( ( V_2 -> V_170 -> V_171 . V_172 >= V_168 ) ||
F_111 ( V_2 ) || ( V_2 -> V_8 & V_159 ) )
return false ;
return true ;
}
int
F_108 ( T_2 * V_2 )
{
if ( ! F_59 ( V_2 , V_173 ) )
return 0 ;
if ( ! F_80 ( & V_2 -> V_4 ) )
return 0 ;
return F_60 ( V_2 , true ) ;
}
int
F_112 (
struct V_1 * V_2 ,
T_12 V_174 )
{
F_113 ( & V_2 -> V_175 , V_174 , V_176 ) ;
if ( F_114 ( & V_2 -> V_175 , 0 , V_176 ) < 0 ) {
ASSERT ( 0 ) ;
F_115 ( & V_2 -> V_175 , - V_174 ) ;
return - V_10 ;
}
return 0 ;
}
int
F_116 (
struct V_1 * V_2 ,
T_12 V_174 )
{
F_115 ( & V_2 -> V_177 , V_174 ) ;
if ( F_117 ( & V_2 -> V_177 , 0 ) < 0 ) {
ASSERT ( 0 ) ;
F_115 ( & V_2 -> V_177 , - V_174 ) ;
return - V_10 ;
}
return 0 ;
}
int
F_118 (
struct V_1 * V_2 ,
T_12 V_174 ,
bool V_178 )
{
T_12 V_179 ;
long long V_180 ;
T_13 V_181 ;
if ( V_174 > 0 ) {
if ( F_119 ( V_2 -> V_182 == V_2 -> V_183 ) ) {
F_115 ( & V_2 -> V_184 , V_174 ) ;
return 0 ;
}
F_14 ( & V_2 -> V_118 ) ;
V_180 = ( long long ) ( V_2 -> V_182 - V_2 -> V_183 ) ;
if ( V_180 > V_174 ) {
V_2 -> V_183 += V_174 ;
} else {
V_174 -= V_180 ;
V_2 -> V_183 = V_2 -> V_182 ;
F_115 ( & V_2 -> V_184 , V_174 ) ;
}
F_16 ( & V_2 -> V_118 ) ;
return 0 ;
}
if ( F_114 ( & V_2 -> V_184 , 2 * V_185 ,
V_185 ) < 0 )
V_181 = 1 ;
else
V_181 = V_185 ;
F_113 ( & V_2 -> V_184 , V_174 , V_181 ) ;
if ( F_114 ( & V_2 -> V_184 , F_120 ( V_2 ) ,
V_185 ) >= 0 ) {
return 0 ;
}
F_14 ( & V_2 -> V_118 ) ;
F_115 ( & V_2 -> V_184 , - V_174 ) ;
if ( ! V_178 )
goto V_186;
V_179 = ( long long ) V_2 -> V_183 + V_174 ;
if ( V_179 >= 0 ) {
V_2 -> V_183 = V_179 ;
F_16 ( & V_2 -> V_118 ) ;
return 0 ;
}
F_121 ( V_187
L_32
L_33 ,
V_2 -> V_135 ) ;
V_186:
F_16 ( & V_2 -> V_118 ) ;
return - V_188 ;
}
int
F_122 (
struct V_1 * V_2 ,
T_12 V_174 )
{
T_12 V_179 ;
int V_189 = 0 ;
F_14 ( & V_2 -> V_118 ) ;
V_179 = V_2 -> V_4 . V_190 + V_174 ;
if ( V_179 < 0 )
V_189 = - V_188 ;
else
V_2 -> V_4 . V_190 = V_179 ;
F_16 ( & V_2 -> V_118 ) ;
return V_189 ;
}
struct V_59 *
F_123 (
struct V_1 * V_2 ,
int V_57 )
{
struct V_59 * V_60 = V_2 -> V_66 ;
if ( ! F_124 ( V_60 ) ) {
if ( V_57 & V_191 )
return NULL ;
F_125 ( V_60 ) ;
}
F_126 ( V_60 ) ;
ASSERT ( F_127 ( V_60 ) ) ;
return V_60 ;
}
void
F_128 (
struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_66 ;
F_125 ( V_60 ) ;
V_2 -> V_66 = NULL ;
F_40 ( V_60 ) ;
}
int
F_129 (
struct V_1 * V_2 ,
char * V_192 )
{
if ( F_130 ( V_2 -> V_67 ) ||
F_130 ( V_2 -> V_114 ) ||
( V_2 -> V_193 && F_130 ( V_2 -> V_193 ) ) ) {
F_91 ( V_2 , L_34 , V_192 ) ;
F_91 ( V_2 , L_35 ) ;
return - V_194 ;
}
return 0 ;
}
