T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return F_2 ( V_5 , V_6 ,
V_7 , V_3 ) ;
}
T_1 F_3 ( struct V_1 * V_2 , T_3 * V_8 )
{
F_4 ( V_9 , V_10 ) ;
F_4 ( V_11 , V_12 ) ;
T_1 V_13 ;
int V_14 ;
if ( ! V_2 -> V_4 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ ) {
if ( V_5 [ V_13 ] . V_15 )
continue;
V_8 [ V_13 ] = * ( unsigned int * ) ( ( char * ) V_2 -> V_4 +
V_5 [ V_13 ] . V_16 ) ;
}
F_5 ( V_9 , V_17 , V_18 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
V_14 = F_6 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_14 ) {
F_7 ( V_2 , V_21 , V_2 -> V_22 ,
L_1 , V_14 ) ;
memset ( V_11 , 0 , sizeof( V_11 ) ) ;
}
F_8 ( V_5 , V_6 ,
V_7 ,
V_8 , F_9 ( V_11 , 0 ) , false ) ;
return V_6 ;
}
static void F_10 ( T_4 V_23 , T_5 * V_24 , T_5 * V_25 )
{
struct V_26 V_27 = F_11 ( V_23 ) ;
* V_24 = V_27 . V_28 ;
* V_25 = V_27 . V_29 ;
}
static T_6 F_12 ( T_5 V_24 , T_5 V_25 ,
T_7 V_30 )
{
T_6 V_31 = F_13 ( V_24 , V_25 ) ;
if ( V_30 >= 0 )
V_31 = F_14 ( V_31 , ( T_3 ) V_30 ) ;
else
V_31 = F_15 ( V_31 , ( T_3 ) - V_30 ) ;
return V_31 ;
}
static void F_16 ( T_4 V_23 , T_5 * V_24 , T_5 * V_25 )
{
struct V_26 V_27 = F_11 ( V_23 ) ;
T_5 V_32 = V_27 . V_28 ;
T_5 V_33 = ( T_5 ) ( ( ( T_3 ) V_27 . V_29 * V_34 +
( 1ULL << ( V_35 - 1 ) ) ) >> V_35 ) ;
if ( V_33 >= V_36 ) {
V_33 -= V_36 ;
V_32 ++ ;
}
* V_24 = V_32 ;
* V_25 = V_33 ;
}
static inline T_6 F_17 ( T_5 V_24 , T_5 V_25 )
{
T_5 V_23 = ( T_5 ) ( ( ( T_3 ) V_25 * V_37 +
( 1ULL << ( V_38 - 1 ) ) ) >> V_38 ) ;
return F_13 ( V_24 , V_23 ) ;
}
static T_6 F_18 ( T_5 V_24 , T_5 V_25 ,
T_7 V_30 )
{
V_25 += V_30 ;
if ( ( T_7 ) V_25 < 0 ) {
V_25 += V_36 ;
V_24 -- ;
} else if ( V_25 >= V_36 ) {
V_25 -= V_36 ;
V_24 ++ ;
}
return F_17 ( V_24 , V_25 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_4 ( V_9 , V_39 ) ;
F_4 ( V_11 , V_40 ) ;
struct V_41 * V_42 = V_2 -> V_4 ;
int V_14 ;
T_5 V_43 ;
T_1 V_44 ;
F_5 ( V_9 , V_17 , V_45 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
V_14 = F_6 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , & V_44 ) ;
if ( V_14 == 0 )
V_43 = F_20 ( V_11 , V_46 ) ;
else if ( V_14 == - V_47 )
V_43 = V_48 ;
else
return V_14 ;
if ( V_43 == V_49 ) {
V_42 -> V_50 = F_16 ;
V_42 -> V_51 = F_18 ;
} else if ( V_43 == V_48 ) {
V_42 -> V_50 = F_10 ;
V_42 -> V_51 = F_12 ;
} else {
return - V_52 ;
}
V_42 -> V_53 = V_43 ;
if ( V_14 == 0 && V_44 >= V_40 )
V_42 -> V_54 =
F_20 ( V_11 ,
V_55 ) ;
else
V_42 -> V_54 = V_56 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_4 ( V_9 , V_57 ) ;
F_4 ( V_11 , V_58 ) ;
int V_14 ;
F_5 ( V_9 , V_17 ,
V_59 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
V_14 = F_6 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_14 == 0 ) {
V_2 -> V_4 -> V_60 . V_61 = F_20 ( V_11 ,
V_62 ) ;
V_2 -> V_4 -> V_60 . V_63 = F_20 ( V_11 ,
V_64 ) ;
V_2 -> V_4 -> V_60 . V_65 = F_20 ( V_11 ,
V_66 ) ;
V_2 -> V_4 -> V_60 . V_67 = F_20 ( V_11 ,
V_68 ) ;
} else if ( V_14 == - V_47 ) {
V_2 -> V_4 -> V_60 . V_61 = 0 ;
V_2 -> V_4 -> V_60 . V_63 = 0 ;
V_2 -> V_4 -> V_60 . V_65 = 0 ;
V_2 -> V_4 -> V_60 . V_67 = 0 ;
} else {
return V_14 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_4 ( V_9 , V_69 ) ;
F_23 ( V_11 , 0 ) ;
int V_14 ;
F_5 ( V_9 , V_17 , V_70 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
F_5 ( V_9 , V_71 ,
V_2 -> V_4 -> V_72 ?
V_2 -> V_4 -> V_72 -> V_72 : 0 ) ;
F_5 ( V_9 , V_73 , V_2 -> V_4 -> V_74 ) ;
V_14 = F_24 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
V_14 = ( V_14 == - V_75 ) ? 0 : V_14 ;
if ( V_14 )
F_25 ( V_2 , V_20 ,
V_69 ,
V_11 , sizeof( V_11 ) , V_14 ) ;
return V_14 ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_4 ( V_9 , V_76 ) ;
F_23 ( V_11 , 0 ) ;
int V_14 ;
F_5 ( V_9 , V_17 , V_77 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
V_14 = F_24 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
V_14 = ( V_14 == - V_75 ) ? 0 : V_14 ;
if ( V_14 )
F_25 ( V_2 , V_20 ,
V_76 ,
V_11 , sizeof( V_11 ) , V_14 ) ;
return V_14 ;
}
static void F_27 ( struct V_78 * V_79 )
{
struct V_80 * V_81 ;
while ( ( V_81 = F_28 ( V_79 ) ) ) {
F_29 () ;
F_30 ( V_81 ) ;
F_31 () ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_82 , V_2 -> V_22 ,
L_2
L_3 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_83 V_85 ;
struct V_26 V_86 ;
struct V_41 * V_42 = V_2 -> V_4 ;
struct V_26 V_87 ;
int * V_88 = V_42 -> V_87 . V_89 ;
F_34 ( & V_85 ) ;
V_87 = V_85 . V_90 ;
V_86 = V_85 . V_90 ;
F_35 ( & V_86 , V_91 ) ;
while ( ( F_36 ( & V_85 . V_90 , & V_86 ) < 0 ) &&
F_37 ( * V_88 ) ) {
struct V_26 V_92 ;
unsigned int V_93 ;
V_92 = V_85 . V_90 ;
F_35 ( & V_92 , V_94 ) ;
do {
F_34 ( & V_85 ) ;
} while ( ( F_36 ( & V_85 . V_90 , & V_92 ) < 0 ) &&
F_37 ( * V_88 ) );
V_93 = ( V_85 . V_90 . V_28 << V_95 |
V_85 . V_90 . V_29 ) ;
V_2 -> type -> V_96 ( V_2 , V_93 ) ;
}
* V_84 = V_85 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_97 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
F_4 ( V_98 , V_99 ) ;
T_1 V_100 ;
int V_14 ;
unsigned long V_101 ;
struct V_83 V_84 = {} ;
unsigned int V_102 = 0 ;
int * V_87 = V_42 -> V_87 . V_89 ;
F_5 ( V_98 , V_17 , V_103 ) ;
F_5 ( V_98 , V_19 , 0 ) ;
F_5 ( V_98 , V_104 ,
V_97 ) ;
F_39 ( V_98 , V_105 ,
V_42 -> V_87 . V_106 ) ;
F_37 ( * V_87 ) = 0 ;
V_14 = F_40 ( V_2 , V_20 , V_98 ,
V_107 ) ;
F_41 ( V_14 ) ;
V_101 = V_108 + F_42 ( V_109 ) ;
while ( ! F_37 ( * V_87 ) && ( F_43 ( V_108 , V_101 ) ) ) {
F_44 ( 20 ) ;
V_102 ++ ;
}
if ( V_102 <= 1 )
++ V_42 -> V_110 ;
if ( ! F_43 ( V_108 , V_101 ) )
++ V_42 -> V_111 ;
if ( F_37 ( * V_87 ) )
F_33 ( V_2 , & V_84 ) ;
V_14 = F_45 ( V_2 , V_20 ,
V_107 ,
V_98 , sizeof( V_98 ) ,
& V_100 ) ;
if ( V_14 == 0 ) {
V_14 = F_46 ( V_2 , V_98 , V_100 ,
& V_84 ) ;
if ( V_14 == 0 )
++ V_42 -> V_112 ;
else
++ V_42 -> V_113 ;
}
if ( V_14 != 0 )
++ V_42 -> V_114 ;
return V_14 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_41 * V_4 = V_2 -> V_4 ;
struct V_115 V_116 ;
int V_14 = - V_117 ;
F_4 ( V_118 , V_119 ) ;
T_1 V_120 ;
F_5 ( V_4 -> V_121 , V_17 , V_122 ) ;
F_5 ( V_4 -> V_121 , V_19 , 0 ) ;
F_5 ( V_4 -> V_121 , V_123 , V_81 -> V_120 ) ;
if ( F_48 ( V_81 ) -> V_124 != 0 ) {
V_14 = F_49 ( V_81 ) ;
if ( V_14 != 0 )
goto V_125;
}
if ( V_81 -> V_126 == V_127 ) {
V_14 = F_50 ( V_81 ) ;
if ( V_14 != 0 )
goto V_125;
}
F_51 ( V_81 ,
F_52 ( V_4 -> V_121 ,
V_128 ) ,
V_81 -> V_120 ) ;
V_14 = F_6 ( V_2 , V_20 ,
V_4 -> V_121 , F_53 ( V_81 -> V_120 ) ,
V_118 , sizeof( V_118 ) , & V_120 ) ;
if ( V_14 != 0 )
goto V_125;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_129 = V_4 -> V_51 (
F_20 ( V_118 , V_130 ) ,
F_20 ( V_118 , V_131 ) ,
V_4 -> V_60 . V_61 ) ;
F_54 ( V_81 , & V_116 ) ;
V_14 = 0 ;
V_125:
F_55 ( V_81 ) ;
return V_14 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
struct V_132 * V_133 ;
struct V_132 * V_134 ;
if ( V_42 -> V_135 )
return;
F_57 ( & V_42 -> V_136 ) ;
if ( ! F_58 ( & V_42 -> V_137 ) ) {
F_59 (cursor, next, &ptp->evt_list) {
struct V_138 * V_139 ;
V_139 = F_60 ( V_133 , struct V_138 ,
V_140 ) ;
if ( F_61 ( V_108 , V_139 -> V_141 ) ) {
F_62 ( & V_139 -> V_140 , & V_42 -> V_142 ) ;
F_63 ( V_2 , V_21 , V_2 -> V_22 ,
L_4 ) ;
}
}
}
F_64 ( & V_42 -> V_136 ) ;
}
static enum V_143 F_65 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
bool V_144 ;
struct V_132 * V_133 ;
struct V_132 * V_134 ;
struct V_145 * V_146 ;
enum V_143 V_14 = V_147 ;
F_66 ( V_42 -> V_135 ) ;
F_57 ( & V_42 -> V_136 ) ;
V_144 = ! F_58 ( & V_42 -> V_137 ) ;
F_64 ( & V_42 -> V_136 ) ;
if ( ! V_144 )
return V_147 ;
V_146 = (struct V_145 * ) V_81 -> V_148 ;
F_57 ( & V_42 -> V_136 ) ;
F_59 (cursor, next, &ptp->evt_list) {
struct V_138 * V_139 ;
V_139 = F_60 ( V_133 , struct V_138 , V_140 ) ;
if ( ( V_139 -> V_149 == V_146 -> V_150 [ 0 ] ) &&
( V_139 -> V_151 == V_146 -> V_150 [ 1 ] ) ) {
struct V_115 * V_116 ;
V_116 = F_67 ( V_81 ) ;
V_116 -> V_129 = V_139 -> V_152 ;
V_146 -> V_153 = V_154 ;
V_14 = V_154 ;
F_62 ( & V_139 -> V_140 , & V_42 -> V_142 ) ;
break;
}
}
F_64 ( & V_42 -> V_136 ) ;
return V_14 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
struct V_80 * V_81 ;
while ( ( V_81 = F_28 ( & V_42 -> V_155 ) ) ) {
struct V_145 * V_146 ;
V_146 = (struct V_145 * ) V_81 -> V_148 ;
if ( V_146 -> V_153 == V_156 ) {
F_69 ( V_79 , V_81 ) ;
} else if ( F_65 ( V_2 , V_81 ) ==
V_154 ) {
F_69 ( V_79 , V_81 ) ;
} else if ( F_61 ( V_108 , V_146 -> V_141 ) ) {
V_146 -> V_153 = V_157 ;
++ V_42 -> V_158 ;
F_69 ( V_79 , V_81 ) ;
} else {
F_70 ( & V_42 -> V_155 , V_81 ) ;
break;
}
}
}
static inline void F_71 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
F_29 () ;
F_30 ( V_81 ) ;
F_31 () ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
if ( V_42 -> V_159 ) {
F_73 ( V_2 , V_160 ,
V_42 -> V_161 ) ;
F_73 ( V_2 , V_160 ,
V_42 -> V_162 ) ;
V_42 -> V_159 = false ;
}
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
struct V_163 V_164 ;
int V_14 ;
if ( ! V_42 -> V_72 || V_42 -> V_159 )
return 0 ;
F_75 ( & V_164 , V_160 , 0 ,
F_76 (
F_77 ( V_42 -> V_72 ) ) ) ;
V_14 = F_78 ( & V_164 , V_165 ,
F_79 ( V_166 ) ,
F_80 ( V_167 ) ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_81 ( V_2 , & V_164 , true ) ;
if ( V_14 < 0 )
return V_14 ;
V_42 -> V_162 = V_14 ;
F_75 ( & V_164 , V_160 , 0 ,
F_76 (
F_77 ( V_42 -> V_72 ) ) ) ;
V_14 = F_78 ( & V_164 , V_165 ,
F_79 ( V_166 ) ,
F_80 ( V_168 ) ) ;
if ( V_14 != 0 )
goto V_125;
V_14 = F_81 ( V_2 , & V_164 , true ) ;
if ( V_14 < 0 )
goto V_125;
V_42 -> V_161 = V_14 ;
V_42 -> V_159 = true ;
return 0 ;
V_125:
F_73 ( V_2 , V_160 ,
V_42 -> V_162 ) ;
return V_14 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
int V_14 ;
V_42 -> V_169 = false ;
V_14 = F_74 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_22 ( V_2 ) ;
if ( V_14 != 0 )
goto V_125;
V_42 -> V_170 = 0 ;
V_42 -> V_171 = 0 ;
return 0 ;
V_125:
F_72 ( V_2 ) ;
return V_14 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
struct V_132 * V_133 ;
struct V_132 * V_134 ;
int V_14 ;
if ( V_42 == NULL )
return 0 ;
V_14 = F_26 ( V_2 ) ;
F_72 ( V_2 ) ;
F_27 ( & V_2 -> V_4 -> V_155 ) ;
F_84 ( & V_2 -> V_4 -> V_172 ) ;
F_57 ( & V_2 -> V_4 -> V_136 ) ;
F_59 (cursor, next, &efx->ptp_data->evt_list) {
F_62 ( V_133 , & V_2 -> V_4 -> V_142 ) ;
}
F_64 ( & V_2 -> V_4 -> V_136 ) ;
return V_14 ;
}
static int F_85 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 && V_2 -> V_4 -> V_173 )
return F_82 ( V_2 ) ;
return 0 ;
}
static void F_86 ( struct V_174 * V_175 )
{
struct V_41 * V_42 =
F_87 ( V_175 , struct V_41 , V_176 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_177 V_178 ;
if ( F_38 ( V_2 , V_179 ) )
return;
V_178 . type = V_180 ;
V_178 . V_181 = V_42 -> V_182 ;
V_177 ( V_42 -> V_183 , & V_178 ) ;
}
static void F_88 ( struct V_174 * V_175 )
{
struct V_41 * V_4 =
F_87 ( V_175 , struct V_41 , V_175 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_80 * V_81 ;
struct V_78 V_184 ;
if ( V_4 -> V_169 ) {
F_83 ( V_2 ) ;
F_82 ( V_2 ) ;
return;
}
F_56 ( V_2 ) ;
F_89 ( & V_184 ) ;
F_68 ( V_2 , & V_184 ) ;
while ( ( V_81 = F_28 ( & V_4 -> V_172 ) ) )
F_47 ( V_2 , V_81 ) ;
while ( ( V_81 = F_90 ( & V_184 ) ) )
F_71 ( V_2 , V_81 ) ;
}
int F_91 ( struct V_1 * V_2 , struct V_185 * V_72 )
{
struct V_41 * V_42 ;
int V_14 = 0 ;
unsigned int V_186 ;
V_42 = F_92 ( sizeof( struct V_41 ) , V_187 ) ;
V_2 -> V_4 = V_42 ;
if ( ! V_2 -> V_4 )
return - V_188 ;
V_42 -> V_2 = V_2 ;
V_42 -> V_72 = V_72 ;
V_42 -> V_135 = F_93 ( V_2 ) >= V_189 ;
V_14 = F_94 ( V_2 , & V_42 -> V_87 , sizeof( int ) , V_187 ) ;
if ( V_14 != 0 )
goto V_190;
F_95 ( & V_42 -> V_155 ) ;
F_95 ( & V_42 -> V_172 ) ;
V_42 -> V_191 = F_96 ( L_5 ) ;
if ( ! V_42 -> V_191 ) {
V_14 = - V_188 ;
goto V_192;
}
F_97 ( & V_42 -> V_175 , F_88 ) ;
V_42 -> V_193 . V_194 = 0 ;
V_42 -> V_193 . V_195 = V_196 ;
V_42 -> V_193 . V_197 = V_198 ;
F_98 ( & V_42 -> V_137 ) ;
F_98 ( & V_42 -> V_142 ) ;
F_99 ( & V_42 -> V_136 ) ;
for ( V_186 = 0 ; V_186 < V_199 ; V_186 ++ )
F_100 ( & V_42 -> V_200 [ V_186 ] . V_140 , & V_42 -> V_142 ) ;
V_14 = F_19 ( V_2 ) ;
if ( V_14 < 0 )
goto V_201;
V_14 = F_21 ( V_2 ) ;
if ( V_14 < 0 )
goto V_201;
if ( V_2 -> V_202 -> V_203 &
( 1 << V_204 ) ) {
V_42 -> V_205 = V_206 ;
V_42 -> V_183 = F_101 ( & V_42 -> V_205 ,
& V_2 -> V_207 -> V_208 ) ;
if ( F_102 ( V_42 -> V_183 ) ) {
V_14 = F_103 ( V_42 -> V_183 ) ;
goto V_201;
}
F_97 ( & V_42 -> V_176 , F_86 ) ;
V_42 -> V_209 = F_96 ( L_6 ) ;
if ( ! V_42 -> V_209 ) {
V_14 = - V_188 ;
goto V_210;
}
}
V_42 -> V_211 = false ;
return 0 ;
V_210:
F_104 ( V_2 -> V_4 -> V_183 ) ;
V_201:
F_105 ( V_2 -> V_4 -> V_191 ) ;
V_192:
F_106 ( V_2 , & V_42 -> V_87 ) ;
V_190:
F_107 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
return V_14 ;
}
static int F_108 ( struct V_185 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
V_72 -> V_212 = 0 ;
V_72 -> V_213 . V_214 = 0 ;
return F_91 ( V_2 , V_72 ) ;
}
void F_109 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return;
( void ) F_26 ( V_2 ) ;
F_110 ( & V_2 -> V_4 -> V_175 ) ;
F_110 ( & V_2 -> V_4 -> V_176 ) ;
F_84 ( & V_2 -> V_4 -> V_155 ) ;
F_84 ( & V_2 -> V_4 -> V_172 ) ;
if ( V_2 -> V_4 -> V_183 ) {
F_105 ( V_2 -> V_4 -> V_209 ) ;
F_104 ( V_2 -> V_4 -> V_183 ) ;
}
F_105 ( V_2 -> V_4 -> V_191 ) ;
F_106 ( V_2 , & V_2 -> V_4 -> V_87 ) ;
F_107 ( V_2 -> V_4 ) ;
}
static void F_111 ( struct V_185 * V_72 )
{
F_109 ( V_72 -> V_2 ) ;
}
static void F_112 ( struct V_185 * V_72 ,
char * V_215 , T_1 V_120 )
{
snprintf ( V_215 , V_120 , L_7 , V_72 -> V_2 -> V_216 ) ;
}
bool F_113 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
return V_2 -> V_4 &&
V_2 -> V_4 -> V_173 &&
V_81 -> V_120 >= V_217 &&
V_81 -> V_120 <= V_218 &&
F_114 ( V_81 -> V_219 == F_80 ( V_220 ) ) &&
F_115 ( V_81 ) &&
F_116 ( V_81 ) >= sizeof( struct V_221 ) &&
F_117 ( V_81 ) -> V_219 == V_165 &&
F_118 ( V_81 ) >=
F_119 ( V_81 ) + sizeof( struct V_222 ) &&
F_120 ( V_81 ) -> V_223 == F_80 ( V_167 ) ;
}
static bool F_121 ( struct V_185 * V_72 , struct V_80 * V_81 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_41 * V_42 = V_2 -> V_4 ;
struct V_145 * V_146 = (struct V_145 * ) V_81 -> V_148 ;
T_2 * V_224 , * V_225 ;
unsigned int V_226 ;
T_2 * V_227 ;
V_146 -> V_141 = V_108 + F_42 ( V_228 ) ;
if ( V_42 -> V_74 == V_229 ) {
if ( ! F_122 ( V_81 , V_230 ) ) {
return false ;
}
V_227 = V_81 -> V_227 ;
V_226 = F_123 ( * ( V_231 * ) & V_227 [ V_232 ] ) ;
if ( V_226 != V_233 ) {
return false ;
}
V_224 = V_227 + V_234 ;
V_225 = V_227 + V_234 + 3 ;
} else {
if ( ! F_122 ( V_81 , V_235 ) ) {
return false ;
}
V_227 = V_81 -> V_227 ;
V_226 = V_227 [ V_236 ] ;
if ( ( V_226 & V_237 ) != V_238 ) {
return false ;
}
V_225 = V_227 + V_239 + 5 ;
if ( V_42 -> V_74 == V_240 ) {
V_224 = V_227 + V_239 + 2 ;
} else {
V_224 = V_227 + V_239 + 0 ;
F_124 ( V_42 -> V_74 != V_241 ) ;
}
}
if ( F_123 ( * ( V_231 * ) & V_227 [ V_242 ] ) == V_167 ) {
V_146 -> V_153 = V_147 ;
F_125 ( V_243 != V_244 ) ;
F_125 ( V_245 != V_246 ) ;
V_146 -> V_150 [ 0 ] = ( V_224 [ 0 ] |
( V_224 [ 1 ] << 8 ) |
( V_224 [ 2 ] << 16 ) |
( V_225 [ 0 ] << 24 ) ) ;
V_146 -> V_150 [ 1 ] = ( V_225 [ 1 ] |
( V_225 [ 2 ] << 8 ) |
( V_227 [ V_243 +
V_245 - 1 ] <<
16 ) ) ;
} else {
V_146 -> V_153 = V_156 ;
}
F_126 ( & V_42 -> V_155 , V_81 ) ;
F_127 ( V_42 -> V_191 , & V_42 -> V_175 ) ;
return true ;
}
int F_128 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
F_126 ( & V_42 -> V_172 , V_81 ) ;
if ( ( F_120 ( V_81 ) -> V_223 == F_80 ( V_167 ) ) &&
( V_81 -> V_120 <= V_218 ) )
F_129 ( V_81 ) ;
F_127 ( V_42 -> V_191 , & V_42 -> V_175 ) ;
return V_247 ;
}
int F_130 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_74 ;
}
int F_131 ( struct V_1 * V_2 , bool V_248 ,
unsigned int V_249 )
{
if ( ( V_248 != V_2 -> V_4 -> V_173 ) ||
( V_248 && ( V_2 -> V_4 -> V_74 != V_249 ) ) ) {
int V_14 = 0 ;
if ( V_248 ) {
if ( V_2 -> V_4 -> V_173 &&
( V_2 -> V_4 -> V_74 != V_249 ) ) {
V_2 -> V_4 -> V_173 = false ;
V_14 = F_83 ( V_2 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_2 -> V_4 -> V_74 = V_249 ;
if ( F_132 ( V_2 -> V_22 ) )
V_14 = F_82 ( V_2 ) ;
if ( V_14 == 0 ) {
V_14 = F_38 ( V_2 ,
V_179 * 2 ) ;
if ( V_14 != 0 )
F_83 ( V_2 ) ;
}
} else {
V_14 = F_83 ( V_2 ) ;
}
if ( V_14 != 0 )
return V_14 ;
V_2 -> V_4 -> V_173 = V_248 ;
}
return 0 ;
}
static int F_133 ( struct V_1 * V_2 , struct V_250 * V_251 )
{
int V_14 ;
if ( V_251 -> V_194 )
return - V_47 ;
if ( ( V_251 -> V_195 != V_196 ) &&
( V_251 -> V_195 != V_252 ) )
return - V_52 ;
V_14 = V_2 -> type -> V_253 ( V_2 , V_251 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_4 -> V_193 = * V_251 ;
return 0 ;
}
void F_134 ( struct V_1 * V_2 , struct V_254 * V_255 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
struct V_1 * V_256 = V_2 -> V_256 ;
F_135 () ;
if ( ! V_42 )
return;
V_255 -> V_257 |= ( V_258 |
V_259 |
V_260 ) ;
if ( V_256 && V_256 -> V_4 && V_256 -> V_4 -> V_183 )
V_255 -> V_261 =
F_136 ( V_256 -> V_4 -> V_183 ) ;
V_255 -> V_262 = 1 << V_196 | 1 << V_252 ;
V_255 -> V_263 = V_42 -> V_2 -> type -> V_264 ;
}
int F_137 ( struct V_1 * V_2 , struct V_265 * V_266 )
{
struct V_250 V_193 ;
int V_14 ;
if ( ! V_2 -> V_4 )
return - V_267 ;
if ( F_138 ( & V_193 , V_266 -> V_268 , sizeof( V_193 ) ) )
return - V_269 ;
V_14 = F_133 ( V_2 , & V_193 ) ;
if ( V_14 != 0 )
return V_14 ;
return F_139 ( V_266 -> V_268 , & V_193 , sizeof( V_193 ) )
? - V_269 : 0 ;
}
int F_140 ( struct V_1 * V_2 , struct V_265 * V_266 )
{
if ( ! V_2 -> V_4 )
return - V_267 ;
return F_139 ( V_266 -> V_268 , & V_2 -> V_4 -> V_193 ,
sizeof( V_2 -> V_4 -> V_193 ) ) ? - V_269 : 0 ;
}
static void F_141 ( struct V_1 * V_2 , int V_270 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
F_7 ( V_2 , V_21 , V_2 -> V_22 ,
L_8 ,
V_42 -> V_170 , V_270 ) ;
V_42 -> V_169 = true ;
F_127 ( V_42 -> V_191 , & V_42 -> V_175 ) ;
}
static void F_142 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_138 * V_139 = NULL ;
if ( F_66 ( V_42 -> V_135 ) )
return;
if ( V_42 -> V_170 != 3 ) {
F_141 ( V_2 , 3 ) ;
return;
}
F_57 ( & V_42 -> V_136 ) ;
if ( ! F_58 ( & V_42 -> V_142 ) ) {
V_139 = F_143 ( & V_42 -> V_142 ,
struct V_138 , V_140 ) ;
F_144 ( & V_139 -> V_140 ) ;
V_139 -> V_149 = F_145 ( V_42 -> V_271 [ 2 ] , V_272 ) ;
V_139 -> V_151 = ( F_145 ( V_42 -> V_271 [ 2 ] ,
V_273 ) |
( F_145 ( V_42 -> V_271 [ 1 ] ,
V_273 ) << 8 ) |
( F_145 ( V_42 -> V_271 [ 0 ] ,
V_273 ) << 16 ) ) ;
V_139 -> V_152 = V_2 -> V_4 -> V_51 (
F_145 ( V_42 -> V_271 [ 0 ] , V_272 ) ,
F_145 ( V_42 -> V_271 [ 1 ] , V_272 ) ,
V_42 -> V_60 . V_63 ) ;
V_139 -> V_141 = V_108 + F_42 ( V_228 ) ;
F_146 ( & V_139 -> V_140 , & V_42 -> V_137 ) ;
F_127 ( V_42 -> V_191 , & V_42 -> V_175 ) ;
} else if ( F_147 () ) {
F_7 ( V_2 , V_274 , V_2 -> V_22 , L_9 ) ;
}
F_64 ( & V_42 -> V_136 ) ;
}
static void F_148 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
int V_275 = F_145 ( V_42 -> V_271 [ 0 ] , V_272 ) ;
if ( V_42 -> V_170 != 1 ) {
F_141 ( V_2 , 1 ) ;
return;
}
F_7 ( V_2 , V_21 , V_2 -> V_22 , L_10 , V_275 ) ;
}
static void F_149 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
if ( V_42 -> V_211 )
F_127 ( V_42 -> V_209 , & V_42 -> V_176 ) ;
}
void F_150 ( struct V_1 * V_2 , T_8 * V_276 )
{
struct V_41 * V_42 = V_2 -> V_4 ;
int V_275 = F_145 ( * V_276 , V_277 ) ;
if ( ! V_42 ) {
if ( F_147 () )
F_63 ( V_2 , V_82 , V_2 -> V_22 ,
L_11 ) ;
return;
}
if ( ! V_42 -> V_173 )
return;
if ( V_42 -> V_170 == 0 ) {
V_42 -> V_278 = V_275 ;
} else if ( V_42 -> V_278 != V_275 ) {
F_7 ( V_2 , V_21 , V_2 -> V_22 ,
L_12 , V_275 ) ;
V_42 -> V_170 = 0 ;
}
V_42 -> V_271 [ V_42 -> V_170 ++ ] = * V_276 ;
if ( ! F_151 ( * V_276 , V_279 ) ) {
switch ( V_275 ) {
case V_280 :
F_142 ( V_2 , V_42 ) ;
break;
case V_281 :
F_148 ( V_2 , V_42 ) ;
break;
case V_282 :
F_149 ( V_2 , V_42 ) ;
break;
default:
F_7 ( V_2 , V_21 , V_2 -> V_22 ,
L_13 , V_275 ) ;
break;
}
V_42 -> V_170 = 0 ;
} else if ( V_283 == V_42 -> V_170 ) {
F_7 ( V_2 , V_21 , V_2 -> V_22 ,
L_14 ) ;
V_42 -> V_170 = 0 ;
}
}
void F_152 ( struct V_185 * V_72 , T_8 * V_276 )
{
V_72 -> V_284 = F_151 ( * V_276 , V_285 ) ;
V_72 -> V_286 =
F_151 ( * V_276 , V_287 ) << 19 ;
( void ) F_153 ( & V_72 -> V_288 , V_289 ,
V_290 ) ;
}
static inline T_5 F_154 ( struct V_1 * V_2 , const T_2 * V_291 )
{
#if F_155 ( V_292 )
return F_156 ( ( const V_293 * ) ( V_291 + V_2 -> V_294 ) ) ;
#else
const T_2 * V_227 = V_291 + V_2 -> V_294 ;
return ( T_5 ) V_227 [ 0 ] |
( T_5 ) V_227 [ 1 ] << 8 |
( T_5 ) V_227 [ 2 ] << 16 |
( T_5 ) V_227 [ 3 ] << 24 ;
#endif
}
void F_157 ( struct V_185 * V_72 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
T_5 V_295 , V_296 ;
T_5 V_297 , V_298 ;
struct V_115 * V_116 ;
V_296 = ( F_154 ( V_2 ,
F_158 ( V_81 ) ) +
( T_5 ) V_2 -> V_4 -> V_60 . V_63 ) &
( V_299 - 1 ) ;
V_297 = ( V_296 - V_72 -> V_286 ) &
( V_299 - 1 ) ;
V_298 = V_72 -> V_286 + V_297 > V_299 ?
1 : 0 ;
if ( V_297 <= V_299 / V_300 +
V_301 ) {
V_295 = V_72 -> V_284 + V_298 ;
} else if ( V_297 >= V_299 - V_301 ) {
V_295 = V_72 -> V_284 - 1 + V_298 ;
} else {
F_159 ( V_2 , V_82 , V_2 -> V_22 ,
L_15 ,
V_296 , V_72 -> V_284 ,
V_72 -> V_286 ) ;
return;
}
V_116 = F_67 ( V_81 ) ;
V_116 -> V_129 =
F_17 ( V_295 , V_296 ) ;
}
static int F_160 ( struct V_302 * V_42 , T_7 V_303 )
{
struct V_41 * V_4 = F_87 ( V_42 ,
struct V_41 ,
V_205 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_4 ( V_304 , V_305 ) ;
T_4 V_306 ;
int V_14 ;
if ( V_303 > V_307 )
V_303 = V_307 ;
else if ( V_303 < - V_307 )
V_303 = - V_307 ;
V_306 = ( ( ( T_4 ) V_303 * V_308 ) >>
( V_309 + V_310 ) ) ;
F_5 ( V_304 , V_17 , V_311 ) ;
F_5 ( V_304 , V_19 , 0 ) ;
F_39 ( V_304 , V_312 , V_306 ) ;
F_5 ( V_304 , V_313 , 0 ) ;
F_5 ( V_304 , V_314 , 0 ) ;
V_14 = F_6 ( V_2 , V_20 , V_304 , sizeof( V_304 ) ,
NULL , 0 , NULL ) ;
if ( V_14 != 0 )
return V_14 ;
V_4 -> V_171 = V_306 ;
return 0 ;
}
static int F_161 ( struct V_302 * V_42 , T_4 V_303 )
{
T_5 V_24 , V_25 ;
struct V_41 * V_4 = F_87 ( V_42 ,
struct V_41 ,
V_205 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_4 ( V_9 , V_305 ) ;
V_2 -> V_4 -> V_50 ( V_303 , & V_24 , & V_25 ) ;
F_5 ( V_9 , V_17 , V_311 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
F_39 ( V_9 , V_312 , V_4 -> V_171 ) ;
F_5 ( V_9 , V_315 , V_24 ) ;
F_5 ( V_9 , V_316 , V_25 ) ;
return F_6 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
NULL , 0 , NULL ) ;
}
static int F_162 ( struct V_302 * V_42 , struct V_317 * V_27 )
{
struct V_41 * V_4 = F_87 ( V_42 ,
struct V_41 ,
V_205 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_4 ( V_9 , V_318 ) ;
F_4 ( V_11 , V_319 ) ;
int V_14 ;
T_6 V_31 ;
F_5 ( V_9 , V_17 , V_320 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
V_14 = F_6 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_14 != 0 )
return V_14 ;
V_31 = V_4 -> V_51 (
F_20 ( V_11 , V_321 ) ,
F_20 ( V_11 , V_322 ) , 0 ) ;
* V_27 = F_163 ( V_31 ) ;
return 0 ;
}
static int F_164 ( struct V_302 * V_42 ,
const struct V_317 * V_323 )
{
int V_14 ;
struct V_317 V_324 ;
struct V_317 V_303 ;
V_14 = F_162 ( V_42 , & V_324 ) ;
if ( V_14 != 0 )
return V_14 ;
V_303 = F_165 ( * V_323 , V_324 ) ;
V_14 = F_161 ( V_42 , F_166 ( & V_303 ) ) ;
if ( V_14 != 0 )
return V_14 ;
return 0 ;
}
static int F_167 ( struct V_302 * V_42 ,
struct V_325 * V_326 ,
int V_327 )
{
struct V_41 * V_4 = F_87 ( V_42 ,
struct V_41 ,
V_205 ) ;
if ( V_326 -> type != V_328 )
return - V_267 ;
V_4 -> V_211 = ! ! V_327 ;
return 0 ;
}
void F_168 ( struct V_1 * V_2 )
{
if ( F_26 ( V_2 ) == 0 )
V_2 -> V_329 [ V_330 ] =
& V_331 ;
}
void F_169 ( struct V_1 * V_2 )
{
if ( F_85 ( V_2 ) )
F_7 ( V_2 , V_82 , V_2 -> V_22 , L_16 ) ;
if ( V_2 -> type -> V_332 )
V_2 -> type -> V_332 ( V_2 , true , true ) ;
}
void F_170 ( struct V_1 * V_2 )
{
if ( V_2 -> type -> V_332 )
V_2 -> type -> V_332 ( V_2 , false , true ) ;
F_83 ( V_2 ) ;
}
