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
struct V_16 *
F_10 ( struct V_1 * V_2 , T_2 V_17 )
{
struct V_16 * V_18 ;
int V_19 = 0 ;
F_11 () ;
V_18 = F_12 ( & V_2 -> V_20 , V_17 ) ;
if ( V_18 ) {
ASSERT ( F_13 ( & V_18 -> V_21 ) >= 0 ) ;
V_19 = F_14 ( & V_18 -> V_21 ) ;
}
F_15 () ;
F_16 ( V_2 , V_17 , V_19 , V_22 ) ;
return V_18 ;
}
struct V_16 *
F_17 (
struct V_1 * V_2 ,
T_2 V_23 ,
int V_24 )
{
struct V_16 * V_18 ;
int V_25 ;
int V_19 ;
F_11 () ;
V_25 = F_18 ( & V_2 -> V_20 ,
( void * * ) & V_18 , V_23 , 1 , V_24 ) ;
if ( V_25 <= 0 ) {
F_15 () ;
return NULL ;
}
V_19 = F_14 ( & V_18 -> V_21 ) ;
F_15 () ;
F_19 ( V_2 , V_18 -> V_26 , V_19 , V_22 ) ;
return V_18 ;
}
void
F_20 ( struct V_16 * V_18 )
{
int V_19 ;
ASSERT ( F_13 ( & V_18 -> V_21 ) > 0 ) ;
V_19 = F_21 ( & V_18 -> V_21 ) ;
F_22 ( V_18 -> V_27 , V_18 -> V_26 , V_19 , V_22 ) ;
}
STATIC void
F_23 (
struct V_28 * V_29 )
{
struct V_16 * V_18 = F_24 ( V_29 , struct V_16 , V_28 ) ;
ASSERT ( F_13 ( & V_18 -> V_21 ) == 0 ) ;
F_25 ( V_18 ) ;
}
STATIC void
F_26 (
T_3 * V_2 )
{
T_2 V_17 ;
struct V_16 * V_18 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_4 . V_30 ; V_17 ++ ) {
F_27 ( & V_2 -> V_31 ) ;
V_18 = F_28 ( & V_2 -> V_20 , V_17 ) ;
F_29 ( & V_2 -> V_31 ) ;
ASSERT ( V_18 ) ;
ASSERT ( F_13 ( & V_18 -> V_21 ) == 0 ) ;
F_30 ( & V_18 -> V_28 , F_23 ) ;
}
}
int
F_31 (
T_4 * V_32 ,
T_5 V_33 )
{
ASSERT ( V_34 >= V_32 -> V_35 ) ;
ASSERT ( V_32 -> V_35 >= V_36 ) ;
#if V_37
if ( V_33 >> ( V_38 - V_32 -> V_35 ) > V_39 )
return V_40 ;
#else
if ( V_33 << ( V_32 -> V_35 - V_36 ) > V_41 )
return V_40 ;
#endif
return 0 ;
}
STATIC int
F_32 (
T_3 * V_2 ,
T_4 * V_32 ,
int V_42 )
{
int V_43 = ! ( V_42 & V_44 ) ;
if ( V_32 -> V_45 != V_46 ) {
if ( V_43 )
F_3 ( V_2 , L_3 ) ;
return F_4 ( V_47 ) ;
}
if ( ! F_33 ( V_32 ) ) {
if ( V_43 )
F_3 ( V_2 , L_4 ) ;
return F_4 ( V_47 ) ;
}
if ( F_34 (
V_32 -> V_48 == 0 && V_2 -> V_49 == V_2 -> V_50 ) ) {
if ( V_43 )
F_3 ( V_2 ,
L_5
L_6 ) ;
return F_4 ( V_10 ) ;
}
if ( F_34 (
V_32 -> V_48 != 0 && V_2 -> V_49 != V_2 -> V_50 ) ) {
if ( V_43 )
F_3 ( V_2 ,
L_7
L_8 ) ;
return F_4 ( V_10 ) ;
}
if ( F_34 (
V_32 -> V_30 <= 0 ||
V_32 -> V_51 < V_52 ||
V_32 -> V_51 > V_53 ||
V_32 -> V_54 < V_55 ||
V_32 -> V_54 > V_56 ||
V_32 -> V_51 != ( 1 << V_32 -> V_54 ) ||
V_32 -> V_57 < V_58 ||
V_32 -> V_57 > V_59 ||
V_32 -> V_35 < V_60 ||
V_32 -> V_35 > V_61 ||
V_32 -> V_57 != ( 1 << V_32 -> V_35 ) ||
V_32 -> V_62 < V_63 ||
V_32 -> V_62 > V_64 ||
V_32 -> V_65 < V_66 ||
V_32 -> V_65 > V_67 ||
V_32 -> V_62 != ( 1 << V_32 -> V_65 ) ||
( V_32 -> V_35 - V_32 -> V_65 != V_32 -> V_68 ) ||
( V_32 -> V_69 * V_32 -> V_57 > V_70 ) ||
( V_32 -> V_69 * V_32 -> V_57 < V_71 ) ||
( V_32 -> V_72 > 100 ) ||
V_32 -> V_73 == 0 ||
V_32 -> V_73 > F_35 ( V_32 ) ||
V_32 -> V_73 < F_36 ( V_32 ) ) ) {
if ( V_43 )
F_37 ( L_9 ,
V_74 , V_2 , V_32 ) ;
return F_4 ( V_75 ) ;
}
if ( F_34 ( V_32 -> V_57 > V_76 ) ) {
if ( V_43 ) {
F_3 ( V_2 ,
L_10
L_11 ,
V_32 -> V_57 , V_76 ) ;
}
return F_4 ( V_77 ) ;
}
switch ( V_32 -> V_62 ) {
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
default:
if ( V_43 )
F_3 ( V_2 , L_12 ,
V_32 -> V_62 ) ;
return F_4 ( V_77 ) ;
}
if ( F_31 ( V_32 , V_32 -> V_73 ) ||
F_31 ( V_32 , V_32 -> V_78 ) ) {
if ( V_43 )
F_3 ( V_2 ,
L_13 ) ;
return F_4 ( V_40 ) ;
}
if ( F_34 ( V_32 -> V_79 ) ) {
if ( V_43 )
F_3 ( V_2 , L_14 ) ;
return F_4 ( V_75 ) ;
}
if ( F_34 ( ! F_38 ( V_32 ) ) ) {
if ( V_43 )
F_3 ( V_2 ,
L_15 ) ;
return F_4 ( V_77 ) ;
}
return 0 ;
}
int
F_39 (
T_3 * V_2 ,
T_2 V_80 ,
T_2 * V_81 )
{
T_2 V_82 , V_83 ;
T_2 V_84 = 0 ;
T_6 * V_18 ;
T_7 V_85 ;
T_8 V_86 ;
T_4 * V_32 = & V_2 -> V_4 ;
int error = - V_87 ;
for ( V_82 = 0 ; V_82 < V_80 ; V_82 ++ ) {
V_18 = F_10 ( V_2 , V_82 ) ;
if ( V_18 ) {
F_20 ( V_18 ) ;
continue;
}
if ( ! V_84 )
V_84 = V_82 ;
V_18 = F_40 ( sizeof( * V_18 ) , V_88 ) ;
if ( ! V_18 )
goto V_89;
V_18 -> V_26 = V_82 ;
V_18 -> V_27 = V_2 ;
F_41 ( & V_18 -> V_90 ) ;
F_42 ( & V_18 -> V_91 ) ;
F_43 ( & V_18 -> V_92 , V_93 ) ;
F_41 ( & V_18 -> V_94 ) ;
V_18 -> V_95 = V_96 ;
if ( F_44 ( V_97 ) )
goto V_89;
F_27 ( & V_2 -> V_31 ) ;
if ( F_45 ( & V_2 -> V_20 , V_82 , V_18 ) ) {
F_46 () ;
F_29 ( & V_2 -> V_31 ) ;
F_47 () ;
error = - V_98 ;
goto V_89;
}
F_29 ( & V_2 -> V_31 ) ;
F_47 () ;
}
V_85 = F_48 ( V_2 , V_32 -> V_99 - 1 , 0 ) ;
V_86 = F_49 ( V_2 , V_80 - 1 , V_85 ) ;
if ( ( V_2 -> V_8 & V_100 ) && V_86 > V_101 )
V_2 -> V_8 |= V_102 ;
else
V_2 -> V_8 &= ~ V_102 ;
if ( V_2 -> V_8 & V_102 ) {
if ( V_2 -> V_103 ) {
T_5 V_104 ;
V_104 = V_32 -> V_73 * V_32 -> V_72 ;
F_50 ( V_104 , 100 ) ;
V_104 += V_32 -> V_99 - 1 ;
F_50 ( V_104 , V_32 -> V_99 ) ;
V_83 = V_104 ;
} else {
V_83 = V_80 ;
}
for ( V_82 = 0 ; V_82 < V_80 ; V_82 ++ ) {
V_86 = F_49 ( V_2 , V_82 , V_85 ) ;
if ( V_86 > V_101 ) {
V_82 ++ ;
break;
}
V_18 = F_10 ( V_2 , V_82 ) ;
V_18 -> V_105 = 1 ;
if ( V_82 < V_83 )
V_18 -> V_106 = 1 ;
F_20 ( V_18 ) ;
}
} else {
for ( V_82 = 0 ; V_82 < V_80 ; V_82 ++ ) {
V_18 = F_10 ( V_2 , V_82 ) ;
V_18 -> V_105 = 1 ;
F_20 ( V_18 ) ;
}
}
if ( V_81 )
* V_81 = V_82 ;
return 0 ;
V_89:
F_25 ( V_18 ) ;
for (; V_82 > V_84 ; V_82 -- ) {
V_18 = F_28 ( & V_2 -> V_20 , V_82 ) ;
F_25 ( V_18 ) ;
}
return error ;
}
void
F_51 (
struct V_1 * V_2 ,
T_9 * V_107 )
{
struct V_108 * V_109 = & V_2 -> V_4 ;
V_109 -> V_45 = F_52 ( V_107 -> V_45 ) ;
V_109 -> V_57 = F_52 ( V_107 -> V_57 ) ;
V_109 -> V_73 = F_53 ( V_107 -> V_73 ) ;
V_109 -> V_78 = F_53 ( V_107 -> V_78 ) ;
V_109 -> V_110 = F_53 ( V_107 -> V_110 ) ;
memcpy ( & V_109 -> V_5 , & V_107 -> V_5 , sizeof( V_109 -> V_5 ) ) ;
V_109 -> V_48 = F_53 ( V_107 -> V_48 ) ;
V_109 -> V_111 = F_53 ( V_107 -> V_111 ) ;
V_109 -> V_112 = F_53 ( V_107 -> V_112 ) ;
V_109 -> V_113 = F_53 ( V_107 -> V_113 ) ;
V_109 -> V_69 = F_52 ( V_107 -> V_69 ) ;
V_109 -> V_99 = F_52 ( V_107 -> V_99 ) ;
V_109 -> V_30 = F_52 ( V_107 -> V_30 ) ;
V_109 -> V_114 = F_52 ( V_107 -> V_114 ) ;
V_109 -> V_115 = F_52 ( V_107 -> V_115 ) ;
V_109 -> V_116 = F_54 ( V_107 -> V_116 ) ;
V_109 -> V_51 = F_54 ( V_107 -> V_51 ) ;
V_109 -> V_62 = F_54 ( V_107 -> V_62 ) ;
V_109 -> V_117 = F_54 ( V_107 -> V_117 ) ;
memcpy ( & V_109 -> V_118 , & V_107 -> V_118 , sizeof( V_109 -> V_118 ) ) ;
V_109 -> V_35 = V_107 -> V_35 ;
V_109 -> V_54 = V_107 -> V_54 ;
V_109 -> V_65 = V_107 -> V_65 ;
V_109 -> V_68 = V_107 -> V_68 ;
V_109 -> V_119 = V_107 -> V_119 ;
V_109 -> V_120 = V_107 -> V_120 ;
V_109 -> V_79 = V_107 -> V_79 ;
V_109 -> V_72 = V_107 -> V_72 ;
V_109 -> V_121 = F_53 ( V_107 -> V_121 ) ;
V_109 -> V_122 = F_53 ( V_107 -> V_122 ) ;
V_109 -> V_123 = F_53 ( V_107 -> V_123 ) ;
V_109 -> V_124 = F_53 ( V_107 -> V_124 ) ;
V_109 -> V_125 = F_53 ( V_107 -> V_125 ) ;
V_109 -> V_126 = F_53 ( V_107 -> V_126 ) ;
V_109 -> V_127 = F_54 ( V_107 -> V_127 ) ;
V_109 -> V_128 = V_107 -> V_128 ;
V_109 -> V_129 = V_107 -> V_129 ;
V_109 -> V_130 = F_52 ( V_107 -> V_130 ) ;
V_109 -> V_131 = F_52 ( V_107 -> V_131 ) ;
V_109 -> V_132 = F_52 ( V_107 -> V_132 ) ;
V_109 -> V_133 = V_107 -> V_133 ;
V_109 -> V_134 = V_107 -> V_134 ;
V_109 -> V_135 = F_54 ( V_107 -> V_135 ) ;
V_109 -> V_136 = F_52 ( V_107 -> V_136 ) ;
V_109 -> V_137 = F_52 ( V_107 -> V_137 ) ;
V_109 -> V_138 = F_52 ( V_107 -> V_138 ) ;
}
void
F_55 (
T_9 * V_109 ,
T_4 * V_107 ,
T_10 V_139 )
{
T_11 V_140 = ( T_11 ) V_109 ;
T_11 V_141 = ( T_11 ) V_107 ;
T_12 V_142 ;
int V_23 ;
int V_143 ;
ASSERT ( V_139 ) ;
if ( ! V_139 )
return;
while ( V_139 ) {
V_142 = ( T_12 ) F_56 ( ( T_5 ) V_139 ) ;
V_23 = V_144 [ V_142 ] . V_145 ;
V_143 = V_144 [ V_142 + 1 ] . V_145 - V_23 ;
ASSERT ( V_144 [ V_142 ] . type == 0 || V_144 [ V_142 ] . type == 1 ) ;
if ( V_143 == 1 || V_144 [ V_142 ] . type == 1 ) {
memcpy ( V_140 + V_23 , V_141 + V_23 , V_143 ) ;
} else {
switch ( V_143 ) {
case 2 :
* ( V_146 * ) ( V_140 + V_23 ) =
F_57 ( * ( V_147 * ) ( V_141 + V_23 ) ) ;
break;
case 4 :
* ( V_148 * ) ( V_140 + V_23 ) =
F_58 ( * ( V_149 * ) ( V_141 + V_23 ) ) ;
break;
case 8 :
* ( V_150 * ) ( V_140 + V_23 ) =
F_59 ( * ( V_151 * ) ( V_141 + V_23 ) ) ;
break;
default:
ASSERT ( 0 ) ;
}
}
V_139 &= ~ ( 1LL << V_142 ) ;
}
}
int
F_60 ( T_3 * V_2 , int V_42 )
{
unsigned int V_152 ;
T_13 * V_153 ;
int error ;
int V_43 = ! ( V_42 & V_44 ) ;
ASSERT ( V_2 -> V_154 == NULL ) ;
ASSERT ( V_2 -> V_50 != NULL ) ;
V_152 = F_61 ( V_2 -> V_50 ) ;
V_155:
V_153 = F_62 ( V_2 , V_2 -> V_50 ,
V_156 , V_152 , 0 ) ;
if ( ! V_153 ) {
if ( V_43 )
F_3 ( V_2 , L_16 ) ;
return V_157 ;
}
F_51 ( V_2 , F_63 ( V_153 ) ) ;
error = F_32 ( V_2 , & ( V_2 -> V_4 ) , V_42 ) ;
if ( error ) {
if ( V_43 )
F_3 ( V_2 , L_17 ) ;
goto V_158;
}
if ( V_152 > V_2 -> V_4 . V_51 ) {
if ( V_43 )
F_3 ( V_2 , L_18 ,
V_152 , V_2 -> V_4 . V_51 ) ;
error = V_77 ;
goto V_158;
}
if ( V_152 < V_2 -> V_4 . V_51 ) {
F_64 ( V_153 ) ;
V_152 = V_2 -> V_4 . V_51 ;
goto V_155;
}
F_65 ( V_2 ) ;
V_2 -> V_154 = V_153 ;
F_66 ( V_153 ) ;
return 0 ;
V_158:
F_64 ( V_153 ) ;
return error ;
}
STATIC void
F_67 ( T_3 * V_2 , T_4 * V_32 )
{
V_2 -> V_159 = V_2 -> V_160 = 0 ;
F_41 ( & V_2 -> V_161 ) ;
V_2 -> V_162 = V_2 -> V_4 . V_30 ;
V_2 -> V_163 = V_32 -> V_35 + V_164 ;
V_2 -> V_165 = V_32 -> V_35 - V_36 ;
V_2 -> V_166 = V_32 -> V_54 - V_36 ;
V_2 -> V_167 = F_68 ( V_32 -> V_30 - 1 ) + 1 ;
V_2 -> V_168 = V_32 -> V_68 + V_32 -> V_119 ;
V_2 -> V_169 = V_32 -> V_57 - 1 ;
V_2 -> V_170 = V_32 -> V_57 >> V_171 ;
V_2 -> V_172 = V_2 -> V_170 - 1 ;
V_2 -> V_173 [ 0 ] = F_69 ( V_2 , V_32 -> V_57 , 1 ) ;
V_2 -> V_173 [ 1 ] = F_69 ( V_2 , V_32 -> V_57 , 0 ) ;
V_2 -> V_174 [ 0 ] = V_2 -> V_173 [ 0 ] / 2 ;
V_2 -> V_174 [ 1 ] = V_2 -> V_173 [ 1 ] / 2 ;
V_2 -> V_175 [ 0 ] = F_70 ( V_2 , V_32 -> V_57 , 1 ) ;
V_2 -> V_175 [ 1 ] = F_70 ( V_2 , V_32 -> V_57 , 0 ) ;
V_2 -> V_176 [ 0 ] = V_2 -> V_175 [ 0 ] / 2 ;
V_2 -> V_176 [ 1 ] = V_2 -> V_175 [ 1 ] / 2 ;
V_2 -> V_177 [ 0 ] = F_71 ( V_2 , V_32 -> V_57 , 1 ) ;
V_2 -> V_177 [ 1 ] = F_71 ( V_2 , V_32 -> V_57 , 0 ) ;
V_2 -> V_178 [ 0 ] = V_2 -> V_177 [ 0 ] / 2 ;
V_2 -> V_178 [ 1 ] = V_2 -> V_177 [ 1 ] / 2 ;
V_2 -> V_179 = F_72 ( V_2 , 1 ) ;
V_2 -> V_180 = ( int ) F_73 ( ( V_181 ) V_182 ,
V_32 -> V_117 ) ;
V_2 -> V_183 = V_2 -> V_180 >> V_32 -> V_68 ;
}
STATIC int
F_74 ( T_3 * V_2 , T_2 V_80 )
{
T_2 V_82 ;
T_6 * V_18 ;
T_4 * V_32 = & V_2 -> V_4 ;
T_14 V_184 = 0 ;
T_14 V_185 = 0 ;
T_14 V_186 = 0 ;
T_14 V_187 = 0 ;
T_14 V_188 = 0 ;
int error ;
for ( V_82 = 0 ; V_82 < V_80 ; V_82 ++ ) {
error = F_75 ( V_2 , NULL , V_82 , 0 ) ;
if ( error )
return error ;
error = F_76 ( V_2 , NULL , V_82 ) ;
if ( error )
return error ;
V_18 = F_10 ( V_2 , V_82 ) ;
V_184 += V_18 -> V_189 ;
V_185 += V_18 -> V_190 ;
V_186 += V_18 -> V_191 ;
V_187 += V_18 -> V_192 ;
V_188 += V_18 -> V_193 ;
F_20 ( V_18 ) ;
}
F_27 ( & V_2 -> V_194 ) ;
V_32 -> V_122 = V_184 ;
V_32 -> V_121 = V_185 ;
V_32 -> V_123 = V_186 + V_187 + V_188 ;
F_29 ( & V_2 -> V_194 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
STATIC int
F_77 ( T_3 * V_2 )
{
T_4 * V_32 = & ( V_2 -> V_4 ) ;
if ( V_2 -> V_195 ) {
if ( ( F_78 ( V_2 -> V_195 ) & V_2 -> V_169 ) ||
( F_78 ( V_2 -> V_196 ) & V_2 -> V_169 ) ) {
if ( V_2 -> V_8 & V_197 ) {
F_3 ( V_2 , L_19
L_20 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_195 = V_2 -> V_196 = 0 ;
} else {
V_2 -> V_195 = F_79 ( V_2 , V_2 -> V_195 ) ;
if ( V_2 -> V_195 && ( V_32 -> V_99 % V_2 -> V_195 ) ) {
if ( V_2 -> V_8 & V_197 ) {
F_3 ( V_2 , L_19
L_21 ) ;
return F_4 ( V_10 ) ;
}
F_3 ( V_2 ,
L_22
L_23 ,
V_2 -> V_195 , V_2 -> V_196 ,
V_32 -> V_99 ) ;
V_2 -> V_195 = 0 ;
V_2 -> V_196 = 0 ;
} else if ( V_2 -> V_195 ) {
V_2 -> V_196 = F_79 ( V_2 , V_2 -> V_196 ) ;
} else {
if ( V_2 -> V_8 & V_197 ) {
F_3 ( V_2 , L_19
L_24 ,
V_2 -> V_195 ,
V_2 -> V_169 + 1 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_196 = 0 ;
}
}
if ( F_80 ( V_32 ) ) {
if ( V_32 -> V_131 != V_2 -> V_195 ) {
V_32 -> V_131 = V_2 -> V_195 ;
V_2 -> V_198 |= V_199 ;
}
if ( V_32 -> V_132 != V_2 -> V_196 ) {
V_32 -> V_132 = V_2 -> V_196 ;
V_2 -> V_198 |= V_200 ;
}
}
} else if ( ( V_2 -> V_8 & V_201 ) != V_201 &&
F_80 ( & V_2 -> V_4 ) ) {
V_2 -> V_195 = V_32 -> V_131 ;
V_2 -> V_196 = V_32 -> V_132 ;
}
return 0 ;
}
STATIC void
F_81 ( T_3 * V_2 )
{
T_4 * V_32 = & ( V_2 -> V_4 ) ;
T_5 V_104 ;
if ( V_32 -> V_72 ) {
V_104 = V_32 -> V_73 * V_32 -> V_72 ;
F_50 ( V_104 , 100 ) ;
F_50 ( V_104 , V_2 -> V_183 ) ;
V_2 -> V_103 = ( V_104 * V_2 -> V_183 ) <<
V_32 -> V_68 ;
} else {
V_2 -> V_103 = 0 ;
}
}
STATIC void
F_82 ( T_3 * V_2 )
{
T_4 * V_32 = & ( V_2 -> V_4 ) ;
int V_202 , V_203 ;
if ( ! ( V_2 -> V_8 & V_204 ) ) {
if ( V_2 -> V_8 & V_205 ) {
V_202 = V_206 ;
V_203 = V_207 ;
} else {
V_202 = V_208 ;
V_203 = V_209 ;
}
} else {
V_202 = V_2 -> V_210 ;
V_203 = V_2 -> V_211 ;
}
if ( V_32 -> V_35 > V_202 ) {
V_2 -> V_210 = V_32 -> V_35 ;
} else {
V_2 -> V_210 = V_202 ;
}
V_2 -> V_212 = 1 << ( V_2 -> V_210 - V_32 -> V_35 ) ;
if ( V_32 -> V_35 > V_203 ) {
V_2 -> V_211 = V_32 -> V_35 ;
} else {
V_2 -> V_211 = V_203 ;
}
V_2 -> V_213 = 1 << ( V_2 -> V_211 - V_32 -> V_35 ) ;
}
void
F_83 (
struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_214 ; V_7 ++ ) {
T_5 V_215 = V_2 -> V_4 . V_73 ;
F_50 ( V_215 , 100 ) ;
V_2 -> V_216 [ V_7 ] = V_215 * ( V_7 + 1 ) ;
}
}
STATIC void
F_84 ( T_3 * V_2 )
{
if ( F_85 ( & V_2 -> V_4 ) &&
V_2 -> V_4 . V_130 >=
F_86 ( V_2 , V_2 -> V_217 ) )
V_2 -> V_218 = V_2 -> V_4 . V_130 - 1 ;
else
V_2 -> V_218 = 0 ;
if ( V_2 -> V_195 && V_2 -> V_218 &&
! ( V_2 -> V_195 & V_2 -> V_218 ) )
V_2 -> V_219 = V_2 -> V_195 ;
else
V_2 -> V_219 = 0 ;
}
STATIC int
F_87 ( T_3 * V_2 )
{
T_13 * V_153 ;
T_15 V_220 ;
V_220 = ( T_15 ) F_72 ( V_2 , V_2 -> V_4 . V_73 ) ;
if ( F_88 ( V_2 , V_220 ) != V_2 -> V_4 . V_73 ) {
F_3 ( V_2 , L_25 ) ;
return F_4 ( V_40 ) ;
}
V_153 = F_62 ( V_2 , V_2 -> V_50 ,
V_220 - F_89 ( V_2 , 1 ) ,
F_78 ( F_89 ( V_2 , 1 ) ) , 0 ) ;
if ( ! V_153 ) {
F_3 ( V_2 , L_26 ) ;
return V_157 ;
}
F_64 ( V_153 ) ;
if ( V_2 -> V_49 != V_2 -> V_50 ) {
V_220 = ( T_15 ) F_72 ( V_2 , V_2 -> V_4 . V_115 ) ;
if ( F_88 ( V_2 , V_220 ) != V_2 -> V_4 . V_115 ) {
F_3 ( V_2 , L_27 ) ;
return F_4 ( V_40 ) ;
}
V_153 = F_62 ( V_2 , V_2 -> V_49 ,
V_220 - F_72 ( V_2 , 1 ) ,
F_90 ( V_2 , 1 ) , 0 ) ;
if ( ! V_153 ) {
F_3 ( V_2 , L_28 ) ;
return V_157 ;
}
F_64 ( V_153 ) ;
}
return 0 ;
}
int
F_91 (
struct V_1 * V_2 )
{
int error ;
struct V_221 * V_222 ;
V_2 -> V_223 = 0 ;
if ( V_2 -> V_4 . V_127 == 0 )
return 0 ;
F_27 ( & V_2 -> V_194 ) ;
V_2 -> V_4 . V_127 = 0 ;
F_29 ( & V_2 -> V_194 ) ;
if ( V_2 -> V_8 & V_224 )
return 0 ;
V_222 = F_92 ( V_2 , V_225 ) ;
error = F_93 ( V_222 , 0 , V_2 -> V_4 . V_51 + 128 , 0 , 0 ,
V_226 ) ;
if ( error ) {
F_94 ( V_222 , 0 ) ;
F_95 ( V_2 , L_29 , V_227 ) ;
return error ;
}
F_96 ( V_222 , V_228 ) ;
return F_97 ( V_222 , 0 ) ;
}
T_5
F_98 ( T_3 * V_2 )
{
T_5 V_229 ;
V_229 = V_2 -> V_4 . V_73 ;
F_50 ( V_229 , 20 ) ;
V_229 = F_99 ( T_5 , V_229 , 8192 ) ;
return V_229 ;
}
int
F_100 (
T_3 * V_2 )
{
T_4 * V_32 = & ( V_2 -> V_4 ) ;
T_16 * V_230 ;
T_5 V_229 ;
T_17 V_231 = 0 ;
T_17 V_232 = 0 ;
int error = 0 ;
F_67 ( V_2 , V_32 ) ;
if ( F_101 ( V_32 ) ) {
F_3 ( V_2 , L_30 ) ;
V_32 -> V_137 |= V_32 -> V_138 ;
V_32 -> V_138 = V_32 -> V_137 ;
V_2 -> V_198 |= V_233 | V_234 ;
if ( F_102 ( & V_2 -> V_4 ) &&
! ( V_2 -> V_8 & V_235 ) )
V_2 -> V_8 |= V_236 ;
}
if ( F_102 ( & V_2 -> V_4 ) &&
( V_2 -> V_8 & V_235 ) ) {
F_103 ( & V_2 -> V_4 ) ;
V_2 -> V_198 |= V_233 ;
if ( ! V_32 -> V_137 )
V_2 -> V_198 |= V_237 ;
}
error = F_77 ( V_2 ) ;
if ( error )
goto V_238;
F_104 ( V_2 ) ;
F_105 ( V_2 , V_239 ) ;
F_105 ( V_2 , V_240 ) ;
F_106 ( V_2 ) ;
F_81 ( V_2 ) ;
V_2 -> V_241 = F_107 ( V_32 -> V_35 ) ;
error = F_1 ( V_2 ) ;
if ( error )
goto V_238;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
V_2 -> V_217 = V_242 ;
F_84 ( V_2 ) ;
error = F_87 ( V_2 ) ;
if ( error )
goto V_243;
error = F_108 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_31 ) ;
goto V_243;
}
F_109 ( & V_32 -> V_5 , V_2 -> V_244 ) ;
V_2 -> V_245 = 0 ;
F_110 ( V_2 ) ;
V_2 -> V_246 = ( V_2 -> V_4 . V_57 * 37 ) / 100 ;
F_111 ( V_2 ) ;
F_41 ( & V_2 -> V_31 ) ;
F_43 ( & V_2 -> V_20 , V_93 ) ;
error = F_39 ( V_2 , V_32 -> V_30 , & V_2 -> V_162 ) ;
if ( error ) {
F_3 ( V_2 , L_32 , error ) ;
goto V_243;
}
if ( ! V_32 -> V_115 ) {
F_3 ( V_2 , L_33 ) ;
F_112 ( L_34 , V_74 , V_2 ) ;
error = F_4 ( V_75 ) ;
goto V_247;
}
error = F_113 ( V_2 , V_2 -> V_49 ,
F_114 ( V_2 , V_32 -> V_48 ) ,
F_72 ( V_2 , V_32 -> V_115 ) ) ;
if ( error ) {
F_3 ( V_2 , L_35 ) ;
goto V_247;
}
if ( F_115 ( & V_2 -> V_4 ) &&
! F_116 ( V_2 ) &&
! V_2 -> V_4 . V_79 ) {
error = F_74 ( V_2 , V_32 -> V_30 ) ;
if ( error )
goto V_247;
}
error = F_117 ( V_2 , NULL , V_32 -> V_111 , 0 , V_248 , & V_230 ) ;
if ( error ) {
F_3 ( V_2 , L_36 ) ;
goto V_249;
}
ASSERT ( V_230 != NULL ) ;
if ( F_34 ( ! F_118 ( V_230 -> V_250 . V_251 ) ) ) {
F_3 ( V_2 , L_37 ,
( unsigned long long ) V_230 -> V_252 ) ;
F_119 ( V_230 , V_248 ) ;
F_112 ( L_38 , V_74 ,
V_2 ) ;
error = F_4 ( V_75 ) ;
goto V_253;
}
V_2 -> V_254 = V_230 ;
F_119 ( V_230 , V_248 ) ;
error = F_120 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_39 ) ;
goto V_253;
}
if ( V_2 -> V_198 && ! ( V_2 -> V_8 & V_224 ) ) {
error = F_121 ( V_2 , V_2 -> V_198 ) ;
if ( error ) {
F_3 ( V_2 , L_40 ) ;
goto V_255;
}
}
if ( F_122 ( V_2 ) ) {
error = F_123 ( V_2 , & V_231 , & V_232 ) ;
if ( error )
goto V_255;
} else {
ASSERT ( ! F_124 ( V_2 ) ) ;
if ( V_2 -> V_4 . V_127 & V_256 ) {
F_125 ( V_2 , L_41 ) ;
error = F_91 ( V_2 ) ;
if ( error )
return error ;
}
}
error = F_126 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 , L_42 ) ;
goto V_255;
}
if ( V_231 ) {
ASSERT ( V_2 -> V_223 == 0 ) ;
V_2 -> V_223 = V_232 ;
F_127 ( V_2 ) ;
}
if ( ! ( V_2 -> V_8 & V_224 ) ) {
V_229 = F_98 ( V_2 ) ;
error = F_128 ( V_2 , & V_229 , NULL ) ;
if ( error )
F_3 ( V_2 ,
L_43 ) ;
}
return 0 ;
V_255:
F_129 ( V_2 ) ;
V_253:
F_130 ( V_230 ) ;
V_249:
F_131 ( V_2 ) ;
V_247:
F_26 ( V_2 ) ;
V_243:
F_9 ( V_2 ) ;
V_238:
return error ;
}
void
F_132 (
struct V_1 * V_2 )
{
T_5 V_229 ;
int error ;
F_133 ( V_2 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 -> V_254 ) ;
F_134 ( V_2 , V_257 ) ;
F_135 ( V_2 , 0 ) ;
F_136 ( V_2 -> V_50 , 1 ) ;
F_135 ( V_2 , V_258 ) ;
F_137 ( V_2 ) ;
F_134 ( V_2 , V_257 ) ;
V_229 = 0 ;
error = F_128 ( V_2 , & V_229 , NULL ) ;
if ( error )
F_3 ( V_2 , L_44
L_45 ) ;
error = F_138 ( V_2 ) ;
if ( error )
F_3 ( V_2 , L_46
L_45 ) ;
F_139 ( V_2 ) ;
error = F_136 ( V_2 -> V_50 , 1 ) ;
if ( error )
F_3 ( V_2 , L_47 , error ) ;
F_140 ( V_2 -> V_50 ) ;
F_141 ( V_2 ) ;
F_131 ( V_2 ) ;
F_9 ( V_2 ) ;
#if F_142 ( V_259 )
F_143 ( V_2 , 0 ) ;
#endif
F_26 ( V_2 ) ;
}
int
F_144 ( T_3 * V_2 )
{
return ! ( F_145 ( V_2 ) || F_146 ( V_2 ) ||
( V_2 -> V_8 & V_224 ) ) ;
}
int
F_138 ( T_3 * V_2 )
{
T_18 * V_222 ;
int error ;
if ( ! F_144 ( V_2 ) )
return 0 ;
F_147 ( V_2 , 0 ) ;
if ( ! F_115 ( & V_2 -> V_4 ) )
return 0 ;
V_222 = F_148 ( V_2 , V_260 , V_15 ) ;
error = F_93 ( V_222 , 0 , V_2 -> V_4 . V_51 + 128 , 0 , 0 ,
V_226 ) ;
if ( error ) {
F_94 ( V_222 , 0 ) ;
return error ;
}
F_96 ( V_222 , V_261 | V_262 | V_263 ) ;
F_149 ( V_222 ) ;
error = F_97 ( V_222 , 0 ) ;
return error ;
}
int
F_139 ( T_3 * V_2 )
{
T_13 * V_32 ;
int error = 0 ;
if ( ! ( ( V_2 -> V_8 & V_224 ) ||
F_146 ( V_2 ) ) ) {
V_32 = F_150 ( V_2 , 0 ) ;
F_151 ( V_32 ) ;
F_152 ( V_32 ) ;
F_153 ( V_32 ) ;
F_154 ( V_32 ) ;
F_155 ( V_32 ) ;
ASSERT ( V_32 -> V_264 == V_2 -> V_50 ) ;
F_156 ( V_2 , V_32 ) ;
error = F_157 ( V_32 ) ;
if ( error )
F_158 ( V_32 , V_227 ) ;
F_64 ( V_32 ) ;
}
return error ;
}
void
F_96 ( T_18 * V_222 , T_10 V_139 )
{
T_13 * V_153 ;
int V_23 ;
int V_265 ;
T_3 * V_2 ;
T_12 V_142 ;
ASSERT ( V_139 ) ;
if ( ! V_139 )
return;
V_2 = V_222 -> V_266 ;
V_153 = F_159 ( V_222 , V_2 , 0 ) ;
V_23 = sizeof( T_4 ) ;
V_265 = 0 ;
F_55 ( F_63 ( V_153 ) , & V_2 -> V_4 , V_139 ) ;
V_142 = ( T_12 ) F_160 ( ( T_5 ) V_139 ) ;
ASSERT ( ( 1LL << V_142 ) & V_267 ) ;
V_265 = V_144 [ V_142 + 1 ] . V_145 - 1 ;
V_142 = ( T_12 ) F_56 ( ( T_5 ) V_139 ) ;
ASSERT ( ( 1LL << V_142 ) & V_267 ) ;
V_23 = V_144 [ V_142 ] . V_145 ;
F_161 ( V_222 , V_153 , V_23 , V_265 ) ;
}
STATIC int
F_162 (
T_3 * V_2 ,
T_12 V_268 ,
T_19 V_269 ,
int V_270 )
{
int V_271 ;
long long V_272 ;
long long V_273 , V_274 ;
switch ( V_268 ) {
case V_275 :
V_272 = ( long long ) V_2 -> V_4 . V_121 ;
V_272 += V_269 ;
if ( V_272 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_121 = V_272 ;
return 0 ;
case V_276 :
V_272 = ( long long ) V_2 -> V_4 . V_122 ;
V_272 += V_269 ;
if ( V_272 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_122 = V_272 ;
return 0 ;
case V_277 :
V_272 = ( long long )
V_2 -> V_4 . V_123 - F_163 ( V_2 ) ;
V_273 = ( long long ) ( V_2 -> V_278 - V_2 -> V_279 ) ;
if ( V_269 > 0 ) {
if ( V_273 > V_269 ) {
V_2 -> V_279 += V_269 ;
} else {
V_274 = V_269 - V_273 ;
V_2 -> V_279 = V_2 -> V_278 ;
V_272 += V_274 ;
}
} else {
V_272 += V_269 ;
if ( V_272 >= 0 ) {
V_2 -> V_4 . V_123 = V_272 +
F_163 ( V_2 ) ;
return 0 ;
}
if ( ! V_270 )
return F_4 ( V_280 ) ;
V_272 = ( long long ) V_2 -> V_279 + V_269 ;
if ( V_272 >= 0 ) {
V_2 -> V_279 = V_272 ;
return 0 ;
}
F_164 ( V_281
L_48
L_49 ,
V_2 -> V_282 ) ;
return F_4 ( V_280 ) ;
}
V_2 -> V_4 . V_123 = V_272 + F_163 ( V_2 ) ;
return 0 ;
case V_283 :
V_272 = ( long long ) V_2 -> V_4 . V_124 ;
V_272 += V_269 ;
if ( V_272 < 0 ) {
return F_4 ( V_280 ) ;
}
V_2 -> V_4 . V_124 = V_272 ;
return 0 ;
case V_284 :
V_272 = ( long long ) V_2 -> V_4 . V_73 ;
V_272 += V_269 ;
if ( V_272 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_73 = V_272 ;
return 0 ;
case V_285 :
V_271 = V_2 -> V_4 . V_30 ;
V_271 += V_269 ;
if ( V_271 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_30 = V_271 ;
return 0 ;
case V_286 :
V_271 = V_2 -> V_4 . V_72 ;
V_271 += V_269 ;
if ( V_271 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_72 = V_271 ;
return 0 ;
case V_287 :
V_271 = V_2 -> V_4 . V_69 ;
V_271 += V_269 ;
if ( V_271 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_69 = V_271 ;
return 0 ;
case V_288 :
V_271 = V_2 -> V_4 . V_114 ;
V_271 += V_269 ;
if ( V_271 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_114 = V_271 ;
return 0 ;
case V_289 :
V_272 = ( long long ) V_2 -> V_4 . V_78 ;
V_272 += V_269 ;
if ( V_272 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_78 = V_272 ;
return 0 ;
case V_290 :
V_272 = ( long long ) V_2 -> V_4 . V_110 ;
V_272 += V_269 ;
if ( V_272 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_110 = V_272 ;
return 0 ;
case V_291 :
V_271 = V_2 -> V_4 . V_120 ;
V_271 += V_269 ;
if ( V_271 < 0 ) {
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
V_2 -> V_4 . V_120 = V_271 ;
return 0 ;
default:
ASSERT ( 0 ) ;
return F_4 ( V_10 ) ;
}
}
int
F_165 (
struct V_1 * V_2 ,
T_12 V_268 ,
T_19 V_269 ,
int V_270 )
{
int V_292 ;
#ifdef F_166
ASSERT ( V_268 < V_275 || V_268 > V_277 ) ;
#endif
F_27 ( & V_2 -> V_194 ) ;
V_292 = F_162 ( V_2 , V_268 , V_269 , V_270 ) ;
F_29 ( & V_2 -> V_194 ) ;
return V_292 ;
}
int
F_167 (
struct V_1 * V_2 ,
T_20 * V_293 ,
T_17 V_294 ,
int V_270 )
{
T_20 * V_295 ;
int error = 0 ;
F_27 ( & V_2 -> V_194 ) ;
for ( V_295 = V_293 ; V_295 < ( V_293 + V_294 ) ; V_295 ++ ) {
ASSERT ( V_295 -> V_296 < V_275 ||
V_295 -> V_296 > V_277 ) ;
error = F_162 ( V_2 , V_295 -> V_296 ,
V_295 -> V_297 , V_270 ) ;
if ( error )
goto V_298;
}
F_29 ( & V_2 -> V_194 ) ;
return 0 ;
V_298:
while ( -- V_295 >= V_293 ) {
error = F_162 ( V_2 , V_295 -> V_296 ,
- V_295 -> V_297 , V_270 ) ;
ASSERT ( error == 0 ) ;
}
F_29 ( & V_2 -> V_194 ) ;
return error ;
}
struct V_299 *
F_150 (
struct V_1 * V_2 ,
int V_42 )
{
struct V_299 * V_153 = V_2 -> V_154 ;
if ( ! F_168 ( V_153 ) ) {
if ( V_42 & V_300 )
return NULL ;
F_169 ( V_153 ) ;
}
F_170 ( V_153 ) ;
ASSERT ( F_171 ( V_153 ) ) ;
return V_153 ;
}
void
F_172 (
struct V_1 * V_2 )
{
struct V_299 * V_153 = V_2 -> V_154 ;
F_169 ( V_153 ) ;
V_2 -> V_154 = NULL ;
F_64 ( V_153 ) ;
}
int
F_121 (
T_3 * V_2 ,
T_10 V_139 )
{
T_18 * V_222 ;
int error ;
ASSERT ( V_139 & ( V_199 | V_200 | V_301 |
V_233 | V_234 |
V_237 ) ) ;
V_222 = F_92 ( V_2 , V_302 ) ;
error = F_93 ( V_222 , 0 , V_2 -> V_4 . V_51 + 128 , 0 , 0 ,
V_226 ) ;
if ( error ) {
F_94 ( V_222 , 0 ) ;
return error ;
}
F_96 ( V_222 , V_139 ) ;
error = F_97 ( V_222 , 0 ) ;
return error ;
}
int
F_173 (
struct V_1 * V_2 ,
char * V_303 )
{
if ( F_174 ( V_2 -> V_50 ) ||
F_174 ( V_2 -> V_49 ) ||
( V_2 -> V_304 && F_174 ( V_2 -> V_304 ) ) ) {
F_125 ( V_2 , L_50 , V_303 ) ;
F_125 ( V_2 , L_51 ) ;
return V_305 ;
}
return 0 ;
}
STATIC int
F_175 (
struct V_306 * V_307 ,
unsigned long V_308 ,
void * V_309 )
{
T_21 * V_310 ;
T_3 * V_2 ;
V_2 = ( T_3 * ) F_24 ( V_307 , T_3 , V_311 ) ;
V_310 = ( T_21 * )
F_176 ( V_2 -> V_312 , ( unsigned long ) V_309 ) ;
switch ( V_308 ) {
case V_313 :
case V_314 :
memset ( V_310 , 0 , sizeof( T_21 ) ) ;
break;
case V_315 :
case V_316 :
F_177 ( V_2 ) ;
F_178 ( V_2 , V_275 , 0 ) ;
F_178 ( V_2 , V_276 , 0 ) ;
F_178 ( V_2 , V_277 , 0 ) ;
F_179 ( V_2 ) ;
break;
case V_317 :
case V_318 :
F_177 ( V_2 ) ;
F_27 ( & V_2 -> V_194 ) ;
F_180 ( V_2 , V_275 ) ;
F_180 ( V_2 , V_276 ) ;
F_180 ( V_2 , V_277 ) ;
V_2 -> V_4 . V_121 += V_310 -> V_319 ;
V_2 -> V_4 . V_122 += V_310 -> V_320 ;
V_2 -> V_4 . V_123 += V_310 -> V_321 ;
memset ( V_310 , 0 , sizeof( T_21 ) ) ;
F_181 ( V_2 , V_275 , 0 ) ;
F_181 ( V_2 , V_276 , 0 ) ;
F_181 ( V_2 , V_277 , 0 ) ;
F_29 ( & V_2 -> V_194 ) ;
F_179 ( V_2 ) ;
break;
}
return V_322 ;
}
int
F_182 (
T_3 * V_2 )
{
T_21 * V_310 ;
int V_7 ;
V_2 -> V_312 = F_183 ( T_21 ) ;
if ( V_2 -> V_312 == NULL )
return - V_87 ;
#ifdef F_184
V_2 -> V_311 . V_323 = F_175 ;
V_2 -> V_311 . V_324 = 0 ;
F_185 ( & V_2 -> V_311 ) ;
#endif
F_186 (i) {
V_310 = ( T_21 * ) F_176 ( V_2 -> V_312 , V_7 ) ;
memset ( V_310 , 0 , sizeof( T_21 ) ) ;
}
F_42 ( & V_2 -> V_325 ) ;
V_2 -> V_326 = - 1 ;
return 0 ;
}
void
F_65 (
T_3 * V_2 )
{
F_177 ( V_2 ) ;
V_2 -> V_326 = - 1 ;
F_178 ( V_2 , V_275 , 0 ) ;
F_178 ( V_2 , V_276 , 0 ) ;
F_178 ( V_2 , V_277 , 0 ) ;
F_179 ( V_2 ) ;
}
void
F_187 (
T_3 * V_2 )
{
if ( V_2 -> V_312 ) {
F_188 ( & V_2 -> V_311 ) ;
F_189 ( V_2 -> V_312 ) ;
}
F_190 ( & V_2 -> V_325 ) ;
}
STATIC void
F_191 (
T_21 * V_327 )
{
while ( F_192 ( V_328 , & V_327 -> V_329 ) ) {
F_193 ( 1000 ) ;
}
}
STATIC void
F_194 (
T_21 * V_327 )
{
F_195 ( V_328 , & V_327 -> V_329 ) ;
}
STATIC void
F_196 (
T_3 * V_2 )
{
T_21 * V_310 ;
int V_7 ;
F_186 (i) {
V_310 = ( T_21 * ) F_176 ( V_2 -> V_312 , V_7 ) ;
F_191 ( V_310 ) ;
}
}
STATIC void
F_197 (
T_3 * V_2 )
{
T_21 * V_310 ;
int V_7 ;
F_186 (i) {
V_310 = ( T_21 * ) F_176 ( V_2 -> V_312 , V_7 ) ;
F_194 ( V_310 ) ;
}
}
STATIC void
F_198 (
T_3 * V_2 ,
T_21 * V_330 ,
int V_42 )
{
T_21 * V_310 ;
int V_7 ;
memset ( V_330 , 0 , sizeof( T_21 ) ) ;
if ( ! ( V_42 & V_331 ) )
F_196 ( V_2 ) ;
F_186 (i) {
V_310 = ( T_21 * ) F_176 ( V_2 -> V_312 , V_7 ) ;
V_330 -> V_319 += V_310 -> V_319 ;
V_330 -> V_320 += V_310 -> V_320 ;
V_330 -> V_321 += V_310 -> V_321 ;
}
if ( ! ( V_42 & V_331 ) )
F_197 ( V_2 ) ;
}
STATIC int
F_199 (
T_3 * V_2 ,
T_12 V_268 )
{
ASSERT ( ( V_268 >= V_275 ) && ( V_268 <= V_277 ) ) ;
return F_200 ( V_268 , & V_2 -> V_326 ) ;
}
STATIC void
F_180 (
T_3 * V_2 ,
T_12 V_268 )
{
T_21 V_330 ;
ASSERT ( ( V_268 >= V_275 ) && ( V_268 <= V_277 ) ) ;
if ( F_199 ( V_2 , V_268 ) )
return;
F_196 ( V_2 ) ;
if ( ! F_192 ( V_268 , & V_2 -> V_326 ) ) {
F_198 ( V_2 , & V_330 , V_331 ) ;
switch( V_268 ) {
case V_275 :
V_2 -> V_4 . V_121 = V_330 . V_319 ;
break;
case V_276 :
V_2 -> V_4 . V_122 = V_330 . V_320 ;
break;
case V_277 :
V_2 -> V_4 . V_123 = V_330 . V_321 ;
break;
default:
F_46 () ;
}
}
F_197 ( V_2 ) ;
}
STATIC void
F_201 (
T_3 * V_2 ,
T_12 V_268 ,
T_14 V_332 ,
T_14 V_333 )
{
T_21 * V_310 ;
int V_7 ;
ASSERT ( ( V_268 >= V_275 ) && ( V_268 <= V_277 ) ) ;
F_196 ( V_2 ) ;
F_186 (i) {
V_310 = F_176 ( V_2 -> V_312 , V_7 ) ;
switch ( V_268 ) {
case V_275 :
V_310 -> V_319 = V_332 + V_333 ;
break;
case V_276 :
V_310 -> V_320 = V_332 + V_333 ;
break;
case V_277 :
V_310 -> V_321 = V_332 + V_333 ;
break;
default:
F_46 () ;
break;
}
V_333 = 0 ;
}
F_195 ( V_268 , & V_2 -> V_326 ) ;
F_197 ( V_2 ) ;
}
void
F_202 (
T_3 * V_2 ,
int V_42 )
{
T_21 V_330 ;
F_198 ( V_2 , & V_330 , V_42 ) ;
if ( ! F_199 ( V_2 , V_275 ) )
V_2 -> V_4 . V_121 = V_330 . V_319 ;
if ( ! F_199 ( V_2 , V_276 ) )
V_2 -> V_4 . V_122 = V_330 . V_320 ;
if ( ! F_199 ( V_2 , V_277 ) )
V_2 -> V_4 . V_123 = V_330 . V_321 ;
}
void
F_147 (
T_3 * V_2 ,
int V_42 )
{
F_27 ( & V_2 -> V_194 ) ;
F_202 ( V_2 , V_42 ) ;
F_29 ( & V_2 -> V_194 ) ;
}
STATIC void
F_181 (
T_3 * V_2 ,
T_12 V_268 ,
int V_334 )
{
T_14 V_332 , V_333 ;
int V_335 = F_203 () ;
T_14 V_336 = ( T_14 ) V_334 ;
F_180 ( V_2 , V_268 ) ;
switch ( V_268 ) {
case V_275 :
V_332 = V_2 -> V_4 . V_121 ;
V_333 = F_50 ( V_332 , V_335 ) ;
if ( V_332 < F_204 ( V_336 , V_337 ) )
return;
break;
case V_276 :
V_332 = V_2 -> V_4 . V_122 ;
V_333 = F_50 ( V_332 , V_335 ) ;
if ( V_332 < F_204 ( V_336 , V_337 ) )
return;
break;
case V_277 :
V_332 = V_2 -> V_4 . V_123 ;
V_333 = F_50 ( V_332 , V_335 ) ;
if ( V_332 < F_204 ( V_336 , F_205 ( V_2 ) ) )
return;
break;
default:
F_46 () ;
V_332 = V_333 = 0 ;
break;
}
F_201 ( V_2 , V_268 , V_332 , V_333 ) ;
}
STATIC void
F_178 (
T_3 * V_2 ,
T_12 V_139 ,
int V_334 )
{
F_27 ( & V_2 -> V_194 ) ;
F_181 ( V_2 , V_139 , V_334 ) ;
F_29 ( & V_2 -> V_194 ) ;
}
int
F_206 (
T_3 * V_2 ,
T_12 V_268 ,
T_19 V_269 ,
int V_270 )
{
T_21 * V_327 ;
long long V_272 ;
int V_338 = 0 ;
F_207 () ;
V_339:
F_208 () ;
V_327 = F_209 ( V_2 -> V_312 ) ;
if ( F_34 ( F_199 ( V_2 , V_268 ) ) )
goto V_340;
F_191 ( V_327 ) ;
if ( F_34 ( F_199 ( V_2 , V_268 ) ) ) {
F_194 ( V_327 ) ;
goto V_340;
}
switch ( V_268 ) {
case V_275 :
V_272 = V_327 -> V_319 ;
V_272 += V_269 ;
if ( F_34 ( V_272 < 0 ) )
goto V_341;
V_327 -> V_319 = V_272 ;
break;
case V_276 :
V_272 = V_327 -> V_320 ;
V_272 += V_269 ;
if ( F_34 ( V_272 < 0 ) )
goto V_341;
V_327 -> V_320 = V_272 ;
break;
case V_277 :
F_210 ( ( V_2 -> V_278 - V_2 -> V_279 ) != 0 ) ;
V_272 = V_327 -> V_321 - F_163 ( V_2 ) ;
V_272 += V_269 ;
if ( F_34 ( V_272 < 0 ) )
goto V_341;
V_327 -> V_321 = V_272 + F_163 ( V_2 ) ;
break;
default:
F_46 () ;
break;
}
F_194 ( V_327 ) ;
F_211 () ;
return 0 ;
V_340:
F_211 () ;
F_177 ( V_2 ) ;
if ( ! ( F_199 ( V_2 , V_268 ) ) ) {
F_179 ( V_2 ) ;
goto V_339;
}
F_27 ( & V_2 -> V_194 ) ;
V_338 = F_162 ( V_2 , V_268 , V_269 , V_270 ) ;
F_29 ( & V_2 -> V_194 ) ;
if ( V_338 != V_280 )
F_178 ( V_2 , V_268 , 0 ) ;
F_179 ( V_2 ) ;
return V_338 ;
V_341:
F_194 ( V_327 ) ;
F_211 () ;
F_177 ( V_2 ) ;
F_178 ( V_2 , V_268 , V_269 ) ;
F_179 ( V_2 ) ;
goto V_339;
}
