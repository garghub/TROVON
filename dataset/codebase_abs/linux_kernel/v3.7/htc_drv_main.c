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
if ( ( V_37 -> type == V_40 ) && V_39 -> V_41 )
V_3 -> V_42 = true ;
if ( V_39 -> V_43 ) {
V_3 -> V_44 = true ;
V_3 -> V_42 = true ;
}
}
static void F_14 ( struct V_2 * V_3 )
{
V_3 -> V_44 = false ;
V_3 -> V_42 = false ;
F_15 ( V_3 -> V_45 ,
F_13 , V_3 ) ;
if ( V_3 -> V_44 )
F_16 ( V_3 ) ;
if ( V_3 -> V_42 ) {
F_7 ( V_3 ) ;
F_17 ( V_3 ) ;
F_8 ( V_3 ) ;
}
}
static void F_18 ( void * V_34 , T_1 * V_35 , struct V_36 * V_37 )
{
struct V_46 * V_47 = V_34 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
V_47 -> V_50 [ V_48 ] &= ~ ( V_47 -> V_51 [ V_48 ] ^ V_35 [ V_48 ] ) ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_46 V_47 ;
V_47 . V_51 = V_53 -> V_54 ;
memset ( & V_47 . V_50 , 0xff , V_49 ) ;
if ( V_37 )
F_18 ( & V_47 , V_37 -> V_55 , V_37 ) ;
F_15 ( V_3 -> V_45 , F_18 ,
& V_47 ) ;
memcpy ( V_53 -> V_56 , V_47 . V_50 , V_49 ) ;
F_21 ( V_53 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
if ( V_3 -> V_57 )
V_3 -> V_22 -> V_58 = V_59 ;
else if ( V_3 -> V_60 )
V_3 -> V_22 -> V_58 = V_40 ;
else
V_3 -> V_22 -> V_58 = V_61 ;
F_23 ( V_3 -> V_22 ) ;
}
void F_24 ( struct V_2 * V_3 )
{
struct V_62 * V_22 = V_3 -> V_22 ;
struct V_52 * V_53 = F_20 ( V_22 ) ;
struct V_63 * V_64 = V_3 -> V_45 -> V_65 . V_64 ;
struct V_66 * V_67 = NULL ;
enum V_1 V_6 ;
T_2 V_68 ;
T_1 V_69 ;
int V_20 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
F_25 ( V_3 ) ;
F_26 ( V_3 -> V_45 ) ;
F_27 ( & V_3 -> V_71 . V_72 ) ;
F_28 ( V_3 ) ;
F_29 ( V_73 ) ;
F_29 ( V_74 ) ;
F_29 ( V_75 ) ;
F_30 ( V_3 ) ;
V_67 = & V_3 -> V_67 ;
V_20 = F_31 ( V_22 , V_22 -> V_76 , V_67 , false ) ;
if ( V_20 ) {
F_32 ( V_53 ,
L_1 ,
V_64 -> V_77 , V_20 ) ;
}
F_33 ( V_22 , V_3 -> V_78 , V_3 -> V_79 ,
& V_3 -> V_78 ) ;
F_29 ( V_80 ) ;
F_34 ( V_3 ) ;
V_6 = F_1 ( V_3 , V_22 -> V_76 ) ;
V_68 = F_35 ( V_6 ) ;
F_36 ( V_81 , & V_68 ) ;
F_29 ( V_82 ) ;
F_37 ( V_3 -> V_83 ) ;
F_14 ( V_3 ) ;
F_38 ( V_3 -> V_45 ) ;
F_39 ( & V_3 -> V_71 . V_72 ,
V_84 + F_40 ( V_85 ) ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_86 * V_45 ,
struct V_4 * V_87 )
{
struct V_62 * V_22 = V_3 -> V_22 ;
struct V_52 * V_53 = F_20 ( V_22 ) ;
struct V_88 * V_65 = & V_53 -> V_45 -> V_65 ;
bool V_89 ;
struct V_63 * V_64 = V_45 -> V_65 . V_64 ;
struct V_66 * V_67 = NULL ;
enum V_1 V_6 ;
T_2 V_68 ;
T_1 V_69 ;
int V_20 ;
if ( F_42 ( V_90 , & V_3 -> V_91 ) )
return - V_92 ;
V_89 = ! ! ( V_45 -> V_65 . V_93 & V_94 ) ;
F_7 ( V_3 ) ;
F_27 ( & V_3 -> V_71 . V_72 ) ;
F_28 ( V_3 ) ;
F_29 ( V_73 ) ;
F_29 ( V_74 ) ;
F_29 ( V_75 ) ;
F_30 ( V_3 ) ;
F_43 ( V_53 , V_95 ,
L_2 ,
V_3 -> V_22 -> V_76 -> V_64 ,
V_64 -> V_77 , F_44 ( V_65 ) , F_45 ( V_65 ) ,
V_89 ) ;
if ( ! V_89 )
V_67 = & V_3 -> V_67 ;
V_20 = F_31 ( V_22 , V_87 , V_67 , V_89 ) ;
if ( V_20 ) {
F_32 ( V_53 ,
L_3 ,
V_64 -> V_77 , V_20 ) ;
goto V_96;
}
F_33 ( V_22 , V_3 -> V_78 , V_3 -> V_79 ,
& V_3 -> V_78 ) ;
F_29 ( V_80 ) ;
if ( V_20 )
goto V_96;
F_34 ( V_3 ) ;
V_6 = F_1 ( V_3 , V_87 ) ;
V_68 = F_35 ( V_6 ) ;
F_36 ( V_81 , & V_68 ) ;
if ( V_20 )
goto V_96;
F_29 ( V_82 ) ;
if ( V_20 )
goto V_96;
F_37 ( V_3 -> V_83 ) ;
if ( ! F_42 ( V_97 , & V_3 -> V_91 ) &&
! ( V_45 -> V_65 . V_93 & V_94 ) )
F_14 ( V_3 ) ;
F_39 ( & V_3 -> V_71 . V_72 ,
V_84 + F_40 ( V_85 ) ) ;
V_96:
F_8 ( V_3 ) ;
return V_20 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_98 V_99 ;
int V_20 = 0 ;
T_1 V_69 ;
memset ( & V_99 , 0 , sizeof( struct V_98 ) ) ;
memcpy ( & V_99 . V_100 , V_53 -> V_54 , V_49 ) ;
V_99 . V_101 = V_3 -> V_102 ;
F_36 ( V_103 , & V_99 ) ;
if ( V_20 ) {
F_32 ( V_53 , L_4 ,
V_3 -> V_102 ) ;
}
V_3 -> V_104 -- ;
V_3 -> V_105 &= ~ ( 1 << V_3 -> V_102 ) ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_98 V_99 ;
struct V_106 V_107 ;
int V_20 = 0 , V_108 ;
T_1 V_69 ;
if ( ( V_3 -> V_104 >= V_109 ) ||
( V_3 -> V_110 >= V_111 ) ) {
V_20 = - V_112 ;
goto V_113;
}
V_108 = F_48 ( V_3 -> V_114 ) ;
if ( ( V_108 < 0 ) || ( V_108 > V_111 ) ) {
V_20 = - V_112 ;
goto V_113;
}
memset ( & V_99 , 0 , sizeof( struct V_98 ) ) ;
memcpy ( & V_99 . V_100 , V_53 -> V_54 , V_49 ) ;
V_99 . V_58 = V_115 ;
V_99 . V_101 = F_48 ( V_3 -> V_105 ) ;
F_36 ( V_116 , & V_99 ) ;
if ( V_20 )
goto V_113;
V_3 -> V_102 = V_99 . V_101 ;
V_3 -> V_105 |= ( 1 << V_99 . V_101 ) ;
if ( ! V_3 -> V_104 )
V_3 -> V_22 -> V_58 = V_117 ;
V_3 -> V_104 ++ ;
memset ( & V_107 , 0 , sizeof( struct V_106 ) ) ;
memcpy ( & V_107 . V_54 , V_53 -> V_54 , V_49 ) ;
V_107 . V_118 = 1 ;
V_107 . V_119 = V_108 ;
V_107 . V_120 = V_99 . V_101 ;
V_107 . V_121 = F_35 ( 0xffff ) ;
F_36 ( V_122 , & V_107 ) ;
if ( V_20 ) {
F_32 ( V_53 , L_5 ) ;
goto V_123;
}
V_3 -> V_114 |= ( 1 << V_108 ) ;
V_3 -> V_110 ++ ;
V_3 -> V_124 [ V_3 -> V_102 ] = V_108 ;
V_3 -> V_22 -> V_125 = true ;
F_43 ( V_53 , V_95 ,
L_6 ,
V_3 -> V_102 , V_108 ) ;
return 0 ;
V_123:
F_46 ( V_3 ) ;
V_113:
F_43 ( V_53 , V_126 , L_7 ) ;
return V_20 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
int V_20 = 0 ;
T_1 V_69 , V_108 ;
F_46 ( V_3 ) ;
V_108 = V_3 -> V_124 [ V_3 -> V_102 ] ;
F_36 ( V_127 , & V_108 ) ;
if ( V_20 ) {
F_32 ( V_53 , L_8 ) ;
return V_20 ;
}
V_3 -> V_114 &= ~ ( 1 << V_108 ) ;
V_3 -> V_110 -- ;
V_3 -> V_22 -> V_125 = false ;
F_43 ( V_53 , V_95 ,
L_9 ,
V_3 -> V_102 , V_108 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_128 * V_129 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_106 V_107 ;
struct V_130 * V_131 = (struct V_130 * ) V_37 -> V_132 ;
struct V_133 * V_134 ;
int V_20 , V_108 ;
T_1 V_69 ;
T_3 V_121 ;
if ( V_3 -> V_110 >= V_111 )
return - V_112 ;
V_108 = F_48 ( V_3 -> V_114 ) ;
if ( ( V_108 < 0 ) || ( V_108 > V_111 ) )
return - V_112 ;
memset ( & V_107 , 0 , sizeof( struct V_106 ) ) ;
if ( V_129 ) {
V_134 = (struct V_133 * ) V_129 -> V_132 ;
memcpy ( & V_107 . V_54 , V_129 -> V_55 , V_49 ) ;
memcpy ( & V_107 . V_135 , V_53 -> V_136 , V_49 ) ;
V_134 -> V_101 = V_108 ;
V_107 . V_118 = 0 ;
V_121 = 1 << ( V_137 +
V_129 -> V_138 . V_139 ) ;
V_107 . V_121 = F_35 ( V_121 ) ;
} else {
memcpy ( & V_107 . V_54 , V_37 -> V_55 , V_49 ) ;
V_107 . V_118 = 1 ;
V_107 . V_121 = F_35 ( 0xffff ) ;
}
V_107 . V_119 = V_108 ;
V_107 . V_120 = V_131 -> V_101 ;
F_36 ( V_122 , & V_107 ) ;
if ( V_20 ) {
if ( V_129 )
F_32 ( V_53 ,
L_10 ,
V_129 -> V_55 ) ;
return V_20 ;
}
if ( V_129 ) {
F_43 ( V_53 , V_95 ,
L_11 ,
V_129 -> V_55 , V_107 . V_119 ) ;
} else {
F_43 ( V_53 , V_95 ,
L_12 ,
V_131 -> V_101 , V_107 . V_119 ) ;
}
V_3 -> V_114 |= ( 1 << V_108 ) ;
V_3 -> V_110 ++ ;
if ( ! V_129 )
V_3 -> V_124 [ V_131 -> V_101 ] = V_108 ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_128 * V_129 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_130 * V_131 = (struct V_130 * ) V_37 -> V_132 ;
struct V_133 * V_134 ;
int V_20 ;
T_1 V_69 , V_108 ;
if ( V_129 ) {
V_134 = (struct V_133 * ) V_129 -> V_132 ;
V_108 = V_134 -> V_101 ;
} else {
V_108 = V_3 -> V_124 [ V_131 -> V_101 ] ;
}
F_36 ( V_127 , & V_108 ) ;
if ( V_20 ) {
if ( V_129 )
F_32 ( V_53 ,
L_13 ,
V_129 -> V_55 ) ;
return V_20 ;
}
if ( V_129 ) {
F_43 ( V_53 , V_95 ,
L_14 ,
V_129 -> V_55 , V_108 ) ;
} else {
F_43 ( V_53 , V_95 ,
L_15 ,
V_131 -> V_101 , V_108 ) ;
}
V_3 -> V_114 &= ~ ( 1 << V_108 ) ;
V_3 -> V_110 -- ;
return 0 ;
}
int F_52 ( struct V_2 * V_3 ,
T_1 V_140 )
{
struct V_141 V_142 ;
int V_20 ;
T_1 V_69 ;
memset ( & V_142 , 0 , sizeof( struct V_141 ) ) ;
V_142 . V_143 = F_53 ( 0xffff ) ;
V_142 . V_144 = 0xff ;
V_142 . V_140 = V_140 ;
V_142 . V_145 = V_3 -> V_22 -> V_146 . V_145 ;
F_36 ( V_147 , & V_142 ) ;
return V_20 ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_128 * V_129 ,
struct V_148 * V_149 )
{
struct V_133 * V_134 = (struct V_133 * ) V_129 -> V_132 ;
struct V_150 * V_151 ;
T_4 V_146 = 0 ;
int V_48 , V_152 ;
V_151 = V_3 -> V_45 -> V_153 -> V_154 [ V_3 -> V_45 -> V_65 . V_64 -> V_155 ] ;
for ( V_48 = 0 , V_152 = 0 ; V_48 < V_151 -> V_156 ; V_48 ++ ) {
if ( V_129 -> V_157 [ V_151 -> V_155 ] & F_55 ( V_48 ) ) {
V_149 -> V_158 . V_159 . V_160 [ V_152 ]
= ( V_151 -> V_161 [ V_48 ] . V_162 * 2 ) / 10 ;
V_152 ++ ;
}
}
V_149 -> V_158 . V_159 . V_163 = V_152 ;
if ( V_129 -> V_138 . V_164 ) {
for ( V_48 = 0 , V_152 = 0 ; V_48 < 77 ; V_48 ++ ) {
if ( V_129 -> V_138 . V_165 . V_166 [ V_48 / 8 ] & ( 1 << ( V_48 % 8 ) ) )
V_149 -> V_158 . V_167 . V_160 [ V_152 ++ ] = V_48 ;
if ( V_152 == V_168 )
break;
}
V_149 -> V_158 . V_167 . V_163 = V_152 ;
V_146 = V_169 ;
if ( V_129 -> V_138 . V_165 . V_166 [ 1 ] )
V_146 |= V_170 ;
if ( ( V_129 -> V_138 . V_171 & V_172 ) &&
( F_45 ( & V_3 -> V_45 -> V_65 ) ) )
V_146 |= V_173 ;
if ( F_45 ( & V_3 -> V_45 -> V_65 ) &&
( V_129 -> V_138 . V_171 & V_174 ) )
V_146 |= V_175 ;
else if ( F_56 ( & V_3 -> V_45 -> V_65 ) &&
( V_129 -> V_138 . V_171 & V_176 ) )
V_146 |= V_175 ;
}
V_149 -> V_119 = V_134 -> V_101 ;
V_149 -> V_177 = 1 ;
V_149 -> V_178 = F_53 ( V_146 ) ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_148 * V_149 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
int V_20 ;
T_1 V_69 ;
F_36 ( V_179 , V_149 ) ;
if ( V_20 ) {
F_32 ( V_53 ,
L_16 ) ;
}
return V_20 ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_128 * V_129 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_148 V_149 ;
int V_20 ;
memset ( & V_149 , 0 , sizeof( struct V_148 ) ) ;
F_54 ( V_3 , V_129 , & V_149 ) ;
V_20 = F_57 ( V_3 , & V_149 ) ;
if ( ! V_20 )
F_43 ( V_53 , V_95 ,
L_17 ,
V_129 -> V_55 , F_59 ( V_149 . V_178 ) ) ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_148 V_149 ;
struct V_128 * V_129 ;
int V_20 ;
memset ( & V_149 , 0 , sizeof( struct V_148 ) ) ;
F_61 () ;
V_129 = F_62 ( V_37 , V_39 -> V_135 ) ;
if ( ! V_129 ) {
F_63 () ;
return;
}
F_54 ( V_3 , V_129 , & V_149 ) ;
F_63 () ;
V_20 = F_57 ( V_3 , & V_149 ) ;
if ( ! V_20 )
F_43 ( V_53 , V_95 ,
L_17 ,
V_39 -> V_135 , F_59 ( V_149 . V_178 ) ) ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_128 * V_129 ,
enum V_180 V_181 ,
T_3 V_182 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_183 V_184 ;
struct V_133 * V_134 ;
int V_20 = 0 ;
T_1 V_69 ;
if ( V_182 >= V_185 )
return - V_7 ;
memset ( & V_184 , 0 , sizeof( struct V_183 ) ) ;
V_134 = (struct V_133 * ) V_129 -> V_132 ;
V_184 . V_119 = V_134 -> V_101 ;
V_184 . V_186 = V_182 & 0xf ;
V_184 . V_187 = ( V_181 == V_188 ) ? true : false ;
F_36 ( V_189 , & V_184 ) ;
if ( V_20 )
F_43 ( V_53 , V_95 ,
L_18 ,
( V_184 . V_187 ) ? L_19 : L_20 , V_129 -> V_55 , V_182 ) ;
else
F_43 ( V_53 , V_95 ,
L_21 ,
( V_184 . V_187 ) ? L_22 : L_23 ,
V_129 -> V_55 , V_182 ) ;
F_65 ( & V_3 -> V_71 . V_190 ) ;
V_134 -> V_191 [ V_182 ] = ( V_184 . V_187 && ! V_20 ) ? V_192 : V_193 ;
F_66 ( & V_3 -> V_71 . V_190 ) ;
return V_20 ;
}
void F_16 ( struct V_2 * V_3 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
unsigned long V_194 = F_67 ( V_84 ) ;
V_53 -> V_195 . V_196 = V_194 ;
V_53 -> V_195 . V_197 = V_194 ;
V_53 -> V_195 . V_198 = V_194 ;
F_68 ( V_199 , & V_3 -> V_91 ) ;
F_69 ( V_53 -> V_45 , & V_3 -> V_200 ,
F_40 ( V_201 ) ) ;
}
void F_25 ( struct V_2 * V_3 )
{
F_70 ( & V_3 -> V_200 ) ;
F_71 ( V_199 , & V_3 -> V_91 ) ;
}
void F_72 ( struct V_31 * V_32 )
{
struct V_2 * V_3 =
F_12 ( V_32 , struct V_2 , V_200 . V_32 ) ;
struct V_62 * V_22 = V_3 -> V_22 ;
struct V_52 * V_53 = F_20 ( V_22 ) ;
bool V_202 = false ;
bool V_203 = false ;
bool V_204 = false ;
unsigned int V_194 = F_67 ( V_84 ) ;
T_4 V_205 , V_206 ;
V_206 = ( V_22 -> V_58 == V_40 ) ?
V_207 : V_208 ;
if ( V_22 -> V_209 != V_25 )
goto V_210;
if ( ( V_194 - V_53 -> V_195 . V_196 ) >= V_211 ) {
V_202 = true ;
F_43 ( V_53 , V_212 , L_24 , V_84 ) ;
V_53 -> V_195 . V_196 = V_194 ;
}
if ( ! V_53 -> V_195 . V_213 ) {
if ( ( V_194 - V_53 -> V_195 . V_197 ) >=
V_206 ) {
V_203 = true ;
F_43 ( V_53 , V_212 , L_25 , V_84 ) ;
V_53 -> V_195 . V_197 = V_194 ;
V_53 -> V_195 . V_214 = V_194 ;
}
} else {
if ( ( V_194 - V_53 -> V_195 . V_214 ) >=
V_215 ) {
V_53 -> V_195 . V_213 = F_73 ( V_22 ) ;
if ( V_53 -> V_195 . V_213 )
V_53 -> V_195 . V_214 = V_194 ;
}
}
if ( V_22 -> V_216 . V_217 &&
( V_194 - V_53 -> V_195 . V_198 ) >= V_201 ) {
V_204 = true ;
V_53 -> V_195 . V_198 = V_194 ;
}
if ( V_202 || V_203 || V_204 ) {
F_7 ( V_3 ) ;
if ( V_204 )
F_74 ( V_22 , V_22 -> V_76 ) ;
if ( V_202 || V_203 )
V_53 -> V_195 . V_213 =
F_75 ( V_22 , V_22 -> V_76 ,
V_22 -> V_218 , V_202 ) ;
F_8 ( V_3 ) ;
}
V_210:
V_205 = V_211 ;
if ( V_22 -> V_216 . V_217 )
V_205 = F_76 ( V_205 , ( T_4 ) V_201 ) ;
if ( ! V_53 -> V_195 . V_213 )
V_205 = F_76 ( V_205 , ( T_4 ) V_206 ) ;
F_69 ( V_53 -> V_45 , & V_3 -> V_200 ,
F_40 ( V_205 ) ) ;
}
static void F_77 ( struct V_86 * V_45 ,
struct V_219 * V_220 ,
struct V_221 * V_222 )
{
struct V_223 * V_224 ;
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
int V_225 , V_226 , V_20 , V_227 ;
V_224 = (struct V_223 * ) V_222 -> V_34 ;
V_225 = F_78 ( V_224 -> V_228 ) ;
V_226 = V_225 & 3 ;
if ( V_226 && V_222 -> V_229 > V_225 ) {
if ( F_79 ( V_222 ) < V_226 ) {
F_43 ( V_53 , V_230 , L_26 ) ;
goto V_231;
}
F_80 ( V_222 , V_226 ) ;
memmove ( V_222 -> V_34 , V_222 -> V_34 + V_226 , V_225 ) ;
}
V_227 = F_81 ( V_3 ) ;
if ( V_227 < 0 ) {
F_43 ( V_53 , V_230 , L_27 ) ;
goto V_231;
}
V_20 = F_82 ( V_3 , V_220 -> V_129 , V_222 , V_227 , false ) ;
if ( V_20 != 0 ) {
F_43 ( V_53 , V_230 , L_28 ) ;
goto V_232;
}
F_83 ( V_3 ) ;
return;
V_232:
F_84 ( V_3 , V_227 ) ;
V_231:
F_85 ( V_222 ) ;
}
static int F_86 ( struct V_86 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_62 * V_22 = V_3 -> V_22 ;
struct V_52 * V_53 = F_20 ( V_22 ) ;
struct V_63 * V_76 = V_45 -> V_65 . V_64 ;
struct V_4 * V_233 ;
int V_20 = 0 ;
enum V_1 V_6 ;
T_2 V_68 ;
T_1 V_69 ;
F_4 ( & V_3 -> V_70 ) ;
F_43 ( V_53 , V_95 ,
L_29 ,
V_76 -> V_77 ) ;
F_3 ( V_3 , V_25 ) ;
F_29 ( V_234 ) ;
V_233 = F_87 ( V_45 , V_22 ) ;
V_20 = F_31 ( V_22 , V_233 , V_22 -> V_67 , false ) ;
if ( V_20 ) {
F_32 ( V_53 ,
L_30 ,
V_20 , V_76 -> V_77 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_20 ;
}
F_33 ( V_22 , V_3 -> V_78 , V_3 -> V_79 ,
& V_3 -> V_78 ) ;
V_6 = F_1 ( V_3 , V_233 ) ;
V_68 = F_35 ( V_6 ) ;
F_36 ( V_81 , & V_68 ) ;
F_29 ( V_235 ) ;
F_29 ( V_80 ) ;
F_34 ( V_3 ) ;
V_20 = F_52 ( V_3 , 0 ) ;
if ( V_20 )
F_43 ( V_53 , V_95 ,
L_31 ) ;
F_71 ( V_90 , & V_3 -> V_91 ) ;
F_37 ( V_3 -> V_83 ) ;
F_65 ( & V_3 -> V_71 . V_190 ) ;
V_3 -> V_71 . V_93 &= ~ V_236 ;
F_66 ( & V_3 -> V_71 . V_190 ) ;
F_38 ( V_45 ) ;
F_39 ( & V_3 -> V_71 . V_72 ,
V_84 + F_40 ( V_85 ) ) ;
F_88 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_20 ;
}
static void F_89 ( struct V_86 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_62 * V_22 = V_3 -> V_22 ;
struct V_52 * V_53 = F_20 ( V_22 ) ;
int V_20 V_237 ( ( V_238 ) ) ;
T_1 V_69 ;
F_4 ( & V_3 -> V_70 ) ;
if ( F_42 ( V_90 , & V_3 -> V_91 ) ) {
F_43 ( V_53 , V_239 , L_32 ) ;
F_6 ( & V_3 -> V_70 ) ;
return;
}
F_7 ( V_3 ) ;
F_29 ( V_73 ) ;
F_29 ( V_74 ) ;
F_29 ( V_75 ) ;
F_90 ( & V_3 -> V_240 ) ;
F_27 ( & V_3 -> V_71 . V_72 ) ;
F_28 ( V_3 ) ;
F_30 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
F_91 ( & V_3 -> V_241 ) ;
F_91 ( & V_3 -> V_33 ) ;
#ifdef F_92
F_91 ( & V_3 -> V_242 ) ;
#endif
F_25 ( V_3 ) ;
F_4 ( & V_3 -> V_70 ) ;
F_93 ( V_3 ) ;
if ( V_3 -> V_22 -> V_125 )
F_49 ( V_3 ) ;
F_94 ( V_22 ) ;
F_95 ( V_22 ) ;
F_8 ( V_3 ) ;
F_3 ( V_3 , V_28 ) ;
F_68 ( V_90 , & V_3 -> V_91 ) ;
F_43 ( V_53 , V_95 , L_33 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static int F_96 ( struct V_86 * V_45 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_130 * V_131 = ( void * ) V_37 -> V_132 ;
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_98 V_99 ;
int V_20 = 0 ;
T_1 V_69 ;
F_4 ( & V_3 -> V_70 ) ;
if ( V_3 -> V_104 >= V_109 ) {
F_6 ( & V_3 -> V_70 ) ;
return - V_112 ;
}
if ( V_3 -> V_57 ||
( V_3 -> V_104 && V_37 -> type == V_59 ) ) {
F_32 ( V_53 , L_34 ) ;
F_6 ( & V_3 -> V_70 ) ;
return - V_112 ;
}
if ( ( ( V_37 -> type == V_40 ) ||
( V_37 -> type == V_59 ) ) &&
( ( V_3 -> V_60 + V_3 -> V_57 ) >= V_243 ) ) {
F_32 ( V_53 , L_35 ) ;
F_6 ( & V_3 -> V_70 ) ;
return - V_112 ;
}
F_7 ( V_3 ) ;
memset ( & V_99 , 0 , sizeof( struct V_98 ) ) ;
memcpy ( & V_99 . V_100 , V_37 -> V_55 , V_49 ) ;
switch ( V_37 -> type ) {
case V_61 :
V_99 . V_58 = V_244 ;
break;
case V_59 :
V_99 . V_58 = V_245 ;
break;
case V_40 :
V_99 . V_58 = V_246 ;
break;
default:
F_32 ( V_53 ,
L_36 , V_37 -> type ) ;
V_20 = - V_247 ;
goto V_248;
}
V_131 -> V_101 = V_99 . V_101 = F_48 ( V_3 -> V_105 ) ;
V_99 . V_249 = F_35 ( 2304 ) ;
F_36 ( V_116 , & V_99 ) ;
if ( V_20 )
goto V_248;
V_20 = F_50 ( V_3 , V_37 , NULL ) ;
if ( V_20 ) {
F_36 ( V_103 , & V_99 ) ;
goto V_248;
}
F_19 ( V_3 , V_37 ) ;
V_3 -> V_105 |= ( 1 << V_131 -> V_101 ) ;
V_3 -> V_104 ++ ;
F_97 ( V_3 , V_37 -> type ) ;
if ( ( V_37 -> type == V_40 ) ||
( V_37 -> type == V_59 ) )
F_98 ( V_3 , V_37 ) ;
F_22 ( V_3 ) ;
if ( ( V_3 -> V_22 -> V_58 == V_40 ) &&
! F_42 ( V_199 , & V_3 -> V_91 ) ) {
F_99 ( V_3 -> V_22 , true ) ;
F_16 ( V_3 ) ;
}
F_43 ( V_53 , V_95 , L_37 ,
V_37 -> type , V_131 -> V_101 ) ;
V_248:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_20 ;
}
static void F_100 ( struct V_86 * V_45 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_130 * V_131 = ( void * ) V_37 -> V_132 ;
struct V_98 V_99 ;
int V_20 = 0 ;
T_1 V_69 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
memset ( & V_99 , 0 , sizeof( struct V_98 ) ) ;
memcpy ( & V_99 . V_100 , V_37 -> V_55 , V_49 ) ;
V_99 . V_101 = V_131 -> V_101 ;
F_36 ( V_103 , & V_99 ) ;
if ( V_20 ) {
F_32 ( V_53 , L_38 ,
V_131 -> V_101 ) ;
}
V_3 -> V_104 -- ;
V_3 -> V_105 &= ~ ( 1 << V_131 -> V_101 ) ;
F_51 ( V_3 , V_37 , NULL ) ;
F_101 ( V_3 , V_37 -> type ) ;
if ( ( V_37 -> type == V_40 ) ||
( V_37 -> type == V_59 ) )
F_102 ( V_3 , V_37 ) ;
F_22 ( V_3 ) ;
F_19 ( V_3 , V_37 ) ;
if ( ( V_37 -> type == V_40 ) && ( V_3 -> V_60 == 0 ) ) {
V_3 -> V_44 = false ;
F_15 ( V_3 -> V_45 ,
F_13 , V_3 ) ;
if ( ! V_3 -> V_44 )
F_25 ( V_3 ) ;
}
F_43 ( V_53 , V_95 , L_39 , V_131 -> V_101 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static int F_103 ( struct V_86 * V_45 , T_4 V_250 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_88 * V_65 = & V_45 -> V_65 ;
bool V_251 = false ;
int V_20 = 0 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
if ( V_250 & V_252 ) {
F_4 ( & V_3 -> V_21 ) ;
V_3 -> V_27 = ! ! ( V_65 -> V_93 & V_253 ) ;
if ( V_3 -> V_27 )
V_251 = true ;
F_6 ( & V_3 -> V_21 ) ;
}
if ( V_250 & V_254 ) {
if ( ( V_65 -> V_93 & V_255 ) &&
! V_3 -> V_22 -> V_125 )
F_47 ( V_3 ) ;
else if ( V_3 -> V_22 -> V_125 )
F_49 ( V_3 ) ;
}
if ( ( V_250 & V_256 ) || V_251 ) {
struct V_63 * V_76 = V_45 -> V_65 . V_64 ;
int V_257 = V_76 -> V_258 ;
F_43 ( V_53 , V_95 , L_40 ,
V_76 -> V_77 ) ;
F_104 ( & V_3 -> V_22 -> V_259 [ V_257 ] ,
V_45 -> V_65 . V_64 ,
V_45 -> V_65 . V_260 ) ;
if ( F_41 ( V_3 , V_45 , & V_3 -> V_22 -> V_259 [ V_257 ] ) < 0 ) {
F_32 ( V_53 , L_41 ) ;
V_20 = - V_7 ;
goto V_248;
}
}
if ( V_250 & V_261 ) {
if ( V_65 -> V_93 & V_262 ) {
F_3 ( V_3 , V_30 ) ;
V_3 -> V_29 = true ;
} else {
V_3 -> V_29 = false ;
F_91 ( & V_3 -> V_33 ) ;
F_3 ( V_3 , V_25 ) ;
}
}
if ( V_250 & V_263 ) {
V_3 -> V_79 = 2 * V_65 -> V_264 ;
F_33 ( V_3 -> V_22 , V_3 -> V_78 ,
V_3 -> V_79 , & V_3 -> V_78 ) ;
}
V_248:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_20 ;
}
static void F_105 ( struct V_86 * V_45 ,
unsigned int V_265 ,
unsigned int * V_266 ,
T_5 V_267 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
T_4 V_268 ;
F_4 ( & V_3 -> V_70 ) ;
V_265 &= V_269 ;
* V_266 &= V_269 ;
if ( F_42 ( V_90 , & V_3 -> V_91 ) ) {
F_43 ( F_20 ( V_3 -> V_22 ) , V_239 ,
L_42 ) ;
F_6 ( & V_3 -> V_70 ) ;
return;
}
F_7 ( V_3 ) ;
V_3 -> V_270 = * V_266 ;
V_268 = F_106 ( V_3 ) ;
F_107 ( V_3 -> V_22 , V_268 ) ;
F_43 ( F_20 ( V_3 -> V_22 ) , V_95 , L_43 ,
V_268 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static int F_108 ( struct V_86 * V_45 ,
struct V_36 * V_37 ,
struct V_128 * V_129 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
int V_20 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
V_20 = F_50 ( V_3 , V_37 , V_129 ) ;
if ( ! V_20 )
F_58 ( V_3 , V_129 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_20 ;
}
static int F_109 ( struct V_86 * V_45 ,
struct V_36 * V_37 ,
struct V_128 * V_129 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_133 * V_134 ;
int V_20 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
V_134 = (struct V_133 * ) V_129 -> V_132 ;
F_110 ( V_3 -> V_83 , V_134 -> V_101 ) ;
V_20 = F_51 ( V_3 , V_37 , V_129 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_20 ;
}
static void F_111 ( struct V_86 * V_45 ,
struct V_36 * V_37 ,
struct V_128 * V_129 , T_4 V_250 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_148 V_149 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
if ( V_250 & V_271 ) {
memset ( & V_149 , 0 , sizeof( struct V_148 ) ) ;
F_54 ( V_3 , V_129 , & V_149 ) ;
if ( ! F_57 ( V_3 , & V_149 ) )
F_43 ( V_53 , V_95 ,
L_44 ,
V_129 -> V_55 , F_59 ( V_149 . V_178 ) ) ;
else
F_43 ( V_53 , V_95 ,
L_45 ,
V_129 -> V_55 ) ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static int F_112 ( struct V_86 * V_45 ,
struct V_36 * V_37 , T_3 V_272 ,
const struct V_273 * V_274 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_275 V_276 ;
int V_20 = 0 , V_277 ;
if ( V_272 >= V_278 )
return 0 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
memset ( & V_276 , 0 , sizeof( struct V_275 ) ) ;
V_276 . V_279 = V_274 -> V_280 ;
V_276 . V_281 = V_274 -> V_282 ;
V_276 . V_283 = V_274 -> V_284 ;
V_276 . V_285 = V_274 -> V_286 * 32 ;
V_277 = F_113 ( V_272 , V_3 -> V_287 ) ;
F_43 ( V_53 , V_95 ,
L_46 ,
V_272 , V_277 , V_274 -> V_280 , V_274 -> V_282 ,
V_274 -> V_284 , V_274 -> V_286 ) ;
V_20 = F_114 ( V_3 , V_277 , & V_276 ) ;
if ( V_20 ) {
F_32 ( V_53 , L_47 ) ;
goto V_248;
}
if ( ( V_3 -> V_22 -> V_58 == V_59 ) &&
( V_277 == V_3 -> V_287 [ V_288 ] ) )
F_115 ( V_3 ) ;
V_248:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_20 ;
}
static int F_116 ( struct V_86 * V_45 ,
enum V_289 V_290 ,
struct V_36 * V_37 ,
struct V_128 * V_129 ,
struct V_291 * V_292 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
int V_20 = 0 ;
if ( V_293 )
return - V_294 ;
if ( ( V_37 -> type == V_59 ||
V_37 -> type == V_295 ) &&
( V_292 -> V_296 == V_297 ||
V_292 -> V_296 == V_298 ) &&
! ( V_292 -> V_93 & V_299 ) ) {
return - V_247 ;
}
F_4 ( & V_3 -> V_70 ) ;
F_43 ( V_53 , V_95 , L_48 ) ;
F_7 ( V_3 ) ;
switch ( V_290 ) {
case V_300 :
V_20 = F_117 ( V_53 , V_37 , V_129 , V_292 ) ;
if ( V_20 >= 0 ) {
V_292 -> V_301 = V_20 ;
V_292 -> V_93 |= V_302 ;
if ( V_292 -> V_296 == V_297 )
V_292 -> V_93 |= V_303 ;
if ( V_3 -> V_22 -> V_304 &&
V_292 -> V_296 == V_298 )
V_292 -> V_93 |= V_305 ;
V_20 = 0 ;
}
break;
case V_306 :
F_118 ( V_53 , V_292 ) ;
break;
default:
V_20 = - V_7 ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_20 ;
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
F_120 ( V_3 -> V_22 ) ;
F_43 ( V_53 , V_95 , L_49 ,
V_53 -> V_136 , V_53 -> V_307 ) ;
}
static void F_121 ( void * V_34 , T_1 * V_35 , struct V_36 * V_37 )
{
struct V_2 * V_3 = (struct V_2 * ) V_34 ;
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_38 * V_39 = & V_37 -> V_39 ;
if ( ( V_37 -> type == V_61 ) && V_39 -> V_43 ) {
V_53 -> V_307 = V_39 -> V_308 ;
memcpy ( V_53 -> V_136 , V_39 -> V_135 , V_49 ) ;
}
}
static void F_122 ( struct V_2 * V_3 )
{
if ( V_3 -> V_309 == 1 ) {
F_15 ( V_3 -> V_45 ,
F_121 , V_3 ) ;
F_119 ( V_3 ) ;
}
}
static void F_123 ( struct V_86 * V_45 ,
struct V_36 * V_37 ,
struct V_38 * V_39 ,
T_4 V_250 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_62 * V_22 = V_3 -> V_22 ;
struct V_52 * V_53 = F_20 ( V_22 ) ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
if ( V_250 & V_310 ) {
F_43 ( V_53 , V_95 , L_50 ,
V_39 -> V_43 ) ;
V_39 -> V_43 ?
V_3 -> V_309 ++ : V_3 -> V_309 -- ;
if ( V_3 -> V_22 -> V_58 == V_61 ) {
F_122 ( V_3 ) ;
if ( V_39 -> V_43 && ( V_3 -> V_309 == 1 ) )
F_16 ( V_3 ) ;
else if ( V_3 -> V_309 == 0 )
F_25 ( V_3 ) ;
}
}
if ( V_250 & V_311 ) {
if ( V_3 -> V_22 -> V_58 == V_59 ) {
V_53 -> V_307 = V_39 -> V_308 ;
memcpy ( V_53 -> V_136 , V_39 -> V_135 , V_49 ) ;
F_119 ( V_3 ) ;
}
}
if ( ( V_250 & V_312 ) && V_39 -> V_41 ) {
F_43 ( V_53 , V_95 , L_51 ,
V_39 -> V_135 ) ;
F_124 ( V_3 , V_37 ) ;
F_68 ( V_313 , & V_3 -> V_91 ) ;
F_125 ( V_3 , V_37 ) ;
}
if ( ( V_250 & V_312 ) && ! V_39 -> V_41 ) {
if ( ( V_3 -> V_60 <= 1 ) || V_3 -> V_57 ) {
F_43 ( V_53 , V_95 ,
L_52 ,
V_39 -> V_135 ) ;
F_71 ( V_313 , & V_3 -> V_91 ) ;
F_125 ( V_3 , V_37 ) ;
}
}
if ( V_250 & V_314 ) {
if ( ( V_3 -> V_22 -> V_58 == V_40 ) &&
( V_3 -> V_104 == 1 ) &&
( V_3 -> V_60 == 1 ) &&
( V_37 -> type == V_40 ) ) {
F_68 ( V_315 , & V_3 -> V_91 ) ;
}
F_43 ( V_53 , V_95 ,
L_53 ,
V_39 -> V_135 ) ;
F_125 ( V_3 , V_37 ) ;
}
if ( V_250 & V_316 ) {
if ( V_39 -> V_317 )
V_22 -> V_318 = 9 ;
else
V_22 -> V_318 = 20 ;
F_126 ( V_22 ) ;
}
if ( V_250 & V_319 )
F_60 ( V_3 , V_37 , V_39 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static T_5 F_127 ( struct V_86 * V_45 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
T_5 V_320 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
V_320 = F_128 ( V_3 -> V_22 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_320 ;
}
static void F_129 ( struct V_86 * V_45 ,
struct V_36 * V_37 , T_5 V_320 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
F_130 ( V_3 -> V_22 , V_320 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static void F_131 ( struct V_86 * V_45 ,
struct V_36 * V_37 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
F_132 ( V_3 -> V_22 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static int F_133 ( struct V_86 * V_45 ,
struct V_36 * V_37 ,
enum V_180 V_181 ,
struct V_128 * V_129 ,
T_3 V_182 , T_3 * V_321 , T_1 V_322 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_133 * V_134 ;
int V_20 = 0 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
switch ( V_181 ) {
case V_323 :
break;
case V_324 :
break;
case V_188 :
V_20 = F_64 ( V_3 , V_37 , V_129 , V_181 , V_182 ) ;
if ( ! V_20 )
F_134 ( V_37 , V_129 -> V_55 , V_182 ) ;
break;
case V_325 :
F_64 ( V_3 , V_37 , V_129 , V_181 , V_182 ) ;
F_135 ( V_37 , V_129 -> V_55 , V_182 ) ;
break;
case V_326 :
V_134 = (struct V_133 * ) V_129 -> V_132 ;
F_65 ( & V_3 -> V_71 . V_190 ) ;
V_134 -> V_191 [ V_182 ] = V_327 ;
F_66 ( & V_3 -> V_71 . V_190 ) ;
break;
default:
F_32 ( F_20 ( V_3 -> V_22 ) , L_54 ) ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
return V_20 ;
}
static void F_136 ( struct V_86 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
F_4 ( & V_3 -> V_70 ) ;
F_65 ( & V_3 -> V_328 ) ;
F_68 ( V_97 , & V_3 -> V_91 ) ;
F_66 ( & V_3 -> V_328 ) ;
F_91 ( & V_3 -> V_33 ) ;
F_25 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static void F_137 ( struct V_86 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
F_4 ( & V_3 -> V_70 ) ;
F_65 ( & V_3 -> V_328 ) ;
F_71 ( V_97 , & V_3 -> V_91 ) ;
F_66 ( & V_3 -> V_328 ) ;
F_7 ( V_3 ) ;
F_14 ( V_3 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static int F_138 ( struct V_86 * V_45 , T_4 V_329 )
{
return 0 ;
}
static void F_139 ( struct V_86 * V_45 ,
T_1 V_330 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
F_4 ( & V_3 -> V_70 ) ;
F_7 ( V_3 ) ;
V_3 -> V_22 -> V_330 = V_330 ;
F_126 ( V_3 -> V_22 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_70 ) ;
}
static int F_140 ( struct V_86 * V_45 ,
struct V_36 * V_37 ,
const struct V_331 * V_50 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_52 * V_53 = F_20 ( V_3 -> V_22 ) ;
struct V_332 V_333 ;
struct V_130 * V_131 = ( void * ) V_37 -> V_132 ;
int V_20 = 0 ;
T_1 V_69 ;
memset ( & V_333 , 0 , sizeof( struct V_332 ) ) ;
V_333 . V_120 = V_131 -> V_101 ;
V_333 . V_155 = V_334 ;
V_333 . V_50 = F_53 ( V_50 -> V_220 [ V_334 ] . V_335 ) ;
F_36 ( V_336 , & V_333 ) ;
if ( V_20 ) {
F_32 ( V_53 ,
L_55
L_56 , V_131 -> V_101 ) ;
goto V_248;
}
V_333 . V_155 = V_337 ;
V_333 . V_50 = F_53 ( V_50 -> V_220 [ V_337 ] . V_335 ) ;
F_36 ( V_336 , & V_333 ) ;
if ( V_20 ) {
F_32 ( V_53 ,
L_57
L_56 , V_131 -> V_101 ) ;
goto V_248;
}
F_43 ( V_53 , V_95 , L_58 ,
V_50 -> V_220 [ V_334 ] . V_335 ,
V_50 -> V_220 [ V_337 ] . V_335 ) ;
V_248:
return V_20 ;
}
static int F_141 ( struct V_86 * V_45 ,
struct V_338 * V_339 )
{
struct V_2 * V_3 = V_45 -> V_3 ;
struct V_62 * V_22 = V_3 -> V_22 ;
struct V_340 * V_341 = & V_22 -> V_342 ;
V_339 -> V_343 = V_341 -> V_344 ;
V_339 -> V_345 = V_341 -> V_346 ;
V_339 -> V_347 = V_341 -> V_348 ;
V_339 -> V_349 = V_341 -> V_350 ;
return 0 ;
}
