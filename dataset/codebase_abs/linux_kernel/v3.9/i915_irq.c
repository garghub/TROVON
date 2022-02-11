static void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
if ( ( V_1 -> V_3 & V_2 ) != 0 ) {
V_1 -> V_3 &= ~ V_2 ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_3 ( V_4 ) ;
}
}
static inline void
F_4 ( T_1 * V_1 , T_2 V_2 )
{
if ( ( V_1 -> V_3 & V_2 ) != V_2 ) {
V_1 -> V_3 |= V_2 ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_3 ( V_4 ) ;
}
}
void
F_5 ( T_1 * V_1 , int V_5 , T_2 V_2 )
{
if ( ( V_1 -> V_6 [ V_5 ] & V_2 ) != V_2 ) {
T_2 V_7 = F_6 ( V_5 ) ;
V_1 -> V_6 [ V_5 ] |= V_2 ;
F_2 ( V_7 , V_1 -> V_6 [ V_5 ] | ( V_2 >> 16 ) ) ;
F_3 ( V_7 ) ;
}
}
void
F_7 ( T_1 * V_1 , int V_5 , T_2 V_2 )
{
if ( ( V_1 -> V_6 [ V_5 ] & V_2 ) != 0 ) {
T_2 V_7 = F_6 ( V_5 ) ;
V_1 -> V_6 [ V_5 ] &= ~ V_2 ;
F_2 ( V_7 , V_1 -> V_6 [ V_5 ] ) ;
F_3 ( V_7 ) ;
}
}
void F_8 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
unsigned long V_11 ;
if ( F_9 ( V_9 ) )
return;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( F_11 ( V_9 ) )
F_1 ( V_1 , V_13 ) ;
else {
F_5 ( V_1 , 1 ,
V_14 ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 )
F_5 ( V_1 , 0 ,
V_14 ) ;
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static int
F_14 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
enum V_16 V_17 = F_15 ( V_1 ,
V_5 ) ;
return F_16 ( F_17 ( V_17 ) ) & V_18 ;
}
static T_2 F_18 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_19 ;
unsigned long V_20 ;
T_2 V_21 , V_22 , V_23 ;
if ( ! F_14 ( V_9 , V_5 ) ) {
F_19 ( L_1
L_2 , F_20 ( V_5 ) ) ;
return 0 ;
}
V_19 = F_21 ( V_5 ) ;
V_20 = F_22 ( V_5 ) ;
do {
V_21 = F_16 ( V_19 ) & V_24 ;
V_23 = F_16 ( V_20 ) & V_25 ;
V_22 = F_16 ( V_19 ) & V_24 ;
} while ( V_21 != V_22 );
V_21 >>= V_26 ;
V_23 >>= V_27 ;
return ( V_21 << 8 ) | V_23 ;
}
static T_2 F_23 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_7 = F_24 ( V_5 ) ;
if ( ! F_14 ( V_9 , V_5 ) ) {
F_19 ( L_1
L_2 , F_20 ( V_5 ) ) ;
return 0 ;
}
return F_16 ( V_7 ) ;
}
static int F_25 ( struct V_8 * V_9 , int V_5 ,
int * V_28 , int * V_29 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_30 = 0 , V_31 = 0 ;
int V_32 , V_33 , V_34 , V_35 ;
bool V_36 = true ;
int V_37 = 0 ;
enum V_16 V_17 = F_15 ( V_1 ,
V_5 ) ;
if ( ! F_14 ( V_9 , V_5 ) ) {
F_19 ( L_3
L_2 , F_20 ( V_5 ) ) ;
return 0 ;
}
V_35 = 1 + ( ( F_16 ( F_26 ( V_17 ) ) >> 16 ) & 0x1fff ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
V_31 = F_16 ( F_27 ( V_5 ) ) ;
* V_28 = V_31 & 0x1fff ;
* V_29 = 0 ;
} else {
V_31 = ( F_16 ( F_22 ( V_5 ) ) & V_38 ) >> V_39 ;
V_34 = 1 + ( ( F_16 ( F_28 ( V_17 ) ) >> 16 ) & 0x1fff ) ;
* V_28 = V_31 / V_34 ;
* V_29 = V_31 - ( * V_28 * V_34 ) ;
}
V_30 = F_16 ( F_29 ( V_17 ) ) ;
V_32 = V_30 & 0x1fff ;
V_33 = ( V_30 >> 16 ) & 0x1fff ;
if ( ( * V_28 < V_32 ) || ( * V_28 > V_33 ) )
V_36 = false ;
if ( V_36 && ( * V_28 >= V_32 ) )
* V_28 = * V_28 - V_35 ;
if ( V_30 > 0 )
V_37 |= V_40 | V_41 ;
if ( V_36 )
V_37 |= V_42 ;
return V_37 ;
}
static int F_30 ( struct V_8 * V_9 , int V_5 ,
int * V_43 ,
struct V_44 * V_45 ,
unsigned V_46 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
struct V_48 * V_49 ;
if ( V_5 < 0 || V_5 >= V_1 -> V_50 ) {
F_31 ( L_4 , V_5 ) ;
return - V_51 ;
}
V_49 = F_32 ( V_9 , V_5 ) ;
if ( V_49 == NULL ) {
F_31 ( L_4 , V_5 ) ;
return - V_51 ;
}
if ( ! V_49 -> V_52 ) {
F_33 ( L_5 , V_5 ) ;
return - V_53 ;
}
return F_34 ( V_9 , V_5 , V_43 ,
V_45 , V_46 ,
V_49 ) ;
}
static void F_35 ( struct V_54 * V_55 )
{
T_1 * V_1 = F_36 ( V_55 , T_1 ,
V_56 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
struct V_57 * V_58 = & V_9 -> V_58 ;
struct V_59 * V_60 ;
if ( ! V_1 -> V_61 )
return;
F_37 ( & V_58 -> V_62 ) ;
F_33 ( L_6 ) ;
F_38 (encoder, &mode_config->encoder_list, base.head)
if ( V_60 -> V_63 )
V_60 -> V_63 ( V_60 ) ;
F_39 ( & V_58 -> V_62 ) ;
F_40 ( V_9 ) ;
}
static void F_41 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
T_2 V_64 , V_65 , V_66 , V_67 ;
T_3 V_68 ;
unsigned long V_46 ;
F_10 ( & V_69 , V_46 ) ;
F_42 ( V_70 , F_16 ( V_70 ) ) ;
V_68 = V_1 -> V_71 . V_72 ;
F_42 ( V_70 , V_73 ) ;
V_64 = F_16 ( V_74 ) ;
V_65 = F_16 ( V_75 ) ;
V_66 = F_16 ( V_76 ) ;
V_67 = F_16 ( V_77 ) ;
if ( V_64 > V_66 ) {
if ( V_1 -> V_71 . V_72 != V_1 -> V_71 . V_78 )
V_68 = V_1 -> V_71 . V_72 - 1 ;
if ( V_68 < V_1 -> V_71 . V_78 )
V_68 = V_1 -> V_71 . V_78 ;
} else if ( V_65 < V_67 ) {
if ( V_1 -> V_71 . V_72 != V_1 -> V_71 . V_79 )
V_68 = V_1 -> V_71 . V_72 + 1 ;
if ( V_68 > V_1 -> V_71 . V_79 )
V_68 = V_1 -> V_71 . V_79 ;
}
if ( F_43 ( V_9 , V_68 ) )
V_1 -> V_71 . V_72 = V_68 ;
F_13 ( & V_69 , V_46 ) ;
return;
}
static void F_44 ( struct V_8 * V_9 ,
struct V_80 * V_81 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
if ( V_81 -> V_82 == NULL )
return;
F_45 ( V_81 , V_81 -> V_83 ( V_81 , false ) ) ;
F_46 ( & V_81 -> V_84 ) ;
if ( V_85 ) {
V_1 -> V_86 . V_87 = 0 ;
F_47 ( & V_1 -> V_86 . V_88 ,
F_48 ( V_89 + V_90 ) ) ;
}
}
static void F_49 ( struct V_54 * V_55 )
{
T_1 * V_1 = F_36 ( V_55 , T_1 ,
V_91 . V_55 ) ;
T_2 V_92 , V_93 ;
T_3 V_68 ;
F_50 ( & V_1 -> V_91 . V_94 ) ;
V_92 = V_1 -> V_91 . V_92 ;
V_1 -> V_91 . V_92 = 0 ;
V_93 = F_16 ( V_95 ) ;
F_2 ( V_95 , 0 ) ;
F_51 ( & V_1 -> V_91 . V_94 ) ;
if ( ( V_92 & V_96 ) == 0 )
return;
F_37 ( & V_1 -> V_91 . V_97 ) ;
if ( V_92 & V_98 )
V_68 = V_1 -> V_91 . V_72 + 1 ;
else
V_68 = V_1 -> V_91 . V_72 - 1 ;
if ( ! ( V_68 > V_1 -> V_91 . V_78 ||
V_68 < V_1 -> V_91 . V_79 ) ) {
F_52 ( V_1 -> V_9 , V_68 ) ;
}
F_39 ( & V_1 -> V_91 . V_97 ) ;
}
static void F_53 ( struct V_54 * V_55 )
{
T_1 * V_1 = F_36 ( V_55 , T_1 ,
V_99 . V_100 ) ;
T_2 V_101 , V_102 , V_103 , V_104 ;
char * V_105 [ 5 ] ;
T_4 V_106 ;
unsigned long V_46 ;
F_37 ( & V_1 -> V_9 -> V_107 ) ;
V_106 = F_16 ( V_108 ) ;
F_2 ( V_108 , V_106 & ~ V_109 ) ;
F_3 ( V_108 ) ;
V_101 = F_16 ( V_110 ) ;
V_102 = F_54 ( V_101 ) ;
V_103 = F_55 ( V_101 ) ;
V_104 = F_56 ( V_101 ) ;
F_2 ( V_110 , V_111 |
V_112 ) ;
F_3 ( V_110 ) ;
F_2 ( V_108 , V_106 ) ;
F_10 ( & V_1 -> V_12 , V_46 ) ;
V_1 -> V_113 &= ~ V_114 ;
F_2 ( V_115 , V_1 -> V_113 ) ;
F_13 ( & V_1 -> V_12 , V_46 ) ;
F_39 ( & V_1 -> V_9 -> V_107 ) ;
V_105 [ 0 ] = L_7 ;
V_105 [ 1 ] = F_57 ( V_116 , L_8 , V_102 ) ;
V_105 [ 2 ] = F_57 ( V_116 , L_9 , V_103 ) ;
V_105 [ 3 ] = F_57 ( V_116 , L_10 , V_104 ) ;
V_105 [ 4 ] = NULL ;
F_58 ( & V_1 -> V_9 -> V_117 -> V_118 . V_119 ,
V_120 , V_105 ) ;
F_59 ( L_11 ,
V_102 , V_103 , V_104 ) ;
F_60 ( V_105 [ 3 ] ) ;
F_60 ( V_105 [ 2 ] ) ;
F_60 ( V_105 [ 1 ] ) ;
}
static void F_61 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_46 ;
if ( ! F_62 ( V_9 ) )
return;
F_10 ( & V_1 -> V_12 , V_46 ) ;
V_1 -> V_113 |= V_114 ;
F_2 ( V_115 , V_1 -> V_113 ) ;
F_13 ( & V_1 -> V_12 , V_46 ) ;
F_63 ( V_1 -> V_121 , & V_1 -> V_99 . V_100 ) ;
}
static void F_64 ( struct V_8 * V_9 ,
struct V_47 * V_1 ,
T_2 V_122 )
{
if ( V_122 & ( V_123 |
V_124 ) )
F_44 ( V_9 , & V_1 -> V_81 [ V_125 ] ) ;
if ( V_122 & V_126 )
F_44 ( V_9 , & V_1 -> V_81 [ V_127 ] ) ;
if ( V_122 & V_128 )
F_44 ( V_9 , & V_1 -> V_81 [ V_129 ] ) ;
if ( V_122 & ( V_130 |
V_131 |
V_132 ) ) {
F_31 ( L_12 , V_122 ) ;
F_65 ( V_9 , false ) ;
}
if ( V_122 & V_114 )
F_61 ( V_9 ) ;
}
static void F_66 ( struct V_47 * V_1 ,
T_2 V_92 )
{
unsigned long V_46 ;
F_10 ( & V_1 -> V_91 . V_94 , V_46 ) ;
V_1 -> V_91 . V_92 |= V_92 ;
F_2 ( V_95 , V_1 -> V_91 . V_92 ) ;
F_3 ( V_95 ) ;
F_13 ( & V_1 -> V_91 . V_94 , V_46 ) ;
F_63 ( V_1 -> V_121 , & V_1 -> V_91 . V_55 ) ;
}
static void F_67 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_46 ( & V_1 -> V_133 ) ;
}
static void F_68 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_46 ( & V_1 -> V_133 ) ;
}
static T_5 F_69 ( int V_134 , void * V_135 )
{
struct V_8 * V_9 = (struct V_8 * ) V_135 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_136 , V_122 , V_92 ;
T_5 V_37 = V_137 ;
unsigned long V_11 ;
int V_5 ;
T_2 V_138 [ V_139 ] ;
F_70 ( & V_1 -> V_140 ) ;
while ( true ) {
V_136 = F_16 ( V_141 ) ;
V_122 = F_16 ( V_142 ) ;
V_92 = F_16 ( V_143 ) ;
if ( V_122 == 0 && V_92 == 0 && V_136 == 0 )
goto V_144;
V_37 = V_145 ;
F_64 ( V_9 , V_1 , V_122 ) ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_71 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_138 [ V_5 ] = F_16 ( V_7 ) ;
if ( V_138 [ V_5 ] & 0x8000ffff ) {
if ( V_138 [ V_5 ] & V_146 )
F_19 ( L_13 ,
F_20 ( V_5 ) ) ;
F_2 ( V_7 , V_138 [ V_5 ] ) ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
F_71 (pipe) {
if ( V_138 [ V_5 ] & V_147 )
F_72 ( V_9 , V_5 ) ;
if ( V_138 [ V_5 ] & V_148 ) {
F_73 ( V_9 , V_5 ) ;
F_74 ( V_9 , V_5 ) ;
}
}
if ( V_136 & V_149 ) {
T_2 V_150 = F_16 ( V_151 ) ;
F_19 ( L_14 ,
V_150 ) ;
if ( V_150 & V_1 -> V_152 )
F_63 ( V_1 -> V_121 ,
& V_1 -> V_56 ) ;
F_2 ( V_151 , V_150 ) ;
F_16 ( V_151 ) ;
}
if ( V_138 [ 0 ] & V_153 )
F_67 ( V_9 ) ;
if ( V_92 & V_96 )
F_66 ( V_1 , V_92 ) ;
F_2 ( V_142 , V_122 ) ;
F_2 ( V_143 , V_92 ) ;
F_2 ( V_141 , V_136 ) ;
}
V_144:
return V_37 ;
}
static void F_75 ( struct V_8 * V_9 , T_2 V_154 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_154 & V_155 )
F_63 ( V_1 -> V_121 , & V_1 -> V_56 ) ;
if ( V_154 & V_156 )
F_19 ( L_15 ,
( V_154 & V_156 ) >>
V_157 ) ;
if ( V_154 & V_158 )
F_68 ( V_9 ) ;
if ( V_154 & V_159 )
F_67 ( V_9 ) ;
if ( V_154 & V_160 )
F_19 ( L_16 ) ;
if ( V_154 & V_161 )
F_19 ( L_17 ) ;
if ( V_154 & V_162 )
F_31 ( L_18 ) ;
if ( V_154 & V_163 )
F_71 (pipe)
F_19 ( L_19 ,
F_20 ( V_5 ) ,
F_16 ( F_76 ( V_5 ) ) ) ;
if ( V_154 & ( V_164 | V_165 ) )
F_19 ( L_20 ) ;
if ( V_154 & ( V_166 | V_167 ) )
F_19 ( L_21 ) ;
if ( V_154 & V_168 )
F_19 ( L_22 ) ;
if ( V_154 & V_169 )
F_19 ( L_23 ) ;
}
static void F_77 ( struct V_8 * V_9 , T_2 V_154 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_154 & V_170 )
F_63 ( V_1 -> V_121 , & V_1 -> V_56 ) ;
if ( V_154 & V_171 )
F_19 ( L_15 ,
( V_154 & V_171 ) >>
V_172 ) ;
if ( V_154 & V_173 )
F_68 ( V_9 ) ;
if ( V_154 & V_174 )
F_67 ( V_9 ) ;
if ( V_154 & V_175 )
F_19 ( L_24 ) ;
if ( V_154 & V_176 )
F_19 ( L_25 ) ;
if ( V_154 & V_177 )
F_71 (pipe)
F_19 ( L_19 ,
F_20 ( V_5 ) ,
F_16 ( F_76 ( V_5 ) ) ) ;
}
static T_5 F_78 ( int V_134 , void * V_135 )
{
struct V_8 * V_9 = (struct V_8 * ) V_135 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_178 , V_122 , V_179 , V_92 , V_180 ;
T_5 V_37 = V_137 ;
int V_181 ;
F_70 ( & V_1 -> V_140 ) ;
V_179 = F_16 ( V_182 ) ;
F_2 ( V_182 , V_179 & ~ V_183 ) ;
V_180 = F_16 ( V_184 ) ;
F_2 ( V_184 , 0 ) ;
F_3 ( V_184 ) ;
V_122 = F_16 ( V_142 ) ;
if ( V_122 ) {
F_64 ( V_9 , V_1 , V_122 ) ;
F_2 ( V_142 , V_122 ) ;
V_37 = V_145 ;
}
V_178 = F_16 ( V_185 ) ;
if ( V_178 ) {
if ( V_178 & V_186 )
F_68 ( V_9 ) ;
if ( V_178 & V_187 )
F_79 ( V_9 ) ;
for ( V_181 = 0 ; V_181 < 3 ; V_181 ++ ) {
if ( V_178 & ( V_188 << ( 5 * V_181 ) ) )
F_72 ( V_9 , V_181 ) ;
if ( V_178 & ( V_189 << ( 5 * V_181 ) ) ) {
F_73 ( V_9 , V_181 ) ;
F_80 ( V_9 , V_181 ) ;
}
}
if ( V_178 & V_190 ) {
T_2 V_154 = F_16 ( V_191 ) ;
F_77 ( V_9 , V_154 ) ;
F_2 ( V_191 , V_154 ) ;
}
F_2 ( V_185 , V_178 ) ;
V_37 = V_145 ;
}
V_92 = F_16 ( V_143 ) ;
if ( V_92 ) {
if ( V_92 & V_96 )
F_66 ( V_1 , V_92 ) ;
F_2 ( V_143 , V_92 ) ;
V_37 = V_145 ;
}
F_2 ( V_182 , V_179 ) ;
F_3 ( V_182 ) ;
F_2 ( V_184 , V_180 ) ;
F_3 ( V_184 ) ;
return V_37 ;
}
static void F_81 ( struct V_8 * V_9 ,
struct V_47 * V_1 ,
T_2 V_122 )
{
if ( V_122 & ( V_192 | V_193 ) )
F_44 ( V_9 , & V_1 -> V_81 [ V_125 ] ) ;
if ( V_122 & V_194 )
F_44 ( V_9 , & V_1 -> V_81 [ V_127 ] ) ;
}
static T_5 F_82 ( int V_134 , void * V_135 )
{
struct V_8 * V_9 = (struct V_8 * ) V_135 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_37 = V_137 ;
T_2 V_178 , V_122 , V_179 , V_92 , V_180 ;
F_70 ( & V_1 -> V_140 ) ;
V_179 = F_16 ( V_182 ) ;
F_2 ( V_182 , V_179 & ~ V_183 ) ;
F_3 ( V_182 ) ;
V_180 = F_16 ( V_184 ) ;
F_2 ( V_184 , 0 ) ;
F_3 ( V_184 ) ;
V_178 = F_16 ( V_185 ) ;
V_122 = F_16 ( V_142 ) ;
V_92 = F_16 ( V_143 ) ;
if ( V_178 == 0 && V_122 == 0 && ( ! F_83 ( V_9 ) || V_92 == 0 ) )
goto V_195;
V_37 = V_145 ;
if ( F_84 ( V_9 ) )
F_81 ( V_9 , V_1 , V_122 ) ;
else
F_64 ( V_9 , V_1 , V_122 ) ;
if ( V_178 & V_196 )
F_68 ( V_9 ) ;
if ( V_178 & V_13 )
F_79 ( V_9 ) ;
if ( V_178 & V_197 )
F_72 ( V_9 , 0 ) ;
if ( V_178 & V_198 )
F_72 ( V_9 , 1 ) ;
if ( V_178 & V_199 ) {
F_73 ( V_9 , 0 ) ;
F_80 ( V_9 , 0 ) ;
}
if ( V_178 & V_200 ) {
F_73 ( V_9 , 1 ) ;
F_80 ( V_9 , 1 ) ;
}
if ( V_178 & V_201 ) {
T_2 V_154 = F_16 ( V_191 ) ;
if ( F_85 ( V_9 ) )
F_77 ( V_9 , V_154 ) ;
else
F_75 ( V_9 , V_154 ) ;
F_2 ( V_191 , V_154 ) ;
}
if ( F_84 ( V_9 ) && V_178 & V_202 )
F_41 ( V_9 ) ;
if ( F_83 ( V_9 ) && V_92 & V_96 )
F_66 ( V_1 , V_92 ) ;
F_2 ( V_142 , V_122 ) ;
F_2 ( V_185 , V_178 ) ;
F_2 ( V_143 , V_92 ) ;
V_195:
F_2 ( V_182 , V_179 ) ;
F_3 ( V_182 ) ;
F_2 ( V_184 , V_180 ) ;
F_3 ( V_184 ) ;
return V_37 ;
}
static void F_86 ( struct V_54 * V_55 )
{
struct V_203 * error = F_36 ( V_55 , struct V_203 ,
V_55 ) ;
T_1 * V_1 = F_36 ( error , T_1 ,
V_86 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
struct V_80 * V_81 ;
char * V_204 [] = { L_26 , NULL } ;
char * V_205 [] = { L_27 , NULL } ;
char * V_206 [] = { L_28 , NULL } ;
int V_181 , V_37 ;
F_58 ( & V_9 -> V_117 -> V_118 . V_119 , V_120 , V_204 ) ;
if ( F_87 ( error ) && ! F_88 ( error ) ) {
F_19 ( L_29 ) ;
F_58 ( & V_9 -> V_117 -> V_118 . V_119 , V_120 ,
V_205 ) ;
V_37 = F_89 ( V_9 ) ;
if ( V_37 == 0 ) {
F_90 () ;
F_70 ( & V_1 -> V_86 . V_207 ) ;
F_58 ( & V_9 -> V_117 -> V_118 . V_119 ,
V_120 , V_206 ) ;
} else {
F_91 ( & error -> V_207 , V_208 ) ;
}
F_92 (ring, dev_priv, i)
F_46 ( & V_81 -> V_84 ) ;
F_46 ( & V_1 -> V_86 . V_209 ) ;
}
}
static void F_93 ( struct V_8 * V_9 ,
T_4 * V_210 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
memset ( V_210 , 0 , sizeof( * V_210 ) * V_211 ) ;
switch( F_12 ( V_9 ) -> V_15 ) {
case 2 :
case 3 :
V_210 [ 0 ] = F_16 ( V_212 ) ;
break;
case 4 :
case 5 :
case 6 :
V_210 [ 0 ] = F_16 ( V_213 ) ;
V_210 [ 1 ] = F_16 ( V_214 ) ;
break;
default:
F_94 ( 1 , L_30 ) ;
case 7 :
V_210 [ 0 ] = F_16 ( V_215 ) ;
V_210 [ 1 ] = F_16 ( V_216 ) ;
V_210 [ 2 ] = F_16 ( V_217 ) ;
V_210 [ 3 ] = F_16 ( V_218 ) ;
break;
}
}
static struct V_219 *
F_95 ( struct V_47 * V_1 ,
struct V_220 * V_221 )
{
struct V_219 * V_222 ;
int V_181 , V_223 ;
T_2 V_224 ;
if ( V_221 == NULL || V_221 -> V_225 == NULL )
return NULL ;
V_223 = V_221 -> V_226 . V_227 / V_228 ;
V_222 = F_96 ( sizeof( * V_222 ) + V_223 * sizeof( T_2 * ) , V_229 ) ;
if ( V_222 == NULL )
return NULL ;
V_224 = V_221 -> V_230 ;
for ( V_181 = 0 ; V_181 < V_223 ; V_181 ++ ) {
unsigned long V_46 ;
void * V_231 ;
V_231 = F_96 ( V_228 , V_229 ) ;
if ( V_231 == NULL )
goto V_232;
F_97 ( V_46 ) ;
if ( V_224 < V_1 -> V_233 . V_234 &&
V_221 -> V_235 ) {
void T_6 * V_236 ;
V_236 = F_98 ( V_1 -> V_233 . V_237 ,
V_224 ) ;
F_99 ( V_231 , V_236 , V_228 ) ;
F_100 ( V_236 ) ;
} else if ( V_221 -> V_238 ) {
unsigned long V_239 ;
V_239 = V_1 -> V_240 . V_241 ;
V_239 += V_221 -> V_238 -> V_242 ;
V_239 += V_181 << V_243 ;
F_99 ( V_231 , ( void T_6 * ) V_239 , V_228 ) ;
} else {
struct V_244 * V_244 ;
void * V_236 ;
V_244 = F_101 ( V_221 , V_181 ) ;
F_102 ( & V_244 , 1 ) ;
V_236 = F_103 ( V_244 ) ;
memcpy ( V_231 , V_236 , V_228 ) ;
F_104 ( V_236 ) ;
F_102 ( & V_244 , 1 ) ;
}
F_105 ( V_46 ) ;
V_222 -> V_225 [ V_181 ] = V_231 ;
V_224 += V_228 ;
}
V_222 -> V_245 = V_223 ;
V_222 -> V_230 = V_221 -> V_230 ;
return V_222 ;
V_232:
while ( V_181 -- )
F_60 ( V_222 -> V_225 [ V_181 ] ) ;
F_60 ( V_222 ) ;
return NULL ;
}
static void
F_106 ( struct V_219 * V_82 )
{
int V_244 ;
if ( V_82 == NULL )
return;
for ( V_244 = 0 ; V_244 < V_82 -> V_245 ; V_244 ++ )
F_60 ( V_82 -> V_225 [ V_244 ] ) ;
F_60 ( V_82 ) ;
}
void
F_107 ( struct V_246 * V_247 )
{
struct V_248 * error = F_36 ( V_247 ,
F_108 ( * error ) , V_249 ) ;
int V_181 ;
for ( V_181 = 0 ; V_181 < F_109 ( error -> V_81 ) ; V_181 ++ ) {
F_106 ( error -> V_81 [ V_181 ] . V_250 ) ;
F_106 ( error -> V_81 [ V_181 ] . V_251 ) ;
F_60 ( error -> V_81 [ V_181 ] . V_252 ) ;
}
F_60 ( error -> V_253 ) ;
F_60 ( error -> V_254 ) ;
F_60 ( error ) ;
}
static void F_110 ( struct V_255 * V_256 ,
struct V_220 * V_82 )
{
V_256 -> V_227 = V_82 -> V_226 . V_227 ;
V_256 -> V_257 = V_82 -> V_226 . V_257 ;
V_256 -> V_258 = V_82 -> V_259 ;
V_256 -> V_260 = V_82 -> V_261 ;
V_256 -> V_230 = V_82 -> V_230 ;
V_256 -> V_262 = V_82 -> V_226 . V_262 ;
V_256 -> V_263 = V_82 -> V_226 . V_263 ;
V_256 -> V_264 = V_82 -> V_264 ;
V_256 -> V_265 = 0 ;
if ( V_82 -> V_266 > 0 )
V_256 -> V_265 = 1 ;
if ( V_82 -> V_267 > 0 )
V_256 -> V_265 = - 1 ;
V_256 -> V_268 = V_82 -> V_269 ;
V_256 -> V_270 = V_82 -> V_270 ;
V_256 -> V_271 = V_82 -> V_272 != V_273 ;
V_256 -> V_81 = V_82 -> V_81 ? V_82 -> V_81 -> V_274 : - 1 ;
V_256 -> V_275 = V_82 -> V_275 ;
}
static T_2 F_111 ( struct V_255 * V_256 ,
int V_223 , struct V_276 * V_277 )
{
struct V_220 * V_82 ;
int V_181 = 0 ;
F_38 (obj, head, mm_list) {
F_110 ( V_256 ++ , V_82 ) ;
if ( ++ V_181 == V_223 )
break;
}
return V_181 ;
}
static T_2 F_112 ( struct V_255 * V_256 ,
int V_223 , struct V_276 * V_277 )
{
struct V_220 * V_82 ;
int V_181 = 0 ;
F_38 (obj, head, gtt_list) {
if ( V_82 -> V_266 == 0 )
continue;
F_110 ( V_256 ++ , V_82 ) ;
if ( ++ V_181 == V_223 )
break;
}
return V_181 ;
}
static void F_113 ( struct V_8 * V_9 ,
struct V_248 * error )
{
struct V_47 * V_1 = V_9 -> V_10 ;
int V_181 ;
switch ( F_12 ( V_9 ) -> V_15 ) {
case 7 :
case 6 :
for ( V_181 = 0 ; V_181 < 16 ; V_181 ++ )
error -> V_278 [ V_181 ] = F_114 ( V_279 + ( V_181 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_181 = 0 ; V_181 < 16 ; V_181 ++ )
error -> V_278 [ V_181 ] = F_114 ( V_280 + ( V_181 * 8 ) ) ;
break;
case 3 :
if ( F_115 ( V_9 ) || F_116 ( V_9 ) || F_117 ( V_9 ) )
for ( V_181 = 0 ; V_181 < 8 ; V_181 ++ )
error -> V_278 [ V_181 + 8 ] = F_16 ( V_281 + ( V_181 * 4 ) ) ;
case 2 :
for ( V_181 = 0 ; V_181 < 8 ; V_181 ++ )
error -> V_278 [ V_181 ] = F_16 ( V_282 + ( V_181 * 4 ) ) ;
break;
default:
F_118 () ;
}
}
static struct V_219 *
F_119 ( struct V_47 * V_1 ,
struct V_80 * V_81 )
{
struct V_220 * V_82 ;
T_2 V_283 ;
if ( ! V_81 -> V_83 )
return NULL ;
if ( F_120 ( V_1 -> V_9 ) ) {
T_2 V_284 = F_16 ( V_285 ) ;
if ( F_121 ( V_81 -> V_274 != V_125 ) )
return NULL ;
V_82 = V_81 -> V_286 ;
if ( V_284 >= V_82 -> V_230 &&
V_284 < V_82 -> V_230 + V_82 -> V_226 . V_227 )
return F_95 ( V_1 , V_82 ) ;
}
V_283 = V_81 -> V_83 ( V_81 , false ) ;
F_38 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_82 -> V_81 != V_81 )
continue;
if ( F_122 ( V_283 , V_82 -> V_259 ) )
continue;
if ( ( V_82 -> V_226 . V_262 & V_287 ) == 0 )
continue;
return F_95 ( V_1 , V_82 ) ;
}
return NULL ;
}
static void F_123 ( struct V_8 * V_9 ,
struct V_248 * error ,
struct V_80 * V_81 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> V_288 [ V_81 -> V_274 ] = F_16 ( V_81 -> V_289 + 0x50 ) ;
error -> V_290 [ V_81 -> V_274 ] = F_16 ( F_124 ( V_81 ) ) ;
error -> V_291 [ V_81 -> V_274 ] [ 0 ]
= F_16 ( F_125 ( V_81 -> V_289 ) ) ;
error -> V_291 [ V_81 -> V_274 ] [ 1 ]
= F_16 ( F_126 ( V_81 -> V_289 ) ) ;
error -> V_292 [ V_81 -> V_274 ] [ 0 ] = V_81 -> V_293 [ 0 ] ;
error -> V_292 [ V_81 -> V_274 ] [ 1 ] = V_81 -> V_293 [ 1 ] ;
}
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
error -> V_294 [ V_81 -> V_274 ] = F_16 ( F_127 ( V_81 -> V_289 ) ) ;
error -> V_295 [ V_81 -> V_274 ] = F_16 ( F_128 ( V_81 -> V_289 ) ) ;
error -> V_296 [ V_81 -> V_274 ] = F_16 ( F_129 ( V_81 -> V_289 ) ) ;
error -> V_210 [ V_81 -> V_274 ] = F_16 ( F_130 ( V_81 -> V_289 ) ) ;
error -> V_297 [ V_81 -> V_274 ] = F_16 ( F_131 ( V_81 -> V_289 ) ) ;
if ( V_81 -> V_274 == V_125 )
error -> V_298 = F_114 ( V_299 ) ;
} else {
error -> V_294 [ V_81 -> V_274 ] = F_16 ( V_300 ) ;
error -> V_295 [ V_81 -> V_274 ] = F_16 ( V_301 ) ;
error -> V_296 [ V_81 -> V_274 ] = F_16 ( V_302 ) ;
error -> V_210 [ V_81 -> V_274 ] = F_16 ( V_212 ) ;
}
error -> V_303 [ V_81 -> V_274 ] = F_132 ( & V_81 -> V_84 ) ;
error -> V_304 [ V_81 -> V_274 ] = F_16 ( F_133 ( V_81 -> V_289 ) ) ;
error -> V_283 [ V_81 -> V_274 ] = V_81 -> V_83 ( V_81 , false ) ;
error -> V_284 [ V_81 -> V_274 ] = F_134 ( V_81 ) ;
error -> V_277 [ V_81 -> V_274 ] = F_135 ( V_81 ) ;
error -> V_305 [ V_81 -> V_274 ] = F_136 ( V_81 ) ;
error -> V_306 [ V_81 -> V_274 ] = F_137 ( V_81 ) ;
error -> V_307 [ V_81 -> V_274 ] = V_81 -> V_277 ;
error -> V_308 [ V_81 -> V_274 ] = V_81 -> V_305 ;
}
static void F_138 ( struct V_8 * V_9 ,
struct V_248 * error )
{
struct V_47 * V_1 = V_9 -> V_10 ;
struct V_80 * V_81 ;
struct V_309 * V_310 ;
int V_181 , V_223 ;
F_92 (ring, dev_priv, i) {
F_123 ( V_9 , error , V_81 ) ;
error -> V_81 [ V_181 ] . V_250 =
F_119 ( V_1 , V_81 ) ;
error -> V_81 [ V_181 ] . V_251 =
F_95 ( V_1 , V_81 -> V_82 ) ;
V_223 = 0 ;
F_38 (request, &ring->request_list, list)
V_223 ++ ;
error -> V_81 [ V_181 ] . V_311 = V_223 ;
error -> V_81 [ V_181 ] . V_252 =
F_96 ( V_223 * sizeof( struct V_312 ) ,
V_229 ) ;
if ( error -> V_81 [ V_181 ] . V_252 == NULL ) {
error -> V_81 [ V_181 ] . V_311 = 0 ;
continue;
}
V_223 = 0 ;
F_38 (request, &ring->request_list, list) {
struct V_312 * V_313 ;
V_313 = & error -> V_81 [ V_181 ] . V_252 [ V_223 ++ ] ;
V_313 -> V_283 = V_310 -> V_283 ;
V_313 -> V_89 = V_310 -> V_314 ;
V_313 -> V_305 = V_310 -> V_305 ;
}
}
}
static void F_139 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
struct V_220 * V_82 ;
struct V_248 * error ;
unsigned long V_46 ;
int V_181 , V_5 ;
F_10 ( & V_1 -> V_86 . V_94 , V_46 ) ;
error = V_1 -> V_86 . V_315 ;
F_13 ( & V_1 -> V_86 . V_94 , V_46 ) ;
if ( error )
return;
error = F_140 ( sizeof( * error ) , V_229 ) ;
if ( ! error ) {
F_19 ( L_31 ) ;
return;
}
F_141 ( L_32
L_33 ,
V_9 -> V_117 -> V_316 ) ;
F_142 ( & error -> V_249 ) ;
error -> V_317 = F_16 ( V_318 ) ;
error -> V_319 = F_16 ( V_320 ) ;
error -> V_321 = F_16 ( V_322 ) ;
if ( F_11 ( V_9 ) )
error -> V_323 = F_16 ( V_182 ) | F_16 ( V_324 ) ;
else if ( F_9 ( V_9 ) )
error -> V_323 = F_16 ( V_324 ) | F_16 ( V_325 ) ;
else if ( F_143 ( V_9 ) )
error -> V_323 = F_144 ( V_326 ) ;
else
error -> V_323 = F_16 ( V_326 ) ;
if ( F_12 ( V_9 ) -> V_15 >= 6 )
error -> V_327 = F_16 ( V_328 ) ;
if ( F_9 ( V_9 ) )
error -> V_329 = F_16 ( V_330 ) ;
else if ( F_12 ( V_9 ) -> V_15 >= 7 )
error -> V_329 = F_16 ( V_331 ) ;
else if ( F_12 ( V_9 ) -> V_15 == 6 )
error -> V_329 = F_16 ( V_332 ) ;
F_71 ( V_5 )
error -> V_6 [ V_5 ] = F_16 ( F_6 ( V_5 ) ) ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> error = F_16 ( V_333 ) ;
error -> V_334 = F_16 ( V_335 ) ;
}
if ( F_12 ( V_9 ) -> V_15 == 7 )
error -> V_336 = F_16 ( V_337 ) ;
F_93 ( V_9 , error -> V_338 ) ;
F_113 ( V_9 , error ) ;
F_138 ( V_9 , error ) ;
error -> V_253 = NULL ;
error -> V_339 = NULL ;
V_181 = 0 ;
F_38 (obj, &dev_priv->mm.active_list, mm_list)
V_181 ++ ;
error -> V_340 = V_181 ;
F_38 (obj, &dev_priv->mm.bound_list, gtt_list)
if ( V_82 -> V_266 )
V_181 ++ ;
error -> V_341 = V_181 - error -> V_340 ;
error -> V_253 = NULL ;
error -> V_339 = NULL ;
if ( V_181 ) {
error -> V_253 = F_96 ( sizeof( * error -> V_253 ) * V_181 ,
V_229 ) ;
if ( error -> V_253 )
error -> V_339 =
error -> V_253 + error -> V_340 ;
}
if ( error -> V_253 )
error -> V_340 =
F_111 ( error -> V_253 ,
error -> V_340 ,
& V_1 -> V_240 . V_342 ) ;
if ( error -> V_339 )
error -> V_341 =
F_112 ( error -> V_339 ,
error -> V_341 ,
& V_1 -> V_240 . V_343 ) ;
F_145 ( & error -> time ) ;
error -> V_254 = F_146 ( V_9 ) ;
error -> V_344 = F_147 ( V_9 ) ;
F_10 ( & V_1 -> V_86 . V_94 , V_46 ) ;
if ( V_1 -> V_86 . V_315 == NULL ) {
V_1 -> V_86 . V_315 = error ;
error = NULL ;
}
F_13 ( & V_1 -> V_86 . V_94 , V_46 ) ;
if ( error )
F_107 ( & error -> V_249 ) ;
}
void F_148 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
struct V_248 * error ;
unsigned long V_46 ;
F_10 ( & V_1 -> V_86 . V_94 , V_46 ) ;
error = V_1 -> V_86 . V_315 ;
V_1 -> V_86 . V_315 = NULL ;
F_13 ( & V_1 -> V_86 . V_94 , V_46 ) ;
if ( error )
F_149 ( & error -> V_249 , F_107 ) ;
}
static void F_150 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
T_4 V_210 [ V_211 ] ;
T_2 V_317 = F_16 ( V_318 ) ;
int V_5 , V_181 ;
if ( ! V_317 )
return;
F_151 ( L_34 , V_317 ) ;
F_93 ( V_9 , V_210 ) ;
if ( F_152 ( V_9 ) ) {
if ( V_317 & ( V_345 | V_346 ) ) {
T_2 V_295 = F_16 ( V_347 ) ;
F_151 ( L_35 , F_16 ( V_347 ) ) ;
F_151 ( L_36 , F_16 ( V_348 ) ) ;
for ( V_181 = 0 ; V_181 < F_109 ( V_210 ) ; V_181 ++ )
F_151 ( L_37 , V_181 , V_210 [ V_181 ] ) ;
F_151 ( L_38 , F_16 ( V_349 ) ) ;
F_151 ( L_39 , F_16 ( V_350 ) ) ;
F_2 ( V_347 , V_295 ) ;
F_3 ( V_347 ) ;
}
if ( V_317 & V_351 ) {
T_2 V_352 = F_16 ( V_320 ) ;
F_151 ( L_40 ) ;
F_151 ( L_41 , V_352 ) ;
F_2 ( V_320 , V_352 ) ;
F_3 ( V_320 ) ;
}
}
if ( ! F_143 ( V_9 ) ) {
if ( V_317 & V_353 ) {
T_2 V_352 = F_16 ( V_320 ) ;
F_151 ( L_40 ) ;
F_151 ( L_41 , V_352 ) ;
F_2 ( V_320 , V_352 ) ;
F_3 ( V_320 ) ;
}
}
if ( V_317 & V_354 ) {
F_151 ( L_42 ) ;
F_71 (pipe)
F_151 ( L_43 ,
F_20 ( V_5 ) , F_16 ( F_6 ( V_5 ) ) ) ;
}
if ( V_317 & V_355 ) {
F_151 ( L_44 ) ;
F_151 ( L_45 , F_16 ( V_356 ) ) ;
for ( V_181 = 0 ; V_181 < F_109 ( V_210 ) ; V_181 ++ )
F_151 ( L_37 , V_181 , V_210 [ V_181 ] ) ;
if ( F_12 ( V_9 ) -> V_15 < 4 ) {
T_2 V_295 = F_16 ( V_301 ) ;
F_151 ( L_35 , F_16 ( V_301 ) ) ;
F_151 ( L_36 , F_16 ( V_302 ) ) ;
F_151 ( L_39 , F_16 ( V_285 ) ) ;
F_2 ( V_301 , V_295 ) ;
F_3 ( V_301 ) ;
} else {
T_2 V_295 = F_16 ( V_347 ) ;
F_151 ( L_35 , F_16 ( V_347 ) ) ;
F_151 ( L_36 , F_16 ( V_348 ) ) ;
F_151 ( L_38 , F_16 ( V_349 ) ) ;
F_151 ( L_39 , F_16 ( V_350 ) ) ;
F_2 ( V_347 , V_295 ) ;
F_3 ( V_347 ) ;
}
}
F_2 ( V_318 , V_317 ) ;
F_3 ( V_318 ) ;
V_317 = F_16 ( V_318 ) ;
if ( V_317 ) {
F_31 ( L_46 , V_317 ) ;
F_2 ( V_357 , F_16 ( V_357 ) | V_317 ) ;
F_2 ( V_358 , V_359 ) ;
}
}
void F_65 ( struct V_8 * V_9 , bool V_360 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
struct V_80 * V_81 ;
int V_181 ;
F_139 ( V_9 ) ;
F_150 ( V_9 ) ;
if ( V_360 ) {
F_153 ( V_361 ,
& V_1 -> V_86 . V_207 ) ;
F_92 (ring, dev_priv, i)
F_46 ( & V_81 -> V_84 ) ;
}
F_63 ( V_1 -> V_121 , & V_1 -> V_86 . V_55 ) ;
}
static void F_154 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = V_9 -> V_10 ;
struct V_48 * V_49 = V_1 -> V_362 [ V_5 ] ;
struct V_363 * V_363 = F_155 ( V_49 ) ;
struct V_220 * V_82 ;
struct V_364 * V_55 ;
unsigned long V_46 ;
bool V_365 ;
if ( V_363 == NULL )
return;
F_10 ( & V_9 -> V_366 , V_46 ) ;
V_55 = V_363 -> V_367 ;
if ( V_55 == NULL ||
F_156 ( & V_55 -> V_368 ) >= V_369 ||
! V_55 -> V_370 ) {
F_13 ( & V_9 -> V_366 , V_46 ) ;
return;
}
V_82 = V_55 -> V_371 ;
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
int V_372 = F_157 ( V_363 -> V_373 ) ;
V_365 = F_158 ( F_16 ( V_372 ) ) ==
V_82 -> V_230 ;
} else {
int V_374 = F_159 ( V_363 -> V_373 ) ;
V_365 = F_16 ( V_374 ) == ( V_82 -> V_230 +
V_49 -> V_375 * V_49 -> V_376 -> V_377 [ 0 ] +
V_49 -> V_378 * V_49 -> V_376 -> V_379 / 8 ) ;
}
F_13 ( & V_9 -> V_366 , V_46 ) ;
if ( V_365 ) {
F_19 ( L_47 ) ;
F_73 ( V_9 , V_363 -> V_373 ) ;
}
}
static int F_160 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_51 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 )
F_5 ( V_1 , V_5 ,
V_380 ) ;
else
F_5 ( V_1 , V_5 ,
V_381 ) ;
if ( V_1 -> V_382 -> V_15 == 3 )
F_2 ( V_356 , F_161 ( V_383 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_162 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_51 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 , ( V_5 == 0 ) ?
V_197 : V_198 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_163 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_51 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 ,
V_188 << ( 5 * V_5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_164 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_384 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_51 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
V_384 = F_16 ( V_385 ) ;
if ( V_5 == 0 )
V_384 &= ~ V_386 ;
else
V_384 &= ~ V_387 ;
F_2 ( V_385 , V_384 ) ;
F_5 ( V_1 , V_5 ,
V_380 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static void F_165 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_1 -> V_382 -> V_15 == 3 )
F_2 ( V_356 , F_166 ( V_383 ) ) ;
F_7 ( V_1 , V_5 ,
V_381 |
V_380 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_167 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 , ( V_5 == 0 ) ?
V_197 : V_198 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_168 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 ,
V_188 << ( V_5 * 5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_169 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_384 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_7 ( V_1 , V_5 ,
V_380 ) ;
V_384 = F_16 ( V_385 ) ;
if ( V_5 == 0 )
V_384 |= V_386 ;
else
V_384 |= V_387 ;
F_2 ( V_385 , V_384 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static T_2
F_170 ( struct V_80 * V_81 )
{
return F_171 ( V_81 -> V_388 . V_389 ,
struct V_309 , V_390 ) -> V_283 ;
}
static bool F_172 ( struct V_80 * V_81 , bool * V_256 )
{
if ( F_173 ( & V_81 -> V_388 ) ||
F_122 ( V_81 -> V_83 ( V_81 , false ) ,
F_170 ( V_81 ) ) ) {
if ( F_132 ( & V_81 -> V_84 ) ) {
F_31 ( L_48 ,
V_81 -> V_257 ) ;
F_46 ( & V_81 -> V_84 ) ;
* V_256 = true ;
}
return true ;
}
return false ;
}
static bool F_174 ( struct V_80 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_9 ;
struct V_47 * V_1 = V_9 -> V_10 ;
T_2 V_391 = F_137 ( V_81 ) ;
if ( V_391 & V_392 ) {
F_31 ( L_49 ,
V_81 -> V_257 ) ;
F_175 ( V_81 , V_391 ) ;
return true ;
}
return false ;
}
static bool F_176 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
if ( V_1 -> V_86 . V_87 ++ > 1 ) {
bool V_393 = true ;
F_31 ( L_50 ) ;
F_65 ( V_9 , true ) ;
if ( ! F_143 ( V_9 ) ) {
struct V_80 * V_81 ;
int V_181 ;
F_92 (ring, dev_priv, i)
V_393 &= ! F_174 ( V_81 ) ;
}
return V_393 ;
}
return false ;
}
void F_177 ( unsigned long V_394 )
{
struct V_8 * V_9 = (struct V_8 * ) V_394 ;
T_1 * V_1 = V_9 -> V_10 ;
T_4 V_284 [ V_395 ] , V_210 [ V_211 ] ;
struct V_80 * V_81 ;
bool V_256 = false , V_396 ;
int V_181 ;
if ( ! V_85 )
return;
memset ( V_284 , 0 , sizeof( V_284 ) ) ;
V_396 = true ;
F_92 (ring, dev_priv, i) {
V_396 &= F_172 ( V_81 , & V_256 ) ;
V_284 [ V_181 ] = F_134 ( V_81 ) ;
}
if ( V_396 ) {
if ( V_256 ) {
if ( F_176 ( V_9 ) )
return;
goto V_397;
}
V_1 -> V_86 . V_87 = 0 ;
return;
}
F_93 ( V_9 , V_210 ) ;
if ( memcmp ( V_1 -> V_86 . V_398 , V_284 ,
sizeof( V_284 ) ) == 0 &&
memcmp ( V_1 -> V_86 . V_399 , V_210 ,
sizeof( V_210 ) ) == 0 ) {
if ( F_176 ( V_9 ) )
return;
} else {
V_1 -> V_86 . V_87 = 0 ;
memcpy ( V_1 -> V_86 . V_398 , V_284 ,
sizeof( V_284 ) ) ;
memcpy ( V_1 -> V_86 . V_399 , V_210 ,
sizeof( V_210 ) ) ;
}
V_397:
F_47 ( & V_1 -> V_86 . V_88 ,
F_48 ( V_89 + V_90 ) ) ;
}
static void F_178 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_91 ( & V_1 -> V_140 , 0 ) ;
F_2 ( V_400 , 0xeffe ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_182 , 0x0 ) ;
F_3 ( V_182 ) ;
F_2 ( V_115 , 0xffffffff ) ;
F_2 ( V_324 , 0x0 ) ;
F_3 ( V_324 ) ;
F_2 ( V_401 , 0xffffffff ) ;
F_2 ( V_184 , 0x0 ) ;
F_3 ( V_184 ) ;
}
static void F_179 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_91 ( & V_1 -> V_140 , 0 ) ;
F_2 ( V_385 , 0 ) ;
F_2 ( F_180 ( V_402 ) , 0 ) ;
F_2 ( F_180 ( V_403 ) , 0 ) ;
F_2 ( F_180 ( V_404 ) , 0 ) ;
F_2 ( V_142 , F_16 ( V_142 ) ) ;
F_2 ( V_142 , F_16 ( V_142 ) ) ;
F_2 ( V_115 , 0xffffffff ) ;
F_2 ( V_324 , 0x0 ) ;
F_3 ( V_324 ) ;
F_2 ( V_405 , 0xff ) ;
F_2 ( V_406 , 0 ) ;
F_2 ( V_151 , F_16 ( V_151 ) ) ;
F_71 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_141 , 0xffffffff ) ;
F_2 ( V_385 , 0xffffffff ) ;
F_2 ( V_325 , 0x0 ) ;
F_3 ( V_325 ) ;
}
static void F_181 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_407 ;
V_407 = F_16 ( V_408 ) ;
V_407 &= ~ ( V_409 | V_410 | V_411 ) ;
V_407 |= V_412 | V_413 ;
V_407 |= V_414 | V_415 ;
V_407 |= V_416 | V_417 ;
F_2 ( V_408 , V_407 ) ;
}
static void F_182 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_2 ;
if ( F_183 ( V_9 ) )
V_2 = V_155 |
V_159 |
V_158 ;
else
V_2 = V_170 |
V_174 |
V_173 ;
F_2 ( V_191 , F_16 ( V_191 ) ) ;
F_2 ( V_401 , ~ V_2 ) ;
F_2 ( V_184 , V_2 ) ;
F_3 ( V_184 ) ;
F_181 ( V_9 ) ;
}
static int F_184 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_418 = V_183 | V_13 | V_201 |
V_199 | V_200 |
V_196 ;
T_2 V_419 ;
V_1 -> V_3 = ~ V_418 ;
F_2 ( V_185 , F_16 ( V_185 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_182 , V_418 | V_197 | V_198 ) ;
F_3 ( V_182 ) ;
V_1 -> V_113 = ~ 0 ;
F_2 ( V_142 , F_16 ( V_142 ) ) ;
F_2 ( V_115 , V_1 -> V_113 ) ;
if ( F_83 ( V_9 ) )
V_419 =
V_192 |
V_126 |
V_128 ;
else
V_419 =
V_192 |
V_193 |
V_194 ;
F_2 ( V_324 , V_419 ) ;
F_3 ( V_324 ) ;
F_182 ( V_9 ) ;
if ( F_185 ( V_9 ) ) {
F_2 ( V_185 , V_202 ) ;
F_2 ( V_182 , F_16 ( V_182 ) | V_202 ) ;
F_1 ( V_1 , V_202 ) ;
}
return 0 ;
}
static int F_186 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_418 =
V_183 | V_187 | V_190 |
V_420 |
V_421 |
V_189 |
V_186 ;
T_2 V_419 ;
V_1 -> V_3 = ~ V_418 ;
F_2 ( V_185 , F_16 ( V_185 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_182 ,
V_418 |
V_422 |
V_423 |
V_188 ) ;
F_3 ( V_182 ) ;
V_1 -> V_113 = ~ V_114 ;
F_2 ( V_142 , F_16 ( V_142 ) ) ;
F_2 ( V_115 , V_1 -> V_113 ) ;
V_419 = V_192 | V_126 |
V_128 | V_114 ;
F_2 ( V_324 , V_419 ) ;
F_3 ( V_324 ) ;
F_182 ( V_9 ) ;
return 0 ;
}
static int F_187 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_424 ;
T_2 V_425 = V_426 ;
T_2 V_419 ;
T_7 V_427 ;
V_424 = V_149 ;
V_424 |= V_428 |
V_386 |
V_429 |
V_387 ;
V_1 -> V_3 = ( ~ V_424 ) |
V_386 |
V_387 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_188 ( V_1 -> V_9 -> V_430 , 0x94 , 0xfee00000 ) ;
F_189 ( V_9 -> V_430 , 0x98 , & V_427 ) ;
V_427 &= 0xff ;
V_427 |= ( 1 << 14 ) ;
F_190 ( V_1 -> V_9 -> V_430 , 0x98 , V_427 ) ;
F_2 ( V_406 , 0 ) ;
F_3 ( V_406 ) ;
F_2 ( V_385 , V_1 -> V_3 ) ;
F_2 ( V_325 , V_424 ) ;
F_2 ( V_141 , 0xffffffff ) ;
F_2 ( F_6 ( 0 ) , 0xffff ) ;
F_2 ( F_6 ( 1 ) , 0xffff ) ;
F_3 ( V_325 ) ;
F_5 ( V_1 , 0 , V_425 ) ;
F_5 ( V_1 , 0 , V_431 ) ;
F_5 ( V_1 , 1 , V_425 ) ;
F_2 ( V_141 , 0xffffffff ) ;
F_2 ( V_141 , 0xffffffff ) ;
F_2 ( V_142 , F_16 ( V_142 ) ) ;
F_2 ( V_115 , V_1 -> V_113 ) ;
V_419 = V_192 | V_126 |
V_128 ;
F_2 ( V_324 , V_419 ) ;
F_3 ( V_324 ) ;
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
F_2 ( V_432 , V_433 ) ;
return 0 ;
}
static void F_191 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_434 = F_16 ( V_406 ) ;
if ( V_1 -> V_152 & V_435 )
V_434 |= V_436 ;
if ( V_1 -> V_152 & V_437 )
V_434 |= V_438 ;
if ( V_1 -> V_152 & V_439 )
V_434 |= V_440 ;
if ( V_1 -> V_152 & V_441 )
V_434 |= V_442 ;
if ( V_1 -> V_152 & V_443 )
V_434 |= V_444 ;
if ( V_1 -> V_152 & V_445 ) {
V_434 |= V_446 ;
V_434 |= V_447 ;
}
F_2 ( V_406 , V_434 ) ;
}
static void F_192 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_71 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_400 , 0xffffffff ) ;
F_2 ( V_406 , 0 ) ;
F_2 ( V_151 , F_16 ( V_151 ) ) ;
F_71 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_141 , 0xffffffff ) ;
F_2 ( V_385 , 0xffffffff ) ;
F_2 ( V_325 , 0x0 ) ;
F_3 ( V_325 ) ;
}
static void F_193 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
if ( ! V_1 )
return;
F_2 ( V_400 , 0xffffffff ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_182 , 0x0 ) ;
F_2 ( V_185 , F_16 ( V_185 ) ) ;
F_2 ( V_115 , 0xffffffff ) ;
F_2 ( V_324 , 0x0 ) ;
F_2 ( V_142 , F_16 ( V_142 ) ) ;
F_2 ( V_401 , 0xffffffff ) ;
F_2 ( V_184 , 0x0 ) ;
F_2 ( V_191 , F_16 ( V_191 ) ) ;
}
static void F_194 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_91 ( & V_1 -> V_140 , 0 ) ;
F_71 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_42 ( V_448 , 0xffff ) ;
F_42 ( V_326 , 0x0 ) ;
F_195 ( V_326 ) ;
}
static int F_196 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_42 ( V_357 ,
~ ( V_353 | V_354 ) ) ;
V_1 -> V_3 =
~ ( V_428 |
V_429 |
V_449 |
V_450 |
V_359 ) ;
F_42 ( V_448 , V_1 -> V_3 ) ;
F_42 ( V_326 ,
V_428 |
V_429 |
V_359 |
V_451 ) ;
F_195 ( V_326 ) ;
return 0 ;
}
static T_5 F_197 ( int V_134 , void * V_135 )
{
struct V_8 * V_9 = (struct V_8 * ) V_135 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_7 V_136 , V_452 ;
T_2 V_138 [ 2 ] ;
unsigned long V_11 ;
int V_140 ;
int V_5 ;
T_7 V_453 =
V_449 |
V_450 ;
F_70 ( & V_1 -> V_140 ) ;
V_136 = F_144 ( V_358 ) ;
if ( V_136 == 0 )
return V_137 ;
while ( V_136 & ~ V_453 ) {
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_136 & V_359 )
F_65 ( V_9 , false ) ;
F_71 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_138 [ V_5 ] = F_16 ( V_7 ) ;
if ( V_138 [ V_5 ] & 0x8000ffff ) {
if ( V_138 [ V_5 ] & V_146 )
F_19 ( L_13 ,
F_20 ( V_5 ) ) ;
F_2 ( V_7 , V_138 [ V_5 ] ) ;
V_140 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
F_42 ( V_358 , V_136 & ~ V_453 ) ;
V_452 = F_144 ( V_358 ) ;
F_198 ( V_9 ) ;
if ( V_136 & V_451 )
F_44 ( V_9 , & V_1 -> V_81 [ V_125 ] ) ;
if ( V_138 [ 0 ] & V_147 &&
F_72 ( V_9 , 0 ) ) {
if ( V_136 & V_449 ) {
F_73 ( V_9 , 0 ) ;
F_74 ( V_9 , 0 ) ;
V_453 &= ~ V_449 ;
}
}
if ( V_138 [ 1 ] & V_147 &&
F_72 ( V_9 , 1 ) ) {
if ( V_136 & V_450 ) {
F_73 ( V_9 , 1 ) ;
F_74 ( V_9 , 1 ) ;
V_453 &= ~ V_450 ;
}
}
V_136 = V_452 ;
}
return V_145 ;
}
static void F_199 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_71 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_16 ( F_6 ( V_5 ) ) ) ;
}
F_42 ( V_448 , 0xffff ) ;
F_42 ( V_326 , 0x0 ) ;
F_42 ( V_358 , F_144 ( V_358 ) ) ;
}
static void F_200 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_91 ( & V_1 -> V_140 , 0 ) ;
if ( F_201 ( V_9 ) ) {
F_2 ( V_406 , 0 ) ;
F_2 ( V_151 , F_16 ( V_151 ) ) ;
}
F_42 ( V_400 , 0xeffe ) ;
F_71 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_448 , 0xffffffff ) ;
F_2 ( V_326 , 0x0 ) ;
F_3 ( V_326 ) ;
}
static int F_202 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_424 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_2 ( V_357 , ~ ( V_353 | V_354 ) ) ;
V_1 -> V_3 =
~ ( V_454 |
V_428 |
V_429 |
V_449 |
V_450 |
V_359 ) ;
V_424 =
V_454 |
V_428 |
V_429 |
V_359 |
V_451 ;
if ( F_201 ( V_9 ) ) {
F_2 ( V_406 , 0 ) ;
F_3 ( V_406 ) ;
V_424 |= V_149 ;
V_1 -> V_3 &= ~ V_149 ;
}
F_2 ( V_448 , V_1 -> V_3 ) ;
F_2 ( V_326 , V_424 ) ;
F_3 ( V_326 ) ;
F_203 ( V_9 ) ;
return 0 ;
}
static void F_204 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_434 ;
if ( F_201 ( V_9 ) ) {
V_434 = F_16 ( V_406 ) ;
if ( V_1 -> V_152 & V_435 )
V_434 |= V_436 ;
if ( V_1 -> V_152 & V_437 )
V_434 |= V_438 ;
if ( V_1 -> V_152 & V_439 )
V_434 |= V_440 ;
if ( V_1 -> V_152 & V_441 )
V_434 |= V_442 ;
if ( V_1 -> V_152 & V_443 )
V_434 |= V_444 ;
if ( V_1 -> V_152 & V_445 ) {
V_434 |= V_446 ;
V_434 |= V_447 ;
}
F_2 ( V_406 , V_434 ) ;
}
}
static T_5 F_205 ( int V_134 , void * V_135 )
{
struct V_8 * V_9 = (struct V_8 * ) V_135 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_136 , V_452 , V_138 [ V_139 ] ;
unsigned long V_11 ;
T_2 V_453 =
V_449 |
V_450 ;
T_2 V_455 [ 2 ] = {
V_449 ,
V_450
} ;
int V_5 , V_37 = V_137 ;
F_70 ( & V_1 -> V_140 ) ;
V_136 = F_16 ( V_358 ) ;
do {
bool V_140 = ( V_136 & ~ V_453 ) != 0 ;
bool V_456 = false ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_136 & V_359 )
F_65 ( V_9 , false ) ;
F_71 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_138 [ V_5 ] = F_16 ( V_7 ) ;
if ( V_138 [ V_5 ] & 0x8000ffff ) {
if ( V_138 [ V_5 ] & V_146 )
F_19 ( L_13 ,
F_20 ( V_5 ) ) ;
F_2 ( V_7 , V_138 [ V_5 ] ) ;
V_140 = true ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_140 )
break;
if ( ( F_201 ( V_9 ) ) &&
( V_136 & V_149 ) ) {
T_2 V_150 = F_16 ( V_151 ) ;
F_19 ( L_14 ,
V_150 ) ;
if ( V_150 & V_1 -> V_152 )
F_63 ( V_1 -> V_121 ,
& V_1 -> V_56 ) ;
F_2 ( V_151 , V_150 ) ;
F_3 ( V_151 ) ;
}
F_2 ( V_358 , V_136 & ~ V_453 ) ;
V_452 = F_16 ( V_358 ) ;
if ( V_136 & V_451 )
F_44 ( V_9 , & V_1 -> V_81 [ V_125 ] ) ;
F_71 (pipe) {
int V_373 = V_5 ;
if ( F_206 ( V_9 ) )
V_373 = ! V_373 ;
if ( V_138 [ V_5 ] & V_147 &&
F_72 ( V_9 , V_5 ) ) {
if ( V_136 & V_455 [ V_373 ] ) {
F_73 ( V_9 , V_373 ) ;
F_74 ( V_9 , V_5 ) ;
V_453 &= ~ V_455 [ V_373 ] ;
}
}
if ( V_138 [ V_5 ] & V_457 )
V_456 = true ;
}
if ( V_456 || ( V_136 & V_454 ) )
F_207 ( V_9 ) ;
V_37 = V_145 ;
V_136 = V_452 ;
} while ( V_136 & ~ V_453 );
F_198 ( V_9 ) ;
return V_37 ;
}
static void F_208 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( F_201 ( V_9 ) ) {
F_2 ( V_406 , 0 ) ;
F_2 ( V_151 , F_16 ( V_151 ) ) ;
}
F_42 ( V_400 , 0xffff ) ;
F_71 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_16 ( F_6 ( V_5 ) ) ) ;
}
F_2 ( V_448 , 0xffffffff ) ;
F_2 ( V_326 , 0x0 ) ;
F_2 ( V_358 , F_16 ( V_358 ) ) ;
}
static void F_209 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_91 ( & V_1 -> V_140 , 0 ) ;
F_2 ( V_406 , 0 ) ;
F_2 ( V_151 , F_16 ( V_151 ) ) ;
F_2 ( V_400 , 0xeffe ) ;
F_71 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_448 , 0xffffffff ) ;
F_2 ( V_326 , 0x0 ) ;
F_3 ( V_326 ) ;
}
static int F_210 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_424 ;
T_2 V_458 ;
V_1 -> V_3 = ~ ( V_454 |
V_149 |
V_428 |
V_429 |
V_449 |
V_450 |
V_359 ) ;
V_424 = ~ V_1 -> V_3 ;
V_424 |= V_451 ;
if ( F_152 ( V_9 ) )
V_424 |= V_459 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_5 ( V_1 , 0 , V_431 ) ;
if ( F_152 ( V_9 ) ) {
V_458 = ~ ( V_351 |
V_345 |
V_346 |
V_354 ) ;
} else {
V_458 = ~ ( V_353 |
V_354 ) ;
}
F_2 ( V_357 , V_458 ) ;
F_2 ( V_448 , V_1 -> V_3 ) ;
F_2 ( V_326 , V_424 ) ;
F_3 ( V_326 ) ;
F_2 ( V_406 , 0 ) ;
F_3 ( V_406 ) ;
F_203 ( V_9 ) ;
return 0 ;
}
static void F_211 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_434 ;
V_434 = 0 ;
if ( V_1 -> V_152 & V_435 )
V_434 |= V_436 ;
if ( V_1 -> V_152 & V_437 )
V_434 |= V_438 ;
if ( V_1 -> V_152 & V_439 )
V_434 |= V_440 ;
if ( F_152 ( V_9 ) ) {
if ( V_1 -> V_152 & V_460 )
V_434 |= V_442 ;
if ( V_1 -> V_152 & V_461 )
V_434 |= V_444 ;
} else {
if ( V_1 -> V_152 & V_462 )
V_434 |= V_442 ;
if ( V_1 -> V_152 & V_463 )
V_434 |= V_444 ;
}
if ( V_1 -> V_152 & V_445 ) {
V_434 |= V_446 ;
if ( F_152 ( V_9 ) )
V_434 |= V_464 ;
V_434 |= V_447 ;
}
F_2 ( V_406 , V_434 ) ;
}
static T_5 F_212 ( int V_134 , void * V_135 )
{
struct V_8 * V_9 = (struct V_8 * ) V_135 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_136 , V_452 ;
T_2 V_138 [ V_139 ] ;
unsigned long V_11 ;
int V_140 ;
int V_37 = V_137 , V_5 ;
F_70 ( & V_1 -> V_140 ) ;
V_136 = F_16 ( V_358 ) ;
for (; ; ) {
bool V_456 = false ;
V_140 = V_136 != 0 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_136 & V_359 )
F_65 ( V_9 , false ) ;
F_71 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_138 [ V_5 ] = F_16 ( V_7 ) ;
if ( V_138 [ V_5 ] & 0x8000ffff ) {
if ( V_138 [ V_5 ] & V_146 )
F_19 ( L_13 ,
F_20 ( V_5 ) ) ;
F_2 ( V_7 , V_138 [ V_5 ] ) ;
V_140 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_140 )
break;
V_37 = V_145 ;
if ( V_136 & V_149 ) {
T_2 V_150 = F_16 ( V_151 ) ;
F_19 ( L_14 ,
V_150 ) ;
if ( V_150 & V_1 -> V_152 )
F_63 ( V_1 -> V_121 ,
& V_1 -> V_56 ) ;
F_2 ( V_151 , V_150 ) ;
F_16 ( V_151 ) ;
}
F_2 ( V_358 , V_136 ) ;
V_452 = F_16 ( V_358 ) ;
if ( V_136 & V_451 )
F_44 ( V_9 , & V_1 -> V_81 [ V_125 ] ) ;
if ( V_136 & V_459 )
F_44 ( V_9 , & V_1 -> V_81 [ V_127 ] ) ;
if ( V_136 & V_449 )
F_73 ( V_9 , 0 ) ;
if ( V_136 & V_450 )
F_73 ( V_9 , 1 ) ;
F_71 (pipe) {
if ( V_138 [ V_5 ] & V_465 &&
F_72 ( V_9 , V_5 ) ) {
F_154 ( V_9 , V_5 ) ;
F_74 ( V_9 , V_5 ) ;
}
if ( V_138 [ V_5 ] & V_457 )
V_456 = true ;
}
if ( V_456 || ( V_136 & V_454 ) )
F_207 ( V_9 ) ;
if ( V_138 [ 0 ] & V_153 )
F_67 ( V_9 ) ;
V_136 = V_452 ;
}
F_198 ( V_9 ) ;
return V_37 ;
}
static void F_213 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_2 ( V_406 , 0 ) ;
F_2 ( V_151 , F_16 ( V_151 ) ) ;
F_2 ( V_400 , 0xffffffff ) ;
F_71 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_448 , 0xffffffff ) ;
F_2 ( V_326 , 0x0 ) ;
F_71 (pipe)
F_2 ( F_6 ( V_5 ) ,
F_16 ( F_6 ( V_5 ) ) & 0x8000ffff ) ;
F_2 ( V_358 , F_16 ( V_358 ) ) ;
}
void F_214 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
F_215 ( & V_1 -> V_56 , F_35 ) ;
F_215 ( & V_1 -> V_86 . V_55 , F_86 ) ;
F_215 ( & V_1 -> V_91 . V_55 , F_49 ) ;
F_215 ( & V_1 -> V_99 . V_100 , F_53 ) ;
F_216 ( & V_1 -> V_86 . V_88 ,
F_177 ,
( unsigned long ) V_9 ) ;
F_217 ( & V_1 -> V_466 , V_467 , V_468 ) ;
V_9 -> V_469 -> V_470 = F_18 ;
V_9 -> V_471 = 0xffffff ;
if ( F_152 ( V_9 ) || F_12 ( V_9 ) -> V_15 >= 5 ) {
V_9 -> V_471 = 0xffffffff ;
V_9 -> V_469 -> V_470 = F_23 ;
}
if ( F_218 ( V_9 , V_472 ) )
V_9 -> V_469 -> V_473 = F_30 ;
else
V_9 -> V_469 -> V_473 = NULL ;
V_9 -> V_469 -> V_474 = F_25 ;
if ( F_9 ( V_9 ) ) {
V_9 -> V_469 -> V_475 = F_69 ;
V_9 -> V_469 -> V_476 = F_179 ;
V_9 -> V_469 -> V_477 = F_187 ;
V_9 -> V_469 -> V_478 = F_192 ;
V_9 -> V_469 -> V_479 = F_164 ;
V_9 -> V_469 -> V_480 = F_169 ;
V_1 -> V_344 . V_481 = F_191 ;
} else if ( F_219 ( V_9 ) || F_220 ( V_9 ) ) {
V_9 -> V_469 -> V_475 = F_78 ;
V_9 -> V_469 -> V_476 = F_178 ;
V_9 -> V_469 -> V_477 = F_186 ;
V_9 -> V_469 -> V_478 = F_193 ;
V_9 -> V_469 -> V_479 = F_163 ;
V_9 -> V_469 -> V_480 = F_168 ;
} else if ( F_11 ( V_9 ) ) {
V_9 -> V_469 -> V_475 = F_82 ;
V_9 -> V_469 -> V_476 = F_178 ;
V_9 -> V_469 -> V_477 = F_184 ;
V_9 -> V_469 -> V_478 = F_193 ;
V_9 -> V_469 -> V_479 = F_162 ;
V_9 -> V_469 -> V_480 = F_167 ;
} else {
if ( F_12 ( V_9 ) -> V_15 == 2 ) {
V_9 -> V_469 -> V_476 = F_194 ;
V_9 -> V_469 -> V_477 = F_196 ;
V_9 -> V_469 -> V_475 = F_197 ;
V_9 -> V_469 -> V_478 = F_199 ;
} else if ( F_12 ( V_9 ) -> V_15 == 3 ) {
V_9 -> V_469 -> V_476 = F_200 ;
V_9 -> V_469 -> V_477 = F_202 ;
V_9 -> V_469 -> V_478 = F_208 ;
V_9 -> V_469 -> V_475 = F_205 ;
V_1 -> V_344 . V_481 = F_204 ;
} else {
V_9 -> V_469 -> V_476 = F_209 ;
V_9 -> V_469 -> V_477 = F_210 ;
V_9 -> V_469 -> V_478 = F_213 ;
V_9 -> V_469 -> V_475 = F_212 ;
V_1 -> V_344 . V_481 = F_211 ;
}
V_9 -> V_469 -> V_479 = F_160 ;
V_9 -> V_469 -> V_480 = F_165 ;
}
}
void F_221 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
if ( V_1 -> V_344 . V_481 )
V_1 -> V_344 . V_481 ( V_9 ) ;
}
