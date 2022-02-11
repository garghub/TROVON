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
V_26 = F_13 ( V_26 , F_14 ( V_4 -> V_29 , V_25 , 0 ) ) ;
F_4 ( V_2 , V_10 , V_30 , sizeof( T_1 ) , & V_26 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_31 ;
T_2 V_32 , V_33 ;
int V_34 ;
V_34 = F_16 ( NULL , V_4 , & V_33 ) ;
if ( V_34 )
return;
V_34 = F_17 ( V_33 , & V_31 , & V_32 ) ;
if ( V_34 )
return;
F_4 ( V_2 , V_10 , V_35 , V_32 , V_31 ) ;
F_18 ( V_31 , V_32 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_36 sin ;
const struct V_37 * V_38 = F_3 ( V_4 ) ;
T_3 * V_39 = ( T_3 * ) F_20 ( V_4 ) ;
if ( F_21 ( V_4 ) + 4 > V_4 -> V_40 )
return;
sin . V_41 = V_42 ;
sin . V_43 . V_8 = V_38 -> V_9 ;
sin . V_44 = V_39 [ 1 ] ;
memset ( sin . V_45 , 0 , sizeof( sin . V_45 ) ) ;
F_4 ( V_2 , V_10 , V_46 , sizeof( sin ) , & sin ) ;
}
void F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_25 )
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
F_15 ( V_2 , V_4 ) ;
V_50 &= ~ V_57 ;
if ( ! V_50 )
return;
}
if ( V_50 & V_58 ) {
F_19 ( V_2 , V_4 ) ;
V_50 &= ~ V_58 ;
if ( ! V_50 )
return;
}
if ( V_50 & V_59 )
F_12 ( V_2 , V_4 , V_25 ) ;
}
int F_24 ( struct V_60 * V_60 , struct V_1 * V_2 , struct V_61 * V_62 ,
bool V_63 )
{
int V_34 , V_64 ;
struct V_65 * V_66 ;
F_25 (cmsg, msg) {
if ( ! F_26 ( V_2 , V_66 ) )
return - V_67 ;
#if F_27 ( V_68 )
if ( V_63 &&
V_66 -> V_69 == V_70 &&
V_66 -> V_71 == V_72 ) {
struct V_73 * V_74 ;
if ( V_66 -> V_75 < F_28 ( sizeof( * V_74 ) ) )
return - V_67 ;
V_74 = (struct V_73 * ) F_29 ( V_66 ) ;
if ( ! F_30 ( & V_74 -> V_76 ) )
return - V_67 ;
V_62 -> V_77 = V_74 -> V_78 ;
V_62 -> V_79 = V_74 -> V_76 . V_80 [ 3 ] ;
continue;
}
#endif
if ( V_66 -> V_69 != V_10 )
continue;
switch ( V_66 -> V_71 ) {
case V_23 :
V_34 = V_66 -> V_75 - F_31 ( sizeof( struct V_65 ) ) ;
V_34 = F_32 ( V_60 , & V_62 -> V_16 , F_29 ( V_66 ) ,
V_34 < 40 ? V_34 : 40 ) ;
if ( V_34 )
return V_34 ;
break;
case V_11 :
{
struct V_5 * V_6 ;
if ( V_66 -> V_75 != F_28 ( sizeof( struct V_5 ) ) )
return - V_67 ;
V_6 = (struct V_5 * ) F_29 ( V_66 ) ;
V_62 -> V_77 = V_6 -> V_81 ;
V_62 -> V_79 = V_6 -> V_82 . V_8 ;
break;
}
case V_13 :
if ( V_66 -> V_75 != F_28 ( sizeof( int ) ) )
return - V_67 ;
V_64 = * ( int * ) F_29 ( V_66 ) ;
if ( V_64 < 1 || V_64 > 255 )
return - V_67 ;
V_62 -> V_12 = V_64 ;
break;
case V_14 :
if ( V_66 -> V_75 != F_28 ( sizeof( int ) ) )
return - V_67 ;
V_64 = * ( int * ) F_29 ( V_66 ) ;
if ( V_64 < 0 || V_64 > 255 )
return - V_67 ;
V_62 -> V_15 = V_64 ;
V_62 -> V_83 = F_33 ( V_62 -> V_15 ) ;
break;
default:
return - V_67 ;
}
}
return 0 ;
}
static void F_34 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = F_35 ( V_85 , struct V_86 , V_88 ) ;
F_36 ( V_87 -> V_89 ) ;
F_37 ( V_87 ) ;
}
int F_38 ( struct V_90 * V_49 , unsigned char V_91 ,
void (* F_39)( struct V_90 * ) )
{
struct V_86 * V_87 , * V_92 ;
struct V_86 T_4 * * V_93 ;
if ( V_49 -> V_94 != V_95 || F_23 ( V_49 ) -> V_96 == V_97 )
return - V_67 ;
V_92 = V_91 ? F_40 ( sizeof( * V_92 ) , V_98 ) : NULL ;
F_41 ( & V_99 ) ;
for ( V_93 = & V_86 ;
( V_87 = F_42 ( * V_93 ,
F_43 ( & V_99 ) ) ) != NULL ;
V_93 = & V_87 -> V_100 ) {
if ( V_87 -> V_49 == V_49 ) {
if ( V_91 ) {
F_44 ( & V_99 ) ;
F_37 ( V_92 ) ;
return - V_101 ;
}
V_87 -> V_49 = NULL ;
F_45 ( * V_93 , V_87 -> V_100 ) ;
F_44 ( & V_99 ) ;
if ( V_87 -> F_39 )
V_87 -> F_39 ( V_49 ) ;
V_87 -> V_89 = V_49 ;
F_46 ( & V_87 -> V_88 , F_34 ) ;
return 0 ;
}
}
if ( ! V_92 ) {
F_44 ( & V_99 ) ;
return - V_102 ;
}
V_92 -> V_49 = V_49 ;
V_92 -> F_39 = F_39 ;
F_45 ( V_92 -> V_100 , V_87 ) ;
F_47 ( * V_93 , V_92 ) ;
F_48 ( V_49 ) ;
F_44 ( & V_99 ) ;
return 0 ;
}
void F_49 ( struct V_90 * V_49 , struct V_3 * V_4 , int V_34 ,
T_3 V_103 , T_2 V_6 , T_5 * V_104 )
{
struct V_105 * V_106 ;
V_4 = F_50 ( V_4 , V_107 ) ;
if ( ! V_4 )
return;
V_106 = F_51 ( V_4 ) ;
V_106 -> V_108 . V_109 = V_34 ;
V_106 -> V_108 . V_110 = V_111 ;
V_106 -> V_108 . V_112 = F_52 ( V_4 ) -> type ;
V_106 -> V_108 . V_113 = F_52 ( V_4 ) -> V_114 ;
V_106 -> V_108 . V_115 = 0 ;
V_106 -> V_108 . V_116 = V_6 ;
V_106 -> V_108 . V_117 = 0 ;
V_106 -> V_118 = ( T_5 * ) & ( ( (struct V_37 * ) ( F_52 ( V_4 ) + 1 ) ) -> V_9 ) -
F_53 ( V_4 ) ;
V_106 -> V_103 = V_103 ;
if ( F_54 ( V_4 , V_104 - V_4 -> V_29 ) ) {
F_55 ( V_4 ) ;
if ( F_56 ( V_49 , V_4 ) == 0 )
return;
}
F_57 ( V_4 ) ;
}
void F_58 ( struct V_90 * V_49 , int V_34 , T_6 V_9 , T_3 V_103 , T_2 V_6 )
{
struct V_47 * V_48 = F_23 ( V_49 ) ;
struct V_105 * V_106 ;
struct V_37 * V_38 ;
struct V_3 * V_4 ;
if ( ! V_48 -> V_119 )
return;
V_4 = F_59 ( sizeof( struct V_37 ) , V_107 ) ;
if ( ! V_4 )
return;
F_60 ( V_4 , sizeof( struct V_37 ) ) ;
F_61 ( V_4 ) ;
V_38 = F_3 ( V_4 ) ;
V_38 -> V_9 = V_9 ;
V_106 = F_51 ( V_4 ) ;
V_106 -> V_108 . V_109 = V_34 ;
V_106 -> V_108 . V_110 = V_120 ;
V_106 -> V_108 . V_112 = 0 ;
V_106 -> V_108 . V_113 = 0 ;
V_106 -> V_108 . V_115 = 0 ;
V_106 -> V_108 . V_116 = V_6 ;
V_106 -> V_108 . V_117 = 0 ;
V_106 -> V_118 = ( T_5 * ) & V_38 -> V_9 - F_53 ( V_4 ) ;
V_106 -> V_103 = V_103 ;
F_62 ( V_4 , F_63 ( V_4 ) - V_4 -> V_29 ) ;
F_55 ( V_4 ) ;
if ( F_56 ( V_49 , V_4 ) )
F_57 ( V_4 ) ;
}
static bool F_64 ( const struct V_90 * V_49 ,
struct V_3 * V_4 ,
int V_110 )
{
struct V_5 * V_6 ;
if ( V_110 == V_111 )
return true ;
if ( V_110 == V_120 )
return false ;
if ( ( ! ( V_49 -> V_121 & V_122 ) ) ||
( ! V_4 -> V_123 ) )
return false ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_82 . V_8 = F_3 ( V_4 ) -> V_124 ;
V_6 -> V_81 = V_4 -> V_123 -> V_125 ;
return true ;
}
int F_65 ( struct V_90 * V_49 , struct V_1 * V_2 , int V_40 , int * V_126 )
{
struct V_105 * V_106 ;
struct V_3 * V_4 ;
F_66 ( struct V_36 * , sin , V_2 -> V_127 ) ;
struct {
struct V_128 V_108 ;
struct V_36 V_129 ;
} V_130 ;
int V_34 ;
int V_131 ;
F_67 ( V_49 -> V_132 == V_133 ) ;
V_34 = - V_134 ;
V_4 = F_68 ( V_49 ) ;
if ( ! V_4 )
goto V_135;
V_131 = V_4 -> V_40 ;
if ( V_131 > V_40 ) {
V_2 -> V_21 |= V_136 ;
V_131 = V_40 ;
}
V_34 = F_69 ( V_4 , 0 , V_2 , V_131 ) ;
if ( V_34 )
goto V_137;
F_70 ( V_2 , V_49 , V_4 ) ;
V_106 = F_51 ( V_4 ) ;
if ( sin && V_106 -> V_103 ) {
sin -> V_41 = V_42 ;
sin -> V_43 . V_8 = * ( T_6 * ) ( F_53 ( V_4 ) +
V_106 -> V_118 ) ;
sin -> V_44 = V_106 -> V_103 ;
memset ( & sin -> V_45 , 0 , sizeof( sin -> V_45 ) ) ;
* V_126 = sizeof( * sin ) ;
}
memcpy ( & V_130 . V_108 , & V_106 -> V_108 , sizeof( struct V_128 ) ) ;
sin = & V_130 . V_129 ;
memset ( sin , 0 , sizeof( * sin ) ) ;
if ( F_64 ( V_49 , V_4 , V_106 -> V_108 . V_110 ) ) {
sin -> V_41 = V_42 ;
sin -> V_43 . V_8 = F_3 ( V_4 ) -> V_124 ;
if ( F_23 ( V_49 ) -> V_51 )
F_71 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_138 , sizeof( V_130 ) , & V_130 ) ;
V_2 -> V_21 |= V_139 ;
V_34 = V_131 ;
V_137:
F_57 ( V_4 ) ;
V_135:
return V_34 ;
}
static bool F_72 ( int V_140 )
{
switch ( V_140 ) {
case V_141 :
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
return true ;
}
return false ;
}
static int F_73 ( struct V_90 * V_49 , int V_155 ,
int V_140 , char T_7 * V_156 , unsigned int V_17 )
{
struct V_47 * V_48 = F_23 ( V_49 ) ;
int V_64 = 0 , V_34 ;
bool V_157 = F_72 ( V_140 ) ;
switch ( V_140 ) {
case V_11 :
case V_158 :
case V_18 :
case V_159 :
case V_23 :
case V_14 :
case V_13 :
case V_160 :
case V_161 :
case V_138 :
case V_162 :
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
case V_30 :
if ( V_17 >= sizeof( int ) ) {
if ( F_74 ( V_64 , ( int T_7 * ) V_156 ) )
return - V_173 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_174 ;
if ( F_74 ( V_174 , ( unsigned char T_7 * ) V_156 ) )
return - V_173 ;
V_64 = ( int ) V_174 ;
}
}
if ( F_75 ( V_140 ) )
return F_76 ( V_49 , V_140 , V_156 , V_17 ) ;
V_34 = 0 ;
if ( V_157 )
F_77 () ;
F_78 ( V_49 ) ;
switch ( V_140 ) {
case V_175 :
{
struct V_176 * V_177 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_178;
V_34 = F_79 ( F_80 ( V_49 ) , & V_16 ,
V_156 , V_17 ) ;
if ( V_34 )
break;
V_177 = F_42 ( V_48 -> V_179 ,
F_81 ( V_49 ) ) ;
if ( V_48 -> V_180 ) {
struct V_181 * V_182 = F_82 ( V_49 ) ;
#if F_27 ( V_68 )
if ( V_49 -> V_132 == V_183 ||
( ! ( ( 1 << V_49 -> V_184 ) &
( V_185 | V_186 ) ) &&
V_48 -> V_187 != V_188 ) ) {
#endif
if ( V_177 )
V_182 -> V_189 -= V_177 -> V_16 . V_17 ;
if ( V_16 )
V_182 -> V_189 += V_16 -> V_16 . V_17 ;
V_182 -> V_190 ( V_49 , V_182 -> V_191 ) ;
#if F_27 ( V_68 )
}
#endif
}
F_47 ( V_48 -> V_179 , V_16 ) ;
if ( V_177 )
F_83 ( V_177 , V_88 ) ;
break;
}
case V_11 :
if ( V_64 )
V_48 -> V_51 |= V_52 ;
else
V_48 -> V_51 &= ~ V_52 ;
break;
case V_158 :
if ( V_64 )
V_48 -> V_51 |= V_53 ;
else
V_48 -> V_51 &= ~ V_53 ;
break;
case V_159 :
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
case V_164 :
if ( V_64 )
V_48 -> V_51 |= V_57 ;
else
V_48 -> V_51 &= ~ V_57 ;
break;
case V_172 :
if ( V_64 )
V_48 -> V_51 |= V_58 ;
else
V_48 -> V_51 &= ~ V_58 ;
break;
case V_30 :
if ( V_64 ) {
if ( ! ( V_48 -> V_51 & V_59 ) ) {
F_84 ( V_49 ) ;
V_48 -> V_51 |= V_59 ;
}
} else {
if ( V_48 -> V_51 & V_59 ) {
F_85 ( V_49 ) ;
V_48 -> V_51 &= ~ V_59 ;
}
}
break;
case V_14 :
if ( V_49 -> V_94 == V_192 ) {
V_64 &= ~ V_193 ;
V_64 |= V_48 -> V_15 & V_193 ;
}
if ( V_48 -> V_15 != V_64 ) {
V_48 -> V_15 = V_64 ;
V_49 -> V_194 = F_33 ( V_64 ) ;
F_86 ( V_49 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_178;
if ( V_64 != - 1 && ( V_64 < 1 || V_64 > 255 ) )
goto V_178;
V_48 -> V_195 = V_64 ;
break;
case V_160 :
if ( V_49 -> V_94 != V_95 ) {
V_34 = - V_196 ;
break;
}
V_48 -> V_197 = V_64 ? 1 : 0 ;
break;
case V_167 :
if ( V_49 -> V_94 != V_95 ) {
V_34 = - V_196 ;
break;
}
V_48 -> V_198 = V_64 ? 1 : 0 ;
break;
case V_161 :
if ( V_64 < V_199 || V_64 > V_200 )
goto V_178;
V_48 -> V_201 = V_64 ;
break;
case V_138 :
V_48 -> V_119 = ! ! V_64 ;
if ( ! V_64 )
F_87 ( & V_49 -> V_202 ) ;
break;
case V_169 :
if ( V_49 -> V_94 == V_192 )
goto V_178;
if ( V_17 < 1 )
goto V_178;
if ( V_64 == - 1 )
V_64 = 1 ;
if ( V_64 < 0 || V_64 > 255 )
goto V_178;
V_48 -> V_203 = V_64 ;
break;
case V_171 :
if ( V_17 < 1 )
goto V_178;
V_48 -> V_204 = ! ! V_64 ;
break;
case V_168 :
{
struct V_205 * V_123 = NULL ;
int V_125 ;
if ( V_17 != sizeof( int ) )
goto V_178;
V_125 = ( V_206 int ) F_88 ( ( V_206 T_6 ) V_64 ) ;
if ( V_125 == 0 ) {
V_48 -> V_207 = 0 ;
V_34 = 0 ;
break;
}
V_123 = F_89 ( F_80 ( V_49 ) , V_125 ) ;
V_34 = - V_208 ;
if ( ! V_123 )
break;
F_90 ( V_123 ) ;
V_34 = - V_67 ;
if ( V_49 -> V_209 )
break;
V_48 -> V_207 = V_125 ;
V_34 = 0 ;
break;
}
case V_210 :
{
struct V_211 V_212 ;
struct V_205 * V_123 = NULL ;
if ( V_49 -> V_94 == V_192 )
goto V_178;
if ( V_17 < sizeof( struct V_213 ) )
goto V_178;
V_34 = - V_173 ;
if ( V_17 >= sizeof( struct V_211 ) ) {
if ( F_91 ( & V_212 , V_156 , sizeof( V_212 ) ) )
break;
} else {
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
if ( V_17 >= sizeof( struct V_214 ) ) {
if ( F_91 ( & V_212 , V_156 ,
sizeof( struct V_214 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_213 ) ) {
if ( F_91 ( & V_212 . V_215 , V_156 ,
sizeof( struct V_213 ) ) )
break;
}
}
if ( ! V_212 . V_216 ) {
if ( V_212 . V_215 . V_8 == F_92 ( V_217 ) ) {
V_48 -> V_218 = 0 ;
V_48 -> V_219 = 0 ;
V_34 = 0 ;
break;
}
V_123 = F_93 ( F_80 ( V_49 ) , V_212 . V_215 . V_8 ) ;
if ( V_123 )
V_212 . V_216 = V_123 -> V_125 ;
} else
V_123 = F_89 ( F_80 ( V_49 ) , V_212 . V_216 ) ;
V_34 = - V_208 ;
if ( ! V_123 )
break;
F_90 ( V_123 ) ;
V_34 = - V_67 ;
if ( V_49 -> V_209 &&
V_212 . V_216 != V_49 -> V_209 )
break;
V_48 -> V_218 = V_212 . V_216 ;
V_48 -> V_219 = V_212 . V_215 . V_8 ;
V_34 = 0 ;
break;
}
case V_141 :
case V_144 :
{
struct V_211 V_212 ;
V_34 = - V_220 ;
if ( F_23 ( V_49 ) -> V_180 )
break;
if ( V_17 < sizeof( struct V_214 ) )
goto V_178;
V_34 = - V_173 ;
if ( V_17 >= sizeof( struct V_211 ) ) {
if ( F_91 ( & V_212 , V_156 , sizeof( V_212 ) ) )
break;
} else {
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
if ( F_91 ( & V_212 , V_156 , sizeof( struct V_214 ) ) )
break;
}
if ( V_140 == V_141 )
V_34 = F_94 ( V_49 , & V_212 ) ;
else
V_34 = F_95 ( V_49 , & V_212 ) ;
break;
}
case V_146 :
{
struct V_221 * V_222 ;
if ( V_17 < F_96 ( 0 ) )
goto V_178;
if ( V_17 > V_223 ) {
V_34 = - V_102 ;
break;
}
V_222 = F_40 ( V_17 , V_98 ) ;
if ( ! V_222 ) {
V_34 = - V_102 ;
break;
}
V_34 = - V_173 ;
if ( F_91 ( V_222 , V_156 , V_17 ) ) {
F_37 ( V_222 ) ;
break;
}
if ( V_222 -> V_224 >= 0x3ffffffcU ||
V_222 -> V_224 > V_225 ) {
F_37 ( V_222 ) ;
V_34 = - V_102 ;
break;
}
if ( F_96 ( V_222 -> V_224 ) > V_17 ) {
F_37 ( V_222 ) ;
V_34 = - V_67 ;
break;
}
V_34 = F_97 ( V_49 , V_222 , 0 ) ;
F_37 ( V_222 ) ;
break;
}
case V_143 :
case V_147 :
case V_142 :
case V_145 :
{
struct V_226 V_227 ;
int V_228 , V_229 ;
if ( V_17 != sizeof( struct V_226 ) )
goto V_178;
if ( F_91 ( & V_227 , V_156 , sizeof( V_227 ) ) ) {
V_34 = - V_173 ;
break;
}
if ( V_140 == V_143 ) {
V_228 = V_230 ;
V_229 = 1 ;
} else if ( V_140 == V_147 ) {
V_228 = V_230 ;
V_229 = 0 ;
} else if ( V_140 == V_142 ) {
struct V_211 V_212 ;
V_212 . V_231 . V_8 = V_227 . V_231 ;
V_212 . V_215 . V_8 = V_227 . V_232 ;
V_212 . V_216 = 0 ;
V_34 = F_94 ( V_49 , & V_212 ) ;
if ( V_34 && V_34 != - V_101 )
break;
V_228 = V_233 ;
V_229 = 1 ;
} else {
V_228 = V_233 ;
V_229 = 0 ;
}
V_34 = F_98 ( V_229 , V_228 , V_49 , & V_227 , 0 ) ;
break;
}
case V_150 :
case V_152 :
{
struct V_234 V_235 ;
struct V_36 * V_236 ;
struct V_211 V_212 ;
if ( V_17 < sizeof( struct V_234 ) )
goto V_178;
V_34 = - V_173 ;
if ( F_91 ( & V_235 , V_156 , sizeof( V_235 ) ) )
break;
V_236 = (struct V_36 * ) & V_235 . V_237 ;
if ( V_236 -> V_41 != V_42 )
goto V_178;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . V_231 = V_236 -> V_43 ;
V_212 . V_216 = V_235 . V_238 ;
if ( V_140 == V_150 )
V_34 = F_94 ( V_49 , & V_212 ) ;
else
V_34 = F_95 ( V_49 , & V_212 ) ;
break;
}
case V_151 :
case V_153 :
case V_148 :
case V_154 :
{
struct V_239 V_240 ;
struct V_226 V_227 ;
struct V_36 * V_236 ;
int V_228 , V_229 ;
if ( V_17 != sizeof( struct V_239 ) )
goto V_178;
if ( F_91 ( & V_240 , V_156 , sizeof( V_240 ) ) ) {
V_34 = - V_173 ;
break;
}
if ( V_240 . V_241 . V_242 != V_42 ||
V_240 . V_243 . V_242 != V_42 ) {
V_34 = - V_208 ;
break;
}
V_236 = (struct V_36 * ) & V_240 . V_241 ;
V_227 . V_231 = V_236 -> V_43 . V_8 ;
V_236 = (struct V_36 * ) & V_240 . V_243 ;
V_227 . V_244 = V_236 -> V_43 . V_8 ;
V_227 . V_232 = 0 ;
if ( V_140 == V_148 ) {
V_228 = V_230 ;
V_229 = 1 ;
} else if ( V_140 == V_154 ) {
V_228 = V_230 ;
V_229 = 0 ;
} else if ( V_140 == V_151 ) {
struct V_211 V_212 ;
V_236 = (struct V_36 * ) & V_240 . V_241 ;
V_212 . V_231 = V_236 -> V_43 ;
V_212 . V_215 . V_8 = 0 ;
V_212 . V_216 = V_240 . V_245 ;
V_34 = F_94 ( V_49 , & V_212 ) ;
if ( V_34 && V_34 != - V_101 )
break;
V_240 . V_245 = V_212 . V_216 ;
V_228 = V_233 ;
V_229 = 1 ;
} else {
V_228 = V_233 ;
V_229 = 0 ;
}
V_34 = F_98 ( V_229 , V_228 , V_49 , & V_227 ,
V_240 . V_245 ) ;
break;
}
case V_149 :
{
struct V_36 * V_236 ;
struct V_221 * V_222 = NULL ;
struct V_246 * V_247 = NULL ;
int V_248 , V_249 , V_125 ;
if ( V_17 < F_99 ( 0 ) )
goto V_178;
if ( V_17 > V_223 ) {
V_34 = - V_102 ;
break;
}
V_247 = F_40 ( V_17 , V_98 ) ;
if ( ! V_247 ) {
V_34 = - V_102 ;
break;
}
V_34 = - V_173 ;
if ( F_91 ( V_247 , V_156 , V_17 ) )
goto V_250;
if ( V_247 -> V_251 >= 0x1ffffff ||
V_247 -> V_251 > V_225 ) {
V_34 = - V_102 ;
goto V_250;
}
if ( F_99 ( V_247 -> V_251 ) > V_17 ) {
V_34 = - V_67 ;
goto V_250;
}
V_248 = F_96 ( V_247 -> V_251 ) ;
V_222 = F_40 ( V_248 , V_98 ) ;
if ( ! V_222 ) {
V_34 = - V_102 ;
goto V_250;
}
V_125 = V_247 -> V_252 ;
V_236 = (struct V_36 * ) & V_247 -> V_253 ;
if ( V_236 -> V_41 != V_42 ) {
V_34 = - V_208 ;
goto V_250;
}
V_222 -> V_254 = V_236 -> V_43 . V_8 ;
V_222 -> V_255 = 0 ;
V_222 -> V_256 = V_247 -> V_257 ;
V_222 -> V_224 = V_247 -> V_251 ;
V_34 = - V_208 ;
for ( V_249 = 0 ; V_249 < V_247 -> V_251 ; ++ V_249 ) {
V_236 = (struct V_36 * ) & V_247 -> V_258 [ V_249 ] ;
if ( V_236 -> V_41 != V_42 )
goto V_250;
V_222 -> V_259 [ V_249 ] = V_236 -> V_43 . V_8 ;
}
F_37 ( V_247 ) ;
V_247 = NULL ;
V_34 = F_97 ( V_49 , V_222 , V_125 ) ;
V_250:
F_37 ( V_222 ) ;
F_37 ( V_247 ) ;
break;
}
case V_170 :
if ( V_17 < 1 )
goto V_178;
if ( V_64 != 0 && V_64 != 1 )
goto V_178;
V_48 -> V_260 = V_64 ;
break;
case V_162 :
V_34 = F_38 ( V_49 , V_64 ? 1 : 0 , NULL ) ;
break;
case V_163 :
if ( V_17 < 1 )
goto V_178;
V_48 -> V_261 = ! ! V_64 ;
break;
case V_262 :
case V_263 :
V_34 = - V_264 ;
if ( ! F_100 ( F_80 ( V_49 ) -> V_265 , V_266 ) )
break;
V_34 = F_101 ( V_49 , V_140 , V_156 , V_17 ) ;
break;
case V_165 :
if ( ! ! V_64 && ! F_100 ( F_80 ( V_49 ) -> V_265 , V_267 ) &&
! F_100 ( F_80 ( V_49 ) -> V_265 , V_266 ) ) {
V_34 = - V_264 ;
break;
}
if ( V_17 < 1 )
goto V_178;
V_48 -> V_268 = ! ! V_64 ;
break;
case V_166 :
if ( V_17 < 1 )
goto V_178;
if ( V_64 < 0 || V_64 > 255 )
goto V_178;
V_48 -> V_269 = V_64 ;
break;
default:
V_34 = - V_196 ;
break;
}
F_102 ( V_49 ) ;
if ( V_157 )
F_103 () ;
return V_34 ;
V_178:
F_102 ( V_49 ) ;
if ( V_157 )
F_103 () ;
return - V_67 ;
}
void F_104 ( const struct V_90 * V_49 , struct V_3 * V_4 )
{
struct V_5 * V_270 = F_2 ( V_4 ) ;
bool V_271 = ( F_23 ( V_49 ) -> V_51 & V_52 ) ||
F_105 ( V_49 ) ;
if ( V_271 && F_106 ( V_4 ) ) {
V_270 -> V_81 = F_107 ( V_4 ) ;
V_270 -> V_82 . V_8 = F_108 ( V_4 ) ;
} else {
V_270 -> V_81 = 0 ;
V_270 -> V_82 . V_8 = 0 ;
}
F_109 ( V_4 ) ;
}
int F_110 ( struct V_90 * V_49 , int V_155 ,
int V_140 , char T_7 * V_156 , unsigned int V_17 )
{
int V_34 ;
if ( V_155 != V_10 )
return - V_196 ;
V_34 = F_73 ( V_49 , V_155 , V_140 , V_156 , V_17 ) ;
#ifdef F_111
if ( V_34 == - V_196 && V_140 != V_160 &&
V_140 != V_262 &&
V_140 != V_263 &&
! F_75 ( V_140 ) ) {
F_78 ( V_49 ) ;
V_34 = F_112 ( V_49 , V_183 , V_140 , V_156 , V_17 ) ;
F_102 ( V_49 ) ;
}
#endif
return V_34 ;
}
int F_113 ( struct V_90 * V_49 , int V_155 , int V_140 ,
char T_7 * V_156 , unsigned int V_17 )
{
int V_34 ;
if ( V_155 != V_10 )
return - V_196 ;
if ( V_140 >= V_150 && V_140 <= V_149 )
return F_114 ( V_49 , V_155 , V_140 , V_156 , V_17 ,
F_110 ) ;
V_34 = F_73 ( V_49 , V_155 , V_140 , V_156 , V_17 ) ;
#ifdef F_111
if ( V_34 == - V_196 && V_140 != V_160 &&
V_140 != V_262 &&
V_140 != V_263 &&
! F_75 ( V_140 ) ) {
F_78 ( V_49 ) ;
V_34 = F_115 ( V_49 , V_183 , V_140 ,
V_156 , V_17 ) ;
F_102 ( V_49 ) ;
}
#endif
return V_34 ;
}
static int F_116 ( struct V_90 * V_49 , int V_155 , int V_140 ,
char T_7 * V_156 , int T_7 * V_17 , unsigned int V_50 )
{
struct V_47 * V_48 = F_23 ( V_49 ) ;
int V_64 ;
int V_40 ;
if ( V_155 != V_10 )
return - V_272 ;
if ( F_75 ( V_140 ) )
return F_117 ( V_49 , V_140 , V_156 , V_17 ) ;
if ( F_74 ( V_40 , V_17 ) )
return - V_173 ;
if ( V_40 < 0 )
return - V_67 ;
F_78 ( V_49 ) ;
switch ( V_140 ) {
case V_175 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_176 * V_179 ;
V_179 = F_42 ( V_48 -> V_179 ,
F_81 ( V_49 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_179 )
memcpy ( V_19 , & V_179 -> V_16 ,
sizeof( struct V_20 ) +
V_179 -> V_16 . V_17 ) ;
F_102 ( V_49 ) ;
if ( V_16 -> V_17 == 0 )
return F_118 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_40 = F_119 (unsigned int, len, opt->optlen) ;
if ( F_118 ( V_40 , V_17 ) )
return - V_173 ;
if ( F_120 ( V_156 , V_16 -> V_24 , V_40 ) )
return - V_173 ;
return 0 ;
}
case V_11 :
V_64 = ( V_48 -> V_51 & V_52 ) != 0 ;
break;
case V_158 :
V_64 = ( V_48 -> V_51 & V_53 ) != 0 ;
break;
case V_159 :
V_64 = ( V_48 -> V_51 & V_54 ) != 0 ;
break;
case V_18 :
V_64 = ( V_48 -> V_51 & V_55 ) != 0 ;
break;
case V_23 :
V_64 = ( V_48 -> V_51 & V_56 ) != 0 ;
break;
case V_164 :
V_64 = ( V_48 -> V_51 & V_57 ) != 0 ;
break;
case V_172 :
V_64 = ( V_48 -> V_51 & V_58 ) != 0 ;
break;
case V_30 :
V_64 = ( V_48 -> V_51 & V_59 ) != 0 ;
break;
case V_14 :
V_64 = V_48 -> V_15 ;
break;
case V_13 :
V_64 = ( V_48 -> V_195 == - 1 ?
V_273 :
V_48 -> V_195 ) ;
break;
case V_160 :
V_64 = V_48 -> V_197 ;
break;
case V_167 :
V_64 = V_48 -> V_198 ;
break;
case V_161 :
V_64 = V_48 -> V_201 ;
break;
case V_274 :
{
struct V_275 * V_276 ;
V_64 = 0 ;
V_276 = F_121 ( V_49 ) ;
if ( V_276 ) {
V_64 = F_122 ( V_276 ) ;
F_123 ( V_276 ) ;
}
if ( ! V_64 ) {
F_102 ( V_49 ) ;
return - V_277 ;
}
break;
}
case V_138 :
V_64 = V_48 -> V_119 ;
break;
case V_169 :
V_64 = V_48 -> V_203 ;
break;
case V_171 :
V_64 = V_48 -> V_204 ;
break;
case V_168 :
V_64 = ( V_206 int ) F_92 ( ( V_278 ) V_48 -> V_207 ) ;
break;
case V_210 :
{
struct V_213 V_79 ;
V_40 = F_119 (unsigned int, len, sizeof(struct in_addr)) ;
V_79 . V_8 = V_48 -> V_219 ;
F_102 ( V_49 ) ;
if ( F_118 ( V_40 , V_17 ) )
return - V_173 ;
if ( F_120 ( V_156 , & V_79 , V_40 ) )
return - V_173 ;
return 0 ;
}
case V_146 :
{
struct V_221 V_222 ;
int V_34 ;
if ( V_40 < F_96 ( 0 ) ) {
F_102 ( V_49 ) ;
return - V_67 ;
}
if ( F_91 ( & V_222 , V_156 , F_96 ( 0 ) ) ) {
F_102 ( V_49 ) ;
return - V_173 ;
}
V_34 = F_124 ( V_49 , & V_222 ,
(struct V_221 T_7 * ) V_156 , V_17 ) ;
F_102 ( V_49 ) ;
return V_34 ;
}
case V_149 :
{
struct V_246 V_247 ;
int V_34 ;
if ( V_40 < F_99 ( 0 ) ) {
F_102 ( V_49 ) ;
return - V_67 ;
}
if ( F_91 ( & V_247 , V_156 , F_99 ( 0 ) ) ) {
F_102 ( V_49 ) ;
return - V_173 ;
}
V_34 = F_125 ( V_49 , & V_247 ,
(struct V_246 T_7 * ) V_156 ,
V_17 ) ;
F_102 ( V_49 ) ;
return V_34 ;
}
case V_170 :
V_64 = V_48 -> V_260 ;
break;
case V_279 :
{
struct V_1 V_2 ;
F_102 ( V_49 ) ;
if ( V_49 -> V_94 != V_192 )
return - V_196 ;
V_2 . V_280 = ( V_206 void * ) V_156 ;
V_2 . V_281 = V_40 ;
V_2 . V_21 = V_50 ;
if ( V_48 -> V_51 & V_52 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_48 -> V_282 ;
V_6 . V_82 . V_8 = V_48 -> V_282 ;
V_6 . V_81 = V_48 -> V_218 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_48 -> V_51 & V_53 ) {
int V_283 = V_48 -> V_203 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_283 ) , & V_283 ) ;
}
if ( V_48 -> V_51 & V_54 ) {
int V_15 = V_48 -> V_284 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_40 -= V_2 . V_281 ;
return F_118 ( V_40 , V_17 ) ;
}
case V_163 :
V_64 = V_48 -> V_261 ;
break;
case V_165 :
V_64 = V_48 -> V_268 ;
break;
case V_166 :
V_64 = V_48 -> V_269 ;
break;
default:
F_102 ( V_49 ) ;
return - V_196 ;
}
F_102 ( V_49 ) ;
if ( V_40 < sizeof( int ) && V_40 > 0 && V_64 >= 0 && V_64 <= 255 ) {
unsigned char V_174 = ( unsigned char ) V_64 ;
V_40 = 1 ;
if ( F_118 ( V_40 , V_17 ) )
return - V_173 ;
if ( F_120 ( V_156 , & V_174 , 1 ) )
return - V_173 ;
} else {
V_40 = F_119 (unsigned int, sizeof(int), len) ;
if ( F_118 ( V_40 , V_17 ) )
return - V_173 ;
if ( F_120 ( V_156 , & V_64 , V_40 ) )
return - V_173 ;
}
return 0 ;
}
int F_126 ( struct V_90 * V_49 , int V_155 ,
int V_140 , char T_7 * V_156 , int T_7 * V_17 )
{
int V_34 ;
V_34 = F_116 ( V_49 , V_155 , V_140 , V_156 , V_17 , 0 ) ;
#ifdef F_111
if ( V_34 == - V_196 && V_140 != V_279 &&
! F_75 ( V_140 ) ) {
int V_40 ;
if ( F_74 ( V_40 , V_17 ) )
return - V_173 ;
F_78 ( V_49 ) ;
V_34 = F_127 ( V_49 , V_183 , V_140 , V_156 ,
& V_40 ) ;
F_102 ( V_49 ) ;
if ( V_34 >= 0 )
V_34 = F_118 ( V_40 , V_17 ) ;
return V_34 ;
}
#endif
return V_34 ;
}
int F_128 ( struct V_90 * V_49 , int V_155 , int V_140 ,
char T_7 * V_156 , int T_7 * V_17 )
{
int V_34 ;
if ( V_140 == V_149 )
return F_129 ( V_49 , V_155 , V_140 , V_156 , V_17 ,
F_126 ) ;
V_34 = F_116 ( V_49 , V_155 , V_140 , V_156 , V_17 ,
V_285 ) ;
#ifdef F_111
if ( V_34 == - V_196 && V_140 != V_279 &&
! F_75 ( V_140 ) ) {
int V_40 ;
if ( F_74 ( V_40 , V_17 ) )
return - V_173 ;
F_78 ( V_49 ) ;
V_34 = F_130 ( V_49 , V_183 , V_140 , V_156 , & V_40 ) ;
F_102 ( V_49 ) ;
if ( V_34 >= 0 )
V_34 = F_118 ( V_40 , V_17 ) ;
return V_34 ;
}
#endif
return V_34 ;
}
