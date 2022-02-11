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
T_3 V_35 = V_36 ;
T_6 * V_19 ;
int error = - V_37 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
V_19 = F_22 ( V_4 , V_34 ) ;
if ( V_19 ) {
F_23 ( V_19 ) ;
continue;
}
V_19 = F_24 ( sizeof( * V_19 ) , V_38 ) ;
if ( ! V_19 )
goto V_39;
V_19 -> V_40 = V_34 ;
V_19 -> V_41 = V_4 ;
F_25 ( & V_19 -> V_42 ) ;
F_26 ( & V_19 -> V_43 ) ;
F_27 ( & V_19 -> V_44 , V_45 ) ;
if ( F_28 ( V_19 ) )
goto V_46;
F_29 ( & V_19 -> V_47 ) ;
if ( F_30 ( V_48 ) )
goto V_49;
F_15 ( & V_4 -> V_23 ) ;
if ( F_31 ( & V_4 -> V_24 , V_34 , V_19 ) ) {
F_32 () ;
F_17 ( & V_4 -> V_23 ) ;
F_33 () ;
error = - V_50 ;
goto V_49;
}
F_17 ( & V_4 -> V_23 ) ;
F_33 () ;
if ( V_35 == V_36 )
V_35 = V_34 ;
}
V_34 = F_34 ( V_4 , V_32 ) ;
if ( V_33 )
* V_33 = V_34 ;
V_4 -> V_51 = F_35 ( V_4 ) ;
return 0 ;
V_49:
F_18 ( V_19 ) ;
V_46:
F_2 ( V_19 ) ;
V_39:
for ( V_34 = V_35 ; V_34 < V_32 ; V_34 ++ ) {
V_19 = F_16 ( & V_4 -> V_24 , V_34 ) ;
if ( ! V_19 )
break;
F_18 ( V_19 ) ;
F_2 ( V_19 ) ;
}
return error ;
}
int
F_36 (
struct V_3 * V_4 ,
int V_52 )
{
unsigned int V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_25 = & V_4 -> V_6 ;
int error ;
int V_57 = ! ( V_52 & V_58 ) ;
const struct V_59 * V_60 ;
ASSERT ( V_4 -> V_61 == NULL ) ;
ASSERT ( V_4 -> V_62 != NULL ) ;
V_53 = F_37 ( V_4 -> V_62 ) ;
V_60 = NULL ;
V_63:
error = F_38 ( V_4 -> V_62 , V_64 ,
F_39 ( V_53 ) , V_65 , & V_55 ,
V_60 ) ;
if ( error ) {
if ( V_57 )
F_5 ( V_4 , L_3 , error ) ;
if ( error == - V_66 )
error = - V_67 ;
return error ;
}
F_40 ( V_25 , F_41 ( V_55 ) ) ;
if ( V_25 -> V_68 != V_69 ) {
if ( V_57 )
F_5 ( V_4 , L_4 ) ;
error = - V_12 ;
goto V_70;
}
if ( V_53 > V_25 -> V_71 ) {
if ( V_57 )
F_5 ( V_4 , L_5 ,
V_53 , V_25 -> V_71 ) ;
error = - V_72 ;
goto V_70;
}
if ( V_60 == NULL ) {
F_42 ( V_55 ) ;
V_53 = V_25 -> V_71 ;
V_60 = V_57 ? & V_73 : & V_74 ;
goto V_63;
}
F_43 ( V_4 ) ;
V_55 -> V_75 = & V_73 ;
V_4 -> V_61 = V_55 ;
F_44 ( V_55 ) ;
return 0 ;
V_70:
F_42 ( V_55 ) ;
return error ;
}
STATIC int
F_45 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
if ( V_4 -> V_76 ) {
if ( ( F_46 ( V_4 -> V_76 ) & V_4 -> V_77 ) ||
( F_46 ( V_4 -> V_78 ) & V_4 -> V_77 ) ) {
F_5 ( V_4 ,
L_6 ,
V_25 -> V_79 ) ;
return - V_12 ;
} else {
V_4 -> V_76 = F_47 ( V_4 , V_4 -> V_76 ) ;
if ( V_4 -> V_76 && ( V_25 -> V_80 % V_4 -> V_76 ) ) {
F_5 ( V_4 ,
L_7 ,
V_25 -> V_80 ) ;
return - V_12 ;
} else if ( V_4 -> V_76 ) {
V_4 -> V_78 = F_47 ( V_4 , V_4 -> V_78 ) ;
} else {
F_5 ( V_4 ,
L_8 ,
V_4 -> V_76 , V_25 -> V_79 ) ;
return - V_12 ;
}
}
if ( F_48 ( V_25 ) ) {
if ( V_25 -> V_81 != V_4 -> V_76 ) {
V_25 -> V_81 = V_4 -> V_76 ;
V_4 -> V_82 = true ;
}
if ( V_25 -> V_83 != V_4 -> V_78 ) {
V_25 -> V_83 = V_4 -> V_78 ;
V_4 -> V_82 = true ;
}
} else {
F_5 ( V_4 ,
L_9 ) ;
return - V_12 ;
}
} else if ( ( V_4 -> V_10 & V_84 ) != V_84 &&
F_48 ( & V_4 -> V_6 ) ) {
V_4 -> V_76 = V_25 -> V_81 ;
V_4 -> V_78 = V_25 -> V_83 ;
}
return 0 ;
}
STATIC void
F_49 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
T_5 V_85 ;
if ( V_25 -> V_86 ) {
V_85 = V_25 -> V_87 * V_25 -> V_86 ;
F_50 ( V_85 , 100 ) ;
F_50 ( V_85 , V_4 -> V_88 ) ;
V_4 -> V_89 = ( V_85 * V_4 -> V_88 ) <<
V_25 -> V_90 ;
} else {
V_4 -> V_89 = 0 ;
}
}
STATIC void
F_51 ( T_2 * V_4 )
{
T_4 * V_25 = & ( V_4 -> V_6 ) ;
int V_91 , V_92 ;
if ( ! ( V_4 -> V_10 & V_93 ) ) {
if ( V_4 -> V_10 & V_94 ) {
V_91 = V_95 ;
V_92 = V_96 ;
} else {
V_91 = V_97 ;
V_92 = V_98 ;
}
} else {
V_91 = V_4 -> V_99 ;
V_92 = V_4 -> V_100 ;
}
if ( V_25 -> V_28 > V_91 ) {
V_4 -> V_99 = V_25 -> V_28 ;
} else {
V_4 -> V_99 = V_91 ;
}
V_4 -> V_101 = 1 << ( V_4 -> V_99 - V_25 -> V_28 ) ;
if ( V_25 -> V_28 > V_92 ) {
V_4 -> V_100 = V_25 -> V_28 ;
} else {
V_4 -> V_100 = V_92 ;
}
V_4 -> V_102 = 1 << ( V_4 -> V_100 - V_25 -> V_28 ) ;
}
void
F_52 (
struct V_3 * V_4 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_103 ; V_9 ++ ) {
T_5 V_104 = V_4 -> V_6 . V_87 ;
F_50 ( V_104 , 100 ) ;
V_4 -> V_105 [ V_9 ] = V_104 * ( V_9 + 1 ) ;
}
}
STATIC void
F_53 ( T_2 * V_4 )
{
if ( F_54 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_106 >= F_55 ( V_4 ) )
V_4 -> V_107 = V_4 -> V_6 . V_106 - 1 ;
else
V_4 -> V_107 = 0 ;
if ( V_4 -> V_76 && V_4 -> V_107 &&
! ( V_4 -> V_76 & V_4 -> V_107 ) )
V_4 -> V_108 = V_4 -> V_76 ;
else
V_4 -> V_108 = 0 ;
}
STATIC int
F_56 (
struct V_3 * V_4 )
{
struct V_54 * V_55 ;
T_7 V_109 ;
int error ;
V_109 = ( T_7 ) F_57 ( V_4 , V_4 -> V_6 . V_87 ) ;
if ( F_58 ( V_4 , V_109 ) != V_4 -> V_6 . V_87 ) {
F_5 ( V_4 , L_10 ) ;
return - V_31 ;
}
error = F_38 ( V_4 -> V_62 ,
V_109 - F_59 ( V_4 , 1 ) ,
F_59 ( V_4 , 1 ) , 0 , & V_55 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_11 ) ;
return error ;
}
F_42 ( V_55 ) ;
if ( V_4 -> V_110 == V_4 -> V_62 )
return 0 ;
V_109 = ( T_7 ) F_57 ( V_4 , V_4 -> V_6 . V_111 ) ;
if ( F_58 ( V_4 , V_109 ) != V_4 -> V_6 . V_111 ) {
F_5 ( V_4 , L_12 ) ;
return - V_31 ;
}
error = F_38 ( V_4 -> V_110 ,
V_109 - F_57 ( V_4 , 1 ) ,
F_57 ( V_4 , 1 ) , 0 , & V_55 , NULL ) ;
if ( error ) {
F_5 ( V_4 , L_13 ) ;
return error ;
}
F_42 ( V_55 ) ;
return 0 ;
}
int
F_60 (
struct V_3 * V_4 )
{
V_4 -> V_112 = 0 ;
if ( V_4 -> V_6 . V_113 == 0 )
return 0 ;
F_15 ( & V_4 -> V_114 ) ;
V_4 -> V_6 . V_113 = 0 ;
F_17 ( & V_4 -> V_114 ) ;
if ( ! F_61 ( V_4 , V_115 ) )
return 0 ;
return F_62 ( V_4 , false ) ;
}
T_5
F_63 ( T_2 * V_4 )
{
T_5 V_116 ;
V_116 = V_4 -> V_6 . V_87 ;
F_50 ( V_116 , 20 ) ;
V_116 = F_64 ( T_5 , V_116 , 8192 ) ;
return V_116 ;
}
int
F_65 (
struct V_3 * V_4 )
{
struct V_56 * V_25 = & ( V_4 -> V_6 ) ;
struct V_117 * V_118 ;
T_5 V_116 ;
T_8 V_119 = 0 ;
T_8 V_120 = 0 ;
int error = 0 ;
F_66 ( V_4 , V_25 ) ;
if ( F_67 ( V_25 ) ) {
F_5 ( V_4 , L_14 ) ;
V_25 -> V_121 |= V_25 -> V_122 ;
V_4 -> V_82 = true ;
if ( F_68 ( & V_4 -> V_6 ) &&
! ( V_4 -> V_10 & V_123 ) )
V_4 -> V_10 |= V_124 ;
}
if ( F_68 ( & V_4 -> V_6 ) &&
( V_4 -> V_10 & V_123 ) ) {
F_69 ( & V_4 -> V_6 ) ;
V_4 -> V_82 = true ;
if ( ! V_25 -> V_121 )
V_4 -> V_82 = true ;
}
if ( ! ( V_4 -> V_6 . V_125 & V_126 ) ) {
V_4 -> V_6 . V_125 |= V_126 ;
V_4 -> V_82 = true ;
}
error = F_45 ( V_4 ) ;
if ( error )
goto V_127;
F_70 ( V_4 ) ;
F_71 ( V_4 , V_128 ) ;
F_71 ( V_4 , V_129 ) ;
F_72 ( V_4 ) ;
F_73 ( V_4 ) ;
F_74 ( V_4 ) ;
F_49 ( V_4 ) ;
V_4 -> V_130 = 1 ;
error = F_75 ( & V_4 -> V_131 , & V_132 , NULL , V_4 -> V_133 ) ;
if ( error )
goto V_127;
error = F_75 ( & V_4 -> V_134 . V_135 , & V_136 ,
& V_4 -> V_131 , L_15 ) ;
if ( error )
goto V_137;
error = F_76 ( V_4 ) ;
if ( error )
goto V_138;
error = F_3 ( V_4 ) ;
if ( error )
goto V_139;
F_51 ( V_4 ) ;
F_52 ( V_4 ) ;
V_4 -> V_140 = V_141 ;
if ( F_77 ( & V_4 -> V_6 ) ) {
int V_142 = V_4 -> V_140 ;
V_142 *= V_4 -> V_6 . V_143 / V_144 ;
if ( V_4 -> V_6 . V_106 >= F_78 ( V_4 , V_142 ) )
V_4 -> V_140 = V_142 ;
}
if ( F_79 ( & V_4 -> V_6 ) &&
V_4 -> V_6 . V_145 !=
F_78 ( V_4 , V_4 -> V_140 ) ) {
F_5 ( V_4 ,
L_16 ,
V_4 -> V_6 . V_145 ,
F_78 ( V_4 , V_4 -> V_140 ) ) ;
error = - V_12 ;
goto V_146;
}
F_53 ( V_4 ) ;
error = F_56 ( V_4 ) ;
if ( error )
goto V_146;
error = F_80 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_17 ) ;
goto V_146;
}
F_81 ( & V_25 -> V_7 , V_4 -> V_147 ) ;
V_4 -> V_148 = 0 ;
error = F_82 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_18 , error ) ;
goto V_146;
}
F_83 ( V_4 ) ;
F_25 ( & V_4 -> V_23 ) ;
F_27 ( & V_4 -> V_24 , V_45 ) ;
error = F_21 ( V_4 , V_25 -> V_22 , & V_4 -> V_149 ) ;
if ( error ) {
F_5 ( V_4 , L_19 , error ) ;
goto V_150;
}
if ( ! V_25 -> V_111 ) {
F_5 ( V_4 , L_20 ) ;
F_84 ( L_21 , V_151 , V_4 ) ;
error = - V_67 ;
goto V_152;
}
error = F_85 ( V_4 , V_4 -> V_110 ,
F_86 ( V_4 , V_25 -> V_153 ) ,
F_57 ( V_4 , V_25 -> V_111 ) ) ;
if ( error ) {
F_5 ( V_4 , L_22 ) ;
goto V_154;
}
if ( F_87 ( & V_4 -> V_6 ) &&
! F_88 ( V_4 ) &&
! V_4 -> V_6 . V_155 ) {
error = F_89 ( V_4 , V_25 -> V_22 ) ;
if ( error )
goto V_156;
}
error = F_90 ( V_4 , NULL , V_25 -> V_157 , 0 , V_158 , & V_118 ) ;
if ( error ) {
F_5 ( V_4 , L_23 ) ;
goto V_156;
}
ASSERT ( V_118 != NULL ) ;
if ( F_91 ( ! F_92 ( F_93 ( V_118 ) -> V_159 ) ) ) {
F_5 ( V_4 , L_24 ,
( unsigned long long ) V_118 -> V_160 ) ;
F_94 ( V_118 , V_158 ) ;
F_84 ( L_25 , V_151 ,
V_4 ) ;
error = - V_67 ;
goto V_161;
}
V_4 -> V_162 = V_118 ;
F_94 ( V_118 , V_158 ) ;
error = F_95 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_26 ) ;
goto V_161;
}
if ( V_4 -> V_82 && ! ( V_4 -> V_10 & V_163 ) ) {
error = F_62 ( V_4 , false ) ;
if ( error ) {
F_5 ( V_4 , L_27 ) ;
goto V_164;
}
}
if ( F_96 ( V_4 ) ) {
error = F_97 ( V_4 , & V_119 , & V_120 ) ;
if ( error )
goto V_164;
} else {
ASSERT ( ! F_98 ( V_4 ) ) ;
if ( V_4 -> V_6 . V_113 & V_165 ) {
F_99 ( V_4 , L_28 ) ;
error = F_60 ( V_4 ) ;
if ( error )
goto V_164;
}
}
V_4 -> V_166 -> V_167 |= V_168 ;
error = F_100 ( V_4 ) ;
if ( error ) {
F_5 ( V_4 , L_29 ) ;
goto V_164;
}
if ( ( V_4 -> V_10 & ( V_163 | V_169 ) ) ==
V_163 ) {
F_101 ( V_4 ) ;
}
if ( V_119 ) {
ASSERT ( V_4 -> V_112 == 0 ) ;
V_4 -> V_112 = V_120 ;
F_102 ( V_4 ) ;
}
if ( ! ( V_4 -> V_10 & V_163 ) ) {
V_116 = F_63 ( V_4 ) ;
error = F_103 ( V_4 , & V_116 , NULL ) ;
if ( error )
F_5 ( V_4 ,
L_30 ) ;
error = F_104 ( V_4 ) ;
if ( error ) {
F_105 ( V_4 ,
L_31 , error ) ;
F_106 ( V_4 , V_170 ) ;
goto V_171;
}
error = F_107 ( V_4 ) ;
if ( error && error != - V_172 )
goto V_173;
}
return 0 ;
V_173:
F_108 ( V_4 ) ;
V_171:
F_109 ( V_4 ) ;
V_164:
V_4 -> V_166 -> V_167 &= ~ V_168 ;
F_110 ( V_4 ) ;
V_161:
F_111 ( V_118 ) ;
F_112 ( & V_4 -> V_174 ) ;
F_113 ( V_4 , V_175 ) ;
V_156:
V_4 -> V_10 |= V_176 ;
F_114 ( V_4 ) ;
V_154:
if ( V_4 -> V_110 && V_4 -> V_110 != V_4 -> V_62 )
F_115 ( V_4 -> V_110 ) ;
F_115 ( V_4 -> V_62 ) ;
V_152:
F_14 ( V_4 ) ;
V_150:
F_116 ( V_4 ) ;
V_146:
F_10 ( V_4 ) ;
V_139:
F_117 ( V_4 ) ;
V_138:
F_118 ( & V_4 -> V_134 . V_135 ) ;
V_137:
F_118 ( & V_4 -> V_131 ) ;
V_127:
return error ;
}
void
F_119 (
struct V_3 * V_4 )
{
T_5 V_116 ;
int error ;
F_112 ( & V_4 -> V_177 ) ;
F_112 ( & V_4 -> V_178 ) ;
F_108 ( V_4 ) ;
F_109 ( V_4 ) ;
F_110 ( V_4 ) ;
F_111 ( V_4 -> V_162 ) ;
F_120 ( V_4 , V_179 ) ;
F_121 ( V_4 ) ;
F_122 ( V_180 ) ;
V_4 -> V_10 |= V_176 ;
F_123 ( V_4 -> V_181 ) ;
F_112 ( & V_4 -> V_174 ) ;
F_113 ( V_4 , V_175 ) ;
F_124 ( V_4 ) ;
V_116 = 0 ;
error = F_103 ( V_4 , & V_116 , NULL ) ;
if ( error )
F_5 ( V_4 , L_32
L_33 ) ;
error = F_125 ( V_4 ) ;
if ( error )
F_5 ( V_4 , L_34
L_33 ) ;
F_126 ( V_4 ) ;
F_116 ( V_4 ) ;
F_10 ( V_4 ) ;
#if F_127 ( V_182 )
F_128 ( V_4 , 0 ) ;
#endif
F_14 ( V_4 ) ;
F_117 ( V_4 ) ;
F_118 ( & V_4 -> V_134 . V_135 ) ;
F_118 ( & V_4 -> V_131 ) ;
}
bool
F_61 (
struct V_3 * V_4 ,
int V_183 )
{
ASSERT ( V_183 > V_184 ) ;
if ( ( V_4 -> V_166 -> V_185 . V_186 >= V_183 ) ||
F_129 ( V_4 ) || ( V_4 -> V_10 & V_163 ) )
return false ;
return true ;
}
int
F_125 ( T_2 * V_4 )
{
if ( ! F_61 ( V_4 , V_187 ) )
return 0 ;
if ( ! F_87 ( & V_4 -> V_6 ) )
return 0 ;
return F_62 ( V_4 , true ) ;
}
int
F_130 (
struct V_3 * V_4 ,
T_9 V_188 )
{
F_131 ( & V_4 -> V_189 , V_188 , V_190 ) ;
if ( F_132 ( & V_4 -> V_189 , 0 , V_190 ) < 0 ) {
ASSERT ( 0 ) ;
F_133 ( & V_4 -> V_189 , - V_188 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_134 (
struct V_3 * V_4 ,
T_9 V_188 )
{
F_133 ( & V_4 -> V_191 , V_188 ) ;
if ( F_135 ( & V_4 -> V_191 , 0 ) < 0 ) {
ASSERT ( 0 ) ;
F_133 ( & V_4 -> V_191 , - V_188 ) ;
return - V_12 ;
}
return 0 ;
}
int
F_136 (
struct V_3 * V_4 ,
T_9 V_188 ,
bool V_192 )
{
T_9 V_193 ;
long long V_194 ;
T_10 V_195 ;
if ( V_188 > 0 ) {
if ( F_137 ( V_4 -> V_196 == V_4 -> V_197 ) ) {
F_133 ( & V_4 -> V_198 , V_188 ) ;
return 0 ;
}
F_15 ( & V_4 -> V_114 ) ;
V_194 = ( long long ) ( V_4 -> V_196 - V_4 -> V_197 ) ;
if ( V_194 > V_188 ) {
V_4 -> V_197 += V_188 ;
} else {
V_188 -= V_194 ;
V_4 -> V_197 = V_4 -> V_196 ;
F_133 ( & V_4 -> V_198 , V_188 ) ;
}
F_17 ( & V_4 -> V_114 ) ;
return 0 ;
}
if ( F_132 ( & V_4 -> V_198 , 2 * V_199 ,
V_199 ) < 0 )
V_195 = 1 ;
else
V_195 = V_199 ;
F_131 ( & V_4 -> V_198 , V_188 , V_195 ) ;
if ( F_132 ( & V_4 -> V_198 , V_4 -> V_200 ,
V_199 ) >= 0 ) {
return 0 ;
}
F_15 ( & V_4 -> V_114 ) ;
F_133 ( & V_4 -> V_198 , - V_188 ) ;
if ( ! V_192 )
goto V_201;
V_193 = ( long long ) V_4 -> V_197 + V_188 ;
if ( V_193 >= 0 ) {
V_4 -> V_197 = V_193 ;
F_17 ( & V_4 -> V_114 ) ;
return 0 ;
}
F_138 ( V_202
L_35
L_36 ,
V_4 -> V_133 ) ;
V_201:
F_17 ( & V_4 -> V_114 ) ;
return - V_172 ;
}
int
F_139 (
struct V_3 * V_4 ,
T_9 V_188 )
{
T_9 V_193 ;
int V_203 = 0 ;
F_15 ( & V_4 -> V_114 ) ;
V_193 = V_4 -> V_6 . V_204 + V_188 ;
if ( V_193 < 0 )
V_203 = - V_172 ;
else
V_4 -> V_6 . V_204 = V_193 ;
F_17 ( & V_4 -> V_114 ) ;
return V_203 ;
}
struct V_54 *
F_140 (
struct V_3 * V_4 ,
int V_52 )
{
struct V_54 * V_55 = V_4 -> V_61 ;
if ( ! F_141 ( V_55 ) ) {
if ( V_52 & V_205 )
return NULL ;
F_142 ( V_55 ) ;
}
F_143 ( V_55 ) ;
ASSERT ( V_55 -> V_206 & V_207 ) ;
return V_55 ;
}
void
F_144 (
struct V_3 * V_4 )
{
struct V_54 * V_55 = V_4 -> V_61 ;
F_142 ( V_55 ) ;
V_4 -> V_61 = NULL ;
F_42 ( V_55 ) ;
}
int
F_145 (
struct V_3 * V_4 ,
char * V_208 )
{
if ( F_146 ( V_4 -> V_62 ) ||
F_146 ( V_4 -> V_110 ) ||
( V_4 -> V_209 && F_146 ( V_4 -> V_209 ) ) ) {
F_99 ( V_4 , L_37 , V_208 ) ;
F_99 ( V_4 , L_38 ) ;
return - V_210 ;
}
return 0 ;
}
