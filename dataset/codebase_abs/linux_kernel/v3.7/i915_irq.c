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
T_3 V_65 ;
unsigned long V_44 ;
F_10 ( & V_66 , V_44 ) ;
F_41 ( V_67 , F_15 ( V_67 ) ) ;
V_65 = V_1 -> V_68 . V_69 ;
F_41 ( V_67 , V_70 ) ;
V_61 = F_15 ( V_71 ) ;
V_62 = F_15 ( V_72 ) ;
V_63 = F_15 ( V_73 ) ;
V_64 = F_15 ( V_74 ) ;
if ( V_61 > V_63 ) {
if ( V_1 -> V_68 . V_69 != V_1 -> V_68 . V_75 )
V_65 = V_1 -> V_68 . V_69 - 1 ;
if ( V_65 < V_1 -> V_68 . V_75 )
V_65 = V_1 -> V_68 . V_75 ;
} else if ( V_62 < V_64 ) {
if ( V_1 -> V_68 . V_69 != V_1 -> V_68 . V_76 )
V_65 = V_1 -> V_68 . V_69 + 1 ;
if ( V_65 > V_1 -> V_68 . V_76 )
V_65 = V_1 -> V_68 . V_76 ;
}
if ( F_42 ( V_9 , V_65 ) )
V_1 -> V_68 . V_69 = V_65 ;
F_13 ( & V_66 , V_44 ) ;
return;
}
static void F_43 ( struct V_8 * V_9 ,
struct V_77 * V_78 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
if ( V_78 -> V_79 == NULL )
return;
F_44 ( V_78 , V_78 -> V_80 ( V_78 , false ) ) ;
F_45 ( & V_78 -> V_81 ) ;
if ( V_82 ) {
V_1 -> V_83 = 0 ;
F_46 ( & V_1 -> V_84 ,
V_85 +
F_47 ( V_86 ) ) ;
}
}
static void F_48 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_87 . V_53 ) ;
T_2 V_88 , V_89 ;
T_3 V_65 ;
F_49 ( & V_1 -> V_87 . V_90 ) ;
V_88 = V_1 -> V_87 . V_88 ;
V_1 -> V_87 . V_88 = 0 ;
V_89 = F_15 ( V_91 ) ;
F_2 ( V_91 , 0 ) ;
F_50 ( & V_1 -> V_87 . V_90 ) ;
if ( ( V_88 & V_92 ) == 0 )
return;
F_36 ( & V_1 -> V_9 -> V_93 ) ;
if ( V_88 & V_94 )
V_65 = V_1 -> V_87 . V_69 + 1 ;
else
V_65 = V_1 -> V_87 . V_69 - 1 ;
if ( ! ( V_65 > V_1 -> V_87 . V_75 ||
V_65 < V_1 -> V_87 . V_76 ) ) {
F_51 ( V_1 -> V_9 , V_65 ) ;
}
F_38 ( & V_1 -> V_9 -> V_93 ) ;
}
static void F_52 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_95 ) ;
T_2 V_96 , V_97 , V_98 , V_99 ;
char * V_100 [ 5 ] ;
T_4 V_101 ;
unsigned long V_44 ;
F_36 ( & V_1 -> V_9 -> V_93 ) ;
V_101 = F_15 ( V_102 ) ;
F_2 ( V_102 , V_101 & ~ V_103 ) ;
F_3 ( V_102 ) ;
V_96 = F_15 ( V_104 ) ;
V_97 = F_53 ( V_96 ) ;
V_98 = F_54 ( V_96 ) ;
V_99 = F_55 ( V_96 ) ;
F_2 ( V_104 , V_105 |
V_106 ) ;
F_3 ( V_104 ) ;
F_2 ( V_102 , V_101 ) ;
F_10 ( & V_1 -> V_12 , V_44 ) ;
V_1 -> V_107 &= ~ V_108 ;
F_2 ( V_109 , V_1 -> V_107 ) ;
F_13 ( & V_1 -> V_12 , V_44 ) ;
F_38 ( & V_1 -> V_9 -> V_93 ) ;
V_100 [ 0 ] = L_7 ;
V_100 [ 1 ] = F_56 ( V_110 , L_8 , V_97 ) ;
V_100 [ 2 ] = F_56 ( V_110 , L_9 , V_98 ) ;
V_100 [ 3 ] = F_56 ( V_110 , L_10 , V_99 ) ;
V_100 [ 4 ] = NULL ;
F_57 ( & V_1 -> V_9 -> V_111 -> V_112 . V_113 ,
V_114 , V_100 ) ;
F_58 ( L_11 ,
V_97 , V_98 , V_99 ) ;
F_59 ( V_100 [ 3 ] ) ;
F_59 ( V_100 [ 2 ] ) ;
F_59 ( V_100 [ 1 ] ) ;
}
static void F_60 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_44 ;
if ( ! F_61 ( V_9 ) )
return;
F_10 ( & V_1 -> V_12 , V_44 ) ;
V_1 -> V_107 |= V_108 ;
F_2 ( V_109 , V_1 -> V_107 ) ;
F_13 ( & V_1 -> V_12 , V_44 ) ;
F_62 ( V_1 -> V_115 , & V_1 -> V_95 ) ;
}
static void F_63 ( struct V_8 * V_9 ,
struct V_45 * V_1 ,
T_2 V_116 )
{
if ( V_116 & ( V_117 |
V_118 ) )
F_43 ( V_9 , & V_1 -> V_78 [ V_119 ] ) ;
if ( V_116 & V_120 )
F_43 ( V_9 , & V_1 -> V_78 [ V_121 ] ) ;
if ( V_116 & V_122 )
F_43 ( V_9 , & V_1 -> V_78 [ V_123 ] ) ;
if ( V_116 & ( V_124 |
V_125 |
V_126 ) ) {
F_30 ( L_12 , V_116 ) ;
F_64 ( V_9 , false ) ;
}
if ( V_116 & V_108 )
F_60 ( V_9 ) ;
}
static void F_65 ( struct V_45 * V_1 ,
T_2 V_88 )
{
unsigned long V_44 ;
F_10 ( & V_1 -> V_87 . V_90 , V_44 ) ;
V_1 -> V_87 . V_88 |= V_88 ;
F_2 ( V_91 , V_1 -> V_87 . V_88 ) ;
F_3 ( V_91 ) ;
F_13 ( & V_1 -> V_87 . V_90 , V_44 ) ;
F_62 ( V_1 -> V_115 , & V_1 -> V_87 . V_53 ) ;
}
static T_5 F_66 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_127 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_128 , V_116 , V_88 ;
T_5 V_35 = V_129 ;
unsigned long V_11 ;
int V_5 ;
T_2 V_130 [ V_131 ] ;
bool V_132 ;
F_67 ( & V_1 -> V_133 ) ;
while ( true ) {
V_128 = F_15 ( V_134 ) ;
V_116 = F_15 ( V_135 ) ;
V_88 = F_15 ( V_136 ) ;
if ( V_116 == 0 && V_88 == 0 && V_128 == 0 )
goto V_137;
V_35 = V_138 ;
F_63 ( V_9 , V_1 , V_116 ) ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_68 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_130 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_130 [ V_5 ] & 0x8000ffff ) {
if ( V_130 [ V_5 ] & V_139 )
F_18 ( L_13 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_130 [ V_5 ] ) ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
F_68 (pipe) {
if ( V_130 [ V_5 ] & V_140 )
F_69 ( V_9 , V_5 ) ;
if ( V_130 [ V_5 ] & V_141 ) {
F_70 ( V_9 , V_5 ) ;
F_71 ( V_9 , V_5 ) ;
}
}
if ( V_128 & V_142 ) {
T_2 V_143 = F_15 ( V_144 ) ;
F_18 ( L_14 ,
V_143 ) ;
if ( V_143 & V_1 -> V_145 )
F_62 ( V_1 -> V_115 ,
& V_1 -> V_54 ) ;
F_2 ( V_144 , V_143 ) ;
F_15 ( V_144 ) ;
}
if ( V_130 [ V_5 ] & V_146 )
V_132 = true ;
if ( V_88 & V_92 )
F_65 ( V_1 , V_88 ) ;
F_2 ( V_135 , V_116 ) ;
F_2 ( V_136 , V_88 ) ;
F_2 ( V_134 , V_128 ) ;
}
V_137:
return V_35 ;
}
static void F_72 ( struct V_8 * V_9 , T_2 V_147 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_147 & V_148 )
F_18 ( L_15 ,
( V_147 & V_148 ) >>
V_149 ) ;
if ( V_147 & V_150 )
F_18 ( L_16 ) ;
if ( V_147 & V_151 )
F_18 ( L_17 ) ;
if ( V_147 & V_152 )
F_18 ( L_18 ) ;
if ( V_147 & V_153 )
F_30 ( L_19 ) ;
if ( V_147 & V_154 )
F_68 (pipe)
F_18 ( L_20 ,
F_19 ( V_5 ) ,
F_15 ( F_73 ( V_5 ) ) ) ;
if ( V_147 & ( V_155 | V_156 ) )
F_18 ( L_21 ) ;
if ( V_147 & ( V_157 | V_158 ) )
F_18 ( L_22 ) ;
if ( V_147 & V_159 )
F_18 ( L_23 ) ;
if ( V_147 & V_160 )
F_18 ( L_24 ) ;
}
static void F_74 ( struct V_8 * V_9 , T_2 V_147 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_147 & V_161 )
F_18 ( L_15 ,
( V_147 & V_161 ) >>
V_162 ) ;
if ( V_147 & V_163 )
F_18 ( L_25 ) ;
if ( V_147 & V_164 )
F_18 ( L_16 ) ;
if ( V_147 & V_165 )
F_18 ( L_26 ) ;
if ( V_147 & V_166 )
F_18 ( L_27 ) ;
if ( V_147 & V_167 )
F_68 (pipe)
F_18 ( L_20 ,
F_19 ( V_5 ) ,
F_15 ( F_73 ( V_5 ) ) ) ;
}
static T_5 F_75 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_127 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_168 , V_116 , V_169 , V_88 ;
T_5 V_35 = V_129 ;
int V_170 ;
F_67 ( & V_1 -> V_133 ) ;
V_169 = F_15 ( V_171 ) ;
F_2 ( V_171 , V_169 & ~ V_172 ) ;
V_116 = F_15 ( V_135 ) ;
if ( V_116 ) {
F_63 ( V_9 , V_1 , V_116 ) ;
F_2 ( V_135 , V_116 ) ;
V_35 = V_138 ;
}
V_168 = F_15 ( V_173 ) ;
if ( V_168 ) {
if ( V_168 & V_174 )
F_76 ( V_9 ) ;
for ( V_170 = 0 ; V_170 < 3 ; V_170 ++ ) {
if ( V_168 & ( V_175 << ( 5 * V_170 ) ) )
F_69 ( V_9 , V_170 ) ;
if ( V_168 & ( V_176 << ( 5 * V_170 ) ) ) {
F_70 ( V_9 , V_170 ) ;
F_77 ( V_9 , V_170 ) ;
}
}
if ( V_168 & V_177 ) {
T_2 V_147 = F_15 ( V_178 ) ;
if ( V_147 & V_179 )
F_62 ( V_1 -> V_115 , & V_1 -> V_54 ) ;
F_74 ( V_9 , V_147 ) ;
F_2 ( V_178 , V_147 ) ;
}
F_2 ( V_173 , V_168 ) ;
V_35 = V_138 ;
}
V_88 = F_15 ( V_136 ) ;
if ( V_88 ) {
if ( V_88 & V_92 )
F_65 ( V_1 , V_88 ) ;
F_2 ( V_136 , V_88 ) ;
V_35 = V_138 ;
}
F_2 ( V_171 , V_169 ) ;
F_3 ( V_171 ) ;
return V_35 ;
}
static void F_78 ( struct V_8 * V_9 ,
struct V_45 * V_1 ,
T_2 V_116 )
{
if ( V_116 & ( V_180 | V_181 ) )
F_43 ( V_9 , & V_1 -> V_78 [ V_119 ] ) ;
if ( V_116 & V_182 )
F_43 ( V_9 , & V_1 -> V_78 [ V_121 ] ) ;
}
static T_5 F_79 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_127 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_35 = V_129 ;
T_2 V_168 , V_116 , V_169 , V_147 , V_88 ;
T_2 V_183 ;
F_67 ( & V_1 -> V_133 ) ;
V_169 = F_15 ( V_171 ) ;
F_2 ( V_171 , V_169 & ~ V_172 ) ;
F_3 ( V_171 ) ;
V_168 = F_15 ( V_173 ) ;
V_116 = F_15 ( V_135 ) ;
V_147 = F_15 ( V_178 ) ;
V_88 = F_15 ( V_136 ) ;
if ( V_168 == 0 && V_116 == 0 && V_147 == 0 &&
( ! F_80 ( V_9 ) || V_88 == 0 ) )
goto V_184;
if ( F_81 ( V_9 ) )
V_183 = V_179 ;
else
V_183 = V_185 ;
V_35 = V_138 ;
if ( F_82 ( V_9 ) )
F_78 ( V_9 , V_1 , V_116 ) ;
else
F_63 ( V_9 , V_1 , V_116 ) ;
if ( V_168 & V_13 )
F_76 ( V_9 ) ;
if ( V_168 & V_186 )
F_69 ( V_9 , 0 ) ;
if ( V_168 & V_187 )
F_69 ( V_9 , 1 ) ;
if ( V_168 & V_188 ) {
F_70 ( V_9 , 0 ) ;
F_77 ( V_9 , 0 ) ;
}
if ( V_168 & V_189 ) {
F_70 ( V_9 , 1 ) ;
F_77 ( V_9 , 1 ) ;
}
if ( V_168 & V_190 ) {
if ( V_147 & V_183 )
F_62 ( V_1 -> V_115 , & V_1 -> V_54 ) ;
if ( F_81 ( V_9 ) )
F_74 ( V_9 , V_147 ) ;
else
F_72 ( V_9 , V_147 ) ;
}
if ( F_82 ( V_9 ) && V_168 & V_191 )
F_40 ( V_9 ) ;
if ( F_80 ( V_9 ) && V_88 & V_92 )
F_65 ( V_1 , V_88 ) ;
F_2 ( V_178 , V_147 ) ;
F_2 ( V_135 , V_116 ) ;
F_2 ( V_173 , V_168 ) ;
F_2 ( V_136 , V_88 ) ;
V_184:
F_2 ( V_171 , V_169 ) ;
F_3 ( V_171 ) ;
return V_35 ;
}
static void F_83 ( struct V_52 * V_53 )
{
T_1 * V_1 = F_35 ( V_53 , T_1 ,
V_192 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
char * V_193 [] = { L_28 , NULL } ;
char * V_194 [] = { L_29 , NULL } ;
char * V_195 [] = { L_30 , NULL } ;
F_57 ( & V_9 -> V_111 -> V_112 . V_113 , V_114 , V_193 ) ;
if ( F_84 ( & V_1 -> V_196 . V_197 ) ) {
F_18 ( L_31 ) ;
F_57 ( & V_9 -> V_111 -> V_112 . V_113 , V_114 , V_194 ) ;
if ( ! F_85 ( V_9 ) ) {
F_86 ( & V_1 -> V_196 . V_197 , 0 ) ;
F_57 ( & V_9 -> V_111 -> V_112 . V_113 , V_114 , V_195 ) ;
}
F_87 ( & V_1 -> V_198 ) ;
}
}
static void F_88 ( struct V_8 * V_9 ,
T_4 * V_199 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
memset ( V_199 , 0 , sizeof( * V_199 ) * V_200 ) ;
switch( F_12 ( V_9 ) -> V_15 ) {
case 2 :
case 3 :
V_199 [ 0 ] = F_15 ( V_201 ) ;
break;
case 4 :
case 5 :
case 6 :
V_199 [ 0 ] = F_15 ( V_202 ) ;
V_199 [ 1 ] = F_15 ( V_203 ) ;
break;
default:
F_89 ( 1 , L_32 ) ;
case 7 :
V_199 [ 0 ] = F_15 ( V_204 ) ;
V_199 [ 1 ] = F_15 ( V_205 ) ;
V_199 [ 2 ] = F_15 ( V_206 ) ;
V_199 [ 3 ] = F_15 ( V_207 ) ;
break;
}
}
static struct V_208 *
F_90 ( struct V_45 * V_1 ,
struct V_209 * V_210 )
{
struct V_208 * V_211 ;
int V_170 , V_212 ;
T_2 V_213 ;
if ( V_210 == NULL || V_210 -> V_214 == NULL )
return NULL ;
V_212 = V_210 -> V_215 . V_216 / V_217 ;
V_211 = F_91 ( sizeof( * V_211 ) + V_212 * sizeof( T_2 * ) , V_218 ) ;
if ( V_211 == NULL )
return NULL ;
V_213 = V_210 -> V_219 ;
for ( V_170 = 0 ; V_170 < V_212 ; V_170 ++ ) {
unsigned long V_44 ;
void * V_220 ;
V_220 = F_91 ( V_217 , V_218 ) ;
if ( V_220 == NULL )
goto V_221;
F_92 ( V_44 ) ;
if ( V_213 < V_1 -> V_196 . V_222 &&
V_210 -> V_223 ) {
void T_7 * V_224 ;
V_224 = F_93 ( V_1 -> V_196 . V_225 ,
V_213 ) ;
F_94 ( V_220 , V_224 , V_217 ) ;
F_95 ( V_224 ) ;
} else {
struct V_226 * V_226 ;
void * V_224 ;
V_226 = F_96 ( V_210 , V_170 ) ;
F_97 ( & V_226 , 1 ) ;
V_224 = F_98 ( V_226 ) ;
memcpy ( V_220 , V_224 , V_217 ) ;
F_99 ( V_224 ) ;
F_97 ( & V_226 , 1 ) ;
}
F_100 ( V_44 ) ;
V_211 -> V_214 [ V_170 ] = V_220 ;
V_213 += V_217 ;
}
V_211 -> V_227 = V_212 ;
V_211 -> V_219 = V_210 -> V_219 ;
return V_211 ;
V_221:
while ( V_170 -- )
F_59 ( V_211 -> V_214 [ V_170 ] ) ;
F_59 ( V_211 ) ;
return NULL ;
}
static void
F_101 ( struct V_208 * V_79 )
{
int V_226 ;
if ( V_79 == NULL )
return;
for ( V_226 = 0 ; V_226 < V_79 -> V_227 ; V_226 ++ )
F_59 ( V_79 -> V_214 [ V_226 ] ) ;
F_59 ( V_79 ) ;
}
void
F_102 ( struct V_228 * V_229 )
{
struct V_230 * error = F_35 ( V_229 ,
F_103 ( * error ) , V_231 ) ;
int V_170 ;
for ( V_170 = 0 ; V_170 < F_104 ( error -> V_78 ) ; V_170 ++ ) {
F_101 ( error -> V_78 [ V_170 ] . V_232 ) ;
F_101 ( error -> V_78 [ V_170 ] . V_233 ) ;
F_59 ( error -> V_78 [ V_170 ] . V_234 ) ;
}
F_59 ( error -> V_235 ) ;
F_59 ( error -> V_236 ) ;
F_59 ( error ) ;
}
static void F_105 ( struct V_237 * V_238 ,
struct V_209 * V_79 )
{
V_238 -> V_216 = V_79 -> V_215 . V_216 ;
V_238 -> V_239 = V_79 -> V_215 . V_239 ;
V_238 -> V_240 = V_79 -> V_241 ;
V_238 -> V_242 = V_79 -> V_243 ;
V_238 -> V_219 = V_79 -> V_219 ;
V_238 -> V_244 = V_79 -> V_215 . V_244 ;
V_238 -> V_245 = V_79 -> V_215 . V_245 ;
V_238 -> V_246 = V_79 -> V_246 ;
V_238 -> V_247 = 0 ;
if ( V_79 -> V_248 > 0 )
V_238 -> V_247 = 1 ;
if ( V_79 -> V_249 > 0 )
V_238 -> V_247 = - 1 ;
V_238 -> V_250 = V_79 -> V_251 ;
V_238 -> V_252 = V_79 -> V_252 ;
V_238 -> V_253 = V_79 -> V_254 != V_255 ;
V_238 -> V_78 = V_79 -> V_78 ? V_79 -> V_78 -> V_256 : - 1 ;
V_238 -> V_257 = V_79 -> V_257 ;
}
static T_2 F_106 ( struct V_237 * V_238 ,
int V_212 , struct V_258 * V_259 )
{
struct V_209 * V_79 ;
int V_170 = 0 ;
F_37 (obj, head, mm_list) {
F_105 ( V_238 ++ , V_79 ) ;
if ( ++ V_170 == V_212 )
break;
}
return V_170 ;
}
static T_2 F_107 ( struct V_237 * V_238 ,
int V_212 , struct V_258 * V_259 )
{
struct V_209 * V_79 ;
int V_170 = 0 ;
F_37 (obj, head, gtt_list) {
if ( V_79 -> V_248 == 0 )
continue;
F_105 ( V_238 ++ , V_79 ) ;
if ( ++ V_170 == V_212 )
break;
}
return V_170 ;
}
static void F_108 ( struct V_8 * V_9 ,
struct V_230 * error )
{
struct V_45 * V_1 = V_9 -> V_10 ;
int V_170 ;
switch ( F_12 ( V_9 ) -> V_15 ) {
case 7 :
case 6 :
for ( V_170 = 0 ; V_170 < 16 ; V_170 ++ )
error -> V_260 [ V_170 ] = F_109 ( V_261 + ( V_170 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_170 = 0 ; V_170 < 16 ; V_170 ++ )
error -> V_260 [ V_170 ] = F_109 ( V_262 + ( V_170 * 8 ) ) ;
break;
case 3 :
if ( F_110 ( V_9 ) || F_111 ( V_9 ) || F_112 ( V_9 ) )
for ( V_170 = 0 ; V_170 < 8 ; V_170 ++ )
error -> V_260 [ V_170 + 8 ] = F_15 ( V_263 + ( V_170 * 4 ) ) ;
case 2 :
for ( V_170 = 0 ; V_170 < 8 ; V_170 ++ )
error -> V_260 [ V_170 ] = F_15 ( V_264 + ( V_170 * 4 ) ) ;
break;
}
}
static struct V_208 *
F_113 ( struct V_45 * V_1 ,
struct V_77 * V_78 )
{
struct V_209 * V_79 ;
T_2 V_265 ;
if ( ! V_78 -> V_80 )
return NULL ;
V_265 = V_78 -> V_80 ( V_78 , false ) ;
F_37 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_79 -> V_78 != V_78 )
continue;
if ( F_114 ( V_265 , V_79 -> V_241 ) )
continue;
if ( ( V_79 -> V_215 . V_244 & V_266 ) == 0 )
continue;
return F_90 ( V_1 , V_79 ) ;
}
return NULL ;
}
static void F_115 ( struct V_8 * V_9 ,
struct V_230 * error ,
struct V_77 * V_78 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> V_267 [ V_78 -> V_256 ] = F_15 ( V_78 -> V_268 + 0x50 ) ;
error -> V_269 [ V_78 -> V_256 ] = F_15 ( F_116 ( V_78 ) ) ;
error -> V_270 [ V_78 -> V_256 ] [ 0 ]
= F_15 ( F_117 ( V_78 -> V_268 ) ) ;
error -> V_270 [ V_78 -> V_256 ] [ 1 ]
= F_15 ( F_118 ( V_78 -> V_268 ) ) ;
}
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
error -> V_271 [ V_78 -> V_256 ] = F_15 ( F_119 ( V_78 -> V_268 ) ) ;
error -> V_272 [ V_78 -> V_256 ] = F_15 ( F_120 ( V_78 -> V_268 ) ) ;
error -> V_273 [ V_78 -> V_256 ] = F_15 ( F_121 ( V_78 -> V_268 ) ) ;
error -> V_199 [ V_78 -> V_256 ] = F_15 ( F_122 ( V_78 -> V_268 ) ) ;
error -> V_274 [ V_78 -> V_256 ] = F_15 ( F_123 ( V_78 -> V_268 ) ) ;
if ( V_78 -> V_256 == V_119 )
error -> V_275 = F_109 ( V_276 ) ;
} else {
error -> V_271 [ V_78 -> V_256 ] = F_15 ( V_277 ) ;
error -> V_272 [ V_78 -> V_256 ] = F_15 ( V_278 ) ;
error -> V_273 [ V_78 -> V_256 ] = F_15 ( V_279 ) ;
error -> V_199 [ V_78 -> V_256 ] = F_15 ( V_201 ) ;
}
error -> V_280 [ V_78 -> V_256 ] = F_124 ( & V_78 -> V_81 ) ;
error -> V_281 [ V_78 -> V_256 ] = F_15 ( F_125 ( V_78 -> V_268 ) ) ;
error -> V_265 [ V_78 -> V_256 ] = V_78 -> V_80 ( V_78 , false ) ;
error -> V_282 [ V_78 -> V_256 ] = F_126 ( V_78 ) ;
error -> V_259 [ V_78 -> V_256 ] = F_127 ( V_78 ) ;
error -> V_283 [ V_78 -> V_256 ] = F_128 ( V_78 ) ;
error -> V_284 [ V_78 -> V_256 ] = V_78 -> V_259 ;
error -> V_285 [ V_78 -> V_256 ] = V_78 -> V_283 ;
}
static void F_129 ( struct V_8 * V_9 ,
struct V_230 * error )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_77 * V_78 ;
struct V_286 * V_287 ;
int V_170 , V_212 ;
F_130 (ring, dev_priv, i) {
F_115 ( V_9 , error , V_78 ) ;
error -> V_78 [ V_170 ] . V_232 =
F_113 ( V_1 , V_78 ) ;
error -> V_78 [ V_170 ] . V_233 =
F_90 ( V_1 , V_78 -> V_79 ) ;
V_212 = 0 ;
F_37 (request, &ring->request_list, list)
V_212 ++ ;
error -> V_78 [ V_170 ] . V_288 = V_212 ;
error -> V_78 [ V_170 ] . V_234 =
F_91 ( V_212 * sizeof( struct V_289 ) ,
V_218 ) ;
if ( error -> V_78 [ V_170 ] . V_234 == NULL ) {
error -> V_78 [ V_170 ] . V_288 = 0 ;
continue;
}
V_212 = 0 ;
F_37 (request, &ring->request_list, list) {
struct V_289 * V_290 ;
V_290 = & error -> V_78 [ V_170 ] . V_234 [ V_212 ++ ] ;
V_290 -> V_265 = V_287 -> V_265 ;
V_290 -> V_85 = V_287 -> V_291 ;
V_290 -> V_283 = V_287 -> V_283 ;
}
}
}
static void F_131 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_209 * V_79 ;
struct V_230 * error ;
unsigned long V_44 ;
int V_170 , V_5 ;
F_10 ( & V_1 -> V_292 , V_44 ) ;
error = V_1 -> V_293 ;
F_13 ( & V_1 -> V_292 , V_44 ) ;
if ( error )
return;
error = F_132 ( sizeof( * error ) , V_218 ) ;
if ( ! error ) {
F_18 ( L_33 ) ;
return;
}
F_133 ( L_34 ,
V_9 -> V_111 -> V_294 ) ;
F_134 ( & error -> V_231 ) ;
error -> V_295 = F_15 ( V_296 ) ;
error -> V_297 = F_15 ( V_298 ) ;
error -> V_299 = F_15 ( V_300 ) ;
if ( F_11 ( V_9 ) )
error -> V_301 = F_15 ( V_171 ) | F_15 ( V_302 ) ;
else if ( F_9 ( V_9 ) )
error -> V_301 = F_15 ( V_302 ) | F_15 ( V_303 ) ;
else if ( F_135 ( V_9 ) )
error -> V_301 = F_136 ( V_304 ) ;
else
error -> V_301 = F_15 ( V_304 ) ;
F_68 ( V_5 )
error -> V_6 [ V_5 ] = F_15 ( F_6 ( V_5 ) ) ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> error = F_15 ( V_305 ) ;
error -> V_306 = F_15 ( V_307 ) ;
}
if ( F_12 ( V_9 ) -> V_15 == 7 )
error -> V_308 = F_15 ( V_309 ) ;
F_88 ( V_9 , error -> V_310 ) ;
F_108 ( V_9 , error ) ;
F_129 ( V_9 , error ) ;
error -> V_235 = NULL ;
error -> V_311 = NULL ;
V_170 = 0 ;
F_37 (obj, &dev_priv->mm.active_list, mm_list)
V_170 ++ ;
error -> V_312 = V_170 ;
F_37 (obj, &dev_priv->mm.bound_list, gtt_list)
if ( V_79 -> V_248 )
V_170 ++ ;
error -> V_313 = V_170 - error -> V_312 ;
error -> V_235 = NULL ;
error -> V_311 = NULL ;
if ( V_170 ) {
error -> V_235 = F_91 ( sizeof( * error -> V_235 ) * V_170 ,
V_218 ) ;
if ( error -> V_235 )
error -> V_311 =
error -> V_235 + error -> V_312 ;
}
if ( error -> V_235 )
error -> V_312 =
F_106 ( error -> V_235 ,
error -> V_312 ,
& V_1 -> V_196 . V_314 ) ;
if ( error -> V_311 )
error -> V_313 =
F_107 ( error -> V_311 ,
error -> V_313 ,
& V_1 -> V_196 . V_315 ) ;
F_137 ( & error -> time ) ;
error -> V_236 = F_138 ( V_9 ) ;
error -> V_316 = F_139 ( V_9 ) ;
F_10 ( & V_1 -> V_292 , V_44 ) ;
if ( V_1 -> V_293 == NULL ) {
V_1 -> V_293 = error ;
error = NULL ;
}
F_13 ( & V_1 -> V_292 , V_44 ) ;
if ( error )
F_102 ( & error -> V_231 ) ;
}
void F_140 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_230 * error ;
unsigned long V_44 ;
F_10 ( & V_1 -> V_292 , V_44 ) ;
error = V_1 -> V_293 ;
V_1 -> V_293 = NULL ;
F_13 ( & V_1 -> V_292 , V_44 ) ;
if ( error )
F_141 ( & error -> V_231 , F_102 ) ;
}
static void F_142 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
T_4 V_199 [ V_200 ] ;
T_2 V_295 = F_15 ( V_296 ) ;
int V_5 , V_170 ;
if ( ! V_295 )
return;
F_143 ( L_35 , V_295 ) ;
F_88 ( V_9 , V_199 ) ;
if ( F_144 ( V_9 ) ) {
if ( V_295 & ( V_317 | V_318 ) ) {
T_2 V_272 = F_15 ( V_319 ) ;
F_143 ( L_36 , F_15 ( V_319 ) ) ;
F_143 ( L_37 , F_15 ( V_320 ) ) ;
for ( V_170 = 0 ; V_170 < F_104 ( V_199 ) ; V_170 ++ )
F_143 ( L_38 , V_170 , V_199 [ V_170 ] ) ;
F_143 ( L_39 , F_15 ( V_321 ) ) ;
F_143 ( L_40 , F_15 ( V_322 ) ) ;
F_2 ( V_319 , V_272 ) ;
F_3 ( V_319 ) ;
}
if ( V_295 & V_323 ) {
T_2 V_324 = F_15 ( V_298 ) ;
F_143 ( L_41 ) ;
F_143 ( L_42 , V_324 ) ;
F_2 ( V_298 , V_324 ) ;
F_3 ( V_298 ) ;
}
}
if ( ! F_135 ( V_9 ) ) {
if ( V_295 & V_325 ) {
T_2 V_324 = F_15 ( V_298 ) ;
F_143 ( L_41 ) ;
F_143 ( L_42 , V_324 ) ;
F_2 ( V_298 , V_324 ) ;
F_3 ( V_298 ) ;
}
}
if ( V_295 & V_326 ) {
F_143 ( L_43 ) ;
F_68 (pipe)
F_143 ( L_44 ,
F_19 ( V_5 ) , F_15 ( F_6 ( V_5 ) ) ) ;
}
if ( V_295 & V_327 ) {
F_143 ( L_45 ) ;
F_143 ( L_46 , F_15 ( V_328 ) ) ;
for ( V_170 = 0 ; V_170 < F_104 ( V_199 ) ; V_170 ++ )
F_143 ( L_38 , V_170 , V_199 [ V_170 ] ) ;
if ( F_12 ( V_9 ) -> V_15 < 4 ) {
T_2 V_272 = F_15 ( V_278 ) ;
F_143 ( L_36 , F_15 ( V_278 ) ) ;
F_143 ( L_37 , F_15 ( V_279 ) ) ;
F_143 ( L_40 , F_15 ( V_329 ) ) ;
F_2 ( V_278 , V_272 ) ;
F_3 ( V_278 ) ;
} else {
T_2 V_272 = F_15 ( V_319 ) ;
F_143 ( L_36 , F_15 ( V_319 ) ) ;
F_143 ( L_37 , F_15 ( V_320 ) ) ;
F_143 ( L_39 , F_15 ( V_321 ) ) ;
F_143 ( L_40 , F_15 ( V_322 ) ) ;
F_2 ( V_319 , V_272 ) ;
F_3 ( V_319 ) ;
}
}
F_2 ( V_296 , V_295 ) ;
F_3 ( V_296 ) ;
V_295 = F_15 ( V_296 ) ;
if ( V_295 ) {
F_30 ( L_47 , V_295 ) ;
F_2 ( V_330 , F_15 ( V_330 ) | V_295 ) ;
F_2 ( V_331 , V_332 ) ;
}
}
void F_64 ( struct V_8 * V_9 , bool V_197 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
struct V_77 * V_78 ;
int V_170 ;
F_131 ( V_9 ) ;
F_142 ( V_9 ) ;
if ( V_197 ) {
F_145 ( V_1 -> V_198 ) ;
F_86 ( & V_1 -> V_196 . V_197 , 1 ) ;
F_130 (ring, dev_priv, i)
F_45 ( & V_78 -> V_81 ) ;
}
F_62 ( V_1 -> V_115 , & V_1 -> V_192 ) ;
}
static void F_146 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = V_9 -> V_10 ;
struct V_46 * V_47 = V_1 -> V_333 [ V_5 ] ;
struct V_334 * V_334 = F_147 ( V_47 ) ;
struct V_209 * V_79 ;
struct V_335 * V_53 ;
unsigned long V_44 ;
bool V_336 ;
if ( V_334 == NULL )
return;
F_10 ( & V_9 -> V_337 , V_44 ) ;
V_53 = V_334 -> V_338 ;
if ( V_53 == NULL || V_53 -> V_339 || ! V_53 -> V_340 ) {
F_13 ( & V_9 -> V_337 , V_44 ) ;
return;
}
V_79 = V_53 -> V_341 ;
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
int V_342 = F_148 ( V_334 -> V_343 ) ;
V_336 = F_149 ( F_15 ( V_342 ) ) ==
V_79 -> V_219 ;
} else {
int V_344 = F_150 ( V_334 -> V_343 ) ;
V_336 = F_15 ( V_344 ) == ( V_79 -> V_219 +
V_47 -> V_345 * V_47 -> V_346 -> V_347 [ 0 ] +
V_47 -> V_348 * V_47 -> V_346 -> V_349 / 8 ) ;
}
F_13 ( & V_9 -> V_337 , V_44 ) ;
if ( V_336 ) {
F_18 ( L_48 ) ;
F_70 ( V_9 , V_334 -> V_343 ) ;
}
}
static int F_151 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 )
F_5 ( V_1 , V_5 ,
V_350 ) ;
else
F_5 ( V_1 , V_5 ,
V_351 ) ;
if ( V_1 -> V_352 -> V_15 == 3 )
F_2 ( V_328 , F_152 ( V_353 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_153 ( struct V_8 * V_9 , int V_5 )
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
static int F_154 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 ,
V_175 << ( 5 * V_5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_155 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_354 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_49 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
V_354 = F_15 ( V_355 ) ;
if ( V_5 == 0 )
V_354 &= ~ V_356 ;
else
V_354 &= ~ V_357 ;
F_2 ( V_355 , V_354 ) ;
F_5 ( V_1 , V_5 ,
V_350 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static void F_156 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_1 -> V_352 -> V_15 == 3 )
F_2 ( V_328 , F_157 ( V_353 ) ) ;
F_7 ( V_1 , V_5 ,
V_351 |
V_350 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_158 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 , ( V_5 == 0 ) ?
V_186 : V_187 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_159 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 ,
V_175 << ( V_5 * 5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_160 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_354 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_7 ( V_1 , V_5 ,
V_350 ) ;
V_354 = F_15 ( V_355 ) ;
if ( V_5 == 0 )
V_354 |= V_356 ;
else
V_354 |= V_357 ;
F_2 ( V_355 , V_354 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static T_2
F_161 ( struct V_77 * V_78 )
{
return F_162 ( V_78 -> V_358 . V_359 ,
struct V_286 , V_360 ) -> V_265 ;
}
static bool F_163 ( struct V_77 * V_78 , bool * V_238 )
{
if ( F_164 ( & V_78 -> V_358 ) ||
F_114 ( V_78 -> V_80 ( V_78 , false ) ,
F_161 ( V_78 ) ) ) {
if ( F_124 ( & V_78 -> V_81 ) ) {
F_30 ( L_49 ,
V_78 -> V_239 ) ;
F_45 ( & V_78 -> V_81 ) ;
* V_238 = true ;
}
return true ;
}
return false ;
}
static bool F_165 ( struct V_77 * V_78 )
{
struct V_8 * V_9 = V_78 -> V_9 ;
struct V_45 * V_1 = V_9 -> V_10 ;
T_2 V_361 = F_166 ( V_78 ) ;
if ( V_361 & V_362 ) {
F_30 ( L_50 ,
V_78 -> V_239 ) ;
F_167 ( V_78 , V_361 ) ;
return true ;
}
return false ;
}
static bool F_168 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
if ( V_1 -> V_83 ++ > 1 ) {
bool V_363 = true ;
F_30 ( L_51 ) ;
F_64 ( V_9 , true ) ;
if ( ! F_135 ( V_9 ) ) {
struct V_77 * V_78 ;
int V_170 ;
F_130 (ring, dev_priv, i)
V_363 &= ! F_165 ( V_78 ) ;
}
return V_363 ;
}
return false ;
}
void F_169 ( unsigned long V_364 )
{
struct V_8 * V_9 = (struct V_8 * ) V_364 ;
T_1 * V_1 = V_9 -> V_10 ;
T_4 V_282 [ V_365 ] , V_199 [ V_200 ] ;
struct V_77 * V_78 ;
bool V_238 = false , V_366 ;
int V_170 ;
if ( ! V_82 )
return;
memset ( V_282 , 0 , sizeof( V_282 ) ) ;
V_366 = true ;
F_130 (ring, dev_priv, i) {
V_366 &= F_163 ( V_78 , & V_238 ) ;
V_282 [ V_170 ] = F_126 ( V_78 ) ;
}
if ( V_366 ) {
if ( V_238 ) {
if ( F_168 ( V_9 ) )
return;
goto V_367;
}
V_1 -> V_83 = 0 ;
return;
}
F_88 ( V_9 , V_199 ) ;
if ( memcmp ( V_1 -> V_368 , V_282 , sizeof( V_282 ) ) == 0 &&
memcmp ( V_1 -> V_369 , V_199 , sizeof( V_199 ) ) == 0 ) {
if ( F_168 ( V_9 ) )
return;
} else {
V_1 -> V_83 = 0 ;
memcpy ( V_1 -> V_368 , V_282 , sizeof( V_282 ) ) ;
memcpy ( V_1 -> V_369 , V_199 , sizeof( V_199 ) ) ;
}
V_367:
F_46 ( & V_1 -> V_84 ,
V_85 + F_47 ( V_86 ) ) ;
}
static void F_170 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_86 ( & V_1 -> V_133 , 0 ) ;
F_2 ( V_370 , 0xeffe ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_171 , 0x0 ) ;
F_3 ( V_171 ) ;
F_2 ( V_109 , 0xffffffff ) ;
F_2 ( V_302 , 0x0 ) ;
F_3 ( V_302 ) ;
F_2 ( V_371 , 0xffffffff ) ;
F_2 ( V_372 , 0x0 ) ;
F_3 ( V_372 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_86 ( & V_1 -> V_133 , 0 ) ;
F_2 ( V_355 , 0 ) ;
F_2 ( F_172 ( V_373 ) , 0 ) ;
F_2 ( F_172 ( V_374 ) , 0 ) ;
F_2 ( F_172 ( V_375 ) , 0 ) ;
F_2 ( V_135 , F_15 ( V_135 ) ) ;
F_2 ( V_135 , F_15 ( V_135 ) ) ;
F_2 ( V_109 , 0xffffffff ) ;
F_2 ( V_302 , 0x0 ) ;
F_3 ( V_302 ) ;
F_2 ( V_376 , 0xff ) ;
F_2 ( V_377 , 0 ) ;
F_2 ( V_144 , F_15 ( V_144 ) ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_134 , 0xffffffff ) ;
F_2 ( V_355 , 0xffffffff ) ;
F_2 ( V_303 , 0x0 ) ;
F_3 ( V_303 ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_378 ;
V_378 = F_15 ( V_379 ) ;
V_378 &= ~ ( V_380 | V_381 | V_382 ) ;
V_378 |= V_383 | V_384 ;
V_378 |= V_385 | V_386 ;
V_378 |= V_387 | V_388 ;
F_2 ( V_379 , V_378 ) ;
}
static int F_174 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_389 = V_172 | V_13 | V_190 |
V_188 | V_189 ;
T_2 V_390 ;
T_2 V_183 ;
V_1 -> V_3 = ~ V_389 ;
F_2 ( V_173 , F_15 ( V_173 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_171 , V_389 | V_186 | V_187 ) ;
F_3 ( V_171 ) ;
V_1 -> V_107 = ~ 0 ;
F_2 ( V_135 , F_15 ( V_135 ) ) ;
F_2 ( V_109 , V_1 -> V_107 ) ;
if ( F_80 ( V_9 ) )
V_390 =
V_180 |
V_120 |
V_122 ;
else
V_390 =
V_180 |
V_181 |
V_182 ;
F_2 ( V_302 , V_390 ) ;
F_3 ( V_302 ) ;
if ( F_81 ( V_9 ) ) {
V_183 = ( V_391 |
V_392 |
V_393 |
V_394 ) ;
} else {
V_183 = ( V_395 |
V_396 |
V_397 |
V_398 |
V_399 ) ;
}
V_1 -> V_400 = ~ V_183 ;
F_2 ( V_178 , F_15 ( V_178 ) ) ;
F_2 ( V_371 , V_1 -> V_400 ) ;
F_2 ( V_372 , V_183 ) ;
F_3 ( V_372 ) ;
F_173 ( V_9 ) ;
if ( F_175 ( V_9 ) ) {
F_2 ( V_173 , V_191 ) ;
F_2 ( V_171 , F_15 ( V_171 ) | V_191 ) ;
F_1 ( V_1 , V_191 ) ;
}
return 0 ;
}
static int F_176 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_389 =
V_172 | V_174 | V_177 |
V_401 |
V_402 |
V_176 ;
T_2 V_390 ;
T_2 V_183 ;
V_1 -> V_3 = ~ V_389 ;
F_2 ( V_173 , F_15 ( V_173 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_171 ,
V_389 |
V_403 |
V_404 |
V_175 ) ;
F_3 ( V_171 ) ;
V_1 -> V_107 = ~ V_108 ;
F_2 ( V_135 , F_15 ( V_135 ) ) ;
F_2 ( V_109 , V_1 -> V_107 ) ;
V_390 = V_180 | V_120 |
V_122 | V_108 ;
F_2 ( V_302 , V_390 ) ;
F_3 ( V_302 ) ;
V_183 = ( V_391 |
V_392 |
V_393 |
V_394 ) ;
V_1 -> V_400 = ~ V_183 ;
F_2 ( V_178 , F_15 ( V_178 ) ) ;
F_2 ( V_371 , V_1 -> V_400 ) ;
F_2 ( V_372 , V_183 ) ;
F_3 ( V_372 ) ;
F_173 ( V_9 ) ;
return 0 ;
}
static int F_177 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_405 ;
T_2 V_406 = F_15 ( V_377 ) ;
T_2 V_407 = V_408 ;
T_8 V_409 ;
V_405 = V_142 ;
V_405 |= V_410 |
V_356 |
V_411 |
V_357 ;
V_1 -> V_3 = ( ~ V_405 ) |
V_356 |
V_357 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_178 ( V_1 -> V_9 -> V_412 , 0x94 , 0xfee00000 ) ;
F_179 ( V_9 -> V_412 , 0x98 , & V_409 ) ;
V_409 &= 0xff ;
V_409 |= ( 1 << 14 ) ;
F_180 ( V_1 -> V_9 -> V_412 , 0x98 , V_409 ) ;
F_2 ( V_355 , V_1 -> V_3 ) ;
F_2 ( V_303 , V_405 ) ;
F_2 ( V_134 , 0xffffffff ) ;
F_2 ( F_6 ( 0 ) , 0xffff ) ;
F_2 ( F_6 ( 1 ) , 0xffff ) ;
F_3 ( V_303 ) ;
F_5 ( V_1 , 0 , V_407 ) ;
F_5 ( V_1 , 1 , V_407 ) ;
F_2 ( V_134 , 0xffffffff ) ;
F_2 ( V_134 , 0xffffffff ) ;
V_1 -> V_107 = ~ 0 ;
F_2 ( V_135 , F_15 ( V_135 ) ) ;
F_2 ( V_135 , F_15 ( V_135 ) ) ;
F_2 ( V_109 , V_1 -> V_107 ) ;
F_2 ( V_302 , V_413 |
V_124 |
V_414 |
V_415 |
V_125 |
V_108 |
V_181 |
V_126 |
V_416 |
V_180 ) ;
F_3 ( V_302 ) ;
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
F_2 ( V_417 , V_418 ) ;
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
F_2 ( V_377 , V_406 ) ;
return 0 ;
}
static void F_181 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_370 , 0xffffffff ) ;
F_2 ( V_377 , 0 ) ;
F_2 ( V_144 , F_15 ( V_144 ) ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_134 , 0xffffffff ) ;
F_2 ( V_355 , 0xffffffff ) ;
F_2 ( V_303 , 0x0 ) ;
F_3 ( V_303 ) ;
}
static void F_182 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
if ( ! V_1 )
return;
F_2 ( V_370 , 0xffffffff ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_171 , 0x0 ) ;
F_2 ( V_173 , F_15 ( V_173 ) ) ;
F_2 ( V_109 , 0xffffffff ) ;
F_2 ( V_302 , 0x0 ) ;
F_2 ( V_135 , F_15 ( V_135 ) ) ;
F_2 ( V_371 , 0xffffffff ) ;
F_2 ( V_372 , 0x0 ) ;
F_2 ( V_178 , F_15 ( V_178 ) ) ;
}
static void F_183 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_86 ( & V_1 -> V_133 , 0 ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_41 ( V_419 , 0xffff ) ;
F_41 ( V_304 , 0x0 ) ;
F_184 ( V_304 ) ;
}
static int F_185 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_41 ( V_330 ,
~ ( V_325 | V_326 ) ) ;
V_1 -> V_3 =
~ ( V_410 |
V_411 |
V_420 |
V_421 |
V_332 ) ;
F_41 ( V_419 , V_1 -> V_3 ) ;
F_41 ( V_304 ,
V_410 |
V_411 |
V_332 |
V_422 ) ;
F_184 ( V_304 ) ;
return 0 ;
}
static T_5 F_186 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_127 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_8 V_128 , V_423 ;
T_2 V_130 [ 2 ] ;
unsigned long V_11 ;
int V_133 ;
int V_5 ;
T_8 V_424 =
V_420 |
V_421 ;
F_67 ( & V_1 -> V_133 ) ;
V_128 = F_136 ( V_331 ) ;
if ( V_128 == 0 )
return V_129 ;
while ( V_128 & ~ V_424 ) {
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_128 & V_332 )
F_64 ( V_9 , false ) ;
F_68 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_130 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_130 [ V_5 ] & 0x8000ffff ) {
if ( V_130 [ V_5 ] & V_139 )
F_18 ( L_13 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_130 [ V_5 ] ) ;
V_133 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
F_41 ( V_331 , V_128 & ~ V_424 ) ;
V_423 = F_136 ( V_331 ) ;
F_187 ( V_9 ) ;
if ( V_128 & V_422 )
F_43 ( V_9 , & V_1 -> V_78 [ V_119 ] ) ;
if ( V_130 [ 0 ] & V_140 &&
F_69 ( V_9 , 0 ) ) {
if ( V_128 & V_420 ) {
F_70 ( V_9 , 0 ) ;
F_71 ( V_9 , 0 ) ;
V_424 &= ~ V_420 ;
}
}
if ( V_130 [ 1 ] & V_140 &&
F_69 ( V_9 , 1 ) ) {
if ( V_128 & V_421 ) {
F_70 ( V_9 , 1 ) ;
F_71 ( V_9 , 1 ) ;
V_424 &= ~ V_421 ;
}
}
V_128 = V_423 ;
}
return V_138 ;
}
static void F_188 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_68 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_15 ( F_6 ( V_5 ) ) ) ;
}
F_41 ( V_419 , 0xffff ) ;
F_41 ( V_304 , 0x0 ) ;
F_41 ( V_331 , F_136 ( V_331 ) ) ;
}
static void F_189 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_86 ( & V_1 -> V_133 , 0 ) ;
if ( F_190 ( V_9 ) ) {
F_2 ( V_377 , 0 ) ;
F_2 ( V_144 , F_15 ( V_144 ) ) ;
}
F_41 ( V_370 , 0xeffe ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_419 , 0xffffffff ) ;
F_2 ( V_304 , 0x0 ) ;
F_3 ( V_304 ) ;
}
static int F_191 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_405 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_2 ( V_330 , ~ ( V_325 | V_326 ) ) ;
V_1 -> V_3 =
~ ( V_425 |
V_410 |
V_411 |
V_420 |
V_421 |
V_332 ) ;
V_405 =
V_425 |
V_410 |
V_411 |
V_332 |
V_422 ;
if ( F_190 ( V_9 ) ) {
V_405 |= V_142 ;
V_1 -> V_3 &= ~ V_142 ;
}
F_2 ( V_419 , V_1 -> V_3 ) ;
F_2 ( V_304 , V_405 ) ;
F_3 ( V_304 ) ;
if ( F_190 ( V_9 ) ) {
T_2 V_406 = F_15 ( V_377 ) ;
if ( V_1 -> V_145 & V_426 )
V_406 |= V_427 ;
if ( V_1 -> V_145 & V_428 )
V_406 |= V_429 ;
if ( V_1 -> V_145 & V_430 )
V_406 |= V_431 ;
if ( V_1 -> V_145 & V_432 )
V_406 |= V_433 ;
if ( V_1 -> V_145 & V_434 )
V_406 |= V_435 ;
if ( V_1 -> V_145 & V_436 ) {
V_406 |= V_437 ;
V_406 |= V_438 ;
}
F_2 ( V_377 , V_406 ) ;
}
F_192 ( V_9 ) ;
return 0 ;
}
static T_5 F_193 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_127 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_128 , V_423 , V_130 [ V_131 ] ;
unsigned long V_11 ;
T_2 V_424 =
V_420 |
V_421 ;
T_2 V_439 [ 2 ] = {
V_420 ,
V_421
} ;
int V_5 , V_35 = V_129 ;
F_67 ( & V_1 -> V_133 ) ;
V_128 = F_15 ( V_331 ) ;
do {
bool V_133 = ( V_128 & ~ V_424 ) != 0 ;
bool V_132 = false ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_128 & V_332 )
F_64 ( V_9 , false ) ;
F_68 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_130 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_130 [ V_5 ] & 0x8000ffff ) {
if ( V_130 [ V_5 ] & V_139 )
F_18 ( L_13 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_130 [ V_5 ] ) ;
V_133 = true ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_133 )
break;
if ( ( F_190 ( V_9 ) ) &&
( V_128 & V_142 ) ) {
T_2 V_143 = F_15 ( V_144 ) ;
F_18 ( L_14 ,
V_143 ) ;
if ( V_143 & V_1 -> V_145 )
F_62 ( V_1 -> V_115 ,
& V_1 -> V_54 ) ;
F_2 ( V_144 , V_143 ) ;
F_3 ( V_144 ) ;
}
F_2 ( V_331 , V_128 & ~ V_424 ) ;
V_423 = F_15 ( V_331 ) ;
if ( V_128 & V_422 )
F_43 ( V_9 , & V_1 -> V_78 [ V_119 ] ) ;
F_68 (pipe) {
int V_343 = V_5 ;
if ( F_194 ( V_9 ) )
V_343 = ! V_343 ;
if ( V_130 [ V_5 ] & V_140 &&
F_69 ( V_9 , V_5 ) ) {
if ( V_128 & V_439 [ V_343 ] ) {
F_70 ( V_9 , V_343 ) ;
F_71 ( V_9 , V_5 ) ;
V_424 &= ~ V_439 [ V_343 ] ;
}
}
if ( V_130 [ V_5 ] & V_146 )
V_132 = true ;
}
if ( V_132 || ( V_128 & V_425 ) )
F_195 ( V_9 ) ;
V_35 = V_138 ;
V_128 = V_423 ;
} while ( V_128 & ~ V_424 );
F_187 ( V_9 ) ;
return V_35 ;
}
static void F_196 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( F_190 ( V_9 ) ) {
F_2 ( V_377 , 0 ) ;
F_2 ( V_144 , F_15 ( V_144 ) ) ;
}
F_41 ( V_370 , 0xffff ) ;
F_68 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_15 ( F_6 ( V_5 ) ) ) ;
}
F_2 ( V_419 , 0xffffffff ) ;
F_2 ( V_304 , 0x0 ) ;
F_2 ( V_331 , F_15 ( V_331 ) ) ;
}
static void F_197 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_86 ( & V_1 -> V_133 , 0 ) ;
F_2 ( V_377 , 0 ) ;
F_2 ( V_144 , F_15 ( V_144 ) ) ;
F_2 ( V_370 , 0xeffe ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_419 , 0xffffffff ) ;
F_2 ( V_304 , 0x0 ) ;
F_3 ( V_304 ) ;
}
static int F_198 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_406 ;
T_2 V_405 ;
T_2 V_440 ;
V_1 -> V_3 = ~ ( V_425 |
V_142 |
V_410 |
V_411 |
V_420 |
V_421 |
V_332 ) ;
V_405 = ~ V_1 -> V_3 ;
V_405 |= V_422 ;
if ( F_144 ( V_9 ) )
V_405 |= V_441 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
if ( F_144 ( V_9 ) ) {
V_440 = ~ ( V_323 |
V_317 |
V_318 |
V_326 ) ;
} else {
V_440 = ~ ( V_325 |
V_326 ) ;
}
F_2 ( V_330 , V_440 ) ;
F_2 ( V_419 , V_1 -> V_3 ) ;
F_2 ( V_304 , V_405 ) ;
F_3 ( V_304 ) ;
V_406 = 0 ;
if ( V_1 -> V_145 & V_426 )
V_406 |= V_427 ;
if ( V_1 -> V_145 & V_428 )
V_406 |= V_429 ;
if ( V_1 -> V_145 & V_430 )
V_406 |= V_431 ;
if ( F_144 ( V_9 ) ) {
if ( V_1 -> V_145 & V_442 )
V_406 |= V_433 ;
if ( V_1 -> V_145 & V_443 )
V_406 |= V_435 ;
} else {
if ( V_1 -> V_145 & V_444 )
V_406 |= V_433 ;
if ( V_1 -> V_145 & V_445 )
V_406 |= V_435 ;
}
if ( V_1 -> V_145 & V_436 ) {
V_406 |= V_437 ;
if ( F_144 ( V_9 ) )
V_406 |= V_446 ;
V_406 |= V_438 ;
}
F_2 ( V_377 , V_406 ) ;
F_192 ( V_9 ) ;
return 0 ;
}
static T_5 F_199 ( T_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_127 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_128 , V_423 ;
T_2 V_130 [ V_131 ] ;
unsigned long V_11 ;
int V_133 ;
int V_35 = V_129 , V_5 ;
F_67 ( & V_1 -> V_133 ) ;
V_128 = F_15 ( V_331 ) ;
for (; ; ) {
bool V_132 = false ;
V_133 = V_128 != 0 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_128 & V_332 )
F_64 ( V_9 , false ) ;
F_68 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_130 [ V_5 ] = F_15 ( V_7 ) ;
if ( V_130 [ V_5 ] & 0x8000ffff ) {
if ( V_130 [ V_5 ] & V_139 )
F_18 ( L_13 ,
F_19 ( V_5 ) ) ;
F_2 ( V_7 , V_130 [ V_5 ] ) ;
V_133 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_133 )
break;
V_35 = V_138 ;
if ( V_128 & V_142 ) {
T_2 V_143 = F_15 ( V_144 ) ;
F_18 ( L_14 ,
V_143 ) ;
if ( V_143 & V_1 -> V_145 )
F_62 ( V_1 -> V_115 ,
& V_1 -> V_54 ) ;
F_2 ( V_144 , V_143 ) ;
F_15 ( V_144 ) ;
}
F_2 ( V_331 , V_128 ) ;
V_423 = F_15 ( V_331 ) ;
if ( V_128 & V_422 )
F_43 ( V_9 , & V_1 -> V_78 [ V_119 ] ) ;
if ( V_128 & V_441 )
F_43 ( V_9 , & V_1 -> V_78 [ V_121 ] ) ;
if ( V_128 & V_420 )
F_70 ( V_9 , 0 ) ;
if ( V_128 & V_421 )
F_70 ( V_9 , 1 ) ;
F_68 (pipe) {
if ( V_130 [ V_5 ] & V_447 &&
F_69 ( V_9 , V_5 ) ) {
F_146 ( V_9 , V_5 ) ;
F_71 ( V_9 , V_5 ) ;
}
if ( V_130 [ V_5 ] & V_146 )
V_132 = true ;
}
if ( V_132 || ( V_128 & V_425 ) )
F_195 ( V_9 ) ;
V_128 = V_423 ;
}
F_187 ( V_9 ) ;
return V_35 ;
}
static void F_200 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_2 ( V_377 , 0 ) ;
F_2 ( V_144 , F_15 ( V_144 ) ) ;
F_2 ( V_370 , 0xffffffff ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_419 , 0xffffffff ) ;
F_2 ( V_304 , 0x0 ) ;
F_68 (pipe)
F_2 ( F_6 ( V_5 ) ,
F_15 ( F_6 ( V_5 ) ) & 0x8000ffff ) ;
F_2 ( V_331 , F_15 ( V_331 ) ) ;
}
void F_201 ( struct V_8 * V_9 )
{
struct V_45 * V_1 = V_9 -> V_10 ;
F_202 ( & V_1 -> V_54 , F_34 ) ;
F_202 ( & V_1 -> V_192 , F_83 ) ;
F_202 ( & V_1 -> V_87 . V_53 , F_48 ) ;
F_202 ( & V_1 -> V_95 , F_52 ) ;
V_9 -> V_448 -> V_449 = F_17 ;
V_9 -> V_450 = 0xffffff ;
if ( F_144 ( V_9 ) || F_12 ( V_9 ) -> V_15 >= 5 ) {
V_9 -> V_450 = 0xffffffff ;
V_9 -> V_448 -> V_449 = F_22 ;
}
if ( F_203 ( V_9 , V_451 ) )
V_9 -> V_448 -> V_452 = F_29 ;
else
V_9 -> V_448 -> V_452 = NULL ;
V_9 -> V_448 -> V_453 = F_24 ;
if ( F_9 ( V_9 ) ) {
V_9 -> V_448 -> V_454 = F_66 ;
V_9 -> V_448 -> V_455 = F_171 ;
V_9 -> V_448 -> V_456 = F_177 ;
V_9 -> V_448 -> V_457 = F_181 ;
V_9 -> V_448 -> V_458 = F_155 ;
V_9 -> V_448 -> V_459 = F_160 ;
} else if ( F_204 ( V_9 ) ) {
V_9 -> V_448 -> V_454 = F_75 ;
V_9 -> V_448 -> V_455 = F_170 ;
V_9 -> V_448 -> V_456 = F_176 ;
V_9 -> V_448 -> V_457 = F_182 ;
V_9 -> V_448 -> V_458 = F_154 ;
V_9 -> V_448 -> V_459 = F_159 ;
} else if ( F_205 ( V_9 ) ) {
V_9 -> V_448 -> V_454 = F_75 ;
V_9 -> V_448 -> V_455 = F_170 ;
V_9 -> V_448 -> V_456 = F_176 ;
V_9 -> V_448 -> V_457 = F_182 ;
V_9 -> V_448 -> V_458 = F_154 ;
V_9 -> V_448 -> V_459 = F_159 ;
} else if ( F_11 ( V_9 ) ) {
V_9 -> V_448 -> V_454 = F_79 ;
V_9 -> V_448 -> V_455 = F_170 ;
V_9 -> V_448 -> V_456 = F_174 ;
V_9 -> V_448 -> V_457 = F_182 ;
V_9 -> V_448 -> V_458 = F_153 ;
V_9 -> V_448 -> V_459 = F_158 ;
} else {
if ( F_12 ( V_9 ) -> V_15 == 2 ) {
V_9 -> V_448 -> V_455 = F_183 ;
V_9 -> V_448 -> V_456 = F_185 ;
V_9 -> V_448 -> V_454 = F_186 ;
V_9 -> V_448 -> V_457 = F_188 ;
} else if ( F_12 ( V_9 ) -> V_15 == 3 ) {
V_9 -> V_448 -> V_455 = F_189 ;
V_9 -> V_448 -> V_456 = F_191 ;
V_9 -> V_448 -> V_457 = F_196 ;
V_9 -> V_448 -> V_454 = F_193 ;
} else {
V_9 -> V_448 -> V_455 = F_197 ;
V_9 -> V_448 -> V_456 = F_198 ;
V_9 -> V_448 -> V_457 = F_200 ;
V_9 -> V_448 -> V_454 = F_199 ;
}
V_9 -> V_448 -> V_458 = F_151 ;
V_9 -> V_448 -> V_459 = F_156 ;
}
}
