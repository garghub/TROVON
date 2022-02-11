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
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_25 , int V_26 )
{
T_1 V_27 = V_4 -> V_27 ;
if ( V_4 -> V_28 != V_29 )
return;
if ( V_26 != 0 )
V_27 = F_13 ( V_27 ,
F_14 ( F_15 ( V_4 ) + V_25 ,
V_26 , 0 ) ) ;
F_4 ( V_2 , V_10 , V_30 , sizeof( T_1 ) , & V_27 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_31 ;
T_2 V_32 , V_33 ;
int V_34 ;
V_34 = F_17 ( NULL , V_4 , & V_33 ) ;
if ( V_34 )
return;
V_34 = F_18 ( V_33 , & V_31 , & V_32 ) ;
if ( V_34 )
return;
F_4 ( V_2 , V_10 , V_35 , V_32 , V_31 ) ;
F_19 ( V_31 , V_32 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_36 sin ;
const struct V_37 * V_38 = F_3 ( V_4 ) ;
T_3 * V_39 = ( T_3 * ) F_15 ( V_4 ) ;
if ( F_21 ( V_4 ) + 4 > V_4 -> V_40 )
return;
sin . V_41 = V_42 ;
sin . V_43 . V_8 = V_38 -> V_9 ;
sin . V_44 = V_39 [ 1 ] ;
memset ( sin . V_45 , 0 , sizeof( sin . V_45 ) ) ;
F_4 ( V_2 , V_10 , V_46 , sizeof( sin ) , & sin ) ;
}
void F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_25 , int V_26 )
{
struct V_47 * V_48 = F_23 ( V_4 -> V_49 ) ;
unsigned int V_50 = V_48 -> V_51 ;
if ( V_50 & V_52 ) {
F_1 ( V_2 , V_4 ) ;
V_50 &= ~ V_52 ;
if ( ! V_50 )
return;
}
if ( V_50 & V_53 ) {
F_5 ( V_2 , V_4 ) ;
V_50 &= ~ V_53 ;
if ( ! V_50 )
return;
}
if ( V_50 & V_54 ) {
F_6 ( V_2 , V_4 ) ;
V_50 &= ~ V_54 ;
if ( ! V_50 )
return;
}
if ( V_50 & V_55 ) {
F_7 ( V_2 , V_4 ) ;
V_50 &= ~ V_55 ;
if ( ! V_50 )
return;
}
if ( V_50 & V_56 ) {
F_9 ( V_2 , V_4 ) ;
V_50 &= ~ V_56 ;
if ( ! V_50 )
return;
}
if ( V_50 & V_57 ) {
F_16 ( V_2 , V_4 ) ;
V_50 &= ~ V_57 ;
if ( ! V_50 )
return;
}
if ( V_50 & V_58 ) {
F_20 ( V_2 , V_4 ) ;
V_50 &= ~ V_58 ;
if ( ! V_50 )
return;
}
if ( V_50 & V_59 )
F_12 ( V_2 , V_4 , V_25 , V_26 ) ;
}
int F_24 ( struct V_60 * V_49 , struct V_1 * V_2 , struct V_61 * V_62 ,
bool V_63 )
{
int V_34 , V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_67 = F_25 ( V_49 ) ;
F_26 (cmsg, msg) {
if ( ! F_27 ( V_2 , V_66 ) )
return - V_68 ;
#if F_28 ( V_69 )
if ( V_63 &&
V_66 -> V_70 == V_71 &&
V_66 -> V_72 == V_73 ) {
struct V_74 * V_75 ;
if ( V_66 -> V_76 < F_29 ( sizeof( * V_75 ) ) )
return - V_68 ;
V_75 = (struct V_74 * ) F_30 ( V_66 ) ;
if ( ! F_31 ( & V_75 -> V_77 ) )
return - V_68 ;
V_62 -> V_78 = V_75 -> V_79 ;
V_62 -> V_80 = V_75 -> V_77 . V_81 [ 3 ] ;
continue;
}
#endif
if ( V_66 -> V_70 == V_82 ) {
V_34 = F_32 ( V_49 , V_2 , V_66 , & V_62 -> V_83 ) ;
if ( V_34 )
return V_34 ;
continue;
}
if ( V_66 -> V_70 != V_10 )
continue;
switch ( V_66 -> V_72 ) {
case V_23 :
V_34 = V_66 -> V_76 - F_33 ( sizeof( struct V_65 ) ) ;
V_34 = F_34 ( V_67 , & V_62 -> V_16 , F_30 ( V_66 ) ,
V_34 < 40 ? V_34 : 40 ) ;
if ( V_34 )
return V_34 ;
break;
case V_11 :
{
struct V_5 * V_6 ;
if ( V_66 -> V_76 != F_29 ( sizeof( struct V_5 ) ) )
return - V_68 ;
V_6 = (struct V_5 * ) F_30 ( V_66 ) ;
V_62 -> V_78 = V_6 -> V_84 ;
V_62 -> V_80 = V_6 -> V_85 . V_8 ;
break;
}
case V_13 :
if ( V_66 -> V_76 != F_29 ( sizeof( int ) ) )
return - V_68 ;
V_64 = * ( int * ) F_30 ( V_66 ) ;
if ( V_64 < 1 || V_64 > 255 )
return - V_68 ;
V_62 -> V_12 = V_64 ;
break;
case V_14 :
if ( V_66 -> V_76 == F_29 ( sizeof( int ) ) )
V_64 = * ( int * ) F_30 ( V_66 ) ;
else if ( V_66 -> V_76 == F_29 ( sizeof( V_86 ) ) )
V_64 = * ( V_86 * ) F_30 ( V_66 ) ;
else
return - V_68 ;
if ( V_64 < 0 || V_64 > 255 )
return - V_68 ;
V_62 -> V_15 = V_64 ;
V_62 -> V_87 = F_35 ( V_62 -> V_15 ) ;
break;
default:
return - V_68 ;
}
}
return 0 ;
}
static void F_36 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = F_37 ( V_89 , struct V_90 , V_92 ) ;
F_38 ( V_91 -> V_93 ) ;
F_39 ( V_91 ) ;
}
int F_40 ( struct V_60 * V_49 , unsigned char V_94 ,
void (* F_41)( struct V_60 * ) )
{
struct V_90 * V_91 , * V_95 ;
struct V_90 T_4 * * V_96 ;
if ( V_49 -> V_97 != V_98 || F_23 ( V_49 ) -> V_99 == V_100 )
return - V_68 ;
V_95 = V_94 ? F_42 ( sizeof( * V_95 ) , V_101 ) : NULL ;
F_43 ( & V_102 ) ;
for ( V_96 = & V_90 ;
( V_91 = F_44 ( * V_96 ,
F_45 ( & V_102 ) ) ) != NULL ;
V_96 = & V_91 -> V_103 ) {
if ( V_91 -> V_49 == V_49 ) {
if ( V_94 ) {
F_46 ( & V_102 ) ;
F_39 ( V_95 ) ;
return - V_104 ;
}
V_91 -> V_49 = NULL ;
F_47 ( * V_96 , V_91 -> V_103 ) ;
F_46 ( & V_102 ) ;
if ( V_91 -> F_41 )
V_91 -> F_41 ( V_49 ) ;
V_91 -> V_93 = V_49 ;
F_48 ( & V_91 -> V_92 , F_36 ) ;
return 0 ;
}
}
if ( ! V_95 ) {
F_46 ( & V_102 ) ;
return - V_105 ;
}
V_95 -> V_49 = V_49 ;
V_95 -> F_41 = F_41 ;
F_47 ( V_95 -> V_103 , V_91 ) ;
F_49 ( * V_96 , V_95 ) ;
F_50 ( V_49 ) ;
F_46 ( & V_102 ) ;
return 0 ;
}
void F_51 ( struct V_60 * V_49 , struct V_3 * V_4 , int V_34 ,
T_3 V_106 , T_2 V_6 , V_86 * V_107 )
{
struct V_108 * V_109 ;
V_4 = F_52 ( V_4 , V_110 ) ;
if ( ! V_4 )
return;
V_109 = F_53 ( V_4 ) ;
V_109 -> V_111 . V_112 = V_34 ;
V_109 -> V_111 . V_113 = V_114 ;
V_109 -> V_111 . V_115 = F_54 ( V_4 ) -> type ;
V_109 -> V_111 . V_116 = F_54 ( V_4 ) -> V_117 ;
V_109 -> V_111 . V_118 = 0 ;
V_109 -> V_111 . V_119 = V_6 ;
V_109 -> V_111 . V_120 = 0 ;
V_109 -> V_121 = ( V_86 * ) & ( ( (struct V_37 * ) ( F_54 ( V_4 ) + 1 ) ) -> V_9 ) -
F_55 ( V_4 ) ;
V_109 -> V_106 = V_106 ;
if ( F_56 ( V_4 , V_107 - V_4 -> V_122 ) ) {
F_57 ( V_4 ) ;
if ( F_58 ( V_49 , V_4 ) == 0 )
return;
}
F_59 ( V_4 ) ;
}
void F_60 ( struct V_60 * V_49 , int V_34 , T_5 V_9 , T_3 V_106 , T_2 V_6 )
{
struct V_47 * V_48 = F_23 ( V_49 ) ;
struct V_108 * V_109 ;
struct V_37 * V_38 ;
struct V_3 * V_4 ;
if ( ! V_48 -> V_123 )
return;
V_4 = F_61 ( sizeof( struct V_37 ) , V_110 ) ;
if ( ! V_4 )
return;
F_62 ( V_4 , sizeof( struct V_37 ) ) ;
F_63 ( V_4 ) ;
V_38 = F_3 ( V_4 ) ;
V_38 -> V_9 = V_9 ;
V_109 = F_53 ( V_4 ) ;
V_109 -> V_111 . V_112 = V_34 ;
V_109 -> V_111 . V_113 = V_124 ;
V_109 -> V_111 . V_115 = 0 ;
V_109 -> V_111 . V_116 = 0 ;
V_109 -> V_111 . V_118 = 0 ;
V_109 -> V_111 . V_119 = V_6 ;
V_109 -> V_111 . V_120 = 0 ;
V_109 -> V_121 = ( V_86 * ) & V_38 -> V_9 - F_55 ( V_4 ) ;
V_109 -> V_106 = V_106 ;
F_64 ( V_4 , F_65 ( V_4 ) - V_4 -> V_122 ) ;
F_57 ( V_4 ) ;
if ( F_58 ( V_49 , V_4 ) )
F_59 ( V_4 ) ;
}
static inline bool F_66 ( struct V_108 * V_109 )
{
return V_109 -> V_111 . V_113 == V_114 ||
V_109 -> V_111 . V_113 == V_124 || V_109 -> V_106 ;
}
static bool F_67 ( const struct V_60 * V_49 ,
struct V_3 * V_4 ,
int V_113 )
{
struct V_5 * V_6 ;
if ( V_113 == V_114 )
return true ;
if ( V_113 == V_124 )
return false ;
if ( ( ! ( V_49 -> V_125 & V_126 ) ) ||
( ! V_4 -> V_127 ) )
return false ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_85 . V_8 = F_3 ( V_4 ) -> V_128 ;
V_6 -> V_84 = V_4 -> V_127 -> V_129 ;
return true ;
}
int F_68 ( struct V_60 * V_49 , struct V_1 * V_2 , int V_40 , int * V_130 )
{
struct V_108 * V_109 ;
struct V_3 * V_4 ;
F_69 ( struct V_36 * , sin , V_2 -> V_131 ) ;
struct {
struct V_132 V_111 ;
struct V_36 V_133 ;
} V_134 ;
int V_34 ;
int V_135 ;
F_70 ( V_49 -> V_136 == V_137 ) ;
V_34 = - V_138 ;
V_4 = F_71 ( V_49 ) ;
if ( ! V_4 )
goto V_139;
V_135 = V_4 -> V_40 ;
if ( V_135 > V_40 ) {
V_2 -> V_21 |= V_140 ;
V_135 = V_40 ;
}
V_34 = F_72 ( V_4 , 0 , V_2 , V_135 ) ;
if ( F_73 ( V_34 ) ) {
F_59 ( V_4 ) ;
return V_34 ;
}
F_74 ( V_2 , V_49 , V_4 ) ;
V_109 = F_53 ( V_4 ) ;
if ( sin && F_66 ( V_109 ) ) {
sin -> V_41 = V_42 ;
sin -> V_43 . V_8 = * ( T_5 * ) ( F_55 ( V_4 ) +
V_109 -> V_121 ) ;
sin -> V_44 = V_109 -> V_106 ;
memset ( & sin -> V_45 , 0 , sizeof( sin -> V_45 ) ) ;
* V_130 = sizeof( * sin ) ;
}
memcpy ( & V_134 . V_111 , & V_109 -> V_111 , sizeof( struct V_132 ) ) ;
sin = & V_134 . V_133 ;
memset ( sin , 0 , sizeof( * sin ) ) ;
if ( F_67 ( V_49 , V_4 , V_109 -> V_111 . V_113 ) ) {
sin -> V_41 = V_42 ;
sin -> V_43 . V_8 = F_3 ( V_4 ) -> V_128 ;
if ( F_23 ( V_49 ) -> V_51 )
F_75 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_141 , sizeof( V_134 ) , & V_134 ) ;
V_2 -> V_21 |= V_142 ;
V_34 = V_135 ;
F_76 ( V_4 ) ;
V_139:
return V_34 ;
}
static bool F_77 ( int V_143 )
{
switch ( V_143 ) {
case V_144 :
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
return true ;
}
return false ;
}
static int F_78 ( struct V_60 * V_49 , int V_158 ,
int V_143 , char T_6 * V_159 , unsigned int V_17 )
{
struct V_47 * V_48 = F_23 ( V_49 ) ;
struct V_67 * V_67 = F_25 ( V_49 ) ;
int V_64 = 0 , V_34 ;
bool V_160 = F_77 ( V_143 ) ;
switch ( V_143 ) {
case V_11 :
case V_161 :
case V_18 :
case V_162 :
case V_23 :
case V_14 :
case V_13 :
case V_163 :
case V_164 :
case V_141 :
case V_165 :
case V_166 :
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
case V_30 :
if ( V_17 >= sizeof( int ) ) {
if ( F_79 ( V_64 , ( int T_6 * ) V_159 ) )
return - V_177 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_178 ;
if ( F_79 ( V_178 , ( unsigned char T_6 * ) V_159 ) )
return - V_177 ;
V_64 = ( int ) V_178 ;
}
}
if ( F_80 ( V_143 ) )
return F_81 ( V_49 , V_143 , V_159 , V_17 ) ;
V_34 = 0 ;
if ( V_160 )
F_82 () ;
F_83 ( V_49 ) ;
switch ( V_143 ) {
case V_179 :
{
struct V_180 * V_181 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_182;
V_34 = F_84 ( F_25 ( V_49 ) , & V_16 ,
V_159 , V_17 ) ;
if ( V_34 )
break;
V_181 = F_44 ( V_48 -> V_183 ,
F_85 ( V_49 ) ) ;
if ( V_48 -> V_184 ) {
struct V_185 * V_186 = F_86 ( V_49 ) ;
#if F_28 ( V_69 )
if ( V_49 -> V_136 == V_187 ||
( ! ( ( 1 << V_49 -> V_188 ) &
( V_189 | V_190 ) ) &&
V_48 -> V_191 != V_192 ) ) {
#endif
if ( V_181 )
V_186 -> V_193 -= V_181 -> V_16 . V_17 ;
if ( V_16 )
V_186 -> V_193 += V_16 -> V_16 . V_17 ;
V_186 -> V_194 ( V_49 , V_186 -> V_195 ) ;
#if F_28 ( V_69 )
}
#endif
}
F_49 ( V_48 -> V_183 , V_16 ) ;
if ( V_181 )
F_87 ( V_181 , V_92 ) ;
break;
}
case V_11 :
if ( V_64 )
V_48 -> V_51 |= V_52 ;
else
V_48 -> V_51 &= ~ V_52 ;
break;
case V_161 :
if ( V_64 )
V_48 -> V_51 |= V_53 ;
else
V_48 -> V_51 &= ~ V_53 ;
break;
case V_162 :
if ( V_64 )
V_48 -> V_51 |= V_54 ;
else
V_48 -> V_51 &= ~ V_54 ;
break;
case V_18 :
if ( V_64 )
V_48 -> V_51 |= V_55 ;
else
V_48 -> V_51 &= ~ V_55 ;
break;
case V_23 :
if ( V_64 )
V_48 -> V_51 |= V_56 ;
else
V_48 -> V_51 &= ~ V_56 ;
break;
case V_167 :
if ( V_64 )
V_48 -> V_51 |= V_57 ;
else
V_48 -> V_51 &= ~ V_57 ;
break;
case V_176 :
if ( V_64 )
V_48 -> V_51 |= V_58 ;
else
V_48 -> V_51 &= ~ V_58 ;
break;
case V_30 :
if ( V_64 ) {
if ( ! ( V_48 -> V_51 & V_59 ) ) {
F_88 ( V_49 ) ;
V_48 -> V_51 |= V_59 ;
}
} else {
if ( V_48 -> V_51 & V_59 ) {
F_89 ( V_49 ) ;
V_48 -> V_51 &= ~ V_59 ;
}
}
break;
case V_14 :
if ( V_49 -> V_97 == V_196 ) {
V_64 &= ~ V_197 ;
V_64 |= V_48 -> V_15 & V_197 ;
}
if ( V_48 -> V_15 != V_64 ) {
V_48 -> V_15 = V_64 ;
V_49 -> V_198 = F_35 ( V_64 ) ;
F_90 ( V_49 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_182;
if ( V_64 != - 1 && ( V_64 < 1 || V_64 > 255 ) )
goto V_182;
V_48 -> V_199 = V_64 ;
break;
case V_163 :
if ( V_49 -> V_97 != V_98 ) {
V_34 = - V_200 ;
break;
}
V_48 -> V_201 = V_64 ? 1 : 0 ;
break;
case V_170 :
if ( V_49 -> V_97 != V_98 ) {
V_34 = - V_200 ;
break;
}
V_48 -> V_202 = V_64 ? 1 : 0 ;
break;
case V_171 :
V_48 -> V_203 = V_64 ? 1 : 0 ;
break;
case V_164 :
if ( V_64 < V_204 || V_64 > V_205 )
goto V_182;
V_48 -> V_206 = V_64 ;
break;
case V_141 :
V_48 -> V_123 = ! ! V_64 ;
if ( ! V_64 )
F_91 ( & V_49 -> V_207 ) ;
break;
case V_173 :
if ( V_49 -> V_97 == V_196 )
goto V_182;
if ( V_17 < 1 )
goto V_182;
if ( V_64 == - 1 )
V_64 = 1 ;
if ( V_64 < 0 || V_64 > 255 )
goto V_182;
V_48 -> V_208 = V_64 ;
break;
case V_175 :
if ( V_17 < 1 )
goto V_182;
V_48 -> V_209 = ! ! V_64 ;
break;
case V_172 :
{
struct V_210 * V_127 = NULL ;
int V_129 ;
if ( V_17 != sizeof( int ) )
goto V_182;
V_129 = ( V_211 int ) F_92 ( ( V_211 T_5 ) V_64 ) ;
if ( V_129 == 0 ) {
V_48 -> V_212 = 0 ;
V_34 = 0 ;
break;
}
V_127 = F_93 ( F_25 ( V_49 ) , V_129 ) ;
V_34 = - V_213 ;
if ( ! V_127 )
break;
F_94 ( V_127 ) ;
V_34 = - V_68 ;
if ( V_49 -> V_214 )
break;
V_48 -> V_212 = V_129 ;
V_34 = 0 ;
break;
}
case V_215 :
{
struct V_216 V_217 ;
struct V_210 * V_127 = NULL ;
if ( V_49 -> V_97 == V_196 )
goto V_182;
if ( V_17 < sizeof( struct V_218 ) )
goto V_182;
V_34 = - V_177 ;
if ( V_17 >= sizeof( struct V_216 ) ) {
if ( F_95 ( & V_217 , V_159 , sizeof( V_217 ) ) )
break;
} else {
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
if ( V_17 >= sizeof( struct V_219 ) ) {
if ( F_95 ( & V_217 , V_159 ,
sizeof( struct V_219 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_218 ) ) {
if ( F_95 ( & V_217 . V_220 , V_159 ,
sizeof( struct V_218 ) ) )
break;
}
}
if ( ! V_217 . V_221 ) {
if ( V_217 . V_220 . V_8 == F_96 ( V_222 ) ) {
V_48 -> V_223 = 0 ;
V_48 -> V_224 = 0 ;
V_34 = 0 ;
break;
}
V_127 = F_97 ( F_25 ( V_49 ) , V_217 . V_220 . V_8 ) ;
if ( V_127 )
V_217 . V_221 = V_127 -> V_129 ;
} else
V_127 = F_93 ( F_25 ( V_49 ) , V_217 . V_221 ) ;
V_34 = - V_213 ;
if ( ! V_127 )
break;
F_94 ( V_127 ) ;
V_34 = - V_68 ;
if ( V_49 -> V_214 &&
V_217 . V_221 != V_49 -> V_214 )
break;
V_48 -> V_223 = V_217 . V_221 ;
V_48 -> V_224 = V_217 . V_220 . V_8 ;
V_34 = 0 ;
break;
}
case V_144 :
case V_147 :
{
struct V_216 V_217 ;
V_34 = - V_225 ;
if ( F_23 ( V_49 ) -> V_184 )
break;
if ( V_17 < sizeof( struct V_219 ) )
goto V_182;
V_34 = - V_177 ;
if ( V_17 >= sizeof( struct V_216 ) ) {
if ( F_95 ( & V_217 , V_159 , sizeof( V_217 ) ) )
break;
} else {
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
if ( F_95 ( & V_217 , V_159 , sizeof( struct V_219 ) ) )
break;
}
if ( V_143 == V_144 )
V_34 = F_98 ( V_49 , & V_217 ) ;
else
V_34 = F_99 ( V_49 , & V_217 ) ;
break;
}
case V_149 :
{
struct V_226 * V_227 ;
if ( V_17 < F_100 ( 0 ) )
goto V_182;
if ( V_17 > V_228 ) {
V_34 = - V_105 ;
break;
}
V_227 = F_42 ( V_17 , V_101 ) ;
if ( ! V_227 ) {
V_34 = - V_105 ;
break;
}
V_34 = - V_177 ;
if ( F_95 ( V_227 , V_159 , V_17 ) ) {
F_39 ( V_227 ) ;
break;
}
if ( V_227 -> V_229 >= 0x3ffffffcU ||
V_227 -> V_229 > V_67 -> V_230 . V_231 ) {
F_39 ( V_227 ) ;
V_34 = - V_105 ;
break;
}
if ( F_100 ( V_227 -> V_229 ) > V_17 ) {
F_39 ( V_227 ) ;
V_34 = - V_68 ;
break;
}
V_34 = F_101 ( V_49 , V_227 , 0 ) ;
F_39 ( V_227 ) ;
break;
}
case V_146 :
case V_150 :
case V_145 :
case V_148 :
{
struct V_232 V_233 ;
int V_234 , V_235 ;
if ( V_17 != sizeof( struct V_232 ) )
goto V_182;
if ( F_95 ( & V_233 , V_159 , sizeof( V_233 ) ) ) {
V_34 = - V_177 ;
break;
}
if ( V_143 == V_146 ) {
V_234 = V_236 ;
V_235 = 1 ;
} else if ( V_143 == V_150 ) {
V_234 = V_236 ;
V_235 = 0 ;
} else if ( V_143 == V_145 ) {
struct V_216 V_217 ;
V_217 . V_237 . V_8 = V_233 . V_237 ;
V_217 . V_220 . V_8 = V_233 . V_238 ;
V_217 . V_221 = 0 ;
V_34 = F_98 ( V_49 , & V_217 ) ;
if ( V_34 && V_34 != - V_104 )
break;
V_234 = V_239 ;
V_235 = 1 ;
} else {
V_234 = V_239 ;
V_235 = 0 ;
}
V_34 = F_102 ( V_235 , V_234 , V_49 , & V_233 , 0 ) ;
break;
}
case V_153 :
case V_155 :
{
struct V_240 V_241 ;
struct V_36 * V_242 ;
struct V_216 V_217 ;
if ( V_17 < sizeof( struct V_240 ) )
goto V_182;
V_34 = - V_177 ;
if ( F_95 ( & V_241 , V_159 , sizeof( V_241 ) ) )
break;
V_242 = (struct V_36 * ) & V_241 . V_243 ;
if ( V_242 -> V_41 != V_42 )
goto V_182;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_237 = V_242 -> V_43 ;
V_217 . V_221 = V_241 . V_244 ;
if ( V_143 == V_153 )
V_34 = F_98 ( V_49 , & V_217 ) ;
else
V_34 = F_99 ( V_49 , & V_217 ) ;
break;
}
case V_154 :
case V_156 :
case V_151 :
case V_157 :
{
struct V_245 V_246 ;
struct V_232 V_233 ;
struct V_36 * V_242 ;
int V_234 , V_235 ;
if ( V_17 != sizeof( struct V_245 ) )
goto V_182;
if ( F_95 ( & V_246 , V_159 , sizeof( V_246 ) ) ) {
V_34 = - V_177 ;
break;
}
if ( V_246 . V_247 . V_248 != V_42 ||
V_246 . V_249 . V_248 != V_42 ) {
V_34 = - V_213 ;
break;
}
V_242 = (struct V_36 * ) & V_246 . V_247 ;
V_233 . V_237 = V_242 -> V_43 . V_8 ;
V_242 = (struct V_36 * ) & V_246 . V_249 ;
V_233 . V_250 = V_242 -> V_43 . V_8 ;
V_233 . V_238 = 0 ;
if ( V_143 == V_151 ) {
V_234 = V_236 ;
V_235 = 1 ;
} else if ( V_143 == V_157 ) {
V_234 = V_236 ;
V_235 = 0 ;
} else if ( V_143 == V_154 ) {
struct V_216 V_217 ;
V_242 = (struct V_36 * ) & V_246 . V_247 ;
V_217 . V_237 = V_242 -> V_43 ;
V_217 . V_220 . V_8 = 0 ;
V_217 . V_221 = V_246 . V_251 ;
V_34 = F_98 ( V_49 , & V_217 ) ;
if ( V_34 && V_34 != - V_104 )
break;
V_246 . V_251 = V_217 . V_221 ;
V_234 = V_239 ;
V_235 = 1 ;
} else {
V_234 = V_239 ;
V_235 = 0 ;
}
V_34 = F_102 ( V_235 , V_234 , V_49 , & V_233 ,
V_246 . V_251 ) ;
break;
}
case V_152 :
{
struct V_36 * V_242 ;
struct V_226 * V_227 = NULL ;
struct V_252 * V_253 = NULL ;
int V_254 , V_255 , V_129 ;
if ( V_17 < F_103 ( 0 ) )
goto V_182;
if ( V_17 > V_228 ) {
V_34 = - V_105 ;
break;
}
V_253 = F_42 ( V_17 , V_101 ) ;
if ( ! V_253 ) {
V_34 = - V_105 ;
break;
}
V_34 = - V_177 ;
if ( F_95 ( V_253 , V_159 , V_17 ) )
goto V_256;
if ( V_253 -> V_257 >= 0x1ffffff ||
V_253 -> V_257 > V_67 -> V_230 . V_231 ) {
V_34 = - V_105 ;
goto V_256;
}
if ( F_103 ( V_253 -> V_257 ) > V_17 ) {
V_34 = - V_68 ;
goto V_256;
}
V_254 = F_100 ( V_253 -> V_257 ) ;
V_227 = F_42 ( V_254 , V_101 ) ;
if ( ! V_227 ) {
V_34 = - V_105 ;
goto V_256;
}
V_129 = V_253 -> V_258 ;
V_242 = (struct V_36 * ) & V_253 -> V_259 ;
if ( V_242 -> V_41 != V_42 ) {
V_34 = - V_213 ;
goto V_256;
}
V_227 -> V_260 = V_242 -> V_43 . V_8 ;
V_227 -> V_261 = 0 ;
V_227 -> V_262 = V_253 -> V_263 ;
V_227 -> V_229 = V_253 -> V_257 ;
V_34 = - V_213 ;
for ( V_255 = 0 ; V_255 < V_253 -> V_257 ; ++ V_255 ) {
V_242 = (struct V_36 * ) & V_253 -> V_264 [ V_255 ] ;
if ( V_242 -> V_41 != V_42 )
goto V_256;
V_227 -> V_265 [ V_255 ] = V_242 -> V_43 . V_8 ;
}
F_39 ( V_253 ) ;
V_253 = NULL ;
V_34 = F_101 ( V_49 , V_227 , V_129 ) ;
V_256:
F_39 ( V_227 ) ;
F_39 ( V_253 ) ;
break;
}
case V_174 :
if ( V_17 < 1 )
goto V_182;
if ( V_64 != 0 && V_64 != 1 )
goto V_182;
V_48 -> V_266 = V_64 ;
break;
case V_165 :
V_34 = F_40 ( V_49 , V_64 ? 1 : 0 , NULL ) ;
break;
case V_166 :
if ( V_17 < 1 )
goto V_182;
V_48 -> V_267 = ! ! V_64 ;
break;
case V_268 :
case V_269 :
V_34 = - V_270 ;
if ( ! F_104 ( F_25 ( V_49 ) -> V_271 , V_272 ) )
break;
V_34 = F_105 ( V_49 , V_143 , V_159 , V_17 ) ;
break;
case V_168 :
if ( ! ! V_64 && ! F_104 ( F_25 ( V_49 ) -> V_271 , V_273 ) &&
! F_104 ( F_25 ( V_49 ) -> V_271 , V_272 ) ) {
V_34 = - V_270 ;
break;
}
if ( V_17 < 1 )
goto V_182;
V_48 -> V_274 = ! ! V_64 ;
break;
case V_169 :
if ( V_17 < 1 )
goto V_182;
if ( V_64 < 0 || V_64 > 255 )
goto V_182;
V_48 -> V_275 = V_64 ;
break;
default:
V_34 = - V_200 ;
break;
}
F_106 ( V_49 ) ;
if ( V_160 )
F_107 () ;
return V_34 ;
V_182:
F_106 ( V_49 ) ;
if ( V_160 )
F_107 () ;
return - V_68 ;
}
void F_108 ( const struct V_60 * V_49 , struct V_3 * V_4 )
{
struct V_5 * V_276 = F_2 ( V_4 ) ;
bool V_277 = ( F_23 ( V_49 ) -> V_51 & V_52 ) ||
F_109 ( V_49 ) ;
if ( V_277 && F_110 ( V_4 ) ) {
V_276 -> V_85 . V_8 = F_111 ( V_4 ) ;
} else {
V_276 -> V_84 = 0 ;
V_276 -> V_85 . V_8 = 0 ;
}
F_112 ( V_4 ) ;
}
int F_113 ( struct V_60 * V_49 , int V_158 ,
int V_143 , char T_6 * V_159 , unsigned int V_17 )
{
int V_34 ;
if ( V_158 != V_10 )
return - V_200 ;
V_34 = F_78 ( V_49 , V_158 , V_143 , V_159 , V_17 ) ;
#ifdef F_114
if ( V_34 == - V_200 && V_143 != V_163 &&
V_143 != V_268 &&
V_143 != V_269 &&
! F_80 ( V_143 ) ) {
F_83 ( V_49 ) ;
V_34 = F_115 ( V_49 , V_187 , V_143 , V_159 , V_17 ) ;
F_106 ( V_49 ) ;
}
#endif
return V_34 ;
}
int F_116 ( struct V_60 * V_49 , int V_158 , int V_143 ,
char T_6 * V_159 , unsigned int V_17 )
{
int V_34 ;
if ( V_158 != V_10 )
return - V_200 ;
if ( V_143 >= V_153 && V_143 <= V_152 )
return F_117 ( V_49 , V_158 , V_143 , V_159 , V_17 ,
F_113 ) ;
V_34 = F_78 ( V_49 , V_158 , V_143 , V_159 , V_17 ) ;
#ifdef F_114
if ( V_34 == - V_200 && V_143 != V_163 &&
V_143 != V_268 &&
V_143 != V_269 &&
! F_80 ( V_143 ) ) {
F_83 ( V_49 ) ;
V_34 = F_118 ( V_49 , V_187 , V_143 ,
V_159 , V_17 ) ;
F_106 ( V_49 ) ;
}
#endif
return V_34 ;
}
static bool F_119 ( int V_143 )
{
switch ( V_143 ) {
case V_149 :
case V_152 :
return true ;
}
return false ;
}
static int F_120 ( struct V_60 * V_49 , int V_158 , int V_143 ,
char T_6 * V_159 , int T_6 * V_17 , unsigned int V_50 )
{
struct V_47 * V_48 = F_23 ( V_49 ) ;
bool V_160 = F_119 ( V_143 ) ;
int V_64 , V_34 = 0 ;
int V_40 ;
if ( V_158 != V_10 )
return - V_278 ;
if ( F_80 ( V_143 ) )
return F_121 ( V_49 , V_143 , V_159 , V_17 ) ;
if ( F_79 ( V_40 , V_17 ) )
return - V_177 ;
if ( V_40 < 0 )
return - V_68 ;
if ( V_160 )
F_82 () ;
F_83 ( V_49 ) ;
switch ( V_143 ) {
case V_179 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_180 * V_183 ;
V_183 = F_44 ( V_48 -> V_183 ,
F_85 ( V_49 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_183 )
memcpy ( V_19 , & V_183 -> V_16 ,
sizeof( struct V_20 ) +
V_183 -> V_16 . V_17 ) ;
F_106 ( V_49 ) ;
if ( V_16 -> V_17 == 0 )
return F_122 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_40 = F_123 (unsigned int, len, opt->optlen) ;
if ( F_122 ( V_40 , V_17 ) )
return - V_177 ;
if ( F_124 ( V_159 , V_16 -> V_24 , V_40 ) )
return - V_177 ;
return 0 ;
}
case V_11 :
V_64 = ( V_48 -> V_51 & V_52 ) != 0 ;
break;
case V_161 :
V_64 = ( V_48 -> V_51 & V_53 ) != 0 ;
break;
case V_162 :
V_64 = ( V_48 -> V_51 & V_54 ) != 0 ;
break;
case V_18 :
V_64 = ( V_48 -> V_51 & V_55 ) != 0 ;
break;
case V_23 :
V_64 = ( V_48 -> V_51 & V_56 ) != 0 ;
break;
case V_167 :
V_64 = ( V_48 -> V_51 & V_57 ) != 0 ;
break;
case V_176 :
V_64 = ( V_48 -> V_51 & V_58 ) != 0 ;
break;
case V_30 :
V_64 = ( V_48 -> V_51 & V_59 ) != 0 ;
break;
case V_14 :
V_64 = V_48 -> V_15 ;
break;
case V_13 :
{
struct V_67 * V_67 = F_25 ( V_49 ) ;
V_64 = ( V_48 -> V_199 == - 1 ?
V_67 -> V_230 . V_279 :
V_48 -> V_199 ) ;
break;
}
case V_163 :
V_64 = V_48 -> V_201 ;
break;
case V_170 :
V_64 = V_48 -> V_202 ;
break;
case V_171 :
V_64 = V_48 -> V_203 ;
break;
case V_164 :
V_64 = V_48 -> V_206 ;
break;
case V_280 :
{
struct V_281 * V_282 ;
V_64 = 0 ;
V_282 = F_125 ( V_49 ) ;
if ( V_282 ) {
V_64 = F_126 ( V_282 ) ;
F_127 ( V_282 ) ;
}
if ( ! V_64 ) {
F_106 ( V_49 ) ;
return - V_283 ;
}
break;
}
case V_141 :
V_64 = V_48 -> V_123 ;
break;
case V_173 :
V_64 = V_48 -> V_208 ;
break;
case V_175 :
V_64 = V_48 -> V_209 ;
break;
case V_172 :
V_64 = ( V_211 int ) F_96 ( ( V_284 ) V_48 -> V_212 ) ;
break;
case V_215 :
{
struct V_218 V_80 ;
V_40 = F_123 (unsigned int, len, sizeof(struct in_addr)) ;
V_80 . V_8 = V_48 -> V_224 ;
F_106 ( V_49 ) ;
if ( F_122 ( V_40 , V_17 ) )
return - V_177 ;
if ( F_124 ( V_159 , & V_80 , V_40 ) )
return - V_177 ;
return 0 ;
}
case V_149 :
{
struct V_226 V_227 ;
if ( V_40 < F_100 ( 0 ) ) {
V_34 = - V_68 ;
goto V_139;
}
if ( F_95 ( & V_227 , V_159 , F_100 ( 0 ) ) ) {
V_34 = - V_177 ;
goto V_139;
}
V_34 = F_128 ( V_49 , & V_227 ,
(struct V_226 T_6 * ) V_159 , V_17 ) ;
goto V_139;
}
case V_152 :
{
struct V_252 V_253 ;
if ( V_40 < F_103 ( 0 ) ) {
V_34 = - V_68 ;
goto V_139;
}
if ( F_95 ( & V_253 , V_159 , F_103 ( 0 ) ) ) {
V_34 = - V_177 ;
goto V_139;
}
V_34 = F_129 ( V_49 , & V_253 ,
(struct V_252 T_6 * ) V_159 ,
V_17 ) ;
goto V_139;
}
case V_174 :
V_64 = V_48 -> V_266 ;
break;
case V_285 :
{
struct V_1 V_2 ;
F_106 ( V_49 ) ;
if ( V_49 -> V_97 != V_196 )
return - V_200 ;
V_2 . V_286 = ( V_211 void * ) V_159 ;
V_2 . V_287 = V_40 ;
V_2 . V_21 = V_50 ;
if ( V_48 -> V_51 & V_52 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_48 -> V_288 ;
V_6 . V_85 . V_8 = V_48 -> V_288 ;
V_6 . V_84 = V_48 -> V_223 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_48 -> V_51 & V_53 ) {
int V_289 = V_48 -> V_208 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_289 ) , & V_289 ) ;
}
if ( V_48 -> V_51 & V_54 ) {
int V_15 = V_48 -> V_290 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_40 -= V_2 . V_287 ;
return F_122 ( V_40 , V_17 ) ;
}
case V_166 :
V_64 = V_48 -> V_267 ;
break;
case V_168 :
V_64 = V_48 -> V_274 ;
break;
case V_169 :
V_64 = V_48 -> V_275 ;
break;
default:
F_106 ( V_49 ) ;
return - V_200 ;
}
F_106 ( V_49 ) ;
if ( V_40 < sizeof( int ) && V_40 > 0 && V_64 >= 0 && V_64 <= 255 ) {
unsigned char V_178 = ( unsigned char ) V_64 ;
V_40 = 1 ;
if ( F_122 ( V_40 , V_17 ) )
return - V_177 ;
if ( F_124 ( V_159 , & V_178 , 1 ) )
return - V_177 ;
} else {
V_40 = F_123 (unsigned int, sizeof(int), len) ;
if ( F_122 ( V_40 , V_17 ) )
return - V_177 ;
if ( F_124 ( V_159 , & V_64 , V_40 ) )
return - V_177 ;
}
return 0 ;
V_139:
F_106 ( V_49 ) ;
if ( V_160 )
F_107 () ;
return V_34 ;
}
int F_130 ( struct V_60 * V_49 , int V_158 ,
int V_143 , char T_6 * V_159 , int T_6 * V_17 )
{
int V_34 ;
V_34 = F_120 ( V_49 , V_158 , V_143 , V_159 , V_17 , 0 ) ;
#ifdef F_114
if ( V_34 == - V_200 && V_143 != V_285 &&
! F_80 ( V_143 ) ) {
int V_40 ;
if ( F_79 ( V_40 , V_17 ) )
return - V_177 ;
F_83 ( V_49 ) ;
V_34 = F_131 ( V_49 , V_187 , V_143 , V_159 ,
& V_40 ) ;
F_106 ( V_49 ) ;
if ( V_34 >= 0 )
V_34 = F_122 ( V_40 , V_17 ) ;
return V_34 ;
}
#endif
return V_34 ;
}
int F_132 ( struct V_60 * V_49 , int V_158 , int V_143 ,
char T_6 * V_159 , int T_6 * V_17 )
{
int V_34 ;
if ( V_143 == V_152 )
return F_133 ( V_49 , V_158 , V_143 , V_159 , V_17 ,
F_130 ) ;
V_34 = F_120 ( V_49 , V_158 , V_143 , V_159 , V_17 ,
V_291 ) ;
#ifdef F_114
if ( V_34 == - V_200 && V_143 != V_285 &&
! F_80 ( V_143 ) ) {
int V_40 ;
if ( F_79 ( V_40 , V_17 ) )
return - V_177 ;
F_83 ( V_49 ) ;
V_34 = F_134 ( V_49 , V_187 , V_143 , V_159 , & V_40 ) ;
F_106 ( V_49 ) ;
if ( V_34 >= 0 )
V_34 = F_122 ( V_40 , V_17 ) ;
return V_34 ;
}
#endif
return V_34 ;
}
