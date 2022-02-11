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
if ( V_29 != 0 )
V_30 = F_14 ( V_30 ,
F_15 ( F_16 ( V_4 ) + V_28 ,
V_29 , 0 ) ) ;
F_4 ( V_2 , V_10 , V_33 , sizeof( T_1 ) , & V_30 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_34 ;
T_2 V_35 , V_36 ;
int V_37 ;
V_37 = F_18 ( NULL , V_4 , & V_36 ) ;
if ( V_37 )
return;
V_37 = F_19 ( V_36 , & V_34 , & V_35 ) ;
if ( V_37 )
return;
F_4 ( V_2 , V_10 , V_38 , V_35 , V_34 ) ;
F_20 ( V_34 , V_35 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 sin ;
const struct V_40 * V_41 = F_3 ( V_4 ) ;
T_3 * V_42 = ( T_3 * ) F_16 ( V_4 ) ;
if ( F_22 ( V_4 ) + 4 > ( int ) V_4 -> V_43 )
return;
sin . V_44 = V_45 ;
sin . V_46 . V_8 = V_41 -> V_9 ;
sin . V_47 = V_42 [ 1 ] ;
memset ( sin . V_48 , 0 , sizeof( sin . V_48 ) ) ;
F_4 ( V_2 , V_10 , V_49 , sizeof( sin ) , & sin ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_50 * V_51 ,
struct V_3 * V_4 , int V_28 , int V_29 )
{
struct V_52 * V_53 = F_24 ( V_51 ) ;
unsigned int V_54 = V_53 -> V_55 ;
if ( V_54 & V_56 ) {
F_1 ( V_2 , V_4 ) ;
V_54 &= ~ V_56 ;
if ( ! V_54 )
return;
}
if ( V_54 & V_57 ) {
F_5 ( V_2 , V_4 ) ;
V_54 &= ~ V_57 ;
if ( ! V_54 )
return;
}
if ( V_54 & V_58 ) {
F_6 ( V_2 , V_4 ) ;
V_54 &= ~ V_58 ;
if ( ! V_54 )
return;
}
if ( V_54 & V_59 ) {
F_7 ( V_2 , V_4 ) ;
V_54 &= ~ V_59 ;
if ( ! V_54 )
return;
}
if ( V_54 & V_60 ) {
F_9 ( V_2 , V_4 ) ;
V_54 &= ~ V_60 ;
if ( ! V_54 )
return;
}
if ( V_54 & V_61 ) {
F_17 ( V_2 , V_4 ) ;
V_54 &= ~ V_61 ;
if ( ! V_54 )
return;
}
if ( V_54 & V_62 ) {
F_21 ( V_2 , V_4 ) ;
V_54 &= ~ V_62 ;
if ( ! V_54 )
return;
}
if ( V_54 & V_63 )
F_13 ( V_2 , V_4 , V_28 , V_29 ) ;
if ( V_54 & V_64 )
F_12 ( V_2 , V_4 ) ;
}
int F_25 ( struct V_50 * V_51 , struct V_1 * V_2 , struct V_65 * V_66 ,
bool V_67 )
{
int V_37 , V_25 ;
struct V_68 * V_69 ;
struct V_70 * V_70 = F_26 ( V_51 ) ;
F_27 (cmsg, msg) {
if ( ! F_28 ( V_2 , V_69 ) )
return - V_71 ;
#if F_29 ( V_72 )
if ( V_67 &&
V_69 -> V_73 == V_74 &&
V_69 -> V_75 == V_76 ) {
struct V_77 * V_78 ;
if ( V_69 -> V_79 < F_30 ( sizeof( * V_78 ) ) )
return - V_71 ;
V_78 = (struct V_77 * ) F_31 ( V_69 ) ;
if ( ! F_32 ( & V_78 -> V_80 ) )
return - V_71 ;
V_66 -> V_81 = V_78 -> V_82 ;
V_66 -> V_83 = V_78 -> V_80 . V_84 [ 3 ] ;
continue;
}
#endif
if ( V_69 -> V_73 == V_85 ) {
V_37 = F_33 ( V_51 , V_2 , V_69 , & V_66 -> V_86 ) ;
if ( V_37 )
return V_37 ;
continue;
}
if ( V_69 -> V_73 != V_10 )
continue;
switch ( V_69 -> V_75 ) {
case V_23 :
V_37 = V_69 -> V_79 - F_34 ( sizeof( struct V_68 ) ) ;
V_37 = F_35 ( V_70 , & V_66 -> V_16 , F_31 ( V_69 ) ,
V_37 < 40 ? V_37 : 40 ) ;
if ( V_37 )
return V_37 ;
break;
case V_11 :
{
struct V_5 * V_6 ;
if ( V_69 -> V_79 != F_30 ( sizeof( struct V_5 ) ) )
return - V_71 ;
V_6 = (struct V_5 * ) F_31 ( V_69 ) ;
V_66 -> V_81 = V_6 -> V_87 ;
V_66 -> V_83 = V_6 -> V_88 . V_8 ;
break;
}
case V_13 :
if ( V_69 -> V_79 != F_30 ( sizeof( int ) ) )
return - V_71 ;
V_25 = * ( int * ) F_31 ( V_69 ) ;
if ( V_25 < 1 || V_25 > 255 )
return - V_71 ;
V_66 -> V_12 = V_25 ;
break;
case V_14 :
if ( V_69 -> V_79 == F_30 ( sizeof( int ) ) )
V_25 = * ( int * ) F_31 ( V_69 ) ;
else if ( V_69 -> V_79 == F_30 ( sizeof( V_89 ) ) )
V_25 = * ( V_89 * ) F_31 ( V_69 ) ;
else
return - V_71 ;
if ( V_25 < 0 || V_25 > 255 )
return - V_71 ;
V_66 -> V_15 = V_25 ;
V_66 -> V_90 = F_36 ( V_66 -> V_15 ) ;
break;
default:
return - V_71 ;
}
}
return 0 ;
}
static void F_37 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = F_38 ( V_92 , struct V_93 , V_95 ) ;
F_39 ( V_94 -> V_96 ) ;
F_40 ( V_94 ) ;
}
int F_41 ( struct V_50 * V_51 , unsigned char V_97 ,
void (* F_42)( struct V_50 * ) )
{
struct V_93 * V_94 , * V_98 ;
struct V_93 T_4 * * V_99 ;
if ( V_51 -> V_100 != V_101 || F_24 ( V_51 ) -> V_102 == V_103 )
return - V_71 ;
V_98 = V_97 ? F_43 ( sizeof( * V_98 ) , V_104 ) : NULL ;
F_44 ( & V_105 ) ;
for ( V_99 = & V_93 ;
( V_94 = F_45 ( * V_99 ,
F_46 ( & V_105 ) ) ) != NULL ;
V_99 = & V_94 -> V_106 ) {
if ( V_94 -> V_51 == V_51 ) {
if ( V_97 ) {
F_47 ( & V_105 ) ;
F_40 ( V_98 ) ;
return - V_107 ;
}
V_94 -> V_51 = NULL ;
F_48 ( * V_99 , V_94 -> V_106 ) ;
F_47 ( & V_105 ) ;
if ( V_94 -> F_42 )
V_94 -> F_42 ( V_51 ) ;
V_94 -> V_96 = V_51 ;
F_49 ( & V_94 -> V_95 , F_37 ) ;
return 0 ;
}
}
if ( ! V_98 ) {
F_47 ( & V_105 ) ;
return - V_108 ;
}
V_98 -> V_51 = V_51 ;
V_98 -> F_42 = F_42 ;
F_48 ( V_98 -> V_106 , V_94 ) ;
F_50 ( * V_99 , V_98 ) ;
F_51 ( V_51 ) ;
F_47 ( & V_105 ) ;
return 0 ;
}
void F_52 ( struct V_50 * V_51 , struct V_3 * V_4 , int V_37 ,
T_3 V_109 , T_2 V_6 , V_89 * V_110 )
{
struct V_111 * V_112 ;
V_4 = F_53 ( V_4 , V_113 ) ;
if ( ! V_4 )
return;
V_112 = F_54 ( V_4 ) ;
V_112 -> V_114 . V_115 = V_37 ;
V_112 -> V_114 . V_116 = V_117 ;
V_112 -> V_114 . V_118 = F_55 ( V_4 ) -> type ;
V_112 -> V_114 . V_119 = F_55 ( V_4 ) -> V_120 ;
V_112 -> V_114 . V_121 = 0 ;
V_112 -> V_114 . V_122 = V_6 ;
V_112 -> V_114 . V_123 = 0 ;
V_112 -> V_124 = ( V_89 * ) & ( ( (struct V_40 * ) ( F_55 ( V_4 ) + 1 ) ) -> V_9 ) -
F_56 ( V_4 ) ;
V_112 -> V_109 = V_109 ;
if ( F_57 ( V_4 , V_110 - V_4 -> V_125 ) ) {
F_58 ( V_4 ) ;
if ( F_59 ( V_51 , V_4 ) == 0 )
return;
}
F_60 ( V_4 ) ;
}
void F_61 ( struct V_50 * V_51 , int V_37 , T_5 V_9 , T_3 V_109 , T_2 V_6 )
{
struct V_52 * V_53 = F_24 ( V_51 ) ;
struct V_111 * V_112 ;
struct V_40 * V_41 ;
struct V_3 * V_4 ;
if ( ! V_53 -> V_126 )
return;
V_4 = F_62 ( sizeof( struct V_40 ) , V_113 ) ;
if ( ! V_4 )
return;
F_63 ( V_4 , sizeof( struct V_40 ) ) ;
F_64 ( V_4 ) ;
V_41 = F_3 ( V_4 ) ;
V_41 -> V_9 = V_9 ;
V_112 = F_54 ( V_4 ) ;
V_112 -> V_114 . V_115 = V_37 ;
V_112 -> V_114 . V_116 = V_127 ;
V_112 -> V_114 . V_118 = 0 ;
V_112 -> V_114 . V_119 = 0 ;
V_112 -> V_114 . V_121 = 0 ;
V_112 -> V_114 . V_122 = V_6 ;
V_112 -> V_114 . V_123 = 0 ;
V_112 -> V_124 = ( V_89 * ) & V_41 -> V_9 - F_56 ( V_4 ) ;
V_112 -> V_109 = V_109 ;
F_65 ( V_4 , F_66 ( V_4 ) - V_4 -> V_125 ) ;
F_58 ( V_4 ) ;
if ( F_59 ( V_51 , V_4 ) )
F_60 ( V_4 ) ;
}
static inline bool F_67 ( struct V_111 * V_112 )
{
return V_112 -> V_114 . V_116 == V_117 ||
V_112 -> V_114 . V_116 == V_127 || V_112 -> V_109 ;
}
static bool F_68 ( const struct V_50 * V_51 ,
struct V_3 * V_4 ,
int V_116 )
{
struct V_5 * V_6 ;
if ( V_116 == V_117 )
return true ;
if ( V_116 == V_127 )
return false ;
if ( ( ! ( V_51 -> V_128 & V_129 ) ) ||
( ! V_4 -> V_130 ) )
return false ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_88 . V_8 = F_3 ( V_4 ) -> V_131 ;
V_6 -> V_87 = V_4 -> V_130 -> V_132 ;
return true ;
}
int F_69 ( struct V_50 * V_51 , struct V_1 * V_2 , int V_43 , int * V_133 )
{
struct V_111 * V_112 ;
struct V_3 * V_4 ;
F_70 ( struct V_39 * , sin , V_2 -> V_134 ) ;
struct {
struct V_135 V_114 ;
struct V_39 V_136 ;
} V_137 ;
int V_37 ;
int V_138 ;
F_71 ( V_51 -> V_139 == V_140 ) ;
V_37 = - V_141 ;
V_4 = F_72 ( V_51 ) ;
if ( ! V_4 )
goto V_142;
V_138 = V_4 -> V_43 ;
if ( V_138 > V_43 ) {
V_2 -> V_21 |= V_143 ;
V_138 = V_43 ;
}
V_37 = F_73 ( V_4 , 0 , V_2 , V_138 ) ;
if ( F_74 ( V_37 ) ) {
F_60 ( V_4 ) ;
return V_37 ;
}
F_75 ( V_2 , V_51 , V_4 ) ;
V_112 = F_54 ( V_4 ) ;
if ( sin && F_67 ( V_112 ) ) {
sin -> V_44 = V_45 ;
sin -> V_46 . V_8 = * ( T_5 * ) ( F_56 ( V_4 ) +
V_112 -> V_124 ) ;
sin -> V_47 = V_112 -> V_109 ;
memset ( & sin -> V_48 , 0 , sizeof( sin -> V_48 ) ) ;
* V_133 = sizeof( * sin ) ;
}
memcpy ( & V_137 . V_114 , & V_112 -> V_114 , sizeof( struct V_135 ) ) ;
sin = & V_137 . V_136 ;
memset ( sin , 0 , sizeof( * sin ) ) ;
if ( F_68 ( V_51 , V_4 , V_112 -> V_114 . V_116 ) ) {
sin -> V_44 = V_45 ;
sin -> V_46 . V_8 = F_3 ( V_4 ) -> V_131 ;
if ( F_24 ( V_51 ) -> V_55 )
F_76 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_144 , sizeof( V_137 ) , & V_137 ) ;
V_2 -> V_21 |= V_145 ;
V_37 = V_138 ;
F_77 ( V_4 ) ;
V_142:
return V_37 ;
}
static bool F_78 ( int V_146 )
{
switch ( V_146 ) {
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
case V_160 :
return true ;
}
return false ;
}
static int F_79 ( struct V_50 * V_51 , int V_161 ,
int V_146 , char T_6 * V_162 , unsigned int V_17 )
{
struct V_52 * V_53 = F_24 ( V_51 ) ;
struct V_70 * V_70 = F_26 ( V_51 ) ;
int V_25 = 0 , V_37 ;
bool V_163 = F_78 ( V_146 ) ;
switch ( V_146 ) {
case V_11 :
case V_164 :
case V_18 :
case V_165 :
case V_23 :
case V_14 :
case V_13 :
case V_166 :
case V_167 :
case V_144 :
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
case V_178 :
case V_179 :
case V_33 :
case V_27 :
if ( V_17 >= sizeof( int ) ) {
if ( F_80 ( V_25 , ( int T_6 * ) V_162 ) )
return - V_180 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_181 ;
if ( F_80 ( V_181 , ( unsigned char T_6 * ) V_162 ) )
return - V_180 ;
V_25 = ( int ) V_181 ;
}
}
if ( F_81 ( V_146 ) )
return F_82 ( V_51 , V_146 , V_162 , V_17 ) ;
V_37 = 0 ;
if ( V_163 )
F_83 () ;
F_84 ( V_51 ) ;
switch ( V_146 ) {
case V_182 :
{
struct V_183 * V_184 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_185;
V_37 = F_85 ( F_26 ( V_51 ) , & V_16 ,
V_162 , V_17 ) ;
if ( V_37 )
break;
V_184 = F_45 ( V_53 -> V_186 ,
F_86 ( V_51 ) ) ;
if ( V_53 -> V_187 ) {
struct V_188 * V_189 = F_87 ( V_51 ) ;
#if F_29 ( V_72 )
if ( V_51 -> V_139 == V_190 ||
( ! ( ( 1 << V_51 -> V_191 ) &
( V_192 | V_193 ) ) &&
V_53 -> V_194 != V_195 ) ) {
#endif
if ( V_184 )
V_189 -> V_196 -= V_184 -> V_16 . V_17 ;
if ( V_16 )
V_189 -> V_196 += V_16 -> V_16 . V_17 ;
V_189 -> V_197 ( V_51 , V_189 -> V_198 ) ;
#if F_29 ( V_72 )
}
#endif
}
F_50 ( V_53 -> V_186 , V_16 ) ;
if ( V_184 )
F_88 ( V_184 , V_95 ) ;
break;
}
case V_11 :
if ( V_25 )
V_53 -> V_55 |= V_56 ;
else
V_53 -> V_55 &= ~ V_56 ;
break;
case V_164 :
if ( V_25 )
V_53 -> V_55 |= V_57 ;
else
V_53 -> V_55 &= ~ V_57 ;
break;
case V_165 :
if ( V_25 )
V_53 -> V_55 |= V_58 ;
else
V_53 -> V_55 &= ~ V_58 ;
break;
case V_18 :
if ( V_25 )
V_53 -> V_55 |= V_59 ;
else
V_53 -> V_55 &= ~ V_59 ;
break;
case V_23 :
if ( V_25 )
V_53 -> V_55 |= V_60 ;
else
V_53 -> V_55 &= ~ V_60 ;
break;
case V_170 :
if ( V_25 )
V_53 -> V_55 |= V_61 ;
else
V_53 -> V_55 &= ~ V_61 ;
break;
case V_179 :
if ( V_25 )
V_53 -> V_55 |= V_62 ;
else
V_53 -> V_55 &= ~ V_62 ;
break;
case V_33 :
if ( V_25 ) {
if ( ! ( V_53 -> V_55 & V_63 ) ) {
F_89 ( V_51 ) ;
V_53 -> V_55 |= V_63 ;
}
} else {
if ( V_53 -> V_55 & V_63 ) {
F_90 ( V_51 ) ;
V_53 -> V_55 &= ~ V_63 ;
}
}
break;
case V_27 :
if ( V_51 -> V_100 != V_101 && V_51 -> V_100 != V_199 )
goto V_185;
if ( V_25 )
V_53 -> V_55 |= V_64 ;
else
V_53 -> V_55 &= ~ V_64 ;
break;
case V_14 :
if ( V_51 -> V_100 == V_200 ) {
V_25 &= ~ V_201 ;
V_25 |= V_53 -> V_15 & V_201 ;
}
if ( V_53 -> V_15 != V_25 ) {
V_53 -> V_15 = V_25 ;
V_51 -> V_202 = F_36 ( V_25 ) ;
F_91 ( V_51 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_185;
if ( V_25 != - 1 && ( V_25 < 1 || V_25 > 255 ) )
goto V_185;
V_53 -> V_203 = V_25 ;
break;
case V_166 :
if ( V_51 -> V_100 != V_101 ) {
V_37 = - V_204 ;
break;
}
V_53 -> V_205 = V_25 ? 1 : 0 ;
break;
case V_173 :
if ( V_51 -> V_100 != V_101 ) {
V_37 = - V_204 ;
break;
}
V_53 -> V_206 = V_25 ? 1 : 0 ;
break;
case V_174 :
V_53 -> V_207 = V_25 ? 1 : 0 ;
break;
case V_167 :
if ( V_25 < V_208 || V_25 > V_209 )
goto V_185;
V_53 -> V_210 = V_25 ;
break;
case V_144 :
V_53 -> V_126 = ! ! V_25 ;
if ( ! V_25 )
F_92 ( & V_51 -> V_211 ) ;
break;
case V_176 :
if ( V_51 -> V_100 == V_200 )
goto V_185;
if ( V_17 < 1 )
goto V_185;
if ( V_25 == - 1 )
V_25 = 1 ;
if ( V_25 < 0 || V_25 > 255 )
goto V_185;
V_53 -> V_212 = V_25 ;
break;
case V_178 :
if ( V_17 < 1 )
goto V_185;
V_53 -> V_213 = ! ! V_25 ;
break;
case V_175 :
{
struct V_214 * V_130 = NULL ;
int V_132 ;
if ( V_17 != sizeof( int ) )
goto V_185;
V_132 = ( V_215 int ) F_93 ( ( V_215 T_5 ) V_25 ) ;
if ( V_132 == 0 ) {
V_53 -> V_216 = 0 ;
V_37 = 0 ;
break;
}
V_130 = F_94 ( F_26 ( V_51 ) , V_132 ) ;
V_37 = - V_217 ;
if ( ! V_130 )
break;
F_95 ( V_130 ) ;
V_37 = - V_71 ;
if ( V_51 -> V_218 )
break;
V_53 -> V_216 = V_132 ;
V_37 = 0 ;
break;
}
case V_219 :
{
struct V_220 V_221 ;
struct V_214 * V_130 = NULL ;
if ( V_51 -> V_100 == V_200 )
goto V_185;
if ( V_17 < sizeof( struct V_222 ) )
goto V_185;
V_37 = - V_180 ;
if ( V_17 >= sizeof( struct V_220 ) ) {
if ( F_96 ( & V_221 , V_162 , sizeof( V_221 ) ) )
break;
} else {
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
if ( V_17 >= sizeof( struct V_223 ) ) {
if ( F_96 ( & V_221 , V_162 ,
sizeof( struct V_223 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_222 ) ) {
if ( F_96 ( & V_221 . V_224 , V_162 ,
sizeof( struct V_222 ) ) )
break;
}
}
if ( ! V_221 . V_225 ) {
if ( V_221 . V_224 . V_8 == F_97 ( V_226 ) ) {
V_53 -> V_227 = 0 ;
V_53 -> V_228 = 0 ;
V_37 = 0 ;
break;
}
V_130 = F_98 ( F_26 ( V_51 ) , V_221 . V_224 . V_8 ) ;
if ( V_130 )
V_221 . V_225 = V_130 -> V_132 ;
} else
V_130 = F_94 ( F_26 ( V_51 ) , V_221 . V_225 ) ;
V_37 = - V_217 ;
if ( ! V_130 )
break;
F_95 ( V_130 ) ;
V_37 = - V_71 ;
if ( V_51 -> V_218 &&
V_221 . V_225 != V_51 -> V_218 )
break;
V_53 -> V_227 = V_221 . V_225 ;
V_53 -> V_228 = V_221 . V_224 . V_8 ;
V_37 = 0 ;
break;
}
case V_147 :
case V_150 :
{
struct V_220 V_221 ;
V_37 = - V_229 ;
if ( F_24 ( V_51 ) -> V_187 )
break;
if ( V_17 < sizeof( struct V_223 ) )
goto V_185;
V_37 = - V_180 ;
if ( V_17 >= sizeof( struct V_220 ) ) {
if ( F_96 ( & V_221 , V_162 , sizeof( V_221 ) ) )
break;
} else {
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
if ( F_96 ( & V_221 , V_162 , sizeof( struct V_223 ) ) )
break;
}
if ( V_146 == V_147 )
V_37 = F_99 ( V_51 , & V_221 ) ;
else
V_37 = F_100 ( V_51 , & V_221 ) ;
break;
}
case V_152 :
{
struct V_230 * V_231 ;
if ( V_17 < F_101 ( 0 ) )
goto V_185;
if ( V_17 > V_232 ) {
V_37 = - V_108 ;
break;
}
V_231 = F_43 ( V_17 , V_104 ) ;
if ( ! V_231 ) {
V_37 = - V_108 ;
break;
}
V_37 = - V_180 ;
if ( F_96 ( V_231 , V_162 , V_17 ) ) {
F_40 ( V_231 ) ;
break;
}
if ( V_231 -> V_233 >= 0x3ffffffcU ||
V_231 -> V_233 > V_70 -> V_234 . V_235 ) {
F_40 ( V_231 ) ;
V_37 = - V_108 ;
break;
}
if ( F_101 ( V_231 -> V_233 ) > V_17 ) {
F_40 ( V_231 ) ;
V_37 = - V_71 ;
break;
}
V_37 = F_102 ( V_51 , V_231 , 0 ) ;
F_40 ( V_231 ) ;
break;
}
case V_149 :
case V_153 :
case V_148 :
case V_151 :
{
struct V_236 V_237 ;
int V_238 , V_239 ;
if ( V_17 != sizeof( struct V_236 ) )
goto V_185;
if ( F_96 ( & V_237 , V_162 , sizeof( V_237 ) ) ) {
V_37 = - V_180 ;
break;
}
if ( V_146 == V_149 ) {
V_238 = V_240 ;
V_239 = 1 ;
} else if ( V_146 == V_153 ) {
V_238 = V_240 ;
V_239 = 0 ;
} else if ( V_146 == V_148 ) {
struct V_220 V_221 ;
V_221 . V_241 . V_8 = V_237 . V_241 ;
V_221 . V_224 . V_8 = V_237 . V_242 ;
V_221 . V_225 = 0 ;
V_37 = F_99 ( V_51 , & V_221 ) ;
if ( V_37 && V_37 != - V_107 )
break;
V_238 = V_243 ;
V_239 = 1 ;
} else {
V_238 = V_243 ;
V_239 = 0 ;
}
V_37 = F_103 ( V_239 , V_238 , V_51 , & V_237 , 0 ) ;
break;
}
case V_156 :
case V_158 :
{
struct V_244 V_245 ;
struct V_39 * V_246 ;
struct V_220 V_221 ;
if ( V_17 < sizeof( struct V_244 ) )
goto V_185;
V_37 = - V_180 ;
if ( F_96 ( & V_245 , V_162 , sizeof( V_245 ) ) )
break;
V_246 = (struct V_39 * ) & V_245 . V_247 ;
if ( V_246 -> V_44 != V_45 )
goto V_185;
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
V_221 . V_241 = V_246 -> V_46 ;
V_221 . V_225 = V_245 . V_248 ;
if ( V_146 == V_156 )
V_37 = F_99 ( V_51 , & V_221 ) ;
else
V_37 = F_100 ( V_51 , & V_221 ) ;
break;
}
case V_157 :
case V_159 :
case V_154 :
case V_160 :
{
struct V_249 V_250 ;
struct V_236 V_237 ;
struct V_39 * V_246 ;
int V_238 , V_239 ;
if ( V_17 != sizeof( struct V_249 ) )
goto V_185;
if ( F_96 ( & V_250 , V_162 , sizeof( V_250 ) ) ) {
V_37 = - V_180 ;
break;
}
if ( V_250 . V_251 . V_252 != V_45 ||
V_250 . V_253 . V_252 != V_45 ) {
V_37 = - V_217 ;
break;
}
V_246 = (struct V_39 * ) & V_250 . V_251 ;
V_237 . V_241 = V_246 -> V_46 . V_8 ;
V_246 = (struct V_39 * ) & V_250 . V_253 ;
V_237 . V_254 = V_246 -> V_46 . V_8 ;
V_237 . V_242 = 0 ;
if ( V_146 == V_154 ) {
V_238 = V_240 ;
V_239 = 1 ;
} else if ( V_146 == V_160 ) {
V_238 = V_240 ;
V_239 = 0 ;
} else if ( V_146 == V_157 ) {
struct V_220 V_221 ;
V_246 = (struct V_39 * ) & V_250 . V_251 ;
V_221 . V_241 = V_246 -> V_46 ;
V_221 . V_224 . V_8 = 0 ;
V_221 . V_225 = V_250 . V_255 ;
V_37 = F_99 ( V_51 , & V_221 ) ;
if ( V_37 && V_37 != - V_107 )
break;
V_250 . V_255 = V_221 . V_225 ;
V_238 = V_243 ;
V_239 = 1 ;
} else {
V_238 = V_243 ;
V_239 = 0 ;
}
V_37 = F_103 ( V_239 , V_238 , V_51 , & V_237 ,
V_250 . V_255 ) ;
break;
}
case V_155 :
{
struct V_39 * V_246 ;
struct V_230 * V_231 = NULL ;
struct V_256 * V_257 = NULL ;
int V_258 , V_259 , V_132 ;
if ( V_17 < F_104 ( 0 ) )
goto V_185;
if ( V_17 > V_232 ) {
V_37 = - V_108 ;
break;
}
V_257 = F_43 ( V_17 , V_104 ) ;
if ( ! V_257 ) {
V_37 = - V_108 ;
break;
}
V_37 = - V_180 ;
if ( F_96 ( V_257 , V_162 , V_17 ) )
goto V_260;
if ( V_257 -> V_261 >= 0x1ffffff ||
V_257 -> V_261 > V_70 -> V_234 . V_235 ) {
V_37 = - V_108 ;
goto V_260;
}
if ( F_104 ( V_257 -> V_261 ) > V_17 ) {
V_37 = - V_71 ;
goto V_260;
}
V_258 = F_101 ( V_257 -> V_261 ) ;
V_231 = F_43 ( V_258 , V_104 ) ;
if ( ! V_231 ) {
V_37 = - V_108 ;
goto V_260;
}
V_132 = V_257 -> V_262 ;
V_246 = (struct V_39 * ) & V_257 -> V_263 ;
if ( V_246 -> V_44 != V_45 ) {
V_37 = - V_217 ;
goto V_260;
}
V_231 -> V_264 = V_246 -> V_46 . V_8 ;
V_231 -> V_265 = 0 ;
V_231 -> V_266 = V_257 -> V_267 ;
V_231 -> V_233 = V_257 -> V_261 ;
V_37 = - V_217 ;
for ( V_259 = 0 ; V_259 < V_257 -> V_261 ; ++ V_259 ) {
V_246 = (struct V_39 * ) & V_257 -> V_268 [ V_259 ] ;
if ( V_246 -> V_44 != V_45 )
goto V_260;
V_231 -> V_269 [ V_259 ] = V_246 -> V_46 . V_8 ;
}
F_40 ( V_257 ) ;
V_257 = NULL ;
V_37 = F_102 ( V_51 , V_231 , V_132 ) ;
V_260:
F_40 ( V_231 ) ;
F_40 ( V_257 ) ;
break;
}
case V_177 :
if ( V_17 < 1 )
goto V_185;
if ( V_25 != 0 && V_25 != 1 )
goto V_185;
V_53 -> V_270 = V_25 ;
break;
case V_168 :
V_37 = F_41 ( V_51 , V_25 ? 1 : 0 , NULL ) ;
break;
case V_169 :
if ( V_17 < 1 )
goto V_185;
V_53 -> V_271 = ! ! V_25 ;
break;
case V_272 :
case V_273 :
V_37 = - V_274 ;
if ( ! F_105 ( F_26 ( V_51 ) -> V_275 , V_276 ) )
break;
V_37 = F_106 ( V_51 , V_146 , V_162 , V_17 ) ;
break;
case V_171 :
if ( ! ! V_25 && ! F_105 ( F_26 ( V_51 ) -> V_275 , V_277 ) &&
! F_105 ( F_26 ( V_51 ) -> V_275 , V_276 ) ) {
V_37 = - V_274 ;
break;
}
if ( V_17 < 1 )
goto V_185;
V_53 -> V_278 = ! ! V_25 ;
break;
case V_172 :
if ( V_17 < 1 )
goto V_185;
if ( V_25 < 0 || V_25 > 255 )
goto V_185;
V_53 -> V_279 = V_25 ;
break;
default:
V_37 = - V_204 ;
break;
}
F_107 ( V_51 ) ;
if ( V_163 )
F_108 () ;
return V_37 ;
V_185:
F_107 ( V_51 ) ;
if ( V_163 )
F_108 () ;
return - V_71 ;
}
void F_109 ( const struct V_50 * V_51 , struct V_3 * V_4 )
{
struct V_5 * V_280 = F_2 ( V_4 ) ;
bool V_281 = ( F_24 ( V_51 ) -> V_55 & V_56 ) ||
F_110 ( V_51 ) ;
if ( V_281 && F_111 ( V_4 ) ) {
if ( V_280 -> V_87 == V_282 )
V_280 -> V_87 = F_112 ( V_4 ) ;
V_280 -> V_88 . V_8 = F_113 ( V_4 ) ;
} else {
V_280 -> V_87 = 0 ;
V_280 -> V_88 . V_8 = 0 ;
}
if ( F_74 ( F_8 ( V_4 ) -> V_16 . V_17 ) )
F_114 ( V_4 ) ;
else
F_115 ( V_4 ) ;
}
int F_116 ( struct V_50 * V_51 , int V_161 ,
int V_146 , char T_6 * V_162 , unsigned int V_17 )
{
int V_37 ;
if ( V_161 != V_10 )
return - V_204 ;
V_37 = F_79 ( V_51 , V_161 , V_146 , V_162 , V_17 ) ;
#ifdef F_117
if ( V_37 == - V_204 && V_146 != V_166 &&
V_146 != V_272 &&
V_146 != V_273 &&
! F_81 ( V_146 ) ) {
F_84 ( V_51 ) ;
V_37 = F_118 ( V_51 , V_190 , V_146 , V_162 , V_17 ) ;
F_107 ( V_51 ) ;
}
#endif
return V_37 ;
}
int F_119 ( struct V_50 * V_51 , int V_161 , int V_146 ,
char T_6 * V_162 , unsigned int V_17 )
{
int V_37 ;
if ( V_161 != V_10 )
return - V_204 ;
if ( V_146 >= V_156 && V_146 <= V_155 )
return F_120 ( V_51 , V_161 , V_146 , V_162 , V_17 ,
F_116 ) ;
V_37 = F_79 ( V_51 , V_161 , V_146 , V_162 , V_17 ) ;
#ifdef F_117
if ( V_37 == - V_204 && V_146 != V_166 &&
V_146 != V_272 &&
V_146 != V_273 &&
! F_81 ( V_146 ) ) {
F_84 ( V_51 ) ;
V_37 = F_121 ( V_51 , V_190 , V_146 ,
V_162 , V_17 ) ;
F_107 ( V_51 ) ;
}
#endif
return V_37 ;
}
static bool F_122 ( int V_146 )
{
switch ( V_146 ) {
case V_152 :
case V_155 :
return true ;
}
return false ;
}
static int F_123 ( struct V_50 * V_51 , int V_161 , int V_146 ,
char T_6 * V_162 , int T_6 * V_17 , unsigned int V_54 )
{
struct V_52 * V_53 = F_24 ( V_51 ) ;
bool V_163 = F_122 ( V_146 ) ;
int V_25 , V_37 = 0 ;
int V_43 ;
if ( V_161 != V_10 )
return - V_283 ;
if ( F_81 ( V_146 ) )
return F_124 ( V_51 , V_146 , V_162 , V_17 ) ;
if ( F_80 ( V_43 , V_17 ) )
return - V_180 ;
if ( V_43 < 0 )
return - V_71 ;
if ( V_163 )
F_83 () ;
F_84 ( V_51 ) ;
switch ( V_146 ) {
case V_182 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_183 * V_186 ;
V_186 = F_45 ( V_53 -> V_186 ,
F_86 ( V_51 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_186 )
memcpy ( V_19 , & V_186 -> V_16 ,
sizeof( struct V_20 ) +
V_186 -> V_16 . V_17 ) ;
F_107 ( V_51 ) ;
if ( V_16 -> V_17 == 0 )
return F_125 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_43 = F_126 (unsigned int, len, opt->optlen) ;
if ( F_125 ( V_43 , V_17 ) )
return - V_180 ;
if ( F_127 ( V_162 , V_16 -> V_24 , V_43 ) )
return - V_180 ;
return 0 ;
}
case V_11 :
V_25 = ( V_53 -> V_55 & V_56 ) != 0 ;
break;
case V_164 :
V_25 = ( V_53 -> V_55 & V_57 ) != 0 ;
break;
case V_165 :
V_25 = ( V_53 -> V_55 & V_58 ) != 0 ;
break;
case V_18 :
V_25 = ( V_53 -> V_55 & V_59 ) != 0 ;
break;
case V_23 :
V_25 = ( V_53 -> V_55 & V_60 ) != 0 ;
break;
case V_170 :
V_25 = ( V_53 -> V_55 & V_61 ) != 0 ;
break;
case V_179 :
V_25 = ( V_53 -> V_55 & V_62 ) != 0 ;
break;
case V_33 :
V_25 = ( V_53 -> V_55 & V_63 ) != 0 ;
break;
case V_27 :
V_25 = ( V_53 -> V_55 & V_64 ) != 0 ;
break;
case V_14 :
V_25 = V_53 -> V_15 ;
break;
case V_13 :
{
struct V_70 * V_70 = F_26 ( V_51 ) ;
V_25 = ( V_53 -> V_203 == - 1 ?
V_70 -> V_234 . V_284 :
V_53 -> V_203 ) ;
break;
}
case V_166 :
V_25 = V_53 -> V_205 ;
break;
case V_173 :
V_25 = V_53 -> V_206 ;
break;
case V_174 :
V_25 = V_53 -> V_207 ;
break;
case V_167 :
V_25 = V_53 -> V_210 ;
break;
case V_285 :
{
struct V_286 * V_287 ;
V_25 = 0 ;
V_287 = F_128 ( V_51 ) ;
if ( V_287 ) {
V_25 = F_129 ( V_287 ) ;
F_130 ( V_287 ) ;
}
if ( ! V_25 ) {
F_107 ( V_51 ) ;
return - V_288 ;
}
break;
}
case V_144 :
V_25 = V_53 -> V_126 ;
break;
case V_176 :
V_25 = V_53 -> V_212 ;
break;
case V_178 :
V_25 = V_53 -> V_213 ;
break;
case V_175 :
V_25 = ( V_215 int ) F_97 ( ( V_289 ) V_53 -> V_216 ) ;
break;
case V_219 :
{
struct V_222 V_83 ;
V_43 = F_126 (unsigned int, len, sizeof(struct in_addr)) ;
V_83 . V_8 = V_53 -> V_228 ;
F_107 ( V_51 ) ;
if ( F_125 ( V_43 , V_17 ) )
return - V_180 ;
if ( F_127 ( V_162 , & V_83 , V_43 ) )
return - V_180 ;
return 0 ;
}
case V_152 :
{
struct V_230 V_231 ;
if ( V_43 < F_101 ( 0 ) ) {
V_37 = - V_71 ;
goto V_142;
}
if ( F_96 ( & V_231 , V_162 , F_101 ( 0 ) ) ) {
V_37 = - V_180 ;
goto V_142;
}
V_37 = F_131 ( V_51 , & V_231 ,
(struct V_230 T_6 * ) V_162 , V_17 ) ;
goto V_142;
}
case V_155 :
{
struct V_256 V_257 ;
if ( V_43 < F_104 ( 0 ) ) {
V_37 = - V_71 ;
goto V_142;
}
if ( F_96 ( & V_257 , V_162 , F_104 ( 0 ) ) ) {
V_37 = - V_180 ;
goto V_142;
}
V_37 = F_132 ( V_51 , & V_257 ,
(struct V_256 T_6 * ) V_162 ,
V_17 ) ;
goto V_142;
}
case V_177 :
V_25 = V_53 -> V_270 ;
break;
case V_290 :
{
struct V_1 V_2 ;
F_107 ( V_51 ) ;
if ( V_51 -> V_100 != V_200 )
return - V_204 ;
V_2 . V_291 = ( V_215 void * ) V_162 ;
V_2 . V_292 = V_43 ;
V_2 . V_21 = V_54 ;
if ( V_53 -> V_55 & V_56 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_53 -> V_293 ;
V_6 . V_88 . V_8 = V_53 -> V_293 ;
V_6 . V_87 = V_53 -> V_227 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_53 -> V_55 & V_57 ) {
int V_294 = V_53 -> V_212 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_294 ) , & V_294 ) ;
}
if ( V_53 -> V_55 & V_58 ) {
int V_15 = V_53 -> V_295 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_43 -= V_2 . V_292 ;
return F_125 ( V_43 , V_17 ) ;
}
case V_169 :
V_25 = V_53 -> V_271 ;
break;
case V_171 :
V_25 = V_53 -> V_278 ;
break;
case V_172 :
V_25 = V_53 -> V_279 ;
break;
default:
F_107 ( V_51 ) ;
return - V_204 ;
}
F_107 ( V_51 ) ;
if ( V_43 < sizeof( int ) && V_43 > 0 && V_25 >= 0 && V_25 <= 255 ) {
unsigned char V_181 = ( unsigned char ) V_25 ;
V_43 = 1 ;
if ( F_125 ( V_43 , V_17 ) )
return - V_180 ;
if ( F_127 ( V_162 , & V_181 , 1 ) )
return - V_180 ;
} else {
V_43 = F_126 (unsigned int, sizeof(int), len) ;
if ( F_125 ( V_43 , V_17 ) )
return - V_180 ;
if ( F_127 ( V_162 , & V_25 , V_43 ) )
return - V_180 ;
}
return 0 ;
V_142:
F_107 ( V_51 ) ;
if ( V_163 )
F_108 () ;
return V_37 ;
}
int F_133 ( struct V_50 * V_51 , int V_161 ,
int V_146 , char T_6 * V_162 , int T_6 * V_17 )
{
int V_37 ;
V_37 = F_123 ( V_51 , V_161 , V_146 , V_162 , V_17 , 0 ) ;
#ifdef F_117
if ( V_37 == - V_204 && V_146 != V_290 &&
! F_81 ( V_146 ) ) {
int V_43 ;
if ( F_80 ( V_43 , V_17 ) )
return - V_180 ;
F_84 ( V_51 ) ;
V_37 = F_134 ( V_51 , V_190 , V_146 , V_162 ,
& V_43 ) ;
F_107 ( V_51 ) ;
if ( V_37 >= 0 )
V_37 = F_125 ( V_43 , V_17 ) ;
return V_37 ;
}
#endif
return V_37 ;
}
int F_135 ( struct V_50 * V_51 , int V_161 , int V_146 ,
char T_6 * V_162 , int T_6 * V_17 )
{
int V_37 ;
if ( V_146 == V_155 )
return F_136 ( V_51 , V_161 , V_146 , V_162 , V_17 ,
F_133 ) ;
V_37 = F_123 ( V_51 , V_161 , V_146 , V_162 , V_17 ,
V_296 ) ;
#ifdef F_117
if ( V_37 == - V_204 && V_146 != V_290 &&
! F_81 ( V_146 ) ) {
int V_43 ;
if ( F_80 ( V_43 , V_17 ) )
return - V_180 ;
F_84 ( V_51 ) ;
V_37 = F_137 ( V_51 , V_190 , V_146 , V_162 , & V_43 ) ;
F_107 ( V_51 ) ;
if ( V_37 >= 0 )
V_37 = F_125 ( V_43 , V_17 ) ;
return V_37 ;
}
#endif
return V_37 ;
}
