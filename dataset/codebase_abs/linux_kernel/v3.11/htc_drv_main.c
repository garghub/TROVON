static enum V_1 F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
enum V_1 V_6 ;
V_6 = - V_7 ;
switch ( V_5 -> V_8 ) {
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_6 = V_13 ;
break;
case V_14 :
case V_15 :
case V_16 :
case V_17 :
V_6 = V_18 ;
break;
default:
break;
}
F_2 ( V_6 < 0 ) ;
return V_6 ;
}
bool F_3 ( struct V_2 * V_3 ,
enum V_19 V_6 )
{
bool V_20 ;
F_4 ( & V_3 -> V_21 ) ;
V_20 = F_5 ( V_3 -> V_22 , V_6 ) ;
F_6 ( & V_3 -> V_21 ) ;
return V_20 ;
}
void F_7 ( struct V_2 * V_3 )
{
F_4 ( & V_3 -> V_21 ) ;
if ( ++ V_3 -> V_23 != 1 )
goto V_24;
F_5 ( V_3 -> V_22 , V_25 ) ;
V_24:
F_6 ( & V_3 -> V_21 ) ;
}
void F_8 ( struct V_2 * V_3 )
{
bool V_26 ;
F_4 ( & V_3 -> V_21 ) ;
if ( -- V_3 -> V_23 != 0 )
goto V_24;
if ( V_3 -> V_27 ) {
F_9 ( V_3 -> V_22 , true ) ;
F_10 ( V_3 -> V_22 , & V_26 ) ;
F_5 ( V_3 -> V_22 , V_28 ) ;
} else if ( V_3 -> V_29 ) {
F_5 ( V_3 -> V_22 , V_30 ) ;
}
V_24:
F_6 ( & V_3 -> V_21 ) ;
}
void F_11 ( struct V_31 * V_32 )
{
struct V_2 * V_3 =
F_12 ( V_32 , struct V_2 ,
V_33 ) ;
F_3 ( V_3 , V_25 ) ;
F_3 ( V_3 , V_30 ) ;
}
static void F_13 ( void * V_34 , T_1 * V_35 , struct V_36 * V_37 )
{
struct V_2 * V_3 = V_34 ;
struct V_38 * V_39 = & V_37 -> V_39 ;
if ( ( V_37 -> type == V_40 ||
V_37 -> type == V_41 ) &&
V_39 -> V_42 )
V_3 -> V_43 = true ;
if ( V_39 -> V_44 ) {
V_3 -> V_45 = true ;
V_3 -> V_43 = true ;
}
}
static void F_14 ( struct V_2 * V_3 )
{
V_3 -> V_45 = false ;
V_3 -> V_43 = false ;
F_15 (
V_3 -> V_46 , V_47 ,
F_13 , V_3 ) ;
if ( V_3 -> V_45 )
F_16 ( V_3 ) ;
if ( V_3 -> V_43 ) {
F_7 ( V_3 ) ;
F_17 ( V_3 ) ;
F_8 ( V_3 ) ;
}
}
static void F_18 ( void * V_34 , T_1 * V_35 , struct V_36 * V_37 )
{
struct V_48 * V_49 = V_34 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ )
V_49 -> V_52 [ V_50 ] &= ~ ( V_49 -> V_53 [ V_50 ] ^ V_35 [ V_50 ] ) ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_48 V_49 ;
V_49 . V_53 = V_55 -> V_56 ;
memset ( & V_49 . V_52 , 0xff , V_51 ) ;
if ( V_37 )
F_18 ( & V_49 , V_37 -> V_57 , V_37 ) ;
F_15 (
V_3 -> V_46 , V_47 ,
F_18 , & V_49 ) ;
memcpy ( V_55 -> V_58 , V_49 . V_52 , V_51 ) ;
F_21 ( V_55 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
if ( V_3 -> V_59 )
V_3 -> V_22 -> V_60 = V_61 ;
else if ( V_3 -> V_62 )
V_3 -> V_22 -> V_60 = V_40 ;
else if ( V_3 -> V_63 )
V_3 -> V_22 -> V_60 = V_41 ;
else
V_3 -> V_22 -> V_60 = V_64 ;
F_23 ( V_3 -> V_22 ) ;
}
void F_24 ( struct V_2 * V_3 )
{
struct V_65 * V_22 = V_3 -> V_22 ;
struct V_54 * V_55 = F_20 ( V_22 ) ;
struct V_66 * V_67 = V_3 -> V_46 -> V_68 . V_69 . V_70 ;
struct V_71 * V_72 = NULL ;
enum V_1 V_6 ;
T_2 V_73 ;
T_1 V_74 ;
int V_20 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
F_25 ( V_3 ) ;
F_26 ( V_3 -> V_46 ) ;
F_27 ( & V_3 -> V_76 . V_77 ) ;
F_28 ( V_3 ) ;
F_29 ( V_78 ) ;
F_29 ( V_79 ) ;
F_29 ( V_80 ) ;
F_30 ( V_3 ) ;
V_72 = & V_3 -> V_72 ;
V_20 = F_31 ( V_22 , V_22 -> V_81 , V_72 , false ) ;
if ( V_20 ) {
F_32 ( V_55 ,
L_1 ,
V_67 -> V_82 , V_20 ) ;
}
F_33 ( V_22 , V_3 -> V_83 , V_3 -> V_84 ,
& V_3 -> V_83 ) ;
F_29 ( V_85 ) ;
F_34 ( V_3 ) ;
V_6 = F_1 ( V_3 , V_22 -> V_81 ) ;
V_73 = F_35 ( V_6 ) ;
F_36 ( V_86 , & V_73 ) ;
F_29 ( V_87 ) ;
F_37 ( V_3 -> V_88 ) ;
F_14 ( V_3 ) ;
F_38 ( V_3 -> V_46 ) ;
F_39 ( & V_3 -> V_76 . V_77 ,
V_89 + F_40 ( V_90 ) ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_91 * V_46 ,
struct V_4 * V_92 )
{
struct V_65 * V_22 = V_3 -> V_22 ;
struct V_54 * V_55 = F_20 ( V_22 ) ;
struct V_93 * V_68 = & V_55 -> V_46 -> V_68 ;
bool V_94 ;
struct V_66 * V_67 = V_46 -> V_68 . V_69 . V_70 ;
struct V_71 * V_72 = NULL ;
enum V_1 V_6 ;
T_2 V_73 ;
T_1 V_74 ;
int V_20 ;
if ( F_42 ( V_95 , & V_3 -> V_96 ) )
return - V_97 ;
V_94 = ! ! ( V_46 -> V_68 . V_98 & V_99 ) ;
F_7 ( V_3 ) ;
F_27 ( & V_3 -> V_76 . V_77 ) ;
F_28 ( V_3 ) ;
F_29 ( V_78 ) ;
F_29 ( V_79 ) ;
F_29 ( V_80 ) ;
F_30 ( V_3 ) ;
F_43 ( V_55 , V_100 ,
L_2 ,
V_3 -> V_22 -> V_81 -> V_67 ,
V_67 -> V_82 , F_44 ( V_68 ) , F_45 ( V_68 ) ,
V_94 ) ;
if ( ! V_94 )
V_72 = & V_3 -> V_72 ;
V_20 = F_31 ( V_22 , V_92 , V_72 , V_94 ) ;
if ( V_20 ) {
F_32 ( V_55 ,
L_3 ,
V_67 -> V_82 , V_20 ) ;
goto V_101;
}
F_33 ( V_22 , V_3 -> V_83 , V_3 -> V_84 ,
& V_3 -> V_83 ) ;
F_29 ( V_85 ) ;
if ( V_20 )
goto V_101;
F_34 ( V_3 ) ;
V_6 = F_1 ( V_3 , V_92 ) ;
V_73 = F_35 ( V_6 ) ;
F_36 ( V_86 , & V_73 ) ;
if ( V_20 )
goto V_101;
F_29 ( V_87 ) ;
if ( V_20 )
goto V_101;
F_37 ( V_3 -> V_88 ) ;
if ( ! F_42 ( V_102 , & V_3 -> V_96 ) &&
! ( V_46 -> V_68 . V_98 & V_99 ) )
F_14 ( V_3 ) ;
F_39 ( & V_3 -> V_76 . V_77 ,
V_89 + F_40 ( V_90 ) ) ;
V_101:
F_8 ( V_3 ) ;
return V_20 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_103 V_104 ;
int V_20 = 0 ;
T_1 V_74 ;
memset ( & V_104 , 0 , sizeof( struct V_103 ) ) ;
memcpy ( & V_104 . V_105 , V_55 -> V_56 , V_51 ) ;
V_104 . V_106 = V_3 -> V_107 ;
F_36 ( V_108 , & V_104 ) ;
if ( V_20 ) {
F_32 ( V_55 , L_4 ,
V_3 -> V_107 ) ;
}
V_3 -> V_109 -- ;
V_3 -> V_110 &= ~ ( 1 << V_3 -> V_107 ) ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_103 V_104 ;
struct V_111 V_112 ;
int V_20 = 0 , V_113 ;
T_1 V_74 ;
if ( ( V_3 -> V_109 >= V_114 ) ||
( V_3 -> V_115 >= V_116 ) ) {
V_20 = - V_117 ;
goto V_118;
}
V_113 = F_48 ( V_3 -> V_119 ) ;
if ( ( V_113 < 0 ) || ( V_113 > V_116 ) ) {
V_20 = - V_117 ;
goto V_118;
}
memset ( & V_104 , 0 , sizeof( struct V_103 ) ) ;
memcpy ( & V_104 . V_105 , V_55 -> V_56 , V_51 ) ;
V_104 . V_60 = V_120 ;
V_104 . V_106 = F_48 ( V_3 -> V_110 ) ;
F_36 ( V_121 , & V_104 ) ;
if ( V_20 )
goto V_118;
V_3 -> V_107 = V_104 . V_106 ;
V_3 -> V_110 |= ( 1 << V_104 . V_106 ) ;
if ( ! V_3 -> V_109 )
V_3 -> V_22 -> V_60 = V_122 ;
V_3 -> V_109 ++ ;
memset ( & V_112 , 0 , sizeof( struct V_111 ) ) ;
memcpy ( & V_112 . V_56 , V_55 -> V_56 , V_51 ) ;
V_112 . V_123 = 1 ;
V_112 . V_124 = V_113 ;
V_112 . V_125 = V_104 . V_106 ;
V_112 . V_126 = F_35 ( 0xffff ) ;
F_36 ( V_127 , & V_112 ) ;
if ( V_20 ) {
F_32 ( V_55 , L_5 ) ;
goto V_128;
}
V_3 -> V_119 |= ( 1 << V_113 ) ;
V_3 -> V_115 ++ ;
V_3 -> V_129 [ V_3 -> V_107 ] = V_113 ;
V_3 -> V_22 -> V_130 = true ;
F_43 ( V_55 , V_100 ,
L_6 ,
V_3 -> V_107 , V_113 ) ;
return 0 ;
V_128:
F_46 ( V_3 ) ;
V_118:
F_43 ( V_55 , V_131 , L_7 ) ;
return V_20 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
int V_20 = 0 ;
T_1 V_74 , V_113 ;
F_46 ( V_3 ) ;
V_113 = V_3 -> V_129 [ V_3 -> V_107 ] ;
F_36 ( V_132 , & V_113 ) ;
if ( V_20 ) {
F_32 ( V_55 , L_8 ) ;
return V_20 ;
}
V_3 -> V_119 &= ~ ( 1 << V_113 ) ;
V_3 -> V_115 -- ;
V_3 -> V_22 -> V_130 = false ;
F_43 ( V_55 , V_100 ,
L_9 ,
V_3 -> V_107 , V_113 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_133 * V_134 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_111 V_112 ;
struct V_135 * V_136 = (struct V_135 * ) V_37 -> V_137 ;
struct V_138 * V_139 ;
int V_20 , V_113 ;
T_1 V_74 ;
T_3 V_126 ;
if ( V_3 -> V_115 >= V_116 )
return - V_117 ;
V_113 = F_48 ( V_3 -> V_119 ) ;
if ( ( V_113 < 0 ) || ( V_113 > V_116 ) )
return - V_117 ;
memset ( & V_112 , 0 , sizeof( struct V_111 ) ) ;
if ( V_134 ) {
V_139 = (struct V_138 * ) V_134 -> V_137 ;
memcpy ( & V_112 . V_56 , V_134 -> V_57 , V_51 ) ;
memcpy ( & V_112 . V_140 , V_55 -> V_141 , V_51 ) ;
V_139 -> V_106 = V_113 ;
V_112 . V_123 = 0 ;
V_126 = 1 << ( V_142 +
V_134 -> V_143 . V_144 ) ;
V_112 . V_126 = F_35 ( V_126 ) ;
} else {
memcpy ( & V_112 . V_56 , V_37 -> V_57 , V_51 ) ;
V_112 . V_123 = 1 ;
V_112 . V_126 = F_35 ( 0xffff ) ;
}
V_112 . V_124 = V_113 ;
V_112 . V_125 = V_136 -> V_106 ;
F_36 ( V_127 , & V_112 ) ;
if ( V_20 ) {
if ( V_134 )
F_32 ( V_55 ,
L_10 ,
V_134 -> V_57 ) ;
return V_20 ;
}
if ( V_134 ) {
F_43 ( V_55 , V_100 ,
L_11 ,
V_134 -> V_57 , V_112 . V_124 ) ;
} else {
F_43 ( V_55 , V_100 ,
L_12 ,
V_136 -> V_106 , V_112 . V_124 ) ;
}
V_3 -> V_119 |= ( 1 << V_113 ) ;
V_3 -> V_115 ++ ;
if ( ! V_134 )
V_3 -> V_129 [ V_136 -> V_106 ] = V_113 ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_133 * V_134 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_135 * V_136 = (struct V_135 * ) V_37 -> V_137 ;
struct V_138 * V_139 ;
int V_20 ;
T_1 V_74 , V_113 ;
if ( V_134 ) {
V_139 = (struct V_138 * ) V_134 -> V_137 ;
V_113 = V_139 -> V_106 ;
} else {
V_113 = V_3 -> V_129 [ V_136 -> V_106 ] ;
}
F_36 ( V_132 , & V_113 ) ;
if ( V_20 ) {
if ( V_134 )
F_32 ( V_55 ,
L_13 ,
V_134 -> V_57 ) ;
return V_20 ;
}
if ( V_134 ) {
F_43 ( V_55 , V_100 ,
L_14 ,
V_134 -> V_57 , V_113 ) ;
} else {
F_43 ( V_55 , V_100 ,
L_15 ,
V_136 -> V_106 , V_113 ) ;
}
V_3 -> V_119 &= ~ ( 1 << V_113 ) ;
V_3 -> V_115 -- ;
return 0 ;
}
int F_52 ( struct V_2 * V_3 ,
T_1 V_145 )
{
struct V_146 V_147 ;
int V_20 ;
T_1 V_74 ;
memset ( & V_147 , 0 , sizeof( struct V_146 ) ) ;
V_147 . V_148 = F_53 ( 0xffff ) ;
V_147 . V_149 = 0xff ;
V_147 . V_145 = V_145 ;
V_147 . V_150 = V_3 -> V_22 -> V_151 . V_150 ;
F_36 ( V_152 , & V_147 ) ;
return V_20 ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_133 * V_134 ,
struct V_153 * V_154 )
{
struct V_138 * V_139 = (struct V_138 * ) V_134 -> V_137 ;
struct V_155 * V_156 ;
T_4 V_151 = 0 ;
int V_50 , V_157 ;
V_156 = V_3 -> V_46 -> V_158 -> V_159 [ V_3 -> V_46 -> V_68 . V_69 . V_70 -> V_160 ] ;
for ( V_50 = 0 , V_157 = 0 ; V_50 < V_156 -> V_161 ; V_50 ++ ) {
if ( V_134 -> V_162 [ V_156 -> V_160 ] & F_55 ( V_50 ) ) {
V_154 -> V_163 . V_164 . V_165 [ V_157 ]
= ( V_156 -> V_166 [ V_50 ] . V_167 * 2 ) / 10 ;
V_157 ++ ;
}
}
V_154 -> V_163 . V_164 . V_168 = V_157 ;
if ( V_134 -> V_143 . V_169 ) {
for ( V_50 = 0 , V_157 = 0 ; V_50 < 77 ; V_50 ++ ) {
if ( V_134 -> V_143 . V_170 . V_171 [ V_50 / 8 ] & ( 1 << ( V_50 % 8 ) ) )
V_154 -> V_163 . V_172 . V_165 [ V_157 ++ ] = V_50 ;
if ( V_157 == V_173 )
break;
}
V_154 -> V_163 . V_172 . V_168 = V_157 ;
V_151 = V_174 ;
if ( V_134 -> V_143 . V_175 & V_176 )
V_151 |= V_177 ;
if ( V_134 -> V_143 . V_170 . V_171 [ 1 ] )
V_151 |= V_178 ;
if ( ( V_134 -> V_143 . V_175 & V_179 ) &&
( F_45 ( & V_3 -> V_46 -> V_68 ) ) )
V_151 |= V_180 ;
if ( F_45 ( & V_3 -> V_46 -> V_68 ) &&
( V_134 -> V_143 . V_175 & V_181 ) )
V_151 |= V_182 ;
else if ( F_56 ( & V_3 -> V_46 -> V_68 ) &&
( V_134 -> V_143 . V_175 & V_183 ) )
V_151 |= V_182 ;
}
V_154 -> V_124 = V_139 -> V_106 ;
V_154 -> V_184 = 1 ;
V_154 -> V_185 = F_53 ( V_151 ) ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_153 * V_154 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
int V_20 ;
T_1 V_74 ;
F_36 ( V_186 , V_154 ) ;
if ( V_20 ) {
F_32 ( V_55 ,
L_16 ) ;
}
return V_20 ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_133 * V_134 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_153 V_154 ;
int V_20 ;
memset ( & V_154 , 0 , sizeof( struct V_153 ) ) ;
F_54 ( V_3 , V_134 , & V_154 ) ;
V_20 = F_57 ( V_3 , & V_154 ) ;
if ( ! V_20 )
F_43 ( V_55 , V_100 ,
L_17 ,
V_134 -> V_57 , F_59 ( V_154 . V_185 ) ) ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_153 V_154 ;
struct V_133 * V_134 ;
int V_20 ;
memset ( & V_154 , 0 , sizeof( struct V_153 ) ) ;
F_61 () ;
V_134 = F_62 ( V_37 , V_39 -> V_140 ) ;
if ( ! V_134 ) {
F_63 () ;
return;
}
F_54 ( V_3 , V_134 , & V_154 ) ;
F_63 () ;
V_20 = F_57 ( V_3 , & V_154 ) ;
if ( ! V_20 )
F_43 ( V_55 , V_100 ,
L_17 ,
V_39 -> V_140 , F_59 ( V_154 . V_185 ) ) ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_133 * V_134 ,
enum V_187 V_188 ,
T_3 V_189 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_190 V_191 ;
struct V_138 * V_139 ;
int V_20 = 0 ;
T_1 V_74 ;
if ( V_189 >= V_192 )
return - V_7 ;
memset ( & V_191 , 0 , sizeof( struct V_190 ) ) ;
V_139 = (struct V_138 * ) V_134 -> V_137 ;
V_191 . V_124 = V_139 -> V_106 ;
V_191 . V_193 = V_189 & 0xf ;
V_191 . V_194 = ( V_188 == V_195 ) ? true : false ;
F_36 ( V_196 , & V_191 ) ;
if ( V_20 )
F_43 ( V_55 , V_100 ,
L_18 ,
( V_191 . V_194 ) ? L_19 : L_20 , V_134 -> V_57 , V_189 ) ;
else
F_43 ( V_55 , V_100 ,
L_21 ,
( V_191 . V_194 ) ? L_22 : L_23 ,
V_134 -> V_57 , V_189 ) ;
F_65 ( & V_3 -> V_76 . V_197 ) ;
V_139 -> V_198 [ V_189 ] = ( V_191 . V_194 && ! V_20 ) ? V_199 : V_200 ;
F_66 ( & V_3 -> V_76 . V_197 ) ;
return V_20 ;
}
void F_16 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
unsigned long V_201 = F_67 ( V_89 ) ;
V_55 -> V_202 . V_203 = V_201 ;
V_55 -> V_202 . V_204 = V_201 ;
V_55 -> V_202 . V_205 = V_201 ;
F_68 ( V_206 , & V_3 -> V_96 ) ;
F_69 ( V_55 -> V_46 , & V_3 -> V_207 ,
F_40 ( V_208 ) ) ;
}
void F_25 ( struct V_2 * V_3 )
{
F_70 ( & V_3 -> V_207 ) ;
F_71 ( V_206 , & V_3 -> V_96 ) ;
}
void F_72 ( struct V_31 * V_32 )
{
struct V_2 * V_3 =
F_12 ( V_32 , struct V_2 , V_207 . V_32 ) ;
struct V_65 * V_22 = V_3 -> V_22 ;
struct V_54 * V_55 = F_20 ( V_22 ) ;
bool V_209 = false ;
bool V_210 = false ;
bool V_211 = false ;
unsigned int V_201 = F_67 ( V_89 ) ;
T_4 V_212 , V_213 ;
V_213 = ( V_22 -> V_60 == V_40 ) ?
V_214 : V_215 ;
if ( V_22 -> V_216 != V_25 )
goto V_217;
if ( ( V_201 - V_55 -> V_202 . V_203 ) >= V_218 ) {
V_209 = true ;
F_43 ( V_55 , V_219 , L_24 , V_89 ) ;
V_55 -> V_202 . V_203 = V_201 ;
}
if ( ! V_55 -> V_202 . V_220 ) {
if ( ( V_201 - V_55 -> V_202 . V_204 ) >=
V_213 ) {
V_210 = true ;
F_43 ( V_55 , V_219 , L_25 , V_89 ) ;
V_55 -> V_202 . V_204 = V_201 ;
V_55 -> V_202 . V_221 = V_201 ;
}
} else {
if ( ( V_201 - V_55 -> V_202 . V_221 ) >=
V_222 ) {
V_55 -> V_202 . V_220 = F_73 ( V_22 ) ;
if ( V_55 -> V_202 . V_220 )
V_55 -> V_202 . V_221 = V_201 ;
}
}
if ( ( V_201 - V_55 -> V_202 . V_205 ) >= V_208 ) {
V_211 = true ;
V_55 -> V_202 . V_205 = V_201 ;
}
if ( V_209 || V_210 || V_211 ) {
F_7 ( V_3 ) ;
if ( V_211 )
F_74 ( V_22 , V_22 -> V_81 ) ;
if ( V_209 || V_210 )
V_55 -> V_202 . V_220 =
F_75 ( V_22 , V_22 -> V_81 ,
V_22 -> V_223 , V_209 ) ;
F_8 ( V_3 ) ;
}
V_217:
V_212 = V_218 ;
V_212 = F_76 ( V_212 , ( T_4 ) V_208 ) ;
if ( ! V_55 -> V_202 . V_220 )
V_212 = F_76 ( V_212 , ( T_4 ) V_213 ) ;
F_69 ( V_55 -> V_46 , & V_3 -> V_207 ,
F_40 ( V_212 ) ) ;
}
static void F_77 ( struct V_91 * V_46 ,
struct V_224 * V_225 ,
struct V_226 * V_227 )
{
struct V_228 * V_229 ;
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
int V_230 , V_231 , V_20 , V_232 ;
V_229 = (struct V_228 * ) V_227 -> V_34 ;
V_230 = F_78 ( V_229 -> V_233 ) ;
V_231 = V_230 & 3 ;
if ( V_231 && V_227 -> V_234 > V_230 ) {
if ( F_79 ( V_227 ) < V_231 ) {
F_43 ( V_55 , V_235 , L_26 ) ;
goto V_236;
}
F_80 ( V_227 , V_231 ) ;
memmove ( V_227 -> V_34 , V_227 -> V_34 + V_231 , V_230 ) ;
}
V_232 = F_81 ( V_3 ) ;
if ( V_232 < 0 ) {
F_43 ( V_55 , V_235 , L_27 ) ;
goto V_236;
}
V_20 = F_82 ( V_3 , V_225 -> V_134 , V_227 , V_232 , false ) ;
if ( V_20 != 0 ) {
F_43 ( V_55 , V_235 , L_28 ) ;
goto V_237;
}
F_83 ( V_3 ) ;
return;
V_237:
F_84 ( V_3 , V_232 ) ;
V_236:
F_85 ( V_227 ) ;
}
static int F_86 ( struct V_91 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_65 * V_22 = V_3 -> V_22 ;
struct V_54 * V_55 = F_20 ( V_22 ) ;
struct V_66 * V_81 = V_46 -> V_68 . V_69 . V_70 ;
struct V_4 * V_238 ;
int V_20 = 0 ;
enum V_1 V_6 ;
T_2 V_73 ;
T_1 V_74 ;
F_4 ( & V_3 -> V_75 ) ;
F_43 ( V_55 , V_100 ,
L_29 ,
V_81 -> V_82 ) ;
F_3 ( V_3 , V_25 ) ;
F_29 ( V_239 ) ;
V_238 = F_87 ( V_46 , V_22 ) ;
V_20 = F_31 ( V_22 , V_238 , V_22 -> V_72 , false ) ;
if ( V_20 ) {
F_32 ( V_55 ,
L_30 ,
V_20 , V_81 -> V_82 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_20 ;
}
F_33 ( V_22 , V_3 -> V_83 , V_3 -> V_84 ,
& V_3 -> V_83 ) ;
V_6 = F_1 ( V_3 , V_238 ) ;
V_73 = F_35 ( V_6 ) ;
F_36 ( V_86 , & V_73 ) ;
F_29 ( V_240 ) ;
F_29 ( V_85 ) ;
F_34 ( V_3 ) ;
V_20 = F_52 ( V_3 , 0 ) ;
if ( V_20 )
F_43 ( V_55 , V_100 ,
L_31 ) ;
F_71 ( V_95 , & V_3 -> V_96 ) ;
F_37 ( V_3 -> V_88 ) ;
F_65 ( & V_3 -> V_76 . V_197 ) ;
V_3 -> V_76 . V_98 &= ~ V_241 ;
F_66 ( & V_3 -> V_76 . V_197 ) ;
F_38 ( V_46 ) ;
F_39 ( & V_3 -> V_76 . V_77 ,
V_89 + F_40 ( V_90 ) ) ;
F_88 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_20 ;
}
static void F_89 ( struct V_91 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_65 * V_22 = V_3 -> V_22 ;
struct V_54 * V_55 = F_20 ( V_22 ) ;
int V_20 V_242 ( ( V_243 ) ) ;
T_1 V_74 ;
F_4 ( & V_3 -> V_75 ) ;
if ( F_42 ( V_95 , & V_3 -> V_96 ) ) {
F_43 ( V_55 , V_244 , L_32 ) ;
F_6 ( & V_3 -> V_75 ) ;
return;
}
F_7 ( V_3 ) ;
F_29 ( V_78 ) ;
F_29 ( V_79 ) ;
F_29 ( V_80 ) ;
F_90 ( & V_3 -> V_245 ) ;
F_27 ( & V_3 -> V_76 . V_77 ) ;
F_28 ( V_3 ) ;
F_30 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
F_91 ( & V_3 -> V_246 ) ;
F_91 ( & V_3 -> V_33 ) ;
#ifdef F_92
F_91 ( & V_3 -> V_247 ) ;
#endif
F_25 ( V_3 ) ;
F_4 ( & V_3 -> V_75 ) ;
F_93 ( V_3 ) ;
if ( V_3 -> V_22 -> V_130 )
F_49 ( V_3 ) ;
F_94 ( V_22 ) ;
F_95 ( V_22 ) ;
F_8 ( V_3 ) ;
F_3 ( V_3 , V_28 ) ;
F_68 ( V_95 , & V_3 -> V_96 ) ;
F_43 ( V_55 , V_100 , L_33 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static int F_96 ( struct V_91 * V_46 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_135 * V_136 = ( void * ) V_37 -> V_137 ;
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_103 V_104 ;
int V_20 = 0 ;
T_1 V_74 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
memset ( & V_104 , 0 , sizeof( struct V_103 ) ) ;
memcpy ( & V_104 . V_105 , V_37 -> V_57 , V_51 ) ;
switch ( V_37 -> type ) {
case V_64 :
V_104 . V_60 = V_248 ;
break;
case V_61 :
V_104 . V_60 = V_249 ;
break;
case V_40 :
V_104 . V_60 = V_250 ;
break;
case V_41 :
V_104 . V_60 = V_251 ;
break;
default:
F_32 ( V_55 ,
L_34 , V_37 -> type ) ;
V_20 = - V_252 ;
goto V_253;
}
V_136 -> V_106 = V_104 . V_106 = F_48 ( V_3 -> V_110 ) ;
V_104 . V_254 = F_35 ( 2304 ) ;
F_36 ( V_121 , & V_104 ) ;
if ( V_20 )
goto V_253;
V_20 = F_50 ( V_3 , V_37 , NULL ) ;
if ( V_20 ) {
F_36 ( V_108 , & V_104 ) ;
goto V_253;
}
F_19 ( V_3 , V_37 ) ;
V_3 -> V_110 |= ( 1 << V_136 -> V_106 ) ;
V_3 -> V_109 ++ ;
F_97 ( V_3 , V_37 -> type ) ;
if ( ( V_37 -> type == V_40 ) ||
( V_37 -> type == V_41 ) ||
( V_37 -> type == V_61 ) )
F_98 ( V_3 , V_37 ) ;
F_22 ( V_3 ) ;
if ( ( V_3 -> V_22 -> V_60 == V_40 ) &&
! F_42 ( V_206 , & V_3 -> V_96 ) ) {
F_99 ( V_3 -> V_22 , true ) ;
F_16 ( V_3 ) ;
}
F_43 ( V_55 , V_100 , L_35 ,
V_37 -> type , V_136 -> V_106 ) ;
V_253:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_20 ;
}
static void F_100 ( struct V_91 * V_46 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_135 * V_136 = ( void * ) V_37 -> V_137 ;
struct V_103 V_104 ;
int V_20 = 0 ;
T_1 V_74 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
memset ( & V_104 , 0 , sizeof( struct V_103 ) ) ;
memcpy ( & V_104 . V_105 , V_37 -> V_57 , V_51 ) ;
V_104 . V_106 = V_136 -> V_106 ;
F_36 ( V_108 , & V_104 ) ;
if ( V_20 ) {
F_32 ( V_55 , L_36 ,
V_136 -> V_106 ) ;
}
V_3 -> V_109 -- ;
V_3 -> V_110 &= ~ ( 1 << V_136 -> V_106 ) ;
F_51 ( V_3 , V_37 , NULL ) ;
F_101 ( V_3 , V_37 -> type ) ;
if ( ( V_37 -> type == V_40 ) ||
V_37 -> type == V_41 ||
( V_37 -> type == V_61 ) )
F_102 ( V_3 , V_37 ) ;
F_22 ( V_3 ) ;
F_19 ( V_3 , V_37 ) ;
if ( ( V_37 -> type == V_40 ) && ( V_3 -> V_62 == 0 ) ) {
V_3 -> V_45 = false ;
F_15 (
V_3 -> V_46 , V_47 ,
F_13 , V_3 ) ;
if ( ! V_3 -> V_45 )
F_25 ( V_3 ) ;
}
F_43 ( V_55 , V_100 , L_37 , V_136 -> V_106 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static int F_103 ( struct V_91 * V_46 , T_4 V_255 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_93 * V_68 = & V_46 -> V_68 ;
bool V_256 = false ;
int V_20 = 0 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
if ( V_255 & V_257 ) {
F_4 ( & V_3 -> V_21 ) ;
V_3 -> V_27 = ! ! ( V_68 -> V_98 & V_258 ) ;
if ( ! V_3 -> V_27 )
V_256 = true ;
F_6 ( & V_3 -> V_21 ) ;
}
if ( V_255 & V_259 ) {
if ( ( V_68 -> V_98 & V_260 ) &&
! V_3 -> V_22 -> V_130 )
F_47 ( V_3 ) ;
else if ( V_3 -> V_22 -> V_130 )
F_49 ( V_3 ) ;
}
if ( ( V_255 & V_261 ) || V_256 ) {
struct V_66 * V_81 = V_46 -> V_68 . V_69 . V_70 ;
enum V_262 V_263 =
F_104 ( & V_46 -> V_68 . V_69 ) ;
int V_264 = V_81 -> V_265 ;
F_43 ( V_55 , V_100 , L_38 ,
V_81 -> V_82 ) ;
F_105 ( & V_3 -> V_22 -> V_266 [ V_264 ] ,
V_46 -> V_68 . V_69 . V_70 ,
V_263 ) ;
if ( F_41 ( V_3 , V_46 , & V_3 -> V_22 -> V_266 [ V_264 ] ) < 0 ) {
F_32 ( V_55 , L_39 ) ;
V_20 = - V_7 ;
goto V_253;
}
}
if ( V_255 & V_267 ) {
if ( V_68 -> V_98 & V_268 ) {
F_3 ( V_3 , V_30 ) ;
V_3 -> V_29 = true ;
} else {
V_3 -> V_29 = false ;
F_91 ( & V_3 -> V_33 ) ;
F_3 ( V_3 , V_25 ) ;
}
}
if ( V_255 & V_269 ) {
V_3 -> V_84 = 2 * V_68 -> V_270 ;
F_33 ( V_3 -> V_22 , V_3 -> V_83 ,
V_3 -> V_84 , & V_3 -> V_83 ) ;
}
V_253:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_20 ;
}
static void F_106 ( struct V_91 * V_46 ,
unsigned int V_271 ,
unsigned int * V_272 ,
T_5 V_273 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
T_4 V_274 ;
F_4 ( & V_3 -> V_75 ) ;
V_271 &= V_275 ;
* V_272 &= V_275 ;
if ( F_42 ( V_95 , & V_3 -> V_96 ) ) {
F_43 ( F_20 ( V_3 -> V_22 ) , V_244 ,
L_40 ) ;
F_6 ( & V_3 -> V_75 ) ;
return;
}
F_7 ( V_3 ) ;
V_3 -> V_276 = * V_272 ;
V_274 = F_107 ( V_3 ) ;
F_108 ( V_3 -> V_22 , V_274 ) ;
F_43 ( F_20 ( V_3 -> V_22 ) , V_100 , L_41 ,
V_274 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static int F_109 ( struct V_91 * V_46 ,
struct V_36 * V_37 ,
struct V_133 * V_134 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
int V_20 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
V_20 = F_50 ( V_3 , V_37 , V_134 ) ;
if ( ! V_20 )
F_58 ( V_3 , V_134 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_20 ;
}
static int F_110 ( struct V_91 * V_46 ,
struct V_36 * V_37 ,
struct V_133 * V_134 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_138 * V_139 ;
int V_20 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
V_139 = (struct V_138 * ) V_134 -> V_137 ;
F_111 ( V_3 -> V_88 , V_139 -> V_106 ) ;
V_20 = F_51 ( V_3 , V_37 , V_134 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_20 ;
}
static void F_112 ( struct V_91 * V_46 ,
struct V_36 * V_37 ,
struct V_133 * V_134 , T_4 V_255 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_153 V_154 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
if ( V_255 & V_277 ) {
memset ( & V_154 , 0 , sizeof( struct V_153 ) ) ;
F_54 ( V_3 , V_134 , & V_154 ) ;
if ( ! F_57 ( V_3 , & V_154 ) )
F_43 ( V_55 , V_100 ,
L_42 ,
V_134 -> V_57 , F_59 ( V_154 . V_185 ) ) ;
else
F_43 ( V_55 , V_100 ,
L_43 ,
V_134 -> V_57 ) ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static int F_113 ( struct V_91 * V_46 ,
struct V_36 * V_37 , T_3 V_278 ,
const struct V_279 * V_280 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_281 V_282 ;
int V_20 = 0 , V_283 ;
if ( V_278 >= V_284 )
return 0 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
memset ( & V_282 , 0 , sizeof( struct V_281 ) ) ;
V_282 . V_285 = V_280 -> V_286 ;
V_282 . V_287 = V_280 -> V_288 ;
V_282 . V_289 = V_280 -> V_290 ;
V_282 . V_291 = V_280 -> V_292 * 32 ;
V_283 = F_114 ( V_278 , V_3 -> V_293 ) ;
F_43 ( V_55 , V_100 ,
L_44 ,
V_278 , V_283 , V_280 -> V_286 , V_280 -> V_288 ,
V_280 -> V_290 , V_280 -> V_292 ) ;
V_20 = F_115 ( V_3 , V_283 , & V_282 ) ;
if ( V_20 ) {
F_32 ( V_55 , L_45 ) ;
goto V_253;
}
if ( ( V_3 -> V_22 -> V_60 == V_61 ) &&
( V_283 == V_3 -> V_293 [ V_294 ] ) )
F_116 ( V_3 ) ;
V_253:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_20 ;
}
static int F_117 ( struct V_91 * V_46 ,
enum V_295 V_296 ,
struct V_36 * V_37 ,
struct V_133 * V_134 ,
struct V_297 * V_298 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
int V_20 = 0 ;
if ( V_299 )
return - V_300 ;
if ( ( V_37 -> type == V_61 ||
V_37 -> type == V_41 ) &&
( V_298 -> V_301 == V_302 ||
V_298 -> V_301 == V_303 ) &&
! ( V_298 -> V_98 & V_304 ) ) {
return - V_252 ;
}
F_4 ( & V_3 -> V_75 ) ;
F_43 ( V_55 , V_100 , L_46 ) ;
F_7 ( V_3 ) ;
switch ( V_296 ) {
case V_305 :
V_20 = F_118 ( V_55 , V_37 , V_134 , V_298 ) ;
if ( V_20 >= 0 ) {
V_298 -> V_306 = V_20 ;
V_298 -> V_98 |= V_307 ;
if ( V_298 -> V_301 == V_302 )
V_298 -> V_98 |= V_308 ;
if ( V_3 -> V_22 -> V_309 &&
V_298 -> V_301 == V_303 )
V_298 -> V_98 |= V_310 ;
V_20 = 0 ;
}
break;
case V_311 :
F_119 ( V_55 , V_298 ) ;
break;
default:
V_20 = - V_7 ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_20 ;
}
static void F_120 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
F_121 ( V_3 -> V_22 ) ;
F_43 ( V_55 , V_100 , L_47 ,
V_55 -> V_141 , V_55 -> V_312 ) ;
}
static void F_122 ( void * V_34 , T_1 * V_35 , struct V_36 * V_37 )
{
struct V_2 * V_3 = (struct V_2 * ) V_34 ;
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_38 * V_39 = & V_37 -> V_39 ;
if ( ( V_37 -> type == V_64 ) && V_39 -> V_44 ) {
V_55 -> V_312 = V_39 -> V_313 ;
memcpy ( V_55 -> V_141 , V_39 -> V_140 , V_51 ) ;
}
}
static void F_123 ( struct V_2 * V_3 )
{
if ( V_3 -> V_314 == 1 ) {
F_15 (
V_3 -> V_46 , V_47 ,
F_122 , V_3 ) ;
F_120 ( V_3 ) ;
}
}
static void F_124 ( struct V_91 * V_46 ,
struct V_36 * V_37 ,
struct V_38 * V_39 ,
T_4 V_255 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_65 * V_22 = V_3 -> V_22 ;
struct V_54 * V_55 = F_20 ( V_22 ) ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
if ( V_255 & V_315 ) {
F_43 ( V_55 , V_100 , L_48 ,
V_39 -> V_44 ) ;
V_39 -> V_44 ?
V_3 -> V_314 ++ : V_3 -> V_314 -- ;
if ( V_3 -> V_22 -> V_60 == V_64 ) {
F_123 ( V_3 ) ;
if ( V_39 -> V_44 && ( V_3 -> V_314 == 1 ) )
F_16 ( V_3 ) ;
else if ( V_3 -> V_314 == 0 )
F_25 ( V_3 ) ;
}
}
if ( V_255 & V_316 ) {
if ( V_3 -> V_22 -> V_60 == V_61 ) {
V_55 -> V_312 = V_39 -> V_313 ;
memcpy ( V_55 -> V_141 , V_39 -> V_140 , V_51 ) ;
F_120 ( V_3 ) ;
}
}
if ( ( V_255 & V_317 ) && V_39 -> V_42 ) {
F_43 ( V_55 , V_100 , L_49 ,
V_39 -> V_140 ) ;
F_125 ( V_3 , V_37 ) ;
F_68 ( V_318 , & V_3 -> V_96 ) ;
F_126 ( V_3 , V_37 ) ;
}
if ( ( V_255 & V_317 ) && ! V_39 -> V_42 ) {
if ( ( V_3 -> V_62 + V_3 -> V_63 <= 1 ) ||
V_3 -> V_59 ) {
F_43 ( V_55 , V_100 ,
L_50 ,
V_39 -> V_140 ) ;
F_71 ( V_318 , & V_3 -> V_96 ) ;
F_126 ( V_3 , V_37 ) ;
}
}
if ( V_255 & V_319 ) {
if ( V_3 -> V_109 == 1 &&
( ( V_3 -> V_22 -> V_60 == V_40 &&
V_37 -> type == V_40 &&
V_3 -> V_62 == 1 ) ||
( V_3 -> V_22 -> V_60 == V_41 &&
V_37 -> type == V_41 &&
V_3 -> V_63 == 1 ) ) ) {
F_68 ( V_320 , & V_3 -> V_96 ) ;
}
F_43 ( V_55 , V_100 ,
L_51 ,
V_39 -> V_140 ) ;
F_126 ( V_3 , V_37 ) ;
}
if ( V_255 & V_321 ) {
if ( V_39 -> V_322 )
V_22 -> V_323 = 9 ;
else
V_22 -> V_323 = 20 ;
F_127 ( V_22 ) ;
}
if ( V_255 & V_324 )
F_60 ( V_3 , V_37 , V_39 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static T_5 F_128 ( struct V_91 * V_46 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
T_5 V_325 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
V_325 = F_129 ( V_3 -> V_22 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_325 ;
}
static void F_130 ( struct V_91 * V_46 ,
struct V_36 * V_37 , T_5 V_325 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
F_131 ( V_3 -> V_22 , V_325 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static void F_132 ( struct V_91 * V_46 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
F_133 ( V_3 -> V_22 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static int F_134 ( struct V_91 * V_46 ,
struct V_36 * V_37 ,
enum V_187 V_188 ,
struct V_133 * V_134 ,
T_3 V_189 , T_3 * V_326 , T_1 V_327 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_138 * V_139 ;
int V_20 = 0 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
switch ( V_188 ) {
case V_328 :
break;
case V_329 :
break;
case V_195 :
V_20 = F_64 ( V_3 , V_37 , V_134 , V_188 , V_189 ) ;
if ( ! V_20 )
F_135 ( V_37 , V_134 -> V_57 , V_189 ) ;
break;
case V_330 :
case V_331 :
case V_332 :
F_64 ( V_3 , V_37 , V_134 , V_188 , V_189 ) ;
F_136 ( V_37 , V_134 -> V_57 , V_189 ) ;
break;
case V_333 :
V_139 = (struct V_138 * ) V_134 -> V_137 ;
F_65 ( & V_3 -> V_76 . V_197 ) ;
V_139 -> V_198 [ V_189 ] = V_334 ;
F_66 ( & V_3 -> V_76 . V_197 ) ;
break;
default:
F_32 ( F_20 ( V_3 -> V_22 ) , L_52 ) ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
return V_20 ;
}
static void F_137 ( struct V_91 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
F_4 ( & V_3 -> V_75 ) ;
F_65 ( & V_3 -> V_335 ) ;
F_68 ( V_102 , & V_3 -> V_96 ) ;
F_66 ( & V_3 -> V_335 ) ;
F_91 ( & V_3 -> V_33 ) ;
F_25 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static void F_138 ( struct V_91 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
F_4 ( & V_3 -> V_75 ) ;
F_65 ( & V_3 -> V_335 ) ;
F_71 ( V_102 , & V_3 -> V_96 ) ;
F_66 ( & V_3 -> V_335 ) ;
F_7 ( V_3 ) ;
F_14 ( V_3 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static int F_139 ( struct V_91 * V_46 , T_4 V_336 )
{
return 0 ;
}
static void F_140 ( struct V_91 * V_46 ,
T_1 V_337 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
F_4 ( & V_3 -> V_75 ) ;
F_7 ( V_3 ) ;
V_3 -> V_22 -> V_337 = V_337 ;
F_127 ( V_3 -> V_22 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_75 ) ;
}
static int F_141 ( struct V_91 * V_46 ,
struct V_36 * V_37 ,
const struct V_338 * V_52 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_54 * V_55 = F_20 ( V_3 -> V_22 ) ;
struct V_339 V_340 ;
struct V_135 * V_136 = ( void * ) V_37 -> V_137 ;
int V_20 = 0 ;
T_1 V_74 ;
memset ( & V_340 , 0 , sizeof( struct V_339 ) ) ;
V_340 . V_125 = V_136 -> V_106 ;
V_340 . V_160 = V_341 ;
V_340 . V_52 = F_53 ( V_52 -> V_225 [ V_341 ] . V_342 ) ;
F_36 ( V_343 , & V_340 ) ;
if ( V_20 ) {
F_32 ( V_55 ,
L_53
L_54 , V_136 -> V_106 ) ;
goto V_253;
}
V_340 . V_160 = V_344 ;
V_340 . V_52 = F_53 ( V_52 -> V_225 [ V_344 ] . V_342 ) ;
F_36 ( V_343 , & V_340 ) ;
if ( V_20 ) {
F_32 ( V_55 ,
L_55
L_54 , V_136 -> V_106 ) ;
goto V_253;
}
F_43 ( V_55 , V_100 , L_56 ,
V_52 -> V_225 [ V_341 ] . V_342 ,
V_52 -> V_225 [ V_344 ] . V_342 ) ;
V_253:
return V_20 ;
}
static int F_142 ( struct V_91 * V_46 ,
struct V_345 * V_346 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_65 * V_22 = V_3 -> V_22 ;
struct V_347 * V_348 = & V_22 -> V_349 ;
V_346 -> V_350 = V_348 -> V_351 ;
V_346 -> V_352 = V_348 -> V_353 ;
V_346 -> V_354 = V_348 -> V_355 ;
V_346 -> V_356 = V_348 -> V_357 ;
return 0 ;
}
struct V_358 * F_143 ( struct V_2 * V_3 )
{
struct V_358 * V_359 = NULL ;
if ( F_144 ( V_3 -> V_22 ) )
V_359 = (struct V_358 * )
& V_3 -> V_22 -> V_360 . V_361 . V_362 ;
else if ( V_3 -> V_22 -> V_363 . V_364 == V_365 )
V_359 = (struct V_358 * )
& V_3 -> V_22 -> V_360 . V_366 . V_362 ;
else if ( V_3 -> V_22 -> V_363 . V_364 == V_367 )
V_359 = (struct V_358 * )
& V_3 -> V_22 -> V_360 . V_368 . V_362 ;
return V_359 ;
}
static int F_145 ( struct V_91 * V_46 , T_4 * V_369 ,
T_4 * V_370 )
{
struct V_2 * V_3 = V_46 -> V_3 ;
struct V_358 * V_359 = F_143 ( V_3 ) ;
if ( V_359 ) {
* V_369 = V_359 -> V_371 ;
* V_370 = V_359 -> V_372 ;
} else {
* V_369 = 0 ;
* V_370 = 0 ;
}
return 0 ;
}
