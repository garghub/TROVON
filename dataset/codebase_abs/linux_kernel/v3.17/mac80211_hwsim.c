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
T_2 V_73 = F_41 ( V_70 - V_66 ) ;
if ( V_70 > V_66 ) {
V_23 -> V_67 += V_73 ;
V_23 -> V_74 = F_42 ( V_73 , V_71 ) ;
} else {
V_23 -> V_67 -= V_73 ;
V_23 -> V_74 = - F_42 ( V_73 , V_71 ) ;
}
}
static void F_43 ( struct V_68 * V_29 ,
struct V_24 * V_75 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_24 * V_25 ;
struct V_77 * V_45 ;
T_6 V_78 ;
struct V_79 * V_80 = F_44 ( V_75 ) ;
struct V_81 * V_82 = F_45 ( V_29 , V_80 ) ;
if ( ! F_46 ( V_83 ) )
return;
V_25 = F_47 ( V_75 , sizeof( * V_45 ) , 0 , V_84 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_77 * ) F_48 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_49 ( ( 1 << V_90 ) |
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
F_50 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_51 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_52 ( V_25 ) ;
}
static void F_53 ( struct V_76 * V_42 ,
const T_1 * V_8 )
{
struct V_24 * V_25 ;
struct V_112 * V_45 ;
T_6 V_78 ;
struct V_44 * V_113 ;
if ( ! F_46 ( V_83 ) )
return;
V_25 = F_14 ( 100 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_112 * ) F_15 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_49 ( ( 1 << V_90 ) |
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
F_50 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_51 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_52 ( V_25 ) ;
}
static void F_54 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_116 * V_117 = V_23 ;
if ( memcmp ( V_21 , V_117 -> V_8 , V_38 ) == 0 )
V_117 -> V_118 = true ;
}
static bool F_55 ( struct V_22 * V_23 ,
const T_1 * V_8 )
{
struct V_116 V_117 = {
. V_118 = false ,
} ;
memcpy ( V_117 . V_8 , V_8 , V_38 ) ;
F_56 ( V_23 -> V_29 ,
V_60 ,
F_54 ,
& V_117 ) ;
return V_117 . V_118 ;
}
static bool F_57 ( struct V_22 * V_23 ,
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
F_55 ( V_23 , V_25 -> V_23 + 4 ) ) {
V_23 -> V_61 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_58 ( struct V_68 * V_29 ,
struct V_24 * V_119 ,
int V_120 )
{
struct V_24 * V_25 ;
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_44 * V_45 = (struct V_44 * ) V_119 -> V_23 ;
struct V_79 * V_80 = F_44 ( V_119 ) ;
void * V_121 ;
unsigned int V_122 = 0 ;
int V_123 ;
struct V_124 V_125 [ V_126 ] ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
if ( F_59 ( & V_23 -> V_127 ) >= V_128 ) {
while ( F_59 ( & V_23 -> V_127 ) >= V_129 )
F_60 ( & V_23 -> V_127 ) ;
}
V_25 = F_61 ( V_130 , V_84 ) ;
if ( V_25 == NULL )
goto V_131;
V_121 = F_62 ( V_25 , 0 , 0 , & V_132 , 0 ,
V_133 ) ;
if ( V_121 == NULL ) {
F_63 ( V_134 L_4 ) ;
goto V_131;
}
if ( F_64 ( V_25 , V_135 ,
V_38 , V_23 -> V_136 [ 1 ] . V_8 ) )
goto V_131;
if ( F_64 ( V_25 , V_137 , V_119 -> V_138 , V_119 -> V_23 ) )
goto V_131;
if ( V_80 -> V_78 & V_139 )
V_122 |= V_140 ;
if ( V_80 -> V_78 & V_141 )
V_122 |= V_142 ;
if ( F_65 ( V_25 , V_143 , V_122 ) )
goto V_131;
for ( V_123 = 0 ; V_123 < V_126 ; V_123 ++ ) {
V_125 [ V_123 ] . V_144 = V_80 -> V_145 . V_146 [ V_123 ] . V_144 ;
V_125 [ V_123 ] . V_147 = V_80 -> V_145 . V_146 [ V_123 ] . V_147 ;
}
if ( F_64 ( V_25 , V_148 ,
sizeof( struct V_124 ) * V_126 ,
V_125 ) )
goto V_131;
if ( F_66 ( V_25 , V_149 , ( unsigned long ) V_119 ) )
goto V_131;
F_67 ( V_25 , V_121 ) ;
F_68 ( & V_150 , V_25 , V_120 ) ;
F_69 ( & V_23 -> V_127 , V_119 ) ;
return;
V_131:
F_63 ( V_134 L_5 , V_31 ) ;
}
static bool F_70 ( struct V_76 * V_151 ,
struct V_76 * V_152 )
{
if ( ! V_151 || ! V_152 )
return false ;
return V_151 -> V_99 == V_152 -> V_99 ;
}
static void F_71 ( void * V_153 , T_1 * V_8 ,
struct V_1 * V_2 )
{
struct V_154 * V_23 = V_153 ;
if ( ! V_2 -> V_40 )
return;
if ( ! F_70 ( V_23 -> V_155 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) )
return;
V_23 -> V_156 = true ;
}
static bool F_72 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 , * V_157 ;
bool V_158 = false ;
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
struct V_79 * V_80 = F_44 ( V_25 ) ;
struct V_159 V_160 ;
T_2 V_66 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
V_160 . V_161 |= V_162 ;
V_160 . V_163 = V_42 -> V_99 ;
V_160 . V_164 = V_42 -> V_164 ;
if ( V_80 -> V_165 . V_146 [ 0 ] . V_78 & V_166 ) {
V_160 . V_167 =
F_73 ( & V_80 -> V_165 . V_146 [ 0 ] ) ;
V_160 . V_168 =
F_74 ( & V_80 -> V_165 . V_146 [ 0 ] ) ;
V_160 . V_161 |= V_169 ;
} else {
V_160 . V_167 = V_80 -> V_165 . V_146 [ 0 ] . V_144 ;
if ( V_80 -> V_165 . V_146 [ 0 ] . V_78 & V_170 )
V_160 . V_161 |= V_171 ;
}
if ( V_80 -> V_165 . V_146 [ 0 ] . V_78 & V_172 )
V_160 . V_161 |= V_173 ;
if ( V_80 -> V_165 . V_146 [ 0 ] . V_78 & V_174 )
V_160 . V_161 |= V_175 ;
V_160 . signal = V_23 -> V_176 - 50 ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
F_75 ( V_25 ) ;
F_76 ( V_25 ) ;
V_25 -> V_177 = 0 ;
F_77 ( V_25 ) ;
F_78 ( V_25 ) ;
if ( F_79 ( V_45 -> V_34 ) ||
F_80 ( V_45 -> V_34 ) )
V_66 = V_23 -> V_178 ;
else
V_66 = F_33 () ;
F_81 ( & V_179 ) ;
F_82 (data2, &hwsim_radios, list) {
struct V_24 * V_180 ;
struct V_154 V_154 = {
. V_156 = false ,
. V_155 = V_42 ,
} ;
if ( V_23 == V_157 )
continue;
if ( ! V_157 -> V_181 || ( V_157 -> V_182 && ! V_157 -> V_183 ) ||
! F_57 ( V_157 , V_25 ) )
continue;
if ( ! ( V_23 -> V_62 & V_157 -> V_62 ) )
continue;
if ( ! F_70 ( V_42 , V_157 -> V_183 ) &&
! F_70 ( V_42 , V_157 -> V_155 ) ) {
F_56 (
V_157 -> V_29 , V_60 ,
F_71 , & V_154 ) ;
if ( ! V_154 . V_156 )
continue;
}
if ( V_25 -> V_138 < V_184 && V_185 ) {
struct V_186 * V_186 = F_83 ( V_84 ) ;
if ( ! V_186 )
continue;
V_180 = F_14 ( 128 ) ;
if ( ! V_180 ) {
F_84 ( V_186 ) ;
continue;
}
memcpy ( F_85 ( V_186 ) , V_25 -> V_23 , V_25 -> V_138 ) ;
F_86 ( V_180 , 0 , V_186 , 0 , V_25 -> V_138 , V_25 -> V_138 ) ;
} else {
V_180 = F_87 ( V_25 , V_84 ) ;
if ( ! V_180 )
continue;
}
if ( F_55 ( V_157 , V_45 -> V_49 ) )
V_158 = true ;
V_160 . V_187 = V_66 + V_157 -> V_67 ;
memcpy ( F_88 ( V_180 ) , & V_160 , sizeof( V_160 ) ) ;
F_89 ( V_157 -> V_29 , V_180 ) ;
}
F_90 ( & V_179 ) ;
return V_158 ;
}
static void F_91 ( struct V_68 * V_29 ,
struct V_188 * V_165 ,
struct V_24 * V_25 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_79 * V_189 = F_44 ( V_25 ) ;
struct V_15 * V_40 ;
struct V_76 * V_155 ;
bool V_158 ;
T_5 V_190 ;
if ( F_6 ( V_25 -> V_138 < 10 ) ) {
F_92 ( V_29 , V_25 ) ;
return;
}
if ( ! V_23 -> V_191 ) {
V_155 = V_23 -> V_155 ;
} else if ( V_189 -> V_192 == 4 ) {
V_155 = V_23 -> V_183 ;
} else {
V_40 = F_19 ( V_189 -> V_165 . V_2 -> V_40 ) ;
if ( V_40 )
V_155 = V_40 -> V_41 . V_42 ;
else
V_155 = NULL ;
}
if ( F_2 ( ! V_155 , L_6 , V_189 -> V_192 ) ) {
F_92 ( V_29 , V_25 ) ;
return;
}
if ( V_23 -> V_182 && ! V_23 -> V_183 ) {
F_13 ( V_29 -> V_30 , L_7 ) ;
F_92 ( V_29 , V_25 ) ;
return;
}
if ( V_189 -> V_165 . V_2 )
F_1 ( V_189 -> V_165 . V_2 ) ;
if ( V_165 -> V_11 )
F_5 ( V_165 -> V_11 ) ;
if ( V_29 -> V_78 & V_193 )
F_93 ( V_189 -> V_165 . V_2 , V_165 -> V_11 , V_25 ,
V_189 -> V_165 . V_146 ,
F_94 ( V_189 -> V_165 . V_146 ) ) ;
V_189 -> V_194 [ 0 ] = V_155 ;
F_43 ( V_29 , V_25 , V_155 ) ;
V_190 = F_95 ( V_195 ) ;
if ( V_190 )
return F_58 ( V_29 , V_25 , V_190 ) ;
V_158 = F_72 ( V_29 , V_25 , V_155 ) ;
if ( V_158 && V_25 -> V_138 >= 16 ) {
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_53 ( V_155 , V_45 -> V_50 ) ;
}
F_96 ( V_189 ) ;
V_189 -> V_165 . V_146 [ 0 ] . V_147 = 1 ;
V_189 -> V_165 . V_146 [ 1 ] . V_144 = - 1 ;
if ( ! ( V_189 -> V_78 & V_141 ) && V_158 )
V_189 -> V_78 |= V_196 ;
F_97 ( V_29 , V_25 ) ;
}
static int F_98 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_8 , V_31 ) ;
V_23 -> V_181 = true ;
return 0 ;
}
static void F_99 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
V_23 -> V_181 = false ;
F_100 ( & V_23 -> V_197 ) ;
F_13 ( V_29 -> V_30 , L_8 , V_31 ) ;
}
static int F_101 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_9 ,
V_31 , F_102 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_198 = 0 ;
V_2 -> V_192 [ V_199 ] = 0 ;
V_2 -> V_192 [ V_200 ] = 1 ;
V_2 -> V_192 [ V_201 ] = 2 ;
V_2 -> V_192 [ V_202 ] = 3 ;
return 0 ;
}
static int F_103 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_203 V_204 ,
bool V_205 )
{
V_204 = F_104 ( V_204 , V_205 ) ;
F_13 ( V_29 -> V_30 ,
L_10 ,
V_31 , F_102 ( V_2 ) ,
V_204 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_198 = 0 ;
return 0 ;
}
static void F_105 (
struct V_68 * V_29 , struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_9 ,
V_31 , F_102 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_18 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
T_5 V_206 = F_95 ( V_195 ) ;
if ( V_29 -> V_78 & V_193 ) {
struct V_79 * V_189 = F_44 ( V_25 ) ;
F_93 ( V_189 -> V_165 . V_2 , NULL , V_25 ,
V_189 -> V_165 . V_146 ,
F_94 ( V_189 -> V_165 . V_146 ) ) ;
}
F_43 ( V_29 , V_25 , V_42 ) ;
if ( V_206 )
return F_58 ( V_29 , V_25 , V_206 ) ;
F_72 ( V_29 , V_25 , V_42 ) ;
F_32 ( V_25 ) ;
}
static void F_106 ( void * V_207 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_207 ;
struct V_68 * V_29 = V_23 -> V_29 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_208 * V_209 ;
struct V_24 * V_25 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_210 &&
V_2 -> type != V_211 &&
V_2 -> type != V_212 )
return;
V_25 = F_107 ( V_29 , V_2 ) ;
if ( V_25 == NULL )
return;
V_80 = F_44 ( V_25 ) ;
if ( V_29 -> V_78 & V_193 )
F_93 ( V_2 , NULL , V_25 ,
V_80 -> V_165 . V_146 ,
F_94 ( V_80 -> V_165 . V_146 ) ) ;
V_82 = F_45 ( V_29 , V_80 ) ;
V_209 = (struct V_208 * ) V_25 -> V_23 ;
V_23 -> V_178 = F_33 () ;
V_209 -> V_213 . V_214 . V_215 = F_37 ( V_23 -> V_178 +
V_23 -> V_67 +
24 * 8 * 10 / V_82 -> V_97 ) ;
F_18 ( V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
if ( V_2 -> V_216 && F_108 ( V_2 ) )
F_109 ( V_2 ) ;
}
static enum V_217
F_110 ( struct V_218 * V_219 )
{
struct V_22 * V_23 =
F_111 ( V_219 , struct V_22 ,
V_197 . V_219 ) ;
struct V_68 * V_29 = V_23 -> V_29 ;
T_2 V_71 = V_23 -> V_72 ;
T_7 V_220 ;
if ( ! V_23 -> V_181 )
goto V_221;
F_56 (
V_29 , V_60 ,
F_106 , V_23 ) ;
if ( V_23 -> V_74 ) {
V_71 -= V_23 -> V_74 ;
V_23 -> V_74 = 0 ;
}
V_220 = F_112 ( F_113 ( V_219 ) ,
F_114 ( V_71 * 1000 ) ) ;
F_115 ( & V_23 -> V_197 , V_220 , V_222 ) ;
V_221:
return V_223 ;
}
static int F_116 ( struct V_68 * V_29 , T_5 V_224 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_225 * V_226 = & V_29 -> V_226 ;
static const char * V_227 [ V_228 ] = {
[ V_229 ] = L_11 ,
[ V_230 ] = L_12 ,
[ V_231 ] = L_13 ,
[ V_232 ] = L_14 ,
} ;
if ( V_226 -> V_233 . V_42 )
F_13 ( V_29 -> V_30 ,
L_15 ,
V_31 ,
V_226 -> V_233 . V_42 -> V_99 ,
V_226 -> V_233 . V_234 ,
V_226 -> V_233 . V_235 ,
V_236 [ V_226 -> V_233 . V_237 ] ,
! ! ( V_226 -> V_78 & V_238 ) ,
! ! ( V_226 -> V_78 & V_239 ) ,
V_227 [ V_226 -> V_240 ] ) ;
else
F_13 ( V_29 -> V_30 ,
L_16 ,
V_31 ,
! ! ( V_226 -> V_78 & V_238 ) ,
! ! ( V_226 -> V_78 & V_239 ) ,
V_227 [ V_226 -> V_240 ] ) ;
V_23 -> V_182 = ! ! ( V_226 -> V_78 & V_238 ) ;
V_23 -> V_155 = V_226 -> V_233 . V_42 ;
F_6 ( V_23 -> V_155 && V_23 -> V_191 ) ;
V_23 -> V_176 = V_226 -> V_176 ;
if ( ! V_23 -> V_181 || ! V_23 -> V_72 )
F_100 ( & V_23 -> V_197 ) ;
else if ( ! F_117 ( & V_23 -> V_197 . V_219 ) ) {
T_2 V_70 = F_38 ( V_29 , NULL ) ;
T_5 V_71 = V_23 -> V_72 ;
T_2 V_241 = V_71 - F_42 ( V_70 , V_71 ) ;
F_115 ( & V_23 -> V_197 ,
F_114 ( V_241 * 1000 ) ,
V_242 ) ;
}
return 0 ;
}
static void F_118 ( struct V_68 * V_29 ,
unsigned int V_243 ,
unsigned int * V_244 , T_2 V_245 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_8 , V_31 ) ;
V_23 -> V_246 = 0 ;
if ( * V_244 & V_247 )
V_23 -> V_246 |= V_247 ;
if ( * V_244 & V_248 )
V_23 -> V_246 |= V_248 ;
* V_244 = V_23 -> V_246 ;
}
static void F_119 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
unsigned int * V_147 = V_23 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_249 )
( * V_147 ) ++ ;
}
static void F_120 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_250 * V_80 ,
T_5 V_224 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_22 * V_23 = V_29 -> V_69 ;
F_1 ( V_2 ) ;
F_13 ( V_29 -> V_30 , L_17 ,
V_31 , V_224 , V_2 -> V_8 ) ;
if ( V_224 & V_251 ) {
F_13 ( V_29 -> V_30 , L_18 ,
V_31 , V_80 -> V_32 ) ;
memcpy ( V_4 -> V_32 , V_80 -> V_32 , V_38 ) ;
}
if ( V_224 & V_252 ) {
F_13 ( V_29 -> V_30 , L_19 ,
V_80 -> V_28 , V_80 -> V_33 ) ;
V_4 -> V_28 = V_80 -> V_28 ;
V_4 -> V_33 = V_80 -> V_33 ;
}
if ( V_224 & V_253 ) {
F_13 ( V_29 -> V_30 , L_20 , V_80 -> V_72 ) ;
V_23 -> V_72 = V_80 -> V_72 * 1024 ;
}
if ( V_224 & V_254 ) {
F_13 ( V_29 -> V_30 , L_21 , V_80 -> V_255 ) ;
V_4 -> V_249 = V_80 -> V_255 ;
if ( V_23 -> V_181 &&
! F_117 ( & V_23 -> V_197 . V_219 ) &&
V_80 -> V_255 ) {
T_2 V_70 , V_241 ;
T_5 V_71 ;
if ( F_6 ( ! V_23 -> V_72 ) )
V_23 -> V_72 = 1000 * 1024 ;
V_70 = F_38 ( V_29 , V_2 ) ;
V_71 = V_23 -> V_72 ;
V_241 = V_71 - F_42 ( V_70 , V_71 ) ;
F_115 ( & V_23 -> V_197 ,
F_114 ( V_241 * 1000 ) ,
V_242 ) ;
} else if ( ! V_80 -> V_255 ) {
unsigned int V_147 = 0 ;
F_56 (
V_23 -> V_29 , V_60 ,
F_119 , & V_147 ) ;
F_13 ( V_29 -> V_30 , L_22 ,
V_147 ) ;
if ( V_147 == 0 )
F_100 ( & V_23 -> V_197 ) ;
}
}
if ( V_224 & V_256 ) {
F_13 ( V_29 -> V_30 , L_23 ,
V_80 -> V_257 ) ;
}
if ( V_224 & V_258 ) {
F_13 ( V_29 -> V_30 , L_24 ,
V_80 -> V_259 ) ;
}
if ( V_224 & V_260 ) {
F_13 ( V_29 -> V_30 , L_25 , V_80 -> V_261 ) ;
}
if ( V_224 & V_262 ) {
F_13 ( V_29 -> V_30 , L_26 ,
V_80 -> V_263 ) ;
}
if ( V_224 & V_264 ) {
F_13 ( V_29 -> V_30 , L_27 ,
( unsigned long long ) V_80 -> V_265 ) ;
}
if ( V_224 & V_266 )
F_13 ( V_29 -> V_30 , L_28 , V_80 -> V_267 ) ;
}
static int F_121 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_122 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_123 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_268 V_269 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_269 ) {
case V_270 :
case V_271 :
break;
default:
F_2 ( 1 , L_29 , V_269 ) ;
break;
}
}
static int F_124 ( struct V_68 * V_29 ,
struct V_10 * V_11 ,
bool V_272 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_125 (
struct V_68 * V_29 ,
struct V_1 * V_2 , T_6 V_273 ,
const struct V_274 * V_275 )
{
F_13 ( V_29 -> V_30 ,
L_30 ,
V_31 , V_273 ,
V_275 -> V_276 , V_275 -> V_277 ,
V_275 -> V_278 , V_275 -> V_279 ) ;
return 0 ;
}
static int F_126 (
struct V_68 * V_29 , int V_144 ,
struct V_280 * V_281 )
{
struct V_225 * V_226 = & V_29 -> V_226 ;
F_13 ( V_29 -> V_30 , L_31 , V_31 , V_144 ) ;
if ( V_144 != 0 )
return - V_282 ;
V_281 -> V_155 = V_226 -> V_233 . V_42 ;
V_281 -> V_283 = V_284 ;
V_281 -> V_285 = - 92 ;
return 0 ;
}
static int F_127 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
void * V_23 , int V_138 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
struct V_287 * V_288 [ V_289 + 1 ] ;
struct V_24 * V_25 ;
int V_290 , V_43 ;
V_290 = F_128 ( V_288 , V_289 , V_23 , V_138 ,
V_291 ) ;
if ( V_290 )
return V_290 ;
if ( ! V_288 [ V_292 ] )
return - V_59 ;
switch ( F_129 ( V_288 [ V_292 ] ) ) {
case V_293 :
if ( ! V_288 [ V_294 ] )
return - V_59 ;
V_43 = F_129 ( V_288 [ V_294 ] ) ;
return F_25 ( V_286 , V_43 ) ;
case V_295 :
V_25 = F_130 ( V_29 -> V_30 ,
F_131 ( sizeof( T_5 ) ) ) ;
if ( ! V_25 )
return - V_296 ;
if ( F_65 ( V_25 , V_294 , V_286 -> V_43 ) )
goto V_131;
return F_132 ( V_25 ) ;
case V_297 :
F_133 ( V_29 ) ;
return 0 ;
case V_298 :
F_134 ( V_29 ) ;
return 0 ;
default:
return - V_299 ;
}
V_131:
F_135 ( V_25 ) ;
return - V_300 ;
}
static int F_136 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_301 V_302 ,
struct V_10 * V_11 , T_6 V_303 , T_6 * V_304 ,
T_1 V_305 )
{
switch ( V_302 ) {
case V_306 :
F_137 ( V_2 , V_11 -> V_8 , V_303 ) ;
break;
case V_307 :
case V_308 :
case V_309 :
F_138 ( V_2 , V_11 -> V_8 , V_303 ) ;
break;
case V_310 :
break;
case V_311 :
case V_312 :
break;
default:
return - V_299 ;
}
return 0 ;
}
static void F_139 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
T_5 V_313 , bool V_314 )
{
}
static void F_140 ( struct V_315 * V_316 )
{
struct V_22 * V_286 =
F_111 ( V_316 , struct V_22 , V_317 . V_316 ) ;
struct V_318 * V_319 = V_286 -> V_320 ;
int V_321 , V_123 ;
F_141 ( & V_286 -> V_322 ) ;
if ( V_286 -> V_323 >= V_319 -> V_324 ) {
F_13 ( V_286 -> V_29 -> V_30 , L_32 ) ;
F_142 ( V_286 -> V_29 , false ) ;
V_286 -> V_320 = NULL ;
V_286 -> V_325 = NULL ;
V_286 -> V_183 = NULL ;
F_143 ( & V_286 -> V_322 ) ;
return;
}
F_13 ( V_286 -> V_29 -> V_30 , L_33 ,
V_319 -> V_326 [ V_286 -> V_323 ] -> V_99 ) ;
V_286 -> V_183 = V_319 -> V_326 [ V_286 -> V_323 ] ;
if ( V_286 -> V_183 -> V_78 & V_327 ||
! V_319 -> V_328 ) {
V_321 = 120 ;
} else {
V_321 = 30 ;
for ( V_123 = 0 ; V_123 < V_319 -> V_328 ; V_123 ++ ) {
struct V_24 * V_329 ;
V_329 = F_144 ( V_286 -> V_29 ,
V_286 -> V_325 ,
V_319 -> V_330 [ V_123 ] . V_331 ,
V_319 -> V_330 [ V_123 ] . V_332 ,
V_319 -> V_333 ) ;
if ( ! V_329 )
continue;
if ( V_319 -> V_333 )
memcpy ( F_15 ( V_329 , V_319 -> V_333 ) , V_319 -> V_334 ,
V_319 -> V_333 ) ;
F_145 () ;
F_18 ( V_286 -> V_29 , V_329 ,
V_286 -> V_183 ) ;
F_146 () ;
}
}
F_147 ( V_286 -> V_29 , & V_286 -> V_317 ,
F_148 ( V_321 ) ) ;
V_286 -> V_323 ++ ;
F_143 ( & V_286 -> V_322 ) ;
}
static int F_149 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_335 * V_336 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
struct V_318 * V_319 = & V_336 -> V_319 ;
F_141 ( & V_286 -> V_322 ) ;
if ( F_6 ( V_286 -> V_183 || V_286 -> V_320 ) ) {
F_143 ( & V_286 -> V_322 ) ;
return - V_337 ;
}
V_286 -> V_320 = V_319 ;
V_286 -> V_325 = V_2 ;
V_286 -> V_323 = 0 ;
F_143 ( & V_286 -> V_322 ) ;
F_13 ( V_29 -> V_30 , L_34 ) ;
F_147 ( V_286 -> V_29 , & V_286 -> V_317 , 0 ) ;
return 0 ;
}
static void F_150 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_35 ) ;
F_151 ( & V_286 -> V_317 ) ;
F_141 ( & V_286 -> V_322 ) ;
F_142 ( V_286 -> V_29 , true ) ;
V_286 -> V_183 = NULL ;
V_286 -> V_320 = NULL ;
V_286 -> V_325 = NULL ;
F_143 ( & V_286 -> V_322 ) ;
}
static void F_152 ( struct V_68 * V_29 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_141 ( & V_286 -> V_322 ) ;
if ( V_286 -> V_338 ) {
F_63 ( V_134 L_36 ) ;
goto V_221;
}
F_63 ( V_134 L_37 ) ;
V_286 -> V_338 = true ;
V_221:
F_143 ( & V_286 -> V_322 ) ;
}
static void F_153 ( struct V_68 * V_29 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_141 ( & V_286 -> V_322 ) ;
F_63 ( V_134 L_38 ) ;
V_286 -> V_338 = false ;
F_143 ( & V_286 -> V_322 ) ;
}
static void F_154 ( struct V_315 * V_316 )
{
struct V_22 * V_286 =
F_111 ( V_316 , struct V_22 , V_339 . V_316 ) ;
F_141 ( & V_286 -> V_322 ) ;
F_155 ( V_286 -> V_29 ) ;
V_286 -> V_183 = NULL ;
F_143 ( & V_286 -> V_322 ) ;
F_13 ( V_286 -> V_29 -> V_30 , L_39 ) ;
}
static int F_156 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_76 * V_42 ,
int V_340 ,
enum V_341 type )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_141 ( & V_286 -> V_322 ) ;
if ( F_6 ( V_286 -> V_183 || V_286 -> V_320 ) ) {
F_143 ( & V_286 -> V_322 ) ;
return - V_337 ;
}
V_286 -> V_183 = V_42 ;
F_143 ( & V_286 -> V_322 ) ;
F_13 ( V_29 -> V_30 , L_40 ,
V_42 -> V_99 , V_340 ) ;
F_157 ( V_29 ) ;
F_147 ( V_29 , & V_286 -> V_339 ,
F_148 ( V_340 ) ) ;
return 0 ;
}
static int F_158 ( struct V_68 * V_29 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_151 ( & V_286 -> V_339 ) ;
F_141 ( & V_286 -> V_322 ) ;
V_286 -> V_183 = NULL ;
F_143 ( & V_286 -> V_322 ) ;
F_13 ( V_29 -> V_30 , L_41 ) ;
return 0 ;
}
static int F_159 ( struct V_68 * V_29 ,
struct V_15 * V_342 )
{
F_10 ( V_342 ) ;
F_13 ( V_29 -> V_30 ,
L_42 ,
V_342 -> V_41 . V_42 -> V_99 , V_342 -> V_41 . V_237 ,
V_342 -> V_41 . V_234 , V_342 -> V_41 . V_235 ) ;
return 0 ;
}
static void F_160 ( struct V_68 * V_29 ,
struct V_15 * V_342 )
{
F_13 ( V_29 -> V_30 ,
L_43 ,
V_342 -> V_41 . V_42 -> V_99 , V_342 -> V_41 . V_237 ,
V_342 -> V_41 . V_234 , V_342 -> V_41 . V_235 ) ;
F_9 ( V_342 ) ;
F_11 ( V_342 ) ;
}
static void F_161 ( struct V_68 * V_29 ,
struct V_15 * V_342 ,
T_5 V_224 )
{
F_9 ( V_342 ) ;
F_13 ( V_29 -> V_30 ,
L_44 ,
V_342 -> V_41 . V_42 -> V_99 , V_342 -> V_41 . V_237 ,
V_342 -> V_41 . V_234 , V_342 -> V_41 . V_235 ) ;
}
static int F_162 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_342 )
{
F_1 ( V_2 ) ;
F_9 ( V_342 ) ;
return 0 ;
}
static void F_163 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_342 )
{
F_1 ( V_2 ) ;
F_9 ( V_342 ) ;
}
static int F_164 ( int V_326 , const char * V_343 ,
const struct V_344 * V_345 ,
bool V_346 , bool V_347 ,
bool V_191 )
{
int V_290 ;
T_1 V_8 [ V_38 ] ;
struct V_22 * V_23 ;
struct V_68 * V_29 ;
enum V_348 V_164 ;
const struct V_349 * V_350 = & V_351 ;
int V_144 ;
if ( F_6 ( V_326 > 1 && ! V_191 ) )
return - V_59 ;
F_165 ( & V_179 ) ;
V_144 = V_352 ++ ;
F_166 ( & V_179 ) ;
if ( V_191 )
V_350 = & V_353 ;
V_29 = F_167 ( sizeof( * V_23 ) , V_350 ) ;
if ( ! V_29 ) {
F_63 ( V_134 L_45 ) ;
V_290 = - V_296 ;
goto V_354;
}
V_23 = V_29 -> V_69 ;
V_23 -> V_29 = V_29 ;
V_23 -> V_64 = F_168 ( V_355 , NULL , 0 , V_29 , L_46 , V_144 ) ;
if ( F_169 ( V_23 -> V_64 ) ) {
F_63 ( V_134
L_47 ,
F_170 ( V_23 -> V_64 ) ) ;
V_290 = - V_296 ;
goto V_356;
}
V_23 -> V_64 -> V_357 = & V_358 . V_357 ;
V_290 = F_171 ( V_23 -> V_64 ) ;
if ( V_290 != 0 ) {
F_63 ( V_134 L_48 ,
V_290 ) ;
goto V_359;
}
F_172 ( & V_23 -> V_127 ) ;
F_173 ( V_29 , V_23 -> V_64 ) ;
memset ( V_8 , 0 , V_38 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_144 >> 8 ;
V_8 [ 4 ] = V_144 ;
memcpy ( V_23 -> V_136 [ 0 ] . V_8 , V_8 , V_38 ) ;
memcpy ( V_23 -> V_136 [ 1 ] . V_8 , V_8 , V_38 ) ;
V_23 -> V_136 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_29 -> V_30 -> V_360 = 2 ;
V_29 -> V_30 -> V_136 = V_23 -> V_136 ;
V_23 -> V_326 = V_326 ;
V_23 -> V_191 = V_191 ;
V_23 -> V_144 = V_144 ;
if ( V_23 -> V_191 ) {
V_29 -> V_30 -> V_361 = 255 ;
V_29 -> V_30 -> V_362 = V_363 ;
V_29 -> V_30 -> V_364 = 1000 ;
V_29 -> V_30 -> V_365 = 1 ;
V_29 -> V_30 -> V_366 = & V_23 -> V_367 ;
if ( V_347 )
V_23 -> V_367 = V_368 [ 0 ] ;
else
V_23 -> V_367 = V_369 [ 0 ] ;
V_23 -> V_367 . V_370 = V_23 -> V_326 ;
} else if ( V_347 ) {
V_29 -> V_30 -> V_366 = V_368 ;
V_29 -> V_30 -> V_365 =
F_94 ( V_368 ) ;
} else {
V_29 -> V_30 -> V_366 = V_369 ;
V_29 -> V_30 -> V_365 = F_94 ( V_369 ) ;
}
F_174 ( & V_23 -> V_339 , F_154 ) ;
F_174 ( & V_23 -> V_317 , F_140 ) ;
V_29 -> V_313 = 5 ;
V_29 -> V_371 = 4 ;
V_29 -> V_30 -> V_372 = F_175 ( V_373 ) |
F_175 ( V_210 ) |
F_175 ( V_374 ) |
F_175 ( V_375 ) |
F_175 ( V_212 ) |
F_175 ( V_211 ) ;
if ( V_347 )
V_29 -> V_30 -> V_372 |= F_175 ( V_376 ) ;
V_29 -> V_78 = V_377 |
V_378 |
V_379 |
V_380 |
V_381 |
V_382 |
V_383 |
V_384 |
V_385 ;
if ( V_386 )
V_29 -> V_78 |= V_193 ;
V_29 -> V_30 -> V_78 |= V_387 |
V_388 |
V_389 |
V_390 ;
V_29 -> V_30 -> V_391 |= V_392 ;
V_29 -> V_30 -> V_391 |= V_393 ;
V_29 -> V_394 = sizeof( struct V_3 ) ;
V_29 -> V_395 = sizeof( struct V_12 ) ;
V_29 -> V_396 = sizeof( struct V_17 ) ;
memcpy ( V_23 -> V_397 , V_398 ,
sizeof( V_398 ) ) ;
memcpy ( V_23 -> V_399 , V_400 ,
sizeof( V_400 ) ) ;
memcpy ( V_23 -> V_146 , V_401 , sizeof( V_401 ) ) ;
for ( V_164 = V_402 ; V_164 < V_403 ; V_164 ++ ) {
struct V_404 * V_405 = & V_23 -> V_406 [ V_164 ] ;
switch ( V_164 ) {
case V_402 :
V_405 -> V_326 = V_23 -> V_397 ;
V_405 -> V_324 = F_94 ( V_398 ) ;
V_405 -> V_407 = V_23 -> V_146 ;
V_405 -> V_408 = F_94 ( V_401 ) ;
break;
case V_409 :
V_405 -> V_326 = V_23 -> V_399 ;
V_405 -> V_324 = F_94 ( V_400 ) ;
V_405 -> V_407 = V_23 -> V_146 + 4 ;
V_405 -> V_408 = F_94 ( V_401 ) - 4 ;
break;
default:
continue;
}
V_405 -> V_410 . V_411 = true ;
V_405 -> V_410 . V_412 = V_413 |
V_414 |
V_415 |
V_416 ;
V_405 -> V_410 . V_417 = 0x3 ;
V_405 -> V_410 . V_418 = 0x6 ;
memset ( & V_405 -> V_410 . V_419 , 0 ,
sizeof( V_405 -> V_410 . V_419 ) ) ;
V_405 -> V_410 . V_419 . V_420 [ 0 ] = 0xff ;
V_405 -> V_410 . V_419 . V_420 [ 1 ] = 0xff ;
V_405 -> V_410 . V_419 . V_421 = V_422 ;
V_29 -> V_30 -> V_406 [ V_164 ] = V_405 ;
V_405 -> V_423 . V_424 = true ;
V_405 -> V_423 . V_412 =
V_425 |
V_426 |
V_427 |
V_428 |
V_429 |
V_430 |
V_431 |
V_432 |
V_433 |
V_434 |
V_435 |
V_436 ;
V_405 -> V_423 . V_437 . V_438 =
F_16 ( V_439 << 0 |
V_439 << 2 |
V_440 << 4 |
V_439 << 6 |
V_439 << 8 |
V_440 << 10 |
V_440 << 12 |
V_439 << 14 ) ;
V_405 -> V_423 . V_437 . V_441 =
V_405 -> V_423 . V_437 . V_438 ;
}
V_23 -> V_62 = 1 ;
F_176 ( & V_23 -> V_322 ) ;
V_29 -> V_442 = 4 ;
V_29 -> V_443 = 11 ;
if ( V_346 )
V_29 -> V_30 -> V_444 |= V_445 ;
if ( V_345 ) {
V_29 -> V_30 -> V_444 |= V_446 ;
F_177 ( V_29 -> V_30 , V_345 ) ;
F_178 ( 1 ) ;
}
V_290 = F_179 ( V_29 ) ;
if ( V_290 < 0 ) {
F_63 ( V_134 L_49 ,
V_290 ) ;
goto V_359;
}
F_13 ( V_29 -> V_30 , L_50 , V_29 -> V_30 -> V_447 ) ;
if ( V_343 )
F_180 ( V_29 -> V_30 , V_343 ) ;
V_23 -> V_448 = F_181 ( L_51 , V_29 -> V_30 -> V_449 ) ;
F_182 ( L_52 , 0666 , V_23 -> V_448 , V_23 , & V_450 ) ;
F_182 ( L_53 , 0666 , V_23 -> V_448 , V_23 ,
& V_451 ) ;
if ( ! V_23 -> V_191 )
F_182 ( L_54 , 0222 ,
V_23 -> V_448 ,
V_23 , & V_452 ) ;
F_183 ( & V_23 -> V_197 ,
F_110 ,
V_453 , V_222 ) ;
F_165 ( & V_179 ) ;
F_184 ( & V_23 -> V_454 , & V_455 ) ;
F_166 ( & V_179 ) ;
return V_144 ;
V_359:
F_185 ( V_23 -> V_64 ) ;
V_356:
F_186 ( V_29 ) ;
V_354:
return V_290 ;
}
static void F_187 ( struct V_22 * V_23 )
{
F_188 ( V_23 -> V_448 ) ;
F_189 ( V_23 -> V_29 ) ;
F_190 ( V_23 -> V_64 ) ;
F_185 ( V_23 -> V_64 ) ;
F_186 ( V_23 -> V_29 ) ;
}
static void F_191 ( void )
{
struct V_22 * V_23 ;
F_165 ( & V_179 ) ;
while ( ( V_23 = F_192 ( & V_455 ,
struct V_22 ,
V_454 ) ) ) {
F_193 ( & V_23 -> V_454 ) ;
F_166 ( & V_179 ) ;
F_187 ( V_23 ) ;
F_165 ( & V_179 ) ;
}
F_166 ( & V_179 ) ;
F_194 ( V_355 ) ;
}
static void F_195 ( struct V_63 * V_64 )
{
V_64 -> V_456 = & V_457 ;
V_64 -> V_458 = V_459 ;
F_196 ( V_64 ) ;
V_64 -> V_460 = 0 ;
V_64 -> type = V_461 ;
memset ( V_64 -> V_462 , 0 , V_38 ) ;
V_64 -> V_462 [ 0 ] = 0x12 ;
}
static struct V_22 * F_197 ( const T_1 * V_8 )
{
struct V_22 * V_23 ;
bool V_463 = false ;
F_165 ( & V_179 ) ;
F_82 (data, &hwsim_radios, list) {
if ( memcmp ( V_23 -> V_136 [ 1 ] . V_8 , V_8 , V_38 ) == 0 ) {
V_463 = true ;
break;
}
}
F_166 ( & V_179 ) ;
if ( ! V_463 )
return NULL ;
return V_23 ;
}
static int F_198 ( struct V_24 * V_464 ,
struct V_465 * V_80 )
{
struct V_44 * V_45 ;
struct V_22 * V_157 ;
struct V_79 * V_189 ;
struct V_124 * V_125 ;
unsigned long V_466 ;
struct V_24 * V_25 , * V_467 ;
const T_1 * V_468 ;
unsigned int V_122 ;
int V_123 ;
bool V_469 = false ;
if ( V_80 -> V_470 != V_195 )
return - V_59 ;
if ( ! V_80 -> V_471 [ V_135 ] ||
! V_80 -> V_471 [ V_143 ] ||
! V_80 -> V_471 [ V_149 ] ||
! V_80 -> V_471 [ V_148 ] )
goto V_221;
V_468 = ( void * ) F_199 ( V_80 -> V_471 [ V_135 ] ) ;
V_122 = F_129 ( V_80 -> V_471 [ V_143 ] ) ;
V_466 = F_200 ( V_80 -> V_471 [ V_149 ] ) ;
V_157 = F_197 ( V_468 ) ;
if ( ! V_157 )
goto V_221;
F_201 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_25 == V_466 ) {
F_202 ( V_25 , & V_157 -> V_127 ) ;
V_469 = true ;
break;
}
}
if ( ! V_469 )
goto V_221;
V_125 = (struct V_124 * ) F_199 (
V_80 -> V_471 [ V_148 ] ) ;
V_189 = F_44 ( V_25 ) ;
F_96 ( V_189 ) ;
for ( V_123 = 0 ; V_123 < V_126 ; V_123 ++ ) {
V_189 -> V_145 . V_146 [ V_123 ] . V_144 = V_125 [ V_123 ] . V_144 ;
V_189 -> V_145 . V_146 [ V_123 ] . V_147 = V_125 [ V_123 ] . V_147 ;
}
V_189 -> V_145 . V_472 = F_129 ( V_80 -> V_471 [ V_473 ] ) ;
if ( ! ( V_122 & V_142 ) &&
( V_122 & V_474 ) ) {
if ( V_25 -> V_138 >= 16 ) {
V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_53 ( V_157 -> V_155 ,
V_45 -> V_50 ) ;
}
V_189 -> V_78 |= V_196 ;
}
F_97 ( V_157 -> V_29 , V_25 ) ;
return 0 ;
V_221:
return - V_59 ;
}
static int F_203 ( struct V_24 * V_464 ,
struct V_465 * V_80 )
{
struct V_22 * V_157 ;
struct V_159 V_160 ;
const T_1 * V_475 ;
int V_476 ;
void * V_477 ;
struct V_24 * V_25 = NULL ;
if ( V_80 -> V_470 != V_195 )
return - V_59 ;
if ( ! V_80 -> V_471 [ V_478 ] ||
! V_80 -> V_471 [ V_137 ] ||
! V_80 -> V_471 [ V_479 ] ||
! V_80 -> V_471 [ V_473 ] )
goto V_221;
V_475 = ( void * ) F_199 ( V_80 -> V_471 [ V_478 ] ) ;
V_476 = F_204 ( V_80 -> V_471 [ V_137 ] ) ;
V_477 = ( void * ) F_199 ( V_80 -> V_471 [ V_137 ] ) ;
V_25 = F_205 ( V_476 , V_480 ) ;
if ( V_25 == NULL )
goto V_290;
if ( V_476 > V_363 )
goto V_290;
memcpy ( F_15 ( V_25 , V_476 ) , V_477 , V_476 ) ;
V_157 = F_197 ( V_475 ) ;
if ( ! V_157 )
goto V_221;
if ( V_157 -> V_182 || ! V_157 -> V_181 )
goto V_221;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
V_160 . V_163 = V_157 -> V_155 -> V_99 ;
V_160 . V_164 = V_157 -> V_155 -> V_164 ;
V_160 . V_167 = F_129 ( V_80 -> V_471 [ V_479 ] ) ;
V_160 . signal = F_129 ( V_80 -> V_471 [ V_473 ] ) ;
memcpy ( F_88 ( V_25 ) , & V_160 , sizeof( V_160 ) ) ;
F_89 ( V_157 -> V_29 , V_25 ) ;
return 0 ;
V_290:
F_63 ( V_134 L_5 , V_31 ) ;
goto V_221;
V_221:
F_32 ( V_25 ) ;
return - V_59 ;
}
static int F_206 ( struct V_24 * V_464 ,
struct V_465 * V_80 )
{
struct V_22 * V_23 ;
int V_481 = 1 ;
F_165 ( & V_179 ) ;
F_82 (data, &hwsim_radios, list)
V_481 = F_207 ( V_481 , V_23 -> V_326 ) ;
F_166 ( & V_179 ) ;
if ( V_481 > 1 )
return - V_299 ;
if ( V_195 )
return - V_337 ;
V_195 = V_80 -> V_470 ;
F_63 ( V_134 L_55
L_56 , V_80 -> V_470 ) ;
return 0 ;
}
static int F_208 ( struct V_24 * V_482 , struct V_465 * V_80 )
{
unsigned int V_481 = V_326 ;
const char * V_483 = NULL ;
const struct V_344 * V_345 = NULL ;
bool V_346 = V_80 -> V_471 [ V_484 ] ;
bool V_347 = V_80 -> V_471 [ V_485 ] ;
bool V_191 ;
if ( V_80 -> V_471 [ V_486 ] )
V_481 = F_129 ( V_80 -> V_471 [ V_486 ] ) ;
if ( V_80 -> V_471 [ V_487 ] )
V_191 = true ;
else
V_191 = ( V_481 > 1 ) ;
if ( V_80 -> V_471 [ V_488 ] )
V_483 = F_199 ( V_80 -> V_471 [ V_488 ] ) ;
if ( V_80 -> V_471 [ V_489 ] ) {
T_5 V_144 = F_129 ( V_80 -> V_471 [ V_489 ] ) ;
if ( V_144 >= F_94 ( V_490 ) )
return - V_59 ;
V_345 = V_490 [ V_144 ] ;
}
return F_164 ( V_481 , V_483 , V_345 , V_346 ,
V_347 , V_191 ) ;
}
static int F_209 ( struct V_24 * V_482 , struct V_465 * V_80 )
{
struct V_22 * V_23 ;
int V_144 ;
if ( ! V_80 -> V_471 [ V_491 ] )
return - V_59 ;
V_144 = F_129 ( V_80 -> V_471 [ V_491 ] ) ;
F_165 ( & V_179 ) ;
F_82 (data, &hwsim_radios, list) {
if ( V_23 -> V_144 != V_144 )
continue;
F_193 ( & V_23 -> V_454 ) ;
F_166 ( & V_179 ) ;
F_187 ( V_23 ) ;
return 0 ;
}
F_166 ( & V_179 ) ;
return - V_492 ;
}
static int F_210 ( struct V_493 * V_494 ,
unsigned long V_495 ,
void * V_496 )
{
struct V_497 * V_498 = V_496 ;
if ( V_495 != V_499 )
return V_500 ;
if ( V_498 -> V_501 == V_195 ) {
F_63 ( V_502 L_57
L_58 ) ;
V_195 = 0 ;
}
return V_500 ;
}
static int F_211 ( void )
{
int V_503 ;
F_63 ( V_502 L_59 ) ;
V_503 = F_212 ( & V_132 , V_504 ) ;
if ( V_503 )
goto V_505;
V_503 = F_213 ( & V_506 ) ;
if ( V_503 )
goto V_505;
return 0 ;
V_505:
F_63 ( V_134 L_5 , V_31 ) ;
return - V_59 ;
}
static void F_214 ( void )
{
F_215 ( & V_506 ) ;
F_216 ( & V_132 ) ;
}
static int T_8 F_217 ( void )
{
int V_123 , V_290 ;
if ( V_507 < 0 || V_507 > 100 )
return - V_59 ;
if ( V_326 < 1 )
return - V_59 ;
V_353 = V_351 ;
V_353 . V_317 = F_149 ;
V_353 . V_508 = F_150 ;
V_353 . V_509 = NULL ;
V_353 . V_510 = NULL ;
V_353 . V_511 = F_156 ;
V_353 . V_512 = F_158 ;
V_353 . V_513 = F_159 ;
V_353 . V_514 = F_160 ;
V_353 . V_515 = F_161 ;
V_353 . V_516 =
F_162 ;
V_353 . V_517 =
F_163 ;
F_218 ( & V_179 ) ;
F_219 ( & V_455 ) ;
V_290 = F_220 ( & V_358 ) ;
if ( V_290 )
return V_290 ;
V_355 = F_221 ( V_518 , L_60 ) ;
if ( F_169 ( V_355 ) ) {
V_290 = F_170 ( V_355 ) ;
goto V_519;
}
for ( V_123 = 0 ; V_123 < V_507 ; V_123 ++ ) {
const char * V_343 = NULL ;
const struct V_344 * V_345 = NULL ;
bool V_346 = false ;
switch ( V_520 ) {
case V_521 :
if ( V_123 < F_94 ( V_522 ) )
V_343 = V_522 [ V_123 ] ;
break;
case V_523 :
if ( ! V_123 )
V_343 = V_522 [ 0 ] ;
break;
case V_524 :
V_346 = true ;
case V_525 :
V_343 = V_522 [ 0 ] ;
break;
case V_526 :
if ( V_123 == 0 )
V_345 = & V_527 ;
break;
case V_528 :
V_345 = & V_527 ;
break;
case V_529 :
if ( V_123 == 0 )
V_345 = & V_527 ;
else if ( V_123 == 1 )
V_345 = & V_530 ;
break;
case V_531 :
if ( V_123 == 0 ) {
V_346 = true ;
V_343 = V_522 [ 0 ] ;
}
break;
case V_532 :
if ( V_123 == 0 ) {
V_346 = true ;
V_343 = V_522 [ 0 ] ;
} else if ( V_123 == 1 ) {
V_343 = V_522 [ 1 ] ;
}
break;
case V_533 :
switch ( V_123 ) {
case 0 :
V_345 = & V_527 ;
break;
case 1 :
V_345 = & V_530 ;
break;
case 2 :
V_343 = V_522 [ 0 ] ;
break;
case 3 :
V_343 = V_522 [ 1 ] ;
break;
case 4 :
V_346 = true ;
V_343 = V_522 [ 2 ] ;
break;
}
break;
default:
break;
}
V_290 = F_164 ( V_326 , V_343 ,
V_345 , V_346 ,
V_534 ,
V_326 > 1 ) ;
if ( V_290 < 0 )
goto V_535;
}
V_83 = F_222 ( 0 , L_46 , V_536 ,
F_195 ) ;
if ( V_83 == NULL ) {
V_290 = - V_296 ;
goto V_535;
}
F_223 () ;
V_290 = F_224 ( V_83 , V_83 -> V_537 ) ;
if ( V_290 < 0 ) {
F_225 () ;
goto V_535;
}
V_290 = F_226 ( V_83 ) ;
if ( V_290 < 0 ) {
F_225 () ;
goto V_538;
}
F_225 () ;
V_290 = F_211 () ;
if ( V_290 < 0 )
goto V_538;
return 0 ;
V_538:
V_459 ( V_83 ) ;
V_535:
F_191 () ;
V_519:
F_227 ( & V_358 ) ;
return V_290 ;
}
static void T_9 F_228 ( void )
{
F_63 ( V_134 L_61 ) ;
F_214 () ;
F_191 () ;
F_229 ( V_83 ) ;
F_227 ( & V_358 ) ;
}
