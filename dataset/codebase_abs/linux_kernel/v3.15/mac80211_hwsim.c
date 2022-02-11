static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
F_2 ( V_4 -> V_6 != V_7 ,
L_1 ,
V_2 , V_4 -> V_6 , V_2 -> V_8 , V_2 -> type , V_2 -> V_9 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
V_4 -> V_6 = V_7 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
}
static inline void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_5 ;
F_6 ( V_13 -> V_6 != V_14 ) ;
}
static inline void F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_5 ;
V_13 -> V_6 = V_14 ;
}
static inline void F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_5 ;
V_13 -> V_6 = 0 ;
}
static inline void F_9 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_5 ;
F_6 ( V_18 -> V_6 != V_19 ) ;
}
static inline void F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_5 ;
V_18 -> V_6 = V_19 ;
}
static inline void F_11 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_5 ;
V_18 -> V_6 = 0 ;
}
static void F_12 ( void * V_20 , T_1 * V_21 , struct V_1 * V_2 )
{
struct V_22 * V_23 = V_20 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
if ( ! V_4 -> V_28 )
return;
F_13 ( V_23 -> V_29 -> V_30 ,
L_2 ,
V_31 , V_4 -> V_32 , V_4 -> V_33 ) ;
V_25 = F_14 ( sizeof( * V_27 ) ) ;
if ( ! V_25 )
return;
V_27 = ( void * ) F_15 ( V_25 , sizeof( * V_27 ) ) ;
V_27 -> V_34 = F_16 ( V_35 |
V_36 |
V_37 ) ;
V_27 -> V_33 = F_16 ( 0xc000 | V_4 -> V_33 ) ;
memcpy ( V_27 -> V_32 , V_4 -> V_32 , V_38 ) ;
memcpy ( V_27 -> V_39 , V_21 , V_38 ) ;
F_17 () ;
F_18 ( V_23 -> V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
F_20 () ;
}
static void F_21 ( struct V_22 * V_23 , T_1 * V_21 ,
struct V_1 * V_2 , int V_43 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_24 * V_25 ;
struct V_44 * V_45 ;
if ( ! V_4 -> V_28 )
return;
F_13 ( V_23 -> V_29 -> V_30 ,
L_3 ,
V_31 , V_4 -> V_32 , V_43 ) ;
V_25 = F_14 ( sizeof( * V_45 ) ) ;
if ( ! V_25 )
return;
V_45 = ( void * ) F_15 ( V_25 , sizeof( * V_45 ) - V_38 ) ;
V_45 -> V_34 = F_16 ( V_46 |
V_47 |
( V_43 ? V_37 : 0 ) ) ;
V_45 -> V_48 = F_16 ( 0 ) ;
memcpy ( V_45 -> V_49 , V_4 -> V_32 , V_38 ) ;
memcpy ( V_45 -> V_50 , V_21 , V_38 ) ;
memcpy ( V_45 -> V_51 , V_4 -> V_32 , V_38 ) ;
F_17 () ;
F_18 ( V_23 -> V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
F_20 () ;
}
static void F_22 ( void * V_20 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_20 ;
F_21 ( V_23 , V_21 , V_2 , 1 ) ;
}
static void F_23 ( void * V_20 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_20 ;
F_21 ( V_23 , V_21 , V_2 , 0 ) ;
}
static int F_24 ( void * V_20 , T_2 * V_52 )
{
struct V_22 * V_23 = V_20 ;
* V_52 = V_23 -> V_43 ;
return 0 ;
}
static int F_25 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
enum V_53 V_54 ;
if ( V_52 != V_55 && V_52 != V_56 && V_52 != V_57 &&
V_52 != V_58 )
return - V_59 ;
V_54 = V_23 -> V_43 ;
V_23 -> V_43 = V_52 ;
if ( V_52 == V_58 ) {
F_26 ( V_23 -> V_29 ,
V_60 ,
F_12 , V_23 ) ;
V_23 -> V_61 = true ;
} else if ( V_54 == V_55 && V_52 != V_55 ) {
F_26 ( V_23 -> V_29 ,
V_60 ,
F_22 ,
V_23 ) ;
} else if ( V_54 != V_55 && V_52 == V_55 ) {
F_26 ( V_23 -> V_29 ,
V_60 ,
F_23 ,
V_23 ) ;
}
return 0 ;
}
static int F_27 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
F_28 ( V_23 -> V_29 ) ;
return 0 ;
}
static int F_29 ( void * V_20 , T_2 * V_52 )
{
struct V_22 * V_23 = V_20 ;
* V_52 = V_23 -> V_62 ;
return 0 ;
}
static int F_30 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
V_23 -> V_62 = V_52 ;
return 0 ;
}
static T_3 F_31 ( struct V_24 * V_25 ,
struct V_63 * V_64 )
{
F_32 ( V_25 ) ;
return V_65 ;
}
static inline T_2 F_33 ( void )
{
return F_34 ( F_35 () ) ;
}
static T_4 F_36 ( struct V_22 * V_23 )
{
T_2 V_66 = F_33 () ;
return F_37 ( V_66 + V_23 -> V_67 ) ;
}
static T_2 F_38 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
return F_39 ( F_36 ( V_23 ) ) ;
}
static void F_40 ( struct V_68 * V_29 ,
struct V_1 * V_2 , T_2 V_70 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
T_2 V_66 = F_38 ( V_29 , V_2 ) ;
T_5 V_71 = V_23 -> V_72 ;
T_6 V_73 = V_70 - V_66 ;
V_23 -> V_67 += V_73 ;
V_23 -> V_74 = F_41 ( V_73 , V_71 ) ;
}
static void F_42 ( struct V_68 * V_29 ,
struct V_24 * V_75 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_24 * V_25 ;
struct V_77 * V_45 ;
T_7 V_78 ;
struct V_79 * V_80 = F_43 ( V_75 ) ;
struct V_81 * V_82 = F_44 ( V_29 , V_80 ) ;
if ( ! F_45 ( V_83 ) )
return;
V_25 = F_46 ( V_75 , sizeof( * V_45 ) , 0 , V_84 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_77 * ) F_47 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_48 ( ( 1 << V_90 ) |
( 1 << V_91 ) |
( 1 << V_92 ) |
( 1 << V_93 ) ) ;
V_45 -> V_94 = F_36 ( V_23 ) ;
V_45 -> V_95 = 0 ;
V_45 -> V_96 = V_82 -> V_97 / 5 ;
V_45 -> V_98 = F_16 ( V_42 -> V_99 ) ;
V_78 = V_100 ;
if ( V_82 -> V_78 & V_101 )
V_78 |= V_102 ;
else
V_78 |= V_103 ;
V_45 -> V_104 = F_16 ( V_78 ) ;
V_25 -> V_64 = V_83 ;
F_49 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_50 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_51 ( V_25 ) ;
}
static void F_52 ( struct V_76 * V_42 ,
const T_1 * V_8 )
{
struct V_24 * V_25 ;
struct V_112 * V_45 ;
T_7 V_78 ;
struct V_44 * V_113 ;
if ( ! F_45 ( V_83 ) )
return;
V_25 = F_14 ( 100 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_112 * ) F_15 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_48 ( ( 1 << V_90 ) |
( 1 << V_93 ) ) ;
V_45 -> V_95 = 0 ;
V_45 -> V_114 = 0 ;
V_45 -> V_98 = F_16 ( V_42 -> V_99 ) ;
V_78 = V_100 ;
V_45 -> V_104 = F_16 ( V_78 ) ;
V_113 = (struct V_44 * ) F_15 ( V_25 , 10 ) ;
V_113 -> V_34 = F_16 ( V_35 |
V_115 ) ;
V_113 -> V_48 = F_16 ( 0 ) ;
memcpy ( V_113 -> V_49 , V_8 , V_38 ) ;
V_25 -> V_64 = V_83 ;
F_49 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_50 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_51 ( V_25 ) ;
}
static bool F_53 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
switch ( V_23 -> V_43 ) {
case V_55 :
return true ;
case V_56 :
return false ;
case V_57 :
return true ;
case V_58 :
if ( V_23 -> V_61 &&
memcmp ( V_23 -> V_29 -> V_30 -> V_116 , V_25 -> V_23 + 4 ,
V_38 ) == 0 ) {
V_23 -> V_61 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_54 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_117 * V_118 = V_23 ;
if ( memcmp ( V_21 , V_118 -> V_8 , V_38 ) == 0 )
V_118 -> V_119 = true ;
}
static bool F_55 ( struct V_22 * V_23 ,
const T_1 * V_8 )
{
struct V_117 V_118 ;
if ( memcmp ( V_8 , V_23 -> V_29 -> V_30 -> V_116 , V_38 ) == 0 )
return true ;
V_118 . V_119 = false ;
V_118 . V_8 = V_8 ;
F_56 ( V_23 -> V_29 ,
V_60 ,
F_54 ,
& V_118 ) ;
return V_118 . V_119 ;
}
static void F_57 ( struct V_68 * V_29 ,
struct V_24 * V_120 ,
int V_121 )
{
struct V_24 * V_25 ;
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_44 * V_45 = (struct V_44 * ) V_120 -> V_23 ;
struct V_79 * V_80 = F_43 ( V_120 ) ;
void * V_122 ;
unsigned int V_123 = 0 ;
int V_124 ;
struct V_125 V_126 [ V_127 ] ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
if ( F_58 ( & V_23 -> V_128 ) >= V_129 ) {
while ( F_58 ( & V_23 -> V_128 ) >= V_130 )
F_59 ( & V_23 -> V_128 ) ;
}
V_25 = F_60 ( V_131 , V_84 ) ;
if ( V_25 == NULL )
goto V_132;
V_122 = F_61 ( V_25 , 0 , 0 , & V_133 , 0 ,
V_134 ) ;
if ( V_122 == NULL ) {
F_62 ( V_135 L_4 ) ;
goto V_132;
}
if ( F_63 ( V_25 , V_136 ,
V_38 , V_23 -> V_137 [ 1 ] . V_8 ) )
goto V_132;
if ( F_63 ( V_25 , V_138 , V_120 -> V_139 , V_120 -> V_23 ) )
goto V_132;
if ( V_80 -> V_78 & V_140 )
V_123 |= V_141 ;
if ( V_80 -> V_78 & V_142 )
V_123 |= V_143 ;
if ( F_64 ( V_25 , V_144 , V_123 ) )
goto V_132;
for ( V_124 = 0 ; V_124 < V_127 ; V_124 ++ ) {
V_126 [ V_124 ] . V_145 = V_80 -> V_146 . V_147 [ V_124 ] . V_145 ;
V_126 [ V_124 ] . V_148 = V_80 -> V_146 . V_147 [ V_124 ] . V_148 ;
}
if ( F_63 ( V_25 , V_149 ,
sizeof( struct V_125 ) * V_127 ,
V_126 ) )
goto V_132;
if ( F_65 ( V_25 , V_150 , ( unsigned long ) V_120 ) )
goto V_132;
F_66 ( V_25 , V_122 ) ;
F_67 ( & V_151 , V_25 , V_121 ) ;
F_68 ( & V_23 -> V_128 , V_120 ) ;
return;
V_132:
F_62 ( V_135 L_5 , V_31 ) ;
}
static bool F_69 ( struct V_76 * V_152 ,
struct V_76 * V_153 )
{
if ( ! V_152 || ! V_153 )
return false ;
return V_152 -> V_99 == V_153 -> V_99 ;
}
static void F_70 ( void * V_154 , T_1 * V_8 ,
struct V_1 * V_2 )
{
struct V_155 * V_23 = V_154 ;
if ( ! V_2 -> V_40 )
return;
if ( ! F_69 ( V_23 -> V_156 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) )
return;
V_23 -> V_157 = true ;
}
static bool F_71 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 , * V_158 ;
bool V_159 = false ;
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
struct V_79 * V_80 = F_43 ( V_25 ) ;
struct V_160 V_161 ;
T_2 V_66 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_162 |= V_163 ;
V_161 . V_164 = V_42 -> V_99 ;
V_161 . V_165 = V_42 -> V_165 ;
if ( V_80 -> V_166 . V_147 [ 0 ] . V_78 & V_167 ) {
V_161 . V_168 =
F_72 ( & V_80 -> V_166 . V_147 [ 0 ] ) ;
V_161 . V_169 =
F_73 ( & V_80 -> V_166 . V_147 [ 0 ] ) ;
V_161 . V_162 |= V_170 ;
} else {
V_161 . V_168 = V_80 -> V_166 . V_147 [ 0 ] . V_145 ;
if ( V_80 -> V_166 . V_147 [ 0 ] . V_78 & V_171 )
V_161 . V_162 |= V_172 ;
}
if ( V_80 -> V_166 . V_147 [ 0 ] . V_78 & V_173 )
V_161 . V_162 |= V_174 ;
if ( V_80 -> V_166 . V_147 [ 0 ] . V_78 & V_175 )
V_161 . V_162 |= V_176 ;
V_161 . signal = V_23 -> V_177 - 50 ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
F_74 ( V_25 ) ;
F_75 ( V_25 ) ;
V_25 -> V_178 = 0 ;
F_76 ( V_25 ) ;
F_77 ( V_25 ) ;
if ( F_78 ( V_45 -> V_34 ) ||
F_79 ( V_45 -> V_34 ) )
V_66 = V_23 -> V_179 ;
else
V_66 = F_33 () ;
F_80 ( & V_180 ) ;
F_81 (data2, &hwsim_radios, list) {
struct V_24 * V_181 ;
struct V_155 V_155 = {
. V_157 = false ,
. V_156 = V_42 ,
} ;
if ( V_23 == V_158 )
continue;
if ( ! V_158 -> V_182 || ( V_158 -> V_183 && ! V_158 -> V_184 ) ||
! F_53 ( V_158 , V_25 ) )
continue;
if ( ! ( V_23 -> V_62 & V_158 -> V_62 ) )
continue;
if ( ! F_69 ( V_42 , V_158 -> V_184 ) &&
! F_69 ( V_42 , V_158 -> V_156 ) ) {
F_56 (
V_158 -> V_29 , V_60 ,
F_70 , & V_155 ) ;
if ( ! V_155 . V_157 )
continue;
}
if ( V_25 -> V_139 < V_185 && V_186 ) {
struct V_187 * V_187 = F_82 ( V_84 ) ;
if ( ! V_187 )
continue;
V_181 = F_14 ( 128 ) ;
if ( ! V_181 ) {
F_83 ( V_187 ) ;
continue;
}
memcpy ( F_84 ( V_187 ) , V_25 -> V_23 , V_25 -> V_139 ) ;
F_85 ( V_181 , 0 , V_187 , 0 , V_25 -> V_139 , V_25 -> V_139 ) ;
} else {
V_181 = F_86 ( V_25 , V_84 ) ;
if ( ! V_181 )
continue;
}
if ( F_55 ( V_158 , V_45 -> V_49 ) )
V_159 = true ;
V_161 . V_188 = V_66 + V_158 -> V_67 ;
memcpy ( F_87 ( V_181 ) , & V_161 , sizeof( V_161 ) ) ;
F_88 ( V_158 -> V_29 , V_181 ) ;
}
F_89 ( & V_180 ) ;
return V_159 ;
}
static void F_90 ( struct V_68 * V_29 ,
struct V_189 * V_166 ,
struct V_24 * V_25 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_79 * V_190 = F_43 ( V_25 ) ;
struct V_15 * V_40 ;
struct V_76 * V_156 ;
bool V_159 ;
T_5 V_191 ;
if ( F_6 ( V_25 -> V_139 < 10 ) ) {
F_91 ( V_29 , V_25 ) ;
return;
}
if ( ! V_23 -> V_192 ) {
V_156 = V_23 -> V_156 ;
} else if ( V_190 -> V_193 == 4 ) {
V_156 = V_23 -> V_184 ;
} else {
V_40 = F_19 ( V_190 -> V_166 . V_2 -> V_40 ) ;
if ( V_40 )
V_156 = V_40 -> V_41 . V_42 ;
else
V_156 = NULL ;
}
if ( F_2 ( ! V_156 , L_6 , V_190 -> V_193 ) ) {
F_91 ( V_29 , V_25 ) ;
return;
}
if ( V_23 -> V_183 && ! V_23 -> V_184 ) {
F_13 ( V_29 -> V_30 , L_7 ) ;
F_91 ( V_29 , V_25 ) ;
return;
}
if ( V_190 -> V_166 . V_2 )
F_1 ( V_190 -> V_166 . V_2 ) ;
if ( V_166 -> V_11 )
F_5 ( V_166 -> V_11 ) ;
if ( V_29 -> V_78 & V_194 )
F_92 ( V_190 -> V_166 . V_2 , V_166 -> V_11 , V_25 ,
V_190 -> V_166 . V_147 ,
F_93 ( V_190 -> V_166 . V_147 ) ) ;
V_190 -> V_195 [ 0 ] = V_156 ;
F_42 ( V_29 , V_25 , V_156 ) ;
V_191 = F_94 ( V_196 ) ;
if ( V_191 )
return F_57 ( V_29 , V_25 , V_191 ) ;
V_159 = F_71 ( V_29 , V_25 , V_156 ) ;
if ( V_159 && V_25 -> V_139 >= 16 ) {
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_52 ( V_156 , V_45 -> V_50 ) ;
}
F_95 ( V_190 ) ;
V_190 -> V_166 . V_147 [ 0 ] . V_148 = 1 ;
V_190 -> V_166 . V_147 [ 1 ] . V_145 = - 1 ;
if ( ! ( V_190 -> V_78 & V_142 ) && V_159 )
V_190 -> V_78 |= V_197 ;
F_96 ( V_29 , V_25 ) ;
}
static int F_97 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_8 , V_31 ) ;
V_23 -> V_182 = true ;
return 0 ;
}
static void F_98 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
V_23 -> V_182 = false ;
F_99 ( & V_23 -> V_198 ) ;
F_13 ( V_29 -> V_30 , L_8 , V_31 ) ;
}
static int F_100 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_9 ,
V_31 , F_101 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_199 = 0 ;
V_2 -> V_193 [ V_200 ] = 0 ;
V_2 -> V_193 [ V_201 ] = 1 ;
V_2 -> V_193 [ V_202 ] = 2 ;
V_2 -> V_193 [ V_203 ] = 3 ;
return 0 ;
}
static int F_102 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_204 V_205 ,
bool V_206 )
{
V_205 = F_103 ( V_205 , V_206 ) ;
F_13 ( V_29 -> V_30 ,
L_10 ,
V_31 , F_101 ( V_2 ) ,
V_205 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_199 = 0 ;
return 0 ;
}
static void F_104 (
struct V_68 * V_29 , struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_9 ,
V_31 , F_101 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_18 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
T_5 V_207 = F_94 ( V_196 ) ;
if ( V_29 -> V_78 & V_194 ) {
struct V_79 * V_190 = F_43 ( V_25 ) ;
F_92 ( V_190 -> V_166 . V_2 , NULL , V_25 ,
V_190 -> V_166 . V_147 ,
F_93 ( V_190 -> V_166 . V_147 ) ) ;
}
F_42 ( V_29 , V_25 , V_42 ) ;
if ( V_207 )
return F_57 ( V_29 , V_25 , V_207 ) ;
F_71 ( V_29 , V_25 , V_42 ) ;
F_32 ( V_25 ) ;
}
static void F_105 ( void * V_208 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_208 ;
struct V_68 * V_29 = V_23 -> V_29 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_209 * V_210 ;
struct V_24 * V_25 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_211 &&
V_2 -> type != V_212 &&
V_2 -> type != V_213 )
return;
V_25 = F_106 ( V_29 , V_2 ) ;
if ( V_25 == NULL )
return;
V_80 = F_43 ( V_25 ) ;
if ( V_29 -> V_78 & V_194 )
F_92 ( V_2 , NULL , V_25 ,
V_80 -> V_166 . V_147 ,
F_93 ( V_80 -> V_166 . V_147 ) ) ;
V_82 = F_44 ( V_29 , V_80 ) ;
V_210 = (struct V_209 * ) V_25 -> V_23 ;
V_23 -> V_179 = F_33 () ;
V_210 -> V_214 . V_215 . V_216 = F_37 ( V_23 -> V_179 +
V_23 -> V_67 +
24 * 8 * 10 / V_82 -> V_97 ) ;
F_18 ( V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
if ( V_2 -> V_217 && F_107 ( V_2 ) )
F_108 ( V_2 ) ;
}
static enum V_218
F_109 ( struct V_219 * V_220 )
{
struct V_22 * V_23 =
F_110 ( V_220 , struct V_22 ,
V_198 . V_220 ) ;
struct V_68 * V_29 = V_23 -> V_29 ;
T_2 V_71 = V_23 -> V_72 ;
T_8 V_221 ;
if ( ! V_23 -> V_182 )
goto V_222;
F_56 (
V_29 , V_60 ,
F_105 , V_23 ) ;
if ( V_23 -> V_74 ) {
V_71 -= V_23 -> V_74 ;
V_23 -> V_74 = 0 ;
}
V_221 = F_111 ( F_112 ( V_220 ) ,
F_113 ( V_71 * 1000 ) ) ;
F_114 ( & V_23 -> V_198 , V_221 , V_223 ) ;
V_222:
return V_224 ;
}
static int F_115 ( struct V_68 * V_29 , T_5 V_225 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_226 * V_227 = & V_29 -> V_227 ;
static const char * V_228 [ V_229 ] = {
[ V_230 ] = L_11 ,
[ V_231 ] = L_12 ,
[ V_232 ] = L_13 ,
[ V_233 ] = L_14 ,
} ;
if ( V_227 -> V_234 . V_42 )
F_13 ( V_29 -> V_30 ,
L_15 ,
V_31 ,
V_227 -> V_234 . V_42 -> V_99 ,
V_227 -> V_234 . V_235 ,
V_227 -> V_234 . V_236 ,
V_237 [ V_227 -> V_234 . V_238 ] ,
! ! ( V_227 -> V_78 & V_239 ) ,
! ! ( V_227 -> V_78 & V_240 ) ,
V_228 [ V_227 -> V_241 ] ) ;
else
F_13 ( V_29 -> V_30 ,
L_16 ,
V_31 ,
! ! ( V_227 -> V_78 & V_239 ) ,
! ! ( V_227 -> V_78 & V_240 ) ,
V_228 [ V_227 -> V_241 ] ) ;
V_23 -> V_183 = ! ! ( V_227 -> V_78 & V_239 ) ;
V_23 -> V_156 = V_227 -> V_234 . V_42 ;
F_6 ( V_23 -> V_156 && V_23 -> V_192 ) ;
V_23 -> V_177 = V_227 -> V_177 ;
if ( ! V_23 -> V_182 || ! V_23 -> V_72 )
F_99 ( & V_23 -> V_198 ) ;
else if ( ! F_116 ( & V_23 -> V_198 . V_220 ) ) {
T_2 V_70 = F_38 ( V_29 , NULL ) ;
T_5 V_71 = V_23 -> V_72 ;
T_2 V_242 = V_71 - F_41 ( V_70 , V_71 ) ;
F_114 ( & V_23 -> V_198 ,
F_113 ( V_242 * 1000 ) ,
V_243 ) ;
}
return 0 ;
}
static void F_117 ( struct V_68 * V_29 ,
unsigned int V_244 ,
unsigned int * V_245 , T_2 V_246 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_8 , V_31 ) ;
V_23 -> V_247 = 0 ;
if ( * V_245 & V_248 )
V_23 -> V_247 |= V_248 ;
if ( * V_245 & V_249 )
V_23 -> V_247 |= V_249 ;
* V_245 = V_23 -> V_247 ;
}
static void F_118 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
unsigned int * V_148 = V_23 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_250 )
( * V_148 ) ++ ;
}
static void F_119 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_251 * V_80 ,
T_5 V_225 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_22 * V_23 = V_29 -> V_69 ;
F_1 ( V_2 ) ;
F_13 ( V_29 -> V_30 , L_17 ,
V_31 , V_225 , V_2 -> V_8 ) ;
if ( V_225 & V_252 ) {
F_13 ( V_29 -> V_30 , L_18 ,
V_31 , V_80 -> V_32 ) ;
memcpy ( V_4 -> V_32 , V_80 -> V_32 , V_38 ) ;
}
if ( V_225 & V_253 ) {
F_13 ( V_29 -> V_30 , L_19 ,
V_80 -> V_28 , V_80 -> V_33 ) ;
V_4 -> V_28 = V_80 -> V_28 ;
V_4 -> V_33 = V_80 -> V_33 ;
}
if ( V_225 & V_254 ) {
F_13 ( V_29 -> V_30 , L_20 , V_80 -> V_72 ) ;
V_23 -> V_72 = V_80 -> V_72 * 1024 ;
}
if ( V_225 & V_255 ) {
F_13 ( V_29 -> V_30 , L_21 , V_80 -> V_256 ) ;
V_4 -> V_250 = V_80 -> V_256 ;
if ( V_23 -> V_182 &&
! F_116 ( & V_23 -> V_198 . V_220 ) &&
V_80 -> V_256 ) {
T_2 V_70 , V_242 ;
T_5 V_71 ;
if ( F_6 ( ! V_23 -> V_72 ) )
V_23 -> V_72 = 1000 * 1024 ;
V_70 = F_38 ( V_29 , V_2 ) ;
V_71 = V_23 -> V_72 ;
V_242 = V_71 - F_41 ( V_70 , V_71 ) ;
F_114 ( & V_23 -> V_198 ,
F_113 ( V_242 * 1000 ) ,
V_243 ) ;
} else if ( ! V_80 -> V_256 ) {
unsigned int V_148 = 0 ;
F_56 (
V_23 -> V_29 , V_60 ,
F_118 , & V_148 ) ;
F_13 ( V_29 -> V_30 , L_22 ,
V_148 ) ;
if ( V_148 == 0 )
F_99 ( & V_23 -> V_198 ) ;
}
}
if ( V_225 & V_257 ) {
F_13 ( V_29 -> V_30 , L_23 ,
V_80 -> V_258 ) ;
}
if ( V_225 & V_259 ) {
F_13 ( V_29 -> V_30 , L_24 ,
V_80 -> V_260 ) ;
}
if ( V_225 & V_261 ) {
F_13 ( V_29 -> V_30 , L_25 , V_80 -> V_262 ) ;
}
if ( V_225 & V_263 ) {
F_13 ( V_29 -> V_30 , L_26 ,
V_80 -> V_264 ) ;
}
if ( V_225 & V_265 ) {
F_13 ( V_29 -> V_30 , L_27 ,
( unsigned long long ) V_80 -> V_266 ) ;
}
if ( V_225 & V_267 )
F_13 ( V_29 -> V_30 , L_28 , V_80 -> V_268 ) ;
}
static int F_120 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_121 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_122 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_269 V_270 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_270 ) {
case V_271 :
case V_272 :
break;
default:
F_2 ( 1 , L_29 , V_270 ) ;
break;
}
}
static int F_123 ( struct V_68 * V_29 ,
struct V_10 * V_11 ,
bool V_273 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_124 (
struct V_68 * V_29 ,
struct V_1 * V_2 , T_7 V_274 ,
const struct V_275 * V_276 )
{
F_13 ( V_29 -> V_30 ,
L_30 ,
V_31 , V_274 ,
V_276 -> V_277 , V_276 -> V_278 ,
V_276 -> V_279 , V_276 -> V_280 ) ;
return 0 ;
}
static int F_125 (
struct V_68 * V_29 , int V_145 ,
struct V_281 * V_282 )
{
struct V_226 * V_227 = & V_29 -> V_227 ;
F_13 ( V_29 -> V_30 , L_31 , V_31 , V_145 ) ;
if ( V_145 != 0 )
return - V_283 ;
V_282 -> V_156 = V_227 -> V_234 . V_42 ;
V_282 -> V_284 = V_285 ;
V_282 -> V_286 = - 92 ;
return 0 ;
}
static int F_126 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
void * V_23 , int V_139 )
{
struct V_22 * V_287 = V_29 -> V_69 ;
struct V_288 * V_289 [ V_290 + 1 ] ;
struct V_24 * V_25 ;
int V_291 , V_43 ;
V_291 = F_127 ( V_289 , V_290 , V_23 , V_139 ,
V_292 ) ;
if ( V_291 )
return V_291 ;
if ( ! V_289 [ V_293 ] )
return - V_59 ;
switch ( F_128 ( V_289 [ V_293 ] ) ) {
case V_294 :
if ( ! V_289 [ V_295 ] )
return - V_59 ;
V_43 = F_128 ( V_289 [ V_295 ] ) ;
return F_25 ( V_287 , V_43 ) ;
case V_296 :
V_25 = F_129 ( V_29 -> V_30 ,
F_130 ( sizeof( T_5 ) ) ) ;
if ( ! V_25 )
return - V_297 ;
if ( F_64 ( V_25 , V_295 , V_287 -> V_43 ) )
goto V_132;
return F_131 ( V_25 ) ;
case V_298 :
F_132 ( V_29 ) ;
return 0 ;
case V_299 :
F_133 ( V_29 ) ;
return 0 ;
default:
return - V_300 ;
}
V_132:
F_134 ( V_25 ) ;
return - V_301 ;
}
static int F_135 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_302 V_303 ,
struct V_10 * V_11 , T_7 V_304 , T_7 * V_305 ,
T_1 V_306 )
{
switch ( V_303 ) {
case V_307 :
F_136 ( V_2 , V_11 -> V_8 , V_304 ) ;
break;
case V_308 :
case V_309 :
case V_310 :
F_137 ( V_2 , V_11 -> V_8 , V_304 ) ;
break;
case V_311 :
break;
case V_312 :
case V_313 :
break;
default:
return - V_300 ;
}
return 0 ;
}
static void F_138 ( struct V_68 * V_29 , T_5 V_314 , bool V_315 )
{
}
static void F_139 ( struct V_316 * V_317 )
{
struct V_22 * V_287 =
F_110 ( V_317 , struct V_22 , V_318 . V_317 ) ;
struct V_319 * V_320 = V_287 -> V_321 ;
int V_322 , V_124 ;
F_140 ( & V_287 -> V_323 ) ;
if ( V_287 -> V_324 >= V_320 -> V_325 ) {
F_13 ( V_287 -> V_29 -> V_30 , L_32 ) ;
F_141 ( V_287 -> V_29 , false ) ;
V_287 -> V_321 = NULL ;
V_287 -> V_326 = NULL ;
V_287 -> V_184 = NULL ;
F_142 ( & V_287 -> V_323 ) ;
return;
}
F_13 ( V_287 -> V_29 -> V_30 , L_33 ,
V_320 -> V_327 [ V_287 -> V_324 ] -> V_99 ) ;
V_287 -> V_184 = V_320 -> V_327 [ V_287 -> V_324 ] ;
if ( V_287 -> V_184 -> V_78 & V_328 ||
! V_320 -> V_329 ) {
V_322 = 120 ;
} else {
V_322 = 30 ;
for ( V_124 = 0 ; V_124 < V_320 -> V_329 ; V_124 ++ ) {
struct V_24 * V_330 ;
V_330 = F_143 ( V_287 -> V_29 ,
V_287 -> V_326 ,
V_320 -> V_331 [ V_124 ] . V_332 ,
V_320 -> V_331 [ V_124 ] . V_333 ,
V_320 -> V_334 ) ;
if ( ! V_330 )
continue;
if ( V_320 -> V_334 )
memcpy ( F_15 ( V_330 , V_320 -> V_334 ) , V_320 -> V_335 ,
V_320 -> V_334 ) ;
F_144 () ;
F_18 ( V_287 -> V_29 , V_330 ,
V_287 -> V_184 ) ;
F_145 () ;
}
}
F_146 ( V_287 -> V_29 , & V_287 -> V_318 ,
F_147 ( V_322 ) ) ;
V_287 -> V_324 ++ ;
F_142 ( & V_287 -> V_323 ) ;
}
static int F_148 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_319 * V_320 )
{
struct V_22 * V_287 = V_29 -> V_69 ;
F_140 ( & V_287 -> V_323 ) ;
if ( F_6 ( V_287 -> V_184 || V_287 -> V_321 ) ) {
F_142 ( & V_287 -> V_323 ) ;
return - V_336 ;
}
V_287 -> V_321 = V_320 ;
V_287 -> V_326 = V_2 ;
V_287 -> V_324 = 0 ;
F_142 ( & V_287 -> V_323 ) ;
F_13 ( V_29 -> V_30 , L_34 ) ;
F_146 ( V_287 -> V_29 , & V_287 -> V_318 , 0 ) ;
return 0 ;
}
static void F_149 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_287 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_35 ) ;
F_150 ( & V_287 -> V_318 ) ;
F_140 ( & V_287 -> V_323 ) ;
F_141 ( V_287 -> V_29 , true ) ;
V_287 -> V_184 = NULL ;
V_287 -> V_321 = NULL ;
V_287 -> V_326 = NULL ;
F_142 ( & V_287 -> V_323 ) ;
}
static void F_151 ( struct V_68 * V_29 )
{
struct V_22 * V_287 = V_29 -> V_69 ;
F_140 ( & V_287 -> V_323 ) ;
if ( V_287 -> V_337 ) {
F_62 ( V_135 L_36 ) ;
goto V_222;
}
F_62 ( V_135 L_37 ) ;
V_287 -> V_337 = true ;
V_222:
F_142 ( & V_287 -> V_323 ) ;
}
static void F_152 ( struct V_68 * V_29 )
{
struct V_22 * V_287 = V_29 -> V_69 ;
F_140 ( & V_287 -> V_323 ) ;
F_62 ( V_135 L_38 ) ;
V_287 -> V_337 = false ;
F_142 ( & V_287 -> V_323 ) ;
}
static void F_153 ( struct V_316 * V_317 )
{
struct V_22 * V_287 =
F_110 ( V_317 , struct V_22 , V_338 . V_317 ) ;
F_140 ( & V_287 -> V_323 ) ;
F_154 ( V_287 -> V_29 ) ;
V_287 -> V_184 = NULL ;
F_142 ( & V_287 -> V_323 ) ;
F_13 ( V_287 -> V_29 -> V_30 , L_39 ) ;
}
static int F_155 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_76 * V_42 ,
int V_339 ,
enum V_340 type )
{
struct V_22 * V_287 = V_29 -> V_69 ;
F_140 ( & V_287 -> V_323 ) ;
if ( F_6 ( V_287 -> V_184 || V_287 -> V_321 ) ) {
F_142 ( & V_287 -> V_323 ) ;
return - V_336 ;
}
V_287 -> V_184 = V_42 ;
F_142 ( & V_287 -> V_323 ) ;
F_13 ( V_29 -> V_30 , L_40 ,
V_42 -> V_99 , V_339 ) ;
F_156 ( V_29 ) ;
F_146 ( V_29 , & V_287 -> V_338 ,
F_147 ( V_339 ) ) ;
return 0 ;
}
static int F_157 ( struct V_68 * V_29 )
{
struct V_22 * V_287 = V_29 -> V_69 ;
F_150 ( & V_287 -> V_338 ) ;
F_140 ( & V_287 -> V_323 ) ;
V_287 -> V_184 = NULL ;
F_142 ( & V_287 -> V_323 ) ;
F_13 ( V_29 -> V_30 , L_41 ) ;
return 0 ;
}
static int F_158 ( struct V_68 * V_29 ,
struct V_15 * V_341 )
{
F_10 ( V_341 ) ;
F_13 ( V_29 -> V_30 ,
L_42 ,
V_341 -> V_41 . V_42 -> V_99 , V_341 -> V_41 . V_238 ,
V_341 -> V_41 . V_235 , V_341 -> V_41 . V_236 ) ;
return 0 ;
}
static void F_159 ( struct V_68 * V_29 ,
struct V_15 * V_341 )
{
F_13 ( V_29 -> V_30 ,
L_43 ,
V_341 -> V_41 . V_42 -> V_99 , V_341 -> V_41 . V_238 ,
V_341 -> V_41 . V_235 , V_341 -> V_41 . V_236 ) ;
F_9 ( V_341 ) ;
F_11 ( V_341 ) ;
}
static void F_160 ( struct V_68 * V_29 ,
struct V_15 * V_341 ,
T_5 V_225 )
{
F_9 ( V_341 ) ;
F_13 ( V_29 -> V_30 ,
L_44 ,
V_341 -> V_41 . V_42 -> V_99 , V_341 -> V_41 . V_238 ,
V_341 -> V_41 . V_235 , V_341 -> V_41 . V_236 ) ;
}
static int F_161 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_341 )
{
F_1 ( V_2 ) ;
F_9 ( V_341 ) ;
return 0 ;
}
static void F_162 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_341 )
{
F_1 ( V_2 ) ;
F_9 ( V_341 ) ;
}
static int F_163 ( int V_327 , const char * V_342 ,
const struct V_343 * V_344 ,
bool V_345 , bool V_346 ,
bool V_192 )
{
int V_291 ;
T_1 V_8 [ V_38 ] ;
struct V_22 * V_23 ;
struct V_68 * V_29 ;
enum V_347 V_165 ;
const struct V_348 * V_349 = & V_350 ;
int V_145 ;
if ( F_6 ( V_327 > 1 && ! V_192 ) )
return - V_59 ;
F_164 ( & V_180 ) ;
V_145 = V_351 ++ ;
F_165 ( & V_180 ) ;
if ( V_192 )
V_349 = & V_352 ;
V_29 = F_166 ( sizeof( * V_23 ) , V_349 ) ;
if ( ! V_29 ) {
F_62 ( V_135 L_45 ) ;
V_291 = - V_297 ;
goto V_353;
}
V_23 = V_29 -> V_69 ;
V_23 -> V_29 = V_29 ;
V_23 -> V_64 = F_167 ( V_354 , NULL , 0 , V_29 , L_46 , V_145 ) ;
if ( F_168 ( V_23 -> V_64 ) ) {
F_62 ( V_135
L_47 ,
F_169 ( V_23 -> V_64 ) ) ;
V_291 = - V_297 ;
goto V_355;
}
V_23 -> V_64 -> V_356 = & V_357 . V_356 ;
V_291 = F_170 ( V_23 -> V_64 ) ;
if ( V_291 != 0 ) {
F_62 ( V_135 L_48 ,
V_291 ) ;
goto V_358;
}
F_171 ( & V_23 -> V_128 ) ;
F_172 ( V_29 , V_23 -> V_64 ) ;
memset ( V_8 , 0 , V_38 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_145 >> 8 ;
V_8 [ 4 ] = V_145 ;
memcpy ( V_23 -> V_137 [ 0 ] . V_8 , V_8 , V_38 ) ;
memcpy ( V_23 -> V_137 [ 1 ] . V_8 , V_8 , V_38 ) ;
V_23 -> V_137 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_29 -> V_30 -> V_359 = 2 ;
V_29 -> V_30 -> V_137 = V_23 -> V_137 ;
V_23 -> V_327 = V_327 ;
V_23 -> V_192 = V_192 ;
V_23 -> V_145 = V_145 ;
if ( V_23 -> V_192 ) {
V_29 -> V_30 -> V_360 = 255 ;
V_29 -> V_30 -> V_361 = V_362 ;
V_29 -> V_30 -> V_363 = 1000 ;
V_29 -> V_30 -> V_364 = 1 ;
V_29 -> V_30 -> V_365 = & V_23 -> V_366 ;
if ( V_346 )
V_23 -> V_366 = V_367 [ 0 ] ;
else
V_23 -> V_366 = V_368 [ 0 ] ;
V_23 -> V_366 . V_369 = V_23 -> V_327 ;
} else if ( V_346 ) {
V_29 -> V_30 -> V_365 = V_367 ;
V_29 -> V_30 -> V_364 =
F_93 ( V_367 ) ;
} else {
V_29 -> V_30 -> V_365 = V_368 ;
V_29 -> V_30 -> V_364 = F_93 ( V_368 ) ;
}
F_173 ( & V_23 -> V_338 , F_153 ) ;
F_173 ( & V_23 -> V_318 , F_139 ) ;
V_29 -> V_314 = 5 ;
V_29 -> V_370 = 4 ;
V_29 -> V_30 -> V_371 = F_174 ( V_372 ) |
F_174 ( V_211 ) |
F_174 ( V_373 ) |
F_174 ( V_374 ) |
F_174 ( V_213 ) |
F_174 ( V_212 ) ;
if ( V_346 )
V_29 -> V_30 -> V_371 |= F_174 ( V_375 ) ;
V_29 -> V_78 = V_376 |
V_377 |
V_378 |
V_379 |
V_380 |
V_381 |
V_382 |
V_383 |
V_384 ;
if ( V_385 )
V_29 -> V_78 |= V_194 ;
V_29 -> V_30 -> V_78 |= V_386 |
V_387 |
V_388 |
V_389 ;
V_29 -> V_30 -> V_390 |= V_391 ;
V_29 -> V_392 = sizeof( struct V_3 ) ;
V_29 -> V_393 = sizeof( struct V_12 ) ;
V_29 -> V_394 = sizeof( struct V_17 ) ;
memcpy ( V_23 -> V_395 , V_396 ,
sizeof( V_396 ) ) ;
memcpy ( V_23 -> V_397 , V_398 ,
sizeof( V_398 ) ) ;
memcpy ( V_23 -> V_147 , V_399 , sizeof( V_399 ) ) ;
for ( V_165 = V_400 ; V_165 < V_401 ; V_165 ++ ) {
struct V_402 * V_403 = & V_23 -> V_404 [ V_165 ] ;
switch ( V_165 ) {
case V_400 :
V_403 -> V_327 = V_23 -> V_395 ;
V_403 -> V_325 = F_93 ( V_396 ) ;
V_403 -> V_405 = V_23 -> V_147 ;
V_403 -> V_406 = F_93 ( V_399 ) ;
break;
case V_407 :
V_403 -> V_327 = V_23 -> V_397 ;
V_403 -> V_325 = F_93 ( V_398 ) ;
V_403 -> V_405 = V_23 -> V_147 + 4 ;
V_403 -> V_406 = F_93 ( V_399 ) - 4 ;
break;
default:
continue;
}
V_403 -> V_408 . V_409 = true ;
V_403 -> V_408 . V_410 = V_411 |
V_412 |
V_413 |
V_414 ;
V_403 -> V_408 . V_415 = 0x3 ;
V_403 -> V_408 . V_416 = 0x6 ;
memset ( & V_403 -> V_408 . V_417 , 0 ,
sizeof( V_403 -> V_408 . V_417 ) ) ;
V_403 -> V_408 . V_417 . V_418 [ 0 ] = 0xff ;
V_403 -> V_408 . V_417 . V_418 [ 1 ] = 0xff ;
V_403 -> V_408 . V_417 . V_419 = V_420 ;
V_29 -> V_30 -> V_404 [ V_165 ] = V_403 ;
V_403 -> V_421 . V_422 = true ;
V_403 -> V_421 . V_410 =
V_423 |
V_424 |
V_425 |
V_426 |
V_427 |
V_428 |
V_429 |
V_430 |
V_431 |
V_432 |
V_433 |
V_434 ;
V_403 -> V_421 . V_435 . V_436 =
F_16 ( V_437 << 0 |
V_437 << 2 |
V_438 << 4 |
V_437 << 6 |
V_437 << 8 |
V_438 << 10 |
V_438 << 12 |
V_437 << 14 ) ;
V_403 -> V_421 . V_435 . V_439 =
V_403 -> V_421 . V_435 . V_436 ;
}
V_23 -> V_62 = 1 ;
F_175 ( & V_23 -> V_323 ) ;
V_29 -> V_440 = 4 ;
V_29 -> V_441 = 11 ;
if ( V_345 )
V_29 -> V_30 -> V_442 |= V_443 ;
if ( V_344 ) {
V_29 -> V_30 -> V_442 |= V_444 ;
F_176 ( V_29 -> V_30 , V_344 ) ;
F_177 ( 1 ) ;
}
V_291 = F_178 ( V_29 ) ;
if ( V_291 < 0 ) {
F_62 ( V_135 L_49 ,
V_291 ) ;
goto V_358;
}
F_13 ( V_29 -> V_30 , L_50 , V_29 -> V_30 -> V_116 ) ;
if ( V_342 )
F_179 ( V_29 -> V_30 , V_342 ) ;
V_23 -> V_445 = F_180 ( L_51 , V_29 -> V_30 -> V_446 ) ;
F_181 ( L_52 , 0666 , V_23 -> V_445 , V_23 , & V_447 ) ;
F_181 ( L_53 , 0666 , V_23 -> V_445 , V_23 ,
& V_448 ) ;
if ( ! V_23 -> V_192 )
F_181 ( L_54 , 0222 ,
V_23 -> V_445 ,
V_23 , & V_449 ) ;
F_182 ( & V_23 -> V_198 ,
F_109 ,
V_450 , V_223 ) ;
F_164 ( & V_180 ) ;
F_183 ( & V_23 -> V_451 , & V_452 ) ;
F_165 ( & V_180 ) ;
return V_145 ;
V_358:
F_184 ( V_23 -> V_64 ) ;
V_355:
F_185 ( V_29 ) ;
V_353:
return V_291 ;
}
static void F_186 ( struct V_22 * V_23 )
{
F_187 ( V_23 -> V_445 ) ;
F_188 ( V_23 -> V_29 ) ;
F_189 ( V_23 -> V_64 ) ;
F_184 ( V_23 -> V_64 ) ;
F_185 ( V_23 -> V_29 ) ;
}
static void F_190 ( void )
{
struct V_22 * V_23 ;
F_164 ( & V_180 ) ;
while ( ( V_23 = F_191 ( & V_452 ,
struct V_22 ,
V_451 ) ) ) {
F_192 ( & V_23 -> V_451 ) ;
F_165 ( & V_180 ) ;
F_186 ( V_23 ) ;
F_164 ( & V_180 ) ;
}
F_165 ( & V_180 ) ;
F_193 ( V_354 ) ;
}
static void F_194 ( struct V_63 * V_64 )
{
V_64 -> V_453 = & V_454 ;
V_64 -> V_455 = V_456 ;
F_195 ( V_64 ) ;
V_64 -> V_457 = 0 ;
V_64 -> type = V_458 ;
memset ( V_64 -> V_459 , 0 , V_38 ) ;
V_64 -> V_459 [ 0 ] = 0x12 ;
}
static struct V_22 * F_196 ( const T_1 * V_8 )
{
struct V_22 * V_23 ;
bool V_460 = false ;
F_164 ( & V_180 ) ;
F_81 (data, &hwsim_radios, list) {
if ( memcmp ( V_23 -> V_137 [ 1 ] . V_8 , V_8 , V_38 ) == 0 ) {
V_460 = true ;
break;
}
}
F_165 ( & V_180 ) ;
if ( ! V_460 )
return NULL ;
return V_23 ;
}
static int F_197 ( struct V_24 * V_461 ,
struct V_462 * V_80 )
{
struct V_44 * V_45 ;
struct V_22 * V_158 ;
struct V_79 * V_190 ;
struct V_125 * V_126 ;
unsigned long V_463 ;
struct V_24 * V_25 , * V_464 ;
const T_1 * V_465 ;
unsigned int V_123 ;
int V_124 ;
bool V_466 = false ;
if ( V_80 -> V_467 != V_196 )
return - V_59 ;
if ( ! V_80 -> V_468 [ V_136 ] ||
! V_80 -> V_468 [ V_144 ] ||
! V_80 -> V_468 [ V_150 ] ||
! V_80 -> V_468 [ V_149 ] )
goto V_222;
V_465 = ( void * ) F_198 ( V_80 -> V_468 [ V_136 ] ) ;
V_123 = F_128 ( V_80 -> V_468 [ V_144 ] ) ;
V_463 = F_199 ( V_80 -> V_468 [ V_150 ] ) ;
V_158 = F_196 ( V_465 ) ;
if ( ! V_158 )
goto V_222;
F_200 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_25 == V_463 ) {
F_201 ( V_25 , & V_158 -> V_128 ) ;
V_466 = true ;
break;
}
}
if ( ! V_466 )
goto V_222;
V_126 = (struct V_125 * ) F_198 (
V_80 -> V_468 [ V_149 ] ) ;
V_190 = F_43 ( V_25 ) ;
F_95 ( V_190 ) ;
for ( V_124 = 0 ; V_124 < V_127 ; V_124 ++ ) {
V_190 -> V_146 . V_147 [ V_124 ] . V_145 = V_126 [ V_124 ] . V_145 ;
V_190 -> V_146 . V_147 [ V_124 ] . V_148 = V_126 [ V_124 ] . V_148 ;
}
V_190 -> V_146 . V_469 = F_128 ( V_80 -> V_468 [ V_470 ] ) ;
if ( ! ( V_123 & V_143 ) &&
( V_123 & V_471 ) ) {
if ( V_25 -> V_139 >= 16 ) {
V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_52 ( V_158 -> V_156 ,
V_45 -> V_50 ) ;
}
V_190 -> V_78 |= V_197 ;
}
F_96 ( V_158 -> V_29 , V_25 ) ;
return 0 ;
V_222:
return - V_59 ;
}
static int F_202 ( struct V_24 * V_461 ,
struct V_462 * V_80 )
{
struct V_22 * V_158 ;
struct V_160 V_161 ;
const T_1 * V_472 ;
int V_473 ;
void * V_474 ;
struct V_24 * V_25 = NULL ;
if ( V_80 -> V_467 != V_196 )
return - V_59 ;
if ( ! V_80 -> V_468 [ V_475 ] ||
! V_80 -> V_468 [ V_138 ] ||
! V_80 -> V_468 [ V_476 ] ||
! V_80 -> V_468 [ V_470 ] )
goto V_222;
V_472 = ( void * ) F_198 ( V_80 -> V_468 [ V_475 ] ) ;
V_473 = F_203 ( V_80 -> V_468 [ V_138 ] ) ;
V_474 = ( void * ) F_198 ( V_80 -> V_468 [ V_138 ] ) ;
V_25 = F_204 ( V_473 , V_477 ) ;
if ( V_25 == NULL )
goto V_291;
if ( V_473 > V_362 )
goto V_291;
memcpy ( F_15 ( V_25 , V_473 ) , V_474 , V_473 ) ;
V_158 = F_196 ( V_472 ) ;
if ( ! V_158 )
goto V_222;
if ( V_158 -> V_183 || ! V_158 -> V_182 )
goto V_222;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_164 = V_158 -> V_156 -> V_99 ;
V_161 . V_165 = V_158 -> V_156 -> V_165 ;
V_161 . V_168 = F_128 ( V_80 -> V_468 [ V_476 ] ) ;
V_161 . signal = F_128 ( V_80 -> V_468 [ V_470 ] ) ;
memcpy ( F_87 ( V_25 ) , & V_161 , sizeof( V_161 ) ) ;
F_88 ( V_158 -> V_29 , V_25 ) ;
return 0 ;
V_291:
F_62 ( V_135 L_5 , V_31 ) ;
goto V_222;
V_222:
F_32 ( V_25 ) ;
return - V_59 ;
}
static int F_205 ( struct V_24 * V_461 ,
struct V_462 * V_80 )
{
struct V_22 * V_23 ;
int V_478 = 1 ;
F_164 ( & V_180 ) ;
F_81 (data, &hwsim_radios, list)
V_478 = F_206 ( V_478 , V_23 -> V_327 ) ;
F_165 ( & V_180 ) ;
if ( V_478 > 1 )
return - V_300 ;
if ( V_196 )
return - V_336 ;
V_196 = V_80 -> V_467 ;
F_62 ( V_135 L_55
L_56 , V_80 -> V_467 ) ;
return 0 ;
}
static int F_207 ( struct V_24 * V_479 , struct V_462 * V_80 )
{
unsigned int V_478 = V_327 ;
const char * V_480 = NULL ;
const struct V_343 * V_344 = NULL ;
bool V_345 = V_80 -> V_468 [ V_481 ] ;
bool V_346 = V_80 -> V_468 [ V_482 ] ;
bool V_192 ;
if ( V_80 -> V_468 [ V_483 ] )
V_478 = F_128 ( V_80 -> V_468 [ V_483 ] ) ;
if ( V_80 -> V_468 [ V_484 ] )
V_192 = true ;
else
V_192 = ( V_478 > 1 ) ;
if ( V_80 -> V_468 [ V_485 ] )
V_480 = F_198 ( V_80 -> V_468 [ V_485 ] ) ;
if ( V_80 -> V_468 [ V_486 ] ) {
T_5 V_145 = F_128 ( V_80 -> V_468 [ V_486 ] ) ;
if ( V_145 >= F_93 ( V_487 ) )
return - V_59 ;
V_344 = V_487 [ V_145 ] ;
}
return F_163 ( V_478 , V_480 , V_344 , V_345 ,
V_346 , V_192 ) ;
}
static int F_208 ( struct V_24 * V_479 , struct V_462 * V_80 )
{
struct V_22 * V_23 ;
int V_145 ;
if ( ! V_80 -> V_468 [ V_488 ] )
return - V_59 ;
V_145 = F_128 ( V_80 -> V_468 [ V_488 ] ) ;
F_164 ( & V_180 ) ;
F_81 (data, &hwsim_radios, list) {
if ( V_23 -> V_145 != V_145 )
continue;
F_192 ( & V_23 -> V_451 ) ;
F_165 ( & V_180 ) ;
F_186 ( V_23 ) ;
return 0 ;
}
F_165 ( & V_180 ) ;
return - V_489 ;
}
static int F_209 ( struct V_490 * V_491 ,
unsigned long V_492 ,
void * V_493 )
{
struct V_494 * V_495 = V_493 ;
if ( V_492 != V_496 )
return V_497 ;
if ( V_495 -> V_498 == V_196 ) {
F_62 ( V_499 L_57
L_58 ) ;
V_196 = 0 ;
}
return V_497 ;
}
static int F_210 ( void )
{
int V_500 ;
F_62 ( V_499 L_59 ) ;
V_500 = F_211 ( & V_133 , V_501 ) ;
if ( V_500 )
goto V_502;
V_500 = F_212 ( & V_503 ) ;
if ( V_500 )
goto V_502;
return 0 ;
V_502:
F_62 ( V_135 L_5 , V_31 ) ;
return - V_59 ;
}
static void F_213 ( void )
{
F_214 ( & V_503 ) ;
F_215 ( & V_133 ) ;
}
static int T_9 F_216 ( void )
{
int V_124 , V_291 ;
if ( V_504 < 0 || V_504 > 100 )
return - V_59 ;
if ( V_327 < 1 )
return - V_59 ;
V_352 = V_350 ;
V_352 . V_318 = F_148 ;
V_352 . V_505 = F_149 ;
V_352 . V_506 = NULL ;
V_352 . V_507 = NULL ;
V_352 . V_508 = F_155 ;
V_352 . V_509 = F_157 ;
V_352 . V_510 = F_158 ;
V_352 . V_511 = F_159 ;
V_352 . V_512 = F_160 ;
V_352 . V_513 =
F_161 ;
V_352 . V_514 =
F_162 ;
F_217 ( & V_180 ) ;
F_218 ( & V_452 ) ;
V_291 = F_219 ( & V_357 ) ;
if ( V_291 )
return V_291 ;
V_354 = F_220 ( V_515 , L_60 ) ;
if ( F_168 ( V_354 ) ) {
V_291 = F_169 ( V_354 ) ;
goto V_516;
}
for ( V_124 = 0 ; V_124 < V_504 ; V_124 ++ ) {
const char * V_342 = NULL ;
const struct V_343 * V_344 = NULL ;
bool V_345 = false ;
switch ( V_517 ) {
case V_518 :
if ( V_124 < F_93 ( V_519 ) )
V_342 = V_519 [ V_124 ] ;
break;
case V_520 :
if ( ! V_124 )
V_342 = V_519 [ 0 ] ;
break;
case V_521 :
V_345 = true ;
case V_522 :
V_342 = V_519 [ 0 ] ;
break;
case V_523 :
if ( V_124 == 0 )
V_344 = & V_524 ;
break;
case V_525 :
V_344 = & V_524 ;
break;
case V_526 :
if ( V_124 == 0 )
V_344 = & V_524 ;
else if ( V_124 == 1 )
V_344 = & V_527 ;
break;
case V_528 :
if ( V_124 == 0 ) {
V_345 = true ;
V_342 = V_519 [ 0 ] ;
}
break;
case V_529 :
if ( V_124 == 0 ) {
V_345 = true ;
V_342 = V_519 [ 0 ] ;
} else if ( V_124 == 1 ) {
V_342 = V_519 [ 1 ] ;
}
break;
case V_530 :
switch ( V_124 ) {
case 0 :
V_344 = & V_524 ;
break;
case 1 :
V_344 = & V_527 ;
break;
case 2 :
V_342 = V_519 [ 0 ] ;
break;
case 3 :
V_342 = V_519 [ 1 ] ;
break;
case 4 :
V_345 = true ;
V_342 = V_519 [ 2 ] ;
break;
}
break;
default:
break;
}
V_291 = F_163 ( V_327 , V_342 ,
V_344 , V_345 ,
V_531 ,
V_327 > 1 ) ;
if ( V_291 < 0 )
goto V_532;
}
V_83 = F_221 ( 0 , L_46 , F_194 ) ;
if ( V_83 == NULL ) {
V_291 = - V_297 ;
goto V_532;
}
F_222 () ;
V_291 = F_223 ( V_83 , V_83 -> V_533 ) ;
if ( V_291 < 0 ) {
F_224 () ;
goto V_532;
}
V_291 = F_225 ( V_83 ) ;
if ( V_291 < 0 ) {
F_224 () ;
goto V_534;
}
F_224 () ;
V_291 = F_210 () ;
if ( V_291 < 0 )
goto V_534;
return 0 ;
V_534:
V_456 ( V_83 ) ;
V_532:
F_190 () ;
V_516:
F_226 ( & V_357 ) ;
return V_291 ;
}
static void T_10 F_227 ( void )
{
F_62 ( V_135 L_61 ) ;
F_213 () ;
F_190 () ;
F_228 ( V_83 ) ;
F_226 ( & V_357 ) ;
}
