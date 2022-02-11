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
F_43 ( & V_106 ) ;
for ( V_100 = & V_94 ;
( V_95 = F_44 ( * V_100 ,
F_45 ( & V_106 ) ) ) != NULL ;
V_100 = & V_95 -> V_107 ) {
if ( V_95 -> V_52 == V_52 ) {
if ( V_98 ) {
F_46 ( & V_106 ) ;
F_39 ( V_99 ) ;
return - V_108 ;
}
V_95 -> V_52 = NULL ;
F_47 ( * V_100 , V_95 -> V_107 ) ;
F_46 ( & V_106 ) ;
if ( V_95 -> F_41 )
V_95 -> F_41 ( V_52 ) ;
V_95 -> V_97 = V_52 ;
F_48 ( & V_95 -> V_96 , F_36 ) ;
return 0 ;
}
}
if ( ! V_99 ) {
F_46 ( & V_106 ) ;
return - V_109 ;
}
V_99 -> V_52 = V_52 ;
V_99 -> F_41 = F_41 ;
F_47 ( V_99 -> V_107 , V_95 ) ;
F_49 ( * V_100 , V_99 ) ;
F_50 ( V_52 ) ;
F_46 ( & V_106 ) ;
return 0 ;
}
void F_51 ( struct V_51 * V_52 , struct V_3 * V_4 , int V_38 ,
T_3 V_110 , T_2 V_6 , V_90 * V_111 )
{
struct V_112 * V_113 ;
V_4 = F_52 ( V_4 , V_114 ) ;
if ( ! V_4 )
return;
V_113 = F_53 ( V_4 ) ;
V_113 -> V_115 . V_116 = V_38 ;
V_113 -> V_115 . V_117 = V_118 ;
V_113 -> V_115 . V_119 = F_54 ( V_4 ) -> type ;
V_113 -> V_115 . V_120 = F_54 ( V_4 ) -> V_121 ;
V_113 -> V_115 . V_122 = 0 ;
V_113 -> V_115 . V_123 = V_6 ;
V_113 -> V_115 . V_124 = 0 ;
V_113 -> V_125 = ( V_90 * ) & ( ( (struct V_41 * ) ( F_54 ( V_4 ) + 1 ) ) -> V_9 ) -
F_55 ( V_4 ) ;
V_113 -> V_110 = V_110 ;
if ( F_56 ( V_4 , V_111 - V_4 -> V_126 ) ) {
F_57 ( V_4 ) ;
if ( F_58 ( V_52 , V_4 ) == 0 )
return;
}
F_59 ( V_4 ) ;
}
void F_60 ( struct V_51 * V_52 , int V_38 , T_5 V_9 , T_3 V_110 , T_2 V_6 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
struct V_112 * V_113 ;
struct V_41 * V_42 ;
struct V_3 * V_4 ;
if ( ! V_54 -> V_127 )
return;
V_4 = F_61 ( sizeof( struct V_41 ) , V_114 ) ;
if ( ! V_4 )
return;
F_62 ( V_4 , sizeof( struct V_41 ) ) ;
F_63 ( V_4 ) ;
V_42 = F_3 ( V_4 ) ;
V_42 -> V_9 = V_9 ;
V_113 = F_53 ( V_4 ) ;
V_113 -> V_115 . V_116 = V_38 ;
V_113 -> V_115 . V_117 = V_128 ;
V_113 -> V_115 . V_119 = 0 ;
V_113 -> V_115 . V_120 = 0 ;
V_113 -> V_115 . V_122 = 0 ;
V_113 -> V_115 . V_123 = V_6 ;
V_113 -> V_115 . V_124 = 0 ;
V_113 -> V_125 = ( V_90 * ) & V_42 -> V_9 - F_55 ( V_4 ) ;
V_113 -> V_110 = V_110 ;
F_64 ( V_4 , F_65 ( V_4 ) - V_4 -> V_126 ) ;
F_57 ( V_4 ) ;
if ( F_58 ( V_52 , V_4 ) )
F_59 ( V_4 ) ;
}
static inline bool F_66 ( struct V_112 * V_113 )
{
return V_113 -> V_115 . V_117 == V_118 ||
V_113 -> V_115 . V_117 == V_128 || V_113 -> V_110 ;
}
static bool F_67 ( const struct V_51 * V_52 ,
struct V_3 * V_4 ,
int V_117 )
{
struct V_5 * V_6 ;
if ( V_117 == V_118 )
return true ;
if ( V_117 == V_128 )
return false ;
V_6 = F_2 ( V_4 ) ;
if ( ! ( V_52 -> V_129 & V_130 ) ||
! V_6 -> V_88 )
return false ;
V_6 -> V_89 . V_8 = F_3 ( V_4 ) -> V_131 ;
return true ;
}
int F_68 ( struct V_51 * V_52 , struct V_1 * V_2 , int V_44 , int * V_132 )
{
struct V_112 * V_113 ;
struct V_3 * V_4 ;
F_69 ( struct V_40 * , sin , V_2 -> V_133 ) ;
struct {
struct V_134 V_115 ;
struct V_40 V_135 ;
} V_136 ;
int V_38 ;
int V_137 ;
F_70 ( V_52 -> V_138 == V_139 ) ;
V_38 = - V_140 ;
V_4 = F_71 ( V_52 ) ;
if ( ! V_4 )
goto V_141;
V_137 = V_4 -> V_44 ;
if ( V_137 > V_44 ) {
V_2 -> V_21 |= V_142 ;
V_137 = V_44 ;
}
V_38 = F_72 ( V_4 , 0 , V_2 , V_137 ) ;
if ( F_73 ( V_38 ) ) {
F_59 ( V_4 ) ;
return V_38 ;
}
F_74 ( V_2 , V_52 , V_4 ) ;
V_113 = F_53 ( V_4 ) ;
if ( sin && F_66 ( V_113 ) ) {
sin -> V_45 = V_46 ;
sin -> V_47 . V_8 = * ( T_5 * ) ( F_55 ( V_4 ) +
V_113 -> V_125 ) ;
sin -> V_48 = V_113 -> V_110 ;
memset ( & sin -> V_49 , 0 , sizeof( sin -> V_49 ) ) ;
* V_132 = sizeof( * sin ) ;
}
memcpy ( & V_136 . V_115 , & V_113 -> V_115 , sizeof( struct V_134 ) ) ;
sin = & V_136 . V_135 ;
memset ( sin , 0 , sizeof( * sin ) ) ;
if ( F_67 ( V_52 , V_4 , V_113 -> V_115 . V_117 ) ) {
sin -> V_45 = V_46 ;
sin -> V_47 . V_8 = F_3 ( V_4 ) -> V_131 ;
if ( F_24 ( V_52 ) -> V_56 )
F_75 ( V_2 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_143 , sizeof( V_136 ) , & V_136 ) ;
V_2 -> V_21 |= V_144 ;
V_38 = V_137 ;
F_76 ( V_4 ) ;
V_141:
return V_38 ;
}
static bool F_77 ( int V_145 )
{
switch ( V_145 ) {
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
case V_160 :
return true ;
}
return false ;
}
static int F_78 ( struct V_51 * V_52 , int V_161 ,
int V_145 , char T_6 * V_162 , unsigned int V_17 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
struct V_71 * V_71 = F_26 ( V_52 ) ;
int V_25 = 0 , V_38 ;
bool V_163 = F_77 ( V_145 ) ;
switch ( V_145 ) {
case V_11 :
case V_164 :
case V_18 :
case V_165 :
case V_23 :
case V_14 :
case V_13 :
case V_166 :
case V_167 :
case V_143 :
case V_160 :
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
case V_34 :
case V_27 :
if ( V_17 >= sizeof( int ) ) {
if ( F_79 ( V_25 , ( int T_6 * ) V_162 ) )
return - V_179 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_180 ;
if ( F_79 ( V_180 , ( unsigned char T_6 * ) V_162 ) )
return - V_179 ;
V_25 = ( int ) V_180 ;
}
}
if ( F_80 ( V_145 ) )
return F_81 ( V_52 , V_145 , V_162 , V_17 ) ;
V_38 = 0 ;
if ( V_163 )
F_82 () ;
F_83 ( V_52 ) ;
switch ( V_145 ) {
case V_181 :
{
struct V_182 * V_183 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_184;
V_38 = F_84 ( F_26 ( V_52 ) , & V_16 ,
V_162 , V_17 ) ;
if ( V_38 )
break;
V_183 = F_44 ( V_54 -> V_185 ,
F_85 ( V_52 ) ) ;
if ( V_54 -> V_186 ) {
struct V_187 * V_188 = F_86 ( V_52 ) ;
#if F_29 ( V_73 )
if ( V_52 -> V_138 == V_189 ||
( ! ( ( 1 << V_52 -> V_190 ) &
( V_191 | V_192 ) ) &&
V_54 -> V_193 != V_194 ) ) {
#endif
if ( V_183 )
V_188 -> V_195 -= V_183 -> V_16 . V_17 ;
if ( V_16 )
V_188 -> V_195 += V_16 -> V_16 . V_17 ;
V_188 -> V_196 ( V_52 , V_188 -> V_197 ) ;
#if F_29 ( V_73 )
}
#endif
}
F_49 ( V_54 -> V_185 , V_16 ) ;
if ( V_183 )
F_87 ( V_183 , V_96 ) ;
break;
}
case V_11 :
if ( V_25 )
V_54 -> V_56 |= V_57 ;
else
V_54 -> V_56 &= ~ V_57 ;
break;
case V_164 :
if ( V_25 )
V_54 -> V_56 |= V_58 ;
else
V_54 -> V_56 &= ~ V_58 ;
break;
case V_165 :
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
case V_169 :
if ( V_25 )
V_54 -> V_56 |= V_62 ;
else
V_54 -> V_56 &= ~ V_62 ;
break;
case V_178 :
if ( V_25 )
V_54 -> V_56 |= V_63 ;
else
V_54 -> V_56 &= ~ V_63 ;
break;
case V_34 :
if ( V_25 ) {
if ( ! ( V_54 -> V_56 & V_64 ) ) {
F_88 ( V_52 ) ;
V_54 -> V_56 |= V_64 ;
}
} else {
if ( V_54 -> V_56 & V_64 ) {
F_89 ( V_52 ) ;
V_54 -> V_56 &= ~ V_64 ;
}
}
break;
case V_27 :
if ( V_52 -> V_101 != V_102 && V_52 -> V_101 != V_198 )
goto V_184;
if ( V_25 )
V_54 -> V_56 |= V_65 ;
else
V_54 -> V_56 &= ~ V_65 ;
break;
case V_14 :
if ( V_52 -> V_101 == V_199 ) {
V_25 &= ~ V_200 ;
V_25 |= V_54 -> V_15 & V_200 ;
}
if ( V_54 -> V_15 != V_25 ) {
V_54 -> V_15 = V_25 ;
V_52 -> V_201 = F_35 ( V_25 ) ;
F_90 ( V_52 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_184;
if ( V_25 != - 1 && ( V_25 < 1 || V_25 > 255 ) )
goto V_184;
V_54 -> V_202 = V_25 ;
break;
case V_166 :
if ( V_52 -> V_101 != V_102 ) {
V_38 = - V_203 ;
break;
}
V_54 -> V_204 = V_25 ? 1 : 0 ;
break;
case V_172 :
if ( V_52 -> V_101 != V_102 ) {
V_38 = - V_203 ;
break;
}
V_54 -> V_205 = V_25 ? 1 : 0 ;
break;
case V_173 :
V_54 -> V_206 = V_25 ? 1 : 0 ;
break;
case V_167 :
if ( V_25 < V_207 || V_25 > V_208 )
goto V_184;
V_54 -> V_209 = V_25 ;
break;
case V_143 :
V_54 -> V_127 = ! ! V_25 ;
if ( ! V_25 )
F_91 ( & V_52 -> V_210 ) ;
break;
case V_175 :
if ( V_52 -> V_101 == V_199 )
goto V_184;
if ( V_17 < 1 )
goto V_184;
if ( V_25 == - 1 )
V_25 = 1 ;
if ( V_25 < 0 || V_25 > 255 )
goto V_184;
V_54 -> V_211 = V_25 ;
break;
case V_177 :
if ( V_17 < 1 )
goto V_184;
V_54 -> V_212 = ! ! V_25 ;
break;
case V_174 :
{
struct V_213 * V_214 = NULL ;
int V_215 ;
if ( V_17 != sizeof( int ) )
goto V_184;
V_215 = ( V_216 int ) F_92 ( ( V_216 T_5 ) V_25 ) ;
if ( V_215 == 0 ) {
V_54 -> V_217 = 0 ;
V_38 = 0 ;
break;
}
V_214 = F_93 ( F_26 ( V_52 ) , V_215 ) ;
V_38 = - V_218 ;
if ( ! V_214 )
break;
F_94 ( V_214 ) ;
V_38 = - V_72 ;
if ( V_52 -> V_219 )
break;
V_54 -> V_217 = V_215 ;
V_38 = 0 ;
break;
}
case V_220 :
{
struct V_221 V_222 ;
struct V_213 * V_214 = NULL ;
int V_223 ;
if ( V_52 -> V_101 == V_199 )
goto V_184;
if ( V_17 < sizeof( struct V_224 ) )
goto V_184;
V_38 = - V_179 ;
if ( V_17 >= sizeof( struct V_221 ) ) {
if ( F_95 ( & V_222 , V_162 , sizeof( V_222 ) ) )
break;
} else {
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
if ( V_17 >= sizeof( struct V_225 ) ) {
if ( F_95 ( & V_222 , V_162 ,
sizeof( struct V_225 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_224 ) ) {
if ( F_95 ( & V_222 . V_226 , V_162 ,
sizeof( struct V_224 ) ) )
break;
}
}
if ( ! V_222 . V_227 ) {
if ( V_222 . V_226 . V_8 == F_96 ( V_228 ) ) {
V_54 -> V_229 = 0 ;
V_54 -> V_230 = 0 ;
V_38 = 0 ;
break;
}
V_214 = F_97 ( F_26 ( V_52 ) , V_222 . V_226 . V_8 ) ;
if ( V_214 )
V_222 . V_227 = V_214 -> V_215 ;
} else
V_214 = F_93 ( F_26 ( V_52 ) , V_222 . V_227 ) ;
V_38 = - V_218 ;
if ( ! V_214 )
break;
V_223 = F_98 ( V_214 ) ;
F_94 ( V_214 ) ;
V_38 = - V_72 ;
if ( V_52 -> V_219 &&
V_222 . V_227 != V_52 -> V_219 &&
( ! V_223 || V_223 != V_52 -> V_219 ) )
break;
V_54 -> V_229 = V_222 . V_227 ;
V_54 -> V_230 = V_222 . V_226 . V_8 ;
V_38 = 0 ;
break;
}
case V_146 :
case V_149 :
{
struct V_221 V_222 ;
V_38 = - V_231 ;
if ( F_24 ( V_52 ) -> V_186 )
break;
if ( V_17 < sizeof( struct V_225 ) )
goto V_184;
V_38 = - V_179 ;
if ( V_17 >= sizeof( struct V_221 ) ) {
if ( F_95 ( & V_222 , V_162 , sizeof( V_222 ) ) )
break;
} else {
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
if ( F_95 ( & V_222 , V_162 , sizeof( struct V_225 ) ) )
break;
}
if ( V_145 == V_146 )
V_38 = F_99 ( V_52 , & V_222 ) ;
else
V_38 = F_100 ( V_52 , & V_222 ) ;
break;
}
case V_151 :
{
struct V_232 * V_233 ;
if ( V_17 < F_101 ( 0 ) )
goto V_184;
if ( V_17 > V_234 ) {
V_38 = - V_109 ;
break;
}
V_233 = F_42 ( V_17 , V_105 ) ;
if ( ! V_233 ) {
V_38 = - V_109 ;
break;
}
V_38 = - V_179 ;
if ( F_95 ( V_233 , V_162 , V_17 ) ) {
F_39 ( V_233 ) ;
break;
}
if ( V_233 -> V_235 >= 0x3ffffffcU ||
V_233 -> V_235 > V_71 -> V_236 . V_237 ) {
F_39 ( V_233 ) ;
V_38 = - V_109 ;
break;
}
if ( F_101 ( V_233 -> V_235 ) > V_17 ) {
F_39 ( V_233 ) ;
V_38 = - V_72 ;
break;
}
V_38 = F_102 ( V_52 , V_233 , 0 ) ;
F_39 ( V_233 ) ;
break;
}
case V_148 :
case V_152 :
case V_147 :
case V_150 :
{
struct V_238 V_239 ;
int V_240 , V_241 ;
if ( V_17 != sizeof( struct V_238 ) )
goto V_184;
if ( F_95 ( & V_239 , V_162 , sizeof( V_239 ) ) ) {
V_38 = - V_179 ;
break;
}
if ( V_145 == V_148 ) {
V_240 = V_242 ;
V_241 = 1 ;
} else if ( V_145 == V_152 ) {
V_240 = V_242 ;
V_241 = 0 ;
} else if ( V_145 == V_147 ) {
struct V_221 V_222 ;
V_222 . V_243 . V_8 = V_239 . V_243 ;
V_222 . V_226 . V_8 = V_239 . V_244 ;
V_222 . V_227 = 0 ;
V_38 = F_99 ( V_52 , & V_222 ) ;
if ( V_38 && V_38 != - V_108 )
break;
V_240 = V_245 ;
V_241 = 1 ;
} else {
V_240 = V_245 ;
V_241 = 0 ;
}
V_38 = F_103 ( V_241 , V_240 , V_52 , & V_239 , 0 ) ;
break;
}
case V_155 :
case V_157 :
{
struct V_246 V_247 ;
struct V_40 * V_248 ;
struct V_221 V_222 ;
if ( V_17 < sizeof( struct V_246 ) )
goto V_184;
V_38 = - V_179 ;
if ( F_95 ( & V_247 , V_162 , sizeof( V_247 ) ) )
break;
V_248 = (struct V_40 * ) & V_247 . V_249 ;
if ( V_248 -> V_45 != V_46 )
goto V_184;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_222 . V_243 = V_248 -> V_47 ;
V_222 . V_227 = V_247 . V_250 ;
if ( V_145 == V_155 )
V_38 = F_99 ( V_52 , & V_222 ) ;
else
V_38 = F_100 ( V_52 , & V_222 ) ;
break;
}
case V_156 :
case V_158 :
case V_153 :
case V_159 :
{
struct V_251 V_252 ;
struct V_238 V_239 ;
struct V_40 * V_248 ;
int V_240 , V_241 ;
if ( V_17 != sizeof( struct V_251 ) )
goto V_184;
if ( F_95 ( & V_252 , V_162 , sizeof( V_252 ) ) ) {
V_38 = - V_179 ;
break;
}
if ( V_252 . V_253 . V_254 != V_46 ||
V_252 . V_255 . V_254 != V_46 ) {
V_38 = - V_218 ;
break;
}
V_248 = (struct V_40 * ) & V_252 . V_253 ;
V_239 . V_243 = V_248 -> V_47 . V_8 ;
V_248 = (struct V_40 * ) & V_252 . V_255 ;
V_239 . V_256 = V_248 -> V_47 . V_8 ;
V_239 . V_244 = 0 ;
if ( V_145 == V_153 ) {
V_240 = V_242 ;
V_241 = 1 ;
} else if ( V_145 == V_159 ) {
V_240 = V_242 ;
V_241 = 0 ;
} else if ( V_145 == V_156 ) {
struct V_221 V_222 ;
V_248 = (struct V_40 * ) & V_252 . V_253 ;
V_222 . V_243 = V_248 -> V_47 ;
V_222 . V_226 . V_8 = 0 ;
V_222 . V_227 = V_252 . V_257 ;
V_38 = F_99 ( V_52 , & V_222 ) ;
if ( V_38 && V_38 != - V_108 )
break;
V_252 . V_257 = V_222 . V_227 ;
V_240 = V_245 ;
V_241 = 1 ;
} else {
V_240 = V_245 ;
V_241 = 0 ;
}
V_38 = F_103 ( V_241 , V_240 , V_52 , & V_239 ,
V_252 . V_257 ) ;
break;
}
case V_154 :
{
struct V_40 * V_248 ;
struct V_232 * V_233 = NULL ;
struct V_258 * V_259 = NULL ;
int V_260 , V_261 , V_215 ;
if ( V_17 < F_104 ( 0 ) )
goto V_184;
if ( V_17 > V_234 ) {
V_38 = - V_109 ;
break;
}
V_259 = F_42 ( V_17 , V_105 ) ;
if ( ! V_259 ) {
V_38 = - V_109 ;
break;
}
V_38 = - V_179 ;
if ( F_95 ( V_259 , V_162 , V_17 ) )
goto V_262;
if ( V_259 -> V_263 >= 0x1ffffff ||
V_259 -> V_263 > V_71 -> V_236 . V_237 ) {
V_38 = - V_109 ;
goto V_262;
}
if ( F_104 ( V_259 -> V_263 ) > V_17 ) {
V_38 = - V_72 ;
goto V_262;
}
V_260 = F_101 ( V_259 -> V_263 ) ;
V_233 = F_42 ( V_260 , V_105 ) ;
if ( ! V_233 ) {
V_38 = - V_109 ;
goto V_262;
}
V_215 = V_259 -> V_264 ;
V_248 = (struct V_40 * ) & V_259 -> V_265 ;
if ( V_248 -> V_45 != V_46 ) {
V_38 = - V_218 ;
goto V_262;
}
V_233 -> V_266 = V_248 -> V_47 . V_8 ;
V_233 -> V_267 = 0 ;
V_233 -> V_268 = V_259 -> V_269 ;
V_233 -> V_235 = V_259 -> V_263 ;
V_38 = - V_218 ;
for ( V_261 = 0 ; V_261 < V_259 -> V_263 ; ++ V_261 ) {
V_248 = (struct V_40 * ) & V_259 -> V_270 [ V_261 ] ;
if ( V_248 -> V_45 != V_46 )
goto V_262;
V_233 -> V_271 [ V_261 ] = V_248 -> V_47 . V_8 ;
}
F_39 ( V_259 ) ;
V_259 = NULL ;
V_38 = F_102 ( V_52 , V_233 , V_215 ) ;
V_262:
F_39 ( V_233 ) ;
F_39 ( V_259 ) ;
break;
}
case V_176 :
if ( V_17 < 1 )
goto V_184;
if ( V_25 != 0 && V_25 != 1 )
goto V_184;
V_54 -> V_272 = V_25 ;
break;
case V_160 :
V_38 = F_40 ( V_52 , V_25 ? 1 : 0 , NULL ) ;
break;
case V_168 :
if ( V_17 < 1 )
goto V_184;
V_54 -> V_273 = ! ! V_25 ;
break;
case V_274 :
case V_275 :
V_38 = - V_276 ;
if ( ! F_105 ( F_26 ( V_52 ) -> V_277 , V_278 ) )
break;
V_38 = F_106 ( V_52 , V_145 , V_162 , V_17 ) ;
break;
case V_170 :
if ( ! ! V_25 && ! F_105 ( F_26 ( V_52 ) -> V_277 , V_279 ) &&
! F_105 ( F_26 ( V_52 ) -> V_277 , V_278 ) ) {
V_38 = - V_276 ;
break;
}
if ( V_17 < 1 )
goto V_184;
V_54 -> V_280 = ! ! V_25 ;
break;
case V_171 :
if ( V_17 < 1 )
goto V_184;
if ( V_25 < 0 || V_25 > 255 )
goto V_184;
V_54 -> V_281 = V_25 ;
break;
default:
V_38 = - V_203 ;
break;
}
F_107 ( V_52 ) ;
if ( V_163 )
F_108 () ;
return V_38 ;
V_184:
F_107 ( V_52 ) ;
if ( V_163 )
F_108 () ;
return - V_72 ;
}
void F_109 ( const struct V_51 * V_52 , struct V_3 * V_4 )
{
struct V_5 * V_282 = F_2 ( V_4 ) ;
bool V_283 = ( F_24 ( V_52 ) -> V_56 & V_57 ) ||
F_110 ( V_52 ) ;
if ( V_283 && F_111 ( V_4 ) ) {
if ( V_282 -> V_88 == V_284 )
V_282 -> V_88 = F_112 ( V_4 ) ;
V_282 -> V_89 . V_8 = F_113 ( V_4 ) ;
} else {
V_282 -> V_88 = 0 ;
V_282 -> V_89 . V_8 = 0 ;
}
if ( F_73 ( F_8 ( V_4 ) -> V_16 . V_17 ) )
F_114 ( V_4 ) ;
else
F_115 ( V_4 ) ;
}
int F_116 ( struct V_51 * V_52 , int V_161 ,
int V_145 , char T_6 * V_162 , unsigned int V_17 )
{
int V_38 ;
if ( V_161 != V_10 )
return - V_203 ;
V_38 = F_78 ( V_52 , V_161 , V_145 , V_162 , V_17 ) ;
#ifdef F_117
if ( V_38 == - V_203 && V_145 != V_166 &&
V_145 != V_274 &&
V_145 != V_275 &&
! F_80 ( V_145 ) ) {
F_83 ( V_52 ) ;
V_38 = F_118 ( V_52 , V_189 , V_145 , V_162 , V_17 ) ;
F_107 ( V_52 ) ;
}
#endif
return V_38 ;
}
int F_119 ( struct V_51 * V_52 , int V_161 , int V_145 ,
char T_6 * V_162 , unsigned int V_17 )
{
int V_38 ;
if ( V_161 != V_10 )
return - V_203 ;
if ( V_145 >= V_155 && V_145 <= V_154 )
return F_120 ( V_52 , V_161 , V_145 , V_162 , V_17 ,
F_116 ) ;
V_38 = F_78 ( V_52 , V_161 , V_145 , V_162 , V_17 ) ;
#ifdef F_117
if ( V_38 == - V_203 && V_145 != V_166 &&
V_145 != V_274 &&
V_145 != V_275 &&
! F_80 ( V_145 ) ) {
F_83 ( V_52 ) ;
V_38 = F_121 ( V_52 , V_189 , V_145 ,
V_162 , V_17 ) ;
F_107 ( V_52 ) ;
}
#endif
return V_38 ;
}
static bool F_122 ( int V_145 )
{
switch ( V_145 ) {
case V_151 :
case V_154 :
return true ;
}
return false ;
}
static int F_123 ( struct V_51 * V_52 , int V_161 , int V_145 ,
char T_6 * V_162 , int T_6 * V_17 , unsigned int V_55 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
bool V_163 = F_122 ( V_145 ) ;
int V_25 , V_38 = 0 ;
int V_44 ;
if ( V_161 != V_10 )
return - V_285 ;
if ( F_80 ( V_145 ) )
return F_124 ( V_52 , V_145 , V_162 , V_17 ) ;
if ( F_79 ( V_44 , V_17 ) )
return - V_179 ;
if ( V_44 < 0 )
return - V_72 ;
if ( V_163 )
F_82 () ;
F_83 ( V_52 ) ;
switch ( V_145 ) {
case V_181 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_182 * V_185 ;
V_185 = F_44 ( V_54 -> V_185 ,
F_85 ( V_52 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_185 )
memcpy ( V_19 , & V_185 -> V_16 ,
sizeof( struct V_20 ) +
V_185 -> V_16 . V_17 ) ;
F_107 ( V_52 ) ;
if ( V_16 -> V_17 == 0 )
return F_125 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_44 = F_126 (unsigned int, len, opt->optlen) ;
if ( F_125 ( V_44 , V_17 ) )
return - V_179 ;
if ( F_127 ( V_162 , V_16 -> V_24 , V_44 ) )
return - V_179 ;
return 0 ;
}
case V_11 :
V_25 = ( V_54 -> V_56 & V_57 ) != 0 ;
break;
case V_164 :
V_25 = ( V_54 -> V_56 & V_58 ) != 0 ;
break;
case V_165 :
V_25 = ( V_54 -> V_56 & V_59 ) != 0 ;
break;
case V_18 :
V_25 = ( V_54 -> V_56 & V_60 ) != 0 ;
break;
case V_23 :
V_25 = ( V_54 -> V_56 & V_61 ) != 0 ;
break;
case V_169 :
V_25 = ( V_54 -> V_56 & V_62 ) != 0 ;
break;
case V_178 :
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
V_25 = ( V_54 -> V_202 == - 1 ?
V_71 -> V_236 . V_286 :
V_54 -> V_202 ) ;
break;
}
case V_166 :
V_25 = V_54 -> V_204 ;
break;
case V_172 :
V_25 = V_54 -> V_205 ;
break;
case V_173 :
V_25 = V_54 -> V_206 ;
break;
case V_167 :
V_25 = V_54 -> V_209 ;
break;
case V_287 :
{
struct V_288 * V_289 ;
V_25 = 0 ;
V_289 = F_128 ( V_52 ) ;
if ( V_289 ) {
V_25 = F_129 ( V_289 ) ;
F_130 ( V_289 ) ;
}
if ( ! V_25 ) {
F_107 ( V_52 ) ;
return - V_290 ;
}
break;
}
case V_143 :
V_25 = V_54 -> V_127 ;
break;
case V_175 :
V_25 = V_54 -> V_211 ;
break;
case V_177 :
V_25 = V_54 -> V_212 ;
break;
case V_174 :
V_25 = ( V_216 int ) F_96 ( ( V_291 ) V_54 -> V_217 ) ;
break;
case V_220 :
{
struct V_224 V_84 ;
V_44 = F_126 (unsigned int, len, sizeof(struct in_addr)) ;
V_84 . V_8 = V_54 -> V_230 ;
F_107 ( V_52 ) ;
if ( F_125 ( V_44 , V_17 ) )
return - V_179 ;
if ( F_127 ( V_162 , & V_84 , V_44 ) )
return - V_179 ;
return 0 ;
}
case V_151 :
{
struct V_232 V_233 ;
if ( V_44 < F_101 ( 0 ) ) {
V_38 = - V_72 ;
goto V_141;
}
if ( F_95 ( & V_233 , V_162 , F_101 ( 0 ) ) ) {
V_38 = - V_179 ;
goto V_141;
}
V_38 = F_131 ( V_52 , & V_233 ,
(struct V_232 T_6 * ) V_162 , V_17 ) ;
goto V_141;
}
case V_154 :
{
struct V_258 V_259 ;
if ( V_44 < F_104 ( 0 ) ) {
V_38 = - V_72 ;
goto V_141;
}
if ( F_95 ( & V_259 , V_162 , F_104 ( 0 ) ) ) {
V_38 = - V_179 ;
goto V_141;
}
V_38 = F_132 ( V_52 , & V_259 ,
(struct V_258 T_6 * ) V_162 ,
V_17 ) ;
goto V_141;
}
case V_176 :
V_25 = V_54 -> V_272 ;
break;
case V_292 :
{
struct V_1 V_2 ;
F_107 ( V_52 ) ;
if ( V_52 -> V_101 != V_199 )
return - V_203 ;
V_2 . V_293 = ( V_216 void * ) V_162 ;
V_2 . V_294 = V_44 ;
V_2 . V_21 = V_55 ;
if ( V_54 -> V_56 & V_57 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_54 -> V_295 ;
V_6 . V_89 . V_8 = V_54 -> V_295 ;
V_6 . V_88 = V_54 -> V_229 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_54 -> V_56 & V_58 ) {
int V_296 = V_54 -> V_211 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_296 ) , & V_296 ) ;
}
if ( V_54 -> V_56 & V_59 ) {
int V_15 = V_54 -> V_297 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_44 -= V_2 . V_294 ;
return F_125 ( V_44 , V_17 ) ;
}
case V_168 :
V_25 = V_54 -> V_273 ;
break;
case V_170 :
V_25 = V_54 -> V_280 ;
break;
case V_171 :
V_25 = V_54 -> V_281 ;
break;
default:
F_107 ( V_52 ) ;
return - V_203 ;
}
F_107 ( V_52 ) ;
if ( V_44 < sizeof( int ) && V_44 > 0 && V_25 >= 0 && V_25 <= 255 ) {
unsigned char V_180 = ( unsigned char ) V_25 ;
V_44 = 1 ;
if ( F_125 ( V_44 , V_17 ) )
return - V_179 ;
if ( F_127 ( V_162 , & V_180 , 1 ) )
return - V_179 ;
} else {
V_44 = F_126 (unsigned int, sizeof(int), len) ;
if ( F_125 ( V_44 , V_17 ) )
return - V_179 ;
if ( F_127 ( V_162 , & V_25 , V_44 ) )
return - V_179 ;
}
return 0 ;
V_141:
F_107 ( V_52 ) ;
if ( V_163 )
F_108 () ;
return V_38 ;
}
int F_133 ( struct V_51 * V_52 , int V_161 ,
int V_145 , char T_6 * V_162 , int T_6 * V_17 )
{
int V_38 ;
V_38 = F_123 ( V_52 , V_161 , V_145 , V_162 , V_17 , 0 ) ;
#ifdef F_117
if ( V_38 == - V_203 && V_145 != V_292 &&
! F_80 ( V_145 ) ) {
int V_44 ;
if ( F_79 ( V_44 , V_17 ) )
return - V_179 ;
F_83 ( V_52 ) ;
V_38 = F_134 ( V_52 , V_189 , V_145 , V_162 ,
& V_44 ) ;
F_107 ( V_52 ) ;
if ( V_38 >= 0 )
V_38 = F_125 ( V_44 , V_17 ) ;
return V_38 ;
}
#endif
return V_38 ;
}
int F_135 ( struct V_51 * V_52 , int V_161 , int V_145 ,
char T_6 * V_162 , int T_6 * V_17 )
{
int V_38 ;
if ( V_145 == V_154 )
return F_136 ( V_52 , V_161 , V_145 , V_162 , V_17 ,
F_133 ) ;
V_38 = F_123 ( V_52 , V_161 , V_145 , V_162 , V_17 ,
V_298 ) ;
#ifdef F_117
if ( V_38 == - V_203 && V_145 != V_292 &&
! F_80 ( V_145 ) ) {
int V_44 ;
if ( F_79 ( V_44 , V_17 ) )
return - V_179 ;
F_83 ( V_52 ) ;
V_38 = F_137 ( V_52 , V_189 , V_145 , V_162 , & V_44 ) ;
F_107 ( V_52 ) ;
if ( V_38 >= 0 )
V_38 = F_125 ( V_44 , V_17 ) ;
return V_38 ;
}
#endif
return V_38 ;
}
