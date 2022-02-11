static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = * F_2 ( V_4 ) ;
V_6 . V_7 . V_8 = F_3 ( V_4 ) -> V_9 ;
F_4 ( V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 = F_3 ( V_4 ) -> V_12 ;
F_4 ( V_2 , V_10 , V_13 , sizeof( int ) , & V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( V_2 , V_10 , V_14 , 1 , & F_3 ( V_4 ) -> V_15 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_8 ( V_4 ) -> V_16 . V_17 == 0 )
return;
F_4 ( V_2 , V_10 , V_18 , F_8 ( V_4 ) -> V_16 . V_17 ,
F_3 ( V_4 ) + 1 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
if ( F_8 ( V_4 ) -> V_16 . V_17 == 0 )
return;
if ( F_10 ( V_16 , V_4 ) ) {
V_2 -> V_21 |= V_22 ;
return;
}
F_11 ( V_16 ) ;
F_4 ( V_2 , V_10 , V_23 , V_16 -> V_17 , V_16 -> V_24 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_25 ;
if ( F_8 ( V_4 ) -> V_26 == 0 )
return;
V_25 = F_8 ( V_4 ) -> V_26 ;
F_4 ( V_2 , V_10 , V_27 , sizeof( V_25 ) , & V_25 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_28 , int V_29 )
{
T_1 V_30 = V_4 -> V_30 ;
if ( V_4 -> V_31 != V_32 )
return;
if ( V_29 != 0 ) {
int V_33 = F_14 ( V_4 ) + V_28 ;
V_30 = F_15 ( V_30 , F_16 ( V_4 , V_33 , V_29 , 0 ) ) ;
}
F_4 ( V_2 , V_10 , V_34 , sizeof( T_1 ) , & V_30 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_35 ;
T_2 V_36 , V_37 ;
int V_38 ;
V_38 = F_18 ( NULL , V_4 , & V_37 ) ;
if ( V_38 )
return;
V_38 = F_19 ( V_37 , & V_35 , & V_36 ) ;
if ( V_38 )
return;
F_4 ( V_2 , V_10 , V_39 , V_36 , V_35 ) ;
F_20 ( V_35 , V_36 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_40 sin ;
const struct V_41 * V_42 = F_3 ( V_4 ) ;
T_3 * V_43 = ( T_3 * ) F_22 ( V_4 ) ;
if ( F_14 ( V_4 ) + 4 > ( int ) V_4 -> V_44 )
return;
sin . V_45 = V_46 ;
sin . V_47 . V_8 = V_42 -> V_9 ;
sin . V_48 = V_43 [ 1 ] ;
memset ( sin . V_49 , 0 , sizeof( sin . V_49 ) ) ;
F_4 ( V_2 , V_10 , V_50 , sizeof( sin ) , & sin ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_51 * V_52 ,
struct V_3 * V_4 , int V_28 , int V_29 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
unsigned int V_55 = V_54 -> V_56 ;
if ( V_55 & V_57 ) {
F_1 ( V_2 , V_4 ) ;
V_55 &= ~ V_57 ;
if ( ! V_55 )
return;
}
if ( V_55 & V_58 ) {
F_5 ( V_2 , V_4 ) ;
V_55 &= ~ V_58 ;
if ( ! V_55 )
return;
}
if ( V_55 & V_59 ) {
F_6 ( V_2 , V_4 ) ;
V_55 &= ~ V_59 ;
if ( ! V_55 )
return;
}
if ( V_55 & V_60 ) {
F_7 ( V_2 , V_4 ) ;
V_55 &= ~ V_60 ;
if ( ! V_55 )
return;
}
if ( V_55 & V_61 ) {
F_9 ( V_2 , V_4 ) ;
V_55 &= ~ V_61 ;
if ( ! V_55 )
return;
}
if ( V_55 & V_62 ) {
F_17 ( V_2 , V_4 ) ;
V_55 &= ~ V_62 ;
if ( ! V_55 )
return;
}
if ( V_55 & V_63 ) {
F_21 ( V_2 , V_4 ) ;
V_55 &= ~ V_63 ;
if ( ! V_55 )
return;
}
if ( V_55 & V_64 )
F_13 ( V_2 , V_4 , V_28 , V_29 ) ;
if ( V_55 & V_65 )
F_12 ( V_2 , V_4 ) ;
}
int F_25 ( struct V_51 * V_52 , struct V_1 * V_2 , struct V_66 * V_67 ,
bool V_68 )
{
int V_38 , V_25 ;
struct V_69 * V_70 ;
struct V_71 * V_71 = F_26 ( V_52 ) ;
F_27 (cmsg, msg) {
if ( ! F_28 ( V_2 , V_70 ) )
return - V_72 ;
#if F_29 ( V_73 )
if ( V_68 &&
V_70 -> V_74 == V_75 &&
V_70 -> V_76 == V_77 ) {
struct V_78 * V_79 ;
if ( V_70 -> V_80 < F_30 ( sizeof( * V_79 ) ) )
return - V_72 ;
V_79 = (struct V_78 * ) F_31 ( V_70 ) ;
if ( ! F_32 ( & V_79 -> V_81 ) )
return - V_72 ;
V_67 -> V_82 = V_79 -> V_83 ;
V_67 -> V_84 = V_79 -> V_81 . V_85 [ 3 ] ;
continue;
}
#endif
if ( V_70 -> V_74 == V_86 ) {
V_38 = F_33 ( V_52 , V_2 , V_70 , & V_67 -> V_87 ) ;
if ( V_38 )
return V_38 ;
continue;
}
if ( V_70 -> V_74 != V_10 )
continue;
switch ( V_70 -> V_76 ) {
case V_23 :
V_38 = V_70 -> V_80 - sizeof( struct V_69 ) ;
V_38 = F_34 ( V_71 , & V_67 -> V_16 , F_31 ( V_70 ) ,
V_38 < 40 ? V_38 : 40 ) ;
if ( V_38 )
return V_38 ;
break;
case V_11 :
{
struct V_5 * V_6 ;
if ( V_70 -> V_80 != F_30 ( sizeof( struct V_5 ) ) )
return - V_72 ;
V_6 = (struct V_5 * ) F_31 ( V_70 ) ;
V_67 -> V_82 = V_6 -> V_88 ;
V_67 -> V_84 = V_6 -> V_89 . V_8 ;
break;
}
case V_13 :
if ( V_70 -> V_80 != F_30 ( sizeof( int ) ) )
return - V_72 ;
V_25 = * ( int * ) F_31 ( V_70 ) ;
if ( V_25 < 1 || V_25 > 255 )
return - V_72 ;
V_67 -> V_12 = V_25 ;
break;
case V_14 :
if ( V_70 -> V_80 == F_30 ( sizeof( int ) ) )
V_25 = * ( int * ) F_31 ( V_70 ) ;
else if ( V_70 -> V_80 == F_30 ( sizeof( V_90 ) ) )
V_25 = * ( V_90 * ) F_31 ( V_70 ) ;
else
return - V_72 ;
if ( V_25 < 0 || V_25 > 255 )
return - V_72 ;
V_67 -> V_15 = V_25 ;
V_67 -> V_91 = F_35 ( V_67 -> V_15 ) ;
break;
default:
return - V_72 ;
}
}
return 0 ;
}
static void F_36 ( struct V_92 * V_93 )
{
struct V_94 * V_95 = F_37 ( V_93 , struct V_94 , V_96 ) ;
F_38 ( V_95 -> V_97 ) ;
F_39 ( V_95 ) ;
}
int F_40 ( struct V_51 * V_52 , unsigned char V_98 ,
void (* F_41)( struct V_51 * ) )
{
struct V_94 * V_95 , * V_99 ;
struct V_94 T_4 * * V_100 ;
if ( V_52 -> V_101 != V_102 || F_24 ( V_52 ) -> V_103 == V_104 )
return - V_72 ;
V_99 = V_98 ? F_42 ( sizeof( * V_99 ) , V_105 ) : NULL ;
for ( V_100 = & V_94 ;
( V_95 = F_43 ( * V_100 ) ) != NULL ;
V_100 = & V_95 -> V_106 ) {
if ( V_95 -> V_52 == V_52 ) {
if ( V_98 ) {
F_39 ( V_99 ) ;
return - V_107 ;
}
V_95 -> V_52 = NULL ;
F_44 ( * V_100 , V_95 -> V_106 ) ;
if ( V_95 -> F_41 )
V_95 -> F_41 ( V_52 ) ;
V_95 -> V_97 = V_52 ;
F_45 ( & V_95 -> V_96 , F_36 ) ;
return 0 ;
}
}
if ( ! V_99 )
return - V_108 ;
V_99 -> V_52 = V_52 ;
V_99 -> F_41 = F_41 ;
F_44 ( V_99 -> V_106 , V_95 ) ;
F_46 ( * V_100 , V_99 ) ;
F_47 ( V_52 ) ;
return 0 ;
}
void F_48 ( struct V_51 * V_52 , struct V_3 * V_4 , int V_38 ,
T_3 V_109 , T_2 V_6 , V_90 * V_110 )
{
struct V_111 * V_112 ;
V_4 = F_49 ( V_4 , V_113 ) ;
if ( ! V_4 )
return;
V_112 = F_50 ( V_4 ) ;
V_112 -> V_114 . V_115 = V_38 ;
V_112 -> V_114 . V_116 = V_117 ;
V_112 -> V_114 . V_118 = F_51 ( V_4 ) -> type ;
V_112 -> V_114 . V_119 = F_51 ( V_4 ) -> V_120 ;
V_112 -> V_114 . V_121 = 0 ;
V_112 -> V_114 . V_122 = V_6 ;
V_112 -> V_114 . V_123 = 0 ;
V_112 -> V_124 = ( V_90 * ) & ( ( (struct V_41 * ) ( F_51 ( V_4 ) + 1 ) ) -> V_9 ) -
F_52 ( V_4 ) ;
V_112 -> V_109 = V_109 ;
if ( F_53 ( V_4 , V_110 - V_4 -> V_125 ) ) {
F_54 ( V_4 ) ;
if ( F_55 ( V_52 , V_4 ) == 0 )
return;
}
F_56 ( V_4 ) ;
}
void F_57 ( struct V_51 * V_52 , int V_38 , T_5 V_9 , T_3 V_109 , T_2 V_6 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
struct V_111 * V_112 ;
struct V_41 * V_42 ;
struct V_3 * V_4 ;
if ( ! V_54 -> V_126 )
return;
V_4 = F_58 ( sizeof( struct V_41 ) , V_113 ) ;
if ( ! V_4 )
return;
F_59 ( V_4 , sizeof( struct V_41 ) ) ;
F_60 ( V_4 ) ;
V_42 = F_3 ( V_4 ) ;
V_42 -> V_9 = V_9 ;
V_112 = F_50 ( V_4 ) ;
V_112 -> V_114 . V_115 = V_38 ;
V_112 -> V_114 . V_116 = V_127 ;
V_112 -> V_114 . V_118 = 0 ;
V_112 -> V_114 . V_119 = 0 ;
V_112 -> V_114 . V_121 = 0 ;
V_112 -> V_114 . V_122 = V_6 ;
V_112 -> V_114 . V_123 = 0 ;
V_112 -> V_124 = ( V_90 * ) & V_42 -> V_9 - F_52 ( V_4 ) ;
V_112 -> V_109 = V_109 ;
F_61 ( V_4 , F_62 ( V_4 ) - V_4 -> V_125 ) ;
F_54 ( V_4 ) ;
if ( F_55 ( V_52 , V_4 ) )
F_56 ( V_4 ) ;
}
static inline bool F_63 ( struct V_111 * V_112 )
{
return V_112 -> V_114 . V_116 == V_117 ||
V_112 -> V_114 . V_116 == V_127 || V_112 -> V_109 ;
}
static bool F_64 ( const struct V_51 * V_52 ,
struct V_3 * V_4 ,
int V_116 )
{
struct V_5 * V_6 ;
if ( V_116 == V_117 )
return true ;
if ( V_116 == V_127 )
return false ;
V_6 = F_2 ( V_4 ) ;
if ( ! ( V_52 -> V_128 & V_129 ) ||
! V_6 -> V_88 )
return false ;
V_6 -> V_89 . V_8 = F_3 ( V_4 ) -> V_130 ;
return true ;
}
int F_65 ( struct V_51 * V_52 , struct V_1 * V_2 , int V_44 , int * V_131 )
{
struct V_111 * V_112 ;
struct V_3 * V_4 ;
F_66 ( struct V_40 * , sin , V_2 -> V_132 ) ;
struct {
struct V_133 V_114 ;
struct V_40 V_134 ;
} V_135 ;
int V_38 ;
int V_136 ;
F_67 ( V_52 -> V_137 == V_138 ) ;
V_38 = - V_139 ;
V_4 = F_68 ( V_52 ) ;
if ( ! V_4 )
goto V_140;
V_136 = V_4 -> V_44 ;
if ( V_136 > V_44 ) {
V_2 -> V_21 |= V_141 ;
V_136 = V_44 ;
}
V_38 = F_69 ( V_4 , 0 , V_2 , V_136 ) ;
if ( F_70 ( V_38 ) ) {
F_56 ( V_4 ) ;
return V_38 ;
}
F_71 ( V_2 , V_52 , V_4 ) ;
V_112 = F_50 ( V_4 ) ;
if ( sin && F_63 ( V_112 ) ) {
sin -> V_45 = V_46 ;
sin -> V_47 . V_8 = * ( T_5 * ) ( F_52 ( V_4 ) +
V_112 -> V_124 ) ;
sin -> V_48 = V_112 -> V_109 ;
memset ( & sin -> V_49 , 0 , sizeof( sin -> V_49 ) ) ;
* V_131 = sizeof( * sin ) ;
}
memcpy ( & V_135 . V_114 , & V_112 -> V_114 , sizeof( struct V_133 ) ) ;
sin = & V_135 . V_134 ;
memset ( sin , 0 , sizeof( * sin ) ) ;
if ( F_64 ( V_52 , V_4 , V_112 -> V_114 . V_116 ) ) {
sin -> V_45 = V_46 ;
sin -> V_47 . V_8 = F_3 ( V_4 ) -> V_130 ;
if ( F_24 ( V_52 ) -> V_56 )
F_72 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_142 , sizeof( V_135 ) , & V_135 ) ;
V_2 -> V_21 |= V_143 ;
V_38 = V_136 ;
F_73 ( V_4 ) ;
V_140:
return V_38 ;
}
static bool F_74 ( int V_144 )
{
switch ( V_144 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
return true ;
}
return false ;
}
static int F_75 ( struct V_51 * V_52 , int V_160 ,
int V_144 , char T_6 * V_161 , unsigned int V_17 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
struct V_71 * V_71 = F_26 ( V_52 ) ;
int V_25 = 0 , V_38 ;
bool V_162 = F_74 ( V_144 ) ;
switch ( V_144 ) {
case V_11 :
case V_163 :
case V_18 :
case V_164 :
case V_23 :
case V_14 :
case V_13 :
case V_165 :
case V_166 :
case V_142 :
case V_159 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_34 :
case V_27 :
if ( V_17 >= sizeof( int ) ) {
if ( F_76 ( V_25 , ( int T_6 * ) V_161 ) )
return - V_178 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_179 ;
if ( F_76 ( V_179 , ( unsigned char T_6 * ) V_161 ) )
return - V_178 ;
V_25 = ( int ) V_179 ;
}
}
if ( F_77 ( V_144 ) )
return F_78 ( V_52 , V_144 , V_161 , V_17 ) ;
V_38 = 0 ;
if ( V_162 )
F_79 () ;
F_80 ( V_52 ) ;
switch ( V_144 ) {
case V_180 :
{
struct V_181 * V_182 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_183;
V_38 = F_81 ( F_26 ( V_52 ) , & V_16 ,
V_161 , V_17 ) ;
if ( V_38 )
break;
V_182 = F_82 ( V_54 -> V_184 ,
F_83 ( V_52 ) ) ;
if ( V_54 -> V_185 ) {
struct V_186 * V_187 = F_84 ( V_52 ) ;
#if F_29 ( V_73 )
if ( V_52 -> V_137 == V_188 ||
( ! ( ( 1 << V_52 -> V_189 ) &
( V_190 | V_191 ) ) &&
V_54 -> V_192 != V_193 ) ) {
#endif
if ( V_182 )
V_187 -> V_194 -= V_182 -> V_16 . V_17 ;
if ( V_16 )
V_187 -> V_194 += V_16 -> V_16 . V_17 ;
V_187 -> V_195 ( V_52 , V_187 -> V_196 ) ;
#if F_29 ( V_73 )
}
#endif
}
F_46 ( V_54 -> V_184 , V_16 ) ;
if ( V_182 )
F_85 ( V_182 , V_96 ) ;
break;
}
case V_11 :
if ( V_25 )
V_54 -> V_56 |= V_57 ;
else
V_54 -> V_56 &= ~ V_57 ;
break;
case V_163 :
if ( V_25 )
V_54 -> V_56 |= V_58 ;
else
V_54 -> V_56 &= ~ V_58 ;
break;
case V_164 :
if ( V_25 )
V_54 -> V_56 |= V_59 ;
else
V_54 -> V_56 &= ~ V_59 ;
break;
case V_18 :
if ( V_25 )
V_54 -> V_56 |= V_60 ;
else
V_54 -> V_56 &= ~ V_60 ;
break;
case V_23 :
if ( V_25 )
V_54 -> V_56 |= V_61 ;
else
V_54 -> V_56 &= ~ V_61 ;
break;
case V_168 :
if ( V_25 )
V_54 -> V_56 |= V_62 ;
else
V_54 -> V_56 &= ~ V_62 ;
break;
case V_177 :
if ( V_25 )
V_54 -> V_56 |= V_63 ;
else
V_54 -> V_56 &= ~ V_63 ;
break;
case V_34 :
if ( V_25 ) {
if ( ! ( V_54 -> V_56 & V_64 ) ) {
F_86 ( V_52 ) ;
V_54 -> V_56 |= V_64 ;
}
} else {
if ( V_54 -> V_56 & V_64 ) {
F_87 ( V_52 ) ;
V_54 -> V_56 &= ~ V_64 ;
}
}
break;
case V_27 :
if ( V_52 -> V_101 != V_102 && V_52 -> V_101 != V_197 )
goto V_183;
if ( V_25 )
V_54 -> V_56 |= V_65 ;
else
V_54 -> V_56 &= ~ V_65 ;
break;
case V_14 :
if ( V_52 -> V_101 == V_198 ) {
V_25 &= ~ V_199 ;
V_25 |= V_54 -> V_15 & V_199 ;
}
if ( V_54 -> V_15 != V_25 ) {
V_54 -> V_15 = V_25 ;
V_52 -> V_200 = F_35 ( V_25 ) ;
F_88 ( V_52 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_183;
if ( V_25 != - 1 && ( V_25 < 1 || V_25 > 255 ) )
goto V_183;
V_54 -> V_201 = V_25 ;
break;
case V_165 :
if ( V_52 -> V_101 != V_102 ) {
V_38 = - V_202 ;
break;
}
V_54 -> V_203 = V_25 ? 1 : 0 ;
break;
case V_171 :
if ( V_52 -> V_101 != V_102 ) {
V_38 = - V_202 ;
break;
}
V_54 -> V_204 = V_25 ? 1 : 0 ;
break;
case V_172 :
V_54 -> V_205 = V_25 ? 1 : 0 ;
break;
case V_166 :
if ( V_25 < V_206 || V_25 > V_207 )
goto V_183;
V_54 -> V_208 = V_25 ;
break;
case V_142 :
V_54 -> V_126 = ! ! V_25 ;
if ( ! V_25 )
F_89 ( & V_52 -> V_209 ) ;
break;
case V_174 :
if ( V_52 -> V_101 == V_198 )
goto V_183;
if ( V_17 < 1 )
goto V_183;
if ( V_25 == - 1 )
V_25 = 1 ;
if ( V_25 < 0 || V_25 > 255 )
goto V_183;
V_54 -> V_210 = V_25 ;
break;
case V_176 :
if ( V_17 < 1 )
goto V_183;
V_54 -> V_211 = ! ! V_25 ;
break;
case V_173 :
{
struct V_212 * V_213 = NULL ;
int V_214 ;
if ( V_17 != sizeof( int ) )
goto V_183;
V_214 = ( V_215 int ) F_90 ( ( V_215 T_5 ) V_25 ) ;
if ( V_214 == 0 ) {
V_54 -> V_216 = 0 ;
V_38 = 0 ;
break;
}
V_213 = F_91 ( F_26 ( V_52 ) , V_214 ) ;
V_38 = - V_217 ;
if ( ! V_213 )
break;
F_92 ( V_213 ) ;
V_38 = - V_72 ;
if ( V_52 -> V_218 )
break;
V_54 -> V_216 = V_214 ;
V_38 = 0 ;
break;
}
case V_219 :
{
struct V_220 V_221 ;
struct V_212 * V_213 = NULL ;
int V_222 ;
if ( V_52 -> V_101 == V_198 )
goto V_183;
if ( V_17 < sizeof( struct V_223 ) )
goto V_183;
V_38 = - V_178 ;
if ( V_17 >= sizeof( struct V_220 ) ) {
if ( F_93 ( & V_221 , V_161 , sizeof( V_221 ) ) )
break;
} else {
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
if ( V_17 >= sizeof( struct V_224 ) ) {
if ( F_93 ( & V_221 , V_161 ,
sizeof( struct V_224 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_223 ) ) {
if ( F_93 ( & V_221 . V_225 , V_161 ,
sizeof( struct V_223 ) ) )
break;
}
}
if ( ! V_221 . V_226 ) {
if ( V_221 . V_225 . V_8 == F_94 ( V_227 ) ) {
V_54 -> V_228 = 0 ;
V_54 -> V_229 = 0 ;
V_38 = 0 ;
break;
}
V_213 = F_95 ( F_26 ( V_52 ) , V_221 . V_225 . V_8 ) ;
if ( V_213 )
V_221 . V_226 = V_213 -> V_214 ;
} else
V_213 = F_91 ( F_26 ( V_52 ) , V_221 . V_226 ) ;
V_38 = - V_217 ;
if ( ! V_213 )
break;
V_222 = F_96 ( V_213 ) ;
F_92 ( V_213 ) ;
V_38 = - V_72 ;
if ( V_52 -> V_218 &&
V_221 . V_226 != V_52 -> V_218 &&
( ! V_222 || V_222 != V_52 -> V_218 ) )
break;
V_54 -> V_228 = V_221 . V_226 ;
V_54 -> V_229 = V_221 . V_225 . V_8 ;
V_38 = 0 ;
break;
}
case V_145 :
case V_148 :
{
struct V_220 V_221 ;
V_38 = - V_230 ;
if ( F_24 ( V_52 ) -> V_185 )
break;
if ( V_17 < sizeof( struct V_224 ) )
goto V_183;
V_38 = - V_178 ;
if ( V_17 >= sizeof( struct V_220 ) ) {
if ( F_93 ( & V_221 , V_161 , sizeof( V_221 ) ) )
break;
} else {
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
if ( F_93 ( & V_221 , V_161 , sizeof( struct V_224 ) ) )
break;
}
if ( V_144 == V_145 )
V_38 = F_97 ( V_52 , & V_221 ) ;
else
V_38 = F_98 ( V_52 , & V_221 ) ;
break;
}
case V_150 :
{
struct V_231 * V_232 ;
if ( V_17 < F_99 ( 0 ) )
goto V_183;
if ( V_17 > V_233 ) {
V_38 = - V_108 ;
break;
}
V_232 = F_100 ( V_161 , V_17 ) ;
if ( F_101 ( V_232 ) ) {
V_38 = F_102 ( V_232 ) ;
break;
}
if ( V_232 -> V_234 >= 0x3ffffffcU ||
V_232 -> V_234 > V_71 -> V_235 . V_236 ) {
F_39 ( V_232 ) ;
V_38 = - V_108 ;
break;
}
if ( F_99 ( V_232 -> V_234 ) > V_17 ) {
F_39 ( V_232 ) ;
V_38 = - V_72 ;
break;
}
V_38 = F_103 ( V_52 , V_232 , 0 ) ;
F_39 ( V_232 ) ;
break;
}
case V_147 :
case V_151 :
case V_146 :
case V_149 :
{
struct V_237 V_238 ;
int V_239 , V_240 ;
if ( V_17 != sizeof( struct V_237 ) )
goto V_183;
if ( F_93 ( & V_238 , V_161 , sizeof( V_238 ) ) ) {
V_38 = - V_178 ;
break;
}
if ( V_144 == V_147 ) {
V_239 = V_241 ;
V_240 = 1 ;
} else if ( V_144 == V_151 ) {
V_239 = V_241 ;
V_240 = 0 ;
} else if ( V_144 == V_146 ) {
struct V_220 V_221 ;
V_221 . V_242 . V_8 = V_238 . V_242 ;
V_221 . V_225 . V_8 = V_238 . V_243 ;
V_221 . V_226 = 0 ;
V_38 = F_97 ( V_52 , & V_221 ) ;
if ( V_38 && V_38 != - V_107 )
break;
V_239 = V_244 ;
V_240 = 1 ;
} else {
V_239 = V_244 ;
V_240 = 0 ;
}
V_38 = F_104 ( V_240 , V_239 , V_52 , & V_238 , 0 ) ;
break;
}
case V_154 :
case V_156 :
{
struct V_245 V_246 ;
struct V_40 * V_247 ;
struct V_220 V_221 ;
if ( V_17 < sizeof( struct V_245 ) )
goto V_183;
V_38 = - V_178 ;
if ( F_93 ( & V_246 , V_161 , sizeof( V_246 ) ) )
break;
V_247 = (struct V_40 * ) & V_246 . V_248 ;
if ( V_247 -> V_45 != V_46 )
goto V_183;
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
V_221 . V_242 = V_247 -> V_47 ;
V_221 . V_226 = V_246 . V_249 ;
if ( V_144 == V_154 )
V_38 = F_97 ( V_52 , & V_221 ) ;
else
V_38 = F_98 ( V_52 , & V_221 ) ;
break;
}
case V_155 :
case V_157 :
case V_152 :
case V_158 :
{
struct V_250 V_251 ;
struct V_237 V_238 ;
struct V_40 * V_247 ;
int V_239 , V_240 ;
if ( V_17 != sizeof( struct V_250 ) )
goto V_183;
if ( F_93 ( & V_251 , V_161 , sizeof( V_251 ) ) ) {
V_38 = - V_178 ;
break;
}
if ( V_251 . V_252 . V_253 != V_46 ||
V_251 . V_254 . V_253 != V_46 ) {
V_38 = - V_217 ;
break;
}
V_247 = (struct V_40 * ) & V_251 . V_252 ;
V_238 . V_242 = V_247 -> V_47 . V_8 ;
V_247 = (struct V_40 * ) & V_251 . V_254 ;
V_238 . V_255 = V_247 -> V_47 . V_8 ;
V_238 . V_243 = 0 ;
if ( V_144 == V_152 ) {
V_239 = V_241 ;
V_240 = 1 ;
} else if ( V_144 == V_158 ) {
V_239 = V_241 ;
V_240 = 0 ;
} else if ( V_144 == V_155 ) {
struct V_220 V_221 ;
V_247 = (struct V_40 * ) & V_251 . V_252 ;
V_221 . V_242 = V_247 -> V_47 ;
V_221 . V_225 . V_8 = 0 ;
V_221 . V_226 = V_251 . V_256 ;
V_38 = F_97 ( V_52 , & V_221 ) ;
if ( V_38 && V_38 != - V_107 )
break;
V_251 . V_256 = V_221 . V_226 ;
V_239 = V_244 ;
V_240 = 1 ;
} else {
V_239 = V_244 ;
V_240 = 0 ;
}
V_38 = F_104 ( V_240 , V_239 , V_52 , & V_238 ,
V_251 . V_256 ) ;
break;
}
case V_153 :
{
struct V_40 * V_247 ;
struct V_231 * V_232 = NULL ;
struct V_257 * V_258 = NULL ;
int V_259 , V_260 , V_214 ;
if ( V_17 < F_105 ( 0 ) )
goto V_183;
if ( V_17 > V_233 ) {
V_38 = - V_108 ;
break;
}
V_258 = F_100 ( V_161 , V_17 ) ;
if ( F_101 ( V_258 ) ) {
V_38 = F_102 ( V_258 ) ;
break;
}
if ( V_258 -> V_261 >= 0x1ffffff ||
V_258 -> V_261 > V_71 -> V_235 . V_236 ) {
V_38 = - V_108 ;
goto V_262;
}
if ( F_105 ( V_258 -> V_261 ) > V_17 ) {
V_38 = - V_72 ;
goto V_262;
}
V_259 = F_99 ( V_258 -> V_261 ) ;
V_232 = F_42 ( V_259 , V_105 ) ;
if ( ! V_232 ) {
V_38 = - V_108 ;
goto V_262;
}
V_214 = V_258 -> V_263 ;
V_247 = (struct V_40 * ) & V_258 -> V_264 ;
if ( V_247 -> V_45 != V_46 ) {
V_38 = - V_217 ;
goto V_262;
}
V_232 -> V_265 = V_247 -> V_47 . V_8 ;
V_232 -> V_266 = 0 ;
V_232 -> V_267 = V_258 -> V_268 ;
V_232 -> V_234 = V_258 -> V_261 ;
V_38 = - V_217 ;
for ( V_260 = 0 ; V_260 < V_258 -> V_261 ; ++ V_260 ) {
V_247 = (struct V_40 * ) & V_258 -> V_269 [ V_260 ] ;
if ( V_247 -> V_45 != V_46 )
goto V_262;
V_232 -> V_270 [ V_260 ] = V_247 -> V_47 . V_8 ;
}
F_39 ( V_258 ) ;
V_258 = NULL ;
V_38 = F_103 ( V_52 , V_232 , V_214 ) ;
V_262:
F_39 ( V_232 ) ;
F_39 ( V_258 ) ;
break;
}
case V_175 :
if ( V_17 < 1 )
goto V_183;
if ( V_25 != 0 && V_25 != 1 )
goto V_183;
V_54 -> V_271 = V_25 ;
break;
case V_159 :
V_38 = F_40 ( V_52 , V_25 ? 1 : 0 , NULL ) ;
break;
case V_167 :
if ( V_17 < 1 )
goto V_183;
V_54 -> V_272 = ! ! V_25 ;
break;
case V_273 :
case V_274 :
V_38 = - V_275 ;
if ( ! F_106 ( F_26 ( V_52 ) -> V_276 , V_277 ) )
break;
V_38 = F_107 ( V_52 , V_144 , V_161 , V_17 ) ;
break;
case V_169 :
if ( ! ! V_25 && ! F_106 ( F_26 ( V_52 ) -> V_276 , V_278 ) &&
! F_106 ( F_26 ( V_52 ) -> V_276 , V_277 ) ) {
V_38 = - V_275 ;
break;
}
if ( V_17 < 1 )
goto V_183;
V_54 -> V_279 = ! ! V_25 ;
break;
case V_170 :
if ( V_17 < 1 )
goto V_183;
if ( V_25 < 0 || V_25 > 255 )
goto V_183;
V_54 -> V_280 = V_25 ;
break;
default:
V_38 = - V_202 ;
break;
}
F_108 ( V_52 ) ;
if ( V_162 )
F_109 () ;
return V_38 ;
V_183:
F_108 ( V_52 ) ;
if ( V_162 )
F_109 () ;
return - V_72 ;
}
void F_110 ( const struct V_51 * V_52 , struct V_3 * V_4 )
{
struct V_5 * V_281 = F_2 ( V_4 ) ;
bool V_282 = ( F_24 ( V_52 ) -> V_56 & V_57 ) ||
F_111 ( V_52 ) ;
if ( V_282 && F_112 ( V_4 ) ) {
if ( V_281 -> V_88 == V_283 )
V_281 -> V_88 = F_113 ( V_4 ) ;
V_281 -> V_89 . V_8 = F_114 ( V_4 ) ;
} else {
V_281 -> V_88 = 0 ;
V_281 -> V_89 . V_8 = 0 ;
}
if ( F_70 ( F_8 ( V_4 ) -> V_16 . V_17 ) )
F_115 ( V_4 ) ;
else
F_116 ( V_4 ) ;
}
int F_117 ( struct V_51 * V_52 , int V_160 ,
int V_144 , char T_6 * V_161 , unsigned int V_17 )
{
int V_38 ;
if ( V_160 != V_10 )
return - V_202 ;
V_38 = F_75 ( V_52 , V_160 , V_144 , V_161 , V_17 ) ;
#ifdef F_118
if ( V_38 == - V_202 && V_144 != V_165 &&
V_144 != V_273 &&
V_144 != V_274 &&
! F_77 ( V_144 ) ) {
F_80 ( V_52 ) ;
V_38 = F_119 ( V_52 , V_188 , V_144 , V_161 , V_17 ) ;
F_108 ( V_52 ) ;
}
#endif
return V_38 ;
}
int F_120 ( struct V_51 * V_52 , int V_160 , int V_144 ,
char T_6 * V_161 , unsigned int V_17 )
{
int V_38 ;
if ( V_160 != V_10 )
return - V_202 ;
if ( V_144 >= V_154 && V_144 <= V_153 )
return F_121 ( V_52 , V_160 , V_144 , V_161 , V_17 ,
F_117 ) ;
V_38 = F_75 ( V_52 , V_160 , V_144 , V_161 , V_17 ) ;
#ifdef F_118
if ( V_38 == - V_202 && V_144 != V_165 &&
V_144 != V_273 &&
V_144 != V_274 &&
! F_77 ( V_144 ) ) {
F_80 ( V_52 ) ;
V_38 = F_122 ( V_52 , V_188 , V_144 ,
V_161 , V_17 ) ;
F_108 ( V_52 ) ;
}
#endif
return V_38 ;
}
static bool F_123 ( int V_144 )
{
switch ( V_144 ) {
case V_150 :
case V_153 :
return true ;
}
return false ;
}
static int F_124 ( struct V_51 * V_52 , int V_160 , int V_144 ,
char T_6 * V_161 , int T_6 * V_17 , unsigned int V_55 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
bool V_162 = F_123 ( V_144 ) ;
int V_25 , V_38 = 0 ;
int V_44 ;
if ( V_160 != V_10 )
return - V_284 ;
if ( F_77 ( V_144 ) )
return F_125 ( V_52 , V_144 , V_161 , V_17 ) ;
if ( F_76 ( V_44 , V_17 ) )
return - V_178 ;
if ( V_44 < 0 )
return - V_72 ;
if ( V_162 )
F_79 () ;
F_80 ( V_52 ) ;
switch ( V_144 ) {
case V_180 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_181 * V_184 ;
V_184 = F_82 ( V_54 -> V_184 ,
F_83 ( V_52 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_184 )
memcpy ( V_19 , & V_184 -> V_16 ,
sizeof( struct V_20 ) +
V_184 -> V_16 . V_17 ) ;
F_108 ( V_52 ) ;
if ( V_16 -> V_17 == 0 )
return F_126 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_44 = F_127 (unsigned int, len, opt->optlen) ;
if ( F_126 ( V_44 , V_17 ) )
return - V_178 ;
if ( F_128 ( V_161 , V_16 -> V_24 , V_44 ) )
return - V_178 ;
return 0 ;
}
case V_11 :
V_25 = ( V_54 -> V_56 & V_57 ) != 0 ;
break;
case V_163 :
V_25 = ( V_54 -> V_56 & V_58 ) != 0 ;
break;
case V_164 :
V_25 = ( V_54 -> V_56 & V_59 ) != 0 ;
break;
case V_18 :
V_25 = ( V_54 -> V_56 & V_60 ) != 0 ;
break;
case V_23 :
V_25 = ( V_54 -> V_56 & V_61 ) != 0 ;
break;
case V_168 :
V_25 = ( V_54 -> V_56 & V_62 ) != 0 ;
break;
case V_177 :
V_25 = ( V_54 -> V_56 & V_63 ) != 0 ;
break;
case V_34 :
V_25 = ( V_54 -> V_56 & V_64 ) != 0 ;
break;
case V_27 :
V_25 = ( V_54 -> V_56 & V_65 ) != 0 ;
break;
case V_14 :
V_25 = V_54 -> V_15 ;
break;
case V_13 :
{
struct V_71 * V_71 = F_26 ( V_52 ) ;
V_25 = ( V_54 -> V_201 == - 1 ?
V_71 -> V_235 . V_285 :
V_54 -> V_201 ) ;
break;
}
case V_165 :
V_25 = V_54 -> V_203 ;
break;
case V_171 :
V_25 = V_54 -> V_204 ;
break;
case V_172 :
V_25 = V_54 -> V_205 ;
break;
case V_166 :
V_25 = V_54 -> V_208 ;
break;
case V_286 :
{
struct V_287 * V_288 ;
V_25 = 0 ;
V_288 = F_129 ( V_52 ) ;
if ( V_288 ) {
V_25 = F_130 ( V_288 ) ;
F_131 ( V_288 ) ;
}
if ( ! V_25 ) {
F_108 ( V_52 ) ;
return - V_289 ;
}
break;
}
case V_142 :
V_25 = V_54 -> V_126 ;
break;
case V_174 :
V_25 = V_54 -> V_210 ;
break;
case V_176 :
V_25 = V_54 -> V_211 ;
break;
case V_173 :
V_25 = ( V_215 int ) F_94 ( ( V_290 ) V_54 -> V_216 ) ;
break;
case V_219 :
{
struct V_223 V_84 ;
V_44 = F_127 (unsigned int, len, sizeof(struct in_addr)) ;
V_84 . V_8 = V_54 -> V_229 ;
F_108 ( V_52 ) ;
if ( F_126 ( V_44 , V_17 ) )
return - V_178 ;
if ( F_128 ( V_161 , & V_84 , V_44 ) )
return - V_178 ;
return 0 ;
}
case V_150 :
{
struct V_231 V_232 ;
if ( V_44 < F_99 ( 0 ) ) {
V_38 = - V_72 ;
goto V_140;
}
if ( F_93 ( & V_232 , V_161 , F_99 ( 0 ) ) ) {
V_38 = - V_178 ;
goto V_140;
}
V_38 = F_132 ( V_52 , & V_232 ,
(struct V_231 T_6 * ) V_161 , V_17 ) ;
goto V_140;
}
case V_153 :
{
struct V_257 V_258 ;
if ( V_44 < F_105 ( 0 ) ) {
V_38 = - V_72 ;
goto V_140;
}
if ( F_93 ( & V_258 , V_161 , F_105 ( 0 ) ) ) {
V_38 = - V_178 ;
goto V_140;
}
V_38 = F_133 ( V_52 , & V_258 ,
(struct V_257 T_6 * ) V_161 ,
V_17 ) ;
goto V_140;
}
case V_175 :
V_25 = V_54 -> V_271 ;
break;
case V_291 :
{
struct V_1 V_2 ;
F_108 ( V_52 ) ;
if ( V_52 -> V_101 != V_198 )
return - V_202 ;
V_2 . V_292 = ( V_215 void * ) V_161 ;
V_2 . V_293 = V_44 ;
V_2 . V_21 = V_55 ;
if ( V_54 -> V_56 & V_57 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_54 -> V_294 ;
V_6 . V_89 . V_8 = V_54 -> V_294 ;
V_6 . V_88 = V_54 -> V_228 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_54 -> V_56 & V_58 ) {
int V_295 = V_54 -> V_210 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_295 ) , & V_295 ) ;
}
if ( V_54 -> V_56 & V_59 ) {
int V_15 = V_54 -> V_296 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_44 -= V_2 . V_293 ;
return F_126 ( V_44 , V_17 ) ;
}
case V_167 :
V_25 = V_54 -> V_272 ;
break;
case V_169 :
V_25 = V_54 -> V_279 ;
break;
case V_170 :
V_25 = V_54 -> V_280 ;
break;
default:
F_108 ( V_52 ) ;
return - V_202 ;
}
F_108 ( V_52 ) ;
if ( V_44 < sizeof( int ) && V_44 > 0 && V_25 >= 0 && V_25 <= 255 ) {
unsigned char V_179 = ( unsigned char ) V_25 ;
V_44 = 1 ;
if ( F_126 ( V_44 , V_17 ) )
return - V_178 ;
if ( F_128 ( V_161 , & V_179 , 1 ) )
return - V_178 ;
} else {
V_44 = F_127 (unsigned int, sizeof(int), len) ;
if ( F_126 ( V_44 , V_17 ) )
return - V_178 ;
if ( F_128 ( V_161 , & V_25 , V_44 ) )
return - V_178 ;
}
return 0 ;
V_140:
F_108 ( V_52 ) ;
if ( V_162 )
F_109 () ;
return V_38 ;
}
int F_134 ( struct V_51 * V_52 , int V_160 ,
int V_144 , char T_6 * V_161 , int T_6 * V_17 )
{
int V_38 ;
V_38 = F_124 ( V_52 , V_160 , V_144 , V_161 , V_17 , 0 ) ;
#ifdef F_118
if ( V_38 == - V_202 && V_144 != V_291 &&
! F_77 ( V_144 ) ) {
int V_44 ;
if ( F_76 ( V_44 , V_17 ) )
return - V_178 ;
F_80 ( V_52 ) ;
V_38 = F_135 ( V_52 , V_188 , V_144 , V_161 ,
& V_44 ) ;
F_108 ( V_52 ) ;
if ( V_38 >= 0 )
V_38 = F_126 ( V_44 , V_17 ) ;
return V_38 ;
}
#endif
return V_38 ;
}
int F_136 ( struct V_51 * V_52 , int V_160 , int V_144 ,
char T_6 * V_161 , int T_6 * V_17 )
{
int V_38 ;
if ( V_144 == V_153 )
return F_137 ( V_52 , V_160 , V_144 , V_161 , V_17 ,
F_134 ) ;
V_38 = F_124 ( V_52 , V_160 , V_144 , V_161 , V_17 ,
V_297 ) ;
#ifdef F_118
if ( V_38 == - V_202 && V_144 != V_291 &&
! F_77 ( V_144 ) ) {
int V_44 ;
if ( F_76 ( V_44 , V_17 ) )
return - V_178 ;
F_80 ( V_52 ) ;
V_38 = F_138 ( V_52 , V_188 , V_144 , V_161 , & V_44 ) ;
F_108 ( V_52 ) ;
if ( V_38 >= 0 )
V_38 = F_126 ( V_44 , V_17 ) ;
return V_38 ;
}
#endif
return V_38 ;
}
