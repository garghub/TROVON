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
if ( V_14 )
memset ( V_11 , 0 , sizeof( V_11 ) ) ;
F_7 ( V_5 , V_6 ,
V_7 ,
V_8 , F_8 ( V_11 , 0 ) , false ) ;
return V_6 ;
}
static void F_9 ( T_4 V_21 , T_5 * V_22 , T_5 * V_23 )
{
struct V_24 V_25 = F_10 ( V_21 ) ;
* V_22 = ( T_5 ) V_25 . V_26 ;
* V_23 = V_25 . V_27 ;
}
static T_6 F_11 ( T_5 V_22 , T_5 V_23 ,
T_7 V_28 )
{
T_6 V_29 = F_12 ( V_22 , V_23 ) ;
if ( V_28 >= 0 )
V_29 = F_13 ( V_29 , ( T_3 ) V_28 ) ;
else
V_29 = F_14 ( V_29 , ( T_3 ) - V_28 ) ;
return V_29 ;
}
static void F_15 ( T_4 V_21 , T_5 * V_22 , T_5 * V_23 )
{
struct V_24 V_25 = F_10 ( V_21 ) ;
T_5 V_30 = ( T_5 ) V_25 . V_26 ;
T_5 V_31 = ( T_5 ) ( ( ( T_3 ) V_25 . V_27 * V_32 +
( 1ULL << ( V_33 - 1 ) ) ) >> V_33 ) ;
if ( V_31 >= V_34 ) {
V_31 -= V_34 ;
V_30 ++ ;
}
* V_22 = V_30 ;
* V_23 = V_31 ;
}
static inline T_6 F_16 ( T_5 V_22 , T_5 V_23 )
{
T_5 V_21 = ( T_5 ) ( ( ( T_3 ) V_23 * V_35 +
( 1ULL << ( V_36 - 1 ) ) ) >> V_36 ) ;
return F_12 ( V_22 , V_21 ) ;
}
static T_6 F_17 ( T_5 V_22 , T_5 V_23 ,
T_7 V_28 )
{
V_23 += V_28 ;
if ( ( T_7 ) V_23 < 0 ) {
V_23 += V_34 ;
V_22 -- ;
} else if ( V_23 >= V_34 ) {
V_23 -= V_34 ;
V_22 ++ ;
}
return F_16 ( V_22 , V_23 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_4 ( V_9 , V_37 ) ;
F_4 ( V_11 , V_38 ) ;
struct V_39 * V_40 = V_2 -> V_4 ;
int V_14 ;
T_5 V_41 ;
T_1 V_42 ;
F_5 ( V_9 , V_17 , V_43 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
V_14 = F_19 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , & V_42 ) ;
if ( V_14 == 0 ) {
V_41 = F_20 ( V_11 , V_44 ) ;
} else if ( V_14 == - V_45 ) {
V_41 = V_46 ;
} else if ( V_14 == - V_47 ) {
F_21 ( V_2 , V_48 , V_2 -> V_49 , L_1 ) ;
return V_14 ;
} else {
F_22 ( V_2 , V_20 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , V_14 ) ;
return V_14 ;
}
if ( V_41 == V_50 ) {
V_40 -> V_51 = F_15 ;
V_40 -> V_52 = F_17 ;
} else if ( V_41 == V_46 ) {
V_40 -> V_51 = F_9 ;
V_40 -> V_52 = F_11 ;
} else {
return - V_53 ;
}
V_40 -> V_54 = V_41 ;
if ( V_14 == 0 && V_42 >= V_38 )
V_40 -> V_55 =
F_20 ( V_11 ,
V_56 ) ;
else
V_40 -> V_55 = V_57 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_4 ( V_9 , V_58 ) ;
F_4 ( V_11 , V_59 ) ;
int V_14 ;
F_5 ( V_9 , V_17 ,
V_60 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
V_14 = F_19 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_14 == 0 ) {
V_2 -> V_4 -> V_61 . V_62 = F_20 ( V_11 ,
V_63 ) ;
V_2 -> V_4 -> V_61 . V_64 = F_20 ( V_11 ,
V_65 ) ;
V_2 -> V_4 -> V_61 . V_66 = F_20 ( V_11 ,
V_67 ) ;
V_2 -> V_4 -> V_61 . V_68 = F_20 ( V_11 ,
V_69 ) ;
} else if ( V_14 == - V_45 ) {
V_2 -> V_4 -> V_61 . V_62 = 0 ;
V_2 -> V_4 -> V_61 . V_64 = 0 ;
V_2 -> V_4 -> V_61 . V_66 = 0 ;
V_2 -> V_4 -> V_61 . V_68 = 0 ;
} else {
F_22 ( V_2 , V_20 , sizeof( V_9 ) , V_11 ,
sizeof( V_11 ) , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_4 ( V_9 , V_70 ) ;
F_25 ( V_11 ) ;
int V_14 ;
F_5 ( V_9 , V_17 , V_71 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
F_5 ( V_9 , V_72 ,
V_2 -> V_4 -> V_73 ?
V_2 -> V_4 -> V_73 -> V_73 : 0 ) ;
F_5 ( V_9 , V_74 , V_2 -> V_4 -> V_75 ) ;
V_14 = F_19 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
V_14 = ( V_14 == - V_76 ) ? 0 : V_14 ;
if ( V_14 )
F_22 ( V_2 , V_20 ,
V_70 ,
V_11 , sizeof( V_11 ) , V_14 ) ;
return V_14 ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_4 ( V_9 , V_77 ) ;
F_25 ( V_11 ) ;
int V_14 ;
F_5 ( V_9 , V_17 , V_78 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
V_14 = F_19 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
V_14 = ( V_14 == - V_76 ) ? 0 : V_14 ;
if ( V_14 == - V_79 || V_14 == - V_47 )
F_21 ( V_2 , V_48 , V_2 -> V_49 , L_1 ) ;
else if ( V_14 )
F_22 ( V_2 , V_20 ,
V_77 ,
V_11 , sizeof( V_11 ) , V_14 ) ;
return V_14 ;
}
static void F_27 ( struct V_80 * V_81 )
{
struct V_82 * V_83 ;
while ( ( V_83 = F_28 ( V_81 ) ) ) {
F_29 () ;
F_30 ( V_83 ) ;
F_31 () ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_84 , V_2 -> V_49 ,
L_2
L_3 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
struct V_85 V_87 ;
struct V_24 V_88 ;
struct V_39 * V_40 = V_2 -> V_4 ;
struct V_24 V_89 ;
int * V_90 = V_40 -> V_89 . V_91 ;
F_35 ( & V_87 ) ;
V_89 = V_87 . V_92 ;
V_88 = V_87 . V_92 ;
F_36 ( & V_88 , V_93 ) ;
while ( ( F_37 ( & V_87 . V_92 , & V_88 ) < 0 ) &&
F_38 ( * V_90 ) ) {
struct V_24 V_94 ;
unsigned int V_95 ;
V_94 = V_87 . V_92 ;
F_36 ( & V_94 , V_96 ) ;
do {
F_35 ( & V_87 ) ;
} while ( ( F_37 ( & V_87 . V_92 , & V_94 ) < 0 ) &&
F_38 ( * V_90 ) );
V_95 = ( V_87 . V_92 . V_26 << V_97 |
V_87 . V_92 . V_27 ) ;
V_2 -> type -> V_98 ( V_2 , V_95 ) ;
}
* V_86 = V_87 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_99 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
F_4 ( V_100 , V_101 ) ;
T_1 V_102 ;
int V_14 ;
unsigned long V_103 ;
struct V_85 V_86 = {} ;
unsigned int V_104 = 0 ;
int * V_89 = V_40 -> V_89 . V_91 ;
F_5 ( V_100 , V_17 , V_105 ) ;
F_5 ( V_100 , V_19 , 0 ) ;
F_5 ( V_100 , V_106 ,
V_99 ) ;
F_40 ( V_100 , V_107 ,
V_40 -> V_89 . V_108 ) ;
F_38 ( * V_89 ) = 0 ;
V_14 = F_41 ( V_2 , V_20 , V_100 ,
V_109 ) ;
F_42 ( V_14 ) ;
V_103 = V_110 + F_43 ( V_111 ) ;
while ( ! F_38 ( * V_89 ) && ( F_44 ( V_110 , V_103 ) ) ) {
F_45 ( 20 ) ;
V_104 ++ ;
}
if ( V_104 <= 1 )
++ V_40 -> V_112 ;
if ( ! F_44 ( V_110 , V_103 ) )
++ V_40 -> V_113 ;
if ( F_38 ( * V_89 ) )
F_34 ( V_2 , & V_86 ) ;
V_14 = F_46 ( V_2 , V_20 ,
V_109 ,
V_100 , sizeof( V_100 ) ,
& V_102 ) ;
if ( V_14 == 0 ) {
V_14 = F_47 ( V_2 , V_100 , V_102 ,
& V_86 ) ;
if ( V_14 == 0 )
++ V_40 -> V_114 ;
else
++ V_40 -> V_115 ;
}
if ( V_14 != 0 )
++ V_40 -> V_116 ;
return V_14 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_39 * V_4 = V_2 -> V_4 ;
struct V_117 V_118 ;
int V_14 = - V_119 ;
F_4 ( V_120 , V_121 ) ;
T_1 V_122 ;
F_5 ( V_4 -> V_123 , V_17 , V_124 ) ;
F_5 ( V_4 -> V_123 , V_19 , 0 ) ;
F_5 ( V_4 -> V_123 , V_125 , V_83 -> V_122 ) ;
if ( F_49 ( V_83 ) -> V_126 != 0 ) {
V_14 = F_50 ( V_83 ) ;
if ( V_14 != 0 )
goto V_127;
}
if ( V_83 -> V_128 == V_129 ) {
V_14 = F_51 ( V_83 ) ;
if ( V_14 != 0 )
goto V_127;
}
F_52 ( V_83 ,
F_53 ( V_4 -> V_123 ,
V_130 ) ,
V_83 -> V_122 ) ;
V_14 = F_6 ( V_2 , V_20 ,
V_4 -> V_123 , F_54 ( V_83 -> V_122 ) ,
V_120 , sizeof( V_120 ) , & V_122 ) ;
if ( V_14 != 0 )
goto V_127;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_131 = V_4 -> V_52 (
F_20 ( V_120 , V_132 ) ,
F_20 ( V_120 , V_133 ) ,
V_4 -> V_61 . V_62 ) ;
F_55 ( V_83 , & V_118 ) ;
V_14 = 0 ;
V_127:
F_56 ( V_83 ) ;
return V_14 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
struct V_134 * V_135 ;
struct V_134 * V_136 ;
if ( V_40 -> V_137 )
return;
F_58 ( & V_40 -> V_138 ) ;
if ( ! F_59 ( & V_40 -> V_139 ) ) {
F_60 (cursor, next, &ptp->evt_list) {
struct V_140 * V_141 ;
V_141 = F_61 ( V_135 , struct V_140 ,
V_142 ) ;
if ( F_62 ( V_110 , V_141 -> V_143 ) ) {
F_63 ( & V_141 -> V_142 , & V_40 -> V_144 ) ;
F_64 ( V_2 , V_145 , V_2 -> V_49 ,
L_4 ) ;
}
}
}
F_65 ( & V_40 -> V_138 ) ;
}
static enum V_146 F_66 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
bool V_147 ;
struct V_134 * V_135 ;
struct V_134 * V_136 ;
struct V_148 * V_149 ;
enum V_146 V_14 = V_150 ;
F_67 ( V_40 -> V_137 ) ;
F_58 ( & V_40 -> V_138 ) ;
V_147 = ! F_59 ( & V_40 -> V_139 ) ;
F_65 ( & V_40 -> V_138 ) ;
if ( ! V_147 )
return V_150 ;
V_149 = (struct V_148 * ) V_83 -> V_151 ;
F_58 ( & V_40 -> V_138 ) ;
F_60 (cursor, next, &ptp->evt_list) {
struct V_140 * V_141 ;
V_141 = F_61 ( V_135 , struct V_140 , V_142 ) ;
if ( ( V_141 -> V_152 == V_149 -> V_153 [ 0 ] ) &&
( V_141 -> V_154 == V_149 -> V_153 [ 1 ] ) ) {
struct V_117 * V_118 ;
V_118 = F_68 ( V_83 ) ;
V_118 -> V_131 = V_141 -> V_155 ;
V_149 -> V_156 = V_157 ;
V_14 = V_157 ;
F_63 ( & V_141 -> V_142 , & V_40 -> V_144 ) ;
break;
}
}
F_65 ( & V_40 -> V_138 ) ;
return V_14 ;
}
static void F_69 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
struct V_82 * V_83 ;
while ( ( V_83 = F_28 ( & V_40 -> V_158 ) ) ) {
struct V_148 * V_149 ;
V_149 = (struct V_148 * ) V_83 -> V_151 ;
if ( V_149 -> V_156 == V_159 ) {
F_70 ( V_81 , V_83 ) ;
} else if ( F_66 ( V_2 , V_83 ) ==
V_157 ) {
F_70 ( V_81 , V_83 ) ;
} else if ( F_62 ( V_110 , V_149 -> V_143 ) ) {
V_149 -> V_156 = V_160 ;
++ V_40 -> V_161 ;
F_70 ( V_81 , V_83 ) ;
} else {
F_71 ( & V_40 -> V_158 , V_83 ) ;
break;
}
}
}
static inline void F_72 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
F_29 () ;
F_30 ( V_83 ) ;
F_31 () ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
if ( V_40 -> V_162 ) {
F_74 ( V_2 , V_163 ,
V_40 -> V_164 ) ;
F_74 ( V_2 , V_163 ,
V_40 -> V_165 ) ;
V_40 -> V_162 = false ;
}
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
struct V_166 V_167 ;
int V_14 ;
if ( ! V_40 -> V_73 || V_40 -> V_162 )
return 0 ;
F_76 ( & V_167 , V_163 , 0 ,
F_77 (
F_78 ( V_40 -> V_73 ) ) ) ;
V_14 = F_79 ( & V_167 , V_168 ,
F_80 ( V_169 ) ,
F_81 ( V_170 ) ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_82 ( V_2 , & V_167 , true ) ;
if ( V_14 < 0 )
return V_14 ;
V_40 -> V_165 = V_14 ;
F_76 ( & V_167 , V_163 , 0 ,
F_77 (
F_78 ( V_40 -> V_73 ) ) ) ;
V_14 = F_79 ( & V_167 , V_168 ,
F_80 ( V_169 ) ,
F_81 ( V_171 ) ) ;
if ( V_14 != 0 )
goto V_127;
V_14 = F_82 ( V_2 , & V_167 , true ) ;
if ( V_14 < 0 )
goto V_127;
V_40 -> V_164 = V_14 ;
V_40 -> V_162 = true ;
return 0 ;
V_127:
F_74 ( V_2 , V_163 ,
V_40 -> V_165 ) ;
return V_14 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
int V_14 ;
V_40 -> V_172 = false ;
V_14 = F_75 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_24 ( V_2 ) ;
if ( V_14 != 0 )
goto V_127;
V_40 -> V_173 = 0 ;
V_40 -> V_174 = 0 ;
return 0 ;
V_127:
F_73 ( V_2 ) ;
return V_14 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
struct V_134 * V_135 ;
struct V_134 * V_136 ;
int V_14 ;
if ( V_40 == NULL )
return 0 ;
V_14 = F_26 ( V_2 ) ;
F_73 ( V_2 ) ;
F_27 ( & V_2 -> V_4 -> V_158 ) ;
F_85 ( & V_2 -> V_4 -> V_175 ) ;
F_58 ( & V_2 -> V_4 -> V_138 ) ;
F_60 (cursor, next, &efx->ptp_data->evt_list) {
F_63 ( V_135 , & V_2 -> V_4 -> V_144 ) ;
}
F_65 ( & V_2 -> V_4 -> V_138 ) ;
return V_14 ;
}
static int F_86 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 && V_2 -> V_4 -> V_176 )
return F_83 ( V_2 ) ;
return 0 ;
}
static void F_87 ( struct V_177 * V_178 )
{
struct V_39 * V_40 =
F_88 ( V_178 , struct V_39 , V_179 ) ;
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_180 V_181 ;
if ( F_39 ( V_2 , V_182 ) )
return;
V_181 . type = V_183 ;
V_181 . V_184 = V_40 -> V_185 ;
V_180 ( V_40 -> V_186 , & V_181 ) ;
}
static void F_89 ( struct V_177 * V_178 )
{
struct V_39 * V_4 =
F_88 ( V_178 , struct V_39 , V_178 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_82 * V_83 ;
struct V_80 V_187 ;
if ( V_4 -> V_172 ) {
F_84 ( V_2 ) ;
F_83 ( V_2 ) ;
return;
}
F_57 ( V_2 ) ;
F_90 ( & V_187 ) ;
F_69 ( V_2 , & V_187 ) ;
while ( ( V_83 = F_28 ( & V_4 -> V_175 ) ) )
F_48 ( V_2 , V_83 ) ;
while ( ( V_83 = F_91 ( & V_187 ) ) )
F_72 ( V_2 , V_83 ) ;
}
int F_92 ( struct V_1 * V_2 , struct V_188 * V_73 )
{
struct V_39 * V_40 ;
int V_14 = 0 ;
unsigned int V_189 ;
V_40 = F_93 ( sizeof( struct V_39 ) , V_190 ) ;
V_2 -> V_4 = V_40 ;
if ( ! V_2 -> V_4 )
return - V_191 ;
V_40 -> V_2 = V_2 ;
V_40 -> V_73 = V_73 ;
V_40 -> V_137 = F_94 ( V_2 ) >= V_192 ;
V_14 = F_95 ( V_2 , & V_40 -> V_89 , sizeof( int ) , V_190 ) ;
if ( V_14 != 0 )
goto V_193;
F_96 ( & V_40 -> V_158 ) ;
F_96 ( & V_40 -> V_175 ) ;
V_40 -> V_194 = F_97 ( L_5 ) ;
if ( ! V_40 -> V_194 ) {
V_14 = - V_191 ;
goto V_195;
}
F_98 ( & V_40 -> V_178 , F_89 ) ;
V_40 -> V_196 . V_197 = 0 ;
V_40 -> V_196 . V_198 = V_199 ;
V_40 -> V_196 . V_200 = V_201 ;
F_99 ( & V_40 -> V_139 ) ;
F_99 ( & V_40 -> V_144 ) ;
F_100 ( & V_40 -> V_138 ) ;
for ( V_189 = 0 ; V_189 < V_202 ; V_189 ++ )
F_101 ( & V_40 -> V_203 [ V_189 ] . V_142 , & V_40 -> V_144 ) ;
V_14 = F_18 ( V_2 ) ;
if ( V_14 < 0 )
goto V_204;
V_14 = F_23 ( V_2 ) ;
if ( V_14 < 0 )
goto V_204;
if ( V_2 -> V_205 -> V_206 &
( 1 << V_207 ) ) {
V_40 -> V_208 = V_209 ;
V_40 -> V_186 = F_102 ( & V_40 -> V_208 ,
& V_2 -> V_210 -> V_211 ) ;
if ( F_103 ( V_40 -> V_186 ) ) {
V_14 = F_104 ( V_40 -> V_186 ) ;
goto V_204;
}
F_98 ( & V_40 -> V_179 , F_87 ) ;
V_40 -> V_212 = F_97 ( L_6 ) ;
if ( ! V_40 -> V_212 ) {
V_14 = - V_191 ;
goto V_213;
}
}
V_40 -> V_214 = false ;
return 0 ;
V_213:
F_105 ( V_2 -> V_4 -> V_186 ) ;
V_204:
F_106 ( V_2 -> V_4 -> V_194 ) ;
V_195:
F_107 ( V_2 , & V_40 -> V_89 ) ;
V_193:
F_108 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
return V_14 ;
}
static int F_109 ( struct V_188 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
V_73 -> V_215 = 0 ;
V_73 -> V_216 . V_217 = 0 ;
return F_92 ( V_2 , V_73 ) ;
}
void F_110 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return;
( void ) F_26 ( V_2 ) ;
F_111 ( & V_2 -> V_4 -> V_178 ) ;
F_111 ( & V_2 -> V_4 -> V_179 ) ;
F_85 ( & V_2 -> V_4 -> V_158 ) ;
F_85 ( & V_2 -> V_4 -> V_175 ) ;
if ( V_2 -> V_4 -> V_186 ) {
F_106 ( V_2 -> V_4 -> V_212 ) ;
F_105 ( V_2 -> V_4 -> V_186 ) ;
}
F_106 ( V_2 -> V_4 -> V_194 ) ;
F_107 ( V_2 , & V_2 -> V_4 -> V_89 ) ;
F_108 ( V_2 -> V_4 ) ;
}
static void F_112 ( struct V_188 * V_73 )
{
F_110 ( V_73 -> V_2 ) ;
}
static void F_113 ( struct V_188 * V_73 ,
char * V_218 , T_1 V_122 )
{
snprintf ( V_218 , V_122 , L_7 , V_73 -> V_2 -> V_219 ) ;
}
bool F_114 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
return V_2 -> V_4 &&
V_2 -> V_4 -> V_176 &&
V_83 -> V_122 >= V_220 &&
V_83 -> V_122 <= V_221 &&
F_115 ( V_83 -> V_222 == F_81 ( V_223 ) ) &&
F_116 ( V_83 ) &&
F_117 ( V_83 ) >= sizeof( struct V_224 ) &&
F_118 ( V_83 ) -> V_222 == V_168 &&
F_119 ( V_83 ) >=
F_120 ( V_83 ) + sizeof( struct V_225 ) &&
F_121 ( V_83 ) -> V_226 == F_81 ( V_170 ) ;
}
static bool F_122 ( struct V_188 * V_73 , struct V_82 * V_83 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_39 * V_40 = V_2 -> V_4 ;
struct V_148 * V_149 = (struct V_148 * ) V_83 -> V_151 ;
T_2 * V_227 , * V_228 ;
unsigned int V_229 ;
T_2 * V_230 ;
V_149 -> V_143 = V_110 + F_43 ( V_231 ) ;
if ( V_40 -> V_75 == V_232 ) {
if ( ! F_123 ( V_83 , V_233 ) ) {
return false ;
}
V_230 = V_83 -> V_230 ;
V_229 = F_124 ( * ( V_234 * ) & V_230 [ V_235 ] ) ;
if ( V_229 != V_236 ) {
return false ;
}
V_227 = V_230 + V_237 ;
V_228 = V_230 + V_237 + 3 ;
} else {
if ( ! F_123 ( V_83 , V_238 ) ) {
return false ;
}
V_230 = V_83 -> V_230 ;
V_229 = V_230 [ V_239 ] ;
if ( ( V_229 & V_240 ) != V_241 ) {
return false ;
}
V_228 = V_230 + V_242 + 5 ;
if ( V_40 -> V_75 == V_243 ) {
V_227 = V_230 + V_242 + 2 ;
} else {
V_227 = V_230 + V_242 + 0 ;
F_125 ( V_40 -> V_75 != V_244 ) ;
}
}
if ( F_124 ( * ( V_234 * ) & V_230 [ V_245 ] ) == V_170 ) {
V_149 -> V_156 = V_150 ;
F_126 ( V_246 != V_247 ) ;
F_126 ( V_248 != V_249 ) ;
V_149 -> V_153 [ 0 ] = ( V_227 [ 0 ] |
( V_227 [ 1 ] << 8 ) |
( V_227 [ 2 ] << 16 ) |
( V_228 [ 0 ] << 24 ) ) ;
V_149 -> V_153 [ 1 ] = ( V_228 [ 1 ] |
( V_228 [ 2 ] << 8 ) |
( V_230 [ V_246 +
V_248 - 1 ] <<
16 ) ) ;
} else {
V_149 -> V_156 = V_159 ;
}
F_127 ( & V_40 -> V_158 , V_83 ) ;
F_128 ( V_40 -> V_194 , & V_40 -> V_178 ) ;
return true ;
}
int F_129 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
F_127 ( & V_40 -> V_175 , V_83 ) ;
if ( ( F_121 ( V_83 ) -> V_226 == F_81 ( V_170 ) ) &&
( V_83 -> V_122 <= V_221 ) )
F_130 ( V_83 ) ;
F_128 ( V_40 -> V_194 , & V_40 -> V_178 ) ;
return V_250 ;
}
int F_131 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_75 ;
}
int F_132 ( struct V_1 * V_2 , bool V_251 ,
unsigned int V_252 )
{
if ( ( V_251 != V_2 -> V_4 -> V_176 ) ||
( V_251 && ( V_2 -> V_4 -> V_75 != V_252 ) ) ) {
int V_14 = 0 ;
if ( V_251 ) {
if ( V_2 -> V_4 -> V_176 &&
( V_2 -> V_4 -> V_75 != V_252 ) ) {
V_2 -> V_4 -> V_176 = false ;
V_14 = F_84 ( V_2 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_2 -> V_4 -> V_75 = V_252 ;
if ( F_133 ( V_2 -> V_49 ) )
V_14 = F_83 ( V_2 ) ;
if ( V_14 == 0 ) {
V_14 = F_39 ( V_2 ,
V_182 * 2 ) ;
if ( V_14 != 0 )
F_84 ( V_2 ) ;
}
} else {
V_14 = F_84 ( V_2 ) ;
}
if ( V_14 != 0 )
return V_14 ;
V_2 -> V_4 -> V_176 = V_251 ;
}
return 0 ;
}
static int F_134 ( struct V_1 * V_2 , struct V_253 * V_254 )
{
int V_14 ;
if ( V_254 -> V_197 )
return - V_45 ;
if ( ( V_254 -> V_198 != V_199 ) &&
( V_254 -> V_198 != V_255 ) )
return - V_53 ;
V_14 = V_2 -> type -> V_256 ( V_2 , V_254 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_4 -> V_196 = * V_254 ;
return 0 ;
}
void F_135 ( struct V_1 * V_2 , struct V_257 * V_258 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
struct V_1 * V_259 = V_2 -> V_259 ;
F_136 () ;
if ( ! V_40 )
return;
V_258 -> V_260 |= ( V_261 |
V_262 |
V_263 ) ;
if ( V_259 && V_259 -> V_4 && V_259 -> V_4 -> V_186 )
V_258 -> V_264 =
F_137 ( V_259 -> V_4 -> V_186 ) ;
V_258 -> V_265 = 1 << V_199 | 1 << V_255 ;
V_258 -> V_266 = V_40 -> V_2 -> type -> V_267 ;
}
int F_138 ( struct V_1 * V_2 , struct V_268 * V_269 )
{
struct V_253 V_196 ;
int V_14 ;
if ( ! V_2 -> V_4 )
return - V_270 ;
if ( F_139 ( & V_196 , V_269 -> V_271 , sizeof( V_196 ) ) )
return - V_272 ;
V_14 = F_134 ( V_2 , & V_196 ) ;
if ( V_14 != 0 )
return V_14 ;
return F_140 ( V_269 -> V_271 , & V_196 , sizeof( V_196 ) )
? - V_272 : 0 ;
}
int F_141 ( struct V_1 * V_2 , struct V_268 * V_269 )
{
if ( ! V_2 -> V_4 )
return - V_270 ;
return F_140 ( V_269 -> V_271 , & V_2 -> V_4 -> V_196 ,
sizeof( V_2 -> V_4 -> V_196 ) ) ? - V_272 : 0 ;
}
static void F_142 ( struct V_1 * V_2 , int V_273 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
F_33 ( V_2 , V_145 , V_2 -> V_49 ,
L_8 ,
V_40 -> V_173 , V_273 ) ;
V_40 -> V_172 = true ;
F_128 ( V_40 -> V_194 , & V_40 -> V_178 ) ;
}
static void F_143 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_140 * V_141 = NULL ;
if ( F_67 ( V_40 -> V_137 ) )
return;
if ( V_40 -> V_173 != 3 ) {
F_142 ( V_2 , 3 ) ;
return;
}
F_58 ( & V_40 -> V_138 ) ;
if ( ! F_59 ( & V_40 -> V_144 ) ) {
V_141 = F_144 ( & V_40 -> V_144 ,
struct V_140 , V_142 ) ;
F_145 ( & V_141 -> V_142 ) ;
V_141 -> V_152 = F_146 ( V_40 -> V_274 [ 2 ] , V_275 ) ;
V_141 -> V_154 = ( F_146 ( V_40 -> V_274 [ 2 ] ,
V_276 ) |
( F_146 ( V_40 -> V_274 [ 1 ] ,
V_276 ) << 8 ) |
( F_146 ( V_40 -> V_274 [ 0 ] ,
V_276 ) << 16 ) ) ;
V_141 -> V_155 = V_2 -> V_4 -> V_52 (
F_146 ( V_40 -> V_274 [ 0 ] , V_275 ) ,
F_146 ( V_40 -> V_274 [ 1 ] , V_275 ) ,
V_40 -> V_61 . V_64 ) ;
V_141 -> V_143 = V_110 + F_43 ( V_231 ) ;
F_147 ( & V_141 -> V_142 , & V_40 -> V_139 ) ;
F_128 ( V_40 -> V_194 , & V_40 -> V_178 ) ;
} else if ( F_148 () ) {
F_33 ( V_2 , V_277 , V_2 -> V_49 , L_9 ) ;
}
F_65 ( & V_40 -> V_138 ) ;
}
static void F_149 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
int V_278 = F_146 ( V_40 -> V_274 [ 0 ] , V_275 ) ;
if ( V_40 -> V_173 != 1 ) {
F_142 ( V_2 , 1 ) ;
return;
}
F_33 ( V_2 , V_145 , V_2 -> V_49 , L_10 , V_278 ) ;
}
static void F_150 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
if ( V_40 -> V_214 )
F_128 ( V_40 -> V_212 , & V_40 -> V_179 ) ;
}
void F_151 ( struct V_1 * V_2 , T_8 * V_279 )
{
struct V_39 * V_40 = V_2 -> V_4 ;
int V_278 = F_146 ( * V_279 , V_280 ) ;
if ( ! V_40 ) {
if ( F_148 () )
F_64 ( V_2 , V_84 , V_2 -> V_49 ,
L_11 ) ;
return;
}
if ( ! V_40 -> V_176 )
return;
if ( V_40 -> V_173 == 0 ) {
V_40 -> V_281 = V_278 ;
} else if ( V_40 -> V_281 != V_278 ) {
F_33 ( V_2 , V_145 , V_2 -> V_49 ,
L_12 , V_278 ) ;
V_40 -> V_173 = 0 ;
}
V_40 -> V_274 [ V_40 -> V_173 ++ ] = * V_279 ;
if ( ! F_152 ( * V_279 , V_282 ) ) {
switch ( V_278 ) {
case V_283 :
F_143 ( V_2 , V_40 ) ;
break;
case V_284 :
F_149 ( V_2 , V_40 ) ;
break;
case V_285 :
F_150 ( V_2 , V_40 ) ;
break;
default:
F_33 ( V_2 , V_145 , V_2 -> V_49 ,
L_13 , V_278 ) ;
break;
}
V_40 -> V_173 = 0 ;
} else if ( V_286 == V_40 -> V_173 ) {
F_33 ( V_2 , V_145 , V_2 -> V_49 ,
L_14 ) ;
V_40 -> V_173 = 0 ;
}
}
void F_153 ( struct V_188 * V_73 , T_8 * V_279 )
{
V_73 -> V_287 = F_152 ( * V_279 , V_288 ) ;
V_73 -> V_289 =
F_152 ( * V_279 , V_290 ) << 19 ;
( void ) F_154 ( & V_73 -> V_291 , V_292 ,
V_293 ) ;
}
static inline T_5 F_155 ( struct V_1 * V_2 , const T_2 * V_294 )
{
#if F_156 ( V_295 )
return F_157 ( ( const V_296 * ) ( V_294 + V_2 -> V_297 ) ) ;
#else
const T_2 * V_230 = V_294 + V_2 -> V_297 ;
return ( T_5 ) V_230 [ 0 ] |
( T_5 ) V_230 [ 1 ] << 8 |
( T_5 ) V_230 [ 2 ] << 16 |
( T_5 ) V_230 [ 3 ] << 24 ;
#endif
}
void F_158 ( struct V_188 * V_73 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
T_5 V_298 , V_299 ;
T_5 V_300 , V_301 ;
struct V_117 * V_118 ;
V_299 = ( F_155 ( V_2 ,
F_159 ( V_83 ) ) +
( T_5 ) V_2 -> V_4 -> V_61 . V_64 ) &
( V_302 - 1 ) ;
V_300 = ( V_299 - V_73 -> V_289 ) &
( V_302 - 1 ) ;
V_301 = V_73 -> V_289 + V_300 > V_302 ?
1 : 0 ;
if ( V_300 <= V_302 / V_303 +
V_304 ) {
V_298 = V_73 -> V_287 + V_301 ;
} else if ( V_300 >= V_302 - V_304 ) {
V_298 = V_73 -> V_287 - 1 + V_301 ;
} else {
F_160 ( V_2 , V_84 , V_2 -> V_49 ,
L_15 ,
V_299 , V_73 -> V_287 ,
V_73 -> V_289 ) ;
return;
}
V_118 = F_68 ( V_83 ) ;
V_118 -> V_131 =
F_16 ( V_298 , V_299 ) ;
}
static int F_161 ( struct V_305 * V_40 , T_7 V_306 )
{
struct V_39 * V_4 = F_88 ( V_40 ,
struct V_39 ,
V_208 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_4 ( V_307 , V_308 ) ;
T_4 V_309 ;
int V_14 ;
if ( V_306 > V_310 )
V_306 = V_310 ;
else if ( V_306 < - V_310 )
V_306 = - V_310 ;
V_309 = ( ( ( T_4 ) V_306 * V_311 ) >>
( V_312 + V_313 ) ) ;
F_5 ( V_307 , V_17 , V_314 ) ;
F_5 ( V_307 , V_19 , 0 ) ;
F_40 ( V_307 , V_315 , V_309 ) ;
F_5 ( V_307 , V_316 , 0 ) ;
F_5 ( V_307 , V_317 , 0 ) ;
V_14 = F_6 ( V_2 , V_20 , V_307 , sizeof( V_307 ) ,
NULL , 0 , NULL ) ;
if ( V_14 != 0 )
return V_14 ;
V_4 -> V_174 = V_309 ;
return 0 ;
}
static int F_162 ( struct V_305 * V_40 , T_4 V_306 )
{
T_5 V_22 , V_23 ;
struct V_39 * V_4 = F_88 ( V_40 ,
struct V_39 ,
V_208 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_4 ( V_9 , V_308 ) ;
V_2 -> V_4 -> V_51 ( V_306 , & V_22 , & V_23 ) ;
F_5 ( V_9 , V_17 , V_314 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
F_40 ( V_9 , V_315 , V_4 -> V_174 ) ;
F_5 ( V_9 , V_318 , V_22 ) ;
F_5 ( V_9 , V_319 , V_23 ) ;
return F_6 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
NULL , 0 , NULL ) ;
}
static int F_163 ( struct V_305 * V_40 , struct V_24 * V_25 )
{
struct V_39 * V_4 = F_88 ( V_40 ,
struct V_39 ,
V_208 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_4 ( V_9 , V_320 ) ;
F_4 ( V_11 , V_321 ) ;
int V_14 ;
T_6 V_29 ;
F_5 ( V_9 , V_17 , V_322 ) ;
F_5 ( V_9 , V_19 , 0 ) ;
V_14 = F_6 ( V_2 , V_20 , V_9 , sizeof( V_9 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_14 != 0 )
return V_14 ;
V_29 = V_4 -> V_52 (
F_20 ( V_11 , V_323 ) ,
F_20 ( V_11 , V_324 ) , 0 ) ;
* V_25 = F_164 ( V_29 ) ;
return 0 ;
}
static int F_165 ( struct V_305 * V_40 ,
const struct V_24 * V_325 )
{
int V_14 ;
struct V_24 V_326 ;
struct V_24 V_306 ;
V_14 = F_163 ( V_40 , & V_326 ) ;
if ( V_14 != 0 )
return V_14 ;
V_306 = F_166 ( * V_325 , V_326 ) ;
V_14 = F_162 ( V_40 , F_167 ( & V_306 ) ) ;
if ( V_14 != 0 )
return V_14 ;
return 0 ;
}
static int F_168 ( struct V_305 * V_40 ,
struct V_327 * V_328 ,
int V_329 )
{
struct V_39 * V_4 = F_88 ( V_40 ,
struct V_39 ,
V_208 ) ;
if ( V_328 -> type != V_330 )
return - V_270 ;
V_4 -> V_214 = ! ! V_329 ;
return 0 ;
}
void F_169 ( struct V_1 * V_2 )
{
if ( F_26 ( V_2 ) == 0 )
V_2 -> V_331 [ V_332 ] =
& V_333 ;
}
void F_170 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 ) )
F_33 ( V_2 , V_84 , V_2 -> V_49 , L_16 ) ;
if ( V_2 -> type -> V_334 )
V_2 -> type -> V_334 ( V_2 , true , true ) ;
}
void F_171 ( struct V_1 * V_2 )
{
if ( V_2 -> type -> V_334 )
V_2 -> type -> V_334 ( V_2 , false , true ) ;
F_84 ( V_2 ) ;
}
