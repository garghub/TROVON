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
for ( V_52 = F_22 ( V_2 ) ; V_52 ; V_52 = F_23 ( V_2 , V_52 ) ) {
if ( ! F_24 ( V_2 , V_52 ) )
return - V_53 ;
#if F_25 ( V_54 )
if ( V_49 &&
V_52 -> V_55 == V_56 &&
V_52 -> V_57 == V_58 ) {
struct V_59 * V_60 ;
if ( V_52 -> V_61 < F_26 ( sizeof( * V_60 ) ) )
return - V_53 ;
V_60 = (struct V_59 * ) F_27 ( V_52 ) ;
if ( ! F_28 ( & V_60 -> V_62 ) )
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
V_28 = V_52 -> V_61 - F_29 ( sizeof( struct V_51 ) ) ;
V_28 = F_30 ( V_46 , & V_48 -> V_16 , F_27 ( V_52 ) ,
V_28 < 40 ? V_28 : 40 ) ;
if ( V_28 )
return V_28 ;
break;
case V_11 :
{
struct V_5 * V_6 ;
if ( V_52 -> V_61 != F_26 ( sizeof( struct V_5 ) ) )
return - V_53 ;
V_6 = (struct V_5 * ) F_27 ( V_52 ) ;
V_48 -> V_63 = V_6 -> V_67 ;
V_48 -> V_65 = V_6 -> V_68 . V_8 ;
break;
}
case V_13 :
if ( V_52 -> V_61 != F_26 ( sizeof( int ) ) )
return - V_53 ;
V_50 = * ( int * ) F_27 ( V_52 ) ;
if ( V_50 < 1 || V_50 > 255 )
return - V_53 ;
V_48 -> V_12 = V_50 ;
break;
case V_14 :
if ( V_52 -> V_61 != F_26 ( sizeof( int ) ) )
return - V_53 ;
V_50 = * ( int * ) F_27 ( V_52 ) ;
if ( V_50 < 0 || V_50 > 255 )
return - V_53 ;
V_48 -> V_15 = V_50 ;
V_48 -> V_69 = F_31 ( V_48 -> V_15 ) ;
break;
default:
return - V_53 ;
}
}
return 0 ;
}
static void F_32 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = F_33 ( V_71 , struct V_72 , V_74 ) ;
F_34 ( V_73 -> V_75 ) ;
F_35 ( V_73 ) ;
}
int F_36 ( struct V_76 * V_43 , unsigned char V_77 ,
void (* F_37)( struct V_76 * ) )
{
struct V_72 * V_73 , * V_78 ;
struct V_72 T_3 * * V_79 ;
if ( V_43 -> V_80 != V_81 || F_20 ( V_43 ) -> V_82 == V_83 )
return - V_53 ;
V_78 = V_77 ? F_38 ( sizeof( * V_78 ) , V_84 ) : NULL ;
F_39 ( & V_85 ) ;
for ( V_79 = & V_72 ;
( V_73 = F_40 ( * V_79 ,
F_41 ( & V_85 ) ) ) != NULL ;
V_79 = & V_73 -> V_86 ) {
if ( V_73 -> V_43 == V_43 ) {
if ( V_77 ) {
F_42 ( & V_85 ) ;
F_35 ( V_78 ) ;
return - V_87 ;
}
V_73 -> V_43 = NULL ;
F_43 ( * V_79 , V_73 -> V_86 ) ;
F_42 ( & V_85 ) ;
if ( V_73 -> F_37 )
V_73 -> F_37 ( V_43 ) ;
V_73 -> V_75 = V_43 ;
F_44 ( & V_73 -> V_74 , F_32 ) ;
return 0 ;
}
}
if ( V_78 == NULL ) {
F_42 ( & V_85 ) ;
return - V_88 ;
}
V_78 -> V_43 = V_43 ;
V_78 -> F_37 = F_37 ;
F_43 ( V_78 -> V_86 , V_73 ) ;
F_45 ( * V_79 , V_78 ) ;
F_46 ( V_43 ) ;
F_42 ( & V_85 ) ;
return 0 ;
}
void F_47 ( struct V_76 * V_43 , struct V_3 * V_4 , int V_28 ,
T_2 V_89 , T_1 V_6 , T_4 * V_90 )
{
struct V_91 * V_92 ;
V_4 = F_48 ( V_4 , V_93 ) ;
if ( ! V_4 )
return;
V_92 = F_49 ( V_4 ) ;
V_92 -> V_94 . V_95 = V_28 ;
V_92 -> V_94 . V_96 = V_97 ;
V_92 -> V_94 . V_98 = F_50 ( V_4 ) -> type ;
V_92 -> V_94 . V_99 = F_50 ( V_4 ) -> V_100 ;
V_92 -> V_94 . V_101 = 0 ;
V_92 -> V_94 . V_102 = V_6 ;
V_92 -> V_94 . V_103 = 0 ;
V_92 -> V_104 = ( T_4 * ) & ( ( (struct V_31 * ) ( F_50 ( V_4 ) + 1 ) ) -> V_9 ) -
F_51 ( V_4 ) ;
V_92 -> V_89 = V_89 ;
if ( F_52 ( V_4 , V_90 - V_4 -> V_105 ) != NULL ) {
F_53 ( V_4 ) ;
if ( F_54 ( V_43 , V_4 ) == 0 )
return;
}
F_55 ( V_4 ) ;
}
void F_56 ( struct V_76 * V_43 , int V_28 , T_5 V_9 , T_2 V_89 , T_1 V_6 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
struct V_91 * V_92 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
if ( ! V_42 -> V_106 )
return;
V_4 = F_57 ( sizeof( struct V_31 ) , V_93 ) ;
if ( ! V_4 )
return;
F_58 ( V_4 , sizeof( struct V_31 ) ) ;
F_59 ( V_4 ) ;
V_32 = F_3 ( V_4 ) ;
V_32 -> V_9 = V_9 ;
V_92 = F_49 ( V_4 ) ;
V_92 -> V_94 . V_95 = V_28 ;
V_92 -> V_94 . V_96 = V_107 ;
V_92 -> V_94 . V_98 = 0 ;
V_92 -> V_94 . V_99 = 0 ;
V_92 -> V_94 . V_101 = 0 ;
V_92 -> V_94 . V_102 = V_6 ;
V_92 -> V_94 . V_103 = 0 ;
V_92 -> V_104 = ( T_4 * ) & V_32 -> V_9 - F_51 ( V_4 ) ;
V_92 -> V_89 = V_89 ;
F_60 ( V_4 , F_61 ( V_4 ) - V_4 -> V_105 ) ;
F_53 ( V_4 ) ;
if ( F_54 ( V_43 , V_4 ) )
F_55 ( V_4 ) ;
}
int F_62 ( struct V_76 * V_43 , struct V_1 * V_2 , int V_34 , int * V_108 )
{
struct V_91 * V_92 ;
struct V_3 * V_4 ;
F_63 ( struct V_30 * , sin , V_2 -> V_109 ) ;
struct {
struct V_110 V_94 ;
struct V_30 V_111 ;
} V_112 ;
int V_28 ;
int V_113 ;
V_28 = - V_114 ;
V_4 = F_64 ( V_43 ) ;
if ( V_4 == NULL )
goto V_115;
V_113 = V_4 -> V_34 ;
if ( V_113 > V_34 ) {
V_2 -> V_21 |= V_116 ;
V_113 = V_34 ;
}
V_28 = F_65 ( V_4 , 0 , V_2 -> V_117 , V_113 ) ;
if ( V_28 )
goto V_118;
F_66 ( V_2 , V_43 , V_4 ) ;
V_92 = F_49 ( V_4 ) ;
if ( sin ) {
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = * ( T_5 * ) ( F_51 ( V_4 ) +
V_92 -> V_104 ) ;
sin -> V_38 = V_92 -> V_89 ;
memset ( & sin -> V_39 , 0 , sizeof( sin -> V_39 ) ) ;
* V_108 = sizeof( * sin ) ;
}
memcpy ( & V_112 . V_94 , & V_92 -> V_94 , sizeof( struct V_110 ) ) ;
sin = & V_112 . V_111 ;
sin -> V_35 = V_119 ;
if ( V_92 -> V_94 . V_96 == V_97 ) {
struct V_41 * V_42 = F_20 ( V_43 ) ;
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = F_3 ( V_4 ) -> V_120 ;
sin -> V_38 = 0 ;
memset ( & sin -> V_39 , 0 , sizeof( sin -> V_39 ) ) ;
if ( V_42 -> V_45 )
F_19 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_121 , sizeof( V_112 ) , & V_112 ) ;
V_2 -> V_21 |= V_122 ;
V_28 = V_113 ;
V_118:
F_55 ( V_4 ) ;
V_115:
return V_28 ;
}
static int F_67 ( struct V_76 * V_43 , int V_123 ,
int V_124 , char T_6 * V_125 , unsigned int V_17 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_50 = 0 , V_28 ;
switch ( V_124 ) {
case V_11 :
case V_126 :
case V_18 :
case V_127 :
case V_23 :
case V_14 :
case V_13 :
case V_128 :
case V_129 :
case V_121 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
if ( V_17 >= sizeof( int ) ) {
if ( F_68 ( V_50 , ( int T_6 * ) V_125 ) )
return - V_141 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_142 ;
if ( F_68 ( V_142 , ( unsigned char T_6 * ) V_125 ) )
return - V_141 ;
V_50 = ( int ) V_142 ;
}
}
if ( F_69 ( V_124 ) )
return F_70 ( V_43 , V_124 , V_125 , V_17 ) ;
V_28 = 0 ;
F_71 ( V_43 ) ;
switch ( V_124 ) {
case V_143 :
{
struct V_144 * V_145 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_146;
V_28 = F_72 ( F_73 ( V_43 ) , & V_16 ,
V_125 , V_17 ) ;
if ( V_28 )
break;
V_145 = F_40 ( V_42 -> V_147 ,
F_74 ( V_43 ) ) ;
if ( V_42 -> V_148 ) {
struct V_149 * V_150 = F_75 ( V_43 ) ;
#if F_25 ( V_54 )
if ( V_43 -> V_151 == V_152 ||
( ! ( ( 1 << V_43 -> V_153 ) &
( V_154 | V_155 ) ) &&
V_42 -> V_156 != V_157 ) ) {
#endif
if ( V_145 )
V_150 -> V_158 -= V_145 -> V_16 . V_17 ;
if ( V_16 )
V_150 -> V_158 += V_16 -> V_16 . V_17 ;
V_150 -> V_159 ( V_43 , V_150 -> V_160 ) ;
#if F_25 ( V_54 )
}
#endif
}
F_45 ( V_42 -> V_147 , V_16 ) ;
if ( V_145 )
F_76 ( V_145 , V_74 ) ;
break;
}
case V_11 :
if ( V_50 )
V_42 -> V_45 |= V_161 ;
else
V_42 -> V_45 &= ~ V_161 ;
break;
case V_126 :
if ( V_50 )
V_42 -> V_45 |= V_162 ;
else
V_42 -> V_45 &= ~ V_162 ;
break;
case V_127 :
if ( V_50 )
V_42 -> V_45 |= V_163 ;
else
V_42 -> V_45 &= ~ V_163 ;
break;
case V_18 :
if ( V_50 )
V_42 -> V_45 |= V_164 ;
else
V_42 -> V_45 &= ~ V_164 ;
break;
case V_23 :
if ( V_50 )
V_42 -> V_45 |= V_165 ;
else
V_42 -> V_45 &= ~ V_165 ;
break;
case V_132 :
if ( V_50 )
V_42 -> V_45 |= V_166 ;
else
V_42 -> V_45 &= ~ V_166 ;
break;
case V_140 :
if ( V_50 )
V_42 -> V_45 |= V_167 ;
else
V_42 -> V_45 &= ~ V_167 ;
break;
case V_14 :
if ( V_43 -> V_80 == V_168 ) {
V_50 &= ~ V_169 ;
V_50 |= V_42 -> V_15 & V_169 ;
}
if ( V_42 -> V_15 != V_50 ) {
V_42 -> V_15 = V_50 ;
V_43 -> V_170 = F_31 ( V_50 ) ;
F_77 ( V_43 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_146;
if ( V_50 != - 1 && ( V_50 < 1 || V_50 > 255 ) )
goto V_146;
V_42 -> V_171 = V_50 ;
break;
case V_128 :
if ( V_43 -> V_80 != V_81 ) {
V_28 = - V_172 ;
break;
}
V_42 -> V_173 = V_50 ? 1 : 0 ;
break;
case V_135 :
if ( V_43 -> V_80 != V_81 ) {
V_28 = - V_172 ;
break;
}
V_42 -> V_174 = V_50 ? 1 : 0 ;
break;
case V_129 :
if ( V_50 < V_175 || V_50 > V_176 )
goto V_146;
V_42 -> V_177 = V_50 ;
break;
case V_121 :
V_42 -> V_106 = ! ! V_50 ;
if ( ! V_50 )
F_78 ( & V_43 -> V_178 ) ;
break;
case V_137 :
if ( V_43 -> V_80 == V_168 )
goto V_146;
if ( V_17 < 1 )
goto V_146;
if ( V_50 == - 1 )
V_50 = 1 ;
if ( V_50 < 0 || V_50 > 255 )
goto V_146;
V_42 -> V_179 = V_50 ;
break;
case V_139 :
if ( V_17 < 1 )
goto V_146;
V_42 -> V_180 = ! ! V_50 ;
break;
case V_136 :
{
struct V_181 * V_182 = NULL ;
int V_183 ;
if ( V_17 != sizeof( int ) )
goto V_146;
V_183 = ( V_184 int ) F_79 ( ( V_184 T_5 ) V_50 ) ;
if ( V_183 == 0 ) {
V_42 -> V_185 = 0 ;
V_28 = 0 ;
break;
}
V_182 = F_80 ( F_73 ( V_43 ) , V_183 ) ;
V_28 = - V_186 ;
if ( ! V_182 )
break;
F_81 ( V_182 ) ;
V_28 = - V_53 ;
if ( V_43 -> V_187 )
break;
V_42 -> V_185 = V_183 ;
V_28 = 0 ;
break;
}
case V_188 :
{
struct V_189 V_190 ;
struct V_181 * V_182 = NULL ;
if ( V_43 -> V_80 == V_168 )
goto V_146;
if ( V_17 < sizeof( struct V_191 ) )
goto V_146;
V_28 = - V_141 ;
if ( V_17 >= sizeof( struct V_189 ) ) {
if ( F_82 ( & V_190 , V_125 , sizeof( V_190 ) ) )
break;
} else {
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
if ( V_17 >= sizeof( struct V_192 ) ) {
if ( F_82 ( & V_190 , V_125 ,
sizeof( struct V_192 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_191 ) ) {
if ( F_82 ( & V_190 . V_193 , V_125 ,
sizeof( struct V_191 ) ) )
break;
}
}
if ( ! V_190 . V_194 ) {
if ( V_190 . V_193 . V_8 == F_83 ( V_195 ) ) {
V_42 -> V_196 = 0 ;
V_42 -> V_197 = 0 ;
V_28 = 0 ;
break;
}
V_182 = F_84 ( F_73 ( V_43 ) , V_190 . V_193 . V_8 ) ;
if ( V_182 )
V_190 . V_194 = V_182 -> V_183 ;
} else
V_182 = F_80 ( F_73 ( V_43 ) , V_190 . V_194 ) ;
V_28 = - V_186 ;
if ( ! V_182 )
break;
F_81 ( V_182 ) ;
V_28 = - V_53 ;
if ( V_43 -> V_187 &&
V_190 . V_194 != V_43 -> V_187 )
break;
V_42 -> V_196 = V_190 . V_194 ;
V_42 -> V_197 = V_190 . V_193 . V_8 ;
V_28 = 0 ;
break;
}
case V_198 :
case V_199 :
{
struct V_189 V_190 ;
V_28 = - V_200 ;
if ( F_20 ( V_43 ) -> V_148 )
break;
if ( V_17 < sizeof( struct V_192 ) )
goto V_146;
V_28 = - V_141 ;
if ( V_17 >= sizeof( struct V_189 ) ) {
if ( F_82 ( & V_190 , V_125 , sizeof( V_190 ) ) )
break;
} else {
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
if ( F_82 ( & V_190 , V_125 , sizeof( struct V_192 ) ) )
break;
}
if ( V_124 == V_198 )
V_28 = F_85 ( V_43 , & V_190 ) ;
else
V_28 = F_86 ( V_43 , & V_190 ) ;
break;
}
case V_201 :
{
struct V_202 * V_203 ;
if ( V_17 < F_87 ( 0 ) )
goto V_146;
if ( V_17 > V_204 ) {
V_28 = - V_88 ;
break;
}
V_203 = F_38 ( V_17 , V_84 ) ;
if ( ! V_203 ) {
V_28 = - V_88 ;
break;
}
V_28 = - V_141 ;
if ( F_82 ( V_203 , V_125 , V_17 ) ) {
F_35 ( V_203 ) ;
break;
}
if ( V_203 -> V_205 >= 0x3ffffffcU ||
V_203 -> V_205 > V_206 ) {
F_35 ( V_203 ) ;
V_28 = - V_88 ;
break;
}
if ( F_87 ( V_203 -> V_205 ) > V_17 ) {
F_35 ( V_203 ) ;
V_28 = - V_53 ;
break;
}
V_28 = F_88 ( V_43 , V_203 , 0 ) ;
F_35 ( V_203 ) ;
break;
}
case V_207 :
case V_208 :
case V_209 :
case V_210 :
{
struct V_211 V_212 ;
int V_213 , V_214 ;
if ( V_17 != sizeof( struct V_211 ) )
goto V_146;
if ( F_82 ( & V_212 , V_125 , sizeof( V_212 ) ) ) {
V_28 = - V_141 ;
break;
}
if ( V_124 == V_207 ) {
V_213 = V_215 ;
V_214 = 1 ;
} else if ( V_124 == V_208 ) {
V_213 = V_215 ;
V_214 = 0 ;
} else if ( V_124 == V_209 ) {
struct V_189 V_190 ;
V_190 . V_216 . V_8 = V_212 . V_216 ;
V_190 . V_193 . V_8 = V_212 . V_217 ;
V_190 . V_194 = 0 ;
V_28 = F_85 ( V_43 , & V_190 ) ;
if ( V_28 && V_28 != - V_87 )
break;
V_213 = V_218 ;
V_214 = 1 ;
} else {
V_213 = V_218 ;
V_214 = 0 ;
}
V_28 = F_89 ( V_214 , V_213 , V_43 , & V_212 , 0 ) ;
break;
}
case V_219 :
case V_220 :
{
struct V_221 V_222 ;
struct V_30 * V_223 ;
struct V_189 V_190 ;
if ( V_17 < sizeof( struct V_221 ) )
goto V_146;
V_28 = - V_141 ;
if ( F_82 ( & V_222 , V_125 , sizeof( V_222 ) ) )
break;
V_223 = (struct V_30 * ) & V_222 . V_224 ;
if ( V_223 -> V_35 != V_36 )
goto V_146;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_190 . V_216 = V_223 -> V_37 ;
V_190 . V_194 = V_222 . V_225 ;
if ( V_124 == V_219 )
V_28 = F_85 ( V_43 , & V_190 ) ;
else
V_28 = F_86 ( V_43 , & V_190 ) ;
break;
}
case V_226 :
case V_227 :
case V_228 :
case V_229 :
{
struct V_230 V_231 ;
struct V_211 V_212 ;
struct V_30 * V_223 ;
int V_213 , V_214 ;
if ( V_17 != sizeof( struct V_230 ) )
goto V_146;
if ( F_82 ( & V_231 , V_125 , sizeof( V_231 ) ) ) {
V_28 = - V_141 ;
break;
}
if ( V_231 . V_232 . V_233 != V_36 ||
V_231 . V_234 . V_233 != V_36 ) {
V_28 = - V_186 ;
break;
}
V_223 = (struct V_30 * ) & V_231 . V_232 ;
V_212 . V_216 = V_223 -> V_37 . V_8 ;
V_223 = (struct V_30 * ) & V_231 . V_234 ;
V_212 . V_235 = V_223 -> V_37 . V_8 ;
V_212 . V_217 = 0 ;
if ( V_124 == V_228 ) {
V_213 = V_215 ;
V_214 = 1 ;
} else if ( V_124 == V_229 ) {
V_213 = V_215 ;
V_214 = 0 ;
} else if ( V_124 == V_226 ) {
struct V_189 V_190 ;
V_223 = (struct V_30 * ) & V_231 . V_232 ;
V_190 . V_216 = V_223 -> V_37 ;
V_190 . V_193 . V_8 = 0 ;
V_190 . V_194 = V_231 . V_236 ;
V_28 = F_85 ( V_43 , & V_190 ) ;
if ( V_28 && V_28 != - V_87 )
break;
V_231 . V_236 = V_190 . V_194 ;
V_213 = V_218 ;
V_214 = 1 ;
} else {
V_213 = V_218 ;
V_214 = 0 ;
}
V_28 = F_89 ( V_214 , V_213 , V_43 , & V_212 ,
V_231 . V_236 ) ;
break;
}
case V_237 :
{
struct V_30 * V_223 ;
struct V_202 * V_203 = NULL ;
struct V_238 * V_239 = NULL ;
int V_240 , V_241 , V_183 ;
if ( V_17 < F_90 ( 0 ) )
goto V_146;
if ( V_17 > V_204 ) {
V_28 = - V_88 ;
break;
}
V_239 = F_38 ( V_17 , V_84 ) ;
if ( ! V_239 ) {
V_28 = - V_88 ;
break;
}
V_28 = - V_141 ;
if ( F_82 ( V_239 , V_125 , V_17 ) )
goto V_242;
if ( V_239 -> V_243 >= 0x1ffffff ||
V_239 -> V_243 > V_206 ) {
V_28 = - V_88 ;
goto V_242;
}
if ( F_90 ( V_239 -> V_243 ) > V_17 ) {
V_28 = - V_53 ;
goto V_242;
}
V_240 = F_87 ( V_239 -> V_243 ) ;
V_203 = F_38 ( V_240 , V_84 ) ;
if ( ! V_203 ) {
V_28 = - V_88 ;
goto V_242;
}
V_183 = V_239 -> V_244 ;
V_223 = (struct V_30 * ) & V_239 -> V_245 ;
if ( V_223 -> V_35 != V_36 ) {
V_28 = - V_186 ;
goto V_242;
}
V_203 -> V_246 = V_223 -> V_37 . V_8 ;
V_203 -> V_247 = 0 ;
V_203 -> V_248 = V_239 -> V_249 ;
V_203 -> V_205 = V_239 -> V_243 ;
V_28 = - V_186 ;
for ( V_241 = 0 ; V_241 < V_239 -> V_243 ; ++ V_241 ) {
V_223 = (struct V_30 * ) & V_239 -> V_250 [ V_241 ] ;
if ( V_223 -> V_35 != V_36 )
goto V_242;
V_203 -> V_251 [ V_241 ] = V_223 -> V_37 . V_8 ;
}
F_35 ( V_239 ) ;
V_239 = NULL ;
V_28 = F_88 ( V_43 , V_203 , V_183 ) ;
V_242:
F_35 ( V_203 ) ;
F_35 ( V_239 ) ;
break;
}
case V_138 :
if ( V_17 < 1 )
goto V_146;
if ( V_50 != 0 && V_50 != 1 )
goto V_146;
V_42 -> V_252 = V_50 ;
break;
case V_130 :
V_28 = F_36 ( V_43 , V_50 ? 1 : 0 , NULL ) ;
break;
case V_131 :
if ( V_17 < 1 )
goto V_146;
V_42 -> V_253 = ! ! V_50 ;
break;
case V_254 :
case V_255 :
V_28 = - V_256 ;
if ( ! F_91 ( F_73 ( V_43 ) -> V_257 , V_258 ) )
break;
V_28 = F_92 ( V_43 , V_124 , V_125 , V_17 ) ;
break;
case V_133 :
if ( ! ! V_50 && ! F_91 ( F_73 ( V_43 ) -> V_257 , V_259 ) &&
! F_91 ( F_73 ( V_43 ) -> V_257 , V_258 ) ) {
V_28 = - V_256 ;
break;
}
if ( V_17 < 1 )
goto V_146;
V_42 -> V_260 = ! ! V_50 ;
break;
case V_134 :
if ( V_17 < 1 )
goto V_146;
if ( V_50 < 0 || V_50 > 255 )
goto V_146;
V_42 -> V_261 = V_50 ;
break;
default:
V_28 = - V_172 ;
break;
}
F_93 ( V_43 ) ;
return V_28 ;
V_146:
F_93 ( V_43 ) ;
return - V_53 ;
}
void F_94 ( const struct V_76 * V_43 , struct V_3 * V_4 )
{
struct V_5 * V_262 = F_2 ( V_4 ) ;
bool V_263 = ( F_20 ( V_43 ) -> V_45 & V_161 ) ||
F_95 ( V_43 ) ;
if ( V_263 && F_96 ( V_4 ) ) {
V_262 -> V_67 = F_97 ( V_4 ) ;
V_262 -> V_68 . V_8 = F_98 ( V_4 ) ;
} else {
V_262 -> V_67 = 0 ;
V_262 -> V_68 . V_8 = 0 ;
}
F_99 ( V_4 ) ;
}
int F_100 ( struct V_76 * V_43 , int V_123 ,
int V_124 , char T_6 * V_125 , unsigned int V_17 )
{
int V_28 ;
if ( V_123 != V_10 )
return - V_172 ;
V_28 = F_67 ( V_43 , V_123 , V_124 , V_125 , V_17 ) ;
#ifdef F_101
if ( V_28 == - V_172 && V_124 != V_128 &&
V_124 != V_254 &&
V_124 != V_255 &&
! F_69 ( V_124 ) ) {
F_71 ( V_43 ) ;
V_28 = F_102 ( V_43 , V_152 , V_124 , V_125 , V_17 ) ;
F_93 ( V_43 ) ;
}
#endif
return V_28 ;
}
int F_103 ( struct V_76 * V_43 , int V_123 , int V_124 ,
char T_6 * V_125 , unsigned int V_17 )
{
int V_28 ;
if ( V_123 != V_10 )
return - V_172 ;
if ( V_124 >= V_219 && V_124 <= V_237 )
return F_104 ( V_43 , V_123 , V_124 , V_125 , V_17 ,
F_100 ) ;
V_28 = F_67 ( V_43 , V_123 , V_124 , V_125 , V_17 ) ;
#ifdef F_101
if ( V_28 == - V_172 && V_124 != V_128 &&
V_124 != V_254 &&
V_124 != V_255 &&
! F_69 ( V_124 ) ) {
F_71 ( V_43 ) ;
V_28 = F_105 ( V_43 , V_152 , V_124 ,
V_125 , V_17 ) ;
F_93 ( V_43 ) ;
}
#endif
return V_28 ;
}
static int F_106 ( struct V_76 * V_43 , int V_123 , int V_124 ,
char T_6 * V_125 , int T_6 * V_17 , unsigned int V_44 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_50 ;
int V_34 ;
if ( V_123 != V_10 )
return - V_264 ;
if ( F_69 ( V_124 ) )
return F_107 ( V_43 , V_124 , V_125 , V_17 ) ;
if ( F_68 ( V_34 , V_17 ) )
return - V_141 ;
if ( V_34 < 0 )
return - V_53 ;
F_71 ( V_43 ) ;
switch ( V_124 ) {
case V_143 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_144 * V_147 ;
V_147 = F_40 ( V_42 -> V_147 ,
F_74 ( V_43 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_147 )
memcpy ( V_19 , & V_147 -> V_16 ,
sizeof( struct V_20 ) +
V_147 -> V_16 . V_17 ) ;
F_93 ( V_43 ) ;
if ( V_16 -> V_17 == 0 )
return F_108 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_34 = F_109 (unsigned int, len, opt->optlen) ;
if ( F_108 ( V_34 , V_17 ) )
return - V_141 ;
if ( F_110 ( V_125 , V_16 -> V_24 , V_34 ) )
return - V_141 ;
return 0 ;
}
case V_11 :
V_50 = ( V_42 -> V_45 & V_161 ) != 0 ;
break;
case V_126 :
V_50 = ( V_42 -> V_45 & V_162 ) != 0 ;
break;
case V_127 :
V_50 = ( V_42 -> V_45 & V_163 ) != 0 ;
break;
case V_18 :
V_50 = ( V_42 -> V_45 & V_164 ) != 0 ;
break;
case V_23 :
V_50 = ( V_42 -> V_45 & V_165 ) != 0 ;
break;
case V_132 :
V_50 = ( V_42 -> V_45 & V_166 ) != 0 ;
break;
case V_140 :
V_50 = ( V_42 -> V_45 & V_167 ) != 0 ;
break;
case V_14 :
V_50 = V_42 -> V_15 ;
break;
case V_13 :
V_50 = ( V_42 -> V_171 == - 1 ?
V_265 :
V_42 -> V_171 ) ;
break;
case V_128 :
V_50 = V_42 -> V_173 ;
break;
case V_135 :
V_50 = V_42 -> V_174 ;
break;
case V_129 :
V_50 = V_42 -> V_177 ;
break;
case V_266 :
{
struct V_267 * V_268 ;
V_50 = 0 ;
V_268 = F_111 ( V_43 ) ;
if ( V_268 ) {
V_50 = F_112 ( V_268 ) ;
F_113 ( V_268 ) ;
}
if ( ! V_50 ) {
F_93 ( V_43 ) ;
return - V_269 ;
}
break;
}
case V_121 :
V_50 = V_42 -> V_106 ;
break;
case V_137 :
V_50 = V_42 -> V_179 ;
break;
case V_139 :
V_50 = V_42 -> V_180 ;
break;
case V_136 :
V_50 = ( V_184 int ) F_83 ( ( V_270 ) V_42 -> V_185 ) ;
break;
case V_188 :
{
struct V_191 V_65 ;
V_34 = F_109 (unsigned int, len, sizeof(struct in_addr)) ;
V_65 . V_8 = V_42 -> V_197 ;
F_93 ( V_43 ) ;
if ( F_108 ( V_34 , V_17 ) )
return - V_141 ;
if ( F_110 ( V_125 , & V_65 , V_34 ) )
return - V_141 ;
return 0 ;
}
case V_201 :
{
struct V_202 V_203 ;
int V_28 ;
if ( V_34 < F_87 ( 0 ) ) {
F_93 ( V_43 ) ;
return - V_53 ;
}
if ( F_82 ( & V_203 , V_125 , F_87 ( 0 ) ) ) {
F_93 ( V_43 ) ;
return - V_141 ;
}
V_28 = F_114 ( V_43 , & V_203 ,
(struct V_202 T_6 * ) V_125 , V_17 ) ;
F_93 ( V_43 ) ;
return V_28 ;
}
case V_237 :
{
struct V_238 V_239 ;
int V_28 ;
if ( V_34 < F_90 ( 0 ) ) {
F_93 ( V_43 ) ;
return - V_53 ;
}
if ( F_82 ( & V_239 , V_125 , F_90 ( 0 ) ) ) {
F_93 ( V_43 ) ;
return - V_141 ;
}
V_28 = F_115 ( V_43 , & V_239 ,
(struct V_238 T_6 * ) V_125 ,
V_17 ) ;
F_93 ( V_43 ) ;
return V_28 ;
}
case V_138 :
V_50 = V_42 -> V_252 ;
break;
case V_271 :
{
struct V_1 V_2 ;
F_93 ( V_43 ) ;
if ( V_43 -> V_80 != V_168 )
return - V_172 ;
V_2 . V_272 = ( V_184 void * ) V_125 ;
V_2 . V_273 = V_34 ;
V_2 . V_21 = V_44 ;
if ( V_42 -> V_45 & V_161 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_42 -> V_274 ;
V_6 . V_68 . V_8 = V_42 -> V_274 ;
V_6 . V_67 = V_42 -> V_196 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_42 -> V_45 & V_162 ) {
int V_275 = V_42 -> V_179 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_275 ) , & V_275 ) ;
}
if ( V_42 -> V_45 & V_163 ) {
int V_15 = V_42 -> V_276 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_34 -= V_2 . V_273 ;
return F_108 ( V_34 , V_17 ) ;
}
case V_131 :
V_50 = V_42 -> V_253 ;
break;
case V_133 :
V_50 = V_42 -> V_260 ;
break;
case V_134 :
V_50 = V_42 -> V_261 ;
break;
default:
F_93 ( V_43 ) ;
return - V_172 ;
}
F_93 ( V_43 ) ;
if ( V_34 < sizeof( int ) && V_34 > 0 && V_50 >= 0 && V_50 <= 255 ) {
unsigned char V_142 = ( unsigned char ) V_50 ;
V_34 = 1 ;
if ( F_108 ( V_34 , V_17 ) )
return - V_141 ;
if ( F_110 ( V_125 , & V_142 , 1 ) )
return - V_141 ;
} else {
V_34 = F_109 (unsigned int, sizeof(int), len) ;
if ( F_108 ( V_34 , V_17 ) )
return - V_141 ;
if ( F_110 ( V_125 , & V_50 , V_34 ) )
return - V_141 ;
}
return 0 ;
}
int F_116 ( struct V_76 * V_43 , int V_123 ,
int V_124 , char T_6 * V_125 , int T_6 * V_17 )
{
int V_28 ;
V_28 = F_106 ( V_43 , V_123 , V_124 , V_125 , V_17 , 0 ) ;
#ifdef F_101
if ( V_28 == - V_172 && V_124 != V_271 &&
! F_69 ( V_124 ) ) {
int V_34 ;
if ( F_68 ( V_34 , V_17 ) )
return - V_141 ;
F_71 ( V_43 ) ;
V_28 = F_117 ( V_43 , V_152 , V_124 , V_125 ,
& V_34 ) ;
F_93 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_108 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
int F_118 ( struct V_76 * V_43 , int V_123 , int V_124 ,
char T_6 * V_125 , int T_6 * V_17 )
{
int V_28 ;
if ( V_124 == V_237 )
return F_119 ( V_43 , V_123 , V_124 , V_125 , V_17 ,
F_116 ) ;
V_28 = F_106 ( V_43 , V_123 , V_124 , V_125 , V_17 ,
V_277 ) ;
#ifdef F_101
if ( V_28 == - V_172 && V_124 != V_271 &&
! F_69 ( V_124 ) ) {
int V_34 ;
if ( F_68 ( V_34 , V_17 ) )
return - V_141 ;
F_71 ( V_43 ) ;
V_28 = F_120 ( V_43 , V_152 , V_124 , V_125 , & V_34 ) ;
F_93 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_108 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
