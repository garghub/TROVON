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
char * V_25 ;
T_1 V_26 , V_27 ;
int V_28 ;
V_28 = F_13 ( NULL , V_4 , & V_27 ) ;
if ( V_28 )
return;
V_28 = F_14 ( V_27 , & V_25 , & V_26 ) ;
if ( V_28 )
return;
F_4 ( V_2 , V_10 , V_29 , V_26 , V_25 ) ;
F_15 ( V_25 , V_26 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_30 sin ;
const struct V_31 * V_32 = F_3 ( V_4 ) ;
T_2 * V_33 = ( T_2 * ) F_17 ( V_4 ) ;
if ( F_18 ( V_4 ) + 4 > V_4 -> V_34 )
return;
sin . V_35 = V_36 ;
sin . V_37 . V_8 = V_32 -> V_9 ;
sin . V_38 = V_33 [ 1 ] ;
memset ( sin . V_39 , 0 , sizeof( sin . V_39 ) ) ;
F_4 ( V_2 , V_10 , V_40 , sizeof( sin ) , & sin ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_41 * V_42 = F_20 ( V_4 -> V_43 ) ;
unsigned int V_44 = V_42 -> V_45 ;
if ( V_44 & 1 )
F_1 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_5 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_6 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_7 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_9 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_12 ( V_2 , V_4 ) ;
if ( ( V_44 >>= 1 ) == 0 )
return;
if ( V_44 & 1 )
F_16 ( V_2 , V_4 ) ;
}
int F_21 ( struct V_46 * V_46 , struct V_1 * V_2 , struct V_47 * V_48 ,
bool V_49 )
{
int V_28 , V_50 ;
struct V_51 * V_52 ;
F_22 (cmsg, msg) {
if ( ! F_23 ( V_2 , V_52 ) )
return - V_53 ;
#if F_24 ( V_54 )
if ( V_49 &&
V_52 -> V_55 == V_56 &&
V_52 -> V_57 == V_58 ) {
struct V_59 * V_60 ;
if ( V_52 -> V_61 < F_25 ( sizeof( * V_60 ) ) )
return - V_53 ;
V_60 = (struct V_59 * ) F_26 ( V_52 ) ;
if ( ! F_27 ( & V_60 -> V_62 ) )
return - V_53 ;
V_48 -> V_63 = V_60 -> V_64 ;
V_48 -> V_65 = V_60 -> V_62 . V_66 [ 3 ] ;
continue;
}
#endif
if ( V_52 -> V_55 != V_10 )
continue;
switch ( V_52 -> V_57 ) {
case V_23 :
V_28 = V_52 -> V_61 - F_28 ( sizeof( struct V_51 ) ) ;
V_28 = F_29 ( V_46 , & V_48 -> V_16 , F_26 ( V_52 ) ,
V_28 < 40 ? V_28 : 40 ) ;
if ( V_28 )
return V_28 ;
break;
case V_11 :
{
struct V_5 * V_6 ;
if ( V_52 -> V_61 != F_25 ( sizeof( struct V_5 ) ) )
return - V_53 ;
V_6 = (struct V_5 * ) F_26 ( V_52 ) ;
V_48 -> V_63 = V_6 -> V_67 ;
V_48 -> V_65 = V_6 -> V_68 . V_8 ;
break;
}
case V_13 :
if ( V_52 -> V_61 != F_25 ( sizeof( int ) ) )
return - V_53 ;
V_50 = * ( int * ) F_26 ( V_52 ) ;
if ( V_50 < 1 || V_50 > 255 )
return - V_53 ;
V_48 -> V_12 = V_50 ;
break;
case V_14 :
if ( V_52 -> V_61 != F_25 ( sizeof( int ) ) )
return - V_53 ;
V_50 = * ( int * ) F_26 ( V_52 ) ;
if ( V_50 < 0 || V_50 > 255 )
return - V_53 ;
V_48 -> V_15 = V_50 ;
V_48 -> V_69 = F_30 ( V_48 -> V_15 ) ;
break;
default:
return - V_53 ;
}
}
return 0 ;
}
static void F_31 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = F_32 ( V_71 , struct V_72 , V_74 ) ;
F_33 ( V_73 -> V_75 ) ;
F_34 ( V_73 ) ;
}
int F_35 ( struct V_76 * V_43 , unsigned char V_77 ,
void (* F_36)( struct V_76 * ) )
{
struct V_72 * V_73 , * V_78 ;
struct V_72 T_3 * * V_79 ;
if ( V_43 -> V_80 != V_81 || F_20 ( V_43 ) -> V_82 == V_83 )
return - V_53 ;
V_78 = V_77 ? F_37 ( sizeof( * V_78 ) , V_84 ) : NULL ;
F_38 ( & V_85 ) ;
for ( V_79 = & V_72 ;
( V_73 = F_39 ( * V_79 ,
F_40 ( & V_85 ) ) ) != NULL ;
V_79 = & V_73 -> V_86 ) {
if ( V_73 -> V_43 == V_43 ) {
if ( V_77 ) {
F_41 ( & V_85 ) ;
F_34 ( V_78 ) ;
return - V_87 ;
}
V_73 -> V_43 = NULL ;
F_42 ( * V_79 , V_73 -> V_86 ) ;
F_41 ( & V_85 ) ;
if ( V_73 -> F_36 )
V_73 -> F_36 ( V_43 ) ;
V_73 -> V_75 = V_43 ;
F_43 ( & V_73 -> V_74 , F_31 ) ;
return 0 ;
}
}
if ( V_78 == NULL ) {
F_41 ( & V_85 ) ;
return - V_88 ;
}
V_78 -> V_43 = V_43 ;
V_78 -> F_36 = F_36 ;
F_42 ( V_78 -> V_86 , V_73 ) ;
F_44 ( * V_79 , V_78 ) ;
F_45 ( V_43 ) ;
F_41 ( & V_85 ) ;
return 0 ;
}
void F_46 ( struct V_76 * V_43 , struct V_3 * V_4 , int V_28 ,
T_2 V_89 , T_1 V_6 , T_4 * V_90 )
{
struct V_91 * V_92 ;
V_4 = F_47 ( V_4 , V_93 ) ;
if ( ! V_4 )
return;
V_92 = F_48 ( V_4 ) ;
V_92 -> V_94 . V_95 = V_28 ;
V_92 -> V_94 . V_96 = V_97 ;
V_92 -> V_94 . V_98 = F_49 ( V_4 ) -> type ;
V_92 -> V_94 . V_99 = F_49 ( V_4 ) -> V_100 ;
V_92 -> V_94 . V_101 = 0 ;
V_92 -> V_94 . V_102 = V_6 ;
V_92 -> V_94 . V_103 = 0 ;
V_92 -> V_104 = ( T_4 * ) & ( ( (struct V_31 * ) ( F_49 ( V_4 ) + 1 ) ) -> V_9 ) -
F_50 ( V_4 ) ;
V_92 -> V_89 = V_89 ;
if ( F_51 ( V_4 , V_90 - V_4 -> V_105 ) != NULL ) {
F_52 ( V_4 ) ;
if ( F_53 ( V_43 , V_4 ) == 0 )
return;
}
F_54 ( V_4 ) ;
}
void F_55 ( struct V_76 * V_43 , int V_28 , T_5 V_9 , T_2 V_89 , T_1 V_6 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
struct V_91 * V_92 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
if ( ! V_42 -> V_106 )
return;
V_4 = F_56 ( sizeof( struct V_31 ) , V_93 ) ;
if ( ! V_4 )
return;
F_57 ( V_4 , sizeof( struct V_31 ) ) ;
F_58 ( V_4 ) ;
V_32 = F_3 ( V_4 ) ;
V_32 -> V_9 = V_9 ;
V_92 = F_48 ( V_4 ) ;
V_92 -> V_94 . V_95 = V_28 ;
V_92 -> V_94 . V_96 = V_107 ;
V_92 -> V_94 . V_98 = 0 ;
V_92 -> V_94 . V_99 = 0 ;
V_92 -> V_94 . V_101 = 0 ;
V_92 -> V_94 . V_102 = V_6 ;
V_92 -> V_94 . V_103 = 0 ;
V_92 -> V_104 = ( T_4 * ) & V_32 -> V_9 - F_50 ( V_4 ) ;
V_92 -> V_89 = V_89 ;
F_59 ( V_4 , F_60 ( V_4 ) - V_4 -> V_105 ) ;
F_52 ( V_4 ) ;
if ( F_53 ( V_43 , V_4 ) )
F_54 ( V_4 ) ;
}
static bool F_61 ( const struct V_76 * V_43 ,
const struct V_3 * V_4 ,
int V_96 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( ( V_96 != V_108 ) ||
( ! ( V_43 -> V_109 & V_110 ) ) ||
( ! V_4 -> V_111 ) )
return false ;
V_6 -> V_68 . V_8 = F_3 ( V_4 ) -> V_112 ;
V_6 -> V_67 = V_4 -> V_111 -> V_113 ;
return true ;
}
int F_62 ( struct V_76 * V_43 , struct V_1 * V_2 , int V_34 , int * V_114 )
{
struct V_91 * V_92 ;
struct V_3 * V_4 ;
F_63 ( struct V_30 * , sin , V_2 -> V_115 ) ;
struct {
struct V_116 V_94 ;
struct V_30 V_117 ;
} V_118 ;
int V_28 ;
int V_119 ;
F_64 ( V_43 -> V_120 == V_121 ) ;
V_28 = - V_122 ;
V_4 = F_65 ( V_43 ) ;
if ( V_4 == NULL )
goto V_123;
V_119 = V_4 -> V_34 ;
if ( V_119 > V_34 ) {
V_2 -> V_21 |= V_124 ;
V_119 = V_34 ;
}
V_28 = F_66 ( V_4 , 0 , V_2 , V_119 ) ;
if ( V_28 )
goto V_125;
F_67 ( V_2 , V_43 , V_4 ) ;
V_92 = F_48 ( V_4 ) ;
if ( sin ) {
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = * ( T_5 * ) ( F_50 ( V_4 ) +
V_92 -> V_104 ) ;
sin -> V_38 = V_92 -> V_89 ;
memset ( & sin -> V_39 , 0 , sizeof( sin -> V_39 ) ) ;
* V_114 = sizeof( * sin ) ;
}
memcpy ( & V_118 . V_94 , & V_92 -> V_94 , sizeof( struct V_116 ) ) ;
sin = & V_118 . V_117 ;
memset ( sin , 0 , sizeof( * sin ) ) ;
if ( V_92 -> V_94 . V_96 == V_97 ||
F_61 ( V_43 , V_4 , V_92 -> V_94 . V_96 ) ) {
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = F_3 ( V_4 ) -> V_112 ;
if ( F_20 ( V_43 ) -> V_45 )
F_19 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_126 , sizeof( V_118 ) , & V_118 ) ;
V_2 -> V_21 |= V_127 ;
V_28 = V_119 ;
V_125:
F_54 ( V_4 ) ;
V_123:
return V_28 ;
}
static int F_68 ( struct V_76 * V_43 , int V_128 ,
int V_129 , char T_6 * V_130 , unsigned int V_17 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_50 = 0 , V_28 ;
switch ( V_129 ) {
case V_11 :
case V_131 :
case V_18 :
case V_132 :
case V_23 :
case V_14 :
case V_13 :
case V_133 :
case V_134 :
case V_126 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
if ( V_17 >= sizeof( int ) ) {
if ( F_69 ( V_50 , ( int T_6 * ) V_130 ) )
return - V_146 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_147 ;
if ( F_69 ( V_147 , ( unsigned char T_6 * ) V_130 ) )
return - V_146 ;
V_50 = ( int ) V_147 ;
}
}
if ( F_70 ( V_129 ) )
return F_71 ( V_43 , V_129 , V_130 , V_17 ) ;
V_28 = 0 ;
F_72 ( V_43 ) ;
switch ( V_129 ) {
case V_148 :
{
struct V_149 * V_150 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_151;
V_28 = F_73 ( F_74 ( V_43 ) , & V_16 ,
V_130 , V_17 ) ;
if ( V_28 )
break;
V_150 = F_39 ( V_42 -> V_152 ,
F_75 ( V_43 ) ) ;
if ( V_42 -> V_153 ) {
struct V_154 * V_155 = F_76 ( V_43 ) ;
#if F_24 ( V_54 )
if ( V_43 -> V_120 == V_156 ||
( ! ( ( 1 << V_43 -> V_157 ) &
( V_158 | V_159 ) ) &&
V_42 -> V_160 != V_161 ) ) {
#endif
if ( V_150 )
V_155 -> V_162 -= V_150 -> V_16 . V_17 ;
if ( V_16 )
V_155 -> V_162 += V_16 -> V_16 . V_17 ;
V_155 -> V_163 ( V_43 , V_155 -> V_164 ) ;
#if F_24 ( V_54 )
}
#endif
}
F_44 ( V_42 -> V_152 , V_16 ) ;
if ( V_150 )
F_77 ( V_150 , V_74 ) ;
break;
}
case V_11 :
if ( V_50 )
V_42 -> V_45 |= V_165 ;
else
V_42 -> V_45 &= ~ V_165 ;
break;
case V_131 :
if ( V_50 )
V_42 -> V_45 |= V_166 ;
else
V_42 -> V_45 &= ~ V_166 ;
break;
case V_132 :
if ( V_50 )
V_42 -> V_45 |= V_167 ;
else
V_42 -> V_45 &= ~ V_167 ;
break;
case V_18 :
if ( V_50 )
V_42 -> V_45 |= V_168 ;
else
V_42 -> V_45 &= ~ V_168 ;
break;
case V_23 :
if ( V_50 )
V_42 -> V_45 |= V_169 ;
else
V_42 -> V_45 &= ~ V_169 ;
break;
case V_137 :
if ( V_50 )
V_42 -> V_45 |= V_170 ;
else
V_42 -> V_45 &= ~ V_170 ;
break;
case V_145 :
if ( V_50 )
V_42 -> V_45 |= V_171 ;
else
V_42 -> V_45 &= ~ V_171 ;
break;
case V_14 :
if ( V_43 -> V_80 == V_172 ) {
V_50 &= ~ V_173 ;
V_50 |= V_42 -> V_15 & V_173 ;
}
if ( V_42 -> V_15 != V_50 ) {
V_42 -> V_15 = V_50 ;
V_43 -> V_174 = F_30 ( V_50 ) ;
F_78 ( V_43 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_151;
if ( V_50 != - 1 && ( V_50 < 1 || V_50 > 255 ) )
goto V_151;
V_42 -> V_175 = V_50 ;
break;
case V_133 :
if ( V_43 -> V_80 != V_81 ) {
V_28 = - V_176 ;
break;
}
V_42 -> V_177 = V_50 ? 1 : 0 ;
break;
case V_140 :
if ( V_43 -> V_80 != V_81 ) {
V_28 = - V_176 ;
break;
}
V_42 -> V_178 = V_50 ? 1 : 0 ;
break;
case V_134 :
if ( V_50 < V_179 || V_50 > V_180 )
goto V_151;
V_42 -> V_181 = V_50 ;
break;
case V_126 :
V_42 -> V_106 = ! ! V_50 ;
if ( ! V_50 )
F_79 ( & V_43 -> V_182 ) ;
break;
case V_142 :
if ( V_43 -> V_80 == V_172 )
goto V_151;
if ( V_17 < 1 )
goto V_151;
if ( V_50 == - 1 )
V_50 = 1 ;
if ( V_50 < 0 || V_50 > 255 )
goto V_151;
V_42 -> V_183 = V_50 ;
break;
case V_144 :
if ( V_17 < 1 )
goto V_151;
V_42 -> V_184 = ! ! V_50 ;
break;
case V_141 :
{
struct V_185 * V_111 = NULL ;
int V_113 ;
if ( V_17 != sizeof( int ) )
goto V_151;
V_113 = ( V_186 int ) F_80 ( ( V_186 T_5 ) V_50 ) ;
if ( V_113 == 0 ) {
V_42 -> V_187 = 0 ;
V_28 = 0 ;
break;
}
V_111 = F_81 ( F_74 ( V_43 ) , V_113 ) ;
V_28 = - V_188 ;
if ( ! V_111 )
break;
F_82 ( V_111 ) ;
V_28 = - V_53 ;
if ( V_43 -> V_189 )
break;
V_42 -> V_187 = V_113 ;
V_28 = 0 ;
break;
}
case V_190 :
{
struct V_191 V_192 ;
struct V_185 * V_111 = NULL ;
if ( V_43 -> V_80 == V_172 )
goto V_151;
if ( V_17 < sizeof( struct V_193 ) )
goto V_151;
V_28 = - V_146 ;
if ( V_17 >= sizeof( struct V_191 ) ) {
if ( F_83 ( & V_192 , V_130 , sizeof( V_192 ) ) )
break;
} else {
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
if ( V_17 >= sizeof( struct V_194 ) ) {
if ( F_83 ( & V_192 , V_130 ,
sizeof( struct V_194 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_193 ) ) {
if ( F_83 ( & V_192 . V_195 , V_130 ,
sizeof( struct V_193 ) ) )
break;
}
}
if ( ! V_192 . V_196 ) {
if ( V_192 . V_195 . V_8 == F_84 ( V_197 ) ) {
V_42 -> V_198 = 0 ;
V_42 -> V_199 = 0 ;
V_28 = 0 ;
break;
}
V_111 = F_85 ( F_74 ( V_43 ) , V_192 . V_195 . V_8 ) ;
if ( V_111 )
V_192 . V_196 = V_111 -> V_113 ;
} else
V_111 = F_81 ( F_74 ( V_43 ) , V_192 . V_196 ) ;
V_28 = - V_188 ;
if ( ! V_111 )
break;
F_82 ( V_111 ) ;
V_28 = - V_53 ;
if ( V_43 -> V_189 &&
V_192 . V_196 != V_43 -> V_189 )
break;
V_42 -> V_198 = V_192 . V_196 ;
V_42 -> V_199 = V_192 . V_195 . V_8 ;
V_28 = 0 ;
break;
}
case V_200 :
case V_201 :
{
struct V_191 V_192 ;
V_28 = - V_202 ;
if ( F_20 ( V_43 ) -> V_153 )
break;
if ( V_17 < sizeof( struct V_194 ) )
goto V_151;
V_28 = - V_146 ;
if ( V_17 >= sizeof( struct V_191 ) ) {
if ( F_83 ( & V_192 , V_130 , sizeof( V_192 ) ) )
break;
} else {
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
if ( F_83 ( & V_192 , V_130 , sizeof( struct V_194 ) ) )
break;
}
if ( V_129 == V_200 )
V_28 = F_86 ( V_43 , & V_192 ) ;
else
V_28 = F_87 ( V_43 , & V_192 ) ;
break;
}
case V_203 :
{
struct V_204 * V_205 ;
if ( V_17 < F_88 ( 0 ) )
goto V_151;
if ( V_17 > V_206 ) {
V_28 = - V_88 ;
break;
}
V_205 = F_37 ( V_17 , V_84 ) ;
if ( ! V_205 ) {
V_28 = - V_88 ;
break;
}
V_28 = - V_146 ;
if ( F_83 ( V_205 , V_130 , V_17 ) ) {
F_34 ( V_205 ) ;
break;
}
if ( V_205 -> V_207 >= 0x3ffffffcU ||
V_205 -> V_207 > V_208 ) {
F_34 ( V_205 ) ;
V_28 = - V_88 ;
break;
}
if ( F_88 ( V_205 -> V_207 ) > V_17 ) {
F_34 ( V_205 ) ;
V_28 = - V_53 ;
break;
}
V_28 = F_89 ( V_43 , V_205 , 0 ) ;
F_34 ( V_205 ) ;
break;
}
case V_209 :
case V_210 :
case V_211 :
case V_212 :
{
struct V_213 V_214 ;
int V_215 , V_216 ;
if ( V_17 != sizeof( struct V_213 ) )
goto V_151;
if ( F_83 ( & V_214 , V_130 , sizeof( V_214 ) ) ) {
V_28 = - V_146 ;
break;
}
if ( V_129 == V_209 ) {
V_215 = V_217 ;
V_216 = 1 ;
} else if ( V_129 == V_210 ) {
V_215 = V_217 ;
V_216 = 0 ;
} else if ( V_129 == V_211 ) {
struct V_191 V_192 ;
V_192 . V_218 . V_8 = V_214 . V_218 ;
V_192 . V_195 . V_8 = V_214 . V_219 ;
V_192 . V_196 = 0 ;
V_28 = F_86 ( V_43 , & V_192 ) ;
if ( V_28 && V_28 != - V_87 )
break;
V_215 = V_220 ;
V_216 = 1 ;
} else {
V_215 = V_220 ;
V_216 = 0 ;
}
V_28 = F_90 ( V_216 , V_215 , V_43 , & V_214 , 0 ) ;
break;
}
case V_221 :
case V_222 :
{
struct V_223 V_224 ;
struct V_30 * V_225 ;
struct V_191 V_192 ;
if ( V_17 < sizeof( struct V_223 ) )
goto V_151;
V_28 = - V_146 ;
if ( F_83 ( & V_224 , V_130 , sizeof( V_224 ) ) )
break;
V_225 = (struct V_30 * ) & V_224 . V_226 ;
if ( V_225 -> V_35 != V_36 )
goto V_151;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_192 . V_218 = V_225 -> V_37 ;
V_192 . V_196 = V_224 . V_227 ;
if ( V_129 == V_221 )
V_28 = F_86 ( V_43 , & V_192 ) ;
else
V_28 = F_87 ( V_43 , & V_192 ) ;
break;
}
case V_228 :
case V_229 :
case V_230 :
case V_231 :
{
struct V_232 V_233 ;
struct V_213 V_214 ;
struct V_30 * V_225 ;
int V_215 , V_216 ;
if ( V_17 != sizeof( struct V_232 ) )
goto V_151;
if ( F_83 ( & V_233 , V_130 , sizeof( V_233 ) ) ) {
V_28 = - V_146 ;
break;
}
if ( V_233 . V_234 . V_235 != V_36 ||
V_233 . V_236 . V_235 != V_36 ) {
V_28 = - V_188 ;
break;
}
V_225 = (struct V_30 * ) & V_233 . V_234 ;
V_214 . V_218 = V_225 -> V_37 . V_8 ;
V_225 = (struct V_30 * ) & V_233 . V_236 ;
V_214 . V_237 = V_225 -> V_37 . V_8 ;
V_214 . V_219 = 0 ;
if ( V_129 == V_230 ) {
V_215 = V_217 ;
V_216 = 1 ;
} else if ( V_129 == V_231 ) {
V_215 = V_217 ;
V_216 = 0 ;
} else if ( V_129 == V_228 ) {
struct V_191 V_192 ;
V_225 = (struct V_30 * ) & V_233 . V_234 ;
V_192 . V_218 = V_225 -> V_37 ;
V_192 . V_195 . V_8 = 0 ;
V_192 . V_196 = V_233 . V_238 ;
V_28 = F_86 ( V_43 , & V_192 ) ;
if ( V_28 && V_28 != - V_87 )
break;
V_233 . V_238 = V_192 . V_196 ;
V_215 = V_220 ;
V_216 = 1 ;
} else {
V_215 = V_220 ;
V_216 = 0 ;
}
V_28 = F_90 ( V_216 , V_215 , V_43 , & V_214 ,
V_233 . V_238 ) ;
break;
}
case V_239 :
{
struct V_30 * V_225 ;
struct V_204 * V_205 = NULL ;
struct V_240 * V_241 = NULL ;
int V_242 , V_243 , V_113 ;
if ( V_17 < F_91 ( 0 ) )
goto V_151;
if ( V_17 > V_206 ) {
V_28 = - V_88 ;
break;
}
V_241 = F_37 ( V_17 , V_84 ) ;
if ( ! V_241 ) {
V_28 = - V_88 ;
break;
}
V_28 = - V_146 ;
if ( F_83 ( V_241 , V_130 , V_17 ) )
goto V_244;
if ( V_241 -> V_245 >= 0x1ffffff ||
V_241 -> V_245 > V_208 ) {
V_28 = - V_88 ;
goto V_244;
}
if ( F_91 ( V_241 -> V_245 ) > V_17 ) {
V_28 = - V_53 ;
goto V_244;
}
V_242 = F_88 ( V_241 -> V_245 ) ;
V_205 = F_37 ( V_242 , V_84 ) ;
if ( ! V_205 ) {
V_28 = - V_88 ;
goto V_244;
}
V_113 = V_241 -> V_246 ;
V_225 = (struct V_30 * ) & V_241 -> V_247 ;
if ( V_225 -> V_35 != V_36 ) {
V_28 = - V_188 ;
goto V_244;
}
V_205 -> V_248 = V_225 -> V_37 . V_8 ;
V_205 -> V_249 = 0 ;
V_205 -> V_250 = V_241 -> V_251 ;
V_205 -> V_207 = V_241 -> V_245 ;
V_28 = - V_188 ;
for ( V_243 = 0 ; V_243 < V_241 -> V_245 ; ++ V_243 ) {
V_225 = (struct V_30 * ) & V_241 -> V_252 [ V_243 ] ;
if ( V_225 -> V_35 != V_36 )
goto V_244;
V_205 -> V_253 [ V_243 ] = V_225 -> V_37 . V_8 ;
}
F_34 ( V_241 ) ;
V_241 = NULL ;
V_28 = F_89 ( V_43 , V_205 , V_113 ) ;
V_244:
F_34 ( V_205 ) ;
F_34 ( V_241 ) ;
break;
}
case V_143 :
if ( V_17 < 1 )
goto V_151;
if ( V_50 != 0 && V_50 != 1 )
goto V_151;
V_42 -> V_254 = V_50 ;
break;
case V_135 :
V_28 = F_35 ( V_43 , V_50 ? 1 : 0 , NULL ) ;
break;
case V_136 :
if ( V_17 < 1 )
goto V_151;
V_42 -> V_255 = ! ! V_50 ;
break;
case V_256 :
case V_257 :
V_28 = - V_258 ;
if ( ! F_92 ( F_74 ( V_43 ) -> V_259 , V_260 ) )
break;
V_28 = F_93 ( V_43 , V_129 , V_130 , V_17 ) ;
break;
case V_138 :
if ( ! ! V_50 && ! F_92 ( F_74 ( V_43 ) -> V_259 , V_261 ) &&
! F_92 ( F_74 ( V_43 ) -> V_259 , V_260 ) ) {
V_28 = - V_258 ;
break;
}
if ( V_17 < 1 )
goto V_151;
V_42 -> V_262 = ! ! V_50 ;
break;
case V_139 :
if ( V_17 < 1 )
goto V_151;
if ( V_50 < 0 || V_50 > 255 )
goto V_151;
V_42 -> V_263 = V_50 ;
break;
default:
V_28 = - V_176 ;
break;
}
F_94 ( V_43 ) ;
return V_28 ;
V_151:
F_94 ( V_43 ) ;
return - V_53 ;
}
void F_95 ( const struct V_76 * V_43 , struct V_3 * V_4 )
{
struct V_5 * V_264 = F_2 ( V_4 ) ;
bool V_265 = ( F_20 ( V_43 ) -> V_45 & V_165 ) ||
F_96 ( V_43 ) ;
if ( V_265 && F_97 ( V_4 ) ) {
V_264 -> V_67 = F_98 ( V_4 ) ;
V_264 -> V_68 . V_8 = F_99 ( V_4 ) ;
} else {
V_264 -> V_67 = 0 ;
V_264 -> V_68 . V_8 = 0 ;
}
F_100 ( V_4 ) ;
}
int F_101 ( struct V_76 * V_43 , int V_128 ,
int V_129 , char T_6 * V_130 , unsigned int V_17 )
{
int V_28 ;
if ( V_128 != V_10 )
return - V_176 ;
V_28 = F_68 ( V_43 , V_128 , V_129 , V_130 , V_17 ) ;
#ifdef F_102
if ( V_28 == - V_176 && V_129 != V_133 &&
V_129 != V_256 &&
V_129 != V_257 &&
! F_70 ( V_129 ) ) {
F_72 ( V_43 ) ;
V_28 = F_103 ( V_43 , V_156 , V_129 , V_130 , V_17 ) ;
F_94 ( V_43 ) ;
}
#endif
return V_28 ;
}
int F_104 ( struct V_76 * V_43 , int V_128 , int V_129 ,
char T_6 * V_130 , unsigned int V_17 )
{
int V_28 ;
if ( V_128 != V_10 )
return - V_176 ;
if ( V_129 >= V_221 && V_129 <= V_239 )
return F_105 ( V_43 , V_128 , V_129 , V_130 , V_17 ,
F_101 ) ;
V_28 = F_68 ( V_43 , V_128 , V_129 , V_130 , V_17 ) ;
#ifdef F_102
if ( V_28 == - V_176 && V_129 != V_133 &&
V_129 != V_256 &&
V_129 != V_257 &&
! F_70 ( V_129 ) ) {
F_72 ( V_43 ) ;
V_28 = F_106 ( V_43 , V_156 , V_129 ,
V_130 , V_17 ) ;
F_94 ( V_43 ) ;
}
#endif
return V_28 ;
}
static int F_107 ( struct V_76 * V_43 , int V_128 , int V_129 ,
char T_6 * V_130 , int T_6 * V_17 , unsigned int V_44 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_50 ;
int V_34 ;
if ( V_128 != V_10 )
return - V_266 ;
if ( F_70 ( V_129 ) )
return F_108 ( V_43 , V_129 , V_130 , V_17 ) ;
if ( F_69 ( V_34 , V_17 ) )
return - V_146 ;
if ( V_34 < 0 )
return - V_53 ;
F_72 ( V_43 ) ;
switch ( V_129 ) {
case V_148 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_149 * V_152 ;
V_152 = F_39 ( V_42 -> V_152 ,
F_75 ( V_43 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_152 )
memcpy ( V_19 , & V_152 -> V_16 ,
sizeof( struct V_20 ) +
V_152 -> V_16 . V_17 ) ;
F_94 ( V_43 ) ;
if ( V_16 -> V_17 == 0 )
return F_109 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_34 = F_110 (unsigned int, len, opt->optlen) ;
if ( F_109 ( V_34 , V_17 ) )
return - V_146 ;
if ( F_111 ( V_130 , V_16 -> V_24 , V_34 ) )
return - V_146 ;
return 0 ;
}
case V_11 :
V_50 = ( V_42 -> V_45 & V_165 ) != 0 ;
break;
case V_131 :
V_50 = ( V_42 -> V_45 & V_166 ) != 0 ;
break;
case V_132 :
V_50 = ( V_42 -> V_45 & V_167 ) != 0 ;
break;
case V_18 :
V_50 = ( V_42 -> V_45 & V_168 ) != 0 ;
break;
case V_23 :
V_50 = ( V_42 -> V_45 & V_169 ) != 0 ;
break;
case V_137 :
V_50 = ( V_42 -> V_45 & V_170 ) != 0 ;
break;
case V_145 :
V_50 = ( V_42 -> V_45 & V_171 ) != 0 ;
break;
case V_14 :
V_50 = V_42 -> V_15 ;
break;
case V_13 :
V_50 = ( V_42 -> V_175 == - 1 ?
V_267 :
V_42 -> V_175 ) ;
break;
case V_133 :
V_50 = V_42 -> V_177 ;
break;
case V_140 :
V_50 = V_42 -> V_178 ;
break;
case V_134 :
V_50 = V_42 -> V_181 ;
break;
case V_268 :
{
struct V_269 * V_270 ;
V_50 = 0 ;
V_270 = F_112 ( V_43 ) ;
if ( V_270 ) {
V_50 = F_113 ( V_270 ) ;
F_114 ( V_270 ) ;
}
if ( ! V_50 ) {
F_94 ( V_43 ) ;
return - V_271 ;
}
break;
}
case V_126 :
V_50 = V_42 -> V_106 ;
break;
case V_142 :
V_50 = V_42 -> V_183 ;
break;
case V_144 :
V_50 = V_42 -> V_184 ;
break;
case V_141 :
V_50 = ( V_186 int ) F_84 ( ( V_272 ) V_42 -> V_187 ) ;
break;
case V_190 :
{
struct V_193 V_65 ;
V_34 = F_110 (unsigned int, len, sizeof(struct in_addr)) ;
V_65 . V_8 = V_42 -> V_199 ;
F_94 ( V_43 ) ;
if ( F_109 ( V_34 , V_17 ) )
return - V_146 ;
if ( F_111 ( V_130 , & V_65 , V_34 ) )
return - V_146 ;
return 0 ;
}
case V_203 :
{
struct V_204 V_205 ;
int V_28 ;
if ( V_34 < F_88 ( 0 ) ) {
F_94 ( V_43 ) ;
return - V_53 ;
}
if ( F_83 ( & V_205 , V_130 , F_88 ( 0 ) ) ) {
F_94 ( V_43 ) ;
return - V_146 ;
}
V_28 = F_115 ( V_43 , & V_205 ,
(struct V_204 T_6 * ) V_130 , V_17 ) ;
F_94 ( V_43 ) ;
return V_28 ;
}
case V_239 :
{
struct V_240 V_241 ;
int V_28 ;
if ( V_34 < F_91 ( 0 ) ) {
F_94 ( V_43 ) ;
return - V_53 ;
}
if ( F_83 ( & V_241 , V_130 , F_91 ( 0 ) ) ) {
F_94 ( V_43 ) ;
return - V_146 ;
}
V_28 = F_116 ( V_43 , & V_241 ,
(struct V_240 T_6 * ) V_130 ,
V_17 ) ;
F_94 ( V_43 ) ;
return V_28 ;
}
case V_143 :
V_50 = V_42 -> V_254 ;
break;
case V_273 :
{
struct V_1 V_2 ;
F_94 ( V_43 ) ;
if ( V_43 -> V_80 != V_172 )
return - V_176 ;
V_2 . V_274 = ( V_186 void * ) V_130 ;
V_2 . V_275 = V_34 ;
V_2 . V_21 = V_44 ;
if ( V_42 -> V_45 & V_165 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_42 -> V_276 ;
V_6 . V_68 . V_8 = V_42 -> V_276 ;
V_6 . V_67 = V_42 -> V_198 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_42 -> V_45 & V_166 ) {
int V_277 = V_42 -> V_183 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_277 ) , & V_277 ) ;
}
if ( V_42 -> V_45 & V_167 ) {
int V_15 = V_42 -> V_278 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_34 -= V_2 . V_275 ;
return F_109 ( V_34 , V_17 ) ;
}
case V_136 :
V_50 = V_42 -> V_255 ;
break;
case V_138 :
V_50 = V_42 -> V_262 ;
break;
case V_139 :
V_50 = V_42 -> V_263 ;
break;
default:
F_94 ( V_43 ) ;
return - V_176 ;
}
F_94 ( V_43 ) ;
if ( V_34 < sizeof( int ) && V_34 > 0 && V_50 >= 0 && V_50 <= 255 ) {
unsigned char V_147 = ( unsigned char ) V_50 ;
V_34 = 1 ;
if ( F_109 ( V_34 , V_17 ) )
return - V_146 ;
if ( F_111 ( V_130 , & V_147 , 1 ) )
return - V_146 ;
} else {
V_34 = F_110 (unsigned int, sizeof(int), len) ;
if ( F_109 ( V_34 , V_17 ) )
return - V_146 ;
if ( F_111 ( V_130 , & V_50 , V_34 ) )
return - V_146 ;
}
return 0 ;
}
int F_117 ( struct V_76 * V_43 , int V_128 ,
int V_129 , char T_6 * V_130 , int T_6 * V_17 )
{
int V_28 ;
V_28 = F_107 ( V_43 , V_128 , V_129 , V_130 , V_17 , 0 ) ;
#ifdef F_102
if ( V_28 == - V_176 && V_129 != V_273 &&
! F_70 ( V_129 ) ) {
int V_34 ;
if ( F_69 ( V_34 , V_17 ) )
return - V_146 ;
F_72 ( V_43 ) ;
V_28 = F_118 ( V_43 , V_156 , V_129 , V_130 ,
& V_34 ) ;
F_94 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_109 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
int F_119 ( struct V_76 * V_43 , int V_128 , int V_129 ,
char T_6 * V_130 , int T_6 * V_17 )
{
int V_28 ;
if ( V_129 == V_239 )
return F_120 ( V_43 , V_128 , V_129 , V_130 , V_17 ,
F_117 ) ;
V_28 = F_107 ( V_43 , V_128 , V_129 , V_130 , V_17 ,
V_279 ) ;
#ifdef F_102
if ( V_28 == - V_176 && V_129 != V_273 &&
! F_70 ( V_129 ) ) {
int V_34 ;
if ( F_69 ( V_34 , V_17 ) )
return - V_146 ;
F_72 ( V_43 ) ;
V_28 = F_121 ( V_43 , V_156 , V_129 , V_130 , & V_34 ) ;
F_94 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_109 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
