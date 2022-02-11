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
int F_21 ( struct V_46 * V_46 , struct V_1 * V_2 , struct V_47 * V_48 )
{
int V_28 , V_49 ;
struct V_50 * V_51 ;
for ( V_51 = F_22 ( V_2 ) ; V_51 ; V_51 = F_23 ( V_2 , V_51 ) ) {
if ( ! F_24 ( V_2 , V_51 ) )
return - V_52 ;
if ( V_51 -> V_53 != V_10 )
continue;
switch ( V_51 -> V_54 ) {
case V_23 :
V_28 = V_51 -> V_55 - F_25 ( sizeof( struct V_50 ) ) ;
V_28 = F_26 ( V_46 , & V_48 -> V_16 , F_27 ( V_51 ) ,
V_28 < 40 ? V_28 : 40 ) ;
if ( V_28 )
return V_28 ;
break;
case V_11 :
{
struct V_5 * V_6 ;
if ( V_51 -> V_55 != F_28 ( sizeof( struct V_5 ) ) )
return - V_52 ;
V_6 = (struct V_5 * ) F_27 ( V_51 ) ;
V_48 -> V_56 = V_6 -> V_57 ;
V_48 -> V_58 = V_6 -> V_59 . V_8 ;
break;
}
case V_13 :
if ( V_51 -> V_55 != F_28 ( sizeof( int ) ) )
return - V_52 ;
V_49 = * ( int * ) F_27 ( V_51 ) ;
if ( V_49 < 1 || V_49 > 255 )
return - V_52 ;
V_48 -> V_12 = V_49 ;
break;
case V_14 :
if ( V_51 -> V_55 != F_28 ( sizeof( int ) ) )
return - V_52 ;
V_49 = * ( int * ) F_27 ( V_51 ) ;
if ( V_49 < 0 || V_49 > 255 )
return - V_52 ;
V_48 -> V_15 = V_49 ;
V_48 -> V_60 = F_29 ( V_48 -> V_15 ) ;
break;
default:
return - V_52 ;
}
}
return 0 ;
}
static void F_30 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_31 ( V_62 , struct V_63 , V_65 ) ;
F_32 ( V_64 -> V_66 ) ;
F_33 ( V_64 ) ;
}
int F_34 ( struct V_67 * V_43 , unsigned char V_68 ,
void (* F_35)( struct V_67 * ) )
{
struct V_63 * V_64 , * V_69 ;
struct V_63 T_3 * * V_70 ;
if ( V_43 -> V_71 != V_72 || F_20 ( V_43 ) -> V_73 == V_74 )
return - V_52 ;
V_69 = V_68 ? F_36 ( sizeof( * V_69 ) , V_75 ) : NULL ;
F_37 ( & V_76 ) ;
for ( V_70 = & V_63 ;
( V_64 = F_38 ( * V_70 ,
F_39 ( & V_76 ) ) ) != NULL ;
V_70 = & V_64 -> V_77 ) {
if ( V_64 -> V_43 == V_43 ) {
if ( V_68 ) {
F_40 ( & V_76 ) ;
F_33 ( V_69 ) ;
return - V_78 ;
}
V_64 -> V_43 = NULL ;
F_41 ( * V_70 , V_64 -> V_77 ) ;
F_40 ( & V_76 ) ;
if ( V_64 -> F_35 )
V_64 -> F_35 ( V_43 ) ;
V_64 -> V_66 = V_43 ;
F_42 ( & V_64 -> V_65 , F_30 ) ;
return 0 ;
}
}
if ( V_69 == NULL ) {
F_40 ( & V_76 ) ;
return - V_79 ;
}
V_69 -> V_43 = V_43 ;
V_69 -> F_35 = F_35 ;
V_69 -> V_77 = V_64 ;
F_41 ( * V_70 , V_69 ) ;
F_43 ( V_43 ) ;
F_40 ( & V_76 ) ;
return 0 ;
}
void F_44 ( struct V_67 * V_43 , struct V_3 * V_4 , int V_28 ,
T_2 V_80 , T_1 V_6 , T_4 * V_81 )
{
struct V_82 * V_83 ;
V_4 = F_45 ( V_4 , V_84 ) ;
if ( ! V_4 )
return;
V_83 = F_46 ( V_4 ) ;
V_83 -> V_85 . V_86 = V_28 ;
V_83 -> V_85 . V_87 = V_88 ;
V_83 -> V_85 . V_89 = F_47 ( V_4 ) -> type ;
V_83 -> V_85 . V_90 = F_47 ( V_4 ) -> V_91 ;
V_83 -> V_85 . V_92 = 0 ;
V_83 -> V_85 . V_93 = V_6 ;
V_83 -> V_85 . V_94 = 0 ;
V_83 -> V_95 = ( T_4 * ) & ( ( (struct V_31 * ) ( F_47 ( V_4 ) + 1 ) ) -> V_9 ) -
F_48 ( V_4 ) ;
V_83 -> V_80 = V_80 ;
if ( F_49 ( V_4 , V_81 - V_4 -> V_96 ) != NULL ) {
F_50 ( V_4 ) ;
if ( F_51 ( V_43 , V_4 ) == 0 )
return;
}
F_52 ( V_4 ) ;
}
void F_53 ( struct V_67 * V_43 , int V_28 , T_5 V_9 , T_2 V_80 , T_1 V_6 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
struct V_82 * V_83 ;
struct V_31 * V_32 ;
struct V_3 * V_4 ;
if ( ! V_42 -> V_97 )
return;
V_4 = F_54 ( sizeof( struct V_31 ) , V_84 ) ;
if ( ! V_4 )
return;
F_55 ( V_4 , sizeof( struct V_31 ) ) ;
F_56 ( V_4 ) ;
V_32 = F_3 ( V_4 ) ;
V_32 -> V_9 = V_9 ;
V_83 = F_46 ( V_4 ) ;
V_83 -> V_85 . V_86 = V_28 ;
V_83 -> V_85 . V_87 = V_98 ;
V_83 -> V_85 . V_89 = 0 ;
V_83 -> V_85 . V_90 = 0 ;
V_83 -> V_85 . V_92 = 0 ;
V_83 -> V_85 . V_93 = V_6 ;
V_83 -> V_85 . V_94 = 0 ;
V_83 -> V_95 = ( T_4 * ) & V_32 -> V_9 - F_48 ( V_4 ) ;
V_83 -> V_80 = V_80 ;
F_57 ( V_4 , F_58 ( V_4 ) - V_4 -> V_96 ) ;
F_50 ( V_4 ) ;
if ( F_51 ( V_43 , V_4 ) )
F_52 ( V_4 ) ;
}
int F_59 ( struct V_67 * V_43 , struct V_1 * V_2 , int V_34 , int * V_99 )
{
struct V_82 * V_83 ;
struct V_3 * V_4 , * V_100 ;
F_60 ( struct V_30 * , sin , V_2 -> V_101 ) ;
struct {
struct V_102 V_85 ;
struct V_30 V_103 ;
} V_104 ;
int V_28 ;
int V_105 ;
V_28 = - V_106 ;
V_4 = F_61 ( & V_43 -> V_107 ) ;
if ( V_4 == NULL )
goto V_108;
V_105 = V_4 -> V_34 ;
if ( V_105 > V_34 ) {
V_2 -> V_21 |= V_109 ;
V_105 = V_34 ;
}
V_28 = F_62 ( V_4 , 0 , V_2 -> V_110 , V_105 ) ;
if ( V_28 )
goto V_111;
F_63 ( V_2 , V_43 , V_4 ) ;
V_83 = F_46 ( V_4 ) ;
if ( sin ) {
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = * ( T_5 * ) ( F_48 ( V_4 ) +
V_83 -> V_95 ) ;
sin -> V_38 = V_83 -> V_80 ;
memset ( & sin -> V_39 , 0 , sizeof( sin -> V_39 ) ) ;
* V_99 = sizeof( * sin ) ;
}
memcpy ( & V_104 . V_85 , & V_83 -> V_85 , sizeof( struct V_102 ) ) ;
sin = & V_104 . V_103 ;
sin -> V_35 = V_112 ;
if ( V_83 -> V_85 . V_87 == V_88 ) {
struct V_41 * V_42 = F_20 ( V_43 ) ;
sin -> V_35 = V_36 ;
sin -> V_37 . V_8 = F_3 ( V_4 ) -> V_113 ;
sin -> V_38 = 0 ;
memset ( & sin -> V_39 , 0 , sizeof( sin -> V_39 ) ) ;
if ( V_42 -> V_45 )
F_19 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_114 , sizeof( V_104 ) , & V_104 ) ;
V_2 -> V_21 |= V_115 ;
V_28 = V_105 ;
F_37 ( & V_43 -> V_107 . V_116 ) ;
V_43 -> V_117 = 0 ;
V_100 = F_64 ( & V_43 -> V_107 ) ;
if ( V_100 != NULL ) {
V_43 -> V_117 = F_46 ( V_100 ) -> V_85 . V_86 ;
F_40 ( & V_43 -> V_107 . V_116 ) ;
V_43 -> V_118 ( V_43 ) ;
} else
F_40 ( & V_43 -> V_107 . V_116 ) ;
V_111:
F_52 ( V_4 ) ;
V_108:
return V_28 ;
}
static int F_65 ( struct V_67 * V_43 , int V_119 ,
int V_120 , char T_6 * V_121 , unsigned int V_17 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_49 = 0 , V_28 ;
switch ( V_120 ) {
case V_11 :
case V_122 :
case V_18 :
case V_123 :
case V_23 :
case V_14 :
case V_13 :
case V_124 :
case V_125 :
case V_114 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
if ( V_17 >= sizeof( int ) ) {
if ( F_66 ( V_49 , ( int T_6 * ) V_121 ) )
return - V_137 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_138 ;
if ( F_66 ( V_138 , ( unsigned char T_6 * ) V_121 ) )
return - V_137 ;
V_49 = ( int ) V_138 ;
}
}
if ( F_67 ( V_120 ) )
return F_68 ( V_43 , V_120 , V_121 , V_17 ) ;
V_28 = 0 ;
F_69 ( V_43 ) ;
switch ( V_120 ) {
case V_139 :
{
struct V_140 * V_141 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_142;
V_28 = F_70 ( F_71 ( V_43 ) , & V_16 ,
V_121 , V_17 ) ;
if ( V_28 )
break;
V_141 = F_38 ( V_42 -> V_143 ,
F_72 ( V_43 ) ) ;
if ( V_42 -> V_144 ) {
struct V_145 * V_146 = F_73 ( V_43 ) ;
#if F_74 ( V_147 )
if ( V_43 -> V_148 == V_149 ||
( ! ( ( 1 << V_43 -> V_150 ) &
( V_151 | V_152 ) ) &&
V_42 -> V_153 != V_154 ) ) {
#endif
if ( V_141 )
V_146 -> V_155 -= V_141 -> V_16 . V_17 ;
if ( V_16 )
V_146 -> V_155 += V_16 -> V_16 . V_17 ;
V_146 -> V_156 ( V_43 , V_146 -> V_157 ) ;
#if F_74 ( V_147 )
}
#endif
}
F_41 ( V_42 -> V_143 , V_16 ) ;
if ( V_141 )
F_75 ( V_141 , V_65 ) ;
break;
}
case V_11 :
if ( V_49 )
V_42 -> V_45 |= V_158 ;
else
V_42 -> V_45 &= ~ V_158 ;
break;
case V_122 :
if ( V_49 )
V_42 -> V_45 |= V_159 ;
else
V_42 -> V_45 &= ~ V_159 ;
break;
case V_123 :
if ( V_49 )
V_42 -> V_45 |= V_160 ;
else
V_42 -> V_45 &= ~ V_160 ;
break;
case V_18 :
if ( V_49 )
V_42 -> V_45 |= V_161 ;
else
V_42 -> V_45 &= ~ V_161 ;
break;
case V_23 :
if ( V_49 )
V_42 -> V_45 |= V_162 ;
else
V_42 -> V_45 &= ~ V_162 ;
break;
case V_128 :
if ( V_49 )
V_42 -> V_45 |= V_163 ;
else
V_42 -> V_45 &= ~ V_163 ;
break;
case V_136 :
if ( V_49 )
V_42 -> V_45 |= V_164 ;
else
V_42 -> V_45 &= ~ V_164 ;
break;
case V_14 :
if ( V_43 -> V_71 == V_165 ) {
V_49 &= ~ V_166 ;
V_49 |= V_42 -> V_15 & V_166 ;
}
if ( V_42 -> V_15 != V_49 ) {
V_42 -> V_15 = V_49 ;
V_43 -> V_167 = F_29 ( V_49 ) ;
F_76 ( V_43 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_142;
if ( V_49 != - 1 && ( V_49 < 1 || V_49 > 255 ) )
goto V_142;
V_42 -> V_168 = V_49 ;
break;
case V_124 :
if ( V_43 -> V_71 != V_72 ) {
V_28 = - V_169 ;
break;
}
V_42 -> V_170 = V_49 ? 1 : 0 ;
break;
case V_131 :
if ( V_43 -> V_71 != V_72 ) {
V_28 = - V_169 ;
break;
}
V_42 -> V_171 = V_49 ? 1 : 0 ;
break;
case V_125 :
if ( V_49 < V_172 || V_49 > V_173 )
goto V_142;
V_42 -> V_174 = V_49 ;
break;
case V_114 :
V_42 -> V_97 = ! ! V_49 ;
if ( ! V_49 )
F_77 ( & V_43 -> V_107 ) ;
break;
case V_133 :
if ( V_43 -> V_71 == V_165 )
goto V_142;
if ( V_17 < 1 )
goto V_142;
if ( V_49 == - 1 )
V_49 = 1 ;
if ( V_49 < 0 || V_49 > 255 )
goto V_142;
V_42 -> V_175 = V_49 ;
break;
case V_135 :
if ( V_17 < 1 )
goto V_142;
V_42 -> V_176 = ! ! V_49 ;
break;
case V_132 :
{
struct V_177 * V_178 = NULL ;
int V_179 ;
if ( V_17 != sizeof( int ) )
goto V_142;
V_179 = ( V_180 int ) F_78 ( ( V_180 T_5 ) V_49 ) ;
if ( V_179 == 0 ) {
V_42 -> V_181 = 0 ;
V_28 = 0 ;
break;
}
V_178 = F_79 ( F_71 ( V_43 ) , V_179 ) ;
V_28 = - V_182 ;
if ( ! V_178 )
break;
F_80 ( V_178 ) ;
V_28 = - V_52 ;
if ( V_43 -> V_183 )
break;
V_42 -> V_181 = V_179 ;
V_28 = 0 ;
break;
}
case V_184 :
{
struct V_185 V_186 ;
struct V_177 * V_178 = NULL ;
if ( V_43 -> V_71 == V_165 )
goto V_142;
if ( V_17 < sizeof( struct V_187 ) )
goto V_142;
V_28 = - V_137 ;
if ( V_17 >= sizeof( struct V_185 ) ) {
if ( F_81 ( & V_186 , V_121 , sizeof( V_186 ) ) )
break;
} else {
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
if ( V_17 >= sizeof( struct V_188 ) ) {
if ( F_81 ( & V_186 , V_121 ,
sizeof( struct V_188 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_187 ) ) {
if ( F_81 ( & V_186 . V_189 , V_121 ,
sizeof( struct V_187 ) ) )
break;
}
}
if ( ! V_186 . V_190 ) {
if ( V_186 . V_189 . V_8 == F_82 ( V_191 ) ) {
V_42 -> V_192 = 0 ;
V_42 -> V_193 = 0 ;
V_28 = 0 ;
break;
}
V_178 = F_83 ( F_71 ( V_43 ) , V_186 . V_189 . V_8 ) ;
if ( V_178 )
V_186 . V_190 = V_178 -> V_179 ;
} else
V_178 = F_79 ( F_71 ( V_43 ) , V_186 . V_190 ) ;
V_28 = - V_182 ;
if ( ! V_178 )
break;
F_80 ( V_178 ) ;
V_28 = - V_52 ;
if ( V_43 -> V_183 &&
V_186 . V_190 != V_43 -> V_183 )
break;
V_42 -> V_192 = V_186 . V_190 ;
V_42 -> V_193 = V_186 . V_189 . V_8 ;
V_28 = 0 ;
break;
}
case V_194 :
case V_195 :
{
struct V_185 V_186 ;
V_28 = - V_196 ;
if ( F_20 ( V_43 ) -> V_144 )
break;
if ( V_17 < sizeof( struct V_188 ) )
goto V_142;
V_28 = - V_137 ;
if ( V_17 >= sizeof( struct V_185 ) ) {
if ( F_81 ( & V_186 , V_121 , sizeof( V_186 ) ) )
break;
} else {
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
if ( F_81 ( & V_186 , V_121 , sizeof( struct V_188 ) ) )
break;
}
if ( V_120 == V_194 )
V_28 = F_84 ( V_43 , & V_186 ) ;
else
V_28 = F_85 ( V_43 , & V_186 ) ;
break;
}
case V_197 :
{
struct V_198 * V_199 ;
if ( V_17 < F_86 ( 0 ) )
goto V_142;
if ( V_17 > V_200 ) {
V_28 = - V_79 ;
break;
}
V_199 = F_36 ( V_17 , V_75 ) ;
if ( ! V_199 ) {
V_28 = - V_79 ;
break;
}
V_28 = - V_137 ;
if ( F_81 ( V_199 , V_121 , V_17 ) ) {
F_33 ( V_199 ) ;
break;
}
if ( V_199 -> V_201 >= 0x3ffffffcU ||
V_199 -> V_201 > V_202 ) {
F_33 ( V_199 ) ;
V_28 = - V_79 ;
break;
}
if ( F_86 ( V_199 -> V_201 ) > V_17 ) {
F_33 ( V_199 ) ;
V_28 = - V_52 ;
break;
}
V_28 = F_87 ( V_43 , V_199 , 0 ) ;
F_33 ( V_199 ) ;
break;
}
case V_203 :
case V_204 :
case V_205 :
case V_206 :
{
struct V_207 V_208 ;
int V_209 , V_210 ;
if ( V_17 != sizeof( struct V_207 ) )
goto V_142;
if ( F_81 ( & V_208 , V_121 , sizeof( V_208 ) ) ) {
V_28 = - V_137 ;
break;
}
if ( V_120 == V_203 ) {
V_209 = V_211 ;
V_210 = 1 ;
} else if ( V_120 == V_204 ) {
V_209 = V_211 ;
V_210 = 0 ;
} else if ( V_120 == V_205 ) {
struct V_185 V_186 ;
V_186 . V_212 . V_8 = V_208 . V_212 ;
V_186 . V_189 . V_8 = V_208 . V_213 ;
V_186 . V_190 = 0 ;
V_28 = F_84 ( V_43 , & V_186 ) ;
if ( V_28 && V_28 != - V_78 )
break;
V_209 = V_214 ;
V_210 = 1 ;
} else {
V_209 = V_214 ;
V_210 = 0 ;
}
V_28 = F_88 ( V_210 , V_209 , V_43 , & V_208 , 0 ) ;
break;
}
case V_215 :
case V_216 :
{
struct V_217 V_218 ;
struct V_30 * V_219 ;
struct V_185 V_186 ;
if ( V_17 < sizeof( struct V_217 ) )
goto V_142;
V_28 = - V_137 ;
if ( F_81 ( & V_218 , V_121 , sizeof( V_218 ) ) )
break;
V_219 = (struct V_30 * ) & V_218 . V_220 ;
if ( V_219 -> V_35 != V_36 )
goto V_142;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_212 = V_219 -> V_37 ;
V_186 . V_190 = V_218 . V_221 ;
if ( V_120 == V_215 )
V_28 = F_84 ( V_43 , & V_186 ) ;
else
V_28 = F_85 ( V_43 , & V_186 ) ;
break;
}
case V_222 :
case V_223 :
case V_224 :
case V_225 :
{
struct V_226 V_227 ;
struct V_207 V_208 ;
struct V_30 * V_219 ;
int V_209 , V_210 ;
if ( V_17 != sizeof( struct V_226 ) )
goto V_142;
if ( F_81 ( & V_227 , V_121 , sizeof( V_227 ) ) ) {
V_28 = - V_137 ;
break;
}
if ( V_227 . V_228 . V_229 != V_36 ||
V_227 . V_230 . V_229 != V_36 ) {
V_28 = - V_182 ;
break;
}
V_219 = (struct V_30 * ) & V_227 . V_228 ;
V_208 . V_212 = V_219 -> V_37 . V_8 ;
V_219 = (struct V_30 * ) & V_227 . V_230 ;
V_208 . V_231 = V_219 -> V_37 . V_8 ;
V_208 . V_213 = 0 ;
if ( V_120 == V_224 ) {
V_209 = V_211 ;
V_210 = 1 ;
} else if ( V_120 == V_225 ) {
V_209 = V_211 ;
V_210 = 0 ;
} else if ( V_120 == V_222 ) {
struct V_185 V_186 ;
V_219 = (struct V_30 * ) & V_227 . V_228 ;
V_186 . V_212 = V_219 -> V_37 ;
V_186 . V_189 . V_8 = 0 ;
V_186 . V_190 = V_227 . V_232 ;
V_28 = F_84 ( V_43 , & V_186 ) ;
if ( V_28 && V_28 != - V_78 )
break;
V_227 . V_232 = V_186 . V_190 ;
V_209 = V_214 ;
V_210 = 1 ;
} else {
V_209 = V_214 ;
V_210 = 0 ;
}
V_28 = F_88 ( V_210 , V_209 , V_43 , & V_208 ,
V_227 . V_232 ) ;
break;
}
case V_233 :
{
struct V_30 * V_219 ;
struct V_198 * V_199 = NULL ;
struct V_234 * V_235 = NULL ;
int V_236 , V_237 , V_179 ;
if ( V_17 < F_89 ( 0 ) )
goto V_142;
if ( V_17 > V_200 ) {
V_28 = - V_79 ;
break;
}
V_235 = F_36 ( V_17 , V_75 ) ;
if ( ! V_235 ) {
V_28 = - V_79 ;
break;
}
V_28 = - V_137 ;
if ( F_81 ( V_235 , V_121 , V_17 ) )
goto V_238;
if ( V_235 -> V_239 >= 0x1ffffff ||
V_235 -> V_239 > V_202 ) {
V_28 = - V_79 ;
goto V_238;
}
if ( F_89 ( V_235 -> V_239 ) > V_17 ) {
V_28 = - V_52 ;
goto V_238;
}
V_236 = F_86 ( V_235 -> V_239 ) ;
V_199 = F_36 ( V_236 , V_75 ) ;
if ( ! V_199 ) {
V_28 = - V_79 ;
goto V_238;
}
V_179 = V_235 -> V_240 ;
V_219 = (struct V_30 * ) & V_235 -> V_241 ;
if ( V_219 -> V_35 != V_36 ) {
V_28 = - V_182 ;
goto V_238;
}
V_199 -> V_242 = V_219 -> V_37 . V_8 ;
V_199 -> V_243 = 0 ;
V_199 -> V_244 = V_235 -> V_245 ;
V_199 -> V_201 = V_235 -> V_239 ;
V_28 = - V_182 ;
for ( V_237 = 0 ; V_237 < V_235 -> V_239 ; ++ V_237 ) {
V_219 = (struct V_30 * ) & V_235 -> V_246 [ V_237 ] ;
if ( V_219 -> V_35 != V_36 )
goto V_238;
V_199 -> V_247 [ V_237 ] = V_219 -> V_37 . V_8 ;
}
F_33 ( V_235 ) ;
V_235 = NULL ;
V_28 = F_87 ( V_43 , V_199 , V_179 ) ;
V_238:
F_33 ( V_199 ) ;
F_33 ( V_235 ) ;
break;
}
case V_134 :
if ( V_17 < 1 )
goto V_142;
if ( V_49 != 0 && V_49 != 1 )
goto V_142;
V_42 -> V_248 = V_49 ;
break;
case V_126 :
V_28 = F_34 ( V_43 , V_49 ? 1 : 0 , NULL ) ;
break;
case V_127 :
if ( V_17 < 1 )
goto V_142;
V_42 -> V_249 = ! ! V_49 ;
break;
case V_250 :
case V_251 :
V_28 = - V_252 ;
if ( ! F_90 ( F_71 ( V_43 ) -> V_253 , V_254 ) )
break;
V_28 = F_91 ( V_43 , V_120 , V_121 , V_17 ) ;
break;
case V_129 :
if ( ! ! V_49 && ! F_90 ( F_71 ( V_43 ) -> V_253 , V_255 ) &&
! F_90 ( F_71 ( V_43 ) -> V_253 , V_254 ) ) {
V_28 = - V_252 ;
break;
}
if ( V_17 < 1 )
goto V_142;
V_42 -> V_256 = ! ! V_49 ;
break;
case V_130 :
if ( V_17 < 1 )
goto V_142;
if ( V_49 < 0 || V_49 > 255 )
goto V_142;
V_42 -> V_257 = V_49 ;
break;
default:
V_28 = - V_169 ;
break;
}
F_92 ( V_43 ) ;
return V_28 ;
V_142:
F_92 ( V_43 ) ;
return - V_52 ;
}
void F_93 ( const struct V_67 * V_43 , struct V_3 * V_4 )
{
struct V_5 * V_258 = F_2 ( V_4 ) ;
bool V_259 = ( F_20 ( V_43 ) -> V_45 & V_158 ) ||
F_94 ( V_43 ) ;
if ( V_259 && F_95 ( V_4 ) ) {
V_258 -> V_57 = F_96 ( V_4 ) ;
V_258 -> V_59 . V_8 = F_97 ( V_4 ) ;
} else {
V_258 -> V_57 = 0 ;
V_258 -> V_59 . V_8 = 0 ;
}
F_98 ( V_4 ) ;
}
int F_99 ( struct V_67 * V_43 , int V_119 ,
int V_120 , char T_6 * V_121 , unsigned int V_17 )
{
int V_28 ;
if ( V_119 != V_10 )
return - V_169 ;
V_28 = F_65 ( V_43 , V_119 , V_120 , V_121 , V_17 ) ;
#ifdef F_100
if ( V_28 == - V_169 && V_120 != V_124 &&
V_120 != V_250 &&
V_120 != V_251 &&
! F_67 ( V_120 ) ) {
F_69 ( V_43 ) ;
V_28 = F_101 ( V_43 , V_149 , V_120 , V_121 , V_17 ) ;
F_92 ( V_43 ) ;
}
#endif
return V_28 ;
}
int F_102 ( struct V_67 * V_43 , int V_119 , int V_120 ,
char T_6 * V_121 , unsigned int V_17 )
{
int V_28 ;
if ( V_119 != V_10 )
return - V_169 ;
if ( V_120 >= V_215 && V_120 <= V_233 )
return F_103 ( V_43 , V_119 , V_120 , V_121 , V_17 ,
F_99 ) ;
V_28 = F_65 ( V_43 , V_119 , V_120 , V_121 , V_17 ) ;
#ifdef F_100
if ( V_28 == - V_169 && V_120 != V_124 &&
V_120 != V_250 &&
V_120 != V_251 &&
! F_67 ( V_120 ) ) {
F_69 ( V_43 ) ;
V_28 = F_104 ( V_43 , V_149 , V_120 ,
V_121 , V_17 ) ;
F_92 ( V_43 ) ;
}
#endif
return V_28 ;
}
static int F_105 ( struct V_67 * V_43 , int V_119 , int V_120 ,
char T_6 * V_121 , int T_6 * V_17 , unsigned int V_44 )
{
struct V_41 * V_42 = F_20 ( V_43 ) ;
int V_49 ;
int V_34 ;
if ( V_119 != V_10 )
return - V_260 ;
if ( F_67 ( V_120 ) )
return F_106 ( V_43 , V_120 , V_121 , V_17 ) ;
if ( F_66 ( V_34 , V_17 ) )
return - V_137 ;
if ( V_34 < 0 )
return - V_52 ;
F_69 ( V_43 ) ;
switch ( V_120 ) {
case V_139 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_140 * V_143 ;
V_143 = F_38 ( V_42 -> V_143 ,
F_72 ( V_43 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_143 )
memcpy ( V_19 , & V_143 -> V_16 ,
sizeof( struct V_20 ) +
V_143 -> V_16 . V_17 ) ;
F_92 ( V_43 ) ;
if ( V_16 -> V_17 == 0 )
return F_107 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_34 = F_108 (unsigned int, len, opt->optlen) ;
if ( F_107 ( V_34 , V_17 ) )
return - V_137 ;
if ( F_109 ( V_121 , V_16 -> V_24 , V_34 ) )
return - V_137 ;
return 0 ;
}
case V_11 :
V_49 = ( V_42 -> V_45 & V_158 ) != 0 ;
break;
case V_122 :
V_49 = ( V_42 -> V_45 & V_159 ) != 0 ;
break;
case V_123 :
V_49 = ( V_42 -> V_45 & V_160 ) != 0 ;
break;
case V_18 :
V_49 = ( V_42 -> V_45 & V_161 ) != 0 ;
break;
case V_23 :
V_49 = ( V_42 -> V_45 & V_162 ) != 0 ;
break;
case V_128 :
V_49 = ( V_42 -> V_45 & V_163 ) != 0 ;
break;
case V_136 :
V_49 = ( V_42 -> V_45 & V_164 ) != 0 ;
break;
case V_14 :
V_49 = V_42 -> V_15 ;
break;
case V_13 :
V_49 = ( V_42 -> V_168 == - 1 ?
V_261 :
V_42 -> V_168 ) ;
break;
case V_124 :
V_49 = V_42 -> V_170 ;
break;
case V_131 :
V_49 = V_42 -> V_171 ;
break;
case V_125 :
V_49 = V_42 -> V_174 ;
break;
case V_262 :
{
struct V_263 * V_264 ;
V_49 = 0 ;
V_264 = F_110 ( V_43 ) ;
if ( V_264 ) {
V_49 = F_111 ( V_264 ) ;
F_112 ( V_264 ) ;
}
if ( ! V_49 ) {
F_92 ( V_43 ) ;
return - V_265 ;
}
break;
}
case V_114 :
V_49 = V_42 -> V_97 ;
break;
case V_133 :
V_49 = V_42 -> V_175 ;
break;
case V_135 :
V_49 = V_42 -> V_176 ;
break;
case V_132 :
V_49 = ( V_180 int ) F_82 ( ( V_266 ) V_42 -> V_181 ) ;
break;
case V_184 :
{
struct V_187 V_58 ;
V_34 = F_108 (unsigned int, len, sizeof(struct in_addr)) ;
V_58 . V_8 = V_42 -> V_193 ;
F_92 ( V_43 ) ;
if ( F_107 ( V_34 , V_17 ) )
return - V_137 ;
if ( F_109 ( V_121 , & V_58 , V_34 ) )
return - V_137 ;
return 0 ;
}
case V_197 :
{
struct V_198 V_199 ;
int V_28 ;
if ( V_34 < F_86 ( 0 ) ) {
F_92 ( V_43 ) ;
return - V_52 ;
}
if ( F_81 ( & V_199 , V_121 , F_86 ( 0 ) ) ) {
F_92 ( V_43 ) ;
return - V_137 ;
}
V_28 = F_113 ( V_43 , & V_199 ,
(struct V_198 T_6 * ) V_121 , V_17 ) ;
F_92 ( V_43 ) ;
return V_28 ;
}
case V_233 :
{
struct V_234 V_235 ;
int V_28 ;
if ( V_34 < F_89 ( 0 ) ) {
F_92 ( V_43 ) ;
return - V_52 ;
}
if ( F_81 ( & V_235 , V_121 , F_89 ( 0 ) ) ) {
F_92 ( V_43 ) ;
return - V_137 ;
}
V_28 = F_114 ( V_43 , & V_235 ,
(struct V_234 T_6 * ) V_121 ,
V_17 ) ;
F_92 ( V_43 ) ;
return V_28 ;
}
case V_134 :
V_49 = V_42 -> V_248 ;
break;
case V_267 :
{
struct V_1 V_2 ;
F_92 ( V_43 ) ;
if ( V_43 -> V_71 != V_165 )
return - V_169 ;
V_2 . V_268 = V_121 ;
V_2 . V_269 = V_34 ;
V_2 . V_21 = V_44 ;
if ( V_42 -> V_45 & V_158 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_42 -> V_270 ;
V_6 . V_59 . V_8 = V_42 -> V_270 ;
V_6 . V_57 = V_42 -> V_192 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_42 -> V_45 & V_159 ) {
int V_271 = V_42 -> V_175 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_271 ) , & V_271 ) ;
}
if ( V_42 -> V_45 & V_160 ) {
int V_15 = V_42 -> V_272 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_34 -= V_2 . V_269 ;
return F_107 ( V_34 , V_17 ) ;
}
case V_127 :
V_49 = V_42 -> V_249 ;
break;
case V_129 :
V_49 = V_42 -> V_256 ;
break;
case V_130 :
V_49 = V_42 -> V_257 ;
break;
default:
F_92 ( V_43 ) ;
return - V_169 ;
}
F_92 ( V_43 ) ;
if ( V_34 < sizeof( int ) && V_34 > 0 && V_49 >= 0 && V_49 <= 255 ) {
unsigned char V_138 = ( unsigned char ) V_49 ;
V_34 = 1 ;
if ( F_107 ( V_34 , V_17 ) )
return - V_137 ;
if ( F_109 ( V_121 , & V_138 , 1 ) )
return - V_137 ;
} else {
V_34 = F_108 (unsigned int, sizeof(int), len) ;
if ( F_107 ( V_34 , V_17 ) )
return - V_137 ;
if ( F_109 ( V_121 , & V_49 , V_34 ) )
return - V_137 ;
}
return 0 ;
}
int F_115 ( struct V_67 * V_43 , int V_119 ,
int V_120 , char T_6 * V_121 , int T_6 * V_17 )
{
int V_28 ;
V_28 = F_105 ( V_43 , V_119 , V_120 , V_121 , V_17 , 0 ) ;
#ifdef F_100
if ( V_28 == - V_169 && V_120 != V_267 &&
! F_67 ( V_120 ) ) {
int V_34 ;
if ( F_66 ( V_34 , V_17 ) )
return - V_137 ;
F_69 ( V_43 ) ;
V_28 = F_116 ( V_43 , V_149 , V_120 , V_121 ,
& V_34 ) ;
F_92 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_107 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
int F_117 ( struct V_67 * V_43 , int V_119 , int V_120 ,
char T_6 * V_121 , int T_6 * V_17 )
{
int V_28 ;
if ( V_120 == V_233 )
return F_118 ( V_43 , V_119 , V_120 , V_121 , V_17 ,
F_115 ) ;
V_28 = F_105 ( V_43 , V_119 , V_120 , V_121 , V_17 ,
V_273 ) ;
#ifdef F_100
if ( V_28 == - V_169 && V_120 != V_267 &&
! F_67 ( V_120 ) ) {
int V_34 ;
if ( F_66 ( V_34 , V_17 ) )
return - V_137 ;
F_69 ( V_43 ) ;
V_28 = F_119 ( V_43 , V_149 , V_120 , V_121 , & V_34 ) ;
F_92 ( V_43 ) ;
if ( V_28 >= 0 )
V_28 = F_107 ( V_34 , V_17 ) ;
return V_28 ;
}
#endif
return V_28 ;
}
