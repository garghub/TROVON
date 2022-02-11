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
return F_15 ( F_16 ( V_5 ) ) & V_16 ;
}
static T_2 F_17 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_17 ;
unsigned long V_18 ;
T_2 V_19 , V_20 , V_21 ;
if ( ! F_14 ( V_9 , V_5 ) ) {
F_18 ( L_1
L_2 , F_19 ( V_5 ) ) ;
return 0 ;
}
V_17 = F_20 ( V_5 ) ;
V_18 = F_21 ( V_5 ) ;
do {
V_19 = F_15 ( V_17 ) & V_22 ;
V_21 = F_15 ( V_18 ) & V_23 ;
V_20 = F_15 ( V_17 ) & V_22 ;
} while ( V_19 != V_20 );
V_19 >>= V_24 ;
V_21 >>= V_25 ;
return ( V_19 << 8 ) | V_21 ;
}
static T_2 F_22 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_7 = F_23 ( V_5 ) ;
if ( ! F_14 ( V_9 , V_5 ) ) {
F_18 ( L_1
L_2 , F_19 ( V_5 ) ) ;
return 0 ;
}
return F_15 ( V_7 ) ;
}
static int F_24 ( struct V_8 * V_9 , int V_5 ,
int * V_26 , int * V_27 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_28 = 0 , V_29 = 0 ;
int V_30 , V_31 , V_32 , V_33 ;
bool V_34 = true ;
int V_35 = 0 ;
if ( ! F_14 ( V_9 , V_5 ) ) {
F_18 ( L_3
L_2 , F_19 ( V_5 ) ) ;
return 0 ;
}
V_33 = 1 + ( ( F_15 ( F_25 ( V_5 ) ) >> 16 ) & 0x1fff ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
V_29 = F_15 ( F_26 ( V_5 ) ) ;
* V_26 = V_29 & 0x1fff ;
* V_27 = 0 ;
} else {
V_29 = ( F_15 ( F_21 ( V_5 ) ) & V_36 ) >> V_37 ;
V_32 = 1 + ( ( F_15 ( F_27 ( V_5 ) ) >> 16 ) & 0x1fff ) ;
* V_26 = V_29 / V_32 ;
* V_27 = V_29 - ( * V_26 * V_32 ) ;
}
V_28 = F_15 ( F_28 ( V_5 ) ) ;
V_30 = V_28 & 0x1fff ;
V_31 = ( V_28 >> 16 ) & 0x1fff ;
if ( ( * V_26 < V_30 ) || ( * V_26 > V_31 ) )
V_34 = false ;
if ( V_34 && ( * V_26 >= V_30 ) )
* V_26 = * V_26 - V_33 ;
if ( V_28 > 0 )
V_35 |= V_38 | V_39 ;
if ( V_34 )
V_35 |= V_40 ;
return V_35 ;
}
static int F_29 ( struct V_8 * V_9 , int V_5 ,
int * V_41 ,
struct V_42 * V_43 ,
unsigned V_44 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_46 * V_47 ;
if ( V_5 < 0 || V_5 >= V_1 -> V_48 ) {
F_30 ( L_4 , V_5 ) ;
return - V_49 ;
}
V_47 = F_31 ( V_9 , V_5 ) ;
if ( V_47 == NULL ) {
F_30 ( L_4 , V_5 ) ;
return - V_49 ;
}
if ( ! V_47 -> V_50 ) {
F_32 ( L_5 , V_5 ) ;
return - V_51 ;
}
return F_33 ( V_9 , V_5 , V_41 ,
V_43 , V_44 ,
V_47 ) ;
}
static void F_34 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_54 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
struct V_55 * V_56 = & V_9 -> V_56 ;
struct V_57 * V_58 ;
F_36 ( & V_56 -> V_59 ) ;
F_32 ( L_6 ) ;
F_37 (encoder, &mode_config->encoder_list, base.head)
if ( V_58 -> V_60 )
V_58 -> V_60 ( V_58 ) ;
F_38 ( & V_56 -> V_59 ) ;
F_39 ( V_9 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
T_2 V_61 , V_62 , V_63 , V_64 ;
T_3 V_65 = V_1 -> V_66 ;
F_41 ( V_67 , V_68 ) ;
V_61 = F_15 ( V_69 ) ;
V_62 = F_15 ( V_70 ) ;
V_63 = F_15 ( V_71 ) ;
V_64 = F_15 ( V_72 ) ;
if ( V_61 > V_63 ) {
if ( V_1 -> V_66 != V_1 -> V_73 )
V_65 = V_1 -> V_66 - 1 ;
if ( V_65 < V_1 -> V_73 )
V_65 = V_1 -> V_73 ;
} else if ( V_62 < V_64 ) {
if ( V_1 -> V_66 != V_1 -> V_74 )
V_65 = V_1 -> V_66 + 1 ;
if ( V_65 > V_1 -> V_74 )
V_65 = V_1 -> V_74 ;
}
if ( F_42 ( V_9 , V_65 ) )
V_1 -> V_66 = V_65 ;
return;
}
static void F_43 ( struct V_8 * V_9 ,
struct V_75 * V_76 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
if ( V_76 -> V_77 == NULL )
return;
F_44 ( V_76 , V_76 -> V_78 ( V_76 ) ) ;
F_45 ( & V_76 -> V_79 ) ;
if ( V_80 ) {
V_1 -> V_81 = 0 ;
F_46 ( & V_1 -> V_82 ,
V_83 +
F_47 ( V_84 ) ) ;
}
}
static void F_48 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_85 ) ;
T_2 V_86 , V_87 ;
T_3 V_65 ;
F_49 ( & V_1 -> V_88 ) ;
V_86 = V_1 -> V_86 ;
V_1 -> V_86 = 0 ;
V_87 = F_15 ( V_89 ) ;
F_2 ( V_89 , 0 ) ;
F_50 ( & V_1 -> V_88 ) ;
if ( ( V_86 & V_90 ) == 0 )
return;
F_36 ( & V_1 -> V_9 -> V_91 ) ;
if ( V_86 & V_92 )
V_65 = V_1 -> V_66 + 1 ;
else
V_65 = V_1 -> V_66 - 1 ;
F_51 ( V_1 -> V_9 , V_65 ) ;
F_38 ( & V_1 -> V_9 -> V_91 ) ;
}
static void F_52 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_93 ) ;
T_2 V_94 , V_95 , V_96 , V_97 ;
char * V_98 [ 5 ] ;
T_4 V_99 ;
unsigned long V_44 ;
F_36 ( & V_1 -> V_9 -> V_91 ) ;
V_99 = F_15 ( V_100 ) ;
F_2 ( V_100 , V_99 & ~ V_101 ) ;
F_3 ( V_100 ) ;
V_94 = F_15 ( V_102 ) ;
V_95 = F_53 ( V_94 ) ;
V_96 = F_54 ( V_94 ) ;
V_97 = F_55 ( V_94 ) ;
F_2 ( V_102 , V_103 |
V_104 ) ;
F_3 ( V_102 ) ;
F_2 ( V_100 , V_99 ) ;
F_10 ( & V_1 -> V_12 , V_44 ) ;
V_1 -> V_105 &= ~ V_106 ;
F_2 ( V_107 , V_1 -> V_105 ) ;
F_13 ( & V_1 -> V_12 , V_44 ) ;
F_38 ( & V_1 -> V_9 -> V_91 ) ;
V_98 [ 0 ] = L_7 ;
V_98 [ 1 ] = F_56 ( V_108 , L_8 , V_95 ) ;
V_98 [ 2 ] = F_56 ( V_108 , L_9 , V_96 ) ;
V_98 [ 3 ] = F_56 ( V_108 , L_10 , V_97 ) ;
V_98 [ 4 ] = NULL ;
F_57 ( & V_1 -> V_9 -> V_109 -> V_110 . V_111 ,
V_112 , V_98 ) ;
F_58 ( L_11 ,
V_95 , V_96 , V_97 ) ;
F_59 ( V_98 [ 3 ] ) ;
F_59 ( V_98 [ 2 ] ) ;
F_59 ( V_98 [ 1 ] ) ;
}
static void F_60 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_44 ;
if ( ! F_61 ( V_9 ) )
return;
F_10 ( & V_1 -> V_12 , V_44 ) ;
V_1 -> V_105 |= V_106 ;
F_2 ( V_107 , V_1 -> V_105 ) ;
F_13 ( & V_1 -> V_12 , V_44 ) ;
F_62 ( V_1 -> V_113 , & V_1 -> V_93 ) ;
}
static void F_63 ( struct V_8 * V_9 ,
struct V_45 * V_1 ,
T_2 V_114 )
{
if ( V_114 & ( V_115 |
V_116 ) )
F_43 ( V_9 , & V_1 -> V_76 [ V_117 ] ) ;
if ( V_114 & V_118 )
F_43 ( V_9 , & V_1 -> V_76 [ V_119 ] ) ;
if ( V_114 & V_120 )
F_43 ( V_9 , & V_1 -> V_76 [ V_121 ] ) ;
if ( V_114 & ( V_122 |
V_123 |
V_124 ) ) {
F_30 ( L_12 , V_114 ) ;
F_64 ( V_9 , false ) ;
}
if ( V_114 & V_106 )
F_60 ( V_9 ) ;
}
static void F_65 ( struct V_45 * V_1 ,
T_2 V_86 )
{
unsigned long V_44 ;
F_10 ( & V_1 -> V_88 , V_44 ) ;
V_1 -> V_86 |= V_86 ;
F_2 ( V_89 , V_1 -> V_86 ) ;
F_3 ( V_89 ) ;
F_13 ( & V_1 -> V_88 , V_44 ) ;
F_62 ( V_1 -> V_113 , & V_1 -> V_85 ) ;
}
static T_5 F_66 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_125 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_126 , V_114 , V_86 ;
T_5 V_35 = V_127 ;
unsigned long V_11 ;
int V_5 ;
T_2 V_128 [ V_129 ] ;
bool V_130 ;
F_67 ( & V_1 -> V_131 ) ;
while ( true ) {
V_126 = F_15 ( V_132 ) ;
V_114 = F_15 ( V_133 ) ;
V_86 = F_15 ( V_134 ) ;
if ( V_114 == 0 && V_86 == 0 && V_126 == 0 )
goto V_135;
V_35 = V_136 ;
F_63 ( V_9 , V_1 , V_114 ) ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_68 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_128 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_128 [ V_5 ] & 0x8000ffff ) {
if ( V_128 [ V_5 ] & V_137 )
F_18 ( L_13 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_128 [ V_5 ] ) ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
F_68 (pipe) {
if ( V_128 [ V_5 ] & V_138 )
F_69 ( V_9 , V_5 ) ;
if ( V_128 [ V_5 ] & V_139 ) {
F_70 ( V_9 , V_5 ) ;
F_71 ( V_9 , V_5 ) ;
}
}
if ( V_126 & V_140 ) {
T_2 V_141 = F_15 ( V_142 ) ;
F_18 ( L_14 ,
V_141 ) ;
if ( V_141 & V_1 -> V_143 )
F_62 ( V_1 -> V_113 ,
& V_1 -> V_54 ) ;
F_2 ( V_142 , V_141 ) ;
F_15 ( V_142 ) ;
}
if ( V_128 [ V_5 ] & V_144 )
V_130 = true ;
if ( V_86 & V_90 )
F_65 ( V_1 , V_86 ) ;
F_2 ( V_133 , V_114 ) ;
F_2 ( V_134 , V_86 ) ;
F_2 ( V_132 , V_126 ) ;
}
V_135:
return V_35 ;
}
static void F_72 ( struct V_8 * V_9 , T_2 V_145 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_145 & V_146 )
F_18 ( L_15 ,
( V_145 & V_146 ) >>
V_147 ) ;
if ( V_145 & V_148 )
F_18 ( L_16 ) ;
if ( V_145 & V_149 )
F_18 ( L_17 ) ;
if ( V_145 & V_150 )
F_18 ( L_18 ) ;
if ( V_145 & V_151 )
F_30 ( L_19 ) ;
if ( V_145 & V_152 )
F_68 (pipe)
F_18 ( L_20 ,
F_19 ( V_5 ) ,
F_15 ( F_73 ( V_5 ) ) ) ;
if ( V_145 & ( V_153 | V_154 ) )
F_18 ( L_21 ) ;
if ( V_145 & ( V_155 | V_156 ) )
F_18 ( L_22 ) ;
if ( V_145 & V_157 )
F_18 ( L_23 ) ;
if ( V_145 & V_158 )
F_18 ( L_24 ) ;
}
static void F_74 ( struct V_8 * V_9 , T_2 V_145 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_145 & V_159 )
F_18 ( L_15 ,
( V_145 & V_159 ) >>
V_160 ) ;
if ( V_145 & V_161 )
F_18 ( L_25 ) ;
if ( V_145 & V_162 )
F_18 ( L_16 ) ;
if ( V_145 & V_163 )
F_18 ( L_26 ) ;
if ( V_145 & V_164 )
F_18 ( L_27 ) ;
if ( V_145 & V_165 )
F_68 (pipe)
F_18 ( L_20 ,
F_19 ( V_5 ) ,
F_15 ( F_73 ( V_5 ) ) ) ;
}
static T_5 F_75 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_125 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_166 , V_114 , V_167 , V_86 ;
T_5 V_35 = V_127 ;
int V_168 ;
F_67 ( & V_1 -> V_131 ) ;
V_167 = F_15 ( V_169 ) ;
F_2 ( V_169 , V_167 & ~ V_170 ) ;
V_114 = F_15 ( V_133 ) ;
if ( V_114 ) {
F_63 ( V_9 , V_1 , V_114 ) ;
F_2 ( V_133 , V_114 ) ;
V_35 = V_136 ;
}
V_166 = F_15 ( V_171 ) ;
if ( V_166 ) {
if ( V_166 & V_172 )
F_76 ( V_9 ) ;
for ( V_168 = 0 ; V_168 < 3 ; V_168 ++ ) {
if ( V_166 & ( V_173 << ( 5 * V_168 ) ) ) {
F_70 ( V_9 , V_168 ) ;
F_77 ( V_9 , V_168 ) ;
}
if ( V_166 & ( V_174 << ( 5 * V_168 ) ) )
F_69 ( V_9 , V_168 ) ;
}
if ( V_166 & V_175 ) {
T_2 V_145 = F_15 ( V_176 ) ;
if ( V_145 & V_177 )
F_62 ( V_1 -> V_113 , & V_1 -> V_54 ) ;
F_74 ( V_9 , V_145 ) ;
F_2 ( V_176 , V_145 ) ;
}
F_2 ( V_171 , V_166 ) ;
V_35 = V_136 ;
}
V_86 = F_15 ( V_134 ) ;
if ( V_86 ) {
if ( V_86 & V_90 )
F_65 ( V_1 , V_86 ) ;
F_2 ( V_134 , V_86 ) ;
V_35 = V_136 ;
}
F_2 ( V_169 , V_167 ) ;
F_3 ( V_169 ) ;
return V_35 ;
}
static void F_78 ( struct V_8 * V_9 ,
struct V_45 * V_1 ,
T_2 V_114 )
{
if ( V_114 & ( V_178 | V_179 ) )
F_43 ( V_9 , & V_1 -> V_76 [ V_117 ] ) ;
if ( V_114 & V_180 )
F_43 ( V_9 , & V_1 -> V_76 [ V_119 ] ) ;
}
static T_5 F_79 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_125 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_35 = V_127 ;
T_2 V_166 , V_114 , V_167 , V_145 , V_86 ;
T_2 V_181 ;
F_67 ( & V_1 -> V_131 ) ;
V_167 = F_15 ( V_169 ) ;
F_2 ( V_169 , V_167 & ~ V_170 ) ;
F_3 ( V_169 ) ;
V_166 = F_15 ( V_171 ) ;
V_114 = F_15 ( V_133 ) ;
V_145 = F_15 ( V_176 ) ;
V_86 = F_15 ( V_134 ) ;
if ( V_166 == 0 && V_114 == 0 && V_145 == 0 &&
( ! F_80 ( V_9 ) || V_86 == 0 ) )
goto V_182;
if ( F_81 ( V_9 ) )
V_181 = V_177 ;
else
V_181 = V_183 ;
V_35 = V_136 ;
if ( F_82 ( V_9 ) )
F_78 ( V_9 , V_1 , V_114 ) ;
else
F_63 ( V_9 , V_1 , V_114 ) ;
if ( V_166 & V_13 )
F_76 ( V_9 ) ;
if ( V_166 & V_184 ) {
F_70 ( V_9 , 0 ) ;
F_77 ( V_9 , 0 ) ;
}
if ( V_166 & V_185 ) {
F_70 ( V_9 , 1 ) ;
F_77 ( V_9 , 1 ) ;
}
if ( V_166 & V_186 )
F_69 ( V_9 , 0 ) ;
if ( V_166 & V_187 )
F_69 ( V_9 , 1 ) ;
if ( V_166 & V_188 ) {
if ( V_145 & V_181 )
F_62 ( V_1 -> V_113 , & V_1 -> V_54 ) ;
if ( F_81 ( V_9 ) )
F_74 ( V_9 , V_145 ) ;
else
F_72 ( V_9 , V_145 ) ;
}
if ( V_166 & V_189 ) {
F_41 ( V_67 , F_15 ( V_67 ) ) ;
F_40 ( V_9 ) ;
}
if ( F_80 ( V_9 ) && V_86 & V_90 )
F_65 ( V_1 , V_86 ) ;
F_2 ( V_176 , V_145 ) ;
F_2 ( V_133 , V_114 ) ;
F_2 ( V_171 , V_166 ) ;
F_2 ( V_134 , V_86 ) ;
V_182:
F_2 ( V_169 , V_167 ) ;
F_3 ( V_169 ) ;
return V_35 ;
}
static void F_83 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_190 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
char * V_191 [] = { L_28 , NULL } ;
char * V_192 [] = { L_29 , NULL } ;
char * V_193 [] = { L_30 , NULL } ;
F_57 ( & V_9 -> V_109 -> V_110 . V_111 , V_112 , V_191 ) ;
if ( F_84 ( & V_1 -> V_194 . V_195 ) ) {
F_18 ( L_31 ) ;
F_57 ( & V_9 -> V_109 -> V_110 . V_111 , V_112 , V_192 ) ;
if ( ! F_85 ( V_9 ) ) {
F_86 ( & V_1 -> V_194 . V_195 , 0 ) ;
F_57 ( & V_9 -> V_109 -> V_110 . V_111 , V_112 , V_193 ) ;
}
F_87 ( & V_1 -> V_196 ) ;
}
}
static struct V_197 *
F_88 ( struct V_45 * V_1 ,
struct V_198 * V_199 )
{
struct V_197 * V_200 ;
int V_201 , V_202 ;
T_2 V_203 ;
if ( V_199 == NULL || V_199 -> V_204 == NULL )
return NULL ;
V_202 = V_199 -> V_205 . V_206 / V_207 ;
V_200 = F_89 ( sizeof( * V_200 ) + V_202 * sizeof( T_2 * ) , V_208 ) ;
if ( V_200 == NULL )
return NULL ;
V_203 = V_199 -> V_209 ;
for ( V_201 = 0 ; V_201 < V_202 ; V_201 ++ ) {
unsigned long V_44 ;
void * V_210 ;
V_210 = F_89 ( V_207 , V_208 ) ;
if ( V_210 == NULL )
goto V_211;
F_90 ( V_44 ) ;
if ( V_203 < V_1 -> V_194 . V_212 &&
V_199 -> V_213 ) {
void T_7 * V_214 ;
V_214 = F_91 ( V_1 -> V_194 . V_215 ,
V_203 ) ;
F_92 ( V_210 , V_214 , V_207 ) ;
F_93 ( V_214 ) ;
} else {
void * V_214 ;
F_94 ( & V_199 -> V_204 [ V_201 ] , 1 ) ;
V_214 = F_95 ( V_199 -> V_204 [ V_201 ] ) ;
memcpy ( V_210 , V_214 , V_207 ) ;
F_96 ( V_214 ) ;
F_94 ( & V_199 -> V_204 [ V_201 ] , 1 ) ;
}
F_97 ( V_44 ) ;
V_200 -> V_204 [ V_201 ] = V_210 ;
V_203 += V_207 ;
}
V_200 -> V_202 = V_202 ;
V_200 -> V_209 = V_199 -> V_209 ;
return V_200 ;
V_211:
while ( V_201 -- )
F_59 ( V_200 -> V_204 [ V_201 ] ) ;
F_59 ( V_200 ) ;
return NULL ;
}
static void
F_98 ( struct V_197 * V_77 )
{
int V_201 ;
if ( V_77 == NULL )
return;
for ( V_201 = 0 ; V_201 < V_77 -> V_202 ; V_201 ++ )
F_59 ( V_77 -> V_204 [ V_201 ] ) ;
F_59 ( V_77 ) ;
}
void
F_99 ( struct V_216 * V_217 )
{
struct V_218 * error = F_35 ( V_217 ,
F_100 ( * error ) , V_219 ) ;
int V_168 ;
for ( V_168 = 0 ; V_168 < F_101 ( error -> V_76 ) ; V_168 ++ ) {
F_98 ( error -> V_76 [ V_168 ] . V_220 ) ;
F_98 ( error -> V_76 [ V_168 ] . V_221 ) ;
F_59 ( error -> V_76 [ V_168 ] . V_222 ) ;
}
F_59 ( error -> V_223 ) ;
F_59 ( error -> V_224 ) ;
F_59 ( error ) ;
}
static void F_102 ( struct V_225 * V_226 ,
struct V_198 * V_77 )
{
V_226 -> V_206 = V_77 -> V_205 . V_206 ;
V_226 -> V_227 = V_77 -> V_205 . V_227 ;
V_226 -> V_228 = V_77 -> V_229 ;
V_226 -> V_209 = V_77 -> V_209 ;
V_226 -> V_230 = V_77 -> V_205 . V_230 ;
V_226 -> V_231 = V_77 -> V_205 . V_231 ;
V_226 -> V_232 = V_77 -> V_232 ;
V_226 -> V_233 = 0 ;
if ( V_77 -> V_234 > 0 )
V_226 -> V_233 = 1 ;
if ( V_77 -> V_235 > 0 )
V_226 -> V_233 = - 1 ;
V_226 -> V_236 = V_77 -> V_237 ;
V_226 -> V_238 = V_77 -> V_238 ;
V_226 -> V_239 = V_77 -> V_240 != V_241 ;
V_226 -> V_76 = V_77 -> V_76 ? V_77 -> V_76 -> V_242 : - 1 ;
V_226 -> V_243 = V_77 -> V_243 ;
}
static T_2 F_103 ( struct V_225 * V_226 ,
int V_244 , struct V_245 * V_246 )
{
struct V_198 * V_77 ;
int V_168 = 0 ;
F_37 (obj, head, mm_list) {
F_102 ( V_226 ++ , V_77 ) ;
if ( ++ V_168 == V_244 )
break;
}
return V_168 ;
}
static T_2 F_104 ( struct V_225 * V_226 ,
int V_244 , struct V_245 * V_246 )
{
struct V_198 * V_77 ;
int V_168 = 0 ;
F_37 (obj, head, gtt_list) {
if ( V_77 -> V_234 == 0 )
continue;
F_102 ( V_226 ++ , V_77 ) ;
if ( ++ V_168 == V_244 )
break;
}
return V_168 ;
}
static void F_105 ( struct V_8 * V_9 ,
struct V_218 * error )
{
struct V_45 * V_1 = V_9 -> V_10 ;
int V_168 ;
switch ( F_12 ( V_9 ) -> V_15 ) {
case 7 :
case 6 :
for ( V_168 = 0 ; V_168 < 16 ; V_168 ++ )
error -> V_247 [ V_168 ] = F_106 ( V_248 + ( V_168 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_168 = 0 ; V_168 < 16 ; V_168 ++ )
error -> V_247 [ V_168 ] = F_106 ( V_249 + ( V_168 * 8 ) ) ;
break;
case 3 :
if ( F_107 ( V_9 ) || F_108 ( V_9 ) || F_109 ( V_9 ) )
for ( V_168 = 0 ; V_168 < 8 ; V_168 ++ )
error -> V_247 [ V_168 + 8 ] = F_15 ( V_250 + ( V_168 * 4 ) ) ;
case 2 :
for ( V_168 = 0 ; V_168 < 8 ; V_168 ++ )
error -> V_247 [ V_168 ] = F_15 ( V_251 + ( V_168 * 4 ) ) ;
break;
}
}
static struct V_197 *
F_110 ( struct V_45 * V_1 ,
struct V_75 * V_76 )
{
struct V_198 * V_77 ;
T_2 V_228 ;
if ( ! V_76 -> V_78 )
return NULL ;
V_228 = V_76 -> V_78 ( V_76 ) ;
F_37 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_77 -> V_76 != V_76 )
continue;
if ( F_111 ( V_228 , V_77 -> V_229 ) )
continue;
if ( ( V_77 -> V_205 . V_230 & V_252 ) == 0 )
continue;
return F_88 ( V_1 , V_77 ) ;
}
return NULL ;
}
static void F_112 ( struct V_8 * V_9 ,
struct V_218 * error ,
struct V_75 * V_76 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> V_253 [ V_76 -> V_242 ] = F_15 ( V_76 -> V_254 + 0x50 ) ;
error -> V_255 [ V_76 -> V_242 ] = F_15 ( F_113 ( V_76 ) ) ;
error -> V_256 [ V_76 -> V_242 ] [ 0 ]
= F_15 ( F_114 ( V_76 -> V_254 ) ) ;
error -> V_256 [ V_76 -> V_242 ] [ 1 ]
= F_15 ( F_115 ( V_76 -> V_254 ) ) ;
}
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
error -> V_257 [ V_76 -> V_242 ] = F_15 ( F_116 ( V_76 -> V_254 ) ) ;
error -> V_258 [ V_76 -> V_242 ] = F_15 ( F_117 ( V_76 -> V_254 ) ) ;
error -> V_259 [ V_76 -> V_242 ] = F_15 ( F_118 ( V_76 -> V_254 ) ) ;
error -> V_260 [ V_76 -> V_242 ] = F_15 ( F_119 ( V_76 -> V_254 ) ) ;
error -> V_261 [ V_76 -> V_242 ] = F_15 ( F_120 ( V_76 -> V_254 ) ) ;
if ( V_76 -> V_242 == V_117 ) {
error -> V_262 = F_15 ( V_263 ) ;
error -> V_264 = F_106 ( V_265 ) ;
}
} else {
error -> V_257 [ V_76 -> V_242 ] = F_15 ( V_266 ) ;
error -> V_258 [ V_76 -> V_242 ] = F_15 ( V_267 ) ;
error -> V_259 [ V_76 -> V_242 ] = F_15 ( V_268 ) ;
error -> V_260 [ V_76 -> V_242 ] = F_15 ( V_269 ) ;
}
error -> V_270 [ V_76 -> V_242 ] = F_121 ( & V_76 -> V_79 ) ;
error -> V_271 [ V_76 -> V_242 ] = F_15 ( F_122 ( V_76 -> V_254 ) ) ;
error -> V_228 [ V_76 -> V_242 ] = V_76 -> V_78 ( V_76 ) ;
error -> V_272 [ V_76 -> V_242 ] = F_123 ( V_76 ) ;
error -> V_246 [ V_76 -> V_242 ] = F_124 ( V_76 ) ;
error -> V_273 [ V_76 -> V_242 ] = F_125 ( V_76 ) ;
error -> V_274 [ V_76 -> V_242 ] = V_76 -> V_246 ;
error -> V_275 [ V_76 -> V_242 ] = V_76 -> V_273 ;
}
static void F_126 ( struct V_8 * V_9 ,
struct V_218 * error )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_75 * V_76 ;
struct V_276 * V_277 ;
int V_168 , V_244 ;
F_127 (ring, dev_priv, i) {
F_112 ( V_9 , error , V_76 ) ;
error -> V_76 [ V_168 ] . V_220 =
F_110 ( V_1 , V_76 ) ;
error -> V_76 [ V_168 ] . V_221 =
F_88 ( V_1 , V_76 -> V_77 ) ;
V_244 = 0 ;
F_37 (request, &ring->request_list, list)
V_244 ++ ;
error -> V_76 [ V_168 ] . V_278 = V_244 ;
error -> V_76 [ V_168 ] . V_222 =
F_89 ( V_244 * sizeof( struct V_279 ) ,
V_208 ) ;
if ( error -> V_76 [ V_168 ] . V_222 == NULL ) {
error -> V_76 [ V_168 ] . V_278 = 0 ;
continue;
}
V_244 = 0 ;
F_37 (request, &ring->request_list, list) {
struct V_279 * V_280 ;
V_280 = & error -> V_76 [ V_168 ] . V_222 [ V_244 ++ ] ;
V_280 -> V_228 = V_277 -> V_228 ;
V_280 -> V_83 = V_277 -> V_281 ;
V_280 -> V_273 = V_277 -> V_273 ;
}
}
}
static void F_128 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_198 * V_77 ;
struct V_218 * error ;
unsigned long V_44 ;
int V_168 , V_5 ;
F_10 ( & V_1 -> V_282 , V_44 ) ;
error = V_1 -> V_283 ;
F_13 ( & V_1 -> V_282 , V_44 ) ;
if ( error )
return;
error = F_129 ( sizeof( * error ) , V_208 ) ;
if ( ! error ) {
F_18 ( L_32 ) ;
return;
}
F_130 ( L_33 ,
V_9 -> V_109 -> V_284 ) ;
F_131 ( & error -> V_219 ) ;
error -> V_285 = F_15 ( V_286 ) ;
error -> V_287 = F_15 ( V_288 ) ;
error -> V_289 = F_15 ( V_290 ) ;
if ( F_11 ( V_9 ) )
error -> V_291 = F_15 ( V_169 ) | F_15 ( V_292 ) ;
else if ( F_9 ( V_9 ) )
error -> V_291 = F_15 ( V_292 ) | F_15 ( V_293 ) ;
else if ( F_132 ( V_9 ) )
error -> V_291 = F_133 ( V_294 ) ;
else
error -> V_291 = F_15 ( V_294 ) ;
F_68 ( V_5 )
error -> V_6 [ V_5 ] = F_15 ( F_6 ( V_5 ) ) ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> error = F_15 ( V_295 ) ;
error -> V_296 = F_15 ( V_297 ) ;
}
F_105 ( V_9 , error ) ;
F_126 ( V_9 , error ) ;
error -> V_223 = NULL ;
error -> V_298 = NULL ;
V_168 = 0 ;
F_37 (obj, &dev_priv->mm.active_list, mm_list)
V_168 ++ ;
error -> V_299 = V_168 ;
F_37 (obj, &dev_priv->mm.gtt_list, gtt_list)
if ( V_77 -> V_234 )
V_168 ++ ;
error -> V_300 = V_168 - error -> V_299 ;
error -> V_223 = NULL ;
error -> V_298 = NULL ;
if ( V_168 ) {
error -> V_223 = F_89 ( sizeof( * error -> V_223 ) * V_168 ,
V_208 ) ;
if ( error -> V_223 )
error -> V_298 =
error -> V_223 + error -> V_299 ;
}
if ( error -> V_223 )
error -> V_299 =
F_103 ( error -> V_223 ,
error -> V_299 ,
& V_1 -> V_194 . V_301 ) ;
if ( error -> V_298 )
error -> V_300 =
F_104 ( error -> V_298 ,
error -> V_300 ,
& V_1 -> V_194 . V_302 ) ;
F_134 ( & error -> time ) ;
error -> V_224 = F_135 ( V_9 ) ;
error -> V_303 = F_136 ( V_9 ) ;
F_10 ( & V_1 -> V_282 , V_44 ) ;
if ( V_1 -> V_283 == NULL ) {
V_1 -> V_283 = error ;
error = NULL ;
}
F_13 ( & V_1 -> V_282 , V_44 ) ;
if ( error )
F_99 ( & error -> V_219 ) ;
}
void F_137 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_218 * error ;
unsigned long V_44 ;
F_10 ( & V_1 -> V_282 , V_44 ) ;
error = V_1 -> V_283 ;
V_1 -> V_283 = NULL ;
F_13 ( & V_1 -> V_282 , V_44 ) ;
if ( error )
F_138 ( & error -> V_219 , F_99 ) ;
}
static void F_139 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
T_2 V_285 = F_15 ( V_286 ) ;
int V_5 ;
if ( ! V_285 )
return;
F_140 ( L_34 , V_285 ) ;
if ( F_141 ( V_9 ) ) {
if ( V_285 & ( V_304 | V_305 ) ) {
T_2 V_258 = F_15 ( V_306 ) ;
F_140 ( L_35 , F_15 ( V_306 ) ) ;
F_140 ( L_36 , F_15 ( V_307 ) ) ;
F_140 ( L_37 ,
F_15 ( V_308 ) ) ;
F_140 ( L_38 , F_15 ( V_309 ) ) ;
F_140 ( L_39 , F_15 ( V_263 ) ) ;
F_140 ( L_40 , F_15 ( V_310 ) ) ;
F_2 ( V_306 , V_258 ) ;
F_3 ( V_306 ) ;
}
if ( V_285 & V_311 ) {
T_2 V_312 = F_15 ( V_288 ) ;
F_140 ( L_41 ) ;
F_140 ( L_42 , V_312 ) ;
F_2 ( V_288 , V_312 ) ;
F_3 ( V_288 ) ;
}
}
if ( ! F_132 ( V_9 ) ) {
if ( V_285 & V_313 ) {
T_2 V_312 = F_15 ( V_288 ) ;
F_140 ( L_41 ) ;
F_140 ( L_42 , V_312 ) ;
F_2 ( V_288 , V_312 ) ;
F_3 ( V_288 ) ;
}
}
if ( V_285 & V_314 ) {
F_140 ( L_43 ) ;
F_68 (pipe)
F_140 ( L_44 ,
F_19 ( V_5 ) , F_15 ( F_6 ( V_5 ) ) ) ;
}
if ( V_285 & V_315 ) {
F_140 ( L_45 ) ;
F_140 ( L_46 , F_15 ( V_316 ) ) ;
if ( F_12 ( V_9 ) -> V_15 < 4 ) {
T_2 V_258 = F_15 ( V_267 ) ;
F_140 ( L_35 , F_15 ( V_267 ) ) ;
F_140 ( L_36 , F_15 ( V_268 ) ) ;
F_140 ( L_37 , F_15 ( V_269 ) ) ;
F_140 ( L_40 , F_15 ( V_317 ) ) ;
F_2 ( V_267 , V_258 ) ;
F_3 ( V_267 ) ;
} else {
T_2 V_258 = F_15 ( V_306 ) ;
F_140 ( L_35 , F_15 ( V_306 ) ) ;
F_140 ( L_36 , F_15 ( V_307 ) ) ;
F_140 ( L_37 ,
F_15 ( V_308 ) ) ;
F_140 ( L_38 , F_15 ( V_309 ) ) ;
F_140 ( L_39 , F_15 ( V_263 ) ) ;
F_140 ( L_40 , F_15 ( V_310 ) ) ;
F_2 ( V_306 , V_258 ) ;
F_3 ( V_306 ) ;
}
}
F_2 ( V_286 , V_285 ) ;
F_3 ( V_286 ) ;
V_285 = F_15 ( V_286 ) ;
if ( V_285 ) {
F_30 ( L_47 , V_285 ) ;
F_2 ( V_318 , F_15 ( V_318 ) | V_285 ) ;
F_2 ( V_319 , V_320 ) ;
}
}
void F_64 ( struct V_8 * V_9 , bool V_195 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_75 * V_76 ;
int V_168 ;
F_128 ( V_9 ) ;
F_139 ( V_9 ) ;
if ( V_195 ) {
F_142 ( V_1 -> V_196 ) ;
F_86 ( & V_1 -> V_194 . V_195 , 1 ) ;
F_127 (ring, dev_priv, i)
F_45 ( & V_76 -> V_79 ) ;
}
F_62 ( V_1 -> V_113 , & V_1 -> V_190 ) ;
}
static void F_143 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = V_9 -> V_10 ;
struct V_46 * V_47 = V_1 -> V_321 [ V_5 ] ;
struct V_322 * V_322 = F_144 ( V_47 ) ;
struct V_198 * V_77 ;
struct V_323 * V_53 ;
unsigned long V_44 ;
bool V_324 ;
if ( V_322 == NULL )
return;
F_10 ( & V_9 -> V_325 , V_44 ) ;
V_53 = V_322 -> V_326 ;
if ( V_53 == NULL || V_53 -> V_327 || ! V_53 -> V_328 ) {
F_13 ( & V_9 -> V_325 , V_44 ) ;
return;
}
V_77 = V_53 -> V_329 ;
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
int V_330 = F_145 ( V_322 -> V_331 ) ;
V_324 = F_146 ( F_15 ( V_330 ) ) ==
V_77 -> V_209 ;
} else {
int V_332 = F_147 ( V_322 -> V_331 ) ;
V_324 = F_15 ( V_332 ) == ( V_77 -> V_209 +
V_47 -> V_333 * V_47 -> V_334 -> V_335 [ 0 ] +
V_47 -> V_336 * V_47 -> V_334 -> V_337 / 8 ) ;
}
F_13 ( & V_9 -> V_325 , V_44 ) ;
if ( V_324 ) {
F_18 ( L_48 ) ;
F_70 ( V_9 , V_322 -> V_331 ) ;
}
}
static int F_148 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 )
F_5 ( V_1 , V_5 ,
V_338 ) ;
else
F_5 ( V_1 , V_5 ,
V_339 ) ;
if ( V_1 -> V_340 -> V_15 == 3 )
F_2 ( V_316 , F_149 ( V_341 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_150 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 , ( V_5 == 0 ) ?
V_186 : V_187 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_151 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 ,
V_174 << ( 5 * V_5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_152 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_342 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
V_342 = F_15 ( V_343 ) ;
if ( V_5 == 0 )
V_342 &= ~ V_344 ;
else
V_342 &= ~ V_345 ;
F_2 ( V_343 , V_342 ) ;
F_5 ( V_1 , V_5 ,
V_338 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static void F_153 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_1 -> V_340 -> V_15 == 3 )
F_2 ( V_316 , F_154 ( V_341 ) ) ;
F_7 ( V_1 , V_5 ,
V_339 |
V_338 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_155 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 , ( V_5 == 0 ) ?
V_186 : V_187 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_156 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 ,
V_174 << ( V_5 * 5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_157 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_342 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_7 ( V_1 , V_5 ,
V_338 ) ;
V_342 = F_15 ( V_343 ) ;
if ( V_5 == 0 )
V_342 |= V_344 ;
else
V_342 |= V_345 ;
F_2 ( V_343 , V_342 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static T_2
F_158 ( struct V_75 * V_76 )
{
return F_159 ( V_76 -> V_346 . V_347 ,
struct V_276 , V_348 ) -> V_228 ;
}
static bool F_160 ( struct V_75 * V_76 , bool * V_226 )
{
if ( F_161 ( & V_76 -> V_346 ) ||
F_111 ( V_76 -> V_78 ( V_76 ) , F_158 ( V_76 ) ) ) {
if ( F_121 ( & V_76 -> V_79 ) ) {
F_30 ( L_49 ,
V_76 -> V_227 ) ;
F_45 ( & V_76 -> V_79 ) ;
* V_226 = true ;
}
return true ;
}
return false ;
}
static bool F_162 ( struct V_75 * V_76 )
{
struct V_8 * V_9 = V_76 -> V_9 ;
struct V_45 * V_1 = V_9 -> V_10 ;
T_2 V_349 = F_163 ( V_76 ) ;
if ( V_349 & V_350 ) {
F_30 ( L_50 ,
V_76 -> V_227 ) ;
F_164 ( V_76 , V_349 ) ;
return true ;
}
return false ;
}
static bool F_165 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
if ( V_1 -> V_81 ++ > 1 ) {
bool V_351 = true ;
F_30 ( L_51 ) ;
F_64 ( V_9 , true ) ;
if ( ! F_132 ( V_9 ) ) {
struct V_75 * V_76 ;
int V_168 ;
F_127 (ring, dev_priv, i)
V_351 &= ! F_162 ( V_76 ) ;
}
return V_351 ;
}
return false ;
}
void F_166 ( unsigned long V_352 )
{
struct V_8 * V_9 = (struct V_8 * ) V_352 ;
T_1 * V_1 = V_9 -> V_10 ;
T_4 V_272 [ V_353 ] , V_260 , V_262 ;
struct V_75 * V_76 ;
bool V_226 = false , V_354 ;
int V_168 ;
if ( ! V_80 )
return;
memset ( V_272 , 0 , sizeof( V_272 ) ) ;
V_354 = true ;
F_127 (ring, dev_priv, i) {
V_354 &= F_160 ( V_76 , & V_226 ) ;
V_272 [ V_168 ] = F_123 ( V_76 ) ;
}
if ( V_354 ) {
if ( V_226 ) {
if ( F_165 ( V_9 ) )
return;
goto V_355;
}
V_1 -> V_81 = 0 ;
return;
}
if ( F_12 ( V_9 ) -> V_15 < 4 ) {
V_260 = F_15 ( V_269 ) ;
V_262 = 0 ;
} else {
V_260 = F_15 ( V_308 ) ;
V_262 = F_15 ( V_263 ) ;
}
if ( memcmp ( V_1 -> V_356 , V_272 , sizeof( V_272 ) ) == 0 &&
V_1 -> V_357 == V_260 &&
V_1 -> V_358 == V_262 ) {
if ( F_165 ( V_9 ) )
return;
} else {
V_1 -> V_81 = 0 ;
memcpy ( V_1 -> V_356 , V_272 , sizeof( V_272 ) ) ;
V_1 -> V_357 = V_260 ;
V_1 -> V_358 = V_262 ;
}
V_355:
F_46 ( & V_1 -> V_82 ,
V_83 + F_47 ( V_84 ) ) ;
}
static void F_167 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_86 ( & V_1 -> V_131 , 0 ) ;
F_2 ( V_359 , 0xeffe ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_169 , 0x0 ) ;
F_3 ( V_169 ) ;
F_2 ( V_107 , 0xffffffff ) ;
F_2 ( V_292 , 0x0 ) ;
F_3 ( V_292 ) ;
F_2 ( V_360 , 0xffffffff ) ;
F_2 ( V_361 , 0x0 ) ;
F_3 ( V_361 ) ;
}
static void F_168 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_86 ( & V_1 -> V_131 , 0 ) ;
F_2 ( V_343 , 0 ) ;
F_2 ( F_169 ( V_362 ) , 0 ) ;
F_2 ( F_169 ( V_363 ) , 0 ) ;
F_2 ( F_169 ( V_364 ) , 0 ) ;
F_2 ( V_133 , F_15 ( V_133 ) ) ;
F_2 ( V_133 , F_15 ( V_133 ) ) ;
F_2 ( V_107 , 0xffffffff ) ;
F_2 ( V_292 , 0x0 ) ;
F_3 ( V_292 ) ;
F_2 ( V_365 , 0xff ) ;
F_2 ( V_366 , 0 ) ;
F_2 ( V_142 , F_15 ( V_142 ) ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_132 , 0xffffffff ) ;
F_2 ( V_343 , 0xffffffff ) ;
F_2 ( V_293 , 0x0 ) ;
F_3 ( V_293 ) ;
}
static void F_170 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_367 ;
V_367 = F_15 ( V_368 ) ;
V_367 &= ~ ( V_369 | V_370 | V_371 ) ;
V_367 |= V_372 | V_373 ;
V_367 |= V_374 | V_375 ;
V_367 |= V_376 | V_377 ;
F_2 ( V_368 , V_367 ) ;
}
static int F_171 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_378 = V_170 | V_13 | V_188 |
V_184 | V_185 ;
T_2 V_379 ;
T_2 V_181 ;
V_1 -> V_3 = ~ V_378 ;
F_2 ( V_171 , F_15 ( V_171 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_169 , V_378 | V_186 | V_187 ) ;
F_3 ( V_169 ) ;
V_1 -> V_105 = ~ 0 ;
F_2 ( V_133 , F_15 ( V_133 ) ) ;
F_2 ( V_107 , V_1 -> V_105 ) ;
if ( F_80 ( V_9 ) )
V_379 =
V_178 |
V_118 |
V_120 ;
else
V_379 =
V_178 |
V_179 |
V_180 ;
F_2 ( V_292 , V_379 ) ;
F_3 ( V_292 ) ;
if ( F_81 ( V_9 ) ) {
V_181 = ( V_380 |
V_381 |
V_382 |
V_383 ) ;
} else {
V_181 = ( V_384 |
V_385 |
V_386 |
V_387 |
V_388 ) ;
}
V_1 -> V_389 = ~ V_181 ;
F_2 ( V_176 , F_15 ( V_176 ) ) ;
F_2 ( V_360 , V_1 -> V_389 ) ;
F_2 ( V_361 , V_181 ) ;
F_3 ( V_361 ) ;
F_170 ( V_9 ) ;
if ( F_172 ( V_9 ) ) {
F_2 ( V_171 , V_189 ) ;
F_2 ( V_169 , F_15 ( V_169 ) | V_189 ) ;
F_1 ( V_1 , V_189 ) ;
}
return 0 ;
}
static int F_173 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_378 =
V_170 | V_172 | V_175 |
V_390 |
V_391 |
V_173 ;
T_2 V_379 ;
T_2 V_181 ;
V_1 -> V_3 = ~ V_378 ;
F_2 ( V_171 , F_15 ( V_171 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_169 ,
V_378 |
V_392 |
V_393 |
V_174 ) ;
F_3 ( V_169 ) ;
V_1 -> V_105 = ~ V_106 ;
F_2 ( V_133 , F_15 ( V_133 ) ) ;
F_2 ( V_107 , V_1 -> V_105 ) ;
V_379 = V_178 | V_118 |
V_120 | V_106 ;
F_2 ( V_292 , V_379 ) ;
F_3 ( V_292 ) ;
V_181 = ( V_380 |
V_381 |
V_382 |
V_383 ) ;
V_1 -> V_389 = ~ V_181 ;
F_2 ( V_176 , F_15 ( V_176 ) ) ;
F_2 ( V_360 , V_1 -> V_389 ) ;
F_2 ( V_361 , V_181 ) ;
F_3 ( V_361 ) ;
F_170 ( V_9 ) ;
return 0 ;
}
static int F_174 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_394 ;
T_2 V_395 = F_15 ( V_366 ) ;
T_2 V_396 = V_397 ;
T_8 V_398 ;
V_394 = V_140 ;
V_394 |= V_399 |
V_344 |
V_400 |
V_345 ;
V_1 -> V_3 = ( ~ V_394 ) |
V_344 |
V_345 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_175 ( V_1 -> V_9 -> V_401 , 0x94 , 0xfee00000 ) ;
F_176 ( V_9 -> V_401 , 0x98 , & V_398 ) ;
V_398 &= 0xff ;
V_398 |= ( 1 << 14 ) ;
F_177 ( V_1 -> V_9 -> V_401 , 0x98 , V_398 ) ;
F_2 ( V_343 , V_1 -> V_3 ) ;
F_2 ( V_293 , V_394 ) ;
F_2 ( V_132 , 0xffffffff ) ;
F_2 ( F_6 ( 0 ) , 0xffff ) ;
F_2 ( F_6 ( 1 ) , 0xffff ) ;
F_3 ( V_293 ) ;
F_5 ( V_1 , 0 , V_396 ) ;
F_5 ( V_1 , 1 , V_396 ) ;
F_2 ( V_132 , 0xffffffff ) ;
F_2 ( V_132 , 0xffffffff ) ;
V_1 -> V_105 = ~ 0 ;
F_2 ( V_133 , F_15 ( V_133 ) ) ;
F_2 ( V_133 , F_15 ( V_133 ) ) ;
F_2 ( V_107 , V_1 -> V_105 ) ;
F_2 ( V_292 , V_402 |
V_122 |
V_403 |
V_404 |
V_123 |
V_106 |
V_179 |
V_124 |
V_405 |
V_178 ) ;
F_3 ( V_292 ) ;
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
F_2 ( V_406 , V_407 ) ;
#if 0
if (dev_priv->hotplug_supported_mask & HDMIB_HOTPLUG_INT_STATUS)
hotplug_en |= HDMIB_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & HDMIC_HOTPLUG_INT_STATUS)
hotplug_en |= HDMIC_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & HDMID_HOTPLUG_INT_STATUS)
hotplug_en |= HDMID_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & SDVOC_HOTPLUG_INT_STATUS)
hotplug_en |= SDVOC_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & SDVOB_HOTPLUG_INT_STATUS)
hotplug_en |= SDVOB_HOTPLUG_INT_EN;
if (dev_priv->hotplug_supported_mask & CRT_HOTPLUG_INT_STATUS) {
hotplug_en |= CRT_HOTPLUG_INT_EN;
hotplug_en |= CRT_HOTPLUG_VOLTAGE_COMPARE_50;
}
#endif
F_2 ( V_366 , V_395 ) ;
return 0 ;
}
static void F_178 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_359 , 0xffffffff ) ;
F_2 ( V_366 , 0 ) ;
F_2 ( V_142 , F_15 ( V_142 ) ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_132 , 0xffffffff ) ;
F_2 ( V_343 , 0xffffffff ) ;
F_2 ( V_293 , 0x0 ) ;
F_3 ( V_293 ) ;
}
static void F_179 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
if ( ! V_1 )
return;
F_2 ( V_359 , 0xffffffff ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_169 , 0x0 ) ;
F_2 ( V_171 , F_15 ( V_171 ) ) ;
F_2 ( V_107 , 0xffffffff ) ;
F_2 ( V_292 , 0x0 ) ;
F_2 ( V_133 , F_15 ( V_133 ) ) ;
F_2 ( V_360 , 0xffffffff ) ;
F_2 ( V_361 , 0x0 ) ;
F_2 ( V_176 , F_15 ( V_176 ) ) ;
}
static void F_180 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_86 ( & V_1 -> V_131 , 0 ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_41 ( V_408 , 0xffff ) ;
F_41 ( V_294 , 0x0 ) ;
F_181 ( V_294 ) ;
}
static int F_182 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_41 ( V_318 ,
~ ( V_313 | V_314 ) ) ;
V_1 -> V_3 =
~ ( V_399 |
V_400 |
V_409 |
V_410 |
V_320 ) ;
F_41 ( V_408 , V_1 -> V_3 ) ;
F_41 ( V_294 ,
V_399 |
V_400 |
V_320 |
V_411 ) ;
F_181 ( V_294 ) ;
return 0 ;
}
static T_5 F_183 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_125 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_8 V_126 , V_412 ;
T_2 V_128 [ 2 ] ;
unsigned long V_11 ;
int V_131 ;
int V_5 ;
T_8 V_413 =
V_409 |
V_410 ;
F_67 ( & V_1 -> V_131 ) ;
V_126 = F_133 ( V_319 ) ;
if ( V_126 == 0 )
return V_127 ;
while ( V_126 & ~ V_413 ) {
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_126 & V_320 )
F_64 ( V_9 , false ) ;
F_68 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_128 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_128 [ V_5 ] & 0x8000ffff ) {
if ( V_128 [ V_5 ] & V_137 )
F_18 ( L_13 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_128 [ V_5 ] ) ;
V_131 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
F_41 ( V_319 , V_126 & ~ V_413 ) ;
V_412 = F_133 ( V_319 ) ;
F_184 ( V_9 ) ;
if ( V_126 & V_411 )
F_43 ( V_9 , & V_1 -> V_76 [ V_117 ] ) ;
if ( V_128 [ 0 ] & V_138 &&
F_69 ( V_9 , 0 ) ) {
if ( V_126 & V_409 ) {
F_70 ( V_9 , 0 ) ;
F_71 ( V_9 , 0 ) ;
V_413 &= ~ V_409 ;
}
}
if ( V_128 [ 1 ] & V_138 &&
F_69 ( V_9 , 1 ) ) {
if ( V_126 & V_410 ) {
F_70 ( V_9 , 1 ) ;
F_71 ( V_9 , 1 ) ;
V_413 &= ~ V_410 ;
}
}
V_126 = V_412 ;
}
return V_136 ;
}
static void F_185 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_68 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_15 ( F_6 ( V_5 ) ) ) ;
}
F_41 ( V_408 , 0xffff ) ;
F_41 ( V_294 , 0x0 ) ;
F_41 ( V_319 , F_133 ( V_319 ) ) ;
}
static void F_186 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_86 ( & V_1 -> V_131 , 0 ) ;
if ( F_187 ( V_9 ) ) {
F_2 ( V_366 , 0 ) ;
F_2 ( V_142 , F_15 ( V_142 ) ) ;
}
F_41 ( V_359 , 0xeffe ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_408 , 0xffffffff ) ;
F_2 ( V_294 , 0x0 ) ;
F_3 ( V_294 ) ;
}
static int F_188 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_394 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_2 ( V_318 , ~ ( V_313 | V_314 ) ) ;
V_1 -> V_3 =
~ ( V_414 |
V_399 |
V_400 |
V_409 |
V_410 |
V_320 ) ;
V_394 =
V_414 |
V_399 |
V_400 |
V_320 |
V_411 ;
if ( F_187 ( V_9 ) ) {
V_394 |= V_140 ;
V_1 -> V_3 &= ~ V_140 ;
}
F_2 ( V_408 , V_1 -> V_3 ) ;
F_2 ( V_294 , V_394 ) ;
F_3 ( V_294 ) ;
if ( F_187 ( V_9 ) ) {
T_2 V_395 = F_15 ( V_366 ) ;
if ( V_1 -> V_143 & V_415 )
V_395 |= V_416 ;
if ( V_1 -> V_143 & V_417 )
V_395 |= V_418 ;
if ( V_1 -> V_143 & V_419 )
V_395 |= V_420 ;
if ( V_1 -> V_143 & V_421 )
V_395 |= V_422 ;
if ( V_1 -> V_143 & V_423 )
V_395 |= V_424 ;
if ( V_1 -> V_143 & V_425 ) {
V_395 |= V_426 ;
V_395 |= V_427 ;
}
F_2 ( V_366 , V_395 ) ;
}
F_189 ( V_9 ) ;
return 0 ;
}
static T_5 F_190 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_125 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_126 , V_412 , V_128 [ V_129 ] ;
unsigned long V_11 ;
T_2 V_413 =
V_409 |
V_410 ;
T_2 V_428 [ 2 ] = {
V_409 ,
V_410
} ;
int V_5 , V_35 = V_127 ;
F_67 ( & V_1 -> V_131 ) ;
V_126 = F_15 ( V_319 ) ;
do {
bool V_131 = ( V_126 & ~ V_413 ) != 0 ;
bool V_130 = false ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_126 & V_320 )
F_64 ( V_9 , false ) ;
F_68 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_128 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_128 [ V_5 ] & 0x8000ffff ) {
if ( V_128 [ V_5 ] & V_137 )
F_18 ( L_13 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_128 [ V_5 ] ) ;
V_131 = true ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_131 )
break;
if ( ( F_187 ( V_9 ) ) &&
( V_126 & V_140 ) ) {
T_2 V_141 = F_15 ( V_142 ) ;
F_18 ( L_14 ,
V_141 ) ;
if ( V_141 & V_1 -> V_143 )
F_62 ( V_1 -> V_113 ,
& V_1 -> V_54 ) ;
F_2 ( V_142 , V_141 ) ;
F_3 ( V_142 ) ;
}
F_2 ( V_319 , V_126 & ~ V_413 ) ;
V_412 = F_15 ( V_319 ) ;
if ( V_126 & V_411 )
F_43 ( V_9 , & V_1 -> V_76 [ V_117 ] ) ;
F_68 (pipe) {
int V_331 = V_5 ;
if ( F_191 ( V_9 ) )
V_331 = ! V_331 ;
if ( V_128 [ V_5 ] & V_138 &&
F_69 ( V_9 , V_5 ) ) {
if ( V_126 & V_428 [ V_331 ] ) {
F_70 ( V_9 , V_331 ) ;
F_71 ( V_9 , V_5 ) ;
V_413 &= ~ V_428 [ V_331 ] ;
}
}
if ( V_128 [ V_5 ] & V_144 )
V_130 = true ;
}
if ( V_130 || ( V_126 & V_414 ) )
F_192 ( V_9 ) ;
V_35 = V_136 ;
V_126 = V_412 ;
} while ( V_126 & ~ V_413 );
F_184 ( V_9 ) ;
return V_35 ;
}
static void F_193 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( F_187 ( V_9 ) ) {
F_2 ( V_366 , 0 ) ;
F_2 ( V_142 , F_15 ( V_142 ) ) ;
}
F_41 ( V_359 , 0xffff ) ;
F_68 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_15 ( F_6 ( V_5 ) ) ) ;
}
F_2 ( V_408 , 0xffffffff ) ;
F_2 ( V_294 , 0x0 ) ;
F_2 ( V_319 , F_15 ( V_319 ) ) ;
}
static void F_194 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_86 ( & V_1 -> V_131 , 0 ) ;
F_2 ( V_366 , 0 ) ;
F_2 ( V_142 , F_15 ( V_142 ) ) ;
F_2 ( V_359 , 0xeffe ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_408 , 0xffffffff ) ;
F_2 ( V_294 , 0x0 ) ;
F_3 ( V_294 ) ;
}
static int F_195 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_395 ;
T_2 V_394 ;
T_2 V_429 ;
V_1 -> V_3 = ~ ( V_414 |
V_140 |
V_399 |
V_400 |
V_409 |
V_410 |
V_320 ) ;
V_394 = ~ V_1 -> V_3 ;
V_394 |= V_411 ;
if ( F_141 ( V_9 ) )
V_394 |= V_430 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
if ( F_141 ( V_9 ) ) {
V_429 = ~ ( V_311 |
V_304 |
V_305 |
V_314 ) ;
} else {
V_429 = ~ ( V_313 |
V_314 ) ;
}
F_2 ( V_318 , V_429 ) ;
F_2 ( V_408 , V_1 -> V_3 ) ;
F_2 ( V_294 , V_394 ) ;
F_3 ( V_294 ) ;
V_395 = 0 ;
if ( V_1 -> V_143 & V_415 )
V_395 |= V_416 ;
if ( V_1 -> V_143 & V_417 )
V_395 |= V_418 ;
if ( V_1 -> V_143 & V_419 )
V_395 |= V_420 ;
if ( F_141 ( V_9 ) ) {
if ( V_1 -> V_143 & V_431 )
V_395 |= V_422 ;
if ( V_1 -> V_143 & V_432 )
V_395 |= V_424 ;
} else {
if ( V_1 -> V_143 & V_433 )
V_395 |= V_422 ;
if ( V_1 -> V_143 & V_434 )
V_395 |= V_424 ;
}
if ( V_1 -> V_143 & V_425 ) {
V_395 |= V_426 ;
if ( F_141 ( V_9 ) )
V_395 |= V_435 ;
V_395 |= V_427 ;
}
F_2 ( V_366 , V_395 ) ;
F_189 ( V_9 ) ;
return 0 ;
}
static T_5 F_196 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_125 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_126 , V_412 ;
T_2 V_128 [ V_129 ] ;
unsigned long V_11 ;
int V_131 ;
int V_35 = V_127 , V_5 ;
F_67 ( & V_1 -> V_131 ) ;
V_126 = F_15 ( V_319 ) ;
for (; ; ) {
bool V_130 = false ;
V_131 = V_126 != 0 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_126 & V_320 )
F_64 ( V_9 , false ) ;
F_68 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_128 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_128 [ V_5 ] & 0x8000ffff ) {
if ( V_128 [ V_5 ] & V_137 )
F_18 ( L_13 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_128 [ V_5 ] ) ;
V_131 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_131 )
break;
V_35 = V_136 ;
if ( V_126 & V_140 ) {
T_2 V_141 = F_15 ( V_142 ) ;
F_18 ( L_14 ,
V_141 ) ;
if ( V_141 & V_1 -> V_143 )
F_62 ( V_1 -> V_113 ,
& V_1 -> V_54 ) ;
F_2 ( V_142 , V_141 ) ;
F_15 ( V_142 ) ;
}
F_2 ( V_319 , V_126 ) ;
V_412 = F_15 ( V_319 ) ;
if ( V_126 & V_411 )
F_43 ( V_9 , & V_1 -> V_76 [ V_117 ] ) ;
if ( V_126 & V_430 )
F_43 ( V_9 , & V_1 -> V_76 [ V_119 ] ) ;
if ( V_126 & V_409 )
F_70 ( V_9 , 0 ) ;
if ( V_126 & V_410 )
F_70 ( V_9 , 1 ) ;
F_68 (pipe) {
if ( V_128 [ V_5 ] & V_436 &&
F_69 ( V_9 , V_5 ) ) {
F_143 ( V_9 , V_5 ) ;
F_71 ( V_9 , V_5 ) ;
}
if ( V_128 [ V_5 ] & V_144 )
V_130 = true ;
}
if ( V_130 || ( V_126 & V_414 ) )
F_192 ( V_9 ) ;
V_126 = V_412 ;
}
F_184 ( V_9 ) ;
return V_35 ;
}
static void F_197 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_2 ( V_366 , 0 ) ;
F_2 ( V_142 , F_15 ( V_142 ) ) ;
F_2 ( V_359 , 0xffffffff ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_408 , 0xffffffff ) ;
F_2 ( V_294 , 0x0 ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) ,
F_15 ( F_6 ( V_5 ) ) & 0x8000ffff ) ;
F_2 ( V_319 , F_15 ( V_319 ) ) ;
}
void F_198 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
F_199 ( & V_1 -> V_54 , F_34 ) ;
F_199 ( & V_1 -> V_190 , F_83 ) ;
F_199 ( & V_1 -> V_85 , F_48 ) ;
F_199 ( & V_1 -> V_93 , F_52 ) ;
V_9 -> V_437 -> V_438 = F_17 ;
V_9 -> V_439 = 0xffffff ;
if ( F_141 ( V_9 ) || F_12 ( V_9 ) -> V_15 >= 5 ) {
V_9 -> V_439 = 0xffffffff ;
V_9 -> V_437 -> V_438 = F_22 ;
}
if ( F_200 ( V_9 , V_440 ) )
V_9 -> V_437 -> V_441 = F_29 ;
else
V_9 -> V_437 -> V_441 = NULL ;
V_9 -> V_437 -> V_442 = F_24 ;
if ( F_9 ( V_9 ) ) {
V_9 -> V_437 -> V_443 = F_66 ;
V_9 -> V_437 -> V_444 = F_168 ;
V_9 -> V_437 -> V_445 = F_174 ;
V_9 -> V_437 -> V_446 = F_178 ;
V_9 -> V_437 -> V_447 = F_152 ;
V_9 -> V_437 -> V_448 = F_157 ;
} else if ( F_61 ( V_9 ) ) {
V_9 -> V_437 -> V_443 = F_75 ;
V_9 -> V_437 -> V_444 = F_167 ;
V_9 -> V_437 -> V_445 = F_173 ;
V_9 -> V_437 -> V_446 = F_179 ;
V_9 -> V_437 -> V_447 = F_151 ;
V_9 -> V_437 -> V_448 = F_156 ;
} else if ( F_201 ( V_9 ) ) {
V_9 -> V_437 -> V_443 = F_75 ;
V_9 -> V_437 -> V_444 = F_167 ;
V_9 -> V_437 -> V_445 = F_173 ;
V_9 -> V_437 -> V_446 = F_179 ;
V_9 -> V_437 -> V_447 = F_151 ;
V_9 -> V_437 -> V_448 = F_156 ;
} else if ( F_11 ( V_9 ) ) {
V_9 -> V_437 -> V_443 = F_79 ;
V_9 -> V_437 -> V_444 = F_167 ;
V_9 -> V_437 -> V_445 = F_171 ;
V_9 -> V_437 -> V_446 = F_179 ;
V_9 -> V_437 -> V_447 = F_150 ;
V_9 -> V_437 -> V_448 = F_155 ;
} else {
if ( F_12 ( V_9 ) -> V_15 == 2 ) {
V_9 -> V_437 -> V_444 = F_180 ;
V_9 -> V_437 -> V_445 = F_182 ;
V_9 -> V_437 -> V_443 = F_183 ;
V_9 -> V_437 -> V_446 = F_185 ;
} else if ( F_12 ( V_9 ) -> V_15 == 3 ) {
V_9 -> V_437 -> V_444 = F_186 ;
V_9 -> V_437 -> V_445 = F_188 ;
V_9 -> V_437 -> V_446 = F_193 ;
V_9 -> V_437 -> V_443 = F_190 ;
} else {
V_9 -> V_437 -> V_444 = F_194 ;
V_9 -> V_437 -> V_445 = F_195 ;
V_9 -> V_437 -> V_446 = F_197 ;
V_9 -> V_437 -> V_443 = F_196 ;
}
V_9 -> V_437 -> V_447 = F_148 ;
V_9 -> V_437 -> V_448 = F_153 ;
}
}
