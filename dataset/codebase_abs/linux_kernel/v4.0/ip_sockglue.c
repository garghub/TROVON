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
if ( V_92 == NULL ) {
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
if ( F_54 ( V_4 , V_104 - V_4 -> V_29 ) != NULL ) {
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
if ( V_4 == NULL )
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
static int F_72 ( struct V_90 * V_49 , int V_140 ,
int V_141 , char T_7 * V_142 , unsigned int V_17 )
{
struct V_47 * V_48 = F_23 ( V_49 ) ;
int V_64 = 0 , V_34 ;
switch ( V_141 ) {
case V_11 :
case V_143 :
case V_18 :
case V_144 :
case V_23 :
case V_14 :
case V_13 :
case V_145 :
case V_146 :
case V_138 :
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
case V_30 :
if ( V_17 >= sizeof( int ) ) {
if ( F_73 ( V_64 , ( int T_7 * ) V_142 ) )
return - V_158 ;
} else if ( V_17 >= sizeof( char ) ) {
unsigned char V_159 ;
if ( F_73 ( V_159 , ( unsigned char T_7 * ) V_142 ) )
return - V_158 ;
V_64 = ( int ) V_159 ;
}
}
if ( F_74 ( V_141 ) )
return F_75 ( V_49 , V_141 , V_142 , V_17 ) ;
V_34 = 0 ;
F_76 ( V_49 ) ;
switch ( V_141 ) {
case V_160 :
{
struct V_161 * V_162 , * V_16 = NULL ;
if ( V_17 > 40 )
goto V_163;
V_34 = F_77 ( F_78 ( V_49 ) , & V_16 ,
V_142 , V_17 ) ;
if ( V_34 )
break;
V_162 = F_42 ( V_48 -> V_164 ,
F_79 ( V_49 ) ) ;
if ( V_48 -> V_165 ) {
struct V_166 * V_167 = F_80 ( V_49 ) ;
#if F_27 ( V_68 )
if ( V_49 -> V_132 == V_168 ||
( ! ( ( 1 << V_49 -> V_169 ) &
( V_170 | V_171 ) ) &&
V_48 -> V_172 != V_173 ) ) {
#endif
if ( V_162 )
V_167 -> V_174 -= V_162 -> V_16 . V_17 ;
if ( V_16 )
V_167 -> V_174 += V_16 -> V_16 . V_17 ;
V_167 -> V_175 ( V_49 , V_167 -> V_176 ) ;
#if F_27 ( V_68 )
}
#endif
}
F_47 ( V_48 -> V_164 , V_16 ) ;
if ( V_162 )
F_81 ( V_162 , V_88 ) ;
break;
}
case V_11 :
if ( V_64 )
V_48 -> V_51 |= V_52 ;
else
V_48 -> V_51 &= ~ V_52 ;
break;
case V_143 :
if ( V_64 )
V_48 -> V_51 |= V_53 ;
else
V_48 -> V_51 &= ~ V_53 ;
break;
case V_144 :
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
case V_149 :
if ( V_64 )
V_48 -> V_51 |= V_57 ;
else
V_48 -> V_51 &= ~ V_57 ;
break;
case V_157 :
if ( V_64 )
V_48 -> V_51 |= V_58 ;
else
V_48 -> V_51 &= ~ V_58 ;
break;
case V_30 :
if ( V_64 ) {
if ( ! ( V_48 -> V_51 & V_59 ) ) {
F_82 ( V_49 ) ;
V_48 -> V_51 |= V_59 ;
}
} else {
if ( V_48 -> V_51 & V_59 ) {
F_83 ( V_49 ) ;
V_48 -> V_51 &= ~ V_59 ;
}
}
break;
case V_14 :
if ( V_49 -> V_94 == V_177 ) {
V_64 &= ~ V_178 ;
V_64 |= V_48 -> V_15 & V_178 ;
}
if ( V_48 -> V_15 != V_64 ) {
V_48 -> V_15 = V_64 ;
V_49 -> V_179 = F_33 ( V_64 ) ;
F_84 ( V_49 ) ;
}
break;
case V_13 :
if ( V_17 < 1 )
goto V_163;
if ( V_64 != - 1 && ( V_64 < 1 || V_64 > 255 ) )
goto V_163;
V_48 -> V_180 = V_64 ;
break;
case V_145 :
if ( V_49 -> V_94 != V_95 ) {
V_34 = - V_181 ;
break;
}
V_48 -> V_182 = V_64 ? 1 : 0 ;
break;
case V_152 :
if ( V_49 -> V_94 != V_95 ) {
V_34 = - V_181 ;
break;
}
V_48 -> V_183 = V_64 ? 1 : 0 ;
break;
case V_146 :
if ( V_64 < V_184 || V_64 > V_185 )
goto V_163;
V_48 -> V_186 = V_64 ;
break;
case V_138 :
V_48 -> V_119 = ! ! V_64 ;
if ( ! V_64 )
F_85 ( & V_49 -> V_187 ) ;
break;
case V_154 :
if ( V_49 -> V_94 == V_177 )
goto V_163;
if ( V_17 < 1 )
goto V_163;
if ( V_64 == - 1 )
V_64 = 1 ;
if ( V_64 < 0 || V_64 > 255 )
goto V_163;
V_48 -> V_188 = V_64 ;
break;
case V_156 :
if ( V_17 < 1 )
goto V_163;
V_48 -> V_189 = ! ! V_64 ;
break;
case V_153 :
{
struct V_190 * V_123 = NULL ;
int V_125 ;
if ( V_17 != sizeof( int ) )
goto V_163;
V_125 = ( V_191 int ) F_86 ( ( V_191 T_6 ) V_64 ) ;
if ( V_125 == 0 ) {
V_48 -> V_192 = 0 ;
V_34 = 0 ;
break;
}
V_123 = F_87 ( F_78 ( V_49 ) , V_125 ) ;
V_34 = - V_193 ;
if ( ! V_123 )
break;
F_88 ( V_123 ) ;
V_34 = - V_67 ;
if ( V_49 -> V_194 )
break;
V_48 -> V_192 = V_125 ;
V_34 = 0 ;
break;
}
case V_195 :
{
struct V_196 V_197 ;
struct V_190 * V_123 = NULL ;
if ( V_49 -> V_94 == V_177 )
goto V_163;
if ( V_17 < sizeof( struct V_198 ) )
goto V_163;
V_34 = - V_158 ;
if ( V_17 >= sizeof( struct V_196 ) ) {
if ( F_89 ( & V_197 , V_142 , sizeof( V_197 ) ) )
break;
} else {
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
if ( V_17 >= sizeof( struct V_199 ) ) {
if ( F_89 ( & V_197 , V_142 ,
sizeof( struct V_199 ) ) )
break;
} else if ( V_17 >= sizeof( struct V_198 ) ) {
if ( F_89 ( & V_197 . V_200 , V_142 ,
sizeof( struct V_198 ) ) )
break;
}
}
if ( ! V_197 . V_201 ) {
if ( V_197 . V_200 . V_8 == F_90 ( V_202 ) ) {
V_48 -> V_203 = 0 ;
V_48 -> V_204 = 0 ;
V_34 = 0 ;
break;
}
V_123 = F_91 ( F_78 ( V_49 ) , V_197 . V_200 . V_8 ) ;
if ( V_123 )
V_197 . V_201 = V_123 -> V_125 ;
} else
V_123 = F_87 ( F_78 ( V_49 ) , V_197 . V_201 ) ;
V_34 = - V_193 ;
if ( ! V_123 )
break;
F_88 ( V_123 ) ;
V_34 = - V_67 ;
if ( V_49 -> V_194 &&
V_197 . V_201 != V_49 -> V_194 )
break;
V_48 -> V_203 = V_197 . V_201 ;
V_48 -> V_204 = V_197 . V_200 . V_8 ;
V_34 = 0 ;
break;
}
case V_205 :
case V_206 :
{
struct V_196 V_197 ;
V_34 = - V_207 ;
if ( F_23 ( V_49 ) -> V_165 )
break;
if ( V_17 < sizeof( struct V_199 ) )
goto V_163;
V_34 = - V_158 ;
if ( V_17 >= sizeof( struct V_196 ) ) {
if ( F_89 ( & V_197 , V_142 , sizeof( V_197 ) ) )
break;
} else {
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
if ( F_89 ( & V_197 , V_142 , sizeof( struct V_199 ) ) )
break;
}
if ( V_141 == V_205 )
V_34 = F_92 ( V_49 , & V_197 ) ;
else
V_34 = F_93 ( V_49 , & V_197 ) ;
break;
}
case V_208 :
{
struct V_209 * V_210 ;
if ( V_17 < F_94 ( 0 ) )
goto V_163;
if ( V_17 > V_211 ) {
V_34 = - V_102 ;
break;
}
V_210 = F_40 ( V_17 , V_98 ) ;
if ( ! V_210 ) {
V_34 = - V_102 ;
break;
}
V_34 = - V_158 ;
if ( F_89 ( V_210 , V_142 , V_17 ) ) {
F_37 ( V_210 ) ;
break;
}
if ( V_210 -> V_212 >= 0x3ffffffcU ||
V_210 -> V_212 > V_213 ) {
F_37 ( V_210 ) ;
V_34 = - V_102 ;
break;
}
if ( F_94 ( V_210 -> V_212 ) > V_17 ) {
F_37 ( V_210 ) ;
V_34 = - V_67 ;
break;
}
V_34 = F_95 ( V_49 , V_210 , 0 ) ;
F_37 ( V_210 ) ;
break;
}
case V_214 :
case V_215 :
case V_216 :
case V_217 :
{
struct V_218 V_219 ;
int V_220 , V_221 ;
if ( V_17 != sizeof( struct V_218 ) )
goto V_163;
if ( F_89 ( & V_219 , V_142 , sizeof( V_219 ) ) ) {
V_34 = - V_158 ;
break;
}
if ( V_141 == V_214 ) {
V_220 = V_222 ;
V_221 = 1 ;
} else if ( V_141 == V_215 ) {
V_220 = V_222 ;
V_221 = 0 ;
} else if ( V_141 == V_216 ) {
struct V_196 V_197 ;
V_197 . V_223 . V_8 = V_219 . V_223 ;
V_197 . V_200 . V_8 = V_219 . V_224 ;
V_197 . V_201 = 0 ;
V_34 = F_92 ( V_49 , & V_197 ) ;
if ( V_34 && V_34 != - V_101 )
break;
V_220 = V_225 ;
V_221 = 1 ;
} else {
V_220 = V_225 ;
V_221 = 0 ;
}
V_34 = F_96 ( V_221 , V_220 , V_49 , & V_219 , 0 ) ;
break;
}
case V_226 :
case V_227 :
{
struct V_228 V_229 ;
struct V_36 * V_230 ;
struct V_196 V_197 ;
if ( V_17 < sizeof( struct V_228 ) )
goto V_163;
V_34 = - V_158 ;
if ( F_89 ( & V_229 , V_142 , sizeof( V_229 ) ) )
break;
V_230 = (struct V_36 * ) & V_229 . V_231 ;
if ( V_230 -> V_41 != V_42 )
goto V_163;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_223 = V_230 -> V_43 ;
V_197 . V_201 = V_229 . V_232 ;
if ( V_141 == V_226 )
V_34 = F_92 ( V_49 , & V_197 ) ;
else
V_34 = F_93 ( V_49 , & V_197 ) ;
break;
}
case V_233 :
case V_234 :
case V_235 :
case V_236 :
{
struct V_237 V_238 ;
struct V_218 V_219 ;
struct V_36 * V_230 ;
int V_220 , V_221 ;
if ( V_17 != sizeof( struct V_237 ) )
goto V_163;
if ( F_89 ( & V_238 , V_142 , sizeof( V_238 ) ) ) {
V_34 = - V_158 ;
break;
}
if ( V_238 . V_239 . V_240 != V_42 ||
V_238 . V_241 . V_240 != V_42 ) {
V_34 = - V_193 ;
break;
}
V_230 = (struct V_36 * ) & V_238 . V_239 ;
V_219 . V_223 = V_230 -> V_43 . V_8 ;
V_230 = (struct V_36 * ) & V_238 . V_241 ;
V_219 . V_242 = V_230 -> V_43 . V_8 ;
V_219 . V_224 = 0 ;
if ( V_141 == V_235 ) {
V_220 = V_222 ;
V_221 = 1 ;
} else if ( V_141 == V_236 ) {
V_220 = V_222 ;
V_221 = 0 ;
} else if ( V_141 == V_233 ) {
struct V_196 V_197 ;
V_230 = (struct V_36 * ) & V_238 . V_239 ;
V_197 . V_223 = V_230 -> V_43 ;
V_197 . V_200 . V_8 = 0 ;
V_197 . V_201 = V_238 . V_243 ;
V_34 = F_92 ( V_49 , & V_197 ) ;
if ( V_34 && V_34 != - V_101 )
break;
V_238 . V_243 = V_197 . V_201 ;
V_220 = V_225 ;
V_221 = 1 ;
} else {
V_220 = V_225 ;
V_221 = 0 ;
}
V_34 = F_96 ( V_221 , V_220 , V_49 , & V_219 ,
V_238 . V_243 ) ;
break;
}
case V_244 :
{
struct V_36 * V_230 ;
struct V_209 * V_210 = NULL ;
struct V_245 * V_246 = NULL ;
int V_247 , V_248 , V_125 ;
if ( V_17 < F_97 ( 0 ) )
goto V_163;
if ( V_17 > V_211 ) {
V_34 = - V_102 ;
break;
}
V_246 = F_40 ( V_17 , V_98 ) ;
if ( ! V_246 ) {
V_34 = - V_102 ;
break;
}
V_34 = - V_158 ;
if ( F_89 ( V_246 , V_142 , V_17 ) )
goto V_249;
if ( V_246 -> V_250 >= 0x1ffffff ||
V_246 -> V_250 > V_213 ) {
V_34 = - V_102 ;
goto V_249;
}
if ( F_97 ( V_246 -> V_250 ) > V_17 ) {
V_34 = - V_67 ;
goto V_249;
}
V_247 = F_94 ( V_246 -> V_250 ) ;
V_210 = F_40 ( V_247 , V_98 ) ;
if ( ! V_210 ) {
V_34 = - V_102 ;
goto V_249;
}
V_125 = V_246 -> V_251 ;
V_230 = (struct V_36 * ) & V_246 -> V_252 ;
if ( V_230 -> V_41 != V_42 ) {
V_34 = - V_193 ;
goto V_249;
}
V_210 -> V_253 = V_230 -> V_43 . V_8 ;
V_210 -> V_254 = 0 ;
V_210 -> V_255 = V_246 -> V_256 ;
V_210 -> V_212 = V_246 -> V_250 ;
V_34 = - V_193 ;
for ( V_248 = 0 ; V_248 < V_246 -> V_250 ; ++ V_248 ) {
V_230 = (struct V_36 * ) & V_246 -> V_257 [ V_248 ] ;
if ( V_230 -> V_41 != V_42 )
goto V_249;
V_210 -> V_258 [ V_248 ] = V_230 -> V_43 . V_8 ;
}
F_37 ( V_246 ) ;
V_246 = NULL ;
V_34 = F_95 ( V_49 , V_210 , V_125 ) ;
V_249:
F_37 ( V_210 ) ;
F_37 ( V_246 ) ;
break;
}
case V_155 :
if ( V_17 < 1 )
goto V_163;
if ( V_64 != 0 && V_64 != 1 )
goto V_163;
V_48 -> V_259 = V_64 ;
break;
case V_147 :
V_34 = F_38 ( V_49 , V_64 ? 1 : 0 , NULL ) ;
break;
case V_148 :
if ( V_17 < 1 )
goto V_163;
V_48 -> V_260 = ! ! V_64 ;
break;
case V_261 :
case V_262 :
V_34 = - V_263 ;
if ( ! F_98 ( F_78 ( V_49 ) -> V_264 , V_265 ) )
break;
V_34 = F_99 ( V_49 , V_141 , V_142 , V_17 ) ;
break;
case V_150 :
if ( ! ! V_64 && ! F_98 ( F_78 ( V_49 ) -> V_264 , V_266 ) &&
! F_98 ( F_78 ( V_49 ) -> V_264 , V_265 ) ) {
V_34 = - V_263 ;
break;
}
if ( V_17 < 1 )
goto V_163;
V_48 -> V_267 = ! ! V_64 ;
break;
case V_151 :
if ( V_17 < 1 )
goto V_163;
if ( V_64 < 0 || V_64 > 255 )
goto V_163;
V_48 -> V_268 = V_64 ;
break;
default:
V_34 = - V_181 ;
break;
}
F_100 ( V_49 ) ;
return V_34 ;
V_163:
F_100 ( V_49 ) ;
return - V_67 ;
}
void F_101 ( const struct V_90 * V_49 , struct V_3 * V_4 )
{
struct V_5 * V_269 = F_2 ( V_4 ) ;
bool V_270 = ( F_23 ( V_49 ) -> V_51 & V_52 ) ||
F_102 ( V_49 ) ;
if ( V_270 && F_103 ( V_4 ) ) {
V_269 -> V_81 = F_104 ( V_4 ) ;
V_269 -> V_82 . V_8 = F_105 ( V_4 ) ;
} else {
V_269 -> V_81 = 0 ;
V_269 -> V_82 . V_8 = 0 ;
}
F_106 ( V_4 ) ;
}
int F_107 ( struct V_90 * V_49 , int V_140 ,
int V_141 , char T_7 * V_142 , unsigned int V_17 )
{
int V_34 ;
if ( V_140 != V_10 )
return - V_181 ;
V_34 = F_72 ( V_49 , V_140 , V_141 , V_142 , V_17 ) ;
#ifdef F_108
if ( V_34 == - V_181 && V_141 != V_145 &&
V_141 != V_261 &&
V_141 != V_262 &&
! F_74 ( V_141 ) ) {
F_76 ( V_49 ) ;
V_34 = F_109 ( V_49 , V_168 , V_141 , V_142 , V_17 ) ;
F_100 ( V_49 ) ;
}
#endif
return V_34 ;
}
int F_110 ( struct V_90 * V_49 , int V_140 , int V_141 ,
char T_7 * V_142 , unsigned int V_17 )
{
int V_34 ;
if ( V_140 != V_10 )
return - V_181 ;
if ( V_141 >= V_226 && V_141 <= V_244 )
return F_111 ( V_49 , V_140 , V_141 , V_142 , V_17 ,
F_107 ) ;
V_34 = F_72 ( V_49 , V_140 , V_141 , V_142 , V_17 ) ;
#ifdef F_108
if ( V_34 == - V_181 && V_141 != V_145 &&
V_141 != V_261 &&
V_141 != V_262 &&
! F_74 ( V_141 ) ) {
F_76 ( V_49 ) ;
V_34 = F_112 ( V_49 , V_168 , V_141 ,
V_142 , V_17 ) ;
F_100 ( V_49 ) ;
}
#endif
return V_34 ;
}
static int F_113 ( struct V_90 * V_49 , int V_140 , int V_141 ,
char T_7 * V_142 , int T_7 * V_17 , unsigned int V_50 )
{
struct V_47 * V_48 = F_23 ( V_49 ) ;
int V_64 ;
int V_40 ;
if ( V_140 != V_10 )
return - V_271 ;
if ( F_74 ( V_141 ) )
return F_114 ( V_49 , V_141 , V_142 , V_17 ) ;
if ( F_73 ( V_40 , V_17 ) )
return - V_158 ;
if ( V_40 < 0 )
return - V_67 ;
F_76 ( V_49 ) ;
switch ( V_141 ) {
case V_160 :
{
unsigned char V_19 [ sizeof( struct V_20 ) + 40 ] ;
struct V_20 * V_16 = (struct V_20 * ) V_19 ;
struct V_161 * V_164 ;
V_164 = F_42 ( V_48 -> V_164 ,
F_79 ( V_49 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_164 )
memcpy ( V_19 , & V_164 -> V_16 ,
sizeof( struct V_20 ) +
V_164 -> V_16 . V_17 ) ;
F_100 ( V_49 ) ;
if ( V_16 -> V_17 == 0 )
return F_115 ( 0 , V_17 ) ;
F_11 ( V_16 ) ;
V_40 = F_116 (unsigned int, len, opt->optlen) ;
if ( F_115 ( V_40 , V_17 ) )
return - V_158 ;
if ( F_117 ( V_142 , V_16 -> V_24 , V_40 ) )
return - V_158 ;
return 0 ;
}
case V_11 :
V_64 = ( V_48 -> V_51 & V_52 ) != 0 ;
break;
case V_143 :
V_64 = ( V_48 -> V_51 & V_53 ) != 0 ;
break;
case V_144 :
V_64 = ( V_48 -> V_51 & V_54 ) != 0 ;
break;
case V_18 :
V_64 = ( V_48 -> V_51 & V_55 ) != 0 ;
break;
case V_23 :
V_64 = ( V_48 -> V_51 & V_56 ) != 0 ;
break;
case V_149 :
V_64 = ( V_48 -> V_51 & V_57 ) != 0 ;
break;
case V_157 :
V_64 = ( V_48 -> V_51 & V_58 ) != 0 ;
break;
case V_30 :
V_64 = ( V_48 -> V_51 & V_59 ) != 0 ;
break;
case V_14 :
V_64 = V_48 -> V_15 ;
break;
case V_13 :
V_64 = ( V_48 -> V_180 == - 1 ?
V_272 :
V_48 -> V_180 ) ;
break;
case V_145 :
V_64 = V_48 -> V_182 ;
break;
case V_152 :
V_64 = V_48 -> V_183 ;
break;
case V_146 :
V_64 = V_48 -> V_186 ;
break;
case V_273 :
{
struct V_274 * V_275 ;
V_64 = 0 ;
V_275 = F_118 ( V_49 ) ;
if ( V_275 ) {
V_64 = F_119 ( V_275 ) ;
F_120 ( V_275 ) ;
}
if ( ! V_64 ) {
F_100 ( V_49 ) ;
return - V_276 ;
}
break;
}
case V_138 :
V_64 = V_48 -> V_119 ;
break;
case V_154 :
V_64 = V_48 -> V_188 ;
break;
case V_156 :
V_64 = V_48 -> V_189 ;
break;
case V_153 :
V_64 = ( V_191 int ) F_90 ( ( V_277 ) V_48 -> V_192 ) ;
break;
case V_195 :
{
struct V_198 V_79 ;
V_40 = F_116 (unsigned int, len, sizeof(struct in_addr)) ;
V_79 . V_8 = V_48 -> V_204 ;
F_100 ( V_49 ) ;
if ( F_115 ( V_40 , V_17 ) )
return - V_158 ;
if ( F_117 ( V_142 , & V_79 , V_40 ) )
return - V_158 ;
return 0 ;
}
case V_208 :
{
struct V_209 V_210 ;
int V_34 ;
if ( V_40 < F_94 ( 0 ) ) {
F_100 ( V_49 ) ;
return - V_67 ;
}
if ( F_89 ( & V_210 , V_142 , F_94 ( 0 ) ) ) {
F_100 ( V_49 ) ;
return - V_158 ;
}
V_34 = F_121 ( V_49 , & V_210 ,
(struct V_209 T_7 * ) V_142 , V_17 ) ;
F_100 ( V_49 ) ;
return V_34 ;
}
case V_244 :
{
struct V_245 V_246 ;
int V_34 ;
if ( V_40 < F_97 ( 0 ) ) {
F_100 ( V_49 ) ;
return - V_67 ;
}
if ( F_89 ( & V_246 , V_142 , F_97 ( 0 ) ) ) {
F_100 ( V_49 ) ;
return - V_158 ;
}
V_34 = F_122 ( V_49 , & V_246 ,
(struct V_245 T_7 * ) V_142 ,
V_17 ) ;
F_100 ( V_49 ) ;
return V_34 ;
}
case V_155 :
V_64 = V_48 -> V_259 ;
break;
case V_278 :
{
struct V_1 V_2 ;
F_100 ( V_49 ) ;
if ( V_49 -> V_94 != V_177 )
return - V_181 ;
V_2 . V_279 = ( V_191 void * ) V_142 ;
V_2 . V_280 = V_40 ;
V_2 . V_21 = V_50 ;
if ( V_48 -> V_51 & V_52 ) {
struct V_5 V_6 ;
V_6 . V_7 . V_8 = V_48 -> V_281 ;
V_6 . V_82 . V_8 = V_48 -> V_281 ;
V_6 . V_81 = V_48 -> V_203 ;
F_4 ( & V_2 , V_10 , V_11 , sizeof( V_6 ) , & V_6 ) ;
}
if ( V_48 -> V_51 & V_53 ) {
int V_282 = V_48 -> V_188 ;
F_4 ( & V_2 , V_10 , V_13 , sizeof( V_282 ) , & V_282 ) ;
}
if ( V_48 -> V_51 & V_54 ) {
int V_15 = V_48 -> V_283 ;
F_4 ( & V_2 , V_10 , V_14 , sizeof( V_15 ) , & V_15 ) ;
}
V_40 -= V_2 . V_280 ;
return F_115 ( V_40 , V_17 ) ;
}
case V_148 :
V_64 = V_48 -> V_260 ;
break;
case V_150 :
V_64 = V_48 -> V_267 ;
break;
case V_151 :
V_64 = V_48 -> V_268 ;
break;
default:
F_100 ( V_49 ) ;
return - V_181 ;
}
F_100 ( V_49 ) ;
if ( V_40 < sizeof( int ) && V_40 > 0 && V_64 >= 0 && V_64 <= 255 ) {
unsigned char V_159 = ( unsigned char ) V_64 ;
V_40 = 1 ;
if ( F_115 ( V_40 , V_17 ) )
return - V_158 ;
if ( F_117 ( V_142 , & V_159 , 1 ) )
return - V_158 ;
} else {
V_40 = F_116 (unsigned int, sizeof(int), len) ;
if ( F_115 ( V_40 , V_17 ) )
return - V_158 ;
if ( F_117 ( V_142 , & V_64 , V_40 ) )
return - V_158 ;
}
return 0 ;
}
int F_123 ( struct V_90 * V_49 , int V_140 ,
int V_141 , char T_7 * V_142 , int T_7 * V_17 )
{
int V_34 ;
V_34 = F_113 ( V_49 , V_140 , V_141 , V_142 , V_17 , 0 ) ;
#ifdef F_108
if ( V_34 == - V_181 && V_141 != V_278 &&
! F_74 ( V_141 ) ) {
int V_40 ;
if ( F_73 ( V_40 , V_17 ) )
return - V_158 ;
F_76 ( V_49 ) ;
V_34 = F_124 ( V_49 , V_168 , V_141 , V_142 ,
& V_40 ) ;
F_100 ( V_49 ) ;
if ( V_34 >= 0 )
V_34 = F_115 ( V_40 , V_17 ) ;
return V_34 ;
}
#endif
return V_34 ;
}
int F_125 ( struct V_90 * V_49 , int V_140 , int V_141 ,
char T_7 * V_142 , int T_7 * V_17 )
{
int V_34 ;
if ( V_141 == V_244 )
return F_126 ( V_49 , V_140 , V_141 , V_142 , V_17 ,
F_123 ) ;
V_34 = F_113 ( V_49 , V_140 , V_141 , V_142 , V_17 ,
V_284 ) ;
#ifdef F_108
if ( V_34 == - V_181 && V_141 != V_278 &&
! F_74 ( V_141 ) ) {
int V_40 ;
if ( F_73 ( V_40 , V_17 ) )
return - V_158 ;
F_76 ( V_49 ) ;
V_34 = F_127 ( V_49 , V_168 , V_141 , V_142 , & V_40 ) ;
F_100 ( V_49 ) ;
if ( V_34 >= 0 )
V_34 = F_115 ( V_40 , V_17 ) ;
return V_34 ;
}
#endif
return V_34 ;
}
