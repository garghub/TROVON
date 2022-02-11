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
F_53 ( V_2 ) ;
error = F_56 ( V_2 ) ;
if ( error )
goto V_141;
error = F_78 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_16 ) ;
goto V_141;
}
F_79 ( & V_25 -> V_5 , V_2 -> V_142 ) ;
V_2 -> V_143 = 0 ;
F_80 ( V_2 ) ;
V_2 -> V_144 = ( V_2 -> V_4 . V_81 * 37 ) / 100 ;
F_81 ( V_2 ) ;
F_24 ( & V_2 -> V_23 ) ;
F_26 ( & V_2 -> V_24 , V_49 ) ;
error = F_20 ( V_2 , V_25 -> V_22 , & V_2 -> V_145 ) ;
if ( error ) {
F_3 ( V_2 , L_17 , error ) ;
goto V_141;
}
if ( ! V_25 -> V_115 ) {
F_3 ( V_2 , L_18 ) ;
F_82 ( L_19 , V_146 , V_2 ) ;
error = F_4 ( V_147 ) ;
goto V_148;
}
error = F_83 ( V_2 , V_2 -> V_114 ,
F_84 ( V_2 , V_25 -> V_149 ) ,
F_57 ( V_2 , V_25 -> V_115 ) ) ;
if ( error ) {
F_3 ( V_2 , L_20 ) ;
goto V_150;
}
if ( F_85 ( & V_2 -> V_4 ) &&
! F_86 ( V_2 ) &&
! V_2 -> V_4 . V_151 ) {
error = F_87 ( V_2 , V_25 -> V_22 ) ;
if ( error )
goto V_150;
}
error = F_88 ( V_2 , NULL , V_25 -> V_152 , 0 , V_153 , & V_127 ) ;
if ( error ) {
F_3 ( V_2 , L_21 ) ;
goto V_154;
}
ASSERT ( V_127 != NULL ) ;
if ( F_89 ( ! F_90 ( V_127 -> V_155 . V_156 ) ) ) {
F_3 ( V_2 , L_22 ,
( unsigned long long ) V_127 -> V_157 ) ;
F_91 ( V_127 , V_153 ) ;
F_82 ( L_23 , V_146 ,
V_2 ) ;
error = F_4 ( V_147 ) ;
goto V_158;
}
V_2 -> V_159 = V_127 ;
F_91 ( V_127 , V_153 ) ;
error = F_92 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_24 ) ;
goto V_158;
}
if ( V_2 -> V_83 && ! ( V_2 -> V_8 & V_121 ) ) {
error = F_93 ( V_2 , V_2 -> V_83 ) ;
if ( error ) {
F_3 ( V_2 , L_25 ) ;
goto V_160;
}
}
if ( F_94 ( V_2 ) ) {
error = F_95 ( V_2 , & V_128 , & V_129 ) ;
if ( error )
goto V_160;
} else {
ASSERT ( ! F_96 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_119 & V_161 ) {
F_97 ( V_2 , L_26 ) ;
error = F_60 ( V_2 ) ;
if ( error )
return error ;
}
}
error = F_98 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_27 ) ;
goto V_160;
}
if ( V_128 ) {
ASSERT ( V_2 -> V_118 == 0 ) ;
V_2 -> V_118 = V_129 ;
F_99 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_121 ) ) {
V_126 = F_68 ( V_2 ) ;
error = F_100 ( V_2 , & V_126 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_28 ) ;
}
return 0 ;
V_160:
F_101 ( V_2 ) ;
V_158:
F_102 ( V_127 ) ;
V_154:
F_103 ( V_2 ) ;
V_150:
if ( V_2 -> V_114 && V_2 -> V_114 != V_2 -> V_67 )
F_104 ( V_2 -> V_114 ) ;
F_104 ( V_2 -> V_67 ) ;
V_148:
F_14 ( V_2 ) ;
V_141:
F_9 ( V_2 ) ;
V_137:
return error ;
}
void
F_105 (
struct V_1 * V_2 )
{
T_5 V_126 ;
int error ;
F_106 ( & V_2 -> V_162 ) ;
F_107 ( V_2 ) ;
F_101 ( V_2 ) ;
F_102 ( V_2 -> V_159 ) ;
F_108 ( V_2 , V_163 ) ;
F_109 ( V_2 -> V_164 ) ;
F_106 ( & V_2 -> V_165 ) ;
F_110 ( V_2 , V_166 ) ;
F_111 ( V_2 ) ;
V_126 = 0 ;
error = F_100 ( V_2 , & V_126 , NULL ) ;
if ( error )
F_3 ( V_2 , L_29
L_30 ) ;
error = F_112 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_31
L_30 ) ;
F_103 ( V_2 ) ;
F_9 ( V_2 ) ;
#if F_113 ( V_167 )
F_114 ( V_2 , 0 ) ;
#endif
F_14 ( V_2 ) ;
}
int
F_115 ( T_2 * V_2 )
{
return ! ( V_2 -> V_168 -> V_169 . V_170 || F_116 ( V_2 ) ||
( V_2 -> V_8 & V_121 ) ) ;
}
int
F_112 ( T_2 * V_2 )
{
T_13 * V_117 ;
int error ;
if ( ! F_115 ( V_2 ) )
return 0 ;
F_117 ( V_2 , 0 ) ;
if ( ! F_85 ( & V_2 -> V_4 ) )
return 0 ;
V_117 = F_118 ( V_2 , V_171 , V_15 ) ;
error = F_62 ( V_117 , & F_63 ( V_2 ) -> V_172 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_117 , 0 ) ;
return error ;
}
F_66 ( V_117 , V_173 | V_174 | V_175 ) ;
F_119 ( V_117 ) ;
error = F_67 ( V_117 , 0 ) ;
return error ;
}
STATIC int
F_120 (
T_2 * V_2 ,
T_14 V_176 ,
T_15 V_177 ,
int V_178 )
{
int V_179 ;
long long V_180 ;
long long V_181 , V_182 ;
switch ( V_176 ) {
case V_183 :
V_180 = ( long long ) V_2 -> V_4 . V_184 ;
V_180 += V_177 ;
if ( V_180 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_184 = V_180 ;
return 0 ;
case V_185 :
V_180 = ( long long ) V_2 -> V_4 . V_186 ;
V_180 += V_177 ;
if ( V_180 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_186 = V_180 ;
return 0 ;
case V_187 :
V_180 = ( long long )
V_2 -> V_4 . V_188 - F_121 ( V_2 ) ;
V_181 = ( long long ) ( V_2 -> V_189 - V_2 -> V_190 ) ;
if ( V_177 > 0 ) {
if ( V_181 > V_177 ) {
V_2 -> V_190 += V_177 ;
} else {
V_182 = V_177 - V_181 ;
V_2 -> V_190 = V_2 -> V_189 ;
V_180 += V_182 ;
}
} else {
V_180 += V_177 ;
if ( V_180 >= 0 ) {
V_2 -> V_4 . V_188 = V_180 +
F_121 ( V_2 ) ;
return 0 ;
}
if ( ! V_178 )
return F_4 ( V_191 ) ;
V_180 = ( long long ) V_2 -> V_190 + V_177 ;
if ( V_180 >= 0 ) {
V_2 -> V_190 = V_180 ;
return 0 ;
}
F_122 ( V_192
L_32
L_33 ,
V_2 -> V_193 ) ;
return F_4 ( V_191 ) ;
}
V_2 -> V_4 . V_188 = V_180 + F_121 ( V_2 ) ;
return 0 ;
case V_194 :
V_180 = ( long long ) V_2 -> V_4 . V_195 ;
V_180 += V_177 ;
if ( V_180 < 0 ) {
return F_4 ( V_191 ) ;
}
V_2 -> V_4 . V_195 = V_180 ;
return 0 ;
case V_196 :
V_180 = ( long long ) V_2 -> V_4 . V_90 ;
V_180 += V_177 ;
if ( V_180 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_90 = V_180 ;
return 0 ;
case V_197 :
V_179 = V_2 -> V_4 . V_22 ;
V_179 += V_177 ;
if ( V_179 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_22 = V_179 ;
return 0 ;
case V_198 :
V_179 = V_2 -> V_4 . V_89 ;
V_179 += V_177 ;
if ( V_179 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_89 = V_179 ;
return 0 ;
case V_199 :
V_179 = V_2 -> V_4 . V_200 ;
V_179 += V_177 ;
if ( V_179 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_200 = V_179 ;
return 0 ;
case V_201 :
V_179 = V_2 -> V_4 . V_202 ;
V_179 += V_177 ;
if ( V_179 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_202 = V_179 ;
return 0 ;
case V_203 :
V_180 = ( long long ) V_2 -> V_4 . V_204 ;
V_180 += V_177 ;
if ( V_180 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_204 = V_180 ;
return 0 ;
case V_205 :
V_180 = ( long long ) V_2 -> V_4 . V_206 ;
V_180 += V_177 ;
if ( V_180 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_206 = V_180 ;
return 0 ;
case V_207 :
V_179 = V_2 -> V_4 . V_208 ;
V_179 += V_177 ;
if ( V_179 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_208 = V_179 ;
return 0 ;
default:
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
}
int
F_123 (
struct V_1 * V_2 ,
T_14 V_176 ,
T_15 V_177 ,
int V_178 )
{
int V_209 ;
#ifdef F_124
ASSERT ( V_176 < V_183 || V_176 > V_187 ) ;
#endif
F_15 ( & V_2 -> V_120 ) ;
V_209 = F_120 ( V_2 , V_176 , V_177 , V_178 ) ;
F_17 ( & V_2 -> V_120 ) ;
return V_209 ;
}
int
F_125 (
struct V_1 * V_2 ,
T_16 * V_210 ,
T_12 V_211 ,
int V_178 )
{
T_16 * V_212 ;
int error = 0 ;
F_15 ( & V_2 -> V_120 ) ;
for ( V_212 = V_210 ; V_212 < ( V_210 + V_211 ) ; V_212 ++ ) {
ASSERT ( V_212 -> V_213 < V_183 ||
V_212 -> V_213 > V_187 ) ;
error = F_120 ( V_2 , V_212 -> V_213 ,
V_212 -> V_214 , V_178 ) ;
if ( error )
goto V_215;
}
F_17 ( & V_2 -> V_120 ) ;
return 0 ;
V_215:
while ( -- V_212 >= V_210 ) {
error = F_120 ( V_2 , V_212 -> V_213 ,
- V_212 -> V_214 , V_178 ) ;
ASSERT ( error == 0 ) ;
}
F_17 ( & V_2 -> V_120 ) ;
return error ;
}
struct V_61 *
F_126 (
struct V_1 * V_2 ,
int V_59 )
{
struct V_61 * V_62 = V_2 -> V_66 ;
if ( ! F_127 ( V_62 ) ) {
if ( V_59 & V_216 )
return NULL ;
F_128 ( V_62 ) ;
}
F_129 ( V_62 ) ;
ASSERT ( F_130 ( V_62 ) ) ;
return V_62 ;
}
void
F_131 (
struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_66 ;
F_128 ( V_62 ) ;
V_2 -> V_66 = NULL ;
F_42 ( V_62 ) ;
}
int
F_93 (
T_2 * V_2 ,
T_17 V_217 )
{
T_13 * V_117 ;
int error ;
ASSERT ( V_217 & ( V_84 | V_86 | V_218 |
V_132 | V_133 |
V_136 ) ) ;
V_117 = F_61 ( V_2 , V_219 ) ;
error = F_62 ( V_117 , & F_63 ( V_2 ) -> V_172 , 0 , 0 ) ;
if ( error ) {
F_64 ( V_117 , 0 ) ;
return error ;
}
F_66 ( V_117 , V_217 ) ;
error = F_67 ( V_117 , 0 ) ;
return error ;
}
int
F_132 (
struct V_1 * V_2 ,
char * V_220 )
{
if ( F_133 ( V_2 -> V_67 ) ||
F_133 ( V_2 -> V_114 ) ||
( V_2 -> V_221 && F_133 ( V_2 -> V_221 ) ) ) {
F_97 ( V_2 , L_34 , V_220 ) ;
F_97 ( V_2 , L_35 ) ;
return V_222 ;
}
return 0 ;
}
STATIC int
F_134 (
struct V_223 * V_224 ,
unsigned long V_225 ,
void * V_226 )
{
T_18 * V_227 ;
T_2 * V_2 ;
V_2 = ( T_2 * ) F_11 ( V_224 , T_2 , V_228 ) ;
V_227 = ( T_18 * )
F_135 ( V_2 -> V_229 , ( unsigned long ) V_226 ) ;
switch ( V_225 ) {
case V_230 :
case V_231 :
memset ( V_227 , 0 , sizeof( T_18 ) ) ;
break;
case V_232 :
case V_233 :
F_136 ( V_2 ) ;
F_137 ( V_2 , V_183 , 0 ) ;
F_137 ( V_2 , V_185 , 0 ) ;
F_137 ( V_2 , V_187 , 0 ) ;
F_138 ( V_2 ) ;
break;
case V_234 :
case V_235 :
F_136 ( V_2 ) ;
F_15 ( & V_2 -> V_120 ) ;
F_139 ( V_2 , V_183 ) ;
F_139 ( V_2 , V_185 ) ;
F_139 ( V_2 , V_187 ) ;
V_2 -> V_4 . V_184 += V_227 -> V_236 ;
V_2 -> V_4 . V_186 += V_227 -> V_237 ;
V_2 -> V_4 . V_188 += V_227 -> V_238 ;
memset ( V_227 , 0 , sizeof( T_18 ) ) ;
F_140 ( V_2 , V_183 , 0 ) ;
F_140 ( V_2 , V_185 , 0 ) ;
F_140 ( V_2 , V_187 , 0 ) ;
F_17 ( & V_2 -> V_120 ) ;
F_138 ( V_2 ) ;
break;
}
return V_239 ;
}
int
F_141 (
T_2 * V_2 )
{
T_18 * V_227 ;
int V_7 ;
V_2 -> V_229 = F_142 ( T_18 ) ;
if ( V_2 -> V_229 == NULL )
return - V_41 ;
F_143 (i) {
V_227 = ( T_18 * ) F_135 ( V_2 -> V_229 , V_7 ) ;
memset ( V_227 , 0 , sizeof( T_18 ) ) ;
}
F_25 ( & V_2 -> V_240 ) ;
V_2 -> V_241 = - 1 ;
#ifdef F_144
V_2 -> V_228 . V_242 = F_134 ;
V_2 -> V_228 . V_243 = 0 ;
F_145 ( & V_2 -> V_228 ) ;
#endif
return 0 ;
}
void
F_43 (
T_2 * V_2 )
{
F_136 ( V_2 ) ;
V_2 -> V_241 = - 1 ;
F_137 ( V_2 , V_183 , 0 ) ;
F_137 ( V_2 , V_185 , 0 ) ;
F_137 ( V_2 , V_187 , 0 ) ;
F_138 ( V_2 ) ;
}
void
F_146 (
T_2 * V_2 )
{
if ( V_2 -> V_229 ) {
F_147 ( & V_2 -> V_228 ) ;
F_148 ( V_2 -> V_229 ) ;
}
F_149 ( & V_2 -> V_240 ) ;
}
STATIC void
F_150 (
T_18 * V_244 )
{
while ( F_151 ( V_245 , & V_244 -> V_246 ) ) {
F_152 ( 1000 ) ;
}
}
STATIC void
F_153 (
T_18 * V_244 )
{
F_154 ( V_245 , & V_244 -> V_246 ) ;
}
STATIC void
F_155 (
T_2 * V_2 )
{
T_18 * V_227 ;
int V_7 ;
F_143 (i) {
V_227 = ( T_18 * ) F_135 ( V_2 -> V_229 , V_7 ) ;
F_150 ( V_227 ) ;
}
}
STATIC void
F_156 (
T_2 * V_2 )
{
T_18 * V_227 ;
int V_7 ;
F_143 (i) {
V_227 = ( T_18 * ) F_135 ( V_2 -> V_229 , V_7 ) ;
F_153 ( V_227 ) ;
}
}
STATIC void
F_157 (
T_2 * V_2 ,
T_18 * V_247 ,
int V_59 )
{
T_18 * V_227 ;
int V_7 ;
memset ( V_247 , 0 , sizeof( T_18 ) ) ;
if ( ! ( V_59 & V_248 ) )
F_155 ( V_2 ) ;
F_143 (i) {
V_227 = ( T_18 * ) F_135 ( V_2 -> V_229 , V_7 ) ;
V_247 -> V_236 += V_227 -> V_236 ;
V_247 -> V_237 += V_227 -> V_237 ;
V_247 -> V_238 += V_227 -> V_238 ;
}
if ( ! ( V_59 & V_248 ) )
F_156 ( V_2 ) ;
}
STATIC int
F_158 (
T_2 * V_2 ,
T_14 V_176 )
{
ASSERT ( ( V_176 >= V_183 ) && ( V_176 <= V_187 ) ) ;
return F_159 ( V_176 , & V_2 -> V_241 ) ;
}
STATIC void
F_139 (
T_2 * V_2 ,
T_14 V_176 )
{
T_18 V_247 ;
ASSERT ( ( V_176 >= V_183 ) && ( V_176 <= V_187 ) ) ;
if ( F_158 ( V_2 , V_176 ) )
return;
F_155 ( V_2 ) ;
if ( ! F_151 ( V_176 , & V_2 -> V_241 ) ) {
F_157 ( V_2 , & V_247 , V_248 ) ;
switch( V_176 ) {
case V_183 :
V_2 -> V_4 . V_184 = V_247 . V_236 ;
break;
case V_185 :
V_2 -> V_4 . V_186 = V_247 . V_237 ;
break;
case V_187 :
V_2 -> V_4 . V_188 = V_247 . V_238 ;
break;
default:
F_29 () ;
}
}
F_156 ( V_2 ) ;
}
STATIC void
F_160 (
T_2 * V_2 ,
T_14 V_176 ,
T_19 V_249 ,
T_19 V_250 )
{
T_18 * V_227 ;
int V_7 ;
ASSERT ( ( V_176 >= V_183 ) && ( V_176 <= V_187 ) ) ;
F_155 ( V_2 ) ;
F_143 (i) {
V_227 = F_135 ( V_2 -> V_229 , V_7 ) ;
switch ( V_176 ) {
case V_183 :
V_227 -> V_236 = V_249 + V_250 ;
break;
case V_185 :
V_227 -> V_237 = V_249 + V_250 ;
break;
case V_187 :
V_227 -> V_238 = V_249 + V_250 ;
break;
default:
F_29 () ;
break;
}
V_250 = 0 ;
}
F_154 ( V_176 , & V_2 -> V_241 ) ;
F_156 ( V_2 ) ;
}
void
F_161 (
T_2 * V_2 ,
int V_59 )
{
T_18 V_247 ;
F_157 ( V_2 , & V_247 , V_59 ) ;
if ( ! F_158 ( V_2 , V_183 ) )
V_2 -> V_4 . V_184 = V_247 . V_236 ;
if ( ! F_158 ( V_2 , V_185 ) )
V_2 -> V_4 . V_186 = V_247 . V_237 ;
if ( ! F_158 ( V_2 , V_187 ) )
V_2 -> V_4 . V_188 = V_247 . V_238 ;
}
void
F_117 (
T_2 * V_2 ,
int V_59 )
{
F_15 ( & V_2 -> V_120 ) ;
F_161 ( V_2 , V_59 ) ;
F_17 ( & V_2 -> V_120 ) ;
}
STATIC void
F_140 (
T_2 * V_2 ,
T_14 V_176 ,
int V_251 )
{
T_19 V_249 , V_250 ;
int V_252 = F_162 () ;
T_19 V_253 = ( T_19 ) V_251 ;
F_139 ( V_2 , V_176 ) ;
switch ( V_176 ) {
case V_183 :
V_249 = V_2 -> V_4 . V_184 ;
V_250 = F_50 ( V_249 , V_252 ) ;
if ( V_249 < F_163 ( V_253 , V_254 ) )
return;
break;
case V_185 :
V_249 = V_2 -> V_4 . V_186 ;
V_250 = F_50 ( V_249 , V_252 ) ;
if ( V_249 < F_163 ( V_253 , V_254 ) )
return;
break;
case V_187 :
V_249 = V_2 -> V_4 . V_188 ;
V_250 = F_50 ( V_249 , V_252 ) ;
if ( V_249 < F_163 ( V_253 , F_164 ( V_2 ) ) )
return;
break;
default:
F_29 () ;
V_249 = V_250 = 0 ;
break;
}
F_160 ( V_2 , V_176 , V_249 , V_250 ) ;
}
STATIC void
F_137 (
T_2 * V_2 ,
T_14 V_217 ,
int V_251 )
{
F_15 ( & V_2 -> V_120 ) ;
F_140 ( V_2 , V_217 , V_251 ) ;
F_17 ( & V_2 -> V_120 ) ;
}
int
F_165 (
T_2 * V_2 ,
T_14 V_176 ,
T_15 V_177 ,
int V_178 )
{
T_18 * V_244 ;
long long V_180 ;
int V_255 = 0 ;
F_166 () ;
V_256:
F_167 () ;
V_244 = F_168 ( V_2 -> V_229 ) ;
if ( F_89 ( F_158 ( V_2 , V_176 ) ) )
goto V_257;
F_150 ( V_244 ) ;
if ( F_89 ( F_158 ( V_2 , V_176 ) ) ) {
F_153 ( V_244 ) ;
goto V_257;
}
switch ( V_176 ) {
case V_183 :
V_180 = V_244 -> V_236 ;
V_180 += V_177 ;
if ( F_89 ( V_180 < 0 ) )
goto V_258;
V_244 -> V_236 = V_180 ;
break;
case V_185 :
V_180 = V_244 -> V_237 ;
V_180 += V_177 ;
if ( F_89 ( V_180 < 0 ) )
goto V_258;
V_244 -> V_237 = V_180 ;
break;
case V_187 :
F_169 ( ( V_2 -> V_189 - V_2 -> V_190 ) != 0 ) ;
V_180 = V_244 -> V_238 - F_121 ( V_2 ) ;
V_180 += V_177 ;
if ( F_89 ( V_180 < 0 ) )
goto V_258;
V_244 -> V_238 = V_180 + F_121 ( V_2 ) ;
break;
default:
F_29 () ;
break;
}
F_153 ( V_244 ) ;
F_170 () ;
return 0 ;
V_257:
F_170 () ;
F_136 ( V_2 ) ;
if ( ! ( F_158 ( V_2 , V_176 ) ) ) {
F_138 ( V_2 ) ;
goto V_256;
}
F_15 ( & V_2 -> V_120 ) ;
V_255 = F_120 ( V_2 , V_176 , V_177 , V_178 ) ;
F_17 ( & V_2 -> V_120 ) ;
if ( V_255 != V_191 )
F_137 ( V_2 , V_176 , 0 ) ;
F_138 ( V_2 ) ;
return V_255 ;
V_258:
F_153 ( V_244 ) ;
F_170 () ;
F_136 ( V_2 ) ;
F_137 ( V_2 , V_176 , V_177 ) ;
F_138 ( V_2 ) ;
goto V_256;
}
