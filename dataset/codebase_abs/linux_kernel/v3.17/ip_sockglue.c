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
V_78 -> V_86 = V_73 ;
F_43 ( * V_79 , V_78 ) ;
F_45 ( V_43 ) ;
F_42 ( & V_85 ) ;
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
int F_61 ( struct V_76 * V_43 , struct V_1 * V_2 , int V_34 , int * V_108 )
{
struct V_91 * V_92 ;
struct V_3 * V_4 , * V_109 ;
F_62 ( struct V_30 * , sin , V_2 -> V_110 ) ;
struct {
struct V_111 V_94 ;
struct V_30 V_112 ;
} V_113 ;
int V_28 ;
int V_114 ;
V_28 = - V_115 ;
V_4 = F_63 ( & V_43 -> V_116 ) ;
if ( V_4 == NULL )
goto V_117;
V_114 = V_4 -> V_34 ;
if ( V_114 > V_34 ) {
V_2 -> V_21 |= V_118 ;
V_114 = V_34 ;
}
V_28 = F_64 ( V_4 , 0 , V_2 -> V_119 , V_114 ) ;
if ( V_28 )
goto V_120;
F_65 ( V_2 , V_43 , V_4 ) ;
V_92 = F_48 ( V_4 ) ;
if ( sin ) {
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = * ( T_5 * ) ( F_50 ( V_4 ) +
V_92 -> V_104 ) ;
sin -> V_38 = V_92 -> V_89 ;
memset ( & sin -> V_39 , 0 , sizeof( sin -> V_39 ) ) ;
* V_108 = sizeof( * sin ) ;
}
memcpy ( & V_113 . V_94 , & V_92 -> V_94 , sizeof( struct V_111 ) ) ;
sin = & V_113 . V_112 ;
sin -> V_35 = V_121 ;
if ( V_92 -> V_94 . V_96 == V_97 ) {
struct V_41 * V_42 = F_20 ( V_43 ) ;
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = F_3 ( V_4 ) -> V_122 ;
sin -> V_38 = 0 ;
memset ( & sin -> V_39 , 0 , sizeof( sin -> V_39 ) ) ;
if ( V_42 -> V_45 )
F_19 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_123 , sizeof( V_113 ) , & V_113 ) ;
V_2 -> V_21 |= V_124 ;
V_28 = V_114 ;
F_39 ( & V_43 -> V_116 . V_125 ) ;
V_43 -> V_126 = 0 ;
V_109 = F_66 ( & V_43 -> V_116 ) ;
if ( V_109 != NULL ) {
V_43 -> V_126 = F_48 ( V_109 ) -> V_94 . V_95 ;
F_42 ( & V_43 -> V_116 . V_125 ) ;
V_43 -> V_127 ( V_43 ) ;
} else
F_42 ( & V_43 -> V_116 . V_125 ) ;
V_120:
F_54 ( V_4 ) ;
V_117:
return V_28 ;
}
static int F_67 ( struct V_76 * V_43 , int V_128 ,
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
case V_123 :
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
if ( F_68 ( V_50 , ( int T_6 * ) V_130 ) )
return - V_146 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_147 ;
if ( F_68 ( V_147 , ( unsigned char T_6 * ) V_130 ) )
return - V_146 ;
V_50 = ( int ) V_147 ;
}
}
if ( F_69 ( V_129 ) )
return F_70 ( V_43 , V_129 , V_130 , V_17 ) ;
V_28 = 0 ;
F_71 ( V_43 ) ;
switch ( V_129 ) {
case V_148 :
{
struct V_149 * V_150 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_151;
V_28 = F_72 ( F_73 ( V_43 ) , & V_16 ,
V_130 , V_17 ) ;
if ( V_28 )
break;
V_150 = F_40 ( V_42 -> V_152 ,
F_74 ( V_43 ) ) ;
if ( V_42 -> V_153 ) {
struct V_154 * V_155 = F_75 ( V_43 ) ;
#if F_76 ( V_54 )
if ( V_43 -> V_156 == V_157 ||
( ! ( ( 1 << V_43 -> V_158 ) &
( V_159 | V_160 ) ) &&
V_42 -> V_161 != V_162 ) ) {
#endif
if ( V_150 )
V_155 -> V_163 -= V_150 -> V_16 . V_17 ;
if ( V_16 )
V_155 -> V_163 += V_16 -> V_16 . V_17 ;
V_155 -> V_164 ( V_43 , V_155 -> V_165 ) ;
#if F_76 ( V_54 )
}
#endif
}
F_43 ( V_42 -> V_152 , V_16 ) ;
if ( V_150 )
F_77 ( V_150 , V_74 ) ;
break;
}
case V_11 :
if ( V_50 )
V_42 -> V_45 |= V_166 ;
else
V_42 -> V_45 &= ~ V_166 ;
break;
case V_131 :
if ( V_50 )
V_42 -> V_45 |= V_167 ;
else
V_42 -> V_45 &= ~ V_167 ;
break;
case V_132 :
if ( V_50 )
V_42 -> V_45 |= V_168 ;
else
V_42 -> V_45 &= ~ V_168 ;
break;
case V_18 :
if ( V_50 )
V_42 -> V_45 |= V_169 ;
else
V_42 -> V_45 &= ~ V_169 ;
break;
case V_23 :
if ( V_50 )
V_42 -> V_45 |= V_170 ;
else
V_42 -> V_45 &= ~ V_170 ;
break;
case V_137 :
if ( V_50 )
V_42 -> V_45 |= V_171 ;
else
V_42 -> V_45 &= ~ V_171 ;
break;
case V_145 :
if ( V_50 )
V_42 -> V_45 |= V_172 ;
else
V_42 -> V_45 &= ~ V_172 ;
break;
case V_14 :
if ( V_43 -> V_80 == V_173 ) {
V_50 &= ~ V_174 ;
V_50 |= V_42 -> V_15 & V_174 ;
}
if ( V_42 -> V_15 != V_50 ) {
V_42 -> V_15 = V_50 ;
V_43 -> V_175 = F_31 ( V_50 ) ;
F_78 ( V_43 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_151;
if ( V_50 != - 1 && ( V_50 < 1 || V_50 > 255 ) )
goto V_151;
V_42 -> V_176 = V_50 ;
break;
case V_133 :
if ( V_43 -> V_80 != V_81 ) {
V_28 = - V_177 ;
break;
}
V_42 -> V_178 = V_50 ? 1 : 0 ;
break;
case V_140 :
if ( V_43 -> V_80 != V_81 ) {
V_28 = - V_177 ;
break;
}
V_42 -> V_179 = V_50 ? 1 : 0 ;
break;
case V_134 :
if ( V_50 < V_180 || V_50 > V_181 )
goto V_151;
V_42 -> V_182 = V_50 ;
break;
case V_123 :
V_42 -> V_106 = ! ! V_50 ;
if ( ! V_50 )
F_79 ( & V_43 -> V_116 ) ;
break;
case V_142 :
if ( V_43 -> V_80 == V_173 )
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
struct V_185 * V_186 = NULL ;
int V_187 ;
if ( V_17 != sizeof( int ) )
goto V_151;
V_187 = ( V_188 int ) F_80 ( ( V_188 T_5 ) V_50 ) ;
if ( V_187 == 0 ) {
V_42 -> V_189 = 0 ;
V_28 = 0 ;
break;
}
V_186 = F_81 ( F_73 ( V_43 ) , V_187 ) ;
V_28 = - V_190 ;
if ( ! V_186 )
break;
F_82 ( V_186 ) ;
V_28 = - V_53 ;
if ( V_43 -> V_191 )
break;
V_42 -> V_189 = V_187 ;
V_28 = 0 ;
break;
}
case V_192 :
{
struct V_193 V_194 ;
struct V_185 * V_186 = NULL ;
if ( V_43 -> V_80 == V_173 )
goto V_151;
if ( V_17 < sizeof( struct V_195 ) )
goto V_151;
V_28 = - V_146 ;
if ( V_17 >= sizeof( struct V_193 ) ) {
if ( F_83 ( & V_194 , V_130 , sizeof( V_194 ) ) )
break;
} else {
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
if ( V_17 >= sizeof( struct V_196 ) ) {
if ( F_83 ( & V_194 , V_130 ,
sizeof( struct V_196 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_195 ) ) {
if ( F_83 ( & V_194 . V_197 , V_130 ,
sizeof( struct V_195 ) ) )
break;
}
}
if ( ! V_194 . V_198 ) {
if ( V_194 . V_197 . V_8 == F_84 ( V_199 ) ) {
V_42 -> V_200 = 0 ;
V_42 -> V_201 = 0 ;
V_28 = 0 ;
break;
}
V_186 = F_85 ( F_73 ( V_43 ) , V_194 . V_197 . V_8 ) ;
if ( V_186 )
V_194 . V_198 = V_186 -> V_187 ;
} else
V_186 = F_81 ( F_73 ( V_43 ) , V_194 . V_198 ) ;
V_28 = - V_190 ;
if ( ! V_186 )
break;
F_82 ( V_186 ) ;
V_28 = - V_53 ;
if ( V_43 -> V_191 &&
V_194 . V_198 != V_43 -> V_191 )
break;
V_42 -> V_200 = V_194 . V_198 ;
V_42 -> V_201 = V_194 . V_197 . V_8 ;
V_28 = 0 ;
break;
}
case V_202 :
case V_203 :
{
struct V_193 V_194 ;
V_28 = - V_204 ;
if ( F_20 ( V_43 ) -> V_153 )
break;
if ( V_17 < sizeof( struct V_196 ) )
goto V_151;
V_28 = - V_146 ;
if ( V_17 >= sizeof( struct V_193 ) ) {
if ( F_83 ( & V_194 , V_130 , sizeof( V_194 ) ) )
break;
} else {
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
if ( F_83 ( & V_194 , V_130 , sizeof( struct V_196 ) ) )
break;
}
if ( V_129 == V_202 )
V_28 = F_86 ( V_43 , & V_194 ) ;
else
V_28 = F_87 ( V_43 , & V_194 ) ;
break;
}
case V_205 :
{
struct V_206 * V_207 ;
if ( V_17 < F_88 ( 0 ) )
goto V_151;
if ( V_17 > V_208 ) {
V_28 = - V_88 ;
break;
}
V_207 = F_38 ( V_17 , V_84 ) ;
if ( ! V_207 ) {
V_28 = - V_88 ;
break;
}
V_28 = - V_146 ;
if ( F_83 ( V_207 , V_130 , V_17 ) ) {
F_35 ( V_207 ) ;
break;
}
if ( V_207 -> V_209 >= 0x3ffffffcU ||
V_207 -> V_209 > V_210 ) {
F_35 ( V_207 ) ;
V_28 = - V_88 ;
break;
}
if ( F_88 ( V_207 -> V_209 ) > V_17 ) {
F_35 ( V_207 ) ;
V_28 = - V_53 ;
break;
}
V_28 = F_89 ( V_43 , V_207 , 0 ) ;
F_35 ( V_207 ) ;
break;
}
case V_211 :
case V_212 :
case V_213 :
case V_214 :
{
struct V_215 V_216 ;
int V_217 , V_218 ;
if ( V_17 != sizeof( struct V_215 ) )
goto V_151;
if ( F_83 ( & V_216 , V_130 , sizeof( V_216 ) ) ) {
V_28 = - V_146 ;
break;
}
if ( V_129 == V_211 ) {
V_217 = V_219 ;
V_218 = 1 ;
} else if ( V_129 == V_212 ) {
V_217 = V_219 ;
V_218 = 0 ;
} else if ( V_129 == V_213 ) {
struct V_193 V_194 ;
V_194 . V_220 . V_8 = V_216 . V_220 ;
V_194 . V_197 . V_8 = V_216 . V_221 ;
V_194 . V_198 = 0 ;
V_28 = F_86 ( V_43 , & V_194 ) ;
if ( V_28 && V_28 != - V_87 )
break;
V_217 = V_222 ;
V_218 = 1 ;
} else {
V_217 = V_222 ;
V_218 = 0 ;
}
V_28 = F_90 ( V_218 , V_217 , V_43 , & V_216 , 0 ) ;
break;
}
case V_223 :
case V_224 :
{
struct V_225 V_226 ;
struct V_30 * V_227 ;
struct V_193 V_194 ;
if ( V_17 < sizeof( struct V_225 ) )
goto V_151;
V_28 = - V_146 ;
if ( F_83 ( & V_226 , V_130 , sizeof( V_226 ) ) )
break;
V_227 = (struct V_30 * ) & V_226 . V_228 ;
if ( V_227 -> V_35 != V_36 )
goto V_151;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
V_194 . V_220 = V_227 -> V_37 ;
V_194 . V_198 = V_226 . V_229 ;
if ( V_129 == V_223 )
V_28 = F_86 ( V_43 , & V_194 ) ;
else
V_28 = F_87 ( V_43 , & V_194 ) ;
break;
}
case V_230 :
case V_231 :
case V_232 :
case V_233 :
{
struct V_234 V_235 ;
struct V_215 V_216 ;
struct V_30 * V_227 ;
int V_217 , V_218 ;
if ( V_17 != sizeof( struct V_234 ) )
goto V_151;
if ( F_83 ( & V_235 , V_130 , sizeof( V_235 ) ) ) {
V_28 = - V_146 ;
break;
}
if ( V_235 . V_236 . V_237 != V_36 ||
V_235 . V_238 . V_237 != V_36 ) {
V_28 = - V_190 ;
break;
}
V_227 = (struct V_30 * ) & V_235 . V_236 ;
V_216 . V_220 = V_227 -> V_37 . V_8 ;
V_227 = (struct V_30 * ) & V_235 . V_238 ;
V_216 . V_239 = V_227 -> V_37 . V_8 ;
V_216 . V_221 = 0 ;
if ( V_129 == V_232 ) {
V_217 = V_219 ;
V_218 = 1 ;
} else if ( V_129 == V_233 ) {
V_217 = V_219 ;
V_218 = 0 ;
} else if ( V_129 == V_230 ) {
struct V_193 V_194 ;
V_227 = (struct V_30 * ) & V_235 . V_236 ;
V_194 . V_220 = V_227 -> V_37 ;
V_194 . V_197 . V_8 = 0 ;
V_194 . V_198 = V_235 . V_240 ;
V_28 = F_86 ( V_43 , & V_194 ) ;
if ( V_28 && V_28 != - V_87 )
break;
V_235 . V_240 = V_194 . V_198 ;
V_217 = V_222 ;
V_218 = 1 ;
} else {
V_217 = V_222 ;
V_218 = 0 ;
}
V_28 = F_90 ( V_218 , V_217 , V_43 , & V_216 ,
V_235 . V_240 ) ;
break;
}
case V_241 :
{
struct V_30 * V_227 ;
struct V_206 * V_207 = NULL ;
struct V_242 * V_243 = NULL ;
int V_244 , V_245 , V_187 ;
if ( V_17 < F_91 ( 0 ) )
goto V_151;
if ( V_17 > V_208 ) {
V_28 = - V_88 ;
break;
}
V_243 = F_38 ( V_17 , V_84 ) ;
if ( ! V_243 ) {
V_28 = - V_88 ;
break;
}
V_28 = - V_146 ;
if ( F_83 ( V_243 , V_130 , V_17 ) )
goto V_246;
if ( V_243 -> V_247 >= 0x1ffffff ||
V_243 -> V_247 > V_210 ) {
V_28 = - V_88 ;
goto V_246;
}
if ( F_91 ( V_243 -> V_247 ) > V_17 ) {
V_28 = - V_53 ;
goto V_246;
}
V_244 = F_88 ( V_243 -> V_247 ) ;
V_207 = F_38 ( V_244 , V_84 ) ;
if ( ! V_207 ) {
V_28 = - V_88 ;
goto V_246;
}
V_187 = V_243 -> V_248 ;
V_227 = (struct V_30 * ) & V_243 -> V_249 ;
if ( V_227 -> V_35 != V_36 ) {
V_28 = - V_190 ;
goto V_246;
}
V_207 -> V_250 = V_227 -> V_37 . V_8 ;
V_207 -> V_251 = 0 ;
V_207 -> V_252 = V_243 -> V_253 ;
V_207 -> V_209 = V_243 -> V_247 ;
V_28 = - V_190 ;
for ( V_245 = 0 ; V_245 < V_243 -> V_247 ; ++ V_245 ) {
V_227 = (struct V_30 * ) & V_243 -> V_254 [ V_245 ] ;
if ( V_227 -> V_35 != V_36 )
goto V_246;
V_207 -> V_255 [ V_245 ] = V_227 -> V_37 . V_8 ;
}
F_35 ( V_243 ) ;
V_243 = NULL ;
V_28 = F_89 ( V_43 , V_207 , V_187 ) ;
V_246:
F_35 ( V_207 ) ;
F_35 ( V_243 ) ;
break;
}
case V_143 :
if ( V_17 < 1 )
goto V_151;
if ( V_50 != 0 && V_50 != 1 )
goto V_151;
V_42 -> V_256 = V_50 ;
break;
case V_135 :
V_28 = F_36 ( V_43 , V_50 ? 1 : 0 , NULL ) ;
break;
case V_136 :
if ( V_17 < 1 )
goto V_151;
V_42 -> V_257 = ! ! V_50 ;
break;
case V_258 :
case V_259 :
V_28 = - V_260 ;
if ( ! F_92 ( F_73 ( V_43 ) -> V_261 , V_262 ) )
break;
V_28 = F_93 ( V_43 , V_129 , V_130 , V_17 ) ;
break;
case V_138 :
if ( ! ! V_50 && ! F_92 ( F_73 ( V_43 ) -> V_261 , V_263 ) &&
! F_92 ( F_73 ( V_43 ) -> V_261 , V_262 ) ) {
V_28 = - V_260 ;
break;
}
if ( V_17 < 1 )
goto V_151;
V_42 -> V_264 = ! ! V_50 ;
break;
case V_139 :
if ( V_17 < 1 )
goto V_151;
if ( V_50 < 0 || V_50 > 255 )
goto V_151;
V_42 -> V_265 = V_50 ;
break;
default:
V_28 = - V_177 ;
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
struct V_5 * V_266 = F_2 ( V_4 ) ;
bool V_267 = ( F_20 ( V_43 ) -> V_45 & V_166 ) ||
F_96 ( V_43 ) ;
if ( V_267 && F_97 ( V_4 ) ) {
V_266 -> V_67 = F_98 ( V_4 ) ;
V_266 -> V_68 . V_8 = F_99 ( V_4 ) ;
} else {
V_266 -> V_67 = 0 ;
V_266 -> V_68 . V_8 = 0 ;
}
F_100 ( V_4 ) ;
}
int F_101 ( struct V_76 * V_43 , int V_128 ,
int V_129 , char T_6 * V_130 , unsigned int V_17 )
{
int V_28 ;
if ( V_128 != V_10 )
return - V_177 ;
V_28 = F_67 ( V_43 , V_128 , V_129 , V_130 , V_17 ) ;
#ifdef F_102
if ( V_28 == - V_177 && V_129 != V_133 &&
V_129 != V_258 &&
V_129 != V_259 &&
! F_69 ( V_129 ) ) {
F_71 ( V_43 ) ;
V_28 = F_103 ( V_43 , V_157 , V_129 , V_130 , V_17 ) ;
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
return - V_177 ;
if ( V_129 >= V_223 && V_129 <= V_241 )
return F_105 ( V_43 , V_128 , V_129 , V_130 , V_17 ,
F_101 ) ;
V_28 = F_67 ( V_43 , V_128 , V_129 , V_130 , V_17 ) ;
#ifdef F_102
if ( V_28 == - V_177 && V_129 != V_133 &&
V_129 != V_258 &&
V_129 != V_259 &&
! F_69 ( V_129 ) ) {
F_71 ( V_43 ) ;
V_28 = F_106 ( V_43 , V_157 , V_129 ,
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
return - V_268 ;
if ( F_69 ( V_129 ) )
return F_108 ( V_43 , V_129 , V_130 , V_17 ) ;
if ( F_68 ( V_34 , V_17 ) )
return - V_146 ;
if ( V_34 < 0 )
return - V_53 ;
F_71 ( V_43 ) ;
switch ( V_129 ) {
case V_148 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_149 * V_152 ;
V_152 = F_40 ( V_42 -> V_152 ,
F_74 ( V_43 ) ) ;
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
V_50 = ( V_42 -> V_45 & V_166 ) != 0 ;
break;
case V_131 :
V_50 = ( V_42 -> V_45 & V_167 ) != 0 ;
break;
case V_132 :
V_50 = ( V_42 -> V_45 & V_168 ) != 0 ;
break;
case V_18 :
V_50 = ( V_42 -> V_45 & V_169 ) != 0 ;
break;
case V_23 :
V_50 = ( V_42 -> V_45 & V_170 ) != 0 ;
break;
case V_137 :
V_50 = ( V_42 -> V_45 & V_171 ) != 0 ;
break;
case V_145 :
V_50 = ( V_42 -> V_45 & V_172 ) != 0 ;
break;
case V_14 :
V_50 = V_42 -> V_15 ;
break;
case V_13 :
V_50 = ( V_42 -> V_176 == - 1 ?
V_269 :
V_42 -> V_176 ) ;
break;
case V_133 :
V_50 = V_42 -> V_178 ;
break;
case V_140 :
V_50 = V_42 -> V_179 ;
break;
case V_134 :
V_50 = V_42 -> V_182 ;
break;
case V_270 :
{
struct V_271 * V_272 ;
V_50 = 0 ;
V_272 = F_112 ( V_43 ) ;
if ( V_272 ) {
V_50 = F_113 ( V_272 ) ;
F_114 ( V_272 ) ;
}
if ( ! V_50 ) {
F_94 ( V_43 ) ;
return - V_273 ;
}
break;
}
case V_123 :
V_50 = V_42 -> V_106 ;
break;
case V_142 :
V_50 = V_42 -> V_183 ;
break;
case V_144 :
V_50 = V_42 -> V_184 ;
break;
case V_141 :
V_50 = ( V_188 int ) F_84 ( ( V_274 ) V_42 -> V_189 ) ;
break;
case V_192 :
{
struct V_195 V_65 ;
V_34 = F_110 (unsigned int, len, sizeof(struct in_addr)) ;
V_65 . V_8 = V_42 -> V_201 ;
F_94 ( V_43 ) ;
if ( F_109 ( V_34 , V_17 ) )
return - V_146 ;
if ( F_111 ( V_130 , & V_65 , V_34 ) )
return - V_146 ;
return 0 ;
}
case V_205 :
{
struct V_206 V_207 ;
int V_28 ;
if ( V_34 < F_88 ( 0 ) ) {
F_94 ( V_43 ) ;
return - V_53 ;
}
if ( F_83 ( & V_207 , V_130 , F_88 ( 0 ) ) ) {
F_94 ( V_43 ) ;
return - V_146 ;
}
V_28 = F_115 ( V_43 , & V_207 ,
(struct V_206 T_6 * ) V_130 , V_17 ) ;
F_94 ( V_43 ) ;
return V_28 ;
}
case V_241 :
{
struct V_242 V_243 ;
int V_28 ;
if ( V_34 < F_91 ( 0 ) ) {
F_94 ( V_43 ) ;
return - V_53 ;
}
if ( F_83 ( & V_243 , V_130 , F_91 ( 0 ) ) ) {
F_94 ( V_43 ) ;
return - V_146 ;
}
V_28 = F_116 ( V_43 , & V_243 ,
(struct V_242 T_6 * ) V_130 ,
V_17 ) ;
F_94 ( V_43 ) ;
return V_28 ;
}
case V_143 :
V_50 = V_42 -> V_256 ;
break;
case V_275 :
{
struct V_1 V_2 ;
F_94 ( V_43 ) ;
if ( V_43 -> V_80 != V_173 )
return - V_177 ;
V_2 . V_276 = ( V_188 void * ) V_130 ;
V_2 . V_277 = V_34 ;
V_2 . V_21 = V_44 ;
if ( V_42 -> V_45 & V_166 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_42 -> V_278 ;
V_6 . V_68 . V_8 = V_42 -> V_278 ;
V_6 . V_67 = V_42 -> V_200 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_42 -> V_45 & V_167 ) {
int V_279 = V_42 -> V_183 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_279 ) , & V_279 ) ;
}
if ( V_42 -> V_45 & V_168 ) {
int V_15 = V_42 -> V_280 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_34 -= V_2 . V_277 ;
return F_109 ( V_34 , V_17 ) ;
}
case V_136 :
V_50 = V_42 -> V_257 ;
break;
case V_138 :
V_50 = V_42 -> V_264 ;
break;
case V_139 :
V_50 = V_42 -> V_265 ;
break;
default:
F_94 ( V_43 ) ;
return - V_177 ;
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
if ( V_28 == - V_177 && V_129 != V_275 &&
! F_69 ( V_129 ) ) {
int V_34 ;
if ( F_68 ( V_34 , V_17 ) )
return - V_146 ;
F_71 ( V_43 ) ;
V_28 = F_118 ( V_43 , V_157 , V_129 , V_130 ,
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
if ( V_129 == V_241 )
return F_120 ( V_43 , V_128 , V_129 , V_130 , V_17 ,
F_117 ) ;
V_28 = F_107 ( V_43 , V_128 , V_129 , V_130 , V_17 ,
V_281 ) ;
#ifdef F_102
if ( V_28 == - V_177 && V_129 != V_275 &&
! F_69 ( V_129 ) ) {
int V_34 ;
if ( F_68 ( V_34 , V_17 ) )
return - V_146 ;
F_71 ( V_43 ) ;
V_28 = F_121 ( V_43 , V_157 , V_129 , V_130 , & V_34 ) ;
F_94 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_109 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
