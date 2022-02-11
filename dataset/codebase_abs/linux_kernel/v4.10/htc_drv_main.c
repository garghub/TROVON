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
V_29 -> V_32 ) {
V_3 -> V_33 = true ;
V_3 -> V_34 = true ;
}
if ( V_29 -> V_35 ) {
V_3 -> V_34 = true ;
V_3 -> V_33 = true ;
}
}
static void F_14 ( struct V_2 * V_3 )
{
V_3 -> V_34 = false ;
V_3 -> V_33 = false ;
F_15 (
V_3 -> V_36 , V_37 ,
F_13 , V_3 ) ;
if ( V_3 -> V_34 )
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
F_21 ( V_39 . V_43 ) ;
if ( V_27 )
F_18 ( & V_39 , V_27 -> V_46 , V_27 ) ;
F_15 (
V_3 -> V_36 , V_37 ,
F_18 , & V_39 ) ;
memcpy ( V_45 -> V_47 , V_39 . V_43 , V_42 ) ;
if ( V_39 . V_41 )
memcpy ( V_45 -> V_48 , V_39 . V_41 , V_42 ) ;
F_22 ( V_45 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
if ( V_3 -> V_49 )
V_3 -> V_12 -> V_50 = V_51 ;
else if ( V_3 -> V_52 )
V_3 -> V_12 -> V_50 = V_30 ;
else if ( V_3 -> V_53 )
V_3 -> V_12 -> V_50 = V_31 ;
else
V_3 -> V_12 -> V_50 = V_54 ;
F_24 ( V_3 -> V_12 ) ;
}
void F_25 ( struct V_2 * V_3 )
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
F_26 ( V_3 ) ;
F_27 ( V_3 -> V_36 ) ;
F_28 ( & V_3 -> V_66 . V_67 ) ;
F_29 ( V_3 ) ;
F_30 ( V_68 ) ;
F_30 ( V_69 ) ;
F_30 ( V_70 ) ;
F_31 ( V_3 ) ;
V_62 = & V_3 -> V_62 ;
V_10 = F_32 ( V_12 , V_12 -> V_71 , V_62 , false ) ;
if ( V_10 ) {
F_33 ( V_45 ,
L_1 ,
V_57 -> V_72 , V_10 ) ;
}
F_34 ( V_12 , V_3 -> V_73 , V_3 -> V_74 ,
& V_3 -> V_73 ) ;
F_30 ( V_75 ) ;
F_35 ( V_3 ) ;
V_9 = F_1 ( V_3 , V_12 -> V_71 ) ;
V_63 = F_36 ( V_9 ) ;
F_37 ( V_76 , & V_63 ) ;
F_30 ( V_77 ) ;
F_38 ( V_3 -> V_78 ) ;
F_14 ( V_3 ) ;
F_39 ( V_3 -> V_36 ) ;
F_40 ( & V_3 -> V_66 . V_67 ,
V_79 + F_41 ( V_80 ) ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_81 * V_36 ,
struct V_4 * V_82 )
{
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
struct V_83 * V_58 = & V_45 -> V_36 -> V_58 ;
bool V_84 ;
struct V_56 * V_57 = V_36 -> V_58 . V_59 . V_60 ;
struct V_61 * V_62 ;
enum V_1 V_9 ;
T_2 V_63 ;
T_1 V_64 ;
int V_10 ;
if ( F_43 ( V_85 , & V_45 -> V_86 ) )
return - V_87 ;
V_84 = ! ! ( V_36 -> V_58 . V_88 & V_89 ) ;
F_7 ( V_3 ) ;
F_26 ( V_3 ) ;
F_28 ( & V_3 -> V_66 . V_67 ) ;
F_29 ( V_3 ) ;
F_30 ( V_68 ) ;
F_30 ( V_69 ) ;
F_30 ( V_70 ) ;
F_31 ( V_3 ) ;
F_44 ( V_45 , V_90 ,
L_2 ,
V_3 -> V_12 -> V_71 -> V_57 ,
V_57 -> V_72 , F_45 ( V_58 ) , F_46 ( V_58 ) ,
V_84 ) ;
V_62 = V_84 ? NULL : & V_3 -> V_62 ;
V_10 = F_32 ( V_12 , V_82 , V_62 , V_84 ) ;
if ( V_10 ) {
F_33 ( V_45 ,
L_3 ,
V_57 -> V_72 , V_10 ) ;
goto V_91;
}
F_34 ( V_12 , V_3 -> V_73 , V_3 -> V_74 ,
& V_3 -> V_73 ) ;
F_30 ( V_75 ) ;
if ( V_10 )
goto V_91;
F_35 ( V_3 ) ;
V_9 = F_1 ( V_3 , V_82 ) ;
V_63 = F_36 ( V_9 ) ;
F_37 ( V_76 , & V_63 ) ;
if ( V_10 )
goto V_91;
F_30 ( V_77 ) ;
if ( V_10 )
goto V_91;
F_38 ( V_3 -> V_78 ) ;
if ( ! F_43 ( V_92 , & V_45 -> V_86 ) &&
! ( V_36 -> V_58 . V_88 & V_89 ) )
F_14 ( V_3 ) ;
F_40 ( & V_3 -> V_66 . V_67 ,
V_79 + F_41 ( V_80 ) ) ;
if ( F_43 ( V_92 , & V_45 -> V_86 ) &&
V_3 -> V_93 . V_94 == V_95 )
F_47 ( V_45 , & V_3 -> V_93 ) ;
V_91:
F_8 ( V_3 ) ;
return V_10 ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_96 V_97 ;
int V_10 = 0 ;
T_1 V_64 ;
memset ( & V_97 , 0 , sizeof( struct V_96 ) ) ;
memcpy ( & V_97 . V_98 , V_45 -> V_48 , V_42 ) ;
V_97 . V_99 = V_3 -> V_100 ;
F_37 ( V_101 , & V_97 ) ;
if ( V_10 ) {
F_33 ( V_45 , L_4 ,
V_3 -> V_100 ) ;
}
V_3 -> V_102 -- ;
V_3 -> V_103 &= ~ ( 1 << V_3 -> V_100 ) ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_96 V_97 ;
struct V_104 V_105 ;
int V_10 = 0 , V_106 ;
T_1 V_64 ;
if ( ( V_3 -> V_102 >= V_107 ) ||
( V_3 -> V_108 >= V_109 ) ) {
V_10 = - V_110 ;
goto V_111;
}
V_106 = F_50 ( V_3 -> V_112 ) ;
if ( ( V_106 < 0 ) || ( V_106 > V_109 ) ) {
V_10 = - V_110 ;
goto V_111;
}
memset ( & V_97 , 0 , sizeof( struct V_96 ) ) ;
memcpy ( & V_97 . V_98 , V_45 -> V_48 , V_42 ) ;
V_97 . V_50 = V_113 ;
V_97 . V_99 = F_50 ( V_3 -> V_103 ) ;
F_37 ( V_114 , & V_97 ) ;
if ( V_10 )
goto V_111;
V_3 -> V_100 = V_97 . V_99 ;
V_3 -> V_103 |= ( 1 << V_97 . V_99 ) ;
if ( ! V_3 -> V_102 )
V_3 -> V_12 -> V_50 = V_115 ;
V_3 -> V_102 ++ ;
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
memcpy ( & V_105 . V_48 , V_45 -> V_48 , V_42 ) ;
V_105 . V_116 = 1 ;
V_105 . V_117 = V_106 ;
V_105 . V_118 = V_97 . V_99 ;
V_105 . V_119 = F_36 ( 0xffff ) ;
F_37 ( V_120 , & V_105 ) ;
if ( V_10 ) {
F_33 ( V_45 , L_5 ) ;
goto V_121;
}
V_3 -> V_112 |= ( 1 << V_106 ) ;
V_3 -> V_108 ++ ;
V_3 -> V_122 [ V_3 -> V_100 ] = V_106 ;
V_3 -> V_12 -> V_123 = true ;
F_44 ( V_45 , V_90 ,
L_6 ,
V_3 -> V_100 , V_106 ) ;
return 0 ;
V_121:
F_48 ( V_3 ) ;
V_111:
F_44 ( V_45 , V_124 , L_7 ) ;
return V_10 ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
int V_10 = 0 ;
T_1 V_64 , V_106 ;
F_48 ( V_3 ) ;
V_106 = V_3 -> V_122 [ V_3 -> V_100 ] ;
F_37 ( V_125 , & V_106 ) ;
if ( V_10 ) {
F_33 ( V_45 , L_8 ) ;
return V_10 ;
}
V_3 -> V_112 &= ~ ( 1 << V_106 ) ;
V_3 -> V_108 -- ;
V_3 -> V_12 -> V_123 = false ;
F_44 ( V_45 , V_90 ,
L_9 ,
V_3 -> V_100 , V_106 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_126 * V_127 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_104 V_105 ;
struct V_128 * V_129 = (struct V_128 * ) V_27 -> V_130 ;
struct V_131 * V_132 ;
int V_10 , V_106 ;
T_1 V_64 ;
T_3 V_119 ;
if ( V_3 -> V_108 >= V_109 )
return - V_110 ;
V_106 = F_50 ( V_3 -> V_112 ) ;
if ( ( V_106 < 0 ) || ( V_106 > V_109 ) )
return - V_110 ;
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
if ( V_127 ) {
V_132 = (struct V_131 * ) V_127 -> V_130 ;
memcpy ( & V_105 . V_48 , V_127 -> V_46 , V_42 ) ;
memcpy ( & V_105 . V_133 , V_45 -> V_134 , V_42 ) ;
V_132 -> V_99 = V_106 ;
V_105 . V_116 = 0 ;
V_119 = 1 << ( V_135 +
V_127 -> V_136 . V_137 ) ;
V_105 . V_119 = F_36 ( V_119 ) ;
} else {
memcpy ( & V_105 . V_48 , V_27 -> V_46 , V_42 ) ;
V_105 . V_116 = 1 ;
V_105 . V_119 = F_36 ( 0xffff ) ;
}
V_105 . V_117 = V_106 ;
V_105 . V_118 = V_129 -> V_99 ;
F_37 ( V_120 , & V_105 ) ;
if ( V_10 ) {
if ( V_127 )
F_33 ( V_45 ,
L_10 ,
V_127 -> V_46 ) ;
return V_10 ;
}
if ( V_127 ) {
F_44 ( V_45 , V_90 ,
L_11 ,
V_127 -> V_46 , V_105 . V_117 ) ;
} else {
F_44 ( V_45 , V_90 ,
L_12 ,
V_129 -> V_99 , V_105 . V_117 ) ;
}
V_3 -> V_112 |= ( 1 << V_106 ) ;
V_3 -> V_108 ++ ;
if ( ! V_127 )
V_3 -> V_122 [ V_129 -> V_99 ] = V_106 ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_126 * V_127 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_128 * V_129 = (struct V_128 * ) V_27 -> V_130 ;
struct V_131 * V_132 ;
int V_10 ;
T_1 V_64 , V_106 ;
if ( V_127 ) {
V_132 = (struct V_131 * ) V_127 -> V_130 ;
V_106 = V_132 -> V_99 ;
} else {
V_106 = V_3 -> V_122 [ V_129 -> V_99 ] ;
}
F_37 ( V_125 , & V_106 ) ;
if ( V_10 ) {
if ( V_127 )
F_33 ( V_45 ,
L_13 ,
V_127 -> V_46 ) ;
return V_10 ;
}
if ( V_127 ) {
F_44 ( V_45 , V_90 ,
L_14 ,
V_127 -> V_46 , V_106 ) ;
} else {
F_44 ( V_45 , V_90 ,
L_15 ,
V_129 -> V_99 , V_106 ) ;
}
V_3 -> V_112 &= ~ ( 1 << V_106 ) ;
V_3 -> V_108 -- ;
return 0 ;
}
int F_54 ( struct V_2 * V_3 ,
T_1 V_138 )
{
struct V_139 V_140 ;
int V_10 ;
T_1 V_64 ;
memset ( & V_140 , 0 , sizeof( struct V_139 ) ) ;
V_140 . V_141 = F_55 ( 0xffff ) ;
V_140 . V_142 = 0xff ;
V_140 . V_138 = V_138 ;
V_140 . V_143 = V_3 -> V_12 -> V_144 . V_143 ;
F_37 ( V_145 , & V_140 ) ;
return V_10 ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_126 * V_127 ,
struct V_146 * V_147 )
{
struct V_131 * V_132 = (struct V_131 * ) V_127 -> V_130 ;
struct V_148 * V_149 ;
T_4 V_144 = 0 ;
int V_40 , V_150 ;
V_149 = V_3 -> V_36 -> V_151 -> V_152 [ V_3 -> V_36 -> V_58 . V_59 . V_60 -> V_153 ] ;
for ( V_40 = 0 , V_150 = 0 ; V_40 < V_149 -> V_154 ; V_40 ++ ) {
if ( V_127 -> V_155 [ V_149 -> V_153 ] & F_57 ( V_40 ) ) {
V_147 -> V_156 . V_157 . V_158 [ V_150 ]
= ( V_149 -> V_159 [ V_40 ] . V_160 * 2 ) / 10 ;
V_150 ++ ;
}
}
V_147 -> V_156 . V_157 . V_161 = V_150 ;
if ( V_127 -> V_136 . V_162 ) {
for ( V_40 = 0 , V_150 = 0 ; V_40 < 77 ; V_40 ++ ) {
if ( V_127 -> V_136 . V_163 . V_164 [ V_40 / 8 ] & ( 1 << ( V_40 % 8 ) ) )
V_147 -> V_156 . V_165 . V_158 [ V_150 ++ ] = V_40 ;
if ( V_150 == V_166 )
break;
}
V_147 -> V_156 . V_165 . V_161 = V_150 ;
V_144 = V_167 ;
if ( V_127 -> V_136 . V_168 & V_169 )
V_144 |= V_170 ;
if ( V_127 -> V_136 . V_163 . V_164 [ 1 ] )
V_144 |= V_171 ;
if ( ( V_127 -> V_136 . V_168 & V_172 ) &&
( F_46 ( & V_3 -> V_36 -> V_58 ) ) )
V_144 |= V_173 ;
if ( F_46 ( & V_3 -> V_36 -> V_58 ) &&
( V_127 -> V_136 . V_168 & V_174 ) )
V_144 |= V_175 ;
else if ( F_58 ( & V_3 -> V_36 -> V_58 ) &&
( V_127 -> V_136 . V_168 & V_176 ) )
V_144 |= V_175 ;
}
V_147 -> V_117 = V_132 -> V_99 ;
V_147 -> V_177 = 1 ;
V_147 -> V_178 = F_55 ( V_144 ) ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_146 * V_147 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
int V_10 ;
T_1 V_64 ;
F_37 ( V_179 , V_147 ) ;
if ( V_10 ) {
F_33 ( V_45 ,
L_16 ) ;
}
return V_10 ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_126 * V_127 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_146 V_147 ;
int V_10 ;
memset ( & V_147 , 0 , sizeof( struct V_146 ) ) ;
F_56 ( V_3 , V_127 , & V_147 ) ;
V_10 = F_59 ( V_3 , & V_147 ) ;
if ( ! V_10 )
F_44 ( V_45 , V_90 ,
L_17 ,
V_127 -> V_46 , F_61 ( V_147 . V_178 ) ) ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_146 V_147 ;
struct V_126 * V_127 ;
int V_10 ;
memset ( & V_147 , 0 , sizeof( struct V_146 ) ) ;
F_63 () ;
V_127 = F_64 ( V_27 , V_29 -> V_133 ) ;
if ( ! V_127 ) {
F_65 () ;
return;
}
F_56 ( V_3 , V_127 , & V_147 ) ;
F_65 () ;
V_10 = F_59 ( V_3 , & V_147 ) ;
if ( ! V_10 )
F_44 ( V_45 , V_90 ,
L_17 ,
V_29 -> V_133 , F_61 ( V_147 . V_178 ) ) ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_126 * V_127 ,
enum V_180 V_181 ,
T_3 V_182 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_183 V_184 ;
struct V_131 * V_132 ;
int V_10 = 0 ;
T_1 V_64 ;
if ( V_182 >= V_185 )
return - V_186 ;
memset ( & V_184 , 0 , sizeof( struct V_183 ) ) ;
V_132 = (struct V_131 * ) V_127 -> V_130 ;
V_184 . V_117 = V_132 -> V_99 ;
V_184 . V_187 = V_182 & 0xf ;
V_184 . V_188 = ( V_181 == V_189 ) ? true : false ;
F_37 ( V_190 , & V_184 ) ;
if ( V_10 )
F_44 ( V_45 , V_90 ,
L_18 ,
( V_184 . V_188 ) ? L_19 : L_20 , V_127 -> V_46 , V_182 ) ;
else
F_44 ( V_45 , V_90 ,
L_21 ,
( V_184 . V_188 ) ? L_22 : L_23 ,
V_127 -> V_46 , V_182 ) ;
F_67 ( & V_3 -> V_66 . V_191 ) ;
V_132 -> V_192 [ V_182 ] = ( V_184 . V_188 && ! V_10 ) ? V_193 : V_194 ;
F_68 ( & V_3 -> V_66 . V_191 ) ;
return V_10 ;
}
void F_16 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
unsigned long V_195 = F_69 ( V_79 ) ;
V_45 -> V_196 . V_197 = V_195 ;
V_45 -> V_196 . V_198 = V_195 ;
V_45 -> V_196 . V_199 = V_195 ;
F_70 ( V_200 , & V_45 -> V_86 ) ;
F_71 ( V_45 -> V_36 , & V_3 -> V_201 ,
F_41 ( V_202 ) ) ;
}
void F_26 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
F_72 ( & V_3 -> V_201 ) ;
F_73 ( V_200 , & V_45 -> V_86 ) ;
}
void F_74 ( struct V_21 * V_22 )
{
struct V_2 * V_3 =
F_12 ( V_22 , struct V_2 , V_201 . V_22 ) ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
bool V_203 = false ;
bool V_204 = false ;
bool V_205 = false ;
unsigned int V_195 = F_69 ( V_79 ) ;
T_4 V_206 , V_207 ;
V_207 = ( V_12 -> V_50 == V_30 ) ?
V_208 : V_209 ;
if ( V_12 -> V_210 != V_15 )
goto V_211;
if ( ( V_195 - V_45 -> V_196 . V_197 ) >= V_212 ) {
V_203 = true ;
F_44 ( V_45 , V_213 , L_24 , V_79 ) ;
V_45 -> V_196 . V_197 = V_195 ;
}
if ( V_45 -> V_196 . V_214 <= 0 ) {
if ( ( V_195 - V_45 -> V_196 . V_198 ) >=
V_207 ) {
V_204 = true ;
F_44 ( V_45 , V_213 , L_25 , V_79 ) ;
V_45 -> V_196 . V_198 = V_195 ;
V_45 -> V_196 . V_215 = V_195 ;
}
} else {
if ( ( V_195 - V_45 -> V_196 . V_215 ) >=
V_216 ) {
V_45 -> V_196 . V_214 = F_75 ( V_12 ) ;
if ( V_45 -> V_196 . V_214 )
V_45 -> V_196 . V_215 = V_195 ;
}
}
if ( ( V_195 - V_45 -> V_196 . V_199 ) >= V_202 ) {
V_205 = true ;
V_45 -> V_196 . V_199 = V_195 ;
}
if ( V_203 || V_204 || V_205 ) {
F_7 ( V_3 ) ;
if ( V_205 )
F_76 ( V_12 , V_12 -> V_71 ) ;
if ( V_203 || V_204 )
V_45 -> V_196 . V_214 =
F_77 ( V_12 , V_12 -> V_71 ,
V_12 -> V_217 , V_203 ) > 0 ;
F_8 ( V_3 ) ;
}
V_211:
V_206 = V_212 ;
V_206 = F_78 ( V_206 , ( T_4 ) V_202 ) ;
if ( V_45 -> V_196 . V_214 <= 0 )
V_206 = F_78 ( V_206 , ( T_4 ) V_207 ) ;
F_71 ( V_45 -> V_36 , & V_3 -> V_201 ,
F_41 ( V_206 ) ) ;
}
static void F_79 ( struct V_81 * V_36 ,
struct V_218 * V_219 ,
struct V_220 * V_221 )
{
struct V_222 * V_223 ;
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
int V_224 , V_225 , V_10 , V_226 ;
V_223 = (struct V_222 * ) V_221 -> V_24 ;
V_224 = F_80 ( V_223 -> V_227 ) ;
V_225 = V_224 & 3 ;
if ( V_225 && V_221 -> V_228 > V_224 ) {
if ( F_81 ( V_221 ) < V_225 ) {
F_44 ( V_45 , V_229 , L_26 ) ;
goto V_230;
}
F_82 ( V_221 , V_225 ) ;
memmove ( V_221 -> V_24 , V_221 -> V_24 + V_225 , V_224 ) ;
}
V_226 = F_83 ( V_3 ) ;
if ( V_226 < 0 ) {
F_44 ( V_45 , V_229 , L_27 ) ;
goto V_230;
}
V_10 = F_84 ( V_3 , V_219 -> V_127 , V_221 , V_226 , false ) ;
if ( V_10 != 0 ) {
F_44 ( V_45 , V_229 , L_28 ) ;
goto V_231;
}
F_85 ( V_3 ) ;
return;
V_231:
F_86 ( V_3 , V_226 ) ;
V_230:
F_87 ( V_221 ) ;
}
static int F_88 ( struct V_81 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
struct V_56 * V_71 = V_36 -> V_58 . V_59 . V_60 ;
struct V_4 * V_232 ;
int V_10 = 0 ;
enum V_1 V_9 ;
T_2 V_63 ;
T_1 V_64 ;
F_4 ( & V_3 -> V_65 ) ;
F_44 ( V_45 , V_90 ,
L_29 ,
V_71 -> V_72 ) ;
F_3 ( V_3 , V_15 ) ;
F_30 ( V_233 ) ;
V_232 = F_89 ( V_36 , V_12 , & V_36 -> V_58 . V_59 ) ;
V_10 = F_32 ( V_12 , V_232 , V_12 -> V_62 , false ) ;
if ( V_10 ) {
F_33 ( V_45 ,
L_30 ,
V_10 , V_71 -> V_72 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
F_34 ( V_12 , V_3 -> V_73 , V_3 -> V_74 ,
& V_3 -> V_73 ) ;
V_9 = F_1 ( V_3 , V_232 ) ;
V_63 = F_36 ( V_9 ) ;
F_37 ( V_76 , & V_63 ) ;
F_30 ( V_234 ) ;
F_30 ( V_75 ) ;
F_35 ( V_3 ) ;
V_10 = F_54 ( V_3 , 0 ) ;
if ( V_10 )
F_44 ( V_45 , V_90 ,
L_31 ) ;
F_73 ( V_85 , & V_45 -> V_86 ) ;
F_38 ( V_3 -> V_78 ) ;
F_67 ( & V_3 -> V_66 . V_191 ) ;
V_3 -> V_66 . V_88 &= ~ V_235 ;
F_68 ( & V_3 -> V_66 . V_191 ) ;
F_39 ( V_36 ) ;
F_40 ( & V_3 -> V_66 . V_67 ,
V_79 + F_41 ( V_80 ) ) ;
F_90 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_91 ( struct V_81 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
int V_10 V_236 ( ( V_237 ) ) ;
T_1 V_64 ;
F_4 ( & V_3 -> V_65 ) ;
if ( F_43 ( V_85 , & V_45 -> V_86 ) ) {
F_44 ( V_45 , V_238 , L_32 ) ;
F_6 ( & V_3 -> V_65 ) ;
return;
}
F_7 ( V_3 ) ;
F_30 ( V_68 ) ;
F_30 ( V_69 ) ;
F_30 ( V_70 ) ;
F_92 ( & V_3 -> V_239 ) ;
F_28 ( & V_3 -> V_66 . V_67 ) ;
F_29 ( V_3 ) ;
F_31 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
F_93 ( & V_3 -> V_240 ) ;
F_93 ( & V_3 -> V_23 ) ;
#ifdef F_94
F_93 ( & V_3 -> V_241 ) ;
#endif
F_26 ( V_3 ) ;
F_4 ( & V_3 -> V_65 ) ;
F_95 ( V_3 ) ;
if ( V_3 -> V_12 -> V_123 )
F_51 ( V_3 ) ;
F_96 ( V_12 ) ;
F_97 ( V_12 ) ;
F_8 ( V_3 ) ;
F_3 ( V_3 , V_18 ) ;
F_70 ( V_85 , & V_45 -> V_86 ) ;
F_44 ( V_45 , V_90 , L_33 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_98 ( struct V_81 * V_36 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_128 * V_129 = ( void * ) V_27 -> V_130 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_96 V_97 ;
int V_10 = 0 ;
T_1 V_64 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
memset ( & V_97 , 0 , sizeof( struct V_96 ) ) ;
memcpy ( & V_97 . V_98 , V_27 -> V_46 , V_42 ) ;
switch ( V_27 -> type ) {
case V_54 :
V_97 . V_50 = V_242 ;
break;
case V_51 :
V_97 . V_50 = V_243 ;
break;
case V_30 :
V_97 . V_50 = V_244 ;
break;
case V_31 :
V_97 . V_50 = V_245 ;
break;
default:
F_33 ( V_45 ,
L_34 , V_27 -> type ) ;
V_10 = - V_246 ;
goto V_247;
}
V_129 -> V_99 = V_97 . V_99 = F_50 ( V_3 -> V_103 ) ;
V_97 . V_248 = F_36 ( 2304 ) ;
F_37 ( V_114 , & V_97 ) ;
if ( V_10 )
goto V_247;
V_10 = F_52 ( V_3 , V_27 , NULL ) ;
if ( V_10 ) {
F_37 ( V_101 , & V_97 ) ;
goto V_247;
}
F_19 ( V_3 , V_27 ) ;
V_3 -> V_103 |= ( 1 << V_129 -> V_99 ) ;
V_3 -> V_102 ++ ;
F_99 ( V_3 , V_27 -> type ) ;
if ( ( V_27 -> type == V_30 ) ||
( V_27 -> type == V_31 ) ||
( V_27 -> type == V_51 ) )
F_100 ( V_3 , V_27 ) ;
F_23 ( V_3 ) ;
if ( ( V_3 -> V_12 -> V_50 == V_30 ) &&
! F_43 ( V_200 , & V_45 -> V_86 ) ) {
F_101 ( V_3 -> V_12 , true ) ;
F_16 ( V_3 ) ;
}
F_44 ( V_45 , V_90 , L_35 ,
V_27 -> type , V_129 -> V_99 ) ;
V_247:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_102 ( struct V_81 * V_36 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_128 * V_129 = ( void * ) V_27 -> V_130 ;
struct V_96 V_97 ;
int V_10 = 0 ;
T_1 V_64 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
memset ( & V_97 , 0 , sizeof( struct V_96 ) ) ;
memcpy ( & V_97 . V_98 , V_27 -> V_46 , V_42 ) ;
V_97 . V_99 = V_129 -> V_99 ;
F_37 ( V_101 , & V_97 ) ;
if ( V_10 ) {
F_33 ( V_45 , L_36 ,
V_129 -> V_99 ) ;
}
V_3 -> V_102 -- ;
V_3 -> V_103 &= ~ ( 1 << V_129 -> V_99 ) ;
if ( V_3 -> V_249 == V_27 )
V_3 -> V_249 = NULL ;
F_53 ( V_3 , V_27 , NULL ) ;
F_103 ( V_3 , V_27 -> type ) ;
if ( ( V_27 -> type == V_30 ) ||
V_27 -> type == V_31 ||
( V_27 -> type == V_51 ) )
F_104 ( V_3 , V_27 ) ;
F_23 ( V_3 ) ;
F_19 ( V_3 , V_27 ) ;
if ( ( V_27 -> type == V_30 ) && ( V_3 -> V_52 == 0 ) ) {
V_3 -> V_34 = false ;
F_15 (
V_3 -> V_36 , V_37 ,
F_13 , V_3 ) ;
if ( ! V_3 -> V_34 )
F_26 ( V_3 ) ;
}
F_44 ( V_45 , V_90 , L_37 , V_129 -> V_99 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_105 ( struct V_81 * V_36 , T_4 V_250 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_83 * V_58 = & V_36 -> V_58 ;
bool V_251 = false ;
int V_10 = 0 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
if ( V_250 & V_252 ) {
F_4 ( & V_3 -> V_11 ) ;
V_3 -> V_17 = ! ! ( V_58 -> V_88 & V_253 ) ;
if ( ! V_3 -> V_17 )
V_251 = true ;
F_6 ( & V_3 -> V_11 ) ;
}
if ( V_250 & V_254 ) {
if ( ( V_58 -> V_88 & V_255 ) &&
! V_3 -> V_12 -> V_123 )
F_49 ( V_3 ) ;
else if ( V_3 -> V_12 -> V_123 )
F_51 ( V_3 ) ;
}
if ( ( V_250 & V_256 ) || V_251 ) {
struct V_56 * V_71 = V_36 -> V_58 . V_59 . V_60 ;
int V_257 = V_71 -> V_258 ;
F_44 ( V_45 , V_90 , L_38 ,
V_71 -> V_72 ) ;
F_89 ( V_36 , V_3 -> V_12 , & V_36 -> V_58 . V_59 ) ;
if ( F_42 ( V_3 , V_36 , & V_3 -> V_12 -> V_259 [ V_257 ] ) < 0 ) {
F_33 ( V_45 , L_39 ) ;
V_10 = - V_186 ;
goto V_247;
}
}
if ( V_250 & V_260 ) {
if ( V_58 -> V_88 & V_261 ) {
F_3 ( V_3 , V_20 ) ;
V_3 -> V_19 = true ;
} else {
V_3 -> V_19 = false ;
F_93 ( & V_3 -> V_23 ) ;
F_3 ( V_3 , V_15 ) ;
}
}
if ( V_250 & V_262 ) {
V_3 -> V_74 = 2 * V_58 -> V_263 ;
F_34 ( V_3 -> V_12 , V_3 -> V_73 ,
V_3 -> V_74 , & V_3 -> V_73 ) ;
}
V_247:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_106 ( struct V_81 * V_36 ,
unsigned int V_264 ,
unsigned int * V_265 ,
T_5 V_266 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
T_4 V_267 ;
F_4 ( & V_3 -> V_65 ) ;
V_264 &= V_268 ;
* V_265 &= V_268 ;
if ( F_43 ( V_85 , & V_45 -> V_86 ) ) {
F_44 ( F_20 ( V_3 -> V_12 ) , V_238 ,
L_40 ) ;
F_6 ( & V_3 -> V_65 ) ;
return;
}
F_7 ( V_3 ) ;
V_3 -> V_269 = * V_265 ;
V_267 = F_107 ( V_3 ) ;
F_108 ( V_3 -> V_12 , V_267 ) ;
F_44 ( F_20 ( V_3 -> V_12 ) , V_90 , L_41 ,
V_267 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static void F_109 ( struct V_21 * V_22 )
{
struct V_131 * V_132 =
F_12 ( V_22 , struct V_131 , V_270 ) ;
struct V_126 * V_127 =
F_12 ( ( void * ) V_132 , struct V_126 , V_130 ) ;
struct V_2 * V_3 = V_132 -> V_271 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_146 V_147 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
memset ( & V_147 , 0 , sizeof( struct V_146 ) ) ;
F_56 ( V_3 , V_127 , & V_147 ) ;
if ( ! F_59 ( V_3 , & V_147 ) )
F_44 ( V_45 , V_90 ,
L_42 ,
V_127 -> V_46 , F_61 ( V_147 . V_178 ) ) ;
else
F_44 ( V_45 , V_90 ,
L_43 ,
V_127 -> V_46 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_110 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_126 * V_127 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_131 * V_132 = (struct V_131 * ) V_127 -> V_130 ;
int V_10 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
V_10 = F_52 ( V_3 , V_27 , V_127 ) ;
if ( ! V_10 ) {
F_111 ( & V_132 -> V_270 , F_109 ) ;
V_132 -> V_271 = V_3 ;
F_60 ( V_3 , V_127 ) ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static int F_112 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_126 * V_127 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_131 * V_132 = (struct V_131 * ) V_127 -> V_130 ;
int V_10 ;
F_93 ( & V_132 -> V_270 ) ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
F_113 ( V_3 -> V_78 , V_132 -> V_99 ) ;
V_10 = F_53 ( V_3 , V_27 , V_127 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_114 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_126 * V_127 , T_4 V_250 )
{
struct V_131 * V_132 = (struct V_131 * ) V_127 -> V_130 ;
if ( ! ( V_250 & V_272 ) )
return;
F_115 ( & V_132 -> V_270 ) ;
}
static int F_116 ( struct V_81 * V_36 ,
struct V_26 * V_27 , T_3 V_273 ,
const struct V_274 * V_275 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_276 V_277 ;
int V_10 = 0 , V_278 ;
if ( V_273 >= V_279 )
return 0 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
memset ( & V_277 , 0 , sizeof( struct V_276 ) ) ;
V_277 . V_280 = V_275 -> V_281 ;
V_277 . V_282 = V_275 -> V_283 ;
V_277 . V_284 = V_275 -> V_285 ;
V_277 . V_286 = V_275 -> V_287 * 32 ;
V_278 = F_117 ( V_273 , V_3 -> V_288 ) ;
F_44 ( V_45 , V_90 ,
L_44 ,
V_273 , V_278 , V_275 -> V_281 , V_275 -> V_283 ,
V_275 -> V_285 , V_275 -> V_287 ) ;
V_10 = F_118 ( V_3 , V_278 , & V_277 ) ;
if ( V_10 ) {
F_33 ( V_45 , L_45 ) ;
goto V_247;
}
if ( ( V_3 -> V_12 -> V_50 == V_51 ) &&
( V_278 == V_3 -> V_288 [ V_289 ] ) )
F_119 ( V_3 ) ;
V_247:
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static int F_120 ( struct V_81 * V_36 ,
enum V_290 V_291 ,
struct V_26 * V_27 ,
struct V_126 * V_127 ,
struct V_292 * V_293 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
int V_10 = 0 ;
if ( V_294 )
return - V_295 ;
if ( ( V_27 -> type == V_51 ||
V_27 -> type == V_31 ) &&
( V_293 -> V_296 == V_297 ||
V_293 -> V_296 == V_298 ) &&
! ( V_293 -> V_88 & V_299 ) ) {
return - V_246 ;
}
F_4 ( & V_3 -> V_65 ) ;
F_44 ( V_45 , V_90 , L_46 ) ;
F_7 ( V_3 ) ;
switch ( V_291 ) {
case V_300 :
V_10 = F_121 ( V_45 , V_27 , V_127 , V_293 ) ;
if ( V_10 >= 0 ) {
V_293 -> V_301 = V_10 ;
V_293 -> V_88 |= V_302 ;
if ( V_293 -> V_296 == V_297 )
V_293 -> V_88 |= V_303 ;
if ( V_3 -> V_12 -> V_304 &&
V_293 -> V_296 == V_298 )
V_293 -> V_88 |= V_305 ;
V_10 = 0 ;
}
break;
case V_306 :
F_122 ( V_45 , V_293 ) ;
break;
default:
V_10 = - V_186 ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_123 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
F_124 ( V_3 -> V_12 ) ;
F_44 ( V_45 , V_90 , L_47 ,
V_45 -> V_134 , V_45 -> V_307 ) ;
}
static void F_125 ( void * V_24 , T_1 * V_25 , struct V_26 * V_27 )
{
struct V_2 * V_3 = (struct V_2 * ) V_24 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_28 * V_29 = & V_27 -> V_29 ;
if ( ( V_27 -> type == V_54 ) && V_29 -> V_35 ) {
V_45 -> V_307 = V_29 -> V_308 ;
V_45 -> V_309 = V_310 ;
memcpy ( V_45 -> V_134 , V_29 -> V_133 , V_42 ) ;
F_70 ( V_311 , & V_45 -> V_86 ) ;
}
}
static void F_126 ( struct V_2 * V_3 )
{
if ( V_3 -> V_312 == 1 ) {
F_15 (
V_3 -> V_36 , V_37 ,
F_125 , V_3 ) ;
F_123 ( V_3 ) ;
}
}
static void F_127 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_28 * V_29 ,
T_4 V_250 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_44 * V_45 = F_20 ( V_12 ) ;
int V_313 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
if ( V_250 & V_314 ) {
F_44 ( V_45 , V_90 , L_48 ,
V_29 -> V_35 ) ;
V_29 -> V_35 ?
V_3 -> V_312 ++ : V_3 -> V_312 -- ;
if ( ! V_29 -> V_35 )
F_73 ( V_311 , & V_45 -> V_86 ) ;
if ( V_3 -> V_12 -> V_50 == V_54 ) {
F_126 ( V_3 ) ;
if ( V_29 -> V_35 && ( V_3 -> V_312 == 1 ) )
F_16 ( V_3 ) ;
else if ( V_3 -> V_312 == 0 )
F_26 ( V_3 ) ;
}
}
if ( V_250 & V_315 ) {
if ( V_3 -> V_12 -> V_50 == V_51 ) {
V_45 -> V_307 = V_29 -> V_308 ;
memcpy ( V_45 -> V_134 , V_29 -> V_133 , V_42 ) ;
F_123 ( V_3 ) ;
}
}
if ( ( V_250 & V_316 ) && V_29 -> V_32 ) {
F_44 ( V_45 , V_90 , L_49 ,
V_29 -> V_133 ) ;
F_128 ( V_3 , V_27 ) ;
V_3 -> V_317 . V_32 = 1 ;
F_129 ( V_3 , V_27 ) ;
}
if ( ( V_250 & V_316 ) && ! V_29 -> V_32 ) {
if ( ( V_3 -> V_52 + V_3 -> V_53 <= 1 ) ||
V_3 -> V_49 ) {
F_44 ( V_45 , V_90 ,
L_50 ,
V_29 -> V_133 ) ;
V_3 -> V_317 . V_32 = 0 ;
F_129 ( V_3 , V_27 ) ;
}
}
if ( V_250 & V_318 ) {
if ( V_3 -> V_102 == 1 &&
( ( V_3 -> V_12 -> V_50 == V_30 &&
V_27 -> type == V_30 &&
V_3 -> V_52 == 1 ) ||
( V_3 -> V_12 -> V_50 == V_31 &&
V_27 -> type == V_31 &&
V_3 -> V_53 == 1 ) ) ) {
F_70 ( V_319 , & V_3 -> V_86 ) ;
}
F_44 ( V_45 , V_90 ,
L_51 ,
V_29 -> V_133 ) ;
F_129 ( V_3 , V_27 ) ;
}
if ( V_250 & V_320 ) {
if ( V_29 -> V_321 )
V_313 = 9 ;
else
V_313 = 20 ;
if ( V_27 -> type == V_30 ) {
V_3 -> V_322 . V_313 = V_313 ;
V_3 -> V_322 . V_323 = V_324 ;
} else {
V_12 -> V_313 = V_313 ;
F_130 ( V_12 ) ;
}
}
if ( V_250 & V_325 )
F_62 ( V_3 , V_27 , V_29 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static T_5 F_131 ( struct V_81 * V_36 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
T_5 V_326 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
V_326 = F_132 ( V_3 -> V_12 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_326 ;
}
static void F_133 ( struct V_81 * V_36 ,
struct V_26 * V_27 , T_5 V_326 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
F_134 ( V_3 -> V_12 , V_326 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static void F_135 ( struct V_81 * V_36 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
F_136 ( V_3 -> V_12 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_137 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_327 * V_275 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_131 * V_132 ;
int V_10 = 0 ;
struct V_126 * V_127 = V_275 -> V_127 ;
enum V_180 V_181 = V_275 -> V_181 ;
T_3 V_182 = V_275 -> V_182 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
switch ( V_181 ) {
case V_328 :
break;
case V_329 :
break;
case V_189 :
V_10 = F_66 ( V_3 , V_27 , V_127 , V_181 , V_182 ) ;
if ( ! V_10 )
F_138 ( V_27 , V_127 -> V_46 , V_182 ) ;
break;
case V_330 :
case V_331 :
case V_332 :
F_66 ( V_3 , V_27 , V_127 , V_181 , V_182 ) ;
F_139 ( V_27 , V_127 -> V_46 , V_182 ) ;
break;
case V_333 :
V_132 = (struct V_131 * ) V_127 -> V_130 ;
F_67 ( & V_3 -> V_66 . V_191 ) ;
V_132 -> V_192 [ V_182 ] = V_334 ;
F_68 ( & V_3 -> V_66 . V_191 ) ;
break;
default:
F_33 ( F_20 ( V_3 -> V_12 ) , L_52 ) ;
}
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
return V_10 ;
}
static void F_140 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
const T_1 * V_335 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
F_4 ( & V_3 -> V_65 ) ;
F_67 ( & V_3 -> V_336 ) ;
F_70 ( V_92 , & V_45 -> V_86 ) ;
F_68 ( & V_3 -> V_336 ) ;
F_93 ( & V_3 -> V_23 ) ;
F_26 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static void F_141 ( struct V_81 * V_36 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
F_4 ( & V_3 -> V_65 ) ;
F_67 ( & V_3 -> V_336 ) ;
F_73 ( V_92 , & V_45 -> V_86 ) ;
F_68 ( & V_3 -> V_336 ) ;
F_7 ( V_3 ) ;
F_14 ( V_3 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_142 ( struct V_81 * V_36 , T_4 V_337 )
{
return 0 ;
}
static void F_143 ( struct V_81 * V_36 ,
T_6 V_338 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
F_4 ( & V_3 -> V_65 ) ;
F_7 ( V_3 ) ;
V_3 -> V_12 -> V_338 = V_338 ;
F_130 ( V_3 -> V_12 ) ;
F_8 ( V_3 ) ;
F_6 ( & V_3 -> V_65 ) ;
}
static int F_144 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
const struct V_339 * V_43 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_44 * V_45 = F_20 ( V_3 -> V_12 ) ;
struct V_340 V_341 ;
struct V_128 * V_129 = ( void * ) V_27 -> V_130 ;
int V_10 = 0 ;
T_1 V_64 ;
memset ( & V_341 , 0 , sizeof( struct V_340 ) ) ;
V_341 . V_118 = V_129 -> V_99 ;
V_341 . V_153 = V_342 ;
V_341 . V_43 = F_55 ( V_43 -> V_219 [ V_342 ] . V_343 ) ;
F_37 ( V_344 , & V_341 ) ;
if ( V_10 ) {
F_33 ( V_45 ,
L_53
L_54 , V_129 -> V_99 ) ;
goto V_247;
}
V_341 . V_153 = V_345 ;
V_341 . V_43 = F_55 ( V_43 -> V_219 [ V_345 ] . V_343 ) ;
F_37 ( V_344 , & V_341 ) ;
if ( V_10 ) {
F_33 ( V_45 ,
L_55
L_54 , V_129 -> V_99 ) ;
goto V_247;
}
F_44 ( V_45 , V_90 , L_56 ,
V_43 -> V_219 [ V_342 ] . V_343 ,
V_43 -> V_219 [ V_345 ] . V_343 ) ;
V_247:
return V_10 ;
}
static int F_145 ( struct V_81 * V_36 ,
struct V_346 * V_347 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_55 * V_12 = V_3 -> V_12 ;
struct V_348 * V_349 = & V_12 -> V_350 ;
V_347 -> V_351 = V_349 -> V_352 ;
V_347 -> V_353 = V_349 -> V_354 ;
V_347 -> V_355 = V_349 -> V_356 ;
V_347 -> V_357 = V_349 -> V_358 ;
return 0 ;
}
struct V_359 * F_146 ( struct V_2 * V_3 )
{
struct V_359 * V_360 = NULL ;
if ( F_147 ( V_3 -> V_12 ) )
V_360 = (struct V_359 * )
& V_3 -> V_12 -> V_361 . V_362 . V_363 ;
else if ( V_3 -> V_12 -> V_364 . V_365 == V_366 )
V_360 = (struct V_359 * )
& V_3 -> V_12 -> V_361 . V_367 . V_363 ;
else if ( V_3 -> V_12 -> V_364 . V_365 == V_368 )
V_360 = (struct V_359 * )
& V_3 -> V_12 -> V_361 . V_369 . V_363 ;
return V_360 ;
}
static int F_148 ( struct V_81 * V_36 , T_4 * V_370 ,
T_4 * V_371 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_359 * V_360 = F_146 ( V_3 ) ;
if ( V_360 ) {
* V_370 = V_360 -> V_372 ;
* V_371 = V_360 -> V_373 ;
} else {
* V_370 = 0 ;
* V_371 = 0 ;
}
return 0 ;
}
static void F_149 ( struct V_81 * V_36 ,
struct V_26 * V_27 ,
struct V_374 * V_59 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
if ( F_150 ( V_3 -> V_249 ) )
return;
V_3 -> V_249 = V_27 ;
}
