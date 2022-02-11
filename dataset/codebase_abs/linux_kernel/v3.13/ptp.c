static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_4 ) ;
F_3 ( V_3 , V_5 , V_6 ) ;
F_3 ( V_3 , V_7 , 0 ) ;
F_3 ( V_3 , V_8 ,
V_2 -> V_9 -> V_10 -> V_10 ) ;
F_3 ( V_3 , V_11 , V_2 -> V_9 -> V_12 ) ;
return F_4 ( V_2 , V_13 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_14 ) ;
F_3 ( V_3 , V_5 , V_15 ) ;
F_3 ( V_3 , V_7 , 0 ) ;
return F_4 ( V_2 , V_13 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static void F_6 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_7 ( V_17 ) ) ) {
F_8 () ;
F_9 ( V_19 ) ;
F_10 () ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_20 , V_2 -> V_21 ,
L_1
L_2 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_22 V_24 ;
struct V_25 V_26 ;
struct V_27 * V_28 = V_2 -> V_9 ;
struct V_25 V_29 ;
int * V_30 = V_28 -> V_29 . V_31 ;
F_14 ( & V_24 ) ;
V_29 = V_24 . V_32 ;
V_26 = V_24 . V_32 ;
F_15 ( & V_26 , V_33 ) ;
while ( ( F_16 ( & V_24 . V_32 , & V_26 ) < 0 ) &&
F_17 ( * V_30 ) ) {
struct V_25 V_34 ;
unsigned int V_35 ;
V_34 = V_24 . V_32 ;
F_15 ( & V_34 , V_36 ) ;
do {
F_14 ( & V_24 ) ;
} while ( ( F_16 ( & V_24 . V_32 , & V_34 ) < 0 ) &&
F_17 ( * V_30 ) );
V_35 = ( V_24 . V_32 . V_37 << V_38 |
V_24 . V_32 . V_39 ) ;
V_2 -> type -> V_40 ( V_2 , V_35 ) ;
}
* V_23 = V_24 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_41 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
F_2 ( V_42 , V_43 ) ;
T_1 V_44 ;
int V_45 ;
unsigned long V_46 ;
struct V_22 V_23 = {} ;
unsigned int V_47 = 0 ;
int * V_29 = V_28 -> V_29 . V_31 ;
F_3 ( V_42 , V_5 , V_48 ) ;
F_3 ( V_42 , V_7 , 0 ) ;
F_3 ( V_42 , V_49 ,
V_41 ) ;
F_19 ( V_42 , V_50 ,
V_28 -> V_29 . V_51 ) ;
F_17 ( * V_29 ) = 0 ;
V_45 = F_20 ( V_2 , V_13 , V_42 ,
V_52 ) ;
F_21 ( V_45 ) ;
V_46 = V_53 + F_22 ( V_54 ) ;
while ( ! F_17 ( * V_29 ) && ( F_23 ( V_53 , V_46 ) ) ) {
F_24 ( 20 ) ;
V_47 ++ ;
}
if ( F_17 ( * V_29 ) )
F_13 ( V_2 , & V_23 ) ;
V_45 = F_25 ( V_2 , V_13 ,
V_52 ,
V_42 , sizeof( V_42 ) ,
& V_44 ) ;
if ( V_45 == 0 )
V_45 = F_26 ( V_2 , V_42 , V_44 ,
& V_23 ) ;
return V_45 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_27 * V_9 = V_2 -> V_9 ;
struct V_55 V_56 ;
int V_45 = - V_57 ;
F_2 ( V_58 , V_59 ) ;
T_1 V_60 ;
F_3 ( V_9 -> V_61 , V_5 , V_62 ) ;
F_3 ( V_9 -> V_61 , V_7 , 0 ) ;
F_3 ( V_9 -> V_61 , V_63 , V_19 -> V_60 ) ;
if ( F_28 ( V_19 ) -> V_64 != 0 ) {
V_45 = F_29 ( V_19 ) ;
if ( V_45 != 0 )
goto V_65;
}
if ( V_19 -> V_66 == V_67 ) {
V_45 = F_30 ( V_19 ) ;
if ( V_45 != 0 )
goto V_65;
}
F_31 ( V_19 ,
F_32 ( V_9 -> V_61 ,
V_68 ) ,
V_19 -> V_60 ) ;
V_45 = F_4 ( V_2 , V_13 ,
V_9 -> V_61 , F_33 ( V_19 -> V_60 ) ,
V_58 , sizeof( V_58 ) , & V_60 ) ;
if ( V_45 != 0 )
goto V_65;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_69 = F_34 (
F_35 ( V_58 , V_70 ) ,
F_35 ( V_58 , V_71 ) ) ;
F_36 ( V_19 , & V_56 ) ;
V_45 = 0 ;
V_65:
F_37 ( V_19 ) ;
return V_45 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
struct V_72 * V_73 ;
struct V_72 * V_74 ;
F_39 ( & V_28 -> V_75 ) ;
if ( ! F_40 ( & V_28 -> V_76 ) ) {
F_41 (cursor, next, &ptp->evt_list) {
struct V_77 * V_78 ;
V_78 = F_42 ( V_73 , struct V_77 ,
V_79 ) ;
if ( F_43 ( V_53 , V_78 -> V_80 ) ) {
F_44 ( & V_78 -> V_79 , & V_28 -> V_81 ) ;
F_45 ( V_2 , V_82 , V_2 -> V_21 ,
L_3 ) ;
}
}
}
if ( V_28 -> V_83 && F_40 ( & V_28 -> V_76 ) )
V_28 -> V_83 = false ;
F_46 ( & V_28 -> V_75 ) ;
}
static enum V_84 F_47 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
bool V_85 ;
struct V_72 * V_73 ;
struct V_72 * V_74 ;
struct V_86 * V_87 ;
enum V_84 V_45 = V_88 ;
F_39 ( & V_28 -> V_75 ) ;
V_85 = ! F_40 ( & V_28 -> V_76 ) ;
F_46 ( & V_28 -> V_75 ) ;
if ( ! V_85 )
return V_88 ;
V_87 = (struct V_86 * ) V_19 -> V_89 ;
F_39 ( & V_28 -> V_75 ) ;
F_41 (cursor, next, &ptp->evt_list) {
struct V_77 * V_78 ;
V_78 = F_42 ( V_73 , struct V_77 , V_79 ) ;
if ( ( V_78 -> V_90 == V_87 -> V_91 [ 0 ] ) &&
( V_78 -> V_92 == V_87 -> V_91 [ 1 ] ) ) {
struct V_55 * V_56 ;
V_56 = F_48 ( V_19 ) ;
V_56 -> V_69 = V_78 -> V_93 ;
V_87 -> V_94 = V_95 ;
V_45 = V_95 ;
F_44 ( & V_78 -> V_79 , & V_28 -> V_81 ) ;
break;
}
}
if ( V_28 -> V_83 && F_40 ( & V_28 -> V_76 ) )
V_28 -> V_83 = false ;
F_46 ( & V_28 -> V_75 ) ;
return V_45 ;
}
static bool F_49 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
bool V_45 = false ;
struct V_18 * V_19 ;
while ( ( V_19 = F_7 ( & V_28 -> V_96 ) ) ) {
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) V_19 -> V_89 ;
if ( V_87 -> V_94 == V_97 ) {
F_50 ( V_17 , V_19 ) ;
} else if ( F_47 ( V_2 , V_19 ) ==
V_95 ) {
V_45 = true ;
F_50 ( V_17 , V_19 ) ;
} else if ( F_43 ( V_53 , V_87 -> V_80 ) ) {
V_87 -> V_94 = V_98 ;
if ( F_51 () )
F_45 ( V_2 , V_99 , V_2 -> V_21 ,
L_4 ) ;
F_50 ( V_17 , V_19 ) ;
} else {
F_52 ( & V_28 -> V_96 , V_19 ) ;
break;
}
}
return V_45 ;
}
static inline void F_53 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
F_8 () ;
F_9 ( V_19 ) ;
F_10 () ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
struct V_100 V_101 ;
int V_45 ;
V_28 -> V_102 = false ;
F_55 ( & V_101 , V_103 , 0 ,
F_56 (
F_57 ( V_28 -> V_10 ) ) ) ;
V_45 = F_58 ( & V_101 , V_104 ,
F_59 ( V_105 ) ,
F_60 ( V_106 ) ) ;
if ( V_45 != 0 )
return V_45 ;
V_45 = F_61 ( V_2 , & V_101 , true ) ;
if ( V_45 < 0 )
return V_45 ;
V_28 -> V_107 = V_45 ;
F_55 ( & V_101 , V_103 , 0 ,
F_56 (
F_57 ( V_28 -> V_10 ) ) ) ;
V_45 = F_58 ( & V_101 , V_104 ,
F_59 ( V_105 ) ,
F_60 ( V_108 ) ) ;
if ( V_45 != 0 )
goto V_65;
V_45 = F_61 ( V_2 , & V_101 , true ) ;
if ( V_45 < 0 )
goto V_65;
V_28 -> V_109 = V_45 ;
V_45 = F_1 ( V_2 ) ;
if ( V_45 != 0 )
goto V_110;
V_28 -> V_111 = 0 ;
V_28 -> V_112 = 0 ;
V_28 -> V_113 = true ;
return 0 ;
V_110:
F_62 ( V_2 , V_103 ,
V_28 -> V_109 ) ;
V_65:
F_62 ( V_2 , V_103 ,
V_28 -> V_107 ) ;
return V_45 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
struct V_72 * V_73 ;
struct V_72 * V_74 ;
int V_45 ;
if ( V_28 == NULL )
return 0 ;
V_45 = F_5 ( V_2 ) ;
if ( V_28 -> V_113 ) {
F_62 ( V_2 , V_103 ,
V_28 -> V_109 ) ;
F_62 ( V_2 , V_103 ,
V_28 -> V_107 ) ;
V_28 -> V_113 = false ;
}
F_6 ( & V_2 -> V_9 -> V_96 ) ;
F_64 ( & V_2 -> V_9 -> V_114 ) ;
F_39 ( & V_2 -> V_9 -> V_75 ) ;
F_41 (cursor, next, &efx->ptp_data->evt_list) {
F_44 ( V_73 , & V_2 -> V_9 -> V_81 ) ;
}
V_28 -> V_83 = false ;
F_46 ( & V_2 -> V_9 -> V_75 ) ;
return V_45 ;
}
static int F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 && V_2 -> V_9 -> V_115 )
return F_54 ( V_2 ) ;
return 0 ;
}
static void F_66 ( struct V_116 * V_117 )
{
struct V_27 * V_28 =
F_67 ( V_117 , struct V_27 , V_118 ) ;
struct V_1 * V_2 = V_28 -> V_10 -> V_2 ;
struct V_119 V_120 ;
if ( F_18 ( V_2 , V_121 ) )
return;
V_120 . type = V_122 ;
V_120 . V_123 = V_28 -> V_124 ;
V_119 ( V_28 -> V_125 , & V_120 ) ;
}
static void F_68 ( struct V_116 * V_117 )
{
struct V_27 * V_9 =
F_67 ( V_117 , struct V_27 , V_117 ) ;
struct V_1 * V_2 = V_9 -> V_10 -> V_2 ;
struct V_18 * V_19 ;
struct V_16 V_126 ;
if ( V_9 -> V_102 ) {
F_63 ( V_2 ) ;
F_54 ( V_2 ) ;
return;
}
F_38 ( V_2 ) ;
F_69 ( & V_126 ) ;
if ( F_49 ( V_2 , & V_126 ) ||
! F_70 ( & V_9 -> V_114 ) ) {
while ( ( V_19 = F_7 ( & V_9 -> V_114 ) ) )
F_27 ( V_2 , V_19 ) ;
}
while ( ( V_19 = F_71 ( & V_126 ) ) )
F_53 ( V_2 , V_19 ) ;
}
static int F_72 ( struct V_127 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_27 * V_28 ;
int V_45 = 0 ;
unsigned int V_128 ;
V_10 -> V_129 = 0 ;
V_10 -> V_130 . V_131 = 0 ;
V_28 = F_73 ( sizeof( struct V_27 ) , V_132 ) ;
V_2 -> V_9 = V_28 ;
if ( ! V_2 -> V_9 )
return - V_133 ;
V_45 = F_74 ( V_2 , & V_28 -> V_29 , sizeof( int ) , V_132 ) ;
if ( V_45 != 0 )
goto V_134;
V_28 -> V_10 = V_10 ;
F_75 ( & V_28 -> V_96 ) ;
F_75 ( & V_28 -> V_114 ) ;
V_28 -> V_135 = F_76 ( L_5 ) ;
if ( ! V_28 -> V_135 ) {
V_45 = - V_133 ;
goto V_110;
}
F_77 ( & V_28 -> V_117 , F_68 ) ;
V_28 -> V_136 . V_137 = 0 ;
V_28 -> V_136 . V_138 = V_139 ;
V_28 -> V_136 . V_140 = V_141 ;
F_78 ( & V_28 -> V_76 ) ;
F_78 ( & V_28 -> V_81 ) ;
F_79 ( & V_28 -> V_75 ) ;
for ( V_128 = 0 ; V_128 < V_142 ; V_128 ++ )
F_80 ( & V_28 -> V_143 [ V_128 ] . V_79 , & V_28 -> V_81 ) ;
V_28 -> V_83 = false ;
V_28 -> V_144 . V_145 = V_146 ;
snprintf ( V_28 -> V_144 . V_147 ,
sizeof( V_28 -> V_144 . V_147 ) ,
L_6 , V_2 -> V_21 -> V_148 ) ;
V_28 -> V_144 . V_149 = V_150 ;
V_28 -> V_144 . V_151 = 0 ;
V_28 -> V_144 . V_152 = 0 ;
V_28 -> V_144 . V_153 = 0 ;
V_28 -> V_144 . V_154 = 1 ;
V_28 -> V_144 . V_155 = V_156 ;
V_28 -> V_144 . V_157 = V_158 ;
V_28 -> V_144 . V_159 = V_160 ;
V_28 -> V_144 . V_161 = V_162 ;
V_28 -> V_144 . V_163 = V_164 ;
V_28 -> V_125 = F_81 ( & V_28 -> V_144 ,
& V_2 -> V_165 -> V_166 ) ;
if ( F_82 ( V_28 -> V_125 ) ) {
V_45 = F_83 ( V_28 -> V_125 ) ;
goto V_167;
}
F_77 ( & V_28 -> V_118 , F_66 ) ;
V_28 -> V_168 = F_76 ( L_7 ) ;
if ( ! V_28 -> V_168 ) {
V_45 = - V_133 ;
goto V_169;
}
V_28 -> V_170 = false ;
return 0 ;
V_169:
F_84 ( V_2 -> V_9 -> V_125 ) ;
V_167:
F_85 ( V_2 -> V_9 -> V_135 ) ;
V_110:
F_86 ( V_2 , & V_28 -> V_29 ) ;
V_134:
F_87 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
return V_45 ;
}
static void F_88 ( struct V_127 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( ! V_2 -> V_9 )
return;
( void ) F_5 ( V_10 -> V_2 ) ;
F_89 ( & V_2 -> V_9 -> V_117 ) ;
F_89 ( & V_2 -> V_9 -> V_118 ) ;
F_64 ( & V_2 -> V_9 -> V_96 ) ;
F_64 ( & V_2 -> V_9 -> V_114 ) ;
F_84 ( V_2 -> V_9 -> V_125 ) ;
F_85 ( V_2 -> V_9 -> V_135 ) ;
F_85 ( V_2 -> V_9 -> V_168 ) ;
F_86 ( V_2 , & V_2 -> V_9 -> V_29 ) ;
F_87 ( V_2 -> V_9 ) ;
}
static void F_90 ( struct V_127 * V_10 ,
char * V_171 , T_1 V_60 )
{
snprintf ( V_171 , V_60 , L_8 , V_10 -> V_2 -> V_147 ) ;
}
bool F_91 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
return V_2 -> V_9 &&
V_2 -> V_9 -> V_115 &&
V_19 -> V_60 >= V_172 &&
V_19 -> V_60 <= V_173 &&
F_92 ( V_19 -> V_174 == F_60 ( V_175 ) ) &&
F_93 ( V_19 ) &&
F_94 ( V_19 ) >= sizeof( struct V_176 ) &&
F_95 ( V_19 ) -> V_174 == V_104 &&
F_96 ( V_19 ) >=
F_97 ( V_19 ) + sizeof( struct V_177 ) &&
F_98 ( V_19 ) -> V_178 == F_60 ( V_106 ) ;
}
static bool F_99 ( struct V_127 * V_10 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_27 * V_28 = V_2 -> V_9 ;
struct V_86 * V_87 = (struct V_86 * ) V_19 -> V_89 ;
T_2 * V_179 , * V_180 ;
unsigned int V_181 ;
V_87 -> V_80 = V_53 + F_22 ( V_182 ) ;
if ( V_28 -> V_12 == V_183 ) {
if ( ! F_100 ( V_19 , V_184 ) ) {
return false ;
}
V_181 = F_101 ( * ( V_185 * ) & V_19 -> V_186 [ V_187 ] ) ;
if ( V_181 != V_188 ) {
return false ;
}
V_179 = V_19 -> V_186 + V_189 ;
V_180 = V_19 -> V_186 + V_189 + 3 ;
} else {
if ( ! F_100 ( V_19 , V_190 ) ) {
return false ;
}
V_181 = V_19 -> V_186 [ V_191 ] ;
if ( ( V_181 & V_192 ) != V_193 ) {
return false ;
}
V_180 = V_19 -> V_186 + V_194 + 5 ;
if ( V_28 -> V_12 == V_195 ) {
V_179 = V_19 -> V_186 + V_194 + 2 ;
} else {
V_179 = V_19 -> V_186 + V_194 + 0 ;
F_102 ( V_28 -> V_12 != V_196 ) ;
}
}
if ( F_101 ( * ( V_185 * ) & V_19 -> V_186 [ V_197 ] ) == V_106 ) {
struct V_55 * V_56 ;
V_87 -> V_94 = V_88 ;
V_56 = F_48 ( V_19 ) ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
F_103 ( V_198 != V_199 ) ;
F_103 ( V_200 != V_201 ) ;
V_87 -> V_91 [ 0 ] = ( V_179 [ 0 ] |
( V_179 [ 1 ] << 8 ) |
( V_179 [ 2 ] << 16 ) |
( V_180 [ 0 ] << 24 ) ) ;
V_87 -> V_91 [ 1 ] = ( V_180 [ 1 ] |
( V_180 [ 2 ] << 8 ) |
( V_19 -> V_186 [ V_198 +
V_200 - 1 ] <<
16 ) ) ;
} else {
V_87 -> V_94 = V_97 ;
}
F_104 ( & V_28 -> V_96 , V_19 ) ;
F_105 ( V_28 -> V_135 , & V_28 -> V_117 ) ;
return true ;
}
int F_106 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
F_104 ( & V_28 -> V_114 , V_19 ) ;
if ( ( F_98 ( V_19 ) -> V_178 == F_60 ( V_106 ) ) &&
( V_19 -> V_60 <= V_173 ) )
F_107 ( V_19 ) ;
F_105 ( V_28 -> V_135 , & V_28 -> V_117 ) ;
return V_202 ;
}
static int F_108 ( struct V_1 * V_2 , bool V_203 ,
unsigned int V_204 )
{
if ( ( V_203 != V_2 -> V_9 -> V_115 ) ||
( V_203 && ( V_2 -> V_9 -> V_12 != V_204 ) ) ) {
int V_45 = 0 ;
if ( V_203 ) {
if ( V_2 -> V_9 -> V_115 &&
( V_2 -> V_9 -> V_12 != V_204 ) ) {
V_2 -> V_9 -> V_115 = false ;
V_45 = F_63 ( V_2 ) ;
if ( V_45 != 0 )
return V_45 ;
}
V_2 -> V_9 -> V_12 = V_204 ;
if ( F_109 ( V_2 -> V_21 ) )
V_45 = F_54 ( V_2 ) ;
if ( V_45 == 0 ) {
V_45 = F_18 ( V_2 ,
V_121 * 2 ) ;
if ( V_45 != 0 )
F_63 ( V_2 ) ;
}
} else {
V_45 = F_63 ( V_2 ) ;
}
if ( V_45 != 0 )
return V_45 ;
V_2 -> V_9 -> V_115 = V_203 ;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_205 * V_206 )
{
bool V_203 = false ;
unsigned int V_204 ;
int V_45 ;
if ( V_206 -> V_137 )
return - V_207 ;
if ( ( V_206 -> V_138 != V_139 ) &&
( V_206 -> V_138 != V_208 ) )
return - V_209 ;
V_204 = V_2 -> V_9 -> V_12 ;
switch ( V_206 -> V_140 ) {
case V_141 :
break;
case V_210 :
case V_211 :
case V_212 :
V_206 -> V_140 = V_210 ;
V_204 = V_183 ;
V_203 = true ;
break;
case V_213 :
case V_214 :
case V_215 :
V_206 -> V_140 = V_213 ;
V_204 = V_196 ;
V_203 = true ;
break;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
return - V_209 ;
break;
default:
return - V_209 ;
}
if ( V_206 -> V_138 != V_139 )
V_203 = true ;
V_45 = F_108 ( V_2 , V_203 , V_204 ) ;
if ( ( V_45 != 0 ) && ( V_204 == V_196 ) )
V_45 = F_108 ( V_2 , V_203 , V_195 ) ;
if ( V_45 != 0 )
return V_45 ;
V_2 -> V_9 -> V_136 = * V_206 ;
return 0 ;
}
void F_111 ( struct V_1 * V_2 , struct V_222 * V_223 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
if ( ! V_28 )
return;
V_223 -> V_224 |= ( V_225 |
V_226 |
V_227 ) ;
V_223 -> V_228 = F_112 ( V_28 -> V_125 ) ;
V_223 -> V_229 = 1 << V_139 | 1 << V_208 ;
V_223 -> V_230 = ( 1 << V_141 |
1 << V_210 |
1 << V_211 |
1 << V_212 |
1 << V_213 |
1 << V_214 |
1 << V_215 ) ;
}
int F_113 ( struct V_1 * V_2 , struct V_231 * V_232 , int V_233 )
{
struct V_205 V_136 ;
int V_45 ;
if ( ! V_2 -> V_9 )
return - V_234 ;
if ( F_114 ( & V_136 , V_232 -> V_235 , sizeof( V_136 ) ) )
return - V_236 ;
V_45 = F_110 ( V_2 , & V_136 ) ;
if ( V_45 != 0 )
return V_45 ;
return F_115 ( V_232 -> V_235 , & V_136 , sizeof( V_136 ) )
? - V_236 : 0 ;
}
static void F_116 ( struct V_1 * V_2 , int V_237 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
F_12 ( V_2 , V_82 , V_2 -> V_21 ,
L_9 ,
V_28 -> V_111 , V_237 ) ;
V_28 -> V_102 = true ;
F_105 ( V_28 -> V_135 , & V_28 -> V_117 ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_77 * V_78 = NULL ;
if ( V_28 -> V_111 != 3 ) {
F_116 ( V_2 , 3 ) ;
return;
}
F_39 ( & V_28 -> V_75 ) ;
if ( ! F_40 ( & V_28 -> V_81 ) ) {
V_78 = F_118 ( & V_28 -> V_81 ,
struct V_77 , V_79 ) ;
F_119 ( & V_78 -> V_79 ) ;
V_78 -> V_90 = F_120 ( V_28 -> V_238 [ 2 ] , V_239 ) ;
V_78 -> V_92 = ( F_120 ( V_28 -> V_238 [ 2 ] ,
V_240 ) |
( F_120 ( V_28 -> V_238 [ 1 ] ,
V_240 ) << 8 ) |
( F_120 ( V_28 -> V_238 [ 0 ] ,
V_240 ) << 16 ) ) ;
V_78 -> V_93 = F_34 (
F_120 ( V_28 -> V_238 [ 0 ] , V_239 ) ,
F_120 ( V_28 -> V_238 [ 1 ] , V_239 ) ) ;
V_78 -> V_80 = V_53 + F_22 ( V_182 ) ;
F_121 ( & V_78 -> V_79 , & V_28 -> V_76 ) ;
F_105 ( V_28 -> V_135 , & V_28 -> V_117 ) ;
} else if ( ! V_28 -> V_83 ) {
F_12 ( V_2 , V_99 , V_2 -> V_21 , L_10 ) ;
V_28 -> V_83 = true ;
}
F_46 ( & V_28 -> V_75 ) ;
}
static void F_122 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_241 = F_120 ( V_28 -> V_238 [ 0 ] , V_239 ) ;
if ( V_28 -> V_111 != 1 ) {
F_116 ( V_2 , 1 ) ;
return;
}
F_12 ( V_2 , V_82 , V_2 -> V_21 , L_11 , V_241 ) ;
}
static void F_123 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
if ( V_28 -> V_170 )
F_105 ( V_28 -> V_168 , & V_28 -> V_118 ) ;
}
void F_124 ( struct V_1 * V_2 , T_3 * V_242 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
int V_241 = F_120 ( * V_242 , V_243 ) ;
if ( ! V_28 -> V_115 )
return;
if ( V_28 -> V_111 == 0 ) {
V_28 -> V_244 = V_241 ;
} else if ( V_28 -> V_244 != V_241 ) {
F_12 ( V_2 , V_82 , V_2 -> V_21 ,
L_12 , V_241 ) ;
V_28 -> V_111 = 0 ;
}
V_28 -> V_238 [ V_28 -> V_111 ++ ] = * V_242 ;
if ( ! F_125 ( * V_242 , V_245 ) ) {
switch ( V_241 ) {
case V_246 :
F_117 ( V_2 , V_28 ) ;
break;
case V_247 :
F_122 ( V_2 , V_28 ) ;
break;
case V_248 :
F_123 ( V_2 , V_28 ) ;
break;
default:
F_12 ( V_2 , V_82 , V_2 -> V_21 ,
L_13 , V_241 ) ;
break;
}
V_28 -> V_111 = 0 ;
} else if ( V_249 == V_28 -> V_111 ) {
F_12 ( V_2 , V_82 , V_2 -> V_21 ,
L_14 ) ;
V_28 -> V_111 = 0 ;
}
}
static int V_156 ( struct V_250 * V_28 , T_4 V_251 )
{
struct V_27 * V_9 = F_67 ( V_28 ,
struct V_27 ,
V_144 ) ;
struct V_1 * V_2 = V_9 -> V_10 -> V_2 ;
F_2 ( V_252 , V_253 ) ;
T_5 V_254 ;
int V_45 ;
if ( V_251 > V_150 )
V_251 = V_150 ;
else if ( V_251 < - V_150 )
V_251 = - V_150 ;
V_254 = ( ( ( T_5 ) V_251 * V_255 ) >>
( V_256 + V_257 ) ) ;
F_3 ( V_252 , V_5 , V_258 ) ;
F_3 ( V_252 , V_7 , 0 ) ;
F_19 ( V_252 , V_259 , V_254 ) ;
F_3 ( V_252 , V_260 , 0 ) ;
F_3 ( V_252 , V_261 , 0 ) ;
V_45 = F_4 ( V_2 , V_13 , V_252 , sizeof( V_252 ) ,
NULL , 0 , NULL ) ;
if ( V_45 != 0 )
return V_45 ;
V_9 -> V_112 = V_254 ;
return 0 ;
}
static int V_158 ( struct V_250 * V_28 , T_5 V_251 )
{
struct V_27 * V_9 = F_67 ( V_28 ,
struct V_27 ,
V_144 ) ;
struct V_1 * V_2 = V_9 -> V_10 -> V_2 ;
struct V_25 V_262 = F_126 ( V_251 ) ;
F_2 ( V_3 , V_253 ) ;
F_3 ( V_3 , V_5 , V_258 ) ;
F_3 ( V_3 , V_7 , 0 ) ;
F_19 ( V_3 , V_259 , V_9 -> V_112 ) ;
F_3 ( V_3 , V_260 , ( V_263 ) V_262 . V_37 ) ;
F_3 ( V_3 , V_261 , ( V_263 ) V_262 . V_39 ) ;
return F_4 ( V_2 , V_13 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static int V_160 ( struct V_250 * V_28 , struct V_25 * V_264 )
{
struct V_27 * V_9 = F_67 ( V_28 ,
struct V_27 ,
V_144 ) ;
struct V_1 * V_2 = V_9 -> V_10 -> V_2 ;
F_2 ( V_3 , V_265 ) ;
F_2 ( V_266 , V_267 ) ;
int V_45 ;
F_3 ( V_3 , V_5 , V_268 ) ;
F_3 ( V_3 , V_7 , 0 ) ;
V_45 = F_4 ( V_2 , V_13 , V_3 , sizeof( V_3 ) ,
V_266 , sizeof( V_266 ) , NULL ) ;
if ( V_45 != 0 )
return V_45 ;
V_264 -> V_37 = F_35 ( V_266 , V_269 ) ;
V_264 -> V_39 = F_35 ( V_266 , V_270 ) ;
return 0 ;
}
static int V_162 ( struct V_250 * V_28 ,
const struct V_25 * V_271 )
{
int V_45 ;
struct V_25 V_272 ;
struct V_25 V_251 ;
V_45 = V_160 ( V_28 , & V_272 ) ;
if ( V_45 != 0 )
return V_45 ;
V_251 = F_127 ( * V_271 , V_272 ) ;
V_45 = V_158 ( V_28 , F_128 ( & V_251 ) ) ;
if ( V_45 != 0 )
return V_45 ;
return 0 ;
}
static int V_164 ( struct V_250 * V_28 ,
struct V_273 * V_274 ,
int V_163 )
{
struct V_27 * V_9 = F_67 ( V_28 ,
struct V_27 ,
V_144 ) ;
if ( V_274 -> type != V_275 )
return - V_234 ;
V_9 -> V_170 = ! ! V_163 ;
return 0 ;
}
void F_129 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) == 0 )
V_2 -> V_276 [ V_277 ] =
& V_278 ;
}
void F_130 ( struct V_1 * V_2 )
{
if ( F_65 ( V_2 ) )
F_12 ( V_2 , V_20 , V_2 -> V_21 , L_15 ) ;
}
void F_131 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
}
