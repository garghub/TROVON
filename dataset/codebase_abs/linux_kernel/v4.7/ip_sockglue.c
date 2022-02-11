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
int V_25 )
{
T_1 V_26 = V_4 -> V_26 ;
if ( V_4 -> V_27 != V_28 )
return;
if ( V_25 != 0 )
V_26 = F_13 ( V_26 , F_14 ( F_15 ( V_4 ) ,
V_25 , 0 ) ) ;
F_4 ( V_2 , V_10 , V_29 , sizeof( T_1 ) , & V_26 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_30 ;
T_2 V_31 , V_32 ;
int V_33 ;
V_33 = F_17 ( NULL , V_4 , & V_32 ) ;
if ( V_33 )
return;
V_33 = F_18 ( V_32 , & V_30 , & V_31 ) ;
if ( V_33 )
return;
F_4 ( V_2 , V_10 , V_34 , V_31 , V_30 ) ;
F_19 ( V_30 , V_31 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 sin ;
const struct V_36 * V_37 = F_3 ( V_4 ) ;
T_3 * V_38 = ( T_3 * ) F_15 ( V_4 ) ;
if ( F_21 ( V_4 ) + 4 > V_4 -> V_39 )
return;
sin . V_40 = V_41 ;
sin . V_42 . V_8 = V_37 -> V_9 ;
sin . V_43 = V_38 [ 1 ] ;
memset ( sin . V_44 , 0 , sizeof( sin . V_44 ) ) ;
F_4 ( V_2 , V_10 , V_45 , sizeof( sin ) , & sin ) ;
}
void F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_25 )
{
struct V_46 * V_47 = F_23 ( V_4 -> V_48 ) ;
unsigned int V_49 = V_47 -> V_50 ;
if ( V_49 & V_51 ) {
F_1 ( V_2 , V_4 ) ;
V_49 &= ~ V_51 ;
if ( ! V_49 )
return;
}
if ( V_49 & V_52 ) {
F_5 ( V_2 , V_4 ) ;
V_49 &= ~ V_52 ;
if ( ! V_49 )
return;
}
if ( V_49 & V_53 ) {
F_6 ( V_2 , V_4 ) ;
V_49 &= ~ V_53 ;
if ( ! V_49 )
return;
}
if ( V_49 & V_54 ) {
F_7 ( V_2 , V_4 ) ;
V_49 &= ~ V_54 ;
if ( ! V_49 )
return;
}
if ( V_49 & V_55 ) {
F_9 ( V_2 , V_4 ) ;
V_49 &= ~ V_55 ;
if ( ! V_49 )
return;
}
if ( V_49 & V_56 ) {
F_16 ( V_2 , V_4 ) ;
V_49 &= ~ V_56 ;
if ( ! V_49 )
return;
}
if ( V_49 & V_57 ) {
F_20 ( V_2 , V_4 ) ;
V_49 &= ~ V_57 ;
if ( ! V_49 )
return;
}
if ( V_49 & V_58 )
F_12 ( V_2 , V_4 , V_25 ) ;
}
int F_24 ( struct V_59 * V_48 , struct V_1 * V_2 , struct V_60 * V_61 ,
bool V_62 )
{
int V_33 , V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_66 = F_25 ( V_48 ) ;
F_26 (cmsg, msg) {
if ( ! F_27 ( V_2 , V_65 ) )
return - V_67 ;
#if F_28 ( V_68 )
if ( V_62 &&
V_65 -> V_69 == V_70 &&
V_65 -> V_71 == V_72 ) {
struct V_73 * V_74 ;
if ( V_65 -> V_75 < F_29 ( sizeof( * V_74 ) ) )
return - V_67 ;
V_74 = (struct V_73 * ) F_30 ( V_65 ) ;
if ( ! F_31 ( & V_74 -> V_76 ) )
return - V_67 ;
V_61 -> V_77 = V_74 -> V_78 ;
V_61 -> V_79 = V_74 -> V_76 . V_80 [ 3 ] ;
continue;
}
#endif
if ( V_65 -> V_69 == V_81 ) {
V_33 = F_32 ( V_48 , V_2 , V_65 , & V_61 -> V_82 ) ;
if ( V_33 )
return V_33 ;
continue;
}
if ( V_65 -> V_69 != V_10 )
continue;
switch ( V_65 -> V_71 ) {
case V_23 :
V_33 = V_65 -> V_75 - F_33 ( sizeof( struct V_64 ) ) ;
V_33 = F_34 ( V_66 , & V_61 -> V_16 , F_30 ( V_65 ) ,
V_33 < 40 ? V_33 : 40 ) ;
if ( V_33 )
return V_33 ;
break;
case V_11 :
{
struct V_5 * V_6 ;
if ( V_65 -> V_75 != F_29 ( sizeof( struct V_5 ) ) )
return - V_67 ;
V_6 = (struct V_5 * ) F_30 ( V_65 ) ;
V_61 -> V_77 = V_6 -> V_83 ;
V_61 -> V_79 = V_6 -> V_84 . V_8 ;
break;
}
case V_13 :
if ( V_65 -> V_75 != F_29 ( sizeof( int ) ) )
return - V_67 ;
V_63 = * ( int * ) F_30 ( V_65 ) ;
if ( V_63 < 1 || V_63 > 255 )
return - V_67 ;
V_61 -> V_12 = V_63 ;
break;
case V_14 :
if ( V_65 -> V_75 != F_29 ( sizeof( int ) ) )
return - V_67 ;
V_63 = * ( int * ) F_30 ( V_65 ) ;
if ( V_63 < 0 || V_63 > 255 )
return - V_67 ;
V_61 -> V_15 = V_63 ;
V_61 -> V_85 = F_35 ( V_61 -> V_15 ) ;
break;
default:
return - V_67 ;
}
}
return 0 ;
}
static void F_36 ( struct V_86 * V_87 )
{
struct V_88 * V_89 = F_37 ( V_87 , struct V_88 , V_90 ) ;
F_38 ( V_89 -> V_91 ) ;
F_39 ( V_89 ) ;
}
int F_40 ( struct V_59 * V_48 , unsigned char V_92 ,
void (* F_41)( struct V_59 * ) )
{
struct V_88 * V_89 , * V_93 ;
struct V_88 T_4 * * V_94 ;
if ( V_48 -> V_95 != V_96 || F_23 ( V_48 ) -> V_97 == V_98 )
return - V_67 ;
V_93 = V_92 ? F_42 ( sizeof( * V_93 ) , V_99 ) : NULL ;
F_43 ( & V_100 ) ;
for ( V_94 = & V_88 ;
( V_89 = F_44 ( * V_94 ,
F_45 ( & V_100 ) ) ) != NULL ;
V_94 = & V_89 -> V_101 ) {
if ( V_89 -> V_48 == V_48 ) {
if ( V_92 ) {
F_46 ( & V_100 ) ;
F_39 ( V_93 ) ;
return - V_102 ;
}
V_89 -> V_48 = NULL ;
F_47 ( * V_94 , V_89 -> V_101 ) ;
F_46 ( & V_100 ) ;
if ( V_89 -> F_41 )
V_89 -> F_41 ( V_48 ) ;
V_89 -> V_91 = V_48 ;
F_48 ( & V_89 -> V_90 , F_36 ) ;
return 0 ;
}
}
if ( ! V_93 ) {
F_46 ( & V_100 ) ;
return - V_103 ;
}
V_93 -> V_48 = V_48 ;
V_93 -> F_41 = F_41 ;
F_47 ( V_93 -> V_101 , V_89 ) ;
F_49 ( * V_94 , V_93 ) ;
F_50 ( V_48 ) ;
F_46 ( & V_100 ) ;
return 0 ;
}
void F_51 ( struct V_59 * V_48 , struct V_3 * V_4 , int V_33 ,
T_3 V_104 , T_2 V_6 , T_5 * V_105 )
{
struct V_106 * V_107 ;
V_4 = F_52 ( V_4 , V_108 ) ;
if ( ! V_4 )
return;
V_107 = F_53 ( V_4 ) ;
V_107 -> V_109 . V_110 = V_33 ;
V_107 -> V_109 . V_111 = V_112 ;
V_107 -> V_109 . V_113 = F_54 ( V_4 ) -> type ;
V_107 -> V_109 . V_114 = F_54 ( V_4 ) -> V_115 ;
V_107 -> V_109 . V_116 = 0 ;
V_107 -> V_109 . V_117 = V_6 ;
V_107 -> V_109 . V_118 = 0 ;
V_107 -> V_119 = ( T_5 * ) & ( ( (struct V_36 * ) ( F_54 ( V_4 ) + 1 ) ) -> V_9 ) -
F_55 ( V_4 ) ;
V_107 -> V_104 = V_104 ;
if ( F_56 ( V_4 , V_105 - V_4 -> V_120 ) ) {
F_57 ( V_4 ) ;
if ( F_58 ( V_48 , V_4 ) == 0 )
return;
}
F_59 ( V_4 ) ;
}
void F_60 ( struct V_59 * V_48 , int V_33 , T_6 V_9 , T_3 V_104 , T_2 V_6 )
{
struct V_46 * V_47 = F_23 ( V_48 ) ;
struct V_106 * V_107 ;
struct V_36 * V_37 ;
struct V_3 * V_4 ;
if ( ! V_47 -> V_121 )
return;
V_4 = F_61 ( sizeof( struct V_36 ) , V_108 ) ;
if ( ! V_4 )
return;
F_62 ( V_4 , sizeof( struct V_36 ) ) ;
F_63 ( V_4 ) ;
V_37 = F_3 ( V_4 ) ;
V_37 -> V_9 = V_9 ;
V_107 = F_53 ( V_4 ) ;
V_107 -> V_109 . V_110 = V_33 ;
V_107 -> V_109 . V_111 = V_122 ;
V_107 -> V_109 . V_113 = 0 ;
V_107 -> V_109 . V_114 = 0 ;
V_107 -> V_109 . V_116 = 0 ;
V_107 -> V_109 . V_117 = V_6 ;
V_107 -> V_109 . V_118 = 0 ;
V_107 -> V_119 = ( T_5 * ) & V_37 -> V_9 - F_55 ( V_4 ) ;
V_107 -> V_104 = V_104 ;
F_64 ( V_4 , F_65 ( V_4 ) - V_4 -> V_120 ) ;
F_57 ( V_4 ) ;
if ( F_58 ( V_48 , V_4 ) )
F_59 ( V_4 ) ;
}
static inline bool F_66 ( struct V_106 * V_107 )
{
return V_107 -> V_109 . V_111 == V_112 ||
V_107 -> V_109 . V_111 == V_122 || V_107 -> V_104 ;
}
static bool F_67 ( const struct V_59 * V_48 ,
struct V_3 * V_4 ,
int V_111 )
{
struct V_5 * V_6 ;
if ( V_111 == V_112 )
return true ;
if ( V_111 == V_122 )
return false ;
if ( ( ! ( V_48 -> V_123 & V_124 ) ) ||
( ! V_4 -> V_125 ) )
return false ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_84 . V_8 = F_3 ( V_4 ) -> V_126 ;
V_6 -> V_83 = V_4 -> V_125 -> V_127 ;
return true ;
}
int F_68 ( struct V_59 * V_48 , struct V_1 * V_2 , int V_39 , int * V_128 )
{
struct V_106 * V_107 ;
struct V_3 * V_4 ;
F_69 ( struct V_35 * , sin , V_2 -> V_129 ) ;
struct {
struct V_130 V_109 ;
struct V_35 V_131 ;
} V_132 ;
int V_33 ;
int V_133 ;
F_70 ( V_48 -> V_134 == V_135 ) ;
V_33 = - V_136 ;
V_4 = F_71 ( V_48 ) ;
if ( ! V_4 )
goto V_137;
V_133 = V_4 -> V_39 ;
if ( V_133 > V_39 ) {
V_2 -> V_21 |= V_138 ;
V_133 = V_39 ;
}
V_33 = F_72 ( V_4 , 0 , V_2 , V_133 ) ;
if ( F_73 ( V_33 ) ) {
F_59 ( V_4 ) ;
return V_33 ;
}
F_74 ( V_2 , V_48 , V_4 ) ;
V_107 = F_53 ( V_4 ) ;
if ( sin && F_66 ( V_107 ) ) {
sin -> V_40 = V_41 ;
sin -> V_42 . V_8 = * ( T_6 * ) ( F_55 ( V_4 ) +
V_107 -> V_119 ) ;
sin -> V_43 = V_107 -> V_104 ;
memset ( & sin -> V_44 , 0 , sizeof( sin -> V_44 ) ) ;
* V_128 = sizeof( * sin ) ;
}
memcpy ( & V_132 . V_109 , & V_107 -> V_109 , sizeof( struct V_130 ) ) ;
sin = & V_132 . V_131 ;
memset ( sin , 0 , sizeof( * sin ) ) ;
if ( F_67 ( V_48 , V_4 , V_107 -> V_109 . V_111 ) ) {
sin -> V_40 = V_41 ;
sin -> V_42 . V_8 = F_3 ( V_4 ) -> V_126 ;
if ( F_23 ( V_48 ) -> V_50 )
F_75 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_139 , sizeof( V_132 ) , & V_132 ) ;
V_2 -> V_21 |= V_140 ;
V_33 = V_133 ;
F_76 ( V_4 ) ;
V_137:
return V_33 ;
}
static bool F_77 ( int V_141 )
{
switch ( V_141 ) {
case V_142 :
case V_143 :
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
return true ;
}
return false ;
}
static int F_78 ( struct V_59 * V_48 , int V_156 ,
int V_141 , char T_7 * V_157 , unsigned int V_17 )
{
struct V_46 * V_47 = F_23 ( V_48 ) ;
struct V_66 * V_66 = F_25 ( V_48 ) ;
int V_63 = 0 , V_33 ;
bool V_158 = F_77 ( V_141 ) ;
switch ( V_141 ) {
case V_11 :
case V_159 :
case V_18 :
case V_160 :
case V_23 :
case V_14 :
case V_13 :
case V_161 :
case V_162 :
case V_139 :
case V_163 :
case V_164 :
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
case V_29 :
if ( V_17 >= sizeof( int ) ) {
if ( F_79 ( V_63 , ( int T_7 * ) V_157 ) )
return - V_175 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_176 ;
if ( F_79 ( V_176 , ( unsigned char T_7 * ) V_157 ) )
return - V_175 ;
V_63 = ( int ) V_176 ;
}
}
if ( F_80 ( V_141 ) )
return F_81 ( V_48 , V_141 , V_157 , V_17 ) ;
V_33 = 0 ;
if ( V_158 )
F_82 () ;
F_83 ( V_48 ) ;
switch ( V_141 ) {
case V_177 :
{
struct V_178 * V_179 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_180;
V_33 = F_84 ( F_25 ( V_48 ) , & V_16 ,
V_157 , V_17 ) ;
if ( V_33 )
break;
V_179 = F_44 ( V_47 -> V_181 ,
F_85 ( V_48 ) ) ;
if ( V_47 -> V_182 ) {
struct V_183 * V_184 = F_86 ( V_48 ) ;
#if F_28 ( V_68 )
if ( V_48 -> V_134 == V_185 ||
( ! ( ( 1 << V_48 -> V_186 ) &
( V_187 | V_188 ) ) &&
V_47 -> V_189 != V_190 ) ) {
#endif
if ( V_179 )
V_184 -> V_191 -= V_179 -> V_16 . V_17 ;
if ( V_16 )
V_184 -> V_191 += V_16 -> V_16 . V_17 ;
V_184 -> V_192 ( V_48 , V_184 -> V_193 ) ;
#if F_28 ( V_68 )
}
#endif
}
F_49 ( V_47 -> V_181 , V_16 ) ;
if ( V_179 )
F_87 ( V_179 , V_90 ) ;
break;
}
case V_11 :
if ( V_63 )
V_47 -> V_50 |= V_51 ;
else
V_47 -> V_50 &= ~ V_51 ;
break;
case V_159 :
if ( V_63 )
V_47 -> V_50 |= V_52 ;
else
V_47 -> V_50 &= ~ V_52 ;
break;
case V_160 :
if ( V_63 )
V_47 -> V_50 |= V_53 ;
else
V_47 -> V_50 &= ~ V_53 ;
break;
case V_18 :
if ( V_63 )
V_47 -> V_50 |= V_54 ;
else
V_47 -> V_50 &= ~ V_54 ;
break;
case V_23 :
if ( V_63 )
V_47 -> V_50 |= V_55 ;
else
V_47 -> V_50 &= ~ V_55 ;
break;
case V_165 :
if ( V_63 )
V_47 -> V_50 |= V_56 ;
else
V_47 -> V_50 &= ~ V_56 ;
break;
case V_174 :
if ( V_63 )
V_47 -> V_50 |= V_57 ;
else
V_47 -> V_50 &= ~ V_57 ;
break;
case V_29 :
if ( V_63 ) {
if ( ! ( V_47 -> V_50 & V_58 ) ) {
F_88 ( V_48 ) ;
V_47 -> V_50 |= V_58 ;
}
} else {
if ( V_47 -> V_50 & V_58 ) {
F_89 ( V_48 ) ;
V_47 -> V_50 &= ~ V_58 ;
}
}
break;
case V_14 :
if ( V_48 -> V_95 == V_194 ) {
V_63 &= ~ V_195 ;
V_63 |= V_47 -> V_15 & V_195 ;
}
if ( V_47 -> V_15 != V_63 ) {
V_47 -> V_15 = V_63 ;
V_48 -> V_196 = F_35 ( V_63 ) ;
F_90 ( V_48 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_180;
if ( V_63 != - 1 && ( V_63 < 1 || V_63 > 255 ) )
goto V_180;
V_47 -> V_197 = V_63 ;
break;
case V_161 :
if ( V_48 -> V_95 != V_96 ) {
V_33 = - V_198 ;
break;
}
V_47 -> V_199 = V_63 ? 1 : 0 ;
break;
case V_168 :
if ( V_48 -> V_95 != V_96 ) {
V_33 = - V_198 ;
break;
}
V_47 -> V_200 = V_63 ? 1 : 0 ;
break;
case V_169 :
V_47 -> V_201 = V_63 ? 1 : 0 ;
break;
case V_162 :
if ( V_63 < V_202 || V_63 > V_203 )
goto V_180;
V_47 -> V_204 = V_63 ;
break;
case V_139 :
V_47 -> V_121 = ! ! V_63 ;
if ( ! V_63 )
F_91 ( & V_48 -> V_205 ) ;
break;
case V_171 :
if ( V_48 -> V_95 == V_194 )
goto V_180;
if ( V_17 < 1 )
goto V_180;
if ( V_63 == - 1 )
V_63 = 1 ;
if ( V_63 < 0 || V_63 > 255 )
goto V_180;
V_47 -> V_206 = V_63 ;
break;
case V_173 :
if ( V_17 < 1 )
goto V_180;
V_47 -> V_207 = ! ! V_63 ;
break;
case V_170 :
{
struct V_208 * V_125 = NULL ;
int V_127 ;
if ( V_17 != sizeof( int ) )
goto V_180;
V_127 = ( V_209 int ) F_92 ( ( V_209 T_6 ) V_63 ) ;
if ( V_127 == 0 ) {
V_47 -> V_210 = 0 ;
V_33 = 0 ;
break;
}
V_125 = F_93 ( F_25 ( V_48 ) , V_127 ) ;
V_33 = - V_211 ;
if ( ! V_125 )
break;
F_94 ( V_125 ) ;
V_33 = - V_67 ;
if ( V_48 -> V_212 )
break;
V_47 -> V_210 = V_127 ;
V_33 = 0 ;
break;
}
case V_213 :
{
struct V_214 V_215 ;
struct V_208 * V_125 = NULL ;
if ( V_48 -> V_95 == V_194 )
goto V_180;
if ( V_17 < sizeof( struct V_216 ) )
goto V_180;
V_33 = - V_175 ;
if ( V_17 >= sizeof( struct V_214 ) ) {
if ( F_95 ( & V_215 , V_157 , sizeof( V_215 ) ) )
break;
} else {
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
if ( V_17 >= sizeof( struct V_217 ) ) {
if ( F_95 ( & V_215 , V_157 ,
sizeof( struct V_217 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_216 ) ) {
if ( F_95 ( & V_215 . V_218 , V_157 ,
sizeof( struct V_216 ) ) )
break;
}
}
if ( ! V_215 . V_219 ) {
if ( V_215 . V_218 . V_8 == F_96 ( V_220 ) ) {
V_47 -> V_221 = 0 ;
V_47 -> V_222 = 0 ;
V_33 = 0 ;
break;
}
V_125 = F_97 ( F_25 ( V_48 ) , V_215 . V_218 . V_8 ) ;
if ( V_125 )
V_215 . V_219 = V_125 -> V_127 ;
} else
V_125 = F_93 ( F_25 ( V_48 ) , V_215 . V_219 ) ;
V_33 = - V_211 ;
if ( ! V_125 )
break;
F_94 ( V_125 ) ;
V_33 = - V_67 ;
if ( V_48 -> V_212 &&
V_215 . V_219 != V_48 -> V_212 )
break;
V_47 -> V_221 = V_215 . V_219 ;
V_47 -> V_222 = V_215 . V_218 . V_8 ;
V_33 = 0 ;
break;
}
case V_142 :
case V_145 :
{
struct V_214 V_215 ;
V_33 = - V_223 ;
if ( F_23 ( V_48 ) -> V_182 )
break;
if ( V_17 < sizeof( struct V_217 ) )
goto V_180;
V_33 = - V_175 ;
if ( V_17 >= sizeof( struct V_214 ) ) {
if ( F_95 ( & V_215 , V_157 , sizeof( V_215 ) ) )
break;
} else {
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
if ( F_95 ( & V_215 , V_157 , sizeof( struct V_217 ) ) )
break;
}
if ( V_141 == V_142 )
V_33 = F_98 ( V_48 , & V_215 ) ;
else
V_33 = F_99 ( V_48 , & V_215 ) ;
break;
}
case V_147 :
{
struct V_224 * V_225 ;
if ( V_17 < F_100 ( 0 ) )
goto V_180;
if ( V_17 > V_226 ) {
V_33 = - V_103 ;
break;
}
V_225 = F_42 ( V_17 , V_99 ) ;
if ( ! V_225 ) {
V_33 = - V_103 ;
break;
}
V_33 = - V_175 ;
if ( F_95 ( V_225 , V_157 , V_17 ) ) {
F_39 ( V_225 ) ;
break;
}
if ( V_225 -> V_227 >= 0x3ffffffcU ||
V_225 -> V_227 > V_66 -> V_228 . V_229 ) {
F_39 ( V_225 ) ;
V_33 = - V_103 ;
break;
}
if ( F_100 ( V_225 -> V_227 ) > V_17 ) {
F_39 ( V_225 ) ;
V_33 = - V_67 ;
break;
}
V_33 = F_101 ( V_48 , V_225 , 0 ) ;
F_39 ( V_225 ) ;
break;
}
case V_144 :
case V_148 :
case V_143 :
case V_146 :
{
struct V_230 V_231 ;
int V_232 , V_233 ;
if ( V_17 != sizeof( struct V_230 ) )
goto V_180;
if ( F_95 ( & V_231 , V_157 , sizeof( V_231 ) ) ) {
V_33 = - V_175 ;
break;
}
if ( V_141 == V_144 ) {
V_232 = V_234 ;
V_233 = 1 ;
} else if ( V_141 == V_148 ) {
V_232 = V_234 ;
V_233 = 0 ;
} else if ( V_141 == V_143 ) {
struct V_214 V_215 ;
V_215 . V_235 . V_8 = V_231 . V_235 ;
V_215 . V_218 . V_8 = V_231 . V_236 ;
V_215 . V_219 = 0 ;
V_33 = F_98 ( V_48 , & V_215 ) ;
if ( V_33 && V_33 != - V_102 )
break;
V_232 = V_237 ;
V_233 = 1 ;
} else {
V_232 = V_237 ;
V_233 = 0 ;
}
V_33 = F_102 ( V_233 , V_232 , V_48 , & V_231 , 0 ) ;
break;
}
case V_151 :
case V_153 :
{
struct V_238 V_239 ;
struct V_35 * V_240 ;
struct V_214 V_215 ;
if ( V_17 < sizeof( struct V_238 ) )
goto V_180;
V_33 = - V_175 ;
if ( F_95 ( & V_239 , V_157 , sizeof( V_239 ) ) )
break;
V_240 = (struct V_35 * ) & V_239 . V_241 ;
if ( V_240 -> V_40 != V_41 )
goto V_180;
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
V_215 . V_235 = V_240 -> V_42 ;
V_215 . V_219 = V_239 . V_242 ;
if ( V_141 == V_151 )
V_33 = F_98 ( V_48 , & V_215 ) ;
else
V_33 = F_99 ( V_48 , & V_215 ) ;
break;
}
case V_152 :
case V_154 :
case V_149 :
case V_155 :
{
struct V_243 V_244 ;
struct V_230 V_231 ;
struct V_35 * V_240 ;
int V_232 , V_233 ;
if ( V_17 != sizeof( struct V_243 ) )
goto V_180;
if ( F_95 ( & V_244 , V_157 , sizeof( V_244 ) ) ) {
V_33 = - V_175 ;
break;
}
if ( V_244 . V_245 . V_246 != V_41 ||
V_244 . V_247 . V_246 != V_41 ) {
V_33 = - V_211 ;
break;
}
V_240 = (struct V_35 * ) & V_244 . V_245 ;
V_231 . V_235 = V_240 -> V_42 . V_8 ;
V_240 = (struct V_35 * ) & V_244 . V_247 ;
V_231 . V_248 = V_240 -> V_42 . V_8 ;
V_231 . V_236 = 0 ;
if ( V_141 == V_149 ) {
V_232 = V_234 ;
V_233 = 1 ;
} else if ( V_141 == V_155 ) {
V_232 = V_234 ;
V_233 = 0 ;
} else if ( V_141 == V_152 ) {
struct V_214 V_215 ;
V_240 = (struct V_35 * ) & V_244 . V_245 ;
V_215 . V_235 = V_240 -> V_42 ;
V_215 . V_218 . V_8 = 0 ;
V_215 . V_219 = V_244 . V_249 ;
V_33 = F_98 ( V_48 , & V_215 ) ;
if ( V_33 && V_33 != - V_102 )
break;
V_244 . V_249 = V_215 . V_219 ;
V_232 = V_237 ;
V_233 = 1 ;
} else {
V_232 = V_237 ;
V_233 = 0 ;
}
V_33 = F_102 ( V_233 , V_232 , V_48 , & V_231 ,
V_244 . V_249 ) ;
break;
}
case V_150 :
{
struct V_35 * V_240 ;
struct V_224 * V_225 = NULL ;
struct V_250 * V_251 = NULL ;
int V_252 , V_253 , V_127 ;
if ( V_17 < F_103 ( 0 ) )
goto V_180;
if ( V_17 > V_226 ) {
V_33 = - V_103 ;
break;
}
V_251 = F_42 ( V_17 , V_99 ) ;
if ( ! V_251 ) {
V_33 = - V_103 ;
break;
}
V_33 = - V_175 ;
if ( F_95 ( V_251 , V_157 , V_17 ) )
goto V_254;
if ( V_251 -> V_255 >= 0x1ffffff ||
V_251 -> V_255 > V_66 -> V_228 . V_229 ) {
V_33 = - V_103 ;
goto V_254;
}
if ( F_103 ( V_251 -> V_255 ) > V_17 ) {
V_33 = - V_67 ;
goto V_254;
}
V_252 = F_100 ( V_251 -> V_255 ) ;
V_225 = F_42 ( V_252 , V_99 ) ;
if ( ! V_225 ) {
V_33 = - V_103 ;
goto V_254;
}
V_127 = V_251 -> V_256 ;
V_240 = (struct V_35 * ) & V_251 -> V_257 ;
if ( V_240 -> V_40 != V_41 ) {
V_33 = - V_211 ;
goto V_254;
}
V_225 -> V_258 = V_240 -> V_42 . V_8 ;
V_225 -> V_259 = 0 ;
V_225 -> V_260 = V_251 -> V_261 ;
V_225 -> V_227 = V_251 -> V_255 ;
V_33 = - V_211 ;
for ( V_253 = 0 ; V_253 < V_251 -> V_255 ; ++ V_253 ) {
V_240 = (struct V_35 * ) & V_251 -> V_262 [ V_253 ] ;
if ( V_240 -> V_40 != V_41 )
goto V_254;
V_225 -> V_263 [ V_253 ] = V_240 -> V_42 . V_8 ;
}
F_39 ( V_251 ) ;
V_251 = NULL ;
V_33 = F_101 ( V_48 , V_225 , V_127 ) ;
V_254:
F_39 ( V_225 ) ;
F_39 ( V_251 ) ;
break;
}
case V_172 :
if ( V_17 < 1 )
goto V_180;
if ( V_63 != 0 && V_63 != 1 )
goto V_180;
V_47 -> V_264 = V_63 ;
break;
case V_163 :
V_33 = F_40 ( V_48 , V_63 ? 1 : 0 , NULL ) ;
break;
case V_164 :
if ( V_17 < 1 )
goto V_180;
V_47 -> V_265 = ! ! V_63 ;
break;
case V_266 :
case V_267 :
V_33 = - V_268 ;
if ( ! F_104 ( F_25 ( V_48 ) -> V_269 , V_270 ) )
break;
V_33 = F_105 ( V_48 , V_141 , V_157 , V_17 ) ;
break;
case V_166 :
if ( ! ! V_63 && ! F_104 ( F_25 ( V_48 ) -> V_269 , V_271 ) &&
! F_104 ( F_25 ( V_48 ) -> V_269 , V_270 ) ) {
V_33 = - V_268 ;
break;
}
if ( V_17 < 1 )
goto V_180;
V_47 -> V_272 = ! ! V_63 ;
break;
case V_167 :
if ( V_17 < 1 )
goto V_180;
if ( V_63 < 0 || V_63 > 255 )
goto V_180;
V_47 -> V_273 = V_63 ;
break;
default:
V_33 = - V_198 ;
break;
}
F_106 ( V_48 ) ;
if ( V_158 )
F_107 () ;
return V_33 ;
V_180:
F_106 ( V_48 ) ;
if ( V_158 )
F_107 () ;
return - V_67 ;
}
void F_108 ( const struct V_59 * V_48 , struct V_3 * V_4 )
{
struct V_5 * V_274 = F_2 ( V_4 ) ;
bool V_275 = ( F_23 ( V_48 ) -> V_50 & V_51 ) ||
F_109 ( V_48 ) ;
if ( V_275 && F_110 ( V_4 ) ) {
V_274 -> V_84 . V_8 = F_111 ( V_4 ) ;
} else {
V_274 -> V_83 = 0 ;
V_274 -> V_84 . V_8 = 0 ;
}
F_112 ( V_4 ) ;
}
int F_113 ( struct V_59 * V_48 , int V_156 ,
int V_141 , char T_7 * V_157 , unsigned int V_17 )
{
int V_33 ;
if ( V_156 != V_10 )
return - V_198 ;
V_33 = F_78 ( V_48 , V_156 , V_141 , V_157 , V_17 ) ;
#ifdef F_114
if ( V_33 == - V_198 && V_141 != V_161 &&
V_141 != V_266 &&
V_141 != V_267 &&
! F_80 ( V_141 ) ) {
F_83 ( V_48 ) ;
V_33 = F_115 ( V_48 , V_185 , V_141 , V_157 , V_17 ) ;
F_106 ( V_48 ) ;
}
#endif
return V_33 ;
}
int F_116 ( struct V_59 * V_48 , int V_156 , int V_141 ,
char T_7 * V_157 , unsigned int V_17 )
{
int V_33 ;
if ( V_156 != V_10 )
return - V_198 ;
if ( V_141 >= V_151 && V_141 <= V_150 )
return F_117 ( V_48 , V_156 , V_141 , V_157 , V_17 ,
F_113 ) ;
V_33 = F_78 ( V_48 , V_156 , V_141 , V_157 , V_17 ) ;
#ifdef F_114
if ( V_33 == - V_198 && V_141 != V_161 &&
V_141 != V_266 &&
V_141 != V_267 &&
! F_80 ( V_141 ) ) {
F_83 ( V_48 ) ;
V_33 = F_118 ( V_48 , V_185 , V_141 ,
V_157 , V_17 ) ;
F_106 ( V_48 ) ;
}
#endif
return V_33 ;
}
static bool F_119 ( int V_141 )
{
switch ( V_141 ) {
case V_147 :
case V_150 :
return true ;
}
return false ;
}
static int F_120 ( struct V_59 * V_48 , int V_156 , int V_141 ,
char T_7 * V_157 , int T_7 * V_17 , unsigned int V_49 )
{
struct V_46 * V_47 = F_23 ( V_48 ) ;
bool V_158 = F_119 ( V_141 ) ;
int V_63 , V_33 = 0 ;
int V_39 ;
if ( V_156 != V_10 )
return - V_276 ;
if ( F_80 ( V_141 ) )
return F_121 ( V_48 , V_141 , V_157 , V_17 ) ;
if ( F_79 ( V_39 , V_17 ) )
return - V_175 ;
if ( V_39 < 0 )
return - V_67 ;
if ( V_158 )
F_82 () ;
F_83 ( V_48 ) ;
switch ( V_141 ) {
case V_177 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_178 * V_181 ;
V_181 = F_44 ( V_47 -> V_181 ,
F_85 ( V_48 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_181 )
memcpy ( V_19 , & V_181 -> V_16 ,
sizeof( struct V_20 ) +
V_181 -> V_16 . V_17 ) ;
F_106 ( V_48 ) ;
if ( V_16 -> V_17 == 0 )
return F_122 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_39 = F_123 (unsigned int, len, opt->optlen) ;
if ( F_122 ( V_39 , V_17 ) )
return - V_175 ;
if ( F_124 ( V_157 , V_16 -> V_24 , V_39 ) )
return - V_175 ;
return 0 ;
}
case V_11 :
V_63 = ( V_47 -> V_50 & V_51 ) != 0 ;
break;
case V_159 :
V_63 = ( V_47 -> V_50 & V_52 ) != 0 ;
break;
case V_160 :
V_63 = ( V_47 -> V_50 & V_53 ) != 0 ;
break;
case V_18 :
V_63 = ( V_47 -> V_50 & V_54 ) != 0 ;
break;
case V_23 :
V_63 = ( V_47 -> V_50 & V_55 ) != 0 ;
break;
case V_165 :
V_63 = ( V_47 -> V_50 & V_56 ) != 0 ;
break;
case V_174 :
V_63 = ( V_47 -> V_50 & V_57 ) != 0 ;
break;
case V_29 :
V_63 = ( V_47 -> V_50 & V_58 ) != 0 ;
break;
case V_14 :
V_63 = V_47 -> V_15 ;
break;
case V_13 :
{
struct V_66 * V_66 = F_25 ( V_48 ) ;
V_63 = ( V_47 -> V_197 == - 1 ?
V_66 -> V_228 . V_277 :
V_47 -> V_197 ) ;
break;
}
case V_161 :
V_63 = V_47 -> V_199 ;
break;
case V_168 :
V_63 = V_47 -> V_200 ;
break;
case V_169 :
V_63 = V_47 -> V_201 ;
break;
case V_162 :
V_63 = V_47 -> V_204 ;
break;
case V_278 :
{
struct V_279 * V_280 ;
V_63 = 0 ;
V_280 = F_125 ( V_48 ) ;
if ( V_280 ) {
V_63 = F_126 ( V_280 ) ;
F_127 ( V_280 ) ;
}
if ( ! V_63 ) {
F_106 ( V_48 ) ;
return - V_281 ;
}
break;
}
case V_139 :
V_63 = V_47 -> V_121 ;
break;
case V_171 :
V_63 = V_47 -> V_206 ;
break;
case V_173 :
V_63 = V_47 -> V_207 ;
break;
case V_170 :
V_63 = ( V_209 int ) F_96 ( ( V_282 ) V_47 -> V_210 ) ;
break;
case V_213 :
{
struct V_216 V_79 ;
V_39 = F_123 (unsigned int, len, sizeof(struct in_addr)) ;
V_79 . V_8 = V_47 -> V_222 ;
F_106 ( V_48 ) ;
if ( F_122 ( V_39 , V_17 ) )
return - V_175 ;
if ( F_124 ( V_157 , & V_79 , V_39 ) )
return - V_175 ;
return 0 ;
}
case V_147 :
{
struct V_224 V_225 ;
if ( V_39 < F_100 ( 0 ) ) {
V_33 = - V_67 ;
goto V_137;
}
if ( F_95 ( & V_225 , V_157 , F_100 ( 0 ) ) ) {
V_33 = - V_175 ;
goto V_137;
}
V_33 = F_128 ( V_48 , & V_225 ,
(struct V_224 T_7 * ) V_157 , V_17 ) ;
goto V_137;
}
case V_150 :
{
struct V_250 V_251 ;
if ( V_39 < F_103 ( 0 ) ) {
V_33 = - V_67 ;
goto V_137;
}
if ( F_95 ( & V_251 , V_157 , F_103 ( 0 ) ) ) {
V_33 = - V_175 ;
goto V_137;
}
V_33 = F_129 ( V_48 , & V_251 ,
(struct V_250 T_7 * ) V_157 ,
V_17 ) ;
goto V_137;
}
case V_172 :
V_63 = V_47 -> V_264 ;
break;
case V_283 :
{
struct V_1 V_2 ;
F_106 ( V_48 ) ;
if ( V_48 -> V_95 != V_194 )
return - V_198 ;
V_2 . V_284 = ( V_209 void * ) V_157 ;
V_2 . V_285 = V_39 ;
V_2 . V_21 = V_49 ;
if ( V_47 -> V_50 & V_51 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_47 -> V_286 ;
V_6 . V_84 . V_8 = V_47 -> V_286 ;
V_6 . V_83 = V_47 -> V_221 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_47 -> V_50 & V_52 ) {
int V_287 = V_47 -> V_206 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_287 ) , & V_287 ) ;
}
if ( V_47 -> V_50 & V_53 ) {
int V_15 = V_47 -> V_288 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_39 -= V_2 . V_285 ;
return F_122 ( V_39 , V_17 ) ;
}
case V_164 :
V_63 = V_47 -> V_265 ;
break;
case V_166 :
V_63 = V_47 -> V_272 ;
break;
case V_167 :
V_63 = V_47 -> V_273 ;
break;
default:
F_106 ( V_48 ) ;
return - V_198 ;
}
F_106 ( V_48 ) ;
if ( V_39 < sizeof( int ) && V_39 > 0 && V_63 >= 0 && V_63 <= 255 ) {
unsigned char V_176 = ( unsigned char ) V_63 ;
V_39 = 1 ;
if ( F_122 ( V_39 , V_17 ) )
return - V_175 ;
if ( F_124 ( V_157 , & V_176 , 1 ) )
return - V_175 ;
} else {
V_39 = F_123 (unsigned int, sizeof(int), len) ;
if ( F_122 ( V_39 , V_17 ) )
return - V_175 ;
if ( F_124 ( V_157 , & V_63 , V_39 ) )
return - V_175 ;
}
return 0 ;
V_137:
F_106 ( V_48 ) ;
if ( V_158 )
F_107 () ;
return V_33 ;
}
int F_130 ( struct V_59 * V_48 , int V_156 ,
int V_141 , char T_7 * V_157 , int T_7 * V_17 )
{
int V_33 ;
V_33 = F_120 ( V_48 , V_156 , V_141 , V_157 , V_17 , 0 ) ;
#ifdef F_114
if ( V_33 == - V_198 && V_141 != V_283 &&
! F_80 ( V_141 ) ) {
int V_39 ;
if ( F_79 ( V_39 , V_17 ) )
return - V_175 ;
F_83 ( V_48 ) ;
V_33 = F_131 ( V_48 , V_185 , V_141 , V_157 ,
& V_39 ) ;
F_106 ( V_48 ) ;
if ( V_33 >= 0 )
V_33 = F_122 ( V_39 , V_17 ) ;
return V_33 ;
}
#endif
return V_33 ;
}
int F_132 ( struct V_59 * V_48 , int V_156 , int V_141 ,
char T_7 * V_157 , int T_7 * V_17 )
{
int V_33 ;
if ( V_141 == V_150 )
return F_133 ( V_48 , V_156 , V_141 , V_157 , V_17 ,
F_130 ) ;
V_33 = F_120 ( V_48 , V_156 , V_141 , V_157 , V_17 ,
V_289 ) ;
#ifdef F_114
if ( V_33 == - V_198 && V_141 != V_283 &&
! F_80 ( V_141 ) ) {
int V_39 ;
if ( F_79 ( V_39 , V_17 ) )
return - V_175 ;
F_83 ( V_48 ) ;
V_33 = F_134 ( V_48 , V_185 , V_141 , V_157 , & V_39 ) ;
F_106 ( V_48 ) ;
if ( V_33 >= 0 )
V_33 = F_122 ( V_39 , V_17 ) ;
return V_33 ;
}
#endif
return V_33 ;
}
