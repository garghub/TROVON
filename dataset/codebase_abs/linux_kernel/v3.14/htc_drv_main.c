static enum V_1 F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( F_2 ( V_5 ) )
return V_6 ;
return V_7 ;
}
bool F_3 ( struct V_2 * V_3 ,
enum V_8 V_9 )
{
bool V_10 ;
F_4 ( & V_3 -> V_11 ) ;
V_10 = F_5 ( V_3 -> V_12 , V_9 ) ;
F_6 ( & V_3 -> V_11 ) ;
return V_10 ;
}
void F_7 ( struct V_2 * V_3 )
{
F_4 ( & V_3 -> V_11 ) ;
if ( ++ V_3 -> V_13 != 1 )
goto V_14;
F_5 ( V_3 -> V_12 , V_15 ) ;
V_14:
F_6 ( & V_3 -> V_11 ) ;
}
void F_8 ( struct V_2 * V_3 )
{
bool V_16 ;
F_4 ( & V_3 -> V_11 ) ;
if ( -- V_3 -> V_13 != 0 )
goto V_14;
if ( V_3 -> V_17 ) {
F_9 ( V_3 -> V_12 , true ) ;
F_10 ( V_3 -> V_12 , & V_16 ) ;
F_5 ( V_3 -> V_12 , V_18 ) ;
} else if ( V_3 -> V_19 ) {
F_5 ( V_3 -> V_12 , V_20 ) ;
}
V_14:
F_6 ( & V_3 -> V_11 ) ;
}
void F_11 ( struct V_21 * V_22 )
{
struct V_2 * V_3 =
F_12 ( V_22 , struct V_2 ,
V_23 ) ;
F_3 ( V_3 , V_15 ) ;
F_3 ( V_3 , V_20 ) ;
}
static void F_13 ( void * V_24 , T_1 * V_25 , struct V_26 * V_27 )
{
struct V_2 * V_3 = V_24 ;
struct V_28 * V_29 = & V_27 -> V_29 ;
if ( ( V_27 -> type == V_30 ||
V_27 -> type == V_31 ) &&
V_29 -> V_32 )
V_3 -> V_33 = true ;
if ( V_29 -> V_34 ) {
V_3 -> V_35 = true ;
V_3 -> V_33 = true ;
}
}
static void F_14 ( struct V_2 * V_3 )
{
V_3 -> V_35 = false ;
V_3 -> V_33 = false ;
F_15 (
V_3 -> V_36 , V_37 ,
F_13 , V_3 ) ;
if ( V_3 -> V_35 )
F_16 ( V_3 ) ;
if ( V_3 -> V_33 ) {
F_7 ( V_3 ) ;
F_17 ( V_3 ) ;
F_8 ( V_3 ) ;
}
}
static void F_18 ( void * V_24 , T_1 * V_25 , struct V_26 * V_27 )
{
struct V_38 * V_39 = V_24 ;
int V_40 ;
if ( V_39 -> V_41 != NULL ) {
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ )
V_39 -> V_43 [ V_40 ] &= ~ ( V_39 -> V_41 [ V_40 ] ^ V_25 [ V_40 ] ) ;
} else {
V_39 -> V_41 = V_25 ;
}
}
static void F_19 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_38 V_39 ;
V_39 . V_41 = NULL ;
memset ( & V_39 . V_43 , 0xff , V_42 ) ;
if ( V_27 )
F_18 ( & V_39 , V_27 -> V_46 , V_27 ) ;
F_15 (
V_3 -> V_36 , V_37 ,
F_18 , & V_39 ) ;
memcpy ( V_45 -> V_47 , V_39 . V_43 , V_42 ) ;
if ( V_39 . V_41 )
memcpy ( V_45 -> V_48 , V_39 . V_41 , V_42 ) ;
F_21 ( V_45 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
if ( V_3 -> V_49 )
V_3 -> V_12 -> V_50 = V_51 ;
else if ( V_3 -> V_52 )
V_3 -> V_12 -> V_50 = V_30 ;
else if ( V_3 -> V_53 )
V_3 -> V_12 -> V_50 = V_31 ;
else
V_3 -> V_12 -> V_50 = V_54 ;
F_23 ( V_3 -> V_12 ) ;
}
void F_24 ( struct V_2 * V_3 )
{
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
struct V_56 * V_57 = V_3 -> V_36 -> V_58 . V_59 . V_60 ;
struct V_61 * V_62 = NULL ;
enum V_1 V_9 ;
T_2 V_63 ;
T_1 V_64 ;
int V_10 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
F_25 ( V_3 ) ;
F_26 ( V_3 -> V_36 ) ;
F_27 ( & V_3 -> V_66 . V_67 ) ;
F_28 ( V_3 ) ;
F_29 ( V_68 ) ;
F_29 ( V_69 ) ;
F_29 ( V_70 ) ;
F_30 ( V_3 ) ;
V_62 = & V_3 -> V_62 ;
V_10 = F_31 ( V_12 , V_12 -> V_71 , V_62 , false ) ;
if ( V_10 ) {
F_32 ( V_45 ,
L_1 ,
V_57 -> V_72 , V_10 ) ;
}
F_33 ( V_12 , V_3 -> V_73 , V_3 -> V_74 ,
& V_3 -> V_73 ) ;
F_29 ( V_75 ) ;
F_34 ( V_3 ) ;
V_9 = F_1 ( V_3 , V_12 -> V_71 ) ;
V_63 = F_35 ( V_9 ) ;
F_36 ( V_76 , & V_63 ) ;
F_29 ( V_77 ) ;
F_37 ( V_3 -> V_78 ) ;
F_14 ( V_3 ) ;
F_38 ( V_3 -> V_36 ) ;
F_39 ( & V_3 -> V_66 . V_67 ,
V_79 + F_40 ( V_80 ) ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_81 * V_36 ,
struct V_4 * V_82 )
{
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
struct V_83 * V_58 = & V_45 -> V_36 -> V_58 ;
bool V_84 ;
struct V_56 * V_57 = V_36 -> V_58 . V_59 . V_60 ;
struct V_61 * V_62 = NULL ;
enum V_1 V_9 ;
T_2 V_63 ;
T_1 V_64 ;
int V_10 ;
if ( F_42 ( V_85 , & V_3 -> V_86 ) )
return - V_87 ;
V_84 = ! ! ( V_36 -> V_58 . V_88 & V_89 ) ;
F_7 ( V_3 ) ;
F_27 ( & V_3 -> V_66 . V_67 ) ;
F_28 ( V_3 ) ;
F_29 ( V_68 ) ;
F_29 ( V_69 ) ;
F_29 ( V_70 ) ;
F_30 ( V_3 ) ;
F_43 ( V_45 , V_90 ,
L_2 ,
V_3 -> V_12 -> V_71 -> V_57 ,
V_57 -> V_72 , F_44 ( V_58 ) , F_45 ( V_58 ) ,
V_84 ) ;
if ( ! V_84 )
V_62 = & V_3 -> V_62 ;
V_10 = F_31 ( V_12 , V_82 , V_62 , V_84 ) ;
if ( V_10 ) {
F_32 ( V_45 ,
L_3 ,
V_57 -> V_72 , V_10 ) ;
goto V_91;
}
F_33 ( V_12 , V_3 -> V_73 , V_3 -> V_74 ,
& V_3 -> V_73 ) ;
F_29 ( V_75 ) ;
if ( V_10 )
goto V_91;
F_34 ( V_3 ) ;
V_9 = F_1 ( V_3 , V_82 ) ;
V_63 = F_35 ( V_9 ) ;
F_36 ( V_76 , & V_63 ) ;
if ( V_10 )
goto V_91;
F_29 ( V_77 ) ;
if ( V_10 )
goto V_91;
F_37 ( V_3 -> V_78 ) ;
if ( ! F_42 ( V_92 , & V_3 -> V_86 ) &&
! ( V_36 -> V_58 . V_88 & V_89 ) )
F_14 ( V_3 ) ;
F_39 ( & V_3 -> V_66 . V_67 ,
V_79 + F_40 ( V_80 ) ) ;
V_91:
F_8 ( V_3 ) ;
return V_10 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_93 V_94 ;
int V_10 = 0 ;
T_1 V_64 ;
memset ( & V_94 , 0 , sizeof( struct V_93 ) ) ;
memcpy ( & V_94 . V_95 , V_45 -> V_48 , V_42 ) ;
V_94 . V_96 = V_3 -> V_97 ;
F_36 ( V_98 , & V_94 ) ;
if ( V_10 ) {
F_32 ( V_45 , L_4 ,
V_3 -> V_97 ) ;
}
V_3 -> V_99 -- ;
V_3 -> V_100 &= ~ ( 1 << V_3 -> V_97 ) ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_93 V_94 ;
struct V_101 V_102 ;
int V_10 = 0 , V_103 ;
T_1 V_64 ;
if ( ( V_3 -> V_99 >= V_104 ) ||
( V_3 -> V_105 >= V_106 ) ) {
V_10 = - V_107 ;
goto V_108;
}
V_103 = F_48 ( V_3 -> V_109 ) ;
if ( ( V_103 < 0 ) || ( V_103 > V_106 ) ) {
V_10 = - V_107 ;
goto V_108;
}
memset ( & V_94 , 0 , sizeof( struct V_93 ) ) ;
memcpy ( & V_94 . V_95 , V_45 -> V_48 , V_42 ) ;
V_94 . V_50 = V_110 ;
V_94 . V_96 = F_48 ( V_3 -> V_100 ) ;
F_36 ( V_111 , & V_94 ) ;
if ( V_10 )
goto V_108;
V_3 -> V_97 = V_94 . V_96 ;
V_3 -> V_100 |= ( 1 << V_94 . V_96 ) ;
if ( ! V_3 -> V_99 )
V_3 -> V_12 -> V_50 = V_112 ;
V_3 -> V_99 ++ ;
memset ( & V_102 , 0 , sizeof( struct V_101 ) ) ;
memcpy ( & V_102 . V_48 , V_45 -> V_48 , V_42 ) ;
V_102 . V_113 = 1 ;
V_102 . V_114 = V_103 ;
V_102 . V_115 = V_94 . V_96 ;
V_102 . V_116 = F_35 ( 0xffff ) ;
F_36 ( V_117 , & V_102 ) ;
if ( V_10 ) {
F_32 ( V_45 , L_5 ) ;
goto V_118;
}
V_3 -> V_109 |= ( 1 << V_103 ) ;
V_3 -> V_105 ++ ;
V_3 -> V_119 [ V_3 -> V_97 ] = V_103 ;
V_3 -> V_12 -> V_120 = true ;
F_43 ( V_45 , V_90 ,
L_6 ,
V_3 -> V_97 , V_103 ) ;
return 0 ;
V_118:
F_46 ( V_3 ) ;
V_108:
F_43 ( V_45 , V_121 , L_7 ) ;
return V_10 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
int V_10 = 0 ;
T_1 V_64 , V_103 ;
F_46 ( V_3 ) ;
V_103 = V_3 -> V_119 [ V_3 -> V_97 ] ;
F_36 ( V_122 , & V_103 ) ;
if ( V_10 ) {
F_32 ( V_45 , L_8 ) ;
return V_10 ;
}
V_3 -> V_109 &= ~ ( 1 << V_103 ) ;
V_3 -> V_105 -- ;
V_3 -> V_12 -> V_120 = false ;
F_43 ( V_45 , V_90 ,
L_9 ,
V_3 -> V_97 , V_103 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_123 * V_124 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_101 V_102 ;
struct V_125 * V_126 = (struct V_125 * ) V_27 -> V_127 ;
struct V_128 * V_129 ;
int V_10 , V_103 ;
T_1 V_64 ;
T_3 V_116 ;
if ( V_3 -> V_105 >= V_106 )
return - V_107 ;
V_103 = F_48 ( V_3 -> V_109 ) ;
if ( ( V_103 < 0 ) || ( V_103 > V_106 ) )
return - V_107 ;
memset ( & V_102 , 0 , sizeof( struct V_101 ) ) ;
if ( V_124 ) {
V_129 = (struct V_128 * ) V_124 -> V_127 ;
memcpy ( & V_102 . V_48 , V_124 -> V_46 , V_42 ) ;
memcpy ( & V_102 . V_130 , V_45 -> V_131 , V_42 ) ;
V_129 -> V_96 = V_103 ;
V_102 . V_113 = 0 ;
V_116 = 1 << ( V_132 +
V_124 -> V_133 . V_134 ) ;
V_102 . V_116 = F_35 ( V_116 ) ;
} else {
memcpy ( & V_102 . V_48 , V_27 -> V_46 , V_42 ) ;
V_102 . V_113 = 1 ;
V_102 . V_116 = F_35 ( 0xffff ) ;
}
V_102 . V_114 = V_103 ;
V_102 . V_115 = V_126 -> V_96 ;
F_36 ( V_117 , & V_102 ) ;
if ( V_10 ) {
if ( V_124 )
F_32 ( V_45 ,
L_10 ,
V_124 -> V_46 ) ;
return V_10 ;
}
if ( V_124 ) {
F_43 ( V_45 , V_90 ,
L_11 ,
V_124 -> V_46 , V_102 . V_114 ) ;
} else {
F_43 ( V_45 , V_90 ,
L_12 ,
V_126 -> V_96 , V_102 . V_114 ) ;
}
V_3 -> V_109 |= ( 1 << V_103 ) ;
V_3 -> V_105 ++ ;
if ( ! V_124 )
V_3 -> V_119 [ V_126 -> V_96 ] = V_103 ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_123 * V_124 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_125 * V_126 = (struct V_125 * ) V_27 -> V_127 ;
struct V_128 * V_129 ;
int V_10 ;
T_1 V_64 , V_103 ;
if ( V_124 ) {
V_129 = (struct V_128 * ) V_124 -> V_127 ;
V_103 = V_129 -> V_96 ;
} else {
V_103 = V_3 -> V_119 [ V_126 -> V_96 ] ;
}
F_36 ( V_122 , & V_103 ) ;
if ( V_10 ) {
if ( V_124 )
F_32 ( V_45 ,
L_13 ,
V_124 -> V_46 ) ;
return V_10 ;
}
if ( V_124 ) {
F_43 ( V_45 , V_90 ,
L_14 ,
V_124 -> V_46 , V_103 ) ;
} else {
F_43 ( V_45 , V_90 ,
L_15 ,
V_126 -> V_96 , V_103 ) ;
}
V_3 -> V_109 &= ~ ( 1 << V_103 ) ;
V_3 -> V_105 -- ;
return 0 ;
}
int F_52 ( struct V_2 * V_3 ,
T_1 V_135 )
{
struct V_136 V_137 ;
int V_10 ;
T_1 V_64 ;
memset ( & V_137 , 0 , sizeof( struct V_136 ) ) ;
V_137 . V_138 = F_53 ( 0xffff ) ;
V_137 . V_139 = 0xff ;
V_137 . V_135 = V_135 ;
V_137 . V_140 = V_3 -> V_12 -> V_141 . V_140 ;
F_36 ( V_142 , & V_137 ) ;
return V_10 ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_143 * V_144 )
{
struct V_128 * V_129 = (struct V_128 * ) V_124 -> V_127 ;
struct V_145 * V_146 ;
T_4 V_141 = 0 ;
int V_40 , V_147 ;
V_146 = V_3 -> V_36 -> V_148 -> V_149 [ V_3 -> V_36 -> V_58 . V_59 . V_60 -> V_150 ] ;
for ( V_40 = 0 , V_147 = 0 ; V_40 < V_146 -> V_151 ; V_40 ++ ) {
if ( V_124 -> V_152 [ V_146 -> V_150 ] & F_55 ( V_40 ) ) {
V_144 -> V_153 . V_154 . V_155 [ V_147 ]
= ( V_146 -> V_156 [ V_40 ] . V_157 * 2 ) / 10 ;
V_147 ++ ;
}
}
V_144 -> V_153 . V_154 . V_158 = V_147 ;
if ( V_124 -> V_133 . V_159 ) {
for ( V_40 = 0 , V_147 = 0 ; V_40 < 77 ; V_40 ++ ) {
if ( V_124 -> V_133 . V_160 . V_161 [ V_40 / 8 ] & ( 1 << ( V_40 % 8 ) ) )
V_144 -> V_153 . V_162 . V_155 [ V_147 ++ ] = V_40 ;
if ( V_147 == V_163 )
break;
}
V_144 -> V_153 . V_162 . V_158 = V_147 ;
V_141 = V_164 ;
if ( V_124 -> V_133 . V_165 & V_166 )
V_141 |= V_167 ;
if ( V_124 -> V_133 . V_160 . V_161 [ 1 ] )
V_141 |= V_168 ;
if ( ( V_124 -> V_133 . V_165 & V_169 ) &&
( F_45 ( & V_3 -> V_36 -> V_58 ) ) )
V_141 |= V_170 ;
if ( F_45 ( & V_3 -> V_36 -> V_58 ) &&
( V_124 -> V_133 . V_165 & V_171 ) )
V_141 |= V_172 ;
else if ( F_56 ( & V_3 -> V_36 -> V_58 ) &&
( V_124 -> V_133 . V_165 & V_173 ) )
V_141 |= V_172 ;
}
V_144 -> V_114 = V_129 -> V_96 ;
V_144 -> V_174 = 1 ;
V_144 -> V_175 = F_53 ( V_141 ) ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_143 * V_144 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
int V_10 ;
T_1 V_64 ;
F_36 ( V_176 , V_144 ) ;
if ( V_10 ) {
F_32 ( V_45 ,
L_16 ) ;
}
return V_10 ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_123 * V_124 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_143 V_144 ;
int V_10 ;
memset ( & V_144 , 0 , sizeof( struct V_143 ) ) ;
F_54 ( V_3 , V_124 , & V_144 ) ;
V_10 = F_57 ( V_3 , & V_144 ) ;
if ( ! V_10 )
F_43 ( V_45 , V_90 ,
L_17 ,
V_124 -> V_46 , F_59 ( V_144 . V_175 ) ) ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_143 V_144 ;
struct V_123 * V_124 ;
int V_10 ;
memset ( & V_144 , 0 , sizeof( struct V_143 ) ) ;
F_61 () ;
V_124 = F_62 ( V_27 , V_29 -> V_130 ) ;
if ( ! V_124 ) {
F_63 () ;
return;
}
F_54 ( V_3 , V_124 , & V_144 ) ;
F_63 () ;
V_10 = F_57 ( V_3 , & V_144 ) ;
if ( ! V_10 )
F_43 ( V_45 , V_90 ,
L_17 ,
V_29 -> V_130 , F_59 ( V_144 . V_175 ) ) ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_123 * V_124 ,
enum V_177 V_178 ,
T_3 V_179 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_180 V_181 ;
struct V_128 * V_129 ;
int V_10 = 0 ;
T_1 V_64 ;
if ( V_179 >= V_182 )
return - V_183 ;
memset ( & V_181 , 0 , sizeof( struct V_180 ) ) ;
V_129 = (struct V_128 * ) V_124 -> V_127 ;
V_181 . V_114 = V_129 -> V_96 ;
V_181 . V_184 = V_179 & 0xf ;
V_181 . V_185 = ( V_178 == V_186 ) ? true : false ;
F_36 ( V_187 , & V_181 ) ;
if ( V_10 )
F_43 ( V_45 , V_90 ,
L_18 ,
( V_181 . V_185 ) ? L_19 : L_20 , V_124 -> V_46 , V_179 ) ;
else
F_43 ( V_45 , V_90 ,
L_21 ,
( V_181 . V_185 ) ? L_22 : L_23 ,
V_124 -> V_46 , V_179 ) ;
F_65 ( & V_3 -> V_66 . V_188 ) ;
V_129 -> V_189 [ V_179 ] = ( V_181 . V_185 && ! V_10 ) ? V_190 : V_191 ;
F_66 ( & V_3 -> V_66 . V_188 ) ;
return V_10 ;
}
void F_16 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
unsigned long V_192 = F_67 ( V_79 ) ;
V_45 -> V_193 . V_194 = V_192 ;
V_45 -> V_193 . V_195 = V_192 ;
V_45 -> V_193 . V_196 = V_192 ;
F_68 ( V_197 , & V_3 -> V_86 ) ;
F_69 ( V_45 -> V_36 , & V_3 -> V_198 ,
F_40 ( V_199 ) ) ;
}
void F_25 ( struct V_2 * V_3 )
{
F_70 ( & V_3 -> V_198 ) ;
F_71 ( V_197 , & V_3 -> V_86 ) ;
}
void F_72 ( struct V_21 * V_22 )
{
struct V_2 * V_3 =
F_12 ( V_22 , struct V_2 , V_198 . V_22 ) ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
bool V_200 = false ;
bool V_201 = false ;
bool V_202 = false ;
unsigned int V_192 = F_67 ( V_79 ) ;
T_4 V_203 , V_204 ;
V_204 = ( V_12 -> V_50 == V_30 ) ?
V_205 : V_206 ;
if ( V_12 -> V_207 != V_15 )
goto V_208;
if ( ( V_192 - V_45 -> V_193 . V_194 ) >= V_209 ) {
V_200 = true ;
F_43 ( V_45 , V_210 , L_24 , V_79 ) ;
V_45 -> V_193 . V_194 = V_192 ;
}
if ( ! V_45 -> V_193 . V_211 ) {
if ( ( V_192 - V_45 -> V_193 . V_195 ) >=
V_204 ) {
V_201 = true ;
F_43 ( V_45 , V_210 , L_25 , V_79 ) ;
V_45 -> V_193 . V_195 = V_192 ;
V_45 -> V_193 . V_212 = V_192 ;
}
} else {
if ( ( V_192 - V_45 -> V_193 . V_212 ) >=
V_213 ) {
V_45 -> V_193 . V_211 = F_73 ( V_12 ) ;
if ( V_45 -> V_193 . V_211 )
V_45 -> V_193 . V_212 = V_192 ;
}
}
if ( ( V_192 - V_45 -> V_193 . V_196 ) >= V_199 ) {
V_202 = true ;
V_45 -> V_193 . V_196 = V_192 ;
}
if ( V_200 || V_201 || V_202 ) {
F_7 ( V_3 ) ;
if ( V_202 )
F_74 ( V_12 , V_12 -> V_71 ) ;
if ( V_200 || V_201 )
V_45 -> V_193 . V_211 =
F_75 ( V_12 , V_12 -> V_71 ,
V_12 -> V_214 , V_200 ) ;
F_8 ( V_3 ) ;
}
V_208:
V_203 = V_209 ;
V_203 = F_76 ( V_203 , ( T_4 ) V_199 ) ;
if ( ! V_45 -> V_193 . V_211 )
V_203 = F_76 ( V_203 , ( T_4 ) V_204 ) ;
F_69 ( V_45 -> V_36 , & V_3 -> V_198 ,
F_40 ( V_203 ) ) ;
}
static void F_77 ( struct V_81 * V_36 ,
struct V_215 * V_216 ,
struct V_217 * V_218 )
{
struct V_219 * V_220 ;
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
int V_221 , V_222 , V_10 , V_223 ;
V_220 = (struct V_219 * ) V_218 -> V_24 ;
V_221 = F_78 ( V_220 -> V_224 ) ;
V_222 = V_221 & 3 ;
if ( V_222 && V_218 -> V_225 > V_221 ) {
if ( F_79 ( V_218 ) < V_222 ) {
F_43 ( V_45 , V_226 , L_26 ) ;
goto V_227;
}
F_80 ( V_218 , V_222 ) ;
memmove ( V_218 -> V_24 , V_218 -> V_24 + V_222 , V_221 ) ;
}
V_223 = F_81 ( V_3 ) ;
if ( V_223 < 0 ) {
F_43 ( V_45 , V_226 , L_27 ) ;
goto V_227;
}
V_10 = F_82 ( V_3 , V_216 -> V_124 , V_218 , V_223 , false ) ;
if ( V_10 != 0 ) {
F_43 ( V_45 , V_226 , L_28 ) ;
goto V_228;
}
F_83 ( V_3 ) ;
return;
V_228:
F_84 ( V_3 , V_223 ) ;
V_227:
F_85 ( V_218 ) ;
}
static int F_86 ( struct V_81 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
struct V_56 * V_71 = V_36 -> V_58 . V_59 . V_60 ;
struct V_4 * V_229 ;
int V_10 = 0 ;
enum V_1 V_9 ;
T_2 V_63 ;
T_1 V_64 ;
F_4 ( & V_3 -> V_65 ) ;
F_43 ( V_45 , V_90 ,
L_29 ,
V_71 -> V_72 ) ;
F_3 ( V_3 , V_15 ) ;
F_29 ( V_230 ) ;
V_229 = F_87 ( V_36 , V_12 , & V_36 -> V_58 . V_59 ) ;
V_10 = F_31 ( V_12 , V_229 , V_12 -> V_62 , false ) ;
if ( V_10 ) {
F_32 ( V_45 ,
L_30 ,
V_10 , V_71 -> V_72 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
F_33 ( V_12 , V_3 -> V_73 , V_3 -> V_74 ,
& V_3 -> V_73 ) ;
V_9 = F_1 ( V_3 , V_229 ) ;
V_63 = F_35 ( V_9 ) ;
F_36 ( V_76 , & V_63 ) ;
F_29 ( V_231 ) ;
F_29 ( V_75 ) ;
F_34 ( V_3 ) ;
V_10 = F_52 ( V_3 , 0 ) ;
if ( V_10 )
F_43 ( V_45 , V_90 ,
L_31 ) ;
F_71 ( V_85 , & V_3 -> V_86 ) ;
F_37 ( V_3 -> V_78 ) ;
F_65 ( & V_3 -> V_66 . V_188 ) ;
V_3 -> V_66 . V_88 &= ~ V_232 ;
F_66 ( & V_3 -> V_66 . V_188 ) ;
F_38 ( V_36 ) ;
F_39 ( & V_3 -> V_66 . V_67 ,
V_79 + F_40 ( V_80 ) ) ;
F_88 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_89 ( struct V_81 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
int V_10 V_233 ( ( V_234 ) ) ;
T_1 V_64 ;
F_4 ( & V_3 -> V_65 ) ;
if ( F_42 ( V_85 , & V_3 -> V_86 ) ) {
F_43 ( V_45 , V_235 , L_32 ) ;
F_6 ( & V_3 -> V_65 ) ;
return;
}
F_7 ( V_3 ) ;
F_29 ( V_68 ) ;
F_29 ( V_69 ) ;
F_29 ( V_70 ) ;
F_90 ( & V_3 -> V_236 ) ;
F_27 ( & V_3 -> V_66 . V_67 ) ;
F_28 ( V_3 ) ;
F_30 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
F_91 ( & V_3 -> V_237 ) ;
F_91 ( & V_3 -> V_23 ) ;
#ifdef F_92
F_91 ( & V_3 -> V_238 ) ;
#endif
F_25 ( V_3 ) ;
F_4 ( & V_3 -> V_65 ) ;
F_93 ( V_3 ) ;
if ( V_3 -> V_12 -> V_120 )
F_49 ( V_3 ) ;
F_94 ( V_12 ) ;
F_95 ( V_12 ) ;
F_8 ( V_3 ) ;
F_3 ( V_3 , V_18 ) ;
F_68 ( V_85 , & V_3 -> V_86 ) ;
F_43 ( V_45 , V_90 , L_33 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_96 ( struct V_81 * V_36 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_125 * V_126 = ( void * ) V_27 -> V_127 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_93 V_94 ;
int V_10 = 0 ;
T_1 V_64 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
memset ( & V_94 , 0 , sizeof( struct V_93 ) ) ;
memcpy ( & V_94 . V_95 , V_27 -> V_46 , V_42 ) ;
switch ( V_27 -> type ) {
case V_54 :
V_94 . V_50 = V_239 ;
break;
case V_51 :
V_94 . V_50 = V_240 ;
break;
case V_30 :
V_94 . V_50 = V_241 ;
break;
case V_31 :
V_94 . V_50 = V_242 ;
break;
default:
F_32 ( V_45 ,
L_34 , V_27 -> type ) ;
V_10 = - V_243 ;
goto V_244;
}
V_126 -> V_96 = V_94 . V_96 = F_48 ( V_3 -> V_100 ) ;
V_94 . V_245 = F_35 ( 2304 ) ;
F_36 ( V_111 , & V_94 ) ;
if ( V_10 )
goto V_244;
V_10 = F_50 ( V_3 , V_27 , NULL ) ;
if ( V_10 ) {
F_36 ( V_98 , & V_94 ) ;
goto V_244;
}
F_19 ( V_3 , V_27 ) ;
V_3 -> V_100 |= ( 1 << V_126 -> V_96 ) ;
V_3 -> V_99 ++ ;
F_97 ( V_3 , V_27 -> type ) ;
if ( ( V_27 -> type == V_30 ) ||
( V_27 -> type == V_31 ) ||
( V_27 -> type == V_51 ) )
F_98 ( V_3 , V_27 ) ;
F_22 ( V_3 ) ;
if ( ( V_3 -> V_12 -> V_50 == V_30 ) &&
! F_42 ( V_197 , & V_3 -> V_86 ) ) {
F_99 ( V_3 -> V_12 , true ) ;
F_16 ( V_3 ) ;
}
F_43 ( V_45 , V_90 , L_35 ,
V_27 -> type , V_126 -> V_96 ) ;
V_244:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_100 ( struct V_81 * V_36 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_125 * V_126 = ( void * ) V_27 -> V_127 ;
struct V_93 V_94 ;
int V_10 = 0 ;
T_1 V_64 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
memset ( & V_94 , 0 , sizeof( struct V_93 ) ) ;
memcpy ( & V_94 . V_95 , V_27 -> V_46 , V_42 ) ;
V_94 . V_96 = V_126 -> V_96 ;
F_36 ( V_98 , & V_94 ) ;
if ( V_10 ) {
F_32 ( V_45 , L_36 ,
V_126 -> V_96 ) ;
}
V_3 -> V_99 -- ;
V_3 -> V_100 &= ~ ( 1 << V_126 -> V_96 ) ;
F_51 ( V_3 , V_27 , NULL ) ;
F_101 ( V_3 , V_27 -> type ) ;
if ( ( V_27 -> type == V_30 ) ||
V_27 -> type == V_31 ||
( V_27 -> type == V_51 ) )
F_102 ( V_3 , V_27 ) ;
F_22 ( V_3 ) ;
F_19 ( V_3 , V_27 ) ;
if ( ( V_27 -> type == V_30 ) && ( V_3 -> V_52 == 0 ) ) {
V_3 -> V_35 = false ;
F_15 (
V_3 -> V_36 , V_37 ,
F_13 , V_3 ) ;
if ( ! V_3 -> V_35 )
F_25 ( V_3 ) ;
}
F_43 ( V_45 , V_90 , L_37 , V_126 -> V_96 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_103 ( struct V_81 * V_36 , T_4 V_246 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_83 * V_58 = & V_36 -> V_58 ;
bool V_247 = false ;
int V_10 = 0 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
if ( V_246 & V_248 ) {
F_4 ( & V_3 -> V_11 ) ;
V_3 -> V_17 = ! ! ( V_58 -> V_88 & V_249 ) ;
if ( ! V_3 -> V_17 )
V_247 = true ;
F_6 ( & V_3 -> V_11 ) ;
}
if ( V_246 & V_250 ) {
if ( ( V_58 -> V_88 & V_251 ) &&
! V_3 -> V_12 -> V_120 )
F_47 ( V_3 ) ;
else if ( V_3 -> V_12 -> V_120 )
F_49 ( V_3 ) ;
}
if ( ( V_246 & V_252 ) || V_247 ) {
struct V_56 * V_71 = V_36 -> V_58 . V_59 . V_60 ;
int V_253 = V_71 -> V_254 ;
F_43 ( V_45 , V_90 , L_38 ,
V_71 -> V_72 ) ;
F_87 ( V_36 , V_3 -> V_12 , & V_36 -> V_58 . V_59 ) ;
if ( F_41 ( V_3 , V_36 , & V_3 -> V_12 -> V_255 [ V_253 ] ) < 0 ) {
F_32 ( V_45 , L_39 ) ;
V_10 = - V_183 ;
goto V_244;
}
}
if ( V_246 & V_256 ) {
if ( V_58 -> V_88 & V_257 ) {
F_3 ( V_3 , V_20 ) ;
V_3 -> V_19 = true ;
} else {
V_3 -> V_19 = false ;
F_91 ( & V_3 -> V_23 ) ;
F_3 ( V_3 , V_15 ) ;
}
}
if ( V_246 & V_258 ) {
V_3 -> V_74 = 2 * V_58 -> V_259 ;
F_33 ( V_3 -> V_12 , V_3 -> V_73 ,
V_3 -> V_74 , & V_3 -> V_73 ) ;
}
V_244:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_104 ( struct V_81 * V_36 ,
unsigned int V_260 ,
unsigned int * V_261 ,
T_5 V_262 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
T_4 V_263 ;
F_4 ( & V_3 -> V_65 ) ;
V_260 &= V_264 ;
* V_261 &= V_264 ;
if ( F_42 ( V_85 , & V_3 -> V_86 ) ) {
F_43 ( F_20 ( V_3 -> V_12 ) , V_235 ,
L_40 ) ;
F_6 ( & V_3 -> V_65 ) ;
return;
}
F_7 ( V_3 ) ;
V_3 -> V_265 = * V_261 ;
V_263 = F_105 ( V_3 ) ;
F_106 ( V_3 -> V_12 , V_263 ) ;
F_43 ( F_20 ( V_3 -> V_12 ) , V_90 , L_41 ,
V_263 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static void F_107 ( struct V_21 * V_22 )
{
struct V_128 * V_129 =
F_12 ( V_22 , struct V_128 , V_266 ) ;
struct V_123 * V_124 =
F_12 ( ( void * ) V_129 , struct V_123 , V_127 ) ;
struct V_2 * V_3 = V_129 -> V_267 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_143 V_144 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
memset ( & V_144 , 0 , sizeof( struct V_143 ) ) ;
F_54 ( V_3 , V_124 , & V_144 ) ;
if ( ! F_57 ( V_3 , & V_144 ) )
F_43 ( V_45 , V_90 ,
L_42 ,
V_124 -> V_46 , F_59 ( V_144 . V_175 ) ) ;
else
F_43 ( V_45 , V_90 ,
L_43 ,
V_124 -> V_46 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_108 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_123 * V_124 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_128 * V_129 = (struct V_128 * ) V_124 -> V_127 ;
int V_10 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
V_10 = F_50 ( V_3 , V_27 , V_124 ) ;
if ( ! V_10 ) {
F_109 ( & V_129 -> V_266 , F_107 ) ;
V_129 -> V_267 = V_3 ;
F_58 ( V_3 , V_124 ) ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static int F_110 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_123 * V_124 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_128 * V_129 = (struct V_128 * ) V_124 -> V_127 ;
int V_10 ;
F_91 ( & V_129 -> V_266 ) ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
F_111 ( V_3 -> V_78 , V_129 -> V_96 ) ;
V_10 = F_51 ( V_3 , V_27 , V_124 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_112 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_123 * V_124 , T_4 V_246 )
{
struct V_128 * V_129 = (struct V_128 * ) V_124 -> V_127 ;
if ( ! ( V_246 & V_268 ) )
return;
F_113 ( & V_129 -> V_266 ) ;
}
static int F_114 ( struct V_81 * V_36 ,
struct V_26 * V_27 , T_3 V_269 ,
const struct V_270 * V_271 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_272 V_273 ;
int V_10 = 0 , V_274 ;
if ( V_269 >= V_275 )
return 0 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
memset ( & V_273 , 0 , sizeof( struct V_272 ) ) ;
V_273 . V_276 = V_271 -> V_277 ;
V_273 . V_278 = V_271 -> V_279 ;
V_273 . V_280 = V_271 -> V_281 ;
V_273 . V_282 = V_271 -> V_283 * 32 ;
V_274 = F_115 ( V_269 , V_3 -> V_284 ) ;
F_43 ( V_45 , V_90 ,
L_44 ,
V_269 , V_274 , V_271 -> V_277 , V_271 -> V_279 ,
V_271 -> V_281 , V_271 -> V_283 ) ;
V_10 = F_116 ( V_3 , V_274 , & V_273 ) ;
if ( V_10 ) {
F_32 ( V_45 , L_45 ) ;
goto V_244;
}
if ( ( V_3 -> V_12 -> V_50 == V_51 ) &&
( V_274 == V_3 -> V_284 [ V_285 ] ) )
F_117 ( V_3 ) ;
V_244:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static int F_118 ( struct V_81 * V_36 ,
enum V_286 V_287 ,
struct V_26 * V_27 ,
struct V_123 * V_124 ,
struct V_288 * V_289 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
int V_10 = 0 ;
if ( V_290 )
return - V_291 ;
if ( ( V_27 -> type == V_51 ||
V_27 -> type == V_31 ) &&
( V_289 -> V_292 == V_293 ||
V_289 -> V_292 == V_294 ) &&
! ( V_289 -> V_88 & V_295 ) ) {
return - V_243 ;
}
F_4 ( & V_3 -> V_65 ) ;
F_43 ( V_45 , V_90 , L_46 ) ;
F_7 ( V_3 ) ;
switch ( V_287 ) {
case V_296 :
V_10 = F_119 ( V_45 , V_27 , V_124 , V_289 ) ;
if ( V_10 >= 0 ) {
V_289 -> V_297 = V_10 ;
V_289 -> V_88 |= V_298 ;
if ( V_289 -> V_292 == V_293 )
V_289 -> V_88 |= V_299 ;
if ( V_3 -> V_12 -> V_300 &&
V_289 -> V_292 == V_294 )
V_289 -> V_88 |= V_301 ;
V_10 = 0 ;
}
break;
case V_302 :
F_120 ( V_45 , V_289 ) ;
break;
default:
V_10 = - V_183 ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_121 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
F_122 ( V_3 -> V_12 ) ;
F_43 ( V_45 , V_90 , L_47 ,
V_45 -> V_131 , V_45 -> V_303 ) ;
}
static void F_123 ( void * V_24 , T_1 * V_25 , struct V_26 * V_27 )
{
struct V_2 * V_3 = (struct V_2 * ) V_24 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_28 * V_29 = & V_27 -> V_29 ;
if ( ( V_27 -> type == V_54 ) && V_29 -> V_34 ) {
V_45 -> V_303 = V_29 -> V_304 ;
memcpy ( V_45 -> V_131 , V_29 -> V_130 , V_42 ) ;
}
}
static void F_124 ( struct V_2 * V_3 )
{
if ( V_3 -> V_305 == 1 ) {
F_15 (
V_3 -> V_36 , V_37 ,
F_123 , V_3 ) ;
F_121 ( V_3 ) ;
}
}
static void F_125 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_28 * V_29 ,
T_4 V_246 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
if ( V_246 & V_306 ) {
F_43 ( V_45 , V_90 , L_48 ,
V_29 -> V_34 ) ;
V_29 -> V_34 ?
V_3 -> V_305 ++ : V_3 -> V_305 -- ;
if ( V_3 -> V_12 -> V_50 == V_54 ) {
F_124 ( V_3 ) ;
if ( V_29 -> V_34 && ( V_3 -> V_305 == 1 ) )
F_16 ( V_3 ) ;
else if ( V_3 -> V_305 == 0 )
F_25 ( V_3 ) ;
}
}
if ( V_246 & V_307 ) {
if ( V_3 -> V_12 -> V_50 == V_51 ) {
V_45 -> V_303 = V_29 -> V_304 ;
memcpy ( V_45 -> V_131 , V_29 -> V_130 , V_42 ) ;
F_121 ( V_3 ) ;
}
}
if ( ( V_246 & V_308 ) && V_29 -> V_32 ) {
F_43 ( V_45 , V_90 , L_49 ,
V_29 -> V_130 ) ;
F_126 ( V_3 , V_27 ) ;
F_68 ( V_309 , & V_3 -> V_86 ) ;
F_127 ( V_3 , V_27 ) ;
}
if ( ( V_246 & V_308 ) && ! V_29 -> V_32 ) {
if ( ( V_3 -> V_52 + V_3 -> V_53 <= 1 ) ||
V_3 -> V_49 ) {
F_43 ( V_45 , V_90 ,
L_50 ,
V_29 -> V_130 ) ;
F_71 ( V_309 , & V_3 -> V_86 ) ;
F_127 ( V_3 , V_27 ) ;
}
}
if ( V_246 & V_310 ) {
if ( V_3 -> V_99 == 1 &&
( ( V_3 -> V_12 -> V_50 == V_30 &&
V_27 -> type == V_30 &&
V_3 -> V_52 == 1 ) ||
( V_3 -> V_12 -> V_50 == V_31 &&
V_27 -> type == V_31 &&
V_3 -> V_53 == 1 ) ) ) {
F_68 ( V_311 , & V_3 -> V_86 ) ;
}
F_43 ( V_45 , V_90 ,
L_51 ,
V_29 -> V_130 ) ;
F_127 ( V_3 , V_27 ) ;
}
if ( V_246 & V_312 ) {
if ( V_29 -> V_313 )
V_12 -> V_314 = 9 ;
else
V_12 -> V_314 = 20 ;
F_128 ( V_12 ) ;
}
if ( V_246 & V_315 )
F_60 ( V_3 , V_27 , V_29 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static T_5 F_129 ( struct V_81 * V_36 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
T_5 V_316 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
V_316 = F_130 ( V_3 -> V_12 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_316 ;
}
static void F_131 ( struct V_81 * V_36 ,
struct V_26 * V_27 , T_5 V_316 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
F_132 ( V_3 -> V_12 , V_316 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static void F_133 ( struct V_81 * V_36 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
F_134 ( V_3 -> V_12 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_135 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
enum V_177 V_178 ,
struct V_123 * V_124 ,
T_3 V_179 , T_3 * V_317 , T_1 V_318 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_128 * V_129 ;
int V_10 = 0 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
switch ( V_178 ) {
case V_319 :
break;
case V_320 :
break;
case V_186 :
V_10 = F_64 ( V_3 , V_27 , V_124 , V_178 , V_179 ) ;
if ( ! V_10 )
F_136 ( V_27 , V_124 -> V_46 , V_179 ) ;
break;
case V_321 :
case V_322 :
case V_323 :
F_64 ( V_3 , V_27 , V_124 , V_178 , V_179 ) ;
F_137 ( V_27 , V_124 -> V_46 , V_179 ) ;
break;
case V_324 :
V_129 = (struct V_128 * ) V_124 -> V_127 ;
F_65 ( & V_3 -> V_66 . V_188 ) ;
V_129 -> V_189 [ V_179 ] = V_325 ;
F_66 ( & V_3 -> V_66 . V_188 ) ;
break;
default:
F_32 ( F_20 ( V_3 -> V_12 ) , L_52 ) ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_138 ( struct V_81 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
F_4 ( & V_3 -> V_65 ) ;
F_65 ( & V_3 -> V_326 ) ;
F_68 ( V_92 , & V_3 -> V_86 ) ;
F_66 ( & V_3 -> V_326 ) ;
F_91 ( & V_3 -> V_23 ) ;
F_25 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static void F_139 ( struct V_81 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
F_4 ( & V_3 -> V_65 ) ;
F_65 ( & V_3 -> V_326 ) ;
F_71 ( V_92 , & V_3 -> V_86 ) ;
F_66 ( & V_3 -> V_326 ) ;
F_7 ( V_3 ) ;
F_14 ( V_3 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_140 ( struct V_81 * V_36 , T_4 V_327 )
{
return 0 ;
}
static void F_141 ( struct V_81 * V_36 ,
T_1 V_328 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
V_3 -> V_12 -> V_328 = V_328 ;
F_128 ( V_3 -> V_12 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_142 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
const struct V_329 * V_43 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_330 V_331 ;
struct V_125 * V_126 = ( void * ) V_27 -> V_127 ;
int V_10 = 0 ;
T_1 V_64 ;
memset ( & V_331 , 0 , sizeof( struct V_330 ) ) ;
V_331 . V_115 = V_126 -> V_96 ;
V_331 . V_150 = V_332 ;
V_331 . V_43 = F_53 ( V_43 -> V_216 [ V_332 ] . V_333 ) ;
F_36 ( V_334 , & V_331 ) ;
if ( V_10 ) {
F_32 ( V_45 ,
L_53
L_54 , V_126 -> V_96 ) ;
goto V_244;
}
V_331 . V_150 = V_335 ;
V_331 . V_43 = F_53 ( V_43 -> V_216 [ V_335 ] . V_333 ) ;
F_36 ( V_334 , & V_331 ) ;
if ( V_10 ) {
F_32 ( V_45 ,
L_55
L_54 , V_126 -> V_96 ) ;
goto V_244;
}
F_43 ( V_45 , V_90 , L_56 ,
V_43 -> V_216 [ V_332 ] . V_333 ,
V_43 -> V_216 [ V_335 ] . V_333 ) ;
V_244:
return V_10 ;
}
static int F_143 ( struct V_81 * V_36 ,
struct V_336 * V_337 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_338 * V_339 = & V_12 -> V_340 ;
V_337 -> V_341 = V_339 -> V_342 ;
V_337 -> V_343 = V_339 -> V_344 ;
V_337 -> V_345 = V_339 -> V_346 ;
V_337 -> V_347 = V_339 -> V_348 ;
return 0 ;
}
struct V_349 * F_144 ( struct V_2 * V_3 )
{
struct V_349 * V_350 = NULL ;
if ( F_145 ( V_3 -> V_12 ) )
V_350 = (struct V_349 * )
& V_3 -> V_12 -> V_351 . V_352 . V_353 ;
else if ( V_3 -> V_12 -> V_354 . V_355 == V_356 )
V_350 = (struct V_349 * )
& V_3 -> V_12 -> V_351 . V_357 . V_353 ;
else if ( V_3 -> V_12 -> V_354 . V_355 == V_358 )
V_350 = (struct V_349 * )
& V_3 -> V_12 -> V_351 . V_359 . V_353 ;
return V_350 ;
}
static int F_146 ( struct V_81 * V_36 , T_4 * V_360 ,
T_4 * V_361 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_349 * V_350 = F_144 ( V_3 ) ;
if ( V_350 ) {
* V_360 = V_350 -> V_362 ;
* V_361 = V_350 -> V_363 ;
} else {
* V_360 = 0 ;
* V_361 = 0 ;
}
return 0 ;
}
